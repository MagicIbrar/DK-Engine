// Pending character-deletion countdown (Global client char-select).
// Evidence (decompile 32-bit-main decompiled.c):
//   FUN_00a5b180 writes per-slot __time64 delete-at from the server packet (param_4) — client does not hardcode delay.
//   FUN_00a5b650 / list refresh: if now >= delete-at -> loginmsg 30:124 (green "Deletion in Progress");
//     else FUN_00a5dc10 remain-seconds + FUN_00a5d2e0 format + loginmsg 30:123 with %s.
//   FUN_00a5d2e0: days = sec/86400, hours = (sec/3600)%24, mins = (sec/60)%60;
//     append Day(s)/Hour(s); Minute(s) only when days==0 (stringtable_system cate 101 codes 17/18/19 = 0x650011..13).
//   ui_charselectwnd: lbl_character_del_N, btn_delete_cancel (30:125), btn_delete_char_confirm (30:126).
//   Actions FUN_00a5d040: 4=confirm finalize, 5=cancel pending.
// Delay duration: UNRESOLVED (older SessionServer sp_char_delete immediate; Hangame policy 10-day is post-delete
// support recovery, not the in-client countdown — https://secure.dekaron.hangame.com/Support/Policy?type=operation).
// This module only formats/displays when a character already carries pendingDeleteAt from the host.

/** @param {unknown} value absolute delete-at (unix seconds or ms, or Date) */
export function pendingDeleteAtMs(value) {
  if (value == null || value === '' || value === 0 || value === false) return null;
  if (value instanceof Date) {
    const t = value.getTime();
    return Number.isFinite(t) && t > 0 ? t : null;
  }
  const n = Number(value);
  if (!Number.isFinite(n) || n <= 0) return null;
  // Heuristic: values below year ~2001 in ms are treated as seconds.
  return n < 1e12 ? Math.trunc(n * 1000) : Math.trunc(n);
}

/** @param {{ pendingDeleteAt?: unknown, deleteAt?: unknown, pending_delete_at?: unknown } | null | undefined} ch */
export function characterPendingDeleteAtMs(ch) {
  if (!ch || typeof ch !== 'object') return null;
  return pendingDeleteAtMs(ch.pendingDeleteAt ?? ch.deleteAt ?? ch.pending_delete_at);
}

export function isCharacterPendingDelete(ch, nowMs = Date.now()) {
  const at = characterPendingDeleteAtMs(ch);
  return at != null && Number.isFinite(nowMs);
}

export function isPendingDeleteExpired(ch, nowMs = Date.now()) {
  const at = characterPendingDeleteAtMs(ch);
  return at != null && nowMs >= at;
}

/** Remain seconds until delete-at (0 when expired/missing). Matches FUN_00a5dc10 + time64 compare. */
export function pendingRemainSeconds(ch, nowMs = Date.now()) {
  const at = characterPendingDeleteAtMs(ch);
  if (at == null) return 0;
  return Math.max(0, Math.floor((at - nowMs) / 1000));
}

/**
 * Format remain seconds like FUN_00a5d2e0.
 * @param {number} remainSec
 * @param {{ day?: string, hour?: string, minute?: string }} [units]
 */
export function formatPendingRemain(remainSec, units = {}) {
  const sec = Math.max(0, Math.floor(Number(remainSec) || 0));
  if (sec <= 0) return '';
  const dayU = units.day ?? 'Day(s)';
  const hourU = units.hour ?? 'Hour(s)';
  const minU = units.minute ?? 'Minute(s)';
  const days = Math.floor(sec / 86400);
  const hours = Math.floor(sec / 3600) % 24;
  const mins = Math.floor(sec / 60) % 60;
  const parts = [];
  if (days) parts.push(`${days}${dayU}`);
  if (hours) parts.push(`${hours}${hourU}`);
  if (mins && !days) parts.push(`${mins}${minU}`);
  // Native concatenates number+unit with a thin separator between groups (DAT_01ab24fc / 01ab2508).
  return parts.join(' ');
}

/**
 * Build lbl_character_del text from loginmsg templates.
 * 30:123 uses %s for remain; lone `\` in the table is a line break (multiline label).
 * @param {(cate:number, code:number, fallback?:string)=>string} raw
 */
export function pendingDeleteLabelText(ch, raw, nowMs = Date.now(), units) {
  const at = characterPendingDeleteAtMs(ch);
  if (at == null) return '';
  const remain = pendingRemainSeconds(ch, nowMs);
  const breakLines = (s) => String(s ?? '').replace(/\\n/g, '\n').replace(/\\/g, '\n');
  if (remain <= 0) return breakLines(raw(30, 124, '<color=00ff00>Deletion</color>\n<color=00ff00>in Progress</color>'));
  const remainText = formatPendingRemain(remain, units);
  const tmpl = raw(30, 123, '<color=ff0000>Deletion</color>\n<color=ff0000>in progress</color>\n%s');
  return breakLines(tmpl).replace(/%s/g, remainText);
}

export const PENDING_DELETE_STRINGS = Object.freeze({
  inProgress: { cate: 30, code: 123 },
  expired: { cate: 30, code: 124 },
  cancel: { cate: 30, code: 125 },
  confirm: { cate: 30, code: 126 },
  units: { cate: 101, codes: { day: 17, hour: 18, minute: 19, second: 20 } },
});