// The client's bloom (data/binary/bloomeffect.fx "TBloomEffect"), reproduced as a cheap post-process:
//
//   PS_POW     copy of the frame, downsampled (a 1/4-size render target, as the DX9 client's StretchRect did),
//              f = pow(colour, g_fPowValue)                                       -> threshold by power
//   PS_BLUR_X  7 taps at -6, -3, -1.5, 0, +1.5, +3, +6 texels, weights {0.1, 0.358, 1.773, 2.0, 0.773, 0.358, 0.1}
//              (sic - the client's kernel is slightly lopsided) / g_fWeightValue
//   PS_BLUR_Y  the same vertically
//   add        the blurred image is added onto the frame (additive, gamma space - no colour management, the DX9 look)
//
// Parameters (per map, per time of day): map/light_*.txt `bloom_value enabled p1 p2 p3 p4` (environment.js key
// `bloom.params`, interpolated by sampleEnvironment): g_fPowValue = p1 / 10, g_fWeightValue = p2 / 10 (bloomlow.fx
// divides the same slider by 10 for its power) [inference: the scale]. p3 (1 in Ardeca, 5..20 in Braiken over the day,
// 104 / 123 in the dark Highland / login scenes) grows as maps get darker: read as the add strength
// 0.3 + 0.7 x p3 / 100 [inference], times the Options "Bloom brightness" level.
//
// Cost: the 3D scene still renders straight to the (antialiased) canvas; bloom adds one framebuffer copy, three passes
// over a quarter-size target and one additive full-screen pass - well under a millisecond at 1080p. Quality `scale`
// (governor) picks 1/4 or 1/8 size; the tap offsets scale with it so the glow keeps its on-screen radius.
import * as THREE from 'three';
import { FullScreenQuad } from 'three/addons/postprocessing/Pass.js';

const VERT = /* glsl */`
varying vec2 vUv;
void main() { vUv = uv; gl_Position = vec4(position.xy, 0.0, 1.0); }`;

const POW_FRAG = /* glsl */`
uniform sampler2D tSrc;
uniform vec2 srcTexel;
uniform float powValue;
uniform float step;
varying vec2 vUv;
void main() {
  // the mean of the source block under this texel (4 bilinear taps = 16 texels at 1/4 size)
  vec2 o = srcTexel * step;
  vec3 c = texture2D(tSrc, vUv + vec2(-o.x, -o.y)).rgb + texture2D(tSrc, vUv + vec2(o.x, -o.y)).rgb
         + texture2D(tSrc, vUv + vec2(-o.x, o.y)).rgb + texture2D(tSrc, vUv + vec2(o.x, o.y)).rgb;
  c *= 0.25;
  gl_FragColor = vec4(pow(max(c, vec3(0.0)), vec3(powValue)), 1.0);
}`;

const BLUR_FRAG = /* glsl */`
uniform sampler2D tSrc;
uniform vec2 dir;          // texel step (x or y) x the tap scale
uniform float weightValue;
varying vec2 vUv;
void main() {
  vec3 c = 0.1   * texture2D(tSrc, vUv - 6.0 * dir).rgb
         + 0.358 * texture2D(tSrc, vUv - 3.0 * dir).rgb
         + 1.773 * texture2D(tSrc, vUv - 1.5 * dir).rgb
         + 2.0   * texture2D(tSrc, vUv).rgb
         + 0.773 * texture2D(tSrc, vUv + 1.5 * dir).rgb
         + 0.358 * texture2D(tSrc, vUv + 3.0 * dir).rgb
         + 0.1   * texture2D(tSrc, vUv + 6.0 * dir).rgb;
  gl_FragColor = vec4(c / weightValue, 1.0);
}`;

const ADD_FRAG = /* glsl */`
uniform sampler2D tSrc;
uniform float intensity;
varying vec2 vUv;
void main() { gl_FragColor = vec4(texture2D(tSrc, vUv).rgb * intensity, 1.0); }`;

function passMaterial(frag, uniforms, blend = false) {
  const m = new THREE.ShaderMaterial({ vertexShader: VERT, fragmentShader: frag, uniforms, depthTest: false, depthWrite: false, fog: false, toneMapped: false });
  if (blend) {
    m.transparent = true;
    m.blending = THREE.CustomBlending;
    m.blendEquation = THREE.AddEquation;
    m.blendSrc = THREE.OneFactor;
    m.blendDst = THREE.OneFactor;
  }
  return m;
}

export const BLOOM_LEVELS = [0.6, 1.0, 1.5];   // Options "Bloom brightness" 0..2

export class Bloom {
  constructor(renderer) {
    this.renderer = renderer;
    this.src = null;             // FramebufferTexture (drawing-buffer size)
    this.rtA = null; this.rtB = null;
    this.size = new THREE.Vector2();
    this.scale = 4;              // divisor of the bloom target (4 = quarter, 8 = eighth)
    this.params = { pow: 2.06, weight: 4.41, intensity: 0.4 };
    const rt = { tSrc: { value: null } };
    this.powMat = passMaterial(POW_FRAG, { ...THREE.UniformsUtils.clone(rt), srcTexel: { value: new THREE.Vector2() }, powValue: { value: 2 }, step: { value: 1 } });
    this.blurMat = passMaterial(BLUR_FRAG, { ...THREE.UniformsUtils.clone(rt), dir: { value: new THREE.Vector2() }, weightValue: { value: 4.4 } });
    this.addMat = passMaterial(ADD_FRAG, { ...THREE.UniformsUtils.clone(rt), intensity: { value: 0.4 } }, true);
    this.quad = new FullScreenQuad(this.powMat);
    this.lastMs = 0;
  }

  _ensure(w, h) {
    const sw = Math.max(8, Math.round(w / this.scale)), sh = Math.max(8, Math.round(h / this.scale));
    if (this.src && this.size.x === w && this.size.y === h && this.rtA.width === sw && this.rtA.height === sh) return;
    this.src?.dispose();
    this.rtA?.dispose(); this.rtB?.dispose();
    this.size.set(w, h);
    this.src = new THREE.FramebufferTexture(w, h);
    this.src.minFilter = this.src.magFilter = THREE.LinearFilter;
    this.src.generateMipmaps = false;
    const opt = { depthBuffer: false, stencilBuffer: false, type: THREE.UnsignedByteType, minFilter: THREE.LinearFilter, magFilter: THREE.LinearFilter, generateMipmaps: false };
    this.rtA = new THREE.WebGLRenderTarget(sw, sh, opt);
    this.rtB = new THREE.WebGLRenderTarget(sw, sh, opt);
    this.rtA.texture.name = 'bloom A'; this.rtB.texture.name = 'bloom B';
  }

  /** Apply the bloom to what was just rendered into the canvas. */
  apply() {
    const r = this.renderer, p = this.params;
    if (!(p.intensity > 0.001)) return;
    const t0 = performance.now();
    const buf = r.getDrawingBufferSize(_v2);
    const w = buf.x | 0, h = buf.y | 0;
    if (w < 16 || h < 16) return;
    this._ensure(w, h);
    const prevTarget = r.getRenderTarget();
    const prevAuto = r.autoClear;
    r.autoClear = false;
    try {
      r.setRenderTarget(null);
      r.copyFramebufferToTexture(this.src);
      // 1. downsample + pow
      const pu = this.powMat.uniforms;
      pu.tSrc.value = this.src;
      pu.srcTexel.value.set(1 / w, 1 / h);
      pu.step.value = this.scale / 4;              // 4 taps cover the whole block at either scale
      pu.powValue.value = p.pow;
      this.quad.material = this.powMat;
      r.setRenderTarget(this.rtA); this.quad.render(r);
      // 2. blur x, 3. blur y  (tap offsets in quarter-size texels, whatever the target scale)
      const k = 4 / this.scale;
      const bu = this.blurMat.uniforms;
      bu.weightValue.value = p.weight;
      this.quad.material = this.blurMat;
      bu.tSrc.value = this.rtA.texture; bu.dir.value.set(k / this.rtA.width, 0);
      r.setRenderTarget(this.rtB); this.quad.render(r);
      bu.tSrc.value = this.rtB.texture; bu.dir.value.set(0, k / this.rtB.height);
      r.setRenderTarget(this.rtA); this.quad.render(r);
      // 4. add onto the frame
      this.addMat.uniforms.tSrc.value = this.rtA.texture;
      this.addMat.uniforms.intensity.value = p.intensity;
      this.quad.material = this.addMat;
      r.setRenderTarget(null); this.quad.render(r);
    } finally {
      r.setRenderTarget(prevTarget);
      r.autoClear = prevAuto;
    }
    this.lastMs = performance.now() - t0;
  }

  dispose() {
    this.src?.dispose(); this.rtA?.dispose(); this.rtB?.dispose();
    this.powMat.dispose(); this.blurMat.dispose(); this.addMat.dispose();
    this.src = this.rtA = this.rtB = null;
  }
}

const _v2 = new THREE.Vector2();

/**
 * Bloom parameters of an environment sample (environment.js sampleEnvironment result) -> {enabled, pow, weight, strength}.
 * Raw key values: bloom.params = [p1, p2, p3, p4] (the enabled flag is bloom.enabled).
 */
export function bloomFromEnvironment(e) {
  const b = e?.bloom;
  // a light file without any bloom_value line: the common field setting (1 20.59 44.12 10.00)
  if (!b || !(b.raw?.length || b.params?.length)) return { enabled: true, pow: 2.06, weight: 4.41, strength: 0.37 };
  const P = Array.isArray(b.params) ? b.params : Array.isArray(b.raw) ? b.raw.slice(1) : [];
  const p1 = Number(P[0]), p2 = Number(P[1]), p3 = Number(P[2]);
  return {
    enabled: b.enabled !== false && Number(b.enabled) !== 0,
    pow: Math.min(10, Math.max(1, (p1 > 0 ? p1 : 20.6) / 10)),
    weight: Math.min(12, Math.max(2, (p2 > 0 ? p2 : 44.1) / 10)),
    strength: 0.3 + 0.7 * Math.min(1.25, Math.max(0, (Number.isFinite(p3) ? p3 : 10) / 100)),
  };
}
