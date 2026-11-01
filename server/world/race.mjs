// EVENT-MODES host: the Server Whole Competition (Race, stringtable_title 100|128). Data: share/race/list.csv (bands of
// maps 164-167 per WorldIndex, LimitedCount, waiting point, entrant-count spawn brackets) + playtime.csv (DayOfWeek,
// WaitingHour:WaitingMinute, StartHour, EndHour) from gamedata/events.json modes.race. Rules: src/systems/events/race-rules.js;
// every gap is a tagged line of src/config/engine-chosen-event-modes.js RACE_CHOSEN; every PvP hit runs src/game/pvp-rules.js
// through server/world/pvp.mjs (registerPvpMode). Intents arrive as `event` operations race-info / race-entry / race-leave
// (server/world/events.mjs), so the core dispatcher is unchanged.
import {fishingBusy} from './fishing.mjs';
import { hostEvents } from './prepared-roots.mjs';
import { RACE_CHOSEN as C } from '../../src/config/engine-chosen-event-modes.js';
import { raceRows, raceSchedule, racePhase, raceBand, raceSpawn, raceRanking, raceStatus } from '../../src/systems/events/race-rules.js';
import { registerPvpMode } from './pvp.mjs';
import { createInstance, stageInstanceMembers, requestInstanceClose, exitInstance } from './instances.mjs';
import { sameScene } from './scene.mjs';

export const RACE_OPS = new Set(['race-info', 'race-entry', 'race-leave']);
// Engine texts (no shipped string covers them; the window title / capacity are 100|128 / 100|129): RACE_CHOSEN.text.
export const RACE_TEXT = C.text;
const fail = (message, status = 400) => { throw Object.assign(new Error(message), { status }); };
// Without a file: the active prepared generation's events.json (server/world/prepared-roots.mjs), never a fixed engine/gamedata path.
export async function loadRaceData(file) { return raceDataFrom(await hostEvents(null, file)); }
export function raceDataFrom(ev) {
  const rows = raceRows(ev?.modes?.race?.list || []), schedule = raceSchedule(ev?.modes?.race?.playtime || []);
  if (!rows.length || !schedule) throw new Error('Race: share/race/list.csv / playtime.csv are missing from gamedata/events.json.');
  return { rows, schedule };
}
async function dataOf(world) {
  if (world.data?.race) return (world._raceReady = world.data.race);
  // the world's own events.json (gamedata root of this host) when it is loaded; otherwise this host's gamedata root (prepared generation)
  const built = world.data?.eventData?.modes?.race;
  if (!world._raceReady && built?.list?.length) { const rows = raceRows(built.list), schedule = raceSchedule(built.playtime || []); if (rows.length && schedule) world._raceReady = { rows, schedule }; }
  if (world._raceReady) return world._raceReady;
  if (!world._raceData) world._raceData = hostEvents(world).then(raceDataFrom).then(data => (world._raceReady = data), error => { world._raceData = null; throw error; });
  return world._raceData;
}
const rulesOf = world => { const r = world.data?.pvpRules; if (!r) fail('PvP rules are unavailable on this host.', 503); return r; };
const state = world => world.race ||= { runs: new Map(), announced: null };
const live = (world, q) => !!q && world.players.get(q.account) === q && !q.leaving;
const byId = (world, id) => [...world.players.values()].find(q => q.id === id && !q.leaving) || null;
const runOf = (world, p) => (p?.raceRun && state(world).runs.get(p.raceRun)) || null;
const entrantOf = (r, p) => r?.entrants.find(e => e.id === p.id) || null;
const inside = (world, r, q) => !!q && live(world, q) && q.instanceId === r.instanceId;

/** PvP hooks: during the competition every other entrant of the same band instance is an enemy. */
export function raceEnemy(world, p, q) {
  const r = runOf(world, p);
  if (!r || r.phase !== 'race' || !q || q === p || q.raceRun !== r.id || r.down.has(p.id) || r.down.has(q.id)) return false;
  return inside(world, r, p) && inside(world, r, q) && sameScene(p, q);
}
function raceOpponents(world, p) { const r = runOf(world, p); return r && r.phase === 'race' ? r.entrants.map(e => byId(world, e.id)).filter(q => q && !q.dead && raceEnemy(world, p, q)) : []; }
function guard(world, p, input) { const r = runOf(world, p); if (r && input?.type === 'revive' && inside(world, r, p) && ['race', 'over'].includes(r.phase)) fail(RACE_TEXT.revive); }
registerPvpMode({ enemy: raceEnemy, opponents: raceOpponents, guard, onDown: (world, attacker, target) => { const r = runOf(world, target); if (r?.phase === 'race') markDown(world, r, target); } });

const stat = (r, e) => (r.stats.get(e.id) || r.stats.set(e.id, { id: e.id, name: e.name, kills: 0, deaths: 0, lastKillAt: null }).get(e.id));
function markDown(world, r, q) {
  if (r.down.has(q.id)) return;
  const rules = rulesOf(world), e = entrantOf(r, q); if (!e) return;
  r.down.set(q.id, world.now() + rules.reviveTick * 1000);
  q.hp = 0; q.dead = true; q.path = []; world.changed(q);
  stat(r, e).deaths++;
  const by = q.pvpLastHit?.by && byId(world, q.pvpLastHit.by), be = by && by.raceRun === r.id && entrantOf(r, by);
  if (be && by !== q) { const s = stat(r, be); s.kills++; s.lastKillAt = world.now(); }
}
function place(world, r, q, at) { const scene = world.instances?.get(r.instanceId)?.scene, cell = scene?.nearest(at.x, at.z); if (!cell) return false; q.x = cell.x; q.z = cell.z; q.path = []; return true; }
function refill(world, q, rules, ratio = false) {
  q.dead = false; q.hp = ratio ? Math.max(1, Math.round(q.maxHp * rules.reviveHpRatio / 100)) : q.maxHp; q.mp = Math.round((q.stats.maxMp || 0) * (ratio ? rules.reviveMpRatio / 100 : 1)); delete q.pvpLastHit;
  world.changed(q);
}

function busyReason(q) {
  if (q.dead) return RACE_TEXT.dead;
  if (q.duelId || q.partyPvpId || q.trainingCampId || q.instanceId || q.tradeId || fishingBusy(q) || q.mount?.phase === 'on' || q.sceneTransition) return RACE_TEXT.busy;
  return null;
}

async function enter(world, p, row, win) {
  const st = state(world);
  let r = [...st.runs.values()].find(x => x.row.index === row.index && x.entryAt === win.entryAt && x.phase !== 'over');
  if (r && r.entrants.length >= row.limit) fail(RACE_TEXT.full);
  const exit = { map: p.map, x: p.x, z: p.z };
  p.sceneTransition = true;
  try {
    const staged = stageInstanceMembers(world, [p], [structuredClone(p.profile)]), q = staged.candidates[0];
    if (!r) {
      const instance = await createInstance(staged.world, { map: row.map, members: [q], kind: 'race', exit: undefined, durationMs: Math.max(60000, win.endAt - world.now()) + (C.finishWaitSec + 120) * 1000 });
      instance.admitting = true;
      r = { id: instance.id, instanceId: instance.id, row, entryAt: win.entryAt, startAt: win.startAt, endAt: win.endAt, phase: 'entry', entrants: [], stats: new Map(), down: new Map(), result: null };
      try { if (!place(world, r, q, row.wait)) fail('No safe competition point exists.', 503); }
      catch (error) { world.instances.delete(instance.id); world.maps.delete(`${instance.map}@${instance.id}`); throw error; }
      st.runs.set(r.id, r);
    } else {
      const instance = world.instances?.get(r.instanceId); if (!instance) fail(RACE_TEXT.closed, 409);
      world.emit(q.map, { type: 'leave', actorId: q.id });
      q.instanceId = instance.id; q.map = instance.map; q.path = []; q.mount = null; q.pet = null;
      instance.admitted.add(q.characterId); instance.members.add(q.id);
    }
    const n = r.entrants.length + 1, e = { id: p.id, name: p.profile.name, n, exit };
    r.entrants.push(e); stat(r, e);
    q.profile.instance = { id: r.instanceId, kind: 'race', map: row.map, exit };
    place(world, r, q, r.phase === 'race' ? raceSpawn(row, n) : row.wait);
    q.raceRun = r.id; world.changed(q);
    await world.persistMany(staged.candidates);
    await staged.commit();
    const instance = world.instances?.get(r.instanceId); if (instance) instance.admitting = false;
    p.raceRun = r.id; if (r.phase === 'race') refill(world, p, rulesOf(world));
    return r;
  } finally { p.sceneTransition = false; }
}

export async function raceCommand(world, p, input) {
  const data = await dataOf(world), win = racePhase(data.schedule, world.now());
  if (input.operation === 'race-info') return { race: raceView(world, p, data, win) };
  if (input.operation === 'race-entry') {
    rulesOf(world);
    if (runOf(world, p)) fail(RACE_TEXT.already);
    if (win.phase === 'closed') fail(RACE_TEXT.closed);
    const busy = busyReason(p); if (busy) fail(busy);
    const row = data.rows.find(x => x.map === Number(input.map)) || null;
    if (!row || raceBand(data.rows, p.profile.level) !== row) fail(RACE_TEXT.band);
    await enter(world, p, row, win);
    return { race: raceView(world, p, data, racePhase(data.schedule, world.now())) };
  }
  // race-leave: before the start (waiting point) or once the result is out; the competition itself has no exit button.
  const r = runOf(world, p); if (!r) fail(RACE_TEXT.noEntry);
  if (r.phase === 'race') fail(RACE_TEXT.cannotLeave);
  await leave(world, r, p);
  return { race: raceView(world, p, data, win) };
}
async function leave(world, r, q) {
  if (q.instanceId === r.instanceId) await exitInstance(world, q);
  q.raceRun = null; r.down.delete(q.id);
  if (r.phase === 'entry') { r.entrants = r.entrants.filter(e => e.id !== q.id); r.stats.delete(q.id); }
  world.changed(q);
}

function finish(world, r) {
  const rules = rulesOf(world);
  r.phase = 'over'; r.finishAt = world.now() + C.finishWaitSec * 1000;
  r.result = { ranking: raceRanking([...r.stats.values()]), at: world.now() };
  for (const e of r.entrants) { const q = byId(world, e.id); if (q && q.raceRun === r.id && inside(world, r, q) && (q.dead || q.hp <= 0)) refill(world, q, rules); }
  r.down.clear();
}

export async function tickRace(world) {
  const st = state(world); let data;
  try { data = await dataOf(world); } catch { return; }
  const now = world.now(), win = racePhase(data.schedule, now);
  if (win.phase !== 'closed' && st.announced !== win.entryAt) {
    st.announced = win.entryAt;
    for (const q of world.players.values()) if (!q.leaving && raceBand(data.rows, q.profile.level)) world.emit(q.map, { type: 'event:message', text: RACE_TEXT.open, recipients: [q.id] });
  }
  if (!st.runs.size || !world.data?.pvpRules) return;
  const rules = world.data.pvpRules;
  for (const r of [...st.runs.values()]) {
    if (r.ticking) continue; r.ticking = true;
    try {
      // an entrant that logged in again inside the competition instance (the instance is restored with the profile) is back in the run
      for (const e of r.entrants) { const q = byId(world, e.id); if (q && q.instanceId === r.instanceId && q.raceRun !== r.id) { q.raceRun = r.id; world.changed(q); } }
      for (const e of [...r.entrants]) { const q = byId(world, e.id); if (q && q.raceRun === r.id && !q.instanceId && !q.sceneTransition) { q.raceRun = null; world.changed(q); if (r.phase === 'entry') { r.entrants = r.entrants.filter(x => x.id !== e.id); r.stats.delete(e.id); } } }
      if (r.phase === 'entry' && now >= r.startAt) {
        r.phase = 'race';
        for (const e of r.entrants) { const q = byId(world, e.id); if (inside(world, r, q)) { place(world, r, q, raceSpawn(r.row, e.n)); refill(world, q, rules); } }
      }
      if (r.phase === 'race') {
        for (const e of r.entrants) {
          const q = byId(world, e.id); if (!inside(world, r, q)) continue;
          if ((q.hp <= 0 || q.dead) && !r.down.has(q.id)) markDown(world, r, q);
          else if (r.down.has(q.id) && now >= r.down.get(q.id)) { r.down.delete(q.id); place(world, r, q, raceSpawn(r.row, e.n)); refill(world, q, rules, true); world.emit(q.map, { type: 'revive', actorId: q.id, instanceId: q.instanceId }); }
        }
        if (now >= r.endAt) finish(world, r);
      } else if (r.phase === 'over' && now >= r.finishAt) {
        const instance = world.instances?.get(r.instanceId), still = r.entrants.map(e => byId(world, e.id)).filter(q => inside(world, r, q));
        if (instance && still.length) { requestInstanceClose(world, instance); continue; }
        for (const e of r.entrants) { const q = byId(world, e.id); if (q && q.raceRun === r.id) { q.raceRun = null; world.changed(q); } }
        st.runs.delete(r.id);
      }
      if (!r.entrants.length && r.phase !== 'over') { const instance = world.instances?.get(r.instanceId); if (instance) requestInstanceClose(world, instance); st.runs.delete(r.id); }
    } finally { r.ticking = false; }
  }
}

/** snapshot.race: the entered player's own competition state (a downed entrant cannot send actions, so it reads this); null otherwise. */
export function raceSnapshot(world, p) {
  const data = world._raceReady; if (!data || !runOf(world, p)) return null;
  return raceView(world, p, data, racePhase(data.schedule, world.now()));
}

/** Window state for p: the band list of this host (ui_entreeinfo), p's own run (dashboard / capacity) and the result. */
export function raceView(world, p, data, win) {
  const runs = [...state(world).runs.values()], mine = runOf(world, p);
  const count = row => runs.filter(r => r.row.index === row.index && r.entryAt === win.entryAt && r.phase !== 'over').reduce((n, r) => n + r.entrants.length, 0);
  const myBand = raceBand(data.rows, p.profile.level);
  const rows = data.rows.map(row => ({ map: row.map, index: row.index, server: row.server, minLevel: row.minLevel, maxLevel: row.maxLevel, users: count(row), limit: row.limit,
    status: raceStatus(win.phase, count(row), row.limit), canEnter: win.phase !== 'closed' && row === myBand && !mine && count(row) < row.limit }));
  const out = { phase: win.phase, entryAt: win.entryAt, startAt: win.startAt, endAt: win.endAt, labels: C.labels, rows, run: null };
  if (!mine) return out;
  const ranking = mine.result?.ranking || raceRanking([...mine.stats.values()]), me = ranking.find(s => s.id === p.id) || null;
  out.run = { id: mine.id, server: mine.row.server, map: mine.row.map, phase: mine.phase, users: mine.entrants.length, limit: mine.row.limit, startAt: mine.startAt, endAt: mine.endAt, finishAt: mine.finishAt || null,
    inside: p.instanceId === mine.instanceId, down: mine.down.has(p.id), respawnAt: mine.down.get(p.id) || null, rank: me?.rank ?? null, kills: me?.kills ?? 0, deaths: me?.deaths ?? 0,
    ranking: ranking.slice(0, 10).map(({ id, name, kills, deaths, rank }) => ({ id, name, kills, deaths, rank })),
    enemies: mine.phase === 'race' ? mine.entrants.filter(e => e.id !== p.id && !mine.down.has(e.id)).map(e => e.id) : [], result: mine.result ? { at: mine.result.at } : null };
  return out;
}
