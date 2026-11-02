import {rewardBonusPercent} from '../../game/reward-bonus.js';
import {premiumSum} from '../shops/premium-rules.js';

// The personal part of server/world/core.mjs hunting EXP bonusOf. Conditional
// party-size, level-cap and server rates are not intrinsic character bonuses.
// stats.expBonus already folds worn OPT_316 / RESULT_EXP_MUL / cash AddExpRate (items.json addExp).
// Buff RESULT_EXP_MUL stays in rewardBonusPercent so expired statuses drop out; itemOptions are
// omitted here to avoid double-counting the same worn RESULT_EXP_MUL already in stats.expBonus.
export function personalExpBonus(game,stats,now) {
  if(now==null) {
    const clock=game.network?._serverClock;
    now=clock&&Number.isFinite(clock.time)&&Number.isFinite(clock.at)?clock.time+performance.now()-clock.at:Date.now();
  }
  return (Number(stats?.expBonus) || 0)
    + rewardBonusPercent('exp',{buffs:game.save?.buffs},now)
    + premiumSum(game.save?.premium,now,'rate');
}
