// Level-difference ability caps (MAP-CAPS): share/maplist.csv StrAbilityCapPath -> share/pc/abilitycap*.csv
// (AbilityCap.csv on 134 maps, AbliityCap_Indun_01.csv on 144, Colosseum 15, Qune Temple, Kastrioti, Lost Horizon, Siz,
// Braiken broken). Columns: Level Cap, then the same seven names twice - Melee Decrease Rate, Magic Decrease Rate,
// Elemenet Decrease Rate, All Resist Rate, Miss Rate, Blocking Rate, Guard Rate.
// Reading (the file does not label the two blocks): column 0 is the level difference DEFENDER - ATTACKER (+250 .. -250,
// 0 at an equal level, rates rising with the gap). Block 1 = a character attacking a monster: a much stronger monster cuts
// the character's melee / magic damage by up to 30 % and adds up to 25 % misses, a much weaker one raises it. Block 2 =
// a monster attacking a character: against a much stronger character its damage drops (37.5 % melee / 75 % magic),
// against a much weaker one it rises (up to 9x at -250). Applied: the melee / magic decrease and the miss rate; the
// element, all-resist, blocking and guard columns have no server mechanic to scale yet.
export const CAP_COLUMNS = ['melee', 'magic', 'element', 'resist', 'miss', 'blocking', 'guard'];

/** Parse an ability cap CSV (rows of numbers) into {byDiff: Map(diff -> row), allZero}. */
export function abilityCapTable(rows) {
  const byDiff = new Map();
  let allZero = true;
  for (const r of rows || []) {
    const v = r.map(Number);
    if (!Number.isFinite(v[0]) || v.length < 15) continue;
    byDiff.set(Math.round(v[0]), v);
    if (v.slice(1).some(x => x !== 0)) allZero = false;
  }
  return byDiff.size ? { byDiff, allZero } : null;
}

/** The capped modifiers for an attack: {damageMul, miss} (block 1 = player attacker, block 2 = monster attacker). */
export function abilityCapFor(table, { attackerLevel, defenderLevel, attackerIsPlayer, kind = 'melee' }) {
  if (!table || table.allZero) return { damageMul: 1, miss: 0 };
  const diff = Math.max(-250, Math.min(250, Math.round((Number(defenderLevel) || 1) - (Number(attackerLevel) || 1))));
  const row = table.byDiff.get(diff);
  if (!row) return { damageMul: 1, miss: 0 };
  const o = attackerIsPlayer ? 1 : 8;
  const rate = kind === 'magic' ? row[o + 1] : row[o];
  return { damageMul: Math.max(0, 1 - (Number(rate) || 0) / 100), miss: Math.max(0, Number(row[o + 4]) || 0) };
}

/** Apply to a damage amount; returns {amount, miss}. rand() in [0, 1). */
export function applyAbilityCap(table, attack, amount, rand = Math.random) {
  const c = abilityCapFor(table, attack);
  if (c.miss > 0 && rand() * 100 < c.miss) return { amount: 0, miss: true };
  return { amount: c.damageMul === 1 ? amount : Math.max(1, Math.round(amount * c.damageMul)), miss: false };
}
