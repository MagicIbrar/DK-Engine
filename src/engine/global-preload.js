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

// ---- 4.3.2 workstream E: Global's preload lists in FILE ORDER (not grouped by kind) ---------------------------------
// parsePreloadOrdered keeps every listed item where the .pre lists it, so a <pre> include is expanded at its own line
// (depth-first). Several tags on one line (`</anim><texture>`) are split. An item outside a kind block is typed by its
// extension. Items whose kind cannot be told are returned in `unparsed` (never silently dropped).
const EXT_KIND = { pre: 'pre', tpack: 'tpack', mesh: 'mesh', anim: 'anim', skel: 'skel', dds: 'texture', tga: 'texture', bmp: 'texture', jpg: 'texture', png: 'texture' };
export function parsePreloadOrdered(text) {
  const items = [], unparsed = [];
  let kind = null, entity = null, lineNo = 0;
  for (const raw of String(text).replace(/^\uFEFF/, '').split(/\r?\n/)) {
    lineNo++;
    // split "</anim><texture>" style lines into tokens; keep quoted / angle-wrapped paths whole
    const tokens = String(raw).trim().match(/"[^"]*"|<[^<>]*>|[^\s<>"][^<>"]*[^\s<>"]|[^\s<>"]/g) || [];
    for (const tok of tokens) {
      const tag = /^<(\/?)([A-Za-z_][\w ]*)>$/.exec(tok);
      if (tag && !/[\\.]/.test(tok)) {
        const k = tag[2].toLowerCase(), close = tag[1] === '/';
        if (KINDS.has(k)) kind = close ? null : k;
        else if (close) { if (entity && entity.toLowerCase() === k) entity = null; }
        else entity = tag[2];
        continue;
      }
      const item = tok.replace(/^<|>$/g, '').replace(/^"|"$/g, '').trim();
      if (!item) continue;
      const ext = /\.([a-z0-9]+)$/i.exec(item)?.[1]?.toLowerCase();
      if (!ext) continue;   // stray words between tags (none in g2; counted by the census test)
      const k = ext === 'pre' ? 'pre' : (kind && kind !== 'pre' ? kind : EXT_KIND[ext] || null);
      const rec = { kind: k, path: item.replace(/\//g, '\\'), entity, line: lineNo };
      if (k) items.push(rec); else unparsed.push(rec);
    }
  }
  return { items, unparsed };
}

/**
 * A Preloading entry (plus the startup roots) in Global's file order: `order` lists every asset once, first-seen,
 * in the depth-first order the .pre files name them; `files` lists every .pre visited in that order with how it
 * resolved ('ok' | 'alias' | 'missing'). aliases: { lowerKey: {kind:'GLOBAL-TYPO-ALIAS', to} } (see
 * config/global-preload-aliases.js); an alias is only followed when the exact name has no file.
 */
export function resolvePreloadOrdered(entries, read, { aliases = null, seen = new Set(), assetKeys = new Set() } = {}) {
  const order = [], files = [], missing = [], aliased = [], unparsed = [];
  const visit = (rel, from) => {
    const key = String(rel).replace(/\//g, '\\').toLowerCase();
    if (seen.has(key)) return; seen.add(key);
    let text = read(rel), status = 'ok', as = rel;
    if (text == null) {
      const a = aliases?.[key];
      if (a && a.kind === 'GLOBAL-TYPO-ALIAS' && a.to) {
        const toKey = a.to.replace(/\//g, '\\').toLowerCase();
        text = read(a.to); as = a.to;
        if (text != null) { status = 'alias'; aliased.push({ name: rel, to: a.to, from }); if (seen.has(toKey)) { files.push({ name: rel, status, as, from }); return; } seen.add(toKey); }
      }
      if (text == null) { status = 'missing'; missing.push({ name: rel, from, documented: aliases?.[key]?.kind || null }); files.push({ name: rel, status, as: null, from }); return; }
    }
    files.push({ name: rel, status, as, from });
    const p = parsePreloadOrdered(text);
    for (const u of p.unparsed) unparsed.push({ ...u, file: as });
    for (const it of p.items) {
      if (it.kind === 'pre') { visit(it.path, as); continue; }
      const ak = it.kind + ':' + it.path.toLowerCase();
      if (assetKeys.has(ak)) continue;
      assetKeys.add(ak);
      order.push({ kind: it.kind, path: it.path, file: as, entity: it.entity });
    }
  };
  for (const e of [].concat(entries || []).filter(Boolean)) visit(e, null);
  return { order, files, missing, aliased, unparsed };
}
