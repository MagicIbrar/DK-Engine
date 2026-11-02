// ModelCache: .mesh / .skel / .anim -> three.js objects (docs/ARCHITECTURE.md §3.2).
//
// THE MIRROR RULE: everything here is raw FILE-frame data (parseMesh default, raw D3DX quaternions, raw skeleton TRS).
// Instances are meant to live under game.worldRoot (scale z = -1); three.js flips the front face for the negative
// determinant, so there is no winding swap and no z negation anywhere in this file.
//
// Static models   loadStatic(meshKey, opts) -> StaticModel: one BufferGeometry + one material per mesh entry, shared by
//                 every instance; instantiate() -> Group, createInstanced(n) -> one InstancedMesh per mesh entry.
// Skinned models  loadSkinned({skelKey, parts}) -> SkinnedModel: ONE skeleton (THREE.Bone per .skel bone, local
//                 transform = raw position / quaternion / the 3x3 stretch matrix: its diagonal as bone.scale, its
//                 off-diagonal terms as bone.shear, see BoneShear) + an identity root bone for the influences-0
//                 vertices (mesh.js skin.staticIndex) and for palette bones the skeleton lacks.
//                 instantiate() -> SkinnedInstance (own bones + skeleton, shared geometry + materials).
// Clips           loadClip(animKey, model, {duration}) -> THREE.AnimationClip (normalised key times x duration):
//                 .position / .quaternion / .scale (+ .shear where the stretch is not diagonal) per bone.
// Verified against the reference file-frame skinning (anim.js sampleAnim) for every spawned monster and placed NPC
// type and all 15 classes: node tools/test-render.mjs [--all].
import * as THREE from 'three';
import { tryFetchBuffer, normPath } from './assets.js';
import { parseMesh } from '../formats/mesh.js';
import { parseSkel, findBone } from '../formats/skel.js';
import { parseAnim, AUTHORING_FPS } from '../formats/anim.js';
import { parseTpack, resolveTexture, tpackPathForMesh } from '../formats/tpack.js';
import { hasObjectTangentBasis, patchObjectNormalBasis } from './object-normal.js';
import { breathe } from './yield.js';
import { assetWork } from './asset-work.js';
import { decodeText } from '../formats/binreader.js';
import { patchSpecular, reapplySpecular, glowCandidates, GLOW_COLOR, loadEnvironmentCube } from './matfx.js';
import { parseWingAssetKey } from '../content/wings-catalog.js';
import { ITEM_GLASS_CHOSEN } from '../config/engine-chosen-item-glass.js';
import { gfxB } from '../config/gfx-b-switches.js'; // gfx-B2
import { globalAlphaMode, isDdsFormat, parseDxtAlphaFilterTable, DXT_ALPHA_FILTER_TABLE } from './global-alpha-modes.js'; // LANE-54

export const STATIC_BONE_NAME = '__dk_static_root';
const IDENTITY = new THREE.Matrix4();

// Some animated weapons author root-space effect/weapon lines alongside their
// skinned surface. Preserve only explicitly rigid lines; weighted lines need a
// separate bone evaluation before they can safely serve as effect attachments.
export function rigidModelLines(parsed) {
  return (parsed?.lines || []).filter(line => !(line.bonePalette?.length) &&
    line.strips?.length && line.strips.every(strip => strip.skinRaw &&
      strip.skinRaw.length === strip.positions.length / 3 * 4 && !strip.skinRaw.some(value => value !== 0)))
    .map(line => ({ name: line.name, strips: line.strips.map(strip => strip.positions) }));
}

// ---------------------------------------------------------------------------------------------- matrix freezing
// three r170's Object3D.updateMatrixWorld recurses into EVERY child each frame (matrixWorldAutoUpdate = false only skips
// that node's own multiply, the subtree below is still composed and multiplied). A frozen subtree gets an own no-op
// updateMatrixWorld instead, so the renderer's per-frame scene update skips it entirely. Used for hidden (culled) actors,
// animation-LOD frames of standing bodies (SkinnedInstance.freeze) and static map geometry (objects.js / graphics).
function frozenUpdateMatrixWorld() { /* frozen: matrices stay as they are */ }
/**
 * Freeze (true) or unfreeze (false) the matrices of a subtree. compute: bring them up to date first (static geometry
 * that was never rendered); false keeps the ones of the last render (animation-LOD frames).
 */
/**
 * gfx-B2 round 3 (switch scrollAlphaBlend): a UV-scrolling map object (object table uvx/uvy/uvspeed) whose texture alpha is
 * smooth is drawn alpha blended like the table's transparent flag path (depthWrite off, alphaTest 0.02) instead of the
 * engine's alphaTest 0.5 cut-out. Evidence: Global g195 fountain jets (sbs-9). Light shafts keep A2's additive material.
 */
export function scrollAlphaBlend(mat) {
  if (!gfxB('scrollAlphaBlend') || !mat || mat.transparent || mat.userData?.dkLightShaft || mat.userData?.alphaKind !== 'smooth') return mat;
  mat.transparent = true; mat.depthWrite = false; mat.alphaTest = 0.02; mat.needsUpdate = true;
  mat.userData = { ...mat.userData, dkScrollAlphaBlend: true };
  return mat;
}

export function freezeMatrices(obj, on = true, compute = true) {
  if (!obj) return;
  const frozen = obj.updateMatrixWorld === frozenUpdateMatrixWorld;
  if (!on) { if (frozen) delete obj.updateMatrixWorld; return; }
  if (frozen && !compute) return;
  if (frozen) delete obj.updateMatrixWorld;
  if (compute) {
    obj.parent?.updateWorldMatrix(true, false);
    obj.updateMatrixWorld(true);
  }
  obj.updateMatrixWorld = frozenUpdateMatrixWorld;
}
export function isFrozen(obj) { return !!obj && obj.updateMatrixWorld === frozenUpdateMatrixWorld; }
/**
 * Skeleton.update that skips the bone matrices / bone texture upload while the body is frozen, and that does NOT re-upload the
 * bone texture when the pose it computed is bit-for-bit the one already in the texture (opt-4, measured: in the town the aura pass
 * and every animation-LOD-skipped rig re-ran three's update on an unchanged pose and re-uploaded it: ~75 % of the skeleton updates of a
 * frame were identical, each one a texSubImage2D + ~10 state calls).
 * Same numbers as THREE.Skeleton.prototype.update (r170): offset = bone.matrixWorld x boneInverse, 4x4 multiplyMatrices in the same
 * operation order, stored as float32. Differences, all invisible to the shader: (1) it writes straight into boneMatrices (no
 * Matrix4 temp + toArray); (2) a bone world matrix with the affine last row (0, 0, 0, 1) - every THREE.Bone - gets its offset last
 * row copied from the inverse (the 4 terms of the general product are 0 * x + 0 * x + 0 * x + 1 * inverse, = inverse exactly);
 * (3) boneTexture.needsUpdate is set only when a stored float actually changed. tools/test-actors-opt4.mjs compares it with
 * the three implementation on random and real skeletons.
 */
const _IDENT = IDENTITY.elements;
export function skeletonUpdateUnlessFrozen() {
  if (this._dkFrozen) return;
  const bones = this.bones, inv = this.boneInverses, out = this.boneMatrices;
  let changed = false, f = 0;
  for (let i = 0, n = bones.length; i < n; i++) {
    const bone = bones[i];
    const a = bone ? bone.matrixWorld.elements : _IDENT, b = inv[i].elements, o = i * 16;
    const a11 = a[0], a12 = a[4], a13 = a[8], a14 = a[12];
    const a21 = a[1], a22 = a[5], a23 = a[9], a24 = a[13];
    const a31 = a[2], a32 = a[6], a33 = a[10], a34 = a[14];
    const b11 = b[0], b12 = b[4], b13 = b[8], b14 = b[12];
    const b21 = b[1], b22 = b[5], b23 = b[9], b24 = b[13];
    const b31 = b[2], b32 = b[6], b33 = b[10], b34 = b[14];
    const b41 = b[3], b42 = b[7], b43 = b[11], b44 = b[15];
    if (out[o] !== (f = Math.fround(a11 * b11 + a12 * b21 + a13 * b31 + a14 * b41))) { out[o] = f; changed = true; }
    if (out[o + 4] !== (f = Math.fround(a11 * b12 + a12 * b22 + a13 * b32 + a14 * b42))) { out[o + 4] = f; changed = true; }
    if (out[o + 8] !== (f = Math.fround(a11 * b13 + a12 * b23 + a13 * b33 + a14 * b43))) { out[o + 8] = f; changed = true; }
    if (out[o + 12] !== (f = Math.fround(a11 * b14 + a12 * b24 + a13 * b34 + a14 * b44))) { out[o + 12] = f; changed = true; }
    if (out[o + 1] !== (f = Math.fround(a21 * b11 + a22 * b21 + a23 * b31 + a24 * b41))) { out[o + 1] = f; changed = true; }
    if (out[o + 5] !== (f = Math.fround(a21 * b12 + a22 * b22 + a23 * b32 + a24 * b42))) { out[o + 5] = f; changed = true; }
    if (out[o + 9] !== (f = Math.fround(a21 * b13 + a22 * b23 + a23 * b33 + a24 * b43))) { out[o + 9] = f; changed = true; }
    if (out[o + 13] !== (f = Math.fround(a21 * b14 + a22 * b24 + a23 * b34 + a24 * b44))) { out[o + 13] = f; changed = true; }
    if (out[o + 2] !== (f = Math.fround(a31 * b11 + a32 * b21 + a33 * b31 + a34 * b41))) { out[o + 2] = f; changed = true; }
    if (out[o + 6] !== (f = Math.fround(a31 * b12 + a32 * b22 + a33 * b32 + a34 * b42))) { out[o + 6] = f; changed = true; }
    if (out[o + 10] !== (f = Math.fround(a31 * b13 + a32 * b23 + a33 * b33 + a34 * b43))) { out[o + 10] = f; changed = true; }
    if (out[o + 14] !== (f = Math.fround(a31 * b14 + a32 * b24 + a33 * b34 + a34 * b44))) { out[o + 14] = f; changed = true; }
    if (a[3] === 0 && a[7] === 0 && a[11] === 0 && a[15] === 1) {   // affine world matrix: last row of the product = last row of the inverse
      if (out[o + 3] !== (f = Math.fround(b41))) { out[o + 3] = f; changed = true; }
      if (out[o + 7] !== (f = Math.fround(b42))) { out[o + 7] = f; changed = true; }
      if (out[o + 11] !== (f = Math.fround(b43))) { out[o + 11] = f; changed = true; }
      if (out[o + 15] !== (f = Math.fround(b44))) { out[o + 15] = f; changed = true; }
    } else {
      const a41 = a[3], a42 = a[7], a43 = a[11], a44 = a[15];
      if (out[o + 3] !== (f = Math.fround(a41 * b11 + a42 * b21 + a43 * b31 + a44 * b41))) { out[o + 3] = f; changed = true; }
      if (out[o + 7] !== (f = Math.fround(a41 * b12 + a42 * b22 + a43 * b32 + a44 * b42))) { out[o + 7] = f; changed = true; }
      if (out[o + 11] !== (f = Math.fround(a41 * b13 + a42 * b23 + a43 * b33 + a44 * b43))) { out[o + 11] = f; changed = true; }
      if (out[o + 15] !== (f = Math.fround(a41 * b14 + a42 * b24 + a43 * b34 + a44 * b44))) { out[o + 15] = f; changed = true; }
    }
  }
  if (changed && this.boneTexture !== null) this.boneTexture.needsUpdate = true;
}

// ---------------------------------------------------------------------------------------------- sheared bones
// A .skel / .anim scale channel is a full 3x3 "stretch" matrix; 147 skeletons and 145 anims have off-diagonal terms
// (e.g. monster/zombihost), which three's position/quaternion/scale cannot express. Every bone therefore carries a
// `shear` property (the 6 off-diagonal terms, D3D array indices 1,2,4,6,8,9) that AnimationClip tracks drive like any
// other property (the mixer lerps and cross-fades it, exactly like the game lerps the matrix), and an updateMatrix
// that composes T * R * S with the full stretch when the shear is non-zero. Column-major three elements of S are the
// D3D row-major array itself (S is applied first in both conventions; see skel.js composeLocal).
export const SHEAR_INDICES = [1, 2, 4, 6, 8, 9];

export class BoneShear {
  constructor() { this.v = new Float32Array(6); this.isBoneShear = true; }
  fromArray(a, o = 0) { const v = this.v; for (let i = 0; i < 6; i++) v[i] = a[o + i]; return this; }
  toArray(a = [], o = 0) { const v = this.v; for (let i = 0; i < 6; i++) a[o + i] = v[i]; return a; }
  copy(s) { this.v.set(s.v); return this; }
  clone() { return new BoneShear().copy(this); }
  isZero() { const v = this.v; return v[0] === 0 && v[1] === 0 && v[2] === 0 && v[3] === 0 && v[4] === 0 && v[5] === 0; }
}

const _rotM = new THREE.Matrix4();
/** m = T(p) * R(q) * S, S = diag(scale) + shear (off-diagonals, D3D layout). */
export function composeSheared(m, p, q, scale, shear) {
  const r = _rotM.makeRotationFromQuaternion(q).elements;
  const s = shear.v;
  const te = m.elements;
  // columns of S (three column-major == D3D row-major array)
  const c = [scale.x, s[0], s[1], s[2], scale.y, s[3], s[4], s[5], scale.z];
  for (let j = 0; j < 3; j++) {
    const a = c[j * 3], b = c[j * 3 + 1], d = c[j * 3 + 2];
    te[j * 4] = r[0] * a + r[4] * b + r[8] * d;
    te[j * 4 + 1] = r[1] * a + r[5] * b + r[9] * d;
    te[j * 4 + 2] = r[2] * a + r[6] * b + r[10] * d;
    te[j * 4 + 3] = 0;
  }
  te[12] = p.x; te[13] = p.y; te[14] = p.z; te[15] = 1;
  return m;
}

// Native animation drives quaternion tracks. Object3D normally converts every
// quaternion write back into Euler angles, even though matrix composition uses
// the quaternion directly. Defer only that conversion until an Euler field is
// read or edited; ordinary rotation setters, orders, copies and serialization
// retain the same behavior. Shared descriptors avoid per-bone getter closures.
const quaternionEulerStates=new WeakMap(),quaternionEulerDescriptors={};
function syncQuaternionEuler(state){
  if(state.dirty&&!state.syncing){state.syncing=true;try{state.rotation.setFromQuaternion(state.quaternion,undefined,false);state.dirty=false;}finally{state.syncing=false;}}
}
for(const key of ['_x','_y','_z','_order'])quaternionEulerDescriptors[key]={configurable:true,enumerable:true,
  get(){const state=quaternionEulerStates.get(this);syncQuaternionEuler(state);return state[key];},
  set(value){const state=quaternionEulerStates.get(this);if(!state.syncing)syncQuaternionEuler(state);state[key]=value;}
};
export function installQuaternionBoneEuler(bone){
  const rotation=bone.rotation,quaternion=bone.quaternion;
  if(quaternionEulerStates.has(rotation))return bone;
  // This adapter is specific to the bundled Three Euler layout. Other layouts
  // keep Object3D's original eager synchronization rather than guessing.
  if(typeof quaternion?._onChange!=='function'||Object.keys(quaternionEulerDescriptors).some(key=>Object.getOwnPropertyDescriptor(rotation,key)?.configurable!==true))return bone;
  const state={rotation,quaternion,dirty:false,syncing:false,_x:rotation._x,_y:rotation._y,_z:rotation._z,_order:rotation._order};
  quaternionEulerStates.set(rotation,state);Object.defineProperties(rotation,quaternionEulerDescriptors);
  quaternion._onChange(()=>{state.dirty=true;});return bone;
}

function shearedUpdateMatrix() {
  if (this.shear.isZero()) this.matrix.compose(this.position, this.quaternion, this.scale);
  else composeSheared(this.matrix, this.position, this.quaternion, this.scale, this.shear);
  this.matrixWorldNeedsUpdate = true;
}

/** Give an Object3D (bone) the shear property + full-stretch updateMatrix. */
export function makeShearable(o, rest) {
  installQuaternionBoneEuler(o);
  o.shear = new BoneShear();
  if (rest) o.shear.fromArray(rest);
  o.updateMatrix = shearedUpdateMatrix;
  return o;
}

const warned = new Set();
function warnOnce(key, msg) {
  if (warned.has(key)) return;
  warned.add(key);
  console.warn(`[models] ${msg}`);
}

const flag = v => v === true || Number(v) > 0 || v === '1';
// Only an explicit false/0 disables fog; missing table flags preserve the normal material default.
export const materialFog = v => !(v === false || v === 0 || v === '0');

/**
 * Normalise the accepted explicit-texture shapes to Map(slot -> [data keys]):
 *   [{material, diffuse}]            (classes.json parts / weapon)
 *   ['texture/a.dds', null, ...]     (index = material slot)
 *   { diffuse: [...] }               (monsters.json / npcs.json shapes: textures.diffuse[slot])
 *   { 0: 'texture/a.dds', ... }      (slot map)
 */
function normalizeTextures(textures) {
  const out = new Map();
  if (!textures) return out;
  const add = (slot, key) => {
    if (!key) return;
    const s = Number(slot);
    if (!Number.isFinite(s)) return;
    if (!out.has(s)) out.set(s, []);
    for (const k of Array.isArray(key) ? key : [key]) if (k) out.get(s).push(k);
  };
  if (Array.isArray(textures)) {
    textures.forEach((t, i) => {
      if (t && typeof t === 'object' && !Array.isArray(t)) add(t.material ?? i, t.diffuse ?? t.key ?? t.texture);
      else add(i, t);
    });
  } else if (typeof textures === 'object') {
    if (Array.isArray(textures.diffuse)) textures.diffuse.forEach((t, i) => add(i, t));
    else for (const [k, v] of Object.entries(textures)) if (/^\d+$/.test(k)) add(k, v);
  }
  return out;
}

/** Map(slot -> [keys]) of a non-diffuse kind ('specular' | 'glow') from the explicit texture shapes above. */
function normalizeTextureKind(textures, kind) {
  const out = new Map();
  if (!textures || typeof textures !== 'object') return out;
  const add = (slot, key) => {
    const s = Number(slot);
    if (!key || !Number.isFinite(s)) return;
    if (!out.has(s)) out.set(s, []);
    for (const k of Array.isArray(key) ? key : [key]) if (k) out.get(s).push(k);
  };
  if (Array.isArray(textures)) textures.forEach((t, i) => { if (t && typeof t === 'object' && !Array.isArray(t)) add(t.material ?? i, t[kind]); });
  else if (Array.isArray(textures[kind])) textures[kind].forEach((t, i) => add(i, t));
  return out;
}

function box3FromMinMax(min, max) {
  return new THREE.Box3(new THREE.Vector3().fromArray(min), new THREE.Vector3().fromArray(max));
}

function tightBox(positions) {
  const b = new THREE.Box3();
  const v = new THREE.Vector3();
  for (let i = 0; i + 2 < positions.length; i += 3) {
    v.set(positions[i], positions[i + 1], positions[i + 2]);
    if (Number.isFinite(v.x) && Number.isFinite(v.y) && Number.isFinite(v.z)) b.expandByPoint(v);
  }
  return b;
}

function baseGeometry(m) {
  const g = new THREE.BufferGeometry();
  g.setAttribute('position', new THREE.BufferAttribute(m.positions, 3));
  g.setAttribute('normal', new THREE.BufferAttribute(m.normals, 3));
  g.setAttribute('uv', new THREE.BufferAttribute(m.uv0, 2));
  if (hasObjectTangentBasis(m)) g.setAttribute('tangent', new THREE.BufferAttribute(m.tangents, 4));
  g.setIndex(new THREE.BufferAttribute(m.indices, 1));
  g.boundingBox = box3FromMinMax(m.bbox.min, m.bbox.max);
  g.boundingSphere = g.boundingBox.getBoundingSphere(new THREE.Sphere());
  return g;
}

// ============================================================================================ StaticModel
export class StaticModel {
  constructor({ key, parts, bbox, helpers, helperList, lines, flags }) {
    this.key = key;
    this.parts = parts;                    // [{ name, slot, geometry, material, texture }]
    this.bbox = bbox;                      // THREE.Box3, FILE frame
    this.center = bbox.getCenter(new THREE.Vector3());
    this.radius = bbox.isEmpty() ? 0 : bbox.getBoundingSphere(new THREE.Sphere()).radius;
    this.height = bbox.isEmpty() ? 0 : bbox.max.y;
    this.helpers = helpers;                // { name: { min:[x,y,z], max:[x,y,z] } } tight boxes (FILE frame), merged per name
    this.helperList = helperList;          // [{ name, min, max, positions, indices }] every helper, raw triangles (e.g. 'ground*')
    this.lines = lines;                    // [{ name, strips:[Float32Array positions] }] weapon-trail polylines
    this.flags = flags;
  }

  /** New Object3D (Group of Meshes) sharing this model's geometry and materials. */
  instantiate() {
    const g = new THREE.Group();
    g.name = `static:${this.key}`;
    for (const p of this.parts) {
      const mesh = new THREE.Mesh(p.geometry, p.material);
      mesh.name = `part:${p.name}`;
      g.add(mesh);
    }
    g.userData.model = this;
    return g;
  }

  /**
   * One InstancedMesh per mesh entry, capacity `count`. Instance matrices are FILE-frame (e.g. from .mol placements).
   * Instances with a negative determinant (mirrored placements) cannot share an InstancedMesh (three.js decides the
   * front face per draw call), so finish() turns them into ordinary Meshes; zero-scale instances are skipped.
   * @returns {{object:THREE.Group, meshes:THREE.InstancedMesh[], setMatrixAt(i:number, m:THREE.Matrix4):void,
   *            finish(count?:number):number, dispose():void}}
   */
  createInstanced(count) {
    const cap = Math.max(1, count | 0);
    const object = new THREE.Group();
    object.name = `instanced:${this.key}`;
    object.userData.model = this;
    const meshes = this.parts.map(p => {
      const im = new THREE.InstancedMesh(p.geometry, p.material, cap);
      im.name = `part:${p.name}`;
      im.count = 0;
      object.add(im);
      return im;
    });
    const data = new Float32Array(cap * 16);
    const used = new Uint8Array(cap);
    let mirrored = [];
    const tmp = new THREE.Matrix4();
    return {
      object, meshes,
      setMatrixAt(i, m) {
        if (i < 0 || i >= cap) return;
        m.toArray(data, i * 16);
        used[i] = 1;
      },
      finish: (n = cap) => {
        for (const o of mirrored) object.remove(o);
        mirrored = [];
        let k = 0;
        for (let i = 0; i < Math.min(n, cap); i++) {
          if (!used[i]) continue;
          tmp.fromArray(data, i * 16);
          const det = tmp.determinant();
          if (!Number.isFinite(det) || Math.abs(det) < 1e-12) continue;
          if (det < 0) {
            for (const p of this.parts) {
              const mesh = new THREE.Mesh(p.geometry, p.material);
              mesh.name = `mirrored:${p.name}`;
              mesh.matrixAutoUpdate = false;
              mesh.matrix.copy(tmp);
              object.add(mesh);
              mirrored.push(mesh);
            }
            continue;
          }
          for (const im of meshes) im.setMatrixAt(k, tmp);
          k++;
        }
        for (const im of meshes) {
          im.count = k;
          im.instanceMatrix.needsUpdate = true;
          im.visible = k > 0;
          if (k > 0) im.computeBoundingSphere();
        }
        return k;
      },
      dispose() {
        for (const im of meshes) im.dispose();
        object.removeFromParent();
      },
    };
  }
}

// ============================================================================================ SkinnedModel
export class SkinnedModel {
  constructor({ skelKey, skel, bones, boneNames, boneInverses, parts, bbox, missingSkeleton, partKeys, missingPartKeys = [], lines = [] }) {
    this.skelKey = skelKey;
    this.skel = skel;                     // parsed .skel (null when the skeleton is missing -> bind pose only)
    this._bones = bones;                  // [{ name, rawName, parent, p:[3], q:[4], s:[3] diag, sh:[6]|null off-diag }]
    this.boneNames = boneNames;           // sanitised THREE names, skeleton order (the track names of every clip)
    this._boneInverses = boneInverses;    // Matrix4[] incl. the identity static root (last)
    this.parts = parts;                   // [{ name, meshKey, slot, geometry, material, texture, missingBones }]
    this.partKeys = partKeys;
    this.missingPartKeys = missingPartKeys;
    this.lines = lines;
    this.bbox = bbox;                     // bind-pose Box3 (FILE frame)
    this.height = bbox.isEmpty() ? 0 : bbox.max.y;
    const size = bbox.isEmpty() ? new THREE.Vector3() : bbox.getSize(new THREE.Vector3());
    this.radius = 0.5 * Math.max(size.x, size.z);           // horizontal half-extent (bind pose)
    this.sphere = bbox.isEmpty() ? new THREE.Sphere(new THREE.Vector3(), 1) : bbox.getBoundingSphere(new THREE.Sphere());
    this.missingSkeleton = !!missingSkeleton;
    this.empty = parts.length === 0;      // mesh files exist but hold no geometry (invisible monsters): nothing to draw
    this._rawIndex = new Map();
    bones.forEach((b, i) => { if (!this._rawIndex.has(b.rawName)) this._rawIndex.set(b.rawName, i); });
  }

  /** Skeleton bone index of a bone name (raw game name or sanitised name; exact, case-insensitive, alias). -1 if absent. */
  boneIndex(name) {
    if (name == null) return -1;
    if (this._rawIndex.has(name)) return this._rawIndex.get(name);
    let i = this.boneNames.indexOf(name);
    if (i >= 0) return i;
    if (this.skel) { i = findBone(this.skel, name); if (i >= 0) return i; }
    const l = String(name).toLowerCase();
    return this.boneNames.findIndex(n => n.toLowerCase() === l);
  }

  instantiate() {
    const root = new THREE.Group();
    root.name = `skinned:${this.skelKey || 'none'}`;
    const bones = this._bones.map(b => {
      const bone = makeShearable(new THREE.Bone(), b.sh);
      bone.name = b.name;
      bone.position.fromArray(b.p);
      bone.quaternion.fromArray(b.q);
      bone.scale.fromArray(b.s);
      return bone;
    });
    this._bones.forEach((b, i) => (b.parent >= 0 ? bones[b.parent] : root).add(bones[i]));
    const staticBone = new THREE.Bone();
    staticBone.name = STATIC_BONE_NAME;
    root.add(staticBone);
    const skeleton = new THREE.Skeleton(bones.concat(staticBone), this._boneInverses.map(m => m.clone()));
    skeleton.update = skeletonUpdateUnlessFrozen;
    const meshes = this.parts.map(p => {
      const mesh = new THREE.SkinnedMesh(p.geometry, p.material);
      mesh.name = `part:${p.name}`;
      mesh.bind(skeleton, IDENTITY);
      // Culling sphere from the bind pose with generous slack: never derive bounds from animated poses (die clips
      // sink the root far below the ground on purpose).
      mesh.boundingSphere = new THREE.Sphere(this.sphere.center.clone(), this.sphere.radius * 1.6 + 0.5);
      root.add(mesh);
      return mesh;
    });
    root.userData.model = this;
    return new SkinnedInstance(this, root, skeleton, bones, staticBone, meshes);
  }
}

// ============================================================================================ SkinnedInstance
export class SkinnedInstance {
  constructor(model, root, skeleton, bones, staticBone, meshes) {
    this.model = model;
    this.root = root;                     // feet at origin, faces local -Z, FILE frame
    this.skeleton = skeleton;
    this.bones = bones;
    this.staticBone = staticBone;
    this.meshes = meshes;
    this.boneByName = new Map();
    bones.forEach((b, i) => {
      if (!this.boneByName.has(b.name)) this.boneByName.set(b.name, b);
      const raw = model._bones[i].rawName;
      if (!this.boneByName.has(raw)) this.boneByName.set(raw, b);
    });
    this._attached = new Set();
    this._own = null;                     // per-instance material clones (created on first setOpacity/setHighlight)
    this._opacity = 1;
    this._highlight = null;
    root.userData.instance = this;
  }

  get height() { return this.model.height; }
  get bbox() { return this.model.bbox; }

  /** Change equipment without replacing the wearer's bones, mixer or unchanged meshes. */
  replaceParts(model) {
    if (!model || model.missingSkeleton || this.model.skel !== model.skel || this.model.skelKey !== model.skelKey) return false;
    const available = this.model.parts.map((part, i) => ({ part, mesh: this.meshes[i] }));
    const meshes = model.parts.map(part => {
      const i = available.findIndex(old => old.part.meshKey === part.meshKey && old.part.name === part.name && old.part.slot === part.slot && old.part.material === part.material);
      if (i >= 0) return available.splice(i, 1)[0].mesh;
      const mesh = new THREE.SkinnedMesh(part.geometry, part.material);
      mesh.name = `part:${part.name}`;
      mesh.bind(this.skeleton, IDENTITY);
      mesh.castShadow = true; mesh.receiveShadow = false;
      mesh.boundingSphere = new THREE.Sphere(model.sphere.center.clone(), model.sphere.radius * 1.6 + 0.5);
      this.root.add(mesh);
      if (this._own) this._adopt(mesh);
      if (this._frozen) freezeMatrices(mesh, true, false);
      return mesh;
    });
    for (const { mesh } of available) {
      mesh.removeFromParent();
      const own = this._own?.get(mesh);
      if (own) { mesh.material = own.shared; own.mat.dispose(); this._own.delete(mesh); }
    }
    this.meshes = meshes;
    this.model = model;
    this.root.userData.model = model;
    return true;
  }

  /** THREE.Bone by raw game name or sanitised name (case-insensitive / alias fallback). */
  getBone(name) {
    if (name == null) return null;
    const b = this.boneByName.get(name);
    if (b) return b;
    const i = this.model.boneIndex(name);
    return i >= 0 ? this.bones[i] : null;
  }

  /**
   * Rigidly attach an object to a bone (weapons: their vertices are in the bone's local frame, classes.json
   * conventions.weaponAttach, so no offset and no flip). Returns false when the bone does not exist.
   */
  attach(object3d, boneName) {
    const bone = this.getBone(boneName);
    if (!bone || !object3d) return false;
    bone.add(object3d);
    this._attached.add(object3d);
    if (this._own) this._adopt(object3d);
    return true;
  }

  detach(object3d) {
    if (!this._attached.has(object3d)) return false;
    this._attached.delete(object3d);
    object3d.removeFromParent();
    if (this._own) {
      object3d.traverse(o => {
        const e = this._own.get(o);
        if (e) { o.material = e.shared; e.mat.dispose(); this._own.delete(o); }
      });
    }
    return true;
  }

  /**
   * Animation LOD (graphics): freeze = skip this body's bone matrices and skeleton upload each frame (the pose and the
   * placement must not change while frozen - the caller unfreezes before it animates or moves the body).
   */
  freeze(on) {
    on = !!on;
    if (on === !!this._frozen) return;
    this._frozen = on;
    this.skeleton._dkFrozen = on;
    freezeMatrices(this.root, on, false);
  }
  get frozen() { return !!this._frozen; }

  /** Bone world position (THREE space) into out. */
  boneWorldPosition(name, out = new THREE.Vector3()) {
    const b = this.getBone(name);
    if (!b) return null;
    b.updateWorldMatrix(true, false);
    return out.setFromMatrixPosition(b.matrixWorld);
  }

  // ---- per-instance material state (copy-on-write: shared materials are never modified)
  _adopt(root) {
    root.traverse(o => {
      if (!o.isMesh || this._own.has(o) || Array.isArray(o.material)) return;
      const shared = o.material;
      const mat = reapplySpecular(shared, shared.clone());   // keeps the specular / env patch (matfx.js)
      o.material = mat;
      this._own.set(o, { shared, mat, transparent: shared.transparent, opacity: shared.opacity, depthWrite: shared.depthWrite,
        emissive: shared.emissive ? shared.emissive.clone() : null, color: shared.color ? shared.color.clone() : null });
    });
    this._apply();
  }

  _ensureOwn() {
    if (this._own) return;
    this._own = new Map();
    this._adopt(this.root);
  }

  _apply() {
    const a = this._opacity;
    const hl = this._highlight;
    for (const e of this._own.values()) {
      const m = e.mat;
      const wantTransparent = a < 1 ? true : e.transparent;
      if (m.transparent !== wantTransparent) { m.transparent = wantTransparent; m.needsUpdate = true; }
      m.opacity = e.opacity * a;
      m.depthWrite = a < 1 ? (a > 0.5 && e.depthWrite) : e.depthWrite;
      if (m.emissive && e.emissive) {
        if (hl) m.emissive.copy(hl).multiplyScalar(0.35).add(e.emissive); else m.emissive.copy(e.emissive);
      } else if (m.color && e.color) {
        if (hl) m.color.copy(e.color).lerp(hl, 0.3); else m.color.copy(e.color);
      }
    }
    this.root.visible = a > 0.001;
  }

  /** Fade the whole model (incl. attachments). 1 restores the shared material state. */
  setOpacity(a) {
    a = Math.max(0, Math.min(1, Number(a)));
    if (!Number.isFinite(a)) a = 1;
    if (a >= 1 && !this._own) { this._opacity = 1; this.root.visible = true; return; }
    this._opacity = a;
    this._ensureOwn();
    this._apply();
  }

  /** Emissive tint for target highlighting (THREE.Color | number | css string), or null to clear. */
  setHighlight(color) {
    if (color == null || color === false) {
      this._highlight = null;
      if (this._own) this._apply();
      return;
    }
    this._highlight = color === true ? new THREE.Color(0xffffff) : new THREE.Color(color);
    this._ensureOwn();
    this._apply();
  }

  dispose() {
    this.root.removeFromParent();
    if (this._own) for (const e of this._own.values()) e.mat.dispose();
    this._own = null;
    this._attached.clear();
    this.skeleton.dispose();
  }
}

// ---------------------------------------------------------------------------------------------- item texture guess
const _texDirs = new Map();
function textureDirList(dir) {
  if (!_texDirs.has(dir)) {
    _texDirs.set(dir, (typeof fetch === 'function' ? fetch(`/api/ls?dir=${encodeURIComponent(dir)}`).then(r => (r.ok ? r.json() : [])) : Promise.resolve([]))
      .then(list => (Array.isArray(list) ? list : []).filter(e => e && !e.dir).map(e => String(e.name).toLowerCase()))
      .catch(() => []));
  }
  return _texDirs.get(dir);
}
/** The texture of an item mesh with no usable texture list, by the mesh's own name (see _fallbackTexture). */
async function guessItemTexture(meshKey) {
  const k = normPath(meshKey || '');
  if (!k.startsWith('mesh/item/')) return null;
  const stem = k.slice(k.lastIndexOf('/') + 1).replace(/\.mesh$/, '');
  const stems = [...new Set([stem, stem.replace('_inv_', '_equ_'), stem.replace(/^inv_equ_/, 'att_equ_'), stem.replace(/_(inv|equ)_/, '_'),
    stem.replace(/^(att|inv)_inv_/, 'att_equ_'), stem.replace(/_l$/, ''), stem.replace(/^inv_/, ''), stem.replace(/_\d$/, '')])].filter(s => s.length >= 6);
  const isMap = (f) => /\.(dds|tga|bmp)$/.test(f) && !/_(s|g|n|spec|glow|bump)\.(dds|tga|bmp)$/.test(f);
  for (const dir of ['texture/item', 'texture/character', 'texture/costume']) {
    const files = await textureDirList(dir);
    for (const s of stems) {
      const exact = files.find(f => f === `${s}.dds`);
      if (exact) return `${dir}/${exact}`;
      const hits = files.filter(f => f.startsWith(s) && isMap(f)).sort((a, b) => a.length - b.length || (a < b ? -1 : 1));
      if (hits.length) return `${dir}/${hits[0]}`;
    }
  }
  return null;
}

// ============================================================================================ ModelCache
export class ModelCache {
  constructor(textures) {
    this.textures = textures;
    this._meshes = new Map();     // meshKey -> Promise<parsed mesh|null>
    this._tpacks = new Map();     // tpackKey -> Promise<parsed tpack|null>
    this._skels = new Map();      // skelKey -> Promise<parsed skel|null>
    this._static = new Map();     // meshKey|opts -> Promise<StaticModel|null>
    this._skinned = new Map();    // skelKey|parts -> Promise<SkinnedModel|null>
    this._skinnedParts = new Map(); // shared rig/part geometry across different equipment combinations
    this._clips = new Map();      // animKey|skelKey|duration -> Promise<AnimationClip|null>
    this._clipPublic = new WeakMap(); // status-bearing promise -> null-on-failure public promise
    this._materials = new Map();  // texture uuid|flags -> Material
    this._geoms = new Map();      // meshKey#index -> base BufferGeometry (static use)
    this._dxtFilter = null;       // LANE-54: Set of texture keys from script/DXTAlphaFilterTable.txt (null until loaded)
    this._dxtFilterP = null;
  }

  /** LANE-54: Global's DXTAlphaFilterTable.txt (DXT1 textures listed there get no alpha cut-out; global-alpha-modes.js). */
  dxtAlphaFilter() {
    if (this._dxtFilter) return Promise.resolve(this._dxtFilter);
    if (!this._dxtFilterP) {
      this._dxtFilterP = tryFetchBuffer(DXT_ALPHA_FILTER_TABLE).then(buf => {
        if (!buf) warnOnce('dxtfilter', `missing ${DXT_ALPHA_FILTER_TABLE}: no DXT1 texture is exempt from the alpha cut-out`);
        this._dxtFilter = parseDxtAlphaFilterTable(buf ? decodeText(new Uint8Array(buf), false) : '');
        return this._dxtFilter;
      }).catch(err => { this._dxtFilterP = null; if (err?.transient) throw err; warnOnce('dxtfilter', `bad ${DXT_ALPHA_FILTER_TABLE}: ${err && err.message || err}`); return null; });
    }
    return this._dxtFilterP;
  }

  // ---------------------------------------------------------------------------------------- raw assets
  _fetchParsed(map, key, parse, what) {
    const k = normPath(key);
    let p = map.get(k);
    if (!p) {
      p = tryFetchBuffer(k).then(async buf => {
        if (!buf) { warnOnce(k, `missing ${what} ${k}`); return null; }
        await breathe();             // time-slice parsing across frames (engine/yield.js)
        return what === 'mesh' || what === 'skeleton' ? assetWork(what, buf) : parse(buf, k);
      }).catch(err => { if (err?.transient) { if (map.get(k) === p) map.delete(k); throw err; } warnOnce(k, `bad ${what} ${k}: ${err && err.message || err}`); return null; });
      map.set(k, p);
    }
    return p;
  }

  mesh(key) { return this._fetchParsed(this._meshes, key, buf => parseMesh(buf), 'mesh'); }
  skeleton(key) { return this._fetchParsed(this._skels, key, buf => parseSkel(buf), 'skeleton'); }
  tpack(key) {
    return this._fetchParsed(this._tpacks, key, buf => parseTpack(decodeText(new Uint8Array(buf), false)), 'tpack');
  }

  /** Parsed .anim (not cached: clips are cached instead; the file buffer itself is cached by assets.js). */
  async anim(key) {
    try { return await this.animWithStatus(key); } catch { return null; }
  }

  async animWithStatus(key) {
    const k = normPath(key);
    try {
      const buf = await tryFetchBuffer(k);
      if (!buf) { warnOnce(k, `missing anim ${k}`); return null; }
      await breathe();
      return await assetWork('anim', buf);
    } catch (err) {
      if (err?.transient) throw err;
      warnOnce(k, `bad anim ${k}: ${err && err.message || err}`);
      return null;
    }
  }

  /** First tpack that exists: the explicit key, else the naming convention (tpack.js tpackPathForMesh). */
  async _resolveTpack(meshKey, tpackKey) {
    if (tpackKey === false) return null;
    const cands = tpackKey ? [tpackKey] : tpackPathForMesh(meshKey);
    for (const c of cands) {
      const k = normPath(c);
      let p = this._tpacks.get(k);
      if (!p) {
        p = tryFetchBuffer(k).then(buf => (buf ? parseTpack(decodeText(new Uint8Array(buf), false)) : null))
          .catch(error => { if (error?.transient) { if (this._tpacks.get(k) === p) this._tpacks.delete(k); throw error; } return null; });
        this._tpacks.set(k, p);
      }
      const tp = await p;
      if (tp) return tp;
    }
    if (tpackKey) warnOnce(`tp:${tpackKey}`, `missing tpack ${normPath(tpackKey)} (mesh ${normPath(meshKey)})`);
    return null;
  }

  async _textureFor(slot, { tpack, explicit, meshKey }) {
    const keys = [];
    if (explicit.has(slot)) keys.push(...explicit.get(slot));
    if (tpack) keys.push(...resolveTexture(tpack, slot, 'diffuse', { meshPath: meshKey }));
    const uniq = [...new Set(keys.map(normPath))];
    const tex = uniq.length && this.textures ? await this.textures.loadFirst(uniq) : null;
    return tex || this._fallbackTexture(slot, { tpack, explicit, meshKey });
  }

  /**
   * Specular and glow maps of a material slot (matfx.js): the explicit shapes' `specular` keys / the tpack `sN` slot,
   * and the tpack `gN` slot / the '<name>+.<ext>.glow' image of a '+' diffuse texture. Missing files resolve null
   * quietly (the tables name a few specular maps that do not ship).
   */
  async _extraMaps(slot, { tpack, textures, meshKey, diffuse, specular = true }) {
    if (!this.textures) return { spec: null, glow: null };
    const quiet = { _quiet: true };
    const list = (explicit, kind) => {
      const keys = [...(explicit.get(slot) || [])];
      if (tpack && tpack[kind] && tpack[kind][slot] != null) keys.push(...resolveTexture(tpack, slot, kind, { meshPath: meshKey }));
      return [...new Set(keys.map(normPath))];
    };
    const specKeys = specular ? list(normalizeTextureKind(textures, 'specular'), 'specular') : [];
    const glowKeys = [...list(normalizeTextureKind(textures, 'glow'), 'glow'), ...glowCandidates(diffuse?.userData?.key)];
    const [spec, glow] = await Promise.all([
      specKeys.length ? this.textures.loadFirst(specKeys, quiet).catch(() => null) : null,
      glowKeys.length ? this.textures.loadFirst(glowKeys, quiet).catch(() => null) : null,
    ]);
    return { spec: spec || null, glow: glow || null };
  }

  /**
   * A material slot that neither the tpack nor the item table names (items were drawn without colour).
   * 1. The client binds textures per subset with SetTexture and D3D keeps the last bound one, so a subset whose slot
   *    the tpack leaves out is drawn with the previous subset's texture: the nearest named slot below (else above).
   *    A slot the tpack lists with an empty name ('1 ""') stays untextured on purpose.
   * 2. Item meshes with no texture list at all, or naming files that do not ship: the texture named after the mesh
   *    (att_equ_chn_lsw_01.mesh -> texture/item/att_equ_chn_lsw_01_y.dds, bwz_equ_cot_07l -> ..._cot_07l...).
   */
  async _fallbackTexture(slot, { tpack, explicit, meshKey }) {
    if (!this.textures) return null;
    if (tpack?.empty?.diffuse?.includes(slot)) return null;
    const named = [...new Set([...explicit.keys(), ...(tpack?.slots || [])].map(Number))].filter(s => s !== slot).sort((a, b) => a - b);
    for (const s of [...named.filter(s => s < slot).reverse(), ...named.filter(s => s > slot)]) {
      const keys = [...(explicit.get(s) || []), ...(tpack ? resolveTexture(tpack, s, 'diffuse', { meshPath: meshKey }) : [])];
      const uniq = [...new Set(keys.map(normPath))];
      const tex = uniq.length ? await this.textures.loadFirst(uniq, { _quiet: true }) : null;
      if (tex) return tex;
    }
    const guess = await guessItemTexture(meshKey);
    return guess ? this.textures.load(guess) : null;
  }

  /**
   * Shared material for (texture, flags).
   *  - opaque by default; alphaTest 0.5 when the texture really has alpha (hair, foliage, armour cut-outs)
   *  - transparent (object table flag): alpha blended with depthWrite off when the texture alpha is smooth; a 1-bit
   *    (cut-out) texture is drawn alpha-tested with depth writes instead, which looks identical without sorting errors
   *  - twoSide -> DoubleSide · maxDiffuse -> unlit (MeshBasicMaterial, the game's "full-bright diffuse")
   */
  material(texture, { twoSide = false, transparent = false, alphaTest = null, maxDiffuse = false, depthWrite = null,
    specularMap = null, specKind = null, glowMap = null, fog = true, objectNormalMap = null, objectShininess = null } = {}) {
    fog = materialFog(fog);
    const ud = texture?.userData || {};
    const kind = ud.alphaKind || (ud.hasAlpha ? 'binary' : 'none');
    // specular (matfx.js): 'env' = skinned BoneAnimEnv (Lambert + env cube), 'item' = ItemMeshSpecular (Lambert + .fx specular)
    const spec = !maxDiffuse && specularMap && (specKind === 'env' || specKind === 'item') ? specKind : null;
    // itemmesh.fx (ItemMeshRender / ItemMeshSpecular) has no ShadeLighting: item meshes skip shade.js's sun fall-off
    const itemMesh = specKind === 'item' && !maxDiffuse;
    // LANE-54 globalAlphaModes: Global's per-texture draw mode (global-alpha-modes.js) when neither the table transparent path
    // nor an explicit alphaTest applies. DDS: the header format; non-DDS: the D3DX load format (textures.js userData.d3dFormat,
    // 32-bit FUN_0151e070). Images without a resolved D3DX format keep the previous handling.
    const gFormat = isDdsFormat(ud.format) ? ud.format : (ud.d3dFormat || null);
    const gMode = gfxB('globalAlphaModes') && texture && gFormat && alphaTest == null && !(transparent && kind === 'smooth')
      ? globalAlphaMode({ format: gFormat, key: ud.key, alphaKind: kind }, this._dxtFilter) : null;
    const key = [texture ? texture.uuid : 'none', twoSide ? 1 : 0, transparent ? 1 : 0, alphaTest ?? 'a',
      maxDiffuse ? 1 : 0, depthWrite ?? 'a', spec ? `${spec}:${specularMap.uuid}` : '-', glowMap ? glowMap.uuid : '-', fog ? 1 : 0, itemMesh ? 'i' : '', !maxDiffuse && objectNormalMap ? objectNormalMap.uuid : '-', objectShininess ?? '-', gMode ? `g${gMode.mode}` : '-'].join('|');
    let mat = this._materials.get(key);
    if (mat) return mat;
    const params = { map: texture || null, color: texture ? 0xffffff : 0x9a9a9a, side: twoSide ? THREE.DoubleSide : THREE.FrontSide, fog };
    if (spec) params.specularMap = specularMap;
    if (objectNormalMap && !maxDiffuse) params.normalMap = objectNormalMap;
    if (glowMap && !maxDiffuse) { params.emissiveMap = glowMap; params.emissive = new THREE.Color(GLOW_COLOR, GLOW_COLOR, GLOW_COLOR); }
    mat = maxDiffuse ? new THREE.MeshBasicMaterial(params) : new THREE.MeshLambertMaterial(params);
    if (spec) patchSpecular(mat, spec);
    if (objectNormalMap && !maxDiffuse) patchObjectNormalBasis(mat);
    if (spec === 'env') loadEnvironmentCube(this.textures);   // BoneAnimEnv envTexture (once, any stage)
    if (transparent && kind === 'smooth') {
      mat.transparent = true;
      mat.depthWrite = depthWrite ?? false;
      mat.alphaTest = alphaTest ?? 0.02;
    } else if (alphaTest != null) {
      mat.alphaTest = alphaTest;
    } else if (gMode) {
      // Global: cut-out = ALPHAREF 240 no blend; blend = ALPHAREF 1 SrcAlpha/InvSrcAlpha; '#' = ALPHAREF 1 SrcAlpha/One.
      // Depth writes stay on (no ZWRITE change in the Bone::Normal / MeshImpl draw).
      if (gMode.alphaTest > 0) mat.alphaTest = gMode.alphaTest;
      if (gMode.mode === 'blend' || gMode.mode === 'additive') {
        mat.transparent = true;
        mat.depthWrite = true;
        if (gMode.mode === 'additive') {
          mat.blending = THREE.CustomBlending;
          mat.blendEquation = THREE.AddEquation;
          mat.blendSrc = THREE.SrcAlphaFactor;
          mat.blendDst = THREE.OneFactor;
        } else mat.blending = THREE.NormalBlending;
      }
    } else if (kind !== 'none') {
      mat.alphaTest = 0.5;   // ENGINE-CHOSEN legacy path (switch globalAlphaModes off, or an image with no resolved D3DX format)
    }
    if (depthWrite != null) mat.depthWrite = depthWrite;
    // glass: the cash potions' bottle subset (texture/item/gen_pot_cas_bottle.dds, DXT1 without alpha) is drawn over
    // the coloured liquid subset and the liquid shows through it (the 1000 starter potions showed as
    // colourless white bottles when the glass was opaque) - normal alpha blending at the ENGINE-CHOSEN glass opacity, no
    // depth write, after the opaque liquid. Not additive: the full-bright inventory icon light added the white glass to the
    // liquid and washed the red / blue potions out to white (src/config/engine-chosen-item-glass.js).
    // gfx-B2 itemGlassOff: the bottle texture is DXT1 with no transparent texel and no blend data, so by default it is drawn as the data says.
    if (!gfxB('itemGlassOff') && /^texture\/item\/[^/]*bottle[^/]*\.dds$/.test(ud.key || '')) {
      mat.transparent = true;
      mat.blending = THREE.NormalBlending;
      mat.opacity = ITEM_GLASS_CHOSEN.OPACITY;
      mat.depthWrite = false;
      mat.alphaTest = 0;
    }
    mat.name = texture ? texture.name : 'untextured';
    mat.userData = { ...mat.userData, alphaKind: kind, maxDiffuse: !!maxDiffuse, twoSide: !!twoSide, transparent: !!transparent,
      specular: spec, glow: !!glowMap, fog, objectShininess, ...(gMode ? { globalAlphaMode: gMode.mode, globalAlphaClass: gMode.cls } : {}), ...(itemMesh ? { dkNoShade: true } : {}) };
    this._materials.set(key, mat);
    return mat;
  }

  // ---------------------------------------------------------------------------------------- static
  /**
   * @param {string} meshKey  data key ('mesh/object/building/x.mesh')
   * @param {{tpackKey?:string|false, textures?:any, twoSide?:any, transparent?:any, alphaTest?:number,
   *          maxDiffuse?:any, depthWrite?:boolean, fog?:boolean|number|string}} [opts]
   *   Flags accept the raw table values (1 / '1' / true).
   * @returns {Promise<StaticModel|null>}
   */
  loadStatic(meshKey, opts = {}) {
    if (!meshKey) return Promise.resolve(null);
    const k = normPath(meshKey);
    const o = {
      tpackKey: opts.tpackKey === false ? false : (opts.tpackKey ? normPath(opts.tpackKey) : null),
      textures: opts.textures || null,
      twoSide: flag(opts.twoSide), transparent: flag(opts.transparent), maxDiffuse: flag(opts.maxDiffuse),
      alphaTest: opts.alphaTest != null ? Number(opts.alphaTest) : null,
      depthWrite: opts.depthWrite != null ? !!opts.depthWrite : null,
      fog: materialFog(opts.fog),
      effectSpecular: flag(opts.effectSpecular),
      objectBump: /^mesh\/object\//.test(k) && flag(opts.objectBump),
      objectShininess: Number.isFinite(opts.objectShininess) ? opts.objectShininess : null,
    };
    const ck = parseWingAssetKey(k) ? `${k}|wing|${o.fog}` : `${k}|${o.tpackKey}|${JSON.stringify(o.textures)}|${o.twoSide}|${o.transparent}|${o.maxDiffuse}|${o.alphaTest}|${o.depthWrite}|${o.fog}${o.effectSpecular ? '|fxspec' : ''}|b${o.objectBump}|h${o.objectShininess}`;
    let p = this._static.get(ck);
    if (!p) {
      p = this._buildStatic(k, o).catch(err => {
        if (err?.transient) {
          if (this._static.get(ck) === p) this._static.delete(ck);
          throw err;
        }
        warnOnce(`s:${k}`, `static ${k}: ${err && err.stack || err}`); return null;
      });
      this._static.set(ck, p);
    }
    return p;
  }

  _geometry(meshKey, m) {
    const gk = `${meshKey}#${m.index}`;
    let g = this._geoms.get(gk);
    if (!g) { g = baseGeometry(m); this._geoms.set(gk, g); }
    return g;
  }

  async _buildStatic(k, o) {
    if (k.startsWith('engine/wings/')) {
      // Fabricated procedural wings retired (ANIM-FX-GLOBAL-REA 2026-10-27).
      // Live wings load only from Global mesh/item/armor/wing/* via mounts.json.
      return null;
    }
    if (/^custom\/glb\/[a-f0-9]{64}\.glb$/.test(k)) return this._buildImportedStatic(k, o);
    const [parsed, tpack] = await Promise.all([this.mesh(k), this._resolveTpack(k, o.tpackKey)]);
    if (!parsed) return null;
    const explicit = normalizeTextures(o.textures);
    const entries = parsed.meshes.filter(m => m.vertexCount > 0 && m.indices.length >= 3);
    const texs = await Promise.all(entries.map(m => this._textureFor(m.material, { tpack, explicit, meshKey: k })));
    if (gfxB('globalAlphaModes')) await this.dxtAlphaFilter();   // LANE-54: material() reads the DXT1 filter list
    // item meshes (weapons, drops, inventory models) draw with itemmesh.fx: specular maps; map objects (geometry.fx)
    // have no specular technique. Glow maps for both.
    // effectSpecular (skill effect meshes, fx-units.js MeshUnit): unskinned effect meshes draw like boneanimation.fx Bone0
    // (vsBone0Env + psEnvSpecular), so their authored specular slot selects the env patch.
    const specKind = /^mesh\/item\//.test(k) ? 'item' : o.effectSpecular ? 'env' : null;
    const extra = await Promise.all(entries.map((m, i) => this._extraMaps(m.material, { tpack, textures: o.textures, meshKey: k, diffuse: texs[i], specular: !!specKind })));
    // Authored object bump=1 selects geometry.fx's tangent-space RGB normal map.
    // Keep the existing lighting/alpha/fog paths; native highlight/cover parity
    // is separate. Missing maps or old meshes without tangents retain Lambert.
    const normals = await Promise.all(entries.map(m => o.objectBump && !o.maxDiffuse && hasObjectTangentBasis(m) && this.textures
      ? this.textures.loadFirst(resolveTexture(tpack, m.material, 'bump', { meshPath: k }), { quiet: true }) : null));
    await breathe();
    const parts = entries.map((m, i) => ({
      name: m.name, slot: m.material, geometry: this._geometry(k, m), texture: texs[i],
      material: this.material(texs[i], { ...o, specularMap: extra[i].spec, specKind, glowMap: extra[i].glow, objectNormalMap: normals[i] }),
    }));
    const bbox = new THREE.Box3();
    for (const m of entries) bbox.union(box3FromMinMax(m.bbox.min, m.bbox.max));
    const helpers = {};
    const helperList = [];
    for (const h of parsed.helpers || []) {
      const b = tightBox(h.positions);
      if (b.isEmpty()) continue;
      const entry = { name: h.name, min: b.min.toArray(), max: b.max.toArray(), positions: h.positions, indices: h.indices };
      helperList.push(entry);
      const cur = helpers[h.name];
      if (!cur) helpers[h.name] = { min: entry.min.slice(), max: entry.max.slice() };
      else for (let a = 0; a < 3; a++) { cur.min[a] = Math.min(cur.min[a], entry.min[a]); cur.max[a] = Math.max(cur.max[a], entry.max[a]); }
    }
    const lines = (parsed.lines || []).map(l => ({ name: l.name, strips: l.strips.map(s => s.positions) }));
    return new StaticModel({ key: k, parts, bbox, helpers, helperList, lines, flags: { ...o } });
  }

  async _buildImportedStatic(key, opts = {}) {
    const {loadImportedGLB}=await import('../systems/itembuilder/glb-import.js');
    const bytes=await tryFetchBuffer(key);
    if(!bytes)return null;
    const imported=await loadImportedGLB(bytes);
    if(imported.report.skins){imported.dispose();throw Error('GLB armor needs native rig mapping; static equipment cannot silently discard skinning.');}
    const parts=[],bbox=new THREE.Box3(),mirror=new THREE.Matrix4().makeScale(1,1,-1),original=new Set();
    imported.object.updateMatrixWorld(true);
    imported.object.traverse(node=>{
      if(!node.isMesh)return;
      for (const material of Array.isArray(node.material) ? node.material : [node.material]) material.fog = materialFog(opts.fog);
      const geometry=node.geometry.clone();original.add(node.geometry);
      const matrix=new THREE.Matrix4().multiplyMatrices(mirror,node.matrixWorld);
      geometry.applyMatrix4(matrix);
      // GLB is right-handed/Y-up. Convert once into the native FILE frame; preserve face winding.
      if(matrix.determinant()<0){
        if(!geometry.index){const count=geometry.attributes.position.count;geometry.setIndex(Array.from({length:count},(_,i)=>i));}
        const indices=geometry.index.array;for(let i=0;i+2<indices.length;i+=3){const value=indices[i+1];indices[i+1]=indices[i+2];indices[i+2]=value;}
        geometry.index.needsUpdate=true;
      }
      geometry.computeBoundingBox();bbox.union(geometry.boundingBox);
      parts.push({name:node.name||'GLB mesh',slot:0,geometry,material:node.material,texture:node.material?.map||null});
    });
    for(const geometry of original)geometry.dispose();
    return new StaticModel({key,parts,bbox,helpers:{},helperList:[],lines:[],flags:{importedGLB:true}});
  }

  // ---------------------------------------------------------------------------------------- skinned
  /**
   * @param {{skelKey:string, parts:Array<{meshKey:string, tpackKey?:string|false, textures?:any, twoSide?:any,
   *          transparent?:any, maxDiffuse?:any, alphaTest?:number, fog?:boolean|number|string}>}} def
   * @returns {Promise<SkinnedModel|null>} null only when no part mesh file could be read. A missing skeleton gives a
   *   bind-pose model (every vertex on the identity root bone, model.missingSkeleton = true); mesh files without any
   *   geometry give an empty model (model.empty = true, instance.meshes = []).
   */
  loadSkinned({ skelKey, parts = [] } = {}) {
    const sk = skelKey ? normPath(skelKey) : '';
    const list = (parts || []).filter(p => p && p.meshKey).map(p => ({
      meshKey: normPath(p.meshKey),
      tpackKey: p.tpackKey === false ? false : (p.tpackKey ? normPath(p.tpackKey) : null),
      textures: p.textures || null,
      twoSide: flag(p.twoSide), transparent: flag(p.transparent), maxDiffuse: flag(p.maxDiffuse),
      alphaTest: p.alphaTest != null ? Number(p.alphaTest) : null,
      depthWrite: p.depthWrite != null ? !!p.depthWrite : null,
      fog: materialFog(p.fog),
    }));
    if (!list.length) return Promise.resolve(null);
    const ck = `${sk}|${JSON.stringify(list)}`;
    let p = this._skinned.get(ck);
    if (!p) {
      p = this._buildSkinned(sk, list).catch(err => {
        if (err?.transient) {
          if (this._skinned.get(ck) === p) this._skinned.delete(ck);
          throw err;
        }
        warnOnce(`k:${ck}`, `skinned ${sk}: ${err && err.stack || err}`); return null;
      });
      this._skinned.set(ck, p);
    }
    return p;
  }

  async _buildSkinned(skelKey, parts) {
    const skel = skelKey ? await this.skeleton(skelKey) : null;
    const nb = skel ? skel.bones.length : 0;
    const staticIndex = nb;

    // bones: sanitised unique names (the first duplicate keeps the plain name, as in skel.js boneIndex)
    const used = new Set([STATIC_BONE_NAME]);
    const bones = (skel ? skel.bones : []).map((b, i) => {
      let name = THREE.PropertyBinding.sanitizeNodeName(b.name) || `bone${i}`;
      if (used.has(name)) { let n = 1; while (used.has(`${name}_dup${n}`)) n++; name = `${name}_dup${n}`; }
      used.add(name);
      const S = b.scaleMatrix;
      const q = new THREE.Quaternion(b.rotation[0], b.rotation[1], b.rotation[2], b.rotation[3]).normalize();
      const sh = S ? SHEAR_INDICES.map(k => (Math.abs(S[k]) > 1e-7 ? S[k] : 0)) : null;
      return { name, rawName: b.name, parent: b.parent, p: [...b.position], q: [q.x, q.y, q.z, q.w],
        s: [S ? S[0] : 1, S ? S[5] : 1, S ? S[10] : 1], sh: sh && sh.some(v => v !== 0) ? sh : null };
    });

    // bone inverses from the bind pose as the bones themselves compose it (skeleton.calculateInverses equivalent)
    const tmpRoot = new THREE.Object3D();
    const tmp = bones.map(b => {
      const o = makeShearable(new THREE.Object3D(), b.sh);
      o.position.fromArray(b.p); o.quaternion.fromArray(b.q); o.scale.fromArray(b.s);
      return o;
    });
    bones.forEach((b, i) => (b.parent >= 0 ? tmp[b.parent] : tmpRoot).add(tmp[i]));
    tmpRoot.updateMatrixWorld(true);
    const boneInverses = tmp.map(o => o.matrixWorld.clone().invert());
    boneInverses.push(new THREE.Matrix4());

    // parts
    const built = await Promise.all(parts.map(part => {
      const key = `${skelKey}|${JSON.stringify(part)}`;
      let pending = this._skinnedParts.get(key);
      if (!pending) {
        pending = this._buildSkinnedPart(part, skel, staticIndex).catch(error => {
          if (this._skinnedParts.get(key) === pending) this._skinnedParts.delete(key);
          throw error;
        });
        this._skinnedParts.set(key, pending);
      }
      return pending;
    }));
    // null: no part mesh file could be read. A mesh that parses but has no geometry (e.g. the invisible trap monsters'
    // ghostman_knight_none.mesh, which holds only a 'picking' helper) gives a valid EMPTY model (model.empty = true).
    if (built.every(b => b === null)) return null;
    const partList = built.filter(Boolean).flat();
    const bbox = new THREE.Box3();
    for (const p of partList) bbox.union(p.geometry.boundingBox);
    const missing = partList.reduce((a, p) => a + p.missingBones.length, 0);
    if (missing && skel) {
      warnOnce(`mb:${skelKey}:${parts.map(p => p.meshKey).join(',')}`,
        `${missing} palette bone(s) not in ${skelKey}; they stay in bind pose (${[...new Set(partList.flatMap(p => p.missingBones))].slice(0, 5).join(', ')})`);
    }
    const lineMeshes = await Promise.all([...new Set(parts.map(p => p.meshKey))].map(key => this.mesh(key)));
    return new SkinnedModel({
      skelKey, skel, bones, boneNames: bones.map(b => b.name), boneInverses, parts: partList, bbox,
      missingSkeleton: !skel, partKeys: parts.map(p => p.meshKey),
      missingPartKeys: parts.filter((p,i) => built[i] === null).map(p => p.meshKey),
      lines: lineMeshes.flatMap(rigidModelLines),
    });
  }

  async _buildSkinnedPart(part, skel, staticIndex) {
    const [parsed, tpack] = await Promise.all([this.mesh(part.meshKey), this._resolveTpack(part.meshKey, part.tpackKey)]);
    if (!parsed) return null;
    const explicit = normalizeTextures(part.textures);
    const entries = parsed.meshes.filter(m => m.vertexCount > 0 && m.indices.length >= 3);
    const texs = await Promise.all(entries.map(m => this._textureFor(m.material, { tpack, explicit, meshKey: part.meshKey })));
    if (gfxB('globalAlphaModes')) await this.dxtAlphaFilter();   // LANE-54
    // skinned bodies draw with boneanimation.fx: a specular map selects BoneAnimEnv (env reflection, matfx.js)
    const extra = await Promise.all(entries.map((m, i) => this._extraMaps(m.material, { tpack, textures: part.textures, meshKey: part.meshKey, diffuse: texs[i], specular: part.specular !== false })));
    await breathe();
    return entries.map((m, i) => {
      const n = m.vertexCount;
      const skinIndex = new Uint16Array(n * 4);
      const skinWeight = new Float32Array(n * 4);
      const missingBones = [];
      if (m.skin && skel) {
        const map = m.skin.bonePalette.map(name => {
          const bi = findBone(skel, name);
          if (bi < 0) { missingBones.push(name); return staticIndex; }
          return bi;
        });
        const BI = m.skin.boneIndices, BW = m.skin.boneWeights, si = m.skin.staticIndex;
        for (let v = 0; v < n * 4; v++) {
          const w = BW[v];
          if (!(w > 0)) continue;
          const pi = BI[v];
          skinIndex[v] = pi === si ? staticIndex : (map[pi] ?? staticIndex);
          skinWeight[v] = w;
        }
      } else {
        for (let v = 0; v < n; v++) { skinIndex[v * 4] = staticIndex; skinWeight[v * 4] = 1; }
      }
      const g = new THREE.BufferGeometry();
      g.setAttribute('position', new THREE.BufferAttribute(m.positions, 3));
      g.setAttribute('normal', new THREE.BufferAttribute(m.normals, 3));
      g.setAttribute('uv', new THREE.BufferAttribute(m.uv0, 2));
      g.setAttribute('skinIndex', new THREE.Uint16BufferAttribute(skinIndex, 4));
      g.setAttribute('skinWeight', new THREE.Float32BufferAttribute(skinWeight, 4));
      g.setIndex(new THREE.BufferAttribute(m.indices, 1));
      g.boundingBox = box3FromMinMax(m.bbox.min, m.bbox.max);
      g.boundingSphere = g.boundingBox.getBoundingSphere(new THREE.Sphere());
      return {
        name: `${part.meshKey.split('/').pop().replace(/\.mesh$/, '')}:${m.name}`, meshKey: part.meshKey, slot: m.material,
        geometry: g, texture: texs[i], missingBones,
        material: this.material(texs[i], { ...part, specularMap: extra[i].spec, specKind: 'env', glowMap: extra[i].glow }),
      };
    });
  }

  // ---------------------------------------------------------------------------------------- clips
  /**
   * @param {string} animKey
   * @param {SkinnedModel} model
   * @param {{duration?:number}} [opts] playback length in seconds (action-table TimeLength). Values >= 100 are read as
   *   milliseconds (modeldef.actionSeconds rule). Default: frameCount / 30, else 1 s.
   * @returns {Promise<THREE.AnimationClip|null>}  clip.userData = { animKey, skelKey, duration, rootMotion, frameCount,
   *   boundTracks, skippedTracks }
   */
  loadClip(animKey, model, { duration } = {}) {
    const pending = this.loadClipWithStatus(animKey, model, { duration });
    let safe = this._clipPublic.get(pending);
    if (!safe) { safe = pending.catch(() => null); this._clipPublic.set(pending, safe); }
    return safe;
  }

  loadClipWithStatus(animKey, model, { duration } = {}) {
    if (!animKey || !model) return Promise.resolve(null);
    const k = normPath(animKey);
    let dur = Number(duration);
    if (!(dur > 0) || !Number.isFinite(dur)) dur = null;
    else if (dur >= 100) dur /= 1000;
    // Keep plain bare, full-stretch bare, and skinned clips separate: only owners
    // that explicitly support shear may receive animation shear tracks.
    const ck = `${k}|${model.skelKey}|${dur ?? 'auto'}${model instanceof SkinnedModel ? '' : model.supportsShear === true ? '|bare-shear' : '|bare'}`;
    let p = this._clips.get(ck);
    if (!p) {
      p = this._buildClip(k, model, dur).catch(err => {
        if (err?.transient) {
          if (this._clips.get(ck) === p) this._clips.delete(ck);
          throw err;
        }
        warnOnce(`c:${ck}`, `clip ${k}: ${err && err.stack || err}`); return null;
      });
      this._clips.set(ck, p);
    }
    return p;
  }

  async _buildClip(k, model, dur) {
    const anim = await this.animWithStatus(k);
    if (!anim) return null;
    await breathe();
    if (dur == null) dur = anim.estDurationSec || (anim.frameCount ? anim.frameCount / AUTHORING_FPS : 1);
    const scaleTimes = src => {
      const t = new Float32Array(src.length);
      let prev = 0;
      for (let i = 0; i < src.length; i++) {
        let v = Math.min(1, Math.max(0, src[i])) * dur;
        if (i && v < prev) v = prev;
        t[i] = prev = v;
      }
      return t;
    };
    const tracks = [];
    const seen = new Set();
    let skipped = 0, shearTracks = 0;
    for (const tr of anim.tracks) {
      const bi = model.skel ? findBone(model.skel, tr.name) : -1;
      if (bi < 0 || seen.has(bi)) { skipped++; continue; }
      seen.add(bi);
      const name = model.boneNames[bi];
      if (tr.posTimes.length) tracks.push(new THREE.VectorKeyframeTrack(`${name}.position`, scaleTimes(tr.posTimes), tr.positions));
      if (tr.rotTimes.length) tracks.push(new THREE.QuaternionKeyframeTrack(`${name}.quaternion`, scaleTimes(tr.rotTimes), tr.rotations));
      if (tr.sclTimes.length) {
        const n = tr.sclTimes.length, S = tr.scales, v = new Float32Array(n * 3), sh = new Float32Array(n * 6);
        let sheared = !!model._bones[bi]?.sh;               // a keyed stretch replaces the rest shear, even with zeros
        for (let i = 0; i < n; i++) {
          v[i * 3] = S[i * 16]; v[i * 3 + 1] = S[i * 16 + 5]; v[i * 3 + 2] = S[i * 16 + 10];
          for (let k = 0; k < 6; k++) {
            const x = S[i * 16 + SHEAR_INDICES[k]];
            sh[i * 6 + k] = Math.abs(x) > 1e-7 ? x : 0;
            if (sh[i * 6 + k] !== 0) sheared = true;
          }
        }
        const times = scaleTimes(tr.sclTimes);
        tracks.push(new THREE.VectorKeyframeTrack(`${name}.scale`, times, v));
        // Full-stretch effect skeletons opt in after installing shear on every bone.
        // Other bare facades keep plain tracks and never receive unbindable properties.
        if (sheared && (model instanceof SkinnedModel || model.supportsShear === true)) { tracks.push(new THREE.VectorKeyframeTrack(`${name}.shear`, times, sh)); shearTracks++; }
      }
    }
    if (!tracks.length) warnOnce(`nt:${k}|${model.skelKey}`, `clip ${k} has no track that drives ${model.skelKey}`);
    const clip = new THREE.AnimationClip(k, dur, tracks);
    clip.userData = {
      animKey: k, skelKey: model.skelKey, duration: dur, frameCount: anim.frameCount, rootMotion: anim.rootMotion,
      boundTracks: seen.size, skippedTracks: skipped, shearTracks, truncated: anim.truncated,
    };
    return clip;
  }
}
