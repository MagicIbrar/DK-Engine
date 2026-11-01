// Character progression: derived combat stats, experience / levels, stat points and HP/MP regeneration.
//
// Data sources (all real client data, see docs/formats/characters.md):
//   classes.json  classes[].stats (base STR/DEX/CON/SPR, damageRatios, guardRate ...), growth (HP/MP per level/stat),
//                 level1 (HP/MP check values), weapon.stats (starter weapon), formula (share formula.ini),
//                 statPointsPerLevel, maxLevel
//   exp.json      levels[n].exp = exp needed from level n to n+1, levelDifference (share/pc/levelcap.csv)
//
// The damage/defence/hit formulas themselves were server-side and are NOT in the client. What follows is a
// reconstruction that uses every factor the client ships, documented inline. The HP/MP formula reproduces the
// builder's level-1 values exactly (AK 193/14, Hunter 112/17, Magician 74/118 ...).
//
// save.exp is the experience gathered INSIDE the current level (0 .. expToNext(level)-1), like the original's gauge.

import { PVP_OPTION_CODES } from './pvp-rules.js';
import { awakeningShield } from './awakening-shield.js';
import { applyStatReset } from './point-resets.js';

const DEFAULT_FORMULA = {
  fSTRDamageRatio: 0.4, fDEXDamageRatio: 0.4, fSPRDamageRatio: 0.4, fLEVELDamageRatio: 0.4,
  fCONDefenseRatio: 0.6, fLEVELDefenseRatio: 1,
  fDEXAttackRatingFactor: 4, fMaxAttackProbFactor: 100, fDefaultAttackProb: 40,
  byMinAttackProbability: 30, byMaxAttackProbability: 95,
  fSTRFactorForCritical: 1.4, fDEXFactorForCritical: 2, fSPRFactorForCritical: 1.5,
  byGuardProbability: 15, byGuardEfficiency: 50,
  byHPRecoveryFactor: 35, byMPRecoveryFactor: 35, wHPFullRecoveryTime: 360, wMPFullRecoveryTime: 360,
  byRespawnExpCostRatio: 3, wMinLevelToLoseExp: 0, wMaxLevel: 250, byStatPointPerLevel: 5,
  fMonAttDamageRatio: 1, fMonDefRatio: 1, fMonEXPRatio: 1, fMonItemDropRatio: 1, fMonMoneyDropRatio: 1,
  fSkillCoolTimeRate: 1,
};

/** Fallback player run speed (m/s) when a class has no root-motion data. The real speed of each class is its RUN
 *  clip's root-motion stride per cycle / the clip's action-table TimeLength (classes.json
 *  stats.speedFromRootMotion.run: 3.445 for the 7 classic classes, 4.278 Dragon Knight, 4.444 Segita Shooter,
 *  5.004 Conserra ...), so the run animation's feet never slide (Player.groundSpeed picks the
 *  clip of the current stance). pcclass Speed_WALK (2.5, every class) is a server validation value, not a run speed. */
export const BASE_RUN_SPEED = 3.445;
/** Walk (R) speed as a fraction of the run speed: the WALK clip's root-motion speed / the RUN clip's (classes.json
 *  stats.speedFromRootMotion; the peace stance walks with walkPeace where the class has it). The shared host moves a
 *  walking player at run speed x this ratio and the client predicts with the same ratio, so feet stay planted. */
export function walkSpeedRatio(classDef, peace = false) {
  const s = classDef?.stats?.speedFromRootMotion || {};
  const run = Number(s.run) > 0 ? Number(s.run) : BASE_RUN_SPEED;
  const walk = Number(peace ? (s.walkPeace || s.walk) : (s.walk || s.walkPeace)) || 0;
  return walk > 0 ? Math.min(1, walk / run) : 1.851 / BASE_RUN_SPEED;
}
/** Out-of-combat regeneration multiplier and how long after the last hit a character counts as "in combat". */
export const OUT_OF_COMBAT_REGEN = 4;
export const COMBAT_TIMEOUT = 6;
/** Skill points granted per level (the original gave 1 per level; the client carries no table for it). */
export const SKILL_POINTS_PER_LEVEL = 1;

const _formulaCache = new WeakMap();
/** formula.ini values from classes.json merged over defaults (so tests / partial data still work). */
export function formulaOf(data) {
  const src = data?.classesFile?.formula || data?.formula || null;
  if (!src) return DEFAULT_FORMULA;
  let f = _formulaCache.get(src);
  if (!f) { f = { ...DEFAULT_FORMULA, ...src }; _formulaCache.set(src, f); }
  return f;
}

/** Sum of an option code over a status list ([{options:[{code,value}], remaining}]). */
export function sumStatus(list, code) {
  if (!list || !list.length) return 0;
  let v = 0;
  for (const s of list) {
    if (!s || (s.remaining != null && s.remaining <= 0)) continue;
    for (const o of s.options || []) if (o.code === code) v += Number(o.value) || 0;
  }
  return v;
}

const num = (v, d = 0) => (Number.isFinite(+v) ? +v : d);

/** Stats of everything the character wears. save.equipment = { weapon: {itemIndex, name, stats:{meleeMin..}}, coat: {stats:{defense, con ..}} }.
 *  Until the item system lands, the starter weapon from classes.json stands in for an empty weapon slot. */
function equipmentStats(save, classDef) {
  const eq = save?.equipment || {};
  const weapon = (eq.weapon && eq.weapon.stats) || classDef?.weapon?.stats || {};
  const bonus = { str: 0, dex: 0, con: 0, spr: 0, defense: 0, hp: 0, mp: 0, hitRate: 0, dodge: 0, critical: 0 };
  for (const [slot, item] of Object.entries(eq)) {
    if (!item || !item.stats || slot === 'weapon') continue;
    for (const k of Object.keys(bonus)) bonus[k] += num(item.stats[k]);
  }
  for (const k of ['str', 'dex', 'con', 'spr', 'hp', 'mp', 'hitRate', 'dodge']) bonus[k] += num(weapon[k]);
  return { weapon, bonus };
}

/**
 * Derived combat stats of the player.
 *   save     character record (level, stats {str,dex,con,spr}, equipment, buffs)
 *   classDef classes.json class entry
 *   data     GameData (for formula.ini); buffs default to save.buffs (active statuses written by skills.js)
 */
export function deriveStats(save, classDef, data, buffs = save?.buffs) {
  // extra stat sources (items system: worn item options/sets as status-like entries): fn(save, classDef, data) -> [{options:[{code,value}]}]
  if (statProviders.length) {
    const extra = [];
    for (const fn of statProviders) { try { const r = fn(save, classDef, data); if (r?.length) extra.push(...r); } catch (err) { console.error('[progression] stat provider', err); } }
    if (extra.length) buffs = [...(buffs || []), ...extra];
  }
  const out = deriveStatsBase(save, classDef, data, buffs);
  const raw = classDef?.stats?.raw || {};
  const weights = ['HP_WEIGHTPOINT', 'DEF_WEIGHTPOINT', 'LEVELWEIGHTPOINT', 'EFFICIENCY'];
  const native = weights.every(key => raw[key] != null && Number.isFinite(Number(raw[key]))) && Number(raw.DEF_WEIGHTPOINT) === 0;
  shieldInputs.set(out, Object.freeze({
    native, hpWeight: Math.fround(num(raw.HP_WEIGHTPOINT)), levelWeight: Math.fround(num(raw.LEVELWEIGHTPOINT)),
    // + the awakening grade's shield (grade.csv Reward2(Sheild), src/game/awakening-shield.js); data.gradeShieldRows is set by
    // the life system (client) and server/world/data.mjs (host), so both derive the same capacity
    efficiency: Math.fround(num(raw.EFFICIENCY)), add: sumStatus(buffs, 'SHIELD_MAX_ADD') + awakeningShield(save, data?.gradeShieldRows), mul: sumStatus(buffs, 'SHIELD_MAX_MUL'),
    regen: num(raw.SHIELD_RPS, 30) + out.level * num(raw.SHIELD_RPS_LF, 0.1) + sumStatus(buffs, 'SHIELD_RECOVERY_ADD') / 200,
  }));
  for (const fn of statPostHooks) { try { fn(out, save, classDef, data); } catch (err) { console.error('[progression] stat post hook', err); } }
  return refreshDerivedShield(out);
}

/** Stat extension points (additive; used by src/systems/items): providers add buff entries, post hooks edit the result. */
export const statProviders = [];
export const statPostHooks = [];

// Captured once per derivation, after providers. No save/packet fields or retained actor references.
const shieldInputs = new WeakMap();
/** Recompute after HP posthooks; an explicit source preserves inputs when a caller edits a clone. */
export function refreshDerivedShield(stats, sourceStats = stats) {
  const input = shieldInputs.get(sourceStats);
  if (!input || !stats || typeof stats !== 'object') return stats;
  if (sourceStats !== stats) shieldInputs.set(stats, input);
  const { native, hpWeight, levelWeight, efficiency, add, mul, regen } = input;
  // Legacy server shield calculation: float stores after weighted base,
  // ADD and MUL; its setter stores that float unchanged. Preserve this engine's
  // existing final HP behavior. The awakening grade's shield is part of `add` (see awakening-shield.js); the weekly
  // "de Honor" shield (gradeweek.csv) has no earning rule in the data and is not applied.
  // Every prepared class has DEF_WEIGHTPOINT=0; the two native defense inputs are
  // unnamed, so do not invent their mapping for unsupported/missing class data.
  const base = native ? Math.fround((Math.fround(num(stats.level)) * levelWeight
    + Math.fround(num(stats.maxHp)) * hpWeight) * efficiency) : 0;
  const value = native
    ? Math.fround(Math.fround(base + add) * (1 + mul * Math.fround(0.01)))
    : Math.round(add * (1 + mul / 100));
  stats.maxShield = Number.isFinite(value) ? Math.max(0, value) : 0;
  stats.shieldRegen = stats.maxShield > 0 ? regen : 0;
  return stats;
}

function deriveStatsBase(save, classDef, data, buffs) {
  const F = formulaOf(data);
  const level = Math.max(1, num(save?.level, 1));
  const base = classDef?.stats?.base || { str: 5, dex: 5, con: 5, spr: 5 };
  const st = save?.stats || base;
  const { weapon: w, bonus } = equipmentStats(save, classDef);
  const str = num(st.str, base.str) + bonus.str;
  const dex = num(st.dex, base.dex) + bonus.dex;
  const con = num(st.con, base.con) + bonus.con;
  const spr = num(st.spr, base.spr) + bonus.spr;
  const g = classDef?.growth || {};
  const R = classDef?.stats?.damageRatios || {};
  const raw = classDef?.stats?.raw || {};

  // HP / MP: the builder's inferred pcclass formula (reproduces classes.json level1 exactly).
  const maxHp = Math.max(1, Math.round(num(g.hpBase) + num(g.hpPerLevel, 30) * level + num(g.hpPerCon, 20) * con + bonus.hp));
  const maxMp = Math.max(0, Math.round(num(g.mpBase) + num(g.mpPerLevel, 8) * level + num(g.mpPerSpr, 6) * spr + bonus.mp));

  // Attack: weapon damage + STAT*STAT_xxxDAMAGE_RATIO*fSTATDamageRatio + LEVEL*LEVEL_xxxDAMAGE_RATIO*fLEVELDamageRatio
  // (the per-class pcclass ratios scaled by the global formula.ini ratios).
  const meleeBonus = str * num(R.strMelee, 3) * F.fSTRDamageRatio + level * num(R.levelMelee, 3) * F.fLEVELDamageRatio;
  const rangeBonus = dex * num(R.dexRange, 3) * F.fDEXDamageRatio + level * num(R.levelRange, 3) * F.fLEVELDamageRatio;
  const magicBonus = spr * num(R.sprMagic, 3) * F.fSPRDamageRatio + level * num(R.levelMagic, 3) * F.fLEVELDamageRatio;

  const phyMul = 1 + (sumStatus(buffs, 'DAMAGE_PHYSICAL_MUL') - sumStatus(buffs, 'DAMAGE_PHYSICAL_SUB')) / 100;
  const rngMul = phyMul * (1 + (sumStatus(buffs, 'RANGE_DAMAGE_RANGECAL_MUL') - sumStatus(buffs, 'RANGE_DAMAGE_RANGECAL_SUB')) / 100);
  const magMul = 1 + (sumStatus(buffs, 'DAMAGE_MAGICAL_MUL') - sumStatus(buffs, 'DAMAGE_MAGICAL_SUB')) / 100;
  const minPhyAdd = sumStatus(buffs, 'DAMAGE_MINPHYSICAL_ADD');
  const pair = (lo, hi, add, mul, minAdd = 0) => {
    let a = (num(lo) + add + minAdd) * mul, b = (num(hi) + add) * mul;
    if (b < a) b = a;
    return [Math.max(0, Math.round(a)), Math.max(0, Math.round(b))];
  };
  const [meleeMin, meleeMax] = pair(w.meleeMin, w.meleeMax, meleeBonus, phyMul, minPhyAdd);
  const [rangeMin, rangeMax] = pair(w.rangeMin, w.rangeMax, rangeBonus, rngMul, minPhyAdd);
  const [magicMin, magicMax] = pair(w.magicMin, w.magicMax, magicBonus, magMul);

  // Basic attacks use the weapon's physical kind: bows/crossbows/whips are 'range', everything else 'melee'.
  // (Magicians swing their wand/orb; their magic damage is used by magic skills.)
  const attackType = num(w.rangeMax) > 0 && num(w.rangeMax) >= num(w.meleeMax) ? 'range' : 'melee';
  const attackMin = attackType === 'range' ? rangeMin : meleeMin;
  const attackMax = attackType === 'range' ? rangeMax : meleeMax;

  // Defence: LEVEL*LEVEL_DEFENSE_RATIO*fLEVELDefenseRatio + CON*CON_DEFENSE_RATIO*fCONDefenseRatio + armour.
  const defMul = 1 + (sumStatus(buffs, 'DEFENSE_MUL') - sumStatus(buffs, 'DEFENSE_SUB')) / 100;
  const defense = Math.round((level * num(R.levelDefense, 5) * F.fLEVELDefenseRatio
    + con * num(R.conDefense) * F.fCONDefenseRatio + bonus.defense + sumStatus(buffs, 'DEFENSE_ADD')) * defMul);

  // Attack rating / dodge (see combat.js hitChance): DEX*fDEXAttackRatingFactor + 10/level.
  const hitRate = Math.round(dex * F.fDEXAttackRatingFactor + level * 10 + bonus.hitRate);
  const dodge = Math.round(dex * 2 + level * 10 + bonus.dodge);

  // Critical chance (%): weapon critical + a DEX term that saturates with level
  // (fDEXFactorForCritical and pcclass CRITICALRATE_LEVEL_FACTORY), capped at 50%.
  const critPts = dex * F.fDEXFactorForCritical;
  const critLv = level * num(raw.CRITICALRATE_LEVEL_FACTORY, 85) / 10 + 20;
  const critRate = Math.min(50, 3 + num(w.critical) + bonus.critical + 20 * critPts / (critPts + critLv));
  const critMultiplier = num(raw.CRITICAL_DAMAGE_FACTORY, 1500) / 1000;

  const guardRate = Math.min(num(raw.GUARDRATE_MAX, 50), num(classDef?.stats?.guardRate, 8) + sumStatus(buffs, 'BALANCE_GUARD_ADD') / 10);
  const guardEfficiency = num(classDef?.stats?.guardEfficiency, 25);

  const attackRange = Math.max(1.2, num(w.range, 2));
  const attackSpeed = Math.max(0.2, num(w.speed, 1) * (1 + (sumStatus(buffs, 'SPEED_ATTACK_MUL') - sumStatus(buffs, 'SPEED_ATTACK_SUB')) / 100));
  // Movement: the class's battle RUN clip root-motion speed x buffs (Player.groundSpeed uses the clip of the current
  // stance and the map's MoveSpeedFactor). runAnimSpeed = the matching playback-rate factor (the actor's locomotion
  // sync also derives it from the measured ground speed).
  const moveSpeedMul = Math.max(0.2, 1 + (sumStatus(buffs, 'SPEED_MOVE_MUL') - sumStatus(buffs, 'SPEED_MOVE_SUB')) / 100);
  const clipRun = num(classDef?.stats?.speedFromRootMotion?.run, BASE_RUN_SPEED) || BASE_RUN_SPEED;
  const moveSpeed = clipRun * moveSpeedMul;
  const runAnimSpeed = moveSpeedMul;

  // Regeneration per second (in combat). pcclass HP_RPS/MP_RPS plus a full refill over
  // wHP/MPFullRecoveryTime seconds; out of combat tickRegen multiplies this by OUT_OF_COMBAT_REGEN.
  // HP/MP_RECOVERY_ADD statuses (e.g. Mana force 1443) are read as value/200 per second (approximation).
  // HP/MP_RECOVERY_IMPOSSIBLE ("Temporarily Can Not Regain HP", "Block MP Recovery"): no regeneration while the status lasts
  // (ENGINE-CHOSEN reading of the status text; skill heals are refused the same way by the skill engine).
  const hpBlocked = sumStatus(buffs, 'HP_RECOVERY_IMPOSSIBLE') > 0, mpBlocked = sumStatus(buffs, 'MP_RECOVERY_IMPOSSIBLE') > 0;
  const hpRegen = hpBlocked ? 0 : num(g.hpRegenPerSec, 1) + maxHp / Math.max(1, F.wHPFullRecoveryTime) + sumStatus(buffs, 'HP_RECOVERY_ADD') / 200;
  const mpRegen = mpBlocked ? 0 : num(g.mpRegenPerSec, 1) + maxMp / Math.max(1, F.wMPFullRecoveryTime) + sumStatus(buffs, 'MP_RECOVERY_ADD') / 200;

  // Shield capacity is finalized after HP posthooks by refreshDerivedShield.
  // Existing recovery timing remains: raw RPS + level*RPS_LF + RECOVERY_ADD/200,
  // out of combat only (the recovery timing itself is still an engine assumption).
  const maxShield = 0, shieldRegen = 0;

  // PvP option codes of the statuses and passive / mastery skills in `buffs` (worn items reach pvp-rules through stats.itemOptions;
  // the items provider forwards only its BUFFED list, so nothing is counted twice). Only present when a code is active.
  const pvpOptions = {};
  for (const code of PVP_OPTION_CODES) { const v = sumStatus(buffs, code); if (v) pvpOptions[code] = v; }

  return {
    level, str, dex, con, spr,
    maxHp, maxMp,
    attackMin, attackMax, attackType,
    meleeMin, meleeMax, rangeMin, rangeMax, magicMin, magicMax,
    defense, hitRate, dodge, critRate, critMultiplier, guardRate, guardEfficiency,
    attackRange, attackSpeed, moveSpeed, moveSpeedMul, runAnimSpeed,
    hpRegen, mpRegen, maxShield, shieldRegen,
    ...(Object.keys(pvpOptions).length ? { pvpOptions } : {}),
  };
}

// ------------------------------------------------------------------ experience

export function maxLevelOf(data) {
  return num(data?.exp?.maxLevel, 0) || num(data?.classesFile?.maxLevel, 0) || formulaOf(data).wMaxLevel || 250;
}

/** Experience needed to go from `level` to `level + 1`. */
export function expToNext(level, data) {
  if (data && typeof data.expNeeded === 'function') {
    const v = data.expNeeded(level);
    if (Number.isFinite(v)) return v;
  }
  const L = data?.exp?.levels;
  if (Array.isArray(L)) {
    const row = L.find(r => r.level === level) || L[level - 1];
    if (row) return num(row.exp ?? row.toNext, Infinity);
  }
  return 40 * Math.pow(2, Math.max(0, level - 1));
}

/** exp % for a kill, from share/pc/levelcap.csv (monster level minus player level). */
/**
 * EXP multiplier hooks: systems push fn({amount, monsterLevel}) -> factor into game.expModifiers (premium services,
 * events...). The factors multiply; a throwing or non-positive hook counts as 1.
 */
export function expHookMul(game, amount, monsterLevel) {
  let m = 1;
  for (const fn of game?.expModifiers || []) {
    try { const f = Number(fn({ amount, monsterLevel })); if (f > 0 && Number.isFinite(f)) m *= f; } catch { /* ignore a broken hook */ }
  }
  return m;
}

export function expRateFor(levelDiff, data) {
  const rows = data?.exp?.levelDifference;
  if (!Array.isArray(rows) || !rows.length) return 100;
  const d = Math.round(levelDiff);
  for (const r of rows) if (d >= r.diffFrom && d < r.diffTo) return num(r.expRate, 100);
  // outside every band: use the extreme band on that side
  let lo = rows[0], hi = rows[0];
  for (const r of rows) { if (r.diffFrom < lo.diffFrom) lo = r; if (r.diffTo > hi.diffTo) hi = r; }
  return num(d >= hi.diffTo ? hi.expRate : lo.expRate, 100);
}

/**
 * Give the player experience. monsterLevel (optional) applies the level-difference rate.
 * Handles multi-level-ups; each level grants statPointsPerLevel stat points and SKILL_POINTS_PER_LEVEL skill points.
 * Emits 'exp' {amount, base, rate} then one 'levelup' {level} per level gained. Returns the exp actually gained.
 */
export function grantExp(game, amount, monsterLevel = null) {
  if (game?.save?.authority === 'server') return 0;
  const save = game?.save;
  if (!save || !(amount > 0)) return 0;
  const data = game.data;
  const F = formulaOf(data);
  save.level = Math.max(1, num(save.level, 1));
  save.exp = Math.max(0, num(save.exp));
  const rate = monsterLevel == null ? 100 : expRateFor(num(monsterLevel) - save.level, data);
  const mult = num(F.fMonEXPRatio, 1) * num(game.settings?.expRate, 1) * expHookMul(game, amount, monsterLevel);
  const gained = Math.max(1, Math.round((amount * rate / 100) * mult));

  const maxLevel = maxLevelOf(data);
  const perLevel = num(data?.classesFile?.statPointsPerLevel, 0) || num(game.classDef?.growth?.statPointsPerLevel, 0) || F.byStatPointPerLevel || 5;
  save.exp += gained;
  const levels = [];
  while (save.level < maxLevel) {
    const need = expToNext(save.level, data);
    if (!(need > 0) || !Number.isFinite(need) || save.exp < need) break;
    save.exp -= need;
    save.level++;
    save.statPoints = num(save.statPoints) + perLevel;
    save.skillPoints = num(save.skillPoints) + SKILL_POINTS_PER_LEVEL;
    levels.push(save.level);
  }
  if (save.level >= maxLevel) save.exp = 0;
  if (game.player) game.player.level = save.level;

  game.events?.emit('exp', { amount: gained, base: amount, rate });
  for (const level of levels) game.events?.emit('levelup', { level });
  return gained;
}

/** Death penalty: lose byRespawnExpCostRatio % of the current level's requirement (never de-levels).
 *  Disabled with game.settings.deathPenalty === false. Returns the exp lost. */
export function applyDeathPenalty(game) {
  const save = game?.save;
  if (!save || game.settings?.deathPenalty === false) return 0;
  const F = formulaOf(game.data);
  if (num(save.level, 1) < num(F.wMinLevelToLoseExp)) return 0;
  const loss = Math.floor(expToNext(num(save.level, 1), game.data) * num(F.byRespawnExpCostRatio, 3) / 100);
  const lost = Math.min(num(save.exp), Math.max(0, loss));
  if (lost > 0) {
    save.exp -= lost;
    game.events?.emit('exp', { amount: -lost, penalty: true });
  }
  return lost;
}

const STATS = ['str', 'dex', 'con', 'spr'];
/** Spend stat points on STR/DEX/CON/SPR. Returns the number of points spent. */
export function allocateStat(game, stat, count = 1) {
  const save = game?.save;
  const key = String(stat || '').toLowerCase();
  if (!save || !STATS.includes(key)) return 0;
  if (save.authority === 'server') {
    if (Number.isInteger(count) && count > 0) void game.network?.action?.('allocate', { stat: key, count });
    return 0;
  }
  const n = Math.min(Math.max(0, Math.floor(count)), num(save.statPoints));
  if (n <= 0) return 0;
  if (!save.stats) save.stats = { ...(game.classDef?.stats?.base || { str: 5, dex: 5, con: 5, spr: 5 }) };
  save.stats[key] = num(save.stats[key]) + n;
  save.statPoints = num(save.statPoints) - n;
  if (typeof game.refreshPlayerStats === 'function' && game.player) game.refreshPlayerStats(false);
  game.events?.emit('stats', { stat: key, count: n });
  return n;
}

/**
 * STATCLEAR NPC service ("[Stat Reset] Reset my stats.", msgbox/ui_statreset) in the local game: return every spent
 * STR/DEX/CON/SPR point to the pool under the src/game/point-resets.js rules (`row` = the level's exp.csv row). The shared
 * server runs the same rules (server/world/point-resets.mjs). Returns {back, cost} or {error}.
 */
export function resetStats(game, row) {
  const save = game?.save;
  if (!save) return { error: 'nothing' };
  const r = applyStatReset(save, { base: game.classDef?.stats?.base || { str: 5, dex: 5, con: 5, spr: 5 }, row });
  if (r.error) return r;
  if (r.cost) { if (game.items?.spendDil) game.items.spendDil(r.cost); else save.dil = num(save.dil) - r.cost; }
  if (typeof game.refreshPlayerStats === 'function' && game.player) game.refreshPlayerStats(false);
  game.events?.emit('stats', { reset: true, count: r.back });
  return r;
}

/** Is the actor still "in combat" (hit or was hit within COMBAT_TIMEOUT seconds)? */
export function inCombat(actor, now) {
  return actor?.lastCombat != null && now - actor.lastCombat < COMBAT_TIMEOUT;
}

/**
 * One HP / MP / shield regeneration step, shared by the local game and the authoritative server so both agree.
 * `mult` scales HP and MP (faster out of combat); shield regenerates only when `idle` (out of combat).
 * Returns true when any value changed.
 */
export function regenStep(p, st, mult, idle, dt) {
  if (!p || !st || !(dt > 0)) return false;
  let changed = false;
  const maxHp = p.maxHp ?? st.maxHp, maxMp = p.maxMp ?? st.maxMp;
  if (p.hp < maxHp) { p.hp = Math.min(maxHp, p.hp + Math.max(0, st.hpRegen ?? 1) * mult * dt); changed = true; }
  if ((p.mp || 0) < maxMp) { p.mp = Math.min(maxMp, (p.mp || 0) + Math.max(0, st.mpRegen ?? 1) * mult * dt); changed = true; }
  const maxShield = Number(p.maxShield ?? st.maxShield) || 0;
  if (idle && maxShield > 0 && (Number(p.shield) || 0) < maxShield) {
    p.shield = Math.min(maxShield, (Number(p.shield) || 0) + Math.max(0, st.shieldRegen || 0) * dt); changed = true;
  }
  return changed;
}

/** HP/MP/shield regeneration for the player, called every frame. Faster out of combat; nothing while dead. */
export function tickRegen(game, dt) {
  const p = game?.player;
  if (!p || p.dead || !(dt > 0)) return;
  const st = p.stats;
  if (!st) return;
  const idle = !inCombat(p, game.time || 0);
  regenStep(p, st, idle ? OUT_OF_COMBAT_REGEN : 1, idle, dt);
}
