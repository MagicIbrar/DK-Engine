// Generated entrance gates need an actual entrance body. NPC4001 is an
// invisible interaction placeholder, not the generic visible dungeon model.
// Original placed NPCs, hidden stairs and quest actors keep their source shape.
export function npcPresentation(npc, catalog) {
  const def = npc.def || {};
  const original = {
    shape: catalog.shapes?.[def.shape] || null,
    actionSet: def.act ? catalog.actionSets?.[def.act] || null : null,
    static: !!def.static,
  };
  // Dora's placed shape row points at npc_hidden.dds, while her original
  // NPC_DOLA mesh, texture pack, skeleton and stand clip are all shipped.
  // Restore that authored body without changing her crafting/quest identity.
  if (Number(def.index) === 5715 && def.shape === 'dola') return {
    ...original,
    shape: { mesh:'mesh/npc/npc_dola.mesh', tpack:'texturepack/npc/npc_dola.tpack' },
    fallback:original,
  };
  const generated = npc.entryGate || def.entryGate || npc.sharedDungeonIds?.length;
  if (!generated || !['potal_enter', 'tomb_stone', 'npc_d_potalstone'].includes(def.shape)) return original;
  // Crespo's authored entrance uses this visible shape and the same action
  // table already borrowed by4001. Select source metadata, never recolor the
  // placeholder's intentionally transparent npc_hidden texture.
  const entrance = catalog.npcs?.[1208];
  const shape = catalog.shapes?.[entrance?.shape];
  const actionSet = catalog.actionSets?.[entrance?.act];
  if (entrance?.shape !== 'in_gate' || !shape?.mesh || !shape.textures?.diffuse?.some(Boolean)) return original;
  return { shape, actionSet: actionSet || original.actionSet, static: !!entrance.static,
    sourceNpc: 1208, reason: 'generated-dungeon-entrance', fallback: original };
}
