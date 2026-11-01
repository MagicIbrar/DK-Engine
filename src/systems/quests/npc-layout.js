// Runtime correction for the inferred Ardeca quest NPC ring, not authored NPC rows.
// These plaza rows were checked against the original Ardeca_new.mac. Keep the
// central east/west approach (Z 128-132) open; eligibility never changes slots.
const cache = new WeakMap();
const ROW_Z = [118.5, 122.5, 126.5, 134.5, 138.5];

export function questNpcLayout(source, catalog) {
  if (!source || !catalog) return { quests: source, placements: [] };
  let byCatalog = cache.get(source);
  if (!byCatalog) cache.set(source, byCatalog = new WeakMap());
  if (byCatalog.has(catalog)) return byCatalog.get(catalog);
  const anchor = catalog.placements?.[150]?.rows?.find(r => Number(r[0]) === 5489);
  const authored = new Set((catalog.placements?.[150]?.rows || []).map(r => Number(r[0])));
  const matches = who => anchor && who?.unplaced && Number(who.map) === 150
    && who.posGuess === 'npc:5489' && Array.isArray(who.pos)
    && Math.hypot(Number(anchor[1]) - 336.933, Number(anchor[2]) - 129.02) < 0.01
    && Math.hypot(Number(who.pos[0]) - anchor[1], Number(who.pos[1]) - anchor[2]) < 4.1
    && catalog.npcs?.[who.npc] && !authored.has(Number(who.npc));
  const ids = [...new Set(Object.values(source.quests || {}).filter(q => q && !q.isGroup).flatMap(q => [q.giver, q.turnIn])
    .filter(matches).map(who => Number(who.npc)))].sort((a, b) => a - b);
  // This correction covers the existing cluster only, with no overflow pile.
  const placements = ids.length <= 50 ? ids.map((npcIndex, i) => ({
    // World Tree Messenger's native mesh spans 12.38 by 13.72 cells and
    // cannot share the smaller actors' three-cell slots.
    npcIndex, x: npcIndex === 5882 ? 303.5 : 312.5 + (i % 10) * 3,
    z: npcIndex === 5882 ? 145.5 : ROW_Z[Math.floor(i / 10)], dirDeg: 180,
  })) : [];
  const positions = new Map(placements.map(p => [p.npcIndex, p]));
  const quests = {};
  for (const [id, q] of Object.entries(source.quests || {})) {
    let next = q;
    for (const key of ['giver', 'turnIn']) {
      const who = q?.[key], p = matches(who) && positions.get(Number(who.npc));
      if (p) next = { ...next, [key]: { ...who, pos: [p.x, p.z], dir: p.dirDeg } };
    }
    quests[id] = next;
  }
  const result = { quests: placements.length ? { ...source, quests } : source, placements };
  byCatalog.set(catalog, result);
  return result;
}
