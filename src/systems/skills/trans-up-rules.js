// Trans-Up / Meister gates from Global guide Cate 1305/2 (guide_info_system <cate> 1305 code 2).
// Chart levels: 1st Trans-Up @ 131, 2nd Trans-Up @ 165, Meister @ 170.
// Skill L.grade values are Awakening Grade numbers from share/pc/awakening (life.json grade rows),
// not a separate 1/2 counter. UI string "Trans-up grade" (ui-skillwnd) labels that Awakening Grade.
// Meister path/reinforce/change already live in server/world/skills.mjs + src/game/meister-change.js;
// awardMeisterRank is applied from quest rewards (src/systems/quests/engine.js).

export const TRANS_UP_LEVELS = Object.freeze({
  first: 131,
  second: 165,
  meister: 170,
});

/** Guide Cate 1305/2 stage -> minimum character level. */
export function transUpRequiredLevel(stage) {
  if (stage === 1 || stage === 'first') return TRANS_UP_LEVELS.first;
  if (stage === 2 || stage === 'second') return TRANS_UP_LEVELS.second;
  if (stage === 'meister' || stage === 3) return TRANS_UP_LEVELS.meister;
  return null;
}

/** True when character level meets the guide gate for that Trans-Up / Meister stage. */
export function canAttemptTransUp(save, stage) {
  const need = transUpRequiredLevel(stage);
  if (need == null) return false;
  return Number(save?.level) >= need;
}

/**
 * Resolve the Awakening Grade number used as the skill "Trans-up grade" gate.
 * Prefers an explicit save.grade / save.transGrade when present; otherwise derives
 * from save.life.grade.totalExp against the authored awakening rows (same cumulative
 * rule as src/systems/life/grade.js Grade.current()).
 */
export function awakeningGradeNumber(save, gradesRows) {
  if (save && Object.prototype.hasOwnProperty.call(save, 'grade') && save.grade != null && Number.isFinite(Number(save.grade))) {
    return Math.max(0, Math.floor(Number(save.grade)));
  }
  if (save && Object.prototype.hasOwnProperty.call(save, 'transGrade') && save.transGrade != null && Number.isFinite(Number(save.transGrade))) {
    return Math.max(0, Math.floor(Number(save.transGrade)));
  }
  const rows = Array.isArray(gradesRows) ? gradesRows : [];
  if (!rows.length) return 0;
  const sorted = rows.slice().sort((a, b) => (a.division - b.division) || (a.grade - b.grade));
  let cum = 0;
  let cur = 0;
  const totalExp = Number(save?.life?.grade?.totalExp) || 0;
  const level = Number(save?.level) || 1;
  for (const r of sorted) {
    cum += Math.max(0, Number(r.gradeExp) || 0);
    if (totalExp >= cum && level >= (Number(r.levelLimit) || 0)) cur = Number(r.grade) || 0;
    else break;
  }
  return cur;
}

/** Meister path selection requires guide level 170 (also enforced in server/world/skills.mjs). */
export function canSelectMeisterPath(save) {
  return canAttemptTransUp(save, 'meister');
}

/** Pull awakening grade rows from a game, world, or raw array. */
export function gradesFromContext(ctx) {
  if (Array.isArray(ctx)) return ctx;
  if (!ctx || typeof ctx !== 'object') return [];
  return ctx.data?.nameplateGrades
    || ctx.data?.grade?.grades
    || ctx.life?.grade?.G?.grades
    || ctx.life?.data?.grade?.grades
    || ctx.G?.grades
    || [];
}

/** Convenience: awakeningGradeNumber(save, gradesFromContext(ctx)). */
export function resolveAwakeningGrade(save, ctx) {
  return awakeningGradeNumber(save, gradesFromContext(ctx));
}