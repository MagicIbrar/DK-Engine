// Global particle emission (emitrate) and particle spin (addrotate). Reimplemented from the Global 43.19 32-bit client
// (read-only evidence, decompile/32-bit-main\decompiled.c; constants from reconstructed-images\dekaron32-memory-image.bin,
// file offset = address - 0x6e0c00). No value here is chosen by 4.2.0.
//
// emitrate: the effectdata parser (decompiled.c ~390917) reads it as an integer into emitter data +0x14.
//   Emit tick FUN_011a65e0 (~1709540), called from the unit tick FUN_011a5dc0 only while the unit clock is inside its
//   emit window, with the frame time in whole milliseconds:
//     rate > 0 : milliseconds per particle. acc += dt; if acc < rate nothing; else count = acc / rate, acc = acc % rate.
//     rate < 0 : particles per frame. count = -rate on every tick.
//     rate = 0 : no emission.
//   Either way count is capped at 10 per tick, and FUN_011a67c0 then takes up to count free elements of the pool
//   (maxelementcount). FUN_011a67c0 is the only caller of the spawn FUN_011a6910, so there is no burst at start.
// addrotate: the parser (~390973) stores degrees x 0.01745329 (_DAT_01b7e0ec) into emitter data +0x1c.
//   Spawn FUN_011a6910 (~1709742): when addrotate != 0, rotation = rand()/32767 (_DAT_01b7e3e0) x addrotate + 0
//   (DAT_01b7e0ac); otherwise the rotation stays 0.
//   Step FUN_011a7980 (~1710247-1710275): age = clamp(1 - remaining/total, 0, 1), taken BEFORE this tick's life
//   decrement (FUN_011a7600); when addrotate != 0, rotation = addrotate x age (assigned, not accumulated). So a particle
//   turns through exactly `addrotate` degrees over its whole life, whatever that life is.

/** Global per-tick particle cap (FUN_011a65e0 `if (10 < count) count = 10`). */
export const GLOBAL_EMIT_MAX_PER_TICK = 10;
/** _DAT_01b7e0ec: the degree-to-radian factor the parser applies to addrotate. */
// float32 read from the memory image at 0x01b7e0ec (decompile prints it rounded as 0.01745329).
export const GLOBAL_DEG_TO_RAD = 0.01745329238474369;

/** emitrate as the parser stores it (integer, truncated toward zero like an atoi read). */
export function globalEmitRate(rate) {
  const n = Number(rate);
  return Number.isFinite(n) ? Math.trunc(n) : 0;
}

/**
 * One Global emit tick. `state.emitAcc` holds the millisecond accumulator (only used by a positive rate).
 * Returns how many particles to spawn this tick (0..10); the caller still clips to free pool elements.
 */
export function globalEmitCount(state, dtMs, rate) {
  const r = globalEmitRate(rate);
  if (r === 0) return 0;
  let count;
  if (r < 0) count = -r;
  else {
    const acc = (Number(state.emitAcc) || 0) + Math.max(0, Number(dtMs) || 0);
    state.emitAcc = acc;
    if (acc < r) return 0;
    count = Math.floor(acc / r);
    state.emitAcc = acc - count * r;
  }
  return Math.min(GLOBAL_EMIT_MAX_PER_TICK, count);
}

// Weather units (unittype weather: Ghost::DollStage::Effect::Unit::Weather, 32-bit decompiled-named.c ~1711239-1711990):
//   Unit tick FUN_011a96a0 adds the frame ms to the unit clock and calls the emit FUN_011a9d00 only while the clock is
//   below the unit's end time. FUN_011a9d00 reads emitrate (data +0x14) as an UNSIGNED integer: rate 0 = no emission;
//   otherwise acc += dt (unsigned ms), and once acc >= rate: count = acc / rate, acc = acc % rate, then FUN_011a9d60
//   takes up to count elements from the free pool (no 10-per-tick cap and no "negative = per frame" path, unlike
//   FUN_011a65e0). A negative emitrate is therefore a huge unsigned rate (no Global weather unit has one).
//   Spawn FUN_011a9eb0: rotation (+0x30) = 0; only a control rotation track (control +0x3c) would set it, and no Global
//   weather control has one (effectscene.map / effectscene.com cate 10 checked, LANE-63). No random start angle.
//   Step FUN_011aa570: remaining life -= dt FIRST, then age = clamp(1 - remaining/total, 0, 1); when addrotate != 0,
//   rotation = addrotate x age (assigned). So weather spins on the age AFTER this tick's decrement.

/** One Global weather emit tick (FUN_011a9d00). `state.emitAcc` = unsigned ms accumulator. Returns the spawn count. */
export function globalWeatherEmitCount(state, dtMs, rate) {
  const r = globalEmitRate(rate) >>> 0;
  if (r === 0) return 0;
  const acc = ((Number(state.emitAcc) || 0) + Math.max(0, Number(dtMs) || 0)) % 4294967296;
  state.emitAcc = acc;
  if (acc < r) return 0;
  const count = Math.floor(acc / r);
  state.emitAcc = acc - count * r;
  return count;
}

/** Weather spawn rotation (FUN_011a9eb0): always 0 for the Global data (no weather control has a rotation track). */
export const GLOBAL_WEATHER_SPAWN_ROTATION = 0;

/** addrotate in radians, as stored at emitter data +0x1c. */
export function globalAddRotateRad(addRotateDeg) {
  const n = Number(addRotateDeg);
  return Number.isFinite(n) ? n * GLOBAL_DEG_TO_RAD : 0;
}

/** Spawn rotation (radians): rand x addrotate, or 0 when addrotate is 0. `random` returns [0,1]. */
export function globalSpawnRotation(addRotateDeg, random = Math.random) {
  const a = globalAddRotateRad(addRotateDeg);
  return a !== 0 ? random() * a : 0;
}

/** Age fraction Global uses for the spin: clamp(1 - remaining/total) = clamp(age/life). */
export function globalAgeFraction(ageSec, lifeSec) {
  const life = Number(lifeSec);
  if (!(life > 0)) return 1;
  return Math.max(0, Math.min(1, (Number(ageSec) || 0) / life));
}

/**
 * Step rotation (radians). `ageBefore` is the age fraction before this tick's life decrement. Returns `current`
 * unchanged when addrotate is 0 (Global leaves the field alone).
 */
export function globalStepRotation(addRotateDeg, ageBefore, current) {
  const a = globalAddRotateRad(addRotateDeg);
  return a !== 0 ? a * ageBefore : current;
}