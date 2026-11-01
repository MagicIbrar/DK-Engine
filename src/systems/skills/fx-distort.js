// `distort true` sprites (3 units, sp_BAR_Crash_Boost_01..03). Global ships no effect distortion shader (binary/*.fx:
// water.fx refraction and postwatereffect.fx ripples only), so the native look is unknown. DISTORT.MODE (config):
//   'off'     (default) the sprite draws as authored with its texture and blend, like every other sprite;
//   'refract' opt-in approximation: the sprite's texture offsets a copy of the frame drawn so far (one framebuffer copy
//             per rendered frame while such a sprite is visible, shared by all of them).
import * as THREE from 'three';
import { DISTORT } from '../../config/engine-chosen-skill-fx.js';

const captures = new WeakMap();      // renderer -> { texture, frame, size }
const _size = new THREE.Vector2();

/** Scene-colour copy for this renderer, refreshed at most once per rendered frame. */
export function sceneCapture(renderer) {
  let c = captures.get(renderer);
  if (!c) { c = { texture: null, frame: -1, size: new THREE.Vector2(1, 1), copies: 0 }; captures.set(renderer, c); }
  const target = renderer.getRenderTarget?.();
  if (target) _size.set(target.width, target.height); else renderer.getDrawingBufferSize(_size);
  if (!c.texture || c.texture.image.width !== _size.x || c.texture.image.height !== _size.y) {
    c.texture?.dispose();
    c.texture = new THREE.FramebufferTexture(_size.x, _size.y);
    c.texture.minFilter = c.texture.magFilter = THREE.LinearFilter;
    c.frame = -1;
  }
  const frame = renderer.info?.render?.frame ?? 0;
  if (c.frame !== frame) { renderer.copyFramebufferToTexture(c.texture); c.frame = frame; c.copies++; }
  c.size.copy(_size);
  return c;
}

/** Turn a camera SpriteMaterial into the refraction approximation (mode 'refract'); returns false when not applied. */
export function applyDistort(sprite, mode = DISTORT.MODE, strength = DISTORT.STRENGTH) {
  if (mode !== 'refract' || !sprite?.isSprite) return false;
  const mat = sprite.material;
  const u = { dkScene: { value: null }, dkRes: { value: new THREE.Vector2(1, 1) }, dkStrength: { value: strength } };
  mat.blending = THREE.NormalBlending;
  mat.onBeforeCompile = sh => {
    Object.assign(sh.uniforms, u);
    sh.fragmentShader = sh.fragmentShader
      .replace('#include <common>', '#include <common>\nuniform sampler2D dkScene; uniform vec2 dkRes; uniform float dkStrength;')
      .replace('outgoingLight = diffuseColor.rgb;', 'vec2 dkOff = ( diffuseColor.rg - 0.5 ) * dkStrength * diffuseColor.a;\n\toutgoingLight = texture2D( dkScene, gl_FragCoord.xy / dkRes + dkOff ).rgb;');
  };
  mat.customProgramCacheKey = () => 'fx-distort-refract';
  mat.needsUpdate = true;
  sprite.onBeforeRender = renderer => { const c = sceneCapture(renderer); u.dkScene.value = c.texture; u.dkRes.value.copy(c.size); };
  sprite.userData.dkDistort = true;
  return true;
}
