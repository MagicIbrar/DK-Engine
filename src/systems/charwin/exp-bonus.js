import {rewardBonusPercent} from '../../game/reward-bonus.js';
import {premiumSum} from '../shops/premium-rules.js';

// The personal part of server/world/core.mjs hunting EXP bonusOf. Conditional
// party-size, level-cap and server rates are not intrinsic character bonuses.
export function personalExpBonus(game,stats,now) {
  if(now==null) {
    const clock=game.network?._serverClock;
    now=clock&&Number.isFinite(clock.time)&&Number.isFinite(clock.at)?clock.time+performance.now()-clock.at:Date.now();
  }
  return rewardBonusPercent('exp',{buffs:game.save?.buffs,itemOptions:stats?.itemOptions},now)+premiumSum(game.save?.premium,now,'rate');
}
