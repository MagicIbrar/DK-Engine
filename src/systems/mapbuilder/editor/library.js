// Searchable object library: every placeable name from script/object/*.csv (world/objects.js objectDB(), the same
// tables the real game resolves .mol names against), plus a live-rotating 3D preview of the selected entry rendered
// into a corner of the main canvas (one shared WebGL context - a scissored sub-viewport, no second renderer).
import * as THREE from 'three';
import { objectDB } from '../../../world/objects.js';

export class ObjectLibrary {
  constructor(editor) {
    this.ed = editor;
    this.game = editor.game;
    this.items = [];       // [{ name: 'plant\\b_grasstotal_01', category, key }]
    this.ready = false;
    this.categories = [];
    // preview scene
    this.previewScene = new THREE.Scene();
    this.previewCamera = new THREE.PerspectiveCamera(35, 1, 0.05, 200);
    this.previewScene.add(new THREE.HemisphereLight(0xffffff, 0x404050, 1.4));
    const sun = new THREE.DirectionalLight(0xffffff, 1.4); sun.position.set(2, 4, 3);
    this.previewScene.add(sun);
    // objects are authored in the FILE frame (raw vertex data, winding relies on a -Z mirror parent - see
    // docs/ARCHITECTURE.md mirror rule), so the preview needs the same mirror scale the real worldRoot has.
    this.previewMirror = new THREE.Group();
    this.previewMirror.scale.set(1, 1, -1);
    this.previewScene.add(this.previewMirror);
    this.previewGroup = new THREE.Group();
    this.previewMirror.add(this.previewGroup);
    this._previewName = null;
    this._spin = 0;
  }

  async load() {
    if (this.ready) return;
    const db = await objectDB();
    const items = [];
    // a placeable name is always "<category>\<name>" (assetresolve.js splitObjectName) - the same string a .mol
    // placement stores, so this list is placed exactly like the client's own object stamp tool.
    for (const [cat, table] of db.tables) for (const [key, row] of table) items.push({ name: `${cat}\\${row.name}`, category: cat, key });
    items.sort((a, b) => a.category === b.category ? a.key.localeCompare(b.key) : a.category.localeCompare(b.category));
    this.items = items;
    this.categories = [...db.tables.keys()].sort();
    this.ready = true;
  }

  /** Case-insensitive substring search over name/category, optionally restricted to one category. */
  search(query = '', category = '', limit = 200) {
    const q = query.trim().toLowerCase();
    let list = this.items;
    if (category) list = list.filter(i => i.category === category);
    if (q) list = list.filter(i => i.key.includes(q) || i.name.toLowerCase().includes(q));
    return list.slice(0, limit);
  }

  /** Show `name` in the preview viewport (loads the model through the shared ObjectsLayer cache). */
  async setPreview(name) {
    this._previewName = name;
    for (const c of this.previewGroup.children.slice()) this.previewGroup.remove(c);
    if (!name) return;
    const model = await this.ed.objects._modelFor(name);
    if (this._previewName !== name) return; // superseded by a newer selection
    if (!model) return;
    const g = model.instantiate();
    const r = model.radius || 1, c = model.center || new THREE.Vector3();
    g.position.set(-c.x, -c.y, -c.z);
    this.previewGroup.add(g);
    const dist = Math.max(1.2, r * 2.4);
    this.previewCamera.position.set(dist * 0.7, dist * 0.55, dist * 0.7);
    this.previewCamera.near = Math.max(0.02, dist * 0.02); this.previewCamera.far = dist * 20;
    this.previewCamera.updateProjectionMatrix();
    this.previewCamera.lookAt(0, r * 0.15, 0);
  }

  /** Call every frame the preview panel is visible: renders into a scissored rect of the shared canvas. */
  render(renderer, dt, x, y, w, h) {
    if (!this.previewGroup.children.length) return;
    this._spin += dt * 0.6;
    this.previewGroup.rotation.y = this._spin;
    const prevScissorTest = renderer.getScissorTest();
    const prevViewport = new THREE.Vector4(); renderer.getViewport(prevViewport);
    const prevScissor = new THREE.Vector4(); renderer.getScissor(prevScissor);
    const dpr = renderer.getPixelRatio();
    renderer.setScissorTest(true);
    renderer.setScissor(x * dpr, y * dpr, w * dpr, h * dpr);
    renderer.setViewport(x * dpr, y * dpr, w * dpr, h * dpr);
    this.previewCamera.aspect = w / h; this.previewCamera.updateProjectionMatrix();
    renderer.clearDepth();
    renderer.render(this.previewScene, this.previewCamera);
    renderer.setViewport(prevViewport); renderer.setScissor(prevScissor); renderer.setScissorTest(prevScissorTest);
  }
}
