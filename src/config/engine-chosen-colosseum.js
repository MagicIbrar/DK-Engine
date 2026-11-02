// COLOSSEUM (Battle Royale classic 163 / renew 196, Individual Ranking Match 164): values the shipped client data does
// not contain. Lane 51 g: every value here is a JUDGMENT (no value in Global data, the decompiles, the server reference -
// its colosseum states carry no timing - or the guides) with its reasoning in the comment, unless labelled ONLINE / GLOBAL.
// Data-backed values stay in the data:
//   share/colosseum/battleroyal/{list,grade,playtime,reward_br}.csv (map 163, 16 start cells, grade S 185-250, daily
//     hours 2-3 / 7-8 / 13-14 / 19-20, round coins + CP, CP per kill / per buff),
//   share/colosseum/battleroyal_renew/{list,grade,playtime,reward_br}.csv (map 196, channel 100, ticket 4002357,
//     16 members, entry 347,263 / battle 256,259, grade S 185-230, Sunday 0-24, rank rows: Rank_Point, Kill_Per_Point,
//     item 4002356),
//   share/colosseum/partymatch/{list,grade,playtime,reward}.csv (map 164, 2:2, team A / B starts, level sections x PCP
//     bands, B Coin 6804 W 75 / L 20 / D 0, PCP W 65 / L 14 / D 33, CP per kill 3 / per win 3, MVP rate 1),
//   the map tables of 163 / 164 / 196 (round effects, timer labels, 700 death sentence, 90 inventory full) and
//   stringtable_colosseum 360|* (refusals, mode names, column titles).
// PvP hits use the shared PvP rules (src/game/pvp-rules.js) through server/world/pvp.mjs registerPvpMode.
export const ENGINE_CHOSEN_TAG = 'JUDGMENT (lane 51 g; not in Global data) unless labelled';
export const COLOSSEUM_ENGINE_CHOSEN = Object.freeze({
  tag: ENGINE_CHOSEN_TAG,
  // Registration: no NPC of the Global npc.csv carries the waiting-list jobs 81 / 82 / 132, so the hidden minimap
  // button btn_colosseummatching (colosseum image 50) is shown while a mode's playtime is open and opens the mode
  // choice (360|8 Battle Royale / 360|9 Individual Match); the NPC jobs, where present, use the same registration.
  entry: 'minimap btn_colosseummatching while a playtime is open; NPC jobs 81 / 82 / 132 register the same way',
  // Matching: a match forms when the queue of a mode holds MemberCount (Battle Royale) or 2 x MemberCount of one
  // grade row (Individual Match) players, in registration order; there is no timeout and no partial match.
  matchFill: 'MemberCount in registration order, no timeout',
  // Individual Match teams: queue order alternates A, B, A, B.
  teamPairing: 'alternate A / B in queue order',
  // 360|7 "(You will join in %d sec.)": the prompt countdown; joining is automatic when it ends, closing the prompt
  // declines (360|119) and the player leaves the queue. Fewer than minEntrants left: the others go back to the front.
  // JUDGMENT: 360|7 prints the count with no number; 10 s = the Global duel request wait (decompile PVPRequestWaitWnd 9999 ms),
  // the client's other accept prompt.
  entryPromptSec: 10,
  minEntrants: Object.freeze({ battleRoyal: 2, individual: 4 }),
  // Battle Royale phases (map 196 timer labels 300 Start waiting / 302+ Round N; map 163 round effects 200-500).
  // JUDGMENT: 30 s = Global share/article/partypvp.csv WaitTime 30, the data's own PvP match start wait.
  startWaitSec: 30,
  // ONLINE (nearest source, Fomos 2021-05-04 on the publisher's Colosseum Battle Royale update: a fighter dies after 3 minutes unless
  // a kill renews the 3 minutes) + JUDGMENT: one round = that 3-minute survival window (was 120).
  roundSec: 180,
  // Rounds: classic Round 1, 2, 3, Final (reward_br Round1..3 / RoundF / Champ); renew up to 30 rounds (the 30
  // Round N labels of map 196). The death roll ("You have been sentenced to death.", map 163:700, the DeathRollWnd)
  // runs at every round end: classic keeps at most 8 / 4 / 2 / 1 players after Round 1 / 2 / 3 / Final, renew
  // sentences one player when nobody was eliminated during the round (and everyone but one after the last round).
  classicCaps: Object.freeze([8, 4, 2, 1]),
  renewRounds: 30,
  deathRollPick: 'fewest kills first, ties by a random roll',
  // Place order: the survivor first, then by elimination (later = better; one death roll: more kills first).
  placeOrder: 'survivor, then later elimination, then more kills',
  // Classic reward row: reward_br Index 1 ("Class 1"); the data gives no rule for picking "Class 2".
  classicRewardRow: 1,
  // reward_br Reward_Coin_* has no coin index; the only Colosseum coin index of the data is partymatch Coin_Index
  // 6804 (B Coin), used for the Battle Royale coins too.
  classicCoinItem: 6804,
  // Points: every "CP" award (reward_br Reward_CP_*, reward.csv Reward_CP_*) is Colosseum Point (ranking Total 360|44);
  // Battle Royale CP and the renew Rank_Point / Kill_Per_Point are B Point (360|12, ranking Battle Royale 360|45);
  // reward.csv PCP is the Individual Match point (ranking 360|46) and also picks the grade.csv PCP band (a PCP above
  // the last band's PCP_Max uses that last band).
  points: 'CP -> Total; BR CP / Rank_Point -> B Point; PCP -> Individual Match',
  // A Battle Royale CP / coin reward is the highest round reached (Round1..3 / RoundF) or Champ for the winner.
  // Blessing of the Dead (buff_table.csv, Korean "Blessing of the Dead buff set": statuses 7101-7104, four "souls of the dead",
  // Buff_Rate 100 / 75 / 50 / 25): the data has no spawn point, time or object for it. The pickup object is the Crystal of the
  // Dead 2826 (Korean name in the same "of the dead" family; HP 3, breakable object shape deadman_buffer), which no map of the
  // data places anywhere.
  crystal: 2826,
  // One crystal appears on the cell where an entrant dies in a Battle Royale round (PvP kill or death roll; not a leaver); it
  // stays until it is broken or the result; Individual Match (no buff_table) has none.
  crystalSpawn: 'cell of each Battle Royale death, until broken or the result',
  // Pickup = the breaking hit (ordinary attack or skill) of the live session of a standing entrant of the same match inside its
  // arena during a round; any other breaker gets nothing and the crystal stands again on its cell.
  crystalTake: 'breaking hit of a standing entrant in its own arena during a round',
  // Each buff_table row is rolled on its own Buff_Rate as a percentage (literal reading: 100 = always), one stack per success up
  // to the status row's maxStack 10; a success at maxStack only refreshes the status and is not a blessing received.
  buffRoll: 'each row on its own Buff_Rate %, one stack each up to maxStack',
  // A blessing lasts while its holder stands in the match: it ends at elimination, at the result and at exit, and is removed
  // from anyone outside a running Battle Royale.
  blessingTime: 'while standing in the match',
  // Reward_CP_Per_Buffs (classic reward_br) x blessings received (stacks gained, result column 360|15 "Buffs") is added to the
  // classic CP / B Point; renew reward_br has no per-buff column, so renew blessings change no score.
  buffPoints: 'classic Reward_CP_Per_Buffs per blessing received; renew none',
  // Individual Match: ready wait (map 164:100), fight time limit, then win / lose / draw (164:300 / 400 / 500).
  // JUDGMENT: ready wait = partypvp.csv WaitTime 30 (above); fight = 5 min, half the 10-minute round of the official JP guild
  // tournament notice (dk.brabragames.jp no=589, 7 vs 7) for a 2 vs 2 match.
  matchReadySec: 30,
  matchSec: 300,
  // ONLINE (JP guild tournament notice no=589 round decision: annihilation, else more kills at the time limit, else draw): win rule:
  // the side with a standing member when the other has none; at the time limit more kills; equal = draw.
  matchWinRule: 'annihilation, else more kills at the time limit, equal = draw',
  // MVP: the most kills of the match (a tie = no MVP); Reward_MVP_Rate multiplies its CP (the data's rate is 1).
  mvpRule: 'most kills, tie = none',
  // JUDGMENT (= partypvp.csv WaitTime 30, reading the result windows): after the result everyone stays this long, then returns to where they registered.
  resultSec: 30,
  // Downed / eliminated players stay down until the result (no revive in the arena).
  revive: 'You cannot revive during a Colosseum match.',
  // DeathRollWnd lines: the sentenced player sees map 163:700; the others see "<name> <360|13 Died>".
  deathRollLine: '<name> Died',
  // Ranking board: every character with a Colosseum record known to this host, by the category points; the weekly /
  // monthly views count the points earned in the current ISO week / calendar month.
  ranking: 'host records; week = ISO week, month = calendar month',
  // GLOBAL (UI geometry): rows per page: pan_base (y 126, 26 high) down to pan_page (y 402) of ui_rankingwnd.
  rankingRows: 10,
  // Inventory full at the reward: map 163:90 is shown and that item reward is not given (points are kept).
  bagFull: 'item reward not given, points kept',
  // Server name: Global's client has no fixed string; the server supplies it. Left empty (no invented name).
  serverName: '',
  // Battle Royale result table (battleroyal/ui_resultwnd): the script has the tags and a 16-row panel but no row controls, so the host
  // sends each entrant's queue order and the client fills one row per entrant under the tags; the "Enter" column shows that order.
  resultEnterColumn: 'entry order in the queue (1..16)',
  // Individual Match result (pvpmode/ui_resultwnd): the script has one board; the window shows Red Team (A) on the left and Blue Team (B) on
  // the right, so the second half reuses the same header and row layout 428 px to the right.
  resultTeamBoards: 'Red Team (A) left board, Blue Team (B) right board with the same columns',
});
export function colosseumChosenList() { return Object.entries(COLOSSEUM_ENGINE_CHOSEN).filter(([k]) => k !== 'tag').map(([k, v]) => `${k}=${typeof v === 'object' ? JSON.stringify(v) : JSON.stringify(v)}`); }