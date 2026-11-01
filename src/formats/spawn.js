// Dekaron world coordinates + map placement tables (spawns, NPCs, bricks, triggers, start/return points).
// The single source of truth for the conventions used here is docs/formats/coords.md.
//
// WORLD / CELL CONVENTIONS (verified, see coords.md):
//   * 1 cell = 1 world unit = ~1 metre. A standard map is 512 x 512 cells; the .map heightmap has 513 x 513 vertices.
//   * FILE frame = Direct3D, left-handed, Y up. Cell (x, y) covers X in [x, x+1), Z in [y, y+1) (y is the ROW of the
//     .mac/.mal grid and of the heightmap). Terrain vertex (i, j) sits at X = i, Z = j. Origin = grid corner (0,0).
//   * Every CSV position (spawn "x,y", NPC Location_X/Y, Brick Location_X/Y, location.csv Pos_X/Pos_Y ...) is (X, Z)
//     in that frame: X = column, Y-in-the-CSV = Z = row. Integer spawn coordinates are cell indices (stand at the
//     cell centre); fractional NPC/brick coordinates are continuous positions.
//   * Ground height = the rendered terrain (two triangles per cell, (i,j)-(i+1,j+1) diagonal) — heightAtTriangulated(),
//     identical to map.js sampleHeight() — or a walkable object surface (mesh "ground" helpers: bridges, decks).
//   * three.js (right-handed): mirror Z, like every other format module: three = (X, Y, -Z).
//   * Direction (NPC/trigger/brick CSVs, degrees): model yaw = D3DXMatrixRotationY(deg) in the file frame; models face
//     local -Z, so the facing vector is (-sin d, 0, -cos d). Under the engine's mirror root (docs/ARCHITECTURE.md:
//     raw FILE-frame models under a Group with scale.z = -1): rotation.y = directionToYaw(d) = +d * PI / 180.
//     With converted (Z-negated) models instead (front = local +Z): rotation.y = directionToThreeYaw(d) = -d * PI / 180.
//   * Minimap textures (imagetable group `minimap`): texel (u, v) normalised = (Z / 512, X / 512), for every map size.
//
// Pure functions, no three.js / Node APIs. CSV inputs may be strings or raw bytes (decoded as EUC-KR).

import { parseCSV, decodeText } from './binreader.js';

export const CELL_SIZE = 1;
export const DEFAULT_MAP_INFO = Object.freeze({ width: 512, height: 512, cellSize: 1, originX: 0, originZ: 0 });

const toText = (src) => (typeof src === 'string' ? src : decodeText(src instanceof ArrayBuffer ? new Uint8Array(src) : src, true));
const numOrNull = (v) => {
  if (v === undefined || v === null) return null;
  const s = String(v).trim();
  if (s === '') return null;
  const x = Number(s);
  return Number.isFinite(x) ? x : null;
};
const info = (m) => ({ ...DEFAULT_MAP_INFO, ...(m || {}) });

// ------------------------------------------------------------------------------------------------ coordinates

/**
 * EXACT terrain height of a (w+1) x (h+1) vertex heightmap (vertex (i,j) at X=i, Z=j) on the rendered surface:
 * every cell is split along its (i,j)-(i+1,j+1) diagonal, exactly like map.js buildTerrainArrays/sampleHeight
 * (verified identical to map.js sampleHeight by tools/verify-coords-collision.mjs). Use this for placing things
 * on the ground. Coordinates outside the grid are clamped to the border.
 */
export function heightAtTriangulated(heights, vertsPerRow, x, z, cellSize = 1) {
  const W = vertsPerRow - 1, H = Math.floor(heights.length / vertsPerRow) - 1;
  let col = x / cellSize, row = z / cellSize;
  if (!(col >= 0)) col = 0; if (!(row >= 0)) row = 0;
  if (col > W) col = W; if (row > H) row = H;
  let i = Math.floor(col), j = Math.floor(row);
  if (i >= W) i = W - 1; if (j >= H) j = H - 1;
  const fx = col - i, fz = row - j, a = j * vertsPerRow + i;
  const ha = heights[a], hb = heights[a + 1], hc = heights[a + vertsPerRow], hd = heights[a + vertsPerRow + 1];
  return fx >= fz ? ha + (hb - ha) * fx + (hd - hb) * fz : ha + (hc - ha) * fz + (hd - hc) * fx;
}

/**
 * Terrain height by BILINEAR interpolation of the vertex heightmap. This is NOT the rendered surface (the terrain
 * is two triangles per cell): on steep cells it is up to ~2 units off (Braiken). Kept for smooth-camera style
 * uses only; place characters/objects with heightAtTriangulated() (or map.js sampleHeight()).
 */
export function heightAtBilinear(heights, vertsPerRow, x, z, cellSize = 1) {
  const rows = Math.floor(heights.length / vertsPerRow);
  let fx = x / cellSize, fz = z / cellSize;
  fx = Math.min(Math.max(fx, 0), vertsPerRow - 1);
  fz = Math.min(Math.max(fz, 0), rows - 1);
  const i = Math.min(Math.floor(fx), vertsPerRow - 2), j = Math.min(Math.floor(fz), rows - 2);
  const u = fx - i, v = fz - j;
  const h00 = heights[j * vertsPerRow + i], h10 = heights[j * vertsPerRow + i + 1];
  const h01 = heights[(j + 1) * vertsPerRow + i], h11 = heights[(j + 1) * vertsPerRow + i + 1];
  return (h00 * (1 - u) + h10 * u) * (1 - v) + (h01 * (1 - u) + h11 * u) * v;
}

/** Vertices per heightmap row: width+1 when consistent with heights.length, else derived from a square grid. */
function vertsPerRowOf(mi) {
  const n = mi.heights.length, w = mi.width || 512, h = mi.height || w;
  if ((w + 1) * (h + 1) === n) return w + 1;
  const s = Math.round(Math.sqrt(n));
  return s * s === n ? s : w + 1;   // e.g. { heights } of a 256-cell map passed without width -> 257
}

function groundY(mi, x, z) {
  if (typeof mi.heightAt === 'function') return mi.heightAt(x, z);
  if (mi.heights) return heightAtTriangulated(mi.heights, vertsPerRowOf(mi), x - (mi.originX || 0), z - (mi.originZ || 0), mi.cellSize || 1);
  return 0;
}

/**
 * mapInfo for the helpers below from a map.js parseMap() result (or anything with width/height/heights):
 *   { width, height, cellSize, originX: 0, originZ: 0, heights }  -> cellToWorld()/positionToWorld() then return the
 * exact rendered terrain height. (Walkable object surfaces such as bridges are NOT included: see coords.md.)
 */
export function mapInfoFromMap(map, originX = 0, originZ = 0) {
  return { width: map.width, height: map.height, cellSize: map.cellSize || 1, originX, originZ, heights: map.heights };
}

/**
 * Cell index -> FILE-frame world position (centre of the cell by default).
 * @param {number} cellX column (spawn CSV x)   @param {number} cellY row (spawn CSV y)
 * @param {{width?:number,height?:number,cellSize?:number,originX?:number,originZ?:number,
 *          heightAt?:(x:number,z:number)=>number, heights?:Float32Array}} [mapInfo]
 * @returns {{x:number, y:number, z:number}}  y = terrain height when mapInfo.heightAt/heights is given, else 0
 */
export function cellToWorld(cellX, cellY, mapInfo, { center = true } = {}) {
  const mi = info(mapInfo);
  const c = center ? 0.5 : 0;
  const x = mi.originX + (cellX + c) * mi.cellSize;
  const z = mi.originZ + (cellY + c) * mi.cellSize;
  return { x, y: groundY(mi, x, z), z };
}

/** Continuous CSV position (NPC Location_X/Location_Y, brick, location.csv) -> FILE-frame world position. */
export function positionToWorld(px, py, mapInfo) {
  const mi = info(mapInfo);
  const x = mi.originX + px * mi.cellSize, z = mi.originZ + py * mi.cellSize;
  return { x, y: groundY(mi, x, z), z };
}

/** FILE-frame world (x, z) -> cell indices. inside=false when outside the grid. */
export function worldToCell(x, z, mapInfo) {
  const mi = info(mapInfo);
  const cellX = Math.floor((x - mi.originX) / mi.cellSize), cellY = Math.floor((z - mi.originZ) / mi.cellSize);
  return { cellX, cellY, inside: cellX >= 0 && cellY >= 0 && cellX < mi.width && cellY < mi.height };
}

/** FILE frame <-> three.js (mirror Z). Works on [x,y,z] arrays or {x,y,z} objects; returns the same shape. */
export function fileToThree(p) {
  return Array.isArray(p) || ArrayBuffer.isView(p) ? [p[0], p[1], -p[2]] : { x: p.x, y: p.y, z: -p.z };
}
export const threeToFile = fileToThree;

/** Cell -> three.js world position [x, y, z]. */
export function cellToThree(cellX, cellY, mapInfo, opts) {
  const w = cellToWorld(cellX, cellY, mapInfo, opts);
  return [w.x, w.y, -w.z];
}

/** three.js world (x, z) -> cell indices. */
export function threeToCell(x, z, mapInfo) { return worldToCell(x, -z, mapInfo); }

/** CSV Direction (degrees) -> yaw in the FILE frame (radians, D3DXMatrixRotationY). */
export function directionToYaw(deg) { return (Number(deg) || 0) * Math.PI / 180; }
/** CSV Direction (degrees) -> three.js Object3D.rotation.y for a Z-mirrored model (front = local +Z). */
export function directionToThreeYaw(deg) { return -(Number(deg) || 0) * Math.PI / 180; }
/** Facing unit vector of a CSV Direction in the FILE frame: (-sin d, 0, -cos d). */
export function facingVector(deg) { const a = directionToYaw(deg); return [-Math.sin(a), 0, -Math.cos(a)]; }
/** CSV Direction for a FILE-frame facing vector (inverse of facingVector), degrees in [0, 360). */
export function vectorToDirection(fx, fz) { let d = Math.atan2(-fx, -fz) * 180 / Math.PI; if (d < 0) d += 360; return d; }
/**
 * location.csv byte angles (0..255 = full turn) -> degrees (same zero/sense as the CSV degrees above).
 * NOT for smartwarp.csv: its Direction is (most likely) plain degrees — see parseMapPointCSV.
 */
export function byteAngleToDegrees(b) { return (Number(b) || 0) * 360 / 256; }

// ------------------------------------------------------------------------------------------------ CSV tables

/**
 * Header-keyed rows for simple tables. Duplicate header names get a numeric suffix (Pos_X, Pos_X_2 ...).
 * The first header cell is often an edit date instead of "Index": it is exposed as `Index` too.
 * @returns {{headers:string[], rows:Array<Record<string,string>>}}
 */
export function parseTableCSV(src) {
  const rows = parseCSV(toText(src));
  const raw = (rows.shift() || []).map(h => String(h).trim());
  const seen = new Map();
  const headers = raw.map((h, i) => {
    const k = h || `col${i}`;
    const n = (seen.get(k) || 0) + 1; seen.set(k, n);
    return n === 1 ? k : `${k}_${n}`;
  });
  const out = [];
  for (const r of rows) {
    if (!r || !r.some(c => String(c).trim() !== '')) continue;
    const o = {};
    headers.forEach((h, i) => { o[h] = r[i] === undefined ? '' : String(r[i]).trim(); });
    if (!('Index' in o)) o.Index = o[headers[0]];
    out.push(o);
  }
  return { headers, rows: out };
}

/**
 * Monster spawn table: share/map/<map>/MON_*.csv (maplist MonsterLocatePath). One spawn point per line:
 *   monsterIndex, respawnSec, x, y
 *   monsterIndex -> share/creature/monster.csv Index
 *   respawnSec   -> respawn delay in seconds (20..60 normal mobs, 3600 bosses, 36000/60000 Rank-5 world bosses,
 *                   65534 = special / scripted, 0 = no timer) — inferred from the Rank correlation
 *   x, y         -> cell column / row (FILE X / Z). Use cellToWorld(x, y) (cell centre).
 * Lines that are not 4+ numeric fields (the *_monster.csv helper lists) go to `skipped`.
 * @returns {{spawns:Array<{monsterIndex:number, respawnSec:number, x:number, y:number, line:number, extra?:number[]}>,
 *            skipped:Array<{line:number, text:string}>, count:number}}
 */
export function parseSpawnCSV(src) {
  const text = toText(src);
  const spawns = [], skipped = [];
  const lines = text.split(/\r?\n/);
  for (let i = 0; i < lines.length; i++) {
    const l = lines[i].trim();
    if (!l) continue;
    const parts = l.split(',').map(s => s.trim());
    const nums = parts.map(numOrNull);
    if (parts.length >= 4 && nums.slice(0, 4).every(v => v !== null)) {
      const s = { monsterIndex: nums[0], respawnSec: nums[1], x: nums[2], y: nums[3], line: i + 1 };
      if (parts.length > 4) s.extra = parts.slice(4);
      spawns.push(s);
    } else {
      skipped.push({ line: i + 1, text: l.length > 120 ? l.slice(0, 120) + '...' : l });
    }
  }
  return { spawns, skipped, count: spawns.length };
}

/**
 * Transposed "column per entity" tables: NPC_*.csv (maplist NPCLocatePath / PosFile), MINIMAP_NPC_*.csv, TRIGGER_*.csv.
 *   row 0: <label: NpcIndex | NPCIndex | TriggerIndex | edit date>, id1, id2, ...
 *   Direction    degrees (see directionToYaw)
 *   Location_X   FILE X (continuous)      Location_Y   FILE Z (continuous)
 *   Description  string/quest id (numeric) or text (triggers)
 *   Warp_X/Warp_Y  where a player is put when warped to this NPC (usually 1-2 cells in front of it)   [NPC files]
 *   IsEvent      0/1                                                                                  [NPC files]
 * NPCs stand on their own blocked footprint in the .mac: 98.5% are within 3 cells of a walkable cell.
 * @returns {{idLabel:string, labels:string[], npcs:Array<{id:number, npcIndex:number, direction:number|null, x:number|null,
 *   y:number|null, description:string, warpX:number|null, warpY:number|null, isEvent:number|null, column:number,
 *   extra:Record<string,string>}>}}
 */
export function parseNpcCSV(src) {
  const rows = parseCSV(toText(src)).filter(r => r && r.some(c => String(c).trim() !== ''));
  if (!rows.length) return { idLabel: '', labels: [], npcs: [] };
  const idRow = rows[0];
  const byLabel = new Map();
  for (const r of rows.slice(1)) byLabel.set(String(r[0]).trim(), r);
  const known = new Set(['Direction', 'Location_X', 'Location_Y', 'Description', 'Warp_X', 'Warp_Y', 'IsEvent']);
  const get = (label, c) => { const r = byLabel.get(label); return r ? (r[c] === undefined ? '' : String(r[c]).trim()) : ''; };
  const npcs = [];
  for (let c = 1; c < idRow.length; c++) {
    const idStr = String(idRow[c]).trim();
    if (idStr === '') continue;
    const id = numOrNull(idStr);
    const extra = {};
    for (const [label] of byLabel) if (!known.has(label)) extra[label] = get(label, c);
    npcs.push({
      id, npcIndex: id, column: c,
      direction: numOrNull(get('Direction', c)),
      x: numOrNull(get('Location_X', c)), y: numOrNull(get('Location_Y', c)),
      description: get('Description', c),
      warpX: numOrNull(get('Warp_X', c)), warpY: numOrNull(get('Warp_Y', c)),
      isEvent: numOrNull(get('IsEvent', c)),
      extra,
    });
  }
  return { idLabel: String(idRow[0]).trim(), labels: [...byLabel.keys()], npcs };
}

/** TRIGGER_*.csv uses the same transposed layout (TriggerIndex, Direction, Location_X, Location_Y, Description). */
export const parseTriggerCSV = parseNpcCSV;

/**
 * Brick table: BRICK_*.csv / BRI_*.csv (maplist BrickLocatePath). Bricks are dynamic map objects (gates, barriers,
 * destructible props) -> share/creature/brick.csv by BrickIndex. NOTE brick.csv itself is TRANSPOSED: row 0 =
 * <edit date>, brick indices...; then one row per field (Name, Property, ...); column k describes brick index k.
 *   BrickUID|BrickID, BrickIndex, Revival, RegenCycle, Direction (degrees), Location_X, Location_Y, [IsCreate]
 * @returns {Array<{uid:number, brickIndex:number, revival:number|null, regenCycle:number|null, direction:number|null,
 *   x:number, y:number, isCreate:number|null, raw:Record<string,string>}>}
 */
export function parseBrickCSV(src) {
  const { rows } = parseTableCSV(src);
  const out = [];
  for (const r of rows) {
    const x = numOrNull(r.Location_X), y = numOrNull(r.Location_Y);
    if (x === null || y === null) continue;
    out.push({
      uid: numOrNull(r.BrickUID ?? r.BrickID), brickIndex: numOrNull(r.BrickIndex),
      revival: numOrNull(r.Revival), regenCycle: numOrNull(r.RegenCycle), direction: numOrNull(r.Direction),
      x, y, isCreate: numOrNull(r.IsCreate), raw: r,
    });
  }
  return out;
}

/**
 * CallMonster_*.csv / GroupCallMonster_*.csv / CallMon_*.csv (maplist CallMonsterPath): scripted/event spawns.
 *   "MapIndex,<n>" / blank / "CallIndex,MonsterIndex,X,Y,Cell,Count" / rows
 *   X, Y = cell column/row, Cell = scatter radius in cells (0 = exact), Count = monsters at this point.
 * One file (callmonster_707_braiken_broken.csv, the "Defense Battle" map) puts two more tables side by side on the
 * same rows, each introduced by its own header cell and separated by empty columns (the fixed block is empty there,
 * and its first row is ",707" without the "MapIndex" label):
 *   RandCallIndex, MonsterIndex, Count, PosIndex   -> randomCalls   (call group -> monsters of the wave)
 *   RandPosIndex, X, Y, Cell                       -> randomPositions (position list; PosIndex refers to RandPosIndex)
 *   Inferred meaning: call group k spawns Count x MonsterIndex at a random point of position list PosIndex,
 *   scattered by Cell. All 10 points of list 1 are walkable in braiken_broken.mac (tools/verify-coords-collision.mjs).
 * Columns are located by header name, so the block layout does not have to start at column 0.
 * @returns {{mapIndex:number|null, calls:Array<{callIndex:number, monsterIndex:number, x:number, y:number,
 *   radius:number|null, count:number|null, extra?:string[]}>,
 *   randomCalls:Array<{randCallIndex:number, monsterIndex:number, count:number|null, posIndex:number|null}>,
 *   randomPositions:Array<{randPosIndex:number, x:number, y:number, radius:number|null}>}}
 */
export function parseCallMonsterCSV(src) {
  const rows = parseCSV(toText(src));
  const cell = (r, i) => (i >= 0 && i < r.length ? String(r[i] ?? '').trim() : '');
  let mapIndex = null, hi = -1;
  for (let i = 0; i < rows.length; i++) {
    const lc = rows[i].map(v => String(v ?? '').trim().toLowerCase());
    if (lc[0] === 'mapindex') mapIndex = numOrNull(rows[i][1]);
    if (lc.includes('callindex') || lc.includes('randcallindex')) { hi = i; break; }
  }
  const calls = [], randomCalls = [], randomPositions = [];
  if (hi < 0) return { mapIndex, calls, randomCalls, randomPositions };
  // header-less map index row (",707,,,"): first numeric cell of the first row above the header
  if (mapIndex === null) {
    for (let i = 0; i < hi && mapIndex === null; i++) {
      const v = rows[i].map(numOrNull).find(x => x !== null);
      if (v !== undefined) mapIndex = v;
    }
  }
  const head = rows[hi].map(v => String(v ?? '').trim().toLowerCase());
  // each block starts at its first header cell; the next columns are positional within the block
  const cCall = head.indexOf('callindex'), cRand = head.indexOf('randcallindex'), cPos = head.indexOf('randposindex');
  for (let i = hi + 1; i < rows.length; i++) {
    const r = rows[i];
    if (cCall >= 0) {
      const n = [0, 1, 2, 3, 4, 5].map(k => numOrNull(cell(r, cCall + k)));
      if (n[0] !== null && n[1] !== null && n[2] !== null && n[3] !== null) {
        const c = { callIndex: n[0], monsterIndex: n[1], x: n[2], y: n[3], radius: n[4], count: n[5] };
        const rest = r.slice(cCall + 6);
        if (cRand < 0 && cPos < 0 && rest.some(v => String(v).trim() !== '')) c.extra = rest;
        calls.push(c);
      }
    }
    if (cRand >= 0) {
      const n = [0, 1, 2, 3].map(k => numOrNull(cell(r, cRand + k)));
      if (n[0] !== null && n[1] !== null) randomCalls.push({ randCallIndex: n[0], monsterIndex: n[1], count: n[2], posIndex: n[3] });
    }
    if (cPos >= 0) {
      const n = [0, 1, 2, 3].map(k => numOrNull(cell(r, cPos + k)));
      if (n[0] !== null && n[1] !== null && n[2] !== null) randomPositions.push({ randPosIndex: n[0], x: n[1], y: n[2], radius: n[3] });
    }
  }
  return { mapIndex, calls, randomCalls, randomPositions };
}

/**
 * share/arrange/location.csv — the teleport/start/return point table (Location_Index everywhere refers here).
 *   <date as Index>, Location_Name, MapIndex, Pos_X, Pos_Y, Direction, Pos_X, Pos_Y, Direction
 *   Direction is a byte angle (0..255; 97.8% are multiples of 32, 23 rows use other values such as 36, 78, 250)
 *   — directionDeg = byteAngleToDegrees(direction). The 2nd triple is identical in 1053/1055 rows (Crespo
 *   treasure rows differ by 5 cells). (0,0) rows are unused placeholders.
 * @returns {Map<number, {index:number, name:string, mapIndex:number, x:number, y:number, direction:number,
 *   directionDeg:number, x2:number, y2:number, direction2:number, direction2Deg:number, placeholder:boolean}>}
 */
export function parseLocationCSV(src) {
  const rows = parseCSV(toText(src));
  rows.shift();
  const out = new Map();
  for (const r of rows) {
    const n = r.map(numOrNull);
    if (n[0] === null || n[2] === null) continue;
    out.set(n[0], {
      index: n[0], name: String(r[1] ?? '').trim(), mapIndex: n[2],
      x: n[3], y: n[4], direction: n[5], directionDeg: byteAngleToDegrees(n[5]),
      x2: n[6], y2: n[7], direction2: n[8], direction2Deg: byteAngleToDegrees(n[8]),
      placeholder: !n[3] && !n[4],
    });
  }
  return out;
}

/**
 * share/pc/startpoint.csv (also share/server/startpoint.csv): Index, Location_Index, Retun_Index -> location.csv.
 * Index 0..2 start in Braiken Castle (locations 1..3), 3..5 in Loa Castle (7..9); Retun_Index = respawn/return point.
 */
export function parseStartPointCSV(src) {
  const { rows } = parseTableCSV(src);
  return rows.map(r => ({
    index: numOrNull(r.Index), locationIndex: numOrNull(r.Location_Index), returnIndex: numOrNull(r.Retun_Index ?? r.Return_Index),
  })).filter(r => r.index !== null && r.locationIndex !== null);
}

/**
 * Point lists keyed by map: share/arrange/portallocation.csv, chaoticlocation.csv (MapIndex, Pos_X, Pos_Y, Direction, Location_Name)
 * and share/support/smartwarp/smartwarp.csv (… Map Index, Position_X, Position_Y, Direction …).
 * Direction units: portal/chaotic tables only contain 0. smartwarp.csv is (inferred) DEGREES like the NPC CSVs, not
 * a location.csv byte angle: its values are 0/5/40/45/70/90/95/128/135/180/192/220/224/225, and against location.csv
 * rows at the same map position, deg*256/360 reproduces the byte angle (180->128, 90->64, 45->32, 224->160 ...) far
 * more often than equality does. `directionDeg` = the value as degrees (null when absent).
 */
export function parseMapPointCSV(src) {
  const { rows } = parseTableCSV(src);
  const out = [];
  for (const r of rows) {
    const mapIndex = numOrNull(r.MapIndex ?? r['Map Index']);
    const x = numOrNull(r.Pos_X ?? r.Position_X), y = numOrNull(r.Pos_Y ?? r.Position_Y);
    if (mapIndex === null || x === null || y === null) continue;
    const direction = numOrNull(r.Direction);
    out.push({ mapIndex, x, y, direction, directionDeg: direction, name: r.Location_Name ?? r.Name ?? '', raw: r });
  }
  return out;
}

// ------------------------------------------------------------------------------------------------ maplist paths

/** maplist placeholder cells such as "<< Emtpy >>" (sic) mean "no file". */
const isPlaceholder = (p) => /^<<.*>>$/.test(String(p ?? '').trim());

/** Normalise a game path to a data key: backslashes -> '/', lower case, no leading '../', './' or '/'. '' for placeholders. */
export function dataKey(p) {
  if (isPlaceholder(p)) return '';
  return String(p ?? '').trim().replace(/\\/g, '/').replace(/^(\.\.?\/)+/, '').replace(/^\/+/, '').replace(/\/{2,}/g, '/').toLowerCase();
}

/** maplist path columns are relative to the share/ folder ("..\Share\Map\X" or "Map\X") — make them data keys. */
export function shareKey(p) {
  const k = dataKey(p);
  if (!k) return '';
  return k.startsWith('share/') ? k : `share/${k}`;
}

/** Table columns name CSV files; one maplist row (707, NPCLocatePath) omits the extension. */
const csvKey = (k) => (k && !/\.[a-z0-9]{1,4}$/.test(k.slice(k.lastIndexOf('/') + 1)) ? `${k}.csv` : k);

/**
 * Data keys (fetch as /data/<key>) of every per-map file named by one share/maplist.csv row
 * (row = object keyed by header, e.g. from environment.js parseMapList or parseTableCSV).
 * '' = no file ("<< Emtpy >>" placeholders and empty cells). CSV columns get ".csv" appended when the maplist omits
 * the extension. Keys that still do not exist on disk are genuine client holes (tools/verify-coords-collision.mjs [G]:
 * 29 MON_ files, m126.mal, 2 CallMonster files whose real name differs, e.g. callmon_550_guild_port.csv).
 */
export function mapDataPaths(row) {
  const s = (k) => String(row[k] ?? '').trim();
  const inDir = (dir, f) => { const k = dataKey(f); return k ? `${dir}/${k}` : ''; };
  return {
    index: numOrNull(row.Index), name: s('Name'),
    map: inDir('map', s('MapFile')),
    mol: inDir('map', s('MapObject')),
    mel: inDir('map', s('MapEffect')),
    mac: inDir('share/mapredcell', s('MapAttribute')),     // NOT map/: only two all-zero stubs live there
    zoneGraph: shareKey(s('MapPath')),                      // graph .mal (see mal.js)
    monsters: csvKey(shareKey(s('MonsterLocatePath'))),
    npcs: csvKey(shareKey(s('NPCLocatePath'))),
    npcsClient: csvKey(shareKey(s('PosFile'))),             // same file as NPCLocatePath in practice
    bricks: csvKey(shareKey(s('BrickLocatePath'))),
    triggers: csvKey(shareKey(s('TriggerLocatePath'))),
    callMonsters: csvKey(shareKey(s('CallMonsterPath'))),
    levelCap: csvKey(shareKey(s('StrLevelCapPath'))),
  };
}
