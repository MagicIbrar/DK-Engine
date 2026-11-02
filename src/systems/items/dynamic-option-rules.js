// Item Modification (guide Cate 1307/5) — Dynamic Option side.
// Seal: server/world/conversions.mjs operation "seal" + items-tables itemChange + Sealing Powder (type1/code18).
// Dynamic Option pools: gamedata/life_rebirth.json (Grade.rebirthOptions / changeOption).
// Carmen option craft/remove: enhancement.mjs craft "option" / "removeoption".
// optionchange.csv is a 5-row material recipe for specific Mone Bloodbane pieces only.
// Dynamic Option material costs (scan-fix 2026-10-29): GLOBAL. Global's help text (script/string/item/stringtable_itemupgrade.txt
// code 66) says "The required materials for changing dynamic options vary depending on the item", and the client's
// Load::OptionChange / LogicObject::OptionChange::Version0_1 loaders read share/item/optionchange/. Its per-item material
// table is share/item/optionchange/optionchange.csv (TargetItemIndex, then 3 x [material index, count]) - 5 rows
// (44500-44540). That file has no DIL column, so dil is 0 for those rows. The other optionchange/*.csv files are option
// ranges/revisions (itemoption_*_<class>, *_optionrevision, *grade, changeoption_matchtable, oldoptionlist), not costs.
// ENGINE-DEFAULT (configurable): an item with no optionchange.csv row gets no material recipe (ok:false). Sources searched:
// all Global share/ + script/ csv/txt (rebirth, optionchange, itemoptionupgrade), client decompile (OptionChange, rebirth,
// DynamicOption: no other table), server-ref share/rebirth (changeoption + 2 option pools only).

export const DYNAMIC_OPTION_COST = Object.freeze({
  status: 'GLOBAL',
  source: 'share/item/optionchange/optionchange.csv',
  reason: 'Items without an optionchange.csv row: ENGINE-DEFAULT (configurable) - Global ships no recipe for them.',
});

export const BRAND_DIL_COST = Object.freeze({
  status: 'UNRESOLVED',
  reason: 'Help text names Brand Cost (DIL) but share/item ships no brand/incuse price column; wing/costume dismantle Need_Dil only.',
});

export const DISASSEMBLE_DIL_COST = Object.freeze({
  status: 'UNRESOLVED',
  reason: 'Help text names Disassembly Cost (DIL) for weapons/armor; itemdisassemble.csv has no DIL column (wing/costume tables do).',
});

/** Parse items-legacy / optionchange.csv rows into { targetIndex, materials:[{index,count},...] }. */
export function parseOptionChangeRows(rows) {
  if (!Array.isArray(rows)) return [];
  return rows.map((row) => {
    const targetIndex = Number(row.c0 ?? row.TargetItemIndex ?? row[0]);
    const materials = [];
    const pairs = [
      [row.c1 ?? row[1], row.c2 ?? row[2]],
      [row.c3 ?? row[3], row.c4 ?? row[4]],
      [row.c5 ?? row[5], row.c6 ?? row[6]],
    ];
    for (const [idx, cnt] of pairs) {
      const index = Number(idx); const count = Number(cnt);
      if (Number.isSafeInteger(index) && index > 0 && Number.isSafeInteger(count) && count > 0) materials.push({ index, count });
    }
    return { targetIndex, materials };
  }).filter((r) => Number.isSafeInteger(r.targetIndex) && r.targetIndex > 0 && r.materials.length);
}

/** Recipe for a specific item index from optionChange, or null. */
export function optionChangeRecipe(rows, itemIndex) {
  const list = parseOptionChangeRows(rows);
  return list.find((r) => r.targetIndex === Number(itemIndex)) || null;
}

/** Dynamic options available at an item level from life_rebirth armor/weapon pools. */
export function rebirthOptionPool(rebirth, { isWeapon, level }) {
  const grp = (isWeapon ? rebirth?.weapon : rebirth?.armor) || {};
  const rows = grp[level] || grp[String(level)] || [];
  return rows.map((row) => {
    if (Array.isArray(row)) {
      const [index, type, desc, min, max] = row;
      return { index, type, desc, min, max };
    }
    return row;
  });
}

/** Map a legacy option type name through life_rebirth.change for a job (0 = any). */
export function mapChangeOption(rebirth, fromType, job = 0) {
  const list = rebirth?.change || [];
  const row = list.find((c) => c.from === fromType && (Number(c.job) === Number(job) || Number(c.job) === 0));
  return row?.to || null;
}

/**
 * Fail-closed Dynamic Option cost lookup.
 * Returns { ok:true, materials, dil:0 } only for evidenced optionChange recipes;
 * otherwise { ok:false, unresolved:DYNAMIC_OPTION_COST }.
 */
export function dynamicOptionCost(optionChangeRows, itemIndex) {
  const recipe = optionChangeRecipe(optionChangeRows, itemIndex);
  if (!recipe) return { ok: false, unresolved: DYNAMIC_OPTION_COST };
  return { ok: true, materials: recipe.materials, dil: 0, source: 'optionchange.csv' };
}