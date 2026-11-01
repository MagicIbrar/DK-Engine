// Map-object name -> asset file resolution (mesh / texturepack / textures / skeleton / animation).
//
// A .mol object name is always "<category>\<name>" (exactly one backslash). Two kinds exist:
//   1. "<category>\<name>"       (no extension; 6218 names, 75.7% of instances) -> row <name> of script/object/<category>.csv
//   2. "<Category>\<name>.txt"   (1213 names, 24.3% of instances)             -> text file object/static/<category>/<name>.txt
// Game-internal asset paths ("Object\tree\a.mesh") are relative to the per-type root folder:
//   mesh -> mesh/, tpack -> texturepack/, skel -> skel/, anim -> anim/, textures -> texture/<texpath>/.
// Every returned path is a data-relative key (lower case, forward slashes) usable as  /data/<key>.
// Pure functions only: no three.js, no Node APIs. See docs/formats/mol.md ("Asset resolution").

import { parseCSV, decodeText } from './binreader.js';
import { parseTpack, textureCandidates } from './tpack.js';

export const OBJECT_CATEGORIES = [
  'animal', 'bridge', 'building', 'building_extra', 'etc', 'field_extra', 'house',
  'junk', 'plant', 'portal', 'rock', 'siegeflag', 'tree', 'wall',
];

/** data-relative path of each object table */
export const OBJECT_TABLE_PATHS = Object.fromEntries(OBJECT_CATEGORIES.map(c => [c, `script/object/${c}.csv`]));

/** Column order of script/object/*.csv (header names are NOT reliable: several files have typos in column 0/19). */
export const OBJECT_TABLE_COLUMNS = [
  'index', 'name', 'mesh', 'tpack', 'skel', 'anim', 'time', 'twoside', 'maxdiffuse', 'shadow', 'fog', 'transparent',
  'uvx', 'uvy', 'uvspeed', 'material', 'bump', 'shininess', 'lodMesh', 'lodTpack', 'lod',
];
const NUMERIC_COLUMNS = new Set(['index', 'time', 'twoside', 'maxdiffuse', 'shadow', 'fog', 'transparent', 'uvx', 'uvy', 'uvspeed', 'material', 'bump', 'shininess', 'lod']);

const toText = (src) => (typeof src === 'string' ? src : decodeText(src instanceof ArrayBuffer ? new Uint8Array(src) : src));

/** Normalise any game path to a data key: backslashes -> '/', lower case, no leading './' or '/'. */
export function normPath(p) {
  return String(p ?? '').trim().replace(/\\/g, '/').replace(/^(\.\/)+/, '').replace(/^\/+/, '').replace(/\/{2,}/g, '/').toLowerCase();
}

/** Game path relative to a type root ("Object\\tree\\a.mesh") -> data key ("mesh/object/tree/a.mesh"). */
export function gamePathToData(root, p) {
  const n = normPath(p);
  if (!n) return null;
  const r = normPath(root).replace(/\/$/, '');
  return n.startsWith(r + '/') ? n : `${r}/${n}`;
}

function withExt(p, ext) { return p.replace(/\.[^./]*$/, '') + ext; }
/**
 * Repair a table path whose extension was mangled by hand-editing: "x" -> "x.mesh", "xmesh" -> "x.mesh",
 * "x.mesh" unchanged. Returns '' when no repair applies. Observed in the object tables, e.g.
 * "Object\wall\ba_stonewall_01" (11 lodmesh cells) and "ch_l_wall_linear_windowmesh".
 */
function repairExt(p, ext) {
  const s = String(p || '').trim();
  if (!s || new RegExp(`\\.${ext}$`, 'i').test(s)) return '';
  if (new RegExp(`[^.]${ext}$`, 'i').test(s)) return s.slice(0, -ext.length) + '.' + ext;
  if (!/\.[a-z0-9]{2,5}$/i.test(s.slice(s.lastIndexOf('\\') + 1))) return s + '.' + ext;
  return '';
}
/** Data-key candidates of one table path: as written, then the extension-repaired form. */
function pathCandidates(root, p, ext) {
  const out = [];
  if (!p) return out;
  const a = gamePathToData(root, p); if (a) out.push(a);
  const fixed = repairExt(p, ext);
  if (fixed) { const b = gamePathToData(root, fixed); if (b && !out.includes(b)) out.push(b); }
  return out;
}
function baseName(p) { const n = normPath(p); return n.slice(n.lastIndexOf('/') + 1); }
function num(v) {
  if (v === undefined || v === null) return null;
  const s = String(v).trim();
  if (s === '') return null;
  const x = Number(s);
  return Number.isFinite(x) ? x : s;
}
function uniq(list) { const out = []; for (const x of list) if (x && !out.includes(x)) out.push(x); return out; }

/** Split a .mol object name into { category, key, isStatic }. key is lower-case name without extension. */
export function splitObjectName(name) {
  const s = String(name).replace(/\//g, '\\');
  const i = s.indexOf('\\');
  const category = (i < 0 ? '' : s.slice(0, i)).trim().toLowerCase();
  let rest = (i < 0 ? s : s.slice(i + 1)).trim();
  const isStatic = /\.txt$/i.test(rest);
  if (isStatic) rest = rest.slice(0, -4);
  return { category, key: rest.toLowerCase(), isStatic };
}

/** data key of the object/static text file for a ".txt" object name (or null for table objects). */
export function objectStaticPath(name) {
  const { isStatic } = splitObjectName(name);
  return isStatic ? `object/static/${normPath(name)}` : null;
}

/**
 * Parse one script/object/<category>.csv.
 * @returns {Map<string, object>} lower-case name -> row (first definition wins; duplicate rows in the data are identical)
 */
export function parseObjectTable(src, category = '') {
  const rows = parseCSV(toText(src));
  const out = new Map();
  for (let i = 1; i < rows.length; i++) {
    const r = rows[i];
    if (!r || r.length < 3 || !String(r[1] ?? '').trim()) continue;
    const row = { category };
    OBJECT_TABLE_COLUMNS.forEach((c, k) => {
      const v = r[k];
      row[c] = NUMERIC_COLUMNS.has(c) ? num(v) : (v === undefined ? '' : String(v).trim());
    });
    if (r.length > OBJECT_TABLE_COLUMNS.length) row.extra = r.slice(OBJECT_TABLE_COLUMNS.length);
    const key = row.name.toLowerCase();
    if (!out.has(key)) out.set(key, row);
  }
  return out;
}

/**
 * Parse an object/static/**.txt descriptor, e.g.
 *   mesh      Object\animal\a_pig_01.mesh
 *   animation Object\animal\a_pig_01.anim 5
 *   skeleton  Object\animal\a_pig_01.skel
 *   shadow 1 / meshtype tree / transparent 1 / twoside 1 / maxdiffuse 1 / uvanim 0 -1 3 / nofog 1
 * Lines starting with // are disabled entries (kept in .commented).
 */
export function parseStaticObject(src) {
  const text = toText(src);
  const o = { mesh: '', animation: '', animTime: null, skeleton: '', shadow: null, meshtype: '', twoside: null,
    transparent: null, maxdiffuse: null, uvanim: null, nofog: null, extra: {}, commented: [] };
  for (const raw of text.split(/\r?\n/)) {
    const line = raw.trim();
    if (!line) continue;
    if (line.startsWith('//')) { o.commented.push(line.slice(2).trim()); continue; }
    const m = /^(\S+)\s*(.*)$/.exec(line);
    const key = m[1].toLowerCase();
    const rest = m[2].trim();
    const parts = rest.split(/\s+/).filter(Boolean);
    switch (key) {
      case 'mesh': o.mesh = rest; break;
      case 'skeleton': o.skeleton = rest; break;
      case 'animation': {
        // path may not contain spaces in practice; trailing number is the animation time value
        const last = parts[parts.length - 1];
        if (parts.length > 1 && /^-?\d+(\.\d+)?$/.test(last)) { o.animation = parts.slice(0, -1).join(' '); o.animTime = Number(last); }
        else o.animation = rest;
        break;
      }
      case 'meshtype': o.meshtype = rest.toLowerCase(); break;
      case 'shadow': case 'twoside': case 'maxdiffuse': case 'nofog': o[key] = num(parts[0]); break;
      case 'transparent': case 'trensparent': o.transparent = num(parts[0]); break; // 'trensparent' typo exists in data
      case 'uvanim': o.uvanim = parts.map(Number); break;
      default: o.extra[key] = parts;
    }
  }
  return o;
}

// .tpack parsing is owned by tpack.js (single parser for the whole engine); re-exported here for convenience.
export { parseTpack };

/**
 * Candidate data keys for one texture named in a tpack (first existing wins): tpack.js textureCandidates()
 * plus a ".dds" twin for the few tpacks that still name .bmp/.tga sources (e.g. "dv_wall_03.bmp").
 */
export function tpackTextureCandidates(texdir, file, meshPath = null) {
  const opts = meshPath ? { meshPath } : {};
  const c = textureCandidates(texdir, file, opts);
  if (!/\.dds$/i.test(file)) for (const p of textureCandidates(texdir, withExt(String(file), '.dds'), opts)) c.push(p);
  return uniq(c);
}

/**
 * Candidate lists for every texture of a parsed tpack (parseTpack result).
 * @returns {{diffuse:Record<number,string[]>, specular:Record<number,string[]>, bump:Record<number,string[]>, glow:Record<number,string[]>}}
 */
export function resolveTpackTextures(tp, meshPath = null) {
  const res = {};
  for (const kind of ['diffuse', 'specular', 'bump', 'glow']) {
    res[kind] = {};
    for (const [slot, file] of Object.entries(tp[kind] || {})) res[kind][slot] = tpackTextureCandidates(tp.texdir, file, meshPath);
  }
  return res;
}

/**
 * Build the lookup database.
 * @param {{ tables?: Record<string, string|ArrayBuffer|Uint8Array|Map>, statics?: Record<string, string|ArrayBuffer|Uint8Array|object>,
 *           files?: Iterable<string> }} opts
 *   tables: category -> csv content (or an already parsed Map from parseObjectTable)
 *   statics: data key ("object/static/tree/a.txt") -> txt content (or parsed object)  — optional, can be added lazily
 *   files: optional list of every existing data key (lower case). Enables existence checks + basename fallback.
 */
export function buildObjectDB({ tables = {}, statics = {}, files = null } = {}) {
  const db = { tables: new Map(), statics: new Map(), files: null, meshByBase: null };
  for (const [cat, src] of Object.entries(tables)) {
    db.tables.set(cat.toLowerCase(), src instanceof Map ? src : parseObjectTable(src, cat.toLowerCase()));
  }
  for (const [p, src] of Object.entries(statics)) addStaticObject(db, p, src);
  if (files) setFileIndex(db, files);
  return db;
}

export function addStaticObject(db, path, src) {
  db.statics.set(normPath(path), (src && typeof src === 'object' && 'mesh' in src && 'extra' in src) ? src : parseStaticObject(src));
}

/** Attach an existence index (iterable of data keys). Used to pick existing candidates and for basename fallback. */
export function setFileIndex(db, files) {
  db.files = files instanceof Set ? files : new Set([...files].map(normPath));
  db.meshByBase = new Map();
  for (const f of db.files) {
    if (!f.startsWith('mesh/') || !f.endsWith('.mesh')) continue;
    const b = f.slice(f.lastIndexOf('/') + 1);
    if (!db.meshByBase.has(b)) db.meshByBase.set(b, []);
    db.meshByBase.get(b).push(f);
  }
}

// fallback order for basename search (object folders first, then other static-mesh style roots)
const MESH_FALLBACK_ROOTS = ['mesh/object/', 'mesh/brick/', 'mesh/npc/', 'mesh/effect/', 'mesh/'];

/**
 * Resolve a .mol object name to asset candidates.
 * @param {string} name   e.g. "plant\\b_grasstotal_01" or "Tree\\a_autumntree_01.txt"
 * @param {object} [db]   from buildObjectDB(); without it (or without the row) only naming conventions are used
 * @returns {{
 *   name:string, category:string, key:string, source:'table'|'static'|'convention', pending?:boolean, staticPath:string|null,
 *   mesh:string|null, tpack:string|null, skel:string|null, anim:string|null, anims:string[], animTime:number|null,
 *   lodMesh:string|null, lodTpack:string|null, lod:number|null, animated:boolean,
 *   flags:object, row?:object, static?:object,
 *   candidates:{mesh:string[], tpack:string[], skel:string[], anim:string[], lodMesh:string[], lodTpack:string[]},
 *   exists?:{mesh:boolean, tpack:boolean, skel:boolean, anim:boolean}
 * }}
 *   mesh/tpack/skel/anim are the best candidate (first existing one when db.files is set, else the first candidate).
 *   Table paths with a mangled extension ("x", "xmesh") also get a repaired candidate ("x.mesh") right after the raw one.
 */
export function resolveObject(name, db = null) {
  const { category, key, isStatic } = splitObjectName(name);
  const convMesh = `mesh/object/${category}/${key}.mesh`;
  const out = {
    name, category, key, source: 'convention', staticPath: isStatic ? `object/static/${normPath(name)}` : null,
    mesh: null, tpack: null, skel: null, anim: null, anims: [], animTime: null,
    lodMesh: null, lodTpack: null, lod: null, animated: false, flags: {},
    candidates: { mesh: [], tpack: [], skel: [], anim: [], lodMesh: [], lodTpack: [] },
  };
  let meshGame = '', tpackGame = '', skelGame = '', animGame = '';
  let lodMeshC = [], lodTpackC = [];
  if (isStatic) {
    const st = db && db.statics.get(out.staticPath);
    if (st) {
      out.source = 'static'; out.static = st;
      meshGame = st.mesh; skelGame = st.skeleton; animGame = st.animation; out.animTime = st.animTime;
      out.flags = { shadow: st.shadow, meshtype: st.meshtype, twoside: st.twoside, transparent: st.transparent,
        maxdiffuse: st.maxdiffuse, uvanim: st.uvanim, nofog: st.nofog, ...st.extra };
    } else {
      out.pending = true; // descriptor not loaded: fetch out.staticPath, addStaticObject(db, path, text), resolve again
    }
  } else {
    const tab = db && db.tables.get(category);
    const row = tab && (tab.get(key) || tab.get(key.trim()));
    if (row) {
      out.source = 'table'; out.row = row;
      meshGame = row.mesh; tpackGame = row.tpack; skelGame = row.skel; animGame = row.anim; out.animTime = row.time;
      out.lod = row.lod;
      lodMeshC = pathCandidates('mesh', row.lodMesh, 'mesh');
      lodTpackC = pathCandidates('texturepack', row.lodTpack, 'tpack');
      out.flags = { twoside: row.twoside, maxdiffuse: row.maxdiffuse, shadow: row.shadow, fog: row.fog, transparent: row.transparent,
        uvx: row.uvx, uvy: row.uvy, uvspeed: row.uvspeed, material: row.material, bump: row.bump, shininess: row.shininess };
    }
  }
  // Data errors: some rows put the .mesh path into the skel/anim columns (e.g. plant\mi_grass_0x). The client cannot
  // load those as skeleton/animation, so they are ignored (object renders static) and reported in badRefs.
  out.badRefs = [];
  if (skelGame && !/\.skel$/i.test(skelGame)) { out.badRefs.push(`skel:${skelGame}`); skelGame = ''; }
  if (animGame && !/\.anim$/i.test(animGame)) { out.badRefs.push(`anim:${animGame}`); animGame = ''; }
  // --- mesh
  const meshC = [];
  if (meshGame) meshC.push(...pathCandidates('mesh', meshGame, 'mesh'));
  meshC.push(convMesh);
  // --- texture pack: explicit column > same path as the mesh > lod tpack column > naming convention
  const tpC = [];
  if (tpackGame) tpC.push(...pathCandidates('texturepack', tpackGame, 'tpack'));
  for (const m of meshC) if (/\.mesh$/.test(m)) tpC.push(withExt(m.replace(/^mesh\//, 'texturepack/'), '.tpack'));
  tpC.push(...lodTpackC);
  tpC.push(`texturepack/object/${category}/${key}.tpack`);
  // --- skeleton / animation (only when declared: static objects are not skinned unless a skeleton is given)
  const skC = [], anC = [];
  if (skelGame) skC.push(gamePathToData('skel', skelGame));
  if (animGame) anC.push(gamePathToData('anim', animGame));
  if (skelGame || animGame) {
    const mb = meshC[0].replace(/^mesh\//, '');
    if (!skelGame) skC.push('skel/' + withExt(mb, '.skel'));
    if (!animGame) anC.push('anim/' + withExt(mb, '.anim'));
  }
  // --- basename fallbacks (need a file index)
  if (db && db.meshByBase) {
    const b = baseName(meshC[0]);
    const alts = (db.meshByBase.get(b) || []).slice().sort((a, c) => rootRank(a) - rootRank(c));
    for (const a of alts) {
      meshC.push(a);
      tpC.push(withExt(a.replace(/^mesh\//, 'texturepack/'), '.tpack'));
    }
  }
  out.candidates.mesh = uniq(meshC);
  out.candidates.tpack = uniq(tpC);
  out.candidates.skel = uniq(skC);
  out.candidates.anim = uniq(anC);
  out.candidates.lodMesh = uniq(lodMeshC);
  out.candidates.lodTpack = uniq(lodTpackC);
  const pick = (list) => {
    if (!list.length) return null;
    if (db && db.files) return list.find(p => db.files.has(p)) || null;
    return list[0];
  };
  out.mesh = pick(out.candidates.mesh);
  out.tpack = pick(out.candidates.tpack);
  out.skel = pick(out.candidates.skel);
  out.anim = pick(out.candidates.anim);
  // lod: without a file index keep the path as written (first candidate); with one, the first existing candidate,
  // falling back to the declared path so callers can still see what was requested
  out.lodMesh = pick(out.candidates.lodMesh) || out.candidates.lodMesh[0] || null;
  out.lodTpack = pick(out.candidates.lodTpack) || out.candidates.lodTpack[0] || null;
  out.anims = out.anim ? [out.anim] : [];
  out.animated = !!(skelGame || animGame);
  if (db && db.files) {
    out.exists = { mesh: !!out.mesh, tpack: !!out.tpack, skel: out.candidates.skel.length ? !!out.skel : null, anim: out.candidates.anim.length ? !!out.anim : null };
  }
  return out;
}

function rootRank(p) {
  for (let i = 0; i < MESH_FALLBACK_ROOTS.length; i++) if (p.startsWith(MESH_FALLBACK_ROOTS[i])) return i;
  return MESH_FALLBACK_ROOTS.length;
}

/**
 * Browser-friendly async helper: loads the 14 object tables once (and object/static descriptors on demand).
 * @param {(key:string)=>Promise<string>} fetchText  e.g. engine/assets.js fetchText
 */
export async function loadObjectDB(fetchText, { files = null } = {}) {
  const tables = {};
  await Promise.all(OBJECT_CATEGORIES.map(async (c) => {
    try { tables[c] = await fetchText(OBJECT_TABLE_PATHS[c]); } catch { /* table missing: convention fallback */ }
  }));
  return buildObjectDB({ tables, files });
}

/** resolveObject() that fetches the object/static descriptor first when needed. */
export async function resolveObjectAsync(name, db, fetchText) {
  let r = resolveObject(name, db);
  if (r.pending && r.staticPath) {
    try { addStaticObject(db, r.staticPath, await fetchText(r.staticPath)); r = resolveObject(name, db); }
    catch { /* keep convention result */ }
  }
  return r;
}
