// Native notices define server time as Central European Time (UTC+1).
// Use a fixed offset: host timezone and daylight-saving changes must not move events.
export const SERVER_TIME_OFFSET_MINUTES = 60;
export const SERVER_TIME = Object.freeze({ name: 'UTC+1', offsetMinutes: SERVER_TIME_OFFSET_MINUTES });
const OFFSET_MS = SERVER_TIME_OFFSET_MINUTES * 60_000;

/** A shifted Date for UTC getters only (never local Date getters). */
export function serverDate(now = Date.now()) {
  return new Date(Number(now) + OFFSET_MS);
}

/** Convert server calendar components back to a real UTC epoch. Month is zero-based. */
export function serverTimestamp(year, month, day, hour = 0, minute = 0, second = 0, ms = 0) {
  return Date.UTC(year, month, day, hour, minute, second, ms) - OFFSET_MS;
}

export function serverDayKey(now = Date.now()) {
  return serverDate(now).toISOString().slice(0, 10);
}
