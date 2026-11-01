// Native turn-in custody the prepared catalogue misses. The builder resolves a journal's completion NPC only from an
// [nlink] id; quest 9763 "Dungeon Master" names it in plain text (string 12: "Completed NPC" / "Eva Riana"), so the
// catalogue has no turn-in and the reward could be claimed anywhere. Bind it to the single original NPC of that exact
// name (5401, placed on map 156) only while every original fact still matches; otherwise the catalogue is unchanged.
const BINDINGS = [{ quest: 9763, npc: 5401, name: 'Eva Riana', map: 156, journal: /Completed NPC\s*(?:<[^>]*>\s*)*Eva Riana\s*(?:\r?\n|$)/ }];

export function nativeQuestCustody(quests, dialogs, game) {
  const npcs = game?.data?.npcs;
  let out = quests;
  for (const b of BINDINGS) {
    const q = quests?.quests?.[b.quest], journal = String(dialogs?.strings?.[b.quest]?.[12] ?? '');
    if (!q || q.isGroup || q.turnIn || q.giver || !b.journal.test(journal)) continue;
    if (String(npcs?.npcs?.[b.npc]?.name ?? '').trim() !== b.name) continue;
    if (Object.values(npcs.npcs).filter(n => String(n?.name ?? '').trim() === b.name).length !== 1) continue;
    const row = (npcs.placements?.[b.map]?.rows || []).find(r => Number(r[0]) === b.npc);
    if (!row) continue;
    const turnIn = { npc: b.npc, name: b.name, map: b.map, pos: [Number(row[1]), Number(row[2])], dir: Number(row[3]) || 0, inferred: 'journalName' };
    out = { ...out, quests: { ...out.quests, [b.quest]: { ...q, turnIn } } };
  }
  return out;
}
export const NATIVE_QUEST_CUSTODY = BINDINGS;
