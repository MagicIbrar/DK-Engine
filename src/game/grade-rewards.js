import {gradeRowsOf,gradeAt} from '../systems/shops/coin-shops-rules.js';

/** Reconcile earned but unclaimed rewards, including ranks unlocked by character level.
 * Retains the existing cumulative Grade EXP policy; no native RoyalPoint reinterpretation.
 * The caller owns persistence/authority and must apply this to its transaction candidate.
 */
export function claimEligibleGradeRewards(profile, authoredRows) {
  const rows=gradeRowsOf(authoredRows), state=profile.life?.grade;
  if(!state||!rows.length)return [];
  const total=Number(state.totalExp)||0,level=Number(profile.level)||1;
  const current=gradeAt(rows,total,level), awarded=[];
  state.claimed||={};
  for(const row of rows){
    if(row.i>(current?.i??-1)||total<row.cum||level<(row.levelLimit||0))break;
    if(state.claimed[row.key])continue;
    state.claimed[row.key]=true;
    if(row.rewardStat>0)profile.statPoints=(profile.statPoints||0)+row.rewardStat;
    if(row.rewardSkill>0)profile.skillPoints=(profile.skillPoints||0)+row.rewardSkill;
    awarded.push(row);
  }
  if(current)state.rowKey=current.key;
  return awarded;
}
