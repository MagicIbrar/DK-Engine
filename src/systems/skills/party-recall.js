// Native Recall (compiled 702/1502): Target 64, target status 4000002 then 4500010.
// 4500010's eight argument fields are zero: recipient comes from the selected party target,
// destination is the caster. It is not the separate pet recall/order operation.
export function isPartyRecallSkill(skill) {
  return Number(skill?.targetMask) === 64 && [skill?.steps || [], ...(skill?.levels || []).map(l => l.steps || [])]
    .some(steps => steps.some(st => Number(st.result?.resultCode) === 4500010));
}

// Same range envelope already used by the host cast command, including its existing actor-radius allowance.
export function withinRecallRange(skill, caster, target) {
  const reach = Math.max(1.5, Number(skill?.range) || 3) + (Number(target?.radius) || .5) + .3;
  return Number.isFinite(caster?.x) && Number.isFinite(caster?.z) && Number.isFinite(target?.x) && Number.isFinite(target?.z)
    && Math.hypot(caster.x - target.x, caster.z - target.z) <= reach;
}
