// EVENT-MODES: the values Global data leaves open for the Server Whole Competition (Race) and the Mission titles.
// Global parity: every number that IS in the data comes from it (share/race/list.csv + playtime.csv,
// share/pc/title/title_base.csv via gamedata/events.json / life.json) and every PvP hit runs src/game/pvp-rules.js
// through server/world/pvp.mjs. Nothing is scaled and no modifier is added; where the data is silent the original's
// default behaviour is preferred, and each gap is one tagged line below.
// Egutt (job 130 EGUTT_ENTER = Draco Desert Battlefield) is hosted by the arena module (server/world/arena.mjs,
// src/config/engine-chosen-arena.js venueJobs[130]); it is not duplicated here.
// Forgotten Shipwreck: its reward roulette (share/forgottenshipwreck/rewardslot.csv, one weighted slot) is verified through the
// host dungeon path by tools/test-event-modes.mjs. The BLUE / RED team mode of game2/forgottenshipwreck (startcondition.csv: 10
// players at 6 weekly windows; ui_matchingwait / ui_scorewnd / team, buff and target skill windows; string cate 161 = the
// "Monster Carnival" strings) has no rule, CP or score data in the shipped files; it is hosted by server/world/monster-carnival.mjs
// with its own choices in src/config/engine-chosen-monster-carnival.js - CLOSED by lane 71 (CARNIVAL_CHOSEN.closed: no Global
// entrance and no source for its rules; registration is refused).

// Lane 47: RACE_CHOSEN removed with the race host (no Global evidence for any race rule or window).

export const TITLE_CHOSEN = Object.freeze({
  // ENGINE-CHOSEN (not in Global data): Type 1 = kill monster Type_Value1 Type_Value2 times (credited to the killing character).
  type1: 'kill Type_Value1 x Type_Value2',
  // ENGINE-CHOSEN (not in Global data): Type 7 = be knocked down by monster Type_Value1 Type_Value2 times (title 12 text 2803|12 'He welcomed me with his slap, and I'm laying on the ground').
  type7: 'downed by Type_Value1 x Type_Value2',
  // ENGINE-CHOSEN (not in Global data): Type 9 rows have no condition data (server script achievements, text 2803|<Index>); they stay locked until a host grant (grantTitle) - none is invented.
  type9: 'locked, host grant only',
  // ENGINE-CHOSEN (not in Global data): a Type 9 row whose 2803 text names a dungeon clear (20 Solo Champion = Colosseum Arena (Solo), dungeon 615 SOLO) is granted inside the host's durable last-floor clear transaction of that dungeon for its one runner (src/systems/life/title-rules.js TITLE_DUNGEON_CLEARS).
  clearTitle: 'durable last-floor clear of the named dungeon, one runner',
  // ENGINE-CHOSEN (not in Global data): the list shows an owned title by name and an unowned one with its script default 2801|6 "Unacquired Title"; selecting a row shows its 2803 text; only an owned title can be applied.
  window: 'owned by name, others "Unacquired Title", owned selectable',
  // ENGINE-CHOSEN (not in Global data): the original "in progress" message 2802|9 is shown for each counted kill / down that does not finish a title yet (the cadence is not in the data).
  progressNotice: 'each counted event below the goal',
});

const list = o => Object.entries(o).map(([k, v]) => `${k}=${typeof v === 'object' ? JSON.stringify(v) : v}`);
export function eventModesChosenList() { return list(TITLE_CHOSEN).map(s => 'title.' + s); }
