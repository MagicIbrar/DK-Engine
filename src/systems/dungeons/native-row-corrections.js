// ENGINE CHOICES for three floors whose original call-monster rows cannot be placed. These are NOT native Global
// rules: no original server controller or authored correction exists. Each entry matches one exact original row
// or group and only moves it; anything else is left untouched, so the Director's unresolved-spawn fail-safe still
// faults it. Monster IDs, Cell and Count are never changed, so every monster keeps its own native catalog stats
// (HP, damage, attack/move speed, level, EXP, drops, AI). Nothing is removed and no stat row is created or edited.
//
// Prepared wave rows are [monsterIndex, x, y, cell, count] (tools/build-dungeons.mjs).

export const ENGINE_CHOICE = 'ENGINE CHOICE';
export const OWNER_APPROVAL = 'owner approval 2026-10-12';

const freezeRows = (rows) => Object.freeze(rows.map((r) => Object.freeze(r)));

/** Temple 1F offering-room block, shipped verbatim as call 1 of 235/264 (and native call 1 of 562). */
const TEMPLE_GOLEM_BLOCK = freezeRows([
  [8045, 215, 171, 1, 1], [8046, 214, 164, 1, 1], [8045, 207, 164, 1, 1], [8046, 204, 169, 1, 1], [8045, 199, 164, 1, 1],
  [8046, 194, 170, 1, 1], [8045, 191, 162, 1, 1], [8046, 106, 169, 1, 1], [8045, 187, 160, 1, 1], [8046, 195, 155, 1, 1],
  [8045, 194, 150, 1, 1], [8046, 188, 149, 1, 1], [8045, 186, 144, 1, 1], [8046, 187, 148, 1, 1], [8045, 194, 140, 1, 1],
  [8046, 190, 143, 1, 1], [8045, 197, 138, 1, 1], [8046, 201, 135, 1, 1], [8045, 203, 142, 1, 1], [8046, 206, 147, 1, 1],
]);

/**
 * The same 20 rows, row for row (same order, monster, Cell and Count), moved into the Nepturos boss-room arena.
 * Derived once by RELOCATION_RULE on wrecked_boat_undersea.mac (shared by 235 and 264); the explicit cells below are
 * the runtime authority and tools/test-dungeon-native-row-corrections.mjs re-derives them from the rule.
 */
const ARENA_GOLEM_FILL = freezeRows([
  [8045, 279, 243, 1, 1], [8046, 282, 236, 1, 1], [8045, 278, 239, 1, 1], [8046, 275, 244, 1, 1], [8045, 270, 244, 1, 1],
  [8046, 265, 246, 1, 1], [8045, 259, 242, 1, 1], [8046, 242, 242, 1, 1], [8045, 252, 235, 1, 1], [8046, 275, 228, 1, 1],
  [8045, 258, 219, 1, 1], [8046, 254, 220, 1, 1], [8045, 255, 216, 1, 1], [8046, 252, 224, 1, 1], [8045, 278, 225, 1, 1],
  [8046, 249, 221, 1, 1], [8045, 282, 223, 1, 1], [8046, 282, 227, 1, 1], [8045, 279, 230, 1, 1], [8046, 283, 231, 1, 1],
]);

export const RELOCATION_RULE = Object.freeze({
  reachable: '4-neighbour path from the floor arrival point over walkable undersea MAC cells (both floors: same component)',
  eligible: 'the cell and its 8 neighbours are reachable (Cell 1 scatter stays on the floor); at least 18 cells from the exit NPC '
    + '6047 (272.456,207.522) and from both floor arrivals (235: 272.5,207.5; 264: 272.956,208.022), i.e. no closer than the '
    + 'nearest native call 11-15 monster (17.65-17.99); outside the call 11-15 bounding box widened by 2 (x 254-274, z 222-241); '
    + 'at least 5 cells from every call 11-15 row and at least 4 cells from every fill already placed (native call 11-15 '
    + 'spacing is 2), so no 3-10 cell neighbourhood is denser than the native call 11-15 cluster',
  target: 'native row + (centroid of reachable cells - centroid of the 20 native rows), i.e. the block keeps its layout '
    + 'translated onto the arena centre',
  choice: 'rows in native order; nearest eligible cell to the target; ties by smaller z, then smaller x',
  keep: 18, spacing: 4, addsDistance: 5, boxMargin: 2,
});

const GOLEM_EVIDENCE = 'Row-for-row copy of 562 call 1 (Temple 1F offering room): fits 20/20 there, 0/20 rows placeable within 32 '
  + 'cells on wrecked_boat_undersea.mac. Owner chose a relocated fill: the same native IDs 8045/8046 (normal level-190 Temple '
  + 'golems as listed by the native 235/264 files; they are not solo variants on 264), required for the clear.';
const GUARD_EVIDENCE = 'Native X equals the monster index 7409, outside the 512-cell map. Calls 1-4 are four symmetric six-guard '
  + 'squads; call 2 places the same squad positions at X=209. 209,258 and 209,268 are walkable on dravis_under.mac in the guard room.';
const BRICK_NOTE = 'Brick 101 (36859 Magic Barrier at 232,112), the companion Temple residue, stays as native: not added or moved.';

export const NATIVE_ROW_CORRECTIONS = Object.freeze([
  Object.freeze({ id: '181#1:7411@7409,258', map: 181, call: 1, kind: 'coordinate', native: Object.freeze([7411, 7409, 258, 0, 1]),
    corrected: Object.freeze([7411, 209, 258, 0, 1]), label: ENGINE_CHOICE, approval: OWNER_APPROVAL, evidence: GUARD_EVIDENCE }),
  Object.freeze({ id: '181#1:7410@7409,268', map: 181, call: 1, kind: 'coordinate', native: Object.freeze([7410, 7409, 268, 0, 1]),
    corrected: Object.freeze([7410, 209, 268, 0, 1]), label: ENGINE_CHOICE, approval: OWNER_APPROVAL, evidence: GUARD_EVIDENCE }),
  Object.freeze({ id: '235#1:temple-golem-fill', map: 235, call: 1, kind: 'relocate-group', native: TEMPLE_GOLEM_BLOCK, relocated: ARENA_GOLEM_FILL,
    copyOf: '562#1', rule: RELOCATION_RULE, label: ENGINE_CHOICE, approval: OWNER_APPROVAL, evidence: GOLEM_EVIDENCE, note: BRICK_NOTE }),
  Object.freeze({ id: '264#1:temple-golem-fill', map: 264, call: 1, kind: 'relocate-group', native: TEMPLE_GOLEM_BLOCK, relocated: ARENA_GOLEM_FILL,
    copyOf: '562#1', rule: RELOCATION_RULE, label: ENGINE_CHOICE, approval: OWNER_APPROVAL, evidence: GOLEM_EVIDENCE, note: BRICK_NOTE }),
]);

const sameRow = (a, b) => a.length >= 5 && b.length >= 5 && [0, 1, 2, 3, 4].every((i) => Number(a[i]) === Number(b[i]));
const sameRows = (a, b) => a.length === b.length && a.every((r, i) => sameRow(r, b[i]));

/** Wave summary fields recomputed the way tools/build-dungeons.mjs computes them. */
function summarize(wave, rows) {
  let n = 0, sx = 0, sy = 0;
  for (const [, x, y, , cnt] of rows) { const c = Number(cnt) || 1; n += c; sx += x * c; sy += y * c; }
  const cx = sx / n, cy = sy / n;
  let radius = 0;
  for (const [, x, y] of rows) radius = Math.max(radius, Math.hypot(x - cx, y - cy));
  const r1 = (v) => Math.round(v * 10) / 10;
  return { ...wave, rows, center: [r1(cx), r1(cy)], radius: r1(radius) };
}

const cache = new WeakMap();

/**
 * The map info the Director plays, with this map's approved corrections applied. Returns `info` itself when no entry
 * matches exactly; otherwise a new object (the shared prepared data is never mutated) carrying `engineChoices`.
 * Stages are unchanged: a corrected call keeps its stage, objective and gates, so it stays required.
 */
export function correctedMapInfo(map, info) {
  if (!info || typeof info !== 'object') return info;
  const entries = NATIVE_ROW_CORRECTIONS.filter((e) => e.map === Number(map));
  if (!entries.length || !Array.isArray(info.waves)) return info;
  const memo = cache.get(info);
  if (memo && memo.map === Number(map)) return memo.out;
  let waves = info.waves;
  const applied = [];
  for (const e of entries) {
    const at = waves.findIndex((w) => Number(w.call) === e.call);
    if (at < 0) continue;
    const wave = waves[at];
    let rows = null;
    if (e.kind === 'relocate-group') {
      if (sameRows(wave.rows || [], e.native)) rows = e.relocated.map((r, i) => [...r, ...wave.rows[i].slice(5)]);
    } else if (e.kind === 'coordinate') {
      const hits = (wave.rows || []).map((r, i) => (sameRow(r, e.native) ? i : -1)).filter((i) => i >= 0);
      if (hits.length === 1) rows = wave.rows.map((r, i) => (i === hits[0] ? [...e.corrected, ...r.slice(5)] : r));
    }
    if (!rows) continue;
    waves = waves.map((w, i) => (i === at ? summarize(w, rows) : w));
    applied.push(e.id);
  }
  const out = applied.length ? { ...info, waves, engineChoices: Object.freeze(applied.slice()) } : info;
  cache.set(info, { map: Number(map), out });
  return out;
}
