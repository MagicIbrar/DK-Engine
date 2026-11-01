// Original skill style rule shared by cast validation and hotbar presentation.
export function skillWeaponCompatible(skill, style) {
  const styles = (skill?.styles || []).map(Number);
  return !styles.length || styles.includes(Number(style)) || styles.includes(0);
}
