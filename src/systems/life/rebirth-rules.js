// Dynamic Option ("Rebirth") table helpers - share/rebirth -> gamedata/life_rebirth.json.
// Global UI strings (stringtable_itemupgrade 55-67): "Dynamic Option" / "Change Dynamic Option" re-rolls all
// 4 option values at once; materials "vary depending on the item" (Theos Fragments + DIL mentioned in 223-225).
// UNRESOLVED (no invented values): prepared Global data has no CSV mapping item -> material counts / DIL cost,
// and no dedicated window script beyond OptionUpgrade imagetable DynamicOption sprites. Lookups below are the
// authored pools + changeoption rename map only. Do not invent purchase costs or an NPC procedure.
//
// changeoption.csv: legacy option type name -> new type name (optional job filter).
// itemoption_armor.csv / itemoption_weapon.csv: per item-level pools [index, type, desc, min, max].

/** @typedef {{ from: string, type: number, code: number, job: number, to: string }} ChangeRow */
/** @typedef {[number, string, string, number, number]} PoolRow */

export const REBIRTH_UNRESOLVED = Object.freeze({
  materialCosts: 'Per-item materials come from share/item/optionchange/optionchange.csv (dynamic-option-rules.js dynamicOptionCost; Global help code 66). Items without a row: ENGINE-DEFAULT (configurable), no Global recipe. No DIL column exists in Global.',
  windowProcedure: 'No ui_*dynamic* script; DynamicOption sprites sit under OptionUpgrade imagetable. Do not invent a separate window or costs.',
});

/** Options available when re-rolling a weapon or armor at the given item level. */
export function rebirthOptionsAt(data, isWeapon, level) {
  if (!data) return [];
  const grp = (isWeapon ? data.weapon : data.armor) || {};
  const key = String(Number(level) || 0);
  const rows = grp[key] || grp[level] || [];
  return rows.map(([index, type, desc, min, max]) => ({
    index: Number(index),
    type: String(type),
    desc: String(desc || ''),
    min: Number(min),
    max: Number(max),
  }));
}

/** Map a legacy option type through changeoption.csv for a class job (0 = any). */
export function changeOptionType(data, fromType, job = 0) {
  if (!data?.change?.length || fromType == null) return null;
  const j = Number(job) || 0;
  const row = data.change.find((c) => c.from === fromType && (Number(c.job) === j || Number(c.job) === 0));
  return row?.to || null;
}

/** Pick one pool entry at random; value is inclusive [min, max]. rng() -> [0,1). */
export function rollDynamicOption(pool, rng = Math.random) {
  if (!pool?.length) return null;
  const r = typeof rng === 'function' ? rng() : Math.random();
  const entry = pool[Math.min(pool.length - 1, Math.floor(Math.max(0, r) * pool.length))];
  const lo = Number(entry.min), hi = Number(entry.max);
  const a = Math.round(Math.min(lo, hi)), b = Math.round(Math.max(lo, hi));
  const t = typeof rng === 'function' ? rng() : Math.random();
  const value = a + Math.floor(Math.max(0, Math.min(0.999999, t)) * (b - a + 1));
  return { index: entry.index, type: entry.type, desc: entry.desc, min: a, max: b, value };
}

/** Re-roll four option slots from the same level pool (Global: all 4 change at once). */
export function rollDynamicOptionSet(pool, count = 4, rng = Math.random) {
  const n = Math.max(0, Number(count) || 0);
  const out = [];
  for (let i = 0; i < n; i++) {
    const one = rollDynamicOption(pool, rng);
    if (!one) break;
    out.push(one);
  }
  return out;
}
