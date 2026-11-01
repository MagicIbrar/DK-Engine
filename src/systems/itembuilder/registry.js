// Custom item library of the item builder (src/systems/itembuilder). Pure logic: no DOM, no three.js, so the items
// system's ItemDB.load() (src/systems/items/db.js) and node tests (tools/test-itembuilder.mjs) can use it.
//
// A custom item is a real item of the items database: it gets its own item index in the free range
// 900,000,001 .. 900,999,998 (items.json has nothing between 1e8 and 1e9), a row in db.items with the items.json
// fields (docs/formats/items.md 3.1), a look in items-looks (looks[index] + its mesh/tpack/texture assets appended to
// looks.assets) and an item shape in items-visual (shapes[index]: game / inventory / field models). Everything else
// of the engine (bag footprints, tooltips, stats, equip rules, weapon bones and stances, character parts, icons,
// ground drops, shops, the GM spawner) then treats it exactly like an original item.
//
// Library record (the saved / exported format, assets inlined so an export is self-contained):
//   { index, name, desc, base (the item it was cloned from, 0 = none),
//     type, code, slot?, rank, classMask, reqLv, maxLv, reqStr, reqDex, reqSpr, reqGrade, price, sell, cash, npcSell,
//     w, h, stack, quality, itemLv, melee, magic, ranged, def, pvpDmg, pvpDef, block, range, speed, crit, options,
//     exOptions, optionPools, socketRates, union, use, value1, value2, trade, belong, period, action, ...,
//     grade ('normal'|'magic'|'noble'|'divine': grade of spawned instances), sockets (socket count of spawned
//     instances), roll (roll random options from optionPools on spawn),
//     look: { all: asset, byClass: {classIndex: asset}, left: asset, leftItem, action, leftAction, bone, parts,
//             weaponType, effect },
//     shape: { game: asset, inv: asset, field: asset, invAnim, invSkel, invAnimTime, invTwoSide, drop },
//     created, updated }
//   asset = { mesh, tpack, textures: [{material, diffuse, specular?}] } (data keys).

export const LS_KEY = 'dekaron-solo:customItems:v1';
export const BASE_INDEX = 900000000;
export const DRAFT_INDEX = 900999999;          // the builder's live preview item
export const LAST_INDEX = 900999998;
export const FORMAT = 'dekaron-online-custom-items';

/** Is this item index a custom (builder) item (the draft included)? */
export function isCustomIndex(i) { i = Number(i); return Number.isInteger(i) && i > BASE_INDEX && i <= DRAFT_INDEX; }

/** items.json row fields a record carries over (everything the engine reads from an item definition). */
export const ROW_FIELDS = ['type', 'code', 'rank', 'classMask', 'reqLv', 'maxLv', 'reqStr', 'reqDex', 'reqSpr', 'reqGrade',
  'price', 'sell', 'cash', 'npcSell', 'w', 'h', 'stack', 'maxStack', 'autoStack', 'quality', 'itemLv', 'melee', 'magic',
  'ranged', 'def', 'pvpDmg', 'pvpDef', 'block', 'range', 'speed', 'crit', 'options', 'exOptions', 'optionPools',
  'socketRates', 'value1', 'value2', 'use', 'trade', 'belong', 'periodBreak', 'period', 'union', 'appraisal', 'attribute',
  'action', 'cosShape', 'group', 'dropStack', 'dropRate', 'upgradeRate', 'addExp', 'addDrop', 'addDil', 'eventType'];

/** Armour part replaced by each armour slot (items.md 7.2). */
export const PART_OF_SLOT = { helmet: 'helmet', armor: 'coat', pants: 'pants', glove: 'glove', boots: 'boots' };

/** Slot group of a kind when the data has no example (items.md 4.1). */
export function defaultSlot(type, code) {
  type = Number(type); code = Number(code);
  if (type === 4) return [14, 15, 16, 21].includes(code) ? 'offhand' : code === 32 ? null : 'weapon';
  if (type === 5) {
    const m = { 0: 'helmet', 1: 'armor', 2: 'pants', 3: 'boots', 4: 'glove', 11: 'bracelet', 15: 'bracelet', 12: 'belt', 16: 'belt', 13: 'emblem', 18: 'talisman' };
    if (m[code]) return m[code];
    if ([5, 6, 7, 8, 9, 10, 14, 17].includes(code)) return 'costume';
    return null;
  }
  if (type === 2) return [8, 10, 14].includes(code) ? 'earring' : 'accessory';
  if (type === 6) return { 0: 'grow', 9: 'grow', 1: 'wing', 4: 'vehicle', 5: 'pet' }[code] || null;
  if (type === 10) return 'costume';
  if (type === 11) return 'force';
  return null;
}

/** Slot group of a (type, code) kind: the slot the original items of that kind use, else defaultSlot. */
export function slotForKind(db, type, code) {
  if (!db._kindSlot) {
    const counts = new Map();
    for (const k in db.items) {
      const it = db.items[k];
      if (!it?.slot || it.custom) continue;
      const kind = (Number(it.type) || 0) * 256 + (Number(it.code) || 0);
      let m = counts.get(kind);
      if (!m) counts.set(kind, (m = new Map()));
      m.set(it.slot, (m.get(it.slot) || 0) + 1);
    }
    db._kindSlot = new Map([...counts].map(([kind, m]) => [kind, [...m].sort((a, b) => b[1] - a[1])[0][0]]));
  }
  const kind = (Number(type) || 0) * 256 + (Number(code) || 0);
  return db._kindSlot.has(kind) ? db._kindSlot.get(kind) : defaultSlot(type, code);
}

const clone = (o) => (o == null ? o : JSON.parse(JSON.stringify(o)));
const num = (v, d = 0) => { const n = Number(v); return Number.isFinite(n) ? n : d; };
const pair = (v) => (Array.isArray(v) ? [num(v[0]), num(v[1])] : [0, 0]);

/** A clean asset object (mesh/tpack/textures data keys) or null. */
export function cleanAsset(a) {
  if (!a || typeof a !== 'object' || !a.mesh) return null;
  const out = { mesh: String(a.mesh) };
  if (a.tpack) out.tpack = String(a.tpack);
  if (Array.isArray(a.textures) && a.textures.length) {
    out.textures = a.textures.filter(t => t && (t.diffuse || t.specular)).map(t => {
      const o = { material: num(t.material) };
      if (t.diffuse) o.diffuse = String(t.diffuse);
      if (t.specular) o.specular = String(t.specular);
      return o;
    });
    if (!out.textures.length) delete out.textures;
  }
  for (const k of ['anim', 'skel']) if (a[k]) out[k] = String(a[k]);
  return out;
}

/** Normalise a record (types, ranges, derived fields). Returns a new object. */
export function normalizeRecord(rec, db = null) {
  const r = clone(rec) || {};
  r.index = num(r.index);
  r.name = String(r.name ?? '').slice(0, 120) || 'New Item';
  r.desc = String(r.desc ?? '').slice(0, 2000);
  r.type = num(r.type); r.code = num(r.code);
  if (db) { const s = slotForKind(db, r.type, r.code); if (s) r.slot = s; else delete r.slot; }
  r.rank = num(r.rank);
  r.classMask = num(r.classMask, 32767) & 32767;
  for (const k of ['reqLv', 'maxLv', 'reqStr', 'reqDex', 'reqSpr', 'reqGrade', 'price', 'sell', 'pvpDmg', 'pvpDef', 'block', 'range', 'speed', 'crit', 'itemLv', 'union', 'period', 'value1', 'value2'])
    if (r[k] != null) r[k] = Math.max(0, num(r[k]));
  r.w = Math.max(1, Math.min(4, Math.floor(num(r.w, 1))));
  r.h = Math.max(1, Math.min(5, Math.floor(num(r.h, 1))));
  r.stack = Math.max(0, Math.min(9999, Math.floor(num(r.stack))));
  r.npcSell = r.npcSell == null ? 1 : num(r.npcSell) ? 1 : 0;
  r.trade = r.trade == null ? 1 : num(r.trade) ? 1 : 0;
  for (const k of ['melee', 'magic', 'ranged', 'def']) if (r[k] != null) { const p = pair(r[k]); r[k] = [Math.max(0, p[0]), Math.max(0, p[1], p[0])]; }
  for (const k of ['options', 'exOptions']) {
    r[k] = (Array.isArray(r[k]) ? r[k] : []).map(o => [num(o?.[0]), num(o?.[1])]).filter(o => o[0] > 0 && o[1] !== 0).slice(0, k === 'options' ? 6 : 7);
  }
  r.grade = ['normal', 'magic', 'noble', 'divine'].includes(r.grade) ? r.grade : 'normal';
  r.sockets = Math.max(0, Math.min(4, Math.floor(num(r.sockets))));
  r.roll = !!r.roll;
  // look / shape: inline assets only
  const L = r.look && typeof r.look === 'object' ? r.look : {};
  const look = {};
  const all = cleanAsset(L.all); if (all) look.all = all;
  const left = cleanAsset(L.left); if (left) look.left = left;
  if (L.byClass && typeof L.byClass === 'object') {
    const bc = {};
    for (const [ci, a] of Object.entries(L.byClass)) { const c = cleanAsset(a); if (c && /^\d+$/.test(ci)) bc[ci] = c; }
    if (Object.keys(bc).length) look.byClass = bc;
  }
  for (const k of ['leftItem', 'action', 'leftAction', 'effect', 'leftEffect']) if (L[k] != null && L[k] !== '') look[k] = num(L[k]);
  if (L.bone) look.bone = String(L.bone);
  if (Array.isArray(L.parts) && L.parts.length) look.parts = L.parts.map(String);
  if (L.costype) look.costype = String(L.costype);
  r.look = look;
  const S = r.shape && typeof r.shape === 'object' ? r.shape : {};
  const shape = {};
  for (const k of ['game', 'inv', 'field']) { const a = cleanAsset(S[k]); if (a) shape[k] = a; }
  if (S.invAnim) shape.invAnim = String(S.invAnim);
  if (S.invSkel) shape.invSkel = String(S.invSkel);
  if (S.invAnimTime) shape.invAnimTime = num(S.invAnimTime, 2);
  if (num(S.invScale) > 0) shape.invScale = num(S.invScale);
  if (S.invTwoSide != null) shape.invTwoSide = !!S.invTwoSide;
  if (S.drop && typeof S.drop === 'object') shape.drop = clone(S.drop);
  r.shape = shape;
  r.created = num(r.created) || Date.now();
  r.updated = num(r.updated) || r.created;
  return r;
}

// ------------------------------------------------------------------------------------------ library storage
/** The stored library {format, version, items: [records]} (empty when nothing is stored / no localStorage). */
export function loadLibrary(storage = globalThis.localStorage) {
  let lib = null;
  try { lib = JSON.parse(storage?.getItem(LS_KEY) || 'null'); } catch { lib = null; }
  if (!lib || !Array.isArray(lib.items)) lib = { format: FORMAT, version: 1, items: [] };
  lib.items = lib.items.filter(r => r && isCustomIndex(r.index) && Number(r.index) !== DRAFT_INDEX).map(r => normalizeRecord(r));
  return lib;
}
export function saveLibrary(lib, storage = globalThis.localStorage) {
  try { storage?.setItem(LS_KEY, JSON.stringify({ format: FORMAT, version: 1, items: lib.items })); return true; } catch { return false; }
}
/** The next free custom index of a library. */
export function nextIndex(lib, taken = null) {
  const occupied = new Set(lib.items.map(r => Number(r.index)));
  for (const i of taken || []) occupied.add(Number(i));
  let max = BASE_INDEX;
  for (const r of lib.items) if (r.index > max && r.index < DRAFT_INDEX) max = r.index;
  let i = max + 1;
  while (occupied.has(i)) i++;
  if (i > LAST_INDEX) { for (i = BASE_INDEX + 1; i <= LAST_INDEX; i++) if (!occupied.has(i)) break; }
  if (i > LAST_INDEX) throw new Error('The custom item library is full.');
  return i;
}

// ------------------------------------------------------------------------------------------ database
function assetId(db, a) {
  const L = db.looks;
  db._customAssets ||= new Map();
  const key = JSON.stringify(a);
  let id = db._customAssets.get(key);
  if (id == null || L.assets[id] == null) { id = L.assets.length; L.assets.push(a); db._customAssets.set(key, id); }
  return id;
}

/** The items-looks entry of a record (asset ids allocated in db.looks.assets). */
function lookToDB(db, rec, slot) {
  const L = rec.look || {};
  const out = {};
  if (slot) out.slot = slot;
  if (L.all) out.all = assetId(db, L.all);
  if (L.left) out.left = assetId(db, L.left);
  if (L.byClass) { out.byClass = {}; for (const [ci, a] of Object.entries(L.byClass)) out.byClass[ci] = assetId(db, a); }
  for (const k of ['leftItem', 'action', 'leftAction', 'effect', 'leftEffect', 'bone', 'costype']) if (L[k] != null) out[k] = L[k];
  if (Number(rec.type) === 4) out.weaponType = 1024 + Number(rec.code);
  if (PART_OF_SLOT[slot]) out.parts = [PART_OF_SLOT[slot]];
  else if (L.parts?.length) out.parts = L.parts.slice();
  else if (slot === 'costume') out.parts = ['helmet', 'coat', 'pants', 'glove', 'boots'];
  if (slot === 'wing' && !out.bone) out.bone = db.equipment?.wingBone || 'weaponW';
  return (out.all != null || out.byClass || out.left != null) ? out : null;
}

/** The items-visual shape of a record, or null. */
function shapeToDB(rec) {
  const S = rec.shape || {};
  const game = S.game || rec.look?.all || (rec.look?.byClass && Object.values(rec.look.byClass)[0]) || null;
  const inv = S.inv || null;
  if (!game && !inv && !S.field) return null;
  const out = {};
  if (game) out.game = clone(game);
  if (inv) out.inv = clone(inv);
  if (S.field) out.field = clone(S.field);
  if (S.invAnim) out.invAnim = S.invAnim;
  if (S.invSkel) out.invSkel = S.invSkel;
  if (S.invAnimTime) out.invAnimTime = S.invAnimTime;
  if (S.invScale) out.invScale = S.invScale;
  out.invTwoSide = S.invTwoSide !== false;
  if (S.drop) out.drop = clone(S.drop);
  else if (Number(rec.type) === 4) out.drop = { pos: [0, 0.2, 0], scale: 1, rot: ['y', 90] };
  return out;
}

/**
 * Put a record into an ItemDB as item `index` (default rec.index): items row, description, look, shape.
 * Replaces an earlier version of the same index (the def cache is cleared).
 */
export function applyItem(db, rec, index = rec.index) {
  index = Number(index);
  if (!db || !db.items || !isCustomIndex(index)) return null;
  const r = normalizeRecord({ ...rec, index }, db);
  const row = { name: r.name, src: 'custom', custom: 1 };
  for (const k of ROW_FIELDS) if (r[k] !== undefined && r[k] !== null) row[k] = clone(r[k]);
  if (r.slot) row.slot = r.slot;
  row.w = r.w; row.h = r.h;
  if (!(row.stack > 1)) row.stack = 0;
  // description text (descriptions are keyed by description id: the custom item uses its own index)
  db.descriptions ||= {};
  if (r.desc) { db.descriptions[index] = r.desc; row.desc = index; } else { delete db.descriptions[index]; row.desc = 0; }
  // visuals
  if (db.looks) {
    db.looks.looks ||= {};
    db.looks.assets ||= [];
    const L = lookToDB(db, r, r.slot);
    if (L) db.looks.looks[index] = L; else delete db.looks.looks[index];
  }
  const shape = shapeToDB(r);
  if (shape) { db.visual ||= {}; db.visual.shapes ||= {}; db.visual.shapes[index] = shape; row.shape = index; }
  else { if (db.visual?.shapes) delete db.visual.shapes[index]; row.shape = 0; }
  db.items[index] = row;
  db._defs?.delete?.(index);
  db._byName = null;
  return db.def ? db.def(index) : row;
}

/** Remove a custom item from an ItemDB. */
export function removeItem(db, index) {
  index = Number(index);
  if (!db || !isCustomIndex(index)) return;
  delete db.items[index];
  if (db.looks?.looks) delete db.looks.looks[index];
  if (db.visual?.shapes) delete db.visual.shapes[index];
  if (db.descriptions) delete db.descriptions[index];
  db._defs?.delete?.(index);
  db._byName = null;
}

/** Apply every stored custom item to a freshly loaded ItemDB (called by ItemDB.load, before any save is read). */
export function applyStoredCustomItems(db, storage = globalThis.localStorage) {
  const lib = loadLibrary(storage);
  let n = 0;
  for (const r of lib.items) { try { if (applyItem(db, r)) n++; } catch (err) { console.warn('[itembuilder] custom item', r?.index, err); } }
  db._customLibrary = lib;
  return n;
}

// ------------------------------------------------------------------------------------------ records from items
/** An asset object of a look/asset id of the database (a copy), or null. */
export function assetOf(db, id) { return id == null ? null : cleanAsset(db.asset ? db.asset(id) : db.looks?.assets?.[id]); }

/**
 * A library record copied from an original (or custom) item: every row field, its description text, look (assets
 * inlined) and shape. `opts.lookOnly` returns just {look, shape}.
 */
export function recordFromItem(db, itemIndex, opts = {}) {
  const def = db.def(itemIndex);
  if (!def) return null;
  const L = db.look(itemIndex) || {};
  const look = {};
  if (L.all != null) look.all = assetOf(db, L.all);
  if (L.left != null) look.left = assetOf(db, L.left);
  if (L.byClass) { look.byClass = {}; for (const [ci, id] of Object.entries(L.byClass)) { const a = assetOf(db, id); if (a) look.byClass[ci] = a; } }
  for (const k of ['leftItem', 'action', 'leftAction', 'effect', 'leftEffect', 'bone', 'costype']) if (L[k] != null) look[k] = L[k];
  if (L.parts) look.parts = L.parts.slice();
  const sh = db.shape(def) || {};
  const shape = {};
  for (const k of ['game', 'inv', 'field']) { const a = cleanAsset(sh[k]); if (a) shape[k] = a; }
  if (shape.inv && sh.inv?.anim) shape.invAnim = sh.inv.anim;
  if (sh.invAnim) shape.invAnim = sh.invAnim;
  if (shape.inv && sh.inv?.skel) shape.invSkel = sh.inv.skel;
  if (sh.invSkel) shape.invSkel = sh.invSkel;
  if (sh.invAnimTime) shape.invAnimTime = sh.invAnimTime;
  if (sh.invScale) shape.invScale = sh.invScale;
  if (sh.invTwoSide != null) shape.invTwoSide = sh.invTwoSide;
  if (sh.drop) shape.drop = clone(sh.drop);
  if (opts.lookOnly) return { look, shape, action: def.action || 0 };
  const rec = { base: Number(itemIndex), name: def.name, desc: db.description ? db.description(def) : '', look, shape };
  for (const k of ROW_FIELDS) if (def[k] !== undefined) rec[k] = clone(def[k]);
  rec.w = def.w; rec.h = def.h;
  rec.grade = 'normal';
  rec.sockets = 0;
  rec.roll = false;
  return rec;
}

/** A blank record of a kind (defaults of items.json itemDefaults). */
export function blankRecord(db, type = 4, code = 1) {
  const d = db?.defaults || {};
  const rec = {
    name: 'New Item', desc: '', base: 0, type, code, rank: 0, classMask: 32767, reqLv: 1, maxLv: 0, reqStr: 0, reqDex: 0,
    reqSpr: 0, price: 100, sell: 0, npcSell: 1, trade: 1, w: 1, h: 1, stack: 0, quality: d.quality ?? 27, itemLv: 0,
    melee: [0, 0], magic: [0, 0], ranged: [0, 0], def: [0, 0], pvpDmg: 0, pvpDef: 0, block: 0, range: 0, speed: 0, crit: 0,
    options: [], exOptions: [], union: 0, grade: 'normal', sockets: 0, roll: false, look: {}, shape: {},
  };
  return rec;
}

// ------------------------------------------------------------------------------------------ export / import
/** The library as an export document (a JSON string). `indices` limits it to some items. */
export function exportLibrary(lib, indices = null) {
  const items = indices ? lib.items.filter(r => indices.includes(r.index)) : lib.items;
  return JSON.stringify({ format: FORMAT, version: 1, exported: new Date().toISOString(), items }, null, 1);
}

/**
 * Parse an export document (or a bare record / array of records) into normalised records. Indices that are taken
 * by a different item of `lib` (or are outside the custom range) are renumbered. Returns {records, renumbered}.
 * Optional maxRecords refuses oversized input lists before record normalisation (server imports: 100).
 */
export function parseImport(text, lib, db = null, { maxRecords = Infinity } = {}) {
  let data = typeof text === 'string' ? JSON.parse(text) : text;
  let list = Array.isArray(data) ? data : Array.isArray(data?.items) ? data.items : data && typeof data === 'object' ? [data] : [];
  if (list.length > maxRecords) throw new Error(`Import at most ${maxRecords} custom items at a time. Split the export into smaller files.`);
  list = list.filter(r => r && typeof r === 'object' && (r.name != null || r.type != null));
  const taken = new Set(lib.items.map(r => r.index));
  const used = new Set();
  let renumbered = 0;
  const records = [];
  for (const raw of list) {
    const r = normalizeRecord(raw, db);
    const same = lib.items.find(x => x.index === r.index);
    const clash = !isCustomIndex(r.index) || r.index === DRAFT_INDEX || used.has(r.index) || (same && (same.created !== r.created || same.name !== r.name));
    if (clash) { r.index = nextIndex(lib, new Set([...taken, ...used])); renumbered++; }
    used.add(r.index);
    records.push(r);
  }
  return { records, renumbered };
}
