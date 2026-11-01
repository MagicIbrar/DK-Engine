// lane-perf: Global's own preload model (read-only parser). Source: share/maplist.csv column `Preloading` (e.g. braiken.pre)
// names a file in property/preload/; a <pre> block includes other .pre files (npc\*.pre, monster\*.pre, skill\*.pre),
// and an entity block lists <TPack>/<Mesh>/<Anim>/<Skel>/<Texture> paths (quoted or <angle-wrapped>). Case-insensitive.
const KINDS = new Set(['pre', 'tpack', 'mesh', 'anim', 'skel', 'texture']);
export function parsePreload(text) {
  const out = { pre: [], tpack: [], mesh: [], anim: [], skel: [], texture: [] };
  let kind = null;
  for (const raw of String(text).replace(/^\uFEFF/, '').split(/\r?\n/)) {
    const line = raw.trim(); if (!line) continue;
    const tag = /^<\/?([A-Za-z_][\w ]*)>$/.exec(line);
    if (tag && !/[\\.]/.test(line)) { const k = tag[1].toLowerCase(); kind = line[1] === '/' ? (KINDS.has(k) ? null : kind) : (KINDS.has(k) ? k : kind); continue; }
    const item = line.replace(/^<|>$/g, '').replace(/^"|"$/g, '').trim();
    if (!item) continue;
    const k = kind ?? (/\.pre$/i.test(item) ? 'pre' : null);
    if (k && /\.[a-z0-9]+$/i.test(item)) out[k].push(item.replace(/\//g, '\\'));
  }
  return out;
}
/** Every asset a map's Preloading entry reaches, deduplicated case-insensitively in first-seen order. read(rel) -> text|null. */
export function resolvePreload(entry, read, { includeCommon = true } = {}) {
  const seen = new Set(), assets = { tpack: [], mesh: [], anim: [], skel: [], texture: [] }, keys = new Set(), missing = [];
  const visit = rel => { const key = rel.toLowerCase(); if (seen.has(key)) return; seen.add(key); const text = read(rel); if (text == null) { missing.push(rel); return; }
    const p = parsePreload(text); for (const k of Object.keys(assets)) for (const a of p[k]) { const ak = k + ':' + a.toLowerCase(); if (!keys.has(ak)) { keys.add(ak); assets[k].push(a); } } for (const sub of p.pre) visit(sub); };
  if (includeCommon) { visit('common.pre'); visit('common_effect.pre'); }
  if (entry) visit(entry);
  return { files: [...seen], assets, missing };
}
