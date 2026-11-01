// The original guide recommendation and server acceptance window are distinct.
// Starter rows reuse listLevel=1, while questnotice.csv advances 1,5,10,12,20.
// Present that authored recommendation without changing when a quest can be accepted.
const positive = value => Number.isFinite(Number(value)) && Number(value) > 0 ? Math.floor(Number(value)) : null;
const recommendations = new WeakMap();

function guideLevel(q, catalog) {
  if (!catalog || typeof catalog !== 'object') return null;
  let levels = recommendations.get(catalog);
  if (!levels) {
    levels = new Map();
    for (const row of catalog.notices || []) if (positive(row.level)) levels.set(Number(row.quest), positive(row.level));
    recommendations.set(catalog, levels);
  }
  return levels.get(Number(q?.id)) || null;
}

export function questLevelRange(q) {
  return {
    min: Math.max(positive(q?.level?.[0]) || 1, positive(q?.require?.level) || 1),
    max: positive(q?.level?.[1]) || 250,
  };
}

export function questDisplayLevel(q, catalog) {
  const { min, max } = questLevelRange(q);
  return Math.max(min, Math.min(max, guideLevel(q, catalog) || positive(q?.listLevel) || min));
}

export function questLevelTag(q, catalog) { return `[Lv.${questDisplayLevel(q, catalog)}]`; }

export function questLevelRequirement(q, catalog) {
  const { min, max } = questLevelRange(q);
  const required = `Required level: ${max < 250 ? `${min}–${max}` : `${min}+`}`;
  return catalog ? `Recommended level: ${questDisplayLevel(q, catalog)}\n${required}` : required;
}
