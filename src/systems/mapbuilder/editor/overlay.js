// Non-interactive visual aids for the map builder: ground grid, brush cursor, collision tint, portal boxes,
// start-point flag. Everything sits under editorView.root (FILE frame, local x/z = FILE x/z, no negation - see
// docs/ARCHITECTURE.md mirror rule), drawn with simple unlit materials so it never depends on the environment.
import * as THREE from 'three';
import { DEFAULT_CELL_TABLE } from '../../../formats/mac.js';

function argbToRGB(argb) { return [((argb >> 16) & 255) / 255, ((argb >> 8) & 255) / 255, (argb & 255) / 255]; }

export class Overlay {
  constructor(editor) {
    this.ed = editor;
    this.root = new THREE.Group();
    this.root.name = 'editor overlay';
    editor.view.root.add(this.root);
    this.terrain = null;

    // ground grid (flat reference, 8-unit cells)
    this.grid = new THREE.GridHelper(8, 8, 0x88bfff, 0x355070);
    this.grid.material.transparent = true; this.grid.material.opacity = 0.55; this.grid.material.depthWrite = false;
    this.grid.visible = false;
    this.root.add(this.grid);

    // brush cursor: filled disc + ring outline
    this.cursorDisc = new THREE.Mesh(new THREE.CircleGeometry(1, 40), new THREE.MeshBasicMaterial({ color: 0xffd35c, transparent: true, opacity: 0.18, depthWrite: false }));
    this.cursorDisc.rotation.x = -Math.PI / 2;
    this.cursorRing = new THREE.LineLoop(new THREE.BufferGeometry(), new THREE.LineBasicMaterial({ color: 0xffd35c }));
    this.cursorGroup = new THREE.Group(); this.cursorGroup.add(this.cursorDisc, this.cursorRing); this.cursorGroup.visible = false;
    this.cursorGroup.renderOrder = 10;
    this.root.add(this.cursorGroup);
    this._ringPts = 40;

    // collision tint (rebuilt on demand)
    this.collisionMesh = null;
    this.collisionOn = false;

    // portal boxes
    this.portalGroup = new THREE.Group();
    this.root.add(this.portalGroup);

    // start flag
    this.startFlag = new THREE.Group();
    const pole = new THREE.Mesh(new THREE.CylinderGeometry(0.05, 0.05, 2, 6), new THREE.MeshBasicMaterial({ color: 0xffffff }));
    pole.position.y = 1;
    const flag = new THREE.Mesh(new THREE.ConeGeometry(0.5, 1, 4), new THREE.MeshBasicMaterial({ color: 0x40ff80 }));
    flag.rotation.z = Math.PI / 2; flag.position.set(0.5, 1.7, 0);
    this.startFlag.add(pole, flag);
    this.root.add(this.startFlag);
  }

  attach(terrain) { this.terrain = terrain; }

  setGridVisible(on) { this.grid.visible = on; }

  /** Move the brush cursor (FILE x,z) and set its radius (cells). null hides it. */
  setCursor(pt, radius) {
    if (!pt) { this.cursorGroup.visible = false; return; }
    this.cursorGroup.visible = true;
    this.cursorGroup.position.set(pt.x, pt.y + 0.12, pt.z);
    this.cursorDisc.scale.setScalar(Math.max(0.05, radius));
    const n = this._ringPts, pos = new Float32Array((n + 1) * 3);
    for (let i = 0; i <= n; i++) { const a = (i / n) * Math.PI * 2; pos[i * 3] = Math.cos(a) * radius; pos[i * 3 + 1] = 0; pos[i * 3 + 2] = Math.sin(a) * radius; }
    this.cursorRing.geometry.dispose();
    this.cursorRing.geometry = new THREE.BufferGeometry();
    this.cursorRing.geometry.setAttribute('position', new THREE.BufferAttribute(pos, 3));
  }

  updateStart() {
    const st = this.ed.doc.meta.start || { x: 0, z: 0, dirDeg: 0 };
    const y = this.ed.doc.heightAt(st.x, st.z);
    this.startFlag.position.set(st.x, y, st.z);
    this.startFlag.rotation.y = (Number(st.dirDeg) || 0) * Math.PI / 180;
  }

  updatePortals() {
    for (const c of this.portalGroup.children.slice()) { c.geometry?.dispose(); c.material?.dispose(); this.portalGroup.remove(c); }
    const doc = this.ed.doc;
    for (const p of doc.meta.portals || []) {
      const y0 = doc.heightAt(p.x0, p.z0);
      const box = new THREE.Box3(new THREE.Vector3(p.x0, y0, p.z0), new THREE.Vector3(p.x1, y0 + 3, p.z1));
      const helper = new THREE.Box3Helper(box, 0xff40c0);
      helper.userData.portalId = p.id;
      this.portalGroup.add(helper);
    }
  }

  /** Rebuild the collision colour overlay (translucent quads over every non-walkable / special cell). */
  rebuildCollision(table = DEFAULT_CELL_TABLE) {
    if (this.collisionMesh) { this.collisionMesh.geometry.dispose(); this.collisionMesh.material.dispose(); this.root.remove(this.collisionMesh); this.collisionMesh = null; }
    if (!this.collisionOn) return;
    const doc = this.ed.doc, W = doc.width, H = doc.height, X = W + 1;
    const pos = [], col = [], idx = [];
    let n = 0;
    for (let z = 0; z < H; z++) {
      for (let x = 0; x < W; x++) {
        const a = doc.attrs[z * W + x];
        if (!a) continue;
        const info = table.get(a);
        const [r, g, b] = argbToRGB(info ? info.color : 0xffff0000);
        const h00 = doc.heights[z * X + x] + 0.08, h10 = doc.heights[z * X + x + 1] + 0.08;
        const h01 = doc.heights[(z + 1) * X + x] + 0.08, h11 = doc.heights[(z + 1) * X + x + 1] + 0.08;
        pos.push(x, h00, z, x + 1, h10, z, x, h01, z + 1, x + 1, h11, z + 1);
        for (let k = 0; k < 4; k++) col.push(r, g, b);
        idx.push(n, n + 1, n + 2, n + 2, n + 1, n + 3);
        n += 4;
      }
    }
    if (!n) return;
    const g = new THREE.BufferGeometry();
    g.setAttribute('position', new THREE.BufferAttribute(new Float32Array(pos), 3));
    g.setAttribute('color', new THREE.BufferAttribute(new Float32Array(col), 3));
    g.setIndex(idx);
    const mat = new THREE.MeshBasicMaterial({ vertexColors: true, transparent: true, opacity: 0.45, depthWrite: false, side: THREE.DoubleSide });
    this.collisionMesh = new THREE.Mesh(g, mat);
    this.collisionMesh.renderOrder = 5;
    this.root.add(this.collisionMesh);
  }

  setCollisionVisible(on) { this.collisionOn = on; this.rebuildCollision(); }

  dispose() {
    this.grid.geometry.dispose(); this.grid.material.dispose();
    this.cursorDisc.geometry.dispose(); this.cursorDisc.material.dispose();
    this.cursorRing.geometry.dispose(); this.cursorRing.material.dispose();
    if (this.collisionMesh) { this.collisionMesh.geometry.dispose(); this.collisionMesh.material.dispose(); }
    for (const c of this.portalGroup.children) { c.geometry?.dispose(); c.material?.dispose(); }
    this.root.removeFromParent();
  }
}
