const clamp = value => Math.max(0, Math.min(1, Number(value) || 0));

// Independent work may finish in any order. Count each phase once and never
// infer completion from elapsed time, cached timing or network activity.
export function startupProgress(onProgress = () => {}) {
  const phases = [0, 0, 0];
  return (phase, fraction, label) => {
    if (!Number.isInteger(phase) || phase < 0 || phase >= phases.length) throw new Error('Invalid startup phase');
    phases[phase] = Math.max(phases[phase], clamp(fraction));
    const value = phases.reduce((sum, part) => sum + part, 0) / phases.length;
    onProgress(value, label);
    return value;
  };
}

// Smooth only already-completed work. A stalled operation cannot creep toward
// 100%; short cached starts do not acquire a fixed minimum loading duration.
export function startupDisplayProgress(value, target, elapsedMs) {
  const goal = clamp(target), current = Math.min(goal, clamp(value));
  if (goal === 1) return 1;
  return Math.min(goal, current + Math.max(0, Math.min(64, elapsedMs || 0)) / 1000);
}
