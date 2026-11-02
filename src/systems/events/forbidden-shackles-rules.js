// Forbidden Shackles (Fetters) floor table helpers.
// Data: share/forbiddenshackles/forbiddenshacklesdata.csv -> dungeons.json forbiddenShackles.
// Consumed by FettersRun in staged.js (map 260). No invented schedules or packets.

const num = (v, d = 0) => { const x = Number(v); return Number.isFinite(x) ? x : d; };

/** Normalize one Floor/ResetCost/ClearExp row. */
export function shacklesFloorRow(raw) {
  if (!raw || typeof raw !== 'object') return null;
  const floor = num(raw.floor ?? raw.Floor);
  if (!floor) return null;
  return {
    floor,
    resetCost: num(raw.resetCost ?? raw.ResetCost),
    clearExp: num(raw.clearExp ?? raw.ClearExp),
  };
}

/** Expand an array of floor rows (dungeons.json or CSV-shaped objects). */
export function normalizeShacklesFloors(source) {
  if (!source) return [];
  if (Array.isArray(source)) return source.map(shacklesFloorRow).filter(Boolean);
  if (Array.isArray(source.rows) && Array.isArray(source.fields)) {
    const fields = source.fields;
    return source.rows.map((row) => {
      const obj = {};
      for (let i = 0; i < fields.length; i++) obj[fields[i]] = row[i];
      return shacklesFloorRow(obj);
    }).filter(Boolean);
  }
  return [];
}

/** Lookup by floor number (1-based). */
export function shacklesFloor(table, floor) {
  const list = normalizeShacklesFloors(table);
  const f = num(floor);
  return list.find((r) => r.floor === f) || null;
}

/** Map index used by Forbidden Shackles / Fetters (events data + staged.js). */
export const FORBIDDEN_SHACKLES_MAP = 260;

/** Coverage note for EVENTS-MODES-COVERAGE.md. */
export const FORBIDDEN_SHACKLES_NOTE = Object.freeze({
  map: FORBIDDEN_SHACKLES_MAP,
  host: 'FettersRun in src/systems/events/staged.js (no dedicated server/world/forbiddenshackles.mjs)',
  data: 'share/forbiddenshackles/forbiddenshacklesdata.csv',
  floors: '1..20 ResetCost/ClearExp',
});
