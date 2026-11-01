// ENGINE-CHOSEN skill effect presentation policies (fx-units.js, fx-trails.js). The fields themselves are read from
// Global data (property/effect/effectdata.*.txt via tools/build-skills.mjs); only the points marked here are
// interpretations that no Global file states. Each one names its evidence. A quality setting changes cost only:
// 'faithful' draws every authored layer; 'safe' keeps them but caps the work per unit.
//
// tailstep <count> <a> <b> <ms> <on>  (26,085 authored lines; 312 enabled units with count > 0)
//   Read as an after-image emitter: a frozen copy of the unit is left behind every `a` ms (a > 0) or every `b` metres
//   travelled (b > 0), each copy fades linearly to 0 over `ms`, at most `count` copies at once. a = b = 0 spaces the
//   copies evenly over ms / count. Evidence: in the "a > 0, b = 0" rows ms == count * a in most cases (3 20 0 60,
//   3 50 0 150, 5 20 0 100, 10 10 0 100, 5 5 0 50), which an interval reading explains. The b-only rows sit on moving
//   projectiles and are 0.01 .. 0.3, a plausible distance step. Native vertex format (binary/trace.fx): position, uv
//   and per-vertex colour, texture modulated, fog. The copies use the unit's own texture, blend and size.
//   [medium confidence: interval/spacing/fade reading not stated by any Global file]
export const TRAIL = Object.freeze({
  MAX_COPIES: 128,          // safety cap per unit (authored count max is 300, but emission is at most one copy per frame)
  FRAME_MS: 1000 / 60,      // ms used when a row authors ms = 0 (lifetime = count frames)
});

// Colour keys above 1.0 (135 skills). The fixed-function pipeline (billboard.fx / tracemesh.fx: texture x vertex
// colour) cannot exceed 1 per channel in a D3D9 vertex colour (COLOR0 is saturated to [0,1] by the rasteriser), so the
// faithful reading of an over-range key is the saturated value, NOT an HDR boost. Three's material colour is not
// clamped (MeshBasicMaterial multiplies a float uniform), so the client currently draws keys > 1 brighter than native.
// 'faithful' clamps each channel to 1 (D3D9 COLOR0 behaviour); 'boost' keeps the unclamped float (previous client
// behaviour, an additive-glow look) for comparison only.
export const COLOR_OVERRANGE = 'faithful';

// Distortion units (`distort true`, 3 units, 1 skill: sp_BAR_Crash_Boost_01..03). No Global shader implements a
// distortion/refraction pass (binary/*.fx has bloom, glow, blur, trace, billboard, water; none samples the scene
// colour for offset UVs), so the native presentation of the flag is unknown. 'off' draws the unit as an ordinary
// sprite (the current behaviour, the authored texture still shows). 'refract' is a screen-copy refraction approximation
// (one extra framebuffer copy per frame while such a unit is visible), opt-in only.
export const DISTORT = Object.freeze({ MODE: 'off', STRENGTH: 0.03 });

// Quality: 'faithful' (default) draws every authored trail copy and specular/glow map. 'safe' halves the trail copy
// cap and skips specular maps on effect meshes, for software renderers or very busy scenes.
export const SKILL_FX_QUALITY = { level: 'faithful' };
export const trailCopyCap = () => SKILL_FX_QUALITY.level === 'safe' ? TRAIL.MAX_COPIES >> 1 : TRAIL.MAX_COPIES;

// Bone-name aliases for VERIFIED authoring typos only. A name qualifies when (1) no Global skeleton (skel/character,
// skel/effect, any bone name or alias) defines it and (2) it is one edit away from a virtual attach point the effect
// player resolves itself ('', top, center, movement). Census of all 1,521 distinct effectscene bonename values:
//   "movemevt" (1 use, 100:1013 scene 1 unit 1, Azure Knight) -> "movement".   ("top00" is 2 edits away: not aliased.)
// Every other unresolved name (body_u on bar.skel, Dum1-5, eye01/02, Point00x, eff_fire0x ...) is a real bone of some
// other skeleton (monster/servant/effect) or unknown; those keep the existing Spine1 -> Bip01 -> half-height fallback.
export const BONE_ALIASES = Object.freeze({ movemevt: 'movement' });
