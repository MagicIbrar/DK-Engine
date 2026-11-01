import { ITEM_GRADE_COLORS, dilColor } from '../../ui/item-colors.js';

// Color the reward value, not the whole system line. These are the authored
// stringtable_color item/DIL colors already used by item links and DIL labels.
export function itemPickupText(template, name, count = 1, grade = 'normal') {
  const color = (ITEM_GRADE_COLORS[grade] || ITEM_GRADE_COLORS.normal).slice(1);
  const value = `${name}${count > 1 ? ` x${Math.round(count).toLocaleString('en-US')}` : ''}`;
  return String(template).replace('<VALUE>', `<color=${color}>${value}</color>`);
}

export function dilPickupText(template, amount) {
  const value = Math.round(Number(amount) || 0);
  return String(template).replace('%lld', `<color=${dilColor(value).slice(1)}>${value.toLocaleString('en-US')}</color>`);
}
