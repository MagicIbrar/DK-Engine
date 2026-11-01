// Monster-AI values the shipped Global client data does NOT contain. Every constant in this file is ENGINE-CHOSEN.
// The per-monster rules themselves come from the data and are read by src/game/monster-rules.js on BOTH sides
// (offline brain src/game/ai.js, authoritative server server/world/core.mjs):
//   share/ai/info.csv      DwSight (sight), DwPersuitRange (pursuit), DwExploreRange, DwCallTeamCount / dwCallTeamCell
//   share/creature/monster.dat   WalkSpeed @203 / RunSpeed @207 / Width @211  (monsters.json speed [walk, run], width)
//   share/ai/monsterbattle.csv   attack blocks [min, max, absMin, absMax, CellRange, AttackDelay, ...] (monsters.json attacks)
//   share/ai/patterninfo.csv + share/ai/pattern/*.csv   aggressive / call / range / aggro-table behaviour per pattern
// Nothing below changes a data value; these are only the fallbacks and paddings the engine needs where the data is silent.
export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';
export const MONSTER_AI_ENGINE_CHOSEN = Object.freeze({
  tag: ENGINE_CHOSEN_TAG,
  // Fallbacks for the 3 monsters without a share/ai/info.csv row (2325 Favnil, 3738 Ilias, 3739). A DATA value of 0 is kept
  // as 0 (8031 Crystal of Health / 9155 Big Melon: DwSight 0 = never notices anyone).
  defaultSight: 8,
  defaultPursuit: 20,
  defaultExplore: 4,
  // monster.dat run speed missing -> walk x 2.5 (the old ai.js:46 rule); run is never below walk.
  runFromWalk: 2.5,
  // Attack reach. The data gives CellRange (cells); whether it is measured centre-to-centre or edge-to-edge is unknown, so the
  // reach adds half the monster's body radius plus the target's radius (old ai.js:78-82), with a floor of 1.2 cells.
  reach: Object.freeze({
    defaultRange: 2,        // an attack block without a CellRange
    ownRadiusFactor: 0.5,   // + monster body radius x 0.5
    targetRadius: 0.4,      // the player's body radius (src/actors/player.js:77 = 0.4); the server has no mesh, so it uses this
    min: 1.2,
    swingSlack: 0.25,       // a block "reaches" within reach + slack when choosing the swing
  }),
  // Body radius from monster.dat Width when no mesh is loaded (src/actors/monster.js:84): max(0.4, width x 0.45), else 0.5.
  bodyRadius: Object.freeze({ min: 0.4, widthFactor: 0.45, fallback: 0.5 }),
  leash: Object.freeze({
    // While swinging the monster may stand up to pursuit + 2 from home before PERSUIT_OUT (old ai.js:327 hysteresis).
    attackPad: 2,
    // ENGINE INFERENCE (no data says what DwPersuitRange is measured from): a target farther than pursuit + sight from the
    // monster's home cannot be chased without leashing, so the chase is given up at once (old ai.js:311).
    targetFromHomeAddsSight: true,
    // An immobile monster (speed [0,0]) forgets a target farther than max(sight, its longest reach) + 2 (old ai.js:316 used
    // sight + 2, which could drop a target still inside a 14-cell bow reach).
    immobileForgetPad: 2,
  }),
  // PERSUIT_OUT (share/ai/pattern/*.csv: every state -> NEXT_STATE FEAR or UNCARING, NEXT_MODE EXPLORE; see monster-rules.js
  // persuitOutRule) means "stop chasing, go back to EXPLORE". The data lists NO "return home" / "evade" / "reset HP" /
  // "full heal" state or mode, and the monster HPRecovery column is 0 for Crocuda (and 4516 of 4590 rows). The old client
  // policy (evade every hit while walking home, +35 % max HP per second, full heal on arrival, run speed x 1.15, snap / teleport
  // home when stuck) was invented and has been DELETED on both sides (the data lists no such state). What is left is ONE inference:
  explore: Object.freeze({
    // ENGINE-CHOSEN (not in Global data): the data does not
    // say what EXPLORE roams around (share/ai/pattern/*.csv: PERSUIT_OUT -> mode EXPLORE; info.csv DwExploreRange / DwExploreStandDelay;
    // monster.dat WalkSpeed; nothing names a centre). 'ended' = a monster that gives up a chase (PERSUIT_OUT) roams around the point
    // where it stands (its ROAMING CENTRE); nothing walks back to its spawn. The point where the chase ended is ALSO the origin the pursuit range is measured from (canAcquire / shouldLeash / DwPersuitRange,
    // monster-rules.js roamCentre = m.anchor || m.home): the leash follows the monster at every give-up, so a monster whose target is still
    // in sight follows it on, a player can pull monsters across the whole map, and the monster never walks back. Only death returns it to its
    // original spawn (server `m.home` / offline `monster.home` is the respawn point and is never changed by the AI). Only PERSUIT_OUT
    // re-homes (never an explore leg); death / respawn / GM respawn / map edits clear it; the roaming centre is `m.anchor` (server) /
    // `brain.anchor` (offline). A monster that never gave up a chase roams around its spawn exactly as before.
    // ONLY monsters that roam at all (DwExploreRange > 0 AND WalkSpeed > 0, the old idle condition) are re-homed and get explore
    // movement after that, at WalkSpeed with the normal stand delay (no evade, no heal, no teleport, hittable the whole time).
    // Monsters that never roamed (explore range 0, WalkSpeed 0, patterns 20-23 / 1002, boss style) and event marchers
    // (server m.eventMarch) are not touched: they stay where the chase ended / keep their march, with the leash at the spawn, as before.
    // 'home' = the pre-decision reading (roam around the spawn, walk back into it): set it to restore that behaviour.
    anchor: 'ended',
  }),
  // Chase give-up when the path is blocked (old ai.js STUCK_GIVEUP): ENGINE-CHOSEN trigger for PERSUIT_OUT ("unreachable").
  chaseStuckGiveUpSec: 2.5,
  // Call patterns 4/5/6 (NegativeCall / PositiveCall / RangeCall): the pattern tables say WHEN (UNDER_ATTACK from a calm
  // state -> CALLTEAM, re-armed by PERSUIT_OUT / death) and info.csv says HOW MANY (DwCallTeamCount) and HOW FAR
  // (dwCallTeamCell). WHO answers is not in the data; this is the engine's filter:
  callTeam: Object.freeze({
    anySpecies: true,       // any monster of the same scene, not only the caller's species
    idleOnly: true,         // only monsters without a target (not chasing / attacking)
    // DwCallTeamPossibelHP (info.csv col 12, 50 on most rows) is NOT applied: its direction/meaning is unknown, and the
    // pattern rows call on the first hit from REST (full HP), which a "<= 50 % HP" reading would contradict.
    possibleHpApplied: false,
  }),
  // MON_*.csv column 2 (respawn seconds, meaning inferred). The old client sanitising, now used by the server too:
  respawn: Object.freeze({
    defaultSec: 30,         // 0 / missing / negative
    minSec: 5,              // 1..4
    rareThresholdSec: 60000,
    rareSec: 900,           // 60000 / 65534 ("never" in the server tables) -> 15 minutes
  }),
  // Per-TARGET follower cap (src/game/follow-cap.js). DATA: share/ai/info.csv dwFollowTarget (monsters.json ai.followTarget, 5,171 rows:
  // 100 x1,234, 3 x1,212, 5 x539, 1000 x333, 2 x294, 50 x275, 4 x221, 6 x210, 0 x209, 150 x174, 8 x161, 1 x151 ...). WHAT IT MEANS is not in
  // any readable file (the exe is packed): ENGINE-CHOSEN reading = the most monsters that may chase / attack ONE target at the same time;
  // player, servant and every party member are separate targets. 0 / missing and every value >= noCapFrom = no practical cap (the values
  // 50 / 100 / 150 / 200 / 1000 are far above any crowd; the real cut-off between "a cap" and "no cap" is not stated: 30 stays a cap).
  // A monster over its cap does not chase that target, stays in its state / explore, still takes damage and takes a free slot later.
  // enabled = the default of the kill switch (DEKARON_FOLLOW_CAP=off on the server, ?followcap=off in the client page).
  followCap: Object.freeze({ enabled: true, noCapFrom: 50 }),
  // Skill slows / hastes on monsters: SPEED_MOVE_MUL (and the engine-only SPEED_MOVE_SUB) in %, floor 10 %.
  statusSpeedMulMin: 0.1,
  // Server swing delay floor (an attack block with AttackDelay 0 waits 2000 ms, never less than 700 ms between swings).
  serverSwing: Object.freeze({ minDelayMs: 700, defaultDelayMs: 2000 }),
});
