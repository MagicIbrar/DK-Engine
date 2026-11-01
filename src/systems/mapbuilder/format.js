// Custom map documents (map builder) and writers for the ORIGINAL client formats.
//
// A custom map is stored exactly as the game's own files, so the engine loads it through the same code as every
// shipped map (world.js): the terrain is a real .map (version 20051216, docs/formats/map.md), the objects a real
// .mol (mol.md), the collision grid a real .mac (mac.md); the placements the client keeps in CSV tables (monster
// spawns, NPCs), the start point, portals and the environment live in a small JSON "meta" next to them.
//
// MapDoc = the editable state (FILE frame: X = column, Z = row, 1 unit = 1 cell):
//   heights Float32(V), colors Uint8(V*4 RGBA), vertexTypes Uint8(V), normals Float32(V*3), cellVariants Uint16(C)
//   attrs Uint16(C)            .mac attribute per cell (share/arrange/cell.csv index, 0 = walkable)
//   holes Uint8(C)             terrain not drawn (s_empty decals)
//   waterDef Uint8(C)          0 = dry, k = waterDefs[k-1] (property/effect/water/<name>)
//   waterH Float32(C)          water surface level of the cell
//   decals [{name, cell, size, rot, mat}]   texture/maptile/<folder>/<name>, footprint size x size cells
//   objects [{id, name, x, z, y (above terrain), qx, qy, qz, qw, scale}]
//   meta { id, index, name, desc, start, spawns, npcs, portals, env, ... }
// Pure module: no three.js, no DOM (runs in Node for tests).
import { parseMap, MAP_VERSION_V2 } from '../../formats/map.js';
import { parseMol } from '../../formats/mol.js';
import { parseMac, DEFAULT_CELL_TABLE } from '../../formats/mac.js';

export const CUSTOM_BASE = 90000;            // custom map indices: 90001, 90002, ... (never used by maplist.csv)
export const META_FORMAT = 'dekaron-online/custommap@1';
export const HOLE_DECAL = 's_empty.dds';
export const DEFAULT_TILE_FOLDER = 'MapTile\\braiken\\';
export const DEFAULT_LIGHT = 'light_braiken.txt';
export const DEFAULT_WATER = 'water01.txt';
export const SIZES = [64, 128, 256, 512];

let idSeq = 1;
export const newId = (p = 'o') => `${p}${Date.now().toString(36)}${(idSeq++).toString(36)}`;
export const isCustomIndex = (i) => Number(i) > CUSTOM_BASE && Number(i) < CUSTOM_BASE + 100000;

// ------------------------------------------------------------------------------------------ byte writer
class Writer {
  constructor(size = 1 << 16) { this.buf = new ArrayBuffer(size); this.dv = new DataView(this.buf); this.u8 = new Uint8Array(this.buf); this.pos = 0; }
  need(n) {
    if (this.pos + n <= this.buf.byteLength) return;
    let s = this.buf.byteLength * 2; while (s < this.pos + n) s *= 2;
    const nb = new ArrayBuffer(s); new Uint8Array(nb).set(this.u8); this.buf = nb; this.dv = new DataView(nb); this.u8 = new Uint8Array(nb);
  }
  u32(v) { this.need(4); this.dv.setUint32(this.pos, v >>> 0, true); this.pos += 4; }
  u16(v) { this.need(2); this.dv.setUint16(this.pos, v & 0xffff, true); this.pos += 2; }
  f32(v) { this.need(4); this.dv.setFloat32(this.pos, v, true); this.pos += 4; }
  bytes(a) { this.need(a.length); this.u8.set(a, this.pos); this.pos += a.length; }
  typed(t) { this.bytes(new Uint8Array(t.buffer, t.byteOffset, t.byteLength)); }   // little-endian hosts (browsers, x86 Node)
  str(s) { const b = ascii(s); this.u32(b.length); this.bytes(b); }
  done() { return this.buf.slice(0, this.pos); }
}
function ascii(s) { const str = String(s ?? ''); const b = new Uint8Array(str.length); for (let i = 0; i < str.length; i++) { const c = str.charCodeAt(i); b[i] = c < 256 ? c : 63; } return b; }

// ------------------------------------------------------------------------------------------ MapDoc
export class MapDoc {
  constructor(width, height = width) {
    const W = width | 0, H = height | 0, V = (W + 1) * (H + 1), C = W * H;
    this.width = W; this.height = H;
    this.heights = new Float32Array(V);
    this.colors = new Uint8Array(V * 4).fill(255);
    this.vertexTypes = new Uint8Array(V);
    this.normals = new Float32Array(V * 3);
    for (let i = 0; i < V; i++) this.normals[i * 3 + 1] = 1;
    this.cellVariants = new Uint16Array(C);
    this.attrs = new Uint16Array(C);
    this.holes = new Uint8Array(C);
    this.waterDef = new Uint8Array(C);
    this.waterH = new Float32Array(C);
    this.waterDefs = [DEFAULT_WATER];
    this.decals = [];
    this.objects = [];
    this.tileFolder = DEFAULT_TILE_FOLDER;
    this.atlasNames = ['maptex_first.dds', 'maptex_second.dds'];
    this.typeMaterials = [0, 0, 0, 0];
    this.meta = defaultMeta(W, H);
  }
  get vertsX() { return this.width + 1; }
  get V() { return (this.width + 1) * (this.height + 1); }
  get C() { return this.width * this.height; }

  /** A new flat map. opts: {size, name, tileFolder, height, type, color:[r,g,b], light} */
  static blank(opts = {}) {
    const W = SIZES.includes(Number(opts.size)) ? Number(opts.size) : 256;
    const d = new MapDoc(W, W);
    if (opts.tileFolder) d.tileFolder = normFolder(opts.tileFolder);
    if (Number.isFinite(Number(opts.height))) d.heights.fill(Number(opts.height));
    if (opts.type != null) d.vertexTypes.fill(Number(opts.type) & 3);
    if (Array.isArray(opts.color)) for (let i = 0; i < d.V; i++) { d.colors[i * 4] = opts.color[0]; d.colors[i * 4 + 1] = opts.color[1]; d.colors[i * 4 + 2] = opts.color[2]; }
    let seed = 12345;
    for (let i = 0; i < d.C; i++) { seed = (seed * 1103515245 + 12345) >>> 0; d.cellVariants[i] = (seed >>> 16) & 3; }
    d.meta.name = String(opts.name || 'New Map').slice(0, 60);
    if (opts.light) d.meta.env.light = opts.light;
    d.meta.start = { x: W / 2, z: W / 2, dirDeg: 0 };
    return d;
  }

  /**
   * From original files. files: {map: ArrayBuffer, mol?: ArrayBuffer, mac?: ArrayBuffer, meta?: object}.
   * The same path loads a stored custom map (its files are original formats) and an original client map.
   */
  static fromFiles(files) {
    const m = parseMap(files.map);
    const d = new MapDoc(m.width, m.height);
    d.heights.set(m.heights); d.colors.set(m.colors); d.vertexTypes.set(m.vertexTypes); d.normals.set(m.normals);
    d.cellVariants.set(m.cellVariants); d.holes.set(m.holes);
    d.tileFolder = m.tileFolder || DEFAULT_TILE_FOLDER;
    d.atlasNames = m.atlasNames.length ? m.atlasNames.slice() : d.atlasNames;
    d.typeMaterials = m.unkTypeMaterials.slice();
    // water: per-cell definition + level (entries in file order; the first entry wins a doubly listed cell)
    d.waterDefs = [];
    const C = d.C;
    for (const w of m.water) {
      let k = d.waterDefs.findIndex(n => n.toLowerCase() === waterName(w.name).toLowerCase());
      if (k < 0) { d.waterDefs.push(waterName(w.name)); k = d.waterDefs.length - 1; }
      if (k > 254) continue;
      for (let j = 0; j < w.cells.length; j++) {
        const c = w.cells[j];
        if (c >= C || d.waterDef[c]) continue;
        d.waterDef[c] = k + 1; d.waterH[c] = w.cellHeights[j];
      }
    }
    if (!d.waterDefs.length) d.waterDefs.push(DEFAULT_WATER);
    // decals (holes are kept in d.holes)
    for (const r of m.decals) {
      if (r.isNone || r.isHole) continue;
      for (let j = 0; j < r.count; j++) if (r.sizes[j]) d.decals.push({ name: r.name, cell: r.cells[j], size: r.sizes[j], rot: r.rotations[j] & 3, mat: r.unkMaterial });
    }
    if (files.mol) {
      try {
        const mol = parseMol(files.mol);
        for (const o of mol.objects) d.objects.push({ id: newId(), name: o.name, x: o.x, z: o.z, y: o.y, qx: o.qx, qy: o.qy, qz: o.qz, qw: o.qw, scale: o.scale });
      } catch (err) { console.warn('[mapbuilder] .mol parse failed', err); }
    }
    if (files.mac) {
      try {
        const g = parseMac(files.mac);
        if (!g.empty && g.width === d.width && g.height === d.height) d.attrs.set(g.attrs);
      } catch (err) { console.warn('[mapbuilder] .mac parse failed', err); }
    }
    if (files.meta) d.meta = mergeMeta(defaultMeta(d.width, d.height), files.meta);
    return d;
  }

  /** The original files of this map: { map, mol, mac } ArrayBuffers + meta (plain object). */
  toFiles() {
    this.meta.size = this.width;
    this.meta.objects = this.objects.length;
    return { map: writeMap(this.mapView()), mol: writeMol(this.objects), mac: writeMac(this.width, this.height, this.attrs), meta: clone(this.meta) };
  }

  /** Deep copy (undo snapshots of whole maps, "save as"). */
  clone() { return MapDoc.fromFiles(this.toFiles()); }

  // ---------------------------------------------------------------------------------------- views
  /** Texture folder data key ("texture/maptile/braiken/"). */
  get textureDir() { let t = String(this.tileFolder || '').replace(/\\/g, '/').toLowerCase(); if (t && !t.endsWith('/')) t += '/'; return 'texture/' + t.replace(/^\/+/, ''); }

  /**
   * A parseMap()-shaped object over this document (shares the typed arrays): what Terrain / WaterLayer / writeMap
   * take. Water entries and decal records are rebuilt from the per-cell arrays on every call.
   */
  mapView() {
    const tex = this.textureDir;
    const atlasPaths = this.atlasNames.map(n => tex + n.toLowerCase());
    return {
      version: MAP_VERSION_V2, knownVersion: true, width: this.width, height: this.height, cellSize: 1,
      vertsX: this.width + 1, vertsZ: this.height + 1,
      heights: this.heights, colors: this.colors, normals: this.normals, vertexTypes: this.vertexTypes, cellVariants: this.cellVariants,
      atlasNames: this.atlasNames.slice(), atlasPaths,
      atlasPathsAlt: atlasPaths.map(p => (/\.dds$/.test(p) ? null : p.replace(/\.[^./]+$/, '.dds'))),
      tileFolder: this.tileFolder, textureDir: tex,
      water: this.waterEntries(), decals: this.decalRecords(), holes: this.holes,
      unkTypeMaterials: this.typeMaterials.slice(), layers: [], unkTypeOverflow: 0,
    };
  }

  /** map.water entries (per definition): {name, defPath, format, cells, cellHeights}. */
  waterEntries() {
    const C = this.C, per = this.waterDefs.map(() => []);
    for (let c = 0; c < C; c++) { const k = this.waterDef[c]; if (k && per[k - 1]) per[k - 1].push(c); }
    const out = [];
    per.forEach((cells, k) => {
      if (!cells.length) return;
      const name = this.waterDefs[k];
      const hs = new Float32Array(cells.length);
      cells.forEach((c, j) => { hs[j] = this.waterH[c]; });
      out.push({ name, defPath: `property/effect/water/${name.toLowerCase()}`, format: 'patches', patches: [], cells: Uint32Array.from(cells), cellHeights: hs });
    });
    return out;
  }

  /** map.decals records: textured decals grouped by (name, material) in first-use order, then the holes. */
  decalRecords() {
    const tex = this.textureDir;
    const groups = new Map();
    for (const d of this.decals) {
      const key = `${String(d.name).toLowerCase()}|${d.mat | 0}`;
      let g = groups.get(key);
      if (!g) groups.set(key, (g = { name: d.name, mat: d.mat | 0, list: [] }));
      g.list.push(d);
    }
    const rec = (name, list, mat, isHole) => {
      const n = list.length, cells = new Uint32Array(n), sizes = new Uint32Array(n), rotations = new Uint16Array(n);
      list.forEach((d, j) => { cells[j] = d.cell; sizes[j] = d.size; rotations[j] = d.rot & 3; });
      const path = tex + String(name).toLowerCase();
      return { name, path, pathAlt: /\.dds$/.test(path) ? null : path.replace(/\.[^./]+$/, '.dds'), isHole, isNone: false, count: n, cells, sizes, rotations, unkMaterial: mat };
    };
    const out = [...groups.values()].map(g => rec(g.name, g.list, g.mat, false));
    const holes = [];
    for (let c = 0; c < this.C; c++) if (this.holes[c]) holes.push({ cell: c, size: 1, rot: 0 });
    if (holes.length) out.push(rec(HOLE_DECAL, holes, 0, true));
    return out;
  }

  // ---------------------------------------------------------------------------------------- queries
  heightAt(x, z) {
    const W = this.width, H = this.height, X = W + 1, h = this.heights;
    if (!(x >= 0)) x = 0; if (!(z >= 0)) z = 0; if (x > W) x = W; if (z > H) z = H;
    let i = Math.floor(x), j = Math.floor(z);
    if (i >= W) i = W - 1; if (j >= H) j = H - 1;
    const fx = x - i, fz = z - j, a = j * X + i;
    const ha = h[a], hb = h[a + 1], hc = h[a + X], hd = h[a + X + 1];
    return fx >= fz ? ha + (hb - ha) * fx + (hd - hb) * fz : ha + (hc - ha) * fz + (hd - hc) * fx;
  }

  /** Recompute vertex normals in [x0..x1] x [z0..z1] (vertex coords, clamped) from the heights. */
  recomputeNormals(x0 = 0, z0 = 0, x1 = this.width, z1 = this.height) {
    const W = this.width, H = this.height, X = W + 1, h = this.heights, n = this.normals;
    x0 = Math.max(0, x0 | 0); z0 = Math.max(0, z0 | 0); x1 = Math.min(W, Math.ceil(x1)); z1 = Math.min(H, Math.ceil(z1));
    for (let z = z0; z <= z1; z++) {
      for (let x = x0; x <= x1; x++) {
        const hl = h[z * X + Math.max(0, x - 1)], hr = h[z * X + Math.min(W, x + 1)];
        const hd = h[Math.max(0, z - 1) * X + x], hu = h[Math.min(H, z + 1) * X + x];
        const dx = (hr - hl) / ((x < W ? 1 : 0) + (x > 0 ? 1 : 0) || 1), dz = (hu - hd) / ((z < H ? 1 : 0) + (z > 0 ? 1 : 0) || 1);
        let nx = -dx, ny = 1, nz = -dz;
        const l = Math.hypot(nx, ny, nz);
        nx /= l; ny /= l; nz /= l;
        const o = (z * X + x) * 3;
        n[o] = nx; n[o + 1] = ny; n[o + 2] = nz;
      }
    }
  }

  /** Is the cell walkable in the .mac sense (inside and attribute not Blocked)? */
  walkable(x, z) {
    const cx = Math.floor(x), cz = Math.floor(z);
    if (cx < 0 || cz < 0 || cx >= this.width || cz >= this.height) return false;
    const t = DEFAULT_CELL_TABLE.get(this.attrs[cz * this.width + cx]);
    return !(t && t.blocked);
  }

  /** Resize (crop / extend) to a new size; content is kept at the origin corner. */
  resized(size) {
    const S = Number(size) | 0;
    if (!SIZES.includes(S) || S === this.width) return this;
    const d = new MapDoc(S, S);
    const Xo = this.width + 1, Xn = S + 1;
    for (let z = 0; z <= S; z++) for (let x = 0; x <= S; x++) {
      const zs = Math.min(z, this.height), xs = Math.min(x, this.width), si = zs * Xo + xs, di = z * Xn + x;
      d.heights[di] = this.heights[si]; d.vertexTypes[di] = this.vertexTypes[si];
      for (let k = 0; k < 4; k++) d.colors[di * 4 + k] = this.colors[si * 4 + k];
      for (let k = 0; k < 3; k++) d.normals[di * 3 + k] = this.normals[si * 3 + k];
    }
    for (let z = 0; z < S; z++) for (let x = 0; x < S; x++) {
      const di = z * S + x;
      if (x < this.width && z < this.height) {
        const si = z * this.width + x;
        d.cellVariants[di] = this.cellVariants[si]; d.attrs[di] = this.attrs[si]; d.holes[di] = this.holes[si];
        d.waterDef[di] = this.waterDef[si]; d.waterH[di] = this.waterH[si];
      } else d.cellVariants[di] = (x * 7 + z * 13) & 3;
    }
    d.waterDefs = this.waterDefs.slice();
    d.decals = this.decals.filter(e => e.cell % this.width < S && Math.floor(e.cell / this.width) < S)
      .map(e => ({ ...e, cell: Math.floor(e.cell / this.width) * S + (e.cell % this.width) }));
    d.objects = this.objects.filter(o => o.x < S && o.z < S).map(o => ({ ...o }));
    d.tileFolder = this.tileFolder; d.atlasNames = this.atlasNames.slice(); d.typeMaterials = this.typeMaterials.slice();
    d.meta = clone(this.meta);
    d.meta.size = S;
    const inside = (p) => p.x < S && p.z < S;
    d.meta.spawns = d.meta.spawns.filter(inside); d.meta.npcs = d.meta.npcs.filter(inside);
    d.meta.portals = d.meta.portals.filter(p => p.x0 < S && p.z0 < S);
    if (!inside(d.meta.start)) d.meta.start = { x: S / 2, z: S / 2, dirDeg: 0 };
    return d;
  }
}

function waterName(n) {
  const s = String(n || '').replace(/\\/g, '/');
  return s.slice(s.lastIndexOf('/') + 1) || DEFAULT_WATER;
}
function normFolder(f) {
  let s = String(f || '').replace(/\//g, '\\').replace(/^texture\\/i, '');
  if (!/^maptile\\/i.test(s)) s = 'MapTile\\' + s.replace(/^\\+/, '');
  if (!s.endsWith('\\')) s += '\\';
  return s;
}
export { normFolder };
const clone = (o) => JSON.parse(JSON.stringify(o));

// ------------------------------------------------------------------------------------------ meta
/** The non-terrain part of a custom map (JSON). */
export function defaultMeta(W = 256, H = W) {
  return {
    format: META_FORMAT, id: null, index: null, name: 'New Map', desc: '', author: '', created: 0, modified: 0,
    basedOn: null, size: W,
    start: { x: W / 2, z: H / 2, dirDeg: 0 },
    // monster spawns (MON_*.csv rows): {id, monsterIndex, x, z, respawnSec}
    spawns: [],
    // NPC placements (NPC_*.csv rows): {id, npcIndex, x, z, dirDeg, name?, jobs?:[[jobType, jobIndex]]}
    npcs: [],
    // walk-in portals: {id, name, x0, z0, x1, z1, object?, to: {map, custom?, x, z, dirDeg}}
    portals: [],
    env: {
      light: DEFAULT_LIGHT,      // map/<file> light keys the map starts from
      lightText: null,           // edited light file text (original map/light_*.txt format); null = use `light` as is
      envMap: 'water/skyCube=.dds',
      clipFar: 75, dayMinutes: 90, fixedHour: null,
      bgmMap: 150,               // play the BGM of this map index
      minLevel: 0, maxLevel: 0, returnScroll: 1,
    },
    minimap: null,               // PNG data URL (512 px top view, transposed like the client minimaps)
  };
}
export function mergeMeta(base, m) {
  const out = { ...base, ...(m || {}) };
  out.env = { ...base.env, ...(m?.env || {}) };
  for (const k of ['spawns', 'npcs', 'portals']) out[k] = Array.isArray(m?.[k]) ? m[k] : [];
  out.start = m?.start && Number.isFinite(Number(m.start.x)) ? m.start : base.start;
  return out;
}

// ------------------------------------------------------------------------------------------ writers
/**
 * Write a parseMap()-shaped object as an original .map file (version 20051216: patch-grouped water).
 * parseMap(writeMap(m)) reproduces every field (tools/test-mapbuilder.mjs).
 */
export function writeMap(m) {
  const W = m.width, H = m.height, X = W + 1, V = X * (H + 1), C = W * H;
  const w = new Writer(64 + V * 28 + C * 2 + 4096);
  w.u32(MAP_VERSION_V2); w.u32(W); w.u32(H);
  const atlases = m.atlasNames && m.atlasNames.length ? m.atlasNames : ['maptex_first.dds', 'maptex_second.dds'];
  w.u32(atlases.length); for (const a of atlases) w.str(a);
  w.typed(m.heights instanceof Float32Array ? m.heights : Float32Array.from(m.heights));
  // vertex colours: RGBA in memory -> D3DCOLOR bytes B,G,R,A
  const col = new Uint8Array(V * 4);
  for (let i = 0; i < V; i++) { col[i * 4] = m.colors[i * 4 + 2]; col[i * 4 + 1] = m.colors[i * 4 + 1]; col[i * 4 + 2] = m.colors[i * 4]; col[i * 4 + 3] = m.colors[i * 4 + 3]; }
  w.bytes(col);
  const types = new Uint32Array(V); for (let i = 0; i < V; i++) types[i] = m.vertexTypes[i] & 3;
  w.typed(types);
  w.typed(m.normals instanceof Float32Array ? m.normals : Float32Array.from(m.normals));
  w.typed(m.cellVariants instanceof Uint16Array ? m.cellVariants : Uint16Array.from(m.cellVariants));
  w.str(m.tileFolder || DEFAULT_TILE_FOLDER);
  // water: per entry, 16x16-cell patches keyed by the centre VERTEX index, cells grouped by level
  const water = m.water || [];
  w.u32(water.length);
  for (const e of water) {
    w.str(e.name);
    const patches = new Map();
    for (let j = 0; j < e.cells.length; j++) {
      const c = e.cells[j], col0 = c % W, row0 = Math.floor(c / W);
      const pc = Math.floor(col0 / 16) * 16 + 8, pr = Math.floor(row0 / 16) * 16 + 8;
      const key = pr * X + pc;
      let p = patches.get(key);
      if (!p) patches.set(key, (p = new Map()));
      const h = e.cellHeights[j];
      let lv = p.get(h);
      if (!lv) p.set(h, (lv = []));
      lv.push(c);
    }
    w.u32(patches.size);
    for (const [key, levels] of patches) {
      w.u32(key); w.u32(levels.size);
      for (const [h, cells] of levels) { w.f32(h); w.u32(cells.length); for (const c of cells) w.u32(c); }
    }
  }
  const decals = m.decals || [];
  w.u32(decals.length);
  for (const d of decals) {
    w.str(d.name);
    w.u32(d.count);
    for (let j = 0; j < d.count; j++) { w.u32(d.cells[j]); w.u32(d.sizes[j]); w.u16(d.rotations[j]); }
    w.u32(d.unkMaterial | 0);
  }
  const t = m.unkTypeMaterials || [0, 0, 0, 0];
  for (let k = 0; k < 4; k++) w.u32(t[k] | 0);
  return w.done();
}

/** Write a .mol object list: u32 count, per object f32 x z qx qy qz qw y scale, u32 nameLen, name. */
export function writeMol(objects) {
  const w = new Writer(4 + objects.length * 80);
  const list = objects.filter(o => o && o.name && Number.isFinite(o.x) && Number.isFinite(o.z));
  w.u32(list.length);
  for (const o of list) {
    w.f32(o.x); w.f32(o.z);
    w.f32(o.qx ?? 0); w.f32(o.qy ?? 0); w.f32(o.qz ?? 0); w.f32(o.qw ?? 1);
    w.f32(o.y ?? 0); w.f32(o.scale ?? 1);
    w.str(String(o.name).replace(/\//g, '\\'));
  }
  return w.done();
}

/** Write a .mac attribute grid: u32 width, u32 height, u16 attribute per cell (row-major, row = Z). */
export function writeMac(W, H, attrs) {
  const w = new Writer(8 + W * H * 2);
  w.u32(W); w.u32(H);
  w.typed(attrs instanceof Uint16Array ? attrs : Uint16Array.from(attrs));
  return w.done();
}

// ------------------------------------------------------------------------------------------ quaternions (FILE frame)
/** D3DX quaternion of yaw (radians about +Y, FILE frame) - the rotation the client's tools write for "rotate Y". */
export function yawQuat(yaw) { return { qx: 0, qy: Math.sin(yaw / 2), qz: 0, qw: Math.cos(yaw / 2) }; }
/** Yaw of a stored quaternion (same convention as yawQuat). */
export function quatYaw(o) { return Math.atan2(2 * (o.qw * o.qy + o.qx * o.qz), 1 - 2 * (o.qy * o.qy + o.qx * o.qx)); }
