// Lane 68 (owner: "get ice castle solved"; rule: nothing stays UNRESOLVED): Ice Castle (maps 167-174) values, each
// labelled with its source, from docs/global-parity-420/ICE-CASTLE-EVIDENCE.md. Source order: Global data / client,
// the decompiles, the OLDER SERVER REFERENCE (server-ref, data only, never run), then online secondary.
// Ice Castle has no script in the older server reference build (ScriptProcess.dll 11.07.29 holds Dead_Front_* only).
// Its start / PvP / close frame uses the same Global message codes as Dead Front (1001 / 1002 / 1003 / 1401 / 1402 /
// 1501-1504, stringtable_icecastle vs stringtable_deadfront), so that frame takes the Dead Front script timers
// (owner approved the older server reference where Global has nothing). Values with no credible source were removed,
// not guessed (ICE_CASTLE_REMOVED). Used by src/systems/events/{icecastle,partywar}.js, server/world/party-war.mjs and
// server/world/npc-event-objectives.mjs (offline run and host share them).
import { DEAD_FRONT_SCRIPT_TIMINGS as DFT } from './dead-front-script-ref.js';

export const IC_GLOBAL = 'Global';
export const IC_OLDER_SERVER_REF = 'older server reference (ScriptProcess.dll 11.07.29 Dead_Front_* frame; same Global message codes in Ice Castle)';
export const IC_ONLINE = 'online secondary (dekaron.fandom.com/wiki/The_Revamp = italianrevenge.wixsite.com/dekaronxxx/ice-castle, publisher update text)';
export const IC_DERIVED = 'derived (Global scriptmonster / brick / callmonster data arranged by the online 3 x 3 rule; no extra number)';

const freeze = o => { if (o && typeof o === 'object' && !Object.isFrozen(o)) { Object.freeze(o); for (const v of Object.values(o)) freeze(v); } return o; };

/** Global data / client values used by the Ice Castle flow. */
export const ICE_CASTLE_GLOBAL = freeze({ source: IC_GLOBAL,
  towerBrick: 36820,                 // Tower of Shield (events.json bricks, 100 HP)
  towerHp: 100,                      // brick 36820 HP
  towerTarget: [248, 266],           // script/partywar/icecastle.csv checkpoint 12
  devildomGates: [142, 143, 144, 145, 146, 147],  // Gates of Devildom bricks (36822), map 167 brick file
  reenergizeDil: 100000,             // dialogs 10034-10037
  stageStartLines: [[1304, 1305], [1309, 1310], [1314, 1315]],  // "Stage N Phase 1 / Phase 2" (stringtable_icecastle)
  stageEndLines: [[1306, 1307, 1308], [1311, 1312, 1313], [1316, 1317]],  // "Stage N ended - Boss message 1-3"
  aslaEndLines: [1318, 1319, 1320],  // "Stage 3 ended - Asla Statue message 1-3"
  aslaTowerLines: [1301, 1302, 1303],// "Asla Statue activated - Boss message 1-3"
  karkeLine: 25301,                  // Karke spawn line
  roundClearLine: 1505,              // "The round has been cleared!"
  overtimeLine: 1408,                // Ice Castle extra-time notice (= Dead Front 1406)
  winNotice: [300, 105],             // partywar2 "Congratulations, Team <PARTYNAMES>! ... strongest Troopers"
  closeNotice: [300, 106],           // partywar2 "Ice Castle closes in 3 minutes."
  closeNoticeSec: 180,               // the 300:106 text itself: "closes in 3 minutes"
});

/** Start / PvP / close / fail timers: the Dead Front script frame (older server reference), seconds. */
export const ICE_CASTLE_SCRIPT_TIMINGS = freeze({ source: IC_OLDER_SERVER_REF,
  firstNoticeSec: DFT.firstNoticeSec,          // waitStart -> 1001
  countdownSec: DFT.countdownSec,              // 1001 -> 1002 countdown
  startSec: DFT.startSec,                      // 1002 -> 1003 start (120 + 55 + 5 = Global waitStart 180)
  fortressSec: DFT.fortressSec,                // = Global LimitStarTime 1800
  pvpWaitSec: DFT.pvpWaitSec, pvpWaitCountdownSec: DFT.pvpWaitCountdownSec, pvpSec: DFT.pvpSec,   // = Global 30 / 240
  overtimeWaitSec: DFT.overtimeWaitSec, overtimeCountdownSec: DFT.overtimeCountdownSec, overtimeSec: DFT.overtimeSec, // = Global 10 / 60
  closeSec: DFT.closeSec,                      // objective / PvP end -> close step
  closeLineSec: DFT.closeLineSec,              // close: 1501, +7 waitClose, +270 1502, +24 1002, +6 end (= Global LimitEndDelay 300)
  timeoutLineSec: DFT.timeoutLineSec,          // fail / timeout: +1 1504, +8 1503
  timeoutEndSec: DFT.timeoutEndSec,            // fail / timeout -> end
  // three-line boss monologues: Dead Front 1301-1303 (secret wall +7 1301, +5 1302, +6 1303, +1 the wall falls)
  aslaLineGapSec: [DFT.bossRoomLineSec[1], DFT.bossRoomLineSec[2]],
  towerRiseSec: DFT.bossRoomLineSec[3],         // the Tower of Shield rises 1 s after 1303 (Dead Front: Orphina 131 falls)
  // stage-end boss monologue: Dead Front boss dead -> +1 1307, +4 1308, +5 1309, +5 next step
  stageEndLineSec: DFT.bossDeadLineSec,
});

/** Tower defence structure (online secondary). */
export const ICE_CASTLE_TOWER_DEFENCE = freeze({ source: IC_ONLINE,
  rounds: 3,
  wavesPerRound: 3,
  gatesPerRound: [4, 4, 6],          // rounds 1-2: 4 of the 6 gates at random, a new set each wave; round 3: all 6
  karkeFrom: { round: 3, wave: 2 },  // Karke joins from round 3 wave 2
  // derived: the Global scriptmonster order is dealt over the 9 waves in file order; each monster of a wave leaves
  // every active gate once (Karke once). No wave size or split number is stored.
  waveContents: IC_DERIVED,
  // next wave / next round start: when the previous wave is gone (no timer: no source has a wave gap)
  waveStart: 'previous wave cleared (no timer)',
});

/** Former UNRESOLVED / engine-chosen values: what replaced each one, or that it was removed. */
export const ICE_CASTLE_REMOVED = freeze({
  waveSize: 'removed (no source); one attacker per active gate per wave monster (online gate rule)',
  waveGapSec: 'removed (no source); next wave when the previous one is cleared',
  stageSplit: 'removed (8/16 invented); online 3 rounds x 3 waves over the Global scriptmonster order',
  nearMonsters: 'removed (no source for the paw refusal radius); the paw refusal 1206/1210/1217/1221 no longer fires',
  towerLineSec: 'replaced: older server reference 1301-1303 gaps 5 / 6 s',
  stageStartSec: 'replaced: older server reference, round 1 starts when the tower rises (+1 s after 1303)',
  stageEndLineGapSec: 'replaced: older server reference boss-dead lines +1 / +4 / +5 s',
  nextStageSec: 'replaced: older server reference +5 s after the last line',
  towerWarnHp: 'removed (no source); 25302 / 25303 warnings not sent',
  failResolveSec: 'replaced: older server reference timeout +1 1504, +8 1503, end at 15 s',
  winResolveSec: 'replaced: older server reference close step 5 s after the objective',
  finalLineGapSec: 'removed: solo win has no 1401 / 1402 (the script frame sends none for one party)',
  closeLineSec: 'replaced: older server reference close 1501, +7, +270 1502, +24 1002, +6 end',
  closeNoticeSec: 'Global (300:106 text "closes in 3 minutes")',
  treasureBoxPositions: 'replaced: the Tower of Shield cell (Global icecastle.csv checkpoint 12); the invented ring of 5 removed',
});