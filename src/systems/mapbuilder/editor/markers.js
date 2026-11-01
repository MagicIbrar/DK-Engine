// Interactive markers for monster spawns, NPC placements and walk-in portals (doc.meta.spawns/npcs/portals).
// Simple coloured primitives (no game art needed - these are editor-only gizmos), individually pickable and
// draggable on the terrain. FILE frame under editorView.root (see overlay.js header).
import * as THREE from 'three';

const SPAWN_GEO = new THREE.ConeGeometry(0.5, 1.4, 8);
const NPC_GEO = new THREE.ConeGeometry(0.55, 1.6, 4);
const HANDLE_GEO = new THREE.SphereGeometry(0.35, 10, 8);
const SPAWN_MAT = new THREE.MeshBasicMaterial({ color: 0xff5040 });
const NPC_MAT = new THREE.MeshBasicMaterial({ color: 0x40a0ff });
const HANDLE_MAT = new THREE.MeshBasicMaterial({ color: 0xffe040 });
const SEL_MAT = new THREE.MeshBasicMaterial({ color: 0x40ff90 });

export class MarkersLayer {
  constructor(editor) {
    this.ed = editor;
    this.root = new THREE.Group();
    this.root.name = 'editor markers';
    editor.view.root.add(this.root);
    this.spawnGroup = new THREE.Group(); this.npcGroup = new THREE.Group(); this.portalGroup = new THREE.Group();
    this.root.add(this.spawnGroup, this.npcGroup, this.portalGroup);
    this.visible = { spawns: true, npcs: true, portals: true };
    this._byMesh = new Map();  // Mesh -> {kind, id, handle?}
    this.selected = null;      // {kind, id}
  }

  setVisible(kind, on) { this.visible[kind] = on; ({ spawns: this.spawnGroup, npcs: this.npcGroup, portals: this.portalGroup })[kind].visible = on; }

  rebuildAll() {
    this._clear(this.spawnGroup); this._clear(this.npcGroup); this._clear(this.portalGroup);
    const meta = this.ed.doc.meta;
    for (const s of meta.spawns || []) this._addSpawn(s);
    for (const n of meta.npcs || []) this._addNpc(n);
    for (const p of meta.portals || []) this._addPortal(p);
  }
  _disposeNode(c) {
    this._byMesh.delete(c);
    if (c.geometry && c.geometry !== SPAWN_GEO && c.geometry !== NPC_GEO && c.geometry !== HANDLE_GEO) c.geometry.dispose();
    if (c.material) c.material.dispose();
    for (const child of c.children || []) this._disposeNode(child);
  }
  _clear(group) { for (const c of group.children.slice()) this._disposeNode(c); group.clear(); }

  groundY(x, z) { return this.ed.doc.heightAt(x, z); }

  _addSpawn(rec) {
    const m = new THREE.Mesh(SPAWN_GEO, SPAWN_MAT.clone());
    m.position.set(rec.x, this.groundY(rec.x, rec.z) + 0.7, rec.z);
    this.spawnGroup.add(m);
    this._byMesh.set(m, { kind: 'spawns', id: rec.id, mesh: m });
    return m;
  }
  _addNpc(rec) {
    const m = new THREE.Mesh(NPC_GEO, NPC_MAT.clone());
    m.position.set(rec.x, this.groundY(rec.x, rec.z) + 0.8, rec.z);
    m.rotation.y = (Number(rec.dirDeg) || 0) * Math.PI / 180;
    this.npcGroup.add(m);
    this._byMesh.set(m, { kind: 'npcs', id: rec.id, mesh: m });
    return m;
  }
  _addPortal(rec) {
    const g = new THREE.Group();
    const w = Math.max(0.2, rec.x1 - rec.x0), d = Math.max(0.2, rec.z1 - rec.z0);
    const y = this.groundY((rec.x0 + rec.x1) / 2, (rec.z0 + rec.z1) / 2) + 0.05;
    const body = new THREE.Mesh(new THREE.PlaneGeometry(w, d), new THREE.MeshBasicMaterial({ color: 0xff40c0, transparent: true, opacity: 0.3, side: THREE.DoubleSide, depthWrite: false }));
    body.rotation.x = -Math.PI / 2;
    body.position.set((rec.x0 + rec.x1) / 2, y, (rec.z0 + rec.z1) / 2);
    g.add(body);
    this._byMesh.set(body, { kind: 'portals', id: rec.id, mesh: body });
    const h0 = new THREE.Mesh(HANDLE_GEO, HANDLE_MAT.clone()); h0.position.set(rec.x0, this.groundY(rec.x0, rec.z0) + 0.4, rec.z0);
    const h1 = new THREE.Mesh(HANDLE_GEO, HANDLE_MAT.clone()); h1.position.set(rec.x1, this.groundY(rec.x1, rec.z1) + 0.4, rec.z1);
    g.add(h0, h1);
    this._byMesh.set(h0, { kind: 'portals', id: rec.id, mesh: body, handle: 0 });
    this._byMesh.set(h1, { kind: 'portals', id: rec.id, mesh: body, handle: 1 });
    g.userData.portalId = rec.id;
    this.portalGroup.add(g);
  }

  /** Sync one marker's position/rotation from its doc record (after an edit). */
  refresh(kind, id) {
    if (kind === 'portals') { this._refreshPortal(id); return; }
    const list = kind === 'spawns' ? this.ed.doc.meta.spawns : this.ed.doc.meta.npcs;
    const group = kind === 'spawns' ? this.spawnGroup : this.npcGroup;
    const rec = (list || []).find(r => r.id === id);
    const entry = [...this._byMesh.entries()].find(([, v]) => v.kind === kind && v.id === id);
    if (!rec) { if (entry) { group.remove(entry[0]); this._byMesh.delete(entry[0]); } return; }
    if (!entry) { kind === 'spawns' ? this._addSpawn(rec) : this._addNpc(rec); return; }
    const [mesh] = entry;
    mesh.position.set(rec.x, this.groundY(rec.x, rec.z) + (kind === 'spawns' ? 0.7 : 0.8), rec.z);
    if (kind === 'npcs') mesh.rotation.y = (Number(rec.dirDeg) || 0) * Math.PI / 180;
  }
  _refreshPortal(id) {
    const group = this.portalGroup.children.find(g => g.userData.portalId === id);
    const rec = (this.ed.doc.meta.portals || []).find(p => p.id === id);
    if (group) { for (const c of group.children.slice()) this._disposeNode(c); group.removeFromParent(); }
    if (rec) this._addPortal(rec);
  }
  removeMarker(kind, id) {
    if (kind === 'portals') { this._refreshPortal(id); return; }
    this.refresh(kind, id);
  }

  terrainChanged() {
    // cheap: full resnap (marker counts are small, unlike terrain vertices)
    for (const s of this.ed.doc.meta.spawns || []) this.refresh('spawns', s.id);
    for (const n of this.ed.doc.meta.npcs || []) this.refresh('npcs', n.id);
    for (const p of this.ed.doc.meta.portals || []) this._refreshPortal(p.id);
  }

  /** Raycast every visible marker kind; returns {kind, id, handle} or null. */
  pick(raycaster) {
    const groups = [];
    if (this.visible.spawns) groups.push(this.spawnGroup);
    if (this.visible.npcs) groups.push(this.npcGroup);
    if (this.visible.portals) groups.push(this.portalGroup);
    for (const grp of groups) {
      const hits = raycaster.intersectObjects(grp.children, true);
      if (hits.length) {
        const info = this._byMesh.get(hits[0].object);
        if (info) return info;
      }
    }
    return null;
  }

  setSelected(kind, id) {
    if (this.selected) this._paint(this.selected.kind, this.selected.id, false);
    this.selected = kind != null ? { kind, id } : null;
    if (this.selected) this._paint(kind, id, true);
  }
  _paint(kind, id, on) {
    for (const [mesh, v] of this._byMesh) {
      if (v.kind !== kind || v.id !== id || v.handle != null) continue;
      mesh.material.color.set(on ? 0x40ff90 : (kind === 'spawns' ? 0xff5040 : kind === 'npcs' ? 0x40a0ff : 0xff40c0));
    }
  }

  dispose() { this.root.removeFromParent(); }
}
