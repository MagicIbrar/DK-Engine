// Lane 27 / 27b / 60 - monster gait + Global move destination for host monsterRow.
// Explore (idleMonster) tags m.moveGait = 'walk'. Chase (core.mjs tick, RunSpeed) sets
// m.moveGait = 'run' via tagMonsterChaseGait when a chase step actually moves; clears to null
// while standing / in attack reach. Spreading monsterRowGait(m) into World.monsterRow publishes
// walk:'peace' for explore so remotes play the walk clip.
//
// Lane 60 (2026-10-29) - Global monster movement. The Global client does not interpolate monster
// positions: a monster move is a Ghost::ModelCenter::Actors::Command::MoveDest (64-bit vft 7ff671e06f78,
// built by Command::Builder slot 4 FUN_7ff67099bde0 -> FUN_7ff67099d010) carrying a destination and a speed;
// PC::Action slot 36 (FUN_7ff670a0d280) snaps the facing toward the destination and the doll walks there
// (TDoll::CPathFindMoveCmd / Transfrom::State::CPathFind FUN_7ff6712d5540). The host therefore publishes
// the destination the monster is walking to and its speed: row.mv = [x, z, cells/s] while it moves, 0 while
// it stands (0 = Global Stand; the client then runs the Global catch-up rule, src/systems/network/monster-move.js).
//   explore leg  -> the leg goal (idleMonster state.goal) at WalkSpeed x status speed multiplier
//   chase step   -> the host position after the step at chaseSpeed(def) x status speed multiplier (same
//                   expression core.mjs passes to world.step)
//   event march  -> the current path waypoint at march.speed x speed multiplier (event-march.mjs)
// Old clients ignore mv (they keep their interpolation buffer); old hosts never send it (clients keep
// the buffer for them). Protocol stays backward compatible.
import {chaseSpeed,statusSpeedMul} from '../../src/game/monster-rules.js';

const r3=v=>Math.round(v*1000)/1000;

/** Fields to merge into monsterRow: walk gait and the Global move destination. */
export function monsterRowGait(m) {
  const out = m?.moveGait === 'walk' ? { walk: 'peace' } : {};
  out.mv = monsterMoveDest(m);
  return out;
}

/** [x, z, speed] of the move the host is making now, else 0 (standing). */
export function monsterMoveDest(m) {
  const t = m?.moveTo;
  if (!t || m.dead || !(t.s > 0) || !Number.isFinite(t.s)) return 0;
  if (t.kind === 'explore') {
    const g = m.idleMove?.goal;
    if (m.moveGait !== 'walk' || !g || g.x !== t.x || g.z !== t.z) return 0;
    return [r3(t.x), r3(t.z), r3(t.s)];
  }
  if (t.kind === 'chase') return m.moveGait === 'run' && Number.isFinite(m.x) && Number.isFinite(m.z) ? [r3(m.x), r3(m.z), r3(t.s)] : 0;
  if (t.kind === 'march') return m.eventMarch && !m.targetId && Number.isFinite(t.x) && Number.isFinite(t.z) ? [r3(t.x), r3(t.z), r3(t.s)] : 0;
  return 0;
}

/** Tag chase/step gait on a monster record (core.mjs chase path). */
export function tagMonsterChaseGait(m, moved) {
  if (!m) return;
  m.moveGait = moved ? 'run' : null;
  m.moveTo = moved ? { kind: 'chase', s: chaseSpeed(m.def) * statusSpeedMul(m.statuses) } : null;
}

/** Tag an explore leg (monster-idle.mjs): goal null = standing. */
export function tagMonsterExploreLeg(m, goal, speed) {
  if (!m) return;
  m.moveTo = goal && speed > 0 ? { kind: 'explore', x: goal.x, z: goal.z, s: speed } : null;
}

/** Tag an event-march step (event-march.mjs): point null = standing. */
export function tagMonsterMarch(m, point, speed) {
  if (!m) return;
  m.moveTo = point && speed > 0 ? { kind: 'march', x: point.x, z: point.z, s: speed } : null;
}