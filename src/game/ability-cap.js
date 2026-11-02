// Level-difference ability caps (MAP-CAPS): share/maplist.csv StrAbilityCapPath -> share/pc/abilitycap*.csv
// (AbilityCap.csv on 134 maps, AbliityCap_Indun_01.csv on 144, Colosseum 15, Qune Temple, Kastrioti, Lost Horizon, Siz,
// Braiken broken). Columns: Level Cap, then the same seven names twice - Melee Decrease Rate, Magic Decrease Rate,
// Elemenet Decrease Rate, All Resist Rate, Miss Rate, Blocking Rate, Guard Rate.
// Reading (the file does not label the two blocks): column 0 is the level difference DEFENDER - ATTACKER (+250 .. -250,
// 0 at an equal level, rates rising with the gap). Block 1 = a character attacking a monster: a much stronger monster cuts
// the character's melee / magic damage by up to 30 % and adds up to 25 % misses, a much weaker one raises it. Block 2 =
// a monster attacking a character: against a much stronger character its damage drops (37.5 % melee / 75 % magic),
// against a much weaker one it rises (up to 9x at -250). Applied: the melee / magic decrease and the miss rate, and
// (MATH-VERIFY 4.3.2) the Blocking / Guard columns: the Global server's Computer methods 0x586ff0 (base +0x1f0 + row
// +0x18/+0x34) and 0x5870a0 (base +0x1f4 + row +0x1c/+0x38) add them to the block / guard chance with exactly the same
// level-gap row and block selection as the miss roll 0x586f40 (+0x14/+0x30). Element / All Resist are returned for
// callers (0x5874d0..); All Resist drives the Immune roll (0x587150, below).
export const CAP_COLUMNS = ['melee', 'magic', 'element', 'resist', 'miss', 'blocking', 'guard'];

/** Parse an ability cap CSV (rows of numbers) into {byDiff: Map(diff -> row), allZero}. */
export function abilityCapTable(rows) {
  const byDiff = new Map();
  let allZero = true;
  for (const r of rows || []) {
    const v = r.map(Number);
    if (!Number.isFinite(v[0]) || v.length < 15) continue;
    byDiff.set(Math.round(v[0]), v);
    if (v.slice(1).some(x => x !== 0)) allZero = false;
  }
  return byDiff.size ? { byDiff, allZero } : null;
}

// Block selection (MATH-VERIFY row 8, proven): every level-gap Computer method (0x586f40 miss, 0x586ff0 block, 0x5870a0
// guard, 0x587150.. resist/element/decrease) reads `attackerActor->vt+0x28` and uses block 2 only when it returns 1. The
// Actor providers' vt+0x28 are constants: PC 0 (0x4d3030), Monster 1 (0x4d1270), Guard 2, Servant 3, Remote 4, Brick 5,
// Sentry 6 (0x4cc750), Pet 7, Totem 8. So block 2 = a Monster attacking; every other attacker (character, servant, pet,
// totem, siege sentry, guard) uses block 1, whatever the defender is. 0x596890 passes the attacker actor (ebp) to all of them.
export const GLOBAL_ACTOR_TYPE = Object.freeze({ pc: 0, monster: 1, guard: 2, servant: 3, remote: 4, brick: 5, sentry: 6, pet: 7, totem: 8 });
/** true = block 1 (non-monster attacker). `kind` is the engine actor kind or a GLOBAL_ACTOR_TYPE key. */
export const capAttackerUsesBlock1 = kind => GLOBAL_ACTOR_TYPE[kind === 'player' ? 'pc' : kind] !== GLOBAL_ACTOR_TYPE.monster;

/** The capped modifiers for an attack: {damageMul, miss} (block 1 = player attacker, block 2 = monster attacker). */
export function abilityCapFor(table, { attackerLevel, defenderLevel, attackerIsPlayer, kind = 'melee' }) {
  const none = { damageMul: 1, miss: 0, blocking: 0, guard: 0, element: 0, resist: 0 };
  if (!table || table.allZero) return none;
  const diff = Math.max(-250, Math.min(250, Math.round((Number(defenderLevel) || 1) - (Number(attackerLevel) || 1))));
  const row = table.byDiff.get(diff);
  if (!row) return none;
  const o = attackerIsPlayer ? 1 : 8;
  const rate = kind === 'magic' ? row[o + 1] : row[o];
  const n = i => Number(row[o + i]) || 0;
  return { damageMul: Math.max(0, 1 - (Number(rate) || 0) / 100), miss: Math.max(0, n(4)),
    element: n(2), resist: n(3), blocking: n(5), guard: n(6) };
}

// STEP10-LANE51 Immune (ActivePoint subtype 0) - older server reference (DekaronServer.exe, static read): every hit caller
// runs the miss roll (Computer vf+0xc0 = 0x586f40) first; when it did not miss it calls vf+0xcc = 0x587150, and on 1 it
// sends ActivePoint subtype 0 (Immune, sender 0x593150) and ends the hit with no damage (e.g. 0x599028..0x5990ec).
// 0x587150: chance = defender base term + the ability-cap All Resist column (row +0x10 block 1 / +0x2c block 2, same
// level-gap row and block selection as the miss roll); Immune iff rand(0, 0x2710) <= trunc(chance * 100) ([0x961d7c] = 100.0).
// The defender base term reads a float of a struct that is not the State Provider (whose +0x1c8 is the WORD magic resist);
// no credible source names it -> REMOVED (base 0). No roll at all when the chance is 0 (so a zero chance never immunes).
/** One Immune roll on an All Resist chance (percent). rand() in [0, 1) -> integer 0..9999. */
export function immuneHit(chance, rand = Math.random) {
  const c = Number(chance) || 0;
  if (!(c > 0)) return false;
  return Math.floor(rand() * 10000) <= Math.trunc(c * 100);
}
/** Immune roll for an attack on the map's ability-cap table (All Resist column). */
export const immuneRoll = (table, attack, rand = Math.random) => immuneHit(abilityCapFor(table, attack).resist, rand);

/** Apply to a damage amount; returns {amount, miss} (+ immune: true when the 0x587150 roll hit). rand() in [0, 1). */
export function applyAbilityCap(table, attack, amount, rand = Math.random) {
  const c = abilityCapFor(table, attack);
  if (c.miss > 0 && rand() * 100 < c.miss) return { amount: 0, miss: true };
  // Immune ends the hit like a miss (old clients keep drawing Miss); immune: true lets this client draw the Immune word.
  if (immuneHit(c.resist, rand)) return { amount: 0, miss: true, immune: true };
  return { amount: c.damageMul === 1 ? amount : Math.max(1, Math.round(amount * c.damageMul)), miss: false,
    blocking: c.blocking, guard: c.guard };
}
