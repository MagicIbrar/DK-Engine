// Dead Front / Ice Castle (party war): values the shipped client data does not contain (the party war
// server script is not shipped; docs/formats/events.md A4.4). Every value here is ENGINE-CHOSEN (not in Global data).
// Data-backed values stay in gamedata/events.json (share/partywar/*.csv, script/partywar/icecastle.csv: phase times,
// fields, respawns, rewards, tower damage, scriptOrder, strings). Used by src/systems/events/{partywar,deadfront,
// icecastle}.js, which the offline run and the host (server/world/events.mjs) share.
export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';

/** Message order of the shared party-war end (#1401 -> #1402 -> result) and the close notice. Seconds. */
export const PARTY_WAR_ENGINE_CHOSEN = Object.freeze({
  tag: ENGINE_CHOSEN_TAG,
  finalLineGapSec: Object.freeze([3, 3]),  // 1401, +3 s 1402, +3 s 1403 / 1404 + teleport + rewards
  closeLineSec: 2,                         // 1501 / 1504, +2 s 1502
  closeNoticeSec: 180,                     // #300|106 when 180 s of waitClose remain
});

/** Dead Front guard placement and boss timings. Distances in cells, times in seconds. */
export const DEAD_FRONT_ENGINE_CHOSEN = Object.freeze({
  tag: ENGINE_CHOSEN_TAG,
  groupSize: 6,             // monsters per guard group (soloRules groupSize)
  laneGuardBack: 7,         // a canyon lane group stands 7 cells before its barrier (route distance)
  laneGuardSpread: 2,       // the 2nd group of the same barrier stands +2 / +2 cells beside the first
  midBossBack: 6,           // Las Alhage stands 6 cells before his Magical Field (119)
  roadSecondLegOffset: 0.6, // fortress groups on the leg 118 -> 119 at (i + 0.6) / (n + 0.6); the 1st leg at (i + 1) / (n + 1)
  canyonWatchSec: 1,
  innerOpenSec: 4,          // 1203, +4 s the inner castle opens (1204)
  finalBossDelaySec: 3,     // the secret wall (1212), +3 s the final boss lines
  finalBossLineSec: Object.freeze([5, 11]),   // 1301, +5 s 1302, +11 s 1303 + Wall of Fire falls + Oppucus spawns
  finalBossOffsetX: 3,      // Oppucus spawns 3 cells beside the Orphina statue 132 / 131
  bossHalfHp: 0.5,          // 1304 at half HP, then 1305 / 1306
  bossHalfLineSec: Object.freeze([5, 10]),
  endLineSec: Object.freeze([4, 8]),          // 1307, +4 s 1308, +8 s 1309
  armorySec: 10,            // +10 s the armories open (1505), 1506 2 s later
  armorySecondSec: 2,
  winResolveSec: 12,        // the uncontested win 12 s after the armories
});

/** Ice Castle wave gaps and stage split. Times in seconds. */
export const ICE_CASTLE_ENGINE_CHOSEN = Object.freeze({
  tag: ENGINE_CHOSEN_TAG,
  waveSize: 6,              // attackers per scriptOrder entry
  waveGapSec: 25,           // between the waves of a stage
  nearMonsters: 12,         // "too many monsters around" radius of the paw switches (cells)
  towerLineSec: Object.freeze([4, 8]),        // 1301, +4 s 1302, +8 s 1303
  stageStartSec: 12,        // the first defence stage 12 s after the tower rises
  stageSplit: Object.freeze([8, 16]),         // scriptOrder entries 1-8, 9-16, 17-end
  stageEndLineGapSec: 4,    // the stage end lines 4 s apart
  nextStageSec: 6,          // the next stage 6 s after the last end line
  towerWarnHp: Object.freeze([50, 20]),       // 25302 at 50 HP, 25303 at 20 HP
  failResolveSec: 4,        // tower down (1504), +4 s the loss
  winResolveSec: 15,        // last stage held (1505), +15 s the win
});