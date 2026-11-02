// Placed .mol objects (doc.objects) as individually selectable/movable THREE meshes (not instanced, so the
// TransformControls gizmo can grab any single one). Loads through the same tables/resolver/ModelCache as the real
// game (src/world/objects.js), so a placed object renders identically in the builder and in play.
import * as THREE from 'three';
import { objectDB } from '../../../world/objects.js';
import { resolveObjectAsync } from '../../../formats/assetresolve.js';
import { tryFetchBuffer, fetchText } from '../../../engine/assets.js';
import { applyShade, applyShadeTree } from '../../../world/shade.js';
import { GroundSurfaces } from '../../../world/groundsurf.js';

async function firstExisting(keys) {
  for (const k of keys || []) {
    if (!k) continue;
    const buf = await tryFetchBuffer(k);
    if (buf) return k;
  }
  return null;
}

export class ObjectsLayer {
  constructor(editor) {
    this.ed = editor;
    this.game = editor.game;
    this.root = new THREE.Group();
    this.root.name = 'editor objects';
    editor.view.root.add(this.root);
    this.byId = new Map();          // id -> { rec, group, ready }
    this.selBoxes = new Map();      // id -> Box3Helper
    this._modelCache = new Map();   // name -> Promise<StaticModel|null> (per object-name, not per instance)
    this._db = null;
    this._surfaceCache = null;
  }

  async db() { return this._db || (this._db = await objectDB()); }

  /** Rebuild every placed object from doc.objects (map load / doc replace). */
  async rebuildAll() {
    for (const id of [...this.byId.keys()]) this._removeVisual(id);
    this.byId.clear();
    await Promise.all(this.ed.doc.objects.map(rec => this.add(rec, { silent: true })));
  }

  async _modelFor(name) {
    let p = this._modelCache.get(name);
    if (!p) {
      p = (async () => {
        const db = await this.db();
        const r = await resolveObjectAsync(name, db, fetchText);
        const meshKey = await firstExisting(r.candidates.mesh);
        if (!meshKey) return null;
        const tpackKey = await firstExisting(r.candidates.tpack);
        const flags = r.flags || {};
        const on = v => v === true || Number(v) > 0;
        const opts = { tpackKey: tpackKey || null, twoSide: on(flags.twoside), transparent: on(flags.transparent), maxDiffuse: on(flags.maxdiffuse) };
        const model = await this.game.models.loadStatic(meshKey, opts);
        if (model) for (const p2 of model.parts) applyShade(p2.material);
        return model;
      })().catch(err => {
        if (err?.transient && this._modelCache.get(name) === p) this._modelCache.delete(name);
        throw err;
      });
      this._modelCache.set(name, p);
    }
    return p;
  }

  /** Add a placed object (rec = doc.objects entry, already pushed to doc.objects by the caller). */
  async add(rec, { silent = false } = {}) {
    const model = await this._modelFor(rec.name);
    // A pending load may outlive Delete, Undo, map replacement or a duplicate request.
    if(!this.ed.doc.objects.includes(rec))return null;
    const existing=this.byId.get(rec.id);
    if(existing?.rec===rec)return existing.group;
    if(existing)this._removeVisual(rec.id);
    const holder = new THREE.Group();
    holder.name = `placed:${rec.id}`;
    holder.userData.objId = rec.id;
    if (model) {
      const g = model.instantiate();
      applyShadeTree(g);
      g.traverse(o => { if (o.isMesh) { o.castShadow = false; o.receiveShadow = true; o.userData.objId = rec.id; } });
      holder.add(g);
      holder.userData.model = model;
    } else {
      // placeholder: a small magenta box so a missing/unresolved object is still visible and selectable
      const ph = new THREE.Mesh(new THREE.BoxGeometry(1, 1.6, 1), new THREE.MeshBasicMaterial({ color: 0xff40ff, wireframe: true }));
      ph.position.y = 0.8; ph.userData.objId = rec.id;
      holder.add(ph);
      holder.userData.missing = true;
    }
    this.root.add(holder);
    this.byId.set(rec.id, { rec, group: holder });
    this._applyTransform(rec.id);
    if (!silent) {this.ed.emit?.('objects');if(this.ed.selection?.kind==='objects'&&this.ed.selection.ids.has(rec.id)&&!this.ed._gizmoBefore)this.ed._syncSelectionVisual();}
    return holder;
  }

  remove(id) { this._removeVisual(id); this.ed.emit?.('objects'); }
  _removeVisual(id) {
    const e = this.byId.get(id);
    if (!e) return;
    e.group.removeFromParent();
    this.byId.delete(id);
    this._surfaceCache = null;
    this.clearHighlight(id);
  }

  /** Re-read rec.x/y/z/qx.../scale into the live group (call after any doc edit). */
  _applyTransform(id) {
    const e = this.byId.get(id);
    if (!e) return;
    const r = e.rec, y = this.ed.doc.heightAt(r.x, r.z) + (Number(r.y) || 0);
    e.group.position.set(r.x, y, r.z);
    e.group.quaternion.set(r.qx || 0, r.qy || 0, r.qz || 0, r.qw ?? 1);
    if (e.group.quaternion.lengthSq() < 1e-8) e.group.quaternion.identity();
    const s = Number.isFinite(r.scale) ? r.scale : 1;
    e.group.scale.setScalar(s || 1);
    this._surfaceCache = null;
    if (this.selBoxes.has(id)) this._updateHighlight(id);
  }
  syncTransform(id) { this._applyTransform(id); }

  /** Use the same ground helpers and FILE transforms as the runtime bridge floor. */
  groundSurfaces(excludeIds = []) {
    const excluded = new Set(excludeIds), key = [...excluded].sort().join('|');
    if (this._surfaceCache?.key === key) return this._surfaceCache.ground;
    const ground = new GroundSurfaces(this.ed.doc.width, this.ed.doc.height);
    for (const [id, {group}] of this.byId) {
      if (excluded.has(id)) continue;
      group.updateMatrix();
      for (const helper of group.userData.model?.helperList || []) {
        if (/^ground/i.test(helper.name) && helper.positions && helper.indices)
          ground.addMesh(helper.positions, helper.indices, group.matrix.elements);
      }
    }
    this._surfaceCache = {key, ground};
    return ground;
  }
  groundHeightAt(x, z, maxY = Infinity, excludeIds = []) {
    return Math.max(this.ed.doc.heightAt(x, z), this.groundSurfaces(excludeIds).heightAt(x, z, maxY));
  }
  pickSurface(raycaster) {
    const ray = raycaster.ray.clone();ray.origin.z *= -1;ray.direction.z *= -1;
    const ground = this.groundSurfaces(), a = new THREE.Vector3(), b = new THREE.Vector3(), c = new THREE.Vector3(), hit = new THREE.Vector3();
    let nearest = Infinity, point = null;
    for (let i = 0; i < ground.count; i++) {
      a.fromArray(ground.tris, i*9);b.fromArray(ground.tris, i*9+3);c.fromArray(ground.tris, i*9+6);
      if (!ray.intersectTriangle(a,b,c,false,hit)) continue;
      const distance = hit.distanceToSquared(ray.origin);
      if (distance < nearest) {nearest = distance;point = {x:hit.x,y:hit.y,z:hit.z};}
    }
    return point;
  }

  /** Re-snap every placed object whose (x,z) falls in a changed terrain rect (called from EditorView after sculpting). */
  terrainChanged(x0, z0, x1, z1) {
    for (const [id, e] of this.byId) {
      const r = e.rec;
      if (r.x >= x0 - 1 && r.x <= x1 + 1 && r.z >= z0 - 1 && r.z <= z1 + 1) this._applyTransform(id);
    }
  }

  /** Raycast the placed objects; returns the topmost hit object's id or null. */
  pick(raycaster) {
    const hits = raycaster.intersectObject(this.root, true);
    for (const h of hits) {
      let o = h.object;
      while (o && o.userData.objId == null) o = o.parent;
      if (o) return o.userData.objId;
    }
    return null;
  }

  highlight(id, on = true) {
    if (!on) { this.clearHighlight(id); return; }
    const e = this.byId.get(id);
    if (!e) return;
    let box = this.selBoxes.get(id);
    if (!box) {
      box = new THREE.BoxHelper(e.group, 0x40ff90);
      box.material.depthTest = false;
      this.root.add(box);
      this.selBoxes.set(id, box);
    }
    this._updateHighlight(id);
  }
  _updateHighlight(id) { this.selBoxes.get(id)?.update(); }
  clearHighlight(id) {
    const box = this.selBoxes.get(id);
    if (!box) return;
    box.geometry.dispose(); box.material.dispose(); box.removeFromParent();
    this.selBoxes.delete(id);
  }
  clearAllHighlights() { for (const id of [...this.selBoxes.keys()]) this.clearHighlight(id); }

  dispose() {
    for (const id of [...this.byId.keys()]) this._removeVisual(id);
    this.root.removeFromParent();
  }
}
