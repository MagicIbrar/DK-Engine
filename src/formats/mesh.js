// Dekaron .mesh parser (all four on-disk versions). Pure function, no three.js / Node APIs.
// Full format description: docs/formats/mesh.md
//
// File layout (all little-endian):
//   0x00 u32 version            0x20030820 | 0x20031117 | 0x20060303 | 0x20191130
//   0x04 u32[3] unk (always 0)
//   0x10 4 x {u32 offset, u32 size}   section table. Exact for 2003 versions, stale in 2006/2019
//                                     (sizes computed with a smaller vertex) -> we parse sequentially.
//   0x30 char[64] source path (EUC-KR, NUL terminated; also the XOR key table of v2019 strings)
//   0x70 section 0  helpers  (named collision / attachment meshes: "EXBOX", "ground", "picking", "weaponR"...)
//        section 1  lines    (named polylines: "weaponline", "traceline", "effectline" ... weapon trails)
//        section 2  unk      (count x 12 bytes, always zero in the corpus)
//        section 3  meshes   (renderable meshes; one tpack texture slot per mesh)
//   v2019 ("0x20191130") is an obfuscated re-save of the 2006 layout: the three section counts are
//   hoisted to 0x70 (order c2, c1, c0), fields inside records are permuted and names are XORed.
//
// Coordinates are returned in the FILE frame (Direct3D, left-handed, Y up, clockwise front faces).
// Pass { rightHanded: true } (or call meshToRightHanded) to get the three.js frame: z -> -z for
// positions/normals/tangents/bboxes and triangle winding swapped (i0,i1,i2) -> (i0,i2,i1).
// Defaults repair data defects: NaN normals/positions/stale bboxes (repair) and the 1,783 meshes whose normals
// point inward (fixNormals). Skinning follows the game's HLSL (data/binary/boneanimation.fx): stored weights as-is;
// vertices of influences-0 subsets (and all-zero-weight vertices) stay at the model root -> virtual bone
// skin.staticIndex = bonePalette.length (the engine adds an identity root bone).

import { BinReader, decodeText } from './binreader.js';

export const MESH_VERSION = Object.freeze({
  V2003_08: 0x20030820, // 6 files, 64-byte vertex, 3 bone influences
  V2003_11: 0x20031117, // main format, 56-byte vertex, 2 bone influences
  V2006: 0x20060303,    // 72-byte vertex (adds tangent + handedness)
  V2019: 0x20191130,    // same data as 2006, obfuscated (field order + XOR-ed strings)
});

/** Per-version vertex layout. Offsets in bytes inside one vertex. */
export const VERTEX_LAYOUTS = Object.freeze({
  [MESH_VERSION.V2003_08]: { stride: 64, tangent: -1, uv0: 24, uv1: 32, bones: 40, weights: 52, influences: 3 },
  [MESH_VERSION.V2003_11]: { stride: 56, tangent: -1, uv0: 24, uv1: 32, bones: 40, weights: 48, influences: 2 },
  [MESH_VERSION.V2006]:    { stride: 72, tangent: 24, uv0: 40, uv1: 48, bones: 56, weights: 64, influences: 2 },
  [MESH_VERSION.V2019]:    { stride: 72, tangent: 24, uv0: 40, uv1: 48, bones: 56, weights: 64, influences: 2 },
});

export const HELPER_VERTEX_STRIDE = 40; // pos3 nrm3 bone0 bone1 weight0 weight1 (all f32)
export const LINE_POINT_STRIDE = 28;    // pos3 + 4 f32 (bone0 bone1 weight0 weight1, same as helpers)
export const PRIMITIVE = Object.freeze({ TRIANGLE_LIST: 0, TRIANGLE_STRIP: 1 });

export class MeshFormatError extends Error {}

const MAX_STR = 4096;

function readBytesStr(r) {
  const n = r.u32();
  if (n > MAX_STR) throw new MeshFormatError(`string length ${n} at 0x${(r.pos - 4).toString(16)}`);
  return r.bytes(n);
}
function bytesToStr(b, key = 0) {
  let end = b.length;
  const out = new Uint8Array(b.length);
  for (let i = 0; i < b.length; i++) out[i] = b[i] ^ key;
  for (let i = 0; i < out.length; i++) if (out[i] === 0) { end = i; break; }
  return decodeText(out.subarray(0, end), true);
}

/** D3D triangle strip -> triangle list (drops degenerate triangles, keeps D3D winding parity). */
export function stripToList(strip, out = [], base = 0) {
  for (let k = 0; k + 2 < strip.length; k++) {
    let a = strip[k], b = strip[k + 1];
    const c = strip[k + 2];
    if (a === b || b === c || a === c) continue;
    if (k & 1) { const t = a; a = b; b = t; }
    out.push(a + base, b + base, c + base);
  }
  return out;
}

function readVertices(r, count, version, meshOut, paletteSize) {
  const L = VERTEX_LAYOUTS[version];
  const stride = L.stride;
  r.ensure(count * stride);
  const dv = r.dv, p0 = r.pos;
  const positions = new Float32Array(count * 3);
  const normals = new Float32Array(count * 3);
  const uv0 = new Float32Array(count * 2);
  const uv1 = new Float32Array(count * 2);
  const tangents = L.tangent >= 0 ? new Float32Array(count * 4) : null;
  const rawBones = new Float32Array(count * L.influences);
  const rawWeights = new Float32Array(count * L.influences);
  for (let i = 0; i < count; i++) {
    const o = p0 + i * stride;
    for (let k = 0; k < 3; k++) {
      positions[i * 3 + k] = dv.getFloat32(o + k * 4, true);
      normals[i * 3 + k] = dv.getFloat32(o + 12 + k * 4, true);
    }
    if (tangents) for (let k = 0; k < 4; k++) tangents[i * 4 + k] = dv.getFloat32(o + L.tangent + k * 4, true);
    uv0[i * 2] = dv.getFloat32(o + L.uv0, true); uv0[i * 2 + 1] = dv.getFloat32(o + L.uv0 + 4, true);
    uv1[i * 2] = dv.getFloat32(o + L.uv1, true); uv1[i * 2 + 1] = dv.getFloat32(o + L.uv1 + 4, true);
    for (let k = 0; k < L.influences; k++) {
      rawBones[i * L.influences + k] = dv.getFloat32(o + L.bones + k * 4, true);
      rawWeights[i * L.influences + k] = dv.getFloat32(o + L.weights + k * 4, true);
    }
  }
  r.pos = p0 + count * stride;
  Object.assign(meshOut, { positions, normals, uv0, uv1 });
  if (tangents) meshOut.tangents = tangents;
  meshOut._rawBones = rawBones; meshOut._rawWeights = rawWeights; meshOut._influences = L.influences;
}

/**
 * Convert the float bone-index/weight tuples to 4-wide three.js skin attributes, exactly as the game's
 * vertex shaders do (data/binary/boneanimation.fx and siblings, plain HLSL):
 *   - subsets with influences > 0 are drawn with pass p1 `AnimateBone2`: pos = v*M[b0]*w0 + v*M[b1]*w1, i.e. the
 *     STORED weights (they sum to 1 for every weighted vertex of the corpus; normalised here for safety);
 *   - subsets with influences 0 are drawn with pass p0 `vsBone0*`: pos = v * modelViewProj - no bone matrix at all,
 *     the vertex stays in model space (the object/root transform), exactly like unassigned vertices in 3ds Max.
 *     These "static" vertices are bound with weight 1 to the VIRTUAL bone index `staticIndex` = palette.length:
 *     the engine adds one extra bone with an identity inverse-bind that stays at the model root.
 *   - vertices with no positive stored weight that are also referenced by a blended subset (401: 397 raw
 *     (b=0,0 w=0,0) in 26 meshes + 4 NaN) would collapse to the model origin in the game's p1 pass; they are bound
 *     to the static root as well (the p0 triangles that share them stay intact).
 * NOTE: an earlier revision bound static vertices to palette bone 0. Its evidence (seam vertices driven by palette 0)
 * was circular: those seam vertices are exactly the zero-weight vertices above, whose palette-0 binding came from
 * this function's own former "last weight = 1 - sum" rule. See docs/formats/mesh.md "Skinning".
 * @param vinf Int8Array per vertex: max influences of the subsets that reference it (-1 = unreferenced)
 */
function buildSkin(m, palette, vinf) {
  const n = m.positions.length / 3, inf = m._influences;
  const W = m._rawWeights, B = m._rawBones;
  const boneIndices = new Uint16Array(n * 4), boneWeights = new Float32Array(n * 4);
  const staticIndex = palette.length; // virtual root bone (identity bind) followed by influences-0 vertices
  let staticVertexCount = 0;
  const clampIdx = (b) => { const r = Math.round(b); return r >= 0 && r < palette.length ? r : 0; };
  for (let i = 0; i < n; i++) {
    let sum = 0;
    for (let k = 0; k < inf; k++) { const w = W[i * inf + k]; if (w > 0) sum += w; }
    // vinf 0 = referenced only by influences-0 subsets (p0 pass); sum 0 = no stored weight at all
    if (vinf[i] === 0 || !(sum > 0)) { boneIndices[i * 4] = staticIndex; boneWeights[i * 4] = 1; staticVertexCount++; continue; }
    let o = 0;
    for (let k = 0; k < inf && o < 4; k++) {
      const w = W[i * inf + k];
      if (!(w > 0)) continue;
      boneIndices[i * 4 + o] = clampIdx(B[i * inf + k]);
      boneWeights[i * 4 + o] = w / sum;
      o++;
    }
  }
  return { boneIndices, boneWeights, bonePalette: palette, influences: inf, staticIndex, staticVertexCount };
}

function readHelperVerts(r, n) {
  r.ensure(n * HELPER_VERTEX_STRIDE);
  const positions = new Float32Array(n * 3), normals = new Float32Array(n * 3);
  const skinRaw = new Float32Array(n * 4);
  const dv = r.dv, p0 = r.pos;
  for (let i = 0; i < n; i++) {
    const o = p0 + i * HELPER_VERTEX_STRIDE;
    for (let k = 0; k < 3; k++) {
      positions[i * 3 + k] = dv.getFloat32(o + k * 4, true);
      normals[i * 3 + k] = dv.getFloat32(o + 12 + k * 4, true);
    }
    for (let k = 0; k < 4; k++) skinRaw[i * 4 + k] = dv.getFloat32(o + 24 + k * 4, true);
  }
  r.pos = p0 + n * HELPER_VERTEX_STRIDE;
  return { positions, normals, skinRaw };
}

function helperSkin(h) {
  const n = h.positions.length / 3;
  if (!h.bonePalette.length) return null;
  const boneIndices = new Uint16Array(n * 4), boneWeights = new Float32Array(n * 4);
  const staticIndex = h.bonePalette.length; // same virtual root bone as mesh skins
  let staticVertexCount = 0;
  for (let i = 0; i < n; i++) {
    let o = 0, sum = 0;
    for (let k = 0; k < 2; k++) { const w = h.skinRaw[i * 4 + 2 + k]; if (w > 0) sum += w; }
    for (let k = 0; k < 2 && sum > 0; k++) {
      const w = h.skinRaw[i * 4 + 2 + k], b = Math.round(h.skinRaw[i * 4 + k]);
      if (!(w > 0)) continue;
      boneIndices[i * 4 + o] = b >= 0 && b < h.bonePalette.length ? b : 0;
      boneWeights[i * 4 + o] = w / sum; o++;
    }
    // unweighted vertex (74 in the corpus): same rule as influences-0 mesh vertices -> static root
    if (!o) { boneIndices[i * 4] = staticIndex; boneWeights[i * 4] = 1; staticVertexCount++; }
  }
  return { boneIndices, boneWeights, staticIndex, staticVertexCount };
}

const bboxOf = (a) => ({ min: [a[0], a[1], a[2]], max: [a[3], a[4], a[5]] });

/**
 * A handful of exported meshes contain NaN positions/normals (degenerate triangles in the source art).
 * Repair in place so the data is GPU-safe; counts are reported in mesh.repaired (all zero for clean files).
 *  - non-finite position component -> 0
 *  - non-finite or zero-length normal -> area-weighted face normal of its triangles (else 0,1,0)
 *  - non-finite uv -> 0, non-finite tangent -> (1,0,0,1)
 *  - stored bbox with non-finite values, or not containing the vertices -> recomputed from the positions
 */
function repairMesh(m) {
  const rep = { positions: 0, normals: 0, uvs: 0, tangents: 0, bbox: 0 };
  const P = m.positions, N = m.normals, n = P.length / 3;
  for (let i = 0; i < P.length; i++) if (!Number.isFinite(P[i])) { P[i] = 0; rep.positions++; }
  for (const U of [m.uv0, m.uv1]) for (let i = 0; i < U.length; i++) if (!Number.isFinite(U[i])) { U[i] = 0; rep.uvs++; }
  if (m.tangents) {
    const T = m.tangents;
    for (let i = 0; i < n; i++) {
      if (![0, 1, 2, 3].every((k) => Number.isFinite(T[i * 4 + k]))) { T.set([1, 0, 0, 1], i * 4); rep.tangents++; }
    }
  }
  let badList = null;
  for (let i = 0; i < n; i++) {
    const x = N[i * 3], y = N[i * 3 + 1], z = N[i * 3 + 2];
    if (!(Number.isFinite(x) && Number.isFinite(y) && Number.isFinite(z)) || x * x + y * y + z * z < 1e-12) (badList ||= []).push(i);
  }
  if (badList) {
    const acc = new Float64Array(n * 3), I = m.indices;
    const need = new Uint8Array(n); for (const i of badList) need[i] = 1;
    for (let t = 0; t + 2 < I.length; t += 3) {
      const a = I[t], b = I[t + 1], c = I[t + 2];
      if (!(need[a] | need[b] | need[c])) continue;
      const ux = P[b * 3] - P[a * 3], uy = P[b * 3 + 1] - P[a * 3 + 1], uz = P[b * 3 + 2] - P[a * 3 + 2];
      const vx = P[c * 3] - P[a * 3], vy = P[c * 3 + 1] - P[a * 3 + 1], vz = P[c * 3 + 2] - P[a * 3 + 2];
      const cx = uy * vz - uz * vy, cy = uz * vx - ux * vz, cz = ux * vy - uy * vx;
      for (const v of [a, b, c]) if (need[v]) { acc[v * 3] += cx; acc[v * 3 + 1] += cy; acc[v * 3 + 2] += cz; }
    }
    for (const i of badList) {
      const l = Math.hypot(acc[i * 3], acc[i * 3 + 1], acc[i * 3 + 2]);
      if (l > 0) { N[i * 3] = acc[i * 3] / l; N[i * 3 + 1] = acc[i * 3 + 1] / l; N[i * 3 + 2] = acc[i * 3 + 2] / l; }
      else { N[i * 3] = 0; N[i * 3 + 1] = 1; N[i * 3 + 2] = 0; }
      rep.normals++;
    }
  }
  // stored bbox: exact vertex extents in 57,241 / 57,251 meshes; 1 is NaN and 10 are stale (do not contain the
  // vertices, e.g. effect/cutscene/cut_npc_victoria) -> recompute those from the positions (stored kept in bboxStored)
  const bb = m.bbox;
  const mn = [Infinity, Infinity, Infinity], mx = [-Infinity, -Infinity, -Infinity];
  for (let i = 0; i < n; i++) for (let k = 0; k < 3; k++) { const v = P[i * 3 + k]; if (v < mn[k]) mn[k] = v; if (v > mx[k]) mx[k] = v; }
  const finite = [...bb.min, ...bb.max].every(Number.isFinite);
  let stale = false;
  if (finite && n) {
    const tol = 1e-3 * (1 + Math.max(...mn.map(Math.abs), ...mx.map(Math.abs)));
    for (let k = 0; k < 3; k++) if (mn[k] < bb.min[k] - tol || mx[k] > bb.max[k] + tol) stale = true;
  }
  if (!finite || stale) {
    m.bboxStored = bb; m.bbox = n ? { min: mn, max: mx } : { min: [0, 0, 0], max: [0, 0, 0] }; rep.bbox = 1;
  }
  m.repaired = rep;
}

/**
 * Parse a .mesh file.
 * @param {ArrayBuffer|Uint8Array|Buffer} buf
 * @param {{rightHanded?: boolean, keepStrips?: boolean, repair?: boolean, fixNormals?: boolean, fixWinding?: boolean}} [opts]
 *   rightHanded  convert to the three.js frame (see meshToRightHanded)            default false (FILE frame)
 *   keepStrips   also return mesh.stripIndices (raw D3D index data, groups[].rawStart/rawCount) default false
 *   repair       fix NaN positions / NaN-or-zero normals / NaN or stale bboxes (counts in mesh.repaired) default true
 *   fixNormals   meshes whose triangles ALL disagree with their normals (raw windingConsistency < 0.1, 1,783 meshes):
 *                negate normals + tangent w, keep the winding (mesh.normalsFlipped). Right for ~97% of them: their
 *                winding is outward, the normals point inward.                                  default true
 *   fixWinding   NOT recommended: swap the winding of meshes that are still inverted (< 0.1) after fixNormals.
 *                (Before the fix above this was the suggested repair; it turns most inverted meshes inside out.) default false
 * @returns {{
 *   version:number, sourcePath:string, unkHeader:number[], sectionTable:{offset:number,size:number}[],
 *   obfuscated:boolean, sectionCounts:number[4], unkPreCounts:number[]|null, xorKeys:object|null,
 *   helpers: Array<{name, bbox, positions, normals, indices(triangle list), bonePalette, skinRaw(b0,b1,w0,w1), skin?}>,
 *   lines: Array<{name, strips:Array<{positions, skinRaw(b0,b1,w0,w1)}>, bonePalette}>,
 *   unkSection2: Float32Array,
 *   meshes: Array<{ name:string, index:number, material:number (= tpack slot), vertexCount:number,
 *     bbox:{min:number[],max:number[]},
 *     positions:Float32Array, normals:Float32Array, tangents?:Float32Array(n*4), uv0:Float32Array, uv1:Float32Array,
 *     indices:Uint16Array|Uint32Array (triangle list), groups:Array<{start:number,count:number,material:number,
 *       influences:number,primitive:number,minIndex:number,numVertices:number,rawStart:number,rawCount:number}>,
 *     skin?:{boneIndices:Uint16Array(n*4),boneWeights:Float32Array(n*4),bonePalette:string[],influences:number,
 *            staticIndex:number (= bonePalette.length: virtual identity root bone used by influences-0 / unweighted
 *            vertices; add it to the skeleton when staticVertexCount > 0), staticVertexCount:number},
 *     bonePalette:string[], rawSkin:{bones:Float32Array,weights:Float32Array,influences:number},
 *     windingConsistency:number (after fixNormals/repair), windingConsistencyRaw:number, normalsFlipped:boolean,
 *     repaired:object, stripIndices?:Uint16Array (raw FILE-frame D3D strips, never converted) }>,
 *   bbox: {min:number[],max:number[]}|null, frame:'file'|'three', bytesRead:number, trailingBytes:number
 * }}
 */
export function parseMesh(buf, opts = {}) {
  const r = new BinReader(buf);
  if (r.length < 0x74) throw new MeshFormatError(`file too small (${r.length} bytes)`);
  const version = r.u32();
  const layout = VERTEX_LAYOUTS[version];
  if (!layout) throw new MeshFormatError(`unknown mesh version 0x${version.toString(16)}`);
  const obf = version === MESH_VERSION.V2019;
  const unkHeader = [r.u32(), r.u32(), r.u32()];
  const sectionTable = [];
  for (let i = 0; i < 4; i++) sectionTable.push({ offset: r.u32(), size: r.u32() });
  const pathBytes = r.bytes(64).slice();
  let pe = pathBytes.indexOf(0); if (pe < 0) pe = 64;
  const sourcePath = decodeText(pathBytes.subarray(0, pe), true);
  // v2019 XOR key for a section = pathBytes[count of another section] (see mesh.md).
  const keyAt = (i) => (obf ? pathBytes[i & 63] : 0);

  r.seek(0x70);
  let c0, c1, c2, cPre = null;
  if (obf) { c2 = r.u32(); c1 = r.u32(); c0 = r.u32(); cPre = [c2, c1, c0]; }
  else c0 = r.u32();

  // ---- section 0: helpers -------------------------------------------------------------
  const helperRaw = [];
  for (let i = 0; i < c0; i++) {
    let name, bb, verts, idx, nb;
    if (obf) {
      const ic = r.u32(), vc = r.u32();
      name = readBytesStr(r);
      const a = [r.f32(), r.f32(), r.f32(), r.f32()]; // minX minZ maxY maxZ
      verts = readHelperVerts(r, vc);
      const minY = r.f32(); nb = r.u32(); const maxX = r.f32();
      bb = [a[0], minY, a[1], maxX, a[2], a[3]];
      idx = r.u16array(ic);
    } else {
      name = readBytesStr(r);
      bb = [r.f32(), r.f32(), r.f32(), r.f32(), r.f32(), r.f32()];
      const vc = r.u32(); verts = readHelperVerts(r, vc);
      const ic = r.u32(); idx = r.u16array(ic);
      nb = r.u32();
    }
    const bones = [];
    for (let k = 0; k < nb; k++) bones.push(readBytesStr(r));
    helperRaw.push({ name, bb, verts, idx, bones });
  }
  // ---- section 1: lines -----------------------------------------------------------------
  const lineRaw = [];
  if (!obf) c1 = r.u32();
  for (let i = 0; i < c1; i++) {
    const name = readBytesStr(r);
    let nb = 0, nl;
    if (obf) { nb = r.u32(); nl = r.u32(); } else nl = r.u32();
    const strips = [];
    for (let s = 0; s < nl; s++) {
      const np = r.u32();
      r.ensure(np * LINE_POINT_STRIDE);
      const positions = new Float32Array(np * 3), unk = new Float32Array(np * 4);
      for (let k = 0; k < np; k++) {
        for (let j = 0; j < 3; j++) positions[k * 3 + j] = r.f32();
        for (let j = 0; j < 4; j++) unk[k * 4 + j] = r.f32();
      }
      strips.push({ positions, skinRaw: unk });
    }
    if (!obf) nb = r.u32();
    const bones = [];
    for (let k = 0; k < nb; k++) bones.push(readBytesStr(r));
    lineRaw.push({ name, strips, bones });
  }
  // ---- section 2: unknown 12-byte records (always zero) ---------------------------------
  if (!obf) c2 = r.u32();
  const unkSection2 = r.f32array(c2 * 3);

  // ---- section 3: meshes -----------------------------------------------------------------
  const nMesh = r.u32();
  const meshes = [];
  const kHelper = keyAt(nMesh), kLine = keyAt(c0), kMesh = keyAt(c1);
  for (let mi = 0; mi < nMesh; mi++) {
    const b6 = [r.f32(), r.f32(), r.f32(), r.f32(), r.f32(), r.f32()];
    // v2019 stores (minZ, minX, minY, maxX, maxZ, maxY)
    const bb = obf ? [b6[1], b6[2], b6[0], b6[3], b6[5], b6[4]] : b6;
    const nSub = r.u32();
    const subs = [];
    for (let s = 0; s < nSub; s++) {
      let influences, primitive, minIndex, numVertices, ic;
      if (obf) { ic = r.u32(); influences = r.u32(); primitive = r.u32(); minIndex = r.u32(); numVertices = r.u32(); }
      else { influences = r.u32(); primitive = r.u32(); minIndex = r.u32(); numVertices = r.u32(); ic = r.u32(); }
      const idx = r.u16array(ic);
      subs.push({ influences, primitive, minIndex, numVertices, idx });
    }
    const vc = r.u32();
    const m = { name: `mesh${mi}`, index: mi, bbox: bboxOf(bb), vertexCount: vc };
    readVertices(r, vc, version, m, 0);
    let nb, material;
    if (obf) { nb = r.u32(); material = r.u32(); }
    else nb = r.u32();
    const palette = [];
    for (let k = 0; k < nb; k++) palette.push(readBytesStr(r));
    if (!obf) material = r.u32();
    m._paletteRaw = palette; m.material = material;
    const vinf = new Int8Array(vc).fill(-1);
    for (const s of subs) for (const v of s.idx) if (v < vc && s.influences > vinf[v]) vinf[v] = s.influences;
    m._vinf = vinf;
    // index buffer: triangle list, one group per subset
    const tri = []; const groups = []; let rawStart = 0; const stripParts = [];
    for (const s of subs) {
      const start = tri.length;
      if (s.primitive === PRIMITIVE.TRIANGLE_STRIP) stripToList(s.idx, tri);
      else for (let k = 0; k + 2 < s.idx.length; k += 3) tri.push(s.idx[k], s.idx[k + 1], s.idx[k + 2]);
      groups.push({ start, count: tri.length - start, material, influences: s.influences, primitive: s.primitive,
        minIndex: s.minIndex, numVertices: s.numVertices, rawStart, rawCount: s.idx.length });
      rawStart += s.idx.length; stripParts.push(s.idx);
    }
    m.indices = vc > 0xffff ? Uint32Array.from(tri) : Uint16Array.from(tri);
    m.groups = groups;
    // Fully inverted meshes (~3%): the triangle winding is right (outward CW fronts, which is what D3D culled with)
    // and the NORMALS point inward in 1,093 of the 1,130 decidable cases -> flip normals (+ tangent w), keep winding.
    // Decided on the raw data (NaN normals are ignored) BEFORE repair, so repaired normals are not flipped twice.
    m.windingConsistencyRaw = windingConsistency(m);
    m.normalsFlipped = false;
    if (opts.fixNormals !== false && m.windingConsistencyRaw < 0.1) { flipNormals(m); m.normalsFlipped = true; }
    if (opts.repair !== false) repairMesh(m); else m.repaired = { positions: 0, normals: 0, uvs: 0, tangents: 0, bbox: 0 };
    m.windingConsistency = windingConsistency(m);
    if (opts.fixWinding && m.windingConsistency < 0.1) { swapWinding(m.indices); m.windingFlipped = true; m.windingConsistency = 1 - m.windingConsistency; }
    if (opts.keepStrips) {
      const all = new Uint16Array(rawStart); let o = 0;
      for (const p of stripParts) { all.set(p, o); o += p.length; }
      m.stripIndices = all;
    }
    meshes.push(m);
  }
  const bytesRead = r.pos;

  // ---- decode names / skins now that every section key is known ------------------------
  const helpers = helperRaw.map((h) => {
    const bonePalette = h.bones.map((b) => bytesToStr(b, kHelper));
    const out = {
      name: bytesToStr(h.name, kHelper), bbox: bboxOf(h.bb), positions: h.verts.positions, normals: h.verts.normals,
      indices: h.idx, bonePalette, skinRaw: h.verts.skinRaw,
    };
    const sk = helperSkin({ positions: out.positions, skinRaw: out.skinRaw, bonePalette });
    if (sk) out.skin = sk;
    return out;
  });
  const lines = lineRaw.map((l) => ({
    name: bytesToStr(l.name, kLine), strips: l.strips, bonePalette: l.bones.map((b) => bytesToStr(b, kLine)),
  }));
  let gmin = [Infinity, Infinity, Infinity], gmax = [-Infinity, -Infinity, -Infinity];
  for (const m of meshes) {
    m.bonePalette = m._paletteRaw.map((b) => bytesToStr(b, kMesh));
    if (m.bonePalette.length) m.skin = buildSkin(m, m.bonePalette, m._vinf);
    m.rawSkin = { bones: m._rawBones, weights: m._rawWeights, influences: m._influences };
    delete m._paletteRaw; delete m._rawBones; delete m._rawWeights; delete m._influences; delete m._vinf;
    for (let k = 0; k < 3; k++) { gmin[k] = Math.min(gmin[k], m.bbox.min[k]); gmax[k] = Math.max(gmax[k], m.bbox.max[k]); }
  }
  const out = {
    version, sourcePath, unkHeader, sectionTable, obfuscated: obf, sectionCounts: [c0, c1, c2, nMesh],
    unkPreCounts: cPre, xorKeys: obf ? { helpers: kHelper, lines: kLine, meshes: kMesh } : null,
    helpers, lines, unkSection2, meshes,
    bbox: meshes.length ? { min: gmin, max: gmax } : null,
    frame: 'file', bytesRead, trailingBytes: r.length - bytesRead,
  };
  return opts.rightHanded ? meshToRightHanded(out) : out;
}

/**
 * Fraction of triangles whose geometric normal (v1-v0)x(v2-v0) agrees with the averaged vertex normal,
 * measured in the FILE frame (1 = every triangle is a D3D clockwise front face). 98.4% of all raw triangles
 * agree; 1,783 meshes (~3%, mostly bricks/buildings/effects) are fully inverted (< 0.1). For ~97% of the
 * decidable ones the winding is outward and the normals inward, so parseMesh flips their normals by default
 * (opts.fixNormals) -> 99.5% agree. The value is unchanged by meshToRightHanded.
 */
export function windingConsistency(m) {
  const P = m.positions, N = m.normals, I = m.indices;
  let pos = 0, neg = 0;
  for (let t = 0; t + 2 < I.length; t += 3) {
    const a = I[t] * 3, b = I[t + 1] * 3, c = I[t + 2] * 3;
    const ux = P[b] - P[a], uy = P[b + 1] - P[a + 1], uz = P[b + 2] - P[a + 2];
    const vx = P[c] - P[a], vy = P[c + 1] - P[a + 1], vz = P[c + 2] - P[a + 2];
    const d = (uy * vz - uz * vy) * (N[a] + N[b] + N[c]) + (uz * vx - ux * vz) * (N[a + 1] + N[b + 1] + N[c + 1])
      + (ux * vy - uy * vx) * (N[a + 2] + N[b + 2] + N[c + 2]);
    if (d > 0) pos++; else if (d < 0) neg++;
  }
  return pos + neg ? pos / (pos + neg) : 1;
}
function swapWinding(ix) { for (let i = 0; i + 2 < ix.length; i += 3) { const t = ix[i + 1]; ix[i + 1] = ix[i + 2]; ix[i + 2] = t; } }
/** Negate every normal and the tangent handedness w (bitangent = w * cross(N, T) keeps pointing along +v). */
function flipNormals(m) {
  const N = m.normals; for (let i = 0; i < N.length; i++) N[i] = -N[i];
  if (m.tangents) for (let i = 3; i < m.tangents.length; i += 4) m.tangents[i] = -m.tangents[i];
}

function flipZ3(a) { if (a) for (let i = 2; i < a.length; i += 3) a[i] = -a[i]; }
function flipBox(b) { if (!b) return b; return { min: [b.min[0], b.min[1], -b.max[2]], max: [b.max[0], b.max[1], -b.min[2]] }; }

/**
 * Convert a parsed mesh (FILE frame, D3D left-handed) to the three.js frame IN PLACE:
 * mirror Z (positions, normals, tangent xyz, helper/line points, bboxes) and swap triangle winding.
 * Tangent w (handedness) is negated as well because mirroring flips the bitangent.
 */
export function meshToRightHanded(p) {
  if (p.frame === 'three') return p;
  for (const m of p.meshes) {
    flipZ3(m.positions); flipZ3(m.normals);
    if (m.tangents) for (let i = 0; i < m.tangents.length; i += 4) { m.tangents[i + 2] = -m.tangents[i + 2]; m.tangents[i + 3] = -m.tangents[i + 3]; }
    const ix = m.indices;
    for (let i = 0; i + 2 < ix.length; i += 3) { const t = ix[i + 1]; ix[i + 1] = ix[i + 2]; ix[i + 2] = t; }
    m.bbox = flipBox(m.bbox);
    if (m.bboxStored) m.bboxStored = flipBox(m.bboxStored);
    // NOTE: m.stripIndices (keepStrips) stay raw D3D strips with FILE-frame winding.
  }
  for (const h of p.helpers) {
    flipZ3(h.positions); flipZ3(h.normals); h.bbox = flipBox(h.bbox);
    const ix = h.indices;
    for (let i = 0; i + 2 < ix.length; i += 3) { const t = ix[i + 1]; ix[i + 1] = ix[i + 2]; ix[i + 2] = t; }
  }
  for (const l of p.lines) for (const s of l.strips) flipZ3(s.positions);
  p.bbox = flipBox(p.bbox);
  p.frame = 'three';
  return p;
}

/** Quick header probe without parsing geometry. */
export function peekMeshVersion(buf) {
  const r = new BinReader(buf);
  return r.length >= 4 ? r.u32() : 0;
}
