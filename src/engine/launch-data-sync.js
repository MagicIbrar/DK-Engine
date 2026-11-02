// Launch-bar hook for the server-hosted table sync (wt-data owns what the sync does; this file only runs it).
// The launch runs ONE registered sync as its 'datasync' stage (config/engine-chosen-launch-pacing.js), FIRST, after
// the 0% cover paints and BEFORE anything reads /gamedata (startup catalogs, FrontData.load), so every table the
// launch parses is the synced one. With nothing registered the stage completes at once (no added time).
//   setLaunchDataSync(async ({onProgress, current}) => { ...; onProgress(0..1); return summary; })
//     onProgress(fraction) : stage progress 0..1 (only rises; the bar never shows more than is done)
//     current()            : false once the front-end was disposed (stop early)
//   A rejection fails the launch like any other startup error (the retry panel), so stale tables never load silently.
let registered = null;
export function setLaunchDataSync(fn) {
  if (fn != null && typeof fn !== 'function') throw new TypeError('setLaunchDataSync: expected a function or null');
  registered = fn || null;
}
export const hasLaunchDataSync = () => registered !== null;
export async function runLaunchDataSync({ onProgress = () => {}, current = () => true } = {}) {
  const started = performance.now();
  if (!registered) { onProgress(1); return { registered: false, ms: 0 }; }
  const clamp = v => Math.max(0, Math.min(1, Number(v) || 0));
  onProgress(0);
  const result = await registered({ onProgress: f => onProgress(clamp(f)), current });
  onProgress(1);
  return { registered: true, ms: Math.round(performance.now() - started), result };
}
