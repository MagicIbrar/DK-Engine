// DKR-PVP (DK Rumble 3v3 PvP, Colosseum "pvp3v3"): every value the Global data does not define. Each carries its own tag.
// Defined by the data and read at run time (src/systems/events/dkr-pvp-rules.js):
//   share/dkrpvpbattle/config.csv     map 164, ObserverMaxCount 200, Wait_Time 300, Round_Time 600, Match_Create_Time 300,
//                                     three start cells per team, ObserverSpeed 8
//   share/dkrpvpbattle/matchtime.csv  registration / league allocation / league A-H orders 1-6 / tournament 16-8-4-3-2 calendar
//   npc jobs 148 register, 149 game info, 160 enter player, 161 enter observer (Entry Guard 6180, 60006)
//   texts stringtable_partywarui 2011|*, windows script/ui/game2/dkrpvpbattle/*, team-name edit maxlength 20 (registrationwnd)
// Nothing here scales or modifies a data value; these only fill the gaps the data leaves open.
export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';
export const DKR_PVP_CHOSEN = Object.freeze({
  // ENGINE-CHOSEN (not in Global data): matchtime.csv carries no zone; its rows use the common fixed UTC+1 server calendar.
  calendarZone: 'UTC+1',
  // ENGINE-CHOSEN (not in Global data): teams per league group (6 orders per group = a full round robin of 4 teams).
  groupSize: 4,
  // ENGINE-CHOSEN (not in Global data): league allocation deals teams in registration order round-robin over groups A-H.
  allocation: 'registration-order-round-robin',
  // ENGINE-CHOSEN (not in Global data): the six league orders pair the group's slots like this (slot = allocation order).
  leaguePairs: Object.freeze([[0, 1], [2, 3], [0, 2], [1, 3], [0, 3], [1, 2]]),
  // ENGINE-CHOSEN (not in Global data): league points for a match win / draw / loss (the windows show Points, the data gives none).
  points: Object.freeze({ win: 3, draw: 1, loss: 0 }),
  // ENGINE-CHOSEN (not in Global data): group rank = points, then kills minus deaths, then kills, then registration order.
  rankOrder: Object.freeze(['points', 'killDiff', 'kills', 'registered']),
  // ENGINE-CHOSEN (not in Global data): the best this many teams of each group reach the Round of 16.
  advancePerGroup: 2,
  // ENGINE-CHOSEN (not in Global data): Round of 16 order 1-8 pairings (group winner vs runner-up of the partner group).
  round16: Object.freeze([['A', 1, 'B', 2], ['C', 1, 'D', 2], ['E', 1, 'F', 2], ['G', 1, 'H', 2], ['B', 1, 'A', 2], ['D', 1, 'C', 2], ['F', 1, 'E', 2], ['H', 1, 'G', 2]]),
  // ENGINE-CHOSEN (not in Global data): a match is up to this many rounds (matchresultwnd has five round rows) ...
  maxRounds: 5,
  // ENGINE-CHOSEN (not in Global data): ... and ends as soon as a team has won this many rounds.
  roundsToWin: 3,
  // ENGINE-CHOSEN (not in Global data): a round still running at Round_Time goes to the team with more kills in it, else it is a draw round.
  roundTimeout: 'kills-else-draw',
  // ENGINE-CHOSEN (not in Global data): a tournament match level on rounds goes to more kills, then fewer deaths, then the upper bracket slot.
  tournamentTiebreak: Object.freeze(['kills', 'fewerDeaths', 'upperSlot']),
  // ENGINE-CHOSEN (not in Global data): seconds of the round-start count and of the round result window, and between rounds.
  countSec: 5,
  finishRoundSec: 10,
  breakSec: 5,
  // ENGINE-CHOSEN (not in Global data): seconds the match result window stays before the arena closes.
  finishMatchSec: 30,
  // ENGINE-CHOSEN (not in Global data): a team with fewer entrants than this when Wait_Time ends forfeits the match.
  minimumEntrants: 1,
  // ENGINE-CHOSEN (not in Global data): config.csv has no observer point; observers enter between the two team lines.
  observerPoint: Object.freeze([256, 255]),
  // ENGINE-CHOSEN (not in Global data): ObserverSpeed has no unit; the observer camera flies at that many cells/s exactly as written
  // (same reading as the OBSERVER gate's fSpeed). Walking keeps the normal run speed.
  observerSpeedUnit: 'cells/s',
  // ENGINE-CHOSEN (not in Global data): how close (cells) to the Entry Guard the host accepts a job request.
  npcRadius: 8,
  // ENGINE-CHOSEN (not in Global data): downed fighters stay down until the next round (no revive inside a round).
  reviveInRound: false,
});
