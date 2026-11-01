// Shared refreshes may supply active buffs and cached passiveEntries.
// Equipment's applyPost runs first, as in the local item/skill refresh hooks.
// This pure fold reads only the status options progression does not consume;
// it never folds stats.itemOptions a second time or mutates either input.
import { sumStatus, refreshDerivedShield } from './progression.js';

export function foldSharedStatusStats(stats, statuses, passivePools = []) {
  const list = (statuses || []).filter(status => status?.source !== 'items');
  const add = sumStatus(list, 'COMBINE_OPTION_COMBINE_ADD');
  const mul = Math.max(0, 1 + (sumStatus(list, 'COMBINE_OPTION_COMBINE_MUL') - sumStatus(list, 'COMBINE_OPTION_COMBINE_SUB')) / 100);
  const allRes = sumStatus(list, 'POSITIVE_ALLRESIST_ADD');
  // Max HP / MP statuses (native HP_MAX_ADD / HP_MAX_MUL / MP_MAX_ADD / MP_MAX_MUL; a stacked status already carries
  // value x stacks) use the local stat hook's formula on top of the worn items' own percentage: (max + ADD) x (1 + MUL / 100).
  // Caller-supplied passive caches stay out. The central host derivation supplies
  // authoritative pools from the exact staged profile and current equipment,
  // once, so inventory/respawn/skill refreshes cannot disagree or double-count.
  const pools = list.filter(status => !status?.passive).concat(passivePools);
  const hpAdd = sumStatus(pools, 'HP_MAX_ADD'), hpMul = sumStatus(pools, 'HP_MAX_MUL');
  const mpAdd = sumStatus(pools, 'MP_MAX_ADD'), mpMul = sumStatus(pools, 'MP_MAX_MUL');
  const pool = !!(hpAdd || hpMul || mpAdd || mpMul);
  if (!add && mul === 1 && !allRes && !pool) return stats;
  const out = { ...stats };
  if (add || mul !== 1) {
    for (const [lo, hi] of [['meleeMin','meleeMax'], ['rangeMin','rangeMax'], ['magicMin','magicMax']]) {
      if (Number.isFinite(stats[lo])) out[lo] = Math.max(0, Math.round((stats[lo] + add) * mul));
      if (Number.isFinite(stats[hi])) out[hi] = Math.max(out[lo] || 0, Math.round((stats[hi] + add) * mul));
    }
    out.attackMin = out.attackType === 'range' ? out.rangeMin : out.meleeMin;
    out.attackMax = out.attackType === 'range' ? out.rangeMax : out.meleeMax;
  }
  if (allRes) {
    out.resist = { ...stats.resist };
    for (const element of ['fire','ice','lightning','poison','curse','dark']) out.resist[element] = (Number(stats.resist?.[element]) || 0) + allRes;
    out.magicResist = (Number(stats.magicResist) || 0) + allRes;
  }
  if (pool) {
    if (Number.isFinite(stats.maxHp)) out.maxHp = Math.max(1, Math.round((stats.maxHp + hpAdd) * (1 + hpMul / 100)));
    if (Number.isFinite(stats.maxMp)) out.maxMp = Math.max(0, Math.round((stats.maxMp + mpAdd) * (1 + mpMul / 100)));
    // The shield capacity weights the final HP (as the local hook re-derives it); inputs come from the source stats.
    refreshDerivedShield(out, stats);
  }
  return out;
}
