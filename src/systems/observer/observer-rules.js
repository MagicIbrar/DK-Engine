// OBSERVER rules shared by the host (server/world/observer.mjs) and the client windows (./observer.js).
// Data: share/observer/info.csv (siege venue) and share/guildobserver/info.csv (guild venue); strings 2100 / 2101 / 241.
// Values the data does not define live in src/config/engine-chosen-observer.js (each tagged ENGINE-CHOSEN).
import { OBSERVER_CHOSEN as C } from '../../config/engine-chosen-observer.js';

export const OBSERVER_JOB = 40;   // npc job 40 ENTER_GUILD_OBSERVER (Blake 135, Cain 734)
export const OBSERVER_FILES = Object.freeze({ siege: 'share/observer/info.csv', guild: 'share/guildobserver/info.csv', maps: 'share/maplist.csv' });
export const OBSERVER_SCRIPTS = Object.freeze({
  enter: 'game2/observer/ui_observer_enterwnd.txt', exit: 'game2/observer/ui_observer_exitwnd.txt',
  area: 'game2/observer/ui_observer_areamovewnd.txt', option: 'game2/observer/ui_observer_optionwnd.txt',
  pop: 'game2/observer/ui_observer_popwnd.txt', confirm: 'game2/observer/ui_observer_confirmwnd.txt',
});
/** [cate, code] of every original text the observer windows show. */
export const OBSERVER_STRINGS = Object.freeze({
  exitTitle: [2100, 0], enterTitle: [2100, 1], areaTitle: [2100, 2], optionTitle: [2100, 3], exitHelp: [2100, 10],
  current: [2100, 11], currentGuild: [2100, 12], max: [2100, 13], enterHelp: [2100, 15], areaHelp: [2100, 16],
  situation: [2100, 17], chat: [2100, 18], camera: [2100, 19], warp: [241, 0], follow: [241, 1], ui: [241, 2], exitButton: [241, 3],
});
/** share/observer/info.csv area Name (Korean) -> its English text in string cate 2101 (same names). */
export const AREA_NAME_CODES = Object.freeze({
  '공성측 - 공성포탈': 11, '남문': 8, '서문': 9, '동문': 10, '쥬토': 7,
  '정신의 수호석': 2, '대지의 수호석': 3, '물의 수호석': 4, '바람의 수호석': 5, '불의 수호석': 6,
});
export const OBSERVER_ERRORS = Object.freeze({
  venue: 'Choose an observer venue.', observing: 'You are already observing.', notObserving: 'You are not observing.',
  dead: 'You cannot observe while dead.', instance: 'Leave the dungeon first.', npc: 'Walk near the observer NPC first.',
  full: 'The observer seats are full.', wait: 'Please wait a moment before entering Observer mode again.',
  area: 'Choose an observer area.', noAreas: 'This venue has no observer areas.', busy: 'Finish what you are doing first.',
  closed: 'This observer venue is not open on this server.',
});

const num = v => { const n = Number(v); return Number.isFinite(n) ? n : 0; };
const header = rows => (rows?.[0] || []).map(h => String(h).trim());
/** Parse share/observer/info.csv rows (parseCSV output, header first) into the siege venue record. */
export function parseObserverInfo(rows) {
  const h = header(rows), r = rows?.[1]; if (!r) return null;
  const at = name => h.indexOf(name), last = name => h.lastIndexOf(name);
  const count = num(r[at('Count')]), areas = [];
  for (let i = 0, col = at('Index'); i < count && col >= 0; i++, col += 4)
    areas.push({ index: num(r[col]), name: String(r[col + 1] ?? '').trim(), x: num(r[col + 2]), z: num(r[col + 3]) });
  for (const a of areas) a.textCode = AREA_NAME_CODES[a.name] ?? null;
  return { key: 'siege', map: num(r[at('MapIndex')]), areas, max: num(r[last('MaxUserCount')]), enterEnableMs: num(r[last('EnterEnableTime')]), speed: num(r[last('fSpeed')]) };
}
/** Parse share/guildobserver/info.csv rows into the guild venue record. */
export function parseGuildObserverInfo(rows) {
  const h = header(rows), r = rows?.[1]; if (!r) return null;
  const v = name => num(r[h.indexOf(name)]);
  return { key: 'guild', map: v('MapIndex'), areas: [], entry: { x: v('POSX'), z: v('POSY') }, max: v('MaxUserCount'), enterEnableMs: C.guildEnterEnableMs, speed: v('fSpeed') };
}
/** Both venues; the siege venue lands on area C.siegeEntryArea. Coordinates are data cells (+0.5 = cell centre on arrival). */
export function buildObserverVenues({ siegeRows, guildRows, mapRows }) {
  const siege = parseObserverInfo(siegeRows), guild = parseGuildObserverInfo(guildRows), out = {}, names = mapNames(mapRows);
  for (const v of [siege, guild]) if (v) v.name = names.get(v.map) || `Map ${v.map}`;
  if (guild?.map) out.guild = guild;
  if (siege?.map) { const a = siege.areas[C.siegeEntryArea] || siege.areas[0]; siege.entry = a ? { x: a.x, z: a.z } : null; out.siege = siege; }
  return out;
}
/** share/maplist.csv Index -> Name. */
export function mapNames(rows) { const h = header(rows), i = h.indexOf('Index'), n = h.indexOf('Name'), out = new Map(); for (const r of (rows || []).slice(1)) if (r?.[i] !== undefined && r[i] !== '') out.set(num(r[i]), String(r[n] ?? '').trim()); return out; }
/** Remove the Observer-item caution from 2100:15 / 2100:10 (ENGINE-CHOSEN: no item is consumed). */
export function stripItemCaution(text) {
  let s = String(text ?? '');
  if (!C.stripItemCaution) return s;
  s = s.replace(/\s*and will consume an Observer item\./i, '.');
  s = s.replace(/\s*<color=[0-9a-f]+>\s*Caution:[\s\S]*$/i, '');
  return s.replace(/\s+$/, '');
}
/** Observer Camera fly speed (cells/s): the venue fSpeed clamped to the ENGINE-CHOSEN range. */
/** Global parity: the venue's fSpeed as written (unit ENGINE-CHOSEN: cells/s); no clamp or default multiplier. */
export function cameraSpeed(venue) { const s = num(venue?.speed); return s > 0 ? s : null; }
/** Pure entry check -> an OBSERVER_ERRORS key, or null when entry is allowed. */
export function enterProblem({ venue, observing, dead, instance, busy, nearNpc, count, cooldownMs }) {
  if (!venue) return 'venue';
  if (observing) return 'observing';
  if (dead) return 'dead';
  if (instance) return 'instance';
  if (busy) return 'busy';
  if (!nearNpc) return 'npc';
  if (venue.max > 0 && count >= venue.max) return 'full';
  if (cooldownMs > 0) return 'wait';
  return null;
}
/** Remaining wait (ms) before re-entering, from the time the observer last left. */
export function cooldownLeft(venue, leftAt, now) { if (!Number.isFinite(leftAt)) return 0; return Math.max(0, num(venue?.enterEnableMs) - (now - leftAt)); }
/** Accompany: the point C.followDistance cells short of the target, or null when already close enough. */
export function followPoint(me, target, distance = C.followDistance) {
  if (!me || !target) return null;
  const dx = target.x - me.x, dz = target.z - me.z, d = Math.hypot(dx, dz);
  if (d <= distance + 0.5) return null;
  const k = (d - distance) / d;
  return { x: me.x + dx * k, z: me.z + dz * k };
}
/** Which pop-up variant of ui_observer_popwnd.txt a venue uses. */
export function popVariant(venueKey) { return venueKey === 'siege' || /^renew-(193|194|195)$/.test(String(venueKey)) ? 'siege' : venueKey === 'guild' ? 'guild' : 'partypvp'; }
