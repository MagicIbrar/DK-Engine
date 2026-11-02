// Map-event catalog from Global data/script/eventinfo/mapevent.csv
// (life.events.mapEvent + events.modes.mapEvent).
// Native evidence (decompile/dekaron64/decompiled.c, read-only):
//   FUN_7ff6708a9350 loads eventinfo\\MapEvent.csv keyed by script index; skips index==0;
//   accepts eventType only when (eventType-1) < 100 (i.e. 1..100); stores time/id/monster + param strings.
//   FUN_7ff6708a1010 is the eventType factory (same 7ff6708a* module): creates typed action objects.
//   eventType 100 hits factory default and returns null (noop / marker).
//   events.modes.eventInfo.enable === false (info.csv title enable false) — UI jump list present but disabled.
// Lane 64: Execute/tick methods of every action class are recovered (Global x64 client, lanes 49/64) and run in
// map-event-runner.js. This module stays the catalog + due-row planner.

const num = (v, d = 0) => { const x = Number(v); return Number.isFinite(x) ? x : d; };

/** Known eventType values present in Global mapevent.csv. */
export const MAP_EVENT_TYPES = Object.freeze([1, 2, 5, 6, 7, 9, 10, 11, 12, 100]);

/** Script indices present in mapevent.csv (0..5). Native loader skips index 0. */
export const MAP_EVENT_INDICES = Object.freeze([0, 1, 2, 3, 4, 5]);

/**
 * Native factory FUN_7ff6708a1010(eventType) — object sizes / vtables from decomp.
 * role = Global action class (Ghost::GameHandler::Dungeon::Event::*, Init/Execute in map-event-runner.js). type 100 => null.
 */
export const MAP_EVENT_FACTORY = Object.freeze({
  1: Object.freeze({ size: 0x100, ctor: 'FUN_7ff6708bebf0', vtable: 'DAT_7ff671dff820', role: 'Enter' }),
  2: Object.freeze({ size: 0x90, ctor: 'inline', vtable: 'DAT_7ff671dff628', role: 'Move' }),
  5: Object.freeze({ size: 0x30, ctor: 'inline', vtable: 'DAT_7ff671dfe818', role: 'SetAction', sharedWith: 9 }),
  6: Object.freeze({ size: 0x28, ctor: 'inline', vtable: 'DAT_7ff671dff390', role: 'Talk' }),
  7: Object.freeze({ size: 0x130, ctor: 'FUN_7ff6708a1410', vtable: 'DAT_7ff671dff5e8', role: 'SetCamera' }),
  9: Object.freeze({ size: 0x30, ctor: 'inline', vtable: 'DAT_7ff671dfe818', role: 'Leave', sharedWith: 5 }),
  10: Object.freeze({ size: 0x50, ctor: 'inline', vtable: 'DAT_7ff671dff468', role: 'FadeInOut' }),
  11: Object.freeze({ size: 0x38, ctor: 'inline', vtable: 'DAT_7ff671dff4e8', role: 'ShowAllUI' }),
  12: Object.freeze({ size: 0x30, ctor: 'inline', vtable: 'DAT_7ff671dff568', role: 'BrickAction' }),
  100: Object.freeze({ size: 0, ctor: null, vtable: null, role: 'noop-factory-default' }),
});

/** events.modes.eventInfo from Global prepared data. */
export const MAP_EVENT_INFO = Object.freeze({
  file: 'script/eventinfo/info.csv',
  enable: false,
  jumps: Object.freeze([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]),
  note: 'Global eventInfo.enable is false — no authored UI surface for mapEvent jumps',
});

/** Normalize one life.events.mapEvent / CSV / modes.mapEvent row (full param columns). */
export function mapEventRow(raw) {
  if (!raw || typeof raw !== 'object') return null;
  const eventType = num(raw.eventType ?? raw.EventType ?? raw.eventtype);
  const row = {
    index: num(raw.index ?? raw.Index),
    time: num(raw.time ?? raw.Time),
    eventType,
    id: num(raw.id ?? raw.ID ?? raw.Id),
    monster: num(raw.monster ?? raw.MonsterIndex ?? raw.monsterindex),
    p1: raw.p1 ?? raw.param1 ?? raw.Param1 ?? 0,
    p2: raw.p2 ?? raw.param2 ?? raw.Param2 ?? 0,
    p3: raw.p3 ?? raw.param3 ?? raw.Param3 ?? 0,
    p4: raw.p4 ?? raw.param4 ?? raw.Param4 ?? 0,
    p5: raw.p5 ?? raw.param5 ?? raw.Param5 ?? 0,
    p6: raw.p6 ?? raw.param6 ?? raw.Param6 ?? 0,
    p7: raw.p7 ?? raw.param7 ?? raw.Param7 ?? 0,
    p8: raw.p8 ?? raw.param8 ?? raw.Param8 ?? 0,
    p9: raw.p9 ?? raw.param9 ?? raw.Param9 ?? 0,
  };
  row.factory = MAP_EVENT_FACTORY[eventType] || null;
  row.loadable = row.index !== 0 && eventType >= 1 && eventType <= 100;
  row.actionable = !!(row.factory && row.factory.ctor !== null && row.factory.role !== 'noop-factory-default');
  return row;
}

/** Expand events.modes.mapEvent {fields,rows} or an object-row array into object rows. */
export function normalizeMapEventRows(source) {
  if (!source) return [];
  if (Array.isArray(source)) return source.map(mapEventRow).filter(Boolean);
  if (Array.isArray(source.rows) && Array.isArray(source.fields)) {
    const fields = source.fields;
    return source.rows.map((row) => {
      const obj = {};
      for (let i = 0; i < fields.length; i++) obj[fields[i]] = row[i];
      return mapEventRow(obj);
    }).filter(Boolean);
  }
  return [];
}

/** Rows the native loader would keep (index != 0, eventType 1..100). */
export function loadableMapEventRows(source) {
  return normalizeMapEventRows(source).filter((r) => r.loadable);
}

/** Group rows by script index. */
export function mapEventsByIndex(rows) {
  const list = normalizeMapEventRows(rows);
  const by = new Map();
  for (const r of list) {
    if (!by.has(r.index)) by.set(r.index, []);
    by.get(r.index).push(r);
  }
  return by;
}

/**
 * Catalog-only schedule: rows of one script index whose time <= elapsedMs, in CSV order.
 * Does not execute actions (the runner is map-event-runner.js). Lane 64: row.time is milliseconds after
 * Start (Global fireAt = Time::Provider slot 0x58 + time), not seconds.
 */
export function mapEventDueRows(source, index, elapsedMs) {
  const list = (mapEventsByIndex(source).get(Number(index)) || []).filter((r) => r.loadable);
  const t = Number(elapsedMs);
  if (!Number.isFinite(t)) return [];
  return list.filter((r) => r.time <= t);
}

/** Coverage summary for tests / EVENTS-MODES-COVERAGE.md. */
export function mapEventCoverage(rows) {
  const all = normalizeMapEventRows(rows);
  const loadable = all.filter((r) => r.loadable);
  const by = mapEventsByIndex(all);
  const types = new Set();
  for (const r of all) types.add(r.eventType);
  const factoryTypes = Object.keys(MAP_EVENT_FACTORY).map(Number).sort((a, b) => a - b);
  return {
    indices: [...by.keys()].sort((a, b) => a - b),
    rowCount: all.length,
    loadableCount: loadable.length,
    skippedIndex0: all.filter((r) => r.index === 0).length,
    eventTypes: [...types].sort((a, b) => a - b),
    factoryTypes,
    eventInfoEnable: MAP_EVENT_INFO.enable,
    execution: 'RUNNER', // Lane 64: proven Global runner (Ghost::GameHandler::Dungeon::Reference) in map-event-runner.js
    runner: 'src/systems/events/map-event-runner.js (Global Ghost::GameHandler::Dungeon::Reference)',
    note: 'Catalog only. Real factory FUN_7ff6714e39f0 (not FUN_7ff6708a1010); Execute semantics recovered in map-event-runner.js (lanes 49/64); indices 1-5 = map 706 (MAP_EVENT_BINDING); eventInfo.enable=false',
  };
}

/**
 * Lane 64: which map plays mapevent.csv indices 1..5. Source: Global data: script/string/normal/stringtable_event.txt cate 3000 (Talk codes 1-6, Aloken guard lines), share/creature/monster_aggro.csv 9293 = Castotica, share/dungeonlist.csv "Hidden Mansion of Kastotica" = 706.
 * Index 1 BrickAction 101 + Talk 1/2, index 2 (9294/9295) Talk 3/4, index 3 (9293 Castotica) Talk 5/6, index 4 Castotica Move,
 * index 5 (9421). The Hard (722) and Solo (265) variants have no Global evidence of their own, so they are not bound.
 */
export const MAP_EVENT_BINDING = Object.freeze({ map: 706, dungeon: 'Hidden Mansion of Kastotica', indices: Object.freeze([1, 2, 3, 4, 5]),
  source: 'Global data: script/string/normal/stringtable_event.txt cate 3000 (Talk codes 1-6, Aloken guard lines), share/creature/monster_aggro.csv 9293 = Castotica, share/dungeonlist.csv "Hidden Mansion of Kastotica" = 706' });

/** Lane 64: every former gap with the value used and its source (owner: nothing stays open). */
export const MAP_EVENT_DECISIONS = Object.freeze([
  'Index->map: indices 1-5 play in map 706 Hidden Mansion of Kastotica (source: Global data: script/string/normal/stringtable_event.txt cate 3000 (Talk codes 1-6, Aloken guard lines), share/creature/monster_aggro.csv 9293 = Castotica, share/dungeonlist.csv "Hidden Mansion of Kastotica" = 706). The earlier map 38 / brick 101 lead is dropped (older server reference brick UID 101 is a coincidence; index 1 is the Kastotica guard scene).',
  'Index->trigger moment inside 706: no Global, decompile, older-server or online source says which room/kill fires which index, so no automatic host trigger is wired (removed). The GM path (/gm mapevent <map> 1..5) stays.',
  'UI jump surface: Global info.csv eventInfo.enable=false, so no map-event jump UI is shown (source: Global data).',
  'Skip 0x05260022: the Global client only ends from the server side via 0x05260023, so the 4.2.0 host answers skip with the 0x23 end for that player (source: Global client).',
  'SetCamera f0/f1/f2 = distance/pitch/yaw, the same 1:1 mapping 4.2.0 uses for Global maplist DefaultZoom/Default_V_Angle/Default_H_Angle (source: Global client clamp/wrap + Global maplist). CameraImpl+0x10d is carried as data only; it has no 4.2.0 effect (removed).',
]);
/** Kept for old imports: nothing is left open. */
export const MAP_EVENT_UNRESOLVED = Object.freeze([]);
