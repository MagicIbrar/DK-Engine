// First-person look-down (body / legs visible when looking down).  DISABLED BY DEFAULT (MIN_SCALE 1 = no change).
//
// MEASURED (test-client run, class 8 Segita Shooter, real client): the first-person eye sits 0.56 m in FRONT of the body root
// (`nativeAvatarEyeOffset`, so the head / pants never clip into the view) and 1.93 m above the feet. Looking down at the camera's
// 1.45 rad limit the feet land at screen height -0.66 .. -0.86 (-1 = bottom edge), i.e. in the bottom 15 % behind the hotbar, and the
// pelvis is below the frame. The legs ARE drawn - they are just small and low, as they physically would be from 1.9 m up.
//
// TRIED (test-client screenshots, classes 0 / 5 / 8 / 13, looking down): easing the forward
// eye offset back over the body (MIN_SCALE 0.25 or 0) does bring the body into the frame, but what appears is the HOLLOW torso shell
// (the head is hidden, so the collar is an open tube; the legs are dark inside it) floating over the grass - worse than the sliver the
// current view shows. A proper fix needs the shell closed per class (caps / a solid neck), which is separate work, so the shipped look
// stays as it was. Console override for trying it: globalThis.__dekaronFpLookDown = { MIN_SCALE: 0.25 }.
//
// The game data has no first-person camera at all (Dekaron has none), so every number here is ENGINE-CHOSEN.
export const FP_LOOKDOWN = Object.freeze({
  FROM_PITCH: 0.9,   // rad: the offset starts to ease back (the body fade-in starts at 0.65 and is complete at 0.95)
  TO_PITCH: 1.35,    // rad: fully eased
  MIN_SCALE: 1,      // share of the forward offset kept when looking almost straight down (1 = off)
});

/** Multiplier of the first-person forward eye offset for a view pitch (rad, positive = looking down). */
export function lookDownOffsetScale(pitch, cfg = globalThis.__dekaronFpLookDown ? { ...FP_LOOKDOWN, ...globalThis.__dekaronFpLookDown } : FP_LOOKDOWN) {
  const p = Number(pitch);
  if (!Number.isFinite(p) || p <= cfg.FROM_PITCH) return 1;
  const t = Math.min(1, (p - cfg.FROM_PITCH) / Math.max(1e-6, cfg.TO_PITCH - cfg.FROM_PITCH));
  const s = t * t * (3 - 2 * t);
  return 1 - (1 - cfg.MIN_SCALE) * s;
}

// ======================================================================================================================================
// First-person ARM + WEAPON FRAMING.  The original game has no first-person view, so every framing number below is
// either ENGINE-CHOSEN (a design choice) or FITTED (searched against the named measurement).  Nothing here comes from game data.
//
// MEASURED FACT behind it (tools/test-first-person-coverage.mjs --hands, real class models + native clips, camera space, x right, y up,
// -z forward): in the native STAND clips the weapon hand hangs 0.5 .. 0.7 m BELOW the eye and 0.2 .. 0.6 m ahead (angle 38 .. 76 deg below
// the view axis; the frame ends at 35 deg), so the weapon is outside the frame while standing and only swings into view while running
// (staff / wand / sword / bow; see the table in the report).  The arm rig itself (armour pauldrons / bracers skinned to the arm bones)
// covers 5 .. 30 % of the frame at idle and up to 60 % in attack frames.
//
// WEAPON KEEP-IN-VIEW CLAMP (global rule, ENGINE-CHOSEN design; the numbers were picked by a grid scan over every class / style scenario of the
// coverage test, best compromise of "weapon visible while standing" vs "weapon share"): a weapon is moved by a smooth camera-space offset so
// that its GRIP (the rig hand bone) is never lower than `floor` x depth below the view axis, never closer than `near` metres in front of the
// eye, never wider than `side` x depth and never on the wrong side of the midline (`mid`, see fpWeaponClamp).  The offset is zero whenever the
// hand is already inside that region, so running / attack swings keep the native hand-weapon relation and the weapon only 'floats up' while
// the hand is out of the frame anyway (it is then not visible, so no gap shows).  Two-sided bound of the weapon: a weapon whose bounding box is
// bigger than `area` is scaled down about the grip (fpWeaponAreaScale), so the bulkiest legal item of a style is bounded like the others.
//
// FRAMING per class / weapon style = { scale, dx, dy, dz } in CAMERA space (metres x player scale):
//   rig    : the whole arm rig + the weapons hanging on it, scaled about the shoulder pivot (0,-.28,-.10) (ENGINE-CHOSEN, unchanged) and moved.
//   main / second : an EXTRA transform of ONE weapon object (main hand / off-hand: shield, 2nd blade), scaled about its grip; plus optional
//                   per-weapon clamp overrides { floor } (a number; the other clamp axes come from FP_WEAPON_CLAMP).
// Lookup: styles[style] over the class entry over identity.  Riding never uses a framing.  Every table entry is FITTED: `node
// tools/test-first-person-coverage.mjs --fit` searched the smallest change from the defaults that puts the style (highest-tier weapon AND the biggest
// weapon the class can wear in that style) inside FP_COVERAGE_BUDGET (with a 5 % margin); the test then asserts the result on the real native pass.
// ======================================================================================================================================
export const FP_FRAMING_IDENTITY = Object.freeze({ scale: 1, dx: 0, dy: 0, dz: 0 });
/** First-person ARM pass near cut (metres from the eye; ENGINE-CHOSEN, chosen by measurement): arm-pass pixels closer than this are not
 *  drawn, so wide sleeves that swing through the eye while running do not cover the view. Measured 2026-10-04 (test-client runs,
 *  running-wedge check): the Black Wizard's black running "wedge" is its coat sleeve (bwz_equ_cot_*, 97-99 % of the dark pixels); sleeve-dark
 *  pixels per 480x270 frame 1023 at the old 0.08 -> 64 at 0.15 / 36 at 0.2, hand pixels unchanged (203 -> 226); at 0.3+ real arm
 *  geometry starts to go. Gear (weapons) and the body pass keep 0.08. Override for measurements: globalThis.__dekaronFpArmNear. */
export const FP_ARM_NEAR = 0.15;
/** Default clamp of every weapon (ENGINE-CHOSEN). */
export const FP_WEAPON_CLAMP = Object.freeze({ floor: 0.55, side: 0.85, mid: 0.12, near: 0.3, soft: 0.06, area: 0.7 });
/** Per-class / per-style framing table (filled by `node tools/test-first-person-coverage.mjs --fit`; every entry is FITTED). */
export const FP_FRAMING = Object.freeze({
  0: { styles: {
    1: { rig: { dz: 0.06 } },
    2: { rig: { scale: 0.7 } },
    3: { rig: { scale: 0.7 } },
    4: { rig: { scale: 0.78 } },
    10: { rig: { scale: 0.66 } },
    12: { rig: { scale: 0.66 } },
    13: { rig: { scale: 0.77 } },
    14: { rig: { scale: 0.77 }, main: { scale: 0.55, dx: -0.09 } },
    15: { rig: { scale: 0.7 }, second: { scale: 0.5 } },
    16: { rig: { scale: 0.74, dz: -0.03 }, second: { scale: 0.5 } },
    17: { rig: { scale: 0.66 }, second: { scale: 0.53 } },
    18: { rig: { scale: 0.7 }, second: { scale: 0.5 } },
    19: { rig: { scale: 0.78 }, main: { scale: 1.16, dy: 0.09 } },
    23: { rig: { scale: 0.95 } },
  } },
  1: { styles: {
    2: { rig: { dy: -0.07 } },
    23: { rig: { scale: 0.85 } },
  } },
  2: { styles: {
    2: { main: { floor: 0.5 } },
    9: { rig: { dx: -0.07 } },
  } },
  3: { styles: {
    2: { main: { dz: -0.09, floor: 0.5 } },
    21: { main: { scale: 0.5 }, second: { floor: 0.5 } },
  } },
  5: { styles: {
    2: { rig: { scale: 0.74 } },
    23: { rig: { dy: -0.09 } },
    24: { rig: { scale: 0.59 }, main: { scale: 0.5 }, second: { scale: 0.5 } },
  } },
  6: { styles: {
    2: { rig: { dx: 0.07 } },
    26: { main: { scale: 0.5 } },
    27: { rig: { scale: 0.85 }, second: { scale: 0.5 } },
    28: { rig: { scale: 0.66 } },
  } },
  7: { styles: {
    2: { rig: { dz: -0.09 }, main: { scale: 0.5 } },
  } },
  8: { styles: {
    35: { rig: { scale: 0.63, dx: -0.06 }, main: { scale: 0.53 } },
  } },
  9: { styles: {
    2: { rig: { dy: -0.09 }, main: { dy: 0.06 } },
    31: { rig: { scale: 0.7 }, second: { scale: 0.5, dz: -0.18 } },
  } },
  10: { styles: {
    2: { rig: { dx: -0.04 }, main: { scale: 1.43 } },
    29: { main: { scale: 0.5 }, second: { scale: 0.5 } },
  } },
  11: { styles: {
    23: { rig: { dy: -0.03 } },
  } },
  12: { styles: {
    1: { rig: { dx: 0.03 } },
    2: { main: { dy: 0.09, floor: 0.51 } },
    32: { main: { scale: 1.18 } },
    33: { rig: { scale: 0.7 }, main: { scale: 0.5 }, second: { scale: 0.7 } },
  } },
  13: { styles: {
    2: { rig: { scale: 0.66 }, main: { dy: 0.09 } },
    23: { rig: { scale: 0.7, dy: -0.03 } },
    39: { rig: { scale: 0.74, dz: 0.09 } },
    40: { rig: { dy: -0.12 } },
  } },
  14: { styles: {
    2: { rig: { dz: -0.09 }, main: { scale: 0.5 } },
    37: { main: { scale: 0.5 } },
    38: { rig: { scale: 1.03, dx: -0.09, dz: 0.15 }, main: { scale: 0.55 } },
  } },
});
/** Coverage budget (shares of the 70 degree / 16:9 frame), derived in tools/test-first-person-coverage.mjs (see FIT notes there). */
/**
 * Coverage budget, in shares of the 70 degree / 16:9 first-person frame, measured by tools/test-first-person-coverage.mjs on the real native pass.
 * DERIVATION (ENGINE-CHOSEN reference set; "looks right" was judged on the real-client baseline shots shots/_fpo-before-*.png; not confirmed against any original):
 * the native weapon styles of classes 2, 3, 4, 6, 7, 8, 10, 11, 12.  Under the final pipeline (clamp on, no table entry needed) they measure:
 *   max steady (idle / run) arm + weapon coverage 22.1 % (class 11 run)      -> STEADY_TOTAL 23 %
 *   max attack-pose coverage 54.2 % (class 4)                                -> ATTACK_TOTAL 55 %
 *   max weapon-only share while standing / running 10.5 % (class 4 run)      -> WEAPON_SHARE 12 %  (WEAPON_SHARE_BIG 18 % for the BIGGEST item
 *                                                                               of a style, which shares its table entry with the typical one: ENGINE-CHOSEN)
 *   smallest weapon share while standing: min over phases 2.8 %, mean 2.9 %  -> WEAPON_MIN 0.3 % in every standing phase (ENGINE-CHOSEN, ~1/10),
 *                                                                               WEAPON_IDLE_MEAN 2 % on average over the stand clip
 *   weapon pixels inside the frame while standing: mean >= 27 %             -> WEAPON_IN_FRAME 20 %
 *   weapon visible in 100 % of the sampled run phases                        -> RUN_SEEN 75 %
 * The upper limits are the reference maxima rounded up; the lower limits are the reference minima rounded down.
 */export const FP_COVERAGE_BUDGET = Object.freeze({ STEADY_TOTAL: 0.23, ATTACK_TOTAL: 0.55, WEAPON_SHARE: 0.12, WEAPON_SHARE_BIG: 0.18, WEAPON_MIN: 0.003, WEAPON_IDLE_MEAN: 0.02, WEAPON_IN_FRAME: 0.2, RUN_SEEN: 0.75 });

/** The framing {rig, main, second} for a class + weapon style (identity fields when nothing is tabulated). */
export function fpFraming(classIndex, style, table = globalThis.__dekaronFpFraming || FP_FRAMING, clamp = globalThis.__dekaronFpClamp || FP_WEAPON_CLAMP) {
  const c = table?.[classIndex] || null, s = c?.styles?.[style] || null;
  return {
    rig: { ...FP_FRAMING_IDENTITY, ...(c?.rig || {}), ...(s?.rig || {}) },
    main: { ...FP_FRAMING_IDENTITY, ...clamp, ...(c?.main || {}), ...(s?.main || {}) },
    second: { ...FP_FRAMING_IDENTITY, ...clamp, ...(c?.second || {}), ...(s?.second || {}) },
  };
}

/** Smooth max(t, 0): 0 below -soft, t above soft, quadratic blend between (continuous with a continuous slope). */
const smax0 = (t, soft) => (t <= -soft ? 0 : t >= soft ? t : (t + soft) * (t + soft) / (4 * soft));
/**
 * Camera-space offset [dx, dy, dz] (metres) that keeps a weapon grip g = [x, y, z] (camera space, metres) inside the keep-in-view region of
 * `w` ({ floor, side, mid, near, soft }); ps = player scale; hand = 'L' | 'R' | null (the hand bone that holds the weapon).
 * Order: forward (near), then up (floor), then sideways (side, then `mid`: a left-hand grip stays at least mid x depth LEFT of the view
 * midline and a right-hand grip RIGHT of it.  MEASURED (tools/test-first-person-coverage.mjs --hands, 4 phases of every native stand clip x every weapon\n * style): 63 of 72 left-hand grip samples are 0.14 .. 1.1 x depth LEFT of the midline and 251 of 255 right-hand samples are 0.12+ x depth RIGHT of it;\n * the outliers are the Segita Hunter bow hand (styles 7 and 8: +0.11 .. +0.16 x depth, RIGHT of the midline although it is the left hand), the Black Wizard\n * left orb (-0.01) and the Dragon Knight pole (right hand, -0.04 m).
 */
export function fpWeaponClamp(g, ps, w, hand = null) {
  const soft = Math.max(1e-6, (w.soft ?? 0.06) * ps);
  const dz = w.near == null ? 0 : -smax0(g[2] + w.near * ps, soft), depth = -(g[2] + dz);
  const dy = w.floor == null ? 0 : smax0(-w.floor * depth - g[1], soft);
  const lim = (w.side ?? 0) * depth;
  let dx = w.side == null ? 0 : smax0(-lim - g[0], soft) - smax0(g[0] - lim, soft);
  if (w.mid != null && hand) { const m = w.mid * depth, x = g[0] + dx; dx += hand === 'L' ? -smax0(x + m, soft) : smax0(m - x, soft); }
  return [dx, dy, dz];
}/** Scale (<= 1) that bounds a weapon whose two largest bounding-box sides are dims = [a, b, ...] (m) to the clamp's `area` (m^2); 1 when off. */
export function fpWeaponAreaScale(dims, area) {
  const a = Number(dims?.[0]) * Number(dims?.[1]);
  return area > 0 && a > area ? Math.sqrt(area / a) : 1;
}
