import { readRenderTargetPixels } from '../../engine/pixel-pack-readback.js';
// Item "icons": the original inventory draws each item's inventory 3D model (items-visual.json shapes[shape].inv,
// items.md 7.1, property/item/<n>.txt inv_mesh / inv_skel / inv_anim) in its w x h cell area, SPINNING. The
// inventory .anim files are exactly that spin: one bone turning 360 deg about Y over the loop (invAnimTime, 2 s;
// e.g. att_inv_wip_20, stone_18; coats add a base tilt). Static inventory meshes (no anim) turn about their vertical
// axis at the same rate (camera orbit, same direction as the anim).
//
// Rendering (fast): every (model, pixel size) is rendered ONCE through the shared renderer into one offscreen target:
//   get(i, w, h)  / now()      -> {url}                    a still (frame 0), for any consumer
//   spin(i, w, h) / spinNow()  -> {url, spin: {url, cols, rows, n, period}}   a cached sprite sheet of SPIN_FRAMES
//                                 frames; uiwin paintIcon() plays it with a CSS steps() animation on the shared clock
// FILE frame under the mirror root, NoColorSpace textures, orthographic fit (64 units per inventory cell, invScale),
// lit from the viewer. Items without an inventory model use noItem.
import * as THREE from 'three';
import { PreviewCache, previewReload } from '../../ui/preview-cache.js';
import { PreviewQueue, PreviewPreparation } from './preview-queue.js';
import { WORLD_MIRROR } from '../../engine/space.js';
import { inventoryMaterials, refinementTier, ICON_LIGHT } from './preview-materials.js';
import { bakeSlices, captureBakeRenderer, restoreBakeRenderer } from './bake-slices.js';
import { AuthoredEffectsData } from './authored-effects-data.js';
import { previewRefinement, preparePreviewRefinement, compositeTierAura } from './preview-refinement.js';
import { previewBlobUrl as blobUrl } from './preview-export.js';
import { preparePreviewGlow, compositePreviewGlow, previewGlowRGBA } from './preview-glow.js';
import { prepareSocketGlow, compositeSocketGlow } from './preview-socket-glow.js';

/** Cache-key part of a socket glow variant ({key, gems}): icons of the same item with different stones are different bakes. */
const glowKey = glow => (glow?.gems?.length ? `|glow:${glow.key}` : '');

export const SPIN_FRAMES = 32;        // 11.25 deg per frame, 16 fps at the 2 s loop
const SHEET_MAX = 4096;               // max sheet width / height (px)


export class Icons {
  constructor(sys) {
    this.sys = sys;
    this.cache = new PreviewCache();   // key -> {url, spin?} | Promise; clear expires in-flight bakes
    this.queue = new PreviewQueue();
    this.preparation = new PreviewPreparation(4);
  }
  _glowEnabled() { return (this.sys.game?.options?.get?.('bloom') ?? this.sys.game?.settings?.bloom ?? true) !== false; }
  /** Requests made synchronously inside fn are background prefetch: baked as usual, but queue.idle() does not wait for them. */
  background(fn) { this._background = (this._background || 0) + 1; try { return fn(); } finally { this._background--; } }
  /** Inventory model descriptor of an item index: {mesh, tpack, textures, anim?, skel?, animTime, twoSide, scale}. */
  model(itemIndex) {
    const db = this.sys.db;
    const def = db.def(itemIndex);
    const sh = db.shape(def);
    const inv = sh?.inv || sh?.game || sh?.field || null;
    if (inv?.mesh) {
      const sc = Number(sh.invScale);
      return { ...inv, glow: this._glowEnabled(), refinement: refinementTier(def, sh), nativeRefinement: previewRefinement(def), anim: inv.anim || sh.invAnim || null, skel: inv.skel || sh.invSkel || null,
        animTime: Number(sh.invAnimTime) || 2, twoSide: sh.invTwoSide !== false, scale: sc > 0 ? sc : 1 };
    }
    const ni = db.visual?.noItem;
    const m = ni?.inv || ni?.game || ni;
    return m?.mesh ? { ...m, glow: this._glowEnabled(), anim: m.anim || ni.invAnim || null, skel: m.skel || ni.invSkel || null,
      animTime: Number(ni.invAnimTime) || 2, twoSide: true, scale: 1 } : null;
  }
  // `cells` (optional): the image spans these many inventory cells (an equipment slot rect / its script cellsize)
  // instead of the item's own footprint, so the model keeps the slot's per-cell scale and may use the whole slot.
  /** Promise<{url}|null>: the still icon at w x h reference px. */
  // `glow` (optional, every method below): the socket glow of THIS item instance, {key, gems:[{x, y, size, attribute}]} in the
  // icon's own reference px (see socketIconGlow in ui/common.js). Same item + different stones = a different bake.
  get(itemIndex, w, h, cells = null, glow = null) { return this._get(itemIndex, w, h, false, cells, glow); }
  /** Sync still icon if already rendered (else null; call get() to render). */
  now(itemIndex, w, h, cells = null, glow = null) { return this._readyAlias(itemIndex, Math.round(w), Math.round(h), false, cells, glow); }
  /** Promise<{url, spin}|null>: the spinning icon (sprite sheet) at w x h reference px. */
  spin(itemIndex, w, h, cells = null, glow = null) { return this._get(itemIndex, w, h, true, cells, glow); }
  /** Sync spinning icon if already rendered (else null; call spin() to render). */
  spinNow(itemIndex, w, h, cells = null, glow = null) { return this._readyAlias(itemIndex, Math.round(w), Math.round(h), true, cells, glow); }

  /** Reuse this item's original cached model while a different-size bake is pending (never a socket-glow variant). */
  cached(itemIndex) {
    const prefix = `${itemIndex}|`, spinPrefix = `s|${prefix}`;
    let still = null;
    for (const [key, value] of this.cache) {
      if (!value?.url || value.then) continue;
      if (key.includes('|glow:')) continue;
      if (!key.endsWith(`|g${this._glowEnabled() ? 1 : 0}`)) continue;
      if (key.startsWith(spinPrefix)) return value;
      if (key.startsWith(prefix)) still ||= value;
    }
    return still;
  }

  _now(key) { const v = this.cache.get(key); return v && !v.then && v.url && !(v.nativeRefinementRetryAt && performance.now() >= v.nativeRefinementRetryAt) ? v : null; }
  _modelKey(itemIndex, w, h, spin, m = this.model(itemIndex), span = null, glow = null) {
    if (!m) return null;
    const def=this.sys.db.def(itemIndex),cells=span||[Math.max(1,def?.w|0||1),Math.max(1,def?.h|0||1)];
    return `${spin ? 's|' : ''}${m.mesh}|${m.tpack || ''}|${m.skel || ''}|${m.anim || ''}|${m.animTime}|${m.twoSide}|${JSON.stringify(m.textures || null)}|${m.scale}|f${m.refinement || 0}|u${JSON.stringify(m.nativeRefinement)}|${w}x${h}|${cells}${glowKey(glow)}|g${m.glow ? 1 : 0}`;
  }
  _readyAlias(itemIndex, w, h, spin, cells = null, glow = null) {
    const span=spanCells(cells),key=`${spin?'s|':''}${itemIndex}|${w}x${h}${spanKey(span)}${glowKey(glow)}|g${this._glowEnabled() ? 1 : 0}`,hit=this._now(key);
    if(hit)return hit;
    const m=this.model(itemIndex);if(!m)return null;
    let ready=this._now(this._modelKey(itemIndex,w,h,spin,m,span,glow));
    // A completed spin owns the separately exported frame-zero still already.
    if(!ready&&!spin){const sheet=this._now(this._modelKey(itemIndex,w,h,true,m,span,glow));if(sheet)ready=this.cache.alias({url:sheet.url,nativeRefinementRetryAt:sheet.nativeRefinementRetryAt},sheet);}
    if(ready)this.cache.set(key,ready);
    return ready;
  }

  _get(itemIndex, w, h, spin, span = null, glow = null) {
    w = Math.round(w); h = Math.round(h); span = spanCells(span);
    if (!glow?.gems?.length) glow = null;
    const key = `${spin ? 's|' : ''}${itemIndex}|${w}x${h}${spanKey(span)}${glowKey(glow)}|g${this._glowEnabled() ? 1 : 0}`;
    const generation = this.cache.generation, background = this._background > 0;
    const warm=this._readyAlias(itemIndex,w,h,spin,span,glow);
    if(warm)return Promise.resolve(warm);
    const hit = this.cache.get(key);
    // A foreground request that joins a background bake makes it foreground work (queue.idle waits for it).
    if (hit?.then || (hit?.url && !(hit.nativeRefinementRetryAt && performance.now() >= hit.nativeRefinementRetryAt))) return hit.then ? (background ? hit : this.queue.track(hit)) : Promise.resolve(hit);
    if (hit && performance.now() < (hit.retryAt || 0)) return Promise.resolve(null);
    if (hit) this.cache.delete(key);
    const m = this.model(itemIndex);
    const g = this.sys.game;
    if (!m || !g.renderer || !g.models) return Promise.resolve(null);
    const def = this.sys.db.def(itemIndex);
    const cells = span || [Math.max(1, def?.w | 0 || 1), Math.max(1, def?.h | 0 || 1)];
    const mk = this._modelKey(itemIndex,w,h,spin,m,span,glow);
    let shared = this.cache.get(mk);
    if (shared?.nativeRefinementRetryAt && performance.now() >= shared.nativeRefinementRetryAt) { this.cache.delete(mk); shared = null; }
    if (shared && !shared.then && !shared.url && performance.now() >= (shared.retryAt || 0)) { this.cache.delete(mk); shared = null; }
    const ready = shared?.then ? shared : shared ? Promise.resolve(shared.url ? shared : null) : this.preparation.add(async () => {
      if (generation !== this.cache.generation) return null;
      const data = m.nativeRefinement || glow ? (this.sys.authoredEffects?.data || (this._effectData ||= new AuthoredEffectsData())) : null;
      const prepared = await prepareDraw(g, m, data, glow);
      if (!prepared) return null;
      try {
        if (generation !== this.cache.generation) return null;
        const result = await this.queue.add(checkpoint => generation === this.cache.generation ? draw(g, m, w, h, cells, spin ? SPIN_FRAMES : 1, prepared, checkpoint, glow) : null, spin ? 1 : 0, background);
        if (result && (prepared.refinementMissing || prepared.socketGlowMissing)) result.nativeRefinementRetryAt = performance.now() + 1000;
        return result;
      } finally { prepared.refinement?.dispose(); prepared.o.dispose(); }
    }, spin ? 1 : 0);
    const p = ready.then(v => {
      if (generation !== this.cache.generation) {
        if (v?.url?.startsWith('blob:')) URL.revokeObjectURL(v.url);
        if (v?.spin?.url?.startsWith('blob:')) URL.revokeObjectURL(v.spin.url);
        return null;
      }
      const bytes = Math.max(8, w * 2) * Math.max(8, h * 2) * 4 * (spin ? SPIN_FRAMES + 1 : 1);
      const out = v?.url ? this.cache.remember(v, bytes, previewReload(this, itemIndex, w, h, spin, generation, span, glow)) : { url: null, retryAt: performance.now() + 1000 };
      this.cache.set(key, out);
      if (!out.url && (!shared || this.cache.get(mk) === shared)) this.cache.set(mk, out);
      if (out.url) {
        this.cache.set(mk, out);
        // a spin render also gives the still (its frame 0)
        const sk = `${itemIndex}|${w}x${h}${spanKey(span)}${glowKey(glow)}|g${m.glow ? 1 : 0}`;
        if (spin) {
          // The completed original sheet already owns frame zero. Reuse it for
          // both still aliases without touching the obsolete standalone still.
          const still = this.cache.alias({ url: out.url, nativeRefinementRetryAt: out.nativeRefinementRetryAt }, out);
          this.cache.set(sk, still);
          this.cache.set(this._modelKey(itemIndex, w, h, false, m, span, glow), still);
        }
      }
      return out.url ? out : null;
    }).catch((err) => { console.warn('[items] icon', m.mesh, err); if (generation === this.cache.generation) { const out = { url: null, retryAt: performance.now() + 1000 }; this.cache.set(key, out); if (!shared || this.cache.get(mk) === shared) this.cache.set(mk, out); } return null; });
    this.cache.set(key, p);
    if (!shared) this.cache.set(mk, p);
    return this.queue.track(p, background);
  }
}

/** A cell span override [w, h] (> 0, fractional allowed), rounded so equal spans share cache entries; else null. */
function spanCells(cells) {
  if (!Array.isArray(cells) || cells.length !== 2) return null;
  const s = cells.map(v => Math.round(Number(v) * 1000) / 1000);
  return s.every(v => v > 0) ? s : null;
}
const spanKey = span => (span ? `|c${span[0]},${span[1]}` : '');
async function loadObject(g, m) {
  if (m.anim && m.skel) {
    const model = await g.models.loadSkinned({ skelKey: m.skel, parts: [{ meshKey: m.mesh, tpackKey: m.tpack || null, textures: m.textures || null }] });
    if (model) {
      const inst = model.instantiate();
      const clip = await g.models.loadClip(m.anim, model, { duration: m.animTime || 2 }).catch(() => null);
      let mixer = null;
      if (clip) {
        mixer = new THREE.AnimationMixer(inst.root);
        mixer.clipAction(clip).play();
        mixer.setTime(0);
      }
      inst.root.updateMatrixWorld(true);
      inventoryMaterials(inst.root, g.models, m.twoSide, m.nativeRefinement ? 0 : m.refinement);
      return { obj: inst.root, mixer, duration: clip?.duration || m.animTime || 2, dispose: () => inst.dispose?.() };
    }
  }
  const model = await g.models.loadStatic(m.mesh, { tpackKey: m.tpack || null, textures: m.textures || null, twoSide: m.twoSide !== false });
  if (!model) return null;
  const obj = model.instantiate();
  inventoryMaterials(obj, g.models, m.twoSide !== false, m.nativeRefinement ? 0 : m.refinement);
  return { obj, mixer: null, duration: m.animTime || 2, dispose: () => obj.userData.wingMotion?.dispose() };
}

// inventory meshes are modelled at 64 units per inventory cell (att_inv_swd_21: 1 x 3 cells, 190 units tall;
// potion_01: 1 x 1, 62 units): small models keep that scale, larger ones shrink to fit the footprint
const UNITS_PER_CELL = 64;

/** Bounds (scene space) of an object in its current pose; skinned meshes use their posed vertices. */
function expandBox(obj, box) {
  const v = new THREE.Vector3();
  obj.traverse(n => {
    if (n.isSkinnedMesh) {
      const pos = n.geometry.attributes.position;
      for (let i = 0; i < pos.count; i++) { n.getVertexPosition(i, v); v.applyMatrix4(n.matrixWorld); box.expandByPoint(v); }
    } else if (n.isMesh) { n.geometry.computeBoundingBox?.(); const b = n.geometry.boundingBox?.clone().applyMatrix4(n.matrixWorld); if (b) box.union(b); }
  });
  return box;
}

/** Sheet columns: the largest divisor of `frames` whose row fits SHEET_MAX. */
function sheetCols(frames, W, maxW) {
  for (let c = frames; c >= 1; c--) if (frames % c === 0 && c * W <= maxW) return c;
  return 1;
}


async function prepareDraw(g, m, effectData, glow = null) {
  if (m.nativeRefinement && effectData) void effectData.inventoryUpgradeReference(m.nativeRefinement.tier).catch(() => {});
  const o = await loadObject(g, m);
  if (!o) return null;
  try {
    let socketGlowMissing = false;
    const socketAssets = glow && effectData ? await prepareSocketGlow(effectData, glow).catch(error => {
      socketGlowMissing = true;
      console.warn('[items] socket glow preview', error.message);
      return null;
    }) : null;
    let refinementMissing = false;
    const refinement = m.nativeRefinement ? await preparePreviewRefinement(g, o.obj, m.nativeRefinement, effectData).catch(error => {
      refinementMissing = true;
      console.warn('[items] refinement preview', error.message);
      inventoryMaterials(o.obj, g.models, m.twoSide, m.refinement);
      return null;
    }) : null;
    return {o, refinement, refinementMissing, socketAssets, socketGlowMissing};
  } catch (error) { o.dispose(); throw error; }
}

async function draw(g, m, w, h, cells = [1, 1], frames = 1, prepared, checkpoint, socketGlow = null) {
  const {o, refinement} = prepared;
  const S = 2;
  const W = Math.max(8, Math.round(w * S)), H = Math.max(8, Math.round(h * S));
  const scene = new THREE.Scene();
  const root = new THREE.Group();
  root.scale.copy(WORLD_MIRROR);
  scene.add(root);
  const holder = new THREE.Group();
  holder.scale.setScalar(m.scale || 1);   // invScale
  holder.add(o.obj);
  root.add(holder);
  // itemmesh.fx lighting in three's x PI units (ICON_LIGHT, clamped materials). The engine-designed wings (wing-models.js,
  // not original assets, their own unclamped materials) keep the light they were tuned under.
  const designed = !!o.obj.userData?.model?.flags?.authoredWing;
  scene.add(new THREE.AmbientLight(0xffffff, designed ? 0.75 : ICON_LIGHT.ambient));
  const cam = new THREE.OrthographicCamera(-1, 1, 1, -1, 0.01, 1000);
  // the key light is fixed to the viewer (as before), so a turning model is lit like the original
  const sun = new THREE.DirectionalLight(0xffffff, designed ? 1.15 : ICON_LIGHT.key);
  sun.position.set(-0.4, 0.8, 1);
  cam.add(sun); cam.add(sun.target);
  scene.add(cam);
  const T = o.mixer ? o.duration : (m.animTime || 2);
  const pose = (k) => { if (o.mixer) o.mixer.setTime((k / frames) * T); o.obj.userData.wingMotion?.sample((k / frames) * T); root.updateMatrixWorld(true); };

  // bounds: every pose of an animated spin; a static mesh once (its orbit radius is used for the width)
  const box = new THREE.Box3();
  const nPose = o.mixer && frames > 1 ? frames : 1;
  await bakeSlices(nPose, k => { pose(k); expandBox(o.obj, box); }, undefined, undefined, undefined, checkpoint);
  if (box.isEmpty()) { root.remove(holder); return null; }
  if (refinement?.padding) box.expandByScalar(refinement.padding * (m.scale || 1));
  const c = box.getCenter(new THREE.Vector3()), sz = box.getSize(new THREE.Vector3());
  const orbit = !o.mixer && frames > 1;
  const halfX = orbit ? Math.hypot(sz.x, sz.z) / 2 : sz.x / 2;
  const aspect = W / H;
  const fixedH = Math.max(cells[1] * UNITS_PER_CELL / 2, cells[0] * UNITS_PER_CELL / 2 / aspect);
  // legacy / non-inventory meshes (world units, a few units tall) are fitted
  const small = Math.max(sz.x, sz.y) < 8;
  const fitH = Math.max(sz.y / 2, halfX / aspect);
  const halfH = small ? fitH * 1.06 : Math.max(fixedH, fitH * 1.02);
  const halfW = halfH * aspect;
  const dist = Math.hypot(sz.x, sz.y, sz.z) + 5;
  cam.left = -halfW; cam.right = halfW; cam.top = halfH; cam.bottom = -halfH;
  cam.near = 0.01; cam.far = dist * 2 + 10;
  cam.updateProjectionMatrix();
  const view = (k) => {
    // static meshes: orbit the camera (+a) = the model turning like the inventory anims (FILE +Y)
    const a = orbit ? (k / frames) * Math.PI * 2 : 0;
    cam.position.set(c.x + Math.sin(a) * dist, c.y, c.z + Math.cos(a) * dist);
    cam.lookAt(c);
    cam.updateMatrixWorld(true);
  };

  const r = g.renderer;
  const maxTex = Math.min(SHEET_MAX, r.capabilities?.maxTextureSize || SHEET_MAX);
  const cols = frames > 1 ? sheetCols(frames, W, maxTex) : 1;
  const rows = Math.ceil(frames / cols);
  const RW = W * cols, RH = H * rows;
  const rt = new THREE.WebGLRenderTarget(RW, RH, { depthBuffer: true });
  const pixels = new Uint8Array(RW * RH * 4);
  const glow = m.glow ? preparePreviewGlow(o.obj, !!refinement) : null;
  const glowTarget = glow ? new THREE.WebGLRenderTarget(RW, RH, { depthBuffer: true }) : null;
  const glowPixels = glow ? new Uint8Array(RW * RH * 4) : null;
  try {
    // 2.2.1: the item's shader variants are linked in parallel (KHR_parallel_shader_compile) before the first slice draws them.
    // A background bake used to link them inside the draw (getProgramInfoLog stalls of 50-160 ms in play, measured).
    if (typeof r.compileAsync === 'function') { try { await r.compileAsync(scene, cam); } catch { /* the draw compiles as before */ } }
    if (glow) { try { await glow.compile(r, scene, cam); } catch { /* the draw compiles as before */ } }
    await bakeSlices(frames, k => {
      if (k === 0) {
        rt.viewport.set(0, 0, RW, RH); r.setRenderTarget(rt);
        r.clear(true, true, true);
        if (glowTarget) { glowTarget.viewport.set(0, 0, RW, RH); r.setRenderTarget(glowTarget); r.clear(true, true, true); }
      }
      pose(k); view(k); refinement?.sample(k / frames, T);
      const col = k % cols, row = Math.floor(k / cols);
      rt.viewport.set(col * W, (rows - 1 - row) * H, W, H);   // GL rows start at the bottom
      r.setRenderTarget(rt);
      r.clearDepth();
      r.render(scene, cam);
      if (glowTarget) {
        glowTarget.viewport.copy(rt.viewport); r.setRenderTarget(glowTarget); r.clearDepth();
        glow.render(r, scene, cam);
      }
    }, () => {
      const state = captureBakeRenderer(r);
      r.shadowMap.enabled = false; r.autoClear = false;
      r.setScissorTest(false); r.setClearColor(0x000000, 0);
      return state;
    }, state => restoreBakeRenderer(r, state), undefined, checkpoint);
    rt.viewport.set(0, 0, RW, RH);
    if (r.readRenderTargetPixelsAsync) await r.readRenderTargetPixelsAsync(rt, 0, 0, RW, RH, pixels);
    else {
      const state = captureBakeRenderer(r);
      try { readRenderTargetPixels(r, rt, 0, 0, RW, RH, pixels); }
      finally { restoreBakeRenderer(r, state); }
    }
    if (glowTarget) {
      if (r.readRenderTargetPixelsAsync) await r.readRenderTargetPixelsAsync(glowTarget, 0, 0, RW, RH, glowPixels);
      else { const state = captureBakeRenderer(r); try { readRenderTargetPixels(r, glowTarget, 0, 0, RW, RH, glowPixels); } finally { restoreBakeRenderer(r, state); } }
    }
  } finally {
    rt.dispose(); glowTarget?.dispose(); glow?.dispose();
    root.remove(holder);
  }
  let cv = document.createElement('canvas');
  cv.width = RW; cv.height = RH;
  const ctx = cv.getContext('2d');
  const img = ctx.createImageData(RW, RH);
  for (let y = 0; y < RH; y++) img.data.set(pixels.subarray((RH - 1 - y) * RW * 4, (RH - y) * RW * 4), y * RW * 4);
  ctx.putImageData(img, 0, 0);
  if (glowPixels) {
    const halo = document.createElement('canvas'); halo.width = RW; halo.height = RH;
    const context = halo.getContext('2d'), image = context.createImageData(RW, RH);
    const rgba = previewGlowRGBA(glowPixels);
    for (let y = 0; y < RH; y++) image.data.set(rgba.subarray((RH - 1 - y) * RW * 4, (RH - y) * RW * 4), y * RW * 4);
    context.putImageData(image, 0, 0);
    cv = compositePreviewGlow(cv, halo, W, H, cols, rows, S);
  }
  // Refined weapons carry the tier-coloured aura in the inventory too (the overlay alone is invisible on small weapon models).
  if (refinement?.weapon && refinement.hue) cv = compositeTierAura(cv, refinement.hue, phase => refinement.alphaAt(phase, T), { W, H, cols, rows, frames, S });
  // Socket glow of the instance's stones (gem-coloured wash, halo and the authored UI sprite at each filled socket marker).
  if (socketGlow?.gems?.length && prepared.socketAssets) cv = compositeSocketGlow(cv, prepared.socketAssets, socketGlow, { W, H, cols, rows, frames, S, period: T });
  if (frames <= 1) return { url: await blobUrl(cv) };
  const still = document.createElement('canvas');
  still.width = W; still.height = H;
  still.getContext('2d').drawImage(cv, 0, 0, W, H, 0, 0, W, H);
  const [sheetUrl, stillUrl] = await Promise.all([blobUrl(cv), blobUrl(still)]);
  return { url: stillUrl, spin: { url: sheetUrl, cols, rows, n: frames, period: T } };
}
