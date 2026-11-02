// Monster AI rules shared by the offline brain (src/game/ai.js) and the authoritative server (server/world/core.mjs).
// Pure functions over a monsters.json definition; no actor classes, no browser, no server state.
//
// Data sources (per monster, monsters.json built by tools/build-monsters.mjs):
//   def.ai.sight      share/ai/info.csv DwSight          cells a monster notices a player in (SIGHT_IN)
//   def.ai.pursuit    share/ai/info.csv DwPersuitRange   cells from home before it gives up (PERSUIT_OUT); "home" = the roaming centre roamCentre():
//                     the spawn until a chase ends, then the point where it ended (explore.anchor 'ended': the leash follows the monster)
//   def.ai.aggressive share/ai/pattern/<pattern>.csv     SIGHT_IN,REST -> PERSUIT (patterns 1/3/5/6/8/9/11)
//   def.ai.pattern    share/ai/patterninfo.csv index     3/6/9/12 = Range_* files: MELEE_ATTACK_IN,REST -> RANGE_ATTACK
//   def.ai.callTeam   share/ai/info.csv [DwCallTeamPossibelHP, DwCallTeamCount, dwCallTeamCell] (patterns 4/5/6 only)
//   def.ai.aggroRates share/ai/info.csv dwAttack1..4_Rate (aggro-table patterns 10/11 pick aggro1..4 by weight)
//   def.ai.special / def.ai.power   info.csv [StartHP, MeleeRate, RangeRate, dwSpecialAttackRate|dwPowerRate, DelayTime]
//   def.speed         monster.dat [WalkSpeed, RunSpeed]; def.width monster.dat Width
//   def.attacks[key]  share/ai/monsterbattle.csv blocks [min, max, absMin, absMax, CellRange, AttackDelay, material, resultCode, ...]
// Everything that is NOT in the data (fallbacks, paddings, the explore anchor) lives in
// src/config/engine-chosen-monster-ai.js and is tagged ENGINE-CHOSEN there.
// A monster has NO regeneration, evade, "full heal" or "walk home" behaviour: none is listed in share/ai (the pattern tables only
// know the modes EXPLORE / PERSUIT / MELEE_ATTACK / RANGE_ATTACK; the monsterbattle.csv HPRecovery column is 0 for 4516 of 4590
// rows and its unit is not stated anywhere, so it is not implemented). Giving up a chase = PERSUIT_OUT = persuitOutRule().
import { MONSTER_AI_ENGINE_CHOSEN as C } from '../config/engine-chosen-monster-ai.js';
import { optionSum, flagsOf } from '../systems/skills/statuses.js';

const num = (v, d = 0) => (v === undefined || v === null || !Number.isFinite(+v) ? d : +v);
export const dist = (a, b) => Math.hypot((a?.x || 0) - (b?.x || 0), (a?.z || 0) - (b?.z || 0));

/** monsters.json attackActionIndex: attack block key -> ATTACK clip index (monster.dat action set). */
export const ATTACK_INDEX = Object.freeze({
  melee: 0, powerMelee: 1, specialMelee: 2, greatMelee: 3, range: 4, powerRange: 5, specialRange: 6, greatRange: 7,
  heal: 8, revive: 9, aggro1: 10, aggro2: 11, aggro3: 12, aggro4: 13,
});
export const attackVariant = key => ATTACK_INDEX[key] ?? 0;
/** 'range' for the range blocks (range / powerRange / specialRange / greatRange), else 'melee'. */
export const attackKind = key => (/range/i.test(key || '') ? 'range' : 'melee');
const AGGRO_KEYS = ['aggro1', 'aggro2', 'aggro3', 'aggro4'];
const NON_ATTACK = new Set(['heal', 'revive']);
/** share/ai/patterninfo.csv: 3 Range_Attack, 6 RangeCall_Attack, 9 Range_Attack_noex, 12 Negative_Range_Attack. */
const RANGE_PATTERNS = new Set([3, 6, 9, 12]);

// ------------------------------------------------------------------------------------------------ radii / speeds
/** SIGHT_IN radius in cells: info.csv DwSight. Only a MISSING value falls back (ENGINE-CHOSEN 8); 0 stays 0. */
export function aggroRadius(def) { return Math.max(0, num(def?.ai?.sight, C.defaultSight)); }
/** PERSUIT_OUT radius from home in cells: info.csv DwPersuitRange. Only a MISSING value falls back (ENGINE-CHOSEN 20). */
export function leashRange(def) { return Math.max(0, num(def?.ai?.pursuit, C.defaultPursuit)); }
/** Wander radius: info.csv DwExploreRange. */
export function exploreRange(def) { return Math.max(0, num(def?.ai?.explore, C.defaultExplore)); }
/**
 * info.csv DwAvoidRange (monsters.json ai.avoid). Present on every info row (hist: 6/0/3/5/4).
 * Native client enum lists AVOID as a pattern MODE and EVENT, but shipped share/ai/pattern/*.csv
 * never transitions to AVOID and has no AVOID event rows. Behavior that would consume this radius
 * is UNRESOLVED — do not invent a flee formula. Accessor only exposes the data value.
 */
export function avoidRange(def) { return Math.max(0, num(def?.ai?.avoid, 0)); }
/**
 * info.csv delay quartet (ms), monsters.json ai.delays:
 *   [0] DwExploreStandDelay — used by offline brain / server idle as the explore stand wait (with 0.6..1.4 jitter).
 *   [1] DwExploreMoveDelay  — DATA present; no shipped pattern / brain consumption found (UNRESOLVED).
 *   [2] DwStandDelay        — DATA present; UNRESOLVED for combat stand.
 *   [3] DwMoveDelay         — DATA present; UNRESOLVED for combat move.
 * Missing delays fall back to the monsters.json default [2000,2000,1200,1000] (build-monsters.mjs).
 */
export function exploreStandDelayMs(def) { return Math.max(0, num(def?.ai?.delays?.[0], 2000)); }
export function exploreMoveDelayMs(def) { return Math.max(0, num(def?.ai?.delays?.[1], 2000)); }
export function standDelayMs(def) { return Math.max(0, num(def?.ai?.delays?.[2], 1200)); }
export function moveDelayMs(def) { return Math.max(0, num(def?.ai?.delays?.[3], 1000)); }
/**
 * Does this monster roam in EXPLORE at all? DwExploreRange > 0 AND monster.dat WalkSpeed > 0 (the condition the idle code of both
 * sides always used). Only such a monster moves in EXPLORE; the others (explore range 0: 339 mobile rows, WalkSpeed 0: 421 combat
 * rows such as 116 Dark Avenger [0, 4.4]) stand still and get NO walk back after PERSUIT_OUT (no speed is borrowed from RunSpeed).
 */
export function roamsInExplore(def) { return exploreRange(def) > 0 && walkSpeed(def) > 0; }
/**
 * ENGINE-CHOSEN (the data does not say what EXPLORE roams around): the
 * explore area is the disc of radius DwExploreRange around the monster's ROAMING CENTRE, which is its spawn until a chase ends and
 * the point where that chase ended afterwards (engine-chosen-monster-ai.js explore.anchor 'ended'; rehomesAtPersuitOut). True only
 * for a monster that roams (roamsInExplore) and stands outside that disc; callers pass the roaming centre as `home`. Since PERSUIT_OUT
 * moves the centre to the monster itself, this is false after a give-up (nothing walks back); it is kept for anchor 'home'.
 */
export function outsideExploreArea(def, m, home) {
  return roamsInExplore(def) && dist(m, home) > exploreRange(def);
}
/** engine-chosen-monster-ai.js explore.anchor: does PERSUIT_OUT move the ROAMING centre to where the monster stands? */
export const rehomesAtPersuitOut = () => C.explore.anchor === 'ended';
/**
 * Which monsters PERSUIT_OUT re-homes: only ones that roam at all (roamsInExplore) and only when the key says 'ended'. Non-roamers
 * (explore range 0, WalkSpeed 0) have nothing to roam around, so they are left exactly as before; the server also skips event
 * marchers (m.eventMarch) at the call site.
 */
export const rehomes = def => rehomesAtPersuitOut() && roamsInExplore(def);
/**
 * The roaming centre of a server monster: `m.anchor` (set by PERSUIT_OUT, cleared at respawn) else `m.home`. It is ALSO the origin the pursuit range is measured from, so every
 * canAcquire / shouldLeash call of the server tick passes roamCentre(m) as `home`: the leash follows the monster at each give-up, a monster
 * whose target is still in sight follows on, and nothing walks back. `m.home` itself stays the ORIGINAL spawn (respawn point, never
 * written by the AI). Offline: `brain.anchor || brain.home` (ai.js).
 */
export const roamCentre = m => m.anchor || m.home;
/** monster.dat WalkSpeed (cells/s). */
export function walkSpeed(def) { const sp = Array.isArray(def?.speed) ? def.speed : []; return Math.max(0, num(sp[0], 1)); }
/** Chase speed = monster.dat RunSpeed (cells/s), never below the walk speed; missing -> walk x 2.5 (ENGINE-CHOSEN). */
export function chaseSpeed(def) { const sp = Array.isArray(def?.speed) ? def.speed : [], walk = walkSpeed(def); return Math.max(walk, num(sp[1], walk * C.runFromWalk)); }
/**
 * Walk vs run gait from a measured cells/s speed vs monster.dat WalkSpeed/RunSpeed.
 * Midpoint between walk and run is ENGINE-CHOSEN (tick jitter); returns 'walk' | 'run' | null.
 * Used by remote monster clip selection when the host does not publish row.walk.
 */
export function gaitFromMeasuredSpeed(def, spd) {
  const walk = walkSpeed(def), run = chaseSpeed(def);
  if (!(walk > 0) || !Number.isFinite(spd) || spd < 0) return null;
  const mid = walk + (run - walk) * 0.5;
  return spd <= mid + 1e-6 ? 'walk' : 'run';
}
/** speed [0, 0]: fights without moving (plants, crystals, the Racoon). */
export function isImmobile(def) { return walkSpeed(def) <= 0 && chaseSpeed(def) <= 0; }
/** Body radius when no mesh is measured (src/actors/monster.js:84): max(0.4, Width x 0.45), else 0.5. */
export function bodyRadius(def) {
  const w = num(def?.width, 0);
  return Math.max(C.bodyRadius.min, w > 0 ? w * C.bodyRadius.widthFactor : C.bodyRadius.fallback);
}
export function isRangeStyle(def) { return RANGE_PATTERNS.has(Number(def?.ai?.pattern)); }

// ------------------------------------------------------------------------------------------------ what can fight
/**
 * Never acquires a target and never attacks: event objects (role 'object' / pattern 7: event.csv has EXPLORE on every row)
 * and traps (pattern 13: trap.csv acts only through OPERATION_REPEAT -> TRAP_ATTACK, which no side implements yet).
 * Role 'invisible' (rows without a texture pack, e.g. 5910 Mana_Mon, 7420-7424 A_trap, 8123-8135 boss tags) is included for
 * parity with the offline client (ai.js / spawner.js never fight or spawn them). ENGINE-CHOSEN: those rows are pattern-1
 * effect sources whose ResultCode status application (monsterbattle v3 = status index, v4 = duration) is not implemented;
 * until it is, treating their melee block as raw damage would be wrong on either side.
 */
export function isNonCombatant(def) {
  const p = Number(def?.ai?.pattern);
  return def?.role === 'object' || def?.role === 'invisible' || p === 7 || p === 13;
}
/**
 * Can an enemy-target skill hit this monster row? Invisible rows (trap / trigger volumes) never; role 'object' rows
 * (boxes, chests, crystals: pattern 7/13) when the authored def says attackable (siege gates/stones) or when Global
 * monster.csv `Target` (flags[0], build-monsters.mjs:1467) is 0, the same targetable value 3610 of 3617 creatures carry.
 * Rows with Target 1 (34 of 770 objects; invisible rows are excluded anyway) stay excluded. Damage and rewards are unchanged:
 * this only stops the skill engine refusing a target the player can already click and basic-attack.
 */
export function skillTargetable(def) {
  if (!def || def.role === 'invisible') return false;
  if (def.role !== 'object') return true;
  return !!def.attackable || Number(def.flags?.[0] || 0) === 0;
}
/** Has a usable attack block (anything but heal / revive) and is not a non-combatant. */
export function canAttack(def) {
  if (!def || isNonCombatant(def) || !def.attacks) return false;
  return Object.keys(def.attacks).some(k => !NON_ATTACK.has(k));
}
/** A monsterbattle filler block (every value equal, e.g. 8112 greatMelee [33,33,33,33,33,33,5,33]). */
export function isFillerBlock(block) {
  if (!Array.isArray(block)) return true;
  const v = block.filter((x, i) => i !== 6 && typeof x === 'number');
  return v.length >= 6 && v.every(x => x === v[0]);
}
/** The call pattern parameters {count, cells} (info.csv DwCallTeamCount / dwCallTeamCell) for patterns 4/5/6, else null. */
export function callTeamRule(def) {
  const ct = def?.ai?.callTeam;
  if (!Array.isArray(ct)) return null;
  return { possibleHp: num(ct[0], 0), count: Math.max(1, num(ct[1], 1)), cells: Math.max(0, num(ct[2], 4)) };
}

// ------------------------------------------------------------------------------------------------ reach
/** Centre-to-centre reach of an attack block: CellRange + body radius x 0.5 + target radius, at least 1.2 (ENGINE-CHOSEN padding). */
export function reach(def, key, mRadius, tRadius) {
  const a = def?.attacks?.[key];
  const range = a ? num(a[4], C.reach.defaultRange) : C.reach.defaultRange;
  const mr = mRadius > 0 ? mRadius : bodyRadius(def);
  const tr = tRadius > 0 ? tRadius : C.reach.targetRadius;
  return Math.max(C.reach.min, range + mr * C.reach.ownRadiusFactor + tr);
}
/** Distance at which the chase stops: the longest of the melee / range / aggro1 reaches (range monsters stop at bow range). */
export function preferredReach(def, mRadius, tRadius) {
  const A = def?.attacks || {};
  let best = 0;
  for (const k of ['melee', 'range', 'aggro1']) if (A[k]) best = Math.max(best, reach(def, k, mRadius, tRadius));
  if (!best) for (const k of Object.keys(A)) if (!NON_ATTACK.has(k) && !isFillerBlock(A[k])) best = Math.max(best, reach(def, k, mRadius, tRadius));
  return best || reach(def, 'melee', mRadius, tRadius);
}

// ------------------------------------------------------------------------------------------------ acquire / leash
/**
 * SIGHT_IN: the target is within `sight` of the monster AND within `pursuit` of the monster's home (the second test is the
 * engine inference described in engine-chosen-monster-ai.js leash.targetFromHomeAddsSight). Callers pass the effective radii
 * (aggroRadius / leashRange, or an event override) so the same test runs on both sides.
 */
export function canAcquire({ sight, pursuit }, m, home, t) {
  // dist(m, home) <= pursuit is the same inference seen from the monster: a monster beyond the pursuit range of its home would
  // flip between chase and EXPLORE every tick. `home` is the roaming centre (roamCentre: the spawn, or where the last chase ended,
  // explore.anchor 'ended'): a re-homed monster is always inside its own range, so it aggros again whenever the player is in sight.
  return dist(m, t) <= sight && dist(t, home) <= pursuit && dist(m, home) <= pursuit;
}

/**
 * share/ai/pattern/<file>.csv, the PERSUIT_OUT rows (every CURRENT_STATE REST / FEAR / UNCARING / ANNOYED / RAGE / BERSERK has
 * the same NEXT_STATE and NEXT_MODE in a file), keyed by share/ai/patterninfo.csv PatternIndex:
 *   UNCARING  Negative_Attack 2, NegativeCall_Attack 4, Aggro_Negative_Attack 10, Negative_Range_Attack 12, Call 1000, Stop 1002
 *   FEAR      Positive_Attack 1, Range_Attack 3, PositiveCall_Attack 5, RangeCall_Attack 6, Event 7, Positive_Attack_noex 8,
 *             Range_Attack_noex 9, Aggro_Positive_Attack 11, Regulus 20, Grupain 21, Tarantula 22, Aldebaran 23
 *   (Trap 13 has no PERSUIT_OUT row.) NEXT_MODE is EXPLORE in every file except Positive_Attack_noex / Range_Attack_noex / Call /
 *   Stop, whose mode column is __MAX_ (not a mode; meaning unknown, treated as "no mode set": the chase still ends).
 * tools/test-monster-rules.mjs re-reads the real CSVs and compares them with this table.
 */
const PERSUIT_OUT_ROWS = Object.freeze({
  1: ['FEAR', 'EXPLORE'], 2: ['UNCARING', 'EXPLORE'], 3: ['FEAR', 'EXPLORE'], 4: ['UNCARING', 'EXPLORE'], 5: ['FEAR', 'EXPLORE'],
  6: ['FEAR', 'EXPLORE'], 7: ['FEAR', 'EXPLORE'], 8: ['FEAR', null], 9: ['FEAR', null], 10: ['UNCARING', 'EXPLORE'],
  11: ['FEAR', 'EXPLORE'], 12: ['UNCARING', 'EXPLORE'], 20: ['FEAR', 'EXPLORE'], 21: ['FEAR', 'EXPLORE'], 22: ['FEAR', 'EXPLORE'],
  23: ['FEAR', 'EXPLORE'], 1000: ['UNCARING', null], 1002: ['UNCARING', null],
});
/**
 * PERSUIT_OUT for this monster's own pattern: {state, mode} = NEXT_STATE / NEXT_MODE of the pattern table, or null when the
 * pattern has no PERSUIT_OUT row (Trap). The monster stops chasing, forgets its hostility and takes `state`; `mode` EXPLORE
 * (null = the table's __MAX_) is its normal roaming. UNDER_ATTACK from FEAR / UNCARING is RAGE in every table row
 * (UNDER_ATTACK_STATE), i.e. a hit re-engages it.
 */
export function persuitOutRule(def) {
  const row = PERSUIT_OUT_ROWS[Number(def?.ai?.pattern)];
  return row ? { state: row[0], mode: row[1] } : null;
}
export const UNDER_ATTACK_STATE = 'RAGE';
export const REST_STATE = 'REST';
/**
 * PERSUIT_OUT. Mobile monsters: farther than `pursuit` from home (+ 2 while swinging), or the target farther than
 * pursuit + sight from home (engine inference, not applied while swinging in reach). Immobile monsters never leave home, so
 * they forget a target farther than forgetRange (max(sight, longest reach)) + 2 (ENGINE-CHOSEN).
 */
export function shouldLeash({ sight, pursuit, immobile = false, forgetRange = null }, m, home, t, { attacking = false } = {}) {
  if (immobile) return dist(m, t) > (forgetRange ?? sight) + C.leash.immobileForgetPad;
  if (dist(m, home) > pursuit + (attacking ? C.leash.attackPad : 0)) return true;
  if (!attacking && C.leash.targetFromHomeAddsSight && dist(t, home) > pursuit + sight) return true;
  return false;
}

// ------------------------------------------------------------------------------------------------ attack selection
/**
 * Pick the attack block for a target at distance `dist` (cells). Returns {key, block, specialReadyAt, powerReadyAt} or null
 * when nothing reaches (the caller then closes in). Order:
 *   1. special / power attacks (info.csv dwSpecial* / dwPower*): HP at or below StartHP, the per-kind rate (MeleeRate for a
 *      melee-distance swing, RangeRate for a range one), the block in reach, the DelayTime cooldown (ms). Index 3
 *      (dwSpecialAttackRate / dwPowerRate) is NOT read: 276 special and 275 power rows fill only it (e.g. 2333 Illipia
 *      [100,0,0,45,20000]) but its runtime meaning is unknown, so those rows never fire on either side.
 *   2. aggro-table blocks aggro1..4 weighted by dwAttack1..4_Rate over the blocks that reach (aggro_positive_attack.csv:
 *      every attack mode is AGGRO_ATTACK). dwAttackN_TargetType/Value are unknown and not read.
 *   3. the base block: range patterns (3/6/9/12) prefer 'range' whenever it reaches (range_attack.csv:74
 *      MELEE_ATTACK_IN,REST -> RANGE_ATTACK), the others prefer 'melee'.
 *   4. ENGINE-CHOSEN last resort only for a monster with no melee / range / aggro block at all (6129 Giant Herb has only a
 *      specialMelee): any non-filler, non-heal block in reach.
 * `rng` is called only when a chance or weight is actually rolled.
 */
export function chooseAttack(def, { dist: d = 0, hpPct = 100, nowMs = 0, specialReadyAt = 0, powerReadyAt = 0, rng = Math.random, mRadius, tRadius } = {}) {
  const A = def?.attacks || {}, ai = def?.ai || {};
  const result = { key: null, block: null, specialReadyAt: num(specialReadyAt, 0), powerReadyAt: num(powerReadyAt, 0) };
  const inReach = k => !!A[k] && d <= reach(def, k, mRadius, tRadius) + C.reach.swingSlack;
  const done = key => { result.key = key; result.block = A[key]; return result; };
  const melee = inReach('melee') || !inReach('range');
  const tryExtra = (arr, keyMelee, keyRange, readyKey) => {
    if (!Array.isArray(arr) || nowMs < result[readyKey]) return null;
    const [startHp, meleeRate, rangeRate, , cd] = arr;
    if (hpPct > (num(startHp, 0) || 100)) return null;
    const key = melee ? keyMelee : keyRange, rate = num(melee ? meleeRate : rangeRate, 0);
    if (!A[key] || !(rate > 0) || !inReach(key) || rng() * 100 >= rate) return null;
    result[readyKey] = nowMs + num(cd, 0);
    return key;
  };
  const extra = tryExtra(ai.special, 'specialMelee', 'specialRange', 'specialReadyAt') || tryExtra(ai.power, 'powerMelee', 'powerRange', 'powerReadyAt');
  if (extra) return done(extra);
  if (Array.isArray(ai.aggroRates) && AGGRO_KEYS.some(k => A[k])) {
    const w = AGGRO_KEYS.map((k, i) => (inReach(k) ? Math.max(0, num(ai.aggroRates[i], 0)) : 0));
    const sum = w.reduce((a, b) => a + b, 0);
    if (sum > 0) {
      let r = rng() * sum;
      for (let i = 0; i < AGGRO_KEYS.length; i++) if ((r -= w[i]) < 0) return done(AGGRO_KEYS[i]);
      return done(AGGRO_KEYS[w.findLastIndex(x => x > 0)]);
    }
  }
  const order = isRangeStyle(def) ? ['range', 'melee'] : ['melee', 'range'];
  for (const k of order) if (inReach(k)) return done(k);
  if (!A.melee && !A.range && !AGGRO_KEYS.some(k => A[k])) {
    for (const k of Object.keys(A)) if (!NON_ATTACK.has(k) && !isFillerBlock(A[k]) && inReach(k)) return done(k);
  }
  return null;
}

// ------------------------------------------------------------------------------------------------ call for help
/**
 * Recruit up to rule.count monsters within rule.cells of the caller (info.csv DwCallTeamCount / dwCallTeamCell).
 * canAnswer(o) is the engine's filter (idle, can attack, same scene; engine-chosen-monster-ai.js callTeam), engage(o) must
 * return true when the monster really took the target. Returns the number engaged.
 */
export function recruitCallTeam(candidates, caller, rule, { canAnswer, engage }) {
  if (!rule || !candidates) return 0;
  let n = 0;
  for (const o of candidates) {
    if (n >= rule.count) break;
    if (!o || o === caller || !canAnswer(o)) continue;
    if (dist(o, caller) > rule.cells) continue;
    if (engage(o)) n++;
  }
  return n;
}

// ------------------------------------------------------------------------------------------------ statuses on monsters
/** Movement multiplier from the monster's statuses (SPEED_MOVE_MUL / SPEED_MOVE_SUB in %, floor 10 %). */
export function statusSpeedMul(list) {
  if (!list || !list.length) return 1;
  const v = 1 + (optionSum(list, 'SPEED_MOVE_MUL') - optionSum(list, 'SPEED_MOVE_SUB')) / 100;
  return Math.max(C.statusSpeedMulMin, Number.isFinite(v) ? v : 1);
}
/** {move, attack, lock}: ACTION_DISALLOW_MOVE / ACTION_DISALLOW_ATTACK and the lock codes (sleep, purge, panic ...). */
export function statusFlags(list) {
  if (!list || !list.length) return { move: false, attack: false, lock: false };
  const f = flagsOf(list);
  return { move: !!f.move, attack: !!f.attack, lock: !!f.lock };
}

// ------------------------------------------------------------------------------------------------ respawn
/**
 * MON_*.csv column 2 (seconds; the meaning is inferred). Infinity (instance statics, event waves) stays Infinity. Every
 * other value follows the ENGINE-CHOSEN sanitising in engine-chosen-monster-ai.js respawn, the same on client and server.
 */
export function sanitizeRespawn(sec) {
  const s = Number(sec);
  if (s === Infinity) return Infinity;
  if (!Number.isFinite(s) || s <= 0) return C.respawn.defaultSec;
  if (s >= C.respawn.rareThresholdSec) return C.respawn.rareSec;
  return Math.max(C.respawn.minSec, s);
}
export function respawnDelayMs(sec) { return sanitizeRespawn(sec) * 1000; }
