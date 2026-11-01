// ENGINE CHOICE for the one original Ice Castle call-monster row per tier that lies outside the 512-cell map. This is
// NOT a native Global rule and NOT an authored correction: no original server controller (maplist ScriptName
// Map_167_IceCastle ... Map_174_IceCastle) or client table says what the server does with the row.
//
// Original evidence (share/map/<tier>_icecastle_*/callmonster_*.csv, prepared events.json, Global Copy packs): call 53
// of every tier 167-174 carries `53,<base+36>,166,3752,0,1` (167: 6536; +100 per tier). Its other 23 rows stand at
// X 151-176 / Y 360-383 and are all walkable on dead_front_2.mac; Y=3752 is 3241 cells past the map edge. Unfixed, the
// shared host's nearestWalkable (edge clamp + 32-cell search) put that monster at 162.5,479.5 in the outer south-west
// corridor, the offline Waves kept it off the map where it could never load or die, and the row dragged call 53's
// centroid to 166,514.5 so IceCastleRun._guardGates tied call 53 to castle gate 119 (133 cells) instead of gate 123.
//
// The choice follows the owner's established pattern for 181 (X=7409 -> 209) and 235/264 (relocated fill): KEEP the
// monster with its native ID, Cell, Count and catalog stats, and correct only the likely typo coordinate, Y=3752 -> 375
// (one extra digit). 166,375 is a walkable original cell inside call 53's own cluster, reachable from the southern
// team routes and the sibling rows (tools/test-ice-castle-native-call-corrections.mjs re-derives this on every tier,
// with the stated fallback search). The monster stays required, so call 53 (24 monsters) guards gate 123 by the
// existing nearest-gate inference in icecastle.js. This exact entry is not individually owner-approved.
//
// Event call rows are [monsterIndex, x, y, cell, count] (tools/build-events.mjs).

export const ENGINE_CHOICE = 'ENGINE CHOICE';
export const APPROVAL = 'typo-coordinate correction following the owner-approved 181 / 235 / 264 pattern (relayed by the round-3 coordinator, 2026-10-12); not individually owner-approved';

const ICE_CASTLE_TIERS = Object.freeze([167, 168, 169, 170, 171, 172, 173, 174]);
/** Deterministic fallback when the typo cell is not walkable/reachable on a tier: rings outward, then smaller z, then x. */
export const RELOCATION_RULE = Object.freeze({
  target: 'Y=3752 read as Y=375 (one extra digit), X kept: cell 166,375',
  eligible: 'walkable on the bound original MAC with every authored brick standing, and in the same 4-neighbour component as the southern team starts and call 53\'s 23 authored rows',
  fallback: 'nearest eligible cell to 166,375 by Chebyshev ring, then Euclidean distance, then smaller z, then smaller x (not needed on any tier)',
});
const EVIDENCE = 'Original call 53 row Y=3752 is outside the 512x512 dead_front_2.mac grid on every tier (byte-identical in the Global Copy '
  + 'pack); its 23 sibling rows lie at Y 360-383. Keeping the native monster and correcting the likely extra digit (3752 -> 375) mirrors '
  + 'the owner-approved 181 X=7409 -> 209 fix; 166,375 is walkable and reachable on every tier.';

export const NATIVE_EVENT_CALL_CORRECTIONS = Object.freeze(ICE_CASTLE_TIERS.map((map) => {
  const monster = 6536 + 100 * (map - 167);
  return Object.freeze({
    id: `${map}#53:${monster}@166,3752`, map, mode: 'iceCastle', call: 53, kind: 'coordinate',
    native: Object.freeze([monster, 166, 3752, 0, 1]), corrected: Object.freeze([monster, 166, 375, 0, 1]),
    rule: RELOCATION_RULE, label: ENGINE_CHOICE, approval: APPROVAL, evidence: EVIDENCE,
  });
}));

const sameRow = (a, b) => Array.isArray(a) && a.length >= 5 && [0, 1, 2, 3, 4].every((i) => Number(a[i]) === Number(b[i]));

/**
 * The call table an event run plays, with this map's disclosed corrections applied. Each entry acts only when exactly
 * one row of its call matches the native row exactly; otherwise it is skipped. The prepared tables are never mutated:
 * a corrected result is a new object whose untouched calls keep their original arrays; the corrected row keeps its
 * position in the call.
 * @returns {{ calls: object, engineChoices: string[] }}
 */
export function correctedEventCalls(map, calls) {
  const engineChoices = [];
  if (!calls || typeof calls !== 'object') return { calls, engineChoices };
  let out = calls;
  for (const e of NATIVE_EVENT_CALL_CORRECTIONS) {
    if (e.map !== Number(map)) continue;
    const rows = out[e.call] ?? out[String(e.call)];
    if (!Array.isArray(rows)) continue;
    const hits = rows.map((r, i) => (sameRow(r, e.native) ? i : -1)).filter((i) => i >= 0);
    if (hits.length !== 1) continue;
    if (out === calls) out = { ...calls };
    out[e.call] = rows.map((r, i) => (i === hits[0] ? [...e.corrected, ...r.slice(5)] : r));
    engineChoices.push(e.id);
  }
  return { calls: out, engineChoices };
}
