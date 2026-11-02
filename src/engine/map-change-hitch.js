// 4.1.1 / 4.3.2 E4: map-change hitch mitigations and shader precompile hooks.
// WHAT THIS MODULE OWNS: the ENGINE-CHOSEN cover-behind compile/warm contract for an
// in-game map change (travel / enterMap). The concrete GL work still lives in
// game.js _warmUp (compileSceneInParts, settleShaderPrewarm, warmWholeScene, …);
// this module is the named hook surface + the knobs the warm-up reads, so hitch
// policy is one place and tests can assert the contract without driving WebGL.
//
// PROCMON-BLOCKED: Global's per-stage map-change timings (file-open order, shader
// link cost, first-frame hitch) are UNKNOWN until a longer Procmon of a real Global
// travel fills MAP_PACING. Values below are ENGINE-CHOSEN placeholders — never claim
// Global parity for them. t104u: keep budgets short so the bar never sits forever
// near ~90% while optional prewarm finishes.
import { settleShaderPrewarm, tickShaderPrewarm, markProgramsTouched } from './shader-prewarm.js';
import { keepShaderPrograms, flushWarmDraws, touchPrograms, warmWholeScene } from './warm-draw.js';
import { compileSceneInParts } from './scene-compile.js';

export const MAP_CHANGE_HITCH = Object.freeze({
  source: 'ENGINE-CHOSEN',
  /** true until the owner's Procmon CSV fills Global map-change stage timings. */
  procmonBlocked: true,
  /** settleShaderPrewarm budget under the cover (ms). Short: leftover jobs continue in play. */
  settleShaderMs: 1200,
  /** cap for mount + Trans Up prewarm racing under the cover (ms). */
  mountTransUpCapMs: 2000,
  /** finishInterfaceWarmup race budget (ms). Required panels still prefer to finish; never unbounded. */
  interfaceWarmupCapMs: 4000,
  /** after cover lift, programs/tex uploads in this window are pop-in candidates (bench-mapchange). */
  settleObserveMs: 4000,
});

/**
 * Ordered cover-behind phases for a map change. Callers pass the live work; we
 * only sequence + label so a future Procmon table can retarget budgets without
 * rewriting game.js.
 *
 * @param {object} ctx
 * @param {() => boolean} [ctx.current]
 * @param {(phase: string, label?: string) => void} [ctx.onPhase]
 * @param {object} steps  each value is an async () => any (or sync)
 */
export async function runMapChangePrecompile(steps, { current = () => true, onPhase = () => {} } = {}) {
  const order = ['compile', 'firstPerson', 'mountTransUp', 'effectGraphics', 'settle', 'warmDraws'];
  const times = {};
  let last = performance.now();
  for (const phase of order) {
    if (!current()) {
      throw Object.assign(new Error('Map loading changed. Retry loading.'), { loadingStageFailure: true, loadingStageReason: 'changed' });
    }
    const fn = steps?.[phase];
    if (typeof fn !== 'function') continue;
    onPhase(phase);
    await fn();
    const now = performance.now();
    times[phase] = Math.round(now - last);
    last = now;
  }
  times.total = Object.values(times).reduce((a, b) => a + b, 0);
  return times;
}

/** Re-export the warm helpers so hitch policy and call sites share one import surface. */
export {
  settleShaderPrewarm, tickShaderPrewarm, markProgramsTouched,
  keepShaderPrograms, flushWarmDraws, touchPrograms, warmWholeScene,
  compileSceneInParts,
};