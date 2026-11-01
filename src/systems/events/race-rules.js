// Server Whole Competition (Race) rules shared by the host (server/world/race.mjs), the client windows
// (src/systems/network/race.js) and tools/test-event-modes.mjs. Data: share/race/list.csv + playtime.csv as parsed into
// gamedata/events.json modes.race; the values the data leaves open are src/config/engine-chosen-event-modes.js RACE_CHOSEN.
import { RACE_CHOSEN as C } from '../../config/engine-chosen-event-modes.js';
import {serverDate,serverTimestamp} from '../../game/server-time.js';

const num = v => Number(v) || 0;
// list.csv Description of each WorldIndex (Korean 헬리온 / 아크 / 리케츠) = the server names the same battle uses in English:
// stringtable_dksquare 160|631 "Helion server won", 160|632 "Arc server won", 160|638 "Riketz Won!".
export const RACE_SERVERS = Object.freeze({ 1: 'Helion', 10: 'Arc', 20: 'Riketz' });

/** list.csv rows this host plays (WorldIndex C.worldIndex), in Index order, as plain records. */
export function raceRows(list = [], worldIndex = C.worldIndex) {
  return list.filter(r => num(r.WorldIndex) === worldIndex).sort((a, b) => num(a.Index) - num(b.Index)).map(r => {
    const brackets = [];
    for (let k = 1; r[`MinCount${k}`] != null; k++) brackets.push({ min: num(r[`MinCount${k}`]), max: num(r[`MaxCount${k}`]), x: num(r[`PosX${k}`]), z: num(r[`PosY${k}`]) });
    return { index: num(r.Index), map: num(r.MapIndex), worldIndex: num(r.WorldIndex), server: RACE_SERVERS[num(r.WorldIndex)] || String(num(r.WorldIndex)), minLevel: num(r.MinLevel), maxLevel: num(r.MaxLevel), limit: num(r.LimitedCount), wait: { x: num(r.DefaultPosX), z: num(r.DefaultPosY) }, brackets };
  });
}

/** playtime.csv row -> schedule (DayOfWeek 0 = Sunday, fixed UTC+1). */
export function raceSchedule(playtime = []) {
  const r = playtime[0]; if (!r) return null;
  return { day: num(r.DayOfWeek), waitHour: num(r.WaitingHour), waitMinute: num(r.WaitingMinute), startHour: num(r.StartHour), endHour: num(r.EndHour) };
}

/** This week's server window around `nowMs`: {phase:'closed'|'entry'|'race', entryAt, startAt, endAt, nextEntryAt}. */
export function racePhase(schedule, nowMs) {
  if (!schedule) return { phase: 'closed', entryAt: null, startAt: null, endAt: null, nextEntryAt: null };
  const now = serverDate(nowMs);
  const at = (dayOffset, h, m = 0) => serverTimestamp(now.getUTCFullYear(), now.getUTCMonth(), now.getUTCDate() + dayOffset, h, m);
  const delta = schedule.day - now.getUTCDay();
  const win = off => ({ entryAt: at(off, schedule.waitHour, schedule.waitMinute), startAt: at(off, schedule.startHour), endAt: at(off, schedule.endHour) });
  let w = win(delta);
  if (nowMs >= w.endAt) w = win(delta + 7);
  else if (delta > 0 && nowMs < w.entryAt) { const prev = win(delta - 7); if (nowMs < prev.endAt) w = prev; }
  const phase = nowMs >= w.startAt && nowMs < w.endAt ? 'race' : nowMs >= w.entryAt && nowMs < w.startAt ? 'entry' : 'closed';
  return { phase, ...w, nextEntryAt: phase === 'closed' ? w.entryAt : null };
}

/** The band (row) of a character level, or null. */
export function raceBand(rows, level) { const l = num(level); return rows.find(r => l >= r.minLevel && l <= r.maxLevel) || null; }

/** Start cell of the n-th entrant (1-based entry order): the first bracket holding n, else the waiting point. */
export function raceSpawn(row, n) { const b = row.brackets.find(k => n >= k.min && n <= k.max); return b ? { x: b.x, z: b.z, bracket: row.brackets.indexOf(b) + 1 } : { ...row.wait, bracket: 0 }; }

/** Ranking: kills high to low, then fewer deaths, then the earlier last kill, then name. Adds rank 1.. */
export function raceRanking(stats) {
  return [...stats].sort((a, b) => b.kills - a.kills || a.deaths - b.deaths || (a.lastKillAt ?? Infinity) - (b.lastKillAt ?? Infinity) || String(a.name).localeCompare(String(b.name)))
    .map((s, i) => ({ ...s, rank: i + 1 }));
}

/** Status text of a band row for the list window. */
export function raceStatus(phase, count, limit) { if (phase === 'closed') return C.status.closed; if (count >= limit) return C.status.full; return phase === 'race' ? C.status.race : C.status.entry; }
