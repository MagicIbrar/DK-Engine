// The launch bar's fill rule (4.3.2 E). Two numbers per frame:
//   real      = work done, weighted by the pacing table: sum(share * stageFraction). Stage fractions only rise.
//   displayed = what the bar shows. Each frame it advances by rate*dt, where
//                 rate = max(share/targetMs of the stage the bar is in, (real - displayed)/catchUpMs)
//               and it is capped at `real`. So: displayed <= real always (never 100% before the work is done),
//               (and once all work is done, at no less than 1/finishMs) it moves at the table's steady rate while the load keeps up, it never sits still while real is
//               ahead (the planned rate is > 0), and it fills to exactly 1 only once real == 1.
import { LAUNCH_PACING, LAUNCH_CATCH_UP_MS, LAUNCH_FINISH_MS, LAUNCH_MAX_STEP_MS } from '../config/engine-chosen-launch-pacing.js';
const clamp01 = v => Math.max(0, Math.min(1, Number(v) || 0));

export function validatePacing(table) {
  const ids = new Set();
  let sum = 0;
  for (const row of table) {
    if (!row || typeof row.stage !== 'string' || ids.has(row.stage)) throw new Error(`pacing: bad/duplicate stage ${row?.stage}`);
    if (!(row.share > 0) || !(row.targetMs > 0)) throw new Error(`pacing: ${row.stage} needs share > 0 and targetMs > 0`);
    ids.add(row.stage); sum += row.share;
  }
  if (Math.abs(sum - 1) > 1e-6) throw new Error(`pacing: shares sum to ${sum}, not 1`);
  return table;
}

/** Stage tracker: report(stage, fraction) -> overall real fraction (work-weighted by the table's shares). */
export function launchProgress(table = LAUNCH_PACING, onProgress = () => {}) {
  validatePacing(table);
  const at = new Map(table.map(r => [r.stage, 0]));
  const real = () => { let v = 0; for (const r of table) v += r.share * at.get(r.stage); return v >= 1 - 1e-9 ? 1 : v; };
  const report = (stage, fraction, label) => {
    if (!at.has(stage)) throw new Error(`Invalid launch stage ${stage}`);
    at.set(stage, Math.max(at.get(stage), clamp01(fraction)));
    const value = real(); onProgress(value, label, stage); return value;
  };
  report.real = real;
  report.stages = () => Object.fromEntries(at);
  return report;
}

/** The planned fill rate (bar fraction per ms) at bar position `displayed`. */
export function plannedRate(table, displayed) {
  let start = 0;
  for (const r of table) { if (displayed < start + r.share - 1e-12) return r.share / r.targetMs; start += r.share; }
  const last = table[table.length - 1]; return last.share / last.targetMs;
}

/** One frame of the bar: next displayed value. */
export function paceStep(displayed, real, dtMs, { table = LAUNCH_PACING, catchUpMs = LAUNCH_CATCH_UP_MS, finishMs = LAUNCH_FINISH_MS, maxStepMs = LAUNCH_MAX_STEP_MS } = {}) {
  const goal = clamp01(real), d = Math.min(goal, clamp01(displayed));
  if (d >= goal) return goal === 1 && d >= 1 ? 1 : d;
  const dt = Math.max(0, Math.min(maxStepMs, Number(dtMs) || 0));
  const rate = Math.max(plannedRate(table, d), (goal - d) / catchUpMs, goal === 1 ? 1 / finishMs : 0);
  const next = d + rate * dt;
  return next >= goal - 1e-9 ? goal : next;
}

/** Drive paceStep until displayed catches real (or untilMs elapses). Used by the launch cover finish run. */
export function paceUntil(displayed, real, { table = LAUNCH_PACING, catchUpMs = LAUNCH_CATCH_UP_MS, finishMs = LAUNCH_FINISH_MS, maxStepMs = LAUNCH_MAX_STEP_MS, stepMs = 16, untilMs = 5000 } = {}) {
  let d = Math.max(0, Number(displayed) || 0), t = 0;
  const goal = Math.max(0, Math.min(1, Number(real) || 0));
  while (d < goal - 1e-9 && t < untilMs) {
    const dt = Math.min(maxStepMs, stepMs);
    d = paceStep(d, goal, dt, { table, catchUpMs, finishMs, maxStepMs });
    t += dt;
  }
  return d;
}
