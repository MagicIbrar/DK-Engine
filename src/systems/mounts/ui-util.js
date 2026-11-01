import { readRenderTargetPixels } from '../../engine/pixel-pack-readback.js';
import { renderAuraPass, compositeAura } from './preview-aura.js';
// Shared helpers of the mounts system's windows: item icons / tooltips / drag-and-drop through the items system's
// public API (game.items: icon, tooltip, count, add, remove, dil ...) with fallbacks to gamedata/mounts-ui.json, and
// ModelPreview, the rotating 3D preview of the costume / wing / pet shape windows (pan_view_bg / pan_preview panels:
// btn_rot_left / btn_rot_right / btn_zoom_in / btn_zoom_out), rendered off-screen with the shared renderer.
import * as THREE from 'three';
import { WORLD_MIRROR } from '../../engine/space.js';
import { PREVIEW_LIGHT } from '../../config/engine-chosen-preview-light.js';
import { renderItemIcon } from '../../ui/frontend/itemicon.js';

export const fmt = n => Number(n || 0).toLocaleString('en-US');
export const idxOf = x => Number(x?.itemIndex ?? x?.index ?? x) || 0;

// ------------------------------------------------------------------ items system bridge
export function items(sys) { return sys.game.items || null; }
export function itemName(sys, x) { const i = idxOf(x); return items(sys)?.name?.(i) || sys.data.name(i) || `Item ${i}`; }
export function itemDef(sys, x) { return items(sys)?.def?.(idxOf(x)) || null; }
export function countItem(sys, index) {
  const it = items(sys);
  if (it?.count) return Number(it.count(index)) || 0;
  return (sys.game.save?.inventory || []).filter(e => e.itemIndex === index).reduce((a, e) => a + (e.count || 1), 0);
}
export function removeItem(sys, index, n) {
  const it = items(sys);
  if (it?.remove) return !!it.remove(index, n);
  let left = n;
  const inv = sys.game.save?.inventory || [];
  for (let i = inv.length - 1; i >= 0 && left > 0; i--) {
    if (inv[i].itemIndex !== index) continue;
    const t = Math.min(left, inv[i].count || 1);
    inv[i].count = (inv[i].count || 1) - t; left -= t;
    if (inv[i].count <= 0) inv.splice(i, 1);
  }
  return left <= 0;
}
export function removeInst(sys, inst, n = inst?.count || 1) {
  const it = items(sys);
  if (it?.removeInst) return !!it.removeInst(inst, n);
  return removeItem(sys, idxOf(inst), n);
}
export function addItem(sys, index, n = 1, opts = {}) {
  const it = items(sys);
  if (it?.add) { const r = it.add(index, n, { source: 'mounts', ...opts }); return r?.ok !== false ? r : null; }
  return sys.game.loot?.addItem?.({ itemIndex: index, name: sys.data.name(index), count: n, stack: n > 1 }) || null;
}
export function dil(sys) { const it = items(sys); return Number(it ? it.dil : sys.game.save?.dil) || 0; }
export function spendDil(sys, n) {
  n = Number(n) || 0;
  const it = items(sys);
  if (it?.spendDil) return !!it.spendDil(n);
  if (dil(sys) < n) return false;
  sys.game.save.dil = dil(sys) - n;
  return true;
}
/** Icon {url} of an item (inventory 3D model render), or null. */
export function iconOf(sys, x, w = 32, h = 32) {
  const i = idxOf(x);
  const it = items(sys);
  if (it?.icon) return Promise.resolve(it.icon(i, w, h)).catch(() => null);
  const inv = sys.data.invModel(i);
  return inv ? renderItemIcon(sys.game, inv, w, h).then(url => (url ? { url } : null)) : Promise.resolve(null);
}
// The items system's NPC-window machinery (src/systems/items/ui/craft.js, common.js): material slots that REGISTER bag
// items the way the original does (the item stays in its bag cell, dimmed and locked, until the window uses it or it
// is taken out again), the bag opened beside the window, right-click offers from the bag, the NPC-range auto close,
// and footprint-sized slot icons. Loaded dynamically so the mounts system still works without the items system.
let CRAFT = null, COMMON = null;
export const itemsUiReady = Promise.all([
  import('../items/ui/craft.js').then(m => { CRAFT = m; }).catch(() => null),
  import('../items/ui/common.js').then(m => { COMMON = m; }).catch(() => null),
]);

/** Put an item (index or instance) into an `item` slot control: icon, count, tooltip. null clears. */
export function setSlot(sys, ctrl, x, { count = null, dimmed = false } = {}) {
  if (!ctrl) return;
  const slot = ctrl.data?.slot;
  if (x == null || !idxOf(x)) {
    if (slot?.inst) slot.clear(false);          // used up / taken back: release the registration
    ctrl.setIcon(null); ctrl.setCount?.(''); ctrl.setTooltip(undefined); ctrl.data.item = null; return;
  }
  const i = idxOf(x);
  ctrl.data.item = x;
  const it = items(sys);
  if (COMMON?.slotIcon && it?.icons) {
    // the items system's footprint icon (w x h cells scaled into the slot), as its own NPC windows draw them
    COMMON.slotIcon(it, ctrl, typeof x === 'object' ? x : { itemIndex: i, count: 1, grade: 'normal' });
  } else {
    const b = ctrl.box || { w: 32, h: 32 };
    const tok = (ctrl._mountsTok = {});
    ctrl.setIcon(null);
    iconOf(sys, i, Math.max(16, b.w || 32), Math.max(16, b.h || 32)).then(ic => { if (ctrl._mountsTok === tok) ctrl.setIcon(ic || null); });
  }
  ctrl.setCount?.(count != null ? count : (typeof x === 'object' && x.count > 1 ? x.count : ''));
  if (ctrl.el) ctrl.el.style.opacity = dimmed ? '0.5' : '';
  ctrl.setTooltip(() => tooltipOf(sys, x));
}
export function tooltipOf(sys, x) {
  const it = items(sys);
  if (it?.tooltip) { try { return it.tooltip(typeof x === 'object' ? x : idxOf(x)); } catch { /* fall through */ } }
  return itemName(sys, x);
}

/** The window's registration kit (items system Crafting), created on first use; null without the items system. */
export function kitOf(sys, win) {
  if (!win) return null;
  if (win.data.kit !== undefined) return win.data.kit;
  const it = items(sys);
  win.data.kit = CRAFT?.Crafting && it?.bag ? new CRAFT.Crafting(it, win, win.name) : null;
  return win.data.kit;
}

/**
 * Let a slot control take an item from the bag: dragged onto it or right-clicked in the bag while the window is open.
 * accept(inst, def) -> true | string (refusal message) | false; drop(inst) when registered. The control's
 * data.onClear() runs when the item is taken back out (right click / drag out). With the items system the item is
 * REGISTERED (stays in the bag, dimmed and locked) like the original; without it the drag payload is used directly.
 */
export function acceptItem(sys, ctrl, accept, drop) {
  const kit = kitOf(sys, ctrl.win);
  if (kit) {
    const slot = kit.slot(ctrl, {
      accept: (inst, def) => { const r = accept(inst, def); return r === true ? true : (typeof r === 'string' ? r : null); },
      onChange: (s) => { if (s.inst) drop(s.inst); else ctrl.data.onClear?.(); },
    });
    ctrl.data.slot = slot;
    return slot;
  }
  ctrl.acceptDrop({
    accept: (d) => d?.kind === 'item' || d?.inst || d?.itemIndex,
    drop: (d) => {
      const inst = d.inst || { itemIndex: d.itemIndex, count: d.count || 1 };
      const r = accept(inst, itemDef(sys, inst));
      if (r !== true) { if (typeof r === 'string') sys.log(r, 'err'); return false; }
      drop(inst, d);
      return true;
    },
  });
  // right click clears the registered item (the original's way to take it back out)
  ctrl.onRightClick?.(() => { if (ctrl.data.item) { ctrl.data.onClear?.(); setSlot(sys, ctrl, null); } });
  return null;
}

/** A bag item right-clicked while the window is open goes to the first free slot that accepts it. */
export function offerToKit(sys, win, inst) {
  const kit = win?.data?.kit;
  if (!kit || !inst) return false;
  const def = itemDef(sys, inst);
  let refusal = null;
  for (const pass of [0, 1]) {
    for (const s of kit.slots) {
      if (s.opts.view || (pass === 0 && s.inst)) continue;
      if (s.ctrl?.el && !s.ctrl.el.getClientRects().length) continue;     // on a hidden page / tab
      const r = s.opts.accept ? s.opts.accept(inst, def, s) : true;
      if (r === true) return s.put(inst);
      if (!refusal && typeof r === 'string') refusal = r;
    }
  }
  if (refusal) sys.log(refusal, 'err');
  return false;
}

/**
 * Kit lifecycle of a window (called from windows.js for every mounts window). bag: open the bag beside the window
 * (the NPC crafting windows); without it only the right-click offer and the registration are active.
 */
export function kitOpened(sys, win, arg, { bag = true } = {}) {
  const k = win?.data?.kit;
  if (!k) return;
  const offer = (inst) => offerToKit(sys, win, inst);
  if (bag) { k.opened(win, arg, offer); return; }
  const npc = arg?.npc || arg;
  k.npc = npc && npc.kind === 'npc' ? npc : null;
  k.sys.craftOffer = (inst) => (win.isOpen ? offer(inst) : false);
  k.sys.craftWin = k.name;
  k.fixMarkup();
}
export function kitClosed(win) { win?.data?.kit?.closed(); }
export function kitTick(win) { win?.data?.kit?.tick(win); }

/** Tab-button group: check one button, show the page of the checked tab. */
export function tabs(win, pairs, onChange) {
  const sel = (i) => {
    // a page may belong to several tabs (the pet window's inventory): hide the others' pages first, then show
    const show = new Set([].concat(pairs[i]?.[1] || []));
    pairs.forEach(([btn, page], k) => {
      win.control(btn).setChecked(k === i);
      for (const p of [].concat(page || [])) if (!show.has(p)) win.control(p).setVisible(false);
    });
    // (a page the script leaves `enable false`, e.g. the vehicle window's evolution page, becomes usable when shown)
    for (const p of show) win.control(p).setVisible(true).setEnabled?.(true);
    onChange?.(i);
  };
  pairs.forEach(([btn], k) => win.control(btn).onClick(() => sel(k)));
  return sel;
}

/** Labels whose script text carries client markup (<color=..>, <font=..>) are drawn as rich text. */
export function richify(win) {
  for (const c of win.all || []) {
    const t = typeof c.getText === 'function' ? c.getText() : null;
    if (t && /<(color|font|center)/i.test(String(t)) && typeof c.setRichText === 'function') c.setRichText(String(t));
  }
}

/** A client string (group NORMAL by default) through the window's string tables, with a fallback. */
export function str(win, cate, code, fallback = '', group = 'NORMAL') {
  const v = win?.mgr?.strings?.get({ group, cate, code });
  return v != null ? String(v) : fallback;
}

// ------------------------------------------------------------------ 3D preview
/**
 * Rotating 3D preview drawn into a panel: the player's body with a costume / wing, or a pet / mount model.
 * Rendered only when something changes (rotate / zoom / model), off-screen with the shared renderer.
 */
export class ModelPreview {
  /**
   * cover: the script's black panel over the render-target panel (costume / wing windows' pan_bg_black layer 131 over
   * pan_bg common#65500, the pet windows' pan_effect_bg layer 1000 over pan_preview_bg). It is the preview's black
   * backdrop: the model is drawn on top of it (inside it), as the client draws its render target over the black.
   */
  constructor(sys, panel, { w = null, h = null, background = null, cover = null } = {}) {
    this.sys = sys;
    this.game = sys.game;
    this.panel = panel;
    this.cover = cover && !cover.missing ? cover : null;
    this.w = w || panel.box?.w || 336;
    this.h = h || panel.box?.h || 336;
    this.yaw = 0.35;
    this.zoom = 1;
    this.obj = null;
    this._disposers = [];
    this.canvas = document.createElement('canvas');
    this.canvas.width = this.w; this.canvas.height = this.h;
    this.background = background;
    this._token = 0;
  }

  /** Bind the four original buttons of the preview frame. */
  bindButtons(win, { left = 'btn_rot_left', right = 'btn_rot_right', zin = 'btn_zoom_in', zout = 'btn_zoom_out' } = {}) {
    const hold = (id, fn) => { const c = win.find(id); if (!c) return; c.on('down', () => { this._hold = fn; }); c.on('up', () => { this._hold = null; }); c.on('out', () => { this._hold = null; }); c.onClick(() => fn(0.25)); };
    hold(left, d => this.rotate(-d));
    hold(right, d => this.rotate(d));
    hold(zin, d => this.setZoom(this.zoom * (1 + d * 0.6)));
    hold(zout, d => this.setZoom(this.zoom / (1 + d * 0.6)));
  }
  tick(dt) {
    if (this._hold) this._hold(dt * 2.2);
    let animated = false;
    this.obj?.traverse(o => { if (o.userData.wingMotion) { o.userData.wingMotion.update(dt); animated = true; } });
    if (animated) this.render();
  }
  rotate(d) { this.yaw += d; this.render(); }
  setZoom(z) { this.zoom = Math.max(0.5, Math.min(3, z)); this.render(); }

  clear() {
    this._token++;
    for (const d of this._disposers.splice(0)) { try { d(); } catch { /* ignore */ } }
    this.obj = null;
    if (this._box) this._box.style.display = 'none';
  }

  /** Fade the drawn model in (after a change was applied). */
  fadeIn(ms = 900) {
    const b = this._box;
    if (!b) return;
    b.style.transition = 'none'; b.style.opacity = '0';
    requestAnimationFrame(() => requestAnimationFrame(() => { b.style.transition = `opacity ${ms}ms ease-out`; b.style.opacity = '1'; }));
  }

  /** The canvas fills the whole panel (item slots draw their icons at the cell size, so it is not an icon). */
  _show() {
    const el = this.cover?.el || this.panel?.el;
    if (!el) return;
    if (!this._box || this._box.parentNode !== el) {
      const b = this._box || document.createElement('div');
      b.className = 'mounts-preview';
      Object.assign(b.style, { position: 'absolute', left: '0', top: '0', width: '100%', height: '100%', zIndex: '1', pointerEvents: 'none' });
      Object.assign(this.canvas.style, { width: '100%', height: '100%', display: 'block' });
      if (this.canvas.parentNode !== b) b.appendChild(this.canvas);
      el.appendChild(b);
      this._box = b;
    }
    this._box.style.display = '';
    if (this.cover && !this.cover.isVisible?.()) this.cover.show?.();
  }

  /** The player's current body (+ costume asset replacing its parts, + wing item on weaponW). */
  async showPlayer({ costume = null, wing = null } = {}) {
    const tok = ++this._token;
    this.aura = null;
    const g = this.game, p = g.player, sys = this.sys;
    if (!p) return;
    let parts = (typeof p.partDefs === 'function' ? p.partDefs() : []).slice();
    if (costume) {
      const c = sys.data.costume(costume, Number(p.classIndex ?? 0));
      if (c) {
        const eq = g.save?.equipment || {};
        const low = s => String(s || '').toLowerCase();
        // the worn costume comes off first: its mesh goes, the slots it covered get their armour (or bare) part back
        const worn = sys.costume?.active?.();
        if (worn) {
          const wornMesh = low(worn.asset.mesh);
          parts = parts.filter(d => low(d.meshKey) !== wornMesh);
          for (const x of p.classDef?.parts || []) {
            if (!worn.parts.includes(x.slot) || c.parts.includes(x.slot)) continue;
            const e = eq[x.slot];
            const mesh = e && !e.costume && e.mesh ? e : x;
            parts.push({ meshKey: mesh.mesh, tpackKey: mesh.tpack || null, textures: mesh.textures || null });
          }
        }
        const covered = new Set((p.classDef?.parts || []).filter(x => c.parts.includes(x.slot)).flatMap(x => [low(eq[x.slot]?.mesh), low(x.mesh)]));
        parts = parts.filter(d => !covered.has(low(d.meshKey)));
        parts.push({ meshKey: c.asset.mesh, tpackKey: c.asset.tpack || null, textures: c.asset.textures || null });
      }
    }
    const model = await g.models.loadSkinned({ skelKey: p.classDef.skeleton, parts });
    if (tok !== this._token || !model) return;
    const inst = model.instantiate();
    const idle = p.anims?.idlePeace || p.anims?.idle;
    if (idle?.anim) {
      const clip = await g.models.loadClip(idle.anim, model, { duration: idle.timeLength || null }).catch(() => null);
      if (clip) { const m = new THREE.AnimationMixer(inst.root); m.clipAction(clip).play(); m.setTime(0.1); }
    }
    const extra = [];                         // (disposed with the body, never before it is shown)
    if (wing) {
      const w = sys.data.wing(wing);
      if (w) {
        let wobj = null;
        if (w.table?.skel) {
          const wm = await g.models.loadSkinned({ skelKey: w.table.skel, parts: [{ meshKey: w.asset.mesh, tpackKey: w.asset.tpack || null, textures: w.asset.textures || null }] });
          if (wm) {
            const wi = wm.instantiate(); wobj = wi.root; extra.push(() => wi.dispose());
            const row = sys.data.row(w.table, 1, 0, 0);
            if (row) { const c = await g.models.loadClip(row.anim, wm, { duration: row.timeLength }).catch(() => null); if (c) { const m = new THREE.AnimationMixer(wi.root); m.clipAction(c).play(); m.setTime(0.1); } }
          }
        }
        if (!wobj) { const sm = await g.models.loadStatic(w.asset.mesh, { tpackKey: w.asset.tpack || null, textures: w.asset.textures || null, twoSide: true }); if (sm) wobj = sm.instantiate(); }
        if (wobj) { inst.attach(wobj, sys.data.core?.wingBone || 'weaponW'); if (wobj.userData.wingMotion) extra.push(() => wobj.userData.wingMotion.dispose()); }
      }
    }
    const dispose = () => { for (const d of extra) { try { d(); } catch { /* ignore */ } } inst.dispose(); };
    if (tok !== this._token) { dispose(); return; }
    this._set(inst.root, dispose);
  }

  /** A skinned model with its STAND pose: {mesh, tpack, textures, skel, anim, timeLength}. */
  async showModel(m) {
    const tok = ++this._token;
    const g = this.game;
    this.aura = null;
    if (!m?.mesh) { this.clear(); return; }
    let root = null, dispose = () => {};
    if (m.skel) {
      const model = await g.models.loadSkinned({ skelKey: m.skel, parts: [{ meshKey: m.mesh, tpackKey: m.tpack || null, textures: m.textures || null }] });
      if (model) {
        const inst = model.instantiate(); root = inst.root; dispose = () => inst.dispose();
        if (m.anim) { const c = await g.models.loadClip(m.anim, model, { duration: m.timeLength || null }).catch(() => null); if (c) { const mx = new THREE.AnimationMixer(inst.root); mx.clipAction(c).play(); mx.setTime(0.1); } }
      }
    }
    if (!root) { const sm = await g.models.loadStatic(m.mesh, { tpackKey: m.tpack || null, textures: m.textures || null }); if (sm) root = sm.instantiate(); }
    if (tok !== this._token) { dispose(); return; }
    if (root) this._set(root, dispose);
  }

  _set(root, dispose) {
    for (const d of this._disposers.splice(0)) { try { d(); } catch { /* ignore */ } }
    this._disposers.push(dispose);
    this.obj = root;
    this.render();
    // textures arrive after the meshes: draw again while they stream in
    for (const ms of [350, 1000, 2500]) setTimeout(() => { if (this.obj === root) this.render(); }, ms);
  }

  /** Render the model into the canvas, framed from its drawn silhouette (a measured fit, then the final draw). */
  render() {
    const g = this.game, r = g.renderer;
    if (!this.obj || !r) return;
    const scene = new THREE.Scene();
    const mirror = new THREE.Group();
    mirror.scale.copy(WORLD_MIRROR);
    scene.add(mirror);
    const turn = new THREE.Group();
    turn.rotation.y = this.yaw;
    mirror.add(turn);
    turn.add(this.obj);
    // PREVIEW_LIGHT (config/engine-chosen-preview-light.js); globalThis.__dekaronPreviewLight = {ambient, key} overrides it
    // for test-client measurements
    const L = globalThis.__dekaronPreviewLight || PREVIEW_LIGHT;
    scene.add(new THREE.AmbientLight(0xffffff, L.ambient));
    const sun = new THREE.DirectionalLight(0xffffff, L.key); sun.position.set(-0.5, 1, 1.2); scene.add(sun);
    scene.updateMatrixWorld(true);
    const W = this.w, H = this.h, FOV = 30, tanH = Math.tan(THREE.MathUtils.degToRad(FOV / 2));
    const cam = new THREE.PerspectiveCamera(FOV, W / H, 0.05, 400);
    const rt = new THREE.WebGLRenderTarget(W, H, { depthBuffer: true });
    const px = new Uint8Array(W * H * 4);
    let auraPx = null, weaponPx = null;
    // a glowing model leaves room around it for its aura (86 % of the frame otherwise)
    const fill = this.aura?.length ? 0.74 : 0.86;
    const prevT = r.getRenderTarget(), prevC = r.getClearColor(new THREE.Color()), prevA = r.getClearAlpha(), prevS = r.shadowMap.enabled;
    const draw = (target, dist) => {
      cam.position.set(target.x, target.y, target.z + dist);
      cam.lookAt(target);
      cam.updateMatrixWorld(true);
      r.setRenderTarget(rt);
      r.setClearColor(0x000000, 0);
      r.clear(true, true, true);
      r.render(scene, cam);
      readRenderTargetPixels(r, rt, 0, 0, W, H, px);
    };
    // drawn bounds (rows of px are bottom-up)
    const bounds = () => {
      let x0 = W, x1 = -1, y0 = H, y1 = -1;
      for (let y = 0; y < H; y++) for (let x = 0; x < W; x++) if (px[(y * W + x) * 4 + 3] > 8) { if (x < x0) x0 = x; if (x > x1) x1 = x; if (y < y0) y0 = y; if (y > y1) y1 = y; }
      return x1 < 0 ? null : { x0, x1, y0, y1 };
    };
    try {
      r.shadowMap.enabled = false;
      // first guess from the geometry bounds
      const box = new THREE.Box3();
      this.obj.traverse(n => { if (n.isMesh) { n.geometry.computeBoundingBox?.(); const b = n.geometry.boundingBox?.clone().applyMatrix4(n.matrixWorld); if (b) box.union(b); } });
      if (box.isEmpty()) return;
      const target = box.getCenter(new THREE.Vector3());
      const sz = box.getSize(new THREE.Vector3());
      let dist = Math.max(sz.y, sz.x * H / W, 0.2) * 0.5 / tanH + sz.z * 0.5;
      // measured fit: the silhouette fills 86 % of the frame, centred (two corrections)
      for (let k = 0; k < 2; k++) {
        draw(target, dist);
        const b = bounds();
        if (!b) { dist *= 2; continue; }
        const viewH = 2 * dist * tanH, viewW = viewH * W / H;
        const cx = (b.x0 + b.x1 + 1) / 2 / W - 0.5, cy = (b.y0 + b.y1 + 1) / 2 / H - 0.5;
        target.x += cx * viewW; target.y += cy * viewH;
        dist *= Math.max((b.x1 - b.x0 + 1) / W, (b.y1 - b.y0 + 1) / H) / fill;
      }
      draw(target, dist / this.zoom);
      if (this.aura?.length) { try { auraPx = renderAuraPass(r, scene, cam, rt, this.aura, W, H); const w = this.aura.filter(s => s.part === 'weapon'); if (w.length) weaponPx = renderAuraPass(r, scene, cam, rt, w, W, H); } catch (err) { console.warn('[preview] aura pass failed', err); } }   // the glowing parts, flat, same camera
    } finally {
      r.setRenderTarget(prevT); r.setClearColor(prevC, prevA); r.shadowMap.enabled = prevS; rt.dispose();
      turn.remove(this.obj);
    }
    const ctx = this.canvas.getContext('2d');
    const img = ctx.createImageData(W, H);
    for (let y = 0; y < H; y++) img.data.set(px.subarray((H - 1 - y) * W * 4, (H - y) * W * 4), y * W * 4);
    ctx.putImageData(img, 0, 0);
    if (auraPx) { try { compositeAura(ctx, auraPx, W, H); if (weaponPx) compositeAura(ctx, weaponPx, W, H, true); } catch (err) { console.warn('[preview] aura composite failed', err); } }
    this._show();
  }

  dispose() { this.clear(); this._box?.remove(); this._box = null; }
}
