// Original Dekaron UI art: the sprite table script/ui/com/imagetable.txt (docs/formats/ui.md §1) and
// the DDS/TGA/PNG atlases under texture/ui/. Sprites are cropped into their own canvases and exposed as
// blob/data URLs so the DOM HUD can use them as CSS backgrounds (stretched, nine-sliced via border-image).
// Everything degrades gracefully: without a DOM/canvas (Node tests) or when a file is missing, the
// lookups resolve null and the caller keeps its CSS fallback look.
import { fetchText, tryFetchBuffer, normPath } from '../engine/assets.js';
import { decodeImageAsync } from '../formats/image.js';
import { recordAtlasRequest } from '../engine/prefetch.js';

const IMAGETABLE = 'script/ui/com/imagetable.txt';
const PRELOADING = 'script/ui/com/preloading.txt';

/** Data key of an imagetable texture path ("UI\\Game\\Mainbar\\new_mainbar.dds" -> "texture/ui/game/mainbar/new_mainbar.dds"). */
export function textureKey(tex) {
  return normPath(`texture/${String(tex).trim()}`);
}

/**
 * Parse imagetable.txt (group,index,texture,x,y,w,h[,L,T,R,B],description).
 * Groups match case-insensitively; for duplicate (group,index) pairs the last line wins (ui.md §1).
 * @returns {Map<string, {group:string,index:number,tex:string,key:string,x:number,y:number,w:number,h:number,m:number[]}>}
 */
export function parseImageTable(text) {
  const map = new Map();
  for (const line of String(text).split(/\r?\n/)) {
    const c = line.split(',');
    if (c.length < 7) continue;
    const group = c[0].trim();
    const idx = c[1].trim();
    if (!group || !/^-?\d+$/.test(idx) || !c[2] || !c[2].trim()) continue;
    const nums = c.slice(3, 7).map(v => Number(v));
    if (nums.some(v => !Number.isFinite(v))) continue;
    // four lines omit the nine-slice margins (description at column 7)
    const m = c.slice(7, 11).map(v => Number(v));
    const margins = m.length === 4 && m.every(v => Number.isFinite(v) && String(v) !== '') ? m : [0, 0, 0, 0];
    const row = {
      group, index: Number(idx), tex: c[2].trim(), key: textureKey(c[2]),
      x: nums[0], y: nums[1], w: nums[2], h: nums[3], m: margins,
    };
    map.set(`${group.toLowerCase()}#${row.index}`, row);
  }
  return map;
}

/** [a,r,g,b] | 'AARRGGBB' | '0xAARRGGBB' -> [a,r,g,b] (null stays null). */
function argbArray(c) {
  if (c == null || Array.isArray(c)) return c;
  const h = String(c).trim().replace(/^0x|^#/i, '');
  if (!/^[0-9a-f]{1,8}$/i.test(h)) return null;
  const p = h.length <= 6 ? `ff${h.padStart(6, '0')}` : h.padStart(8, '0');
  return [0, 2, 4, 6].map(i => parseInt(p.slice(i, i + 2), 16));
}

const hasDOM = () => typeof document !== 'undefined' && typeof document.createElement === 'function';

function makeCanvas(w, h) {
  if (hasDOM()) {
    const cv = document.createElement('canvas');
    cv.width = w; cv.height = h;
    if (cv.getContext) return cv;
  }
  if (typeof OffscreenCanvas !== 'undefined') return new OffscreenCanvas(w, h);
  return null;
}
// Every atlas canvas is read back (PNG blob, tint pixels): a CPU-backed context keeps putImageData / drawImage / toBlob
// in memory instead of a GPU canvas whose read-back waited on the GPU (~1.1 s of GPU-finish stalls in the 2.2.0 loading
// screen, measured). The pixels are the same; the first getContext call fixes the backing.
const ctx2d = cv => cv.getContext('2d', { willReadFrequently: true });

async function canvasURL(cv) {
  try {
    if (typeof cv.convertToBlob === 'function') return URL.createObjectURL(await cv.convertToBlob({ type: 'image/png' }));
    if (typeof cv.toBlob === 'function') {
      const blob = await new Promise(res => cv.toBlob(res, 'image/png'));
      if (blob) return URL.createObjectURL(blob);
    }
    if (typeof cv.toDataURL === 'function') return cv.toDataURL('image/png');
  } catch { /* fall through */ }
  return null;
}

class RetryMap extends Map {
  constructor(owner, kind) { super(); this.owner = owner; this.kind = kind; this.failures = new Map(); }
  has(key) {
    const failed = this.failures.get(key);
    if (failed && failed.count < 3 && performance.now() >= failed.retryAt) { super.delete(key); this.failures.delete(key); this.previous ||= new Map(); this.previous.set(key, failed.count); }
    return super.has(key);
  }
  set(key, promise) {
    const generation = this.owner._generation;
    const count = this.previous?.get(key) || 0; this.previous?.delete(key);
    const pending = Promise.resolve(promise).then(value => {
      const url = typeof value === 'string' ? value : value?.url;
      if (generation !== this.owner._generation) { if (url?.startsWith('blob:')) URL.revokeObjectURL(url); return null; }
      if (value) { this.failures.delete(key); if (url?.startsWith('blob:')) this.owner._ownedURLs.add(url); }
      else this.failures.set(key, { count: this.kind === 'texture' ? 3 : count + 1, retryAt: performance.now() + 1100 * (count + 1) });
      return value;
    }, () => { if (generation === this.owner._generation) this.failures.set(key, { count: count + 1, retryAt: performance.now() + 1100 * (count + 1) }); return null; });
    return super.set(key, pending);
  }
  clear() { super.clear(); this.failures.clear(); this.previous?.clear(); }
}

export class UIAtlas {
  constructor({ waitRetry = null } = {}) {
    this._generation = 0; this._ownedURLs = new Set(); this._retryTimers = new Set(); this._waitOverride = waitRetry;
    this.table = null;
    this._loading = null;
    this._tex = new RetryMap(this, 'texture');     // data key -> Promise<{width,height,canvas}|null>
    this._spr = new RetryMap(this, 'sprite');     // 'group#index' -> Promise<Sprite|null>
    this._urls = new RetryMap(this, 'url');    // data key -> Promise<string|null> (whole texture as URL)
    this.ready = false;
  }

  _waitRetry(ms) {
    if (this._waitOverride) return this._waitOverride(ms);
    return new Promise(resolve => { const entry = { resolve, timer: null }; entry.timer = setTimeout(() => { this._retryTimers.delete(entry); resolve(); }, ms); this._retryTimers.add(entry); });
  }
  clear() {
    this._generation++;
    for (const entry of this._retryTimers) { clearTimeout(entry.timer); entry.resolve(); } this._retryTimers.clear();
    for (const url of this._ownedURLs) URL.revokeObjectURL(url); this._ownedURLs.clear();
    this._tex.clear(); this._spr.clear(); this._urls.clear(); this._done?.clear();
    this._loading = null; this.table = null; this.ready = false;
  }
  /**
   * Load imagetable.txt once (EUC-KR). Resolves this; never rejects.
   * script/ui/com/preloading.txt (the client's boot-time sprite table: InitScreen, preloading, credit, console,
   * common#1 = white.dds, Loading, ...) is merged underneath; imagetable.txt wins on duplicate (group,index).
   */
  load() {
    if (!this._loading) {
      const generation = this._generation;
      const pre = fetchText(PRELOADING, true).then(parseImageTable).catch(() => new Map());
      this._loading = Promise.all([fetchText(IMAGETABLE, true), pre])
        .then(([t, preMap]) => { if (generation !== this._generation) return this; const m = new Map(preMap); for (const [k, v] of this._extraRows || []) m.set(k, v); for (const [k, v] of parseImageTable(t)) m.set(k, v); this.table = m; this.ready = true; return this; })
        .catch(err => { console.warn('[ui] imagetable unavailable, using CSS look', err?.message || err); if (generation === this._generation) { this.table = new Map(); if (err?.transient) this._loading = null; } return this; });
    }
    return this._loading;
  }

  /**
   * Engine rows for screens the shipped imagetable.txt lacks (imagetable-format text, e.g. TRAINING-CAMP's ENGINE-CHOSEN
   * TrainingCamp rows in src/config/engine-chosen-training-camp.js). They sit under imagetable.txt: a shipped row with
   * the same (group,index) always wins. Kept across clear(); merged into an already loaded table at once.
   */
  addRows(text) {
    const rows = parseImageTable(text);
    this._extraRows ||= new Map();
    for (const [k, v] of rows) { this._extraRows.set(k, v); if (this.table && !this.table.has(k)) this.table.set(k, v); }
    return rows.size;
  }

  /** Sprite already decoded (sync; null while loading or missing). Filled by sprite(). */
  spriteNow(group, index, dx = 0) {
    const id = `${String(group).toLowerCase()}#${Number(index)}`;
    return this._done?.get(dx ? `${id}@${dx}` : id) || null;
  }

  /**
   * A sprite multiplied by an ARGB colour (window-script `<image> color AARRGGBB`: D3D vertex-colour modulate).
   * argb = [a, r, g, b] 0..255. White/opaque returns the plain sprite.
   */
  tinted(group, index, argb) {
    const generation = this._generation;
    argb = argbArray(argb);
    if (!argb || (argb[0] === 255 && argb[1] === 255 && argb[2] === 255 && argb[3] === 255)) return this.sprite(group, index);
    recordAtlasRequest('tinted', [String(group).toLowerCase(), Number(index), argb]);
    const id = `${String(group).toLowerCase()}#${Number(index)}~${argb.join('.')}`;
    if (!this._spr.has(id)) {
      this._spr.set(id, this.sprite(group, index).then(async s => {
        if (!s) return null;
        const cv = makeCanvas(s.canvas.width, s.canvas.height);
        const ctx = ctx2d(cv);
        ctx.drawImage(s.canvas, 0, 0);
        const d = ctx.getImageData(0, 0, cv.width, cv.height);
        const [a, r, g, b] = argb;
        for (let i = 0; i < d.data.length; i += 4) {
          d.data[i] = (d.data[i] * r) / 255; d.data[i + 1] = (d.data[i + 1] * g) / 255;
          d.data[i + 2] = (d.data[i + 2] * b) / 255; d.data[i + 3] = (d.data[i + 3] * a) / 255;
        }
        ctx.putImageData(d, 0, 0);
        const url = await canvasURL(cv);
        const out = url ? { ...s, url, canvas: cv } : null;
        if (out && generation === this._generation) (this._done ||= new Map()).set(id, out);
        return out;
      }).catch(() => null));
    }
    return this._spr.get(id);
  }

  /** Sync twin of tinted() (null until decoded). */
  tintedNow(group, index, argb) {
    argb = argbArray(argb);
    if (!argb || argb.every(v => v === 255)) return this.spriteNow(group, index);
    return this._done?.get(`${String(group).toLowerCase()}#${Number(index)}~${argb.join('.')}`) || null;
  }

  /** An arbitrary texture rectangle (legacy tool UI `control_image flags tex x y w h`). */
  region(tex, x, y, w, h) {
    const key = textureKey(tex);
    const id = `@${key}#${x},${y},${w},${h}`;
    if (!this._spr.has(id)) {
      this._spr.set(id, (async () => {
        const t = await this.texture(key);
        if (!t || w <= 0 || h <= 0) return null;
        const cx = Math.max(0, Math.min(x, t.width - 1)), cy = Math.max(0, Math.min(y, t.height - 1));
        const cw = Math.max(1, Math.min(w, t.width - cx)), ch = Math.max(1, Math.min(h, t.height - cy));
        const cv = makeCanvas(cw, ch);
        ctx2d(cv).drawImage(t.canvas, cx, cy, cw, ch, 0, 0, cw, ch);
        const url = await canvasURL(cv);
        return url ? { url, w, h, canvas: cv, row: { key, x, y, w, h, m: [0, 0, 0, 0] } } : null;
      })().catch(() => null));
    }
    return this._spr.get(id);
  }

  /** Synchronous lookup (after load()). */
  rect(group, index) {
    return this.table?.get(`${String(group).toLowerCase()}#${Number(index)}`) || null;
  }

  /** Decoded texture as a canvas, or null. */
  texture(key) {
    key = normPath(key);
    recordAtlasRequest('texture', [key]);
    if (!this._tex.has(key)) {
      const generation = this._generation;
      this._tex.set(key, (async () => {
        if (!makeCanvas(1, 1)) return null;
        for (let attempt = 1; attempt <= 3; attempt++) {
          if (generation !== this._generation) return null;
          try {
            const buf = await tryFetchBuffer(key);
            if (!buf || generation !== this._generation) return null; // explicit absence is not retried
            const img = await decodeImageAsync(buf);
            if (generation !== this._generation) return null;
            const cv = makeCanvas(img.width, img.height), ctx = ctx2d(cv);
            const pixels = ctx.createImageData(img.width, img.height); pixels.data.set(img.data.subarray(0, pixels.data.length)); ctx.putImageData(pixels, 0, 0);
            return { width: img.width, height: img.height, canvas: cv };
          } catch (error) {
            if (error?.missing || attempt === 3) { console.warn('[ui] cannot load/decode', key, error?.message || error); return null; }
            await this._waitRetry(1100 * attempt);
          }
        }
        return null;
      })());
    }
    return this._tex.get(key);
  }

  /** Whole texture as an object URL (for big backgrounds). */
  textureURL(key) {
    key = normPath(key);
    if (!this._urls.has(key)) this._urls.set(key, this.texture(key).then(t => (t ? canvasURL(t.canvas) : null)));
    return this._urls.get(key);
  }

  /**
   * One sprite cropped to its own canvas.
   * `dx` shifts the crop horizontally (skill_icon: the greyed icon is the 40-px column left of the
   * coloured one in S_<Class>.dds).
   * @returns {Promise<{url:string, w:number, h:number, canvas:any, row:object}|null>}
   */
  sprite(group, index, dx = 0) {
    const generation = this._generation;
    const id = `${String(group).toLowerCase()}#${Number(index)}`;
    const cacheId = dx ? `${id}@${dx}` : id;
    recordAtlasRequest('sprite', [String(group).toLowerCase(), Number(index), dx || 0]);
    if (!this._spr.has(cacheId)) {
      this._spr.set(cacheId, (async () => {
        await this.load();
        if (generation !== this._generation) return null;
        const base = this.table?.get(id);
        const row = base && dx ? { ...base, x: base.x + dx } : base;
        if (!row || row.w <= 0 || row.h <= 0 || row.x < 0) return null;
        const tex = await this.texture(row.key);
        if (!tex) return null;
        const x = Math.max(0, Math.min(row.x, tex.width - 1)), y = Math.max(0, Math.min(row.y, tex.height - 1));
        const w = Math.max(1, Math.min(row.w, tex.width - x)), h = Math.max(1, Math.min(row.h, tex.height - y));
        const cv = makeCanvas(w, h);
        if (!cv) return null;
        ctx2d(cv).drawImage(tex.canvas, x, y, w, h, 0, 0, w, h);
        const url = await canvasURL(cv);
        const out = url ? { url, w, h, canvas: cv, row } : null;
        if (out && generation === this._generation) (this._done ||= new Map()).set(cacheId, out);
        return out;
      })().catch(() => null));
    }
    return this._spr.get(cacheId);
  }

  /**
   * Paint a sprite onto an element as a stretched CSS background (resolves true when applied).
   * opts: { size: 'stretch'|'natural', sizeEl: bool (set width/height to the sprite size) }
   */
  async paint(el, group, index, opts = {}) {
    const s = await this.sprite(group, index, opts.dx || 0);
    if (!s || !el) return false;
    el.style.backgroundImage = `url("${s.url}")`;
    el.style.backgroundRepeat = 'no-repeat';
    el.style.backgroundSize = opts.size === 'natural' ? `${s.w}px ${s.h}px` : '100% 100%';
    if (opts.sizeEl) { el.style.width = `${s.w}px`; el.style.height = `${s.h}px`; }
    el.classList?.add('art');
    return true;
  }

  /**
   * Multi-state art button (imagetable states none/over/down/disable, ui.md §2). Keeps the CSS
   * fallback until the art is decoded. `states` = { none, over?, down?, disable? } sprite indices.
   */
  button(el, group, states) {
    if (!el) return;
    el._art = { group, states };   // may be called again to swap the state set (e.g. toggles)
    const show = async (pick) => {
      const a = el._art;
      const idx = pick(a.states);
      if (idx == null) return;
      const s = await this.sprite(a.group, idx);
      if (s && el._art === a) { el.style.backgroundImage = `url("${s.url}")`; el.style.backgroundSize = '100% 100%'; el.style.backgroundRepeat = 'no-repeat'; el.classList?.add('art'); }
    };
    const base = st => (el.disabled || el.classList?.contains('off') ? st.disable ?? st.none : st.none);
    show(base);
    if (el._artWired) return;
    el._artWired = true;
    el.addEventListener('mouseenter', () => { if (!el.disabled) show(st => st.over ?? base(st)); });
    el.addEventListener('mouseleave', () => show(base));
    el.addEventListener('mousedown', () => { if (!el.disabled) show(st => st.down ?? st.over ?? base(st)); });
    el.addEventListener('mouseup', () => show(st => st.over ?? base(st)));
    el._artRefresh = () => show(base);
  }

  /** Nine-slice a sprite onto an element with CSS border-image (margins in sprite pixels: [L,T,R,B]). */
  async frame(el, group, index, margins, widths = margins) {
    const s = await this.sprite(group, index);
    if (!s || !el) return false;
    const [l, t, r, b] = margins;
    const [wl, wt, wr, wb] = widths;
    el.style.borderStyle = 'solid';
    el.style.borderWidth = `${wt}px ${wr}px ${wb}px ${wl}px`;
    el.style.borderImage = `url("${s.url}") ${t} ${r} ${b} ${l} fill / ${wt}px ${wr}px ${wb}px ${wl}px stretch`;
    el.style.background = 'none';
    el.classList?.add('art');
    return true;
  }
}

/** Shared instance: every HUD/window uses the same decoded atlases. */
export const atlas = new UIAtlas();

/** Skill icon sprite id (imagetable group skill_icon, index = skill IconIndex; 40x40 cells in UI/Game/skill/S_<Class>.dds). */
export function skillIconSprite(skill) {
  const i = skill?.iconIndex ?? skill?.index;
  return i == null ? null : ['skill_icon', Number(i)];
}

/** Class emblem (ui.md §3: etc_01#100..114, 27x25, per class index). */
export function classIconSprite(classIndex) {
  const i = Number(classIndex);
  return Number.isFinite(i) && i >= 0 && i <= 14 ? ['etc_01', 100 + i] : ['etc_01', 34];
}
