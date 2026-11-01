// TRAINING-CAMP host: server-authoritative Training Camp (the earlier revision of the DK Square team battle). Windows and
// strings: script/ui/game2/trainingcamp/*.txt, stringtable_dksquare.txt cate 160. Flow (ENGINE-CHOSEN values in
// src/config/engine-chosen-training-camp.js, every PvP number from src/game/pvp-rules.js):
//   lobby list (ui_selectwnd 160:13: No / Lobby Name / Participants / Waiting-In Battle / Join) -> Open Lobby (160:20) or
//   Join (160:23) -> waiting information (ui_waitinginfownd 160:1, Cancel Joining 160:11) while the lobby fills ->
//   when Start (M) participants are in, everybody confirms (ui_confirmwnd 160:25 / 160:48, OK 160:46 / Cancel 160:47;
//   no answer = cancelled, 160:49) -> the confirmed ones are dealt at random to Miseria (160:101) / Ricchez (160:102)
//   (160:2) and enter one battlefield instance (share/arena/field.csv Type 0: map 67, Pos_01 / Pos_02) -> "Eliminate the
//   Enemy" (160:303) for Playtime minutes: hits run the PVP-DUEL pipeline (registerPvpMode), a downed participant returns
//   at the team's Revive_Pos after respawnSec -> result (Battle / Mission / Bonus / Total 160:109-112, WIN / LOSE) ->
//   "moved out of the lobby in %d second(s)" (160:70) or Leave Now (160:71) -> back where each one joined the lobby.
import {fishingBusy} from './fishing.mjs';
import { randomUUID } from 'node:crypto';
import { hostEvents } from './prepared-roots.mjs';
import { partyPvpOutcome } from '../../src/game/pvp-rules.js';
import { TRAINING_CAMP_CHOSEN as C, BATTLE_POINTS_PER_KILL, FINISH_WAIT_SEC, SHIELD_AT_START, missionPoints, battlefieldOf, dealTeams } from '../../src/config/engine-chosen-training-camp.js';
import { registerPvpMode } from './pvp.mjs';
import { createInstance, stageInstanceMembers, requestInstanceClose, exitInstance } from './instances.mjs';
import { sameScene } from './scene.mjs';

export const TRAINING_CAMP_SCHEMAS = { trainingcamp: ['token', 'type', 'operation', 'lobbyId'] };
const OPS = new Set(['open', 'join', 'cancel', 'accept', 'decline', 'leave']);
// Original texts (stringtable_dksquare.txt cate 160) unless marked engine text.
export const TRAINING_CAMP_TEXT = {
  levelLimit: 'Your level is not eligible to enter.',                                         // 160:33
  already: 'You are already waiting in the lobby.',                                           // 160:41 (first line)
  noMore: 'No more lobbies can be opened.',                                                   // 160:45
  full: 'The lobby is full; you cannot join the lobby.',                                      // 160:28
  noLobby: 'No such lobby exists.',                                                           // 160:80
  dead: 'Dead characters cannot enter the lobby.',                                            // 160:81
  busy: 'You are in some condition that prohibits you from entering the lobby. Please abort or finish your current activity, and then try again.', // 160:84
  inBattle: 'A battle is already taking place.',                                              // 160:24 (first line; raid not offered)
  closing: 'You cannot join a battle that is being closed.',                                  // 160:76
  cancelled: 'You have canceled entering the Battlefield.',                                   // 160:49
  someCancelled: 'Some participants have canceled; you cannot enter the arena.',              // 160:98
  cannotLeave: 'You cannot leave right now.',                                                 // 160:72
  failed: 'Failed to execute the command.',                                                   // 160:62
  revive: 'You cannot revive during a Training Camp battle.',                                 // engine text
};
const fail = (message, status = 400) => { throw Object.assign(new Error(message), { status }); };

/** Battlefield of the Training Camp from gamedata/events.json (modes.arena.field = share/arena/field.csv). Without a file: the active
 *  prepared generation's events.json (server/world/prepared-roots.mjs), never a fixed engine/gamedata path (absent on an install). */
export async function loadTrainingCampData(file) { return trainingCampDataFrom(await hostEvents(null, file)); }
export function trainingCampDataFrom(ev) {
  const field = battlefieldOf(ev?.modes?.arena?.field);
  if (!field) throw new Error('Training Camp: share/arena/field.csv Type 0 is missing from gamedata/events.json.');
  return { field };
}
async function dataOf(world) {
  if (world.data?.trainingCamp) return world.data.trainingCamp;
  // this host's loaded event tables (world.data.eventData) first, then its own gamedata root
  if (!world._trainingCampData) world._trainingCampData = hostEvents(world).then(trainingCampDataFrom).catch(error => { world._trainingCampData = null; throw error; });
  return world._trainingCampData;
}
const rulesOf = world => { const r = world.data?.pvpRules; if (!r) fail('PvP rules are unavailable on this host.', 503); return r; };

const lobbies = world => world.trainingCamps ||= new Map();
const live = (world, p) => !!p && world.players.get(p.account) === p && !p.leaving;
const byId = (world, id) => [...world.players.values()].find(q => q.id === id && !q.leaving) || null;
const current = (world, p) => (p?.trainingCampId && lobbies(world).get(p.trainingCampId)) || null;
const teamOf = (l, p) => (l.teams ? l.teams.findIndex(t => t.includes(p.id)) : -1);
const fmt = (s, v) => s.replace(/%[sd]/, String(v));

function notify(world, l, reason, extra = {}) {
  const ids = l.members.map(m => m.id);
  const anyone = ids.map(id => byId(world, id)).find(Boolean);
  if (anyone) world.emit(anyone.map, { type: 'trainingcamp', id: l.id, reason, phase: l.phase, recipients: ids, ...(l.instanceId ? { instanceId: l.instanceId } : {}), ...extra });
}
function setNotice(world, q, reason) { q.trainingCampNotice = { reason, at: world.now() }; world.changed(q); }
function drop(world, l, id, reason) {
  l.members = l.members.filter(m => m.id !== id); l.accepted?.delete(id);
  const q = byId(world, id);
  if (q && q.trainingCampId === l.id) { q.trainingCampId = null; if (reason) setNotice(world, q, reason); else world.changed(q); }
  if (!l.members.length && ['waiting', 'confirm'].includes(l.phase)) lobbies(world).delete(l.id);
}
function busyReason(world, q) {
  if (q.dead) return TRAINING_CAMP_TEXT.dead;
  if (q.duelId || q.partyPvpId || q.instanceId || q.tradeId || fishingBusy(q) || q.mount?.phase === 'on' || q.sceneTransition) return TRAINING_CAMP_TEXT.busy;
  return null;
}
function admit(world, p, l) {
  const busy = busyReason(world, p); if (busy) fail(busy);
  if ((Number(p.profile.level) || 1) < C.minLevel) fail(TRAINING_CAMP_TEXT.levelLimit);
  l.members.push({ id: p.id, joinedAt: world.now(), exit: { map: p.map, x: p.x, z: p.z } });
  p.trainingCampId = l.id; delete p.trainingCampResult; delete p.trainingCampNotice; world.changed(p);
}

/** PvP-mode hooks (server/world/pvp.mjs): an enemy is a participant of the other team, both up, in the battle. */
export function trainingCampEnemy(world, p, q) {
  const l = current(world, p);
  if (!l || l.phase !== 'fight' || !q || q.trainingCampId !== l.id || l.down.has(p.id) || l.down.has(q.id)) return false;
  const a = teamOf(l, p), b = teamOf(l, q);
  return a >= 0 && b >= 0 && a !== b && sameScene(p, q);
}
function trainingCampOpponents(world, p) {
  const l = current(world, p); if (!l || l.phase !== 'fight') return [];
  return l.teams.flat().map(id => byId(world, id)).filter(q => q && trainingCampEnemy(world, p, q) && !q.dead);
}
registerPvpMode({ enemy: trainingCampEnemy, opponents: trainingCampOpponents, onDown: (world, attacker, target) => { const l = current(world, target); if (l?.phase === 'fight') markDown(world, l, target); } });

/** The host revive would leave the battlefield: refused while the participant is in a battle (respawn is automatic). */
export function trainingCampBlocksRevive(world, p) { const l = current(world, p); return !!l && ['fight', 'over'].includes(l.phase) && p.instanceId === l.instanceId; }

const stat = (l, id) => { let s = l.stats.get(id); if (!s) l.stats.set(id, s = { kills: 0, deaths: 0 }); return s; };
function markDown(world, l, q) {
  if (l.down.has(q.id)) return;
  l.down.set(q.id, world.now() + C.respawnSec * 1000);
  q.hp = 0; q.dead = true; q.path = []; world.changed(q);
  stat(l, q.id).deaths++;
  const by = q.pvpLastHit?.by && byId(world, q.pvpLastHit.by);
  if (by && by.trainingCampId === l.id && teamOf(l, by) >= 0 && teamOf(l, by) !== teamOf(l, q)) stat(l, by.id).kills++;
  notify(world, l, 'down', { playerId: q.id, by: by?.id || null });
}

export async function trainingCampCommand(world, p, input) {
  rulesOf(world); await dataOf(world);
  if (!OPS.has(input.operation)) fail('Choose a Training Camp operation.');
  const l = current(world, p);
  if (input.operation === 'open') {
    if (l) fail(TRAINING_CAMP_TEXT.already);
    if (lobbies(world).size >= C.maxLobbies) fail(TRAINING_CAMP_TEXT.noMore);
    const used = new Set([...lobbies(world).values()].map(x => x.no));
    let no = 1; while (used.has(no)) no++;
    const lobby = { id: randomUUID(), no, name: p.profile.name, openerId: p.id, phase: 'waiting', createdAt: world.now(), members: [], accepted: new Set(), stats: new Map(), down: new Map() };
    admit(world, p, lobby); lobbies(world).set(lobby.id, lobby);
    notify(world, lobby, 'open'); return { opened: lobby.id, no };
  }
  if (input.operation === 'join') {
    if (l) fail(TRAINING_CAMP_TEXT.already);
    const target = lobbies(world).get(String(input.lobbyId || ''));
    if (!target) fail(TRAINING_CAMP_TEXT.noLobby);
    if (target.phase === 'over' || target.closing) fail(TRAINING_CAMP_TEXT.closing);
    if (target.phase === 'fight' || target.phase === 'starting') fail(TRAINING_CAMP_TEXT.inBattle);
    if (target.members.length >= C.maxPlayers) fail(TRAINING_CAMP_TEXT.full);
    admit(world, p, target); notify(world, target, 'join', { playerId: p.id });
    return { joined: target.id };
  }
  if (!l) fail(TRAINING_CAMP_TEXT.noLobby);
  if (input.operation === 'cancel') {
    if (!['waiting', 'confirm'].includes(l.phase)) fail(TRAINING_CAMP_TEXT.cannotLeave);
    drop(world, l, p.id, null); notify(world, l, 'cancel', { playerId: p.id }); return { cancelled: l.id };
  }
  if (input.operation === 'accept' || input.operation === 'decline') {
    if (l.phase !== 'confirm') fail(TRAINING_CAMP_TEXT.failed);
    if (input.operation === 'decline') { drop(world, l, p.id, 'cancelled'); notify(world, l, 'cancel', { playerId: p.id }); return { declined: l.id }; }
    l.accepted.add(p.id); for (const m of l.members) { const q = byId(world, m.id); if (q) world.changed(q); }
    return { accepted: l.id };
  }
  // leave (Leave Now 160:71): only once the battle is decided
  if (l.phase !== 'over') fail(TRAINING_CAMP_TEXT.cannotLeave);
  if (p.instanceId === l.instanceId) await exitInstance(world, p);
  p.trainingCampId = null; world.changed(p);
  return { left: l.id };
}

async function start(world, l, data) {
  const rules = rulesOf(world), field = data.field;
  const ps = l.members.map(m => byId(world, m.id)).filter(q => q && live(world, q) && !busyReason(world, q));
  if (ps.length < C.startPlayers) return false;
  const teams = dealTeams(ps.map(q => q.id), () => world.random());
  if (!teams[0].length || !teams[1].length) return false;
  l.phase = 'starting';
  for (const q of ps) q.sceneTransition = true;
  const staged = stageInstanceMembers(world, ps, ps.map(q => structuredClone(q.profile)));
  let instance;
  try {
    instance = await createInstance(staged.world, { map: field.map, members: staged.candidates, kind: 'trainingCamp', exit: undefined, durationMs: (C.playMinutes * 60 + FINISH_WAIT_SEC + 120) * 1000 });
    instance.admitting = true;
    for (const q of staged.candidates) {
      const t = teams[0].includes(q.id) ? 0 : 1, s = field.starts[t], at = instance.scene.nearest(s.x, s.z);
      if (!at) fail('No safe battlefield start exists.', 503);
      q.x = at.x; q.z = at.z; q.profile.instance.exit = l.members.find(m => m.id === q.id)?.exit || world.data.start;
      world.changed(q);
    }
    await world.persistMany(staged.candidates);
    await staged.commit();
    instance.admitting = false;
    for (const q of ps) {
      if (q.profile.instance) q.profile.instance.exit = l.members.find(m => m.id === q.id)?.exit || world.data.start;
      q.hp = q.maxHp; q.mp = q.stats.maxMp || 0; q.shield = SHIELD_AT_START === 'full' ? (Number(q.stats.maxShield) || 0) : 0; q.dead = false; delete q.pvpLastHit; world.changed(q);
    }
  } catch (error) {
    if (instance) { world.instances.delete(instance.id); world.maps.delete(`${instance.map}@${instance.id}`); }
    l.phase = 'waiting'; l.accepted.clear();
    throw error;
  } finally { for (const q of ps) q.sceneTransition = false; }
  const now = world.now();
  for (const m of [...l.members]) if (!ps.some(q => q.id === m.id)) drop(world, l, m.id, 'cancelled');
  Object.assign(l, { phase: 'fight', teams, instanceId: instance.id, startAt: now, endsAt: now + C.playMinutes * 60000, reviveRatio: [rules.reviveHpRatio, rules.reviveMpRatio] });
  notify(world, l, 'start', { endsAt: l.endsAt });
  return true;
}

function points(l, id, outcome, rules) {
  const s = l.stats.get(id) || { kills: 0, deaths: 0 };
  const battle = s.kills * BATTLE_POINTS_PER_KILL, mission = outcome ? missionPoints(rules, outcome) : 0, bonus = C.bonusPoints;
  return { kills: s.kills, deaths: s.deaths, battle, mission, bonus, total: battle + mission + bonus };
}
function teamView(world, l, outcomeOf, rules) {
  return l.teams.map((ids, t) => {
    const members = ids.map(id => { const q = byId(world, id); const present = !!q && live(world, q) && q.instanceId === l.instanceId;
      return { id, name: q?.profile.name || l.names?.get(id) || '', classIndex: q?.profile.classIndex ?? 0, level: q?.profile.level ?? 0, present, down: l.down.has(id), ...points(l, id, outcomeOf?.(t), rules) }; });
    return { team: t, points: members.reduce((n, m) => n + m.battle, 0), present: members.filter(m => m.present).length, members };
  });
}

async function finish(world, l, reason) {
  const rules = rulesOf(world), now = world.now();
  const before = teamView(world, l, null, rules);
  const winner = partyPvpOutcome({ blue: { alive: before[0].present ? 1 : 0, points: before[0].points }, red: { alive: before[1].present ? 1 : 0, points: before[1].points } }, reason);
  const win = winner === 'blue' ? 0 : winner === 'red' ? 1 : -1;
  const outcomeOf = t => (win < 0 ? 'draw' : t === win ? 'win' : 'lose');
  const teams = teamView(world, l, outcomeOf, rules);
  l.phase = 'over'; l.finishAt = now + FINISH_WAIT_SEC * 1000;
  l.result = { winner: win, reason, teams, at: now };
  for (const id of l.teams.flat()) {
    const q = byId(world, id); if (!q || q.trainingCampId !== l.id) continue;
    const t = teamOf(l, q);
    q.trainingCampResult = { ...l.result, team: t, outcome: outcomeOf(t) };
    if (q.instanceId === l.instanceId && (q.dead || q.hp <= 0)) revive(world, l, q, rules, false);
    world.changed(q);
  }
  l.down.clear();
  notify(world, l, 'result', { winner: win, reasonDetail: reason });
}
function revive(world, l, q, rules, relocate) {
  if (relocate) {
    const t = teamOf(l, q), field = l.field, at = field && world.instances?.get(l.instanceId)?.scene?.nearest(field.revives[t].x, field.revives[t].z);
    if (at) { q.x = at.x; q.z = at.z; }
  }
  q.dead = false; q.hp = Math.max(1, Math.round(q.maxHp * rules.reviveHpRatio / 100)); q.mp = Math.round((q.stats.maxMp || 0) * rules.reviveMpRatio / 100); q.path = [];
  q.shield = SHIELD_AT_START === 'full' ? (Number(q.stats.maxShield) || 0) : 0; delete q.pvpLastHit;
  world.changed(q); world.emit(q.map, { type: 'revive', actorId: q.id, instanceId: q.instanceId });
}

export async function tickTrainingCamp(world) {
  if (!world.trainingCamps?.size || !world.data?.pvpRules) return;
  const now = world.now(), rules = world.data.pvpRules;
  let data; try { data = await dataOf(world); } catch { return; }
  for (const l of [...lobbies(world).values()]) {
    if (l.phase === 'starting' || l.ticking) continue;
    l.ticking = true;
    try {
      if (l.phase === 'waiting' || l.phase === 'confirm') {
        for (const m of [...l.members]) { const q = byId(world, m.id); if (!q || !live(world, q) || q.trainingCampId !== l.id || q.instanceId) drop(world, l, m.id, null); }
        if (!lobbies(world).has(l.id)) continue;
        if (l.phase === 'waiting') {
          if (l.members.length >= C.startPlayers) { l.phase = 'confirm'; l.accepted.clear(); l.confirmAt = now; l.confirmEndsAt = now + C.confirmSec * 1000; notify(world, l, 'confirm', { endsAt: l.confirmEndsAt }); for (const m of l.members) { const q = byId(world, m.id); if (q) world.changed(q); } }
          continue;
        }
        const all = l.members.every(m => l.accepted.has(m.id));
        if (!all && now < l.confirmEndsAt) continue;
        for (const m of [...l.members]) if (!l.accepted.has(m.id)) drop(world, l, m.id, 'cancelled');
        if (!lobbies(world).has(l.id)) continue;
        l.names = new Map(l.members.map(m => [m.id, byId(world, m.id)?.profile.name || '']));
        l.field = data.field;
        let started = false;
        if (l.members.length >= C.startPlayers) { try { started = await start(world, l, data); } catch { started = false; } }
        if (!started) {
          l.phase = 'waiting'; l.accepted.clear();
          for (const m of l.members) { const q = byId(world, m.id); if (q) setNotice(world, q, 'someCancelled'); }
          notify(world, l, 'waiting');
        }
        continue;
      }
      if (l.phase === 'fight') {
        for (const id of l.teams.flat()) {
          const q = byId(world, id), inside = !!q && live(world, q) && q.instanceId === l.instanceId;
          if (!inside) { if (q && q.trainingCampId === l.id && !q.instanceId) { q.trainingCampId = null; world.changed(q); } continue; }
          if ((q.hp <= 0 || q.dead) && !l.down.has(id)) markDown(world, l, q);
          else if (l.down.has(id) && now >= l.down.get(id)) { l.down.delete(id); revive(world, l, q, rules, true); notify(world, l, 'respawn', { playerId: id }); }
        }
        const present = l.teams.map(ids => ids.filter(id => { const q = byId(world, id); return q && live(world, q) && q.instanceId === l.instanceId; }).length);
        if (present.some(n => n === 0)) await finish(world, l, 'annihilation');
        else if (now >= l.endsAt) await finish(world, l, 'time');
        continue;
      }
      if (l.phase === 'over') {
        const inside = l.teams.flat().map(id => byId(world, id)).filter(q => q && live(world, q) && q.instanceId === l.instanceId);
        if (now >= l.finishAt) {
          l.closing = true;
          const instance = world.instances?.get(l.instanceId);
          if (instance && inside.length) { requestInstanceClose(world, instance); continue; }
          for (const id of l.teams.flat()) { const q = byId(world, id); if (q && q.trainingCampId === l.id) { q.trainingCampId = null; world.changed(q); } }
          lobbies(world).delete(l.id);
        }
      }
    } finally { l.ticking = false; }
  }
}

export function trainingCampSnapshot(world, p) {
  const list = [...lobbies(world).values()].sort((a, b) => a.no - b.no).map(l => ({ id: l.id, no: l.no, name: l.name, players: l.members.length, max: C.maxPlayers, inBattle: ['starting', 'fight', 'over'].includes(l.phase) }));
  const out = { lobbies: list, lobby: null, result: p.trainingCampResult || null, notice: p.trainingCampNotice || null, rules: { maxPlayers: C.maxPlayers, startPlayers: C.startPlayers, playMinutes: C.playMinutes, confirmSec: C.confirmSec, respawnSec: C.respawnSec, mission: C.missionString } };
  const l = current(world, p); if (!l) return out;
  const rules = world.data?.pvpRules;
  const base = { id: l.id, no: l.no, name: l.name, phase: l.phase, players: l.members.length, max: C.maxPlayers, start: C.startPlayers, playMinutes: C.playMinutes };
  if (l.phase === 'waiting' || l.phase === 'confirm' || l.phase === 'starting') {
    return Object.assign(out, { lobby: { ...base, confirmAt: l.confirmAt || null, confirmEndsAt: l.phase === 'confirm' ? l.confirmEndsAt : null, accepted: l.accepted.has(p.id) } });
  }
  const team = teamOf(l, p), teams = rules ? (l.phase === 'over' ? l.result.teams : teamView(world, l, null, rules)) : [];
  return Object.assign(out, { lobby: { ...base, team, startAt: l.startAt, endsAt: l.endsAt, finishAt: l.finishAt || null, teams, winner: l.result ? l.result.winner : null,
    down: l.down.has(p.id), respawnAt: l.down.get(p.id) || null, inside: p.instanceId === l.instanceId,
    enemies: l.phase === 'fight' && team >= 0 ? l.teams[1 - team].filter(id => !l.down.has(id)) : [] } });
}