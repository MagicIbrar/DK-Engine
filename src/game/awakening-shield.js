// Awakening grade shield - a stat input of the shield capacity (src/game/progression.js refreshDerivedShield).
// DATA: share/pc/awakening/grade.csv column "Reward2(Sheild)" (gamedata life.json grade.grades[].rewardShield): one shield
// amount per grade row, rising with the grade (1501, 1760, 1961, ...). It is NOT an item index (item 1501 is "Polaris Pants",
// 1760 / 1961 are no items), so the old reading in systems/life/grade.js that handed out item 1501 was wrong.
// The character's grade = the same rule as systems/life/grade.js Grade.current(): the highest row (sorted by division,
// grade) whose cumulative Grade EXP is paid and whose level limit the character meets.
// INFERENCE (labelled): the amount joins the additive input of the recovered legacy formula (the same channel as the item
// option SHIELD_MAX_ADD), so it is multiplied by SHIELD_MAX_MUL like other additions.
// NOT APPLIED: share/pc/awakening/gradeweek.csv "Reward1(Shield)" (the weekly "de Honor" rewards) - the data does not say
// who earns them each week (a server ranking), so there is no rule to apply.

/** Grade rows with their cumulative Grade EXP, ready for awakeningShield (null when the table is missing). */
export function awakeningShieldRows(grades) {
  if (!Array.isArray(grades) || !grades.length) return null;
  let cum = 0;
  return Object.freeze(grades.slice().sort((a, b) => a.division - b.division || a.grade - b.grade).map(r => {
    cum += Math.max(0, Number(r.gradeExp) || 0);
    return Object.freeze({ division: Number(r.division) || 0, grade: Number(r.grade) || 0, cum, levelLimit: Number(r.levelLimit) || 0, shield: Math.max(0, Number(r.rewardShield) || 0) });
  }));
}

/** The current grade row of a save (Grade.current() rule) or null. */
export function awakeningGradeRow(save, rows) {
  if (!rows?.length) return null;
  const exp = Number(save?.life?.grade?.totalExp) || 0, level = Number(save?.level) || 1;
  let cur = null;
  for (const r of rows) { if (exp >= r.cum && level >= r.levelLimit) cur = r; else break; }
  return cur;
}

/** Shield amount the save's awakening grade adds (0 without a grade table or grade). */
export function awakeningShield(save, rows) {
  return awakeningGradeRow(save, rows)?.shield || 0;
}
