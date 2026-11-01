// Original itemwingdisassemble.csv is already served in items-tables/mounts.
// Global guides 2/65 establish item dismantling with a hammer and wing -> Liberty Essence.
// Only the listed wing's own row may supply the output, quantity bounds and DIL.
export function wingDismantleRule(db, index, tables = db?.T) {
  const def = db?.def?.(Number(index));
  if (def?.slot !== 'wing') return null;
  const rows = (tables?.wingDisassemble?.rows || []).filter(r => Number(r.ItemIndex) === Number(index));
  if (!rows.length) return null;
  const values = row => [row.Output_Item, row.Count_Min, row.Count_Max, row.Need_Dil];
  if (rows.some(row => values(row).some(v => v === '' || v == null))) return null;
  const [item, min, max, dil] = values(rows[0]).map(Number);
  if (![item, min, max, dil].every(Number.isSafeInteger) || item < 1 || min < 0 || max < 1 || max < min || max > 100000 || dil < 0 || dil > 10000000000 || !db.def(item)) return null;
  if (rows.some(row => values(row).some((v, i) => Number(v) !== [item, min, max, dil][i]))) return null;
  return {item, min, max, dil};
}

// ENGINE_CHOSEN: the client supplies inclusive bounds, not the server's weights.
// Equal probability for each bounded integer preserves every original outcome.
export function rollWingDismantleCount(rule, random = Math.random) {
  const dice = random();
  if (!Number.isFinite(dice) || dice < 0 || dice >= 1) throw new Error('Wing dismantling randomness is unavailable.');
  return rule.min + Math.floor(dice * (rule.max - rule.min + 1));
}
