// Dekaron .mol — map object placement list (map/<name>.mol, 268 files).
//
// Layout (little-endian, no header/version, no padding):
//   u32 count
//   count x {
//     f32 x          // world X (file frame), terrain-cell units: heightmap column
//     f32 z          // world Z (file frame), terrain-cell units: heightmap row
//     f32 qx, qy, qz, qw   // rotation quaternion, D3DX layout (x,y,z,w), unit length, file (left-handed) frame
//     f32 y          // height OFFSET above the terrain surface at (x, z)  (NOT absolute)
//     f32 scale      // uniform scale (rarely <= 0: a negative value is a point mirror, keep it)
//     u32 nameLen
//     char name[nameLen]  // no NUL, ASCII: "<category>\<name>" or "<category>\<name>.txt"
//   }
// Every one of the 268 files is consumed exactly (validated by tools/test-mol.mjs).
//
// World placement in the FILE frame (DirectX, left-handed, Y up):
//   P_file = ( x, terrainHeight(x, z) + y, z )
//   M_file = T(P_file) * R(q) * S(scale)      (standard quaternion->matrix, i.e. D3DXMatrixRotationQuaternion)
// three.js (right-handed) conversion — mirror Z, consistent with every other format:
//   position = ( x, terrainHeight(x, z) + y, -z )
//   quaternion = ( -qx, -qy, qz, qw )
//   scale = (s, s, s)
// (equivalently: keep file-frame values and parent everything under a root with scale.z = -1).
// See docs/formats/mol.md.

import { BinReader, toArrayBuffer } from './binreader.js';

export const MOL_RECORD_FIXED_BYTES = 36; // 8 floats + u32 name length

/** Object categories that appear as the first path component of .mol names (= script/object/<cat>.csv). */
export const MOL_CATEGORIES = [
  'animal', 'bridge', 'building', 'building_extra', 'etc', 'field_extra', 'house',
  'junk', 'plant', 'portal', 'rock', 'siegeflag', 'tree', 'wall',
];

/**
 * Parse a .mol file.
 * @param {ArrayBuffer|Uint8Array} buf
 * @returns {{
 *   count: number,
 *   objects: Array<{name:string, nameId:number, x:number, z:number, y:number, qx:number, qy:number, qz:number, qw:number, scale:number}>,
 *   names: string[],               // unique object names, first-seen order
 *   nameIds: Uint32Array,          // per object: index into names
 *   positions: Float32Array,       // per object (x, yOffset, z)  — FILE frame, y is terrain-relative
 *   quaternions: Float32Array,     // per object (qx, qy, qz, qw) — FILE frame
 *   scales: Float32Array,          // per object uniform scale
 *   bytesConsumed: number, trailingBytes: number
 * }}
 */
export function parseMol(buf) {
  const ab = toArrayBuffer(buf);
  const r = new BinReader(ab);
  if (r.length < 4) throw new Error('mol: file too small');
  const count = r.u32();
  // sanity: every record is at least 36 bytes (+ name)
  if (count * MOL_RECORD_FIXED_BYTES > r.remaining) {
    throw new Error(`mol: count ${count} impossible for ${r.length} bytes`);
  }
  const objects = new Array(count);
  const positions = new Float32Array(count * 3);
  const quaternions = new Float32Array(count * 4);
  const scales = new Float32Array(count);
  const nameIds = new Uint32Array(count);
  const names = [];
  const nameMap = new Map();
  for (let i = 0; i < count; i++) {
    const x = r.f32(), z = r.f32();
    const qx = r.f32(), qy = r.f32(), qz = r.f32(), qw = r.f32();
    const y = r.f32();
    const scale = r.f32();
    const len = r.u32();
    if (len > 1024 || len > r.remaining) throw new Error(`mol: bad name length ${len} at record ${i} (pos ${r.pos - 4})`);
    const name = r.fixedStr(len);
    let id = nameMap.get(name);
    if (id === undefined) { id = names.length; names.push(name); nameMap.set(name, id); }
    nameIds[i] = id;
    positions[i * 3] = x; positions[i * 3 + 1] = y; positions[i * 3 + 2] = z;
    quaternions[i * 4] = qx; quaternions[i * 4 + 1] = qy; quaternions[i * 4 + 2] = qz; quaternions[i * 4 + 3] = qw;
    scales[i] = scale;
    objects[i] = { name, nameId: id, x, z, y, qx, qy, qz, qw, scale };
  }
  return {
    count, objects, names, nameIds, positions, quaternions, scales,
    bytesConsumed: r.pos, trailingBytes: r.length - r.pos,
  };
}

/** Category (lower-case) of a .mol object name, e.g. "Tree\\a_tree_01.txt" -> "tree". */
export function molCategory(name) {
  const s = String(name).replace(/\//g, '\\');
  const i = s.indexOf('\\');
  return (i < 0 ? '' : s.slice(0, i)).trim().toLowerCase();
}

/**
 * File-frame -> three.js transform for one placement.
 * @param {{x,z,y,qx,qy,qz,qw,scale}} o   a parsed record
 * @param {number} terrainHeight          height of the terrain surface at (o.x, o.z) (file frame, same units)
 * @returns {{position:number[], quaternion:number[], scale:number[]}}  three.js (right-handed, Z mirrored)
 */
export function molToThree(o, terrainHeight = 0) {
  return {
    position: [o.x, terrainHeight + o.y, -o.z],
    quaternion: [-o.qx, -o.qy, o.qz, o.qw],
    scale: [o.scale, o.scale, o.scale],
  };
}

/**
 * Column-major 4x4 matrix (three.js Matrix4.elements order) of a placement, already converted to three.js space.
 * Equivalent to Matrix4.compose(position, quaternion, scale) with the values from molToThree().
 */
export function molMatrixThree(o, terrainHeight = 0, out = new Float32Array(16)) {
  const x = -o.qx, y = -o.qy, z = o.qz, w = o.qw;
  const s = o.scale;
  const x2 = x + x, y2 = y + y, z2 = z + z;
  const xx = x * x2, xy = x * y2, xz = x * z2, yy = y * y2, yz = y * z2, zz = z * z2;
  const wx = w * x2, wy = w * y2, wz = w * z2;
  out[0] = (1 - (yy + zz)) * s; out[1] = (xy + wz) * s; out[2] = (xz - wy) * s; out[3] = 0;
  out[4] = (xy - wz) * s; out[5] = (1 - (xx + zz)) * s; out[6] = (yz + wx) * s; out[7] = 0;
  out[8] = (xz + wy) * s; out[9] = (yz - wx) * s; out[10] = (1 - (xx + yy)) * s; out[11] = 0;
  out[12] = o.x; out[13] = terrainHeight + o.y; out[14] = -o.z; out[15] = 1;
  return out;
}

/** Yaw (radians, about +Y, file frame, standard right-hand-rule sign on the stored quaternion). Handy for 2D tools. */
export function molYaw(o) {
  return Math.atan2(2 * (o.qw * o.qy + o.qx * o.qz), 1 - 2 * (o.qy * o.qy + o.qx * o.qx));
}
