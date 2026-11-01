// Half Bagi (class 12) fury gauge - the rules the offline gauge (gauges.js) and the shared-world host (server/world/fury.mjs) share.
//
// From the data (share/action/pc/pcclass.csv, kept in classes.json stats.raw): FURY_POINT_DPS 0.2 and FURY_POINT_MAX_TIME 10000 for the
// Half Bagi column only; "When the Fury gauge reaches 100%, it stays full for 10 seconds without decreasing automatically, until you
// use a Fury skill" (stringtable_skill 150 2). Fury skills pay ResourceFury from the gauge (SkillEngine.useSkill) and are refused
// ("not enough fury") while it is short - so a host that never fills the gauge refuses every one of them.
// Native status option FURY_DPS_CORRECTION_MUL: Fury Control 2122 -> statuses 14860..14879 "Decrease on Rage Decrease rate" (50..90),
// Self Injury 2124 -> 14920..14939 "HP Decrease \ Rage recharge" (600..10000).
//
// Every reading of those values (maximum, gains, DPS unit, loss correction) is ENGINE-CHOSEN: src/config/engine-chosen-fury.js.
// Fury Mastery 2121 FURY_MAX_POINT 50..95 / FURY_CORRECTION_POINT 200..2000 have no stated unit; they are not applied.
import { FURY_CHOICES } from '../../config/engine-chosen-fury.js';

export const FURY_HIT_GAIN = FURY_CHOICES.hitGain;
export const FURY_HURT_GAIN = FURY_CHOICES.hurtGain;

const num = v => (Number.isFinite(+v) ? +v : 0);

/** {dps, holdSec} for a class whose pcclass column carries fury values, else null. `raw` = classes.json stats.raw. */
export function furyRules(raw) {
  const dps = num(raw?.FURY_POINT_DPS), ms = num(raw?.FURY_POINT_MAX_TIME);
  if (!(dps > 0) && !(ms > 0)) return null;
  return { dps, holdSec: ms / 1000 || FURY_CHOICES.holdSecFallback };
}

/** Loss multiplier from the active statuses' native FURY_DPS_CORRECTION_MUL (expired entries ignored): 1 - sum/100. */
export function furyLossScale(statuses) {
  let mul = 0;
  for (const s of statuses || []) {
    if (!s || (s.remaining != null && s.remaining <= 0)) continue;
    for (const o of s.options || []) if (o?.code === FURY_CHOICES.lossCorrection) mul += num(o.value);
  }
  return 1 - mul / 100;
}

/** g = {cur, fullAt}; sets the gauge (clamped to 0..max) and notes when it reached the top. `at` = seconds. */
export function furySet(g, value, max, at) {
  const before = g.cur;
  g.cur = Math.max(0, Math.min(max, num(value)));
  if (g.cur >= max && before < max) g.fullAt = at;
  if (g.cur < max) g.fullAt = null;
  return g.cur;
}

/** Add a fraction of the maximum (a landed hit / a hit taken). */
export function furyGain(g, max, frac, at) { return furySet(g, g.cur + max * frac, max, at); }

/** The passive loss: dps % of the maximum per second times `scale` (furyLossScale), none while the gauge sits at the top inside its
 *  hold time. A negative scale (Self Injury) is a recharge and also runs from an empty gauge. */
export function furyDecay(g, rules, max, dt, at, scale = 1) {
  const loss = max * rules.dps / 100 * (Number.isFinite(scale) ? scale : 1);
  if (loss < 0) return furySet(g, g.cur - loss * dt, max, at);
  if (g.cur >= max && g.fullAt != null && at - g.fullAt < rules.holdSec) return g.cur;
  if (g.cur > 0 && loss > 0) furySet(g, g.cur - loss * dt, max, at);
  return g.cur;
}
