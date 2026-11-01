// Two lag spikes: the first switch from third to first person, and the first mount summon in first person. Two causes measured in the real client (test-client frame timing and profiling of the first switch and the mount summon; ANGLE / Direct3D 11):
//  1. renderer.compileAsync builds a shader program, but the FIRST real draw of it still stalls the GPU process (ANGLE builds
//     the D3D11 vertex-input / output variants, buffers and bone textures upload): a 276 ms frame with no new program and only
//     11 ms inside renderer.render. A warm draw does that first draw early, inside a normal frame after the world render (so
//     the canvas is never presented half-drawn), with colour and depth writes locked off - nothing reaches the screen.
//  2. three.js destroys a program as soon as its last material is disposed and compiles it again when an equal material
//     comes back. Equipment refine-glow shells are rebuilt on every stance change (items/authored-effects.js signature) and
//     their first-person copies follow them, so the same programs were being destroyed and rebuilt. keepShaderPrograms keeps
//     every program for the session (one extra use taken when three creates it). The set of distinct programs is bounded by
//     the material variants the game has (about a hundred), so this costs a little GPU memory, not a per-frame leak.
const queues = new WeakMap();
export const WARM_LAYER = 31;

/** Keep every shader program three creates on this renderer for the session (see 2 above). Idempotent; re-run after a context restore. */
export function keepShaderPrograms(renderer) {
  const list = renderer?.info?.programs;
  if (!Array.isArray(list) || list.__dkKeep) return false;
  Object.defineProperty(list, '__dkKeep', { value: true });
  const push = list.push;
  list.push = function (...programs) {
    for (const program of programs) if (program && typeof program.usedTimes === 'number') program.usedTimes++;
    return push.apply(this, programs);
  };
  for (const program of list) if (program && typeof program.usedTimes === 'number') program.usedTimes++;
  return true;
}

/**
 * three.js reads a program's uniform locations and info log on its first draw (WebGLProgram onFirstUse, a synchronous round
 * trip to the GPU process). Programs compiled for the whole map at load (renderer.compileAsync) but first drawn later - the
 * horizon the third-person camera never looked at, seen on the first switch to first person - paid it then: 56 ms in one
 * frame (test-client frame timing). Do it for every program built so far, while the loading screen still covers the canvas.
 */
export function touchPrograms(renderer) {
  let touched = 0;
  for (const program of renderer?.info?.programs || []) {
    try { program.getUniforms?.(); program.getAttributes?.(); touched++; } catch { /* lost context: three rebuilds on the next draw */ }
  }
  return touched;
}

/**
 * Draw every mesh of the scene once with frustum culling off (colour / depth locked, a camera copy so the post passes are
 * skipped): textures upload and the GPU builds its draw variants under the loading screen, not in the frame where the object
 * first comes into view (the horizon on the first switch to first person, test-client frame timing).
 */
export function warmWholeScene(game) {
  const scene = game?.scene, renderer = game?.renderer;
  if (!scene || !renderer || !game.camera) return false;
  const camera = game.camera.clone(), culled = [];
  scene.traverse(object => { if (object.frustumCulled && (object.isMesh || object.isPoints || object.isSprite || object.isLine)) { object.frustumCulled = false; culled.push(object); } });
  try { return lockedDraw(renderer, r => r.render(scene, camera)); } finally { for (const object of culled) object.frustumCulled = true; }
}

/** Run `draw(renderer)` with colour and depth writes locked off, no clear and the shadow map frozen: GPU work, no pixels. */
export function lockedDraw(renderer, draw) {
  const buffers = renderer?.state?.buffers, shadow = renderer?.shadowMap;
  if (typeof buffers?.color?.setLocked !== 'function' || typeof buffers?.depth?.setLocked !== 'function') return false;
  const clear = renderer.autoClear, auto = shadow?.autoUpdate, needs = shadow?.needsUpdate;
  buffers.color.setMask(false); buffers.color.setLocked(true);
  buffers.depth.setMask(false); buffers.depth.setLocked(true);
  if (shadow) { shadow.autoUpdate = false; shadow.needsUpdate = false; }
  renderer.autoClear = false;
  try { draw(renderer); return true; } finally {
    renderer.autoClear = clear;
    if (shadow) { shadow.autoUpdate = auto; shadow.needsUpdate = needs; }
    buffers.color.setLocked(false); buffers.color.setMask(true);
    buffers.depth.setLocked(false); buffers.depth.setMask(true);
  }
}

/** Queue a warm draw for the next frame (flushWarmDraws, called by the game right after its world render). */
export function queueWarmDraw(game, draw) {
  if (!game || typeof draw !== 'function') return;
  let queue = queues.get(game);
  if (!queue) { queue = []; queues.set(game, queue); }
  queue.push(draw);
}

export function pendingWarmDraws(game) { return queues.get(game)?.length || 0; }

/** Run the queued warm draws (inside the frame, after the world render). */
export function flushWarmDraws(game) {
  const queue = queues.get(game);
  if (!queue?.length || !game.renderer) return 0;
  queues.delete(game);
  let done = 0;
  for (const draw of queue) {
    try { if (lockedDraw(game.renderer, draw)) done++; } catch (error) { console.warn('[render] warm draw failed', error); }
  }
  return done;
}

/**
 * Draw `roots` once lit by the world scene's own lights, the way the world render will draw them: a copy of the game camera
 * on a private layer sees only these meshes and the lights (so the programs match the world pass exactly). Roots that are
 * not in the scene are attached for the draw. `materialFor(mesh, material)` may return the material to draw with instead
 * (first-person variants). Everything is restored afterwards. Call it from a queued warm draw (inside lockedDraw).
 */
export function drawWithWorldLights(game, roots, materialFor = null, { sprites = false } = {}) {
  const scene = game?.scene, renderer = game?.renderer;
  if (!scene || !renderer || !game.camera) return false;
  const camera = game.camera.clone();
  camera.layers.set(WARM_LAYER);
  const undo = [];
  try {
    scene.traverse(object => {
      if (object.isLight && !object.layers.isEnabled(WARM_LAYER)) { object.layers.enable(WARM_LAYER); undo.push(() => object.layers.disable(WARM_LAYER)); }
    });
    let meshes = 0;
    for (const root of roots) {
      if (!root) continue;
      if (!root.parent) { scene.add(root); undo.push(() => root.removeFromParent()); }
      root.traverse(mesh => {
        if ((!mesh.isMesh && !(sprites && mesh.isSprite)) || !mesh.material) return;
        const layers = mesh.layers.mask, culled = mesh.frustumCulled, material = mesh.material;
        mesh.layers.enable(WARM_LAYER); mesh.frustumCulled = false;
        if (materialFor) mesh.material = Array.isArray(material) ? material.map(m => materialFor(mesh, m) || m) : (materialFor(mesh, material) || material);
        undo.push(() => { mesh.layers.mask = layers; mesh.frustumCulled = culled; mesh.material = material; });
        meshes++;
      });
    }
    if (meshes) renderer.render(scene, camera);
    return meshes > 0;
  } finally {
    for (let i = undo.length - 1; i >= 0; i--) undo[i]();
  }
}
