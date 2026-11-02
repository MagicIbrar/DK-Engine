// Lane 59 (d): the Dead Front script operations on the shared host, so an online run gets the same proven behaviour as
// the solo client run (src/systems/events/deadfront.js). Every value comes from src/config/dead-front-script-extras.js
// ('older server reference' = server-ref ScriptProcess.dll Dead_Front_<class> / _DK, decoded as data only;
// 'Global' = the popup strings and item names). No new request type: the host uses its existing event snapshot,
// ground loot, 'reward' / 'event:message' events and durable instance progress, so old clients keep working.
//   Op1034  GiveExp(n) to every player on the map   -> durable instance progress (world.grantProgress + server EXP rate),
//                                                      mid boss only in stage 3, final boss on its death (deadfront.js)
//   Op1c20  kill-all of two ids (final boss death)  -> the host wave records are taken off the map (no kill credit)
//   Op1c28  kill-all (close step, before treasure)  -> the same, every live event monster
//   Op101ae item drop at a cell (treasure monsters) -> a ground item at the cell, owned by the killer for the Global
//                                                      formula.ini dwOwnershipLifeTime (the host's normal drop rule)
//   OnLevelUp gifts (Rabble / Peer scripts)         -> room check, give, else drop at the player; then the Global popup
//                                                      string to that player only (the host has no client 'levelup' bus,
//                                                      so the run watches its members' levels each tick)
import { levelUpGift } from '../../src/config/dead-front-script-extras.js';
import { createItem } from '../../src/systems/items/model.js';
import { AuthoritativeInventory } from './inventory.mjs';
import { grantGroundItem } from './loot.mjs';
import { queueInstanceProgress } from './instance-progress.mjs';
import { scaledReward } from './rates.mjs';

const byId = (world, id) => (id && [...world.players.values()].find(q => q.id === id && !q.leaving)) || null;
const members = (world, i) => [...world.players.values()].filter(q => !q.leaving && q.instanceId === i.id);

/** Item+0x4c / the gift fallback: `count` of item on the ground at (x, z) for owner (stack-size chunks, like monster loot). */
export function dropItemAt(world, owner, itemIndex, count, x, z) {
  const db = world.data.itemDB, def = db?.def(Number(itemIndex));
  if (!owner || !def) return [];
  const stack = Math.max(1, Number(db.stackSize(def)) || 1), out = [];
  for (let left = Math.max(1, Number(count) || 1); left > 0;) {
    const n = Math.min(left, stack); left -= n;
    const inst = createItem(db, Number(itemIndex), { count: n, now: world.now(), rng: world.random });
    const d = grantGroundItem(world, owner, { ...inst, itemIndex: Number(itemIndex), name: def.name || `Item ${itemIndex}`, count: inst.count ?? n });
    d.x = x; d.z = z; out.push(d);
  }
  return out;
}

/** Op1034 GiveExp: every player in the run (durable; the job key makes it once per run and boss). */
export function giveExpAll(world, i, exp, key) {
  if (!(Number(exp) > 0)) return false;
  queueInstanceProgress(world, i, `df-exp:${i.id}:${key}`, (p, facade) => {
    const gain = scaledReward(exp, world.rates?.exp ?? 1);
    world.grantProgress.call(facade, p, gain);
    facade.emit(p.map, { type: 'reward', actorId: p.id, exp: gain, dil: 0 });
  });
  return true;
}

/** Op1c20 (ids) / Op1c28 (no ids): take the live event monsters off the map without kill credit. */
export function killAllHost(waves, ids = null) {
  const set = ids ? new Set(ids.map(Number)) : null;
  let n = 0;
  for (const g of [...(waves?.groups?.values() || [])]) for (const m of [...g.recs]) {
    if (m.dead || m._eventCounted) continue;                          // a death this tick still gets its kill
    if (set && !set.has(Number(m.monsterIndex))) continue;
    waves.removeMonster(m); n++;
  }
  return n;
}

/** OnLevelUp gift for one player and level: room check -> give, else drop at the player; then the popup to that player. */
export function giftLevel(world, i, run, p, level) {
  const g = levelUpGift(run.map, level, Number(p.profile?.classIndex) || 0);
  if (!g) return null;
  const dropped = [];
  queueInstanceProgress(world, i, `df-lvgift:${i.id}:${p.id}:${level}`, q => {
    if (q.id !== p.id) return;
    dropped.length = 0;
    const opts = { now: world.now, random: world.random };
    let inv = new AuthoritativeInventory(q.profile, world.data.itemDB, opts);
    for (const [item, count, roomItem = item] of g.items) {
      const before = structuredClone(q.profile.inventory || []);
      if (inv.canFit([{ item: Number(roomItem), count }]) && inv.add(Number(item), count)) continue;
      q.profile.inventory.splice(0, q.profile.inventory.length, ...before);   // no partial stack left behind
      inv = new AuthoritativeInventory(q.profile, world.data.itemDB, opts);
      dropped.push([Number(item), count]);
    }
  }, () => {
    const live = byId(world, p.id);
    if (live) for (const [item, count] of dropped) dropItemAt(world, live, item, count, live.x, live.z);
    if (g.popup != null && live) { i.sayTo = [p.id]; try { run.say(g.popup); } finally { i.sayTo = null; } }
  });
  return g;
}

/** Level watch: each member's level rise inside the run fires the gift of every level gained (the host emits one
 *  'levelup' per level, so per level here too). The first sighting only records the level. */
export function watchLevels(world, i, run) {
  if (!run.extra?.levelUpGifts || run.ended) return;
  const seen = (i.dfLevels ||= new Map());
  for (const p of members(world, i)) {
    const lv = Number(p.profile?.level) || 0, was = seen.get(p.id);
    seen.set(p.id, lv);
    if (was == null || lv <= was) continue;
    for (let level = was + 1; level <= lv; level++) giftLevel(world, i, run, p, level);
  }
}

/** Install on a prepared Dead Front run (after installPartyWar, before run.start()). Ice Castle is untouched. */
export function installDeadFrontHost(world, i, run) {
  if (i.kind !== 'deadFront' || !run?.extra) return false;
  run._giveExp = (exp, key) => giveExpAll(world, i, exp, key);
  run.waves.killAll = ids => killAllHost(run.waves, ids);
  run._dropAt = (item, x, y) => dropItemAt(world, byId(world, i.creditId) || i.actor?.() || members(world, i)[0], item, 1, x + 0.5, y + 0.5)[0] || null;
  run._levelUp = () => null;                                          // the host gifts come from watchLevels
  const tick = run.tick.bind(run);
  run.tick = dt => { tick(dt); watchLevels(world, i, run); };
  return true;
}