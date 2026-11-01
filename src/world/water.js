// Water surfaces of a .map (map.md "Water"): one quad per water cell at its surface level, grouped in 64x64-cell
// regions for culling, one material per water definition (property/effect/water/*.txt, environment.js parseWater).
//
// The look follows the client's own shader, data/binary/water.fx (techniques by definition `type`):
//   type 0 / -1  "Water/WaterWave"  fixed function: texture x waterColor (ARGB), alpha = texture alpha x alpha curve
//   type 2       "WaterEnvWave"     ps.1.1 texm3x3vspec: environment reflection (bump-perturbed normal) x waterColor
//   type 1       "WaterRefWave"     psWaterRef: lerp(refraction x exp(-depth x attenuation) x phase, reflection,
//                                  fresnel(0.0204, 3.8)); opaque, waterColor unused
//   type 3       "WaterReflect"     psReflect: reflection, alpha = fresnel(0.4, 3.5) x waterColor.a
//   type 4       "FloorReflect"     a 0.2-alpha planar reflection of the scene on shiny floors: not drawn (see below)
// Waves are the vertex displacement of water.fx MakeWave: y += A sin(2pi/L (D.xz - s t)), normal from the derivative.
//
// Deviations (documented): the game's planar reflection / refraction render targets are not reproduced. Reflection
// samples the map's EnvironmentMap panorama (texture/water/skycube*.dds -> skyStripToEquirect, ENGINE_NOTES .mol
// note 8); type 1 refraction is done exactly with blending instead of a render target: a multiply pass
// (dst *= (1-F) T phase) plus an additive pass (+ F refl + (1-F) 0.1 T phase), where T = exp(-pathLength x
// attenuation) uses the per-vertex water depth (level - terrain) - so shallow shores stay clear and deep water darkens,
// as in psWaterRef. Type 4 floors are skipped (a reflection of the sky on indoor floors would be wrong).
//
// FILE frame under worldRoot: (x = col, y = level, z = row), D3D winding (see terrain.js). Colours are raw 0..1.
import * as THREE from 'three';
import { parseWater, skyStripToEquirect } from '../formats/environment.js';
import { sampleHeight } from '../formats/map.js';
import { fetchText, tryFetchBuffer } from '../engine/assets.js';
import { decodeRGBA, loadTexture } from './texload.js';

const REGION = 64;
const TEX_CELLS = 8;            // one water texture repeat per 8 cells (the game's water UV scale is not in the data)
const DEFAULT_ATTENUATION = [0.06, 0.04, 0.03]; // water03 declares none; mild clear water

const WATER_VERTEX = /* glsl */`
attribute float depth;          // water level - terrain height at this vertex (FILE frame)
uniform float time;
uniform vec4 wave1;             // speed, amplitude, 2pi/wavelength, direction (rad)
uniform vec4 wave2;
varying vec2 vCell;
varying vec3 vWorld;
varying vec3 vNormalW;
varying float vDepth;
#include <fog_pars_vertex>
void main() {
  vec3 p = position;
  vec2 d1 = vec2(cos(wave1.w), sin(wave1.w));
  vec2 d2 = vec2(cos(wave2.w), sin(wave2.w));
  float t1 = wave1.z * (dot(d1, p.xz) - wave1.x * time);
  float t2 = wave2.z * (dot(d2, p.xz) - wave2.x * time);
  p.y += wave1.y * sin(t1) + wave2.y * sin(t2);
  vec2 g = d1 * (wave1.y * wave1.z * cos(t1)) + d2 * (wave2.y * wave2.z * cos(t2));
  vec3 nFile = normalize(vec3(-g.x, 1.0, -g.y));
  vNormalW = normalize(vec3(nFile.x, nFile.y, -nFile.z));   // FILE -> three (the worldRoot mirror)
  vCell = position.xz;
  vDepth = max(depth, 0.0);
  vec4 wp = modelMatrix * vec4(p, 1.0);
  vWorld = wp.xyz;
  vec4 mvPosition = viewMatrix * wp;
  gl_Position = projectionMatrix * mvPosition;
  #include <fog_vertex>
}`;

const WATER_FRAGMENT = /* glsl */`
uniform sampler2D map;
uniform float hasMap;
uniform sampler2D bumpMap;
uniform float hasBump;
uniform sampler2D envMap;
uniform float hasEnv;
uniform vec4 waterColor;         // ARGB of the definition as (r,g,b,a)
uniform float opacity;           // alpha curve value
uniform float time;
uniform vec3 attenuation;
uniform vec3 fallbackSky;
uniform vec4 scroll;             // uv1 offset (xy), uv2 offset (zw)
varying vec2 vCell;
varying vec3 vWorld;
varying vec3 vNormalW;
varying float vDepth;
#include <fog_pars_fragment>

vec3 envColor(vec3 r) {
  if (hasEnv < 0.5) return fallbackSky;
  r.y = abs(r.y);
  vec2 uv = vec2(atan(r.z, r.x) / 6.2831853 + 0.5, asin(clamp(r.y, -1.0, 1.0)) / 3.14159265 + 0.5);
  return texture2D(envMap, uv).rgb;
}
vec3 bumpedNormal(float strength) {
  vec3 n = vNormalW;
  if (hasBump > 0.5) {
    vec2 b = texture2D(bumpMap, vCell / ${TEX_CELLS.toFixed(1)} + scroll.xy).xy - 0.6;
    b += texture2D(bumpMap, vCell / ${(TEX_CELLS * 0.77).toFixed(2)} + scroll.zw).xy - 0.6;
    n = normalize(n + vec3(b.x, 0.0, -b.y) * strength);   // FILE (x, z) -> three (x, -z)
  }
  return n;
}
float fresnelTerm(float ndv, float bias, float power) { return bias + (1.0 - bias) * pow(1.0 - max(ndv, 0.0), power); }

void main() {
  vec3 v = normalize(cameraPosition - vWorld);
#if WATER_MODE == 0
  // basic: texture x waterColor, alpha = texture alpha x curve (two scrolled layers of the same texture)
  vec4 t = vec4(1.0);
  if (hasMap > 0.5) {
    t = 0.5 * (texture2D(map, vCell / ${TEX_CELLS.toFixed(1)} + scroll.xy) + texture2D(map, vCell / ${(TEX_CELLS * 1.3).toFixed(1)} + scroll.zw));
  }
  gl_FragColor = vec4(t.rgb * waterColor.rgb, t.a * opacity);
  #include <fog_fragment>
#elif WATER_MODE == 2
  // environment reflection x waterColor
  vec3 n = bumpedNormal(0.35);
  vec3 refl = envColor(reflect(-v, n));
  gl_FragColor = vec4(refl * waterColor.rgb, opacity);
  #include <fog_fragment>
#elif WATER_MODE == 3
  // reflection only, fresnel alpha
  vec3 n = bumpedNormal(0.2);
  float F = fresnelTerm(dot(n, v), 0.4, 3.5);
  gl_FragColor = vec4(envColor(reflect(-v, n)), F * waterColor.a);
  #include <fog_fragment>
#else
  // psWaterRef, split into a multiply pass (WATER_PASS 0) and an additive pass (WATER_PASS 1)
  vec3 n = bumpedNormal(0.25);
  float H = dot(v, n);
  float phase = pow((1.0 + H) * 0.5, 0.6);
  float F = fresnelTerm(H, 0.0204, 3.8);
  float path = vDepth / max(v.y, 0.15);            // underwater path length of the view ray
  vec3 T = exp(-path * attenuation);
  float fogF = 0.0;
  #ifdef USE_FOG
    fogF = clamp((vFogDepth - fogNear) / max(fogFar - fogNear, 1e-4), 0.0, 1.0);   // linear range fog (fog-model.js)
  #endif
  #if WATER_PASS == 0
    gl_FragColor = vec4(mix((1.0 - F) * T * phase, vec3(1.0), fogF), 1.0);
  #else
    vec3 add = F * envColor(reflect(-v, n)) + (1.0 - F) * 0.1 * T * phase;
    gl_FragColor = vec4(add * (1.0 - fogF), 1.0);
  #endif
#endif
}`;

/** Evaluate a parseWater alpha curve [(t 0..999, v)] at cycle position t. */
function alphaAt(curve, t) {
  if (!curve || !curve.length) return 0.6;
  if (curve.length === 1) return curve[0][1];
  for (let i = 0; i < curve.length - 1; i++) {
    const [t0, v0] = curve[i], [t1, v1] = curve[i + 1];
    if (t >= t0 && t <= t1) return v0 + (v1 - v0) * ((t - t0) / Math.max(1e-6, t1 - t0));
  }
  return curve[curve.length - 1][1];
}

const envCache = new Map();
/** Sky panorama for reflections (DataTexture, equirectangular), cached per key. Also the characters' specular
 *  reflection (src/engine/matfx.js via src/systems/graphics). */
export function envTexture(key) {
  if (!key) return Promise.resolve(null);
  if (!envCache.has(key)) {
    envCache.set(key, tryFetchBuffer(key).then(buf => {
      const img = buf && decodeRGBA(new Uint8Array(buf));
      if (!img) return null;
      const eq = skyStripToEquirect(img.data, img.width, img.height, { width: 512 });
      const tex = new THREE.DataTexture(eq.data, eq.width, eq.height, THREE.RGBAFormat, THREE.UnsignedByteType);
      Object.assign(tex, { flipY: false, colorSpace: THREE.NoColorSpace, wrapS: THREE.RepeatWrapping, wrapT: THREE.ClampToEdgeWrapping,
        magFilter: THREE.LinearFilter, minFilter: THREE.LinearMipmapLinearFilter, generateMipmaps: true });
      tex.needsUpdate = true;
      return tex;
    }).catch(() => null));
  }
  return envCache.get(key);
}

/** Shader mode for a definition type (see header). */
export function waterMode(type) {
  if (type === 1) return 1;
  if (type === 2) return 2;
  if (type === 3) return 3;
  if (type === 4) return -1; // floor reflection: skipped
  return 0;                  // 0, -1 and anything unknown: basic
}

export class WaterLayer {
  /**
   * @param {{map:object, game?:object, root:THREE.Object3D, envMapKey?:string}} opts
   */
  constructor({ map, game = null, root, envMapKey = '' }) {
    this.map = map;
    this.game = game;
    this.envMapKey = envMapKey;
    this.group = new THREE.Group();
    this.group.name = 'water';
    root.add(this.group);
    this.meshes = [];     // {meshes:[Mesh], minX, maxX, minZ, maxZ}
    this.materials = [];  // {mats:[ShaderMaterial], def, frames, cycleMs}
    this.geometries = [];
    this.time = 0;
    this.stats = { entries: 0, cells: 0, meshes: 0, modes: [] };
  }

  async build() {
    const map = this.map;
    if (!map.water.length) return;
    const env = await envTexture(this.envMapKey);
    this._env = env;
    const W = map.width, H = map.height;
    for (const entry of map.water) {
      let def;
      try { def = parseWater(await fetchText(entry.defPath)); } catch { def = { textures: [], type: 2, waves: [], color: null, alpha: [[0, 0.6]] }; }
      const mode = waterMode(def.type);
      if (mode < 0) continue;
      const frameKeys = (def.textures || []).map(t => t.path).filter(Boolean);
      const frames = mode === 0 ? (await Promise.all(frameKeys.map(k => loadTexture(this.game, [k, k.replace(/\.[^./]+$/, '.dds')])))).filter(Boolean) : [];
      const bump = def.bumptex ? await loadTexture(this.game, [def.bumptex]) : null;
      const c = def.color || { r: 1, g: 1, b: 1, a: 1 };
      const w1 = def.waves[0] || { speed: 0.4, amplitude: 0.05, wavelength: 3, direction: 60 };
      const w2 = def.waves[1] || w1;
      const wave = (w) => new THREE.Vector4(w.speed, w.amplitude, (2 * Math.PI) / Math.max(0.05, w.wavelength), (w.direction * Math.PI) / 180);
      const att = Array.isArray(def.attenuation) && def.attenuation.length >= 3 ? def.attenuation.slice(0, 3) : DEFAULT_ATTENUATION;
      const shared = {
        time: { value: 0 }, wave1: { value: wave(w1) }, wave2: { value: wave(w2) },
        scroll: { value: new THREE.Vector4() },
      };
      const makeMat = (pass) => {
        const uniforms = THREE.UniformsUtils.merge([THREE.UniformsLib.fog, {
          map: { value: null }, hasMap: { value: frames.length ? 1 : 0 },
          bumpMap: { value: null }, hasBump: { value: bump ? 1 : 0 },
          envMap: { value: null }, hasEnv: { value: env ? 1 : 0 },
          waterColor: { value: new THREE.Vector4(c.r, c.g, c.b, c.a) },
          opacity: { value: alphaAt(def.alpha, 0) },
          attenuation: { value: new THREE.Vector3(...att) },
          fallbackSky: { value: new THREE.Color(0.45, 0.55, 0.7) },
        }]);
        Object.assign(uniforms, shared);   // shared objects: one update per definition drives every pass
        uniforms.map.value = frames[0] || null;
        uniforms.bumpMap.value = bump;
        uniforms.envMap.value = env;
        const mat = new THREE.ShaderMaterial({
          vertexShader: WATER_VERTEX, fragmentShader: WATER_FRAGMENT, uniforms, fog: true,
          defines: { WATER_MODE: mode, WATER_PASS: pass }, side: THREE.FrontSide, depthWrite: false, transparent: true,
        });
        if (mode === 1) {
          mat.blending = THREE.CustomBlending;
          mat.blendEquation = THREE.AddEquation;
          if (pass === 0) { mat.blendSrc = THREE.ZeroFactor; mat.blendDst = THREE.SrcColorFactor; }   // dst *= src
          else { mat.blendSrc = THREE.OneFactor; mat.blendDst = THREE.OneFactor; }                     // dst += src
        }
        mat.name = `water ${entry.name}${mode === 1 ? ` pass${pass}` : ''}`;
        return mat;
      };
      const mats = mode === 1 ? [makeMat(0), makeMat(1)] : [makeMat(0)];
      this.materials.push({ mats, def, frames, shared, frameMs: Math.max(30, Number(def.time) || 250) });
      this.stats.entries++;
      this.stats.modes.push(`${entry.name}:${def.type}`);

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
        const ms = mats.map((mat, pass) => {
          const mesh = new THREE.Mesh(g, mat);
          mesh.name = mat.name;
          mesh.renderOrder = 5 + pass;
          mesh.matrixAutoUpdate = false;
          this.group.add(mesh);
          this.stats.meshes++;
          return mesh;
        });
        this.meshes.push({ meshes: ms, minX, maxX, minZ, maxZ });
      }
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

  update(dt, camX, camZ, viewDist) {
    this.time += dt;
    const t = this.time;
    for (const m of this.materials) {
      const s = m.shared;
      s.time.value = t;
      // two slow scrolls along the wave directions (the engine's g_f2UV / g_f2UV2 offsets)
      const w1 = s.wave1.value, w2 = s.wave2.value;
      s.scroll.value.set(
        (Math.cos(w1.w) * w1.x * t * 0.05) % 1, (Math.sin(w1.w) * w1.x * t * 0.05) % 1,
        (Math.cos(w2.w) * w2.x * t * 0.04) % 1, (Math.sin(w2.w) * w2.x * t * 0.04) % 1);
      // alpha curve over a 0..999 cycle (cycle length = 16 frames of `time`; the unit is not documented)
      const cycle = m.frameMs * 16;
      const a = alphaAt(m.def.alpha, ((t * 1000) % cycle) / cycle * 999);
      for (const mat of m.mats) {
        mat.uniforms.opacity.value = a;
        if (m.frames.length > 1) mat.uniforms.map.value = m.frames[Math.floor((t * 1000) / m.frameMs) % m.frames.length];
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
      m.mats[0]?.uniforms.bumpMap.value?.dispose();
    }
    this._env?.dispose();
    this.group.removeFromParent();
    this.meshes = []; this.materials = []; this.geometries = [];
  }
}
