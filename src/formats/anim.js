// Dekaron .anim — per-bone keyframe animation (anim/<category>/<model>/*.anim, ~25,500 files).
//
// Pure parser + sampler: no three.js, no Node APIs. See docs/formats/anim.md.
//
// Header (headerSize bytes, little-endian):
//   u32 version      0x20030820 (37 map-object files, headerSize 0x64) | 0x20031113 (plain, 0x68) | 0x20191130 (obfuscated, 0x68)
//   u32 trackCount
//   u32 headerSize   0x64 | 0x68
//   u32 trackDataSize  == tailOffset - headerSize
//   u32 tailOffset     start of the root-motion block
//   u32 tailSize       declared size of the root-motion block (v0x20191130: stale value of the plain layout)
//   u8[..] zero, char[64] sourcePath (EUC-KR) ending at headerSize
// @headerSize: u32 trackCount (repeated), then trackCount tracks, SORTED BY NAME (byte-wise ascending, like std::map):
//   plain:  lpstr name; for ch in (pos, rot, scale): { u32 unkFlag(=0); u32 n; n keys }
//   v2019:  u32 nPos, u32 unkFlagPos, lpstr name, u32 unkFlagScl, u32 nScl, u32 unkFlagRot, u32 nRot,
//           then the pos, rot, scale key arrays (each key's dwords permuted, see KEY_PERM_2019);
//           name bytes XOR pathBytes[(2*trackCount) & 63] (64-byte sourcePath field incl. NUL padding; 0 = clear)
//   pos key   : f32 t, x, y, z                               (16 bytes)  local translation (parent space)
//   rot key   : f32 t, qx, qy, qz, qw                         (20 bytes)  local rotation, D3DX quaternion
//   scale key : f32 t, m[16] row-major 4x4 stretch matrix     (68 bytes)  same meaning as the .skel scale matrix
//   t is NORMALISED time in [0,1] (first key 0, last key 1). Real length comes from the action tables
//   (share/action/**: TimeLength seconds) or the object/static "animation <path> <seconds>" line.
// @tailOffset: root motion (displacement of the character origin, removed from the Bip01 track):
//   plain:  u32 unkA, u32 nA, nA x {f32 t, x, z};   u32 unkB, u32 nB, nB x {f32 t, y}   (horizontal + vertical)
//   v2019:  u32 unkA, u32 nA, nA x {f32 x, t, z};   u32 unkB, u32 nB(=0)
//   v2003:  u32 unkA, u32 nA, nA x {f32 t, z};      u32 unkB, u32 nB, nB x {f32 t, y}
//   unkA/unkB are garbage (uninitialised pointers). Values are model-space, file frame; forward = -Z.
//   The curve is the authored position of the character origin: 11 % of files do not start at 0 (combo steps that
//   continue where the previous clip ended) -> move entities by differences only (sampleRootMotion does this).
// Local pose per bone (D3D row vectors): L = SCALE(t) * R(t) * T(t); model = L * model(parent)  (same as .skel)

import { BinReader, toArrayBuffer } from './binreader.js';
import {
  detectXorKey, xorDecode, composeLocal, mat4Multiply, mat4Identity, findBone,
} from './skel.js';

export const ANIM_V2003 = 0x20030820;
export const ANIM_V2003B = 0x20031113;
export const ANIM_V2019 = 0x20191130;
export const ANIM_VERSIONS = [ANIM_V2003, ANIM_V2003B, ANIM_V2019];

/** v0x20191130 key layouts: stored dword i holds plain dword KEY_PERM_2019.X[i] (plain = t, values...). -1 = zero cell. */
export const KEY_PERM_2019 = {
  pos: [2, 0, 3, 1],                 // stored (y, t, z, x)
  rot: [3, 1, 0, 4, 2],              // stored (qz, qx, t, qw, qy)
  // plain scale key: 0 t, 1..16 = m00 m01 m02 m03 m10 m11 m12 m13 m20 m21 m22 m23 m30 m31 m32 m33
  scl: [0, 11, 2, 16, 10, 1, 3, -1, 6, -1, 5, 7, 9, -1, -1, -1, -1],
  rootA: [1, 0, 2],                  // stored (x, t, z)
};
const KEY_DWORDS = { pos: 4, rot: 5, scl: 17 };
/** Authoring frame rate: frameCount / TimeLength == 30 for 73 % of action-table rows. */
export const AUTHORING_FPS = 30;
const NAME_CHARSET = /[A-Za-z0-9 _\-.#()\t]/;

function readKeys(r, n, kind, obf) {
  const size = KEY_DWORDS[kind];
  r.ensure(n * size * 4);
  const dv = new DataView(r.buf, r.pos, n * size * 4);
  r.skip(n * size * 4);
  const times = new Float32Array(n);
  const vals = new Float32Array(n * (size - 1));
  const perm = obf ? KEY_PERM_2019[kind] : null;
  const tmp = new Float32Array(size);
  for (let k = 0; k < n; k++) {
    if (perm) {
      tmp.fill(0);
      for (let i = 0; i < size; i++) { const d = perm[i]; if (d >= 0) tmp[d] = dv.getFloat32((k * size + i) * 4, true); }
    } else {
      for (let i = 0; i < size; i++) tmp[i] = dv.getFloat32((k * size + i) * 4, true);
    }
    times[k] = tmp[0];
    for (let i = 1; i < size; i++) vals[k * (size - 1) + i - 1] = tmp[i];
  }
  return { times, vals };
}

/**
 * Parse a .anim file.
 * @param {ArrayBuffer|Uint8Array} buf
 * @param {{ guessKey?: boolean }} [opts]  guessKey (default true): if the path-derived v2019 name key decodes to
 *        implausible text (never happens in the shipped data) fall back to charset scoring.
 * @returns {{
 *   version:number, versionHex:string, obfuscated:boolean, headerSize:number, trackCount:number,
 *   trackDataSize:number, tailOffset:number, tailSize:number, tailSizeActual:number, sourcePath:string,
 *   duration:1, normalizedTime:true, fps:null, frameCount:number|null, estDurationSec:number|null,
 *   nameKey:number, nameKeyScore:number,
 *   tracks: Array<{ name:string, bone:string, rawName:Uint8Array,
 *     times:Float32Array,                  // sorted union of all key times of this track
 *     posTimes:Float32Array, positions:Float32Array,    // 3 per key (x,y,z)
 *     rotTimes:Float32Array, rotations:Float32Array,    // 4 per key (x,y,z,w)
 *     sclTimes:Float32Array, scales:Float32Array,       // 16 per key (row-major 4x4 stretch matrix)
 *     unkFlags:number[] }>,
 *   rootMotion: { unkA:number, times:Float32Array, x:Float32Array, z:Float32Array,   // horizontal displacement
 *                 unkB:number, yTimes:Float32Array, y:Float32Array },                 // vertical displacement
 *   truncated:boolean,   // file ends before the declared track data (6 shipped files; complete tracks are kept)
 *                        // or inside the root-motion block (root motion then empty or partial)
 *   trackIndex: Record<string, number>, unkHeader:number[], trailingBytes:number
 * }}
 */
export function parseAnim(buf, opts = {}) {
  const r = new BinReader(toArrayBuffer(buf));
  const version = r.u32();
  if (!ANIM_VERSIONS.includes(version)) throw new Error(`anim: unknown version 0x${version.toString(16)}`);
  const trackCount = r.u32(), headerSize = r.u32(), trackDataSize = r.u32(), tailOffset = r.u32(), tailSize = r.u32();
  const unkHeader = [];
  while (r.pos < headerSize - 64) unkHeader.push(r.u32());
  r.seek(headerSize - 64);
  const pathBytes = r.bytes(64).slice();
  r.seek(headerSize - 64);
  const sourcePath = r.fixedStr(64, true);
  r.seek(headerSize);
  const obf = version === ANIM_V2019;
  const count2 = r.u32();
  const raw = [];
  let truncated = false;
  try {
    for (let i = 0; i < count2; i++) {
      let nPos, nRot, nScl, flags, nameBytes;
      if (obf) {
        nPos = r.u32(); const fPos = r.u32();
        nameBytes = r.bytes(r.u32()).slice();
        const fScl = r.u32(); nScl = r.u32(); const fRot = r.u32(); nRot = r.u32();
        flags = [fPos, fRot, fScl];
        const pos = readKeys(r, nPos, 'pos', true);
        const rot = readKeys(r, nRot, 'rot', true);
        const scl = readKeys(r, nScl, 'scl', true);
        raw.push({ nameBytes, pos, rot, scl, flags });
      } else {
        nameBytes = r.bytes(r.u32()).slice();
        const fPos = r.u32(); nPos = r.u32(); const pos = readKeys(r, nPos, 'pos', false);
        const fRot = r.u32(); nRot = r.u32(); const rot = readKeys(r, nRot, 'rot', false);
        const fScl = r.u32(); nScl = r.u32(); const scl = readKeys(r, nScl, 'scl', false);
        flags = [fPos, fRot, fScl];
        raw.push({ nameBytes, pos, rot, scl, flags });
      }
    }
  } catch (e) {
    // 6 shipped files are cut short (declared tailOffset > file size): keep the complete tracks, flag the file
    if (!(e instanceof RangeError)) throw e;
    truncated = true;
    r.seek(r.length);
  }
  const tracksEnd = r.pos;

  const root = readRootMotion(r, version);
  const rootMotion = root.rootMotion;
  if (root.truncated) truncated = true;
  // plain versions declare the exact tail size (v2019's is stale): a shorter file lost (part of) its root motion
  if (!obf && tailOffset + tailSize > r.length) truncated = true;
  const trailingBytes = r.remaining;

  // ---- names (v2019: XOR key = pathBytes[(2 * trackCount) & 63], verified on all 4,850 files)
  let nameKey = 0, nameKeyScore = 1;
  const nameList = raw.map(t => t.nameBytes);
  if (obf) {
    nameKey = pathBytes[(2 * trackCount) & 63];
    let ok = 0, tot = 0;
    for (const b of nameList) for (const c of b) { tot++; ok += NAME_CHARSET.test(String.fromCharCode(c ^ nameKey)) ? 1 : 0; }
    nameKeyScore = tot ? ok / tot : 1;
    if (nameKeyScore < 0.9 && opts.guessKey !== false) {
      // defensive fallback for hand-made files: choose the key by charset heuristics
      ({ key: nameKey, score: nameKeyScore } = detectXorKey(nameList, [nameKey, 0x3a]));
    }
  }

  const tracks = raw.map(t => {
    const name = xorDecode(t.nameBytes, nameKey);
    const all = new Float32Array([...t.pos.times, ...t.rot.times, ...t.scl.times]).sort();
    const times = all.filter((v, i) => i === 0 || v !== all[i - 1]);
    // ~50 tracks (breakable-object fragments) contain NaN keys: sanitise (pos 0, rot identity, scale identity)
    let nonFinite = 0;
    const P = t.pos.vals, Q = t.rot.vals, S = t.scl.vals;
    for (let i = 0; i < P.length; i++) if (!Number.isFinite(P[i])) { P[i] = 0; nonFinite++; }
    for (let k = 0; k < Q.length; k += 4) {
      if (!(Number.isFinite(Q[k]) && Number.isFinite(Q[k + 1]) && Number.isFinite(Q[k + 2]) && Number.isFinite(Q[k + 3])) ||
          !(Q[k] || Q[k + 1] || Q[k + 2] || Q[k + 3])) { Q[k] = Q[k + 1] = Q[k + 2] = 0; Q[k + 3] = 1; nonFinite++; }
    }
    for (let k = 0; k < S.length; k += 16) {
      let bad = false; for (let i = 0; i < 16; i++) if (!Number.isFinite(S[k + i])) bad = true;
      if (bad) { S.fill(0, k, k + 16); S[k] = S[k + 5] = S[k + 10] = S[k + 15] = 1; nonFinite++; }
    }
    // 31 tracks (e.g. character/shooter sht_com_surrender) store quaternions of norm sqrt(2): normalise them here so
    // every consumer (sampleAnim().rotations, THREE.QuaternionKeyframeTrack, Matrix4.compose) gets unit quaternions
    let nonUnit = 0;
    for (let k = 0; k < Q.length; k += 4) {
      const l = Math.hypot(Q[k], Q[k + 1], Q[k + 2], Q[k + 3]);
      if (Math.abs(l - 1) > 1e-4) { Q[k] /= l; Q[k + 1] /= l; Q[k + 2] /= l; Q[k + 3] /= l; nonUnit++; }
    }
    const tr = {
      name, bone: name, rawName: t.nameBytes, times,
      posTimes: t.pos.times, positions: P,
      rotTimes: t.rot.times, rotations: Q,
      sclTimes: t.scl.times, scales: S,
      unkFlags: t.flags,
    };
    if (nonFinite) tr.unkNonFinite = nonFinite;
    if (nonUnit) tr.unkNonUnitQuat = nonUnit;
    return tr;
  });
  const trackIndex = Object.create(null); // null prototype: no Object.prototype members as "track names"
  tracks.forEach((t, i) => { if (!(t.name in trackIndex)) trackIndex[t.name] = i; });

  const frameCount = estimateFrameCount(tracks);
  return {
    version, versionHex: '0x' + version.toString(16), obfuscated: obf, headerSize, trackCount,
    trackDataSize, tailOffset, tailSize, tailSizeActual: r.length - tracksEnd, tracksEnd, sourcePath,
    // times are normalised: duration 1. Real seconds = action-table TimeLength; fallback estimate = frames / 30 fps
    duration: 1, normalizedTime: true, fps: null, frameCount,
    estDurationSec: frameCount ? frameCount / AUTHORING_FPS : null, truncated,
    nameKey, nameKeyScore, tracks, trackIndex, rootMotion, unkHeader, trailingBytes,
  };
}

// ---- root motion tail: horizontal (x, z) list + vertical (y) list, same key times, normalised t
//   v0x20031113: {t,x,z} + {t,y};  v0x20191130: {x,t,z} + (y list always empty);  v0x20030820: {t,z} + {t,y}
function readRootMotion(r, version) {
  const obf = version === ANIM_V2019;
  let truncated = false;
  const rootMotion = {
    unkA: 0, times: new Float32Array(0), x: new Float32Array(0), z: new Float32Array(0),
    unkB: 0, yTimes: new Float32Array(0), y: new Float32Array(0),
  };
  const aStride = version === ANIM_V2003 ? 8 : 12;
  const cnt = () => new DataView(r.buf).getUint32(r.pos + 4, true);
  if (r.remaining >= 8 && r.remaining >= 8 + aStride * cnt()) {
    rootMotion.unkA = r.u32();
    const nA = r.u32();
    rootMotion.times = new Float32Array(nA); rootMotion.x = new Float32Array(nA); rootMotion.z = new Float32Array(nA);
    for (let k = 0; k < nA; k++) {
      if (aStride === 8) { rootMotion.times[k] = r.f32(); rootMotion.z[k] = r.f32(); continue; }
      const a = r.f32(), b = r.f32(), c = r.f32();
      if (obf) { rootMotion.x[k] = a; rootMotion.times[k] = b; rootMotion.z[k] = c; }
      else { rootMotion.times[k] = a; rootMotion.x[k] = b; rootMotion.z[k] = c; }
    }
    if (r.remaining >= 8 && r.remaining >= 8 + 8 * cnt()) {
      rootMotion.unkB = r.u32();
      const nB = r.u32();
      rootMotion.yTimes = new Float32Array(nB); rootMotion.y = new Float32Array(nB);
      for (let k = 0; k < nB; k++) { rootMotion.yTimes[k] = r.f32(); rootMotion.y[k] = r.f32(); }
    } else if (r.remaining > 0) truncated = true;   // vertical list cut short
  } else if (r.remaining > 0) truncated = true;     // horizontal list cut short
  return { rootMotion, truncated };
}

/**
 * Root-motion block only (header + tail at tailOffset; no track parsing), the same values parseAnim(buf).rootMotion
 * returns. The host reads every skill clip's origin curve this way (tailOffset equals the end of the track data in all
 * 2,464 skill clips of the class packs). null when the header is not an .anim or the tail lies outside the buffer.
 */
export function parseAnimRootMotion(buf) {
  const r = new BinReader(toArrayBuffer(buf));
  if (r.length < 24) return null;
  const version = r.u32();
  if (!ANIM_VERSIONS.includes(version)) return null;
  r.u32(); r.u32(); r.u32();
  const tailOffset = r.u32();
  if (!(tailOffset >= 24 && tailOffset <= r.length)) return null;
  r.seek(tailOffset);
  return readRootMotion(r, version).rootMotion;
}

/**
 * Estimate the source frame count N (key times are k/N). Returns the smallest N in 1..1000 that puts every key
 * time within ~2e-3 frames of an integer; for longer clips (34 files, e.g. the 1,819-frame *_emt_worldcup_01 emotes)
 * the candidate round(1 / smallest key gap) is tried as well. null when the clip only has keys at t = 0 and t = 1
 * (816 files: N is not recoverable) or the times are not on a regular grid.
 */
export function estimateFrameCount(tracks) {
  const ts = new Set();
  for (const t of tracks) for (const v of t.times) if (v > 0 && v < 1) ts.add(v);
  if (!ts.size) return null;
  const all = [...ts];
  const arr = all.slice(0, 400);
  const fits = (n, list) => {
    for (const v of list) { const f = v * n; if (Math.abs(f - Math.round(f)) > 2e-3 * Math.max(1, n / 60)) return false; }
    return true;
  };
  for (let n = 1; n <= 1000; n++) if (fits(n, arr)) return n;
  // long clips: the densest channel is normally keyed every frame -> N = 1 / (smallest gap between key times)
  const sorted = [0, ...all.sort((a, b) => a - b), 1];
  let gap = 1; for (let i = 1; i < sorted.length; i++) if (sorted[i] > sorted[i - 1]) gap = Math.min(gap, sorted[i] - sorted[i - 1]);
  const n = Math.round(1 / gap);
  return n > 1000 && n <= 100000 && fits(n, all) ? n : null;
}

// ------------------------------------------------------------------------------------------ sampling

function findKey(times, t) {
  // index i with times[i] <= t < times[i+1] (clamped)
  const n = times.length;
  if (n <= 1 || t <= times[0]) return 0;
  if (t >= times[n - 1]) return n - 1;
  let lo = 0, hi = n - 1;
  while (hi - lo > 1) { const m = (lo + hi) >> 1; if (times[m] <= t) lo = m; else hi = m; }
  return lo;
}

function lerpChannel(times, vals, stride, t, out) {
  const n = times.length;
  const i = findKey(times, t);
  if (i >= n - 1 || times[i + 1] === times[i] || t <= times[i]) {
    for (let c = 0; c < stride; c++) out[c] = vals[i * stride + c];
    return out;
  }
  const a = (t - times[i]) / (times[i + 1] - times[i]);
  for (let c = 0; c < stride; c++) out[c] = vals[i * stride + c] * (1 - a) + vals[(i + 1) * stride + c] * a;
  return out;
}

function slerpChannel(times, vals, t, out) {
  const n = times.length;
  const i = findKey(times, t);
  const o = i * 4;
  if (i >= n - 1 || times[i + 1] === times[i] || t <= times[i]) {
    out[0] = vals[o]; out[1] = vals[o + 1]; out[2] = vals[o + 2]; out[3] = vals[o + 3];
    return out;
  }
  const a = (t - times[i]) / (times[i + 1] - times[i]);
  let bx = vals[o + 4], by = vals[o + 5], bz = vals[o + 6], bw = vals[o + 7];
  let ax = vals[o], ay = vals[o + 1], az = vals[o + 2], aw = vals[o + 3];
  // defensive normalisation (parseAnim already normalises; hand-built tracks may not)
  const la = Math.hypot(ax, ay, az, aw) || 1, lb = Math.hypot(bx, by, bz, bw) || 1;
  ax /= la; ay /= la; az /= la; aw /= la; bx /= lb; by /= lb; bz /= lb; bw /= lb;
  let cos = ax * bx + ay * by + az * bz + aw * bw;
  if (cos < 0) { cos = -cos; bx = -bx; by = -by; bz = -bz; bw = -bw; } // shortest arc
  let k0, k1;
  if (cos > 0.9995) { k0 = 1 - a; k1 = a; } else {
    const th = Math.acos(Math.min(1, cos)), s = Math.sin(th);
    k0 = Math.sin((1 - a) * th) / s; k1 = Math.sin(a * th) / s;
  }
  out[0] = ax * k0 + bx * k1; out[1] = ay * k0 + by * k1; out[2] = az * k0 + bz * k1; out[3] = aw * k0 + bw * k1;
  const l = Math.hypot(out[0], out[1], out[2], out[3]) || 1;
  out[0] /= l; out[1] /= l; out[2] /= l; out[3] /= l;
  return out;
}

/**
 * Map every track to a skeleton bone index (exact name, then case-insensitive, then alias). -1 = no such bone.
 * Cached on the anim object per skeleton.
 */
export function bindAnimToSkel(anim, skel) {
  if (anim._bindSkel === skel && anim._bind) return anim._bind;
  const map = anim.tracks.map(t => findBone(skel, t.name));
  anim._bindSkel = skel; anim._bind = map;
  return map;
}

/**
 * Sample the animation at normalised time t in [0,1] (use t = seconds / TimeLength, wrap for loops).
 * Bones without a track keep their bind pose (skel position/rotation/scale).
 * Interpolation: linear (position, scale matrix), shortest-arc slerp (rotation); clamped at the ends.
 * @returns {{ positions: Float32Array(3n), rotations: Float32Array(4n), scales: Float32Array(16n),
 *            local: Float32Array(16n) (L = S*R*T), model: Float32Array(16n) (L * parent model),
 *            skin: Float32Array(16n) (invBind * model, the skinning matrix for vertices in bind/model space) }}
 *   All matrices are D3D row-major (row-vector convention, file frame). For three.js use toThreeMatrix().
 */
export function sampleAnim(anim, skel, t, opts = {}) {
  const n = skel.bones.length;
  const bind = bindAnimToSkel(anim, skel);
  const positions = new Float32Array(n * 3), rotations = new Float32Array(n * 4), scales = new Float32Array(n * 16);
  for (let i = 0; i < n; i++) {
    const b = skel.bones[i];
    positions.set(b.position, i * 3); rotations.set(b.rotation, i * 4); scales.set(b.scaleMatrix, i * 16);
  }
  const tp = new Float32Array(3), tq = new Float32Array(4), ts = new Float32Array(16);
  anim.tracks.forEach((tr, ti) => {
    const bi = bind[ti];
    if (bi < 0) return;
    if (tr.posTimes.length) positions.set(lerpChannel(tr.posTimes, tr.positions, 3, t, tp), bi * 3);
    if (tr.rotTimes.length) rotations.set(slerpChannel(tr.rotTimes, tr.rotations, t, tq), bi * 4);
    if (tr.sclTimes.length) scales.set(lerpChannel(tr.sclTimes, tr.scales, 16, t, ts), bi * 16);
  });
  const local = new Float32Array(n * 16), model = new Float32Array(n * 16), skin = opts.skin === false ? null : new Float32Array(n * 16);
  const L = new Float32Array(16), M = new Float32Array(16);
  for (let i = 0; i < n; i++) {
    composeLocal(positions.subarray(i * 3, i * 3 + 3), rotations.subarray(i * 4, i * 4 + 4), scales.subarray(i * 16, i * 16 + 16), L);
    local.set(L, i * 16);
    const p = skel.bones[i].parent;
    if (p >= 0) mat4Multiply(L, model.subarray(p * 16, p * 16 + 16), M); else M.set(L);
    model.set(M, i * 16);
    if (skin) {
      const ib = skel.bones[i].invBind;
      if (ib) skin.set(mat4Multiply(ib, M), i * 16); else skin.set(mat4Identity(), i * 16);
    }
  }
  return { positions, rotations, scales, local, model, skin };
}

function rawRootMotion(rm, t) {
  const out = [0, 0, 0];
  if (!rm) return out;
  if (rm.times.length) {
    const packed = new Float32Array(rm.times.length * 2), xz = new Float32Array(2);
    for (let i = 0; i < rm.times.length; i++) { packed[i * 2] = rm.x[i]; packed[i * 2 + 1] = rm.z[i]; }
    lerpChannel(rm.times, packed, 2, t, xz);
    out[0] = xz[0]; out[2] = xz[1];
  }
  if (rm.yTimes && rm.yTimes.length) out[1] = lerpChannel(rm.yTimes, rm.y, 1, t, new Float32Array(1))[0];
  return out;
}

/**
 * Root-motion displacement [x, y, z] SINCE THE START OF THE CLIP (file frame, MODEL space: rotate by the entity's
 * facing before adding to its world position; forward is -Z) at normalised time t, linear interpolation, clamped.
 * [0,0,0] when absent. The per-bone tracks already have this displacement removed (Bip01 stays in place).
 *
 * The stored curve does NOT always start at 0: 1,692 of 15,659 files start where the previous clip of an authored
 * combo ended (e.g. character/warrior/skill/bgw_skl_ncl_tempestwing05 starts at z = -13.48 and ends at -15.71,
 * share/movecache.csv lists the same Start/End). The entity must only move by the difference, so by default the
 * value at the first key is subtracted; pass { absolute: true } for the raw stored curve.
 */
export function sampleRootMotion(anim, t, opts = {}) {
  const rm = anim.rootMotion;
  const out = rawRootMotion(rm, t);
  if (opts.absolute || !rm) return out;
  const o = rawRootMotion(rm, -Infinity); // first keys
  out[0] -= o[0]; out[1] -= o[1]; out[2] -= o[2];
  return out;
}
