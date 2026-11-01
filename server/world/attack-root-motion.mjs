// BASIC-ATTACK ROOT MOTION, host side. Global's share/movecache.csv lists the normal-attack combo clips as moving clips
// (e.g. Swordmans LSW ATTACK_01..05 travel 6.7 m forward over the combo, each step starting where the last ended); the
// caster's controller plays the same curves (src/game/controller.js). An accepted hit names its combo step; the host then
// moves the canonical record along that step's whole curve (src/systems/skills/root-motion.js), stretched over the step
// length at the player's attack speed, with 0.1 m swept walkability. The run starts at the hit (the moment observers
// start the swing clip from the attack event), so the record trails the caster's own body by the wind-up and ends on the
// same point. server/world/core.mjs absorbs the displacement as canonical motion (movement-authority noteSkillRootMotion).
// A refused hit moves nothing; a skill, death, scene change or an accepted movement report ends the runs.
import { styledClass } from '../../src/systems/items/look.js';
import { comboStepsOf, comboStepTiming, HIT_INTERVAL_TOLERANCE, ATTACK_JITTER_MS } from '../../src/game/attack-timing.js';
import { rootMotionCurves, rootKey, attackStepAnim, startRootRun, advanceRootRuns, sweepRoot } from '../../src/systems/skills/root-motion.js';
import { mapFor, sceneKey } from './scene.mjs';

const sceneOf = p => sceneKey(p.map, p.instanceId, p.channel ?? 0);
const refuseStep = (status, message) => { throw Object.assign(new Error(message), { status }); };

/** Validate a client-selected combo index and its authored timeline without mutating the player.
 * A skipped packet is allowed after the skipped clips' time; repeating an index pays an entire cycle.
 * Target changes, stop commands and omitted step fields cannot reset this ledger. The first accepted
 * step may be nonzero (joining an already-started/lossy combo); this is a one-time entry allowance.
 * Existing attack-timing tolerance/jitter apply, but jitter is debt carried forward, never free credit.
 * Stance/scene changes pay the previous clip's recovery and the new stance's entry sequence.
 * Commit only after every target/range/LOS/damage admission check succeeds. */
export function previewAttackStep(world, p, step, now) {
  if (step === undefined) return null; // legacy commands grant no clip/root motion
  const cls = attackClassDef(world, p), steps = comboStepsOf(cls);
  if (!Number.isInteger(step) || step < 0 || step >= steps.length) refuseStep(400, 'Attack step is outside the equipped stance combo.');
  if (!Number.isFinite(now)) refuseStep(400, 'Attack step needs a valid server clock.');
  const speed = Math.max(.2, Number(p.stats?.attackSpeed) || 1), timing = comboStepTiming(steps[step], speed);
  const key = `${sceneOf(p)}|${cls?.index}|${cls?.style}|${steps.length}`;
  const previous = p._attackStepAuthority;
  let slot = now;
  if (previous) {
    if (now < previous.wallAt) refuseStep(429, 'Attack combo step is cooling down.');
    let seconds = Math.max(0, previous.timing.next - previous.timing.hitAt);
    const first = previous.key === key ? (previous.step + 1) % steps.length : 0;
    // Missing intermediate packets may predate a server-owned speed change. Use the faster of
    // the two authoritative speeds for those unseen clips, not any client-supplied duration.
    const middleSpeed = Math.max(speed, previous.speed);
    for (let k = first, count = 0; k !== step && count < steps.length; k = (k + 1) % steps.length, count++) seconds += comboStepTiming(steps[k], middleSpeed).next;
    seconds += timing.hitAt;
    const due = previous.slot + seconds * 1000 * HIT_INTERVAL_TOLERANCE;
    if (now + ATTACK_JITTER_MS + 1e-6 < due) refuseStep(429, 'Attack combo step is cooling down.');
    slot = Math.max(due, now);
  }
  return { key, step, timing, speed, slot, wallAt: now };
}

export function commitAttackStepAdmission(p, approval) { if (approval) p._attackStepAuthority = approval; }

/** Server-owned bots use the same authored combo order when their director submits a plain attack.
 * Preview does not mutate: a refused attack must not consume a combo step. Human requests keep their own step.
 * ENGINE-CHOSEN: target/stance/scene changes restart; continuation lasts through the previous
 * clip or the next authored hit, whichever is later, plus the existing network jitter allowance. */
export function attackStepFor(world, p, input, now) {
  if (input.step !== undefined || p?.npcPlayer !== true) return input.step;
  const cls = attackClassDef(world, p), state = p._npcAttackCombo;
  const key = `${sceneOf(p)}|${cls?.index}|${cls?.style}|${input.targetId}`;
  return state?.key === key && now <= state.until ? state.next % comboStepsOf(cls).length : 0;
}

export function commitAttackStep(world, p, targetId, step, now) {
  if (p?.npcPlayer !== true || !Number.isInteger(step)) return;
  const cls = attackClassDef(world, p), steps = comboStepsOf(cls);
  const timing = comboStepTiming(steps[step % steps.length], p.stats?.attackSpeed || 1);
  const next = (step + 1) % steps.length, nextTiming = comboStepTiming(steps[next], p.stats?.attackSpeed || 1);
  const window = Math.max(timing.len, timing.next-timing.hitAt+nextTiming.hitAt)*1000+ATTACK_JITTER_MS;
  p._npcAttackCombo = { key: `${sceneOf(p)}|${cls?.index}|${cls?.style}|${targetId}`, next, until: now + window };
}

/** The (stance-styled) class the player swings with: the same choice as attack-timing.js playerAttackLimit. */
export function attackClassDef(world, p) {
  const base = typeof world?.data?.classDef === 'function' ? world.data.classDef(Number(p?.profile?.classIndex)) : null;
  if (!base || typeof base !== 'object') return null;
  let style = null;
  try { if (world.data.itemDB && typeof world.data.equipmentStyle === 'function') style = world.data.equipmentStyle(p.profile); } catch { style = null; }
  try { return style != null ? styledClass(base, world.data.itemDB, style) : base; } catch { return base; }
}

/** An accepted normal hit of combo step `step`: start that step's root run. Returns true when a moving run started. */
export function startAttackRoot(world, p, step) {
  const cls = attackClassDef(world, p);
  const steps = comboStepsOf(cls);
  if (!Number.isInteger(step) || step < 0 || step >= steps.length || p?.dead) return false;
  const curve = (world?.data?.skillRootMotion?.table || rootMotionCurves).get(rootKey(attackStepAnim(cls, step)));
  if (!curve) return false;
  const len = comboStepTiming(steps[step], p.stats?.attackSpeed || 1).len;
  const state = p._attackRoot;
  if (!state || state.scene !== sceneOf(p)) p._attackRoot = { scene: sceneOf(p), runs: [] };
  return !!startRootRun(p._attackRoot.runs, curve, Number(p.yaw) || 0, len);
}

/** Advance the player's swing runs by dt seconds; returns the displacement applied {x, z} or null. */
export function tickAttackRoot(world, p, dt) {
  const state = p?._attackRoot;
  if (!state?.runs.length) return null;
  if (p.dead || p.leaving || state.scene !== sceneOf(p) || p._skills?.engine?.active || p.mount?.phase === 'on') { state.runs.length = 0; return null; }
  const d = advanceRootRuns(state.runs, dt);
  if (!(Math.abs(d.x) > 1e-9 || Math.abs(d.z) > 1e-9)) return null;
  const map = mapFor(world, p);
  const to = sweepRoot(p.x, p.z, d.x, d.z, (x, z) => !!map?.isWalkable(x, z));
  const dx = to.x - p.x, dz = to.z - p.z;
  if (!(Math.abs(dx) > 1e-9 || Math.abs(dz) > 1e-9)) return null;
  p.x = to.x; p.z = to.z; world.changed?.(p);
  return { x: dx, z: dz };
}

/** The player moved by input (accepted movement report) or the scene ended: no swing keeps carrying the body. */
export function clearAttackRoot(p) { if (p?._attackRoot) p._attackRoot.runs.length = 0; }
