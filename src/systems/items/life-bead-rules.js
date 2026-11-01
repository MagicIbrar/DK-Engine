// Native item Type3/Code7, Value1/Value2 and Appraisal define death-window beads.
// stringtable_item 20:398: Life Bead, 50% HP/MP, 15min; 20:399: Blessed, 100%, no wait.
// Names, Redemption Seeds, exchange boxes and selfrevive.csv are not item identity.
export function lifeBeadRule(db, index) {
  const def = db?.def?.(Number(index));
  if (Number(def?.type) !== 3 || Number(def?.code) !== 7) return null;
  const raw = [def.value1, def.value2, def.appraisal];
  if (raw.some(value => value == null || value === '')) return null;
  const [hp, mp, cooldown] = raw.map(Number);
  if (![hp, mp, cooldown].every(Number.isSafeInteger) || hp < 1 || hp > 100 || mp < 1 || mp > 100 || cooldown < 0 || cooldown > 86400000) return null;
  return {hp, mp, cooldown, blessed: hp === 100 && mp === 100 && cooldown === 0};
}

export function ownedLifeBead(profile, db, uid, now) {
  if (typeof uid !== 'string' || !Number.isSafeInteger(now) || now < 0) return null;
  const rows = (profile?.inventory || []).filter(item => item?.uid === uid);
  if (rows.length !== 1) return null;
  const item = rows[0], rule = lifeBeadRule(db, item.itemIndex);
  const expiry = item.expiresAt;
  if (!rule || !Number.isSafeInteger(item.count ?? 1) || (item.count ?? 1) < 1 || expiry != null && (!Number.isSafeInteger(expiry) || expiry < 0 || expiry > 0 && expiry <= now)) return null;
  const def = db.def(item.itemIndex), level = Number(profile.level) || 1, ci = Number(profile.classIndex);
  if (!Number.isInteger(ci) || ci < 0 || ci > 14 || !((Number(def.classMask) >>> ci) & 1) || level < Number(def.reqLv || 0) || Number(def.maxLv) > 0 && level > Number(def.maxLv)) return null;
  return {item, rule};
}
