// Damage numbers of the original: sprite digits from texture/ui/default/damage*.dds (the View tab's "Damage Font
// Type" A-D = damage.dds, damage1.dds, damage2.dds, damage_0_new.dds; 34 x 48 cells, words Block / Miss / Guard /
// Cancel / Blow / Immune at x 350), animated by script/effect/damageeffect.csv:
//   Alpha 0->1 (0..10%), 1 (..30%), ->0 (100%);  Zpos -6 -> -3 -> -2 -> 0 -> 3 (towards the camera, world units);
//   Ypos 0 .. 0.5 (after 30%);  Scale 3;  Time 800 ms (critical 1000 ms, x1.5).
// "Damage Effect Display Setting" (all / own only / none) filters them. Row colours per font are an inference
// (documented in docs/HUD_OPTIONS.md): outgoing, critical, incoming, heal, MP, damage over time.
import * as THREE from 'three';
import { fetchCSV } from '../../engine/assets.js';
import { atlas } from '../../ui/atlas.js';

const FONTS = ['texture/ui/default/damage.dds', 'texture/ui/default/damage1.dds', 'texture/ui/default/damage2.dds', 'texture/ui/default/damage_0_new.dds'];
const CELL_W = 33.5, CELL_H = 48, WORD_X = 350, WORD_W = 162;
const WORDS = { block: 0, miss: 1, guard: 2, cancel: 3, blow: 4, immune: 5 };
// Row tops measured from the textures (alpha bands). The rows are NOT on a 48 px grid: using r*48 cut every row
// from the 5th down and showed a slice of the neighbouring row above/below the number.
const GLYPH_H = 42, GLYPH_PAD = 2, WORD_H = 40, WORD_PAD = 3;
const DIGIT_ROW_Y = [
  [0, 50, 98, 150, 204, 256, 308, 360],                  // A damage.dds
  [2, 51, 101, 152, 201, 255, 304, 353, 403, 454],       // B damage1.dds (10 rows)
  [2, 52, 100, 152, 204, 256, 308, 360],                 // C damage2.dds
  [2, 52, 100, 152, 204, 256, 308, 360],                 // D damage_0_new.dds
];
const WORD_ROW_Y = [
  [2, 50, 96, 143, 194, 238],
  [6, 52, null, 144, 191, 239],                          // B has no Guard word
  [6, 53, 99, 145, 196, 239],
  [6, 53, 99, 145, 196, 239],
];
const B_CRIT_WORD_Y = { crit: 439, incrit: 398 };
const digitY = (font, row) => Math.max(0, (DIGIT_ROW_Y[font]?.[row] ?? row * CELL_H) - GLYPH_PAD);
const wordY = (font, w) => Math.max(0, (WORD_ROW_Y[font]?.[w] ?? WORD_ROW_Y[font]?.[0] ?? w * CELL_H) - WORD_PAD);
/** kind -> row per font layout: [8-row fonts (A, C, D), 10-row font (B)]. INFERENCE: no data file maps an event to a row
 *  (script/effect/damageeffect.csv is animation only; the Options window only names the fonts "Type A..D"; the choice is
 *  compiled into the client exe). Row colours MEASURED from the sprite sheets:
 *  A/C/D rows 0 orange, 1 white, 2 blue, 3 tan, 4 magenta, 5 cyan-green, 6 yellow, 7 grey;
 *  B rows 0 white, 1 pale yellow, 2 orange, 3 light grey, 4 grey, 5 dark grey, 6 white, 7 gold, 8 green, 9 grey.
 *  CRIT = YELLOW, the only file evidence (sheets exported from the client's art): font B is the only sheet with critical artwork - an orange "x CRITICAL"
 *  word (crossed swords, y 439, rgb 254,89,0 = dealt) and a magenta "skull CRITICAL" (y 398, rgb 227,62,214 = received),
 *  and its critical burst icon is drawn beside the GOLD digit row 7. No file ties light blue to criticals (the blue row is
 *  used for MP). Pinned by tools/test-damage-number-rows.mjs. */
export const ROWS = {
  out: [0, 2], crit: [6, 7], in: [4, 0], incrit: [4, 6], heal: [5, 8], mp: [2, 1], dot: [3, 3], other: [1, 6],
};
const DEFAULT_ANIM = {
  alpha: [[0, 0], [100, 1], [200, 1], [300, 1], [999, 0]],
  scale: [[0, 3], [999, 3]], y: [[0, 0], [300, 0], [999, 0.5]], z: [[0, -6], [100, -3], [200, -2], [300, 0], [999, 3]],
  time: 800, critTime: 1000, critScale: 1.5,
};
const GLYPH_WORLD = 0.13;      // world height of a glyph per Scale unit (Scale 3 -> 0.39 units)
const ADVANCE = 0.74;          // glyph advance / cell width (the digits overlap slightly, as drawn by the client)

const tmp = new THREE.Vector3(), toCam = new THREE.Vector3(), up = new THREE.Vector3();

function sampleKeys(keys, t) {
  if (!keys?.length) return 0;
  if (t <= keys[0][0]) return keys[0][1];
  for (let i = 1; i < keys.length; i++) {
    const [t1, v1] = keys[i], [t0, v0] = keys[i - 1];
    if (t <= t1) return v0 + (v1 - v0) * ((t - t0) / Math.max(1e-6, t1 - t0));
  }
  return keys[keys.length - 1][1];
}

export class DamageNumbers {
  constructor(game, ctx) {
    this.game = game;
    this.ctx = ctx;
    this.items = [];
    this.anim = DEFAULT_ANIM;
    // fontUrls[i] = the sprite sheet of font i as a data: URL (kept: it is the fallback and what the tests / tools read).
    // The digits never carry a URL of their own: they get ONE shared CSS class per font (dkdn-b<i> = Blob URL once it is
    // decoded, dkdn-d<i> = the data: URL until then / when no Blob can be made), so a number costs ~0.1 ms instead of pasting
    // the 232 KB data: URL into the inline style of every digit (7-8 ms per number, a 1-1.5 s freeze for an area cast).
    this.fontUrls = [];
    this._blobUrls = [];       // font -> object URL (set only after the image is decoded)
    this._holds = [];          // font -> Image element that keeps the decoded sheet alive
    this._classes = new Map(); // 'b0' | 'd0' ... -> class name whose rule exists in this._sheet
    this._sheet = undefined;   // undefined = not made yet, null = no stylesheet available (inline fallback)
    this._styleEl = null;
    this._disposed = false;
    this.layer = document.createElement('div');
    this.layer.style.cssText = 'position:fixed;left:0;top:0;width:100%;height:100%;pointer-events:none;z-index:30;overflow:hidden';
    (game.ui || document.body).appendChild(this.layer);
    this._loadAnim();
    this._loadFonts();
  }
  async _loadAnim() {
    try {
      const rows = await fetchCSV('script/effect/damageeffect.csv');
      const a = { ...DEFAULT_ANIM };
      const keys = (r) => { const out = []; for (let i = 1; i + 1 < r.length; i += 2) { const t = Number(r[i]), v = Number(r[i + 1]); if (r[i] !== '' && Number.isFinite(t) && Number.isFinite(v)) out.push([t, v]); } return out; };
      for (const r of rows) {
        const k = String(r[0] || '').trim().toLowerCase();
        if (k === 'alpha') a.alpha = keys(r); else if (k === 'scale') a.scale = keys(r);
        else if (k === 'ypos') a.y = keys(r); else if (k === 'zpos') a.z = keys(r);
        else if (k === 'time') a.time = Number(r[1]) || a.time; else if (k === 'criticaltime') a.critTime = Number(r[1]) || a.critTime;
        else if (k === 'criticalscale') a.critScale = Number(r[1]) || a.critScale;
      }
      this.anim = a;
    } catch { /* defaults */ }
  }
  async _loadFonts() {
    for (let i = 0; i < FONTS.length; i++) {
      try {
        const tex = await atlas.texture(FONTS[i]);
        if (tex?.canvas) { this.fontUrls[i] = tex.canvas.toDataURL(); this._makeBlobUrl(i, tex.canvas); }
      } catch { /* missing font: fall back to type A */ }
    }
  }
  /** The same PNG bytes as one Blob (object) URL, like ui/atlas.js canvasURL. Never throws: on any failure / missing API the
   *  data: URL of that font stays in use. The URL is published only after the image decoded, so the first number drawn
   *  from it does not wait for a load. */
  async _makeBlobUrl(i, cv) {
    let url = null;
    try {
      if (typeof URL === 'undefined' || typeof URL.createObjectURL !== 'function') return;
      let blob = null;
      if (typeof cv.convertToBlob === 'function') blob = await cv.convertToBlob({ type: 'image/png' });
      else if (typeof cv.toBlob === 'function') blob = await new Promise(res => cv.toBlob(res, 'image/png'));
      if (!blob || this._disposed) return;
      url = URL.createObjectURL(blob);
      if (typeof Image === 'function') {
        const img = new Image();
        img.src = url;
        if (typeof img.decode === 'function') await img.decode();
        else await new Promise((res, rej) => { img.onload = res; img.onerror = rej; });
        this._holds[i] = img;
      }
      if (this._disposed) return;
      this._blobUrls[i] = url;
      url = null;
    } catch { /* keep the data: URL */ }
    finally { if (url) { try { URL.revokeObjectURL(url); } catch { /* ignore */ } } }
  }
  _font() { const f = Number(this.ctx.options.get('damageFont')) || 0; return this.fontUrls[f] ? f : 0; }
  /** Class of font f's sprite sheet (rule created once), or null when no stylesheet can be made (digits then carry the URL inline). */
  _glyphClass(f) {
    try {
      if (this._sheet === undefined) {
        this._sheet = null;
        const st = document.createElement('style');
        (document.head || document.documentElement).appendChild(st);
        this._styleEl = st;
        this._sheet = st.sheet || null;
      }
      if (!this._sheet) return null;
      const blob = this._blobUrls[f], key = (blob ? 'b' : 'd') + f;
      let name = this._classes.get(key);
      if (!name) {
        name = 'dkdn-' + key;
        this._sheet.insertRule(`.${name}{background:url("${blob || this.fontUrls[f]}") 0 0 / 512px 512px no-repeat}`, this._sheet.cssRules.length);
        this._classes.set(key, name);
      }
      return name;
    } catch { return null; }
  }

  /** Show a number (or word) over an actor. kind: out|crit|in|incrit|heal|mp|dot|other; word: block|miss|guard|... */
  show(actor, { value = null, kind = 'out', word = null, crit = false } = {}) {
    if (!actor || !this.fontUrls.length) return;
    const font = this._font();
    const url = this.fontUrls[font];
    if (!url) return;
    const layout = font === 1 ? 1 : 0;
    const row = (ROWS[kind] || ROWS.out)[layout];
    // Preserve every accepted impact through its authored lifetime, including large AoE bursts.
    // Capture the anchor now: a killing hit may outlive the actor's render model.
    const anchor = new THREE.Vector3();
    this._anchor(actor, anchor);
    this.items.push({ el: null, spec: { font, layout, row, kind, word, value }, actor, anchor, t: 0, life: (crit ? this.anim.critTime : this.anim.time) / 1000, scale: crit ? this.anim.critScale : 1, width: 0, jitter: (Math.random() - 0.5) * 0.6 });
  }

  _anchor(actor, out) {
    let head = null;
    try { head = actor.headWorldPosition?.(tmp); } catch { /* model may already be released */ }
    if (head) out.copy(head);
    else out.set(actor.x || 0, (actor.y || 0) + (actor.height || 2), -(actor.z || 0));
  }

  /** Build the element of a number (the former body of show()). */
  _build(f) {
    const { font, layout, row, kind, word, value } = f.spec;
    const cls = this._glyphClass(font);
    const url = this._blobUrls[font] || this.fontUrls[font];
    const el = document.createElement('div');
    el.style.cssText = 'position:absolute;left:0;top:0;will-change:transform,opacity;white-space:nowrap';
    const glyphs = [];
    if (word) {
      let w = WORDS[word] ?? 1;
      if (layout === 1 && w === 2) w = 0;   // type B has no Guard word
      glyphs.push({ x: WORD_X, y: wordY(font, w), w: WORD_W, h: WORD_H, top: (CELL_H - WORD_H) / 2, adv: WORD_W * 0.8 });
    }
    if (value != null) {
      const s = String(Math.max(0, Math.round(Number(value) || 0)));
      const digits = layout === 1 ? s.replace(/\B(?=(\d{3})+(?!\d))/g, ',') : s;
      for (const ch of digits) {
        const d = ch === ',' ? 10 : Number(ch);
        glyphs.push({ x: Math.round(d * CELL_W), y: digitY(font, row), w: ch === ',' ? 14 : 34, h: GLYPH_H, top: (CELL_H - GLYPH_H) / 2, adv: ch === ',' ? 10 : CELL_W * ADVANCE });
      }
      if (layout === 1 && (kind === 'crit' || kind === 'incrit')) glyphs.push({ x: WORD_X, y: B_CRIT_WORD_Y[kind] - WORD_PAD, w: WORD_W, h: WORD_H, top: (CELL_H - WORD_H) / 2, adv: WORD_W });
    }
    let x = 0;
    for (const g of glyphs) {
      const c = document.createElement('div');
      const geo = `position:absolute;top:${g.top || 0}px;left:${x}px;width:${g.w}px;height:${g.h}px;`;
      if (cls) { c.className = cls; c.style.cssText = `${geo}background-position:-${g.x}px -${g.y}px`; }
      else c.style.cssText = `${geo}background:url(${url}) -${g.x}px -${g.y}px / 512px 512px no-repeat`;   // no stylesheet available: the old inline form
      el.appendChild(c);
      x += g.adv;
    }
    f.width = x + (glyphs.length ? glyphs[glyphs.length - 1].w - glyphs[glyphs.length - 1].adv : 0);
    f.el = el;
    f.spec = null;
    this.layer.appendChild(el);
  }

  update(dt) {
    const g = this.game, cam = g.camera;
    if (!cam || !this.items.length) return;
    for (const f of this.items) if (!f.el) this._build(f);   // creation order = DOM order (later numbers paint over earlier ones)
    const W = innerWidth, H = innerHeight;
    const fovK = H / (2 * Math.tan((cam.fov * Math.PI) / 360));
    for (let i = this.items.length - 1; i >= 0; i--) {
      const f = this.items[i];
      f.t += dt;
      if (f.t >= f.life) { f.el?.remove(); continue; }
      const k = (f.t / f.life) * 999;
      const a = sampleKeys(this.anim.alpha, k), sc = sampleKeys(this.anim.scale, k) * f.scale;
      const yOff = sampleKeys(this.anim.y, k), zOff = sampleKeys(this.anim.z, k);
      if (f.actor && !f.actor.disposed) this._anchor(f.actor, f.anchor);
      else f.actor = null; // release the disposed model; keep the final impact position
      const head = tmp.copy(f.anchor);
      toCam.copy(cam.position).sub(head).normalize();
      up.set(0, 1, 0);
      head.addScaledVector(toCam, zOff).addScaledVector(up, yOff + 0.3);
      head.x += f.jitter * 0.4;
      const dist = head.distanceTo(cam.position);
      const p = head.clone().project(cam);
      if (p.z > 1 || p.z < -1 || dist < 0.3) { f.el.style.opacity = '0'; continue; }
      const px = (p.x + 1) * 0.5 * W, py = (1 - p.y) * 0.5 * H;
      const pxPerUnit = fovK / dist;
      const hgt = GLYPH_WORLD * sc * pxPerUnit;          // glyph height in CSS px
      const s = hgt / CELL_H;
      f.el.style.opacity = String(Math.max(0, Math.min(1, a)).toFixed(3));
      f.el.style.transform = `translate(${(px - (f.width * s) / 2).toFixed(1)}px, ${(py - hgt / 2).toFixed(1)}px) scale(${s.toFixed(4)})`;
      f.el.style.transformOrigin = '0 0';
    }
    let live = 0;
    for (const f of this.items) if (f.t < f.life) this.items[live++] = f;
    this.items.length = live;
  }
  _kill(f) { const i = this.items.indexOf(f); if (i >= 0) this.items.splice(i, 1); f.el?.remove(); }
  dispose() {
    this._disposed = true;
    this.items.length = 0;
    this.layer.remove();
    try { this._styleEl?.remove(); } catch { /* ignore */ }
    this._styleEl = null; this._sheet = null; this._classes.clear(); this._holds.length = 0;
    for (const u of this._blobUrls) if (u) { try { URL.revokeObjectURL(u); } catch { /* ignore */ } }
    this._blobUrls.length = 0;
  }
}
