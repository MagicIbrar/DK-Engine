// The map builder's live world: the engine's own Terrain / WaterLayer / Environment (src/world) built from a MapDoc,
// plus in-place GPU updates while sculpting and painting (no rebuilds for heights, colours, ground tiles, holes).
//
//  * Terrain is built from the document with NO holes, so every chunk has its full index buffer; holes are the LUT
//    alpha flag (terrain.js shader discards CELL_HOLE), so painting holes never touches geometry.
//  * Heights / normals / vertex colours: the chunk attributes are rewritten for the touched vertices.
//  * Ground types / variants / holes: the tile lookup texels of the touched cells (map.js terrainTileForCell).
//  * Decals and water drape on the terrain: they are rebuilt (debounced) after a stroke that touches them.
// FILE frame under game.worldRoot (docs/ARCHITECTURE.md §1).
import * as THREE from 'three';
import { Terrain } from '../../../world/terrain.js';
import { WaterLayer } from '../../../world/water.js';
import { Environment } from '../../../world/environment.js';
import { terrainTileForCell, CELL_HOLE, CELL_DECAL } from '../../../formats/map.js';
import { mapEnvironmentInfo, parseEnvironment, sampleEnvironment } from '../../../formats/environment.js';
import { setShade, resetShade, applyShadeTree } from '../../../world/shade.js';

export class EditorView {
  constructor(editor) {
    this.ed = editor;
    this.game = editor.game;
    this.root = new THREE.Group();
    this.root.name = 'editor world';
    this.game.worldRoot.add(this.root);
    this.terrain = null;
    this.water = null;
    this.environment = null;
    this.view = null;
    this._decalsDirty = false;
    this._waterDirty = false;
    this._busy = { decals: false, water: false };
    this._timers = { decals: 0, water: 0 };
    this.fog = false;           // editing view: no fog (whole map visible); preview (player mode) turns it on
    this.shade = false;
  }
  get doc() { return this.ed.doc; }

  /** Build everything for the current document. */
  async build(onProgress = () => {}) {
    await this.rebuildTerrain(onProgress);
    onProgress(0.6, 'Environment');
    await this.rebuildEnvironment();
    onProgress(0.8, 'Water');
    await this.rebuildWater();
    onProgress(1, 'Ready');
  }

  // ---------------------------------------------------------------------------------------- terrain
  async rebuildTerrain(onProgress = () => {}) {
    const doc = this.doc;
    if (this.terrain) { this.terrain.dispose(); this.terrain = null; }
    const view = doc.mapView();
    this.view = view;
    // no holes at build time: every chunk gets its full index buffer (holes = LUT flag, see header)
    const buildView = { ...view, holes: new Uint8Array(doc.C) };
    const t = new Terrain({ map: buildView, game: this.game, root: this.root });
    await t.build((f, l) => onProgress(f * 0.55, l));
    t.map = view;
    this.terrain = t;
    t.group.visible=this.ed.toggles?.terrain!==false;
    for (const c of t.chunks) { c.mesh.frustumCulled = true; }
    this.lut = t.material?.userData?.uniforms?.dkTileLUT?.value || null;
    if (this.lut) this.updateTiles(0, 0, doc.width - 1, doc.height - 1);
    this.ed.overlay?.attach(t);
    this.ed.emit?.('terrain');
  }

  /** Chunks intersecting the vertex rect [x0..x1] x [z0..z1]. */
  _chunksIn(x0, z0, x1, z1) {
    return (this.terrain?.chunks || []).filter(c => c.maxX >= x0 && c.minX <= x1 && c.maxZ >= z0 && c.minZ <= z1);
  }

  /**
   * Push heights (+ recomputed normals) and vertex colours of the vertex rect to the GPU.
   * opts: { normals = true, colors = true }
   */
  updateVertices(x0, z0, x1, z1, { normals = true, colors = true } = {}) {
    const doc = this.doc, W = doc.width, H = doc.height, X = W + 1;
    x0 = Math.max(0, Math.floor(x0)); z0 = Math.max(0, Math.floor(z0)); x1 = Math.min(W, Math.ceil(x1)); z1 = Math.min(H, Math.ceil(z1));
    if (normals) doc.recomputeNormals(x0 - 1, z0 - 1, x1 + 1, z1 + 1);
    const nx0 = Math.max(0, x0 - 1), nz0 = Math.max(0, z0 - 1), nx1 = Math.min(W, x1 + 1), nz1 = Math.min(H, z1 + 1);
    for (const c of this._chunksIn(nx0, nz0, nx1, nz1)) {
      const g = c.mesh.geometry, vx = c.maxX - c.minX + 1;
      const pos = g.attributes.position.array, nrm = g.attributes.normal.array, col = g.attributes.color.array;
      const ax = Math.max(nx0, c.minX), bx = Math.min(nx1, c.maxX), az = Math.max(nz0, c.minZ), bz = Math.min(nz1, c.maxZ);
      for (let z = az; z <= bz; z++) {
        for (let x = ax; x <= bx; x++) {
          const s = z * X + x, d = (z - c.minZ) * vx + (x - c.minX);
          pos[d * 3 + 1] = doc.heights[s];
          if (normals) { nrm[d * 3] = doc.normals[s * 3]; nrm[d * 3 + 1] = doc.normals[s * 3 + 1]; nrm[d * 3 + 2] = doc.normals[s * 3 + 2]; }
          if (colors) { col[d * 3] = doc.colors[s * 4]; col[d * 3 + 1] = doc.colors[s * 4 + 1]; col[d * 3 + 2] = doc.colors[s * 4 + 2]; }
        }
      }
      g.attributes.position.needsUpdate = true;
      if (normals) g.attributes.normal.needsUpdate = true;
      if (colors) g.attributes.color.needsUpdate = true;
      g.computeBoundingBox(); g.computeBoundingSphere();
    }
    this._touchDrapes(x0, z0, x1, z1);
    this.ed.objects?.terrainChanged(x0, z0, x1, z1);
    this.ed.actors?.terrainChanged(x0, z0, x1, z1);
  }

  /** Re-evaluate the tile lookup texels (ground type transitions, variants, holes) of the cell rect. */
  updateTiles(x0, z0, x1, z1) {
    const lut = this.lut;
    if (!lut) return;
    const doc = this.doc, W = doc.width, H = doc.height, data = lut.image.data;
    x0 = Math.max(0, Math.floor(x0) - 1); z0 = Math.max(0, Math.floor(z0) - 1); x1 = Math.min(W - 1, Math.ceil(x1) + 1); z1 = Math.min(H - 1, Math.ceil(z1) + 1);
    const m = this.view;
    for (let row = z0; row <= z1; row++) {
      for (let col = x0; col <= x1; col++) {
        const t = terrainTileForCell(m, col, row), o = (row * W + col) * 4;
        data[o] = t.slot; data[o + 1] = t.rot; data[o + 2] = t.variant;
        data[o + 3] = (t.flags & ~CELL_DECAL) | (data[o + 3] & CELL_DECAL) | (doc.holes[row * W + col] ? CELL_HOLE : 0);
      }
    }
    lut.needsUpdate = true;
  }

  _touchDrapes(x0, z0, x1, z1) {
    const doc = this.doc, W = doc.width;
    // decals under the rect
    if (!this._decalsDirty) {
      for (const d of doc.decals) {
        const c0 = d.cell % W, r0 = Math.floor(d.cell / W);
        if (c0 <= x1 && c0 + d.size >= x0 && r0 <= z1 && r0 + d.size >= z0) { this.markDecals(); break; }
      }
    }
    // water over the rect
    if (!this._waterDirty) {
      const cx0 = Math.max(0, Math.floor(x0) - 1), cz0 = Math.max(0, Math.floor(z0) - 1);
      const cx1 = Math.min(doc.width - 1, Math.ceil(x1)), cz1 = Math.min(doc.height - 1, Math.ceil(z1));
      outer: for (let z = cz0; z <= cz1; z++) for (let x = cx0; x <= cx1; x++) if (doc.waterDef[z * W + x]) { this.markWater(); break outer; }
    }
  }

  markDecals(delay = 0.35) { this._decalsDirty = true; this._timers.decals = delay; }
  markWater(delay = 0.35) { this._waterDirty = true; this._timers.water = delay; }

  async rebuildDecals() {
    const t = this.terrain;
    if (!t) return;
    this._decalsDirty = false;
    this._busy.decals = true;
    try {
      for (const d of t.decals) { d.mesh.removeFromParent(); d.mesh.geometry.dispose(); }
      for (const m of t._decalMaterials || []) m.dispose();
      t.decals = []; t._decalMaterials = [];
      t.stats.decalRecords = 0; t.stats.decalMeshes = 0; t.stats.missingDecals = [];
      this.view = this.doc.mapView();
      t.map = this.view;
      await t._buildDecals();
      for (const d of t.decals) applyShadeTree(d.mesh);
    } finally { this._busy.decals = false; }
    this.ed.emit?.('decals');
  }

  async rebuildWater() {
    this._waterDirty = false;
    this._busy.water = true;
    try {
      const old = this.water;
      const view = this.doc.mapView();
      this.view.water = view.water;
      const w = new WaterLayer({ map: view, game: this.game, root: this.root, envMapKey: this._envMapKey() });
      await w.build();
      old?.dispose();
      w.group.visible = this.ed.toggles?.water !== false;
      this.water = w;
    } finally { this._busy.water = false; }
  }

  _envMapKey() {
    const e = this.doc.meta.env || {};
    return mapEnvironmentInfo({ EnvironmentMap: e.envMap || 'water/skyCube=.dds' }).environmentMap;
  }

  // ---------------------------------------------------------------------------------------- environment
  /** The environment: the chosen light file, or the edited light text of the map. */
  async rebuildEnvironment() {
    const e = this.doc.meta.env || {};
    this.environment?.dispose();
    const row = { Index: '0', EnvironmentFile: e.light || 'light_braiken.txt', EnvironmentMap: e.envMap || 'water/skyCube=.dds', 'OnedayTime(Min)': String(e.dayMinutes || 90), Clip_Far: String(e.clipFar || 75) };
    const env = new Environment(this.game, { envInfo: mapEnvironmentInfo(row), row, lightText: e.lightText || null });
    await env.load();
    const h = e.fixedHour != null && e.fixedHour !== '' ? Number(e.fixedHour) : (this.hour ?? 12);
    env.setHour(h);
    env.fixedTime = env.time;
    this.environment = env;
    this.ed.emit?.('environment');
  }

  /** Replace the light keys live (environment window edits) without reloading. */
  setLightText(text) {
    const env = this.environment;
    if (!env) return;
    env.env = parseEnvironment(text);
    const types = new Set(env.env.keys.map(k => k.sky?.type ?? 0));
    for (const t of types) env._skyTexture(t);
  }

  setHour(h) {
    this.hour = h;
    const env = this.environment;
    if (!env) return;
    env.setHour(h);
    env.fixedTime = env.time;
  }

  /** The sampled light key at the current hour (for the environment window). */
  currentKey() { const env = this.environment; return env?.env ? sampleEnvironment(env.env, env.time) : null; }

  // ---------------------------------------------------------------------------------------- queries
  heightAt(x, z) { return this.doc.heightAt(x, z); }

  /** Ground point (FILE frame) under a THREE-space ray, or null (ray-march + bisection, like World.pickGround). */
  pickGround(raycaster, { clampToMap = false } = {}) {
    const doc = this.doc;
    const ray = raycaster.ray;
    const ox = ray.origin.x, oy = ray.origin.y, oz = -ray.origin.z;
    const dx = ray.direction.x, dy = ray.direction.y, dz = -ray.direction.z;
    const W = doc.width, H = doc.height;
    const above = (t) => oy + dy * t - doc.heightAt(ox + dx * t, oz + dz * t);
    if (above(0) < 0) return null;
    let t = 0;
    const maxT = 4000;
    while (t < maxT) {
      const step = Math.max(0.2, t * 0.004);
      const t1 = t + step;
      const x = ox + dx * t1, z = oz + dz * t1;
      if ((x < -W || z < -H || x > 2 * W || z > 2 * H) && dy >= 0) break;
      if (above(t1) <= 0) {
        let a = t, b = t1;
        for (let i = 0; i < 24; i++) { const m = (a + b) / 2; if (above(m) > 0) a = m; else b = m; }
        let px = ox + dx * b, pz = oz + dz * b;
        if (px < 0 || pz < 0 || px > W || pz > H) {
          if (!clampToMap) return null;
          px = Math.max(0, Math.min(W, px)); pz = Math.max(0, Math.min(H, pz));
        }
        return { x: px, y: doc.heightAt(px, pz), z: pz };
      }
      t = t1;
    }
    // no hit (looking at the sky): intersect the plane y = 0
    if (clampToMap && dy < 0) {
      const tt = -oy / dy;
      const px = Math.max(0, Math.min(W, ox + dx * tt)), pz = Math.max(0, Math.min(H, oz + dz * tt));
      return { x: px, y: doc.heightAt(px, pz), z: pz };
    }
    return null;
  }

  // ---------------------------------------------------------------------------------------- frame
  update(dt, camera, focusThree) {
    const env = this.environment;
    for (const k of ['decals', 'water']) {
      if (this[`_${k}Dirty`] && !this._busy[k]) {
        this._timers[k] -= dt;
        if (this._timers[k] <= 0) (k === 'decals' ? this.rebuildDecals() : this.rebuildWater()).catch(err => console.error('[mapbuilder] rebuild', k, err));
      }
    }
    if (env) {
      env.update(dt, focusThree, camera.position);
      if (!this.fog) {
        this.game.scene.fog = null;
        const want = 4000;
        if (Math.abs(camera.far - want) > 1) { camera.far = want; camera.updateProjectionMatrix(); }
      } else if (this.game.scene.fog !== env.fog) this.game.scene.fog = env.fog;
      if (this.shade) setShade(focusThree, env.current?.lightDistance); else resetShade();
    }
    const cx = camera.position.x, cz = -camera.position.z;
    const far = this.fog && env ? Math.min(env.viewDistance, env.fogEnd + 12) + 8 : 1e6;
    this.terrain?.update(cx, cz, far);
    this.water?.update(dt, cx, cz, far);
  }

  setVisible(part, on) {
    if(part!=='terrain'&&part!=='water')return;
    this.ed.toggles||={};this.ed.toggles[part]=!!on;
    if (part === 'terrain' && this.terrain) this.terrain.group.visible = on;
    if (part === 'water' && this.water) this.water.group.visible = on;
  }

  dispose() {
    this.terrain?.dispose(); this.water?.dispose(); this.environment?.dispose();
    this.terrain = this.water = this.environment = null;
    this.root.removeFromParent();
    resetShade();
  }
}
