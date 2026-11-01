// The Dil pile models are built under the loading screen, not at the first monster death.
// MEASURED CAUSE: the first drop of every ground-model kind built its shader programs (the model as it is, the sun fall-off
// copy the world.js patch makes within 0.5 s, and the shadow depth variant of a new caster) in the play frame that first drew it: 50-110 ms per kind. The
// shader pre-build (engine/shader-prewarm.js warmDropModel, called by items/ground.js _makeMarker) already builds them in parallel at the FIRST DROP of a
// kind, before the model is put down. What is left is that a Dil pile is certain to drop at the first kill of every session, so its five models (money_01 ..
// money_05) are known at map load: here they go through the very same warmDropModel under the loading screen, so even the first kill finds them built
// (no 100-220 ms wait for the pile to appear, no draw of a new kind in the middle of a fight). Item kinds (potions, stones, equipment) are not known before
// they drop and stay on the first-drop path of shader-prewarm.js.
// WHAT THIS CHANGES: only WHEN. The model request is the one ground.js _makeMarker makes (same loadStatic cache key => the same shared model object and
// materials, so warmDropModel's per-model memo recognises it later), nothing is added to the scene, nothing is drawn to the screen (locked draws).
// KILL SWITCH: globalThis.__dekaronNoDropPrewarm = true (read on every call) gives today's behaviour (the first-drop path of shader-prewarm.js), and so does
// globalThis.__dekaronNoPrewarm = true. FALLBACK: every step is in try / catch, a model that does not load or a compile that fails is skipped, the wait is capped.
import { warmDropModel, tickShaderPrewarm, prewarmActive } from '../../engine/shader-prewarm.js';

const MONEY_KINDS = 5;                                      // money_shape.csv: 5 pile sizes (ground.js DIL_THRESH has four thresholds)
const macrotask = () => new Promise(resolve => setTimeout(resolve, 0));
const clock = () => (typeof performance !== 'undefined' && performance.now ? performance.now() : Date.now());

export function dropPrewarmDisabled() { return globalThis.__dekaronNoDropPrewarm === true; }

/**
 * The loadStatic requests of the five Dil piles, exactly as items/ground.js _makeMarker builds them for a dil drop
 * (vis = db.visual.money[k].field; twoSide: vis.twoSide !== false -> true; transparent: true).
 */
export function dilPileRequests(db) {
  const out = [];
  for (let k = 0; k < MONEY_KINDS; k++) {
    const field = db?.visual?.money?.[k]?.field;
    if (!field?.mesh) continue;
    out.push({ mesh: field.mesh, opts: { tpackKey: field.tpack || null, textures: field.textures || null, twoSide: true, transparent: true } });
  }
  return out;
}

/**
 * Load the Dil pile models and pre-build their programs (warmDropModel: compile in parallel, then one locked draw each) while the loading screen is up.
 * Resolves {models, built, ms} (never rejects). Waits at most maxMs, then leaves the rest to the first-drop path.
 */
export async function prewarmDilPiles(game, { maxMs = 2500 } = {}) {
  const result = { models: 0, built: 0, ms: 0, skipped: null };
  const t0 = clock();
  try {
    if (dropPrewarmDisabled()) { result.skipped = 'kill switch'; return result; }
    if (!prewarmActive(game)) { result.skipped = 'prewarm inactive'; return result; }
    const requests = dilPileRequests(game.items?.db), models = game.models;
    if (!requests.length || typeof models?.loadStatic !== 'function') { result.skipped = 'no models'; return result; }
    // Loading the source models is optional too. A missing or slow asset must
    // not consume the entire map transition before the shader-loop budget starts.
    let assetTimer;
    const assets = Promise.all(requests.map(r => Promise.resolve().then(() => models.loadStatic(r.mesh, r.opts)).catch(() => null)));
    const settled = await Promise.race([
      assets,
      new Promise(resolve => { assetTimer = setTimeout(() => resolve(null), Math.max(0, maxMs - (clock() - t0))); }),
    ]);
    clearTimeout(assetTimer);
    if (!settled) { result.skipped = 'asset wait budget'; result.ms = Math.round(clock() - t0); return result; }
    const loaded = settled.filter(m => m && typeof m.instantiate === 'function');
    result.models = loaded.length;
    let left = loaded.length;
    for (const model of loaded) warmDropModel(game, model, { cap: maxMs }).then(done => { if (done) result.built++; }, () => {}).finally(() => { left--; });
    // the first draws are normally run one frame at a time by game.js; under the loading screen nothing renders, so run them here
    while (left > 0 && clock() - t0 < maxMs) { tickShaderPrewarm(game, { all: true }); await macrotask(); }
  } catch (error) { result.skipped = String(error?.message || error); }
  result.ms = Math.round(clock() - t0);
  return result;
}
