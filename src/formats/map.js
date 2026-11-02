// Dekaron terrain (.map) parser + three.js-ready geometry builders.
// Pure functions: no three.js import, no Node APIs (runs in the browser and in Node).
// Full format description: docs/formats/map.md
//
// File layout (all little-endian, W×H cells, V = (W+1)*(H+1) vertices, row-major, index = row*(W+1)+col):
//   u32 version (20040811 | 20051216), u32 W, u32 H, u32 atlasCount(=2), atlasCount × lpStr atlasName
//   f32[V]     heights            (world units; 1 unit = 1 cell = 1 .mol unit)
//   u8[V*4]    vertex colours     (D3DCOLOR little-endian => bytes B,G,R,A)
//   u32[V]     terrain type 0..3  (which of the 4 base ground textures owns this vertex)
//   f32[V*3]   normals            (file space: +x = +col, +y = up, +z = +row)
//   u16[W*H]   cell variant 0..3  (random pick among the 4 variants of an atlas tile)
//   lpStr      tile folder        ("MapTile\braiken\" -> texture/maptile/braiken/)
//   water list (format depends on version), decal ("tile") list, u32[4] trailer.

import { toArrayBuffer, decodeText } from './binreader.js';

export const MAP_VERSION_V1 = 20040811; // old water format (per-cell list)
export const MAP_VERSION_V2 = 20051216; // patch-grouped water format
export const MAP_CELL_SIZE = 1.0;       // world units per cell (heights use the same unit)
export const ATLAS_GRID = 8;            // each maptex_*.dds is an 8×8 grid of 64 px tiles
export const ATLAS_TILE_PX = 64;
export const ATLAS_SLOTS_USED = 112;    // 16 base + 6 pairs × 16; slots 112..127 (atlas 1 rows 6-7) unused
export const WATER_PATCH = 16;          // v2 water is grouped in 16×16-cell patches

/** PAIR_INDEX[a][b] (a<b): which 16-slot transition block of the atlas pair (a,b) uses. */
export const PAIR_INDEX = [
  [-1, 0, 1, 2],
  [0, -1, 3, 4],
  [1, 3, -1, 5],
  [2, 4, 5, -1],
];

/**
 * TEXTURE ORIENTATION (shared by terrain tiles and decals; see map.md "Texture orientation"):
 * seen from above with +col to the right (east) and +row UP (north), a tile/decal image is displayed UPRIGHT at
 * rotation 0 (image top edge on the high-row side, image left edge on the low-col side) and `rot` turns it
 * rot × 90° COUNTER-clockwise. Proven for decals (multi-part decal pictures such as dead_front's 4-piece
 * s_bigsnaketile medallion only assemble with this rule; corpus-wide seam continuity agrees); terrain tiles follow
 * the same rule by analogy (their transitions are equally continuous under any consistent convention).
 * @param {number} s cell/placement-local coordinate along +col (0..1)
 * @param {number} t cell/placement-local coordinate along +row (0..1)
 * @param {number} rot counter-clockwise quarter turns (0..3; decals: rotations[j] & 3)
 * @returns {[number, number]} texture (u, v), v = 0 = first (top) image row (flipY = false)
 */
export function tileUV(s, t, rot) {
  const [u, v] = rotateUV(s, t, rot);
  return [u, 1 - v];
}

/**
 * Corner mask -> [canonical pattern k (0..3), rot] with rot = counter-clockwise quarter turns for tileUV().
 * Mask bits are set where the corner differs from the selected lower terrain type:
 * 1 = (col,row), 2 = (col+1,row), 4 = (col,row+1), 8 = (col+1,row+1)
 * (seen from above, north = +row: 1 = SW, 2 = SE, 4 = NW, 8 = NE).
 * Canonical atlas patterns (corners that show a type other than the lower type):
 * k0 = {bottom-right}, k1 = {top-right, bottom-right} (right half), k2 = {top-left, bottom-right} (diagonal),
 * k3 = {top-left, top-right, bottom-right} (all but bottom-left). At rot 0 image bottom-right = SE = bit 2.
 * (Pattern and rotation order follows the native terrain classifier.)
 */
export const MASK_TO_TILE = [
  null, [0, 1], [0, 0], [1, 1], [0, 2], [1, 2], [2, 0], [3, 2],
  [0, 3], [2, 1], [1, 0], [3, 1], [1, 3], [3, 3], [3, 0], null,
];

// Cell flags in the tile lookup (A channel).
export const CELL_HOLE = 1;       // covered by an s_empty decal: do not render the terrain. NOT a walkability flag:
                                  // .mac decides (hole cells marked walkable there are object-borne floors, e.g.
                                  // arcadia_sky platforms / bridges; the ground height then comes from the object)
export const CELL_MULTITYPE = 2;  // 3-4 distinct corner types: native selection collapses non-lower types
export const CELL_DECAL = 4;      // covered by at least one (non-hole) decal

const LITTLE_ENDIAN = new Uint8Array(new Uint16Array([1]).buffer)[0] === 1;

function typedSlice(ab, off, count, Ctor) {
  const bytes = count * Ctor.BYTES_PER_ELEMENT;
  if (off + bytes > ab.byteLength) throw new RangeError(`map: section at ${off} (+${bytes}) past end ${ab.byteLength}`);
  if (LITTLE_ENDIAN) return new Ctor(ab.slice(off, off + bytes)); // slice => aligned copy
  const dv = new DataView(ab, off, bytes), out = new Ctor(count);
  const get = Ctor === Float32Array ? 'getFloat32' : Ctor === Uint32Array ? 'getUint32' : 'getUint16';
  for (let i = 0; i < count; i++) out[i] = dv[get](i * Ctor.BYTES_PER_ELEMENT, true);
  return out;
}

class Cursor {
  constructor(ab) { this.ab = ab; this.dv = new DataView(ab); this.u8 = new Uint8Array(ab); this.pos = 0; }
  need(n) { if (this.pos + n > this.ab.byteLength) throw new RangeError(`map: read of ${n} bytes at ${this.pos} past end (${this.ab.byteLength})`); }
  u32() { this.need(4); const v = this.dv.getUint32(this.pos, true); this.pos += 4; return v; }
  u16() { this.need(2); const v = this.dv.getUint16(this.pos, true); this.pos += 2; return v; }
  f32() { this.need(4); const v = this.dv.getFloat32(this.pos, true); this.pos += 4; return v; }
  str() {
    const n = this.u32();
    if (n > 4096) throw new RangeError(`map: implausible string length ${n} at ${this.pos - 4}`);
    this.need(n);
    let b = this.u8.subarray(this.pos, this.pos + n); this.pos += n;
    const z = b.indexOf(0); if (z >= 0) b = b.subarray(0, z);
    return decodeText(b, true);
  }
}

/** Normalise a game path: backslashes -> '/', lowercase, no leading './' or '/'. */
export function normPath(p) {
  return String(p).replace(/\\/g, '/').replace(/\/+/g, '/').replace(/^\.?\//, '').toLowerCase();
}

/** Path (relative to the data root) of a water definition named inside a .map. */
export function waterDefPath(name) {
  const n = normPath(name);
  // v1 files store "Effect\Water\Water01.txt" (relative to property/), v2 files store "water01.txt".
  return n.includes('/') ? `property/${n}` : `property/effect/water/${n}`;
}

/**
 * Parse a .map terrain file.
 * @param {ArrayBuffer|Uint8Array} buf
 * @param {{strict?: boolean}} [opts] strict: throw when bytes remain after the trailer (default false).
 */
export function parseMap(buf, opts = {}) {
  const ab = toArrayBuffer(buf);
  const r = new Cursor(ab);
  const sections = {};
  const mark = (name, start) => { sections[name] = { offset: start, size: r.pos - start }; };

  // ---- header -------------------------------------------------------------------------------
  let s0 = r.pos;
  const version = r.u32();
  if(version !== MAP_VERSION_V1 && version !== MAP_VERSION_V2) throw new Error(`map: unsupported version ${version}; a compatible parser is required.`);
  const width = r.u32(), height = r.u32();
  if (!(width > 0 && height > 0 && width <= 4096 && height <= 4096)) throw new Error(`map: bad size ${width}x${height}`);
  const atlasCount = r.u32();
  if (atlasCount > 16) throw new Error(`map: bad atlas count ${atlasCount}`);
  const atlasNames = [];
  for (let i = 0; i < atlasCount; i++) atlasNames.push(r.str());
  mark('header', s0);
  const knownVersion = true;
  const vertsX = width + 1, vertsZ = height + 1, V = vertsX * vertsZ, C = width * height;

  // ---- fixed-size grids -------------------------------------------------------------------------
  s0 = r.pos; const heights = typedSlice(ab, r.pos, V, Float32Array); r.pos += V * 4; mark('heights', s0);
  s0 = r.pos; r.need(V * 4);
  const colors = new Uint8Array(V * 4); // RGBA
  {
    const src = r.u8;
    for (let i = 0, o = r.pos; i < V; i++, o += 4) {
      colors[i * 4] = src[o + 2]; colors[i * 4 + 1] = src[o + 1]; colors[i * 4 + 2] = src[o]; colors[i * 4 + 3] = src[o + 3];
    }
    r.pos += V * 4;
  }
  mark('colors', s0);
  s0 = r.pos;
  const typesRaw = typedSlice(ab, r.pos, V, Uint32Array); r.pos += V * 4;
  const vertexTypes = new Uint8Array(V);
  let typeOverflow = 0;
  for (let i = 0; i < V; i++) { const t = typesRaw[i]; if (t > 3) typeOverflow++; vertexTypes[i] = t & 3; }
  mark('vertexTypes', s0);
  s0 = r.pos; const normals = typedSlice(ab, r.pos, V * 3, Float32Array); r.pos += V * 12; mark('normals', s0);
  s0 = r.pos; const cellVariants = typedSlice(ab, r.pos, C, Uint16Array); r.pos += C * 2; mark('cellVariants', s0);

  // ---- tile folder --------------------------------------------------------------------------------
  s0 = r.pos;
  const tileFolder = r.str();
  mark('tileFolder', s0);
  let textureDir = normPath(tileFolder);
  if (textureDir && !textureDir.endsWith('/')) textureDir += '/';
  textureDir = 'texture/' + textureDir;

  // ---- water ----------------------------------------------------------------------------------------
  s0 = r.pos;
  const waterCount = r.u32();
  const water = [];
  for (let wi = 0; wi < waterCount; wi++) {
    const name = r.str();
    const count = r.u32();
    const entry = { name, defPath: waterDefPath(name), format: version <= MAP_VERSION_V1 ? 'cells' : 'patches', patches: [], cells: null, cellHeights: null };
    if (version <= MAP_VERSION_V1) {
      // v1: count × { u32 cellIndex (row*W+col), f32 height }
      r.need(count * 8);
      const cells = new Uint32Array(count), hs = new Float32Array(count);
      for (let j = 0; j < count; j++) { cells[j] = r.u32(); hs[j] = r.f32(); }
      entry.cells = cells; entry.cellHeights = hs;
    } else {
      // v2: count × patch { u32 key = centre VERTEX index (row*(W+1)+col) of a 16×16-cell patch,
      //                     u32 levelCount, levelCount × { f32 height, u32 n, n × u32 cellIndex (row*W+col) } }
      const allCells = [], allH = [];
      for (let j = 0; j < count; j++) {
        const key = r.u32();
        const levelCount = r.u32();
        if (levelCount > 1024) throw new RangeError(`map: implausible water level count ${levelCount} at ${r.pos - 4}`);
        const levels = [];
        for (let k = 0; k < levelCount; k++) {
          const h = r.f32();
          const n = r.u32();
          r.need(n * 4);
          const cells = typedSlice(ab, r.pos, n, Uint32Array); r.pos += n * 4;
          levels.push({ height: h, cells });
          for (let q = 0; q < n; q++) { allCells.push(cells[q]); allH.push(h); }
        }
        entry.patches.push({ key, centerCol: key % vertsX, centerRow: Math.floor(key / vertsX), levels });
      }
      entry.cells = Uint32Array.from(allCells); entry.cellHeights = Float32Array.from(allH);
    }
    water.push(entry);
  }
  mark('water', s0);

  // ---- decals ("tiles") -----------------------------------------------------------------------------
  s0 = r.pos;
  const decalCount = r.u32();
  const decals = [];
  for (let di = 0; di < decalCount; di++) {
    const name = r.str();
    const n = r.u32();
    r.need(n * 10 + 4);
    const cells = new Uint32Array(n), sizes = new Uint32Array(n), rotations = new Uint16Array(n);
    for (let j = 0; j < n; j++) { cells[j] = r.u32(); sizes[j] = r.u32(); rotations[j] = r.u16(); }
    const unkMaterial = r.u32();
    const lname = name.toLowerCase();
    const isNone = lname === '' || lname === 'none';
    const isHole = /^s_empty/.test(lname);
    const path = isNone ? null : textureDir + lname;
    decals.push({
      name, path, pathAlt: path && !/\.dds$/.test(path) ? path.replace(/\.[^./]+$/, '.dds') : null,
      isHole, isNone, count: n, cells, sizes, rotations, unkMaterial,
    });
  }
  mark('decals', s0);

  // ---- trailer ----------------------------------------------------------------------------------------
  s0 = r.pos;
  const unkTypeMaterials = [r.u32(), r.u32(), r.u32(), r.u32()];
  mark('trailer', s0);
  const trailing = ab.byteLength - r.pos;
  if (trailing && opts.strict) throw new Error(`map: ${trailing} trailing bytes`);

  // ---- derived: hole mask -------------------------------------------------------------------------
  const holes = new Uint8Array(C);
  for (const d of decals) {
    if (!d.isHole) continue;
    for (let j = 0; j < d.count; j++) {
      const S = d.sizes[j]; if (!S) continue; // size 0 = erased placement (never seen for s_empty, all are size 1)
      const c0 = d.cells[j] % width, r0 = Math.floor(d.cells[j] / width);
      for (let y = r0; y < r0 + S && y < height; y++) for (let x = c0; x < c0 + S && x < width; x++) holes[y * width + x] = 1;
    }
  }

  const atlasPaths = atlasNames.map(n => textureDir + n.toLowerCase());
  const layers = [0, 1, 2, 3].map(t => ({
    type: t,
    texture: atlasPaths[0] || null,  // base tiles of all 4 types live in atlas 0 (rows 0-1)
    atlas: 0,
    slots: [t * 4, t * 4 + 1, t * 4 + 2, t * 4 + 3],
    uvScale: 1,                      // one 64 px tile per cell
    unkMaterial: unkTypeMaterials[t],
  }));

  return {
    version, knownVersion, width, height, cellSize: MAP_CELL_SIZE, vertsX, vertsZ,
    heights, colors, normals, vertexTypes, cellVariants,
    atlasNames, atlasPaths,
    atlasPathsAlt: atlasPaths.map(p => (/\.dds$/.test(p) ? null : p.replace(/\.[^./]+$/, '.dds'))),
    tileFolder, textureDir,
    layers, water, decals, holes, unkTypeMaterials,
    unkTypeOverflow: typeOverflow,
    sections, byteLength: ab.byteLength, bytesConsumed: r.pos, trailing,
  };
}

// =====================================================================================================
// Terrain tile selection (the "blend" of this format: corner-type transition tiles from 2 atlases)
// =====================================================================================================

/**
 * Atlas slot + rotation for one cell.
 * @returns {{slot:number, atlas:number, atlasCol:number, atlasRow:number, rot:number, variant:number,
 *            lo:number, hi:number, mask:number, flags:number}}
 *   rot = counter-clockwise quarter turns of the upright tile image seen from above (north = +row):
 *   sample the atlas tile at tileUV(s, t, rot) for the cell-local point (s along +col, t along +row).
 */
export function terrainTileForCell(map, col, row) {
  const X = map.vertsX, T = map.vertexTypes;
  const i = row * X + col;
  const tl = T[i], tr = T[i + 1], bl = T[i + X], br = T[i + X + 1];
  const variant = map.cellVariants[row * map.width + col] & 3;
  let flags = map.holes[row * map.width + col] ? CELL_HOLE : 0;
  let slot, rot = 0, lo, hi, mask = 0;
  if (tl === tr && tl === bl && tl === br) {
    lo = hi = tl; slot = tl * 4 + variant;
  } else {
    // Native client examines corners in TL, BL, BR, TR order and chooses the
    // first value different from TL. Other types are rendered as the upper type.
    const second = bl !== tl ? bl : br !== tl ? br : tr;
    lo = Math.min(tl, second); hi = Math.max(tl, second);
    if ((tl !== lo && tl !== hi) || (tr !== lo && tr !== hi) ||
        (bl !== lo && bl !== hi) || (br !== lo && br !== hi)) flags |= CELL_MULTITYPE;
    mask = (tl !== lo ? 1 : 0) | (tr !== lo ? 2 : 0) | (bl !== lo ? 4 : 0) | (br !== lo ? 8 : 0);
    const [k, r] = MASK_TO_TILE[mask];
    slot = 16 + PAIR_INDEX[lo][hi] * 16 + k * 4 + variant;
    rot = r;
  }
  const local = slot & 63;
  return { slot, atlas: slot >> 6, atlasCol: local & 7, atlasRow: local >> 3, rot, variant, lo, hi, mask, flags };
}

/**
 * Per-cell lookup texture for a terrain ShaderMaterial (THREE.DataTexture, RGBA, UnsignedByte, NearestFilter,
 * flipY=false; texel (col,row) = data[(row*W+col)*4]).
 * R = atlas slot 0..111 (atlas = slot>>6), G = rot 0..3 for tileUV() (counter-clockwise quarter turns seen from
 * above), B = variant, A = CELL_* flags.
 */
export function buildTileLookup(map) {
  const W = map.width, H = map.height, data = new Uint8Array(W * H * 4);
  const decalCover = new Uint8Array(W * H);
  for (const d of map.decals) {
    if (d.isHole || d.isNone) continue;
    for (let j = 0; j < d.count; j++) {
      const S = d.sizes[j]; if (!S) continue;
      const c0 = d.cells[j] % W, r0 = Math.floor(d.cells[j] / W);
      for (let y = r0; y < r0 + S && y < H; y++) for (let x = c0; x < c0 + S && x < W; x++) decalCover[y * W + x] = 1;
    }
  }
  let multi = 0;
  for (let row = 0; row < H; row++) {
    for (let col = 0; col < W; col++) {
      const t = terrainTileForCell(map, col, row), o = (row * W + col) * 4;
      if (t.flags & CELL_MULTITYPE) multi++;
      data[o] = t.slot; data[o + 1] = t.rot; data[o + 2] = t.variant;
      data[o + 3] = t.flags | (decalCover[row * W + col] ? CELL_DECAL : 0);
    }
  }
  return { width: W, height: H, data, multiTypeCells: multi };
}

/**
 * Low-level helper: rotate (s,t)∈[0,1]² as image coordinates, (u,v) <- (v, 1-u) per turn, i.e. the displayed
 * image is turned clockwise in a (right = +s, down = +t) view. This is NOT the texture mapping on its own: use
 * tileUV() (= rotateUV followed by v -> 1-v), which is what the game does for tiles and decals.
 */
export function rotateUV(s, t, cwTurns) {
  let u = s, v = t;
  const n = ((cwTurns % 4) + 4) % 4;
  for (let i = 0; i < n; i++) { const nu = v, nv = 1 - u; u = nu; v = nv; } // CW: (u,v) <- (v, 1-u)
  return [u, v];
}

/** UV of a point inside an atlas slot (flipY=false textures: v=0 is the first/top image row). */
export function atlasUV(slot, u, v) {
  const local = slot & 63;
  return [((local & 7) + u) / ATLAS_GRID, ((local >> 3) + v) / ATLAS_GRID];
}

/**
 * Split the two decoded atlases (RGBA8, e.g. dds.js decodeToRGBA(parseDDS(buf))) into a texture-array payload:
 * layer = slot (0..111), each layer tilePx×tilePx (64 for 512² atlases). Upload as
 * new THREE.DataArrayTexture(data, tilePx, tilePx, layers) with generateMipmaps = true -> no cross-tile bleeding.
 * A missing atlas (null) yields grey layers.
 * @param {({width:number,height:number,data:Uint8Array}|null)[]} atlases
 */
export function buildTileArrayData(atlases, layers = ATLAS_SLOTS_USED) {
  const ref = atlases.find(Boolean);
  const tilePx = ref ? Math.floor(ref.width / ATLAS_GRID) : ATLAS_TILE_PX;
  const layerBytes = tilePx * tilePx * 4, data = new Uint8Array(layerBytes * layers);
  for (let slot = 0; slot < layers; slot++) {
    const at = atlases[slot >> 6], local = slot & 63, o = slot * layerBytes;
    if (!at || at.width < tilePx * ATLAS_GRID || at.height < tilePx * ATLAS_GRID) { data.fill(128, o, o + layerBytes); continue; }
    const x0 = (local & 7) * tilePx, y0 = (local >> 3) * tilePx;
    for (let y = 0; y < tilePx; y++) {
      const src = ((y0 + y) * at.width + x0) * 4;
      data.set(at.data.subarray(src, src + tilePx * 4), o + y * tilePx * 4);
    }
  }
  return { width: tilePx, height: tilePx, depth: layers, data };
}

/** One-hot per-vertex weights of the 4 base types (for a simple splat fallback material). Float32Array(V*4). */
export function computeLayerWeights(map) {
  const V = map.vertsX * map.vertsZ, w = new Float32Array(V * 4);
  for (let i = 0; i < V; i++) w[i * 4 + map.vertexTypes[i]] = 1;
  return w;
}

// =====================================================================================================
// Height queries (file/grid space: col = x / cellSize, row = -z / cellSize in three.js space)
// =====================================================================================================

/** Terrain height at continuous grid coords, using the same triangulation as buildTerrainArrays. */
export function sampleHeight(map, col, row) {
  const W = map.width, H = map.height, X = map.vertsX, h = map.heights;
  if (!(col >= 0)) col = 0; if (!(row >= 0)) row = 0;
  if (col > W) col = W; if (row > H) row = H;
  let i = Math.floor(col), j = Math.floor(row);
  if (i >= W) i = W - 1; if (j >= H) j = H - 1;
  const fx = col - i, fz = row - j, a = j * X + i;
  const ha = h[a], hb = h[a + 1], hc = h[a + X], hd = h[a + X + 1];
  // cells are split along the (col,row)-(col+1,row+1) diagonal
  return fx >= fz ? ha + (hb - ha) * fx + (hd - hb) * fz : ha + (hc - ha) * fz + (hd - hc) * fx;
}

/** Height at a three.js world position (x, z) (terrain placed with buildTerrainArrays defaults). */
export function heightAtWorld(map, x, z, originX = 0, originZ = 0) {
  return sampleHeight(map, (x - originX) / map.cellSize, -(z - originZ) / map.cellSize);
}

/** Water surface height of a cell, or null. Builds a cache on the map object on first use. */
export function waterHeightAtCell(map, col, row) {
  if (!map._waterIndex) {
    const idx = new Map();
    for (let wi = 0; wi < map.water.length; wi++) {
      const w = map.water[wi];
      for (let j = 0; j < w.cells.length; j++) idx.set(w.cells[j], { height: w.cellHeights[j], water: wi });
    }
    Object.defineProperty(map, '_waterIndex', { value: idx, enumerable: false });
  }
  if (col < 0 || row < 0 || col >= map.width || row >= map.height) return null;
  const e = map._waterIndex.get(row * map.width + col);
  return e ? e.height : null;
}

// =====================================================================================================
// Geometry builders -> plain typed arrays for THREE.BufferGeometry
// Coordinate conversion (D3D left-handed -> three.js right-handed):
//   file vertex (col,row,h)  -> D3D (X=col*cs, Y=h, Z=row*cs) -> three (x=X, y=Y, z=-Z)
//   normal (nx,ny,nz)        -> (nx, ny, -nz)
//   triangles per cell: (a,b,d),(a,d,c) with a=(col,row) b=(col+1,row) c=(col,row+1) d=(col+1,row+1)
//   -> counter-clockwise seen from +Y in three.js (front faces up, default side=FrontSide works).
// =====================================================================================================

/**
 * @param {object} map parseMap() result
 * @param {{x0?:number,z0?:number,cols?:number,rows?:number,skipHoles?:boolean,originX?:number,originZ?:number,
 *          splat?:boolean}} [opts]  chunk = cells [x0,x0+cols) × [z0,z0+rows)
 */
export function buildTerrainArrays(map, opts = {}) {
  const cs = map.cellSize, X = map.vertsX;
  const x0 = opts.x0 | 0, z0 = opts.z0 | 0;
  const cols = Math.min(opts.cols ?? map.width - x0, map.width - x0);
  const rows = Math.min(opts.rows ?? map.height - z0, map.height - z0);
  const ox = opts.originX || 0, oz = opts.originZ || 0;
  const skipHoles = opts.skipHoles !== false;
  const vx = cols + 1, vz = rows + 1, Vc = vx * vz;
  const positions = new Float32Array(Vc * 3), normals = new Float32Array(Vc * 3);
  const uvs = new Float32Array(Vc * 2), colors = new Uint8Array(Vc * 3);
  const splat = opts.splat ? new Float32Array(Vc * 4) : null;
  let minY = Infinity, maxY = -Infinity;
  for (let r = 0; r < vz; r++) {
    for (let c = 0; c < vx; c++) {
      const src = (z0 + r) * X + (x0 + c), dst = r * vx + c;
      const h = map.heights[src];
      positions[dst * 3] = ox + (x0 + c) * cs;
      positions[dst * 3 + 1] = h;
      positions[dst * 3 + 2] = oz - (z0 + r) * cs;
      normals[dst * 3] = map.normals[src * 3];
      normals[dst * 3 + 1] = map.normals[src * 3 + 1];
      normals[dst * 3 + 2] = -map.normals[src * 3 + 2];
      uvs[dst * 2] = x0 + c; uvs[dst * 2 + 1] = z0 + r; // absolute cell coords; fract() = in-cell position
      colors[dst * 3] = map.colors[src * 4]; colors[dst * 3 + 1] = map.colors[src * 4 + 1]; colors[dst * 3 + 2] = map.colors[src * 4 + 2];
      if (splat) splat[dst * 4 + map.vertexTypes[src]] = 1;
      if (h < minY) minY = h; if (h > maxY) maxY = h;
    }
  }
  let nTri = 0;
  for (let r = 0; r < rows; r++) for (let c = 0; c < cols; c++) if (!(skipHoles && map.holes[(z0 + r) * map.width + x0 + c])) nTri += 2;
  const indices = Vc > 65535 ? new Uint32Array(nTri * 3) : new Uint16Array(nTri * 3);
  let k = 0;
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (skipHoles && map.holes[(z0 + r) * map.width + x0 + c]) continue;
      const a = r * vx + c, b = a + 1, cc = a + vx, d = cc + 1;
      indices[k++] = a; indices[k++] = b; indices[k++] = d;
      indices[k++] = a; indices[k++] = d; indices[k++] = cc;
    }
  }
  return {
    positions, normals, uvs, colors, colorItemSize: 3, splat, indices,
    vertexCount: Vc, triangleCount: nTri,
    bbox: { min: [ox + x0 * cs, minY, oz - (z0 + rows) * cs], max: [ox + (x0 + cols) * cs, maxY, oz - z0 * cs] },
    x0, z0, cols, rows,
  };
}

/**
 * Decal ("tile") meshes that drape over the terrain. One group per decal record (file order = draw order).
 * UVs: decal-local tileUV(s, t, rotation & 3) -> image upright seen from above (north = +row), turned
 * counter-clockwise by (rotation & 3) quarter turns; textures flipY=false. Vertices sit exactly on the terrain grid
 * vertices with the terrain's diagonal, so a decal is coplanar with the ground (use polygonOffset, not lift).
 * @param {{includeHoles?:boolean, lift?:number, originX?:number, originZ?:number}} [opts]
 */
export function buildDecalArrays(map, opts = {}) {
  const W = map.width, H = map.height, X = map.vertsX, cs = map.cellSize;
  const ox = opts.originX || 0, oz = opts.originZ || 0, lift = opts.lift || 0;
  const groups = [];
  map.decals.forEach((d, record) => {
    if (d.isNone || (d.isHole && !opts.includeHoles)) return;
    let nv = 0, nq = 0;
    for (let j = 0; j < d.count; j++) {
      const S = d.sizes[j]; if (!S) continue;
      const c0 = d.cells[j] % W, r0 = Math.floor(d.cells[j] / W);
      if (r0 >= H) continue;
      nv += (S + 1) * (S + 1); nq += Math.min(S, W - c0) * Math.min(S, H - r0);
    }
    if (!nq) return;
    const positions = new Float32Array(nv * 3), normals = new Float32Array(nv * 3), uvs = new Float32Array(nv * 2);
    const colors = new Uint8Array(nv * 3), indices = nv > 65535 ? new Uint32Array(nq * 6) : new Uint16Array(nq * 6);
    let v = 0, k = 0, instances = 0;
    for (let j = 0; j < d.count; j++) {
      const S = d.sizes[j]; if (!S) continue;
      const c0 = d.cells[j] % W, r0 = Math.floor(d.cells[j] / W);
      if (r0 >= H) continue;
      instances++;
      const rot = d.rotations[j] & 3, base = v;
      for (let y = 0; y <= S; y++) {
        for (let x = 0; x <= S; x++) {
          const col = Math.min(c0 + x, W), row = Math.min(r0 + y, H), src = row * X + col;
          positions[v * 3] = ox + (c0 + x) * cs;
          positions[v * 3 + 1] = map.heights[src] + lift;
          positions[v * 3 + 2] = oz - (r0 + y) * cs;
          normals[v * 3] = map.normals[src * 3]; normals[v * 3 + 1] = map.normals[src * 3 + 1]; normals[v * 3 + 2] = -map.normals[src * 3 + 2];
          const [u, vv] = tileUV(x / S, y / S, rot);
          uvs[v * 2] = u; uvs[v * 2 + 1] = vv;
          colors[v * 3] = map.colors[src * 4]; colors[v * 3 + 1] = map.colors[src * 4 + 1]; colors[v * 3 + 2] = map.colors[src * 4 + 2];
          v++;
        }
      }
      for (let y = 0; y < S && r0 + y < H; y++) {
        for (let x = 0; x < S && c0 + x < W; x++) {
          const a = base + y * (S + 1) + x, b = a + 1, c = a + S + 1, dd = c + 1;
          indices[k++] = a; indices[k++] = b; indices[k++] = dd;
          indices[k++] = a; indices[k++] = dd; indices[k++] = c;
        }
      }
    }
    groups.push({
      record, name: d.name, path: d.path, pathAlt: d.pathAlt, isHole: d.isHole, unkMaterial: d.unkMaterial,
      instances, positions, normals, uvs, colors, colorItemSize: 3, indices: k === indices.length ? indices : indices.subarray(0, k),
      vertexCount: v, triangleCount: k / 3,
    });
  });
  return groups;
}

/**
 * Water surfaces: one flat quad per water cell at its level height, grouped per water definition.
 * uvs = absolute cell coords (col,row) for world-space tiling/scrolling.
 */
export function buildWaterArrays(map, opts = {}) {
  const W = map.width, H = map.height, cs = map.cellSize, ox = opts.originX || 0, oz = opts.originZ || 0;
  return map.water.map((w, wi) => {
    const seen = new Set(), list = [];
    for (let j = 0; j < w.cells.length; j++) {
      const cell = w.cells[j];
      if (cell >= W * H || seen.has(cell)) continue;
      seen.add(cell); list.push(j);
    }
    const n = list.length;
    const positions = new Float32Array(n * 12), uvs = new Float32Array(n * 8);
    const indices = n * 4 > 65535 ? new Uint32Array(n * 6) : new Uint16Array(n * 6);
    let minH = Infinity, maxH = -Infinity;
    list.forEach((j, q) => {
      const cell = w.cells[j], h = w.cellHeights[j], c = cell % W, r = Math.floor(cell / W);
      if (h < minH) minH = h; if (h > maxH) maxH = h;
      const corners = [[c, r], [c + 1, r], [c, r + 1], [c + 1, r + 1]];
      corners.forEach(([cc, rr], t) => {
        positions[(q * 4 + t) * 3] = ox + cc * cs; positions[(q * 4 + t) * 3 + 1] = h; positions[(q * 4 + t) * 3 + 2] = oz - rr * cs;
        uvs[(q * 4 + t) * 2] = cc; uvs[(q * 4 + t) * 2 + 1] = rr;
      });
      const a = q * 4;
      indices.set([a, a + 1, a + 3, a, a + 3, a + 2], q * 6);
    });
    return { water: wi, name: w.name, defPath: w.defPath, positions, uvs, indices, cellCount: n, minHeight: minH, maxHeight: maxH };
  });
}

// =====================================================================================================
// Reference shaders for THREE.ShaderMaterial (strings only; three.js prepends its standard declarations).
// Terrain: geometry from buildTerrainArrays (attributes position, normal, uv, vcolor = colors [3, normalized]),
// uniforms:
//   tileArray  DataArrayTexture from buildTileArrayData (RGBA, generateMipmaps, LinearMipmapLinear, flipY=false,
//              colorSpace = SRGBColorSpace like every colour texture of the engine, dds.md)
//   tileLUT    DataTexture from buildTileLookup (RGBA UnsignedByte, NearestFilter, no mipmaps, flipY=false,
//              colorSpace = NoColorSpace: it holds indices)
//   mapSize    vec2(width, height)
//   ambientColor, lightColor (vec3, LINEAR: e.g. new THREE.Color().setRGB(r, g, b, THREE.SRGBColorSpace) from the
//              light file), lightDir (vec3, direction TO the light, three.js frame), fogColor (vec3, linear),
//              fogRange (vec2 near, far)
// Output goes through <colorspace_fragment> (renderer.outputColorSpace = SRGBColorSpace, as game.js sets it); with
// ambient 1 / light 0 the result is exactly the D3D9 gamma-space product tile x vertexColour (GPU-checked by
// tools/verify-terrain-gpu.html).
// Decals: geometry from buildDecalArrays (uv already oriented), uniform decalMap (flipY=false, SRGBColorSpace) + the
// lighting uniforms.
// =====================================================================================================

export const TERRAIN_VERTEX_GLSL = /* glsl */`
attribute vec3 vcolor;
varying vec2 vCell;
varying vec3 vColor;
varying vec3 vNormalW;
varying float vFogDepth;
void main() {
  vCell = uv;
  vColor = vcolor;
  vNormalW = normalize(mat3(modelMatrix) * normal);
  vec4 mv = modelViewMatrix * vec4(position, 1.0);
  vFogDepth = length(mv.xyz);   // range fog: distance to the camera (geometry.fx GetFogLinear, src/engine/fog-model.js)
  gl_Position = projectionMatrix * mv;
}`;

const LIGHTING_GLSL = /* glsl */`
uniform vec3 ambientColor;
uniform vec3 lightColor;
uniform vec3 lightDir;
uniform vec3 fogColor;
uniform vec2 fogRange;
varying vec2 vCell;
varying vec3 vColor;
varying vec3 vNormalW;
varying float vFogDepth;
vec4 dkShade(vec3 base) {
  float ndl = max(dot(normalize(vNormalW), normalize(lightDir)), 0.0);
  // vertex colours are gamma-space bytes like the textures: linearise them so that base * vColor equals the
  // D3D9 gamma-space modulate after <colorspace_fragment> re-encodes (textures must be SRGBColorSpace, see map.md)
  vec3 vc = sRGBTransferEOTF(vec4(vColor, 1.0)).rgb;
  vec3 col = base * vc * (ambientColor + lightColor * ndl);
  float f = clamp((vFogDepth - fogRange.x) / max(fogRange.y - fogRange.x, 1e-4), 0.0, 1.0);   // linear (GetFogLinear)
  return vec4(mix(col, fogColor, f), 1.0);
}`;

export const TERRAIN_FRAGMENT_GLSL = /* glsl */`
precision highp sampler2DArray;
uniform sampler2DArray tileArray;
uniform sampler2D tileLUT;
uniform vec2 mapSize;
${LIGHTING_GLSL}
// = map.js tileUV(s, t, r): upright image seen from above (north = +row), r counter-clockwise quarter turns
vec2 dkTileUV(vec2 st, float r) {
  vec2 uv = st;
  if (r > 2.5) uv = vec2(1.0 - st.y, st.x);
  else if (r > 1.5) uv = vec2(1.0 - st.x, 1.0 - st.y);
  else if (r > 0.5) uv = vec2(st.y, 1.0 - st.x);
  return vec2(uv.x, 1.0 - uv.y);
}
void main() {
  vec2 cell = clamp(floor(vCell), vec2(0.0), mapSize - 1.0);
  vec2 st = clamp(vCell - cell, 0.0, 1.0);
  vec4 t = floor(texture2D(tileLUT, (cell + 0.5) / mapSize) * 255.0 + 0.5); // r=slot g=rot b=variant a=flags
  if (mod(t.a, 2.0) > 0.5) discard;                                           // CELL_HOLE
  vec3 base = textureGrad(tileArray, vec3(dkTileUV(st, t.g), t.r), dFdx(vCell), dFdy(vCell)).rgb;
  gl_FragColor = dkShade(base);
  #include <colorspace_fragment>
}`;

export const DECAL_FRAGMENT_GLSL = /* glsl */`
uniform sampler2D decalMap;
${LIGHTING_GLSL}
void main() {
  gl_FragColor = dkShade(texture2D(decalMap, vCell).rgb);
  #include <colorspace_fragment>
}`;

// Water definition files (entry.defPath -> property/effect/water/*.txt) are parsed by
// environment.js parseWater(); nothing water-material related is stored in the .map itself.
