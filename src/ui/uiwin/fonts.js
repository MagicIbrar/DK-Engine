// script/ui/font.csv: `fontIndex` of the window scripts -> the client's GDI fonts (docs/formats/ui.md §5).
//   index,height,weight,shadow,facename,fontname
// Tahoma is a Windows system font (the client did not ship it) and is used as-is; NanumBarunGothic (100-102,
// Korean) falls back to Malgun Gothic. Rule (ui.md): bold when weight >= 6, 1-px black drop shadow when shadow.
// The builtin FONT_TABLE is font.csv verbatim (tools/test-uiwin.mjs checks it against the file); loadFonts()
// re-reads the shipped file so an edited font.csv is honoured.
import { fetchText } from '../../engine/assets.js';

const T = (height, weight, shadow, face = 'Tahoma') => ({ height, weight, bold: weight >= 6, shadow, face });
/** font.csv as shipped. */
export const FONT_TABLE = {
  1: T(8, 6.4, false), 2: T(11, 5.4, false), 3: T(11, 5.4, false), 4: T(11, 6.4, false), 5: T(11, 6.4, false),
  6: T(14, 5.4, false), 7: T(14, 6.4, false), 8: T(16, 6.4, false), 9: T(16, 6.4, false), 10: T(18, 5.4, false),
  11: T(18, 6.4, false), 12: T(22, 5.4, false), 13: T(22, 6.4, false), 14: T(16, 6.4, false), 15: T(16, 6.4, true),
  100: T(30, 5, true, 'NanumBarunGothic'), 101: T(16, 0.6, true, 'NanumBarunGothic'), 102: T(13, 0.4, true, 'NanumBarunGothic'),
  103: T(8, 15, true), 104: T(9, 15, true), 105: T(10, 10, true), 106: T(12, 10, true), 107: T(14, 10, true),
  108: T(15, 10, true), 109: T(16, 10, true), 110: T(18, 10, true), 111: T(20, 5, true), 112: T(24, 5, true),
  113: T(11, 10, true), 114: T(12, 9, true), 115: T(13, 8, true), 116: T(15, 7, true), 117: T(16, 7, true),
  118: T(18, 7, true), 119: T(22, 9, true),
};
export const DEFAULT_FONT = 2;

/** Parse font.csv text -> Map<index, {height, weight, bold, shadow, face}>. Handles the quoted "Tahoma,tahoma.ttf" rows. */
export function parseFontCSV(text) {
  const out = new Map();
  for (const line of String(text || '').split(/\r\n|\n|\r/).slice(1)) {
    const cells = [];
    let cur = '', q = false;
    for (const ch of line) {
      if (ch === '"') { q = !q; continue; }
      if (ch === ',' && !q) { cells.push(cur); cur = ''; continue; }
      cur += ch;
    }
    cells.push(cur);
    const idx = Number(cells[0]);
    if (!cells[0] || !Number.isFinite(idx)) continue;
    const height = Number(cells[1]), weight = Number(cells[2]);
    const shadow = /^true$/i.test(String(cells[3]).trim());
    let face = String(cells[4] || 'Tahoma').split(',')[0].trim();
    if (!/^[\x20-\x7e]+$/.test(face)) face = 'NanumBarunGothic';   // the Korean face name (EUC-KR)
    out.set(idx, { height, weight, bold: weight >= 6, shadow, face });
  }
  return out;
}

let table = { ...FONT_TABLE };
const availableFaces = new Map();
/** Platform-local originals only: missing fonts retain the documented fallback. */
export function fontAvailability() { return Object.fromEntries(availableFaces); }
/** Re-read script/ui/font.csv (EUC-KR). Resolves the table; never rejects. */
export async function loadFonts() {
  try {
    const m = parseFontCSV(await fetchText('script/ui/font.csv', true));
    if (m.size) { table = { ...FONT_TABLE }; for (const [k, v] of m) table[k] = v; }
  } catch { /* keep the builtin copy */ }
  if(typeof FontFace!=='undefined'&&typeof document!=='undefined'){
    await Promise.all([...new Set(Object.values(table).map(f=>f.face))].map(async face=>{
      // Probe the local face without registering a normal-only web face over the
      // platform family: native Tahoma Bold must remain available to bold rows.
      try{await new FontFace(face,`local(${JSON.stringify(face)})`).load();availableFaces.set(face,true);}
      catch{availableFaces.set(face,false);}
    }));
  }
  return table;
}

/** Font entry of a fontIndex (falls back to fontIndex 2). */
export function fontOf(index) { return table[index] || table[DEFAULT_FONT]; }

const FAMILY = {
  Tahoma: 'Tahoma, Verdana, "Segoe UI", sans-serif',
  NanumBarunGothic: '"NanumBarunGothic", "Malgun Gothic", "Apple SD Gothic Neo", Tahoma, sans-serif',
};
/** CSS `font` shorthand of a fontIndex. */
export function fontCSS(index) {
  const f = fontOf(index);
  return `${f.bold ? 'bold ' : ''}${f.height}px ${FAMILY[f.face] || `${JSON.stringify(f.face)}, ${FAMILY.Tahoma}`}`;
}
/** CSS text-shadow of a fontIndex ('' when the font has none). */
export function fontShadow(index) { return fontOf(index).shadow ? '1px 1px 0 #000' : ''; }

/** Apply a fontIndex to an element (font + line-height + shadow). */
export function applyFont(el, index, lineHeight = 0) {
  const f = fontOf(index);
  el.style.font = fontCSS(index);
  el.style.lineHeight = lineHeight ? `${lineHeight}px` : `${Math.round(f.height * 1.25)}px`;
  el.style.textShadow = f.shadow ? '1px 1px 0 #000' : '';
  return el;
}

let measureCtx = null;
/** Pixel width of a string in a fontIndex (canvas measureText; ~6 px/char estimate without a DOM). */
export function measureText(str, index) {
  if (typeof document !== 'undefined') {
    measureCtx ||= document.createElement('canvas').getContext('2d');
    measureCtx.font = fontCSS(index);
    return measureCtx.measureText(String(str)).width;
  }
  return String(str).length * Math.round(fontOf(index).height * 0.55);
}
