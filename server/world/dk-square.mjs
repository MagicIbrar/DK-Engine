// DK-SQUARE host: server-authoritative DK Square (npc job 48 ARENA_SQUARE, npcs 121 Jerome / 720 Kenneth / 5167 Kadie).
// Global parity: data values are used as written (gamedata/events.json modes.arena = share/arena/*.csv); only the gaps are
// ENGINE-CHOSEN (src/config/engine-chosen-dk-square.js). Every PvP hit runs the PVP-DUEL pipeline (registerPvpMode ->
// server/world/pvp.mjs -> src/game/pvp-rules.js); this module never computes damage.
//   Ranks  : conquest.csv Mode 0 rows Rank 7 (Lv.190-229, EnterCost 500000, ActiveScore 13750) / Rank 8 (Lv.230-250,
//            EnterCost 1000000, ActiveScore 22000): StartPCCount 6, MaxPCCount 42, FightTime 1200 s, ConquestWaitTime 300 s,
//            ConquestTime 180 s, CoolTime 30 s, Buff 11009 / BuffTime 180 s, KeepTime 6; rank.csv Max_Room 40.
//   Lobby  : dkschedule.csv hours (160:95) -> DK Square Lobby list (160:13) -> Open Lobby (160:20, 160:45 / 160:96) or Join
//            (160:23, 160:28) -> Waiting Information (160:1) -> StartPCCount in: entry confirmation (160:48) -> dealt at
//            random to Miseria / Ricchez (160:2) -> field.csv Type 0 (map 67, Pos_01 / Pos_02). Joining a lobby In Battle
//            (160:22) raids it (160:24 / 160:79) onto the team with fewer members, up to MaxPCCount (160:300).
//   Battle : Sunstone (npc 5003, job 52) communion, dkactionpoint.csv points, win rule, activity.csv S (Rank 8) / A (Rank 7)
//            settlement, dkkillpoint DP, dktierbuff tier, PaneltyStatus 11067 for leaving: the shared readings of
//            src/systems/arena/arena-rules.js (src/config/engine-chosen-arena.js), with the Mode 0 rank rows.
//   Stones : map 67 IsCreate 0 guardian / protection stone bricks (server/world/team-stones.mjs): the rank's native placement
//            rows stand from the start, only the other squad breaks them, the destroying hit pays Destroy Guardian Stone (300,
//            sub mission 160:302) - never Kill Monster. Outcomes are journaled on each participant's profile before the
//            award write and replayed after a restart (server/world/arena-reward-commit.mjs).
import {fishingBusy} from './fishing.mjs';
import { randomUUID } from 'node:crypto';
import { hostEvents } from './prepared-roots.mjs';
import { DK_SQUARE_CHOSEN as C } from '../../src/config/engine-chosen-dk-square.js';
import { lobbyListRow } from '../../src/config/older-server-ref-dk-square.js';   // older server reference (lobbylist.csv)
import { DK_SQUARE_JOB, DK_SQUARE_TEXT as T, buildDkSquare, rankForLevel, scheduleWindow, openRefusal, dealTeams } from '../../src/systems/pvp/dksquare-rules.js';
import { ARENA_TEXT as AT, ARENA_BROADCAST as B, TEAM_NAME_CODES, SUNSTONE_JOB, parseActivity, parseActionPoints, assignTeam, settle, dkPointFor, tierFor, decideWinner, boardRows, fillAlly } from '../../src/systems/arena/arena-rules.js';
import { registerPvpMode } from './pvp.mjs';
import { grantModeSafeTime } from './wanted.mjs';
import { createInstance, stageInstanceMembers, requestInstanceClose, exitInstance } from './instances.mjs';
import { nearbyNpc } from './npc-services.mjs';
import { sameScene } from './scene.mjs';
import { ensureSkills } from './skills.mjs';
import { AuthoritativeInventory } from './inventory.mjs';
import { progressDekaPass } from './dekapass.mjs';
import { commitArenaReward, journalArenaOutcome, replayArenaOutcomes, refreshArenaStats } from './arena-reward-commit.mjs';
import { questPvpResult } from './quests.mjs';
import { teamStoneRows, spawnTeamStones, releaseTeamStones, teamStoneSnapshot } from './team-stones.mjs';

export const DK_SQUARE_SCHEMAS = { dksquare: ['token', 'type', 'operation', 'lobbyId', 'npcIndex'] };
const OPS = new Set(['list', 'open', 'join', 'cancel', 'accept', 'decline', 'commune', 'revive', 'leave', 'board', 'gmopen']);
const TEAM_NAMES = ['Miseria', 'Ricchez'];   // 160:101 / 160:102
const fail = (message, status = 400) => { throw Object.assign(new Error(message), { status }); };

// Without a file: the active prepared generation's events.json (server/world/prepared-roots.mjs), never a fixed engine/gamedata path.
export async function loadDkSquareData(file) { return dkSquareDataFrom(await hostEvents(null, file)); }
export function dkSquareDataFrom(ev) {
  const a = ev?.modes?.arena || {}, ds = buildDkSquare(a, ev?.maps || {});
  if (!ds || !Object.keys(ds.ranks).length) throw new Error('DK-SQUARE: share/arena conquest Mode 0 / field Type 0 / rank rows are missing from gamedata/events.json.');
  return { ...ds, activity: parseActivity(a.activity), action: parseActionPoints(a.dkActionPoint), killPoint: a.dkKillPoint || [], tiers: a.dkTierBuff || [] };
}
async function dataOf(world) {
  if (world.data?.dkSquare) return world.data.dkSquare;
  // this host's loaded event tables (world.data.eventData) first, then its own gamedata root
  if (!world._dkSquareData) world._dkSquareData = hostEvents(world).then(dkSquareDataFrom).catch(error => { world._dkSquareData = null; throw error; });
  return world._dkSquareData;
}

const lobbies = world => world.dkSquares ||= new Map();
const board = world => world.arenaBoard ||= new Map();   // the DP Score board shared with ARENA (162:1-6)
const live = (world, p) => !!p && world.players.get(p.account) === p && !p.leaving;
const byId = (world, id) => [...world.players.values()].find(q => q.id === id && !q.leaving) || null;
const current = (world, p) => (p?.dkSquareId && lobbies(world).get(p.dkSquareId)) || null;
const teamOf = (l, p) => (l?.teams ? l.teams.findIndex(t => t.includes(p.id)) : -1);
const inside = (world, l, q) => !!q && live(world, q) && !!l.instanceId && q.instanceId === l.instanceId;
const teamName = t => TEAM_NAMES[t] || `Team ${t + 1}`;
const record = p => (p.profile.arena ||= { dp: 0, rankScore: 0, battles: 0, wins: 0 });
const pendingRewards = new WeakMap();
const stat = (l, id) => { let s = l.stats.get(id); if (!s) l.stats.set(id, s = { kills: 0, deaths: 0, points: 0, hits: 0, monsters: 0, moves: 0, stones: 0 }); return s; };
const addPoints = (l, id, key, data) => { const v = data.action.points[key] || 0; if (v) stat(l, id).points += v; };
const battling = l => ['starting', 'fight', 'over'].includes(l.phase);

function notify(world, l, reason, extra = {}) {
  const ids = l.members.map(m => m.id), anyone = ids.map(id => byId(world, id)).find(Boolean);
  if (anyone) world.emit(anyone.map, { type: 'dksquare', id: l.id, reason, phase: l.phase, recipients: ids, ...(l.instanceId ? { instanceId: l.instanceId } : {}), ...extra });
}
function setNotice(world, q, reason) { q.dkSquareNotice = { reason, at: world.now() }; world.changed(q); }
function drop(world, l, id, reason) {
  l.members = l.members.filter(m => m.id !== id); l.accepted.delete(id);
  const q = byId(world, id);
  if (q && q.dkSquareId === l.id) { q.dkSquareId = null; if (reason) setNotice(world, q, reason); else world.changed(q); }
  if (!l.members.length && !battling(l)) lobbies(world).delete(l.id);
}
function windowOf(world, data) {
  const f = world.dkSquareForcedOpen;
  if (f && world.now() < f.endsAt) return { open: true, startsAt: f.startsAt, endsAt: f.endsAt, forced: true };
  return scheduleWindow(data?.schedule || [], world.now());
}
function busyReason(world, q) {
  if (q.dead) return T.dead;
  if (q.arenaQueued || q.arenaId) return T.draco;
  if (q.duelId || q.partyPvpId || q.instanceId || q.tradeId || fishingBusy(q) || q.mount?.phase === 'on' || q.sceneTransition) return T.busy;
  return null;
}
const penalised = (world, p) => (Number(p.profile.arena?.penaltyUntil) || 0) > world.now();
// Global GM command `set_dksquareInfo [mode] [rank] [fightTime] [startPcCount] [maxPcCount] [LobbyIndex]` (client GM help string,
// decompile 64-bit-named strings-xref.csv): the values it gives replace the conquest.csv FightTime / StartPCCount / MaxPCCount of
// that mode + rank for lobbies opened afterwards. LobbyIndex is kept and shown with its older server reference lobbylist.csv row
// (src/config/older-server-ref-dk-square.js; null when that file has no such Index). Nobody is moved by it (lobby maps are not entered).
const infoKey = (mode, rank) => `${Number(mode)}:${Number(rank)}`;
export function dkSquareGm(world, args) {
  const a = (args || []).map(Number);
  if (a.length < 6 || a.some(x => !Number.isFinite(x)) || a[2] <= 0 || a[3] <= 0 || a[4] < a[3]) throw Object.assign(new Error('set_dksquareInfo [mode] [rank] [fightTime] [startPcCount] [maxPcCount] [LobbyIndex]'), { status: 400 });
  (world.dkSquareInfo ||= new Map()).set(infoKey(a[0], a[1]), { fightSec: a[2], startPlayers: a[3], maxPlayers: a[4], lobbyIndex: a[5], lobbyListRow: lobbyListRow(a[5]) });
  return { message: `set_dksquareInfo ${a.join(' ')}` };
}
const venueFor = (world, data, level) => { const v = rankForLevel(data, level); if (!v) return v; const g = world.dkSquareInfo?.get(infoKey(v.mode, v.rank)); return g ? { ...v, ...g } : v; };
function admissible(world, p, data, opening) {
  if (!windowOf(world, data).open) fail(T.closed);
  const v = venueFor(world, data, p.profile.level); if (!v) fail(T.level);
  if (penalised(world, p)) fail(opening ? T.berserkOpen : T.berserkJoin);
  const busy = busyReason(world, p); if (busy) fail(busy);
  if ((Number(p.profile.dil) || 0) < v.enterCost) fail(T.dil);
  return v;
}
function npcCheck(world, p, input) {
  const opts = { jobType: DK_SQUARE_JOB, radius: C.npcRadius, ...(Number.isInteger(input.npcIndex) ? { npcIndex: input.npcIndex } : {}) };
  if (!nearbyNpc(world, p, opts)) fail('Talk to the DK Square NPC first.');
}
function applyPenalty(world, p, data) {
  const ms = data.activity.penaltySec * 1000; if (!(ms > 0)) return;
  record(p).penaltyUntil = world.now() + ms;
  try { const { statuses, game } = ensureSkills(world, p); statuses.add(game.player, data.activity.penaltyStatus, ms, { source: game.player }); } catch { /* status packs optional */ }
  world.changed(p);
}

// ---- PvP-mode hooks: an enemy is a participant of the other team, both up, inside the battlefield during the fight
export function dkSquareEnemy(world, p, q) {
  const l = current(world, p);
  if (!l || l.phase !== 'fight' || !q || q.dkSquareId !== l.id || l.down.has(p.id) || l.down.has(q.id)) return false;
  const a = teamOf(l, p), b = teamOf(l, q);
  return a >= 0 && b >= 0 && a !== b && sameScene(p, q);
}
function dkSquareOpponents(world, p) {
  const l = current(world, p); if (!l || l.phase !== 'fight') return [];
  return l.teams.flat().map(id => byId(world, id)).filter(q => q && dkSquareEnemy(world, p, q) && !q.dead);
}
const TRAVEL_TYPES = new Set(['travel', 'smartwarp', 'mapnpcwarp', 'npctravel', 'channel']);
function dkSquareGuard(world, p, input) {
  const l = current(world, p); if (!l || !input || !inside(world, l, p)) return;
  if (input.type === 'revive' && (l.phase === 'fight' || l.phase === 'over')) fail(T.revive);
  if (l.phase === 'fight' && TRAVEL_TYPES.has(input.type)) fail(T.cannotLeave);
}
registerPvpMode({ enemy: dkSquareEnemy, opponents: dkSquareOpponents, guard: dkSquareGuard,
  onDown: (world, attacker, target) => { const l = current(world, target); if (l?.phase === 'fight') markDown(world, l, target); } });

function markDown(world, l, q) {
  if (l.down.has(q.id)) return;
  l.down.set(q.id, world.now());
  q.hp = 0; q.dead = true; q.path = []; world.changed(q);
  stat(l, q.id).deaths++; addPoints(l, q.id, 'dead', l.data);
  if (l.sun.communing?.id === q.id) stopCommunion(world, l, 'dead');
  const by = q.pvpLastHit?.by && byId(world, q.pvpLastHit.by);
  if (by && by.dkSquareId === l.id && teamOf(l, by) >= 0 && teamOf(l, by) !== teamOf(l, q)) { stat(l, by.id).kills++; addPoints(l, by.id, 'killPc', l.data); }
  notify(world, l, 'down', { playerId: q.id, by: by?.id || null });
}
function revive(world, l, q, relocate) {
  const rules = world.data.pvpRules || { reviveHpRatio: 100, reviveMpRatio: 100 };
  if (relocate) { const t = teamOf(l, q), sq = l.v.squads[t], at = sq && world.instances?.get(l.instanceId)?.scene?.nearest(sq.revive.x, sq.revive.z); if (at) { q.x = at.x; q.z = at.z; } }
  q.dead = false; q.hp = Math.max(1, Math.round(q.maxHp * rules.reviveHpRatio / 100)); q.mp = Math.round((q.stats.maxMp || 0) * rules.reviveMpRatio / 100); q.path = []; delete q.pvpLastHit;
  l.down.delete(q.id); world.changed(q); world.emit(q.map, { type: 'revive', actorId: q.id, instanceId: q.instanceId });
  if (relocate) grantModeSafeTime(world, q, 'arena');
}

// ---- lobby
function newLobby(world, p, v, data, no) {
  return { id: randomUUID(), no, rank: v.rank, v, data, name: p.profile.name, openerId: p.id, phase: 'waiting', createdAt: world.now(), members: [], accepted: new Set(),
    teams: null, names: new Map(), classes: new Map(), stats: new Map(), down: new Map(), instanceId: null, everTeams: new Set(), lastSeq: 0,
    sun: { owner: -1, since: null, communing: null, blocked: v.squads.map(() => 0) }, result: null };
}
function admit(world, p, l, raid = false) {
  l.members.push({ id: p.id, joinedAt: world.now(), exit: { map: p.map, x: p.x, z: p.z }, ...(raid ? { raid: true } : {}) });
  p.dkSquareId = l.id; delete p.dkSquareResult; delete p.dkSquareNotice; world.changed(p);
}
const rankLobbies = (world, rank) => [...lobbies(world).values()].filter(l => l.rank === rank && l.phase !== 'over');
const presentCount = (world, l) => (l.teams ? l.teams.flat().filter(id => inside(world, l, byId(world, id))).length : 0);
const exitOf = (l, id, world) => l.members.find(m => m.id === id)?.exit || world.data.start;

async function stageInto(world, l, ps) {
  const v = l.v; for (const q of ps) q.sceneTransition = true;
  const staged = stageInstanceMembers(world, ps, ps.map(q => structuredClone(q.profile)));
  let instance = l.instanceId ? world.instances?.get(l.instanceId) : null, created = false;
  try {
    for (const q of staged.candidates) { if ((Number(q.profile.dil) || 0) < v.enterCost) fail(T.dil); q.profile.dil = (Number(q.profile.dil) || 0) - v.enterCost; }
    if (!instance) {
      instance = await createInstance(staged.world, { map: v.map, members: staged.candidates, kind: 'dkSquare', exit: undefined, });
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
      const t = teamOf(l, q), s = v.squads[t].start, at = instance.scene.nearest(s.x, s.z);
      if (!at) fail('No safe battlefield start exists.', 503);
      q.x = at.x; q.z = at.z; q.profile.instance.exit = exitOf(l, q.id, world);
      world.changed(q); if (!created) staged.world.emit(q.map, { type: 'join', actorId: q.id });
    }
    await world.persistMany(staged.candidates);
    await staged.commit();
    instance.admitting = false;
    for (const q of ps) {
      if (q.profile.instance) q.profile.instance.exit = exitOf(l, q.id, world);
      q.hp = q.maxHp; q.mp = q.stats.maxMp || 0; q.dead = false; delete q.pvpLastHit; world.changed(q);
      const s = stat(l, q.id); s.lastPos = { x: q.x, z: q.z }; s.moveAt = world.now();
    }
  } catch (error) {
    if (created && instance) { world.instances.delete(instance.id); world.maps.delete(`${instance.map}@${instance.id}`); }
    else if (instance) { instance.admitting = false; for (const q of ps) instance.members.delete(q.id); }
    throw error;
  } finally { for (const q of ps) q.sceneTransition = false; }
  return instance;
}
async function start(world, l) {
  const v = l.v;
  const ps = l.members.map(m => byId(world, m.id)).filter(q => q && live(world, q) && !busyReason(world, q) && (Number(q.profile.dil) || 0) >= v.enterCost);
  if (ps.length < v.startPlayers) return false;
  const teams = dealTeams(ps.map(q => q.id), () => world.random());
  if (!teams[0].length || !teams[1].length) return false;
  l.phase = 'starting'; l.teams = teams; l.endsAt = null;
  for (const q of ps) { l.names.set(q.id, q.profile.name); l.classes.set(q.id, q.profile.classIndex); }
  try { const instance = await stageInto(world, l, ps); l.instanceId = instance.id; placeStones(world, l, instance); }
  catch (error) { l.phase = 'waiting'; l.teams = null; l.accepted.clear(); throw error; }
  const now = world.now();
  for (const m of [...l.members]) if (!ps.some(q => q.id === m.id)) drop(world, l, m.id, 'cancelled');
  teams.forEach((ids, t) => { if (ids.length) l.everTeams.add(t); });
  Object.assign(l, { phase: 'fight', startAt: now, endsAt: now + v.fightSec * 1000, lastSeq: world.sequence || 0 });
  notify(world, l, 'start', { endsAt: l.endsAt });
  return true;
}
async function raidIn(world, l, q) {
  const counts = l.teams.map(ids => ids.filter(id => inside(world, l, byId(world, id))).length), t = assignTeam(counts);
  l.teams[t].push(q.id); l.names.set(q.id, q.profile.name); l.classes.set(q.id, q.profile.classIndex); l.everTeams.add(t);
  try { await stageInto(world, l, [q]); }
  catch (error) { l.teams[t] = l.teams[t].filter(id => id !== q.id); throw error; }
  const m = l.members.find(x => x.id === q.id); if (m) delete m.raid;
  notify(world, l, 'join', { playerId: q.id, team: t });
}

// ---- guardian / protection stones (map 67 IsCreate 0 bricks; rows per rank: engine-chosen-dk-square.js stoneUids)
function placeStones(world, l, instance) {
  const rows = teamStoneRows(world, l.v.map, C.stoneUids?.[l.rank] || []);
  l.stones = spawnTeamStones(world, { battle: l, instance, rows, squadOfAlly: ally => l.v.squads.findIndex(s => s.ally === ally), teamOf: q => teamOf(l, q),
    onDestroyed: (w, p, m) => { stat(l, p.id).stones++; addPoints(l, p.id, 'destroyStone', l.data); notify(w, l, 'stone', { playerId: p.id, team: m.teamStone.team, stoneId: m.id, uid: m.uid }); } });
}

// ---- Sunstone communion (npc 5003, job 52)
function stopCommunion(world, l, why) {
  const c = l.sun.communing; if (!c) return; l.sun.communing = null;
  l.sun.blocked[c.team] = world.now() + l.v.coolSec * 1000;
  notify(world, l, 'communion-stopped', { playerId: c.id, team: c.team, why, text: AT.stopped, broadcast: fillAlly(B.failedTeam, teamName(c.team), l.names.get(c.id) || '') });
}
function commune(world, p, l) {
  const v = l.v, now = world.now();
  if (l.phase !== 'fight' || !v.sunstone || !inside(world, l, p)) fail(AT.unavailable);
  if (now < l.startAt + v.conquestWaitSec * 1000) fail(AT.unavailable);
  if (p.dead || l.down.has(p.id)) fail(T.failed);
  if (!nearbyNpc(world, p, { npcIndex: v.sunstone.npc, jobType: SUNSTONE_JOB, radius: v.radius }) && Math.hypot(p.x - v.sunstone.x, p.z - v.sunstone.z) > v.radius) fail('Move closer to the Sunstone.');
  const t = teamOf(l, p);
  if (l.sun.owner === t) fail(AT.ownStone);
  if (l.sun.communing) fail(l.sun.communing.id === p.id ? AT.communing : AT.someoneElse);
  if (now < l.sun.blocked[t]) fail(AT.blocked);
  if (stat(l, p.id).points < l.data.action.minReward) fail(AT.needScore);
  l.sun.communing = { id: p.id, team: t, startAt: now, endsAt: now + v.conquestSec * 1000, x: p.x, z: p.z, hp: p.hp };
  notify(world, l, 'communion', { playerId: p.id, team: t, endsAt: l.sun.communing.endsAt, text: AT.communing, broadcast: fillAlly(B.trying, teamName(t)) });
  return { communing: l.sun.communing.endsAt };
}
function tickCommunion(world, l) {
  const c = l.sun.communing; if (!c) return;
  const q = byId(world, c.id);
  if (!q || !inside(world, l, q) || q.dead || l.down.has(q.id)) return stopCommunion(world, l, 'gone');
  if (Math.hypot(q.x - c.x, q.z - c.z) > 0) return stopCommunion(world, l, 'moved');   // any movement (engine-chosen-arena communionMoveTolerance removed, f pass)
  if (q.hp < c.hp) return stopCommunion(world, l, 'hit');
  if (world.now() < c.endsAt) return;
  l.sun.communing = null; l.sun.owner = c.team; l.sun.since = world.now();
  for (const id of l.teams[c.team]) {
    const m = byId(world, id); if (!inside(world, l, m)) continue;
    try { const { statuses, game } = ensureSkills(world, m); statuses.add(game.player, l.v.buff, l.v.buffSec * 1000, { source: game.player }); world.changed(m); } catch { /* status packs optional */ }
  }
  notify(world, l, 'occupied', { playerId: c.id, team: c.team, text: AT.conquered, broadcast: fillAlly(B.occupied, teamName(c.team)) });
}
// ---- points from host events (Hit Skill PC / Kill Monster) and movement (dkactionpoint.csv)
function scanEvents(world, l) {
  const ids = new Set(l.teams.flat()), stones = new Set((l.stones || []).map(m => m.id)); let last = l.lastSeq;
  for (const e of world.events || []) {
    if (!(e.sequence > l.lastSeq)) continue; last = Math.max(last, e.sequence);
    if (e.instanceId !== l.instanceId || e.type !== 'damage' || e.miss || !ids.has(e.sourceId)) continue;
    const src = byId(world, e.sourceId); if (!src) continue;
    if (ids.has(e.targetId)) { if (e.skillId != null && teamOf(l, src) !== teamOf(l, { id: e.targetId })) { stat(l, src.id).hits++; addPoints(l, src.id, 'hitSkill', l.data); } }
    // a stone's destruction is Destroy Guardian Stone (paid once by team-stones onDestroyed), never Kill Monster
    else if (e.dead && !stones.has(e.targetId) && ![...world.players.values()].some(x => x.id === e.targetId)) { stat(l, src.id).monsters++; addPoints(l, src.id, 'killMonster', l.data); }
  }
  l.lastSeq = last;
}
function tickMoves(world, l, q) {
  const s = stat(l, q.id), now = world.now(), every = l.data.action.moveSec * 1000;
  if (!s.lastPos) { s.lastPos = { x: q.x, z: q.z }; s.moveAt = now; return; }
  if (!(every > 0) || now - s.moveAt < every) return;
  if (!q.dead && Math.hypot(q.x - s.lastPos.x, q.z - s.lastPos.z) > 0) { s.moves++; addPoints(l, q.id, 'move', l.data); }
  s.lastPos = { x: q.x, z: q.z }; s.moveAt = now;
}

// ---- settlement
function teamView(world, l) {
  return (l.teams || []).map((ids, t) => {
    const members = ids.map(id => { const q = byId(world, id), s = l.stats.get(id) || { kills: 0, deaths: 0, points: 0 };
      return { id, name: l.names.get(id) || q?.profile.name || '', classIndex: l.classes.get(id) ?? q?.profile.classIndex ?? 0, level: q?.profile.level ?? 0,
        present: inside(world, l, q), down: l.down.has(id), kills: s.kills, deaths: s.deaths, points: s.points }; });
    return { team: t, name: teamName(t), nameCode: TEAM_NAME_CODES[t], points: members.reduce((a, m) => a + m.points, 0), present: members.filter(m => m.present).length, members };
  });
}
async function finish(world, l, reason) {
  if (l.phase !== 'fight') return;
  if (l.sun.communing) stopCommunion(world, l, 'end');
  const now = world.now(), data = l.data, teams = teamView(world, l);
  const win = decideWinner(teams, l.sun, reason), outcomeOf = t => (win < 0 ? 'draw' : t === win ? 'win' : 'lose');
  l.phase = 'over'; l.finishAt = null;   // Lane 71: 160:70 timed move-out REMOVED (no source for its seconds); participants leave with Leave Now (160:71)
  const entries = [];
  for (const id of l.teams.flat()) {
    const q = byId(world, id); if (!inside(world, l, q)) continue;
    const t = teamOf(l, q), s = stat(l, id), outcome = outcomeOf(t);
    const st = settle({ activity: data.activity, rank: l.rank, points: s.points, outcome, minReward: data.action.minReward });
    entries.push({actor:q,done:false,journaled:false,reward:{battle:l.id,venue:'dkSquare',rank:l.rank,map:l.v.map,reason,winner:win,team:t,outcome,points:s.points,kills:s.kills,deaths:s.deaths,stones:s.stones,...st,dpGain:dkPointFor(s.kills,data.killPoint),at:now}});
  }
  l.result = { winner: win, reason, teams, at: now };
  l.down.clear(); releaseTeamStones(l.stones);
  pendingRewards.set(l,{entries,published:false});
  await settleRewards(world,l);
}
// DekaPass / quest credit of one DK Square outcome (live settlement and restart replay alike).
const dkCredit=reward=>(facade,actor)=>{
  progressDekaPass(facade,actor,3,16,0,1);
  if(reward.outcome==='win')progressDekaPass(facade,actor,3,20,0,1);
  questPvpResult(facade,actor,{venue:'dkSquare',outcome:reward.outcome,kills:reward.kills},{profile:actor.profile,emit:false})?.commit();
};
async function settleRewards(world,l) {
  const pending=pendingRewards.get(l);if(!pending)return true;
  // Durable before any award: each present participant's frozen outcome is journaled on its own profile first.
  await Promise.all(pending.entries.filter(e=>!e.done&&!e.journaled&&live(world,e.actor)&&byId(world,e.actor.id)===e.actor)
    .map(async e=>{try{e.journaled=!!await journalArenaOutcome(world,e.actor,e.reward);}catch(error){e.error=error?.message||String(error);}}));
  for(const entry of pending.entries){
    if(entry.done)continue;
    const q=entry.actor;
    // gone: a journaled outcome is paid by replayDkSquare at the character's next presence
    if(!live(world,q)||byId(world,q.id)!==q){entry.done=true;continue;}
    if(!entry.journaled)continue;
    try {
      const r=await commitArenaReward(world,q,entry.reward,dkCredit(entry.reward));
      entry.done=true;if(!r||!live(world,q))continue;
      refreshArenaStats(world,q);
      const tier=tierFor(r.dp,l.data.tiers,l.rank);
      if(inside(world,l,q)&&(q.dead||q.hp<=0))revive(world,l,q,false);
      q.dkSquareResult={...r,tier,teams:l.result.teams};
      board(world).set(q.id,{id:q.id,name:q.profile.name,classIndex:q.profile.classIndex,level:q.profile.level,dp:r.dp,tier:tier?.name||null,rank:l.rank});
      world.changed(q);
    }catch(error){entry.error=error?.message||String(error);}
  }
  if(pending.entries.some(e=>!e.done))return false;
  if(!pending.published){pending.published=true;const {winner,reason}=l.result;
    notify(world,l,'result',{winner,reasonDetail:reason,...(winner<0?{}:{winnerName:teamName(winner)})});}
  return true;
}
async function removeParticipant(world, l, q, { penalty = false } = {}) {
  if (l.sun.communing?.id === q.id) stopCommunion(world, l, 'left');
  if (inside(world, l, q)) { if (q.dead || q.hp <= 0) revive(world, l, q, false); await exitInstance(world, q); }
  if (penalty) applyPenalty(world, q, l.data);
  l.members = l.members.filter(m => m.id !== q.id);
  q.dkSquareId = null; world.changed(q);
}

// Journaled DK Square outcomes no live settlement owns (host restart, gone before the award write): paid once, now.
function replayDkSquare(world) {
  replayArenaOutcomes(world, 'dkSquare', { owns: r => r.venue === 'dkSquare', credit: dkCredit,
    live: (r, p) => { const l = lobbies(world).get(r.battle), e = l && pendingRewards.get(l)?.entries.find(x => x.actor === p); return !!e && !e.done; },
    done: (p, r, reward) => { refreshArenaStats(world, p); const data = world.data?.dkSquare || world._dkSquareDataSync, tier = data ? tierFor(r.dp, data.tiers, reward.rank) : null;
      p.dkSquareResult = { ...r, tier, teams: [], replayed: true };
      board(world).set(p.id, { id: p.id, name: p.profile.name, classIndex: p.profile.classIndex, level: p.profile.level, dp: r.dp, tier: tier?.name || null, rank: reward.rank }); world.changed(p); } });
}
export async function tickDkSquare(world) {
  if (!world._dkSquareTicking && world.data?.pvpRules) replayDkSquare(world);
  if (world._dkSquareTicking || !world.dkSquares?.size || !world.data?.pvpRules) return;
  world._dkSquareTicking = true;
  try {
    const now = world.now();
    for (const l of [...lobbies(world).values()]) {
      if (l.phase === 'starting') continue;
      if (l.phase === 'waiting' || l.phase === 'confirm') {
        for (const m of [...l.members]) { const q = byId(world, m.id); if (!q || !live(world, q) || q.dkSquareId !== l.id || q.instanceId) drop(world, l, m.id, null); }
        if (!lobbies(world).has(l.id)) continue;
        if (l.phase === 'waiting') {
          if (l.members.length >= l.v.startPlayers) { l.phase = 'confirm'; l.accepted.clear(); l.confirmAt = now; l.confirmEndsAt = null; /* Lane 71: the 160:48 '(%d)' countdown is REMOVED (no source for its seconds); the window waits for every OK / Cancel */ notify(world, l, 'confirm', { endsAt: l.confirmEndsAt }); for (const m of l.members) { const q = byId(world, m.id); if (q) world.changed(q); } }
          continue;
        }
        if (!l.members.every(m => l.accepted.has(m.id))) continue;
        for (const m of [...l.members]) if (!l.accepted.has(m.id)) drop(world, l, m.id, 'cancelled');
        if (!lobbies(world).has(l.id)) continue;
        let started = false;
        if (l.members.length >= l.v.startPlayers) { try { started = await start(world, l); } catch { started = false; } }
        if (!started) { l.phase = 'waiting'; l.accepted.clear(); for (const m of l.members) { const q = byId(world, m.id); if (q) setNotice(world, q, 'someCancelled'); } notify(world, l, 'waiting'); }
        continue;
      }
      if (l.phase === 'fight') {
        // raiders: accepted -> into the battlefield (the 160:79 answer countdown is REMOVED - no source for its seconds: no timeout; Cancel = 160:49)
        for (const m of l.members.filter(x => x.raid)) {
          const q = byId(world, m.id);
          if (!q || !live(world, q) || q.dkSquareId !== l.id) { drop(world, l, m.id, null); continue; }
          if (l.accepted.has(m.id)) { if (presentCount(world, l) >= l.v.maxPlayers || busyReason(world, q)) { drop(world, l, m.id, 'someCancelled'); continue; } try { await raidIn(world, l, q); } catch { drop(world, l, m.id, 'someCancelled'); } }
        }
        scanEvents(world, l);
        for (const id of l.teams.flat()) {
          const q = byId(world, id);
          if (!inside(world, l, q)) { if (q && q.dkSquareId === l.id && !q.instanceId && !q.sceneTransition) { q.dkSquareId = null; l.members = l.members.filter(m => m.id !== id); applyPenalty(world, q, l.data); } continue; }
          if ((q.hp <= 0 || q.dead) && !l.down.has(id)) markDown(world, l, q);
          else if (l.down.has(id) && now - l.down.get(id) >= C.autoExitSec * 1000) { l.down.delete(id); await removeParticipant(world, l, q).catch(() => {}); notify(world, l, 'removed', { playerId: id }); continue; }
          tickMoves(world, l, q);
        }
        tickCommunion(world, l);
        const present = l.teams.map(ids => ids.filter(id => inside(world, l, byId(world, id))).length);
        if (!present.some(Boolean)) { l.phase = 'over'; l.finishAt = now; l.result = { winner: -1, reason: 'empty', teams: teamView(world, l), at: now }; }
        else if (l.sun.owner >= 0 && now - l.sun.since >= l.v.keepMin * 60000) await finish(world, l, 'keep');
        else if (l.everTeams.size > 1 && present.filter(Boolean).length === 1) await finish(world, l, 'alone');
        else if (now >= l.endsAt) await finish(world, l, 'time');
        continue;
      }
      if (l.phase === 'over' && !await settleRewards(world,l)) continue;
      if (l.phase === 'over') {
        const left = l.teams.flat().map(id => byId(world, id)).filter(q => inside(world, l, q)), instance = world.instances?.get(l.instanceId);
        if (left.length) continue;
        l.closing = true; if (instance) requestInstanceClose(world, instance);
        for (const m of l.members) { const q = byId(world, m.id); if (q && q.dkSquareId === l.id) { q.dkSquareId = null; world.changed(q); } }
        lobbies(world).delete(l.id);
      }
    }
  } finally { world._dkSquareTicking = false; }
}

// ---- state
function battleOf(world, l, p) {
  const t = teamOf(l, p), s = l.stats.get(p.id) || { points: 0, kills: 0, deaths: 0 }, v = l.v;
  return { id: l.id, venue: 'dkSquare', rank: l.rank, map: v.map, phase: l.phase, team: t, teamName: t >= 0 ? teamName(t) : null, startAt: l.startAt, endsAt: l.endsAt, finishAt: l.finishAt || null,
    teams: l.phase === 'over' && l.result ? l.result.teams : teamView(world, l), winner: l.result ? l.result.winner : null, reason: l.result?.reason || null,
    me: { points: s.points, kills: s.kills, deaths: s.deaths, stones: s.stones || 0, down: l.down.has(p.id), downAt: l.down.get(p.id) || null, autoExitAt: l.down.has(p.id) ? l.down.get(p.id) + C.autoExitSec * 1000 : null },
    activeScore: v.activeScore, missions: v.missions, title: v.title, inside: inside(world, l, p), stones: teamStoneSnapshot(l.stones, t),
    sun: { owner: l.sun.owner, ownerName: l.sun.owner >= 0 ? teamName(l.sun.owner) : null, since: l.sun.since, keepMin: v.keepMin, keepEndsAt: l.sun.owner >= 0 ? l.sun.since + v.keepMin * 60000 : null,
      opensAt: (l.startAt || 0) + v.conquestWaitSec * 1000, communing: l.sun.communing ? { id: l.sun.communing.id, team: l.sun.communing.team, startAt: l.sun.communing.startAt, endsAt: l.sun.communing.endsAt } : null,
      blockedUntil: t >= 0 ? l.sun.blocked[t] : 0, x: v.sunstone?.x, z: v.sunstone?.z, radius: v.radius },
    enemies: l.phase === 'fight' && t >= 0 ? l.teams.flatMap((ids, i) => (i === t ? [] : ids.filter(id => !l.down.has(id)))) : [] };
}
export function dkSquareSnapshot(world, p) {
  const data = world.data?.dkSquare || world._dkSquareDataSync || null;
  const v = data ? venueFor(world, data, p.profile.level) : null, w = data ? windowOf(world, data) : { open: false };
  const rec = p.profile.arena || {};
  const out = { open: !!w.open, startsAt: w.startsAt ?? null, endsAt: w.endsAt ?? null,
    rank: v ? { rank: v.rank, minLevel: v.minLevel, maxLevel: v.maxLevel, enterCost: v.enterCost, maxPlayers: v.maxPlayers, startPlayers: v.startPlayers, fightSec: v.fightSec, maxRooms: v.maxRooms, missions: v.missions } : null,
    lobbies: v ? rankLobbies(world, v.rank).sort((a, b) => a.no - b.no).map(l => ({ id: l.id, no: l.no, name: l.name, players: battling(l) ? presentCount(world, l) : l.members.length, max: l.v.maxPlayers, inBattle: battling(l), closing: !!l.closing || l.phase === 'over' })) : [],
    lobby: null, battle: null, result: p.dkSquareResult || null, notice: p.dkSquareNotice || null,
    record: { dp: rec.dp || 0, rankScore: rec.rankScore || 0, battles: rec.battles || 0, wins: rec.wins || 0, penaltyUntil: rec.penaltyUntil || 0, tier: data && v ? tierFor(rec.dp || 0, data.tiers, v.rank) : null },
    minReward: data?.action.minReward || 0 };
  const l = current(world, p); if (!l) return out;
  const m = l.members.find(x => x.id === p.id);
  out.lobby = { id: l.id, no: l.no, name: l.name, rank: l.rank, phase: l.phase, players: battling(l) ? presentCount(world, l) : l.members.length, max: l.v.maxPlayers, start: l.v.startPlayers,
    playMinutes: Math.round(l.v.fightSec / 60), missions: l.v.missions, enterCost: l.v.enterCost, confirmAt: l.phase === 'confirm' ? l.confirmAt : (m?.raid ? m.joinedAt : null),
    confirmEndsAt: null, raid: !!m?.raid, accepted: l.accepted.has(p.id) };
  if (l.teams && teamOf(l, p) >= 0) out.battle = battleOf(world, l, p);
  return out;
}

export async function dkSquareCommand(world, p, input) {
  if (!world.data?.pvpRules) fail('PvP rules are unavailable on this host.', 503);
  const data = await dataOf(world); world._dkSquareDataSync = data;
  const op = input.operation || 'list'; if (!OPS.has(op)) fail('Choose a DK Square operation.');
  const l = current(world, p), state = extra => ({ ...dkSquareSnapshot(world, p), ...extra });
  if (op === 'list') return state();
  if (op === 'board') {
    const own = p.profile.arena, v = rankForLevel(data, p.profile.level);
    if (own) board(world).set(p.id, { id: p.id, name: p.profile.name, classIndex: p.profile.classIndex, level: p.profile.level, dp: own.dp || 0, tier: tierFor(own.dp || 0, data.tiers, v?.rank ?? 8)?.name || null });
    return state({ board: boardRows(board(world).values()) });
  }
  if (op === 'gmopen') {
    if (!p.gmAuthorized) fail('GM DK Square commands require server authorization.', 403);
    world.dkSquareForcedOpen = { startsAt: world.now(), endsAt: world.now() + 2 * 3600000 };
    return state();
  }
  if (op === 'open') {
    if (l) fail(T.already);
    npcCheck(world, p, input);
    const v = admissible(world, p, data, true), why = openRefusal(rankLobbies(world, v.rank), v);
    if (why) fail(T[why]);
    const used = new Set(rankLobbies(world, v.rank).map(x => x.no)); let no = 1; while (used.has(no)) no++;
    const lobby = newLobby(world, p, v, data, no); admit(world, p, lobby); lobbies(world).set(lobby.id, lobby);
    notify(world, lobby, 'open'); return state({ opened: lobby.id, no });
  }
  if (op === 'join') {
    if (l) fail(T.already);
    npcCheck(world, p, input);
    const target = lobbies(world).get(String(input.lobbyId || '')); if (!target) fail(T.noLobby);
    const v = admissible(world, p, data, false);
    if (target.rank !== v.rank) fail(T.level);
    if (target.phase === 'over' || target.closing) fail(T.closing);
    if (target.phase === 'starting') fail(T.failed);
    if (target.phase === 'fight') {
      if (presentCount(world, target) + target.members.filter(m => m.raid).length >= target.v.maxPlayers) fail(T.battleFull);
      admit(world, p, target, true); notify(world, target, 'raid', { playerId: p.id });
      return state({ raiding: target.id });
    }
    if (target.members.length >= target.v.maxPlayers) fail(T.full);
    admit(world, p, target); notify(world, target, 'join', { playerId: p.id });
    return state({ joined: target.id });
  }
  if (!l) fail(T.noLobby);
  const m = l.members.find(x => x.id === p.id);
  if (op === 'cancel') {
    if (l.phase !== 'waiting' && l.phase !== 'confirm' && !m?.raid) fail(T.cannotLeave);
    drop(world, l, p.id, null); notify(world, l, 'cancel', { playerId: p.id }); return state({ left: l.id });
  }
  if (op === 'accept' || op === 'decline') {
    if (!(l.phase === 'confirm' || m?.raid)) fail(T.failed);
    if (op === 'decline') { drop(world, l, p.id, 'cancelled'); notify(world, l, 'decline', { playerId: p.id }); return state(); }
    l.accepted.add(p.id); world.changed(p); notify(world, l, 'accept', { playerId: p.id }); return state();
  }
  if (op === 'commune') return state(commune(world, p, l));
  if (op === 'revive') {
    if (!l.down.has(p.id) || l.phase !== 'fight' || !inside(world, l, p)) fail(T.failed);
    revive(world, l, p, true); notify(world, l, 'respawn', { playerId: p.id }); return state();
  }
  // leave: during the fight it is desertion (PaneltyStatus); after the result it is Leave Now (160:71)
  if (!inside(world, l, p)) fail(T.cannotLeave);
  const fighting = l.phase === 'fight';
  await removeParticipant(world, l, p, { penalty: fighting });
  if (fighting) notify(world, l, 'left', { playerId: p.id });
  return state();
}
