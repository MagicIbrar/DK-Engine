// Aura glow of glowing gear: the client's glow buffer (binary/glow.fx) blurred and added onto the screen (binary/blurglow.fx).
// See src/config/engine-chosen-aura.js for what is data and what is fitted.
//
//   1. SOURCE   every registered overlay mesh (a gem-coloured weapon wash, a refinement shell) is drawn flat into a 1/SCALE size
//               half-float target: rgb = hue x amount x glowColor (0.4), alpha = view-space distance of the nearest source
//               (opaque, depth tested, so overlapping shells are one silhouette);
//   2. BLUR     the bloomeffect.fx kernel, horizontal then vertical, PASSES times; the alpha channel is dilated with the same
//               footprint (minimum distance of the taps) so the halo carries the depth of the source it spills from;
//   3. ADD      a full-screen quad adds the blurred rgb onto the frame, ONE / ONE, with gl_FragDepth = that source distance, so the
//               frame's real depth buffer hides the aura behind anything nearer than its source (walls, terrain, bodies).
// Cost: nothing when no source is on screen; otherwise one cheap draw of a few meshes, 2 x PASSES small blurs, one quad.
import * as THREE from 'three';
import { FullScreenQuad } from 'three/addons/postprocessing/Pass.js';
import { GLOW_COLOR } from '../../engine/material-constants.js';
import { AURA } from '../../config/engine-chosen-aura.js';
import { captureBakeRenderer, restoreBakeRenderer } from '../items/bake-slices.js';

export const GLOW_LAYER = 5;

const VERT = /* glsl */`
varying vec2 vUv;
void main() { vUv = uv; gl_Position = vec4(position.xy, 0.0, 1.0); }`;

// bloomeffect.fx: weights {0.1, 0.358, 1.773, 2.0, 0.773, 0.358, 0.1} at texel offsets {-6, -3, -1.5, 0, +1.5, +3, +6}
const BLUR_FRAG = /* glsl */`
uniform sampler2D tSrc;
uniform vec2 dir;
uniform vec2 size;
uniform float tap;
varying vec2 vUv;
const float W[7] = float[7](0.1, 0.358, 1.773, 2.0, 0.773, 0.358, 0.1);
const float O[7] = float[7](-6.0, -3.0, -1.5, 0.0, 1.5, 3.0, 6.0);
void main() {
  vec3 c = vec3(0.0);
  float wsum = 0.0;
  float dmin = 1e9;
  ivec2 here = ivec2(gl_FragCoord.xy);
  ivec2 hi = ivec2(size) - 1;
  for (int i = 0; i < 7; i++) {
    c += W[i] * texture2D(tSrc, vUv + dir * (O[i] * tap) / size).rgb;
    wsum += W[i];
    float d = texelFetch(tSrc, clamp(here + ivec2(floor(dir * O[i] * tap + 0.5)), ivec2(0), hi), 0).a;
    if (d > 0.0) dmin = min(dmin, d);
  }
  gl_FragColor = vec4(c / wsum, dmin < 1e8 ? dmin : 0.0);
}`;

const ADD_FRAG = /* glsl */`
uniform sampler2D tGlow;
uniform vec2 size;
uniform float gain;
uniform float bias;
uniform float e10;
uniform float e14;
varying vec2 vUv;
void main() {
  float d = texelFetch(tGlow, clamp(ivec2(vUv * size), ivec2(0), ivec2(size) - 1), 0).a;
  if (d <= 0.0) discard;
  vec3 c = texture2D(tGlow, vUv).rgb * gain;
  if (max(c.r, max(c.g, c.b)) < 0.002) discard;
  float z = max(0.05, d - bias);
  gl_FragColor = vec4(c, 1.0);
  gl_FragDepth = ((e10 * -z + e14) / z) * 0.5 + 0.5;
}`;

function sourceMaterial() {
  const m = new THREE.MeshBasicMaterial({ color: 0xffffff, side: THREE.DoubleSide, fog: false, toneMapped: false });
  m.customProgramCacheKey = () => 'glow-pass-source';
  m.onBeforeCompile = sh => {
    sh.vertexShader = sh.vertexShader.replace('#include <common>', '#include <common>\nvarying float vDkZ;')
      .replace('#include <project_vertex>', '#include <project_vertex>\nvDkZ = -mvPosition.z;');
    sh.fragmentShader = sh.fragmentShader.replace('#include <common>', '#include <common>\nvarying float vDkZ;')
      .replace('#include <opaque_fragment>', 'gl_FragColor = vec4(outgoingLight, vDkZ);');
  };
  return m;
}

const _v2 = new THREE.Vector2(), _v3 = new THREE.Vector3(), _frustum = new THREE.Frustum(), _pv = new THREE.Matrix4(), _sphere = new THREE.Sphere();

export class GlowPass {
  constructor(renderer) {
    this.renderer = renderer;
    this.enabled = true;
    this.broken = false;
    this.sources = new Map();            // overlay mesh -> { hue:[r,g,b], gain:()=>number, material }
    this.rtA = this.rtB = this.rtC = null;
    this.size = new THREE.Vector2();
    this.lastMs = 0;
    this.drawn = 0;
    this._lights = null;                 // the scene's lights (see _sceneLights), reused every aura render
    this._lightsScene = null;
    this._lightsAge = 0;
    this._lifted = [];                   // lights this render put on GLOW_LAYER (taken off again afterwards)
    const rt = () => ({ tSrc: { value: null } });
    this.blurMat = new THREE.ShaderMaterial({ vertexShader: VERT, fragmentShader: BLUR_FRAG, depthTest: false, depthWrite: false, toneMapped: false,
      uniforms: { ...rt(), dir: { value: new THREE.Vector2() }, size: { value: new THREE.Vector2() }, tap: { value: 1 } } });
    this.addMat = new THREE.ShaderMaterial({ vertexShader: VERT, fragmentShader: ADD_FRAG, toneMapped: false,
      depthTest: true, depthWrite: false, depthFunc: THREE.LessEqualDepth, transparent: true,
      blending: THREE.CustomBlending, blendEquation: THREE.AddEquation, blendSrc: THREE.OneFactor, blendDst: THREE.OneFactor,
      uniforms: { tGlow: { value: null }, size: { value: new THREE.Vector2() }, gain: { value: 1 }, bias: { value: 0 }, e10: { value: 0 }, e14: { value: 0 } } });
    this.quad = new FullScreenQuad(this.blurMat);
  }

  /** Can this GPU render the half-float glow buffer? */
  get supported() {
    const r = this.renderer;
    return !!(r.capabilities?.isWebGL2 && (r.extensions.has('EXT_color_buffer_float') || r.extensions.has('EXT_color_buffer_half_float')));
  }

  /** Register an overlay mesh as a glow source. spec = { hue: [r,g,b] 0..1, gain: () => number }. */
  add(mesh, spec) {
    if (!mesh || this.sources.has(mesh)) return;
    mesh.layers.enable(GLOW_LAYER);
    this.sources.set(mesh, { hue: spec.hue, gain: spec.gain, material: sourceMaterial() });
  }
  remove(mesh) {
    const s = this.sources.get(mesh);
    if (!s) return;
    s.material.dispose();
    this.sources.delete(mesh);
    mesh.layers.disable(GLOW_LAYER);
  }
  get active() { return this.enabled && !this.broken && this.sources.size > 0; }

  /** Forget the cached light list (a new map / scene): the next aura render walks the scene again. */
  invalidateLights() { this._lights = null; this._lightsScene = null; }

  /**
   * Every light of `scene`. three.js pushes a light into a render only when the light's layers match the camera's, and its
   * light-state version (which every lit material compares before reusing its program) changes whenever the pushed lights differ
   * from the previous render() call. The aura pass looks through the glow layer only, so without these lights it changed that
   * version twice per frame and every lit material of the frame pass re-ran getProgram / getParameters (measured 3.2 ms of 14 in
   * Ardeca). The list is cached; the walk repeats every `rescan` renders and after invalidateLights(). A light missed by the cache
   * can only bring the old churn back for a while: the aura sources are unlit, so no pixel depends on it.
   */
  _sceneLights(scene, rescan) {
    if (this._lights && this._lightsScene === scene && ++this._lightsAge < rescan) return this._lights;
    const list = this._lights && this._lightsScene === scene ? this._lights : [];
    list.length = 0;
    const stack = [scene];
    while (stack.length) {
      const o = stack.pop();
      if (o.isLight) list.push(o);
      for (let i = o.children.length - 1; i >= 0; i--) stack.push(o.children[i]);
    }
    this._lights = list; this._lightsScene = scene; this._lightsAge = 0;
    return list;
  }

  _ensure(w, h) {
    if (this.rtA && this.size.x === w && this.size.y === h) return;
    for (const t of [this.rtA, this.rtB, this.rtC]) t?.dispose();
    this.size.set(w, h);
    const opt = { type: THREE.HalfFloatType, format: THREE.RGBAFormat, stencilBuffer: false, minFilter: THREE.LinearFilter, magFilter: THREE.LinearFilter, generateMipmaps: false };
    this.rtA = new THREE.WebGLRenderTarget(w, h, { ...opt, depthBuffer: true });
    this.rtB = new THREE.WebGLRenderTarget(w, h, { ...opt, depthBuffer: false });
    this.rtC = new THREE.WebGLRenderTarget(w, h, { ...opt, depthBuffer: false });
  }

  _live(camera) {
    const live = [];
    camera.updateMatrixWorld();
    _frustum.setFromProjectionMatrix(_pv.multiplyMatrices(camera.projectionMatrix, camera.matrixWorldInverse));
    for (const [mesh, s] of this.sources) {
      let visible = true;
      for (let o = mesh; o; o = o.parent) if (o.visible === false) { visible = false; break; }
      if (!visible) continue;
      const amount = s.gain();
      if (!(amount > 0.01)) continue;
      mesh.getWorldPosition(_v3);
      _sphere.set(_v3, 4);
      if (!_frustum.intersectsSphere(_sphere) || _v3.distanceTo(camera.position) > AURA.MAX_DISTANCE) continue;
      live.push([mesh, s, amount]);
    }
    return live;
  }

  /** Add the aura onto the frame that was just rendered into the canvas. Returns the number of sources drawn. */
  render(scene, camera) {
    if (!this.active || !this.supported) return 0;
    // tuning hook (console): globalThis.__dekaronAura = { TAP_SCALE, PASSES, GAIN, SCALE } overrides engine-chosen-aura.js
    const A = globalThis.__dekaronAura ? { ...AURA, ...globalThis.__dekaronAura } : AURA;
    const live = this._live(camera);
    this.drawn = live.length;
    if (!live.length) return 0;
    const r = this.renderer, t0 = performance.now();
    const buf = r.getDrawingBufferSize(_v2);
    if (buf.x < 16 || buf.y < 16) return 0;
    const w = Math.max(8, Math.ceil(buf.x / A.SCALE)), h = Math.max(8, Math.ceil(buf.y / A.SCALE));
    this._ensure(w, h);
    const state = captureBakeRenderer(r);
    const mask = camera.layers.mask, bg = scene.background, override = scene.overrideMaterial, mwa = scene.matrixWorldAutoUpdate;
    const shadowAuto = r.shadowMap.autoUpdate, needsUpdate = r.shadowMap.needsUpdate;
    const saved = [], lifted = this._lifted;
    try {
    try {
      // 1. SOURCE: flat glow colour + distance of each overlay mesh
      for (const [mesh, s, amount] of live) {
        saved.push([mesh, mesh.material]);
        s.material.color.setRGB(s.hue[0] * amount * GLOW_COLOR, s.hue[1] * amount * GLOW_COLOR, s.hue[2] * amount * GLOW_COLOR);
        mesh.material = s.material;
      }
      camera.layers.set(GLOW_LAYER);
      if (A.STABLE_LIGHT_STATE !== false) {
        for (const light of this._sceneLights(scene, A.LIGHT_RESCAN_RENDERS)) {
          if (!light.layers.isEnabled(GLOW_LAYER)) { light.layers.enable(GLOW_LAYER); lifted.push(light); }
        }
      }
      scene.background = null; scene.overrideMaterial = null; scene.matrixWorldAutoUpdate = false;
      r.shadowMap.autoUpdate = false; r.shadowMap.needsUpdate = false; r.shadowMap.enabled = false;
      r.setRenderTarget(this.rtA);
      r.setClearColor(0x000000, 0); r.autoClear = true;
      r.render(scene, camera);
    } finally {
      for (const [mesh, material] of saved) mesh.material = material;
      for (const light of lifted) light.layers.disable(GLOW_LAYER);
      lifted.length = 0;
      camera.layers.mask = mask; scene.background = bg; scene.overrideMaterial = override; scene.matrixWorldAutoUpdate = mwa;
      r.shadowMap.autoUpdate = shadowAuto; r.shadowMap.needsUpdate = needsUpdate;
    }
    {
      r.autoClear = false;
      // 2. BLUR (bloomeffect.fx kernel), PASSES x (horizontal, vertical)
      const bu = this.blurMat.uniforms, unit = A.TAP_SCALE * (h / 225);
      bu.size.value.set(w, h); bu.tap.value = unit;
      this.quad.material = this.blurMat;
      let from = this.rtA;
      for (let i = 0; i < A.PASSES; i++) {
        bu.tSrc.value = from.texture; bu.dir.value.set(1, 0);
        r.setRenderTarget(this.rtB); this.quad.render(r);
        bu.tSrc.value = this.rtB.texture; bu.dir.value.set(0, 1);
        r.setRenderTarget(this.rtC); this.quad.render(r);
        from = this.rtC;
      }
      // 3. ADD onto the frame, depth tested against the frame's own depth buffer
      const au = this.addMat.uniforms, e = camera.projectionMatrix.elements;
      au.tGlow.value = from.texture; au.size.value.set(w, h); au.gain.value = A.GAIN; au.bias.value = A.DEPTH_BIAS;
      au.e10.value = e[10]; au.e14.value = e[14];
      this.quad.material = this.addMat;
      r.setRenderTarget(null);
      this.quad.render(r);
    }
    } finally {
      restoreBakeRenderer(r, state);   // whatever happened above: the renderer is exactly as the frame left it
    }
    this.lastMs = performance.now() - t0;
    return live.length;
  }

  dispose() {
    for (const t of [this.rtA, this.rtB, this.rtC]) t?.dispose();
    this.rtA = this.rtB = this.rtC = null;
    for (const s of this.sources.values()) s.material.dispose();
    this.sources.clear();
    this.blurMat.dispose(); this.addMat.dispose();
  }
}
