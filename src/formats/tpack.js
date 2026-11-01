// Dekaron .tpack (texture pack) parser + texture path resolution. Pure functions, browser + Node.
// Full description: docs/formats/tpack.md
//
// A .tpack is a tiny latin1 text file, one "key <whitespace> value" pair per line:
//     texpath   "monster"            folder under texture/ (either slash, any case)
//     0         "spiderlord01.dds"   diffuse texture of material slot 0  (= mesh.material of parseMesh)
//     s0        "spiderlord01_s.dds" specular/gloss map of slot 0   (also "S0", "0s", bare "s" = slot 0)
//     b1        "ze_wall_01_b.dds"   bump / normal map of slot 1
//     g0        "Nymph_01_g.dds"     glow (emissive) map of slot 0
//     //0       "dr_box_01.dds"      commented out
// Values are normally double-quoted, but the corpus also contains unquoted values, a missing closing
// quote, trailing junk after the closing quote and a stray leading ':'; all are tolerated.
// Texture names may contain '#' and spaces: URL-encode each path segment before fetching.

import { decodeText } from './binreader.js';

const toText = (src) => (typeof src === 'string' ? src
  : decodeText(src instanceof ArrayBuffer ? new Uint8Array(src) : src, false));

/** Normalise a game path fragment: backslashes -> '/', lower case, trimmed, no leading/trailing slashes. */
export function normTexPath(p) {
  return String(p ?? '').trim().replace(/\\/g, '/').replace(/\/{2,}/g, '/').replace(/^\.?\/+/, '').replace(/\/+$/, '').toLowerCase();
}

function cleanValue(raw) {
  let v = raw.trim();
  if (v.startsWith('"')) {
    const end = v.indexOf('"', 1);
    const rest = end < 0 ? '' : v.slice(end + 1);
    v = end < 0 ? v.slice(1) : v.slice(1, end);
    // '""c_roller.dds""' -> doubled quotes around the name
    if (!v && /[^"\s]/.test(rest)) v = rest.replace(/"/g, ' ').trim().split(/\s+/)[0];
  } else {
    v = v.split(/\s+/)[0] ?? '';
  }
  v = v.replace(/^[:\s"]+/, '').replace(/["\s]+$/, '');
  return v;
}

/**
 * Parse tpack text.
 * @param {string|ArrayBuffer|Uint8Array} src
 * @returns {{
 *   texpath: string|null,            // raw texpath value (null if absent)
 *   texdir: string|null,             // normalised texpath ("effect/monster")
 *   diffuse: Record<number,string>,  // slot -> file name as written
 *   specular: Record<number,string>, bump: Record<number,string>, glow: Record<number,string>,
 *   slots: number[],                 // sorted diffuse slot numbers
 *   empty: Record<string, number[]>, // kind -> slots listed with an empty value ('3  ""' = no texture)
 *   entries: Array<{key:string, kind:string, slot:number|null, value:string, line:number}>,
 *   disabled: Array<{key:string, value:string, line:number}>,  // "//" commented lines and "_texpath"
 *   unknown: Array<{line:number, text:string}>
 * }}
 */
export function parseTpack(src) {
  const text = toText(src);
  const out = { texpath: null, texdir: null, diffuse: {}, specular: {}, bump: {}, glow: {}, slots: [],
    empty: {}, entries: [], disabled: [], unknown: [] };
  const lines = text.split(/\r\n|\n|\r/);
  let disabledTexpath = null;
  for (let ln = 0; ln < lines.length; ln++) {
    const s = lines[ln].replace(/^﻿/, '').trim();
    if (!s) continue;
    let m = /^(\S+?)(?:\s+|(?="))(.*)$/.exec(s);
    // a bare key without value ("2", 4 lines in the corpus) = that slot has no texture, like '2 ""'
    if (!m && /^(?:\d+|[sbg]\d+|\d+s)$/i.test(s)) m = [s, s, ''];
    if (!m) { out.unknown.push({ line: ln + 1, text: s }); continue; }
    const key = m[1];
    const value = cleanValue(m[2] ?? '');
    if (key.startsWith('//') || key.startsWith('#') || key.startsWith(';')) {
      out.disabled.push({ key, value, line: ln + 1 }); continue;
    }
    const k = key.toLowerCase();
    let kind = null, slot = null, mm;
    if (k === 'texpath') kind = 'texpath';
    else if (k === '_texpath') { disabledTexpath = value; out.disabled.push({ key, value, line: ln + 1 }); continue; }
    else if ((mm = /^(\d+)$/.exec(k))) { kind = 'diffuse'; slot = +mm[1]; }
    else if ((mm = /^s(\d*)$/.exec(k)) || (mm = /^(\d+)s$/.exec(k))) { kind = 'specular'; slot = mm[1] === '' ? 0 : +mm[1]; }
    else if ((mm = /^b(\d+)$/.exec(k))) { kind = 'bump'; slot = +mm[1]; }
    else if ((mm = /^g(\d+)$/.exec(k))) { kind = 'glow'; slot = +mm[1]; }
    if (kind && !value) {
      // '0  ""' = slot deliberately without texture; 'texpath ""' = files directly under texture/
      if (kind === 'texpath') { if (out.texpath === null) out.texpath = ''; }
      else (out.empty[kind] ||= []).push(slot);
      out.entries.push({ key, kind, slot, value: '', line: ln + 1 });
      continue;
    }
    if (!kind) { out.unknown.push({ line: ln + 1, text: s }); continue; }
    out.entries.push({ key, kind, slot, value, line: ln + 1 });
    // A slot defined twice keeps the FIRST value (19 files): the repeat is nearly always a mistyped specular
    // ('0 "mooncake.dds"' then '0 "mooncake_s.dds"') or an effect '#' variant. All values stay in `entries`.
    if (kind === 'texpath') { if (out.texpath === null) out.texpath = value; }
    else if (!(slot in out[kind])) out[kind][slot] = value;
  }
  if (out.texpath === null && disabledTexpath !== null) out.texpathFallback = disabledTexpath;
  out.texdir = out.texpath !== null ? normTexPath(out.texpath) : (disabledTexpath !== null ? normTexPath(disabledTexpath) : null);
  out.slots = Object.keys(out.diffuse).map(Number).sort((a, b) => a - b);
  return out;
}

/** Top-level texture folders present in the client (texture/<folder>/...). */
export const TEXTURE_ROOT_FOLDERS = ['character', 'costume', 'effect', 'item', 'monster', 'npc', 'object', 'servant',
  'vehicle', 'sentry', 'remote', 'brick', 'etc', 'environment', 'water', 'maptile', 'ui', 'minimap', 'losthorizon'];

/**
 * Candidate data-relative paths (lower case, '/' separated, NOT url-encoded) for one texture of a tpack,
 * most likely first. The first candidate is the path the game itself uses (texture/<texpath>/<file>);
 * the rest are fallbacks for the few broken tpacks (wrong texpath, file moved to a sibling folder).
 * @param {ReturnType<typeof parseTpack>} tpack
 * @param {number} slot material slot (parseMesh -> mesh.material)
 * @param {'diffuse'|'specular'|'bump'|'glow'} [kind]
 * @param {{meshPath?: string}} [opts] meshPath = data key of the .mesh (adds folders derived from it)
 * @returns {string[]} empty when the tpack has no such slot
 */
export function resolveTexture(tpack, slot, kind = 'diffuse', opts = {}) {
  const file = tpack?.[kind]?.[slot];
  if (!file) return [];
  return textureCandidates(tpack.texdir, file, opts);
}

/** Other extensions tried when the named file is absent (tpacks sometimes name the .bmp/.psd/.tga art source). */
export const TEXTURE_EXTENSIONS = ['dds', 'tga', 'bmp', 'jpg', 'png'];

/**
 * Build a basename index for the last-resort lookup: Map(lower-case file name -> [data keys]).
 * @param {Iterable<string>} keys data keys of every file under texture/ (e.g. from a directory listing)
 */
export function buildTextureIndex(keys) {
  const m = new Map();
  for (const k0 of keys) {
    const k = normTexPath(k0);
    if (!k.startsWith('texture/')) continue;
    const b = k.slice(k.lastIndexOf('/') + 1);
    const stem = b.replace(/\.[^.]*$/, '');
    for (const name of [b, `${stem}.*`]) { let l = m.get(name); if (!l) m.set(name, (l = [])); l.push(k); }
  }
  return m;
}

/**
 * Candidate list for an arbitrary (texdir, file) pair. See resolveTexture.
 * @param {{meshPath?: string, index?: Map<string,string[]>}} [opts] index = buildTextureIndex(...) result
 */
export function textureCandidates(texdir, file, opts = {}) {
  const f = normTexPath(file);
  const base = f.slice(f.lastIndexOf('/') + 1);
  const stemOf = (p) => p.replace(/\.[^./]*$/, '');
  const near = [], far = [];
  const addDir = (list, d) => { d = d.replace(/\/+$/, ''); if (!near.includes(d) && !far.includes(d)) list.push(d); };
  const dir = texdir ? normTexPath(texdir) : '';
  // 1. the game rule, 2. parent folders of texpath / texture root / mesh-derived folders ("near"),
  // 3. every other top-level texture folder ("far": original name and .dds only)
  const primary = dir ? `texture/${dir}/${f}` : `texture/${f}`;
  if (dir) {
    const parts = dir.split('/');
    for (let i = parts.length - 1; i > 0; i--) addDir(near, `texture/${parts.slice(0, i).join('/')}`);
  }
  addDir(near, 'texture');
  if (opts.meshPath) {
    // mesh/<type>/... -> texture/<type>/, and alongside the mesh itself
    const segs = normTexPath(opts.meshPath).split('/');
    if (segs.length > 2) addDir(near, `texture/${segs[1]}`);
    addDir(near, segs.slice(0, -1).join('/'));
  }
  if (dir) addDir(near, `texture/${dir}`);
  for (const root of TEXTURE_ROOT_FOLDERS) addDir(far, `texture/${root}`);
  addDir(far, 'object');
  const out = [];
  const add = (p) => { if (p && !out.includes(p)) out.push(p); };
  const addWithExts = (p) => {
    add(p);
    const stem = stemOf(p);
    for (const e of TEXTURE_EXTENSIONS) add(`${stem}.${e}`);
  };
  addWithExts(primary);
  for (const d of near) add(`${d}/${base}`);
  for (const d of near) addWithExts(`${d}/${base}`);
  for (const d of far) add(`${d}/${base}`);
  for (const d of far) add(`${d}/${stemOf(base)}.dds`);
  if (opts.index) {
    const hits = [...(opts.index.get(base) || []), ...(opts.index.get(`${stemOf(base)}.*`) || [])];
    const first = dir.split('/')[0];
    hits.sort((a, b) => (b.startsWith(`texture/${first}/`) ? 1 : 0) - (a.startsWith(`texture/${first}/`) ? 1 : 0));
    for (const h of hits) add(h);
  }
  return out;
}

/**
 * Data key of the .tpack that belongs to a mesh: texturepack/<same relative path>.tpack.
 * Returns candidates (the texturepack/ mirror first, then a .tpack next to the mesh).
 * @param {string} meshPath data key or game path, e.g. "mesh/monster/spider_lord.mesh"
 */
export function tpackPathForMesh(meshPath) {
  const mp = normTexPath(meshPath).replace(/\.mesh$/, '');
  // data key "mesh/monster/x" or game path relative to mesh/ ("Monster\\x.mesh")
  if (/^(anim|texture|skel|texturepack)\//.test(mp)) return [`${mp}.tpack`]; // stray meshes: tpack beside them
  const rel = mp.startsWith('mesh/') ? mp.slice(5) : mp;
  return [`texturepack/${rel}.tpack`, `mesh/${rel}.tpack`];
}

/** Encode a data key for fetch(): every segment URI-encoded ('#', spaces, '%' are legal in names). */
export function dataUrl(key, prefix = '/data/') {
  return prefix + String(key).split('/').map(encodeURIComponent).join('/');
}
