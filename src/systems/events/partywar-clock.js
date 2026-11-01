// Native schedule/config offsets on the common fixed UTC+1 server calendar.
import {serverDate,serverTimestamp} from '../../game/server-time.js';
export function partyWarWindow(table, now, { upcoming = false } = {}) {
  const cfg = table?.config, date = serverDate(now);
  if (!cfg || !Number.isFinite(now) ||
      !['RecordTime', 'RecordEndTime', 'ChooseTime', 'WaitTime'].every(k => Number.isFinite(cfg[k])) ||
      cfg.RecordEndTime < cfg.RecordTime || cfg.ChooseTime < cfg.RecordEndTime || cfg.WaitTime <= 0) return null;
  const windows = [];
  for (const day of [-1, 0, 1, 2]) for (const row of table.schedule || []) {
    const match = /^(\d{1,2}):(\d{2})$/.exec(row.cycleStart || '');
    if (!match || +match[1] > 23 || +match[2] > 59) continue;
    const cycle = serverTimestamp(date.getUTCFullYear(), date.getUTCMonth(), date.getUTCDate() + day, +match[1], +match[2]);
    const register = cycle + cfg.RecordTime * 1000, closed = cycle + cfg.RecordEndTime * 1000;
    const enter = cycle + cfg.ChooseTime * 1000, end = enter + cfg.WaitTime * 1000;
    if (now < end && (upcoming || now >= register)) windows.push({ cycle, register, closed, enter, end,
      phase: now < register ? 'waiting' : now < closed ? 'register' : now < enter ? 'selection' : 'enter' });
  }
  return windows.sort((a, b) => a.register - b.register)[0] || null;
}

// Original lobby strings differ from the seven in-instance phase strings.
export function partyWarLobbyTimer(mode, window, now) {
  if (!window || ![window.register, window.closed, window.enter, window.end].every(Number.isFinite) || now >= window.end) return null;
  const phase = now < window.register ? 'waiting' : now < window.closed ? 'register' : now < window.enter ? 'selection' : 'enter';
  return { mode, cycle: window.cycle, phase,
    until: phase === 'waiting' ? window.register : phase === 'register' ? window.closed : phase === 'selection' ? window.enter : window.end,
    cate: phase === 'waiting' || phase === 'register' ? 100 : 200,
    code: phase === 'waiting' ? 11 : phase === 'register' ? 12 : 103 };
}
