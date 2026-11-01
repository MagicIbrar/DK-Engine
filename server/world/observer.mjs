// OBSERVER host service (action 'observer'): npc job 40 ENTER_GUILD_OBSERVER (Blake 135, Cain 734) seats a spectator in
// the guild venue (share/guildobserver/info.csv, map 22 Undo Stadion) or the siege venue (share/observer/info.csv,
// map 23 Zenoa Castle, 10 warp areas). Rules: src/systems/observer/observer-rules.js; values the data does not define:
// src/config/engine-chosen-observer.js (ENGINE-CHOSEN). The seat registers with server/world/observers.mjs, so the
// SharedWorld observer hooks hide the observer from other players, keep monsters and PvP off them, and allow only
// OBSERVER_CHOSEN.actions. Operations: info | enter {venue, npcIndex} | warp {area} | exit.
import fs from 'node:fs';
import path from 'node:path';
import { parseCSV, decodeText } from '../../src/formats/binreader.js';
import { defaultRoots, worldRoots } from './prepared-roots.mjs';
import { OBSERVER_CHOSEN as C } from '../../src/config/engine-chosen-observer.js';
import { OBSERVER_JOB, OBSERVER_FILES, OBSERVER_ERRORS as E, buildObserverVenues, enterProblem, cooldownLeft, cameraSpeed } from '../../src/systems/observer/observer-rules.js';
import { registerObserverMode, isObserver } from './observers.mjs';
import { enterTrustedScene,stageInstanceMembers } from './instances.mjs';
import { AuthoritativeInventory } from './inventory.mjs';
import { socialRef } from './social-state.mjs';
import { sideOf } from './siege.mjs';
import { nearbyNpc } from './npc-services.mjs';
import { pvpOpponents } from './pvp.mjs';
import {isRenewObserverVenue,renewObserverInfo,renewObserverRecord,enterRenewObserver,warpRenewObserver,exitRenewObserver} from './siege-renew-observer.mjs';

export const OBSERVER_SCHEMAS = { observer: ['token', 'type', 'operation', 'venue', 'npcIndex', 'area', 'enabled'] };
const OPERATIONS = new Set(['info', 'enter', 'warp', 'exit', 'camera']);
function fail(message, status = 400) { throw Object.assign(new Error(message), { status }); }

/**
 * Read both observer tables (Korean area names decode as EUC-KR). world.data.observerVenues overrides for tests. Without a root:
 * the active prepared generation (server/world/prepared-roots.mjs; an install has no ../data/unpacked/data). A table that cannot be
 * read is NOT silent any more: its path is listed on the result's non-enumerable `missing` array (info reports it, enter refuses
 * with it) and logged once.
 */
export function loadObserverVenues(dataRoot) {
  dataRoot = defaultRoots({ dataRoot }).dataRoot;
  const missing = [];
  const read = (rel, korean) => { try { return parseCSV(decodeText(fs.readFileSync(path.join(dataRoot, rel)), korean)); } catch (error) { missing.push(`${rel} (${error.code || error.message})`); return null; } };
  const venues = buildObserverVenues({ siegeRows: read(OBSERVER_FILES.siege, true), guildRows: read(OBSERVER_FILES.guild, true), mapRows: read(OBSERVER_FILES.maps, false) });
  Object.defineProperty(venues, 'missing', { value: missing, enumerable: false });
  if (missing.length) console.warn(`[observer] tables unavailable under ${dataRoot}: ${missing.join(', ')}`);
  return venues;
}
export function observerVenues(world) { return world.observerVenues ||= world.data?.observerVenues || loadObserverVenues(worldRoots(world).dataRoot); }
const missingTables = venues => (Array.isArray(venues?.missing) && venues.missing.length ? venues.missing : null);
const seats = world => world.observerSeats ||= new Map();
const leftAt = world => world.observerLeftAt ||= new Map();
const keyOf = p => String(p.characterId ?? p.profile?.characterId ?? p.id);
/** The observer seat of p, or null; a seat whose player left the venue map (or entered an instance) is dropped. */
export function observerSeat(world, p) {
  if (!p) return null;
  const s = world.observerSeats?.get(keyOf(p)); if (!s) return null;
  if (p.map !== s.map || (isRenewObserverVenue(s.venue) ? !renewObserverRecord(world,p) : !!p.instanceId)) { world.observerSeats.delete(keyOf(p)); return null; }
  return s;
}
const isSeated = (world, p) => !!observerSeat(world, p);
export const OBSERVER_MODE_ACTIONS = new Set(C.actions);
registerObserverMode({ is: isSeated, actions: OBSERVER_MODE_ACTIONS });

function venueCount(world, key) { let n = 0; for (const p of world.players?.values?.() || []) if (!p.leaving && observerSeat(world, p)?.venue === key) n++; return n; }
/** A venue is open when the shared host can load its map (data.mjs keeps siege maps out of the shared field world today). */
export async function venueAvailable(world, v) {
  const cache = world.observerAvailable ||= new Map();
  if (!cache.has(v.map)) cache.set(v.map, Promise.resolve().then(() => world.data.map(v.map, { instance: !!world.data.requiresInstance?.(v.map) })).then(() => true, () => false));
  return cache.get(v.map);
}
function publicVenue(world, v, available) {
  return { key: v.key, name: v.name, map: v.map, available, max: v.max, count: venueCount(world, v.key), enterEnableMs: v.enterEnableMs, cameraSpeed: cameraSpeed(v),
    areas: v.areas.map(a => ({ index: a.index, textCode: a.textCode, x: a.x, z: a.z })) };
}
/** Restore a seat after a host restart when the durable profile still says the player is observing on the venue map. */
function restoreSeat(world, p) {
  const saved = p.profile?.observer, v = saved && observerVenues(world)[saved.venue];
  if (!v || p.map !== v.map || p.instanceId || observerSeat(world, p)) return;
  seats(world).set(keyOf(p), { venue: v.key, map: v.map, from: saved.from, since: world.now() });
}
export async function observerInfo(world, p) {
  restoreSeat(world, p);
  const venues = observerVenues(world), seat = observerSeat(world, p), list = Object.values(venues);
  const open = await Promise.all(list.map(v => venueAvailable(world, v)));
  const missing = missingTables(venues);
  const renew=renewObserverInfo(world,p);
  return { venues: {...Object.fromEntries(list.map((v, i) => [v.key, publicVenue(world, v, open[i])])),...renew.venues},
    seat: seat ? { venue: seat.venue, map: seat.map, from: seat.from,...(seat.instanceId?{instanceId:seat.instanceId,channel:0}:{}) } : null,
    waitMs: {...Object.fromEntries(Object.values(venues).map(v => [v.key, cooldownLeft(v, leftAt(world).get(keyOf(p)), world.now())])),...renew.waitMs},
    ...(missing ? { missingTables: missing } : {}) };
}
const info=observerInfo;
const arrival = (v, at) => ({ x: Number(at.x) + .5, z: Number(at.z) + .5 });

async function enter(world, p, input) {
  if(isRenewObserverVenue(input.venue)){await enterRenewObserver(world,p,input);return info(world,p);}
  const venues = observerVenues(world), v = venues[input.venue];
  // a venue whose table could not be read on this host: say so instead of the generic "no such venue"
  if (!v && missingTables(venues)) fail(`Observer venue unavailable on this host: ${missingTables(venues).join(', ')} could not be read.`, 503);
  const jobType=v?.key==='siege'?36:OBSERVER_JOB;
  const near = Number.isInteger(input.npcIndex) ? nearbyNpc(world, p, { npcIndex: input.npcIndex, jobType, radius: C.npcRadius }) : nearbyNpc(world, p, { jobType, radius: C.npcRadius });
  const problem = enterProblem({ venue: v && C.jobVenues.includes(v.key) ? v : null, observing: isObserver(world, p), dead: p.dead, instance: !!p.instanceId,
    busy: !!p.sceneTransition || !!p.tradeCommitting || pvpOpponents(world, p).length > 0, nearNpc: !!near,
    count: v ? venueCount(world, v.key) : 0, cooldownMs: v ? cooldownLeft(v, leftAt(world).get(keyOf(p)), world.now()) : 0 });
  if (problem) fail(E[problem], { npc: 403, full: 409, observing: 409, wait: 429 }[problem] || 400);
  if(v.key==='siege'){
    if(near.npcIndex!==753&&near.index!==753&&Number(input.npcIndex)!==753)fail(E.npc,403);
    if(world.siegeLive?.battle?.phase!=='battle')fail('siege:241:14',409);
    const guild=Object.values(world.socialState?.guilds||{}).find(g=>g.members?.some(m=>m.ref===socialRef(p)));
    if(sideOf(world,guild?.id))fail('siege:241:16',403);
  }
  if (!v.entry) fail(E.noAreas, 503);
  if (!(await venueAvailable(world, v))) fail(E.closed, 503);
  // Native tickets 54501/54502 (item descriptions 18/19, strings 2100:10/15).
  // Stage both inventory and seat: a failed write must neither charge nor transport.
  const ticket=C.consumeItem[v.key];
  const from={map:p.map,x:p.x,z:p.z},staged=stageInstanceMembers(world,[p],[structuredClone(p.profile)]),q=staged.candidates[0];
  if(!new AuthoritativeInventory(q.profile,world.data.itemDB,{now:world.now}).remove(ticket,1))fail('siege:241:12',409);
  q.profile.observer={venue:v.key,from};
  const transition=p.sceneTransition;p.sceneTransition=true;
  try{
    await enterTrustedScene(staged.world,q,v.map,arrival(v,v.entry),{kind:'observer'});
    await world.persist(q);await staged.commit();
    seats(world).set(keyOf(p),{venue:v.key,map:v.map,from,since:world.now()});
  }finally{p.sceneTransition=transition;}
  return info(world, p);
}
async function warp(world, p, input) {
  const seat = observerSeat(world, p); if (!seat) fail(E.notObserving, 409);
  if(isRenewObserverVenue(seat.venue)){await warpRenewObserver(world,p,input);return info(world,p);}
  const v = observerVenues(world)[seat.venue]; if (!v?.areas.length) fail(E.noAreas);
  if(!seat.camera)fail('siege:241:9',409);
  const a = Number.isInteger(input.area) ? v.areas.find(r => r.index === input.area) : null; if (!a) fail(E.area);
  await enterTrustedScene(world, p, v.map, arrival(v, a), { kind: 'observer',durable:true });
  return info(world, p);
}
async function exit(world, p) {
  const seat = observerSeat(world, p); if (!seat) fail(E.notObserving, 409);
  if(isRenewObserverVenue(seat.venue)){await exitRenewObserver(world,p);return info(world,p);}
  const back = seat.from || p.profile.observer?.from;
  const staged=stageInstanceMembers(world,[p],[structuredClone(p.profile)]),q=staged.candidates[0],transition=p.sceneTransition;
  delete q.profile.observer;p.sceneTransition=true;
  try{await enterTrustedScene(staged.world,q,back.map,{x:back.x,z:back.z},{kind:'observer'});await world.persist(q);await staged.commit();}
  finally{p.sceneTransition=transition;}
  seats(world).delete(keyOf(p));leftAt(world).set(keyOf(p),world.now());
  return info(world, p);
}
/** Dispatch one 'observer' action; the result rides back as {observerResult}. */
export async function observerCommand(world, p, input) {
  if (Object.keys(input).some(k => !OBSERVER_SCHEMAS.observer.includes(k)) || !OPERATIONS.has(input.operation)) fail('Invalid observer request.');
  if(input.operation==='camera'){
    const seat=observerSeat(world,p);if(!seat)fail(E.notObserving,409);
    if(typeof input.enabled!=='boolean')fail('Invalid observer camera state.');
    seat.camera=input.enabled;return {observerResult:{operation:'camera',...await info(world,p)}};
  }
  const result = input.operation === 'enter' ? await enter(world, p, input) : input.operation === 'warp' ? await warp(world, p, input)
    : input.operation === 'exit' ? await exit(world, p) : await info(world, p);
  return { observerResult: { operation: input.operation, ...result } };
}
