// Lane 65 (2026-10-29): floors wired from the OLDER SERVER REFERENCE (server-ref ScriptProcess.dll build
// 11.07.29, read as data only, never run). Global ships no script for these floors; every value below that is not
// a Global code/text/limit is labelled 'older server reference'. Nothing here is invented: a reference action
// with no 4.2.0 system is left out (named in a comment as removed), never approximated.
//
// Tables are reimplemented as data for a small event interpreter in this file:
//   timers[id]  -> actions run when a script timer fires
//   kill[mon]   -> actions run when a monster of that index dies
//   npc[npc]    -> actions run when the NPC's dialog answer is chosen (answers keyed by NPC, see note A)
// Action ops: add/set (script var 'v' or instance var 'iv'), timer/kill-timer, notice (message code), dialog,
// brickOn/brickOff (brick uid), spawn [[mon,x,y]], remove (monster index), phase, warp, mission done/show,
// limit (KillTimer(0)+SetTimer(4,sec): a new remaining time), clear, fail, exit,
// exp (reference Info provider +0x30 = DekaronServer GiveExp to the dungeon's PCs, GiveExp.cpp),
// gradeExp (reference Awakening provider +0x38 = Grade/Awakening EXP add, packet 0x25 with the grade),
// giveItem [item, count, fullNotice] (reference Item provider +0x14 inventory check -> Notice(fullNotice), else
// Item provider +0x30 GiveItem). Rewards: the reference also calls Awakening provider +0x4c (1000) after each
// grade-EXP award - a second awakening counter (packet 0x26) that 4.2.0 does not model (grade-rewards.js keeps no
// RoyalPoint), so that call is removed, not approximated.
// Conditions: ['if', [ns, n, op, k], then, else]; op == != < <= > >=; ns 'v' / 'iv' (script / instance var),
// 'item' (bag count of item n), 'space' (1 when item n fits the bag), 'class' (player class byte: 0 Azure Knight,
// 1 Segita Hunter, 2 Incar Magician, 3 Vicious Summoner, 4 Segnale, 5 Bagi - the order of Global 1100-1105),
// 'rand' (the last ['random', n, range] roll, 0..range-1: the reference buckets 100 into twenty equal 5-wide steps).
//
// Transport Ship 1-4 (52-55, server-ref-transport.js) use the reference class layout itself: an outer table
// (talk / answer / levelUp, run first) and per-phase tables (timers / kill / talk / answer). ['phaseHandler'] is the
// outer handler handing the same event to the current phase. More ops for them: random, take [item, count|'all'],
// drop [item, count] (reference Item drop at the player when the bag is full), redCellOpen [uid] (Brick+0xc,
// "Brick OpenRedCell" in DekaronServer.exe: frees the brick's cells, the brick stays).
//
// Note A (76/85/86/87): Global npc_76.csv opens dialog 21000/22000 on Shield Stones 1237/1238 and 30000/31000 on
// Shield Protection Stones 1243/1244. The reference script keys answer 21001/22001 to the first-phase stones and
// 30001/31001 to the second-phase stones; its first-phase stones are the ones the Shield Protectors spawn beside
// (291,382)/(119,297) = 1243 (294.9,385.8)/1244 (119.8,301.4), so the plan keys the handlers on the NPC.

import { TRANSPORT_SHIP } from './server-ref-transport.js';

export const SERVER_REF = 'older server reference';

// ------------------------------------------------------------------------------------------------ Karon's Fragments
// Map_76/85/86/87_Under_Crespo_Indun (identical apart from per-class mission helpers). Hallway spawns of timer 2.
const CRESPO_HALL = [[5093,384,265],[5094,385,276],[5095,374,277],[5093,377,288],[5094,373,298],[5095,368,309],[5093,363,318],[5094,355,325],[5095,342,330],[5093,333,332],[5094,323,333],[5095,311,341],[5093,307,334],[5094,286,391],[5095,285,383],[5093,294,388],[5094,293,376],[5095,301,380],[5093,305,390],[5094,405,365],[5095,397,366],[5093,395,376],[5094,391,360],[5095,380,360],[5093,372,354],[5094,327,296],[5095,314,282],[5093,289,276],[5094,277,282],[5095,269,297],[5093,305,271],[5094,277,259],[5095,266,257],[5093,255,260],[5094,245,264],[5095,238,276],[5093,235,287],[5094,238,298],[5095,244,313],[5093,248,324],[5094,251,336],[5095,247,349],[5093,250,359],[5094,240,357],[5095,200,325],[5093,201,315],[5094,209,320],[5095,218,320],[5093,297,251],[5094,298,241],[5095,306,226],[5093,323,224],[5094,300,216],[5095,295,195],[5093,285,181],[5094,275,173],[5095,266,166],[5093,254,166],[5094,251,154],[5095,322,150],[5093,317,160],[5094,330,157],[5095,264,125],[5093,261,134],[5094,255,128],[5095,241,132],[5093,228,139],[5094,221,149],[5095,217,157],[5093,220,164],[5094,221,173],[5095,225,182],[5093,225,196],[5094,229,203],[5095,239,201],[5093,247,203],[5094,255,199],[5095,262,200],[5093,185,196],[5094,175,205],[5095,186,207],[5093,193,216],[5094,198,227],[5095,208,225],[5093,218,214],[5094,196,239],[5095,187,249],[5093,178,259],[5094,168,264],[5095,110,302],[5093,117,292],[5094,126,292],[5095,133,303],[5093,120,306],[5094,200,102],[5095,208,114],[5093,194,112],[5094,200,119],[5095,190,127],[5094,180,141]];
const WARP_STONES = { 1226: [298, 394], 1227: [402, 372], 1228: [298, 394], 1229: [117, 311], 1230: [245, 360], 1231: [117, 311], 1232: [328, 152], 1233: [246, 157], 1234: [206, 103], 1235: [266, 129] };
const warpActs = (extra) => { const o = {}; for (const [n, p] of Object.entries(WARP_STONES)) o[n] = [['warp', p[0], p[1]]]; return Object.assign(o, extra); };
const hallKill = [['add', 'v', 1, 1], ['if', ['v', 1, '==', 100], [['notice', 900], ['gradeExp', 1000], ['exp', 1000000]], []]];
const hallKill2 = [['add', 'v', 1, 1], ['if', ['v', 1, '==', 100], [['notice', 900], ['gradeExp', 500], ['exp', 1000000]], []]];
const protectors = (a, b) => [['spawn', [[5096, a[0], a[1]], [5096, b[0], b[1]]]], ['timer', 3, 300]];
const stone = (mine, other, done, show, then) => [['add', 'iv', mine, 1],
  ['if', ['iv', mine, '!=', 1], [['dialog', 25000]], [['if', ['iv', other, '!=', 0], [['mission', 'done', done], ['mission', 'show', show], ...then], []]]]];
const CRESPO = {
  name: 'Under_Crespo_Indun',
  startSec: 60,                     // create: SetTimer(2,60) -> start (Global 30 "Standby")
  start: 2,
  exits: [1225, 5928],
  phases: {
    1: {
      timers: {
        // SetTimer(0,1200) = Global's 20-minute limit (director); Notice(2000) = the director's start effect
        2: [['brickOff', 101], ['brickOn', 102], ['brickOn', 103], ['brickOn', 104], ['brickOn', 105], ['spawn', CRESPO_HALL]],
        3: [['timer', 3, 300], ['set', 'v', 6, 0], ['remove', 5096], ['remove', 5096], ['spawn', [[5096, 291, 382], [5096, 119, 297]]], ['notice', 200]],
      },
      kill: {
        5093: hallKill, 5094: hallKill, 5095: hallKill,
        5096: [['add', 'v', 6, 1], ['if', ['v', 6, '==', 1], [['kill-timer', 3], ['timer', 3, 5]],
          [['if', ['v', 6, '==', 2], [['kill-timer', 3], ['add', 'v', 7, 10], ['notice', 300], ['mission', 'done', 11], ['mission', 'show', 12], ['exp', 500000], ['phase', 2]], []]]]],
      },
      npc: warpActs({
        1236: [['if', ['v', 7, '==', 10], [['warp', 152, 171]], [['notice', 400]]]],
        1243: stone(3, 4, 10, 11, protectors([291, 382], [119, 297])),
        1244: stone(4, 3, 10, 11, protectors([119, 297], [291, 382])),
      }),
    },
    2: {
      timers: {
        3: [['notice', 1000], ['timer', 9, 10]],
        9: [['brickOn', 106], ['notice', 1100], ['timer', 5, 2]],
        5: [['if', ['v', 5, '==', 10], [['clear']], [['brickOn', 107], ['timer', 6, 8]]]],
        6: [['brickOn', 108], ['timer', 7, 3]],
        7: [['brickOff', 102], ['brickOff', 103], ['brickOff', 104], ['brickOff', 105], ...[109, 110, 111, 112, 113, 114, 115, 116].map(u => ['brickOn', u]), ['timer', 8, 3]],
        8: [['notice', 1200], ['brickOff', 107], ['brickOn', 117], ['brickOff', 114], ['spawn', [[5092, 106, 157]]], ['brickOff', 100], ['limit', 900]],
      },
      kill: {
        5093: hallKill2, 5094: hallKill2, 5095: hallKill2,
        5092: [['brickOff', 116], ['spawn', [[5090, 121, 184]]], ['add', 'v', 4, 1]],
        5090: [['brickOff', 115], ['spawn', [[5089, 106, 182]]], ['add', 'v', 4, 1]],
        5089: [['brickOff', 113], ['spawn', [[5091, 122, 157]]], ['add', 'v', 4, 1]],
        5091: [['add', 'v', 4, 1], ['if', ['v', 4, '==', 4], [['add', 'v', 5, 10], ['mission', 'done', 13], ['brickOff', 118], ['gradeExp', 5000], ['exp', 1500000], ['timer', 5, 1]], []]],
      },
      npc: warpActs({
        1236: [['warp', 152, 171]],
        1237: stone(1, 2, 12, 13, [['timer', 3, 3]]),
        1238: stone(2, 1, 12, 13, [['timer', 3, 3]]),
        // answer 40001 (exit Reezena): v5==10 -> item 6008 x5 (inventory check, message 110), then exit
        1225: [['if', ['v', 5, '==', 10], [['giveItem', 6008, 5, 110]], []], ['exit']],
        5928: [['if', ['v', 5, '==', 10], [['giveItem', 6008, 5, 110]], []], ['exit']],
      }),
    },
  },
};
// 5091 kill: the reference plays Notice(1300) and the clear happens on timer 5 one second later (v5 == 10); the
// director's clear() plays Global's clearMessage 1300 itself, so the plan clears there instead of a second 1300.

// ------------------------------------------------------------------------------------------------ Quilue Liana (48)
// Map48_D_Qilue_Laina. Global keeps its 50-minute limit (3000 s); the reference timeline (180 s + 3540 s + 60 s)
// is longer, so the reference's "1 minute left" (300) and "failed" (400) notices follow Global's limit.
const QUILUE = {
  name: 'D_Qilue_Laina',
  createTimers: [[1, 180]],          // create: SetTimer(1,180)
  exits: [],
  warnBeforeEnd: 60,                 // timer 0 -> Notice(300) + SetTimer(3,60)
  endNotice: 400, endRemove: 3701,   // timer 3 -> Notice(400), Op1c20(3701)
  phases: {
    1: {
      timers: { 1: [['notice', 100], ['spawn', [[3701, 247, 266]]]] },
      kill: { 3701: [['mission', 'done', 10], ['giveItem', 6143, 1], ['notice', 200], ['clear']] },
      npc: { 3405: { 10001: [['dialog', 20000]], 20001: [['dialog', 40000]], 40001: [['exit']] } },
    },
  },
};

export const SERVER_REF_SCRIPTS = { 76: CRESPO, 85: CRESPO, 86: CRESPO, 87: CRESPO, 48: QUILUE, ...TRANSPORT_SHIP };
export const SERVER_REF_MAPS = new Set(Object.keys(SERVER_REF_SCRIPTS).map(Number));

// ------------------------------------------------------------------------------------------------ script monster X/Y
// Global scriptmonster_<n>.csv lists the monsters a floor's server script spawns, with no position. The reference
// script of the same floor spawns them at these cells (every Spawn(mon, x, y) call of the class; one entry = one
// monster). Floors not listed have no reference class and keep the 4.2.0 engine placement (no source - left as built).
export const SERVER_REF_POSITIONS = {
  49: {
    3800: [[271,245],[271,245]],
    3801: [[194,53]],
    3808: [[247,343]],
    3809: [[262,407]],
  },
  64: {
    3986: [[360,237],[355,242]],
    3987: [[354,234],[326,211],[347,210],[361,216]],
    3988: [[347,216],[322,216],[332,215],[361,211]],
    3989: [[309,209],[302,228]],
    3990: [[303,212],[302,241]],
    3991: [[298,245],[303,249],[297,223]],
    3992: [[221,256]],
    3993: [[208,255]],
  },
  66: {
    5050: [[252,83],[253,112],[251,144],[257,82],[255,272],[256,336],[257,336],[258,399],[252,420],[261,422],[256,430]],
    5051: [[255,113],[253,176],[255,208],[256,209],[256,240],[255,304],[256,368],[257,368]],
    5052: [[257,144],[255,176],[256,242],[258,273],[257,304],[256,399]],
    5053: [[256,479]],
    5054: [[256,479]],
    5055: [[256,479]],
    5056: [[256,479]],
    5057: [[256,479]],
    5058: [[256,479]],
    5059: [[256,479]],
  },
  89: {
    5300: [[180,259],[192,248],[189,246],[198,216],[186,260],[197,210],[189,269],[184,264],[219,214],[190,235],[216,210],[189,251],[191,229],[193,232],[221,208],[193,214],[190,292],[231,306],[221,320],[191,297],[189,283],[190,279],[188,297],[193,282],[194,308],[211,308],[228,304],[221,316],[213,304],[196,312],[210,304],[191,311],[180,259],[192,248],[189,246],[198,216],[186,260],[197,210],[189,269],[184,264],[219,214],[190,235],[216,210],[189,251],[191,229],[193,232],[221,208],[193,214],[190,292],[231,306],[221,320],[191,297],[189,283],[190,279],[188,297],[193,282],[194,308],[211,308],[228,304],[221,316],[213,304],[196,312],[210,304],[191,311],[244,235],[257,230],[247,236],[235,229],[237,228],[251,229],[212,236],[219,256],[213,270],[214,255],[215,236],[210,273],[263,294],[235,295],[240,291],[219,291],[259,295],[220,288],[276,283],[281,284],[278,252],[273,265],[280,247],[275,268],[239,230],[236,232],[253,231],[245,234],[256,229],[247,235]],
    5301: [[248,315],[252,315],[261,307],[267,304],[264,303],[280,312],[252,312],[290,305],[299,312],[296,308],[269,320],[280,308],[272,321],[300,308],[284,309],[273,319],[300,217],[308,274],[305,257],[304,277],[300,248],[299,254],[300,286],[297,287],[302,260],[303,273],[305,232],[301,235],[304,221],[304,241],[298,220],[298,292],[248,315],[252,315],[261,307],[267,304],[264,303],[280,312],[252,312],[290,305],[299,312],[296,308],[269,320],[280,308],[272,321],[300,308],[284,309],[273,319],[300,217],[308,274],[305,257],[304,277],[300,248],[299,254],[300,286],[297,287],[302,260],[303,273],[305,232],[301,235],[304,221],[304,241],[298,220],[298,292],[210,269],[215,258],[214,239],[218,238],[212,273],[217,254],[215,288],[236,292],[258,293],[240,296],[261,291],[214,292],[277,266],[278,286],[272,269],[280,252],[280,281],[276,249]],
    5303: [[243,275]],
  },
  91: {
    5309: [[278,177]],
    5311: [[255,265],[256,250],[286,265],[286,250]],
    5312: [[256,314],[250,327],[250,314],[252,330],[247,332],[252,317],[249,302],[248,307],[250,294],[253,302],[252,291],[255,297],[256,314],[250,327],[250,314],[252,330],[247,332],[252,317],[249,302],[248,307],[250,294],[253,302],[252,291],[255,297]],
  },
  92: {
    5313: [[264,239]],
    5314: [[319,296]],
    5315: [[309,285],[309,305],[305,285],[301,305],[305,306],[298,306],[298,285],[302,285],[294,301],[293,297],[293,293],[293,288]],
    5316: [[310,309],[307,309],[303,310],[299,309],[294,309],[294,305],[294,285],[294,282],[299,282],[303,282],[307,282],[310,282]],
    5317: [[301,265],[300,265],[302,264],[302,266],[310,266],[309,265],[311,266],[310,264],[301,265],[300,265],[302,264],[302,266],[310,266],[309,265],[311,266],[310,264],[301,265],[300,265],[302,264],[302,266],[310,266],[309,265],[311,266],[310,264]],
    5318: [[301,328],[302,327],[300,326],[302,326],[310,328],[310,328],[310,326],[311,327],[301,328],[302,327],[300,326],[302,326],[310,328],[310,328],[310,326],[311,327],[301,328],[302,327],[300,326],[302,326],[310,328],[310,328],[310,326],[311,327]],
    5321: [[211,220],[209,222],[220,226],[223,224],[224,227],[199,222],[201,224],[213,223],[197,226],[201,227],[202,238],[201,248],[201,262],[202,266],[200,235],[198,238],[198,246],[197,250],[205,262],[206,264],[198,283],[198,293],[212,294],[217,294],[217,297],[198,277],[202,280],[202,294],[199,296],[212,298],[231,296],[256,297],[248,294],[261,293],[242,294],[257,294],[260,297],[230,298],[228,295],[244,297]],
    5322: [[225,188],[232,186],[226,180],[229,188],[229,180],[229,183],[232,183],[229,185],[264,185],[264,189],[260,188],[259,183],[259,180],[264,180],[264,183],[259,186],[225,185],[225,183],[264,192],[260,192],[225,188],[232,186],[226,180],[229,188],[229,180],[229,183],[232,183],[229,185],[264,185],[264,189],[260,188],[259,183],[259,180],[264,180],[264,183],[259,186],[225,185],[225,183],[264,192],[260,192]],
  },
  93: {
    5323: [[230,293],[234,293],[238,293],[241,293],[246,293],[249,293],[253,293],[257,293],[262,293],[265,294],[231,276],[235,276],[239,275],[241,275],[245,276],[250,275],[254,275],[257,276],[261,276],[265,276]],
    5324: [[246,234],[247,243],[243,235],[252,243],[249,243],[243,243],[249,235],[243,224],[249,225],[246,225],[253,234],[252,224],[252,212],[243,212],[246,212],[250,212],[243,201],[247,201],[249,201],[252,201],[246,234],[247,243],[243,235],[252,243],[249,243],[243,243],[249,235],[243,224],[249,225],[246,225],[253,234],[252,224],[252,212],[243,212],[246,212],[250,212],[243,201],[247,201],[249,201],[252,201]],
    5325: [[248,308]],
  },
  97: {
    5337: [[255,265],[256,250],[286,265],[286,250]],
  },
};

/** Older-server-reference cells of a floor's script monster, or null. */
export function serverRefPositions(map, monster) {
  return SERVER_REF_POSITIONS[String(Number(map))]?.[String(Number(monster))] || null;
}

// ------------------------------------------------------------------------------------------------ script monster timing
// Source: older server reference, the same floor classes as SERVER_REF_POSITIONS (static reading of the timer calls).
// sec = the reference timer between the 4.2.0 stage that places the monster and its Spawn call:
//   start squad - the create handler (or the first-entry handler, guarded by var 0) arms timer 2, whose handler spawns it;
//   boss stage  - the trigger NPC answer arms the timer whose handler spawns it;
//   after       - the monster waits for that monster's kill, then sec (the timers chained from that kill, summed).
// Monsters the reference spawns straight from an answer or kill handler have no entry (they appear at once, as now).
// Monsters spawned from timer chains on events 4.2.0 has no plan for (91 5309/5311, 92 5313-5318/5321, 93 5325,
// 97 5337) and 93 5324 (timer 2 or answer 11001, whichever comes first) keep the 4.2.0 stage timing.
export const SERVER_REF_SPAWN_TIMING = {
  // 64: create SetTimer(2,60) -> timer 2 spawns 3986-3991; answer 19001 SetTimerX(5,9) -> timer 5 spawns 3992;
  //     3992 kill SetTimer(6,1) -> timer 6 SetTimerX(7,5) -> timer 7 SetTimerX(8,6) -> timer 8 spawns 3993 (1+5+6)
  64: { 3986: { sec: 60 }, 3987: { sec: 60 }, 3988: { sec: 60 }, 3989: { sec: 60 }, 3990: { sec: 60 }, 3991: { sec: 60 },
    3992: { sec: 9 }, 3993: { after: 3992, sec: 12 } },
  // 66: create SetTimer(2,20) -> timer 2 spawns 5050-5052; answers 12001-18001 SetTimerX(3..9,5) -> timers 3-9 spawn
  //     5053, 5054, 5057, 5056, 5055, 5058, 5059
  66: { 5050: { sec: 20 }, 5051: { sec: 20 }, 5052: { sec: 20 },
    5053: { sec: 5 }, 5054: { sec: 5 }, 5055: { sec: 5 }, 5056: { sec: 5 }, 5057: { sec: 5 }, 5058: { sec: 5 }, 5059: { sec: 5 } },
  // 89: create SetTimer(2,60) -> timer 2 spawns 5300/5301
  89: { 5300: { sec: 60 }, 5301: { sec: 60 } },
  // 91: first-entry handler SetTimer(2,60) -> timer 2 spawns 5312
  91: { 5312: { sec: 60 } },
  // 92: first-entry handler SetTimer(2,60) -> timer 2 spawns 5322
  92: { 5322: { sec: 60 } },
  // 49: 3800/3801 (answer 38001), 3808 (answer 27001) and 3809 (answer 15001) spawn straight from the answer: no entry
};

export function serverRefSpawnTiming(map, monster) {
  return SERVER_REF_SPAWN_TIMING[String(Number(map))]?.[String(Number(monster))] || null;
}

// ------------------------------------------------------------------------------------------------ interpreter
function test(d, st, c) {
  const [ns, n, op, k] = c;
  const v = ns === 'iv' ? st.iv[n] || 0 : ns === 'v' ? st.v[n] || 0 : probe(d, st, ns, n);
  switch (op) {
    case '==': return v === k;
    case '!=': return v !== k;
    case '<': return v < k;
    case '<=': return v <= k;
    case '>': return v > k;
    case '>=': return v >= k;
    default: return false;
  }
}

let lifeCommon = null;   // ../life/common.js (canGive / giveItem), loaded once by the first plan
function loadLife() { if (!lifeCommon) import('../life/common.js').then((m) => { lifeCommon = m; }).catch(() => {}); }

function probe(d, st, ns, n) {
  const g = d.game, hook = d.sys?.serverRefItems;
  if (ns === 'rand') return st.rand?.[n] ?? 0;
  if (ns === 'item') return Number(hook?.count ? hook.count(g, n) : d.sys?.itemCount?.([n])) || 0;
  if (ns === 'space') return (hook?.canGive || lifeCommon?.canGive)?.(g, n, 1) ? 1 : 0;
  if (ns === 'class') return Number(g?.player?.classIndex ?? g?.save?.classIndex ?? -1);
  return 0;
}

/** A table entry; '=N' is the same op list as key N of that table. */
function entry(table, key) {
  let a = table?.[key];
  if (typeof a === 'string') a = table[a.slice(1)];
  return Array.isArray(a) ? a : null;
}

function takeItem(d, st, item, count) {
  const g = d.game, hook = d.sys?.serverRefItems;
  const n = count === 'all' ? probe(d, st, 'item', item) : count;
  if (!(n > 0)) return;
  award(d, 'take', [item, n]);
  if (hook?.take) hook.take(g, item, n); else d.sys?.consumeItem?.([item], n);
}

function dropItem(d, item, count) {
  const g = d.game, hook = d.sys?.serverRefItems;
  award(d, 'drop', [item, count]);
  if (hook?.drop) { hook.drop(g, item, count); return; }
  if (!g?.loot || !g.player) return;
  const names = g.data?.monsters?.itemNames || {};
  g.loot.spawnDrop({ kind: 'item', itemIndex: item, name: names[item] || `Item #${item}`, count, stack: count > 1, grade: 'normal' }, g.player.x + 1.2, g.player.z);
}

function dialog(d, code, npc, onAnswer) {
  const dlg = d.sys?.dialog;
  if (!dlg?.open) { d.alert?.(code); return; }
  const m = d.msg?.(code);
  const strip = (t) => String(t || '').replace(/<[^>]*>/g, '').trim();
  const menu = (m?.m?.length ? m.m : [null]).map((mc) => ({
    text: (mc != null ? strip(d.text(mc)) : '') || 'OK',
    onClick: () => { dlg.close?.(); if (mc != null) onAnswer(mc); },
  }));
  dlg.open({ title: npc?.name || '', text: d.text(code), menu, options: true });
}

function warp(d, x, y) {
  const g = d.game, col = g?.world?.collision;
  let s = { x: x + 0.5, z: y + 0.5 };
  if (col?.walkableCell && !col.walkableCell(Math.floor(x), Math.floor(y))) s = col.nearestWalkable?.(x + 0.5, y + 0.5, 8) || s;
  g?.travel?.(d.map, { x: s.x, z: s.z, dirDeg: 0 });
  g?.events?.emit?.('dungeon:warp', { map: d.map, to: [s.x, s.z], source: SERVER_REF });
}

function spawn(d, st, rows) {
  if (!d.stages) d.stages = [];
  let stg = st.stage;
  if (!stg) {
    stg = { n: 960, kind: 'script-ref', objective: 'none', rows: [], opens: [], bosses: [], group: 0, spawned: true, done: false, recs: [], optional: true, source: SERVER_REF };
    d.stages.push(stg);
    st.stage = stg;
  }
  for (const [mon, x, y] of rows) {
    stg.rows.push([mon, x, y, 0, 1]);
    if (d._spawnOne) d._spawnOne(stg, mon, x + 0.5, y + 0.5, 0);
  }
}

function remove(d, st, mon) {
  const rec = (st.stage?.recs || []).find((r) => Number(r.spawn?.monsterIndex) === Number(mon) && !r.dg?.killed && !r.skip);
  if (!rec) return;
  rec.dg.killed = true;
  rec.skip = true;
  const m = rec.monster;
  if (m) { m.dead = true; m.hp = 0; m.faded = m.removable = m.fadeDone = true; if (m.group) m.group.visible = false; }
}

function mission(d, how, code) {
  const m = (d.missions || []).find((x) => Number(x.code) === Number(code));
  if (how === 'done' && m) m.done = true;
  if (how === 'show') d.serverRefMission = Number(code);
  d._refreshInfo?.();
}

function award(d, op, args) { (d.serverRefLog ||= []).push({ op, args: [...args], source: SERVER_REF }); }

/** Reference: Item+0x14 HasInventorySpace(item) false -> Notice(full); else Item+0x30 GiveItem(item, count). */
function giveItemRef(d, item, count, full) {
  const g = d.game;
  const hook = d.sys?.serverRefItems;    // isolated tests inject { canGive, giveItem, count, take, drop }
  const go = ({ canGive, giveItem }) => {
    if (full != null && !canGive(g, item, count)) { award(d, 'itemFull', [item, count]); d.alert?.(full); return; }
    award(d, 'giveItem', [item, count]);
    giveItem(g, item, count, { source: 'dungeon-script' });
  };
  if (hook) { go(hook); return; }
  import('../life/common.js').then(go).catch(() => {});
}

function setTimer(d, st, id, sec) {
  const tok = (st.timerTok[id] = (st.timerTok[id] || 0) + 1);
  d.later(sec, () => { if (st.timerTok[id] === tok && !d.disposed) fire(d, st, id); });
}

function fire(d, st, id) {
  const acts = entry(st.def.outer?.timers, id) || entry(st.def.phases[st.phase]?.timers, id);
  if (acts) run(d, st, acts, { kind: 'timers', key: id });
}

function run(d, st, acts, ctx = {}) {
  for (const a of acts) {
    const [op, ...p] = a;
    switch (op) {
      case 'if': run(d, st, test(d, st, p[0]) ? p[1] : p[2], ctx); break;
      case 'add': { const t = p[0] === 'iv' ? st.iv : st.v; t[p[1]] = (t[p[1]] || 0) + p[2]; break; }
      case 'set': { const t = p[0] === 'iv' ? st.iv : st.v; t[p[1]] = p[2]; break; }
      case 'timer': setTimer(d, st, p[0], p[1]); break;
      case 'kill-timer': st.timerTok[p[0]] = (st.timerTok[p[0]] || 0) + 1; break;
      case 'notice': {
        // Transport Ship: <MAP_COUNT_n> in 200 / 520 is instance var n (IV2 crystals, IV5 seals) the reference just added
        const mc = st.def.outer && /<MAP_COUNT_(\d+)>/.exec(d.msg?.(p[0])?.t || '');
        if (mc && d.vars) d.vars.count = st.iv[mc[1]] || 0;
        d.alert?.(p[0]);
        break;
      }
      case 'dialog': dialog(d, p[0], ctx.npc, (code) => (st.def.outer ? answerRef(d, st, ctx.npc, ctx.sn, code) : answer(d, st, ctx.npc, ctx.sn, code))); break;
      case 'brickOn': {
        const pl = d.pendingBricks?.get(p[0]);
        if (pl) { d.pendingBricks.delete(p[0]); d._createBrick?.(pl, true); }
        break;
      }
      case 'brickOff': {
        if (d.pendingBricks?.has(p[0])) d.pendingBricks.delete(p[0]);
        else d.openBrick?.(p[0], false);
        break;
      }
      case 'spawn': spawn(d, st, p[0]); break;
      case 'remove': remove(d, st, p[0]); break;
      case 'phase': st.phase = p[0]; break;
      case 'warp': warp(d, p[0], p[1]); break;
      case 'mission': mission(d, p[0], p[1]); break;
      case 'limit': if (d.running) d.limit = d.elapsed + p[0]; break;
      case 'clear': st.cleared = true; d.clear?.(); break;
      case 'fail': d.fail?.('script'); break;
      case 'exit': d._exit?.(ctx.npc, ctx.sn); break;
      case 'exp': award(d, 'exp', p); d.sys?.grantExp?.(p[0]); break;
      case 'gradeExp': award(d, 'gradeExp', p); d.game?.life?.grade?.addExp?.(p[0]); break;
      case 'giveItem': giveItemRef(d, p[0], p[1], p[2]); break;
      case 'random': (st.rand ||= {})[p[0]] = Math.floor((d.sys?.serverRefRandom?.() ?? Math.random()) * p[1]); break;
      case 'take': takeItem(d, st, p[0], p[1]); break;
      case 'drop': dropItem(d, p[0], p[1]); break;
      case 'redCellOpen': { const b = d.brickByUid?.get(p[0]); award(d, 'redCellOpen', p); b?.unblock?.(); break; }
      case 'phaseHandler': { const acts = entry(st.def.phases[st.phase]?.[ctx.kind], ctx.key); if (acts) run(d, st, acts, ctx); break; }
      default: break;
    }
  }
}

/** Transport Ship: a dialog answer goes to the outer table first, else the current phase. */
function answerRef(d, st, npc, sn, code) {
  const c = Number(code);
  const acts = entry(st.def.outer?.answer, c) || entry(st.def.phases[st.phase]?.answer, c);
  if (acts) run(d, st, acts, { npc, sn, code: c, kind: 'answer', key: c });
  return !!acts;
}

function answer(d, st, npc, sn, code) {
  const h = st.def.phases[st.phase]?.npc?.[sn?.npc];
  if (!h) return false;
  const acts = Array.isArray(h) ? h : h[code];
  if (!acts) return Array.isArray(h) ? false : true;
  run(d, st, acts, { npc, sn, code });
  return true;
}

/** The director plan of a floor wired from the older server reference (76/85/86/87, 48, 52-55), or null. */
export function serverRefPlan(map) {
  const def = SERVER_REF_SCRIPTS[Number(map)];
  if (!def) return null;
  let st = null;
  return {
    name: 'server-ref',
    source: SERVER_REF,
    noStages: true,
    noStartEffect: !!def.noStartEffect,   // Transport Ship: the reference plays 4000 at its own start, 2000 at the clear
    setup(d) {
      st = { def, phase: 1, v: {}, iv: {}, rand: {}, timerTok: {}, stage: null, cleared: false };
      loadLife();
      d.serverRef = { script: def.name, source: SERVER_REF, state: st };
      d.stages = [];
      d.clearDef = { kind: 'script' };
      d.sequential = false;
      d.killTarget = 0;
      d._stuckAt = Infinity;      // the reference script opens every gate itself: no 4.2.0 progress guard
      for (const m of d.missions || []) m.kind = 'script';
      if (def.startSec) d.countdown = def.startSec;
      for (const [id, sec] of def.createTimers || []) setTimer(d, st, id, sec);
      if (def.clearMessage) d.info = { ...d.info, stages: { ...(d.info?.stages || {}), clearMessage: def.clearMessage } };
      if (def.create) run(d, st, def.create, { kind: 'create' });
      else mission(d, 'show', 10);
      if (def.outer?.levelUp && d.game?.events?.on) {
        st.onLevel = (e) => {
          const acts = !d.disposed && entry(def.outer.levelUp, Number(e?.level));
          if (acts) run(d, st, acts, { kind: 'levelUp', key: Number(e.level) });
        };
        d.game.events.on('levelup', st.onLevel);
      }
    },
    dispose(d) { if (st?.onLevel) d.game?.events?.off?.('levelup', st.onLevel); },
    begin(d) {
      if (def.start != null) fire(d, st, def.start);
      if (def.warnBeforeEnd && d.limit > def.warnBeforeEnd) {
        d.later(d.limit - def.warnBeforeEnd, () => { if (d.running) d.alert(300); });
        d.later(Math.max(0, d.limit - 0.05), () => { if (d.running) { d.alert(def.endNotice); remove(d, st, def.endRemove); } });
      }
    },
    onKill(d, actor, rec) {
      if (!st || rec?.dg?.stage !== st.stage) return;
      const idx = Number(actor?.monsterIndex ?? actor?.def?.index ?? rec?.spawn?.monsterIndex);
      const acts = entry(def.phases[st.phase]?.kill, idx);
      if (acts) run(d, st, acts, { kind: 'kill', key: idx });
    },
    talk(d, npc, sn) {
      if (!st || !def.outer) return false;
      const k = Number(sn?.npc);
      const acts = entry(def.outer.talk, k) || entry(def.phases[st.phase]?.talk, k);
      if (acts) run(d, st, acts, { npc, sn, kind: 'talk', key: k });
      return true;   // the reference script answers every NPC of the floor itself (nothing when it has no handler)
    },
    act(d, npc, sn, code) {
      if (!st) return false;
      if (def.outer) return true;
      if (answer(d, st, npc, sn, code)) return true;
      // the reference handles these NPCs only in another phase: nothing happens now (exits fall to the director)
      if (def.exits.includes(Number(sn?.npc))) return false;
      return Object.values(def.phases).some((ph) => ph.npc?.[sn?.npc]);
    },
    clearMet() { return !!st?.cleared; },
  };
}
