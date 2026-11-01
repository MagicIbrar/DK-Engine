// TRAINING-CAMP: everything the Global data leaves open for the Training Camp windows (script/ui/game2/trainingcamp/*.txt,
// strings cate 160 stringtable_dksquare.txt). Each value below is ENGINE-CHOSEN (not in Global data) unless its comment
// names the file it comes from. Player-vs-player numbers are NOT chosen here: they come from src/game/pvp-rules.js.
//
// 1. Art. The 11 windows draw from imagetable screen "TrainingCamp" (indexes 1, 11-16, 21, 22, 31, 32, 39, 42-50, 52, 53,
//    56, 57, 61, 62, 64) but script/ui/com/imagetable.txt has no TrainingCamp row. The four shipped sheets
//    texture/ui/game/trainingcamp/trainingcamp_{choice,info,mission,waiting}.dds are the older revision of the DK Square
//    sheets, and 10 of the 11 windows are older twins of game2/dksquare windows that use screen "DKSquare" at the same index
//    for the same control. So every TrainingCamp row below is the DKSquare row of the same index (31/32: the DKSquare 81/82
//    rows of the twin's pan_mylotto / pan_myclass), cut from the trainingcamp sheet where that same sprite sits:
//      waiting / mission sheets: byte-identical to dksquare_waiting / dksquare_mission -> same rectangles;
//      info sheet: same cells, the right-hand icon block starts at y 0 instead of the DK sheet's y 620;
//      choice sheet: the lobby panel (435x341, the window's own size), its refresh buttons and its state icons.
//    tools/test-training-camp.mjs decodes both sheets and checks each cut against its DKSquare source sprite.
// 2. Lobby + battle rules (lobby size, start count, play time, confirm time, respawn, mission scoring).
// 3. Battlefield: share/arena/field.csv Type 0 (the DK Square battlefield, gamedata/events.json modes.arena.field):
//    map 67, Squad 1 (Miseria 160:101) at Pos_01 / Revive_Pos_01, Squad 2 (Ricchez 160:102) at Pos_02 / Revive_Pos_02.
import { PARTY_PVP_CHOSEN, ENGINE_CHOSEN as PVP_CHOSEN } from '../game/pvp-rules.js';

export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';
export const TRAINING_CAMP_SCREEN = 'TrainingCamp';
const T = 'UI\\Game\\TrainingCamp\\';

/** ENGINE-CHOSEN (not in Global data): imagetable rows for screen TrainingCamp. [index, sheet, x, y, w, h, DKSquare source index]. */
export const TRAINING_CAMP_IMAGE_ROWS = Object.freeze([
  [1, 'trainingcamp_waiting.dds', 0, 0, 435, 341, 1],       // waiting-information panel
  [11, 'trainingcamp_choice.dds', 0, 346, 26, 26, 11],      // refresh button: disable
  [12, 'trainingcamp_choice.dds', 26, 346, 26, 26, 12],     // refresh button: down
  [13, 'trainingcamp_choice.dds', 52, 346, 26, 26, 13],     // refresh button: none / over
  [14, 'trainingcamp_choice.dds', 0, 0, 435, 341, 14],      // lobby-list panel
  [15, 'trainingcamp_choice.dds', 461, 0, 22, 15, 15],      // lobby state icon: waiting
  [16, 'trainingcamp_choice.dds', 461, 15, 22, 15, 16],     // lobby state icon: in battle
  [21, 'trainingcamp_info.dds', 0, 0, 747, 523, 21],        // battle-information panel (the window's 747x523)
  [22, 'trainingcamp_info.dds', 0, 524, 721, 2, 22],        // board row divider
  [31, 'trainingcamp_info.dds', 770, 0, 22, 15, 81],        // my-row mark (pan_mylotto)
  [32, 'trainingcamp_info.dds', 770, 15, 22, 15, 82],       // my-row class mark (pan_myclass)
  [39, 'trainingcamp_info.dds', 0, 527, 466, 10, 39],       // battle gauge
  [42, 'trainingcamp_info.dds', 748, 187, 74, 23, 42],      // WIN
  [43, 'trainingcamp_info.dds', 748, 211, 74, 23, 43],      // LOSE
  [44, 'trainingcamp_info.dds', 748, 235, 105, 29, 44],     // Miseria
  [45, 'trainingcamp_info.dds', 748, 265, 105, 29, 45],     // Ricchez
  [46, 'trainingcamp_info.dds', 793, 0, 66, 66, 46],        // circle gauge base
  [47, 'trainingcamp_info.dds', 859, 0, 65, 65, 47],        // circle gauge ring (both teams)
  [48, 'trainingcamp_info.dds', 859, 0, 33, 66, 48],        // circle gauge: blue half
  [49, 'trainingcamp_info.dds', 892, 0, 33, 66, 49],        // circle gauge: red half
  [50, 'trainingcamp_info.dds', 925, 0, 37, 4, 50],         // circle gauge bar
  [52, 'trainingcamp_waiting.dds', 0, 342, 26, 26, 52],     // lobby alarm
  [53, 'trainingcamp_waiting.dds', 26, 342, 26, 26, 53],    // lobby alarm: blink
  [56, 'trainingcamp_info.dds', 100, 914, 22, 15, 56],      // party mark
  [57, 'trainingcamp_info.dds', 122, 914, 22, 15, 57],      // party mark: down
  [61, 'trainingcamp_mission.dds', 0, 0, 379, 580, 61],     // mission details panel
  [62, 'trainingcamp_info.dds', 749, 324, 83, 42, 62],      // battle-information button
  [64, 'trainingcamp_info.dds', 793, 67, 30, 30, 64],       // Training Camp HUD icon
].map(r => Object.freeze(r)));

/** The rows as imagetable.txt lines (group,index,texture,x,y,w,h,L,T,R,B,description) for src/ui/atlas.js. */
export function trainingCampImageTableText() {
  return TRAINING_CAMP_IMAGE_ROWS.map(([i, sheet, x, y, w, h, src]) => `${TRAINING_CAMP_SCREEN},${i},${T}${sheet},${x},${y},${w},${h},0,0,0,0,${ENGINE_CHOSEN_TAG} from DKSquare ${src}`).join('\n');
}

export const TRAINING_CAMP_CHOSEN = Object.freeze({
  /** ENGINE-CHOSEN (not in Global data): the lobby list is one shared list per world (every field map, channel 0 rules). */
  lobbyScope: 'one list per world',
  /** ENGINE-CHOSEN (not in Global data): lobbies open at the same time (160:45 "No more lobbies can be opened."). */
  maxLobbies: 10,
  /** ENGINE-CHOSEN (not in Global data): Maximum Participants (160:5) of a lobby, both teams together. */
  maxPlayers: 10,
  /** ENGINE-CHOSEN (not in Global data): Start (M) (160:8, 160:2 "%d players complete the team"): participants needed. */
  startPlayers: 2,
  /** ENGINE-CHOSEN (not in Global data): Playtime (160:7, "%d min" 160:36) of a battle. */
  playMinutes: 10,
  /** ENGINE-CHOSEN (not in Global data): seconds of the entry confirmation (ui_confirmwnd, 160:48 "automatically canceled in (%d)"). */
  confirmSec: 15,
  /** ENGINE-CHOSEN (not in Global data): seconds a downed participant waits before returning at the team's Revive_Pos. */
  respawnSec: 5,
  /** ENGINE-CHOSEN (not in Global data): Battle Mode (160:4) / Main Mission (160:9): 160:303 "Eliminate the Enemy"; no Sub Mission. */
  missionString: [160, 303],
  /** ENGINE-CHOSEN (not in Global data): lowest level that may open or join (160:33 otherwise). */
  minLevel: 1,
  /** ENGINE-CHOSEN (not in Global data): Lobby Name (160:15) = the opener's character name (the window has no name input). */
  lobbyName: 'opener character name',
  /** ENGINE-CHOSEN (not in Global data): teams are dealt at random (160:2) alternating Miseria / Ricchez, so they differ by at most one. */
  teamRule: 'random order, alternating Miseria / Ricchez',
  /** ENGINE-CHOSEN (not in Global data): Bonus (160:111) has no source in this mode and stays 0. */
  bonusPoints: 0,
  /** ENGINE-CHOSEN (not in Global data): joining a lobby that is In Battle (160:22) is refused (the raid prompt 160:24 is not offered). */
  raid: false,
  /** ENGINE-CHOSEN (not in Global data): leaving the battlefield returns each participant to where they stood when they joined the lobby. */
  exitPoint: 'own spot at join',
  /** ENGINE-CHOSEN (not in Global data): battlefield = share/arena/field.csv row Type 0 (MapIndex 67), squads 1 / 2. */
  fieldType: 0,
});

// PvP numbers (src/game/pvp-rules.js): every hit runs the PVP-DUEL pipeline through server/world/pvp.mjs registerPvpMode.
/** Battle points (160:109) per enemy downed = PARTY_PVP_CHOSEN.pointsPerKill. */
export const BATTLE_POINTS_PER_KILL = PARTY_PVP_CHOSEN.pointsPerKill;
/** Seconds of "moved out of the lobby in %d second(s)" (160:70) = PARTY_PVP_CHOSEN.finishWaitSec. */
export const FINISH_WAIT_SEC = PARTY_PVP_CHOSEN.finishWaitSec;
/** Shield at the battle start = pvp-rules ENGINE_CHOSEN.shieldAtStart. */
export const SHIELD_AT_START = PVP_CHOSEN.shieldAtStart;
/** Mission points (160:110) for "Eliminate the Enemy": the duel result values of pvp-rules (formula.ini ratios x basePoints):
 *  winning team +dwWinPVPPointRatio x base, a DRAW +dwLosePVPPointRatio x base, the losing team 0. rules = buildPvpRules(). */
export function missionPoints(rules, outcome) {
  if (outcome === 'win') return Math.round(rules.winRatio * rules.basePoints);
  if (outcome === 'draw') return Math.round(rules.loseRatio * rules.basePoints);
  return 0;
}

/** Field row of the battlefield from gamedata/events.json modes.arena.field. */
export function battlefieldOf(fields) {
  const f = (fields || []).find(r => Number(r.Type) === TRAINING_CAMP_CHOSEN.fieldType);
  if (!f) return null;
  const p = (k, n) => ({ x: Number(f[`${k}_0${n}_X`]) + 0.5, z: Number(f[`${k}_0${n}_Y`]) + 0.5 });
  return { map: Number(f.MapIndex), radius: Number(f.Pos_Radius) || 0, starts: [p('Pos', 1), p('Pos', 2)], revives: [p('Revive_Pos', 1), p('Revive_Pos', 2)] };
}

/** Deal participants to the two teams (index 0 Miseria, 1 Ricchez). random() in [0,1). */
export function dealTeams(ids, random = Math.random) {
  const order = [...ids];
  for (let i = order.length - 1; i > 0; i--) { const j = Math.floor(random() * (i + 1)); [order[i], order[j]] = [order[j], order[i]]; }
  return [order.filter((_, i) => i % 2 === 0), order.filter((_, i) => i % 2 === 1)];
}

export function trainingCampChosenList() {
  return [...Object.entries(TRAINING_CAMP_CHOSEN).map(([k, v]) => `${k}=${typeof v === 'string' ? JSON.stringify(v) : Array.isArray(v) ? v.join(':') : v}`), `imagetable TrainingCamp ${TRAINING_CAMP_IMAGE_ROWS.length} rows`];
}