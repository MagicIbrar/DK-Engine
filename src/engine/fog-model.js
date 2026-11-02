// (environment) The client's fog model, from the original shaders (data/binary/*.fx, e.g. geometry.fx / boneanimation.fx):
//
//   float GetFogLinear(float3 f3Position, float fFogStart, float fFogEnd) {
//     float fDist = distance(f3Position, g_f3FogCenterPos);
//     return fDist * fFogEnd + fFogStart; }          -> the vertex FOG output (D3D fog factor, clamped 0..1)
//
// i.e. RANGE fog (the 3-D distance to the fog centre, not the view depth) that is LINEAR in that distance. three.js
// r170 defaults to view-depth fog (-mvPosition.z) with a smoothstep ramp: a prop at the screen edge is fogged less than
// one straight ahead at the same distance, and the S-curve fogs too little near the start. Both chunks are replaced
// once, before any program compiles (this module is imported by environment.js). Linear fog keeps the light files'
// fog_value start/end meaning: factor 0 at start, 1 at end (clamped).
//
// 2026-10-29 LANE-66 (Global exe, decompile/32-bit-main FUN_0151b680, disassembly 0151b879..0151b8be):
// the exe turns the light key's fog_value (first = near, second = far) into g_f2FogValue as
//     range = far - near;   x = far / range;   y = -1 / range            (no abs, no min-gap, no swap)
// and only D3DRS_FOGENABLE (28) / D3DRS_FOGCOLOR (34, 0xFF<<24 | r<<16 | g<<8 | b) are ever set: no FOGTABLEMODE /
// FOGVERTEXMODE / FOGSTART / FOGEND / FOGDENSITY (35..38) and no D3DRS_RANGEFOGENABLE, so it is the shader's vertex
// FOG output (linear, clamped 0..1 by the hardware, 1 = clear) and fog density / exp fog are not used at all.
// Fog amount = 1 - clamp(x + y*d) = clamp((d - near) / (far - near)) with the SIGNED denominator.
// 2026-10-29 LANE-66 pass b (Global exe): before the key fog reaches the render core, the Environment light-key apply
// clamps an authored reversed pair: if near > far (strict) then far = near + 1.0 (32-bit FUN_011bcae0 @011bcbb8,
// constant DAT_01b7e1b8 = 1.0; 64-bit FUN_7ff67129b5d0, near +0x68 / far +0x6c, DAT_7ff671e84f48 = 1.0). The earlier
// note that this guard was "invented" was wrong. globalFogGuard() below. The camera-underwater fog (FUN_0151b680 first
// branch, GLOBAL_UNDERWATER_FOG) is built inside the render core and does NOT pass through the guard.
// g_f3FogCenterPos: (P.x, P.y + 4.0 + env[+0x18], P.z), P = camera look-at point (camera object +4 [0..2]). 4.0 =
// DAT_01b7e278 (32-bit FUN_0156afc0 / FUN_0158c090), DAT_7ff671e8500c (64-bit). env[+0x18] (64-bit env+0x70) is 0 for
// every map light key (CMapFogMsg handler FUN_01168fa0 writes 0); only the Effect::Unit::Light "fog s e t3" line
// writes it (t3). setGlobalFogCenter() below; until it is called the shader keeps the camera origin (no regression).
// Billboard sprites (CSpriteRenderer, FUN_0156afc0) set g_f2FogValue.y = DAT_01b7e420 (-1.0) / (range * DAT_01b7e240
// (2.5)) with x unchanged, i.e. sprite fog amount = clamp((d / 2.5 - near) / range): GLOBAL_BILLBOARD_FOG_RANGE_SCALE + applyBillboardFogScale().
// The Bone mesh scale path (FUN_0158bfd0) has no writer of its scale in either exe -> plain fog (scale 1, removed).
import * as THREE from 'three';

export const RANGE_FOG_PARS_VERTEX = /* glsl */`
#ifdef USE_FOG
	varying float vFogDepth;
	uniform vec4 dkFogCenter; // xyz = Global g_f3FogCenterPos (world), w = 1 when set (0 -> camera origin)
	#ifndef DK_FOG_RANGE_SCALE
		#define DK_FOG_RANGE_SCALE 1.0
	#endif
#endif
`;

export const RANGE_FOG_VERTEX = /* glsl */`
#ifdef USE_FOG
	vFogDepth = ( dkFogCenter.w > 0.5
		? length( mvPosition.xyz - ( viewMatrix * vec4( dkFogCenter.xyz, 1.0 ) ).xyz )
		: length( mvPosition.xyz ) ) / DK_FOG_RANGE_SCALE;
#endif
`;

export const LINEAR_FOG_FRAGMENT = /* glsl */`
#ifdef USE_FOG
	#ifdef FOG_EXP2
		float fogFactor = 1.0 - exp( - fogDensity * fogDensity * vFogDepth * vFogDepth );
	#else
		float fogRange = fogFar - fogNear;   // signed (Global FUN_0151b680); +-1e-4 only so an exact 0 cannot divide by zero
		float fogFactor = clamp( ( vFogDepth - fogNear ) / ( abs( fogRange ) < 1e-4 ? 1e-4 : fogRange ), 0.0, 1.0 );
	#endif
	gl_FragColor.rgb = mix( gl_FragColor.rgb, fogColor, fogFactor );
#endif
`;

/** Global's g_f2FogValue for a fog_value pair (FUN_0151b680): shader fog factor = clamp(x + y*d), 1 = clear. */
export function globalFogValue(near, far) {
  const range = far - near;
  return { range, x: far / range, y: -1 / range };
}

/** Signed fog range with the engine-side zero guard (an exact 0 never occurs in Global light files). */
export function signedFogRange(near, far) {
  const r = far - near;
  return Math.abs(r) < 1e-4 ? 1e-4 : r;
}

/** The same rule in JS (tests, culling checks): fog amount 0..1 at range d (1 - Global's clamped fog factor). */
export function fogAmount(d, near, far) {
  return Math.min(1, Math.max(0, (d - near) / signedFogRange(near, far)));
}

/** Range beyond which nothing is fully fogged-out: far for normal fog; reversed fog (far < near) clears beyond near. */
export function fogHidesBeyond(near, far) {
  return far > near ? far : Infinity;
}

/**
 * Global camera-underwater fog (FUN_0151b680 first branch): when the camera eye is inside the map's water grid
 * (cell = truncated FILE x / z) and below that cell's water height h, the light key's fog is replaced by
 * colour 0xff4050a0 and near = max(-20, 15 - (h - eyeY) * 10), far = 60 (constants 15, 10, -20, 60 read from
 * the exe image). Returns null when the eye is not underwater. The exe skips this branch when the eye cell's
 * water entry has definition type 4 (FloorReflect: FUN_0098bc60 -> +0xbc -> +0x60 -> +0x64 == 4; 64-bit
 * FUN_7ff670a55630 / FUN_7ff67164ef70): callers pass that type as `waterType` (null/undefined = unknown, not 4).
 */
export const GLOBAL_UNDERWATER_FOG = Object.freeze({ argb: 0xff4050a0, nearBase: 15, depthScale: 10, nearMin: -20, far: 60 });
export function underwaterFog(waterHeight, eyeY, waterType = null) {
  if (waterType === 4) return null;
  if (!(Number.isFinite(waterHeight) && Number.isFinite(eyeY)) || !(waterHeight > eyeY)) return null;
  const u = GLOBAL_UNDERWATER_FOG;
  const near = Math.max(u.nearMin, u.nearBase - (waterHeight - eyeY) * u.depthScale);
  return { near, far: u.far, color: [((u.argb >>> 16) & 255) / 255, ((u.argb >>> 8) & 255) / 255, (u.argb & 255) / 255] };
}

/** Global reversed-fog guard (FUN_011bcae0 / FUN_7ff67129b5d0): near > far -> far = near + 1.0. Key fog only. */
export const GLOBAL_FOG_GUARD_GAP = 1.0;
export function globalFogGuard(near, far) {
  return near > far ? { near, far: near + GLOBAL_FOG_GUARD_GAP } : { near, far };
}

/** g_f3FogCenterPos height above the look-at point: 4.0 (DAT_01b7e278 / DAT_7ff671e8500c) + env[+0x18]. */
export const GLOBAL_FOG_CENTER_LIFT = 4.0;
/** CSpriteRenderer billboard fog range multiplier (FUN_0156afc0): sprites fog at distance / 2.5. */
export const GLOBAL_BILLBOARD_FOG_RANGE_SCALE = 2.5;

// One shared plain {x,y,z,w} object: UniformsUtils.clone/merge copy only objects with .clone, so every material (built-in
// ShaderLib programs and ShaderMaterials merged from UniformsLib.fog) references this same value.
export const FOG_CENTER = { x: 0, y: 0, z: 0, w: 0 };
const FOG_CENTER_UNIFORM = { value: FOG_CENTER };

/** Set Global's fog centre from the camera look-at point (three world coords) and env[+0x18] (0 for map keys). */
export function setGlobalFogCenter(lookAt, offset = 0) {
  if (!lookAt) { FOG_CENTER.w = 0; return FOG_CENTER; }
  FOG_CENTER.x = lookAt.x;
  FOG_CENTER.y = lookAt.y + GLOBAL_FOG_CENTER_LIFT + (Number.isFinite(offset) ? offset : 0);
  FOG_CENTER.z = lookAt.z;
  FOG_CENTER.w = 1;
  return FOG_CENTER;
}

/** Mark a material as a Global billboard sprite (fog range x 2.5). Returns the material. */
export function applyBillboardFogScale(material) {
  if (!material) return material;
  material.defines = { ...(material.defines || {}), DK_FOG_RANGE_SCALE: GLOBAL_BILLBOARD_FOG_RANGE_SCALE.toFixed(1) };
  material.needsUpdate = true;
  return material;
}

THREE.UniformsLib.fog.dkFogCenter = FOG_CENTER_UNIFORM;
for (const lib of Object.values(THREE.ShaderLib)) {
  if (lib && lib.uniforms && lib.uniforms.fogNear && !lib.uniforms.dkFogCenter) lib.uniforms.dkFogCenter = FOG_CENTER_UNIFORM;
}
THREE.ShaderChunk.fog_pars_vertex = RANGE_FOG_PARS_VERTEX;
THREE.ShaderChunk.fog_vertex = RANGE_FOG_VERTEX;
THREE.ShaderChunk.fog_fragment = LINEAR_FOG_FRAGMENT;
