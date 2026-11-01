// Normal-attack timing of the combo, shared by the client (src/game/controller.js _stepTiming) and the shared-world host
// (server/world/core.mjs normal attack, server/world/pvp.mjs pvpAttack) so both read the SAME numbers.
//
// DATA: the combo steps come from gamedata/classes.json `combo`, and for a worn weapon stance from items-styles.json
// classes[ci].combos[style] (src/systems/items/look.js styledClass, the class copy the client swings with): per step
// timeLength (s), timing (fraction of the clip where the damage lands), timing2 (fraction where the next step may
// start), all authored in the game files. The attack speed (stats.attackSpeed: weapon speed x SPEED_ATTACK buffs, the
// same derived stats on the client and the host) divides the clip length.
//
// The host used to refuse a normal attack for max(600, 1000 / min(2, attackSpeed)) ms after the last one (not in the
// game data) and sent the same number to the client as its own request throttle. The combo's own hit-to-hit time is
// shorter on every class (0.17-0.95 s at attack speed 1), so every second swing (or two of three) of an auto-attack
// combo was dropped: the swing played, no damage. The host now admits hits at the rate of the data's combo cycle (a
// leaky-bucket check on the player's attackAt slot) and still refuses a client that swings faster than its data.
import { styledClass } from '../systems/items/look.js';

/** The step used when a class has no combo table (identical to the client's former local default). */
export const DEFAULT_COMBO = [{ timeLength: 0.8, timing: 0.5, timing2: 1 }];

/** ENGINE-CHOSEN (not in the game data): sustained-rate headroom. The host's sustained limit is one hit per
 *  HIT_INTERVAL_TOLERANCE x the combo cycle's average hit-to-hit time, i.e. a client may sustain at most 1/0.85 = 1.18x
 *  the hit rate of its own combo (covers a buff that changes the attack speed on one side a moment before the other). */
export const HIT_INTERVAL_TOLERANCE = 0.85;

/** ENGINE-CHOSEN (not in the game data): jitter allowance (ms). A hit may arrive this much before its slot on top of the
 *  combo's own unevenness, which absorbs a late request followed by an on-time one (network jitter; the client's frame
 *  quantisation: a hit fires on the first frame at or after its frame time, a projectile row one frame before).
 *  Measured with the real client on a local host: consecutive hits left
 *  the client up to 46 ms closer together than the data's hit-to-hit time, and the host saw their spacing within
 *  -5..+6 ms of the client's; 150 covers that plus +-30 ms of internet jitter on each of two requests.
 *  It never raises the sustained rate. */
export const ATTACK_JITTER_MS = 150;

/** ENGINE-CHOSEN (not in the game data): client attack requests that may be in flight at once. With one, a round trip
 *  longer than the combo's fastest step (Alokes 0.17 s at attack speed 1) dropped that step's hit. */
export const ATTACK_REQUESTS_IN_FLIGHT = 3;
/** ENGINE-CHOSEN (not in the game data): the client never sends two attack requests closer than this (a repeated hit marker
 *  of the same frame); every combo hit-to-hit time of the data is far longer (>= 0.11 s up to attack speed 2). */
export const ATTACK_MIN_GAP_MS = 20;

/** The old host rule, kept only as the fallback for a host without class data (and as the regression reference). */
export function legacyAttackCooldownMs(attackSpeed) {
  return Math.max(600, 1000 / Math.min(2, attackSpeed || 1));
}

/** Combo steps of a (styled) class definition: the exact choice the client controller makes. */
export function comboStepsOf(classDef) {
  const c = classDef;
  return (c?.combo?.length ? c.combo : c?.anims?.attack?.length ? c.anims.attack : DEFAULT_COMBO);
}

/** Timing of one combo step in seconds: the clip is stretched to `len`, damage lands at `hitAt`, the next step may
 *  start at `next`. These are exactly the numbers the client controller has always used. */
export function comboStepTiming(step, attackSpeed) {
  const st = step || DEFAULT_COMBO[0];
  const spd = Math.max(0.2, attackSpeed || 1);
  const len = Math.max(0.1, (Number(st.timeLength) || 0.8) / spd);
  const timing = st.timing > 0 && st.timing <= 1 ? st.timing : 0.5;
  const t2 = st.timing2 > timing && st.timing2 <= 1 ? st.timing2 : 1;
  return { len, hitAt: timing * len, next: Math.max(t2 * len, timing * len + 0.01) };
}

/** Hit-to-hit times (s) of the chained combo cycle: from the hit of step k to the hit of step k+1 is next_k - hitAt_k +
 *  hitAt_{k+1} (the last step wraps to the first). One entry per step. */
export function comboHitIntervals(steps, attackSpeed) {
  const list = steps?.length ? steps : DEFAULT_COMBO;
  const t = list.map(s => comboStepTiming(s, attackSpeed));
  return t.map((s, k) => s.next - s.hitAt + t[(k + 1) % t.length].hitAt);
}

/** Smallest time (seconds) between two consecutive hits of the combo cycle. */
export function minHitInterval(steps, attackSpeed) {
  return Math.min(...comboHitIntervals(steps, attackSpeed));
}

/** The host's normal-attack limit for a combo at an attack speed (all ms):
 *   intervalMs  sustained slot spacing = tolerance x the cycle's average hit-to-hit time;
 *   burstMs     how far before its slot a hit is still admitted = the combo's own unevenness (the largest run of fast
 *               steps below the average: their total shortfall against intervalMs) + ATTACK_JITTER_MS;
 *   spacingMs   the client's own minimum spacing between attack requests (snapshot self.attackCooldownMs), below the
 *               combo's fastest step, so the client never holds back a hit of its own combo. */
export function attackLimit(steps, attackSpeed) {
  const iv = comboHitIntervals(steps, attackSpeed).map(s => s * 1000), n = iv.length;
  const intervalMs = Math.round(HIT_INTERVAL_TOLERANCE * iv.reduce((a, b) => a + b, 0) / n);
  let uneven = 0;
  for (let k = 0; k < n; k++) { let s = 0; for (let j = 0; j < n; j++) { s += intervalMs - iv[(k + j) % n]; uneven = Math.max(uneven, s); } }
  return { intervalMs, burstMs: Math.ceil(uneven) + ATTACK_JITTER_MS, spacingMs: Math.max(0, Math.round(Math.min(...iv) * HIT_INTERVAL_TOLERANCE) - ATTACK_JITTER_MS) };
}

/** The old rule as a limit (no burst): a host without class data behaves exactly as before. */
export function legacyAttackLimit(attackSpeed) {
  const ms = legacyAttackCooldownMs(attackSpeed);
  return { intervalMs: ms, burstMs: 0, spacingMs: ms };
}

/** Is a normal attack admitted at `now`? `attackAt` is the host's slot for the next hit (player.attackAt). */
export function attackReady(attackAt, now, burstMs = 0) {
  return now >= (Number(attackAt) || 0) - burstMs;
}

/** The slot after an admitted hit: one interval after the later of the previous slot and now (an idle player banks no
 *  credit beyond the burst allowance; a hit admitted before its slot spends that much of the allowance). */
export function nextAttackAt(attackAt, now, intervalMs) {
  return Math.max(Number(attackAt) || 0, now) + intervalMs;
}

/** Host: the normal-attack limit of a shared-world player, from the SAME combo the client swings (its classes.json class
 *  with the stance of its worn weapon, items-styles.json) and the host's derived attack speed. Falls back to the old
 *  rule only when the host has no class definition for the player. */
export function playerAttackLimit(data, p) {
  const speed = p?.stats?.attackSpeed || 1;
  const ci = Number(p?.profile?.classIndex);
  const base = typeof data?.classDef === 'function' ? data.classDef(ci) : null;
  if (!base || typeof base !== 'object') return legacyAttackLimit(speed);
  let style = null;
  try { if (data.itemDB && typeof data.equipmentStyle === 'function') style = data.equipmentStyle(p.profile); } catch { style = null; }
  // the self snapshot asks on every broadcast: the styled combo of a (class definition, stance) pair is built once
  let byStyle = STEP_CACHE.get(base);
  if (!byStyle) STEP_CACHE.set(base, byStyle = new Map());
  let steps = byStyle.get(style);
  if (!steps) {
    let cls = base;
    try { if (style != null) cls = styledClass(base, data.itemDB, style); } catch { cls = base; }
    byStyle.set(style, steps = comboStepsOf(cls));
  }
  return attackLimit(steps, speed);
}
const STEP_CACHE = new WeakMap();
