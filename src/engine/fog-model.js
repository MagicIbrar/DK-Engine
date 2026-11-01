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
// NOT IN THE DATA: the value of g_f3FogCenterPos (set by the exe). The engine keeps the camera (view-space origin).
import * as THREE from 'three';

export const RANGE_FOG_VERTEX = /* glsl */`
#ifdef USE_FOG
	vFogDepth = length( mvPosition.xyz );
#endif
`;

export const LINEAR_FOG_FRAGMENT = /* glsl */`
#ifdef USE_FOG
	#ifdef FOG_EXP2
		float fogFactor = 1.0 - exp( - fogDensity * fogDensity * vFogDepth * vFogDepth );
	#else
		float fogFactor = clamp( ( vFogDepth - fogNear ) / max( fogFar - fogNear, 1e-4 ), 0.0, 1.0 );
	#endif
	gl_FragColor.rgb = mix( gl_FragColor.rgb, fogColor, fogFactor );
#endif
`;

/** The same rule in JS (tests, culling checks): fog amount 0..1 at range d. */
export function fogAmount(d, near, far) {
  return Math.min(1, Math.max(0, (d - near) / Math.max(far - near, 1e-4)));
}

THREE.ShaderChunk.fog_vertex = RANGE_FOG_VERTEX;
THREE.ShaderChunk.fog_fragment = LINEAR_FOG_FRAGMENT;
