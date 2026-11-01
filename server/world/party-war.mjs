// PARTY-WAR: several parties in one Dead Front / Ice Castle war (server/world/events.mjs runs the PvE of the shared
// PartyWarRun). share/partywar data: config.csv LimitPvPDelay 30 / LimitPvPTime 240 / LimitExtensionDelay 10 /
// LimitExtension 60 (events.json timeline.inMap waitPvp / pvp / waitExtension / extension), field.csv StartPoint1..4,
// PvPPoint1..4, Winner / Loser / EndWar respawns, RecordEnableCount (maxParties), WinRPoint, result.csv PvPPoint_1..4
// and the win / lost EXP + R-point columns; the map tables' final-battle lines (Dead Front 1401 / 1402 / 1403 win /
// 1404 lose / 1406 extra time, Ice Castle 1401 / 1402 / 1403-1406 = 1st-4th place / 1408 overtime) and the team
// colours of the strings. The rules between them are src/game/pvp-rules.js PARTY_WAR_CHOSEN (each tagged ENGINE-CHOSEN).
import { partyWarPlaces, partyWarHostilePhase } from '../../src/game/pvp-rules.js';
import { registerPvpMode } from './pvp.mjs';

const LANES = ['A', 'B', 'C', 'D'];
const FINAL = ['waitPvp', 'pvp', 'waitExtension', 'extension'];
const JOIN_MARGIN_SEC = 5;   // the start countdown (map line 1002, 5..1) plays in the last 5 s of waitStart
const fail = (message, status = 400) => { throw Object.assign(new Error(message), { status }); };
export const PARTY_WAR_TEXT = {
  revive: 'You cannot revive during the final battle.',   // engine text (no original string)
};

const live = (world, i) => [...world.players.values()].filter(q => !q.leaving && q.instanceId === i.id);
const warOf = (world, p) => { const i = p?.instanceId && world.instances?.get(p.instanceId); return i?.teams?.length ? i : null; };
export const teamOf = (i, p) => (p && i?.teams?.find(t => t.ids.has(p.id))) || null;
const contested = i => (i?.teams?.length || 0) > 1;
const byId = (world, id) => [...world.players.values()].find(q => q.id === id && !q.leaving) || null;
const phaseSec = (run, id, dflt) => run.inMap?.[id]?.sec ?? dflt;

/** The last player that damaged target id (the host's recent event log), for objective point credit. */
export function lastHitter(world, id) {
  const events = world.events || [];
  for (let k = events.length - 1; k >= 0; k--) { const e = events[k]; if (e.type === 'damage' && e.targetId === id && e.sourceId) return e.sourceId; }
  return null;
}

/** field.csv RecordEnableCount (events.json fields[m].maxParties): teams one war can hold. */
export function warCapacity(world, mode, map) { return Math.max(1, Math.min(LANES.length, Number(world.data.eventData?.field(mode, map)?.maxParties) || 1)); }

/** A war of this map that a further party or solo entrant can still join. */
export function joinableWar(world, mode, map, p = null) {
  for (const i of world.instances?.values() || []) {
    if (i.kind !== mode || i.map !== map || !i.run || !i.teams?.length || i.run.ended || i.closeRequested || i.closed || i.admitting) continue;
    if (i.run.phase !== 'waitStart' || i.run.phaseT <= JOIN_MARGIN_SEC || i.teams.length >= warCapacity(world, mode, map)) continue;
    return i;
  }
  return null;
}

function addTeam(i, members) {
  const index = i.teams.length, name = i.run?.M?.teams?.[index]?.name || ['Purple', 'Orange', 'Yellow', 'Blue'][index];
  const team = { index, name, partyId: members[0]?.partyId || null, ids: new Set(members.map(q => q.id)), score: 0, kills: 0, place: null };
  i.teams.push(team); for (const q of members) q.eventTeam = index;
  syncRun(i); return team;
}
function syncRun(i) { if (!i.run) return; i.run.teamLanes = i.teams.map(t => LANES[t.index]); i.run.teamIds = i.teams.map(t => t.index); }

/** Admit staged party members into war i as its next team, at their StartPoint (createInstance's member rules). */
export function joinWarTeam(world, i, members) {
  const team = addTeam(i, members), field = i.run.field, mode = i.kind;
  const start = world.data.eventData.fieldPoint(mode, i.map, field.starts?.[team.index] || field.starts?.[0]);
  const at = start && i.scene.nearest(start.x, start.z); if (!at) { removeTeam(i, team); fail('No safe event start exists.', 503); }
  for (const p of members) {
    world.emit(p.map, { type: 'leave', actorId: p.id });
    p.instanceId = i.id; p.map = i.map; p.path = []; p.mount = null; p.pet = null; p.x = at.x; p.z = at.z;
    p.profile.instance = { id: i.id, kind: i.kind, map: i.map, exit: i.exit };
    i.admitted.add(p.characterId); i.members.add(p.id); world.changed(p);
  }
  return team;
}
export function removeTeam(i, team) {
  i.teams = i.teams.filter(t => t !== team);
  for (const id of team.ids) i.members.delete(id);
  syncRun(i);
}

/** Install the team layer on a freshly prepared war run (before run.start()). */
export function installPartyWar(world, i, run) {
  i.teams = [];
  addTeam(i, live(world, i));
  if (i.kind === 'deadFront') run.planLanes = LANES.slice(0, warCapacity(world, i.kind, i.map));
  // objective points go to the team of the player who earned them (PARTY_WAR_CHOSEN.pointsCredit)
  const addScore = run.addScore.bind(run);
  run.addScore = (n, why = '') => {
    const id = i.creditId; i.creditId = null;
    const team = teamOf(i, (id && byId(world, id)) || i.actor?.()) || i.teams[0];
    if (n > 0 && team) team.score += n;
    return addScore(n, why);
  };
  const channel = run.ui.channel.bind(run.ui);
  run.ui = Object.create(run.ui);
  // a side reaction on the same promise (registered before the run's await, so it runs first; no extra microtask hop)
  run.ui.channel = (text, ms, opts) => { const who = i.actor?.(), done = channel(text, ms, opts); done.then(ok => { if (ok && who) i.creditId = who.id; }, () => {}); return done; };
  let brickHook = null;
  Object.defineProperty(run, 'onBrickDestroyed', { configurable: true, get: () => brickHook && (b => { i.creditId = lastHitter(world, b.id) || i.creditId; return brickHook(b); }), set: fn => { brickHook = fn; } });
  // the final battle replaces the uncontested result when two or more teams are inside (PARTY_WAR_CHOSEN.finalBattle)
  const resolveFinal = run.resolveFinal.bind(run);
  run.resolveFinal = win => {
    if (i.final || run.won != null) return;
    captureStartingTeams(world, i);
    // Publisher guides: Dead Front reaches player combat only after its final boss.
    // A fortress timeout is a failed PvE attempt, never a substitute winner.
    if(i.kind==='deadFront'&&(!win||!run.objectiveDone()))return failFortress(world,i,run);
    // Publisher July 25, 2024: initially solo skips PvP; later departures do
    // not erase the participation of two or more teams at the battle start.
    if (i.startingTeamCount < 2) return resolveFinal(win);
    startFinal(world, i, run);
    warTick(world, i, run);
  };
  const onPhaseEnd = run.onPhaseEnd.bind(run);
  run.onPhaseEnd = id => {
    if (id === 'waitStart') captureStartingTeams(world, i);
    return i.final && FINAL.includes(id) ? finalPhaseEnd(world, i, run, id) : onPhaseEnd(id);
  };
  const tick = run.tick?.bind(run);
  run.tick = dt => { if (run.phase === 'fortress') captureStartingTeams(world, i); tick?.(dt); warTick(world, i, run); };
  i.warReward = p => rewardOf(i, run, teamOf(i, p));
  i.resultFor = p => i.results?.get(teamOf(i, p)?.index) || null;
}

function members(world, i, team) { return live(world, i).filter(q => team.ids.has(q.id)); }
function standing(world, i, team) { return members(world, i, team).filter(q => !q.dead && q.hp > 0 && !i.final?.down.has(q.id)); }
function standingTeams(world, i, present = false) { return i.teams.filter(t => (present ? members(world, i, t) : standing(world, i, t)).length > 0); }
function captureStartingTeams(world, i) {
  if (i.startingTeamCount == null) i.startingTeamCount = standingTeams(world, i, true).length;
}

function sayTo(i, run, ids, code) { i.sayTo = ids; try { run.say(code); } finally { i.sayTo = null; } }
function placeLine(run, place) { return run.mode === 'iceCastle' ? 1402 + place : place === 1 ? 1403 : 1404; }

function moveTeam(world, i, team, point, revive = false) {
  const at = point && i.scene.nearest(point.x, point.z);
  for (const q of members(world, i, team)) {
    if (revive) { q.dead = false; q.hp = q.maxHp; q.mp = q.stats?.maxMp || q.mp; delete q.pvpLastHit; }
    if (at) { q.x = at.x; q.z = at.z; q.path = []; }
    world.changed(q);
  }
}

function startFinal(world, i, run) {
  i.final = { down: new Set(), extended: false };
  for (const c of i.channels || []) c.resolve(false);
  run.say(1401);
  for (const t of i.teams) moveTeam(world, i, t, run.data.fieldPoint(run.mode, run.map, run.field.pvpPoints?.[t.index]), true);
  run.setPhase('waitPvp', phaseSec(run, 'waitPvp', 30));
}

function failFortress(world,i,run){
  if(i.fortressFailed||run.won!=null)return;
  i.fortressFailed=true;run.failed=true;run.won=false;
  for(const c of i.channels||[])c.resolve(false);
  for(const t of i.teams){t.place=null;moveTeam(world,i,t,run.data.fieldPoint(run.mode,run.map,run.field.loserRespawn));}
  run.setPhase('waitClose',phaseSec(run,'waitClose',300));run.say(1504);run.rewards();
}

function finalPhaseEnd(world, i, run, id) {
  if (id === 'waitPvp') { run.setPhase('pvp', phaseSec(run, 'pvp', 240)); run.say(1402); return; }
  if (id === 'pvp' && !i.final.extended && standingTeams(world, i).length > 1) {
    i.final.extended = true;
    // Dead Front 1406 / Ice Castle 1408 = the extra-time notice with its 2040 banner (Ice Castle 1407 is that banner alone)
    run.setPhase('waitExtension', phaseSec(run, 'waitExtension', 10)); run.say(run.mode === 'iceCastle' ? 1408 : 1406); return;
  }
  if (id === 'waitExtension') { run.setPhase('extension', phaseSec(run, 'extension', 60)); run.say(1402); return; }
  finishFinal(world, i, run);
}

function markDown(world, i, run, q) {
  if (i.final.down.has(q.id)) return;
  i.final.down.add(q.id); q.hp = 0; q.dead = true; q.path = []; world.changed(q);
  if (['pvp', 'extension'].includes(run.phase) && standingTeams(world, i).length <= 1) finishFinal(world, i, run);
}

function warTick(world, i, run) {
  if (!i.final || i.final.done) return;
  // Publisher July 25, 2024: one remaining team also wins during PvP waiting.
  if (!['waitPvp', 'pvp', 'extension'].includes(run.phase)) return;
  if (run.phase === 'waitPvp') {
    if (standingTeams(world, i).length === 1) finishFinal(world, i, run);
    return;
  }
  for (const t of i.teams) for (const q of members(world, i, t)) if ((q.hp <= 0 || q.dead) && !i.final.down.has(q.id)) markDown(world, i, run, q);
  if (!i.final.done && standingTeams(world, i).length <= 1) finishFinal(world, i, run);
}

function finishFinal(world, i, run) {
  if (i.final.done) return; i.final.done = true;
  const order = partyWarPlaces(i.teams.map(t => ({ index: t.index, standing: standing(world, i, t).length, score: t.score, kills: t.kills, team: t })));
  order.forEach((o, k) => { o.team.place = k + 1; o.team.score += Number(run.res.pvpPoints?.[k]) || 0; });
  run.won = true;
  for (const t of i.teams) {
    const ids = members(world, i, t).map(q => q.id);
    if (ids.length) sayTo(i, run, ids, placeLine(run, t.place));
    moveTeam(world, i, t, run.data.fieldPoint(run.mode, run.map, t.place === 1 ? run.field.winnerRespawn : run.field.loserRespawn), true);
  }
  run.rewards();
  run.setPhase('waitClose', phaseSec(run, 'waitClose', 300));
  for (const t of i.teams) { const ids = members(world, i, t).map(q => q.id); if (ids.length) sayTo(i, run, ids, t.place === 1 ? 1501 : 1504); }
}

/** Reward inputs of one team (the PartyWarRun result formula; place 1 = won). */
function rewardOf(i, run, team) {
  const res = run.res, won = team?.place === 1, score = team?.score || 0;
  // ENGINE-CHOSEN failure payout: retain the existing earned PvE score ratio.
  // No PvP took place, so its win/loss EXP and R-point columns are ineligible.
  if(i.fortressFailed)return {won:false,score,exp:Math.max(0,Math.round(score*(Number(res.advRatio)||0))),points:0,failed:true};
  const exp = Math.max(0, Math.round(score * (Number(res.advRatio) || 0)) + (Number(won ? res.winExp4PvP : res.lostExp4PvP) || 0));
  const points = Math.max(0, (won ? Number(run.field.winRPoint) || 0 : 0) + (Number(won ? res.winRPoint4PvP : res.lostRPoint4PvP) || 0));
  return { won, score, exp, points };
}

registerPvpMode({
  enemy(world, p, q) {
    const i = warOf(world, p);
    if (!i || !contested(i) || q?.instanceId !== i.id || i.run?.won != null || !combatPhase(i)) return false;
    const a = teamOf(i, p), b = teamOf(i, q);
    return !!a && !!b && a !== b && !q.dead && !i.final?.down.has(q.id) && !i.final?.down.has(p.id);
  },
  opponents(world, p) { const i = warOf(world, p); return i ? live(world, i).filter(q => this.enemy(world, p, q)) : []; },
  onDown(world, attacker, target) {
    const i = warOf(world, target); if (!i || !contested(i)) return;
    const t = teamOf(i, attacker); if (t && teamOf(i, target) !== t) t.kills++;
    if (i.final && ['pvp', 'extension'].includes(i.run.phase)) markDown(world, i, i.run, target);
    // fortress: an ordinary death (the war's existing revive / respawn rules)
    else if (!i.final) { target.hp = 0; target.dead = true; target.path = []; world.changed(target); }
  },
  guard(world, p, input) {
    const i = warOf(world, p);
    if (input?.type === 'revive' && i?.final && !i.final.done && i.final.down.has(p.id)) fail(PARTY_WAR_TEXT.revive);
  },
});

/** Team view for the snapshot. */
export function partyWarSnapshot(world, p, i) {
  if (!i?.teams?.length) return null;
  const mine = teamOf(i, p);
  return {
    team: mine?.index ?? null, name: mine?.name || null, place: mine?.place ?? null, capacity: warCapacity(world, i.kind, i.map),
    teams: i.teams.map(t => ({ index: t.index, name: t.name, score: t.score, kills: t.kills, size: members(world, i, t).length, standing: standing(world, i, t).length, place: t.place })),
    failed:!!i.fortressFailed,
    enemies: live(world, i).filter(q => q !== p && q.instanceId === i.id && i.teams.length > 1 && teamOf(i, q) && teamOf(i, q) !== mine && i.run?.won == null && combatPhase(i) && !q.dead && !i.final?.down.has(q.id)).map(q => q.id),
    down: !!i.final?.down.has(p.id),
  };
}

function combatPhase(i){return partyWarHostilePhase(i.kind,i.run?.phase)&&(i.kind!=='deadFront'||!!i.final&&i.run.objectiveDone());}
