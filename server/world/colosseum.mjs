// COLOSSEUM: server-authoritative Colosseum matches (data: share/colosseum, map tables of 163 / 164 / 196, strings
// stringtable_colosseum 360|*). Three modes share one queue / prompt / instance / result flow:
//   classic  Battle Royale (battleroyal/list.csv map 163, 16 members, 16 start cells, grade S, daily playtime hours):
//            Round 1, 2, 3, Final (163:200-500 effects) with the death roll (163:700) between rounds; coins + CP by the
//            highest round reached / Champ (reward_br row 1) and CP per kill.
//   renew    Battle Royale (battleroyal_renew/list.csv map 196, ticket 4002357 used at entry, entry / battle points,
//            Sunday 0-24): up to 30 rounds (196:302-331 labels); B Point = Rank_Point of the place row + kills x
//            Kill_Per_Point, Rank_ItemIdx x Rank_ItemCnt.
//   individual  Individual Ranking Match (partymatch/list.csv map 164 2:2, grade.csv level section x PCP band): ready
//            (164:100), fight (164:200), win / lose / draw (164:300 / 400 / 500); reward.csv row of the grade (B Coin
//            6804, PCP, CP per kill / per win, MVP rate).
// Battle Royale "Blessing of the Dead" (buff_table.csv of both folders: statuses 7101-7104 at Buff_Rate 100 / 75 / 50 / 25,
// status rows group 125 / maxStack 10): a Crystal of the Dead (2826) appears where an entrant dies; the entrant whose hit breaks
// it receives each set row on its own rate roll; classic reward_br pays Reward_CP_Per_Buffs per blessing received.
// Values the data does not give are ENGINE-CHOSEN in src/config/engine-chosen-colosseum.js. Player hits use the shared
// PvP rules through registerPvpMode; eliminated players stay down until the result (no revive in the arena).
import {fishingBusy} from './fishing.mjs';
import {serverDate} from '../../src/game/server-time.js';
import fs from 'node:fs/promises';
import path from 'node:path';
import { randomUUID } from 'node:crypto';
import { parseCSV } from '../../src/formats/binreader.js';
import { COLOSSEUM_ENGINE_CHOSEN as C } from '../../src/config/engine-chosen-colosseum.js';
import { registerPvpMode } from './pvp.mjs';
import { createInstance, stageInstanceMembers, requestInstanceClose, exitInstance } from './instances.mjs';
import { AuthoritativeInventory } from './inventory.mjs';
import { serializeLife, commitLife } from './life-transactions.mjs';
import { sameScene } from './scene.mjs';
import { socialRef } from './social-state.mjs';
import { ensureSkills } from './skills.mjs';
// MONSTER CARNIVAL (the Forgotten Shipwreck team mode) rides this command, tick and snapshot: server/world/monster-carnival.mjs.
import { CARNIVAL_OPS, carnivalCommand, tickCarnival, carnivalSnapshot, carnivalBusy } from './monster-carnival.mjs';

export const COLOSSEUM_SCHEMAS = { colosseum: ['token', 'type', 'operation', 'mode', 'category', 'period', 'page', 'skill', 'target'] };
const OPS = new Set(['register', 'cancel', 'accept', 'decline', 'exit', 'ranking']);
// Runtime identity and retry state stay private; neither belongs in snapshots.
const participantActors = new WeakMap(), settlements = new WeakMap();
export const MODES = Object.freeze(['classic', 'renew', 'individual']);
const fail = (message, status = 400) => { throw Object.assign(new Error(message), { status }); };
const fmt = (s, ...v) => { let i = 0; return s.replace(/%[sd]/g, () => String(v[i++] ?? '')); };
// Original texts (stringtable_colosseum.txt cate 360).
export const COLOSSEUM_TEXT = {
  ticket: 'There is no admission ticket.',                                                   // 360:99
  waiting: 'Waiting for a Colosseum match...',                                               // 360:101
  party: 'You cannot request a Colosseum match while in a party.',                           // 360:103
  declined: 'You have cancelled joining the Colosseum Match.',                               // 360:119
  cancelled: 'You have cancelled registering the Colosseum Match.',                          // 360:120
  notRegistered: 'The Colosseum Match has not been registered; the match cannot cancelled.', // 360:121
  processing: 'Processing your Colosseum Match at the server end...',                        // 360:122
  rank: 'Your ranking is not eligible to join Colosseum.',                                   // 360:147
  brTime: 'It is past the time to request for a Battle Royale.',                             // 360:166
  matchTime: "You can't register Individual Ranking Match in this time.",                    // 360:167
  enter: 'You cannot enter.',                                                                // 360:185
  ended: 'You cannot enter because the match has ended.',                                    // 360:192
  level: '%s is a level that cannot be applied for.',                                        // 360:217
  partyEnter: 'You cannot enter while you are already in a party.',                          // 360:221
  bagFull: '[Message] You do not have enough Inventory space to receive the reward.',        // map 163:90
  sentenced: 'You have been sentenced to death.',                                            // map 163:700
  revive: C.revive,                                                                          // ENGINE-CHOSEN
};

const num = v => Number(v) || 0;
async function csv(root, ...parts) {
  const text = await fs.readFile(path.join(root, 'share', 'colosseum', ...parts), 'latin1');
  const [head, ...rows] = parseCSV(text).filter(r => r.length > 1 && r.some(c => String(c).trim() !== ''));
  return rows.map(r => Object.fromEntries(head.map((h, i) => [String(h).trim(), String(r[i] ?? '').trim()])));
}
const cells = (row, fx, fy, n) => Array.from({ length: n }, (_, i) => { const k = String(i).padStart(2, '0'); return { x: num(row[`${fx}${k}`]), z: num(row[`${fy}${k}`]) }; }).filter(p => p.x || p.z);
/** share/colosseum tables (+ the map message codes the clients play). */
export async function loadColosseumData(dataRoot) {
  const [cl, cg, cp, cr, rl, rg, rp, rr, ml, mg, mp, mr] = await Promise.all([
    csv(dataRoot, 'battleroyal', 'list.csv'), csv(dataRoot, 'battleroyal', 'grade.csv'), csv(dataRoot, 'battleroyal', 'playtime.csv'), csv(dataRoot, 'battleroyal', 'reward_br.csv'),
    csv(dataRoot, 'battleroyal_renew', 'list.csv'), csv(dataRoot, 'battleroyal_renew', 'grade.csv'), csv(dataRoot, 'battleroyal_renew', 'playtime.csv'), csv(dataRoot, 'battleroyal_renew', 'reward_br.csv'),
    csv(dataRoot, 'partymatch', 'list.csv'), csv(dataRoot, 'partymatch', 'grade.csv'), csv(dataRoot, 'partymatch', 'playtime.csv'), csv(dataRoot, 'partymatch', 'reward.csv')]);
  const hours = rows => rows.map(r => ({ start: num(r.StartTime), end: num(r.EndTime), day: Object.keys(r).some(k => /^StartDay/.test(k)) ? num(r[Object.keys(r).find(k => /^StartDay/.test(k))]) : null }));
  const grade = rows => rows.map(r => ({ index: num(r.Index), min: num(r.Level_Min), max: num(r.Level_Max) }));
  // buff_table.csv (both Battle Royale folders): the "Blessing of the Dead" set, Buff_Count rows of status Buff_Index_k / Buff_Rate_k.
  const buffSet = rows => rows.flatMap(r => Array.from({ length: num(r.Buff_Count) }, (_, k) => ({ status: num(r[`Buff_Index_${k}`]), rate: num(r[`Buff_Rate_${k}`]) })).filter(b => b.status > 0));
  const [cb, rb] = await Promise.all([csv(dataRoot, 'battleroyal', 'buff_table.csv').catch(() => []), csv(dataRoot, 'battleroyal_renew', 'buff_table.csv').catch(() => [])]);
  const c0 = cl[0], r0 = rl[0], m0 = ml[0];
  const classic = { mode: 'classic', map: num(c0.MapIndex), members: num(c0.MemberCount), starts: cells(c0, 'PosX_', 'PosY_', 16), grades: grade(cg), playtime: hours(cp), buffs: buffSet(cb),
    rewards: cr.map(r => ({ index: num(r.Index), coin: [num(r.Reward_Coin_1), num(r.Reward_Coin_2), num(r.Reward_Coin_3), num(r.Reward_Coin_F)], coinChamp: num(r.Reward_Coin_Champ),
      cp: [num(r.Reward_CP_Round1), num(r.Reward_CP_Round2), num(r.Reward_CP_Round3), num(r.Reward_CP_RoundF)], cpChamp: num(r.Reward_CP_Champ), cpKill: num(r.Reward_CP_Per_Kills), cpBuff: num(r.Reward_CP_Per_Buffs) })) };
  const renew = { mode: 'renew', map: num(r0.MapIndex), channel: num(r0.ChannelIndex), ticket: num(r0.EntranceIndex), members: num(r0.MemberCount),
    enter: { x: num(r0.PosX_Enter), z: num(r0.PosY_Enter) }, battle: { x: num(r0.PosX_Battle), z: num(r0.PosY_Battle) }, grades: grade(rg), playtime: hours(rp), buffs: buffSet(rb),
    rewards: rr.map(r => ({ index: num(r.Index), killPoint: num(r.Kill_Per_Point), rankPoint: num(r.Rank_Point), item: num(r.Rank_ItemIdx), count: num(r.Rank_ItemCnt), low: num(r.LowRank), high: num(r.HighRank) })) };
  const individual = { mode: 'individual', map: num(m0.MapIndex), members: num(m0.MemberCount), starts: [cells(m0, 'APosX_', 'APosY_', 7), cells(m0, 'BPosX_', 'BPosY_', 7)], playtime: hours(mp),
    grades: mg.map(r => ({ index: num(r.Index), section: num(r.Level_Section), min: num(r.Level_Min), max: num(r.Level_Max), pcpMin: num(r.PCP_Min), pcpMax: num(r.PCP_Max) })),
    rewards: mr.map(r => ({ section: num(r.LevelSection), coinItem: num(r.Coin_Index), coin: { W: num(r.Reward_W_Coin), L: num(r.Reward_L_Coin), D: num(r.Reward_D_Coin) },
      pcp: { W: num(r.Reward_W_PCP), L: num(r.Reward_L_PCP), D: num(r.Reward_D_PCP) }, cpKill: num(r.Reward_CP_Per_Kills), cpWin: num(r.Reward_CP_Per_Wins), mvpRate: num(r.Reward_MVP_Rate) })) };
  return { classic, renew, individual };
}

// ------------------------------------------------------------------------------------------------ helpers
const state = world => world.colosseum ||= { queues: { classic: [], renew: [], individual: [] }, matches: new Map() };
const dataOf = world => { const d = world.data?.colosseum; if (!d?.classic) fail('Colosseum tables are unavailable on this host.', 503); return d; };
const live = (world, p) => !!p && world.players.get(p.account) === p && !p.leaving;
const byId = (world, id) => [...world.players.values()].find(q => q.id === id && !q.leaving) || null;
const current = (world, p) => (p?.colosseumId && state(world).matches.get(p.colosseumId)) || null;
const entrant = (m, p) => m.players.find(e => e.id === p?.id) || null;
const levelOf = p => num(p.profile.level) || 1;
/** Mode playtime against the host clock: StartTime <= hour < EndTime (and the StartDay weekday when the table has it). */
export function colosseumOpen(mode, now) {
  const d = serverDate(now), h = d.getUTCHours(), wd = d.getUTCDay();
  return (mode.playtime || []).some(r => h >= r.start && h < r.end && (r.day == null || r.day === wd));
}
export function blankRecord() { return { points: { colosseumPoint: 0, brPoint: 0, partyPoint: 0 }, records: { total: rec(), battleroyal: rec(), party: rec() }, ledger: [] }; }
function rec() { return { wins: 0, defeats: 0, draws: 0, kills: 0, died: 0 }; }
const recordOf = profile => { const r = profile.colosseum ||= blankRecord(); r.points ||= blankRecord().points; r.records ||= blankRecord().records; for (const k of ['total', 'battleroyal', 'party']) r.records[k] ||= rec(); r.ledger ||= []; return r; };
/** Individual Match grade row of a character (level section x PCP band; PCP above the last band = highest band). */
export function individualGrade(d, level, pcp) {
  const rows = d.individual.grades.filter(g => level >= g.min && level <= g.max);
  if (!rows.length) return null;
  return rows.find(g => pcp >= g.pcpMin && pcp <= g.pcpMax) || rows.reduce((a, b) => (b.pcpMax > a.pcpMax ? b : a));
}
function busy(world, q) {
  return q.dead || q.instanceId || q.duelId || q.partyPvpId || q.tradeId || q.sceneTransition || fishingBusy(q) || q.colosseumId || carnivalBusy(world, q);
}
function noticeTo(world, q, text, extra = {}) { q.colosseumNotice = { text, at: world.now(), ...extra }; world.changed(q); }

// ------------------------------------------------------------------------------------------------ PvP mode
export function colosseumEnemy(world, p, q) {
  const m = current(world, p);
  if (!m || !q || q.colosseumId !== m.id || !sameScene(p, q)) return false;
  const a = entrant(m, p), b = entrant(m, q);
  if (!a || !b || a === b || a.out || b.out) return false;
  if (m.mode === 'individual') return m.phase === 'fight' && a.team !== b.team;
  return m.phase === 'round';
}
function colosseumOpponents(world, p) {
  const m = current(world, p); if (!m) return [];
  return m.players.map(e => byId(world, e.id)).filter(q => q && !q.dead && colosseumEnemy(world, p, q));
}
const TRAVEL_TYPES = new Set(['travel', 'smartwarp', 'mapnpcwarp', 'npctravel', 'channel', 'dungeon']);
const TRAVEL_FREE_OPS = { smartwarp: ['cancel'], mapnpcwarp: ['cancel'], npctravel: ['bind'], channel: ['list'] };
function colosseumGuard(world, p, input) {
  if (!input || !current(world, p)) return;
  if (TRAVEL_TYPES.has(input.type) && !(TRAVEL_FREE_OPS[input.type] || []).includes(input.operation)) fail(COLOSSEUM_TEXT.enter);
  if (input.type === 'party' && ['invite', 'accept', 'create'].includes(input.operation)) fail(COLOSSEUM_TEXT.partyEnter);
}
registerPvpMode({ enemy: colosseumEnemy, opponents: colosseumOpponents, guard: colosseumGuard, onDown: (world, attacker, target) => { const m = current(world, target); const e = m && entrant(m, target); if (e) eliminate(world, m, e, 'killed'); } });
/** No Return / teleport scroll inside a match (maps 163 / 164 / 196 carry returnScroll 0). */
export function colosseumItemGuard(world, p, def) { if (def?.use?.teleport != null && current(world, p)) fail(COLOSSEUM_TEXT.enter); }
export function colosseumBlocksRevive(world, p) { const m = current(world, p); return !!m && m.phase !== 'prompt' && !m.closed; }
export const COLOSSEUM_REVIVE_TEXT = COLOSSEUM_TEXT.revive;

function push(world, m, code, extra = {}) {
  m.seq = (m.seq || 0) + 1; m.events.push({ seq: m.seq, code, map: m.map, at: world.now(), ...extra }); if (m.events.length > 24) m.events.shift();
  for (const e of m.players) { const q = byId(world, e.id); if (q && q.colosseumId === m.id) world.changed(q); }
}
function changedAll(world, m) { for (const e of m.players) { const q = byId(world, e.id); if (q && q.colosseumId === m.id) world.changed(q); } }
const aliveOf = m => m.players.filter(e => e.entered && !e.out);
function eliminate(world, m, e, how) {
  if (!e || e.out || !['round', 'fight', 'ready', 'wait'].includes(m.phase)) return;
  const q = byId(world, e.id), inside = q && q.colosseumId === m.id && q.instanceId === m.instanceId;
  const alive = aliveOf(m).length;
  e.out = how; e.outRound = m.round || 0; e.outAt = world.now(); e.place = m.mode === 'individual' ? null : alive;
  if (inside) { q.hp = 0; q.dead = true; q.path = []; world.changed(q); }
  const by = how === 'killed' && q?.pvpLastHit?.by ? entrant(m, { id: q.pvpLastHit.by }) : null;
  if (by && by !== e && !by.out) { by.kills++; if (m.mode === 'individual' && by.team !== e.team) m.teamKills[by.team]++; }
  m.roundOut = (m.roundOut || 0) + 1;
  push(world, m, how === 'sentenced' ? 700 : 0, { kind: how, playerId: e.id, name: e.name, by: by?.name || null });
  if (inside && how !== 'left') spawnCrystal(world, m, { x: q.x, z: q.z });
}

// ------------------------------------------------------------------------------------------------ Blessing of the Dead
const BLESSINGS = new Set([7101, 7102, 7103, 7104]);
const blessed = p => Array.isArray(p?.profile?.buffs) && p.profile.buffs.some(s => BLESSINGS.has(Number(s?.statusIndex)));
/** A Crystal of the Dead (C.crystal) at the cell where an entrant died; one per death, until broken or the result. */
function spawnCrystal(world, m, at) {
  const md = world.data?.colosseum?.[m.mode], def = world.data?.monsterDef?.(C.crystal), scene = world.instances?.get(m.instanceId)?.scene;
  if (!md?.buffs?.length || !def || !scene?.monsters || m.phase === 'over' || m.closed) return null;
  const point = scene.nearest?.(at.x, at.z); if (!point) return null;
  const c = { id: `colosseum:${m.instanceId}:${randomUUID()}`, map: m.map, instanceId: m.instanceId, monsterIndex: C.crystal, name: def.name, x: point.x, z: point.z, hp: def.hp, maxHp: def.hp,
    home: { ...point }, dead: false, targetId: null, attackAt: 0, respawnSec: Infinity, respawnAt: Infinity, def, kind: 'monster', colosseumCrystal: m.id, setPosition(x, z) { this.x = x; this.z = z; }, play() {} };
  c.onKilled = killer => takeCrystal(world, m, c, killer);
  scene.monsters.set(c.id, c); (m.crystals ||= new Map()).set(c.id, c);
  return c;
}
/** The breaking hit: the live session of a standing entrant of this match, inside its arena, during a round. Anyone else breaks
 *  nothing: the crystal stands again on its cell. */
function takeCrystal(world, m, c, killer) {
  if (c.taken) return; c.taken = true;
  m.crystals?.delete(c.id);
  const e = entrant(m, killer);
  const ok = !!e && !e.out && m.phase === 'round' && !m.closed && live(world, killer) && byId(world, e.id) === killer && participantActors.get(e) === killer
    && killer.colosseumId === m.id && killer.instanceId === m.instanceId && !killer.dead;
  if (!ok) { spawnCrystal(world, m, c); return; }
  const md = dataOf(world)[m.mode], i = world.instances?.get(m.instanceId), ms = Math.max(1000, Math.min(86400000, (i?.expiresAt || world.now()) - world.now())), got = [];
  for (const b of md.buffs) if (world.random() * 100 < b.rate && blessing(world, killer, b.status, ms)) got.push(b.status);
  e.buffs = (e.buffs || 0) + got.length;
  push(world, m, 0, { kind: 'blessing', playerId: e.id, name: e.name, statuses: got });
}
/** One stack of `status`; true only when a stack was added (a status already at its maxStack is refreshed, not counted). */
function blessing(world, p, status, ms) {
  try {
    const sys = ensureSkills(world, p), stacks = () => num((p.profile.buffs || []).find(s => Number(s?.statusIndex) === status)?.stacks), before = stacks();
    const entry = sys.statuses.add(sys.game.player, status, ms, { source: sys.game.player }); if (entry) world.changed(p);
    return !!entry && stacks() > before;
  } catch { return false; }
}
/** Blessings exist only inside a running Battle Royale: removed at the result, at exit and from anyone outside a match. */
function stripBlessings(world, p) {
  if (!blessed(p)) return false;
  const pred = s => BLESSINGS.has(Number(s?.statusIndex));
  // The skill system's own removal refreshes the stats with the passives; a profile without one is only filtered.
  if (p._skills) p._skills.statuses.remove(p._skills.game.player, pred, 'silent');
  const list = p.profile.buffs; for (let i = list.length - 1; i >= 0; i--) if (pred(list[i])) list.splice(i, 1);
  world.changed(p); return true;
}
function clearCrystals(world, m) {
  for (const c of m.crystals?.values() || []) { c.dead = true; c.hp = 0; world.emit(m.map, { type: 'damage', sourceId: c.id, targetId: c.id, amount: 0, dead: true, instanceId: m.instanceId }); }
  m.crystals?.clear();
}

// ------------------------------------------------------------------------------------------------ commands
export async function colosseumCommand(world, p, input) {
  if (CARNIVAL_OPS.includes(input.operation)) return carnivalCommand(world, p, input);
  const d = dataOf(world), st = state(world), now = world.now();
  if (!OPS.has(input.operation)) fail('Choose a Colosseum operation.');
  if (input.operation === 'ranking') return colosseumRanking(world, p, input);
  if (input.operation === 'register') {
    const mode = String(input.mode || ''); if (!MODES.includes(mode)) fail('Choose a Colosseum mode.');
    const md = d[mode], level = levelOf(p);
    if (p.colosseumQueue || current(world, p)) fail(COLOSSEUM_TEXT.waiting);
    if (!colosseumOpen(md, now)) fail(mode === 'individual' ? COLOSSEUM_TEXT.matchTime : COLOSSEUM_TEXT.brTime);
    if (p.partyId && world.parties?.get(p.partyId)) fail(COLOSSEUM_TEXT.party);
    if (busy(world, p)) fail(COLOSSEUM_TEXT.enter);
    let grade = null;
    if (mode === 'individual') { grade = individualGrade(d, level, num(recordOf(structuredClone(p.profile)).points.partyPoint)); if (!grade) fail(fmt(COLOSSEUM_TEXT.level, level)); }
    else if (!md.grades.some(g => level >= g.min && level <= g.max)) fail(fmt(COLOSSEUM_TEXT.level, level));
    if (mode === 'renew' && !ticketClone(world, p, md.ticket)) fail(COLOSSEUM_TEXT.ticket);
    st.queues[mode].push({ id: p.id, at: now, grade: grade?.index ?? null });
    p.colosseumQueue = mode; p.colosseumQueuedAt = now; delete p.colosseumResult; delete p.colosseumNotice; world.changed(p);
    return { registered: mode, waiting: st.queues[mode].length };
  }
  if (input.operation === 'cancel') {
    if (!p.colosseumQueue) fail(COLOSSEUM_TEXT.notRegistered);
    const q = st.queues[p.colosseumQueue]; const i = q.findIndex(e => e.id === p.id); if (i >= 0) q.splice(i, 1);
    p.colosseumQueue = null; noticeTo(world, p, COLOSSEUM_TEXT.cancelled);
    return { cancelled: true };
  }
  const m = current(world, p);
  if (input.operation === 'accept' || input.operation === 'decline') {
    if (!m || m.phase !== 'prompt') fail(COLOSSEUM_TEXT.notRegistered);
    const e = entrant(m, p);
    if (input.operation === 'accept') { e.answer = 'accept'; changedAll(world, m); return { accepted: m.id }; }
    m.players = m.players.filter(x => x !== e); p.colosseumId = null; noticeTo(world, p, COLOSSEUM_TEXT.declined); changedAll(world, m);
    return { declined: m.id };
  }
  // exit: an eliminated entrant (mini result btn_exit 360|81) or anyone after the result (btn_exit 2000|46)
  if (!m) fail(COLOSSEUM_TEXT.ended);
  const e = entrant(m, p);
  if (m.phase !== 'over' && !e?.out) fail(COLOSSEUM_TEXT.processing);
  await leaveMatch(world, m, p);
  return { exited: m.id };
}
async function leaveMatch(world, m, p) {
  stripBlessings(world, p);
  if (p.dead) { p.dead = false; p.hp = Math.max(1, Math.round(p.maxHp * (world.data.pvpRules?.reviveHpRatio ?? 100) / 100)); world.changed(p); }
  if (p.instanceId === m.instanceId) await exitInstance(world, p);
  p.colosseumId = null; world.changed(p);
}

// ------------------------------------------------------------------------------------------------ matching
function form(world, mode, list) {
  const st = state(world), now = world.now(), id = randomUUID();
  const m = { id, mode, phase: 'prompt', createdAt: now, promptEndsAt: now + C.entryPromptSec * 1000, events: [], seq: 0, round: 0, teamKills: [0, 0],
    grade: list[0].grade, players: list.map((e, i) => { const q = byId(world, e.id); return { id: e.id, at: e.at, grade: e.grade, name: q.profile.name, classIndex: num(q.profile.classIndex), level: levelOf(q), kills: 0, team: mode === 'individual' ? i % 2 : null, answer: null, out: null, entered: false }; }) };
  st.matches.set(id, m);
  for (const e of m.players) participantActors.set(e, byId(world, e.id));
  for (const e of m.players) { const q = byId(world, e.id); q.colosseumQueue = null; q.colosseumId = id; delete q.colosseumResult; world.changed(q); }
  return m;
}
function requeue(world, m, ids) {
  const st = state(world);
  const back = m.players.filter(e => ids.includes(e.id)).map(e => ({ id: e.id, at: e.at, grade: e.grade }));
  st.queues[m.mode].unshift(...back);
  for (const e of back) { const q = byId(world, e.id); if (q) { q.colosseumId = null; q.colosseumQueue = m.mode; world.changed(q); } }
  st.matches.delete(m.id);
}
async function startMatch(world, m) {
  const d = dataOf(world), md = d[m.mode], st = state(world);
  const ok = [];
  for (const e of m.players) {
    const q = byId(world, e.id);
    let why = null;
    if (!q || !live(world, q)) continue;
    if (q.partyId && world.parties?.get(q.partyId)) why = COLOSSEUM_TEXT.partyEnter;
    else if (q.dead || q.instanceId || q.duelId || q.partyPvpId || q.tradeId || q.sceneTransition || fishingBusy(q)) why = COLOSSEUM_TEXT.enter;
    else if (m.mode === 'renew' && !ticketClone(world, q, md.ticket)) why = COLOSSEUM_TEXT.ticket;
    if (why) { q.colosseumId = null; noticeTo(world, q, why); continue; }
    ok.push(q);
  }
  const need = m.mode === 'individual' ? md.members * 2 : C.minEntrants.battleRoyal;
  if (ok.length < need || (m.mode === 'individual' && ok.length !== md.members * 2)) {
    requeue(world, m, ok.map(q => q.id));
    for (const q of ok) noticeTo(world, q, COLOSSEUM_TEXT.waiting);
    return false;
  }
  m.players = m.players.filter(e => ok.some(q => q.id === e.id));
  if (m.mode === 'individual') m.players.forEach((e, i) => { e.team = i % 2; });
  const clones = ok.map(q => (m.mode === 'renew' ? ticketClone(world, q, md.ticket) : structuredClone(q.profile)));
  const origin = new Map(ok.map(q => [q.id, { map: q.map, x: q.x, z: q.z }]));
  for (const q of ok) q.sceneTransition = true;
  const staged = stageInstanceMembers(world, ok, clones);
  let instance;
  try {
    const rounds = m.mode === 'classic' ? 4 : m.mode === 'renew' ? C.renewRounds : 1;
    const durationMs = ((m.mode === 'individual' ? C.matchReadySec + C.matchSec : C.startWaitSec + rounds * C.roundSec) + C.resultSec + 300) * 1000;
    instance = await createInstance(staged.world, { map: md.map, members: staged.candidates, kind: 'colosseum', exit: origin.get(ok[0].id), durationMs });
    instance.admitting = true; instance.exit = null;
    staged.candidates.forEach((q, i) => {
      const e = entrant(m, q);
      let cell;
      if (m.mode === 'classic') cell = md.starts[i % md.starts.length];
      else if (m.mode === 'renew') cell = md.enter;
      else { const side = md.starts[e.team]; cell = side[Math.floor(i / 2) % side.length]; }
      const at = instance.scene.nearest(cell.x + 0.5, cell.z + 0.5); if (!at) fail('No safe Colosseum start exists.', 503);
      q.x = at.x; q.z = at.z; q.profile.instance = { ...(q.profile.instance || {}), exit: origin.get(q.id) }; world.changed(q);
    });
    await world.persistMany(staged.candidates);
    await staged.commit();
    instance.admitting = false;
    for (const q of ok) { q.hp = q.maxHp; q.mp = q.stats.maxMp || 0; q.shield = Number(q.stats.maxShield) || 0; q.dead = false; delete q.pvpLastHit; world.changed(q); }
    if (m.mode === 'renew') for (const q of ok) world.emit(q.map, { type: 'inventory', actorId: q.id, reason: 'colosseum' });
  } catch (error) {
    if (instance) { world.instances.delete(instance.id); world.maps.delete(`${instance.map}@${instance.id}`); }
    for (const q of ok) q.sceneTransition = false;
    requeue(world, m, ok.map(q => q.id));
    throw error;
  } finally { for (const q of ok) q.sceneTransition = false; }
  const now = world.now();
  for (const e of m.players) e.entered = true;
  Object.assign(m, { instanceId: instance.id, map: md.map, startedAt: now });
  if (m.mode === 'individual') { m.phase = 'ready'; m.phaseEndsAt = now + C.matchReadySec * 1000; push(world, m, 100); }
  else { m.phase = 'wait'; m.phaseEndsAt = now + C.startWaitSec * 1000; push(world, m, m.mode === 'renew' ? 200 : 0, { kind: 'enter' }); }
  void st;
  return true;
}
function ticketClone(world, q, ticket) {
  const profile = structuredClone(q.profile), db = world.data.itemDB;
  if (!db) return null;
  const inv = new AuthoritativeInventory(profile, db, { now: world.now, random: world.random });
  return inv.remove(ticket, 1) ? profile : null;
}

// ------------------------------------------------------------------------------------------------ rounds
const roundCount = m => (m.mode === 'classic' ? 4 : C.renewRounds);
function startRound(world, m, n) {
  const now = world.now();
  m.phase = 'round'; m.round = n; m.phaseEndsAt = now + C.roundSec * 1000; m.roundOut = 0;
  if (m.mode === 'classic') { if (n === 1) push(world, m, 100); push(world, m, [200, 300, 400, 500][n - 1]); }
  else {
    if (n === 1) {
      const md = dataOf(world).renew, scene = world.instances?.get(m.instanceId)?.scene;
      for (const e of aliveOf(m)) { const q = byId(world, e.id); const at = scene?.nearest(md.battle.x + 0.5, md.battle.z + 0.5); if (q && at) { q.x = at.x; q.z = at.z; q.path = []; world.changed(q); world.emit(q.map, { type: 'revive', actorId: q.id, instanceId: q.instanceId }); } }
      push(world, m, 100);
    }
    if (n === roundCount(m)) push(world, m, 101);
    else push(world, m, 0, { kind: 'round' });
  }
}
/** Death roll (map 163:700, DeathRollWnd): fewest kills first, ties by the host's random roll. */
export function deathRollPick(players, count, random) {
  const roll = new Map(players.map(e => [e.id, random()]));
  return [...players].sort((a, b) => a.kills - b.kills || roll.get(a.id) - roll.get(b.id)).slice(0, Math.max(0, count));
}
function endRound(world, m) {
  const alive = aliveOf(m), last = m.round >= roundCount(m);
  let sentence = 0;
  if (m.mode === 'classic') sentence = alive.length - C.classicCaps[m.round - 1];
  else sentence = last ? alive.length - 1 : (m.roundOut ? 0 : 1);
  sentence = Math.min(Math.max(0, sentence), alive.length - 1);
  for (const e of deathRollPick(alive, sentence, () => world.random())) eliminate(world, m, e, 'sentenced');
}

// ------------------------------------------------------------------------------------------------ results
function ledger(r, at, add) { r.ledger.push({ at, ...add }); const keep = at - 62 * 86400000; r.ledger = r.ledger.filter(x => x.at >= keep).slice(-400); }
function bump(r, cat, field, n = 1) { r.records[cat][field] += n; r.records.total[field] += n; }
async function finish(world, m, reason) {
  if (m.phase === 'over') return;
  const d = dataOf(world), md = d[m.mode], now = world.now(), result = { mode: m.mode, reason, at: now, rows: [] };
  let teamWin = -1;
  if (m.mode === 'individual') {
    const alive = [0, 1].map(t => m.players.filter(e => e.team === t && !e.out).length);
    if (alive[0] && !alive[1]) teamWin = 0; else if (alive[1] && !alive[0]) teamWin = 1;
    else if (m.teamKills[0] !== m.teamKills[1]) teamWin = m.teamKills[0] > m.teamKills[1] ? 0 : 1;
    const top = Math.max(...m.players.map(e => e.kills)), tops = m.players.filter(e => e.kills === top);
    m.mvp = top > 0 && tops.length === 1 ? tops[0].id : null;
    result.winner = teamWin < 0 ? 'draw' : teamWin === 0 ? 'A' : 'B'; result.teamKills = [...m.teamKills]; result.mvp = m.mvp;
  } else {
    const alive = aliveOf(m);
    for (const e of alive) e.place = 1;
    if (alive.length > 1) alive.sort((a, b) => b.kills - a.kills).forEach((e, i) => { e.place = i + 1; });
    result.winner = m.players.find(e => e.place === 1)?.name || '';
  }
  const rewardFor = e => {
    if (m.mode === 'classic') {
      const row = md.rewards.find(r => r.index === C.classicRewardRow) || md.rewards[0], champ = e.place === 1;
      const reached = Math.min(4, Math.max(1, e.out ? e.outRound : m.round)) - 1, cp = (champ ? row.cpChamp : row.cp[reached]) + e.kills * row.cpKill + (e.buffs ? e.buffs * num(row.cpBuff) : 0);
      return { coinItem: C.classicCoinItem, coin: champ ? row.coinChamp : row.coin[reached], cp, br: cp, party: 0, win: champ };
    }
    if (m.mode === 'renew') {
      const row = md.rewards.find(r => e.place >= r.low && e.place <= r.high);
      const pts = (row?.rankPoint || 0) + e.kills * (row?.killPoint || md.rewards[0]?.killPoint || 0);
      return { item: row?.item || 0, count: row?.count || 0, coin: 0, cp: 0, br: pts, party: 0, win: e.place === 1 };
    }
    const row = md.rewards.find(r => r.section === m.grade) || md.rewards[0], k = teamWin < 0 ? 'D' : e.team === teamWin ? 'W' : 'L';
    const cp = (e.kills * row.cpKill + (k === 'W' ? row.cpWin : 0)) * (m.mvp === e.id ? row.mvpRate : 1);
    return { coinItem: row.coinItem, coin: row.coin[k], cp, br: 0, party: row.pcp[k], outcome: k, win: k === 'W' };
  };
  for (const [idx, e] of m.players.entries()) {
    e.reward = rewardFor(e);
    result.rows.push({ id: e.id, name: e.name, classIndex: e.classIndex, level: e.level, server: C.serverName, kills: e.kills, buffs: e.buffs || 0, place: e.place ?? null, team: e.team, out: e.out, enter: idx + 1, reward: { pending: true } });
  }
  if (m.mode !== 'individual') result.rows.sort((a, b) => a.place - b.place);
  m.phase = 'over'; m.finishAt = now + C.resultSec * 1000; m.result = result;
  clearCrystals(world, m);
  for (const e of m.players) { const q = byId(world, e.id); if (q && q.colosseumId === m.id) stripBlessings(world, q); }
  settlements.set(m, { entries: m.players.map(e => ({ e, actor: participantActors.has(e) ? participantActors.get(e) : byId(world, e.id), done: false })), published: false });
  await settleRewards(world, m);
}
async function settleRewards(world, m) {
  const pending = settlements.get(m); if (!pending) return true;
  const now = m.result.at, cat = m.mode === 'individual' ? 'party' : 'battleroyal';
  for (const entry of pending.entries) {
    if (entry.done) continue;
    const { e, actor: q } = entry;
    // Never transfer an old actor's pending grant to a replacement session.
    if (!q || !live(world, q) || byId(world, e.id) !== q || q.colosseumId !== m.id) { entry.done = true; continue; }
    const r = e.reward;
    try { await serializeLife(q, async () => {
      if (!live(world, q) || byId(world, e.id) !== q || q.colosseumId !== m.id) { entry.done = true; return; }
      const profile = structuredClone(q.profile), db = world.data.itemDB, inv = db ? new AuthoritativeInventory(profile, db, { now: world.now, random: world.random }) : null;
      const cr = recordOf(profile);
      const prior = cr.ledger.find(x => x.colosseumMatch === m.id);
      let full = prior ? !prior.delivered : false;
      if (!prior) {
        cr.points.colosseumPoint += r.cp; cr.points.brPoint += r.br; cr.points.partyPoint += r.party;
        bump(cr, cat, 'kills', e.kills); if (e.out) bump(cr, cat, 'died');
        if (m.mode === 'individual') bump(cr, cat, r.outcome === 'W' ? 'wins' : r.outcome === 'L' ? 'defeats' : 'draws'); else bump(cr, cat, r.win ? 'wins' : 'defeats');
        if (inv && r.coin && r.coinItem && !inv.add(r.coinItem, r.coin)) full = true;
        if (inv && r.item && r.count && !inv.add(r.item, r.count)) full = true;
        ledger(cr, now, { cp: r.cp, br: r.br, party: r.party, colosseumMatch: m.id, delivered: !full });
        await commitLife(world, q, profile);
      }
      // Mark committed before notifications: their failure cannot replay grants.
      entry.done = true; r.delivered = !full;
      m.result.rows.find(row => row.id === e.id).reward = { ...r };
      if (!live(world, q) || byId(world, e.id) !== q || q.colosseumId !== m.id) return;
      q.colosseumResult = { ...structuredClone(m.result), me: e.id, team: e.team, outcome: r.outcome || (r.win ? 'W' : 'L'), reward: { ...r } };
      world.changed(q);
      world.emit(q.map, { type: 'inventory', actorId: q.id, reason: 'colosseum' });
      if (full) noticeTo(world, q, COLOSSEUM_TEXT.bagFull);
    }); } catch { /* An uncommitted grant remains pending for the next tick. */ }
  }
  if (pending.entries.some(e => !e.done)) return false;
  if (pending.published) return true;
  pending.published = true;
  for (const { e, actor: q } of pending.entries) {
    if (!q || !live(world, q) || byId(world, e.id) !== q || q.colosseumId !== m.id || rPending(e)) continue;
    q.colosseumResult = { ...structuredClone(m.result), me: e.id, team: e.team, outcome: e.reward.outcome || (e.reward.win ? 'W' : 'L'), reward: { ...e.reward } };
  }
  if (m.mode === 'individual') push(world, m, 0, { kind: 'result' }); else push(world, m, m.mode === 'classic' ? 600 : 0, { kind: 'result' });
  if (m.mode === 'individual') for (const e of m.players) {
    const q = byId(world, e.id); if (!q) continue;
    const k = e.reward.outcome; m.seq++; m.events.push({ seq: m.seq, code: k === 'W' ? 300 : k === 'L' ? 400 : 500, map: m.map, at: now, only: e.id });
  }
  changedAll(world, m);
  return true;
}
const rPending = e => !Object.hasOwn(e.reward, 'delivered');

export async function tickColosseum(world) {
  void tickCarnival(world).catch(() => {});
  const d = world.data?.colosseum; if (!d?.classic || world._colosseumTicking) return;
  world._colosseumTicking = true;   // a match start / result awaits the store: never run two ticks at once
  try { await colosseumStep(world, d); } finally { world._colosseumTicking = false; }
}
async function colosseumStep(world, d) {
  const st = state(world), now = world.now();
  for (const p of world.players.values()) if (!p.leaving && blessed(p)) { const m = current(world, p); if (!m || m.phase === 'over' || m.closed || entrant(m, p)?.out) stripBlessings(world, p); }
  // queues: drop gone players, close Battle Royale queues outside the playtime, form matches
  for (const mode of MODES) {
    const q = st.queues[mode];
    for (let i = q.length - 1; i >= 0; i--) {
      const p = byId(world, q[i].id);
      if (!p || !live(world, p) || p.colosseumQueue !== mode) { q.splice(i, 1); continue; }
      if (!colosseumOpen(d[mode], now)) { q.splice(i, 1); p.colosseumQueue = null; noticeTo(world, p, mode === 'individual' ? COLOSSEUM_TEXT.matchTime : COLOSSEUM_TEXT.brTime); }
    }
    if (mode === 'individual') {
      const need = d.individual.members * 2;
      for (const g of [...new Set(q.map(e => e.grade))]) { const cur = st.queues[mode], list = cur.filter(e => e.grade === g); if (list.length >= need) { const take = list.slice(0, need); st.queues[mode] = cur.filter(e => !take.includes(e)); form(world, mode, take); } }
    } else if (q.length >= d[mode].members) form(world, mode, q.splice(0, d[mode].members));
  }
  for (const m of [...st.matches.values()]) {
    if (m.phase === 'prompt') {
      m.players = m.players.filter(e => { const q = byId(world, e.id); return q && live(world, q); });
      if (now >= m.promptEndsAt || m.players.every(e => e.answer === 'accept')) { try { await startMatch(world, m); } catch (error) { st.lastError = error?.message || String(error); /* requeued */ } }
      continue;
    }
    if (m.closed) continue;
    if (m.phase === 'over' && !await settleRewards(world, m)) continue;
    // a participant who left the arena (disconnect, exit) is out
    for (const e of m.players) {
      const q = byId(world, e.id);
      const inside = q && live(world, q) && q.instanceId === m.instanceId;
      if (!inside && !e.out && m.phase !== 'over') eliminate(world, m, e, 'left');
      else if (inside && !e.out && (q.hp <= 0 || q.dead) && m.phase !== 'over') eliminate(world, m, e, 'killed');
    }
    if (m.phase === 'wait' && now >= m.phaseEndsAt) { startRound(world, m, 1); continue; }
    if (m.phase === 'ready' && now >= m.phaseEndsAt) { m.phase = 'fight'; m.phaseEndsAt = now + C.matchSec * 1000; push(world, m, 200); continue; }
    if (m.phase === 'round') {
      if (aliveOf(m).length <= 1) { await finish(world, m, 'survivor'); continue; }
      if (now >= m.phaseEndsAt) {
        endRound(world, m);
        if (aliveOf(m).length <= 1 || m.round >= roundCount(m)) await finish(world, m, 'survivor'); else startRound(world, m, m.round + 1);
      }
      continue;
    }
    if (m.phase === 'fight') {
      const alive = [0, 1].map(t => m.players.filter(e => e.team === t && !e.out).length);
      if (alive.some(n => n === 0)) await finish(world, m, 'annihilation'); else if (now >= m.phaseEndsAt) await finish(world, m, 'time');
      continue;
    }
    if (m.phase === 'over' && now >= m.finishAt) {
      const inside = m.players.map(e => byId(world, e.id)).filter(q => q && live(world, q) && q.instanceId === m.instanceId);
      if (!m.closing) {
        m.closing = true; const rules = world.data.pvpRules || { reviveHpRatio: 100, reviveMpRatio: 100 };
        for (const q of inside) { q.dead = false; q.hp = Math.max(1, Math.round(q.maxHp * rules.reviveHpRatio / 100)); q.mp = Math.round((q.stats.maxMp || 0) * rules.reviveMpRatio / 100); q.path = []; world.changed(q); world.emit(q.map, { type: 'revive', actorId: q.id, instanceId: q.instanceId }); }
      }
      const instance = world.instances?.get(m.instanceId);
      if (instance && inside.length) { requestInstanceClose(world, instance); continue; }
      m.closed = true; st.matches.delete(m.id);
      for (const e of m.players) { const q = byId(world, e.id); if (q && q.colosseumId === m.id) { q.colosseumId = null; world.changed(q); } }
    }
  }
}

// ------------------------------------------------------------------------------------------------ ranking
const isoWeek = t => { const d = serverDate(t); d.setUTCHours(0, 0, 0, 0); d.setUTCDate(d.getUTCDate() + 3 - ((d.getUTCDay() + 6) % 7)); const y = new Date(Date.UTC(d.getUTCFullYear(), 0, 4)); return `${d.getUTCFullYear()}-${1 + Math.round(((d - y) / 86400000 - 3 + ((y.getUTCDay() + 6) % 7)) / 7)}`; };
const monthKey = t => { const d = serverDate(t); return `${d.getUTCFullYear()}-${d.getUTCMonth()}`; };
function guildName(world, ref) {
  const gs = world.socialState?.guilds, list = Array.isArray(gs) ? gs : gs instanceof Map ? [...gs.values()] : Object.values(gs || {});
  return (ref && list.find(g => (g?.members || []).some(x => x?.ref === ref))?.name) || '';
}
const CAT_POINT = { total: ['colosseumPoint', 'cp'], battleroyal: ['brPoint', 'br'], party: ['partyPoint', 'party'] };
/** ui_rankingwnd rows: every character with a Colosseum record known to this host (directory + online players). */
export async function colosseumRanking(world, p, input = {}) {
  const cat = CAT_POINT[input.category] ? input.category : 'total', period = ['whole', 'week', 'month'].includes(input.period) ? input.period : 'whole', now = world.now();
  const rows = new Map();
  if (world.listCharacters) for (const c of await Promise.resolve().then(() => world.listCharacters()).catch(() => [])) if (c?.colosseum) rows.set(c.name, { name: c.name, classIndex: num(c.classIndex), level: num(c.level), guild: guildName(world, c.ref), colosseum: c.colosseum });
  for (const q of world.players.values()) if (!q.leaving && q.profile.colosseum) rows.set(q.profile.name, { name: q.profile.name, classIndex: num(q.profile.classIndex), level: levelOf(q), guild: guildName(world, socialRef(q)), colosseum: q.profile.colosseum });
  const [field, lf] = CAT_POINT[cat], key = period === 'week' ? isoWeek : period === 'month' ? monthKey : null;
  const list = [...rows.values()].map(r => {
    const c = r.colosseum, rc = c.records?.[cat] || rec();
    const points = key ? (c.ledger || []).filter(x => key(x.at) === key(now)).reduce((n, x) => n + num(x[lf]), 0) : num(c.points?.[field]);
    return { name: r.name, classIndex: r.classIndex, level: r.level, guild: r.guild, server: C.serverName, points, wins: num(rc.wins), defeats: num(rc.defeats), kills: num(rc.kills), died: num(rc.died) };
  }).sort((a, b) => b.points - a.points || b.wins - a.wins || a.name.localeCompare(b.name));
  list.forEach((r, i) => { r.rank = i + 1; });
  return { category: cat, period, rows: list, me: list.find(r => r.name === p.profile.name)?.rank || null };
}

// ------------------------------------------------------------------------------------------------ snapshot
export function colosseumSnapshot(world, p) {
  const d = world.data?.colosseum, carnival = carnivalSnapshot(world, p); if (!d?.classic) return carnival ? { carnival } : null;
  const st = state(world), now = world.now(), m = current(world, p);
  const r = p.profile.colosseum;
  const out = { open: Object.fromEntries(MODES.map(k => [k, colosseumOpen(d[k], now)])), queue: p.colosseumQueue || null, queuedAt: p.colosseumQueuedAt || null,
    waiting: p.colosseumQueue ? st.queues[p.colosseumQueue].length : 0, notice: p.colosseumNotice || null, result: p.colosseumResult || null,
    points: r?.points || null, records: r?.records || null, match: null, carnival };
  if (!m) return out;
  const me = entrant(m, p);
  out.match = { id: m.id, mode: m.mode, phase: m.phase, map: m.map, round: m.round, rounds: m.mode === 'individual' ? 1 : roundCount(m), promptEndsAt: m.promptEndsAt, phaseEndsAt: m.phaseEndsAt || null, finishAt: m.finishAt || null,
    answer: me?.answer || null, out: me?.out || null, team: me?.team ?? null, kills: me?.kills || 0, buffs: me?.buffs || 0, teamKills: m.teamKills, alive: aliveOf(m).length, crystals: m.crystals?.size || 0,
    players: m.players.map(e => ({ id: e.id, name: e.name, classIndex: e.classIndex, level: e.level, server: C.serverName, kills: e.kills, buffs: e.buffs || 0, out: e.out, place: e.place ?? null, team: e.team })),
    events: m.events.filter(x => !x.only || x.only === p.id), enemies: m.players.filter(e => e.id !== p.id && colosseumEnemy(world, p, byId(world, e.id))).map(e => e.id) };
  return out;
}
