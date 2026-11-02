#!/usr/bin/env node
// Dekaron Solo — dungeon / instance / map-transition database builder.
//
//   node tools/build-dungeons.mjs [--data <unpacked data root>] [--out <dir>] [--pretty] [--quiet] [--no-mac]
//
// Reads the user's own unpacked client (default ../data/unpacked/data next to the engine) and writes
//   gamedata/dungeons.json         every dungeon (share/dungeonlist.csv + instance/event maps of share/maplist.csv),
//                                  per-map script data (message/dialog tables resolved to English text, static +
//                                  scripted spawn waves, script-watched monsters, bosses, bricks (gates/walls),
//                                  triggers (levers/boxes), DUNGEON_SCRIPT NPCs, entry/exit points, time limits,
//                                  reconstructed stage flow), brick + trigger definitions with visuals, reward tables.
//   gamedata/dungeons_travel.json  map transitions: location table, walk-in warp zones, portal network, NPC teleport
//                                  menus, sky/siege/premiere teleports, smart-warp list, respawn tables, start points,
//                                  and a map graph (which map leads to which, and how).
// Every asset path in the output is a lower-case data key (fetch as /data/<key>) that was verified to exist on disk.
// The run doubles as the validation script: counts, cross-references (monster / NPC / item / map / location / brick /
// trigger indices, mesh / anim / skel / texture pack paths), walkability of placements against the .mac grids and 10
// hand-picked spot checks against the raw files are printed; exit code 1 on hard failures.
// Format + semantics: docs/formats/dungeons.md
//
// The parse* functions are pure (string / bytes in, plain objects out) so they can move to src/formats/ unchanged.

import { makeNameIndex, resolveRef } from './asset-ref-resolve.mjs';
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { parseCSV, stripBOM } from '../src/formats/binreader.js';
import {
  parseSpawnCSV, parseNpcCSV, parseBrickCSV, parseCallMonsterCSV, parseLocationCSV, parseMapPointCSV, dataKey as pathKey,
} from '../src/formats/spawn.js';
import { parseMac, nearestWalkable } from '../src/formats/mac.js';
import { parseMol } from '../src/formats/mol.js';
import { parseLinesEu, parseActDat, parseActCsv } from './build-monsters.mjs';

// ------------------------------------------------------------------------------------------------
// text helpers (pure)
// ------------------------------------------------------------------------------------------------
const KR = (() => { try { return new TextDecoder('euc-kr'); } catch { return new TextDecoder('latin1'); } })();
export const decodeKr = (u8) => KR.decode(stripBOM(u8));   // a UTF-8 BOM (Global edit) must not become part of the first header cell
const num = (v, d = 0) => { const x = Number(String(v ?? '').trim()); return Number.isFinite(x) ? x : d; };
const numOrNull = (v) => { const s = String(v ?? '').trim(); if (s === '') return null; const x = Number(s); return Number.isFinite(x) ? x : null; };
const round = (x, k = 3) => (Number.isFinite(x) ? Math.round(x * 10 ** k) / 10 ** k : x);
const hasHangul = (s) => /[ㄱ-힝]/.test(String(s || ''));
const clean = (s) => String(s ?? '').replace(/\s+$/, '').trim();
// keyword tokens for the NPC <-> dialog linker
const STOP = new Set(['the', 'and', 'with', 'old', 'dialogue', 'dialog', 'speak', 'operation', 'you', 'your', 'this', 'that', 'will', 'would', 'like', 'mission', 'message', 'color', 'from', 'are', 'for', 'have', 'has', 'can', 'not', 'ok']);
const toks = (s) => new Set(String(s || '').toLowerCase().replace(/<[^>]*>/g, ' ').replace(/[_\-]/g, ' ').replace(/[^a-z0-9 ]+/g, ' ').split(/\s+/).filter((w) => w.length > 2 && !STOP.has(w) && !/^\d+$/.test(w)));
const SYN = { switchgear: ['lever', 'switch'], knob: ['lever'], lever: ['lever'], stairs: ['enter', 'move', 'floor', 'stairs'], potal: ['enter', 'move', 'portal'], statue: ['statue'], reezena: ['reezena', 'exit', 'leave'], stone: ['stone', 'warp'], door: ['door', 'move', 'enter'], gate: ['gate', 'enter'], exit: ['exit', 'leave'], lobby: ['lobby', 'move'], book: ['book', 'read'], slate: ['slate', 'decipher'] };

/** Game path -> data key under a type root: ("Brick\\a.mesh", "mesh") -> "mesh/brick/a.mesh". */
export function rootKey(root, gamePath) {
  let n = String(gamePath ?? '').trim().replace(/\\/g, '/').replace(/\/{2,}/g, '/').replace(/^(\.\.?\/)+/, '').replace(/^\/+/, '').toLowerCase();
  if (!n) return null;
  const r = root.toLowerCase();
  return n.startsWith(r + '/') ? n : `${r}/${n}`;
}

/** Header-keyed table. rows: Array<{_:string[], get(name)}>; duplicate header names get suffixes _2, _3 ... */
export function parseTable(text, { headerRow = 0 } = {}) {
  const all = parseCSV(text);
  const raw = (all[headerRow] || []).map((h) => String(h).trim());
  const seen = new Map();
  const headers = raw.map((h, i) => { const k = h || `col${i}`; const n = (seen.get(k) || 0) + 1; seen.set(k, n); return n === 1 ? k : `${k}_${n}`; });
  const lc = headers.map((h) => h.toLowerCase());
  const rows = [];
  for (let i = headerRow + 1; i < all.length; i++) {
    const r = all[i];
    if (!r || !r.some((c) => String(c).trim() !== '')) continue;
    rows.push(r.map((c) => String(c ?? '').trim()));
  }
  const col = (name) => lc.indexOf(String(name).toLowerCase());
  return { headers, rows, col, get: (r, name) => { const i = col(name); return i < 0 ? '' : (r[i] ?? ''); } };
}

/**
 * Category-aware string table (script/string/**.txt):
 *   <cate> N [#comment]   code N [#comment]   {   text lines   }   </cate>
 * @returns {Map<number, {comment:string, codes:Map<number,{text:string, comment:string}>}>}  (cate -1 = no <cate>)
 */
export function parseCateStringTable(text) {
  const out = new Map();
  let cate = -1, cur = null, code = null, ccom = '', buf = null;
  const ensure = (c, com) => { if (!out.has(c)) out.set(c, { comment: com || '', codes: new Map() }); return out.get(c); };
  cur = ensure(-1);
  for (const raw of String(text).split(/\r?\n/)) {
    const line = raw.replace(/\s+$/, '');
    if (buf) {
      if (line.trim() === '}') {
        while (buf.length && !buf[0].trim()) buf.shift();
        while (buf.length && !buf[buf.length - 1].trim()) buf.pop();
        if (code != null) cur.codes.set(code, { text: buf.join('\n'), comment: ccom });
        buf = null; code = null; ccom = '';
      } else buf.push(line);
      continue;
    }
    let m;
    if ((m = /^\s*<cate>\s*(-?\d+)\s*(.*)$/i.exec(line))) { cate = +m[1]; cur = ensure(cate, m[2].replace(/^#\s*/, '').trim()); continue; }
    if (/^\s*<\/cate>/i.test(line)) { cate = -1; cur = ensure(-1); continue; }
    if ((m = /^\s*code\s+(-?\d+)\s*(.*)$/i.exec(line))) { code = +m[1]; ccom = m[2].replace(/^#\s*/, '').trim(); continue; }
    if (line.trim() === '{' && code != null) buf = [];
  }
  return out;
}

/**
 * Split a message into display text + client directives.
 *   "text@<effectui>2082,1,7000,1@<effectsound>22,1003,25,4@<sound>0,3004"
 *   "Touch the statue. <guage,sec 3000,text The statue ...,snd 22 1028 25 29>"
 * effectui  = UI flash effect: effect-scene id in <cate> 8 UI of property/effect/effectscene.*.txt, ?, duration ms, ?
 * effectsound = sound effect scene (category, id, volume?, ?);  sound = (0 start / 1 stop?, BGM/jingle id)
 * guage (sic) = progress bar shown when the menu entry is chosen: duration ms, caption, sound (cate id vol ?)
 */
export function parseMessageText(s) {
  const fx = [];
  let t = String(s ?? '');
  t = t.replace(/<guage\s*,([^>]*)>/gi, (_, body) => {
    const g = { gauge: true };
    for (const part of body.split(',')) {
      const p = part.trim(); const sp = p.indexOf(' ');
      const k = (sp < 0 ? p : p.slice(0, sp)).toLowerCase(), v = sp < 0 ? '' : p.slice(sp + 1).trim();
      if (k === 'sec') g.ms = num(v); else if (k === 'text') g.text = v; else if (k === 'snd') g.sound = v.split(/\s+/).map(num); else g[k] = v;
    }
    fx.push(g); return '';
  });
  t = t.replace(/@?<(effectui|effectsound|sound)>\s*([-\d, ]+)/gi, (_, k, v) => {
    const a = v.split(',').map((x) => num(x));
    const kk = k.toLowerCase();
    if (kk === 'effectui') fx.push({ ui: a[0], ms: a[2], args: a });
    else if (kk === 'effectsound') fx.push({ sfx: a });
    else fx.push({ sound: a });
    return '';
  });
  t = t.replace(/@+\s*$/g, '').replace(/^\s*@+/, '').replace(/\s+$/, '');
  return { t, fx };
}

/** "10 minutes" / "1 hour" / "30 Min" / "90 sec" -> seconds (null when no duration found). */
export function parseDuration(s) {
  const txt = String(s ?? '');
  let sec = 0, found = false;
  const re = /(\d+(?:\.\d+)?)\s*(hours?|hrs?|h\b|minutes?|mins?|m\b|seconds?|secs?|s\b|시간|분|초)/gi;
  let m;
  while ((m = re.exec(txt))) {
    const v = +m[1], u = m[2].toLowerCase();
    sec += (u.startsWith('h') || u === '시간') ? v * 3600 : (u.startsWith('m') || u === '분') ? v * 60 : v; found = true;
  }
  return found ? Math.round(sec) : null;
}

/** share/dungeon/*.csv message table: "DungeonIndex,<n>" / blank / MessageIndex,StringCode,Menu0..MenuN / rows. */
export function parseDungeonMessageCsv(text) {
  const rows = parseCSV(text).map((r) => (r || []).map((c) => String(c ?? '').trim()));
  let index = null, hi = -1;
  for (let i = 0; i < rows.length; i++) {
    if (rows[i][0]?.toLowerCase() === 'dungeonindex') index = numOrNull(rows[i][1]);
    if (rows[i][0]?.toLowerCase() === 'messageindex') { hi = i; break; }
  }
  const messages = [];
  if (hi >= 0) {
    for (const r of rows.slice(hi + 1)) {
      const msg = numOrNull(r[0]); if (msg === null) continue;
      const str = numOrNull(r[1]);
      const menus = r.slice(2).map(numOrNull).filter((v) => v);
      messages.push({ msg, str: str ?? msg, menus });
    }
  }
  return { index, messages, menuColumns: hi >= 0 ? rows[hi].length - 2 : 0 };
}

/** item.dat: 565-byte records, u32 item index at +128, UTF-16LE name key ("item#itemetc.csv#1|5600") at +204. */
export const ITEM_DAT_RECORD = 565;
export function parseItemDatIndex(buf) {
  const u8 = buf instanceof Uint8Array ? buf : new Uint8Array(buf);
  const dv = new DataView(u8.buffer, u8.byteOffset, u8.byteLength);
  const n = Math.floor(u8.byteLength / ITEM_DAT_RECORD);
  const u16 = new TextDecoder('utf-16le');
  const out = new Map();
  for (let r = 0; r < n; r++) {
    const o = r * ITEM_DAT_RECORD;
    const id = dv.getUint32(o + 128, true);
    let e = o + 204; while (e < o + 204 + 256 && (u8[e] | u8[e + 1])) e += 2;
    out.set(id, u16.decode(u8.subarray(o + 204, e)));
  }
  return { items: out, records: n, trailingBytes: u8.byteLength - n * ITEM_DAT_RECORD };
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
const NO_MAC = argv.includes('--no-mac');
const log = (...a) => { if (!QUIET) console.log(...a); };
const problems = { hard: [], soft: [] };
const hard = (m) => problems.hard.push(m);
const soft = (m) => problems.soft.push(m);

const readRel = (rel) => fs.readFileSync(path.join(DATA, rel));
const readKr = (rel) => decodeKr(readRel(rel));
const FILES = new Set();
const BY_DIR = new Map();
function indexDir(sub) {
  const root = path.join(DATA, sub);
  if (!fs.existsSync(root)) { hard(`missing data folder ${sub}`); return; }
  for (const d of fs.readdirSync(root, { recursive: true, withFileTypes: true })) {
    if (!d.isFile()) continue;
    const key = path.relative(DATA, path.join(d.parentPath ?? d.path, d.name)).replace(/\\/g, '/').toLowerCase();
    FILES.add(key);
    const dir = key.slice(0, key.lastIndexOf('/') + 1);
    if (!BY_DIR.has(dir)) BY_DIR.set(dir, []);
    BY_DIR.get(dir).push(key);
  }
}
const has = (k) => !!k && FILES.has(k);
let BY_NAME = null;   // basename -> keys, built once FILES is indexed (asset-ref-resolve.mjs)
const RESOLVED = [];
const resolve = (k) => { if (!k || has(k)) return k; BY_NAME ||= makeNameIndex(FILES); const r = resolveRef(k, has, BY_NAME); if (r.key) { RESOLVED.push(`${r.how}: ${k} -> ${r.key}`); return r.key; } return k; };
const exists = (k) => (has(k) ? k : null);
const shareKey = (p) => { const k = pathKey(p); if (!k) return ''; return k.startsWith('share/') ? k : `share/${k}`; };
const csvKey = (k) => (k && !/\.[a-z0-9]{1,4}$/.test(k.slice(k.lastIndexOf('/') + 1)) ? `${k}.csv` : k);

function main() {
  const t0 = Date.now();
  if (!fs.existsSync(DATA)) { console.error(`data root not found: ${DATA}`); process.exit(2); }
  log(`data root: ${DATA}`);
  for (const sub of ['share', 'script', 'mesh', 'texturepack', 'skel', 'anim', 'map', 'property/effect']) indexDir(sub);
  log(`indexed ${FILES.size} files`);

  // ---------------------------------------------------------------- localisation + reference data
  const wantKey = (k) => /^(share#(dungeonlist|maplist|dkmaplist)|arrange#(location|chaoticlocation)|creature#(brick|trigger)|smartwarp#|premiere#teleport|item#)/i.test(k);
  const L = parseLinesEu(readRel('script/lines_eu'), { keyFilter: wantKey });
  if (L.trailingBytes) hard(`lines_eu: ${L.trailingBytes} trailing bytes`);
  const loc = (key) => { const id = L.csvKeys.get(key); const s = id ? L.strings.get(id) : null; return s && s.trim() ? s.trim() : null; };
  const locCI = (() => { const m = new Map(); for (const [k, id] of L.csvKeys) m.set(k.toLowerCase(), id); return (key) => { const id = m.get(key.toLowerCase()); const s = id ? L.strings.get(id) : null; return s && s.trim() ? s.trim() : null; }; })();

  const itemDat = parseItemDatIndex(readRel('share/item/item.dat'));
  if (itemDat.trailingBytes) hard(`item.dat: ${itemDat.trailingBytes} trailing bytes`);
  const itemName = (id) => { const k = itemDat.items.get(id); return k ? (locCI(k) || k) : null; };
  const itemSetIdx = new Set(parseTable(readKr('share/item/itemset.csv')).rows.map((r) => num(r[0], -1)));
  const itemSetExIdx = FILES.has('share/item/itemsetex.csv') ? new Set(parseTable(readKr('share/item/itemsetex.csv')).rows.map((r) => num(r[0], -1))) : new Set();

  const gd = process.env.DEKARON_GAMEDATA || path.join(ENGINE, 'gamedata');
  const MON = JSON.parse(fs.readFileSync(path.join(gd, 'monsters.json'), 'utf8'));
  const NPC = JSON.parse(fs.readFileSync(path.join(gd, 'npcs.json'), 'utf8'));
  const monsterCsvIdx = new Set(parseTable(readKr('share/creature/monster.csv')).rows.map((r) => num(r[0], -1)));
  const monInfo = (i) => MON.monsters[i] || null;
  const isBossMon = (i) => (monInfo(i)?.rank ?? 0) >= 3;

  // ---------------------------------------------------------------- maplist
  const ML = parseTable(readKr('share/maplist.csv'));
  const maplist = new Map();
  for (const r of ML.rows) {
    const idx = numOrNull(r[0]); if (idx === null || idx === 65535) continue;
    const g = (n) => ML.get(r, n);
    maplist.set(idx, { r, g });
  }
  const mapName = (i) => {
    const m = maplist.get(i); if (!m) return null;
    const n = clean(m.g('Name'));
    if (!hasHangul(n)) return n;
    const rowNo = ML.rows.indexOf(m.r) + 1;
    return loc(`share#maplist.csv#1|${rowNo}`) && !hasHangul(loc(`share#maplist.csv#1|${rowNo}`)) ? loc(`share#maplist.csv#1|${rowNo}`) : n;
  };
  const mapFiles = (i) => {
    const m = maplist.get(i); if (!m) return null;
    const s = (n) => clean(m.g(n));
    const inDir = (dir, f) => { const k = pathKey(f); return k ? `${dir}/${k}` : ''; };
    const f = {
      map: inDir('map', s('MapFile')), mol: inDir('map', s('MapObject')), mel: inDir('map', s('MapEffect')),
      mac: inDir('share/mapredcell', s('MapAttribute')), mal: shareKey(s('MapPath')),
      monsters: csvKey(shareKey(s('MonsterLocatePath'))), npcs: csvKey(shareKey(s('NPCLocatePath'))),
      bricks: csvKey(shareKey(s('BrickLocatePath'))), triggers: csvKey(shareKey(s('TriggerLocatePath'))),
      calls: csvKey(shareKey(s('CallMonsterPath'))), levelCap: csvKey(shareKey(s('StrLevelCapPath'))),
    };
    if (f.calls === 'share/0.csv') f.calls = '';
    for (const k of ['mal', 'calls']) if (f[k]) f[k] = resolve(f[k]);
    return f;
  };

  // ---------------------------------------------------------------- string tables (DUNGEON category files + 2004)
  const listTxt = readKr('script/string/list.txt');
  const dungeonStringFiles = [];
  for (const line of listTxt.split(/\r?\n/)) {
    const m = /^\s*DUNGEON\s*,\s*(\S+)/i.exec(line);
    if (m) dungeonStringFiles.push(rootKey('script', m[1]));
  }
  const STR = new Map(); // cate -> {comment, codes, files:[]}
  let strCodes = 0;
  for (const f of dungeonStringFiles) {
    if (!has(f)) { hard(`list.txt DUNGEON file missing: ${f}`); continue; }
    for (const [cate, blk] of parseCateStringTable(readKr(f))) {
      if (cate < 0) { if (blk.codes.size) soft(`${f}: ${blk.codes.size} codes outside <cate>`); continue; }
      if (!STR.has(cate)) STR.set(cate, { comment: blk.comment, codes: new Map(), files: [] });
      const t = STR.get(cate);
      if (!t.files.includes(f)) t.files.push(f);
      if (!t.comment && blk.comment) t.comment = blk.comment;
      for (const [c, v] of blk.codes) { t.codes.set(c, v); strCodes++; }
    }
  }
  const SYS = parseCateStringTable(readKr('script/string/dungeon/stringtable_dungeon.txt')).get(2004)?.codes || new Map();
  log(`dungeon string tables: ${dungeonStringFiles.length} files, ${STR.size} categories, ${strCodes} codes; system (2004) ${SYS.size} codes`);

  // ---------------------------------------------------------------- message tables (share/dungeon)
  const FL = parseTable(readKr('share/dungeon/dungeonfilelist.csv'));
  const msgFileByIndex = new Map();
  const dungeonDirFiles = (BY_DIR.get('share/dungeon/') || []).filter((k) => k.endsWith('.csv') && !k.endsWith('dungeonfilelist.csv'));
  const listedFiles = new Set();
  for (const r of FL.rows) {
    const idx = numOrNull(r[0]); const k = `share/dungeon/${String(r[1]).trim().toLowerCase()}`;
    if (idx === null) continue;
    if (!has(k)) { hard(`dungeonfilelist: ${idx} -> ${k} missing`); continue; }
    msgFileByIndex.set(idx, k); listedFiles.add(k);
  }
  const unlistedMsgFiles = dungeonDirFiles.filter((k) => !listedFiles.has(k));
  const msgTables = new Map();
  let msgRows = 0, msgIndexMismatch = [];
  for (const [idx, k] of msgFileByIndex) {
    const t = parseDungeonMessageCsv(readKr(k));
    if (t.index !== idx) msgIndexMismatch.push(`${k}: header ${t.index} vs list ${idx}`);
    msgTables.set(idx, { file: k, ...t }); msgRows += t.messages.length;
  }
  // superseded / retired tables that dungeonfilelist does not bind: kept raw (rows = [MessageIndex, StringCode, ...menus])
  const unlistedMessageTables = {};
  for (const k of unlistedMsgFiles) {
    const t = parseDungeonMessageCsv(readKr(k));
    unlistedMessageTables[k] = { index: t.index, rows: t.messages.map((m) => [m.msg, m.str, ...m.menus]) };
  }
  log(`message tables: ${msgFileByIndex.size} listed (${msgRows} rows), ${unlistedMsgFiles.length} unlisted files in share/dungeon`);

  const messagesFor = (mapIdx, cateIdx = mapIdx) => {
    const cat = STR.get(cateIdx); const tbl = msgTables.get(mapIdx);
    if (!cat && !tbl) return null;
    const out = {};
    // key = MessageIndex (what the script sends and what menus point at); text = StringCode (differs in 14 rows,
    // e.g. Quun's Temple 12001/13001 -> string 11001: aliases that reuse another text) -> `s`
    const add = (code, sent, menus, strCode = code) => {
      const s = cat?.codes.get(strCode);
      const e = out[code] || {};
      if (s) { const p = parseMessageText(s.text); e.t = p.t; if (p.fx.length) e.fx = p.fx; if (s.comment) e.c = s.comment; }
      if (strCode !== code) e.s = strCode;
      if (sent) e.sent = 1;
      if (menus && menus.length) e.m = menus;
      out[code] = e;
    };
    if (cat) for (const code of cat.codes.keys()) add(code, false);
    let missing = 0;
    if (tbl) for (const m of tbl.messages) { add(m.msg, true, m.menus, m.str); if (!cat?.codes.has(m.str)) missing++; for (const mm of m.menus) if (!out[mm]) add(mm, false); }
    return { messages: out, stringCate: cat ? cateIdx : null, stringComment: cat?.comment || '', table: tbl?.file || null, missing, total: tbl ? tbl.messages.length : 0 };
  };
  // maps without their own string category borrow the one of a map with the same name (Nunvice 36/37 -> 35)
  const cateFallback = (mi) => {
    if (STR.has(mi)) return mi;
    const nm = clean(maplist.get(mi)?.g('Name')).toLowerCase();
    for (const [j, m] of maplist) if (j !== mi && STR.has(j) && clean(m.g('Name')).toLowerCase() === nm) return j;
    return mi;
  };
  const msgMissing = [];

  // ---------------------------------------------------------------- dungeonlist
  const DL = parseTable(readKr('share/dungeonlist.csv'));
  const dungeonRows = new Map(); const dupDungeon = [];
  DL.rows.forEach((r, i) => {
    const idx = numOrNull(DL.get(r, 'Dungeon_Index')); if (idx === null) return;
    if (dungeonRows.has(idx)) { dupDungeon.push(idx); return; }
    dungeonRows.set(idx, { r, rowNo: i + 1 });
  });

  // ---------------------------------------------------------------- NPC roles
  const DUNGEON_ENTRY_JOBS = { 19: 'DUNGEON', 45: 'TROOP_DUNGEON', 58: 'MINI_DUNGEON_SCRIPT', 34: 'RANDOM_DUNGEON' };
  const entryDefs = new Map(); // dungeonIndex -> [npc ids whose definition carries the entry job, placed or not]
  for (const [id, def] of Object.entries(NPC.npcs || {})) for (const [jt, ji] of def.jobs || []) if (DUNGEON_ENTRY_JOBS[jt]) { if (!entryDefs.has(ji)) entryDefs.set(ji, []); if (!entryDefs.get(ji).includes(+id)) entryDefs.get(ji).push(+id); }
  const entryNpcs = new Map(); // dungeonIndex -> [{npc, name, map, x, y, dir, warp, job}]
  const scriptNpcsByMap = new Map();
  for (const [mapKey, pl] of Object.entries(NPC.placements || {})) {
    const map = +mapKey;
    for (const row of pl.rows) {
      const [npc, x, y, dir, wx, wy] = row;
      const def = NPC.npcs[npc]; if (!def?.jobs) continue;
      for (const [jt, ji] of def.jobs) {
        if (DUNGEON_ENTRY_JOBS[jt]) {
          if (!entryNpcs.has(ji)) entryNpcs.set(ji, []);
          entryNpcs.get(ji).push({ npc, name: def.name, map, x: round(x), y: round(y), dir, warp: wx != null ? [round(wx), round(wy)] : null, job: jt });
        }
        if (jt === 31 || jt === 80) {
          if (!scriptNpcsByMap.has(map)) scriptNpcsByMap.set(map, []);
          scriptNpcsByMap.get(map).push({ npc, name: def.name, shape: def.shape, x: round(x), y: round(y), dir, warp: wx != null ? [round(wx), round(wy)] : null, job: [jt, ji] });
        }
      }
    }
  }

  // ---------------------------------------------------------------- locations & respawn tables
  const LOC = parseLocationCSV(readKr('share/arrange/location.csv'));
  const locName = (i) => { const l = LOC.get(i); if (!l) return null; return l.name; };
  const locByMap = new Map();
  for (const l of LOC.values()) { if (l.placeholder) continue; if (!locByMap.has(l.mapIndex)) locByMap.set(l.mapIndex, []); locByMap.get(l.mapIndex).push(l); }
  const DK = parseTable(readKr('share/dkmaplist.csv'));
  const dkmap = new Map();
  for (const r of DK.rows) {
    const idx = numOrNull(r[0]); if (idx === null) continue;
    const c = (n) => r[DK.col(n)];
    const pts = [];
    const cnt = num(c('RespawnPosCount'));
    // header: RespawnMap_00,RespawnPosX_00,RespawnPosX_00(=Y) ... (duplicate name -> the parser suffixes _2)
    for (let k = 0; k < 2; k++) {
      const kk = String(k).padStart(2, '0');
      const mi = DK.col(`RespawnMap_${kk}`), xi = DK.col(`RespawnPosX_${kk}`), yi = DK.col(`RespawnPosX_${kk}_2`);
      if (k < cnt && mi >= 0) pts.push({ map: num(r[mi]), x: num(r[xi]), y: num(r[yi]) });
    }
    const channels = [];
    for (let k = 0; k < 4; k++) {
      const kk = String(k).padStart(2, '0');
      const ch = num(c(`LocateDKChannel_${kk}`)); if (!ch) continue;
      channels.push({ channel: ch, script: c(`LocateDscript_${kk}`), dkIndex: num(c(`LocateDK_Index_${kk}`)) });
    }
    dkmap.set(idx, { respawnType: c('RespawnType') || 'NONE', points: pts, locate: [num(c('LocatePosX')), num(c('LocatePosY'))], channels,
      cost: [num(c('CostItem_Index_1')), num(c('CostItem_Index_2')), num(c('CashCostItem_Index_1')), num(c('CashCostItem_Index_2'))].filter(Boolean),
      cashLocate: [num(c('CashLocatePosX')), num(c('CashLocatePosY'))] });
  }
  const MR = parseTable(readKr('share/arrange/maprespawn.csv'));
  const mapRespawn = new Map();
  for (const r of MR.rows) {
    const map = num(MR.get(r, 'MapIndex'), null); if (map === null) continue;
    const stages = [];
    for (let k = 1; k <= 10; k++) {
      const si = numOrNull(MR.get(r, `StageIndex_${k}`)); if (si === null) continue;
      stages.push({ stage: si, x: num(MR.get(r, `LocationX_${k}`)), y: num(MR.get(r, `LocationY_${k}`)) });
    }
    mapRespawn.set(map, { id: num(r[0]), respawnMap: num(MR.get(r, 'RespawnMap')), stageCount: num(MR.get(r, 'StageCount')), stages });
  }

  // ---------------------------------------------------------------- brick + trigger definitions
  const brickDefs = buildBrickDefs();
  const triggerDefs = buildTriggerDefs();

  function resolveShape(csvRel) {
    const t = parseTable(readKr(csvRel));
    const m = new Map();
    for (const r of t.rows) {
      const name = String(t.get(r, 'name')).trim(); if (!name) continue;
      const mesh = rootKey('mesh', t.get(r, 'mesh')), tpack = rootKey('texturepack', t.get(r, 'tpack'));
      m.set(name.toLowerCase(), { name, mesh: exists(mesh), tpack: exists(tpack), meshWanted: mesh, tpackWanted: tpack,
        effect: num(t.get(r, 'effect')), effectId: num(t.get(r, 'EffectID')), glow: /true/i.test(t.get(r, 'GlowEffect')) ? 1 : 0 });
    }
    return m;
  }
  function actTables(kind) {
    // compiled tables first (header index), csv sources as fallback
    const out = new Map();
    const stats = { dat: 0, csv: 0, bad: [] };
    for (const k of (BY_DIR.get(`share/action/action/${kind}/`) || [])) {
      try { const a = parseActDat(readRel(k)); if (a.trailingBytes) stats.bad.push(`${k}: ${a.trailingBytes} trailing`); if (!out.has(a.index)) out.set(a.index, { src: k, ...a }); stats.dat++; } catch (e) { stats.bad.push(`${k}: ${e.message}`); }
    }
    for (const k of (BY_DIR.get(`share/action/${kind}/`) || [])) {
      if (!k.endsWith('.csv')) continue;
      try { const a = parseActCsv(readKr(k)); stats.csv++; if (a.index !== null && !out.has(a.index)) out.set(a.index, { src: k, ...a }); } catch (e) { stats.bad.push(`${k}: ${e.message}`); }
    }
    return { tables: out, stats };
  }
  function actionSet(tbl, missing) {
    if (!tbl) return null;
    const skel = resolve(rootKey('skel', tbl.skeleton));
    const out = { src: tbl.src, skel: exists(skel) };
    if (skel && !has(skel)) missing.push(skel);
    const clips = {};
    for (const rec of tbl.records) {
      if (!rec.anim) continue;
      const a = resolve(rootKey('anim', rec.anim));
      if (!has(a)) { missing.push(a); continue; }
      const key = rec.index ? `${rec.name}_${rec.index}` : rec.name;
      if (!clips[key]) clips[key] = { anim: a, len: round(rec.timeLength, 3), effect: rec.effect || undefined };
    }
    out.clips = clips;
    return out;
  }

  function buildBrickDefs() {
    const rows = parseCSV(readKr('share/creature/brick.csv')).map((r) => (r || []).map((c) => String(c ?? '').trim()));
    const byLabel = new Map(); rows.slice(1).forEach((r) => { if (r[0]) byLabel.set(r[0].trim(), r); });
    const shapes = resolveShape('script/shape/brick_shape.csv');
    const { tables: acts, stats } = actTables('brick');
    const missingAssets = [];
    const out = {};
    const idRow = rows[0];
    for (let c = 1; c < idRow.length; c++) {
      const id = numOrNull(idRow[c]); if (id === null) continue;
      const g = (lab) => (byLabel.get(lab)?.[c] ?? '');
      const gn = (lab) => num(g(lab));
      const nameCsv = g('Name');
      const nameEn = loc(`creature#brick.csv#${c}|1`);
      const shapeName = g('ShapeInfo');
      const sh = shapes.get(shapeName.toLowerCase());
      if (!sh) missingAssets.push(`brick ${id}: shape '${shapeName}' not in brick_shape.csv`);
      else { if (!sh.mesh && sh.meshWanted) missingAssets.push(sh.meshWanted); if (!sh.tpack && sh.tpackWanted) missingAssets.push(sh.tpackWanted); }
      const drops = [];
      for (let k = 1; k <= 15; k++) { const s = gn(`ItemSetIndex_${k}`), rt = gn(`ItemSetDropRatio_${k}`); if (s) drops.push([s, rt]); }
      const name = (nameEn && !hasHangul(nameEn) ? nameEn : nameCsv) || shapeName;
      const invisible = /hidden/i.test(shapeName) || /hidden_brick\.mesh$/.test(sh?.mesh || '') || (sh && !sh.mesh) ? 1 : 0;
      const attackable = gn('IsAttackable'), targeting = gn('Targeting');
      // breakable = the player can destroy it (targetable, not immune); gate = scripted (immune: 100 % resist or not
      // targetable, typically 10,000,000 HP) and opened/removed by the map script; wall = invisible scripted blocker
      const immune = Math.min(gn('MeleeDamageResist'), gn('RangeDamageResist')) >= 100;
      const role = attackable && targeting && !immune ? 'breakable' : invisible ? 'wall' : 'gate';
      const act = actionSet(acts.get(id), missingAssets);
      const e = {
        name, role, property: gn('Property'), rank: gn('Rank'), level: gn('Level'), hp: gn('MaxHP'), hp0: gn('DefaultHP'), regen: gn('HPRecovery'),
        actionType: gn('ActionType'), disappear: gn('Disappear'), size: [gn('WidthSize'), gn('HeightSize')],
        def: [gn('Defence_Min'), gn('Defence_Max')], resist: { melee: gn('MeleeDamageResist'), range: gn('RangeDamageResist'), physical: gn('PhysicalResist'), magic: gn('MagicResist') },
        exp: gn('Exp'), money: [gn('Money_Min'), gn('Money_Max'), gn('Money_Rate')], drops,
        statusIndex: gn('StatusIndex'), lifeTime: gn('LifeTime'), showName: gn('ShowName'), ally: gn('Ally'), targeting, attackable,
        shape: shapeName, mesh: sh?.mesh || null, tpack: sh?.tpack || null, invisible,
      };
      if (sh?.effectId) e.effectId = sh.effectId;
      if (nameCsv && nameCsv !== name) e.nameKr = nameCsv;
      const desc = g('DescriptionInfo'); if (desc && !/작성중|Under Construction|In progress|Processing/.test(desc)) e.desc = locCI(`creature#brick.csv#${c}|35`) || desc;
      if (act) e.act = act;
      const raw = {}; for (const [lab, r] of byLabel) if (!BRICK_KNOWN.has(lab)) raw[lab] = r[c] ?? '';
      if (Object.keys(raw).length) e.raw = raw;
      out[id] = e;
    }
    return { defs: out, missingAssets, actStats: stats, actCount: acts.size, labels: [...byLabel.keys()] };
  }

  function buildTriggerDefs() {
    const t = parseTable(readKr('share/creature/trigger.csv'));
    const shapes = resolveShape('script/shape/trigger_shape.csv');
    const { tables: acts, stats } = actTables('trigger');
    const missingAssets = [];
    const out = {};
    t.rows.forEach((r, i) => {
      const id = numOrNull(r[0]); if (id === null) return;
      const rowNo = i + 1;
      const g = (n) => t.get(r, n);
      const nameCsv = g('Name'); const nameEn = loc(`creature#Trigger.csv#1|${rowNo}`) || locCI(`creature#trigger.csv#1|${rowNo}`);
      const sh = shapes.get(g('Shape').toLowerCase());
      if (!sh) missingAssets.push(`trigger ${id}: shape '${g('Shape')}' not in trigger_shape.csv`);
      else { if (!sh.mesh) missingAssets.push(sh.meshWanted); if (!sh.tpack && sh.tpackWanted) missingAssets.push(sh.tpackWanted); }
      const states = [];
      const cnt = num(g('StateCount'));
      for (let k = 1; k <= 20; k++) {
        const type = num(g(`StateType_${k}`)), sidx = num(g(`StateIndex_${k}`)), chg = num(g(`StateChangeNum_${k}`));
        const str = g(`StateString_${k}`), ms = num(g(`StateChangeTime_${k}`)), vis = num(g(`StateVisible_${k}`)), clk = num(g(`StateClickAble_${k}`));
        if (k > cnt && !type && !sidx && !chg && (!str || str === '0')) continue;
        const colStr = t.col(`StateString_${k}`);
        const strEn = colStr >= 0 ? (locCI(`creature#Trigger.csv#${colStr}|${rowNo}`)) : null;
        const txt = strEn && !hasHangul(strEn) ? strEn : str;
        states.push({ type, index: sidx, next: chg, text: txt === '0' ? '' : txt, ms, visible: vis, clickable: clk });
      }
      const e = {
        name: (nameEn && !hasHangul(nameEn) ? nameEn : nameCsv), desc: num(g('Desc')), mapVisible: num(g('MapVisible')), nameVisible: num(g('NameVisible')),
        minimapColor: num(g('Minimapcolor')), stateCount: cnt, states, shape: g('Shape'), mesh: sh?.mesh || null, tpack: sh?.tpack || null,
      };
      if (nameCsv && e.name !== nameCsv) e.nameKr = nameCsv;
      const act = actionSet(acts.get(id), missingAssets);
      if (act) e.act = act;
      out[id] = e;
    });
    // interactive actions (emote-like animations the player plays at a trigger)
    const ia = parseTable(readKr('script/interactiveaction/triggerinteractiveaction.csv'));
    for (const r of ia.rows) {
      const id = numOrNull(r[0]); if (id === null || !out[id]) continue;
      out[id].interactive = { actions: [1, 2, 3, 4, 5].map((k) => num(ia.get(r, `ActionIndex_${k}`))).filter(Boolean), interaction: num(ia.get(r, 'InteractionIndex')), dir: num(ia.get(r, 'Direction')) };
    }
    return { defs: out, missingAssets, actStats: stats, actCount: acts.size };
  }

  // ---------------------------------------------------------------- drops / rewards tables
  const TD = parseTable(readKr('share/item/triggerdropitem.csv'));
  const triggerDrops = {};
  const usedItems = new Set(), usedSets = new Set(), usedSetsEx = new Set();
  for (const r of TD.rows) {
    const map = numOrNull(TD.get(r, 'MapIndex')), trig = numOrNull(TD.get(r, 'TriggerIndex')); if (map === null || trig === null) continue;
    const g = (n) => num(TD.get(r, n));
    const money = [];
    for (let k = 1; k <= 10; k++) { const rate = g(`Money_Rate_${k}`); if (rate) money.push([g(`MoneyCount_Min_${k}`), g(`MoneyCount_Max_${k}`), g(`Money_Min_${k}`), g(`Money_Max_${k}`), rate]); }
    const sets = [];
    for (let k = 1; k <= 15; k++) { const s = g(`ItemSetIndex_${k}`); if (s) { sets.push([s, g(`ItemSetDropRatio_${k}`), g(`ItemSetSocket_${k}`)]); usedSets.add(s); } }
    const fixed = [];
    for (let k = 1; k <= 10; k++) { const it = g(`Fix_ItemIndex_${k}`); if (it) { fixed.push([it, g(`Fix_ItemStack_${k}`), g(`Fix_ItemCountMin_${k}`), g(`Fix_ItemCountMax_${k}`)]); usedItems.add(it); } }
    const fixedSets = [];
    for (let k = 1; k <= 10; k++) { const s = g(`Fix_ItemSet_${k}`); if (s) { fixedSets.push([s, g(`Fix_ItemSetCountMin_${k}`), g(`Fix_ItemSetCountMax_${k}`), g(`Fix_ItemSetSocket_${k}`), g(`FixItemSetRatio_${k}`)]); usedSets.add(s); } }
    const setsEx = [];
    for (let k = 1; k <= 15; k++) { const s = g(`ItemSetExIndex_${k}`); if (s) { setsEx.push([s, g(`ItemSetExDropRatio_${k}`), g(`ItemSetExSocket_${k}`)]); usedSetsEx.add(s); } }
    const fixedSetsEx = [];
    for (let k = 1; k <= 10; k++) { const s = g(`Fix_ItemSetEx_${k}`); if (s) { fixedSetsEx.push([s, g(`Fix_ItemSetExCountMin_${k}`), g(`Fix_ItemSetExCountMax_${k}`), g(`Fix_ItemSetExSocket_${k}`), g(`FixItemSetExRatio_${k}`)]); usedSetsEx.add(s); } }
    const e = { map, trigger: trig, name: TD.get(r, 'Name'), cond: TD.get(r, 'CondName'), maxItemSet: g('MaxItemSet') };
    if (money.length) e.money = money; if (sets.length) e.sets = sets; if (fixed.length) e.fixed = fixed; if (fixedSets.length) e.fixedSets = fixedSets;
    if (setsEx.length) e.setsEx = setsEx; if (fixedSetsEx.length) e.fixedSetsEx = fixedSetsEx;
    e.gainLimitTime = g('GainLimitTime'); e.dropRange = g('DropRange'); e.petPick = g('PetPick');
    e.funcs = ['DropItemSetFunc', 'DropFixItemFunc', 'DropFixItemSetFunc', 'DropItemSetExFunc', 'DropFixItemSetExFunc'].map((h) => TD.get(r, h));
    e.maxItemSetEx = g('MaxItemSetEx');
    triggerDrops[`${map}:${trig}`] = e;
  }
  const MD = parseTable(readKr('share/item/monsterdropitem_map.csv'));
  const mapDrops = {};
  for (const r of MD.rows) {
    const idx = numOrNull(r[0]); if (idx === null) continue;
    const g = (n) => num(MD.get(r, n));
    const sets = []; for (let k = 1; k <= 15; k++) { const s = g(`ItemSetIndex_${k}`); if (s) { sets.push([s, g(`ItemSetDropRatio_${k}`)]); usedSets.add(s); } }
    const raw = {};
    MD.headers.forEach((h, i) => { if (i > 1 && !/^ItemSetIndex_|^ItemSetDropRatio_/.test(h) && r[i] && r[i] !== '0') raw[h] = r[i]; });
    mapDrops[idx] = { classCheck: g('Class_Check'), excludeMonster: g('Exclude_Monster'), money: [g('MoneyCount_Min'), g('MoneyCount_Max'), g('Money_Min'), g('Money_Max'), g('Money_Rate')], maxItemSet: g('MaxItemSet'), sets, raw };
    for (const [h, v] of Object.entries(raw)) if (/ItemIndex/i.test(h) && num(v) > 100) usedItems.add(num(v));
  }
  // forbidden shackles (map 260), forgotten shipwreck (234/235/250/251/263/264), field bosses, boss memento
  const FS = parseTable(readKr('share/forbiddenshackles/forbiddenshacklesdata.csv'));
  const forbiddenShackles = FS.rows.map((r) => ({ floor: num(r[0]), resetCost: num(r[1]), clearExp: num(r[2]) }));
  const RS = parseTable(readKr('share/forgottenshipwreck/rewardslot.csv'));
  const shipwreckRewards = {};
  for (const r of RS.rows) {
    const team = RS.get(r, 'team'); if (!team) continue;
    const items = [];
    for (let k = 1; k <= num(RS.get(r, 'count')); k++) { const it = num(RS.get(r, `index${k}`)); if (!it) continue; items.push([it, num(RS.get(r, `vlaue${k}`)), num(RS.get(r, `rate${k}`))]); usedItems.add(it); }
    shipwreckRewards[team] = items;
  }
  const SC = parseTable(readKr('share/forgottenshipwreck/startcondition.csv'));
  const shipwreckSchedule = SC.rows.map((r) => ({ day: num(r[0]), startPc: num(r[1]), maxPc: num(r[2]), startHour: num(r[3]), finishHour: num(r[4]) }));
  const FB = parseTable(readKr('share/fieldboss/config.csv'));
  const fieldBosses = FB.rows.map((r) => {
    const g = (n) => num(FB.get(r, n));
    return { world: g('WorldIndex'), dkServer: g('DKServerIndex'), channel: g('ChannelIndex'), day: g('Day'), start: [g('StartHour'), g('StartMin')], end: [g('EndHour'), g('EndMin')],
      notices: [1, 2, 3, 4, 5].map((k) => g(`Noty_${k}`)), map: g('MapIndex'), x: g('Start_X'), y: g('Start_Y'), dir: g('Direction'), monster: g('MonsterIndex'),
      slaves: [1, 2, 3, 4, 5].map((k) => g(`Slave_${k}`)).filter(Boolean) };
  });
  const FBS = parseTable(readKr('share/fieldboss/summonsmonster.csv'));
  const fieldBossSummons = FBS.rows.map((r) => { const g = (n) => num(FBS.get(r, n)); return { group: g('Index'), no: g('No'), monster: g('MonsterIndex'), tickMs: g('dwTick'), range: [g('dwMinRange'), g('dwMaxRange')], maxLimit: g('dwMaxLimit'), callMax: g('CallMax'), count: [g('dwMin'), g('dwMax')] }; });
  const BM = parseTable(readKr('share/creature/bossmemento.csv'));
  const bossMemento = {}; for (const r of BM.rows) bossMemento[num(r[0])] = { hpBar: num(r[1]), maxStepHp: num(r[2]), bgm: num(r[3]), bgmIndex: num(r[4]) };

  // ---------------------------------------------------------------- level caps (exp by level difference)
  const levelCaps = {};
  const levelCapOf = (key) => {
    if (!key || !has(key)) return null;
    if (!levelCaps[key]) {
      const t = parseTable(readKr(key));
      levelCaps[key] = t.rows.map((r) => [num(r[1]), num(r[2]), num(r[3]), num(r[4]), num(r[5]), num(r[6]), [num(r[7]), num(r[8]), num(r[9])]]);
    }
    return key;
  };

  // ---------------------------------------------------------------- script monster lists (share/map/*/scriptmonster_<map>.csv)
  const scriptMonsterFiles = new Map();
  for (const k of FILES) {
    const m = /^share\/map\/[^/]+\/scriptmonster_(\d+)\.csv$/.exec(k);
    if (m) { const mi = +m[1]; if (!scriptMonsterFiles.has(mi)) scriptMonsterFiles.set(mi, k); }
  }
  const scriptMonstersOf = (mi) => {
    const k = scriptMonsterFiles.get(mi); if (!k) return null;
    const ids = parseCSV(readKr(k)).map((r) => numOrNull(r?.[0])).filter((v) => v !== null);
    return { file: k, ids };
  };

  // ---------------------------------------------------------------- per-map classification
  const dungeonOfMap = new Map(); // map -> {dungeon, floor}
  for (const [idx, { r }] of dungeonRows) {
    const cnt = num(DL.get(r, 'MapCount'));
    for (let k = 0; k < Math.max(cnt, 1); k++) {
      const mi = numOrNull(DL.get(r, `MapIndex_${k}`)); if (mi === null || (k > 0 && mi === 0)) continue;
      if (!dungeonOfMap.has(mi)) dungeonOfMap.set(mi, { dungeon: idx, floor: k });
    }
  }
  const MACS = new Map();
  const macOf = (mi) => {
    if (NO_MAC) return null;
    if (MACS.has(mi)) return MACS.get(mi);
    const f = mapFiles(mi); let g = null;
    if (f?.mac && has(f.mac)) { try { g = parseMac(readRel(f.mac)); } catch (e) { soft(`mac ${f.mac}: ${e.message}`); } }
    MACS.set(mi, g); return g;
  };

  const V = { walk: { bricks: [0, 0], calls: [0, 0], statics: [0, 0], triggers: [0, 0], spawns: [0, 0], scriptNpcs: [0, 0], locations: [0, 0] }, monstersMissing: new Set(), monstersNotInJson: new Set() };
  const walkCheck = (grid, bucket, x, y, radius = 3) => {
    if (!grid) return null;
    V.walk[bucket][1]++;
    const w = nearestWalkable(grid, x, y, radius);
    if (w) V.walk[bucket][0]++;
    return w ? w.distance : -1;
  };
  const checkMonster = (i) => { if (!monsterCsvIdx.has(i) && !MON.monsters[i]) V.monstersMissing.add(i); else if (!MON.monsters[i]) V.monstersNotInJson.add(i); };

  const kindOf = (mi) => {
    const m = maplist.get(mi); if (!m) return 'unknown';
    const dyn = num(m.g('DynamicType'));
    if (/selection map|^login$|^new_server$|map tool/i.test(clean(m.g('Name')))) return 'system';
    if (dungeonOfMap.has(mi) || dyn === 1) return 'instance';
    if (dyn === 2) return 'colosseum';
    const nm = (mapName(mi) || '').toLowerCase();
    if (/dead front|ice castle/.test(nm)) return 'event';
    if (num(m.g('IsSiege'))) return 'siege';
    if (num(m.g('DungeonIndex'))) return 'event';
    if (/selection map|^login|new_server/.test(nm)) return 'system';
    return 'field';
  };

  const maps = {};
  const allMapIdx = [...maplist.keys()].sort((a, b) => a - b);
  for (const mi of allMapIdx) {
    const m = maplist.get(mi); const g = (n) => clean(m.g(n));
    const f = mapFiles(mi);
    const files = {};
    for (const [k, v] of Object.entries(f)) { if (!v) continue; if (has(v)) files[k] = v; else { files[`${k}Missing`] = v; } }
    const e = {
      name: mapName(mi), kind: kindOf(mi), mapType: num(g('Map_Type')), dynamicType: num(g('DynamicType')), dungeonIndex: num(g('DungeonIndex')), troopLobby: num(g('TROOP_LOBBY')),
      script: g('ScriptName') || undefined, levels: [num(g('LimitMinLevel')), num(g('LimitMaxLevel'))],
      flags: { portal: num(g('IsPortal')), pvp: num(g('IsPvP')), siege: num(g('IsSiege')), returnScroll: num(g('IsReturnScroll')), isReturn: num(g('IsReturn')),
        noChaoGain: num(g('IsNotIncreaseChao')), vehicle: num(g('IsVehicle')), pet: num(g('IsPet')), peace: num(g('PeaceZone')), pvpPeace: num(g('PVP_PeaceZone')), revivalCheck: num(g('PCRevivalChack')) },
      monsterLimit: num(g('MonsterLimit')), respawnFactor: num(g('MonsterRespawnFactor')), files,
    };
    // remaining gameplay columns of maplist.csv, raw (camera / culling / mip-map columns belong to the world renderer)
    const raw = {};
    for (const h of MAPLIST_RAW) { const v = g(h); if (v !== '' && v !== '0') raw[h] = v; }
    if (Object.keys(raw).length) e.raw = raw;
    if (hasHangul(m.g('Name')) && e.name !== clean(m.g('Name'))) e.nameKr = clean(m.g('Name'));
    const d = dungeonOfMap.get(mi); if (d) { e.dungeon = d.dungeon; e.floor = d.floor; }
    else if (e.dungeonIndex && dungeonRows.has(e.dungeonIndex)) e.dungeon = e.dungeonIndex;
    if (f.levelCap) e.levelCap = levelCapOf(f.levelCap) || undefined;
    for (const k of ['StrGradeCapPath', 'StrAbilityCapPath']) { const v = g(k); if (v && v !== '0') e[k === 'StrGradeCapPath' ? 'gradeCap' : 'abilityCap'] = exists(csvKey(shareKey(v))) || exists(csvKey(shareKey(`pc/${v}`))) || `unresolved:${v}`; }
    const dk = dkmap.get(mi); if (dk) e.dk = dk;
    const mr = mapRespawn.get(mi); if (mr) e.stageRespawn = mr;
    const lvlLocs = (locByMap.get(mi) || []).map((l) => l.index); if (lvlLocs.length) e.locations = lvlLocs;

    const detail = e.kind !== 'field' && e.kind !== 'system' || msgTables.has(mi) || STR.has(mi) || f.calls || f.bricks || f.triggers || scriptMonsterFiles.has(mi);
    if (detail) fillScript(mi, e, f);
    maps[mi] = e;
  }
  // message tables / string categories / share/map folders of map indices that share/maplist.csv does not define
  // (server-side copies such as Dravice Field I-IV 202-205 and Mitera I-IV 536-539, retired maps 1/2/8/27/28/120):
  // the client cannot load them; kept so nothing is lost.
  const orphanIdx = [...new Set([...msgTables.keys(), ...STR.keys()])].filter((i) => !maplist.has(i) && i >= 0).sort((a, b) => a - b);
  for (const i of orphanIdx) {
    const msg = messagesFor(i);
    const dir = [...BY_DIR.keys()].find((d) => new RegExp(`^share/map/0*${i}_[^/]+/$`).test(d));
    const e = { name: STR.get(i)?.codes.get(1)?.text || STR.get(i)?.comment || (msg?.table || '').replace(/^.*dungeon_\d+_|\.csv$/g, ''), kind: 'orphan',
      note: 'map index not defined by share/maplist.csv: not loadable by this client (server-side copy or retired map)' };
    if (msg) { e.messages = msg.messages; if (msg.table) e.messageTable = msg.table; if (msg.stringCate !== null) e.stringCate = msg.stringCate; if (msg.stringComment) e.stringComment = msg.stringComment; }
    if (dir) e.files = { folder: (BY_DIR.get(dir) || []).filter((k) => k.endsWith('.csv') || k.endsWith('.mal')) };
    // Lane 52: an orphan floor's own Global brick_/npc_ CSVs (map 120 Karon's Fragments [Hard]: brick_120_under_crespo_indun.csv,
    // npc_120_under_crespo_indun.csv) are parsed the same way as a maplist floor's, so the runtime gets the floor's real bricks
    // and DUNGEON_SCRIPT NPCs. Only that folder's own files are read (never a sibling's). No .mac grid: no walk check.
    if (dir) {
      const keys = BY_DIR.get(dir) || [];
      const brickKey = keys.find((k) => /\/brick_[^/]*\.csv$/.test(k));
      const npcKey = keys.find((k) => /\/npc_[^/]*\.csv$/.test(k));
      if (brickKey) {
        const ob = parseBrickCSV(readKr(brickKey)).map((b) => {
          if (!brickDefs.defs[b.brickIndex]) hard(`map ${i}: brick index ${b.brickIndex} not in brick.csv`);
          return { uid: b.uid, brick: b.brickIndex, x: round(b.x), y: round(b.y), dir: b.direction ?? 0, create: b.isCreate ?? 1, revival: b.revival ?? 0, regen: b.regenCycle ?? 0 };
        });
        if (ob.length) e.bricks = ob;
        e.bricksFile = brickKey;
      }
      if (npcKey) {
        const sn = [];
        for (const q of parseNpcCSV(readKr(npcKey)).npcs) {
          if (q.id === null || q.x === null) continue;
          const def = NPC.npcs[q.id];
          for (const [jt, ji] of def?.jobs || []) if (jt === 31 || jt === 80) sn.push({ npc: q.id, name: def.name, shape: def.shape, x: round(q.x), y: round(q.y), dir: q.direction ?? 0, warp: q.warpX != null ? [round(q.warpX), round(q.warpY)] : null, job: [jt, ji] });
        }
        if (sn.length) {
          const list = sn.map((n) => { const o = { npc: n.npc, name: n.name, x: n.x, y: n.y, dir: n.dir, job: n.job }; if (n.warp) o.warp = n.warp; return o; });
          assignDialogs(list, sn, e.messages, e.missions);
          for (const o of list) o.role = npcRole(o, o.dialog != null ? e.messages?.[o.dialog] : null);
          e.scriptNpcs = list;
        }
        e.npcsFile = npcKey;
      }
    }
    const ls = (locByMap.get(i) || []).map((l) => l.index); if (ls.length) e.locations = ls;
    maps[i] = e;
  }

  function fillScript(mi, e, f) {
    const grid = (e.kind === 'field' || e.kind === 'system') && !dungeonOfMap.has(mi) ? macOf(mi) : macOf(mi);
    // messages / dialogs
    const cate = cateFallback(mi);
    const msg = messagesFor(mi, cate);
    if (msg) {
      e.messages = msg.messages; if (msg.table) e.messageTable = msg.table;
      if (msg.stringCate !== null) e.stringCate = msg.stringCate; if (msg.stringComment) e.stringComment = msg.stringComment;
      if (cate !== mi) e.stringCateBorrowed = 1;
      if (msg.missing) msgMissing.push(`${mi}:${msg.missing}/${msg.total}`);
      const T = msg.messages;
      const std = T[1] && T[2] && (T[3] || T[30]);
      if (std) {
        e.title = T[1]?.t; e.mission = T[2]?.t;
        if (T[3]?.t) e.timeLimit = { text: T[3].t, sec: parseDuration(T[3].t) };
        const missions = Object.keys(T).map(Number).filter((c) => c >= 10 && c < 30 && T[c].t).map((c) => ({ code: c, text: T[c].t, note: T[c].c || undefined }));
        if (missions.length) e.missions = missions;
      }
    }
    // static spawns
    if (f.monsters && has(f.monsters)) {
      const s = parseSpawnCSV(readKr(f.monsters));
      if (s.spawns.length) {
        e.static = { file: f.monsters, rows: s.spawns.map((p) => [p.monsterIndex, p.respawnSec, p.x, p.y]) };
        for (const p of s.spawns) { checkMonster(p.monsterIndex); walkCheck(grid, 'statics', p.x, p.y, 0); }
      }
    }
    // scripted call waves
    const callFile = f.calls && has(f.calls) ? f.calls : null;
    if (callFile) {
      const c = parseCallMonsterCSV(readKr(callFile));
      const groups = new Map();
      for (const r of c.calls) {
        if (!r.monsterIndex) continue;
        checkMonster(r.monsterIndex); walkCheck(grid, 'calls', r.x, r.y, 1);
        if (!groups.has(r.callIndex)) groups.set(r.callIndex, []);
        groups.get(r.callIndex).push([r.monsterIndex, r.x, r.y, r.radius ?? 0, r.count ?? 1]);
      }
      if (groups.size) {
        e.waves = [...groups.entries()].sort((a, b) => a[0] - b[0]).map(([call, rows]) => {
          let n = 0, sx = 0, sy = 0; const mons = new Map();
          for (const [mo, x, y, , cnt] of rows) { n += cnt; sx += x * cnt; sy += y * cnt; mons.set(mo, (mons.get(mo) || 0) + cnt); }
          const cx = sx / n, cy = sy / n;
          let rad = 0; for (const [, x, y] of rows) rad = Math.max(rad, Math.hypot(x - cx, y - cy));
          const bosses = [...mons.keys()].filter(isBossMon);
          const w = { call, count: n, center: [round(cx, 1), round(cy, 1)], radius: round(rad, 1), monsters: [...mons.entries()], rows };
          if (bosses.length) w.bosses = bosses;
          return w;
        });
        e.callFile = callFile;
      }
      if (c.randomCalls.length) e.randomWaves = { calls: c.randomCalls.map((r) => [r.randCallIndex, r.monsterIndex, r.count, r.posIndex]), positions: c.randomPositions.map((p) => [p.randPosIndex, p.x, p.y, p.radius]) };
      for (const r of c.randomCalls) checkMonster(r.monsterIndex);
      if (c.mapIndex !== null && c.mapIndex !== mi) e.callFileMapIndex = c.mapIndex;
    }
    // script-watched monsters
    const sm = scriptMonstersOf(mi);
    if (sm) { e.scriptMonsters = sm.ids; e.scriptMonsterFile = sm.file; for (const i of sm.ids) checkMonster(i); }
    // bricks
    if (f.bricks && has(f.bricks)) {
      const bs = parseBrickCSV(readKr(f.bricks));
      e.bricks = bs.map((b) => {
        const def = brickDefs.defs[b.brickIndex];
        if (!def) hard(`map ${mi}: brick index ${b.brickIndex} not in brick.csv`);
        const o = { uid: b.uid, brick: b.brickIndex, x: round(b.x), y: round(b.y), dir: b.direction ?? 0, create: b.isCreate ?? 1, revival: b.revival ?? 0, regen: b.regenCycle ?? 0 };
        const wd = walkCheck(grid, 'bricks', b.x, b.y, 3); if (wd !== null) o.walk = wd;
        return o;
      });
    }
    // triggers
    if (f.triggers && has(f.triggers)) {
      const ts = parseNpcCSV(readKr(f.triggers));
      e.triggers = ts.npcs.filter((t) => t.x !== null).map((t) => {
        if (!triggerDefs.defs[t.id]) hard(`map ${mi}: trigger index ${t.id} not in trigger.csv`);
        walkCheck(grid, 'triggers', t.x, t.y, 3);
        const o = { trigger: t.id, x: round(t.x), y: round(t.y), dir: t.direction ?? 0 };
        if (t.description) o.desc = t.description;
        if (triggerDrops[`${mi}:${t.id}`]) o.drop = `${mi}:${t.id}`;
        return o;
      });
    }
    // DUNGEON_SCRIPT NPCs (levers, doors, stairs, exit NPCs)
    const sn = scriptNpcsByMap.get(mi);
    if (sn) {
      const list = sn.map((n) => {
        const o = { npc: n.npc, name: n.name, x: n.x, y: n.y, dir: n.dir, job: n.job };
        if (n.warp) o.warp = n.warp;
        walkCheck(grid, 'scriptNpcs', n.warp ? n.warp[0] : n.x, n.warp ? n.warp[1] : n.y, 3);
        return o;
      });
      assignDialogs(list, sn, e.messages, e.missions);
      for (const o of list) o.role = npcRole(o, o.dialog != null ? e.messages?.[o.dialog] : null);
      e.scriptNpcs = list;
    }
    // bosses
    const bossSet = new Map();
    const addBoss = (id, where, pos) => { if (!isBossMon(id) && !(e.scriptMonsters || []).includes(id)) return; if (!bossSet.has(id)) bossSet.set(id, { monster: id, where: [], pos: [] }); const b = bossSet.get(id); if (!b.where.includes(where)) b.where.push(where); if (pos && b.pos.length < 4) b.pos.push(pos); };
    for (const r of e.static?.rows || []) if (isBossMon(r[0])) addBoss(r[0], 'static', [r[2], r[3]]);
    for (const w of e.waves || []) for (const [mo, x, y] of w.rows) if (isBossMon(mo) || (e.scriptMonsters || []).includes(mo)) addBoss(mo, `wave ${w.call}`, [x, y]);
    const present = new Set([...(e.static?.rows || []).map((r) => r[0]), ...(e.waves || []).flatMap((w) => w.monsters.map((m) => m[0]))]);
    for (const id of e.scriptMonsters || []) if (!present.has(id) && isBossMon(id)) addBoss(id, 'script', null);
    for (const b of bossSet.values()) {
      const mi2 = monInfo(b.monster);
      b.name = mi2?.name || null; b.rank = mi2?.rank ?? null; b.level = mi2?.level ?? null; b.hp = mi2?.hp ?? null;
      if (!isBossMon(b.monster)) b.scriptOnly = 1;
      if (e.messages && b.name) {
        const alerts = Object.entries(e.messages).filter(([c, v]) => +c >= 300 && +c < 400 && v.t && v.t.toLowerCase().includes(b.name.toLowerCase())).map(([c]) => +c);
        if (alerts.length) b.alert = alerts;
      }
      if (bossMemento[b.monster]) b.memento = bossMemento[b.monster];
    }
    if (bossSet.size) e.bosses = [...bossSet.values()];
    // entry point candidates
    const cands = [];
    for (const l of (locByMap.get(mi) || [])) cands.push({ src: `location ${l.index}`, x: l.x, y: l.y, dir: round(l.directionDeg, 1) });
    if (e.dk?.points?.length) for (const p of e.dk.points) if (p.map === mi && (p.x || p.y)) cands.push({ src: 'dkmaplist respawn', x: p.x, y: p.y });
    if (e.stageRespawn && e.stageRespawn.respawnMap === mi) for (const s of e.stageRespawn.stages) cands.push({ src: `maprespawn stage ${s.stage}`, x: s.x, y: s.y });
    const okWarp = (w) => w && w[0] > 1 && w[1] > 1;   // a few NPC rows carry (x, 0) / (0, 0) warp junk
    const exitNpc = (e.scriptNpcs || []).find((n) => n.role === 'exit' && (n.x > 1 || n.y > 1));
    if (exitNpc) cands.push({ src: `exit npc ${exitNpc.npc}`, x: okWarp(exitNpc.warp) ? exitNpc.warp[0] : exitNpc.x, y: okWarp(exitNpc.warp) ? exitNpc.warp[1] : exitNpc.y });
    if (!cands.length) {
      // no table point: stand next to a placed NPC of this map (instances put their guide/exit NPC at the start)
      const pl = NPC.placements?.[mi]?.rows?.find((r) => r[1] > 1 && r[2] > 1);
      if (pl) cands.push({ src: `npc ${pl[0]} ${okWarp([pl[4], pl[5]]) ? 'warp point' : 'position'}`, x: okWarp([pl[4], pl[5]]) ? pl[4] : pl[1], y: okWarp([pl[4], pl[5]]) ? pl[5] : pl[2] });
    }
    if (!cands.length && e.waves?.length) { const w = e.waves[0]; cands.push({ src: `first wave ${w.call} centre (fallback)`, x: Math.round(w.center[0]), y: Math.round(w.center[1]) }); }
    for (const c of cands) {
      const d = walkCheck(grid, 'spawns', c.x, c.y, 4); if (d !== null) c.walk = d;
      if (grid && d !== null && d !== 0) { const w = nearestWalkable(grid, c.x, c.y, 16); if (w) c.snap = [w.x + 0.5, w.y + 0.5]; }
    }
    if (cands.length) { e.spawn = cands[0]; if (cands.length > 1) e.spawnAlt = cands.slice(1, 6); }
    // script-spawned monsters (scriptmonster_<map>.csv ids that no MON_/CallMonster row places): the position lives in
    // the server script, so suggest one: boss -> the boss-summon device, else the last wave / farthest gate; others ->
    // the closed scripted gate nearest to the entry point (they usually guard it), else the entry point.
    if (e.scriptMonsters) {
      const at = (o) => (o ? [o.warp ? o.warp[0] : o.x, o.warp ? o.warp[1] : o.y] : null);
      const summon = (e.scriptNpcs || []).find((n) => n.role === 'bossSummon');
      const sp = e.spawn ? [e.spawn.x, e.spawn.y] : null;
      const gates = (e.bricks || []).filter((b) => b.create && brickDefs.defs[b.brick]?.role !== 'breakable');
      const byDist = (list, p) => (p ? [...list].sort((a, b) => Math.hypot(a.x - p[0], a.y - p[1]) - Math.hypot(b.x - p[0], b.y - p[1])) : list);
      const ss = [];
      for (const id of e.scriptMonsters) {
        if (present.has(id)) continue;
        const m = monInfo(id); const boss = isBossMon(id);
        let pos = null, src = null;
        if (boss && summon) { pos = at(summon); src = `bossSummon npc ${summon.npc}`; }
        else if (boss && e.waves?.length) { const w = e.waves[e.waves.length - 1]; pos = w.center.map(Math.round); src = `last wave ${w.call}`; }
        else if (boss && gates.length) { const g = byDist(gates, sp).at(-1); pos = [g.x, g.y]; src = `farthest gate ${g.uid}`; }
        else if (!boss && gates.length) { const g = byDist(gates, sp)[0]; pos = [g.x, g.y]; src = `nearest gate ${g.uid}`; }
        else if (sp) { pos = sp; src = 'entry point'; }
        if (pos && grid) { const w = nearestWalkable(grid, pos[0], pos[1], 12); if (w) pos = [w.x, w.y]; }
        ss.push({ monster: id, name: m?.name || null, rank: m?.rank ?? null, level: m?.level ?? null, boss: boss ? 1 : 0, suggest: pos, suggestFrom: src });
      }
      if (ss.length) e.scriptSpawns = ss;
    }
    // reconstructed stage flow (instances / events only)
    if (e.kind === 'instance' || e.kind === 'event' || e.kind === 'colosseum') e.stages = reconstructStages(mi, e);
  }

  // DUNGEON_SCRIPT dialog linking (the server script decides which dialog an NPC opens; the client has no table):
  //  1. JobIndex J >= 100 and code J+1 (Dead Front convention) or J is a dialog with menu entries -> that dialog;
  //  2. otherwise a one-to-one greedy assignment on keyword overlap between the NPC (name, shape) and the dialog
  //     (designer comment, text, menu entries, gauge captions), +3 when a mission line names the NPC and shares
  //     keywords with the dialog comment ("Find the Unknown Statue" / "#Mission 1: Lever Operation" <-> "#Lever Operation").
  function assignDialogs(list, src, T, missions) {
    if (!T) return;
    const isDlg = (c) => T[c] && T[c].m && T[c].m.length;
    const children = new Set(); const parentOf = new Map();
    for (const [c, v] of Object.entries(T)) for (const k of v.m || []) { children.add(k); if (!parentOf.has(k)) parentOf.set(k, +c); }
    const roots = Object.keys(T).map(Number).filter((c) => c >= 1000 && isDlg(c) && !children.has(c) && !/already|not defeated|sever merge|server merge|hacker/i.test(T[c].c || ''));
    const dtok = new Map(roots.map((c) => { const v = T[c]; let s = `${v.c || ''} ${v.t || ''}`; for (const k of v.m) s += ` ${T[k]?.t || ''} ${(T[k]?.fx || []).map((f) => f.text || '').join(' ')}`; return [c, toks(s)]; }));
    // JobIndex J of a DUNGEON_SCRIPT NPC = string code of its entry in the NPC menu ("Examine", "Talk to Regena.",
    // "I'll take a look at the lever."): the label shown in the NPC window; the dialog it opens is chosen by the script.
    const ntok = src.map((n, i) => { const lab = T[n.job[1]]?.t || ''; const t = toks(`${n.name} ${n.shape || ''} ${lab}`); for (const w of [...t]) for (const [k, v] of Object.entries(SYN)) if (w.includes(k)) v.forEach((x) => t.add(x)); return t; });
    const pairs = [];
    list.forEach((o, i) => {
      const J = o.job[1];
      if (T[J]?.t) o.label = T[J].t;
      if (J >= 100 && isDlg(J + 1)) { o.dialog = J + 1; o.dialogBy = 'label+1'; return; }
      if (J >= 100 && isDlg(J)) { o.dialog = J; o.dialogBy = 'jobIndex'; return; }
      if (J >= 100 && parentOf.has(J)) { o.dialog = parentOf.get(J); o.dialogBy = 'menuParent'; return; }
      const nameLc = String(o.name || '').toLowerCase();
      for (const c of roots) {
        let s = 0; for (const w of ntok[i]) if (dtok.get(c).has(w)) s++;
        for (const m of missions || []) if (nameLc.length > 3 && String(m.text).toLowerCase().includes(nameLc)) { const mt = toks(m.note); const ct = toks(T[c].c); for (const w of mt) if (ct.has(w)) { s += 3; break; } }
        if (s > 0) pairs.push([s, i, c]);
      }
    });
    pairs.sort((a, b) => b[0] - a[0] || a[2] - b[2]);
    const used = new Set();
    for (const [s, i, c] of pairs) { const o = list[i]; if (o.dialog != null || used.has(c)) continue; o.dialog = c; o.dialogBy = `keywords(${s})`; used.add(c); }
    for (const [s, i, c] of pairs) { const o = list[i]; if (o.dialog != null) continue; o.dialog = c; o.dialogBy = `keywords-shared(${s})`; }
    list.forEach((o, i) => { const alt = pairs.filter((p) => p[1] === i && p[2] !== o.dialog).slice(0, 3).map((p) => p[2]); if (alt.length && String(o.dialogBy).startsWith('keywords')) o.dialogAlt = alt; });
  }
  function npcRole(n, dlg) {
    const txt = `${n.name} ${n.label || ''} ${dlg?.c || ''} ${dlg?.t || ''}`.toLowerCase();
    if (/boss summon|summon/.test(txt)) return 'bossSummon';
    if (/exit|leave|return to|escape|would you like to exit|move out|go back/.test(txt) && !/enter \d|next floor|2nd floor|3rd floor|4th floor|5th floor/.test(txt)) return 'exit';
    if (/starting lever|start lever|^starting|open the gate|open the chamber door/.test(txt) || (/start/.test(txt) && /lever|switch|knob/.test(txt))) return 'start';
    if (/stairs|floor|enter \d|next stage|move to the|warp|teleport|portal|lobby/.test(txt) || n.job[1] === 6) return 'warp';
    if (/lever|switch|knob|statue|stone|slate|book|seal|altar|device|examine|touch|pull/.test(txt) || n.job[1] === 5) return 'interact';
    return 'talk';
  }

  function reconstructStages(mi, e) {
    const stages = [];
    const T = e.messages || {};
    const missions = e.missions || [];
    const waves = e.waves || [];
    const bossWaves = waves.filter((w) => w.bosses?.length);
    const gates = (e.bricks || []).filter((b) => brickDefs.defs[b.brick] && brickDefs.defs[b.brick].role !== 'breakable' && b.create);
    const nearestWave = (x, y) => { let best = null, bd = Infinity; for (const w of waves) { const d = Math.hypot(w.center[0] - x, w.center[1] - y) - w.radius; if (d < bd) { bd = d; best = w.call; } } return best === null ? null : { call: best, dist: round(Math.max(0, bd), 1) }; };
    for (const b of e.bricks || []) { const nw = nearestWave(b.x, b.y); if (nw) { b.nearWave = nw.call; b.nearWaveDist = nw.dist; } }
    let k = 0;
    for (const w of waves) {
      k++;
      const st = { n: k, call: w.call, objective: w.bosses?.length ? 'kill-boss' : 'kill-all', monsters: w.count };
      if (w.bosses?.length) { st.bosses = w.bosses; const al = (e.bosses || []).filter((b) => w.bosses.includes(b.monster)).flatMap((b) => b.alert || []); if (al.length) st.alert = al; }
      const opens = gates.filter((b) => b.nearWave === w.call).map((b) => b.uid);
      if (opens.length) st.opens = opens;
      stages.push(st);
    }
    const scriptBosses = (e.scriptSpawns || []).filter((s) => s.boss).map((s) => s.monster);
    if (scriptBosses.length) {
      const st = { n: ++k, script: scriptBosses, objective: 'kill-boss', bosses: scriptBosses };
      const al = (e.bosses || []).filter((b) => scriptBosses.includes(b.monster)).flatMap((b) => b.alert || []); if (al.length) st.alert = al;
      const sm = (e.scriptNpcs || []).find((n) => n.role === 'bossSummon'); if (sm) st.trigger = { npc: sm.npc, dialog: sm.dialog };
      stages.push(st);
    }
    const out = { inferred: 1, stages };
    if (missions.length) out.missions = missions.map((m) => m.code);
    // call indices numbered floor*10+k (Forbidden Fetters 11..209: 20 floors, one per forbiddenshacklesdata.csv row)
    const calls = waves.map((w) => w.call);
    if (calls.length >= 12 && calls.filter((c) => c >= 11).length / calls.length > 0.9) {
      const grp = new Map();
      for (const w of waves) { const g = Math.floor(w.call / 10); if (!grp.has(g)) grp.set(g, { group: g, calls: [], monsters: 0 }); const o = grp.get(g); o.calls.push(w.call); o.monsters += w.count; }
      out.groups = [...grp.values()];
      if (mi === 260) for (const g of out.groups) { const f = forbiddenShackles.find((x) => x.floor === g.group); if (f) { g.floor = f.floor; g.clearExp = f.clearExp; g.resetCost = f.resetCost; } }
      out.groupNote = 'waves grouped by CallIndex / 10 (floor or round number)';
    }
    if (!waves.length) out.note = e.static ? 'no CallMonster waves: static MON_ spawns only (clear = every static monster dead / boss dead)' : 'no monster waves in the client data (server-side only or NPC/trigger driven)';
    const bossIds = (e.bosses || []).filter((b) => !b.scriptOnly).map((b) => b.monster);
    if (scriptBosses.length) out.clear = { kind: 'boss', monsters: scriptBosses };
    else if (bossWaves.length) out.clear = { kind: 'boss', monsters: bossWaves[bossWaves.length - 1].bosses };
    else if (bossIds.length) out.clear = { kind: 'boss', monsters: bossIds };
    else if (waves.length) out.clear = { kind: 'all-waves' };
    else if (e.static) out.clear = { kind: 'all-static' };
    else out.clear = { kind: 'script' };
    if (T[1300]) out.clearMessage = 1300; if (T[2000]) out.startMessage = 2000; if (T[3000]) out.failMessage = 3000;
    return out;
  }

  // ---------------------------------------------------------------- dungeons
  const dungeons = {};
  const KEEPERS = new Set();
  const ticketItems = [];
  for (const [idx, { r, rowNo }] of [...dungeonRows].sort((a, b) => a[0] - b[0])) {
    const g = (n) => DL.get(r, n);
    const cnt = num(g('MapCount'));
    const floors = [];
    for (let k = 0; k < Math.max(cnt, 1); k++) { const mi = numOrNull(g(`MapIndex_${k}`)); if (mi !== null && !(k > 0 && mi === 0)) floors.push(mi); }
    const csvName = clean(g('Dungeon_Name'));
    let name = csvName, nameSrc = 'dungeonlist';
    const lz = loc(`share#dungeonlist.csv#0|${rowNo}`);
    if (hasHangul(name) && lz && !hasHangul(lz)) { name = lz; nameSrc = 'lines_eu'; }
    if (hasHangul(name)) { const mn = mapName(floors[0]); if (mn && !hasHangul(mn)) { name = mn; nameSrc = 'maplist'; } }
    if (hasHangul(name) && STR.get(floors[0])?.codes.get(1)?.text && !hasHangul(STR.get(floors[0]).codes.get(1).text)) { name = STR.get(floors[0]).codes.get(1).text; nameSrc = 'string code 1'; }
    const keeper = clean(g('Keeper_Type')); KEEPERS.add(keeper);
    const f0 = maps[floors[0]];
    const ticketRaw = num(g('Ticket'));
    const d = {
      name, keeper, floors,
      party: { min: num(g('RequestMember')), max: num(g('RequestMember_Max')) },
      solo: { allowed: 1, original: keeper === 'SOLO' ? 'solo' : `${keeper.toLowerCase()} (min ${num(g('RequestMember'))})` },
      ...(keeper === 'PARTYMATCH' ? { pvpOnly: 1 } : {}),
      expireTime: num(g('ExpireTime')),
      entry: {
        npcs: (entryNpcs.get(idx) || []).map((n) => ({ ...n, mapName: mapName(n.map) })),
        levels: f0 ? f0.levels : null,
        ticket: ticketRaw > 1 ? { item: ticketRaw, name: itemName(ticketRaw) } : null,
        vehicle: num(g('IsVehicle')), siegeSeal: num(g('IsSiegeSeal')), check: num(g('Check')), captchaRate: num(g('CaptchaRate')),
        spawn: f0?.spawn || null,
      },
      exit: { kickType: clean(g('KickType')), to: [0, 1].map((k) => ({ map: num(g(`KickToMap_${k}`)), x: num(g(`KickToX_${k}`)), y: num(g(`KickToY_${k}`)) })).filter((p, i) => i === 0 || p.map || p.x || p.y), respawnOnKick: num(g('KickRespawn')) },
      raw: Object.fromEntries(DL.headers.map((h, i) => [h, r[i] ?? ''])),
    };
    if (csvName !== name) d.nameKr = csvName;
    if (nameSrc !== 'dungeonlist') d.nameSrc = nameSrc;
    if (ticketRaw > 1) { ticketItems.push(ticketRaw); usedItems.add(ticketRaw); }
    for (const x of d.exit.to) if (x.map && !maplist.has(x.map)) hard(`dungeon ${idx}: kick map ${x.map} not in maplist`);
    const missingFloors = floors.filter((fm) => !maplist.has(fm));
    if (missingFloors.length) { d.missingFloors = missingFloors; soft(`dungeon ${idx} (${name}): floor map(s) ${missingFloors.join(',')} not in maplist (client hole: unplayable as shipped)`); }
    const defs = (entryDefs.get(idx) || []).filter((n) => !d.entry.npcs.some((p) => p.npc === n));
    if (defs.length) d.entry.unplacedNpcs = defs.map((n) => ({ npc: n, name: NPC.npcs[n]?.name || null }));
    if (!d.entry.npcs.length && (d.exit.to[0].map || d.exit.to[0].x)) d.entry.fallback = { map: d.exit.to[0].map, x: d.exit.to[0].x, y: d.exit.to[0].y, src: 'KickTo (exit point = in front of the original entrance)' };
    if (f0) { if (f0.title) d.title = f0.title; if (f0.mission) d.mission = f0.mission; if (f0.timeLimit) d.timeLimit = f0.timeLimit; }
    d.rewards = rewardsFor(floors);
    dungeons[idx] = d;
  }
  // instance / event maps that dungeonlist does not describe (Dead Front, Ice Castle, Helion's Sanctuary, colosseum ...)
  const extra = [];
  for (const mi of allMapIdx) {
    const e = maps[mi];
    if (e.dungeon !== undefined) continue;
    if (!(e.kind === 'instance' || e.kind === 'event' || e.kind === 'colosseum' || (e.kind === 'siege' && e.dungeonIndex))) continue;
    const key = `m${mi}`;
    const ents = []; for (const [di, list] of entryNpcs) if (di === mi || (e.dungeonIndex && di === e.dungeonIndex)) ents.push(...list.map((n) => ({ ...n, mapName: mapName(n.map) })));
    dungeons[key] = { name: e.name, keeper: e.kind === 'event' ? 'EVENT' : e.kind === 'colosseum' ? 'COLOSSEUM' : e.kind === 'siege' ? 'SIEGE' : 'INSTANCE', floors: [mi], source: 'maplist',
      party: null, solo: { allowed: 1, original: 'not in dungeonlist.csv' }, entry: { npcs: ents, levels: e.levels, spawn: e.spawn || null }, rewards: rewardsFor([mi]) };
    // event maps (Dead Front / Ice Castle ...) send the dead / finished player to their lobby: dkmaplist RespawnMap_00
    const rp = e.dk?.points?.find((p) => p.map && p.map !== mi);
    if (rp) { dungeons[key].exit = { kickType: 'DKMAPLIST_RESPAWN', to: [{ map: rp.map, x: rp.x, y: rp.y }] }; dungeons[key].entry.lobby = rp.map; }
    if (e.title) dungeons[key].title = e.title; if (e.mission) dungeons[key].mission = e.mission; if (e.timeLimit) dungeons[key].timeLimit = e.timeLimit;
    e.dungeon = key; extra.push(key);
  }

  function rewardsFor(floors) {
    const out = {};
    const bosses = new Set(); const tds = []; const md = [];
    for (const fm of floors) {
      const e = maps[fm]; if (!e) continue;
      for (const b of e.bosses || []) bosses.add(b.monster);
      for (const k of Object.keys(triggerDrops)) if (k.startsWith(`${fm}:`)) tds.push(k);
      if (mapDrops[fm] && (mapDrops[fm].sets.length || Object.keys(mapDrops[fm].raw).length)) md.push(fm);
      if (e.messages?.[930]) out.perfectExpMessage = 930;
    }
    if (bosses.size) out.bossDrops = [...bosses];
    if (tds.length) out.triggerDrops = tds;
    if (md.length) out.mapDrops = md;
    if (floors.includes(260)) out.special = 'forbiddenShackles';
    if (floors.some((f) => [234, 235, 250, 251, 263, 264].includes(f))) out.special = 'forgottenShipwreck';
    return out;
  }

  // ---------------------------------------------------------------- travel data
  const travel = buildTravel();
  for (const w of travel.warps) if (w.kind !== 'disabled' && w.fromMap != null && maps[w.fromMap]) (maps[w.fromMap].warps ||= []).push(w.id);
  if (msgMissing.length) soft(`message-table codes without any text in the DUNGEON string files (map:missing/rows): ${msgMissing.join(' ')}`);

  function buildTravel() {
    const out = {};
    // locations (all rows, placeholders included: scripted warps use them as "no fixed source point")
    const locations = {};
    const locNoMap = [];
    const locRows = parseTable(readKr('share/arrange/location.csv')).rows;
    locRows.forEach((r, i) => {
      const idx = numOrNull(r[0]); if (idx === null) return;
      const l = LOC.get(idx); if (!l) return;
      const en = loc(`arrange#location.csv#1|${i + 1}`);
      const name = en && !hasHangul(en) ? en : l.name;
      const e = [l.mapIndex, l.x, l.y, round(l.directionDeg, 1), name];
      if (l.x2 !== l.x || l.y2 !== l.y || l.direction2 !== l.direction) e.push([l.x2, l.y2, round(l.direction2Deg, 1)]);
      locations[idx] = e;
      if (!maplist.has(l.mapIndex)) locNoMap.push(`${idx}@${l.mapIndex}`);
      else if (!l.placeholder) { const gr = macOf(l.mapIndex); walkCheck(gr, 'locations', l.x, l.y, 3); }
    });
    if (locNoMap.length) soft(`${locNoMap.length} location.csv rows on maps missing from maplist (orphan maps): ${locNoMap.join(' ')}`);
    out.locationFields = ['map', 'x', 'y', 'dirDeg', 'name', '[x2, y2, dir2Deg] only when the second triple differs'];
    out.locations = locations;

    // walk-in warp zones (share/arrange/warp.csv)
    const W = parseTable(readKr('share/arrange/warp.csv'));
    const warps = [];
    const moveZones = new Map();
    const moveZonesOf = (mi) => {
      if (moveZones.has(mi)) return moveZones.get(mi);
      const fm = mapFiles(mi); let list = [];
      if (fm?.mol && has(fm.mol)) { try { list = parseMol(readRel(fm.mol)).objects.filter((o) => /movezone|^portal[\\/]|potal/i.test(o.name)).map((o) => ({ name: o.name, x: o.x, z: o.z })); } catch { list = []; } }
      moveZones.set(mi, list); return list;
    };
    // Rect semantics test: is the zone [x, x+w) x [y, y+h) (from-location = min corner) or centred on the location?
    // Measured on the .mac walkability and on the warp-gate objects of the .mol (their centre sits in the rect centre).
    const zoneStats = { tested: 0, walkAnchored: 0, walkCentered: 0, meanWalkAnchored: 0, meanWalkCentered: 0, withObject: 0, objToAnchoredCentre: 0, objToLocation: 0 };
    for (const r of W.rows) {
      const id = numOrNull(r[0]); if (id === null) continue;
      const from = num(W.get(r, 'From_LocationIndex')), to = num(W.get(r, 'To_LocationIndex'));
      const rw = num(W.get(r, 'Rect_X')), rh = num(W.get(r, 'Rect_Y'));
      const a = LOC.get(from), b = LOC.get(to);
      if (!a) hard(`warp ${id}: from location ${from} missing`); if (!b) hard(`warp ${id}: to location ${to} missing`);
      let kind = 'zone';
      if (!rw && !rh) kind = 'disabled';
      else if (a && a.placeholder) kind = 'scripted';
      if (from === to) kind = 'disabled';
      const w = { id, from, to, rect: [rw, rh], kind, siege: num(W.get(r, 'Seige')), dungeon: num(W.get(r, 'Dengeon')) };
      if (a) w.fromMap = a.mapIndex; if (b) w.toMap = b.mapIndex;
      if (kind === 'zone' && a) {
        w.box = [a.x, a.y, a.x + rw, a.y + rh];
        const gr = macOf(a.mapIndex);
        if (gr) {
          const frac = (x0, y0) => { let wk = 0, n = 0; for (let y = Math.floor(y0); y < Math.floor(y0) + rh; y++) for (let x = Math.floor(x0); x < Math.floor(x0) + rw; x++) { n++; if (gr.isWalkable(x, y)) wk++; } return n ? wk / n : 0; };
          const anc = frac(a.x, a.y), cen = frac(a.x - rw / 2, a.y - rh / 2);
          zoneStats.tested++; zoneStats.meanWalkAnchored += anc; zoneStats.meanWalkCentered += cen;
          if (anc > cen) zoneStats.walkAnchored++; else if (cen > anc) zoneStats.walkCentered++;
          w.walk = round(anc, 2);
        }
        const mz = moveZonesOf(a.mapIndex);
        const cx = a.x + rw / 2, cy = a.y + rh / 2;
        let best = null; for (const o of mz) { const d = Math.hypot(o.x - cx, o.z - cy); if (!best || d < best.d) best = { d, o }; }
        if (best && best.d <= Math.max(rw, rh) + 3) {
          w.object = best.o.name.replace(/\\/g, '/').toLowerCase();
          zoneStats.withObject++; zoneStats.objToAnchoredCentre += best.d; zoneStats.objToLocation += Math.hypot(best.o.x - a.x, best.o.z - a.y);
        }
      }
      warps.push(w);
    }
    if (zoneStats.tested) { zoneStats.meanWalkAnchored = round(zoneStats.meanWalkAnchored / zoneStats.tested, 3); zoneStats.meanWalkCentered = round(zoneStats.meanWalkCentered / zoneStats.tested, 3); }
    if (zoneStats.withObject) { zoneStats.objToAnchoredCentre = round(zoneStats.objToAnchoredCentre / zoneStats.withObject, 2); zoneStats.objToLocation = round(zoneStats.objToLocation / zoneStats.withObject, 2); }
    out.warpFields = { box: '[x0, y0, x1, y1] trigger rectangle in cells: the from-location is the MIN corner, Rect_X/Rect_Y extend towards +x/+y (warp-gate objects sit at the rectangle centre)', kind: 'zone = walk-in trigger area; scripted = the from-location is a (0,0) placeholder: fired by an NPC / map script; disabled = 0x0 rect or self-loop', dungeon: 'Dengeon column: 1 = the warp lives inside an instance (room-to-room pads)', siege: 'Seige column: 1 = siege-war warp (Zenoa castle gates)' };
    out.warps = warps;
    out.warpZoneStats = zoneStats;

    // portal network (Return Portal NPCs, job 16): creature/portal.csv + portallocation.csv + portal_shape.csv
    const PT = parseTable(readKr('share/creature/portal.csv'));
    const PS = parseTable(readKr('script/shape/portal_shape.csv'));
    const pshape = PS.rows[0] ? { effect: num(PS.rows[0][3]), fieldMesh: exists(rootKey('mesh', PS.rows[0][10])), fieldTpack: exists(rootKey('texturepack', PS.rows[0][11])), offset: [num(PS.rows[0][13]), num(PS.rows[0][14]), num(PS.rows[0][15])], scale: num(PS.rows[0][16]), fieldEffect: num(PS.rows[0][19]) } : null;
    out.portalShape = pshape;
    // portal.csv LocationIndex is the MapIndex key of portallocation.csv (not a location.csv row): 21 of 26 resolve,
    // the 5 arena waiting rooms (708/709/712/718/720) have no arrival point in the client.
    const PL = parseMapPointCSV(readKr('share/arrange/portallocation.csv'));
    const plNames = new Map(); parseTable(readKr('share/arrange/portallocation.csv')).rows.forEach((r) => plNames.set(num(r[0]), r[4]));
    out.portalArrivals = PL.map((p) => ({ map: p.mapIndex, x: p.x, y: p.y, dir: p.direction ?? 0, name: plNames.get(p.mapIndex) || p.name }));
    const arrivalByMap = new Map(out.portalArrivals.map((p) => [p.map, p]));
    out.portals = PT.rows.map((r) => {
      const p = { map: num(r[0]), location: num(r[1]), shape: r[2], mapName: mapName(num(r[0])) };
      const a = arrivalByMap.get(p.location); if (a) p.arrival = [a.x, a.y]; else p.arrival = null;
      if (!maplist.has(p.map)) soft(`portal map ${p.map} not in maplist`);
      return p;
    });
    const noArrival = out.portals.filter((p) => !p.arrival).map((p) => p.map);
    if (noArrival.length) soft(`portal.csv maps without a portallocation arrival point: ${noArrival.join(',')}`);

    // NPC teleport menus (job TELEPORT = 2, JobIndex -> share/arrange/teleport.csv row) + stringtable_teleport.txt
    const TS = parseCateStringTable(readKr('script/string/stringtable_teleport.txt'));
    const TP = parseTable(readKr('share/arrange/teleport.csv'));
    const teleports = {};
    for (const r of TP.rows) {
      const id = numOrNull(r[0]); if (id === null) continue;
      const cat = TS.get(id)?.codes;
      const units = [];
      const cnt = num(TP.get(r, 'UnitCount'));
      for (let k = 1; k <= 15; k++) {
        const li = num(TP.get(r, `LocationIndex_${k}`)); if (!li) continue;
        const l = LOC.get(li); if (!l) { hard(`teleport ${id}: location ${li} missing`); continue; }
        const sc = num(TP.get(r, `String_${k}`));
        const lname = locations[li]?.[4] || l.name;
        const cost = num(TP.get(r, `Cost_${k}`)), level = num(TP.get(r, `Level_${k}`));
        const tmpl = cat?.get(sc)?.text || null;
        const label = tmpl ? tmpl.replace(/<MAPNAME>/g, lname).replace(/<LEVEL>/g, level).replace(/<COST>/g, cost) : `${lname} (LV:${level}+, DIL:${cost})`;
        units.push({ unit: num(TP.get(r, `UnitIndex_${k}`)), location: li, map: l.mapIndex, cost, level, label });
      }
      teleports[id] = { useStrings: num(TP.get(r, 'Teleport_StringIndex')), count: cnt, prompt: cat?.get(1)?.text || 'Where do you want to go?', units };
    }
    out.teleports = teleports;
    // which NPCs open which teleport menu / other travel jobs
    const travelNpcs = [];
    const TRAVEL_JOBS = { 2: 'TELEPORT', 4: 'RETURN', 16: 'PORTAL', 21: 'SIEGE_TELEPORT', 42: 'SKY_TELEPORT', 50: 'ARENA_TELEPORT', 127: 'SIEGE_DEFENDER_TELEPORT', 128: 'SIEGE_MASTER_TELEPORT' };
    for (const [mapKey, pl] of Object.entries(NPC.placements || {})) {
      for (const row of pl.rows) {
        const def = NPC.npcs[row[0]]; if (!def?.jobs) continue;
        for (const [jt, ji] of def.jobs) if (TRAVEL_JOBS[jt]) {
          const o = { npc: row[0], name: def.name, map: +mapKey, x: round(row[1]), y: round(row[2]), job: TRAVEL_JOBS[jt], index: ji };
          if (jt === 2 && !teleports[ji]) soft(`teleport NPC ${row[0]} (${def.name}) map ${mapKey}: teleport table ${ji} missing`);
          if (jt === 4) { if (LOC.get(ji)) o.returnLocation = ji; else soft(`return NPC ${row[0]}: location ${ji} missing`); }   // RETURN: JobIndex = location.csv bind point
          if (jt === 42) o.skyTable = ji;                                                                                      // SKY_TELEPORT: skyteleport.csv row
          travelNpcs.push(o);
        }
      }
    }
    out.travelNpcs = travelNpcs;
    // sky teleport / siege teleport / premiere teleport / smart warp
    const SK = parseTable(readKr('share/arrange/skyteleport.csv'));
    out.skyTeleports = SK.rows.map((r) => {
      const units = [];
      for (let k = 1; k <= 9; k++) { const li = num(SK.get(r, `LocationIndex_${k}`)); if (!li) continue; units.push({ unit: num(SK.get(r, `UnitIndex_${k}`)), location: li, string: num(SK.get(r, `String_${k}`)), cost: num(SK.get(r, `Cost_${k}`)), level: num(SK.get(r, `Level_${k}`)), skyQuest: num(SK.get(r, `SkyQuest_${k}`)) }); if (!LOC.get(li)) hard(`skyteleport: location ${li} missing`); }
      return { id: num(r[0]), string: num(SK.get(r, 'Teleport_StringIndex')), skyQuest: num(SK.get(r, 'SkyQuest')), units };
    });
    const SGT = parseTable(readKr('share/arrange/siegeteleport.csv'));
    out.siegeTeleports = SGT.rows.map((r) => ({ id: num(r[0]), dialog: num(r[1]), location: num(r[2]), desc: num(r[3]), state: num(r[4]) }));
    const PR = parseTable(readKr('share/premiere/teleport.csv'));
    out.premiereTeleports = PR.rows.map((r, i) => { const li = num(r[0]); if (!LOC.get(li)) soft(`premiere teleport: location ${li} missing`); const en = loc(`premiere#teleport.csv#2|${i + 1}`); return { location: li, type: num(r[1]), name: en && !hasHangul(en) ? en : r[2], levels: [num(r[3]), num(r[4])] }; });
    const SW = parseTable(readKr('share/support/smartwarp/smartwarp.csv'));
    out.smartWarp = SW.rows.map((r, i) => { const en = loc(`smartwarp#smartwarp.csv#4|${i + 1}`); const mi = num(SW.get(r, 'Map Index')); if (!maplist.has(mi)) soft(`smartwarp ${r[0]}: map ${mi} not in maplist`); return { id: num(r[0]), levels: [num(SW.get(r, 'Level Min')), num(SW.get(r, 'Level Max'))], type: num(SW.get(r, 'Type')), name: en && !hasHangul(en) ? en : SW.get(r, 'Name'), map: mi, x: num(SW.get(r, 'Position_X')), y: num(SW.get(r, 'Position_Y')), dirDeg: num(SW.get(r, 'Direction')), help: num(SW.get(r, 'Help Notify')) }; });
    // start / chaotic / return
    const SP = parseTable(readKr('share/pc/startpoint.csv'));
    out.startPoints = SP.rows.map((r) => ({ index: num(r[0]), location: num(r[1]), returnLocation: num(r[2]) }));
    const CH = parseTable(readKr('share/arrange/chaoticlocation.csv'));
    out.chaoticLocations = CH.rows.map((r, i) => { const en = loc(`arrange#chaoticlocation.csv#4|${i + 1}`); return { map: num(r[0]), x: num(r[1]), y: num(r[2]), dir: num(r[3]), name: en && !hasHangul(en) ? en : (mapName(num(r[0])) || r[4]) }; });
    // map graph
    const graph = {};
    const edge = (a, b, via, ref) => { if (a === b || a == null || b == null) return; (graph[a] ||= []).push({ to: b, via, ref }); };
    for (const w of warps) if (w.kind !== 'disabled' && w.fromMap != null) edge(w.fromMap, w.toMap, w.kind === 'zone' ? 'warp' : 'scriptedWarp', w.id);
    for (const n of travelNpcs) if (n.job === 'TELEPORT' && teleports[n.index]) for (const u of teleports[n.index].units) edge(n.map, u.map, 'teleport', `${n.npc}:${n.index}`);
    for (const [di, d] of Object.entries(dungeons)) for (const n of d.entry.npcs || []) if (d.floors?.length) edge(n.map, d.floors[0], 'dungeon', di);
    for (const [di, d] of Object.entries(dungeons)) if (d.exit) for (const t of d.exit.to) if (t.map || t.x) for (const fm of d.floors) edge(fm, t.map, 'dungeonExit', di);
    for (const [di, d] of Object.entries(dungeons)) for (let k = 1; k < (d.floors || []).length; k++) edge(d.floors[k - 1], d.floors[k], 'nextFloor', di);
    for (const k of Object.keys(graph)) { const seen = new Set(); graph[k] = graph[k].filter((e) => { const s = `${e.to}|${e.via}|${e.ref}`; if (seen.has(s)) return false; seen.add(s); return true; }); }
    out.mapGraph = graph;
    return out;
  }

  // ---------------------------------------------------------------- item names for referenced items
  const itemNames = {};
  const missingItems = [];
  for (const it of usedItems) { const n = itemName(it); if (n) itemNames[it] = n; else missingItems.push(it); }
  const missingSets = [...usedSets].filter((s) => !itemSetIdx.has(s));
  const missingSetsEx = [...usedSetsEx].filter((s) => !itemSetExIdx.has(s));
  if (missingItems.length) soft(`${missingItems.length} referenced items not in item.dat: ${missingItems.slice(0, 20).join(', ')}`);
  if (missingSets.length) soft(`${missingSets.length} referenced item sets not in itemset.csv: ${missingSets.slice(0, 20).join(', ')}`);
  if (missingSetsEx.length) soft(`${missingSetsEx.length} referenced ex item sets not in itemsetex.csv: ${missingSetsEx.slice(0, 20).join(', ')}`);

  // ---------------------------------------------------------------- asset verification over the whole output
  const assetKeys = [];
  const walkAssets = (o) => { if (!o || typeof o !== 'object') return; for (const [k, v] of Object.entries(o)) { if (typeof v === 'string' && /^(mesh|texturepack|skel|anim|share|map|script|texture)\//.test(v) && /\.[a-z0-9]+$/.test(v)) assetKeys.push([k, v]); else if (typeof v === 'object') walkAssets(v); } };
  const brickOut = brickDefs.defs, trigOut = triggerDefs.defs;
  walkAssets(brickOut); walkAssets(trigOut); walkAssets(maps); walkAssets(travel.portalShape);
  const badAssets = assetKeys.filter(([k, v]) => !/Missing$/.test(k) && !has(v));
  for (const [k, v] of badAssets.slice(0, 20)) hard(`asset key not on disk: ${k} = ${v}`);

  // ---------------------------------------------------------------- report + spot checks
  // NPC indices used anywhere in the output must exist in share/creature/npc.csv
  const npcCsvIdx = new Set(parseTable(readKr('share/creature/npc.csv')).rows.map((r) => num(r[0], -1)));
  const npcUsed = new Set();
  for (const d of Object.values(dungeons)) { for (const n of d.entry.npcs || []) npcUsed.add(n.npc); for (const n of d.entry.unplacedNpcs || []) npcUsed.add(n.npc); }
  for (const m of Object.values(maps)) for (const n of m.scriptNpcs || []) npcUsed.add(n.npc);
  for (const n of travel.travelNpcs) npcUsed.add(n.npc);
  const npcMissing = [...npcUsed].filter((n) => !npcCsvIdx.has(n));
  for (const n of npcMissing) hard(`NPC index ${n} used but not in share/creature/npc.csv`);
  const report = buildReport();
  report.resolvedRefs = [...new Set(RESOLVED)];   // path-wiring refs re-pointed to the one Global file of that name
  function buildReport() {
    const R = {};
    const dl = Object.values(dungeons);
    R.dungeons = { total: dl.length, fromDungeonList: dungeonRows.size, fromMaplist: extra.length, duplicateIndices: dupDungeon, keepers: [...KEEPERS],
      withEntryNpc: dl.filter((d) => d.entry.npcs?.length).length, withSpawn: dl.filter((d) => d.entry.spawn).length, withTimeLimit: dl.filter((d) => d.timeLimit?.sec).length,
      withTicket: ticketItems.length };
    const mv = Object.values(maps);
    R.maps = { total: mv.length, byKind: mv.reduce((a, m) => ((a[m.kind] = (a[m.kind] || 0) + 1), a), {}), withMessages: mv.filter((m) => m.messages).length,
      withWaves: mv.filter((m) => m.waves).length, waves: mv.reduce((a, m) => a + (m.waves?.length || 0), 0), waveRows: mv.reduce((a, m) => a + (m.waves || []).reduce((b, w) => b + w.rows.length, 0), 0),
      withStatic: mv.filter((m) => m.static).length, staticRows: mv.reduce((a, m) => a + (m.static?.rows.length || 0), 0),
      withBricks: mv.filter((m) => m.bricks).length, bricksPlaced: mv.reduce((a, m) => a + (m.bricks?.length || 0), 0),
      withTriggers: mv.filter((m) => m.triggers?.length).length, triggersPlaced: mv.reduce((a, m) => a + (m.triggers?.length || 0), 0),
      withScriptNpcs: mv.filter((m) => m.scriptNpcs).length, scriptNpcs: mv.reduce((a, m) => a + (m.scriptNpcs?.length || 0), 0),
      scriptNpcDialogLinked: mv.reduce((a, m) => a + (m.scriptNpcs || []).filter((n) => n.dialog != null).length, 0),
      withBosses: mv.filter((m) => m.bosses).length, bosses: mv.reduce((a, m) => a + (m.bosses?.length || 0), 0),
      withScriptMonsters: mv.filter((m) => m.scriptMonsters).length, missingFiles: mv.flatMap((m) => Object.entries(m.files).filter(([k]) => k.endsWith('Missing')).map(([k, v]) => `${k}:${v}`)) };
    R.messages = { tables: msgTables.size, tableRows: msgRows, unlistedFiles: unlistedMsgFiles, headerMismatch: msgIndexMismatch, stringCategories: STR.size, stringCodes: strCodes,
      categoriesWithoutMap: [...STR.keys()].filter((c) => !maplist.has(c)) };
    R.bricks = { defs: Object.keys(brickOut).length, withMesh: Object.values(brickOut).filter((b) => b.mesh).length, withAct: Object.values(brickOut).filter((b) => b.act).length,
      byRole: Object.values(brickOut).reduce((a, b) => ((a[b.role] = (a[b.role] || 0) + 1), a), {}), actTables: brickDefs.actCount, actStats: { ...brickDefs.actStats, bad: brickDefs.actStats.bad.slice(0, 10) },
      missingAssets: [...new Set(brickDefs.missingAssets)].slice(0, 40), missingAssetCount: new Set(brickDefs.missingAssets).size };
    R.triggers = { defs: Object.keys(trigOut).length, withMesh: Object.values(trigOut).filter((b) => b.mesh).length, withAct: Object.values(trigOut).filter((b) => b.act).length,
      actTables: triggerDefs.actCount, missingAssets: [...new Set(triggerDefs.missingAssets)].slice(0, 40), missingAssetCount: new Set(triggerDefs.missingAssets).size, drops: Object.keys(triggerDrops).length };
    R.walkable = Object.fromEntries(Object.entries(V.walk).map(([k, [ok, n]]) => [k, n ? `${ok}/${n} (${round(100 * ok / n, 1)}%)` : 'n/a']));
    R.crossRefs = { monstersMissing: [...V.monstersMissing].sort((a, b) => a - b), monstersNotInMonstersJson: [...V.monstersNotInJson].sort((a, b) => a - b).slice(0, 50),
      itemsReferenced: usedItems.size, itemsMissing: missingItems, itemSetsReferenced: usedSets.size, itemSetsMissing: missingSets, itemSetsExMissing: missingSetsEx,
      assetKeys: assetKeys.length, assetKeysMissing: badAssets.length, npcsReferenced: npcUsed.size, npcsMissing: npcMissing };
    R.travel = { locations: Object.keys(travel.locations).length, warps: travel.warps.length, warpKinds: travel.warps.reduce((a, w) => ((a[w.kind] = (a[w.kind] || 0) + 1), a), {}),
      warpZoneStats: travel.warpZoneStats, portals: travel.portals.length, teleportTables: Object.keys(travel.teleports).length, travelNpcs: travel.travelNpcs.length,
      smartWarp: travel.smartWarp.length, graphMaps: Object.keys(travel.mapGraph).length, graphEdges: Object.values(travel.mapGraph).reduce((a, l) => a + l.length, 0) };
    R.timeLimits = [...new Set(Object.values(maps).filter((m) => m.timeLimit).map((m) => `${m.timeLimit.text} => ${m.timeLimit.sec}`))];
    return R;
  }
  // monster indices referenced by a spawn/wave file but absent from monster.csv + monster.dat are client holes (the
  // shipped server would skip them too): reported, not fatal. Everything else must resolve.
  for (const m of report.crossRefs.monstersMissing) soft(`monster index ${m} referenced by a spawn/wave but not in monster.csv/monsters.json (client hole)`);
  if (report.crossRefs.monstersMissing.length > 3) hard(`${report.crossRefs.monstersMissing.length} unresolved monster indices`);

  // ---------------------------------------------------------------- write
  const common = { generatedBy: 'tools/build-dungeons.mjs', doc: 'docs/formats/dungeons.md' };
  const units = {
    position: 'FILE-frame map cells (docs/formats/coords.md): x = column (X), y = row (Z); integer spawn/wave/location coords = cell index (stand at x+0.5, y+0.5); brick/NPC/trigger coords are continuous. three.js = (x, h, -y)',
    dir: 'degrees (brick/NPC/trigger CSV Direction, smartwarp); location dirDeg already converted from the 0..255 byte angle',
    timeLimit: 'seconds, parsed from string code 3 of the map category',
    rates: 'drop ratios/rates are per 100000 unless stated (monsters.md)',
  };
  const outD = {
    format: 'dekaron-solo/dungeons@1', ...common, units,
    fields: {
      waveRow: ['monster', 'x', 'y', 'cell (scatter radius)', 'count'], staticRow: ['monster', 'respawnSec', 'x', 'y'],
      levelCapRow: ['levelDiffFrom', 'levelDiffTo', 'expRatePct', 'chaoticRatePct', 'blocking', 'blocked', '[r,g,b] monster-name colour'],
      triggerDropMoney: ['countMin', 'countMax', 'dilMin', 'dilMax', 'rate'], triggerDropSet: ['itemSet', 'ratio', 'socket'], triggerDropFixed: ['item', 'stack', 'countMin', 'countMax'],
      triggerDropFixedSet: ['itemSet', 'countMin', 'countMax', 'socket', 'ratio'], shipwreckReward: ['item', 'count', 'rate'],
      unlistedMessageRow: ['MessageIndex', 'StringCode', '...Menu codes'],
    },
    keeperTypes: { SOLO: 'one character', PARTY: 'party; party.min = RequestMember (minimum members), party.max = RequestMember_Max', TROOP: 'expedition (several parties)', GUILD: 'guild members', PARTYMATCH: 'PvP party match arena', SQUARE: 'DK Square cross-server battlefield', EVENT: '(synthesised) scheduled event map, e.g. Dead Front / Ice Castle', COLOSSEUM: '(synthesised) colosseum instance', INSTANCE: '(synthesised) instance map not in dungeonlist', SIEGE: '(synthesised) siege map with a dungeon index' },
    npcScriptJobs: { 19: 'DUNGEON: create/enter instance (JobIndex = dungeon index)', 31: 'DUNGEON_SCRIPT: map-script NPC click (5 = interact/lever/talk, 6 = warp/door/stairs, other = script-specific id; Dead Front: JobIndex+1 = dialog code)', 34: 'RANDOM_DUNGEON', 45: 'TROOP_DUNGEON (expedition instance, JobIndex = dungeon index)', 58: 'MINI_DUNGEON_SCRIPT (JobIndex = dungeon index)', 80: 'EVENT_DUNGEON_SCRIPT' },
    messageCodes: {
      '1': 'dungeon title (info window)', '2': 'mission description', '3': 'time limit text', '5': 'NPC interact button label', '6': 'next-floor button label',
      '10-29': 'mission / objective lines (info window progress list)', '30-39': 'timer captions: 30 running, 31 closing standby, 32 start countdown, 34 success/transfer countdown, 39 close countdown',
      '100-199': 'entry / requirement / inventory alerts', '200': 'finish current mission first', '300-399': 'boss appearance alerts', '500-599': 'device already used / lever alerts',
      '800-899': 'boss entrance / defeat flash lines (UI effect)', '900-999': 'progress alerts (gate opened, hallway cleared, exit info, 930 perfect-exp)', '1300': 'dungeon cleared effect',
      '2000': 'dungeon start effect', '3000': 'mission failed effect', '>=10000': 'NPC / device dialogs; m = menu entry codes (the entry text may carry a <guage> progress bar)',
      note: 'standard layout of instance categories; Dead Front / Ice Castle / field-event categories use their own numbering (see comments c)',
    },
    systemText: Object.fromEntries([...SYS].map(([c, v]) => [c, v.text])),
    dungeons, maps,
    bricks: brickOut, triggers: trigOut, triggerDrops, mapDrops,
    levelCaps, forbiddenShackles, forgottenShipwreck: { rewards: shipwreckRewards, schedule: shipwreckSchedule }, fieldBosses, fieldBossSummons, bossMemento,
    unlistedMessageTables, itemNames, report,
  };
  const outT = { format: 'dekaron-solo/travel@1', ...common, units, ...travel };
  fs.mkdirSync(OUTDIR, { recursive: true });
  const dump = (o) => JSON.stringify(o, null, PRETTY ? 1 : 0);
  const pD = path.join(OUTDIR, 'dungeons.json'), pT = path.join(OUTDIR, 'dungeons_travel.json');
  fs.writeFileSync(pD, dump(outD)); fs.writeFileSync(pT, dump(outT));
  log(`wrote ${pD} (${(fs.statSync(pD).size / 1048576).toFixed(2)} MB), ${pT} (${(fs.statSync(pT).size / 1048576).toFixed(2)} MB)`);

  // ---------------------------------------------------------------- summary
  log(JSON.stringify(report, null, 1).slice(0, QUIET ? 0 : 20000));
  spotChecks(outD, outT);
  log(`\nhard failures: ${problems.hard.length}, soft warnings: ${problems.soft.length}  (${((Date.now() - t0) / 1000).toFixed(1)} s)`);
  for (const h of problems.hard.slice(0, 40)) console.log('  HARD', h);
  for (const s of problems.soft.slice(0, QUIET ? 0 : 60)) log('  soft', s);
  process.exitCode = problems.hard.length ? 1 : 0;
}

const MAPLIST_RAW = ['PcStore', 'wChaoticDecrease', 'dwChaoticDecreasePeriod', 'MoveSpeedFactor', 'IsWarFog', 'LoadatServer', 'RetMapIndex', 'RetX', 'RetY', 'RetDirection',
  'IsFindAuto', 'IsOrnament', 'IsGuildObserver', 'FOV', 'RandomItem', 'IsInviteAlliance', 'IsCreateAlliance', 'TerritoryIndex', 'IsUrbanWarfare', 'GradeExpSharePolicy',
  'isDeclareWar', 'isUseMap', 'viewType', 'OnedayTime(Min)', 'EnvironmentFile', 'EnvironmentMap'];
const BRICK_KNOWN = new Set(['Name', 'Property', 'Rank', 'Material', 'Level', 'MaxHP', 'DefaultHP', 'HPRecovery', 'ActionType', 'Disappear', 'WidthSize', 'HeightSize',
  'Defence_Min', 'Defence_Max', 'MeleeDamageResist', 'RangeDamageResist', 'PhysicalResist', 'MagicResist', 'ShapeInfo', 'DescriptionInfo', 'Exp', 'Money_Min', 'Money_Max',
  'Money_Rate', 'StatusIndex', 'LifeTime', 'ShowName', 'Ally', 'Targeting', 'IsAttackable',
  ...Array.from({ length: 15 }, (_, i) => `ItemSetIndex_${i + 1}`), ...Array.from({ length: 15 }, (_, i) => `ItemSetDropRatio_${i + 1}`)]);

// 10 hand-verified spot checks: values read by hand from the raw files (see docs/formats/dungeons.md "Validation").
function spotChecks(D, T) {
  const checks = [
    ['dungeonlist 89 Tower of Spell 1F: PARTY, min 2, floors 89..93, kick to map 88 (400,100)', () => { const d = D.dungeons[89]; return d.keeper === 'PARTY' && d.party.min === 2 && d.floors.join() === '89,90,91,92,93' && d.exit.to[0].map === 88 && d.exit.to[0].x === 400 && d.exit.to[0].y === 100; }],
    ['dungeon 89 entry NPC 4001 "Tower of Spell" in map 88 at (358.017,157.847)', () => D.dungeons[89].entry.npcs.some((n) => n.npc === 4001 && n.map === 88 && n.x === 358.017 && n.y === 157.847)],
    ['map 89 string code 3 "10 minutes" -> 600 s; code 310 alert names Filatus', () => D.maps[89].timeLimit.sec === 600 && /Filatus/.test(D.maps[89].messages[310].t)],
    ['map 89 message 10000 has menu [10001]; 10001 carries a 3000 ms gauge', () => D.maps[89].messages[10000].m.join() === '10001' && D.maps[89].messages[10001].fx.some((f) => f.gauge && f.ms === 3000)],
    ['callmonster_89 wave 1 = 20 x monster 5307 starting at (273,209)', () => { const w = D.maps[89].waves.find((x) => x.call === 1); return w.count === 20 && w.monsters[0][0] === 5307 && w.rows[0][1] === 273 && w.rows[0][2] === 209; }],
    ['brick_89 uid 102 = brick 36704 at (246.621,224.945) dir 1 IsCreate 0', () => D.maps[89].bricks.some((b) => b.uid === 102 && b.brick === 36704 && b.x === 246.621 && b.y === 224.945 && b.dir === 1 && b.create === 0)],
    ['brick.csv 30001 = East Gate, MaxHP 500000, shape war_castle_door_01 -> mesh/brick/war_castle_door_01.mesh', () => D.bricks[30001].name === 'East Gate' && D.bricks[30001].hp === 500000 && D.bricks[30001].mesh === 'mesh/brick/war_castle_door_01.mesh'],
    ['warp 1003: Deneb location 1003 (20,357) rect 11x8 -> location 1004 HeiHaff (470,46)', () => { const w = T.warps.find((x) => x.id === 1003); return w.from === 1003 && w.rect.join() === '11,8' && w.to === 1004 && w.fromMap === 3 && w.toMap === 5 && T.locations[1004][1] === 470 && T.locations[1004][2] === 46; }],
    ['teleport 101 unit 1 -> location 103 (Deneb) 5000 dil level 20', () => { const u = T.teleports[101].units[0]; return u.location === 103 && u.map === 3 && u.cost === 5000 && u.level === 20; }],
    ['forbiddenshackles floor 20 clear exp 5333333333; fieldboss 9490 at map 533 (53,57)', () => D.forbiddenShackles[19].floor === 20 && D.forbiddenShackles[19].clearExp === 5333333333 && D.fieldBosses[0].monster === 9490 && D.fieldBosses[0].map === 533 && D.fieldBosses[0].x === 53],
  ];
  let ok = 0;
  console.log('\nspot checks (values read by hand from the raw files):');
  for (const [name, fn] of checks) {
    let r = false, err = '';
    try { r = !!fn(); } catch (e) { err = ` (${e.message})`; }
    if (r) ok++; else problems.hard.push(`spot check failed: ${name}${err}`);
    console.log(`  ${r ? 'OK  ' : 'FAIL'} ${name}${err}`);
  }
  console.log(`  ${ok}/${checks.length} spot checks passed`);
}

// run only when executed directly (the parse* exports can be imported without side effects)
if (process.argv[1] && path.resolve(process.argv[1]) === fileURLToPath(import.meta.url)) main();
