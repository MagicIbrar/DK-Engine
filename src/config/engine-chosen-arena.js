// ARENA (Draco Desert Battlefield, npc job 130 EGUTT_ENTER; Lost Horizon battlefield, npc job 111 ARENA_LOSTHORIZON).
// Global parity: every number comes from the Global data (share/arena/*.csv as parsed into
// gamedata/events.json modes.arena, the map dungeon rows, string cate 160/162, status 11009/11067) and every PvP hit runs
// src/game/pvp-rules.js through server/world/pvp.mjs. No scaling, multiplier or modifier is added. Only the gaps the data
// leaves open are listed here, each on its own tagged line.
export const ARENA_CHOSEN = Object.freeze({
  // ENGINE-CHOSEN (not in Global data): job 130 enters conquest.csv Mode 3 (Rank 0) on field.csv Type 3 (map 702); job 111 enters losthorizon.csv Mode 100 on field.csv Type 2 (map 548, rank.csv Rank 100).
  venueJobs: Object.freeze({ 130: 'draco', 111: 'lostHorizon' }),
  // ENGINE-CHOSEN (not in Global data): distance from the entry NPC that counts as talking to it (cells).
  npcRadius: 12,
  // ENGINE-CHOSEN (not in Global data): OpenTime_1 is the fixed UTC+1 server hour of the single opening (OpenCount 1); 24 = open all day; one opening lasts FightTime(Sec).
  openReading: 'UTC+1 server hour, FightTime long',
  // ENGINE-CHOSEN (not in Global data): Lost Horizon has no FightTime row; its battle lasts the map 548 dungeon row expireTime (minutes).
  lostHorizonFight: 'dungeon.expireTime minutes',
  // ENGINE-CHOSEN (not in Global data): Lost Horizon starts once the dungeon row requestMember players are queued in total; rank.csv Max_Room caps one room.
  lostHorizonStart: 'requestMember queued in total',
  // ENGINE-CHOSEN (not in Global data): team assignment = the squad with the fewest members, ties to the lower squad number.
  teamAssign: 'fewest members, lower squad first',
  // ENGINE-CHOSEN (not in Global data): win rule: the Sunstone owner when it was kept KeepTime minutes or when time runs out; otherwise the team with the most dkactionpoint points; equal points = draw (pan_top_*_draw); a team left alone in the battlefield wins.
  winRule: 'sunstone kept / sunstone owner / team action points / draw',
  // ENGINE-CHOSEN (not in Global data): KeepTime is minutes the Sunstone owner stays unchanged (160:604 'for __minutes').
  keepTimeUnit: 'minutes',
  // ENGINE-CHOSEN (not in Global data): a draw settles on the _Lose activity row.
  drawRow: 'Lose',
  // ENGINE-CHOSEN (not in Global data): Sunstone communion (npc 6054 job 52 ARENA_CONQUEST) = staying ConquestTime(Sec) in range; moving, being hit or dying stops it (160:622) and blocks the team CoolTime(Sec) (160:201).
  communionRule: 'stay ConquestTime in range, unhit',
  // ENGINE-CHOSEN (not in Global data): communion range = field.csv Pos_Radius (cells).
  communionRange: 'Pos_Radius',
  // ENGINE-CHOSEN (not in Global data): movement tolerated while communing (cells).
  communionMoveTolerance: 0.5,
  // ENGINE-CHOSEN (not in Global data): communion needs personal action points >= MinRewardActionPoint (160:208 'not enough Personal Score points').
  communionNeed: 'MinRewardActionPoint',
  // ENGINE-CHOSEN (not in Global data): the conquering team's present members get Buff 11009 for BuffTime(Sec).
  buffTargets: 'conquering team members inside',
  // ENGINE-CHOSEN (not in Global data): Hit Skill PC (10) counts host skill damage events (skillId set, not a miss) on an enemy participant; Kill Monster (30) counts damage events that kill a battlefield monster.
  eventPoints: 'host damage events',
  // ENGINE-CHOSEN (not in Global data): Move (1) is paid per MoveTimeSec in which the host saw the participant's position change.
  movePoints: 'per MoveTimeSec with a position change',
  // ENGINE-CHOSEN (not in Global data): activity grade = highest Grade whose <rank>_GradePoint <= personal points; rewards need personal points >= MinRewardActionPoint (160:667/668).
  gradeReading: 'GradePoint threshold, MinRewardActionPoint gate',
  // ENGINE-CHOSEN (not in Global data): <rank>_Grade_* is added to the character's Rank Score (160:666), _EXP_* through the normal EXP grant, _Coin_* = CoinIndex items, _Proof_* = ProofIndex items, _Purchase_* (all 0) unused.
  rewardReading: 'Grade -> Rank Score, EXP, Coin, Proof',
  // ENGINE-CHOSEN (not in Global data): DP Score (162:6) += dkkillpoint DkPoint of the battle's PC kills (KillCount above the table uses its last row); DK Tier = dktierbuff row of the battle rank (none for ranks without rows).
  dpReading: 'per battle kills, last row above the table',
  // ENGINE-CHOSEN (not in Global data): rank board rows = characters whose battle this host settled (persisted on the profile, kept in memory since boot), DP Score high to low then name; no reset rule is in the data.
  boardSource: 'settled characters, DP desc then name',
  // ENGINE-CHOSEN (not in Global data): Battle Information columns (160:109-112): Battle = Kill PC / Dead / Hit Skill PC points, Mission = Destroy Guardian Stone / Kill Monster, Bonus = Move, Total = all; Rank (160:108) = current activity grade.
  boardColumns: 'battle / mission / bonus split of dkactionpoint',
  // ENGINE-CHOSEN (not in Global data): rank board rows shown.
  boardRows: 100,
  // ENGINE-CHOSEN (not in Global data): leaving during a fight applies PaneltyStatus for StatusTime(Sec) (status 11067 'raging due to leaving the battlefield').
  penaltyReading: 'leave during the fight',
  // ENGINE-CHOSEN (not in Global data): a downed participant revives at the squad Revive_Pos with Revive; unrevived for autoExitSec it is moved out (160:636 '1 minute').
  autoExitSec: 60,
  // ENGINE-CHOSEN (not in Global data): seconds between the result and moving everyone out (160:70 '%d second(s)').
  finishWaitSec: 30,
  // ENGINE-CHOSEN (not in Global data): exit point = where each participant entered (map 548's kickTo is the DK lobby 68, not on this host's entry route).
  exitPoint: 'entry point',
  // ENGINE-CHOSEN (not in Global data): Lost Horizon NeedItemType 69 is not consumed because NeedItemCount is 0 (and NeedDil 0, WaitTime 0).
  lostHorizonCost: 'none (counts 0)',
  // ENGINE-CHOSEN (not in Global data): the Draco level band = rank.csv row of conquest Rank 0 (Lv.100-149).
  levelBand: 'rank.csv row of the conquest Rank',
  // ENGINE-CHOSEN (not in Global data): Lost Horizon (map 548) IsCreate 0 statue bricks 301/302/401/402 stay unspawned (the data does not say when they appear) and its IsCreate 1 statues (101-105 / 201-205, HP 10) are scenery only; on Draco (map 702) the two further identical rows of each squad stone stay unspawned (dracoStoneUids).
  unspawned: 'Lost Horizon IsCreate 0 statues; IsCreate 1 statues are scenery; Draco duplicate stone rows',
  // ENGINE-CHOSEN (not in Global data): map 702 lists each squad stone three times (same brick, place and HP, IsCreate 0, Revival 0); one stands per squad, the lowest uid (70201 Rebel 37022 / 70210 Terra 37025 / 70220 Miseria 37027 / 70230 Ricchez 37026), from the battle start, breakable by the other squads during the fight, never rebuilt; the destroyer earns Destroy Guardian Stone (300, Mission column); the stone's HPRecovery (no period in the data, no host monster recovery exists) and brick exp column are not applied.
  dracoStoneUids: Object.freeze([70201, 70210, 70220, 70230]),
  // ENGINE-CHOSEN (not in Global data): at settlement each present participant's frozen outcome is first journaled on its own profile (arena.pending, at most this many), removed by the same write that pays it and the receipt, and replayed once at the next presence after a restart or disconnect.
  pendingOutcomes: 32,
  // ENGINE-CHOSEN (not in Global data): Lost Horizon call 1 spawns when the battle starts (the callmonster row has no time); the effect of a destroyed stone image is read from the monster's own name (7878 / 7916 stun, 7879 / 7917 skills disabled, 7880 / 7918 meteor) and lands on every standing member of the other squads.
  stoneImages: 'call 1 at the start; effect by monster name on the opposing squads',
  // ENGINE-CHOSEN (not in Global data): the status used for each effect = the lowest index of the data group (131 Stun = 81, 118 Crisis / Unable to use skill = 1544).
  stoneStatus: Object.freeze({ stun: 81, lock: 1544 }),
  // ENGINE-CHOSEN (not in Global data): seconds a stun / skill lock lasts (the monster rows carry no duration).
  stoneEffectSec: 5,
  // ENGINE-CHOSEN (not in Global data): the meteor takes this percent of each standing opponent's max HP and never kills (the monster row carries no damage).
  stoneMeteor: Object.freeze({ percent: 20, lethal: false }),
  // ENGINE-CHOSEN (not in Global data): a destroyed stone image is not respawned during the battle (the call row carries no respawn).
  stoneRespawn: 'none',
  // ENGINE-CHOSEN (not in Global data): the client refreshes the battle every refreshMs.
  refreshMs: 1000,
});
