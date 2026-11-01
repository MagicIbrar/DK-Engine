#!/usr/bin/env node
// Dekaron Solo - skills + skill-effect data builder.
//
// Reads the user's own unpacked client data and writes
//   gamedata/skills.json          complete skill trees of all 15 classes (1,418 compiled skill tables), every level,
//                                 every combo step (animation, timing, effect ids, decoded result), requirements,
//                                 icons, tree placement, per-class SKILL animation tables, projectiles (remote.csv),
//                                 summons (servant.csv / totem.csv), trans-up transforms, meister/upgrade tables,
//                                 aggro codes (share/ai/aggroaccount.csv).
//   gamedata/skills_effects.json  the effect-scene library the skill system needs (cate 100 skill, 11 condition,
//                                 6 hit + everything statuses/skills/remotes/summons/combat+game events reference):
//                                 scenes -> controls -> units (sprite/particle/mesh/decal/sound/quake/meshstatus) with
//                                 every asset path resolved, modeleffect tables, floating damage-number animation.
//   gamedata/skills_status.json   every status (buff/debuff) of share/skill/status.csv with decoded option codes,
//                                 icons and the start/keep/end condition effects (script/effect/modeleffect.csv).
//
// Usage:  node tools/build-skills.mjs [--data <unpacked data root>] [--out <dir>] [--verbose] [--spot]
//   --spot   print 10 hand-checkable entries (raw bytes/CSV next to the emitted JSON)
// Exit code 1 when a referenced asset path is missing on disk, a cross reference does not resolve or a
// parser consistency check fails (every path in the JSON is a lower-case "/" data key: fetch /data/<key>,
// URL-encoding each segment because names contain '#').
//
// Format notes: docs/formats/skills.md (skill tables) and docs/formats/effects.md (effect system).
// The parsers below are pure functions (Buffer|Uint8Array|string in, plain objects out) and never touch the
// file system, so the engine can port them to the browser unchanged.

import fs from 'node:fs';
import { createHash } from 'node:crypto';
import path from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { parseCSV, decodeText } from '../src/formats/binreader.js';
import { parseActionDat } from '../src/formats/modeldef.js';
import { parseTpack, textureCandidates, buildTextureIndex } from '../src/formats/tpack.js';
import { supplementTransforms } from './transform-compatibility.mjs';
import { ESCANA_BACKUP_SOURCE, recoverEscanaUnit } from './effect-unit-recovery.mjs';
import { repairedEffectPath, repairedBoneAnimationPath, repairedActionAnimationPath } from '../src/game/effect-path-repairs.js';

// ---------------------------------------------------------------------------------------------------------------
// Paths
// ---------------------------------------------------------------------------------------------------------------

/** Game path -> data key: backslashes -> '/', lower case, no leading './' or '/'. */
export function normPath(p) {
  return String(p ?? '').trim().replace(/^"|"$/g, '').replace(/\\/g, '/').replace(/^(\.\/)+/, '').replace(/^\/+/, '').replace(/\/{2,}/g, '/').toLowerCase();
}
/** Game path relative to a type root ("Effect\\Skill\\x.mesh") -> data key ("mesh/effect/skill/x.mesh"). */
export function gamePathToData(root, p) {
  const n = normPath(p);
  if (!n) return null;
  const r = normPath(root).replace(/\/$/, '');
  return n.startsWith(r + '/') ? n : `${r}/${n}`;
}
const toU8 = (b) => (b instanceof Uint8Array ? b : new Uint8Array(b));
const toText = (src, korean = true) => (typeof src === 'string' ? src : decodeText(toU8(src), korean));

// ---------------------------------------------------------------------------------------------------------------
// Static knowledge (see docs/formats/skills.md for the evidence behind every table)
// ---------------------------------------------------------------------------------------------------------------

/**
 * Class wiring. `bit` = the PC class bit of skill tables (u16 at 12274, 1 << (15 - index), same bitmask order as the
 * 16-character `Job` strings of the item tables), `csvFlag` = PCClassFlag of the legacy share/skill/*.csv twins
 * (null: the class never had CSV twins), `desc` = script/skilldesc/<desc>.csv (English names), `act` = action file.
 */
export const SKILL_CLASSES = [
  { index: 0, code: 'SWD', csvFlag: 'SWD', desc: 'knight', act: 'swd.act.0.dat', prefix: 'K' },
  { index: 1, code: 'ARC', csvFlag: 'ARC', desc: 'hunter', act: 'arc.act.1.dat', prefix: 'A' },
  { index: 2, code: 'SOR', csvFlag: 'SOR', desc: 'magician', act: 'sor.act.2.dat', prefix: 'M' },
  { index: 3, code: 'SUM', csvFlag: 'SUM', desc: 'summoner', act: 'sum.act.3.dat', prefix: 'S' },
  { index: 4, code: 'HIL', csvFlag: 'SEG', desc: 'segnale', act: 'hil.act.4.dat', prefix: 'H' },
  { index: 5, code: 'WAR', csvFlag: 'WAR', desc: 'warrior', act: 'war.act.5.dat', prefix: 'B' },
  { index: 6, code: 'ALO', csvFlag: 'ALO', desc: 'aloken', act: 'alo.act.6.dat', prefix: 'L' },
  { index: 7, code: 'DRG', csvFlag: 'DRG', desc: 'dragonknight', act: 'drg.act.7.dat', prefix: 'K2' },
  { index: 8, code: 'SHT', csvFlag: null, desc: 'shooter', act: 'sht.act.8.dat', prefix: 'A2' },
  { index: 9, code: 'BWZ', csvFlag: 'BWZ', desc: 'wizard', act: 'bwz.act.9.dat', prefix: 'M2' },
  { index: 10, code: 'WSU', csvFlag: 'CON', desc: 'concerra', act: 'wsu.act.10.dat', prefix: 'S2' },
  { index: 11, code: 'MSE', csvFlag: 'RIP', desc: 'segeuriper', act: 'mse.act.11.dat', prefix: 'H2' },
  { index: 12, code: 'HWA', csvFlag: 'HWA', desc: 'halfbagi', act: 'hwa.act.12.dat', prefix: 'B2' },
  { index: 13, code: 'MAL', csvFlag: null, desc: 'aloken_m', act: 'malo.act.13.dat', prefix: 'LM' },
  { index: 14, code: 'TRI', csvFlag: 'TRI', desc: 'triemuse', act: 'tri.act.14.dat', prefix: 'MU' },
].map(c => ({ ...c, bit: 1 << (15 - c.index) }));
export const CLASS_BY_BIT = new Map(SKILL_CLASSES.map(c => [c.bit, c]));

/** Action-style enum (share/action/action/pc/*.act.N.dat records; docs/formats/characters.md section 4). */
export const STYLE_NAMES = {
  0: 'COMMON', 1: 'BAREHANDS', 2: 'SHORT_SWORD', 3: 'SWORD', 4: 'LONG_SWORD', 5: 'SPEAR', 6: 'POLEARM', 7: 'BOW',
  8: 'CROSS_BOW', 9: 'STAFF', 10: 'DUAL', 11: 'WAND', 12: 'MACE', 13: 'AX', 14: 'SHIELD', 15: 'SHIELD_SHORT_SWORD',
  16: 'SHIELD_SWORD', 17: 'SHIELD_MACE', 18: 'SHIELD_AX', 19: 'GREAT_MACE', 20: 'GREAT_AX', 21: 'TWIN_SWORD',
  22: 'BLOODWHIP', 23: 'FISHING_ROD', 24: 'GAUNTLET', 25: 'ALOKEN_SPEAR', 26: 'GUARDARM', 27: 'GUARDARM_SPEAR',
  28: 'GUARDARM_SHORT_SWORD', 29: 'DUALBLADE', 30: 'SCYTHE', 31: 'ORB', 32: 'GREAT_FALCHION', 33: 'KATAR',
  34: 'SEALFORCE', 35: 'GUN', 36: 'CANNON', 37: 'LILY', 38: 'CLOCHE', 39: 'RAPIER', 40: 'WINSWORD', 255: 'CURRENT',
};
/** Combo-row ActionType (u8 at +60 of a combo record; CSV words). */
export const COMBO_ACTION_TYPES = { 0: 'NONE', 1: 'ACTION', 2: 'NO_CANCEL' };
/** Skill TypeFlag bitmask (u32 at 12268). CSV words: ACTION, MASTERY, PASSIVE, "ACTION NOTSAVE"; CAST/POWERUP compile to ACTION. */
export const TYPE_BITS = { 1: 'PASSIVE', 2: 'MASTERY', 4: 'NOTSAVE', 16: 'ACTION' };
/** Skill Target bitmask (u32 at 12261; the CSV lists the set bits, e.g. "1 4" = 5). Meanings inferred from usage. */
export const TARGET_BITS = {
  1: 'AREA (also hits units around the target)', 2: 'ALLY (party member / friendly)', 4: 'ENEMY', 8: 'ANY (8 = rare, all 3 skills also list 1/2)',
  16: 'SELF', 32: 'CORPSE/DEAD ALLY (revive skills)', 64: 'OWN SUMMON (Recall)',
};
/** Skill points vs attribute points (u32 at 12290, absent in 16 older 12,290-byte tables = 1). */
export const POINT_TYPES = { 1: 'skill', 2: 'attribute' };
/** Effect-scene categories ("<cate> N name" blocks of property/effect/effectscene.*.txt). */
export const EFFECT_CATEGORIES = { 0: 'none', 1: 'monster', 3: 'sound', 4: 'game_sound', 5: 'game', 6: 'hit', 7: 'item', 8: 'ui', 9: 'light', 10: 'weather', 11: 'condition', 12: 'event', 100: 'skill' };
export const EFFECT_FILES = ['01', '02', '03', 'com', 'map', 'snd'];

// ---------------------------------------------------------------------------------------------------------------
// Pure parsers
// ---------------------------------------------------------------------------------------------------------------

/** Compiled skill table layout (share/skill/skill/<index>.dat). All little endian, packed. */
export const SKILL_DAT = Object.freeze({
  LEVELS: 16, LEVEL_SIZE: 102, STYLE_BASE: 1632, STYLE_SLOTS: 20, COMBO_BASE: 1712, COMBOS: 150, COMBO_SIZE: 70,
  HEAD_BASE: 12212, SIZE: 12294, SIZE_OLD: 12290,
});

/**
 * Parse one compiled skill table (12,294 bytes; 16 files are 12,290 bytes = the same without the trailing u32).
 *   [0, 1632)      16 level records x 102 bytes (level 0 is an unused placeholder)
 *   [1632, 1712)   20 x u32 allowed weapon styles (StyleCode list; count at 12213)
 *   [1712, 12212)  150 combo records x 70 bytes (ComboIndex 0..149; a level uses rows StartComboIndex..EndComboIndex)
 *   [12212, end)   header (key/value part of the legacy CSV)
 * @param {Uint8Array|Buffer|ArrayBuffer} buf
 */
export function parseSkillDat(buf) {
  const u8 = toU8(buf);
  if (u8.length !== SKILL_DAT.SIZE && u8.length !== SKILL_DAT.SIZE_OLD) throw new Error(`skill dat: unexpected size ${u8.length}`);
  const dv = new DataView(u8.buffer, u8.byteOffset, u8.byteLength);
  const U8 = (o) => dv.getUint8(o), U16 = (o) => dv.getUint16(o, true), U32 = (o) => dv.getUint32(o, true), I32 = (o) => dv.getInt32(o, true);
  const levels = [];
  for (let L = 0; L < SKILL_DAT.LEVELS; L++) {
    const b = L * SKILL_DAT.LEVEL_SIZE;
    const optionCount = U8(b + 48), reqCount = U8(b + 61);
    const options = [], reqs = [];
    for (let k = 0; k < 6; k++) { const code = U32(b + 8 * k), value = I32(b + 8 * k + 4); if (k < optionCount || code || value) options.push({ slot: k, code, value }); }
    for (let k = 0; k < 4; k++) { const skill = U16(b + 49 + 3 * k), level = U8(b + 51 + 3 * k); if (k < reqCount || skill || level) reqs.push({ slot: k, skill, level }); }
    const unk82 = Array.from(u8.subarray(b + 82, b + 96));
    levels.push({
      level: L, optionCount, options, reqCount, reqs,
      // +64/+68 = ResourceItemCode (u32) / ResourceItemCount (u16) of the CSV level rows (0 in every compiled table)
      pcLevel: U8(b + 62), grade: U8(b + 63), itemCode: U32(b + 64), itemCount: U16(b + 68),
      hp: U16(b + 70), mp: U16(b + 72), fury: U16(b + 74), start: U8(b + 76), end: U8(b + 77), cooldown: U32(b + 78),
      unk82: unk82.some(x => x) ? unk82 : null, cast: U32(b + 96), sp: U8(b + 100), choiceLimit: U8(b + 101),
    });
  }
  const H = SKILL_DAT.HEAD_BASE;
  const styleCount = U16(H + 1);
  const styles = [];
  for (let k = 0; k < SKILL_DAT.STYLE_SLOTS; k++) styles.push(U32(SKILL_DAT.STYLE_BASE + 4 * k));
  const combos = [];
  for (let c = 0; c < SKILL_DAT.COMBOS; c++) {
    const o = SKILL_DAT.COMBO_BASE + c * SKILL_DAT.COMBO_SIZE;
    const args = []; for (let k = 0; k < 8; k++) args.push(I32(o + 4 + 4 * k));
    combos.push({
      combo: c, resultCode: U32(o), args,
      resultEffectId: U16(o + 36), resultSceneId: U16(o + 38), resultEffectTime: U32(o + 40),
      effectId: U16(o + 44), sceneId: U16(o + 46), effectTime: U32(o + 48),
      aggro: U32(o + 52), pvpRate: U16(o + 56), defeat: U16(o + 58),
      actionType: U8(o + 60), style: U8(o + 61), actionIndex: U32(o + 62), timeTick: U32(o + 66),
    });
  }
  const act = (o) => ({ effectId: U16(o), sceneId: U16(o + 2), effectTime: U32(o + 4), actionType: U8(o + 8), style: U8(o + 9), actionIndex: U32(o + 10), timeTick: U32(o + 14) });
  const head = {
    levelCount: U8(H), styleCount, iconIndex: U16(H + 3), iconTab: U8(H + 5), iconX: U8(H + 6), iconY: U8(H + 7),
    ready: act(H + 8), charge: act(H + 26),
    index: U16(H + 44), maxNormal: U8(H + 46) - 1, maxA: U8(H + 47) - 1, maxB: U8(H + 48) - 1,
    target: U32(H + 49), avail: U8(H + 53), distance: U16(H + 54), typeMask: U32(H + 56), unk12272: U16(H + 60),
    classMask: U16(H + 62), awakening: U8(H + 64), needType: U8(H + 65), vars: [U32(H + 66), U32(H + 70), U32(H + 74)],
    pointType: u8.length >= SKILL_DAT.SIZE ? U32(H + 78) : null,
  };
  return { size: u8.length, head, styles: styles.slice(0, styleCount), stylesRaw: styles, levels, combos };
}

/**
 * Legacy text twin share/skill/<tree>_<tab>_<n>_<name>.csv -> { kv, combos[], levels[] (each with its option/
 * requirement sub-rows) }. Only used for cross-validation and the few CSV-only (removed) skills.
 */
export function parseSkillCsv(src) {
  const rows = parseCSV(toText(src, true));
  const kv = {}, combos = [], levels = [];
  let mode = 'kv', ch = null, lh = null, cur = null;
  for (const r of rows) {
    if (!r || !r.length) continue;
    const f0 = String(r[0]).trim();
    if (f0 === 'ComboIndex') { ch = r.map(x => String(x).trim()); mode = 'combo'; continue; }
    if (f0 === 'LevelIndex') { lh = r.map(x => String(x).trim()); mode = 'level'; continue; }
    if (mode === 'kv') { if (f0 && r.length > 1 && !(f0 in kv)) kv[f0] = String(r[1]).trim(); continue; }
    const hdr = mode === 'combo' ? ch : lh;
    const o = {};
    hdr.forEach((h, i) => { if (h && !(h in o)) o[h] = r[i] === undefined ? '' : String(r[i]).trim(); });
    if (mode === 'combo') { if (/^\d+$/.test(f0)) combos.push(o); continue; }
    if (/^\d+$/.test(f0)) { cur = { main: o, subs: [o] }; levels.push(cur); } else if (f0 === '-' && cur) cur.subs.push(o);
  }
  return { kv, combos, levels };
}

/**
 * "(0,1)(500,0.8) (999,0)" or "(0 7 7 7) (999 3 3 3)" -> [[0,1],[500,0.8],[999,0]]
 * Both separators occur in the client files (commas in older effects, spaces in newer ones, ".7" without a leading 0).
 */
export function parseKeyframes(s) {
  const out = [];
  for (const m of String(s).matchAll(/\(([^)]*)\)/g)) {
    const v = m[1].split(/[\s,]+/).filter(x => x !== '').map(Number).filter(x => Number.isFinite(x));
    if (v.length) out.push(v);
  }
  return out;
}
const tokens = (s) => {
  const out = [];
  for (const m of String(s).matchAll(/"([^"]*)"|(\S+)/g)) out.push(m[1] !== undefined ? m[1] : m[2]);
  return out;
};
const num = (v) => { const x = Number(String(v ?? '').trim()); return Number.isFinite(x) ? x : null; };
const bool = (v) => /^(true|ture|1)$/i.test(String(v ?? '').trim());

/**
 * property/effect/effectscene.<file>.txt -> array of effects
 * { cate, id, name, file, res: {unitId: unitName}, scenes: [{ sceneId, name, controls: [...] }] }
 * Control keys are kept verbatim (keyframe lists parsed, see parseKeyframes); docs/formats/effects.md lists them.
 */
export function parseEffectScenes(src, file = '') {
  const text = toText(src, true);
  const effects = [];
  let cate = null, eff = null, scene = null, ctl = null, inList = false;
  for (const raw of text.split(/\r?\n/)) {
    const line = raw.trim();
    if (!line || line[0] === '#') continue;
    const low = line.toLowerCase();
    let m;
    if ((m = /^<cate>\s*(-?\d+)/i.exec(line))) { cate = +m[1]; continue; }
    if (low.startsWith('</cate>')) continue;
    if (low.startsWith('<effect>')) { eff = { cate, id: null, name: '', file, res: {}, scenes: [] }; scene = null; ctl = null; inList = false; continue; }
    if (low.startsWith('</effect>')) { if (eff && eff.id !== null) effects.push(eff); eff = null; continue; }
    if (!eff) continue;
    if (low.startsWith('<list>')) { inList = true; continue; }
    if (low.startsWith('</list>')) { inList = false; continue; }
    if (low.startsWith('<scene>')) { scene = { sceneId: null, name: '', controls: [] }; eff.scenes.push(scene); continue; }
    if (low.startsWith('</scene>')) { scene = null; continue; }
    if (low.startsWith('<control>')) { ctl = {}; if (scene) scene.controls.push(ctl); continue; }
    if (low.startsWith('</control>')) { ctl = null; continue; }
    const sp = line.search(/\s/);
    const key = (sp < 0 ? line : line.slice(0, sp)).toLowerCase();
    const val = sp < 0 ? '' : line.slice(sp).trim();
    if (ctl) {
      if (key in ctl && key === 'active') continue; // every control repeats "active" at its end with the same value
      ctl[key] = val;
      continue;
    }
    if (scene) {
      if (key === 'sceneid') scene.sceneId = num(val);
      else if (key === 'name') scene.name = val;
      continue;
    }
    if (inList && key === 'res') { const t = val.split(/\s+/); eff.res[num(t[0])] = t.slice(1).join(' '); continue; }
    if (key === 'id' && eff.id === null) eff.id = num(val);
    else if (key === 'name' && !eff.name) eff.name = val;
  }
  return effects;
}

/**
 * property/effect/effectdata.<file>.txt -> array of units { name, unittype, file, fields: {key: value} }.
 * Units are addressed by `name` (case-insensitive) from the `res` lists of effect scenes.
 */
export function parseEffectData(src, file = '') {
  const text = toText(src, true);
  const units = [];
  let cur = null, cate = null;
  for (const raw of text.split(/\r?\n/)) {
    const line = raw.trim();
    if (!line || line[0] === '#') continue;
    let m;
    if ((m = /^<cate>\s*(-?\d+)/i.exec(line))) { cate = +m[1]; continue; }
    if (/^<effectdata>/i.test(line)) { cur = { name: '', unittype: '', file, cate, tag: num(line.replace(/^<effectdata>/i, '')), fields: {} }; continue; }
    if (/^<\/effectdata>/i.test(line)) { if (cur && cur.name) units.push(cur); cur = null; continue; }
    if (!cur) continue;
    const sp = line.search(/\s/);
    const key = (sp < 0 ? line : line.slice(0, sp)).toLowerCase();
    const val = sp < 0 ? '' : line.slice(sp).trim();
    if (key === 'name') cur.name = val;
    else if (key === 'unittype') cur.unittype = val.toLowerCase();
    else cur.fields[key] = val;
  }
  return units;
}

/** script/string/*.txt "<cate> N" / "code N # NAME" / "{ text }" -> Map("cate:code" -> {cate, code, tag, text}) */
export function parseStringTable(src) {
  const text = toText(src, true);
  const out = new Map();
  let cate = null, cur = null, body = null;
  for (const raw of text.split(/\r?\n/)) {
    const line = raw.replace(/\s+$/, '');
    const t = line.trim();
    let m;
    if (body !== null) {
      if (t === '}') { cur.text = body.join('\n').trim(); out.set(`${cur.cate}:${cur.code}`, cur); body = null; cur = null; } else body.push(line);
      continue;
    }
    if ((m = /^<cate>\s*(-?\d+)/i.exec(t))) { cate = +m[1]; continue; }
    if ((m = /^code\s+(-?\d+)\s*(?:#\s*(.*))?$/.exec(t))) { cur = { cate, code: +m[1], tag: (m[2] || '').trim() }; continue; }
    if (t === '{' && cur) { body = []; continue; }
  }
  return out;
}

/** Transposed CSV (share/creature/servant.csv, one column per record, first column = field names). */
export function parseTransposedCsv(src) {
  const rows = parseCSV(toText(src, true));
  const names = rows.map(r => String(r[0] ?? '').trim());
  const width = Math.max(...rows.map(r => r.length));
  const recs = [];
  for (let c = 1; c < width; c++) {
    const o = {};
    let any = false;
    rows.forEach((r, i) => { const n = names[i]; if (!n) return; const v = String(r[c] ?? '').trim(); if (v !== '') any = true; if (!(n in o)) o[n] = v; });
    if (any && o.Index !== '') recs.push(o);
  }
  return recs;
}

/** Plain header CSV -> objects (header = first row). */
export function csvObjects(src, korean = true) {
  const rows = parseCSV(toText(src, korean));
  const header = (rows.shift() || []).map(h => String(h).trim());
  const out = [];
  for (const r of rows) {
    if (!r || !r.some(x => String(x).trim() !== '')) continue;
    const o = {};
    header.forEach((h, i) => { if (h && !(h in o)) o[h] = r[i] === undefined ? '' : String(r[i]).trim(); });
    out.push(o);
  }
  return { header, rows: out };
}

// ---------------------------------------------------------------------------------------------------------------
// Result codes
// ---------------------------------------------------------------------------------------------------------------

/** Skill-table distances (radius args) are stored in 1/128 world units: 512 = 4 m (characters.md, confirmed by texts). */
export const DIST_SCALE = 128;

/**
 * Result-code families. `layout` names Arg1..Arg8 (index 0 = Arg1); '?' = not understood (kept raw in args).
 * Evidence: value statistics over all 1,418 compiled tables (which positions hold x64 multiples, percentages,
 * valid status.csv / remote.csv indices, ms durations) + the English skilldesc texts; see docs/formats/skills.md.
 */
export const RESULT_FAMILIES = [
  { re: /^1000[1-7]\d\d$/, family: 'damage', kind: 'damage', confidence: 'high',
    layout: ['radius', 'elementPct', 'addDamage', 'chance', 'statusIndex', 'statusDurationMs', 'damagePct?', '?'],
    note: 'digit 5 = shape (1 single target, 2 area around the target, 3 elemental area, 4 single + status, 5 area + knockback/status, 7 area over time); last 2 digits = damage type (see damageType)' },
  { re: /^1100\d{3}$/, family: 'damage_special', kind: 'damage', confidence: 'low', layout: ['radius|chance', '?', 'addDamage|durationMs', 'chance', '?', '?', '?', '?'] },
  { re: /^3000\d{3}$/, family: 'projectile', kind: 'projectile', confidence: 'high',
    layout: ['remoteIndex', '...args of remote.csv ResultType (Arg2..Arg8 = Arg1..Arg7 of the impact result)'],
    note: 'launches remote.csv[Arg1]; on impact the remote\'s ResultType is applied with Arg2..Arg8 as its Arg1..Arg7 (e.g. Protection sanctuary 3000006 [78,1024,100,381,2000] = remote 78 (ResultType 4000101) -> [radius 8 m, 100%, status 381, 2000 ms])' },
  { re: /^200000[12]$/, family: 'heal', kind: 'heal', confidence: 'high', layout: ['amount', 'perSpr(x100)'], note: '2000001 = selected target, 2000002 = self' },
  { re: /^2000[12]01$/, family: 'heal_area', kind: 'heal', confidence: 'high', layout: ['radius', 'amount', 'perSpr(x100)'] },
  { re: /^2000301$/, family: 'resurrect', kind: 'resurrect', confidence: 'medium', layout: [] },
  { re: /^2000401$/, family: 'shield_heal', kind: 'heal', confidence: 'medium', layout: ['amount', 'perSpr(x100)'], note: 'restores the target\'s shield (Recover shield)' },
  { re: /^20005\d\d$/, family: 'damage_share', kind: 'status', confidence: 'medium', layout: ['radius', 'sharePct', 'statusIndex', 'durationMs'], note: 'Divide Force / Divide Pain: take a % of an ally\'s damage' },
  { re: /^400000[23]$/, family: 'status', kind: 'status', confidence: 'high', layout: ['chance', 'statusIndex', 'durationMs', '?', '?', '?', 'chance2?', 'statusIndex2?'], note: '4000002 = on the selected target, 4000003 = on self' },
  { re: /^4000006$/, family: 'transform', kind: 'transform', confidence: 'high', layout: ['durationMs', 'transformSkill', 'transformLevel'], note: 'trans-up: share/skill/awakening/transform.csv[transformSkill][transformLevel] -> script/shape/shapeshift.csv look' },
  { re: /^400010\d$/, family: 'area_status_party', kind: 'area_status', confidence: 'high', layout: ['radius', 'chance', 'statusIndex', 'durationMs', '?', '?durationMs', '?', '?'] },
  { re: /^400020\d$/, family: 'area_status_enemy', kind: 'area_status', confidence: 'high', layout: ['radius', 'chance', 'statusIndex', 'durationMs', '?', '?', '?', '?'] },
  { re: /^4000301$/, family: 'dispel', kind: 'dispel', confidence: 'medium', layout: ['?', 'chance', 'statusGroup', 'statusGroup', 'statusGroup', 'statusGroup', 'count', '?'], note: 'Regression: removes the last-applied buff of the listed status groups' },
  { re: /^4000600$/, family: 'auto_revive', kind: 'status', confidence: 'medium', layout: ['statusIndex', 'durationMs', '?', '?'], note: 'Recover Routine: buff that lets the holder resurrect' },
  { re: /^4100101$/, family: 'shield_break', kind: 'status', confidence: 'low', layout: ['?', '?', '?'] },
  { re: /^4200001$/, family: 'spell_self', kind: 'spell', confidence: 'medium', layout: ['statusIndex'], note: 'Aloken spell (proc) buff on self; proc chance/effect come from the status options' },
  { re: /^420000[2-6]$/, family: 'spell_party', kind: 'spell', confidence: 'medium', layout: ['statusIndex', 'chance', 'range?'], note: 'spell on party members' },
  { re: /^4200003$/, family: 'spell_self', kind: 'spell', confidence: 'medium', layout: ['statusIndex'] },
  { re: /^4500010$/, family: 'recall', kind: 'movement', confidence: 'medium', layout: [], note: 'summon the selected party member to the caster' },
  { re: /^4500021$/, family: 'dash', kind: 'movement', confidence: 'high', layout: [], note: 'dash to the target (Charged shock, Power dash, Charge Diss)' },
  { re: /^4500022$/, family: 'teleport', kind: 'movement', confidence: 'high', layout: [], note: 'move to the chosen location (Out of sight)' },
  { re: /^4500023$/, family: 'share_target', kind: 'area_status', confidence: 'medium', layout: ['radius', '?', 'statusIndex', 'durationMs'], note: 'Point target' },
  { re: /^5000001$/, family: 'summon', kind: 'summon', confidence: 'high', layout: ['servantIndex', 'summonLevel'] },
  { re: /^5000003$/, family: 'servant_explode', kind: 'damage', confidence: 'medium', layout: ['radius', '?', 'addDamage', 'chance', 'statusIndex', 'statusDurationMs'], note: 'explodes the own summon' },
  { re: /^5100001$/, family: 'totem', kind: 'summon', confidence: 'high', layout: ['totemIndex', 'summonLevel'], note: 'summoner Sacra/Chakra sculptures: share/creature/totem.csv' },
  { re: /^6100000$/, family: 'cooldown_lock', kind: 'special', confidence: 'low', layout: [], note: '"turns the target\'s skill cooldowns by force"' },
  { re: /^6100001$/, family: 'cooldown_reset', kind: 'special', confidence: 'medium', layout: ['?', 'all?', 'skillIndex'], note: 'resets the cooldown of skillIndex (or all when Arg2 = 1)' },
  { re: /^7000001$/, family: 'stealth', kind: 'status', confidence: 'high', layout: ['?', '?', '?', 'statusIndex', '?', 'durationMs'] },
  { re: /^7000002$/, family: 'detect', kind: 'special', confidence: 'high', layout: ['radius'], note: 'reveals hidden units within radius' },
  { re: /^700000[34]$/, family: 'sleep_shock', kind: 'status', confidence: 'high', layout: ['radius', '?', '?', 'chance', 'statusIndex', 'durationMs'], note: '7000003 single target, 7000004 area' },
  { re: /^700000[679]$/, family: 'cleanse', kind: 'dispel', confidence: 'high', layout: ['radius', 'chance', '?', '?', 'statusGroup', 'count'], note: 'removes `count` statuses of statusGroup (statusgroup.csv); 7000009 = area' },
  { re: /^70000(20|21)$/, family: 'surrender', kind: 'status', confidence: 'medium', layout: ['chance', 'statusIndex|?', 'durationMs|statusIndex', 'durationMs'], note: 'Hella: forces the target to kneel' },
];

/** Damage-type suffix (last two digits of 1000xyy) -> engine damage class. Element names only where texts confirm them. */
export const DAMAGE_TYPES = {
  1: { cls: 'melee' }, 2: { cls: 'melee' }, 3: { cls: 'range' }, 5: { cls: 'magic', element: 'energy' },
  6: { cls: 'melee' }, 7: { cls: 'melee' }, 10: { cls: 'magic' }, 11: { cls: 'magic', element: 'fire' }, 12: { cls: 'magic' },
  13: { cls: 'magic', element: 'ice' }, 14: { cls: 'magic', element: 'lightning' }, 16: { cls: 'magic', element: 'curse' },
  17: { cls: 'magic', element: 'dark' }, 18: { cls: 'melee' }, 19: { cls: 'melee' }, 20: { cls: 'melee' },
};
/** 10003yy elemental-area pairs (confirmed by skill texts: Fire blaze, Lightning chase, Infected earth, Silent cry). */
export const ELEMENT_AREA_PAIRS = { 1: 'fire', 2: 'fire', 3: 'ice', 4: 'ice', 5: 'lightning', 6: 'lightning', 7: 'poison', 8: 'poison', 9: 'curse', 10: 'curse', 11: 'dark?', 12: 'dark?' };

/**
 * Decode a result code + its 8 args. `ctx.remotes` (Map index -> remote row) enables projectile impact decoding.
 * Always keeps `args` (raw) so nothing is lost; named fields are only the understood ones.
 */
export function describeResult(code, args, ctx = null, depth = 0) {
  const c = String(code);
  const a = (args || []).map(Number);
  while (a.length < 8) a.push(0);
  const fam = RESULT_FAMILIES.find(f => f.re.test(c));
  const out = { resultCode: +c, family: fam ? fam.family : 'unknown', kind: fam ? fam.kind : 'other' };
  const R = (v) => +(v / DIST_SCALE).toFixed(4);
  const status = (ch, st, dur) => { if (!st) return; out.statusIndex = st; out.chance = ch; if (dur) out.statusDurationMs = dur; };
  if (!fam) { out.args = trimZeros(a); return out; }
  switch (fam.family) {
    case 'damage': {
      const shape = +c[4], yy = +c.slice(5);
      out.shape = { 1: 'single', 2: 'area', 3: 'area_element', 4: 'single_status', 5: 'area_status', 7: 'area_dot' }[shape] || `shape${shape}`;
      out.damageType = yy;
      const dt = shape === 3 ? { cls: 'magic', element: ELEMENT_AREA_PAIRS[yy] } : DAMAGE_TYPES[yy];
      if (dt) { out.damageClass = dt.cls; if (dt.element) out.element = dt.element; }
      if (shape === 7) { out.dotStatusIndex = a[0]; break; }
      if (a[0] > 0 && shape !== 1 && shape !== 4) out.radius = R(a[0]);
      if (a[1]) out.elementPct = a[1];
      out.addDamage = a[2];
      status(a[3], a[4], a[5]);
      if (a[6]) out.damagePct = a[6];
      if (c === '1000420') { delete out.elementPct; out.randomDebuffs = a[1]; out.statusDurationMs = a[5]; }
      break;
    }
    case 'projectile': {
      out.remoteIndex = a[0];
      out.launch = +c.slice(4);
      const rm = ctx?.remotes?.get(a[0]);
      if (!rm) { if (ctx) out.remoteMissing = true; break; }
      if (rm.resultType && depth < 2) {
        const impact = describeResult(rm.resultType, a.slice(1).concat([0]), ctx, depth + 1);
        delete impact.args;
        // the impact's named values are hoisted onto the projectile result; impact keeps only what identifies it
        for (const k of ['radius', 'addDamage', 'statusIndex', 'chance', 'statusDurationMs', 'durationMs', 'damageClass', 'element', 'elementPct', 'damagePct', 'target', 'statusMissing']) {
          if (impact[k] !== undefined) { out[k] = impact[k]; delete impact[k]; }
        }
        out.impact = impact;
      }
      break;
    }
    case 'heal': out.amount = a[0]; if (a[1]) out.perSpr = a[1] / 100; out.target = c === '2000002' ? 'self' : 'target'; break;
    case 'heal_area': if (a[0]) out.radius = R(a[0]); out.amount = a[1]; if (a[2]) out.perSpr = a[2] / 100; out.target = c[4] === '1' ? 'target_area' : 'party'; break;
    case 'shield_heal': out.amount = a[0]; if (a[1]) out.perSpr = a[1] / 100; break;
    case 'damage_share': if (a[0]) out.radius = R(a[0]); out.sharePct = a[1]; out.statusIndex = a[2]; out.durationMs = a[3]; break;
    case 'status': out.chance = a[0]; out.statusIndex = a[1]; out.durationMs = a[2]; out.target = c === '4000003' ? 'self' : 'target'; if (a[7]) { out.chance2 = a[6]; out.statusIndex2 = a[7]; } break;
    case 'transform': out.durationMs = a[0]; out.transformSkill = a[1]; out.transformLevel = a[2]; break;
    case 'area_status_party': case 'area_status_enemy':
      out.target = fam.family === 'area_status_party' ? 'party' : 'enemies';
      if (a[0]) out.radius = R(a[0]); out.chance = a[1]; out.statusIndex = a[2]; out.durationMs = a[3]; break;
    case 'dispel': out.chance = a[1]; out.statusGroups = a.slice(2, 6).filter(Boolean); out.count = a[6]; break;
    case 'auto_revive': out.statusIndex = a[0]; out.durationMs = a[1]; break;
    case 'spell_self': out.statusIndex = a[0]; out.target = 'self'; break;
    case 'spell_party': out.statusIndex = a[0]; out.chance = a[1]; out.target = 'party'; break;
    case 'share_target': out.radius = R(a[0]); out.statusIndex = a[2]; out.durationMs = a[3]; break;
    case 'summon': out.servantIndex = a[0]; out.summonLevel = a[1]; break;
    case 'servant_explode': out.radius = R(a[0]); out.addDamage = a[2]; status(a[3], a[4], a[5]); break;
    case 'totem': out.totemIndex = a[0]; out.summonLevel = a[1]; break;
    case 'cooldown_reset': if (a[2]) out.skillIndex = a[2]; if (a[1]) out.all = true; break;
    case 'stealth': out.statusIndex = a[3]; out.durationMs = a[5]; out.target = 'self'; break;
    case 'detect': out.radius = R(a[0]); break;
    case 'sleep_shock': if (a[0]) out.radius = R(a[0]); status(a[3], a[4], a[5]); break;
    case 'cleanse': if (a[0]) out.radius = R(a[0]); out.chance = a[1]; out.statusGroup = a[4]; out.count = a[5]; break;
    case 'surrender': if (c === '7000020') { out.chance = a[0]; out.statusIndex = a[1]; out.durationMs = a[2]; } else { out.chance = a[0]; out.statusIndex = a[2]; out.durationMs = a[3]; } break;
    default: break;
  }
  if (out.statusIndex && ctx?.statuses && !ctx.statuses.has(out.statusIndex)) out.statusMissing = true;
  out.args = trimZeros(a);
  return out;
}
/** [0,0,22,0,0,0,0,0] -> [0,0,22] (raw Arg1..Arg8; missing trailing entries are 0) */
export const trimZeros = (a) => { let n = a.length; while (n > 0 && !a[n - 1]) n--; return a.slice(0, n); };

// ---------------------------------------------------------------------------------------------------------------
// Effect units -> renderable description
// ---------------------------------------------------------------------------------------------------------------

const vec = (s) => String(s ?? '').trim().split(/[\s,]+/).filter(x => x !== '').map(Number).filter(Number.isFinite);

/** Turn a raw effectdata unit into a typed, engine-friendly object (asset paths resolved by `res`). */
export function describeUnit(u, res) {
  // every field the switch below does not read is kept verbatim in o.raw (Proxy records the reads)
  const used = new Set();
  const f = new Proxy(u.fields, { get(t, k) { used.add(k); return t[k]; } });
  const o = { type: u.unittype || 'unknown', file: u.file };
  if (u.tag) o.flag = u.tag; // the number after "<effectdata>" (0, or 1 on 389 units; meaning unknown)
  const finish = () => {
    if (o.raw === u.fields) return o;
    for (const k of Object.keys(u.fields)) if (!used.has(k) && u.fields[k] !== '') (o.raw ??= {})[k] = u.fields[k];
    return o;
  };
  const tex = () => {
    if (f.texturefile) { const k = res.texture(f.texturefile, u); if (k) o.texture = k; }
    if (f.texturepack) { const tp = res.tpack(f.texturepack, u); if (tp) { o.tpack = tp.key; o.frames = tp.frames; } }
    if (f.blendtype) o.blend = f.blendtype.toLowerCase();
    if (f.textureloop) o.texLoop = f.textureloop.toLowerCase();
    if (f.texanimtime !== undefined) o.texAnimMs = num(f.texanimtime) || 0;
  };
  const common = () => {
    if (f.billboardtype !== undefined) o.billboard = f.billboardtype.toLowerCase();
    if (f.size !== undefined) o.size = num(f.size);
    if (f.backprint !== undefined) o.backPrint = bool(f.backprint);
    if (f.disort !== undefined) o.distort = bool(f.disort);
    if (f.tailstep !== undefined) { const t = tokens(f.tailstep); o.tail = { count: num(t[0]), a: num(t[1]), b: num(t[2]), ms: num(t[3]), on: bool(t[4]) }; }
  };
  const meshPart = () => {
    if (f.mesh) { const k = res.path('mesh', f.mesh, u); if (k) o.mesh = k; }
    if (f.animation) { const k = res.path('anim', f.animation, u); if (k) o.anim = k; }
    if (f.skeleton) { const k = res.path('skel', f.skeleton, u); if (k) o.skel = k; }
    if (f.animlength !== undefined) o.animLengthMs = num(f.animlength);
    if (f.twoside !== undefined) o.twoSide = bool(f.twoside);
    if (f.transparent !== undefined) o.transparent = bool(f.transparent);
    if (f.mesh_status !== undefined) { const t = tokens(f.mesh_status); o.meshStatus = { mode: num(t[0]), a: num(t[1]), b: num(t[2]), line: t[3] || '' }; }
  };
  switch (o.type) {
    case 'sprite': common(); tex(); break;
    case 'decal': common(); tex(); break;
    case 'mesh': common(); meshPart(); if (f.texturepack) { const tp = res.tpack(f.texturepack, u, true); if (tp) { o.tpack = tp.key; o.textures = tp.textures; } } break;
    case 'particle': case 'weather': {
      common(); tex();
      if (f.leaftype) o.leaf = f.leaftype.toLowerCase();
      const e = {};
      if (f.activestate) e.state = f.activestate.toLowerCase();
      if (f.lifetime !== undefined) e.lifetimeMs = vec(f.lifetime);
      if (f.emitrate !== undefined) e.rate = num(f.emitrate);
      if (f.maxelementcount !== undefined) e.max = num(f.maxelementcount);
      if (f.addrotate !== undefined) e.addRotate = num(f.addrotate);
      if (f.velocity !== undefined) e.velocity = vec(f.velocity);
      if (f.acceleration !== undefined) e.acceleration = num(f.acceleration);
      if (f.spawndirection !== undefined) e.spawnDir = vec(f.spawndirection);
      if (f.gravity !== undefined) e.gravity = vec(f.gravity);
      if (f.colorrange !== undefined) e.colorRange = num(f.colorrange);
      if (f.startrange !== undefined) e.startRange = vec(f.startrange);
      if (f.endposition !== undefined) e.endPos = vec(f.endposition);
      if (f.particlesize !== undefined) e.particleSize = vec(f.particlesize);
      if (f.followdirection !== undefined) e.followDir = bool(f.followdirection);
      if (f.spawndirabs !== undefined) e.spawnDirAbs = bool(f.spawndirabs);
      if (f.trianglerender !== undefined) e.triangleRender = bool(f.trianglerender);
      for (const k of ['flatmaxelementcount', 'flatscale', 'flatcolor', 'flatrenderrate']) if (f[k] !== undefined) e[k] = vec(f[k]);
      if (f.flattexturefile) e.flatTexture = res.texture(f.flattexturefile, u);
      o.emitter = e;
      if (o.leaf === 'mesh' || f.mesh) meshPart();
      break;
    }
    case 'sound': {
      const t = tokens(f.sound);
      o.subtype = (f.subtype || '').toLowerCase();
      if (t[0]) { o.soundFile = t[0]; const k = res.sound(t[0], u); if (k) o.sound = k; }
      o.flagA = num(t[1]); o.volume = num(t[2]); o.range = num(t[3]); o.lengthMs = num(t[4]); o.exclusive = bool(t[5]);
      if (f.playintv) o.playInterval = vec(f.playintv);
      break;
    }
    case 'quake': { const t = vec(f.camera); o.camera = { a: t[0], amplitude: t[1], frequency: t[2] }; break; }
    case 'meshstatus': {
      common(); tex();
      if (f.mesh_status !== undefined) { const t = tokens(f.mesh_status); o.meshStatus = { mode: num(t[0]), a: num(t[1]), b: num(t[2]), line: t[3] || '' }; }
      if (f.mesh_color !== undefined) o.color = vec(f.mesh_color);
      break;
    }
    case 'light': {
      for (const k of ['light', 'dirlight', 'bloom', 'fog']) if (f[k] !== undefined) o[k] = vec(f[k]);
      for (const k of ['light_enable', 'bloom_enable', 'fog_enable']) if (f[k] !== undefined) o[k.replace('_enable', 'Enable')] = bool(f[k]);
      if (f.light_fadetime !== undefined) o.fadeMs = num(f.light_fadetime);
      if (f.light_range !== undefined) o.range = num(f.light_range);
      if (f.light_faderange !== undefined) o.fadeRange = num(f.light_faderange);
      break;
    }
    default: o.raw = u.fields;
  }
  return finish();
}

/** Effect-scene control -> compact object (defaults omitted). Keyframe times: 0..999 over the control's lifetime. */
export function describeControl(c) {
  const o = { unit: num(c.unitid) };
  if (c.active !== undefined && !bool(c.active)) o.active = false;
  const sp = vec(c.startposition);
  if (sp.some(v => v)) o.pos = sp;
  if (c.lifetime !== undefined) o.life = vec(c.lifetime);
  if (c.animtime !== undefined && num(c.animtime)) o.animTime = num(c.animtime);
  if (c.bonename !== undefined) o.bone = tokens(c.bonename)[0] ?? '';
  if (c.follow !== undefined) o.follow = bool(c.follow);
  if (c.randomstart !== undefined && bool(c.randomstart)) o.randomStart = true;
  if (c.absdir !== undefined) o.absDir = bool(c.absdir);
  if (c.abspos !== undefined) o.absPos = bool(c.abspos);
  if (c.animpath !== undefined) o.animPath = tokens(c.animpath)[0] ?? '';
  if (c.bone_animation !== undefined) {
    const t = tokens(c.bone_animation);
    o.boneAnim = { bone: t[0], skel: t[1] ? gamePathToData('skel', t[1]) : null, anim: t[2] ? gamePathToData('anim', t[2]) : null, params: t.slice(3).map(Number) };
  }
  for (const [k, n] of [['scale', 'scale'], ['alpha', 'alpha'], ['color', 'color'], ['rotation', 'rotation'], ['position', 'position']]) {
    if (c[k] !== undefined) o[n] = parseKeyframes(c[k]);
  }
  const known = new Set(['unitid', 'active', 'startposition', 'lifetime', 'animtime', 'bonename', 'follow', 'randomstart', 'absdir', 'abspos', 'animpath', 'bone_animation', 'scale', 'alpha', 'color', 'rotation', 'position']);
  for (const k of Object.keys(c)) if (!known.has(k)) (o.raw ??= {})[k] = c[k];
  return o;
}

// ---------------------------------------------------------------------------------------------------------------
// Builder (Node only)
// ---------------------------------------------------------------------------------------------------------------

const cleanDesc = (s) => String(s || '').replace(/<\/?color[^>]*>/gi, '').replace(/<[^>]+>/g, '').replace(/\s*\\+\s*/g, ' ').replace(/\s{2,}/g, ' ').trim();

// These two impact scenes are inferred from exact skill assets and timing.
// No native category dispatch has been established. Changed source definitions fail closed.
const ALOKEN_HIT_CATEGORY_COMPATIBILITY = [
  {
    "skill": 1284,
    "classIndex": 6,
    "resultCode": 1000414,
    "id": 34,
    "scene": 1,
    "timeMs": 600,
    "definitionSha256": "e52994ee44a1bb6d56b8c4639df9443dba1b9ac496340742c8dec572b0e6388a",
    "assets": [
      "texture/effect/skill/manashock02/eff_mana_con_tg03#.dds",
      "texture/effect/skill/manashock02/eff_mana_con_tg01#.dds",
      "texture/effect/skill/manashock02/eff_mana_con_tg02#.dds",
      "texture/effect/skill/manashock02/eff_mana_con_pt01#.dds",
      "sound/skill/manashock_finish.wav"
    ]
  },
  {
    "skill": 1211,
    "classIndex": 6,
    "resultCode": 1000202,
    "id": 35,
    "scene": 1,
    "timeMs": 500,
    "definitionSha256": "3c983a0877a90d1fda58c4d273801b92746d41872d4d3163e1c6db8cd383234d",
    "assets": [
      "texture/effect/skill/lavieenrose/eff_lavie_con_finish01#.dds",
      "texture/effect/skill/lavieenrose/eff_lavie_con_finish02#.dds",
      "mesh/effect/skill/lavieenrose/eff_lavie_con_light01.mesh",
      "anim/effect/skill/lavieenrose/eff_lavie_con_light01.anim",
      "skel/effect/skill/lavieenrose/eff_lavie_con_light01.skel",
      "texturepack/effect/skill/lavieenrose/eff_lavie_con_light01.tpack",
      "texture/effect/skill/lavieenrose/eff_lavie_con_light01#.dds",
      "texture/effect/monster/eff_tyrant_ludni_die_pt01#.dds"
    ]
  }
];

export function recoverAlokenHitCategory(input, { effectsByKey, unitsByName, has }) {
  const spec = ALOKEN_HIT_CATEGORY_COMPATIBILITY.find(c =>
    ['skill', 'classIndex', 'resultCode', 'id', 'scene', 'timeMs'].every(k => c[k] === input[k]));
  if (!spec || effectsByKey.has(`100:${input.id}`)) return null;
  const scenes = effectsByKey.get(`11:${input.id}`) || [];
  const units = scenes.flatMap(s => Object.values(s.res).map(name => {
    const found = unitsByName.get(String(name).toLowerCase()) || [];
    return found.find(u => u.file === s.file) || found.find(u => u.file !== 'snd') || found[0];
  }));
  if (units.some(u => !u) || !spec.assets.every(has)) return null;
  const fingerprint = createHash('sha256').update(JSON.stringify({ scenes, units })).digest('hex');
  if (fingerprint !== spec.definitionSha256) return null;
  return { cate: 11, id: input.id, scene: input.scene, timeMs: input.timeMs,
    compatibility: { kind: 'inferred-aloken-hit-category', originalCate: 100,
      nativeDispatchVerified: false, definitionSha256: fingerprint,
      evidence: input.skill === 1284 ? 'Exact Manashock02 impact assets and matching Manashock finish sound scene.' : 'Exact Lavieenrose impact mesh, animation and textures, separate from its status aura.' } };
}

export async function build({ dataRoot, verbose = false } = {}) {
  const t0 = Date.now();
  const problems = [], notes = [];
  const log = (...a) => { if (verbose) console.log(...a); };

  // ---- file index
  const FILES = new Map();
  for (const top of ['anim', 'mesh', 'skel', 'texture', 'texturepack', 'share', 'script', 'property', 'sound']) {
    const abs = path.join(dataRoot, top);
    if (!fs.existsSync(abs)) continue;
    // files only: a directory key (e.g. an effectdata "Skeleton Effect\skill\sht\" with an empty file name) must not resolve
    for (const ent of fs.readdirSync(abs, { recursive: true, withFileTypes: true })) {
      if (!ent.isFile()) continue;
      const full = path.join(ent.parentPath ?? ent.path, ent.name);
      const key = normPath(`${top}/${path.relative(abs, full)}`);
      if (!FILES.has(key)) FILES.set(key, full);
    }
  }
  const has = (k) => !!k && FILES.has(normPath(k));
  const read = (k) => { const a = FILES.get(normPath(k)); if (!a) throw new Error(`missing ${k}`); return fs.readFileSync(a); };
  const readText = (k) => decodeText(read(k), true);
  const texIndex = buildTextureIndex([...FILES.keys()].filter(k => k.startsWith('texture/')));
  const soundByBase = new Map();
  for (const k of FILES.keys()) if (k.startsWith('sound/')) { const b = k.slice(k.lastIndexOf('/') + 1); if (!soundByBase.has(b)) soundByBase.set(b, k); }
  const missingAssets = new Map(); // key -> referenced by
  const miss = (kind, key, by) => { if (!missingAssets.has(key)) missingAssets.set(key, { kind, by }); };

  // ---- strings
  const strCom = parseStringTable(read('script/string/stringtable_com.txt'));
  const strSkill = parseStringTable(read('script/string/normal/stringtable_skill.txt'));
  const optionCodes = {};           // id -> { name, text }
  const optionIdByName = new Map();
  for (const v of strCom.values()) if (v.cate === 200) { optionCodes[v.code] = { name: v.tag.split(/\s+/)[0] || null, text: cleanDesc(v.text) }; if (v.tag) optionIdByName.set(v.tag.split(/\s+/)[0], v.code); }

  // ---- class names (share/pc/pcclass.csv row name_kor holds the English display names)
  const pc = {};
  for (const r of parseCSV(readText('share/pc/pcclass.csv'))) pc[String(r[0]).trim()] = r.slice(1).map(x => String(x).trim());

  // ---- skilldesc (English)
  const desc = new Map(); // index -> { classFile, name, weapon, levels: Map(level -> description), iconIndex }
  for (const C of SKILL_CLASSES) {
    const k = `script/skilldesc/${C.desc}.csv`;
    if (!has(k)) { problems.push(`missing ${k}`); continue; }
    for (const r of csvObjects(read(k)).rows) {
      const i = num(r.Index); if (i === null) continue;
      const d = desc.get(i) || { classFile: C.desc, name: r.Name, weapon: r.Weapon, levels: new Map(), iconIndex: num(r.IconIndex) };
      d.levels.set(num(r.Level), cleanDesc(r.Description));
      desc.set(i, d);
    }
  }

  // ---- skilltable.csv (index -> Korean name + legacy CSV/code name)
  const tableInfo = new Map();
  {
    const rows = parseCSV(readText('share/skill/skilltable.csv'));
    let category = '';
    for (let r = 2; r < rows.length; r++) {
      const row = rows[r];
      if (String(row[0] ?? '').trim()) category = String(row[0]).trim();
      for (let c = 1; c < row.length; c += 3) {
        const i = num(row[c]); if (i === null || String(row[c]).trim() === '') continue;
        const nameKor = String(row[c + 1] ?? '').trim(), file = String(row[c + 2] ?? '').trim();
        if (!file && !nameKor) continue;
        tableInfo.set(i, { nameKor, file, code: file.replace(/\.csv$/i, ''), category });
      }
    }
  }

  // ---- legacy CSV twins (cross-check only)
  const csvByIndex = new Map();
  for (const k of FILES.keys()) {
    if (!/^share\/skill\/[^/]+\.csv$/.test(k)) continue;
    let p; try { p = parseSkillCsv(read(k)); } catch { continue; }
    const i = num(p.kv.Index); if (i === null || !p.levels.length) continue;
    p.file = k;
    if (!csvByIndex.has(i)) csvByIndex.set(i, []);
    csvByIndex.get(i).push(p);
  }

  // ---- option-code names missing from stringtable <cate> 200: learn them from the CSV twins (same level/slot in the .dat)
  {
    const learned = new Map();
    for (const [i, list] of csvByIndex) {
      if (!has(`share/skill/skill/${i}.dat`)) continue;
      // Some indices retain an obsolete CSV next to their current native table.
      // Only the exact skilltable filename may disambiguate those twins; never
      // infer an enum name from an unrelated same-index historical skill.
      const declared = normPath(tableInfo.get(i)?.file).replace(/\.csv$/i, '');
      const candidates = list.length === 1 ? list : list.filter(p =>
        normPath(path.basename(p.file)).replace(/\.csv$/i, '') === declared);
      if (candidates.length !== 1) continue;
      let d; try { d = parseSkillDat(read(`share/skill/skill/${i}.dat`)); } catch { continue; }
      for (const lv of candidates[0].levels) {
        const L = num(lv.main.LevelIndex); if (!L || L > 15) continue;
        lv.subs.forEach((s, k) => {
          const name = String(s.OptionCode || '').trim();
          const o = d.levels[L].options.find(x => x.slot === k);
          if (!o || !o.code || !name || name === '-' || /^\d+$/.test(name) || num(s.OptionValue) !== o.value) return;
          const key = `${o.code}`;
          if (!learned.has(key)) learned.set(key, new Map());
          learned.get(key).set(name, (learned.get(key).get(name) || 0) + 1);
        });
      }
    }
    for (const [id, names] of learned) {
      const best = [...names].sort((a, b) => b[1] - a[1])[0][0];
      if (!optionCodes[id]) { optionCodes[id] = { name: best, text: null, source: 'share/skill/*.csv option name (no stringtable text)' }; optionIdByName.set(best, +id); }
      else if (optionCodes[id].name !== best && !optionIdByName.has(best)) optionIdByName.set(best, +id);
    }
  }

  // ---- remotes (share/creature/remote.csv)
  const remotes = new Map();
  for (const r of csvObjects(read('share/creature/remote.csv')).rows) {
    const i = num(r.Index); if (i === null) continue;
    remotes.set(i, {
      index: i, description: r.Description, resultType: num(r.ResultType), maxDistance: num(r.MaxDistance), moveSpeed: num(r.MoveSpeed),
      size: num(r.Size), maxPiercing: num(r.MaxPiercingNum), piercingRate: num(r.MaxPiercingRate), hitCycleMs: num(r.HitCycle),
      lifetimeMs: num(r.EffectTime), // Native lifetime exists even when EffectID is zero.
      effect: { id: num(r.EffectID), scene: num(r.SceneID), timeMs: num(r.EffectTime) },
      contactEffect: { id: num(r.ContactEffectID), scene: num(r.ContactSceneID), timeMs: num(r.ContactEffectTime) },
      piercingEffect: { id: num(r.PiercingEffectID), scene: num(r.PiercingSceneID), timeMs: num(r.PiercingEffectTime) },
      warningEffect: num(r.WarningEffectID) ? { id: num(r.WarningEffectID), cate: num(r.WarningEffectCate), scene: num(r.WarningSceneID), timeMs: num(r.WarningEffectTime) } : null,
      hitStartDistance: num(r.fHitStartDistance), destroyWhenDie: num(r.bDestroyWhenDie),
    });
  }

  // ---- statuses (share/skill/status.csv)
  const statusRows = csvObjects(read('share/skill/status.csv'));
  const statuses = new Map();
  for (const r of statusRows.rows) {
    const i = num(r.Index); if (i === null) continue;
    const cells = statusRows.header.map(h => r[h]);
    const options = [];
    // option columns come in (code, value) pairs after OptionCount; the header has a typo (Optio11_Value) so read by position
    const firstOpt = statusRows.header.indexOf('Option0_code');
    for (let k = 0; k < 15; k++) {
      const code = cells[firstOpt + 2 * k], value = cells[firstOpt + 2 * k + 1];
      if (!code || code === 'NONE') continue;
      const id = optionIdByName.has(code) ? optionIdByName.get(code) : (num(code) ?? null);
      options.push({ code: optionCodes[id]?.name || code, id, value: num(value) });
    }
    statuses.set(i, {
      index: i, type: num(r.Type), property: num(r.Property), style: num(r.Style), maxStack: num(r.MaxStackCount), group: num(r.GroupIndex),
      description: cleanDesc(String(r.Description || '').replace(/\\/g, ' / ')), mapMoveDelete: num(r.MapMoveDelete), iconIndex: num(r.IconIndex),
      sendToOthers: num(r.SendToOthers), optionCount: num(r.OptionCount), options,
    });
  }

  // ---- image table (skill icons / status icons)
  const imageTable = new Map(); // "group:index" -> {texture, rect}
  for (const line of readText('script/ui/com/imagetable.txt').split(/\r?\n/)) {
    const p = line.split(',');
    if (p.length < 7) continue;
    const g = p[0].trim().toLowerCase();
    if (g !== 'skill_icon' && g !== 'buffer' && g !== 'buffer_b') continue;
    const i = num(p[1]); if (i === null) continue;
    const tex = gamePathToData('texture', p[2].trim());
    imageTable.set(`${g}:${i}`, { texture: tex, rect: [num(p[3]), num(p[4]), num(p[5]), num(p[6])] });
  }
  const icon = (group, i) => { const e = imageTable.get(`${group}:${i}`); return e ? { texture: e.texture, rect: e.rect } : null; };

  // ---- modeleffect.csv (code1 19 = status icon -> condition effects; 25 = action-record Effect ids; 41 = spell procs)
  const modelEffects = [];
  for (const r of parseCSV(readText('script/effect/modeleffect.csv')).slice(1)) {
    if (!r || String(r[0] ?? '').trim() === '') continue;
    const n = r.map(x => num(x));
    modelEffects.push({ code: [n[0], n[1], n[2], n[3]], effect: { cate: n[4], id: n[5], scene: n[6], timeMs: n[7], loop: n[8] }, combat: n[10] ? { cate: n[9], id: n[10], scene: n[11], timeMs: n[12], loop: n[13] } : null, note: String(r[14] ?? '').trim() });
  }
  const statusFx = new Map(); // iconIndex -> {start, keep, end}
  for (const m of modelEffects) if (m.code[0] === 19 && m.effect.id) {
    const ph = { 1: 'start', 2: 'keep', 3: 'end' }[m.code[3]] || `phase${m.code[3]}`;
    const o = statusFx.get(m.code[1]) || {};
    if (!o[ph]) o[ph] = { ...m.effect, ...(m.code[2] ? { variant: m.code[2] } : {}) };
    statusFx.set(m.code[1], o);
  }
  const pcActionFx = new Map(); // action-record Effect id -> effect (code1 25, code2 0 = PC)
  for (const m of modelEffects) if (m.code[0] === 25 && m.code[1] === 0 && m.effect.id && !pcActionFx.has(m.code[3])) pcActionFx.set(m.code[3], { ...m.effect, code3: m.code[2] });
  // creature-kind effect ids (code1 25): code2 = kind (0 pc, 1 monster, 2 servant, 8 totem ...), code3 = variant, code4 = id
  const kindFx = (kind, id, variant = null) => {
    const rows = modelEffects.filter(m => m.code[0] === 25 && m.code[1] === kind && m.code[3] === id);
    const m = variant !== null ? rows.find(x => x.code[2] === variant) : rows[0];
    return m ? { ...m.effect } : null;
  };
  const spellFx = {};
  for (const m of modelEffects) if (m.code[0] === 41) spellFx[m.code[1]] = { ...m.effect, note: m.note };
  // code1 21 = combat reactions (hit / block / dead / blood per material), 39 = game events (level up per class, revive,
  // hp/mp recovery, skill level up, target markers, enhancement results); rows kept as { code: [code2, code3, code4], effect, note }
  const modelRows = (c1) => modelEffects.filter(m => m.code[0] === c1 && m.effect.id).map(m => ({ code: m.code.slice(1), effect: { ...m.effect }, ...(m.note ? { note: m.note } : {}) }));
  const combatFx = modelRows(21), gameFx = modelRows(39);

  // ---- floating damage numbers (script/effect/damageeffect.csv: rows Alpha/Scale/Ypos/Zpos = (time 0..999, value) pairs)
  let damageText = null;
  if (has('script/effect/damageeffect.csv')) {
    damageText = { source: 'script/effect/damageeffect.csv' };
    for (const r of parseCSV(readText('script/effect/damageeffect.csv')).slice(1)) {
      const k = String(r[0] ?? '').trim(); if (!k) continue;
      const v = r.slice(1).map(x => String(x).trim()).filter(x => x !== '').map(Number);
      const key = k[0].toLowerCase() + k.slice(1);
      if (v.length === 1) damageText[key === 'time' ? 'timeMs' : key === 'criticaltime' ? 'criticalTimeMs' : key === 'criticalScale' ? 'criticalScale' : key] = v[0];
      else { const kf = []; for (let i = 0; i + 1 < v.length; i += 2) kf.push([v[i], v[i + 1]]); damageText[key] = kf; }
    }
  }

  // ---- misc skill tables
  const upgrade = new Map();
  for (const r of csvObjects(read('share/skill/skillupgrade.csv')).rows) {
    const i = num(r.Index); if (i === null) continue;
    if (!upgrade.has(i)) upgrade.set(i, []);
    upgrade.get(i).push({ level: num(r.Level), ratePct: num(r.Rate), priceDil: num(r.Price) });
  }
  const meister = new Map();
  for (const r of csvObjects(read('share/skill/skill_maister.csv')).rows) { const i = num(r.SkillIndex); if (i !== null) meister.set(i, { classWord: r.Class, autoLearn: num(r.AutoLearn), meisterGrade: num(r.MeisterGrade) }); }
  const moveSkills = new Map(); // class -> {1: [], 2: []}
  for (const r of csvObjects(read('script/skilldesc/moveskill.csv')).rows) {
    const c = num(r.Index), t = num(r.Type), s = num(r.Skillindex); if (c === null || s === null) continue;
    const o = moveSkills.get(c) || {}; (o[t] ??= []).push(s); moveSkills.set(c, o);
  }
  const transforms = new Map();
  const transformSource = read('share/skill/awakening/transform.csv');
  for (const r of csvObjects(transformSource).rows) {
    const i = num(r.SkillIndex); if (i === null) continue;
    if (!transforms.has(i)) transforms.set(i, []);
    const args = []; for (let k = 0; k < 16; k++) args.push(num(r[`Arg${k}`]) || 0);
    transforms.get(i).push({ level: num(r.SkillLevel), endEffect: num(r.DwEndEffectIndex), transType: num(r.TransType), args });
  }
  const shapeshift = new Map();
  for (const r of csvObjects(read('script/shape/shapeshift.csv')).rows) {
    const i = num(r.Index); if (i === null) continue;
    shapeshift.set(i, { index: i, mesh: gamePathToData('mesh', r.mesh), tpack: gamePathToData('texturepack', r.tpack), tier: num(r.tier) });
  }
  const transformCompatibility = supplementTransforms(transformSource, transforms, shapeshift, key => FILES.has(normPath(key)));
  const randomBuff = {};
  for (const r of csvObjects(read('share/skill/random_buff.csv')).rows) { const i = num(r.INDEX); if (i === null) continue; (randomBuff[i] ??= []).push({ count: num(r.COUNT), statusIndex: num(r.STATUS_INDEX) }); }
  const weaponStatus = {};
  {
    const t = csvObjects(read('share/skill/weaponstatus.csv'));
    for (const r of t.rows) {
      const i = num(r.INDEX); if (i === null) continue;
      const cells = t.header.map(h => r[h]);
      const o = {};
      for (let s = 1; s < cells.length; s++) { const v = num(cells[s]); if (v) o[s - 1] = v; }
      weaponStatus[i] = o;
    }
  }
  const statusGroups = {};
  for (const r of csvObjects(read('share/skill/statusgroup.csv')).rows) { const i = num(r.GroupIndex); if (i !== null) statusGroups[i] = { attribute: num(r.Attribute) }; }
  const statusEffectTable = csvObjects(read('share/skill/statuseffect.csv')).rows.map(r => {
    const c = Object.values(r).map(num);
    return { iconIndex: c[0], imageIndex: c[1], start: { id: c[2], scene: c[3], timeMs: c[4] }, keep: { id: c[5], scene: c[6] }, end: { id: c[7], scene: c[8], timeMs: c[9] } };
  });
  const statusDelete = csvObjects(read('share/skill/status_delete.csv')).rows.map(r => ({ itemIndex: num(r.Item_Index), statusGroup: num(r.Status_Group) }));

  // ---- aggro (share/ai/aggroaccount.csv: AggroCode -> ResultCode + up to 10 (Unit, Value) pairs; aggrosetting.csv globals;
  //      damageaggrocode.csv: class index -> default damage AggroCode 100xx)
  const aggroCodes = new Map();
  for (const r of csvObjects(read('share/ai/aggroaccount.csv')).rows) {
    const c = num(r.AggroCode); if (c === null) continue;
    const units = [];
    for (let k = 1; k <= 10; k++) { const u = num(r[`Unit_${k}`]), v = num(r[`Value_${k}`]); if (u) units.push([u, v]); }
    aggroCodes.set(c, { code: c, nameKor: String(r.Description || '').trim(), resultCode: num(r.ResultCode), units });
  }
  const aggroSettings = {};
  for (const r of csvObjects(read('share/ai/aggrosetting.csv')).rows) if (r.Type) aggroSettings[r.Type] = num(r.Value);
  const classDamageAggro = {};
  for (const r of csvObjects(read('share/ai/damageaggrocode.csv')).rows) { const i = num(r.Index), c = num(r.AggroCode); if (i !== null && c !== null) classDamageAggro[i] = c; }

  // ---- servants / totems (summons)
  const servantShapes = new Map(), totemShapes = new Map();
  for (const r of csvObjects(read('script/shape/servant_shape.csv')).rows) servantShapes.set(String(r.name).toLowerCase(), { mesh: gamePathToData('mesh', r.mesh), tpack: gamePathToData('texturepack', r.tpack) });
  for (const r of csvObjects(read('script/shape/totem_shape.csv')).rows) totemShapes.set(String(r.name).toLowerCase(), { index: num(r.index), mesh: gamePathToData('mesh', r.Mesh), tpack: gamePathToData('texturepack', r.Tpack) });
  const servantRows = new Map(parseTransposedCsv(read('share/creature/servant.csv')).map(r => [num(r.Index), r]));
  const totemRows = new Map(csvObjects(read('share/creature/totem.csv')).rows.map(r => [num(r.INDEX), r]));
  const servantActFiles = new Map();
  for (const k of FILES.keys()) { const m = /^share\/action\/action\/servant\/[^/]*\.act\.(\d+)\.dat$/.exec(k); if (m) servantActFiles.set(+m[1], k); }

  // ---- effects: parse every effectscene / effectdata file
  const effectsByKey = new Map();  // "cate:id" -> [effect per file] (visual files first)
  const effectFileOrder = ['01', '02', '03', 'com', 'map', 'snd'];
  for (const f of effectFileOrder) {
    const k = `property/effect/effectscene.${f}.txt`;
    if (!has(k)) { problems.push(`missing ${k}`); continue; }
    for (const e of parseEffectScenes(read(k), f)) {
      const key = `${e.cate}:${e.id}`;
      if (!effectsByKey.has(key)) effectsByKey.set(key, []);
      effectsByKey.get(key).push(e);
    }
  }
  const unitsByName = new Map(); // lower name -> [unit per file]
  for (const f of effectFileOrder) {
    const k = `property/effect/effectdata.${f}.txt`;
    if (!has(k)) { problems.push(`missing ${k}`); continue; }
    for (const u of parseEffectData(read(k), f)) {
      const n = u.name.toLowerCase();
      if (!unitsByName.has(n)) unitsByName.set(n, []);
      const l = unitsByName.get(n);
      if (!l.some(x => x.file === f)) l.push(u); // first definition per file wins (13 names repeat inside a file)
    }
  }
  const visualOf = (cate, id) => (effectsByKey.get(`${cate}:${id}`) || []).find(e => e.file !== 'snd') || null;
  const soundSceneOf = (cate, id) => (effectsByKey.get(`${cate}:${id}`) || []).find(e => e.file === 'snd') || null;

  // ---- per-class action tables (SKILL records)
  const classActions = new Map(); // class -> { clips: [], byKey: Map("style:index" -> clipIdx), fxRaw }
  for (const C of SKILL_CLASSES) {
    const k = `share/action/action/pc/${C.act}`;
    if (!has(k)) { problems.push(`class ${C.index}: missing action file ${k}`); classActions.set(C.index, { clips: [], byKey: new Map(), missing: [] }); continue; }
    const t = parseActionDat(read(k));
    if (t.trailingBytes) problems.push(`${k}: ${t.trailingBytes} trailing bytes`);
    const clips = [], clipIdx = new Map(), byKey = new Map(), missing = [], animless = new Map();
    const clipFields = (a) => {
      const clip = { timeLength: +a.timeLength.toFixed(4) };
      if (a.timing) clip.timing = +a.timing.toFixed(4);
      if (a.timing2) clip.timing2 = +a.timing2.toFixed(4);
      if (a.freeze) clip.freeze = +a.freeze.toFixed(4);
      if (a.cancelTime) clip.cancelTime = a.cancelTime;
      if (a.startInter) clip.startInter = +a.startInter.toFixed(4);
      if (a.endInter) clip.endInter = +a.endInter.toFixed(4);
      if (a.effect) { clip.effect = a.effect; const fx = pcActionFx.get(a.effect); if (fx) clip.actionEffect = { cate: fx.cate, id: fx.id, scene: fx.scene, timeMs: fx.timeMs, loop: fx.loop }; }
      return clip;
    };
    for (const rawAction of t.actions) {
      if (rawAction.actionId !== 10) continue;
      const animKey = repairedActionAnimationPath(k, rawAction.animKey, has);
      const a = animKey === rawAction.animKey ? rawAction : { ...rawAction, animKey };
      if (a !== rawAction) notes.push(`action ${k}: repaired animation ${rawAction.animKey} -> ${animKey}`);
      const key = `${a.style}:${a.index}`;
      if (byKey.has(key)) continue;
      if (!a.animKey || !has(a.animKey)) { if (a.animKey) missing.push({ style: a.style, index: a.index, anim: a.animKey }); if (!animless.has(key)) animless.set(key, a); continue; }
      const sig = `${a.animKey}|${+a.timeLength.toFixed(4)}|${+a.timing.toFixed(4)}|${a.effect}`;
      let ci = clipIdx.get(sig);
      if (ci === undefined) {
        ci = clips.length; clipIdx.set(sig, ci);
        clips.push({ anim: a.animKey, ...clipFields(a) });
      }
      byKey.set(key, ci);
    }
    // Native SKILL records whose animation file is in neither Global nor its backup (no record with an anim shares the
    // style:index key): keep their timing and action effect; the runtime plays no animation for them.
    const animlessActions = {};
    for (const [key, a] of animless) if (!byKey.has(key)) (animlessActions[a.index] ??= {})[a.style] = { anim: null,
      ...(a.animKey ? { missingAnim: `missing:${a.animKey}` } : {}), ...clipFields(a),
      compatibility: { kind: 'native-record-anim-absent', nativeDispatchVerified: false } };
    classActions.set(C.index, { clips, byKey, missing, animlessActions, skeleton: t.skelKey });
  }
  const resolveClip = (cls, style, actionIndex) => {
    const ca = classActions.get(cls);
    if (!ca) return null;
    const ci = ca.byKey.get(`${style}:${actionIndex}`);
    return ci === undefined ? null : ci;
  };

  // ---- skills
  const resultCtx = { remotes, statuses };
  const effectRefs = new Map();   // "cate:id" -> Set(where)
  const refEffect = (cate, id, where) => { if (!id) return; const k = `${cate}:${id}`; if (!effectRefs.has(k)) effectRefs.set(k, new Set()); effectRefs.get(k).add(where); };
  const fxRef = (id, scene, timeMs, where) => { if (!id) return null; refEffect(100, id, where); const o = { id, scene, timeMs }; return o; };
  const usedRemotes = new Set(), usedStatuses = new Set(), usedServants = new Set(), usedTotems = new Set(), usedAggro = new Set();
  const skills = {};
  const datFiles = [...FILES.keys()].filter(k => /^share\/skill\/skill\/\d+\.dat$/.test(k)).sort((a, b) => parseInt(a.split('/').pop()) - parseInt(b.split('/').pop()));
  const csvCompare = { fields: {}, skills: 0 };
  const cmp = (field, ok) => { const e = csvCompare.fields[field] ??= { ok: 0, total: 0 }; e.total++; if (ok) e.ok++; };
  const classSkillLists = new Map(SKILL_CLASSES.map(c => [c.index, []]));
  let comboStepsTotal = 0, stepsWithClipDefault = 0, stepsTotalForAnim = 0, stepsNoClip = [];

  const tabNames = new Map(); // class -> { normal: [names], pathA, pathB }
  for (const C of SKILL_CLASSES) {
    const base = (C.index + 1) * 100;
    // codes base..base+9 = "<center>Tab name" (skill tabs, then meister path A, path B); 111/112 are tooltip texts, not names
    const codes = [...strSkill.values()].filter(v => v.cate === 60 && v.code >= base && v.code < base + 10).sort((a, b) => a.code - b.code).map(v => cleanDesc(v.text));
    tabNames.set(C.index, { normal: codes.slice(0, Math.max(0, codes.length - 2)), pathA: codes[codes.length - 2] || null, pathB: codes[codes.length - 1] || null });
  }
  const attributeTabName = cleanDesc(strSkill.get('150:208')?.text || 'Attribute');
  const lifeTabName = cleanDesc(strSkill.get('150:209')?.text || 'Life');

  for (const key of datFiles) {
    const fileIndex = num(key.split('/').pop().replace('.dat', ''));
    let d;
    try { d = parseSkillDat(read(key)); } catch (e) { problems.push(`${key}: ${e.message}`); continue; }
    const h = d.head;
    if (h.index !== fileIndex) problems.push(`${key}: header index ${h.index} != file name`);
    const C = CLASS_BY_BIT.get(h.classMask);
    if (!C) { problems.push(`${key}: unknown class mask ${h.classMask}`); continue; }
    const idx = h.index;
    const ds = desc.get(idx);
    const ti = tableInfo.get(idx);
    const ctxName = `skill ${idx}`;

    // tree placement
    let window = 'skill', tabName = null, pathName = null, meisterPath = null;
    if (idx >= 3001) {
      window = 'meister';
      // Updated Grand Meister rows may move between paths while retaining their
      // old skill IDs/names. An exclusive authored A/B limit is the access rule.
      meisterPath = h.maxA > 0 && h.maxB === 0 ? 'A' : h.maxB > 0 && h.maxA === 0 ? 'B' : ((idx - 3001) % 60) < 30 ? 'A' : 'B';
      pathName = meisterPath === 'A' ? tabNames.get(C.index).pathA : tabNames.get(C.index).pathB;
      tabName = pathName;
    } else if (h.iconTab === 10) { window = 'attribute'; tabName = attributeTabName; }
    else if (h.iconTab === 11) { window = 'life'; tabName = lifeTabName; }
    else tabName = tabNames.get(C.index).normal[h.iconTab - 1] || null;
    // mirrors of the attribute page (tab 10 skills of meister indices) keep window 'meister' but tab 10

    // allowed weapon styles
    const styles = d.styles.slice();
    const typeFlags = Object.entries(TYPE_BITS).filter(([b]) => h.typeMask & +b).map(([, n]) => n);
    const targets = Object.keys(TARGET_BITS).map(Number).filter(b => h.target & b);
    const maxLevel = Math.max(h.maxNormal, h.maxA, h.maxB, 0);

    // levels
    const levels = [];
    const actionKeys = new Set();
    for (let L = 1; L <= Math.min(15, Math.max(maxLevel, h.levelCount - 1)); L++) {
      const lv = d.levels[L];
      const steps = [];
      if (lv.end >= lv.start && !(lv.start === 0 && lv.end === 0 && !d.combos[0].resultCode && !d.combos[0].timeTick)) {
        for (let c = lv.start; c <= lv.end && c < SKILL_DAT.COMBOS; c++) {
          const cb = d.combos[c];
          if (!cb.actionType && !cb.timeTick && !cb.resultCode && !cb.effectId && !cb.resultEffectId && !cb.actionIndex) continue; // padding row
          const step = { combo: c, type: COMBO_ACTION_TYPES[cb.actionType] || `TYPE_${cb.actionType}`, style: cb.style, actionIndex: cb.actionIndex, durationMs: cb.timeTick };
          if (cb.effectId) step.effect = fxRef(cb.effectId, cb.sceneId, cb.effectTime, ctxName);
          if (cb.resultCode) {
            const r = describeResult(cb.resultCode, cb.args, resultCtx);
            if (cb.pvpRate) r.pvpDamageRate = cb.pvpRate;
            if (cb.aggro) { r.aggro = cb.aggro; usedAggro.add(cb.aggro); if (!aggroCodes.has(cb.aggro)) problems.push(`${ctxName} L${L}: aggro code ${cb.aggro} not in share/ai/aggroaccount.csv`); }
            if (cb.defeat) r.defeat = cb.defeat;
            if (cb.resultEffectId) {
              const recovered = recoverAlokenHitCategory({ skill: idx, classIndex: C.index, resultCode: cb.resultCode,
                id: cb.resultEffectId, scene: cb.resultSceneId, timeMs: cb.resultEffectTime }, { effectsByKey, unitsByName, has });
              if (recovered) { r.hitEffect = recovered; refEffect(recovered.cate, recovered.id, ctxName); }
              else r.hitEffect = fxRef(cb.resultEffectId, cb.resultSceneId, cb.resultEffectTime, ctxName);
            }
            if (r.remoteIndex) usedRemotes.add(r.remoteIndex);
            if (r.statusIndex) usedStatuses.add(r.statusIndex);
            if (r.statusIndex2) usedStatuses.add(r.statusIndex2);
            if (r.dotStatusIndex) usedStatuses.add(r.dotStatusIndex);
            if (r.servantIndex) usedServants.add(r.servantIndex);
            if (r.totemIndex) usedTotems.add(r.totemIndex);
            if (r.remoteMissing) problems.push(`${ctxName} L${L}: remote ${r.remoteIndex} not in remote.csv`);
            if (r.statusMissing) notes.push(`${ctxName} L${L}: status ${r.statusIndex} not in status.csv`);
            step.result = r;
          } else if (cb.resultEffectId) step.hitEffect = fxRef(cb.resultEffectId, cb.resultSceneId, cb.resultEffectTime, ctxName);
          if (cb.actionType || cb.timeTick) { actionKeys.add(`${cb.style}:${cb.actionIndex}`); comboStepsTotal++; }
          steps.push(step);
        }
      }
      const reqs = lv.reqs.filter(r => r.skill).map(r => ({ skill: r.skill, level: r.level }));
      const options = lv.options.filter(o => o.code || o.value).map(o => ({ code: optionCodes[o.code]?.name || String(o.code), id: o.code, value: o.value }));
      const rs = steps.filter(s => s.result).map(s => s.result);
      const hitsR = rs.filter(r => r.addDamage !== undefined);
      const level = {
        level: L, reqLevel: lv.pcLevel, spCost: lv.sp, mp: lv.mp, hp: lv.hp, fury: lv.fury, castMs: lv.cast, cooldownMs: lv.cooldown,
        combos: [lv.start, lv.end],
        ...(lv.grade ? { grade: lv.grade } : {}), ...(lv.choiceLimit ? { choiceLimit: lv.choiceLimit } : {}),
        prereqs: reqs,
        ...(options.length ? { options } : {}),
        hits: hitsR.length,
        addDamage: hitsR.map(r => r.addDamage),
        ...(rs.some(r => r.statusIndex) ? { statuses: rs.filter(r => r.statusIndex).map(r => ({ statusIndex: r.statusIndex, chance: r.chance ?? null, durationMs: r.durationMs ?? r.statusDurationMs ?? null })) } : {}),
        ...(rs.some(r => r.amount !== undefined) ? { heal: rs.filter(r => r.amount !== undefined).map(r => ({ amount: r.amount, perSpr: r.perSpr ?? 0 })) } : {}),
        steps,
        availability: L <= h.maxNormal ? 'all' : (L <= h.maxA && L <= h.maxB ? 'path A or B' : (L <= h.maxA ? 'path A' : (L <= h.maxB ? 'path B' : 'none'))),
      };
      if (lv.itemCode || lv.itemCount) level.resourceItem = { itemCode: lv.itemCode, count: lv.itemCount };
      if (lv.unk82) level.raw = { unk82: lv.unk82 };
      if (ds?.levels.get(L) && ds.levels.get(L) !== ds.levels.get(1)) level.description = ds.levels.get(L);
      levels.push(level);
      for (const o of lv.options) if (o.code && !optionCodes[o.code]) notes.push(`option code ${o.code} has no name in stringtable_com <cate> 200 nor in a CSV twin (first seen: ${ctxName})`.replace(/ \(first seen.*$/, ''));
    }

    // ready / charge
    const actObj = (a, what) => {
      if (!a.actionIndex && !a.effectId && !a.timeTick) return null;
      const o = { style: a.style, actionIndex: a.actionIndex, durationMs: a.timeTick };
      if (a.actionType) o.type = COMBO_ACTION_TYPES[a.actionType] || a.actionType;
      if (a.effectId) o.effect = fxRef(a.effectId, a.sceneId, a.effectTime, `${ctxName} ${what}`);
      if (a.actionIndex || a.timeTick) actionKeys.add(`${a.style}:${a.actionIndex}`);
      return o;
    };
    const ready = actObj(h.ready, 'ready'), charge = actObj(h.charge, 'charge');

    // animation resolution report: for each (style, actionIndex) the clip for each allowed style
    const animStyles = [...new Set([...styles.filter(s => s > 0), 1, 0])];
    const actions = {};
    for (const k of actionKeys) {
      const [st, ai] = k.split(':').map(Number);
      const byStyle = {};
      const tryStyles = st === 255 ? animStyles : [st, ...animStyles];
      for (const s of tryStyles) { const ci = resolveClip(C.index, s, ai); if (ci !== null && !(s in byStyle)) byStyle[s] = ci; }
      actions[k] = byStyle;
      if (!Object.keys(byStyle).length && (ai || st !== 0)) stepsNoClip.push(`${idx}:${k}`);
    }

    // level-1 compat view (same field names as classes.json skills)
    const l1 = levels.find(l => l.reqLevel > 0 || l.steps.length) || levels[0] || null;
    const results = (l1?.steps || []).filter(s => s.result).map(s => s.result);
    const main = results.find(r => r.kind === 'damage' || r.kind === 'projectile') || results[0];
    const ktype = (r) => {
      if (!r) return typeFlags.includes('ACTION') ? 'other' : 'passive';
      if (r.kind === 'damage' || r.kind === 'projectile') return r.damageClass || (C.code === 'ARC' || C.code === 'SHT' ? 'range' : 'magic');
      if (r.kind === 'status') return r.target === 'self' ? 'buff' : 'status';
      return r.kind;
    };
    const tr = transforms.get(idx);
    const skill = {
      index: idx, class: C.index, classCode: C.code,
      name: (ds?.name || '').trim() || ti?.nameKor || `Skill ${idx}`, nameKor: ti?.nameKor || csvByIndex.get(idx)?.[0]?.kv?.Name || null,
      code: ti?.code || null, hidden: !ds,
      weaponReq: ds?.weapon ? ds.weapon.trim() : null, description: ds?.levels.get(1) || ds?.levels.values().next().value || '',
      typeFlags, typeMask: h.typeMask, kind: typeFlags.includes('ACTION') ? 'active' : (typeFlags.includes('MASTERY') ? 'mastery' : (typeFlags.includes('PASSIVE') ? 'passive' : 'other')),
      pointType: POINT_TYPES[h.pointType ?? 1] || h.pointType,
      type: ktype(main),
      target: targets, targetMask: h.target, range: h.distance, avail: h.avail,
      tree: { window, tab: h.iconTab, tabName, x: h.iconX, y: h.iconY, ...(meisterPath ? { path: meisterPath, pathName, tier: h.iconTab === 3 || h.iconTab === 4 ? 'grand_meister' : h.iconTab === 10 ? 'attribute' : 'meister' } : {}), table: ti?.category || null },
      icon: icon('skill_icon', h.iconIndex), iconDisabled: icon('skill_icon', 10000 + h.iconIndex), iconIndex: h.iconIndex,
      maxLevel: { normal: h.maxNormal, a: h.maxA, b: h.maxB }, levelCount: h.levelCount,
      styles, styleNames: styles.map(s => STYLE_NAMES[s] || `STYLE_${s}`),
      ...(ready ? { ready } : {}), ...(charge ? { charge } : {}),
      ...(h.awakening ? { awakeningCheck: h.awakening } : {}), ...(h.needType ? { needType: h.needType, needVars: h.vars } : (h.vars.some(Boolean) ? { vars: h.vars } : {})),
      reqLevel: l1?.reqLevel ?? null, mpCost: l1?.mp ?? 0, hpCost: l1?.hp ?? 0, furyCost: l1?.fury ?? 0, cooldownMs: l1?.cooldownMs ?? 0, castMs: l1?.castMs ?? 0,
      prereq: l1?.prereqs?.[0] ? { skillIndex: l1.prereqs[0].skill, level: l1.prereqs[0].level } : null,
      hits: l1?.hits ?? 0, addDamage: (l1?.addDamage || []).reduce((s, v) => s + (v || 0), 0),
      steps: l1?.steps || [],
      actions,
      levels,
      ...(upgrade.has(idx) ? { upgrade: upgrade.get(idx) } : {}),
      ...(meister.has(idx) ? { meister: meister.get(idx) } : {}),
      ...(tr ? { transform: tr.map(t => ({ ...t, shapeshift: shapeshift.get(t.args[0]) || null })) } : {}),
      ...(weaponStatus[idx] && h.typeMask !== 16 ? { weaponStatus: weaponStatus[idx] } : {}),
      source: key,
    };
    if (h.unk12272) skill.raw = { unk12272: h.unk12272 };
    if (!skill.icon) notes.push(`${ctxName}: no skill_icon sprite for IconIndex ${h.iconIndex}`);
    skills[idx] = skill;
    classSkillLists.get(C.index).push(idx);

    // ---- cross-check against the legacy CSV twin (same index and class flag)
    const twins = (csvByIndex.get(idx) || []).filter(p => !C.csvFlag || p.kv.PCClassFlag === C.csvFlag);
    if (twins.length === 1) {
      const p = twins[0];
      csvCompare.skills++;
      cmp('Distance', num(p.kv.Distance) === h.distance);
      cmp('IconIndex', num(p.kv.IconIndex) === h.iconIndex);
      cmp('IconTabIndex', num(p.kv.IconTabIndex) === h.iconTab);
      cmp('Target', String(p.kv.Target || '').split(/\s+/).filter(Boolean).reduce((m, v) => m | +v, 0) === h.target);
      cmp('TypeFlag', (p.kv.TypeFlag === 'ACTION' || p.kv.TypeFlag === 'CAST' || p.kv.TypeFlag === 'POWERUP') ? h.typeMask === 16 : p.kv.TypeFlag === 'MASTERY' ? h.typeMask === 2 : p.kv.TypeFlag === 'PASSIVE' ? h.typeMask === 1 : p.kv.TypeFlag === 'ACTION NOTSAVE' ? h.typeMask === 20 : false);
      cmp('MaxStyleCode', num(p.kv.MaxStyleCode) === h.styleCount);
      for (const lv of p.levels) {
        const L = num(lv.main.LevelIndex); if (!L || L > 15) continue;
        const b = d.levels[L];
        if (num(lv.main.PCLevel) !== null) cmp('PCLevel', num(lv.main.PCLevel) === b.pcLevel);
        cmp('CoolTick', num(lv.main.CoolTick) === b.cooldown);
        cmp('CastTick', num(lv.main.CastTick) === b.cast);
        cmp('ResourceMP', num(lv.main.ResourceMP) === b.mp);
        cmp('ResourceHP', num(lv.main.ResourceHP) === b.hp);
        cmp('StartComboIndex', num(lv.main.StartComboIndex) === b.start);
        cmp('EndComboIndex', num(lv.main.EndComboIndex) === b.end);
      }
      for (const cr of p.combos) {
        const c = num(cr.ComboIndex); if (c === null || c >= 150) continue;
        const b = d.combos[c];
        cmp('ResultCode', num(cr.ResultCode) === b.resultCode);
        cmp('Arg3', num(cr.Arg3) === b.args[2]);
        cmp('ActionIndex', num(cr.ActionIndex) === b.actionIndex);
        cmp('TimeTick', num(cr.TimeTick) === b.timeTick);
        cmp('EffectID', num(cr.EffectID) === b.effectId);
        cmp('ResultEffectID', num(cr.ResultEffectID) === b.resultEffectId);
      }
    }
  }
  // CSV-only (removed from the compiled data) skills
  const legacyOnly = [];
  for (const [i, list] of csvByIndex) if (!skills[i]) for (const p of list) legacyOnly.push({ index: i, file: p.file, classFlag: p.kv.PCClassFlag, typeFlag: p.kv.TypeFlag, nameKor: p.kv.Name });

  // ---- per-class structure
  const classes = SKILL_CLASSES.map(C => {
    const ca = classActions.get(C.index);
    const skillActions = {};
    for (const [k, ci] of ca.byKey) { const [s, i] = k.split(':'); (skillActions[i] ??= {})[s] = ci; }
    const list = classSkillLists.get(C.index);
    const tn = tabNames.get(C.index);
    const tabs = {};
    for (const i of list) { const s = skills[i]; const tk = `${s.tree.window}:${s.tree.tab}${s.tree.path ? ':' + s.tree.path : ''}`; (tabs[tk] ??= { window: s.tree.window, tab: s.tree.tab, name: s.tree.tabName, path: s.tree.path || null, skills: [] }).skills.push(i); }
    const ms = moveSkills.get(C.index) || {};
    return {
      index: C.index, code: C.code, name: pc.name_kor?.[C.index] || null, classBit: C.bit, skillDesc: `script/skilldesc/${C.desc}.csv`,
      actionFile: `share/action/action/pc/${C.act}`, skeleton: ca.skeleton || null,
      tabNames: tn, tabs: Object.values(tabs).sort((a, b) => a.window.localeCompare(b.window) || a.tab - b.tab || String(a.path).localeCompare(String(b.path))),
      moveSkills: { A: ms[1] || [], B: ms[2] || [] },
      skills: list,
      clips: ca.clips, skillActions,
      missingClips: ca.missing.length,
      ...(Object.keys(ca.animlessActions || {}).length ? { animlessActions: ca.animlessActions } : {}),
    };
  });

  // ---- remotes / statuses / servants / totems referenced
  const remotesOut = {};
  const addRemote = (i) => {
    const r = remotes.get(i); if (!r || remotesOut[i]) return;
    const o = { ...r };
    for (const k of ['effect', 'contactEffect', 'piercingEffect']) { if (!o[k].id) delete o[k]; else refEffect(100, o[k].id, `remote ${i}`); }
    if (o.warningEffect) refEffect(o.warningEffect.cate, o.warningEffect.id, `remote ${i}`); else delete o.warningEffect;
    o.impact = o.resultType ? describeResult(o.resultType, [0, 0, 0, 0, 0, 0, 0, 0], resultCtx) : null;
    if (o.impact) { delete o.impact.args; }
    remotesOut[i] = o;
  };
  for (const i of usedRemotes) addRemote(i);
  // Native Siege sentries have their attacks in sentry.csv, outside the player
  // skill graph. Keep their projectile definitions in the shared runtime pack.
  for (const i of [1, 601, 602, 603, 604, 605, 606, 607]) addRemote(i);
  // servants
  const servantsOut = {};
  const servantAnims = (i) => {
    const k = servantActFiles.get(i);
    if (!k) return null;
    const t = parseActionDat(read(k));
    const pick = (action, index = 0) => t.actions.find(a => a.actionId === action && a.index === index && a.animKey && has(a.animKey)) || t.actions.find(a => a.actionId === action && a.animKey && has(a.animKey));
    const out = { actionFile: k, skeleton: t.skelKey && has(t.skelKey) ? t.skelKey : null, anims: {} };
    for (const [name, act] of [['stand', 1], ['move', 2], ['attack', 6], ['hit', 7], ['die', 8], ['skill', 10]]) {
      const a = pick(act); if (a) out.anims[name] = { anim: a.animKey, index:a.index, style:a.style, effect:a.effect||0, timeLength: +a.timeLength.toFixed(4), ...(a.timing ? { timing: +a.timing.toFixed(4) } : {}) };
    }
    const atk = t.actions.filter(a => a.actionId === 6 && a.animKey && has(a.animKey)).map(a => ({ index: a.index, style:a.style, effect:a.effect||0, anim: a.animKey, timeLength: +a.timeLength.toFixed(4), timing: +a.timing.toFixed(4) }));
    if (atk.length) out.attacks = atk;
    return out;
  };
  for (const i of [...usedServants].sort((a, b) => a - b)) {
    const r = servantRows.get(i);
    if (!r) { problems.push(`servant ${i} referenced by a skill is not in servant.csv`); continue; }
    const shape = servantShapes.get(String(r.ShapeInfo || '').toLowerCase()) || null;
    const numeric = {}; for (const [k, v] of Object.entries(r)) { const n = num(v); numeric[k] = n === null ? v : n; }
    const o = { index: i, name: r.Name, tab: r.Tab, level: num(r.Level), maxHp: num(r.MaxHP), shapeInfo: r.ShapeInfo, shape, ...servantAnims(i) };
    for(const id of new Set([...Object.values(o.anims||{}),...(o.attacks||[])].map(a=>a.effect).filter(Boolean))){
      const matches=modelEffects.filter(m=>m.code[0]===25&&m.code[1]===2&&m.code[2]===1&&m.code[3]===id&&m.effect.id);
      const refs=new Map(matches.map(m=>[JSON.stringify(m.effect),m.effect]));
      if(refs.size!==1){problems.push(`servant ${i}: action Effect ${id} needs one unambiguous modeleffect25/2/1 mapping; found ${refs.size}`);continue;}
      const ref=[...refs.values()][0];refEffect(ref.cate,ref.id,`servant ${i} action ${id}`);
    }
    // LeaveEffectID is a direct skill-effect id; EnterEffectID / StatusEffectID go through modeleffect.csv (25, 2 = servant, *, id)
    if (num(r.LeaveEffectID)) { o.leaveEffect = { cate: 100, id: num(r.LeaveEffectID), scene: num(r.LeaveSceneID), timeMs: num(r.LeaveEffectTime) }; refEffect(100, o.leaveEffect.id, `servant ${i}`); }
    // Native modeleffect keys distinguish entry (code3=0) from status (code3=1).
    for (const [k, col, variant] of [['enterEffect', 'EnterEffectID', 0], ['statusEffect', 'StatusEffectID', 1]]) {
      const id = num(r[col]); if (!id) continue;
      const matches = modelEffects.filter(m => m.code[0] === 25 && m.code[1] === 2 && m.code[2] === variant && m.code[3] === id && m.effect.id);
      if (matches.length !== 1) {
        problems.push(`servant ${i}: ${col} ${id} needs one modeleffect.csv row (25,2,${variant},${id}); found ${matches.length}`);
        continue;
      }
      o[k] = { ...matches[0].effect };
      refEffect(o[k].cate, o[k].id, `servant ${i}`);
    }
    o.iconIndex = num(r.IconIndex);
    o.raw = numeric;
    servantsOut[i] = o;
  }
  const totemsOut = {};
  for (const i of [...usedTotems].sort((a, b) => a - b)) {
    const r = totemRows.get(i);
    if (!r) { problems.push(`totem ${i} referenced by a skill is not in totem.csv`); continue; }
    const numeric = {}; for (const [k, v] of Object.entries(r)) { const n = num(v); numeric[k] = n === null ? v : n; }
    const shape = totemShapes.get(String(r.SHAPEINFO || '').toLowerCase()) || null;
    const aura = num(r.RESULTCODE_1) ? describeResult(num(r.RESULTCODE_1), [1, 2, 3, 4, 5, 6, 7].map(k => num(r[`ARG_${k}`]) || 0).concat([0]), resultCtx) : null;
    if (aura?.statusIndex) usedStatuses.add(aura.statusIndex);
    const o = { index: i, name: r.NAME, level: num(r.LEVEL), maxHp: num(r.MAXHP), shapeInfo: r.SHAPEINFO, shape, aura, lifeSec: num(r.TOTALTIME), tickMs: num(r.FLUSHTIME), iconIndex: num(r.ICONINDEX) };
    if (num(r.LEAVEEFFECTID)) { o.leaveEffect = { cate: 100, id: num(r.LEAVEEFFECTID), scene: num(r.LEAVESCENEID), timeMs: num(r.LEAVEEFFECTTIME) }; refEffect(100, o.leaveEffect.id, `totem ${i}`); }
    // modeleffect.csv (25, 8 = totem, variant 0 stand / 1 die, totem_shape index)
    const shapeIdx = totemShapes.get(String(r.SHAPEINFO || '').toLowerCase())?.index;
    for (const [k, variant] of [['standEffect', 0], ['dieEffect', 1]]) {
      const fx = shapeIdx ? kindFx(8, shapeIdx, variant) : null;
      if (fx) { o[k] = fx; refEffect(fx.cate, fx.id, `totem ${i}`); }
    }
    o.raw = numeric;
    totemsOut[i] = o;
  }
  // statuses referenced by skills / servants / random buffs
  for (const g of Object.values(randomBuff)) for (const e of g) usedStatuses.add(e.statusIndex);
  for (const w of Object.values(weaponStatus)) for (const v of Object.values(w)) usedStatuses.add(v);

  // ---- status json
  const statusOut = {}, statusIcons = {};
  for (const [i, s] of statuses) {
    const o = { ...s };
    const fx = statusFx.get(s.iconIndex);
    if (fx) { o.effects = fx; for (const ph of Object.values(fx)) refEffect(ph.cate, ph.id, `status icon ${s.iconIndex}`); }
    if (s.iconIndex && !statusIcons[s.iconIndex]) {
      const small = icon('buffer', s.iconIndex), large = icon('buffer_b', s.iconIndex);
      if (small || large) statusIcons[s.iconIndex] = { ...(small ? { small } : {}), ...(large ? { large } : {}) };
      else notes.push(`status icon ${s.iconIndex} has no buffer/buffer_b sprite`);
    }
    statusOut[i] = o;
  }
  for (const i of usedStatuses) if (!statuses.has(i)) notes.push(`status ${i} referenced but not in status.csv`);
  for (const fx of Object.values(spellFx)) refEffect(fx.cate, fx.id, 'spell proc');
  for (const [id, fx] of pcActionFx) refEffect(fx.cate, fx.id, `pc action effect ${id}`);
  for (const r of combatFx) refEffect(r.effect.cate, r.effect.id, 'modeleffect 21 (combat)');
  for (const r of gameFx) refEffect(r.effect.cate, r.effect.id, 'modeleffect 39 (game event)');
  for (const r of statusEffectTable) { refEffect(11, r.keep.id, 'statuseffect.csv'); refEffect(11, r.start.id, 'statuseffect.csv'); refEffect(11, r.end.id, 'statuseffect.csv'); }

  // ---- effect library
  const texCache = new Map(), tpackCache = new Map();
  const effectAsset = (root, p, u) => {
    const original = gamePathToData(root, p); if (!original || has(original)) return original;
    const repaired = repairedEffectPath(`${u.file}:${u.name}`, original);
    if (!repaired || !has(repaired)) return original;
    notes.push(`effect unit ${u.name}: repaired native asset ${original} -> ${repaired}`);
    return repaired;
  };
  const resolver = {
    texture: (p, u) => {
      const raw = normPath(p); if (!raw) return null;
      if (texCache.has(raw)) return texCache.get(raw);
      const direct = raw.startsWith('texture/') ? raw : `texture/${raw}`;
      let k = has(direct) ? direct : null;
      if (!k) {
        const dir = direct.slice(8, direct.lastIndexOf('/'));
        k = textureCandidates(dir, direct.slice(direct.lastIndexOf('/') + 1), { index: texIndex }).find(has) || null;
        if (k) notes.push(`effect unit ${u.name}: texture ${p} -> ${k}`);
        else miss('texture', direct, u.name);
      }
      texCache.set(raw, k);
      return k;
    },
    tpack: (p, u, asMaterials = false) => {
      const key = effectAsset('texturepack', p, u); if (!key) return null;
      const ck = `${key}|${asMaterials}`;
      if (tpackCache.has(ck)) return tpackCache.get(ck);
      if (!has(key)) { miss('tpack', key, u.name); tpackCache.set(ck, null); return null; }
      const tp = parseTpack(read(key));
      const resolve = (file) => {
        const c = textureCandidates(tp.texdir, file, { index: texIndex });
        const k = c.find(has);
        if (!k) miss('texture', c[0], `${u.name} via ${key}`);
        return k || null;
      };
      let out;
      if (asMaterials) out = { key, textures: tp.slots.map(s => ({ material: s, diffuse: resolve(tp.diffuse[s]), ...(tp.specular[s] ? { specular: resolve(tp.specular[s]) } : {}) })) };
      else out = { key, frames: tp.slots.map(s => resolve(tp.diffuse[s])) };
      tpackCache.set(ck, out);
      return out;
    },
    path: (root, p, u) => {
      const k = effectAsset(root, p, u); if (!k) return null;
      if (!has(k)) { miss(root, k, u.name); return null; }
      return k;
    },
    sound: (f, u) => {
      const n = normPath(f);
      const cands = [`sound/${n}`, `sound/skill/${n}`, `sound/effect/${n}`];
      for (const c of cands) if (has(c)) return c;
      const b = n.slice(n.lastIndexOf('/') + 1);
      const k = soundByBase.get(b) || soundByBase.get(b.endsWith('.wav') ? b : `${b}.wav`);
      if (!k) miss('sound', `sound/${n}`, u.name);
      return k || null;
    },
  };
  const wantCates = new Set([100, 11, 6]);
  const emitKeys = new Set([...effectRefs.keys()]);
  for (const k of effectsByKey.keys()) if (wantCates.has(+k.split(':')[0])) emitKeys.add(k);
  const scenesOut = {}, unitsOut = {}, unitRefs = new Map();
  const compatibilityRepairs = [];
  let escanaBackupUnits;
  const unitFor = (name, file, sceneKey) => {
    const l = unitsByName.get(String(name).toLowerCase());
    if (l?.length) return l.find(u => u.file === file) || l.find(u => u.file !== 'snd') || l[0];
    const recovered = recoverEscanaUnit(name, file, sceneKey,
      () => escanaBackupUnits ??= parseEffectData(read(ESCANA_BACKUP_SOURCE), '01.bak'), has);
    if (recovered) compatibilityRepairs.push({ scene: sceneKey, unit: recovered.name,
      source: ESCANA_BACKUP_SOURCE, kind: 'original-backup-unit',
      note: 'Exact shipped backup definition; current scene controls retained. Native backup-table loading is unverified.' });
    return recovered;
  };
  const unresolvedEffectRefs = [], missingEffects = {};
  for (const k of [...emitKeys].sort((a, b) => { const [ca, ia] = a.split(':').map(Number), [cb, ib] = b.split(':').map(Number); return ca - cb || ia - ib; })) {
    const [cate, id] = k.split(':').map(Number);
    const e = visualOf(cate, id);
    const snd = soundSceneOf(cate, id);
    if (!e && !snd) { if (effectRefs.has(k)) { unresolvedEffectRefs.push(`${k} (${[...effectRefs.get(k)].slice(0, 3).join(', ')})`); missingEffects[k] = [...effectRefs.get(k)].slice(0, 10); } continue; }
    const o = { cate, id, name: (e || snd).name, file: e ? e.file : null };
    if (e) {
      o.res = {};
      for (const [slot, name] of Object.entries(e.res)) {
        const u = unitFor(name, e.file, k);
        if (!u) { o.res[slot] = { name, missing: true }; continue; }
        const uk = `${u.file}:${u.name.toLowerCase()}`;
        o.res[slot] = uk;
        if (!unitsOut[uk]) unitsOut[uk] = { name: u.name, ...describeUnit(u, resolver) };
        unitRefs.set(uk, (unitRefs.get(uk) || 0) + 1);
      }
      o.scenes = {};
      for (const s of e.scenes) {
        const controls = s.controls.map(describeControl);
        for (const c of controls) if (c.boneAnim) {
          for (const kk of ['skel', 'anim']) {
            const original = c.boneAnim[kk];
            const p = repairedBoneAnimationPath(k, original, has);
            if (p !== original) { c.boneAnim[kk] = p; notes.push(`effect ${k}: repaired bone animation ${original} -> ${p}`); }
            if (p && !has(p)) { miss(kk, p, `${k} control ${c.unit}`); (c.boneAnim.missing ??= []).push(`missing:${p}`); c.boneAnim[kk] = null; }
          }
        }
        o.scenes[s.sceneId] = { name: s.name, controls };
      }
    }
    if (snd) o.soundScenes = Object.fromEntries(snd.scenes.map(s => [s.sceneId, s.name]));
    if (effectRefs.has(k)) o.refs = effectRefs.get(k).size;
    scenesOut[k] = o;
  }

  // ---- json documents
  const now = new Date().toISOString();
  const skillsJson = {
    version: 1, generatedBy: 'tools/build-skills.mjs', generatedAt: now,
    transformCompatibility,
    paths: 'All asset paths are data-root-relative keys (lower case, "/" separators): fetch /data/<key>, URL-encoding each segment (names contain "#").',
    sources: ['share/skill/skill/<index>.dat (authoritative compiled tables, all 15 classes)', 'script/skilldesc/*.csv (English names/texts)', 'share/skill/skilltable.csv', 'share/action/action/pc/*.act.N.dat (SKILL records = action 10)', 'share/creature/remote.csv', 'share/creature/servant.csv', 'share/creature/totem.csv', 'share/skill/{skillupgrade,skill_maister,random_buff,weaponstatus}.csv', 'share/skill/awakening/transform.csv', 'script/shape/shapeshift.csv', 'script/string/normal/stringtable_skill.txt', 'script/string/stringtable_com.txt (<cate> 200 option codes)', 'script/ui/com/imagetable.txt (skill_icon)', 'share/ai/{aggroaccount,aggrosetting,damageaggrocode}.csv'],
    conventions: {
      levels: 'levels[L-1] = skill level L (1..max). reqLevel = character level needed; spCost = SPCostLevelUp, the skill (or attribute, see pointType) points this level costs (0 = free: level 1 of normal skills, every meister level); grade = required trans-up (awakening) grade, choiceLimit = CSV ChoiceLimit (trans-up skills only, kept raw); availability = which characters can reach the level: maxLevel.normal for everyone, up to maxLevel.a / maxLevel.b only after choosing meister path A / B (docs/formats/skills.md). mp/hp/fury = resource cost per cast, castMs = cast time, cooldownMs = cooldown.',
      steps: 'steps = the combo rows StartComboIndex..EndComboIndex of the level, played in order. Each step plays animation (style, actionIndex) for durationMs (TimeTick); style 255 = the currently equipped weapon style. Resolve the clip with classes[c].skillActions[actionIndex][style] -> classes[c].clips[i] (skill.actions lists the pre-resolved clip per allowed style); classes[c].animlessActions[actionIndex][style] holds native SKILL records whose anim file is absent from Global (timing and action effect only, anim null). type NO_CANCEL = the step cannot be interrupted; ACTION = cancellable. result = what the step does when it lands; effect = visual on the caster at step start; result.hitEffect = visual on each unit hit.',
      effects: 'effect/hitEffect {id, scene, timeMs} are effect-scene ids of category 100 (skill) in gamedata/skills_effects.json scenes["100:<id>"]; play scene <scene> for timeMs. Sounds for the same id: gamedata/sound.json skill["<id>"].scenes["<scene>"].',
      results: 'result = describeResult(resultCode, Arg1..Arg8): radius already divided by 128 (world units = metres); addDamage = flat bonus added to the attack; chance in %; statusIndex -> gamedata/skills_status.json; durations in ms; args keeps the raw values. resultCodes lists every family with its argument layout and confidence.',
      icons: 'icon / iconDisabled = sprite {texture, rect:[x,y,w,h]} from imagetable group skill_icon (index = IconIndex, disabled = 10000 + IconIndex).',
      tree: 'tree.window: skill (normal skill window, tab 1..N named by tabName), attribute (tab 10, spent with attribute points), life (tab 11: fishing, commission sale, vehicle), meister (skills >= 3001, per path A/B; tab 1/2 = Meister skills of path A/B, 3/4 = Grand Meister skills, 10 = meister attribute masteries; tree.tier). x/y = icon cell in the tab grid.',
      aggro: 'result.aggro = AggroCode -> aggro.codes (hostility the step generates, see aggro.note).',
    },
    enums: { styleNames: STYLE_NAMES, comboActionTypes: COMBO_ACTION_TYPES, typeBits: TYPE_BITS, targetBits: TARGET_BITS, pointTypes: POINT_TYPES, damageTypes: DAMAGE_TYPES, elementAreaPairs: ELEMENT_AREA_PAIRS },
    resultCodes: Object.fromEntries(RESULT_FAMILIES.map(f => [f.family, { pattern: f.re.source, kind: f.kind, layout: f.layout, confidence: f.confidence, ...(f.note ? { note: f.note } : {}) }])),
    optionCodes,
    classes,
    skills,
    remotes: remotesOut,
    servants: servantsOut,
    totems: totemsOut,
    randomBuff,
    weaponStatus,
    aggro: {
      sources: ['share/ai/aggroaccount.csv', 'share/ai/aggrosetting.csv', 'share/ai/damageaggrocode.csv'],
      note: 'result.aggro of a skill step = AggroCode. units = [Unit, Value] pairs: 3 = multiplier on the dealt damage / healed amount (divided by the Value of unit 4 when present, i.e. percent), 1 = flat hostility added. resultCode 0 = class base damage, 1 = attack skill, 2 = support skill. classDamage[class] = code used for plain attacks. See docs/formats/skills.md (medium confidence).',
      settings: aggroSettings,
      classDamage: classDamageAggro,
      codes: Object.fromEntries([...new Set([...usedAggro, ...Object.values(classDamageAggro)])].sort((a, b) => a - b).filter(c => aggroCodes.has(c)).map(c => [c, aggroCodes.get(c)])),
    },
    legacyOnly,
  };
  const effectsJson = {
    version: 1, generatedBy: 'tools/build-skills.mjs', generatedAt: now,
    sources: ['property/effect/effectscene.{01,02,03,com,map,snd}.txt', 'property/effect/effectdata.{01,02,03,com,map,snd}.txt', 'script/effect/modeleffect.csv', 'script/effect/damageeffect.csv', 'share/skill/statuseffect.csv'],
    conventions: {
      keys: 'scenes["<cate>:<id>"] (cate 100 skill, 11 condition, 6 hit, plus every other category referenced by skills/statuses/remotes). res[slot] = key into units ("<file>:<unit name lower case>"); { name, missing:true } when the unit does not exist in any effectdata file.',
      playback: 'Play scenes[sceneId]: every control with active !== false spawns units[res[control.unit]] at time life[0] ms after the trigger and removes it at life[1] ms. Keyframe lists (scale [t,x,y,z], alpha [t,a], color [t,r,g,b], rotation [t,deg], position [t,x,y,z]) use t = 0..999 across the control lifetime (life[1] - life[0]). pos = start offset in the owner frame (FILE frame, metres), bone = attach to that bone of the owner, follow = keep following the owner after spawning. See docs/formats/effects.md.',
      units: 'sprite = billboard quad (billboard camera|yaxis|carpet), decal = ground-projected quad, mesh = (skinned) mesh + anim over animLengthMs, particle = emitter, sound = 3-D sound (wav), quake = camera shake, meshstatus = overlay drawn on the owner\'s mesh, light = local light/fog zone. frames = texture animation frames (tpack slots) played over texAnimMs with texLoop increase|decrease|cycle; blend add|modulate.',
      damageText: 'floating damage numbers: alpha/scale/ypos/zpos keyframes [t 0..999, value] over timeMs (criticalTimeMs and x criticalScale for critical hits).',
    },
    ...(compatibilityRepairs.length ? { compatibilityRepairs } : {}),
    categories: EFFECT_CATEGORIES,
    damageText,
    modelEffects: {
      note: 'script/effect/modeleffect.csv (code1, code2, code3, code4) -> effect {cate, id, scene, timeMs, loop}. status = code1 19 by status IconIndex (code4 1 start / 2 keep / 3 end); spell = code1 41 by spell id; pcActionEffects = code1 25 code2 0 by the "effect" id of PC action records (skill clips); combat = code1 21 rows [code2, code3, code4] (1 hit, 2 block, 4 dead, 0 blood per material code3 / blood sound); game = code1 39 rows (code2 1..13 level up of class code2-1, 14-17 revive, 21 hp / 31 mp recovery, 41 skill level up, 51 monster death, 61-66 target markers, 100-111 quest / enhancement results). loop 0 = persistent (keep until removed), 1 = one-shot for timeMs.',
      status: Object.fromEntries(statusFx), spell: spellFx, pcActionEffects: Object.fromEntries(pcActionFx), combat: combatFx, game: gameFx,
    },
    statusEffectTable,
    scenes: scenesOut,
    units: unitsOut,
    missing: missingEffects,
  };
  const statusJson = {
    version: 1, generatedBy: 'tools/build-skills.mjs', generatedAt: now,
    sources: ['share/skill/status.csv', 'share/skill/statusgroup.csv', 'share/skill/statuseffect.csv', 'share/skill/status_delete.csv', 'script/string/stringtable_com.txt <cate> 200', 'script/effect/modeleffect.csv code1 19', 'script/ui/com/imagetable.txt buffer / buffer_b'],
    conventions: {
      statuses: 'statuses["<index>"] = { type, property, style, maxStack, group, description, mapMoveDelete, iconIndex, sendToOthers, optionCount, options[{code, id, value}], effects{start,keep,end} }. options apply while the status is active; codes are the item/status option enum (optionCodes[id].text is the tooltip with <VALUE>). effects = condition effect scenes (skills_effects.json scenes["<cate>:<id>"]) played when the status starts / while it lasts (loop) / when it ends.',
      icons: 'icons["<iconIndex>"] = { small: 22x22 buff-bar sprite (imagetable group buffer), large: imagetable group buffer_b } as {texture, rect:[x,y,w,h]}.',
    },
    optionCodes,
    statusGroups,
    statusDelete,
    icons: statusIcons,
    statuses: statusOut,
  };

  // ---- stats
  const stats = {
    files: FILES.size, skillTables: datFiles.length, skills: Object.keys(skills).length,
    perClass: classes.map(c => ({ class: c.index, code: c.code, name: c.name, skills: c.skills.length, named: c.skills.filter(i => !skills[i].hidden).length, clips: c.clips.length, missingClips: c.missingClips })),
    levels: Object.values(skills).reduce((s, k) => s + k.levels.length, 0), comboSteps: comboStepsTotal,
    stepsWithoutClip: stepsNoClip.length, stepsWithoutClipSample: stepsNoClip.slice(0, 20),
    remotes: Object.keys(remotesOut).length, statusesReferenced: usedStatuses.size, statuses: statuses.size, servants: Object.keys(servantsOut).length, totems: Object.keys(totemsOut).length,
    effectScenes: Object.keys(scenesOut).length, effectUnits: Object.keys(unitsOut).length, effectRefs: effectRefs.size, unresolvedEffectRefs,
    missingAssets: [...missingAssets].map(([k, v]) => `${v.kind} ${k} (${v.by})`),
    csvCompare, legacyOnly: legacyOnly.length, ms: Date.now() - t0,
  };
  return { skillsJson, effectsJson, statusJson, problems, notes, stats, has, read };
}

// ---------------------------------------------------------------------------------------------------------------
// Validation + CLI
// ---------------------------------------------------------------------------------------------------------------

function collectPaths(obj, out = []) {
  if (Array.isArray(obj)) { obj.forEach(x => collectPaths(x, out)); return out; }
  if (obj && typeof obj === 'object') { for (const v of Object.values(obj)) collectPaths(v, out); return out; }
  if (typeof obj === 'string' && /^(anim|mesh|skel|texture|texturepack|share|script|property|sound)\/[^{}<>\n,]+\.[a-z0-9_]+$/i.test(obj) && !/\s\(/.test(obj)) out.push(obj);
  return out;
}

export function validate({ skillsJson, effectsJson, statusJson, has }) {
  const problems = [], warnings = new Set();
  const P = (m) => problems.push(m);
  const S = skillsJson.skills;
  const statuses = statusJson.statuses;
  // every asset path exists
  for (const [name, doc] of [['skills.json', skillsJson], ['skills_effects.json', effectsJson], ['skills_status.json', statusJson]]) {
    const paths = collectPaths(doc);
    for (const p of new Set(paths)) if (!has(p)) P(`${name}: path does not exist: ${p}`);
    for (const p of new Set(paths)) if (p !== p.toLowerCase()) P(`${name}: path not lower case: ${p}`);
  }
  // cross references
  let steps = 0, clipOk = 0;
  const clipOf = (c, style, ai) => { const cl = skillsJson.classes[c]; const e = cl.skillActions[ai]; return e && e[style] !== undefined ? cl.clips[e[style]] : null; };
  for (const s of Object.values(S)) {
    if (s.class < 0 || s.class > 14) P(`skill ${s.index}: bad class`);
    for (const lv of s.levels) {
      for (const pr of lv.prereqs) if (!S[pr.skill]) P(`skill ${s.index} L${lv.level}: prerequisite skill ${pr.skill} does not exist`);
      for (const st of lv.steps) {
        const r = st.result;
        const fx = [st.effect, r?.hitEffect, st.hitEffect].filter(Boolean);
        for (const f of fx) if (!effectsJson.scenes[`${f.cate ?? 100}:${f.id}`] && !effectsJson.missing[`${f.cate ?? 100}:${f.id}`]) P(`skill ${s.index} L${lv.level}: effect ${f.cate ?? 100}:${f.id} not in skills_effects.json`);
        for (const f of fx) { const sc = effectsJson.scenes[`${f.cate ?? 100}:${f.id}`]; if (sc && sc.scenes && !sc.scenes[f.scene] && !(sc.soundScenes && sc.soundScenes[f.scene])) warnings.add(`skill ${s.index}: effect ${f.cate ?? 100}:${f.id} has no scene ${f.scene} in the client data (scenes ${Object.keys(sc.scenes).join(',')})`); }
        if (r?.statusIndex && !statuses[r.statusIndex]) P(`skill ${s.index} L${lv.level}: status ${r.statusIndex} missing`);
        if (r?.remoteIndex && !skillsJson.remotes[r.remoteIndex]) P(`skill ${s.index} L${lv.level}: remote ${r.remoteIndex} missing`);
        if (r?.servantIndex && !skillsJson.servants[r.servantIndex]) P(`skill ${s.index} L${lv.level}: servant ${r.servantIndex} missing`);
        if (r?.totemIndex && !skillsJson.totems[r.totemIndex]) P(`skill ${s.index} L${lv.level}: totem ${r.totemIndex} missing`);
        if (r?.aggro && !skillsJson.aggro.codes[r.aggro]) P(`skill ${s.index} L${lv.level}: aggro code ${r.aggro} missing`);
        if (r?.statusIndex2 && !statuses[r.statusIndex2]) P(`skill ${s.index} L${lv.level}: status ${r.statusIndex2} missing`);
        if (r?.dotStatusIndex && !statuses[r.dotStatusIndex]) P(`skill ${s.index} L${lv.level}: dot status ${r.dotStatusIndex} missing`);
        if (st.type !== 'NONE' || st.durationMs) {
          steps++;
          const styles = st.style === 255 ? (s.styles.length ? s.styles : [1]) : [st.style];
          if (styles.some(x => clipOf(s.class, x, st.actionIndex)) || clipOf(s.class, 1, st.actionIndex) || clipOf(s.class, 0, st.actionIndex)) clipOk++;
        }
      }
    }
    if (s.icon && !has(s.icon.texture)) P(`skill ${s.index}: icon texture missing`);
  }
  for (const [k, sc] of Object.entries(effectsJson.scenes)) {
    for (const [slot, u] of Object.entries(sc.res || {})) if (typeof u === 'string' && !effectsJson.units[u]) P(`effect ${k}: unit ${u} not emitted`);
    for (const s of Object.values(sc.scenes || {})) for (const c of s.controls) if (sc.res && !(c.unit in sc.res) && c.active !== false) P(`effect ${k}: control unit ${c.unit} not in res list`);
  }
  for (const [i, r] of Object.entries(skillsJson.remotes)) for (const k of ['effect', 'contactEffect', 'piercingEffect']) if (r[k] && !effectsJson.scenes[`100:${r[k].id}`] && !effectsJson.missing[`100:${r[k].id}`]) P(`remote ${i}: ${k} 100:${r[k].id} not emitted`);
  for (const [i, st] of Object.entries(statuses)) for (const ph of Object.values(st.effects || {})) if (!effectsJson.scenes[`${ph.cate}:${ph.id}`] && !effectsJson.missing[`${ph.cate}:${ph.id}`]) P(`status ${i}: effect ${ph.cate}:${ph.id} not emitted`);
  const me = effectsJson.modelEffects;
  for (const fx of [...Object.values(me.spell), ...Object.values(me.pcActionEffects), ...me.combat.map(r => r.effect), ...me.game.map(r => r.effect)]) {
    const k = `${fx.cate}:${fx.id}`;
    if (!effectsJson.scenes[k] && !effectsJson.missing[k]) P(`modelEffects: effect ${k} not emitted`);
  }
  for (const [i, sv] of Object.entries(skillsJson.servants)) for (const f of ['leaveEffect', 'enterEffect', 'statusEffect']) if (sv[f] && !effectsJson.scenes[`${sv[f].cate}:${sv[f].id}`] && !effectsJson.missing[`${sv[f].cate}:${sv[f].id}`]) P(`servant ${i}: ${f} not emitted`);
  for (const [i, tt] of Object.entries(skillsJson.totems)) for (const f of ['leaveEffect', 'standEffect', 'dieEffect']) if (tt[f] && !effectsJson.scenes[`${tt[f].cate}:${tt[f].id}`] && !effectsJson.missing[`${tt[f].cate}:${tt[f].id}`]) P(`totem ${i}: ${f} not emitted`);
  for (const c of Object.values(skillsJson.classes)) for (const cl of c.clips) if (cl.actionEffect && !effectsJson.scenes[`${cl.actionEffect.cate}:${cl.actionEffect.id}`] && !effectsJson.missing[`${cl.actionEffect.cate}:${cl.actionEffect.id}`]) P(`class ${c.index}: clip action effect ${cl.actionEffect.cate}:${cl.actionEffect.id} not emitted`);
  return { problems, warnings: [...warnings], steps, clipOk };
}

function spotCheck({ skillsJson, read }, picks) {
  const out = [];
  const hex = (b, o, n) => Array.from(b.subarray(o, o + n), x => x.toString(16).padStart(2, '0')).join(' ');
  for (const i of picks) {
    const s = skillsJson.skills[i]; if (!s) continue;
    const b = read(s.source);
    const lv = s.levels.find(l => l.steps.some(st => st.result)) || s.levels[0];
    const L = lv.level, lb = 102 * L;
    const st = lv.steps.find(x => x.result) || lv.steps[0];
    out.push(`#${i} ${s.name} (class ${s.class} ${s.classCode}, ${s.kind}, tab ${s.tree.window}:${s.tree.tab} ${s.tree.tabName}) file ${s.source}`);
    out.push(`   head  @12256 index=${b.readUInt16LE(12256)} max=${b[12258] - 1}/${b[12259] - 1}/${b[12260] - 1} target=${b.readUInt32LE(12261)} dist=${b.readUInt16LE(12266)} type=${b.readUInt32LE(12268)} class=0x${b.readUInt16LE(12274).toString(16)} icon=${b.readUInt16LE(12215)} tab=${b[12217]} xy=${b[12218]},${b[12219]}`);
    out.push(`   json  index=${s.index} max=${s.maxLevel.normal}/${s.maxLevel.a}/${s.maxLevel.b} target=${s.targetMask} range=${s.range} typeMask=${s.typeMask} icon=${s.iconIndex} tab=${s.tree.tab} xy=${s.tree.x},${s.tree.y}`);
    out.push(`   L${L} raw @${lb}: pcLevel=${b[lb + 62]} mp=${b.readUInt16LE(lb + 72)} hp=${b.readUInt16LE(lb + 70)} cool=${b.readUInt32LE(lb + 78)} cast=${b.readUInt32LE(lb + 96)} combos=${b[lb + 76]}..${b[lb + 77]} sp=${b[lb + 100]} reqs=${hex(b, lb + 49, 12)}`);
    out.push(`   L${L} json: reqLevel=${lv.reqLevel} mp=${lv.mp} hp=${lv.hp} cool=${lv.cooldownMs} cast=${lv.castMs} combos=${lv.combos} sp=${lv.spCost} prereqs=${JSON.stringify(lv.prereqs)}`);
    if (st) {
      const o = 1712 + 70 * st.combo;
      const args = []; for (let k = 0; k < 8; k++) args.push(b.readInt32LE(o + 4 + 4 * k));
      out.push(`   combo ${st.combo} raw: rc=${b.readUInt32LE(o)} args=[${args}] fx=${b.readUInt16LE(o + 44)}/${b.readUInt16LE(o + 46)} hitfx=${b.readUInt16LE(o + 36)} type=${b[o + 60]} style=${b[o + 61]} action=${b.readUInt32LE(o + 62)} tick=${b.readUInt32LE(o + 66)}`);
      out.push(`   combo json: ${JSON.stringify({ type: st.type, style: st.style, actionIndex: st.actionIndex, durationMs: st.durationMs, effect: st.effect, result: st.result && { ...st.result, impact: undefined } })}`);
    }
  }
  return out.join('\n');
}

async function main() {
  const HERE = path.dirname(fileURLToPath(import.meta.url));
  const ENGINE = path.resolve(HERE, '..');
  const argv = process.argv.slice(2);
  const arg = (k) => { const i = argv.indexOf(k); return i >= 0 ? argv[i + 1] : null; };
  const dataRoot = path.resolve(arg('--data') || process.env.DEKARON_DATA || path.join(ENGINE, '..', 'data', 'unpacked', 'data'));
  const outDir = path.resolve(arg('--out') || path.join(ENGINE, 'gamedata'));
  const verbose = argv.includes('--verbose');
  const res = await build({ dataRoot, verbose });
  const { skillsJson, effectsJson, statusJson, problems, notes, stats } = res;
  const v = validate(res);
  problems.push(...v.problems);
  notes.push(...v.warnings);
  fs.mkdirSync(outDir, { recursive: true });
  const write = (name, obj) => { const p = path.join(outDir, name); const s = JSON.stringify(obj); fs.writeFileSync(p, s); return `${name} ${(s.length / 1048576).toFixed(2)} MB`; };
  console.log('wrote', [write('skills.json', skillsJson), write('skills_effects.json', effectsJson), write('skills_status.json', statusJson)].join(', '));
  console.log(`data root ${dataRoot}: ${stats.files} files indexed, ${stats.skillTables} skill tables, ${stats.ms} ms`);
  console.log(`skills ${stats.skills} (levels ${stats.levels}, combo steps ${stats.comboSteps}); steps with an animation clip for an allowed style: ${v.clipOk}/${v.steps}`);
  for (const c of stats.perClass) console.log(`  [${String(c.class).padStart(2)}] ${String(c.name).padEnd(18)} ${String(c.skills).padStart(4)} skills (${c.named} named), ${c.clips} skill clips${c.missingClips ? `, ${c.missingClips} SKILL records point to missing anims` : ''}`);
  console.log(`remotes ${stats.remotes}, statuses ${stats.statuses} (${stats.statusesReferenced} referenced), servants ${stats.servants}, totems ${stats.totems}`);
  console.log(`effect scenes ${stats.effectScenes}, units ${stats.effectUnits}, referenced effect ids ${stats.effectRefs}, unresolved refs ${stats.unresolvedEffectRefs.length}`);
  if (stats.unresolvedEffectRefs.length) console.log('  unresolved: ' + stats.unresolvedEffectRefs.slice(0, 15).join('; '));
  console.log(`missing effect assets (referenced by effectdata units, absent from the client): ${stats.missingAssets.length}`);
  for (const m of stats.missingAssets.slice(0, 25)) console.log('  - ' + m);
  console.log(`legacy CSV twins compared for ${stats.csvCompare.skills} skills (the compiled .dat is newer; mismatches are expected where the CSV is stale):`);
  console.log('  ' + Object.entries(stats.csvCompare.fields).map(([k, e]) => `${k} ${(100 * e.ok / e.total).toFixed(1)}%`).join(', '));
  console.log(`legacy CSV-only skills (not in the compiled data, not emitted as skills): ${stats.legacyOnly}`);
  if (stats.stepsWithoutClip) console.log(`steps whose (style, actionIndex) has no SKILL record with an existing anim: ${stats.stepsWithoutClip} e.g. ${stats.stepsWithoutClipSample.slice(0, 8).join(' ')}`);
  if (argv.includes('--spot')) console.log('\nSPOT CHECK\n' + spotCheck(res, [42, 1, 402, 1102, 2402, 2403, 2701, 2801, 3721, 508]));
  const uniq = [...new Set(notes)];
  if (uniq.length) { console.log(`notes (${uniq.length}):`); for (const n of uniq.slice(0, verbose ? 400 : 20)) console.log('  - ' + n); if (!verbose && uniq.length > 20) console.log(`  ... ${uniq.length - 20} more (--verbose)`); }
  if (problems.length) { console.log(`PROBLEMS (${problems.length}):`); for (const p of problems.slice(0, 150)) console.log('  ! ' + p); process.exitCode = 1; } else console.log('OK: no problems');
}

if (import.meta.url === pathToFileURL(process.argv[1] || '').href) main();

