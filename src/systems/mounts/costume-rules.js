// Rules shared by the Transcendence costume windows (win-costume.js) and the authoritative server
// (server/world/item-services.mjs). Pure functions: every number comes from the original tables the caller passes in
// (costumesewing.csv, costume_option.csv, the item option table), nothing is guessed here.

/** Mystical Fabric variants (costumesewing.csv KeyItem_index_1 / _2): the bound one is spent first. */
import {canonicalOptionName,namedOptionCode} from '../items/option-identities.js';
export const FABRIC = [4002291, 4002292];

/** option type name -> code from option tables shaped like items-options.json `optionTypes` / mounts `optionLabels` (first table wins). */
export function optionNameMap(...tables) {
  const byName = new Map();
  for (const table of tables) for (const [code, option] of Object.entries(table || {})) {
    const name = canonicalOptionName(code, table);
    if (name && !byName.has(name)) byName.set(name, Number.isFinite(Number(code)) ? Number(code) : code);
  }
  return byName;
}

/** Preserve exact native enums, including category-qualified PC damage options. */
export function optionCodeByName(byName, name) {
  return namedOptionCode(byName, name);
}

/**
 * Change Options of a Transcendence Costume: three distinct options of costume_option.csv, each weighted 1 / mode
 * (mode 10 = the rare ones). Resolve the original enums rather than comment captions;
 * the boss percentage retains its distinct native symbolic enum. `random()` returns [0, 1).
 */
export function rollCostumeOptions(rows, codeOf, random, count = 3) {
  const pool = (rows || []).filter(row => codeOf(row.option) != null);
  const weight = row => 1 / Math.max(1, Number(row.mode) || 1);
  const picked = [];
  for (let k = 0; k < count && pool.length; k++) {
    let x = random() * pool.reduce((sum, row) => sum + weight(row), 0), chosen = pool[pool.length - 1];
    for (const row of pool) { x -= weight(row); if (x <= 0) { chosen = row; break; } }
    pool.splice(pool.indexOf(chosen), 1);
    picked.push([codeOf(chosen.option), Number(chosen.value)]);
  }
  return picked;
}

/** Sewing succeeds with probability Rate / 1,000,000 (costumesewing.csv Type 0: Rate 50000 = 5 %). */
export const sewingSucceeds = (rate, random) => random() * 1_000_000 < Number(rate);
