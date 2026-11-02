// Legacy entry used by feel-bench and as a pre-gfx fallback from game._drawFrame.
// Implements the same bloomeffect.fx path as systems/graphics/bloom.js (Global-comparable),
// not the old weak bright-pass (strength 0.18 / threshold 0.8) that G3 measured as near-no-op.
import { Bloom as GlobalBloom, bloomFromEnvironment, BLOOM_LEVELS } from '../systems/graphics/bloom.js';

export class Bloom {
  constructor(renderer) {
    this.renderer = renderer;
    this.failed = false;
    this._inner = new GlobalBloom(renderer);
    // Default mid Options brightness, common field light params (Global full-add strength).
    const env = bloomFromEnvironment(null);
    this._inner.params.pow = env.pow;
    this._inner.params.weight = env.weight;
    this._inner.params.intensity = env.strength * BLOOM_LEVELS[1];
  }

  /** Render scene then apply Global-comparable bloom onto the canvas. */
  render(scene, camera) {
    const r = this.renderer;
    if (this.failed) { r.render(scene, camera); return; }
    try {
      r.render(scene, camera);
      this._inner.apply();
    } catch (error) {
      this.failed = true;
      console.warn('[graphics] bloom unavailable; using direct rendering', error);
      try { r.render(scene, camera); } catch { /* already failed */ }
    }
  }

  dispose() {
    this._inner?.dispose();
    this._inner = null;
  }
}

export { bloomFromEnvironment, BLOOM_LEVELS };
