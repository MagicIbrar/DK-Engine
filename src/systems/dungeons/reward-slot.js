// Forgotten Shipwreck reward roulette: game2/forgottenshipwreck/ui_reward_slotwnd.txt + share/forgottenshipwreck/rewardslot.csv.
// rewardslot.csv has one row per team (`win` = cleared, `lose` = failed): `count`, then index/vlaue/rate triples. The rates of
// each row sum to exactly 1,000,000 (win: 11 slots, lose: 8 slots) and the window has ONE result label (lbl_result_rullet), so a
// spin picks ONE slot weighted by its rate (the same rule as the offline roulette in src/systems/events/staged.js). Shared by the
// client dungeon director (src/systems/dungeons/index.js) and the host (server/world/dungeons.mjs).
/** One weighted slot of a [[item, count, rate], ...] reward list, as [item, count, rate]; null when the list has no slot. */
export function pickRewardSlot(list, random = Math.random) {
  const rows = (Array.isArray(list) ? list : []).filter((r) => Number(r?.[0]) > 0 && Number(r?.[2]) > 0);
  const sum = rows.reduce((a, r) => a + Number(r[2]), 0);
  if (!sum) return null;
  let roll = Number(random()) * sum;
  let row = rows[rows.length - 1];
  for (const r of rows) { roll -= Number(r[2]); if (roll < 0) { row = r; break; } }
  return [Number(row[0]), Math.max(1, Number(row[1]) || 1), Number(row[2])];
}