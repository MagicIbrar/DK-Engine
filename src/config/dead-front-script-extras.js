// Dead Front script operations resolved by Lane 59 (2026-10-29). Every value carries its source label:
//   'older server reference' = server-ref ScriptProcess.dll (build 11.07.29) Dead_Front_<class> / _DK triggers and
//                              DekaronServer.exe provider methods (data only, nothing executed, no code copied);
//   'Global'                 = the Global client data (string tables, warp.csv / location.csv, npc csvs, itemetc).
// Former UNRESOLVED ops:
//   Op1034  = Info GiveExp(n) to every player on the map (mid boss / final boss kill)       -> bossExp
//   Op1c20  = Monster kill-all-of-id (two ids, on the final boss death)                       -> bossDeathKills
//   Op1c28  = Monster kill-all (the close step, before the treasure)                          -> closeKillAll
//   Op101ae = Item drop at cell (x, y) (the two treasure monsters)                            -> treasureDrops
//   OnLevelUp gifts (Rabble and Peer scripts only)                                            -> levelUpGifts
//   OnMissionFail = KillTimer 0 + SetTimer(0, 0): the fortress timer expires now (= timeout)  -> MISSION_FAIL
//   NPC 4161 exchange (dialog 40000 / answer 40001 after the final boss, var100 == 10)          -> NPC_4161_EXCHANGE
//   Dungeon+0x88 / +0x8c (party count / tie)                                                  -> pvpNeeded / isTie
export const SRC = Object.freeze({ ref: 'older server reference', global: 'Global' });

/** Map -> script class (older server reference IScript::Dungeon Dead_Front_<class>; DK copies use the same values). */
export const DF_CLASS_OF_MAP = Object.freeze({
  39: 'Rabble', 77: 'Rabble', 40: 'Peer', 78: 'Peer', 41: 'Baron', 79: 'Baron', 42: 'Earl', 80: 'Earl',
  43: 'Duke', 81: 'Duke', 44: 'Arch', 82: 'Arch', 60: 'Doom', 83: 'Doom', 160: 'Hell', 161: 'Hell',
});
export const DK_MAPS = Object.freeze([77, 78, 79, 80, 81, 82, 83, 161]);

// [midBoss, midExp, finalBoss, finalExp, [kill-all ids on the final boss death], [treasure monster 1, treasure monster 2]]
const C = {
  Rabble: [3016, 25871, 3023, 51743, [3022, 3031], [3350, 3351]],
  Peer: [3066, 156138, 3073, 312275, [3072, 3081], [3360, 3361]],
  Baron: [3116, 411573, 3123, 823147, [3122, 3131], [3370, 3371]],
  Earl: [3166, 931271, 3173, 1862543, [3172, 3181], [3380, 3381]],
  Duke: [3216, 1669121, 3223, 3338241, [3222, 3231], [3390, 3391]],
  Arch: [3266, 1914681, 3273, 3829362, [3272, 3281], [3400, 3401]],
  Doom: [5016, 2127352, 5023, 4254704, [5022, 5031], [3409, 3410]],
  Hell: [6158, 2340087, 6165, 4680174, [6164, 6173], [3418, 3419]],
};
// Item+0x4c(item, x, y): server cells. 64607 "Orphina's Seal", 64083 "Clear Water of Volcano" (Global itemetc names).
const TREASURE_ITEMS = [[64607, 258, 374], [64083, 255, 377]];

// Level-up gifts. Each item: room check -> give, else drop at the player; then the InformDialog popup (map string, Global
// stringtable_deadfront cate 39/77 holds 2350..3000, cate 40/78 holds 3100 / 3200). popup = code, or {classIndex: code, else}.
const LV50 = { items: [[62608, 10], [6116, 1], [6116, 1], [6116, 1]], popup: 3100 };
// lv60: the script room-checks 62608 but gives 62607 x100 (kept as the reference does it)
const LV60 = { items: [[62607, 100, 62608], [6150, 1], [3860, 20], [3861, 20]], popup: 3200 };
const GIFTS = {
  Rabble: {
    24: { items: [], popup: { 6: 2350 } },
    25: { items: [], popup: { 0: 2400, 5: 2401, 6: 2402 } },
    26: { items: [], popup: { 1: 2500, 5: 2501 } },
    27: { items: [], popup: { 0: 2600, 1: 2601, 2: 2602, 4: 2603 } },
    28: { items: [], popup: { 1: 2700, 4: 2701 } },
    29: { items: [], popup: { 0: 2800, 4: 2801 } },
    30: { items: [[6115, 1], [6115, 1], [6115, 1], [3857, 20]], popup: { 0: 2900, 2: 2901, 3: 2902, 4: 2903, 5: 2904, else: 2950 } },
    40: { items: [[62606, 100], [3859, 20]], popup: 3000 },
    50: LV50, 60: LV60,
  },
  Peer: { 50: LV50, 60: LV60 },
};

/** Per-map resolved values (null for a map outside Dead Front). */
export function deadFrontExtras(map) {
  const cls = DF_CLASS_OF_MAP[Number(map)];
  if (!cls) return null;
  const [mid, midExp, fin, finExp, kills, tre] = C[cls];
  return {
    cls, dk: DK_MAPS.includes(Number(map)), source: SRC.ref,
    bossExp: { [mid]: midExp, [fin]: finExp },                 // Op1034 GiveExp (mid boss only in stage 3, final in stage 8)
    bossDeathKills: kills.slice(),                             // Op1c20
    closeKillAll: true,                                        // Op1c28
    treasureDrops: { [tre[0]]: TREASURE_ITEMS[0].slice(), [tre[1]]: TREASURE_ITEMS[1].slice() }, // Op101ae
    levelUpGifts: GIFTS[cls] || null,
    exchange: exchangeFor(map),
  };
}

/** Level-up gift for (map, level, classIndex): {items:[[give, count, roomCheckItem?]], popup} or null. */
export function levelUpGift(map, level, classIndex) {
  const g = deadFrontExtras(map)?.levelUpGifts?.[Number(level)];
  if (!g) return null;
  const p = g.popup;
  const popup = typeof p === 'number' ? p : (p[Number(classIndex)] ?? p.else ?? null);
  if (!g.items.length && popup == null) return null;
  return { items: g.items.map(r => r.slice()), popup };
}

// NPC 4161 (Reezena) exchange: OnNPCClick 4161 with var100 == 10 opens dialog 40000; answer 40001 room-checks
// [1300008 x1 + X x10], gives both and warps (warp.csv index), else notice 110. Not in the Rabble script.
// Warp indices are the reference values; destinations are the Global warp.csv / location.csv rows.
// 11307 / 11309 (DK Arch / DK Doom) have no Global warp.csv key; the same ids are Global location rows
// (DK Chain of Fire 84 (247, 242)), used as the destination.
// PLACEMENT: neither Global (share/map/<map>/npc_*.csv) nor the older server reference places an NPC 4161 on any Dead
// Front map, and no credible online source does -> the NPC is NOT spawned (removed). The handler below only runs if a
// 4161 NPC is ever present on the map.
const EXCHANGE = {
  Peer: [1300002, 11126, 11299], Baron: [1300002, 11128, 11301], Earl: [1300003, 11130, 11303], Duke: [1300003, 11132, 11305],
  Arch: [1300004, 11134, 11307], Doom: [1300004, 11204, 11309], Hell: [1300004, 11204, 11204],
};
const WARP_DEST = {   // Global warp.csv To_LocationIndex -> location.csv (map, x, y, dir byte)
  11126: [11127, 45, 334, 252, 64], 11128: [11129, 45, 334, 252, 64], 11130: [11131, 45, 334, 252, 64], 11132: [11133, 45, 334, 252, 64],
  11134: [11135, 45, 247, 242, 64], 11204: [11205, 45, 247, 242, 64],
  11299: [11299, 84, 334, 252, 64], 11301: [11301, 84, 334, 252, 64], 11303: [11303, 84, 334, 252, 64], 11305: [11305, 84, 334, 252, 64],
  11307: [11307, 84, 247, 242, 64], 11309: [11309, 84, 247, 242, 64],
};
export const NPC_4161_EXCHANGE = Object.freeze({
  npc: 4161, dialog: 40000, answer: 40001, fullNotice: 110, needVar100: 10, give: 1300008, giveCount: 1, xCount: 10,
  placed: false, source: SRC.ref, placementSource: 'none (Global and older server reference place no 4161) - removed',
});
export function exchangeFor(map) {
  const cls = DF_CLASS_OF_MAP[Number(map)], e = EXCHANGE[cls];
  if (!e) return null;
  const warp = DK_MAPS.includes(Number(map)) ? e[2] : e[1];
  const d = WARP_DEST[warp];
  return { item: e[0], warp, dest: d ? { loc: d[0], map: d[1], x: d[2], y: d[3], dirDeg: (d[4] * 360) / 256 } : null };
}

/** OnMissionFail (older server reference): KillTimer 0, SetTimer(0, 0) -> the fortress timer fires now = the timeout
 *  path. The Dead Front scripts never start a Mission, so it is unreachable there; it maps to _timeout() if ever called. */
export const MISSION_FAIL = Object.freeze({ action: 'timeout', source: SRC.ref, reachable: false });

/** Dungeon+0x88 (older server reference): PvP needed = more than one party has at least one living member on the map.
 *  parties = [{alive: n}] or numbers (living members per party). */
export function pvpNeeded(parties) {
  return (parties || []).filter(p => (typeof p === 'number' ? p : Number(p?.alive) || 0) > 0).length > 1;
}

/** Dungeon+0x8c (older server reference): tie test on per-party scores. The reference keeps top / second with
 *  `if c > top: top = c; elif c > second: second = c` (the old top is NOT moved down) and returns top == second && top != 0.
 *  Reproduced exactly, quirk included (e.g. [5, 9, 9] -> tie; [9, 5, 9] -> tie; [9, 9] -> tie; [5, 9] -> no tie). */
export function isTie(scores) {
  let top = 0, second = 0;
  for (const v of scores || []) {
    const c = Number(typeof v === 'number' ? v : v?.score) || 0;
    if (c > top) top = c; else if (c > second) second = c;
  }
  return top === second && top !== 0;
}

/** Red cell (DekaronServer.exe Brick provider + Perform\Brick\ChangeBrick.cpp): Brick+0xc OpenRedCell -> brick state
 *  0x18, Brick+0x10 CloseRedCell -> state 0x19, Brick+0x8 Destroy -> state 8, Brick+0x4 Create. Open = the brick's
 *  cells are walkable (setPassable(uid, true)), Close = blocked. Script order (Peer / every class): OnCreate open 128;
 *  1301 open 131 + create 132; 1303 close 128 + 132; 1304 open 128; PvP start close 128; close step open 128. */
export const RED_CELL = Object.freeze({ open: { op: 0xc, state: 0x18, passable: true }, close: { op: 0x10, state: 0x19, passable: false }, source: SRC.ref });

/** 1602 (Global stringtable_deadfront: gate close effect sound). Neither the reference script (no 1601 / 1602 sends) nor
 *  Global data names a trigger -> not played (removed as a trigger). 1601 stays the Global lever sound (earlier lanes). */
export const SOUND_1602 = Object.freeze({ played: false, source: 'no trigger in Global or the older server reference - removed' });
