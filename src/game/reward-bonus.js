// Hunting reward bonuses from status / item options (TODO-HOLYWATER.md 6). The client data carries them as status options in
// skills_status.json - RESULT_EXP_MUL on 110 statuses (EXP scrolls / potions, e.g. 6540-6542 = +10 / +20 / +30 %), RESULT_DIL_MUL on 18
// (6550-6552), RESULT_DROP_MUL on 21 (6560-6562) - and the same option codes can sit on equipment / crests (stats.itemOptions).
// Before this, nothing read them: the buff icon showed but monster EXP / DIL / drops did not change.
// ENGINE-CHOSEN: the data does not say how bonuses stack; they are summed (percent) and added to the premium Rate the same way the
// server already adds the premium personal and party rates.
export const REWARD_OPTIONS = Object.freeze({ exp: 'RESULT_EXP_MUL', dil: 'RESULT_DIL_MUL', drop: 'RESULT_DROP_MUL' });

/** Percent bonus of one kind ('exp' | 'dil' | 'drop') from the active buffs (profile.buffs: {options:[{code,value}], expiresAt?})
 *  and the equipped item options ({code: value}). Expired buffs count for nothing. */
export function rewardBonusPercent(kind, { buffs = [], itemOptions = null } = {}, now = Date.now()) {
  const code = REWARD_OPTIONS[kind];
  if (!code) return 0;
  let sum = Number(itemOptions?.[code]) || 0;
  for (const b of Array.isArray(buffs) ? buffs : []) {
    if (!b || (Number(b.expiresAt) > 0 && Number(b.expiresAt) <= now)) continue;
    for (const o of Array.isArray(b.options) ? b.options : []) if (o?.code === code) sum += Number(o.value) || 0;
  }
  return Math.max(0, sum);
}

/** The reward bonuses of a server player (profile buffs + derived item options). */
export const playerRewardBonus = (kind, player, now) => rewardBonusPercent(kind, { buffs: player?.profile?.buffs, itemOptions: player?.stats?.itemOptions }, now);
