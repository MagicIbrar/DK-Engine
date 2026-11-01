// NPC point resets (stringtable_jobtype 200): job 7 "[Skill Reset] Reset my skills.", 120 "[Attribute Reset] Reset my
// attributes.", 13 "[Stat Reset] Reset my stats.". Shared by the local game (skills/ui-skillwnd.js msgbox/ui_skillreset and
// msgbox/ui_statreset, opened by the quests/index.js NPC services) and the shared server (server/world/point-resets.mjs).
//   costs  share/pc/exp.csv per character level: ClearCount_1..5 = DIL of the 1st..5th skill / attribute reset (later resets
//          keep the 5th price), StatClearCost_1..2 = DIL of the stat resets.
//   stats  one NPC stat reset per StatClearCost column (stringtable_skill 60:38 "Available stat rests: <VALUE>times"); after
//          them only the Regenerator items reset stats (stringtable_helper "Stat Reset": "You can reset Stats by using
//          Regenerator Item after the initial reset."). Every worn item comes off first (60:36 "You must unequip all equipment
//          to reset.", 60:40 "Notice: Please unequip the item before trying.").
// Rows come either from the raw csv (fetchCSVObjects: ClearCount_1) or from gamedata exp.json (tools/build-characters.mjs
// lower-cases the first letter: clearCount_1); both spellings are read.
export const RESET_JOBS = Object.freeze({ skill: 7, attribute: 120, stat: 13 });
export const RESET_COUNTS = Object.freeze({ skill: 'skillResets', attribute: 'attrResets', stat: 'statResets' });
export const STAT_KEYS = Object.freeze(['str', 'dex', 'con', 'spr']);
const SKILL_PRICES = 5;
/** stringtable_skill (cate 60) codes of the reset boxes and their answers. */
export const RESET_MSG = Object.freeze({
  skillAsk: 29, skillDone: 31, skillNone: 33, attrAsk: 67, attrDone: 70, attrNone: 71,
  statAsk: 35, statEquipped: 36, statDone: 37, statLeft: 38, statCost: 39, statNotice: 40, noDil: 46,
});
// ENGINE-CHOSEN: the client tables have no line for a stat reset with no spent point; the reset (and its count) is kept.
export const STAT_NOTHING_TEXT = 'There are no stat points to reset.';

const num = v => (Number.isFinite(+v) ? +v : 0);
const col = (row, name) => { const v = row?.[name] ?? row?.[name.charAt(0).toLowerCase() + name.slice(1)]; return v === '' ? undefined : v; };

export function resetsUsed(save, kind) { return Math.max(0, Math.floor(num(save?.[RESET_COUNTS[kind]]))); }
/** NPC stat resets a character has in all: the StatClearCost_n columns of its level row. */
export function statResetLimit(row) { let n = 0; while (col(row, `StatClearCost_${n + 1}`) !== undefined) n++; return n; }
export function statResetsLeft(row, used) { return Math.max(0, statResetLimit(row) - used); }
/** DIL of the next reset of `kind` after `used` ones. */
export function pointResetCost(row, kind, used) {
  if (kind === 'stat') return num(col(row, `StatClearCost_${Math.max(1, Math.min(statResetLimit(row), used + 1))}`));
  return num(col(row, `ClearCount_${Math.min(SKILL_PRICES, used + 1)}`));
}
/** Does the active preset wear anything (the reserve weapon pair 104 / 105 and the sub costume 114 are not worn)? */
export function wearsEquipment(equip) {
  const preset = equip?.presets?.[Number(equip.active) || 0] || {};
  return Object.entries(preset).some(([slot, uid]) => Number(slot) < 100 && uid && equip.items?.[uid]);
}
export function returnedStatPoints(stats, base) {
  let back = 0;
  for (const k of STAT_KEYS) back += Math.max(0, num(stats?.[k]) - num(base?.[k]));
  return back;
}
/**
 * Checks and applies one NPC stat reset to a save / profile object (`save.equip` is the equipment record). DIL is left
 * to the caller (the local items system announces it). Returns {back, cost} or {error: 'left' | 'equipped' | 'nothing' |
 * 'dil'}, which leaves the object untouched.
 */
export function applyStatReset(save, { base, row }) {
  if (!base) return { error: 'nothing' };
  const used = resetsUsed(save, 'stat');
  if (statResetsLeft(row, used) <= 0) return { error: 'left' };
  if (wearsEquipment(save.equip)) return { error: 'equipped' };
  const back = returnedStatPoints(save.stats, base);
  if (back <= 0) return { error: 'nothing' };
  const cost = pointResetCost(row, 'stat', used);
  if (num(save.dil) < cost) return { error: 'dil' };
  save.stats = { ...base };
  save.statPoints = num(save.statPoints) + back;
  save.statResets = used + 1;
  return { back, cost };
}
/** The stringtable_skill code of an applyStatReset error (null = STAT_NOTHING_TEXT). */
export function statResetErrorCode(error) {
  return error === 'left' ? RESET_MSG.statLeft : error === 'equipped' ? RESET_MSG.statEquipped : error === 'dil' ? RESET_MSG.noDil : null;
}
