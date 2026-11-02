import {attackPreferenceRefusal} from './gameplay-preferences.mjs';
import {pkSafeTimeActive} from './wanted.mjs';
// PVP-DUEL: server-authoritative 1:1 duel + player-vs-player damage (rules: src/game/pvp-rules.js).
// Flow (original windows/strings): request (pcpop 240:5 Duel) -> pvp_ask on the target (280:14, Accept/Decline) while the
// requester waits (pvp_acceptwait 280:5, Cancel) -> countdown (pvp_countui 1008:8 + N 1008:10) -> fight inside the limited
// area around the duel flag -> result (pvpbattlewnd 280:8 Winner / 280:16 Loser, 280:9 / 280:10 points) -> the loser
// resurrects at the spot with pvp_restore (280:4 Reincarnate). Refusal: 30 s re-request delay (1008:16).
import {fishingBusy} from './fishing.mjs';
import fs from 'node:fs/promises';
import path from 'node:path';
import { randomUUID } from 'node:crypto';
import { buildPvpRules, parseFormulaIni, parsePcclass, pvpDamage, duelPoints, withinBox } from '../../src/game/pvp-rules.js';
import {criticalChance,criticalDamageMultiplier,modifyHitDamage} from '../../src/game/combat.js';
import { sameScene, mapFor } from './scene.mjs';
import { attackReady, nextAttackAt, playerAttackLimit } from '../../src/game/attack-timing.js';
import { divideShare } from './damage-share.mjs';
import { applyAbilityCap, capAttackerUsesBlock1 } from '../../src/game/ability-cap.js';

export const PVP_SCHEMAS = { pvp: ['token', 'type', 'operation', 'targetId'] };
const OPS = new Set(['request', 'accept', 'decline', 'cancel', 'restore']);
const fail = (message, status = 400) => { throw Object.assign(new Error(message), { status }); };
// Messages are the original string table texts (stringtable_pvp.txt cate 1008 / 280).
export const PVP_TEXT = {
  far: 'The opponent is too far away.',                       // 1008:1
  reach: 'You are too far away from the opponent.',           // 1008:9 (attack out of reach)
  busy: 'The opponent is already in a match.',                // 1008:2
  cancelled: 'The match request has been cancelled.',         // 1008:4
  declined: 'The opponent declined your match request.',      // 1008:7
  wait: 'Please try again in 30 seconds.',                    // 1008:16
  condition: 'This character is not in a condition for fighting.', // 1008:17
  self: 'You are currently in a PvP battle.',                 // 1008:26
  area: 'You cannot participate in PvP or Party Matches while in this area.', // 280:106
  dead: 'That character is already dead!',                    // 280:105
};

export async function loadPvpRules(dataRoot) {
  const [formula, pcclass] = await Promise.all([
    fs.readFile(path.join(dataRoot, 'share', 'formula.ini'), 'latin1'),
    fs.readFile(path.join(dataRoot, 'share', 'pc', 'pcclass.csv'), 'latin1'),
  ]);
  return buildPvpRules(parseFormulaIni(formula), parsePcclass(pcclass));
}

const duels = world => world.duels ||= new Map();
const rulesOf = world => { const r = world.data?.pvpRules; if (!r) fail('PvP rules are unavailable on this host.', 503); return r; };
const live = (world, p) => !!p && world.players.get(p.account) === p && !p.leaving && !p.sceneTransition;
const dist = (a, b) => Math.hypot(a.x - b.x, a.z - b.z);
const current = (world, p) => (p?.duelId && duels(world).get(p.duelId)) || null;
const other = (duel, p) => duel.players.find(q => q !== p);
const pvpProfile = p => (p.profile.pvp ||= { points: 0, wins: 0, losses: 0, draws: 0 });
function notify(world, duel, reason, extra = {}) {
  world.emit(duel.players[0].map, { type: 'pvp', id: duel.id, reason, phase: duel.phase, recipients: duel.players.map(q => q.id), ...extra });
}
function condition(world, p) {
  if (p.dead) return PVP_TEXT.dead;
  if (p.tradeId || p.mount?.phase === 'on' || fishingBusy(p) || p.instanceId || (p.gmAuthorized && p.profile.gm?.hide)) return PVP_TEXT.condition;
  return null;
}
export function pvpAllowedOn(map, row = map?.row) { return Number(row?.IsPvP) === 1; }

/** The duel opponent p may attack right now (fight phase), or null. */
export function duelOpponent(world, p) {
  const duel = current(world, p);
  return duel && duel.phase === 'fight' ? other(duel, p) : null;
}
export function isDuelTarget(world, p, q) { return !!q && duelOpponent(world, p) === q; }

// Other PvP modes (PARTY-PVP: server/world/party-pvp.mjs) register {enemy(world, p, q), opponents(world, p), onDown?(world, attacker, target)}.
// Registration can run through a native event import cycle before this module
// finishes evaluating. A hoisted lazy registry preserves those early modes.
var MODES;
function pvpModes(){return MODES ||= [];}
export function registerPvpMode(mode) { if (!pvpModes().includes(mode)) pvpModes().push(mode); return mode; }
/** q is a player p may hit right now (duel opponent or an enemy of another PvP mode). */
export function isPvpTarget(world, p, q) {
  if (!q || q === p || attackPreferenceRefusal(world,p,q)) return false;
  // Duels are exempt from Safe Time / NonPK (consensual; stringtable_helper PvP vs PK).
  if (isDuelTarget(world, p, q)) return true;
  // Mode + field NonPK: formula.ini *NonPKTime — neither side may hit while protected.
  if (pkSafeTimeActive(world, p) || pkSafeTimeActive(world, q)) return false;
  return pvpModes().some(m => m.enemy(world, p, q));
}
/** Every player p may hit right now. */
/** Action guards of the PvP modes (e.g. no revive while downed in a final battle); called by core through partyPvpGuard. */
export function pvpModeGuard(world, p, input) { for (const m of pvpModes()) m.guard?.(world, p, input); }
/** A PvP hit left target at 0 HP: the duel ends, or every mode's onDown runs (basic attacks and skills alike). */
export async function pvpDowned(world, attacker, target) {
  if (isDuelTarget(world, attacker, target)) return finish(world, current(world, attacker), attacker, target, 'defeated');
  for (const m of pvpModes()) await m.onDown?.(world, attacker, target);
}
/** FIELD-PK (server/world/field-pk.mjs): SOURCE (lane 51 g, FINAL 64-bit decompile) GameUser::EventHandler::Command::Force::State::PK
 *  (ctor 0x7ff670988480 keeps the target id and a forced byte; check FUN_7ff670988550 reads that byte, no timer): the forced flag
 *  belongs to the attack / cast command itself. A forced command arms p; the next command without the flag disarms it. */
export function noteForcedIntent(world, p, forced = true) { p.pkForced = forced === true; delete p.pkForcedAt; }
export function pvpOpponents(world, p) {
  const d = duelOpponent(world, p);
  const out = [];
  if (d && !attackPreferenceRefusal(world, p, d)) out.push(d);
  if (!pkSafeTimeActive(world, p)) {
    for (const m of pvpModes()) for (const q of m.opponents(world, p) || []) {
      if (q && !attackPreferenceRefusal(world, p, q) && !pkSafeTimeActive(world, q)) out.push(q);
    }
  }
  return out;
}

function clear(world, duel) {
  duels(world).delete(duel.id);
  for (const q of duel.players) if (q.duelId === duel.id) q.duelId = null;
}
function cancel(world, duel, reason) {
  clear(world, duel); notify(world, duel, reason);
  const at = world.now();
  duel.players.forEach((q, i) => { q.pvpNotice = { reason, at, requester: i === 0 }; world.changed(q); });
}

async function finish(world, duel, winner, loser, reason) {
  if (duel.phase === 'over') return;
  const rules = rulesOf(world), now = world.now();
  duel.phase = 'over'; clear(world, duel);
  if (!winner) {
    for (const q of duel.players) { pvpProfile(q).draws++; q.pvpResult = { result: 'draw', gain: 0, loss: 0, total: pvpProfile(q).points, at: now, opponent: other(duel, q).profile.name }; world.changed(q); }
  } else {
    const wp = pvpProfile(winner), lp = pvpProfile(loser);
    const { winnerGain, loserLoss, limited } = duelPoints(rules, { level: winner.profile.level, points: wp.points }, { level: loser.profile.level, points: lp.points });
    wp.points += winnerGain; wp.wins++; lp.points -= loserLoss; lp.losses++;
    winner.pvpResult = { result: 'win', gain: winnerGain, loss: 0, total: wp.points, at: now, limited, opponent: loser.profile.name };
    loser.pvpResult = { result: 'lose', gain: 0, loss: loserLoss, total: lp.points, at: now, limited, opponent: winner.profile.name };
    // The loser resurrects at the spot (stringtable_helper) through pvp_restore after the DeadRestoreWnd wait
    // (restoreWaitSec 15, FINAL 64-bit decompile FUN_7ff670cfcbb0; src/game/pvp-rules.js).
    loser.hp = 0; loser.dead = true; loser.path = [];
    loser.pvpRestore = { at: now + rules.restoreWaitSec * 1000, x: loser.x, z: loser.z, map: loser.map };
    world.changed(winner); world.changed(loser);
  }
  notify(world, duel, 'result', { reasonDetail: reason, winnerId: winner?.id || null, loserId: loser?.id || null });
  const keep = duel.players.filter(q => live(world, q));
  try { await world.persistMany(keep); } catch { for (const q of keep) await world.persist(q).catch(() => {}); }
}

export async function pvpCommand(world, p, input) {
  const rules = rulesOf(world), now = world.now();
  if (!OPS.has(input.operation)) fail('Choose a PvP operation.');
  const duel = current(world, p);
  if (input.operation === 'restore') {
    const r = p.pvpRestore;
    if (!r || !p.dead) fail('There is nothing to restore.');
    if (now < r.at) fail('Wait for the PvP respawn.', 429);
    delete p.pvpRestore;
    p.dead = false; p.hp = Math.max(1, Math.round(p.maxHp * rules.reviveHpRatio / 100)); p.mp = Math.round((p.stats.maxMp || 0) * rules.reviveMpRatio / 100);
    p.path = []; world.changed(p);
    world.emit(p.map, { type: 'revive', actorId: p.id });
    await world.persist(p);
    return { restored: true };
  }
  if (input.operation === 'request') {
    if (duel) fail(PVP_TEXT.self);
    const target = [...world.players.values()].find(q => q.id === input.targetId);
    if (!target || target === p || !live(world, target) || !sameScene(target, p)) fail('Choose a character on your map.');
    if (!pvpAllowedOn(mapFor(world, p), world.data.mapRow?.(p.map) ?? mapFor(world, p)?.row)) fail(PVP_TEXT.area);
    const own = condition(world, p); if (own) fail(own);
    const theirs = condition(world, target); if (theirs) fail(theirs);
    if (current(world, target)) fail(PVP_TEXT.busy);
    if (!withinBox(p, target, rules.requestRange)) fail(PVP_TEXT.far);   // OnRequest 0x61fd20 per-axis box
    const refusals = world.duelRefusals ||= new Map(), key = `${p.id}>${target.id}`;
    if ((refusals.get(key) || 0) > now) fail(PVP_TEXT.wait, 429);
    const id = randomUUID();
    const d = { id, players: [p, target], phase: 'invited', map0: p.map, createdAt: now, expiresAt: now + rules.acceptTimeoutSec * 1000 };
    duels(world).set(id, d); p.duelId = id; target.duelId = id;
    notify(world, d, 'request', { requesterId: p.id, requesterName: p.profile.name, points: pvpProfile(p).points });
    return { requested: id };
  }
  if (!duel) fail('There is no PvP request.');
  if (input.operation === 'cancel') {
    if (duel.phase !== 'invited' || duel.players[0] !== p) fail('Only a waiting request can be cancelled.');
    cancel(world, duel, 'cancelled'); return { cancelled: duel.id };
  }
  if (duel.players[1] !== p || duel.phase !== 'invited') fail('There is no PvP request to answer.');
  if (input.operation === 'decline') {
    (world.duelRefusals ||= new Map()).set(`${duel.players[0].id}>${p.id}`, now + rules.reRequestSec * 1000);
    cancel(world, duel, 'declined'); return { declined: duel.id };
  }
  // accept
  const [a, b] = duel.players;
  if (!live(world, a) || !sameScene(a, b)) { cancel(world, duel, 'cancelled'); fail(PVP_TEXT.cancelled); }
  if (condition(world, a) || condition(world, b)) { cancel(world, duel, 'cancelled'); fail(PVP_TEXT.condition); }
  if (!withinBox(a, b, rules.requestRange)) { cancel(world, duel, 'cancelled'); fail(PVP_TEXT.far); }
  duel.phase = 'countdown'; duel.startAt = now + rules.countdownSec * 1000;
  duel.flag = { x: (a.x + b.x) / 2, z: (a.z + b.z) / 2 }; duel.outside = new Map();
  for (const q of duel.players) { delete q.pvpResult; if (rules.shieldAtStart === 'full') q.shield = Number(q.stats.maxShield) || 0; world.changed(q); }
  notify(world, duel, 'accepted', { startAt: duel.startAt, flag: duel.flag });
  return { accepted: duel.id };
}

/** Host basic attack on a player target. Returns true when handled. */
export async function pvpAttack(world, p, target, now, step) {
  const rules = rulesOf(world);
  if (!isPvpTarget(world, p, target)) fail('You can only attack your PvP opponent during the match.');
  if (p.dead || target.dead) fail(PVP_TEXT.dead);
  const map = mapFor(world, p);
  // Reach = the weapon's own range from the data (itemweapon range -> stats.attackRange, src/game/progression.js), no engine cap or
  // fallback; +0.5 is a JUDGMENT (lane 51 g): the same body tolerance the host uses for monster reach (core.mjs).
  if (dist(p, target) > (Number(p.stats.attackRange) || 0) + 0.5) fail(PVP_TEXT.reach);
  if (map?.collision?.lineOfSight && !map.collision.lineOfSight(p.x, p.z, target.x, target.z)) fail('An obstacle blocks this attack.');
  const limit = playerAttackLimit(world.data, p);   // the data's combo cadence (src/game/attack-timing.js)
  if (!attackReady(p.attackAt, now, limit.burstMs)) fail('Attack is cooling down.', 429);
  if (Math.hypot(target.x - p.x, target.z - p.z) > 1e-6) p.yaw = Math.atan2(-(target.x - p.x), -(target.z - p.z));
  p.attackAt = nextAttackAt(p.attackAt, now, limit.intervalMs);
  p.lastCombat = now; target.lastCombat = now; p.path = [];
  p._skills?.statuses.onAttack(p._skills.game.player);
  // ENGINE-DEFAULT (configurable): fallback minimum 20 only when stats.attackMin is 0/absent; no Global source.
  const lo = p.stats.attackMin || 20, hi = p.stats.attackMax || lo;
  let raw = Math.max(1, lo + world.random() * (hi - lo));
  const chance=criticalChance(p,target,Number(p.stats.critRate)||0),crit=chance>0&&world.random()*100<chance;
  const elementBase=raw;   // Global Melee calculator: element terms scale the weapon roll A (MATH-VERIFY row 7)
  if(crit)raw*=criticalDamageMultiplier(p,target,Number(p.stats.critMultiplier)||1);
  raw=modifyHitDamage(p,target,raw,{round:false,...((p.stats.attackType||'melee')!=='magic'?{elementBase}:{})});
  const hit = pvpHit(world, p, target, raw, p.stats.attackType || 'melee');
  world.emit(p.map, { type: 'attack', actorId: p.id, targetId: target.id, ...(Number.isInteger(step) ? { variant: step } : {}) });
  world.emit(p.map, { type: 'damage', sourceId: p.id, targetId: target.id, amount: hit.amount + hit.shieldDamage, shieldDamage: hit.shieldDamage, dead: target.hp === 0, ...(hit.block ? { block: true } : {}), ...(hit.guard ? { guard: true } : {}), ...(hit.miss ? { miss: true } : {}), ...(hit.immune ? { immune: true } : {}), ...(crit ? {crit:true}:{}), pvp: true });
  for (const m of pvpModes()) m.onHit?.(world, p, target);
  if (target.hp === 0) await pvpDowned(world, p, target);
  return hit;
}

/** Apply one PvP hit (basic attack or a skill's raw amount) to target: shield first, then HP. */
function pvpDefender(target){
  const owner=target._skills?.game?.player,servant=owner&&target._skills?.summons?.servantOf(owner);
  const owned=servant&&owner&&servant.owner===owner&&!servant.dead&&!servant.disposed&&servant.hp>0?servant:null;
  return {classIndex:target.profile.classIndex,level:target.profile.level,stats:target.stats,shield:target.shield,classDef:target.classDef,statuses:target.profile.buffs,_skills:target._skills,ownedServant:owned};
}
function sharePvpDamage(defender,hit){if(hit.sharedDamage>0&&defender.ownedServant)defender.ownedServant.hp=Math.max(1,defender.ownedServant.hp-hit.sharedDamage);}
// Divide Pain / Force (src/systems/skills/damage-share.js): the protected player's caster takes sharePct of what the protected
// player is about to suffer. In a fight the caster must stand on the protected player's side (the hitter is among the
// caster's opponents), so a third party outside a duel never receives it. The shield then absorbs only the remainder.
function divideShareHit(world,attacker,target,hit){
  const suffered=hit.amount+hit.shieldDamage;if(!(suffered>0))return;
  const shared=divideShare(world,target,{amount:suffered,attacker,context:caster=>pvpOpponents(world,caster).includes(attacker)});
  if(!(shared.part>0))return;
  const shieldDamage=Math.min(Math.max(0,Number(target.shield)||0),shared.kept);
  hit.shieldDamage=shieldDamage;hit.amount=shared.kept-shieldDamage;hit.dividedDamage=shared.part;
}
// MATH-VERIFY 4.3.2 row 14: Global applies the map ability cap (levelcap) to PC->PC hits too - Calculator 0x596890 has no
// defender-type check and a PC attacker (vt+0x28 = 0) selects block 1. Miss ends the hit; the Blocking / Guard columns feed avoidance.
function pvpCap(world, attacker, target, amount, kind) {
  return applyAbilityCap(world.data?.abilityCap?.(attacker.map), { attackerLevel: attacker.profile.level, defenderLevel: target.profile.level,
    attackerIsPlayer: capAttackerUsesBlock1('pc'), kind: kind === 'magic' ? 'magic' : 'melee' }, amount, () => world.random());
}
export function pvpHit(world, attacker, target, raw, kind) {
  const rules = rulesOf(world);
  const defender=pvpDefender(target);
  const cap = pvpCap(world, attacker, target, raw, kind);
  if (cap.miss) { target.pvpLastHit = { by: attacker.id, at: world.now() }; return { amount: 0, shieldDamage: 0, block: false, guard: false, miss: true, ...(cap.immune ? { immune: true } : {}) }; }
  const hit = pvpDamage(rules, {
    attacker: { classIndex: attacker.profile.classIndex, level: attacker.profile.level, stats: attacker.stats, classDef:attacker.classDef,statuses:attacker.profile.buffs,_skills:attacker._skills },
    defender,
    raw: cap.amount, kind, random: () => world.random(), cap,
  });
  sharePvpDamage(defender,hit);
  divideShareHit(world,attacker,target,hit);
  target.shield = Math.max(0, (Number(target.shield) || 0) - hit.shieldDamage);
  target.hp = Math.max(0, target.hp - hit.amount); target.pvpLastHit = { by: attacker.id, at: world.now() };
  world.changed(target);
  return hit;
}

/** beforeDamage hook of the host skill engine: a skill hit on the duel opponent runs the PvP stages (shield first). */
export function pvpSkillAdjust(world, attacker, target, result) {
  if(attackPreferenceRefusal(world,attacker,target)){result.amount=0;result.shieldDamage=0;result.miss=true;return result;}
  // Per-skill PCDamageRate (combo CSV PCDamageRate / binary U16 @ SkillCombo+0x38 ->
  // skill step r.pvpDamageRate via build-skills; skillDamage copies onto result).
  // elitepvpers PvE thread + CSV column: PvP skill damage ~= amount * (PCDamageRate/100).
  // Applied BEFORE abilityCap / fPCDamageRatio / share. rate<=0 leaves amount alone.
  // Lane 05: audit/pvp-rate-census.json, EVIDENCE-SOURCES.md.
  {
    const rate = Number(result?.pvpDamageRate) || 0;
    if (rate > 0 && Number(result.amount) > 0) {
      result.amount = Math.max(0, Math.floor(Number(result.amount) * rate / 100));
    }
  }
  const rules = rulesOf(world);
  const defender=pvpDefender(target);
  const skillKind = ['magic','range'].includes(result.kind) ? result.kind : 'melee';
  const cap = pvpCap(world, attacker, target, Number(result.amount) || 0, skillKind);
  if (cap.miss) { result.amount = 0; result.shieldDamage = 0; result.miss = true; result.crit = false; result.pvp = true; if (cap.immune) result.immune = true; return { amount: 0, shieldDamage: 0, block: false, guard: false, miss: true, ...(cap.immune ? { immune: true } : {}) }; }
  const hit = pvpDamage(rules, {
    attacker: { classIndex: attacker.profile.classIndex, level: attacker.profile.level, stats: attacker.stats,classDef:attacker.classDef,statuses:attacker.profile.buffs,_skills:attacker._skills },
    defender, cap,
    raw: cap.amount, kind: ['magic','range'].includes(result.kind) ? result.kind : 'melee', random: () => world.random(), defenceApplied: true,
    element: result.element || null, elementShare: result.elementShare,
  });
  sharePvpDamage(defender,hit);
  divideShareHit(world,attacker,target,hit);
  target.shield = Math.max(0, (Number(target.shield) || 0) - hit.shieldDamage);
  result.amount = hit.amount; result.shieldDamage = hit.shieldDamage; result.pvp = true; result.block = hit.block; result.guard = hit.guard; target.pvpLastHit = { by: attacker.id, at: world.now() };
  world.changed(target);
  for (const m of pvpModes()) m.onHit?.(world, attacker, target);
  // a lethal skill hit: the skill engine applies the amount right after this hook, then the modes see the down
  if ((Number(target.hp) || 0) - hit.amount <= 0) queueMicrotask(() => { if (target.hp <= 0) pvpDowned(world, attacker, target).catch(() => {}); });
  return hit;
}

export async function tickPvp(world) {
  const rules = world.data?.pvpRules; if (!rules) return;
  const now = world.now();
  for (const duel of [...duels(world).values()]) {
    const [a, b] = duel.players;
    const gone = duel.players.find(q => !live(world, q)) || (!sameScene(a, b) ? (duel.players.find(q => q.map !== duel.map0) || b) : null);
    if (duel.phase === 'invited') {
      if (gone || now >= duel.expiresAt) cancel(world, duel, gone ? 'cancelled' : 'expired');
      continue;
    }
    if (gone) { await finish(world, duel, other(duel, gone), gone, 'left'); continue; }
    if (duel.phase === 'countdown') {
      if (now >= duel.startAt) { duel.phase = 'fight'; duel.endsAt = null; /* no duel timer (older server reference) */ notify(world, duel, 'start', { endsAt: duel.endsAt, flag: duel.flag, radius: rules.areaRadius }); }
      continue;
    }
    if (duel.phase !== 'fight') continue;
    const down = duel.players.find(q => q.hp <= 0 || q.dead);
    if (down) { await finish(world, duel, other(duel, down), down, 'defeated'); continue; }
    let forfeit = null;
    for (const q of duel.players) {
      if (!withinBox(q, duel.flag, rules.areaRadius)) {   // OnCheckRange 0x61f170 per-axis box
       if (!duel.outside.has(q.id)) { duel.outside.set(q.id, now); notify(world, duel, 'outside', { playerId: q.id, until: now + rules.outsideForfeitSec * 1000 }); } else if (now - duel.outside.get(q.id) >= rules.outsideForfeitSec * 1000) forfeit = q; }
      else if (duel.outside.delete(q.id)) notify(world, duel, 'inside', { playerId: q.id });
    }
    if (forfeit) { await finish(world, duel, other(duel, forfeit), forfeit, 'area'); continue; }
  }
}

export function pvpSnapshot(world, p) {
  const duel = current(world, p), points = p.profile.pvp || { points: 0, wins: 0, losses: 0, draws: 0 };
  const out = { points: { ...points }, restoreAt: p.pvpRestore?.at || null, result: p.pvpResult || null, notice: p.pvpNotice || null };
  if (duel) {
    const q = other(duel, p);
    Object.assign(out, { id: duel.id, phase: duel.phase, incoming: duel.phase === 'invited' && duel.players[1] === p,
      opponent: { id: q.id, name: q.profile.name, level: q.profile.level, points: (q.profile.pvp?.points) || 0 },
      createdAt: duel.createdAt, expiresAt: duel.expiresAt || null, startAt: duel.startAt || null, endsAt: duel.endsAt || null, flag: duel.flag || null,
      radius: world.data?.pvpRules?.areaRadius ?? null, outsideSince: duel.outside?.get(p.id) || null });
  }
  return out;
}
