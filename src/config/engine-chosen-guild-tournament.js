// Guild Tournament (Colosseum Lobby 162 -> Guild Tournament map 165): values the shipped client data does not contain.
// Every value here is ENGINE-CHOSEN (not in Global data). Data-backed values stay in the data:
//   share/guildtournament/config.csv (GUILDMATCH_LIST_INDEX 1, DEFAULT_MATCH 16, DEFAULT_ORDER 1, WAITING_TIME 180),
//   share/guildtournament/match.csv (bracket: MATCH/ORDER -> NEXTMATCH/NEXTORDER/NEXTSEED),
//   share/guildtournament/donation.csv (B_COIN 6804 / P_COIN 6805, amounts 10/50/100/500/1000),
//   share/colosseum/guildmatch/list.csv (map 165, 7 members, team A/B starts, observer point),
//   NPC jobs 86-95/100 (Ferdianand 5159, Donation Angel 5165, Gambler Egg 5166), stringtable_colosseum 360|*.
// PvP hits use the shared PvP rules (src/game/pvp-rules.js) through server/world/pvp.mjs registerPvpMode.
// Lane 71: match-phase timers and the points rule from the official JP publisher notice (ONLINE: dk.brabragames.jp/news/notice.html?mode=read&no=589,
//   2023 Strongest Guild Tournament): entry wait 3 hours (= GLOBAL WAITING_TIME 180, read as minutes), a 5-minute break before the match,
//   rounds of at most 10 minutes, a 5-minute rest before the next round, at most 3 rounds, win 2 / draw 1 / loss 0 points, first to 4 points
//   wins, 3:3 after the rounds = rematch, a guild whose members do not take part forfeits. Phases the notice does not have (Count, Finish
//   Round, Finish Match) are 0 seconds (no source: the phase is skipped, not invented).
export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';
export const GUILD_TOURNAMENT_ENGINE_CHOSEN = Object.freeze({
  tag: ENGINE_CHOSEN_TAG,
  // Season model: on demand. The first seed request opens registration; the bracket locks registrationSec later
  // (or as soon as all 16 seeds are taken) and the matches run one after another in match.csv order.
  // ONLINE (no=589: applications 2023-06-16 after maintenance to 06-29 11:59) + JUDGMENT (the window rounded to 13 whole days).
  registrationSec: 13 * 86400,
  minGuilds: 2,               // a bracket with fewer guilds is cancelled (203 "Guild Tournament has ended.")
  // Seeds: Round of 16 order k pairs seed 2k-1 (left) against seed 2k (right). An empty seed is a bye.
  // Match phases (strings 360|193-199). The entry wait is the data's WAITING_TIME.
  readySec: 300,                // 194 Ready Time (ui_battlereadywnd) - ONLINE no=589: 5-minute break before the match
  countSec: 0,                  // 195 Count - no source: skipped
  roundSec: 600,                // 196 Battle (one round) - ONLINE no=589: a round lasts at most 10 minutes
  finishRoundSec: 0,            // 197 Finish Round (ui_roundendwnd) - no source: skipped
  breakSec: 300,                // 199 Break Time between rounds - ONLINE no=589: 5-minute rest before the next round
  finishMatchSec: 0,            // 198 Finish Match (ui_battlereultwnd) - no source: everyone returns to the lobby at once
  // ONLINE no=589: win 2 / draw 1 / loss 0 points per round, the first guild to 4 points wins, at most 3 rounds; 3:3 = rematch
  // (JUDGMENT: the rematch is played as further rounds until one guild is 4+ points and ahead).
  roundPoints: Object.freeze({ win: 2, draw: 1, loss: 0 }),
  pointsToWin: 4,
  maxRounds: 3,
  roundsToWin: 2,             // round wins a forfeit winner is credited with (2:0, 360|76-79 rounds; = pointsToWin / win points)
  // Round winner: the side left standing; at the time limit the side with more kills; equal kills = draw round (JUDGMENT, lane 49).
  // ONLINE no=589 rule 6: a guild whose members do not take part forfeits even if only the majority is absent. JUDGMENT: 'majority'
  // of the 7-member roster (list.csv MemberCount 7) = fewer than 4 entrants forfeits; both short = both disqualified (206).
  minimumEntrants: 4,
  // Roster (ui_entrymemberwnd): the guild master picks up to MemberCount online guild members, one per class (182).
  // Betting (ui_bettingwnd): one bet per character per match on a final score, paid in P or B coins. The data has no
  // odds table; the RATIO of 360|178/187 is the native pool split (no house multiplier): per coin, every coin bet on
  // the match divided by the coins bet on the final score. A winning bet pays floor(amount x ratio) into the
  // claimable pool (ui_rewardbettingwnd); losing bets are lost. Only the step/max of the amount buttons are chosen.
  betScores: Object.freeze(['2:0', '2:1', '1:2', '0:2']),
  betStep: 10,                // the up/down buttons change the bet by this many coins
  betMax: 1000,
  // Donation (Donation Angel): donations add to the guild's season total; the ranking window lists every donating
  // guild. The top 16 are 24 "Strongest Cid Candidate", the rest 25 "Reserved Cid Candidate".
  candidateCount: 16,
  // Server name: Global's client has no fixed string; the server supplies it. Left empty (no invented name).
  serverName: '',
  // Donation Angel and Gambler Egg have no placement row in the data. They are placed beside Ferdianand in the
  // Colosseum Lobby (same facing), rows in the npc_*.csv layout: [npc, x, y, dir, warpX, warpY, isEvent, desc].
  placements: Object.freeze({
    162: Object.freeze([
      Object.freeze([5165, 113.936, 250.732, 270, 116, 250, 0, '']),
      Object.freeze([5166, 113.936, 260.732, 270, 116, 260, 0, '']),
    ]),
  }),
  // Jobs 88 GUILDTOURNAMENT_SELECT_RANK / 89 SEED_INFO / 91 ENTRY_INFO belong to no NPC in the data: Ferdianand's
  // info service (job 90) offers them (entry list, Request Cid, Select Players).
  infoJobs: Object.freeze([90, 91, 89, 88]),
  // Window layout spacing for the scripts' template controls (derived from their rects).
  layout: Object.freeze({ bracket16: 70, bracket8: 140, seedButton: 35, entryRow: 35, memberRow: 26, rankingRow: 26, betRow: 45, resultRow: 30, rosterColumn: 272, matchRow: 35, dashboardMember: 52 }),
  // ui_battlereultwnd pan_score_left/right show the round wins as guildtournament digit images; the script shows
  // index 50 for 0, so digit n is drawn with index scoreDigitBase + n.
  scoreDigitBase: 50,
  rankingPage: 16,            // rows per ui_donationrankingwnd page (page 1 = the 16 Cid candidates)
});
/** Original placement rows of a map plus the ENGINE-CHOSEN rows above (never duplicating an authored NPC). */
export function withChosenPlacements(map, rows = []) {
  const extra = GUILD_TOURNAMENT_ENGINE_CHOSEN.placements[Number(map)] || [];
  const have = new Set(rows.map(r => Number(Array.isArray(r) ? r[0] : r?.npcIndex)));
  return [...rows, ...extra.filter(r => !have.has(r[0])).map(r => [...r])];
}