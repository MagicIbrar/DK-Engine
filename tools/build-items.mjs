#!/usr/bin/env node
// Dekaron Solo - item data builder.
//
// Reads the user's own unpacked client data and writes
//   gamedata/items.json          every item (84,020 share/item/item.dat + 10,783 share/item/itemevent/itemevent.dat
//                                + 109 mileage-shop CSV rows + 88 retired CSV rows), enums, tooltip text/layout,
//                                equipment rules (slots, weapon styles/bones, upgrade mapping, set bonuses)
//   gamedata/items-visual.json   item_shape / cos_shape / vehicle / pet / money visuals with resolved meshes + textures,
//                                legacy property/item/NNNN.txt definitions
//   gamedata/items-looks.json    per-class look of every visible equippable item (parts replaced + asset)
//   gamedata/items-actions.json  action tables (skeleton + anims) of wings, animated weapons, pets, mounts, rider poses
//   gamedata/items-options.json  option-type enum (+ English tooltip labels), random option pools (itemoption.dat)
//   gamedata/items-tables.json   upgrade / socket / set (union) / crest / costume / wing / disassembly / package / buff tables
//   gamedata/items-raw.json      unknown / uncompiled columns kept raw
//   gamedata/items-legacy.json   superseded option tables and the one-off option-conversion tables
//
// Usage:  node tools/build-items.mjs [--data <unpacked data root>] [--out <dir>] [--verbose] [--verify [--gamedata <dir>]]
// Exit code 1 when a hard check fails (see report.problems in items.json and docs/formats/items.md section 9).
// Every asset path in the JSON is a lower-case, '/'-separated key relative to the data root that exists on disk
// (fetch as /data/<key>, URL-encode each segment). Game paths that do not exist are only listed, in their original
// spelling, under report.missingAssets.
//
// Format notes: docs/formats/items.md. The binary parsers are exported (pure functions, no file system access).

import fs from 'node:fs';
import { isUtf8 } from 'node:buffer';
import path from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { parseCSV, decodeText } from '../src/formats/binreader.js';
import { parseTpack, textureCandidates } from '../src/formats/tpack.js';
import { parseActionDat as parseCreatureActionDat, ACTION_IDS } from '../src/formats/modeldef.js';
import { parseSkel } from '../src/formats/skel.js';
import { itemActionSources } from './build-item-action-sources.mjs';
import { parseLinesEu } from './build-monsters.mjs';
import { parseActionDat, WEAPON_CODES, STYLE_NAMES, CLASS_WIRING, normPath, gamePathToData } from './build-characters.mjs';

// ---------------------------------------------------------------------------------------------------------------
// share/item/item.dat  -  84,020 packed little-endian records of 565 bytes, no header.
// Layout recovered by aligning every CSV column against every (offset, width) over the 63,493 records that also
// exist in the item CSVs (docs/formats/items.md section 2). [offset, type, field, csv header(s), confidence]
// Bytes not covered here are zero in every record (the builder checks this).
// ---------------------------------------------------------------------------------------------------------------
// share/item/itemevent/itemevent.dat (10,783 records) has exactly the same layout; its name keys point into
// "itemevent#<table>.csv#1|<row>" and it is the only file where bytes 132-136 and 391 are used.
export const ITEM_DAT_RECORD = 565;
export const ITEM_DAT_FIELDS = [
  [0, 'zero128', 'nameBlank', null, 'Name field of the source table, blanked in the client (3 records hold junk)'],
  [128, 'u32', 'index', 'ItemIndex'],
  [132, 'u8', 'u132', null, 'itemevent.dat only: 0/1 (6,212 of 10,783 records); matches no CSV column; unknown'],
  [133, 'u32', 'eventDate', 'EventDate', 'itemevent.dat only: YYYYMMDD (e.g. 20140401); 10,783/10,783 agree with the event CSVs'],
  [137, 'u32', 'rank', 'Rank'],
  [141, 'u32', 'type', 'Type'],
  [145, 'u8', 'code', 'Code'],
  [146, 'u8', 'type2', null, 'always equal to Type'],
  [149, 'u32', 'attribute', 'Attribute'],
  [153, 'u16', 'description', 'Description'],
  [155, 'u32', 'quality', 'Quality'],
  [159, 'u32', 'job', 'Job'],
  [163, 'u32', 'itemShape', 'ItemShape'],
  [167, 'u32', 'cosShape', 'CosShape'],
  [171, 'u32', 'actionIndex', 'Action_Index'],
  [175, 'u32', 'appraisal', 'Appraisal'],
  [179, 'u8', 'unionSet', 'Union_Set_Index'],
  [180, 'u16', 'value1', 'Value1'],
  [182, 'u32', 'value2', 'Value2'],
  [186, 'u32', 'trade', 'Trade'],
  [190, 'u16', 'reqLv', 'ReqLv'],
  [192, 'u16', 'reqHLv', 'ReqHLv'],
  [194, 'u32', 'price', 'Price'],
  [198, 'u32', 'sellPrice', 'SellPrice', 'not in the 6 main CSVs; itemmileage.csv has a SellPrice column; ~30% of Price'],
  [202, 'u8', 'width', 'Width'],
  [203, 'u8', 'height', 'Height'],
  [204, 'wstr64', 'nameKey', null, 'UTF-16 lines_eu key "item#<table>.csv#1|<row>"'],
  [332, 'u16', 'maxStackNumber', 'MaxStackNumber'],
  [334, 'u16', 'stackNumber', 'StackNumber'],
  [336, 'u8', 'autoStack', 'AutoStack'],
  [337, 'u16', 'stackDropMin', 'StackDrop_Min'],
  [339, 'u16', 'stackDropMax', 'StackDrop_Max'],
  [341, 'u32', 'dropRateLow', 'DropRate_LowQuality'],
  [345, 'u32', 'dropRateNormal', 'DropRate_NormalQuality'],
  [349, 'u32', 'dropRateHigh', 'DropRate_HighQuality'],
  [353, 'u16', 'groupIndex', 'GroupIndex'],
  [355, 'f32', 'addExpRate', 'AddExpRate'],
  [359, 'f32', 'addDropItemRate', 'AddDropItemRate'],
  [363, 'f32', 'addDropDilRate', 'AddDropDilRate'],
  [367, 'u16', 'eventType', 'EventType'],
  [369, 'u8', 'periodBreak', 'PeriodBreak'],
  [370, 'u16', 'belong', 'Belong'],
  [373, 'u16', 'reqGrade', 'ReqGrade'],
  [375, 'u32', 'purchasePoint', 'PurchasePoint'],
  [379, 'u8', 'choiceLimit', 'ChoiceLimit'],
  [380, 'u8', 'purchaseLimit', 'PurchaseLimit'],
  [381, 'u32', 'pointLimit', 'PointLimit'],
  [385, 'u8', 'flag385', null, '0 for every itemcash.csv record, else 1 (except 51); meaning unknown'],
  [387, 'u16', 'u387', null, 'Unknown client-variant bytes @387-388; retained verbatim, no gameplay meaning inferred'],
  [389, 'u8', 'range', 'Wear : Range'],
  [390, 'u8', 'speed', 'Wear : Speed'],
  [391, 'u8', 'criticalRate', 'Wear : CriticalRate', 'non-zero on 60 itemevent.dat records only (all agree with the CSV)'],
  [394, 'u8', 'socket1Rate', 'Wear : Drop Socket 1EA Rate'],
  [395, 'u8', 'socket2Rate', 'Wear : Drop Socket 2EA Rate'],
  [396, 'u8', 'socket3Rate', 'Wear : Drop Socket 3EA Rate'],
  [397, 'u8', 'socket4Rate', 'Wear : Drop Socket 4EA Rate'],
  ...[1, 2, 3, 4, 5, 6].flatMap((k) => [
    [403 + (k - 1) * 6, 'u16', `opt${k}`, `Option Index ${k}`],
    [405 + (k - 1) * 6, 'u32', `opt${k}Value`, `Option Value ${k}`],
  ]),
  ...[1, 2, 3, 4, 5, 6, 7].flatMap((k) => [
    [439 + (k - 1) * 6, 'u16', `exOpt${k}`, `Expansion Option Index ${k}`],
    [441 + (k - 1) * 6, 'u32', `exOpt${k}Value`, `Expansion Option Value ${k}`],
  ]),
  ...[1, 2, 3].flatMap((k) => [
    [481 + (k - 1) * 4, 'u16', `minOption${k}`, `MinOption${k}`],
    [483 + (k - 1) * 4, 'u16', `maxOption${k}`, `MaxOption${k}`],
  ]),
  [493, 'u32', 'u493', null, '0-6, per-rank pattern; unknown'],
  [497, 'u32', 'u497', null, '0-6; unknown'],
  [501, 'u32', 'u501', null, '0,1,3; unknown'],
  [505, 'u16', 'meleeMin', 'Level 0 Melee Min Attack'],
  [507, 'u16', 'meleeMax', 'Level 0 Melee Max Attack'],
  [509, 'u16', 'magicMin', 'Level 0 Magic Min Attack'],
  [511, 'u16', 'magicMax', 'Level 0 Magic Max Attack'],
  [513, 'u16', 'rangeMin', 'Level 0 Range Min Attack'],
  [515, 'u16', 'rangeMax', 'Level 0 Range Max Attack'],
  [517, 'u16', 'pvpDamage', 'PVP Option Damage'],
  [519, 'u16', 'defMin', 'Level 0 Defence Min'],
  [521, 'u16', 'defMax', 'Level 0 Defence Max'],
  [523, 'u16', 'pvpDefence', 'PVP Option Defence'],
  [525, 'u8', 'itemLv', 'Level 0 Item LV'],
  [526, 'u16', 'blockRate', 'Level 0 Blocking Rate'],
  [528, 'u16', 'reqStr', 'Level 0 Str Request'],
  [530, 'u16', 'reqDex', 'Level 0 Dex Request'],
  [532, 'u16', 'reqSpr', 'Level 0 Spr Request'],
  [534, 'u16', 'criticalBonus', 'Level 0 Critical Bonus', 'always 0 (placement by column order only)'],
  [536, 'u16', 'appraisalAddition', 'Level 0 Appraisal Addition', 'always 0 (placement by column order only)'],
  [538, 'u32', 'beforeLevelIndex', 'BeforeLevelIndex'],
  [542, 'u32', 'nextLevelIndex', 'NextLevelIndex'],
  [546, 'u32', 'cashCost', 'DwCashItemCost'],
  [550, 'u32', 'period', ['Period', 'CashItemUsePeriod']],
  [554, 'u8', 'npcSell', ['CashItemSell', 'NPC SELL'], '1 for every non-cash item; on itemcash rows it follows CashItemSell (15426/15482 zeros agree)'],
  [555, 'u8', 'upgradeRate', 'UpgradeRate'],
  [556, 'u8', 'purchaseType', 'PurchaseType'],
  [557, 'u8', 'purchaseLimitLv', 'PurchaseLimitLv'],
  [558, 'u32', 'u558', null, '195 on 24 misc items; unknown'],
  [564, 'u8', 'flag564', null, '1 for types 2,4,5,6,7,8,9,11 (wearable/holdable), 0 for 0,1,3; equip flag (inferred)'],
];
const WIDTH = { u8: 1, u16: 2, u32: 4, f32: 4, wstr64: 128, zero128: 128 };

/** item.dat -> { records: object[], uncovered: Map(offset -> nonzero count) } */
export function parseItemDat(buf) {
  const u8 = buf instanceof Uint8Array ? buf : new Uint8Array(buf);
  const dv = new DataView(u8.buffer, u8.byteOffset, u8.byteLength);
  if (u8.length % ITEM_DAT_RECORD) throw new Error(`item.dat: size ${u8.length} is not a multiple of ${ITEM_DAT_RECORD}`);
  const n = u8.length / ITEM_DAT_RECORD;
  const utf16 = new TextDecoder('utf-16le');
  const covered = new Uint8Array(ITEM_DAT_RECORD);
  for (const [o, t] of ITEM_DAT_FIELDS) covered.fill(1, o, o + WIDTH[t]);
  const uncovered = new Map();
  const records = new Array(n);
  for (let i = 0; i < n; i++) {
    const base = i * ITEM_DAT_RECORD;
    const r = { record: i };
    for (const [o, t, name] of ITEM_DAT_FIELDS) {
      const p = base + o;
      if (t === 'u8') r[name] = u8[p];
      else if (t === 'u16') r[name] = dv.getUint16(p, true);
      else if (t === 'u32') r[name] = dv.getUint32(p, true);
      else if (t === 'f32') r[name] = Math.round(dv.getFloat32(p, true) * 1e6) / 1e6;
      else if (t === 'wstr64') { let e = p; while (e < p + 128 && (u8[e] || u8[e + 1])) e += 2; r[name] = utf16.decode(u8.subarray(p, e)); }
      else if (t === 'zero128') { let nz = 0; for (let k = p; k < p + 128; k++) if (u8[k]) nz++; r[name] = nz; }
    }
    for (let o = 0; o < ITEM_DAT_RECORD; o++) if (!covered[o] && u8[base + o]) uncovered.set(o, (uncovered.get(o) || 0) + 1);
    records[i] = r;
  }
  return { records, uncovered };
}

// ---------------------------------------------------------------------------------------------------------------
// share/item/itemoption.dat - 30,323 records of 148 bytes:
//   u16 optionLevel | u16 optionIndex | u32 typeCode | wchar key[64] ("item#itemoption_<x>.csv#3|<row>") |
//   i32 min | i32 max | i32 limit
// It is exactly itemoption_accessory/armor/weapon.csv (all 30,323 rows agree) plus the numeric typeCode, which is
// the option-type enum also used by item "Option Index N", union-set effects and stringtable_itemdesc cate 502.
// ---------------------------------------------------------------------------------------------------------------
export const OPTION_DAT_RECORD = 148;
export function parseItemOptionDat(buf) {
  const u8 = buf instanceof Uint8Array ? buf : new Uint8Array(buf);
  const dv = new DataView(u8.buffer, u8.byteOffset, u8.byteLength);
  if (u8.length % OPTION_DAT_RECORD) throw new Error(`itemoption.dat: size ${u8.length} is not a multiple of ${OPTION_DAT_RECORD}`);
  const utf16 = new TextDecoder('utf-16le');
  const out = [];
  for (let p = 0; p < u8.length; p += OPTION_DAT_RECORD) {
    let e = p + 8; while (e < p + 136 && (u8[e] || u8[e + 1])) e += 2;
    out.push({ level: dv.getUint16(p, true), index: dv.getUint16(p + 2, true), type: dv.getUint32(p + 4, true),
      key: utf16.decode(u8.subarray(p + 8, e)), min: dv.getInt32(p + 136, true), max: dv.getInt32(p + 140, true), limit: dv.getInt32(p + 144, true) });
  }
  return out;
}

/**
 * script/string/**.txt:  <cate> N ... code M [# comment] { text } ... </cate>  ->  Map(cate -> Map(code -> {text, comment}))
 * A line starting with '}' closes the block even when junk follows it (3 lines in the item tables: "}|", "}s",
 * "}code 2182" - the last one also opens the next code).
 */
export function parseStringTable(text) {
  const out = new Map();
  let cate = null, code = null, comment = '', hashless = false, buf = null;
  for (const raw of String(text).split(/\r?\n/)) {
    let line = raw.replace(/^﻿/, '');
    if (buf) {
      if (/^\s*\}/.test(line)) {
        cate.set(code, hashless ? { text: buf.join('\n'), comment, hashless } : { text: buf.join('\n'), comment }); buf = null; code = null;
        line = line.replace(/^\s*\}/, '');
        if (!/^\s*code\s+\d+/.test(line)) continue;
      } else { buf.push(line.replace(/\s+$/, '')); continue; }
    }
    const t = line.trim();
    let m;
    if ((m = /^<cate>\s*(\d+)/.exec(t))) { const id = +m[1]; if (!out.has(id)) out.set(id, new Map()); cate = out.get(id); continue; }
    if (/^<\/cate>/.test(t)) { cate = null; continue; }
    // scan fix A (W1): Global itemdesc cate 502 writes some labels with no '#' ("code 307 DAMAGE_TRANSITION_ENEMY_MUL",
    // "code 337 PVP Attack Increase" .. 341); the old '#'-only pattern dropped those blocks. Trailing text is the comment either way.
    if (cate && (m = /^code\s+(\d+)\b\s*(#?)\s*(.*)$/.exec(t))) { code = +m[1]; comment = (m[3] || '').trim(); hashless = !m[2] && !!comment; continue; }
    if (cate && code !== null && t === '{') { buf = []; continue; }
  }
  return out;
}

/** Strip the tooltip markup of the string tables (<color=..>, <set=..>, <img ..>) but keep <VALUE>-style tokens. */
export function plainText(s) {
  return String(s ?? '').replace(/<\/?color[^>]*>/gi, '').replace(/<set=[^>]*>/gi, ' ').replace(/<img[^>]*>/gi, '').replace(/[ \t]+/g, ' ').replace(/ ?\n ?/g, '\n').trim();
}

// ---------------------------------------------------------------------------------------------------------------
// Static knowledge (derived from the data; evidence in docs/formats/items.md)
// ---------------------------------------------------------------------------------------------------------------

/** Item Type (share/item Type column; kind = Type*256+Code indexes stringtable_itemdesc cate 104). */
export const ITEM_TYPES = {
  0: 'misc', 1: 'stone', 2: 'accessory', 3: 'scroll', 4: 'weapon', 5: 'armor', 6: 'special', 7: 'npcSummon',
  8: 'antiAuto', 9: 'theme', 10: 'costume', 11: 'force',
};

/**
 * Equipment slots = the `suititem_N` controls of script/ui/game2/inven/ui_invenwnd_base_renew.txt (N = slot id).
 * Labels come from the pan_* frame drawn at the same position (pan_equip_lock_0 children offset by 10,63).
 * suititem_100..117 are the same slots of the reserve (second) equipment set, 114 = reserve costume.
 */
export const EQUIP_SLOTS = [
  { id: 0, key: 'accessory1', ui: 'pan_ring1', rect: [100, 215, 36, 36] },
  { id: 1, key: 'accessory3', ui: 'pan_ring3', rect: [242, 215, 36, 36] },
  { id: 2, key: 'accessory2', ui: 'pan_ring2', rect: [100, 258, 36, 36] },
  { id: 3, key: 'accessory4', ui: 'pan_ring4', rect: [242, 258, 36, 36] },
  { id: 4, key: 'weapon', ui: 'pan_weapon', rect: [12, 111, 72, 140] },
  { id: 5, key: 'offhand', ui: 'pan_shield', rect: [293, 111, 72, 140] },
  { id: 6, key: 'grow', ui: 'pan_grow', rect: [12, 64, 36, 36] },
  { id: 7, key: 'wing', ui: 'pan_wing', rect: [63, 63, 72, 36] },
  { id: 8, key: 'helmet', ui: 'pan_helmet', rect: [154, 65, 72, 72], part: 'helmet' },
  { id: 9, key: 'armor', ui: 'pan_armor', rect: [154, 152, 72, 99], part: 'coat' },
  { id: 10, key: 'pants', ui: 'pan_pants', rect: [152, 262, 72, 72], part: 'pants' },
  { id: 11, key: 'glove', ui: 'pan_glove', rect: [12, 262, 72, 72], part: 'glove' },
  { id: 12, key: 'boots', ui: 'pan_boots', rect: [293, 262, 72, 72], part: 'boots' },
  { id: 18, key: 'costume', ui: 'pan_CostumeBG', rect: [154, 152, 72, 99] },
  { id: 19, key: 'pet', ui: 'pan_pet', rect: [287, 63, 36, 36] },
  { id: 20, key: 'vehicle', ui: 'pan_vehicle', rect: [331, 63, 36, 36] },
  { id: 24, key: 'earringL', ui: 'pan_ear_l', rect: [102, 111, 36, 36] },
  { id: 25, key: 'earringR', ui: 'pan_ear_r', rect: [242, 111, 36, 36] },
  { id: 26, key: 'bracelet1', ui: 'pan_bangle1', rect: [83, 353, 36, 36] },
  { id: 27, key: 'bracelet2', ui: 'pan_bangle2', rect: [259, 353, 36, 36] },
  { id: 28, key: 'belt', ui: 'pan_belt', rect: [154, 353, 72, 36] },
  { id: 33, key: 'emblem', ui: 'pan_emblem', rect: [242, 63, 36, 36] },
  { id: 34, key: 'force1', ui: 'pan_force1', rect: [11, 353, 36, 36] },
  { id: 35, key: 'force2', ui: 'pan_force2', rect: [330, 353, 36, 36] },
  { id: 36, key: 'talisman', ui: 'pan_talisman', rect: [242, 300, 36, 36] },
];
/** slot group name -> slot ids an item of that group may occupy */
export const SLOT_GROUPS = {
  accessory: [0, 1, 2, 3], weapon: [4], offhand: [5], grow: [6], wing: [7], helmet: [8], armor: [9], pants: [10],
  glove: [11], boots: [12], costume: [18], pet: [19], vehicle: [20], earring: [24, 25], bracelet: [26, 27],
  belt: [28], emblem: [33], force: [34, 35], talisman: [36],
};
const ARMOR_PART = { 0: 'helmet', 1: 'coat', 2: 'pants', 3: 'boots', 4: 'glove' };

/** (type, code) -> slot group (null = not equippable). */
export function slotGroupOf(type, code) {
  if (type === 4) {
    if (code === 14 || code === 21 || code === 15 || code === 16) return 'offhand';
    if (code === 32) return null; // "For Branding" material weapons
    return 'weapon';
  }
  if (type === 5) {
    if (code === 0) return 'helmet';
    if (code === 1) return 'armor';
    if (code === 2) return 'pants';
    if (code === 3) return 'boots';
    if (code === 4) return 'glove';
    if (code >= 5 && code <= 10) return 'costume';
    if (code === 11 || code === 15) return 'bracelet';
    if (code === 12 || code === 16) return 'belt';
    if (code === 13) return 'emblem';
    if (code === 14 || code === 17) return 'costume';
    if (code === 18) return 'talisman';
    return null;
  }
  if (type === 2) return [8, 10, 14].includes(code) ? 'earring' : 'accessory';
  if (type === 6) {
    if (code === 0 || code === 9) return 'grow';
    if (code === 1) return 'wing';
    if (code === 4) return 'vehicle';
    if (code === 5) return 'pet';
    return null;
  }
  if (type === 10) return 'costume';
  if (type === 11) return 'force';
  return null;
}

/**
 * Weapon codes (Type 4) -> handling. `style` = action style (share/action/action/pc style enum, classes.json
 * styleNames). `hands` 1 = one-handed (may take an off-hand item), 2 = occupies both hands.
 * `withOffhand` maps an off-hand weapon code to the combined style; `dual` = the style when a second one-handed
 * weapon of the same code is in the off-hand (stringtable_itemdesc cate 401: Sword+Sword, Mace+Mace, Axe+Axe).
 */
export const WEAPON_RULES = {
  0: { hands: 1, style: 2, withOffhand: { 14: 15, 21: 28 } },
  1: { hands: 1, style: 3, withOffhand: { 14: 16 }, dual: 10 },
  2: { hands: 2, style: 4 },
  3: { hands: 2, style: 4 },
  4: { hands: 2, style: 5 },
  5: { hands: 2, style: 6 },
  6: { hands: 1, style: 12, withOffhand: { 14: 17 }, dual: 10 },
  7: { hands: 2, style: 19 },
  8: { hands: 1, style: 13, withOffhand: { 14: 18 }, dual: 10 },
  9: { hands: 2, style: 20 },
  10: { hands: 2, style: 7, ammo: 15 },
  11: { hands: 2, style: 8, ammo: 16 },
  12: { hands: 2, style: 9 },
  13: { hands: 1, style: 11 },
  14: { offhand: true, style: 14 },
  15: { offhand: true, ammoFor: 10 },
  16: { offhand: true, ammoFor: 11 },
  17: { hands: 2, style: 21, altStyle: 10 },
  18: { hands: 2, style: 22 },
  19: { hands: 2, style: 23 },
  20: { hands: 2, style: 24 },
  21: { offhand: true, style: 26 },
  22: { hands: 1, style: 25, withOffhand: { 21: 27 } },
  23: { hands: 2, style: 29 },
  24: { hands: 2, style: 30 },
  25: { hands: 2, style: 31 },
  26: { hands: 2, style: 32 },
  27: { hands: 2, style: 33 },
  28: { hands: 2, style: 34 },
  30: { hands: 2, style: 23 },
  31: { hands: 2, style: 23 },
  33: { hands: 2, style: 23 },
  34: { hands: 2, style: 35 },
  35: { hands: 2, style: 36 },
  36: { hands: 2, style: 37 },
  37: { hands: 2, style: 38 },
  38: { hands: 2, style: 39 },
  39: { hands: 2, style: 40 },
};
/**
 * itemupgrade.csv "item code" of an item kind (type*256+code). Weapon/armour names are the item-code names of the
 * itemsocket.csv header (high confidence); accessory / emblem entries are matched by item names (medium-low,
 * see docs/formats/items.md section 6.1). Kinds not listed are upgraded through accessoryupgrade.csv / wingupgrade.csv
 * or not at all.
 */
export const UPGRADE_CATEGORY = {
  ...Object.fromEntries([[0, 'SHORT_SWORD'], [1, 'SWORD'], [2, 'LONG_SWORD'], [3, 'GREAT_SWORD'], [4, 'SPEAR'], [5, 'POLEARM'],
    [6, 'MACE'], [7, 'GREAT_MACE'], [8, 'AX'], [9, 'GREAT_AX'], [10, 'BOW'], [11, 'CROSS_BOW'], [12, 'STAFF'], [13, 'WAND'],
    [14, 'SHIELD'], [17, 'TWIN_SWORD'], [18, 'BLOODWHIP'], [20, 'GAUNTLET'], [21, 'GUARDARM'], [22, 'ALOKEN_SPEAR'],
    [23, 'DUALBLADE'], [24, 'SCYTHE'], [25, 'ORB'], [26, 'GREAT_FALCHION'], [27, 'KATAR'], [28, 'SEALFORCE'], [34, 'GUN'],
    [35, 'CANNON'], [36, 'LILY'], [37, 'CLOCHE'], [38, 'RAPIER'], [39, 'FISHSWORD']].map(([c, n]) => [1024 + c, n])),
  [1280]: 'HELMET', [1281]: 'COAT', [1282]: 'PANTS', [1283]: 'BOOTS', [1284]: 'GLOVES',
  [1291]: 'BANGLE', [1292]: 'ARMOR_BELT', [1293]: 'TRANFER_EMBLEM',
  [512]: 'NECK_WEAR', [515]: 'RING', [522]: 'UNIQUE_EARRING', [524]: 'UNIQUE_ACCESSORY', [525]: 'UNIQUE_ACCESSORY',
  [526]: 'UNIQUE_EARRING_2', [527]: 'UNIQUE_ACCESSORY_RING',
};
/** item Rank -> itemupgrade.csv rank column (0 Normal, 3 Legend, 10 Epic, 12-15 = the four Epic generations, 16 PvP). */
export const UPGRADE_GRADE = { 0: 'NORMAL', 2: 'NORMAL', 4: 'NORMAL', 5: 'NORMAL', 3: 'LEGEND', 10: 'EPIC', 12: 'EPIC2', 13: 'EPIC3', 14: 'EPIC4', 15: 'EPIC5', 16: 'PVP' };
/** itemupgrade.csv PENALTY column (what a failed attempt does; see docs/formats/items.md 6.1). */
export const UPGRADE_PENALTY = {
  NOT_FAIL: 'nothing is lost except the materials and dil',
  ALLITEM_DESTRUCT: 'the item is destroyed',
  BACK_TO_ZERO: 'the item falls back to +0',
  BACK_TO_CONST_N: 'the item falls back to +Value',
  BACKWARD_ITEM: 'the item falls back by itemupgrade_safe.csv (BACKWARD_LEVEL with BACKWARD_RATIO %)',
  '': 'unspecified (treated as NOT_FAIL)',
};
/** item_shape.csv Costype: which character parts a costume replaces (bit string, only these two values occur). */
export const COSTYPE_PARTS = { '10000': ['helmet'], '11111': ['helmet', 'coat', 'pants', 'glove', 'boots'] };
/** Coarse category per item kind (type*256+code) for UI filters; derived from the kind labels (cate 104). */
export function categoryOf(type, code) {
  if (type === 4) return code === 15 || code === 16 ? 'ammo' : code === 32 ? 'material' : [19, 30, 31, 33].includes(code) ? 'fishing' : 'weapon';
  if (type === 5) return code <= 4 ? 'armor' : [5, 6, 7, 8, 9, 10, 14, 17].includes(code) ? 'costume' : 'accessory';
  if (type === 2) return 'accessory';
  if (type === 6) return { 0: 'buff', 1: 'wing', 3: 'fishing', 4: 'vehicle', 5: 'pet', 9: 'buff' }[code] || 'special';
  if (type === 1) return code === 0 ? 'socketStone' : [23, 24, 25, 26].includes(code) ? 'crest' : 'upgradeMaterial';
  if (type === 3) return code === 2 || code === 9 ? 'skillBook' : 'scroll';
  if (type === 11) return 'force';
  if (type === 0) {
    if ([1, 2, 17, 18, 31, 32, 36, 44, 50, 51, 52, 53, 54, 56, 211].includes(code)) return 'potion';
    if (code === 4) return 'quest';
    if ([24, 25, 59].includes(code) || (code >= 200 && code <= 209) || code === 212) return 'box';
    if ([12, 28, 34, 35, 45, 210].includes(code)) return 'buff';
    if (code === 5 || code === 60 || code === 64 || (code >= 70 && code <= 78)) return 'material';
    return 'utility';
  }
  return ITEM_TYPES[type] || 'other';
}
/** Character bone that carries wings (inferred: every class skeleton has 'weaponW', a child of Bip01 Spine1, that no weapon uses). */
export const WING_BONE = 'weaponW';
let WING_EFFECT_INFO = null; // scan fix A: filled from script/effect/wingeffect.csv while building items
/** items-raw.json columns (values kept verbatim; meanings unknown or only relevant for tooling). */
export const RAW_COLUMN_NOTES = {
  row: 'data row of the source table in the lines_eu name key (item#<table>.csv#1|<row>)',
  type2: 'item.dat byte 146, always equal to Type',
  u387: 'item.dat/itemevent.dat u16 @387: unknown client-variant value; preserved without gameplay interpretation',
  flag385: 'item.dat byte 385: 0 on every itemcash.csv record, 1 elsewhere (51 exceptions); unknown',
  flag564: 'item.dat byte 564: 1 for types 2,4,5,6,7,8,9,11 (wearable/holdable), 0 for 0,1,3; probably "equippable"',
  u493: 'item.dat u32 @493 (0-6); unknown', u497: 'item.dat u32 @497 (0-6); unknown', u501: 'item.dat u32 @501 (0,1,3); unknown',
  u558: 'item.dat u32 @558 (195 on 24 misc items); unknown',
  criticalBonus: 'item.dat u16 @534 (CSV "Level 0 Critical Bonus", always 0)', appraisalAddition: 'item.dat u16 @536 (CSV "Level 0 Appraisal Addition", always 0)',
  nameBlankBytes: 'non-zero bytes in the blanked 128-byte name field (3 records)',
  addExpRate: 'raw f32 @355 (non-cash tables hold the compiler default 1.0; the real bonus is item.addExp)',
  addDropItemRate: 'raw f32 @359 (see addExpRate)', addDropDilRate: 'raw f32 @363 (see addExpRate)',
  csvNoData: 'CSV column NoData (3150 on classic weapons, 60xx on socket stones); unknown',
  csvIsLimit: 'CSV column IsLimit (not compiled into item.dat)', csvNpcSell: 'CSV column "NPC SELL"', csvCashItemSell: 'CSV column CashItemSell (itemcash)',
  csvBuyMinLevel: 'CSV column BuyMinLevel (itemcash)', csvName: 'CSV Name when it differs from the lines_eu English name',
  u132: 'itemevent.dat u8 @132 (0/1; unknown)', dat: 'compiled table the record comes from: 0 item.dat, 1 itemevent.dat, 2 none (CSV only)',
  csvNextShape: 'CSV column NextShape (not compiled)', csvIsMapLimit: 'event CSV column IsMapLimit (not compiled)',
  csvMapLimit: 'event CSV column MapLimit (not compiled)', csvDropPeriod: 'event CSV column dwDropPeriod (not compiled)',
};
/** Which weapon_bonename.csv column pair a weapon code uses (same rule as build-characters HAND_BY_CODE). */
const COLUMN_BY_CODE = { 10: 'left', 11: 'left', 14: 'left', 21: 'left', 17: 'both', 20: 'both', 23: 'both', 27: 'both', 34: 'both' };

// ---------------------------------------------------------------------------------------------------------------
// Builder (Node only)
// ---------------------------------------------------------------------------------------------------------------
const num = (v) => { const s = String(v ?? '').trim(); if (s === '') return null; const x = Number(s); return Number.isFinite(x) ? x : null; };
const HANGUL = /[ᄀ-ᇿ㄰-㆏가-힯]/;

function classMaskFromDatJob(job) {
  let m = 0;
  for (let c = 0; c < 15; c++) if ((job >>> (31 - c)) & 1) m |= 1 << c;
  return m;
}
function classMaskFromCsvJob(s) {
  const b = String(s ?? '').replace(/[^01]/g, '');
  let m = 0;
  for (let c = 0; c < 15 && c < b.length; c++) if (b[c] === '1') m |= 1 << c;
  return m;
}

export async function build({ dataRoot, verbose = false } = {}) {
  const t0 = Date.now();
  const problems = [];
  const notes = [];
  const log = (...a) => { if (verbose) console.log(...a); };

  // ---- file index
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
  const readText = (k, korean = true) => decodeText(read(k), korean);
  // scan fix A (W2): Global stringtable_item.txt mixes EUC-KR lines with lines saved as UTF-8 (45 lines, e.g. the en dash
  // in "0–3" of codes 1172/1173 that decode to U+FFFD under EUC-KR). Decode per line: valid UTF-8 first, EUC-KR fallback.
  // A file with a BOM keeps decodeText's explicit-encoding path.
  const readTextMixed = (k) => {
    const b = read(k);
    if ((b[0] === 0xef && b[1] === 0xbb && b[2] === 0xbf) || (b[0] === 0xff && b[1] === 0xfe) || (b[0] === 0xfe && b[1] === 0xff)) return decodeText(b, true);
    const out = []; let s = 0;
    for (let i = 0; i <= b.length; i++) if (i === b.length || b[i] === 0x0a) { const seg = b.subarray(s, i); out.push(isUtf8(seg) ? seg.toString('utf8') : decodeText(seg, true)); s = i + 1; }
    return out.join('\n');
  };
  const csvRows = (k) => parseCSV(readText(k)).filter(r => r.some(x => String(x).trim() !== ''));
  const csvObjects = (k, headerRows = 1) => {
    const rows = csvRows(k);
    const header = rows[headerRows - 1].map(h => String(h).trim());
    return { header, rows: rows.slice(headerRows).map(r => { const o = {}; header.forEach((h, i) => { if (h && !(h in o)) o[h] = String(r[i] ?? '').trim(); }); o.__cells = r; return o; }) };
  };
  const missingAssets = new Map(); // original game path -> first referrer
  const missing = (gamePath, ctx) => { if (!missingAssets.has(gamePath)) missingAssets.set(gamePath, ctx); };

  // ---- localisation
  const L = parseLinesEu(read('script/lines_eu'), { keyFilter: (k) => k.startsWith('item') || k.startsWith('pet#pet.csv') });
  if (L.trailingBytes) problems.push(`lines_eu: ${L.trailingBytes} trailing bytes`);
  const loc = (key) => { const id = L.csvKeys.get(key); return id === undefined ? null : (L.strings.get(id) ?? null); };
  const itemDescTable = parseStringTable(readText('script/string/item/stringtable_itemdesc.txt'));
  const itemTextTable = parseStringTable(readTextMixed('script/string/item/stringtable_item.txt'));
  const kindNames = {};
  for (const [code, v] of itemDescTable.get(104) || []) kindNames[code] = plainText(v.text);
  const rankNames = {};
  for (const [code, v] of itemDescTable.get(103) || []) rankNames[code] = plainText(v.text);
  const descriptions = {};
  for (const [code, v] of itemTextTable.get(20) || []) descriptions[code] = plainText(v.text);

  // ---- classes (pcclass.csv row name_kor holds the English display names)
  const pc = {};
  for (const r of csvRows('share/pc/pcclass.csv')) pc[String(r[0]).trim()] = r.slice(1).map(x => String(x).trim());
  const classes = CLASS_WIRING.map(w => ({ index: w.index, code: w.code, name: pc.name_kor?.[w.index] || pc.name_eng?.[w.index] }));

  // ---- item.dat + itemevent.dat (the two compiled tables the client loads; same 565-byte layout)
  const dat = { records: [] };
  const datCounts = {};
  for (const [part, file] of [[0, 'share/item/item.dat'], [1, 'share/item/itemevent/itemevent.dat']]) {
    if (!has(file)) { problems.push(`${file} missing`); continue; }
    const d = parseItemDat(read(file));
    for (const [o, n] of d.uncovered) problems.push(`${file}: byte ${o} is not covered by the layout but non-zero in ${n} records`);
    for (const r of d.records) { r.dat = part; dat.records.push(r); }
    datCounts[file] = d.records.length;
  }
  const datByIndex = new Map();
  for (const r of dat.records) {
    if (datByIndex.has(r.index)) problems.push(`item.dat/itemevent.dat: duplicate index ${r.index}`);
    datByIndex.set(r.index, r);
  }
  log(`compiled item records: ${JSON.stringify(datCounts)}`);

  // ---- CSV twins (for comparison + CSV-only columns) and CSV-only items (event, mileage)
  const CSV_SOURCES = [
    { file: 'share/item/itemweapon.csv', src: 'weapon' },
    { file: 'share/item/itemarmor.csv', src: 'armor' },
    { file: 'share/item/itemaccessory.csv', src: 'accessory' },
    { file: 'share/item/itemetc.csv', src: 'etc' },
    { file: 'share/item/itemetc_socket.csv', src: 'etc_socket' },
    { file: 'share/item/itemcash.csv', src: 'cash' },
    { file: 'share/item/itemmileage.csv', src: 'mileage', lines: 'item#itemmileage.csv' },
    { file: 'share/item/itemevent/accessoryevent.csv', src: 'event_accessory', lines: 'itemevent#accessoryevent.csv', indexKey: 'Index' },
    { file: 'share/item/itemevent/cashevent.csv', src: 'event_cash', lines: 'itemevent#cashevent.csv' },
    { file: 'share/item/itemevent/etcevent.csv', src: 'event_etc', lines: 'itemevent#etcevent.csv' },
  ];
  const csvByIndex = new Map(); // index -> {src, row (1-based data row), o}
  const csvOnly = [];
  const csvStats = {};
  for (const S of CSV_SOURCES) {
    if (!has(S.file)) { notes.push(`${S.file} missing`); continue; }
    const rows = csvRows(S.file);
    const header = rows[0].map(h => String(h).trim().replace(/^Item Index$/, 'ItemIndex').replace(/^No Data$/, 'NoData'));
    const indexKey = S.indexKey || 'ItemIndex';
    const indexColumn = header.indexOf(indexKey);
    if (indexColumn < 0 || header.lastIndexOf(indexKey) !== indexColumn) {
      throw new Error(`${S.file}: expected one ${indexKey} column; refusing ambiguous item joins`);
    }
    let n = 0, inDat = 0;
    for (let ri = 1; ri < rows.length; ri++) {
      const r = rows[ri];
      const idx = num(r[indexColumn]);
      if (idx === null || r.length < 10) continue;
      n++;
      const o = {};
      header.forEach((h, i) => { if (h && !(h in o)) o[h] = String(r[i] ?? '').trim(); });
      const entry = { src: S.src, row: ri, o, lines: S.lines || `item#${S.file.split('/').pop()}` };
      if (datByIndex.has(idx)) { inDat++; if (!csvByIndex.has(idx)) csvByIndex.set(idx, entry); }
      else if (S.lines) csvOnly.push({ index: idx, ...entry });
      else {
        // row of a main table missing from the compiled tables: retired from the live client, still referenced by
        // packages / D-Shop / drop sets, so it is emitted with retired: 1
        if (!csvByIndex.has(idx)) csvByIndex.set(idx, { ...entry, notInDat: true });
        csvOnly.push({ index: idx, ...entry, retired: true });
      }
    }
    csvStats[S.src] = { rows: n, inDat, csvOnly: n - inDat };
  }
  // CSV rows of the 6 main tables that are absent from item.dat: dropped from the live client, not emitted (listed)
  const csvDropped = [...csvByIndex].filter(([, e]) => e.notInDat).map(([i, e]) => ({ index: i, src: e.src, name: e.o.Name }));

  // ---- CSV vs dat comparison (per column mismatch counts)
  const compare = {};
  for (const [idx, e] of csvByIndex) {
    if (e.notInDat) continue;
    const r = datByIndex.get(idx);
    for (const [, t, name, hdr] of ITEM_DAT_FIELDS) {
      if (!hdr) continue;
      const hs = Array.isArray(hdr) ? hdr : [hdr];
      const h = hs.find(x => e.o[x] !== undefined && e.o[x] !== '');
      if (!h) continue;
      const c = compare[name] || (compare[name] = { compared: 0, differ: 0 });
      c.compared++;
      let v;
      if (name === 'job') v = classMaskFromCsvJob(e.o[h]) === classMaskFromDatJob(r.job);
      else v = t === 'f32' ? Math.abs(Number(e.o[h]) - r[name]) < 1e-3 : Number(e.o[h]) === r[name];
      if (!v) c.differ++;
    }
  }

  // ---- option enum (itemoption.dat types + stringtable_itemdesc cate 502 labels)
  const optDat = parseItemOptionDat(read('share/item/itemoption.dat'));
  const optionCsv = {};
  for (const f of ['itemoption_accessory.csv', 'itemoption_armor.csv', 'itemoption_weapon.csv']) optionCsv[f] = csvRows(`share/item/${f}`);
  const optionTypes = {}; // code -> {name, label, text}
  for (const [code, v] of itemDescTable.get(502) || []) {
    // hashless labels ("PVP Attack Increase") are prose, not an option identifier - only take an UPPER_SNAKE token as the name
    const tok = (v.comment || '').split(/\s+/)[0] || null;
    const name = v.hashless && !/^[A-Z][A-Z0-9]*_[A-Z0-9_]+$/.test(tok || '') ? null : tok;
    const text = plainText(v.text).replace(/\n/g, ' ');
    optionTypes[code] = { name, label: text.replace(/\s*<VALUE>.*$/, '').replace(/[:\s]+$/, '').trim(), text };
  }
  let optJoined = 0, optAgree = 0;
  const optionPools = {}; // level -> [[index, type, min, max, limit, table]]
  for (const o of optDat) {
    const m = /^item#([^#]+)#3\|(\d+)$/.exec(o.key);
    const row = m ? optionCsv[m[1]]?.[Number(m[2])] : null;
    const table = m ? m[1].replace(/^itemoption_|\.csv$/g, '') : null;
    if (row) {
      optJoined++;
      if (num(row[0]) === o.level && num(row[1]) === o.index && num(row[4]) === o.min && num(row[5]) === o.max) optAgree++;
      const tn = String(row[2]).trim();
      const ot = optionTypes[o.type] || (optionTypes[o.type] = { name: tn, label: null, text: null });
      if (!ot.name) ot.name = tn;
      else if (ot.name !== tn) notes.push(`option type ${o.type}: itemoption csv name ${tn} vs string table ${ot.name}`);
      if (!ot.csvLabel) ot.csvLabel = loc(`item#${m[1]}#3|${m[2]}`) || String(row[3]).trim();
    }
    (optionPools[o.level] ||= []).push([o.index, o.type, o.min, o.max, o.limit, table]);
  }
  if (optJoined !== optDat.length || optAgree !== optDat.length) problems.push(`itemoption.dat vs csv: joined ${optJoined}, agree ${optAgree} of ${optDat.length}`);
  // option codes Global's cate 502 has no line for (e.g. 337 / 339 PVP damage): the same code's line in Global
  // stringtable_com cate 200 (the option-code keyed table) is the text, so the tooltip never shows "Option <code>"
  if (has('script/string/stringtable_com.txt')) {
    const com200 = parseStringTable(readText('script/string/stringtable_com.txt')).get(200) || new Map();
    for (const [code, ot] of Object.entries(optionTypes)) {
      const v = ot.text ? null : com200.get(Number(code));
      if (!v) continue;
      const text = plainText(v.text).replace(/\n/g, ' ').trim();
      if (!text || /^[A-Z0-9_]+ <VALUE>$/.test(text)) continue;
      ot.text = text; ot.textSource = 'stringtable_com 200';
      if (!ot.label) ot.label = text.replace(/<VALUE>%?/g, '').replace(/^[\s+\-]+/, '').replace(/\s+/g, ' ').trim();
    }
  }

  // ---- itemstatus (buff / status consumables), itempackage, random box tables (pointer only)
  const itemStatus = {};
  {
    const rows = csvRows('share/item/itemstatus.csv');
    for (let ri = 1; ri < rows.length; ri++) {
      const c = rows[ri].map(x => String(x ?? '').trim());
      const i = num(c[0]); if (i === null) continue;
      // columns: Index(wValue),StatusIndex,ShowEffect,MaxStack,EffectID,SceneID,NotifyMessage,LifeTime,Hp,Mp,HPRatio,MPRatio,Descript
      itemStatus[i] = { statusIndex: num(c[1]), showEffect: c[2] === 'Y', maxStack: num(c[3]), effectId: num(c[4]), sceneId: num(c[5]),
        notify: loc(`item#itemstatus.csv#6|${ri}`) || c[6], lifeTimeMs: num(c[7]), hp: num(c[8]), mp: num(c[9]), hpRatio: num(c[10]), mpRatio: num(c[11]),
        description: loc(`item#itemstatus.csv#12|${ri}`) || c[12] };
    }
  }
  const packages = {};
  for (const r of csvObjects('share/item/itempackage.csv').rows) {
    const i = num(r.PackageItemIndex); if (i === null) continue;
    const items = [];
    for (let k = 0; k < 10; k++) { const it = num(r[`ItemIndex_${k}`]); if (it) items.push([it, num(r[`StackNum_${k}`]) || 1]); }
    packages[i] = { minLv: num(r.WminLevel), maxLv: num(r.WmaxLevel), count: num(r.ItemCount), items };
  }
  const randomBoxIndex = new Set(csvObjects('share/item/itemchange_randombox.csv').rows.map(r => num(r.Index)).filter(x => x !== null));
  const eggBoxIndex = new Set(csvObjects('share/item/egg_box.csv').rows.map(r => num(r.RandomBoxIndex)).filter(x => x !== null));
  const premiere = {};
  for (const r of csvObjects('share/item/premiereitem.csv').rows) {
    const i = num(r.ItemIndex); if (i === null) continue;
    const o = {}; for (const [k, v] of Object.entries(r)) if (k !== '__cells' && k !== 'ItemIndex' && num(v)) o[k] = num(v);
    premiere[i] = o;
  }

  // ---- compose items
  // Every item is first built with ALL fields (zeros included). A post-pass then stores the most common value of
  // each field in itemDefaults and drops it from the items that have it (consumers: {...itemDefaults, ...item}).
  const full = new Map();     // index -> full item
  const rawFull = new Map();  // index -> raw columns
  const nameSources = { lines_eu: 0, csv: 0, csvKoreanFallback: 0, none: 0 };
  let koreanNames = 0;
  const CASH_SRC = new Set(['cash', 'event_cash', 'mileage']);
  const emit = (f, meta) => {
    const it = { name: meta.name, src: meta.src, type: f.type ?? 0, code: f.code ?? 0 };
    const group = slotGroupOf(it.type, it.code);
    if (group) it.slot = group;
    Object.assign(it, {
      rank: f.rank ?? 0, classMask: f.classMask, reqLv: f.reqLv ?? 0, maxLv: f.reqHLv ?? 0,
      reqStr: f.reqStr ?? 0, reqDex: f.reqDex ?? 0, reqSpr: f.reqSpr ?? 0, reqGrade: f.reqGrade ?? 0,
      price: f.price ?? 0, sell: f.sellPrice ?? 0, cash: f.cashCost ?? 0, npcSell: f.npcSell ?? 0,
      w: f.width || 1, h: f.height || 1, stack: f.stackNumber ?? 0, maxStack: f.maxStackNumber ?? 0, autoStack: f.autoStack ?? 0,
      quality: f.quality ?? 0, desc: f.description ?? 0, shape: f.itemShape ?? 0, cosShape: f.cosShape ?? 0, action: f.actionIndex ?? 0,
      itemLv: f.itemLv ?? 0, prev: f.beforeLevelIndex ?? 0, next: f.nextLevelIndex ?? 0,
      melee: [f.meleeMin ?? 0, f.meleeMax ?? 0], magic: [f.magicMin ?? 0, f.magicMax ?? 0], ranged: [f.rangeMin ?? 0, f.rangeMax ?? 0],
      def: [f.defMin ?? 0, f.defMax ?? 0], pvpDmg: f.pvpDamage ?? 0, pvpDef: f.pvpDefence ?? 0, block: f.blockRate ?? 0,
      range: f.range ?? 0, speed: f.speed ?? 0, crit: f.criticalRate ?? 0,
    });
    const opts = [];
    for (let k = 1; k <= 6; k++) if (f[`opt${k}`]) opts.push([f[`opt${k}`], f[`opt${k}Value`] ?? 0]);
    it.options = opts;
    const ex = [];
    for (let k = 1; k <= 7; k++) if (f[`exOpt${k}`]) ex.push([f[`exOpt${k}`], f[`exOpt${k}Value`] ?? 0]);
    it.exOptions = ex;
    it.optionPools = [1, 2, 3].map(k => [f[`minOption${k}`] || 0, f[`maxOption${k}`] || 0]);
    it.socketRates = [f.socket1Rate, f.socket2Rate, f.socket3Rate, f.socket4Rate].map(x => x || 0);
    Object.assign(it, {
      value1: f.value1 ?? 0, value2: f.value2 ?? 0, trade: f.trade ?? 0, belong: f.belong ?? 0, periodBreak: f.periodBreak ?? 0,
      period: f.period ?? 0, union: f.unionSet ?? 0, appraisal: f.appraisal ?? 0, attribute: f.attribute ?? 0, group: f.groupIndex ?? 0,
      eventType: f.eventType ?? 0, eventDate: f.eventDate ?? 0,
      // the compiler writes 1.0 into these floats for every table without the column (all non-cash items): only
      // values of tables that have the column are real bonuses; the rest stay in items-raw.json
      addExp: CASH_SRC.has(meta.src) ? (f.addExpRate ?? 0) : 0, addDrop: CASH_SRC.has(meta.src) ? (f.addDropItemRate ?? 0) : 0,
      addDil: meta.src === 'cash' || meta.src === 'mileage' ? (f.addDropDilRate ?? 0) : 0,
      dropStack: [f.stackDropMin ?? 0, f.stackDropMax ?? 0], dropRate: [f.dropRateLow ?? 0, f.dropRateNormal ?? 0, f.dropRateHigh ?? 0],
      purchasePoint: f.purchasePoint ?? 0, choiceLimit: f.choiceLimit ?? 0, purchaseLimit: f.purchaseLimit ?? 0, pointLimit: f.pointLimit ?? 0,
      purchaseType: f.purchaseType ?? 0, purchaseLimitLv: f.purchaseLimitLv ?? 0, upgradeRate: f.upgradeRate ?? 0,
    });
    // interpreted use / contents (only where the data is unambiguous; value1/value2 stay for everything else)
    const use = {};
    if (it.type === 0 && (it.code === 1 || it.code === 17)) use.hp = it.value1;
    if (it.type === 0 && (it.code === 2 || it.code === 18)) use.mp = it.value1;
    if (it.type === 0 && [12, 14, 28, 57].includes(it.code) && itemStatus[it.value1]) use.itemStatus = it.value1;
    if (it.type === 0 && it.code === 36) use.shield = it.value1;                       // Shield Recovery (tooltip cate 2 code 3)
    if (it.type === 0 && (it.code === 50 || it.code === 53)) use.hpPct = it.value1;    // "20% Health Potion": value1 = % of max HP
    if (it.type === 0 && (it.code === 51 || it.code === 54)) use.mpPct = it.value1;
    if (it.type === 0 && it.code === 52) { use.hpPct = it.value1; use.mpPct = it.value1; }
    if (it.type === 0 && it.code === 56) use.shieldPct = it.value1;
    if (it.type === 0 && it.code === 211) use.stamina = it.value1;
    if (it.type === 3 && (it.code === 0 || it.code === 5)) use.teleport = it.value1;  // share/arrange/location.csv index; 0 = return to town
    if (it.type === 3 && it.code === 9) use.meisterSkill = it.value1;
    if (it.type === 1 && it.code === 19) use.brandLevel = it.value1;                   // Soul Stone: Level N (brand / incuse)
    if (it.type === 3 && it.code === 2) use.skill = it.value1;
    if (it.type === 1 && it.code === 0 && it.value1) use.socketIcon = it.value1; // imagetable Socket#value1 (enums.socketIcons)
    if (packages[f.index]) use.package = true;
    if (randomBoxIndex.has(f.index)) use.randomBox = 'itemchange_randombox';
    if (eggBoxIndex.has(f.index)) use.randomBox = 'egg_box';
    if (premiere[f.index]) use.premiere = true;
    if (Object.keys(use).length) it.use = use;
    // raw: unknown dat fields + CSV-only columns
    const c = meta.csv || {};
    rawFull.set(f.index, {
      row: meta.row ?? 0, type2: f.type2 ?? 0, flag385: f.flag385 ?? 0, u387: f.u387 ?? 0, flag564: f.flag564 ?? 0, u493: f.u493 ?? 0, u497: f.u497 ?? 0,
      u501: f.u501 ?? 0, u558: f.u558 ?? 0, criticalBonus: f.criticalBonus ?? 0, appraisalAddition: f.appraisalAddition ?? 0,
      nameBlankBytes: f.nameBlank ?? 0, addExpRate: f.addExpRate ?? 0, addDropItemRate: f.addDropItemRate ?? 0, addDropDilRate: f.addDropDilRate ?? 0,
      csvNoData: num(c.NoData) ?? 0, csvIsLimit: num(c.IsLimit) ?? 0, csvNpcSell: num(c['NPC SELL']) ?? 0, csvCashItemSell: num(c.CashItemSell) ?? 0,
      csvBuyMinLevel: num(c.BuyMinLevel) ?? 0, csvName: meta.csvNameDiffers ?? '',
      u132: f.u132 ?? 0, dat: meta.dat ?? 2, csvNextShape: num(c.NextShape) ?? 0, csvIsMapLimit: num(c.IsMapLimit) ?? 0,
      csvMapLimit: num(c.MapLimit) ?? 0, csvDropPeriod: num(c.dwDropPeriod) ?? 0,
    });
    full.set(f.index, it);
  };

  const nameFor = (key, csvEntry) => {
    let n = key ? loc(key) : null;
    const csvName = csvEntry?.o?.Name?.trim() || null;
    if (n) {
      if (HANGUL.test(n) && csvName && !HANGUL.test(csvName)) { nameSources.csvKoreanFallback++; n = csvName; }
      else nameSources.lines_eu++;
    } else if (csvName) { nameSources.csv++; n = csvName; } else { nameSources.none++; n = null; }
    if (n && HANGUL.test(n)) koreanNames++;
    return { name: n, csvNameDiffers: csvName && csvName !== n ? csvName : '' };
  };

  for (const r of dat.records) {
    const km = /^(?:item#item(\w+?)|itemevent#(\w+?)event)\.csv#1\|(\d+)$/.exec(r.nameKey);
    const src = km ? (km[1] ?? `event_${km[2]}`) : 'unknown';
    const csvE = csvByIndex.get(r.index);
    const f = { ...r, classMask: classMaskFromDatJob(r.job) };
    const nm = nameFor(r.nameKey, csvE);
    emit(f, { name: nm.name, csvNameDiffers: nm.csvNameDiffers, src, row: km ? Number(km[3]) : null, csv: csvE?.o, dat: r.dat });
    if (!km) problems.push(`item ${r.index}: unexpected name key "${r.nameKey}"`);
  }
  // CSV-only items (event tables, mileage shop): the same field set read by header name (first header wins)
  const HDR = new Map();
  for (const [, t, name, hdr] of ITEM_DAT_FIELDS) if (hdr) for (const h of (Array.isArray(hdr) ? hdr : [hdr])) HDR.set(h, [name, t]);
  let csvOnlyDup = 0;
  const retiredWeaponsDropped = [];
  for (const c of csvOnly) {
    if (full.has(c.index)) { csvOnlyDup++; continue; }
    // a retired weapon row (itemweapon.csv only, no item.dat record) that no Global share/script table references
    // (packages, shops, drops, boxes) cannot appear in Global, e.g. the "N Million / Billion Cecil +9" rows
    if (c.retired && c.src === 'weapon') { retiredWeaponsDropped.push(c.index); continue; }
    const f = { index: c.index };
    for (const [h, [name]] of HDR) if (c.o[h] !== undefined && name !== 'job' && f[name] === undefined) { const v = num(c.o[h]); if (v !== null) f[name] = v; }
    f.classMask = classMaskFromCsvJob(c.o.Job);
    // a CSV-only row has no compiled name key: "<table>#1|<row>" only matches lines_eu when the CSV is the version
    // lines_eu was built from (not true for retired rows, e.g. 7305), so an English CSV name wins
    const csvName = c.o.Name?.trim();
    const nm = csvName && !HANGUL.test(csvName) ? (nameSources.csv++, { name: csvName, csvNameDiffers: '' }) : nameFor(`${c.lines}#1|${c.row}`, c);
    emit(f, { name: nm.name, csvNameDiffers: nm.csvNameDiffers, src: c.src, row: c.row, csv: c.o });
    if (c.retired) full.get(c.index).retired = 1;
  }
  if (csvOnlyDup) notes.push(`${csvOnlyDup} CSV-only rows share an index with an earlier item and were skipped`);
  if (retiredWeaponsDropped.length) notes.push(`${retiredWeaponsDropped.length} retired weapon rows not in item.dat dropped: ${retiredWeaponsDropped.join(', ')}`);

  // ---- defaults (mode of each field) and sparse items
  const NEVER_DEFAULT = new Set(['name', 'src', 'type', 'code', 'slot', 'use', 'retired']);
  const modeOf = (rows, skip) => {
    const counts = new Map();
    for (const o of rows) for (const [k, v] of Object.entries(o)) {
      if (skip.has(k)) continue;
      const s = JSON.stringify(v);
      let m = counts.get(k); if (!m) counts.set(k, (m = new Map()));
      m.set(s, (m.get(s) || 0) + 1);
    }
    const out = {};
    for (const [k, m] of counts) out[k] = JSON.parse([...m].sort((a, b) => b[1] - a[1])[0][0]);
    return out;
  };
  const itemDefaults = modeOf(full.values(), NEVER_DEFAULT);
  // id-like / amount fields always default to zero (a "most common shape" default would only confuse readers)
  for (const k of ['shape', 'cosShape', 'desc', 'prev', 'next', 'action', 'union', 'value1', 'value2', 'price', 'sell', 'cash', 'itemLv',
    'reqLv', 'period', 'group', 'eventType', 'eventDate', 'crit', 'attribute', 'appraisal', 'rank', 'maxLv', 'reqStr', 'reqDex', 'reqSpr', 'reqGrade', 'stack', 'maxStack']) itemDefaults[k] = 0;
  for (const k of ['melee', 'magic', 'ranged', 'def']) itemDefaults[k] = [0, 0];
  itemDefaults.options = []; itemDefaults.exOptions = [];
  const fullList = [...full].map(([index, it]) => ({ index, ...it, part: it.type === 5 ? ARMOR_PART[it.code] : undefined }));
  const sparse = (o, defs) => {
    const out = {};
    for (const [k, v] of Object.entries(o)) if (!(k in defs) || JSON.stringify(v) !== JSON.stringify(defs[k])) out[k] = v;
    return out;
  };
  const items = {};
  for (const [i, it] of [...full].sort((a, b) => a[0] - b[0])) items[i] = sparse(it, itemDefaults);
  // Scan fix A: script/effect/wingeffect.csv (one ItemIndex column). Global Ghost::DriverKernel::Table::WingEffect
  // (64-bit decompile FUN_7ff6708a7740) is a lookup by item index; the wing render paths (decompile L266017, L345084,
  // L369704) ask it whether the item is listed and only take their default attach/effect path when it is NOT listed.
  // Carried as items[i].wingEffect = 1 (Global data). The alternate path's string literal is not in the decompile text,
  // so the runtime branch is not wired here.
  {
    const key = 'script/effect/wingeffect.csv';
    const info = { file: key, rows: 0, matched: 0, notInItems: [] };
    if (has(key)) {
      for (const line of read(key).toString('latin1').split(/\r?\n/).slice(1)) {
        const v = Number(line.split(',')[0].trim()); if (!Number.isInteger(v) || v <= 0) continue;
        info.rows++;
        if (items[v]) { items[v].wingEffect = 1; info.matched++; } else if (info.notInItems.length < 50) info.notInItems.push(v);
      }
    }
    WING_EFFECT_INFO = info;
  }
  const rawDefaults = modeOf(rawFull.values(), new Set());
  const rawItems = {};
  for (const [i, r] of [...rawFull].sort((a, b) => a[0] - b[0])) { const s = sparse(r, rawDefaults); if (Object.keys(s).length) rawItems[i] = s; }

  // ---- visuals -----------------------------------------------------------------------------------------------
  const tpackCache = new Map();
  const texturesOf = (tpackKey, meshKey, ctx) => {
    if (!tpackKey || !has(tpackKey)) return null;
    if (tpackCache.has(tpackKey)) return tpackCache.get(tpackKey);
    let tp;
    try { tp = parseTpack(read(tpackKey)); } catch (e) { problems.push(`${ctx}: tpack ${tpackKey}: ${e.message}`); tpackCache.set(tpackKey, null); return null; }
    const slots = new Set([...Object.keys(tp.diffuse), ...Object.keys(tp.specular)].map(Number));
    const out = [];
    for (const s of [...slots].sort((a, b) => a - b)) {
      const pick = (kind) => {
        const file = tp[kind][s];
        if (!file) return null;
        const c = textureCandidates(tp.texdir, file, { meshPath: meshKey || undefined }).find(has);
        if (!c) missing(`${tp.texpath ?? ''}\\${file}`, tpackKey);
        return c || null;
      };
      const t = { material: s };
      const d = pick('diffuse'); if (d) t.diffuse = d;
      const sp = pick('specular'); if (sp) t.specular = sp;
      if (tp.glow[s]) { const g = pick('glow'); if (g) t.glow = g; }
      if (t.diffuse || t.specular) out.push(t);
    }
    tpackCache.set(tpackKey, out);
    return out;
  };
  /** game mesh path (relative to mesh/) + optional tpack (relative to texturepack/) -> {mesh, tpack, textures} */
  const assetRef = (meshGame, tpackGame, ctx, root = 'mesh') => {
    const mg = String(meshGame ?? '').trim();
    if (!mg || mg === '0') return null;
    const mesh = gamePathToData(root, mg);
    const out = {};
    if (has(mesh)) out.mesh = mesh; else { missing(mg, ctx); return null; }
    // item_shape rows 4077-4084 (ATT_EQU_*_LIGHT) author an .anim in the game tpack column (Global truth item_shape.csv col 2):
    // resolve it under anim/ and keep the mesh-derived tpack, instead of reporting texturepack/...anim missing.
    if (/\.anim$/i.test(String(tpackGame ?? '').trim())) { const ak = gamePathToData('anim', String(tpackGame).trim()); if (has(ak)) out.anim = ak; else missing(String(tpackGame).trim(), ctx); tpackGame = null; }
    let tp = tpackGame && String(tpackGame).trim() && String(tpackGame).trim() !== '0' ? gamePathToData('texturepack', tpackGame) : null;
    if (!tp || !has(tp)) {
      if (tp) missing(String(tpackGame).trim(), ctx);
      const conv = mesh.replace(/^mesh\//, 'texturepack/').replace(/\.mesh$/, '.tpack');
      tp = has(conv) ? conv : null;
    }
    if (tp) { out.tpack = tp; const tx = texturesOf(tp, mesh, ctx); if (tx && tx.length) out.textures = tx; }
    return out;
  };
  const invExtras = (meshKey) => {
    const o = {};
    const a = meshKey.replace(/^mesh\//, 'anim/').replace(/\.mesh$/, '.anim');
    const s = meshKey.replace(/^mesh\//, 'skel/').replace(/\.mesh$/, '.skel');
    if (has(a)) o.anim = a;
    if (has(s)) o.skel = s;
    return o;
  };

  // item_shape.csv
  const shapeRowsRaw = csvRows('script/shape/item_shape.csv');
  const shapeHeader = shapeRowsRaw[0].map(h => String(h).trim());
  const usedShapes = new Set(fullList.map(i => i.shape).filter(Boolean));
  const shapes = {};
  const costypes = {};
  for (const r of shapeRowsRaw.slice(1)) {
    const id = num(r[0]); if (id === null) continue;
    const c = r.map(x => String(x ?? '').trim());
    const ctx = `item_shape ${id}`;
    const s = {};
    const game = assetRef(c[1], c[2], ctx); if (game) s.game = game;
    const inv = assetRef(c[5], c[6], ctx); if (inv) { Object.assign(inv, invExtras(inv.mesh)); s.inv = inv; }
    const field = assetRef(c[9], c[10], ctx); if (field) s.field = field;
    const left = assetRef(c[23], c[24], ctx); if (left) s.left = left;
    const n = (i) => num(c[i]);
    if (n(3)) s.effect = n(3);
    if (n(4)) s.effectAdd = n(4);
    if (n(7) !== null && n(7) !== 1) s.invScale = n(7);
    if (/true/i.test(c[8])) s.invTwoSide = true;
    if (/true/i.test(c[11])) s.fieldTwoSide = true;
    s.drop = { pos: [n(12) || 0, n(13) || 0, n(14) || 0], scale: n(15) ?? 1, rot: [c[16] || 'y', n(17) || 0] };
    if (n(18)) s.drop.effect = n(18);
    if (/true/i.test(c[19])) s.lod = true;
    if (c[20] && c[20] !== '0') { s.costype = c[20]; costypes[c[20]] = (costypes[c[20]] || 0) + 1; }
    if (n(21)) s.boneIndex = n(21);
    if (n(22)) s.targetEffect = n(22);
    if (n(25)) s.leftEffect = n(25);
    if (n(26)) s.leftEffectAdd = n(26);
    shapes[id] = s;
  }
  let shapeRefsMissing = 0;
  for (const id of usedShapes) if (!shapes[id]) shapeRefsMissing++;

  // cos_shape.csv (per-class costume / event-hat meshes; class order = pcclass index 0..14)
  const cosRows = csvRows('script/shape/cos_shape.csv');
  const cosShapes = {};
  for (const r of cosRows.slice(1)) {
    const id = num(r[0]); if (id === null) continue;
    const c = r.map(x => String(x ?? '').trim());
    const byClass = {};
    for (let k = 0; k < 15; k++) {
      const a = assetRef(c[1 + k * 3], c[2 + k * 3], `cos_shape ${id} class ${k}`);
      if (a) { const e = num(c[3 + k * 3]); if (e) a.effect = e; byClass[k] = a; }
    }
    cosShapes[id] = { byClass };
    if (/true/i.test(c[46])) cosShapes[id].lod = true;
  }
  // vehicle_shape.csv (item index -> per-class mount mesh)
  const vehRows = csvRows('script/shape/vehicle_shape.csv');
  const vehicles = {};
  for (const r of vehRows.slice(1)) {
    const id = num(r[0]); if (id === null) continue;
    const c = r.map(x => String(x ?? '').trim());
    const byClass = {};
    const seen = new Map();
    for (let k = 0; k < 15; k++) {
      const key = `${c[1 + k * 3]}|${c[2 + k * 3]}`;
      let a = seen.get(key);
      if (a === undefined) { a = assetRef(c[1 + k * 3], c[2 + k * 3], `vehicle_shape ${id} class ${k}`); seen.set(key, a); }
      if (a) byClass[k] = { ...a, effect: num(c[3 + k * 3]) || 0 };
    }
    vehicles[id] = { byClass, bone: c[46] || null, lod: /true/i.test(c[47]), vehicleIndex: num(c[48]), footStyle: num(c[49]) };
  }
  // compact vehicles: when every class uses the same asset, store it once
  for (const v of Object.values(vehicles)) {
    const vals = Object.values(v.byClass);
    if (vals.length === 15 && vals.every(x => JSON.stringify(x) === JSON.stringify(vals[0]))) { v.all = vals[0]; delete v.byClass; }
  }
  // ---- compiled action tables used by items (wings / animated weapons: numeric filenames or verified ITEM header index,
  // pets: share/action/action/pet/<petIndex>.act.<shape>.dat, mounts: share/action/action/vehicle/*.dat by header index,
  // rider poses: share/action/action/rider/<cls><FootStyle>.dat). Emitted compactly: rows [style, action, index, anim, timeLength]
  const actionFiles = { item: new Map(), pet: new Map(), vehicle: new Map(), rider: new Map(), wingrider: new Map() };
  for (const k of FILES.keys()) {
    const m = /^share\/action\/action\/(item|pet|vehicle|rider|wingrider)\/([^/]+)\.dat$/.exec(k);
    if (!m) continue;
    const n = /^(\d+)/.exec(m[2]);
    if (m[1] === 'vehicle' || m[1] === 'rider') actionFiles[m[1]].set(m[2], k); else if (n && !actionFiles[m[1]].has(Number(n[1]))) actionFiles[m[1]].set(Number(n[1]), k);
  }
  actionFiles.item = itemActionSources(FILES.keys(), key => {
    const fd = fs.openSync(FILES.get(key), 'r');
    try {
      const header = Buffer.alloc(8);
      const size = fs.readSync(fd, header, 0, header.length, 0);
      return header.subarray(0, size);
    } finally { fs.closeSync(fd); }
  }, fullList.map(item => item.action));
  const actionStats = { tables: 0, rows: 0, rowsAnimMissing: 0, skelMissing: 0, parseErrors: 0 };
  const actionCache = new Map();
  const actionTable = (key) => {
    if (!key) return null;
    if (actionCache.has(key)) return actionCache.get(key);
    let t = null;
    try {
      const a = parseCreatureActionDat(read(key));
      const rows = [];
      for (const r of a.actions) {
        if (!r.animKey) continue;
        if (!has(r.animKey)) { actionStats.rowsAnimMissing++; missing(r.animation, key); continue; }
        rows.push([r.style, r.actionId, r.index, r.animKey, Math.round(r.timeLength * 1000) / 1000, r.effect || 0]);
      }
      t = { file: key, index: a.index, rows };
      if (a.skelKey && has(a.skelKey)) t.skel = a.skelKey; else { actionStats.skelMissing++; if (a.skeleton) missing(a.skeleton, key); }
      actionStats.tables++; actionStats.rows += rows.length;
    } catch (e) { actionStats.parseErrors++; problems.push(`${key}: ${e.message}`); }
    actionCache.set(key, t);
    return t;
  };
  const itemActions = {};
  for (const it of fullList) {
    if (!it.action || itemActions[it.action] !== undefined) continue;
    const t = actionTable(actionFiles.item.get(it.action));
    itemActions[it.action] = t ? { skel: t.skel, rows: t.rows, wingRider: actionFiles.wingrider.has(it.action) ? actionFiles.wingrider.get(it.action) : undefined } : null;
  }
  for (const k of Object.keys(itemActions)) if (!itemActions[k]) delete itemActions[k];

  // pets: pet item -> share/creature/pet/pet.csv (Index = item index / PetShape) -> ShapeInfo -> script/shape/pet_shape.csv
  const petShapeRows = {};
  for (const r of csvRows('script/shape/pet_shape.csv').slice(1)) {
    const c = r.map(x => String(x ?? '').trim());
    if (!c[1]) continue;
    const a = assetRef(c[2], c[3], `pet_shape ${c[1]}`);
    petShapeRows[c[1].toLowerCase()] = { ...(a || {}), effect: num(c[4]) || undefined, lod: /true/i.test(c[5]) || undefined, glow: /true/i.test(c[6]) || undefined, effectId: num(c[7]) || undefined };
  }
  const petCreatures = {};
  {
    const rows = csvRows('share/creature/pet/pet.csv');
    const h = rows[0].map(x => String(x).trim());
    for (let ri = 1; ri < rows.length; ri++) {
      const o = {}; h.forEach((k, i) => { o[k] = String(rows[ri][i] ?? '').trim(); });
      const i = num(o.Index); if (i === null || petCreatures[i]) continue;
      petCreatures[i] = { name: loc(`pet#pet.csv#1|${ri}`) || o.Name, rank: num(o.Rank), shapeInfo: o.ShapeInfo, walkSpeed: num(o.WalkSpeed), aiKey: num(o.AIKey),
        enterEffect: num(o.EnterEffect), leaveEffect: num(o.LeaveEffect), optionGroup: num(o.PetOptionGroupID), skill: num(o.PetSkillID), bless: num(o.PetBlessID),
        raw: Object.fromEntries(h.filter(k => !['Index', 'Name', 'Rank', 'ShapeInfo'].includes(k)).map(k => [k, num(o[k]) ?? o[k]])) };
    }
  }
  const petItemShape = {};
  for (const r of csvObjects('share/item/petitem_shape.csv').rows) {
    const i = num(r.ItemIndex); if (i === null) continue;
    petItemShape[i] = { petShape: num(r.PetShape), dormancyShape: num(r.Dormancyshape), shape: num(r.shapeindex), previewHeight: num(r.previewheight) };
  }
  // pets[itemIndex] = {petIndex, sleepItem, modelItem, name, shapeInfo, mesh, tpack, textures, action, creature}
  //   petitem_shape.csv: PetShape = pet.csv Index, Dormancyshape = the "(Sleep)" item, shapeindex = the "(modelling)" item
  const pets = {};
  const petActions = {};
  let legacyPets = 0;
  for (const it of fullList) {
    if (it.slot !== 'pet') continue;
    const ps = petItemShape[it.index];
    const petIndex = ps?.petShape ?? (petCreatures[it.index] ? it.index : null);
    const pc = petIndex !== null ? petCreatures[petIndex] : null;
    if (!pc) { legacyPets++; continue; } // pre-2010 pets (Woody, Wiki, ...): no creature row; only the item_shape model
    const p = { petIndex, name: pc.name, shapeInfo: pc.shapeInfo };
    if (ps?.dormancyShape) p.sleepItem = ps.dormancyShape;
    if (ps?.shape) p.modelItem = ps.shape;
    if (ps?.previewHeight) p.previewHeight = ps.previewHeight;
    const shp = petShapeRows[String(pc.shapeInfo || '').toLowerCase()];
    if (shp?.mesh) Object.assign(p, shp);
    if (petActions[petIndex] === undefined) { const t = actionTable(actionFiles.pet.get(petIndex)); petActions[petIndex] = t ? { skel: t.skel, rows: t.rows, file: t.file } : null; }
    if (petActions[petIndex]) p.action = petIndex;
    p.creature = { rank: pc.rank, walkSpeed: pc.walkSpeed, aiKey: pc.aiKey, enterEffect: pc.enterEffect, leaveEffect: pc.leaveEffect, optionGroup: pc.optionGroup, skill: pc.skill, bless: pc.bless, raw: pc.raw };
    pets[it.index] = p;
  }
  for (const k of Object.keys(petActions)) if (!petActions[k]) delete petActions[k];
  // vehicles: action table by header index == VehicleIndex, rider pose table "<class code><FootStyle>"
  const vehicleActions = {};
  for (const [, key] of actionFiles.vehicle) { const t = actionTable(key); if (t && !vehicleActions[t.index]) vehicleActions[t.index] = { skel: t.skel, rows: t.rows, file: key }; }
  const RIDER_CODE = ['swd', 'arc', 'sor', 'sum', 'hil', 'war', 'alo', 'drg', 'sht', 'bwz', 'wsu', 'mse', 'hwa', 'mal', 'tri'];
  const riderTables = {};
  for (const [name, key] of actionFiles.rider) { const t = actionTable(key); if (t) riderTables[name] = { skel: t.skel, rows: t.rows }; }
  for (const v of Object.values(vehicles)) if (vehicleActions[v.vehicleIndex]) v.action = v.vehicleIndex;
  // money_shape.csv: the dil pile dropped on the ground (5 sizes)
  const money = {};
  for (const r of csvRows('script/shape/money_shape.csv').slice(1)) {
    const c = r.map(x => String(x ?? '').trim()); const id = num(c[0]); if (id === null) continue;
    const field = assetRef(c[9], c[10], `money_shape ${id}`);
    money[id] = { field, drop: { pos: [num(c[12]) || 0, num(c[13]) || 0, num(c[14]) || 0], scale: num(c[15]) ?? 1, rot: [c[16] || 'y', num(c[17]) || 0], effect: num(c[18]) || 0 } };
  }
  // legacy property/item/NNNN.txt (keyed by item index; the live client uses item_shape.csv)
  const legacy = {};
  let legacyFiles = 0, legacyAgree = 0, legacyCompared = 0, legacyDropSoundLines = 0;
  const parseLegacyItemTxt = (text, ctx, full = false) => {
    const kv = {};
    for (const line of text.split(/\r?\n/)) {
      const t = line.trim(); if (!t || t.startsWith('//')) continue;
      const parts = t.split(/\s+/); kv[parts[0].toLowerCase()] = parts.slice(1);
    }
    const o = {};
    if (kv.game_mesh) { const a = assetRef(kv.game_mesh[0], kv.game_tpack?.[0], ctx); if (a) o.game = full ? a : a.mesh; }
    if (kv.inv_mesh) { const a = assetRef(kv.inv_mesh[0], kv.inv_tpack?.[0], ctx); if (a) o.inv = full ? a : a.mesh; }
    if (kv.inv_anim) { const a = gamePathToData('anim', kv.inv_anim[0]); if (has(a)) o.invAnim = a; else missing(kv.inv_anim[0], ctx); }
    if (kv.inv_skel) { const a = gamePathToData('skel', kv.inv_skel[0]); if (has(a)) o.invSkel = a; else missing(kv.inv_skel[0], ctx); }
    if (kv.inv_anim_time) o.invAnimTime = num(kv.inv_anim_time[0]);
    if (kv.inv_twoside && kv.inv_twoside[0] !== '1') o.invTwoSide = num(kv.inv_twoside[0]);
    if (kv.field_pos) o.fieldPos = kv.field_pos.map(Number);
    if (kv.field_rot) o.fieldRot = kv.field_rot.map(x => (num(x) ?? x));
    if (kv.field_effectid) o.fieldEffect = num(kv.field_effectid[0]);
    if (kv.field_effect) o.fieldEffectFile = kv.field_effect[0]; // effect script name (not a data file on disk)
    // *_dropsound lines name "Item\Item_Drop_*.wav" files that are not shipped (the live client uses sound.json item classes)
    for (const s of ['inv_dropsound', 'pc_dropsound', 'mon_dropsound']) if (kv[s]) { legacyDropSoundLines++; missing(kv[s][1] || kv[s][0], ctx); }
    return o;
  };
  for (const k of FILES.keys()) {
    const m = /^property\/item\/(\d+)\.txt$/.exec(k);
    if (!m) continue;
    legacyFiles++;
    const idx = Number(m[1]);
    const o = parseLegacyItemTxt(decodeText(read(k), true), `property/item/${m[1]}.txt`);
    if (Object.keys(o).length) legacy[idx] = o;
    const it = full.get(idx);
    if (it && it.shape && shapes[it.shape]?.game && o.game) { legacyCompared++; if (shapes[it.shape].game.mesh === o.game) legacyAgree++; }
  }
  // property/item/noitem.txt: the model shown when an item has none; property/item/default.txt: the naked parts
  const noItem = has('property/item/noitem.txt') ? parseLegacyItemTxt(decodeText(read('property/item/noitem.txt'), true), 'property/item/noitem.txt', true) : null;
  const defaultParts = {};
  if (has('property/item/default.txt')) {
    const PART = { HEL: 'helmet', COT: 'coat', PAT: 'pants', BOT: 'boots', GLV: 'glove' };
    let sec = null, kv = {};
    for (const line of decodeText(read('property/item/default.txt'), true).split(/\r?\n/)) {
      const t = line.trim(); let m;
      if ((m = /^\[([A-Z]+)_([A-Z]+)\]$/.exec(t))) { sec = [m[1], m[2]]; kv = {}; continue; }
      if (/^\[\//.test(t)) {
        if (sec && PART[sec[1]]) { const a = assetRef(kv.game_mesh, kv.game_tpack, `property/item/default.txt ${sec.join('_')}`); if (a) (defaultParts[sec[0].toLowerCase()] ||= {})[PART[sec[1]]] = a; }
        sec = null; continue;
      }
      if (sec && (m = /^(\w+)\s+"?([^"]+)"?$/.exec(t))) kv[m[1].toLowerCase()] = m[2];
    }
  }

  // ---- per-class look of every visible equippable item (items-looks.json) -------------------------------------
  // assets[] = unique {mesh, tpack, textures, effect?}; looks[index] = {slot, parts?, all | byClass, left?, bone?, action?, ...}
  const assets = [];
  const assetIds = new Map();
  const assetId = (a) => {
    if (!a?.mesh) return null;
    const k = JSON.stringify(a);
    let id = assetIds.get(k);
    if (id === undefined) { id = assets.length; assets.push(a); assetIds.set(k, id); }
    return id;
  };
  const CLASS_PREFIX = ['swd', 'arc', 'sor', 'sum', 'hil', 'war', 'alo', 'drg', 'sht', 'bwz', 'wsu', 'mse', 'hwa', 'mal', 'bar'];
  const lookStats = {
    armor: 0, armorNoMesh: 0, armorSingleClass: 0, armorMultiClass: 0, armorPrefixMismatch: 0, armorPartFolderMismatch: 0,
    costume: 0, costumeCosShape: 0, costumeShapeOnly: 0, costumeNoMesh: 0, costumeHat: 0, costumeFull: 0, costumePartsInferred: 0,
    weapon: 0, weaponNoMesh: 0, weaponLeftFromShape: 0, weaponLeftFromWeaponLeft: 0, weaponAnimated: 0,
    wing: 0, wingNoMesh: 0, wingAnimated: 0, wingSkelMatchesMesh: 0,
    vehicle: 0, vehicleNoShape: 0, pet: 0, petNoVisual: 0, noBodyVisual: 0,
  };
  const lookExamples = { armorPrefixMismatch: [], armorPartFolderMismatch: [], weaponNoMesh: [], costumeNoMesh: [], wingNoMesh: [] };
  const lookEx = (k, v) => { if (lookExamples[k].length < 12) lookExamples[k].push(v); };
  const PART_FOLDER = { helmet: 'helmet', coat: 'coat', pants: 'pants', glove: 'glove', boots: 'boots' };
  const looks = {};
  const itemByIndex = new Map(fullList.map(i => [i.index, i]));
  const weaponLeftEarly = {};
  for (const r of csvObjects('script/weapon_left.csv').rows) { const a = num(r.index), b = num(r.index2); if (a !== null && b !== null) weaponLeftEarly[a] = b; }
  const baseName = (k) => String(k || '').split('/').pop().replace(/\.(mesh|skel)$/, '');
  for (const it of fullList) {
    const slot = it.slot;
    if (!slot) continue;
    const cls = [];
    for (let c = 0; c < 15; c++) if ((it.classMask >> c) & 1) cls.push(c);
    const sh = shapes[it.shape];
    const L = { slot };
    if (it.part) {
      lookStats.armor++;
      L.parts = [it.part];
      const a = assetId(sh?.game);
      if (a === null) { lookStats.armorNoMesh++; continue; }
      L.all = a;
      if (cls.length === 1) lookStats.armorSingleClass++; else lookStats.armorMultiClass++;
      const b = baseName(sh.game.mesh);
      if (!cls.every(c => b.startsWith(CLASS_PREFIX[c] + '_'))) { lookStats.armorPrefixMismatch++; lookEx('armorPrefixMismatch', `${it.index} ${it.name} classes ${cls} ${sh.game.mesh}`); }
      if (!sh.game.mesh.includes(`/${PART_FOLDER[it.part]}/`)) { lookStats.armorPartFolderMismatch++; lookEx('armorPartFolderMismatch', `${it.index} ${it.name} part ${it.part} ${sh.game.mesh}`); }
      const meshClass = CLASS_PREFIX.findIndex(p => b.startsWith(p + '_'));
      if (meshClass >= 0 && !cls.includes(meshClass)) L.meshClass = meshClass;
    } else if (slot === 'costume') {
      lookStats.costume++;
      const ct = sh?.costype;
      L.parts = COSTYPE_PARTS[ct] || COSTYPE_PARTS['11111'];
      if (!COSTYPE_PARTS[ct]) { L.partsInferred = true; lookStats.costumePartsInferred++; }
      if (L.parts.length === 1) lookStats.costumeHat++; else lookStats.costumeFull++;
      const cos = it.cosShape ? cosShapes[it.cosShape] : null;
      const byClass = {};
      for (const c of cls) { const a = assetId(cos?.byClass[c] ?? sh?.game); if (a !== null) byClass[c] = a; }
      const ids = Object.values(byClass);
      if (!ids.length) { lookStats.costumeNoMesh++; lookEx('costumeNoMesh', `${it.index} ${it.name}`); continue; }
      if (cos) lookStats.costumeCosShape++; else lookStats.costumeShapeOnly++;
      if (ids.length === cls.length && ids.every(x => x === ids[0])) L.all = ids[0]; else L.byClass = byClass;
    } else if (slot === 'weapon' || slot === 'offhand') {
      lookStats.weapon++;
      const a = assetId(sh?.game);
      if (a === null) { lookStats.weaponNoMesh++; lookEx('weaponNoMesh', `${it.index} ${it.name} shape ${it.shape}`); continue; }
      L.all = a;
      L.weaponType = 1024 + it.code;
      let left = sh.left ? assetId(sh.left) : null;
      if (left !== null) lookStats.weaponLeftFromShape++;
      else if (weaponLeftEarly[it.index] && itemByIndex.get(weaponLeftEarly[it.index])) {
        const li = itemByIndex.get(weaponLeftEarly[it.index]);
        left = assetId(shapes[li.shape]?.game);
        if (left !== null) { lookStats.weaponLeftFromWeaponLeft++; L.leftItem = li.index; if (li.action && itemActions[li.action]) L.leftAction = li.action; }
      }
      if (left !== null) L.left = left;
      if (it.action && itemActions[it.action]) { L.action = it.action; lookStats.weaponAnimated++; }
      if (sh.effect) L.effect = sh.effect;
      if (sh.leftEffect) L.leftEffect = sh.leftEffect;
    } else if (slot === 'wing') {
      lookStats.wing++;
      const a = assetId(sh?.game);
      if (a === null) { lookStats.wingNoMesh++; lookEx('wingNoMesh', `${it.index} ${it.name}`); continue; }
      L.all = a; L.bone = WING_BONE;
      if (it.action && itemActions[it.action]) {
        L.action = it.action; lookStats.wingAnimated++;
        if (baseName(itemActions[it.action].skel) === baseName(sh.game.mesh)) lookStats.wingSkelMatchesMesh++;
      }
      if (sh.effect) L.effect = sh.effect;
    } else if (slot === 'vehicle') {
      lookStats.vehicle++;
      if (!vehicles[it.index]) { lookStats.vehicleNoShape++; continue; }
      L.vehicle = it.index;
    } else if (slot === 'pet') {
      lookStats.pet++;
      if (!pets[it.index]?.mesh) { lookStats.petNoVisual++; continue; }
      L.pet = it.index;
    } else { lookStats.noBodyVisual++; continue; }
    looks[it.index] = L;
  }
  // class skeletons (bones must exist: weapon bones, wing bone)
  const CLASS_SKEL = ['swd', 'arc', 'sor', 'sum', 'hil', 'bgw', 'alo', 'drg', 'sht', 'bwz', 'wsu', 'mse', 'hwa', 'mal', 'bar'].map(p => `skel/character/${p}.skel`);
  const classBones = CLASS_SKEL.map(k => { try { return new Set(parseSkel(read(k)).bones.map(b => b.name)); } catch (e) { problems.push(`${k}: ${e.message}`); return new Set(); } });
  const wingBoneMissing = CLASS_SKEL.filter((k, c) => !classBones[c].has(WING_BONE));
  if (wingBoneMissing.length) notes.push(`wing bone ${WING_BONE} missing in ${wingBoneMissing.join(', ')}`);

  // ---- rules: class styles, weapon bones, weapon_left, slots ------------------------------------------------
  const classStyles = {};
  for (const k of FILES.keys()) {
    const m = /^share\/action\/action\/pc\/([a-z]+)\.act\.(\d+)\.dat$/.exec(k);
    if (!m) continue;
    let act; try { act = parseActionDat(read(k)); } catch (e) { problems.push(`${k}: ${e.message}`); continue; }
    const st = new Map();
    for (const r of act.records) { if (!st.has(r.style)) st.set(r.style, new Set()); st.get(r.style).add(r.action); }
    classStyles[Number(m[2])] = [...st].filter(([s, a]) => s > 0 && a.has(1) && a.has(6)).map(([s]) => s).sort((a, b) => a - b);
  }
  const weaponBones = {};
  for (const r of csvRows('script/weapon_bonename.csv').slice(1)) {
    const c = r.map(x => String(x ?? '').trim());
    const cls = num(c[0]), wt = num(c[1]); if (cls === null || wt === null) continue;
    (weaponBones[cls] ||= {})[wt] = { peaceLeft: c[2] || null, peaceRight: c[3] || null, battleLeft: c[4] || null, battleRight: c[5] || null, desc: c[6] || null };
  }
  const weaponLeft = {};
  for (const r of csvObjects('script/weapon_left.csv').rows) { const a = num(r.index), b = num(r.index2); if (a !== null && b !== null) weaponLeft[a] = b; }

  const weaponRules = {};
  for (const [code, w] of Object.entries(WEAPON_RULES)) {
    weaponRules[code] = { name: WEAPON_CODES[code]?.name || kindNames[1024 + Number(code)] || null, label: kindNames[1024 + Number(code)] || null,
      weaponType: 1024 + Number(code), column: COLUMN_BY_CODE[code] || 'right', ...w };
  }
  // every (class, weapon code) pair allowed by some item: does the class action file have the weapon's style?
  const styleCheck = { pairs: 0, ok: 0, missing: [] };
  {
    const pairs = new Map();
    for (const it of fullList) if (it.type === 4) for (let c = 0; c < 15; c++) if ((it.classMask >> c) & 1) pairs.set(`${c}:${it.code}`, (pairs.get(`${c}:${it.code}`) || 0) + 1);
    for (const [k, n] of pairs) {
      const [c, code] = k.split(':').map(Number);
      const st = weaponRules[code]?.style;
      if (st === undefined) continue;
      styleCheck.pairs++;
      if (classStyles[c]?.includes(st)) styleCheck.ok++; else styleCheck.missing.push(`class ${c} weapon code ${code} style ${st} (${n} items)`);
    }
  }
  // every weapon bone named for a (class, weaponType) that some usable weapon needs must exist in the class skeleton
  const boneCheck = { pairs: 0, bonesChecked: 0, bonesMissing: 0, pairsWithoutRow: 0, examples: [] };
  {
    const pairs = new Set();
    for (const it of fullList) {
      if (it.slot !== 'weapon' && it.slot !== 'offhand') continue;
      for (let c = 0; c < 15; c++) if ((it.classMask >> c) & 1) pairs.add(`${c}:${1024 + it.code}`);
    }
    for (const p of pairs) {
      const [c, wt] = p.split(':').map(Number);
      boneCheck.pairs++;
      const row = weaponBones[c]?.[wt];
      if (!row) { boneCheck.pairsWithoutRow++; continue; }
      const col = COLUMN_BY_CODE[wt - 1024] || 'right';
      const names = col === 'left' ? [row.peaceLeft, row.battleLeft] : col === 'both' ? [row.peaceLeft, row.peaceRight, row.battleLeft, row.battleRight] : [row.peaceRight, row.battleRight];
      for (const b of names.filter(Boolean)) {
        boneCheck.bonesChecked++;
        if (!classBones[c].has(b)) { boneCheck.bonesMissing++; if (boneCheck.examples.length < 12) boneCheck.examples.push(`class ${c} weaponType ${wt}: ${b}`); }
      }
    }
  }

  // ---- item-related globals of share/formula.ini (+ formulaex.ini overrides)
  const itemFormula = {};
  {
    const KEYS = /^(fItemRatio|byMaxItemLevel|fSameWeaponBonus|fItemSetDropRate|fDILDropRate|fBuyPriceRate|fSellPriceRate|byNormalRepairPriceRate|byDamagedRepairPriceRate|byDamagedDurabilityRate|wDualWeight|wDualSwordStatus|wDualMacStatus|wDualAxStatus|byMaxUpgradeLimit|byCanUpgradeCaronBlood|byCanUpgradeItemSafe|byCanMaxUpgrade|byCanUseMaxCaronBlood|byCanUseMaxItemSafe|byCanUseMinCaronBlood2|byUpgradeNotifyLevel|bUseUpgradeNotifyForFailed|byChaoWeaponDropRate|stStorageCostPerUnit|wDropMaxDistance|dwOwnershipLifeTime|fMonItemDropRatio|fMonMoneyDropRatio|fAuctionCommissionRatio|fConsignmentCommissionRatio)$/;
    for (const f of ['share/formula.ini', 'share/formulaex.ini']) {
      if (!has(f)) continue;
      for (const line of readText(f, false).split(/\r?\n/)) {
        const m = /^\s*(\w+)\s*,\s*([-\d.]+)f?\s*$/.exec(line);
        if (m && KEYS.test(m[1])) itemFormula[m[1]] = Number(m[2]);
      }
    }
  }

  // ---- socket-stone icons: imagetable group "Socket" (32x32 cells of ui/game/theme01/socket.dds); stone value1 = cell
  const socketIcons = {};
  const socketIconStats = { sprites: 0, outsideTexture: 0, stonesWithIcon: 0, stonesIconMissing: 0, stonesIconOutside: 0 };
  {
    const lines = decodeText(read('script/ui/com/imagetable.txt'), true).split(/\r?\n/);
    const texSize = new Map();
    const sizeOf = (k) => {
      if (texSize.has(k)) return texSize.get(k);
      let s = null;
      if (has(k)) { const b = read(k); if (b.length > 20 && b.toString('latin1', 0, 4) === 'DDS ') s = [b.readUInt32LE(16), b.readUInt32LE(12)]; }
      texSize.set(k, s);
      return s;
    };
    for (const line of lines) {
      const c = line.split(',').map(x => x.trim());
      if (c.length < 7 || c[0].toLowerCase() !== 'socket') continue;
      const idx = num(c[1]); if (idx === null) continue;
      const tex = gamePathToData('texture', c[2]);
      const rect = [num(c[3]), num(c[4]), num(c[5]), num(c[6])];
      const size = sizeOf(tex);
      const e = { texture: has(tex) ? tex : null, rect };
      if (size) { e.textureSize = size; if (rect[0] + rect[2] > size[0] || rect[1] + rect[3] > size[1]) { e.outside = true; socketIconStats.outsideTexture++; } }
      socketIcons[idx] = e; // last one wins (as in the client table)
      socketIconStats.sprites++;
    }
    for (const it of fullList) {
      if (!it.use?.socketIcon) continue;
      const s = socketIcons[it.use.socketIcon];
      if (!s) socketIconStats.stonesIconMissing++; else if (s.outside) socketIconStats.stonesIconOutside++; else socketIconStats.stonesWithIcon++;
    }
  }

  // ---- tooltip text + layout (stringtable_itemdesc keeps its markup: <color=RRGGBB>, <set=VALUE2>, <VALUE>, <MIN>, ...)
  const tooltipStrings = {};
  for (const [cate, m] of itemDescTable) { const o = {}; for (const [code, v] of m) o[code] = v.comment ? [v.text, v.comment] : v.text; tooltipStrings[cate] = o; }
  const upgradeStrings = {};
  for (const [cate, m] of parseStringTable(readText('script/string/item/stringtable_itemupgrade.txt'))) { const o = {}; for (const [code, v] of m) o[code] = v.text; upgradeStrings[cate] = o; }
  const tooltipLayout = {};
  {
    const rows = csvRows('script/itemdesc/itemdesc.csv');
    for (const r of rows.slice(1)) {
      const c = r.map(x => String(x ?? '').trim()); const t = num(c[0]), cd = num(c[1]); if (t === null || cd === null) continue;
      tooltipLayout[t * 256 + cd] = { font: num(c[2]), color: c[3], groups: c.slice(4, 19).map(x => num(x) || 0) };
    }
  }

  // ---- upgrade rules: item -> itemupgrade.csv row (category, grade, level); coverage of every +N chain link
  const upgradeRows = new Map();
  {
    const rows = csvRows('share/item/itemupgrade.csv');
    for (const r of rows.slice(1)) {
      const c = r.map(x => String(x ?? '').trim()); if (!c[0]) continue;
      upgradeRows.set(`${c[0]}|${c[1]}|${num(c[2])}`, { stone1: num(c[3]), stone2: num(c[4]), dil: num(c[5]), rate: num(c[6]), rate145: num(c[7]), penalty: c[8], value: num(c[9]) });
    }
  }
  const upgradeCoverage = { links: 0, rowFound: 0, noCategory: 0, noGrade: 0, noRow: 0, byKind: {}, examplesNoRow: [] };
  for (const it of fullList) {
    if (!it.next) continue;
    upgradeCoverage.links++;
    const kind = it.type * 256 + it.code;
    const cat = UPGRADE_CATEGORY[kind];
    const kc = upgradeCoverage.byKind[kind] || (upgradeCoverage.byKind[kind] = { label: kindNames[kind], category: cat || null, links: 0, found: 0 });
    kc.links++;
    if (!cat) { upgradeCoverage.noCategory++; continue; }
    const grade = UPGRADE_GRADE[it.rank];
    if (!grade) { upgradeCoverage.noGrade++; continue; }
    if (upgradeRows.has(`${cat}|${grade}|${it.itemLv}`)) { upgradeCoverage.rowFound++; kc.found++; }
    else { upgradeCoverage.noRow++; if (upgradeCoverage.examplesNoRow.length < 12) upgradeCoverage.examplesNoRow.push(`${it.index} ${it.name} ${cat}|${grade}|${it.itemLv}`); }
  }
  // accessories / wings with next links are upgraded by accessoryupgrade.csv (item -> result item) and wingupgrade.csv
  const accUpgradeItems = new Set();
  for (const r of csvRows('share/item/accessoryupgrade.csv').slice(1)) { const i = num(r[3]); if (i) accUpgradeItems.add(i); }
  upgradeCoverage.accessoryUpgradeRows = accUpgradeItems.size;
  upgradeCoverage.accessoryUpgradeItemsWithNext = fullList.filter(i => accUpgradeItems.has(i.index) && i.next).length;
  // wings: wingupgrade.csv (item code WINGS, rank CASH, level = itemLv)
  const wingLevels = new Set(csvRows('share/item/wingupgrade.csv').slice(1).map(r => `${String(r[0]).trim()}|${String(r[1]).trim()}|${num(r[2])}`));
  const wingLinks = fullList.filter(i => i.next && i.slot === 'wing');
  upgradeCoverage.wingLinks = wingLinks.length;
  upgradeCoverage.wingLinksWithRow = wingLinks.filter(i => wingLevels.has(`WINGS|CASH|${i.itemLv}`)).length;

  // ---- tables (upgrade, socket, sets, ...) ------------------------------------------------------------------
  const tableOf = (file, { headerRows = 1, rename = null, keep = null } = {}) => {
    if (!has(file)) { notes.push(`${file} missing`); return null; }
    const rows = csvRows(file);
    let header = headerRows > 0 ? rows[headerRows - 1].map(h => String(h).trim())
      : Array.from({ length: Math.max(...rows.map(r => r.length)) }, (_, i) => `c${i}`);
    if (rename) header = header.map((h, i) => rename[i] ?? h);
    // duplicate header names (e.g. "Group,Index,Name" repeated per class) get a numeric suffix
    const seenH = new Map();
    header = header.map(h => { if (!h) return h; const n = seenH.get(h) || 0; seenH.set(h, n + 1); return n ? `${h}_${n}` : h; });
    const out = [];
    for (const r of rows.slice(headerRows)) {
      const o = {};
      header.forEach((h, i) => { if (!h || (keep && !keep.includes(h))) return; const v = String(r[i] ?? '').trim(); if (v === '') return; o[h] = num(v) ?? v; });
      if (Object.keys(o).length) out.push(o);
    }
    return { source: file, columns: header.filter(Boolean), rows: out };
  };
  const unionSets = {};
  for (const r of csvObjects('share/item/item_union_set.csv').rows) {
    const i = num(r.INDEX); if (i === null) continue;
    const tiers = [];
    for (let k = 1; k <= 4; k++) {
      const need = num(r[`UNION_NEED_COUNT${k}`]); if (!need) continue;
      const effects = [];
      for (let e = 1; e <= 2; e++) { const id = num(r[`UNION_EFFECT_ID${k}_${e}`]); if (id) effects.push([id, num(r[`UNION_EFFECT_VALUE${k}_${e}`])]); }
      tiers.push({ need, effects });
    }
    unionSets[i] = { name: r.NAME, tiers, items: [], parts: [] };
  }
  // names through lines_eu by row number
  {
    const rows = csvRows('share/item/item_union_set.csv');
    for (let ri = 1; ri < rows.length; ri++) { const i = num(rows[ri][0]); const n = loc(`item#item_union_set.csv#1|${ri}`); if (i !== null && unionSets[i] && n) unionSets[i].name = n; }
  }
  const unionInfoFile = has('share/item/item_union_info.csv') ? 'share/item/item_union_info.csv' : 'share/item/union_item_info.csv';
  for (const r of csvRows(unionInfoFile).slice(1)) { const u = num(r[0]), i = num(r[1]); if (u !== null && i !== null && unionSets[u]) unionSets[u].items.push(i); }
  {
    const rows = csvRows('share/item/item_union_string.csv');
    for (let ri = 1; ri < rows.length; ri++) {
      const c = rows[ri].map(x => String(x ?? '').trim());
      const u = num(c[0]); if (u === null || !unionSets[u]) continue;
      unionSets[u].parts.push({ type: num(c[1]), code: num(c[2]), duplicate: num(c[3]), group: num(c[4]), label: loc(`item#item_union_string.csv#5|${ri}`) || c[5], groupLabel: loc(`item#item_union_string.csv#6|${ri}`) || c[6] || undefined });
    }
  }
  const K = (a) => a; // readability marker for the Korean-header renames below
  const tables = {
    itemUpgrade: tableOf('share/item/itemupgrade.csv', { rename: K(['itemCode', 'rank', 'level', 'stone1', 'stone2', 'costDil', 'rateUpTo144', 'rateFrom145', 'penalty', 'value']) }),
    itemUpgradeSafe: tableOf('share/item/itemupgrade_safe.csv'),
    accessoryUpgrade: tableOf('share/item/accessoryupgrade.csv', { rename: K(['mainCate', 'subCate', 'desc', 'itemIndex', 'costDil', 'successRate', 'resultItem',
      'mat1Bound', 'mat1Trade', 'mat1Count', 'mat2Bound', 'mat2Trade', 'mat2Count', 'mat3Bound', 'mat3Trade', 'mat3Count',
      'mat4Bound', 'mat4Trade', 'mat4Count', 'mat5Bound', 'mat5Trade', 'mat5Count', 'mat6Bound', 'mat6Trade', 'mat6Count',
      'penalty', 'failResultItem', 'eventText', 'eventDesc', 'sortOrder']) }),
    wingUpgrade: tableOf('share/item/wingupgrade.csv', { rename: K(['itemCode', 'rank', 'level', 'material', 'materialCount', 'costDil', 'rate', 'rate2Unused', 'penalty', 'value']) }),
    materialUpgrade: tableOf('share/item/materialupgrade.csv', { rename: K(['resultItem', 'resultCount', 'eventMatBound', 'eventMatTrade', 'eventMatCount', 'matBound', 'matTrade', 'matCount', 'costDil', 'storeType']) }),
    helmetRankChange: tableOf('share/item/helmetrankchange.csv'),
    optionUpgrade: tableOf('share/item/itemoptionupgrade.csv'),
    addSocket: tableOf('share/item/itemaddsocket.csv'),
    removeStone: tableOf('share/item/itemdelstone.csv'),
    socketStones: tableOf('share/item/itemsocket.csv', { headerRows: 2 }),
    socketMax: tableOf('share/item/socketmaxinfo.csv', { rename: K(['group', 'itemIndex', 'name', 'option1', 'name1', 'min1', 'max1', 'option2', 'name2', 'min2', 'max2', 'option3', 'name3', 'min3', 'max3', 'option4', 'name4', 'min4', 'max4']) }),
    optionMax: tableOf('share/item/optionmaxinfo.csv'),
    sellPrice: tableOf('share/item/itemsellprice.csv'),
    disassemble: tableOf('share/item/itemdisassemble.csv'),
    amplify: tableOf('share/item/itemamplify.csv'),
    itemChange: tableOf('share/item/itemchange.csv'),
    costumeDisassemble: tableOf('share/item/costumedisassemble.csv'),
    costumeSewing: tableOf('share/item/costumesewing.csv'),
    costumeSewingList: tableOf('share/item/costumesewinglist.csv'),
    costumeShapeChange: tableOf('share/item/costumeshapechange.csv'),
    costumeOption: tableOf('share/item/costume_option.csv'),
    transcendenceCostume: tableOf('share/item/transcendencecostume.csv'),
    wingDisassemble: tableOf('share/item/itemwingdisassemble.csv'),
    wingAddSocket: tableOf('share/item/itemwingsaddsocket.csv'),
    wingRemoveStone: tableOf('share/item/itemwingsdelstone.csv'),
    wingExchange: tableOf('share/item/itemwingexchange.csv', { rename: K(['groupIndex', ...CLASS_WIRING.map(w => `class${w.index}`), 'name']) }),
    wingChangeList: tableOf('share/item/wingchangelist.csv'),
    incuseOption: tableOf('share/item/incuseoption.csv'),
    incuseDice: tableOf('share/item/itemincusedice.csv'),
    incuseOptionLevels: tableOf('share/item/itemincuseoption.csv'),
    crestIncuse: tableOf('share/item/itemmunzang_incuse.csv', { rename: K(['level', 'index', 'type', 'desc', 'min', 'max']) }),
    crestOption: tableOf('share/item/itemmunzang_option.csv', { rename: K(['level', 'index', 'type', 'desc', 'min', 'max']) }),
    crestPrice: tableOf('share/item/munzang_price.csv'),
    forceSkill: tableOf('share/item/force_skill.csv'),
    runeCheck: tableOf('share/item/runeitem_check.csv'),
    slotItem: tableOf('share/item/slotitem.csv'),
    upgradeSubItem: tableOf('script/itemdesc/upgradesubitem.csv'),
    wingShapeChange: tableOf('share/item/wingshapechange.csv', { headerRows: 3 }),
    groupExpRatio: tableOf('share/item/groupexpratio.csv'),
    matchingChatItem: tableOf('share/item/matchingchatitem.csv', { rename: ['itemIndex', 'name'] }),
    disassembleInfo: tableOf('share/item/disassembleinfo.csv'),
    petItemPickup: tableOf('share/item/petitempickup.csv'),
    petCreatures: { source: 'share/creature/pet/pet.csv', names: 'lines_eu pet#pet.csv', rows: petCreatures },
  };
  // superseded / one-off conversion tables, kept raw for completeness (items-legacy.json)
  const legacyTables = {
    itemOptionOld: tableOf('share/item/itemoption.csv', { headerRows: 2 }),
    oldOptionArmor: tableOf('share/item/oldoption/itemoption_armor.csv', { headerRows: 2 }),
    oldOptionWeapon: tableOf('share/item/oldoption/itemoption_weapon.csv', { headerRows: 2 }),
    oldOptionEtc: tableOf('share/item/oldoption/itemoption_etc.csv', { headerRows: 2 }),
    optionChange: tableOf('share/item/optionchange/optionchange.csv', { headerRows: 0 }),
    optionChangeMatch: tableOf('share/item/optionchange/changeoption_matchtable.csv'),
    armorGrade: tableOf('share/item/optionchange/itemarmorgrade.csv', { headerRows: 0 }),
    weaponGrade: tableOf('share/item/optionchange/itemweapongrade.csv', { headerRows: 0 }),
    armorOptionRevision: tableOf('share/item/optionchange/armor_optionrevision.csv'),
    armorDkOptionRevision: tableOf('share/item/optionchange/armordk_optionrevision.csv'),
    weaponOptionRevision: tableOf('share/item/optionchange/weapon_optionrevision.csv'),
    oldOptionList: tableOf('share/item/optionchange/oldoptionlist.csv', { headerRows: 0 }),
  };
  for (const k of FILES.keys()) {
    const m = /^share\/item\/optionchange\/(itemoption_[a-z_]+)\.csv$/.exec(k);
    if (m) legacyTables[m[1]] = tableOf(k, { headerRows: 0 });
  }
  // English labels for the Korean crest (munzang) descriptions via lines_eu
  for (const [key, file] of [['crestIncuse', 'itemmunzang_incuse.csv'], ['crestOption', 'itemmunzang_option.csv']]) {
    const t = tables[key]; if (!t) continue;
    t.rows.forEach((row, i) => { const en = loc(`item#${file}#3|${i + 1}`); if (en) row.descEn = en; });
  }

  // ---- validation ---------------------------------------------------------------------------------------------
  const itemIdx = new Set(full.keys());
  const refCheck = {};
  const ref = (name, ok) => { const r = refCheck[name] || (refCheck[name] = { checked: 0, missing: 0, examples: [] }); r.checked++; if (!ok.ok) { r.missing++; if (r.examples.length < 8) r.examples.push(ok.ex); } };
  for (const it of fullList) {
    if (it.shape) ref('item.shape -> item_shape.csv', { ok: !!shapes[it.shape], ex: `${it.index}:${it.shape}` });
    if (it.cosShape) ref('item.cosShape -> cos_shape.csv', { ok: !!cosShapes[it.cosShape], ex: `${it.index}:${it.cosShape}` });
    if (it.prev) ref('item.prev (BeforeLevelIndex) -> item', { ok: itemIdx.has(it.prev), ex: `${it.index}:${it.prev}` });
    if (it.next) ref('item.next (NextLevelIndex) -> item', { ok: itemIdx.has(it.next), ex: `${it.index}:${it.next}` });
    for (const [c] of it.options || []) ref('item.options code -> option enum', { ok: !!optionTypes[c], ex: `${it.index}:${c}` });
    for (const [c] of it.exOptions || []) ref('item.exOptions code -> option enum', { ok: !!optionTypes[c], ex: `${it.index}:${c}` });
    for (const [a, b] of it.optionPools || []) for (const lv of [a, b]) if (lv) ref('item.optionPools level -> itemoption.dat', { ok: !!optionPools[lv], ex: `${it.index}:${lv}` });
    if (it.desc) ref('item.desc -> stringtable_item cate 20', { ok: descriptions[it.desc] !== undefined, ex: `${it.index}:${it.desc}` });
    if (it.union) ref('item.union -> item_union_set.csv', { ok: !!unionSets[it.union], ex: `${it.index}:${it.union}` });
    const kind = it.type * 256 + it.code;
    ref('item.kind -> stringtable_itemdesc cate 104', { ok: kindNames[kind] !== undefined, ex: `${it.index}:${kind}` });
    if (it.rank) ref('item.rank -> stringtable_itemdesc cate 103', { ok: rankNames[it.rank] !== undefined, ex: `${it.index}:${it.rank}` });
    if (it.slot === 'vehicle') ref('vehicle item -> vehicle_shape.csv', { ok: !!vehicles[it.index], ex: `${it.index}` });
    if (it.slot === 'pet') ref('pet item -> pet.csv creature with a mesh (legacy pets excluded)', { ok: !!pets[it.index]?.mesh || !pets[it.index], ex: `${it.index}` });
    if (it.use?.itemStatus) ref('item.use.itemStatus -> itemstatus.csv', { ok: !!itemStatus[it.use.itemStatus], ex: `${it.index}` });
    if (it.use?.socketIcon) ref('socket stone value1 -> imagetable Socket sprite inside the texture', { ok: !!socketIcons[it.use.socketIcon] && !socketIcons[it.use.socketIcon].outside, ex: `${it.index}:${it.use.socketIcon}` });
    if (it.action && (it.slot === 'wing' || it.slot === 'weapon' || it.slot === 'offhand')) ref('wing/weapon Action_Index -> share/action/action/item/<n>.dat', { ok: !!itemActions[it.action], ex: `${it.index}:${it.action}` });
    if (it.shape && shapes[it.shape]) ref('item shape -> inventory model (icon) mesh', { ok: !!shapes[it.shape].inv?.mesh, ex: `${it.index}:${it.shape}` });
    if (it.slot && it.shape && shapes[it.shape]) ref('equippable item shape -> field (drop) or game mesh', { ok: !!(shapes[it.shape].field?.mesh || shapes[it.shape].game?.mesh), ex: `${it.index}:${it.shape}` });
  }
  // map / location cross-references (teleport scrolls, event map limits, party-exp map table)
  {
    const mapIdx = new Set(csvRows('share/maplist.csv').slice(1).map(r => num(r[0])).filter(x => x !== null));
    const locMap = new Map();
    for (const r of csvRows('share/arrange/location.csv').slice(1)) { const i = num(r[0]); if (i !== null) locMap.set(i, num(r[2])); }
    for (const it of fullList) {
      if (it.use?.teleport) {
        ref('teleport scroll value1 -> share/arrange/location.csv', { ok: locMap.has(it.use.teleport), ex: `${it.index}:${it.use.teleport}` });
        if (locMap.has(it.use.teleport)) ref('teleport location map -> share/maplist.csv', { ok: mapIdx.has(locMap.get(it.use.teleport)), ex: `${it.index}:${locMap.get(it.use.teleport)}` });
      }
    }
    for (const [i, r] of rawFull) if (r.csvMapLimit) ref('event item MapLimit -> share/maplist.csv', { ok: mapIdx.has(r.csvMapLimit), ex: `${i}:${r.csvMapLimit}` });
    for (const row of tables.groupExpRatio?.rows || []) ref('groupexpratio MapIndex -> share/maplist.csv', { ok: mapIdx.has(row.MapIndex), ex: `${row.MapIndex}` });
  }
  for (const [p, pv] of Object.entries(pets)) { if (pv.sleepItem) ref('pet sleepItem (Dormancyshape) -> item', { ok: itemIdx.has(pv.sleepItem), ex: `${p}:${pv.sleepItem}` }); if (pv.modelItem) ref('pet modelItem (shapeindex) -> item', { ok: itemIdx.has(pv.modelItem), ex: `${p}:${pv.modelItem}` }); }
  for (const [v, vv] of Object.entries(vehicles)) {
    ref('vehicle VehicleIndex -> share/action/action/vehicle table', { ok: vv.action !== undefined, ex: `${v}:${vv.vehicleIndex}` });
    for (let c = 0; c < 15; c++) ref('vehicle FootStyle -> rider pose table <class><FootStyle>', { ok: !!riderTables[`${RIDER_CODE[c]}${vv.footStyle}`], ex: `${v}:${RIDER_CODE[c]}${vv.footStyle}` });
  }
  for (const [i, L] of Object.entries(looks)) {
    for (const a of [L.all, L.left, ...Object.values(L.byClass || {})]) if (a !== undefined) ref('looks asset id -> assets[]', { ok: !!assets[a], ex: `${i}:${a}` });
    if (L.action) ref('looks action -> items-actions.json item table with skeleton', { ok: !!itemActions[L.action]?.skel, ex: `${i}:${L.action}` });
  }
  for (const [u, s] of Object.entries(unionSets)) {
    for (const i of s.items) ref('union set item -> item', { ok: itemIdx.has(i), ex: `${u}:${i}` });
    for (const t of s.tiers) for (const [c] of t.effects) ref('union set effect -> option enum', { ok: !!optionTypes[c], ex: `${u}:${c}` });
  }
  for (const [p, pk] of Object.entries(packages)) {
    ref('package item -> item', { ok: itemIdx.has(Number(p)), ex: p });
    for (const [i] of pk.items) ref('package content -> item', { ok: itemIdx.has(i), ex: `${p}:${i}` });
  }
  for (const [a, b] of Object.entries(weaponLeft)) { ref('weapon_left index -> item', { ok: itemIdx.has(Number(a)), ex: a }); ref('weapon_left index2 -> item', { ok: itemIdx.has(b), ex: `${a}:${b}` }); }
  // itemset.csv (monster drop sets) item indices
  {
    const rows = csvRows('share/item/itemset.csv');
    const hdr = rows[0].map(h => String(h).trim());
    const cols = hdr.map((h, i) => (/^Set\d+_ItemIndex$/.test(h) ? i : -1)).filter(i => i >= 0);
    for (const r of rows.slice(1)) for (const ci of cols) { const v = num(r[ci]); if (v) ref('itemset.csv (drop sets) item -> item', { ok: itemIdx.has(v), ex: `${r[0]}:${v}` }); }
  }
  // tables with item indices
  const tableItemCols = { itemChange: ['SourceItemIndex', 'DestItemIndex'], amplify: ['RESOURCE_INDEX', 'TARGET_INDEX'], accessoryUpgrade: ['itemIndex', 'resultItem'], helmetRankChange: ['BeforItem', 'AfterItem'], costumeDisassemble: ['ItemIndex', 'Output_Item'] };
  for (const [t, cols] of Object.entries(tableItemCols)) for (const row of tables[t]?.rows || []) for (const c of cols) if (typeof row[c] === 'number' && row[c]) ref(`${t}.${c} -> item`, { ok: itemIdx.has(row[c]), ex: `${row[c]}` });
  // weapon rules: every emitted style exists in the style enum; class styles cover the starter weapons
  for (const [code, w] of Object.entries(weaponRules)) for (const s of [w.style, w.altStyle, w.dual, ...Object.values(w.withOffhand || {})]) if (s !== undefined && !STYLE_NAMES[s]) problems.push(`weapon code ${code}: unknown style ${s}`);

  // asset path audit: every data-key-looking string in the output must exist
  const out = {
    items: null, visual: { shapes, cosShapes, vehicles, pets, money, noItem, defaultParts, legacy },
    looks: { assets, looks }, actions: { item: itemActions, pet: petActions, vehicle: vehicleActions, rider: riderTables },
  };
  let pathCount = 0, pathMissing = 0;
  const walk = (o) => {
    if (typeof o === 'string') { if (/^(mesh|texture|texturepack|anim|skel|sound|property|share|script)\//.test(o)) { pathCount++; if (!has(o) || o !== o.toLowerCase()) { pathMissing++; if (pathMissing < 20) problems.push(`emitted path does not exist: ${o}`); } } return; }
    if (Array.isArray(o)) { for (const x of o) walk(x); return; }
    if (o && typeof o === 'object') for (const v of Object.values(o)) walk(v);
  };
  walk(out.visual); walk(out.looks); walk(out.actions); walk(socketIcons);
  // de-duplicate animation paths of the action tables: rows[k][3] becomes an index into actions.anims
  {
    const animIds = new Map();
    const anims = [];
    for (const group of Object.values(out.actions)) for (const t of Object.values(group)) {
      t.rows = t.rows.map(r => {
        let id = animIds.get(r[3]);
        if (id === undefined) { id = anims.length; anims.push(r[3]); animIds.set(r[3], id); }
        return [r[0], r[1], r[2], id, r[4], r[5]];
      });
    }
    out.actions = { anims, ...out.actions };
  }

  const counts = {
    items: itemIdx.size, fromItemDat: dat.records.length, csvOnly: itemIdx.size - dat.records.length,
    bySource: Object.entries(fullList.reduce((a, i) => { a[i.src] = (a[i.src] || 0) + 1; return a; }, {})).reduce((a, [k, v]) => { a[k] = v; return a; }, {}),
    byType: Object.entries(fullList.reduce((a, i) => { const t = ITEM_TYPES[i.type] || `type${i.type}`; a[t] = (a[t] || 0) + 1; return a; }, {})).reduce((a, [k, v]) => { a[k] = v; return a; }, {}),
    bySlot: fullList.reduce((a, i) => { const k = i.slot || 'none'; a[k] = (a[k] || 0) + 1; return a; }, {}),
    names: { ...nameSources, stillKorean: koreanNames },
    shapes: Object.keys(shapes).length, shapesUsed: usedShapes.size, shapeRefsMissing, cosShapes: Object.keys(cosShapes).length,
    vehicles: Object.keys(vehicles).length, pets: Object.keys(pets).length, legacyPets, legacyFiles, legacyWithData: Object.keys(legacy).length,
    legacyGameMeshAgreesWithItemShape: `${legacyAgree}/${legacyCompared}`, legacyDropSoundLines,
    optionPoolLevels: Object.keys(optionPools).length, optionPoolRows: optDat.length, optionTypes: Object.keys(optionTypes).length,
    unionSets: Object.keys(unionSets).length, packages: Object.keys(packages).length, itemStatus: Object.keys(itemStatus).length,
    descriptions: Object.keys(descriptions).length, tpacksParsed: tpackCache.size, assetPaths: pathCount, assetPathsMissing: pathMissing,
    missingGameAssets: missingAssets.size, csvRowsNotInDat: csvDropped.length, retired: fullList.filter(i => i.retired).length, compiled: datCounts,
    looks: Object.keys(looks).length, lookAssets: assets.length, itemActionTables: Object.keys(itemActions).length, riderTables: Object.keys(riderTables).length,
    socketIcons: Object.keys(socketIcons).length, tooltipLayouts: Object.keys(tooltipLayout).length,
  };
  const categoryByKind = {};
  for (const k of new Set(fullList.map(i => i.type * 256 + i.code))) categoryByKind[k] = categoryOf(Math.floor(k / 256), k % 256);
  const report = {
    csvSources: csvStats, csvVsDat: compare, csvRowsNotInDat: csvDropped.slice(0, 200), optionDatVsCsv: { joined: optJoined, agree: optAgree, of: optDat.length },
    looks: lookStats, lookExamples, costypes, actionTables: actionStats, weaponBoneCheck: boneCheck, weaponStyleCheck: styleCheck, wingBoneMissing, socketIcons: socketIconStats,
    upgradeCoverage, refCheck, problems, notes: notes.slice(0, 300), missingAssets: Object.fromEntries([...missingAssets].slice(0, 2000)),
    missingAssetsTotal: missingAssets.size, timeMs: Date.now() - t0,
  };
  return {
    items, itemDefaults, rawItems, rawDefaults, fullList, counts, report, kindNames, rankNames, descriptions, optionTypes, optionPools, classes, classStyles, weaponBones, weaponLeft,
    weaponRules, unionSets, packages, itemStatus, premiere, tables, legacyTables, visual: out.visual, looks: out.looks, actions: out.actions, walk, problems,
    socketIcons, tooltipStrings, tooltipLayout, upgradeStrings, categoryByKind, riderCodes: RIDER_CODE, upgradeRows, itemFormula,
  };
}

/**
 * --verify: independent checks on the written files.
 *  1. spot-check: re-read 12 items straight from the raw bytes of item.dat / itemevent.dat (fixed offsets, no layout
 *     table) and from their CSV row (by header name), and compare with items.json;
 *  2. cross-file references: item indices used by the other gamedata/*.json builders must exist in items.json.
 */
async function verify({ dataRoot, outDir, gamedataDir = outDir }) {
  const J = JSON.parse(fs.readFileSync(path.join(outDir, 'items.json'), 'utf8'));
  const V = JSON.parse(fs.readFileSync(path.join(outDir, 'items-visual.json'), 'utf8'));
  const LK = JSON.parse(fs.readFileSync(path.join(outDir, 'items-looks.json'), 'utf8'));
  const item = (i) => (J.items[i] ? { ...J.itemDefaults, ...J.items[i] } : null);
  const raw = {};
  for (const [part, f] of [['item.dat', 'share/item/item.dat'], ['itemevent.dat', 'share/item/itemevent/itemevent.dat']]) {
    const b = fs.readFileSync(path.join(dataRoot, f));
    for (let o = 0; o < b.length; o += 565) raw[b.readUInt32LE(o + 128)] = { part, b, o };
  }
  const L = parseLinesEu(fs.readFileSync(path.join(dataRoot, 'script/lines_eu')), { keyFilter: (k) => k.startsWith('item') });
  const csvCache = {};
  const csvRow = (file, idx) => {
    if (!csvCache[file]) { const rows = parseCSV(decodeText(fs.readFileSync(path.join(dataRoot, file)), true)); csvCache[file] = { h: rows[0].map(s => String(s).trim()), rows }; }
    const C = csvCache[file];
    const r = C.rows.find((x, k) => k > 0 && Number(String(x[0]).trim()) === idx);
    if (!r) return null;
    const o = {}; C.h.forEach((h, k) => { if (!(h in o)) o[h] = String(r[k] ?? '').trim(); });
    return o;
  };
  const SRC_CSV = { weapon: 'share/item/itemweapon.csv', armor: 'share/item/itemarmor.csv', accessory: 'share/item/itemaccessory.csv', etc: 'share/item/itemetc.csv',
    etc_socket: 'share/item/itemetc_socket.csv', cash: 'share/item/itemcash.csv', mileage: 'share/item/itemmileage.csv', event_etc: 'share/item/itemevent/etcevent.csv',
    event_cash: 'share/item/itemevent/cashevent.csv', event_accessory: 'share/item/itemevent/accessoryevent.csv' };
  const pick = [810030, 810039, 100094, 980561, 6301, 7439, 57043, 3151, 3917, 1751281, 62001];
  const firstOf = (pred) => Number(Object.keys(J.items).find(i => pred(item(Number(i)))));
  pick.push(firstOf(it => it.src === 'mileage'), firstOf(it => it.type === 0 && it.code === 1), firstOf(it => it.type === 0 && it.code === 4), firstOf(it => it.retired));
  let spotFail = 0, csvDiffs = 0;
  console.log('\n--verify 1: spot-check against raw bytes and CSV rows');
  for (const idx of pick.filter(Boolean)) {
    const it = item(idx); if (!it) { console.log(`  ${idx}: not in items.json`); spotFail++; continue; }
    const r = raw[idx];
    const chk = [];
    // raw-byte comparisons must agree; CSV comparisons are informational (the CSVs are an older snapshot of item.dat)
    const cmp = (label, a, b, info = false) => { const ok = JSON.stringify(a) === JSON.stringify(b); if (!ok && !info) spotFail++; if (!ok && info) csvDiffs++; chk.push(`${label} ${ok ? 'ok' : `${info ? 'differs (csv is older)' : 'MISMATCH'} json=${JSON.stringify(a)} ${info ? 'csv' : 'raw'}=${JSON.stringify(b)}`}`); };
    if (r) {
      const { b, o } = r;
      let e = o + 204; while (e < o + 332 && (b[e] || b[e + 1])) e += 2;
      const key = b.toString('utf16le', o + 204, e);
      const id = L.csvKeys.get(key);
      cmp('name', it.name, id !== undefined ? L.strings.get(id) : null);
      cmp('type/code', [it.type, it.code], [b.readUInt32LE(o + 141), b[o + 145]]);
      cmp('rank', it.rank, b.readUInt32LE(o + 137));
      cmp('reqLv', it.reqLv, b.readUInt16LE(o + 190));
      cmp('price/sell', [it.price, it.sell], [b.readUInt32LE(o + 194), b.readUInt32LE(o + 198)]);
      cmp('shape', it.shape, b.readUInt32LE(o + 163));
      cmp('melee', it.melee, [b.readUInt16LE(o + 505), b.readUInt16LE(o + 507)]);
      cmp('def', it.def, [b.readUInt16LE(o + 519), b.readUInt16LE(o + 521)]);
      cmp('stack', it.stack, b.readUInt16LE(o + 334));
      cmp('next', it.next, b.readUInt32LE(o + 542));
      chk.push(`[${r.part} rec ${o / 565} key ${key}]`);
    } else chk.push('[csv-only]');
    const c = SRC_CSV[it.src] ? csvRow(SRC_CSV[it.src], idx) : null;
    if (c) {
      const info = !!r;
      cmp('csv ReqLv', it.reqLv, Number(c.ReqLv), info);
      cmp('csv Price', it.price, Number(c.Price), info);
      cmp('csv ItemShape', it.shape, Number(c.ItemShape), info);
      if (c['Level 0 Melee Min Attack'] !== undefined) cmp('csv melee', it.melee, [Number(c['Level 0 Melee Min Attack']), Number(c['Level 0 Melee Max Attack'])], info);
      if (c['Level 0 Defence Min'] !== undefined) cmp('csv def', it.def, [Number(c['Level 0 Defence Min']), Number(c['Level 0 Defence Max'])], info);
      chk.push(`csv name "${c.Name}"`);
    } else chk.push('(no csv row)');
    const look = LK.looks[idx];
    const asset = look ? LK.assets[look.all ?? Object.values(look.byClass || {})[0]] : null;
    console.log(`  ${idx} "${it.name}" t${it.type}/${it.code} slot=${it.slot || '-'} class=${it.classMask} lv${it.reqLv} ` +
      `inv=${V.shapes[it.shape]?.inv?.mesh || '-'} look=${asset?.mesh || look?.vehicle || look?.pet || '-'}\n      ${chk.join(' | ')}`);
  }
  // 2. cross-file item references
  console.log('\n--verify 2: item indices referenced by other gamedata files');
  const REF_KEYS = new Set(['item', 'priceItem', 'priceItemAlt', 'ItemIndex', 'WinRewardItemIndex', 'LoseRewardItemIndex', 'itemIndex', 'specialItem']);
  let xMissing = 0;
  for (const f of fs.readdirSync(gamedataDir)) {
    if (!/\.json$/.test(f) || /^items/.test(f) || f === 'gmcommands_items.json') continue;
    let G; try { G = JSON.parse(fs.readFileSync(path.join(gamedataDir, f), 'utf8')); } catch { continue; }
    let checked = 0, miss = 0; const ex = [];
    const note = (v) => { if (!Number.isInteger(v) || v <= 0) return; checked++; if (!J.items[v]) { miss++; if (ex.length < 6) ex.push(v); } };
    const walk = (o, k) => {
      if (Array.isArray(o)) {
        if (k === 'items') for (const x of o) { if (typeof x === 'number') note(x); else if (Array.isArray(x) && typeof x[0] === 'number') note(x[0]); }
        for (const x of o) if (x && typeof x === 'object') walk(x, null);
        return;
      }
      if (o && typeof o === 'object') for (const [kk, v] of Object.entries(o)) {
        if (kk === 'report' || kk === 'unused') continue;
        if (typeof v === 'number' && REF_KEYS.has(kk)) note(v); else if (v && typeof v === 'object') walk(v, kk);
      }
    };
    walk(G, null);
    if (checked) { console.log(`  ${f}: ${checked - miss}/${checked} item refs resolve${miss ? ` (missing e.g. ${ex.join(' ')})` : ''}`); xMissing += miss; }
  }
  console.log(`\n--verify: spot-check raw mismatches ${spotFail} (csv snapshot differences ${csvDiffs}), cross-file item refs missing ${xMissing}`);
  return spotFail;
}

function writeJson(file, obj) {
  const s = JSON.stringify(obj);
  fs.writeFileSync(file, s);
  return s.length;
}

async function main() {
  const args = process.argv.slice(2);
  const arg = (k, d) => { const i = args.indexOf(k); return i >= 0 ? args[i + 1] : d; };
  const here = path.dirname(fileURLToPath(import.meta.url));
  const dataRoot = path.resolve(arg('--data', path.join(here, '..', '..', 'data', 'unpacked', 'data')));
  const outDir = path.resolve(arg('--out', path.join(here, '..', 'gamedata')));
  const verbose = args.includes('--verbose');
  const R = await build({ dataRoot, verbose });
  const now = new Date().toISOString();
  const head = (what) => ({ version: 1, generatedBy: 'tools/build-items.mjs', generatedAt: now, dataRoot: 'data/unpacked/data', what });
  const sizes = {};
  sizes['items.json'] = writeJson(path.join(outDir, 'items.json'), {
    ...head('every item: stats, requirements, prices, stacks, options, upgrade chain, slot, visual shape refs'),
    files: { visual: 'items-visual.json', looks: 'items-looks.json', actions: 'items-actions.json', options: 'items-options.json', tables: 'items-tables.json', raw: 'items-raw.json', legacy: 'items-legacy.json' },
    conventions: {
      classMask: 'bit c set = class c (pcclass index 0..14, see enums.classes) may use the item',
      kind: 'type*256+code; enums.kindNames[kind] = the tooltip "Type:" label (stringtable_itemdesc cate 104); enums.categoryByKind[kind] = coarse UI category',
      stats: 'melee/magic/ranged/def = [min,max] at +0 of THIS item index; +N upgrades are separate items linked by prev/next (itemLv = N)',
      options: '[optionTypeCode, value] pairs; names/labels in items-options.json optionTypes',
      optionPools: '3 random-option slots, each [minLevel, maxLevel] = itemoption.dat option levels to draw from (items-options.json pools)',
      price: 'Dil buy price; sell = the NPC buy-back price stored in the compiled table (0 = cannot be sold for dil, see docs/formats/items.md)',
      period: 'lifetime in seconds (0 = permanent)',
      icon: 'the inventory shows a 3D model, not a sprite: items-visual.json shapes[item.shape].inv {mesh, tpack, textures, anim?, skel?}; socket stones also have a 2D socket sprite (use.socketIcon -> enums.socketIcons)',
      visuals: 'shape -> items-visual.json shapes[shape]; per-class look of every equippable item: items-looks.json looks[index] (+ assets[])',
      defaults: 'an item stores only the fields that differ from itemDefaults: always read items as {...itemDefaults, ...items[index]}',
      index: 'items is keyed by item index (the number used by drops, shops, quests, packages, GM commands)',
      names: 'English from script/lines_eu (the name key stored in item.dat); ~3% of items only have a Korean name in the EU client (region-specific items), kept as is',
    },
    enums: {
      types: ITEM_TYPES, kindNames: R.kindNames, categoryByKind: R.categoryByKind, rankNames: R.rankNames, classes: R.classes,
      soundClassNote: 'item.quality = the item sound class of gamedata/sound.json codes.itemClass (drop/pick/equip/get sounds)',
      styleNames: STYLE_NAMES, socketIcons: R.socketIcons,
    },
    tooltip: {
      note: 'strings[cate][code] = raw text with client markup (<color=RRGGBB>..</color>, <set=VALUE2> = jump to the value column, <VALUE>/<MIN>/<MAX>/<RANK>/<CODE>/<GRADE> placeholders); a [text, comment] pair when the code carries a comment (cate 502 option labels: comment = option enum name). layout[kind] = script/itemdesc/itemdesc.csv {font, color (name colour), groups[15] (1 = show tooltip block N)}',
      strings: R.tooltipStrings, layout: R.tooltipLayout,
    },
    equipment: {
      slots: EQUIP_SLOTS, slotGroups: SLOT_GROUPS, reserveSetOffset: 100,
      weaponRules: R.weaponRules, classStyles: R.classStyles, weaponBones: R.weaponBones, weaponLeft: R.weaponLeft,
      wingBone: WING_BONE, wingEffectTable: WING_EFFECT_INFO, costypeParts: COSTYPE_PARTS, riderCodes: R.riderCodes, formula: R.itemFormula,
      upgrade: { categoryByKind: UPGRADE_CATEGORY, gradeByRank: UPGRADE_GRADE, penalties: UPGRADE_PENALTY, table: 'items-tables.json itemUpgrade (key: itemCode|rank|level)' },
      unionSets: R.unionSets,
    },
    descriptions: R.descriptions,
    counts: R.counts,
    report: R.report,
    itemDefaults: R.itemDefaults,
    items: R.items,
  });
  sizes['items-visual.json'] = writeJson(path.join(outDir, 'items-visual.json'), {
    ...head('item visuals: game/inventory/field/left-hand meshes with tpacks and resolved textures'),
    conventions: {
      asset: '{mesh, tpack?, textures?[{material, diffuse?, specular?, glow?}]} - textures resolved from the tpack exactly like character parts (characters.md)',
      shapes: 'shapes[item_shape index] = {game? (equipped/held mesh), inv? (inventory model = the item icon; + anim/skel when the model is animated), field? (dropped-on-ground mesh), left? (left-hand mesh), effect?, effectAdd?, invScale?, invTwoSide?, fieldTwoSide?, drop {pos, scale, rot:[axis, degrees], effect?}, lod?, costype? ("10000" hat / "11111" full body), boneIndex?, targetEffect?, leftEffect?, leftEffectAdd?}',
      cosShapes: 'cosShapes[cos_shape index].byClass[class] = per-class costume asset (+effect)',
      vehicles: 'vehicles[item index] = {all | byClass (mount asset), bone (rider attach bone name), lod, vehicleIndex, footStyle (rider pose), action (items-actions.json vehicle[])}',
      pets: 'pets[item index] = {petIndex, name, shapeInfo, mesh/tpack/textures, sleepItem, modelItem, previewHeight?, action (items-actions.json pet[]), creature {...pet.csv}}',
      money: 'money[0..4] = dil pile models on the ground (script/shape/money_shape.csv); pick by amount tier',
      noItem: 'fallback model when an item has no shape (from property/item/noitem.txt)',
      defaultParts: 'naked part meshes per class code, the part an unequipped slot shows (from property/item/default.txt)',
      legacy: 'legacy[item index] = property/item/<index>.txt (older per-item model files; mesh keys only; the live client uses item_shape.csv)',
    },
    ...R.visual,
  });
  sizes['items-raw.json'] = writeJson(path.join(outDir, 'items-raw.json'), {
    ...head('unknown / unused item columns kept raw: item.dat bytes without a known meaning, CSV-only columns, lines_eu row'),
    columns: RAW_COLUMN_NOTES, defaults: R.rawDefaults, items: R.rawItems,
  });
  sizes['items-options.json'] = writeJson(path.join(outDir, 'items-options.json'), {
    ...head('option-type enum and random option pools'),
    poolColumns: ['index', 'type', 'min', 'max', 'limit', 'table'],
    optionTypes: R.optionTypes, pools: R.optionPools,
  });
  sizes['items-tables.json'] = writeJson(path.join(outDir, 'items-tables.json'), {
    ...head('upgrade / socket / crest / costume / wing / disassembly tables, packages, buff items, premiere items'),
    packages: R.packages, itemStatus: R.itemStatus, premiere: R.premiere, upgradeStrings: R.upgradeStrings, ...R.tables,
  });
  sizes['items-looks.json'] = writeJson(path.join(outDir, 'items-looks.json'), {
    ...head('per-class look of every visible equippable item: which character parts it replaces and with which mesh/tpack/textures'),
    conventions: {
      looks: 'looks[itemIndex] = {slot, parts?, all?: assetId (same for every allowed class), byClass?: {class: assetId}, left?: assetId (left-hand mesh), leftItem?, weaponType?, bone?, action?, leftAction?, effect?, vehicle?, pet?, meshClass?, partsInferred?}',
      assets: 'assets[assetId] = {mesh, tpack?, textures?[{material, diffuse, specular?, glow?}], effect?}',
      parts: 'character parts the item replaces (helmet/coat/pants/glove/boots, see characters.md). Costumes: Costype 10000 = helmet only (hats), 11111 = all five parts (full-body mesh incl. head)',
      weapons: 'attach to equipment.weaponBones[class][weaponType] (battle/peace columns per equipment.weaponRules[code].column); left mesh goes to the left column bone',
      wings: 'attach to bone equipment.wingBone; animate with items-actions.json item[action] (style/action rows mirror the character)',
      vehicle: 'items-visual.json vehicles[vehicle]; pet: items-visual.json pets[pet]',
      meshClass: 'present when the mesh belongs to a different class than the item allows (data errors in the client, e.g. Sanctus +4 set)',
    },
    ...R.looks,
  });
  sizes['items-actions.json'] = writeJson(path.join(outDir, 'items-actions.json'), {
    ...head('action tables (skeleton + animation per action) of animated items and mount rider poses'),
    rowColumns: ['style', 'actionId', 'index', 'animId (-> anims[animId])', 'timeLength (s)', 'effect'], actionIds: ACTION_IDS,
    conventions: {
      item: 'item[Action_Index] = {skel, rows, wingRider?}: wings and animated weapons (numeric item filenames, then a unique matching ITEM header for named exports). Play the row whose (style, action, index) matches the character, falling back to style 0',
      rider: 'rider["<class code><FootStyle>"] = character pose table while mounted (share/action/action/rider); FootStyle from items-visual.json vehicles[i].footStyle',
      pet: 'pet[petIndex] = pet creature table (share/action/action/pet/<petIndex>.act.<shape>.dat); items-visual.json pets[item].action',
      vehicle: 'vehicle[VehicleIndex] = mount creature table (share/action/action/vehicle/*.dat, header index); items-visual.json vehicles[item].action',
    },
    ...R.actions,
  });
  sizes['items-legacy.json'] = writeJson(path.join(outDir, 'items-legacy.json'), {
    ...head('superseded option tables and the one-off option-conversion tables (optionchange/, oldoption/, itemoption.csv), kept raw'),
    ...R.legacyTables,
  });
  console.log(`items: ${R.counts.items} (${R.counts.fromItemDat} compiled ${JSON.stringify(R.counts.compiled)} + ${R.counts.csvOnly} csv-only) in ${R.report.timeMs} ms`);
  console.log('by source', JSON.stringify(R.counts.bySource));
  console.log('by type', JSON.stringify(R.counts.byType));
  console.log('by slot', JSON.stringify(R.counts.bySlot));
  console.log('names', JSON.stringify(R.counts.names));
  console.log('looks', JSON.stringify(R.report.looks));
  console.log('action tables', JSON.stringify(R.report.actionTables), '| weapon bones', JSON.stringify({ ...R.report.weaponBoneCheck, examples: undefined }), '| wing bone missing in', R.report.wingBoneMissing.length);
  console.log('socket icons', JSON.stringify(R.report.socketIcons));
  console.log('weapon styles', `${R.report.weaponStyleCheck.ok}/${R.report.weaponStyleCheck.pairs} (class, weapon code) pairs have the style in the class action file; missing:`, R.report.weaponStyleCheck.missing.join('; '));
  const uc = R.report.upgradeCoverage;
  console.log('upgrade links', uc.links, 'row found', uc.rowFound, 'no category', uc.noCategory, 'no grade', uc.noGrade, 'no row', uc.noRow, 'wing links', uc.wingLinks, 'with wingupgrade row', uc.wingLinksWithRow, 'accessoryupgrade items with next', uc.accessoryUpgradeItemsWithNext);
  console.log('asset paths', R.counts.assetPaths, 'missing', R.counts.assetPathsMissing, '| game assets referenced but absent', R.counts.missingGameAssets);
  for (const [k, v] of Object.entries(R.report.refCheck)) console.log(`  ref ${k}: ${v.checked - v.missing}/${v.checked}${v.missing ? ' missing e.g. ' + v.examples.join(' ') : ''}`);
  console.log('sizes', JSON.stringify(sizes));
  if (R.problems.length) {
    console.log(`${R.problems.length} problems:`);
    for (const p of R.problems.slice(0, 60)) console.log('  ! ' + p);
    process.exitCode = 1;
  } else console.log('OK: no problems');
  if (args.includes('--verify')) { const f = await verify({ dataRoot, outDir, gamedataDir: path.resolve(arg('--gamedata', path.join(here, '..', 'gamedata'))) }); if (f) process.exitCode = 1; }
}

if (import.meta.url === pathToFileURL(process.argv[1] || '').href) main();
