// Damage numbers of the original: sprite digits from texture/ui/default/damage*.dds, animated by script/effect/damageeffect.csv:
//   Alpha 0->1 (0..10%), 1 (..30%), ->0 (100%);  Zpos -6 -> -3 -> -2 -> 0 -> 3 (towards the camera, world units);
//   Ypos 0 .. 0.5 (after 30%);  Scale 3;  Time 800 ms (CriticalTime 1000 ms, CriticalScale 1.5 - see CRIT_TIMING below).
// "Damage Effect Display Setting" (all / own only / none) filters them.
// LANE51 crit-row pass (Global client evidence, decompile read-only):
//   Font option = data/script/ui/game2/option/ui_optionwndwin64.txt check_damage_font_0..3 -> config "damage_font" byte.
//   Texture bind (32-bit FUN_01564380 / 64-bit CTextureNumberRenderer::vf02 FUN_7ff67169d880): byte 1 or 2 -> damage1.dds,
//   3 -> damage2.dds, else damage.dds. Only these three are loaded (32-bit FUN_01563e60 / 64-bit ctor FUN_7ff67169d360):
//   damage_0_new.dds is never loaded by Global (removed). UV layout per byte (dispatch 64-bit FUN_7ff67169e790):
//   1 -> layout 1 (FUN_015651b0 / FUN_7ff67169eaa0), 2 -> layout 2 (FUN_015652f0 / FUN_7ff67169ebb0),
//   0 and 3 -> layout 0 (FUN_01564e90 / FUN_7ff67169e7f0).  => A = damage.dds L0, B = damage1.dds L1, C = damage1.dds L2,
//   D = damage2.dds L0.
import * as THREE from 'three';
import { fetchCSV } from '../../engine/assets.js';
import { atlas } from '../../ui/atlas.js';

const FONTS = ['texture/ui/default/damage.dds', 'texture/ui/default/damage1.dds', 'texture/ui/default/damage1.dds', 'texture/ui/default/damage2.dds'];
export const FONT_LAYOUT = [0, 1, 2, 0];
const CELL_W = 33.5, CELL_H = 48, WORD_X = 350, WORD_W = 162;
// STEP12-LANE51 (not in Global = removed): only the word types Global's client draws (FUN_01564fe0: 1 block, 0 miss,
// 0xb blow, 0xc immune). Texture rows 2 (Guard) / 3 (Cancel) have NO native UV consumer in any decompile decompile, so
// they are never drawn; WORD_ROW_Y keeps their measured slots as texture geometry only.
const WORDS = { block: 0, miss: 1, blow: 4, immune: 5 };
// Row tops measured from the textures (alpha bands). The rows are NOT on a 48 px grid: using r*48 cut every row
// from the 5th down and showed a slice of the neighbouring row above/below the number.
const GLYPH_H = 42, GLYPH_PAD = 2, WORD_H = 40, WORD_PAD = 3;
const DIGIT_ROW_Y = [
  [0, 50, 98, 150, 204, 256, 308, 360],                  // A damage.dds
  [2, 51, 101, 152, 201, 255, 304, 353, 403, 454],       // B damage1.dds (10 rows)
  [2, 51, 101, 152, 201, 255, 304, 353, 403, 454],       // C damage1.dds (layout 2 uses rows 0 / 7 / 8 / 9)
  [2, 52, 100, 152, 204, 256, 308, 360],                 // D damage2.dds
];
const WORD_ROW_Y = [
  [2, 50, 96, 143, 194, 238],
  [6, 52, null, 144, 191, 239],                          // damage1.dds has no Guard word
  [6, 52, null, 144, 191, 239],
  [6, 53, 99, 145, 196, 239],
];
// Native overlays (32-bit FUN_015653e0, drawn at remaining-count 1 = after the last digit; V/U x 512):
//   layout 1: type 2 -> Guard icon U 0x3f488000..0x3f5a8000 V 0x3f2e8000..0x3f448000 (x401 y349 36x44);
//             types 7 / 8 / 0xe -> CRIT icon U = V = 0x3f2e8000..0x3f428000 (x349 y349 40x40).
//   layout 2: type 2 -> nothing; types 7 / 8 -> word U 0x3f2e8000..0x3f7c0000 V 0x3f468000..0x3f548000 (x349 y397 155x28,
//             "skull CRITICAL"); type 0xe -> V 0x3f5a8000..0x3f688000 (y437, "x CRITICAL").
//   Thousands separator (same function, every 3rd digit): U 0x3f268000..0x3f2c8000 = x333..345 on the digit row.
const CRIT_ICON_L1 = { x: 349, y: 349, w: 40, h: 40 };
const CRIT_WORD_L2 = { x: 349, w: 155, h: 28, y78: 397, yE: 437 };
const SEP = { x: 333, w: 12 };
// STEP10-LANE51 overlay geometry (32-bit FUN_015653e0, y-up, scale = entry[0xe]; DAT values read from the 32-bit image):
//   DAT_01b7e34c 77.5, DAT_01b7e2d4 14.0, DAT_01b7e17c 0.6, DAT_01b7e168 0.5, DAT_01b7e194 0.8, DAT_01b7e1ac 0.9,
//   DAT_01b7e2ac 6.0, DAT_01b7e2e4 18, DAT_01b7e2e8 20, DAT_01b7e2ec 22.
//   separator (idx > 3, (idx-1) % 3 == 0): 6*scale wide, digit height, pen += 0.8*6 = 4.8*scale.
//   layout 2 CRITICAL word (7 / 8 / 0xe): 77.5*0.6 = 46.5*scale x 14*0.6 = 8.4*scale, right edge = the digits' right edge,
//     bottom at anchor.y + 0.9*halfH (above the digits).  layout 1 crit icon: 16*scale square; Guard icon (type 2):
//     18*0.6 = 10.8*scale x 22*0.6 = 13.2*scale; both centred on the LAST digit cell, bottom at anchor.y + 0.9*halfH.
//   CSS px per scale unit = 2: calibrated on the separator (6*scale draws its 12-texel slot x333..345), same function.
const OV_PX = 2;
export const OVERLAY = Object.freeze({
  sepW: 6 * OV_PX, sepAdv: 4.8 * OV_PX, bottomK: 0.9,
  critWordL2: { w: 46.5 * OV_PX, h: 8.4 * OV_PX }, critIconL1: { w: 16 * OV_PX, h: 16 * OV_PX }, guardIconL1: { w: 10.8 * OV_PX, h: 13.2 * OV_PX },
});
// Guard = Global display type 2 (64-bit Guard model handler FUN_7ff670a0aba0 -> a09340 p7=2; renderer digit path).
//   Layout 0: V 0x3f188000 = y305 = row 6. Layout 1: amount bands < 100000 / < 1000000 / else -> rows 3 / 4 / 5 (+ Guard
//   icon). Layout 2: V 0x3f4a0000 = y404 = damage1.dds row 8 (Font C draws damage1.dds, so y404 is a real glyph row).
const GUARD_ROW_LAYOUT0 = 6;
const GUARD_B_BANDS = [[100000, 3], [1000000, 4], [Infinity, 5]];
const GUARD_B_ICON = { x: 401, y: 349, w: 36, h: 44 };
const GUARD_ROW_LAYOUT2 = 8;
export const guardRow = (layout, value) => layout === 1
  ? GUARD_B_BANDS.find(([lim]) => Math.max(0, Math.round(Number(value) || 0)) < lim)[1]
  : layout === 2 ? GUARD_ROW_LAYOUT2 : GUARD_ROW_LAYOUT0;
const digitY = (font, row) => Math.max(0, (DIGIT_ROW_Y[font]?.[row] ?? row * CELL_H) - GLYPH_PAD);
const wordY = (font, w) => Math.max(0, (WORD_ROW_Y[font]?.[w] ?? WORD_ROW_Y[font]?.[0] ?? w * CELL_H) - WORD_PAD);
/** Global render type -> sprite row (VERIFIED, 32-bit renderer UV functions):
 *  layout 0 FUN_01564e90: 3->0, 9/0xd->1, 8/0xe->2, 6->3, else->4, 7->5, 2->6, 10->7;
 *  layout 1 FUN_015651b0: {3,6,7,10} -> rows 0/1/2 and {2,8,9,0xd,0xe} -> rows 3/4/5 by amount < 100000 / < 1000000 / else;
 *  layout 2 FUN_015652f0: 8/9 -> V 0x3f638000 (y455 row 9), 2 -> y404 row 8, 0xd/0xe -> V 0x3f300000 (y352 row 7), else row 0. */
export function nativeRow(layout, type, value) {
  const n = Math.max(0, Math.round(Number(value) || 0));
  const band = n < 100000 ? 0 : n < 1000000 ? 1 : 2;
  if (layout === 1) return [3, 6, 7, 10].includes(type) ? band : [2, 8, 9, 0xd, 0xe].includes(type) ? 3 + band : 0;
  if (layout === 2) return type === 8 || type === 9 ? 9 : type === 2 ? 8 : type === 0xd || type === 0xe ? 7 : 0;
  return { 3: 0, 9: 1, 0xd: 1, 8: 2, 0xe: 2, 6: 3, 7: 5, 2: 6, 10: 7 }[type] ?? 4;
}
/** Global render type of a hit (VERIFIED chain, 64-bit):
 *  packet hit byte (+0x29) -> Defeat model msg +0xd -> handler FUN_7ff670a0aa70 -> Post_Message_IDelivery__Effect_Damage_a09340:
 *    message type = 4 when the hit byte == 1 (0xb when PvP), else 3 (10 when PvP) for a plain hit, 2 for Guard (FUN_7ff670a0aba0).
 *    kind = 0 when the target actor type (IActor vf+0x18) == 0, else 1 (2 for an info vf+0x38 class 3/6/7).
 *    Actor type 0 = Pc: Info::Pc vf01 returns 0 (Monster 1, Servant 2, Guard 3, Npc 4, Brick 5, Sentry 6, Pet 17, Totem 18),
 *    PC::Provider vf03 forwards to it; Actors::NPC vf03 returns 4 etc. (reconstructed 64-bit image vtables).
 *    PvP (bVar10) = attacker actor type 0 AND kind 0 = Pc hits Pc.
 *  remap FUN_7ff6712c4510 (message type, kind) -> render type: 3 -> kind 0 ? 9 : 3; 4 -> kind != 0 ? 7 : 8; 10 -> 0xd; 0xb -> 0xe;
 *    2 -> 2; 8 -> 0xb (Blow word); 9 -> 0xc (Immune word).
 *  CRITICAL = hit byte 1: the only render types that carry the CRITICAL glyphs (FUN_015653e0: layout 1 crit icon, layout 2
 *  "CRITICAL" words) are 7 / 8 / 0xe, and they come only from message 4 / 0xb (hit byte == 1). */
export function hitRenderType({ crit = false, guard = false, targetPc = false, attackerPc = false } = {}) {
  if (guard) return 2;
  const pvp = targetPc && attackerPc;
  if (crit) return pvp ? 0xe : targetPc ? 8 : 7;
  return pvp ? 0xd : targetPc ? 9 : 3;
}
/** CriticalTime / CriticalScale (damageeffect.csv) apply only to MESSAGE types 7 / 8 (64-bit FUN_7ff6712c41c0:
 *  `*(int*)(msg+0xc) - 7U < 2` selects the second timing entry). Message 8 = Defeat subtype 0xf flag (Defeat_9f3960 sets
 *  msg+0x15) = render 0xb = the Blow word; message 7 = the packet +0x2a byte = render 10 (row 7 grey on layout 0).
 *  +0x2a (older server reference, DekaronServer.exe 0x5946a5): low byte of the first word packed by 0x593780 = min(0xffff,
 *  f*128) with f = Computer vf+0x64 (0x586dc0), a push / knockback magnitude - not a Blow flag. The host has no push
 *  magnitude source, so render 10 is never produced (removed from the host; old clients unaffected). A hit-byte critical (message 4 / 0xb) uses the normal Time. */
export const CRIT_TIMING = { words: ['blow'], renderTypes: [10] };
/** kind -> row per layout [L0 (A, D), L1 (B), L2 (C)] for legacy callers that pass no render type.
 *  out / crit / in / incrit / other = nativeRow() of their usual render type at the smallest amount band:
 *  out = own hit on a non-Pc (type 3), crit = critical on a non-Pc (type 7), in = non-Pc hits me (type 9),
 *  incrit = non-Pc critical on me (type 8), other = third-party hit on a non-Pc (type 3; a09340 has no own/other type).
 *  STEP10-LANE51 (64-bit dekaron64, proven): the Effect::Damage message (vtable DAT_7ff671e060c8) has exactly three
 *  builders - a09340 (types 0/1/2/3/9 from the hit / Guard / Defeat / Immune handlers), Post_Message_IDelivery__Effect_Damage
 *  _9cf0b0 (Brick slide: types 1/3/4/6) and FUN_7ff6709fddb0 (type 0). No builder writes message type 5 (render 4) or any
 *  heal / MP type: Global draws NO heal or MP number -> heal / mp removed. A DoT tick reaches the client only through the
 *  hit paths -> it uses the plain hit render type (hitRenderType, crit false). Render 6 = the Brick slide variant.
 *  Pinned by tools/test-damage-number-rows.mjs. */
export const ROWS = {
  out: [0, 0, 0], crit: [5, 0, 0], in: [1, 3, 9], incrit: [2, 3, 9], other: [0, 0, 0],
};
export const KIND_TYPE = { out: 3, crit: 7, in: 9, incrit: 8, other: 3 };
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


/** Map a combat damage/heal event to a DamageNumbers.show() spec.
 * Global result types (combat.js comments / 0x9fef0c): 0 miss, 1 block, 2 guard.
 * Sprite words = Global's word display types only (FUN_01564550 word path; FUN_01564fe0 UVs): block|miss|blow|immune.
 * Guard is not a word type but its own digit type 2 (Guard handler FUN_7ff670a0aba0 -> a09340): kind 'guard' draws the
 * reduced damage on the type-2 row (guardRow) and, on Font B, the Guard icon overlay. Cancel: no Global message class,
 * no display type, no UV -> not drawn. Absorb / Evade: no glyph or string in Global, nothing drawn.
 * Returns null when the event should show nothing (caller still applies viewAllowed). */
export function combatResultFloater(e, { toMe = false, ownHit = false } = {}) {
  const targetPc = e?.target?.kind === 'player', attackerPc = e?.source?.kind === 'player';
  if (!e) return null;
  // Immune first: the host marks an Immune hit miss + immune (older server reference: the hit ends like a miss) so old
  // clients keep drawing Miss; this client draws Global's Immune word (render 0xc).
  if (e.immune) return { word: 'immune' };
  if (e.miss) return { word: 'miss' };
  if (e.block) return { word: 'block', kind: toMe ? 'in' : 'out' };
  if (e.blow) return { word: 'blow' };
  // e.guard: Global display type 2 (digits + Font B Guard icon). e.cancel: not in Global -> ignored (plain digits/none).
  if (e.guard) {
    if (e.amount == null) return null;
    return { value: e.amount, kind: 'guard', crit: false, type: hitRenderType({ guard: true }) };
  }
  // Absorb: no Absorb glyph in damage.dds family (Global word UVs = block/miss/blow/immune only).
  // shieldDamage is carried on the event for combat math; presentation shows remaining HP damage digits only.
  // Heal / MP recovery: no Global Effect::Damage builder carries a heal or MP type (STEP10-LANE51) -> nothing drawn.
  if (e.heal || e.kind === 'heal') return null;
  const amount = e.amount;
  if (amount == null && !e.crit) return null;
  const kind = toMe ? (e.crit ? 'incrit' : 'in')
    : ownHit ? (e.crit ? 'crit' : 'out')
    : 'other';
  // DoT ticks: plain hit render type (no Global DoT type; the tick has no hit byte -> never critical).
  const crit = !e.dot && !!e.crit;
  return { value: amount, kind: e.dot ? (toMe ? 'in' : ownHit ? 'out' : 'other') : kind, crit, type: hitRenderType({ crit, targetPc, attackerPc }) };
}

/** FUN_015653e0 overlay quads of a number: texture slot + native size (OVERLAY) + alignment. Pinned by the rows test. */
export function overlayGlyphs(layout, kind, type) {
  const out = [];
  const critType = type === 7 || type === 8 || type === 0xe;
  if (layout === 1 && kind === 'guard') out.push({ x: GUARD_B_ICON.x, y: GUARD_B_ICON.y, w: OVERLAY.guardIconL1.w, h: OVERLAY.guardIconL1.h, align: 'last' });
  else if (layout === 1 && critType) out.push({ x: CRIT_ICON_L1.x, y: CRIT_ICON_L1.y, w: OVERLAY.critIconL1.w, h: OVERLAY.critIconL1.h, align: 'last' });
  if (layout === 2 && critType) out.push({ x: CRIT_WORD_L2.x, y: type === 0xe ? CRIT_WORD_L2.yE : CRIT_WORD_L2.y78, w: OVERLAY.critWordL2.w, h: OVERLAY.critWordL2.h, align: 'right' });
  return out;
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

  /** Show a number (or word) over an actor. kind: out|crit|in|incrit|other|guard; word: block|miss|blow|immune (Global word types only) */
  show(actor, { value = null, kind = 'out', word = null, crit = false, type = null } = {}) {
    if (!actor || !this.fontUrls.length) return;
    const font = this._font();
    const url = this.fontUrls[font];
    if (!url) return;
    const layout = FONT_LAYOUT[font] ?? 0;
    const row = kind === 'guard' ? guardRow(layout, value) : type != null ? nativeRow(layout, type, value) : (ROWS[kind] || ROWS.out)[layout];
    // Critical timing = Global message types 7 / 8 only (CRIT_TIMING); legacy callers without a render type keep their crit flag.
    const critTiming = word ? CRIT_TIMING.words.includes(word) : type != null ? CRIT_TIMING.renderTypes.includes(type) : !!crit;
    // Preserve every accepted impact through its authored lifetime, including large AoE bursts.
    // Capture the anchor now: a killing hit may outlive the actor's render model.
    const anchor = new THREE.Vector3();
    this._anchor(actor, anchor);
    this.items.push({ el: null, spec: { font, layout, row, kind, word, value, type }, actor, anchor, t: 0, life: (critTiming ? this.anim.critTime : this.anim.time) / 1000, scale: critTiming ? this.anim.critScale : 1, width: 0, jitter: (Math.random() - 0.5) * 0.6 });
  }

  _anchor(actor, out) {
    let head = null;
    try { head = actor.headWorldPosition?.(tmp); } catch { /* model may already be released */ }
    if (head) out.copy(head);
    else out.set(actor.x || 0, (actor.y || 0) + (actor.height || 2), -(actor.z || 0));
  }

  /** Build the element of a number (the former body of show()). */
  _build(f) {
    const { font, layout, row, kind, word, value, type } = f.spec;
    const cls = this._glyphClass(font);
    const url = this._blobUrls[font] || this.fontUrls[font];
    const el = document.createElement('div');
    el.style.cssText = 'position:absolute;left:0;top:0;will-change:transform,opacity;white-space:nowrap';
    const glyphs = [], overlays = [];
    if (word) {
      let w = WORDS[word] ?? 1;
        glyphs.push({ x: WORD_X, y: wordY(font, w), w: WORD_W, h: WORD_H, top: (CELL_H - WORD_H) / 2, adv: WORD_W * 0.8 });
    }
    if (value != null) {
      const s = String(Math.max(0, Math.round(Number(value) || 0)));
      const digits = layout !== 0 ? s.replace(/\B(?=(\d{3})+(?!\d))/g, ',') : s;   // FUN_015653e0 separator (layouts 1 / 2)
      for (const ch of digits) {
        const d = ch === ',' ? 10 : Number(ch);
        glyphs.push({ x: ch === ',' ? SEP.x : Math.round(d * CELL_W), y: digitY(font, row), w: ch === ',' ? OVERLAY.sepW : 34, h: GLYPH_H, top: (CELL_H - GLYPH_H) / 2, adv: ch === ',' ? OVERLAY.sepAdv : CELL_W * ADVANCE, digit: ch !== ',' });
      }
      overlays.push(...overlayGlyphs(layout, kind, type));
    }
    let x = 0, right = 0, lastLeft = 0, lastW = 0;
    const put = (g, left, top) => {
      const c = document.createElement('div');
      const geo = `position:absolute;top:${top}px;left:${left}px;width:${g.w}px;height:${g.h}px;`;
      if (cls) { c.className = cls; c.style.cssText = `${geo}background-position:-${g.x}px -${g.y}px`; }
      else c.style.cssText = `${geo}background:url(${url}) -${g.x}px -${g.y}px / 512px 512px no-repeat`;   // no stylesheet available: the old inline form
      el.appendChild(c);
    };
    for (const g of glyphs) {
      put(g, x, g.top || 0);
      right = Math.max(right, x + g.w);
      if (g.digit) { lastLeft = x; lastW = g.w; }
      x += g.adv;
    }
    // FUN_015653e0 overlays (last digit only): bottom edge at anchor.y + 0.9 * halfH in y-up = CSS top of the overlay is
    // digitCentre - 0.9 * halfH - h; the word is right-aligned on the digits, icons are centred on the last digit cell.
    const centre = (CELL_H - GLYPH_H) / 2 + GLYPH_H / 2, half = GLYPH_H / 2;
    for (const g of overlays) put(g, g.align === 'right' ? right - g.w : lastLeft + (lastW - g.w) / 2, centre - OVERLAY.bottomK * half - g.h);
    f.width = right;
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
