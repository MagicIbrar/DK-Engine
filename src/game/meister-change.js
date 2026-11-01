import { meisterRank, meisterRequirement } from '../systems/skills/rank.js';

// Global item type0/code63, item description623 and messagebox80:41:
// switch the two class paths, refund normal skill points, retain Meister levels.
// Return a plan so the caller can consume the owned item before publishing it.
export function planMeisterChange(profile, classDef) {
  const from = profile?.meister?.path;
  if (!['A', 'B'].includes(from)) return { error: 'Choose a Meister path before using Meister Change.' };
  const to = from === 'A' ? 'B' : 'A', definitions = classDef?.skills;
  if (!Array.isArray(definitions) || !definitions.some(s => s.tree?.window === 'meister' && s.tree.path === to)) return { error: 'This class has no matching Meister path.' };
  const skills = structuredClone(profile.skills || {});
  // Engine reset policy: the ordinary automatic first-rank grants must not
  // undo an explicit paid-skill reset or manufacture the next refund. Block
  // only this class's authored paid first ranks; free gifts remain automatic.
  const suppressed = new Set(Array.isArray(profile.normalSkillResetSuppressed)
    ? profile.normalSkillResetSuppressed.filter(Number.isSafeInteger) : []);
  let refunded = 0;
  for (const skill of definitions) {
    if (skill.pointType === 'attribute' || skill.tree?.window === 'meister') continue;
    if (skill.tree?.window === 'skill' && Number(skill.levels?.[0]?.spCost) > 0) suppressed.add(Number(skill.index));
    const value = skills[skill.index], level = Number(value?.level ?? value) || 0;
    if (!level) continue;
    if (skill.type === 'passive' && (skill.levels || []).every(l => !Number(l.spCost))) continue;
    for (let n = 0; n < level; n++) {
      const cost = Number(skill.levels?.[n]?.spCost);
      if (!Number.isSafeInteger(cost) || cost < 0) return { error: 'The learned skill refund data is unavailable.' };
      refunded += cost;
    }
    delete skills[skill.index];
  }
  const points = (Number(profile.skillPoints) || 0) + refunded;
  if (!Number.isSafeInteger(points) || points < 0) return { error: 'Invalid skill point balance.' };
  const meister = { ...profile.meister, path: to };
  // Authored automatic path skills use the same prerequisites as first choice.
  for (const skill of definitions) {
    const first = skill.levels?.[0];
    if (skill.hidden || skill.tree?.window !== 'meister' || skill.tree.path !== to || !skill.meister?.autoLearn || skills[skill.index] || !first) continue;
    if (meisterRank(profile) < meisterRequirement(skill) || Number(first.reqLevel) > Number(profile.level) ||
      Number(first.grade || 0) > Number(profile.grade ?? profile.transGrade ?? 0) ||
      (first.prereqs || []).some(p => Number(skills[p.skill]?.level ?? skills[p.skill] ?? 0) < Number(p.level))) continue;
    skills[skill.index] = 1;
  }
  return { meister, skills, skillPoints: points, refunded, normalSkillResetSuppressed: [...suppressed].sort((a, b) => a - b) };
}
