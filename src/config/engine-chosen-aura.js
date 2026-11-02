// Aura glow (the soft coloured halo that glowing weapons / refined gear throw onto their surroundings).
//
// DATA (data/binary/glow.fx + blurglow.fx, shipped with the Global client):
//   * glow.fx draws glowTexture x glowColor x baseColor into a separate GLOW BUFFER (glowColor = {0.4, 0.4, 0.4, 1});
//   * blurglow.fx adds that buffer, blurred in four directional passes (direction0..3 = (-0.75, 0), (0.75, 0), (0, -1), (0, 1) x
//     uvoffset0..3, weights weight0..3), onto the screen with ONE / ONE blending and no depth test.
//   uvoffset0..3, weight0..3 and baseColor are set by the exe at run time (the exe is packed; the pack data of the fresh Global
//   install is byte-identical to the unpacked data used here, so nothing newer exists in any file). They are therefore NOT known.
//
// ENGINE-CHOSEN / FITTED (not Global constants; each one says how it was set):
//   * the blur kernel is the one data/binary/bloomeffect.fx uses (weights {0.1, 0.358, 1.773, 2.0, 0.773, 0.358, 0.1} at texel
//     offsets {-6, -3, -1.5, 0, 1.5, 3, 6}) applied to the glow buffer, separable, at SCALE x lower resolution;
//   * TAP_SCALE, PASSES and GAIN were FITTED to a Global screenshot (a glowing spear in the Ardeca town frame, the pink
//     aura on the ground);
//   * the per-source gains below say how strong each kind of source is relative to a weapon.
export const AURA = Object.freeze({
  /** glow buffer = drawing buffer / SCALE (the bloom uses 4 as well). */
  SCALE: 4,
  /** multiplier of the bloom kernel's texel offsets, at a 900 px tall screen (scaled with the screen height). FITTED. */
  TAP_SCALE: 2.2,
  /** blur iterations (one iteration = horizontal + vertical). FITTED. */
  PASSES: 2,
  /** composite gain of the blurred buffer. FITTED. */
  GAIN: 4.0,
  /** the glow is drawn this many metres in front of the nearest glow source, so a source never hides its own halo. */
  DEPTH_BIAS: 0.04,
  /** strength of each kind of source (a weapon gem/refinement overlay = 1). ENGINE-CHOSEN. */
  WEAPON_GEM: 1.0,
  WEAPON_REFINE: 1.0,
  /** JUDGMENT (LANE-70, 2026-10-29; no Global value exists, so 0.2 is kept only for the legacy path):
   *  GLOBAL DATA: glow.fx / blurglow.fx author one glowColor {0.4, 0.4, 0.4, 1} for every glow source and no per-source or armor
   *  strength; effectscene 7:10 (the refinement shell) authors texture x colour x alpha keys only, no glow key.
   *  GLOBAL DECOMPILE (32-bit main): the only glow binding is the generic material slot glowTexture (FUN_00740220 / FUN_01576110
   *  slot 0x1e, next to bumpTexture and modelViewProj); there is no glowColor, blurglow, refine or armor glow string or constant.
   *  SERVER-REF (data only): only item / NPC names contain 'aura' or 'glow'; no render value.
   *  ONLINE (elitepvpers Dekaron private-server threads 428792, 429919, 2466371; community, not official): the armor/weapon refine look
   *  is the meshstatus ms_upgrade_U_* / ms_upgrade_W_* shell on Effect\Levelup\eff_upgrade_*.dds, and its strength is the effectscene /
   *  mesh_status alpha keys. That matches the data above: there is no separate armor aura strength.
   *  Not reached by default: gfx-B refineShellAuthored (fx-units.js glowRim = 0) adds no refinement shell to the glow buffer, and
   *  gfx-B previewAuraAuthored (mounts/preview-aura.js) adds no preview armor aura. Used only when both are switched off. */
  ARMOR_REFINE: 0.2,
  /** authored alpha at which a refinement overlay counts as fully lit (the authored peak keys are 0.67 / 0.7 / 0.8). */
  REFINE_ALPHA_REF: 0.8,
  /** farthest a glowing actor is from the camera (m) and still drawn. */
  MAX_DISTANCE: 70,
  /**
   * PERFORMANCE ONLY, no look: while the aura pass renders, the scene's lights are also put on the glow layer so three.js sees the
   * SAME light set in the aura pass and in the frame pass (three keys every lit material's program check on a light-state version
   * that changes whenever the pushed lights differ between two render() calls, which re-ran getProgram / getParameters for every
   * object twice a frame). The aura source materials are unlit, so no pixel changes. false = the previous behaviour (A/B, kill switch).
   * ENGINE-CHOSEN (a switch, not a data value).
   */
  STABLE_LIGHT_STATE: true,
  /**
   * The scene's lights are found by a scene walk, then reused; the walk repeats every this many aura renders (and on a map change,
   * GlowPass.invalidateLights) so a light added later is picked up. A missed light only brings the old light-state churn back for
   * at most this many aura renders; it can never change a pixel. ENGINE-CHOSEN (240 = about one second at the 240 Hz target).
   */
  LIGHT_RESCAN_RENDERS: 240,
});

/** AURA[key], or the console override globalThis.__dekaronAura[key] (tuning only). */
export const auraValue = key => globalThis.__dekaronAura?.[key] ?? AURA[key];
