// Field Boss rules from Global share/fieldboss (events.modes.fieldBoss) and
// dungeons.json fieldBosses / fieldBossSummons. Consumed by server/world/field-boss.mjs
// and the client FieldBossRun (src/systems/events/fieldboss.js).
// Evidence: share/fieldboss/config.csv + summonsmonster.csv; gamedata/events.json modes.fieldBoss;
// gamedata/dungeons.json fieldBosses/fieldBossSummons; client FieldBossRun map-string codes.
// Day column uses the same 0=Sunday..6=Saturday convention as share/race/playtime.csv (UTC+1).
import { serverDate, serverTimestamp } from '../../game/server-time.js';

const num = (v, d = 0) => { const x = Number(v); return Number.isFinite(x) ? x : d; };

/** Prefer dungeons.json fieldBosses[0]; fall back to events.modes.fieldBoss.config[0]. */
export function fieldBossConfig(eventModes, dungeonFieldBosses) {
  const fromDg = Array.isArray(dungeonFieldBosses) ? dungeonFieldBosses[0] : null;
  if (fromDg && Number.isFinite(Number(fromDg.map))) {
    return {
      day: num(fromDg.day, 6),
      startHour: num(fromDg.start?.[0], 23),
      startMin: num(fromDg.start?.[1], 0),
      endHour: num(fromDg.end?.[0], 23),
      endMin: num(fromDg.end?.[1], 20),
      notices: Array.isArray(fromDg.notices) ? fromDg.notices.map(Number) : [],
      map: num(fromDg.map, 533),
      x: num(fromDg.x, 53),
      y: num(fromDg.y, 57),
      dir: num(fromDg.dir, 260),
      monster: num(fromDg.monster, 9490),
      slaves: (fromDg.slaves || []).map(Number).filter((n) => n > 0),
      source: 'dungeons.json fieldBosses',
    };
  }
  const row = eventModes?.fieldBoss?.config?.[0];
  if (!row) return null;
  const slaves = [row.Slave_1, row.Slave_2, row.Slave_3, row.Slave_4, row.Slave_5].map(Number).filter((n) => n > 0);
  return {
    day: num(row.Day, 6),
    startHour: num(row.StartHour, 23),
    startMin: num(row.StartMin, 0),
    endHour: num(row.EndHour, 23),
    endMin: num(row.EndMin, 20),
    notices: [row.Noty_1, row.Noty_2, row.Noty_3, row.Noty_4, row.Noty_5].map(Number).filter((n) => n > 0),
    map: num(row.MapIndex, 533),
    x: num(row.Start_X, 53),
    y: num(row.Start_Y, 57),
    dir: num(row.Direction, 260),
    monster: num(row.MonsterIndex, 9490),
    slaves,
    source: 'events.modes.fieldBoss.config',
  };
}

/** Summons for the live boss group. Client FieldBossRun filters group === 1 (slaves of monster 9490). */
export function fieldBossSummons(eventModes, dungeonSummons, group = 1) {
  const fromDg = Array.isArray(dungeonSummons) ? dungeonSummons : null;
  if (fromDg?.length) {
    return fromDg.filter((r) => num(r.group) === group).map((r) => ({
      group: num(r.group),
      no: num(r.no),
      monster: num(r.monster),
      tickMs: num(r.tickMs, 15000),
      range: Array.isArray(r.range) ? [num(r.range[0], 5), num(r.range[1], 48)] : [5, 48],
      maxLimit: num(r.maxLimit, 50),
      callMax: num(r.callMax, 50),
      count: Array.isArray(r.count) ? [num(r.count[0], 1), num(r.count[1], 1)] : [1, 1],
      source: 'dungeons.json fieldBossSummons',
    }));
  }
  const rows = eventModes?.fieldBoss?.summons || [];
  return rows.filter((r) => num(r.Index) === group).map((r) => ({
    group: num(r.Index),
    no: num(r.No),
    monster: num(r.MonsterIndex),
    tickMs: num(r.dwTick, 15000),
    range: [num(r.dwMinRange, 5), num(r.dwMaxRange, 48)],
    maxLimit: num(r.dwMaxLimit, 50),
    callMax: num(r.CallMax, 50),
    count: [num(r.dwMin, 1), num(r.dwMax, 1)],
    source: 'events.modes.fieldBoss.summons',
  }));
}

/** This week's Saturday window around nowMs using config Day (0=Sun). */
export function fieldBossWindow(cfg, nowMs) {
  if (!cfg) return { phase: 'closed', startAt: null, endAt: null, nextStartAt: null };
  const now = serverDate(nowMs);
  const at = (dayOffset, h, m = 0) => serverTimestamp(now.getUTCFullYear(), now.getUTCMonth(), now.getUTCDate() + dayOffset, h, m);
  const delta = cfg.day - now.getUTCDay();
  const win = (off) => ({ startAt: at(off, cfg.startHour, cfg.startMin), endAt: at(off, cfg.endHour, cfg.endMin) });
  let w = win(delta);
  if (nowMs >= w.endAt) w = win(delta + 7);
  else if (delta > 0 && nowMs < w.startAt) {
    const prev = win(delta - 7);
    if (nowMs < prev.endAt) w = prev;
  }
  const phase = nowMs >= w.startAt && nowMs < w.endAt ? 'active' : 'closed';
  return { phase, ...w, nextStartAt: phase === 'closed' ? w.startAt : null };
}

/** Duration of the fight window in seconds from config start/end. */
export function fieldBossDurationSec(cfg) {
  if (!cfg) return 0;
  return Math.max(60, ((cfg.endHour * 60 + cfg.endMin) - (cfg.startHour * 60 + cfg.startMin)) * 60);
}

/** Map-string codes used by client FieldBossRun (stringtable_dungeon_06 #533). */
export const FIELD_BOSS_MAP_STRINGS = Object.freeze({
  fiveMin: 120,
  start: 101,
  energy80: 111,
  energy85: 112,
  energy90: 113,
  energy95: 114,
  timeUp: 116,
  purified: 118,
  purifiedFollow: 119,
});

/** Energy notice thresholds as fractions of fight elapsed (client FieldBossRun). */
export const FIELD_BOSS_ENERGY = Object.freeze([
  [0.8, FIELD_BOSS_MAP_STRINGS.energy80],
  [0.85, FIELD_BOSS_MAP_STRINGS.energy85],
  [0.9, FIELD_BOSS_MAP_STRINGS.energy90],
  [0.95, FIELD_BOSS_MAP_STRINGS.energy95],
]);

/** Spawn count for a summons row this tick (min of dwMin..dwMax band and remaining cap). */
export function fieldBossSummonCount(row, alive) {
  const want = num(row.count?.[0], 1);
  const cap = num(row.maxLimit, 50);
  return Math.max(0, Math.min(want, cap - alive));
}

/** Lane 64: Noty_1..5 texts. Global script/string/dungeon/stringtable_dungeon_mapnotify.txt cate 533 codes 121-125. */
export const FIELD_BOSS_NOTY_TEXT = Object.freeze({
  121: 'The World Tree\u2019s agonized cries never cease.', 122: 'The World Tree howls in pain.',
  123: 'The twisted World Tree ravages its surroundings.', 124: 'The twisted World Tree falls into a peaceful slumber.',
  125: 'The twisted World Tree fades away in agony.',
});
/** Lane 64: every former gap with the value used and its source (owner: nothing stays open). */
export const FIELD_BOSS_DECISIONS = Object.freeze([
  'Noty_1..5 = map 533 notify strings 121-125 (World Tree lines, effectui 2603-2607; source: Global stringtable_dungeon_mapnotify.txt cate 533). The Global client never reads config.csv and the decompile has no Noty reader; the older server reference and online sources have no field boss timing, so these five are NOT broadcast (timed broadcast removed). The Red Hole cues 120/101/111-114/116/118/119 stay.',
  'Summons groups 2/3/4: unused. Global config.csv Slave_1/2 = 9491/9492, which are group 1 only (source: Global share/fieldboss).',
  'Loot for 9490: no field boss loot table exists in Global share/fieldboss, the decompile or the older server reference, so no special loot is added (removed); normal monster drop rules apply.',
]);
/** Kept for old imports: nothing is left open. */
export const FIELD_BOSS_UNRESOLVED = Object.freeze([]);
