// Weapon appearance (NPC Ian, job 110 CHANGESHAPE_JOB, window game2/changeshapewnd/changeshapewnd.txt): the rules shared by the
// host service (server/world/ian-appearance.mjs), its window (items/ui/weapon-look.js), the look builder (equip.js weaponView)
// and the host's public look rows (server/world/battle-looks.mjs). Native data only:
//   * a material is item type 0 code 64 "Cash Appearance Change Materials" or code 65 "Normal Appearance Change Materials"
//     (items.json enums.kindNames 64 / 65; the current item tables carry code 64 rows only);
//   * its value1 is the code of the weapon (item type 4) it applies to, value2 the duration in seconds;
//   * the look is the material's OWN item_shape row (items-visual.json shapes[shape]: game / left meshes, model effects), its
//     action table (items-actions.json item[action]) and its weapon_left.csv row;
//   * the DIL cost is share/system_variable.csv 21 (cash material, 0) or 22 (normal material, 1,000,000).
// The weapon instance keeps `appearance` (the material item index) and `appearanceExpiresAt` (ms). Its own stats, options,
// sockets and upgrade grade are never changed. A row without `appearanceExpiresAt` (a public look row) carries no timer.
const n = v => Number(v);
/** Material code -> share/system_variable.csv Index of its DIL cost. */
export const COST_VARIABLE = Object.freeze({ 64: 21, 65: 22 });
/** Native strings of the window and the service (SYSTEM 101 = stringtable_system, NORMAL 40 / 1001 / 2000 = stringtable_pc /
 *  stringtable_itemupgrade / stringtable_button) with the Global text as the fallback. */
export const WEAPON_LOOK_TEXT = Object.freeze({
  title: ['SYSTEM', 101, 199, 'Change Weapon appearance'],
  cost: ['SYSTEM', 101, 202, '%d'],
  success: ['SYSTEM', 101, 203, 'You have successfully changed the weapon appearance.'],
  expired: ['SYSTEM', 101, 204, 'Weapon appearance change period is expired.'],
  reset: ['SYSTEM', 101, 205, 'Appearance Reset'],
  caution: ['SYSTEM', 101, 206, 'Caution'],
  remove: ['SYSTEM', 101, 207, 'Would you like to delete [TARGET_ITEM] appearance ?\\Deleted appearance cannot be retrieved.'],
  dil: ['SYSTEM', 101, 229, '[message] Not enough DIL.'],
  mismatch: ['NORMAL', 40, 57, 'You do not meet the requirement to register this item (level, class, etc.).'],
  missing: ['NORMAL', 1001, 118, 'The item cannot be found.'],
  unusable: ['NORMAL', 1001, 185, 'This item cannot be used.'],
  material: ['NORMAL', 1001, 260, 'You do not have enough material items.'],
});

/** `def` when it is a weapon appearance material (type 0, code 64 / 65), else null. */
export function appearanceMaterial(def) { return def && n(def.type) === 0 && Object.hasOwn(COST_VARIABLE, n(def.code)) ? def : null; }
/** The native type match: the material's value1 is the weapon's own code. */
export function materialFits(material, weapon) {
  return !!appearanceMaterial(material) && !!weapon && n(weapon.type) === 4 && Number.isSafeInteger(n(material.value1)) && n(material.value1) === n(weapon.code);
}
/** The material's duration (value2) in seconds, or null. */
export function materialSeconds(material) { const s = n(material?.value2); return appearanceMaterial(material) && Number.isSafeInteger(s) && s > 0 ? s : null; }
/** DIL cost of one change with this material from share/system_variable.csv rows (Index -> Variable), or null when absent. */
export function appearanceCost(material, variables) {
  const index = appearanceMaterial(material) ? COST_VARIABLE[n(material.code)] : null;
  const v = index == null ? null : variables instanceof Map ? variables.get(index) : variables?.[index];
  return v != null && v !== '' && Number.isSafeInteger(n(v)) && n(v) >= 0 ? n(v) : null;
}
/** share/system_variable.csv rows ([[Index, Variable, Desc], ...] or objects) -> Map(Index -> Variable). */
export function systemVariables(rows) {
  const out = new Map();
  for (const r of rows || []) {
    const index = n(Array.isArray(r) ? r[0] : r?.Index), value = Array.isArray(r) ? r[1] : r?.Variable;
    if (Number.isSafeInteger(index) && value != null && String(value).trim() !== '') out.set(index, n(value));
  }
  return out;
}
/** True while a timed appearance still runs (rows without a timer count as running). */
export function appearanceRunning(inst, now = Date.now()) {
  if (inst?.appearanceExpiresAt == null) return true;
  const at = n(inst.appearanceExpiresAt);
  return Number.isFinite(at) && at > now;
}
/** The material item index the instance of a worn weapon draws now, or 0 (no / expired / non-matching appearance). */
export function activeAppearance(db, inst, now = Date.now()) {
  const index = n(inst?.appearance);
  if (!Number.isSafeInteger(index) || index <= 0 || !appearanceRunning(inst, now)) return 0;
  return materialFits(db?.def?.(index), db?.def?.(inst.itemIndex)) ? index : 0;
}
/** An instance whose timed appearance has run out (the host clears it; the client announces 101:204). */
export function appearanceExpired(inst, now = Date.now()) {
  return n(inst?.appearance) > 0 && inst.appearanceExpiresAt != null && !appearanceRunning(inst, now);
}
/** The look of a material in the shape the weapon view uses: {index, asset, left, action, leftItem, leftAction} from its own
 *  item_shape row, action table and weapon_left.csv row; null when the shape has no equipped mesh. */
export function materialLook(db, index) {
  const def = appearanceMaterial(db?.def?.(index)), shape = def ? db.shape?.(def) : null;
  if (!shape?.game?.mesh) return null;
  const leftItem = n(db.equipment?.weaponLeft?.[def.index]) || null;
  const leftAction = leftItem ? (db.look?.(leftItem)?.action ?? db.def(leftItem)?.action ?? null) : null;
  return { index: def.index, asset: shape.game, left: shape.left || null, action: n(def.action) || null, leftItem, leftAction: n(leftAction) || null };
}
