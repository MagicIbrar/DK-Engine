// Spike when you transform with Trans Up. Measured in the real client (test-client Trans Up run,
// the first Barad cast in third person): a 401-882 ms frame plus 120-370 ms frames with only 6-10 ms inside renderer.render -
// the transform body's model load and clip resolve, and the D3D11 shader build on its first draw. At the map load (game.js
// _warmUp, under the loading screen) the Trans Up looks of the skills this character has learned are loaded through the same
// model cache key the swap uses (hooks.js Player.partDefs: one part {meshKey, tpackKey, textures: null}), their clips resolved,
// their shaders compiled and drawn once with colour / depth locked (engine/warm-draw.js). The cast then swaps to a warm body.
import { applyShadeTree } from '../../world/shade.js';
import { queueWarmDraw, drawWithWorldLights } from '../../engine/warm-draw.js';
import { prewarmFirstPersonLook } from '../../engine/native-first-person-presentation.js';

/** Distinct transform looks {mesh, tpack} of the Trans Up skills the player has learned (rows up to the learned level, the highest first). */
export function learnedTransformLooks(game, max = 3) {
  const learned = game?.save?.skills || {}, out = new Map();
  for (const [id, level] of Object.entries(learned)) {
    const rows = game.skills?.skillDef?.(Number(id))?.transform;
    if (!Array.isArray(rows) || !(Number(level) > 0)) continue;
    for (const row of [...rows].sort((a, b) => Number(b?.level) - Number(a?.level))) {
      const look = row?.shapeshift;
      if (!look?.mesh || !(Number(row.level) <= Number(level))) continue;
      const key = `${String(look.mesh).toLowerCase()}|${String(look.tpack || '').toLowerCase()}`;
      if (!out.has(key)) out.set(key, { mesh: look.mesh, tpack: look.tpack || null });
    }
  }
  return [...out.values()].slice(0, max);
}

/** Load + resolve clips + compile each learned transform look; with `draw` (map load only) also one locked draw. Resolves the count. */
export async function prewarmTransformLooks(game, { draw = false } = {}) {
  const p = game?.player, models = game?.models;
  if (!p?.classDef?.skeleton || typeof models?.loadSkinned !== 'function' || p.disposed) return 0;
  let warmed = 0;
  for (const look of learnedTransformLooks(game)) {
    const model = await models.loadSkinned({ skelKey: p.classDef.skeleton, parts: [{ meshKey: look.mesh, tpackKey: look.tpack || null, textures: null }] });
    if (!model?.instantiate || p.disposed || game.player !== p) continue;
    await p._preloadAnims?.(model, p.anims);
    const inst = model.instantiate();
    // the world gives every actor material the sun fall-off patch (world.js / shade.js): the same programs as the real body
    applyShadeTree(inst.root);
    if (typeof game.renderer?.compileAsync === 'function' && game.scene && game.camera) await game.renderer.compileAsync(inst.root, game.camera, game.scene);
    if (draw) queueWarmDraw(game, () => { try { drawWithWorldLights(game, [inst.root]); } finally { inst.dispose(); } });
    else inst.dispose();
    // and its first-person arm / body variants (a transform in first person: 443 ms frame without, test-client Trans Up run)
    await prewarmFirstPersonLook(game, model, { draw }).catch(error => console.warn('[skills] first-person Trans Up pre-build failed', error));
    warmed++;
  }
  return warmed;
}
