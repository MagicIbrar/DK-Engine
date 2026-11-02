// ARENA host: Draco Desert Battlefield (npc job 130 EGUTT_ENTER, Draco Battle Herald) and the Lost Horizon battlefield
// (npc job 111 ARENA_LOSTHORIZON, npc 5519). Server-authoritative team PvP on the share/arena tables (gamedata/events.json
// modes.arena) with the original texts of stringtable_dksquare.txt. Global parity: data values are used as written; only the
// gaps are ENGINE-CHOSEN (src/config/engine-chosen-arena.js). Every PvP hit runs the PVP-DUEL pipeline
// (registerPvpMode -> server/world/pvp.mjs -> src/game/pvp-rules.js); this module never computes damage.
//   Draco  : conquest.csv Mode 3 / Rank 0 (Lv.100-149, MaxPCCount 120, FightTime 1200 s, OpenTime_1 18), field.csv Type 3
//            (map 702, 4 squads Miseria / Ricchez / Rebel / Terra 160:643-646). Entry while the opening runs; Sunstone
//            (npc 6054, job 52 ARENA_CONQUEST) communion ConquestTime / CoolTime / Buff 11009 BuffTime / KeepTime.
//   Lost Horizon: losthorizon.csv Mode 100 (NeedItemCount 0, NeedDil 0, WaitTime 0), field.csv Type 2 (map 548, 2 squads),
//            rank.csv Rank 100 (Lv.110-250, Max_Room 20), map 548 dungeon row requestMember 7 / expireTime 30.
//   Points : dkactionpoint.csv (Kill PC 400, Dead 350, Destroy Guardian Stone 300, Kill Monster 30, Move 1 / MoveTimeSec 3,
//            Hit Skill PC 10; MinRewardActionPoint 3000). Settlement: activity.csv grades + rank rows, dkkillpoint DP,
//            dktierbuff tiers, PaneltyStatus 11067 / StatusTime 300 for leaving during a fight.
// Action 'arena' rides the dungeons.mjs dispatch ({arenaResult}); the tick rides tickDungeons. No core.mjs edit.
//   Stones : map 702 IsCreate 0 squad guardian stones (server/world/team-stones.mjs, one standing row per squad:
//            engine-chosen-arena.js dracoStoneUids) pay Destroy Guardian Stone (Mission column), never Kill Monster.
//            Outcomes are journaled on each participant's profile before the award write and replayed after a restart.
import {fishingBusy} from './fishing.mjs';
import { randomUUID } from 'node:crypto';
import { hostEvents } from './prepared-roots.mjs';
import { ARENA_CHOSEN as C } from '../../src/config/engine-chosen-arena.js';
import { ARENA_TEXT as T, ARENA_BROADCAST as B, TEAM_NAME_CODES, SUNSTONE_JOB, buildArenaVenues, parseActivity, parseActionPoints, openWindow, levelAllowed,
  assignTeam, settle, dkPointFor, tierFor, decideWinner, boardRows, fillAlly, gradeOf } from '../../src/systems/arena/arena-rules.js';
import { registerPvpMode } from './pvp.mjs';
import { grantModeSafeTime } from './wanted.mjs';
import { createInstance, stageInstanceMembers, requestInstanceClose, exitInstance } from './instances.mjs';
import { nearbyNpc } from './npc-services.mjs';
import { sameScene } from './scene.mjs';
import { ensureSkills } from './skills.mjs';
import { SCENE_REVIVE_HOOKS } from './guild-war-hunting.mjs';
import { AuthoritativeInventory } from './inventory.mjs';
import { progressDekaPass } from './dekapass.mjs';
import { commitArenaReward, journalArenaOutcome, replayArenaOutcomes, refreshArenaStats } from './arena-reward-commit.mjs';
import { teamStoneRows, spawnTeamStones, releaseTeamStones, teamStoneSnapshot } from './team-stones.mjs';

export {ARENA_SCHEMAS} from './arena-schema.mjs';
const OPS = new Set(['info', 'enter', 'cancel', 'commune', 'leave', 'board', 'gmopen']);
const fail = (message, status = 400) => { throw Object.assign(new Error(message), { status }); };
const TEAM_NAMES = ['Miseria', 'Ricchez', 'Rebel', 'Terra'];   // 160:643-646

/** Venues + tables from gamedata/events.json (modes.arena = share/arena/*.csv, maps 548 / 702). Without a file: the active prepared
 *  generation's events.json (server/world/prepared-roots.mjs), never a fixed engine/gamedata path (absent on an install). */
export async function loadArenaData(file) {
  return arenaDataFrom(await hostEvents(null, file));
}
export function arenaDataFrom(ev) {
  const a = ev?.modes?.arena || {};
  const venues = buildArenaVenues(a, ev?.maps || {});
  if (!venues.draco || !venues.lostHorizon) throw new Error('ARENA: share/arena conquest/field/losthorizon rows are missing from gamedata/events.json.');
  return { venues, activity: parseActivity(a.activity), action: parseActionPoints(a.dkActionPoint), killPoint: a.dkKillPoint || [], tiers: a.dkTierBuff || [] };
}
async function dataOf(world) {
  if (world.data?.arena) return world.data.arena;
  // this host's loaded event tables (world.data.eventData) first, then its own gamedata root
  if (!world._arenaData) world._arenaData = hostEvents(world).then(arenaDataFrom).catch(error => { world._arenaData = null; throw error; });
  return world._arenaData;
}

const battles = world => world.arenaBattles ||= new Map();
const queue = world => world.arenaQueue ||= [];
const board = world => world.arenaBoard ||= new Map();
const live = (world, p) => !!p && world.players.get(p.account) === p && !p.leaving;
const byId = (world, id) => [...world.players.values()].find(q => q.id === id && !q.leaving) || null;
const current = (world, p) => (p?.arenaId && battles(world).get(p.arenaId)) || null;
const teamOf = (b, p) => (b?.teams ? b.teams.findIndex(t => t.includes(p.id)) : -1);
const inside = (world, b, q) => !!q && live(world, q) && q.instanceId === b.instanceId;
const teamName = t => TEAM_NAMES[t] || `Team ${t + 1}`;
const stat = (b, id) => { let s = b.stats.get(id); if (!s) b.stats.set(id, s = { kills: 0, deaths: 0, points: 0, battle: 0, mission: 0, bonus: 0, hits: 0, monsters: 0, moves: 0, stones: 0 }); return s; };
// ENGINE-CHOSEN columns (src/config/engine-chosen-arena.js boardColumns): Battle = Kill PC / Dead / Hit Skill PC, Mission = Destroy Guardian Stone / Kill Monster, Bonus = Move.
const COLUMN = { killPc: 'battle', dead: 'battle', hitSkill: 'battle', destroyStone: 'mission', killMonster: 'mission', move: 'bonus' };
const record = p => (p.profile.arena ||= { dp: 0, rankScore: 0, battles: 0, wins: 0 });
const pendingRewards = new WeakMap();
function notify(world, b, reason, extra = {}) {
  const ids = b.teams.flat(), anyone = ids.map(id => byId(world, id)).find(q => q && q.instanceId === b.instanceId);
  if (anyone) world.emit(anyone.map, { type: 'arena', id: b.id, reason, phase: b.phase, recipients: ids, instanceId: b.instanceId, ...extra });
}
function busyReason(world, q) {
  if (q.dead) return T.dead;
  if (q.duelId || q.partyPvpId || q.instanceId || q.tradeId || fishingBusy(q) || q.mount?.phase === 'on' || q.sceneTransition) return T.busy;
  return null;
}
const penalised = (world, p) => (Number(p.profile.arena?.penaltyUntil) || 0) > world.now();
function applyPenalty(world, p, data) {
  const ms = data.activity.penaltySec * 1000; if (!(ms > 0)) return;
  record(p).penaltyUntil = world.now() + ms;
  try { const { statuses, game } = ensureSkills(world, p); statuses.add(game.player, data.activity.penaltyStatus, ms, { source: game.player }); } catch { /* status packs optional */ }
  world.changed(p);
}
function addPoints(b, id, key, data) { const v = data.action.points[key] || 0; if (!v) return; const s = stat(b, id); s.points += v; s[COLUMN[key]] += v; }

/** PvP-mode hooks: an enemy is a participant of another squad, both up, inside the same battlefield during the fight. */
export function arenaEnemy(world, p, q) {
  const b = current(world, p);
  if (!b || b.phase !== 'fight' || !q || q.arenaId !== b.id || b.down.has(p.id) || b.down.has(q.id)) return false;
  const a = teamOf(b, p), c = teamOf(b, q);
  return a >= 0 && c >= 0 && a !== c && sameScene(p, q);
}
function arenaOpponents(world, p) {
  const b = current(world, p); if (!b || b.phase !== 'fight') return [];
  return b.teams.flat().map(id => byId(world, id)).filter(q => q && arenaEnemy(world, p, q) && !q.dead);
}
const TRAVEL_TYPES = new Set(['travel', 'smartwarp', 'mapnpcwarp', 'npctravel', 'channel']);
function arenaGuard(world, p, input) {
  const b = current(world, p); if (!b || !input || !inside(world, b, p)) return;
  if (b.phase === 'fight' && TRAVEL_TYPES.has(input.type)) fail(T.cannotLeave);
}
/** Core's Revive (the death window) revives a downed participant at its squad Revive_Pos inside the battlefield. */
export function arenaRevive(world, p) {
  const b = current(world, p); if (!b || !p.dead || !inside(world, b, p)) return false;
  revive(world, b, p, b.phase === 'fight'); if (b.phase === 'fight') notify(world, b, 'respawn', { playerId: p.id });
  return true;
}
if (!SCENE_REVIVE_HOOKS.includes(arenaRevive)) SCENE_REVIVE_HOOKS.push(arenaRevive);
registerPvpMode({ enemy: arenaEnemy, opponents: arenaOpponents, guard: arenaGuard,
  onDown: (world, attacker, target) => { const b = current(world, target); if (b?.phase === 'fight') markDown(world, b, target); } });

function markDown(world, b, q) {
  if (b.down.has(q.id)) return;
  b.down.set(q.id, world.now());
  q.hp = 0; q.dead = true; q.path = []; world.changed(q);
  const data = b.data; stat(b, q.id).deaths++; addPoints(b, q.id, 'dead', data);
  if (b.sun?.communing?.id === q.id) stopCommunion(world, b, 'dead');
  const by = q.pvpLastHit?.by && byId(world, q.pvpLastHit.by);
  if (by && by.arenaId === b.id && teamOf(b, by) >= 0 && teamOf(b, by) !== teamOf(b, q)) { stat(b, by.id).kills++; addPoints(b, by.id, 'killPc', data); }
  notify(world, b, 'down', { playerId: q.id, by: by?.id || null });
}
function revive(world, b, q, relocate) {
  const rules = world.data.pvpRules || { reviveHpRatio: 100, reviveMpRatio: 100 };
  if (relocate) { const t = teamOf(b, q), sq = b.v.squads[t], at = sq && world.instances?.get(b.instanceId)?.scene?.nearest(sq.revive.x, sq.revive.z); if (at) { q.x = at.x; q.z = at.z; } }
  q.dead = false; q.hp = Math.max(1, Math.round(q.maxHp * rules.reviveHpRatio / 100)); q.mp = Math.round((q.stats.maxMp || 0) * rules.reviveMpRatio / 100); q.path = []; delete q.pvpLastHit;
  b.down.delete(q.id); world.changed(q); if (relocate) grantModeSafeTime(world, q, 'arena'); world.emit(q.map, { type: 'revive', actorId: q.id, instanceId: q.instanceId });
}

// ---- entry
function npcCheck(world, p, v, input) {
  const opts = { jobType: v.job, radius: C.npcRadius, ...(Number.isInteger(input.npcIndex) ? { npcIndex: input.npcIndex } : {}) };
  if (!nearbyNpc(world, p, opts)) fail('Talk to the battlefield NPC first.');
}
function windowOf(world, v) {
  const f = world.arenaForcedOpen?.[v.key];
  if (f && world.now() < f.endsAt) return { open: true, startsAt: f.startsAt, endsAt: f.endsAt, forced: true };
  return openWindow(v, world.now());
}
function admissible(world, p, v) {
  if (penalised(world, p)) fail(v.key === 'draco' ? T.penalty : T.busy);
  const busy = busyReason(world, p); if (busy) fail(busy);
  if (!levelAllowed(v, p.profile.level)) fail(T.level);
}
async function stageInto(world, b, ps, exits) {
  const v = b.v; for (const q of ps) q.sceneTransition = true;
  const staged = stageInstanceMembers(world, ps, ps.map(q => structuredClone(q.profile)));
  let instance = b.instanceId ? world.instances?.get(b.instanceId) : null, created = false;
  try {
    if (!instance) {
      instance = await createInstance(staged.world, { map: v.map, members: staged.candidates, kind: 'arena', exit: undefined, durationMs: (Math.max(0, b.endsAt - world.now()) / 1000 + 120) * 1000 });   /* +120 s instance housekeeping margin */
      created = true;
    } else {
      for (const q of staged.candidates) {
        staged.world.emit(q.map, { type: 'leave', actorId: q.id });
        instance.admitted.add(q.characterId); instance.members.add(q.id);
        q.instanceId = instance.id; q.map = instance.map; q.path = []; q.mount = null; q.pet = null;
        q.profile.instance = { id: instance.id, kind: instance.kind, map: instance.map, exit: undefined };
      }
    }
    instance.admitting = true;
    for (const q of staged.candidates) {
      const t = teamOf(b, q), s = v.squads[t].start, at = instance.scene.nearest(s.x, s.z);
      if (!at) fail('No safe battlefield start exists.', 503);
      q.x = at.x; q.z = at.z; q.profile.instance.exit = exits.get(q.id) || world.data.start;
      world.changed(q); if (!created) staged.world.emit(q.map, { type: 'join', actorId: q.id });
    }
    await world.persistMany(staged.candidates);
    await staged.commit();
    instance.admitting = false;
    for (const q of ps) {
      if (q.profile.instance) q.profile.instance.exit = exits.get(q.id) || world.data.start;
      q.hp = q.maxHp; q.mp = q.stats.maxMp || 0; q.dead = false; delete q.pvpLastHit; q.arenaId = b.id; delete q.arenaResult; world.changed(q);
      const s = stat(b, q.id); s.lastPos = { x: q.x, z: q.z }; s.moveAt = world.now();
    }
  } catch (error) {
    if (created && instance) { world.instances.delete(instance.id); world.maps.delete(`${instance.map}@${instance.id}`); }
    else if (instance) { instance.admitting = false; for (const q of ps) instance.members.delete(q.id); }
    throw error;
  } finally { for (const q of ps) q.sceneTransition = false; }
  return instance;
}
function newBattle(world, v, data, endsAt) {
  return { id: randomUUID(), venue: v.key, v, data, phase: 'fight', instanceId: null, teams: v.squads.map(() => []), names: new Map(), classes: new Map(),
    stats: new Map(), down: new Map(), startAt: world.now(), endsAt, lastSeq: world.sequence || 0, everTeams: new Set(),
    sun: v.key === 'draco' ? { owner: -1, since: null, communing: null, blocked: v.squads.map(() => 0) } : null, buffs: [], effects: [], stones: [], guardStones: [], result: null };
}
/** Draco squad guardian stones (map 702 IsCreate 0 bricks) in a fresh battle instance. */
function placeGuardStones(world, b, instance) {
  const rows = teamStoneRows(world, b.v.map, C.dracoStoneUids || []);
  b.guardStones = spawnTeamStones(world, { battle: b, instance, rows, squadOfAlly: ally => b.v.squads.findIndex(s => s.ally === ally), teamOf: q => teamOf(b, q),
    onDestroyed: (w, p, m) => { stat(b, p.id).stones++; addPoints(b, p.id, 'destroyStone', b.data); notify(w, b, 'guardStone', { playerId: p.id, team: m.teamStone.team, stoneId: m.id, uid: m.uid }); } });
}
async function enterDraco(world, p, v, data) {
  const w = windowOf(world, v); if (!w.open) fail(T.closed);
  admissible(world, p, v);
  let b = [...battles(world).values()].find(x => x.venue === 'draco' && x.phase === 'fight' && x.window === (w.startsAt ?? 'all'));
  const count = b ? b.teams.flat().filter(id => inside(world, b, byId(world, id))).length : 0;
  if (count >= v.maxPlayers) fail(T.full);
  const fresh = !b;
  if (fresh) { b = newBattle(world, v, data, w.endsAt ?? world.now() + v.fightSec * 1000); b.window = w.startsAt ?? 'all'; }
  const counts = b.teams.map(ids => ids.filter(id => inside(world, b, byId(world, id))).length), t = assignTeam(counts);
  b.teams[t].push(p.id); b.names.set(p.id, p.profile.name); b.classes.set(p.id, p.profile.classIndex); b.everTeams.add(t);
  let instance;
  try { instance = await stageInto(world, b, [p], new Map([[p.id, { map: p.map, x: p.x, z: p.z }]])); }
  catch (error) { b.teams[t] = b.teams[t].filter(id => id !== p.id); throw error; }
  if (fresh) { b.instanceId = instance.id; placeGuardStones(world, b, instance); battles(world).set(b.id, b); notify(world, b, 'start', { endsAt: b.endsAt }); }
  else notify(world, b, 'join', { playerId: p.id, team: t });
  return { entered: b.id, team: t };
}
// ---- Lost Horizon stone images (map 548 call group 1)
// The map's only call (callmonster_548_lost_horizon.csv, call 1) puts three stone images in each sealed base. Their own names state the
// effect on the OPPOSING team once destroyed: 7878 / 7916 "Stuns opponent team", 7879 / 7917 "Disables opponent team's skills", 7880 / 7918
// "Drops meteor on opponent team" (HP 607013, no attack). A base belongs to the squad whose start point is nearest to it.
const STONE_EFFECT = { 7878: 'stun', 7916: 'stun', 7879: 'lock', 7917: 'lock', 7880: 'meteor', 7918: 'meteor' };
function spawnStoneImages(world, b, instance) {
  const rows = b.v.stoneCalls || [], scene = instance.scene;
  b.stones = [];
  for (const [mon, x, z] of rows) {
    const effect = STONE_EFFECT[Number(mon)], def = effect && world.data.monsterDef?.(Number(mon)); if (!def || !scene?.monsters) continue;
    const point = scene.nearest(Number(x) + 0.5, Number(z) + 0.5); if (!point) continue;
    let team = 0, best = Infinity;
    b.v.squads.forEach((s, t) => { const d = Math.hypot(s.start.x - point.x, s.start.z - point.z); if (d < best) { best = d; team = t; } });
    const id = `arena:${b.id}:${mon}`;
    const m = { id, map: b.v.map, instanceId: instance.id, channel: 0, monsterIndex: Number(mon), name: def.name, ...point, hp: def.hp, maxHp: def.hp, home: { ...point }, dead: false, targetId: null,
      attackAt: 0, respawnAt: Infinity, respawnSec: Infinity, def: { ...def }, arenaStone: { team, effect } };
    m.onKilled = killer => stoneDestroyed(world, b, m, killer);
    scene.monsters.set(id, m); b.stones.push(m);
  }
}
/** A stone image is destroyed: its effect hits every standing member of the other squads (stun / skill lock = the lowest status of the
 *  data group, a meteor = a share of max HP that never kills). The kill itself pays Kill Monster points through scanEvents. */
function stoneDestroyed(world, b, m, killer) {
  if (b.phase !== 'fight' || m._arenaDone) return; m._arenaDone = true;
  const by = killer && teamOf(b, killer) >= 0 ? teamOf(b, killer) : m.arenaStone.team, effect = m.arenaStone.effect, ms = C.stoneEffectSec * 1000, targets = [];
  b.effects.push({ team: by, effect, monsterIndex: m.monsterIndex, status: C.stoneStatus[effect] ?? null, until: world.now() + ms, targets });
  for (const [t, ids] of b.teams.entries()) {
    if (t === by) continue;
    for (const id of ids) {
      const q = byId(world, id); if (!inside(world, b, q) || q.dead || b.down.has(q.id)) continue;
      targets.push(q.id);
      if (effect === 'meteor') {
        const amount = Math.round(q.maxHp * C.stoneMeteor.percent / 100); q.hp = Math.max(1, q.hp - amount); world.changed(q);
        world.emit(q.map, { type: 'damage', sourceId: m.id, targetId: q.id, amount, dead: false, instanceId: b.instanceId, pvp: true });
      } else {
        try { const { statuses, game } = ensureSkills(world, q); statuses.add(game.player, C.stoneStatus[effect], ms, { source: game.player }); world.changed(q); } catch { /* status packs optional */ }
      }
    }
  }
  notify(world, b, 'stone', { team: by, effect, playerId: killer?.id || null, monsterIndex: m.monsterIndex });
}
async function queueLostHorizon(world, p, v, data) {
  if (queue(world).some(e => e.id === p.id)) fail(T.already);
  admissible(world, p, v);
  queue(world).push({ id: p.id, at: world.now(), exit: { map: p.map, x: p.x, z: p.z } });
  p.arenaQueued = 'lostHorizon'; delete p.arenaResult; world.changed(p);
  await startLostHorizon(world, v, data);
  return { queued: queue(world).length, start: v.startPlayers };
}
async function startLostHorizon(world, v, data) {
  const q = queue(world);
  for (const e of [...q]) { const x = byId(world, e.id); if (!x || !live(world, x) || x.arenaQueued !== 'lostHorizon' || busyReason(world, x)) q.splice(q.indexOf(e), 1); }
  if (q.length < v.startPlayers) return false;
  const picked = q.splice(0, v.maxPlayers), ps = picked.map(e => byId(world, e.id));
  const b = newBattle(world, v, data, world.now() + (v.waitSec + v.fightSec) * 1000);
  for (const x of ps) { const t = assignTeam(b.teams.map(ids => ids.length)); b.teams[t].push(x.id); b.names.set(x.id, x.profile.name); b.classes.set(x.id, x.profile.classIndex); b.everTeams.add(t); }
  for (const x of ps) { x.arenaQueued = null; world.changed(x); }
  try { const instance = await stageInto(world, b, ps, new Map(picked.map(e => [e.id, e.exit]))); b.instanceId = instance.id; spawnStoneImages(world, b, instance); }
  catch (error) { for (const e of picked.reverse()) { q.unshift(e); const x = byId(world, e.id); if (x) { x.arenaQueued = 'lostHorizon'; world.changed(x); } } throw error; }
  battles(world).set(b.id, b);
  notify(world, b, 'start', { endsAt: b.endsAt });
  return true;
}

// ---- Sunstone communion (Draco)
function stopCommunion(world, b, why) {
  const c = b.sun.communing; if (!c) return; b.sun.communing = null;
  b.sun.blocked[c.team] = world.now() + b.v.coolSec * 1000;
  notify(world, b, 'communion-stopped', { playerId: c.id, team: c.team, why, text: T.stopped, broadcast: fillAlly(B.failedTeam, teamName(c.team), b.names.get(c.id) || '') });
}
function commune(world, p, b) {
  const v = b.v, data = b.data, now = world.now();
  if (b.venue !== 'draco' || b.phase !== 'fight' || !v.sunstone) fail(T.unavailable);
  if (now < b.startAt + v.conquestWaitSec * 1000) fail(T.unavailable);
  if (p.dead || b.down.has(p.id)) fail(T.failed);
  if (!nearbyNpc(world, p, { npcIndex: v.sunstone.npc, jobType: SUNSTONE_JOB, radius: v.radius }) && Math.hypot(p.x - v.sunstone.x, p.z - v.sunstone.z) > v.radius) fail('Move closer to the Sunstone.');
  const t = teamOf(b, p);
  if (b.sun.owner === t) fail(T.ownStone);
  if (b.sun.communing) fail(b.sun.communing.id === p.id ? T.communing : T.someoneElse);
  if (now < b.sun.blocked[t]) fail(T.blocked);
  if (stat(b, p.id).points < data.action.minReward) fail(T.needScore);
  b.sun.communing = { id: p.id, team: t, startAt: now, endsAt: now + v.conquestSec * 1000, x: p.x, z: p.z, hp: p.hp };
  notify(world, b, 'communion', { playerId: p.id, team: t, endsAt: b.sun.communing.endsAt, text: T.communing, broadcast: fillAlly(B.trying, teamName(t)) });
  return { communing: b.sun.communing.endsAt };
}
function tickCommunion(world, b) {
  const c = b.sun?.communing; if (!c) return;
  const q = byId(world, c.id);
  if (!q || !inside(world, b, q) || q.dead || b.down.has(q.id)) return stopCommunion(world, b, 'gone');
  if (Math.hypot(q.x - c.x, q.z - c.z) > C.communionMoveTolerance) return stopCommunion(world, b, 'moved');
  if (q.hp < c.hp) return stopCommunion(world, b, 'hit');
  c.hp = Math.max(c.hp, q.hp);
  if (world.now() < c.endsAt) return;
  b.sun.communing = null; b.sun.owner = c.team; b.sun.since = world.now();
  const until = world.now() + b.v.buffSec * 1000;
  b.buffs.push({ team: c.team, status: b.v.buff, until });
  for (const id of b.teams[c.team]) {
    const m = byId(world, id); if (!inside(world, b, m)) continue;
    try { const { statuses, game } = ensureSkills(world, m); statuses.add(game.player, b.v.buff, b.v.buffSec * 1000, { source: game.player }); world.changed(m); } catch { /* status packs optional */ }
  }
  notify(world, b, 'occupied', { playerId: c.id, team: c.team, text: T.conquered, broadcast: fillAlly(B.occupied, teamName(c.team)) });
}

// ---- points from host events (Hit Skill PC / Kill Monster) and movement
function scanEvents(world, b) {
  const evs = world.events || [], ids = new Set(b.teams.flat()), stones = new Set((b.guardStones || []).map(m => m.id));
  let last = b.lastSeq;
  for (const e of evs) {
    if (!(e.sequence > b.lastSeq)) continue; last = Math.max(last, e.sequence);
    if (e.instanceId !== b.instanceId || e.type !== 'damage' || e.miss || !ids.has(e.sourceId)) continue;
    const src = byId(world, e.sourceId); if (!src) continue;
    if (ids.has(e.targetId)) {
      if (e.skillId != null && teamOf(b, src) !== teamOf(b, { id: e.targetId })) { stat(b, src.id).hits++; addPoints(b, src.id, 'hitSkill', b.data); }
    } else if (e.dead && !stones.has(e.targetId) && ![...world.players.values()].some(x => x.id === e.targetId)) { stat(b, src.id).monsters++; addPoints(b, src.id, 'killMonster', b.data); }   // a guardian stone pays Destroy Guardian Stone only
  }
  b.lastSeq = last;
}
function tickMoves(world, b, q) {
  const s = stat(b, q.id), now = world.now(), every = b.data.action.moveSec * 1000;
  if (!s.lastPos) { s.lastPos = { x: q.x, z: q.z }; s.moveAt = now; return; }
  if (!(every > 0) || now - s.moveAt < every) return;
  if (!q.dead && Math.hypot(q.x - s.lastPos.x, q.z - s.lastPos.z) > 0) { s.moves++; addPoints(b, q.id, 'move', b.data); }
  s.lastPos = { x: q.x, z: q.z }; s.moveAt = now;
}

// ---- settlement
function teamView(world, b) {
  return b.teams.map((ids, t) => {
    const block = b.data.activity.ranks[b.v.rank];
    const members = ids.map(id => { const q = byId(world, id), s = b.stats.get(id) || { kills: 0, deaths: 0, points: 0, battle: 0, mission: 0, bonus: 0 };
      return { id, name: b.names.get(id) || q?.profile.name || '', classIndex: b.classes.get(id) ?? q?.profile.classIndex ?? 0, level: q?.profile.level ?? 0,
        present: inside(world, b, q), down: b.down.has(id), kills: s.kills, deaths: s.deaths, points: s.points, battle: s.battle, mission: s.mission, bonus: s.bonus,
        gradeString: block ? (b.data.activity.strings[gradeOf(s.points, block)] ?? null) : null }; });
    return { team: t, name: teamName(t), nameCode: TEAM_NAME_CODES[t], points: members.reduce((n, m) => n + m.points, 0), present: members.filter(m => m.present).length, members };
  });
}
async function finish(world, b, reason) {
  if (b.phase !== 'fight') return;
  if (b.sun?.communing) stopCommunion(world, b, 'end');
  const now = world.now(), data = b.data, teams = teamView(world, b);
  const win = decideWinner(teams, b.sun || {}, reason), outcomeOf = t => (win < 0 ? 'draw' : t === win ? 'win' : 'lose');
  b.phase = 'over'; b.finishAt = now;   /* Lane 71: 160:70 timed move-out REMOVED (no Global, decompile, older-server or online value); participants are moved out once settled */
  const entries = [];
  for (const id of b.teams.flat()) {
    const q = byId(world, id); if (!inside(world, b, q)) continue;
    const t = teamOf(b, q), s = stat(b, id), outcome = outcomeOf(t);
    const st = settle({ activity: data.activity, rank: b.v.rank, points: s.points, outcome, minReward: data.action.minReward });
    entries.push({actor:q,done:false,journaled:false,reward:{battle:b.id,venue:b.venue,rank:b.v.rank,map:Number(b.v?.map)||0,reason,winner:win,team:t,outcome,points:s.points,kills:s.kills,deaths:s.deaths,stones:s.stones,...st,dpGain:dkPointFor(s.kills,data.killPoint),at:now}});
  }
  b.result = { winner: win, reason, teams, at: now };
  b.down.clear(); releaseTeamStones(b.guardStones);
  pendingRewards.set(b,{entries,published:false});
  await settleRewards(world,b);
}
// DekaPass credit of one battlefield outcome (live settlement and restart replay alike).
const arenaCredit=reward=>(facade,actor)=>progressDekaPass(facade,actor,2,16,Number(reward.map)||0,1);
async function settleRewards(world,b) {
  const pending=pendingRewards.get(b);if(!pending)return true;
  // Durable before any award: each present participant's frozen outcome is journaled on its own profile first.
  await Promise.all(pending.entries.filter(e=>!e.done&&!e.journaled&&live(world,e.actor)&&byId(world,e.actor.id)===e.actor)
    .map(async e=>{try{e.journaled=!!await journalArenaOutcome(world,e.actor,e.reward);}catch(error){e.error=error?.message||String(error);}}));
  for(const entry of pending.entries){
    if(entry.done)continue;const q=entry.actor;
    // gone: a journaled outcome is paid by replayArena at the character's next presence
    if(!live(world,q)||byId(world,q.id)!==q){entry.done=true;continue;}
    if(!entry.journaled)continue;
    try{
      const r=await commitArenaReward(world,q,entry.reward,arenaCredit(entry.reward));
      entry.done=true;if(!r||!live(world,q))continue;
      refreshArenaStats(world,q);
      const tier=tierFor(r.dp,b.data.tiers,b.v.rank);
      if(inside(world,b,q)&&(q.dead||q.hp<=0))revive(world,b,q,false);
      q.arenaResult={...r,tier,teams:b.result.teams};
      board(world).set(q.id,{id:q.id,name:q.profile.name,classIndex:q.profile.classIndex,level:q.profile.level,dp:r.dp,tier:tier?.name||null,rank:b.v.rank});world.changed(q);
    }catch(error){entry.error=error?.message||String(error);}
  }
  if(pending.entries.some(e=>!e.done))return false;
  if(!pending.published){pending.published=true;const {winner,reason}=b.result;
    notify(world,b,'result',{winner,reasonDetail:reason,...(winner<0?{text:T.noWinner}:{winnerName:teamName(winner)})});}
  return true;
}
async function removeParticipant(world, b, q, { penalty = false } = {}) {
  if (b.sun?.communing?.id === q.id) stopCommunion(world, b, 'left');
  if (inside(world, b, q)) { if (q.dead || q.hp <= 0) revive(world, b, q, false); await exitInstance(world, q); }
  if (penalty) applyPenalty(world, q, b.data);
  q.arenaId = null; world.changed(q);
}

// Journaled battlefield outcomes no live settlement owns (host restart, gone before the award write): paid once, now.
function replayArena(world) {
  replayArenaOutcomes(world, 'arena', { owns: r => r.venue === 'draco' || r.venue === 'lostHorizon', credit: arenaCredit,
    live: (r, p) => { const b = battles(world).get(r.battle), e = b && pendingRewards.get(b)?.entries.find(x => x.actor === p); return !!e && !e.done; },
    done: (p, r, reward) => { refreshArenaStats(world, p); const data = world.data?.arena || world._arenaDataSync, tier = data ? tierFor(r.dp, data.tiers, reward.rank) : null;
      p.arenaResult = { ...r, tier, teams: [], replayed: true };
      board(world).set(p.id, { id: p.id, name: p.profile.name, classIndex: p.profile.classIndex, level: p.profile.level, dp: r.dp, tier: tier?.name || null, rank: reward.rank }); world.changed(p); } });
}
export async function tickArena(world) {
  if (!world._arenaTicking && world.data?.pvpRules) replayArena(world);
  if (world._arenaTicking || (!world.arenaBattles?.size && !world.arenaQueue?.length)) return;
  world._arenaTicking = true;
  try {
    const data = await dataOf(world), now = world.now(); world._arenaDataSync = data;
    if (queue(world).length) await startLostHorizon(world, data.venues.lostHorizon, data).catch(() => {});
    for (const b of [...battles(world).values()]) {
      if (b.phase === 'fight') {
        scanEvents(world, b);
        for (const id of b.teams.flat()) {
          const q = byId(world, id);
          if (!inside(world, b, q)) { if (q && q.arenaId === b.id && !q.instanceId && !q.sceneTransition) { q.arenaId = null; applyPenalty(world, q, data); } continue; }
          if ((q.hp <= 0 || q.dead) && !b.down.has(id)) markDown(world, b, q);
          else if (b.down.has(id) && now - b.down.get(id) >= C.autoExitSec * 1000) { b.down.delete(id); await removeParticipant(world, b, q).catch(() => {}); notify(world, b, 'removed', { playerId: id }); continue; }
          tickMoves(world, b, q);
        }
        tickCommunion(world, b);
        const present = b.teams.map(ids => ids.filter(id => inside(world, b, byId(world, id))).length);
        if (!present.some(Boolean)) { b.phase = 'over'; b.finishAt = now; b.result = { winner: -1, reason: 'empty', teams: teamView(world, b), at: now }; }
        else if (b.sun && b.sun.owner >= 0 && now - b.sun.since >= b.v.keepMin * 60000) await finish(world, b, 'keep');
        else if (b.everTeams.size > 1 && present.filter(Boolean).length === 1) await finish(world, b, 'alone');
        else if (now >= b.endsAt) await finish(world, b, 'time');
        continue;
      }
      if (b.phase === 'over' && !await settleRewards(world,b)) continue;
      if (b.phase === 'over' && now >= b.finishAt) {
        const left = b.teams.flat().map(id => byId(world, id)).filter(q => inside(world, b, q));
        const instance = world.instances?.get(b.instanceId);
        if (instance && left.length) { requestInstanceClose(world, instance); continue; }
        for (const id of b.teams.flat()) { const q = byId(world, id); if (q && q.arenaId === b.id) { q.arenaId = null; world.changed(q); } }
        battles(world).delete(b.id);
      }
    }
  } finally { world._arenaTicking = false; }
}

// ---- command
function venueInfo(world, v, p) {
  const w = windowOf(world, v);
  const b = [...battles(world).values()].find(x => x.venue === v.key && x.phase === 'fight');
  const count = b ? b.teams.flat().filter(id => inside(world, b, byId(world, id))).length : 0;
  return { key: v.key, name: v.name, map: v.map, job: v.job, mode: v.mode, rank: v.rank, minLevel: v.minLevel, maxLevel: v.maxLevel, maxPlayers: v.maxPlayers, startPlayers: v.startPlayers,
    fightSec: v.fightSec, open: !!w.open, startsAt: w.startsAt ?? null, endsAt: w.endsAt ?? null, inBattle: count, queued: v.key === 'lostHorizon' ? queue(world).length : 0,
    title: v.title, missions: v.missions, levelOk: levelAllowed(v, p.profile.level), penaltyUntil: Number(p.profile.arena?.penaltyUntil) || 0 };
}
export function arenaState(world, p, data) {
  const b = current(world, p), rec = p.profile.arena || { dp: 0, rankScore: 0, battles: 0, wins: 0 };
  const out = { venues: data ? Object.fromEntries(Object.values(data.venues).map(v => [v.key, venueInfo(world, v, p)])) : {}, queued: p.arenaQueued || null,
    record: { dp: rec.dp || 0, rankScore: rec.rankScore || 0, battles: rec.battles || 0, wins: rec.wins || 0, tier: data ? tierFor(rec.dp || 0, data.tiers, 7) : null },
    result: p.arenaResult || null, battle: null, minReward: data?.action.minReward || 0 };
  if (!b) return out;
  const t = teamOf(b, p), s = b.stats.get(p.id) || { points: 0, kills: 0, deaths: 0 };
  out.battle = { id: b.id, venue: b.venue, map: b.v.map, phase: b.phase, team: t, teamName: teamName(t), startAt: b.startAt, endsAt: b.endsAt, finishAt: b.finishAt || null,
    teams: b.phase === 'over' && b.result ? b.result.teams : teamView(world, b), winner: b.result ? b.result.winner : null, reason: b.result?.reason || null,
    me: { points: s.points, kills: s.kills, deaths: s.deaths, stones: s.stones || 0, down: b.down.has(p.id), downAt: b.down.get(p.id) || null, autoExitAt: b.down.has(p.id) ? b.down.get(p.id) + C.autoExitSec * 1000 : null },
    activeScore: b.v.activeScore, missions: b.v.missions, title: b.v.title, inside: inside(world, b, p), stones: teamStoneSnapshot(b.guardStones, t),
    sun: b.sun ? { owner: b.sun.owner, ownerName: b.sun.owner >= 0 ? teamName(b.sun.owner) : null, since: b.sun.since, keepMin: b.v.keepMin, keepEndsAt: b.sun.owner >= 0 ? b.sun.since + b.v.keepMin * 60000 : null,
      communing: b.sun.communing ? { id: b.sun.communing.id, team: b.sun.communing.team, startAt: b.sun.communing.startAt, endsAt: b.sun.communing.endsAt } : null,
      blockedUntil: t >= 0 ? b.sun.blocked[t] : 0, x: b.v.sunstone?.x, z: b.v.sunstone?.z, radius: b.v.radius } : null,
    enemies: b.phase === 'fight' && t >= 0 ? b.teams.flatMap((ids, i) => (i === t ? [] : ids.filter(id => !b.down.has(id)))) : [] };
  return out;
}
export async function arenaCommand(world, p, input) {
  if (!world.data?.pvpRules) fail('PvP rules are unavailable on this host.', 503);
  const data = await dataOf(world); world._arenaDataSync = data;
  const op = input.operation || 'info'; if (!OPS.has(op)) fail('Choose a battlefield operation.');
  const b = current(world, p);
  if (op === 'info') { await tickArena(world); return { arenaResult: arenaState(world, p, data) }; }
  if (op === 'board') {
    const own = p.profile.arena; if (own) board(world).set(p.id, { id: p.id, name: p.profile.name, classIndex: p.profile.classIndex, level: p.profile.level, dp: own.dp || 0, tier: tierFor(own.dp || 0, data.tiers, 7)?.name || null });
    return { arenaResult: { ...arenaState(world, p, data), board: boardRows(board(world).values()) } };
  }
  if (op === 'gmopen') {
    if (!p.gmAuthorized) fail('GM battlefield commands require server authorization.', 403);
    const v = data.venues.draco; (world.arenaForcedOpen ||= {}).draco = { startsAt: world.now(), endsAt: world.now() + v.fightSec * 1000 };
    return { arenaResult: arenaState(world, p, data) };
  }
  if (op === 'enter') {
    if (b) fail(T.already);
    const v = data.venues[input.venue] || Object.values(data.venues).find(x => x.job === Number(input.venue));
    if (!v) fail(T.failed);
    npcCheck(world, p, v, input);
    const r = v.key === 'draco' ? await enterDraco(world, p, v, data) : await queueLostHorizon(world, p, v, data);
    return { arenaResult: { ...arenaState(world, p, data), ...r } };
  }
  if (op === 'cancel') {
    const i = queue(world).findIndex(e => e.id === p.id); if (i < 0) fail(T.failed);
    queue(world).splice(i, 1); p.arenaQueued = null; world.changed(p);
    return { arenaResult: { ...arenaState(world, p, data), notice: T.cancelled } };
  }
  if (!b) fail(T.failed);
  if (op === 'commune') { const started = commune(world, p, b); return { arenaResult: { ...arenaState(world, p, data), ...started } }; }
  // leave: during the fight it is desertion (PaneltyStatus); after the result it is Leave Now (160:71)
  await removeParticipant(world, b, p, { penalty: b.phase === 'fight' });
  if (b.phase === 'fight') notify(world, b, 'left', { playerId: p.id });
  return { arenaResult: arenaState(world, p, data) };
}
