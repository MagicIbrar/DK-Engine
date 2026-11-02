// Worn-gear refinement glow clock (2026-10-30 glowrate2). One tunable: globalThis.__dekaronGlowTimeScale.
//
// PROVEN (Global 0.0.1 32-bit decompile): MeshStatus keys are NORMALIZED, not ms. FUN_011b46e0 computes
// frac = 1 - remaining/total over the unit's own life (FUN_011b44f0 sets total = end - start) and looks the keys up at
// frac * _DAT_01b7e3bc (the 0..1000 key space; FUN_011a8600 interpolates linearly). The scene's `lifetime 0 1000` is that key
// space. The real play length is supplied by the caller (Provider FUN_011a3600 param_5 -> +0xc), and for worn gear refinement
// there is no modeleffect.csv row: the length is compiled into the client and not recoverable from the available decompile.
// So 1000 ms (used since LANE-63) was the key-space constant read as a duration. NOT PROVEN: the exact length / time unit.
// BEST READING (medium-low confidence): one pulse every 3500 ms, the 4.1.1 value set against the official look
// (4.1.1 src/config/engine-chosen-refinement-rate.js REFINEMENT_LOOP_MS). The same scale is applied to the gear UV scroll
// (mesh_status `b`), whose time base in the renderer (FUN_0158e6f0) is likewise not recoverable.
// Scale = 1000 / loop ms: 1 = the old 1000 ms reading, 0.2857 = 3500 ms. Set globalThis.__dekaronGlowTimeScale to override.
export const GLOW_TIME_SCALE_DEFAULT = 1000 / 3500;
export function glowTimeScale() {
  const v = Number(globalThis.__dekaronGlowTimeScale);
  return Number.isFinite(v) && v > 0 ? v : GLOW_TIME_SCALE_DEFAULT;
}
/** Play length of one refinement pulse in ms (the scene's normalized 0..1000 keys are spread over it). */
export function refineLoopMs() { return Math.max(1, Math.round(1000 / glowTimeScale())); }
