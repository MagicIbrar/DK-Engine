// Port of the Global client's data/binary/postwatereffect.fx (technique "ColorConversion", ps_2_0): a full-screen
// two-point ripple that refracts the finished frame. What the source says:
//   UserPoint1 / UserPoint2  "first / second click position" (texture space 0..1)
//   Pt1Time / Pt2Time        "ripples time ... x = [1,0], y = [0,1]": x fades 1 -> 0 (strength), y grows 0 -> 1 (radius)
//   ripple(p) = sin(-(R - |c - p|) * 4) * 0.125 * (x / 2) * normalize(c - p)  inside R = (y / 2) * 5.4, else 0
//   colour    = scene(uv + ripple1 + ripple2)
// So it is a CLICK RIPPLE, not an underwater pass and not a timed screen sweep: it is driven by two click points and
// their timers. `sinTexture` is filled by the exe (not in the data); its name and use (one lookup of -inside x 4) make it
// a sine table - read here as sin() of the same argument [inference: the table's period/scale is not in the data].
// What triggers it (which click, which screen, which option) is in the exe only, so this pass is NOT hooked to any input
// or option (bench/GRAPHICS-SETTINGS-403.md): it is a faithful pass, ready to be driven once the trigger is known.
import * as THREE from 'three';

export const RIPPLE = Object.freeze({ freq: 4.0, speed: 5.4, height: 0.125 });

export const POST_WATER_FRAG = /* glsl */`
uniform sampler2D tScene;
uniform vec4 userPoint1;
uniform vec4 userPoint2;
uniform vec4 pt1Time;
uniform vec4 pt2Time;
varying vec2 vUv;
vec2 rippleAt(vec2 p, vec4 c, vec4 t) {
  vec4 m = t * 0.5;
  float radius = m.y * ${RIPPLE.speed.toFixed(1)};
  vec2 d = c.xy - p;
  float inside = radius - length(d);
  if (inside <= 0.0) return vec2(0.0);
  return sin(-inside * ${RIPPLE.freq.toFixed(1)}) * ${RIPPLE.height.toFixed(3)} * m.x * normalize(d);
}
void main() {
  vec2 uv = rippleAt(vUv, userPoint1, pt1Time) + rippleAt(vUv, userPoint2, pt2Time) + vUv;
  gl_FragColor = texture2D(tScene, uv);
}`;

/** CPU reference of the shader's per-pixel offset (tests). */
export function rippleOffset(p, c, t) {
  const mx = t[0] * 0.5, my = t[1] * 0.5;
  const radius = my * RIPPLE.speed, dx = c[0] - p[0], dy = c[1] - p[1], len = Math.hypot(dx, dy);
  const inside = radius - len;
  if (!(inside > 0) || len === 0) return [0, 0];
  const k = Math.sin(-inside * RIPPLE.freq) * RIPPLE.height * mx / len;
  return [k * dx, k * dy];
}

export function createPostWaterMaterial() {
  return new THREE.ShaderMaterial({
    uniforms: {
      tScene: { value: null },
      userPoint1: { value: new THREE.Vector4() }, userPoint2: { value: new THREE.Vector4() },
      pt1Time: { value: new THREE.Vector4() }, pt2Time: { value: new THREE.Vector4() },
    },
    vertexShader: 'varying vec2 vUv; void main(){ vUv = uv; gl_Position = vec4(position.xy, 0.0, 1.0); }',
    fragmentShader: POST_WATER_FRAG, depthTest: false, depthWrite: false,
  });
}
