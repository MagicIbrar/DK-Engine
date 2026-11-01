// The client's lighting rules for lit world materials (terrain, objects, actors):
//  1. "Shade light": the sun only lights the world within a radius of the player (below).
//  2. Saturation: lighting never makes a surface brighter than its texture (CLAMP_GLSL below).
//
// Every lit shader of the client (data/binary/geometry.fx for the terrain and objects, boneanimation.fx for
// characters) computes
//     diffuse = ambient + max(N.L, 0) x sunColour x shade,   shade = 1 - min(1, |P - g_f3ShadePos| / g_fShadeDistance)
// i.e. the directional light fades linearly to zero at `lightdistance` (map/light_*.txt, environment.js
// `lightDistance`) from the shade centre (the player). Dungeons use 5-10 units - a pool of light around the hero -,
// open fields 100, showcase scenes 250-10000.
//
// applyShade(material) patches a three.js MeshLambert/Phong/Standard material (onBeforeCompile, chained with any
// existing hook) so its directional lights are multiplied by that factor. One module-level uniform (SHADE) drives
// every patched material, so they never need recompiling when the map changes; with no world loaded the radius is
// huge (factor 1). World.update() sets it every frame and patches the materials it finds under game.worldRoot.
//  3. Sampler LOD bias: the map's maplist MipMapBias on the diffuse lookup (src/engine/sampler-state.js).
import * as THREE from 'three';
import { MIP_BIAS, MIP_BIAS_GLSL, MAP_FRAGMENT_BIAS } from '../engine/sampler-state.js';

/** xyz = shade centre in THREE world space, w = distance (world units). */
export const SHADE = { value: new THREE.Vector4(0, 0, 0, 1e9) };

const GLSL = /* glsl */`
uniform vec4 dkShade;
float dkShadeFactor(vec3 viewPos) {
  vec3 c = (viewMatrix * vec4(dkShade.xyz, 1.0)).xyz;
  return 1.0 - min(1.0, distance(viewPos, c) / max(dkShade.w, 1e-3));
}`;

// D3D9 saturates the vertex-shader colour output (COLOR0 = vertexColour x (ambient + sun x shade)) to [0,1] before
// it modulates the texture, so lit surfaces never get brighter than their texture: outgoing = tex x min(light, 1).
// With three's lighting that is min(diffuse light, reference) where the reference is the diffuse colour, or - for the
// terrain, whose vertex colour is inside the clamp - the bare tile colour (DK_TILE_CLAMP, dkTileColor set by
// terrain.js). Emissive (target highlight) stays on top.
const CLAMP_GLSL = /* glsl */`
#ifdef DK_TILE_CLAMP
  outgoingLight = min(outgoingLight - totalEmissiveRadiance, dkTileColor) + totalEmissiveRadiance;
#else
  outgoingLight = min(outgoingLight - totalEmissiveRadiance, diffuseColor.rgb) + totalEmissiveRadiance;
#endif
#include <opaque_fragment>`;

let patchedChunk = null;
function lightsChunk() {
  if (!patchedChunk) {
    const src = THREE.ShaderChunk.lights_fragment_begin;
    const anchor = 'getDirectionalLightInfo( directionalLight, directLight );';
    patchedChunk = src.includes(anchor)
      ? src.replace(anchor, `${anchor}\n\t\tdirectLight.color *= dkShadeFactor( geometryPosition );`)
      : src; // unknown three.js version: leave lighting untouched
  }
  return patchedChunk;
}

const patched = new WeakSet();

/** Patch a lit material (idempotent). Returns the material. */
export function applyShade(material) {
  if (!material || patched.has(material)) return material;
  if (!(material.isMeshLambertMaterial || material.isMeshPhongMaterial || material.isMeshStandardMaterial)) return material;
  patched.add(material);
  const prev = material.onBeforeCompile;
  const own = Object.prototype.hasOwnProperty.call(material, 'onBeforeCompile') ? prev : null;
  material.onBeforeCompile = function (shader, renderer) {
    if (own) own.call(this, shader, renderer);
    shader.uniforms.dkShade = SHADE;
    shader.uniforms.dkMipBias = MIP_BIAS;
    shader.fragmentShader = shader.fragmentShader
      .replace('#include <common>', `#include <common>\n${GLSL}\n${MIP_BIAS_GLSL}`)
      .replace('#include <map_fragment>', MAP_FRAGMENT_BIAS)
      // itemmesh.fx (weapons, drops: userData.dkNoShade, models.js / matfx.js) has no ShadeLighting: clamp only
      .replace('#include <lights_fragment_begin>', this.userData?.dkNoShade ? '#include <lights_fragment_begin>' : lightsChunk())
      .replace('#include <opaque_fragment>', CLAMP_GLSL);
  };
  const prevKey = Object.prototype.hasOwnProperty.call(material, 'customProgramCacheKey') ? material.customProgramCacheKey : null;
  // keep the old key (three's default is the hook's source) so differently patched materials never share a program
  material.customProgramCacheKey = function () {
    return `${prevKey ? prevKey.call(this) : own ? own.toString() : ''}|dkshade2${this.userData?.dkNoShade ? '-noshade' : ''}`;
  };
  material.needsUpdate = true;
  return material;
}

/** Apply to every material of an object tree. */
export function applyShadeTree(root) {
  root.traverse(o => {
    if (!o.material) return;
    if (Array.isArray(o.material)) o.material.forEach(applyShade); else applyShade(o.material);
  });
}

/** Set the shade centre (THREE space vector) and radius. */
export function setShade(center, distance) {
  SHADE.value.set(center.x, center.y, center.z, Number.isFinite(distance) && distance > 0 ? distance : 1e9);
}

/** No world: no fall-off. */
export function resetShade() { SHADE.value.set(0, 0, 0, 1e9); }
