import { NPC_MODEL_LANES } from '../config/engine-chosen-loading.js';
import { npcPresentation } from '../actors/npc-presentation.js';

// ENGINE-CHOSEN scheduling only: four shared-model loads overlap terrain/object
// loading without creating actors, scene groups, or animation instances.
export async function prewarmNpcModels(models, catalog = {}, placements = [], focus = null) {
  if (!models) return { requested: 0, failures: [] };
  const jobs = new Map(), failures = [];
  for (const placement of placements) {
    const def = catalog.npcs?.[placement.npcIndex];
    if (!def) continue;
    const presentation = npcPresentation({ def: { index: placement.npcIndex, ...def } }, catalog);
    for (const body of [presentation, presentation.fallback].filter(Boolean)) {
      const shape = body.shape, set = body.actionSet;
      if (!shape?.mesh) continue;
      const part = { meshKey: shape.mesh, tpackKey: shape.tpack || null, textures: shape.textures || null };
      const skinned = !!(set?.skel && !body.static);
      const input = skinned ? { skelKey: set.skel, parts: [part] }
        : { mesh: shape.mesh, tpackKey: part.tpackKey, textures: part.textures };
      const key=JSON.stringify([skinned,input]);
      const distance=focus?(Number(placement.x)-Number(focus.x))**2+(Number(placement.z)-Number(focus.z))**2:0;
      const prior=jobs.get(key);
      if(!prior||distance<prior.distance)jobs.set(key,{skinned,input,distance});
    }
  }
  const work = [...jobs.values()].sort((a,b)=>a.distance-b.distance);
  let cursor = 0;
  await Promise.all(Array.from({ length: Math.min(NPC_MODEL_LANES, work.length) }, async () => {
    while (cursor < work.length) {
      const { skinned, input } = work[cursor++];
      try {
        if (skinned) await models.loadSkinned(input);
        else await models.loadStatic(input.mesh, { tpackKey: input.tpackKey, textures: input.textures });
      } catch (error) { failures.push(String(error?.message || error)); }
    }
  }));
  return { requested: work.length, failures };
}
