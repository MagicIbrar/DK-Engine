// Native option identities, without changing numeric codes, labels or stored values.
// Evidence is checked against the original COM cate 200, itemoption.dat/CSV joins,
// itemdesc cate 502 and status.csv by test-native-option-identities.mjs.
// Caption comments are not enum names (e.g. 325/328 both became "All").
const identities = [
  [22, 'MP_DECREASE_SPENDRESOURCE', ['MP_RESERVED_6']],
  [53, 'RATING_ANTI_STATUS_ADD', ['RATING_RESERVED_5']],
  [176, 'RESIST_DISTANCE_MELEEDAMAGE'],
  [177, 'RESIST_DISTANCE_RANGEDAMAGE'],
  [193, 'PC_DAMAGE_DAMAGE_ADD', ['DAMAGE_ADD']],
  [194, 'PC_DAMAGE_DAMAGE_MUL', ['DAMAGE_MUL']],
  [195, 'PC_DAMAGE_ARMOR_ADD', ['ARMOR_ADD']],
  [196, 'PC_DAMAGE_ARMOR_MUL', ['ARMOR_MUL']],
  [197, 'PC_DAMAGE_FIRERESIST_ADD', ['FIRERESIST_ADD']],
  [198, 'PC_DAMAGE_FIRERESIST_MUL', ['FIRERESIST_MUL']],
  [199, 'PC_DAMAGE_ICERESIST_ADD', ['ICERESIST_ADD']],
  [200, 'PC_DAMAGE_ICERESIST_MUL', ['ICERESIST_MUL']],
  [201, 'PC_DAMAGE_CURSERESIST_ADD', ['CURSERESIST_ADD']],
  [202, 'PC_DAMAGE_CURSERESIST_MUL', ['CURSERESIST_MUL']],
  [203, 'PC_DAMAGE_POISONRESIST_ADD', ['POISONRESIST_ADD', 'POSIONRESIST_ADD', 'PC_DAMAGE_POSIONRESIST_ADD']],
  [204, 'PC_DAMAGE_POISONRESIST_MUL', ['POISONRESIST_MUL', 'POSIONRESIST_MUL', 'PC_DAMAGE_POSIONRESIST_MUL']],
  [205, 'PC_DAMAGE_LIGHTNINGRESIST_ADD', ['LIGHTNINGRESIST_ADD', 'LIGHTINGRESIST_ADD', 'PC_DAMAGE_LIGHTINGRESIST_ADD']],
  [206, 'PC_DAMAGE_LIGHTNINGRESIST_MUL', ['LIGHTNINGRESIST_MUL', 'LIGHTINGRESIST_MUL', 'PC_DAMAGE_LIGHTINGRESIST_MUL']],
  [207, 'PC_DAMAGE_ALLMAGICRESIST_ADD', ['ALLMAGICRESIST_ADD']],
  [208, 'PC_DAMAGE_ALLMAGICRESIST_MUL', ['ALLMAGICRESIST_MUL']],
  [209, 'PC_DAMAGE_ALLPHYSICSRESIST_ADD', ['ALLPHYSICSRESIST_ADD']],
  [210, 'PC_DAMAGE_ALLPHYSICSRESIST_MUL', ['ALLPHYSICSRESIST_MUL']],
  [294, 'PC_DAMAGE_DARKRESIST_ADD', ['DARKRESIST_ADD']],
  [295, 'PC_DAMAGE_DARKRESIST_MUL', ['DARKRESIST_MUL']],
  [316, 'RESULT_EXP_MUL'],
  [324, 'COMBINE_OPTION_COMBINE_ADD'],
  [325, 'COMBINE_OPTION_COMBINE_MUL'],
  [326, 'COMBINE_OPTION_COMBINE_SUB'],
  [327, 'STATUS_EX_MONSTER_TOLERANCE_DOWN'],
  [328, 'STATUS_EX_CRITICAL_RESIST_DOWN'],
  [329, 'POWER_UP_RATE'],
  [331, 'STATUS_EX_SPEED_SKILL_MUL', ['STATUS_EX2_SPEED_SKILL_MUL']],
  [332, 'STATUS_EX_COMPETENCE', ['STATUS_EX2_COMPETENCE']],
  [334, 'DAMAGERATE_EX_CRITICAL_SUB'],
  [337, 'PVPDAMAGE_PVP_DAMAGE_ADD', ['PVP_DAMAGE_ADD']],
  [338, 'PVPDAMAGE_PVP_DAMAGE_MUL', ['PVP_DAMAGE_MUL']],
  [339, 'PVPDAMAGE_PVP_DAMAGERATE_ADD', ['PC_DAMAGERATE_ADD']],
  [340, 'ANTI_ANTI_SUB'],
  [341, 'ANTI_ANTI_RATE'],
  [342, 'PENETRATE_PHYSICAL', ['PHYGICAL', 'PHYGICAL PENENTRATE']],
  [343, 'PENETRATE_MAGICAL', ['MAGICAL', 'MAGICAL PENETRATE']],
];

export const NATIVE_OPTION_IDENTITIES = Object.freeze(identities.map(([code, name, aliases = []]) =>
  Object.freeze({code, name, aliases: Object.freeze(aliases)})));
const byCode = new Map(NATIVE_OPTION_IDENTITIES.map(row => [row.code, row]));
const byName = new Map(NATIVE_OPTION_IDENTITIES.flatMap(row => [row.name, ...row.aliases].map(name => [name, row])));
const itemScopedAliases = new Set(NATIVE_OPTION_IDENTITIES.filter(row =>
  (row.code >= 193 && row.code <= 210) || [294, 295].includes(row.code)).flatMap(row => row.aliases.filter(name => !name.startsWith('PC_DAMAGE_'))));
// COM cate 300:66 and costume_option.csv:38 author this name, but provide no
// numeric cate-200 binding. Keep its own enum; 69 RESERVED_5 remains distinct.
export const NATIVE_SYMBOLIC_OPTION_TYPES = Object.freeze({
  SIZEDAMAGERATE_BOSS_MUL: Object.freeze({name: 'SIZEDAMAGERATE_BOSS_MUL',
    label: 'Increase damage to boss', text: '+ <VALUE>% Increase damage to boss', source: 'stringtable_com.txt 300:66'}),
});

/** Normalize only proven names. Short DK captions require numeric/item-table
 * provenance; a generic status string DAMAGE_ADD/ARMOR_ADD retains its own identity. */
export function normalizeOptionName(name, numericCode = null) {
  if (typeof name !== 'string' || !name.trim()) return null;
  const key = name.trim();
  if (numericCode != null && byCode.has(Number(numericCode))) return byCode.get(Number(numericCode)).name;
  if (itemScopedAliases.has(key)) return key;
  return byName.get(key)?.name || key;
}

/** Numeric identity is authoritative, including the distinct native 176/177 resistance codes. */
export function canonicalOptionName(code, optionTypes = {}) {
  if (Object.hasOwn(NATIVE_SYMBOLIC_OPTION_TYPES, code)) return NATIVE_SYMBOLIC_OPTION_TYPES[code].name;
  const number = Number(code);
  return byCode.get(number)?.name || normalizeOptionName(optionTypes[number]?.name);
}

/** Exact native name/alias -> numeric code; unknown names require a supplied table match. */
export function canonicalOptionCode(name, optionTypes = {}) {
  const canonical = normalizeOptionName(name);
  if (!canonical) return null;
  if (Object.hasOwn(NATIVE_SYMBOLIC_OPTION_TYPES, canonical)) return canonical;
  if (byName.has(canonical)) return byName.get(canonical).code;
  const matches = Object.keys(optionTypes).filter(code => canonicalOptionName(code, optionTypes) === canonical).map(Number);
  return matches.length === 1 ? matches[0] : null;
}

/** Same lookup for costume/crest callers already holding a name -> code Map. No guessed suffix search. */
export function namedOptionCode(names, name) {
  const canonical = normalizeOptionName(name);
  if (!canonical) return null;
  if (Object.hasOwn(NATIVE_SYMBOLIC_OPTION_TYPES, canonical)) return canonical;
  if (byName.has(canonical)) return byName.get(canonical).code;
  const matches = new Set();
  for (const [key, code] of names || []) if (normalizeOptionName(key) === canonical) matches.add(Number(code));
  return matches.size === 1 ? [...matches][0] : null;
}

/** A copied table keeps all native tooltip fields. Raw source tables are never mutated. */
export function normalizeOptionTypes(optionTypes = {}) {
  return {...Object.fromEntries(Object.entries(optionTypes).map(([code, row]) =>
    [code, row ? {...row, name: canonicalOptionName(code, optionTypes)} : row])), ...NATIVE_SYMBOLIC_OPTION_TYPES};
}
