#!/usr/bin/env node
// Dekaron Solo — quest + dialog database builder.
//
//   node tools/build-quests.mjs [--data <unpacked data root>] [--out <dir>] [--pretty] [--quiet] [--spot <id,id,...>]
//
// Reads the user's own unpacked client (default: ../data/unpacked/data next to the engine) and writes
//   gamedata/quests.json    every quest index -> category, level range, giver / turn-in NPC (+ map position),
//                           prerequisites / chains, repeatability, class gates, objectives (kill / collect / talk /
//                           kill-on-map / clear-map / use-skill / fish ...), rewards (exp, dil, items, choice and
//                           per-repeat variants, warp, title, status ...), quest-item drop rules, dialog flow ids,
//                           the quest-line graph (main story chains per level band), the level guide and the
//                           request (commission) boards.
//   gamedata/dialogs.json   every quest dialog tree (message -> string code -> English text + menu options), all quest
//                           strings (title, journal, diary, progress messages), the common quest messages, every NPC's
//                           generic greeting / name / title / service menu labels, and monster chatter.
// Every asset path in the output is a lower-case data key (relative to the data root, fetch it as /data/<key>) that was
// verified to exist on disk. The run doubles as the validation script: counts, cross references (monster / item / NPC /
// map / location / skill indices) and text coverage are printed and stored under report (exit code 1 on hard failures).
// Format + field documentation: docs/formats/quests.md
//
// The parse* / helper exports are pure (strings / buffers in, plain objects out) so they can move to src/formats/.

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
/** A latin1-decoded string that actually holds EUC-KR/CP949 bytes -> proper text (Korean, curly quotes, arrows). */
export function kr(s) {
  if (!s || !/[\x80-\xff]/.test(s) || !krDecoder) return s;
  const b = new Uint8Array(s.length);
  for (let i = 0; i < s.length; i++) b[i] = s.charCodeAt(i) & 0xff;
  return krDecoder.decode(b);
}
const u8of = (src) => (src instanceof Uint8Array ? src : new Uint8Array(toArrayBuffer(src)));
const textOf = (src) => (typeof src === 'string' ? src : latin1(u8of(src)));
const num = (v, d = 0) => { const x = Number(String(v ?? '').trim()); return Number.isFinite(x) ? x : d; };
const str = (v) => String(v ?? '').trim();
/** "6004/6008/6012" -> [6004, 6008, 6012]; "0" / "" -> [] */
export function splitIds(v) {
  return str(v).split('/').map((s) => s.trim()).filter((s) => /^-?\d+(\.\d+)?$/.test(s)).map(Number).filter((x) => x !== 0);
}
/** like splitIds but keeps 0 (map 0 = Braiken Castle is a real map): "0/7" -> [0, 7] */
export function splitList(v) {
  return str(v).split('/').map((s) => s.trim()).filter((s) => /^-?\d+$/.test(s)).map(Number);
}
/** lines_eu / localisation text -> display text ('\' is the line break; trailing breaks trimmed). */
export function locText(s) {
  if (s == null) return null;
  return String(s).replace(/\\/g, '\n').replace(/\r/g, '').replace(/[ \t]+\n/g, '\n').replace(/^\n+|\s+$/g, '');
}
/**
 * Strip the client's presentation markup (<color=..>, </color>, <font=..>, <center>, <img ..>) -> plain text.
 * Link tags are replaced through nameOf(kind, id) when given ('npc' | 'monster' | 'item'), else kept verbatim.
 */
export function plainText(s, nameOf = null) {
  if (s == null) return null;
  let t = String(s).replace(/<\/?(color|font|center|b|u|i)(=[^>]*)?>/gi, '').replace(/<img[^>]*>/gi, '');
  if (nameOf) {
    t = t.replace(/\[elink\](\d+)\[\/elink\]\s*\[([^\]]*)\]/gi, (_, id, label) => label)
      .replace(/\[([^\]]*)\]\s*\[vlink\](\d+)\[\/vlink\]/gi, (_, label) => label)
      .replace(/\[([nmiv])link\](\d+)\[\/\1link\]/gi, (m, k, id) => nameOf(LINK_KINDS[k.toLowerCase()], +id) ?? m);
  }
  return t.trim();
}

// ------------------------------------------------------------------------------------------------
// script/lines_eu — localisation database (UTF-16LE), full parse (both key tables)
//   u32 nTxt  { u32 len, wchar name[len], u32 n, n x (i32,i32) }        string-table files (namespace, cate)
//   u32 nCsv  { u32 len, wchar name[len], u32 n, n x (i32 col,i32 -1) } localised csv tables / columns
//   u32 nStr  { u32 id, u32 len, wchar text[len] }                       the strings
//   u32 nKeyT { u32 len, wchar "NN|file.txt#cate|code", u32 id }        NN = list.txt namespace (00 NORMAL, 01 QUEST ...)
//   u32 nKeyC { u32 len, wchar "folder#file.csv#col|row", u32 id }      row = 1-based data row (header excluded)
// ------------------------------------------------------------------------------------------------
export function parseLinesEuFull(buf) {
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
  const readKeys = () => { const n = r.u32(); const m = new Map(); for (let i = 0; i < n; i++) { const k = wstr(r.u32()); m.set(k.toLowerCase(), r.u32()); } return m; };
  const txtKeys = readKeys();
  const csvKeys = readKeys();
  return { txtFiles, csvFiles, strings, txtKeys, csvKeys, trailingBytes: r.remaining };
}

// ------------------------------------------------------------------------------------------------
// script/string/**/*.txt — categorised string tables
//   <cate> N [#label]          (optional; tables without it use cate 0)
//   code M [#comment]
//   {
//   text lines...
//   }
//   </cate>
// ------------------------------------------------------------------------------------------------
export function parseCateStringTable(src) {
  const out = new Map(); const labels = new Map();
  let cate = 0, code = null, buf = null, dup = 0;
  for (const raw of textOf(src).split(/\r?\n/)) {
    const line = raw.replace(/\s+$/, '');
    if (buf) {
      if (line.trim() === '}') {
        while (buf.length && !buf[0].trim()) buf.shift();
        while (buf.length && !buf[buf.length - 1].trim()) buf.pop();
        if (!out.has(cate)) out.set(cate, new Map());
        if (out.get(cate).has(code)) dup++;
        out.get(cate).set(code, buf.join('\n'));
        buf = null; code = null;
      } else buf.push(line);
      continue;
    }
    let m;
    if ((m = /^\s*<cate>\s*(-?\d+)\s*(?:#(.*))?$/i.exec(line))) { cate = +m[1]; if (m[2] && m[2].trim()) labels.set(cate, m[2].trim()); continue; }
    if (/^\s*<\/cate>/i.test(line)) continue;
    if ((m = /^\s*code\s+(-?\d+)/i.exec(line))) { code = +m[1]; continue; }
    if (code != null && /^\s*\{/.test(line)) { const rest = line.replace(/^\s*\{/, ''); buf = rest.trim() ? [rest] : []; }
  }
  return { cates: out, labels, dup };
}

// ------------------------------------------------------------------------------------------------
// share/quest/<quest dialog>.csv — one NPC dialog tree per quest
//   row 0 "QuestIndex,<n>" (the file's own quest index; copy-pasted in a few files)
//   header "MessageIndex,StringCode,Menu0..MenuN"; each row: message id, string code (cate = quest), option message ids
// ------------------------------------------------------------------------------------------------
export function parseQuestDialogCsv(src) {
  const rows = parseCSV(textOf(src)).map((r) => (r || []).map((c) => str(c)));
  let quest = null, hi = -1;
  for (let i = 0; i < rows.length; i++) {
    const c0 = rows[i][0]?.toLowerCase();
    if (c0 === 'questindex' && quest === null) quest = num(rows[i][1], null);
    if (c0 === 'messageindex') { hi = i; break; }
  }
  const msgs = []; let bad = 0;
  if (hi >= 0) {
    for (const r of rows.slice(hi + 1)) {
      if (!r.some((c) => c !== '')) continue;
      if (!/^\d+$/.test(r[0]) || !/^\d+$/.test(r[1] ?? '')) { bad++; continue; }
      msgs.push([+r[0], +r[1], r.slice(2).filter((c) => /^\d+$/.test(c)).map(Number).filter((x) => x > 0)]);
    }
  }
  return { quest, messages: msgs, bad, header: hi >= 0 ? rows[hi] : null };
}

// ------------------------------------------------------------------------------------------------
// share/item/item.dat, share/item/itemevent/itemevent.dat — compiled item tables (fixed 565-byte records).
// Only the two fields this builder needs are read: u32 index @128, UTF-16 lines_eu name key @204
// ("item#itemetc.csv#1|5557"; its row points into the csv as it was when localised, so it is resolved through
// lines_eu, never through the current csv row). Full layout: the items research (docs/formats/items.md).
// ------------------------------------------------------------------------------------------------
export const ITEM_DAT_RECORD = 565;
export function parseItemDatNames(buf) {
  const u8 = u8of(buf);
  if (u8.length % ITEM_DAT_RECORD !== 0) return null;
  const dv = new DataView(u8.buffer, u8.byteOffset, u8.byteLength);
  const out = [];
  for (let o = 0; o < u8.length; o += ITEM_DAT_RECORD) {
    const index = dv.getUint32(o + 128, true);
    let e = o + 204; const lim = Math.min(o + ITEM_DAT_RECORD, o + 204 + 256);
    while (e + 1 < lim && (u8[e] | u8[e + 1])) e += 2;
    out.push({ index, key: utf16.decode(u8.subarray(o + 204, e)) });
  }
  return out;
}

// ------------------------------------------------------------------------------------------------
// inline links in quest text: [nlink]npc[/nlink], [mlink]monster[/mlink], [ilink]item[/ilink],
// [elink]npc[/elink][Label] (navigation to an NPC, shown as Label), [Label][vlink]monster[/vlink] (navigation to a monster)
// ------------------------------------------------------------------------------------------------
export const LINK_KINDS = { n: 'npc', m: 'monster', i: 'item', e: 'npcNav', v: 'monsterNav' };
export function extractLinks(text) {
  const out = [];
  const re = /\[([nmiev])link\](\d+)\[\/\1link\]/gi;
  let m;
  while ((m = re.exec(String(text ?? '')))) out.push({ kind: LINK_KINDS[m[1].toLowerCase()], id: +m[2] });
  return out;
}

/**
 * Dialog page navigation (derived from the files; the server script that drove it is not in the client):
 * option o = p + n (n = 1..9) on page p opens page p + n*10 when the tree has it, else (entry pages only, p % 1000 == 0)
 * p + n*100, else the dialog closes.
 * (10000 -[10001]-> 10010 -[10011]-> 10020 ...; 10000 -[10001]-> 10100 / -[10002]-> 10200; 1000 -[1001]-> 1100)
 * msgs: Map(page -> [page, stringCode, options]) of the pages that have text.
 */
export function nextPage(msgs, p, o) {
  const n = o - p;
  if (!(n > 0 && n < 10)) return undefined;
  if (msgs.has(p + n * 10)) return p + n * 10;
  if (p % 1000 === 0 && msgs.has(p + n * 100)) return p + n * 100;
  return undefined;
}

import { parseRewardText } from '../src/systems/quests/reward-text.js';
export { parseRewardText };
export const normName = (s) => String(s ?? '').toLowerCase().replace(/<[^>]*>/g, '').replace(/[^a-z0-9]+/g, '');

// ================================================================================================
// constants: meanings of the code columns (see docs/formats/quests.md for confidence)
// ================================================================================================
/** questtable_renew Type */
export const RENEW_TYPE = { 1: 'normal', 2: 'daily', 3: 'main', 5: 'request', 6: 'weekday', 7: 'ticket', 10: 'growth', 11: 'wanted' };
/** script/quest/quest.csv Type (quest-log tab) */
export const CLIENT_TYPE = { 0: 'normal', 1: 'request', 2: 'normal', 4: 'repeat', 5: 'main', 6: 'event', 7: 'event', 8: 'weekly', 9: 'growth' };
/** questtable_renew Rank_1 (objective kind of Index_k) and Rank_2 (kind of EX_Index_k) */
export const OBJ_KIND = {
  1: 'kill',        // Index = monster index (slash list = any of them)
  2: 'collect',     // Index = item index (dropped by the monsters in questdropitem.csv, or given by an NPC)
  3: 'talk',        // Index = npc index (talk to that NPC; Index_Dialog = the message it shows)
  4: 'killOnMap',   // Index = map index (kill any monster on that map; slash list = any of those maps)
  5: 'instant',     // no objective: the quest completes at the NPC right away (teleports, services)
  7: 'exchange',    // no objective: repeatable exchange / ticket issuance at the NPC (per-repeat reward variants)
  8: 'clearMap',    // Index = map index of a dungeon / battlefield (clear it N times)
  9: 'useSkill',    // Index = skill index (use one of those skills N times; Meister specialisation)
  10: 'fish',       // no Index: catch N fish (count = quest.csv Object MaxCount)
};
/** NPC job types that list quests (npc.csv JobType -> JobIndex is a quest index) */
export const QUEST_JOBS = { 1: 'QUEST', 57: 'DAILY_QUEST_STD', 106: 'QUEST_MAIN', 114: 'MISSION_TITILE' };
/** NPC job types whose JobIndex is a request-board set (share/request_quest/office_set.csv) */
export const OFFICE_JOBS = { 18: 'REQUEST_QUEST', 54: 'DAILY_REQUEST_QUEST' };
/** Dialog message ids with a fixed role (per-quest files follow these conventions). */
export const FLOW_IDS = {
  offer: [10000], accepted: [10100, 10010], declined: [10200, 10020], lowLevel: [10300, 150],
  progressAtGiver: [11000], progress: [20000], complete: [30000], title: [11], journal: [12], diary: [13], alarm: [14],
  partTitle: [1], partDesc: [2], completedNote: [5],
};

// ================================================================================================
// Node side: the builder
// ================================================================================================
const HERE = path.dirname(fileURLToPath(import.meta.url));
const ENGINE = path.resolve(HERE, '..');
const argv = process.argv.slice(2);
const arg = (k) => { const i = argv.indexOf(k); return i >= 0 ? argv[i + 1] : null; };
const DATA = path.resolve(arg('--data') || process.env.DEKARON_DATA || path.resolve(ENGINE, '../data/unpacked/data'));
const OUTDIR = path.resolve(arg('--out') || path.join(ENGINE, 'gamedata'));
const PRETTY = argv.includes('--pretty');
const QUIET = argv.includes('--quiet');
const SPOT = (arg('--spot') || '').split(',').filter(Boolean).map(Number);
const log = (...a) => { if (!QUIET) console.log(...a); };
const problems = { hard: [], soft: [] };
const hard = (m) => problems.hard.push(m);
const soft = (m) => problems.soft.push(m);

const readRel = (rel) => fs.readFileSync(path.join(DATA, rel));
const readText = (rel) => latin1(readRel(rel));
const existsRel = (rel) => { try { return fs.statSync(path.join(DATA, rel)).isFile(); } catch { return false; } };

// ---- file index (lower-case data keys) for existence checks ------------------------------------
const FILES = new Set();
function indexDir(sub) {
  const root = path.join(DATA, sub);
  if (!fs.existsSync(root)) return;
  for (const d of fs.readdirSync(root, { recursive: true, withFileTypes: true })) {
    if (!d.isFile()) continue;
    FILES.add(path.relative(DATA, path.join(d.parentPath ?? d.path, d.name)).replace(/\\/g, '/').toLowerCase());
  }
}
const has = (k) => !!k && FILES.has(k);

/** csv -> { header, rows (data rows after the header, ALL of them, so rows[i] is lines_eu row i+1) } */
function csvTable(text) {
  const all = parseCSV(text).map((r) => (r || []).map((c) => str(c)));
  return { header: (all[0] || []).map((h) => h.trim()), rows: all.slice(1) };
}
function loadCsv(rel) { return csvTable(readText(rel)); }
export const SPECIFIC_PERIOD_SCHEDULE = 'share/quest/specificperiodschedule.csv';
/** Older Global packs can omit this event calendar. Other read errors remain
 * fatal: unreadable/corrupt installation data must not masquerade as absence. */
export function loadSpecificPeriodSchedule({ dataRoot = DATA, readFile = fs.readFileSync, warn = soft } = {}) {
  let bytes;
  try { bytes = readFile(path.join(dataRoot, SPECIFIC_PERIOD_SCHEDULE)); }
  catch (error) {
    if (error.code !== 'ENOENT') throw error;
    warn(`${SPECIFIC_PERIOD_SCHEDULE}: optional event calendar is absent in this client; dated Wanted quests remain unavailable until calendar data is supplied.`);
    return { header: [], rows: [], missing: true };
  }
  return { ...csvTable(latin1(bytes)), missing: false };
}
function colIndex(header) { const m = {}; header.forEach((h, i) => { if (!(h in m)) m[h] = i; }); return m; }
const isNumCell = (v) => /^-?\d+(\.\d+)?$/.test(str(v));

// ================================================================================================
function main() {
  const t0 = Date.now();
  if (!fs.existsSync(DATA)) { console.error(`data root not found: ${DATA}`); process.exit(2); }
  log(`data root: ${DATA}`);
  for (const sub of ['share/quest', 'share/request_quest', 'script', 'sound', 'mesh/effect', 'anim/effect/quest', 'texture/effect/ui', 'texture/ui/game', 'texturepack/effect/ui', 'property/effect']) indexDir(sub);
  log(`indexed ${FILES.size} files`);

  // ---------------------------------------------------------------- localisation
  const LE = parseLinesEuFull(readRel('script/lines_eu'));
  if (LE.trailingBytes) hard(`lines_eu: ${LE.trailingBytes} trailing bytes`);
  // txt keys without their namespace prefix: "file.txt#cate|code" -> id
  const LT = new Map();
  for (const [k, id] of LE.txtKeys) { const p = k.indexOf('|'); LT.set(k.slice(p + 1), id); }
  const ltxt = (file, cate, code) => { const id = LT.get(`${file.toLowerCase()}#${cate}|${code}`); return id !== undefined ? locText(LE.strings.get(id)) : null; };
  const lcsv = (table, col, row) => { const id = LE.csvKeys.get(`${table.toLowerCase()}#${col}|${row}`); return id !== undefined ? locText(LE.strings.get(id)) : null; };
  log(`lines_eu: ${LE.strings.size} strings, ${LE.txtKeys.size} txt keys, ${LE.csvKeys.size} csv keys`);

  // ---------------------------------------------------------------- quest string tables (list.txt order, QUEST namespace)
  const listTxt = readText('script/string/list.txt').split(/\r?\n/).map((l) => l.trim()).filter((l) => l && !l.startsWith('#'));
  const questFiles = listTxt.filter((l) => /^QUEST,/i.test(l)).map((l) => l.split(',')[1].trim().replace(/\\/g, '/'));
  const qs = new Map(); // cate -> Map(code -> text)
  const qsLabel = new Map();
  const strStats = { files: 0, strings: 0, fromLinesEu: 0, fromRawDecoded: 0, overridden: 0, stillKorean: 0 };
  for (const f of questFiles) {
    const rel = `script/${f}`.toLowerCase();
    if (!existsRel(rel)) { soft(`list.txt quest table missing: ${rel}`); continue; }
    const base = rel.slice(rel.lastIndexOf('/') + 1);
    const t = parseCateStringTable(readRel(rel));
    strStats.files++;
    for (const [c, lbl] of t.labels) if (!qsLabel.has(c)) qsLabel.set(c, kr(lbl));
    for (const [cate, codes] of t.cates) {
      if (!qs.has(cate)) qs.set(cate, new Map());
      const m = qs.get(cate);
      for (const [code, rawText] of codes) {
        const loc = ltxt(base, cate, code);
        const text = loc ?? kr(rawText).replace(/^\n+|\s+$/g, '');
        if (loc != null) strStats.fromLinesEu++; else strStats.fromRawDecoded++;
        if (m.has(code)) strStats.overridden++;
        m.set(code, text);
        strStats.strings++;
      }
    }
    // lines_eu entries of this file with no raw counterpart
    const prefix = `${base}#`;
    for (const [k, id] of LT) {
      if (!k.startsWith(prefix)) continue;
      const mm = /#(-?\d+)\|(-?\d+)$/.exec(k); if (!mm) continue;
      const cate = +mm[1], code = +mm[2];
      if (!qs.has(cate)) qs.set(cate, new Map());
      if (!qs.get(cate).has(code)) { qs.get(cate).set(code, locText(LE.strings.get(id))); strStats.fromLinesEu++; strStats.strings++; }
    }
  }
  for (const m of qs.values()) for (const v of m.values()) if (/[가-힣]/.test(v)) strStats.stillKorean++;
  const qstr = (q, code) => qs.get(q)?.get(code) ?? null;
  log(`quest strings: ${strStats.strings} in ${qs.size} cates from ${strStats.files} tables (lines_eu ${strStats.fromLinesEu}, raw ${strStats.fromRawDecoded}, Korean-only ${strStats.stillKorean})`);

  // objective strings (QUEST_OBJECT namespace): cate = quest, code = objective slot
  const objTxt = new Map();
  {
    const rel = 'script/string/quest/stringtable_quest_objectstring.txt';
    const t = parseCateStringTable(readRel(rel));
    for (const [cate, codes] of t.cates) for (const [code, raw] of codes) {
      const loc = ltxt('stringtable_quest_objectstring.txt', cate, code);
      if (!objTxt.has(cate)) objTxt.set(cate, new Map());
      objTxt.get(cate).set(code, loc ?? kr(raw).trim());
    }
  }

  // ---------------------------------------------------------------- reference tables
  const gd = process.env.DEKARON_GAMEDATA || path.join(ENGINE, 'gamedata');
  const npcsDb = JSON.parse(fs.readFileSync(path.join(gd, 'npcs.json'), 'utf8'));
  const monDb = JSON.parse(fs.readFileSync(path.join(gd, 'monsters.json'), 'utf8'));
  const NPC = npcsDb.npcs, MON = monDb.monsters;
  const npcPos = new Map(); // npc -> [{map, x, y, dir}]
  for (const [mi, p] of Object.entries(npcsDb.placements || {})) {
    for (const r of p.rows || []) {
      const [npc, x, y, dir] = r;
      if (!npcPos.has(npc)) npcPos.set(npc, []);
      npcPos.get(npc).push({ map: +mi, x, y, dir });
    }
  }
  // maps
  const maps = new Map();
  { const t = loadCsv('share/maplist.csv'); const c = colIndex(t.header);
    t.rows.forEach((r, i) => { if (!isNumCell(r[0]) || !r[c.MapFile]) return; maps.set(+r[0], lcsv('share#maplist.csv', 1, i + 1) || kr(r[1])); }); }
  // items: the compiled tables (item.dat + itemevent.dat: index + lines_eu name key per record) are authoritative,
  // the csv tables add the few rows the .dat lacks
  const items = new Map(); const itemByName = new Map();
  const itemLocAgree = [0, 0]; const itemSrc = { dat: 0, csv: 0 };
  for (const rel of ['share/item/item.dat', 'share/item/itemevent/itemevent.dat']) {
    if (!existsRel(rel)) { soft(`missing ${rel}`); continue; }
    const recs = parseItemDatNames(readRel(rel));
    if (!recs) { hard(`${rel}: size not a multiple of ${ITEM_DAT_RECORD}`); continue; }
    for (const { index, key } of recs) {
      if (items.has(index)) continue;
      const id = LE.csvKeys.get(key.toLowerCase());
      items.set(index, { name: id !== undefined ? locText(LE.strings.get(id)) : null, key, src: rel.endsWith('itemevent.dat') ? 'itemevent.dat' : 'item.dat' });
      itemSrc.dat++;
    }
  }
  const ITEM_TABLES = ['itemweapon.csv', 'itemarmor.csv', 'itemaccessory.csv', 'itemetc.csv', 'itemetc_socket.csv', 'itemcash.csv', 'itemmileage.csv', 'itemevent/etcevent.csv', 'itemevent/cashevent.csv', 'itemevent/accessoryevent.csv'];
  for (const f of ITEM_TABLES) {
    if (!existsRel(`share/item/${f}`)) continue;
    const t = loadCsv(`share/item/${f}`);
    t.rows.forEach((r) => {
      if (!/^\d+$/.test(r[0] || '')) return;
      const idx = +r[0];
      const csvName = kr(r[1]);
      const e = items.get(idx);
      if (e) { if (e.name != null) { itemLocAgree[0]++; if (normName(e.name) === normName(csvName)) itemLocAgree[1]++; } else e.name = csvName; return; }
      items.set(idx, { name: csvName, src: f }); itemSrc.csv++;
    });
  }
  for (const [idx, e] of [...items].sort((a, b) => a[0] - b[0])) { const nk = normName(e.name); if (nk && !itemByName.has(nk)) itemByName.set(nk, idx); }
  log(`items: ${items.size} (${itemSrc.dat} from item.dat/itemevent.dat, ${itemSrc.csv} csv-only; .dat name == csv name for ${itemLocAgree[1]}/${itemLocAgree[0]})`);
  // warp locations
  const locations = new Map();
  { const t = loadCsv('share/arrange/location.csv');
    t.rows.forEach((r, i) => { if (!/^\d+$/.test(r[0] || '')) return; locations.set(+r[0], { name: lcsv('arrange#location.csv', 1, i + 1) || kr(r[1]), map: num(r[2]), x: num(r[3]), y: num(r[4]), dir: num(r[5]) }); }); }
  // titles, statuses, skills
  const titles = new Map();
  { const t = loadCsv('share/pc/title/title_base.csv'); t.rows.forEach((r, i) => { if (/^\d+$/.test(r[0] || '')) titles.set(+r[0], lcsv('title#title_base.csv', 1, i + 1) || kr(r[1])); }); }
  const statuses = new Map();
  { const t = loadCsv('share/skill/status.csv'); t.rows.forEach((r, i) => { if (/^\d+$/.test(r[0] || '')) statuses.set(+r[0], (lcsv('skill#status.csv', 6, i + 1) || kr(r[6]) || '').split('\n')[0]); }); }
  const skills = new Map();
  for (const f of fs.readdirSync(path.join(DATA, 'script/skilldesc'))) {
    if (!/\.csv$/i.test(f) || /^list_skill/i.test(f)) continue;
    const t = loadCsv(`script/skilldesc/${f}`);
    t.rows.forEach((r, i) => { if (!/^\d+$/.test(r[0] || '')) return; const idx = +r[0]; if (!skills.has(idx)) skills.set(idx, { name: lcsv(`skilldesc#${f.toLowerCase()}`, 2, i + 1) || kr(r[2]), class: f.replace(/\.csv$/i, '').toLowerCase() }); });
  }
  const npcByName = new Map(); for (const [id, n] of Object.entries(NPC)) { const k = normName(n.name); if (k && !npcByName.has(k)) npcByName.set(k, +id); }
  const monByName = new Map(); for (const [id, m] of Object.entries(MON)) { const k = normName(m.name); if (k && !monByName.has(k)) monByName.set(k, +id); }
  log(`refs: ${Object.keys(NPC).length} npcs, ${Object.keys(MON).length} monsters, ${maps.size} maps, ${locations.size} locations, ${titles.size} titles, ${statuses.size} statuses, ${skills.size} skills`);

  // ---------------------------------------------------------------- quest tables
  const T = {};
  const byId = (t, col = 0, { allowFrac = false } = {}) => {
    const m = new Map(); let dup = 0;
    t.rows.forEach((r, i) => {
      const k = str(r[col]);
      if (!(allowFrac ? /^\d+(\.\d+)?$/ : /^\d+$/).test(k)) return;
      if (m.has(k)) { dup++; return; }
      m.set(k, { r, row: i + 1 });
    });
    return { map: m, dup };
  };
  T.client = loadCsv('script/quest/quest.csv');
  T.table = loadCsv('share/quest/questtable.csv');
  T.renew = loadCsv('share/quest/questtable_renew.csv');
  T.reward = loadCsv('share/quest/quest_rewardlist.csv');
  T.drop = loadCsv('share/quest/questdropitem.csv');
  T.objstr = loadCsv('share/quest/quest_objectstring.csv');
  T.files = loadCsv('share/quest/questfilelist.csv');
  T.pfiles = loadCsv('share/quest/periodquestfilelist.csv');
  T.sched = loadSpecificPeriodSchedule();
  T.notice = loadCsv('script/questnotice.csv');
  T.officeSet = loadCsv('share/request_quest/office_set.csv');
  T.office = loadCsv('share/request_quest/quest_office.csv');
  T.common = loadCsv('script/quest/quest_commonstring.csv');
  const C = {}; for (const k of Object.keys(T)) C[k] = colIndex(T[k].header);
  const I = {
    client: byId(T.client), table: byId(T.table), renew: byId(T.renew, 1), reward: byId(T.reward, 0, { allowFrac: true }),
    drop: byId(T.drop), objstr: byId(T.objstr), files: byId(T.files), pfiles: byId(T.pfiles), sched: byId(T.sched),
  };
  for (const [k, v] of Object.entries(I)) if (v.dup) soft(`${k}: ${v.dup} duplicate index rows (first kept)`);
  const get = (tab, row, name) => row[C[tab][name]];
  log(`tables: quest.csv ${I.client.map.size}, questtable ${I.table.map.size}, renew ${I.renew.map.size}, rewardlist ${I.reward.map.size} rows, drops ${I.drop.map.size}, objectstrings ${I.objstr.map.size}, dialog files listed ${I.files.map.size}+${I.pfiles.map.size}`);

  // sub-reward rows "201.01" grouped under their quest
  const rewardRows = new Map(); // quest -> { main, subs: Map(id -> row) }
  for (const [k, { r, row }] of I.reward.map) {
    const q = +k.split('.')[0];
    if (!rewardRows.has(q)) rewardRows.set(q, { main: null, subs: new Map() });
    if (k.includes('.')) rewardRows.get(q).subs.set(k, { r, row }); else rewardRows.get(q).main = { r, row };
  }

  // ---------------------------------------------------------------- dialog files
  const questDir = path.join(DATA, 'share/quest');
  const onDisk = new Map(fs.readdirSync(questDir).filter((f) => f.toLowerCase().endsWith('.csv')).map((f) => [f.toLowerCase(), f]));
  const TABLE_FILES = new Set(['questtable.csv', 'questtable_renew.csv', 'quest_rewardlist.csv', 'questdropitem.csv', 'quest_objectstring.csv', 'questfilelist.csv', 'periodquestfilelist.csv', 'specificperiodschedule.csv']);
  const listed = new Map(); // quest -> { key, period }
  for (const [k, { r }] of I.files.map) listed.set(+k, { file: str(r[1]).toLowerCase(), period: null });
  for (const [k, { r }] of I.pfiles.map) { const q = +k; const e = { file: str(r[2]).toLowerCase(), period: num(r[1]) }; if (listed.has(q)) { if (listed.get(q).file !== e.file) soft(`quest ${q} listed in both file lists with different files`); listed.get(q).period = e.period; } else listed.set(q, e); }
  const dialogs = new Map(); // quest -> { file, listed, header, messages, alt: [] }
  const dialogStats = { listed: listed.size, listedMissing: [], parsed: 0, unlisted: 0, unlistedAttached: 0, unlistedPrimary: 0, headerMismatch: [], badRows: 0 };
  for (const [q, e] of listed) {
    if (!onDisk.has(e.file)) { dialogStats.listedMissing.push(e.file); hard(`listed dialog file missing: share/quest/${e.file}`); continue; }
    const d = parseQuestDialogCsv(readRel(`share/quest/${onDisk.get(e.file)}`));
    dialogStats.parsed++; dialogStats.badRows += d.bad;
    if (d.quest !== q) dialogStats.headerMismatch.push([q, d.quest, e.file]);
    dialogs.set(q, { file: `share/quest/${e.file}`, listed: true, header: d.quest, messages: d.messages, period: e.period, alt: [] });
    // Lane 37: periodquestfilelist QuestIndex typos (e.g. 8489 -> file header 9489). Also attach the
    // dialog tree under the file's own QuestIndex so the titled catalog row gets the tree. Evidence:
    // share/quest/quest_09489_thanksgiving_huntingdummy.csv header QuestIndex=9489 while list says 8489.
    if (d.quest != null && d.quest !== q && !dialogs.has(d.quest)) {
      dialogs.set(d.quest, { file: `share/quest/${e.file}`, listed: true, header: d.quest, messages: d.messages, period: e.period, alt: [], repairedFromListed: q });
    }
  }
  const listedFiles = new Set([...listed.values()].map((e) => e.file));
  for (const [lower] of onDisk) {
    if (TABLE_FILES.has(lower) || listedFiles.has(lower)) continue;
    const d = parseQuestDialogCsv(readRel(`share/quest/${onDisk.get(lower)}`));
    if (!d.messages.length && d.quest === null) continue;
    dialogStats.unlisted++;
    const q = d.quest ?? num((/_(\d+)_/.exec(lower) || [])[1], null);
    if (q === null) continue;
    if (dialogs.has(q)) { dialogs.get(q).alt.push({ file: `share/quest/${lower}`, messages: d.messages }); dialogStats.unlistedAttached++; }
    else { dialogs.set(q, { file: `share/quest/${lower}`, listed: false, header: d.quest, messages: d.messages, alt: [] }); dialogStats.unlistedPrimary++; }
  }
  log(`dialog files: ${dialogStats.parsed} listed parsed, ${dialogStats.unlisted} unlisted (${dialogStats.unlistedAttached} attached as alternatives, ${dialogStats.unlistedPrimary} as the only tree of their quest), header mismatches ${dialogStats.headerMismatch.length}`);

  // ---------------------------------------------------------------- NPC quest menus
  const offeredBy = new Map(); // quest -> [[npc, jobType]]
  const officeSets = new Map(); // `${jt}:${ji}` -> {name, quests}
  T.officeSet.rows.forEach((r, i) => {
    if (!isNumCell(r[1])) return;
    const quests = []; for (let k = 1; k <= 15; k++) { const v = num(get('officeSet', r, `Quest_Index${k}`)); if (v) quests.push(v); }
    officeSets.set(`${num(r[1])}:${num(r[2])}`, { name: lcsv('request_quest#office_set.csv', 0, i + 1) || kr(r[0]), jobType: num(r[1]), jobIndex: num(r[2]), count: num(r[3]), quests });
  });
  const officeNpcs = new Map();
  for (const [id, n] of Object.entries(NPC)) {
    for (const [jt, ji] of n.jobs || []) {
      if (QUEST_JOBS[jt]) { if (!offeredBy.has(ji)) offeredBy.set(ji, []); offeredBy.get(ji).push([+id, jt]); }
      if (OFFICE_JOBS[jt]) {
        const set = officeSets.get(`${jt}:${ji}`);
        if (!set) { soft(`npc ${id}: office job ${jt}:${ji} has no office_set row`); continue; }
        if (!officeNpcs.has(`${jt}:${ji}`)) officeNpcs.set(`${jt}:${ji}`, []);
        officeNpcs.get(`${jt}:${ji}`).push(+id);
        for (const q of set.quests) { if (!offeredBy.has(q)) offeredBy.set(q, []); offeredBy.get(q).push([+id, jt]); }
      }
    }
  }

  // ---------------------------------------------------------------- quest id universe
  const ids = new Set();
  for (const m of [I.client.map, I.table.map, I.renew.map, I.objstr.map]) for (const k of m.keys()) ids.add(+k);
  for (const q of rewardRows.keys()) ids.add(q);
  for (const q of listed.keys()) ids.add(q);
  for (const q of offeredBy.keys()) if (qs.has(q) || dialogs.has(q)) ids.add(q);
  // quests only named by a request board (office_set) or the level guide, when the client has their text / dialog
  for (const s of officeSets.values()) for (const q of s.quests) if (qs.has(q) || dialogs.has(q)) ids.add(q);
  T.notice.rows.forEach((r) => { const q = num(r[5]); if (q && (qs.has(q) || dialogs.has(q))) ids.add(q); });
  const sorted = [...ids].sort((a, b) => a - b);

  // ---------------------------------------------------------------- helpers for the quest records
  const npcRef = (npc, preferMaps = []) => {
    if (!npc) return null;
    const n = NPC[npc];
    const places = npcPos.get(npc) || [];
    const p = places.find((x) => preferMaps.includes(x.map)) || places[0] || null;
    const o = { npc, name: n ? n.name : null };
    if (p) { o.map = p.map; o.pos = [Math.round(p.x * 100) / 100, Math.round(p.y * 100) / 100]; o.dir = p.dir; if (places.length > 1) o.alsoOn = [...new Set(places.map((x) => x.map))].filter((m) => m !== p.map); }
    else { o.unplaced = true; if (preferMaps.length) o.map = preferMaps[0]; } // server-spawned (event) NPC: no placement file
    if (!n) o.missing = true;
    return o;
  };
  const objectLabel = (q, slot) => {
    const o = I.objstr.map.get(String(q));
    if (o) {
      const loc = lcsv('quest#quest_objectstring.csv', 3 + slot, o.row);
      const v = loc ?? kr(get('objstr', o.r, `Object_${slot}`));
      if (v && v !== '0') return v;
    }
    const t = objTxt.get(q)?.get(slot);
    if (t) return t.replace(/<COUNT\d*>\s*\/\s*<MAX_COUNT\d*>/gi, '').replace(/\s+$/, '');
    return null;
  };
  const progressMsgs = (q) => { // slot -> message code, parsed from <COUNTk> placeholders in codes 200..499
    const out = {}; const m = qs.get(q); if (!m) return out;
    for (const [code, text] of m) {
      if (code < 200 || code >= 500) continue;
      const mm = /<COUNT(\d)>/.exec(text || '');
      if (mm && !(mm[1] in out)) out[mm[1]] = code;
    }
    return out;
  };
  const locRef = (loc) => { const l = locations.get(loc); return l ? { loc, name: l.name, map: l.map, pos: [l.x, l.y], dir: l.dir } : { loc, missing: true }; };

  const REWARD_MAPPED = new Set(['QuestIndex', 'ParentIndex', 'NextIndex', 'Level_Min', 'Level_Max', 'Money_Min', 'Money_Max', 'Take_Money', 'ExpItem_Check', 'ExpItem_Index', 'ExpItem_Take_Check', 'ExpItem_Give_Rate', 'Exp_Min', 'Exp_Max', 'Class_Check', 'Class_Index', 'SubNo_Check', 'Repeat_Count', 'String_No', 'Sel_Reward_On/Off', 'Sel_No', 'Sel_Reward_Result', 'Object_No_On/off', 'Object_No', 'Item_Limit', 'Limit_Time', 'Warp', 'Status', 'Status_T', 'Title', 'Take_Title', 'Quest_Take', 'Royal_Point', 'Adv_Point', 'Awaken_Check', 'Awakening', 'Meister_Check', 'Meister_Grade', 'Meister_Type', 'Item_Option',
    ...Array.from({ length: 10 }, (_, k) => [`Item_Index_${k + 1}`, `Item_Socket_${k + 1}`, `Item_Count_${k + 1}`, `Item_Rate_${k + 1}`, `Take_Index_${k + 1}`, `Take_Count_${k + 1}`, `Take_Rate_${k + 1}`]).flat()]);
  const rawOf = (tab, r, mapped) => {
    const o = {};
    T[tab].header.forEach((h, i) => { if (!mapped.has(h) && h && r[i] !== undefined && r[i] !== '' && r[i] !== '0' && r[i] !== 'FALSE') o[h] = isNumCell(r[i]) ? +r[i] : r[i]; });
    return Object.keys(o).length ? o : undefined;
  };
  const refs = { monster: new Map(), item: new Map(), npc: new Map(), map: new Map(), skill: new Map(), location: new Map(), title: new Map(), status: new Map(), quest: new Map() };
  const useRef = (kind, id, where) => { if (!id) return; if (!refs[kind].has(id)) refs[kind].set(id, where); };

  function rewardOf(r, where, qlv) {
    const g = (n) => get('reward', r, n);
    const o = {};
    const rl = [num(g('Level_Min')), num(g('Level_Max'))];
    if (!qlv || rl[0] !== qlv[0] || rl[1] !== qlv[1]) o.level = rl;
    const exp = [num(g('Exp_Min')), num(g('Exp_Max'))];
    if (exp[0] || exp[1]) o.exp = exp[0] === exp[1] ? exp[0] : exp;
    const dil = [num(g('Money_Min')), num(g('Money_Max'))];
    if (dil[0] || dil[1]) o.dil = dil[0] === dil[1] ? dil[0] : dil;
    const itemsOut = [];
    for (let k = 1; k <= 10; k++) {
      const ids2 = splitIds(g(`Item_Index_${k}`)); if (!ids2.length) continue;
      // Scan fix A (SCAN-B I4): an explicit Item_Count 0 is Global data (only quest 5003, quest_rewardlist.csv:605, item 6008),
      // not "1". The decompile only has the Quest_RewardList loader/provider (no count-0 rule), so the row grants nothing:
      // it is kept as zeroCount for traceability and not handed out. An EMPTY cell still defaults to 1.
      const rawCount = String(g(`Item_Count_${k}`) ?? '').trim();
      if (rawCount !== '' && num(rawCount) === 0) { (o.zeroCountItems ||= []).push(ids2.length === 1 ? ids2[0] : ids2); continue; }
      const it = { item: ids2.length === 1 ? ids2[0] : ids2, count: num(rawCount) || 1 };
      if (num(g(`Item_Socket_${k}`))) it.sockets = num(g(`Item_Socket_${k}`));
      if (num(g(`Item_Rate_${k}`))) it.chance = num(g(`Item_Rate_${k}`)) / 100000;
      for (const x of ids2) useRef('item', x, where);
      itemsOut.push(it);
    }
    if (itemsOut.length) o.items = itemsOut;
    const take = [];
    for (let k = 1; k <= 10; k++) {
      const ids2 = splitIds(g(`Take_Index_${k}`)); if (!ids2.length) continue;
      const it = { item: ids2.length === 1 ? ids2[0] : ids2, count: num(g(`Take_Count_${k}`)) || 1 };
      if (num(g(`Take_Rate_${k}`))) it.chance = num(g(`Take_Rate_${k}`)) / 100000;
      for (const x of ids2) useRef('item', x, where);
      take.push(it);
    }
    if (take.length) o.take = take;
    if (num(g('Take_Money'))) o.takeDil = num(g('Take_Money'));
    if (num(g('ExpItem_Check'))) { o.expBonus = { item: num(g('ExpItem_Index')), rate: num(g('ExpItem_Give_Rate')) / 100000, consume: num(g('ExpItem_Take_Check')) === 1 }; useRef('item', o.expBonus.item, where); }
    if (num(g('Adv_Point'))) o.adv = num(g('Adv_Point'));
    if (num(g('Royal_Point'))) o.royal = num(g('Royal_Point'));
    if (num(g('Title'))) { o.title = num(g('Title')); o.titleName = titles.get(o.title) ?? null; useRef('title', o.title, where); }
    if (num(g('Take_Title'))) { o.takeTitle = num(g('Take_Title')); useRef('title', o.takeTitle, where); }
    if (num(g('Warp'))) { o.warp = locRef(num(g('Warp'))); useRef('location', o.warp.loc, where); }
    if (num(g('Status'))) { o.status = { id: num(g('Status')), seconds: num(g('Status_T')), name: statuses.get(num(g('Status'))) ?? null }; useRef('status', o.status.id, where); }
    if (num(g('Item_Limit'))) { o.timedItem = { item: num(g('Item_Limit')), seconds: num(g('Limit_Time')) }; useRef('item', o.timedItem.item, where); }
    if (num(g('Quest_Take'))) { o.removeQuest = num(g('Quest_Take')); useRef('quest', o.removeQuest, where); }
    if (num(g('Awaken_Check')) || num(g('Awakening'))) o.awakening = num(g('Awakening'));
    if (num(g('Meister_Check')) || num(g('Meister_Grade')) || num(g('Meister_Type'))) o.meister = { grade: num(g('Meister_Grade')), type: num(g('Meister_Type')) };
    if (num(g('Item_Option'))) o.itemOption = num(g('Item_Option'));
    if (num(g('Class_Check'))) o.classIndex = num(g('Class_Index'));
    const raw = rawOf('reward', r, REWARD_MAPPED); if (raw) o.raw = raw;
    return o;
  }

  const RENEW_MAPPED = new Set(['No', 'QuestIndex', 'ParentIndex', 'Type', 'Rank_1', 'Rank_2', 'Code', 'Pre_Index', 'Going_Index', 'Min_Level', 'Max_Level', 'RepeatCount', 'S_npc', 'E_npc', 'S_Map', 'E_Map', 'Condition_Check', 'N_Day', 'Quest_Reset', 'Map_Check', 'Class_Check', 'Class_No', 'Complete_Count', 'Apply_GiveItem_OnOff', 'N_DIL', 'N_Item_Not_Dialog', 'Extent_Check', 'Extent_Index_Min', 'Extent_Index_Max', 'Call_Mon_Index', 'Call_Mon_Count', 'Call_MapIndex', 'Call_X', 'Call_Y', 'N_Status', 'N_Level', 'Awaken_Check', 'Meister_Check',
    ...Array.from({ length: 10 }, (_, k) => [`N_Item_Index_${k + 1}`, `N_Item_Count_${k + 1}`, `Index_${k + 1}`, `Index_Count_${k + 1}`, `Index_Succ_Count_${k + 1}`, `Index_Rate_${k + 1}`, `Index_Object_Number_${k + 1}`, `N_Item_Check_${k + 1}`, `N_Item_Check_Count_${k + 1}`, `Index_Dialog_${k + 1}`, `EX_Index_${k + 1}`, `EX_Index_Count_${k + 1}`, `Ex_Index_Succ_Count_${k + 1}`, `EX_Index_Rate_${k + 1}`, `Ex_Index_Object_Number_${k + 1}`, `Ex_N_Item_Check_${k + 1}`, `Ex_N_Item_Check_Count_${k + 1}`, `Ex_Index_Dialog_${k + 1}`]).flat()]);
  const CLIENT_MAPPED = new Set(['QuestIndex', 'ParentIndex', 'QuestTitleCode', 'QuestBookCode', 'QuestDiaryCode', 'Type', 'Level', 'Quest_MapIndex', 'P_QuestIndex', 'Level_Min', 'Level_Max', 'S_npc', 'E_npc', 'Notice',
    ...Array.from({ length: 10 }, (_, k) => [`Object_${k}_Enable`, `Object_${k}_MaxCount`]).flat()]);

  const targetRef = (kind, id, where) => {
    const o = { id };
    if (kind === 'kill') { o.name = MON[id]?.name ?? null; useRef('monster', id, where); }
    else if (kind === 'collect') { o.name = items.get(id)?.name ?? null; useRef('item', id, where); }
    else if (kind === 'talk') { o.name = NPC[id]?.name ?? null; useRef('npc', id, where); }
    else if (kind === 'killOnMap' || kind === 'clearMap') { o.name = maps.get(id) ?? null; useRef('map', id, where); }
    else if (kind === 'useSkill') { o.name = skills.get(id)?.name ?? null; useRef('skill', id, where); }
    return o;
  };

  // monster name -> ids (several monsters share a name); prefer the one spawned on the quest's map
  const monMaps = new Map();
  for (const [mi, s] of Object.entries(monDb.spawns || {})) for (const r of s.rows || []) { if (!monMaps.has(r[0])) monMaps.set(r[0], new Set()); monMaps.get(r[0]).add(+mi); }
  const monNames = new Map();
  for (const [id, m] of Object.entries(MON)) { const k = normName(m.name); if (!k) continue; if (!monNames.has(k)) monNames.set(k, []); monNames.get(k).push(+id); }
  const nameVariants = (s) => {
    const k = normName(s); const out = [k];
    if (k.endsWith('men')) out.push(k.slice(0, -3) + 'man');
    if (k.endsWith('ies')) out.push(k.slice(0, -3) + 'y');
    if (k.endsWith('es')) out.push(k.slice(0, -2));
    if (k.endsWith('s')) out.push(k.slice(0, -1));
    return out.filter(Boolean);
  };
  const findMonster = (name, map) => {
    for (const k of nameVariants(name)) {
      const c = monNames.get(k); if (!c) continue;
      const onMap = map !== undefined ? c.filter((x) => monMaps.get(x)?.has(map)) : [];
      return onMap.length ? onMap : [c.find((x) => monMaps.has(x)) ?? c[0]];
    }
    return null;
  };
  const findNpc = (name) => { for (const k of nameVariants(name)) if (npcByName.has(k)) return npcByName.get(k); return null; };
  const findItem = (name) => { for (const k of nameVariants(name)) if (itemByName.has(k)) return itemByName.get(k); return null; };
  const lev = (a, b) => { // edit distance (short names only)
    if (Math.abs(a.length - b.length) > 3) return 99;
    let prev = Array.from({ length: b.length + 1 }, (_, j) => j);
    for (let i = 1; i <= a.length; i++) { const cur = [i]; for (let j = 1; j <= b.length; j++) cur[j] = Math.min(prev[j] + 1, cur[j - 1] + 1, prev[j - 1] + (a[i - 1] === b[j - 1] ? 0 : 1)); prev = cur; }
    return prev[b.length];
  };
  /** fuzzy NPC: exact -> the turn-in NPC when its name is close -> a placed NPC whose name contains the target. */
  const findNpcFuzzy = (name, turnIn, map) => {
    const exact = findNpc(name); if (exact) return [exact, 'name:npc'];
    const k = normName(name.replace(/\s+(at|in|of)\s+.*$/i, '')); if (k.length < 4) return null;
    if (turnIn && NPC[turnIn]) { const tn = normName(NPC[turnIn].name); if (tn.includes(k) || k.includes(tn) || lev(k, tn) <= 2) return [turnIn, 'fuzzy:npc=turnIn']; }
    const cands = Object.keys(NPC).map(Number).filter((id) => { const n = normName(NPC[id].name); return n && (n.includes(k) || (n.length >= 4 && k.includes(n))); });
    if (!cands.length) return null;
    const placed = cands.filter((id) => npcPos.has(id));
    const onMap = placed.filter((id) => npcPos.get(id).some((p) => p.map === map));
    return [(onMap[0] ?? placed[0] ?? cands[0]), 'fuzzy:npc'];
  };
  /** map by English name ("Clear Karon's Transport Ship C Rank" -> 52); exact, then a unique prefix/containment match. */
  const mapByName = new Map(); for (const [id, n] of maps) { const k = normName(n); if (k && !mapByName.has(k)) mapByName.set(k, id); }
  const findMap = (name) => {
    const k = normName(String(name ?? '').replace(/\b(clear|complete|win|in|the|rank|solo|conquer|execute|defeat)\b/gi, ' ').replace(/\(.*?\)/g, ''));
    if (k.length < 5) return null;
    if (mapByName.has(k)) return mapByName.get(k);
    const c = [...mapByName].filter(([n]) => n.startsWith(k) || (n.length >= 6 && k.startsWith(n)));
    if (!c.length) return null;
    c.sort((a, b) => b[0].length - a[0].length); // the most specific name ("karonstransportshipc" over "karonstransportship")
    return c[0][1];
  };
  /** Monster by a name fragment, restricted to monsters spawned on the quest map (avoids false hits). */
  const findMonsterOnMap = (name, map) => {
    const k = normName(name); if (k.length < 5 || map === undefined) return null;
    const c = [...monNames].filter(([n]) => n.includes(k) || (n.length >= 5 && k.includes(n))).flatMap(([, ids]) => ids).filter((x) => monMaps.get(x)?.has(map));
    return c.length ? [...new Set(c)] : null;
  };

  /** Resolve a free-text objective / link list to targets (legacy quests without a server row). */
  function inferTargets(texts0, map, ctx = {}) {
    let texts = texts0;
    let navFallback = null;
    for (const t of texts0) {
      if (!t) continue;
      const links = extractLinks(t);
      if (links.length) {
        const l = links[0];
        if (l.kind === 'npcNav') { // "[elink]npc[/elink][Label]" / "[Label][elink]npc[/elink]": the NPC is a waypoint; the label usually names the real target
          const lab = /\[elink\]\d+\[\/elink\]\s*\[([^\]]+)\]/i.exec(t) || /\[([^\]]+)\]\s*(?:defeat\s*)?\[elink\]\d+\[\/elink\]/i.exec(t);
          const label = lab ? lab[1] : t.replace(/\[\/?elink\]|\d+/gi, ' ').replace(/\[|\]/g, ' ').trim();
          const mids = label ? findMonster(label, map) : null;
          if (mids) return { kind: 'kill', ids: mids, how: 'link:npcNav+name:monster', ok: true, nav: l.id };
          const npcName = normName(NPC[l.id]?.name);
          if (/\b(tell|talk|speak|report|deliver|visit|story|meet)\b/i.test(t) || (npcName && normName(label).includes(npcName))) return { kind: 'talk', ids: [l.id], how: 'link:npcNav', ok: !!NPC[l.id] };
          // label not a monster name: try the other texts (progress message) and the fuzzy pass first, the waypoint NPC last
          navFallback = { kind: 'talk', ids: [l.id], how: 'link:npcNav', ok: !!NPC[l.id], weak: true };
          texts = [...texts0.filter((x) => x !== t), label];
          continue;
        }
        const kind = l.kind === 'monster' || l.kind === 'monsterNav' ? 'kill' : l.kind === 'item' ? 'collect' : 'talk';
        const ok = kind === 'kill' ? !!MON[l.id] : kind === 'collect' ? items.has(l.id) : !!NPC[l.id];
        return { kind, ids: [...new Set(links.filter((x) => x.kind === l.kind).map((x) => x.id))], how: `link:${l.kind}`, ok };
      }
    }
    const r = inferFromText(texts, map, ctx);
    if (r && navFallback) r.nav = navFallback.ids[0];
    return r ?? navFallback;
  }
  function inferFromText(texts, map, ctx) {
    for (const t0 of texts) {
      if (!t0) continue;
      const t = t0.replace(/\(?\s*<COUNT\d?>\s*\/\s*(<MAX_COUNT\d?>|\d+)\s*\)?/gi, ' ').replace(/<[^>]*>/g, '').replace(/\[message\]/i, '').replace(/\s+/g, ' ').trim().replace(/[.!]+$/, '');
      let m;
      if ((m = /(?:talk|speak|converse|conversation|meet)\s*(?:to|with)?\s+(?:the\s+)?(.+)$/i.exec(t))) { const n = findNpc(m[1].replace(/^\((main|normal|general)\)\s*/i, '')); if (n) return { kind: 'talk', ids: [n], how: 'name:npc', ok: true }; }
      if ((m = /(?:defeat(?:ed)?|kill(?:ed)?|eliminat\w*|hunt(?:ed)?|slay|slain|destroy\w*|exterminat\w*)\s+(?:\d+\s+)?(?:the\s+|all\s+)?(.+?)(?:\s*\(.*\))?(?:\s+\d+)?$/i.exec(t))) {
        const ids2 = findMonster(m[1], map); if (ids2) return { kind: 'kill', ids: ids2, how: 'name:monster', ok: true };
        if (/^monsters?$|monsters?\b/i.test(m[1]) && map !== undefined) return { kind: 'killOnMap', ids: [map], how: 'text:anyMonster', ok: maps.has(map) };
      }
      if ((m = /^(.+?)\s+(?:defeat(?:ed)?|kill(?:ed)?)$/i.exec(t))) { const ids2 = findMonster(m[1], map); if (ids2) return { kind: 'kill', ids: ids2, how: 'name:monster', ok: true }; }
      if ((m = /^(.+?)\s+(?:has\/have|has|have)?\s*(?:been\s+)?(?:defeated|killed|eliminated|hunted)\b/i.exec(t))) { const ids2 = findMonster(m[1], map); if (ids2) return { kind: 'kill', ids: ids2, how: 'name:monster', ok: true }; }
      if (/\b(hunt(?:ed)?|defeat(?:ed)?|kill(?:ed)?|investigate)\b.*\bmonsters?\b|\bmonsters?\b.*\b(defeat|hunt|kill)/i.test(t) && map !== undefined) return { kind: 'killOnMap', ids: [map], how: 'text:anyMonster', ok: maps.has(map) };
      if (/\bclear\b.*\b(dungeon|instance|indun)\b|\b(dungeon|indun)\b.*\bclear/i.test(t)) {
        const mp = findMap(t);
        if (mp !== null && mp !== undefined) return { kind: 'clearMap', ids: [mp], how: 'name:map', ok: true };
        return { kind: 'clearMap', ids: [], how: 'text:clearAnyDungeon', ok: true }; // "Clear the Instance Dungeon": any dungeon counts
      }
      const ids2 = findMonster(t, map); if (ids2) return { kind: 'kill', ids: ids2, how: 'name:monster', ok: true };
      const it = findItem(t); if (it) return { kind: 'collect', ids: [it], how: 'name:item', ok: true };
      const n = findNpc(t); if (n) return { kind: 'talk', ids: [n], how: 'name:npc', ok: true };
    }
    // second pass (fuzzy): talk / find -> NPC (the turn-in NPC when its name is close); clear / dungeon name -> map;
    // monster name fragments restricted to the quest map
    for (const t0 of texts) {
      if (!t0 || /^\[message\]/i.test(t0)) continue;
      const t = t0.replace(/<[^>]*>/g, '').replace(/\s+/g, ' ').trim().replace(/[.!]+$/, '');
      let m;
      if ((m = /^(?:\((?:main|normal|daily|general)\)\s*)?(?:talk|speak|converse|conversation|meet|find|visit|report)\s*(?:to|with)?\s+(?:the\s+)?(.+)$/i.exec(t))) {
        const r = findNpcFuzzy(m[1], ctx.turnIn, map); if (r) return { kind: 'talk', ids: [r[0]], how: r[1], ok: true };
      }
      if (/\b(clear|complete|win|conquer)\b/i.test(t) || ctx.dungeonHint) {
        const mp = findMap(t); if (mp !== null && mp !== undefined) return { kind: 'clearMap', ids: [mp], how: 'name:map', ok: true };
      }
      const km = /(?:defeat(?:ed)?|kill(?:ed)?|eliminat\w*|hunt(?:ed)?|remove|execute)\s+(?:\d+\s+)?(?:the\s+|all\s+)?(.+)$/i.exec(t);
      const mids = findMonsterOnMap(km ? km[1] : t, map); if (mids && mids.length <= 6) return { kind: 'kill', ids: mids, how: 'fuzzy:monster@map', ok: true };
    }
    return null;
  }

  /** Legacy objectives with no resolvable target: the server script drives them. Classify for the engine. */
  function scriptedHint(label, prog, q) {
    const t = `${label || ''} ${prog || ''} ${q.title || ''}`;
    if (/DK Square|Battle Royale|Colosseum|Party Ranking|PvP|opponents?|enemy|Deserter|Win in DK/i.test(t)) return 'pvp';
    if (/Recruit|Knight|Guardsman|Regular|Commander|Sergeant/i.test(label || '') && /\[Battlefield\].*Title|Title Conquest/i.test(q.title || '')) return 'rank';
    if (/\[Guild\]|guild/i.test(q.title || '')) return 'guild';
    if (/Hunting Points?/i.test(t)) return 'huntPoints';
    if (/Favorability|Affection/i.test(t)) return 'affection';
    if (/\bclear\b|dungeon|boss/i.test(t)) return 'dungeon';
    if (!label && (q.tags || []).some((x) => ['teleport', 'exchange', 'ticket'].includes(x))) return 'service';
    if (!label) return 'service';
    if (/collect|obtain|acquire|gather|sample|piece|fragment|tears?|core|scale|seal|proof|evidence|ingredients?/i.test(t)) return 'collect';
    if (/defeat|kill|hunt|eliminat|remove|destroy|crack|burst|unmask/i.test(t)) return 'kill';
    return 'script';
  }

  // ---------------------------------------------------------------- loot sources for collect items (monsters.json drops + trigger drops)
  let lootIdx = null;
  const lootSources = (itemIds) => {
    if (!lootIdx) {
      lootIdx = { mon: new Map(), trig: new Map() };
      const add = (m, k, v) => { if (!m.has(k)) m.set(k, []); if (m.get(k).length < 12) m.get(k).push(v); };
      for (const [mid, m] of Object.entries(MON)) {
        for (const f of m.drops?.fixed || []) add(lootIdx.mon, f[0], [+mid, 'fixed']);
        for (const s of [...(m.drops?.sets || []), ...(m.drops?.fixedSets || [])]) for (const it of monDb.itemSets?.[s[0]]?.items || []) add(lootIdx.mon, it[0], [+mid, `set${s[0]}`]);
      }
      if (existsRel('share/item/triggerdropitem.csv')) {
        const t = loadCsv('share/item/triggerdropitem.csv'); const cc = colIndex(t.header);
        for (const r of t.rows) { if (!isNumCell(r[0])) continue; for (let k = 1; k <= 10; k++) { const it = num(r[cc[`Fix_ItemIndex_${k}`]]); if (it) add(lootIdx.trig, it, { map: num(r[0]), trigger: num(r[1]), name: kr(r[2]) }); } }
      }
    }
    const out = {};
    const mons = itemIds.flatMap((i) => lootIdx.mon.get(i) || []); if (mons.length) out.monsters = mons;
    const trig = itemIds.flatMap((i) => lootIdx.trig.get(i) || []); if (trig.length) out.triggers = trig;
    return Object.keys(out).length ? out : null;
  };

  // ---------------------------------------------------------------- build every quest
  const quests = {};
  const stats = { total: 0, bySrc: {}, byCat: {}, offered: 0, withDialog: 0, withTitle: 0, withJournal: 0, objectives: 0, objectivesByKind: {}, legacyObjectives: 0, legacyInferred: 0,
    legacyRewardsFromText: 0, inferenceCheck: [0, 0, 0], corePages: [0, 0], giverPlaced: 0, giverTotal: 0, turnInPlaced: 0, turnInTotal: 0, maxCountAgree: [0, 0], journalRewardAgree: { exp: [0, 0], dil: [0, 0] }, drops: 0, variants: 0 };
  for (const id of sorted) {
    const where = `quest ${id}`;
    const c = I.client.map.get(String(id))?.r;
    const t = I.table.map.get(String(id))?.r;
    const rn = I.renew.map.get(String(id))?.r;
    const rw = rewardRows.get(id);
    const dr = I.drop.map.get(String(id))?.r;
    const os = I.objstr.map.get(String(id));
    const dlg = dialogs.get(id);
    const q = { id };
    const gc = (n) => (c ? get('client', c, n) : undefined);
    const gr = (n) => (rn ? get('renew', rn, n) : undefined);
    q.parent = num(gc('ParentIndex')) || num(t?.[1]) || num(gr('ParentIndex')) || id;
    const titleCode = num(gc('QuestTitleCode')) || 11;
    q.title = qstr(id, titleCode) ?? qstr(id, 11) ?? qstr(id, 1) ?? null;
    const shortName = os ? (lcsv('quest#quest_objectstring.csv', 1, os.row) ?? kr(get('objstr', os.r, 'QuestName'))) : null;
    if (shortName && shortName !== '0') q.name = shortName;
    if (!q.title && q.name) q.title = q.name;
    if (!q.title) q.title = qsLabel.get(id) ? `(${qsLabel.get(id)})` : null;
    q.src = rn ? (c || qs.has(id) ? 'renew' : 'server') : c ? 'client' : 'text';
    if (c) q.clientType = num(gc('Type'));
    if (rn) q.type = num(gr('Type'));
    if (t) q.serverType = num(t[2]);
    q.cat = rn ? (RENEW_TYPE[q.type] || `type${q.type}`) : c ? (CLIENT_TYPE[q.clientType] || `client${q.clientType}`) : 'normal';
    const tags = [];
    const tt = (q.title || '') + ' ' + (q.name || '');
    for (const [re, tag] of [[/\[(event|evento)\]/i, 'event'], [/\[exchange\]|exchange/i, 'exchange'], [/\[daily\]/i, 'daily'], [/\[weekly\]/i, 'weekly'], [/teleport|\[move\]|^move\b|warp/i, 'teleport'], [/ticket/i, 'ticket'], [/\[craft\]|craft/i, 'craft'], [/\[guide\]|advice|how to/i, 'guide'], [/\[repeat|\[repetition\]/i, 'repeat'], [/meister/i, 'meister'], [/awaken/i, 'awakening'], [/\[battlefield\]|\[dk square\]/i, 'battlefield'], [/\[guild\]/i, 'guild']]) if (re.test(tt)) tags.push(tag);
    if (tags.length) q.tags = tags;

    // level
    let lv = null;
    if (rn) lv = [num(gr('Min_Level')), num(gr('Max_Level'))];
    else if (c && (num(gc('Level_Min')) || num(gc('Level_Max')))) lv = [num(gc('Level_Min')), num(gc('Level_Max'))];
    else if (c && num(gc('Level'))) lv = [num(gc('Level')), 0];
    if (lv) q.level = lv;
    if (c && num(gc('Level'))) q.listLevel = num(gc('Level'));
    if (c && num(gc('Quest_MapIndex'))) { q.map = num(gc('Quest_MapIndex')); useRef('map', q.map, where); }
    if (c && num(gc('Notice'))) q.noticeMsg = num(gc('Notice'));
    if (titleCode === 1) q.isGroup = true; // quest-log group header (code 1 = group title, 2 = description)

    // NPCs
    const sMaps = rn ? splitList(gr('S_Map')) : q.map !== undefined ? [q.map] : [];
    const eMaps = rn ? splitList(gr('E_Map')) : q.map !== undefined ? [q.map] : [];
    if (rn) { for (const m of sMaps) useRef('map', m, where); for (const m of eMaps) useRef('map', m, where); }
    const sList = splitIds(rn ? gr('S_npc') : gc('S_npc')); const sNpc = sList[0] || 0;
    const eList = splitIds(rn ? gr('E_npc') : gc('E_npc')); const eNpc = eList[0] || 0;
    const givers = (offeredBy.get(id) || []).map(([n, jt]) => [n, jt]);
    if (givers.length) q.listedBy = givers; // NPCs whose menu lists this quest (npc.csv jobs / request boards)
    q.offered = givers.length > 0;
    let giverId = sNpc || (givers[0] ? givers[0][0] : 0);
    const journal = qstr(id, num(gc('QuestBookCode')) || 12);
    const jl = extractLinks((journal || '').split(/Quest Info|Details/i)[0]).find((l) => l.kind === 'npc');
    let turnInId = eNpc || (jl ? jl.id : 0) || giverId;
    if (giverId) { q.giver = npcRef(giverId, sMaps); if (sList.length > 1) { q.giver.alt = sList.slice(1); sList.slice(1).forEach((n) => useRef('npc', n, where)); } useRef('npc', giverId, where); stats.giverTotal++; if (q.giver.pos) stats.giverPlaced++; }
    if (turnInId) { q.turnIn = npcRef(turnInId, eMaps); if (eList.length > 1) { q.turnIn.alt = eList.slice(1); eList.slice(1).forEach((n) => useRef('npc', n, where)); } useRef('npc', turnInId, where); stats.turnInTotal++; if (q.turnIn.pos) stats.turnInPlaced++; if (!eNpc) q.turnIn.inferred = jl ? 'journal' : 'giver'; }
    if (!sNpc && giverId) q.giver.inferred = 'npcJob';

    // chain / gates
    const pre = rn ? num(gr('Pre_Index')) : num(gc('P_QuestIndex'));
    if (pre && pre !== id) { q.prereq = pre; useRef('quest', pre, where); }
    if (c && num(gc('P_QuestIndex')) && rn && num(gc('P_QuestIndex')) !== pre && num(gc('P_QuestIndex')) !== id) q.prereqClient = num(gc('P_QuestIndex'));
    if (rn && num(gr('Going_Index'))) { q.going = num(gr('Going_Index')); useRef('quest', q.going, where); }
    if (rw?.main && num(get('reward', rw.main.r, 'NextIndex'))) { q.next = num(get('reward', rw.main.r, 'NextIndex')); useRef('quest', q.next, where); }
    const repeat = {};
    if (rn && num(gr('RepeatCount'))) repeat.count = num(gr('RepeatCount'));
    if (dlg?.period) repeat.perPeriod = dlg.period;
    if (rn && num(gr('Quest_Reset'))) repeat.reset = num(gr('Quest_Reset'));
    if (q.cat === 'daily' || q.cat === 'ticket' || q.cat === 'weekday' || q.clientType === 4) repeat.daily = true;
    if (q.cat === 'weekday') repeat.weekday = num(gr('N_Day')) || 7; // N_Day 1..6 = Mon..Sat, 0 on the Sunday quest
    if (Object.keys(repeat).length) q.repeat = repeat;
    if (I.sched.map.has(String(id))) {
      const s = I.sched.map.get(String(id)).r;
      const iso = (v) => { const m = /^(\d{4})(\d\d)(\d\d)(\d\d)(\d\d)(\d\d)$/.exec(str(v)); return m ? `${m[1]}-${m[2]}-${m[3]}T${m[4]}:${m[5]}:${m[6]}` : str(v); };
      q.schedule = { start: iso(s[1]), end: iso(s[2]) };
    } else if (T.sched.missing && q.cat === 'wanted') {
      // Renew Type11 identifies dated Wanted notices. Without their calendar,
      // do not invent dates or silently make expired events always available.
      q.schedule = { unavailable: true, source: SPECIFIC_PERIOD_SCHEDULE };
    }
    const req = {};
    if (rn) {
      if (num(gr('Class_Check'))) { req.class = num(gr('Class_No')); }
      if (num(gr('N_DIL'))) req.dil = num(gr('N_DIL'));
      if (num(gr('N_Level'))) req.level = num(gr('N_Level'));
      if (num(gr('N_Status'))) { req.status = num(gr('N_Status')); useRef('status', req.status, where); }
      if (num(gr('Map_Check')) === 1) req.onTargetMap = true; // flag form (clearMap quests): progress only inside the Index map
      else if (num(gr('Map_Check'))) { req.map = num(gr('Map_Check')); useRef('map', req.map, where); }
      if (num(gr('Awaken_Check'))) req.awakened = true;
      if (num(gr('Meister_Check'))) req.meister = true;
      if (num(gr('Condition_Check'))) req.instant = true;
      const nItems = [];
      for (let k = 1; k <= 10; k++) { const v = num(gr(`N_Item_Index_${k}`)); if (v) { nItems.push({ item: v, count: num(gr(`N_Item_Count_${k}`)) || 1 }); useRef('item', v, where); } }
      if (nItems.length) { if (num(gr('Apply_GiveItem_OnOff'))) req.giveOnAccept = nItems; else req.items = nItems; }
      if (num(gr('N_Item_Not_Dialog'))) req.missingItemsMsg = num(gr('N_Item_Not_Dialog'));
      if (num(gr('Complete_Count'))) req.completeAny = num(gr('Complete_Count'));
    }
    if (Object.keys(req).length) q.require = req;

    // objectives
    const objectives = [];
    const pm = progressMsgs(id);
    if (rn) {
      const kindCode = num(gr('Rank_1'));
      const kind = OBJ_KIND[kindCode] || `kind${kindCode}`;
      q.kind = kind;
      const add = (pfx, k, kd, ex) => {
        const I2 = ex ? { idx: `EX_Index_${k}`, cnt: `EX_Index_Count_${k}`, succ: `Ex_Index_Succ_Count_${k}`, rate: `EX_Index_Rate_${k}`, obj: `Ex_Index_Object_Number_${k}`, chk: `Ex_N_Item_Check_${k}`, chkc: `Ex_N_Item_Check_Count_${k}`, dlg: `Ex_Index_Dialog_${k}` }
          : { idx: `Index_${k}`, cnt: `Index_Count_${k}`, succ: `Index_Succ_Count_${k}`, rate: `Index_Rate_${k}`, obj: `Index_Object_Number_${k}`, chk: `N_Item_Check_${k}`, chkc: `N_Item_Check_Count_${k}`, dlg: `Index_Dialog_${k}` };
        const tg = splitIds(gr(I2.idx)); if (!tg.length) return;
        const slot = num(gr(I2.obj));
        const o = { slot, kind: kd, targets: tg.map((x) => targetRef(kd, x, where)), count: num(gr(I2.succ)) || 1 };
        if (num(gr(I2.cnt)) !== 1) o.per = num(gr(I2.cnt));
        if (num(gr(I2.rate))) o.chance = num(gr(I2.rate)) / 100000;
        if (num(gr(I2.chk))) { o.needItem = { item: num(gr(I2.chk)), count: num(gr(I2.chkc)) || 1 }; useRef('item', o.needItem.item, where); }
        if (num(gr(I2.dlg))) o.talkMsg = num(gr(I2.dlg));
        if (req.map) o.map = req.map;
        if (ex) o.extra = true;
        if (kd === 'kill' && num(gr('Extent_Check'))) o.range = [num(gr('Extent_Index_Min')), num(gr('Extent_Index_Max'))];
        const lbl = objectLabel(id, slot); if (lbl) o.label = lbl;
        if (pm[slot] !== undefined) o.progressMsg = pm[slot];
        objectives.push(o);
      };
      for (let k = 1; k <= 10; k++) add('', k, kind, false);
      const exKind = OBJ_KIND[num(gr('Rank_2'))] || 'collect';
      for (let k = 1; k <= 10; k++) add('EX', k, exKind, true);
      if (kind === 'fish' && !objectives.length) {
        for (let s = 0; s < 10; s++) if (gc(`Object_${s}_Enable`) === 'TRUE') objectives.push({ slot: s, kind: 'fish', targets: [], count: num(gc(`Object_${s}_MaxCount`)) || 1, label: objectLabel(id, s) ?? undefined });
      }
      if (num(gr('Call_Mon_Index'))) {
        q.callMonster = { monster: num(gr('Call_Mon_Index')), count: num(gr('Call_Mon_Count')) || 1, map: num(gr('Call_MapIndex')), pos: [num(gr('Call_X')), num(gr('Call_Y'))], name: MON[num(gr('Call_Mon_Index'))]?.name ?? null };
        useRef('monster', q.callMonster.monster, where); useRef('map', q.callMonster.map, where);
      }
      // accuracy of the legacy text inference, measured on quests whose real targets are known
      for (const o of objectives) {
        if (o.extra || !['kill', 'collect', 'talk', 'killOnMap'].includes(o.kind)) continue;
        const inf = inferTargets([o.label, o.progressMsg !== undefined ? qstr(id, o.progressMsg) : null], q.map ?? sMaps[0], { turnIn: turnInId });
        stats.inferenceCheck[1]++;
        // "Clear <dungeon>" inferred as clearMap is right when the real (renew) target is a monster of that map (its boss)
        const right = inf && ((inf.kind === o.kind && inf.ids.some((x) => o.targets.some((tg) => tg.id === x || (MON[x] && MON[tg.id] && MON[x].name === MON[tg.id].name))))
          || (inf.kind === 'clearMap' && o.kind === 'kill' && o.targets.some((tg) => inf.ids.some((mp) => monMaps.get(tg.id)?.has(mp) || normName(maps.get(mp)) === normName(String(o.label || '').replace(/^clear\s+/i, ''))))));
        if (right) stats.inferenceCheck[0]++;
        else if (inf) stats.inferenceCheck[2]++;
        if (inf) { const b = (stats.inferenceByHow ||= {})[inf.how] ||= [0, 0]; b[1]++; if (right) b[0]++; }
      }
      // client Object MaxCount cross-check
      for (const o of objectives) {
        const mc = gc(`Object_${o.slot}_Enable`) === 'TRUE' ? num(gc(`Object_${o.slot}_MaxCount`)) : null;
        if (mc !== null && c) { stats.maxCountAgree[0]++; if (mc === o.count || mc === 0) stats.maxCountAgree[1]++; }
      }
    } else if (c) {
      // legacy quest (no server row in the client): objectives from quest.csv Object slots + object / progress strings
      for (let s = 0; s < 10; s++) {
        if (gc(`Object_${s}_Enable`) !== 'TRUE') continue;
        const lbl = objectLabel(id, s);
        const prog = pm[s] !== undefined ? qstr(id, pm[s]) : null;
        const o = { slot: s, kind: 'unknown', targets: [], count: num(gc(`Object_${s}_MaxCount`)) || 1 };
        if (lbl) o.label = lbl;
        if (pm[s] !== undefined) o.progressMsg = pm[s];
        const inf = inferTargets([lbl, prog], q.map, { turnIn: turnInId });
        if (process.env.DEBUGQ && +process.env.DEBUGQ === id) console.log('DEBUG', id, s, JSON.stringify([lbl, prog]), JSON.stringify(inf));
        if (inf) { o.kind = inf.kind; o.targets = inf.ids.map((x) => targetRef(inf.kind, x, where)); o.inferred = inf.how; if (inf.nav) o.navNpc = inf.nav; if (inf.weak) o.weak = true; if (!inf.ok) o.unresolved = true; if (inf.how === 'text:clearAnyDungeon') o.anyDungeon = true; stats.legacyInferred++; }
        else { o.kind = 'scripted'; o.hint = scriptedHint(lbl, prog, q); stats.legacyScripted = (stats.legacyScripted || 0) + 1; }
        stats.legacyObjectives++;
        objectives.push(o);
      }
      if (objectives.length) q.kind = objectives.every((o) => o.kind === objectives[0].kind) ? objectives[0].kind : 'mixed';
      else q.kind = dlg ? 'dialog' : 'none';
    } else q.kind = dlg ? 'dialog' : 'none'; // no quest.csv row: dialog / string-only entry (NPC talk trees, event pages)
    // Scan fix A (SCAN-B I5): no quest-table row, no dialog file, only a lines_eu title (5398, 15342): inert text-only stub.
    if (q.src === 'text' && q.kind === 'none') q.textOnly = true;
    if (objectives.length) q.objectives = objectives;
    for (const o of objectives) { stats.objectives++; stats.objectivesByKind[o.kind] = (stats.objectivesByKind[o.kind] || 0) + 1; }

    // rewards
    if (rw?.main) {
      q.rewards = rewardOf(rw.main.r, where, q.level);
      const main = rw.main.r;
      const variants = [];
      const selNo = str(get('reward', main, 'Sel_No')).split('/').filter((x) => x && x !== '0').map(Number);
      const selRes = str(get('reward', main, 'Sel_Reward_Result')).split('/').filter((x) => x && x !== '0');
      const selMode = num(get('reward', main, 'Sel_Reward_On/Off')) ? 'choice' : num(get('reward', main, 'SubNo_Check')) ? 'repeat' : num(get('reward', main, 'Object_No_On/off')) ? 'objective' : null;
      if (num(get('reward', main, 'SubNo_Check'))) variants.push({ id: String(id), repeat: num(get('reward', main, 'Repeat_Count')), msg: num(get('reward', main, 'String_No')) || undefined, reward: q.rewards });
      for (const [sid, { r }] of [...rw.subs].sort()) {
        const v = { id: sid };
        const si = selRes.indexOf(sid);
        if (si >= 0 && selNo[si]) v.option = selNo[si];
        if (num(get('reward', r, 'SubNo_Check'))) { v.repeat = num(get('reward', r, 'Repeat_Count')); if (num(get('reward', r, 'String_No'))) v.msg = num(get('reward', r, 'String_No')); }
        if (num(get('reward', r, 'Object_No_On/off'))) v.slot = num(get('reward', r, 'Object_No'));
        if (num(get('reward', r, 'Class_Check'))) v.classIndex = num(get('reward', r, 'Class_Index'));
        v.reward = rewardOf(r, where, q.level);
        variants.push(v);
      }
      if (variants.length) { q.rewardVariants = { mode: selMode || 'other', list: variants }; stats.variants += variants.length; }
      // journal cross-check (validates the text parser used for legacy quests)
      const pr = parseRewardText(journal);
      if (pr && q.rewards.exp && typeof q.rewards.exp === 'number') { stats.journalRewardAgree.exp[0]++; if (pr.exp === q.rewards.exp) stats.journalRewardAgree.exp[1]++; }
      if (pr && q.rewards.dil && typeof q.rewards.dil === 'number') { stats.journalRewardAgree.dil[0]++; if (pr.dil === q.rewards.dil) stats.journalRewardAgree.dil[1]++; }
    } else if (journal) {
      const pr = parseRewardText(journal);
      if (pr && (pr.exp || pr.dil || pr.adv || pr.items.length || pr.lines.length)) {
        const r = {};
        if (pr.exp) r.exp = pr.exp; if (pr.dil) r.dil = pr.dil; if (pr.adv) r.adv = pr.adv;
        const its = []; const notes = [];
        for (const [cnt, name] of pr.items) {
          const lk = extractLinks(name).find((l) => l.kind === 'item');
          const idx = lk ? lk.id : findItem(name.replace(/\s*\(.*?\)\s*$/, '')) ?? findItem(name);
          const text = name.replace(/\[\/?[a-z]link\]/gi, '');
          if (cnt === null && !idx) { notes.push(text); continue; } // e.g. "you will obtain a title", "Grade Point 1020"
          const it = { count: cnt ?? 1, text };
          if (idx) { it.item = idx; useRef('item', idx, where); }
          its.push(it);
        }
        if (its.length) r.items = its;
        if (notes.length) r.notes = notes;
        r.fromText = true;
        q.rewards = r; stats.legacyRewardsFromText++;
      }
    }

    // collect objectives with no quest-drop row: where the item comes from in the normal loot tables
    for (const o of objectives) {
      if (o.kind !== 'collect') continue;
      const ids2 = o.targets.map((tg) => tg.id);
      if (dr && [...Array(10).keys()].some((k) => ids2.includes(num(get('drop', dr, `DropItemIndex_${k}`))))) continue;
      const src = lootSources(ids2);
      if (src) o.sources = src;
    }
    // quest item drops
    if (dr) {
      const drops = [];
      for (let k = 0; k < 10; k++) {
        const mons = splitIds(get('drop', dr, `MonsterIndex_${k}`)); const it = num(get('drop', dr, `DropItemIndex_${k}`));
        if (!mons.length || !it) continue;
        for (const m of mons) useRef('monster', m, where);
        useRef('item', it, where);
        drops.push({ monsters: mons, item: it, chance: num(get('drop', dr, `DropRatio_${k}`)) / 100000 });
      }
      if (num(get('drop', dr, 'MapIndex'))) drops.forEach((d) => { d.map = num(get('drop', dr, 'MapIndex')); });
      if (num(get('drop', dr, 'LevelCap'))) drops.forEach((d) => { d.levelCap = num(get('drop', dr, 'LevelCap')); });
      if (drops.length) { q.drops = drops; stats.drops += drops.length; }
    }

    // dialog / text
    if (dlg) {
      q.dialog = { file: dlg.file, listed: dlg.listed };
      if (dlg.header !== id && dlg.header !== null) q.dialog.header = dlg.header;
      // only messages whose string exists count: the files come from a template and list unused branches
      const txtOf = (code) => qstr(id, code) ?? (dlg.header != null && dlg.header !== id ? qstr(dlg.header, code) : null);
      const withText = new Set(dlg.messages.filter((m) => txtOf(m[1]) != null).map((m) => m[0]));
      const msgs = new Map(dlg.messages.filter((m) => withText.has(m[0])).map((m) => [m[0], [m[0], m[1], m[2].filter((o) => withText.has(o))]]));
      for (const core of [10000, 20000, 30000]) if (dlg.listed && q.offered && dlg.messages.some((m) => m[0] === core)) { stats.corePages[1]++; if (withText.has(core)) stats.corePages[0]++; }
      const flow = {};
      const pick = (arr) => arr.find((m) => msgs.has(m));
      for (const k of ['offer', 'lowLevel', 'progressAtGiver', 'progress', 'complete']) { const m = pick(FLOW_IDS[k]); if (m !== undefined) flow[k] = m; }
      if (flow.offer !== undefined) {
        const opts = msgs.get(flow.offer)[2];
        if (opts.length) { flow.accept = opts[0]; if (opts.length > 1) flow.decline = opts[opts.length - 1]; if (opts.length > 2) flow.offerOptions = opts; }
        // pages shown after each choice until the dialog closes (page navigation rule: see nextPage)
        const path2 = (o) => { const out = []; let p = flow.offer, opt = o; for (let g = 0; g < 12 && opt !== undefined; g++) { const nx = nextPage(msgs, p, opt); if (nx === undefined) break; out.push(nx); p = nx; opt = msgs.get(nx)[2][0]; } return out; };
        if (flow.accept !== undefined) { const pth = path2(flow.accept); if (pth.length) flow.acceptPath = pth; }
        if (flow.decline !== undefined) { const pth = path2(flow.decline); if (pth.length) flow.declinePath = pth; }
      }
      // reply pages: 10100/10200 when present, else 10010/10020 (only when the offer has an accept AND a decline option)
      if (msgs.has(10100)) flow.accepted = 10100;
      else if (msgs.has(10010) && flow.decline !== undefined) flow.accepted = 10010;
      if (msgs.has(10200)) flow.declined = 10200;
      else if (msgs.has(10020) && flow.decline !== undefined && !msgs.has(10100)) flow.declined = 10020;
      if (flow.accepted !== undefined && msgs.get(flow.accepted)[2].length) flow.acceptedOk = msgs.get(flow.accepted)[2][0];
      if (flow.complete !== undefined) {
        const opts = msgs.get(flow.complete)[2];
        if (opts.length) flow.claim = opts[0];
        if (opts.length > 1) flow.completeOptions = opts;
      }
      for (const o of objectives) if (o.talkMsg && msgs.has(o.talkMsg)) (flow.talk ||= {})[o.slot] = o.talkMsg;
      { // further state entry pages (12000.. extra in-progress stages, 21000.. turn-in stages, 31000.. completion variants, 40000+ post-quest)
        const used = new Set(Object.values(flow).filter((v) => typeof v === 'number'));
        const more = [...msgs.keys()].filter((m) => m >= 10000 && m % 1000 === 0 && !used.has(m)).sort((a, b) => a - b);
        if (more.length) flow.otherEntries = more;
      }
      if (flow.offer === undefined) {
        // non-standard trees (manuals, exchange menus, per-class pages): entry = root pages (id >= 1000, with text,
        // not an option of another page); the NPC opens the lowest one
        const referenced = new Set([...msgs.values()].flatMap((m) => m[2]));
        const roots = [...msgs.keys()].filter((m) => m >= 1000 && !referenced.has(m)).sort((a, b) => a - b);
        if (roots.length) { flow.entry = roots[0]; if (roots.length > 1) flow.roots = roots.slice(0, 40); }
      }
      if (Object.keys(flow).length) q.flow = flow;
      stats.withDialog++;
    }
    const text = {};
    for (const [k, code] of [['journal', num(gc('QuestBookCode')) || 12], ['diary', num(gc('QuestDiaryCode')) || 13], ['alarm', 14]]) if (qstr(id, code) != null) text[k] = code;
    if (Object.keys(text).length) q.text = text;
    if (q.title) stats.withTitle++;
    if (text.journal) stats.withJournal++;

    // raw, unmapped columns
    const raw = {};
    if (rn) { const x = rawOf('renew', rn, RENEW_MAPPED); if (x) raw.renew = x; if (num(gr('Code')) !== 1) raw.renewCode = num(gr('Code')); if (num(gr('Rank_2'))) raw.rank2 = num(gr('Rank_2')); if (num(gr('Extent_Check'))) raw.extent = [num(gr('Extent_Index_Min')), num(gr('Extent_Index_Max'))]; }
    if (c) { const x = rawOf('client', c, CLIENT_MAPPED); if (x) raw.client = x; }
    if (dr) { const x = {}; for (const h of ['Type', 'Rank_1', 'Rank_2', 'Code']) if (num(get('drop', dr, h)) !== (h === 'Type' ? q.type : h === 'Rank_1' ? num(gr('Rank_1')) : h === 'Rank_2' ? num(gr('Rank_2')) : num(gr('Code')))) x[h] = num(get('drop', dr, h)); if (Object.keys(x).length) raw.dropHeader = x; }
    if (t && num(t[3])) raw.serverLevel = num(t[3]);
    if (Object.keys(raw).length) q.raw = raw;

    quests[id] = q;
    stats.total++;
    stats.bySrc[q.src] = (stats.bySrc[q.src] || 0) + 1;
    stats.byCat[q.cat] = (stats.byCat[q.cat] || 0) + 1;
    if (q.offered) stats.offered++;
  }
  log(`quests: ${stats.total} (${JSON.stringify(stats.bySrc)}), offered by an NPC ${stats.offered}, objectives ${stats.objectives} ${JSON.stringify(stats.objectivesByKind)}`);
  log(`legacy objectives: ${stats.legacyObjectives}, targets inferred ${stats.legacyInferred}, server-scripted ${stats.legacyScripted || 0}; inference self-test on renew rows: ${stats.inferenceCheck[0]}/${stats.inferenceCheck[1]} right, ${stats.inferenceCheck[2]} wrong, no guess ${stats.inferenceCheck[1] - stats.inferenceCheck[0] - stats.inferenceCheck[2]} (by method ${JSON.stringify(stats.inferenceByHow || {})})`);

  // ---------------------------------------------------------------- prerequisite typos
  // quest.csv P_QuestIndex of 8901..8905 reads 1900..1904 (missing / empty stub rows) instead of 8900..8904. Generic repair:
  // a prereq that does not exist or is an untitled stub row becomes id-1 when id-1 hands off to this quest
  // (its turn-in NPC is this quest's giver). The original value is kept as prereqRaw.
  let prereqFixed = 0;
  for (const q of Object.values(quests)) {
    if (!q.prereq || q.prereq === q.id - 1) continue;
    const p = quests[q.prereq];
    const stub = !p || !p.title;
    const prev = quests[q.id - 1];
    if (stub && prev && prev.turnIn && q.giver && prev.turnIn.npc === q.giver.npc) { q.prereqRaw = q.prereq; q.prereq = q.id - 1; prereqFixed++; }
  }
  log(`prerequisite typos repaired: ${prereqFixed}`);

  // ---------------------------------------------------------------- suggested spots for unplaced quest NPCs
  // (event / server-spawned NPCs and the Arcadia NPCs have no row in any npc_<map>.csv). One deterministic guess per NPC:
  // a ring (radius 4 cells) around the map's quest hub = the placed NPC on that map that lists the most quests, else any
  // placed NPC there, else the map's first warp location. Flagged posGuess so the engine can tell it from real data.
  const unplaced = new Map(); // npc -> Map(map -> uses)
  for (const q of Object.values(quests)) for (const r of [q.giver, q.turnIn]) {
    if (!r || !r.unplaced || r.map === undefined) continue;
    if (!unplaced.has(r.npc)) unplaced.set(r.npc, new Map());
    unplaced.get(r.npc).set(r.map, (unplaced.get(r.npc).get(r.map) || 0) + 1);
  }
  const questJobCount = (npc) => (NPC[npc]?.jobs || []).filter(([jt]) => QUEST_JOBS[jt] || OFFICE_JOBS[jt]).length;
  const anchors = new Map();
  const anchorOf = (map) => {
    if (anchors.has(map)) return anchors.get(map);
    let best = null;
    for (const [npc, ps] of npcPos) for (const p of ps) if (p.map === map) { const s = questJobCount(npc); if (!best || s > best.s || (s === best.s && npc < best.npc)) best = { s, npc, x: p.x, y: p.y }; }
    let a = best ? { x: best.x, y: best.y, from: `npc:${best.npc}` } : null;
    if (!a) { const l = [...locations].filter(([, v]) => v.map === map).sort((x, y) => x[0] - y[0])[0]; if (l) a = { x: l[1].x, y: l[1].y, from: `location:${l[0]}` }; }
    anchors.set(map, a); return a;
  };
  const guess = new Map(); // `${npc}:${map}` -> {pos, from}
  const byMapN = new Map();
  for (const [npc, ms] of [...unplaced].sort((a, b) => a[0] - b[0])) for (const map of ms.keys()) { if (!byMapN.has(map)) byMapN.set(map, []); byMapN.get(map).push(npc); }
  for (const [map, list] of byMapN) {
    const a = anchorOf(map); if (!a) continue;
    list.forEach((npc, i) => { const ang = (2 * Math.PI * i) / list.length; guess.set(`${npc}:${map}`, { pos: [Math.round((a.x + 4 * Math.cos(ang)) * 100) / 100, Math.round((a.y + 4 * Math.sin(ang)) * 100) / 100], from: a.from }); });
  }
  let guessed = 0;
  for (const q of Object.values(quests)) for (const r of [q.giver, q.turnIn]) {
    if (!r || !r.unplaced) continue;
    const g = guess.get(`${r.npc}:${r.map}`); if (!g) continue;
    r.pos = g.pos; r.posGuess = g.from; guessed++;
  }
  log(`unplaced quest NPCs: ${unplaced.size} (${guessed} giver/turn-in refs given a suggested spot)`);

  // ---------------------------------------------------------------- groups (quest-log headers: ParentIndex)
  const groups = {};
  for (const q of Object.values(quests)) {
    if (q.parent === q.id) continue;
    if (!groups[q.parent]) groups[q.parent] = { title: qstr(q.parent, 1) ?? qstr(q.parent, 11) ?? quests[q.parent]?.title ?? null, desc: qstr(q.parent, 2) ?? null, quests: [] };
    groups[q.parent].quests.push(q.id);
  }

  // ---------------------------------------------------------------- quest-line graph
  const lines = buildLines(quests);
  log(`quest lines: main ${lines.main.quests} quests in ${lines.main.chains.length} chains (${lines.main.bands.length} level bands), growth ${lines.growth.chains.length} chains`);

  // ---------------------------------------------------------------- level guide + request boards
  const notices = [];
  T.notice.rows.forEach((r, i) => {
    if (!isNumCell(r[0])) return;
    const range = str(r[1]).split(/\s+/).map(Number);
    const q = num(r[5]);
    notices.push({ level: num(r[0]), show: range.length === 2 ? range : [range[0] || 0, 250], quest: q, subject: lcsv('script#questnotice.csv', 2, i + 1) || kr(r[2]), npc: lcsv('script#questnotice.csv', 3, i + 1) || kr(r[3]), location: lcsv('script#questnotice.csv', 4, i + 1) || kr(r[4]) });
    useRef('quest', q, 'questnotice');
  });
  const offices = [];
  T.office.rows.forEach((r, i) => {
    if (!isNumCell(r[0])) return;
    offices.push({ quest: num(r[0]), level: [num(r[1]), num(r[2])], subject: lcsv('request_quest#quest_office.csv', 3, i + 1) || kr(r[3]), npc: num(r[4]), price: num(r[5]), reward: lcsv('request_quest#quest_office.csv', 6, i + 1) || kr(r[6]) });
    useRef('quest', num(r[0]), 'quest_office'); useRef('npc', num(r[4]), 'quest_office');
  });
  const boards = {};
  for (const [k, s] of officeSets) boards[k] = { ...s, npcs: officeNpcs.get(k) || [] };
  for (const s of officeSets.values()) for (const q of s.quests) useRef('quest', q, 'office_set');

  // ---------------------------------------------------------------- dialogs.json
  const dialogOut = {};
  const dstats = { quests: 0, messages: 0, resolved: 0, unresolved: 0, listedRows: [0, 0], offeredRows: [0, 0], offeredPages: [0, 0], offeredPagesMissing: [], unresolvedList: [], orphanCates: 0 };
  for (const [q, d] of [...dialogs].sort((a, b) => a[0] - b[0])) {
    const cate = q; // strings live under the quest's own cate
    const e = { file: d.file, listed: d.listed };
    if (d.header !== null && d.header !== q) e.header = d.header;
    e.messages = d.messages;
    const off = !!quests[q]?.offered;
    for (const [, code] of d.messages) {
      const ok = qs.get(cate)?.has(code) || (d.header !== null && qs.get(d.header)?.has(code));
      dstats.messages++;
      if (d.listed) { dstats.listedRows[1]++; if (ok) dstats.listedRows[0]++; }
      if (d.listed && off) { dstats.offeredRows[1]++; if (ok) dstats.offeredRows[0]++; }
      // dialog pages (message ids >= 10000: offer / reply / progress / completion pages; lower ids are mostly
      // [message] system lines that the files list as boilerplate whether the quest uses them or not)
      const page = d.messages.find((m) => m[1] === code)?.[0] >= 10000;
      if (d.listed && off && page) { dstats.offeredPages[1]++; if (ok) dstats.offeredPages[0]++; else if (!dstats.offeredPagesMissing.includes(q)) dstats.offeredPagesMissing.push(q); }
      if (ok) dstats.resolved++; else { dstats.unresolved++; if (dstats.unresolvedList.length < 40) dstats.unresolvedList.push(`${q}:${code}`); }
    }
    // navigation: option -> page it opens (nextPage rule), over the pages that have text
    const hasTxt = (code) => qs.get(cate)?.has(code) || (d.header !== null && qs.get(d.header)?.has(code));
    const tm = new Map(d.messages.filter((m) => hasTxt(m[1])).map((m) => [m[0], m]));
    const next = {};
    for (const [p, , opts] of tm.values()) for (const o of opts) { const nx = nextPage(tm, p, o); if (nx !== undefined) next[o] = nx; }
    if (Object.keys(next).length) e.next = next;
    // state entry pages (multiples of 1000 with text): which one the NPC opens depends on the quest state (see quests.md)
    const entries = [...tm.keys()].filter((m) => m >= 1000 && m % 1000 === 0).sort((a, b) => a - b);
    if (entries.length) e.entries = entries;
    if (d.alt.length) e.alt = d.alt.map((a) => ({ file: a.file, messages: a.messages }));
    dialogOut[q] = e; dstats.quests++;
  }
  const questStrings = {};
  for (const [cate, m] of [...qs].sort((a, b) => a[0] - b[0])) {
    const o = {}; for (const [code, text] of [...m].sort((a, b) => a[0] - b[0])) o[code] = text;
    questStrings[cate] = o;
    if (!quests[cate] && !dialogs.has(cate)) dstats.orphanCates++;
  }
  const objectiveStrings = {};
  for (const [cate, m] of objTxt) { const o = {}; for (const [code, text] of m) o[code] = text; objectiveStrings[cate] = o; }
  const common = {};
  T.common.rows.forEach((r, i) => { if (isNumCell(r[0])) common[num(r[0])] = lcsv('quest#quest_commonstring.csv', 1, i + 1) ?? kr(r[1]); });

  // NPC generic dialog: name / title (stringtable_job), greeting (stringtable_conv), menu labels (stringtable_jobtype)
  const tbl = (rel) => { const t = parseCateStringTable(readRel(rel)); return t.cates; };
  const convT = tbl('script/string/npc/stringtable_conv.txt'), jobT = tbl('script/string/npc/stringtable_job.txt'), jtT = tbl('script/string/npc/stringtable_jobtype.txt');
  const sget = (tables, file, cate, code) => ltxt(file, cate, code) ?? (tables.get(cate)?.get(code) != null ? kr(tables.get(cate).get(code)) : null);
  const lineFeed = new Map();
  { const t = loadCsv('script/dialog/dialoglinefeed.csv'); for (const r of t.rows) { if (!isNumCell(r[0])) continue; const k = num(r[0]); if (!lineFeed.has(k)) lineFeed.set(k, []); lineFeed.get(k).push([num(r[2]), num(r[3]), num(r[4])]); } }
  const npcDialogs = {};
  const nstats = { npcs: 0, greeting: 0, title: 0, jobs: 0, jobLabels: 0 };
  for (const [id, n] of Object.entries(NPC)) {
    const e = { name: n.name };
    const jobStr = n.desc != null ? sget(jobT, 'stringtable_job.txt', 10, n.desc) : null;
    if (jobStr) { const m = /^(.*?)\s*\((.*)\)\s*$/.exec(jobStr); e.fullName = jobStr; if (m) e.title = m[2]; nstats.title++; }
    const greet = n.comm != null ? sget(convT, 'stringtable_conv.txt', 0, n.comm) : null;
    if (greet) { e.greeting = greet; e.comm = n.comm; nstats.greeting++; }
    const jobs = [];
    for (const [jt, ji] of n.jobs || []) {
      const j = [jt, ji];
      let label = null;
      if (QUEST_JOBS[jt]) label = quests[ji]?.title ?? qstr(ji, 11) ?? null;
      else if (OFFICE_JOBS[jt]) label = officeSets.get(`${jt}:${ji}`)?.name ?? null;
      if (!label) label = sget(jtT, 'stringtable_jobtype.txt', 200, jt);
      if (label) { j.push(label.split('\n')[0]); nstats.jobLabels++; }
      jobs.push(j); nstats.jobs++;
    }
    if (jobs.length) e.jobs = jobs;
    if (lineFeed.has(+id)) e.lineFeed = lineFeed.get(+id);
    npcDialogs[id] = e; nstats.npcs++;
  }
  const jobTypeLabels = {};
  for (const [code, text] of jtT.get(200) || []) jobTypeLabels[code] = sget(jtT, 'stringtable_jobtype.txt', 200, code) ?? kr(text);
  // monster chatter (share/support/monsterdialogue/monsterdialogue.csv)
  const monsterTalk = {};
  { const rel = 'share/support/monsterdialogue/monsterdialogue.csv';
    if (existsRel(rel)) {
      const t = loadCsv(rel); const cc = colIndex(t.header);
      t.rows.forEach((r, i) => {
        if (!isNumCell(r[0])) return;
        const g = (h) => { const ci = cc[h]; if (ci === undefined) return null; const v = lcsv('monsterdialogue#monsterdialogue.csv', ci, i + 1) ?? kr(r[ci]); return v && v !== '0' ? v : null; };
        const e = {};
        for (const [k, pfx] of [['create', 'CreateDlg_'], ['idle', 'IdleDlg_'], ['attack', 'AttackDlg_'], ['die', 'DieDlg_']]) { const a = [1, 2, 3].map((n) => g(pfx + n)).filter(Boolean); if (a.length) e[k] = a; }
        if (!Object.keys(e).length) return;
        e.time = [num(r[cc.timeMin]), num(r[cc.timeMax])]; e.chance = num(r[cc.Probability]); if (num(r[cc.HasDlg])) e.has = 1;
        monsterTalk[num(r[0])] = e;
        useRef('monster', num(r[0]), 'monsterdialogue');
      });
    } }

  // ---------------------------------------------------------------- assets used by the quest UI / NPC marks (verified)
  const assets = {
    sounds: { accept: 'sound/quest_accept.wav', complete: 'sound/quest_finish.wav', giveUp: 'sound/quest_qive_up.wav', missionStart: 'sound/word_missionstart.wav' },
    npcMarks: {
      note: 'NPC overhead quest marks are effect scenes in property/effect/effectscene.02.txt: quest_point* (P mesh = "!", quest available) and quest_Q_* (Q mesh = "?", quest ready to turn in). Colour meaning is not in the data (see quests.md).',
      effectSceneFile: 'property/effect/effectscene.02.txt',
      scenes: { available: 'quest_point', availableBlue: 'quest_point_blue', availableRed: 'quest_point_red', availableViolet: 'quest_point_violetblue', completeGray: 'quest_q_gray', completeYellow: 'quest_q_yellow', completeBlue: 'quest_q_blue', completeRed: 'quest_q_red', completeViolet: 'quest_q_violetblue' },
      // effect ids in effectscene.02.txt (names there are mixed case: quest_Q_gray, quest_point_VioletBlue ...)
      effectIds: { quest_point: 2551, quest_Q_gray: 2552, quest_Q_yellow: 2553, quest_point_blue: 2829, quest_Q_blue: 2830, quest_Q_red: 2877, quest_point_red: 2878, quest_point_VioletBlue: 20098, quest_Q_VioletBlue: 20099, quest_end: 1122, Quest_Q_mesh: 2590 },
      meshes: { point: 'mesh/effect/quest_mark_p.mesh', pointGlow: 'mesh/effect/quest_mark_p#.mesh', question: 'mesh/effect/quest_mark_q.mesh', questionGlow: 'mesh/effect/quest_mark_q#.mesh' },
      texturePacks: Object.fromEntries(['yellow', 'blue', 'red', 'gray', 'violetblue'].flatMap((c) => [[c, `texturepack/effect/ui/quest_mark_${c}.tpack`], [`${c}Glow`, `texturepack/effect/ui/quest_mark_${c}#.tpack`]])),
      textures: Object.fromEntries(['yellow', 'blue', 'red', 'gray', 'violetblue'].flatMap((c) => [[c, `texture/effect/ui/quest_${c}.dds`], [`${c}Glow`, `texture/effect/ui/quest_${c}#.dds`]])),
    },
    rewardProps: { goldBox: ['mesh/effect/quest/que_goldbox.mesh', 'anim/effect/quest/que_goldbox.anim'], grayBox: ['mesh/effect/quest/que_graybox.mesh', 'anim/effect/quest/que_graybox.anim'], goldScroll: ['mesh/effect/quest/que_goldscroll.mesh', 'anim/effect/quest/que_goldscroll.anim'] },
    ui: {
      questWindow: 'script/ui/game2/quest/ui_new_quest.txt', questWindowOld: 'script/ui/game2/quest/ui_quest.txt', tracker: 'script/ui/game2/quest/ui_new_questassist.txt', trackerOld: 'script/ui/game2/quest/ui_questassist.txt',
      clientQuestList: 'script/ui/game2/quest/ui_clientquestlist.txt', startDialog: 'script/ui/game2/ui_quest_start_dialog.txt', completeDialog: 'script/ui/game2/ui_quest_complet_dialog.txt',
      npcDialog: 'script/ui/game2/ui_dialog_renewal.txt', npcDialogOld: 'script/ui/game2/ui_dialog.txt',
      textures: ['texture/ui/game/quest/newquest_01.dds', 'texture/ui/game/quest/newquest_02.dds', 'texture/ui/game/quest/quest_01.dds', 'texture/ui/game/quest/quest_02.dds', 'texture/ui/game/quest/quest_memo.dds', 'texture/ui/game/quest/quest_q.dds', 'texture/ui/game/clientquest/new_quest_npc.dds'],
      banners: { missionStart: 'texture/effect/ui/mission_start.dds', missionComplete: 'texture/effect/ui/mission_complete.dds', missionClear: 'texture/effect/ui/mission_clear.dds', missionFail: 'texture/effect/ui/mission_fail.dds' },
    },
  };
  const assetKeys = [];
  const walk = (o) => { if (typeof o === 'string') { if (/^(sound|mesh|anim|texture|texturepack|script|property|share)\//.test(o)) assetKeys.push(o); } else if (Array.isArray(o)) o.forEach(walk); else if (o && typeof o === 'object') Object.values(o).forEach(walk); };
  walk(assets);
  for (const d of Object.values(dialogOut)) { assetKeys.push(d.file); for (const a of d.alt || []) assetKeys.push(a.file); }
  { // the effect ids must match effectscene.02.txt
    const es = readText(assets.npcMarks.effectSceneFile).split(/\r?\n/);
    const idByName = new Map();
    for (let i = 1; i < es.length; i++) { const m = /^\s*name\s+(\S+)/.exec(es[i]); const p = /^\s*id\s+(\d+)/.exec(es[i - 1]); if (m && p) idByName.set(m[1], +p[1]); }
    for (const [n, id] of Object.entries(assets.npcMarks.effectIds)) if (idByName.get(n) !== id) hard(`effect ${n}: id ${id} does not match effectscene.02.txt (${idByName.get(n)})`);
  }
  let assetsOk = 0;
  for (const k of assetKeys) { if (k !== k.toLowerCase()) hard(`asset key not lower case: ${k}`); if (has(k)) assetsOk++; else hard(`asset key does not exist: ${k}`); }
  log(`asset keys: ${assetsOk}/${assetKeys.length} exist`);

  // ---------------------------------------------------------------- cross-reference validation
  const exists = {
    monster: (x) => !!MON[x], item: (x) => items.has(x), npc: (x) => !!NPC[x], map: (x) => maps.has(x) || x === 0, skill: (x) => skills.has(x),
    location: (x) => locations.has(x), title: (x) => titles.has(x), status: (x) => statuses.has(x), quest: (x) => !!quests[x],
  };
  const xref = {};
  for (const [kind, m] of Object.entries(refs)) {
    const missing = [...m.entries()].filter(([x]) => !exists[kind](x));
    xref[kind] = { referenced: m.size, resolved: m.size - missing.length, missing: missing.slice(0, 60).map(([x, w]) => `${x} (${w})`), missingCount: missing.length };
    if (missing.length) soft(`${kind}: ${missing.length}/${m.size} referenced ids do not resolve, e.g. ${missing.slice(0, 5).map(([x, w]) => `${x}@${w}`).join(', ')}`);
  }
  // renew rows must resolve their core targets (monster / npc / map indices come from the same client)
  for (const k of ['monster', 'npc']) { const pct = xref[k].referenced ? (100 * xref[k].resolved) / xref[k].referenced : 100; if (pct < 95) hard(`${k} references resolve for only ${pct.toFixed(1)}%`); }

  // ---------------------------------------------------------------- output
  const report = {
    strings: strStats, dialogs: { ...dialogStats, headerMismatch: dialogStats.headerMismatch.slice(0, 30), headerMismatchCount: dialogStats.headerMismatch.length, ...dstats }, npcDialogs: nstats,
    quests: { ...stats, maxCountAgree: `${stats.maxCountAgree[1]}/${stats.maxCountAgree[0]}`, journalRewardAgree: { exp: `${stats.journalRewardAgree.exp[1]}/${stats.journalRewardAgree.exp[0]}`, dil: `${stats.journalRewardAgree.dil[1]}/${stats.journalRewardAgree.dil[0]}` } },
    xref, itemNameAgreement: `${itemLocAgree[1]}/${itemLocAgree[0]}`, lines: lines.report,
    specificPeriodSchedule: { present: !T.sched.missing, entries: I.sched.map.size },
  };
  const questsOut = {
    format: 'dekaron-solo/quests@1', generatedBy: 'tools/build-quests.mjs', doc: 'docs/formats/quests.md',
    units: { position: 'NPC / callMonster pos = map cells in the file frame (same as npcs.json placements: three.js (x, h, -y))', chance: 'probability 0..1 (source columns are per 100000)', level: '[min, max] (max 250 = no cap; 0 = not set)' },
    enums: { renewType: RENEW_TYPE, clientType: CLIENT_TYPE, objectiveKind: OBJ_KIND, questJobs: QUEST_JOBS, officeJobs: OFFICE_JOBS, flowIds: FLOW_IDS },
    quests, groups, lines, notices, requestBoards: { boards, offices }, assets, report,
  };
  const dialogsOut = {
    format: 'dekaron-solo/dialogs@1', generatedBy: 'tools/build-quests.mjs', doc: 'docs/formats/quests.md',
    markup: {
      newline: '\\n (the client uses a backslash in lines_eu / new lines in the .txt tables)',
      tags: { '<color=RRGGBB>..</color>': 'text colour', '<font=N>..</font>': 'font (4 = bold header)', '<center>': 'centre the line', '[nlink]N[/nlink]': 'NPC N name, clickable (navigate to the NPC)', '[mlink]N[/mlink]': 'monster N name', '[ilink]N[/ilink]': 'item N name (tooltip)', '[elink]N[/elink][Label]': 'navigation link to NPC N shown as Label', '[Label][vlink]N[/vlink]': 'navigation link to monster N shown as Label', '<img screen=.. index=.. width=.. height=..>': 'inline UI image' },
      placeholders: { '<COUNTk>': 'current count of objective slot k', '<MAX_COUNTk>': 'required count of slot k', '<Object_k>': 'objective slot k label', '<code N>': 'string code N of the same quest (e.g. <code 11> = title)', '<COUNT>/<MAX_COUNT>': 'objective-string progress (stringtable_quest_objectstring)' },
      messagePrefix: '[message] = system chat / notice line, not a dialog page',
    },
    messageFields: ['message', 'stringCode', 'options'],
    navigation: 'next[option] = page opened by that option (option p+n on page p opens p+n*10, else p+n*100, else the dialog closes); entries = state entry pages (multiples of 1000 with text)',
    quests: dialogOut, strings: questStrings, objectiveStrings, common, npcs: npcDialogs, jobTypeLabels, monsterTalk,
    report: { dialogs: dstats, npcs: nstats },
  };

  // ---------------------------------------------------------------- spot check: 10 quests re-read from the raw csv lines
  // (a plain split, independent of parseCSV / the mapping above) and compared field by field with the JSON
  const SPOT_IDS = [51, 121, 201, 611, 1101, 1625, 5286, 9414, 21, 8903];
  const rawRow = (rel, col, id) => {
    const lines = readText(rel).split(/\r?\n/); const h = lines[0].split(',').map((x) => x.trim());
    const l = lines.find((x) => x.split(',')[col] === String(id)); if (!l) return null;
    const c = l.split(','); const o = {}; h.forEach((k, i) => { o[k] = (c[i] ?? '').trim(); }); return o;
  };
  const spot = [];
  for (const id of SPOT_IDS) {
    const q = quests[id]; const fails = [];
    const eq = (what, a, b) => { if (JSON.stringify(a) !== JSON.stringify(b)) fails.push(`${what}: json ${JSON.stringify(a)} != raw ${JSON.stringify(b)}`); };
    const rn = rawRow('share/quest/questtable_renew.csv', 1, id), rw = rawRow('share/quest/quest_rewardlist.csv', 0, id), cl = rawRow('script/quest/quest.csv', 0, id), dr = rawRow('share/quest/questdropitem.csv', 0, id);
    if (!q) { spot.push({ id, ok: false, fails: ['missing'] }); continue; }
    if (rn) {
      eq('level', q.level, [+rn.Min_Level, +rn.Max_Level]);
      eq('giver', q.giver?.npc, +rn.S_npc.split('/')[0]);
      eq('turnIn', q.turnIn?.npc, +rn.E_npc.split('/')[0]);
      for (let k = 1; k <= 10; k++) {
        if (!rn[`Index_${k}`] || rn[`Index_${k}`] === '0') continue;
        const o = q.objectives?.find((x) => !x.extra && x.slot === +rn[`Index_Object_Number_${k}`]);
        eq(`objective ${k} targets`, o?.targets.map((t) => t.id), rn[`Index_${k}`].split('/').map(Number));
        eq(`objective ${k} count`, o?.count, +rn[`Index_Succ_Count_${k}`] || 1);
      }
    } else if (cl) {
      eq('level', q.level, [+cl.Level_Min, +cl.Level_Max]);
      if (+cl.S_npc) eq('giver', q.giver?.npc, +cl.S_npc);
      if (+cl.E_npc) eq('turnIn', q.turnIn?.npc, +cl.E_npc);
      for (let s = 0; s < 10; s++) if (cl[`Object_${s}_Enable`] === 'TRUE') eq(`objective slot ${s} count`, q.objectives?.find((x) => x.slot === s)?.count, +cl[`Object_${s}_MaxCount`] || 1);
    }
    if (rw) {
      const r0 = q.rewards || {};
      if (+rw.Exp_Min) eq('exp', r0.exp, +rw.Exp_Min === +rw.Exp_Max ? +rw.Exp_Min : [+rw.Exp_Min, +rw.Exp_Max]);
      if (+rw.Money_Min) eq('dil', r0.dil, +rw.Money_Min === +rw.Money_Max ? +rw.Money_Min : [+rw.Money_Min, +rw.Money_Max]);
      const its = []; for (let k = 1; k <= 10; k++) if (rw[`Item_Index_${k}`] && rw[`Item_Index_${k}`] !== '0') its.push(+rw[`Item_Index_${k}`]);
      eq('reward items', (r0.items || []).map((x) => x.item), its);
      if (+rw.NextIndex) eq('next', q.next, +rw.NextIndex);
    }
    if (dr) { const d = []; for (let k = 0; k < 10; k++) if (+dr[`DropItemIndex_${k}`]) d.push([+dr[`MonsterIndex_${k}`], +dr[`DropItemIndex_${k}`], +dr[`DropRatio_${k}`] / 100000]); eq('drops', (q.drops || []).map((x) => [x.monsters[0], x.item, x.chance]), d); }
    const lf = rawRow('share/quest/questfilelist.csv', 0, id) || rawRow('share/quest/periodquestfilelist.csv', 0, id);
    if (lf) eq('dialog file', q.dialog?.file, `share/quest/${(lf.TextFileName).toLowerCase()}`);
    spot.push({ id, ok: !fails.length, fails });
  }
  const spotOk = spot.filter((s) => s.ok).length;
  log(`spot check vs raw csv: ${spotOk}/${spot.length} quests identical${spot.filter((s) => !s.ok).map((s) => `\n  ! ${s.id}: ${s.fails.join('; ')}`).join('')}`);
  if (spotOk !== spot.length) hard(`spot check: ${spot.length - spotOk} quests differ from the raw rows`);
  questsOut.report.spotCheck = spot;

  // spot check print
  for (const id of SPOT) console.log(`\n--- spot ${id}\n${JSON.stringify(quests[id], null, 1)}\n${JSON.stringify(dialogOut[id] ? { ...dialogOut[id], messages: dialogOut[id].messages.slice(0, 6) } : null)}`);

  fs.mkdirSync(OUTDIR, { recursive: true });
  const write = (name, obj) => { const p = path.join(OUTDIR, name); const s = PRETTY ? JSON.stringify(obj, null, 1) : JSON.stringify(obj); fs.writeFileSync(p, s); log(`wrote ${path.relative(ENGINE, p)} (${(s.length / 1024).toFixed(0)} KiB)`); };
  write('quests.json', questsOut);
  write('dialogs.json', dialogsOut);

  log('');
  log(`dialog rows: ${dstats.messages}, string code resolved ${dstats.resolved} (${((100 * dstats.resolved) / Math.max(1, dstats.messages)).toFixed(1)}%); listed files ${dstats.listedRows[0]}/${dstats.listedRows[1]}; listed files of NPC-offered quests ${dstats.offeredRows[0]}/${dstats.offeredRows[1]}, their dialog pages ${dstats.offeredPages[0]}/${dstats.offeredPages[1]} (${dstats.offeredPagesMissing.length} quests lack some page text)`);
  log(`givers placed ${stats.giverPlaced}/${stats.giverTotal}, turn-ins placed ${stats.turnInPlaced}/${stats.turnInTotal}; objective counts agree with quest.csv ${report.quests.maxCountAgree}; journal EXP text == table ${report.quests.journalRewardAgree.exp}, DIL ${report.quests.journalRewardAgree.dil}`);
  for (const [k, v] of Object.entries(xref)) log(`xref ${k}: ${v.resolved}/${v.referenced}`);
  log(`soft issues: ${problems.soft.length}`);
  for (const s of problems.soft.slice(0, 30)) log(`  - ${s}`);
  log(`HARD failures: ${problems.hard.length}`);
  for (const s of problems.hard.slice(0, 40)) log(`  ! ${s}`);
  log(`done in ${((Date.now() - t0) / 1000).toFixed(1)} s`);
  process.exitCode = problems.hard.length ? 1 : 0;
}

// ================================================================================================
// quest-line graph: main story chains (per level band), growth line, and the plain edge list
// ================================================================================================
export function buildLines(quests) {
  const Q = quests;
  const isMain = (q) => q && q.cat === 'main';
  const isGrowth = (q) => q && q.cat === 'growth';
  const chainsOf = (pred) => {
    const ids = Object.values(Q).filter(pred).map((q) => q.id);
    const set = new Set(ids);
    const succ = new Map();
    const addEdge = (a, b) => { if (!set.has(a) || !set.has(b) || a === b) return; if (!succ.has(a)) succ.set(a, new Set()); succ.get(a).add(b); };
    for (const id of ids) { const q = Q[id]; if (q.next) addEdge(id, q.next); if (q.prereq) addEdge(q.prereq, id); }
    const indeg = new Map(ids.map((i) => [i, 0]));
    for (const [, bs] of succ) for (const b of bs) indeg.set(b, (indeg.get(b) || 0) + 1);
    const visited = new Set(); const chains = [];
    const lvl = (i) => (Q[i].level ? Q[i].level[0] : Q[i].listLevel || 0);
    const roots = ids.filter((i) => indeg.get(i) === 0).sort((a, b) => lvl(a) - lvl(b) || a - b);
    const walk = (start) => {
      const chain = []; let cur = start;
      while (cur !== undefined && !visited.has(cur)) {
        visited.add(cur); chain.push(cur);
        const nx = [...(succ.get(cur) || [])].filter((b) => !visited.has(b)).sort((a, b) => lvl(a) - lvl(b) || a - b);
        cur = nx[0];
        for (const other of nx.slice(1)) pending.push(other);
      }
      return chain;
    };
    const pending = [];
    const drain = () => { while (pending.length) { const s = pending.shift(); if (!visited.has(s)) chains.push(walk(s)); } };
    for (const r of roots) { pending.push(r); drain(); }
    for (const i of ids.sort((a, b) => a - b)) if (!visited.has(i)) { pending.push(i); drain(); } // cycles
    return chains.map((ch) => {
      const lv = ch.map(lvl);
      const maps = [...new Set(ch.map((i) => Q[i].map ?? Q[i].giver?.map).filter((m) => m !== undefined))];
      const o = { start: ch[0], title: Q[ch[0]].title, level: [Math.min(...lv), Math.max(...lv)], maps, quests: ch, offered: ch.filter((i) => Q[i].offered).length };
      if (ch.every((i) => Q[i].src === 'server')) o.serverOnly = true; // renew rows with no client text / NPC (not in this client's story)
      if (ch.every((i) => Q[i].src === 'client')) o.legacy = true;
      return o;
    });
  };
  const mainChains = chainsOf(isMain);
  // the playable story: chains with client text, ordered by level (the data bridges level gaps by level, not by prereq)
  const story = mainChains.filter((c) => !c.serverOnly).sort((a, b) => a.level[0] - b.level[0] || a.start - b.start).map((c) => c.start);
  const bands = [];
  const bandOf = (l) => (l <= 0 ? -1 : Math.floor((l - 1) / 10));
  const bandMap = new Map();
  for (const ch of mainChains) {
    if (ch.serverOnly) continue;
    for (const i of ch.quests) {
      const q = Q[i]; const l = q.level ? q.level[0] : q.listLevel || 0; const b = bandOf(l);
      if (!bandMap.has(b)) bandMap.set(b, []);
      bandMap.get(b).push(i);
    }
  }
  for (const [b, list] of [...bandMap].sort((a, b2) => a[0] - b2[0])) bands.push({ band: b < 0 ? 'unset' : `${b * 10 + 1}-${b * 10 + 10}`, quests: list });
  const growth = chainsOf(isGrowth);
  // full edge list (every quest)
  const edges = [];
  for (const q of Object.values(Q)) { if (q.prereq) edges.push([q.prereq, q.id, 'prereq']); if (q.next) edges.push([q.id, q.next, 'next']); if (q.going) edges.push([q.going, q.id, 'going']); }
  const dangling = edges.filter(([a, b]) => !Q[a] || !Q[b]).map((e) => e.join(':'));
  const selfLoops = Object.values(Q).filter((q) => q.prereqClient === q.id).map((q) => q.id);
  const mainCount = Object.values(Q).filter(isMain).length;
  return {
    main: { quests: mainCount, story, chains: mainChains, bands },
    growth: { chains: growth },
    edges,
    report: { mainQuests: mainCount, mainChains: mainChains.length, longestMainChain: Math.max(0, ...mainChains.map((c) => c.quests.length)), edges: edges.length, dangling: dangling.slice(0, 40), danglingCount: dangling.length, selfLoops },
  };
}

// run only when executed directly (the parse* exports can be imported without side effects)
if (process.argv[1] && path.resolve(process.argv[1]) === fileURLToPath(import.meta.url)) main();
