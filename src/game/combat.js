// Combat rules: hit/miss, damage, crits, guards, kills. Plus the small helpers every gameplay module shares
// (random numbers, animation-state tracking, statuses).
//
// The original resolved combat on the server, so the formula is a reconstruction. It uses the client factors:
//   formula.ini  fDefaultAttackProb 40, fMaxAttackProbFactor 100, byMin/MaxAttackProbability 30/95,
//                fMonAttDamageRatio / fMonDefRatio, LIMIT via pcclass LIMIT_DAMAGE_DECREASE_RATE 75
//   pcclass      MELEEDAMAGE_DECREASERATE_LEVEL_FACTOR 125, MAGICDAMAGE_ALLRESIST_LEVEL_FACTOR 195,
//                CRITICAL_DAMAGE_FACTORY 1500 (x1.5), GUARD_RATE / GUARD_EFFICIENCY
//   monsters     attacks[key] = [min, max, absMin, absMax, rangeCells, delayMs, ...], def [min,max], guard, resist
//
//   hit%   = fDefaultAttackProb + fMaxAttackProbFactor * AR / (AR + DR)
//            - 2 per level the defender is above the attacker (+1 per level below), +10 for skills, +10 magic,
//            clamped to [byMinAttackProbability, byMaxAttackProbability]
//            AR (attack rating): player DEX*4 + 10*level, monster 14*level; DR (dodge): player DEX*2 + 10*level, monster 12*level
//   raw    = rand(min, max) * multiplier + skill addDamage          (player: weapon + stat/level ratios, progression.js)
//   red    = DEF / (DEF + attackerLevel*125 + 250), max 75%          (magic: DEF/2 + magic resist vs level*195)
//   dmg    = raw * (1 - red) * (crit ? 1.5 : 1) * (guard ? 1 - efficiency : 1) + rand(absMin, absMax)
// A level-1 Azure Knight (31 dmg) takes about 10 swings to kill a Spider Larva (278 HP, def 41-59), and a level-30
// player fighting a level-30 Spider loses about half their HP per kill without armour, which matches the
// potion-heavy pace of the original.
import { grantExp, applyDeathPenalty, sumStatus, formulaOf, COMBAT_TIMEOUT } from './progression.js';
import { normalizeOptionName } from '../systems/items/option-identities.js';

// ------------------------------------------------------------------ random numbers (swappable for tests)
export const RNG = { random: Math.random };
export const rand = () => RNG.random();
export const randRange = (a, b) => (b > a ? a + (b - a) * RNG.random() : a);
export function randInt(a, b) {
  a = Math.round(+a || 0); b = Math.round(+b || 0);
  if (b < a) [a, b] = [b, a];
  return a + Math.floor(RNG.random() * (b - a + 1));
}
/** Deterministic PRNG (mulberry32) for tests and replays. */
export function seededRandom(seed = 1) {
  let s = seed >>> 0;
  return () => {
    s = (s + 0x6d2b79f5) >>> 0;
    let t = s;
    t = Math.imul(t ^ (t >>> 15), t | 1);
    t ^= t + Math.imul(t ^ (t >>> 7), t | 61);
    return ((t ^ (t >>> 14)) >>> 0) / 4294967296;
  };
}

// ------------------------------------------------------------------ actor helpers
/** monsters.json definition of a monster actor (+index), or null. */
export function monsterDef(actor) {
  return actor?.def || actor?.monsterDef || actor?.data || null;
}
export function levelOf(actor) {
  return Number(actor?.level ?? monsterDef(actor)?.level ?? 1) || 1;
}
export function isAlive(actor) {
  return !!actor && !actor.dead && !actor.disposed && (actor.hp == null || actor.hp > 0);
}
export function isEnemyOf(a, b) {
  return !!a && !!b && a !== b && (a.kind === 'monster') !== (b.kind === 'monster') && a.kind !== 'npc' && b.kind !== 'npc';
}
export function dist2(a, b) {
  return Math.hypot((a.x || 0) - (b.x || 0), (a.z || 0) - (b.z || 0));
}
/** Record that an actor took part in combat now (drives regen and battle stance). */
export function markCombat(actor, now) {
  if (actor) actor.lastCombat = now;
}

// ------------------------------------------------------------------ animation state tracking
// Per-frame gameplay code calls playLoop() every frame; play() is only issued when the state changes.
// playOnce() starts a one-shot (attack, hit, skill, die) and holds the state until `now + hold`, so an idle
// request does not cut a hit reaction short. Movement passes force=true to interrupt immediately.
export function playOnce(actor, state, opts = {}, now = 0, hold = 0) {
  if (!actor) return;
  actor._gpState = state;
  actor._gpHold = now + (hold > 0 ? hold : 0);
  try { actor.play?.(state, { loop: false, ...opts }); } catch (err) { console.warn('play failed', state, err); }
}
export function playLoop(actor, state, opts = {}, now = 0, force = false) {
  if (!actor) return false;
  if (actor._gpState === state) return false;
  if (!force && now < (actor._gpHold || 0)) return false;
  actor._gpState = state;
  actor._gpHold = 0;
  try { actor.play?.(state, { loop: true, ...opts }); } catch (err) { console.warn('play failed', state, err); }
  return true;
}
/** Forget the tracked state (after something outside gameplay code changed the animation, e.g. revive). */
export function resetAnimState(actor) {
  if (actor) { actor._gpState = null; actor._gpHold = 0; }
}

// ------------------------------------------------------------------ statuses (buffs/debuffs from skills)
/** Status list of an actor: the player's lives in save.buffs (persists), monsters' in monster.statuses. */
export function statusesOf(actor) {
  return actor?.statuses || null;
}
export function statusValue(actor, code) {
  return sumStatus(statusesOf(actor), code);
}
/** Read a combat option at the point of use. Derived attack/HP/resist fields have
 * already folded equipment; this is only for options those fields do not fold.
 * Shared actors and local actors keep the same raw native option units. */
// LANE1-PERF: normalizeOptionName reads only immutable module tables, so its result
// for a given string never changes. Bounded memo; exact parity is proven by
// tools/test-lane1-combat-option-parity.mjs against the verbatim original.
const NORMALIZED_OPTION_NAMES = new Map();
const NORMALIZED_OPTION_NAME_LIMIT = 8192;
function normalizedOptionName(name) {
  if (typeof name !== 'string') return normalizeOptionName(name);
  const hit = NORMALIZED_OPTION_NAMES.get(name);
  if (hit !== undefined) return hit;
  const value = normalizeOptionName(name);
  if (NORMALIZED_OPTION_NAMES.size < NORMALIZED_OPTION_NAME_LIMIT) NORMALIZED_OPTION_NAMES.set(name, value);
  return value;
}
function sumOptionEntries(entries, code, value) {
  for (const entry of entries) {
    if (!entry || (entry.remaining != null && entry.remaining <= 0)) continue;
    for (const option of entry.options || []) if (normalizedOptionName(option.code) === code) value += Number(option.value) || 0;
  }
  return value;
}
export function combatOptionValue(actor, code, sources = {}) {
  code = normalizedOptionName(code);
  const engine = actor?._skills?.engine || actor?.game?.skills;
  const list = sources.statuses ?? actor?.statuses ?? actor?.profile?.buffs ?? [];
  const passives = sources.passiveEntries ?? (engine?.game?.player === actor || actor?._skills ? engine?.passiveEntries?.() : []) ?? [];
  // Same order as the former [...list, ...passives] walk (identical float summation).
  let value = sumOptionEntries(passives, code, sumOptionEntries(list, code, 0));
  const itemOptions = actor?.stats?.itemOptions || {};
  for (const name of Object.keys(itemOptions)) if (normalizedOptionName(name) === code) value += Number(itemOptions[name]) || 0;
  return value;
}
export function combatClassRaw(actor) {
  return actor?.stats?.raw ?? actor?.classDef?.stats?.raw ?? actor?.game?.classDef?.stats?.raw ?? {};
}
/** These native types store tenths of a percent (status descriptions and native
 * item option labels); keep saved values raw and convert only for the effect. */
export function combatOptionPercent(actor, code, sources) {
  code = normalizeOptionName(code);
  const divisor = ['PENETRATE_PHYSICAL', 'PENETRATE_MAGICAL', 'ANTI_ANTI_RATE', 'SIZEDAMAGERATE_BOSS_MUL'].includes(code) ? 10 : 1;
  let value = combatOptionValue(actor, code, sources) / divisor;
  // Original 6676 explicitly pairs raw5 with 5%, while 6855 raw50 is 5%.
  // Honor that exact native exception; do not change or guess other raw rows.
  if (code === 'ANTI_ANTI_RATE') for (const entry of sources?.statuses ?? actor?.statuses ?? actor?.profile?.buffs ?? []) {
    if (Number(entry?.statusIndex) !== 6676 || (entry.remaining != null && entry.remaining <= 0)) continue;
    for (const option of entry.options || []) if (normalizeOptionName(option.code) === code) value += (Number(option.value) || 0) * 0.9;
  }
  return value;
}
export function penetratedDefense(attacker, defense, kind = 'melee') {
  const code = kind === 'magic' ? 'PENETRATE_MAGICAL' : 'PENETRATE_PHYSICAL';
  // DEFENSE_TARGET_IGNORE_MELLE_MUL ("Ignore DEF" 10-50, the data spells melee MELLE): percent of the target's defence a melee hit
  // ignores. ENGINE-CHOSEN reading of the status text; it adds to the physical penetration option.
  const ignoreMelee = kind === 'melee' ? combatOptionValue(attacker, 'DEFENSE_TARGET_IGNORE_MELLE_MUL') : 0;
  return Math.max(0, Number(defense) || 0) * (1 - Math.max(0, Math.min(100, combatOptionPercent(attacker, code) + ignoreMelee)) / 100);
}
export function criticalChance(attacker, defender, base = attacker?.stats?.critRate ?? 5) {
  const raw = combatClassRaw(attacker);
  // ENGINE-CHOSEN equation using original charwin29 and pcclass factors. The
  // client ships the role/cap/factor, not the Global server's point equation.
  const factory = Number(raw.DESTRUCTION_FACTORY) || 5;
  const destruction = Math.max(0, Math.min(Number(raw.DESTRUCTIONRATE_MAX) || 50, combatOptionValue(attacker, 'STATUS_EX_CRITICAL_RESIST_DOWN') / factory));
  const resistance = Math.max(0, combatOptionValue(defender, 'RATING_CRITICAL_SUB') - destruction);
  return Math.max(0, Math.min(100, (Number(base) || 0) - resistance));
}
export function criticalDamageMultiplier(attacker, defender, base = attacker?.stats?.critMultiplier ?? 1.5) {
  // Native Vitality charwin271:47 affects critical power, not healing. The
  // point/factory equation is reconstructed; the role and +400% cap are native.
  const factory = Number(combatClassRaw(attacker).CRITICAL_DAMAGE_FACTORY) || 1500;
  const vitality = Math.max(0, Math.min(4, combatOptionValue(attacker, 'BALANCE_VITALITY_ADD') / factory));
  return (Math.max(1, Number(base) || 1) + vitality) * (1 - Math.min(90, combatOptionValue(defender, 'DAMAGERATE_EX_CRITICAL_SUB')) / 100);
}
/** Native Vitality increases damage absorption on a successful guard (max80%).
 * ENGINE-CHOSEN points/factory curve, kept distinct from the guard chance. */
export function guardEfficiency(defender, base = defender?.stats?.guardEfficiency ?? 0) {
  const factory = Number(combatClassRaw(defender).GUARD_EFFICIENCY_FACTORY) || 1250;
  return Math.max(0, Math.min(80, (Number(base) || 0) + Math.max(0, combatOptionValue(defender, 'BALANCE_VITALITY_ADD')) / factory * 100));
}
/** ENGINE-CHOSEN point curve using native charwin31/46 + pcclass. Mastery
 * reduces the target's block/guard chances; it does not raise damage/cast speed. */
export function masteryReduction(attacker, { kind = 'guard', pvp = false } = {}) {
  const raw = combatClassRaw(attacker), key = kind === 'block' ? 'BLOCK' : 'GUARD';
  const factory = Number(raw[`COMPETENCE_${key}_FACTORY`]) || (key === 'BLOCK' ? 170 : 95);
  const cap = Number(raw[`COMPETENCE_PVP_${key}_RATE_MAX`]) || (key === 'BLOCK' ? 20 : 30);
  const scale = pvp ? 1 : Number(raw[`COMPETENCE_PVE_${key}_VALUE`]) || (key === 'BLOCK' ? 1.15 : 1.6);
  return Math.max(0, Math.min(cap, combatOptionValue(attacker, 'STATUS_EX_COMPETENCE') / factory)) * scale;
}
export function blockChance(attacker, defender, base = defender?.stats?.blockRate ?? monsterDef(defender)?.blockRate ?? 0, options) {
  return Math.max(0, Math.min(100, avoidanceBase(defender, base) - masteryReduction(attacker, { ...options, kind: 'block' })));
}
export function guardChance(attacker, defender, base = defender?.stats?.guardRate ?? monsterDef(defender)?.guard?.[0] ?? 0, options) {
  return Math.max(0, Math.min(100, avoidanceBase(defender, base) - masteryReduction(attacker, { ...options, kind: 'guard' })));
}
// Native monster tables mix legacy percentage-like rows with newer large
// rating values (e.g. Hunting9330 Block3385/Guard2235). Treating a rating as
// percent makes that monster permanently immune. The private rating equation
// is absent: ENGINE-CHOSEN saturation uses the existing level*12 monster dodge
// scale and a50% ceiling. Preserve legacy0..100 values, player percentages and
// authored brick percentages; retain all original rows unchanged.
function avoidanceBase(defender, value) {
  const raw = Math.max(0, Number(value) || 0);
  const monster = !!monsterDef(defender) && (defender?.kind === 'monster' || !defender?.profile);
  if (!monster || defender?.isBrick || raw <= 100) return raw;
  return 50 * raw / (raw + Math.max(1, levelOf(defender)) * 12);
}
const HIT_ELEMENTS = [['fire','FIRE',1], ['ice','ICE',2], ['lightning','LIGHTNING',3], ['poison','POISON',4], ['curse','CURSE',5], ['dark','DARK',6]];
export function elementResistance(defender, element, index) {
  if (defender?.kind !== 'monster' && !defender?.def) return Math.max(-100, Math.min(75, (Number(defender?.stats?.resist?.[element]) || 0) / 10));
  const raw = (Number(monsterDef(defender)?.resist?.[index]) || 0) + combatOptionValue(defender, `RESIST_${element.toUpperCase()}_ADD`);
  return Math.max(-100, Math.min(90, raw / (raw > 100 ? 10 : 1)));
}
/** Final offensive stage shared by ordinary hits and skill hits. The curve and
 * caps remain this engine's reconstruction; native tables establish the option
 * identity/unit, not the undisclosed Global server's combat ordering. No RNG,
 * HP mutation, rewards or scripted/GM damage are performed here. */
export function modifyHitDamage(attacker, defender, amount, { includeElement = true, round = true } = {}) {
  let damage = Math.max(0, Number(amount) || 0);
  if (!damage) return 0;
  // A monster under a native invincible/barrier row (e.g. Triforce 7324,
  // STATUS_EX2_ALL_TOLERANCE flag) takes no hit damage.
  if (monsterDef(defender) && defender?.kind === 'monster' && statusValue(defender, 'STATUS_EX2_ALL_TOLERANCE') > 0) return 0;
  if (includeElement) for (const [element, code, index] of HIT_ELEMENTS) {
    const flat = combatOptionValue(attacker, `DAMAGEADD_${code}_ADD`);
    if (flat) damage += flat * Math.max(0, 1 + combatOptionPercent(attacker, `DAMAGERATE_${code}_ADD`) / 100) * (1 - elementResistance(defender, element, index) / 100);
  }
  if (Number(monsterDef(defender)?.rank) >= 3) {
    damage += combatOptionValue(attacker, 'SIZEDAMAGERATE_BOSS_ADD');
    damage *= Math.max(0, 1 + (combatOptionPercent(attacker, 'SIZEDAMAGERATE_RESERVED_5') + combatOptionPercent(attacker, 'SIZEDAMAGERATE_BOSS_MUL')) / 100);
  }
  damage *= Math.max(0, 1 + combatOptionPercent(defender, 'STATUS_EX_MONSTER_TOLERANCE_DOWN') / 100);
  return round ? Math.max(1, Math.round(damage)) : Math.max(0, damage);
}
/** Stunned / rooted (ACTION_DISALLOW_MOVE, e.g. Death scythe). */
export function isDisabled(actor) {
  return statusValue(actor, 'ACTION_DISALLOW_MOVE') > 0 || statusValue(actor, 'ACTION_DISALLOW_ALL') > 0;
}

// ------------------------------------------------------------------ attack resolution
const MONSTER_ATTACK_ORDER = ['melee', 'range', 'aggro1', 'powerMelee', 'specialMelee', 'greatMelee', 'powerRange',
  'specialRange', 'greatRange', 'aggro2', 'aggro3', 'aggro4'];

/** Default attack key of a monster (first usable block). */
export function defaultAttackKey(def) {
  const A = def?.attacks || {};
  for (const k of MONSTER_ATTACK_ORDER) if (A[k]) return k;
  return null;
}

const SKILL_KIND = { melee: 'melee', range: 'range', magic: 'magic', heal: 'magic', status: 'magic', area_status: 'magic' };

function attackProfile(attacker, opts, F) {
  const st = attacker.stats;
  if (st && attacker.kind !== 'monster') {
    let kind = opts.kind || SKILL_KIND[opts.skill?.type] || st.attackType || 'melee';
    const lo = { melee: st.meleeMin, range: st.rangeMin, magic: st.magicMin };
    const hi = { melee: st.meleeMax, range: st.rangeMax, magic: st.magicMax };
    if (!(hi[kind] > 0)) {
      // e.g. a 'range' skill on a class without a ranged weapon: use the strongest damage it has
      kind = ['melee', 'range', 'magic'].reduce((b, k) => ((hi[k] || 0) > (hi[b] || 0) ? k : b), st.attackType || 'melee');
    }
    return {
      kind, min: lo[kind] ?? st.attackMin ?? 1, max: hi[kind] ?? st.attackMax ?? 1, absMin: 0, absMax: 0,
      rating: st.hitRate ?? levelOf(attacker) * 14, critRate: st.critRate ?? 5, critMult: st.critMultiplier ?? 1.5,
    };
  }
  const def = monsterDef(attacker) || {};
  const key = opts.attackKey || defaultAttackKey(def);
  const a = (key && def.attacks?.[key]) || null;
  const lv = levelOf(attacker);
  const mul = Number(F.fMonAttDamageRatio) || 1;
  const kind = opts.kind || (key && /range/i.test(key) ? 'range' : 'melee');
  // monsters without an attack block (objects) still hit weakly if something makes them attack
  const min = a ? a[0] : lv * 3, max = a ? a[1] : lv * 3.3;
  return {
    kind, attackKey: key, min: min * mul, max: max * mul, absMin: a ? a[2] || 0 : 0, absMax: a ? a[3] || 0 : 0,
    rating: lv * 14, critRate: 3, critMult: 1.5,
  };
}

function defenceProfile(defender, F) {
  const st = defender.stats;
  if (st && defender.kind !== 'monster') {
    return {
      def: st.defense || 0, dodge: st.dodge ?? levelOf(defender) * 10, magicResist: st.magicResist || 0,
      blockRate: st.blockRate || 0, guardRate: st.guardRate || 0, guardEff: st.guardEfficiency || 0,
    };
  }
  const def = monsterDef(defender) || {};
  const d = Array.isArray(def.def) ? def.def : [0, 0];
  const lv = levelOf(defender);
  const guard = Array.isArray(def.guard) ? def.guard : [0, 0];
  const defMul = (Number(F.fMonDefRatio) || 1) * (1 + (statusValue(defender, 'DEFENSE_MUL') - statusValue(defender, 'DEFENSE_SUB')) / 100);
  return {
    def: randRange(d[0] || 0, d[1] || d[0] || 0) * defMul,
    dodge: lv * 12,
    magicResist: Array.isArray(def.resist) ? def.resist[7] || 0 : 0,
    blockRate: def.blockRate || 0, guardRate: guard[0] || 0,
    // monster GuardEfficiency values are per-mille-ish (180..2394); read >100 as tenths of a percent, max 75%
    guardEff: Math.min(75, guard[1] > 100 ? guard[1] / 10 : guard[1] || 0),
  };
}

/** Chance (0..100) that `attacker` hits `defender`. */
export function hitChance(attacker, defender, opts = {}, F = formulaOf(attacker?.game?.data || defender?.game?.data)) {
  const A = opts._profile || attackProfile(attacker, opts, F);
  const D = opts._defence || defenceProfile(defender, F);
  const ar = Math.max(1, A.rating), dr = Math.max(1, D.dodge);
  let hit = F.fDefaultAttackProb + F.fMaxAttackProbFactor * ar / (ar + dr);
  const diff = levelOf(defender) - levelOf(attacker);
  hit -= diff > 0 ? diff * 2 : diff; // diff<0 adds |diff|
  if (opts.skill) hit += 10;
  if (A.kind === 'magic') hit += 10;
  return Math.max(F.byMinAttackProbability, Math.min(F.byMaxAttackProbability, hit));
}

/**
 * Resolve one attack. attacker/defender are actors; opts:
 *   skill       classes.json skill (adds hit bonus, picks melee/range/magic base)
 *   multiplier  scales the rolled base damage (default 1)
 *   addDamage   flat skill damage (per hit)
 *   attackKey   monster attack block ('melee', 'range', 'powerMelee', ...)
 *   kind        force 'melee' | 'range' | 'magic'
 *   noMiss      always hit (damage over time, scripted hits)
 * Returns { amount, crit, miss, guard, kind }.
 */
export function resolveAttack(attacker, defender, opts = {}) {
  const res = { amount: 0, crit: false, miss: true, guard: false, block: false, kind: 'melee' };
  if (!attacker || !defender || defender.dead) return res;
  const F = formulaOf(attacker.game?.data || defender.game?.data || opts.data);
  const A = attackProfile(attacker, opts, F);
  const D = defenceProfile(defender, F);
  res.kind = A.kind;
  if (A.attackKey) res.attackKey = A.attackKey;

  if (!opts.nativeBrick && !opts.noMiss && rand() * 100 >= hitChance(attacker, defender, { ...opts, _profile: A, _defence: D }, F)) return res;
  res.miss = false;

  const multiplier = opts.multiplier ?? 1;
  let raw = randRange(A.min, Math.max(A.min, A.max)) * multiplier + (Number(opts.addDamage) || 0);
  // debuffs on the attacker (e.g. Segnale "Decrease attack": DAMAGE_PHYSICAL_SUB 6 = -6 %)
  if (attacker.kind === 'monster') {
    const sub = A.kind === 'magic' ? statusValue(attacker, 'DAMAGE_MAGICAL_SUB')
      : A.kind === 'range' ? statusValue(attacker, 'RANGE_DAMAGE_RANGECAL_SUB') + statusValue(attacker, 'DAMAGE_PHYSICAL_SUB')
        : statusValue(attacker, 'DAMAGE_PHYSICAL_SUB');
    raw *= Math.max(0, 1 - sub / 100);
  }

  // Host-owned siege bricks use the authored weapon/skill damage and their own
  // exact brick resistance stage. Ordinary monster crit/guard, defense curves,
  // penetration, boss bonuses and crest elements do not replace that stage.
  if (opts.nativeBrick) { res.amount = Math.max(0, Math.round(raw)); return res; }

  const aLv = levelOf(attacker);
  const raw_ = defender.stats?.raw || {};
  const limit = (Number(raw_.LIMIT_DAMAGE_DECREASE_RATE) || 75) / 100;
  let red;
  if (A.kind === 'magic') {
    const eff = penetratedDefense(attacker, D.def * 0.5 + D.magicResist, A.kind);
    red = eff / (eff + aLv * 195 + 250);
  } else {
    const defense = penetratedDefense(attacker, D.def, A.kind);
    red = defense / (defense + aLv * 125 + 250);
  }
  red = Math.max(0, Math.min(limit, red));
  let dmg = raw * (1 - red);

  if (rand() * 100 < criticalChance(attacker, defender, A.critRate)) { res.crit = true; dmg *= criticalDamageMultiplier(attacker, defender, A.critMult); }
  // Shared player skills apply the authoritative PvP block/guard stage later;
  // resolving either here would roll and reduce the same native option twice.
  const pvp = attacker.kind === 'player' && defender.kind === 'player';
  const block = pvp ? 0 : blockChance(attacker, defender, D.blockRate), guard = pvp ? 0 : guardChance(attacker, defender, D.guardRate);
  // ENGINE-CHOSEN ordinary PvE block: a successful block prevents this hit.
  // Native BlockRate and BLOCKING clips establish the context; PK90 is a
  // separate PvP formula and is not reused here. No extra roll without block.
  if (block > 0 && rand() * 100 < block) { res.block = true; return res; }
  if (guard > 0 && rand() * 100 < guard) { res.guard = true; dmg *= 1 - guardEfficiency(defender, D.guardEff) / 100; }
  dmg += randRange(A.absMin || 0, Math.max(A.absMin || 0, A.absMax || 0));
  res.amount = opts.deferFinalModifiers ? Math.max(1, Math.round(dmg)) : modifyHitDamage(attacker, defender, dmg);
  return res;
}

// ------------------------------------------------------------------ applying damage
/**
 * Apply a resolved attack: HP, 'damage' event, hit reaction / retaliation, and on a kill the 'death' event,
 * experience (level-difference rate) and loot. Dead actors ignore damage; HP never goes below 0.
 * Returns true if the defender was affected.
 */
export function applyDamage(game, attacker, defender, result) {
  if (game?.save?.authority === 'server' || game?.network?.active) return false;
  if (!defender || defender.dead || !result) return false;
  const now = game?.time || 0;
  markCombat(attacker, now);
  markCombat(defender, now);
  // systems may adjust a landed hit before it applies (skills: damage-taken statuses, shields, damage share)
  const hooks = game?.combatHooks?.beforeDamage;
  if (hooks && hooks.length && !result.miss) {
    for (const h of hooks) { try { h(attacker, defender, result); } catch (err) { console.warn('beforeDamage hook failed', err); } }
  }
  const miss = !!result.miss;
  const amount = miss ? 0 : Math.max(0, Math.round(Number(result.amount) || 0));
  defender.hp = Math.max(0, (Number(defender.hp) || 0) - amount);
  if (attacker) defender.lastAttacker = attacker;

  // Both local play and the host run this path at impact, including remotes.
  // Charge before the death callback can replace or dismiss the servant.
  if (attacker?.kind === 'servant') game?.summons?.onDamage?.(attacker, defender, { ...result, amount });

  game?.events?.emit('damage', {
    source: attacker || null, target: defender, amount, shieldDamage: miss ? 0 : Math.max(0, Math.round(Number(result.shieldDamage) || 0)), crit: !!result.crit, miss,
    guard: !!result.guard, block: !!result.block, kind: result.kind || null, skill: result.skill || null, dot: !!result.dot,
    attackKey: result.attackKey || null, status: result.status || null,
  });

  if (defender.hp <= 0) {
    kill(game, defender, attacker);
    return true;
  }
  // reactions: monsters retaliate / flinch through their brain, the player through the controller
  try {
    if (defender.brain?.onDamaged) defender.brain.onDamaged(attacker, amount, result);
    else if (defender === game?.player) game.controller?.onDamaged?.(attacker, amount, result);
  } catch (err) { console.warn('damage reaction failed', err); }
  return true;
}

/** Kill an actor: 'die' animation, 'death' event, exp + loot for the player's kills, death penalty for the player. */
export function kill(game, actor, killer = null) {
  if (game?.save?.authority === 'server' || game?.network?.active) return;
  if (!actor || actor.dead) return;
  const now = game?.time || 0;
  actor.hp = 0;
  actor.dead = true;
  actor.diedAt = now;
  actor.killer = killer || null;
  if (actor.kind === 'monster') actor.target = null;
  playOnce(actor, 'die', { loop: false }, now, Infinity);
  try { actor.brain?.onDeath?.(killer); } catch (err) { console.warn(err); }

  game?.events?.emit('death', { actor, killer: killer || null });

  const player = game?.player;
  if (actor.kind === 'monster' && killer && (killer === player || killer.owner === player)) {
    const def = monsterDef(actor) || {};
    try { grantExp(game, Number(def.exp) || 0, Number(def.level ?? actor.level) || 1); } catch (err) { console.warn('exp failed', err); }
    try { game.loot?.dropFrom?.(actor); } catch (err) { console.warn('loot failed', err); }
  }
  if (actor === player) {
    applyDeathPenalty(game);
    try { game.controller?.onPlayerDeath?.(killer); } catch (err) { console.warn(err); }
  }
}

/** Heal an actor (capped at maxHp). Emits 'heal' and shows a floater. Returns the HP actually restored. */
export function heal(game, source, target, amount) {
  if (game?.save?.authority === 'server' || game?.network?.active) return 0;
  if (!target || target.dead || !(amount > 0)) return 0;
  const max = target.maxHp ?? target.hp;
  const before = target.hp;
  target.hp = Math.min(max, before + Math.round(amount));
  const got = target.hp - before;
  game?.events?.emit('heal', { source, target, amount: got });
  try { game?.hud?.floater?.(target, `+${got}`, 'heal'); } catch { /* HUD optional */ }
  return got;
}

export { COMBAT_TIMEOUT };
