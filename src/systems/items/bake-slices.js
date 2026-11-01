import * as THREE from 'three';

// Timers also progress while a loading screen or hidden document suppresses RAF.
export const yieldBake = () => new Promise(resolve => setTimeout(resolve, 0));
export async function bakeSlices(count, draw, enter = () => {}, leave = () => {}, yieldWork = yieldBake, boundary = null) {
  let next = 0;
  while (next < count) {
    const state = enter(), start = performance.now();
    try {
      let batch = 0;
      do { draw(next++); batch++; } while (next < count && batch < 4 && performance.now() - start < 2);
    } finally { leave(state); }
    if (next < count) await yieldWork();
    // A queued foreground bake may run here, after all renderer state was restored.
    if (boundary) await boundary();
  }
}
export function captureBakeRenderer(r) {
  return { target: r.getRenderTarget(), face: r.getActiveCubeFace?.() || 0, mip: r.getActiveMipmapLevel?.() || 0,
    color: r.getClearColor(new THREE.Color()), alpha: r.getClearAlpha(), shadow: r.shadowMap.enabled,
    auto: r.autoClear, viewport: r.getViewport(new THREE.Vector4()), scissor: r.getScissor(new THREE.Vector4()),
    scissorTest: r.getScissorTest() };
}
export function restoreBakeRenderer(r, state) {
  r.setRenderTarget(state.target, state.face, state.mip);
  r.setClearColor(state.color, state.alpha);
  r.shadowMap.enabled = state.shadow; r.autoClear = state.auto;
  r.setViewport(state.viewport); r.setScissor(state.scissor); r.setScissorTest(state.scissorTest);
}
