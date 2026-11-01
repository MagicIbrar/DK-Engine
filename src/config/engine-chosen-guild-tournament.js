// Guild Tournament (Colosseum Lobby 162 -> Guild Tournament map 165): values the shipped client data does not contain.
// Every value here is ENGINE-CHOSEN (not in Global data). Data-backed values stay in the data:
//   share/guildtournament/config.csv (GUILDMATCH_LIST_INDEX 1, DEFAULT_MATCH 16, DEFAULT_ORDER 1, WAITING_TIME 180),
//   share/guildtournament/match.csv (bracket: MATCH/ORDER -> NEXTMATCH/NEXTORDER/NEXTSEED),
//   share/guildtournament/donation.csv (B_COIN 6804 / P_COIN 6805, amounts 10/50/100/500/1000),
//   share/colosseum/guildmatch/list.csv (map 165, 7 members, team A/B starts, observer point),
//   NPC jobs 86-95/100 (Ferdianand 5159, Donation Angel 5165, Gambler Egg 5166), stringtable_colosseum 360|*.
// PvP hits use the shared PvP rules (src/game/pvp-rules.js) through server/world/pvp.mjs registerPvpMode.
export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';
export const GUILD_TOURNAMENT_ENGINE_CHOSEN = Object.freeze({
  tag: ENGINE_CHOSEN_TAG,
  // Season model: on demand. The first seed request opens registration; the bracket locks registrationSec later
  // (or as soon as all 16 seeds are taken) and the matches run one after another in match.csv order.
  registrationSec: 600,
  minGuilds: 2,               // a bracket with fewer guilds is cancelled (203 "Guild Tournament has ended.")
  // Seeds: Round of 16 order k pairs seed 2k-1 (left) against seed 2k (right). An empty seed is a bye.
  // Match phases (strings 360|193-199). The entry wait is the data's WAITING_TIME.
  readySec: 30,               // 194 Ready Time (ui_battlereadywnd)
  countSec: 5,                // 195 Count
  roundSec: 300,              // 196 Battle (one round)
  finishRoundSec: 10,         // 197 Finish Round (ui_roundendwnd)
  breakSec: 30,               // 199 Break Time between rounds
  finishMatchSec: 30,         // 198 Finish Match (ui_battlereultwnd), then everyone returns to the lobby
  roundsToWin: 2,             // best of three (Round 1-3 / Final Round, 360|76-79)
  // Round winner: the side left standing; at the time limit the side with more kills; equal kills = draw round.
  // Match winner after 3 rounds without 2 wins: more total kills, then more first kills, then the lower seed.
  // A side with no entrant when the entry wait ends forfeits; both empty = both disqualified (206), nobody advances.
  minimumEntrants: 1,
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
  serverName: 'Dekaron Online',
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