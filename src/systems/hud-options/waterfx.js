// Two Graphics-tab effects of the client that live on the map's water section (.map water entries,
// property/effect/water/*.txt definitions, docs/formats/environment.md):
//
//   "Tile Reflection Effect" (check_reflect_tile): definition type 4 "FloorReflect" of binary/water.fx = a 0.2-alpha
//     planar reflection of the scene on shiny floors (castle and dungeon tiles). The world's water layer skips type 4
//     (world/water.js header); this module draws it: one mirror per floor height (three Reflector render target at
//     half the canvas size), only while the camera is near the floor cells.
//   "Water Effect" (check_swimming_effect): characters standing or moving in water leave ring ripples on the surface
//     (texture/effect/common/waterfront.dds) and running kicks up splash drops (particle_waterl_01/02.dds). Both
//     textures are used by client code only (no effect scene references them) [inference: rates and sizes].
import * as THREE from 'three';
import { Reflector } from 'three/addons/objects/Reflector.js';
import { parseWater } from '../../formats/environment.js';
import { fetchText } from '../../engine/assets.js';

const FLOOR_ALPHA = 0.2;
const RIPPLE_TEX = 'texture/effect/common/waterfront.dds';
const DROP_TEX = ['texture/effect/common/particle_waterl_01.dds', 'texture/effect/common/particle_waterl_02.dds'];

const MIRROR_SHADER = {
  uniforms: { color: { value: null }, tDiffuse: { value: null }, textureMatrix: { value: null }, alpha: { value: FLOOR_ALPHA } },
  vertexShader: /* glsl */`
    uniform mat4 textureMatrix;
    varying vec4 vUv;
    void main() {
      vUv = textureMatrix * vec4(position, 1.0);
      gl_Position = projectionMatrix * modelViewMatrix * vec4(position, 1.0);
    }`,
  fragmentShader: /* glsl */`
    uniform vec3 color;
    uniform sampler2D tDiffuse;
    uniform float alpha;
    varying vec4 vUv;
    void main() {
      vec4 base = texture2DProj(tDiffuse, vUv);
      gl_FragColor = vec4(base.rgb * color, alpha);
    }`,
};

export class WaterFx {
  constructor(game, ctx) {
    this.game = game;
    this.ctx = ctx;
    this.types = null;          // per map: [{entry, type}]
    this.mirrors = [];          // [{mesh, minX, maxX, minZ, maxZ}]
    this.fx = [];               // live ripples / drops
    this.group = new THREE.Group();
    this.group.name = 'water fx (FILE frame)';
    game.worldRoot?.add(this.group);
    this.tex = { ripple: null, drops: [] };
    const T = game.textures;
    Promise.resolve(T?.load?.(RIPPLE_TEX, { repeat: false })).then(t => { if (!this._disposed) this.tex.ripple = t || null; }).catch(() => {});
    DROP_TEX.forEach((k, i) => Promise.resolve(T?.load?.(k, { repeat: false })).then(t => { if (!this._disposed) this.tex.drops[i] = t || null; }).catch(() => {}));
    this.rippleGeo = new THREE.PlaneGeometry(1, 1).rotateX(-Math.PI / 2);
    this.dropGeo = new THREE.PlaneGeometry(1, 1);
    this._t = 0;
    this._mapKey = null;
    this._mapEpoch = 0;
    this._disposed = false;
  }

  // ------------------------------------------------------------------ per map
  async onMap() {
    if (this._disposed) return;
    const epoch = ++this._mapEpoch;
    this.clearMirrors();
    this.clearFx();
    const w = this.game.world, map = w?.water?.map;
    const key = `${w?.info?.index}`;
    this._mapKey = key;
    this.types = null;
    this.waterIdx = null;
    this.width = 0;
    if (!map?.water?.length) return;
    const types = [];
    for (const entry of map.water) {
      let type = 2;
      try { type = Number(parseWater(await fetchText(entry.defPath)).type); } catch { /* default */ }
      if (this._disposed || this._mapEpoch !== epoch || this.game.world !== w) return;
      types.push({ entry, type });
    }
    this.types = types;
    // cell -> is real water (types 0..3), for the ripples
    const idx = new Map();
    for (const { entry, type } of this.types) if (type !== 4) for (let j = 0; j < entry.cells.length; j++) if (!idx.has(entry.cells[j])) idx.set(entry.cells[j], entry.cellHeights[j]);
    this.waterIdx = idx;
    this.width = map.width;
    this.applyFloors();
  }

  /** Build or drop the floor mirrors for the current option value. */
  applyFloors() {
    this.clearMirrors();
    if (this._disposed || !this.ctx.options.get('reflectTile') || !this.types) return;
    const g = this.game, map = g.world?.water?.map;
    if (!map) return;
    const W = map.width;
    const byHeight = new Map();
    for (const { entry, type } of this.types) {
      if (type !== 4) continue;
      for (let j = 0; j < entry.cells.length; j++) {
        const h = entry.cellHeights[j];
        let s = byHeight.get(h);
        if (!s) byHeight.set(h, (s = new Set()));
        s.add(entry.cells[j]);
      }
    }
    const r = g.renderer;
    const size = new THREE.Vector2();
    r?.getDrawingBufferSize?.(size);
    // Every authored floor remains available. A global top-three cap permanently
    // erased smaller rooms in Chaos Temple and Kastrioti Mansion.
    for (const [h, cells] of byHeight) {
      const list = [...cells];
      const pos = new Float32Array(list.length * 12);
      const idx = list.length * 4 > 65535 ? new Uint32Array(list.length * 6) : new Uint16Array(list.length * 6);
      let minX = Infinity, maxX = -Infinity, minZ = Infinity, maxZ = -Infinity;
      list.forEach((cell, q) => {
        const c = cell % W, rr = Math.floor(cell / W);
        // Reflector plane = local XY (normal +Z); rotated -90 deg about X: local (x, y) -> THREE (x, 0, -y) = FILE (x, z=y)
        const corners = [c, rr, c + 1, rr, c, rr + 1, c + 1, rr + 1];
        for (let t = 0; t < 4; t++) { const o = (q * 4 + t) * 3; pos[o] = corners[t * 2]; pos[o + 1] = corners[t * 2 + 1]; pos[o + 2] = 0; }
        const a = q * 4;
        idx.set([a, a + 1, a + 3, a, a + 3, a + 2], q * 6);
        if (c < minX) minX = c; if (c + 1 > maxX) maxX = c + 1; if (rr < minZ) minZ = rr; if (rr + 1 > maxZ) maxZ = rr + 1;
      });
      const geo = new THREE.BufferGeometry();
      geo.setAttribute('position', new THREE.BufferAttribute(pos, 3));
      geo.setIndex(new THREE.BufferAttribute(idx, 1));
      geo.computeBoundingSphere();
      const mesh = new Reflector(geo, {
        color: 0xffffff, clipBias: 0.003, shader: MIRROR_SHADER,
        textureWidth: Math.max(256, Math.floor((size.x || innerWidth) / 2)), textureHeight: Math.max(256, Math.floor((size.y || innerHeight) / 2)),
      });
      mesh.material.transparent = true;
      mesh.material.depthWrite = false;
      mesh.material.side = THREE.FrontSide;
      mesh.rotation.x = -Math.PI / 2;
      mesh.position.y = h + 0.002;
      mesh.renderOrder = 4;
      mesh.name = `floor reflection ${h}`;
      // A floor capture must not recursively render the other floor mirrors.
      // Nearby, frustum-visible floors each capture the ordinary scene once.
      const renderMirror = mesh.onBeforeRender;
      mesh.onBeforeRender = (...args) => {
        if (this._disposed) return;
        const siblings = this.mirrors.map(m => [m.mesh, m.mesh.visible]);
        for (const [other] of siblings) if (other !== mesh) other.visible = false;
        try { renderMirror.apply(mesh, args); }
        finally { for (const [other, visible] of siblings) other.visible = visible; }
      };
      g.scene.add(mesh);
      this.mirrors.push({ mesh, minX, maxX, minZ, maxZ });
    }
  }

  clearMirrors() {
    for (const m of this.mirrors) { m.mesh.removeFromParent(); m.mesh.dispose?.(); m.mesh.geometry.dispose(); }
    this.mirrors = [];
  }

  // ------------------------------------------------------------------ per frame
  update(dt) {
    if (this._disposed) return;
    const g = this.game;
    this._t += dt;
    // mirrors: only near the camera target (they render the scene once more each)
    if (this.mirrors.length) {
      const p = g.player, view = (g.world?.cullDistance || 60) * 0.8;
      for (const m of this.mirrors) {
        if (!p) { m.mesh.visible = false; continue; }
        const dx = p.x < m.minX ? m.minX - p.x : p.x > m.maxX ? p.x - m.maxX : 0;
        const dz = p.z < m.minZ ? m.minZ - p.z : p.z > m.maxZ ? p.z - m.maxZ : 0;
        m.mesh.visible = dx * dx + dz * dz < view * view;
      }
    }
    if (this.ctx.options.get('swimming')) this._spawn(dt);
    this._animate(dt);
  }

  _levelAt(x, z) {
    if (!this.waterIdx) return null;
    const c = Math.floor(x), r = Math.floor(z);
    if (c < 0 || r < 0) return null;
    const h = this.waterIdx.get(r * this.width + c);
    return h === undefined ? null : h;
  }

  _spawn(dt) {
    const g = this.game;
    let actors = [];
    try { actors = g.actors ? g.actors() : [g.player]; } catch { actors = [g.player]; }
    for (const a of actors) {
      if (!a || a.dead || a.culled || !(a.kind === 'player' || a.kind === 'monster' || a.kind === 'npc')) continue;
      const lvl = this._levelAt(a.x, a.z);
      if (lvl == null) { a._hoWet = null; continue; }
      const ground = Number(a.y ?? g.world?.heightAt?.(a.x, a.z)) || 0;
      if (lvl - ground < 0.08) { a._hoWet = null; continue; }
      const w = (a._hoWet ||= { t: 0, lx: a.x, lz: a.z, drop: 0 });
      const moved = Math.hypot(a.x - w.lx, a.z - w.lz);
      const speed = moved / Math.max(1e-4, dt);
      w.lx = a.x; w.lz = a.z;
      w.t -= dt;
      if (w.t <= 0) {
        w.t = speed > 0.5 ? 0.32 : 1.1;
        this._ripple(a.x, lvl, a.z, speed > 0.5 ? 1.8 : 1.3);
      }
      if (speed > 2.5 && a.kind === 'player') {
        w.drop -= dt;
        if (w.drop <= 0) { w.drop = 0.07; for (let i = 0; i < 2; i++) this._drop(a.x, lvl, a.z); }
      }
    }
  }

  _ripple(x, y, z, size) {
    if (!this.tex.ripple || this.fx.length > 120) return;
    // the foam texture carries its own alpha (bright flecks): drawn alpha-blended, not added
    const mat = new THREE.MeshBasicMaterial({ map: this.tex.ripple, transparent: true, depthWrite: false, opacity: 1, side: THREE.DoubleSide });
    const m = new THREE.Mesh(this.rippleGeo, mat);
    m.position.set(x, y + 0.02, z);
    m.renderOrder = 7;
    this.group.add(m);
    this.fx.push({ m, t: 0, life: 1.2, kind: 'ripple', size });
  }

  _drop(x, y, z) {
    const tex = this.tex.drops[Math.floor(Math.random() * this.tex.drops.length)];
    if (!tex || this.fx.length > 160) return;
    const mat = new THREE.SpriteMaterial({ map: tex, transparent: true, depthWrite: false, opacity: 0.9 });
    const s = new THREE.Sprite(mat);
    const a = Math.random() * Math.PI * 2, r = 0.15 + Math.random() * 0.25;
    s.position.set(x + Math.cos(a) * r, y + 0.05, z + Math.sin(a) * r);
    s.scale.setScalar(0.18 + Math.random() * 0.12);
    this.group.add(s);
    this.fx.push({ m: s, t: 0, life: 0.55, kind: 'drop', v: new THREE.Vector3(Math.cos(a) * 0.8, 2.2 + Math.random() * 1.4, Math.sin(a) * 0.8), y0: y });
  }

  _animate(dt) {
    for (let i = this.fx.length - 1; i >= 0; i--) {
      const f = this.fx[i];
      f.t += dt;
      const k = f.t / f.life;
      if (k >= 1) { f.m.removeFromParent(); f.m.material.dispose(); this.fx.splice(i, 1); continue; }
      if (f.kind === 'ripple') {
        const s = f.size * (0.35 + 0.65 * k);
        f.m.scale.set(s, 1, s);
        f.m.material.opacity = 1 - k;
      } else {
        f.v.y -= 9 * dt;
        f.m.position.addScaledVector(f.v, dt);
        if (f.m.position.y < f.y0) f.t = f.life;
        f.m.material.opacity = 0.9 * (1 - k);
      }
    }
  }

  clearFx() { for (const f of this.fx) { f.m.removeFromParent(); f.m.material.dispose(); } this.fx = []; }

  dispose() {
    if (this._disposed) return;
    this._disposed = true; ++this._mapEpoch;
    this.types = null; this.waterIdx = null; this.width = 0;
    this.clearMirrors(); this.clearFx(); this.group.removeFromParent(); this.rippleGeo.dispose(); this.dropGeo.dispose();
  }
}
