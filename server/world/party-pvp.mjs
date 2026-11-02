// PARTY-PVP: server-authoritative Party Match between two parties (rules: src/game/pvp-rules.js PARTY_PVP_CHOSEN,
// arenas: share/article/partypvp.csv). Flow with the original windows/strings:
//   request (pcpop 240:8 "Party PvP" on the other party's leader) -> ui_partypvpask on that leader (280:17, Accept /
//   Decline) while the requester waits (ui_partypvpacceptwait 280:19, Cancel) -> both parties get ui_partypvp_battlewnd:
//   the BLUE leader sets MODE 280:30 / MAP 280:31 / Entry Fee 280:32 / Time Limit of Battle 280:33 (280:60-62) and every
//   participant presses Start (280:36); Withdraw (280:37, ui_partypvpcancel 280:47) ends it -> when all are ready the
//   two parties enter one arena instance (fees paid), wait WaitTime (csv), fight until a team is wiped out or the time
//   limit -> ui_partypvp_resultwnd (BLUE/RED 280:22/23, Total Points 280:24, Survived 280:25, Prize Money 280:27,
//   WINNER 280:78/79 / DRAW 280:80) -> "Waiting to finish" (280:51) -> everybody returns revived.
// Player-vs-player hits use the PVP-DUEL pipeline (server/world/pvp.mjs pvpAttack / pvpSkillAdjust) through
// registerPvpMode; Annihilation stays down, while Buff Mode permits authored skill resurrection.
import {fishingBusy} from './fishing.mjs';
import fs from 'node:fs/promises';
import path from 'node:path';
import { randomUUID } from 'node:crypto';
import { PARTY_PVP_CHOSEN as C, ENGINE_CHOSEN, parsePartyPvpCsv, partyPvpOutcome, partyPvpPrize } from '../../src/game/pvp-rules.js';
import { registerPvpMode, pvpAllowedOn, pvpModeGuard, PVP_TEXT } from './pvp.mjs';
import { createInstance, stageInstanceMembers, requestInstanceClose,exitInstance } from './instances.mjs';
import { sameScene, mapFor } from './scene.mjs';
import { colosseumItemGuard } from './colosseum.mjs';
import {parsePartyPvpBuffs,selectPartyPvpBuff,applyPartyPvpBuffs,clearPartyPvpBuffs} from './party-pvp-buffs.mjs';
import {ensureSkills,disposeSkills} from './skills.mjs';
import {registerObserverMode} from './observers.mjs';

export const PARTY_PVP_SCHEMAS = { partypvp: ['token', 'type', 'operation', 'targetId', 'row', 'fee', 'minutes', 'buff', 'enabled','matchId'] };
const OPS = new Set(['request', 'accept', 'decline', 'cancel', 'setting', 'ready', 'withdraw', 'buff','list','observe','leaveObserver']);
export const WAR_MINUTES = Object.freeze([15, 30, 60]); // 280:60 / 280:61 / 280:62
const fail = (message, status = 400) => { throw Object.assign(new Error(message), { status }); };
// Original texts (stringtable_pvp.txt cate 1008 / 280).
export const PARTY_PVP_TEXT = {
  noParty: 'The character is not in a Party.',                                    // 1008:21
  far: 'The opponent Party Leader is too far away.',                              // 1008:22
  preparing: 'The opponent Party is preparing to fight.',                         // 1008:23
  another: 'You cannot request a match during another match.',                    // 1008:25
  self: 'You are currently in a PvP battle.',                                     // 1008:26
  ownMatch: 'Your Party is currently in a Party Match.',                          // 1008:27
  theirMatch: 'The opponent Party is currently in a Party Match.',                // 1008:29
  ownDuel: 'Your Party Member is currently in a PvP battle.',                     // 1008:30
  theirDuel: 'One of the opponent Party Members is currently in a PvP battle.',   // 1008:31
  member: 'This character is your Party Member.',                                 // 1008:32
  ownDead: 'One of your Party Members has died.',                                 // 1008:33
  theirDead: 'One of the opponent Party Members has died.',                       // 1008:34
  authority: "You don't have authority to request a Party Match.",                // 280:67
  sameMap: '%s is not on the same map as the leader.',                            // 280:53
  feeMax: 'You have exceeded the maximum amount of DIL that can be set.',         // 280:39
  feeMin: 'You have to set DIL at %d or higher.',                                 // 280:45
  busy: 'Party Match cannot be started because %s is doing something else.',     // 280:76
  dead: 'Party Match cannot be started because some of your participants are currently dead.', // 280:75
  cancelled: 'The match request has been cancelled.',                             // 1008:20
  declined: 'The opponent declined your match request.',                          // 1008:7
  over: "You can't enter because Party Match time is over.",                      // 280:73
  dil: '%s does not have enough DIL for the Entry Fee.',                          // engine text (no original string)
  limit: 'Too many participants for this Party Match.',                           // engine text (EntryLimit)
  revive: 'You cannot revive during a Party Match.',                              // engine text
  leader: "It's not possible to assign a new party leader during a Party Match.", // 280:66
  portal: "You can't use a portal during a Party Match.",                         // 280:68
  returnScroll: "You can't use a Return Scroll during a Party Match.",            // 280:69
};

export async function loadPartyPvpData(dataRoot, maps = []) {
  const text = await fs.readFile(path.join(dataRoot, 'share', 'article', 'partypvp.csv'), 'latin1');
  const names = Object.fromEntries((maps || []).map(m => [m.index, m.name]));
  const rows = parsePartyPvpCsv(text, names);
  const offered=rows.filter(r => [0,4].includes(r.mode) && r.map < 200);
  // Older tables can offer Annihilation alone. Require the buff catalog only
  // when this source actually enables Buff Mode; malformed/missing enabled
  // data still fails rather than silently advertising an unusable mode.
  const buffs=offered.some(r=>r.mode===4)
    ?parsePartyPvpBuffs(await fs.readFile(path.join(dataRoot,'share/article/partypvpbuff.csv'),'latin1'))
    :[];
  return { rows, buffs, offered };
}

const matches = world => world.partyMatches ||= new Map();
const dataOf = world => { const d = world.data?.partyPvp; if (!d?.offered?.length || !world.data?.pvpRules) fail('Party Match tables are unavailable on this host.', 503); return d; };
const live = (world, p) => !!p && world.players.get(p.account) === p && !p.leaving;
const byId = (world, id) => [...world.players.values()].find(q => q.id === id && !q.leaving) || null;
const partyOf = (world, p) => (p?.partyId && world.parties?.get(p.partyId)) || null;
const current = (world, p) => (p?.partyPvpId && matches(world).get(p.partyPvpId)) || null;
const observed = (world,p) => {
  if(!p)return null;
  let m=p.partyPvpObserverId&&matches(world).get(p.partyPvpObserverId);
  if(!m&&p.profile?.instance?.kind==='partyPvpObserver')m=[...matches(world).values()].find(m=>m.instanceId===p.instanceId&&world.instances?.get(m.instanceId)?.admitted.has(p.characterId));
  if(!m||p.instanceId!==m.instanceId)return null;
  p.partyPvpObserverId=m.id;(m.observers ||= new Map()).set(p.id,p);return m;
};
registerObserverMode({is:(world,p)=>!!observed(world,p),actions:new Set(['move','stop','chat','partypvp'])});
const sideOf = (m, p) => m.sides.findIndex(s => s.ids.includes(p.id));
const fmt = (s, v) => s.replace(/%[sd]/, String(v));
const avgLevel = players => players.length ? Math.round(players.reduce((n, q) => n + (q.profile.level || 1), 0) / players.length) : 0;
const membersOf = (world, party) => party.members.map(id => byId(world, id)).filter(Boolean);
const participants = m => m.sides.flatMap(s => s.players);
function notify(world, m, reason, extra = {}) {
  const ps = participants(m); const map = ps[0]?.map;
  if (map != null) world.emit(map, { type: 'partypvp', id: m.id, reason, phase: m.phase, recipients: ps.map(q => q.id), ...(m.instanceId ? { instanceId: m.instanceId } : {}), ...extra });
}
function release(world, m) { matches(world).delete(m.id); for (const q of participants(m)) if (q.partyPvpId === m.id) { q.partyPvpId = null; world.changed(q); } for(const q of m.observers?.values()||[])if(q.partyPvpObserverId===m.id){q.partyPvpObserverId=null;world.changed(q);} }
function cancel(world, m, reason) {
  const at = world.now(); release(world, m); notify(world, m, reason);
  for (const q of participants(m)) { q.partyPvpNotice = { reason, at, requester: sideOf(m, q) === 0 }; world.changed(q); }
}
function busyReason(world, q) {
  if (q.dead) return 'dead';
  if (q.duelId) return 'duel';
  if (q.instanceId || q.tradeId || fishingBusy(q) || q.mount?.phase === 'on' || q.sceneTransition || (q.gmAuthorized && q.profile.gm?.hide)) return 'busy';
  if (q.partyPvpId) return 'match';
  return null;
}
function checkSide(world, leader, own) {
  const party = partyOf(world, leader), ps = party ? membersOf(world, party) : [];
  for (const q of ps) {
    const r = busyReason(world, q);
    if (r === 'dead') fail(own ? PARTY_PVP_TEXT.ownDead : PARTY_PVP_TEXT.theirDead);
    if (r === 'duel') fail(own ? PARTY_PVP_TEXT.ownDuel : PARTY_PVP_TEXT.theirDuel);
    if (r === 'match') fail(own ? PARTY_PVP_TEXT.ownMatch : PARTY_PVP_TEXT.theirMatch);
    if (r) fail(fmt(PARTY_PVP_TEXT.busy, q.profile.name));
    if (!sameScene(q, leader)) fail(fmt(PARTY_PVP_TEXT.sameMap, q.profile.name));
  }
  return ps;
}

/** PvP-mode hooks (server/world/pvp.mjs): an enemy is a live participant of the other team during the fight. */
export function partyPvpEnemy(world, p, q) {
  const m = current(world, p);
  if (!m || m.phase !== 'fight' || !q || q.partyPvpId !== m.id || m.down.has(p.id) || m.down.has(q.id)) return false;
  const a = sideOf(m, p), b = sideOf(m, q);
  return a >= 0 && b >= 0 && a !== b && sameScene(p, q);
}
function partyPvpOpponents(world, p) {
  const m = current(world, p); if (!m || m.phase !== 'fight') return [];
  return participants(m).filter(q => partyPvpEnemy(world, p, q) && live(world, q) && !q.dead);
}
registerPvpMode({ enemy: partyPvpEnemy, opponents: partyPvpOpponents, onDown: (world, attacker, target) => { const m = current(world, target); if (m) markDown(world, m, target); } });

/** Downed participants stay down (PARTY_PVP_CHOSEN.downedRule): the host's revive is refused in the arena. */
// 280:66 / 280:68 / 280:69: while a Party Match holds a character (request through Waiting to finish) no new Party Leader
// (delegation, or the leader leaving the party), no travel of its own (field gates, NPC teleport / sky / portal services,
// Smart Warp, map NPC warp, channel and DK portal moves) and no Return or teleport scroll. The match moves its own
// participants (arena entry and exit) without these commands.
const TRAVEL_TYPES = new Set(['travel', 'smartwarp', 'mapnpcwarp', 'npctravel', 'channel']);
const TRAVEL_FREE_OPS = { smartwarp: ['cancel'], mapnpcwarp: ['cancel'], npctravel: ['bind'], channel: ['list'] };
export function partyPvpGuard(world, p, input) {
  if(observed(world,p)&&input?.type==='partypvp'&&!['list','leaveObserver'].includes(input.operation))fail('Observers can only watch.');
  pvpModeGuard(world, p, input);
  const m = current(world, p); if (!m || !input) return;
  if (input.type === 'party' && (input.operation === 'lead' || (input.operation === 'leave' && m.sides.some(s => s.leaderId === p.id)))) fail(PARTY_PVP_TEXT.leader);
  if (TRAVEL_TYPES.has(input.type) && !(TRAVEL_FREE_OPS[input.type] || []).includes(input.operation)) fail(PARTY_PVP_TEXT.portal);
}
export function partyPvpItemGuard(world, p, def) { if (def?.use?.teleport != null && current(world, p)) fail(PARTY_PVP_TEXT.returnScroll); colosseumItemGuard(world, p, def); }   // COLOSSEUM: no Return Scroll in a match

export function partyPvpBlocksRevive(world, p) { const m = current(world, p); return !!m && ['wait', 'fight', 'over'].includes(m.phase); }

function markDown(world, m, q) {
  if (m.down.has(q.id)) return;
  m.down.add(q.id);
  q.hp = 0; q.dead = true; q.path = []; world.changed(q);
  const by = q.pvpLastHit?.by && byId(world, q.pvpLastHit.by);
  if (by && by.partyPvpId === m.id && sideOf(m, by) !== sideOf(m, q)) m.score.set(by.id, (m.score.get(by.id) || 0) + C.pointsPerKill);
  notify(world, m, 'down', { playerId: q.id, by: by?.id || null });
}

export async function partyPvpCommand(world, p, input) {
  const data = dataOf(world), now = world.now();
  if(Object.keys(input).some(key=>!PARTY_PVP_SCHEMAS.partypvp.includes(key)))fail('Unexpected Party Match fields.');
  if (!OPS.has(input.operation)) fail('Choose a Party Match operation.');
  if(input.operation==='list')return {matches:[...matches(world).values()].filter(m=>['wait','fight'].includes(m.phase)&&m.map0===p.map&&(m.exit?.channel??0)===(p.channel??0)).map(m=>({id:m.id,name:m.sides[0].name,map:m.arena,phase:m.phase}))};
  if(input.operation==='leaveObserver'){
    const match=observed(world,p);if(!match)fail('You are not observing a Party Match.');
    await exitInstance(world,p);match.observers?.delete(p.id);p.partyPvpObserverId=null;world.changed(p);return {left:true};
  }
  if(input.operation==='observe'){
    if(observed(world,p)||current(world,p)||busyReason(world,p)||p.customMapPending)fail('Finish your current activity before observing.');
    const match=matches(world).get(input.matchId),instance=match?.instanceId&&world.instances?.get(match.instanceId);
    if(!match||!['wait','fight'].includes(match.phase)||!instance||instance.closed||instance.closeRequested)fail(PARTY_PVP_TEXT.over);
    if(p.map!==match.map0||(p.channel??0)!==(match.exit?.channel??0)||Math.hypot(p.x-match.exit.x,p.z-match.exit.z)>ENGINE_CHOSEN.requestRange)fail('Walk near the Party Match entrance first.');
    const row=data.offered.find(r=>r.index===match.settings.row),start=row?.starts[2],at=start&&instance.scene.nearest(start.x,start.z);
    if(!at)fail('No safe observer start is available.',503);
    // ENGINE-CHOSEN: the native unused Start_2 row seats observers; no ticket is specified by the Party Match portal prompt.
    const staged=stageInstanceMembers(world,[p],[structuredClone(p.profile)]),q=staged.candidates[0],transition=p.sceneTransition;
    p.sceneTransition=true;match.observerAdmissions=(match.observerAdmissions||0)+1;
    try{
      q.instanceId=instance.id;q.map=instance.map;q.x=at.x;q.z=at.z;q.path=[];q.mount=null;q.pet=null;
      q.profile.instance={id:instance.id,kind:'partyPvpObserver',map:instance.map,exit:match.exit};
      world.changed(q);await world.persist(q);
      await staged.commit();instance.members.add(p.id);instance.admitted.add(p.characterId);
      p.partyPvpObserverId=match.id;(match.observers ||= new Map()).set(p.id,p);world.changed(p);
      world.emit(match.map0,{type:'leave',actorId:p.id,instanceId:null});
    }finally{p.sceneTransition=transition;match.observerAdmissions--;}
    return {observing:match.id};
  }
  const m = current(world, p);
  if (input.operation === 'request') {
    if (m) fail(PARTY_PVP_TEXT.another);
    if (p.duelId) fail(PARTY_PVP_TEXT.self);
    const own = partyOf(world, p); if (!own) fail(PARTY_PVP_TEXT.noParty);
    if (own.leader !== p.id) fail(PARTY_PVP_TEXT.authority);
    const target = byId(world, input.targetId);
    if (!target || target === p || !sameScene(target, p)) fail('Choose the opponent Party Leader on your map.');
    const theirs = partyOf(world, target);
    if (!theirs) fail(PARTY_PVP_TEXT.noParty);
    if (theirs === own) fail(PARTY_PVP_TEXT.member);
    if (theirs.leader !== target.id) fail('Choose the opponent Party Leader on your map.');
    if (!pvpAllowedOn(mapFor(world, p), world.data.mapRow?.(p.map) ?? mapFor(world, p)?.row)) fail(PVP_TEXT.area);
    if (current(world, target)) fail(target.partyPvpId && matches(world).get(target.partyPvpId)?.phase !== 'invited' ? PARTY_PVP_TEXT.theirMatch : PARTY_PVP_TEXT.preparing);
    if (Math.hypot(p.x - target.x, p.z - target.z) > ENGINE_CHOSEN.requestRange) fail(PARTY_PVP_TEXT.far);
    const a = checkSide(world, p, true), b = checkSide(world, target, false);
    if (a.length + b.length > data.offered[0].entryLimit) fail(PARTY_PVP_TEXT.limit);
    const id = randomUUID();
    const match = { id, phase: 'invited', createdAt: now, expiresAt: now + ENGINE_CHOSEN.acceptTimeoutSec * 1000, map0: p.map,
      sides: [{ partyId: own.id, leaderId: p.id, name: p.profile.name, ids: a.map(q => q.id), players: a }, { partyId: theirs.id, leaderId: target.id, name: target.profile.name, ids: b.map(q => q.id), players: b }],
      ready: new Set(), down: new Set(), score: new Map(), buffs: new Map(), settings: null };
    matches(world).set(id, match); for (const q of [...a, ...b]) { q.partyPvpId = id; delete q.partyPvpResult; world.changed(q); }
    notify(world, match, 'request', { requesterId: p.id });
    return { requested: id };
  }
  if (!m) fail('There is no Party Match request.');
  const side = sideOf(m, p), leader = m.sides[side]?.leaderId === p.id;
  if (input.operation === 'cancel') {
    if (m.phase !== 'invited' || side !== 0 || !leader) fail('Only a waiting request can be cancelled.');
    cancel(world, m, 'cancelled'); return { cancelled: m.id };
  }
  if (input.operation === 'decline' || input.operation === 'accept') {
    if (m.phase !== 'invited' || side !== 1 || !leader) fail('There is no Party Match request to answer.');
    if (input.operation === 'decline') { cancel(world, m, 'declined'); return { declined: m.id }; }
    const a = byId(world, m.sides[0].leaderId);
    if (!a || !sameScene(a, p)) { cancel(world, m, 'cancelled'); fail(PARTY_PVP_TEXT.cancelled); }
    const row = data.offered[0];
    m.phase = 'setup'; m.settings = { row: row.index, fee: row.feeMin, minutes: WAR_MINUTES.includes(row.limitMin) ? row.limitMin : WAR_MINUTES[1] };
    m.exit = { map: a.map, x: a.x, z: a.z,channel:a.channel??0 }; m.ready.clear();
    notify(world, m, 'accepted'); return { accepted: m.id };
  }
  if (input.operation === 'withdraw') {
    if (!['invited', 'setup'].includes(m.phase)) fail('The Party Match has already begun.');
    cancel(world, m, 'withdrawn'); return { withdrawn: m.id };
  }
  if (m.phase !== 'setup') fail('The Party Match setting is closed.');
  if(input.operation==='buff'){
    const row=data.offered.find(r=>r.index===m.settings?.row);
    if(row?.mode!==4)fail('Buff selection is only available in Buff Mode.');
    const choices=selectPartyPvpBuff(data.buffs||[],m.buffs?.get(p.id),input.buff,input.enabled);
    (m.buffs ||= new Map()).set(p.id,choices);m.ready.delete(p.id);
    world.changed(p);notify(world,m,'buff');return {selected:choices};
  }
  if (input.operation === 'setting') {
    if (side !== 0 || !leader) fail(PARTY_PVP_TEXT.authority);
    const row = data.offered.find(r => r.index === Number(input.row));
    if (!row) fail('Choose an offered arena.');
    const fee = Number(input.fee);
    if (!Number.isInteger(fee) || fee < row.feeMin) fail(fmt(PARTY_PVP_TEXT.feeMin, row.feeMin));
    if (fee > row.feeMax) fail(PARTY_PVP_TEXT.feeMax);
    const minutes = Number(input.minutes); if (!WAR_MINUTES.includes(minutes)) fail('Choose the Time Limit of Battle.');
    m.settings = { row: row.index, fee, minutes }; m.ready.clear();
    notify(world, m, 'setting'); for (const q of participants(m)) world.changed(q);
    return { setting: m.settings };
  }
  // ready (Start 280:36): toggles; the last one starts the match
  if (m.ready.has(p.id)) m.ready.delete(p.id); else m.ready.add(p.id);
  for (const q of participants(m)) world.changed(q);
  if (participants(m).every(q => m.ready.has(q.id))) {
    try { await start(world, m); } catch (error) { m.ready.clear(); for (const q of participants(m)) world.changed(q); throw error; }
    return { started: m.id };
  }
  return { ready: m.ready.has(p.id) };
}

async function start(world, m) {
  const data = dataOf(world), row = data.offered.find(r => r.index === m.settings.row), fee = m.settings.fee;
  const ps = participants(m);
  for (const [i, s] of m.sides.entries()) {
    const lead = byId(world, s.leaderId); if (!lead) fail(PARTY_PVP_TEXT.cancelled);
    for (const q of s.players) {
      if (!live(world, q)) fail(PARTY_PVP_TEXT.cancelled);
      if (q.dead) fail(PARTY_PVP_TEXT.dead);
      const r = busyReason(world, { ...q, partyPvpId: null }); if (r) fail(fmt(PARTY_PVP_TEXT.busy, q.profile.name));
      if (!sameScene(q, lead)) fail(fmt(PARTY_PVP_TEXT.sameMap, q.profile.name));
      if ((Number(q.profile.dil) || 0) < fee) fail(fmt(PARTY_PVP_TEXT.dil, q.profile.name));
      if (partyOf(world, q)?.id !== s.partyId) fail(PARTY_PVP_TEXT.cancelled);
    }
    void i;
  }
  const clones = ps.map(q => { const profile = structuredClone(q.profile); profile.dil = (Number(profile.dil) || 0) - fee; return profile; });
  // Validate all selected statuses before charging/admitting anybody.
  if(row.mode===4)for(const q of ps){
    const sys=ensureSkills(world,q);
    for(const index of m.buffs?.get(q.id)||[]){
      const choice=data.buffs.find(r=>r.index===index);
      if(!choice||!sys.data.status(choice.status))fail('A selected Party Match buff is unavailable.',503);
    }
  }
  for (const q of ps) q.sceneTransition = true;
  const staged = stageInstanceMembers(world, ps, clones);
  let instance;
  try {
    const durationMs = (row.waitSec + m.settings.minutes * 60 + 120) * 1000;   /* +120 s instance housekeeping margin */
    instance = await createInstance(staged.world, { map: row.map, members: staged.candidates, kind: 'partyPvp', exit: m.exit, durationMs });
    instance.admitting = true;
    staged.candidates.forEach((q, i) => {
      const s = m.sides[0].ids.includes(q.id) ? 0 : 1, at = instance.scene.nearest(row.starts[s].x, row.starts[s].z);
      if (!at) fail('No safe arena start exists.', 503);
      if(row.mode===4){
        q._skills=null;q._skillActor=null;q.dead=false;
        applyPartyPvpBuffs(staged.world,q,data.buffs,m.buffs?.get(q.id),durationMs);
        q.profile.partyPvpBuffScope={id:m.id,instanceId:instance.id};
      }
      q.x = at.x; q.z = at.z; world.changed(q); void i;
    });
    await world.persistMany(staged.candidates);
    await staged.commit();
    instance.admitting = false;
    // the scene publication copies position/scene only: the arena start state is set on the live records
    for (const q of ps) { if(row.mode===4){disposeSkills(q);ensureSkills(world,q);} q.hp = q.maxHp; q.mp = q.stats.maxMp || 0; q.shield = ENGINE_CHOSEN.shieldAtStart === 'full' ? (Number(q.stats.maxShield) || 0) : 0; q.dead = false; delete q.pvpLastHit;
      world.changed(q); }
  } catch (error) {
    if (instance) { world.instances.delete(instance.id); world.maps.delete(`${instance.map}@${instance.id}`); }
    throw error;
  } finally { for (const q of ps) q.sceneTransition = false; }
  const now = world.now();
  Object.assign(m, { phase: 'wait', instanceId: instance.id, arena: row.map, mode:row.mode, startAt: now + row.waitSec * 1000, paid: ps.length, fee });
  notify(world, m, 'enter', { startAt: m.startAt });
}

async function finish(world, m, reason) {
  if (m.phase === 'over') return;
  const now = world.now(), teams = m.sides.map(s => {
    const players = s.players.filter(q => live(world, q) && q.partyPvpId === m.id && q.instanceId === m.instanceId);
    return { alive: players.filter(q => !m.down.has(q.id)).length, points: s.ids.reduce((n, id) => n + (m.score.get(id) || 0), 0), players };
  });
  const winner = partyPvpOutcome({ blue: teams[0], red: teams[1] }, reason);
  const win = winner === 'blue' ? 0 : winner === 'red' ? 1 : -1;
  const prize = new Map();
  if (win < 0) for (const t of teams) for (const q of t.players) prize.set(q.id, m.fee); // DRAW refunds
  else {
    const winners = teams[win].players, { each, remainder } = partyPvpPrize(m.fee, m.paid, winners.length);
    for (const q of winners) prize.set(q.id, each + (q.id === m.sides[win].leaderId ? remainder : 0));
    if (!winners.some(q => q.id === m.sides[win].leaderId) && winners[0]) prize.set(winners[0].id, prize.get(winners[0].id) + remainder);
  }
  const summary = m.sides.map((s, i) => ({ name: s.name, points: teams[i].points, survived: teams[i].alive,
    members: s.players.map(q => ({ id: q.id, name: q.profile.name, classIndex: q.profile.classIndex, level: q.profile.level, score: m.score.get(q.id) || 0, down: m.down.has(q.id) })) }));
  m.phase = 'over'; m.finishAt = now;   /* Lane 71: the 280:51 'Waiting to finish' duration is REMOVED (no source): the label shows, no timer */
  m.result = { winner, reason, teams: summary, at: now };
  for (const t of teams) for (const q of t.players) {
    const got = prize.get(q.id) || 0;
    if (got) q.profile.dil = (Number(q.profile.dil) || 0) + got;
    q.partyPvpResult = { ...m.result, side: sideOf(m, q) === 0 ? 'blue' : 'red', prize: got };
    world.changed(q);
  }
  notify(world, m, 'result', { winner, reasonDetail: reason });
  const keep = teams.flatMap(t => t.players);
  try { await world.persistMany(keep); } catch { for (const q of keep) await world.persist(q).catch(() => {}); }
}

export async function tickPartyPvp(world) {
  if (!world.data?.partyPvp) return;
  const now = world.now(), rules = world.data.pvpRules;
  for (const m of [...matches(world).values()]) {
    const ps = participants(m);
    if (m.phase === 'invited' || m.phase === 'setup') {
      const gone = ps.find(q => !live(world, q) || partyOf(world, q)?.id !== m.sides[sideOf(m, q)].partyId || q.dead || !sameScene(q, byId(world, m.sides[sideOf(m, q)].leaderId) || q));
      if (gone || (m.phase === 'invited' && now >= m.expiresAt)) cancel(world, m, gone ? 'cancelled' : 'expired');
      continue;
    }
    if (m.phase === 'wait') {
      if (now >= m.startAt) { m.phase = 'fight'; m.endsAt = now + m.settings.minutes * 60000; notify(world, m, 'start', { endsAt: m.endsAt }); for (const q of ps) world.changed(q); }
      continue;
    }
    if (m.phase === 'fight') {
      for (const q of ps) {
        const inside = live(world, q) && q.instanceId === m.instanceId;
        if (!inside && !m.down.has(q.id)) { m.down.add(q.id); notify(world, m, 'left', { playerId: q.id }); }
        else if (inside && (q.hp <= 0 || q.dead)) markDown(world, m, q);
        else if(inside&&m.mode===4&&m.down.has(q.id)){
          m.down.delete(q.id);
          applyPartyPvpBuffs(world,q,world.data.partyPvp.buffs,m.buffs?.get(q.id),Math.max(1000,m.endsAt-now));
        }
      }
      const alive = m.sides.map(s => s.players.filter(q => !m.down.has(q.id)).length);
      if (alive.some(n => n === 0)) await finish(world, m, 'annihilation');
      else if (now >= m.endsAt) await finish(world, m, 'time');
      continue;
    }
    if (m.phase === 'over' && now >= m.finishAt) {
      if(m.observerAdmissions>0)continue;
      const inside = ps.filter(q => live(world, q) && q.instanceId === m.instanceId);
      const watchers=[...(m.observers?.values()||[])].filter(q=>live(world,q)&&q.instanceId===m.instanceId);
      if (!m.closing) {
        m.closing = true;
        for (const q of inside) {
          if(m.mode===4){clearPartyPvpBuffs(world,q);delete q.profile.partyPvpBuffScope;}
          q.dead = false; q.hp = Math.max(1, Math.round(q.maxHp * rules.reviveHpRatio / 100)); q.mp = Math.round((q.stats.maxMp || 0) * rules.reviveMpRatio / 100); q.path = [];
          world.changed(q); world.emit(q.map, { type: 'revive', actorId: q.id, instanceId: q.instanceId });
        }
      }
      const instance = world.instances?.get(m.instanceId);
      if (instance && (inside.length||watchers.length)) { requestInstanceClose(world, instance); continue; }
      release(world, m);
    }
  }
}

export function partyPvpSnapshot(world, p) {
  const m = current(world, p)||observed(world,p), d = world.data?.partyPvp;
  const out = { result: p.partyPvpResult || null, notice: p.partyPvpNotice || null };
  if (!m) return out;
  if(observed(world,p)){
    const row=d?.offered?.find(r=>r.index===m.settings.row);
    return Object.assign(out,{id:m.id,observer:true,name:m.sides[0].name,phase:m.phase,startAt:m.startAt,endsAt:m.endsAt,finishAt:m.finishAt,observerSpeed:row?.observerSpeed,enemies:[],down:false});
  }
  const side = sideOf(m, p), mine = m.sides[side], theirs = m.sides[1 - side];
  const team = s => ({ name: s.name, leaderId: s.leaderId, avgLevel: avgLevel(s.players),
    members: s.players.map(q => ({ id: q.id, name: q.profile.name, classIndex: q.profile.classIndex, level: q.profile.level, ready: m.ready.has(q.id), down: m.down.has(q.id), score: m.score.get(q.id) || 0 })) });
  return Object.assign(out, {
    id: m.id, phase: m.phase, side: side === 0 ? 'blue' : 'red', leader: mine.leaderId === p.id, canSet: side === 0 && mine.leaderId === p.id,
    incoming: m.phase === 'invited' && side === 1 && mine.leaderId === p.id, waiting: m.phase === 'invited' && side === 0 && mine.leaderId === p.id,
    own: team(mine), enemy: team(theirs), settings: m.settings, ready: m.ready.has(p.id),
    buffs:m.phase==='setup'&&d?.offered?.find(r=>r.index===m.settings?.row)?.mode===4?(d.buffs||[]):[],
    selectedBuffs:m.buffs?.get(p.id)||[],
    rows: m.phase === 'setup' ? (d?.offered || []).map(r => ({ index: r.index, mode: r.mode, modeName: r.modeName, map: r.map, mapName: r.mapName, imgIndex: r.imgIndex, feeMin: r.feeMin, feeMax: r.feeMax, waitSec: r.waitSec })) : undefined,
    minutes: WAR_MINUTES, createdAt: m.createdAt, expiresAt: m.phase === 'invited' ? m.expiresAt : null, startAt: m.startAt || null, endsAt: m.endsAt || null, finishAt: m.finishAt || null,
    enemies: m.phase === 'fight' ? theirs.players.filter(q => !m.down.has(q.id)).map(q => q.id) : [], down: m.down.has(p.id),
  });
}
