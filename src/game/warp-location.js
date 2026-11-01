// Quest warp targets whose position the client data leaves at (0,0).
// share/arrange/location.csv lists 103 rows with position 0,0 ("unused placeholders" to the parsers); 36 quests still warp to them:
// the Parca Temple chamber gates ("Gate of Challenge / Qualification"), "Move - Terra's Altar", "Move - Favnil's Altar", the Python
// Castle / Aquirai Ruins / Deadlands moves, ... The original server held the real arrival points, the client table does not, so the
// warp used to land on the map's corner (0,0) and the move failed or dropped the player in the wrong place.
// ENGINE-CHOSEN rule (checked against the data: tools/test-warp-location.mjs): a (0,0) row is the first half of a pair, the arrival is the
// NEXT row of the same map that has coordinates (the pair rows face each other: 11005 (69,326) dir 90 / 11007 (87,325) dir 270, and
// "Teleport to South" -> 11042 -> (407,344) = the standard Avalon Island arrival of location 116). A row that has coordinates is used as is.
const num = v => (Number.isFinite(Number(v)) ? Number(v) : 0);
export const hasPos = pos => Array.isArray(pos) && (num(pos[0]) !== 0 || num(pos[1]) !== 0);
// These two source rows have no adjacent same-map arrival. Use existing named
// locations on the same map: the Python entrance beside Carlyle, and the
// Avalon fishing landing. No new coordinates are invented.
const missingArrivals = new Map([[1153, 1136], [11202, 11201]]);

/** {map, pos:[x,y], dir, guessed, via?} for a quest warp {loc, map, pos, dir}. `rowOf(index)` = [map, x, y, dirDeg, name] or null. */
export function resolveQuestWarp(warp, rowOf) {
  if (!warp || warp.map == null) return null;
  const given = { map: Number(warp.map), pos: Array.isArray(warp.pos) ? warp.pos.map(num) : [0, 0], dir: num(warp.dir), guessed: false };
  if (hasPos(given.pos) || typeof rowOf !== 'function' || warp.loc == null) return given;
  const base = rowOf(warp.loc);
  if (base && (num(base[1]) !== 0 || num(base[2]) !== 0)) return { map: Number(base[0]), pos: [num(base[1]), num(base[2])], dir: num(base[3]), guessed: false };
  const map = Number(base ? base[0] : warp.map);
  for (let d = 1; d <= 3; d++) {
    const row = rowOf(Number(warp.loc) + d);
    if (row && Number(row[0]) === map && (num(row[1]) !== 0 || num(row[2]) !== 0)) return { map, pos: [num(row[1]), num(row[2])], dir: num(row[3]), guessed: true, via: Number(warp.loc) + d };
  }
  const alternate = missingArrivals.get(Number(warp.loc));
  if (alternate) {
    const row = rowOf(alternate);
    if (row && Number(row[0]) === map && hasPos([row[1], row[2]])) return { map, pos: [num(row[1]), num(row[2])], dir: num(row[3]), guessed: true, via: alternate };
  }
  return given;   // nothing better in the table: the old behaviour (map.nearest of the corner)
}
