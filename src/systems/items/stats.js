// Item stats: everything the worn items add to the character (items.md 4.4 / 4.5 / 5 / 6.2-6.4):
// weapon damage (replaces the bare-hand damage), armour defence, block, fixed + expansion + rank (random) + socket
// stone + brand + crest options, set bonuses (tier by distinct worn parts) and the dual-weapon status.
//
// Output of computeItemStats(sys):
//   weapon  {meleeMin..rangeMax, range, speed, critical}  -> save.equipment.weapon.stats (progression.equipmentStats)
//   flat    {str, dex, con, spr, defense, hp, mp, hitRate, dodge, critical}  -> save.equipment._items.stats
//   options Map(optionName -> summed value) of every option; statuses [{options:[{code,value}]}] for deriveStats'
//           buff sums (DAMAGE_PHYSICAL_MUL, DEFENSE_MUL, SPEED_MOVE_MUL, ...); applyPost(stats) folds the rest in.
import { S } from './equip.js';
import { refreshDerivedShield } from '../../game/progression.js';
import {ownsTitle} from '../life/title-rules.js';

// Current Global Titles guide18: acquired options accumulate even when another title is displayed.
// Values remain native title_base.csv; no title is granted by this stat hook.
export function ownedTitleOptions(sys){
  const rows=sys.game?.life?.data?.grade?.titles||sys.game?.data?.titleRows||[],state=sys.game?.save?.life?.titles;
  return rows.filter(row=>ownsTitle(state,row.Index)&&Number.isFinite(Number(row.Option_Value1))).map(row=>[Number(row.Option_Index1),Number(row.Option_Value1),row.Index]);
}

const FLAT = {
  STAT_STR_ADD: 'str', STAT_DEX_ADD: 'dex', STAT_CON_ADD: 'con', STAT_SPR_ADD: 'spr',
  HP_MAX_ADD: 'hp', MP_MAX_ADD: 'mp', RATING_ATTACK_ADD: 'hitRate', BALANCE_MARK_ADD: 'hitRate',
  DEFENSE_MIN_ADD: 'defense', ARMOR_ADD: 'defense',
};
// option names deriveStats already sums from its buff list (progression.js)
const BUFFED = new Set(['DAMAGE_PHYSICAL_MUL', 'DAMAGE_PHYSICAL_SUB', 'RANGE_DAMAGE_RANGECAL_MUL', 'RANGE_DAMAGE_RANGECAL_SUB',
  'DAMAGE_MAGICAL_MUL', 'DAMAGE_MAGICAL_SUB', 'DAMAGE_MINPHYSICAL_ADD', 'DEFENSE_MUL', 'DEFENSE_SUB', 'DEFENSE_ADD',
  'BALANCE_GUARD_ADD', 'SPEED_ATTACK_MUL', 'SPEED_ATTACK_SUB', 'SPEED_MOVE_MUL', 'SPEED_MOVE_SUB', 'HP_RECOVERY_ADD', 'MP_RECOVERY_ADD',
  'SHIELD_MAX_ADD', 'SHIELD_MAX_MUL', 'SHIELD_RECOVERY_ADD']);

/** Every [optionType, value] pair an instance carries (fixed, expansion, rank, sockets, brand, crest). */
export function instOptions(db, inst, { includeSockets = true } = {}) {
  const def = db.def(inst?.itemIndex);
  if (!def) return [];
  const out = [];
  for (const o of def.options || []) out.push(o);
  for (const o of def.exOptions || []) out.push(o);
  for (const o of inst.rnd || []) out.push(o);
  if (includeSockets) for (const s of inst.sockets || []) if (s) for (const o of db.def(s)?.options || []) out.push(o);
  for (const o of inst.brand || []) out.push(o);
  for (const o of inst.crest?.options || []) out.push(o);
  return out;
}

/** Set bonus tiers active for the worn items: [{set, name, count, tiers:[{need, effects}]}]. */
export function activeSets(db, worn) {
  const sets = db.equipment.unionSets || {};
  const by = new Map();
  for (const { inst } of worn) {
    const def = db.def(inst.itemIndex);
    if (!def?.union) continue;
    const set = sets[def.union];
    if (!set) continue;
    let e = by.get(def.union);
    if (!e) by.set(def.union, e = { set: def.union, name: set.name, parts: new Map(), items: new Set() });
    // distinct parts: a part kind counts once unless the set says duplicate
    const part = (set.parts || []).find(p => Number(p.type) === Number(def.type) && Number(p.code) === Number(def.code));
    const key = part ? (part.group ? `g${part.group}` : `${def.type}/${def.code}`) : `${def.type}/${def.code}`;
    const dup = part?.duplicate ? e.items.size : 0;
    e.parts.set(dup ? `${key}#${dup}` : key, def.index);
    e.items.add(inst.uid);
  }
  const out = [];
  for (const e of by.values()) {
    const set = sets[e.set];
    const count = e.parts.size;
    const tiers = (set.tiers || []).filter(t => count >= t.need);
    out.push({ set: e.set, name: e.name, count, tiers, all: set.tiers || [] });
  }
  return out;
}

export function computeItemStats(sys) {
  const db = sys.db, eq = sys.equip;
  const worn = eq.worn().filter(({ slot }) => slot !== S.costume2);
  const now = Date.now();
  const opts = new Map();
  const add = (type, v) => {
    const name = db.optionName(type) || `OPT_${type}`;
    opts.set(name, (opts.get(name) || 0) + (Number(v) || 0));
  };
  const flat = { str: 0, dex: 0, con: 0, spr: 0, defense: 0, hp: 0, mp: 0, hitRate: 0, dodge: 0, critical: 0 };
  let block = 0, pvpDmg = 0, pvpDef = 0;
  // Cash item AddExpRate / AddDrop* (items.json addExp/addDrop/addDil as fractions: 0.2 = +20%).
  // stringtable_cashitem: "[Veteran's Amulet] EXP +20%"; Reinforced "increases your EXP reward from hunting by 200%".
  let cashAddExp = 0, cashAddDrop = 0, cashAddDil = 0;
  for (const { slot, inst } of worn) {
    if (inst.expiresAt && inst.expiresAt < now) continue;
    const def = db.def(inst.itemIndex);
    if (!def) continue;
    cashAddExp += Number(def.addExp) || 0;
    cashAddDrop += Number(def.addDrop) || 0;
    cashAddDil += Number(def.addDil) || 0;
    if (slot === S.weapon) continue;   // weapon damage below
    if (def.def) flat.defense += Number(def.def[1] || def.def[0]) || 0;
    block += Number(def.block) || 0;
    pvpDef += Number(def.pvpDef) || 0;
    pvpDmg += Number(def.pvpDmg) || 0;
    // (mounts system, docs/MOUNTS.md) a mount's fixed options (speed, monster damage tolerance) count only while riding
    if (slot === S.vehicle && sys.game?.mounts && !sys.game.mounts.isMounted()) { for (const [t, v] of def.exOptions || []) add(t, v); continue; }
    for (const [t, v] of instOptions(db, inst)) add(t, v);
  }
  // (mounts system) options of the summoned pet and of the mount's enchanted option: game.mounts.extraOptions()
  for (const [t, v] of sys.game?.mounts?.extraOptions?.() || []) add(t, v);
  let titleAttack=0;
  for(const [type,value,index] of ownedTitleOptions(sys)){
    // Savior's native Option_Index1=3 conflicts with its HP+ caption and publisher Heal+25; do not invent CON+25.
    if(index===2)continue;
    if(type===324){titleAttack+=value;continue;} // native title caption + current publisher: All ATT +.
    add(type,value);
  }
  // main weapon
  const wi = eq.get(S.weapon);
  const wd = db.def(wi?.itemIndex);
  const weapon = { meleeMin: 0, meleeMax: 0, magicMin: 0, magicMax: 0, rangeMin: 0, rangeMax: 0, range: 1.5, speed: 1, critical: 0 };
  if (wd && !(wi.expiresAt && wi.expiresAt < now)) {
    [weapon.meleeMin, weapon.meleeMax] = wd.melee || [0, 0];
    [weapon.magicMin, weapon.magicMax] = wd.magic || [0, 0];
    [weapon.rangeMin, weapon.rangeMax] = wd.ranged || [0, 0];
    weapon.range = Number(wd.range) || 1.5;
    weapon.speed = Number(wd.speed) || 1;
    weapon.critical = Number(wd.crit) || 0;
    block += Number(wd.block) || 0;
    pvpDmg += Number(wd.pvpDmg) || 0;
    if (wd.def) flat.defense += Number(wd.def[1] || wd.def[0]) || 0;
    for (const [t, v] of instOptions(db, wi)) add(t, v);
  }
  // set bonuses
  const sets = activeSets(db, worn);
  for (const s of sets) for (const t of s.tiers) for (const [type, v] of t.effects || []) add(type, v);
  // fold
  for (const [name, v] of opts) if (FLAT[name]) flat[FLAT[name]] += v;
  // max-damage adds go straight onto the weapon ranges
  weapon.meleeMax += opts.get('DAMAGE_MAXPHYSICAL_ADD') || 0;
  weapon.magicMin += opts.get('DAMAGE_MINMAGICAL_ADD') || 0;
  weapon.magicMax += (opts.get('DAMAGE_MAXMAGICAL_ADD') || 0) + (opts.get('DAMAGE_MINMAGICAL_ADD') || 0);
  weapon.rangeMin += opts.get('RANGE_DAMAGE_MINRANGECAL_ADD') || 0;
  weapon.rangeMax += (opts.get('RANGE_DAMAGE_MAXRANGECAL_ADD') || 0) + (opts.get('RANGE_DAMAGE_MINRANGECAL_ADD') || 0);
  const statuses = [{ source: 'items', options: [...opts].filter(([n]) => BUFFED.has(n)).map(([code, value]) => ({ code, value })) }];
  const dual = eq.dualStatus();
  return { weapon, flat, block, pvpDmg, pvpDef, options: opts, statuses, sets, dual, titleAttack, cashAddExp, cashAddDrop, cashAddDil };
}

/** Fold the options deriveStats does not know into its result (called from the progression post hook). */
export function applyPost(stats, it) {
  if (!it) return stats;
  for(const key of ['meleeMin','meleeMax','rangeMin','rangeMax','magicMin','magicMax','attackMin','attackMax'])if(Number.isFinite(stats[key]))stats[key]+=it.titleAttack||0;
  const o = (n) => it.options.get(n) || 0;
  // Native cate200:324/325/326 and itemmunzang_* call these All Attack,
  // not crafting. Match the established skill/passive all-attack fold while
  // keeping worn options separate from buffs, so neither is counted twice.
  const allAdd = o('COMBINE_OPTION_COMBINE_ADD');
  const allMul = Math.max(0, 1 + (o('COMBINE_OPTION_COMBINE_MUL') - o('COMBINE_OPTION_COMBINE_SUB')) / 100);
  if (allAdd || allMul !== 1) {
    for (const [lo, hi] of [['meleeMin','meleeMax'],['rangeMin','rangeMax'],['magicMin','magicMax']]) {
      if (Number.isFinite(stats[lo])) stats[lo] = Math.max(0, Math.round((stats[lo] + allAdd) * allMul));
      if (Number.isFinite(stats[hi])) stats[hi] = Math.max(stats[lo] || 0, Math.round((stats[hi] + allAdd) * allMul));
    }
    stats.attackMin = stats.attackType === 'range' ? stats.rangeMin : stats.meleeMin;
    stats.attackMax = stats.attackType === 'range' ? stats.rangeMax : stats.meleeMax;
  }
  if (o('HP_MAX_MUL')) { stats.maxHp = Math.round(stats.maxHp * (1 + o('HP_MAX_MUL') / 100)); }
  if (o('MP_MAX_MUL')) { stats.maxMp = Math.round(stats.maxMp * (1 + o('MP_MAX_MUL') / 100)); }
  stats.blockRate = (stats.blockRate || 0) + it.block + o('RATING_BLOCKING_ADD') + o('BALANCE_BLOCKING_ADD') / 10;
  stats.guardRate = Math.max(0, (stats.guardRate || 0) + o('RATING_GUARD_ADD'));
  stats.critRate = Math.min(95, (stats.critRate || 0) + o('RATING_CRITICAL_ADD') + o('BALANCE_DEATHBLOW_ADD') / 100);
  stats.critMultiplier = (stats.critMultiplier || 1.5) * (1 + o('DAMAGERATE_CRITICAL_ADD') / 100);
  stats.magicResist = (stats.magicResist || 0) + o('BALANCE_MAGIC_REGIST_ADD') + o('RESIST_MAGIC_ADD');
  stats.hitRate = (stats.hitRate || 0) + o('BALANCE_MARK_ADD') * 0;   // already in flat.hitRate
  stats.vitality = (stats.vitality || 0) + o('BALANCE_VITALITY_ADD');
  stats.resist = {
    fire: o('POSITIVE_FIRERESIST_ADD') + o('POSITIVE_ALLRESIST_ADD'), ice: o('POSITIVE_ICERESIST_ADD') + o('POSITIVE_ALLRESIST_ADD'),
    lightning: o('POSITIVE_LIGHTNINHRESIST_ADD') + o('POSITIVE_ALLRESIST_ADD'), poison: o('POSITIVE_POISONRESIST_ADD') + o('POSITIVE_ALLRESIST_ADD'),
    curse: o('POSITIVE_CURSERESIST_ADD') + o('POSITIVE_ALLRESIST_ADD'), dark: o('POSITIVE_DARKRESIST_ADD') + o('POSITIVE_ALLRESIST_ADD'),
  };
  stats.elementDamage = {
    fire: o('DAMAGEADD_FIRE_ADD'), ice: o('DAMAGEADD_ICE_ADD'), lightning: o('DAMAGEADD_LIGHTNING_ADD'),
    poison: o('DAMAGEADD_POISON_ADD'), curse: o('DAMAGEADD_CURSE_ADD'), dark: o('DAMAGEADD_DARK_ADD'),
  };
  stats.pvpDamage = it.pvpDmg; stats.pvpDefense = it.pvpDef;
  // OPT_316 / RESULT_*_MUL are percent points; cash AddExpRate is a fraction (0.2 -> +20).
  stats.expBonus = (stats.expBonus || 0) + (it.options.get('OPT_316') || 0) + o('RESULT_EXP_MUL') + Math.round((Number(it.cashAddExp) || 0) * 100);
  // the client data names these RESULT_DROP_MUL / RESULT_DIL_MUL (skills_status.json); OPT_317 / OPT_318 kept for unnamed option ids
  stats.dropBonus = (stats.dropBonus || 0) + (it.options.get('OPT_318') || 0) + o('RESULT_DROP_MUL') + Math.round((Number(it.cashAddDrop) || 0) * 100);
  stats.dilBonus = (stats.dilBonus || 0) + (it.options.get('OPT_317') || 0) + o('RESULT_DIL_MUL') + Math.round((Number(it.cashAddDil) || 0) * 100);
  stats.cooldownMul = 1 - o('SPEED_COOLTIME_MUL') / 100;
  stats.castMul = 1 - o('SPEED_CASTING_MUL') / 100;
  stats.mpCostMul = 1 - o('MP_DECREASE_SPENDRESOURCE') / 100;
  stats.bossDamage = o('SIZEDAMAGERATE_BOSS_ADD') + o('SIZEDAMAGERATE_RESERVED_5');
  stats.itemOptions = Object.fromEntries(it.options);
  stats.itemSets = it.sets.map(s => ({ set: s.set, name: s.name, count: s.count }));
  return refreshDerivedShield(stats);
}
