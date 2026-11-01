// Material effects of the client's shaders that three's stock Lambert/Phong do not have,
// written from the original sources data/binary/boneanimation.fx, itemmesh.fx, glow.fx. Constants and the
// values the exe sets at run time (ENGINE-CHOSEN) live in ./material-constants.js.
//
//  * SPECULAR MAPS (tpack `sN` slots, *_s.dds; classes/monsters.json textures.specular):
//      - skinned characters / monsters (armour) use boneanimation.fx "BoneAnimEnv" (vsBone0Env / vsBonesEnv + psEnvSpecular):
//            D      = saturate( (ambient + max(N.L, 0) x sun x shade) x f4GlobalColor + f4SpecularColor )   (COLOR0, per vertex)
//            colour = tex x D + specMap.rgb x D x texCUBE(envTexture, R)
//            R      = reflect(eye, N) per vertex in MODEL space (f4Position / f3Normal after skinning, before the world matrix)
//        -> MeshLambertMaterial (its lit colour = tex x min(light, 1) with shade.js) + specularMap + the env term below.
//           envTexture = the data's only cube map, texture/environment/cube/test=.dds (ENV_CUBE_KEY, setEnvironment):
//           soft white light spots on black. (It used to be the map's sky strip, a 2D water panorama.)
//           All three specular-map channels are used (three's specularStrength is the red channel only).
//      - item meshes (weapons, drops) use itemmesh.fx "ItemMeshSpecular" (vsBone0Item_Specular + ps2Specular):
//            colour = tex x saturate(Aci + max(N.L, 0) x sun) + specMap.rgb x pow(max(0, N.H), g_fShininess) x sun x 1.2
//        -> MeshLambertMaterial + the specular term below: no N.L factor, no Fresnel / BRDF normalisation, no shade fall-off
//           (itemmesh.fx has no ShadeLighting; shade.js skips materials flagged userData.dkNoShade).
//      - eye-vector sign: the .fx write `reflect(eyeToVertex, N)` / `H = normalize(L - eye)` with eye = normalize(eyePos -
//        position), and the item vertex shader even takes `position` from the clip-space output. Read literally the half
//        vector can never face a front-facing surface (no highlight at all). ENGINE-CHOSEN (not in Global data): the
//        textbook view vector, H = normalize(L + V) and R = physical reflection (EYE_CONVENTION in material-constants.js).
//  * GLOW MAPS (tpack `gN`, and the client's '<name>+.dds' textures with a '<name>+.<ext>.glow' image beside them):
//      glow.fx draws glowTexture x glowColor (0.4) x baseColor into the glow buffer, blurglow.fx adds it blurred onto the
//      screen -> emissiveMap x 0.4 here; the bloom pass (src/systems/graphics) spreads the halo.
//
// shade.js clamps the lit colour to the texture (D3D9 saturates COLOR0 before the modulate) - the specular / env terms
// are D3D's separate specular (the pixel shader's add) and stay on top of that clamp: patchSpecular() adds them after
// opaque_fragment (shade.js chains our onBeforeCompile first, so its clamp lands before), and the sum saturates like the
// ps_1_1 / ps_2_0 output into the 8-bit back buffer. Fog (fixed-function, after the pixel shader) comes later.
//
// SPEC.gain (a shared uniform) is the Options "Reflection" switch x the adaptive quality governor.
import * as THREE from 'three';
import { GLOW_COLOR as FX_GLOW_COLOR, ITEM_SPECULAR_SCALE, ITEM_SHININESS, ENV_CUBE_KEY } from './material-constants.js';

/** Shared uniforms: gain = specular/env strength (0 = off). */
export const SPEC = { gain: { value: 1 } };
/** itemmesh.fx ps2Specular gain (x sun x specular map). */
export const ITEM_SPEC_GAIN = ITEM_SPECULAR_SCALE;
export { ENV_CUBE_KEY };

const ENV_MATS = new Set();         // materials using the environment cube
let ENV = null;                     // current environment cube texture
let FALLBACK = null;
let DATA_CUBE = null;                // texture/environment/cube/test=.dds once loaded
let CUBE_LOADING = null;

/** A black 1x1 cube (no environment light) used until the data cube is loaded. */
export function fallbackEnvironment() {
  if (FALLBACK) return FALLBACK;
  const faces = [];
  for (let i = 0; i < 6; i++) {
    const t = new THREE.DataTexture(new Uint8Array([0, 0, 0, 255]), 1, 1, THREE.RGBAFormat, THREE.UnsignedByteType);
    t.needsUpdate = true;
    faces.push(t);
  }
  const c = new THREE.CubeTexture(faces);
  Object.assign(c, { colorSpace: THREE.NoColorSpace, magFilter: THREE.LinearFilter, minFilter: THREE.LinearFilter, generateMipmaps: false });
  c.name = 'dk black environment cube';
  c.needsUpdate = true;
  FALLBACK = c;
  return c;
}

/**
 * Load the client's environment cube (ENV_CUBE_KEY) through a TextureCache (game.models.textures) once; every
 * env-specular material reflects it from then on. Resolves the cube or null.
 */
export function loadEnvironmentCube(textures) {
  if (DATA_CUBE) return Promise.resolve(DATA_CUBE);
  if (!CUBE_LOADING && textures?.load) {
    CUBE_LOADING = Promise.resolve(textures.load(ENV_CUBE_KEY, { mipmaps: 'file' })).then(t => {
      if (t?.isCubeTexture) { DATA_CUBE = t; if (!ENV || ENV === FALLBACK) setEnvironment(t); }
      else CUBE_LOADING = null;
      return DATA_CUBE;
    }, () => { CUBE_LOADING = null; return null; });
  }
  return CUBE_LOADING || Promise.resolve(null);
}

/**
 * The environment cube every env-specular material reflects. A cube texture is used as given; anything else (the old
 * callers pass the map's 2D sky strip, which a texCUBE cannot sample) selects the data cube, or black until it loads.
 */
export function setEnvironment(tex) {
  const t = tex && tex.isCubeTexture ? tex : (DATA_CUBE || fallbackEnvironment());
  if (ENV === t) return;
  ENV = t;
  for (const m of ENV_MATS) if (m.envMap !== t) m.envMap = t;
}
export function currentEnvironment() { return ENV || fallbackEnvironment(); }

const SPEC_PARS = /* glsl */`
uniform float dkSpecGain;
uniform float dkShininess;`;

// vertex: boneanimation.fx vsBone0Env / vsBonesEnv - per-vertex reflection in model space (after skinning, before the
// world / instance matrix), from the camera position brought into that space
const ENV_VERTEX_PARS = /* glsl */`
varying vec3 vDkReflect;`;
const ENV_VERTEX = /* glsl */`
#include <project_vertex>
{
  mat4 dkModel = modelMatrix;
  #ifdef USE_INSTANCING
    dkModel = modelMatrix * instanceMatrix;
  #endif
  vec3 dkEyeM = ( inverse( dkModel ) * vec4( cameraPosition, 1.0 ) ).xyz;
  vDkReflect = reflect( normalize( transformed - dkEyeM ), normalize( objectNormal ) );
}`;

// replaces #include <envmap_fragment>
const SPEC_SPLIT = /* glsl */`
vec3 dkSpecAdd = vec3( 0.0 );
#ifdef PHONG
  outgoingLight -= reflectedLight.directSpecular + reflectedLight.indirectSpecular;   // replaced by the .fx terms
#endif
vec3 dkSpecMap = vec3( specularStrength );
#ifdef USE_SPECULARMAP
  dkSpecMap = texelSpecular.rgb;                       // .fx: specularMap.xyz (all three channels)
#endif
#if defined( DK_SPEC_ENV ) && defined( USE_ENVMAP ) && defined( ENVMAP_TYPE_CUBE )
  // psEnvSpecular: specularMap x COLOR0 x envCube(R); COLOR0 = saturate(vertex light) = min(lit / albedo, 1)
  vec3 dkLit = ( reflectedLight.directDiffuse + reflectedLight.indirectDiffuse ) / max( diffuseColor.rgb, vec3( 0.02 ) );
  dkSpecAdd += dkSpecMap * min( dkLit, vec3( 1.0 ) ) * textureCube( envMap, vDkReflect ).rgb;
#endif
#if defined( DK_SPEC_ITEM ) && NUM_DIR_LIGHTS > 0
  // ps2Specular: specularMap x pow(max(0, N.H), g_fShininess) x sun x 1.2 (three's light colours are x PI)
  vec3 dkV = normalize( vViewPosition );
  for ( int i = 0; i < NUM_DIR_LIGHTS; i ++ ) {
    vec3 dkH = normalize( directionalLights[ i ].direction + dkV );
    dkSpecAdd += dkSpecMap * pow( max( 0.0, dot( normal, dkH ) ), dkShininess ) * directionalLights[ i ].color * ( ${ITEM_SPECULAR_SCALE.toFixed(4)} / PI );
  }
#endif
dkSpecAdd *= dkSpecGain;`;

/**
 * Give a lit material the client's specular path (see header). kind 'env' (skinned, BoneAnimEnv) or 'item'
 * (ItemMeshSpecular). The material must already carry its specularMap. Idempotent; survives clone() through
 * reapplySpecular (models.js SkinnedInstance._adopt).
 */
export function patchSpecular(mat, kind = 'env') {
  if (!mat || mat.userData?.dkSpec) return mat;
  mat.userData.dkSpec = kind;
  if (kind === 'env') {
    mat.envMap = currentEnvironment();
    mat.combine = THREE.AddOperation;
    mat.reflectivity = 1;
    ENV_MATS.add(mat);
  } else {
    mat.userData.dkNoShade = true;                     // itemmesh.fx: no ShadeLighting
  }
  const define = kind === 'env' ? 'DK_SPEC_ENV' : 'DK_SPEC_ITEM';
  const prev = Object.prototype.hasOwnProperty.call(mat, 'onBeforeCompile') ? mat.onBeforeCompile : null;
  mat.onBeforeCompile = function (shader, renderer) {
    if (prev) prev.call(this, shader, renderer);
    shader.uniforms.dkSpecGain = SPEC.gain;
    shader.uniforms.dkShininess = { value: ITEM_SHININESS };
    if (kind === 'env') {
      shader.vertexShader = shader.vertexShader
        .replace('#include <common>', `#include <common>\n${ENV_VERTEX_PARS}`)
        .replace('#include <project_vertex>', ENV_VERTEX);
    }
    shader.fragmentShader = shader.fragmentShader
      .replace('#include <common>', `#define ${define}\n#include <common>\n${SPEC_PARS}${kind === 'env' ? ENV_VERTEX_PARS : ''}`)
      .replace('#include <envmap_fragment>', SPEC_SPLIT)
      .replace('#include <opaque_fragment>', '#include <opaque_fragment>\n\tgl_FragColor.rgb += dkSpecAdd;\n\tgl_FragColor.rgb = min( gl_FragColor.rgb, vec3( 1.0 ) );   // ps output saturates');
  };
  const prevKey = Object.prototype.hasOwnProperty.call(mat, 'customProgramCacheKey') ? mat.customProgramCacheKey : null;
  mat.customProgramCacheKey = function () { return `${prevKey ? prevKey.call(this) : ''}|dkspec2-${kind}`; };
  mat.needsUpdate = true;
  return mat;
}

/** Re-apply the patch to a clone of a patched material (Material.copy keeps userData but not the hooks). */
export function reapplySpecular(src, clone) {
  const kind = src?.userData?.dkSpec;
  if (!kind || !clone) return clone;
  if (clone.userData) delete clone.userData.dkSpec;
  return patchSpecular(clone, kind);
}

/** Forget a disposed material. */
export function releaseMaterial(mat) { ENV_MATS.delete(mat); }

/** Glow (emissive) strength of the client's glow.fx: glowColor = 0.4. */
export const GLOW_COLOR = FX_GLOW_COLOR;

/**
 * Candidate data keys of the glow image of a diffuse texture: the client ships '<name>+.dds' with
 * '<name>+.<original ext>.glow' beside it (texture/object/d_mushroom_01+.dds.glow, d_jewel_01+.jpg.glow).
 */
export function glowCandidates(diffuseKey) {
  const k = String(diffuseKey || '').toLowerCase();
  const base = k.slice(k.lastIndexOf('/') + 1);
  if (!base.includes('+')) return [];
  const stem = k.replace(/\.[^./]+$/, '');
  return [`${k}.glow`, ...['dds', 'tga', 'bmp', 'jpg', 'png'].map(e => `${stem}.${e}.glow`)].filter((v, i, a) => a.indexOf(v) === i);
}
