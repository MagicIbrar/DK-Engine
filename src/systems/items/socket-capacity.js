// Limits from the publisher's Socket Refinement guide, read 2026-09-30:
// https://dekaron.ubifungames.com/Board/GameGuide?guideNo=3
// Native type/code mapping: tools/build-items.mjs UPGRADE_CATEGORY / UPGRADE_GRADE.
// Null means the guide does not identify this native family/variant, or the item
// is authored/custom. Drop distributions are not generally service capacities.
const NATIVE_ORIGINS = new Set(['weapon','armor','accessory','cash','event_cash','etc','event_etc','mileage']);
const EPIC_RANKS = new Set([10,12,13,14,15]);
const WEAPON_LIMITS = new Map([[0,2],[1,3],[2,4],[4,4],[6,3],[7,4],[8,3],[9,4],[10,4],[11,4],[12,4],[14,3],[17,3],[18,3],[20,4],[21,2],[22,4],[23,4],[24,4],[25,4],[26,4],[27,4],[28,4],[34,4],[35,4]]);
export function documentedSocketLimit(db, def) {
  if (!def || !NATIVE_ORIGINS.has(def.src) || def.customId || def.custom) return null;
  const type = Number(def.type), code = Number(def.code);
  if (type === 4) {
    // SHORT_SWORD is the native dagger; LONG_SWORD records name Great Sword.
    // GUN/CANNON records name Pierce/Blast. Unlisted Lily/Cloche/Espada/
    // Laevateinn and polearm families deliberately have no publisher mapping.
    if (code === 13) {
      // The guide explicitly distinguishes 2-slot partial wands from 3-slot
      // wands. Only native records authored with exactly 2 or 3 drop positions
      // identify that distinction; zero/other distributions remain unresolved.
      const count = (def.socketRates || []).reduce((n,r,i)=>Number(r)>0?i+1:n,0);
      return count === 2 || count === 3 ? count : null;
    }
    return WEAPON_LIMITS.get(code) ?? null;
  }
  if (type === 5) {
    if (code === 0 || code === 1) return 4; // helmet / armor
    if ((code === 2 || code === 4) && EPIC_RANKS.has(Number(def.rank))) return 4;
    if (code === 3) return 0; // publisher explicitly excludes boots
    if (code === 11 || code === 15) return 1; // bracelet / unique bracelet
    if (code === 12 || code === 16) return 2; // belt / unique belt
    return null; // no inferred non-Epic glove/pants or costume rules
  }
  if (type === 2 && [0,10,14].includes(code)) return 0; // necklace / earrings
  if (type === 6 && code === 1) return 2;
  if (type === 6 && code === 5) return 1; // cap only; no new pet service/rank rule
  return null;
}
