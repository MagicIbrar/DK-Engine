// PERF-CROWD (2026-10-29): spreads the synchronous part of monster spawns (skinned instantiate + _afterLoad: first pose,
// compileAsync, crowd register) over frames. At most SLOTS_PER_FRAME bodies pass per animation frame; a burst of 200
// spawns resolving in one task no longer lands in one frame. Not throttled while a map is loading (loading screen).
// ENGINE-CHOSEN pacing value (no game file says how many bodies may appear per frame). Kill switch: globalThis.__dekaronNoSpawnBudget.
export const SLOTS_PER_FRAME = 4;
const q = [];
let pumping = false;
const raf = typeof requestAnimationFrame === 'function' ? requestAnimationFrame : f => setTimeout(f, 16);
function pump() {
  pumping = false;
  const per = Number(globalThis.__dkSpawnSlots) > 0 ? Number(globalThis.__dkSpawnSlots) : SLOTS_PER_FRAME;
  for (let i = 0; i < per && q.length; i++) q.shift()();
  if (q.length) { pumping = true; raf(pump); }
}
/** Resolves when this body may do its synchronous build work (same frame when unthrottled). */
export function spawnSlot(game) {
  if (globalThis.__dekaronNoSpawnBudget || globalThis.__dkT_noSpawnBudget || game?._loadingMap) return null;
  return new Promise(r => { q.push(r); if (!pumping) { pumping = true; raf(pump); } });
}
