// MONSTER CARNIVAL: server-authoritative Forgotten Shipwreck team mode (string cate 161 "Monster Carnival" of
// stringtable_dksquare.txt, the game2/forgottenshipwreck windows, share/forgottenshipwreck/{startcondition,rewardslot}.csv as
// gamedata/dungeons.json forgottenShipwreck). Registrants queue during a native window (DAY / Start_Hour..Finish_Hour, fixed UTC+1);
// StartPCCount of them start one run of MaxPCCount, split into BLUE (161:101) and RED (161:102), inside ONE shared instance of the
// ordinary Forgotten Shipwreck (dungeon 234: floors 234 -> 235 with their native monsters, stats, stages, placement and time
// limit, run unchanged by the dungeon Director). A monster a team member kills earns the team CP (161:3) and score
// (ui_scorewnd); CP buys the six team skills of ui_team_skill_wnd (161:33-38), at most ten uses per team (161:220). The run ends
// at the Nepturos clear, the time limit, a missed floor transfer or an empty team; the higher score wins and every member still
// inside spins the Shipwreck Roulette (161:2, ui_reward_slotwnd) once over the rewardslot.csv win / lose table, durably. Intents
// ride the colosseum command (server/world/colosseum.mjs carnival-* operations); the values the data does not give are
// ENGINE-CHOSEN in src/config/engine-chosen-monster-carnival.js.
import { randomUUID } from 'node:crypto';
import { createInstance, stageInstanceMembers, requestInstanceClose, exitInstance } from './instances.mjs';
import { prepareDungeon } from './dungeons.mjs';
import { dungeonEntranceCosts, consumeDungeonRequirements } from './dungeon-admission-rules.mjs';
import { premiumDungeonFee } from './premium-fees.mjs';
import { AuthoritativeInventory } from './inventory.mjs';
import { serializeLife, commitLife } from './life-transactions.mjs';
import { registerPvpMode } from './pvp.mjs';
import { ensureSkills } from './skills.mjs';
import { sameScene, sceneKey } from './scene.mjs';
import { fishingBusy } from './fishing.mjs';
import { pickRewardSlot } from '../../src/systems/dungeons/reward-slot.js';
import { CARNIVAL_CHOSEN as C } from '../../src/config/engine-chosen-monster-carnival.js';
import { CARNIVAL_TEXT as T, CARNIVAL_SKILLS, CARNIVAL_EFFECTS, CARNIVAL_DUNGEON, CARNIVAL_ATTACK, BLUE, RED, carnivalWindow, fmt } from '../../src/systems/events/monster-carnival-rules.js';

export const CARNIVAL_OPS = Object.freeze(['carnival-register', 'carnival-cancel', 'carnival-skill', 'carnival-spin', 'carnival-exit']);
const SCARLET = 5992, STATUS = Object.freeze({ shock: 7496, breath: 7497 }), METEOR = Object.freeze({ [RED]: 9120, [BLUE]: 9139 });
const fail = (text, status = 400) => { throw Object.assign(new Error(text), { status }); };
const num = v => Number(v) || 0;
const state = world => world.carnival ||= { queue: [], runs: new Map() };
const fsData = world => world.data?.dungeonData?.dg?.forgottenShipwreck || null;
const dungeonOf = world => world.data?.dungeonData?.dg?.dungeons?.[CARNIVAL_DUNGEON] || null;
const live = (world, p) => !!p && world.players.get(p.account) === p && !p.leaving;
const byId = (world, id) => [...world.players.values()].find(q => q.id === id && !q.leaving) || null;
const runOf = (world, p) => (p?.carnivalId && state(world).runs.get(p.carnivalId)) || null;
const memberOf = (run, p) => run?.members.find(m => m.id === p?.id) || null;
/** The live actor of a member while it is inside the run's instance (custody: same character, same run, same instance). */
const inside = (world, run, m) => { const q = m && byId(world, m.id); return q && live(world, q) && q.instanceId === run.instanceId && q.carnivalId === run.id ? q : null; };
const standing = (world, run, m) => { const q = inside(world, run, m); return q && !q.dead && q.hp > 0 ? q : null; };
const mapText = (world, code, fallback) => String(world.data?.dungeonData?.dg?.maps?.[CARNIVAL_DUNGEON]?.messages?.[code]?.t || fallback).replace(/^\s*\[message\]\s*/i, '');
const itemName = (world, item) => world.data?.itemDB?.def?.(item)?.name || `Item ${item}`;
function busy(p) { return !!(p.instanceId || p.duelId || p.partyPvpId || p.tradeId || p.charTradeId || p.sceneTransition || fishingBusy(p) || p.arenaId || p.dkSquareId || p.trainingCampId || p.raceRun || p.pcShopOpen); }
function levelOk(world, p) { const [lo, hi] = dungeonOf(world)?.entry?.levels || [0, 0], lv = num(p.profile.level); return lv >= lo && (!hi || lv <= hi); }
function notice(world, p, text) { p.carnivalNotice = { text, at: world.now() }; world.changed(p); }
/** The native Forgotten Shipwreck Normal Mode entrance of Scarlet (fee + items of its text), or null when the data lacks it. */
function entranceCost(world) { try { return dungeonEntranceCosts(world, CARNIVAL_DUNGEON, SCARLET); } catch { return null; } }
function stagedEntry(world, p, cost) {
  const profile = structuredClone(p.profile), inv = new AuthoritativeInventory(profile, world.data.itemDB, { now: world.now, random: world.random });
  if (!consumeDungeonRequirements(inv, cost.requirements, { first: true })) return { error: T.noTicket };
  const fee = premiumDungeonFee(world, profile, cost.fee); if (inv.dil < fee) return { error: mapText(world, 101, 'Not enough DIL.') };
  inv.addDil(-fee); return { profile };
}
function push(world, run, ev) {
  run.seq++; run.events.push({ seq: run.seq, at: world.now(), ...ev }); if (run.events.length > 24) run.events.shift();
  for (const m of run.members) { const q = byId(world, m.id); if (q && q.carnivalId === run.id) world.changed(q); }
}
function refreshStats(world, q) {
  if (q._skills?.game?.refreshPlayerStats) q._skills.game.refreshPlayerStats();
  else if (typeof world.data?.stats === 'function') { q.stats = world.data.stats(q.profile, q, world.now()); q.maxHp = q.stats.maxHp; q.hp = Math.min(q.hp, q.maxHp); }
  world.changed(q);
}
function status(world, q, index, ms, opts = {}) { try { const sys = ensureSkills(world, q), entry = sys.statuses.add(sys.game.player, index, ms, opts); if (entry) world.changed(q); return !!entry; } catch { return false; } }

// ------------------------------------------------------------------------------------------------ PvP (skill 6 only)
export function carnivalEnemy(world, p, q) {
  const run = runOf(world, p); if (!run || run.phase !== 'run' || !q || q === p || q.carnivalId !== run.id || !sameScene(p, q)) return false;
  const a = memberOf(run, p), b = memberOf(run, q); if (!a || !b || a.team === b.team || a.left || b.left) return false;
  const now = world.now(), cq = run.combat.get(q.id), cp = run.combat.get(p.id);
  return !!((cq && cq.team === a.team && cq.until > now) || (cp && cp.team === b.team && cp.until > now));
}
registerPvpMode({ enemy: carnivalEnemy, opponents: (world, p) => { const run = runOf(world, p); return run ? run.members.map(m => byId(world, m.id)).filter(q => q && !q.dead && carnivalEnemy(world, p, q)) : []; } });

// ------------------------------------------------------------------------------------------------ commands
export async function carnivalCommand(world, p, input) {
  const op = input.operation;
  if (op === 'carnival-register') return register(world, p);
  if (op === 'carnival-cancel') return cancel(world, p);
  if (op === 'carnival-skill') return useSkill(world, p, input);
  if (op === 'carnival-spin') return spinCommand(world, p);
  if (op === 'carnival-exit') return exitRun(world, p);
  fail(T.failed);
}
function register(world, p) {
  const fs = fsData(world), st = state(world);
  if (!fs?.schedule?.length || !dungeonOf(world)) fail(T.noServer, 503);
  if (st.queue.some(e => e.id === p.id)) fail(T.already);
  if (runOf(world, p)) fail(T.entry);
  if (p.colosseumQueue || p.colosseumId) fail(T.colosseum);
  if (!carnivalWindow(fs.schedule, world.now())) fail(T.closed);
  if (p.dead) fail(T.dead);
  if (busy(p)) fail(T.entry);
  if (!levelOk(world, p)) fail(mapText(world, 100, 'Level not high enough.'));
  const cost = entranceCost(world); if (!cost) fail(T.noServer, 503);
  const staged = stagedEntry(world, p, cost); if (staged.error) fail(staged.error);
  st.queue.push({ id: p.id, at: world.now() }); p.carnivalQueue = world.now(); delete p.carnivalNotice; world.changed(p);
  return { registered: true, waiting: st.queue.length };
}
function cancel(world, p) {
  const st = state(world), k = st.queue.findIndex(e => e.id === p.id); if (k < 0) fail(T.noInfo);
  st.queue.splice(k, 1); p.carnivalQueue = null; world.changed(p); return { cancelled: true };
}
async function useSkill(world, p, input) {
  const run = runOf(world, p), mem = memberOf(run, p), s = CARNIVAL_SKILLS.find(x => x.skill === Number(input.skill)), now = world.now();
  if (!run || !mem || mem.left || inside(world, run, mem) !== p) fail(T.noInfo);
  if (run.phase !== 'run' || !s || p.dead || p.hp <= 0 || run.director?.phase !== 'running') fail(T.skillFailed);
  const team = run.teams[mem.team];
  if (team.uses >= C.skillUses) fail(T.maxUses);
  if (team.cp < s.cost) fail(T.noCp);
  const own = run.members.filter(m => m.team === mem.team).map(m => standing(world, run, m)).filter(Boolean);
  const foes = run.members.filter(m => m.team !== mem.team).map(m => standing(world, run, m)).filter(Boolean);
  let target = null; const detail = {};
  if (s.target) { const t = run.members.find(m => m.id === input.target && m.team !== mem.team); target = t ? standing(world, run, t) : null; if (!target) fail(T.badTarget); }
  else if (!['heal', 'attack'].includes(s.kind) && !foes.length) fail(T.badTarget);
  if (s.kind === 'heal') for (const q of own) {
    const hp = Math.min(q.maxHp, q.hp + Math.round(q.maxHp * .5)), mp = Math.min(num(q.stats?.maxMp), num(q.mp) + Math.round(num(q.stats?.maxMp) * .5));
    world.emit(q.map, { type: 'heal', actorId: p.id, targetId: q.id, amount: hp - q.hp }); q.hp = hp; q.mp = mp; world.changed(q);
  } else if (s.kind === 'attack') for (const q of own) { q.carnivalAttackUntil = now + CARNIVAL_ATTACK.ms; refreshStats(world, q); }
  else if (s.kind === 'root') for (const q of foes) status(world, q, STATUS.shock, 5000);
  else if (s.kind === 'seal') for (const q of foes) status(world, q, STATUS.breath, 5000, { blocksSkills: true });
  else if (s.kind === 'random') {
    const pick = ['hit', 'seal2', 'shock2'][Math.min(2, Math.floor(world.random() * 3))], victim = foes[Math.min(foes.length - 1, Math.floor(world.random() * foes.length))];
    Object.assign(detail, { effect: pick, target: victim.id });
    if (pick === 'seal2') status(world, victim, STATUS.breath, 3000, { blocksSkills: true });
    else if (pick === 'shock2') status(world, victim, STATUS.shock, 3000);
    else {
      const melee = world.data.monsterDef?.(METEOR[mem.team])?.attacks?.melee || [0, 0], lo = num(melee[0]), hi = Math.max(lo, num(melee[1]));
      for (let n = 0; n < 3; n++) for (const q of foes.filter(q => sameScene(q, victim) && Math.hypot(q.x - victim.x, q.z - victim.z) <= 3)) {
        if (q.dead || q.hp <= 0) continue;
        const amount = Math.min(Math.max(0, q.hp - 1), Math.round(lo + world.random() * (hi - lo)));
        q.hp -= amount; world.changed(q); world.emit(q.map, { type: 'damage', sourceId: p.id, targetId: q.id, amount, instanceId: q.instanceId });
      }
    }
  } else if (s.kind === 'combat') { run.combat.set(target.id, { team: mem.team, until: now + 20000 }); detail.target = target.id; }
  team.cp -= s.cost; team.uses++;
  push(world, run, { kind: 'skill', skill: s.skill, team: mem.team, by: mem.id, name: mem.name, ...detail });
  return { used: s.skill, cp: team.cp, uses: C.skillUses - team.uses, ...detail };
}
async function spinCommand(world, p) {
  const run = runOf(world, p), mem = memberOf(run, p);
  if (!run || !mem || mem.left || inside(world, run, mem) !== p) fail(T.noInfo);
  if (run.phase === 'run') fail(T.failed);
  if (mem.spun) fail(T.spun);
  if (p.dead || p.hp <= 0) fail(T.spinDead);
  if (num(world.data?.dungeonData?.dg?.maps?.[p.map]?.flags?.peace) === 1) fail(T.safeZone);
  return settleSpin(world, run, mem, p);
}
/** One durable roulette grant: the host fixes the slot at the first attempt; a receipt in the profile stops a replay. */
function settleSpin(world, run, mem, p) {
  const table = fsData(world)?.rewards?.[run.result?.winner === mem.team ? 'win' : 'lose'] || [];
  mem.pick ||= pickRewardSlot(table, world.random);
  if (!mem.pick) fail(T.noInfo);
  const [item, count] = mem.pick.map(Number);
  return serializeLife(p, async () => {
    if (mem.spun) fail(T.spun);
    const profile = structuredClone(p.profile), receipts = (profile.carnival ||= {}).spins ||= [];
    if (receipts.includes(run.id)) { mem.spun = { item, count }; fail(T.spun); }
    const inv = new AuthoritativeInventory(profile, world.data.itemDB, { now: world.now, random: world.random });
    if (!inv.add(item, count)) fail(T.noSpace);
    receipts.push(run.id); if (receipts.length > 32) receipts.shift();
    try { await commitLife(world, p, profile); } catch { fail(T.unknown, 503); }
    mem.spun = { item, count, at: world.now() };
    world.emit(p.map, { type: 'inventory', actorId: p.id, reason: 'carnival' });
    push(world, run, { kind: 'spin', only: mem.id, item, count });
    return { spun: true, item, count, win: run.result?.winner === mem.team, text: fmt(T.received, count, itemName(world, item), T.roulette) };
  });
}
async function exitRun(world, p) {
  const run = runOf(world, p), mem = memberOf(run, p);
  if (!run || !mem) fail(T.noInfo);
  if (run.phase === 'run') fail(T.failed);
  if (inside(world, run, mem) === p) { if (!mem.spun && !mem.left) await settleSpin(world, run, mem, p).catch(() => {}); await exitInstance(world, p); }
  mem.left = true; p.carnivalId = null; world.changed(p);
  return { exited: run.id };
}

// ------------------------------------------------------------------------------------------------ run
async function startRun(world, take, win) {
  const st = state(world), cost = entranceCost(world), ok = [], profiles = [];
  for (const e of take) {
    const p = byId(world, e.id); if (!p || !live(world, p)) continue;
    let why = null, staged = null;
    if (p.dead) why = T.dead; else if (busy(p) || p.colosseumQueue || p.colosseumId) why = T.entry; else if (!levelOk(world, p)) why = mapText(world, 100, 'Level not high enough.');
    else if (!cost) why = T.noServer; else { staged = stagedEntry(world, p, cost); why = staged.error || null; }
    if (why) { p.carnivalQueue = null; notice(world, p, why); continue; }
    ok.push(p); profiles.push(staged.profile);
  }
  if (ok.length < num(win.startPc)) { st.queue.unshift(...ok.map(p => ({ id: p.id, at: p.carnivalQueue || world.now() }))); return false; }
  const d = dungeonOf(world), exit = d.exit?.to?.[0], id = randomUUID();
  const run = { id, phase: 'start', startedAt: world.now(), seq: 0, events: [], combat: new Map(), teams: [BLUE, RED].map(side => ({ side, cp: 0, score: 0, uses: 0 })),
    members: ok.map((p, k) => ({ id: p.id, name: p.profile.name, classIndex: num(p.profile.classIndex), level: num(p.profile.level), team: k % 2 === 0 ? BLUE : RED, kills: 0, score: 0, left: false, spun: null, pick: null })) };
  for (const q of ok) q.sceneTransition = true;
  const staged = stageInstanceMembers(world, ok, profiles); let i;
  try {
    i = await createInstance(staged.world, { map: Number(d.floors[0]), members: staged.candidates, kind: 'dungeon', exit: { map: Number(exit.map), x: Number(exit.x) + .5, z: Number(exit.y) + .5 }, durationMs: Math.max(600000, num(d.expireTime) * 60000) });
    i.admitting = true; i.carnival = id;
    await prepareDungeon(staged.world, i, CARNIVAL_DUNGEON, 0, staged.candidates[0]);
    await world.persistMany(staged.candidates); await staged.commit();
    i.acting = ok[0]; i.admitting = false;
  } catch (error) {
    if (i) { i.director?.dispose(); world.instances.delete(i.id); world.maps.delete(sceneKey(i.map, i.id)); }
    st.queue.unshift(...ok.map(p => ({ id: p.id, at: p.carnivalQueue || world.now() })));
    throw error;
  } finally { for (const q of ok) q.sceneTransition = false; }
  run.instanceId = i.id; run.phase = 'run'; st.runs.set(id, run);
  for (const p of ok) { p.carnivalId = id; p.carnivalQueue = null; delete p.carnivalNotice; world.changed(p); }
  patchDirector(world, run, i); adopt(world, run, i);
  push(world, run, { kind: 'start', effects: [CARNIVAL_EFFECTS.carnival, CARNIVAL_EFFECTS.start] });
  return true;
}
/** The ordinary dungeon's single roulette drop gives way to the team roulette, and its timed close waits for the result. */
function patchDirector(world, run, i) {
  const d = i.director; if (!d || run.director === d) return; run.director = d;
  const sys = d.sys, leave = sys.leave;
  sys.rollRewardList = () => {};
  sys.leave = (director, reason) => {
    if (reason === 'transfer' || reason === 'fail') { if (run.phase === 'run') endRun(world, run, reason === 'transfer' ? 'transfer' : 'time'); return Promise.resolve(); }
    return leave(director, reason);
  };
}
/** Every native monster of the run credits its killer's team: CP and score = its native rank (at least 1). */
function adopt(world, run, i) {
  for (const m of i.scene?.monsters?.values() || []) {
    if (m.dead || m.isBrick || m.kind !== 'monster' || !m.def || ['invisible', 'object'].includes(m.def.role) || m._carnival === run.id) continue;
    m._carnival = run.id; const previous = m.onKilled;
    m.onKilled = killer => { previous?.(killer); credit(world, run, m, killer); };
  }
}
function credit(world, run, m, killer) {
  if (run.phase !== 'run') return;
  const mem = memberOf(run, killer); if (!mem || mem.left || inside(world, run, mem) !== killer) return;
  const value = Math.max(1, num(m.def?.rank)), team = run.teams[mem.team];
  team.cp += value; team.score += value; mem.kills++; mem.score += value;
  for (const q of run.members) { const a = byId(world, q.id); if (a && a.carnivalId === run.id) world.changed(a); }
}
function endRun(world, run, reason) {
  if (run.phase !== 'run') return;
  const present = [BLUE, RED].map(t => run.members.some(m => m.team === t && !m.left)), [b, r] = run.teams.map(t => t.score);
  let winner = null;
  if (present[BLUE] !== present[RED]) winner = present[BLUE] ? BLUE : RED;
  else if (b !== r) winner = b > r ? BLUE : RED;
  run.phase = 'result'; run.endedAt = world.now(); run.closeAt = world.now() + C.resultSec * 1000; run.result = { reason, winner, scores: [b, r] };
  run.combat.clear();
  for (const m of run.members) { const q = byId(world, m.id); if (q?.carnivalAttackUntil) { delete q.carnivalAttackUntil; refreshStats(world, q); } }
  push(world, run, { kind: 'result', reason, winner, effects: [CARNIVAL_EFFECTS.win, CARNIVAL_EFFECTS.lose] });
}
function closeRun(world, run) {
  for (const m of run.members) { const q = byId(world, m.id); if (q && q.carnivalId === run.id) { q.carnivalId = null; if (q.carnivalAttackUntil) { delete q.carnivalAttackUntil; refreshStats(world, q); } world.changed(q); } }
  state(world).runs.delete(run.id);
}
async function stepRun(world, run) {
  const now = world.now(), i = world.instances?.get(run.instanceId);
  if (!i) { closeRun(world, run); return; }
  patchDirector(world, run, i);
  for (const m of run.members) { const q = byId(world, m.id); if (q?.carnivalAttackUntil && q.carnivalAttackUntil <= now) { delete q.carnivalAttackUntil; refreshStats(world, q); } }
  for (const [id, c] of run.combat) if (c.until <= now) run.combat.delete(id);
  if (run.phase === 'run') {
    adopt(world, run, i);
    for (const m of run.members) if (!m.left && !inside(world, run, m) && !byId(world, m.id)?.sceneTransition) m.left = true;
    const d = i.director;
    if (d?.phase === 'cleared' && d.isLastFloor) endRun(world, run, 'clear');
    else if (d?.phase === 'failed') endRun(world, run, 'time');
    else if ([BLUE, RED].some(t => !run.members.some(m => m.team === t && !m.left))) endRun(world, run, 'empty');
    return;
  }
  if (run.phase === 'result') {
    for (const m of run.members) if (!m.left && !inside(world, run, m) && !byId(world, m.id)?.sceneTransition) m.left = true;
    if (now < run.closeAt) return;
    run.phase = 'closing';
    for (const m of run.members) { const q = inside(world, run, m); if (q && !m.spun && !m.left) await settleSpin(world, run, m, q).catch(() => {}); }
  }
  if (run.phase === 'closing') {
    if (run.members.some(m => inside(world, run, m))) { requestInstanceClose(world, i); return; }
    closeRun(world, run);
  }
}
export async function tickCarnival(world) {
  const fs = fsData(world); if (!fs?.schedule?.length || world._carnivalTicking) return;
  world._carnivalTicking = true;   // a run start awaits the store: never run two ticks at once
  try {
    const st = state(world), win = carnivalWindow(fs.schedule, world.now());
    for (let k = st.queue.length - 1; k >= 0; k--) {
      const p = byId(world, st.queue[k].id);
      if (!p || !live(world, p) || !p.carnivalQueue) { st.queue.splice(k, 1); continue; }
      if (!win) { st.queue.splice(k, 1); p.carnivalQueue = null; notice(world, p, T.closed); }
    }
    if (win && st.queue.length >= num(win.startPc)) { const take = st.queue.splice(0, Math.max(num(win.startPc), num(win.maxPc))); try { await startRun(world, take, win); } catch (error) { st.lastError = error?.message || String(error); } }
    for (const run of [...st.runs.values()]) { try { await stepRun(world, run); } catch (error) { st.lastError = error?.message || String(error); } }
  } finally { world._carnivalTicking = false; }
}
/** True while p waits in the lobby or plays / waits in a run (other matchmaking refuses it). */
export function carnivalBusy(world, p) { return !!(p?.carnivalQueue || runOf(world, p)); }

// ------------------------------------------------------------------------------------------------ snapshot
export function carnivalSnapshot(world, p) {
  const fs = fsData(world); if (!fs?.schedule?.length) return null;
  const st = state(world), now = world.now(), win = carnivalWindow(fs.schedule, now), run = runOf(world, p), mem = memberOf(run, p);
  const out = { open: !!win, need: num((win || fs.schedule[0]).startPc), queue: p.carnivalQueue ? { at: p.carnivalQueue, waiting: st.queue.length } : null, notice: p.carnivalNotice || null, run: null };
  if (!run || !mem) return out;
  const d = world.instances?.get(run.instanceId)?.director, own = run.teams[mem.team];
  const remainingMs = run.phase !== 'run' ? Math.max(0, (run.closeAt || now) - now) : d ? Math.max(0, (d.phase === 'countdown' ? d.countdown : d.phase === 'cleared' ? d.transfer : d.phase === 'running' ? d.limit - d.elapsed : 0) * 1000) : 0;
  out.run = { id: run.id, phase: run.phase, dungeonPhase: d?.phase || null, team: mem.team, cp: own.cp, usesLeft: C.skillUses - own.uses, remainingMs,
    teams: run.teams.map(t => ({ cp: t.cp, score: t.score, uses: t.uses })), skills: CARNIVAL_SKILLS.map(s => ({ skill: s.skill, cost: s.cost, icon: s.icon, target: s.target })),
    members: run.members.map(m => ({ id: m.id, name: m.name, classIndex: m.classIndex, level: m.level, team: m.team, kills: m.kills, left: m.left })),
    enemies: run.members.filter(m => m.id !== p.id).map(m => byId(world, m.id)).filter(q => q && carnivalEnemy(world, p, q)).map(q => q.id),
    result: run.result || null, spun: mem.spun || null, left: mem.left, events: run.events.filter(e => !e.only || e.only === p.id) };
  return out;
}
