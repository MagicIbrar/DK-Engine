// Shader pre-build of the programs the game used to build LAZILY, inside a play frame (the HUD ping label is about 3 x the frame time, so every stalled frame showed as a ping jump).
// MEASURED CAUSE: the biggest client stalls of a big fight are 100-460 ms
// frames inside three.js WebGLProgram.onFirstUse (getProgramInfoLog = a synchronous wait for the GPU process to finish linking a program that
// is drawn for the FIRST time). renderer.info.programs grew from 75 (after the load) to 86-104 programs during the session: 11-29 programs
// built while playing: the corpse-fade variant of every monster kind that dies for the first time, the ground model of every drop kind, the
// skill status shells ... Every one of them is a program that is known as soon as its model / material exists.
//
// WHAT THIS MODULE DOES: nothing but WHEN the programs are built. The same materials, the same states, the same program cache keys: a hidden
// instance of the model goes through the very same code path the real one takes later (SkinnedInstance.setOpacity -> clone materials ->
// world.js applyShadeTree patch), its programs are compiled in parallel (renderer.compileAsync, KHR_parallel_shader_compile: no main thread
// block) and drawn once with colour / depth writes locked off (warm-draw.js), one draw per frame during play. Nothing it draws reaches the
// screen, no shared material is touched.
// COST: a compile / draw against the real world scene walks every object of it (400 monsters with their bones = tens of thousands of nodes:
// several ms each, measured: it made the big-fight frames WORSE). So the programs are built in a small private scene that holds only the
// hidden objects and clones of the world's lights (the sun / back / ambient lights are direct children of the scene, environment.js): the
// same light counts and shadow flags, the same fog = the same program cache keys, at a few hundred microseconds. If the world ever holds a
// light somewhere else the private scene would not match: then the module uses the world scene as before (slower, still correct).
// FIRST-USE SET-UP: besides the link, a program's first draw runs three's WebGLProgram.onFirstUse (uniform + attribute introspection: a burst of
// synchronous GL queries, 20-30 ms per program, measured: the 167 ms frame of the first status-shell cast was nine samples of it). Programs built
// during play are introspected here one per frame as soon as they have linked, and the first draws wait for it; under the loading screen all at once.
//
// KILL SWITCH: globalThis.__dekaronNoPrewarm = true (set it before the game loads, e.g. in the browser console + reload, or any time: it is
// read on every call) restores today's lazy behaviour exactly. FALLBACK: feature detection (renderer.compileAsync, locked draw), every step in
// try / catch (a failing job is dropped, three failures in a row switch the module off for the session), a lost WebGL context aborts and
// forgets everything it knew. Statistics: window.__dekaronPrewarmStats.
import * as THREE from 'three';
import { applyShade, applyShadeTree } from '../world/shade.js';
import { reapplySpecular } from './matfx.js';
import { lockedDraw, drawWithWorldLights } from './warm-draw.js';

const FAIL_LIMIT = 3;
const JOB_TIMEOUT_MS = 10000;  // a background job (compile + hand-over) that never finishes must not block the queue behind it
const PRIORITY_PER_FRAME = 4;   // drops / status shells waiting for their first draw: at most this many renders per frame (a kill-all drops dozens of new kinds)
const states = new WeakMap();

export function prewarmDisabled() { return globalThis.__dekaronNoPrewarm === true; }

function stats() {
  return (globalThis.__dekaronPrewarmStats ||= { jobs: 0, done: 0, failed: 0, skipped: 0, programs: 0, draws: 0, syncMs: 0, drawMs: 0, touches: 0, touchMs: 0, models: 0, off: false, lastError: null, byKind: {} });
}

function stateOf(game) {
  let st = states.get(game);
  if (!st) {
    st = { queue: [], running: false, models: new WeakSet(), drops: new WeakMap(), signatures: new Set(), draws: [], fails: 0, off: false, gen: 0, proxy: null, proxySig: null, proxyOk: false, proxyChecked: 0, camera: null, touched: new WeakSet(), scan: 0 };
    states.set(game, st);
    const canvas = game.renderer?.domElement;
    // a lost context takes every program with it: forget what was warmed, drop what was queued (a restored context warms again)
    if (canvas?.addEventListener) canvas.addEventListener('webglcontextlost', () => { st.gen++; st.queue.length = 0; releaseDraws(st); st.models = new WeakSet(); st.drops = new WeakMap(); st.signatures.clear(); st.proxySig = null; }, false);
  }
  return st;
}

function contextLost(renderer) {
  try { return !!renderer?.getContext?.()?.isContextLost?.(); } catch { return true; }
}

/** Can this game pre-build at all (renderer.compileAsync, a scene and a camera) and is it allowed (kill switch, not switched off by failures)? */
export function prewarmActive(game) {
  if (prewarmDisabled()) { stats().off = true; return false; }
  const r = game?.renderer;
  if (!r || typeof r.compileAsync !== 'function' || !game.scene || !game.camera) return false;
  if (stateOf(game).off) return false;
  return !contextLost(r);
}

const nextMacrotask = () => new Promise(resolve => setTimeout(resolve, 0));

/**
 * The private scene the programs are built in: clones of the world's lights (same types, same shadow flags: the light counts are part of three's program
 * key) and the world's fog (a bit of the key). Rebuilt when the set of lights changes (shadows option, a map with other lights); null when the world holds a
 * visible light that is not a direct child of the scene (then the world scene itself is used).
 */
function proxyOf(game) {
  const st = stateOf(game), world = game.scene;
  const lights = world.children.filter(o => o.isLight && o.visible);
  const sig = lights.map(l => `${l.type}|${l.castShadow ? 1 : 0}|${l.layers.mask}`).join(',');
  const now = performance.now(), every = Number(globalThis.__dekaronPrewarmRecheckMs ?? 5000);
  if (!st.proxy || st.proxySig !== sig || now - st.proxyChecked >= every) {
    // the full walk of the world (is every visible light a direct child?) happens when the light set changes and every few seconds, not per call
    let all = 0;
    world.traverseVisible(o => { if (o.isLight) all++; });
    st.proxyChecked = now; st.proxyOk = all === lights.length;
    if (!st.proxy || st.proxySig !== sig) {
      const proxy = new THREE.Scene();
      for (const light of lights) { const copy = light.clone(); copy.name = `prewarm ${light.type}`; proxy.add(copy); }
      st.proxy = proxy; st.proxySig = sig;
    }
  }
  if (!st.proxyOk) return null;
  st.proxy.fog = world.fog;
  return st.proxy;
}

/** Compile `root` (non-blocking, parallel) against the world's lights / fog, the same call Actor._afterLoad makes. Resolves when linked. */
async function compile(game, root, { fog = true } = {}) {
  const before = game.renderer.info?.programs?.length ?? 0, t = performance.now();
  // the shadow pass draws its casters in an EMPTY scene (no fog) lit by the world's lights: the depth variants are compiled the same way (the fog bit is in the key)
  const proxy = proxyOf(game), scene = proxy || game.scene, sceneFog = scene.fog;
  if (!fog) scene.fog = null;
  let p;
  try { p = game.renderer.compileAsync(root, game.camera, scene); } finally { if (!fog) scene.fog = sceneFog; }
  stats().syncMs += performance.now() - t;
  await p;
  stats().programs += Math.max(0, (game.renderer.info?.programs?.length ?? 0) - before);
}

/** One locked-draw render of private objects: in the private scene (cheap) or, when that does not match the world's lights, lit by the world scene (warm-draw.js). */
function drawRoots(game, roots, { fog = true } = {}) {
  const proxy = proxyOf(game);
  if (!proxy) {
    const scene = game.scene, sceneFog = scene.fog;
    if (!fog) scene.fog = null;
    try { return drawWithWorldLights(game, roots); } finally { if (!fog) scene.fog = sceneFog; }
  }
  const st = stateOf(game);
  if (!fog) proxy.fog = null;
  const camera = (st.camera ||= new THREE.PerspectiveCamera());
  camera.copy(game.camera, false);
  const added = [];
  try {
    for (const root of roots) {
      if (!root) continue;
      root.traverse(o => { if (o.isMesh) o.frustumCulled = false; });   // the hidden copies sit at the origin: never view-culled
      proxy.add(root); added.push(root);
    }
    if (added.length) game.renderer.render(proxy, camera);
    return added.length > 0;
  } finally { for (const root of added) proxy.remove(root); }
}

/**
 * Queue a pre-build job. job() is async and may return {draws: [fn(game)], dispose: fn} : the draws are run once each (locked, no pixels)
 * and dispose() is called after the last one (or at once when nothing is drawn). One job runs at a time, each in its own macrotask.
 */
export function schedulePrewarm(game, kind, job) {
  if (!prewarmActive(game)) { stats().skipped++; return false; }
  const st = stateOf(game);
  stats().jobs++;
  st.queue.push({ kind, job, gen: st.gen });
  void pump(game, st);
  return true;
}

async function pump(game, st) {
  if (st.running) return;
  st.running = true;
  try {
    while (st.queue.length) {
      await nextMacrotask();
      const item = st.queue.shift();
      if (item.gen !== st.gen || !prewarmActive(game)) { stats().skipped++; continue; }
      try {
        let timer = null;
        const stuck = new Promise((_, reject) => { timer = setTimeout(() => reject(new Error(`pre-build job '${item.kind}' took longer than ${JOB_TIMEOUT_MS} ms`)), JOB_TIMEOUT_MS); });
        const work = item.job();
        work.catch(() => {});   // a job that fails after the timeout is not an unhandled rejection
        const out = await Promise.race([work, stuck]).finally(() => clearTimeout(timer));
        if (item.gen !== st.gen || !out) { out?.dispose?.(); }
        else if (out.draws?.length) {
          const left = { n: out.draws.length };
          for (const draw of out.draws) st.draws.push({ draw, done: () => { if (--left.n === 0) { try { out.dispose?.(); } catch { /* ignore */ } } } });
        } else { try { out.dispose?.(); } catch { /* ignore */ } }
        st.fails = 0;
        stats().done++;
        stats().byKind[item.kind] = (stats().byKind[item.kind] || 0) + 1;
      } catch (error) { noteFailure(st, item.kind, error); }
    }
  } finally { st.running = false; }
}

function releaseDraws(st) {
  const list = st.draws.splice(0);
  for (const d of list) { try { d.done(); } catch { /* ignore */ } }
}

// ------------------------------------------------------------------------------------------------ first-use set-up of new programs
function programList(game) { const list = game?.renderer?.info?.programs; return Array.isArray(list) ? list : null; }

/** Programs of the renderer that have not been introspected yet (in creation order). */
function untouchedPrograms(game, st) {
  const list = programList(game), out = [];
  if (!list) return out;
  if (st.scan > list.length) st.scan = 0;   // a new program list (lost / restored context)
  for (let i = st.scan; i < list.length; i++) {
    const program = list[i];
    if (!program || st.touched.has(program)) { if (!out.length) st.scan = i + 1; continue; }
    out.push(program);
  }
  return out;
}

/** The map load's touchPrograms (warm-draw.js) did every program built so far: remember that. Call it right after it. */
export function markProgramsTouched(game) {
  const list = programList(game);
  if (!list) return 0;
  const st = stateOf(game);
  for (const program of list) if (program) st.touched.add(program);
  st.scan = list.length;
  return list.length;
}

function touchPrograms(game, st, limit) {
  let n = 0;
  const t = performance.now();
  for (const program of untouchedPrograms(game, st)) {
    if (n >= limit) break;
    if (typeof program.isReady === 'function' && !program.isReady()) continue;   // still linking: a later frame
    try { program.getUniforms?.(); program.getAttributes?.(); } catch { /* lost context: three rebuilds on the next draw */ }
    st.touched.add(program); n++;
  }
  stats().touches += n; stats().touchMs += performance.now() - t;
  return n;
}

export function untouchedProgramCount(game) { const st = states.get(game); return st ? untouchedPrograms(game, st).length : 0; }

/**
 * Wait (at most maxMs) until every program built so far has had its first-use set-up (done one per frame by tickShaderPrewarm; under the loading
 * screen it is done here at once). First draws that would otherwise run it themselves, inside a play frame, wait for this. With the module off: no wait.
 */
export async function waitProgramsTouched(game, { maxMs = 1500 } = {}) {
  if (!prewarmActive(game)) return true;
  const st = stateOf(game);
  if (game._loadingMap) { touchPrograms(game, st, Infinity); return true; }
  const t = performance.now();
  while (untouchedPrograms(game, st).length && performance.now() - t < maxMs && prewarmActive(game)) await new Promise(resolve => setTimeout(resolve, 8));
  return untouchedPrograms(game, st).length === 0;
}

/**
 * Called once per game frame after the world render: the first-use set-up of ONE new program (all of them under the loading screen, `all`), then the
 * queued first draws: ONE background draw per frame (all at once under the loading screen) and at most PRIORITY_PER_FRAME drops / shells. Colour / depth
 * writes are locked off, nothing reaches the screen (warm-draw.js lockedDraw).
 */
export function tickShaderPrewarm(game, { all = false } = {}) {
  const st = states.get(game);
  if (!st || !game.renderer) return 0;
  if (prewarmDisabled() || st.off || contextLost(game.renderer)) { releaseDraws(st); return 0; }
  if (!all || st.touched) touchPrograms(game, st, all ? Infinity : 1);
  if (!st.draws.length) return 0;
  let n = 0, regular = 0, urgent = 0;
  const t = performance.now(), info = game.renderer.info?.render, keep = info ? { calls: info.calls, triangles: info.triangles, points: info.points, lines: info.lines } : null;
  // a drop / a status shell is waiting for its draw (priority): all of those now; the background jobs one per frame
  for (let i = 0; i < st.draws.length;) {
    const item = st.draws[i];
    if (!all && (item.priority ? urgent >= PRIORITY_PER_FRAME : regular >= 1)) { i++; continue; }
    st.draws.splice(i, 1);
    if (item.priority) urgent++; else regular++;
    try { if (lockedDraw(game.renderer, item.draw)) n++; } catch (error) { stats().failed++; stats().lastError = String(error?.message || error); }
    finally { try { item.done(); } catch { /* ignore */ } }
  }
  if (keep) Object.assign(info, keep);   // the HUD / graphics statistics keep describing the game's own render, not these hidden ones
  stats().draws += n; stats().drawMs += performance.now() - t;
  return n;
}

/** Wait (at most maxMs) until the queue and the running job are done: for the map load, under the loading screen. */
export async function settleShaderPrewarm(game, maxMs = 2500) {
  const st = states.get(game);
  if (!st) return true;
  const t = performance.now();
  while ((st.running || st.queue.length) && performance.now() - t < maxMs && prewarmActive(game)) await nextMacrotask();
  return !(st.running || st.queue.length);
}

export function pendingShaderPrewarm(game) {
  const st = states.get(game);
  return st ? st.queue.length + (st.running ? 1 : 0) + st.draws.length : 0;
}

// ------------------------------------------------------------------------------------------------ the corpse-fade variants of a body
/**
 * The first corpse fade of a model kind (Actor._updateDeath -> setOpacity(a < 1)) clones the instance's materials and makes them transparent
 * (a different program than the opaque body: three's OPAQUE define), and world.js applyShadeTree then patches the clones with the sun fall-off
 * (a second program) within 0.5 s. Both were built inside the play frame of the first fade of every monster kind that died (two programs per
 * kind, a kill-all of seven kinds = fourteen linked in one frame). Here a hidden instance of the model walks the same two steps ahead of time.
 * Called once the body has loaded (Actor._afterLoad); once per model.
 */
export function warmActorFade(game, actor) {
  const model = actor?.model;
  if (!actor?.fadeOnDeath || !model || typeof model.instantiate !== 'function' || model.empty || !prewarmActive(game)) return false;
  const st = stateOf(game);
  if (st.models.has(model)) return false;
  st.models.add(model);
  stats().models++;
  return schedulePrewarm(game, 'fade', () => fadeJob(game, model));
}

async function fadeJob(game, model) {
  const plain = model.instantiate(), shaded = model.instantiate();
  const dispose = () => { for (const inst of [plain, shaded]) { try { inst.dispose?.(); } catch { /* ignore */ } } };
  if (typeof plain?.setOpacity !== 'function' || typeof shaded?.setOpacity !== 'function' || !plain.root) { dispose(); return null; }   // a static body (no per-instance fade clones): nothing to pre-build
  try {
    for (const inst of [plain, shaded]) {
      inst.root.traverse(o => { if (o.isMesh) { o.castShadow = true; o.receiveShadow = false; } });   // Actor._setSkinned
      inst.setOpacity(0.99);                                                                            // the first fade frame: clone materials, transparent
    }
    applyShadeTree(shaded.root);                                                                        // world.js: the sun fall-off patch of those clones
    await Promise.all([compile(game, plain.root), compile(game, shaded.root)]);
    await waitProgramsTouched(game, { maxMs: 2000 });
    return { draws: [() => drawRoots(game, [plain.root]), () => drawRoots(game, [shaded.root])], dispose };
  } catch (error) { dispose(); throw error; }
}

// ------------------------------------------------------------------------------------------------ the ground model of a drop
const SHADOW_SIDE = { 0: 1, 1: 0, 2: 2 };   // three's WebGLShadowMap shadowSide (not VSM)

/** The depth-pass material three's shadow map builds for a caster material (WebGLShadowMap.getDepthMaterial): same map / alphaTest / side. */
function depthVariant(material) {
  const depth = new THREE.MeshDepthMaterial({ depthPacking: THREE.RGBADepthPacking });
  depth.visible = material.visible;
  depth.side = material.shadowSide !== null && material.shadowSide !== undefined ? material.shadowSide : (SHADOW_SIDE[material.side] ?? material.side);
  depth.alphaMap = material.alphaMap; depth.alphaTest = material.alphaTest; depth.map = material.map;
  return depth;
}

/**
 * A copy of `material` as it is drawn once world.js applyShadeTree has patched it (a clone: the shared material is never touched), so the
 * second program of the model (the sun fall-off variant, built within 0.5 s of its first draw) is known too.
 */
function shadedClone(material) {
  const copy = reapplySpecular(material, material.clone());
  applyShade(copy);
  return copy;
}

/**
 * The first drop of a model kind (items/ground.js _makeMarker): its materials build their programs in the frame that first draws it,
 * then again within 0.5 s (the sun fall-off patch), plus the shadow depth variant of a new caster (map / alphaTest / side): up to seven
 * programs of one kind linked in one frame (226-234 ms frames, measured). Called before the model is put on the ground: the programs
 * of the model as it is, its shaded copy and its depth variant are compiled in parallel and drawn once (locked, no pixels). Later drops
 * of the same kind resolve at once. Resolves true when everything is built, false when it was skipped / failed / took longer than
 * `cap` ms (the drop is then placed as before, lazily).
 */
export function warmDropModel(game, model, { cap = 220 } = {}) {
  if (!model || typeof model.instantiate !== 'function' || !prewarmActive(game)) return Promise.resolve(false);
  const st = stateOf(game);
  let job = st.drops.get(model);
  if (!job) {
    stats().models++;
    job = dropJob(game, st, model).catch(error => { noteFailure(st, 'drop', error); return false; });
    st.drops.set(model, job);
  }
  let timer = null;
  const timeout = new Promise(resolve => { timer = setTimeout(() => resolve(false), cap); });
  return Promise.race([job, timeout]).finally(() => clearTimeout(timer));
}

async function dropJob(game, st, model) {
  const gen = st.gen;
  const as = model.instantiate(), shaded = model.instantiate(), depth = model.instantiate();
  const owned = [];
  const dispose = () => { for (const m of owned) { try { m.dispose(); } catch { /* ignore */ } } };
  try {
    for (const root of [as, shaded, depth]) root.traverse(o => { if (o.isMesh) { o.castShadow = true; o.receiveShadow = false; } });
    shaded.traverse(o => { if (o.isMesh && o.material && !Array.isArray(o.material)) { o.material = shadedClone(o.material); owned.push(o.material); } });
    depth.traverse(o => { if (o.isMesh && o.material && !Array.isArray(o.material)) { o.material = depthVariant(o.material); owned.push(o.material); } });
    await Promise.all([compile(game, as), compile(game, shaded), compile(game, depth, { fog: false })]);
    if (gen !== st.gen) return false;
    await waitProgramsTouched(game, { maxMs: 1500 });
    if (gen !== st.gen) return false;
    const drawn = new Promise(resolve => { st.draws.push({ priority: true, draw: () => drawDrop(game, as, shaded, depth), done: resolve }); });
    await drawn;
    stats().byKind.drop = (stats().byKind.drop || 0) + 1; stats().done++;
    return true;
  } finally { dispose(); }
}

/** The first draws of a drop kind: the model as it is and its shaded copy in the world scene, the depth variant as the shadow pass draws it (no fog). */
function drawDrop(game, as, shaded, depth) {
  drawRoots(game, [as, shaded]);
  drawRoots(game, [depth], { fog: false });
}

function noteFailure(st, kind, error) {
  stats().failed++; stats().lastError = String(error?.message || error);
  if (++st.fails >= FAIL_LIMIT) { st.off = true; stats().off = true; console.warn('[prewarm] switched off after repeated failures, shaders build lazily again:', error); }
  else console.warn('[prewarm] job failed (dropped):', kind, error);
}

// ------------------------------------------------------------------------------------------------ objects that are about to be shown
/** What decides the program of a mesh (the parts of three's cache key that differ between the overlays of one game): material type + states + custom key, skinned or not. */
function programSignature(object) {
  const m = Array.isArray(object.material) ? object.material[0] : object.material;
  if (!m) return String(object.uuid);
  let custom = '';
  try { custom = m.customProgramCacheKey?.() ?? ''; } catch { /* a hook that throws: no memo */ custom = String(Math.random()); }
  return [m.type, m.transparent ? 1 : 0, m.blending, m.alphaTest, m.side, m.map ? 1 : 0, m.depthWrite ? 1 : 0, m.vertexColors ? 1 : 0, m.fog ? 1 : 0, object.isSkinnedMesh ? 1 : 0, object.isInstancedMesh ? 1 : 0, object.geometry?.morphAttributes?.position ? 1 : 0, object.geometry?.attributes?.color ? 1 : 0, custom].join('|');
}

/**
 * Programs of objects a system has just created and is about to show (skill status shells, ...): compile (parallel) and draw once, locked,
 * while the objects are hidden, then show them. Calls `show()` at the latest after `cap` ms; with the module off, for objects outside the world
 * scene, or for programs that were already built it calls it at once. The objects must be in the scene (they ride a body) and hidden by the
 * caller; `show` makes them visible again.
 */
export async function warmThenShow(game, objects, show, { cap = 220 } = {}) {
  let shown = false;
  const showOnce = () => { if (shown) return; shown = true; try { show(); } catch (error) { console.warn('[prewarm] show failed', error); } };
  const inWorld = o => { for (let p = o; p; p = p.parent) if (p === game.scene) return true; return false; };   // an item-preview scene is not the world: nothing to match
  if (!prewarmActive(game) || !objects?.length || !objects.every(inWorld)) { showOnce(); return false; }
  const st = stateOf(game), signatures = objects.map(programSignature);
  if (signatures.every(s => st.signatures.has(s))) { showOnce(); return true; }   // the same programs were built and drawn before: nothing to wait for
  let timer = null;
  try {
    stats().jobs++;
    const work = (async () => {
      await Promise.all(objects.map(o => compile(game, o)));
      await waitProgramsTouched(game, { maxMs: 1500 });
      await new Promise(resolve => {
        st.draws.push({ priority: true, done: resolve, draw: () => {
          if (!proxyOf(game)) {   // the private scene does not match the world's lights: draw the real objects in the world scene
            const keep = objects.map(o => o.visible);
            objects.forEach(o => { o.visible = true; });
            try { drawWithWorldLights(game, objects); } finally { objects.forEach((o, i) => { o.visible = keep[i]; }); }
            return;
          }
          // shallow copies share geometry, material and skeleton: the same programs, drawn in the private scene
          const copies = objects.map(o => { const c = o.clone(false); c.visible = true; return c; });
          drawRoots(game, copies);
        } });
      });
      return true;
    })();
    work.catch(() => {});   // a late failure after the cap is not an unhandled rejection
    const capped = new Promise(resolve => { timer = setTimeout(() => resolve(false), cap); });
    const built = await Promise.race([work, capped]);
    if (built) { stats().done++; stats().byKind.show = (stats().byKind.show || 0) + 1; for (const s of signatures) st.signatures.add(s); }
    return built;
  } catch (error) { noteFailure(st, 'show', error); return false; }
  finally { clearTimeout(timer); showOnce(); }
}
