// MONSTER CARNIVAL rules shared by the host (server/world/monster-carnival.mjs), the client windows
// (src/systems/network/monster-carnival.js), the host stat pipeline (server/world/data.mjs) and
// tools/test-shipwreck-carnival.mjs. Native data: dungeons.json forgottenShipwreck (startcondition.csv schedule, rewardslot.csv
// tables), string cate 161 of stringtable_dksquare.txt. Choices: src/config/engine-chosen-monster-carnival.js.
import { serverDate } from '../../game/server-time.js';
import { CARNIVAL_CHOSEN as C } from '../../config/engine-chosen-monster-carnival.js';

export const CARNIVAL_STRINGS = 'stringtable_dksquare.txt', CARNIVAL_CATE = 161, CARNIVAL_DUNGEON = '234';
export const BLUE = 0, RED = 1;
// Original texts (stringtable_dksquare.txt cate 161, "[message]" / <center> removed); tools/test-shipwreck-carnival.mjs compares them.
export const CARNIVAL_TEXT = Object.freeze({
  time: 'Time remaining',                                                             // 161:1
  roulette: 'Shipwreck Roulette',                                                     // 161:2
  cp: 'CP',                                                                           // 161:3
  consumed: 'CP %d consumed',                                                         // 161:4
  use: 'Use',                                                                         // 161:5
  waiting: 'Waiting to enter the Forgotten Shipwreck.',                               // 161:7
  count: '%d of %d people are waiting.',                                              // 161:8
  spinDead: 'You cannot spin reward slots while dead.',                               // 161:9
  noSpace: 'There is no space available to receive the reward item.',                 // 161:10
  uses: 'Number of uses remaining :',                                                 // 161:11
  safeZone: 'Cannot spin slots in the safe zone.',                                    // 161:12
  blue: 'BLUE',                                                                       // 161:101
  red: 'RED',                                                                         // 161:102
  closed: 'Forgotten Shipwreck entry is unavailable at this time.\nPlease refer to the content guide for detailed admission times.', // 161:202
  colosseum: 'You cannot open the Forgotten Shipwreck lobby during Coliseum Matching.', // 161:204
  noServer: 'Forgotten Shipwreck Servers not found.',                                 // 161:205
  already: 'Already waiting in the lobby.',                                           // 161:206
  received: 'Received %d %s of %s as a reward.',                                      // 161:207
  unknown: 'Failed due to unknown error.',                                            // 161:208
  spun: 'The slot is already closed.',                                                // 161:209
  noInfo: 'No information found.',                                                    // 161:210
  failed: 'Failed.',                                                                  // 161:211
  skillFailed: 'Failed to use skill.',                                                // 161:217
  noCp: 'Cannot use skill due to lack of CP.',                                        // 161:218
  badTarget: 'You have selected a destination that cannot be specified.',             // 161:219
  maxUses: 'Exceeded 10 uses.',                                                       // 161:220
  entry: 'Entry failed.',                                                             // 161:222
  noTicket: 'You have failed to enter because you do not have a ticket.',             // 161:223
  dead: 'You cannot enter while dead.',                                               // 161:224
});
export const CARNIVAL_CODES = Object.freeze({ time: 1, roulette: 2, cp: 3, consumed: 4, use: 5, waiting: 7, count: 8, spinDead: 9, noSpace: 10, uses: 11, safeZone: 12, blue: 101, red: 102,
  closed: 202, colosseum: 204, noServer: 205, already: 206, received: 207, unknown: 208, spun: 209, noInfo: 210, failed: 211, skillFailed: 217, noCp: 218, badTarget: 219, maxUses: 220,
  entry: 222, noTicket: 223, dead: 224 });
// Native effects (161:103 end_win_eff 1133, 161:104 end_lose_eff 1134, 161:105 m_carnival_text 1136, 161:225 forgotten_shipwreck_start_1 2553).
export const CARNIVAL_EFFECTS = Object.freeze({ win: 103, lose: 104, carnival: 105, start: 225 });
export const fmt = (s, ...v) => { let i = 0; return String(s).replace(/%[sd]/g, () => String(v[i++] ?? '')); };
/** The six team skills of ui_team_skill_wnd: icon monster_carnival 32+n, short text 161:32+n, long text 161:132+n. */
export const CARNIVAL_SKILLS = Object.freeze([1, 2, 3, 4, 5, 6].map(n => Object.freeze({
  skill: n, icon: 32 + n, short: 32 + n, long: 132 + n, cost: C.skillCost[n - 1],
  kind: ['heal', 'attack', 'root', 'seal', 'random', 'combat'][n - 1], target: n === 6 })));
/** The startcondition row whose DAY (0 = Sunday, fixed UTC+1) and Start_Hour <= hour < Finish_Hour hold `now`, else null. */
export function carnivalWindow(schedule, now) {
  const d = serverDate(now), wd = d.getUTCDay(), h = d.getUTCHours();
  return (schedule || []).find(r => Number(r.day) === wd && h >= Number(r.startHour) && h < Number(r.finishHour)) || null;
}
/** Team-skill 2 (161:34): the native All Attack option pair while it lasts (host stat pipeline extraOptions). */
export const CARNIVAL_ATTACK = Object.freeze({ option: 325, value: 30, ms: 60000 });
export function carnivalStatOptions(actor, now) { return Number(actor?.carnivalAttackUntil) > Number(now) ? [[CARNIVAL_ATTACK.option, CARNIVAL_ATTACK.value]] : []; }
