#!/usr/bin/env node
// Dekaron Solo - player-character data builder.
//
// Reads the user's own unpacked client data and writes
//   gamedata/classes.json   (per class: skeleton, default body parts + textures, starter weapon + attach bones,
//                            animation map, base stats / growth, basic-attack combo, early skills)
//   gamedata/exp.json       (experience table + level-difference exp modifiers)
//
// Usage:  node tools/build-characters.mjs [--data <unpacked data root>] [--out <dir>] [--png] [--png-out <file>] [--verbose]
// Independent checks: node tools/verify-characters.mjs
// Exit code 1 when any referenced path is missing on disk (every path in the JSON is a lower-case,
// forward-slash key relative to the data root, i.e. fetchable as /data/<key>).
//
// Format notes live in docs/formats/characters.md. The small binary/text parsers used here are exported so a
// validator (or the engine, if it ever wants to read the raw tables at runtime) can reuse them; they are pure
// functions (ArrayBuffer|Buffer|string in, plain objects out) and do not touch the file system.

import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { BinReader, parseCSV, decodeText } from '../src/formats/binreader.js';

/** Game path -> data key: backslashes -> '/', lower case, no leading './' or '/' (same rule as src/engine/assets.js). */
export function normPath(p) {
  return String(p ?? '').trim().replace(/\\/g, '/').replace(/^(\.\/)+/, '').replace(/^\/+/, '').replace(/\/{2,}/g, '/').toLowerCase();
}
/** Game path relative to a type root ("Item\\Armor\\Coat\\x.mesh") -> data key ("mesh/item/armor/coat/x.mesh"). */
export function gamePathToData(root, p) {
  const n = normPath(p);
  if (!n) return null;
  const r = normPath(root).replace(/\/$/, '');
  return n.startsWith(r + '/') ? n : `${r}/${n}`;
}

/**
 * Sibling format modules (owned by other parts of the engine). Loaded dynamically so this tool keeps working
 * (with reduced validation) if one of them is missing or changes shape.
 */
async function loadFormatModules() {
  const load = async (f) => { try { return await import(new URL(`../src/formats/${f}`, import.meta.url)); } catch { return null; } };
  const [tpack, skel, mesh, dds, anim] = await Promise.all([load('tpack.js'), load('skel.js'), load('mesh.js'), load('dds.js'), load('anim.js')]);
  return { tpack, skel, mesh, dds, anim };
}

/** Minimal .tpack reader used when src/formats/tpack.js is unavailable (same output shape for the fields used). */
function parseTpackLite(src) {
  const text = typeof src === 'string' ? src : decodeText(src instanceof ArrayBuffer ? new Uint8Array(src) : src);
  const out = { texpath: null, texdir: null, diffuse: {}, specular: {}, bump: {}, glow: {} };
  for (const raw of text.split(/\r?\n/)) {
    const m = /^\s*(\S+?)\s+"?([^"]*)"?/.exec(raw);
    if (!m || m[1].startsWith('//')) continue;
    const k = m[1].toLowerCase(), v = m[2].trim();
    let mm;
    if (k === 'texpath') out.texpath = v;
    else if ((mm = /^(\d+)$/.exec(k))) out.diffuse[+mm[1]] ??= v;
    else if ((mm = /^s(\d*)$/.exec(k)) || (mm = /^(\d+)s$/.exec(k))) out.specular[mm[1] === '' ? 0 : +mm[1]] ??= v;
    else if ((mm = /^b(\d+)$/.exec(k))) out.bump[+mm[1]] ??= v;
    else if ((mm = /^g(\d+)$/.exec(k))) out.glow[+mm[1]] ??= v;
  }
  out.texdir = out.texpath !== null ? normPath(out.texpath).replace(/\/$/, '') : null;
  return out;
}
function textureCandidatesLite(texdir, file) {
  const f = normPath(file), base = f.slice(f.lastIndexOf('/') + 1);
  return [...new Set([texdir ? `texture/${texdir}/${f}` : null, `texture/${f}`, `texture/character/${base}`, `texture/costume/${base}`, `texture/item/${base}`].filter(Boolean))];
}

// ---------------------------------------------------------------------------------------------------------------
// Static knowledge (derived from the data; see docs/formats/characters.md for the evidence behind each table)
// ---------------------------------------------------------------------------------------------------------------

/** Action enum used by share/action/action/pc/*.act.N.dat (names voted from the legacy share/action/pc/*.csv twins). */
export const ACTION_NAMES = {
  1: 'STAND', 2: 'MOVE', 6: 'ATTACK', 7: 'DEFEAT', 8: 'DEAD', 10: 'SKILL', 11: 'REVIVE', 12: 'BLOCKING', 13: 'BLOCKED',
  14: 'GUARDING', 15: 'MOTION', 17: 'OPENMARKET', 18: 'CLOSEMARKET', 21: 'FISHFIGHTING', 22: 'OPENFISHING',
  23: 'CLOSEFISHING', 26: 'SM_STAND', 27: 'SM_DEAD', 28: 'SM_MOVE', 29: 'SM_REVIVE', 30: 'ENDSIEGE', 38: 'KNOCKDOWN',
  39: 'AWK_STAND', 40: 'AWK_MOVE', 41: 'STUN', 43: 'SLEEP', 44: 'RUSH', 46: 'EMOTIONSTART', 47: 'EMOTIONKEEP',
  48: 'EMOTIONEND', 53: 'SURRENDER',
};
export const ACTION_IDS = Object.fromEntries(Object.entries(ACTION_NAMES).map(([k, v]) => [v, +k]));

/**
 * Weapon "Code" (itemweapon.csv Type=4) -> name, weaponType (= Type<<8 | Code, the key of script/weapon_bonename.csv),
 * candidate action styles (first one present in the class' action file wins) and the motion-folder token the
 * style's ATTACK animations are expected to live in (used as a data cross-check).
 */
export const WEAPON_CODES = {
  0: { name: 'SHORT_SWORD', styles: [2], token: ['SSW'] },
  1: { name: 'SWORD', styles: [3], token: ['SWD'] },
  2: { name: 'LONG_SWORD', styles: [4], token: ['LSW'] },
  3: { name: 'GREAT_SWORD', styles: [], token: [] },
  4: { name: 'SPEAR', styles: [5], token: ['SPR'] },
  5: { name: 'POLEARM', styles: [6], token: ['POL'] },
  6: { name: 'MACE', styles: [12], token: ['MAC'] },
  7: { name: 'GREAT_MACE', styles: [19], token: ['GMA'] },
  8: { name: 'AX', styles: [13], token: ['MAX'] },
  9: { name: 'GREAT_AX', styles: [20], token: ['GAX'] },
  10: { name: 'BOW', styles: [7], token: ['BOW'] },
  11: { name: 'CROSS_BOW', styles: [8], token: ['CRS'] },
  12: { name: 'STAFF', styles: [9], token: ['STF'] },
  13: { name: 'WAND', styles: [11], token: ['SSW', 'WAD'] },
  14: { name: 'SHIELD', styles: [14], token: [] },
  15: { name: 'ARROW', styles: [], token: [] },
  16: { name: 'BOLT', styles: [], token: [] },
  17: { name: 'TWIN_SWORD', styles: [21, 10], token: ['DUL'] },
  18: { name: 'BLOODWHIP', styles: [22], token: ['WIP'] },
  19: { name: 'FISHING_ROD', styles: [23], token: [] }, // style 23 ATTACK rows reuse the one-handed weapon clips
  20: { name: 'GAUNTLET', styles: [24], token: ['NCL'] },
  21: { name: 'GUARDARM', styles: [26], token: [] },
  22: { name: 'ALOKEN_SPEAR', styles: [25, 27], token: ['SPR'] },
  23: { name: 'DUALBLADE', styles: [29], token: ['DUAL'] },
  24: { name: 'SCYTHE', styles: [30], token: ['SIC'] },
  25: { name: 'ORB', styles: [31], token: ['BAL', 'BALL'] },
  26: { name: 'GREAT_FALCHION', styles: [32], token: ['FAL', 'FALCHION'] },
  27: { name: 'KATAR', styles: [33], token: ['KAT', 'KATAR'] },
  28: { name: 'SEALFORCE', styles: [34], token: ['SF', 'SFC'] },
  34: { name: 'GUN', styles: [35], token: ['PIS'] },
  35: { name: 'CANNON', styles: [36], token: ['RIF'] },
  36: { name: 'LILY', styles: [37], token: ['HAF'] },
  37: { name: 'CLOCHE', styles: [38], token: ['CEL'] },
  38: { name: 'RAPIER', styles: [39], token: ['RAP'] },
  39: { name: 'WINSWORD', styles: [40], token: ['SIS'] },
};
/** Global action-style enum (style 0 = weapon-independent actions, 1 = bare hands, 23 = fishing rod). */
export const STYLE_NAMES = {
  0: 'COMMON', 1: 'BAREHANDS', 2: 'SHORT_SWORD', 3: 'SWORD', 4: 'LONG_SWORD', 5: 'SPEAR', 6: 'POLEARM', 7: 'BOW',
  8: 'CROSS_BOW', 9: 'STAFF', 10: 'DUAL', 11: 'WAND', 12: 'MACE', 13: 'AX', 14: 'SHIELD', 15: 'SHIELD_SHORT_SWORD',
  16: 'SHIELD_SWORD', 17: 'SHIELD_MACE', 18: 'SHIELD_AX', 19: 'GREAT_MACE', 20: 'GREAT_AX', 21: 'TWIN_SWORD',
  22: 'BLOODWHIP', 23: 'FISHING_ROD', 24: 'GAUNTLET', 25: 'ALOKEN_SPEAR', 26: 'GUARDARM', 27: 'GUARDARM_SPEAR',
  28: 'GUARDARM_SHORT_SWORD', 29: 'DUALBLADE', 30: 'SCYTHE', 31: 'ORB', 32: 'GREAT_FALCHION', 33: 'KATAR',
  34: 'SEALFORCE', 35: 'GUN', 36: 'CANNON', 37: 'LILY', 38: 'CLOCHE', 39: 'RAPIER', 40: 'WINSWORD',
};
/**
 * Which weapon_bonename.csv column pair an item uses: 'left' = the secondary column (bow, crossbow, shield,
 * guard arm), 'both' = one mesh per column (twin sword, gauntlet, dual blade, katar, gun), otherwise the right
 * column. The bow case is confirmed by posing ATTACK clips (weaponL = the extended bow arm, weaponR = the drawing
 * hand); the others follow the item type. The reported weapon.hand is then read from the skeleton.
 */
const HAND_BY_CODE = { 10: 'left', 11: 'left', 14: 'left', 21: 'left', 17: 'both', 20: 'both', 23: 'both', 27: 'both', 34: 'both' };

const PART_SLOTS = [
  { key: 'HEL', slot: 'helmet', role: 'head (face + hair); replaced by an equipped helmet' },
  { key: 'COT', slot: 'coat', role: 'torso / upper body' },
  { key: 'PAT', slot: 'pants', role: 'legs / lower body' },
  { key: 'GLV', slot: 'glove', role: 'hands / forearms' },
  { key: 'BOT', slot: 'boots', role: 'feet / shins' },
];

/**
 * Per-class wiring. `code` = section prefix in property/item/default.txt, `skillFlag` = PCClassFlag in share/skill/*.csv,
 * `skillDesc` = script/skilldesc/<name>.csv (English names), `weapons` = starter-weapon codes in preference order.
 * Everything else (skeleton, action file, meshes, textures, stats) is read from the data.
 */
export const CLASS_WIRING = [
  { index: 0, code: 'SWD', classic: true, skillFlag: 'SWD', skillDesc: 'knight', weapons: [1, 0] },
  { index: 1, code: 'ARC', classic: true, skillFlag: 'ARC', skillDesc: 'hunter', weapons: [10, 11] },
  { index: 2, code: 'SOR', classic: true, skillFlag: 'SOR', skillDesc: 'magician', weapons: [12, 13] },
  { index: 3, code: 'SUM', classic: true, skillFlag: 'SUM', skillDesc: 'summoner', weapons: [17, 12] },
  { index: 4, code: 'HIL', classic: true, skillFlag: 'SEG', skillDesc: 'segnale', weapons: [18] },
  { index: 5, code: 'WAR', classic: true, skillFlag: 'WAR', skillDesc: 'warrior', weapons: [20] },
  { index: 6, code: 'ALO', classic: true, skillFlag: 'ALO', skillDesc: 'aloken', weapons: [22] },
  { index: 7, code: 'DRG', classic: false, skillFlag: 'DRG', skillDesc: 'dragonknight', weapons: [28] },
  { index: 8, code: 'SHT', classic: false, skillFlag: null, skillDesc: 'shooter', weapons: [34, 35] },
  { index: 9, code: 'BWZ', classic: false, skillFlag: 'BWZ', skillDesc: 'wizard', weapons: [25] },
  { index: 10, code: 'WSU', classic: false, skillFlag: 'CON', skillDesc: 'concerra', weapons: [23] },
  { index: 11, code: 'MSE', classic: false, skillFlag: 'RIP', skillDesc: 'segeuriper', weapons: [24] },
  { index: 12, code: 'HWA', classic: false, skillFlag: 'HWA', skillDesc: 'halfbagi', weapons: [26, 27] },
  { index: 13, code: 'MAL', classic: false, skillFlag: null, skillDesc: 'aloken_m', weapons: [38, 39] },
  { index: 14, code: 'TRI', classic: false, skillFlag: null, skillDesc: 'triemuse', weapons: [36, 37] },
];
/** item_shape.csv folder token used to find a weapon mesh when the weapon is absent from itemweapon.csv. */
const SHAPE_FOLDER_FALLBACK = { 34: 'pis', 35: 'rif', 36: 'haf', 37: 'cel', 38: 'rapier', 39: 'swordinsky' };

/** skilldesc "Weapon" column -> allowed weapon codes (null = any). */
function weaponReqCodes(txt) {
  const t = String(txt || '').toLowerCase().replace(/\s+/g, ' ').trim();
  if (!t || t.startsWith('all weapon')) return null;
  const set = new Set();
  if (t.includes('one-handed')) [0, 1, 6, 8].forEach(c => set.add(c));
  if (t.includes('two-handed')) [2, 3, 4, 5, 7, 9].forEach(c => set.add(c));
  if (t.includes('dual weapon')) set.add(-1); // two one-handed weapons at once: never true for a starter
  if (/\bbow\b/.test(t) || t.startsWith('bow')) set.add(10);
  if (t.includes('crossbow') || t.includes('cross bow') || t.includes('bow/cross')) set.add(11);
  if (t.includes('dagger')) set.add(0);
  if (t.includes('staff')) set.add(12);
  if (t.includes('twin sword')) set.add(17);
  if (t.includes('blood whip')) set.add(18);
  if (t.includes('gauntlet')) set.add(20);
  if (t.includes('fishing')) set.add(19);
  if (t === 'guardarm') set.add(21);
  if (t === 'spear and guardarm') set.add(-2); // needs both items
  else if (t.includes('spear')) set.add(22);
  return set.size ? set : null;
}

/** Skill-table distances (radius args) are stored in 1/128 world units: "4m radius" = 512, "radius of 14m" = 1792. */
export const SKILL_DISTANCE_SCALE = 128;

/**
 * ResultCode families -> named fields. `args` = Arg1..Arg8 (index 0 = Arg1). The layouts come from the value patterns
 * of all 1,082 skill tables (which columns hold x64 multiples, percentages, status.csv/remote.csv indices, ms
 * durations) and are cross-checked against script/skilldesc texts by tools/verify-characters.mjs
 * ("damages the enemy in a 4m radius" = Arg 512, "for 20min ... radius of 14m" = 1792/../1200000):
 *   1000xxx damage          [radius*128 (10002xx/10003xx/10005xx area families only), unk, addDamage, chance, statusIndex, statusDurationMs, unk, unk]
 *   3000xxx projectile      [remoteIndex, radius*128, unk, addDamage, chance, statusIndex, statusDurationMs, unk]
 *   20000xx/20004xx heal    [amount, hpPerSpr*100]              ("Receives 20 HP for 1 Mentality" = 2000)
 *   20001xx/20002xx heal    [radius*128, amount, hpPerSpr*100]  (area heal)
 *   40000xx status          [chance, statusIndex, durationMs]      (4000006 "transup": [durationMs, transform, level])
 *   40001xx/40002xx status  [radius*128, chance, statusIndex, durationMs]  (area: party buff / enemy debuff)
 *   5000001 summon          [servantIndex]
 * Other families (other 4xxxxxx layouts, 20003xx/20005xx, 5000003, 7xxxxxx ...) are kept as raw args only.
 * `chance` is the % chance to apply statusIndex (only emitted together with a status).
 */
export function describeResult(code, args, ctx = null) {
  const c = String(code);
  const a = args.map(Number);
  const out = { resultCode: +c };
  const R = (v) => +(v / SKILL_DISTANCE_SCALE).toFixed(4);
  const status = (ch, st, dur) => {
    if (!st) return;
    out.statusIndex = st;
    if (ch) out.chance = ch;
    if (dur) out.statusDurationMs = dur;
  };
  if (/^1000\d{3}$/.test(c)) {
    out.kind = 'damage';
    if (/^1000[235]\d\d$/.test(c) && a[0] > 0) out.radius = R(a[0]);
    out.addDamage = a[2];
    status(a[3], a[4], a[5]);
  } else if (/^3000\d{3}$/.test(c)) {
    out.kind = 'projectile';
    out.remoteIndex = a[0];
    if (a[1]) out.radius = R(a[1]);
    out.addDamage = a[3];
    status(a[4], a[5], a[6]);
    if (ctx && !ctx.remotes.has(a[0])) out.remoteMissing = true;
  } else if (/^2000[04]\d\d$/.test(c)) {
    out.kind = 'heal'; out.amount = a[0]; if (a[1]) out.perSpr = a[1] / 100;
  } else if (/^2000[12]\d\d$/.test(c)) {
    out.kind = 'heal'; if (a[0]) out.radius = R(a[0]); out.amount = a[1]; if (a[2]) out.perSpr = a[2] / 100;
  } else if (/^2\d{6}$/.test(c)) {
    out.kind = 'heal_other';
  } else if (c === '4000006') {
    // "transup" skills: [durationMs, transform index (not in status.csv), skill level]
    out.kind = 'status_other'; out.durationMs = a[0];
  } else if (/^40000\d\d$/.test(c)) {
    out.kind = 'status';
    out.chance = a[0]; out.statusIndex = a[1]; out.durationMs = a[2];
  } else if (/^4000[12]\d\d$/.test(c)) {
    out.kind = 'area_status';
    out.target = c[4] === '1' ? 'party' : 'enemies';
    if (a[0]) out.radius = R(a[0]);
    out.chance = a[1]; out.statusIndex = a[2]; out.durationMs = a[3];
  } else if (/^4\d{6}$/.test(c)) {
    out.kind = 'status_other';
  } else if (/^5000001$/.test(c)) {
    out.kind = 'summon'; out.servantIndex = a[0];
  } else if (/^5\d{6}$/.test(c)) {
    out.kind = 'summon_other';
  } else {
    out.kind = 'other';
  }
  if (out.statusIndex && ctx && !ctx.statuses.has(out.statusIndex)) out.statusMissing = true;
  out.args = a;
  return out;
}

// ---------------------------------------------------------------------------------------------------------------
// Pure parsers
// ---------------------------------------------------------------------------------------------------------------

const toText = (src, korean = false) => (typeof src === 'string' ? src : decodeText(src instanceof ArrayBuffer ? new Uint8Array(src) : src, korean));

/** CSV text -> { header:string[], rows:object[] } (header row = first row). */
export function csvObjects(src, korean = false) {
  const rows = parseCSV(toText(src, korean));
  const header = (rows.shift() || []).map(h => String(h).trim());
  const out = [];
  for (const r of rows) {
    if (!r || !r.some(x => String(x).trim() !== '')) continue;
    const o = {};
    header.forEach((h, i) => { if (h && !(h in o)) o[h] = r[i] === undefined ? '' : String(r[i]).trim(); });
    o.__cells = r;
    out.push(o);
  }
  return { header, rows: out };
}

/**
 * share/action/action/pc/<cls>.act.<classIndex>.dat
 * layout: u32 creatureType(0=PC) | u32 classIndex | char[256] skeleton path | records[] of 303 bytes:
 *   u8 style | u32 action | u32 index | char[256] anim path | f32 startInter | f32 endInter | f32 timeLength |
 *   u8 swing | u8 strike | f32 timing | u8 split | f32 timing2 | f32 freeze | u32 effect | u32 cancelTime | u8[3] unk
 */
export function parseActionDat(buf) {
  const r = new BinReader(buf);
  const HEADER = 264, REC = 303;
  if (r.length < HEADER || (r.length - HEADER) % REC !== 0) throw new Error(`action dat: bad size ${r.length}`);
  const creatureType = r.u32();
  const classIndex = r.u32();
  const skeleton = r.fixedStr(256, true);
  const records = [];
  while (!r.eof()) {
    const style = r.u8r();
    const action = r.u32();
    const index = r.u32();
    const anim = r.fixedStr(256, true);
    records.push({
      style, action, actionName: ACTION_NAMES[action] || `ACTION_${action}`, index, anim,
      startInter: r.f32(), endInter: r.f32(), timeLength: r.f32(), swing: r.u8r(), strike: r.u8r(), timing: r.f32(),
      split: r.u8r(), timing2: r.f32(), freeze: r.f32(), effect: r.u32(), cancelTime: r.u32(), unk: Array.from(r.bytes(3)),
    });
  }
  return { creatureType, classIndex, skeleton, records, consumed: r.pos, length: r.length };
}

/**
 * Bone-name scan of a .skel (sufficient for attach-bone checks; full skeleton parsing belongs to the skel module).
 * Each bone record starts with two length-prefixed names: name1 XOR k1, name2 XOR k2 (v2019 files: per-file k1,
 * k2 = 0x3A; v2004 files: plain). k1/k2 are recovered from the root bone which is always "Bip01".
 */
export function skelBoneNames(buf) {
  const u8 = buf instanceof ArrayBuffer ? new Uint8Array(buf) : new Uint8Array(buf.buffer, buf.byteOffset, buf.byteLength);
  const dv = new DataView(u8.buffer, u8.byteOffset, u8.byteLength);
  const version = dv.getUint32(0, true), boneCount = dv.getUint32(8, true), first = dv.getUint32(12, true);
  const n0 = dv.getUint32(first, true);
  const k1 = u8[first + 4] ^ 0x42;
  const k2 = u8[first + 8 + n0] ^ 0x42;
  const printable = (a) => a.every(c => c >= 32 && c < 127);
  const dec = (off, n, k) => Array.from(u8.subarray(off, off + n), c => c ^ k);
  const junk = String.fromCharCode(k1).repeat(3);
  const names = [], alt = [];
  let i = first;
  while (i + 8 < u8.length) {
    const n = dv.getUint32(i, true);
    if (n >= 1 && n <= 64 && i + 8 + n <= u8.length) {
      const a = dec(i + 4, n, k1);
      const n2 = dv.getUint32(i + 4 + n, true);
      if (printable(a) && n2 >= 1 && n2 <= 64 && i + 8 + n + n2 <= u8.length) {
        const b = dec(i + 8 + n, n2, k2);
        const s1 = String.fromCharCode(...a);
        if (printable(b) && !(k1 >= 32 && k1 < 127 && s1.includes(junk))) {
          names.push(s1); alt.push(String.fromCharCode(...b));
          i += 8 + n + n2; continue;
        }
      }
    }
    i++;
  }
  return { version, boneCount, names, altNames: alt, keys: [k1, k2] };
}

/** property/item/default.txt -> { SECTION: { game_mesh, game_tpack, ... } } */
export function parseSectionTxt(src) {
  const out = {};
  let cur = null;
  for (const raw of toText(src).split(/\r?\n/)) {
    const line = raw.trim();
    if (!line || line.startsWith('//')) continue;
    let m = /^\[\/([^\]]+)\]$/.exec(line);
    if (m) { cur = null; continue; }
    m = /^\[([^\]/]+)\]$/.exec(line);
    if (m) { cur = out[m[1].toUpperCase()] = {}; continue; }
    m = /^(\S+)\s+"?([^"]*)"?\s*$/.exec(line);
    if (m && cur) cur[m[1].toLowerCase()] = m[2].trim();
  }
  return out;
}

/** script/producer/char_createinfo.txt (character-creation showcase) -> { classIndex: {...} } */
export function parseCreateInfo(src) {
  const out = {};
  for (const raw of toText(src).split(/\r?\n/)) {
    const parts = raw.trim().split(/\s+/);
    if (parts.length < 3) continue;
    const [key, idxS, ...rest] = parts;
    const idx = Number(idxS);
    if (!Number.isInteger(idx)) continue;
    const o = out[idx] || (out[idx] = { meshes: [] });
    if (key === 'mesh') o.meshes.push({ mesh: rest[0], tpack: rest[1] || '' });
    else o[key] = rest.map(Number).length === 1 ? Number(rest[0]) : rest.map(Number);
  }
  return out;
}

/** share/skill/<skill>.csv -> { kv, combos[], levels[] } */
export function parseSkillCSV(src) {
  const rows = parseCSV(toText(src, true));
  const kv = {};
  const combos = [], levels = [];
  let mode = 'kv', chdr = null, lhdr = null;
  for (const r of rows) {
    if (!r || !r.length) continue;
    const f0 = String(r[0]).trim();
    if (f0 === 'ComboIndex') { chdr = r.map(x => String(x).trim()); mode = 'combo'; continue; }
    if (f0 === 'LevelIndex') { lhdr = r.map(x => String(x).trim()); mode = 'level'; continue; }
    if (mode === 'kv') { if (f0 && r.length > 1 && !(f0 in kv)) kv[f0] = String(r[1]).trim(); continue; }
    if (!/^\d+$/.test(f0)) continue;
    const hdr = mode === 'combo' ? chdr : lhdr;
    const o = {};
    hdr.forEach((h, i) => { if (h && !(h in o)) o[h] = r[i] === undefined ? '' : String(r[i]).trim(); });
    (mode === 'combo' ? combos : levels).push(o);
  }
  return { kv, combos, levels };
}

/** share/combo/combo.csv -> Map("class:style" -> steps[]) */
export function parseComboCSV(src) {
  const rows = parseCSV(toText(src));
  const out = new Map();
  for (let i = 0; i < rows.length; i++) {
    if (String(rows[i][0]).trim() !== 'CLASS') continue;
    const [c, s, m] = rows[i + 1].map(x => Number(x));
    const hdr = rows[i + 2].map(x => String(x).trim());
    const steps = [];
    for (let k = 0; k < m; k++) {
      const r = rows[i + 3 + k];
      if (!r) break;
      const o = {};
      hdr.forEach((h, j) => { if (h) o[h] = Number(r[j]); });
      steps.push({ step: o.COMBOCOUNT, timeLength: o.TimeLength, timing: o.Timing, timing2: o.Timing2, resultCode: o.RESULTCODE,
        args: [o.Arg0, o.Arg1, o.Arg2, o.Arg3, o.Arg4, o.Arg5] });
    }
    out.set(`${c}:${s}`, steps);
    i += 2 + m;
  }
  return out;
}

/** "key ,value" ini (share/formula.ini) -> object with numbers where possible */
export function parseCommaIni(src) {
  const out = {};
  for (const raw of toText(src).split(/\r?\n/)) {
    const m = /^\s*([A-Za-z_]\w*)\s*,\s*(\S+)\s*$/.exec(raw);
    if (!m) continue;
    const v = m[2].replace(/f$/, '');
    out[m[1]] = Number.isFinite(Number(v)) ? Number(v) : m[2];
  }
  return out;
}

/** effectscene*.txt -> Map(id -> name) for one <cate> (default 100 = Skill). */
export function effectSceneIndex(src, cate = 100) {
  const out = new Map();
  let inCate = false, pendingId = null;
  for (const raw of toText(src, true).split(/\r?\n/)) {
    const line = raw.trim();
    let m = /^<cate>\s+(\d+)/.exec(line);
    if (m) { inCate = Number(m[1]) === cate; continue; }
    if (!inCate) continue;
    if (line === '<effect>') { pendingId = null; continue; }
    m = /^id\s+(\d+)$/.exec(line);
    if (m) { pendingId = Number(m[1]); continue; }
    m = /^name\s+(\S+)/.exec(line);
    if (m && pendingId !== null) { if (!out.has(pendingId)) out.set(pendingId, m[1]); pendingId = null; }
  }
  return out;
}

// ---------------------------------------------------------------------------------------------------------------
// Builder (Node only)
// ---------------------------------------------------------------------------------------------------------------

const num = (v) => { const x = Number(String(v ?? '').trim()); return Number.isFinite(x) ? x : null; };
const isNum = (v) => /^-?\d+(\.\d+)?$/.test(String(v ?? '').trim());

export async function build({ dataRoot, verbose = false, formats = null } = {}) {
  const t0 = Date.now();
  const F = formats || await loadFormatModules();
  const parseTpack = F.tpack?.parseTpack || parseTpackLite;
  const texCands = F.tpack?.textureCandidates || textureCandidatesLite;
  const problems = [];      // hard failures: referenced path missing, parse errors
  const notes = [];         // soft: fallbacks used, heuristics
  const log = (...a) => { if (verbose) console.log(...a); };

  // ---- file index (lower-case key -> absolute path)
  const FILES = new Map();
  for (const top of ['anim', 'mesh', 'skel', 'texture', 'texturepack', 'share', 'script', 'property', 'sound']) {
    const abs = path.join(dataRoot, top);
    if (!fs.existsSync(abs)) continue;
    for (const rel of fs.readdirSync(abs, { recursive: true })) {
      const key = normPath(`${top}/${rel}`);
      if (!FILES.has(key)) FILES.set(key, path.join(abs, rel));
    }
  }
  const has = (k) => !!k && FILES.has(normPath(k));
  const read = (k) => { const a = FILES.get(normPath(k)); if (!a) throw new Error(`missing ${k}`); return fs.readFileSync(a); };
  const readText = (k, korean = false) => decodeText(read(k), korean);
  const textureByBase = new Map();
  for (const k of FILES.keys()) {
    if (!k.startsWith('texture/')) continue;
    const b = k.slice(k.lastIndexOf('/') + 1);
    if (!textureByBase.has(b)) textureByBase.set(b, k);
  }
  const need = (kind, key, ctx) => { if (!has(key)) problems.push(`${ctx}: missing ${kind} ${key}`); return key; };

  // ---- tables
  const pcRows = parseCSV(readText('share/pc/pcclass.csv'));
  const pc = {};
  for (const r of pcRows) pc[String(r[0]).trim()] = r.slice(1).map(x => String(x).trim());
  const pcNum = (key, i) => num(pc[key]?.[i]);
  const defaults = parseSectionTxt(read('property/item/default.txt'));
  const createInfo = parseCreateInfo(read('script/producer/char_createinfo.txt'));
  const formula = parseCommaIni(read('share/formula.ini'));
  Object.assign(formula, parseCommaIni(read('share/formulaex.ini')));
  const combos = parseComboCSV(read('share/combo/combo.csv'));
  const boneRows = csvObjects(read('script/weapon_bonename.csv'), true).rows;
  const weaponLeft = new Map(csvObjects(read('script/weapon_left.csv')).rows.map(r => [num(r.index), num(r.index2)]));
  const weapons = csvObjects(read('share/item/itemweapon.csv'), true).rows;
  const shapeRows = parseCSV(readText('script/shape/item_shape.csv', true));
  const SHAPE = new Map();
  for (const r of shapeRows.slice(1)) if (isNum(r[0])) SHAPE.set(Number(r[0]), r.map(x => String(x ?? '').trim()));
  const remotes = new Map();
  for (const r of csvObjects(read('share/creature/remote.csv'), true).rows) {
    if (!isNum(r.Index)) continue;
    remotes.set(Number(r.Index), {
      index: Number(r.Index), description: r.Description, resultType: num(r.ResultType), maxDistance: num(r.MaxDistance),
      moveSpeed: num(r.MoveSpeed), size: num(r.Size), maxPiercing: num(r.MaxPiercingNum), piercingRate: num(r.MaxPiercingRate),
      effectId: num(r.EffectID), sceneId: num(r.SceneID), effectTimeMs: num(r.EffectTime),
      contactEffectId: num(r.ContactEffectID), contactSceneId: num(r.ContactSceneID), contactEffectTimeMs: num(r.ContactEffectTime),
      hitCycleMs: num(r.HitCycle),
    });
  }
  const statuses = new Map();
  for (const r of csvObjects(read('share/skill/status.csv'), true).rows) {
    if (!isNum(r.Index)) continue;
    const opts = [];
    for (let k = 0; k < 10; k++) {
      const code = r[`Option${k}_code`], val = r[`Option${k}_Value`];
      if (code && code !== 'NONE') opts.push({ code, value: num(val) });
    }
    statuses.set(Number(r.Index), { index: Number(r.Index), description: (r.Description || '').replace(/\\/g, ' / '), options: opts, iconIndex: num(r.IconIndex) });
  }
  // effect scene ids (cate 100 "Skill") -> name, per visual file, plus the sound scene file
  const effectFiles = ['01', '02', '03', 'com', 'map'].map(s => `property/effect/effectscene.${s}.txt`).filter(has);
  const effVisual = effectFiles.map(f => ({ file: f, ids: effectSceneIndex(read(f)) }));
  const effSound = has('property/effect/effectscene.snd.txt') ? effectSceneIndex(read('property/effect/effectscene.snd.txt')) : new Map();
  const effectRef = (id, scene, timeMs) => {
    if (!id) return null;
    const o = { id, scene, timeMs };
    const v = effVisual.find(e => e.ids.has(id));
    if (v) { o.visual = v.ids.get(id); o.visualFile = v.file; }
    if (effSound.has(id)) o.sound = effSound.get(id);
    return o;
  };
  // remotes (projectiles) and statuses referenced by the emitted skills -> top-level dictionaries
  // (collected after the skills are chosen, see the post-pass below)
  const resultCtx = { remotes, statuses, useRemote: () => {}, useStatus: () => {} };

  // action files by class index
  const actionFiles = new Map();
  for (const k of FILES.keys()) {
    const m = /^share\/action\/action\/pc\/([a-z]+)\.act\.(\d+)\.dat$/.exec(k);
    if (m) actionFiles.set(Number(m[2]), k);
  }

  // skill CSVs grouped by PCClassFlag
  const skillsByFlag = new Map();
  let skillFilesParsed = 0;
  for (const k of FILES.keys()) {
    if (!/^share\/skill\/[^/]+\.csv$/.test(k)) continue;
    let parsed;
    try { parsed = parseSkillCSV(read(k)); } catch (e) { problems.push(`skill ${k}: ${e.message}`); continue; }
    const flag = parsed.kv.PCClassFlag;
    if (!flag) continue;
    skillFilesParsed++;
    parsed.file = k;
    if (!skillsByFlag.has(flag)) skillsByFlag.set(flag, []);
    skillsByFlag.get(flag).push(parsed);
  }

  const texturesOfTpack = (tpackKey, ctx) => {
    if (!has(tpackKey)) { problems.push(`${ctx}: missing tpack ${tpackKey}`); return { texpath: '', textures: [] }; }
    const tp = parseTpack(read(tpackKey));
    const texdir = tp.texdir ?? (tp.texpath ? normPath(tp.texpath) : '');
    const textures = [];
    const pick = (file) => {
      if (!file) return null;
      const first = texdir ? `texture/${texdir}/${normPath(file)}` : `texture/${normPath(file)}`;
      if (has(first)) return first;
      const c = texCands(texdir, file).find(has);
      const b = normPath(file).split('/').pop();
      const fb = c || textureByBase.get(b) || textureByBase.get(b.replace(/\.[^.]*$/, '') + '.dds');
      if (fb) { notes.push(`${ctx}: texture ${file} not at ${first}, using ${fb}`); return fb; }
      problems.push(`${ctx}: missing texture ${file} (texpath "${tp.texpath}") from ${tpackKey}`);
      return first;
    };
    const keysOf = (o) => Object.keys(o || {}).map(Number).filter(Number.isInteger);
    const slots = new Set([...keysOf(tp.diffuse), ...keysOf(tp.specular)].filter(i => tp.diffuse[i] || tp.specular[i]));
    for (const i of [...slots].sort((a, b) => a - b)) {
      textures.push({ material: i, diffuse: pick(tp.diffuse[i]), specular: tp.specular[i] ? pick(tp.specular[i]) : null,
        ...(tp.bump[i] ? { bump: pick(tp.bump[i]) } : {}), ...(tp.glow[i] ? { glow: pick(tp.glow[i]) } : {}) });
    }
    return { texpath: tp.texpath, textures };
  };

  const shapeAssets = (shapeIndex, ctx) => {
    const s = SHAPE.get(shapeIndex);
    if (!s) return null;
    const mesh = gamePathToData('mesh', s[1]);
    let tpack = s[2] ? gamePathToData('texturepack', s[2]) : null;
    if (!tpack || !has(tpack)) {
      const conv = mesh.replace(/^mesh\//, 'texturepack/').replace(/\.mesh$/, '.tpack');
      if (has(conv)) { if (tpack) notes.push(`${ctx}: shape tpack ${tpack} missing, using ${conv}`); tpack = conv; }
    }
    const leftGame = s[23] ? gamePathToData('mesh', s[23]) : null;
    return { shapeIndex, mesh, tpack, leftMesh: leftGame, row: s };
  };

  const classes = [];
  for (const W of CLASS_WIRING) {
    const i = W.index;
    const ctx = `class ${i} ${W.code}`;
    const cls = {
      index: i, code: W.code, name: pc.name_kor?.[i] || pc.name_eng?.[i], nameCode: pc.name_eng?.[i],
      classic: W.classic, playable: false, sex: pcNum('sex', i), size: pcNum('size', i),
    };
    // ---- action file + skeleton
    const actKey = actionFiles.get(i);
    let act = null;
    if (!actKey) problems.push(`${ctx}: no share/action/action/pc/*.act.${i}.dat`);
    else {
      try { act = parseActionDat(read(actKey)); } catch (e) { problems.push(`${ctx}: ${actKey}: ${e.message}`); }
    }
    cls.actionFile = actKey || null;
    cls.skeleton = act ? need('skeleton', gamePathToData('skel', act.skeleton), ctx) : null;
    let bones = null, skelParsed = null;
    if (cls.skeleton && has(cls.skeleton)) {
      if (F.skel?.parseSkel) {
        try {
          skelParsed = F.skel.parseSkel(read(cls.skeleton), { computeMatrices: true });
          bones = { version: skelParsed.version, boneCount: skelParsed.bones.length, names: skelParsed.bones.map(b => b.name), altNames: skelParsed.bones.map(b => b.alias || '') };
        } catch (e) { notes.push(`${ctx}: skel.js failed on ${cls.skeleton} (${e.message}); using the name scanner`); }
      }
      if (!bones) bones = skelBoneNames(read(cls.skeleton));
      cls.skeletonInfo = { version: `0x${bones.version.toString(16)}`, boneCount: bones.boneCount, bonesFound: bones.names.length, parser: skelParsed ? 'src/formats/skel.js' : 'name scan' };
    }
    const boneSet = new Set([...(bones?.names || []), ...(bones?.altNames || [])].filter(Boolean));
    const boneSetLower = new Set([...boneSet].map(s => s.toLowerCase()));
    const hasBone = (n) => boneSet.has(n) || boneSetLower.has(String(n).toLowerCase());
    const recs = act ? act.records : [];
    const firstAnim = recs.find(r => r.anim)?.anim || '';
    cls.animDir = firstAnim ? gamePathToData('anim', firstAnim.split('\\').slice(0, 2).join('\\')) : null;

    // ---- default body parts (property/item/default.txt), textures via tpack
    cls.scale = 1;
    const ci = createInfo[i];
    if (ci) cls.showcase = { scale: ci.scale ?? null, mapIndex: ci.mapindex ?? null, standTime: ci.stand ?? null };
    cls.parts = [];
    for (const P of PART_SLOTS) {
      const sec = defaults[`${W.code}_${P.key}`];
      if (!sec || !sec.game_mesh) { problems.push(`${ctx}: no [${W.code}_${P.key}] in property/item/default.txt`); continue; }
      const mesh = need('mesh', gamePathToData('mesh', sec.game_mesh), ctx);
      const tpack = gamePathToData('texturepack', sec.game_tpack || sec.game_mesh.replace(/\.mesh$/i, '.tpack'));
      const tx = texturesOfTpack(tpack, `${ctx} ${P.slot}`);
      cls.parts.push({ slot: P.slot, role: P.role, mesh, tpack, texture: tx.textures[0]?.diffuse || null, textures: tx.textures });
    }
    // character-creation showcase outfit (the _14 armour set shown on the class-select screen)
    if (ci && ci.meshes?.length) {
      cls.showcase.parts = ci.meshes.map((m, k) => {
        const mesh = gamePathToData('mesh', m.mesh);
        const tpack = gamePathToData('texturepack', m.tpack || m.mesh.replace(/\.mesh$/i, '.tpack'));
        const ok = has(mesh);
        if (!ok) notes.push(`${ctx}: showcase mesh ${mesh} missing (listed in char_createinfo.txt)`);
        const tx = ok ? texturesOfTpack(tpack, `${ctx} showcase ${k}`) : { textures: [] };
        return { mesh: ok ? mesh : null, listed: mesh, tpack, texture: tx.textures[0]?.diffuse || null, textures: tx.textures };
      }).filter(p => p.mesh);
    }

    // ---- starter weapon
    let weapon = null;
    const jobHas = (job) => { const s = String(job || '').replace(/-/g, ''); return s[i] === '1'; };
    const atk = (w) => ['Level 0 Melee Max Attack', 'Level 0 Magic Max Attack', 'Level 0 Range Max Attack', 'Level 0 Defence Max'].reduce((s, k) => s + (num(w[k]) || 0), 0);
    const cands = [];
    for (const [pref, code] of W.weapons.entries()) {
      for (const w of weapons) {
        if (w.Type !== '4' || Number(w.Code) !== code || !jobHas(w.Job)) continue;
        const lv = num(w.ReqLv);
        if (!lv || lv < 1 || w.Rank !== '0' || /\+\d|TEST|^GM|Hellion|Anniversary|1Day/i.test(w.Name)) continue;
        const sa = shapeAssets(num(w.ItemShape), ctx);
        if (!sa || !has(sa.mesh)) continue;
        cands.push({ w, code, pref, lv, atk: atk(w), sa });
      }
    }
    cands.sort((a, b) => a.lv - b.lv || a.pref - b.pref || a.atk - b.atk || Number(a.w.ItemIndex) - Number(b.w.ItemIndex));
    let pickW = cands[0];
    let wsrc = 'itemweapon.csv';
    if (!pickW) {
      // weapons of the newest classes are not in itemweapon.csv (they live in item.dat): take the first item_shape row
      // in the weapon's mesh folder whose mesh exists.
      // Preference: plain tier-1 model (..._01.mesh), then the legend tier-1 (..._leg_01 / leg_..._01), then the
      // lowest item_shape index.
      const rank = (m) => {
        const b = m.slice(m.lastIndexOf('/') + 1);
        if (/^att_equ_[a-z]+_0?1\.mesh$/.test(b)) return 0;
        if (/^att_equ_(leg_[a-z]+|[a-z]+_leg)_0?1\.mesh$/.test(b)) return 1;
        return 2;
      };
      for (const code of W.weapons) {
        const folder = SHAPE_FOLDER_FALLBACK[code];
        if (!folder) continue;
        const found = [];
        for (const [id, s] of SHAPE) {
          const m = gamePathToData('mesh', s[1] || '');
          if (!m || !m.startsWith(`mesh/item/weapon/${folder}/`) || /_l\.mesh$/.test(m) || !has(m)) continue;
          found.push({ id, m, r: rank(m) });
        }
        found.sort((a, b) => a.r - b.r || a.id - b.id);
        if (found.length) { pickW = { w: null, code, pref: 0, lv: 1, atk: 0, sa: shapeAssets(found[0].id, ctx) }; break; }
      }
      wsrc = 'item_shape.csv (folder fallback)';
      if (pickW) notes.push(`${ctx}: starter weapon not in itemweapon.csv; picked item_shape ${pickW.sa.shapeIndex} ${pickW.sa.mesh}`);
    }
    let style = null;
    if (pickW) {
      const code = pickW.code, WC = WEAPON_CODES[code];
      const weaponType = 1024 + code;
      const br = boneRows.find(r => Number(r.__cells[0]) === i && Number(r.__cells[1]) === weaponType);
      const bonesObj = br ? { peaceLeft: br.__cells[2], peaceRight: br.__cells[3], battleLeft: br.__cells[4], battleRight: br.__cells[5] } : null;
      if (!br) problems.push(`${ctx}: weapon_bonename.csv has no row for class ${i} weaponType ${weaponType}`);
      const hand = HAND_BY_CODE[code] || 'right';
      const tx = pickW.sa.tpack ? texturesOfTpack(pickW.sa.tpack, `${ctx} weapon`) : { textures: [] };
      if (!pickW.sa.tpack) problems.push(`${ctx}: weapon ${pickW.sa.mesh} has no tpack`);
      let leftMesh = null;
      const lIdx = pickW.w ? weaponLeft.get(Number(pickW.w.ItemIndex)) : null;
      let leftMeshSource = null;
      if (hand === 'both') {
        const conv = pickW.sa.mesh.replace(/\.mesh$/, '_l.mesh');
        if (pickW.sa.leftMesh && has(pickW.sa.leftMesh)) { leftMesh = pickW.sa.leftMesh; leftMeshSource = 'item_shape.csv column 23'; }
        else if (has(conv)) { leftMesh = conv; leftMeshSource = '<mesh>_l.mesh'; }
        else { leftMesh = pickW.sa.mesh; leftMeshSource = 'same mesh as the right hand (no _l variant exists for this old item)'; }
      }
      const bone = bonesObj ? (hand === 'left' ? bonesObj.battleLeft : bonesObj.battleRight) : null;
      const bonePeace = bonesObj ? (hand === 'left' ? bonesObj.peaceLeft : bonesObj.peaceRight) : null;
      const boneLeft = hand === 'both' && bonesObj ? bonesObj.battleLeft : null;
      const bonePeaceLeft = hand === 'both' && bonesObj ? bonesObj.peaceLeft : null;
      const usedBones = new Set([bone, bonePeace, boneLeft, bonePeaceLeft].filter(Boolean));
      for (const [k, b] of Object.entries(bonesObj || {})) {
        if (!b || !bones || hasBone(b)) continue;
        if (usedBones.has(b)) problems.push(`${ctx}: attach bone "${b}" (${k}) not found in ${cls.skeleton}`);
        else notes.push(`${ctx}: unused-hand bone "${b}" (${k}) from weapon_bonename.csv is not in ${cls.skeleton}`);
      }
      // action style for this weapon: first candidate style that has STAND + ATTACK records
      for (const s of WC.styles) {
        if (recs.some(r => r.style === s && r.action === 1) && recs.some(r => r.style === s && r.action === 6)) { style = s; break; }
      }
      if (style === null) { style = 1; problems.push(`${ctx}: no action style for weapon ${WC.name}; using BAREHANDS`); }
      const w = pickW.w;
      // The actual hand is read from the skeleton: the attach bone hangs under 'Bip01 L Hand' or 'Bip01 R Hand'
      // (weapon_bonename columns are primary/secondary slots, not hands: the Trie Muse lily lists weaponL1, a
      // left-hand bone, in every column). Fallback: side of the bind position (+X = the character's left).
      const sideOfBone = (name) => {
        if (!skelParsed || !name) return null;
        let k = F.skel.findBone(skelParsed, name);
        const k0 = k;
        while (k >= 0) {
          const nm = skelParsed.bones[k].name;
          if (/\bL Hand$/i.test(nm)) return 'left';
          if (/\bR Hand$/i.test(nm)) return 'right';
          k = skelParsed.bones[k].parent;
        }
        return k0 >= 0 ? (skelParsed.bones[k0].bindMatrix[12] > 0 ? 'left' : 'right') : null;
      };
      const actualHand = hand === 'both' ? 'both' : (sideOfBone(bone) || hand);
      weapon = {
        source: wsrc,
        itemIndex: w ? Number(w.ItemIndex) : null, name: w ? w.Name : null, reqLevel: w ? num(w.ReqLv) : null,
        code, type: WC.name, weaponType, style, styleName: STYLE_NAMES[style],
        mesh: need('mesh', pickW.sa.mesh, `${ctx} weapon`), tpack: pickW.sa.tpack, texture: tx.textures[0]?.diffuse || null, textures: tx.textures,
        leftMesh, ...(leftMesh ? { leftMeshSource } : {}), leftItemIndex: lIdx || null,
        hand: actualHand, handFrom: hand === 'both' ? 'two meshes (right + left column)' : 'skeleton (attach bone parent chain)',
        column: hand === 'both' ? 'both' : hand,
        bone, bonePeace, ...(hand === 'both' ? { boneLeft, bonePeaceLeft, secondHand: sideOfBone(boneLeft) } : {}), bones: bonesObj,
        shapeIndex: pickW.sa.shapeIndex,
        stats: w ? {
          meleeMin: num(w['Level 0 Melee Min Attack']), meleeMax: num(w['Level 0 Melee Max Attack']),
          magicMin: num(w['Level 0 Magic Min Attack']), magicMax: num(w['Level 0 Magic Max Attack']),
          rangeMin: num(w['Level 0 Range Min Attack']), rangeMax: num(w['Level 0 Range Max Attack']),
          range: num(w['Wear : Range']), speed: num(w['Wear : Speed']), critical: num(w['Wear : CriticalRate']),
          reqStr: num(w['Level 0 Str Request']), reqDex: num(w['Level 0 Dex Request']), reqSpr: num(w['Level 0 Spr Request']),
        } : null,
      };
      // cross-check: the chosen style's ATTACK animations should live in the weapon's motion folder
      const att = recs.find(r => r.style === style && r.action === 6);
      if (att && WC.token.length) {
        const up = att.anim.toUpperCase();
        if (!WC.token.some(t => up.includes(`\\${t}\\`) || up.includes(`_${t}_`))) notes.push(`${ctx}: style ${style} attack anim ${att.anim} does not contain ${WC.token.join('/')}`);
        else weapon.styleCheck = `ATTACK anims of style ${style} are in the ${WC.token[0]} motion folder`;
      }
    } else {
      problems.push(`${ctx}: no starter weapon found`);
      style = 1;
    }
    cls.weapon = weapon;
    cls.style = style;
    cls.styleName = STYLE_NAMES[style];

    // ---- mesh-level validation (src/formats/mesh.js): skin palette vs skeleton, material slots vs tpack textures
    if (F.mesh?.parseMesh) {
      const box = { min: [Infinity, Infinity, Infinity], max: [-Infinity, -Infinity, -Infinity] };
      const inspect = (key, textures, label, skinned) => {
        let m;
        try { m = F.mesh.parseMesh(read(key)); } catch (e) { problems.push(`${ctx} ${label}: parseMesh failed on ${key}: ${e.message}`); return null; }
        const pal = new Set(), mats = new Set();
        let verts = 0, tris = 0;
        for (const s of m.meshes) {
          (s.bonePalette || []).forEach(b => pal.add(b));
          mats.add(s.material);
          verts += s.positions.length / 3; tris += s.indices.length / 3;
        }
        const info = { version: `0x${m.version.toString(16)}`, subMeshes: m.meshes.length, vertices: verts, triangles: Math.round(tris),
          materials: [...mats].sort((a, b) => a - b), bbox: m.bbox };
        if (skinned) {
          const missing = [...pal].filter(b => !hasBone(b));
          info.skinBones = pal.size;
          if (missing.length) problems.push(`${ctx} ${label}: ${key} skinned to bones not in ${cls.skeleton}: ${missing.join(', ')}`);
          if (m.bbox) for (let k = 0; k < 3; k++) { box.min[k] = Math.min(box.min[k], m.bbox.min[k]); box.max[k] = Math.max(box.max[k], m.bbox.max[k]); }
        } else {
          info.ownBones = [...pal];
          if (m.lines?.length) info.lines = m.lines.map(l => l.name);
          if (m.helpers?.length) info.helpers = m.helpers.map(h => h.name);
        }
        const tx = new Set((textures || []).filter(t => t.diffuse).map(t => t.material));
        const noTex = info.materials.filter(k => !tx.has(k));
        if (noTex.length) problems.push(`${ctx} ${label}: ${key} uses material slot(s) ${noTex.join(',')} with no diffuse texture in its tpack`);
        return info;
      };
      for (const p of cls.parts) if (has(p.mesh)) p.meshInfo = inspect(p.mesh, p.textures, p.slot, true);
      if (weapon && has(weapon.mesh)) weapon.meshInfo = inspect(weapon.mesh, weapon.textures, 'weapon', false);
      if (weapon?.leftMesh && has(weapon.leftMesh)) weapon.leftMeshInfo = inspect(weapon.leftMesh, weapon.textures, 'weapon(left)', false);
      if (Number.isFinite(box.min[1])) {
        cls.bindBox = { min: box.min.map(v => +v.toFixed(4)), max: box.max.map(v => +v.toFixed(4)) };
        cls.bindHeight = +(box.max[1] - box.min[1]).toFixed(4);
      }
    } else notes.push(`${ctx}: src/formats/mesh.js not available - mesh-level checks skipped`);
    // bind-pose position of the attach bones (file frame, from skel.js) - handy for placing the weapon without animation
    if (skelParsed && weapon) {
      const at = (name) => {
        const k = F.skel.findBone(skelParsed, name);
        if (k < 0) return null;
        const b = skelParsed.bones[k];
        return b.bindMatrix ? [b.bindMatrix[12], b.bindMatrix[13], b.bindMatrix[14]].map(v => +v.toFixed(4)) : null;
      };
      weapon.boneBindPosition = at(weapon.bone);
      weapon.boneIndex = F.skel.findBone(skelParsed, weapon.bone);
      weapon.bonePeaceIndex = F.skel.findBone(skelParsed, weapon.bonePeace);
    }

    // ---- animation map
    // timing / timing2 are fractions of timeLength. A few records are out of range (Segita Shooter style 35 ATTACK 0
    // has timing 15.7 where combo.csv has 0.157): repair ATTACK rows from combo.csv (same class/style/step), clamp
    // anything else to [0,1], and keep the raw value in timingRaw / timing2Raw.
    const fraction = (v, alt) => {
      if (v >= 0 && v <= 1.0001) return { v };
      if (alt !== undefined && alt >= 0 && alt <= 1) return { v: alt, raw: v, how: 'combo.csv' };
      return { v: Math.min(1, Math.max(0, v || 0)), raw: v, how: 'clamped' };
    };
    const animRef = (r) => {
      if (!r || !r.anim) return null;
      const key = gamePathToData('anim', r.anim);
      const cmb = r.action === 6 ? combos.get(`${i}:${r.style}`)?.[r.index] : undefined;
      const t1 = fraction(r.timing, cmb?.timing), t2 = fraction(r.timing2, cmb?.timing2);
      if (t1.raw !== undefined) notes.push(`${ctx}: ${r.actionName} style ${r.style} #${r.index} timing ${r.timing} is not a fraction; using ${t1.v} (${t1.how})`);
      if (t2.raw !== undefined) notes.push(`${ctx}: ${r.actionName} style ${r.style} #${r.index} timing2 ${r.timing2} is not a fraction; using ${t2.v} (${t2.how})`);
      return {
        anim: key, action: r.actionName, style: r.style, index: r.index, timeLength: +r.timeLength.toFixed(4),
        startInter: +r.startInter.toFixed(3), endInter: +r.endInter.toFixed(3),
        ...(t1.v ? { timing: +t1.v.toFixed(4) } : {}), ...(t2.v ? { timing2: +t2.v.toFixed(4) } : {}),
        ...(t1.raw !== undefined ? { timingRaw: r.timing, timingFix: t1.how } : {}), ...(t2.raw !== undefined ? { timing2Raw: r.timing2, timing2Fix: t2.how } : {}),
        ...(r.swing ? { swing: r.swing } : {}), ...(r.strike ? { strike: r.strike } : {}), ...(r.split ? { split: r.split } : {}),
        ...(r.freeze ? { freeze: +r.freeze.toFixed(4) } : {}), ...(r.effect ? { effect: r.effect } : {}),
        ...(r.cancelTime ? { cancelTime: r.cancelTime } : {}),
      };
    };
    // Records whose clip lies in the class' own anim folder win over earlier styles: some weapon styles carry
    // copy-paste rows from other classes (e.g. Segita Shooter style 35 REVIVE -> HalfWarrior\HWA_COM_REVIVE.anim,
    // while its style 0 row has SHT_COM_Revive.anim). Foreign clips are only used when nothing else exists.
    const ownClip = (x) => !cls.animDir || gamePathToData('anim', x.anim).startsWith(cls.animDir + '/');
    const findRec = (styles, action, index) => {
      for (const own of [true, false]) {
        for (const s of styles) {
          const r = recs.find(x => x.style === s && x.action === action && x.index === index && x.anim && (!own || ownClip(x)) && has(gamePathToData('anim', x.anim)));
          if (r) return r;
        }
      }
      return null;
    };
    const W_STYLES = [style, 1, 0];
    const anims = {};
    const setA = (name, styles, action, index, required = true) => {
      const r = findRec(styles, action, index);
      if (r) {
        anims[name] = animRef(r);
        if (r.style !== styles[0]) anims[name].fallbackFromStyle = styles[0];
      } else if (required) problems.push(`${ctx}: no existing animation for ${name} (${ACTION_NAMES[action]} idx ${index}, styles ${styles.join('/')})`);
    };
    setA('idlePeace', [0, 1], 1, 0);
    setA('idlePeaceAlt', [0, 1], 1, 1, false);
    setA('walkPeace', [0, 1], 2, 0);
    setA('runPeace', [0, 1], 2, 1);
    setA('idle', W_STYLES, 1, 0);
    setA('idleAlt', W_STYLES, 1, 1, false);
    setA('walk', W_STYLES, 2, 0);
    setA('run', W_STYLES, 2, 1);
    // Native SM_STAND / SM_MOVE rows supply class-specific underwater motion.
    setA('swimIdle', W_STYLES, 26, 0, false);
    setA('swimIdleCombat', W_STYLES, 26, 1, false);
    setA('swimWalk', W_STYLES, 28, 0, false);
    setA('swimRun', W_STYLES, 28, 1, false);
    setA('die', [style, 0, 1], 8, 0);
    setA('dieAlt', [style, 0, 1], 8, 1, false);
    setA('revive', [style, 0, 1], 11, 0, false);
    setA('knockdown', [style, 0, 1], 38, 0, false);
    setA('stun', [style, 0, 1], 41, 0, false);
    setA('sleep', [style, 0, 1], 43, 0, false);
    setA('block', W_STYLES, 12, 0, false);
    setA('guard', W_STYLES, 14, 0, false);
    setA('createPose', [0], 1, 2, false);
    // sitting: emotion start/keep/end (46/47/48) if present, else the emote motions 12/14/13
    if (findRec([0], 46, 0)) { setA('sitDown', [0], 46, 0); setA('sit', [0], 47, 0); setA('standUp', [0], 48, 0); }
    else { setA('sitDown', [0], 15, 12, false); setA('sit', [0], 15, 14, false); setA('standUp', [0], 15, 13, false); }
    const listOf = (action, styles) => {
      for (const s of styles) {
        const rs = recs.filter(r => r.style === s && r.action === action).sort((a, b) => a.index - b.index);
        const ok = rs.filter(r => r.anim && has(gamePathToData('anim', r.anim)));
        if (ok.length) {
          if (ok.length < rs.length) notes.push(`${ctx}: ${rs.length - ok.length} ${ACTION_NAMES[action]} anims of style ${s} missing on disk`);
          return ok.map(animRef);
        }
      }
      return [];
    };
    anims.attack = listOf(6, W_STYLES);
    anims.hit = listOf(7, W_STYLES);
    anims.blocked = listOf(13, W_STYLES);
    if (!anims.attack.length) problems.push(`${ctx}: no ATTACK animations`);
    if (!anims.hit.length) problems.push(`${ctx}: no DEFEAT (hit) animations`);
    const emotes = recs.filter(r => r.style === 0 && r.action === 15 && r.index < 100 && r.anim && has(gamePathToData('anim', r.anim)))
      .map(r => ({ index: r.index, anim: gamePathToData('anim', r.anim), timeLength: +r.timeLength.toFixed(3),
        name: r.anim.split('\\').pop().replace(/\.anim$/i, '').replace(/^[a-z]+_emt_/i, '').toLowerCase() }));
    anims.emotes = emotes;
    cls.anims = anims;
    // movement speed implied by the clips: root-motion displacement of one cycle (src/formats/anim.js
    // sampleRootMotion, FILE frame, forward = -Z) divided by the action-table timeLength
    const speedFromRootMotion = {};
    if (F.anim?.parseAnim && F.anim?.sampleRootMotion) {
      for (const nm of ['walkPeace', 'runPeace', 'walk', 'run']) {
        const a = anims[nm];
        if (!a) continue;
        try {
          const rm = F.anim.sampleRootMotion(F.anim.parseAnim(read(a.anim)), 1);
          a.rootMotion = rm.map(v => +v.toFixed(4));
          speedFromRootMotion[nm] = +(Math.hypot(rm[0], rm[2]) / a.timeLength).toFixed(3);
          if (!(rm[2] < 0)) problems.push(`${ctx}: ${nm} root motion ${rm} does not move forward (-Z)`);
        } catch (e) { notes.push(`${ctx}: root motion of ${a.anim} unavailable (${e.message})`); }
      }
    } else notes.push(`${ctx}: src/formats/anim.js not available - speedFromRootMotion skipped`);
    // basic attack combo timing (share/combo/combo.csv) for the chosen style
    cls.combo = combos.get(`${i}:${style}`) || combos.get(`${i}:1`) || [];
    if (!combos.has(`${i}:${style}`)) notes.push(`${ctx}: combo.csv has no entry for style ${style}`);

    // ---- stats & growth (share/pc/pcclass.csv)
    const raw = {};
    for (const k of Object.keys(pc)) {
      if (k === 'Class' || k === 'name_eng' || k === 'name_kor') continue;
      const v = pc[k][i];
      raw[k] = isNum(v) ? Number(v) : v;
    }
    const base = { str: raw.STR_DEF, dex: raw.DEX_DEF, con: raw.CON_DEF, spr: raw.SPR_DEF };
    const growth = {
      hpBase: raw.HP_DEF, mpBase: raw.MP_DEF, hpPerLevel: raw.HP_UP, mpPerLevel: raw.MP_UP,
      hpPerCon: raw.HP_UP_PER_CON, mpPerSpr: raw.MP_UP_PER_SPR, statPointsPerLevel: formula.byStatPointPerLevel ?? 5,
      hpRegenPerSec: raw.HP_RPS, mpRegenPerSec: raw.MP_RPS,
    };
    const hpAt = (lv, con) => growth.hpBase + growth.hpPerLevel * lv + growth.hpPerCon * con;
    const mpAt = (lv, spr) => growth.mpBase + growth.mpPerLevel * lv + growth.mpPerSpr * spr;
    cls.stats = {
      base, moveSpeed: raw.Speed_WALK, speedFromRootMotion, attackDistance: raw.Distance,
      damageRatios: {
        strMelee: raw.STR_MELEEDAMAGE_RATIO, levelMelee: raw.LEVEL_MELEEDAMAGE_RATIO,
        dexRange: raw.DEX_RANGEDAMAGE_RATIO, levelRange: raw.LEVEL_RANGEDAMAGE_RATIO,
        sprMagic: raw.SPR_MAGICDAMAGE_RATIO, levelMagic: raw.LEVEL_MAGICDAMAGE_RATIO,
        levelDefense: raw.LEVEL_DEFENSE_RATIO, conDefense: raw.CON_DEFENSE_RATIO,
      },
      guardRate: raw.GUARD_RATE, guardEfficiency: raw.GUARD_EFFICIENCY, defeatRateMin: raw.DEFEATRATE_MIN, defeatRateMax: raw.DEFEATRATE_MAX,
      raw,
    };
    cls.growth = growth;
    cls.level1 = { level: 1, ...base, hp: hpAt(1, base.con), mp: mpAt(1, base.spr), formula: 'hp = HP_DEF + HP_UP*level + HP_UP_PER_CON*CON; mp = MP_DEF + MP_UP*level + MP_UP_PER_SPR*SPR (inferred, not in data)' };

    // ---- skills
    cls.skills = [];
    const flagSkills = W.skillFlag ? (skillsByFlag.get(W.skillFlag) || []) : [];
    let desc = new Map();
    const descKey = [...FILES.keys()].find(k => k === `script/skilldesc/${W.skillDesc}.csv`);
    if (descKey) {
      for (const r of csvObjects(read(descKey), true).rows) {
        const idx = num(r.Index);
        if (idx === null) continue;
        if (!desc.has(idx)) desc.set(idx, { name: r.Name, weapon: r.Weapon, description: (r.Description || '').replace(/<\/?color[^>]*>/gi, '').replace(/\s*\\+\s*/g, ' ').replace(/\s{2,}/g, ' ').trim(), iconIndex: num(r.IconIndex) });
      }
    }
    const skillRecs = new Map();
    for (const r of recs) if (r.action === 10) skillRecs.set(`${r.style}:${r.index}`, r);
    // Style 255 = the current weapon style. A literal style (0 in ~1% of combo rows and in most Ready* actions) is
    // tried first and falls back to the weapon style when the class has no SKILL record there.
    const resolveSkillAnim = (st, ai) => {
      for (const s of st === 255 ? [style] : [st, style]) {
        const r = skillRecs.get(`${s}:${ai}`);
        if (r && r.anim && has(gamePathToData('anim', r.anim))) return r;
      }
      return null;
    };
    const buildLevel = (sk, lv) => {
      const s = num(lv.StartComboIndex), e = num(lv.EndComboIndex);
      const steps = sk.combos.filter(c => num(c.ComboIndex) >= s && num(c.ComboIndex) <= e).map(c => {
        const st = num(c.Style), ai = num(c.ActionIndex);
        const r = resolveSkillAnim(st, ai);
        const step = {
          combo: num(c.ComboIndex), type: c.ActionType, style: st, actionIndex: ai, durationMs: num(c.TimeTick),
          anim: r ? animRef(r) : null,
        };
        const eff = effectRef(num(c.EffectID), num(c.SceneID), num(c.EffectTime));
        if (eff) step.effect = eff;
        if (c.ResultCode && c.ResultCode !== '0') {
          const args = [1, 2, 3, 4, 5, 6, 7, 8].map(k => num(c[`Arg${k}`]) || 0);
          step.result = describeResult(c.ResultCode, args, resultCtx);
          step.result.pvpDamageRate = num(c.PCDamageRate);
          step.result.aggro = num(c.AggroCode);
          if (num(c.Defeat)) step.result.defeat = num(c.Defeat);
          const reff = effectRef(num(c.ResultEffectID), num(c.ResultSceneID), num(c.ResultEffectTime));
          if (reff) step.result.hitEffect = reff;
          if (step.result.remoteMissing) problems.push(`${ctx}: skill ${sk.kv.Index} references remote ${step.result.remoteIndex} not in remote.csv`);
          if (step.result.statusMissing) problems.push(`${ctx}: skill ${sk.kv.Index} references status ${step.result.statusIndex} not in status.csv`);
        }
        return step;
      });
      return {
        level: num(lv.LevelIndex), reqLevel: num(lv.PCLevel), spCost: num(lv.SPCostLevelUp), mp: num(lv.ResourceMP), hp: num(lv.ResourceHP),
        castMs: num(lv.CastTick), cooldownMs: num(lv.CoolTick),
        prereq: num(lv.Index) ? { skillIndex: num(lv.Index), level: num(lv.Level) } : null,
        steps,
      };
    };
    const candSkills = [];
    for (const sk of flagSkills) {
      if (sk.kv.TypeFlag !== 'ACTION') continue;
      const idx = num(sk.kv.Index);
      const d = desc.get(idx);
      if (!d || !d.name) continue;
      // level rows with PCLevel 0 / '-' are unused placeholders (e.g. Critical Isis levels 11..15 beyond BTypeMaxLevel 10)
      const lvs = sk.levels.filter(l => num(l.LevelIndex) >= 1 && num(l.PCLevel) >= 1 &&
        sk.combos.some(cb => num(cb.ComboIndex) >= num(l.StartComboIndex) && num(cb.ComboIndex) <= num(l.EndComboIndex)));
      if (!lvs.length) continue;
      const allowed = weaponReqCodes(d.weapon);
      if (allowed && weapon && !allowed.has(weapon.code)) continue;
      const l1 = buildLevel(sk, lvs[0]);
      if (!l1.steps.length || l1.steps.some(s => !s.anim)) continue;
      if (!l1.steps.some(s => s.result)) continue;
      candSkills.push({ sk, idx, d, lvs, l1 });
    }
    candSkills.sort((a, b) => a.l1.reqLevel - b.l1.reqLevel || a.idx - b.idx);
    const known = new Set(candSkills.map(c => c.idx));
    const chosen = [];
    for (const c of candSkills) {
      if (chosen.length >= 6) break;
      // keep skills whose prerequisite is either none or another available skill of this class
      if (c.l1.prereq && !known.has(c.l1.prereq.skillIndex) && c.l1.prereq.skillIndex !== c.idx) {
        const pre = flagSkills.find(s => num(s.kv.Index) === c.l1.prereq.skillIndex);
        if (pre && pre.kv.TypeFlag === 'ACTION') continue; // prerequisite is an active skill we could not use
      }
      chosen.push(c);
    }
    for (const c of chosen) {
      const { sk, idx, d, lvs, l1 } = c;
      const results = l1.steps.filter(s => s.result).map(s => s.result);
      const main = results.find(r => r.kind === 'damage' || r.kind === 'projectile') || results[0];
      // damage kind from the last two digits of the damage code (a projectile uses its remote.csv ResultType):
      // 01/02 = melee (every melee class), 03 = ranged (arrows), others = elemental/magic; bow skills stay 'range'.
      const dmgType = (code) => {
        const s = String(code || '').slice(-2);
        if (s === '01' || s === '02') return 'melee';
        if (s === '03' || W.code === 'ARC' || W.code === 'SHT') return 'range';
        return 'magic';
      };
      const ktype = (r) => {
        if (!r) return 'other';
        if (r.kind === 'damage') return dmgType(r.resultCode);
        if (r.kind === 'projectile') return dmgType(remotes.get(r.remoteIndex)?.resultType);
        return r.kind;
      };
      const skill = {
        index: idx, name: d.name.trim(), nameKor: sk.kv.Name, file: sk.file, weaponReq: d.weapon, description: d.description,
        type: ktype(main), typeFlag: sk.kv.TypeFlag, target: String(sk.kv.Target || '').split(/\s+/).filter(Boolean).map(Number),
        range: num(sk.kv.Distance), iconIndex: num(sk.kv.IconIndex), iconTab: num(sk.kv.IconTabIndex),
        iconPos: [num(sk.kv.IconPosX), num(sk.kv.IconPosY)], maxLevel: num(sk.kv.NormalMaxLevel) ?? num(sk.kv.MaxLevel),
        maxLevelA: num(sk.kv.ATypeMaxLevel), maxLevelB: num(sk.kv.BTypeMaxLevel),
        reqLevel: l1.reqLevel, mpCost: l1.mp, hpCost: l1.hp, cooldownMs: l1.cooldownMs, castMs: l1.castMs, prereq: l1.prereq,
        hits: results.filter(r => r.kind === 'damage' || r.kind === 'projectile').length,
        addDamage: results.filter(r => r.addDamage !== undefined).reduce((s, r) => s + (r.addDamage || 0), 0),
        ready: (num(sk.kv.ReadyActionIndex) || num(sk.kv.ReadyEffectID)) ? {
          style: num(sk.kv.ReadyActionStyle), actionIndex: num(sk.kv.ReadyActionIndex), durationMs: num(sk.kv.ReadyActionTimeTick),
          effect: effectRef(num(sk.kv.ReadyEffectID), num(sk.kv.ReadySceneID), num(sk.kv.ReadyEffectTime)),
          anim: (() => { const r = resolveSkillAnim(num(sk.kv.ReadyActionStyle) ?? 255, num(sk.kv.ReadyActionIndex)); return r ? animRef(r) : null; })(),
        } : null,
        steps: l1.steps,
        levels: lvs.map(l => {
          const b = buildLevel(sk, l);
          const rs = b.steps.filter(s => s.result).map(s => s.result);
          return {
            level: b.level, reqLevel: b.reqLevel, spCost: b.spCost, mp: b.mp, hp: b.hp, cooldownMs: b.cooldownMs, castMs: b.castMs,
            addDamage: rs.map(r => r.addDamage ?? r.amount ?? null),
            ...(rs.some(r => r.statusIndex) ? { statusIndex: rs.map(r => r.statusIndex ?? null), durationMs: rs.map(r => r.durationMs ?? r.statusDurationMs ?? null) } : {}),
            ...(rs.some(r => r.remoteIndex) ? { remoteIndex: rs.map(r => r.remoteIndex ?? null) } : {}),
            ...(b.steps.some(s => s.anim?.anim !== l1.steps.find(x => x.actionIndex === s.actionIndex)?.anim?.anim) ? { steps: b.steps } : {}),
          };
        }),
      };
      cls.skills.push(skill);
    }
    if (W.classic && cls.skills.length < 6) problems.push(`${ctx}: only ${cls.skills.length} usable early skills`);
    if (!W.skillFlag) notes.push(`${ctx}: no share/skill/*.csv with a PCClassFlag for this class (its skills are only in binary tables) - no skills emitted`);

    // skills: the legacy CSVs, or the full binary skill tables (gamedata/skills/index.json, tools/build-skills-runtime.mjs)
    // that the skills system runs for every class (Segita Shooter / Alokes / Trie Muse have no CSVs)
    const packSkills = (() => { try { const file = process.env.DEKARON_GAMEDATA ? path.join(process.env.DEKARON_GAMEDATA, 'skills/index.json') : fileURLToPath(new URL('../gamedata/skills/index.json', import.meta.url)); return JSON.parse(fs.readFileSync(file, 'utf8')).classes.find(x => x.index === cls.index)?.skills || 0; } catch { return 0; } })();
    cls.playable = !!(cls.skeleton && has(cls.skeleton) && cls.parts.length === 5 && weapon && anims.idle && anims.run && anims.attack.length && (cls.skills.length || packSkills));
    classes.push(cls);
    log(`${ctx}: ${cls.name} skel=${cls.skeleton} style=${style} weapon=${weapon?.name || weapon?.mesh} skills=${cls.skills.map(s => s.name).join(', ')}`);
  }

  // ---- remotes (projectiles) / statuses referenced by emitted skills -> top-level dictionaries
  const usedRemotes = {}, usedStatuses = {};
  const walk = (o) => {
    if (Array.isArray(o)) { o.forEach(walk); return; }
    if (!o || typeof o !== 'object') return;
    const addR = (k) => {
      if (!k || usedRemotes[k] || !remotes.has(k)) return;
      const rm = { ...remotes.get(k) };
      const pe = effectRef(rm.effectId, rm.sceneId, rm.effectTimeMs); if (pe) rm.effect = pe;
      const ce = effectRef(rm.contactEffectId, rm.contactSceneId, rm.contactEffectTimeMs); if (ce) rm.contactEffect = ce;
      usedRemotes[k] = rm;
    };
    const addS = (k) => { if (k && !usedStatuses[k] && statuses.has(k)) usedStatuses[k] = statuses.get(k); };
    if (typeof o.remoteIndex === 'number') addR(o.remoteIndex);
    if (Array.isArray(o.remoteIndex)) o.remoteIndex.forEach(addR);
    if (typeof o.statusIndex === 'number') addS(o.statusIndex);
    if (Array.isArray(o.statusIndex)) o.statusIndex.forEach(addS);
    for (const v of Object.values(o)) if (v && typeof v === 'object') walk(v);
  };
  walk(classes.map(c => c.skills));

  // ---- start locations (share/pc/startpoint.csv -> share/arrange/location.csv)
  const locRows = parseCSV(readText('share/arrange/location.csv'));
  const loc = new Map();
  // Pos_X/Pos_Y = integer cell of FILE-frame X/Z (stand at the cell centre, docs/formats/coords.md); Direction = byte angle (256 = full turn)
  for (const r of locRows.slice(1)) if (isNum(r[0])) loc.set(Number(r[0]), { location: Number(r[0]), name: String(r[1]).trim(), mapIndex: num(r[2]), x: num(r[3]), y: num(r[4]), direction: num(r[5]), directionDeg: (num(r[5]) || 0) * 360 / 256 });
  const startLocations = csvObjects(read('share/pc/startpoint.csv')).rows.map(r => ({
    index: num(r.Index), start: loc.get(num(r.Location_Index)) || null, respawn: loc.get(num(r.Retun_Index)) || null,
  }));

  // ---- exp table
  const expRows = parseCSV(readText('share/pc/exp.csv'));
  const expHdr = expRows[0].map(x => String(x).trim());
  // exp.csv splits the 64-bit requirement into two decimal halves: Exp = low 9 digits, EndExp = the billions
  // (level 156 needs 868,705,560, level 157 has Exp 15,574,918 + EndExp 1 = 1,015,574,918; the per-level growth
  // ratio stays ~1.17 only with base 1e9 - 2^32 or 1e10 would give x5 / x11 jumps). Levels 1..156 have EndExp 0.
  const EXP_HIGH_BASE = 1e9;
  const levels = [];
  let cum = 0;
  for (const r of expRows.slice(1)) {
    if (!isNum(r[0])) continue;
    const o = { level: Number(r[0]) };
    expHdr.forEach((h, k) => { if (k > 0 && h) o[h.charAt(0).toLowerCase() + h.slice(1)] = num(r[k]); });
    o.expLow = o.exp;
    o.exp = (o.endExp || 0) * EXP_HIGH_BASE + (o.exp || 0);
    o.toNext = o.exp; o.totalAtLevel = cum; cum += o.exp || 0;
    levels.push(o);
  }
  const levelDiff = csvObjects(read('share/pc/levelcap.csv')).rows.map(r => ({
    index: num(r.Index), diffFrom: num(r['Level Cap Start']), diffTo: num(r['Level Cap End']), expRate: num(r['Exp Rate']),
    chaoticRate: num(r['Chaotic Rate']), blocking: num(r.BLOCKING), blocked: num(r.BLOCKED), color: [num(r.Color_R), num(r.Color_G), num(r.Color_B)],
  }));
  const addExp = csvObjects(read('share/pc/addexp.csv')).rows.map(r => ({ minLevel: num(r.MINLEVEL), maxLevel: num(r.MAXLEVEL), addRate: num(r.ADDRATE),
    disallowedMaps: String(r.DISALLOWEDMAP || '').split('/').map(s => s.trim()).filter(isNum).map(Number) }));

  const statMax = csvObjects(read('share/pc/statmaxvalue.csv'), true).rows.map(r => ({ index: num(r.Index), equipMax: num(r.EquipMaxValue), skillMax: num(r.SkillMaxValue) }));

  const classesJson = {
    version: 1,
    generatedBy: 'tools/build-characters.mjs',
    generatedAt: new Date().toISOString(),
    paths: 'All asset paths are data-root-relative keys (lower case, "/" separators): fetch as /data/<key>.',
    conventions: {
      assembly: 'A character = skeleton + 5 skinned body parts (helmet=head/face/hair, coat, pants, glove, boots) all bound to the same skeleton. Equipping armour replaces the part mesh of that slot. The weapon is a rigid mesh parented to the bone given in weapon.bone (battle stance) or weapon.bonePeace (peace stance).',
      textures: 'parts[].textures[k] belongs to material/subset k of the mesh; diffuse from tpack slot "k", specular from "sk".',
      styles: 'Animation "style" = weapon stance. style 0 = weapon-independent (peace idle/walk/run, emotes, death); class.style = stance of the starter weapon. Skill steps with style 255 use the current weapon style.',
      timings: 'anims[*].timeLength is the playback length in seconds the client stretches the clip to; timing/timing2 are fractions of timeLength (hit frame / combo-continue window); out-of-range source values are repaired (timingRaw/timingFix keep the original). Skill steps: play steps[k].anim over steps[k].durationMs (TimeTick) - SKILL-record timeLengths are unreliable (1 for most, ~TimeTick/30 for the Half Bagi).',
      handedness: 'Skeleton, meshes and animations are DirectX left-handed FILE-frame data (Y up, models face -Z, left hand at +X). The engine keeps them raw under the worldRoot mirror (scale.z = -1, docs/ARCHITECTURE.md); the alternative is to convert everything with the Z-mirror rule of docs/formats/skel.md / mesh.md. Never mix the two. The weapon mesh goes under its bone node in the same frame as the body; no extra flip.',
      weaponAttach: 'Weapon meshes are rigid and stored in the attach bone\'s local frame: vertex * boneModelMatrix (row vectors, FILE frame; the animated model matrix from anim.js sampleAnim().model, or bindMatrix at bind pose). Battle stance = weapon.bone (+ boneLeft for weapon.hand "both"), peace stance (style-0 clips) = weapon.bonePeace (+ bonePeaceLeft). The Black Wizard peace clips move the orb bone BAL_R ~340 units away, which hides the orb.',
      skillDistances: 'Radius arguments in skill tables are stored x128 (512 = 4 m, 1792 = 14 m); every result.radius in this file is already divided by 128 (world units: 1 unit = 1 map cell = ~1 m). Skill Distance, remote.csv MaxDistance and pcclass Distance are plain world units.',
      startLocation: 'startLocations[].start / respawn: x, y = integer map cell (FILE-frame X, Z); stand at the cell centre (x+0.5, y+0.5) as docs/formats/coords.md does for integer coordinates (src/game/data.js startFor). direction = byte angle, directionDeg = direction*360/256. Under the engine worldRoot mirror (docs/ARCHITECTURE.md, FILE frame): position (x+0.5, groundHeight, y+0.5), rotation.y = +directionDeg*PI/180. With converted (Z-negated) data instead: position (x+0.5, h, -(y+0.5)), rotation.y = -directionDeg*PI/180.',
      movement: 'stats.speedFromRootMotion[walk|run|walkPeace|runPeace] = root-motion distance of one clip cycle / timeLength (m/s). Moving at that speed while playing the clip at its timeLength keeps the feet planted (monster table speeds obey the same relation, median ratio 1.00). pcclass Speed_WALK (2.5, all classes) is kept as stats.moveSpeed (cells/s like the monster speeds, docs/formats/monsters.md); it is slower than the run clips, so an engine that moves the player at moveSpeed should play the run clip at rate moveSpeed / speedFromRootMotion.run.',
    },
    actionNames: ACTION_NAMES,
    styleNames: STYLE_NAMES,
    weaponCodes: Object.fromEntries(Object.entries(WEAPON_CODES).map(([k, v]) => [k, { name: v.name, weaponType: 1024 + Number(k), styles: v.styles }])),
    formula,
    maxLevel: formula.wMaxLevel ?? 250,
    statPointsPerLevel: formula.byStatPointPerLevel ?? 5,
    statMax,
    startLocations,
    defaultStart: startLocations[0]?.start || null,
    remotes: usedRemotes,
    statuses: usedStatuses,
    classes,
  };
  const expJson = {
    version: 1, generatedBy: 'tools/build-characters.mjs', source: 'share/pc/exp.csv',
    notes: 'levels[n].exp = experience needed to go from level n to n+1 = EndExp*1e9 + Exp (exp.csv stores the 64-bit value as two decimal halves; expLow/endExp keep the raw columns). totalAtLevel = cumulative exp at the start of level n (exceeds 2^53 from level 247 on, so those totals are approximate doubles; per-level exp values stay exact). levelDifference = share/pc/levelcap.csv (monster level minus player level -> exp %). addExp = share/pc/addexp.csv bands (ADDRATE % by player level).',
    maxLevel: formula.wMaxLevel ?? 250,
    levels, levelDifference: levelDiff, addExp,
  };
  return { classesJson, expJson, problems, notes, stats: { files: FILES.size, skillFilesParsed, ms: Date.now() - t0 }, has };
}

// ---------------------------------------------------------------------------------------------------------------
// Visual check (--png): bind-pose contact sheet of every class (5 default parts + starter weapon on its bone)
// ---------------------------------------------------------------------------------------------------------------

export async function renderBindPoseSheet({ classes, read, has, F, outPath, cellW = 200, cellH = 320, cols = 5, sideView = false }) {
  const png = await import(new URL('./png.mjs', import.meta.url));
  if (!F.mesh?.parseMesh || !F.skel?.parseSkel || !F.dds?.parseDDS) return 'skipped (mesh/skel/dds module missing)';
  const CW = cellW, CH = cellH, GAP = 10, VIEWS = sideView ? 3 : 2, COLS = Math.min(cols, classes.length);
  const rowsN = Math.ceil(classes.length / COLS);
  const W = COLS * (CW * VIEWS + GAP), H = rowsN * (CH + GAP);
  const img = new Uint8Array(W * H * 4);
  for (let i = 0; i < W * H; i++) { img[i * 4] = 38; img[i * 4 + 1] = 40; img[i * 4 + 2] = 48; img[i * 4 + 3] = 255; }
  const texCache = new Map();
  const getTex = (key) => {
    if (!key || !has(key)) return null;
    if (!texCache.has(key)) {
      let t = null;
      try { t = F.dds.decodeToRGBA(F.dds.parseDDS(read(key)), 0); } catch { t = null; }
      texCache.set(key, t);
    }
    return texCache.get(key);
  };
  const xf = (m, x, y, z) => [x * m[0] + y * m[4] + z * m[8] + m[12], x * m[1] + y * m[5] + z * m[9] + m[13], x * m[2] + y * m[6] + z * m[10] + m[14]];
  classes.forEach((c, ci) => {
    const tris = [];
    let minY = Infinity, maxY = -Infinity, minX = Infinity, maxX = -Infinity;
    const addMesh = (key, textures, matrix, tint) => {
      let m;
      try { m = F.mesh.parseMesh(read(key)); } catch { return; }
      for (const s of m.meshes) {
        const tex = getTex((textures || []).find(t => t.material === s.material)?.diffuse);
        const P = s.positions, U = s.uv0, I = s.indices;
        const pt = (k) => (matrix ? xf(matrix, P[k * 3], P[k * 3 + 1], P[k * 3 + 2]) : [P[k * 3], P[k * 3 + 1], P[k * 3 + 2]]);
        for (let t = 0; t + 2 < I.length; t += 3) {
          const ps = [pt(I[t]), pt(I[t + 1]), pt(I[t + 2])];
          const uv = [I[t], I[t + 1], I[t + 2]].map(k => [U[k * 2], U[k * 2 + 1]]);
          tris.push({ ps, uv, tex, tint });
          if (!matrix) for (const p of ps) { minY = Math.min(minY, p[1]); maxY = Math.max(maxY, p[1]); minX = Math.min(minX, p[0]); maxX = Math.max(maxX, p[0]); }
        }
      }
    };
    for (const p of c.parts) addMesh(p.mesh, p.textures, null, null);
    let skel = null;
    try { skel = F.skel.parseSkel(read(c.skeleton), { computeMatrices: true }); } catch { skel = null; }
    if (c.weapon && skel) {
      const bi = F.skel.findBone(skel, c.weapon.bone);
      if (bi >= 0) addMesh(c.weapon.mesh, c.weapon.textures, skel.bones[bi].bindMatrix, [255, 230, 120]);
      if (c.weapon.leftMesh && c.weapon.boneLeft) {
        const bl = F.skel.findBone(skel, c.weapon.boneLeft);
        if (bl >= 0) addMesh(c.weapon.leftMesh, c.weapon.textures, skel.bones[bl].bindMatrix, [255, 230, 120]);
      }
    }
    if (!tris.length) return;
    const span = Math.max(maxY - minY, (maxX - minX) * (CH / CW)) * 1.08;
    const sc = (CH - 8) / span;
    const cx = (minX + maxX) / 2, cy = (minY + maxY) / 2;
    for (let v = 0; v < VIEWS; v++) {
      const ox = (ci % COLS) * (CW * VIEWS + GAP) + v * CW, oy = Math.floor(ci / COLS) * (CH + GAP);
      const zbuf = new Float32Array(CW * CH).fill(Infinity);
      const sx = v === 0 ? 1 : -1; // view 0: camera on -Z looking +Z (file frame); view 1: camera on +Z looking -Z
      // view 2 (optional): camera on -X looking +X (left-handed: screen-right = -Z, so the model faces right)
      const proj = v === 2 ? (p) => [CW / 2 - p[2] * sc, CH / 2 - (p[1] - cy) * sc, p[0]]
        : (p) => [CW / 2 + sx * (p[0] - cx) * sc, CH / 2 - (p[1] - cy) * sc, sx * p[2]];
      for (const tr of tris) {
        const [a, b, d] = tr.ps.map(proj);
        const x0 = Math.max(0, Math.floor(Math.min(a[0], b[0], d[0]))), x1 = Math.min(CW - 1, Math.ceil(Math.max(a[0], b[0], d[0])));
        const y0 = Math.max(0, Math.floor(Math.min(a[1], b[1], d[1]))), y1 = Math.min(CH - 1, Math.ceil(Math.max(a[1], b[1], d[1])));
        const area = (b[0] - a[0]) * (d[1] - a[1]) - (b[1] - a[1]) * (d[0] - a[0]);
        if (!area) continue;
        const e1 = [tr.ps[1][0] - tr.ps[0][0], tr.ps[1][1] - tr.ps[0][1], tr.ps[1][2] - tr.ps[0][2]];
        const e2 = [tr.ps[2][0] - tr.ps[0][0], tr.ps[2][1] - tr.ps[0][1], tr.ps[2][2] - tr.ps[0][2]];
        const n = [e1[1] * e2[2] - e1[2] * e2[1], e1[2] * e2[0] - e1[0] * e2[2], e1[0] * e2[1] - e1[1] * e2[0]];
        const nl = Math.hypot(n[0], n[1], n[2]) || 1;
        const shade = 0.55 + 0.45 * Math.min(1, Math.abs((n[2] * 0.8 + n[1] * 0.6) / nl));
        for (let y = y0; y <= y1; y++) for (let x = x0; x <= x1; x++) {
          const px = x + 0.5, py = y + 0.5;
          const w1 = ((px - a[0]) * (d[1] - a[1]) - (py - a[1]) * (d[0] - a[0])) / area;
          const w2 = ((b[0] - a[0]) * (py - a[1]) - (b[1] - a[1]) * (px - a[0])) / area;
          const w0 = 1 - w1 - w2;
          if (w0 < 0 || w1 < 0 || w2 < 0) continue;
          const z = w0 * a[2] + w1 * b[2] + w2 * d[2];
          const zi = y * CW + x;
          if (z >= zbuf[zi]) continue;
          let col = tr.tint || [200, 200, 200], alpha = 255;
          if (tr.tex) {
            let u = w0 * tr.uv[0][0] + w1 * tr.uv[1][0] + w2 * tr.uv[2][0];
            let vv = w0 * tr.uv[0][1] + w1 * tr.uv[1][1] + w2 * tr.uv[2][1];
            u -= Math.floor(u); vv -= Math.floor(vv);
            const tx = Math.min(tr.tex.width - 1, Math.floor(u * tr.tex.width)), ty = Math.min(tr.tex.height - 1, Math.floor(vv * tr.tex.height));
            const o = (ty * tr.tex.width + tx) * 4;
            col = [tr.tex.data[o], tr.tex.data[o + 1], tr.tex.data[o + 2]]; alpha = tr.tex.data[o + 3];
          }
          if (alpha < 60) continue;
          zbuf[zi] = z;
          const o = ((oy + y) * W + ox + x) * 4;
          img[o] = Math.min(255, col[0] * shade); img[o + 1] = Math.min(255, col[1] * shade); img[o + 2] = Math.min(255, col[2] * shade);
        }
      }
      if (skel) for (const b of skel.bones) {
        if (!b.bindMatrix) continue;
        const [x, y] = proj([b.bindMatrix[12], b.bindMatrix[13], b.bindMatrix[14]]);
        const isW = b.name === c.weapon?.bone;
        for (let dy = -1; dy <= 1; dy++) for (let dx = -1; dx <= 1; dx++) {
          const X = Math.round(x) + dx, Y = Math.round(y) + dy;
          if (X < 0 || Y < 0 || X >= CW || Y >= CH) continue;
          const o = ((oy + Y) * W + ox + X) * 4;
          img[o] = 255; img[o + 1] = isW ? 255 : 40; img[o + 2] = isW ? 0 : 40;
        }
      }
    }
  });
  png.writePNG(outPath, W, H, img);
  return `${outPath} (${W}x${H}, ${classes.length} classes in index order, ${COLS} per row; views: from -Z (front), from +Z (back)${sideView ? ', from -X (side, facing right)' : ''})`;
}

// ---------------------------------------------------------------------------------------------------------------
// CLI
// ---------------------------------------------------------------------------------------------------------------

function collectPaths(obj, out = []) {
  if (Array.isArray(obj)) { obj.forEach(x => collectPaths(x, out)); return out; }
  if (obj && typeof obj === 'object') { for (const v of Object.values(obj)) collectPaths(v, out); return out; }
  if (typeof obj === 'string' && /^(anim|mesh|skel|texture|texturepack|share|script|property)\/.+\.[a-z0-9]+$/.test(obj)) out.push(obj);
  return out;
}

async function main() {
  const HERE = path.dirname(fileURLToPath(import.meta.url));
  const ENGINE = path.resolve(HERE, '..');
  const argv = process.argv.slice(2);
  const arg = (k) => { const i = argv.indexOf(k); return i >= 0 ? argv[i + 1] : null; };
  const dataRoot = path.resolve(arg('--data') || process.env.DEKARON_DATA || path.join(ENGINE, '..', 'data', 'unpacked', 'data'));
  const outDir = path.resolve(arg('--out') || path.join(ENGINE, 'gamedata'));
  const verbose = argv.includes('--verbose');
  const formats = await loadFormatModules();
  const { classesJson, expJson, problems, notes, stats, has } = await build({ dataRoot, verbose, formats });

  // independent validation pass over the emitted JSON
  const paths = collectPaths(classesJson);
  const missing = [...new Set(paths.filter(p => !has(p)))];
  for (const p of missing) problems.push(`emitted path does not exist: ${p}`);
  for (const c of classesJson.classes) {
    const chk = (cond, msg) => { if (!cond) problems.push(`class ${c.index}: ${msg}`); };
    chk(Number.isFinite(c.level1.hp) && c.level1.hp > 0, 'level1 hp not positive');
    chk(Number.isFinite(c.level1.mp) && c.level1.mp > 0, 'level1 mp not positive');
    for (const a of c.anims.attack) chk(a.timeLength > 0 && a.timeLength < 10, `bad attack timeLength ${a.timeLength}`);
    for (const a of c.anims.attack) chk((a.timing ?? 0) <= 1 && (a.timing2 ?? 0) <= 1.0001, `attack timing ${a.timing}/${a.timing2} not a fraction`);
    // combo.csv (server-side basic-attack timing) must agree with the action file's ATTACK records
    const cmb = c.combo.length === c.anims.attack.length && c.combo.every((s, k) => Math.abs(s.timeLength - c.anims.attack[k].timeLength) < 0.011);
    if (!cmb) notes.push(`class ${c.index}: combo.csv steps (${c.combo.map(s => s.timeLength)}) differ from ATTACK anims (${c.anims.attack.map(a => a.timeLength)})`);
    for (const s of c.skills) {
      chk(s.reqLevel >= 0 && s.reqLevel <= 250, `skill ${s.index} reqLevel ${s.reqLevel}`);
      chk(s.cooldownMs >= 0 && s.mpCost >= 0, `skill ${s.index} negative cost`);
      chk(s.steps.every(st => st.anim && st.anim.anim), `skill ${s.index} step without animation`);
    }
  }
  // exp to the next level never decreases up to the level cap (catches the Exp/EndExp split being ignored)
  for (let q = 1; q < Math.min(expJson.maxLevel, expJson.levels.length); q++) {
    if (expJson.levels[q].exp < expJson.levels[q - 1].exp) { problems.push(`exp.json: level ${expJson.levels[q].level} needs less exp than level ${expJson.levels[q - 1].level}`); break; }
  }
  fs.mkdirSync(outDir, { recursive: true });
  fs.writeFileSync(path.join(outDir, 'classes.json'), JSON.stringify(classesJson, null, 1));
  fs.writeFileSync(path.join(outDir, 'exp.json'), JSON.stringify(expJson, null, 1));
  if (argv.includes('--png')) {
    const read = (k) => fs.readFileSync(path.join(dataRoot, k));
    const pngOut = path.resolve(arg('--png-out') || path.join(ENGINE, 'docs', 'formats', 'img', 'characters_bindpose.png'));
    fs.mkdirSync(path.dirname(pngOut), { recursive: true });
    console.log('png: ' + await renderBindPoseSheet({ classes: classesJson.classes, read, has, F: formats, outPath: pngOut, cellW: 160, cellH: 300, sideView: true }));
  }

  console.log(`data root: ${dataRoot}  (${stats.files} files indexed, ${stats.skillFilesParsed} skill tables, ${stats.ms} ms)`);
  console.log(`wrote ${path.join(outDir, 'classes.json')} (${classesJson.classes.length} classes) and exp.json (${expJson.levels.length} levels)`);
  console.log(`paths referenced: ${paths.length} (${new Set(paths).size} unique), missing: ${missing.length}`);
  for (const c of classesJson.classes) {
    console.log(`  [${String(c.index).padStart(2)}] ${String(c.name).padEnd(18)} ${c.playable ? 'PLAYABLE' : 'partial '} skel=${c.skeleton}  parts=${c.parts.length}  ` +
      `weapon=${c.weapon ? (c.weapon.name || c.weapon.mesh) : '-'} (${c.weapon?.type}, style ${c.style}, bone ${c.weapon?.bone})  ` +
      `atk=${c.anims.attack.length} hp/mp@1=${c.level1.hp}/${c.level1.mp}  skills=${c.skills.map(s => `${s.name}@${s.reqLevel}`).join(', ') || '-'}`);
  }
  const uniqNotes = [...new Set(notes)];
  if (uniqNotes.length) {
    console.log(`notes (${uniqNotes.length}):`);
    for (const n of uniqNotes.slice(0, 60)) console.log('  - ' + n);
    if (uniqNotes.length > 60) console.log(`  ... ${uniqNotes.length - 60} more`);
  }
  if (problems.length) {
    console.log(`PROBLEMS (${problems.length}):`);
    for (const p of problems.slice(0, 80)) console.log('  ! ' + p);
    process.exitCode = 1;
  } else console.log('OK: no problems');
}

if (import.meta.url === pathToFileURL(process.argv[1] || '').href) main();
