import { readRenderTargetPixels } from '../../engine/pixel-pack-readback.js';
// A small turntable view of an item's model for the D-Shop "Preview" (cashshop/ui_previewwnd.txt, rotated with
// btn_leftrot / btn_rightrot) and the box info "Detail" pane (ui_cashshopboxinfownd.txt pan_preview). Renders with the
// shared WebGL renderer into a render target and copies the pixels to a 2D canvas (mirror + colour rules as the world:
// the model sits in the FILE frame under a z-mirrored root, textures NoColorSpace via the TextureCache).
import * as THREE from 'three';
import { WORLD_MIRROR } from '../../engine/space.js';
import { iconModel, itemInfo, itemInfoFull, loadVisual } from './common.js';
import { clampZoom } from './shop-windows-rules.js';
import { PREVIEW_LIGHT } from '../../config/engine-chosen-preview-light.js';

export class ModelPreview {
  constructor(game, w, h) {
    this.game = game;
    this.w = w; this.h = h;
    this.canvas = document.createElement('canvas');
    this.canvas.width = w * 2; this.canvas.height = h * 2;
    this.canvas.style.width = '100%'; this.canvas.style.height = '100%';
    this.ctx = this.canvas.getContext('2d');
    this.scene = new THREE.Scene();
    this.root = new THREE.Group();
    this.root.scale.copy(WORLD_MIRROR);
    this.pivot = new THREE.Group();
    this.scene.add(this.pivot);
    this.pivot.add(this.root);
    // PREVIEW_LIGHT (config/engine-chosen-preview-light.js, x PI units, same as the character preview). The old 0.8 / 0.9 were
    // not in three r170's x PI units: measured 45 % of the texture's own brightness on 12 D-Shop items, 84 % with PREVIEW_LIGHT
    // (measured). globalThis.__dekaronPreviewLight = {ambient, key} overrides it at render.
    this.ambient = new THREE.AmbientLight(0xffffff, PREVIEW_LIGHT.ambient);
    this.scene.add(this.ambient);
    const sun = this.sun = new THREE.DirectionalLight(0xffffff, PREVIEW_LIGHT.key);
    sun.position.set(-0.5, 0.8, 1);
    this.scene.add(sun);
    this.cam = new THREE.PerspectiveCamera(30, w / h, 0.01, 1000);
    this.yaw = 0;
    this.auto = true;
    this.zoom = 1;          // camera zoom (VIP box info btn_camera_plus / btn_camera_minus)
    this.item = null;
    this._tok = 0;
    this._acc = 0;
  }

  /** Show an item (null clears). */
  async show(itemIndex) {
    const tok = ++this._tok;
    this.item = itemIndex;
    this.root.children.forEach(object => object.userData?.wingMotion?.dispose());
    this.root.clear();
    this.root.position.set(0, 0, 0);
    this._clearCanvas();
    if (itemIndex == null) return false;
    await itemInfoFull(this.game, itemIndex);
    // The equipped ("game") mesh of the item shape first, then the inventory model. Some shapes (the Blood Armor Wings)
    // point their equipped mesh at a flat placeholder that draws nothing, so a candidate that renders no pixels falls
    // through to the next model the item's own data offers.
    const candidates = [];
    const it = itemInfo(this.game, itemIndex);
    try {
      const V = await loadVisual();
      const sh = V?.shapes?.[it.shape];
      const g = sh?.game;
      if (g?.mesh && !g.skel) candidates.push({ mesh: g.mesh, tpack: g.tpack || null, textures: g.textures || null });
      if (sh?.inv?.mesh) candidates.push({ mesh: sh.inv.mesh, tpack: sh.inv.tpack || null, textures: sh.inv.textures || null });
    } catch { /* fall back below */ }
    if (!candidates.length) { const fallback = await iconModel(this.game, itemIndex); if (fallback?.mesh) candidates.push(fallback); }
    for (const inv of candidates) {
      if (tok !== this._tok) return false;
      const shown = await this._showModel(inv, tok);
      if (shown) return true;
      this.root.children.forEach(object => object.userData?.wingMotion?.dispose());
      this.root.clear(); this.root.position.set(0, 0, 0); this._clearCanvas();
    }
    return false;
  }
  /** Load one candidate model, frame it and render it. True when something is actually visible. */
  async _showModel(inv, tok) {
    if (!inv?.mesh) return false;
    const model = await this.game.models.loadStatic(inv.mesh, { tpackKey: inv.tpack || null, textures: inv.textures || null, twoSide: true }).catch(() => null);
    if (tok !== this._tok || !model) return false;
    const obj = model.instantiate();
    this.root.add(obj);
    this.root.updateMatrixWorld(true);
    const box = new THREE.Box3().setFromObject(this.root);
    if (box.isEmpty()) return false;
    const c = box.getCenter(new THREE.Vector3()), sz = box.getSize(new THREE.Vector3());
    this.root.position.sub(c);
    const r = Math.max(sz.x, sz.y, sz.z) * 0.6 || 1;
    const dist = r / Math.tan((this.cam.fov * Math.PI) / 360) * 1.25;
    this.cam.position.set(0, r * 0.25, dist);
    this.cam.lookAt(0, 0, 0);
    this.cam.near = dist / 100; this.cam.far = dist * 10; this.cam.updateProjectionMatrix();
    this._camBase = this.cam.position.clone();
    this.yaw = 0.5;
    this._rendered = false;
    this.render();
    // With a renderer, a model that leaves (almost) every pixel transparent is not a usable preview.
    return !this._rendered || this._coverage() >= 0.004;
  }
  _coverage() {
    const d = this.px; let n = 0;
    for (let k = 3; k < d.length; k += 4) if (d[k] > 16) n++;
    return n / (d.length / 4);
  }
  rotate(d) { this.yaw += d; this.render(); }
  setZoom(z) { this.zoom = clampZoom(z); this.render(); }
  /** Per frame (while visible): slow auto-rotation, rendered at ~12 fps. */
  tick(dt) {
    if (this.item == null || !this.root.children.length) return;
    this.root.children.forEach(object => object.userData?.wingMotion?.update(dt));
    if (this.auto) this.yaw += dt * 0.6;
    this._acc += dt;
    if (this._acc >= 1 / 12) { this._acc = 0; this.render(); }
  }
  _clearCanvas() { this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height); }
  render() {
    const r = this.game.renderer;
    if (!r || !this.root.children.length) return;
    this.pivot.rotation.y = this.yaw;
    const L = globalThis.__dekaronPreviewLight || PREVIEW_LIGHT;
    this.ambient.intensity = L.ambient; this.sun.intensity = L.key;
    if (this._camBase) { this.cam.position.copy(this._camBase).multiplyScalar(1 / this.zoom); this.cam.lookAt(0, 0, 0); }
    const W = this.canvas.width, H = this.canvas.height;
    if (!this.rt || this.rt.width !== W || this.rt.height !== H) { this.rt?.dispose(); this.rt = new THREE.WebGLRenderTarget(W, H, { depthBuffer: true }); this.px = new Uint8Array(W * H * 4); this.img = this.ctx.createImageData(W, H); }
    const prevT = r.getRenderTarget();
    const prevC = r.getClearColor(new THREE.Color()), prevA = r.getClearAlpha();
    try {
      r.setRenderTarget(this.rt);
      r.setClearColor(0x000000, 0);
      r.clear(true, true, true);
      r.render(this.scene, this.cam);
      readRenderTargetPixels(r, this.rt, 0, 0, W, H, this.px);
      this._rendered = true;
    } finally {
      r.setRenderTarget(prevT);
      r.setClearColor(prevC, prevA);
    }
    for (let y = 0; y < H; y++) this.img.data.set(this.px.subarray((H - 1 - y) * W * 4, (H - y) * W * 4), y * W * 4);
    this.ctx.putImageData(this.img, 0, 0);
  }
  dispose() { ++this._tok; this.rt?.dispose(); this.root.children.forEach(object => object.userData?.wingMotion?.dispose()); this.root.clear(); }
}
