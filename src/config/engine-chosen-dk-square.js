// DK-SQUARE (npc job 48 ARENA_SQUARE: npcs 121 Jerome / 720 Kenneth / 5167 Kadie). Global parity: every
// number comes from the Global data (share/arena/*.csv as parsed into gamedata/events.json modes.arena: rank.csv ranks 7 / 8,
// conquest.csv Mode 0, field.csv Type 0, dkschedule.csv, dkactionpoint / activity / dkkillpoint / dktierbuff; strings
// stringtable_dksquare.txt cate 160 / 161 / 162) and every PvP hit runs src/game/pvp-rules.js through server/world/pvp.mjs.
// No scaling, multiplier or modifier is added. Only the gaps the data leaves open are listed here, each on its own tagged line.
export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';
export const DK_SQUARE_CHOSEN = Object.freeze({
  // ENGINE-CHOSEN (not in Global data): DK Square = conquest.csv Mode 0 (rows Rank 7 / Rank 8) on field.csv Type 0 (map 67 Egutt Desert, squads 1 Miseria / 2 Ricchez).
  conquestMode: 0,
  // ENGINE-CHOSEN (not in Global data): field.csv Type of the DK Square battlefield.
  fieldType: 0,
  // ENGINE-CHOSEN (not in Global data): a character's DK Square rank = the conquest Mode 0 rank whose rank.csv Min_Level..Max_Level holds its level (7 = Lv.190-229 Rank A 160:503, 8 = Lv.230-250 Rank S 160:504); other levels get 160:33.
  rankReading: 'rank.csv band of a Mode 0 conquest rank',
  // ENGINE-CHOSEN (not in Global data): one lobby list per rank on this host; the DK server (rank.csv Server_00 100) and the cross-server list (gameServerName.csv) are this host (160:106 Server column left blank).
  lobbyScope: 'one list per rank on this host',
  // ENGINE-CHOSEN (not in Global data): the lobby list is used from where the character stands; the lobby maps (rank.csv Lobby_00 68 / Lobby_01 69) are not entered.
  lobbyMaps: 'not entered',
  // ENGINE-CHOSEN (not in Global data): distance from the job 48 NPC that counts as talking to it (cells), for Open Lobby and Join.
  npcRadius: 12,
  // ENGINE-CHOSEN (not in Global data): opening hours = dkschedule.csv windows in fixed UTC+1 server time (== Content Timetable TAB 4, 160:95 otherwise); conquest OpenTime_1 24 and schedule.csv (Rank 8, every weekday 0 h + 24 h) add no further limit.
  openReading: 'dkschedule.csv UTC+1 windows',
  // ENGINE-CHOSEN (not in Global data): share/dksquare/playtime.csv (days 1/3/5 21:00, Lv.210-250, no end time) and gradeexp.csv (trainee grade names, dwKillExp per grade) are not applied.
  unusedTables: 'dksquare/playtime.csv, dksquare/gradeexp.csv',
  // ENGINE-CHOSEN (not in Global data): Open Lobby is refused (160:96) while any lobby of the rank is still waiting with fewer than this many participants (the number is written in 160:96 / 160:130).
  openBelow: 20,
  // ENGINE-CHOSEN (not in Global data): lobbies of a rank at the same time = rank.csv Max_Room (160:45 beyond it).
  roomCap: 'rank.csv Max_Room',
  // ENGINE-CHOSEN (not in Global data): Lobby Name (160:15) = the opener's character name (createdksquarewnd has no name input).
  lobbyName: 'opener character name',
  // Lane 47/71: confirmSec (15) REMOVED - no Global, decompile, older-server (Option.csv VERIFYWAIT_TIME is a generic server option, not tied to this window) or online value for the ui_confirmwnd 160:48 / 160:79 '(%d)' seconds; the host waits for every OK / Cancel.
  // ENGINE-CHOSEN (not in Global data): the first StartPCCount who accept are dealt at random alternating Miseria / Ricchez (160:2); a later joiner raids (160:24 / 160:79) onto the team with fewer members present, ties to Miseria.
  teamRule: 'random alternating at start, fewest present on raid',
  // ENGINE-CHOSEN (not in Global data): EnterCost DIL is checked on Open Lobby / Join (160:669) and paid when the character enters the battlefield; it is not returned.
  costReading: 'checked on open / join, paid on entry',
  // ENGINE-CHOSEN (not in Global data): the battle lasts FightTime(Sec) from its start; Sunstone (npc 5003 job 52) communion opens ConquestWaitTime(Sec) after the start.
  fightReading: 'FightTime from the start',
  // ENGINE-CHOSEN (not in Global data): win rule, Sunstone communion, action points, settlement, DP / tier, rank board, desertion penalty and revive / auto-exit are read exactly as src/config/engine-chosen-arena.js reads them (shared helpers of src/systems/arena/arena-rules.js); activity.csv blocks S (Rank 8) / A (Rank 7).
  battleReading: 'as engine-chosen-arena.js',
  // ENGINE-CHOSEN (not in Global data): a downed participant revives at the squad Revive_Pos; unrevived for autoExitSec it is moved out (160:636 '1 minute').
  autoExitSec: 60,
  // Lane 47/71: finishWaitSec (30) REMOVED - no source for the 160:70 '%d second(s)' move-out time (the JP DK Square guide no=41&pno=61 gives none); participants leave with Leave Now (160:71).
  // Lane 47: fight time / StartPCCount / MaxPCCount may be replaced per mode + rank by the Global GM command set_dksquareInfo (server/world/dk-square.mjs).
  // ENGINE-CHOSEN (not in Global data): exit point = where each participant stood when it joined the lobby (map 67's kickTo is the lobby map 68, not entered).
  exitPoint: 'own spot at join',
  // ENGINE-CHOSEN (not in Global data): still unapplied: dktierbuff GradePercentValue (no rule names what it scales), changeshape.csv PET rows (a pet companion is not an appearance slot), the season reset of 160:137/138, stone HPRecovery and the brick exp column. The weapon look rows (type 0 code 64 appearance materials) are drawn on every body.
  unapplied: 'GradePercentValue, PET looks, season reset, stone HPRecovery / exp',
  // ENGINE-CHOSEN (not in Global data): no native row binds a rank to the three map 67 stone sets (uid groups 4xx 36671/36672, 5xx 36674/36675, 6xx 36792/36793); both Mode 0 ranks stand the strongest set, 602 / 612 (36792 Ricchez / 36793 Miseria Protection Stone, the only set named as 160:302 'Destroy the Enemy Protection Stone'), so no rank fights a weaker stone than a native set; 4xx / 5xx stay unspawned.
  stoneUids: Object.freeze({ 7: Object.freeze([602, 612]), 8: Object.freeze([602, 612]) }),
  // ENGINE-CHOSEN (not in Global data): IsCreate 0 stones are created when the battle starts and are breakable only by the other squad during the fight (Revival 0: never rebuilt); the destroyer alone earns dkactionpoint ActionType 3 (300); a destroyed stone has no other effect on the battle.
  stoneRule: 'at start, enemy squad only, fight only, destroyer gets ActionType 3',
  // ENGINE-CHOSEN (not in Global data): dktierbuff options (8 HP_MAX_ADD, 43 SPEED_MOVE_MUL, 316 RESULT_EXP_MUL) apply wherever the character holds the tier: its level is in a Mode 0 rank band and its DP Score reaches the row's DKPoint; they enter the host stat pipeline as option pairs (server/world/data.mjs stats extraOptions). Reason: 316 only changes hunting EXP, which no DK Square / Draco battle pays.
  tierScope: 'while holding the tier (level band + DP Score)',
  // ENGINE-CHOSEN (not in Global data): changeshape.csv Team = the squad's Squad_AllyType (1 Miseria, 2 Ricchez, 3 Rebel, 4 Terra, 0 every squad); costume / wings by class, emblem and weapon look by the worn weapon's code (the look item's value1) are projected on the public appearance only while the participant is inside its battle (fight and result wait); real equipment, its stats and the profile are never changed.
  teamLook: 'projected while inside the battle; Team = ally; real gear untouched',
  // ENGINE-CHOSEN (not in Global data): 160:139 'adjusted by battlefield participation time' has no formula in the data: DP, tier points and EXP are not adjusted.
  participationTime: 'not adjusted',
  // ENGINE-CHOSEN (not in Global data): the client refreshes the lobby / battle every refreshMs.
  refreshMs: 1000,
});

export function dkSquareChosenList() {
  return Object.entries(DK_SQUARE_CHOSEN).map(([k, v]) => `${k}=${typeof v === 'number' ? v : JSON.stringify(v)}`);
}
