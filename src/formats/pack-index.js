// Global pack index + reference resolver (lane L2). Pure; no Node APIs.
// Index source: data/pack.hdr of the Global client (see audit/global-ref/index.mjs -> index.tsv: path, pack, offset, size).
// Rules, tried in order; each returns the rule name so callers / reports can show why a path resolved:
//   exact     normalised key (lower case, '/', no leading data/ or ./) exists. Pack paths are stored lower-cased
//             (pack.hdr '/data/...'), and the game is case-insensitive on Windows -> case-fold is the native rule.
//   root      key relative to the type root the client config declares (data/shadow.txt [path]: path_bonemesh Mesh\,
//             path_bone Skel\, path_boneanimation Anim\, path_texture Texture\, path_texturepack TexturePack\,
//             path_sound Sound\, path_effect Property\Effect\, path_map Map\ ...).
//   squeeze   blanks around path segments / before the extension removed (modeldef.js resolveDataKey step 2).
//   texext    texture with another image extension, same stem (game uses D3DX, which sniffs content: dds.js sniffImageType;
//             same rule as tpack.js textureCandidates TEXTURE_EXTENSIONS).
//   basename  the only file with the same basename under the same type root (modeldef.js resolveDataKey step 3).
import { TEXTURE_EXTENSIONS, textureCandidates } from './tpack.js';

export const SHADOW_ROOTS = Object.freeze({ // extension -> roots, from data/shadow.txt [path]
  mesh: ['mesh'], skel: ['skel'], anim: ['anim'], tpack: ['texturepack'], dds: ['texture'], tga: ['texture'], bmp: ['texture'],
  jpg: ['texture'], png: ['texture'], wav: ['sound'], ogg: ['sound'], mp3: ['sound'], map: ['map'], mel: ['map'], mal: ['share', 'map'],
  mol: ['map'], mac: ['share/mapredcell', 'share', 'map'], txt: ['property/effect', 'property', 'script', 'map'], pre: ['property/preload'],
  // share tables (maplist.csv, list.csv, check.csv) name files relative to Share\ : maplist "Map\00_Braiken_Castle\NPC_..csv"
  // is share/map/00_braiken_castle/npc_..csv in the pack; light_*.txt from maplist is map/light_*.txt (path_map).
  csv: ['share'], act: ['share/action/action', 'share/action'],
});
const IMAGE = new Set(['dds', 'tga', 'bmp', 'jpg', 'png', ...TEXTURE_EXTENSIONS]);

export function normKey(p) {
  return String(p ?? '').trim().replace(/\\/g, '/').replace(/^(\.\/)+/, '').replace(/^\/+/, '').replace(/\/{2,}/g, '/')
    .toLowerCase().replace(/^data\//, '');
}
/** Parse index.tsv text -> { keys:Set, byBase:Map<basename,key[]>, entry:Map<key,{pack,offset,size}> } */
export function parsePackIndexTsv(text) {
  const keys = new Set(), byBase = new Map(), entry = new Map();
  for (const line of text.split('\n')) {
    if (!line) continue; const [p, pack, off, size] = line.split('\t'); const k = normKey(p);
    keys.add(k); entry.set(k, { pack, offset: Number(off), size: Number(size) });
    const b = k.slice(k.lastIndexOf('/') + 1); (byBase.get(b) || byBase.set(b, []).get(b)).push(k);
  }
  return { keys, byBase, entry };
}
const extOf = (k) => { const m = /\.([a-z0-9]+)$/.exec(k); return m ? m[1] : ''; };
/** Resolve one requested reference. -> { key, rule } or { key:null, rule:null, reason } */
export function resolveRef(ref, idx, { roots = null, texdir = null, meshPath = null, from = null, skillIndex = null } = {}) {
  const k = normKey(ref); if (!k) return { key: null, rule: null, reason: 'empty' };
  const has = (x) => idx.keys.has(x);
  if (has(k)) return { key: k, rule: 'exact' };
  // texpath: a .tpack slot names a file relative to its "texpath" folder under texture/ (tpack.js textureCandidates,
  // the same order the engine renderer already uses: game rule first, then parent/near folders, then .dds alias).
  if (texdir !== null) for (const c of textureCandidates(texdir, ref, { meshPath })) if (has(c)) return { key: c, rule: 'texpath' };
  // tabledir: a share table names files relative to its own folder (share/action/list.csv "Monster\\x.act.csv").
  if (from) { const d = normKey(from).replace(/[^/]*$/, ''); if (d && has(d + k)) return { key: d + k, rule: 'tabledir' }; }
  // actiondat: share/action/list.csv names the text action table "<Dir>\\<name>.csv"; Global ships only the compiled
  // twin share/action/action/<dir>/<name>.dat (2256/2256 list.csv rows absent as csv resolve this way; global-ref index).
  if (from && /^share\/action\//.test(normKey(from)) && k.endsWith('.csv')) {
    const c = 'share/action/action/' + k.replace(/^share\/action\//, '').replace(/\.csv$/, '.dat'); if (has(c)) return { key: c, rule: 'actiondat' };
  }
  // skilldat: share/skill/skilltable.csv cells are (index, name, csv); Global ships only share/skill/skill/<index>.dat
  // (tools/build-skills.mjs already reads it that way; parseSkillDat).
  if (skillIndex != null && k.endsWith('.csv')) { const c = `share/skill/skill/${skillIndex}.dat`; if (has(c)) return { key: c, rule: 'skilldat' }; }
  const ext = extOf(k); const rs = roots || SHADOW_ROOTS[ext] || [];
  const rooted = (x) => rs.map(r => x.startsWith(r + '/') ? x : `${r}/${x}`);
  for (const c of rooted(k)) if (has(c)) return { key: c, rule: 'root' };
  const sq = k.split('/').map(s => s.trim()).join('/').replace(/\s+(\.[a-z0-9]+)$/, '$1');
  for (const c of [sq, ...rooted(sq)]) if (sq !== k && has(c)) return { key: c, rule: 'squeeze' };
  if (IMAGE.has(ext)) {
    const stem = sq.slice(0, -ext.length - 1);
    for (const s of [stem, ...rooted(stem)]) for (const e of TEXTURE_EXTENSIONS)
      if (e !== ext && has(`${s}.${e}`)) return { key: `${s}.${e}`, rule: 'texext' };
  }
  // actdat: change_monster.csv / action tables name "<id>.<name>.act"; the pack stores the compiled "<id>.<name>.act.dat"
  // (share/action/action/monster/8494.rubicin.act.dat; build-skills.mjs reads swd.act.0.dat the same way).
  if (ext === 'act') {
    const b = sq.slice(sq.lastIndexOf('/') + 1) + '.dat';
    const c = (idx.byBase.get(b) || []).filter(x => x.startsWith('share/action/'));
    if (c.length === 1) return { key: c[0], rule: 'actdat' };
  }
  const base = sq.slice(sq.lastIndexOf('/') + 1);
  const cands = (idx.byBase.get(base) || []).filter(c => !rs.length || rs.some(r => c.startsWith(r + '/')));
  if (cands.length === 1) return { key: cands[0], rule: 'basename' };
  if (cands.length > 1) { // modeldef.js resolveDataKey scoring: most shared leading+trailing directory segments; unique best only
    const segs = (rs.length && !rs.some(r => sq.startsWith(r + '/')) ? `${rs[0]}/${sq}` : sq).split('/');
    const score = (c) => { const s = c.split('/'); let a = 0, b = 0;
      while (a < s.length - 1 && a < segs.length - 1 && s[a] === segs[a]) a++;
      while (b < s.length - 1 && b < segs.length - 1 && s[s.length - 2 - b] === segs[segs.length - 2 - b]) b++; return a + b; };
    const sc = cands.map(c => [score(c), c]).sort((x, y) => y[0] - x[0]);
    if (sc[0][0] > 0 && sc[0][0] > sc[1][0]) return { key: sc[0][1], rule: 'basename-scored' };
    return { key: null, rule: null, reason: `ambiguous-basename(${cands.length})`, candidates: cands.slice(0, 4) };
  }
  return { key: null, rule: null, reason: 'not-in-global-index' };
}

/** Build the same index from tools/client-pack.mjs inspectPack().entries (rel, pack, offset, size). */
export function packIndexFromEntries(entries) {
  return parsePackIndexTsv(entries.map(e => [e.rel, e.pack, e.offset, e.size].join('\t')).join('\n'));
}
