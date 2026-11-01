// Dekaron .skel - bone hierarchy + bind pose (skel/<category>/*.skel, ~9,100 files).
//
// Pure parser: no three.js, no Node APIs. See docs/formats/skel.md for the full description.
//
// Header (0x60 = 96 bytes, little-endian):
//   v0x20030820:  u32 version, u32 boneCount, u32 headerSize(=96), u32 dataSize, u8[16] zero, char[64] sourcePath
//   other:        u32 version, u32 rootCount, u32 boneCount, u32 headerSize(=96), u32 dataSize, u8[12] zero, char[64] sourcePath
//   dataSize == fileSize - headerSize (6 v0x20191130 files carry a stale value; the records still parse exactly).
// Bone records, depth-first PRE-ORDER (parents always precede children), boneCount times:
//   lpstr name                 (u32 len + bytes, no NUL)
//   lpstr alias                (only v0x20040729 / v0x20191130; usually == name, sometimes a part tag like "body_u")
//   24 dwords  (plain order; v0x20191130 stores the same 24 dwords shuffled, see RECORD_PERM_2019):
//     f32 pos[3]               local translation relative to parent (file frame, D3D left-handed, Y up)
//     f32 rot[4]               local rotation quaternion (x, y, z, w), D3DX convention
//     f32 scale[16]            4x4 row-major "stretch" matrix: 3x3 scale/shear in the upper-left, last row/col = 0,0,0,1
//     u32 childCount           number of direct children (following records, pre-order)
// Local bone matrix (D3D row-vector convention, v' = v * M):  L = SCALE * R(rot) * T(pos)
// World (model space) bind matrix:                              W = L * W(parent)
// Inverse bind matrix:                                          invBind = inverse(W)
// v0x20191130 ("2019 re-export") obfuscation: the 24 record dwords are permuted and both names are XOR'ed with a
// single byte taken from the 64-byte sourcePath field (NUL padding included, index & 63):
//   aliasKey = pathBytes[rootCount & 63]                 (':' = 0x3A for "C:\..." paths)
//   nameKey  = pathBytes[(dataSize + headerSize) & 63]   (the declared file size; verified on all 1,571 files)
// A key byte of 0 (index past the end of the path string) means the names are stored in clear.

import { BinReader, toArrayBuffer, decodeText } from './binreader.js';

export const SKEL_V2003 = 0x20030820;
export const SKEL_V2004A = 0x20040303;
export const SKEL_V2004 = 0x20040729;
export const SKEL_V2019 = 0x20191130;
export const SKEL_VERSIONS = [SKEL_V2003, SKEL_V2004A, SKEL_V2004, SKEL_V2019];
export const SKEL_HEADER_SIZE = 96;
export const SKEL_RECORD_DWORDS = 24;

/**
 * v0x20191130 record permutation: stored dword i holds plain dword RECORD_PERM_2019[i].
 * Plain dword indices: 0..2 pos, 3..6 quat xyzw, 7..22 scale matrix m00..m33 (row-major), 23 childCount.
 * -1 = one of the six always-zero matrix cells (m03,m13,m23,m30,m31,m32); their exact slots are unknowable
 * (zero in all 18,533 records), they are left 0.  Derived from 683 records that exist in both encodings.
 */
export const RECORD_PERM_2019 = [17, 8, 0, 4, 22, 1, 3, 16, 5, 7, 9, -1, 12, -1, 2, 11, 6, 13, 23, 15, -1, -1, -1, -1];

// ------------------------------------------------------------------------------------------------ small math
// Matrices are Float32Array(16) (or plain arrays) in D3D ROW-MAJOR layout: m[r*4+c], row 3 = translation.
// Row-vector convention: v' = v * M, and A * B means "apply A, then B".
// NOTE: a D3D row-major array fed to three.js Matrix4.fromArray() (column-major) is already the correct
// column-vector matrix (the transpose cancels out) - no transposition needed.

export function mat4Identity(out = new Float32Array(16)) {
  out.fill(0); out[0] = out[5] = out[10] = out[15] = 1; return out;
}

/** out = a * b (row-vector convention: apply a first, then b). out may alias a or b. */
export function mat4Multiply(a, b, out = new Float32Array(16)) {
  const r = new Float64Array(16);
  for (let i = 0; i < 4; i++) {
    const a0 = a[i * 4], a1 = a[i * 4 + 1], a2 = a[i * 4 + 2], a3 = a[i * 4 + 3];
    for (let j = 0; j < 4; j++) r[i * 4 + j] = a0 * b[j] + a1 * b[4 + j] + a2 * b[8 + j] + a3 * b[12 + j];
  }
  for (let i = 0; i < 16; i++) out[i] = r[i];
  return out;
}

/** General 4x4 inverse (returns identity-filled NaN-free result; singular -> all zeros). */
export function mat4Invert(m, out = new Float32Array(16)) {
  const a00 = m[0], a01 = m[1], a02 = m[2], a03 = m[3], a10 = m[4], a11 = m[5], a12 = m[6], a13 = m[7];
  const a20 = m[8], a21 = m[9], a22 = m[10], a23 = m[11], a30 = m[12], a31 = m[13], a32 = m[14], a33 = m[15];
  const b00 = a00 * a11 - a01 * a10, b01 = a00 * a12 - a02 * a10, b02 = a00 * a13 - a03 * a10;
  const b03 = a01 * a12 - a02 * a11, b04 = a01 * a13 - a03 * a11, b05 = a02 * a13 - a03 * a12;
  const b06 = a20 * a31 - a21 * a30, b07 = a20 * a32 - a22 * a30, b08 = a20 * a33 - a23 * a30;
  const b09 = a21 * a32 - a22 * a31, b10 = a21 * a33 - a23 * a31, b11 = a22 * a33 - a23 * a32;
  let det = b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;
  if (!det) { out.fill(0); return out; }
  det = 1 / det;
  out[0] = (a11 * b11 - a12 * b10 + a13 * b09) * det;
  out[1] = (a02 * b10 - a01 * b11 - a03 * b09) * det;
  out[2] = (a31 * b05 - a32 * b04 + a33 * b03) * det;
  out[3] = (a22 * b04 - a21 * b05 - a23 * b03) * det;
  out[4] = (a12 * b08 - a10 * b11 - a13 * b07) * det;
  out[5] = (a00 * b11 - a02 * b08 + a03 * b07) * det;
  out[6] = (a32 * b02 - a30 * b05 - a33 * b01) * det;
  out[7] = (a20 * b05 - a22 * b02 + a23 * b01) * det;
  out[8] = (a10 * b10 - a11 * b08 + a13 * b06) * det;
  out[9] = (a01 * b08 - a00 * b10 - a03 * b06) * det;
  out[10] = (a30 * b04 - a31 * b02 + a33 * b00) * det;
  out[11] = (a21 * b02 - a20 * b04 - a23 * b00) * det;
  out[12] = (a11 * b07 - a10 * b09 - a12 * b06) * det;
  out[13] = (a00 * b09 - a01 * b07 + a02 * b06) * det;
  out[14] = (a31 * b01 - a30 * b03 - a32 * b00) * det;
  out[15] = (a20 * b03 - a21 * b01 + a22 * b00) * det;
  return out;
}

/** D3DXMatrixRotationQuaternion: row-major rotation matrix for quaternion (x,y,z,w) (normalised first). */
export function quatToMat4(q, out = new Float32Array(16)) {
  let x = q[0], y = q[1], z = q[2], w = q[3];
  const n = Math.hypot(x, y, z, w) || 1; x /= n; y /= n; z /= n; w /= n;
  out[0] = 1 - 2 * (y * y + z * z); out[1] = 2 * (x * y + z * w); out[2] = 2 * (x * z - y * w); out[3] = 0;
  out[4] = 2 * (x * y - z * w); out[5] = 1 - 2 * (x * x + z * z); out[6] = 2 * (y * z + x * w); out[7] = 0;
  out[8] = 2 * (x * z + y * w); out[9] = 2 * (y * z - x * w); out[10] = 1 - 2 * (x * x + y * y); out[11] = 0;
  out[12] = 0; out[13] = 0; out[14] = 0; out[15] = 1;
  return out;
}

/** Local matrix L = S * R(q) * T(p)  (row-vector). scaleMat may be null (identity). */
export function composeLocal(pos, quat, scaleMat = null, out = new Float32Array(16)) {
  const r = quatToMat4(quat);
  if (scaleMat) mat4Multiply(scaleMat, r, out); else out.set(r);
  out[12] += pos[0]; out[13] += pos[1]; out[14] += pos[2];
  // (S*R has a zero translation row as long as scaleMat has none - always true in the data)
  return out;
}

/** Transform a point by a row-major matrix (row-vector convention). */
export function transformPoint(m, p, out = [0, 0, 0]) {
  const x = p[0], y = p[1], z = p[2];
  out[0] = x * m[0] + y * m[4] + z * m[8] + m[12];
  out[1] = x * m[1] + y * m[5] + z * m[9] + m[13];
  out[2] = x * m[2] + y * m[6] + z * m[10] + m[14];
  return out;
}

// ------------------------------------------------------------------------------------ three.js frame helpers
// File frame = D3D left-handed, Y up. three.js = right-handed, Y up. Project-wide rule: mirror Z.
//   position (x,y,z) -> (x,y,-z);  quaternion (x,y,z,w) -> (-x,-y,z,w);  matrix M -> F*M*F, F = diag(1,1,-1,1)
// (equivalently keep file-frame data and parent the model under a root with scale.z = -1).
export const toThreePosition = (p) => [p[0], p[1], -p[2]];
export const toThreeQuaternion = (q) => [-q[0], -q[1], q[2], q[3]];
export function toThreeMatrix(m, out = new Float32Array(16)) {
  // F*M*F negates row 2 and column 2 (the [2][2] cell is negated twice)
  for (let r = 0; r < 4; r++) for (let c = 0; c < 4; c++) {
    const s = (r === 2 ? -1 : 1) * (c === 2 ? -1 : 1);
    out[r * 4 + c] = m[r * 4 + c] * s;
  }
  return out; // row-major D3D layout == column-major three.js layout: new Matrix4().fromArray(out)
}

// -------------------------------------------------------------------------------------- name de-obfuscation
const NAME_OK = new Uint8Array(256);
for (const c of 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 _-.#()\t') NAME_OK[c.charCodeAt(0)] = 1;
// frequent tokens of plain-text bone / track names (lower-case); used to break ties between XOR keys that
// all yield printable text (e.g. "Fkja45" vs "Bone01" differ by ^0x04, "Head" vs "hEAD" by ^0x20)
const NAME_TOKENS = ['bip0', 'bone', 'dummy', 'object', 'box', 'point', 'plane', 'frag', 'spine', 'pelvis', 'thigh',
  'calf', 'foot', 'toe', 'head', 'neck', 'clavicle', 'upperarm', 'forearm', 'hand', 'finger', 'tail', 'weapon', 'cylinder',
  'sphere', 'body', 'wing', 'eff', 'att', 'root', 'hair', 'cloth', 'cape', 'skirt', 'ponytail', 'horse', 'teapot',
  'helper', 'line', 'shape', 'mesh', 'rotation', 'face'];
// the 220 most frequent letter bigrams over the 15,024 distinct plain-text bone names (lower-cased)
const COMMON_BIGRAMS = new Set(('inneboonraffefbiipagfratlangttleilerdenvanisarshadpoaigequeateelstemntotrosiecwieqherealeni' +
  'criplguuifipeckortactllmoasbrowoispostojethmaobhihabjeyumloliswirssclcowepacandubyehofaebigbaslceduesoowdedghtrsuchega' +
  'pfeutwampoxrmseitmycuouacmmpirteeupsovenuhtoletmephrrustigloclvodrciefoldimdonaueniviskmsomdiavoeioppcrprcykeoprdiddye' +
  'pylovwobeblafdrhjjnrslfakcijunoflunrnulgamioknkktgrwnmhdwurrgkiamtcsbluwpeiltewzebbikoaabpbwhaxsadlfsmbtlscrkvfru')
  .match(/../g));
function nameLikeness(s) {
  s = s.toLowerCase();
  let score = 0;
  for (const t of NAME_TOKENS) if (s.includes(t)) score += 4;
  for (let i = 0; i + 1 < s.length; i++) {
    const a = s.charCodeAt(i), b = s.charCodeAt(i + 1);
    if (a >= 97 && a <= 122 && b >= 97 && b <= 122) score += COMMON_BIGRAMS.has(s.slice(i, i + 2)) ? 1 : -2;
  }
  return score;
}

/**
 * (Fallback / diagnostics only - the real keys are derived from the source path, see parseSkel/parseAnim.)
 * Pick the single-byte XOR key that turns every byte string into a plausible bone name
 * (charset seen in all plain-text files: [A-Za-z0-9 _-.#()\t]). Among keys with the same number of plausible
 * bytes, the one producing the most known name tokens wins, then more lower-case letters, then `prefer`.
 * @param {Uint8Array[]} list
 * @param {number[]} prefer keys to favour on ties (first wins)
 * @returns {{key:number, score:number}} score = fraction of plausible bytes (1 = all)
 */
export function detectXorKey(list, prefer = [0x3a, 0x00]) {
  let total = 0; for (const b of list) total += b.length;
  if (!total) return { key: prefer[0] ?? 0, score: 1 };
  const cands = [];
  for (let k = 0; k < 256; k++) {
    let ok = 0, lower = 0;
    for (const b of list) for (let i = 0; i < b.length; i++) {
      const c = b[i] ^ k; ok += NAME_OK[c]; if (c >= 97 && c <= 122) lower++;
    }
    const pr = prefer.indexOf(k);
    cands.push({ key: k, ok, lower, pr: pr < 0 ? 999 : pr, tok: 0 });
  }
  const maxOk = Math.max(...cands.map(c => c.ok));
  const top = cands.filter(c => c.ok === maxOk);
  if (top.length > 1) {
    const sample = list.length > 64 ? list.filter((_, i) => i % Math.ceil(list.length / 64) === 0) : list;
    for (const c of top) for (const b of sample) c.tok += nameLikeness(xorDecode(b, c.key));
  }
  top.sort((a, b) => (b.tok - a.tok) || (b.lower - a.lower) || (a.pr - b.pr) || (a.key - b.key));
  return { key: top[0].key, score: maxOk / total };
}

/**
 * XOR-decode a name (key 0 = clear text) and decode it as EUC-KR (CP949), exactly like mesh.js decodes its bone
 * palette names, so that a Korean bone name (e.g. item/general/etc/gen_inv_etc_53) is the SAME JS string in the
 * .skel, the .anim tracks and the .mesh palette. ASCII names are unaffected.
 */
export function xorDecode(bytes, key) {
  if (!key) return decodeText(bytes, true);
  const t = new Uint8Array(bytes.length);
  for (let i = 0; i < bytes.length; i++) t[i] = bytes[i] ^ key;
  return decodeText(t, true);
}

// ------------------------------------------------------------------------------------------------- parser

/**
 * Parse a .skel file.
 * @param {ArrayBuffer|Uint8Array} buf
 * @param {{computeMatrices?: boolean}} [opts]  computeMatrices (default true): fill localMatrix/bindMatrix/invBind
 * @returns {{
 *   version:number, versionHex:string, obfuscated:boolean,
 *   rootCount:number, headerSize:number, dataSize:number, dataSizeOk:boolean, sourcePath:string,
 *   bones: Array<{
 *     index:number, name:string, alias:string, parent:number, childCount:number, children:number[], depth:number,
 *     position:number[3], rotation:number[4] (x,y,z,w), scaleMatrix:Float32Array(16),
 *     localMatrix?:Float32Array(16), bindMatrix?:Float32Array(16) (model-space bind = "world"), invBind?:Float32Array(16),
 *     rawName:Uint8Array, rawAlias:Uint8Array|null
 *   }>,
 *   boneIndex: Record<string, number>,   // exact name -> index (first wins)
 *   nameKey:number, aliasKey:number, nameKeyScore:number,   // XOR keys (0 for plain files)
 *   unkHeader: number[], trailingBytes:number
 * }}
 */
export function parseSkel(buf, opts = {}) {
  const computeMatrices = opts.computeMatrices !== false;
  const r = new BinReader(toArrayBuffer(buf));
  const version = r.u32();
  if (!SKEL_VERSIONS.includes(version)) throw new Error(`skel: unknown version 0x${version.toString(16)}`);
  let rootCount, boneCount, headerSize, dataSize;
  if (version === SKEL_V2003) {
    boneCount = r.u32(); headerSize = r.u32(); dataSize = r.u32(); rootCount = -1;
  } else {
    rootCount = r.u32(); boneCount = r.u32(); headerSize = r.u32(); dataSize = r.u32();
  }
  const unkHeader = [];
  while (r.pos < 0x20) unkHeader.push(r.u32());
  const pathBytes = r.bytes(0x40).slice();
  r.seek(0x20);
  const sourcePath = r.fixedStr(0x40, true);
  r.seek(headerSize);

  const twoNames = version === SKEL_V2004 || version === SKEL_V2019;
  const obf = version === SKEL_V2019;
  const raw = [];
  for (let i = 0; i < boneCount; i++) {
    const n1 = r.bytes(r.u32()).slice();
    const n2 = twoNames ? r.bytes(r.u32()).slice() : null;
    const dv = new DataView(r.buf, r.pos, 96);
    r.skip(96);
    const plainU = new Uint32Array(SKEL_RECORD_DWORDS);
    if (obf) {
      for (let k = 0; k < SKEL_RECORD_DWORDS; k++) {
        const dst = RECORD_PERM_2019[k];
        if (dst >= 0) plainU[dst] = dv.getUint32(k * 4, true);
      }
    } else {
      for (let k = 0; k < SKEL_RECORD_DWORDS; k++) plainU[k] = dv.getUint32(k * 4, true);
    }
    raw.push({ n1, n2, plainU });
  }
  const trailingBytes = r.remaining;

  // names (v2019: keys come from the source-path bytes, see header comment)
  let nameKey = 0, aliasKey = 0, nameKeyScore = 1;
  if (obf) {
    aliasKey = pathBytes[rootCount & 63];
    nameKey = pathBytes[(dataSize + headerSize) & 63];
    let ok = 0, tot = 0;
    for (const b of raw) for (const c of b.n1) { tot++; ok += NAME_OK[c ^ nameKey]; }
    nameKeyScore = tot ? ok / tot : 1; // plausibility of the decoded names (1 = every byte in the name charset)
  }

  const f32 = new Float32Array(1), u32v = new Uint32Array(f32.buffer);
  const asF = (u) => { u32v[0] = u; return f32[0]; };
  const bones = raw.map((b, index) => {
    const u = b.plainU;
    const position = [asF(u[0]), asF(u[1]), asF(u[2])];
    const rotation = [asF(u[3]), asF(u[4]), asF(u[5]), asF(u[6])];
    const scaleMatrix = new Float32Array(16);
    for (let k = 0; k < 16; k++) scaleMatrix[k] = asF(u[7 + k]);
    // A handful of plain files (breakable-object fragments) store NaN positions: sanitise to identity parts, flag it.
    let nonFinite = false;
    for (let k = 0; k < 3; k++) if (!Number.isFinite(position[k])) { position[k] = 0; nonFinite = true; }
    if (!rotation.every(Number.isFinite) || !Math.hypot(...rotation)) { rotation.splice(0, 4, 0, 0, 0, 1); nonFinite = true; }
    if (!scaleMatrix.every(Number.isFinite)) { mat4Identity(scaleMatrix); nonFinite = true; }
    const name = xorDecode(b.n1, nameKey);
    const bone = {
      index, name, alias: b.n2 ? xorDecode(b.n2, aliasKey) : name, parent: -1, childCount: u[23], children: [], depth: 0,
      position, rotation, scaleMatrix, rawName: b.n1, rawAlias: b.n2,
    };
    if (nonFinite) bone.unkNonFinite = true;
    return bone;
  });

  // hierarchy from pre-order child counts
  let actualRoots = 0;
  {
    const stack = []; // [boneIndex, remainingChildren]
    for (let i = 0; i < bones.length; i++) {
      while (stack.length && stack[stack.length - 1][1] === 0) stack.pop();
      if (stack.length) {
        const top = stack[stack.length - 1];
        bones[i].parent = top[0]; top[1]--;
        bones[top[0]].children.push(i);
        bones[i].depth = bones[top[0]].depth + 1;
      } else actualRoots++;
      stack.push([i, bones[i].childCount]);
    }
  }

  // null prototype: a bone called "constructor"/"toString" must not resolve to an Object.prototype member
  const boneIndex = Object.create(null);
  bones.forEach((b, i) => { if (!(b.name in boneIndex)) boneIndex[b.name] = i; });

  const out = {
    version, versionHex: '0x' + version.toString(16), obfuscated: obf,
    rootCount: rootCount < 0 ? actualRoots : rootCount, actualRootCount: actualRoots,
    headerSize, dataSize, dataSizeOk: headerSize + dataSize === r.length, sourcePath,
    bones, boneIndex, nameKey, aliasKey, nameKeyScore, unkHeader, trailingBytes,
  };
  if (computeMatrices) computeBindMatrices(out);
  return out;
}

/** Fill localMatrix / bindMatrix (model space) / invBind for every bone of a parsed skeleton. */
export function computeBindMatrices(skel) {
  for (const b of skel.bones) {
    b.localMatrix = composeLocal(b.position, b.rotation, b.scaleMatrix);
    b.bindMatrix = b.parent >= 0 ? mat4Multiply(b.localMatrix, skel.bones[b.parent].bindMatrix) : new Float32Array(b.localMatrix);
    b.invBind = mat4Invert(b.bindMatrix);
  }
  return skel;
}

/** Model-space bind position of every bone: Float32Array(boneCount*3) (file frame). */
export function bindPositions(skel) {
  const out = new Float32Array(skel.bones.length * 3);
  skel.bones.forEach((b, i) => { out[i * 3] = b.bindMatrix[12]; out[i * 3 + 1] = b.bindMatrix[13]; out[i * 3 + 2] = b.bindMatrix[14]; });
  return out;
}

/** Find a bone index by name: exact, then case-insensitive, then by alias. Returns -1 if absent. */
export function findBone(skel, name) {
  if (name in skel.boneIndex) return skel.boneIndex[name];
  const l = String(name).toLowerCase();
  let i = skel.bones.findIndex(b => b.name.toLowerCase() === l);
  if (i < 0) i = skel.bones.findIndex(b => b.alias.toLowerCase() === l);
  return i;
}
