// Placement rules of the original window scripts (pure; docs/UIWIN.md "Layout rules").
//
// Window `rect x1 y1 x2 y2` is relative to the anchor point given by `position <h> <v>`:
//   h: left -> 0, center -> floor(screenW/2), right -> screenW, inverse -> stretch (x1 from the left, x2 from the right)
//   v: top  -> 0, center -> floor(screenH/2), bottom -> screenH, inverse -> stretch
// Without `position`: `center_h dx center_v dy` centres the window (+ offsets); otherwise x1,y1 are absolute
// reference (1024x768) coordinates. `align_left/right/top/bottom` pin an edge to the screen with a margin.
// The window size is x2-x1 by y2-y1; when that is empty or the script used the "x y w h" form (a few files do,
// detected because the children's extent matches x2,y2 exactly) the children's extent is used.
//
// Control `rect x y w h` is relative to its parent; a control `position <h> <v>` anchors it to the parent's
// edges the same way (inverse = stretch: x from the left, width = parentW - x + w).

import { gfxC } from '../gfx-parity-c.js';

export const REF_W = 1024;

// gfxC3 'hudpos': HUD window positions from Global 43.19's own layout file bin/optionEtc.txt
// (Global client\bin\optionEtc.txt, sha256 B8FD5182...CC1FA87F):
//   hp_state_pos 580 -80          -> the HP window (script game2/mainbar/ui_hpwnd.txt, 'left bottom' rect 572 -89)
//   skill_quickslot_pos 0 -157    -> the skill quickslot (game2/mainbar/ui_quickslotwnd.txt, 'left bottom' rect 0 -153)
// x from the left edge, negative y from the bottom edge (both windows are 'position left bottom').
// Verified against the recording global-gfx-session2.mkv (t=26-30 s): Lv box at x 583 (580 + lbl_pclevel x 3), HP frame
// top at y 698 (768 - 80 + pan_bg y 10), the single skill row at y 707 (768 - 157 + row y 96).
// item_belt_pos (678 -153) is NOT applied: the recording shows the belt at x 508 / y 561, i.e. moved by hand that session.
export const GLOBAL_OPTIONETC_POS = Object.freeze([
  [/(^|\/)mainbar\/ui_hpwnd\.txt$/i, 580, -80],
  [/(^|\/)mainbar\/ui_quickslotwnd\.txt$/i, 0, -157],
  // gfxC4 [chatgeom]: chatwnd_pos 0 -519 -> chat button row top at y 249 (recording: buttons 249-275)
  [/(^|\/)chat\/ui_chatwnd\.txt$/i, 0, -519, 'chatgeom'],
]);
export function globalOptionEtcPos(spec, screen) {
  if (!spec?.file) return null;
  const hit = GLOBAL_OPTIONETC_POS.find(([re]) => re.test(spec.file));
  if (!hit || !gfxC(hit[3] || 'hudpos')) return null;
  const [, x, y] = hit;
  return { x: x < 0 ? screen.w + x : x, y: y < 0 ? screen.h + y : y };
}
export const REF_H = 768;

/** Extent of a control list (max right / bottom of their un-anchored rects). */
export function childrenExtent(children = []) {
  let w = 0, h = 0;
  for (const c of children) {
    if (!c || c.kind === 'window' || c.anchor) continue;
    const r = c.rect || [0, 0, 0, 0];
    if (c.visible === false && c.type === 'pivot') continue;
    w = Math.max(w, r[0] + r[2]);
    h = Math.max(h, r[1] + r[3]);
  }
  return { w, h };
}

function axis(anchor, a1, a2, size, screen) {
  switch (anchor) {
    case 'center': return { p: Math.floor(screen / 2) + a1, s: size };
    case 'right': case 'bottom': return { p: screen + a1, s: size };
    case 'inverse': return { p: a1, s: Math.max(0, screen - a1 + a2) };
    default: return { p: a1, s: size };
  }
}

/**
 * Screen box of a window spec. screen = {w, h} in reference pixels (viewport / interface scale).
 * @returns {{x, y, w, h, stretchW: boolean, stretchH: boolean}}
 */
export function computeWindowBox(spec, screen = { w: REF_W, h: REF_H }) {
  const [x1, y1, x2, y2] = spec.rect || [0, 0, 0, 0];
  let w = x2 - x1, h = y2 - y1;
  const ext = childrenExtent(spec.children);
  if (w <= 0 && !(spec.anchor && spec.anchor[0] === 'inverse')) w = ext.w;
  if (h <= 0 && !(spec.anchor && spec.anchor[1] === 'inverse')) h = ext.h;
  // "x y w h" variant: the content fits x2,y2 exactly but not x2-x1,y2-y1
  if (spec.rect && ext.w > 0 && ext.h > 0 && Math.abs(ext.w - x2) <= 2 && Math.abs(ext.h - y2) <= 2 && (Math.abs(ext.w - w) > 2 || Math.abs(ext.h - h) > 2)) { w = x2; h = y2; }
  let x, y, stretchW = false, stretchH = false;
  if (spec.anchor) {
    const ax = axis(spec.anchor[0], x1, x2, w, screen.w);
    const ay = axis(spec.anchor[1], y1, y2, h, screen.h);
    x = ax.p; w = ax.s; y = ay.p; h = ay.s;
    stretchW = spec.anchor[0] === 'inverse'; stretchH = spec.anchor[1] === 'inverse';
  } else if (spec.center) {
    x = Math.round((screen.w - w) / 2) + spec.center[0];
    y = Math.round((screen.h - h) / 2) + spec.center[1];
  } else {
    x = x1; y = y1;
  }
  const gp = globalOptionEtcPos(spec, screen);
  if (gp) { x = gp.x; y = gp.y; }
  const e = spec.edges;
  if (e) {
    if (e.left != null) x = e.left;
    if (e.right != null) x = screen.w - w + e.right;
    if (e.top != null) y = e.top;
    if (e.bottom != null) y = screen.h - h + e.bottom;
  }
  return { x, y, w: Math.max(0, w), h: Math.max(0, h), stretchW, stretchH };
}

/**
 * Box of a control inside its parent (parent = {w, h}).
 * @returns {{x, y, w, h}}
 */
export function controlBox(spec, parent) {
  let [x, y, w, h] = spec.rect || [0, 0, 0, 0];
  if (spec.anchor) {
    const ax = axis(spec.anchor[0], x, w, w, parent.w);
    const ay = axis(spec.anchor[1], y, h, h, parent.h);
    return { x: ax.p, y: ay.p, w: ax.s, h: ay.s };
  }
  // edge pins of controls (as windows): align_left L / align_right R / align_top T / align_bottom B put that edge
  // at L / parentW+R / T / parentH+B, center_h / center_v centre it (+ offset); the rect x / y add to it.
  // e.g. ui_charselectwnd.txt: pan_select (align_top 100, align_right 0), btn_create_char (align_right -150,
  // align_bottom -40), pan_connect (center_h 0, align_bottom -160); ui_loginwnd.txt pan_dekaron_logo (align_top 100).
  const p = spec.props || {};
  const pin = k => { const v = p[k]?.[0]; const n = v == null ? NaN : Number(v); return Number.isFinite(n) ? n : null; };
  const L = pin('align_left'), R = pin('align_right'), T = pin('align_top'), B = pin('align_bottom'), CH = pin('center_h'), CV = pin('center_v');
  if (R != null) x = parent.w + R - w + x;
  else if (L != null) x = L + x;
  else if (CH != null) x = Math.round((parent.w - w) / 2) + CH + x;
  if (B != null) y = parent.h + B - h + y;
  else if (T != null) y = T + y;
  else if (CV != null) y = Math.round((parent.h - h) / 2) + CV + y;
  return { x, y, w, h };
}

/** Keep a fitting window fully visible; oversized windows retain a reachable title strip. */
export function clampToScreen(x, y, w, h, screen, keep = 24) {
  const nx = w <= screen.w ? Math.min(Math.max(x, 0), screen.w - w)
    : Math.min(Math.max(x, keep - w), screen.w - keep);
  const ny = Math.min(Math.max(y, 0), h <= screen.h ? screen.h - h : screen.h - Math.min(keep, h || keep));
  return { x: Math.round(nx), y: Math.round(ny) };
}
