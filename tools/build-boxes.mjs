#!/usr/bin/env node
// Dekaron Solo — openable boxes / packages / level-up boxes database builder.
//
//   node tools/build-boxes.mjs [--data <unpacked data root>] [--out <dir>] [--pretty] [--quiet]
//
// Reads the user's own unpacked client (default ../data/unpacked/data next to the engine) and writes
//   gamedata/boxes.json   every openable item (box, package, Ex-Box, lucky box, summon box, keyed treasure chest,
//                         pet egg), its contents + probabilities + requirements, the level-up box chains, the
//                         recommended new-character grant, item stubs (name/type/class/level) for every item the
//                         tables reference, and the small reward tables that feed boxes (connect/attendance/
//                         DekaPass/event-time rewards, roulette/supply machines, map treasure chests, premium
//                         service items, accessory sealing), and `grantedBy`: where each box comes from (quests,
//                         D-Shop / NPC shops via gamedata/dshop.json + shops.json, reward tables, drop item sets).
// The run doubles as the validation script: cross references (item, item-set, monster, map, string, data-key) are
// checked, 12 boxes are re-read straight from the raw CSV text and compared with the JSON, and a summary is printed
// (exit code 1 on hard failures).  Format + field documentation: docs/formats/boxes.md
//
// The parse* functions are pure (buffer/string in, plain objects out) so the engine can reuse them.

import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { BinReader, parseCSV, toArrayBuffer } from '../src/formats/binreader.js';

// ------------------------------------------------------------------------------------------------
// text helpers (pure)
// ------------------------------------------------------------------------------------------------
const utf16 = new TextDecoder('utf-16le');
let krDecoder = null;
try { krDecoder = new TextDecoder('euc-kr'); } catch { krDecoder = null; }
/** True ISO-8859-1 decode (byte -> same code point, reversible). */
export function latin1(u8) {
  let s = '';
  for (let i = 0; i < u8.length; i += 8192) s += String.fromCharCode.apply(null, u8.subarray(i, i + 8192));
  return s;
}
/** latin1-decoded string holding EUC-KR/CP949 bytes -> Korean text (ASCII passes through). */
export function kr(s) {
  if (!s || !/[\x80-\xff]/.test(s) || !krDecoder) return s;
  const b = new Uint8Array(s.length);
  for (let i = 0; i < s.length; i++) b[i] = s.charCodeAt(i) & 0xff;
  return krDecoder.decode(b);
}
const num = (v, d = 0) => { const x = Number(String(v ?? '').trim()); return Number.isFinite(x) ? x : d; };
const isInt = (v) => /^-?\d+$/.test(String(v ?? '').trim());

// ------------------------------------------------------------------------------------------------
// script/lines_eu (UTF-16LE localisation db; same layout as tools/build-monsters.mjs parseLinesEu)
//   u32 nTxt  { u32 len, wchar name[len], u32 n, n x (i32,i32) }
//   u32 nCsv  { u32 len, wchar name[len], u32 n, n x (i32 col,i32 -1) }
//   u32 nStr  { u32 id, u32 len, wchar text[len] }
//   u32 nKeyT { u32 len, wchar key[len], u32 id }          txt keys (skipped)
//   u32 nKeyC { u32 len, wchar key[len], u32 id }          csv keys "item#itemcash.csv#1|<row>"
// ------------------------------------------------------------------------------------------------
export function parseLinesEu(buf, { keyFilter = null } = {}) {
  const r = new BinReader(buf);
  const wstr = (n) => utf16.decode(r.bytes(n * 2));
  const readIndex = () => {
    const n = r.u32(); const files = [];
    for (let i = 0; i < n; i++) {
      const name = wstr(r.u32()); const c = r.u32(); const cols = [];
      for (let k = 0; k < c; k++) cols.push([r.i32(), r.i32()]);
      files.push({ name, cols });
    }
    return files;
  };
  const txtFiles = readIndex();
  const csvFiles = readIndex();
  const nStr = r.u32();
  const strings = new Map();
  for (let i = 0; i < nStr; i++) { const id = r.u32(); strings.set(id, wstr(r.u32())); }
  const readKeys = (filter) => {
    const n = r.u32(); const m = new Map();
    for (let i = 0; i < n; i++) { const k = wstr(r.u32()); const id = r.u32(); if (!filter || filter(k)) m.set(k, id); }
    return { count: n, map: m };
  };
  const txtKeys = readKeys(() => false);
  const csvKeys = readKeys(keyFilter);
  return { txtFiles, csvFiles, strings, txtKeyCount: txtKeys.count, csvKeyCount: csvKeys.count, csvKeys: csvKeys.map, trailingBytes: r.remaining };
}

// ------------------------------------------------------------------------------------------------
// share/item/item.dat and share/item/itemevent/itemevent.dat: the compiled item tables the client really uses.
// No header, fixed 565-byte records (84 020 + 10 783).  Field offsets were located by correlating every record with
// its row in the item*.csv twins (63 493 matched rows); the rate is the share of rows where the field equals the
// csv column.  Only the fields the box system needs are decoded here; the items builder owns the full layout.
// ------------------------------------------------------------------------------------------------
export const ITEM_DAT_RECORD = 565;
export const ITEM_DAT_FIELDS = [ // [offset, type, name, csv column, match rate]
  [128, 'u32', 'index', 'ItemIndex', 1.0],
  [137, 'u8', 'rank', 'Rank', 0.975],
  [141, 'i32', 'type', 'Type', 1.0],
  [145, 'u8', 'code', 'Code', 0.999],
  [153, 'u16', 'desc', 'Description (stringtable_item cate 20 code)', 0.96],
  [155, 'i32', 'quality', 'Quality', 1.0],
  [159, 'u16', 'jobExt', 'Job digits 17-32 (accessory 8-group masks)', 0.998],
  [161, 'u16', 'job', 'Job digits 1-16: digit i (class i) = bit 15-i', 0.998],
  [163, 'i32', 'shape', 'ItemShape', 0.999],
  [190, 'u16', 'reqLv', 'ReqLv', 1.0],
  [192, 'u16', 'reqHLv', 'ReqHLv', 1.0],
  [202, 'u8', 'width', 'Width', 1.0],
  [203, 'u8', 'height', 'Height', 1.0],
  [204, 'wchar65', 'nameKey', 'lines_eu csv key of the Name column', 1.0],
  [334, 'u16', 'stack', 'StackNumber', 0.985],
  [550, 'i32', 'period', 'Period (seconds until the item expires, 0 = permanent)', 1.0],
];
export function parseItemDat(buf) {
  const u8 = buf instanceof Uint8Array ? buf : new Uint8Array(toArrayBuffer(buf));
  const dv = new DataView(u8.buffer, u8.byteOffset, u8.byteLength);
  if (u8.length % ITEM_DAT_RECORD) throw new Error(`item dat size ${u8.length} is not a multiple of ${ITEM_DAT_RECORD}`);
  const out = [];
  for (let o = 0; o < u8.length; o += ITEM_DAT_RECORD) {
    let e = o + 204; while (e < o + 334 && (u8[e] || u8[e + 1])) e += 2;
    out.push({
      index: dv.getUint32(o + 128, true), rank: u8[o + 137], type: dv.getInt32(o + 141, true), code: u8[o + 145],
      desc: dv.getUint16(o + 153, true), quality: dv.getInt32(o + 155, true), jobExt: dv.getUint16(o + 159, true),
      job: dv.getUint16(o + 161, true), shape: dv.getInt32(o + 163, true), reqLv: dv.getUint16(o + 190, true),
      reqHLv: dv.getUint16(o + 192, true), width: u8[o + 202], height: u8[o + 203],
      nameKey: utf16.decode(u8.subarray(o + 204, e)), stack: dv.getUint16(o + 334, true), period: dv.getInt32(o + 550, true),
    });
  }
  return out;
}
/** Job column "1000-0100-..." -> 16-bit mask in the item.dat layout (digit i -> bit 15-i). */
export function jobStringToMask(s) {
  const d = String(s || '').replace(/[^01]/g, '');
  let m = 0; for (let i = 0; i < 16 && i < d.length; i++) if (d[i] === '1') m |= 1 << (15 - i);
  return m;
}
export const maskToClasses = (m, nClasses = 15) => { const a = []; for (let i = 0; i < nClasses; i++) if (m & (1 << (15 - i))) a.push(i); return a; };

/** script/string/*.txt: "<cate> N" blocks of "code K ... { text }". Returns Map "cate:code" -> text. */
export function parseStringTable(txt) {
  const out = new Map(); let cate = null;
  const re = /<cate>\s*(\d+)|(?:^|\n)\s*code\s+(\d+)[^\n]*\r?\n\s*\{\r?\n?([\s\S]*?)\r?\n\s*\}/g; let m;
  while ((m = re.exec(txt))) { if (m[1]) cate = +m[1]; else if (!out.has(`${cate}:${m[2]}`)) out.set(`${cate}:${m[2]}`, m[3]); }
  return out;
}

/**
 * share/item/itemchange_randombox.csv (the box table the server runs when a box item is used):
 *   Index, Type, WminLevel, WmaxLevel, BonusItemIndex, BonusStackCount, TakeItemCount, GiveItemCount, DRopFilde,
 *   ServerMessageIndex, listCount, then 36 x (GiveIndex n, StackNum n, Percent n).
 */
export function parseRandomBoxCsv(text) {
  const rows = parseCSV(text);
  const out = [];
  for (let i = 1; i < rows.length; i++) {
    const r = rows[i]; if (!r || !isInt(r[0])) continue;
    const n = num(r[10]); const e = [];
    for (let k = 0; k < n; k++) e.push([num(r[11 + 3 * k]), num(r[12 + 3 * k]), num(r[13 + 3 * k])]);
    const trailing = r.slice(11 + 3 * n).filter((x) => String(x).trim() !== '' && String(x).trim() !== '0');
    out.push({ index: num(r[0]), type: num(r[1]), minLv: num(r[2]), maxLv: num(r[3]), bonusItem: num(r[4]), bonusCount: num(r[5]),
      take: num(r[6]), give: num(r[7]), dropField: num(r[8]), msg: num(r[9]), list: n, entries: e, trailing, line: i + 1 });
  }
  return out;
}
/** share/item/itempackage.csv: PackageItemIndex, WminLevel, WmaxLevel, ItemCount, 10 x (ItemIndex n, StackNum n). */
export function parseItemPackageCsv(text) {
  const rows = parseCSV(text); const out = [];
  for (let i = 1; i < rows.length; i++) {
    const r = rows[i]; if (!r || !isInt(r[0])) continue;
    const n = num(r[3]); const e = [];
    for (let k = 0; k < n; k++) e.push([num(r[4 + 2 * k]), num(r[5 + 2 * k])]);
    out.push({ index: num(r[0]), minLv: num(r[1]), maxLv: num(r[2]), entries: e, line: i + 1 });
  }
  return out;
}
/** share/premiere/cash_randombox.csv: BoxItem_Index, KeyCount, KeyItem_Index_0..5, list_Count, 30 x (Item, Stack, Percent(cum /1e6), Notify). */
export function parseCashRandomBoxCsv(text) {
  const rows = parseCSV(text); const out = [];
  for (let i = 1; i < rows.length; i++) {
    const r = rows[i]; if (!r || !isInt(r[0])) continue;
    const nk = num(r[1]); const keys = []; for (let k = 0; k < 6; k++) { const v = num(r[2 + k]); if (v) keys.push(v); }
    const n = num(r[8]); const e = [];
    for (let k = 0; k < n; k++) e.push([num(r[9 + 4 * k]), num(r[10 + 4 * k]), num(r[11 + 4 * k]), num(r[12 + 4 * k])]);
    out.push({ index: num(r[0]), keyCount: nk, keys, list: n, entries: e, line: i + 1 });
  }
  return out;
}

/**
 * Raw Percent/weight column -> per-entry weights.  Three encodings occur in the client:
 *   cumulative  non-decreasing, last value = the roll range (itemchange_randombox 10000, cash_randombox 1 000 000)
 *   weights     per-entry numbers (non-monotonic rows, egg_box, roulette) -> total = sum
 *   uniform     every value 0 (single-item "random" boxes) -> each entry weight 1
 */
export function toWeights(p, { denom = 0, forceWeights = false } = {}) {
  const n = p.length;
  if (!n) return { w: [], total: 0, mode: 'empty' };
  if (p.every((x) => x === 0)) return { w: p.map(() => 1), total: n, mode: 'uniform' };
  const mono = p.every((x, i) => i === 0 || x >= p[i - 1]);
  if (!forceWeights && mono && n > 1) {
    const w = p.map((x, i) => x - (i ? p[i - 1] : 0));
    return { w, total: Math.max(p[n - 1], denom || 0), mode: 'cumulative' };
  }
  if (!forceWeights && n === 1) return { w: [p[0]], total: Math.max(p[0], denom || 0), mode: 'cumulative' };
  const total = p.reduce((a, b) => a + b, 0);
  return { w: p.slice(), total, mode: 'weights' };
}

// ================================================================================================
// Node side
// ================================================================================================
const HERE = path.dirname(fileURLToPath(import.meta.url));
const ENGINE = path.resolve(HERE, '..');
const argv = process.argv.slice(2);
const arg = (k) => { const i = argv.indexOf(k); return i >= 0 ? argv[i + 1] : null; };
const DATA = path.resolve(arg('--data') || process.env.DEKARON_DATA || path.resolve(ENGINE, '../data/unpacked/data'));
const OUTDIR = path.resolve(arg('--out') || path.join(ENGINE, 'gamedata'));
const PRETTY = argv.includes('--pretty');
const QUIET = argv.includes('--quiet');
const log = (...a) => { if (!QUIET) console.log(...a); };
const problems = { hard: [], soft: [] };
const hard = (m) => problems.hard.push(m);
const soft = (m) => problems.soft.push(m);
const readRel = (rel) => fs.readFileSync(path.join(DATA, rel));
const readText = (rel) => latin1(readRel(rel));
const existsRel = (rel) => { try { return fs.statSync(path.join(DATA, rel)).isFile(); } catch { return false; } };
/** data key (lower case, '/' separated, relative to the data root) of a file that exists on disk, else null. */
function dataKeyOf(rel) {
  const k = rel.replace(/\\/g, '/').toLowerCase();
  return existsRel(k) ? k : null;
}

// class names (pcclass.csv order = Job digit order), EU display names + the spellings used in box/item names
const CLASS_NAMES = ['Azure Knight', 'Segita Hunter', 'Incar Magician', 'Vicious Summoner', 'Segnale', 'Bagi Warrior', 'Aloken',
  'Dragon Knight', 'Segita Shooter', 'Black Wizard', 'Conserra Summoner', 'Segeuriper', 'Half Bagi', 'Alokes', 'Trie Muse'];
const CLASS_ALIASES = [ // longest first; matched against "(...)" groups of an item name
  [12, /half ?bagi/i], [8, /segita shooter|shooter/i], [7, /d-?knight|dragon knight|dragon night/i], [9, /black wizard|wizard/i],
  [10, /con[cs]err?a|c\. ?summ/i], [11, /seg(?:u|eu)?r(?:i|ee|e)?(?:pp|p)er|segreaper|seguriper|segripper|segeuriper/i], [13, /alokes/i],
  [14, /trie ?muse|triemuse/i], [6, /aloken/i], [5, /bagi warrior|bagi|b\. ?warrior/i], [4, /segnale/i],
  [3, /vicious|v\. ?summ/i], [2, /incar magician|magician|i\. ?magician/i], [1, /segita hunter|hunter|s\. ?hunter/i],
  [0, /azure knight|azur knight|a\. ?knight|knight/i],
];
function classFromName(name) {
  const groups = String(name || '').match(/\(([^)]*)\)/g) || [];
  for (const g of groups) for (const [c, re] of CLASS_ALIASES) if (re.test(g)) return c;
  return null;
}

function main() {
  const t0 = Date.now();
  if (!fs.existsSync(DATA)) { console.error(`data root not found: ${DATA}`); process.exit(2); }
  log(`data root: ${DATA}`);
  const SRC = {};
  const src = (id, rel) => { const k = dataKeyOf(rel); if (!k) hard(`missing source ${rel}`); SRC[id] = k; return k; };

  // ---------------------------------------------------------------- localisation (item names)
  src('linesEu', 'script/lines_eu');
  const lines = parseLinesEu(readRel('script/lines_eu'), { keyFilter: (k) => k.startsWith('item#') || k.startsWith('itemevent#') });
  if (lines.trailingBytes) hard(`lines_eu: ${lines.trailingBytes} trailing bytes`);
  const loc = (key) => { const id = lines.csvKeys.get(key); return id ? lines.strings.get(id) ?? null : null; };

  // ---------------------------------------------------------------- item universe
  const ITEMS = new Map(); // index -> { n, t, c, lv, job, period, stack, w, h, shape, desc, rank, from }
  const datCounts = {};
  for (const [id, rel] of [['itemDat', 'share/item/item.dat'], ['itemEventDat', 'share/item/itemevent/itemevent.dat']]) {
    src(id, rel);
    const recs = parseItemDat(readRel(rel));
    datCounts[id] = recs.length;
    for (const x of recs) {
      if (ITEMS.has(x.index)) { soft(`${rel}: duplicate item ${x.index}`); continue; }
      const n = loc(x.nameKey);
      if (!n) soft(`${rel}: item ${x.index} name key ${x.nameKey} not in lines_eu`);
      ITEMS.set(x.index, { n, t: x.type, c: x.code, lv: x.reqLv, job: x.job, period: x.period, stack: x.stack, w: x.width, h: x.height,
        shape: x.shape, desc: x.desc, rank: x.rank, from: id });
    }
  }
  // CSV twins: names for the few rows missing from the .dat files + itemmileage.csv (mileage shop items, csv only)
  const CSV_ITEM_FILES = ['share/item/itemarmor.csv', 'share/item/itemweapon.csv', 'share/item/itemcash.csv', 'share/item/itemetc.csv',
    'share/item/itemaccessory.csv', 'share/item/itemetc_socket.csv', 'share/item/itemmileage.csv', 'share/item/itemevent/cashevent.csv',
    'share/item/itemevent/etcevent.csv', 'share/item/itemevent/accessoryevent.csv'];
  let csvOnly = 0, csvRows = 0;
  for (const rel of CSV_ITEM_FILES) {
    src(`csv:${rel.split('/').pop()}`, rel);
    const rows = parseCSV(readText(rel)); const h = rows[0].map((x) => x.trim().toLowerCase());
    const col = (n) => h.indexOf(n.toLowerCase());
    const [cN, cT, cC, cJ, cL, cS, cW, cH, cD, cSt] = ['name', 'type', 'code', 'job', 'reqlv', 'itemshape', 'width', 'height', 'description', 'stacknumber'].map(col);
    const fileKey = rel.split('/').pop();
    const prefix = rel.includes('/itemevent/') ? 'itemevent#' : 'item#';
    for (let i = 1; i < rows.length; i++) {
      const r = rows[i]; if (!r || !isInt(r[0])) continue; csvRows++;
      const idx = num(r[0]);
      if (ITEMS.has(idx)) continue;
      csvOnly++;
      const n = loc(`${prefix}${fileKey}#1|${i}`) || kr(String(r[cN] ?? '').trim()) || null;
      ITEMS.set(idx, { n, t: num(r[cT]), c: num(r[cC]), lv: num(r[cL]), job: jobStringToMask(r[cJ]), period: 0, stack: num(r[cSt]), w: num(r[cW]), h: num(r[cH]),
        shape: num(r[cS]), desc: num(r[cD]), rank: 0, from: `csv:${fileKey}` });
    }
  }
  log(`items: ${ITEMS.size} (item.dat ${datCounts.itemDat}, itemevent.dat ${datCounts.itemEventDat}, csv-only ${csvOnly} of ${csvRows} csv rows)`);
  const itemName = (i) => ITEMS.get(i)?.n ?? null;

  // ---------------------------------------------------------------- string tables
  src('stringItem', 'script/string/item/stringtable_item.txt');
  const strItem = parseStringTable(readText('script/string/item/stringtable_item.txt'));
  src('stringRandomBoxInfo', 'script/string/cash/stringtable_randomboxinfo.txt');
  const strRbi = parseStringTable(readText('script/string/cash/stringtable_randomboxinfo.txt'));
  src('stringMessageBox', 'script/string/normal/stringtable_messagebox.txt');
  const strMsg = parseStringTable(readText('script/string/normal/stringtable_messagebox.txt'));
  src('stringNotice', 'script/string/normal/stringtable_notice.txt');
  const strNotice = parseStringTable(readText('script/string/normal/stringtable_notice.txt'));
  src('stringConnectReward', 'script/string/normal/stringtable_connectreward.txt');

  // ---------------------------------------------------------------- item sets (T2 contents, map treasure chests)
  src('itemSet', 'share/item/itemset.csv');
  const ITEMSET = new Map();
  for (const r of parseCSV(readText('share/item/itemset.csv')).slice(1)) {
    if (!r || !isInt(r[0])) continue;
    const n = num(r[3]); const e = [];
    for (let k = 0; k < n; k++) e.push([num(r[4 + 5 * k]), num(r[5 + 5 * k]), num(r[6 + 5 * k]), num(r[7 + 5 * k]), num(r[8 + 5 * k])]);
    ITEMSET.set(num(r[0]), { n: kr(String(r[1] || '').trim()), total: num(r[2]), e });
  }
  src('itemSetEx', 'share/item/itemsetex.csv'); src('itemSetExGroup', 'share/item/itemsetexgroup.csv');
  const ITEMSETEX = new Map();
  const exGroupRatio = new Map();
  for (const r of parseCSV(readText('share/item/itemsetexgroup.csv')).slice(1)) if (r && isInt(r[0])) exGroupRatio.set(`${num(r[0])}:${num(r[1])}`, num(r[3]));
  for (const r of parseCSV(readText('share/item/itemsetex.csv')).slice(1)) {
    if (!r || !isInt(r[0])) continue;
    const e = []; for (let k = 4; k + 3 < r.length; k += 4) { const it = num(r[k]); if (it) e.push([it, num(r[k + 1]), num(r[k + 2]), num(r[k + 3])]); }
    const id = num(r[0]); if (!ITEMSETEX.has(id)) ITEMSETEX.set(id, { groups: [] });
    ITEMSETEX.get(id).groups.push({ g: num(r[1]), n: kr(String(r[2] || '').trim()), ratio: num(r[3]), groupRatio: exGroupRatio.get(`${id}:${num(r[1])}`) ?? null, e });
  }

  // ---------------------------------------------------------------- monsters (T4 summon boxes) + maps
  let MONSTERS = null;
  const gd = process.env.DEKARON_GAMEDATA || path.join(ENGINE, 'gamedata');
  const monPath = path.join(gd, 'monsters.json');
  if (fs.existsSync(monPath)) { try { MONSTERS = JSON.parse(fs.readFileSync(monPath, 'utf8')).monsters; } catch (e) { soft(`gamedata/monsters.json unreadable: ${e.message}`); } }
  src('monsterCsv', 'share/creature/monster.csv');
  const MONCSV = new Map();
  for (const r of parseCSV(readText('share/creature/monster.csv')).slice(1)) if (r && isInt(r[0])) MONCSV.set(num(r[0]), { n: String(r[1] || '').trim(), lv: num(r[4]) });
  src('mapList', 'share/maplist.csv');
  const MAPS = new Map();
  for (const r of parseCSV(readText('share/maplist.csv')).slice(1)) if (r && isInt(r[0])) MAPS.set(num(r[0]), String(r[1] || '').trim());
  if (existsRel('share/server/maplist.csv')) { src('serverMapList', 'share/server/maplist.csv'); for (const r of parseCSV(readText('share/server/maplist.csv')).slice(1)) if (r && isInt(r[0]) && !MAPS.has(num(r[0]))) MAPS.set(num(r[0]), null); }

  // ---------------------------------------------------------------- box tables
  src('randomBox', 'share/item/itemchange_randombox.csv');
  const RB = parseRandomBoxCsv(readText('share/item/itemchange_randombox.csv'));
  src('itemPackage', 'share/item/itempackage.csv');
  const PK = parseItemPackageCsv(readText('share/item/itempackage.csv'));
  src('eggBox', 'share/item/egg_box.csv');
  const EGG = new Map();
  for (const r of parseCSV(readText('share/item/egg_box.csv')).slice(1)) {
    if (!r || !isInt(r[0])) continue;
    const b = num(r[0]); if (!EGG.has(b)) EGG.set(b, { e: [], desc: kr(String(r[3] || '').trim()) });
    EGG.get(b).e.push([num(r[1]), 1, num(r[2])]);
  }
  src('cashRandomBox', 'share/premiere/cash_randombox.csv');
  const CRB = parseCashRandomBoxCsv(readText('share/premiere/cash_randombox.csv'));
  src('randomBoxInfo', 'script/cashshop/randomboxinfo.csv');
  const RBI = new Map();
  for (const r of parseCSV(readText('script/cashshop/randomboxinfo.csv')).slice(1)) if (r && isInt(r[0])) RBI.set(num(r[0]), { showDigit: num(r[2]), nameKr: kr(String(r[1] || '').trim()) });
  src('randomBoxEffect', 'script/effect/randomboxeffect.csv');
  const RBFX = new Map();
  for (const r of parseCSV(readText('script/effect/randomboxeffect.csv')).slice(1)) if (r && isInt(r[0])) RBFX.set(num(r[0]), { cate: num(r[1]), id: num(r[2]), scene: num(r[3]), timeMs: num(r[4]) });

  const BOXES = new Map();
  const kindOfType = { 0: 'select', 1: 'random', 2: 'itemset', 4: 'summon', 5: 'keyed', 8: 'package' };
  const typeCounts = {}; const rawCounts = { dropFieldNonZero: 0, trailingData: 0, giveMismatchPackage: [], countZero: [] };
  for (const r of RB) {
    typeCounts[r.type] = (typeCounts[r.type] || 0) + 1;
    if (BOXES.has(r.index)) { hard(`randombox duplicate ${r.index}`); continue; }
    let k = kindOfType[r.type];
    if (!k) { soft(`randombox ${r.index}: unknown Type ${r.type}`); k = `type${r.type}`; }
    if (r.type === 0 && r.give >= r.list) k = 'all';
    const box = { src: 'randombox', t: r.type, k, give: r.give, take: r.take, minLv: r.minLv, maxLv: r.maxLv, msg: r.msg, line: r.line };
    if (r.bonusItem) box.bonus = [r.bonusItem, r.bonusCount];
    if (r.dropField) { rawCounts.dropFieldNonZero++; box.raw = { ...(box.raw || {}), dropField: r.dropField }; }
    if (r.trailing.length) { rawCounts.trailingData++; box.raw = { ...(box.raw || {}), trailing: r.trailing.map(num) }; }
    if (r.type === 8 && r.give !== r.list) rawCounts.giveMismatchPackage.push(r.index);
    if (r.entries.some((x) => x[1] === 0)) rawCounts.countZero.push(r.index);
    if (k === 'random' || k === 'itemset' || k === 'summon') {
      const W = toWeights(r.entries.map((x) => x[2]), { denom: 10000 });
      box.e = r.entries.map((x, i) => [x[0], x[1], W.w[i]]); box.total = W.total; box.wmode = W.mode;
      if (W.mode === 'cumulative' && W.total !== 10000) soft(`randombox ${r.index}: cumulative percent ends at ${r.entries.at(-1)[2]} (< 10000: the remainder is an empty roll)`);
    } else {
      box.e = r.entries.map((x) => [x[0], x[1], 0]);
      if (r.entries.some((x) => x[2])) box.raw = { ...(box.raw || {}), percent: r.entries.map((x) => x[2]) }; // ignored by select/package boxes
    }
    BOXES.set(r.index, box);
  }
  // itempackage.csv: D-Shop / cash-inventory package definitions.  Rows that the box table lacks become boxes; rows
  // that differ from the box table are kept as box.pkg (alternative contents).
  let pkOnly = 0, pkSame = 0, pkDiff = 0;
  const pkKey = (e) => JSON.stringify(e.map((x) => `${x[0]}x${x[1]}`).sort());
  for (const p of PK) {
    const b = BOXES.get(p.index);
    if (!b) { pkOnly++; BOXES.set(p.index, { src: 'itempackage', t: 'pkg', k: 'package', give: p.entries.length, take: 1, minLv: p.minLv, maxLv: p.maxLv, msg: 0, e: p.entries.map((x) => [x[0], x[1], 0]), line: p.line }); continue; }
    const same = pkKey(p.entries) === pkKey(b.e) && p.minLv === b.minLv && p.maxLv === b.maxLv;
    if (same) { pkSame++; b.inPackageCsv = true; } else { pkDiff++; b.pkg = { minLv: p.minLv, maxLv: p.maxLv, e: p.entries, line: p.line }; }
  }
  // egg_box.csv: pet eggs (hatch = one pet item by relative weight)
  for (const [id, g] of EGG) {
    if (BOXES.has(id)) { const b = BOXES.get(id); b.egg = { e: g.e.map((x) => [x[0], 1, x[2]]), total: g.e.reduce((a, x) => a + x[2], 0) }; continue; }
    const W = toWeights(g.e.map((x) => x[2]), { forceWeights: true });
    BOXES.set(id, { src: 'egg_box', t: 'egg', k: 'egg', give: 1, take: 1, minLv: 0, maxLv: 0, msg: 0, e: g.e.map((x, i) => [x[0], 1, W.w[i]]), total: W.total, wmode: 'weights' });
  }
  // cash_randombox.csv: keyed treasure chests (itemchange_randombox Type 5 rows point here)
  for (const c of CRB) {
    let b = BOXES.get(c.index);
    if (!b) { b = { src: 'cash_randombox', t: 5, k: 'keyed', give: 1, take: 1, minLv: 0, maxLv: 0, msg: 0, e: [] }; BOXES.set(c.index, b); }
    if (b.k !== 'keyed') soft(`cash_randombox ${c.index}: box table Type ${b.t} is not 5`);
    const W = toWeights(c.entries.map((x) => x[2]), { denom: 1000000 });
    b.placeholder = b.e; // the single 0% entry of the Type 5 row (not used when the chest opens)
    b.e = c.entries.map((x, i) => [x[0], x[1], W.w[i]]); b.total = W.total; b.wmode = W.mode;
    b.notify = c.entries.map((x) => x[3]); b.keys = c.keys; b.keyCount = c.keyCount; b.give = 1; b.keyedLine = c.line;
    if (c.keyCount !== c.keys.length) soft(`cash_randombox ${c.index}: KeyCount ${c.keyCount} != ${c.keys.length} listed keys`);
  }
  for (const [id, b] of BOXES) if (b.k === 'keyed' && !b.keys) { b.noTable = true; soft(`box ${id} Type 5 without a cash_randombox row (noTable: the engine gives the listed entry)`); }
  for (const [id, x] of RBI) { const b = BOXES.get(id); if (b) b.info = x.showDigit; else soft(`randomboxinfo ${id}: not a box`); }
  for (const [id, x] of RBFX) { const b = BOXES.get(id); if (b) b.fx = x; else soft(`randomboxeffect ${id}: not a box`); }

  // ---------------------------------------------------------------- requirements, class-specific entries, existence
  const isItemEntryKind = (k) => !(k === 'itemset' || k === 'summon');
  const classMemo = new Map();
  function classesOf(id, depth = 0) {
    if (classMemo.has(id)) return classMemo.get(id);
    classMemo.set(id, null);
    const it = ITEMS.get(id); let res = null;
    if (it) {
      // 1) the item's own Job mask; 2) a class named in the item name ("... (Azure Knight)"): boxes carry the
      // all-classes mask but are made for one class; 3) for a box, the union of what every entry is limited to.
      if (it.job && it.job !== 0xffff) { const cl = maskToClasses(it.job); if (cl.length && cl.length < 15) res = cl; }
      if (!res) { const c = classFromName(it.n); if (c !== null) res = [c]; }
      if (!res && BOXES.has(id) && depth < 4 && isItemEntryKind(BOXES.get(id).k)) {
        const u = new Set(); let allSpecific = true;
        for (const [c] of BOXES.get(id).e) { const cl = classesOf(c, depth + 1); if (!cl) { allSpecific = false; break; } cl.forEach((x) => u.add(x)); }
        if (allSpecific && u.size && u.size < 15) res = [...u].sort((a, b) => a - b);
      }
    }
    classMemo.set(id, res);
    return res;
  }
  const missingRefs = { boxItem: [], entryItem: new Map(), itemSet: new Map(), monster: new Map(), key: new Map(), bonus: [] };
  const addMiss = (m, k, v) => { if (!m.has(k)) m.set(k, []); m.get(k).push(v); };
  for (const [id, b] of BOXES) {
    const it = ITEMS.get(id);
    b.itemLv = it ? it.lv : 0;
    b.lv = Math.max(b.itemLv || 0, b.minLv || 0);
    if (!it) { b.orphan = true; missingRefs.boxItem.push(id); }
    if (it && it.job && it.job !== 0xffff) b.job = maskToClasses(it.job);
    if (b.k === 'itemset') { for (const [s] of b.e) if (!ITEMSET.has(s)) addMiss(missingRefs.itemSet, s, id); }
    else if (b.k === 'summon') { for (const [m] of b.e) if (!(MONSTERS ? MONSTERS[m] : MONCSV.has(m))) addMiss(missingRefs.monster, m, id); }
    else {
      const miss = b.e.filter((x) => !ITEMS.has(x[0])).map((x) => x[0]);
      if (miss.length) { b.missing = [...new Set(miss)]; for (const m of b.missing) addMiss(missingRefs.entryItem, m, id); }
      const ec = b.e.map((x) => classesOf(x[0]));
      if (ec.some((x) => x)) b.ec = ec;
    }
    if (b.keys) for (const k of b.keys) if (!ITEMS.has(k)) addMiss(missingRefs.key, k, id);
    if (b.bonus && !ITEMS.has(b.bonus[0])) missingRefs.bonus.push(id);
  }

  // ---------------------------------------------------------------- level-up chains
  // gate(B) = max(item ReqLv, WminLevel).  A box that contains another box with a HIGHER gate unlocks it: the child
  // can only be opened once the character reaches that level.  Chains follow, from every root, the child with the
  // longest continuation.
  const gate = (id) => BOXES.get(id)?.lv ?? 0;
  const children = new Map(); const parents = new Map();
  for (const [id, b] of BOXES) {
    if (!isItemEntryKind(b.k) || b.orphan) continue;
    for (const [c] of b.e) {
      if (c === id || !BOXES.has(c) || BOXES.get(c).orphan) continue;
      if (gate(c) > gate(id)) {
        if (!children.has(id)) children.set(id, new Set()); children.get(id).add(c);
        if (!parents.has(c)) parents.set(c, new Set()); parents.get(c).add(id);
      }
    }
  }
  const longest = new Map();
  const L = (id, stack = new Set()) => {
    if (longest.has(id)) return longest.get(id);
    if (stack.has(id)) return 1; stack.add(id);
    let best = 1;
    for (const c of children.get(id) || []) best = Math.max(best, 1 + L(c, stack));
    stack.delete(id); longest.set(id, best); return best;
  };
  const nextOf = (id) => {
    let best = null;
    for (const c of children.get(id) || []) {
      if (!best || L(c) > L(best) || (L(c) === L(best) && (gate(c) < gate(best) || (gate(c) === gate(best) && c < best)))) best = c;
    }
    return best;
  };
  for (const [id, set] of children) { const b = BOXES.get(id); b.unlocks = [...set].sort((a, c) => gate(a) - gate(c) || a - c); b.next = nextOf(id); }
  // who hands out a root without a level gate (same-level packages, e.g. the D-Shop "Start-Up Package")
  const containedBy = new Map();
  for (const [id, b] of BOXES) if (isItemEntryKind(b.k)) for (const [c] of b.e) if (BOXES.has(c) && c !== id) { if (!containedBy.has(c)) containedBy.set(c, new Set()); containedBy.get(c).add(id); }
  const chains = [];
  for (const id of children.keys()) {
    if (parents.has(id)) continue;
    if (L(id) < 3) continue;
    const stages = []; let cur = id; const seen = new Set();
    while (cur && !seen.has(cur)) { seen.add(cur); stages.push(cur); cur = BOXES.get(cur).next; }
    chains.push({ root: id, name: itemName(id), length: stages.length, levels: stages.map(gate), stages,
      grantedBy: [...(containedBy.get(id) || [])].filter((p) => !parents.has(id) || !parents.get(id).has(p)).sort((a, b) => a - b) });
  }
  chains.sort((a, b) => b.length - a.length || a.root - b.root);
  for (const c of chains) for (let i = 1; i < c.stages.length; i++) if (!(c.levels[i] > c.levels[i - 1])) hard(`chain ${c.root}: level does not increase at ${c.stages[i]}`);

  // recommended new-character grant (no starter-kit table exists in the client; see docs/formats/boxes.md §4)
  const STARTER = [
    { item: 54389, count: 1, why: 'item literally named "New Character Gift Pack" (package: 7-day Growth Blessing, 7-day battle amulet, bound pet egg, 1000+1000 potion packages); nothing in the client grants it, so the server did at character creation' },
    { item: 1195439, count: 1, why: 'root of the newest and longest level-up box chain ("N Level Achievement Package": 5,10,20,...,195; 30 stages); nothing in the client contains it, it is the only root that starts below level 10, and the newer "Update New/Return" packages hand out its level-10 stage' },
  ];
  for (const s of STARTER) { if (!ITEMS.has(s.item)) hard(`starter item ${s.item} missing`); if (!BOXES.has(s.item)) hard(`starter item ${s.item} is not a box`); s.name = itemName(s.item); }
  const starterChain = chains.find((c) => c.root === 1195439);
  if (!starterChain) hard('the Level Achievement chain rooted at 1195439 was not found');

  // ---------------------------------------------------------------- side tables that feed boxes / rewards
  // premium service items (Growth Blessing, Holy Water of Almighty ...), used from boxes
  src('premiereItem', 'share/item/premiereitem.csv');
  const PREMIUM = {}; const premiumOdd = [];
  { const rows = parseCSV(readText('share/item/premiereitem.csv')); const h = rows[0].map((x) => x.trim());
    for (const r of rows.slice(1)) { if (!r || !isInt(r[0])) continue; const o = {}; h.forEach((k, j) => { if (j) o[k] = num(r[j]); });
      if (num(r[0]) === 0) { premiumOdd.push(o); continue; } PREMIUM[num(r[0])] = o; } }
  // accessory sealing (itemchange.csv): item -> sealed box item, SpendCount = Sealing Powder (see doc)
  src('itemChange', 'share/item/itemchange.csv');
  const SEALING = parseCSV(readText('share/item/itemchange.csv')).slice(1).filter((r) => r && isInt(r[0])).map((r) => [num(r[0]), num(r[1]), num(r[2])]);
  // connection-time / hunting / key-item rewards
  src('connectReward', 'share/support/connectreward/connectreward.csv');
  const CONNECT = parseCSV(readText('share/support/connectreward/connectreward.csv')).slice(1).filter((r) => r && isInt(r[0])).map((r) => {
    const n = num(r[2]); const steps = []; for (let k = 0; k < n; k++) steps.push([num(r[3 + 4 * k]), num(r[4 + 4 * k]), num(r[5 + 4 * k]), num(r[6 + 4 * k])]);
    return { index: num(r[0]), type: num(r[1]), kind: { 1: 'onlineTime', 2: 'huntTarget', 3: 'keyItem' }[num(r[1])] || null, steps };
  });
  src('attendList', 'share/support/attendancereward/attend_list.csv'); src('attendSet', 'share/support/attendancereward/attend_set.csv');
  const ATTEND = {
    sets: parseCSV(readText('share/support/attendancereward/attend_set.csv')).slice(1).filter((r) => r && isInt(r[0])).map((r) => ({ index: num(r[0]), start: num(r[1]), end: num(r[2]), startTime: num(r[3]), endTime: num(r[4]), enable: num(r[5]), count: num(r[6]), group: num(r[7]) })),
    days: parseCSV(readText('share/support/attendancereward/attend_list.csv')).slice(1).filter((r) => r && isInt(r[0])).map((r) => ({ group: num(r[0]), no: num(r[1]), type: num(r[2]), value: [num(r[3]), num(r[4])], item: num(r[5]), count: num(r[6]), raw: { rewardSize: num(r[7]), processFunc: num(r[8]) } })),
  };
  src('dekaPassReward', 'share/dekapass/dekapassreward.csv'); src('dekaPassConfig', 'share/dekapass/dekapassconfig.csv');
  const DEKAPASS = {
    config: Object.fromEntries(parseCSV(readText('share/dekapass/dekapassconfig.csv')).filter((r) => r && r[0] && String(r[0]).trim()).map((r) => [String(r[0]).trim(), num(r[1], String(r[1]).trim())])),
    rewards: parseCSV(readText('share/dekapass/dekapassreward.csv')).slice(1).filter((r) => r && isInt(r[0])).map((r) => ({ level: num(r[0]), basic: [num(r[1]), num(r[2])], premier: [num(r[3]), num(r[4])] })),
  };
  src('eventTime', 'share/event/event_time.csv');
  const EVENT_TIME = parseCSV(readText('share/event/event_time.csv')).slice(1).filter((r) => r && isInt(r[0])).map((r) => ({ used: num(r[0]), everySec: num(r[1]), item: num(r[2]), specialEvery: num(r[3]), specialItem: num(r[4]) }));
  src('fieldBossRoulette', 'share/supplymachine/fieldboss_supplymachine.csv');
  const ROULETTE = parseCSV(readText('share/supplymachine/fieldboss_supplymachine.csv')).slice(1).filter((r) => r && isInt(r[0])).map((r) => {
    const e = []; for (let k = 3; k + 3 < r.length + 1; k += 4) { if (!isInt(r[k])) continue; const it = num(r[k]); if (it) e.push([it, num(r[k + 3]), num(r[k + 2])]); }
    return { index: num(r[0]), pay: String(r[1]).split('/').map(num).filter(Boolean), payCount: num(r[2]), e, total: e.reduce((a, x) => a + x[2], 0) };
  });
  src('singleSupplyBase', 'share/supplymachine/single_supplymachine_base.csv'); src('singleSupplyDetails', 'share/supplymachine/single_supplymachine_details.csv');
  const SUPPLY = {
    grades: parseCSV(readText('share/supplymachine/single_supplymachine_base.csv')).slice(1).filter((r) => r && isInt(r[0])).map((r) => ({ grade: num(r[0]), min: num(r[1]), max: num(r[2]) })),
    items: parseCSV(readText('share/supplymachine/single_supplymachine_details.csv')).filter((r) => r && isInt(r[0]) && isInt(r[2])).map((r) => ({ no: num(r[0]), grade: num(r[1]), item: num(r[2]), registerRate: num(r[4]), winRate: num(r[5]), serverLimit: num(r[6]), count: num(r[7]) })),
  };
  src('supplyMachine', 'share/supplymachine/supplymachine.csv');
  const supplyEnabled = parseCSV(readText('share/supplymachine/supplymachine.csv')).slice(1).filter((r) => r && isInt(r[0]) && num(r[1])).length;
  // map treasure chests (trigger drops)
  src('triggerDrop', 'share/item/triggerdropitem.csv');
  const TREASURE = parseCSV(readText('share/item/triggerdropitem.csv')).slice(1).filter((r) => r && isInt(r[0])).map((r) => {
    let c = 4; const money = [];
    for (let k = 0; k < 10; k++, c += 5) { const v = r.slice(c, c + 5).map(num); if (v.some(Boolean)) money.push(v); }
    const setFunc = r[c++]; const maxSet = num(r[c++]); const sets = [];
    for (let k = 0; k < 15; k++, c += 3) { const v = r.slice(c, c + 3).map(num); if (v[0]) sets.push(v); }
    const fixFunc = r[c++]; const fix = [];
    for (let k = 0; k < 10; k++, c += 4) { const v = r.slice(c, c + 4).map(num); if (v[0]) fix.push(v); }
    const fixSetFunc = r[c++]; const fixSets = [];
    for (let k = 0; k < 10; k++, c += 5) { const v = r.slice(c, c + 5).map(num); if (v[0]) fixSets.push(v); }
    const setExFunc = r[c++]; const maxSetEx = num(r[c++]); const setsEx = [];
    for (let k = 0; k < 15; k++, c += 3) { const v = r.slice(c, c + 3).map(num); if (v[0]) setsEx.push(v); }
    const fixSetExFunc = r[c++]; const fixSetsEx = [];
    for (let k = 0; k < 10; k++, c += 5) { const v = r.slice(c, c + 5).map(num); if (v[0]) fixSetsEx.push(v); }
    return { map: num(r[0]), trigger: num(r[1]), name: String(r[2]).trim(), cond: String(r[3]).trim(), money, maxSet, sets, fix, fixSets, maxSetEx, setsEx, fixSetsEx,
      gainLimitTime: num(r[c]), dropRange: num(r[c + 1]), petPick: num(r[c + 2]), funcs: [setFunc, fixFunc, fixSetFunc, setExFunc, fixSetExFunc].map((x) => String(x).trim()) };
  });
  for (const t of TREASURE) if (!MAPS.has(t.map)) hard(`triggerdropitem: map ${t.map} not in maplist`);
  src('diceEffects', 'share/server/randomeffect.csv');
  const DICE = {};
  { const rows = parseCSV(readText('share/server/randomeffect.csv')).filter((r) => r && r[0]); const ids = rows[0].slice(1).map(num);
    ids.forEach((id, j) => { DICE[id] = rows.slice(1).map((r) => num(r[j + 1])); }); }

  // ---------------------------------------------------------------- where each box comes from (outside other boxes)
  // quests (raw quest_rewardlist.csv), the D-Shop and NPC shops/exchanges (gamedata/dshop.json + shops.json when the
  // shop builder has run), the reward tables above, drop item sets (itemset.csv / itemsetex.csv, used by monster and
  // map drops) and accessory sealing.  Informational: lets the engine / GM panel answer "how do I get this box".
  const GRANTS = new Map();
  const grant = (box, kind, v) => {
    if (!box || !BOXES.has(box)) return;
    if (!GRANTS.has(box)) GRANTS.set(box, {});
    const g = GRANTS.get(box); (g[kind] ||= []);
    if (!g[kind].some((x) => JSON.stringify(x) === JSON.stringify(v))) g[kind].push(v);
  };
  src('questReward', 'share/quest/quest_rewardlist.csv');
  let questRewardRows = 0;
  { const rows = parseCSV(readText('share/quest/quest_rewardlist.csv')); const h = rows[0].map((x) => x.trim()); const c = (n) => h.indexOf(n);
    for (const r of rows.slice(1)) {
      if (!r || !isInt(r[0])) continue; questRewardRows++;
      const cls = num(r[c('Class_Check')]) ? num(r[c('Class_Index')]) : null;
      for (let k = 1; k <= 10; k++) {
        const it = num(r[c(`Item_Index_${k}`)]);
        if (it) grant(it, 'quest', cls === null ? [num(r[0]), num(r[c(`Item_Count_${k}`)]), num(r[c('Level_Min')])] : [num(r[0]), num(r[c(`Item_Count_${k}`)]), num(r[c('Level_Min')]), cls]);
      }
    } }
  const readGameData = (name) => { const p = path.join(process.env.DEKARON_GAMEDATA || path.join(ENGINE, 'gamedata'), name); if (!fs.existsSync(p)) { soft(`gamedata/${name} not built yet: its box sources are skipped`); return null; } try { return JSON.parse(fs.readFileSync(p, 'utf8')); } catch (e) { soft(`gamedata/${name} unreadable: ${e.message}`); return null; } };
  const DSHOP = readGameData('dshop.json');
  if (DSHOP) {
    for (const [kind, list] of [['dshop', DSHOP.products], ['dshopLegacy', DSHOP.legacyProducts], ['vipShop', DSHOP.vipShop?.products]]) for (const p of list || []) for (const it of p.items || []) grant(it, kind, p.id);
  }
  const SHOPS = readGameData('shops.json');
  if (SHOPS) {
    for (const [s, v] of Object.entries(SHOPS.sets || {})) for (const x of v.items || []) grant(x[0], 'npcShopSet', +s);
    for (const [s, v] of Object.entries(SHOPS.exchanges || {})) for (const x of v.entries || []) grant(x[0], 'exchange', +s);
    for (const [s, v] of Object.entries(SHOPS.exchangeStores || {})) for (const x of v.entries || []) grant(x[0], 'exchangeStore', +s);
    for (const [s, v] of Object.entries(SHOPS.materialExchanges || {})) for (const x of v.entries || []) grant(x[0], 'materialExchange', +s);
  }
  CONNECT.forEach((c) => c.steps.forEach((s, i) => grant(s[2], 'connectReward', [c.index, i])));
  ATTEND.days.forEach((d) => grant(d.item, 'attendance', [d.group, d.no]));
  DEKAPASS.rewards.forEach((d) => { grant(d.basic[0], 'dekaPass', ['basic', d.level]); grant(d.premier[0], 'dekaPass', ['premier', d.level]); });
  EVENT_TIME.forEach((e) => { grant(e.item, 'eventTime', 'every'); grant(e.specialItem, 'eventTime', 'special'); });
  ROULETTE.forEach((r) => r.e.forEach((x) => grant(x[0], 'fieldBossRoulette', r.index)));
  SUPPLY.items.forEach((x) => grant(x.item, 'singleSupplyMachine', x.grade));
  TREASURE.forEach((t) => t.fix.forEach((x) => grant(x[0], 'mapTreasure', t.map)));
  for (const [s, v] of ITEMSET) for (const x of v.e) grant(x[0], 'dropItemSet', s);
  for (const [s, v] of ITEMSETEX) for (const gr of v.groups) for (const x of gr.e) grant(x[0], 'dropItemSetEx', s);
  SEALING.forEach(([acc, sealed]) => grant(sealed, 'sealing', acc));
  const grantedByOut = {};
  for (const id of [...GRANTS.keys()].sort((a, b) => a - b)) grantedByOut[id] = GRANTS.get(id);
  const grantKinds = {}; for (const g of GRANTS.values()) for (const k of Object.keys(g)) grantKinds[k] = (grantKinds[k] || 0) + 1;
  const insideOtherBox = new Set(containedBy.keys());
  const noSource = [...BOXES.keys()].filter((id) => !BOXES.get(id).orphan && !GRANTS.has(id) && !insideOtherBox.has(id));

  // ---------------------------------------------------------------- referenced item sets / monsters
  const setRefs = new Set(); const setExRefs = new Set(); const monRefs = new Set();
  for (const b of BOXES.values()) { if (b.k === 'itemset') b.e.forEach((x) => setRefs.add(x[0])); if (b.k === 'summon') b.e.forEach((x) => monRefs.add(x[0])); }
  for (const t of TREASURE) { t.sets.forEach((x) => setRefs.add(x[0])); t.fixSets.forEach((x) => setRefs.add(x[0])); t.setsEx.forEach((x) => setExRefs.add(x[0])); t.fixSetsEx.forEach((x) => setExRefs.add(x[0])); }
  const itemSetsOut = {}; for (const s of [...setRefs].sort((a, b) => a - b)) { const v = ITEMSET.get(s); if (v) itemSetsOut[s] = v; else hard(`item set ${s} referenced but missing from itemset.csv`); }
  const itemSetsExOut = {}; for (const s of [...setExRefs].sort((a, b) => a - b)) { const v = ITEMSETEX.get(s); if (v) itemSetsExOut[s] = v; else hard(`item set ex ${s} referenced but missing from itemsetex.csv`); }
  const summonsOut = {};
  for (const m of [...monRefs].sort((a, b) => a - b)) {
    const x = MONSTERS ? MONSTERS[m] : null; const c = MONCSV.get(m);
    summonsOut[m] = x ? { n: x.name, lv: x.level, shape: x.shape, role: x.role ?? null, inMonstersJson: true } : c ? { n: c.n, lv: c.lv, inMonstersJson: false } : null;
  }

  // ---------------------------------------------------------------- item stubs for every referenced item
  const refItems = new Set();
  const ref = (i) => { if (i && ITEMS.has(i)) refItems.add(i); };
  for (const [id, b] of BOXES) {
    ref(id);
    if (isItemEntryKind(b.k)) b.e.forEach((x) => ref(x[0]));
    if (b.egg) b.egg.e.forEach((x) => ref(x[0]));
    if (b.placeholder) b.placeholder.forEach((x) => ref(x[0]));
    if (b.pkg) b.pkg.e.forEach((x) => ref(x[0]));
    if (b.keys) b.keys.forEach(ref); if (b.bonus) ref(b.bonus[0]);
  }
  for (const s of Object.values(itemSetsOut)) s.e.forEach((x) => ref(x[0]));
  for (const s of Object.values(itemSetsExOut)) s.groups.forEach((g) => g.e.forEach((x) => ref(x[0])));
  Object.keys(PREMIUM).forEach((i) => ref(+i)); SEALING.forEach((x) => { ref(x[0]); ref(x[1]); });
  CONNECT.forEach((c) => c.steps.forEach((s) => { ref(s[2]); if (c.type === 3) ref(s[0]); }));
  ATTEND.days.forEach((d) => ref(d.item)); DEKAPASS.rewards.forEach((d) => { ref(d.basic[0]); ref(d.premier[0]); });
  EVENT_TIME.forEach((e) => { ref(e.item); ref(e.specialItem); }); ROULETTE.forEach((r) => { r.pay.forEach(ref); r.e.forEach((x) => ref(x[0])); });
  SUPPLY.items.forEach((x) => ref(x.item)); TREASURE.forEach((t) => t.fix.forEach((x) => ref(x[0]))); Object.keys(DICE).forEach((i) => ref(+i));
  const itemsOut = {};
  const ITEM_FIELDS = ['name', 'type', 'code', 'reqLv', 'jobMask', 'periodSec', 'stack', 'w', 'h', 'shape', 'desc'];
  const descRefs = new Set();
  for (const i of [...refItems].sort((a, b) => a - b)) {
    const it = ITEMS.get(i);
    itemsOut[i] = [it.n, it.t, it.c, it.lv, it.job, it.period, it.stack, it.w, it.h, it.shape, it.desc];
    if (BOXES.has(i) && it.desc) descRefs.add(it.desc);
  }
  const descsOut = {}; let descMissing = 0;
  for (const d of [...descRefs].sort((a, b) => a - b)) { const s = strItem.get(`20:${d}`); if (s !== undefined) descsOut[d] = s; else descMissing++; }
  if (descMissing) soft(`${descMissing} box description codes not in stringtable_item cate 20`);

  // ---------------------------------------------------------------- UI (windows + strings the box system uses)
  const UI_WINDOWS = {
    select: 'script/ui/game2/ui_new_randomboxwnd.txt', selectOld: 'script/ui/game2/ui_randomboxwnd.txt',
    keyedChest: 'script/ui/game2/randombox/ui_cashrandomboxwnd_renew.txt', keyedChestOld: 'script/ui/game2/ui_cashrandomboxwnd.txt',
    probabilityInfo: 'script/ui/game2/notice/ui_randomboxinfownd.txt', preview: 'script/ui/game2/previewboxinfo/ui_previewboxinfownd.txt',
    dshopBoxConfirm: 'script/ui/game2/cashshop/ui_boxconfirmwnd.txt', dshopBoxInfo: 'script/ui/game2/cashshop/ui_cashshopboxinfownd.txt',
    connectReward: 'script/ui/game2/connectreward/ui_new_connectrewardwnd.txt', growthBlessing: 'script/ui/game2/growbless/growbless.txt',
  };
  const uiOut = { windows: {}, strings: {} };
  for (const [k, rel] of Object.entries(UI_WINDOWS)) { const key = dataKeyOf(rel); if (!key) hard(`ui window ${rel} missing`); uiOut.windows[k] = key; }
  const needStr = { selectHeader: [strRbi, '600:1'], distributeHeader: [strRbi, '600:2'], summonHeader: [strRbi, '600:3'],
    packageOpenTitle: [strMsg, '80:65'], packageOpenWarning: [strMsg, '81:65'], inventoryFullOnOpen: [strNotice, '1002:67'] };
  for (const [k, [tbl, key]] of Object.entries(needStr)) { const s = tbl.get(key); if (s === undefined) hard(`string ${key} (${k}) missing`); uiOut.strings[k] = { key, text: s ?? null }; }
  uiOut.stringFiles = { randomBoxInfo: SRC.stringRandomBoxInfo, messageBox: SRC.stringMessageBox, notice: SRC.stringNotice, item: SRC.stringItem, connectReward: SRC.stringConnectReward };

  // ---------------------------------------------------------------- serialise boxes (compact, stable key order)
  const boxesOut = {};
  const ORDER = ['n', 'k', 't', 'lv', 'itemLv', 'minLv', 'maxLv', 'job', 'give', 'take', 'total', 'wmode', 'e', 'ec', 'keys', 'keyCount', 'notify', 'bonus', 'egg',
    'placeholder', 'noTable', 'pkg', 'next', 'unlocks', 'period', 'd', 'info', 'fx', 'msg', 'missing', 'orphan', 'inPackageCsv', 'src', 'line', 'keyedLine', 'raw'];
  let entryCount = 0;
  for (const id of [...BOXES.keys()].sort((a, b) => a - b)) {
    const b = BOXES.get(id); const it = ITEMS.get(id);
    b.n = it ? it.n : null; if (it && it.period) b.period = it.period; if (it && it.desc) b.d = it.desc;
    entryCount += b.e.length;
    const o = {};
    for (const k of ORDER) {
      const v = b[k];
      if (v === undefined || v === null || v === false) continue;
      if ((k === 'minLv' || k === 'maxLv' || k === 'msg' || k === 'itemLv') && !v) continue;
      if (k === 'take' && v === 1) continue;
      o[k] = v;
    }
    boxesOut[id] = o;
  }

  // ---------------------------------------------------------------- spot checks straight against the raw csv text
  const rawLine = (rel, id) => { const t = readText(rel).split(/\r?\n/); const l = t.find((x) => x.startsWith(`${id},`)); return l ? l.split(',') : null; };
  const SPOT = [1195439, 1195440, 1194542, 1755620, 2313312, 1191963, 47000, 1755570, 54359, 6900];
  const spot = [];
  for (const id of SPOT) {
    const b = boxesOut[id]; const r = rawLine('share/item/itemchange_randombox.csv', id);
    if (!b || !r) { hard(`spot ${id}: missing (${!b ? 'json' : 'csv'})`); continue; }
    const n = num(r[10]); const errs = [];
    if (num(r[1]) !== b.t) errs.push(`Type ${r[1]} vs ${b.t}`);
    if (num(r[7]) !== b.give && b.k !== 'keyed') errs.push(`GiveItemCount ${r[7]} vs ${b.give}`);
    if (num(r[2]) !== (b.minLv || 0)) errs.push(`WminLevel ${r[2]} vs ${b.minLv || 0}`);
    const E = b.k === 'keyed' ? b.placeholder : b.e;
    if (n !== E.length) errs.push(`listCount ${n} vs ${E.length}`);
    let cum = 0;
    for (let k = 0; k < Math.min(n, E.length); k++) {
      if (num(r[11 + 3 * k]) !== E[k][0] || num(r[12 + 3 * k]) !== E[k][1]) errs.push(`entry ${k}: ${r[11 + 3 * k]}x${r[12 + 3 * k]} vs ${E[k][0]}x${E[k][1]}`);
      if (b.wmode === 'cumulative' && b.k !== 'keyed') { cum += E[k][2]; if (cum !== num(r[13 + 3 * k])) errs.push(`entry ${k}: cumulative ${r[13 + 3 * k]} vs rebuilt ${cum}`); }
    }
    if (b.k === 'keyed') {
      const c = rawLine('share/premiere/cash_randombox.csv', id); let cc = 0;
      if (!c) errs.push('no cash_randombox line');
      else for (let k = 0; k < b.e.length; k++) { cc += b.e[k][2]; if (num(c[9 + 4 * k]) !== b.e[k][0] || num(c[11 + 4 * k]) !== cc) errs.push(`keyed entry ${k}`); }
    }
    if (errs.length) hard(`spot ${id}: ${errs.join('; ')}`);
    spot.push({ box: id, name: b.n, kind: b.k, lv: b.lv, entries: b.e.length, ok: !errs.length });
  }
  // itempackage / egg spot checks
  { const r = rawLine('share/item/itempackage.csv', 1191963); const b = boxesOut[1191963];
    const pe = b.pkg ? b.pkg.e : b.e; const ok = r && num(r[1]) === 50 && num(r[3]) === pe.length && pe.every((x, k) => num(r[4 + 2 * k]) === x[0] && num(r[5 + 2 * k]) === x[1]);
    if (!ok) hard('spot itempackage 1191963 mismatch'); spot.push({ box: 1191963, source: 'itempackage.csv', ok: !!ok }); }
  { const t = readText('share/item/egg_box.csv').split(/\r?\n/).filter((l) => l.startsWith('1751315,')).map((l) => l.split(','));
    const b = boxesOut[1751315]; const ok = b && t.length === b.e.length && t.every((r, k) => num(r[1]) === b.e[k][0] && num(r[2]) === b.e[k][2]);
    if (!ok) hard('spot egg_box 1751315 mismatch'); spot.push({ box: 1751315, source: 'egg_box.csv', ok: !!ok }); }

  // ---------------------------------------------------------------- report
  const kinds = {}; for (const b of Object.values(boxesOut)) kinds[b.k] = (kinds[b.k] || 0) + 1;
  const topMiss = (m) => [...m].slice(0, 40).map(([k, v]) => [k, v.slice(0, 5)]);
  const REPORT = {
    counts: { items: ITEMS.size, itemsReferenced: Object.keys(itemsOut).length, boxes: Object.keys(boxesOut).length, entries: entryCount, kinds,
      randomBoxRows: RB.length, randomBoxTypes: typeCounts, itemPackageRows: PK.length, itemPackageOnly: pkOnly, itemPackageSame: pkSame, itemPackageDiffers: pkDiff,
      eggBoxes: EGG.size, keyedChests: CRB.length, levelUpChains: chains.length, itemSets: Object.keys(itemSetsOut).length, itemSetsEx: Object.keys(itemSetsExOut).length,
      summonTargets: Object.keys(summonsOut).length, premiumItems: Object.keys(PREMIUM).length, sealing: SEALING.length, descs: Object.keys(descsOut).length },
    columns: { dropFieldNonZero: rawCounts.dropFieldNonZero, rowsWithTrailingData: rawCounts.trailingData, packageGiveMismatch: rawCounts.giveMismatchPackage, entriesWithCount0: rawCounts.countZero },
    missing: {
      boxItemsNotInClient: missingRefs.boxItem.length, boxItemsNotInClientSample: missingRefs.boxItem.slice(0, 40),
      entryItems: missingRefs.entryItem.size, entryItemRefs: [...missingRefs.entryItem.values()].reduce((a, v) => a + v.length, 0), entryItemSample: topMiss(missingRefs.entryItem),
      itemSets: topMiss(missingRefs.itemSet), monsters: topMiss(missingRefs.monster), keys: topMiss(missingRefs.key), bonus: missingRefs.bonus,
    },
    reachableBoxes: Object.values(boxesOut).filter((b) => !b.orphan).length,
    grants: { questRewardRows, boxesWithExternalSource: GRANTS.size, byKind: grantKinds, boxesOnlyInsideOtherBoxes: [...insideOtherBox].filter((id) => !GRANTS.has(id) && BOXES.has(id) && !BOXES.get(id).orphan).length,
      boxesWithNoSource: noSource.length, boxesWithNoSourceSample: noSource.slice(0, 40), dshopJson: !!DSHOP, shopsJson: !!SHOPS },
    koreanOnlyNames: Object.values(itemsOut).filter((x) => x[0] && /[가-힣]/.test(x[0])).length,
    supplyMachinesEnabled: supplyEnabled, premiumRowsWithoutItem: premiumOdd,
    spotChecks: spot,
  };

  const out = {
    format: 'dekaron-solo/boxes@1', generatedBy: 'tools/build-boxes.mjs', doc: 'docs/formats/boxes.md', sources: SRC,
    classes: CLASS_NAMES,
    kinds: {
      select: 'Type 0, give < entries: the player picks `give` different entries (Ex-Box / selection box)',
      all: 'Type 0, give >= entries: every entry is given',
      package: 'Type 8 (and itempackage-only rows): every entry is given',
      random: 'Type 1: `give` independent rolls, entry weight w out of `total` (remainder = empty roll)',
      itemset: 'Type 2: one roll picks an item set (itemSets) by w/`total`, then one item of that set; plus `bonus` every time',
      summon: 'Type 4: one roll picks a MONSTER index (summons) by w/`total`; it is spawned next to the player and drops its loot',
      keyed: 'Type 5 / cash_randombox.csv: needs one of `keys` (consumed); one roll by w/`total` (1 000 000); notify[i] = broadcast type',
      egg: 'egg_box.csv pet egg: one pet item by relative weight w/`total`',
    },
    entryFields: ['item (or item-set index for itemset, monster index for summon)', 'count', 'weight (0 = not random)'],
    itemFields: ITEM_FIELDS,
    itemDatLayout: { recordBytes: ITEM_DAT_RECORD, fields: ITEM_DAT_FIELDS },
    starter: { onCreate: STARTER, levelUpChain: starterChain ? starterChain.root : null, confidence: 'inferred (no starter-kit table in the client)' },
    levelUpChains: chains,
    boxes: boxesOut,
    grantedBy: grantedByOut,
    itemSets: itemSetsOut, itemSetsEx: itemSetsExOut, summons: summonsOut,
    items: itemsOut, descs: descsOut,
    premium: PREMIUM, sealing: SEALING, connectReward: CONNECT, attendance: ATTEND, dekaPass: DEKAPASS, eventTime: EVENT_TIME,
    fieldBossRoulette: ROULETTE, singleSupplyMachine: SUPPLY, mapTreasureBoxes: TREASURE, diceEffects: DICE,
    ui: uiOut,
    report: REPORT,
  };

  // every emitted data key exists
  const keys = [...Object.values(SRC), ...Object.values(uiOut.windows), ...Object.values(uiOut.stringFiles)];
  for (const k of keys) { if (!k || k !== k.toLowerCase() || !existsRel(k)) hard(`emitted data key invalid: ${k}`); }

  fs.mkdirSync(OUTDIR, { recursive: true });
  const s = PRETTY ? JSON.stringify(out, null, 1) : JSON.stringify(out);
  const p = path.join(OUTDIR, 'boxes.json');
  fs.writeFileSync(p, s);
  log(`wrote ${path.relative(ENGINE, p)} (${(s.length / 1024 / 1024).toFixed(2)} MiB)`);
  log(`boxes ${REPORT.counts.boxes} (${JSON.stringify(kinds)}), entries ${entryCount}, reachable ${REPORT.reachableBoxes}, chains ${chains.length}, items referenced ${REPORT.counts.itemsReferenced}`);
  log(`itempackage: ${pkSame} identical to the box table, ${pkDiff} differ (kept as pkg), ${pkOnly} only in itempackage`);
  log(`missing: ${missingRefs.boxItem.length} box items not defined in this client, ${missingRefs.entryItem.size} distinct entry items (${REPORT.missing.entryItemRefs} refs), ${missingRefs.itemSet.size} item sets, ${missingRefs.monster.size} monsters, ${missingRefs.key.size} keys`);
  log(`starter: ${STARTER.map((x) => `${x.item} ${x.name}`).join(' + ')}; chain ${starterChain ? starterChain.levels.join('>') : '-'}`);
  log(`grants: ${GRANTS.size} boxes have an external source ${JSON.stringify(grantKinds)}; ${REPORT.grants.boxesOnlyInsideOtherBoxes} only come from other boxes; ${noSource.length} have no source in the client (GM/server only)`);
  log(`spot checks: ${spot.filter((x) => x.ok).length}/${spot.length} ok`);
  log('');
  log(`soft issues: ${problems.soft.length}`);
  for (const x of problems.soft.slice(0, 20)) log(`  - ${x}`);
  if (problems.soft.length > 20) log(`  ... ${problems.soft.length - 20} more`);
  log(`HARD failures: ${problems.hard.length}`);
  for (const x of problems.hard.slice(0, 40)) log(`  ! ${x}`);
  log(`done in ${((Date.now() - t0) / 1000).toFixed(1)} s`);
  process.exitCode = problems.hard.length ? 1 : 0;
}

if (process.argv[1] && path.resolve(process.argv[1]) === fileURLToPath(import.meta.url)) main();
