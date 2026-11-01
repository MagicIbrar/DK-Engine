// Attendance Rewards: pure rules shared by the host (server/world/support-rewards.mjs) and the client window
// (attendance.js). Every value comes from the original client files:
//
//   share/support/attendancereward/attend_set.csv   Index, StartDate, EndDate (YYYYMMDD), StartTime, EndTime (HHMM), Enable,
//                                                   Count (days on the board), GroupIndex (gamedata boxes.json attendance.sets)
//   share/support/attendancereward/attend_list.csv  GroupIndex, No (day 1..Count), Type, Value1_1, value1_2, Reward Index,
//                                                   Reward Count, Reward Size, Process Func (boxes.json attendance.days)
//   script/string/normal/stringtable_event.txt (NORMAL cate 2300): 21 "Attendance Rewards" (title + alarm tooltip),
//     22 "Must close inventory window to access Attendance Rewards.", 24 "%s Claim this reward? Only one character per account
//     can claim.", 25 the rules: "Board updates daily. Complete each day's mission to access the next day's." / "Each reward can
//     only be claimed once per account." / "You may claim different rewards for multiple characters on the same account." /
//     "Only one character can claim a reward per day." / "Missions & rewards will change every four weeks."; 15..20 claim
//     results; 26 "Please wait until the next event period."; cate 2310 1001 "Connection Time: Stay connected for indicated
//     time. - Time : %s".
//   script/ui/game2/attendancereward/ui_attendance_event_wnd.txt + ui_attendance_alarm.txt, imagetable AttendanceReward
//     (9 normal cell, 10 claimable, 11 completed, 12 kill / 13 quest / 14 connection mission icon, 15 not opened, 16..18 alarm).
//
// ASSUMPTIONS (documented in the gate evidence):
//   * Type 1 = connection time (the same Type id and the same 1800 as connectreward.csv Type 1 "Connection Time Reward";
//     2310:1001 is its mission text, imagetable 14 "connection" its icon): the day's mission = Value1_1 seconds connected on
//     that calendar day (value1_2 equals Value1_1 in every row). Other types are not in the data and are never completable.
//   * Dates/times are CEST (UTC+2), the only zone the client strings name (5000:12); the board day changes at 00:00
//     (StartTime 0 .. EndTime 2359).
//   * Account-wide (2300:24/25): the board progress, the one-claim-per-day rule and the day's connection time belong to the
//     account (only one character of an account is online at a time), stored in the account features next to shared storage.
//   * Reward Size (150) and Process Func (0) have no client meaning that the data explains; they are not used.
export const ATTEND_SCRIPT = 'game2/attendancereward/ui_attendance_event_wnd.txt';
export const ATTEND_ALARM_SCRIPT = 'game2/attendancereward/ui_attendance_alarm.txt';
export const ATTEND_CATE = 2300;
export const MISSION_CATE = 2310;
export const TYPE_CONNECTION = 1;
/** imagetable AttendanceReward cell images and the mission icon of each known Type. */
export const CELL_IMAGE = { normal: 9, ready: 10, done: 11, locked: 15 };
export const TYPE_ICON = { [TYPE_CONNECTION]: 14 };
/** cate 2310 mission text of each known Type. */
export const TYPE_TEXT = { [TYPE_CONNECTION]: 1001 };
export const CEST_OFFSET_MS = 2 * 3600 * 1000;

const int = v => (Number.isSafeInteger(v) ? v : Number.isFinite(Number(v)) ? Math.trunc(Number(v)) : 0);
/** CEST calendar date (YYYYMMDD) and time (HHMM) of an epoch ms. */
export function cestClock(now) {
  const d = new Date(Number(now) + CEST_OFFSET_MS);
  return { date: d.getUTCFullYear() * 10000 + (d.getUTCMonth() + 1) * 100 + d.getUTCDate(), hhmm: d.getUTCHours() * 100 + d.getUTCMinutes() };
}
/** Tables from boxes.json attendance ({sets, days}) or the two raw CSV texts ({setCsv, listCsv}). */
export function attendanceTables(source) {
  if (source && typeof source.setCsv === 'string') return parseAttendanceCsv(source.setCsv, source.listCsv);
  const sets = (source?.sets || []).filter(s => s && Number.isInteger(s.index)).map(s => ({ index: s.index, start: int(s.start), end: int(s.end), startTime: int(s.startTime), endTime: int(s.endTime), enable: int(s.enable), count: int(s.count), group: int(s.group) }));
  const days = (source?.days || []).filter(d => d && Number.isInteger(d.group) && Number.isInteger(d.no)).map(d => ({ group: d.group, no: d.no, type: int(d.type), value1: int(d.value?.[0]), value2: int(d.value?.[1]), item: int(d.item), count: int(d.count) }));
  return { sets, days };
}
/** Independent parse of attend_set.csv + attend_list.csv. */
export function parseAttendanceCsv(setCsv, listCsv) {
  const rows = t => String(t || '').split(/\r?\n/).slice(1).map(l => l.split(',').map(s => s.trim())).filter(c => /^\d+$/.test(c[0] || ''));
  const sets = rows(setCsv).map(c => ({ index: int(c[0]), start: int(c[1]), end: int(c[2]), startTime: int(c[3]), endTime: int(c[4]), enable: int(c[5]), count: int(c[6]), group: int(c[7]) }));
  const days = rows(listCsv).map(c => ({ group: int(c[0]), no: int(c[1]), type: int(c[2]), value1: int(c[3]), value2: int(c[4]), item: int(c[5]), count: int(c[6]) }));
  return { sets, days };
}
/** The enabled event whose dates and daily hours contain now (CEST), or null. */
export function activeSet(tables, now) {
  const { date, hhmm } = cestClock(now);
  return tables.sets.find(s => s.enable === 1 && date >= s.start && date <= s.end && hhmm >= s.startTime && hhmm <= s.endTime) || null;
}
/** The board of an event: its group's days No 1..Count in order. */
export function boardDays(tables, set) {
  if (!set) return [];
  return tables.days.filter(d => d.group === set.group && d.no >= 1 && d.no <= set.count).sort((a, b) => a.no - b.no);
}

// ------------------------------------------------------------------------------------------ state
/** Account state (accountFeatures.attendance): {date, seconds (connected on that CEST date), sets: {index: {claimed, lastDate}}}. */
export function normalizeState(raw, now) {
  const { date } = cestClock(now);
  const sets = {};
  for (const [k, v] of Object.entries(raw?.sets || {})) if (/^\d+$/.test(k) && v && typeof v === 'object') sets[k] = { claimed: Math.max(0, int(v.claimed)), lastDate: Math.max(0, int(v.lastDate)) };
  return { date, seconds: raw?.date === date ? Math.max(0, int(raw.seconds)) : 0, sets };
}
export const setProgress = (st, set) => st.sets[String(set.index)] || { claimed: 0, lastDate: 0 };
/** Is the day's mission complete? (Type 1: connected seconds of today >= Value1_1.) */
export function missionDone(day, st) { return day.type === TYPE_CONNECTION && day.value1 > 0 && st.seconds >= day.value1; }
/** Seconds still needed for today's mission (Type 1), or null for an unknown type. */
export function missionRemaining(day, st) { return day.type === TYPE_CONNECTION ? Math.max(0, day.value1 - st.seconds) : null; }
/**
 * The board cells: {day, status} with status 'done' (claimed), 'ready' (today's cell, mission complete), 'today' (today's
 * cell, mission running), 'locked' (a later day, or the next cell after today's claim: the board updates daily).
 */
export function boardView(tables, st, now) {
  const set = activeSet(tables, now);
  if (!set) return { set: null, cells: [] };
  const prog = setProgress(st, set), today = cestClock(now).date;
  const cells = boardDays(tables, set).map(day => {
    if (day.no <= prog.claimed) return { day, status: 'done' };
    if (day.no === prog.claimed + 1 && prog.lastDate !== today) return { day, status: missionDone(day, st) ? 'ready' : 'today' };
    return { day, status: 'locked' };
  });
  return { set, cells };
}
/** Add connected seconds while an event runs (capped at the largest Type 1 value of the board). Returns true on change. */
export function addSeconds(tables, st, now, seconds) {
  const set = activeSet(tables, now);
  if (!set) return false;
  const cap = Math.max(0, ...boardDays(tables, set).filter(d => d.type === TYPE_CONNECTION).map(d => d.value1));
  const next = Math.min(cap, st.seconds + Math.max(0, Math.floor(seconds)));
  if (next === st.seconds) return false;
  st.seconds = next; return true;
}
/** Validate a claim of day `no` of event `setIndex`. Returns {ok, error (REWARD_MESSAGES key), set, day}. */
export function checkClaim(tables, st, now, setIndex, no, { hasItem = () => true } = {}) {
  const set = activeSet(tables, now);
  if (!set || set.index !== setIndex) return { ok: false, error: 'waitPeriod' };
  const prog = setProgress(st, set), today = cestClock(now).date, day = boardDays(tables, set).find(d => d.no === no);
  // "Each reward can only be claimed once per account" / "Only one character can claim a reward per day" -> 2300:17
  if (!day || no <= prog.claimed || prog.lastDate === today) return { ok: false, error: 'already' };
  if (no !== prog.claimed + 1 || !missionDone(day, st)) return { ok: false, error: 'notDone' };
  if (!day.item || !hasItem(day.item) || !(day.count > 0)) return { ok: false, error: 'noItem' };
  return { ok: true, set, day };
}
export function markClaimed(st, set, now) {
  const prog = setProgress(st, set);
  st.sets = { ...st.sets, [String(set.index)]: { claimed: prog.claimed + 1, lastDate: cestClock(now).date } };
  return st;
}
