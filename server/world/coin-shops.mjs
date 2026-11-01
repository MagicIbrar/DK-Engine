// COIN-SHOPS host transaction: the coin exchange (job 164, Karin) and the currency trade (job 165, Sinan) windows send
// only {operation, rows:[[itemIndex, count]]}; the host checks the NPC is near, prices everything with the shared rules
// (src/systems/shops/coin-shops-rules.js), and commits coins, DIL, EXP and Grade points in one durable write.
//   rankup    Rank-Up Coin (Bind) -> profile.life.grade.totalExp (+ the one-time stat / skill gifts of newly reached rows)
//   expup     EXP coins -> the core grantProgress level-up path (staged, like fishing)
//   sale      gold items -> DIL minus the sale fee
//   purchase  DIL plus the purchase fee -> gold items
import { AuthoritativeInventory } from './inventory.mjs';
import { nearbyNpc } from './npc-services.mjs';
import { serializeLife, commitLife } from './life-transactions.mjs';
import { coinQuote, gradeRowsOf, gradeAt, COIN_SHOP_KINDS, COIN_SHOP_JOB, COIN_SHOP_ERRORS, MAX_HOST_DIL } from '../../src/systems/shops/coin-shops-rules.js';
import { COIN_SHOP_CONFIG as C } from '../../src/systems/shops/coin-shops-config.js';
import {assertNieteService} from './niete-services.mjs';
import {claimEligibleGradeRewards} from '../../src/game/grade-rewards.js';

export const COIN_SHOP_ACTION_SCHEMAS = { coinshop: ['token', 'type', 'operation', 'rows'] };
function fail(message, status = 400) { throw Object.assign(new Error(message), { status }); }

export function coinShopAction(world, p, input) {
  if (Object.keys(input).some(k => !COIN_SHOP_ACTION_SCHEMAS.coinshop.includes(k)) || !COIN_SHOP_KINDS.includes(input.operation)) fail(COIN_SHOP_ERRORS.invalid);
  return serializeLife(p, async () => {
    assertNieteService(world,p);
    if (p.dead) fail('You cannot trade while dead.');
    const db = world.data.itemDB; if (!db) fail('Item catalog is unavailable.', 503);
    if (!nearbyNpc(world, p, { jobType: COIN_SHOP_JOB[input.operation], radius: C.npcRadius })) fail('Walk near the coin exchange NPC first.', 403);
    const profile = structuredClone(p.profile), inv = new AuthoritativeInventory(profile, db, { now: world.now, random: world.random });
    const grades = gradeRowsOf(world.data.nameplateGrades);
    const q = coinQuote(input.operation, input.rows, {
      have: i => inv.count(i), dil: inv.dil, level: profile.level, exp: profile.exp, maxLevel: world.data.maxLevel || 250,
      expNeeded: l => world.data.expNeeded(l), grades, gradeExp: profile.life?.grade?.totalExp, dilCap: MAX_HOST_DIL });
    if (!q.ok) fail(COIN_SHOP_ERRORS[q.error] || COIN_SHOP_ERRORS.invalid);
    for (const [index, n] of q.spend) if (!inv.remove(index, n)) fail(COIN_SHOP_ERRORS.material);
    for (const [index, n] of q.give) if (!inv.add(index, n)) fail(COIN_SHOP_ERRORS.bagFull);
    if (q.dilIn) inv.addDil(q.dilIn);
    if (q.dilOut) profile.dil = inv.dil - q.dilOut;
    const actor = { ...p, profile }, events = [];
    if (q.exp > 0) world.grantProgress.call({ ...world, changed() {}, emit: (map, event) => events.push([map, event]) }, actor, q.exp, 0);
    if (q.points > 0) {
      profile.life ||= {};
      const g = profile.life.grade = { ...(profile.life.grade || {}) };
      g.totalExp = (Number(g.totalExp) || 0) + q.points; g.claimed = { ...(g.claimed || {}) };
      claimEligibleGradeRewards(profile,world.data.nameplateGrades);
      const row = gradeAt(grades, g.totalExp, profile.level || 1);
      if (row) g.rowKey = row.key;
    }
    const leveled = profile.level > p.profile.level;
    const committed = await commitLife(world, p, profile, { rewardProgress: q.exp > 0, ...(leveled ? { stats: actor.stats, hp: actor.hp, mp: actor.mp } : {}) });
    for (const [map, event] of [...events.filter(([, e]) => e.type !== 'levelup' || e.level > committed.concurrentLevel), ...committed.notices]) world.emit(map, event);
    world.emit(p.map, { type: 'inventory', actorId: p.id, reason: 'coinshop' });
    world.emit(p.map, { type: 'coinshop', actorId: p.id, operation: input.operation, exp: q.exp, points: q.points, dil: q.dilIn - q.dilOut, fee: q.fee,
      grade: q.points > 0 ? q.after.grade?.name || '' : undefined });
    return true;
  });
}
