#!/usr/bin/env node
// Dekaron Solo — monster + NPC database builder.
//
//   node tools/build-monsters.mjs [--data <unpacked data root>] [--out <dir>] [--pretty] [--quiet]
//
// Reads the user's own unpacked client (default: ../data/unpacked/data next to the engine) and writes
//   gamedata/monsters.json   every monster index -> stats, AI, attacks, drops, visual (shape + action set)
//   gamedata/npcs.json       every NPC index     -> name, roles, visual, per-map placements
// Every asset path in the output is a data key (lower case, '/' separated, relative to the data root,
// fetch it as /data/<key>) that was verified to exist on disk.  The run doubles as the validation
// script: every source file of each binary format is parsed, exact consumption / invariants are
// asserted and a summary with counts + first failures is printed (exit code 1 on hard failures).
// Format + field documentation: docs/formats/monsters.md
//
// The parse* functions below are pure (ArrayBuffer/Uint8Array/string in, plain objects out, no Node
// APIs) so they can be moved into src/formats/ unchanged if the engine ever needs them at runtime.

import { resolveRef } from './asset-ref-resolve.mjs';
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import { fileURLToPath } from 'node:url';
import { BinReader, parseCSV, toArrayBuffer } from '../src/formats/binreader.js';
import {describeSentryResult} from './lib/siege-sentry-results.mjs';
import {DEAD_ISLAND_IGNITER_SET} from '../src/config/engine-chosen-dead-island.js';
// cross-format fit checks while choosing action tables (builder side only; the parse* exports below stay pure)
import { parseMesh } from '../src/formats/mesh.js';
import { referencedMapFolders } from '../src/world/map-folder-bindings.js';
import { parseSkel, findBone } from '../src/formats/skel.js';
import { parseAnim } from '../src/formats/anim.js';
// native effect-body monsters (empty *_none body drawn only by its authored action effects): see src/game/effect-body.js
import { EFFECT_FILES, monsterActionEffectRows, effectSceneResources, effectMeshUnits, classifyEffectBody } from '../src/game/effect-body.js';

// ------------------------------------------------------------------------------------------------
// text helpers (pure)
// ------------------------------------------------------------------------------------------------
const utf16 = new TextDecoder('utf-16le');
let krDecoder = null;
try { krDecoder = new TextDecoder('euc-kr'); } catch { krDecoder = null; }

/** True ISO-8859-1 decode (byte -> same code point, reversible; unlike TextDecoder('latin1') = cp1252). */
export function latin1(u8) {
  let s = '';
  for (let i = 0; i < u8.length; i += 8192) s += String.fromCharCode.apply(null, u8.subarray(i, i + 8192));
  return s;
}
/** A latin1-decoded string that actually holds EUC-KR/CP949 bytes -> proper Korean text. */
export function kr(s) {
  if (!s || !/[\x80-\xff]/.test(s) || !krDecoder) return s;
  const b = new Uint8Array(s.length);
  for (let i = 0; i < s.length; i++) b[i] = s.charCodeAt(i) & 0xff;
  return krDecoder.decode(b);
}
const u8of = (src) => (src instanceof Uint8Array ? src : new Uint8Array(toArrayBuffer(src)));
const textOf = (src) => (typeof src === 'string' ? src : latin1(u8of(src)));
function cstrAt(u8, off, max) {
  let e = off;
  while (e < off + max && u8[e] !== 0) e++;
  return latin1(u8.subarray(off, e));
}

/** Game path ("Monster\\a\\b.anim") -> data key under a type root ("anim/monster/a/b.anim"). */
export function dataKey(root, gamePath) {
  let n = String(gamePath ?? '').trim().replace(/\\/g, '/').replace(/\/{2,}/g, '/').replace(/^(\.\/)+/, '').replace(/^\/+/, '').toLowerCase();
  if (!n) return null;
  n = n.replace(/^(\.\.\/)+/, '');
  const r = root.toLowerCase();
  return n.startsWith(r + '/') ? n : `${r}/${n}`;
}
const num = (v, d = 0) => { const x = Number(String(v ?? '').trim()); return Number.isFinite(x) ? x : d; };
const round = (x, k = 4) => (Number.isFinite(x) ? Math.round(x * 10 ** k) / 10 ** k : x);
const baseNoExt = (p) => { const s = String(p).replace(/\\/g, '/'); return s.slice(s.lastIndexOf('/') + 1).replace(/\.[^.]*$/, '').toLowerCase(); };

// ------------------------------------------------------------------------------------------------
// ACTION tables: share/action/action/<type>/*.act.dat (compiled) and share/action/<type>/*.csv (source)
// ------------------------------------------------------------------------------------------------
export const ACT_HEADER_BYTES = 264;   // u32 creatureType, u32 index, char skeleton[256]
export const ACT_RECORD_BYTES = 303;
export const ACT_CREATURE_TYPES = { 1: 'MONSTER', 4: 'NPC' };
/** action code (dat) <-> action name (csv). Same ids as docs/formats/modeldef.md ACTION_IDS (all creature kinds);
 *  the ones this builder can verify on monster/NPC twins are listed in monsters.json actionCodesVerified.
 *  51/52 are named from their animation files (*_Appear / *_Disappear), no csv counterpart exists. */
export const ACTION_CODES = {
  0: 'ENTER', 1: 'STAND', 2: 'MOVE', 6: 'ATTACK', 7: 'DEFEAT', 8: 'DEAD', 9: 'LEAVE', 10: 'SKILL', 11: 'REVIVE', 12: 'BLOCKING',
  13: 'BLOCKED', 14: 'GUARDING', 15: 'MOTION', 17: 'OPENMARKET', 18: 'CLOSEMARKET', 21: 'FISHFIGHTING', 22: 'OPENFISHING',
  23: 'CLOSEFISHING', 24: 'OPENBRICK', 25: 'CLOSEBRICK', 26: 'SM_STAND', 27: 'SM_DEAD', 28: 'SM_MOVE', 29: 'SM_REVIVE',
  30: 'ENDSIEGE', 38: 'KNOCKDOWN', 39: 'AWK_STAND', 40: 'AWK_MOVE', 41: 'STUN', 43: 'SLEEP', 44: 'RUSH',
  46: 'EMOTIONSTART', 47: 'EMOTIONKEEP', 48: 'EMOTIONEND', 49: 'TRIGGERCHANGE', 51: 'APPEAR', 52: 'DISAPPEAR', 53: 'SURRENDER',
};
export const ACTION_NAME_TO_CODE = Object.fromEntries(Object.entries(ACTION_CODES).map(([c, n]) => [n, +c]));

/**
 * Parse a compiled action table (.act.dat).
 * Layout: u32 creatureType (1 monster, 4 npc) | u32 index | char skeleton[256] | n x 303-byte records:
 *   +0 u8 style  +1 u32 action  +5 u32 index  +9 char anim[256]  +265 f32 startInter  +269 f32 endInter
 *   +273 f32 timeLength  +277 u8 swing  +278 u8 strike  +279 f32 timing  +283 u8 split  +284 f32 timing2
 *   +288 f32 freeze  +292 u32 effect  +296 u32 cancelTime(ms)  +300 u8 defaultAction  +301 u8 intersect  +302 u8 through
 * (the last three = csv columns Default|DefaultAction, Intersect, Through; kept under their unk300..302 names too)
 */
export function parseActDat(buf) {
  const r = new BinReader(buf);
  const type = r.u32();
  const index = r.u32();
  const skeleton = cstrAt(r.u8, r.pos, 256); r.skip(256);
  const n = Math.floor(r.remaining / ACT_RECORD_BYTES);
  const records = [];
  for (let i = 0; i < n; i++) {
    const style = r.u8r();
    const action = r.u32();
    const idx = r.u32();
    const anim = cstrAt(r.u8, r.pos, 256); r.skip(256);
    const startInter = r.f32(), endInter = r.f32(), timeLength = r.f32();
    const swing = r.u8r(), strike = r.u8r();
    const timing = r.f32();
    const split = r.u8r();
    const timing2 = r.f32();
    const freeze = r.f32(), effect = r.u32(), cancelTime = r.u32();
    const unk300 = r.u8r(), unk301 = r.u8r(), unk302 = r.u8r();
    records.push({ style, action, name: ACTION_CODES[action] ?? `ACT_${action}`, index: idx, anim, startInter, endInter,
      timeLength, swing, strike, timing, split, timing2, freeze, effect, cancelTime, unk300, unk301, unk302,
      defaultAction: unk300, intersect: unk301, through: unk302 });
  }
  return { type, index, skeleton, records, trailingBytes: r.remaining };
}

/**
 * Parse a source action table (.act.csv / .csv under share/action/<type>/).
 * Rows before the header are key/value pairs (Creature, Index, Skeleton). Header row contains "Action";
 * columns: Style,Action,Index,Animation,Start_Inter,End_Inter,TimeLength,Swing,Strike,Timing,Split,Timing2,Freeze
 * [,Effect,CancelTime,Default|DefaultAction,Intersect,Through]. Column 3 is always the animation even when its
 * header cell is blank (some files).
 */
export function parseActCsv(src) {
  const rows = parseCSV(textOf(src));
  const meta = {};
  let hdr = null;
  const records = [];
  for (const row of rows) {
    if (!row || !row.some((c) => String(c).trim())) continue;
    if (!hdr) {
      if (row.some((c) => String(c).trim().toLowerCase() === 'action')) { hdr = row.map((c) => String(c).trim().toLowerCase()); continue; }
      meta[String(row[0]).trim().toLowerCase()] = String(row[1] ?? '').trim();
      continue;
    }
    const get = (names, pos) => {
      for (const nm of names) { const i = hdr.indexOf(nm); if (i >= 0) return row[i]; }
      return pos !== undefined ? row[pos] : undefined;
    };
    const actionName = String(get(['action'], 1) ?? '').trim().toUpperCase();
    if (!actionName) continue;
    records.push({
      style: num(get(['style'], 0)), name: actionName, action: ACTION_NAME_TO_CODE[actionName] ?? -1,
      index: num(get(['index'], 2)), anim: String(row[3] ?? '').trim(),
      startInter: num(get(['start_inter'], 4)), endInter: num(get(['end_inter'], 5)), timeLength: num(get(['timelength'], 6)),
      swing: num(get(['swing'], 7)), strike: num(get(['strike'], 8)), timing: num(get(['timing'], 9)), split: num(get(['split'], 10)),
      timing2: num(get(['timing2'], 11)), freeze: num(get(['freeze'], 12)), effect: num(get(['effect'])), cancelTime: num(get(['canceltime'])),
      unk300: num(get(['default', 'defaultaction'])), unk301: num(get(['intersect'])), unk302: num(get(['through'])),
    });
  }
  const idx = parseInt(meta.index, 10);
  return { type: (meta.creature || '').toUpperCase(), index: Number.isFinite(idx) ? idx : null, skeleton: meta.skeleton || '', records };
}

// ------------------------------------------------------------------------------------------------
// share/creature/monster.dat — compiled client monster table (fixed 2643-byte records)
// ------------------------------------------------------------------------------------------------
export const MONSTER_DAT_RECORD = 2643;
export const MONSTER_DAT_FIELDS = [ // [offset, size, name]  (everything else is zero in the corpus except noted unk)
  [0, 2, 'index'], [2, 128, 'nameKey'], [130, 4, 'rank'], [134, 4, 'material'], [138, 2, 'level'], [140, 4, 'maxHP'], [144, 4, 'unk144'],
  [198, 1, 'blood'], [199, 1, 'cutting'], [200, 1, 'deadEffect'], [201, 1, 'damageType'], [202, 1, 'target'],
  [203, 4, 'walkSpeed'], [207, 4, 'runSpeed'], [211, 4, 'width'], [215, 272, 'shape'], [487, 4, 'exp'], [491, 4, 'moneyMin'],
  [495, 4, 'moneyMax'], [499, 4, 'moneyRate'], [503, 4, 'aiType'], [507, 2, 'aiKey'], [509, 2, 'unk509'], [2587, 4, 'unk2587'],
  [2604, 1, 'isBlock'], [2607, 4, 'unk2607'], [2623, 2, 'unk2623'], [2625, 1, 'unk2625'],
];
// share/creature/monster64.dat - newer re-save of the same table: 4323-byte records = the 2643-byte layout with 1680
// zero bytes inserted between unk509 (ends 511) and unk2587. Fields < 2587 keep their offset, fields >= 2587 move +1680.
// Evidence (bench/DATA-FORMAT-CENSUS.md): 4575 records each, same index order, 4565/4575 byte-identical under this
// mapping, the 10 others differ only at 108/420 (nameKey / shape garbage tails, not decoded fields).
export const MONSTER64_DAT_RECORD = 4323;
export const MONSTER64_TAIL_SHIFT = MONSTER64_DAT_RECORD - MONSTER_DAT_RECORD; // 1680
/** Detect the monster table layout by record stride; the 2nd record's nameKey ("creature#") pins it when both divide. */
export function detectMonsterDatLayout(u8) {
  const key = [0x63, 0, 0x72, 0, 0x65, 0, 0x61, 0]; // "crea" utf-16le
  const at = (o) => key.every((b, i) => u8[o + i] === b);
  const fits = [MONSTER_DAT_RECORD, MONSTER64_DAT_RECORD].filter((r) => u8.length && u8.length % r === 0);
  const pinned = fits.filter((r) => u8.length <= r || at(r + 2));
  const rec = (pinned.length === 1 ? pinned : fits)[0];
  if (!rec) throw new Error(`monster.dat: size ${u8.length} is neither a multiple of ${MONSTER_DAT_RECORD} nor ${MONSTER64_DAT_RECORD}`);
  return { record: rec, shift: rec === MONSTER64_DAT_RECORD ? MONSTER64_TAIL_SHIFT : 0, layout: rec === MONSTER64_DAT_RECORD ? 'monster64' : 'monster' };
}
export function parseMonsterDat(buf) {
  const ab0 = toArrayBuffer(buf);
  const { record, shift } = detectMonsterDatLayout(new Uint8Array(ab0));
  let ab = ab0;
  if (shift) { // remap to the classic 2643-byte layout, keeping the decoder below single-sourced
    const src = new Uint8Array(ab0), n = src.length / record, dst = new Uint8Array(n * MONSTER_DAT_RECORD);
    for (let i = 0; i < n; i++) {
      const a = i * MONSTER_DAT_RECORD, b = i * record;
      dst.set(src.subarray(b, b + 2587), a);
      dst.set(src.subarray(b + 2587 + shift, b + record), a + 2587);
    }
    ab = dst.buffer;
  }
  const dv = new DataView(ab), u8 = new Uint8Array(ab);
  const REC = MONSTER_DAT_RECORD;
  if (ab.byteLength % REC !== 0) throw new Error(`monster.dat: size ${ab.byteLength} not a multiple of ${REC}`);
  const covered = new Uint8Array(REC);
  for (const [o, s] of MONSTER_DAT_FIELDS) covered.fill(1, o, o + s);
  const out = [];
  for (let o = 0; o < ab.byteLength; o += REC) {
    const nk = utf16.decode(u8.subarray(o + 2, o + 130));
    let stray = 0;
    const shape = cstrAt(u8, o + 215, 272);
    for (let k = 0; k < REC; k++) if (!covered[k] && u8[o + k]) stray++;
    // bytes after the shape terminator inside the 272-byte text field (garbage in 2 records)
    let shapeTail = 0;
    for (let k = o + 215 + shape.length + 1; k < o + 487; k++) if (u8[k]) shapeTail++;
    out.push({
      index: dv.getUint16(o, true), nameKey: nk.slice(0, nk.indexOf('\0') < 0 ? nk.length : nk.indexOf('\0')),
      rank: dv.getUint32(o + 130, true), material: dv.getUint32(o + 134, true), level: dv.getUint16(o + 138, true),
      maxHP: dv.getUint32(o + 140, true), unk144: dv.getUint32(o + 144, true),
      blood: u8[o + 198], cutting: u8[o + 199], deadEffect: u8[o + 200], damageType: u8[o + 201], target: u8[o + 202],
      walkSpeed: dv.getFloat32(o + 203, true), runSpeed: dv.getFloat32(o + 207, true), width: dv.getFloat32(o + 211, true),
      shape, exp: dv.getUint32(o + 487, true), moneyMin: dv.getUint32(o + 491, true), moneyMax: dv.getUint32(o + 495, true),
      moneyRate: dv.getUint32(o + 499, true), aiType: dv.getUint32(o + 503, true), aiKey: dv.getUint16(o + 507, true),
      unk509: dv.getUint16(o + 509, true), unk2587: dv.getUint32(o + 2587, true), isBlock: u8[o + 2604],
      unk2607: dv.getUint32(o + 2607, true), unk2623: dv.getUint16(o + 2623, true), unk2625: u8[o + 2625],
      strayBytes: stray, shapeTailBytes: shapeTail,
    });
  }
  return out;
}

// ------------------------------------------------------------------------------------------------
// script/lines_eu — localisation database (UTF-16LE)
//   u32 nTxt  { u32 len, wchar name[len], u32 n, n x (i32,i32) }        txt string files
//   u32 nCsv  { u32 len, wchar name[len], u32 n, n x (i32 col,i32 -1) } localised csv tables/columns
//   u32 nStr  { u32 id, u32 len, wchar text[len] }                       the strings (ids 1..nStr ascending)
//   u32 nKeyT { u32 len, wchar key[len] ("00|file.txt#id|n"), u32 id }
//   u32 nKeyC { u32 len, wchar key[len] ("creature#monster.csv#1|144"), u32 id }   -> monster.dat nameKey
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
// .tpack (text).  texpath "<folder under texture/>", N "diffuse of slot N", sN specular, bN bump, gN glow.
// ------------------------------------------------------------------------------------------------
export function parseTpackText(src) {
  const out = { texpath: null, diffuse: {}, specular: {}, bump: {}, glow: {}, unknown: [] };
  let disabledTexpath = null;
  for (const raw of textOf(src).split(/\r\n|\n|\r/)) {
    const s = raw.trim();
    if (!s) continue;
    const m = /^(\S+?)(?:\s+|(?="))(.*)$/.exec(s);
    if (!m) { out.unknown.push(s); continue; }
    const key = m[1].toLowerCase();
    let v = (m[2] || '').trim();
    if (v.startsWith('"')) { const e = v.indexOf('"', 1); v = e < 0 ? v.slice(1) : v.slice(1, e); } else v = v.split(/\s+/)[0] || '';
    v = v.replace(/^[:\s"]+/, '').replace(/["\s]+$/, '');
    if (key.startsWith('//') || key.startsWith('#') || key.startsWith(';')) continue;
    let mm;
    if (key === 'texpath') { if (out.texpath === null) out.texpath = v; }
    else if (key === '_texpath') disabledTexpath = v;
    else if ((mm = /^(\d+)$/.exec(key))) { if (v && !(mm[1] in out.diffuse)) out.diffuse[+mm[1]] = v; }
    else if ((mm = /^s(\d*)$/.exec(key)) || (mm = /^(\d+)s$/.exec(key))) { const k = mm[1] === '' ? 0 : +mm[1]; if (v && !(k in out.specular)) out.specular[k] = v; }
    else if ((mm = /^b(\d+)$/.exec(key))) { if (v && !(mm[1] in out.bump)) out.bump[+mm[1]] = v; }
    else if ((mm = /^g(\d+)$/.exec(key))) { if (v && !(mm[1] in out.glow)) out.glow[+mm[1]] = v; }
    else out.unknown.push(s);
  }
  if (out.texpath === null && disabledTexpath !== null) out.texpath = disabledTexpath;
  return out;
}

// ------------------------------------------------------------------------------------------------
// spawn / placement tables (text)
// ------------------------------------------------------------------------------------------------
/** MON_*.csv: one spawn per line "monsterIndex,regenSeconds,cellX,cellY" (no header). */
export function parseSpawnCsv(src) {
  const rows = []; let skipped = 0;
  for (const line of textOf(src).split(/\r?\n/)) {
    const p = line.split(',').map((s) => s.trim());
    if (p.length === 4 && p.every((x) => /^-?\d+(\.\d+)?$/.test(x))) rows.push([+p[0], +p[1], +p[2], +p[3]]);
    else if (line.trim()) skipped++;
  }
  return { rows, skipped };
}
/**
 * [group]callmonster_*.csv (scripted spawns). A "MapIndex,<n>" row (4 files have no label: "w,564" / ",707" -> the first
 * number above the header), then a header row. Blocks are located by their header cell, so they need not start at column 0:
 *   CallIndex,MonsterIndex,X,Y,Cell,Count          -> rows            [callIndex, monster, x, y, cell, count]
 *   RandCallIndex,MonsterIndex,Count,PosIndex      -> randomCalls     [randCallIndex, monster, count, posIndex]
 *   RandPosIndex,X,Y,Cell                          -> randomPositions [randPosIndex, x, y, cell]
 * (the random blocks exist only in callmonster_707_braiken_broken.csv, "Defense Battle": call group k spawns count x
 * monster at a random point of position list posIndex; same reading as src/formats/spawn.js parseCallMonsterCSV).
 * The file's own map index is copy-pasted in ~20 files: bind files to maps through maplist CallMonsterPath instead.
 */
export function parseCallMonsterCsv(src) {
  const rows = parseCSV(textOf(src)).map((r) => (r || []).map((c) => String(c ?? '').trim()));
  const isNum = (s) => /^-?\d+(\.\d+)?$/.test(s);
  let map = null, hi = -1;
  for (let i = 0; i < rows.length; i++) {
    const lc = rows[i].map((c) => c.toLowerCase());
    if (lc[0] === 'mapindex') map = num(rows[i][1], null);
    if (lc.includes('callindex') || lc.includes('randcallindex')) { hi = i; break; }
  }
  const out = [], randomCalls = [], randomPositions = [];
  if (hi < 0) return { map, rows: out, randomCalls, randomPositions };
  if (map === null) for (let i = 0; i < hi && map === null; i++) { const v = rows[i].find(isNum); if (v !== undefined) map = +v; }
  const head = rows[hi].map((c) => c.toLowerCase());
  const cCall = head.indexOf('callindex'), cRand = head.indexOf('randcallindex'), cPos = head.indexOf('randposindex');
  const block = (r, c, n) => { const v = []; for (let k = 0; k < n; k++) v.push(r[c + k] ?? ''); return v; };
  for (let i = hi + 1; i < rows.length; i++) {
    const r = rows[i];
    if (cCall >= 0) {
      const v = block(r, cCall, 6);
      if (v.slice(0, 4).every(isNum) && +v[1] > 0) out.push(v.map((x) => num(x)));
    }
    if (cRand >= 0) {
      const v = block(r, cRand, 4);
      if (isNum(v[0]) && isNum(v[1]) && +v[1] > 0) randomCalls.push(v.map((x) => num(x)));
    }
    if (cPos >= 0) {
      const v = block(r, cPos, 4);
      if (isNum(v[0]) && isNum(v[1]) && isNum(v[2])) randomPositions.push(v.map((x) => num(x)));
    }
  }
  return { map, rows: out, randomCalls, randomPositions };
}

/** NPC_*.csv: transposed table, one row per field (NpcIndex, Direction, Location_X, Location_Y, Description,
 *  Warp_X, Warp_Y, IsEvent), one column per placed NPC. Row 0 holds the NPC indices whatever its label says
 *  (npc_00_north_ares.csv labels it with an edit date, "2005-10-21 16:13"). */
export function parseNpcPlacementCsv(src) {
  const rows = parseCSV(textOf(src)).filter((r) => r && r.some((c) => String(c).trim() !== ''));
  const by = {};
  for (const r of rows.slice(1)) if (r.length > 1) by[String(r[0]).trim().toLowerCase()] = r.slice(1);
  const idx = rows.length ? rows[0].slice(1) : [];
  const out = [];
  for (let i = 0; i < idx.length; i++) {
    const s = String(idx[i] ?? '').trim();
    if (!/^\d+$/.test(s)) continue;
    const g = (k) => (by[k] ? String(by[k][i] ?? '').trim() : '');
    out.push({ npc: +s, dir: num(g('direction')), x: num(g('location_x')), y: num(g('location_y')), desc: g('description'),
      warpX: g('warp_x') === '' ? null : num(g('warp_x')), warpY: g('warp_y') === '' ? null : num(g('warp_y')), isEvent: num(g('isevent')) });
  }
  return { rows: out, fields: Object.keys(by) };
}

// ------------------------------------------------------------------------------------------------
// property/effect/effectscene.snd.txt + effectdata.snd.txt (sound effect scenes, text)
// ------------------------------------------------------------------------------------------------
export function parseEffectScenes(src) {
  const scenes = new Map();
  const text = textOf(src);
  const re = /<effect>([\s\S]*?)<\/effect>/g;
  let m;
  while ((m = re.exec(text))) {
    const body = m[1];
    const id = /^\s*id\s+(\d+)/m.exec(body);
    const name = /^\s*name\s+(\S+)/m.exec(body);
    if (!name) continue;
    const res = [];
    const lr = /^\s*res\s+(\d+)\s+(\S+)/gm;
    let q;
    while ((q = lr.exec(body))) res.push([+q[1], q[2]]);
    const key = name[1].toLowerCase();
    if (!scenes.has(key)) scenes.set(key, { id: id ? +id[1] : null, name: name[1], res });
  }
  return scenes;
}
export function parseEffectData(src) {
  const units = new Map();
  const re = /<effectdata>([\s\S]*?)<\/effectdata>/g;
  let m;
  const text = textOf(src);
  while ((m = re.exec(text))) {
    const body = m[1];
    const name = /^\s*name\s+(\S+)/m.exec(body);
    if (!name) continue;
    const sounds = [];
    const lr = /^\s*sound\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)/gm;
    let q;
    while ((q = lr.exec(body))) sounds.push({ file: q[1], unk: num(q[2]), volume: num(q[3]), range: num(q[4]) });
    const key = name[1].toLowerCase();
    if (!units.has(key)) units.set(key, { name: name[1], type: (/^\s*unittype\s+(\S+)/m.exec(body) || [])[1] || '', sounds });
  }
  return units;
}

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
// Sounds: gamedata/sound.json (docs/formats/sound.md: monsterSfxIndex / actionEffectSfx,
// resolved through soundscript.csv + modeleffect.csv) is authoritative. --sfx additionally embeds this builder's
// name-convention guess (Basic_Mon_<shape> scenes + scenes named after anim files) as shapes[..].sfx / actionSets[..].sfx.
const WITH_SFX = argv.includes('--sfx');
const QUIET = argv.includes('--quiet');
const log = (...a) => { if (!QUIET) console.log(...a); };

const problems = { hard: [], soft: [] };
const hard = (msg) => { problems.hard.push(msg); };
const soft = (msg) => { problems.soft.push(msg); };

function readRel(rel) { return fs.readFileSync(path.join(DATA, rel)); }
function readText(rel) { return latin1(readRel(rel)); }
function existsRel(rel) { try { return fs.statSync(path.join(DATA, rel)).isFile(); } catch { return false; } }
// modeleffect.csv monster action rows + effect scene resources + effectdata mesh units, read once on first use
let EFFECT_BODY_INDEX = null;
function effectBodyIndex() {
  if (EFFECT_BODY_INDEX) return EFFECT_BODY_INDEX;
  const scenes = new Map(), units = new Map();
  for (const f of EFFECT_FILES) {
    if (existsRel(`property/effect/effectscene.${f}.txt`)) effectSceneResources(readText(`property/effect/effectscene.${f}.txt`), f, scenes);
    if (existsRel(`property/effect/effectdata.${f}.txt`)) effectMeshUnits(readText(`property/effect/effectdata.${f}.txt`), f, units);
  }
  const rows = existsRel('script/effect/modeleffect.csv') ? monsterActionEffectRows(parseCSV(readText('script/effect/modeleffect.csv'))) : new Map();
  return (EFFECT_BODY_INDEX = { rows, scenes, units });
}

// ---- file index (lower-case data keys) -------------------------------------------------------
const FILES = new Set();
const BY_BASENAME = new Map(); // basename -> [keys]
const BY_DIR = new Map();      // directory key -> [file keys]
function indexDir(sub) {
  const root = path.join(DATA, sub);
  if (!fs.existsSync(root)) { hard(`missing data folder ${sub}`); return; }
  for (const d of fs.readdirSync(root, { recursive: true, withFileTypes: true })) {
    if (!d.isFile()) continue;
    const full = path.join(d.parentPath ?? d.path, d.name);
    const key = path.relative(DATA, full).replace(/\\/g, '/').toLowerCase();
    FILES.add(key);
    const b = key.slice(key.lastIndexOf('/') + 1);
    if (!BY_BASENAME.has(b)) BY_BASENAME.set(b, []);
    BY_BASENAME.get(b).push(key);
    const dir = key.slice(0, key.lastIndexOf('/') + 1);
    if (!BY_DIR.has(dir)) BY_DIR.set(dir, []);
    BY_DIR.get(dir).push(key);
  }
}
const has = (k) => !!k && FILES.has(k);

// ---- generic csv table ------------------------------------------------------------------------
function loadTable(rel, { indexCol = 0 } = {}) {
  const rows = parseCSV(readText(rel));
  const header = (rows[0] || []).map((h) => String(h).trim());
  const byIndex = new Map();
  let dup = 0;
  for (let i = 1; i < rows.length; i++) {
    const r = rows[i];
    if (!r || r.length < 2) continue;
    const k = String(r[indexCol] ?? '').trim();
    if (!/^-?\d+$/.test(k)) continue;
    if (byIndex.has(+k)) { dup++; continue; }
    byIndex.set(+k, r);
  }
  const col = (name) => header.findIndex((h) => h.toLowerCase() === name.toLowerCase());
  return { header, rows, byIndex, col, dup };
}

// ================================================================================================
function main() {
  const t0 = Date.now();
  if (!fs.existsSync(DATA)) { console.error(`data root not found: ${DATA}`); process.exit(2); }
  log(`data root: ${DATA}`);
  for (const sub of ['mesh', 'skel', 'anim', 'texture', 'texturepack', 'sound', 'share/map']) indexDir(sub);
  log(`indexed ${FILES.size} files`);

  // ---------------------------------------------------------------- localisation
  let lines = null;
  if (existsRel('script/lines_eu')) {
    lines = parseLinesEu(readRel('script/lines_eu'), { keyFilter: (k) => k.startsWith('creature#') });
    if (lines.trailingBytes !== 0) hard(`lines_eu: ${lines.trailingBytes} trailing bytes`);
  } else soft('script/lines_eu missing: monster names fall back to monster.csv');
  const locName = (key) => { if (!lines || !key) return null; const id = lines.csvKeys.get(key); return id ? lines.strings.get(id) ?? null : null; };

  // ---------------------------------------------------------------- action tables
  const actions = buildActionIndex();

  // ---------------------------------------------------------------- monsters
  const monsters = buildMonsters({ locName, actions });
  // ---------------------------------------------------------------- npcs
  const npcs = buildNpcs({ actions });

  // ---------------------------------------------------------------- write
  fs.mkdirSync(OUTDIR, { recursive: true });
  const write = (name, obj) => {
    const p = path.join(OUTDIR, name);
    const s = PRETTY ? JSON.stringify(obj, null, 1) : JSON.stringify(obj);
    fs.writeFileSync(p, s);
    log(`wrote ${path.relative(ENGINE, p)} (${(s.length / 1024).toFixed(0)} KiB)`);
  };
  // ---------------------------------------------------------------- every emitted asset key: exists + right file type
  const keys = new Set();
  const collect = (db) => {
    for (const s of Object.values(db.shapes)) {
      if (s.mesh) keys.add(s.mesh);
      if (s.tpack) keys.add(s.tpack);
      for (const arr of Object.values(s.textures || {})) for (const t of arr) if (t) keys.add(t);
      for (const arr of Object.values(s.sfx || {})) for (const t of arr) keys.add(t);
    }
    for (const a of Object.values(db.actionSets)) {
      if (a.skel) keys.add(a.skel);
      for (const c of a.clips) keys.add(c[0]);
      for (const arr of Object.values(a.sfx || {})) for (const t of arr) keys.add(t);
    }
  };
  collect(monsters); collect(npcs);
  const magic = { mesh: new Map(), skel: new Map(), anim: new Map() };
  const EXPECT = { mesh: new Set([0x20030820, 0x20031117, 0x20060303, 0x20191130]) };
  const hdr = Buffer.alloc(4);
  let checked = 0;
  for (const k of keys) {
    if (!has(k)) { hard(`emitted key does not exist: ${k}`); continue; }
    const ext = k.slice(k.lastIndexOf('.') + 1);
    if (!(ext in magic)) continue;
    const fd = fs.openSync(path.join(DATA, k), 'r');
    const n = fs.readSync(fd, hdr, 0, 4, 0); fs.closeSync(fd);
    const v = n === 4 ? hdr.readUInt32LE(0) : -1;
    magic[ext].set(v, (magic[ext].get(v) || 0) + 1);
    if (ext === 'mesh' && !EXPECT.mesh.has(v)) soft(`mesh with unexpected version 0x${v.toString(16)}: ${k}`);
    checked++;
  }
  const fmtMagic = (m) => [...m.entries()].sort((a, b) => b[1] - a[1]).map(([v, c]) => `0x${(v >>> 0).toString(16)} x${c}`).join(', ');
  log(`emitted asset keys: ${keys.size} (all exist); headers checked ${checked}: mesh [${fmtMagic(magic.mesh)}] skel [${fmtMagic(magic.skel)}] anim [${fmtMagic(magic.anim)}]`);
  monsters.report.assetHeaders = { mesh: Object.fromEntries([...magic.mesh].map(([v, c]) => [`0x${(v >>> 0).toString(16)}`, c])),
    skel: Object.fromEntries([...magic.skel].map(([v, c]) => [`0x${(v >>> 0).toString(16)}`, c])),
    anim: Object.fromEntries([...magic.anim].map(([v, c]) => [`0x${(v >>> 0).toString(16)}`, c])) };
  if (monsters.report.coverage.roleAwarePercent < 95) hard(`role-aware coverage ${monsters.report.coverage.roleAwarePercent}% < 95%`);
  log(`action names verified against compiled twins: ${Object.keys(actionsVerified(monsters)).join(' ') || '-'}`);

  write('monsters.json', monsters);
  write('npcs.json', npcs);

  // ---------------------------------------------------------------- summary
  log('');
  log(`soft issues: ${problems.soft.length}`);
  for (const s of problems.soft.slice(0, 25)) log(`  - ${s}`);
  if (problems.soft.length > 25) log(`  ... ${problems.soft.length - 25} more (see report sections in the json)`);
  log(`HARD failures: ${problems.hard.length}`);
  for (const s of problems.hard.slice(0, 40)) log(`  ! ${s}`);
  log(`done in ${((Date.now() - t0) / 1000).toFixed(1)} s`);
  process.exitCode = problems.hard.length ? 1 : 0;
}

const actionsVerified = (db) => Object.fromEntries((db.actionCodesVerified || []).map((n) => [n, true]));

// ================================================================================================
// action tables: parse ALL compiled + source files, index by creature index
// ================================================================================================
function buildActionIndex() {
  const out = { MONSTER: { dat: new Map(), csv: new Map() }, NPC: { dat: new Map(), csv: new Map() }, SENTRY: { dat: new Map(), csv: new Map() }, stats: {}, bySkelBase: new Map(), listed: new Set() };
  // share/action/list.csv = the source files the compiler consumed
  if (existsRel('share/action/list.csv')) {
    for (const l of readText('share/action/list.csv').split(/\r?\n/)) {
      const s = l.trim().toLowerCase().replace(/\\/g, '/');
      if (s) out.listed.add(s.replace(/\.csv$/, ''));
    }
  }
  const codeVotes = new Map(); // csv name -> Map(code -> n)
  for (const [kind, sub] of [['MONSTER', 'monster'], ['NPC', 'npc'], ['SENTRY','sentry']]) {
    const st = { datFiles: 0, datRecords: 0, datBad: 0, datTrailing: 0, datUnknownCodes: new Map(), csvFiles: 0, csvRecords: 0, csvNoIndex: 0,
      csvUnknownNames: new Map(), pairs: 0, pairsAgree: 0, fieldAgree: {}, nonFinite: 0 };
    out.stats[kind] = st;
    const datDir = path.join(DATA, 'share/action/action', sub);
    const datStems = new Map();
    for (const f of fs.existsSync(datDir) ? fs.readdirSync(datDir) : []) {
      if (!f.toLowerCase().endsWith('.dat')) continue;
      const rel = `share/action/action/${sub}/${f}`;
      let a;
      try { a = parseActDat(readRel(rel)); } catch (e) { st.datBad++; hard(`${rel}: ${e.message}`); continue; }
      st.datFiles++; st.datRecords += a.records.length;
      if (a.trailingBytes) { st.datTrailing++; hard(`${rel}: ${a.trailingBytes} trailing bytes (not 264 + 303n)`); }
      const want = kind === 'MONSTER' ? 1 : kind === 'SENTRY' ? 6 : 4;
      if (a.type !== want) hard(`${rel}: creature type ${a.type} (expected ${want})`);
      for (const r of a.records) {
        if (!(r.action in ACTION_CODES)) st.datUnknownCodes.set(r.action, (st.datUnknownCodes.get(r.action) || 0) + 1);
        for (const k of ['startInter', 'endInter', 'timeLength', 'timing', 'timing2', 'freeze']) if (!Number.isFinite(r[k])) st.nonFinite++;
      }
      const e = { src: rel, stem: f.toLowerCase().replace(/\.dat$/, ''), kind: 'dat', ...a };
      if (!out[kind].dat.has(a.index)) out[kind].dat.set(a.index, []);
      out[kind].dat.get(a.index).push(e);
      datStems.set(e.stem, e);
    }
    const csvDir = path.join(DATA, 'share/action', sub);
    for (const f of fs.existsSync(csvDir) ? fs.readdirSync(csvDir) : []) {
      if (!f.toLowerCase().endsWith('.csv')) continue;
      const rel = `share/action/${sub}/${f}`;
      const a = parseActCsv(readRel(rel));
      st.csvFiles++; st.csvRecords += a.records.length;
      for (const r of a.records) if (r.action < 0) st.csvUnknownNames.set(r.name, (st.csvUnknownNames.get(r.name) || 0) + 1);
      if (a.index === null) { st.csvNoIndex++; soft(`${rel}: no Index row`); continue; }
      const e = { src: rel, stem: f.toLowerCase().replace(/\.csv$/, ''), kind: 'csv', ...a };
      if (!out[kind].csv.has(a.index)) out[kind].csv.set(a.index, []);
      out[kind].csv.get(a.index).push(e);
      // compare with the compiled twin (same file stem)
      const twin = datStems.get(e.stem);
      if (twin) {
        st.pairs++;
        const dm = new Map(twin.records.map((r) => [`${r.action}:${r.index}`, r]));
        let same = twin.skeleton.toLowerCase() === a.skeleton.toLowerCase() && twin.records.length === a.records.length;
        for (const r of a.records) {
          // name -> code votes: the twin record with the same (index, anim) — only when that match is unique
          const hits = r.anim ? twin.records.filter((d) => d.index === r.index && d.anim.toLowerCase() === r.anim.toLowerCase()) : [];
          if (hits.length === 1) {
            if (!codeVotes.has(r.name)) codeVotes.set(r.name, new Map());
            const v = codeVotes.get(r.name); v.set(hits[0].action, (v.get(hits[0].action) || 0) + 1);
          }
          const d = dm.get(`${r.action}:${r.index}`);
          if (!d || d.anim.toLowerCase() !== r.anim.toLowerCase()) { same = false; continue; }
          for (const k of ['startInter', 'endInter', 'timeLength', 'swing', 'strike', 'timing', 'split', 'timing2', 'freeze', 'effect', 'cancelTime', 'unk300', 'unk301', 'unk302']) {
            const fa = st.fieldAgree[k] || (st.fieldAgree[k] = [0, 0]);
            fa[0]++; if (Math.abs(d[k] - r[k]) < 1e-3) fa[1]++;
          }
        }
        if (same) st.pairsAgree++;
      }
    }
    // skeleton basename index (used to borrow action sets for shapes without their own table)
    for (const map of [out[kind].dat, out[kind].csv]) {
      for (const list of map.values()) for (const e of list) {
        const b = baseNoExt(e.skeleton);
        if (!b) continue;
        if (!out.bySkelBase.has(b)) out.bySkelBase.set(b, []);
        out.bySkelBase.get(b).push(e);
      }
    }
    log(`${kind} action tables: ${st.datFiles} .dat (${st.datRecords} rec, ${out[kind].dat.size} indices), ${st.csvFiles} .csv (${st.csvRecords} rec, ${out[kind].csv.size} indices); ` +
      `twins ${st.pairs}, identical ${st.pairsAgree}`);
  }
  // verify the code table
  const verified = {};
  for (const [name, votes] of codeVotes) {
    const best = [...votes.entries()].sort((a, b) => b[1] - a[1]);
    const exp = ACTION_NAME_TO_CODE[name];
    if (best[0][0] === exp) verified[name] = { code: exp, votes: best[0][1], runnerUp: best[1] ? best[1][1] : 0 };
    else if (exp === undefined) soft(`action name ${name} not in ACTION_CODES (best code ${best[0][0]} x${best[0][1]})`);
    else soft(`action ${name}: table says ${exp} but twins vote ${best[0][0]} x${best[0][1]}`);
  }
  out.verifiedCodes = verified;
  return out;
}

// ------------------------------------------------------------------------------------------------
// Action set construction (shared by monsters and NPCs)
// ------------------------------------------------------------------------------------------------
/** Canonical engine states -> [actionName, preferred index] fallbacks, first existing wins. */
const STATE_RULES = {
  idle: [['STAND', 0], ['STAND', 1], ['SM_STAND', 0], ['SM_STAND', 1]],
  idleCombat: [['STAND', 1], ['STAND', 0], ['SM_STAND', 1]],
  walk: [['MOVE', 0], ['SM_MOVE', 0], ['MOVE', 1]],
  run: [['MOVE', 1], ['SM_MOVE', 1], ['MOVE', 0]],
  die: [['DEAD', 0], ['SM_DEAD', 0]],
  block: [['BLOCKING', 0]],
  blocked: [['BLOCKED', 0]],
  revive: [['REVIVE', 0], ['SM_REVIVE', 0]],
  appear: [['ENTER', 0], ['APPEAR', 0]],
  disappear: [['LEAVE', 0], ['DISAPPEAR', 0]],
};
const STATE_LISTS = { attack: 'ATTACK', hit: 'DEFEAT', guard: 'GUARDING' };

/**
 * Resolve a game path under a type root to an existing data key: exact path first, then the unique file with
 * the same basename under that root (a handful of tables omit the sub-folder, e.g. "npc_human_size.skel").
 * @returns {{key:string|null, how:'exact'|'basename'|null, want:string|null}}
 */
function resolveKey(root, gamePath) {
  const want = dataKey(root, gamePath);
  if (!want) return { key: null, how: null, want: null };
  if (has(want)) return { key: want, how: 'exact', want };
  const b = want.slice(want.lastIndexOf('/') + 1);
  const alts = (BY_BASENAME.get(b) || []).filter((k) => k.startsWith(root + '/'));
  if (alts.length >= 1) return { key: alts[0], how: 'basename', want };
  return { key: null, how: null, want };
}

// ------------------------------------------------------------------------------------------------
// Cross-format fit: does a skeleton drive a mesh (mesh bone palette names found in the skeleton, mesh.js/skel.js
// name rules) and do a table's animations drive the skeleton (anim tracks bind by name, anim.js rules)?
// The client pairs the shape's mesh with the action table's skeleton blindly; ~100 tables name a skeleton that
// does not fit the mesh (or their own clips), so the choice of table / skeleton is checked here.
// ------------------------------------------------------------------------------------------------
const FIT = { meshPal: new Map(), skel: new Map(), animTracks: new Map(), animDur: new Map(), cov: new Map(), bind: new Map() };
function meshPalette(meshKey) {
  if (!FIT.meshPal.has(meshKey)) {
    let pal = null;
    try { const m = parseMesh(readRel(meshKey)); pal = [...new Set(m.meshes.flatMap((x) => x.skin?.bonePalette || x.bonePalette || []))]; } catch { pal = null; }
    FIT.meshPal.set(meshKey, pal);
  }
  return FIT.meshPal.get(meshKey);
}
function skelObj(skelKey) {
  if (!FIT.skel.has(skelKey)) { let s = null; try { s = parseSkel(readRel(skelKey), { computeMatrices: false }); } catch { s = null; } FIT.skel.set(skelKey, s); }
  return FIT.skel.get(skelKey);
}
function animInfo(animKey) {
  if (!FIT.animTracks.has(animKey)) {
    let names = null, dur = null;
    try { const a = parseAnim(readRel(animKey)); names = a.tracks.map((t) => t.name); dur = a.estDurationSec; } catch { names = null; }
    FIT.animTracks.set(animKey, names); FIT.animDur.set(animKey, dur);
  }
  return FIT.animTracks.get(animKey);
}
/** a mesh skinned to more than one bone (a skeleton mismatch then tears or freezes parts of it). */
function isDeformable(meshKey) { const p = meshKey ? meshPalette(meshKey) : null; return !!p && p.length > 1; }
/** fraction of the mesh's skin palette bones that exist in the skeleton (1 = fits; mesh without palette = 1). */
function paletteCoverage(meshKey, skelKey) {
  const k = `${meshKey}|${skelKey}`;
  if (!FIT.cov.has(k)) {
    const pal = meshKey ? meshPalette(meshKey) : null;
    const sk = skelKey ? skelObj(skelKey) : null;
    FIT.cov.set(k, !pal || !pal.length ? 1 : !sk ? 0 : pal.filter((b) => findBone(sk, b) >= 0).length / pal.length);
  }
  return FIT.cov.get(k);
}
/** Max helper bones that shipped skeletons prune (anim.md): *Nub, del_*, IK chains, weapon/attach dummies. */
export const HELPER_TRACK = /nub$|^del_|ik ?chain|dummy|^att_equ/i;
/**
 * How well an animation drives a skeleton, 0..1 (>= FIT_MIN_BIND = the clip animates it):
 *   max( fraction of the anim's non-helper tracks that bind to a skeleton bone,
 *        fraction of the skeleton's non-helper bones that get a track — counted only when >= 0.9 and >= 3 bones bind )
 * The second term accepts clips authored for a SUPERSET rig (9082 Death Avoid: vinaelle_faray clips carry 73 tracks,
 * all 31 bones of vinaelle_death_basic.skel are driven -> renders correctly), while a foreign clip that merely shares
 * "Bip01" with a 2-bone prop skeleton (ghostman_knight_die on deadman_chest.skel) stays unbound.
 */
function animBind(animKey, skelKey) {
  const k = `${animKey}|${skelKey}`;
  if (!FIT.bind.has(k)) {
    const all = animInfo(animKey);
    const names = all && all.filter((n) => !HELPER_TRACK.test(n));
    const sk = skelKey ? skelObj(skelKey) : null;
    let v;
    if (!names) v = 0;
    else if (!names.length) v = 1;
    else if (!sk) v = 0;
    else {
      const bound = names.filter((n) => findBone(sk, n) >= 0).length;
      const trackFrac = bound / names.length;
      const tl = new Set(all.map((n) => n.toLowerCase()));
      const bones = sk.bones.filter((b) => !HELPER_TRACK.test(b.name));
      const driven = bones.filter((b) => tl.has(String(b.name).toLowerCase()) || (b.alias && tl.has(String(b.alias).toLowerCase()))).length;
      const skelFrac = bones.length ? driven / bones.length : 0;
      v = Math.max(trackFrac, skelFrac >= 0.9 && driven >= 3 ? skelFrac : 0);
    }
    FIT.bind.set(k, v);
  }
  return FIT.bind.get(k);
}
/** mean anim binding of a table's resolvable clips on a skeleton (1 when the table has no clip). */
function tableBind(e, skelKey) {
  const keys = [...new Set(e.records.map((r) => (r.anim ? resolveKey('anim', r.anim).key : null)).filter(Boolean))];
  if (!keys.length) return 1;
  return keys.reduce((a, k) => a + animBind(k, skelKey), 0) / keys.length;
}
/** skeletons that could drive this mesh + table: named after the mesh, or after the folder / prefix of the table's clips. */
function skeletonCandidates(meshKey, e) {
  const names = new Set();
  if (meshKey) names.add(baseNoExt(meshKey));
  const STATE_TAIL = /_(c?stand\d*|c?walk|c?run|att(ack)?\d*|die|dead|p\d|blocking|blocked|guard\d*|revive|appear)$/;
  for (const r of e.records) {
    if (!r.anim) continue;
    const k = resolveKey('anim', r.anim).key; if (!k) continue;
    const seg = k.split('/');
    if (seg.length > 3) names.add(seg[seg.length - 2]);
    names.add(baseNoExt(k).replace(STATE_TAIL, ''));
  }
  const out = [];
  for (const n of names) for (const k of BY_BASENAME.get(`${n}.skel`) || []) if (k.startsWith('skel/') && !out.includes(k)) out.push(k);
  return out;
}
export const FIT_MIN_COVERAGE = 0.9;  // mesh palette bones that must exist in the skeleton
export const FIT_MIN_BIND = 0.5;      // anim tracks that must bind for a clip to count as driving the skeleton

function scoreActTable(e, meshKey = null) {
  const skelKey = resolveKey('skel', e.skeleton).key;
  let s = skelKey ? 1000 : 0;
  const ok = new Set();
  for (const r of e.records) if (r.anim && resolveKey('anim', r.anim).key) ok.add(r.action);
  for (const c of [1, 2, 6, 8]) if (ok.has(c)) s += 100;
  s += ok.size;
  if (e.kind === 'dat') s += 0.5;
  // a skeleton that fits the mesh (and clips that fit the skeleton) outweighs any number of clips
  if (skelKey && meshKey) s += 3000 * paletteCoverage(meshKey, skelKey) + 500 * tableBind(e, skelKey);
  return s;
}

const trimZeros = (a) => { let n = a.length; while (n > 1 && (a[n - 1] === 0 || a[n - 1] === null)) n--; return a.slice(0, n); };
/** Anim-file naming conventions used only to back-fill a core state the table leaves empty or points at a missing file. */
const STATE_SUFFIX = {
  idle: [/_stand\.anim$/, /_cstand\.anim$/, /_stand\d*\.anim$/],
  walk: [/_walk\.anim$/, /_cwalk\.anim$/, /_c?run\.anim$/],
  run: [/_c?run\.anim$/, /_walk\.anim$/],
  attack: [/_att(ack)?0?1\.anim$/, /_att(ack)?\d*\.anim$/],
  die: [/_die\.anim$/, /_dead\.anim$/, /_die_?\d+\.anim$/],
};

/** Build a compact action set object from a parsed table (+ back-fill of missing core states).
 *  opts.skelOverride: data key of a skeleton to use instead of the table's (see chooseTable). */
function makeActionSet(e, actionsIdx, missingAnims, opts = {}) {
  const sk = opts.skelOverride ? { key: opts.skelOverride, how: 'override', want: dataKey('skel', e.skeleton) } : resolveKey('skel', e.skeleton);
  const clips = []; const clipKey = new Map();
  const actions = {};
  const missing = new Set();
  const estimated = [];
  const addClip = (key, r) => {
    // TimeLength 0 in 9 shipped rows (e.g. 9411 Truper walk): use the anim's own length (frames / 30 fps), else 1 s
    let tl = r.timeLength, est = false;
    if (!(tl > 0)) { animInfo(key); tl = FIT.animDur.get(key) > 0 ? FIT.animDur.get(key) : 1; est = true; }
    const clip = trimZeros([key, round(tl), round(r.startInter), round(r.endInter), round(r.timing), r.split, round(r.timing2), r.effect, r.cancelTime,
      r.swing, r.strike, round(r.freeze), r.unk300 || 0, r.unk301 || 0, r.unk302 || 0]);
    const ck = JSON.stringify(clip);
    if (!clipKey.has(ck)) { clipKey.set(ck, clips.length); clips.push(clip); if (est) estimated.push(clips.length - 1); }
    return clipKey.get(ck);
  };
  // back-filled clips must actually drive this skeleton (the suffix search once pulled ghostman_knight clips into
  // a crystal's deadman_chest table)
  const fits = (animKey) => !sk.key || animBind(animKey, sk.key) >= FIT_MIN_BIND;
  const recs = e.records.slice().sort((a, b) => a.action - b.action || a.index - b.index);
  for (const r of recs) {
    const name = ACTION_CODES[r.action] ?? (r.action >= 0 ? `ACT_${r.action}` : r.name);
    let ci = -1;
    if (r.anim) {
      const k = resolveKey('anim', r.anim);
      if (k.key) ci = addClip(k.key, r);
      else { missing.add(k.want); missingAnims?.add(k.want); }
    }
    if (!actions[name]) actions[name] = [];
    while (actions[name].length < r.index) actions[name].push(-1);
    actions[name][r.index] = ci;
  }
  // engine-facing states only reference clips that drive the skeleton: a rule whose clip does not bind falls through
  // to the next rule (serpens 3010/9612: STAND[0] is a humanoid shurani_stand parked in the table, STAND[1]
  // caput_cstand fits -> idle = STAND[1]); a state with no binding clip at all is left out and listed in unboundStates
  const binds = (ci) => !sk.key || animBind(clips[ci][0], sk.key) >= FIT_MIN_BIND;
  const unboundStates = {};
  const computeStates = () => {
    const states = {};
    for (const [st, rules] of Object.entries(STATE_RULES)) {
      let first = -1;
      for (const [nm, i] of rules) {
        const a = actions[nm];
        if (!(a && a[i] !== undefined && a[i] >= 0)) continue;
        if (first < 0) first = a[i];
        if (binds(a[i])) { states[st] = a[i]; break; }
      }
      if (!(states[st] >= 0) && first >= 0) unboundStates[st] = first;
    }
    for (const [st, nm] of Object.entries(STATE_LISTS)) {
      const a = actions[nm]; if (!a) continue;
      const u = [...new Set(a.filter((x) => x >= 0))];
      const b = u.filter(binds);
      if (b.length) states[st] = b; else if (u.length) unboundStates[st] = u;
    }
    return states;
  };
  let states = computeStates();
  // ---- back-fill core states (idle / walk / run / attack / die) that the table leaves empty
  const derived = {};
  const need = () => ['idle', 'walk', 'run', 'attack', 'die'].filter((s) => !(s === 'attack' ? states.attack : states[s] >= 0));
  if (sk.key && clips.length && need().length && actionsIdx) {
    // (1) another action table driving the same skeleton
    const twins = (actionsIdx.bySkelBase.get(baseNoExt(e.skeleton)) || []).filter((t) => t !== e);
    for (const st of need()) {
      const nm = { idle: 'STAND', walk: 'MOVE', run: 'MOVE', attack: 'ATTACK', die: 'DEAD' }[st];
      const want = st === 'run' ? 1 : 0;
      // accept only clips whose file name also looks like that state (tables sometimes park unrelated clips in MOVE etc.)
      const ok = (q) => q.action === ACTION_NAME_TO_CODE[nm] && q.anim && resolveKey('anim', q.anim).key
        && STATE_SUFFIX[st].some((re) => re.test(resolveKey('anim', q.anim).key)) && fits(resolveKey('anim', q.anim).key);
      for (const t of twins) {
        const r = t.records.find((q) => q.index === want && ok(q)) || t.records.find(ok);
        if (r) { const ci = addClip(resolveKey('anim', r.anim).key, r); derived[st] = t.src; setState(st, ci); break; }
      }
    }
    // (2) naming convention inside the animation folders the table already uses, restricted to files named
    //     after this creature (skeleton base name or the table's own clip prefixes) — anim/npc/ is one flat folder
    if (need().length) {
      const dirs = new Set(clips.map((c) => c[0].slice(0, c[0].lastIndexOf('/') + 1)));
      const STATE_TAIL = /_(c?stand\d*|c?walk|c?run|att(ack)?\d*|die|dead|p\d|blocking|blocked|guard\d*|revive|appear)$/;
      const prefixes = new Set([baseNoExt(e.skeleton), ...clips.map((c) => baseNoExt(c[0]).replace(STATE_TAIL, ''))]
        .filter((p) => p && p.length >= 4 && p !== 'npc' && p !== 'monster'));
      const pool = [...dirs].flatMap((d) => (BY_DIR.get(d) || []).filter((f) => f.endsWith('.anim')
        && [...prefixes].some((p) => f.slice(f.lastIndexOf('/') + 1).startsWith(p + '_')) && fits(f)));
      for (const st of need()) {
        for (const re of STATE_SUFFIX[st]) {
          const f = pool.find((p) => re.test(p));
          if (f) {
            // no table row: timeLength 0 -> the clip length is estimated from the anim (frames / 30 fps, anim.md) and the
            // clip is listed in timeLengthEstimated (a flat 1 s played e.g. house_man_stand, 240 frames, 8x too fast)
            const ci = addClip(f, { timeLength: 0, startInter: 4, endInter: 1, timing: st === 'attack' ? 0.5 : 0, split: 0, timing2: st === 'attack' ? 1 : 0, effect: 0, cancelTime: 0, swing: 0, strike: 0, freeze: 0 });
            derived[st] = 'convention'; setState(st, ci); break;
          }
        }
      }
    }
  }
  function setState(st, ci) {
    if (st === 'attack') states.attack = [ci];
    else states[st] = ci;
    delete unboundStates[st];
    if (st === 'walk' && !(states.run >= 0)) { states.run = ci; delete unboundStates.run; }
    if (st === 'run' && !(states.walk >= 0)) { states.walk = ci; delete unboundStates.walk; }
  }
  const set = { skel: sk.key, clips, actions, states };
  if (Object.keys(unboundStates).length) set.unboundStates = unboundStates;
  if (sk.how === 'basename') set.skelResolvedByName = sk.want;
  if (sk.how === 'override') set.skelFromTable = sk.want;
  if (!sk.key && e.skeleton) set.missingSkel = sk.want;
  if (missing.size) set.missingAnims = [...missing];
  if (Object.keys(derived).length) set.derived = derived;
  if (estimated.length) set.timeLengthEstimated = estimated;
  // clips whose tracks mostly do not bind to the skeleton (they leave the model in bind pose)
  if (sk.key) { const nb = clips.map((c, i) => (animBind(c[0], sk.key) < FIT_MIN_BIND ? i : -1)).filter((i) => i >= 0); if (nb.length) set.unboundClips = nb; }
  return set;
}

/** set.states without clips listed in set.unboundClips (they would leave the model in bind pose). */
function statesThatBind(set) {
  if (!set.unboundClips) return set.states;
  const bad = new Set(set.unboundClips);
  const out = {};
  for (const [k, v] of Object.entries(set.states)) {
    if (Array.isArray(v)) { const a = v.filter((c) => !bad.has(c)); if (a.length) out[k] = a; } else if (!bad.has(v)) out[k] = v;
  }
  return out;
}

class ActionSetRegistry {
  constructor(actionsIdx) { this.actionsIdx = actionsIdx; this.sets = {}; this.byContent = new Map(); this.missingAnims = new Set(); }
  /** @returns {string|null} action set id, or null when the table yields no playable clip at all (static prop). */
  add(e, srcNote, opts = {}) {
    const s = makeActionSet(e, this.actionsIdx, this.missingAnims, opts);
    if (!s.clips.length) { this.empty = (this.empty || 0) + 1; return null; }
    const ck = JSON.stringify(s);
    if (this.byContent.has(ck)) {
      const set = this.sets[this.byContent.get(ck)];
      set.users++;
      return this.byContent.get(ck);
    }
    let id = e.stem.replace(/\.act$/, '').replace(/\.act\./, '.');
    while (this.sets[id]) id += '+';
    this.byContent.set(ck, id);
    this.sets[id] = { src: srcNote || e.src, users: 1, ...s };
    return id;
  }
}

/** Choose the action table for (kind, index); fall back to a table whose skeleton matches the mesh. */
function pickActTable(actions, kind, index, meshKey) {
  const cands = [...(actions[kind].dat.get(index) || []), ...(actions[kind].csv.get(index) || [])];
  const mb = meshKey ? baseNoExt(meshKey) : '';
  if (cands.length) {
    let best = null, bs = -1;
    for (const e of cands) {
      let s = scoreActTable(e, meshKey);
      if (mb && baseNoExt(e.skeleton) === mb) s += 5;
      if (actions.listed.has(`${kind === 'MONSTER' ? 'monster' : 'npc'}/${e.stem}`)) s += 0.25;
      if (s > bs) { bs = s; best = e; }
    }
    return { table: best, how: best.kind, alternatives: cands.length - 1 };
  }
  if (mb && actions.bySkelBase.has(mb)) {
    const list = actions.bySkelBase.get(mb).slice().sort((a, b) => scoreActTable(b, meshKey) - scoreActTable(a, meshKey));
    return { table: list[0], how: 'borrowed' };
  }
  return { table: null, how: 'none' };
}

/** pickActTable + fallbacks: naming convention when there is no table, or when the table's skeleton does not
 *  exist but one named after the mesh does (e.g. NPC "Richard": table says npc_ricahard.skel, file is npc_rechard.skel).
 *  Then the fit check: when the table's skeleton does not drive the mesh (palette coverage < FIT_MIN_COVERAGE) or
 *  its own clips (mean binding < FIT_MIN_BIND), a skeleton named after the mesh / the clips' folder that fits both
 *  replaces it (skelOverride, e.g. 9902 Treasure Chest: table mon_treasurebox_01.skel, mesh + clips fb_treasure_chest).
 *  @returns {{table, how, skelOverride:string|null, coverage:number|null}} coverage = mesh palette fit of the final skeleton */
function chooseTable(actions, kind, index, meshKey) {
  const pick = pickActTable(actions, kind, index, meshKey);
  let table = pick.table, how = pick.how, skelOverride = null;
  if (!table) { table = conventionTable(meshKey, kind); if (table) how = 'convention'; }
  else if (!resolveKey('skel', table.skeleton).key) {
    const conv = conventionTable(meshKey, kind);
    if (conv) { table = conv; how = 'convention'; }
  }
  let coverage = null;
  if (table && meshKey) {
    const tsk = resolveKey('skel', table.skeleton).key;
    const cov = tsk ? paletteCoverage(meshKey, tsk) : 0;
    const bind = tsk ? tableBind(table, tsk) : 0;
    coverage = cov;
    // Only the skeleton the mesh was exported with (named after the mesh) is a safe replacement: mesh vertices are
    // in THAT skeleton's bind space, so a same-named-bones skeleton with another bind pose tears the mesh (tried:
    // 9082 Death Avoid on vinaelle_faray.skel detaches the scythe). And only when the table skeleton does not
    // cover the mesh and the table's own clips drive the mesh-named skeleton at least as well.
    if (tsk && cov < FIT_MIN_COVERAGE) {
      let best = null;
      for (const c of skeletonCandidates(meshKey, table)) {
        if (c === tsk || baseNoExt(c) !== baseNoExt(meshKey)) continue;
        const cc = paletteCoverage(meshKey, c); if (cc < FIT_MIN_COVERAGE) continue;
        const bb = tableBind(table, c);
        if (bb >= bind && (!best || bb > best.bind)) best = { key: c, cov: cc, bind: bb };
      }
      if (best) { skelOverride = best.key; coverage = best.cov; }
    }
    // Still no fit for a DEFORMABLE mesh (rigid 1-bone props render the same either way): the skeleton + clips named
    // after the mesh (convention) replace the table when they drive the mesh (NPC 804 Meister Merchant: table
    // npc_calix.skel lacks 19/39 npc_isis bones; skel/npc/npc_isis.skel + anim/npc/npc_isis.anim fit 100%).
    if (tsk && coverage < FIT_MIN_COVERAGE && !skelOverride && isDeformable(meshKey)) {
      const conv = conventionTable(meshKey, kind);
      const csk = conv ? resolveKey('skel', conv.skeleton).key : null;
      if (csk && csk !== tsk && paletteCoverage(meshKey, csk) >= FIT_MIN_COVERAGE && tableBind(conv, csk) >= FIT_MIN_BIND) {
        return { table: conv, how: 'convention', skelOverride: null, coverage: paletteCoverage(meshKey, csk), replaced: table.src };
      }
    }
  }
  return { table, how: table ? how : 'none', skelOverride, coverage };
}

/** Last resort: skeleton + animations next to the mesh by naming convention (mesh/x/y.mesh -> skel/x/y.skel, anim/x/y*.anim). */
function conventionTable(meshKey, kind) {
  if (!meshKey) return null;
  const rel = meshKey.replace(/^mesh\//, '').replace(/\.mesh$/, '');
  const skel = `skel/${rel}.skel`;
  if (!has(skel)) return null;
  const b = rel.slice(rel.lastIndexOf('/') + 1);
  const dir = rel.slice(0, rel.lastIndexOf('/'));
  const anims = [];
  for (const k of [`anim/${rel}.anim`]) if (has(k)) anims.push(k);
  for (const f of BY_DIR.get(`anim/${dir}/${b}/`) || []) if (f.endsWith('.anim')) anims.push(f);
  if (!anims.length) return null;
  const pick = (re) => anims.find((a) => re.test(a.slice(a.lastIndexOf('/') + 1)));
  const recs = [];
  // timeLength 0 = unknown: makeActionSet estimates it from the anim (frames / 30 fps) and lists the clip in
  // timeLengthEstimated (a flat 1 s played npc_rechard.anim, 350 frames = 11.7 s, 12x too fast). Hit timing only on ATTACK.
  const add = (action, index, a) => {
    if (a) recs.push({ style: 0, action, index, anim: a.replace(/^anim\//, ''), startInter: 4, endInter: 1, timeLength: 0, swing: 0, strike: 0,
      timing: action === 6 ? 0.5 : 0, split: 0, timing2: action === 6 ? 1 : 0, freeze: 0, effect: 0, cancelTime: 0 });
  };
  add(1, 0, pick(/_stand\.anim$/) || pick(/\.anim$/));
  add(1, 1, pick(/_cstand\.anim$/));
  add(2, 0, pick(/_walk\.anim$/));
  add(2, 1, pick(/_c?run\.anim$/));
  anims.filter((a) => /_att(ack)?\d*\.anim$/.test(a)).forEach((a, i) => add(6, i, a));
  anims.filter((a) => /_p\d\.anim$/.test(a)).forEach((a, i) => add(7, i, a));
  add(8, 0, pick(/_(die|dead)\.anim$/));
  return { src: `convention:${meshKey}`, stem: `conv.${b}`, kind: 'convention', type: kind, index: -1, skeleton: skel.replace(/^skel\//, ''), records: recs };
}

// ------------------------------------------------------------------------------------------------
// shapes (script/shape/<kind>_shape.csv) -> mesh / tpack / textures
// ------------------------------------------------------------------------------------------------
function loadShapeTable(rel) {
  const rows = parseCSV(readText(rel));
  const map = new Map();
  let dups = 0;
  for (let i = 1; i < rows.length; i++) {
    const r = rows[i];
    if (!r || r.length < 3 || !String(r[1] ?? '').trim()) continue;
    const key = String(r[1]).trim().toLowerCase();
    if (map.has(key)) { dups++; continue; }
    map.set(key, { index: num(r[0]), name: String(r[1]).trim(), mesh: String(r[2] ?? '').trim(), tpack: String(r[3] ?? '').trim(),
      effect: num(r[4]), lod: /true/i.test(String(r[5] ?? '')), glowEffect: /true/i.test(String(r[6] ?? '')), effectId: num(r[7]) });
  }
  return { map, dups };
}

function resolveTexture(texpath, file, meshKey) {
  const f = String(file).trim().replace(/\\/g, '/').toLowerCase();
  const dir = String(texpath ?? '').trim().replace(/\\/g, '/').replace(/^\/+|\/+$/g, '').toLowerCase();
  const b = f.slice(f.lastIndexOf('/') + 1);
  const cands = [];
  if (dir) cands.push(`texture/${dir}/${f}`);
  cands.push(`texture/${f}`);
  if (dir) cands.push(`texture/${dir.split('/')[0]}/${b}`);
  if (meshKey) { const seg = meshKey.split('/'); if (seg.length > 2) cands.push(`texture/${seg[1]}/${b}`); }
  for (const c of cands) if (has(c)) return c;
  const alts = BY_BASENAME.get(b) || [];
  const t = alts.find((k) => k.startsWith('texture/'));
  return t || null;
}

class ShapeRegistry {
  constructor(kind) { this.kind = kind; this.shapes = {}; this.missing = { mesh: [], tpack: [], texture: [] }; this.tpackCache = new Map(); }
  add(row) {
    const key = row.name.toLowerCase();
    if (this.shapes[key]) return key;
    // shape rows that name the wrong category folder (cf_fountain02a_gate: mesh/monster/, Global ships mesh/brick/): use the one
    // Global file of that name in the same root, recorded in meshResolvedByName / tpackResolvedByName (asset-ref-resolve.mjs)
    const byName = (root, want) => { if (!want || has(want)) return [want, null]; const r = resolveRef(want, has, BY_BASENAME, { roots: [root] }); return r.key ? [r.key, want] : [want, null]; };
    const [mesh, meshWant] = byName('mesh', dataKey('mesh', row.mesh));
    let [tpack, tpackWant] = row.tpack ? byName('texturepack', dataKey('texturepack', row.tpack)) : [null, null];
    const s = { mesh: has(mesh) ? mesh : null };
    if (meshWant) s.meshResolvedByName = meshWant;
    if (tpackWant) s.tpackResolvedByName = tpackWant;
    if (!has(mesh)) { s.missingMesh = mesh; this.missing.mesh.push(`${row.name}: ${mesh}`); }
    // named tpack not shipped (the 6 *_field boss variants): fall back to the texture pack named after the mesh
    // (tpack.js tpackPathForMesh convention), recorded in tpackFrom
    if (tpack && !has(tpack) && has(mesh)) {
      const alt = mesh.replace(/^mesh\//, 'texturepack/').replace(/\.mesh$/, '.tpack');
      if (has(alt)) { s.missingTpack = tpack; s.tpackFrom = 'mesh-name'; this.missing.tpack.push(`${row.name}: ${tpack} (using ${alt})`); tpack = alt; }
    }
    if (tpack) {
      if (has(tpack)) {
        s.tpack = tpack;
        let tp = this.tpackCache.get(tpack);
        if (!tp) { tp = parseTpackText(readRel(tpack)); this.tpackCache.set(tpack, tp); }
        const tex = {};
        const miss = [];
        for (const kind of ['diffuse', 'specular', 'bump', 'glow']) {
          const slots = Object.keys(tp[kind]).map(Number);
          if (!slots.length) continue;
          const arr = [];
          for (const sl of slots) {
            const k = resolveTexture(tp.texpath, tp[kind][sl], mesh);
            arr[sl] = k;
            if (!k) miss.push(`${kind}${sl}:${tp[kind][sl]}`);
          }
          for (let i = 0; i < arr.length; i++) if (arr[i] === undefined) arr[i] = null;
          tex[kind] = arr;
        }
        s.textures = tex;
        if (miss.length) { s.missingTextures = miss; this.missing.texture.push(`${row.name}: ${miss.join(', ')}`); }
        if (!tex.diffuse && !miss.length) s.invisible = true; // texture pack lists no texture: picking / trigger volume
      } else { s.tpack = null; s.missingTpack = tpack; this.missing.tpack.push(`${row.name}: ${tpack}`); }
    } else { s.tpack = null; s.invisible = true; } // no texture pack at all: trap / trigger volume, not drawn by the client
    if (row.effect) s.effect = row.effect;
    if (row.effectId) s.effectId = row.effectId;
    if (row.lod) s.lod = true;
    if (row.glowEffect) s.glowEffect = true;
    this.shapes[key] = s;
    return key;
  }
}

// ------------------------------------------------------------------------------------------------
// sounds: "Basic_Mon_<shape>" scene (stand / defeat / die / atk units) + per-animation scenes named
// after the anim file ("hellspider_att01") in property/effect/effectscene.snd.txt
// ------------------------------------------------------------------------------------------------
function loadSounds() {
  if (!existsRel('property/effect/effectscene.snd.txt') || !existsRel('property/effect/effectdata.snd.txt')) return null;
  const scenes = parseEffectScenes(readRel('property/effect/effectscene.snd.txt'));
  const units = parseEffectData(readRel('property/effect/effectdata.snd.txt'));
  const soundKey = (file) => {
    const b = String(file).trim().replace(/\\/g, '/').toLowerCase();
    const bn = b.slice(b.lastIndexOf('/') + 1);
    if (has(`sound/${b}`)) return `sound/${b}`;
    const alts = (BY_BASENAME.get(bn) || []).filter((k) => k.startsWith('sound/'));
    return alts[0] || null;
  };
  const sceneSounds = (sceneName) => {
    const sc = scenes.get(String(sceneName).toLowerCase());
    if (!sc) return null;
    const out = [];
    for (const [, unitName] of sc.res) {
      const u = units.get(unitName.toLowerCase());
      if (!u) continue;
      for (const s of u.sounds) { const k = soundKey(s.file); if (k) out.push({ unit: u.name, key: k, volume: s.volume, range: s.range }); }
    }
    return out.length ? out : null;
  };
  return { scenes, units, sceneSounds };
}
function classifySfx(unitName) {
  const n = unitName.toLowerCase();
  if (/stand|idle/.test(n)) return 'idle';
  if (/defeat|damage|hit/.test(n)) return 'hit';
  if (/die|dead|death/.test(n)) return 'die';
  if (/atk|att/.test(n)) return 'attack';
  if (/move|walk|run/.test(n)) return 'move';
  return 'other';
}
function shapeSfx(snd, shapeName) {
  if (!snd) return null;
  const list = snd.sceneSounds(`Basic_Mon_${shapeName}`) || snd.sceneSounds(`sd_Basic_Mon_${shapeName}`);
  if (!list) return null;
  const out = {};
  for (const s of list) { const r = classifySfx(s.unit); (out[r] || (out[r] = [])).includes(s.key) || out[r].push(s.key); }
  return out;
}
function clipSfx(snd, set) {
  if (!snd) return null;
  const out = {};
  set.clips.forEach((c, i) => {
    const list = snd.sceneSounds(baseNoExt(c[0]));
    if (list) out[i] = [...new Set(list.map((s) => s.key))];
  });
  return Object.keys(out).length ? out : null;
}

// ================================================================================================
// MONSTERS
// ================================================================================================
const ATTACK_TYPES = ['melee', 'powerMelee', 'specialMelee', 'greatMelee', 'range', 'powerRange', 'specialRange', 'greatRange', 'heal', 'revive'];
const AGGRO_ATTACKS = ['aggro1', 'aggro2', 'aggro3', 'aggro4'];
/** share/ai/patterninfo.csv index -> behaviour (the monster AIKey is this index). */
const AI_BEHAVIOUR = {
  1: { aggressive: true, style: 'melee' }, 2: { aggressive: false, style: 'melee' }, 3: { aggressive: true, style: 'range' },
  4: { aggressive: false, style: 'melee', callTeam: true }, 5: { aggressive: true, style: 'melee', callTeam: true },
  6: { aggressive: true, style: 'range', callTeam: true }, 7: { aggressive: false, style: 'none' }, 8: { aggressive: true, style: 'melee' },
  9: { aggressive: true, style: 'range' }, 10: { aggressive: false, style: 'melee', aggroTable: true },
  11: { aggressive: true, style: 'melee', aggroTable: true }, 12: { aggressive: false, style: 'range' }, 13: { aggressive: false, style: 'trap' },
  20: { aggressive: true, style: 'boss' }, 21: { aggressive: true, style: 'boss' }, 22: { aggressive: true, style: 'boss' }, 23: { aggressive: true, style: 'boss' },
  1000: { aggressive: false, style: 'call' }, 1002: { aggressive: false, style: 'stop' },
};

/** share/ai/info.csv columns mapped to named ai.* fields (the rest go to ai.extra when non-zero). */
const INFO_USED = new Set(['DwInfoIndex', 'DwExploreRange', 'DwSight', 'DwPersuitRange', 'DwAvoidRange', 'DwExploreStandDelay', 'DwExploreMoveDelay',
  'DwStandDelay', 'DwMoveDelay', 'DwCallTeamPossibelHP', 'DwCallTeamCount', 'dwCallTeamCell', 'dwFollowTarget', 'dwSpecialAttackStartHP',
  'dwSpecialMeleeAttackRate', 'dwSpecialRangeAttackRate', 'dwSpecialAttackRate', 'dwSpecialDelayTime', 'DwPowerAttackStartHP',
  'dwPowerMeleeAttackProbable', 'dwPowerRangeAttackProbable', 'dwPowerRate', 'dwPowerDelayTime', 'dwAttack1_Rate', 'dwAttack2_Rate',
  'dwAttack3_Rate', 'dwAttack4_Rate', 'PatternType', 'dwMaxSummonsMonsterCount', 'dwReSummonsMonsterTick', 'dwMaxSummonsMonsterRange',
  'dwSummonsStartPcCount', 'dwMaxSummonsMonsterLimit']);

/** One attack block (15 csv columns) -> [min, max, absMin, absMax, range, delay, material, resultCode, v1..v7] (trailing zeros
 *  trimmed). Blocks with neither a cell range nor a delay are never used by the server AI and are dropped. */
function attackBlocks(header, row, startCols) {
  const out = {};
  for (const [name, c] of startCols) {
    if (c < 0) continue;
    const v = (k) => num(row[c + k]);
    if (!(v(5) > 0 || v(6) > 0)) continue;
    out[name] = trimZeros([v(1), v(2), v(3), v(4), v(5), v(6), v(0), v(7), v(8), v(9), v(10), v(11), v(12), v(13), v(14)]);
  }
  return out;
}
function findAttackStarts(header, names, pattern) {
  // header cells like AttackMaterialMelee / AttackMaterial_Power_Melee / 1stAttackMaterialNormal
  const starts = [];
  for (let i = 0; i < header.length; i++) if (pattern.test(header[i])) starts.push(i);
  return names.map((n, k) => [n, starts[k] ?? -1]);
}

function buildMonsters({ locName, actions }) {
  const REPORT = {};
  // ------------------------------------------------ sources
  const datRecs = parseMonsterDat(readRel('share/creature/monster.dat'));
  const dat = new Map();
  let stray = 0, strayRecs = 0, shapeTail = 0, nonFinite = 0;
  for (const d of datRecs) {
    if (dat.has(d.index)) hard(`monster.dat: duplicate index ${d.index}`);
    dat.set(d.index, d);
    if (d.strayBytes) { stray += d.strayBytes; strayRecs++; }
    if (d.shapeTailBytes) shapeTail++;
    for (const k of ['walkSpeed', 'runSpeed', 'width']) if (!Number.isFinite(d[k]) || d[k] < 0 || d[k] > 1000) nonFinite++;
  }
  if (nonFinite) hard(`monster.dat: ${nonFinite} non-finite/implausible speed/width values`);
  log(`monster.dat: ${datRecs.length} records; ${strayRecs} with nonzero bytes outside known fields (${stray} bytes); ${shapeTail} with junk after the shape string`);
  REPORT.monsterDat = { records: datRecs.length, recordsWithStrayBytes: strayRecs, strayBytes: stray, shapeFieldJunk: shapeTail };

  const csv = loadTable('share/creature/monster.csv');
  // Native guards are a transposed creature table. Align its fields with the
  // existing monster converter; keep all authored stats, attacks and AI values.
  const sentryIds=new Set(),sentryExtras=new Map();
  const remoteRows=parseCSV(readText('share/creature/remote.csv')),remoteHeader=remoteRows.shift(),remoteIndex=remoteHeader.findIndex(k=>k.trim().toLowerCase()==='index'),remoteType=remoteHeader.findIndex(k=>k.trim().toLowerCase()==='resulttype');
  const sentryResultContext={remotes:new Map(remoteRows.map(row=>[Number(row[remoteIndex]),{resultType:Number(row[remoteType])}]))};
  if(existsRel('share/creature/sentry.csv')){
    const rows=parseCSV(readText('share/creature/sentry.csv')),fields=new Map(rows.map(r=>[String(r[0]).trim(),r]));
    const indexes=fields.get('Index')||[];
    for(let col=1;col<indexes.length;col++){
      const id=Number(indexes[col]);if(!Number.isInteger(id)||id<=0)continue;
      if(dat.has(id)||csv.byIndex.has(id)){hard(`sentry.csv: creature index ${id} already exists`);continue;}
      csv.byIndex.set(id,csv.header.map(h=>fields.get(h)?.[col]??'0'));sentryIds.add(id);
      sentryExtras.set(id,Object.fromEntries([...fields].filter(([h])=>!csv.header.includes(h)).map(([h,r])=>[h,num(r[col])])));
    }
  }
  const battle = loadTable('share/ai/monsterbattle.csv');
  const info = loadTable('share/ai/info.csv');
  const aggro = existsRel('share/creature/monster_aggro.csv') ? loadTable('share/creature/monster_aggro.csv') : null;
  const drop = existsRel('share/item/monsterdropitemtable.csv') ? loadTable('share/item/monsterdropitemtable.csv') : null;
  const shapesCsv = loadShapeTable('script/shape/monster_shape.csv');
  const npcShapesCsv = loadShapeTable('script/shape/npc_shape.csv');
  const sentryShapesCsv = loadShapeTable('script/shape/sentry_shape.csv');
  const patternTab = loadTable('share/ai/patterninfo.csv');
  // aggressiveness straight from each pattern's state machine: from the initial REST state, does SIGHT_IN start a
  // chase (PERSUIT / *_ATTACK)?  Positive_* do; Negative_*, Event, Trap and the named-boss patterns 20-23
  // (SIGHT_IN,REST -> EXPLORE; they only chase once enraged) do not.
  // Also recorded per pattern: rest = NEXT_MODE of the triggers from REST (sightIn / meleeIn / rangeIn / underAttack) and
  // attacksInRange = a target entering melee/range-attack distance starts an attack without a hit first.
  // Regulus/Aldebaran (20/23) are the only patterns that do that without chasing on sight (RANGE_ATTACK_IN -> RANGE_ATTACK).
  const patternAggro = new Map();
  const patternRest = new Map();
  for (const [k, r] of patternTab.byIndex) {
    const f = dataKey('share/ai', String(r[1] ?? '').trim());
    if (!f || !existsRel(f)) { soft(`AI pattern ${k}: file ${f} missing`); continue; }
    const rows = parseCSV(readText(f));
    const at = (ev) => { const x = rows.find((q) => String(q[0]).trim() === ev && String(q[1]).trim() === 'REST'); return x ? String(x[3] ?? '').trim() : null; };
    const rest = { sightIn: at('SIGHT_IN'), meleeIn: at('MELEE_ATTACK_IN'), rangeIn: at('RANGE_ATTACK_IN'), underAttack: at('UNDER_ATTACK') };
    for (const key of Object.keys(rest)) if (rest[key] === null) delete rest[key];
    if (Object.keys(rest).length) patternRest.set(k, rest);
    if (rest.sightIn) patternAggro.set(k, /PERSUIT|ATTACK/.test(rest.sightIn));
  }
  const behaviour = (key) => {
    const b = AI_BEHAVIOUR[key] || { aggressive: false, style: 'unknown' };
    const out = patternAggro.has(key) ? { ...b, aggressive: patternAggro.get(key) } : { ...b };
    const rest = patternRest.get(key);
    if (rest) { out.attacksInRange = /ATTACK/.test(rest.meleeIn || '') || /ATTACK/.test(rest.rangeIn || ''); out.rest = rest; }
    return out;
  };
  const rankTab = parseCSV(readText('share/creature/rank.csv'));
  const snd = WITH_SFX ? loadSounds() : null;
  log(`monster.csv ${csv.byIndex.size} rows, monsterbattle.csv ${battle.byIndex.size}, info.csv ${info.byIndex.size}, monster_shape ${shapesCsv.map.size}, drop table ${drop ? drop.byIndex.size : 0}`);

  const C = (t, row, name, d = 0) => { const i = t.col(name); return i < 0 ? d : num(row[i], d); };
  const S = (t, row, name) => { const i = t.col(name); return i < 0 ? '' : String(row[i] ?? '').trim(); };

  // cross-check compiled dat vs the (older) monster.csv snapshot
  const agree = {};
  for (const [idx, d] of dat) {
    const r = csv.byIndex.get(idx); if (!r) continue;
    for (const [k, col] of [['level', 'Level'], ['maxHP', 'MaxHP'], ['exp', 'Exp'], ['walkSpeed', 'WalkSpeed'], ['runSpeed', 'RunSpeed'], ['width', 'Width'],
      ['material', 'Material'], ['aiKey', 'AIKey'], ['aiType', 'AI_Type'], ['rank', 'Rank'], ['moneyRate', 'Money_Rate'], ['isBlock', 'IsBlock'], ['target', 'Target'], ['damageType', 'DamageType']]) {
      const a = agree[k] || (agree[k] = [0, 0]);
      a[0]++; if (Math.abs(d[k] - C(csv, r, col)) < 1e-3) a[1]++;
    }
    if (d.shape.toLowerCase() !== S(csv, r, 'ShapeInfo').toLowerCase()) (agree.shape || (agree.shape = [0, 0]))[0]++;
  }
  REPORT.datVsMonsterCsvAgreement = Object.fromEntries(Object.entries(agree).map(([k, [n, ok]]) => [k, `${ok}/${n}`]));

  // ------------------------------------------------ spawns (every MON_*.csv + maplist bindings)
  const spawnCount = new Map();   // monster -> spawn rows (all MON_ files)
  const spawnFiles = {};          // file key -> rows
  let spawnRows = 0, spawnSkipped = 0;
  const editorLists = [];
  // Scan fix A (handoff 2026-10-29): 'Global (older)' fallback. fullscan agent3 FINDINGS "Server-ref notes" lists 14 spawn
  // tables that current Global ships empty (header-only) or not at all while the older server-ref Global data has rows
  // (server-ref/share/map; the Arena copies are byte-identical). Current Global
  // wins whenever its file has any row; only then are the server-ref rows used, tagged source:'server-ref (Global older)'.
  // Evidence level 3 (server-ref data), read-only file reads; no server-ref program is run.
  // Set DEKARON_NO_SERVER_REF_SPAWNS=1 to build Global-only; DEKARON_SERVER_REF_SHARE overrides the share folder.
  const SR_SHARE = process.env.DEKARON_NO_SERVER_REF_SPAWNS ? null
    : (process.env.DEKARON_SERVER_REF_SHARE || null);
  const SR_SPAWN_KEYS = new Set([
    '00_braiken_castle_old/mon_00_braiken_castle.csv', '07_loa_castle/mon_07_loa_castle.csv', '111_egutt/mon_111_egutt.csv',
    '12_crespo/callmonster_12_crespo.csv', '13_drako/mon_13_draco.csv', '150_ardeca/callmonster_150_ardeca.csv',
    '158_shrineofelonohm/mon_158_shrineofelonohm.csv', '20_under_python/callmonster_20_under_python.csv',
    '20_under_python/mon_20_under_python.csv', '21_deneb/mon_03_deneb.csv', '27_seal/mon_27_seal.csv',
    '548_lost_horizon/mon_548_lost_horizon.csv', '552_guild_agit/mon_552_guild_agit.csv', '63_land of death/callmonster_63_lod.csv',
  ].map((r) => 'share/map/' + r));
  const srFallbackUsed = new Set();
  const srBytes = (key) => {
    if (!SR_SHARE || !SR_SPAWN_KEYS.has(key)) return null;
    let dir = path.join(SR_SHARE, 'map');
    for (const part of key.split('/').slice(2)) {
      let hit = null; try { hit = fs.readdirSync(dir).find((x) => x.toLowerCase() === part); } catch { return null; }
      if (!hit) return null; dir = path.join(dir, hit);
    }
    try { return fs.statSync(dir).isFile() ? fs.readFileSync(dir) : null; } catch { return null; }
  };
  const addSpawnFile = (f) => {
    let p = existsRel(f) ? parseSpawnCsv(readRel(f)) : { rows: [], skipped: 0 };
    if (!p.rows.length) { const b = srBytes(f); const q = b && parseSpawnCsv(b); if (q && q.rows.length) { p = q; srFallbackUsed.add(f); } }
    spawnFiles[f] = p.rows; spawnRows += p.rows.length; spawnSkipped += p.skipped;
    for (const r of p.rows) spawnCount.set(r[0], (spawnCount.get(r[0]) || 0) + 1);
  };
  const callFiles = [];
  for (const f of FILES) {
    if (!f.startsWith('share/map/')) continue;
    const b = f.slice(f.lastIndexOf('/') + 1);
    if (/callmonster_.*\.csv$/.test(b)) { callFiles.push(f); continue; }
    if (!/^mon_.*\.csv$/.test(b)) continue;
    if (/_monster\.csv$/.test(b)) { editorLists.push(f); continue; }
    addSpawnFile(f);
  }
  for (const k of SR_SPAWN_KEYS) {
    if (/\/mon_[^/]+\.csv$/.test(k) && !spawnFiles[k]) addSpawnFile(k);
    if (/callmonster_[^/]+\.csv$/.test(k) && !callFiles.includes(k)) callFiles.push(k);
  }
  // spawn tables a map list points at under another name (monster_177_python_inside.csv, 223_event_dungeon.csv)
  for (const mb of mapBindings()) for (const k of mb.mon) if (!spawnFiles[k] && has(k)) addSpawnFile(k);
  const spawns = {};
  const unboundSpawnFiles = new Set(Object.keys(spawnFiles));
  const missingSpawnFiles = [];
  for (const mb of mapBindings()) {
    if (!mb.mon.length) continue;
    const key = mb.mon.find((k) => spawnFiles[k]);
    if (!key) { missingSpawnFiles.push(`${mb.index} ${mb.name}: ${mb.mon[0]}`); continue; }
    unboundSpawnFiles.delete(key);
    spawns[mb.index] = { name: mb.name, map: mb.mapFile, file: key, rows: spawnFiles[key] };
    if (srFallbackUsed.has(key)) spawns[mb.index].source = 'server-ref (Global older)';
    if (mb.from !== 'client') spawns[mb.index].from = mb.from;
  }
  // Folder-convention: bind unbound MON files and replace cross-map misbinds (share/map/<index>_*/mon_*.csv).
  // Only folders a Global maplist row / synthesised map references (orphan folders are never loaded; LANE-50).
  const REF_FOLDERS = referencedMapFolders(DATA);
  let folderSpawnAdds = 0, folderSpawnReplaces = 0;
  const byFolderMon = new Map();
  for (const f of Object.keys(spawnFiles)) {
    const m = f.match(/^share\/map\/(\d+)_[^/]+\/(mon_[^/]+\.csv)$/i);
    if (!m || /_monster\.csv$/i.test(f) || (REF_FOLDERS && !REF_FOLDERS.has(f.split('/')[2].toLowerCase()))) continue;
    const mapIdx = +m[1];
    const prev = byFolderMon.get(mapIdx);
    const rows = spawnFiles[f];
    const low = m[2].toLowerCase();
    const nameHit = low.includes('_' + mapIdx + '_') || low.startsWith('mon_' + mapIdx + '_') || low.startsWith('mon_' + String(mapIdx).padStart(2, '0') + '_');
    if (!prev || (nameHit && !prev.nameHit) || rows.length > prev.rows.length) byFolderMon.set(mapIdx, { file: f, rows, nameHit: !!nameHit });
  }
  // Scan fix A (SCAN-B I1): Tower of Spell 1F/5F (95/99) have an empty Global MonsterLocatePath (share/maplist.csv:90/:94)
  // and are populated by their dungeon scripts (callmonster_95/_99 + waves in dungeons.json); the shared 16-row MON file
  // (same SHA as 98's, which Global DOES bind) must not also spawn statically. Map 201 stays (LANE-07 decision).
  // Owner rule (never remove content): the static table is KEPT by default and labelled; set
  // DEKARON_SCRIPT_ONLY_MAPS_STATIC=0 to build these two maps script-only (the Global maplist reading).
  const SCRIPT_ONLY_SPAWN_MAPS = process.env.DEKARON_SCRIPT_ONLY_MAPS_STATIC === '0' ? new Set([95, 99]) : new Set();
  const NOT_GLOBAL_BOUND_SPAWN_MAPS = new Set([95, 99]);
  for (const [mapIdx, t] of byFolderMon) {
    const cur = spawns[mapIdx];
    if (!cur && SCRIPT_ONLY_SPAWN_MAPS.has(mapIdx)) { unboundSpawnFiles.delete(t.file); continue; }
    const curFolder = cur?.file && Number((String(cur.file).match(/^share\/map\/(\d+)_/i) || [])[1]);
    if (cur && curFolder === mapIdx) { unboundSpawnFiles.delete(t.file); continue; }
    if (cur) folderSpawnReplaces++; else folderSpawnAdds++;
    const dirName = t.file.split('/')[2].replace(/^\d+_/, '').replace(/_/g, ' ');
    spawns[mapIdx] = { name: cur?.name || dirName, map: cur?.map || null, file: t.file, rows: t.rows, from: 'folder' };
    if (!cur && NOT_GLOBAL_BOUND_SPAWN_MAPS.has(mapIdx)) spawns[mapIdx].note = 'not bound by Global (kept per owner rule)';
    if (srFallbackUsed.has(t.file)) spawns[mapIdx].source = 'server-ref (Global older)';
    unboundSpawnFiles.delete(t.file);
  }
  log(`spawn tables: ${Object.keys(spawnFiles).length} MON_*.csv, ${spawnRows} rows (${spawnSkipped} non-spawn lines), ${spawnCount.size} distinct monsters; ` +
    `${Object.keys(spawns).length} maps bound, ${missingSpawnFiles.length} maplist paths missing, ${unboundSpawnFiles.size} files not referenced by maplist, folder +${folderSpawnAdds}/~${folderSpawnReplaces}`);
  // scripted spawns (dungeon scripts / triggers): share/map/<map>/[group]callmonster_*.csv
  // bound to maps by maplist CallMonsterPath (authoritative: the file's own MapIndex row is copy-pasted in ~20 files,
  // e.g. callmonster_25_crespotreasure.csv says 152); `map` keeps the file's value, `maps` the maplist rows using it
  const callMaps = new Map();
  for (const mb of mapBindings()) for (const k of mb.call) { if (!callMaps.has(k)) callMaps.set(k, []); callMaps.get(k).push(mb.index); }
  const callSpawns = {};
  const callCount = new Map();
  let callHeaderDisagrees = 0; const callPathsMissing = [];
  for (const [k, list] of callMaps) if (!has(k)) callPathsMissing.push(`${list.join(',')}: ${k}`);
  for (const f of callFiles.sort()) {
    let p = existsRel(f) ? parseCallMonsterCsv(readRel(f)) : { map: null, rows: [], randomCalls: [], randomPositions: [] };
    let fromSr = false;
    if (!p.rows.length && !p.randomCalls.length) { const b = srBytes(f); const q = b && parseCallMonsterCsv(b); if (q && (q.rows.length || q.randomCalls.length)) { p = q; fromSr = true; srFallbackUsed.add(f); } }
    if (!p.rows.length && !p.randomCalls.length) continue;
    const e = { map: p.map, group: /groupcallmonster_/.test(f), rows: p.rows };
    if (fromSr) e.source = 'server-ref (Global older)';
    if (callMaps.has(f)) { e.maps = callMaps.get(f); if (!e.maps.includes(p.map)) callHeaderDisagrees++; }
    if (p.randomCalls.length) { e.randomCalls = p.randomCalls; e.randomPositions = p.randomPositions; }
    callSpawns[f] = e;
    for (const r of p.rows) callCount.set(r[1], (callCount.get(r[1]) || 0) + 1);
    for (const r of p.randomCalls) callCount.set(r[1], (callCount.get(r[1]) || 0) + 1);
  }
  log(`call-monster tables: ${Object.keys(callSpawns).length} non-empty of ${callFiles.length}, ${callCount.size} distinct monsters; ` +
    `${Object.values(callSpawns).filter((e) => e.maps).length} bound by maplist CallMonsterPath (${callHeaderDisagrees} whose own MapIndex row disagrees), ${callPathsMissing.length} maplist paths missing`);

  REPORT.serverRefSpawnFallback = { share: SR_SHARE, used: [...srFallbackUsed].sort(),
    boundMaps: Object.entries(spawns).filter(([, v]) => v.source).map(([k, v]) => `${k} ${v.file} ${v.rows.length}`) };
  log(`server-ref (Global older) spawn fallback: ${srFallbackUsed.size} file(s) used, ${REPORT.serverRefSpawnFallback.boundMaps.length} bound map(s)`);

  // ------------------------------------------------ registries
  const shapes = new ShapeRegistry('monster');
  const sets = new ActionSetRegistry(actions);
  const attackStartsBattle = findAttackStarts(battle.header, ATTACK_TYPES, /^AttackMaterial/i);
  const aggroStartsBattle = findAttackStarts(battle.header, AGGRO_ATTACKS, /^\d(st|nd|rd|th)AttackMaterial/i);
  const attackStartsCsv = findAttackStarts(csv.header, ATTACK_TYPES, /^AttackMaterial/i);
  if (attackStartsBattle.some(([, c]) => c < 0)) hard('monsterbattle.csv: attack block columns not found');

  // ------------------------------------------------ build
  const all = new Set([...dat.keys(), ...csv.byIndex.keys()]);
  const monsters = {};
  const itemSetsUsed = new Set();
  const itemSetsExUsed = new Set();
  // every monsterdropitemtable row per Index, in file order (loadTable's byIndex keeps only the first)
  const dropRowsByIndex = new Map();
  if (drop) for (let i = 1; i < drop.rows.length; i++) {
    const r = drop.rows[i]; if (!r || r.length < 2) continue;
    const k = String(r[0] ?? '').trim(); if (!/^-?\d+$/.test(k)) continue;
    if (!dropRowsByIndex.has(+k)) dropRowsByIndex.set(+k, []);
    dropRowsByIndex.get(+k).push(r);
  }
  const sfxDone = new Set();
  const actHow = {};
  const fitStats = { override: [], mismatch: [], replaced: [] };
  for (const idx of [...all].sort((a, b) => a - b)) {
    const d = dat.get(idx) || null;
    const c = csv.byIndex.get(idx) || null;
    const b = battle.byIndex.get(idx) || null;
    const ai = info.byIndex.get(idx) || null;
    const m = {};
    if(sentryIds.has(idx)){m.sentry=true;m.sentryNative=sentryExtras.get(idx);}
    // ---- identity
    const shapeName = d ? d.shape : S(csv, c, 'ShapeInfo');
    // (display name: CP949 bytes in the csv / shape fallbacks are decoded, e.g. 9295 shape "집사_연출"; m.shape stays latin1
    //  because it is the byte-exact key of monster_shape.csv)
    //  lines_eu text is UTF-16 already and must not go through kr())
    m.name = ((d && locName(d.nameKey)) || kr(((c && S(csv, c, 'Name')) || (aggro && aggro.byIndex.get(idx) && String(aggro.byIndex.get(idx)[1]).trim()) || shapeName).trim())).trim();
    if (!(d && locName(d.nameKey)) && !(c && S(csv, c, 'Name'))) m.nameFromShape = true;
    const kname = b ? kr(String(b[2] ?? '').trim()) : '';
    if (kname) m.nameKr = kname;
    m.shape = shapeName.toLowerCase();
    // ---- core stats (compiled dat first; monster.csv only for indices missing from the dat)
    m.rank = d ? d.rank : C(csv, c, 'Rank');
    m.level = d ? d.level : C(csv, c, 'Level');
    m.hp = d ? d.maxHP : C(csv, c, 'MaxHP');
    const regen = b ? C(battle, b, 'HPRecovery') : C(csv, c, 'HPRecovery');
    if (regen) m.hpRegen = regen;
    m.exp = d ? d.exp : C(csv, c, 'Exp');
    m.def = b ? [C(battle, b, 'DefenceMin'), C(battle, b, 'DefenceMax')] : [C(csv, c, 'Defence_Min'), C(csv, c, 'Defence_Max')];
    if (b && (C(battle, b, 'DKDefenceMin') || C(battle, b, 'DKDefenceMax'))) m.defDK = [C(battle, b, 'DKDefenceMin'), C(battle, b, 'DKDefenceMax')];
    m.speed = d ? [round(d.walkSpeed), round(d.runSpeed)] : [C(csv, c, 'WalkSpeed'), C(csv, c, 'RunSpeed')];
    const width = d ? round(d.width) : C(csv, c, 'Width');
    if (width) m.width = width;
    m.material = d ? d.material : C(csv, c, 'Material');
    const src = b ? [battle, b] : c ? [csv, c] : null;
    if (src) {
      const [t, r] = src;
      const g = (a, bb) => C(t, r, t === battle ? a : bb);
      const guard = [g('GuardRate', 'GuardRate'), g('GuardEfficiency', 'GuardEfficiency')];
      if (guard[0] || guard[1]) m.guard = guard;
      if (g('BlockRate', 'BlockRate')) m.blockRate = g('BlockRate', 'BlockRate');
      if (g('Distance', 'Distance') !== 6) m.distance = g('Distance', 'Distance');
      const res = [g('PhysicalResist', 'PhysicalResist'), g('LightResist', 'LightResist'), g('FireResist', 'FireResist'), g('IceResist', 'IceResist'),
        g('PoisonResist', 'PoisonResist'), g('CurseResist', 'CurseResist'), g('DarkResist', 'DarkResist'), g('MagicResist', 'MagicResist')];
      if (res.some((x) => x)) m.resist = res;
      const other = { melee: g('MeleeDamageResist', 'MeleeDamageResist'), range: g('RangeDamageResist', 'RangeDamageResist'),
        antiStatus: g('AntiStatusRate', 'AntiStatusRate'), antiKnockBack: g('AntiKnockBackRate', 'AntiKnockBackRate') };
      if (t === battle) Object.assign(other, { competence: g('Competence'), destruction: g('Destruction'), critResist: g('CriticalRateResist'),
        physPen: g('PhysicsPenetrate'), magicPen: g('MagicPenetrate') });
      for (const k of Object.keys(other)) if (!other[k]) delete other[k];
      if (Object.keys(other).length) m.resistEx = other;
      const defeat = [g('DefeatLengthUpper', 'DefeatLength_Upper'), g('DefeatLengthLower', 'DefeatLength_Lower'), g('DefeatLengthLeft', 'DefeatLength_Left'),
        g('DefeatLengthRight', 'DefeatLength_Right'), g('DefeatDamageMin', 'DefeatDamage_Min'), g('DefeatDamageMax', 'DefeatDamage_Max')];
      if (defeat.some((x) => x)) m.defeat = defeat;
      const summon = [g('DwMinSummonsMonster', 'DwMinSummonsMonster'), g('DwMaxSummonsMonster', 'DwMaxSummonsMonster'), g('dwMaxSummonsMonsterRange', 'dwMaxSummonsMonsterRange')];
      if (summon.some((x) => x)) m.summon = summon;
      m.attacks = t === battle ? attackBlocks(battle.header, r, attackStartsBattle) : attackBlocks(csv.header, r, attackStartsCsv);
      if (t === battle) Object.assign(m.attacks, attackBlocks(battle.header, r, aggroStartsBattle));
      if (!Object.keys(m.attacks).length) delete m.attacks;
      if(m.sentry)m.attackResults=Object.fromEntries(Object.entries(m.attacks||{}).map(([key,block])=>[key,describeSentryResult(block[7],block.slice(8),sentryResultContext)]));
    }
    // ---- AI
    const aiKey = d ? d.aiKey : C(csv, c, 'AIKey');
    const beh = behaviour(aiKey);
    m.ai = { type: d ? d.aiType : C(csv, c, 'AI_Type'), pattern: aiKey, aggressive: beh.aggressive };
    if (ai) {
      const g = (k) => C(info, ai, k);
      Object.assign(m.ai, { explore: g('DwExploreRange'), sight: g('DwSight'), pursuit: g('DwPersuitRange'), avoid: g('DwAvoidRange') });
      const delays = [g('DwExploreStandDelay'), g('DwExploreMoveDelay'), g('DwStandDelay'), g('DwMoveDelay')];
      if (delays.join() !== '2000,2000,1200,1000') m.ai.delays = delays;
      // only the *Call patterns (4/5/6) call for help; the columns are filled for everyone else too
      if (beh.callTeam) m.ai.callTeam = [g('DwCallTeamPossibelHP'), g('DwCallTeamCount'), g('dwCallTeamCell')];
      const special = [g('dwSpecialAttackStartHP'), g('dwSpecialMeleeAttackRate'), g('dwSpecialRangeAttackRate'), g('dwSpecialAttackRate'), g('dwSpecialDelayTime')];
      if (special.slice(1).some((x) => x)) m.ai.special = special;
      const power = [g('DwPowerAttackStartHP'), g('dwPowerMeleeAttackProbable'), g('dwPowerRangeAttackProbable'), g('dwPowerRate'), g('dwPowerDelayTime')];
      if (power.slice(1).some((x) => x)) m.ai.power = power;
      const rates = [g('dwAttack1_Rate'), g('dwAttack2_Rate'), g('dwAttack3_Rate'), g('dwAttack4_Rate')];
      if (rates.some((x) => x)) m.ai.aggroRates = rates;
      if (g('dwFollowTarget')) m.ai.followTarget = g('dwFollowTarget');
      m.ai.patternType = g('PatternType');
      const summ = [g('dwMaxSummonsMonsterCount'), g('dwReSummonsMonsterTick'), g('dwMaxSummonsMonsterRange'), g('dwSummonsStartPcCount'), g('dwMaxSummonsMonsterLimit')];
      if (summ.some((x) => x)) m.ai.summons = summ;
      // every other info.csv column, raw, when non-zero (master follow/stop/warp ranges of summoned monsters, attack
      // target types/values, First/RepeatAttackIndex, EnterType, fAnimLength ...): nothing in the table is dropped
      const extra = {};
      info.header.forEach((h, i) => { if (!INFO_USED.has(h)) { const v = num(ai[i]); if (v) extra[h] = v; } });
      if (Object.keys(extra).length) m.ai.extra = extra;
    }
    // ---- flags
    const fl = d ? { target: d.target, damageType: d.damageType, isBlock: d.isBlock, deadEffect: d.deadEffect, blood: d.blood, cutting: d.cutting }
      : { target: C(csv, c, 'Target'), damageType: C(csv, c, 'DamageType'), isBlock: C(csv, c, 'IsBlock'), deadEffect: C(csv, c, 'DeadEffect'), blood: C(csv, c, 'BloodInfo'), cutting: C(csv, c, 'CuttingInfo') };
    const fa = trimZeros([fl.target, fl.damageType, fl.isBlock, fl.deadEffect, fl.blood, fl.cutting]);
    if (fa.some((x) => x)) m.flags = fa;
    if (d) {
      const unk = {};
      for (const k of ['unk144', 'unk2587', 'unk2607', 'unk2625']) if (d[k]) unk[k] = d[k];
      if (d.unk509 !== 1) unk.unk509 = d.unk509;
      if (d.unk2623 !== 1) unk.unk2623 = d.unk2623;
      if (Object.keys(unk).length) m.unk = unk;
    }
    // ---- money + drops
    m.money = d ? [d.moneyMin, d.moneyMax, d.moneyRate] : [C(csv, c, 'Money_Min'), C(csv, c, 'Money_Max'), C(csv, c, 'Money_Rate')];
    // scan fix A (M1/M2/M3, SCAN-A A1/A2): monsterdropitemtable.csv can hold several rows per Index keyed by CondName
    // (Kill, PREMIUM_N/PREMIUM_Y, 45_DropHellionStamp, Curse_BoxCurse_Gold/Dil, BoxCorridor_Gold/Dil, 701_MainBoss). The first
    // row stays the base drop (as before); its CondName is kept when it is not the default "Kill", and every later row is
    // emitted under drops.alt[] with its own CondName. ItemSetEx/FixItemSetEx blocks, GainLimitTime and PetPick are carried.
    const dropRowsAll = drop ? (dropRowsByIndex.get(idx) || []) : [];
    const dropFrom = (dr) => {
      const drops = {};
      const money = [];
      for (let k = 1; k <= 10; k++) {
        const g = (n) => C(drop, dr, `${n}_${k}`);
        const e = [g('MoneyCount_Min'), g('MoneyCount_Max'), g('Money_Min'), g('Money_Max'), g('Money_Rate')];
        if (e[4] > 0 && e[3] > 0) money.push(e);
      }
      const same = money.length === 1 && money[0][0] === 1 && money[0][1] === 1 && money[0][2] === m.money[0] && money[0][3] === m.money[1] && money[0][4] === m.money[2];
      if (money.length && !same) drops.money = money;
      const sets = [];
      for (let k = 1; k <= 15; k++) {
        const s = C(drop, dr, `ItemSetIndex_${k}`), ratio = C(drop, dr, `ItemSetDropRatio_${k}`);
        if (s > 0 && ratio > 0) { sets.push([s, ratio, C(drop, dr, `ItemSetSocket_${k}`)]); itemSetsUsed.add(s); }
      }
      if (sets.length) { drops.sets = sets; drops.maxSets = C(drop, dr, 'MaxItemSet'); }
      const fixed = [];
      for (let k = 1; k <= 10; k++) {
        const it = C(drop, dr, `Fix_ItemIndex_${k}`);
        if (it > 0) fixed.push([it, C(drop, dr, `Fix_ItemStack_${k}`), C(drop, dr, `Fix_ItemCountMin_${k}`), C(drop, dr, `Fix_ItemCountMax_${k}`)]);
      }
      if (fixed.length) drops.fixed = fixed;
      const fsets = [];
      for (let k = 1; k <= 10; k++) {
        const s = C(drop, dr, `Fix_ItemSet_${k}`);
        if (s > 0) { fsets.push([s, C(drop, dr, `Fix_ItemSetCountMin_${k}`), C(drop, dr, `Fix_ItemSetCountMax_${k}`), C(drop, dr, `Fix_ItemSetSocket_${k}`), C(drop, dr, `FixItemSetRatio_${k}`)]); itemSetsUsed.add(s); }
      }
      if (fsets.length) drops.fixedSets = fsets;
      const range = C(drop, dr, 'DropRange');
      if (range) drops.range = range;
      const setsEx = [];
      for (let k = 1; k <= 15; k++) {
        const s = C(drop, dr, `ItemSetExIndex_${k}`), ratio = C(drop, dr, `ItemSetExDropRatio_${k}`);
        if (s > 0 && ratio > 0) { setsEx.push([s, ratio, C(drop, dr, `ItemSetExSocket_${k}`)]); itemSetsExUsed.add(s); }
      }
      if (setsEx.length) { drops.setsEx = setsEx; drops.maxSetsEx = C(drop, dr, 'MaxItemSetEx'); }
      const fsetsEx = [];
      for (let k = 1; k <= 10; k++) {
        const s = C(drop, dr, `Fix_ItemSetEx_${k}`);
        if (s > 0) { fsetsEx.push([s, C(drop, dr, `Fix_ItemSetExCountMin_${k}`), C(drop, dr, `Fix_ItemSetExCountMax_${k}`), C(drop, dr, `Fix_ItemSetExSocket_${k}`), C(drop, dr, `FixItemSetExRatio_${k}`)]); itemSetsExUsed.add(s); }
      }
      if (fsetsEx.length) drops.fixedSetsEx = fsetsEx;
      const gainLimitTime = C(drop, dr, 'GainLimitTime');
      if (gainLimitTime) drops.gainLimitTime = gainLimitTime;
      // PetPick is 1 on almost every row; only the rows with 0 are marked (a pet must not auto-pick those drops)
      if (drop.col('PetPick') >= 0 && !C(drop, dr, 'PetPick')) drops.noPetPick = true;
      return drops;
    };
    const dr = dropRowsAll[0];
    if (dr) {
      const drops = dropFrom(dr);
      const cond = S(drop, dr, 'CondName');
      if (cond && cond !== 'Kill') drops.cond = cond;
      const alt = dropRowsAll.slice(1).map((r) => ({ cond: S(drop, r, 'CondName'), ...dropFrom(r) }));
      if (alt.length) drops.alt = alt;
      if (Object.keys(drops).length) m.drops = drops;
    } else if (c) {
      const sets = [];
      for (let k = 1; k <= 15; k++) {
        const s = C(csv, c, `ItemSetIndex_${k}`), ratio = C(csv, c, `ItemSetDropRatio_${k}`);
        if (s > 0 && ratio > 0) { sets.push([s, ratio, 0]); itemSetsUsed.add(s); }
      }
      if (sets.length) m.drops = { sets, maxSets: C(csv, c, 'MaxItemSet') };
    }
    // ---- visual: shape -> mesh/tpack/textures, action table -> skeleton + animations
    let shapeRow = shapesCsv.map.get(m.shape);
    let shapeFrom = 'monster_shape';
    if(sentryIds.has(idx)){shapeRow=sentryShapesCsv.map.get(m.shape);shapeFrom='sentry_shape';}
    if (!shapeRow && npcShapesCsv.map.get(m.shape)) { shapeRow = npcShapesCsv.map.get(m.shape); shapeFrom = 'npc_shape'; }
    let meshKey = null;
    if (shapeRow) {
      shapes.add(shapeRow);
      const sh = shapes.shapes[m.shape];
      meshKey = sh.mesh || null;
      if (shapeFrom !== 'monster_shape') sh.from = shapeFrom;
      if (snd && !sfxDone.has(m.shape)) { sfxDone.add(m.shape); const sfx = shapeSfx(snd, shapeRow.name); if (sfx) sh.sfx = sfx; }
    }
    const { table, how, skelOverride, coverage, replaced } = chooseTable(actions, sentryIds.has(idx)?'SENTRY':'MONSTER', idx, meshKey);
    actHow[how] = (actHow[how] || 0) + 1;
    if (table) {
      const id = sets.add(table, how === 'borrowed' ? `${table.src} (borrowed via skeleton name)` : undefined, { skelOverride });
      if (id) {
        m.act = id; if (how !== 'dat') m.actFrom = how;
        if (replaced) { m.actReplaced = replaced; fitStats.replaced.push(idx); }
        // the set's skeleton lacks some of this mesh's palette bones (client data defect, the client pairs them anyway):
        // those bones get an identity skin matrix, i.e. their vertices stay in bind pose (all of them when 1)
        if (coverage !== null && coverage < FIT_MIN_COVERAGE && sets.sets[id].skel) { m.skelMismatch = round(1 - coverage, 2); fitStats.mismatch.push(idx); }
        if (skelOverride) fitStats.override.push(idx);
      }
    }
    const cnt = spawnCount.get(idx);
    if (cnt) m.spawns = cnt;
    if (callCount.get(idx)) m.calls = callCount.get(idx);
    // ---- completeness.  strict = mesh + texture + skeleton that fits the mesh + idle/move/attack/die clips that
    // bind to that skeleton.
    // role-aware: 'invisible' shapes (no texture pack: trap / trigger volumes) need nothing drawable,
    // 'object' monsters (AI pattern 7 event / 13 trap: boxes, coffins, crystals, statues) never move or attack.
    const set = m.act ? sets.sets[m.act] : null;
    const st = set ? statesThatBind(set) : {};
    const sh = shapes.shapes[m.shape];
    const lacks = [];
    if (!sh) lacks.push('shape');
    else {
      if (!sh.mesh) lacks.push('mesh');
      if (!(sh.textures && sh.textures.diffuse && sh.textures.diffuse.some(Boolean))) lacks.push('texture');
    }
    if (!set) lacks.push('act');
    else if (!set.skel) lacks.push('skel');
    else if (m.skelMismatch && isDeformable(meshKey)) lacks.push('skelFit'); // rigid 1-bone props just stay static
    if (!(st.idle >= 0)) lacks.push('idle');
    if (!(st.walk >= 0 || st.run >= 0)) lacks.push('move');
    if (!(st.attack && st.attack.length)) lacks.push('attack');
    if (!(st.die >= 0)) lacks.push('die');
    // an empty *_none body whose every authored action effect draws the real body mesh (src/game/effect-body.js) is a
    // fighting monster seen only through those effects (Ghostman_knight 3810 / Ghostman_archer 3813), not a trap volume
    const effectBody = sh && sh.invisible && set ? classifyEffectBody({ shapeMesh: sh.mesh, shapeTpack: sh.tpack, clips: set.clips, ...effectBodyIndex() }) : null;
    if (effectBody) { Object.assign(m, effectBody); (REPORT.effectBodies ||= []).push(Number(idx)); }
    m.role = effectBody ? 'creature' : sh && sh.invisible ? 'invisible' : (beh.style === 'none' || beh.style === 'trap') ? 'object' : 'creature';
    if (lacks.length) m.lacks = lacks;
    const need = effectBody ? ['shape', 'mesh', 'act', 'skel', 'skelFit', 'idle', 'move', 'attack', 'die']
      : m.role === 'invisible' ? ['shape', 'mesh']
      : m.role === 'object' ? ['shape', 'mesh', 'texture', ...(set && set.clips.length ? ['skel', 'skelFit', 'idle'] : [])]
        : ['shape', 'mesh', 'texture', 'act', 'skel', 'skelFit', 'idle', 'move', 'attack', 'die'];
    m.ok = !lacks.some((l) => need.includes(l));
    monsters[idx] = m;
  }
  REPORT.actionSetSource = actHow;
  REPORT.skeletonFit = { overridden: fitStats.override, replacedByConvention: fitStats.replaced, mismatch: fitStats.mismatch, note: SKELFIT_NOTE };
  log(`skeleton fit: ${fitStats.override.length} monsters use a skeleton override, ${fitStats.replaced.length} a mesh-named convention set, ${fitStats.mismatch.length} keep a table skeleton that does not fit their mesh`);

  // ------------------------------------------------ per-clip sounds
  if (snd) for (const s of Object.values(sets.sets)) { const x = clipSfx(snd, s); if (x) s.sfx = x; }

  // ------------------------------------------------ item sets + item names (only those referenced by drops)
  // plus native set 4852 "guild dungeon lever item", which the Dead Island host
  // run drops from its wave monsters (ENGINE-CHOSEN binding; no Global monster lists it).
  itemSetsUsed.add(DEAD_ISLAND_IGNITER_SET);
  const itemSets = {};
  const itemSetsEx = {};
  const itemNames = {};
  if (existsRel('share/item/itemset.csv')) {
    const t = loadTable('share/item/itemset.csv');
    const itemsUsed = new Set();
    for (const m of Object.values(monsters)) for (const d of [m.drops, ...(m.drops?.alt || [])]) for (const f of d?.fixed || []) itemsUsed.add(f[0]);
    for (const m of Object.values(monsters)) for (const a of m.drops?.alt || []) { for (const x of a.sets || []) itemSetsUsed.add(x[0]); for (const x of a.fixedSets || []) itemSetsUsed.add(x[0]); }
    for (const s of itemSetsUsed) {
      const r = t.byIndex.get(s);
      if (!r) continue;
      const n = num(r[3]);
      const items = [];
      for (let k = 0; k < n; k++) {
        const base = 4 + k * 5;
        const it = num(r[base]);
        if (it > 0) { items.push([it, num(r[base + 1]), num(r[base + 2]), num(r[base + 3]), num(r[base + 4])]); itemsUsed.add(it); }
      }
      itemSets[s] = { name: kr(String(r[1] ?? '').trim()), total: num(r[2]), items };
    }
    // scan fix A (A2): ItemSetEx sets referenced by drop rows - share/item/itemsetex.csv rows (SetExIndex, GroupId, Name,
    // DropRatio, then 15 x [ItemIndex, MagicRatio/Drop_Stack_Min, NobleRatio/Drop_Stack_Max, DivineNobleRatio]) plus the
    // group weight of share/item/itemsetexgroup.csv (SetExIndex, GroupId, Name, DropRatio). Same shape as boxes.json itemSetsEx.
    if (itemSetsExUsed.size && existsRel('share/item/itemsetex.csv')) {
      const gr = new Map();
      if (existsRel('share/item/itemsetexgroup.csv')) for (const r of parseCSV(readText('share/item/itemsetexgroup.csv')).slice(1)) if (r && /^\d+$/.test(String(r[0]).trim())) gr.set(`${num(r[0])}:${num(r[1])}`, num(r[3]));
      for (const r of parseCSV(readText('share/item/itemsetex.csv')).slice(1)) {
        if (!r || !/^\d+$/.test(String(r[0]).trim())) continue;
        const id = num(r[0]); if (!itemSetsExUsed.has(id)) continue;
        const e = []; for (let k = 4; k + 3 < r.length; k += 4) { const it = num(r[k]); if (it) { e.push([it, num(r[k + 1]), num(r[k + 2]), num(r[k + 3])]); itemsUsed.add(it); } }
        (itemSetsEx[id] ||= { groups: [] }).groups.push({ g: num(r[1]), n: kr(String(r[2] || '').trim()), ratio: num(r[3]), groupRatio: gr.get(`${id}:${num(r[1])}`) ?? null, e });
      }
      for (const s of itemSetsExUsed) if (!itemSetsEx[s]) soft(`drop table references ItemSetEx ${s} missing from itemsetex.csv`);
    }
    for (const f of ['itemweapon.csv', 'itemarmor.csv', 'itemaccessory.csv', 'itemetc.csv', 'itemetc_socket.csv', 'itemcash.csv', 'itemmileage.csv']) {
      if (!existsRel(`share/item/${f}`)) continue;
      const rows = parseCSV(readText(`share/item/${f}`));
      for (let i = 1; i < rows.length; i++) {
        const r = rows[i]; if (!r || r.length < 2) continue;
        const k = String(r[0]).trim(); if (!/^\d+$/.test(k)) continue;
        if (itemsUsed.has(+k) && !(k in itemNames)) itemNames[k] = kr(String(r[1] ?? '').trim());
      }
    }
    for (const it of itemsUsed) if (!(it in itemNames)) itemNames[it] = null;
  }

  // ------------------------------------------------ coverage over every monster referenced by a spawn table
  const spawned = [...spawnCount.keys()].sort((a, b) => a - b);
  let strict = 0, roleOk = 0, derivedUsed = 0;
  const incomplete = [];
  const lackCount = {};
  const roles = {};
  for (const i of spawned) {
    const m = monsters[i];
    if (!m) { incomplete.push({ index: i, lacks: ['monster-record'], ok: false }); lackCount['monster-record'] = (lackCount['monster-record'] || 0) + 1; continue; }
    roles[m.role] = (roles[m.role] || 0) + 1;
    if (m.act && sets.sets[m.act].derived) derivedUsed++;
    if (!m.lacks) strict++;
    if (m.ok) roleOk++;
    if (m.lacks) {
      incomplete.push({ index: i, name: m.name, shape: m.shape, role: m.role, ok: m.ok, lacks: m.lacks, act: m.act || null, spawnRows: m.spawns });
      for (const l of m.lacks) lackCount[l] = (lackCount[l] || 0) + 1;
    }
  }
  const pct = (x) => (spawned.length ? round(100 * x / spawned.length, 2) : 0);
  log(`coverage over ${spawned.length} spawned monsters: strict (mesh+skel+idle/move/attack/die+texture) ${strict} = ${pct(strict)}%, ` +
    `role-aware ${roleOk} = ${pct(roleOk)}%  roles ${JSON.stringify(roles)}  lacks ${JSON.stringify(lackCount)}  (${derivedUsed} use back-filled states)`);
  const creatures = spawned.filter((i) => monsters[i]?.role === 'creature');
  const creatureStrict = creatures.filter((i) => !monsters[i].lacks).length;
  log(`  creatures only: strict ${creatureStrict}/${creatures.length} = ${round(100 * creatureStrict / Math.max(1, creatures.length), 2)}%`);
  const called = [...callCount.keys()].filter((i) => !spawnCount.has(i));
  const calledOk = called.filter((i) => monsters[i]?.ok).length;
  log(`  monsters only reachable through call-monster tables: ${called.length}, role-aware complete ${calledOk}`);
  REPORT.coverage = { spawnedMonsters: spawned.length, strictComplete: strict, strictPercent: pct(strict), roleAwareComplete: roleOk,
    roleAwarePercent: pct(roleOk), creatureStrict: `${creatureStrict}/${creatures.length}`, roles, lackCounts: lackCount, usingBackfilledStates: derivedUsed,
    callOnlyMonsters: called.length, callOnlyRoleAwareComplete: calledOk,
    callOnlyIncomplete: called.filter((i) => !monsters[i]?.ok).map((i) => ({ index: i, name: monsters[i]?.name, lacks: monsters[i]?.lacks || ['monster-record'] })),
    incomplete };
  REPORT.shapes = { monsterShapeRows: shapesCsv.map.size, duplicates: shapesCsv.dups, missing: shapes.missing };
  REPORT.missingAnimFiles = [...sets.missingAnims].sort();
  REPORT.spawnFiles = { total: Object.keys(spawnFiles).length, rows: spawnRows, boundToMaps: Object.keys(spawns).length,
    maplistPathsMissing: missingSpawnFiles, notInMaplist: [...unboundSpawnFiles].sort(), editorMonsterLists: editorLists.sort() };
  REPORT.callSpawnFiles = { nonEmpty: Object.keys(callSpawns).length, of: callFiles.length,
    boundByMaplist: Object.values(callSpawns).filter((e) => e.maps).length, ownMapIndexDisagreesWithMaplist: callHeaderDisagrees,
    maplistPathsMissing: callPathsMissing, notInMaplist: Object.keys(callSpawns).filter((k) => !callSpawns[k].maps) };
  REPORT.actionTables = actionStatsJson(actions, 'MONSTER');
  for (const s of shapes.missing.mesh) soft(`monster shape mesh missing: ${s}`);
  for (const s of shapes.missing.tpack) soft(`monster shape tpack missing: ${s}`);

  // ------------------------------------------------ assemble
  const ranks = {};
  if (rankTab.length > 1) {
    const hdr = rankTab[0];
    for (let c = 1; c < hdr.length; c++) {
      const o = {};
      for (let r = 1; r < rankTab.length; r++) if (rankTab[r] && rankTab[r][0]) o[String(rankTab[r][0]).trim()] = num(rankTab[r][c]);
      ranks[String(hdr[c]).trim()] = o;
    }
  }
  const patterns = {};
  for (const [k, r] of patternTab.byIndex) patterns[k] = { file: String(r[1] ?? '').trim(), ...behaviour(k) };

  return {
    format: 'dekaron-solo/monsters@1',
    generatedBy: 'tools/build-monsters.mjs',
    doc: 'docs/formats/monsters.md',
    units: UNITS,
    clipFields: CLIP_FIELDS,
    actionCodes: ACTION_CODES,
    actionCodesVerified: Object.keys(actions.verifiedCodes),
    attackFields: ['min', 'max', 'absMin', 'absMax', 'range', 'delay', 'material', 'resultCode', 'v1', 'v2', 'v3', 'v4', 'v5', 'v6', 'v7'],
    attackActionIndex: Object.fromEntries([...ATTACK_TYPES, ...AGGRO_ATTACKS].map((t, i) => [t, i])),
    flagFields: ['target', 'damageType', 'isBlock', 'deadEffect', 'blood', 'cutting'],
    defaults: { hpRegen: 0, width: 0, distance: 6, guard: [0, 0], blockRate: 0, 'ai.delays': [2000, 2000, 1200, 1000], flags: [0, 0, 0, 0, 0, 0] },
    aiPatterns: patterns,
    ranks,
    shapes: shapes.shapes,
    actionSets: sets.sets,
    monsters,
    itemSets,
    itemSetsEx,
    itemNames,
    spawns,
    callSpawnFields: ['callIndex', 'monster', 'x', 'y', 'cell (scatter radius, cells)', 'count'],
    randomCallFields: ['randCallIndex', 'monster', 'count', 'posIndex (-> randomPositions[i][0])'],
    randomPositionFields: ['randPosIndex', 'x', 'y', 'cell (scatter radius, cells)'],
    callSpawns,
    // MON_*.csv files that neither map list references (retired / instanced variants); keyed by file,
    // folderIndex = the number the folder name starts with (a hint only, not authoritative)
    unboundSpawns: Object.fromEntries([...unboundSpawnFiles].sort().filter((k) => spawnFiles[k].length).map((k) => {
      const f = k.split('/').slice(-2, -1)[0] || '';
      return [k, { folderIndex: /^\d+/.test(f) ? parseInt(f, 10) : null, rows: spawnFiles[k] }];
    })),
    report: REPORT,
  };
}

const UNITS = {
  position: 'map cells (1 cell = 1 world unit, coords.md); spawn/call x,y = integer cell (file-frame column X, row Z): stand at the cell centre, three.js (x+0.5, h, -(y+0.5)); NPC x,y = continuous file-frame X,Z: three.js (x, h, -y)',
  speed: 'cells per second (walk, run) — same scale as share/pc/pcclass.csv Speed_WALK = 2.5 for players',
  width: 'cells (body size used for cell blocking; 0 = one cell)',
  'attack.range / ai.sight / ai.explore / ai.pursuit / ai.avoid / ai.callTeam[2]': 'cells',
  'attack.delay / ai.delays / clip cancelTime / ai.special[4] / ai.power[4]': 'milliseconds',
  'clip timeLength': 'seconds (playback length of the normalised 0..1 anim; 0 in the table -> estimated, listed in actionSets[..].timeLengthEstimated)',
  'clip timing / timing2': 'fraction of timeLength (hit moment / end of hit window); 2 shipped attack rows exceed 1: clamp to 1',
  'money[2], drops.money[i][4], drops.sets[i][1], itemSets.*.items[i][1]': 'probability per 100000',
  regenSeconds: 'spawn row column 2 (seconds; 60000 / 65534 = effectively never)',
  hp: 'hit points', exp: 'experience points', def: '[min, max] defence',
};
const SKELFIT_NOTE = 'overridden: the table skeleton does not cover the mesh palette; the skeleton named after the mesh does and drives the table clips at least as well (set.skelFromTable = original). ' +
  'replacedByConvention: deformable mesh, no such override; the mesh-named skel/<mesh>.skel + anim/<mesh>*.anim fit, so they replace the table (m.actReplaced = table src). ' +
  'mismatch: neither; m.skelMismatch = fraction of mesh palette bones missing from set.skel -> identity skin matrix (bind pose) for those bones (rigid 1-bone props: the whole prop stays static, which is harmless)';
const CLIP_FIELDS = ['anim', 'timeLength', 'startInter', 'endInter', 'timing', 'split', 'timing2', 'effect', 'cancelTime', 'swing', 'strike', 'freeze',
  'defaultAction', 'intersect', 'through']; // trailing zero fields are trimmed from each clip array

function actionStatsJson(actions, kind) {
  const st = actions.stats[kind];
  return { datFiles: st.datFiles, datRecords: st.datRecords, datIndices: actions[kind].dat.size, csvFiles: st.csvFiles, csvRecords: st.csvRecords,
    csvIndices: actions[kind].csv.size, twins: st.pairs, identicalTwins: st.pairsAgree, nonFiniteFloats: st.nonFinite,
    unknownDatCodes: Object.fromEntries(st.datUnknownCodes), unknownCsvNames: Object.fromEntries(st.csvUnknownNames),
    csvVsDatFieldAgreement: Object.fromEntries(Object.entries(st.fieldAgree).map(([k, [n, ok]]) => [k, `${ok}/${n}`])) };
}

// ================================================================================================
// map index -> spawn / NPC placement tables.  share/maplist.csv (client: name + .map file) is merged with
// share/server/maplist.csv (server: MonsterLocatePath / NPCLocatePath, also lists retired maps such as
// 1 North Ares / 2 Norak that the client list dropped). Paths are "..\Share\Map\..." relative to share/.
// ================================================================================================
let MAP_BINDINGS = null;
function mapBindings() {
  if (MAP_BINDINGS) return MAP_BINDINGS;
  const shareKey = (p) => (p && !/<</.test(p) ? dataKey('share', p.replace(/^(\.\.[\\/])+/, '').replace(/^share[\\/]/i, '')) : null);
  const byIdx = new Map();
  const cl = loadTable('share/maplist.csv');
  const g = (t, r, n) => { const i = t.col(n); return i < 0 ? '' : String(r[i] ?? '').trim(); };
  for (const [mi, r] of cl.byIndex) {
    byIdx.set(mi, { index: mi, name: g(cl, r, 'Name'), mapFile: g(cl, r, 'MapFile').toLowerCase() || null, from: 'client',
      mon: [shareKey(g(cl, r, 'MonsterLocatePath'))].filter(Boolean),
      // Scan fix A (SCAN-B I2): PosFile is only a fallback for a NAMED NPCLocatePath. A row with an empty NPCLocatePath binds
      // no NPCs in Global (map 715 "Egutt (test)", share/maplist.csv:295, would otherwise copy map 67's 8 NPCs).
      // Owner rule (never remove content): the PosFile binding is KEPT by default and labelled (npcPosFileOnly);
      // set DEKARON_POSFILE_NPC_FALLBACK=0 for the Global reading (no NPCs on 715).
      npcPosFileOnly: !g(cl, r, 'NPCLocatePath') && !!g(cl, r, 'PosFile'),
      npc: (g(cl, r, 'NPCLocatePath') || process.env.DEKARON_POSFILE_NPC_FALLBACK !== '0') ? [shareKey(g(cl, r, 'NPCLocatePath')), g(cl, r, 'PosFile') ? dataKey('share', g(cl, r, 'PosFile')) : null].filter(Boolean) : [],
      call: [shareKey(g(cl, r, 'CallMonsterPath'))].filter((k) => k && !/^share\/0$/.test(k)) });
  }
  if (existsRel('share/server/maplist.csv')) {
    const sv = loadTable('share/server/maplist.csv');
    for (const [mi, r] of sv.byIndex) {
      const mon = shareKey(g(sv, r, 'MonsterLocatePath')), npc = shareKey(g(sv, r, 'NPCLocatePath'));
      let e = byIdx.get(mi);
      if (!e) {
        const folder = (mon || npc || '').split('/').slice(-2, -1)[0] || '';
        e = { index: mi, name: folder.replace(/^\d+_/, '').replace(/_/g, ' '), mapFile: null, from: 'server', mon: [], npc: [], call: [] };
        byIdx.set(mi, e);
      }
      if (mon && !e.mon.includes(mon)) e.mon.push(mon);
      if (npc && !e.npc.includes(npc)) e.npc.push(npc);
    }
  }
  MAP_BINDINGS = [...byIdx.values()].sort((a, b) => a.index - b.index);
  return MAP_BINDINGS;
}

// ================================================================================================
// NPCS
// ================================================================================================
function buildNpcs({ actions }) {
  const REPORT = {};
  const npc = loadTable('share/creature/npc.csv');
  const shapesCsv = loadShapeTable('script/shape/npc_shape.csv');
  const monShapesCsv = loadShapeTable('script/shape/monster_shape.csv');
  const jobs = {};
  if (existsRel('share/creature/jobtypeconfig.csv')) {
    const t = loadTable('share/creature/jobtypeconfig.csv');
    for (const [k, r] of t.byIndex) {
      const d = String(r[1] ?? '');
      // "SHOP<korean>", "GUILDMARK  10  <korean>", "SKILLMASTERSkillMaster": leading upper-case identifier
      const m = /^\s*([A-Z_][A-Z0-9_]*)([a-z])?/.exec(d);
      const name = m ? (m[2] ? m[1].slice(0, -1) : m[1]) : '';
      jobs[k] = { name: name || `JOB_${k}`, battleOk: num(r[2]), chaoticOk: num(r[3]) };
    }
  }
  const shapes = new ShapeRegistry('npc');
  const sets = new ActionSetRegistry(actions);
  const C = (row, name) => { const i = npc.col(name); return i < 0 ? 0 : num(row[i]); };
  const S = (row, name) => { const i = npc.col(name); return i < 0 ? '' : String(row[i] ?? '').trim(); };
  const out = {};
  const actHow = {};
  const fitStats = { override: [], mismatch: [], replaced: [] };
  for (const [idx, r] of [...npc.byIndex].sort((a, b) => a[0] - b[0])) {
    const n = { name: kr(S(r, 'Name')), shape: S(r, 'Shape').toLowerCase() };
    n.desc = C(r, 'Desc');
    n.mapVisible = C(r, 'MapVisible'); n.nameVisible = C(r, 'NameVisible'); n.minimapColor = C(r, 'Minimapcolor');
    n.comm = C(r, 'CommTableIndex');
    const jl = [];
    for (let k = 1; k <= 20; k++) { const t = C(r, `JobType${k}`), j = C(r, `JobIndex${k}`); if (t || j) jl.push([t, j]); }
    // JobCount is the number of meaningful entries; job type 0 (SHOP) with index 0 is padding
    const jc = C(r, 'JobCount');
    const jobsUsed = jl.slice(0, Math.max(jc, jl.filter(([t, j]) => t || j).length));
    if (jobsUsed.length) { n.jobs = jobsUsed; n.roles = [...new Set(jobsUsed.map(([t]) => jobs[t]?.name || `JOB_${t}`))]; }
    let row = shapesCsv.map.get(n.shape), from = 'npc_shape';
    if (!row && monShapesCsv.map.get(n.shape)) { row = monShapesCsv.map.get(n.shape); from = 'monster_shape'; }
    let meshKey = null;
    if (row) {
      shapes.add(row);
      meshKey = shapes.shapes[n.shape].mesh;
      if (from !== 'npc_shape') shapes.shapes[n.shape].from = from;
    }
    const { table, how, skelOverride, coverage, replaced } = chooseTable(actions, 'NPC', idx, meshKey);
    actHow[how] = (actHow[how] || 0) + 1;
    if (table) {
      const id = sets.add(table, how === 'borrowed' ? `${table.src} (borrowed via skeleton name)` : undefined, { skelOverride });
      if (id) {
        n.act = id; if (how !== 'dat') n.actFrom = how;
        if (replaced) { n.actReplaced = replaced; fitStats.replaced.push(idx); }
        if (coverage !== null && coverage < FIT_MIN_COVERAGE && sets.sets[id].skel) { n.skelMismatch = round(1 - coverage, 2); fitStats.mismatch.push(idx); }
        if (skelOverride) fitStats.override.push(idx);
      }
    }
    const lacks = [];
    const sh = shapes.shapes[n.shape];
    if (!sh) lacks.push('shape'); else { if (!sh.mesh) lacks.push('mesh'); if (!sh.invisible && !(sh.textures?.diffuse?.some(Boolean))) lacks.push('texture'); }
    if (n.act) {
      const s = sets.sets[n.act];
      if (!s.skel) lacks.push('skel'); else if (n.skelMismatch && !sh?.invisible && isDeformable(meshKey)) lacks.push('skelFit');
      if (!(statesThatBind(s).idle >= 0)) lacks.push('idle');
    }
    else n.static = true; // no skeleton/animation anywhere: render the mesh as a static prop
    if (lacks.length) n.lacks = lacks;
    out[idx] = n;
  }
  // ---- placements
  const placements = {};
  const placed = new Map();
  const missingFiles = [];
  for (const mb of mapBindings()) {
    if (!mb.npc.length) continue;
    const key = mb.npc.find((k) => has(k));
    if (!key) { missingFiles.push(`${mb.index} ${mb.name}: ${mb.npc[0]}`); continue; }
    const pl = parseNpcPlacementCsv(readRel(key));
    placements[mb.index] = { name: mb.name, map: mb.mapFile, file: key,
      rows: pl.rows.map((q) => [q.npc, q.x, q.y, q.dir, q.warpX, q.warpY, q.isEvent, /^-?\d+$/.test(q.desc) ? +q.desc : q.desc]) };
    if (mb.from !== 'client') placements[mb.index].from = mb.from;
    if (mb.npcPosFileOnly) placements[mb.index].note = 'not bound by Global (kept per owner rule)';
    for (const q of pl.rows) placed.set(q.npc, (placed.get(q.npc) || 0) + 1);
  }
  // Folder-convention: bind unbound NPC_ files and replace cross-map misbinds (share/map/<index>_*/npc_*.csv).
  // Only maplist/synthesised-referenced folders (orphan folders never load in Global; LANE-50).
  const REF_NPC_FOLDERS = referencedMapFolders(DATA);
  let folderNpcAdds = 0, folderNpcReplaces = 0;
  const byFolderNpc = new Map();
  for (const f of FILES) {
    const m = String(f).match(/^share\/map\/(\d+)_[^/]+\/(npc_[^/]+\.csv)$/i);
    if (!m || (REF_NPC_FOLDERS && !REF_NPC_FOLDERS.has(String(f).split('/')[2].toLowerCase()))) continue;
    const mapIdx = +m[1];
    const prev = byFolderNpc.get(mapIdx);
    const low = m[2].toLowerCase();
    const nameHit = low.includes('_' + mapIdx + '_') || low.startsWith('npc_' + mapIdx + '_') || low.startsWith('npc_' + String(mapIdx).padStart(2, '0') + '_');
    if (!prev || (nameHit && !prev.nameHit)) byFolderNpc.set(mapIdx, { file: f, nameHit: !!nameHit });
  }
  for (const [mapIdx, t] of byFolderNpc) {
    const cur = placements[mapIdx];
    const curFolder = cur?.file && Number((String(cur.file).match(/^share\/map\/(\d+)_/i) || [])[1]);
    if (cur && curFolder === mapIdx) continue;
    // Scan fix A (SCAN-B I3): same file name as the maplist NPCLocatePath (map 31: 31_infinitehunt_c/npc_24_infinitehunt.csv vs
    // Global share/maplist.csv:26 ..\Share\Map\24_Infinitehunt\NPC_24_Infinitehunt.csv) is a copy, not a misbind: keep Global's path.
    if (cur && String(cur.file).split('/').pop().toLowerCase() === String(t.file).split('/').pop().toLowerCase()) continue;
    if (!has(t.file)) continue;
    const plFolder = parseNpcPlacementCsv(readRel(t.file));
    if (cur) folderNpcReplaces++; else folderNpcAdds++;
    const dirName = t.file.split('/')[2].replace(/^\d+_/, '').replace(/_/g, ' ');
    placements[mapIdx] = { name: cur?.name || dirName, map: cur?.map || null, file: t.file,
      rows: plFolder.rows.map((q) => [q.npc, q.x, q.y, q.dir, q.warpX, q.warpY, q.isEvent, /^-?\d+$/.test(q.desc) ? +q.desc : q.desc]), from: 'folder' };
    for (const q of plFolder.rows) placed.set(q.npc, (placed.get(q.npc) || 0) + 1);
  }
  if (folderNpcAdds || folderNpcReplaces) log(`NPC folder binds: +${folderNpcAdds} added, ~${folderNpcReplaces} replaced`);
  let placedOk = 0; const placedMiss = [];
  for (const [i] of placed) {
    const n = out[i];
    if (!n) { placedMiss.push({ index: i, lacks: ['npc-record'] }); continue; }
    n.placements = placed.get(i);
    if (!n.lacks) placedOk++; else placedMiss.push({ index: i, name: n.name, shape: n.shape, lacks: n.lacks, static: !!n.static });
  }
  log(`NPCs: ${npc.byIndex.size} rows; placements on ${Object.keys(placements).length} maps, ${placed.size} distinct placed NPCs; ` +
    `${placedOk} fully resolved; action set source ${JSON.stringify(actHow)}`);
  REPORT.placedCoverage = { placed: placed.size, complete: placedOk, percent: round(100 * placedOk / Math.max(1, placed.size), 2), incomplete: placedMiss };
  REPORT.placementFilesMissing = missingFiles;
  REPORT.actionSetSource = actHow;
  REPORT.skeletonFit = { overridden: fitStats.override, replacedByConvention: fitStats.replaced, mismatch: fitStats.mismatch, note: SKELFIT_NOTE };
  log(`NPC skeleton fit: ${fitStats.override.length} use a skeleton override, ${fitStats.replaced.length} a mesh-named convention set, ${fitStats.mismatch.length} keep a table skeleton that does not fit their mesh`);
  REPORT.shapes = { rows: shapesCsv.map.size, missing: shapes.missing };
  REPORT.missingAnimFiles = [...sets.missingAnims].sort();
  REPORT.actionTables = actionStatsJson(actions, 'NPC');
  return {
    format: 'dekaron-solo/npcs@1',
    generatedBy: 'tools/build-monsters.mjs',
    doc: 'docs/formats/monsters.md',
    units: { position: UNITS.position, dir: 'degrees (raw from NPC_*.csv, file frame; three.js rotation.y = -dir*PI/180 for Z-mirrored meshes)' },
    clipFields: CLIP_FIELDS,
    actionCodes: ACTION_CODES,
    placementFields: ['npc', 'x', 'y', 'dir', 'warpX', 'warpY', 'isEvent', 'desc'],
    jobTypes: jobs,
    shapes: shapes.shapes,
    actionSets: sets.sets,
    npcs: out,
    placements,
    report: REPORT,
  };
}

// run only when executed directly (the parse* exports can be imported without side effects)
if (process.argv[1] && path.resolve(process.argv[1]) === fileURLToPath(import.meta.url)) main();
