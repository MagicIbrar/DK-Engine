// Water surfaces of a .map (map.md "Water"): one quad per water cell at its surface level, grouped in 64x64-cell
// regions for culling, one material per water definition (property/effect/water/*.txt, environment.js parseWater).
//
// The look follows the client's own shader, data/binary/water.fx (techniques by definition `type`):
//   type 0 / -1  "Water/WaterWave"  fixed function: diffuse texture (uv1) x g_waterColor
//   type 2       "WaterEnvWave"     ps.1.1 texm3x3vspec: environment reflection of the bump normal x g_waterColor
//   type 1       "WaterRefWave"     psWaterRef: lerp(scatter x (0.1 + refraction) x phase, reflection, fresnel(H, 0.0204,
//                                  3.8)), alpha 1; reflection / refraction are planar render targets (below)
//   type 3       "WaterReflect"     psReflect: planar reflection, alpha = fresnel(H, 0.4, 3.5) x g_waterColor.a, no wave
//   type 4       "FloorReflect"     shiny floors: drawn by systems/hud-options/waterfx.js (Tile Reflection option), not here.
//                                  The definition type is kept per entry (typeAt): Global skips the camera-underwater fog
//                                  when the eye cell's water entry is type 4 (FUN_0151b680 via FUN_0098bc60; LANE-66).
// Waves are water.fx MakeWave: y += A sin(2pi/L (D.xz - s t)), D = (-sin a, -cos a) (FUN_0097d0f0).
//
// Global values (32-bit addresses; 64-bit cross-checks in docs/global-parity-420/lanes/LANE-66-REPORT.md rev c):
//   uv = (col, row) x 0.125 for every water vertex                 FUN_0098ca80, 0.125 @DAT_01b7e118 (64-bit 0x7ff671e84e60)
//   g_f2UV / g_f2UV2 = frac(D x speed x t x 0.1), t in seconds      FUN_01545ff0 / FUN_015473d0, 0.1 @DAT_01b7e114
//   g_waterColor = (1, 1, 1, a): a = 0.4 for type >= 1 (planar path) @0x01b7e6b0; otherwise the alpha curve at
//                  trunc((1 - frac(t)) x 999) (999 @DAT_01b7e3bc), 1.0 without a curve. The definition `color` is parsed
//                  (FUN_0097cb80) but never reaches the shader.
//   diffuse frame = (time ms / definition time) % frames            FUN_01545d00
//   type 2 bump = the renderer's texturepack/effect/water.tpack (16 frames, 90 ms each) CWaterRenderer FUN_015458a0
//   definition defaults: type 1, attenuation (0.032, 0.02, 0.008), waves speed 0 / amplitude 0 / wavelength 2 / dir 0
//                  FUN_0097c8e0 (@DAT_01b7e0f8, @DAT_01b7e0f0, imm 0x3c03126f); an unreadable definition never loads, so
//                  the entry is not drawn (FUN_0097cb80 failure path)
//   planar targets: 512 x 512 (256 if the device refuses, 0x0159ee90 / 0x0159f2c0), reflection slot 6 + refraction slot
//                  7 (FUN_01545e40) for types 1 and 3; plane height = maplist Reflect_Height (RenderTexture::Provider
//                  +0x18 setter 0x01591840 from the camera setup FUN_01540660).
// Labelled judgments (LANE-66 rev c): Reflect_Height -1000 (= none) uses the entry's water level as the plane; the
// type 2 tangent frame is water.fx's no-wave frame for every vertex (the wave frame's T = (0, df/dz, 0) is degenerate);
// type 0 draws stage 0 only (stage 1 is never configured in the water path and D3D's default stage-1 op is DISABLE).
//
// FILE frame under worldRoot: (x = col, y = level, z = row), D3D winding (see terrain.js). Colours are raw 0..1.
import * as THREE from 'three';
import { parseWater, skyStripToEquirect } from '../formats/environment.js';
import { sampleHeight } from '../formats/map.js';
import { parseTpack, resolveTexture } from '../formats/tpack.js';
import { fetchText, tryFetchBuffer } from '../engine/assets.js';
import { decodeRGBA, loadTexture } from './texload.js';

const REGION = 64;
/** Global water constants (see header). */
export const WATER_GLOBAL = Object.freeze({
  UV_SCALE: 0.125,                 // FUN_0098ca80 @DAT_01b7e118
  SCROLL_RATE: 0.1,                // FUN_015473d0 @DAT_01b7e114
  ALPHA_STEPS: 999,                // FUN_01545ff0 @DAT_01b7e3bc
  PLANAR_ALPHA: 0.4,               // @0x01b7e6b0 (1, 1, 1, 0.4)
  DEFAULT_TYPE: 1,                 // FUN_0097c8e0
  DEFAULT_ATTENUATION: Object.freeze([0.032, 0.02, 0.008]),   // FUN_0097c8e0
  DEFAULT_WAVE: Object.freeze({ speed: 0, amplitude: 0, wavelength: 2, direction: 0 }),   // FUN_0097c8e0
  BUMP_PACK: 'texturepack/effect/water.tpack',   // CWaterRenderer FUN_015458a0 (FUN_01547df0)
  BUMP_FRAME_MS: 90,               // CWaterRenderer +0x18 = 0x5a
  RT_SIZE: 512,                    // 0x0159ee90 (256 fallback 0x0159f2c0)
  NO_REFLECT_HEIGHT: -1000,        // maplist Reflect_Height "none"
});
const DEFAULT_ATTENUATION = WATER_GLOBAL.DEFAULT_ATTENUATION;

const WATER_VERTEX = /* glsl */`
attribute float depth;          // water level - terrain height at this vertex (FILE frame; vertex.position.w in water.fx)
uniform float time;
uniform vec4 wave1;             // speed, amplitude, 2pi/wavelength, direction (rad)
uniform vec4 wave2;
uniform vec4 scroll;            // g_f2UV (xy), g_f2UV2 (zw)
uniform mat4 reflectMatrix;     // g_reflectVPTex
uniform mat4 refractMatrix;     // g_refractVPTex
uniform vec3 attenuation;
varying vec2 vUv1;
varying vec2 vUv2;
varying vec3 vEye;              // eye - undisplaced vertex (water.fx eyeVec)
varying vec4 vRefl;
varying vec4 vRefr;
varying vec3 vScatter;
#include <fog_pars_vertex>
float waveY(vec4 w, vec2 xz) {
  vec2 d = vec2(-sin(w.w), -cos(w.w));   // FUN_0097d0f0
  return w.y * sin(w.z * (dot(d, xz) - w.x * time));
}
void main() {
  vec3 p = position;
#if WATER_WAVE == 1
  p.y += waveY(wave1, position.xz) + waveY(wave2, position.xz);
#endif
  vec2 uv = position.xz * ${WATER_GLOBAL.UV_SCALE.toFixed(3)};
  vUv1 = uv + scroll.xy;
  vUv2 = uv + scroll.zw;
  vec4 wp = modelMatrix * vec4(p, 1.0);
  vec4 wp0 = modelMatrix * vec4(position, 1.0);
  vEye = cameraPosition - wp0.xyz;
  vRefl = reflectMatrix * wp;
  vRefr = refractMatrix * wp;
  vScatter = vec3(1.0);
#if WATER_MODE == 1
  // vsWaterRef: underwater path length of the view ray to the terrain under this vertex
  vec3 geo = (modelMatrix * vec4(position.x, position.y - depth, position.z, 1.0)).xyz;
  float dist = length(cameraPosition - geo);
  float wh = cameraPosition.y - wp0.y;
  float den = cameraPosition.y - geo.y;
  if (abs(den) < 1e-5) den = den < 0.0 ? -1e-5 : 1e-5;
  float dd = dist - dist * wh / den;
  vScatter = exp(max(0.0, dd) * -attenuation);
#endif
  vec4 mvPosition = viewMatrix * wp;
  gl_Position = projectionMatrix * mvPosition;
  #include <fog_vertex>
}`;

const WATER_FRAGMENT = /* glsl */`
uniform sampler2D map;
uniform float hasMap;
uniform sampler2D bumpMap;       // type 2: renderer bump frame; types 1: definition bumptex (g_disortSampler)
uniform float hasBump;
uniform sampler2D envMap;
uniform float hasEnv;
uniform sampler2D reflectMap;
uniform sampler2D refractMap;
uniform vec4 waterColor;         // g_waterColor
varying vec2 vUv1;
varying vec2 vUv2;
varying vec3 vEye;
varying vec4 vRefl;
varying vec4 vRefr;
varying vec3 vScatter;
#include <fog_pars_fragment>

vec4 envColor(vec3 r) {
  if (hasEnv < 0.5) return vec4(0.0, 0.0, 0.0, 1.0);   // unbound texture stage
  r.y = abs(r.y);
  vec2 uv = vec2(atan(r.z, r.x) / 6.2831853 + 0.5, asin(clamp(r.y, -1.0, 1.0)) / 3.14159265 + 0.5);
  return texture2D(envMap, uv);
}
float fresnelTerm(float ndv, float bias, float power) { return bias + (1.0 - bias) * pow(1.0 - max(ndv, 0.0), power); }

void main() {
#if WATER_MODE == 0
  vec4 t = hasMap > 0.5 ? texture2D(map, vUv1) : vec4(1.0);
  gl_FragColor = t * waterColor;
#elif WATER_MODE == 2
  // envWater_ps11: n = bump x 2 - 1 (tangent space) -> world through the no-wave frame (x, z, -y); reflect the eye
  vec3 nt = hasBump > 0.5 ? texture2D(bumpMap, vUv1).xyz * 2.0 - 1.0 : vec3(0.0, 0.0, 1.0);
  vec3 nFile = vec3(nt.x, nt.z, -nt.y);
  vec3 n = normalize(vec3(nFile.x, nFile.y, -nFile.z));   // FILE -> three (the worldRoot mirror)
  gl_FragColor = envColor(reflect(-normalize(vEye), n)) * waterColor;
#elif WATER_MODE == 3
  float H = normalize(vEye).y;
  vec4 refl = texture2DProj(reflectMap, vRefl);
  gl_FragColor = vec4(refl.rgb, fresnelTerm(H, 0.4, 3.5) * waterColor.a);
#else
  vec3 bump = vec3(0.0);
  if (hasBump > 0.5) bump = (texture2D(bumpMap, vUv1).xyz - 0.6) + (texture2D(bumpMap, vUv2).xyz - 0.6);
  float distortion = length(vEye) / 20.0;
  vec4 rl = vRefl; rl.xy += bump.xy * (distortion + 0.4);
  vec4 rr = vRefr; rr.xy += bump.xy * (distortion / 2.0);
  vec3 refl = texture2DProj(reflectMap, rl).rgb;
  vec3 refr = texture2DProj(refractMap, rr).rgb;
  float H = normalize(vEye).y;            // dot(normalize(eyeVec), vertex normal (0, 1, 0))
  float phase = pow((1.0 + H) / 2.0, 0.6);
  vec3 refract = vScatter * ((0.1 + refr) * phase);
  gl_FragColor = vec4(mix(refract, refl, fresnelTerm(H, 0.0204, 3.8)), 1.0);
#endif
  #include <fog_fragment>
}`;

/** Evaluate a parseWater alpha curve [(t 0..999, v)] at cycle position t; 1.0 without a curve (FUN_01545ff0). */
export function alphaAt(curve, t) {
  if (!curve || !curve.length) return 1.0;
  if (curve.length === 1) return curve[0][1];
  for (let i = 0; i < curve.length - 1; i++) {
    const [t0, v0] = curve[i], [t1, v1] = curve[i + 1];
    if (t >= t0 && t <= t1) return v0 + (v1 - v0) * ((t - t0) / Math.max(1e-6, t1 - t0));
  }
  return curve[curve.length - 1][1];
}
/** Alpha-curve index of FUN_01545ff0 at time t seconds: trunc((1 - frac(t)) x 999). */
export function alphaIndex(tSec) {
  return Math.trunc((1 - (tSec - Math.floor(tSec))) * WATER_GLOBAL.ALPHA_STEPS);
}
const frac = x => x - Math.floor(x);
/** g_f2UV of one wave at time t seconds: frac(D x speed x t x 0.1), D = (-sin a, -cos a) (FUN_015473d0). */
export function waveScroll(speed, dirRad, tSec) {
  const k = speed * tSec * WATER_GLOBAL.SCROLL_RATE;
  return [frac(-Math.sin(dirRad) * k), frac(-Math.cos(dirRad) * k)];
}
/** Diffuse frame of FUN_01545d00: (time ms / definition time) % frames; frame 0 for a missing or zero time. */
export function frameAt(tMs, frameMs, n) {
  if (!(n > 1) || !(frameMs > 0)) return 0;
  return Math.floor(tMs / frameMs) % n;
}
/** Wave slot (1 or 2) of a definition, or the constructor default (FUN_0097c8e0). */
export function waveOf(def, slot) {
  const ws = def?.waves || [];
  const w = ws.find(x => x.id === slot) || (ws.every(x => !Number.isFinite(x.id)) ? ws[slot - 1] : null);
  const D = WATER_GLOBAL.DEFAULT_WAVE;
  const f = (v, d) => (Number.isFinite(v) ? v : d);
  return w ? { speed: f(w.speed, D.speed), amplitude: f(w.amplitude, D.amplitude), wavelength: f(w.wavelength, D.wavelength), direction: f(w.direction, D.direction) } : { ...D };
}

const envCache = new Map();
/** Sky panorama for reflections (DataTexture, equirectangular), cached per key. Also the characters' specular
 *  reflection (src/engine/matfx.js via src/systems/graphics). */
export function envTexture(key) {
  if (!key) return Promise.resolve(null);
  let p = envCache.get(key);
  if (!p) {
    p = tryFetchBuffer(key).then(buf => {
      const img = buf && decodeRGBA(new Uint8Array(buf));
      if (!img) return null;
      const eq = skyStripToEquirect(img.data, img.width, img.height, { width: 512 });
      const tex = new THREE.DataTexture(eq.data, eq.width, eq.height, THREE.RGBAFormat, THREE.UnsignedByteType);
      Object.assign(tex, { flipY: false, colorSpace: THREE.NoColorSpace, wrapS: THREE.RepeatWrapping, wrapT: THREE.ClampToEdgeWrapping,
        magFilter: THREE.LinearFilter, minFilter: THREE.LinearMipmapLinearFilter, generateMipmaps: true });
      tex.needsUpdate = true;
      return tex;
    }).catch(err => {
      if (err?.transient) {
        if (envCache.get(key) === p) envCache.delete(key);
        throw err;
      }
      return null;
    });
    envCache.set(key, p);
  }
  return p;
}

let bumpPackPromise = null;
/** The renderer's animated bump set (texturepack/effect/water.tpack: texture/water/normalbump/water00..30.dds). */
function loadBumpPack(game) {
  if (!bumpPackPromise) {
    bumpPackPromise = fetchText(WATER_GLOBAL.BUMP_PACK).then(async src => {
      const tp = parseTpack(src);
      const frames = await Promise.all(tp.slots.map(s => loadTexture(game, resolveTexture(tp, s)).catch(() => null)));
      return frames.filter(Boolean);
    }).catch(() => { bumpPackPromise = null; return []; });
  }
  return bumpPackPromise;
}

/** Shader mode for a definition type (see header); a missing type is the constructor default 1. */
export function waterMode(type) {
  if (type === null || type === undefined) return waterMode(WATER_GLOBAL.DEFAULT_TYPE);
  if (type === 1) return 1;
  if (type === 2) return 2;
  if (type === 3) return 3;
  if (type === 4) return -1; // floor reflection: waterfx.js
  return 0;                  // 0, -1 and anything unknown: basic
}

// ------------------------------------------------------------------ planar reflection / refraction
const _bias = new THREE.Matrix4().set(0.5, 0, 0, 0.5, 0, 0.5, 0, 0.5, 0, 0, 0.5, 0.5, 0, 0, 0, 1);
const _v = new THREE.Vector3(), _d = new THREE.Vector3(), _u = new THREE.Vector3(), _q = new THREE.Vector4();
const _plane = new THREE.Plane(), _cp = new THREE.Vector4();

/** Mirror a camera about the horizontal plane y = h into `out` (three world; FILE y = three y). */
export function mirrorCamera(camera, h, out) {
  camera.updateMatrixWorld();
  out.position.setFromMatrixPosition(camera.matrixWorld);
  out.position.y = 2 * h - out.position.y;
  _d.set(0, 0, -1).transformDirection(camera.matrixWorld); _d.y = -_d.y;
  _u.set(0, 1, 0).transformDirection(camera.matrixWorld); _u.y = -_u.y;
  out.up.copy(_u);
  out.lookAt(_v.copy(out.position).add(_d));
  out.projectionMatrix.copy(camera.projectionMatrix);
  out.updateMatrixWorld();
  out.matrixWorldInverse.copy(out.matrixWorld).invert();
  return out;
}
/** Replace the near plane of a perspective projection by a world plane (oblique clipping). */
export function obliqueClip(cam, normal, constant) {
  _plane.set(normal, constant).applyMatrix4(cam.matrixWorldInverse);
  _cp.set(_plane.normal.x, _plane.normal.y, _plane.normal.z, _plane.constant);
  if (!(_cp.w < 0)) return false;   // eye on the kept side: the plane cannot be the near plane, keep the projection
  const e = cam.projectionMatrix.elements;
  _q.set((Math.sign(_cp.x) + e[8]) / e[0], (Math.sign(_cp.y) + e[9]) / e[5], -1, (1 + e[10]) / e[14]);
  _cp.multiplyScalar(2 / _cp.dot(_q));
  e[2] = _cp.x; e[6] = _cp.y; e[10] = _cp.z + 1; e[14] = _cp.w;
  cam.projectionMatrixInverse.copy(cam.projectionMatrix).invert();
  return true;
}

// PERF-PLANESIDE (2026-10-30): a capture clips at the water plane exactly (obliqueClip: near plane = the plane), so a terrain chunk
// or decal whose world box lies wholly on the clipped side cannot put a pixel in that target. Those are hidden for that one
// capture (restored in _prepass's finally). Margin PLANESIDE_EPS keeps anything touching the plane. Kill switch:
// globalThis.__dekaronNoPlaneSide = true. Ardeca: ~58 of ~60 plain-mesh draws of the refraction capture.
const PLANESIDE_EPS = 0.05;
const _psBox = new THREE.Box3();
function hidePlaneSide(group, h, keepAbove, out) {
  if (!group || globalThis.__dekaronNoPlaneSide === true) return;
  const kids = group.children;
  for (let i = 0; i < kids.length; i++) {
    const o = kids[i];
    if (!o.visible || !o.isMesh || o.isSkinnedMesh || o.isInstancedMesh || !o.geometry) continue;
    const geo = o.geometry;
    if (!geo.boundingBox) geo.computeBoundingBox();
    _psBox.copy(geo.boundingBox).applyMatrix4(o.matrixWorld);
    if (keepAbove ? _psBox.max.y < h - PLANESIDE_EPS : _psBox.min.y > h + PLANESIDE_EPS) { o.visible = false; out.push(o); }
  }
}

// PERF-CAPTURELITE (2026-10-30): the reflection / refraction captures draw a reduced set and are refreshed every 2nd frame.
//  - reduced set: worldRoot children other than the world group and player characters (NPCs, monsters, pets, effects, weapon
//    traces, water fx) are hidden for the capture (restored in _prepass's finally). Terrain, sky, map objects and players stay.
//  - refresh: a capture is reused for one frame (its reflect/refract matrices stay paired with the texture, so it stays registered
//    to the world) unless the camera moved more than CAPTURE_MOVE / turned more than CAPTURE_TURN since the capture, or the
//    viewport camera changed. Kill switches: globalThis.__dekaronNoCaptureLite = true (full set), __dekaronCaptureEvery = 1.
const CAPTURE_MOVE = 0.35, CAPTURE_TURN = 0.035;   // world units / radians (about 2 deg)
const _capQ = new THREE.Quaternion(), _capP = new THREE.Vector3();
function hideCaptureActors(root, keepGroup, out) {
  if (!root || globalThis.__dekaronNoCaptureLite === true) return;
  const kids = root.children;
  for (let i = 0; i < kids.length; i++) {
    const o = kids[i];
    if (!o.visible || o === keepGroup || (typeof o.name === 'string' && o.name.startsWith('player:'))) continue;
    o.visible = false; out.push(o);
  }
}

class WaterPlane {
  constructor(height, refract) {
    this.height = height;
    this.refract = refract;
    this.reflectRT = null; this.refractRT = null;
    this.reflectMatrix = new THREE.Matrix4();
    this.refractMatrix = new THREE.Matrix4();
    this.cam = new THREE.PerspectiveCamera();
    this.cam.userData.dkCaptureCull = true;   // PERF-CAPTURECULL: objects.js culls the static groups / rig sets to this camera's frustum
    this.mats = [];
    this.token = null;
    this.capCam = null; this.capTick = -1; this.capPos = new THREE.Vector3(); this.capQuat = new THREE.Quaternion(); this.capFov = 0; this.capAspect = 0;
  }
  ensure() {
    if (this.reflectRT) return;
    const S = WATER_GLOBAL.RT_SIZE, opt = { type: THREE.UnsignedByteType, depthBuffer: true };
    this.reflectRT = new THREE.WebGLRenderTarget(S, S, opt);
    this.reflectRT.texture.name = 'water reflection';
    if (this.refract) { this.refractRT = new THREE.WebGLRenderTarget(S, S, opt); this.refractRT.texture.name = 'water refraction'; }
    for (const m of this.mats) {
      m.uniforms.reflectMap.value = this.reflectRT.texture;
      if (this.refractRT) m.uniforms.refractMap.value = this.refractRT.texture;
    }
  }
  dispose() { this.reflectRT?.dispose(); this.refractRT?.dispose(); this.reflectRT = this.refractRT = null; }
}

export class WaterLayer {
  /**
   * @param {{map:object, game?:object, root:THREE.Object3D, envMapKey?:string, reflectHeight?:number}} opts
   *   reflectHeight = maplist Reflect_Height (environment.js mapEnvironmentInfo); -1000 / missing = none
   */
  constructor({ map, game = null, root, envMapKey = '', reflectHeight = null }) {
    this.map = map;
    this.game = game;
    this.envMapKey = envMapKey;
    this.reflectHeight = Number.isFinite(reflectHeight) && reflectHeight > WATER_GLOBAL.NO_REFLECT_HEIGHT ? reflectHeight : null;
    this.group = new THREE.Group();
    this.group.name = 'water';
    root.add(this.group);
    this.meshes = [];     // {meshes:[Mesh], minX, maxX, minZ, maxZ}
    this.materials = [];  // {mats:[ShaderMaterial], def, frames, bumpFrames, shared, frameMs, mode}
    this.geometries = [];
    this.planes = new Map();  // plane height -> WaterPlane
    this.time = 0;
    this._tick = 0;
    this._inPrepass = false;
    this.stats = { entries: 0, cells: 0, meshes: 0, modes: [], planes: 0 };
    this.entryTypes = [];  // definition type per map.water entry (null until parsed / unreadable)
  }

  _plane(height, refract) {
    let p = this.planes.get(height);
    if (!p) { p = new WaterPlane(height, refract); this.planes.set(height, p); this.stats.planes++; }
    if (refract) p.refract = true;
    return p;
  }

  async build() {
    const map = this.map;
    if (!map.water.length) return;
    const env = await envTexture(this.envMapKey);
    this._env = env;
    const W = map.width, H = map.height;
    for (let ei = 0; ei < map.water.length; ei++) {
      const entry = map.water[ei];
      let def;
      try { def = parseWater(await fetchText(entry.defPath)); } catch { this.entryTypes[ei] = null; continue; }   // never loads
      const type = Number.isFinite(def.type) ? def.type : WATER_GLOBAL.DEFAULT_TYPE;
      this.entryTypes[ei] = type;
      const mode = waterMode(type);
      if (mode < 0) continue;
      const frameKeys = (def.textures || []).map(t => t.path).filter(Boolean);
      const frames = mode === 0 ? (await Promise.all(frameKeys.map(k => loadTexture(this.game, [k, k.replace(/\.[^./]+$/, '.dds')])))).filter(Boolean) : [];
      const bumpFrames = mode === 2 ? await loadBumpPack(this.game) : [];
      const disort = mode === 1 && def.bumptex ? await loadTexture(this.game, [def.bumptex]) : null;
      const w1 = waveOf(def, 1), w2 = waveOf(def, 2);
      const wave = (w) => new THREE.Vector4(w.speed, w.amplitude, (2 * Math.PI) / w.wavelength, (w.direction * Math.PI) / 180);
      const att = Array.isArray(def.attenuation) && def.attenuation.length >= 3 ? def.attenuation.slice(0, 3) : DEFAULT_ATTENUATION;
      const alpha0 = mode === 0 ? alphaAt(def.alpha, alphaIndex(0)) : WATER_GLOBAL.PLANAR_ALPHA;
      const shared = { time: { value: 0 }, wave1: { value: wave(w1) }, wave2: { value: wave(w2) }, scroll: { value: new THREE.Vector4() } };
      let plane = null;
      if (mode === 1 || mode === 3) {
        const h = this.reflectHeight ?? (entry.cellHeights?.length ? entry.cellHeights[0] : 0);
        plane = this._plane(h, mode === 1);
      }
      const uniforms = THREE.UniformsUtils.merge([THREE.UniformsLib.fog, {
        map: { value: null }, hasMap: { value: frames.length ? 1 : 0 },
        bumpMap: { value: null }, hasBump: { value: (mode === 2 ? bumpFrames.length : disort ? 1 : 0) ? 1 : 0 },
        envMap: { value: null }, hasEnv: { value: env ? 1 : 0 },
        reflectMap: { value: null }, refractMap: { value: null },
        waterColor: { value: new THREE.Vector4(1, 1, 1, alpha0) },
        attenuation: { value: new THREE.Vector3(...att) },
      }]);
      Object.assign(uniforms, shared);
      uniforms.reflectMatrix = { value: plane ? plane.reflectMatrix : new THREE.Matrix4() };
      uniforms.refractMatrix = { value: plane ? plane.refractMatrix : new THREE.Matrix4() };
      uniforms.map.value = frames[0] || null;
      uniforms.bumpMap.value = mode === 2 ? (bumpFrames[0] || null) : disort;
      uniforms.envMap.value = env;
      const mat = new THREE.ShaderMaterial({
        vertexShader: WATER_VERTEX, fragmentShader: WATER_FRAGMENT, uniforms, fog: true,
        defines: { WATER_MODE: mode, WATER_WAVE: mode === 3 ? 0 : 1 }, side: THREE.FrontSide, depthWrite: false, transparent: true,
      });
      mat.name = `water ${entry.name}`;
      if (plane) { plane.mats.push(mat); if (plane.reflectRT) plane.ensure(); }
      const mats = [mat];
      this.materials.push({ mats, def, frames, bumpFrames, disort, shared, frameMs: Number(def.time) || 0, mode, plane });
      this.stats.entries++;
      this.stats.modes.push(`${entry.name}:${type}`);

      // unique cells -> regions
      const seen = new Set(), regions = new Map();
      for (let j = 0; j < entry.cells.length; j++) {
        const cell = entry.cells[j];
        if (cell >= W * H || seen.has(cell)) continue;
        seen.add(cell);
        const col = cell % W, row = Math.floor(cell / W);
        const key = Math.floor(row / REGION) * 64 + Math.floor(col / REGION);
        let list = regions.get(key);
        if (!list) regions.set(key, (list = []));
        list.push(col, row, entry.cellHeights[j]);
      }
      this.stats.cells += seen.size;
      for (const list of regions.values()) {
        const n = list.length / 3;
        const pos = new Float32Array(n * 12), depth = new Float32Array(n * 4);
        const idx = n * 4 > 65535 ? new Uint32Array(n * 6) : new Uint16Array(n * 6);
        let minX = Infinity, maxX = -Infinity, minZ = Infinity, maxZ = -Infinity;
        for (let q = 0; q < n; q++) {
          const c0 = list[q * 3], r0 = list[q * 3 + 1], h = list[q * 3 + 2];
          const corners = [c0, r0, c0 + 1, r0, c0, r0 + 1, c0 + 1, r0 + 1];
          for (let t = 0; t < 4; t++) {
            const x = corners[t * 2], z = corners[t * 2 + 1], o = (q * 4 + t);
            pos[o * 3] = x; pos[o * 3 + 1] = h; pos[o * 3 + 2] = z;
            depth[o] = h - sampleHeight(map, x, z);
          }
          const a = q * 4; // a=(c,r) b=(c+1,r) c=(c,r+1) d=(c+1,r+1); D3D winding (a,d,b),(a,c,d)
          idx[q * 6] = a; idx[q * 6 + 1] = a + 3; idx[q * 6 + 2] = a + 1;
          idx[q * 6 + 3] = a; idx[q * 6 + 4] = a + 2; idx[q * 6 + 5] = a + 3;
          if (c0 < minX) minX = c0; if (c0 + 1 > maxX) maxX = c0 + 1;
          if (r0 < minZ) minZ = r0; if (r0 + 1 > maxZ) maxZ = r0 + 1;
        }
        const g = new THREE.BufferGeometry();
        g.setAttribute('position', new THREE.BufferAttribute(pos, 3));
        g.setAttribute('depth', new THREE.BufferAttribute(depth, 1));
        g.setIndex(new THREE.BufferAttribute(idx, 1));
        g.computeBoundingBox();
        // waves move the surface by up to the summed amplitudes
        const amp = Math.abs(w1.amplitude || 0) + Math.abs(w2.amplitude || 0);
        g.boundingBox.min.y -= amp; g.boundingBox.max.y += amp;
        g.boundingSphere = g.boundingBox.getBoundingSphere(new THREE.Sphere());
        this.geometries.push(g);
        const ms = mats.map((m) => {
          const mesh = new THREE.Mesh(g, m);
          mesh.name = m.name;
          mesh.renderOrder = 5;
          mesh.matrixAutoUpdate = false;
          if (plane) mesh.onBeforeRender = (renderer, scene, camera) => this._prepass(renderer, scene, camera, plane);
          this.group.add(mesh);
          this.stats.meshes++;
          return mesh;
        });
        this.meshes.push({ meshes: ms, minX, maxX, minZ, maxZ });
      }
    }
  }

  /**
   * Planar reflection (types 1, 3) and refraction (type 1) targets of one plane, once per frame and camera, before the
   * first visible water mesh of that plane draws. The water itself is hidden during the capture (no recursion), the
   * capture cameras are private (not game.camera), and every renderer state touched is restored in finally.
   */
  _prepass(renderer, scene, camera, plane) {
    if (this._inPrepass || !camera?.isPerspectiveCamera || !renderer?.setRenderTarget) return;
    const token = `${this._tick}:${camera.uuid}`;
    if (plane.token === token) return;
    plane.token = token;
    // PERF-CAPTURELITE: reuse last frame's capture when the view barely changed (see CAPTURE_MOVE)
    const every = Number.isFinite(globalThis.__dekaronCaptureEvery) ? globalThis.__dekaronCaptureEvery : 2;
    camera.updateMatrixWorld();
    _capP.setFromMatrixPosition(camera.matrixWorld); _capQ.setFromRotationMatrix(camera.matrixWorld);
    if (every > 1 && plane.reflectRT && plane.capCam === camera.uuid && this._tick - plane.capTick < every && plane.capTick < this._tick &&
        plane.capPos.distanceTo(_capP) <= CAPTURE_MOVE && plane.capQuat.angleTo(_capQ) <= CAPTURE_TURN &&
        plane.capFov === camera.fov && plane.capAspect === camera.aspect) return;
    plane.capCam = camera.uuid; plane.capTick = this._tick; plane.capPos.copy(_capP); plane.capQuat.copy(_capQ);
    plane.capFov = camera.fov; plane.capAspect = camera.aspect;
    plane.ensure();
    const prevRT = renderer.getRenderTarget(), prevXr = renderer.xr?.enabled, prevShadow = renderer.shadowMap?.autoUpdate;
    const prevVis = this.group.visible;
    // PERF-CAPTURECULL: the scene's world matrices were updated by the render this capture runs inside (same frame, same poses); the
    // captures skip the second and third whole-scene matrix walk. Kill switch: globalThis.__dekaronNoCaptureCull = true.
    const prevAuto = scene.matrixWorldAutoUpdate;
    const hidden = this._psHidden || (this._psHidden = []), ground = this.game?.world?.terrain?.group || null;
    const actorsHidden = this._acHidden || (this._acHidden = []);
    this._inPrepass = true;
    try {
      if (globalThis.__dekaronNoCaptureCull !== true) scene.matrixWorldAutoUpdate = false;
      if (renderer.xr) renderer.xr.enabled = false;
      if (renderer.shadowMap) renderer.shadowMap.autoUpdate = false;
      this.group.visible = false;
      hideCaptureActors(this.game?.worldRoot, this.game?.world?.root, actorsHidden);
      const cam = plane.cam;
      cam.layers.mask = camera.layers.mask;
      cam.near = camera.near; cam.far = camera.far;
      // reflection: camera mirrored about y = h, keep what is above the plane
      mirrorCamera(camera, plane.height, cam);
      obliqueClip(cam, _v.set(0, 1, 0), -plane.height);
      plane.reflectMatrix.copy(_bias).multiply(cam.projectionMatrix).multiply(cam.matrixWorldInverse);
      hidePlaneSide(ground, plane.height, true, hidden);
      renderer.setRenderTarget(plane.reflectRT);
      if (renderer.autoClear === false) renderer.clear();
      renderer.render(scene, cam);
      if (plane.refractRT) {
        // refraction: the same camera, keep what is below the plane
        camera.updateMatrixWorld();
        cam.position.setFromMatrixPosition(camera.matrixWorld);
        cam.quaternion.setFromRotationMatrix(camera.matrixWorld);
        cam.up.set(0, 1, 0);
        cam.projectionMatrix.copy(camera.projectionMatrix);
        cam.updateMatrixWorld();
        cam.matrixWorldInverse.copy(cam.matrixWorld).invert();
        obliqueClip(cam, _v.set(0, -1, 0), plane.height);
        plane.refractMatrix.copy(_bias).multiply(cam.projectionMatrix).multiply(cam.matrixWorldInverse);
        for (const o of hidden) o.visible = true;
        hidden.length = 0;
        hidePlaneSide(ground, plane.height, false, hidden);
        renderer.setRenderTarget(plane.refractRT);
        if (renderer.autoClear === false) renderer.clear();
        renderer.render(scene, cam);
      }
    } finally {
      renderer.setRenderTarget(prevRT);
      if (renderer.xr) renderer.xr.enabled = prevXr;
      if (renderer.shadowMap) renderer.shadowMap.autoUpdate = prevShadow;
      scene.matrixWorldAutoUpdate = prevAuto;
      for (const o of hidden) o.visible = true;
      hidden.length = 0;
      for (const o of actorsHidden) o.visible = true;
      actorsHidden.length = 0;
      this.group.visible = prevVis;
      this._inPrepass = false;
    }
  }

  /** Water level at a FILE point (or null). */
  levelAt(x, z) {
    const m = this.map;
    const col = Math.floor(x), row = Math.floor(z);
    if (col < 0 || row < 0 || col >= m.width || row >= m.height) return null;
    if (!m._waterIdx) {
      const idx = new Map();
      for (const w of m.water) for (let j = 0; j < w.cells.length; j++) if (!idx.has(w.cells[j])) idx.set(w.cells[j], w.cellHeights[j]);
      Object.defineProperty(m, '_waterIdx', { value: idx, enumerable: false });
    }
    const h = m._waterIdx.get(row * m.width + col);
    return h === undefined ? null : h;
  }

  /** Definition type of the first water entry covering a FILE cell (Global's eye-cell lookup), or null. */
  typeAt(x, z) {
    const m = this.map;
    const col = Math.floor(x), row = Math.floor(z);
    if (col < 0 || row < 0 || col >= m.width || row >= m.height) return null;
    if (!m._waterEntryIdx) {
      const idx = new Map();
      m.water.forEach((w, ei) => { for (let j = 0; j < w.cells.length; j++) if (!idx.has(w.cells[j])) idx.set(w.cells[j], ei); });
      Object.defineProperty(m, '_waterEntryIdx', { value: idx, enumerable: false });
    }
    const ei = m._waterEntryIdx.get(row * m.width + col);
    if (ei === undefined) return null;
    const t = this.entryTypes[ei];
    return t === undefined ? null : t;
  }

  update(dt, camX, camZ, viewDist) {
    this.time += dt;
    this._tick++;
    const t = this.time, tMs = t * 1000;
    for (const m of this.materials) {
      const s = m.shared;
      s.time.value = t;
      const w1 = s.wave1.value, w2 = s.wave2.value;
      const a = waveScroll(w1.x, w1.w, t), b = waveScroll(w2.x, w2.w, t);
      s.scroll.value.set(a[0], a[1], b[0], b[1]);
      for (const mat of m.mats) {
        const u = mat.uniforms;
        if (m.mode === 0) {
          u.waterColor.value.w = alphaAt(m.def.alpha, alphaIndex(t));
          if (m.frames.length > 1) u.map.value = m.frames[frameAt(tMs, m.frameMs, m.frames.length)];
        } else if (m.mode === 2 && m.bumpFrames.length > 1) {
          u.bumpMap.value = m.bumpFrames[frameAt(tMs, WATER_GLOBAL.BUMP_FRAME_MS, m.bumpFrames.length)];
        }
      }
    }
    const v2 = viewDist * viewDist;
    for (const c of this.meshes) {
      const dx = camX < c.minX ? c.minX - camX : camX > c.maxX ? camX - c.maxX : 0;
      const dz = camZ < c.minZ ? c.minZ - camZ : camZ > c.maxZ ? camZ - c.maxZ : 0;
      const vis = dx * dx + dz * dz <= v2;
      for (const m of c.meshes) m.visible = vis;
    }
  }

  dispose() {
    for (const g of this.geometries) g.dispose();
    for (const m of this.materials) {
      for (const mat of m.mats) mat.dispose();
      // cached textures: free the GPU copies only (re-uploaded on reuse)
      for (const t of m.frames) t.dispose();
      for (const t of m.bumpFrames || []) t.dispose();
      m.disort?.dispose();
    }
    for (const p of this.planes.values()) p.dispose();
    this.planes.clear();
    this._env?.dispose();
    this.group.removeFromParent();
    this.meshes = []; this.materials = []; this.geometries = [];
  }
}
