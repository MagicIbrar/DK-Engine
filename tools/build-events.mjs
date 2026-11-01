#!/usr/bin/env node
// Dekaron Solo — event / battleground database builder (Dead Front, Ice Castle, Colosseum, Infinite Battle,
// party-match arenas, battle royale, siege, battlefields, guild-war hunting, forgotten shipwreck, field boss ...).
//
//   node tools/build-events.mjs [--data <unpacked data root>] [--out <dir>] [--pretty] [--quiet]
//
// Writes
//   gamedata/events.json        modes (rules, schedules, phases, tiers, objectives, scoring, rewards, solo rulesets),
//                               every event map (maplist row, files, NPC / brick / call-monster placements, dialog trees),
//                               referenced NPCs / monsters / bricks (+ visuals) / items / statuses
//   gamedata/events_text.json   English message tables of the event maps (lines_eu), parsed markup, developer notes
//   gamedata/events_caps.json   level-cap (exp by level difference) and ability-cap tables used by the event maps
// Every asset path in the output is a lower-case data key (fetch /data/<key>) verified to exist on disk.
// The run doubles as the validator: cross references (maps, NPCs, monsters, bricks, items, statuses, files) are
// checked and a summary is printed; exit code 1 on hard failures.  Documentation: docs/formats/events.md

import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { BinReader, parseCSV } from '../src/formats/binreader.js';
import { parseNpcCSV, parseBrickCSV, parseCallMonsterCSV, parseLocationCSV, mapDataPaths } from '../src/formats/spawn.js';
import { parseMonsterDat, parseActDat, parseActCsv, parseTpackText, ACTION_CODES } from './build-monsters.mjs';
import { parseMac, nearestWalkable } from '../src/formats/mac.js';
import {compileSiegeDeployMask} from './lib/siege-renew-deploy-mask.mjs';

// ------------------------------------------------------------------------------------------------ setup
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
const seenMsg = new Set();
const hard = (m) => { if (!seenMsg.has(m)) { seenMsg.add(m); problems.hard.push(m); } };
const soft = (m) => { if (!seenMsg.has(m)) { seenMsg.add(m); problems.soft.push(m); } };

const euckr = new TextDecoder('euc-kr');
const utf16 = new TextDecoder('utf-16le');
const readRel = (rel) => fs.readFileSync(path.join(DATA, rel));
const existsRel = (rel) => { try { return fs.statSync(path.join(DATA, rel)).isFile(); } catch { return false; } };
/** CSV / text files: EUC-KR (CP949) is a superset of ASCII; UTF-16/UTF-8 BOMs honoured. */
function textRel(rel) {
  const b = readRel(rel);
  if (b[0] === 0xff && b[1] === 0xfe) return utf16.decode(b.subarray(2));
  if (b[0] === 0xef && b[1] === 0xbb && b[2] === 0xbf) return new TextDecoder('utf-8').decode(b.subarray(3));
  return euckr.decode(b);
}
const csvRel = (rel) => parseCSV(textRel(rel)).map((r) => (r || []).map((c) => String(c ?? '').trim()));
const num = (v, d = 0) => { const x = Number(String(v ?? '').trim()); return Number.isFinite(x) && String(v ?? '').trim() !== '' ? x : d; };
const numN = (v) => { const s = String(v ?? '').trim(); if (s === '') return null; const x = Number(s); return Number.isFinite(x) ? x : null; };
const r3 = (x) => (Number.isFinite(x) ? Math.round(x * 1000) / 1000 : x);
const uniq = (a) => [...new Set(a)];
const hasHangul = (s) => /[ㄱ-ㆎ가-힣]/.test(String(s || ''));

// ------------------------------------------------------------------------------------------------ file index
const FILES = new Set();
const BY_BASENAME = new Map();
function indexDir(sub) {
  const root = path.join(DATA, sub);
  if (!fs.existsSync(root)) { hard(`missing data folder ${sub}`); return; }
  for (const d of fs.readdirSync(root, { recursive: true, withFileTypes: true })) {
    if (!d.isFile()) continue;
    const key = path.relative(DATA, path.join(d.parentPath ?? d.path, d.name)).replace(/\\/g, '/').toLowerCase();
    FILES.add(key);
    const b = key.slice(key.lastIndexOf('/') + 1);
    if (!BY_BASENAME.has(b)) BY_BASENAME.set(b, []);
    BY_BASENAME.get(b).push(key);
  }
}
const has = (k) => !!k && FILES.has(k);
/** Game path under a type root -> existing data key (exact, then unique basename under the same root). */
function resolveKey(root, gamePath) {
  let n = String(gamePath ?? '').trim().replace(/\\/g, '/').replace(/\/{2,}/g, '/').replace(/^(\.\.?\/)+/, '').replace(/^\/+/, '').toLowerCase();
  if (!n) return null;
  const want = n.startsWith(root + '/') ? n : `${root}/${n}`;
  if (has(want)) return want;
  const b = want.slice(want.lastIndexOf('/') + 1);
  const alts = (BY_BASENAME.get(b) || []).filter((k) => k.startsWith(root + '/'));
  return alts.length ? alts[0] : null;
}
const EMITTED_KEYS = new Set();
/** register an asset key for the final existence check; returns the key (or null). */
const K = (k) => { if (k) EMITTED_KEYS.add(k); return k || null; };
const keyIf = (k) => (has(k) ? K(k) : null);

// ------------------------------------------------------------------------------------------------ localisation
/**
 * script/lines_eu — full parse (txt + csv keys).  Keys:
 *   txt: "TT|<file>#<cate>|<code>"        (TT = table type, 00 normal, 06 map-scoped dungeon tables, 08/09 party war ...)
 *   csv: "<folder>#<file>#<column>|<row>"  (row = 1-based data row of the csv, column 0-based)
 */
function parseLinesEuFull(buf) {
  const r = new BinReader(buf);
  const wstr = (n) => utf16.decode(r.bytes(n * 2));
  const readIndex = () => { const n = r.u32(); const files = []; for (let i = 0; i < n; i++) { const name = wstr(r.u32()); const c = r.u32(); const cols = []; for (let k = 0; k < c; k++) cols.push([r.i32(), r.i32()]); files.push({ name, cols }); } return files; };
  const txtFiles = readIndex();
  const csvFiles = readIndex();
  const nStr = r.u32();
  const strings = new Map();
  for (let i = 0; i < nStr; i++) { const id = r.u32(); strings.set(id, wstr(r.u32())); }
  const keys = new Map();
  let nTxt = 0, nCsv = 0;
  for (let pass = 0; pass < 2; pass++) {
    const n = r.u32();
    for (let i = 0; i < n; i++) { const k = wstr(r.u32()); keys.set(k, r.u32()); }
    if (pass === 0) nTxt = n; else nCsv = n;
  }
  return { txtFiles, csvFiles, strings, keys, nTxt, nCsv, trailing: r.remaining };
}
let LINES = null;
const L = (key) => { if (!LINES) return null; const id = LINES.keys.get(key); return id ? (LINES.strings.get(id) ?? null) : null; };
/** txt table type prefix per file (from the index: first column of every entry). */
const TXT_TYPE = new Map();
/** map-scoped (type 6) tables: map index -> table file name. */
const MAP_TABLE = new Map();

// ------------------------------------------------------------------------------------------------ message markup
/**
 * Parse a Dekaron script string into { text, kind, effectUi[], sound[], effectSound[], gauge? }.
 *   "\\" in the table = line break.  Leading "[message]" = system chat message (kind "message"), else dialog text.
 *   @<effectui>id,a,ms,b        full-screen UI effect (banner) id shown for ms milliseconds
 *   @<sound>a,id                 scripted sound / BGM cue            @<effectsound>cat,id,vol,range  3D effect sound
 *   <guage,sec MS,text T,snd a b c d>  channel gauge (progress bar) of MS ms with caption T (decipher / capture)
 */
function parseMarkup(raw) {
  if (raw === null || raw === undefined) return null;
  let s = String(raw);
  const out = {};
  const eff = [], snd = [], esnd = [];
  s = s.replace(/@?<effectui>\s*([\d,\s]+)/gi, (_, a) => { const v = a.split(',').map((x) => num(x)); eff.push({ id: v[0], a: v[1], ms: v[2], b: v[3] }); return ''; });
  s = s.replace(/@?<effectsound>\s*([\d,\s]+)/gi, (_, a) => { const v = a.split(',').map((x) => num(x)); esnd.push({ cat: v[0], id: v[1], vol: v[2], range: v[3] }); return ''; });
  s = s.replace(/@?<sound>\s*([\d,\s]+)/gi, (_, a) => { const v = a.split(',').map((x) => num(x)); snd.push({ a: v[0], id: v[1] }); return ''; });
  s = s.replace(/<guage,([^>]*)>/gi, (_, a) => {
    const g = {};
    for (const part of a.split(',')) {
      const m = /^\s*(\w+)\s+(.*)$/.exec(part);
      if (!m) continue;
      if (m[1] === 'sec') g.ms = num(m[2]);
      else if (m[1] === 'text') g.text = m[2].trim();
      else if (m[1] === 'snd') g.snd = m[2].trim().split(/\s+/).map((x) => num(x));
      else g[m[1]] = m[2].trim();
    }
    out.gauge = g; return '';
  });
  let kind = 'dialog';
  if (/^\s*\[\s*message\s*\]/i.test(s)) { kind = 'message'; s = s.replace(/^\s*\[\s*message\s*\]\s*/i, ''); }
  s = s.replace(/\\\\/g, '\n').replace(/\\/g, '\n').replace(/@\s*$/, '').replace(/\n+$/, '').trim();
  out.text = s;
  out.kind = s || out.gauge ? kind : (eff.length || snd.length || esnd.length ? 'effect' : 'empty');
  if (eff.length) out.effectUi = eff;
  if (snd.length) out.sound = snd;
  if (esnd.length) out.effectSound = esnd;
  return out;
}

/** developer notes of script/string/<dir>/<file>.txt: "<cate> N #note", "code N #note" -> Map(cate -> {note, codes: Map}) */
function parseStringNotes(rel) {
  const out = new Map();
  if (!existsRel(rel)) return out;
  let cur = null;
  for (const l of textRel(rel).split(/\r?\n/)) {
    const c = /^<cate>\s*(-?\d+)\s*(?:#\s*(.*))?$/.exec(l.trim());
    if (c) { cur = { note: (c[2] || '').trim(), codes: new Map() }; out.set(+c[1], cur); continue; }
    const m = /^code\s+(-?\d+)\s*(?:#+\s*(.*))?$/.exec(l.trim());
    if (m && cur && m[2]) cur.codes.set(+m[1], m[2].trim());
  }
  return out;
}

// ------------------------------------------------------------------------------------------------ small table helpers
function headerTable(rel) {
  const rows = csvRel(rel);
  const header = rows[0] || [];
  const out = [];
  for (const r of rows.slice(1)) {
    if (!r.some((c) => c !== '')) continue;
    const o = {};
    header.forEach((h, i) => { if (h !== '') o[h] = r[i] ?? ''; });
    out.push(o);
  }
  return { header, rows: out, rawRows: rows };
}
/** "Key,v1,v2,..." rows -> { key: [v...] } */
function kvTable(rel) {
  const out = {};
  for (const r of csvRel(rel)) { if (!r[0]) continue; out[r[0]] = r.slice(1).filter((x, i, a) => i === 0 || x !== '' || a.slice(i).some((y) => y !== '')); }
  return out;
}
const typed = (o) => { const r = {}; for (const [k, v] of Object.entries(o)) { const n = numN(v); r[k] = n === null ? v : n; } return r; };

// ================================================================================================
function main() {
  const t0 = Date.now();
  if (!fs.existsSync(DATA)) { console.error(`data root not found: ${DATA}`); process.exit(2); }
  log(`data root: ${DATA}`);
  for (const sub of ['map', 'share', 'script', 'mesh', 'skel', 'anim', 'texturepack', 'texture']) indexDir(sub);
  log(`indexed ${FILES.size} files`);

  const REPORT_LOC = {};
  LINES = parseLinesEuFull(readRel('script/lines_eu'));
  if (LINES.trailing) hard(`lines_eu: ${LINES.trailing} trailing bytes`);
  for (const f of LINES.txtFiles) {
    if (!f.cols.length) continue;
    TXT_TYPE.set(f.name.toLowerCase(), f.cols[0][0]);
    for (const [t, cate] of f.cols) if (t === 6 && !MAP_TABLE.has(cate)) MAP_TABLE.set(cate, f.name.toLowerCase());
  }
  const txtKey = (file, cate, code) => `${String(TXT_TYPE.get(file) ?? 0).padStart(2, '0')}|${file}#${cate}|${code}`;
  log(`lines_eu: ${LINES.strings.size} strings, ${LINES.nTxt} txt keys, ${LINES.nCsv} csv keys; ${MAP_TABLE.size} map-scoped table sections`);

  // ---------------------------------------------------------------- maplist (client + server)
  const ml = headerTable('share/maplist.csv');
  const MAPS = new Map();
  ml.rows.forEach((r, i) => {
    const idx = numN(r.Index); if (idx === null) return;
    const en = L(`share#maplist.csv#1|${i + 1}`);
    MAPS.set(idx, { row: i + 1, r, name: en || r.Name, nameKr: hasHangul(r.Name) ? r.Name : undefined });
  });
  // verify the row-number reading of the localisation key on rows whose csv name is plain ASCII
  let nameAgree = 0, nameCmp = 0;
  for (const [, m] of MAPS) if (/^[\x20-\x7e]+$/.test(m.r.Name) && L(`share#maplist.csv#1|${m.row}`)) { nameCmp++; if (L(`share#maplist.csv#1|${m.row}`).trim() === m.r.Name.trim()) nameAgree++; }
  log(`maplist: ${MAPS.size} rows; localised names agree with ASCII csv names ${nameAgree}/${nameCmp}`);
  if (nameCmp && nameAgree / nameCmp < 0.9) hard(`maplist localisation row mapping looks wrong (${nameAgree}/${nameCmp})`);

  const dungeonList = new Map();
  for (const r of headerTable('share/dungeonlist.csv').rows) { const i = numN(r.Dungeon_Index); if (i !== null && !dungeonList.has(i)) dungeonList.set(i, r); }
  const dungeonFiles = new Map();
  for (const r of headerTable('share/dungeon/dungeonfilelist.csv').rows) {
    const i = numN(r.DungeonIndex); if (i === null) continue;
    const k = resolveKey('share/dungeon', r.TextFileName);
    if (!dungeonFiles.has(i)) dungeonFiles.set(i, []);
    if (k) dungeonFiles.get(i).push(k); else soft(`dungeonfilelist ${i}: ${r.TextFileName} missing`);
  }
  const locations = parseLocationCSV(readRel('share/arrange/location.csv'));

  // ---------------------------------------------------------------- creatures (raw)
  const monDat = new Map(parseMonsterDat(readRel('share/creature/monster.dat')).map((m) => [m.index, m]));
  const monName = (i) => { const d = monDat.get(i); return d ? (L(d.nameKey) || d.shape) : null; };
  // localisation keys of csv tables use the ROW NUMBER of the csv the localisation was built from; for tables whose
  // shipped row order differs (itemetc.csv) that lookup is wrong, so every table's row mapping is checked first against
  // rows whose csv text is plain ASCII (EU client csvs mostly carry English already)
  const rowLocOk = (label, rows, keyOf, csvText) => {
    let cmp = 0, ok = 0;
    rows.forEach((r, i) => { const t = csvText(r); const l = L(keyOf(i)); if (t && l && /^[\x20-\x7e]+$/.test(t)) { cmp++; if (l.trim() === t.trim()) ok++; } });
    const good = cmp > 0 && ok / cmp >= 0.9;
    log(`localisation row mapping ${label}: ${ok}/${cmp} ASCII rows agree -> ${good ? 'use lines_eu' : 'use csv text'}`);
    REPORT_LOC[label] = `${ok}/${cmp}${good ? '' : ' (lines_eu row keys not used)'}`;
    return good;
  };
  const npcTab = headerTable('share/creature/npc.csv');
  const npcLoc = rowLocOk('creature#npc.csv', npcTab.rows, (i) => `creature#npc.csv#1|${i + 1}`, (r) => r.Name);
  const NPC = new Map();
  npcTab.rows.forEach((r, i) => {
    const idx = numN(r.Index); if (idx === null || NPC.has(idx)) return;
    const jobs = [];
    for (let k = 1; k <= 20; k++) { const t = num(r[`JobType${k}`]), j = num(r[`JobIndex${k}`]); if (t || j) jobs.push([t, j]); }
    const jc = num(r.JobCount);
    NPC.set(idx, { name: ((npcLoc && L(`creature#npc.csv#1|${i + 1}`)) || r.Name || '').trim(), shape: String(r.Shape || '').toLowerCase(), desc: num(r.Desc), comm: num(r.CommTableIndex),
      jobs: jobs.slice(0, Math.max(jc, jobs.filter(([t, j]) => t || j).length)) });
  });
  const monCsv = new Map();
  for (const r of headerTable('share/creature/monster.csv').rows) { const i = numN(r.Index); if (i !== null && !monCsv.has(i)) monCsv.set(i, r); }
  const jobTypes = {};
  for (const r of csvRel('share/creature/jobtypeconfig.csv').slice(1)) {
    const k = numN(r[0]); if (k === null) continue;
    // "SHOP<korean>", "SKILLMASTERSkillMaster", "COLOSSEUM_BATTLEROYAL_RENEW = 132 ...": leading upper-case identifier
    const m = /^\s*([A-Z_][A-Z0-9_]*)([a-z])?/.exec(r[1] || '');
    const name = m ? (m[2] ? m[1].slice(0, -1) : m[1]) : `JOB_${k}`;
    const notes = (r[1] || '').slice(m ? m[0].length - (m[2] ? 2 : 0) : 0).replace(/^\s*=?\s*\d*\s*/, '').trim();
    jobTypes[k] = { name, label: L(txtKey('stringtable_jobtype.txt', 200, k)) || undefined, battleOk: num(r[2]), chaoticOk: num(r[3]), notes: notes || undefined };
  }

  // ---------------------------------------------------------------- bricks (transposed table) + brick shapes + action tables
  const brickRows = csvRel('share/creature/brick.csv');
  const brickIds = brickRows[0].slice(1).map((s) => numN(s));
  const brickField = new Map(brickRows.slice(1).map((r, i) => [r[0], { r, row: i + 1 }]));
  const brickCol = new Map(); brickIds.forEach((id, c) => { if (id !== null && !brickCol.has(id)) brickCol.set(id, c); });
  const brickNameRow = brickField.get('Name');
  const brickLoc = rowLocOk('creature#brick.csv (column = brick)', brickIds.map((id, c) => c), (c) => `creature#brick.csv#${c + 1}|${brickNameRow?.row}`, (c) => brickNameRow?.r[c + 1]);
  const brickShapes = new Map();
  for (const r of csvRel('script/shape/brick_shape.csv').slice(1)) { if (r[1]) brickShapes.set(r[1].toLowerCase(), { mesh: r[2], tpack: r[3], effect: num(r[4]), effectId: num(r[7]) }); }
  const brickActs = new Map();
  for (const dir of ['share/action/action/brick', 'share/action/brick']) {
    const abs = path.join(DATA, dir); if (!fs.existsSync(abs)) continue;
    for (const f of fs.readdirSync(abs)) {
      const rel = `${dir}/${f}`.toLowerCase();
      let a = null;
      try { a = f.toLowerCase().endsWith('.dat') ? parseActDat(readRel(rel)) : f.toLowerCase().endsWith('.csv') ? parseActCsv(readRel(rel)) : null; } catch { a = null; }
      if (!a || a.index === null || a.index === undefined) continue;
      if (!brickActs.has(a.index) || (rel.endsWith('.dat') && !brickActs.get(a.index).src.endsWith('.dat'))) brickActs.set(a.index, { src: rel, ...a });
    }
  }
  const tpackCache = new Map();
  function resolveTexture(texpath, file) {
    const f = String(file).trim().replace(/\\/g, '/').toLowerCase();
    const dir = String(texpath ?? '').trim().replace(/\\/g, '/').replace(/^\/+|\/+$/g, '').toLowerCase();
    const b = f.slice(f.lastIndexOf('/') + 1);
    for (const c of [dir && `texture/${dir}/${f}`, `texture/${f}`, dir && `texture/${dir.split('/')[0]}/${b}`]) if (c && has(c)) return c;
    return (BY_BASENAME.get(b) || []).find((k) => k.startsWith('texture/')) || null;
  }
  function brickVisual(shapeName) {
    const s = brickShapes.get(String(shapeName || '').toLowerCase());
    if (!s) return { missing: `shape ${shapeName} not in brick_shape.csv` };
    const v = {};
    const mesh = resolveKey('mesh', s.mesh);
    if (mesh) v.mesh = K(mesh); else v.missingMesh = s.mesh;
    const tp = s.tpack ? resolveKey('texturepack', s.tpack) : null;
    if (tp) {
      v.tpack = K(tp);
      let t = tpackCache.get(tp); if (!t) { t = parseTpackText(textRel(tp)); tpackCache.set(tp, t); }
      const diffuse = [];
      for (const sl of Object.keys(t.diffuse).map(Number)) { const k = resolveTexture(t.texpath, t.diffuse[sl]); diffuse[sl] = k ? K(k) : null; if (!k) (v.missingTextures ||= []).push(t.diffuse[sl]); }
      for (let i = 0; i < diffuse.length; i++) if (diffuse[i] === undefined) diffuse[i] = null;
      if (diffuse.length) v.diffuse = diffuse;
    } else if (s.tpack) v.missingTpack = s.tpack;
    if (s.effect) v.effect = s.effect;
    if (s.effectId) v.effectId = s.effectId;
    return v;
  }
  const BRICK_KEEP = ['Name', 'Property', 'Rank', 'Material', 'Level', 'MaxHP', 'DefaultHP', 'HPRecovery', 'ActionType', 'Disappear', 'WidthSize', 'HeightSize',
    'Defence_Min', 'Defence_Max', 'GuardRate', 'GuardEfficiency', 'BlockRate', 'Distance', 'MeleeDamageResist', 'RangeDamageResist', 'PhysicalResist', 'MagicResist',
    'ShapeInfo', 'Exp', 'StatusIndex', 'LifeTime', 'ShowName', 'Ally', 'Targeting', 'IsAttackable'];
  const BRICKS = {};
  function useBrick(id) {
    if (id === null || id === undefined) return;
    if (BRICKS[id]) return;
    const c = brickCol.get(id);
    if (c === undefined) { hard(`brick ${id} not in share/creature/brick.csv`); BRICKS[id] = { missing: true }; return; }
    const f = (name) => { const e = brickField.get(name); return e ? (e.r[c + 1] ?? '') : ''; };
    const b = { name: (brickLoc && L(`creature#brick.csv#${c + 1}|${brickNameRow.row}`)) || f('Name') };
    for (const k of BRICK_KEEP.slice(1)) { const v = f(k); if (v !== '' && v !== '0') b[k[0].toLowerCase() + k.slice(1)] = numN(v) ?? v; }
    const raw = {};
    for (const [name] of brickField) { if (BRICK_KEEP.includes(name)) continue; const v = f(name); if (v !== '' && v !== '0') raw[name] = numN(v) ?? v; }
    if (Object.keys(raw).length) b.raw = raw;
    b.visual = brickVisual(f('ShapeInfo'));
    const act = brickActs.get(id);
    if (act) {
      const clips = [];
      for (const rec of act.records) { const k = rec.anim ? resolveKey('anim', rec.anim) : null; clips.push([rec.name ?? ACTION_CODES[rec.action] ?? rec.action, rec.index, k ? K(k) : null]); if (rec.anim && !k) soft(`brick ${id}: anim ${rec.anim} missing`); }
      const skel = act.skeleton ? resolveKey('skel', act.skeleton) : null;
      b.act = { src: K(act.src), skel: skel ? K(skel) : null, clips };
      if (act.skeleton && !skel) b.act.missingSkel = act.skeleton;
    }
    BRICKS[id] = b;
  }

  // ---------------------------------------------------------------- items (csv tables + item.dat name keys)
  const ITEM_FILES = ['itemweapon.csv', 'itemarmor.csv', 'itemaccessory.csv', 'itemetc.csv', 'itemetc_socket.csv', 'itemcash.csv', 'itemmileage.csv', 'itemevent/etcevent.csv', 'itemevent/cashevent.csv', 'itemevent/accessoryevent.csv'];
  const ITEMIDX = new Map();
  for (const f of ITEM_FILES) {
    const rel = `share/item/${f}`; if (!existsRel(rel)) continue;
    const rows = csvRel(rel);
    for (let i = 1; i < rows.length; i++) { const k = numN(rows[i][0]); if (k === null || ITEMIDX.has(k)) continue; ITEMIDX.set(k, { file: rel, row: i, name: rows[i][1] }); }
  }
  // share/item/item.dat = compiled client item table: fixed 565-byte records, u32 item index at +128 (ascending over the
  // whole file), UTF-16LE localisation key at +204 ("item#itemetc.csv#1|5551" -> script/lines_eu).  The key's row number
  // refers to the localisation build of the csv, NOT to the shipped csv row order (itemetc row 5551 != key row 5551), so
  // item.dat is the authoritative name source (same scheme as monster.dat nameKey); csv Name is the fallback.
  const ITEM_DAT_REC = 565, ITEM_DAT_IDX = 128, ITEM_DAT_KEY = 204;
  const itemDat = readRel('share/item/item.dat');
  const itemDatAt = new Map();
  if (itemDat.length % ITEM_DAT_REC) hard(`item.dat size ${itemDat.length} is not a multiple of ${ITEM_DAT_REC}`);
  else { let prev = -1, bad = 0; for (let o = 0; o < itemDat.length; o += ITEM_DAT_REC) { const id = itemDat.readUInt32LE(o + ITEM_DAT_IDX); if (id <= prev) bad++; prev = id; itemDatAt.set(id, o); } if (bad) soft(`item.dat: ${bad} non-ascending indices`); }
  const itemDatKey = (id) => {
    const o = itemDatAt.get(id); if (o === undefined) return null;
    let e = o + ITEM_DAT_KEY; while (e + 1 < o + ITEM_DAT_REC && (itemDat[e] || itemDat[e + 1])) e += 2;
    const k = utf16.decode(itemDat.subarray(o + ITEM_DAT_KEY, e));
    return /^[a-z_]+#[^#]+#\d+\|\d+$/i.test(k) ? k : null;
  };
  const ITEMS = {};
  function useItem(id) {
    if (!id || ITEMS[id]) return;
    const e = ITEMIDX.get(id);
    const nk = itemDatKey(id);
    const loc = nk ? L(nk) : null;
    if (e || nk) {
      ITEMS[id] = { name: loc || e?.name || null };
      if (nk) ITEMS[id].nameKey = nk;
      if (e) ITEMS[id].file = K(e.file); else ITEMS[id].file = K('share/item/item.dat');
      if (e && loc && e.name && !hasHangul(e.name) && loc.trim() !== e.name.trim()) ITEMS[id].csvName = e.name;
      return;
    }
    ITEMS[id] = { name: null, unresolved: true }; soft(`item ${id} not found in item.dat nor the item csv tables`);
  }

  // ---------------------------------------------------------------- statuses (buffs)
  const statusTab = csvRel('share/skill/status.csv');
  const STATUSIDX = new Map();
  for (let i = 1; i < statusTab.length; i++) { const k = numN(statusTab[i][0]); if (k !== null && !STATUSIDX.has(k)) STATUSIDX.set(k, i); }
  const statusLoc = rowLocOk('skill#status.csv', statusTab.slice(1), (i) => `skill#status.csv#6|${i + 1}`, (r) => r[6]);
  const STATUSES = {};
  function useStatus(id) {
    if (!id || STATUSES[id]) return;
    const i = STATUSIDX.get(id);
    if (i === undefined) { hard(`status ${id} not in share/skill/status.csv`); STATUSES[id] = { missing: true }; return; }
    const r = statusTab[i]; const h = statusTab[0];
    const g = (n) => r[h.indexOf(n)] ?? '';
    const opts = [];
    for (let k = 0; k < 15; k++) { const c = r[11 + k * 2], v = r[12 + k * 2]; if (c && c !== 'NONE') opts.push([c, numN(v) ?? v]); }
    STATUSES[id] = { desc: ((statusLoc && L(`skill#status.csv#6|${i}`)) || g('Description')).replace(/\\/g, ' / '), type: num(g('Type')), property: num(g('Property')), style: num(g('Style')),
      maxStack: num(g('MaxStackCount')), group: num(g('GroupIndex')), icon: num(g('IconIndex')), options: opts };
  }

  // ---------------------------------------------------------------- referenced creatures
  const NPCS = {}, MONSTERS = {};
  function useNpc(id) {
    if (NPCS[id]) return;
    const n = NPC.get(id);
    // placed but undefined NPCs are client holes (maps 68/69 Egutt bases place 4016-4027): recorded, engine skips them
    if (!n) { soft(`NPC ${id} placed on an event map but not defined in share/creature/npc.csv (client hole)`); NPCS[id] = { missing: true }; return; }
    const o = { name: n.name, shape: n.shape };
    if (n.jobs.length) o.jobs = n.jobs.map(([t, j]) => [t, j, jobTypes[t]?.name || `JOB_${t}`]);
    const greet = n.comm ? L(txtKey('stringtable_conv.txt', 0, n.comm)) : null;
    if (greet) o.greeting = parseMarkup(greet).text;
    o.comm = n.comm || undefined;
    NPCS[id] = o;
  }
  function useMonster(id) {
    if (MONSTERS[id]) return;
    const d = monDat.get(id);
    if (!d) {
      const c = monCsv.get(id);
      if (c) { MONSTERS[id] = { name: c.Name, level: num(c.Level), hp: num(c.MaxHP), exp: num(c.Exp), rank: num(c.Rank), shape: String(c.ShapeInfo || '').toLowerCase(), from: 'monster.csv' }; return; }
      soft(`monster ${id} referenced by an event table but defined in neither monster.dat nor monster.csv (client hole)`); MONSTERS[id] = { missing: true }; return;
    }
    MONSTERS[id] = { name: monName(id), level: d.level, hp: d.maxHP, exp: d.exp, rank: d.rank, shape: d.shape.toLowerCase(), aiKey: d.aiKey };
  }

  // ---------------------------------------------------------------- map-scoped strings & dialog trees
  const TEXT = { tables: {}, notes: {} };
  const notesCache = new Map();
  const STRING_DIRS = new Map();
  for (const k of FILES) if (k.startsWith('script/string/') && k.endsWith('.txt')) STRING_DIRS.set(k.slice(k.lastIndexOf('/') + 1), k);
  function tableSection(file, cate) {
    file = file.toLowerCase();
    TEXT.tables[file] ||= {};
    if (TEXT.tables[file][cate]) return TEXT.tables[file][cate];
    const sec = {};
    const prefix = `${String(TXT_TYPE.get(file) ?? 0).padStart(2, '0')}|${file}#${cate}|`;
    const codes = [];
    for (const [k, id] of LINES.keys) if (k.toLowerCase().startsWith(prefix)) codes.push([num(k.slice(prefix.length)), LINES.strings.get(id)]);
    codes.sort((a, b) => a[0] - b[0]);
    for (const [c, s] of codes) sec[c] = parseMarkup(s);
    // developer notes (Korean / English comments of the source string file)
    const src = STRING_DIRS.get(file);
    if (src) {
      if (!notesCache.has(src)) notesCache.set(src, parseStringNotes(src));
      const n = notesCache.get(src).get(cate);
      if (n) { TEXT.notes[file] ||= {}; TEXT.notes[file][cate] = { note: n.note, codes: Object.fromEntries(n.codes) }; }
    }
    TEXT.tables[file][cate] = sec;
    return sec;
  }
  const DIALOGS = {};
  function dialogTree(mapIdx) {
    const files = dungeonFiles.get(mapIdx) || [];
    if (!files.length) return null;
    const table = MAP_TABLE.get(mapIdx);
    const out = { files: files.map(K), table: table || null, nodes: {} };
    if (table) tableSection(table, mapIdx);
    for (const f of files) {
      const rows = csvRel(f);
      const hi = rows.findIndex((r) => r[0] === 'MessageIndex');
      for (const r of rows.slice(hi + 1)) {
        const mi = numN(r[0]); if (mi === null) continue;
        const code = num(r[1]);
        const menu = r.slice(2, 7).map((x) => num(x)).filter((x) => x);
        const txt = table ? TEXT.tables[table][mapIdx]?.[code] : null;
        const node = { code };
        if (menu.length) node.menu = menu;
        if (!txt) node.missingText = true;
        if (!out.nodes[mi]) out.nodes[mi] = node;
      }
    }
    DIALOGS[mapIdx] = out;
    return out;
  }

  // ---------------------------------------------------------------- level caps / ability caps
  const CAPS = { levelCaps: {}, abilityCaps: {} };
  function useLevelCap(key) {
    if (!key || CAPS.levelCaps[key]) return key;
    if (!has(key)) { soft(`level cap file ${key} missing`); return null; }
    const t = headerTable(key);
    CAPS.levelCaps[K(key)] = { fields: ['diffFrom', 'diffTo', 'expRate', 'chaoticRate', 'blocking', 'blocked', 'r', 'g', 'b'],
      rows: t.rows.map((r) => [num(r['Level Cap Start']), num(r['Level Cap End']), num(r['Exp Rate']), num(r['Chaotic Rate']), num(r.BLOCKING), num(r.BLOCKED), num(r.Color_R), num(r.Color_G), num(r.Color_B)]) };
    return key;
  }
  function useAbilityCap(key) {
    if (!key) return null;
    let k = key;
    if (!has(k)) { const alt = resolveKey('share/pc', key.replace(/^share\/pc\//, '')); if (alt) k = alt; else { soft(`ability cap file ${key} missing`); return null; } }
    if (CAPS.abilityCaps[k]) return k;
    const rows = csvRel(k);
    const header = rows[0];
    const data = rows.slice(1).filter((r) => numN(r[0]) !== null).map((r) => r.map((x) => num(x)));
    CAPS.abilityCaps[K(k)] = { header, note: 'column 0 = level difference (+250 .. -250); columns 1-7 and 8-14 repeat the same seven names (two contexts, see events.md §caps)',
      allZero: data.every((r) => r.slice(1).every((v) => v === 0)), rows: data };
    return k;
  }

  // ================================================================================================
  // EVENT MAP SET
  // ================================================================================================
  const pwSet = kvTable('share/partywar/set.csv');
  const pwLobbies = (pwSet.LobbyIndex || []).map(numN).filter((x) => x !== null);
  const pwFields = (pwSet.FieldIndex || []).map(numN).filter((x) => x !== null);
  const MODE_OF = new Map();
  const setMode = (i, mode, extra = {}) => { if (!MODE_OF.has(i)) MODE_OF.set(i, { mode, ...extra }); };
  // tiers from the map names ("Dead Front [Core]", "Ice Castle [Fear]")
  const tierOf = (i) => { const n = MAPS.get(i)?.name || ''; const m = /\[(Core|Fear|Baron|Earl|Duke|Arc|Doom|Hell|Rabble|Pier)\]/i.exec(n); return m ? m[1] : null; };
  for (const i of pwFields) {
    const sn = String(MAPS.get(i)?.r.ScriptName || '');
    if (/icecastle/i.test(sn) || /dead_front_2\.map/i.test(MAPS.get(i)?.r.MapFile || '')) setMode(i, 'iceCastle', { tier: tierOf(i), variant: 'dk' });
    else setMode(i, 'deadFront', { tier: tierOf(i), variant: /_DK$/i.test(sn) ? 'dk' : 'normal' });
  }
  for (const i of pwLobbies) setMode(i, /dead_front_2/i.test(MAPS.get(i)?.r.MapFile || '') ? 'iceCastleLobby' : 'deadFrontLobby');
  const colBR = headerTable('share/colosseum/battleroyal/list.csv').rows;
  const colBRR = headerTable('share/colosseum/battleroyal_renew/list.csv').rows;
  const colPM = headerTable('share/colosseum/partymatch/list.csv').rows;
  const colGM = headerTable('share/colosseum/guildmatch/list.csv').rows;
  setMode(162, 'colosseumLobby');
  for (const r of colBR) setMode(num(r.MapIndex), 'battleRoyal');
  for (const r of colBRR) setMode(num(r.MapIndex), 'battleRoyal', { renew: true });
  for (const r of colPM) setMode(num(r.MapIndex), 'partyMatch');
  for (const r of colGM) setMode(num(r.MapIndex), 'guildMatch');
  setMode(615, 'colosseumArena', { party: false }); setMode(616, 'colosseumArena', { party: true });
  setMode(200, 'huntingChallenge'); setMode(714, 'pvp3v3Lobby'); setMode(716, 'pvp3v3');
  for (const i of [153, 154, 155, 613]) setMode(i, 'infiniteBattle');
  for (const i of [228, 229, 534]) setMode(i, 'infiniteBattle2');
  for (const [i, m] of MAPS) if (/PartyMatch_DeathMatch/i.test(m.r.ScriptName || '')) setMode(i, 'partyPvpArena');
  for (const [i, m] of MAPS) if (/^arena_wating\.map$/i.test(m.r.MapFile || '')) setMode(i, 'arenaLobby');
  setMode(22, 'oxQuiz'); setMode(654, 'oxQuiz');
  setMode(23, 'siege'); for (const i of [185, 186, 187, 188]) setMode(i, 'raceHall');
  const siegeRenewCfg = kvTable('share/siege_renew/config.csv');
  for (const [k, v] of Object.entries(siegeRenewCfg)) if (/^MAP_\d+_INDEX$/.test(k) && num(v[0])) setMode(num(v[0]), 'siegeRenew');
  const arenaField = headerTable('share/arena/field.csv').rows;
  for (const r of arenaField) setMode(num(r.MapIndex), 'arenaBattlefield', { arenaType: num(r.Type) });
  setMode(549, 'lostHorizonPve'); setMode(68, 'arenaBattlefieldBase'); setMode(69, 'arenaBattlefieldBase');
  const urban = headerTable('share/urbanwarfare/respawn.csv').rows;
  for (const r of urban) setMode(num(r.MapIndex), 'urbanWarfare');
  for (const i of [651, 652]) setMode(i, 'urbanWarfareLobby'); setMode(653, 'urbanWarfareDungeon');
  const gwh = csvRel('share/guildwarhunting/config.csv');
  setMode(num(gwh[1]?.[1]), 'guildWarHunting');
  for (const i of [234, 235, 250, 251, 263, 264]) setMode(i, 'forgottenShipwreck');
  const fbCfg = headerTable('share/fieldboss/config.csv').rows;
  for (const r of fbCfg) setMode(num(r.MapIndex), 'fieldBoss');
  for (const [i, m] of MAPS) if (/^(dead_front|colosseum|arena|battle_royal|battle_arena|3vs3)/i.test(m.r.MapFile || '')) setMode(i, 'arenaNamedMap');
  for (const i of MODE_OF.keys()) if (!MAPS.has(i)) { soft(`event map ${i} (${MODE_OF.get(i).mode}) not in share/maplist.csv`); MODE_OF.delete(i); }

  // ---------------------------------------------------------------- per map
  const MAPOUT = {};
  const scriptMon = new Map();
  for (const k of FILES) { const m = /^share\/map\/(\d+)_[^/]+\/scriptmonster_(\d+)\.csv$/.exec(k); if (m) scriptMon.set(+m[2], k); }
  const RAW_MAPPED = new Set(['Index', 'Name', 'MapFile', 'MapObject', 'MapEffect', 'MapAttribute', 'PosFile', 'MapPath', 'MonsterLocatePath', 'NPCLocatePath', 'BrickLocatePath',
    'CallMonsterPath', 'TriggerLocatePath', 'StrLevelCapPath', 'StrGradeCapPath', 'StrAbilityCapPath', 'LimitMinLevel', 'LimitMaxLevel', 'ScriptName', 'Map_Type', 'IsPvP', 'IsSiege',
    'DungeonIndex', 'TROOP_LOBBY', 'DynamicType', 'viewType', 'RetMapIndex', 'RetX', 'RetY', 'RetDirection', 'IsReturn', 'PCRevivalChack', 'MonsterRespawnFactor', 'MonsterLimit',
    'IsReturnScroll', 'IsPortal', 'PeaceZone', 'PVP_PeaceZone', 'IsUrbanWarfare', 'isDeclareWar', 'IsVehicle', 'isUseMap']);
  const missingFiles = [];
  for (const [idx, info] of [...MODE_OF].sort((a, b) => a[0] - b[0])) {
    const m = MAPS.get(idx); const r = m.r;
    const p = mapDataPaths(r);
    const o = { name: m.name };
    if (m.nameKr) o.nameKr = m.nameKr;
    Object.assign(o, info);
    const files = {};
    for (const [k, v] of Object.entries({ map: p.map, mol: p.mol, mel: p.mel, mac: p.mac, zoneGraph: p.zoneGraph, npcs: p.npcs, bricks: p.bricks, monsters: p.monsters,
      callMonsters: p.callMonsters, triggers: p.triggers, levelCap: p.levelCap })) {
      if (!v) continue;
      if (has(v)) files[k] = K(v);
      else {
        const alt = k === 'callMonsters' ? [...FILES].find((f) => f.startsWith(v.slice(0, v.lastIndexOf('/') + 1)) && /callmon/i.test(f)) : null;
        if (alt) { files[k] = K(alt); soft(`map ${idx}: ${k} ${v} missing, using ${alt}`); } else missingFiles.push(`${idx} ${k}: ${v}`);
      }
    }
    const gc = r.StrGradeCapPath ? `share/${String(r.StrGradeCapPath).replace(/\\/g, '/').toLowerCase()}` : null;
    if (gc && has(gc)) files.gradeCap = K(gc);
    const ac = r.StrAbilityCapPath ? useAbilityCap(`share/${String(r.StrAbilityCapPath).replace(/\\/g, '/').toLowerCase()}`) : null;
    if (ac) files.abilityCap = ac;
    if (files.levelCap) useLevelCap(files.levelCap);
    if (scriptMon.has(idx)) files.scriptMonsters = K(scriptMon.get(idx));
    o.files = files;
    o.level = [num(r.LimitMinLevel), num(r.LimitMaxLevel)];
    const flags = {};
    for (const k of ['Map_Type', 'IsPvP', 'IsSiege', 'DungeonIndex', 'TROOP_LOBBY', 'DynamicType', 'viewType', 'IsReturn', 'IsReturnScroll', 'IsPortal', 'PeaceZone', 'PVP_PeaceZone',
      'PCRevivalChack', 'MonsterRespawnFactor', 'MonsterLimit', 'IsUrbanWarfare', 'isDeclareWar', 'IsVehicle', 'isUseMap']) flags[k] = numN(r[k]) ?? r[k];
    o.flags = flags;
    if (r.ScriptName) o.scriptName = r.ScriptName;
    const ret = num(r.RetMapIndex);
    o.ret = { map: ret, x: num(r.RetX), y: num(r.RetY), dir: num(r.RetDirection) };
    const raw = {};
    for (const [k, v] of Object.entries(r)) if (!RAW_MAPPED.has(k) && v !== '') raw[k] = numN(v) ?? v;
    o.raw = raw;
    const dl = dungeonList.get(idx);
    if (dl) {
      o.dungeon = { name: dl.Dungeon_Name, keeperType: dl.Keeper_Type, expireTime: num(dl.ExpireTime), requestMember: num(dl.RequestMember), requestMemberMax: num(dl.RequestMember_Max),
        kickType: dl.KickType, kickTo: [[num(dl.KickToMap_0), num(dl.KickToX_0), num(dl.KickToY_0)], [num(dl.KickToMap_1), num(dl.KickToX_1), num(dl.KickToY_1)]].filter((k) => k[0] || k[1] || k[2]),
        kickRespawn: num(dl.KickRespawn), maps: [0, 1, 2, 3, 4, 5].map((k) => num(dl[`MapIndex_${k}`])).slice(0, Math.max(1, num(dl.MapCount))), ticket: num(dl.Ticket), check: num(dl.Check), captchaRate: num(dl.CaptchaRate), isVehicle: num(dl.IsVehicle), isSiegeSeal: num(dl.IsSiegeSeal) };
    }
    // placements
    if (files.npcs) {
      const pn = parseNpcCSV(readRel(files.npcs));
      o.npcs = pn.npcs.filter((q) => q.npcIndex !== null).map((q) => { useNpc(q.npcIndex); return [q.npcIndex, r3(q.x), r3(q.y), q.direction, q.warpX, q.warpY, q.description || '']; });
    }
    if (files.bricks) {
      o.bricks = parseBrickCSV(readRel(files.bricks)).map((b) => { useBrick(b.brickIndex); return [b.uid, b.brickIndex, r3(b.x), r3(b.y), b.direction, b.isCreate, b.revival, b.regenCycle]; });
    }
    if (files.monsters) {
      const rows = [];
      for (const l of textRel(files.monsters).split(/\r?\n/)) { const q = l.split(',').map((s) => s.trim()); if (q.length >= 4 && q.slice(0, 4).every((x) => /^-?\d+(\.\d+)?$/.test(x))) { rows.push(q.slice(0, 4).map(Number)); useMonster(+q[0]); } }
      o.spawns = rows;
    }
    if (files.callMonsters) {
      const c = parseCallMonsterCSV(readRel(files.callMonsters));
      const calls = {};
      for (const q of c.calls) { useMonster(q.monsterIndex); (calls[q.callIndex] ||= []).push([q.monsterIndex, q.x, q.y, q.radius ?? 0, q.count ?? 1]); }
      o.calls = calls;
      if (c.mapIndex !== null && c.mapIndex !== idx) o.callFileMapIndex = c.mapIndex;
      if (c.randomCalls.length) { o.randomCalls = c.randomCalls.map((q) => { useMonster(q.monsterIndex); return [q.randCallIndex, q.monsterIndex, q.count, q.posIndex]; }); o.randomPositions = c.randomPositions.map((q) => [q.randPosIndex, q.x, q.y, q.radius]); }
    }
    if (files.triggers) {
      o.triggers = parseNpcCSV(readRel(files.triggers)).npcs.map((q) => [q.npcIndex, r3(q.x), r3(q.y), q.direction, q.description || '']);
    }
    if (files.scriptMonsters) {
      o.scriptMonsters = csvRel(files.scriptMonsters).slice(1).map((q) => numN(q[0])).filter((x) => x !== null);
      for (const x of o.scriptMonsters) useMonster(x);
    }
    const dt = dialogTree(idx);
    if (dt) o.dialog = true;
    const tbl = MAP_TABLE.get(idx);
    if (tbl) { tableSection(tbl, idx); o.strings = [tbl, idx]; }
    // scripted objective NPCs (DUNGEON_SCRIPT 31 / EVENT_DUNGEON_SCRIPT 80 / MINI_DUNGEON_SCRIPT 58): the NPC menu shows
    // string <jobIndex>; picking it opens dialog node <jobIndex+1> (info + option codes); <jobIndex+2..> are the option /
    // exception strings (developer notes: investigate / info / operate / cancel / exception)
    const sn = [];
    for (const q of o.npcs || []) {
      const n = NPC.get(q[0]); if (!n) continue;
      for (const [jt, ji] of n.jobs) {
        if (![31, 58, 80].includes(jt)) continue;
        const e = { npc: q[0], at: [q[1], q[2]], jobType: jt, jobIndex: ji };
        const node = dt?.nodes[ji + 1];
        if (node) { e.infoNode = ji + 1; if (node.menu) e.options = node.menu; }
        const exc = [ji + 3, ji + 4].filter((c) => dt?.nodes[c] && !(node?.menu || []).includes(c));
        if (exc.length) e.exceptionNodes = exc;
        sn.push(e);
      }
    }
    if (sn.length) o.scriptNpcs = sn;
    if (ret && !MAPS.has(ret)) soft(`map ${idx}: return map ${ret} not in maplist`);
    MAPOUT[idx] = o;
  }
  log(`event maps: ${Object.keys(MAPOUT).length} (${uniq([...MODE_OF.values()].map((v) => v.mode)).length} modes); ${missingFiles.length} maplist file paths missing on disk`);

  // share/dkmaplist.csv (DK-channel maps): DK-channel entry points and the death respawn rule.  The header repeats
  // "RespawnPosX_00" for the Y column, so the row is read by position.
  if (has('share/dkmaplist.csv')) {
    for (const r of csvRel('share/dkmaplist.csv').slice(1)) {
      const mi = numN(r[0]); if (mi === null || !MAPOUT[mi]) continue;
      const locates = []; for (let k = 0; k < num(r[1]); k++) locates.push([num(r[2 + k * 3]), r[3 + k * 3], num(r[4 + k * 3])]);
      const respawn = []; for (let k = 0; k < Math.min(2, num(r[17])); k++) respawn.push([num(r[18 + k * 3]), num(r[19 + k * 3]), num(r[20 + k * 3])]);
      const o = { respawnType: r[16], respawn };
      if (locates.length) { o.locates = locates; o.locate = [num(r[14]), num(r[15])]; }
      const cost = [num(r[24]), num(r[25])].filter(Boolean), cash = [num(r[26]), num(r[27])].filter(Boolean);
      if (cost.length) o.costItems = cost; if (cash.length) { o.cashCostItems = cash; o.cashLocate = [num(r[28]), num(r[29])]; }
      for (const [rm] of respawn) if (rm && !MAPS.has(rm)) soft(`dkmaplist ${mi}: respawn map ${rm} not in maplist`);
      MAPOUT[mi].dkMapList = o;
    }
  }

  // ================================================================================================
  // DEAD FRONT (party war type 1) + ICE CASTLE (party war type 2)
  // ================================================================================================
  const pwConfigRows = csvRel('share/partywar/config.csv');
  const pwTypes = (pwConfigRows.find((r) => r[0] === 'Type') || []).slice(1).map(numN).filter((x) => x !== null);
  const pwConfig = {};
  pwTypes.forEach((t, i) => { const o = {}; for (const r of pwConfigRows) if (r[0] && r[0] !== 'Type') o[r[0]] = numN(r[i + 1]); pwConfig[t] = o; });
  const pwTime = headerTable('share/partywar/time.csv').rows.map((r) => [num(r.TYPE), num(r.HOUR), num(r.MIN)]);
  const pwNames = csvRel('share/partywar/name.csv');
  const teams = (pwNames[0] || []).map((id, i) => ({ id: num(id), name: L(`partywar#name.csv#${i}|1`) || pwNames[1]?.[i] || '' }));
  const zeolite = csvRel('share/partywar/zeolite.csv');
  const zIdx = (zeolite.find((r) => r[0] === 'Index') || []).slice(1), zLv = (zeolite.find((r) => r[0] === 'Level') || []).slice(1), zDel = (zeolite.find((r) => r[0] === 'Delay') || []).slice(1);
  const depots = zIdx.map((v, i) => [num(v), num(zLv[i]), num(zDel[i])]).filter((q) => q[0]);
  for (const [n] of depots) useNpc(n);
  // result.csv (transposed per map column; repeated Indwx/Point pairs)
  const res = csvRel('share/partywar/result.csv');
  const resMaps = (res[0] || []).slice(1).map(numN);
  const result = {};
  resMaps.forEach((mi, c) => {
    if (mi === null) return;
    const o = { pvpPoints: [], killPoints: [] };
    let pendingIdx = null;
    for (const r of res.slice(1)) {
      const v = numN(r[c + 1]);
      if (/^PvPPoint_\d+$/.test(r[0])) o.pvpPoints.push(v);
      else if (/^Ind[wex]+$/i.test(r[0])) pendingIdx = v;
      else if (r[0] === 'Point') { if (pendingIdx !== null) o.killPoints.push([pendingIdx, v]); pendingIdx = null; }
      else if (r[0]) o[r[0][0].toLowerCase() + r[0].slice(1)] = v;
    }
    // classify each scoring target: depot NPC (PARTY_WAR_REIGN), brick, monster, or placeholder
    o.killPoints = o.killPoints.map(([t, pnt]) => {
      let kind = 'unknown';
      const onMap = MAPOUT[mi];
      if (onMap?.npcs?.some((q) => q[0] === t) && NPC.get(t)?.jobs.some(([jt]) => jt === 39)) kind = 'depot';
      else if (onMap?.bricks?.some((q) => q[1] === t)) kind = 'brick';
      else if (monDat.has(t) && t > 100) kind = 'monster';
      else if (t < 100) kind = 'placeholder';
      if (kind === 'monster') useMonster(t);
      if (kind === 'unknown') soft(`partywar result map ${mi}: target ${t} not classified`);
      return [t, pnt, kind];
    });
    result[mi] = o;
  });
  const towerDamage = {};
  for (const r of csvRel('share/partywar/towerdamage.csv').slice(1)) {
    const mi = numN(r[0]); if (mi === null) continue;
    const list = []; for (let k = 2; k + 1 < r.length; k += 2) { const mo = numN(r[k]), d = numN(r[k + 1]); if (mo) { list.push([mo, d]); useMonster(mo); } }
    towerDamage[mi] = { count: num(r[1]), damage: list };
    if (!MAPOUT[mi]) soft(`towerdamage.csv: map ${mi} is not an event map / not in maplist`);
  }
  const targetPos = headerTable('share/ai/targetposition.csv').rows.map((r) => [num(r.MonsterIndex), num(r.X), num(r.Y), num(r.Distanse)]);
  for (const [mo] of targetPos) useMonster(mo);
  const icCheckpoints = csvRel('script/partywar/icecastle.csv').filter((r) => numN(r[0]) !== null).map((r) => [num(r[0]), num(r[1]), num(r[2]), r[3], num(r[4])]);

  // share/partywar/field.csv (transposed: row 0 = field map indices, one row per field).  Per field map: content type
  // (1 Dead Front, 2 Ice Castle), registration level window, number of parties that may register, the four team start
  // points, the four final-battle (PvP) points, winner / loser / end-of-war respawn points, R-points for the win and
  // the 12 supply-depot NPCs.  Every point is checked against the .mac collision grid of its map.
  const fieldRows = csvRel('share/partywar/field.csv');
  const fieldRow = (re) => fieldRows.find((q) => re.test(q[0] || ''));
  const macCache = new Map();
  const macOf = (mi) => {
    if (macCache.has(mi)) return macCache.get(mi);
    const k = MAPOUT[mi]?.files?.mac; let g = null;
    if (k && has(k)) { try { g = parseMac(readRel(k)); } catch (e) { soft(`map ${mi}: .mac parse failed (${e.message})`); } }
    macCache.set(mi, g); return g;
  };
  const pwField = {};
  const FIELD_USED = new Set();
  (fieldRows[0] || []).slice(1).forEach((v, c) => {
    const mi = numN(v); if (mi === null) return;
    const g = (re) => { const r = fieldRow(re); if (r) FIELD_USED.add(r[0]); return r ? numN(r[c + 1]) : null; };
    const pt = (tag, k = '') => {
      const p = { map: g(new RegExp(`^${tag}MapIndex${k}$`, 'i')), x: g(new RegExp(`^${tag.replace(/Pint|Point/, 'Point')}X${k}$`, 'i')), y: g(new RegExp(`^${tag.replace(/Pint|Point/, 'Point')}Y${k}$`, 'i')) };
      const grid = macOf(p.map);
      if (grid) {
        p.walkable = grid.isWalkable(p.x, p.y);
        if (!p.walkable) { const n = nearestWalkable(grid, p.x, p.y, 16); if (n) p.nearestWalkable = [n.x, n.y]; }
      }
      return p;
    };
    const o = {
      contentType: g(/^ContentType$/), itemCode: g(/^ItemCode$/), level: [g(/^MinLevel$/), g(/^MaxLevel$/)], maxParties: g(/^RecordEnableCount$/),
      starts: [1, 2, 3, 4].map((k) => pt('StartPoint', k)),
      pvpPoints: [1, 2, 3, 4].map((k) => pt(k === 1 ? 'PvPPint' : 'PvPPoint', k)),
      winnerRespawn: pt('WinerRespown'), loserRespawn: pt('LoserRespown'), endWarRespawn: pt('EndWarRespown'),
      winRPoint: g(/^WinRPoint$/),
      depots: Array.from({ length: 12 }, (_, k) => g(new RegExp(`^ZeoliteIndex${k + 1}$`))).filter((x) => x),
    };
    const raw = {}; for (const r of fieldRows.slice(1)) if (r[0] && !FIELD_USED.has(r[0])) raw[r[0]] = numN(r[c + 1]) ?? r[c + 1];
    if (Object.keys(raw).length) o.raw = raw;
    // quirks: the respawn map of a copy-pasted column that is not the field itself (loser respawn of 40-44/60 -> 39 etc.)
    const quirks = [];
    for (const [nm, p] of [['loserRespawn', o.loserRespawn], ['winnerRespawn', o.winnerRespawn]]) if (p.map !== mi) quirks.push(`${nm}.map ${p.map} is not the field itself (copy-paste; use the field map with the same x,y)`);
    const placed = new Set((MAPOUT[mi]?.npcs || []).map((q) => q[0]));
    o.depotsPlaced = o.depots.filter((n) => placed.has(n)).length;
    if (o.depots.length && !o.depotsPlaced) quirks.push(`none of the 12 ZeoliteIndex depots (${o.depots[0]}..) is placed on this map: ${o.contentType === 2 ? 'Ice Castle has no supply depots (column copied from Dead Front Hell)' : 'depots missing'}`);
    const ml = MAPOUT[mi]?.level;
    if (ml) {
      const lo = Math.max(ml[0], o.level[0]), hi = Math.min(ml[1], o.level[1]);
      o.entryLevel = lo <= hi ? [lo, hi] : [...ml];
      o.entryLevelSource = lo <= hi ? 'intersection of field.csv MinLevel/MaxLevel (registration) and maplist LimitMin/MaxLevel (map gate)' : 'maplist (field.csv window does not overlap the map gate; officer greeting agrees with maplist)';
      if (lo > hi) quirks.push(`field.csv level ${o.level.join('-')} does not overlap the maplist gate ${ml.join('-')}`);
    }
    for (const p of [...o.starts, ...o.pvpPoints, o.winnerRespawn, o.loserRespawn, o.endWarRespawn]) if (p.map && !MAPS.has(p.map)) soft(`partywar field ${mi}: point map ${p.map} not in maplist`);
    for (const n of o.depots) if (placed.has(n)) useNpc(n);
    if (quirks.length) o.quirks = quirks;
    if (!MAPOUT[mi]) soft(`partywar field.csv: map ${mi} is not an event map / not in maplist`);
    pwField[mi] = o;
  });

  // phase timeline of a party-war type
  function pwTimeline(t) {
    const c = pwConfig[t] || {};
    return {
      preMap: [
        ['notice', c.RecordBefore, 'announcement: application begins shortly (partywar #100|100)'],
        ['registrationOpen', c.RecordTime, 'party leaders apply at the tier officer (RECORD_PARTY_WAR) (#100|101)'],
        ['registrationLastMinute', c.RecordBeforeEnd, '1 minute left (#100|102/#100|104)'],
        ['registrationClosed', c.RecordEndTime, '(#100|103)'],
        ['selection', c.ChooseTime, 'parties selected / not selected (#100|105/#100|106); entry window opens (ENTER_PARTY_WAR, #200)'],
        ['battleIn2Min', c.BattleBefor3M, '#200|100 (column says 3M, message says 2 minutes: 1800-1680 = 120 s)'],
        ['battleIn1Min', c.BattleBefor1M, '#200|101'],
        ['battleIn30Sec', c.BattleBefor30S, '#200|102'],
      ],
      entryWindowSec: c.WaitTime,
      inMap: [
        ['waitStart', 101, c.LimitStarDelay], ['fortress', 102, c.LimitStarTime], ['waitPvp', 103, c.LimitPvPDelay], ['pvp', 104, c.LimitPvPTime],
        ['waitExtension', 105, c.LimitExtensionDelay], ['extension', 106, c.LimitExtension], ['waitClose', 107, c.LimitEndDelay],
      ].map(([id, code, sec]) => ({ id, labelCode: code, sec })),
      channel: c.Channel, checkOut: c.CheckOut,
    };
  }
  const schedule = (t) => pwTime.filter((q) => q[0] === t).map(([, h, mi]) => {
    const start = h * 3600 + mi * 60, battle = start + (pwConfig[t]?.LimitStarTime ?? 1800);
    const hh = (s) => `${String(Math.floor(s / 3600) % 24).padStart(2, '0')}:${String(Math.floor(s / 60) % 60).padStart(2, '0')}`;
    return { cycleStart: hh(start), battleStart: hh(battle) };
  });

  // tier table: officer NPCs by job (RECORD/ENTER_PARTY_WAR 37/38 -> DF, 98/99 -> IC), with target map + lobby placement
  const npcPlaced = new Map();
  for (const [mi, o] of Object.entries(MAPOUT)) for (const q of o.npcs || []) { if (!npcPlaced.has(q[0])) npcPlaced.set(q[0], []); npcPlaced.get(q[0]).push([+mi, q[1], q[2]]); }
  const officers = (recJob, entJob) => {
    const out = [];
    for (const [i, n] of NPC) {
      const rec = n.jobs.find(([t]) => t === recJob), ent = n.jobs.find(([t]) => t === entJob);
      if (!rec && !ent) continue;
      useNpc(i);
      const g = n.comm ? (L(txtKey('stringtable_conv.txt', 0, n.comm)) || '').replace(/<[^>]+>/g, '') : '';
      const m1 = /(\d+)\s*[~\-]\s*(\d+)/.exec(g), m2 = /Level\s+(\d+)\s+or\s+higher/i.exec(g);
      const o = { npc: i, name: n.name, map: (rec || ent)[1] || null, placed: npcPlaced.get(i) || [] };
      if (m1) o.greetingLevel = [+m1[1], +m1[2]]; else if (m2) o.greetingLevel = [+m2[1], 250];
      out.push(o);
    }
    return out;
  };
  const dfOfficers = officers(37, 38), icOfficers = officers(98, 99);
  // entry item per tier: Map of Fortress [tier] (Dead Front), Castle Key [tier] (Ice Castle), Fortress Voucher [tier] (reward currency)
  const itemByName = (re) => { for (const [k, e] of ITEMIDX) if (re.test(e.name)) return k; return null; };
  const tierItems = (tier) => {
    const alias = tier === 'Core' ? '(Core|Rabble)' : tier === 'Fear' ? '(Fear|Pier)' : tier;
    const out = {
      mapOfFortress: itemByName(new RegExp(`^(Map of Fortress|Fortress Map) \\[${tier}\\]`, 'i')) ?? itemByName(new RegExp(`^(Map of Fortress|Fortress Map) \\[${alias}\\]`, 'i')),
      castleKey: itemByName(new RegExp(`^Castle Key \\[${tier}\\]`, 'i')) ?? itemByName(new RegExp(`^Castle Key \\[${alias}\\]`, 'i')),
      fortressVoucher: itemByName(new RegExp(`^Fortress Voucher \\[${tier}\\]`, 'i')) ?? itemByName(new RegExp(`^Fortress Voucher \\[${alias}\\]`, 'i')),
      deadFrontTreasureBox: itemByName(new RegExp(`^Dead Front Treasure Box \\(${tier === 'Arc' ? 'Arch' : tier}\\)`, 'i')),
      iceCastleTreasureBox: itemByName(new RegExp(`^Ice Castle Treasure Box \\(${tier === 'Arc' ? 'Arch' : tier}\\)`, 'i')),
    };
    for (const v of Object.values(out)) if (v) useItem(v);
    return out;
  };
  const TIERS = ['Core', 'Fear', 'Baron', 'Earl', 'Duke', 'Arc', 'Doom', 'Hell'];

  // Dead Front monster blocks: 37 slots per tier; the block base is found from the two bosses the result table scores
  const DF_SLOT_ROLE = ['lane', 'lane', 'lane', 'lane', 'lane', 'lane', 'summon?', 'lane', 'lane', 'lane', 'lane', 'lane', 'fortress', 'fortress', 'midBoss', 'fortress', 'keep',
    'keep', 'keep', 'keep(summoner)', 'keep(spawner)', 'finalBoss', 'lane', 'lane', 'lane', 'lane', 'fortress', 'fortress', 'keep', 'summoned?', 'statue', 'fortress', 'fortress',
    'fortress', 'lane', 'lane', 'lane'];
  function dfMonsterBlock(midBoss) {
    const base = midBoss - 14;
    const slots = [];
    for (let s = 0; s < 37; s++) { const id = base + s; if (monDat.has(id)) { useMonster(id); slots.push([s, id, DF_SLOT_ROLE[s]]); } }
    return { base, slots };
  }
  const deadFront = { name: 'Dead Front', partyWarType: 1, lobbies: pwLobbies.filter((i) => MODE_OF.get(i)?.mode === 'deadFrontLobby'), teams,
    schedule: schedule(1), timeline: pwTimeline(1), config: pwConfig[1], officers: dfOfficers, tiers: [] };
  const iceCastle = { name: 'Ice Castle', partyWarType: 2, lobbies: pwLobbies.filter((i) => MODE_OF.get(i)?.mode === 'iceCastleLobby'), teams,
    schedule: schedule(2), timeline: pwTimeline(2), config: pwConfig[2], officers: icOfficers, tiers: [], checkpoints: icCheckpoints, towerTarget: null };
  for (const tier of TIERS) {
    const dfMaps = pwFields.filter((i) => MODE_OF.get(i)?.mode === 'deadFront' && MODE_OF.get(i)?.tier?.toLowerCase() === tier.toLowerCase());
    const icMaps = pwFields.filter((i) => MODE_OF.get(i)?.mode === 'iceCastle' && MODE_OF.get(i)?.tier?.toLowerCase() === tier.toLowerCase());
    if (dfMaps.length) {
      const t = { tier, maps: dfMaps.map((i) => ({ map: i, variant: MODE_OF.get(i).variant, level: MAPOUT[i].level, registrationLevel: pwField[i]?.level ?? null, entryLevel: pwField[i]?.entryLevel ?? MAPOUT[i].level,
        maxParties: pwField[i]?.maxParties ?? null, officers: dfOfficers.filter((o) => o.map === i).map((o) => o.npc), officerPlaced: dfOfficers.some((o) => o.map === i && o.placed.length) })), items: tierItems(tier) };
      const rs = result[dfMaps[0]];
      const mons = (rs?.killPoints || []).filter((k) => k[2] === 'monster').map((k) => k[0]);
      if (mons.length >= 2) {
        const mid = Math.min(...mons), fin = Math.max(...mons);
        t.bosses = { mid, final: fin, midPoints: rs.killPoints.find((k) => k[0] === mid)[1], finalPoints: rs.killPoints.find((k) => k[0] === fin)[1] };
        t.monsters = dfMonsterBlock(mid);
      }
      deadFront.tiers.push(t);
    }
    if (icMaps.length) {
      const i = icMaps[0];
      const rs = result[i];
      const base = rs?.killPoints.filter((k) => k[2] === 'monster').map((k) => k[0]).reduce((a, b) => Math.min(a, b), Infinity);
      const block = Number.isFinite(base) ? base - 3 : null; // first scoring monster = Aril at slot 3
      const slots = [];
      if (block !== null) for (let s = 0; s < 73; s++) if (monDat.has(block + s)) { useMonster(block + s); slots.push([s, block + s]); }
      const sm = MAPOUT[i]?.scriptMonsters || [];
      iceCastle.tiers.push({ tier, maps: icMaps.map((q) => ({ map: q, level: MAPOUT[q].level, registrationLevel: pwField[q]?.level ?? null, entryLevel: pwField[q]?.entryLevel ?? MAPOUT[q].level,
        maxParties: pwField[q]?.maxParties ?? null, officers: icOfficers.filter((o) => o.map === q).map((o) => o.npc), officerPlaced: icOfficers.some((o) => o.map === q && o.placed.length) })), items: tierItems(tier),
        monsters: { base: block, slots }, towerDamage: towerDamage[i] || null,
        scriptOrder: sm.length ? sm.map((id) => (block !== null && id >= block && id < block + 73 ? `s${id - block}` : id)) : null,
        treasureBoxes: sm.filter((id) => !(block !== null && id >= block && id < block + 73)) });
    }
  }
  // tower defence target (all IC tower attackers walk to the Tower of Shield)
  const tgt = uniq(targetPos.map((q) => `${q[1]},${q[2]},${q[3]}`));
  iceCastle.towerTarget = { targets: tgt.map((s) => s.split(',').map(Number)), monsters: targetPos.map((q) => q[0]) };
  deadFront.fields = Object.fromEntries(Object.entries(pwField).filter(([mi]) => MODE_OF.get(+mi)?.mode === 'deadFront'));
  iceCastle.fields = Object.fromEntries(Object.entries(pwField).filter(([mi]) => MODE_OF.get(+mi)?.mode === 'iceCastle'));
  const strayFields = Object.keys(pwField).filter((mi) => !deadFront.fields[mi] && !iceCastle.fields[mi]);
  if (strayFields.length) { deadFront.fieldsNotInMaplist = {}; for (const mi of strayFields) (pwField[mi].contentType === 2 ? (iceCastle.fieldsNotInMaplist ||= {}) : deadFront.fieldsNotInMaplist)[mi] = pwField[mi]; if (!Object.keys(deadFront.fieldsNotInMaplist).length) delete deadFront.fieldsNotInMaplist; }
  for (const [mi, f] of Object.entries(pwField)) { const want = MODE_OF.get(+mi)?.mode; if (want && ((f.contentType === 1) !== (want === 'deadFront'))) hard(`partywar field ${mi}: ContentType ${f.contentType} but map mode ${want}`); }
  deadFront.depots = depots.map(([n, lv, d]) => [n, lv, d]);
  deadFront.result = Object.fromEntries(Object.entries(result).filter(([mi]) => MODE_OF.get(+mi)?.mode === 'deadFront'));
  iceCastle.result = Object.fromEntries(Object.entries(result).filter(([mi]) => MODE_OF.get(+mi)?.mode === 'iceCastle'));
  iceCastle.towerDamage = towerDamage;

  // Dead Front objective graph (message codes of stringtable_deadfront.txt; bricks by name in brick.csv)
  const brickName = (id) => BRICKS[id]?.name || '';
  const dfLayout = (mi) => {
    const o = MAPOUT[mi]; if (!o) return null;
    const lanes = {};
    for (const b of o.bricks || []) {
      const vis = BRICKS[b[1]]?.visual?.mesh || '';
      const act = BRICKS[b[1]]?.act?.src || '';
      const m = /canyon_([a-d])(\d)/.exec(act);
      if (m) (lanes[m[1].toUpperCase()] ||= { barriers: [] }).barriers[+m[2] - 1] = b[0];
    }
    // lane depots: nearest depot NPCs of each level to the lane's barriers
    const dep = (o.npcs || []).filter((q) => NPC.get(q[0])?.jobs.some(([jt]) => jt === 39));
    for (const [ln, L_] of Object.entries(lanes)) {
      const pts = L_.barriers.map((uid) => o.bricks.find((b) => b[0] === uid)).filter(Boolean);
      const cx = pts.reduce((a, b) => a + b[2], 0) / pts.length, cy = pts.reduce((a, b) => a + b[3], 0) / pts.length;
      L_.center = [r3(cx), r3(cy)];
      L_.depotsNearest = [1, 2, 3].map((lv) => {
        const cands = dep.filter((q) => depots.find((d) => d[0] === q[0])?.[1] === lv);
        cands.sort((a, b) => Math.hypot(a[1] - cx, a[2] - cy) - Math.hypot(b[1] - cx, b[2] - cy));
        return cands[0]?.[0] ?? null;
      });
    }
    return { lanes, entrances: (o.bricks || []).filter((b) => /Entrance Barrier/i.test(brickName(b[1]))).map((b) => b[0]) };
  };
  deadFront.layout = dfLayout(deadFront.tiers[0]?.maps[0]?.map);
  // lane -> team entrance (the four "Entrance Barrier" bricks, IsCreate 0 = spawned by the script for the start countdown)
  if (deadFront.layout) {
    const o = MAPOUT[deadFront.tiers[0].maps[0].map];
    for (const [ln, lane] of Object.entries(deadFront.layout.lanes)) {
      const b1 = o.bricks.find((b) => b[0] === lane.barriers[0]);
      const ent = deadFront.layout.entrances.map((u) => o.bricks.find((b) => b[0] === u)).sort((a, b) => Math.hypot(a[2] - b1[2], a[3] - b1[3]) - Math.hypot(b[2] - b1[2], b[3] - b1[3]))[0];
      lane.entrance = ent ? ent[0] : null;
      lane.team = 'ABCD'.indexOf(ln);
    }
    // team start points (field.csv StartPoint1..4, data): start k belongs to team k-1; check that it lies just outside
    // the entrance barrier of the lane of the same team (validates the lane <-> team binding)
    const f = pwField[deadFront.tiers[0].maps[0].map];
    if (f) for (const [ln, lane] of Object.entries(deadFront.layout.lanes)) {
      const s = f.starts[lane.team]; if (!s) continue;
      lane.start = [s.x, s.y];
      const nearestEnt = deadFront.layout.entrances.map((u) => o.bricks.find((b) => b[0] === u)).sort((a, b) => Math.hypot(a[2] - s.x, a[3] - s.y) - Math.hypot(b[2] - s.x, b[3] - s.y))[0];
      if (nearestEnt?.[0] !== lane.entrance) hard(`DF lane ${ln}: start point ${s.x},${s.y} is nearest to entrance ${nearestEnt?.[0]}, not ${lane.entrance}`);
      lane.startToEntrance = r3(Math.hypot(nearestEnt[2] - s.x, nearestEnt[3] - s.y));
    }
  }
  // lane monster groups: scriptmonster_<dk map>.csv lists the script's monsters in spawn order; the first 16 entries are
  // four groups of four (one group per lane: basilisk / salamander / fate / bartux slots), then the fortress monsters
  {
    const dkCore = deadFront.tiers.find((t) => t.tier === 'Core')?.maps.find((m) => m.variant === 'dk')?.map;
    const sm = MAPOUT[dkCore]?.scriptMonsters || [];
    const base = deadFront.tiers.find((t) => t.tier === 'Core')?.monsters?.base;
    if (sm.length >= 16 && base) {
      const slotOf = (id) => id - base;
      deadFront.scriptOrder = { map: dkCore, slots: sm.map((id) => (monDat.has(id) && id >= base && id < base + 37 ? slotOf(id) : id)) };
      deadFront.laneSlots = { A: sm.slice(0, 4).map(slotOf), B: sm.slice(4, 8).map(slotOf), C: sm.slice(8, 12).map(slotOf), D: sm.slice(12, 16).map(slotOf) };
      const rest = sm.slice(16).filter((id) => id >= base && id < base + 37);
      deadFront.fortressSlots = rest.map(slotOf);
      deadFront.treasureBoxes = sm.filter((id) => !(id >= base && id < base + 37));
      deadFront.notInScript = deadFront.tiers.find((t) => t.tier === 'Core').monsters.slots.map((q) => q[0]).filter((s) => !sm.includes(base + s));
    }
    // armory treasure boxes: the "Treasure Box" (treasurebox03) monsters 3350-3426 come in blocks of 9 (3300-3331 are level-1 event boxes, not armory blocks) (1 money box +
    // 8 item boxes).  The DK script lists name the blocks of Core (3350), Arc (3400), Doom (3409) and Hell (3418); the
    // four remaining blocks (3360, 3370, 3380, 3390) are assigned in tier order to Fear, Baron, Earl, Duke (inferred).
    const boxes = [...monDat.keys()].filter((i) => i >= 3350 && i < 3430 && /treasure\s*box/i.test(monName(i) || '') && monDat.get(i).shape.toLowerCase() === 'treasurebox03').sort((a, b) => a - b);
    const blocks = [];
    for (const i of boxes) { const last = blocks[blocks.length - 1]; if (last && i - last[last.length - 1] <= 2 && last.length < 9) last.push(i); else blocks.push([i]); }
    const claimed = new Set();
    for (const t of deadFront.tiers) {
      const dk = t.maps.find((m) => m.variant === 'dk')?.map;
      const s = MAPOUT[dk]?.scriptMonsters;
      const tb = s ? s.filter((id) => !(t.monsters && id >= t.monsters.base && id < t.monsters.base + 37)) : [];
      if (tb.length) { t.treasureBoxes = tb; t.treasureBoxesFrom = MAPOUT[dk].files.scriptMonsters; const b = blocks.find((x) => x.includes(tb[0])); if (b) claimed.add(b); }
    }
    const free = blocks.filter((b) => !claimed.has(b) && b.length >= 7);
    for (const t of deadFront.tiers) if (!t.treasureBoxes) { const b = free.shift(); if (b) { t.treasureBoxes = b; t.treasureBoxesFrom = 'inferred (unclaimed Treasure Box block, tier order)'; } }
    for (const t of deadFront.tiers) for (const i of t.treasureBoxes || []) useMonster(i);
    deadFront.treasureBoxBlocks = blocks;
  }

  // ---------------------------------------------------------------- objective flows (state machines for the engine)
  // Built from the message codes of the map string tables (developer notes quoted in docs/formats/events.md) and the
  // brick / NPC placements. Every referenced code, brick UID and NPC is validated below against every map of the mode.
  //   confidence: "data" = directly in the tables, "notes" = from the developer comments of the string file,
  //               "inferred" = binding of trigger -> effect not in the client (server script), chosen from names/positions
  const DF_FLOW = [
    { id: 'waitStart', phase: 'waitStart', messages: [1001, 1002], spawnBricks: 'entrances', teleport: 'fields[m].starts[team]', confidence: 'data', desc: 'each party enters at the start point of its team (field.csv StartPoint k = team k-1, just outside the lane entrance barrier); countdown; the lane entrance barriers (IsCreate 0) stand until the fortress phase starts' },
    { id: 'start', phase: 'fortress', messages: [1003], removeBricks: 'entrances', confidence: 'notes', desc: 'battle start effect; entrance barriers removed' },
    { id: 'canyon1', messages: [1101], removeBricks: 'lane.barriers[0]', guards: 'laneSlots[0]', confidence: 'inferred', desc: 'canyon stage 1 broken through (vine pillar DEAD anim)' },
    { id: 'depot1', messages: [1104, 1105, 1108], occupy: 'lane.depotsNearest[0]', confidence: 'data', desc: 'optional: occupy the 1st supply depot (captureSec channel) for its points' },
    { id: 'canyon2', after: ['canyon1'], messages: [1102], removeBricks: 'lane.barriers[1]', guards: 'laneSlots[1]', confidence: 'inferred' },
    { id: 'depot2', messages: [1104, 1106, 1108], occupy: 'lane.depotsNearest[1]', confidence: 'data' },
    { id: 'canyon3', after: ['canyon2'], messages: [1103], removeBricks: 'lane.barriers[2]', guards: 'laneSlots[2..3]', confidence: 'inferred' },
    { id: 'depot3', messages: [1104, 1107, 1108], occupy: 'lane.depotsNearest[2]', confidence: 'data' },
    { id: 'junction', after: ['canyon3'], messages: [1201], removeBricks: [117], confidence: 'inferred', desc: 'junction cleared: thorned barrier 117 on the bridge entrance collapses' },
    { id: 'bridge', after: ['junction'], messages: [1202], removeBricks: [118], guards: 'fortressSlots (before Las Alhage)', confidence: 'inferred', desc: 'bridge broken through: thorned barrier 118 on the road to the fortress' },
    { id: 'midBoss', after: ['bridge'], messages: [1203], kill: 'bosses.mid', removeBricks: [119, 136, 137], points: 'result.killPoints[mid]', confidence: 'notes', desc: 'Las Alhage dies; his Magical Field (119) and field bricks (136/137) vanish' },
    { id: 'innerCastle', after: ['midBoss'], messages: [1204], removeBricks: [122, 123, 124, 125, 126, 138, 139, 140, 141], confidence: 'inferred', desc: 'gate to the keep opened (Inner Castle Gates 122-126, ivy bricks 138-141)' },
    { id: 'levers', after: ['innerCastle'], npcs: 'levers', dialog: [10001, 10006, 10011, 10016], messages: [1601, 1602], confidence: 'notes', desc: 'the NE/NW/SE/SW slate-room levers (operate once each; exception text afterwards)' },
    { id: 'slates', after: ['levers'], npcs: 'slates', dialog: [10021, 10026, 10031, 10036], messages: [1205, 1206, 1207, 1208, 1209], gaugeMs: 10000, confidence: 'notes', desc: 'decipher the four slates (10 s gauge each)' },
    { id: 'book', after: ['slates'], npcs: 'book', dialog: [10041], success: 1210, failure: 1211, removeBricks: [127, 128, 129, 133, 134], confidence: 'notes', desc: 'read the glowing letters of the Ancient Book: succeeds only after all four slates (1210 hidden path) else 1211' },
    { id: 'secretWall', after: ['book'], npcs: 'secretWall', dialog: [10046], messages: [1212], removeBricks: [135, 142], confidence: 'notes', desc: 'push the protruding brick: the Ancient Stone Wall collapses into the boss room' },
    { id: 'finalBoss', after: ['secretWall'], kill: 'bosses.final', lines: { enter: [1301, 1302, 1303], transform: [1304, 1305, 1306], death: [1307, 1308, 1309] }, bricks: [130, 131, 132], points: 'result.killPoints[final]', confidence: 'notes', desc: 'Oppucus: entrance lines, transformation lines, death lines; Wall of Fire 130 and the Orphina bricks 131/132 (HP 600000) stand in the boss room' },
    { id: 'armories', after: ['finalBoss'], messages: [1505, 1506], removeBricks: [120, 121], spawn: 'treasureBoxes', confidence: 'inferred', desc: 'paths to the west/east armories secured (wood fences 120/121); the armory treasure boxes spawn' },
    { id: 'waitPvp', phase: 'waitPvp', messages: [1401], teleport: 'fields[m].pvpPoints[team]', confidence: 'data', desc: 'the parties are moved to the four final-battle points (field.csv PvPPoint1..4)' },
    { id: 'pvp', phase: 'pvp', messages: [1402, 1403, 1404], afterWin: 'fields[m].winnerRespawn', afterLose: 'fields[m].loserRespawn', confidence: 'data', solo: 'skipped (no opponent): resolved as an uncontested win, the player is moved to winnerRespawn' },
    { id: 'waitExtension', phase: 'waitExtension', messages: [1406], confidence: 'data', solo: 'skipped' },
    { id: 'extension', phase: 'extension', messages: [1402, 1403, 1404], confidence: 'data', solo: 'skipped' },
    { id: 'end', phase: 'waitClose', messages: [1501, 1502, 1503, 1504], npcs: 'exits', dialog: [30001, 40000], optional: ['npcs', 'dialog'], kickTo: 'fields[m].endWarRespawn', confidence: 'data', desc: 'result window (partywarui 2008), leave through Reezena (victory / defeat NPC); when the close timer ends (and on maps without a Reezena placement: 40-43, 78-81) everybody is moved to fields[m].endWarRespawn (Chain of Fire 45 / 84)' },
  ];
  const IC_FLOW = [
    { id: 'waitStart', phase: 'waitStart', messages: [1001, 1002], teleport: 'fields[m].starts[team]', confidence: 'data', desc: 'each party enters at the start point of its team (field.csv StartPoint k = team k-1; see teamCorners)' },
    { id: 'start', phase: 'fortress', messages: [1003], calls: [1, 2, 4, 5, 7, 8, 10, 11], callsPerTeam: 'teamCorners[team].calls', confidence: 'inferred', desc: 'each team starts in its corner; the wolf packs of that corner (teamCorners: the call groups nearest to the start point)' },
    { id: 'barbican1', messages: [1101], removeBricks: [101, 102, 103, 104, 105, 106, 107, 108], confidence: 'inferred', desc: 'first barbican opened (outer Old Iron Gates of the corner)' },
    { id: 'wolfStatue', destroyBrick: [131, 132, 133, 134], messages: [1102, 1103], points: 'result.killPoints[36818]', confidence: 'notes', desc: 'destroy the corner Statue of Wolf (brick 36818, HP 100) for points' },
    { id: 'fairies', calls: [13, 14, 16, 17, 19, 20, 22, 23], confidence: 'inferred' },
    { id: 'barbican2', messages: [1104], removeBricks: [109, 110, 111, 112], confidence: 'inferred' },
    { id: 'aril', calls: [25, 26, 28, 29, 31, 32, 34, 35], kill: 'Aril', messages: [1105, 1106], points: 'result.killPoints[aril]', confidence: 'notes', desc: 'small boss Aril (one per team edge) with Penril Slaves' },
    { id: 'barbican3', messages: [1107], removeBricks: [113, 114, 115, 116], confidence: 'inferred', desc: 'last barbican: the way to the castle' },
    { id: 'crystal', destroyBrick: [135, 136], messages: [1201, 1202], points: 'result.killPoints[36819]', confidence: 'notes', desc: 'destroy a Crystal (N/S, brick 36819) for points' },
    { id: 'castleGates', calls: [37, 38, 39, 42, 43, 44, 47, 48, 49, 52, 53, 54, 57, 58, 59, 62, 63, 64], removeBricks: [117, 118, 119, 120, 121, 122, 123, 124], confidence: 'inferred' },
    { id: 'pawAltars', calls: [67, 68, 69, 72, 73, 74, 77, 78, 79, 82, 83, 84], bricks: [138, 139, 140, 141], npcs: 'paws', dialog: [10001, 10006, 10015, 10020],
      messages: [1203, 1204, 1205, 1206, 1207, 1208, 1209, 1210, 1211, 1214, 1215, 1216, 1217, 1218, 1219, 1220, 1221, 1222], confidence: 'notes',
      desc: 'break the altar doors, clear the altar (switch refuses while monsters are near: 10004/10009), operate the right and left paw switches of the west and east wolf statue' },
    { id: 'iceShield', after: ['pawAltars'], messages: [1212, 1223], confidence: 'notes', desc: 'both paws of a statue done: its ice shield melts' },
    { id: 'wolfLevers', after: ['iceShield'], npcs: 'levers', dialog: [10011, 10025], messages: [1213, 1224], removeBricks: [125, 126, 127, 128, 129, 130], confidence: 'notes', desc: 'operate the western / eastern lever: the central gate opens' },
    { id: 'qusil', after: ['wolfLevers'], calls: [87, 88, 89, 90, 92, 93, 94, 95], kill: 'Qusil', messages: [1225, 1226, 1227, 1228], points: 'result.killPoints[qusil]', confidence: 'notes', desc: 'middle boss Qusil (N and S); the passage to the Tower of Shield chamber opens; Regina (5671) offers to continue (30000)' },
    { id: 'aslaStatue', after: ['qusil'], npcs: 'asla', dialog: [10029, 10031, 10033], messages: [1301, 1302, 1303], confidence: 'notes', desc: 'activate the Asla Statue (refuses while the middle boss lives: 10033)' },
    { id: 'towerDefence1', after: ['aslaStatue'], messages: [1304, 1305, 1306, 1307, 1308], spawnAt: 'Gate of Devildom bricks 142-147', walkTo: 'towerTarget', damage: 'towerDamage', confidence: 'notes', desc: 'stage 1 (two phases), then the boss speaks' },
    { id: 'towerDefence2', after: ['towerDefence1'], messages: [1309, 1310, 1311, 1312, 1313], confidence: 'notes' },
    { id: 'towerDefence3', after: ['towerDefence2'], messages: [1314, 1315, 1316, 1317, 1318, 1319, 1320, 25301, 25302, 25303], kill: 'Karke', points: 'result.killPoints[karke]', confidence: 'notes', desc: 'stage 3 with Karke; Asla thanks the troopers; shield warnings 25302/25303' },
    { id: 'reenergize', npcs: 'asla', dialog: [10034, 10035, 10036, 10037], dilCost: 100000, confidence: 'data', desc: 'donate 100,000 DIL at the Asla Statue altar to re-energize the Tower of Shield' },
    { id: 'roundCleared', after: ['towerDefence3'], messages: [1505], confidence: 'notes' },
    { id: 'waitPvp', phase: 'waitPvp', messages: [1401], teleport: 'fields[m].pvpPoints[team]', confidence: 'data', desc: 'the parties are moved to the four final-battle points around the Asla Statue (field.csv PvPPoint1..4)' },
    { id: 'pvp', phase: 'pvp', messages: [1402, 1403, 1404, 1405, 1406], afterWin: 'fields[m].winnerRespawn', afterLose: 'fields[m].loserRespawn', confidence: 'data', solo: 'skipped (no opponent): resolved as an uncontested win, the player is moved to winnerRespawn (next to the victory Reezena)' },
    { id: 'extension', phase: 'extension', messages: [1407, 1408], confidence: 'data', solo: 'skipped' },
    { id: 'end', phase: 'waitClose', messages: [1501, 1502, 1503, 1504], npcs: 'exits', dialog: [30001], optional: ['npcs', 'dialog'], kickTo: 'fields[m].endWarRespawn', confidence: 'data', desc: 'leave through Reezena; when the close timer ends everybody is moved to fields[m].endWarRespawn (Frozen Valley 166)' },
  ];
  deadFront.flow = DF_FLOW;
  iceCastle.flow = IC_FLOW;
  useBrick(36820); // Tower of Shield (spawned by the script, not in the brick placement file)
  iceCastle.towerBrick = 36820;
  // team corners: field.csv start point of each team -> the nearest Statue of Wolf, first-barbican gate and corner call
  // groups (the corner packs of IC_FLOW.start).  Start point = data, the association = nearest by position (inferred).
  {
    const icMap = iceCastle.tiers[0]?.maps[0]?.map, o = MAPOUT[icMap], f = pwField[icMap];
    if (o && f) {
      const d = (a, x, y) => Math.hypot(a[0] - x, a[1] - y);
      const centroid = (rows) => [rows.reduce((a, q) => a + q[1], 0) / rows.length, rows.reduce((a, q) => a + q[2], 0) / rows.length];
      const cornerCalls = [1, 2, 4, 5, 7, 8, 10, 11].filter((c) => o.calls?.[c]).map((c) => [c, centroid(o.calls[c])]);
      const statues = (o.bricks || []).filter((b) => b[1] === 36818), gates = (o.bricks || []).filter((b) => b[0] >= 101 && b[0] <= 108);
      iceCastle.teamCorners = f.starts.map((s, team) => {
        const near = (list, pos) => [...list].sort((a, b) => d(pos(a), s.x, s.y) - d(pos(b), s.x, s.y));
        return { team, start: [s.x, s.y], statue: near(statues, (b) => [b[2], b[3]])[0]?.[0] ?? null, gates: near(gates, (b) => [b[2], b[3]]).slice(0, 2).map((b) => b[0]),
          calls: near(cornerCalls, (q) => q[1]).slice(0, 2).map((q) => q[0]).sort((a, b) => a - b), confidence: 'start = data; statue/gates/calls = nearest by position (inferred)' };
      });
      const allCalls = iceCastle.teamCorners.flatMap((t) => t.calls), allStatues = iceCastle.teamCorners.map((t) => t.statue);
      if (new Set(allCalls).size !== allCalls.length) soft(`IC teamCorners: a corner call group is nearest to two start points (${allCalls.join(',')})`);
      if (new Set(allStatues).size !== allStatues.length) soft(`IC teamCorners: a Statue of Wolf is nearest to two start points (${allStatues.join(',')})`);
    }
  }
  // objective NPC roles per map (from the NPC names / jobs, identical layout on every tier)
  const npcRole = (mode, id) => {
    const n = NPC.get(id)?.name || '';
    if (NPC.get(id)?.jobs.some(([t]) => t === 39)) return 'depot';
    if (/^Lever$/i.test(n)) return 'levers';
    if (/^Slate$/i.test(n)) return 'slates';
    if (/Ancient Book/i.test(n)) return 'book';
    if (NPC.get(id)?.shape === 'secretwall') return 'secretWall';
    if (/Regina_Escape|Rezeena|Reezena/i.test(n) || NPC.get(id)?.jobs.some(([t, j]) => t === 31 && j === 30001)) return 'exits';
    if (/Regina_Middle/i.test(n) || NPC.get(id)?.jobs.some(([t, j]) => t === 31 && j === 30000)) return 'regina';
    if (/Paw/i.test(n)) return 'paws';
    if (/Lever/i.test(n)) return 'levers';
    if (/Asla|Asra/i.test(n) || NPC.get(id)?.shape === 'asra') return 'asla';
    return null;
  };
  for (const [mi, o] of Object.entries(MAPOUT)) {
    if (!['deadFront', 'iceCastle'].includes(o.mode)) continue;
    const roles = {};
    for (const q of o.npcs || []) { const r = npcRole(o.mode, q[0]); if (r) (roles[r] ||= []).push(q[0]); }
    o.objectiveNpcs = roles;
    if (o.mode === 'iceCastle') {
      const t = iceCastle.tiers.find((x) => x.maps.some((m) => m.map === +mi));
      const s = (k) => t?.monsters.slots.filter((q) => new RegExp(k, 'i').test(monName(q[1]) || '')).map((q) => q[1]) || [];
      o.bosses = { aril: s('^Aril'), qusil: s('^Qusil'), karke: s('^Karke') };
    }
  }

  // ---------------------------------------------------------------- flow validation (codes / bricks / npcs exist on every map of the mode)
  const flowCheck = (mode, flow) => {
    const issues = [];
    for (const [mi, o] of Object.entries(MAPOUT)) {
      if (o.mode !== mode) continue;
      const tbl = o.strings ? TEXT.tables[o.strings[0]][o.strings[1]] : null;
      const codeOk = (c) => !!(tbl && tbl[c]) || !!DIALOGS[mi]?.nodes[c];
      const uids = new Set((o.bricks || []).map((b) => b[0]));
      for (const st of flow) {
        for (const c of [...(st.messages || []), ...(st.optional?.includes('dialog') ? [] : (st.dialog || [])), ...Object.values(st.lines || {}).flat(), st.success, st.failure].filter((x) => x !== undefined)) if (!codeOk(c)) issues.push(`${mi} ${st.id}: code ${c} has no text`);
        for (const u of [...(Array.isArray(st.removeBricks) ? st.removeBricks : []), ...(st.bricks || []), ...(st.destroyBrick || [])]) if (!uids.has(u)) issues.push(`${mi} ${st.id}: brick uid ${u} not placed`);
        if (typeof st.npcs === 'string' && !st.optional?.includes('npcs') && !(o.objectiveNpcs?.[st.npcs]?.length)) issues.push(`${mi} ${st.id}: no ${st.npcs} NPC placed`);
        for (const c of st.calls || []) if (!o.calls?.[c]) issues.push(`${mi} ${st.id}: call ${c} missing`);
      }
    }
    return issues;
  };
  const dfIssues = flowCheck('deadFront', DF_FLOW), icIssues = flowCheck('iceCastle', IC_FLOW);
  deadFront.flowValidation = dfIssues.length ? dfIssues : 'every message code, brick uid and objective NPC of the flow exists on all 16 Dead Front maps';
  iceCastle.flowValidation = icIssues.length ? icIssues : 'every message code, brick uid, call group and objective NPC of the flow exists on all 8 Ice Castle maps';
  for (const i of [...dfIssues, ...icIssues].slice(0, 20)) soft(`flow: ${i}`);

  // ================================================================================================
  // COLOSSEUM
  // ================================================================================================
  const brBuff = headerTable('share/colosseum/battleroyal/buff_table.csv').rows.map((r) => {
    const buffs = []; for (let k = 0; k < num(r.Buff_Count); k++) { const s = num(r[`Buff_Index_${k}`]); useStatus(s); buffs.push([s, num(r[`Buff_Rate_${k}`])]); }
    return { index: num(r.Index), buffs };
  });
  const brRenewBuff = headerTable('share/colosseum/battleroyal_renew/buff_table.csv').rows.map((r) => { const buffs = []; for (let k = 0; k < num(r.Buff_Count); k++) { const s = num(r[`Buff_Index_${k}`]); useStatus(s); buffs.push([s, num(r[`Buff_Rate_${k}`])]); } return { index: num(r.Index), buffs }; });
  const posPairs = (r, px, py, n) => { const out = []; for (let k = 0; k < n; k++) { const x = num(r[`${px}${String(k).padStart(2, '0')}`]), y = num(r[`${py}${String(k).padStart(2, '0')}`]); if (x || y) out.push([x, y]); } return out; };
  const brRenewRow = colBRR[0] || {};
  if (num(brRenewRow.EntranceIndex)) useItem(num(brRenewRow.EntranceIndex));
  const brRenewRewards = headerTable('share/colosseum/battleroyal_renew/reward_br.csv').rows.map((r) => { useItem(num(r.Rank_ItemIdx)); return { rank: [num(r.LowRank), num(r.HighRank)], killPoint: num(r.Kill_Per_Point), rankPoint: num(r.Rank_Point), item: [num(r.Rank_ItemIdx), num(r.Rank_ItemCnt)] }; });
  const pmReward = headerTable('share/colosseum/partymatch/reward.csv').rows.map((r) => { useItem(num(r.Coin_Index)); return typed(r); });
  const colosseum = {
    name: 'Colosseum', lobby: 162, abilityCap: useAbilityCap('share/pc/abilitycap_colosseum.csv'),
    lobbyNpcs: (MAPOUT[162]?.npcs || []).map((q) => q[0]),
    arena: {
      solo: 615, party: 616,
      entryNpc: [...NPC].filter(([, n]) => n.jobs.some(([t, j]) => t === 19 && (j === 615 || j === 616))).map(([i]) => { useNpc(i); return i; }),
      tickets: { solo: itemByName(/^Colosseum Arena Entrance Ticket$/i), party: itemByName(/^Colosseum Arena Party Entrance Ticket$/i) },
    },
    battleRoyal: {
      classic: { maps: colBR.map((r) => ({ index: num(r.Index), map: num(r.MapIndex), members: num(r.MemberCount), positions: posPairs(r, 'PosX_', 'PosY_', num(r.MemberCount)) })),
        grade: headerTable('share/colosseum/battleroyal/grade.csv').rows.map(typed), playtime: headerTable('share/colosseum/battleroyal/playtime.csv').rows.map(typed),
        rewards: headerTable('share/colosseum/battleroyal/reward_br.csv').rows.map((r, i) => ({ ...typed(r), Description: L(`battleroyal#reward_br.csv#1|${i + 1}`) || r.Description })), buffs: brBuff },
      renew: { rows: colBRR.map(typed), grade: headerTable('share/colosseum/battleroyal_renew/grade.csv').rows.map(typed), playtime: headerTable('share/colosseum/battleroyal_renew/playtime.csv').rows.map(typed), rewards: brRenewRewards, buffs: brRenewBuff },
    },
    partyMatch: { maps: colPM.map((r) => ({ index: num(r.Index), map: num(r.MapIndex), desc: L(`partymatch#list.csv#2|1`) || r.Descript, members: num(r.MemberCount), teamA: posPairs(r, 'APosX_', 'APosY_', 7), teamB: posPairs(r, 'BPosX_', 'BPosY_', 7) })),
      grade: headerTable('share/colosseum/partymatch/grade.csv').rows.map(typed), playtime: headerTable('share/colosseum/partymatch/playtime.csv').rows.map(typed), rewards: pmReward },
    guildMatch: { maps: colGM.map((r) => ({ index: num(r.Index), map: num(r.MapIndex), desc: r.Descript, members: num(r.MemberCount), teamA: posPairs(r, 'APosX_', 'APosY_', 7), teamB: posPairs(r, 'BPosX_', 'BPosY_', 7), observer: [num(r.ObserverPosX), num(r.ObserverPosY)] })),
      tournament: { config: kvTable('share/guildtournament/config.csv'), donation: headerTable('share/guildtournament/donation.csv').rows.map(typed), bracket: headerTable('share/guildtournament/match.csv').rows.map(typed) } },
    pvp3v3: { config: headerTable('share/dkrpvpbattle/config.csv').rows.map(typed), matchTime: headerTable('share/dkrpvpbattle/matchtime.csv').rows.map(typed) },
    infiniteBattle: [153, 154, 155, 613].filter((i) => MAPOUT[i]).map((i) => ({ map: i, entryNpcs: [...NPC].filter(([, n]) => n.jobs.some(([t, j]) => t === 19 && j === i)).map(([k]) => { useNpc(k); return k; }) })),
  };
  for (const v of Object.values(colosseum.arena.tickets)) if (v) useItem(v);
  // entry conditions quoted by the entry NPC greeting (stringtable_conv) — the server-side gate values
  const greetRules = (npcId) => {
    const n = NPC.get(npcId); const g = n?.comm ? L(txtKey('stringtable_conv.txt', 0, n.comm)) : null;
    if (!g) return null;
    const t = g.replace(/<[^>]+>/g, '');
    const all = (re) => [...t.matchAll(re)].map((m) => m.slice(1));
    return { levels: all(/(?:Entry level|Required Level|Entrance Level)\s*:?\s*(?:Lv\.\s*)?(\d+)/gi).map((q) => +q[0]),
      minutes: all(/(?:Time Limit|Limit)\s*:\s*(\d+)\s*min/gi).map((q) => +q[0]), dil: all(/Entry DIL\s*:\s*([\d,]+)/gi).map((q) => +q[0].replace(/,/g, '')),
      party: all(/(\d+)\s*players?\s*party/gi).map((q) => +q[0]), source: `stringtable_conv.txt#0|${n.comm}` };
  };
  const arenaGate = greetRules(colosseum.arena.entryNpc[0]);
  const txt22 = (mi, c) => { const s = MAP_TABLE.get(mi); return s ? tableSection(s, mi)[c]?.text || '' : ''; };
  const combo = (mi) => [202, 203, 204].map((c) => { const t = txt22(mi, c); const n = /(\d+)\s*Combo/i.exec(t); const pct = /(\d+)%/.exec(t); const mult = /(doubled|tripled|quadrupled)/i.exec(t);
    return { code: c, combo: n ? +n[1] : null, expMul: pct ? +pct[1] / 100 : mult ? { doubled: 2, tripled: 3, quadrupled: 4 }[mult[1].toLowerCase()] : null }; });
  colosseum.arena.rules = {
    gate: arenaGate, // levels [solo, party], minutes, dil, party size
    solo: { map: 615, level: arenaGate?.levels[0] ?? null, minutes: arenaGate?.minutes[0] ?? null, dil: arenaGate?.dil[0] ?? null, ticket: colosseum.arena.tickets.solo, waves: Object.keys(MAPOUT[615]?.calls || {}).map(Number), trophies: MAPOUT[615]?.scriptMonsters || [], exitNpc: (MAPOUT[615]?.npcs || []).map((q) => q[0]), combo: combo(615) },
    party: { map: 616, level: arenaGate?.levels[1] ?? null, minutes: arenaGate?.minutes[1] ?? null, dil: arenaGate?.dil[1] ?? null, partySize: arenaGate?.party[0] ?? null, ticket: colosseum.arena.tickets.party, waves: Object.keys(MAPOUT[616]?.calls || {}).map(Number), trophies: MAPOUT[616]?.scriptMonsters || [], exitNpc: (MAPOUT[616]?.npcs || []).map((q) => q[0]), combo: combo(616) },
    phases: [['waitStart', 30], ['dungeon', 31], ['comboTimer', 35], ['monstersAppearIn', 40], ['waitEnd', 39]].map(([id, code]) => ({ id, labelCode: code })),
    messages: { summon: 200, comboLost: 201, comboFail: 303, comboCount: 400, start: 1000, clear: 1001, fail: 1002, startSoon: 3000, failed: 3001, endSoon: 3002, notEnoughDil: 100, noTicket: 101, inventoryFull: 103 },
    dialogs: { inProgress: 20000, failedExit: 20010, clearedExit: 40000 },
    source: 'callmonster_615/616 (waves), scriptmonster_615/616 (trophy chests), stringtable_dungeon_22 cate 615/616, dungeon_615 dialog tree, NPC 5931 greeting',
  };
  // The solo arena 615 is the Battle Royale 163 prison layout: the 108 Old Bars bricks are identical (uid, brick, x, y,
  // dir) and the 15 solo champions stand on 15 of the 16 Battle Royale start cells (4 bars around each); one cell stays
  // empty.  36803 bars form the cross + corner walls between the quadrants.
  {
    const ring = colosseum.battleRoyal.classic.maps[0]?.positions || [];
    const a = MAPOUT[615]?.bricks || [], b = MAPOUT[163]?.bricks || [];
    const bk = (x) => x.slice(0, 5).join(',');
    const same = a.filter((x) => new Set(b.map(bk)).has(bk(x))).length;
    const champs = Object.entries(MAPOUT[615]?.calls || {}).flatMap(([c, rows]) => rows.map((q) => ({ call: +c, monster: q[0], at: [q[1], q[2]] })));
    const slotOf = (p) => ring.findIndex((r) => r[0] === p[0] && r[1] === p[1]);
    const cells = ring.map((p, slot) => {
      const bars = a.filter((x) => Math.hypot(x[2] - p[0], x[3] - p[1]) < 3).map((x) => x[0]);
      const ch = champs.filter((c) => slotOf(c.at) === slot);
      return { slot, at: p, bars, champion: ch[0] ? [ch[0].call, ch[0].monster] : null };
    });
    const free = cells.filter((c) => !c.champion).map((c) => c.slot);
    colosseum.arena.rules.solo.prison = {
      sameBricksAsBattleRoyal163: `${same}/${a.length}`, cells, emptyCells: free, dividers: a.filter((x) => x[1] === 36803).map((x) => x[0]),
      championsOffRing: champs.filter((c) => slotOf(c.at) < 0).length,
      confidence: 'layout = data (bricks and call cells); the bars of a cell opening when its call spawns = inferred (message 200 "Fighter came out from the prison")',
    };
    if (same !== a.length) soft(`Colosseum Arena 615: only ${same}/${a.length} bricks match Battle Royale 163`);
  }
  for (const ib of colosseum.infiniteBattle) {
    ib.gate = ib.entryNpcs.map(greetRules).find((g) => g && (g.levels.length || g.minutes.length)) || null;
    ib.waves = Object.keys(MAPOUT[ib.map]?.calls || {}).map(Number);
    ib.bossCalls = ib.waves.filter((c) => c >= 11);
    ib.messages = { summon: 230, perish: 300, maxAccumulation: 1101, acc80: 1106, acc90: 1107, acc95: 1108, clearUi: 1300, startUi: 2500, failUi: 3000, failed: 3001 };
    ib.scriptMonsters = MAPOUT[ib.map]?.scriptMonsters || [];
  }
  for (const [i] of [...NPC].filter(([, n]) => n.jobs.some(([t]) => [81, 82, 85, 93, 132].includes(t)))) useNpc(i);
  colosseum.jobNpcs = Object.fromEntries([81, 82, 85, 93, 132].map((t) => [t, [...NPC].filter(([, n]) => n.jobs.some(([jt]) => jt === t)).map(([i]) => i)]));
  for (const r of headerTable('share/guildtournament/donation.csv').rows) useItem(num(r.ItemIndex));

  // ================================================================================================
  // OTHER MODES (complete table parses)
  // ================================================================================================
  const others = {};
  others.partyPvpArenas = { maps: Object.keys(MAPOUT).map(Number).filter((i) => MODE_OF.get(i)?.mode === 'partyPvpArena') };
  // share/article/partypvp.csv: the party-duel arena modes (Annihilation battle / Buff Mode ...) per map, with wait time,
  // time limit, entry limit, entry-point window and the four start points; partypvpbuff.csv: buff items allowed in Buff Mode
  {
    const pp = headerTable('share/article/partypvp.csv');
    others.partyPvpArenas.modes = pp.rows.map((r, i) => {
      const o = typed(r); const en = L(`article#partypvp.csv#2|${i + 1}`); if (en) o.ModeName = en;
      o.starts = [0, 1, 2, 3].map((k) => [num(r[`Start_X_${k}`]), num(r[`Start_Y_${k}`])]);
      for (const k of [0, 1, 2, 3]) { delete o[`Start_X_${k}`]; delete o[`Start_Y_${k}`]; }
      if (!MAPS.has(num(r.MapIndex))) soft(`partypvp.csv row ${i + 1}: map ${r.MapIndex} not in maplist`);
      return o;
    });
    others.partyPvpArenas.buffs = headerTable('share/article/partypvpbuff.csv').rows.map((r, i) => {
      useStatus(num(r.StatusIndex)); useItem(num(r.ItemIndex));
      const en = L(`article#partypvpbuff.csv#4|${i + 1}`);
      return { index: num(r.Index), status: num(r.StatusIndex), baseStatus: num(r.BaseStatusIndex), item: num(r.ItemIndex), name: en || ITEMS[num(r.ItemIndex)]?.name || null, descKr: en ? undefined : r.Desc };
    });
  }
  others.siege = { config: kvTable('share/siege/config.csv'), location: headerTable('share/siege/location.csv').rows.map(typed), tax: kvTable('share/siege/tax.csv'), taxRatio: kvTable('share/siege/taxratio.csv'),
    observer: headerTable('share/observer/info.csv').rawRows.slice(1).filter((r) => r[0]).map((r) => { const o = { map: num(r[0]), count: num(r[1]), points: [] }; for (let k = 0; k < o.count; k++) o.points.push([num(r[2 + k * 4]), r[3 + k * 4], num(r[4 + k * 4]), num(r[5 + k * 4])]); o.maxUsers = num(r[2 + o.count * 4]); return o; }),
    guildObserver: headerTable('share/guildobserver/info.csv').rows.map(typed) };
  others.siege.locationsResolved = others.siege.location.map((q) => ({ ...q, location: locations.get(q.LocationIndex) || null }));
  // siege teleport menu (share/arrange/siegeteleport.csv: dialog entry -> location, State 1 = enabled) and the castle
  // flag objects (script/object/siegeflag.csv: one flag per owning faction, same mesh / skel / anim, different tpack)
  others.siege.teleports = headerTable('share/arrange/siegeteleport.csv').rows.map((r) => ({ ...typed(r), location: locations.get(num(r.LocationIndex)) || null }));
  const tpUnres = uniq(others.siege.teleports.filter((q) => !q.location).map((q) => q.LocationIndex));
  if (tpUnres.length) others.siege.teleportsNote = `LocationIndex ${tpUnres.join(',')} is not in share/arrange/location.csv (placeholder; the server filled the destinations)`;
  others.siege.flags = headerTable('script/object/siegeflag.csv').rows.map((r) => {
    const o = { index: num(r.index), name: r.name };
    for (const [k, root] of [['mesh', 'mesh'], ['tpack', 'texturepack'], ['skel', 'skel'], ['anim', 'anim']]) { const key = r[k] ? resolveKey(root, r[k]) : null; o[k] = key ? K(key) : null; if (r[k] && !key) soft(`siegeflag ${r.name}: ${k} ${r[k]} missing on disk`); }
    if (o.tpack) {
      let t = tpackCache.get(o.tpack); if (!t) { t = parseTpackText(textRel(o.tpack)); tpackCache.set(o.tpack, t); }
      o.diffuse = Object.keys(t.diffuse).map(Number).map((sl) => { const k = resolveTexture(t.texpath, t.diffuse[sl]); if (!k) soft(`siegeflag ${r.name}: texture ${t.diffuse[sl]} missing`); return k ? K(k) : null; });
    }
    const raw = {}; for (const [k, v] of Object.entries(r)) if (!['index', 'name', 'mesh', 'tpack', 'skel', 'anim', 'Lodmesh', 'Lodtpack'].includes(k) && v !== '') raw[k] = numN(v) ?? v;
    o.raw = raw; return o;
  });
  others.siegeRenew = { config: siegeRenewCfg, gateUpgrade: csvRel('share/siege_renew/gateupgradeinfo.csv').filter((r) => r.some((c) => c)), location: headerTable('share/siege_renew/location.csv').rows.map(typed),
    tax: kvTable('share/siege_renew/tax.csv') };
  others.siegeRenew.locationsResolved = others.siegeRenew.location.map((q) => ({ index: q.Index, type: q[Object.keys(q)[3]], location: locations.get(q.LocationIndex) || null }));
  // Original Renew gate definitions exist but no native map placement references
  // them. Include their complete native model/action/stat closure for the
  // explicitly documented engine gate-placement reconstruction.
  for(let brick=36998;brick<=37012;brick++)useBrick(brick);
  others.siegeRenew.deployMasks={};
  for(const [map,file]of [[193,'siege_korea_red.dds'],[194,'siege_china_red.dds'],[195,'siege_eu_red.dds']]){
    const key='texture/minimap/'+file;
    if(existsRel(key))others.siegeRenew.deployMasks[map]={...compileSiegeDeployMask(readRel(key)),file:key};
    else soft(`siegeRenew ${map}: native deployment mask ${key} missing`);
  }
  const act = csvRel('share/arena/activity.csv');
  others.arena = { activity: act.filter((r) => r[0]).map((r) => r.slice(0, 11)), changeShape: headerTable('share/arena/changeshape.csv').rows.map(typed), conquest: headerTable('share/arena/conquest.csv').rows.map(typed),
    dkActionPoint: csvRel('share/arena/dkactionpoint.csv').filter((r) => r[0]), dkKillPoint: headerTable('share/arena/dkkillpoint.csv').rows.map((r) => [num(r.KillCount), num(r.DkPoint)]).filter((q, i, a) => i === 0 || q[1] !== a[i - 1][1]),
    dkSchedule: headerTable('share/arena/dkschedule.csv').rows.map(typed), dkTierBuff: headerTable('share/arena/dktierbuff.csv').rows.map((r, i) => ({ ...typed(r), Name: L(`arena#DKTierBuff.csv#2|${i + 1}`) || r.Name })),
    field: arenaField.map(typed), lostHorizon: headerTable('share/arena/losthorizon.csv').rows.map(typed), rank: headerTable('share/arena/rank.csv').rows.map(typed), schedule: headerTable('share/arena/schedule.csv').rows.map(typed),
    gameServerName: headerTable('share/arena/gameservername.csv').rows.map(typed) };
  for (const r of act) if (/^(CoinIndex|ProofIndex)$/.test(r[0])) useItem(num(r[1]));
  for (const r of headerTable('share/arena/conquest.csv').rows) useStatus(num(r.Buff));
  for (const r of act) if (r[0] === 'PaneltyStatus') useStatus(num(r[1]));
  others.dkSquare = { playtime: headerTable('share/dksquare/playtime.csv').rows.map(typed), gradeExp: headerTable('share/dksquare/gradeexp.csv').rows.map(typed) };
  others.urbanWarfare = { respawn: urban.map(typed), takeStone: headerTable('share/urbanwarfare/takestone.csv').rows.map(typed), time: headerTable('share/urbanwarfare/time.csv').rows.map(typed), winCondition: headerTable('share/urbanwarfare/wincondition.csv').rows.map(typed) };
  for (const r of others.urbanWarfare.takeStone) useStatus(r.Buff);
  for (const r of others.urbanWarfare.winCondition) for (const k of ['WinRewardItemIndex', 'LoseRewardItemIndex', 'AchieveRewardItemIndex', 'JoinRewardItemIndex', 'AttendRewardItemIndex']) useItem(r[k]);
  const gwhScores = gwh.slice(3).filter((r) => numN(r[0]) !== null).map((r) => [num(r[0]), num(r[1])]);
  others.guildWarHunting = { config: typed(Object.fromEntries(gwh[0].map((h, i) => [h, gwh[1][i]]).filter(([h]) => h))), monsterScore: uniq(gwhScores.map((q) => q.join(','))).map((s) => s.split(',').map(Number)), scoreRows: gwhScores.length };
  for (const [mo] of gwhScores) useMonster(mo);
  const fs1 = headerTable('share/forgottenshipwreck/rewardslot.csv');
  others.forgottenShipwreck = { startCondition: headerTable('share/forgottenshipwreck/startcondition.csv').rows.map(typed),
    rewardSlot: fs1.rows.filter((r) => r.team).map((r) => { const items = []; for (let k = 1; k <= num(r.count); k++) { const it = num(r[`index${k}`]); useItem(it); items.push([it, num(r[`vlaue${k}`]), num(r[`rate${k}`])]); } return { team: r.team, items }; }) };
  others.fieldBoss = { config: fbCfg.map(typed), summons: headerTable('share/fieldboss/summonsmonster.csv').rows.map(typed) };
  for (const r of fbCfg) for (const k of ['MonsterIndex', 'Slave_1', 'Slave_2', 'Slave_3', 'Slave_4', 'Slave_5']) if (num(r[k])) useMonster(num(r[k]));
  for (const r of others.fieldBoss.summons) if (r.MonsterIndex) useMonster(r.MonsterIndex);
  others.race = { list: headerTable('share/race/list.csv').rows.map(typed), playtime: headerTable('share/race/playtime.csv').rows.map(typed) };
  others.event = { eventTime: headerTable('share/event/event_time.csv').rows.map(typed), ox: { config: headerTable('share/event/oxevent.csv').rows.map(typed), questions: headerTable('share/event/oxlist.csv').rows.length },
    virus: headerTable('share/event/virus_event.csv').rows.map(typed), proxy: headerTable('share/event/proxy.csv').rows.map(typed) };
  others.mapEvent = { file: K('script/eventinfo/mapevent.csv'), fields: ['index', 'time', 'eventType', 'id', 'monster', 'p1', 'p2', 'p3', 'p4', 'p5', 'p6', 'p7', 'p8', 'p9'],
    rows: csvRel('script/eventinfo/mapevent.csv').slice(1).filter((r) => numN(r[0]) !== null).map((r) => r.slice(0, 14).map((x) => num(x))) };
  for (const r of others.mapEvent.rows) if (r[2] === 1 && r[4]) useMonster(r[4]);
  // script/eventinfo/info.csv: the (disabled) event-information screen: title row (Korean "정보", enable false) + 12 jump ids
  {
    const ei = csvRel('script/eventinfo/info.csv');
    others.eventInfo = { file: K('script/eventinfo/info.csv'), textFile: keyIf('script/eventinfo/info.txt'), title: ei[1]?.[0] || '', enable: /^true$/i.test(ei[1]?.[1] || ''),
      jumps: ei.filter((r) => r[0] === 'jump').map((r) => num(r[1])) };
  }
  // share/event/<publisher>.csv: per-publisher promotion drop lists (Index, ItemIndex, Count, DropRatio out of 100000?)
  others.event.publisherDrops = {};
  for (const k of [...FILES].filter((f) => /^share\/event\/(china|korea|japan|usa|eu|global)_[^/]+\.csv$/.test(f)).sort()) {
    others.event.publisherDrops[k.slice(k.lastIndexOf('/') + 1, -4)] = { file: K(k), rows: headerTable(k).rows.map((r) => { useItem(num(r.ItemIndex)); return [num(r.Index), num(r.ItemIndex), num(r.Count), num(r.DropRatio)]; }), fields: ['index', 'item', 'count', 'dropRatio'] };
  }

  // UI window definitions of the event systems (script/ui/game2/**), grouped per system for the UI module
  const UI_GROUPS = {
    partyWar: /^script\/ui\/game2\/partywar\//, colosseum: /^script\/ui\/game2\/colosseum\//, colosseumLegacy: /^script\/ui\/game2\/closseum\//,
    pvp3v3: /^script\/ui\/game2\/dkrpvpbattle\//, guildTournament: /^script\/ui\/game2\/guildtournament\//,
    partyPvp: /^script\/ui\/game2\/(partypvp\/|msgbox\/ui_partypvp)/, duel: /^script\/ui\/game2\/(pvpbattlewnd\/|msgbox\/ui_pvp)/,
    siege: /^script\/ui\/game2\/(siege\/|msgbox\/ui_siege|systemwnd\/ui_siegemessagewnd)/, guildWar: /^script\/ui\/game2\/guildwar\//, guildWarHunting: /^script\/ui\/game2\/guildwarhunting\//,
    dkSquare: /^script\/ui\/game2\/dksquare\//, fieldBoss: /^script\/ui\/game2\/fieldboss(supply)?\//, forgottenShipwreck: /^script\/ui\/game2\/forgottenshipwreck\//,
    race: /^script\/ui\/game2\/race\//, observer: /^script\/ui\/game2\/observer\//, event: /^script\/ui\/game2\/(event|npcdialogevent)\//, dungeon: /^script\/ui\/game2\/dungeon\//,
  };
  const uiWindows = {};
  for (const [g, re] of Object.entries(UI_GROUPS)) uiWindows[g] = [...FILES].filter((f) => re.test(f) && f.endsWith('.txt')).sort().map(K);

  // content timetable (English via lines_eu) + weekly table
  const tt = csvRel('script/contents_timetable.csv');
  const ttH = tt[0];
  const timetable = tt.slice(1).filter((r) => r[0]).map((r, i) => {
    const o = {}; ttH.forEach((h, c) => { if (h) o[h] = L(`script#contents_timetable.csv#${c}|${i + 1}`) ?? r[c]; }); return typed(o);
  });
  const daystable = headerTable('script/contents_daystable.csv').rows.map(typed);

  // ================================================================================================
  // SOLO RULESETS (machine readable; rationale in docs/formats/events.md §7)
  // ================================================================================================
  const soloRules = {
    principle: 'No AI opponents. Everything that the original client/server data defines as PvE (monsters, bosses, bricks, NPC objectives, timers, points, rewards) runs exactly; phases whose only purpose is fighting other players are skipped or resolved by forfeit, and pure-PvP modes are disabled with the original "no match" message.',
    deadFront: {
      available: true, playerTeam: 0, rivalTeams: [],
      entry: { from: 'officer NPC of the tier (RECORD_PARTY_WAR + ENTER_PARTY_WAR in one click)', level: 'modes.deadFront.fields[m].entryLevel (field.csv registration window within the maplist gate)', requireParty: false,
        consumeItem: 'tiers[t].items.mapOfFortress (1) - the partywar strings require a key/map for every member; field.csv ItemCode is 0, so the item id itself is not in the tables (see doc)', schedule: 'optional: honour modes.deadFront.schedule, default off (enter any time)',
        startAt: 'modes.deadFront.fields[m].starts[0] (team 0 = Purple, lane A)' },
      exit: { win: 'fields[m].winnerRespawn after the (uncontested) final battle', close: 'fields[m].endWarRespawn when waitClose ends or the player talks to Reezena' },
      death: 'resurrect in place (revival item / skill; partywar #300|102) or return to maps[m].dkMapList.respawn[0] (DK maps with a row) else fields[m].endWarRespawn; returning ends the solo run because no party member is left inside',
      liveMaps: deadFront.tiers.flatMap((t) => t.maps.filter((m) => m.officerPlaced).map((m) => m.map)),
      retiredMaps: deadFront.tiers.flatMap((t) => t.maps.filter((m) => !m.officerPlaced).map((m) => m.map)),
      retiredRule: 'retiredMaps have complete map data but no officer placed in any lobby; flag includeRetiredTiers (default false) adds them to the tier menu of the lobby officers',
      phases: [{ id: 'waitStart', sec: pwConfig[1]?.LimitStarDelay, solo: 'run (countdown, can be skipped by the player)' }, { id: 'fortress', sec: pwConfig[1]?.LimitStarTime, solo: 'run fully (PvE)' },
        { id: 'waitPvp', sec: pwConfig[1]?.LimitPvPDelay, solo: 'skip' }, { id: 'pvp', sec: pwConfig[1]?.LimitPvPTime, solo: 'skip: no opponent; final battle resolved as uncontested win (forfeit) if the final boss died, else loss' },
        { id: 'waitExtension', sec: pwConfig[1]?.LimitExtensionDelay, solo: 'skip' }, { id: 'extension', sec: pwConfig[1]?.LimitExtension, solo: 'skip' }, { id: 'waitClose', sec: pwConfig[1]?.LimitEndDelay, solo: 'run (loot the armories, talk to Reezena to leave)' }],
      scoring: 'score = sum(result[map].killPoints for depots occupied, bricks destroyed, bosses killed) + (uncontested win ? result[map].pvpPoints[0] : 0)',
      depotCapture: 'channel zeolite Delay seconds (10) next to the depot NPC; cancelled by moving, being hit or leaving the map (partywar #300|124-126); 1 point per depot',
      rewards: 'Additional EXP shown in the result window = score * advRatio (inferred, see doc); DK maps add winExp4PvP/winRPoint4PvP on an uncontested win, lostExp4PvP otherwise; armory treasure boxes (scriptMonsters 3350-3358 / 3418-3426) drop their monster drop tables',
    },
    iceCastle: { available: true, playerTeam: 0, rivalTeams: [], note: 'fully PvE up to the tower defence (call-monster waves have exact positions); PvP/overtime skipped as for Dead Front; the Tower of Shield (brick 36820) takes towerDamage per attacker that reaches towerTarget',
      entry: { level: 'modes.iceCastle.fields[m].entryLevel', consumeItem: 'tiers[t].items.castleKey (1)', startAt: 'modes.iceCastle.fields[m].starts[0]', cornerCalls: 'modes.iceCastle.teamCorners[0].calls are the player corner; flag spawnAllCorners (default true) also spawns the corners of absent teams, because the call tables define the whole map and nothing in the data says the script skipped them' },
      exit: { win: 'fields[m].winnerRespawn', close: 'fields[m].endWarRespawn' }, death: 'as for Dead Front (Ice Castle 167 dkmaplist respawn: 166 262,285)',
      liveMaps: iceCastle.tiers.flatMap((t) => t.maps.filter((m) => m.officerPlaced).map((m) => m.map)),
      retiredMaps: iceCastle.tiers.flatMap((t) => t.maps.filter((m) => !m.officerPlaced).map((m) => m.map)),
      retiredRule: 'as for Dead Front (flag includeRetiredTiers)' },
    colosseumArena: { available: true, solo: 615, party: 616, playerStart: 'beside the Reezena exit NPC (615: 262,289; 616: 258.5,289.4), the same convention as dungeons.json entry.spawn (inferred: the client has no dungeon start table)',
      waveOpen: 'each call opens the Old Bars of the cells its champions stand in (DEAD clip), then the champions attack (message 200)', partyRule: 'map 616 requires a 3-player party in the original (dungeonlist RequestMember 3): allow solo entry with the same monsters (flag allowSoloParty, default true) — no AI companions' },
    infiniteBattle: { available: true, note: 'pure PvE wave maps (callmonster tables); accumulation limit messages 1101/1106-1108' },
    battleRoyal: { available: false, reason: 'PvP only (16 players)', message: [TXT_TYPE.has('stringtable_colosseum.txt') ? 'stringtable_colosseum.txt' : null, 360, 101] },
    partyMatch: { available: false, reason: 'PvP only (party vs party)', message: ['stringtable_colosseum.txt', 360, 101] },
    guildMatch: { available: false, reason: 'PvP only (guild tournament)', message: ['stringtable_partywarui.txt', 2011, 554] },
    pvp3v3: { available: false, reason: 'PvP only', message: ['stringtable_partywarui.txt', 2011, 554] },
    partyPvpArenas: { available: false, reason: 'party duel maps (PartyMatch_DeathMatch)' },
    huntingChallenge: { available: false, reason: 'map 200 ships no NPC, spawn, call-monster or dungeon data (script Map_200_Hunting is server-side)' },
    arenaBattlefield: { available: false, reason: 'faction PvP (Draco Desert / Lost Horizon / DK Square); map 549 Lost Horizon PvE has call-monster data and can run as a dungeon' },
    siege: { available: false, reason: 'guild PvP' },
    urbanWarfare: { available: false, reason: 'faction PvP (Zuto guardian stones)' },
    guildWarHunting: { available: true, note: 'score = sum(monsterScore) of the Defense Battle waves (map 707 random call tables) — PvE scoring race, runnable solo' },
    forgottenShipwreck: { available: true, note: '10-player PvE raid; solo map 263/264 exists in the original' },
    fieldBoss: { available: true, note: 'PvE world boss on its schedule' },
  };

  // ================================================================================================
  // VALIDATION
  // ================================================================================================
  const REPORT = { counts: {}, xref: {}, missingMapFiles: missingFiles, localisationRowMapping: REPORT_LOC };
  // cross references: every map referenced anywhere exists in maplist
  const mapRefs = new Set();
  for (const o of Object.values(MAPOUT)) { if (o.ret.map) mapRefs.add(o.ret.map); for (const k of o.dungeon?.kickTo || []) if (k[0]) mapRefs.add(k[0]); }
  for (const t of [...deadFront.tiers, ...iceCastle.tiers]) for (const mm of t.maps) mapRefs.add(mm.map);
  for (const o of [...dfOfficers, ...icOfficers]) { if (o.map) mapRefs.add(o.map); for (const p of o.placed) mapRefs.add(p[0]); }
  for (const r of colBR) mapRefs.add(num(r.MapIndex)); for (const r of colBRR) mapRefs.add(num(r.MapIndex));
  const badMaps = [...mapRefs].filter((i) => !MAPS.has(i));
  REPORT.xref.maps = { referenced: mapRefs.size, missing: badMaps };
  if (badMaps.length) soft(`maps referenced but not in maplist: ${badMaps.join(',')}`);
  REPORT.xref.npcs = { referenced: Object.keys(NPCS).length, missing: Object.entries(NPCS).filter(([, v]) => v.missing).map(([k]) => +k) };
  REPORT.xref.monsters = { referenced: Object.keys(MONSTERS).length, missing: Object.entries(MONSTERS).filter(([, v]) => v.missing).map(([k]) => +k) };
  REPORT.xref.bricks = { referenced: Object.keys(BRICKS).length, missing: Object.entries(BRICKS).filter(([, v]) => v.missing).map(([k]) => +k),
    noMesh: Object.entries(BRICKS).filter(([, v]) => !v.visual?.mesh).map(([k, v]) => `${k} ${v.name}`), withAnim: Object.values(BRICKS).filter((v) => v.act).length };
  REPORT.xref.items = { referenced: Object.keys(ITEMS).length, nameFromItemDat: Object.values(ITEMS).filter((v) => v.nameKey).length,
    onlyInItemDat: Object.entries(ITEMS).filter(([, v]) => v.file === 'share/item/item.dat').map(([k]) => +k), csvNameDiffers: Object.entries(ITEMS).filter(([, v]) => v.csvName).map(([k, v]) => `${k}: ${v.name} | csv ${v.csvName}`),
    unresolved: Object.entries(ITEMS).filter(([, v]) => v.unresolved).map(([k]) => +k) };
  REPORT.xref.statuses = { referenced: Object.keys(STATUSES).length, missing: Object.entries(STATUSES).filter(([, v]) => v.missing).map(([k]) => +k) };
  // dialog nodes: every string code resolves in the map's table
  let dlgNodes = 0, dlgMissing = 0; const dlgMissList = [];
  for (const [mi, d] of Object.entries(DIALOGS)) for (const [nid, n] of Object.entries(d.nodes)) { dlgNodes++; if (n.missingText) { dlgMissing++; if (dlgMissList.length < 40) dlgMissList.push(`${mi}:${nid}`); } for (const c of n.menu || []) if (!d.nodes[c]) soft(`dialog ${mi}: node ${nid} menu ${c} has no node`); }
  REPORT.xref.dialogs = { maps: Object.keys(DIALOGS).length, nodes: dlgNodes, nodesWithoutText: dlgMissing, examples: dlgMissList };
  // result.csv targets vs placements
  const resCheck = [];
  for (const [mi, rr] of Object.entries(result)) for (const [t, , kind] of rr.killPoints) if (kind === 'depot' && !(MAPOUT[mi]?.npcs || []).some((q) => q[0] === t)) resCheck.push(`${mi}:${t}`);
  REPORT.xref.resultDepotsPlaced = resCheck.length ? { unplaced: resCheck } : 'all placed';
  // every depot of zeolite.csv is placed on some party-war map
  const zUnplaced = depots.filter(([n]) => !npcPlaced.has(n)).map(([n]) => n);
  REPORT.xref.zeoliteDepotsUnplaced = zUnplaced;
  if (zUnplaced.length) soft(`zeolite depots never placed: ${zUnplaced.join(',')}`);
  // party-war field points (field.csv) on the .mac collision grid of their map
  {
    let pts = 0, checked = 0; const notWalkable = [];
    for (const [mi, f] of Object.entries(pwField)) {
      const named = [...f.starts.map((p, i) => [`start${i + 1}`, p]), ...f.pvpPoints.map((p, i) => [`pvp${i + 1}`, p]), ['winnerRespawn', f.winnerRespawn], ['loserRespawn', f.loserRespawn], ['endWarRespawn', f.endWarRespawn]];
      for (const [nm, p] of named) { pts++; if (p.walkable !== undefined) { checked++; if (!p.walkable) notWalkable.push(`${mi} ${nm} (${p.map}:${p.x},${p.y})${p.nearestWalkable ? ` -> ${p.nearestWalkable.join(',')}` : ''}`); } }
    }
    REPORT.xref.partyWarFields = { fields: Object.keys(pwField).length, points: pts, checkedOnMac: checked, notWalkable,
      quirks: Object.fromEntries(Object.entries(pwField).filter(([, f]) => f.quirks).map(([mi, f]) => [mi, f.quirks])) };
    if (notWalkable.length) soft(`partywar field points on blocked cells: ${notWalkable.length} (${notWalkable.slice(0, 4).join('; ')})`);
  }
  // tier consistency: Dead Front bosses are named "Las Alhage" / "Oppucus"
  for (const t of deadFront.tiers) if (t.bosses) {
    if (!/Las Alhage/i.test(monName(t.bosses.mid) || '')) hard(`DF ${t.tier}: mid boss ${t.bosses.mid} is ${monName(t.bosses.mid)}`);
    if (!/Oppucus/i.test(monName(t.bosses.final) || '')) hard(`DF ${t.tier}: final boss ${t.bosses.final} is ${monName(t.bosses.final)}`);
    if (!new RegExp(`\\[${t.tier}\\]`, 'i').test(monName(t.bosses.mid) || '')) soft(`DF ${t.tier}: boss name tier mismatch ${monName(t.bosses.mid)}`);
  }
  for (const t of iceCastle.tiers) { const s3 = t.monsters.slots.find((q) => q[0] === 3); if (!s3 || !/Aril/i.test(monName(s3[1]) || '')) hard(`IC ${t.tier}: slot 3 is not Aril (${s3 && monName(s3[1])})`); }
  // emitted asset keys exist
  let badKeys = 0;
  for (const k of EMITTED_KEYS) { if (k !== k.toLowerCase()) hard(`key not lower case: ${k}`); if (!has(k)) { badKeys++; hard(`emitted key missing on disk: ${k}`); } }
  REPORT.assetKeys = { emitted: EMITTED_KEYS.size, missing: badKeys };
  REPORT.counts = { maps: Object.keys(MAPOUT).length, modes: uniq([...MODE_OF.values()].map((v) => v.mode)).length, npcs: Object.keys(NPCS).length, monsters: Object.keys(MONSTERS).length,
    bricks: Object.keys(BRICKS).length, items: Object.keys(ITEMS).length, statuses: Object.keys(STATUSES).length, dialogMaps: Object.keys(DIALOGS).length,
    textTables: Object.keys(TEXT.tables).length, textSections: Object.values(TEXT.tables).reduce((a, t) => a + Object.keys(t).length, 0),
    textStrings: Object.values(TEXT.tables).reduce((a, t) => a + Object.values(t).reduce((b, s) => b + Object.keys(s).length, 0), 0),
    levelCaps: Object.keys(CAPS.levelCaps).length, abilityCaps: Object.keys(CAPS.abilityCaps).length,
    dfTiers: deadFront.tiers.length, icTiers: iceCastle.tiers.length, callSpawnRows: Object.values(MAPOUT).reduce((a, o) => a + Object.values(o.calls || {}).reduce((b, l) => b + l.length, 0), 0) };

  // also resolve party-war strings (types 8/9), colosseum/pvp/party-war UI tables into events_text.json
  for (const [f, cates] of [['stringtable_partywar.txt', [100, 200, 300, 400]], ['stringtable_partywar2.txt', [100, 200, 300, 400]], ['stringtable_partywarui.txt', [2008, 2011]],
    ['stringtable_colosseum.txt', [360]], ['stringtable_pvp.txt', [280, 1008, 2100]], ['stringtable_jobtype.txt', [200]], ['stringtable_siege.txt', [100, 200, 300, 400, 500, 510, 700, 701, 800]],
    ['stringtable_dksquare.txt', [160, 161, 162]]]) for (const c of cates) tableSection(f, c);

  // ================================================================================================
  // WRITE
  // ================================================================================================
  const meta = { generatedBy: 'tools/build-events.mjs', doc: 'docs/formats/events.md',
    units: { position: 'map cells, FILE frame (coords.md): NPC/brick x,y continuous -> three.js (x, h, -y); call/spawn x,y integer cell -> stand at (x+0.5, -(y+0.5))', dir: 'degrees (NPC/brick CSV)', time: 'seconds unless the field says ms' } };
  const events = {
    format: 'dekaron-solo/events@1', ...meta,
    fields: {
      'maps[].npcs': ['npc', 'x', 'y', 'dir', 'warpX', 'warpY', 'descKr'], 'maps[].bricks': ['uid', 'brick', 'x', 'y', 'dir', 'isCreate', 'revival', 'regenCycle'],
      'maps[].calls[callIndex]': ['monster', 'x', 'y', 'radius', 'count'], 'maps[].spawns': ['monster', 'regenSec', 'x', 'y'], 'maps[].triggers': ['trigger', 'x', 'y', 'dir', 'desc'],
      'maps[].randomCalls': ['randCallIndex', 'monster', 'count', 'posIndex'], 'maps[].randomPositions': ['randPosIndex', 'x', 'y', 'radius'],
      'modes.deadFront.depots': ['npc', 'depotLevel', 'captureSec'], 'result[].killPoints': ['target', 'points', 'kind'], 'iceCastle.checkpoints': ['index', 'x', 'y', 'label', 'value'],
      'monsters.slots': ['slot', 'monster', 'role'], 'npcs[].jobs': ['jobType', 'jobIndex', 'jobName'], 'brick.act.clips': ['action', 'index', 'anim'],
      'modes.deadFront|iceCastle.fields[m]': 'share/partywar/field.csv column of field map m: {contentType, itemCode, level (registration), entryLevel, maxParties, starts[4], pvpPoints[4], winnerRespawn, loserRespawn, endWarRespawn ({map,x,y,walkable,nearestWalkable?}), winRPoint, depots[12], depotsPlaced, quirks?}',
      'modes.event.publisherDrops[].rows': ['index', 'item', 'count', 'dropRatio'],
      'maps[].dkMapList': 'share/dkmaplist.csv row: {respawnType DEFAULT|NONE, respawn [[map,x,y]] (where a dead player returns), locates [[dkChannel, name, dkIndex]] + locate [x,y] (DK-channel entry point), costItems?, cashCostItems?, cashLocate?}',
    },
    jobTypes,
    modes: { deadFront, iceCastle, colosseum, ...others },
    schedule: { timetable, daystable },
    soloRules,
    ui: uiWindows,
    maps: MAPOUT,
    dialogs: DIALOGS,
    npcs: NPCS, monsters: MONSTERS, bricks: BRICKS, items: ITEMS, statuses: STATUSES,
    report: { ...REPORT, soft: problems.soft.slice(0, 200) },
  };
  const text = { format: 'dekaron-solo/events-text@1', ...meta,
    note: 'tables[file][cate][code] = parsed message {text, kind: message|dialog|effect|empty, effectUi[], sound[], effectSound[], gauge}; map-scoped tables use the map index as cate; notes = developer comments of script/string/**.txt',
    mapTables: Object.fromEntries([...MAP_TABLE].filter(([mi]) => MAPOUT[mi]).map(([mi, f]) => [mi, f])), tables: TEXT.tables, notes: TEXT.notes };
  const caps = { format: 'dekaron-solo/events-caps@1', ...meta, ...CAPS };
  fs.mkdirSync(OUTDIR, { recursive: true });
  const write = (name, obj) => { const p = path.join(OUTDIR, name); const s = PRETTY ? JSON.stringify(obj, null, 1) : JSON.stringify(obj); fs.writeFileSync(p, s); log(`wrote ${path.relative(ENGINE, p)} (${(s.length / 1024).toFixed(0)} KiB)`); };
  write('events.json', events);
  write('events_text.json', text);
  write('events_caps.json', caps);

  log(`counts: ${JSON.stringify(REPORT.counts)}`);
  log(`xref: maps missing ${badMaps.length}, npcs missing ${REPORT.xref.npcs.missing.length}, monsters missing ${REPORT.xref.monsters.missing.length}, bricks missing ${REPORT.xref.bricks.missing.length}, ` +
    `items unresolved ${REPORT.xref.items.unresolved.length} (${REPORT.xref.items.nameFromItemDat} named via item.dat), statuses missing ${REPORT.xref.statuses.missing.length}, dialog nodes without text ${dlgMissing}/${dlgNodes}`);
  log(`soft issues: ${problems.soft.length}`);
  for (const s of problems.soft.slice(0, 30)) log(`  - ${s}`);
  log(`HARD failures: ${problems.hard.length}`);
  for (const s of problems.hard.slice(0, 40)) log(`  ! ${s}`);
  log(`done in ${((Date.now() - t0) / 1000).toFixed(1)} s`);
  process.exitCode = problems.hard.length ? 1 : 0;
}

if (process.argv[1] && path.resolve(process.argv[1]) === fileURLToPath(import.meta.url)) main();
