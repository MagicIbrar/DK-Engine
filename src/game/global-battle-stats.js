// MATH-VERIFY 4.3.2 - the Global DekaronServer player battle-stat calculation (0x7c0950), decoded from the legacy
// server binary (gameplay logic only) and fed exclusively with Global client data: share/pc/pcclass.csv (per class),
// formula.ini (fSTR/fDEX/fSPRFactorForCritical) and share/pc/statmaxvalue.csv caps. Option ids are the server's own
// option registry (mov word [ebp+0x100], id after the name string): 0x31 RATING_CRITICAL_ADD, 0x32 RATING_BLOCKING_ADD,
// 0x33 RATING_GUARD_ADD, 0x36 RATING_CRITICAL_SUB, 0x3d DAMAGERATE_CRITICAL_ADD, 0xe8 BALANCE_MARK_ADD,
// 0xe9 BALANCE_DEATHBLOW_ADD, 0xea BALANCE_BLOCKING_ADD, 0xeb BALANCE_GUARD_ADD, 0xec BALANCE_VITALITY_ADD,
// 0xed BALANCE_MAGIC_REGIST_ADD, 0xef..0xf3 POSITIVE_{FIRE,ICE,LIGHTNINH,POISON,CURSE}RESIST_ADD, 0xf4 POSITIVE_ALLRESIST_ADD.
// Every result is a percent (float, as the server stores it). Pure: no RNG, no actor mutation.
//
// Inputs not identified in the binary are explicit parameters (default 0) - never guessed numbers:
//   baseCritRate   byte +0x49 of the object returned by [[PC+0x1ac0]+0x24]->vt54 (identity open, see MATH-VERIFY)
//   baseBlockRate  byte +0x0c of the same object
//   meleeReduceAdd / magicResistAdd / elementReduceAdd[i]  State Provider bytes +0xdc+i (vt2c(i); writer not traced)
export const GLOBAL_OPTION_IDS = Object.freeze({
  RATING_CRITICAL_ADD: 0x31, RATING_BLOCKING_ADD: 0x32, RATING_GUARD_ADD: 0x33, RATING_CRITICAL_SUB: 0x36,
  DAMAGERATE_CRITICAL_ADD: 0x3d, BALANCE_MARK_ADD: 0xe8, BALANCE_DEATHBLOW_ADD: 0xe9, BALANCE_BLOCKING_ADD: 0xea,
  BALANCE_GUARD_ADD: 0xeb, BALANCE_VITALITY_ADD: 0xec, BALANCE_MAGIC_REGIST_ADD: 0xed, POSITIVE_FIRERESIST_ADD: 0xef,
  POSITIVE_ICERESIST_ADD: 0xf0, POSITIVE_LIGHTNINHRESIST_ADD: 0xf1, POSITIVE_POISONRESIST_ADD: 0xf2,
  POSITIVE_CURSERESIST_ADD: 0xf3, POSITIVE_ALLRESIST_ADD: 0xf4,
});
// Hard caps in the binary: crit 75 (0xa1106c, = statmaxvalue 49), reductions 85 (0xc26ba0), critical damage 300
// (0xc26b9c), guard efficiency 80 (0xc26b98); crit-damage base byte clamp 250, crit resist min(100) then 75 (statmaxvalue 54).
export const GLOBAL_CAPS = Object.freeze({ crit: 75, reduction: 85, critDamage: 300, guardEfficiency: 80, critDamageBase: 250, critResist: 75 });
const ELEMENTS = ['fire', 'ice', 'lightning', 'poison', 'curse'];
const ELEMENT_OPTIONS = ['POSITIVE_FIRERESIST_ADD', 'POSITIVE_ICERESIST_ADD', 'POSITIVE_LIGHTNINHRESIST_ADD', 'POSITIVE_POISONRESIST_ADD', 'POSITIVE_CURSERESIST_ADD'];
const n = (v, d = 0) => { const x = Number(v); return Number.isFinite(x) ? x : d; };
const div1 = (v) => Math.max(1, v);   // the server divides by max(1, denominator) everywhere

/** Melee (physical) damage reduction % of a character: DEF / max(1, MELEE_DEC_LEVEL*L + DEF + MELEE_DEC_DEFENSE) * 100 (+add), cap 85. */
export function globalPhysicalReduction(level, defense, raw, add = 0) {
  const L = Math.trunc(n(level, 1)), def = n(defense);
  const v = def / div1(n(raw?.MELEEDAMAGE_DECREASERATE_LEVEL_FACTOR) * L + def + n(raw?.MELEEDAMAGE_DECREASERATE_DEFENSE_FACTOR)) * 100 + n(add);
  return Math.min(GLOBAL_CAPS.reduction, v);
}
/** Magic damage reduction % from the magic-resist rating MR: MR / max(1, MAGIC_DEC_LEVEL*L + MAGIC_DEC_RESIST + MR) * 100, cap 85. */
export function globalMagicReduction(level, magicResist, raw) {
  const L = Math.trunc(n(level, 1)), mr = n(magicResist);
  return Math.min(GLOBAL_CAPS.reduction, mr / div1(n(raw?.MAGICDAMAGE_DECREASERATE_LEVEL_FACTOR) * L + n(raw?.MAGICDAMAGE_DECREASERATE_RESIST_FACTOR) + mr) * 100);
}

/**
 * @param {object} p
 * @param {number} p.level  character level
 * @param {number} p.str @param {number} p.dex @param {number} p.spr  final stat points
 * @param {number} p.defense  final defence (DEF input of the melee reduction)
 * @param {object} p.raw  pcclass.csv column map of the class
 * @param {object} p.formula  formula.ini values
 * @param {(code:string)=>number} p.opt  total of an option over worn items + statuses (the server's 0x78ba10)
 */
export function globalBattleStats({ level, str = 0, dex = 0, spr = 0, defense = 0, raw = {}, formula = {}, opt = () => 0,
  baseCritRate = 0, baseBlockRate = 0, meleeReduceAdd = 0, magicResistAdd = 0, elementReduceAdd = [] } = {}) {
  const L = Math.max(1, Math.trunc(n(level, 1))), LV = L;
  const o = (code) => n(opt(code));
  // pf[] (State Provider +0xb4..): element points, mark, deathblow, blocking, guard, vitality
  const allResist = o('POSITIVE_ALLRESIST_ADD');
  const elementPts = ELEMENT_OPTIONS.map(code => o(code) + allResist);
  const mark = Math.max(0, LV * n(raw.LEVEL_MARK_FACTORY) + o('BALANCE_MARK_ADD'));
  const deathblow = n(spr) * n(formula.fSPRFactorForCritical) + n(dex) * n(formula.fDEXFactorForCritical) + n(str) * n(formula.fSTRFactorForCritical) + o('BALANCE_DEATHBLOW_ADD');
  const blocking = n(dex) * n(raw.BLOCKDEX_FACTOR) + n(str) * n(raw.BLOCKSTR_FACTOR) + o('BALANCE_BLOCKING_ADD');
  const guardPts = n(dex) * n(raw.GUARDDEX_FACTOR) + o('BALANCE_GUARD_ADD');
  const vitality = Math.max(0, o('BALANCE_VITALITY_ADD'));

  // provider adds (0x7c1da9.., 0x7c2177..)
  const critDamageBase = Math.max(0, Math.min(GLOBAL_CAPS.critDamageBase, 150 + o('DAMAGERATE_CRITICAL_ADD')));
  const critAddOpt = o('RATING_CRITICAL_ADD'), cb = n(baseCritRate);
  let critAdd = cb >= 100 - critAddOpt ? 100 : cb <= -critAddOpt ? 0 : cb + critAddOpt;
  critAdd = Math.min(GLOBAL_CAPS.crit, critAdd);
  const blockAdd = Math.max(0, n(baseBlockRate) + o('RATING_BLOCKING_ADD'));
  const guardAdd = Math.max(0, n(raw.GUARD_RATE));
  const critResist = Math.min(GLOBAL_CAPS.critResist, Math.max(0, Math.min(100, o('RATING_CRITICAL_SUB'))));

  const missRate = Math.max(0, LV / div1(n(raw.MISSRATE_LEVEL_FACTORY) * L + n(raw.MISSRATE_ADDITION_FACTORY)) * 100
    - mark / div1(n(raw.MISSRATE_DECREASE_LEVEL_FACTORY) * L) * 100);
  const critRate = Math.min(GLOBAL_CAPS.crit, deathblow / div1(n(raw.CRITICALRATE_LEVEL_FACTORY) * L) * 100 + critAdd);
  const blockRate = Math.min(n(raw.BLOCKRATEMAX), blocking / div1(n(raw.BLOCKINGRATE_LEVEL_FACTORY) * L) * 100 + blockAdd);
  const guardRate = Math.min(n(raw.GUARDRATEMAX), guardPts / div1(n(raw.GUARDRATE_LEVEL_FACTORY) * L) * 100 + o('RATING_GUARD_ADD') + guardAdd);
  const critDamagePct = Math.min(GLOBAL_CAPS.critDamage, vitality / div1(n(raw.CRITICAL_DAMAGE_FACTORY)) * 100 + critDamageBase);
  const guardEfficiency = Math.min(GLOBAL_CAPS.guardEfficiency, vitality / div1(n(raw.GUARD_EFFICIENCY_FACTORY)) * 100 + n(raw.GUARD_EFFICIENCY));

  const magicResist = n(raw.LEVEL_MAGICRESIST_RATION) * L + n(magicResistAdd) + Math.max(0, o('BALANCE_MAGIC_REGIST_ADD'));
  const elementReduction = {};
  ELEMENTS.forEach((e, i) => {
    elementReduction[e] = Math.min(GLOBAL_CAPS.reduction, elementPts[i] / div1(n(raw.ELEMENTDAMAGE_DECREASERATE_RESIST_FACTOR) + elementPts[i]
      + n(raw.ELEMENTDAMAGE_DECREASERATE_LEVEL_FACTOR) * L) * 100 + n(elementReduceAdd[i]));
  });
  return {
    missRate, hitRate: 100 - missRate, critRate, blockRate, guardRate, critDamagePct, critMultiplier: critDamagePct / 100,
    guardEfficiency, critResist, magicResist,
    meleeReduction: globalPhysicalReduction(L, defense, raw, meleeReduceAdd),
    magicReduction: globalMagicReduction(L, magicResist, raw),
    allResistRate: magicResist / div1(n(raw.MAGICDAMAGE_ALLRESIST_LEVEL_FACTOR) * L) * 100,
    elementReduction,
    points: { elementPts, mark, deathblow, blocking, guard: guardPts, vitality },
  };
}
