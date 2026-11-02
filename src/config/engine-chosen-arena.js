// ARENA (Draco Desert Battlefield, npc job 130 EGUTT_ENTER; Lost Horizon battlefield, npc job 111 ARENA_LOSTHORIZON).
// Global parity: every number comes from the Global data (share/arena/*.csv as parsed into
// gamedata/events.json modes.arena, the map dungeon rows, string cate 160/162, status 11009/11067) and every PvP hit runs
// src/game/pvp-rules.js through server/world/pvp.mjs. No scaling, multiplier or modifier is added. Only the gaps the data
// leaves open are listed here, each on its own line labelled ONLINE / GLOBAL (with source) or JUDGMENT (with reasoning).
export const ARENA_CHOSEN = Object.freeze({
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): job 130 enters conquest.csv Mode 3 (Rank 0) on field.csv Type 3 (map 702); job 111 enters losthorizon.csv Mode 100 on field.csv Type 2 (map 548, rank.csv Rank 100).
  venueJobs: Object.freeze({ 130: 'draco', 111: 'lostHorizon' }),
  // JUDGMENT (lane 51 g; no source; reasoning: a host-side bound that covers walking up to and clicking the entry NPC): distance from the entry NPC that counts as talking to it (cells).
  npcRadius: 12,
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): OpenTime_1 is the fixed UTC+1 server hour of the single opening (OpenCount 1); 24 = open all day; one opening lasts FightTime(Sec).
  openReading: 'UTC+1 server hour, FightTime long',
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): Lost Horizon has no FightTime row; its battle lasts the map 548 dungeon row expireTime (minutes).
  lostHorizonFight: 'dungeon.expireTime minutes',
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): Lost Horizon starts once the dungeon row requestMember players are queued in total; rank.csv Max_Room caps one room.
  lostHorizonStart: 'requestMember queued in total',
  // ONLINE (lane 51 g, official JP publisher DK Square guide dk.brabragames.jp/guide no=41&pno=61: teams are formed at random) + JUDGMENT (the fill rule): team assignment = the squad with the fewest members, ties to the lower squad number.
  teamAssign: 'fewest members, lower squad first',
  // ONLINE (lane 51 g, official JP publisher DK Square guide dk.brabragames.jp/guide no=41&pno=61: the battle ends at time-out or a successful Sunstone communion; the higher battle + mission point total wins; a draw gives both sides the loss result) + JUDGMENT (owner at time-out, a lone team wins): win rule: the Sunstone owner when it was kept KeepTime minutes or when time runs out; otherwise the team with the most dkactionpoint points; equal points = draw (pan_top_*_draw); a team left alone in the battlefield wins.
  winRule: 'sunstone kept / sunstone owner / team action points / draw',
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): KeepTime is minutes the Sunstone owner stays unchanged (160:604 'for __minutes').
  keepTimeUnit: 'minutes',
  // ONLINE (lane 51 g, official JP publisher DK Square guide dk.brabragames.jp/guide no=41&pno=61: a draw gives both teams the loss points): a draw settles on the _Lose activity row.
  drawRow: 'Lose',
  // ONLINE (lane 51 g, official JP publisher DK Square guide dk.brabragames.jp/guide no=41&pno=61: a death during communion bars that team from communion for 30 s = conquest.csv CoolTime 30) + JUDGMENT (moving / being hit also stops it): Sunstone communion (npc 6054 job 52 ARENA_CONQUEST) = staying ConquestTime(Sec) in range; moving, being hit or dying stops it (160:622) and blocks the team CoolTime(Sec) (160:201).
  communionRule: 'stay ConquestTime in range, unhit',
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): communion range = field.csv Pos_Radius (cells).
  communionRange: 'Pos_Radius',
  // communionMoveTolerance REMOVED (f pass: no source): any movement while communing stops it.
  communionMoveTolerance: 0,
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): communion needs personal action points >= MinRewardActionPoint (160:208 'not enough Personal Score points').
  communionNeed: 'MinRewardActionPoint',
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): the conquering team's present members get Buff 11009 for BuffTime(Sec).
  buffTargets: 'conquering team members inside',
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): Hit Skill PC (10) counts host skill damage events (skillId set, not a miss) on an enemy participant; Kill Monster (30) counts damage events that kill a battlefield monster.
  eventPoints: 'host damage events',
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): Move (1) is paid per MoveTimeSec in which the host saw the participant's position change.
  movePoints: 'per MoveTimeSec with a position change',
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): activity grade = highest Grade whose <rank>_GradePoint <= personal points; rewards need personal points >= MinRewardActionPoint (160:667/668).
  gradeReading: 'GradePoint threshold, MinRewardActionPoint gate',
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): <rank>_Grade_* is added to the character's Rank Score (160:666), _EXP_* through the normal EXP grant, _Coin_* = CoinIndex items, _Proof_* = ProofIndex items, _Purchase_* (all 0) unused.
  rewardReading: 'Grade -> Rank Score, EXP, Coin, Proof',
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): DP Score (162:6) += dkkillpoint DkPoint of the battle's PC kills (KillCount above the table uses its last row); DK Tier = dktierbuff row of the battle rank (none for ranks without rows).
  dpReading: 'per battle kills, last row above the table',
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): rank board rows = characters whose battle this host settled (persisted on the profile, kept in memory since boot), DP Score high to low then name; no reset rule is in the data.
  boardSource: 'settled characters, DP desc then name',
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): Battle Information columns (160:109-112): Battle = Kill PC / Dead / Hit Skill PC points, Mission = Destroy Guardian Stone / Kill Monster, Bonus = Move, Total = all; Rank (160:108) = current activity grade.
  boardColumns: 'battle / mission / bonus split of dkactionpoint',
  // boardRows cap REMOVED (f pass: no source): the rank board lists every participant.
  boardRows: Infinity,
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): leaving during a fight applies PaneltyStatus for StatusTime(Sec) (status 11067 'raging due to leaving the battlefield').
  penaltyReading: 'leave during the fight',
  // ONLINE (lane 51 g, official JP publisher DK Square guide dk.brabragames.jp/guide no=41&pno=61: a player not revived within 1 minute is moved out of the battle) + GLOBAL 160:636 '1 minute': a downed participant revives at the squad Revive_Pos with Revive; unrevived for autoExitSec it is moved out (160:636 '1 minute').
  autoExitSec: 60,
  // REMOVED (lane 47; closed lane 51 g): finishWaitSec (30). Global has no value for the 160:70 '%d second(s)' move-out wait;
  // the host moves participants out as soon as the result is settled.
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): exit point = where each participant entered (map 548's kickTo is the DK lobby 68, not on this host's entry route).
  exitPoint: 'entry point',
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): Lost Horizon NeedItemType 69 is not consumed because NeedItemCount is 0 (and NeedDil 0, WaitTime 0).
  lostHorizonCost: 'none (counts 0)',
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): the Draco level band = rank.csv row of conquest Rank 0 (Lv.100-149).
  levelBand: 'rank.csv row of the conquest Rank',
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): Lost Horizon (map 548) IsCreate 0 statue bricks 301/302/401/402 stay unspawned (the data does not say when they appear) and its IsCreate 1 statues (101-105 / 201-205, HP 10) are scenery only; on Draco (map 702) the two further identical rows of each squad stone stay unspawned (dracoStoneUids).
  unspawned: 'Lost Horizon IsCreate 0 statues; IsCreate 1 statues are scenery; Draco duplicate stone rows',
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): map 702 lists each squad stone three times (same brick, place and HP, IsCreate 0, Revival 0); one stands per squad, the lowest uid (70201 Rebel 37022 / 70210 Terra 37025 / 70220 Miseria 37027 / 70230 Ricchez 37026), from the battle start, breakable by the other squads during the fight, never rebuilt; the destroyer earns Destroy Guardian Stone (300, Mission column); the stone's HPRecovery (no period in the data, no host monster recovery exists) and brick exp column are not applied.
  dracoStoneUids: Object.freeze([70201, 70210, 70220, 70230]),
  // At settlement each present participant's frozen outcome is first journaled on its own profile (arena.pending), removed by the same write that pays it and the receipt, and replayed once at the next presence after a restart or disconnect. The engine cap (32) is REMOVED (f pass: no source): nothing is dropped.
  pendingOutcomes: Infinity,
  // ONLINE (lane 51 g, official JP publisher Lost Horizon guide dk.brabragames.jp/guide no=41&pno=63: the shock statue stuns the enemy party, the weakness statue locks their skills, the flame statue drops a meteor) + JUDGMENT (call 1 at the start): Lost Horizon call 1 spawns when the battle starts (the callmonster row has no time); the effect of a destroyed stone image is read from the monster's own name (7878 / 7916 stun, 7879 / 7917 skills disabled, 7880 / 7918 meteor) and lands on every standing member of the other squads.
  stoneImages: 'call 1 at the start; effect by monster name on the opposing squads',
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): the status used for each effect = the lowest index of the data group (131 Stun = 81, 118 Crisis / Unable to use skill = 1544).
  stoneStatus: Object.freeze({ stun: 81, lock: 1544 }),
  // JUDGMENT (lane 51 g; official JP publisher Lost Horizon guide dk.brabragames.jp/guide no=41&pno=63 says only "for a certain time"; reasoning: 5 s is a short control window well inside the guide's 18 s combo-decay window, so a stunned squad can still hold its score): seconds a stun / skill lock lasts (the monster rows carry no duration).
  stoneEffectSec: 5,
  // JUDGMENT (lane 51 g; no source gives the damage; reasoning: a fixed share of max HP that never kills keeps the meteor a pressure effect, not a kill the stone row cannot credit): the meteor takes this percent of each standing opponent's max HP and never kills (the monster row carries no damage).
  stoneMeteor: Object.freeze({ percent: 20, lethal: false }),
  // JUDGMENT (lane 51 g; no value in Global data, decompiles, server reference or guides): a destroyed stone image is not respawned during the battle (the call row carries no respawn).
  stoneRespawn: 'none',
  // JUDGMENT (lane 51 g; no source; reasoning: the board shows whole seconds, so once a second is the finest visible change): the client refreshes the battle every refreshMs.
  refreshMs: 1000,
});
