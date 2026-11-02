#!/usr/bin/env node
// Dekaron Solo - NPC shop + D-Shop (cash shop) database builder.
//
//   node tools/build-shops.mjs [--data <unpacked data root>] [--out <dir>] [--pretty] [--quiet] [--spot]
//
// Reads the user's own unpacked client (default: ../data/unpacked/data next to the engine) and writes
//   gamedata/shops.json   NPC shops: shop.csv tabs -> shopset.csv grids, per-item prices (dil / points / items),
//                         exchange.csv, exchangestore.csv, materialupgrade.csv, which NPC opens what, where
//   gamedata/dshop.json   the D-Shop ("Deka Shop") cash shop: tabs, every product -> item variants with count,
//                         duration and D-Shop coin price, VIP (mileage) shop, packages, random boxes, premium
//                         services, purchase warnings, banner + UI sprites
// Every asset path in the output is a data key (lower case, '/' separated, relative to the data root; fetch it
// as /data/<key>) that was verified to exist on disk. The run doubles as the validation script: every table is
// parsed, every cross reference is checked (items, NPCs, maps, sets, strings, assets), a summary with counts +
// first failures is printed, and the exit code is 1 on hard failures. --spot prints 12 raw-vs-JSON spot checks.
// Format + field documentation: docs/formats/shops.md
//
// The parse* functions are pure (string / ArrayBuffer in, plain objects out) so they can move to src/formats/.

import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { BinReader, parseCSV, toArrayBuffer, stripBOM } from '../src/formats/binreader.js';

// ------------------------------------------------------------------------------------------------
// script/lines_eu - localisation database (UTF-16LE); same layout as tools/build-monsters.mjs parseLinesEu
//   u32 nTxt  { u32 len, wchar name[len], u32 n, n x (i32,i32) }        txt string files
//   u32 nCsv  { u32 len, wchar name[len], u32 n, n x (i32 col,i32 -1) } localised csv tables/columns
//   u32 nStr  { u32 id, u32 len, wchar text[len] }                       the strings
//   u32 nKeyT { u32 len, wchar key[len], u32 id }                        txt keys
//   u32 nKeyC { u32 len, wchar key[len] ("item#itemcash.csv#1|9420" = file#column|row), u32 id }
// ------------------------------------------------------------------------------------------------
export function parseLinesEu(buf, { keyFilter = null } = {}) {
  const r = new BinReader(buf);
  const dec = new TextDecoder('utf-16le');
  const wstr = (n) => dec.decode(r.bytes(n * 2));
  const readIndex = () => {
    const n = r.u32(); const files = [];
    for (let i = 0; i < n; i++) { const name = wstr(r.u32()); const c = r.u32(); const cols = []; for (let k = 0; k < c; k++) cols.push([r.i32(), r.i32()]); files.push({ name, cols }); }
    return files;
  };
  const txtFiles = readIndex();
  const csvFiles = readIndex();
  const nStr = r.u32();
  const strings = new Map();
  for (let i = 0; i < nStr; i++) { const id = r.u32(); strings.set(id, wstr(r.u32())); }
  const readKeys = (filter) => { const n = r.u32(); const m = new Map(); for (let i = 0; i < n; i++) { const k = wstr(r.u32()); const id = r.u32(); if (!filter || filter(k)) m.set(k, id); } return { count: n, map: m }; };
  const txtKeys = readKeys(() => false);
  const csvKeys = readKeys(keyFilter);
  return { txtFiles, csvFiles, strings, txtKeyCount: txtKeys.count, csvKeyCount: csvKeys.count, csvKeys: csvKeys.map, trailingBytes: r.remaining };
}

// ------------------------------------------------------------------------------------------------
// text helpers (pure)
// ------------------------------------------------------------------------------------------------
let krDecoder = null;
try { krDecoder = new TextDecoder('euc-kr'); } catch { krDecoder = new TextDecoder('latin1'); }
const utf16 = new TextDecoder('utf-16le');
/** Client text files are EUC-KR (ASCII for the English tables). */
export const decodeKr = (buf) => krDecoder.decode(stripBOM(buf instanceof Uint8Array ? buf : new Uint8Array(toArrayBuffer(buf))));   // a UTF-8 BOM (Global edit) must not become part of the first header cell
const num = (v, d = 0) => { const x = Number(String(v ?? '').trim()); return Number.isFinite(x) ? x : d; };
const str = (v) => String(v ?? '').trim();
const isInt = (v) => /^-?\d+$/.test(str(v));

/**
 * script/string/**.txt string table with categories:
 *   <cate> N [#comment]   code N [#comment]   {   text lines   }   </cate>
 * -> Map<cate, Map<code, text>> (a later duplicate code inside one cate wins; inner line breaks are kept).
 */
export function parseStringTables(text) {
  const out = new Map();
  let cate = -1, code = null, buf = null;
  for (const raw of String(text).split(/\r?\n/)) {
    const line = raw.replace(/\s+$/, '');
    if (buf) {
      if (line.trim() === '}') {
        while (buf.length && !buf[0].trim()) buf.shift();
        while (buf.length && !buf[buf.length - 1].trim()) buf.pop();
        if (!out.has(cate)) out.set(cate, new Map());
        if (code != null) out.get(cate).set(code, buf.join('\n'));
        buf = null; code = null;
      } else buf.push(line);
      continue;
    }
    let m;
    if ((m = /^\s*<cate>\s*(-?\d+)/i.exec(line))) { cate = Number(m[1]); continue; }
    if (/^\s*<\/cate>/i.test(line)) { cate = -1; continue; }
    if ((m = /^\s*code\s+(-?\d+)/i.exec(line))) { code = Number(m[1]); if (/\{\s*$/.test(line)) buf = []; continue; }
    if (line.trim() === '{' && code != null) buf = [];
  }
  return out;
}

/** script/ui/com/imagetable.txt -> Map<lowercase group, Map<index, {tex, x, y, w, h, nine?}>> (last duplicate wins). */
export function parseImageTable(text) {
  const out = new Map();
  for (const row of parseCSV(text)) {
    if (row.length < 7 || !isInt(row[1])) continue;
    const g = str(row[0]).toLowerCase();
    if (!out.has(g)) out.set(g, new Map());
    const e = { tex: str(row[2]), x: num(row[3]), y: num(row[4]), w: num(row[5]), h: num(row[6]) };
    const nine = row.slice(7, 11).map((v) => num(v));
    if (row.length >= 11 && nine.some(Boolean) && nine.every((v) => Number.isFinite(v))) e.nine = nine;
    out.get(g).set(num(row[1]), e);
  }
  return out;
}

/**
 * UI window script (script/ui/**.txt) -> flat control list [{id, type, depth, rect, text2:[cate,code]|null,
 * images:[{key, screen, index}]}] in file order (enough to recover tab buttons and their captions).
 */
export function parseUiControls(text) {
  const out = [];
  const stack = [];
  for (const raw of String(text).split(/\r?\n/)) {
    const line = raw.trim();
    let m;
    if ((m = /^<(\/?)([a-z0-9_]+)>$/i.exec(line))) {
      const tag = m[2].toLowerCase();
      if (!m[1]) {
        const node = { type: tag, depth: stack.length, id: null, rect: null, text2: null, images: [], _img: null };
        if (tag === 'image') { const parent = stack[stack.length - 1]; node._parent = parent; }
        stack.push(node);
        if (!['image', 'title', 'window'].includes(tag)) out.push(node);
      } else {
        const node = stack.pop();
        if (node && node.type === 'image' && node._parent) node._parent.images.push({ key: node.key ?? null, screen: node.screen ?? null, index: node.index ?? null });
      }
      continue;
    }
    const top = stack[stack.length - 1];
    if (!top || !line) continue;
    const kv = /^(\S+)\s+(.*)$/.exec(line);
    if (!kv) continue;
    const k = kv[1].toLowerCase(), v = kv[2].trim();
    const owner = top.type === 'title' ? stack[stack.length - 2] : top;
    if (!owner) continue;
    if (top.type === 'image') { if (k === 'key') top.key = v; else if (k === 'screen') top.screen = v; else if (k === 'index') top.index = num(v); }
    else if (k === 'id' && owner.id == null) owner.id = v;
    else if (k === 'rect' && owner.rect == null && top.type !== 'title') owner.rect = v.split(/\s+/).map(Number);
    else if (k === 'text2' && owner.text2 == null) { const p = v.split(/\s+/).map(Number); owner.text2 = [p[0], p[1]]; }
  }
  for (const n of out) { delete n._img; delete n._parent; }
  return out;
}

// ------------------------------------------------------------------------------------------------
// share/item/item.dat - the client's compiled item table (84 020 fixed 565-byte records).
// Only the fields shops need are decoded here; offsets were matched against the item csvs by
// correlating every byte offset with every csv column (match counts in docs/formats/shops.md section 2).
// item.dat is newer than the shipped csvs (e.g. Health Potion: csv Price 500 / stack 100, dat 5 / 9999)
// and is what the client actually loads, so it is authoritative.
// ------------------------------------------------------------------------------------------------
export const ITEM_DAT_RECORD = 565;
export const ITEM_DAT_FIELDS = { // name: [offset, type]
  index: [128, 'u32'], nameKey: [204, 'w64'], rank: [137, 'u8'], type: [141, 'u8'], code: [145, 'u8'], quality: [155, 'u8'],
  shape: [163, 'u32'], trade: [186, 'u8'], reqLv: [190, 'u16'], price: [194, 'u32'], width: [202, 'u8'], height: [203, 'u8'],
  stack: [332, 'u16'], maxStack: [334, 'u16'], eventType: [367, 'u16'], belong: [370, 'u8'], reqGrade: [373, 'u8'],
  purchasePoint: [375, 'u16'], choiceLimit: [379, 'u8'], purchaseLimit: [380, 'u8'], pointLimit: [381, 'u8'],
  cashCost: [546, 'u32'], cashPeriod: [550, 'u32'], upgradeRate: [555, 'u8'], purchaseType: [556, 'u8'], purchaseLimitLv: [557, 'u8'],
};
/**
 * Index one or more compiled item tables with the 565-byte layout (share/item/item.dat and
 * share/item/itemevent/itemevent.dat): Map<itemIndex, {part, off}>; the first table wins on duplicates.
 */
export function indexItemDat(bufs) {
  const parts = [];
  const map = new Map();
  let dups = 0, records = 0;
  bufs.forEach((buf, p) => {
    const ab = toArrayBuffer(buf);
    if (ab.byteLength % ITEM_DAT_RECORD !== 0) throw new Error(`item table ${p}: size ${ab.byteLength} not a multiple of ${ITEM_DAT_RECORD}`);
    const dv = new DataView(ab);
    parts.push({ dv, u8: new Uint8Array(ab), records: ab.byteLength / ITEM_DAT_RECORD });
    records += ab.byteLength / ITEM_DAT_RECORD;
    for (let o = 0; o < ab.byteLength; o += ITEM_DAT_RECORD) { const i = dv.getUint32(o + 128, true); if (map.has(i)) { dups++; continue; } map.set(i, { part: p, off: o }); }
  });
  return { parts, map, records, dups };
}
/** Decode the shop-relevant fields of one item record ({part, off} from indexItemDat). */
export function readItemDat(dat, ref) {
  const { dv, u8 } = dat.parts[ref.part];
  const o = ref.off;
  const out = {};
  for (const [k, [off, t]] of Object.entries(ITEM_DAT_FIELDS)) {
    if (t === 'u8') out[k] = u8[o + off];
    else if (t === 'u16') out[k] = dv.getUint16(o + off, true);
    else if (t === 'u32') out[k] = dv.getUint32(o + off, true);
    else if (t === 'w64') { const s = utf16.decode(u8.subarray(o + off, o + off + 128)); const z = s.indexOf('\0'); out[k] = z < 0 ? s : s.slice(0, z); }
  }
  return out;
}

// ------------------------------------------------------------------------------------------------
// share/item/shop.csv - TRANSPOSED: row 0 = "Index,<shop>,<shop>...", one row per field, one column per shop.
//   SellRatio, MaxSellCost, TabCount, SupplyShop, then 5 x (Name_n, BuyRatio_n, SupplyPoint_n, SetIndex_n,
//   SetType_n, Number_n)
// ------------------------------------------------------------------------------------------------
export function parseShopCsv(text) {
  const rows = parseCSV(text).filter((r) => r.length > 1);
  const ids = rows[0].slice(1).map(num);
  const field = new Map(rows.slice(1).map((r) => [str(r[0]), r.slice(1)]));
  const known = new Set(['SellRatio', 'MaxSellCost', 'TabCount', 'SupplyShop']);
  const shops = [];
  ids.forEach((id, c) => {
    const g = (name) => (field.has(name) ? field.get(name)[c] : undefined);
    const tabs = [];
    for (let t = 1; t <= 5; t++) {
      for (const f of ['Name', 'BuyRatio', 'SupplyPoint', 'SetIndex', 'SetType', 'Number']) known.add(`${f}_${t}`);
      tabs.push({ tab: t, name: num(g(`Name_${t}`)), buyRatio: num(g(`BuyRatio_${t}`)), supplyPoint: num(g(`SupplyPoint_${t}`)),
        set: num(g(`SetIndex_${t}`)), setType: str(g(`SetType_${t}`)), number: num(g(`Number_${t}`)) });
    }
    const raw = {};
    for (const [k, v] of field) if (!known.has(k)) raw[k] = v[c];
    shops.push({ index: id, sellRatio: num(g('SellRatio')), maxSellCost: num(g('MaxSellCost')), tabCount: num(g('TabCount')),
      supplyShop: num(g('SupplyShop')), tabs, raw: Object.keys(raw).length ? raw : undefined });
  });
  return { fields: rows.slice(1).map((r) => str(r[0])), shops };
}

// share/item/shopset.csv - TRANSPOSED: Index, Description, TotalCount, then n x (ItemIndex, StackCount, PosX, PosY)
export function parseShopSetCsv(text) {
  const rows = parseCSV(text).filter((r) => r.length > 1);
  const ids = rows[0].slice(1).map(num);
  const desc = rows[1].slice(1), total = rows[2].slice(1);
  const slots = [];
  for (let r = 3; r + 3 < rows.length + 1; r += 4) {
    if (!rows[r] || str(rows[r][0]) !== 'ItemIndex') break;
    slots.push(r);
  }
  const sets = ids.map((id, c) => {
    const items = [];
    for (const r of slots) {
      const item = num(rows[r][c + 1]);
      if (!item) continue;
      items.push({ slot: (r - 3) / 4, item, stack: num(rows[r + 1][c + 1]), x: num(rows[r + 2][c + 1]), y: num(rows[r + 3][c + 1]) });
    }
    return { index: id, desc: str(desc[c]), totalCount: num(total[c]), items };
  });
  return { slotRows: slots.length, sets };
}

// share/item/exchange.csv - TRANSPOSED: Index, Description, TotalCount, PriceItemIndex, then n x
//   (ItemDescription, GiveItemIndex, GiveItemCount, TakeItemIndex, PriceCount)
export function parseExchangeCsv(text) {
  const rows = parseCSV(text).filter((r) => r.length > 1);
  const ids = rows[0].slice(1).map(num);
  const get = (label) => rows.find((r) => str(r[0]) === label);
  const desc = get('Description').slice(1), total = get('TotalCount').slice(1), price = get('PriceItemIndex').slice(1);
  const start = rows.findIndex((r) => str(r[0]) === 'ItemDescription');
  const out = ids.map((id, c) => {
    const entries = [];
    for (let r = start, k = 0; r + 4 < rows.length + 1 && rows[r] && str(rows[r][0]) === 'ItemDescription'; r += 5, k++) {
      const give = num(rows[r + 1][c + 1]);
      if (!give) continue;
      entries.push({ slot: k, row: r, desc: str(rows[r][c + 1]), give, giveCount: num(rows[r + 2][c + 1]), take: num(rows[r + 3][c + 1]), priceCount: num(rows[r + 4][c + 1]) });
    }
    // a price item may list alternatives "A/B" (bound / tradable variants of the same currency)
    const alts = str(price[c]).split('/').map(num).filter(Boolean);
    return { index: id, column: c + 1, desc: str(desc[c]), totalCount: num(total[c]), priceItem: alts[0] || 0, priceItemAlt: alts.slice(1), entries };
  });
  return out;
}

// ------------------------------------------------------------------------------------------------
// share/article/shoplist.dat - the store-search item taxonomy the client loads (player market, Middleman NPCs).
// Fixed 482-byte records (layout verified on all 24 149 records):
//   u16 index | 6 x u16 typeCode (level 1..6) | 6 x char[64] caption | 20 x u32 itemIndex | u16 depth | u16 itemCount
// depth = number of used levels (always equals the last non-zero typeCode position); items are front-packed.
// The file is shoplist_{accessory,armor,socket,waste,weapon}.csv concatenated in that order (same columns).
// ------------------------------------------------------------------------------------------------
export const SHOPLIST_RECORD = 482;
export function parseShopListDat(buf) {
  const ab = toArrayBuffer(buf);
  if (ab.byteLength % SHOPLIST_RECORD) throw new Error(`shoplist.dat: size ${ab.byteLength} not a multiple of ${SHOPLIST_RECORD}`);
  const dv = new DataView(ab), u8 = new Uint8Array(ab);
  const out = [];
  for (let o = 0; o < ab.byteLength; o += SHOPLIST_RECORD) {
    const types = [], names = [], items = [];
    for (let k = 0; k < 6; k++) types.push(dv.getUint16(o + 2 + 2 * k, true));
    for (let k = 0; k < 6; k++) { const s = u8.subarray(o + 14 + 64 * k, o + 78 + 64 * k); const z = s.indexOf(0); names.push(decodeKr(s.slice(0, z < 0 ? 64 : z)).trim()); }
    for (let k = 0; k < 20; k++) items.push(dv.getUint32(o + 398 + 4 * k, true));
    const itemCount = dv.getUint16(o + 480, true);
    out.push({ index: dv.getUint16(o, true), types, names, items: items.slice(0, itemCount), allItems: items, depth: dv.getUint16(o + 478, true), itemCount });
  }
  return out;
}

/** Plain header csv -> array of objects keyed by header (duplicate headers get _2, _3 suffixes). */
export function parseTable(text) {
  const rows = parseCSV(text);
  if (!rows.length) return { header: [], rows: [] };
  const seen = {};
  const header = rows[0].map((h) => { const k = str(h); seen[k] = (seen[k] || 0) + 1; return seen[k] > 1 ? `${k}_${seen[k]}` : k; });
  const out = [];
  rows.slice(1).forEach((r, i) => {
    if (!r.some((c) => str(c))) return;
    const o = { _row: i + 1 };
    header.forEach((h, k) => { o[h] = r[k]; });
    out.push(o);
  });
  return { header, rows: out };
}

// ------------------------------------------------------------------------------------------------
// builder
// ------------------------------------------------------------------------------------------------
const HERE = path.dirname(fileURLToPath(import.meta.url));
function parseArgs(argv) {
  const a = { data: path.resolve(HERE, '..', '..', 'data', 'unpacked', 'data'), out: path.resolve(HERE, '..', 'gamedata'), pretty: false, quiet: false, spot: false };
  for (let i = 2; i < argv.length; i++) {
    if (argv[i] === '--data') a.data = path.resolve(argv[++i]);
    else if (argv[i] === '--out') a.out = path.resolve(argv[++i]);
    else if (argv[i] === '--pretty') a.pretty = true;
    else if (argv[i] === '--quiet') a.quiet = true;
    else if (argv[i] === '--spot') a.spot = true;
  }
  return a;
}

export function build(opts) {
  const ROOT = opts.data;
  const hardFails = [], softWarns = [];
  const hard = (m) => hardFails.push(m);
  const soft = (m) => softWarns.push(m);
  const log = (...m) => { if (!opts.quiet) console.log(...m); };
  const abs = (key) => path.join(ROOT, ...key.split('/'));
  const existsKey = (key) => fs.existsSync(abs(key));
  const readKey = (key) => fs.readFileSync(abs(key));
  const readText = (key) => decodeKr(readKey(key));
  const sources = new Set();
  const src = (key) => { sources.add(key); return key; };

  // case-insensitive on-disk lookup for asset keys (Windows is case-insensitive; keys must be lower case)
  const dirCache = new Map();
  const listDir = (dirKey) => {
    if (!dirCache.has(dirKey)) { let names = []; try { names = fs.readdirSync(abs(dirKey)); } catch { /* missing */ } dirCache.set(dirKey, new Map(names.map((n) => [n.toLowerCase(), n]))); }
    return dirCache.get(dirKey);
  };
  const assetKey = (gamePath, rootDir = '') => {
    let k = String(gamePath || '').trim().replace(/\\/g, '/').replace(/\/{2,}/g, '/').replace(/^\/+/, '').toLowerCase();
    if (!k) return null;
    if (rootDir && !k.startsWith(rootDir + '/')) k = `${rootDir}/${k}`;
    const parts = k.split('/');
    let dir = '';
    for (let i = 0; i < parts.length; i++) {
      const listing = listDir(dir);
      if (!listing.has(parts[i])) return null;
      dir = dir ? `${dir}/${parts[i]}` : parts[i];
    }
    return k;
  };

  const uiKey = (k) => { const a = assetKey(k); if (!a) hard(`ui window ${k} missing`); else src(a); return a; };

  // ---------------- localisation ----------------
  const L = parseLinesEu(readKey(src('script/lines_eu')), { keyFilter: (k) => /^(item#|itemevent#|creature#npc\.csv|premiere#)/.test(k) });
  if (L.trailingBytes) hard(`lines_eu: ${L.trailingBytes} trailing bytes`);
  const loc = (key) => { const id = L.csvKeys.get(key); return id == null ? null : L.strings.get(id) ?? null; };
  const tables = {};
  const table = (key) => (tables[key] ??= parseStringTables(readText(src(key))));
  const tstr = (key, cate, code) => table(key).get(cate)?.get(code) ?? null;
  const T_STORE = 'script/string/normal/stringtable_store.txt';
  const T_TAB = 'script/string/normal/stringtable_storetab.txt';
  const T_EXCH = 'script/string/normal/stringtable_exchange.txt';
  const T_CASHSHOP = 'script/string/cash/stringtable_cashshop.txt';
  const T_CASHITEM = 'script/string/cash/stringtable_cashitem.txt';
  const T_CASH = 'script/string/cash/stringtable_cash.txt';
  const T_RBOX = 'script/string/cash/stringtable_randomboxinfo.txt';
  const T_TITLE = 'script/string/normal/stringtable_title.txt';
  const T_BUTTON = 'script/string/normal/stringtable_button.txt';
  const T_OPTION = 'script/string/normal/stringtable_option.txt';
  // script/string/list.txt loads string/Auction/stringtable_searchstore.txt (the normal/ copy is stale and lacks code 84 "Search")
  const T_SEARCH = 'script/string/auction/stringtable_searchstore.txt';
  const T_SUPPLY = 'script/string/normal/stringtable_supplymachine.txt';

  // ---------------- items (item.dat) ----------------
  const DAT_PARTS = ['share/item/item.dat', 'share/item/itemevent/itemevent.dat'];
  const dat = indexItemDat(DAT_PARTS.map((k) => readKey(src(k))));
  if (dat.dups) soft(`item tables: ${dat.dups} indices appear in both item.dat and itemevent.dat (item.dat wins)`);
  // csv name fallback (Korean/English) for items whose name key has no lines_eu string
  const csvNames = new Map();
  for (const f of ['itemweapon.csv', 'itemarmor.csv', 'itemetc.csv', 'itemaccessory.csv', 'itemetc_socket.csv', 'itemcash.csv',
    'itemevent/cashevent.csv', 'itemevent/etcevent.csv', 'itemevent/accessoryevent.csv']) {
    for (const r of parseCSV(readText(src(`share/item/${f}`))).slice(1)) if (isInt(r[0]) && !csvNames.has(num(r[0]))) csvNames.set(num(r[0]), str(r[1]));
  }
  // mileage (VIP shop) items live only in itemmileage.csv (indices 10000000+, not in item.dat)
  const mileage = parseTable(readText(src('share/item/itemmileage.csv')));
  const mileageItems = new Map();
  for (const r of mileage.rows) if (isInt(r.ItemIndex)) mileageItems.set(num(r.ItemIndex), r);

  const itemsOut = {};               // referenced items only
  const missingItems = new Map();    // index -> first referrer
  const iconMissing = new Set();
  let nameFromLines = 0, nameFromCsv = 0;
  // script/shape/item_shape.csv: ItemShape -> inventory/D-Shop model (the item "icon" is a small 3D model).
  //   cols: 0 Index, 1 game/mesh, 2 tpack, 3 effect, 4 effect_add, 5 inv/mesh, 6 tpack, 7 cashshop/belt/scale, 8 twoside, ...
  const shapeRows = new Map();
  for (const r of parseCSV(readText(src('script/shape/item_shape.csv'))).slice(1)) if (isInt(r[0])) shapeRows.set(num(r[0]), r);
  const iconCache = new Map();
  const propKey = (shape) => {
    if (!shape) return null;
    if (iconCache.has(shape)) return iconCache.get(shape);
    const r = shapeRows.get(shape);
    let icon = null;
    if (r) {
      const meshPath = str(r[5]) || str(r[1]);
      const mesh = assetKey(meshPath, 'mesh');
      let tpack = assetKey(str(r[6]) || str(r[2]), 'texturepack');
      if (!tpack && meshPath) tpack = assetKey(meshPath.replace(/\.mesh$/i, '.tpack'), 'texturepack');
      if (mesh) icon = [mesh, tpack, num(r[7], 1) || 1];
    }
    if (!icon) iconMissing.add(shape);
    iconCache.set(shape, icon);
    return icon;
  };
  function refItem(idx, from) {
    idx = num(idx);
    if (!idx) return null;
    if (itemsOut[idx]) return itemsOut[idx];
    const o = dat.map.get(idx);
    if (o === undefined) {
      const mr = mileageItems.get(idx);
      if (mr) {
        const name = loc(`item#itemmileage.csv#1|${mr._row}`) || str(mr.Name);
        const shape = num(mr.ItemShape);
        const it = { name, src: 'itemmileage.csv', type: num(mr.Type), code: num(mr.Code), rank: num(mr.Rank), quality: num(mr.Quality),
          shape, icon: propKey(shape), w: num(mr.Width), h: num(mr.Height), stack: num(mr.StackNumber), maxStack: num(mr.MaxStackNumber),
          reqLv: num(mr.ReqLv), vipCost: num(mr.DwCashItemCost), period: num(mr.CashItemUsePeriod), purchaseType: num(mr.PurchaseType),
          purchaseLimitLv: num(mr.PurchaseLimitLv), buyMinLevel: num(mr.BuyMinLevel), belong: num(mr.Belong), eventType: num(mr.EventType) };
        for (const k of Object.keys(it)) if (it[k] === 0 || it[k] === null || it[k] === '') delete it[k];
        it.name = name;
        return (itemsOut[idx] = it);
      }
      if (!missingItems.has(idx)) missingItems.set(idx, from);
      return null;
    }
    const d = readItemDat(dat, o);
    let name = loc(d.nameKey);
    if (name) nameFromLines++; else { name = csvNames.get(idx) || null; if (name) nameFromCsv++; }
    const it = { name: name ?? `#${idx}`, src: o.part ? 'itemevent.dat' : undefined, type: d.type, code: d.code, rank: d.rank, quality: d.quality, shape: d.shape, icon: propKey(d.shape),
      w: d.width, h: d.height, price: d.price, stack: d.stack, maxStack: d.maxStack, reqLv: d.reqLv, trade: d.trade, belong: d.belong,
      reqGrade: d.reqGrade, purchasePoint: d.purchasePoint, pointLimit: d.pointLimit, purchaseLimit: d.purchaseLimit, choiceLimit: d.choiceLimit,
      cash: d.cashCost, period: d.cashPeriod, purchaseType: d.purchaseType, purchaseLimitLv: d.purchaseLimitLv, eventType: d.eventType, upgradeRate: d.upgradeRate };
    for (const k of Object.keys(it)) if (it[k] === 0 || it[k] === null || it[k] === undefined) delete it[k];
    if (!name) it.nameMissing = true;
    return (itemsOut[idx] = it);
  }

  // ---------------- NPCs ----------------
  const npcCsv = parseTable(readText(src('share/creature/npc.csv')));
  const jobCfg = new Map();
  for (const r of parseTable(readText(src('share/creature/jobtypeconfig.csv'))).rows) {
    const m = /^([A-Z0-9_]+)/.exec(str(r.Description));
    jobCfg.set(num(r.Index), m ? m[1] : str(r.Description));
  }
  let npcsJson = null;
  const npcsJsonPath = path.join(opts.out, 'npcs.json');
  if (fs.existsSync(npcsJsonPath)) npcsJson = JSON.parse(fs.readFileSync(npcsJsonPath, 'utf8'));
  else soft('gamedata/npcs.json not found: NPC placements/maps omitted');
  const npcPlacements = new Map(); // npc -> [{map, mapName, x, y}]
  if (npcsJson) {
    for (const [mapIdx, p] of Object.entries(npcsJson.placements || {})) {
      for (const row of p.rows || []) {
        const n = row[0];
        if (!npcPlacements.has(n)) npcPlacements.set(n, []);
        npcPlacements.get(n).push({ map: num(mapIdx), mapName: p.name, x: row[1], y: row[2] });
      }
    }
  }
  const npcRows = new Map();
  for (const r of npcCsv.rows) if (isInt(r.Index)) npcRows.set(num(r.Index), r);
  const mapIndex = new Map();
  for (const r of parseTable(readText(src('share/maplist.csv'))).rows) if (isInt(r.Index)) mapIndex.set(num(r.Index), str(r.Name));
  // server-only map rows (north ares, norak, north morte: no client .map, NPC files still ship) count as known maps
  for (const r of parseTable(readText(src('share/server/maplist.csv'))).rows) if (isInt(r.MapIndex) && !mapIndex.has(num(r.MapIndex))) mapIndex.set(num(r.MapIndex), `server:${str(r.MapPath)}`);
  let badPlacementMaps = 0;
  for (const [n, pl] of npcPlacements) for (const p of pl) if (!mapIndex.has(p.map)) { badPlacementMaps++; if (badPlacementMaps <= 3) soft(`npc ${n} placed on map ${p.map} which is not in maplist.csv`); }
  const npcJobs = (r) => {
    const out = [];
    for (let k = 1; k <= 20; k++) { const t = num(r[`JobType${k}`]), i = num(r[`JobIndex${k}`]); if (t || i) out.push([t, i]); }
    return out.slice(0, Math.max(num(r.JobCount), out.filter(([t, i]) => t || i).length));
  };
  const npcName = (idx) => npcsJson?.npcs?.[idx]?.name || loc(`creature#npc.csv#1|${npcRows.get(idx)?._row}`) || str(npcRows.get(idx)?.Name) || `#${idx}`;

  // ---------------- NPC shop tables ----------------
  const shopParsed = parseShopCsv(readText(src('share/item/shop.csv')));
  const setParsed = parseShopSetCsv(readText(src('share/item/shopset.csv')));
  const exPrice = parseTable(readText(src('share/item/exchange_price.csv')));
  const shopExchange = parseTable(readText(src('share/item/shop_exchange.csv')));
  const exchanges = parseExchangeCsv(readText(src('share/item/exchange.csv')));
  const exStore = parseTable(readText(src('share/article/exchangestore.csv')));
  const sellPrice = parseTable(readText(src('share/item/itemsellprice.csv')));

  const SHOP_ROLES = { 0: 'SHOP', 33: 'SIEGE_SHOP', 43: 'SUPPLY_SHOP', 51: 'ARENA_SHOP', 83: 'EXCHANGE_SHOP', 102: 'MULTISHOP' };
  const OTHER_ROLES = { 35: 'EXCHANGE', 166: 'EXCHANGE_STORE', 168: 'EXCHANGE_MATERIAL', 164: 'EXCHANGE_RANKUP_EXP_COIN', 165: 'EXCHANGE_GOLDITEM', 101: 'SUPPLYMACHINE_GAMBLER',
    46: 'SEARCH_STORE' }; // 46 = the "Middleman" NPCs: player-shop search / consignment (-> gamedata/shops_search.json)
  for (const [t, n] of Object.entries({ ...SHOP_ROLES, ...OTHER_ROLES })) if (jobCfg.get(+t) !== n) hard(`jobtypeconfig.csv: JobType ${t} is "${jobCfg.get(+t)}", expected ${n}`);

  // who opens what
  const shopNpcs = new Map(), exchangeNpcs = new Map(), storeNpcs = new Map(), materialNpcs = new Map();
  const npcOut = {};
  const add = (m, k, v) => { if (!m.has(k)) m.set(k, new Set()); m.get(k).add(v); };
  for (const [idx, r] of npcRows) {
    const jobs = npcJobs(r);
    const rel = [];
    for (const [t, i] of jobs) {
      const role = SHOP_ROLES[t] || OTHER_ROLES[t];
      if (!role) continue;
      const e = { role, jobType: t, jobIndex: i };
      if (SHOP_ROLES[t]) { e.shop = i; add(shopNpcs, i, idx); }
      else if (t === 35) { e.exchange = i; add(exchangeNpcs, i, idx); }
      else if (t === 166) { e.store = i; add(storeNpcs, i, idx); }
      else if (t === 168) { e.material = i; add(materialNpcs, i, idx); }
      else if (t === 101) e.supplyMachine = true;   // -> shopsJson.supplyMachine
      else if (t === 46) e.searchStore = true;      // -> gamedata/shops_search.json
      else e.serverSide = true;                   // 164/165: coin / gold-bar exchange, no client table
      rel.push(e);
    }
    if (!rel.length) continue;
    const pl = npcPlacements.get(idx) || [];
    npcOut[idx] = { name: npcName(idx), jobs: rel, maps: [...new Set(pl.map((p) => p.map))] };
    if (pl.length) npcOut[idx].at = pl.map((p) => [p.map, p.x, p.y]);
    if (npcsJson && npcsJson.npcs && !npcsJson.npcs[idx]) soft(`npc ${idx} (shop role) missing from npcs.json`);
  }
  // npcs.json jobs must agree with npc.csv (same source, independent parse)
  if (npcsJson) {
    let agree = 0, disagree = 0;
    for (const [idx, r] of npcRows) {
      const a = JSON.stringify(npcJobs(r).filter(([t, i]) => t || i));
      const b = JSON.stringify(npcsJson.npcs?.[idx]?.jobs || []);
      if (a === b) agree++; else { disagree++; if (disagree <= 3) soft(`npc ${idx}: npc.csv jobs ${a} != npcs.json ${b}`); }
    }
    if (disagree) soft(`npc jobs: ${agree} agree, ${disagree} differ between npc.csv and npcs.json`);
  }

  // exchange price overrides: (set, item) -> [[needItem, count]...]
  const exCost = new Map();
  for (const r of exPrice.rows) {
    const need = [];
    for (let k = 0; k < 4; k++) { const it = num(r[`NeedItemIndex_${k}`]), c = num(r[`NeedItemCount_${k}`]); if (it) { need.push([it, c]); refItem(it, `exchange_price row ${r._row}`); } }
    if (need.length !== num(r.NeedCount)) soft(`exchange_price row ${r._row}: NeedCount ${r.NeedCount} but ${need.length} need items`);
    exCost.set(`${num(r.Shopset_Index)}:${num(r.ItemIndex)}`, { need, desc: str(r.Description), row: r._row, used: false });
  }
  const shopExCost = new Map();
  for (const r of shopExchange.rows) {
    const need = [];
    for (let k = 1; k <= 4; k++) { const it = num(r[`ITEMINDEX_${k}`]), c = num(r[`ITEMCOUNT_${k}`]); if (it) need.push([it, c]); }
    shopExCost.set(`${num(r.SHOPSET_INDEX)}:${num(r.ITEMINDEX)}`, { need, desc: str(r.DESCRIPTION), row: r._row, used: false });
  }

  // shops
  const shopsOut = {};
  const setUse = new Map(); // set -> [shop:tab]
  const shopKinds = (i) => [...new Set([...(shopNpcs.get(i) || [])].flatMap((n) => npcOut[n].jobs.filter((j) => j.shop === i).map((j) => j.role)))];
  const usedTabNames = new Set();
  for (const s of shopParsed.shops) {
    const tabs = [];
    // scan fix A (A7): the client's shop loader reads TabCount (column 3, FUN_010c64e0 @ decompiled-named.c 32-bit-main
    // L1586574) and its row parser FUN_010c68b0 (L1586652) loops tab groups only while index < TabCount (L1586793), so tab
    // groups past TabCount never reach the client (shops 40/61/91/92 have TabCount 1). Empty groups are skipped as before.
    const tabLimit = Number.isFinite(s.tabCount) ? s.tabCount : s.tabs.length;
    const beyond = s.tabs.slice(tabLimit).filter((t) => t.set || t.name);
    if (beyond.length) soft(`shop ${s.index}: TabCount ${s.tabCount} - ${beyond.length} filled tab group(s) past TabCount ignored as the client does (tabs ${beyond.map((t) => t.tab).join(',')})`);
    s.tabs.slice(0, tabLimit).forEach((t) => {
      if (!t.set && !t.name) return;
      if (t.set) { if (!setUse.has(t.set)) setUse.set(t.set, []); setUse.get(t.set).push(`${s.index}:${t.tab}`); }
      const nm = t.name ? tstr(T_TAB, 2002, t.name) : null;
      if (t.name) usedTabNames.add(t.name);
      if (t.name && !nm) soft(`shop ${s.index} tab ${t.tab}: tab name code ${t.name} not in stringtable_storetab`);
      const o = { name: nm ?? '', nameCode: t.name, set: t.set, buyRatio: t.buyRatio };
      if (t.supplyPoint) o.supplyPoint = t.supplyPoint;
      if (t.setType && t.setType !== '0') o.setType = t.setType;
      if (t.number) o.number = t.number;
      tabs.push(o);
    });
    if (tabs.length !== s.tabCount) soft(`shop ${s.index}: TabCount ${s.tabCount} but ${tabs.length} tabs filled`);
    const kinds = shopKinds(s.index);
    const npcs = [...(shopNpcs.get(s.index) || [])].sort((a, b) => a - b);
    const name = tstr(T_STORE, 341, s.index);
    const o = { name: name ?? '', kind: kinds.length === 1 ? kinds[0] : kinds.length ? kinds : null, sellRatio: s.sellRatio, maxSellCost: s.maxSellCost, tabs, npcs };
    if (s.supplyShop) o.supplyShop = s.supplyShop;
    if (s.raw) o.raw = s.raw;
    shopsOut[s.index] = o;
  }
  // premium "remote store" (premiereitem.csv StoreIndex) opens a shop too
  const premiere = parseTable(readText(src('share/item/premiereitem.csv')));
  const remoteStores = new Set(premiere.rows.map((r) => num(r.StoreIndex)).filter(Boolean));
  for (const i of remoteStores) { if (shopsOut[i]) shopsOut[i].remoteStore = true; else hard(`premiereitem StoreIndex ${i} is not a shop`); }
  for (const [i, n] of shopNpcs) if (!shopsOut[i]) hard(`npc(s) ${[...n].join(',')} open shop ${i} which is not in shop.csv`);

  // sets
  const setsOut = {};
  const GRID_COLS = 10, GRID_ROWS = 10; // ui_storewnd itemslot 327x358 at 33 px cells -> 10 columns; rows from the data
  let maxRow = 0, overlaps = 0, overlapsUnused = 0, outOfGrid = 0, setsUsed = 0, costItems = 0, pointItems = 0, dilItems = 0, freeItems = 0;
  for (const s of setParsed.sets) {
    const used = setUse.get(s.index) || [];
    if (used.length) setsUsed++;
    // scan fix A (A8): the client's ShopSet row parser FUN_010ceb10 (decompiled-named.c 32-bit-main L3249506) reads all 0x38
    // (56) ItemIndex/StackCount/PosX/PosY groups whatever TotalCount says, so every filled entry is kept; TotalCount is informational.
    if (s.totalCount !== s.items.length) soft(`shopset ${s.index}: TotalCount ${s.totalCount} but ${s.items.length} items`);
    const kinds = new Set(used.flatMap((u) => { const k = shopsOut[u.split(':')[0]]?.kind; return Array.isArray(k) ? k : k ? [k] : []; }));
    const occ = new Map();
    const items = [];
    const costs = {};
    const unpriced = [];
    for (const e of s.items) {
      const it = refItem(e.item, `shopset ${s.index}`);
      const w = it?.w || 1, h = it?.h || 1;
      if (e.x < 0 || e.x + w > GRID_COLS) outOfGrid++;
      maxRow = Math.max(maxRow, e.y + h);
      let hit = null;
      for (let yy = e.y; yy < e.y + h; yy++) for (let xx = e.x; xx < e.x + w; xx++) {
        const k = `${xx},${yy}`;
        if (occ.has(k)) hit = hit || `${occ.get(k)} at cell ${k}`; else occ.set(k, e.item);
      }
      if (hit) { if (used.length) { overlaps++; if (overlaps <= 5) soft(`shopset ${s.index} (used by ${used.join(',')}): item ${e.item} overlaps ${hit}`); } else overlapsUnused++; }
      items.push([e.item, e.stack, e.x, e.y]);
      const key = `${s.index}:${e.item}`;
      let pk;
      if (exCost.has(key)) { const c = exCost.get(key); c.used = true; costs[e.item] = c.need; pk = 'items'; }
      else if (shopExCost.has(key)) { const c = shopExCost.get(key); c.used = true; costs[e.item] = c.need; pk = 'items'; }
      else if (kinds.has('ARENA_SHOP') && it?.purchasePoint) pk = 'points';
      else if (it?.price) pk = 'dil';
      else { pk = 'none'; unpriced.push(e.item); }
      if (used.length) { if (pk === 'items') costItems++; else if (pk === 'points') pointItems++; else if (pk === 'dil') dilItems++; else freeItems++; }
    }
    const o = { desc: s.desc, items };
    if (Object.keys(costs).length) o.costs = costs;
    if (unpriced.length) o.unpriced = unpriced;
    if (used.length) o.usedBy = used;
    setsOut[s.index] = o;
  }
  for (const [set, u] of setUse) if (!setsOut[set]) hard(`shop tab(s) ${u.join(',')} use shopset ${set} which is not in shopset.csv`);
  const unusedExPrice = [...exCost.entries()].filter(([, v]) => !v.used);
  if (unusedExPrice.length) soft(`exchange_price: ${unusedExPrice.length} rows whose (Shopset_Index, ItemIndex) is not in shopset.csv, e.g. ${unusedExPrice.slice(0, 3).map(([k]) => k).join(' ')}`);
  const unusedShopEx = [...shopExCost.entries()].filter(([, v]) => !v.used);

  // exchanges (exchange.csv)
  const exchangesOut = {};
  for (const e of exchanges) {
    refItem(e.priceItem, `exchange ${e.index}`);
    for (const a of e.priceItemAlt) refItem(a, `exchange ${e.index}`);
    const nm = tstr(T_EXCH, 2006, e.index);
    const descEn = loc(`item#exchange.csv#${e.column}|1`) || e.desc;
    if (e.totalCount !== e.entries.length) soft(`exchange ${e.index}: TotalCount ${e.totalCount} but ${e.entries.length} entries`);
    exchangesOut[e.index] = {
      name: nm ?? `[Exchange Center] ${descEn}`, desc: descEn, priceItem: e.priceItem, ...(e.priceItemAlt.length ? { priceItemAlt: e.priceItemAlt } : {}),
      entries: e.entries.map((x) => { refItem(x.give, `exchange ${e.index}`); if (x.take) refItem(x.take, `exchange ${e.index}`); return [x.give, x.giveCount, x.priceCount, x.take]; }),
      npcs: [...(exchangeNpcs.get(e.index) || [])].sort((a, b) => a - b),
    };
  }
  // client data gap (not ours): npc 5989 "Bella" lists EXCHANGE 538, which exchange.csv does not define
  for (const [i, n] of exchangeNpcs) if (!exchangesOut[i]) soft(`npc(s) ${[...n].join(',')} open exchange ${i} which is not in exchange.csv (client data)`);

  // exchange stores (share/article/exchangestore.csv)
  const storesOut = {};
  for (const r of exStore.rows) {
    const t = num(r.StoreType);
    if (!storesOut[t]) storesOut[t] = { entries: [], npcs: [...(storeNpcs.get(t) || [])].sort((a, b) => a - b) };
    // NeedItemIndex may list alternatives "A/B" (either pays): entry[1] = A, entry[6] = [B...] when present
    const need = str(r.NeedItemIndex).split('/').map(num).filter(Boolean);
    if (!need.length) hard(`exchangestore row ${r._row}: no need item`);
    refItem(r.ItemIndex, `exchangestore row ${r._row}`);
    for (const n of need) refItem(n, `exchangestore row ${r._row}`);
    const e = [num(r.ItemIndex), need[0] || 0, num(r.NeedItemCount), num(r.RetunItemCount), num(r.LimitCount), num(r.Season)];
    if (need.length > 1) e.push(need.slice(1));
    storesOut[t].entries.push(e);
  }
  for (const [i, n] of storeNpcs) if (!storesOut[i]) soft(`npc(s) ${[...n].join(',')} open exchange store ${i} which has no rows in exchangestore.csv`);
  // a store has no name string; the NPC line "[Exchange] use the %s Exchange." is filled with its currency item (inferred)
  for (const st of Object.values(storesOut)) {
    const c = {};
    for (const e of st.entries) c[e[1]] = (c[e[1]] || 0) + 1;
    const cur = +Object.entries(c).sort((a, b) => b[1] - a[1])[0][0];
    st.currency = cur;
    st.name = itemsOut[cur]?.name ?? `#${cur}`;
  }

  // material exchange (share/item/materialupgrade.csv; Korean headers, positional)
  const matOut = {};
  for (const r of parseCSV(readText(src('share/item/materialupgrade.csv'))).slice(1)) {
    if (!isInt(r[0])) continue;
    const v = r.map(num);
    const t = v[9];
    if (!matOut[t]) matOut[t] = { entries: [], npcs: [...(materialNpcs.get(t) || [])].sort((a, b) => a - b) };
    for (const k of [0, 2, 3, 5, 6]) if (v[k]) refItem(v[k], `materialupgrade ${t}`);
    matOut[t].entries.push([v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8]]);
  }
  for (const [i, n] of materialNpcs) if (!matOut[i]) hard(`npc(s) ${[...n].join(',')} open material exchange ${i} which has no rows`);

  // supply machine (SUPPLYMACHINE_GAMBLER NPCs Tes 161 / Grina 756): the per-index machines of supplymachine.csv are all
  // disabled (Enable 0); the live one is the "single supply machine" (grade table + weighted item list) and the field-boss roulette
  const smBase = parseTable(readText(src('share/supplymachine/single_supplymachine_base.csv')));
  const smDetailRows = parseCSV(readText(src('share/supplymachine/single_supplymachine_details.csv')));
  const smHdr = smDetailRows.findIndex((r) => str(r[0]) === 'no');
  const smVersion = num((smDetailRows.find((r) => str(r[0]) === 'version') || [])[1]);
  const smEntries = [];
  for (const r of smDetailRows.slice(smHdr + 1)) {
    if (!isInt(r[0])) continue;
    refItem(r[2], 'single_supplymachine_details');
    smEntries.push([num(r[1]), num(r[2]), num(r[4]), num(r[5]), num(r[6]), num(r[7])]);
  }
  const smMachines = parseTable(readText(src('share/supplymachine/supplymachine.csv'))).rows.filter((r) => isInt(r.SupplyMachineIndex));
  const smUi = parseTable(readText(src('share/supplymachine/supplymachine_ui.csv')));
  for (const r of smUi.rows) for (const h of smUi.header) if (/ItemIndex/.test(h) && num(r[h])) refItem(r[h], 'supplymachine_ui');
  const fbRows = parseTable(readText(src('share/supplymachine/fieldboss_supplymachine.csv'))).rows.filter((r) => isInt(r.RouletteNum));
  const supplyMachine = {
    npcs: Object.entries(npcOut).filter(([, n]) => n.jobs.some((j) => j.role === 'SUPPLYMACHINE_GAMBLER')).map(([i]) => +i),
    window: uiKey('script/ui/game2/supplymachine/ui_supplymachinewnd.txt'),
    singleWindow: uiKey('script/ui/game2/privatesupply/ui_privatesupplywnd.txt'),
    fieldBossWindow: uiKey('script/ui/game2/fieldbosssupply/ui_fieldbosssupplywnd.txt'),
    fieldBossWindowV1: uiKey('script/ui/game2/ui_fieldbosssupplywnd.txt'),
    alarmWindows: [uiKey('script/ui/game2/supplymachine/ui_supplywnd_alarm.txt'), uiKey('script/ui/game2/privatesupply/ui_privatesupplywnd_alarm.txt')],
    version: smVersion,
    grades: smBase.rows.filter((r) => isInt(r.grade)).map((r) => [num(r.grade), num(r.min_count), num(r.max_count)]),
    gradeFields: ['grade', 'minCount', 'maxCount'],
    entries: smEntries,
    entryFields: ['grade', 'item', 'registerRate', 'winRate', 'serverLimit', 'count'],
    machinesEnabled: smMachines.filter((r) => num(r.Enable)).length,
    // the per-index machine tables, kept raw (all 9 ship Enable 0 / Usable 0: the multi-machine mode is off in this client)
    machineFields: smMachines.length ? Object.keys(smMachines[0]).filter((k) => k !== '_row') : [],
    machines: smMachines.map((r) => Object.keys(r).filter((k) => k !== '_row').map((k) => (isInt(r[k]) ? num(r[k]) : str(r[k])))),
    uiMachineFields: smUi.header,
    uiMachines: smUi.rows.filter((r) => isInt(r.SupplyMachineIndex)).map((r) => smUi.header.map((k) => (isInt(r[k]) ? num(r[k]) : str(r[k])))),
    uiMachinesUsable: smUi.rows.filter((r) => num(r.Usable)).length,
    // stringtable_supplymachine.txt: 90 window/messages, 91 machine names, 92 material captions, 95 product tooltips (some Korean only)
    strings: Object.fromEntries([...table(T_SUPPLY)].map(([c, m]) => [c, Object.fromEntries([...m].filter(([, t]) => t))])),
    fieldBossRoulette: fbRows.map((r) => {
      const items = [];
      for (let k = 1; k <= 10; k++) { const it = num(r[`Item${k}_Index`]); if (it) { refItem(it, 'fieldboss_supplymachine'); items.push([it, num(r[`Item${k}_Rate`]), num(r[`Item${k}_Count`])]); } }
      const pay = str(r.PayItemIndex).split('/').map(num).filter(Boolean);
      for (const p of pay) refItem(p, 'fieldboss_supplymachine pay');
      return { roulette: num(r.RouletteNum), payItems: pay, payCount: num(r.PayItemCount), items };
    }),
    rouletteItemFields: ['item', 'rate (increasing column; cumulative weight, total = last value, inferred)', 'count'],
  };

  // NPC dialog menu line per job (npc/stringtable_jobtype.txt cate 200; MULTISHOP lines are the shop names, cate 341)
  const T_JOBTYPE = 'script/string/npc/stringtable_jobtype.txt';
  const jt = (t) => tstr(T_JOBTYPE, 200, t);
  for (const n of Object.values(npcOut)) {
    for (const j of n.jobs) {
      let label = null;
      if (j.role === 'MULTISHOP' || j.role === 'SHOP') label = shopsOut[j.shop]?.name || jt(0);
      else if (j.shop != null) label = jt(j.jobType) || shopsOut[j.shop]?.name || jt(0);
      else if (j.exchange != null) label = exchangesOut[j.exchange]?.name || null;
      else if (j.store != null) label = (jt(166) || '[Exchange] use the %s Exchange.').replace('%s', storesOut[j.store]?.name ?? '');
      else label = jt(j.jobType);
      if (label) j.label = label.split('\n')[0];
    }
  }

  // sell price table
  const sellTable = {};
  for (const r of sellPrice.rows) { if (!isInt(r.SOCKETCOUNT)) continue; const o = {}; for (const h of sellPrice.header.slice(1)) o[h] = num(r[h]); sellTable[num(r.SOCKETCOUNT)] = o; }

  // NPC store UI (window + sprites)
  const imagetable = parseImageTable(readText(src('script/ui/com/imagetable.txt')));
  const texMissing = new Set();
  const sprite = (group, index) => {
    const e = imagetable.get(String(group).toLowerCase())?.get(num(index));
    if (!e) return null;
    const tex = assetKey(e.tex, 'texture');
    if (!tex) { texMissing.add(e.tex); return null; }
    const s = { tex, rect: [e.x, e.y, e.w, e.h] };
    if (e.nine) s.nine = e.nine;
    return s;
  };
  const spriteGroup = (group) => {
    const g = imagetable.get(group.toLowerCase());
    if (!g) { soft(`imagetable: sprite group ${group} missing`); return {}; }
    const out = {};
    for (const i of [...g.keys()].sort((a, b) => a - b)) { const s = sprite(group, i); if (s) out[i] = s; }
    return out;
  };

  const storeUi = {
    window: uiKey('script/ui/game2/store/ui_storewnd.txt'),
    grid: { cols: GRID_COLS, rows: Math.max(GRID_ROWS, maxRow), cellPx: 33, origin: [8, 66] },
    title: tstr(T_OPTION, 2001, 57), defaultTab: tstr(T_OPTION, 2001, 520),
    buttons: { store: tstr(T_BUTTON, 2000, 66), repurchase: tstr(T_BUTTON, 2000, 67), close: tstr(T_BUTTON, 2000, 68) },
    sprites: { store_npc_normal: spriteGroup('store_npc_normal'), store_npc_rebuy: spriteGroup('store_npc_rebuy') },
    exchangeWindow: uiKey('script/ui/game2/exchangeshop/ui_exchangeshopwnd.txt'),
    exchangeStoreWindow: uiKey('script/ui/game2/store/ui_exchangestorewnd.txt'),
    materialWindow: uiKey('script/ui/game2/itemupgrade/ui_materialexchangewnd.txt'),
    legacyWindow: uiKey('script/ui/game2/ui_storewnd.txt'),
    // "Buy Item" popup (title 2001/58, "Price per item" 110/388, "Quantity" 110/389): the quantity prompt for stackables (inferred use)
    quantityWindow: uiKey('script/ui/game2/store/ui_storebuyitem_renew.txt'), quantityWindowV1: uiKey('script/ui/game2/store/ui_storebuyitem.txt'),
    quantityStrings: { title: tstr(T_OPTION, 2001, 58), pricePerItem: tstr('script/string/normal/stringtable_trade.txt', 110, 388), quantity: tstr('script/string/normal/stringtable_trade.txt', 110, 389), ok: tstr(T_BUTTON, 2000, 15) },
    exchangeBuyConfirm: uiKey('script/ui/game2/msgbox/ui_buyexchangeitem.txt'),
  };
  const storeMsgs = {};
  for (const [c, t] of table(T_STORE).get(340) || []) storeMsgs[c] = t;
  const exchMsgs = {};
  for (const [c, t] of table(T_EXCH).get(2006) || []) if (c < 500) exchMsgs[c] = t;

  const shopsJson = {
    format: 'dekaron-solo/shops@1', generatedBy: 'tools/build-shops.mjs', doc: 'docs/formats/shops.md',
    rules: {
      buy: 'per unit, first match wins: (1) sets[s].costs[item] -> pay those [needItem, count] pairs (exchange price, e.g. C Coin); (2) shop kind ARENA_SHOP and items[item].purchasePoint -> that many battle points; (3) items[item].price > 0 -> floor(price * tab.buyRatio / 10) dil (every tab ships buyRatio 10 = list price); (4) item in sets[s].unpriced -> no client-side price (server-side in the original); solo policy: free',
      sell: 'dil = min(floor(items[i].price * shop.sellRatio / 10 * sellPriceTable[sockets][quality] / 100), shop.maxSellCost); items with a cash period cannot be sold (store msg 8)',
      stack: 'set item stack 0 = one unit per click (stackables: ask for a quantity up to items[i].maxStack)',
      grid: 'set items [item, stack, x, y]: x,y = top-left cell in a 10-column grid of 33 px cells (window slot origin 8,66); an item covers items[i].w x items[i].h cells',
    },
    setItemFields: ['item', 'stack', 'x', 'y'],
    exchangeEntryFields: ['giveItem', 'giveCount', 'priceCount (of exchange.priceItem)', 'takeItem (also consumed, 0 = none)'],
    exchangeStoreEntryFields: ['item', 'needItem', 'needCount', 'returnCount', 'limitCount', 'season', 'altNeedItems? (either pays)'],
    materialEntryFields: ['resultItem', 'resultCount', 'eventMaterialBound', 'eventMaterialTradable', 'eventMaterialCount', 'materialBound', 'materialTradable', 'materialCount', 'dilCost'],
    sellPriceTable: sellTable,
    ui: storeUi, messages: { store: storeMsgs, exchange: exchMsgs },
    shops: shopsOut, sets: setsOut, exchanges: exchangesOut, exchangeStores: storesOut, materialExchanges: matOut,
    supplyMachine,
    npcs: npcOut,
    unused: {
      shopExchangeTestRows: unusedShopEx.map(([k, v]) => ({ key: k, need: v.need, desc: v.desc })),
      exchangePriceWithoutSetItem: unusedExPrice.map(([k, v]) => ({ key: k, need: v.need, desc: v.desc })),
    },
    items: null, // filled below (shared item subset)
  };

  // ============================================================================================
  // D-Shop
  // ============================================================================================
  const csCur = parseTable(readText(src('share/cashshop/cashshop.csv')));
  const csOld = parseTable(readText(src('script/cashshop/cashshop.csv')));
  const almighty = parseTable(readText(src('share/cashshop/cashshop_almightypremium.csv')));
  const banner = parseTable(readText(src('script/cashshop/cashshopbanner.csv')));
  const rboxInfo = parseTable(readText(src('script/cashshop/randomboxinfo.csv')));
  const vip = parseTable(readText(src('script/mileageshop/mileageshop.csv')));
  const cashBox = parseTable(readText(src('share/premiere/cash_randombox.csv')));
  const teleport = parseTable(readText(src('share/premiere/teleport.csv')));
  const respon = parseTable(readText(src('share/premiere/respon.csv')));
  const pkg = parseTable(readText(src('share/item/itempackage.csv')));

  const dshopItems = {};
  const dref = (i, from) => { const it = refItem(i, from); if (it) dshopItems[num(i)] = it; return it; };
  const productRows = (t, label) => t.rows.filter((r) => isInt(r.MainCate)).map((r, n) => {
    const items = [];
    const cols = t.header.map((h, k) => [h, k]).filter(([h]) => /^ItemIndex/.test(h));
    for (const [h] of cols) { const v = num(r[h]); if (v) items.push(v); }
    if (items.length !== num(r.Count)) soft(`${label} row ${r._row}: Count ${r.Count} but ${items.length} items`);
    for (const i of items) dref(i, `${label} row ${r._row}`);
    const o = { id: n, main: num(r.MainCate), sub: num(r.SubCate), items };
    if (num(r.Notice)) o.notice = num(r.Notice);
    if (num(r.Warning)) o.warning = 1;
    return o;
  });
  const products = productRows(csCur, 'share/cashshop/cashshop.csv');
  const legacy = productRows(csOld, 'script/cashshop/cashshop.csv');
  const vipProducts = productRows(vip, 'script/mileageshop/mileageshop.csv');

  // tab tree from the live (search) cash shop window + string tables
  const csWin = 'script/ui/game2/cashshop/ui_cashshopwnd_search.txt';
  const csCtl = parseUiControls(readText(src(csWin)));
  const ctl = (id) => csCtl.find((c) => c.id === id);
  const caption = (c) => { if (!c?.text2) return null; const [cate, code] = c.text2; return tstr(T_CASHSHOP, cate, code) ?? tstr(T_CASHITEM, cate, code); };
  const btnSprites = (c) => { const o = {}; for (const im of c?.images || []) { const s = sprite(im.screen, im.index); if (s) o[im.key || 'none'] = s; } return o; };
  // SubCate codes per button: button order of the legacy window (all 7 item sub-tabs) == SubCate 0..6; the live window
  // dropped "Package" (4). Costume: crest button -> 31 and costume button -> 29 (matched by product content).
  const TAB_DEF = [
    { main: 0, key: 'hot', button: 'btn_hot', panel: 'pan_hot', subs: [['btn_all', 0]] },
    { main: 1, key: 'item', button: 'btn_item', panel: 'pan_item', subs: [['btn_reinforcement', 0], ['btn_potion', 1], ['btn_grows', 2], ['btn_theme', 3], ['btn_pakage', 4], ['btn_inventory', 5], ['btn_itempreminum', 6]] },
    { main: 2, key: 'petvehicle', button: 'btn_petvehicle', panel: 'pan_petvehicle', subs: [['btn_pet', 0], ['btn_petitem', 1], ['btn_vehicle', 2], ['btn_scroll', 3]] },
    { main: 3, key: 'costume', button: 'btn_costume', panel: 'pan_costume', subs: [['btn_cospreminum', 29], ['btn_munjang', 31]] },
  ];
  const MAIN_NAMES = { 0: tstr(T_CASHSHOP, 210, 2), 1: tstr(T_CASHSHOP, 210, 3), 2: tstr(T_CASHSHOP, 210, 4), 3: tstr(T_CASHSHOP, 210, 5) };
  const oldWinCtl = parseUiControls(readText(src('script/ui/game2/cashshop/ui_cashshopwnd.txt')));
  const tabs = TAB_DEF.map((t) => {
    const b = ctl(t.button);
    if (!b) hard(`${csWin}: main tab button ${t.button} missing`);
    const subs = t.subs.map(([id, sub]) => {
      const c = ctl(id) || oldWinCtl.find((x) => x.id === id);
      const live = !!ctl(id);
      const n = products.filter((p) => p.main === t.main && p.sub === sub).length;
      const o = { sub, name: caption(c) ?? id, button: id, products: n };
      if (!live) o.legacyOnly = true;
      o.sprites = btnSprites(c);
      return o;
    });
    for (const p of products.filter((p) => p.main === t.main)) if (!t.subs.some(([, s]) => s === p.sub)) hard(`D-Shop product ${p.id}: sub-category ${t.main}/${p.sub} has no tab button`);
    return { main: t.main, key: t.key, name: MAIN_NAMES[t.main], button: t.button, sprites: btnSprites(b), subs };
  });
  for (const p of products) if (!TAB_DEF.some((t) => t.main === p.main)) hard(`D-Shop product ${p.id}: main category ${p.main} unknown`);

  // VIP shop tabs (script/ui/game2/vipshop/ui_vipshopwnd_search.txt): all / premium equipment / unique = MainCate 0/1/2
  const vipWin = 'script/ui/game2/vipshop/ui_vipshopwnd_search.txt';
  const vipCtl = parseUiControls(readText(src(vipWin)));
  const vipTabs = [['btn_main_all', 0, 1], ['btn_premium_equipment', 1, 2], ['btn_unique', 2, 3]].map(([id, main, code]) => {
    const c = vipCtl.find((x) => x.id === id);
    if (!c) hard(`${vipWin}: ${id} missing`);
    return { main, name: tstr(T_CASHSHOP, 214, code), button: id, sprites: btnSprites(c), products: vipProducts.filter((p) => p.main === main).length };
  });

  // purchase warnings (cate 920 code = item index) + generic warning text
  const warnings = {};
  const warnTable = table(T_CASH).get(920) || new Map();
  for (const p of [...products, ...legacy]) for (const i of p.items) if (warnTable.has(i)) warnings[i] = warnTable.get(i);
  const warnedWithoutText = products.filter((p) => p.warning && !p.items.some((i) => warnTable.has(i))).length;

  // packages (itempackage.csv) reachable from D-Shop items, plus the full table (packages are opened in the inventory)
  const packages = {};
  for (const r of pkg.rows) {
    if (!isInt(r.PackageItemIndex)) continue;
    const items = [];
    for (let k = 0; k < 10; k++) { const it = num(r[`ItemIndex_${k}`]), c = num(r[`StackNum_${k}`]); if (it) items.push([it, c]); }
    if (items.length !== num(r.ItemCount)) soft(`itempackage row ${r._row}: ItemCount ${r.ItemCount} but ${items.length} items`);
    const o = { items };
    if (num(r.WminLevel) || num(r.WmaxLevel)) o.level = [num(r.WminLevel), num(r.WmaxLevel)];
    packages[num(r.PackageItemIndex)] = o;
  }
  const productItemSet = new Set([...products, ...legacy, ...vipProducts].flatMap((p) => p.items));
  let pkgProducts = 0;
  for (const i of productItemSet) if (packages[i]) pkgProducts++;
  // every package's items must exist in the client item tables (validated; details emitted only for reachable ones)
  let pkgItemsMissing = 0;
  for (const [p, o] of Object.entries(packages)) for (const [it] of o.items) if (!dat.map.has(it) && !mileageItems.has(it)) { pkgItemsMissing++; if (pkgItemsMissing <= 3) soft(`itempackage ${p}: item ${it} not in item tables`); }

  // box contents (share/item/itemchange_randombox.csv) for every box reachable from a D-Shop / legacy / VIP product
  //   Index, Type, WminLevel, WmaxLevel, BonusItemIndex, BonusStackCount, TakeItemCount, GiveItemCount, DRopFilde,
  //   ServerMessageIndex, listCount, 36 x (GiveIndex n, StackNum n, Percent n)
  const boxRows = new Map();
  for (const r of parseCSV(readText(src('share/item/itemchange_randombox.csv'))).slice(1)) if (isInt(r[0]) && !boxRows.has(num(r[0]))) boxRows.set(num(r[0]), r);
  const boxes = {};
  const boxTypes = {};
  let boxDepthMax = 0, boxOddPercents = 0;
  const visitBox = (i, depth) => {
    if (boxes[i] || !boxRows.has(i) || depth > 16) return;
    boxDepthMax = Math.max(boxDepthMax, depth);
    const r = boxRows.get(i);
    const v = r.map(num);
    const list = [];
    for (let k = 0; k < 36; k++) { const it = v[11 + k * 3]; if (it) list.push([it, v[12 + k * 3], v[13 + k * 3]]); }
    if (list.length !== v[10]) soft(`itemchange_randombox ${i}: listCount ${v[10]} but ${list.length} entries`);
    const o = { type: v[1], take: v[6], give: v[7], list };
    if (v[2] || v[3]) o.level = [v[2], v[3]];
    if (v[4]) o.bonus = [v[4], v[5]];
    if (v[8]) o.dropField = v[8];
    if (v[9]) o.msg = v[9];
    boxes[i] = o;
    boxTypes[v[1]] = (boxTypes[v[1]] || 0) + 1;
    if ([1, 2, 4].includes(o.type)) {
      let prev = -1, mono = true;
      for (const [, , p] of list) { if (p < prev) mono = false; prev = p; }
      if (!mono || prev !== 10000) { boxOddPercents++; if (boxOddPercents <= 3) soft(`box ${i} (type ${o.type}): cumulative percents ${mono ? '' : 'not monotonic, '}end at ${prev} (expected 10000)`); }
    }
    if (o.bonus) dref(o.bonus[0], `box ${i} bonus`);
    for (const [it] of list) { dref(it, `box ${i}`); visitBox(it, depth + 1); }
  };
  for (const p of [...products, ...legacy, ...vipProducts]) for (const i of p.items) visitBox(i, 0);

  // random boxes
  const showDigit = {};
  for (const r of rboxInfo.rows) if (isInt(r.Index)) { showDigit[num(r.Index)] = num(r.ShowDigit); dref(r.Index, 'randomboxinfo'); }
  const keyBoxes = {};
  for (const r of cashBox.rows) {
    if (!isInt(r.BoxItem_Index)) continue;
    const keys = [];
    for (let k = 0; k < 6; k++) { const v = num(r[`KeyItem_Index_${k}`]); if (v) { keys.push(v); dref(v, 'cash_randombox key'); } }
    if (keys.length !== num(r.KeyCount)) soft(`cash_randombox ${r.BoxItem_Index}: KeyCount ${r.KeyCount} but ${keys.length} keys`);
    const entries = [];
    let prev = 0, mono = true;
    for (let k = 0; k < 30; k++) {
      const it = num(r[`Item_Index_${k}`]); if (!it) continue;
      const cum = num(r[`Percent_${k}`]);
      if (cum < prev) mono = false;
      entries.push([it, num(r[`StackNum_${k}`]), cum - prev, num(r[`Notify_Type_${k}`])]);
      prev = cum; dref(it, `cash_randombox ${r.BoxItem_Index}`);
    }
    if (entries.length !== num(r.list_Count)) soft(`cash_randombox ${r.BoxItem_Index}: list_Count ${r.list_Count} but ${entries.length} entries`);
    if (!mono) soft(`cash_randombox ${r.BoxItem_Index}: cumulative percents not monotonic`);
    if (prev !== 1000000) soft(`cash_randombox ${r.BoxItem_Index}: last cumulative percent ${prev} != 1000000`);
    dref(r.BoxItem_Index, 'cash_randombox');
    keyBoxes[num(r.BoxItem_Index)] = { keys, entries };
  }
  for (const kb of Object.values(keyBoxes)) for (const [it] of kb.entries) visitBox(it, 1);
  // packages reachable from products or opened boxes: resolve their contents too
  for (const i of Object.keys(dshopItems).map(Number)) if (packages[i]) for (const [it] of packages[i].items) { dref(it, `package ${i}`); visitBox(it, 1); }

  // premium services
  const premiumItems = {};
  const pHeader = premiere.header.filter((h) => h !== 'ItemIndex');
  for (const r of premiere.rows) {
    if (!isInt(r.ItemIndex)) continue;
    const idx = num(r.ItemIndex);
    const v = pHeader.map((h) => num(r[h]));
    if (idx) dref(idx, 'premiereitem');
    premiumItems[idx] = v;
  }
  // LocationIndex -> share/arrange/location.csv (Index, Location_Name, MapIndex, Pos_X, Pos_Y, Direction, ...)
  const locRows = new Map();
  for (const r of parseCSV(readText(src('share/arrange/location.csv'))).slice(1)) if (isInt(r[0])) locRows.set(num(r[0]), r);
  const locations = (t, label, nameCol) => t.rows.filter((r) => isInt(r.LocationIndex)).map((r) => {
    const li = num(r.LocationIndex);
    const o = { location: li, name: loc(`premiere#${label}#${nameCol}|${r._row}`) || str(r.LocationName), minLv: num(r.MinLevel), maxLv: num(r.MaxLevel) };
    if (r.Type != null) o.type = num(r.Type);
    if (r.Order != null) o.order = num(r.Order);
    const lr = locRows.get(li);
    if (!lr) hard(`premium ${label}: location ${li} not in share/arrange/location.csv`);
    else { o.map = num(lr[2]); o.pos = [num(lr[3]), num(lr[4]), num(lr[5])]; if (!mapIndex.has(o.map)) hard(`premium ${label}: location ${li} map ${o.map} not in maplist.csv`); }
    return o;
  });
  const almightyOut = almighty.rows.filter((r) => isInt(r.ItemIndex)).map((r) => { dref(r.ItemIndex, 'almightypremium'); return { item: num(r.ItemIndex), serviceDays: num(r.ServiceTime), updatableDays: num(r.UpdatableDays) }; });

  // strings the D-Shop window uses
  const csStrings = {};
  for (const cate of [210, 211, 212, 213, 214, 220, 221, 222, 223, 224, 225, 226, 900]) { const m = table(T_CASHSHOP).get(cate); if (m) csStrings[cate] = Object.fromEntries(m); }
  const ciStrings = Object.fromEntries(table(T_CASHITEM).get(171) || []);
  const rbStrings = Object.fromEntries(table(T_RBOX).get(600) || []);

  // banner: the local fallback image + the (ignored) web banner feeds
  const bannerLocal = sprite('banner', 0);
  if (!bannerLocal) hard('banner#0 (local D-Shop banner) does not resolve');
  const csUi = {
    window: uiKey(csWin), legacyWindow: uiKey('script/ui/game2/cashshop/ui_cashshopwnd.txt'), vipWindow: uiKey(vipWin),
    boxInfoWindow: uiKey('script/ui/game2/cashshop/ui_cashshopboxinfownd.txt'), randomBoxWindow: uiKey('script/ui/game2/randombox/ui_cashrandomboxwnd_renew.txt'),
    previewWindow: uiKey('script/ui/game2/cashshop/ui_previewwnd.txt'), cashInventoryWindow: uiKey('script/ui/game2/ui_cashinvenwnd.txt'),
    title: tstr(T_TITLE, 100, 130), vipTitle: tstr(T_TITLE, 100, 153),
    search: { button: tstr(T_SEARCH, 2009, 84), reset: tstr(T_SEARCH, 2009, 8) },
    sprites: {
      cashshop: spriteGroup('cashshop'), cashshopwnd: spriteGroup('cashshopwnd'), banner: bannerLocal ? { 0: bannerLocal } : {},
      banner_vip: (() => { const s = sprite('banner_vip', 0); return s ? { 0: s } : {}; })(), vipshop_tap_btn: spriteGroup('vipshop_tap_btn'),
      RandomBox: spriteGroup('RandomBox'), Itemchoice: spriteGroup('Itemchoice'),
    },
    noticeIcons: { 1: sprite('cashshop', 31), 2: sprite('cashshop', 32), 4: sprite('cashshop', 65) },
    limitIcons: { purchaseLimit: sprite('cashshop', 29), levelLimit: sprite('cashshop', 30) },
  };

  const dshopJson = {
    format: 'dekaron-solo/dshop@1', generatedBy: 'tools/build-shops.mjs', doc: 'docs/formats/shops.md',
    title: csUi.title,
    currency: { name: 'DKC', note: 'D-Shop coins. Solo: the engine grants an unlimited balance; price = items[i].cash per purchase. Billing / gift / refund / password fields are ignored.' },
    rules: {
      product: 'a product is one grid cell; product.items are its purchase variants (the combo box), each variant = one item index',
      variantLabel: 'items[i].period > 0 ? `${period/86400} days / ${cash}` (string 220/24) : `${max(1, stack)} ea / ${cash}` (string 220/23); period 0 = Permanent (220/37)',
      grant: 'buying variant i gives max(1, items[i].stack) x item i (into the Cash Inventory, then the bag); items[i].period > 0 = expires that many seconds after purchase',
      notice: 'product.notice 1 Best Selling (HOT icon), 2 New Items (NEW icon), 3 On Sale, 4 Event Items (EVENT icon) - strings 221/n',
      warning: 'product.warning = show the purchase warning (warnings[item] text, else ciStrings[34]) with Yes/No before buying',
      hot: 'main 0 (HOT) repeats products that also sit in their real tab',
    },
    tabs, products,
    legacyProducts: legacy,
    vipShop: { title: csUi.vipTitle, currency: 'VIP points (items[i].vipCost)', tabs: vipTabs, products: vipProducts },
    warnings,
    boxes,
    boxListFields: ['item', 'stack', 'percent'],
    boxRules: {
      0: 'selection box: the player picks `give` entries from list (percent 0) - Ex-Box / Selection Box',
      1: 'random box: roll r in [0,10000); first entry whose cumulative percent > r (percents are cumulative, last = 10000)',
      2: 'random box as type 1, plus bonus [item, count] always given',
      4: 'random box, cumulative /10000 (variant used by event boxes; treat as type 1)',
      5: 'key box: contents in randomBoxes.keyBoxes (needs one of its keys); list holds a placeholder',
      8: 'give all: every list entry x stack (like a package)',
      note: 'take = boxes consumed per open; level = [min,max] character level to open; msg = server broadcast id for rare results. Types 2/4/5/8 inferred from rows; full box system: see the boxes dataset (share/item/itemchange_randombox.csv)',
    },
    packages,
    randomBoxes: { showDigit, keyBoxes, keyBoxEntryFields: ['item', 'stack', 'chancePerMillion', 'notifyType'] },
    premium: {
      itemFields: pHeader, items: premiumItems,
      teleport: locations(teleport, 'teleport.csv', 2), respon: locations(respon, 'respon.csv', 1), almighty: almightyOut,
    },
    banner: { local: bannerLocal?.tex ?? null, rect: bannerLocal?.rect ?? null, webFeeds: banner.rows.map((r) => ({ nation: str(r.Nation), xml: str(r.BannerXml), images: str(r.ImageURL) })), note: 'web feeds are ignored (offline); show the local banner' },
    ui: csUi,
    strings: { cashshop: csStrings, cashitemUi: ciStrings, randomBox: rbStrings },
    items: dshopItems,
  };

  // ============================================================================================
  // Player market (JobType 46 "Middleman" NPCs): store search + consignment ("Agency")
  // ============================================================================================
  const slRecs = parseShopListDat(readKey(src('share/article/shoplist.dat')));
  const SL_PARTS = ['accessory', 'armor', 'socket', 'waste', 'weapon'];
  const slCsvRows = [];
  for (const p of SL_PARTS) for (const r of parseCSV(readText(src(`share/article/shoplist_${p}.csv`))).slice(1)) if (isInt(r[0])) slCsvRows.push({ part: p, r });
  let slMismatch = 0, slBadDepth = 0, slGaps = 0;
  if (slCsvRows.length !== slRecs.length) hard(`shoplist.dat: ${slRecs.length} records but the 5 shoplist_*.csv hold ${slCsvRows.length} rows`);
  slRecs.forEach((rec, k) => {
    const lastNz = rec.types.reduce((a, v, i) => (v ? i + 1 : a), 0);
    if (rec.depth !== lastNz) slBadDepth++;
    const z = rec.allItems.indexOf(0);
    if (z >= 0 && z < 20 && rec.allItems.slice(z).some(Boolean)) slGaps++;
    const c = slCsvRows[k];
    if (!c) return;
    const r = c.r;
    const csvTypes = [1, 3, 5, 7, 9, 11].map((i) => num(r[i]));
    const csvNames = [2, 4, 6, 8, 10, 12].map((i) => str(r[i]));
    const csvItems = r.slice(13, 33).map(num);
    const same = num(r[0]) === rec.index && csvTypes.join() === rec.types.join() && csvItems.join() === rec.allItems.join()
      && csvNames.every((n, i) => n === rec.names[i] || i >= rec.depth);
    if (!same) { slMismatch++; if (slMismatch <= 3) soft(`shoplist.dat record ${k} != shoplist_${c.part}.csv row ${r[0]}`); }
  });
  if (slBadDepth) hard(`shoplist.dat: ${slBadDepth} records whose depth != used levels`);
  // taxonomy tree: node {n: caption, t: typeCode, i?: items, c?: children}; a record is the node at its depth
  const slRoots = [];
  const slNodeMap = new Map();
  let slDupPaths = 0, slNodes = 0;
  const slItemSet = new Set();
  for (const rec of slRecs) {
    let list = slRoots, key = '';
    let node = null;
    for (let d = 0; d < rec.depth; d++) {
      key += `/${rec.types[d]}`;
      node = slNodeMap.get(key);
      if (!node) { node = { n: rec.names[d], t: rec.types[d] }; slNodeMap.set(key, node); list.push(node); slNodes++; }
      else if (!node.n && rec.names[d]) node.n = rec.names[d];
      if (d < rec.depth - 1) list = (node.c ??= []);
    }
    if (!node) continue;
    if (node.i) { slDupPaths++; for (const it of rec.items) if (!node.i.includes(it)) node.i.push(it); }
    else if (rec.items.length) node.i = [...rec.items];
    for (const it of rec.items) slItemSet.add(it);
  }
  const slMissingItems = [...slItemSet].filter((i) => !dat.map.has(i) && !mileageItems.has(i));
  if (slMissingItems.length) soft(`store-search taxonomy: ${slMissingItems.length} of ${slItemSet.size} item indices are not in item.dat (stale client rows), e.g. ${slMissingItems.slice(0, 5).join(', ')}`);
  // shoplist_total.csv: the search window's class/type filter (List1..3 captions -> Item_Code/Item_Type + class mask)
  const slTotal = parseTable(readText(src('share/article/shoplist_total.csv')));
  const consignSkills = {};
  for (const r of parseTable(readText(src('share/article/consignmentskill.csv'))).rows) if (str(r.Class)) consignSkills[str(r.Class)] = num(r.SkillIndex);
  const T_CONSIGN = 'script/string/auction/stringtable_consignment.txt';
  const catStrings = (key) => Object.fromEntries([...table(key)].map(([c, m]) => [c, Object.fromEntries([...m].filter(([, t]) => t))]));
  const searchNpcs = Object.entries(npcOut).filter(([, n]) => n.jobs.some((j) => j.role === 'SEARCH_STORE')).map(([i]) => +i);
  const shopsSearchJson = {
    format: 'dekaron-solo/shops_search@1', generatedBy: 'tools/build-shops.mjs', doc: 'docs/formats/shops.md',
    note: 'Player market: the Middleman NPCs (JobType 46) open the store search (find items in other players\' private shops) and the consignment "Agency" (list items for other players to buy). Solo play has no other players; the taxonomy is still the client\'s own item catalogue (usable as an item browser).',
    npcs: searchNpcs,
    windows: {
      search: uiKey('script/ui/game2/store/ui_new_storesearch_2.txt'), searchOld: uiKey('script/ui/game2/store/ui_storesearch.txt'), searchV1: uiKey('script/ui/game2/store/ui_new_storesearch.txt'),
      consignment: uiKey('script/ui/game2/store/ui_storeconsignment_2.txt'), consignmentV1: uiKey('script/ui/game2/store/ui_storeconsignment.txt'),
      consignRegister: uiKey('script/ui/game2/store/ui_storeconsignregist_2.txt'), consignRegisterV1: uiKey('script/ui/game2/store/ui_storeconsignregist.txt'),
      purchase: uiKey('script/ui/game2/store/ui_storepurchase_2.txt'), purchaseV1: uiKey('script/ui/game2/store/ui_storepurchase.txt'),
      buyConfirm: uiKey('script/ui/game2/store/ui_storebuyconfirm_2.txt'), buyConfirmV1: uiKey('script/ui/game2/store/ui_storebuyconfirm.txt'),
      msgbox: uiKey('script/ui/game2/msgbox/ui_storesearch.txt'), pcShopCaution: uiKey('script/ui/game2/msgbox/ui_increasepcshop.txt'),
    },
    consignmentSkills: consignSkills,
    consignmentSkillNote: 'per class: the "Consignment Shop" mastery skill (register up to 5 items); see skills.json',
    strings: { searchstore: catStrings(T_SEARCH), consignment: catStrings(T_CONSIGN) },
    classFilterFields: slTotal.header,
    classFilter: slTotal.rows.filter((r) => isInt(r.Index)).map((r) => slTotal.header.map((h) => (isInt(r[h]) ? num(r[h]) : str(r[h])))),
    taxonomyNodeFields: { n: 'caption (English, from the dat)', t: 'type code at this level', i: 'item indices listed at this node (group rows list every +N variant)', c: 'child nodes' },
    taxonomy: slRoots,
    report: { records: slRecs.length, csvRows: slCsvRows.length, recordsDifferingFromCsv: slMismatch, itemGaps: slGaps, nodes: slNodes, duplicatePaths: slDupPaths,
      distinctItems: slItemSet.size, itemsNotInItemTables: slMissingItems.length, classFilterRows: slTotal.rows.length, npcs: searchNpcs.length },
  };

  // ---------------- shared item subset for shops.json ----------------
  const shopItemIdx = new Set();
  for (const s of Object.values(setsOut)) { for (const [i] of s.items) shopItemIdx.add(i); for (const c of Object.values(s.costs || {})) for (const [i] of c) shopItemIdx.add(i); }
  for (const e of Object.values(exchangesOut)) { shopItemIdx.add(e.priceItem); for (const a of e.priceItemAlt || []) shopItemIdx.add(a); for (const [g, , , t] of e.entries) { shopItemIdx.add(g); if (t) shopItemIdx.add(t); } }
  for (const st of Object.values(storesOut)) for (const [i, n, , , , , alt] of st.entries) { shopItemIdx.add(i); shopItemIdx.add(n); for (const a of alt || []) shopItemIdx.add(a); }
  for (const m of Object.values(matOut)) for (const e of m.entries) for (const k of [0, 2, 3, 5, 6]) if (e[k]) shopItemIdx.add(e[k]);
  for (const e of supplyMachine.entries) shopItemIdx.add(e[1]);
  for (const r of supplyMachine.fieldBossRoulette) { for (const p of r.payItems) shopItemIdx.add(p); for (const [i] of r.items) shopItemIdx.add(i); }
  shopsJson.items = {};
  for (const i of [...shopItemIdx].sort((a, b) => a - b)) if (itemsOut[i]) shopsJson.items[i] = itemsOut[i];

  // ---------------- asset verification (every key in both files) ----------------
  const allKeys = new Set();
  const walk = (v) => { if (typeof v === 'string') { if (/^(texture|script|property|share|mesh|anim|skel|texturepack|sound)\//.test(v)) allKeys.add(v); } else if (Array.isArray(v)) v.forEach(walk); else if (v && typeof v === 'object') Object.values(v).forEach(walk); };
  walk(shopsJson); walk(dshopJson); walk(shopsSearchJson);
  let badKeys = 0;
  for (const k of allKeys) { if (k !== k.toLowerCase() || !existsKey(k)) { badKeys++; hard(`asset key ${k} missing or not lower case`); } }

  // ---------------- report ----------------
  const allProductItems = [...productItemSet];
  const report = {
    itemDat: { records: dat.records, referencedItems: Object.keys(itemsOut).length, nameFromLinesEu: nameFromLines, nameFromCsv: nameFromCsv, missing: [...missingItems].map(([i, f]) => `${i} (${f})`) },
    npcShops: {
      shops: Object.keys(shopsOut).length, shopsWithNpc: Object.values(shopsOut).filter((s) => s.npcs.length).length,
      sets: Object.keys(setsOut).length, setsUsed, setItems: Object.values(setsOut).reduce((a, s) => a + s.items.length, 0),
      pricedInUsedSets: { dil: dilItems, battlePoints: pointItems, items: costItems, noClientPrice: freeItems },
      gridRowsNeeded: maxRow, overlapsInUsedSets: overlaps, overlapsInUnusedSets: overlapsUnused, outOfGrid,
      exchanges: Object.keys(exchangesOut).length, exchangeEntries: Object.values(exchangesOut).reduce((a, e) => a + e.entries.length, 0),
      exchangeStores: Object.keys(storesOut).length, materialExchanges: Object.keys(matOut).length,
      shopNpcs: Object.keys(npcOut).length, shopNpcsPlaced: Object.values(npcOut).filter((n) => n.maps.length).length,
      shopNpcsMissingFromNpcsJson: Object.keys(npcOut).filter((i) => npcsJson && !npcsJson.npcs?.[i]).length,
      placementsOnUnknownMaps: badPlacementMaps,
      tabNamesResolved: [...usedTabNames].filter((c) => tstr(T_TAB, 2002, c)).length + '/' + usedTabNames.size,
      shopNamesResolved: Object.values(shopsOut).filter((s) => s.name).length + '/' + Object.keys(shopsOut).length,
    },
    dshop: {
      products: products.length, legacyProducts: legacy.length, vipProducts: vipProducts.length,
      productVariants: products.reduce((a, p) => a + p.items.length, 0), distinctProductItems: new Set(products.flatMap((p) => p.items)).size,
      legacyOnlyItems: [...new Set(legacy.flatMap((p) => p.items))].filter((i) => !products.some((p) => p.items.includes(i))).length,
      pricedVariants: products.flatMap((p) => p.items).filter((i) => dshopItems[i]?.cash).length,
      placeholderPrice999999: products.flatMap((p) => p.items).filter((i) => dshopItems[i]?.cash === 999999).length,
      timedVariants: products.flatMap((p) => p.items).filter((i) => dshopItems[i]?.period).length,
      packageProducts: pkgProducts, packages: Object.keys(packages).length, packageItemsMissing: pkgItemsMissing, keyBoxes: Object.keys(keyBoxes).length,
      boxes: Object.keys(boxes).length, boxTypes, boxDepthMax, randomBoxesWithOddPercents: boxOddPercents, productItemsThatAreBoxes: allProductItems.filter((i) => boxes[i]).length,
      productItemsThatArePackages: allProductItems.filter((i) => packages[i]).length,
      warningProducts: products.filter((p) => p.warning).length, warningsWithoutText: warnedWithoutText, premiumItems: Object.keys(premiumItems).length,
      productItemsMissing: allProductItems.filter((i) => !itemsOut[i]).length,
      productVariantsWithoutPrice: products.flatMap((p) => p.items).filter((i) => !dshopItems[i]?.cash).length,
      vipVariantsWithoutPrice: vipProducts.flatMap((p) => p.items).filter((i) => !dshopItems[i]?.vipCost).length,
    },
    storeSearch: shopsSearchJson.report,
    assets: { keys: allKeys.size, bad: badKeys, itemShapesWithoutIcon: [...iconMissing].sort((a, b) => a - b), texturesMissing: [...texMissing] },
    sources: [...sources].sort(),
    softWarnings: 0,
  };
  if (missingItems.size) soft(`${missingItems.size} referenced item indices are not in item.dat/itemmileage.csv: ${[...missingItems.keys()].slice(0, 10).join(', ')}`);
  report.softWarnings = softWarns.length;
  shopsJson.report = report;
  dshopJson.report = { dshop: report.dshop, itemDat: { referencedItems: Object.keys(dshopItems).length } };

  return { shopsJson, dshopJson, shopsSearchJson, report, hardFails, softWarns, itemsOut, dat, raw: { shopParsed, setParsed, exchanges, exStore, csCur, vip, cashBox, premiere, pkg } };
}

// ------------------------------------------------------------------------------------------------
// spot checks: 10 entries re-read straight from the raw files and compared with the JSON
// ------------------------------------------------------------------------------------------------
function spotChecks(res, opts) {
  const { shopsJson: S, dshopJson: D } = res;
  const ROOT = opts.data;
  const rawCsv = (key) => parseCSV(decodeKr(fs.readFileSync(path.join(ROOT, ...key.split('/')))));
  const col = (rows, label, id) => { const c = rows[0].findIndex((v) => str(v) === String(id)); return c; };
  const out = [];
  const check = (label, ok, detail) => out.push({ label, ok, detail });
  // 1. shop 5 tab 1 -> set, raw column
  { const rows = rawCsv('share/item/shop.csv'); const c = col(rows, 'Index', 5); const g = (f) => rows.find((r) => str(r[0]) === f)[c];
    const t = S.shops[5].tabs[0]; check('shop 5 tab1 (Grocery)', +g('SetIndex_1') === t.set && +g('Name_1') === t.nameCode && +g('BuyRatio_1') === t.buyRatio, `raw SetIndex_1=${g('SetIndex_1')} Name_1=${g('Name_1')} BuyRatio_1=${g('BuyRatio_1')} | json set=${t.set} name=${t.nameCode}("${t.name}") buyRatio=${t.buyRatio} shop="${S.shops[5].name}" npcs=${S.shops[5].npcs.length}`); }
  // 2. shopset 701 first 3 items
  { const rows = rawCsv('share/item/shopset.csv'); const c = col(rows, 'Index', 701); const raw = [3, 7, 11].map((r) => [+rows[r][c], +rows[r + 1][c], +rows[r + 2][c], +rows[r + 3][c]]);
    const js = S.sets[701].items.slice(0, 3); check('shopset 701 first 3 slots', JSON.stringify(raw) === JSON.stringify(js), `raw ${JSON.stringify(raw)} | json ${JSON.stringify(js)} names ${js.map(([i]) => S.items[i]?.name).join(', ')}`); }
  // 3. Health Potion price from item.dat vs json
  const datU32 = (idx, off) => { const r = res.dat.map.get(idx); return res.dat.parts[r.part].dv.getUint32(r.off + off, true); };
  { const p = datU32(3801, 194); check('item 3801 Health Potion price (item.dat @194)', S.items[3801]?.price === p, `dat=${p} json=${S.items[3801]?.price} name=${S.items[3801]?.name} maxStack=${S.items[3801]?.maxStack}`); }
  // 4. exchange 500 entry 0
  { const rows = rawCsv('share/item/exchange.csv'); const c = col(rows, 'Index', 500); const e = S.exchanges[500];
    const raw = [+rows[5][c], +rows[6][c], +rows[8][c], +rows[7][c]]; check('exchange 500 (Obsidian) entry 0', JSON.stringify(raw) === JSON.stringify(e.entries[0]) && +rows[3][c] === e.priceItem, `raw give/count/price/take ${raw} priceItem ${rows[3][c]} | json ${JSON.stringify(e.entries[0])} priceItem ${e.priceItem} "${e.name}" npcs ${e.npcs}`); }
  // 5. exchange price override set 900 first row
  { const rows = rawCsv('share/item/exchange_price.csv'); const r = rows[1]; const js = S.sets[+r[0]]?.costs?.[+r[1]];
    check(`exchange_price set ${r[0]} item ${r[1]}`, js && js[0][0] === +r[4] && js[0][1] === +r[5], `raw need ${r[4]} x${r[5]} | json ${JSON.stringify(js)} (${S.items[+r[4]]?.name})`); }
  // 6. exchangestore row 1
  { const rows = rawCsv('share/article/exchangestore.csv'); const r = rows[1]; const js = S.exchangeStores[+r[0]]?.entries[0];
    check('exchangestore first row', js && js.join() === r.slice(1, 7).map(Number).join(), `raw ${r.join(',')} | json ${JSON.stringify(js)} npcs ${S.exchangeStores[+r[0]]?.npcs}`); }
  // 7. npc 123 Nicole multishop list
  { const rows = rawCsv('share/creature/npc.csv'); const r = rows.find((x) => x[0] === '123'); const raw = []; for (let k = 0; k < +r[8]; k++) raw.push(+r[10 + k * 2]);
    const js = S.npcs[123].jobs.map((j) => j.jobIndex); check('npc 123 Nicole shops', raw.join() === js.join(), `raw ${raw.join(',')} | json ${js.join(',')} maps ${S.npcs[123].maps}`); }
  // 8. D-Shop row 38 (two variants)
  { const rows = rawCsv('share/cashshop/cashshop.csv'); const r = rows[38]; const p = D.products[37];
    const raw = r.slice(5).filter((x) => str(x)).map(Number); check('D-Shop product 37 (csv row 38)', raw.join() === p.items.join() && +r[0] === p.main && +r[1] === p.sub, `raw ${r.join(',')} | json ${JSON.stringify(p)} -> ${p.items.map((i) => `${D.items[i]?.name} ${D.items[i]?.cash}c x${D.items[i]?.stack || 1}`).join(' / ')}`); }
  // 9. D-Shop cash price from item.dat for 1171289
  { const c = datU32(1171289, 546), per = datU32(1171289, 550);
    check('item 1171289 cash cost/period (item.dat @546/@550)', D.items[1171289]?.cash === c && (D.items[1171289]?.period || 0) === per, `dat cost=${c} period=${per} | json ${JSON.stringify(D.items[1171289])}`); }
  // 10. VIP shop first product -> itemmileage row
  { const rows = rawCsv('share/item/itemmileage.csv'); const p = D.vipShop.products[0]; const r = rows.find((x) => +x[0] === p.items[0]); const h = rows[0];
    check('VIP product 0 -> itemmileage', r && D.items[p.items[0]]?.vipCost === +r[h.indexOf('DwCashItemCost')], `raw ${r?.[0]} "${r?.[1]}" cost ${r?.[h.indexOf('DwCashItemCost')]} | json ${JSON.stringify(D.items[p.items[0]])}`); }
  // 11. box contents: itemchange_randombox row for 1760133 (Meister's Rune Fortune Box)
  { const rows = rawCsv('share/item/itemchange_randombox.csv'); const r = rows.find((x) => x[0] === '1760133'); const b = D.boxes[1760133];
    const raw = []; for (let k = 0; k < +r[10]; k++) raw.push([+r[11 + k * 3], +r[12 + k * 3], +r[13 + k * 3]]);
    check('box 1760133 contents', b && JSON.stringify(raw) === JSON.stringify(b.list) && +r[1] === b.type, `raw type ${r[1]} ${JSON.stringify(raw)} | json type ${b?.type} ${JSON.stringify(b?.list)} -> ${b?.list.map(([i]) => D.items[i]?.name).join(', ')}`); }
  // 12. premium teleport 11557 -> location.csv map/pos
  { const rows = rawCsv('share/arrange/location.csv'); const r = rows.find((x) => x[0] === '11557'); const t = D.premium.teleport.find((x) => x.location === 11557);
    check('premium teleport 11557 -> location.csv', t && t.map === +r[2] && t.pos[0] === +r[3] && t.pos[1] === +r[4], `raw ${r.slice(0, 6).join(',')} | json ${JSON.stringify(t)}`); }
  // 13. store-search taxonomy: shoplist_armor.csv row 1 (Armor > Normal Armor > Azure Knight > Helmet > Valor Helmet) -> tree node items
  { const Q = res.shopsSearchJson; const rows = rawCsv('share/article/shoplist_armor.csv'); const r = rows[1];
    const pathT = [1, 3, 5, 7, 9].map((i) => +r[i]).filter(Boolean); let list = Q.taxonomy, node = null, names = [];
    for (const t of pathT) { node = (list || []).find((x) => x.t === t); if (!node) break; names.push(node.n); list = node.c; }
    const raw = r.slice(13, 33).map(Number).filter(Boolean);
    check('store-search shoplist_armor row 1', node && JSON.stringify(node.i) === JSON.stringify(raw), `raw ${r.slice(1, 13).filter((x, i) => i % 2).join(' > ')} items ${raw.join(',')} | json ${names.join(' > ')} items ${node?.i?.join(',')}`); }
  return out;
}

// ------------------------------------------------------------------------------------------------
if (process.argv[1] && path.resolve(process.argv[1]) === fileURLToPath(import.meta.url)) {
  const opts = parseArgs(process.argv);
  const t0 = Date.now();
  const res = build(opts);
  const { shopsJson, dshopJson, shopsSearchJson, report, hardFails, softWarns } = res;
  fs.mkdirSync(opts.out, { recursive: true });
  const ser = (o) => JSON.stringify(o, null, opts.pretty ? 1 : 0);
  const f1 = path.join(opts.out, 'shops.json'), f2 = path.join(opts.out, 'dshop.json'), f3 = path.join(opts.out, 'shops_search.json');
  fs.writeFileSync(f1, ser(shopsJson));
  fs.writeFileSync(f2, ser(dshopJson));
  fs.writeFileSync(f3, ser(shopsSearchJson));
  if (!opts.quiet) {
    console.log(`build-shops: ${((Date.now() - t0) / 1000).toFixed(1)} s`);
    console.log('  ' + [f1, f2, f3].map((f) => `${path.relative(process.cwd(), f)} ${(fs.statSync(f).size / 1024).toFixed(0)} KB`).join(', '));
    console.log(JSON.stringify({ ...report, sources: report.sources.length }, null, 1));
    if (softWarns.length) { console.log(`soft warnings (${softWarns.length}):`); for (const w of softWarns.slice(0, 40)) console.log('  - ' + w); }
  }
  if (opts.spot) {
    const sc = spotChecks(res, opts);
    console.log('spot checks:');
    for (const c of sc) console.log(`  [${c.ok ? 'ok' : 'FAIL'}] ${c.label}: ${c.detail}`);
    if (sc.some((c) => !c.ok)) hardFails.push('spot check failed');
  }
  if (hardFails.length) { console.log(`HARD FAILURES (${hardFails.length}):`); for (const h of hardFails.slice(0, 40)) console.log('  ! ' + h); process.exitCode = 1; }
  else if (!opts.quiet) console.log('OK: 0 hard failures');
}
