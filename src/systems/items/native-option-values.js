import {normalizeOptionName} from './option-identities.js';

// Native status descriptions prove tenths for these option families. Keep the
// authored value in the item/save; only gameplay and displayed percentages scale.
const TENTHS=new Set(['PENETRATE_PHYSICAL','PENETRATE_MAGICAL','ANTI_ANTI_RATE','SIZEDAMAGERATE_BOSS_MUL']);
export function optionDisplayValue(type,value,db) {
  const name=normalizeOptionName(db?.optionName?.(type)||String(type));
  return Number(value)/(TENTHS.has(name)?10:1);
}
