// Dekaron .mac — per-cell map attribute grid ("MapRedCell"), the collision / zone map used by client and server.
//
// Files: share/mapredcell/<name>.mac (258 files, 173 of them referenced by share/maplist.csv column MapAttribute,
// e.g. "braiken.mac" -> /data/share/mapredcell/braiken.mac). Two all-zero stubs also exist in map/.
//
// Layout (little-endian, no magic):
//   u32 width            // cells along world +X (file frame)  — 512 for every field map, 256/128 for small instances
//   u32 height           // cells along world +Z (file frame)
//   width*height cells, row-major, row = Z index:  cell(x, y) at index y*width + x
//     u16 attribute      // normal case (2 bytes / cell)
//     u8  attribute      // 1 file (darkhole_1.mac) stores 1 byte / cell — detected from the file size
//   (5 files are 8-byte stubs with width = height = 0: "cs_*02.mac")
// Every file is consumed exactly (tools/test-coords.mjs).
//
// One cell = 1 x 1 world units (metres). Cell (x, y) covers file-frame X in [x, x+1), Z in [y, y+1);
// it is the quad between terrain vertices (x..x+1, y..y+1) of the .map heightmap. See docs/formats/coords.md.
//
// The attribute value is an index into share/arrange/cell.csv (Cell_Index, Cell_Color, Blocked, Fishing,
// RemoteBlocked, Attribute, Desc, fishing columns...). DEFAULT_CELL_TABLE below is a verified copy of it
// (tools/test-coords.mjs compares them); pass { cellTable: parseCellTable(csvText) } to use the live file.
// Values not in the table (a handful of garbage cells in indun_01_s.mac) are treated as walkable and listed
// in result.unknownValues.
//
// Pure functions, no three.js / Node APIs.

import { BinReader, toArrayBuffer, parseCSV, decodeText } from './binreader.js';

/**
 * share/arrange/cell.csv, verified identical (Blocked/Fishing/RemoteBlocked/Attribute/Color/fishing params).
 * [index, colorARGB, blocked, fishing, remoteBlocked, attribute, fishSkillLevelMin, fishingCasting, fishCount, english description]
 */
const CELL_ROWS = [
  [0, 0xFF000000, 0, 0, 0, '', 0, 0, 0, 'default, walkable'],
  [1, 0xFFFF2020, 1, 0, 1, '', 0, 0, 0, 'not walkable'],
  [2, 0xFFFF6060, 1, 0, 1, '', 0, 0, 0, 'wall'],
  [3, 0xFFFF9090, 1, 0, 1, '', 0, 0, 0, 'no casting (blocked)'],
  [4, 0xFF00FF00, 0, 0, 0, '', 0, 0, 0, 'no PK'],
  [5, 0xFFB5B2FF, 0, 0, 0, 'SAFETY/BLOCK_EAST', 0, 0, 0, 'safety zone'],
  [6, 0xFF665C00, 0, 0, 0, 'NOT_USESKILL', 0, 0, 0, 'skills disabled'],
  [7, 0xFFBCE067, 0, 0, 0, 'TUTORIAL', 0, 0, 0, 'tutorial area'],
  [8, 0xFFFF0000, 0, 0, 0, 'BORDER', 0, 0, 0, 'border marker'],
  [9, 0xFF00FF00, 0, 0, 0, 'SUMMON_ENABLE', 0, 0, 0, 'random monster summoning allowed (field/PvP area)'],
  [100, 0xFF1EFF00, 1, 1, 1, '', 0, 80000, 3, 'fishing water, not walkable (test) - Braiken/Loa'],
  [101, 0xFF1EFF00, 1, 1, 1, '', 1, 0, 3, 'fishing water, not walkable - Braiken/Loa'],
  [102, 0xFF1EFF00, 1, 1, 1, '', 1, 60000, 3, 'fishing water, not walkable - North Ares/West Morte/East Ares'],
  [103, 0xFF1EFF00, 1, 1, 1, '', 2, 5000, 3, 'fishing water, not walkable - Deneb'],
  [104, 0xFF1EFF00, 1, 1, 1, '', 4, 5000, 3, 'fishing water, not walkable - Requies'],
  [105, 0xFF1EFF00, 1, 1, 1, '', 4, 20000, 3, 'fishing water, not walkable - Avalon'],
  [106, 0xFF1EA8FF, 0, 1, 0, '', 1, 55000, 3, 'fishing shallows, walkable - Braiken/Loa'],
  [107, 0xFF1EA8FF, 0, 1, 0, '', 1, 60000, 3, 'fishing shallows, walkable - North Ares/West Morte/East Ares'],
  [108, 0xFF1EA8FF, 0, 1, 0, '', 2, 5000, 3, 'fishing shallows, walkable - Deneb'],
  [109, 0xFF1EA8FF, 0, 1, 0, '', 4, 5000, 3, 'fishing shallows, walkable - Requies'],
  [110, 0xFF1EA8FF, 0, 1, 0, '', 4, 25000, 3, 'fishing shallows, walkable - Avalon'],
  [201, 0xFF1EFF00, 1, 1, 1, '', 2, 60000, 3, 'fishing water, not walkable - Haihaff'],
  [202, 0xFF1EFF00, 1, 1, 1, '', 2, 60000, 3, 'fishing water, not walkable - Haihaff area 2'],
  [203, 0xFF1EFF00, 1, 0, 1, '', 2, 25000, 3, 'water, not walkable - Parca Temple'],
  [204, 0xFF1EFF00, 1, 0, 1, '', 2, 25000, 3, 'water, not walkable - Parca Temple area 2'],
  [205, 0xFF1EFF00, 1, 1, 1, '', 3, 20000, 3, 'fishing water, not walkable - Crespo'],
  [206, 0xFF1EA8FF, 0, 1, 0, '', 2, 60000, 3, 'fishing shallows, walkable - Haihaff'],
  [207, 0xFF1EA8FF, 0, 1, 0, '', 2, 60000, 3, 'fishing shallows, walkable - Haihaff area 2'],
  [208, 0xFF1EA8FF, 0, 0, 0, '', 2, 25000, 3, 'shallows, walkable - Parca Temple'],
  [209, 0xFF1EA8FF, 0, 0, 0, '', 2, 25000, 3, 'shallows, walkable - Parca Temple area 2'],
  [210, 0xFF1EFF00, 0, 1, 0, '', 3, 20000, 3, 'fishing shallows, walkable - Crespo'],
  [301, 0xFF1EFF00, 1, 1, 1, '', 2, 60000, 3, 'fishing water, not walkable - Norak/Castor 1F'],
  [302, 0xFF1EFF00, 1, 1, 1, '', 2, 60000, 3, 'fishing water, not walkable - Norak/Castor 1F area 2'],
  [303, 0xFF1EFF00, 1, 1, 1, '', 3, 35000, 3, 'fishing water, not walkable - Norak/Castor 2F'],
  [304, 0xFF1EFF00, 1, 1, 1, '', 3, 35000, 3, 'fishing water, not walkable - Norak/Castor 2F area 2'],
  [305, 0xFF1EFF00, 1, 1, 1, '', 3, 20000, 3, 'fishing water, not walkable - Draco Desert'],
  [306, 0xFF1EA8FF, 0, 1, 0, '', 2, 60000, 3, 'fishing shallows, walkable - Norak/Castor 1F'],
  [307, 0xFF1EA8FF, 0, 1, 0, '', 2, 60000, 3, 'fishing shallows, walkable - Norak/Castor 1F area 2'],
  [308, 0xFF1EA8FF, 0, 1, 0, '', 3, 35000, 3, 'fishing shallows, walkable - Norak/Castor 2F'],
  [309, 0xFF1EA8FF, 0, 1, 0, '', 3, 35000, 3, 'fishing shallows, walkable - Norak/Castor 2F area 2'],
  [310, 0xFF1EFF00, 0, 1, 0, '', 3, 20000, 3, 'fishing shallows, walkable - Draco Desert'],
  [1000, 0xFF00FF00, 1, 0, 0, '', 0, 0, 0, 'blocked for movement, projectiles/remote attacks pass (siege walls, instance barriers)'],
];

/** @typedef {{index:number, color:number, blocked:boolean, fishing:boolean, remoteBlocked:boolean, attribute:string,
 *   desc:string, fishSkillLevelMin:number, fishingCasting:number, fishCount:number, fish?:Array<{index:number,ratio:number}>,
 *   autoFish?:number[], raw?:string[]}} CellAttr */

/** @type {Map<number, CellAttr>} */
export const DEFAULT_CELL_TABLE = new Map(CELL_ROWS.map(r => [r[0], {
  index: r[0], color: r[1] >>> 0, blocked: !!r[2], fishing: !!r[3], remoteBlocked: !!r[4], attribute: r[5],
  fishSkillLevelMin: r[6], fishingCasting: r[7], fishCount: r[8], desc: r[9],
}]));

/** Named attribute values (share/arrange/cell.csv). */
export const CELL = Object.freeze({
  WALKABLE: 0, BLOCKED: 1, WALL: 2, NO_CAST: 3, NO_PK: 4, SAFETY: 5, NO_SKILL: 6, TUTORIAL: 7, BORDER: 8,
  SUMMON_ENABLE: 9, REMOTE_ONLY: 1000,
});

const toText = (src) => (typeof src === 'string' ? src : decodeText(src instanceof ArrayBuffer ? new Uint8Array(src) : src, true));

/**
 * Parse share/arrange/cell.csv (EUC-KR text or bytes).
 * @returns {Map<number, CellAttr>}
 */
export function parseCellTable(src) {
  const rows = parseCSV(toText(src));
  const head = (rows.shift() || []).map(h => h.trim());
  const col = (name) => head.findIndex(h => h.toLowerCase() === name.toLowerCase());
  const ci = {
    index: col('Cell_Index'), color: col('Cell_Color'), blocked: col('Blocked'), fishing: col('Fishing'),
    remote: col('RemoteBlocked'), attr: col('Attribute'), desc: col('Desc'), lvl: col('FishSkillLevelMin'),
    cast: col('FishingCasting'), count: col('FishCount'),
  };
  const yes = (v) => String(v ?? '').trim().toUpperCase() === 'Y';
  const num = (v) => { const x = Number(String(v ?? '').trim()); return Number.isFinite(x) ? x : 0; };
  const out = new Map();
  for (const r of rows) {
    if (!r || r.length < 3 || String(r[ci.index] ?? '').trim() === '') continue;
    const index = num(r[ci.index]);
    const fish = [];
    for (let k = 1; k <= 10; k++) {
      const i = col(`FishIndex_${k}`), j = col(`FishRatio_${k}`);
      if (i >= 0 && num(r[i])) fish.push({ index: num(r[i]), ratio: j >= 0 ? num(r[j]) : 0 });
    }
    const autoFish = ['AutoFishIndex_1', 'AutoFishIndex_2', 'AutoFishIndex_Unique'].map(n => col(n)).filter(i => i >= 0).map(i => num(r[i]));
    out.set(index, {
      index, color: parseInt(String(r[ci.color] ?? '0').trim(), 16) >>> 0,
      blocked: yes(r[ci.blocked]), fishing: yes(r[ci.fishing]), remoteBlocked: yes(r[ci.remote]),
      attribute: String(r[ci.attr] ?? '').trim(), desc: String(r[ci.desc] ?? '').trim(),
      fishSkillLevelMin: num(r[ci.lvl]), fishingCasting: num(r[ci.cast]), fishCount: num(r[ci.count]),
      fish, autoFish, raw: r,
    });
  }
  return out;
}

/**
 * Low-level: read the (width, height, cells) grid shared by .mac and grid-style .mal files.
 * @returns {{width:number, height:number, bytesPerCell:0|1|2, attrs:Uint16Array, trailingBytes:number}}
 */
export function readCellGrid(buf) {
  const ab = toArrayBuffer(buf);
  const r = new BinReader(ab);
  if (r.length < 8) throw new Error(`cell grid: file too small (${r.length} bytes)`);
  const width = r.u32(), height = r.u32();
  const n = width * height;
  const body = r.length - 8;
  let bytesPerCell = 0;
  if (n === 0) bytesPerCell = 0;
  else if (body === n * 2) bytesPerCell = 2;
  else if (body === n) bytesPerCell = 1;
  else if (body > n * 2) bytesPerCell = 2; // tolerate trailing data (never seen)
  else if (body > n) bytesPerCell = 1;
  else throw new Error(`cell grid: ${width}x${height} needs >= ${n} bytes, file has ${body}`);
  if (width > 8192 || height > 8192) throw new Error(`cell grid: implausible size ${width}x${height}`);
  const attrs = new Uint16Array(n);
  if (bytesPerCell === 2) for (let i = 0; i < n; i++) attrs[i] = r.dv.getUint16(8 + i * 2, true);
  else if (bytesPerCell === 1) attrs.set(r.u8.subarray(8, 8 + n));
  return { width, height, bytesPerCell, attrs, trailingBytes: body - n * bytesPerCell };
}

/**
 * Parse a .mac attribute grid.
 * @param {ArrayBuffer|Uint8Array} buf
 * @param {{cellTable?: Map<number, CellAttr>}} [opts]
 * @returns {{
 *   width:number, height:number, bytesPerCell:0|1|2, trailingBytes:number, empty:boolean,
 *   attrs: Uint16Array,     // raw attribute value per cell (index y*width + x)
 *   cells: Uint8Array,      // movement mask: 1 = blocked (table Blocked=Y), 0 = walkable. Out-of-bounds counts as blocked.
 *   remoteBlocked: Uint8Array, // 1 = blocks projectiles/remote attacks (table RemoteBlocked=Y)
 *   histogram: Record<string, number>, unknownValues: number[], walkableCount:number, blockedCount:number,
 *   isBlocked(x:number, y:number):boolean, isWalkable(x:number,y:number):boolean, attrAt(x:number,y:number):number,
 *   inBounds(x:number,y:number):boolean, info(x:number,y:number):CellAttr|null
 * }}
 *   x, y are cell indices OR continuous world coordinates (file-frame X, Z): they are floored.
 *   The methods are non-enumerable (structuredClone / postMessage drop them; call attachGridMethods() again).
 */
export function parseMac(buf, opts = {}) {
  const table = opts.cellTable || DEFAULT_CELL_TABLE;
  const g = readCellGrid(buf);
  const n = g.width * g.height;
  const cells = new Uint8Array(n);
  const remoteBlocked = new Uint8Array(n);
  const hist = new Map();
  for (let i = 0; i < n; i++) {
    const v = g.attrs[i];
    hist.set(v, (hist.get(v) || 0) + 1);
  }
  const unknownValues = [];
  const blockedOf = new Map(), remoteOf = new Map();
  for (const v of hist.keys()) {
    const t = table.get(v);
    if (!t) unknownValues.push(v);
    blockedOf.set(v, t ? (t.blocked ? 1 : 0) : 0);
    remoteOf.set(v, t ? (t.remoteBlocked ? 1 : 0) : 0);
  }
  let blockedCount = 0;
  for (let i = 0; i < n; i++) {
    const v = g.attrs[i];
    const b = blockedOf.get(v);
    cells[i] = b; blockedCount += b;
    remoteBlocked[i] = remoteOf.get(v);
  }
  const histogram = {};
  for (const [k, c] of [...hist.entries()].sort((a, b) => a[0] - b[0])) histogram[k] = c;
  const out = {
    width: g.width, height: g.height, bytesPerCell: g.bytesPerCell, trailingBytes: g.trailingBytes, empty: n === 0,
    attrs: g.attrs, cells, remoteBlocked, histogram, unknownValues: unknownValues.sort((a, b) => a - b),
    walkableCount: n - blockedCount, blockedCount,
  };
  return attachGridMethods(out, table);
}

/** (Re)attach the lookup helpers to a parsed grid object (e.g. after postMessage). */
export function attachGridMethods(grid, table = DEFAULT_CELL_TABLE) {
  const { width: w, height: h } = grid;
  const idx = (x, y) => {
    const ix = Math.floor(x), iy = Math.floor(y);
    return ix >= 0 && iy >= 0 && ix < w && iy < h ? iy * w + ix : -1;
  };
  const def = (name, fn) => Object.defineProperty(grid, name, { value: fn, enumerable: false, configurable: true, writable: true });
  def('index', idx);
  def('inBounds', (x, y) => idx(x, y) >= 0);
  def('isBlocked', (x, y) => { const i = idx(x, y); return i < 0 || grid.cells[i] === 1; });
  def('isWalkable', (x, y) => { const i = idx(x, y); return i >= 0 && grid.cells[i] === 0; });
  def('attrAt', (x, y) => { const i = idx(x, y); return i < 0 ? -1 : (grid.attrs ? grid.attrs[i] : grid.cells[i]); });
  def('info', (x, y) => { const i = idx(x, y); return i < 0 ? null : (table.get(grid.attrs ? grid.attrs[i] : grid.cells[i]) || null); });
  return grid;
}

/**
 * Nearest walkable cell (Chebyshev rings) — for snapping NPC/brick/warp points that sit on their own
 * blocked footprint. Returns {x, y, distance} (cell indices) or null.
 */
export function nearestWalkable(grid, x, y, maxRadius = 32) {
  const cx = Math.floor(x), cy = Math.floor(y);
  for (let r = 0; r <= maxRadius; r++) {
    for (let dy = -r; dy <= r; dy++) {
      for (let dx = -r; dx <= r; dx++) {
        if (Math.max(Math.abs(dx), Math.abs(dy)) !== r) continue;
        const X = cx + dx, Y = cy + dy;
        if (X >= 0 && Y >= 0 && X < grid.width && Y < grid.height && grid.cells[Y * grid.width + X] === 0) return { x: X, y: Y, distance: r };
      }
    }
  }
  return null;
}

/** Debug colour (RGBA bytes) for an attribute value, from the table's Cell_Color (ARGB). */
export function cellColor(value, table = DEFAULT_CELL_TABLE) {
  const t = table.get(value);
  const c = t ? t.color : 0xFFFFFFFF;
  return [(c >>> 16) & 255, (c >>> 8) & 255, c & 255, (c >>> 24) & 255];
}
