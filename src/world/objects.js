// Map objects: every .mol placement (docs/formats/mol.md) -> ModelCache.loadStatic, instanced per object name.
//
// FILE frame under the mirrored worldRoot: matrix = T(x, H(x,z) + y, z) * R(qx,qy,qz,qw) * S(s) with the raw D3DX
// quaternion and H = the triangle-exact terrain height (map.js sampleHeight). No z negation, no winding swap.
//
//  * Names resolve through assetresolve.js (script/object/*.csv rows or object/static/*.txt descriptors); the first
//    existing mesh / tpack candidate is used. Flags: twoside, transparent, maxdiffuse (full-bright), shadow (1 = casts),
//    uvx/uvy/uvspeed or uvanim (texture scroll).
//  * Loading is progressive and nearest-first: a small worker pool always takes the pending object name whose
//    closest placement is nearest to the camera (re-prioritised as the camera moves). World.load() only waits for
//    the names near the start point.
//  * Distance culling: each name keeps one InstancedMesh set (StaticModel.createInstanced); every ~0.2 s the
//    instances within the cull distance are written to the front of the buffer (finish(k)). Cull distance =
//    min(view distance, fog end) (+ the object's radius), the same for every category: past the fog end a
//    fogged prop is pure fog colour (range fog, fog-model.js), so nothing visible is ever cut. The old engine-only
//    category factors (plant 0.5, junk 0.7, animal/etc 0.85) cut plants at half the fog distance (pop-in). The maplist
//    Cull_Base / Cull_<category> columns are not used: their rule is not derivable from the files (see
//    tools/test-env-visibility.mjs).
//  * Animated objects (skeleton + anim): drawn animated wherever they are drawn at all - the object tables have no LOD
//    distance (script/object/*.csv: Lod 0, Lodmesh = the base mesh), so there is no bind-pose stand-in and no distance
//    switch. Placements share a few rigs (one skeleton + looping Animator each, phase locked to the layer clock) drawn
//    with instanced skinned meshes (_buildRigs). (opt-2) Draw path of the rigs, pixels identical:
//      - every rig mesh has a BufferGeometry object of its own that SHARES the part's attribute buffers (shareGeometry): three's
//        binding-state cache is keyed by geometry, and all rig sets of a part used to share one geometry object, so every draw
//        re-specified all vertex attributes (1,192 vertexAttribPointer per frame in Ardeca, 14 after);
//      - a set is only drawn / only casts a shadow when one of its instances can touch the camera frustum / the sun's depth
//        frustum (RigCullNode, run by three.js inside the render, with the exact frustums of that render); the bound of an
//        instance is the measured reach of the animated vertices over the whole clip (rigReach), NOT the bind sphere: walking
//        animals (chickens, goats, ducks) leave it by up to 4x;
//      - a rig is only re-posed while one of its sets is drawn (a skipped pose is repaired in the same render before it is
//        drawn: the pose is a function of the layer clock), and its bone matrices / bone texture are only rebuilt after a pose.
//      - nothing is culled before it was drawn once (hookWarm): the first draw of a material (shader program, buffer / texture
//        upload) stays at streaming time, it does not move to the moment the camera first looks at the prop;
//    Kill switches (console, A-B tests): globalThis.__dekaronNoRigCull = true (draw and pose everything as before),
//    globalThis.__dekaronNoRigSkelSkip = true (rebuild the bone matrices on every render again).
//  * 'ground*' helper triangles of every placement feed GroundSurfaces (bridges, decks) for World.heightAt.
//  * Real-time shadows: the client's shadow pass (data/binary/shadowobject.fx) only has ShadowBone techniques - only
//    skinned meshes cast; static object shadows are baked into the terrain vertex colours. So static instances never
//    cast (a roof would otherwise black out a whole dungeon); animated object rigs cast when flagged 'shadow';
//    everything receives (actor shadows fall on floors and decks).
import * as THREE from 'three';
import { parseMol, molCategory } from '../formats/mol.js';
import { loadObjectDB, resolveObjectAsync } from '../formats/assetresolve.js';
import { fetchText, tryFetchBuffer } from '../engine/assets.js';
import { applyShade, applyShadeTree } from './shade.js';
import { freezeMatrices, materialFog } from '../engine/models.js';
import { patchObjectNormalBasis } from '../engine/object-normal.js';

const NEAR_RADIUS = 48;          // World.load waits for object names with a placement this close to the start
const WORKERS = 6;               // parallel object-name loads
// ENGINE-CHOSEN animated-object pose rate by distance (FILE units): every frame within `near`, every 2nd frame to `far`,
// every 3rd beyond (the same thresholds idea as the actors' LOD). Console kill switch: globalThis.__dekaronNoAnimLod = true.
const ANIM_OBJECT_LOD = Object.freeze({ near: 30, far: 60 });
const CULL_INTERVAL = 0.2;       // s between visibility rebuilds
const PRIORITY_INTERVAL = 0.75;  // s between loading-queue re-sorts
const PHASES = 4;                // (graphics) rigs per animated object name: placements spread over this many clip phases
const MIRROR_X = new THREE.Matrix4().makeScale(-1, 1, 1);
const UV_RATE = 1;              // texture scroll = uvspeed UV units per second along (uvx, uvy): sky domes use 0.01-0.04
                                 // (slow cloud drift), fountains / waterfalls 1.5-3.3 (fast flow) - read from the data
const OCC_INTERVAL = 0.12;        // (playgate) s between camera-occlusion checks (_occlusion)
const OCC_MAX_R = 12;            // props with a bigger bounding radius (buildings, walls, bridges) never hide
const OCC_SHRINK = 0.7;          // bounding spheres are loose: test against 70 % of the radius
const OCC_SOLID = new Set(['building', 'building_extra', 'house', 'wall', 'bridge']);   // .mol categories that are never hidden

let dbPromise = null;
/** Object tables, loaded once per session. */
export function objectDB() {
  if (!dbPromise) dbPromise = loadObjectDB(fetchText);
  return dbPromise;
}

const flagOn = v => v === true || Number(v) > 0;
export const objectFog = flags => [true, 1, '1'].includes(flags?.nofog) ? false : materialFog(flags?.fog);

/**
 * Performance: static instanced objects never move, so their matrices are computed once (and after every visibility
 * rebuild, which may add mirrored meshes) instead of in every frame's updateMatrixWorld traversal (~2,200 nodes in
 * Ardeca). Nodes that already hold a hand-set matrix (matrixAutoUpdate false, e.g. mirrored placements) keep it.
 */
function freezeStatic(o) {
  freezeMatrices(o, false);          // (graphics) unfreeze to recompute below
  o.traverse(c => { if (c.matrixAutoUpdate) { c.updateMatrix(); c.matrixAutoUpdate = false; } });
  o.parent?.updateWorldMatrix(true, false);
  o.updateMatrixWorld(true);
  o.matrixWorldAutoUpdate = false;
  // (graphics) three r170 still walks and multiplies every child of a matrixWorldAutoUpdate=false node each frame;
  // a frozen subtree is skipped entirely (models.js freezeMatrices)
  freezeMatrices(o, true, false);
}

async function firstExisting(keys) {
  for (const k of keys || []) {
    if (!k) continue;
    const buf = await tryFetchBuffer(k).catch(() => null);
    if (buf) return k;
  }
  return null;
}

/**
 * (graphics) Many placements of an animated object drawn in one pose: a SkinnedMesh that the renderer also treats as an
 * InstancedMesh (three r170 composes the skinning and instancing vertex chunks: bones in model space, then the
 * placement matrix, then the object's world matrix). The bones live under a rig root that is not in the scene (identity
 * world), so the bind matrix and its inverse stay identity (detached mode). The parts of one set share the instance
 * buffer. Never raycast: the bind-pose InstancedMesh of the same placements still answers cameraClip.
 */
export class InstancedSkinnedMesh extends THREE.SkinnedMesh {
  constructor(geometry, material, instanceMatrix, skeleton, sphere) {
    super(geometry, material);
    this.isInstancedMesh = true;
    this.instanceMatrix = instanceMatrix;
    this.instanceColor = null;
    this.morphTexture = null;
    this.count = 0;
    this.bind(skeleton, new THREE.Matrix4());
    this.bindMode = THREE.DetachedBindMode;
    this.frustumCulled = false;      // instances spread over the draw distance and moving parts leave the bind sphere
    this.boundingSphere = sphere;    // render-order sorting only
    this.isRig = true;
  }
  setMatrixAt(i, m) { m.toArray(this.instanceMatrix.array, i * 16); }
  raycast() {}
  dispose() { this.dispatchEvent({ type: 'dispose' }); }
}

/**
 * (opt-2) A BufferGeometry object of its own that shares every attribute buffer, the index, the groups and the draw range of
 * `src` (nothing is copied: one GL buffer per attribute). three.js keys its vertex-array-object cache by geometry, and a
 * rig mesh differs from its siblings only by its instanceMatrix attribute: with one geometry object per mesh the cache hits
 * instead of re-specifying every attribute pointer on every draw.
 */
export function shareGeometry(src) {
  const g = new THREE.BufferGeometry();
  g.name = src.name;
  for (const key of Object.keys(src.attributes)) g.setAttribute(key, src.attributes[key]);
  for (const key of Object.keys(src.morphAttributes || {})) g.morphAttributes[key] = src.morphAttributes[key];
  g.morphTargetsRelative = src.morphTargetsRelative;
  if (src.index) g.setIndex(src.index);
  for (const grp of src.groups) g.addGroup(grp.start, grp.count, grp.materialIndex);
  g.drawRange.start = src.drawRange.start; g.drawRange.count = src.drawRange.count;
  if (src.boundingSphere) g.boundingSphere = src.boundingSphere.clone();
  if (src.boundingBox) g.boundingBox = src.boundingBox.clone();
  g.userData = src.userData;
  return g;
}

/**
 * Dispose a shareGeometry() object without freeing the buffers it shares: three.js' dispose handler deletes the GL buffers of
 * every attribute it finds on the geometry, which would pull them away from the part geometry (and every sibling mesh) that is
 * still in use. The attributes are detached first, so only the vertex-array objects of this geometry go.
 */
export function releaseSharedGeometry(g) {
  g.attributes = {}; g.morphAttributes = {}; g.index = null;
  g.dispose();
}

/** Largest singular value of the 3x3 linear part of a column-major 4x4 (elements e): the most it can stretch any vector. */
export function maxSingular3(e) {
  // S = A^T A (symmetric, columns of A are (e0,e1,e2) (e4,e5,e6) (e8,e9,e10)); its largest eigenvalue, closed form (Smith 1961)
  const s00 = e[0] * e[0] + e[1] * e[1] + e[2] * e[2], s11 = e[4] * e[4] + e[5] * e[5] + e[6] * e[6], s22 = e[8] * e[8] + e[9] * e[9] + e[10] * e[10];
  const s01 = e[0] * e[4] + e[1] * e[5] + e[2] * e[6], s02 = e[0] * e[8] + e[1] * e[9] + e[2] * e[10], s12 = e[4] * e[8] + e[5] * e[9] + e[6] * e[10];
  const q = (s00 + s11 + s22) / 3, p1 = s01 * s01 + s02 * s02 + s12 * s12;
  const p2 = (s00 - q) * (s00 - q) + (s11 - q) * (s11 - q) + (s22 - q) * (s22 - q) + 2 * p1, p = Math.sqrt(p2 / 6);
  if (!(p > 1e-18)) return Math.sqrt(Math.max(q, 0));
  const b00 = (s00 - q) / p, b11 = (s11 - q) / p, b22 = (s22 - q) / p, b01 = s01 / p, b02 = s02 / p, b12 = s12 / p;
  const det = b00 * (b11 * b22 - b12 * b12) - b01 * (b01 * b22 - b12 * b02) + b02 * (b01 * b12 - b11 * b02);
  const phi = Math.acos(Math.max(-1, Math.min(1, det / 2))) / 3;
  return Math.sqrt(Math.max(q + 2 * p * Math.cos(phi), 0)) * (1 + 1e-6);
}

/** The six planes of a THREE.Frustum as flat numbers (nx, ny, nz, constant) x 6. */
function planesOf(fr, out) {
  for (let i = 0; i < 6; i++) { const p = fr.planes[i]; out[i * 4] = p.normal.x; out[i * 4 + 1] = p.normal.y; out[i * 4 + 2] = p.normal.z; out[i * 4 + 3] = p.constant; }
  return out;
}

/** THREE.Frustum.intersectsSphere on raw numbers (a NaN radius or centre keeps the sphere: never culls by mistake). */
function sphereInPlanes(P, x, y, z, r) {
  for (let i = 0; i < 24; i += 4) if (P[i] * x + P[i + 1] * y + P[i + 2] * z + P[i + 3] < -r) return false;
  return true;
}

// ENGINE-CHOSEN margins of the rig culling (nothing in the game files fixes them): the animated reach is sampled in time, so it
// gets 8 % + 5 cm; a sphere must be 25 cm outside a frustum plane before the set is dropped (float32 instance matrices, plane
// arithmetic of two code paths).
const RIG_REACH_SCALE = 1.08, RIG_REACH_ADD = 0.05, RIG_CULL_PAD = 0.25;
const RIG_REACH_SAMPLES = { min: 32, max: 128, perSecond: 8 };

/**
 * (opt-2) Upper bound of how far any skinned vertex of an animated prop gets from the bind-pose bounding-sphere centre (model
 * space) while its clip plays. For a vertex with bone weights w_k and bind position v: the skinned position is
 * sum_k w_k M_k inv_k v (M_k = bone world matrix, inv_k = bone inverse; detached bind mode, bind matrix = identity), so
 *   |p - c| <= sum_k w_k ( |M_k inv_k c - c| + sigma(M_k) * |Linv_k (v - c)| )  [+ |sum w - 1| |c| for weights not summing to 1]
 * where sigma is the largest singular value of M_k's linear part and Linv_k the linear part of inv_k. The per-bone factor
 * r_k = max |Linv_k (v - c)| over the vertices the bone moves is time independent; the rest is evaluated for every bone at
 * `samples` clip times (uniform; the clip is keyed at 30 Hz, the walking cycles of the animals are ~1 s). Returns Infinity when
 * the geometry is not plainly skinned (then nothing is ever culled for it). `inst` is a SkinnedInstance posed through
 * `animator` (its pose is left at the last sample: re-pose it afterwards).
 */
export function rigReach(model, inst, animator, clip, samples = null) {
  const c = model.sphere.center, cx = c.x, cy = c.y, cz = c.z, clen = Math.hypot(cx, cy, cz);
  const bones = inst.skeleton.bones, inv = inst.skeleton.boneInverses, B = bones.length;
  const rmax = new Float64Array(B).fill(-1);
  let wMax = 1, short = false;
  for (const part of model.parts) {
    const geo = part.geometry, pos = geo.attributes.position, si = geo.attributes.skinIndex, sw = geo.attributes.skinWeight;
    if (!pos || !si || !sw || pos.isInterleavedBufferAttribute || si.isInterleavedBufferAttribute || sw.isInterleavedBufferAttribute || si.itemSize !== 4 || sw.itemSize !== 4 || sw.normalized || si.normalized) return Infinity;
    const P = pos.array, I = si.array, W = sw.array, stride = pos.itemSize;
    for (let i = 0, n = pos.count; i < n; i++) {
      const dx = P[i * stride] - cx, dy = P[i * stride + 1] - cy, dz = P[i * stride + 2] - cz;
      let sum = 0;
      for (let k = 0; k < 4; k++) {
        const w = W[i * 4 + k];
        if (!(w > 0)) continue;
        sum += w;
        const b = I[i * 4 + k];
        if (!(b >= 0 && b < B)) return Infinity;
        const e = inv[b].elements;
        const ux = e[0] * dx + e[4] * dy + e[8] * dz, uy = e[1] * dx + e[5] * dy + e[9] * dz, uz = e[2] * dx + e[6] * dy + e[10] * dz;
        const r = Math.hypot(ux, uy, uz);
        if (r > rmax[b]) rmax[b] = r;
      }
      if (sum > wMax) wMax = sum;
      if (sum < 0.999) short = true;
    }
  }
  // the bind-pose centre expressed in every bone's own frame
  const cl = new Float64Array(B * 3);
  for (let b = 0; b < B; b++) {
    if (rmax[b] < 0) continue;
    const e = inv[b].elements;
    cl[b * 3] = e[0] * cx + e[4] * cy + e[8] * cz + e[12]; cl[b * 3 + 1] = e[1] * cx + e[5] * cy + e[9] * cz + e[13]; cl[b * 3 + 2] = e[2] * cx + e[6] * cy + e[10] * cz + e[14];
  }
  const dur = clip.duration > 0 ? clip.duration : 0;
  const N = samples ?? (dur > 0 ? Math.min(RIG_REACH_SAMPLES.max, Math.max(RIG_REACH_SAMPLES.min, Math.ceil(dur * RIG_REACH_SAMPLES.perSecond))) : 1);
  let reach = 0;
  for (let s = 0; s < N; s++) {
    animator.current.time = dur > 0 ? (s / N) * dur : 0;
    animator.update(0);
    inst.root.updateMatrixWorld(true);
    for (let b = 0; b < B; b++) {
      if (rmax[b] < 0) continue;
      const e = bones[b].matrixWorld.elements;
      const x = cl[b * 3], y = cl[b * 3 + 1], z = cl[b * 3 + 2];
      const px = e[0] * x + e[4] * y + e[8] * z + e[12] - cx, py = e[1] * x + e[5] * y + e[9] * z + e[13] - cy, pz = e[2] * x + e[6] * y + e[10] * z + e[14] - cz;
      const bound = Math.hypot(px, py, pz) + maxSingular3(e) * rmax[b];
      if (bound > reach) reach = bound;
    }
  }
  reach = wMax * reach + (wMax - 1) * clen;
  if (short && clen > reach) reach = clen;
  return reach;
}

/**
 * (opt-2) Skeleton.update of a rig: the bone matrices (and with them the bone-texture upload) are only rebuilt after a pose.
 * three.js calls Skeleton.update once per render per pass (main, depth, ...), 2-3 times a frame for a shadow caster, and on
 * every frame between the animation-LOD poses: all of those rebuilt identical matrices and re-uploaded an identical texture.
 */
function rigSkeletonUpdate() {
  if (this._dkPoseDirty === false && globalThis.__dekaronNoRigSkelSkip !== true) return;
  this._dkPoseDirty = false;
  THREE.Skeleton.prototype.update.call(this);
}

/**
 * (opt-2 review) FIRST-DRAW WARMTH. The first time three.js draws a mesh it creates the shader program of its material variant,
 * uploads its buffers / textures and creates its vertex-array object; on a busy machine that is a 50-170 ms frame. Before the
 * per-placement cull, three.js only culled a group by the union sphere of ALL its placements, so a prop that streamed in paid this
 * right away (while the player was still loading). The per-placement cull must not move it to the moment the camera first turns
 * towards the prop. So an object is never culled by _cullDraw until one real draw of every material of it has happened (main pass:
 * onAfterRender with the mesh's own material; depth pass of a shadow caster: onAfterShadow); until then it is left to three.js
 * exactly as before the cull existed. Hooks remove themselves after the first draw (no per-draw cost afterwards).
 */
function hookWarm(mesh, done, shadow = false) {
  const key = shadow ? '_dkWarmShadow' : '_dkWarmMain';
  if (mesh[key]) return;
  mesh[key] = true;
  if (shadow) mesh.onAfterShadow = function () { delete this.onAfterShadow; done.add(this.material); };
  else mesh.onAfterRender = function (renderer, scene, camera, geometry, material) {
    const m = this.material;
    if (material !== m && !(Array.isArray(m) && m.includes(material))) return;     // another pass with an override material: not this program
    delete this.onAfterRender; done.add(m);
  };
}

/**
 * (opt-2) Not drawable: an Object3D that three.js treats as a LOD (projectObject calls update(camera) for those, inside the
 * render, after the scene's onBeforeRender hooks (camera quake) and the camera matrices are final, before the first mesh after it
 * is projected). It is the first child of the objects group, so the rig sets are decided before they are projected.
 */
class RigCullNode extends THREE.Object3D {
  constructor(layer) {
    super();
    this.name = 'rig-cull';
    this.isLOD = true; this.autoUpdate = true;
    this.frustumCulled = false;
    this._layer = layer;
  }
  update(camera) {
    const layer = this._layer;
    try { layer._cullDraw(camera); } catch (err) {
      // a failure here must never take the frame down: log once, draw everything as before from now on
      if (!layer._cullBroken) { layer._cullBroken = true; console.warn('[world] draw culling failed; off', err); }
      try { layer._cullDraw(camera); } catch { /* the draw-all path is plain flag writes */ }
    }
  }
}

/**
 * (opt-2) Sphere (radius around model.center) that holds every part sphere of a static model: the same spheres three.js'
 * own frustum test of the InstancedMesh unions (geometry.boundingSphere), so culling a group with it never drops anything the
 * renderer would have drawn. null when a part has no bound.
 */
function modelCullRadius(model) {
  const c = model.center;
  let r = 0;
  for (const p of model.parts) {
    const geo = p.geometry;
    if (!geo?.attributes?.position) return null;
    if (!geo.boundingSphere) geo.computeBoundingSphere();
    const s = geo.boundingSphere;
    if (!s || !(s.radius >= 0)) return null;
    r = Math.max(r, c.distanceTo(s.center) + s.radius);
  }
  return model.parts.length ? r : null;
}

let animatorModule = null;
function loadAnimator() {
  if (!animatorModule) animatorModule = import('../engine/animator.js').then(m => m.Animator).catch(() => null);
  return animatorModule;
}

export class ObjectLayer {
  /**
   * @param {{game:object, root:THREE.Object3D, heightAt:(x:number,z:number)=>number, ground?:import('./groundsurf.js').GroundSurfaces}} opts
   */
  constructor({ game, root, heightAt, ground = null, environment = null }) {
    this.game = game;
    this.models = game.models || null;
    this.heightAt = heightAt;
    this.ground = ground;
    this.environment = environment;         // (opt-2) the map's Environment: its sun is the depth frustum the rig casters are tested against
    this.group = new THREE.Group();
    this.group.name = 'objects';
    root.add(this.group);
    this._rigGroups = [];                   // (opt-2) groups whose rigs are built, in build order
    this._cullNode = new RigCullNode(this);
    this.group.add(this._cullNode);          // first child: decides the rig sets before three.js projects them
    this._frC = new THREE.Frustum(); this._frS = new THREE.Frustum(); this._pm = new THREE.Matrix4(); this._look = new THREE.Vector3(); this._shCam = null; this._cullBroken = false;
    this._pc = new Float64Array(24); this._ps = new Float64Array(24);     // camera / depth frustum planes, flat
    this.groups = [];
    this.placementCount = 0;
    this._queue = [];
    this._active = 0;
    this._disposed = false;
    this._cullTimer = 0;
    this._prioTimer = 0;
    this._cam = { x: 256, z: 256 };
    this._lastCull = { x: Infinity, z: Infinity, dist: 0 };
    this._animatedLive = 0;
    this._time = 0;
    this._uvGroups = [];
    this._nearWaiters = [];
    this.stats = { names: 0, placements: 0, loaded: 0, failed: 0, pending: 0, visible: 0, animated: 0, groundTris: 0, missing: [] };
    this.cullDistance = 60;
    this.viewDistance = null;
  }

  /**
   * Parse the .mol and start loading. Resolves when the names near `focus` are ready.
   * @param {ArrayBuffer|null} molBuf
   * @param {{focus?:{x:number,z:number}, onProgress?:(f:number,label:string)=>void, nearRadius?:number, timeoutMs?:number}} [opts]
   */
  async load(molBuf, { focus = null, onProgress = () => {}, nearRadius = NEAR_RADIUS, timeoutMs = 10000 } = {}) {
    if (!molBuf || !this.models) return;
    let mol;
    try { mol = parseMol(molBuf); } catch (err) { console.warn('[world] .mol parse failed', err); return; }
    const db = await objectDB();
    this._db = db;
    // group placements by name, precompute FILE-frame matrices
    const byName = new Map();
    const m = new THREE.Matrix4(), q = new THREE.Quaternion(), p = new THREE.Vector3(), s = new THREE.Vector3();
    mol.objects.forEach((o, i) => {
      if (!Number.isFinite(o.scale) || Math.abs(o.scale) < 1e-6) return;
      let g = byName.get(o.name);
      if (!g) byName.set(o.name, (g = { name: o.name, list: [] }));
      g.list.push(i);
    });
    for (const [name, g0] of byName) {
      const n = g0.list.length;
      const mats = new Float32Array(n * 16), xz = new Float32Array(n * 2), sc = new Float32Array(n), heightOffsets = new Float64Array(n);
      g0.list.forEach((i, k) => {
        const o = mol.objects[i];
        p.set(o.x, this.heightAt(o.x, o.z) + o.y, o.z);
        q.set(o.qx, o.qy, o.qz, o.qw);
        if (q.lengthSq() < 1e-8) q.identity(); else q.normalize();
        s.setScalar(o.scale);
        m.compose(p, q, s);
        m.toArray(mats, k * 16);
        xz[k * 2] = o.x; xz[k * 2 + 1] = o.z;
        sc[k] = Math.abs(o.scale);
        heightOffsets[k] = o.y;
      });
      const cat = molCategory(name);
      this.groups.push({
        name, cat, n, mats, xz, sc, heightOffsets, helperRanges: new Map(), state: 'pending', minD2: Infinity,
        radius: 1, inst: null, model: null, visible: new Int32Array(0), visCount: -1,
        anim: null, flags: {},
      });
    }
    this.placementCount = mol.objects.length;
    this.stats.names = this.groups.length;
    this.stats.placements = this.placementCount;
    const f = focus || { x: 256, z: 256 };
    this._cam = { x: f.x, z: f.z };
    this._prioritise();
    // names near the focus: wait for them
    const r2 = nearRadius * nearRadius;
    const near = this.groups.filter(g => g.minD2 <= r2);
    let done = 0;
    const total = near.length;
    onProgress(0, `Objects 0/${total}`);
    const nearDone = Promise.all(near.map(g => new Promise(res => { g._onDone = () => { done++; onProgress(done / Math.max(1, total), `Objects ${done}/${total}`); res(); }; })));
    this._pump();
    let timer;
    try{await Promise.race([nearDone,new Promise(res=>{timer=setTimeout(res,timeoutMs);})]);}
    finally{clearTimeout(timer);}
    this._rebuildAll(true);
  }

  /** Re-sort the pending queue by distance to the camera (FILE frame). */
  _prioritise() {
    const cx = this._cam.x, cz = this._cam.z;
    for (const g of this.groups) {
      if (g.state !== 'pending') continue;
      let best = Infinity;
      const xz = g.xz;
      for (let k = 0; k < g.n; k++) {
        const dx = xz[k * 2] - cx, dz = xz[k * 2 + 1] - cz, d = dx * dx + dz * dz;
        if (d < best) best = d;
      }
      g.minD2 = best;
    }
    this._queue = this.groups.filter(g => g.state === 'pending').sort((a, b) => a.minD2 - b.minD2);
    this.stats.pending = this._queue.length;
  }

  _pump() {
    while (!this._disposed && this._active < WORKERS && this._queue.length) {
      const g = this._queue.shift();
      if (g.state !== 'pending') continue;
      g.state = 'loading';
      this._active++;
      this._loadGroup(g).catch(err => { console.warn('[world] object failed', g.name, err); g.state = 'failed'; })
        .finally(() => {
          this._active--;
          if (g.state === 'loading') g.state = 'failed';
          if (g.state === 'failed') { this.stats.failed++; this.stats.missing.push(g.name); } else this.stats.loaded++;
          this.stats.pending = this._queue.length;
          if (g._onDone) { const cb = g._onDone; g._onDone = null; cb(); }
          if (!this._disposed && g.state === 'ready') this._rebuildGroup(g, true);
          this._pump();
        });
    }
  }

  async _loadGroup(g) {
    const r = await resolveObjectAsync(g.name, this._db, fetchText);
    if (this._disposed) return;
    g.r = r;
    const flags = r.flags || {};
    const uv = Array.isArray(flags.uvanim) ? flags.uvanim : null;
    g.flags = {
      twoSide: flagOn(flags.twoside), transparent: flagOn(flags.transparent), maxDiffuse: flagOn(flags.maxdiffuse),
      fog: objectFog(flags),
      objectBump: flagOn(flags.bump),
      objectShininess: Number.isFinite(flags.shininess) ? flags.shininess : null,
      shadow: Number(flags.shadow) === 1 || (flags.meshtype && ['tree', 'building', 'house'].includes(flags.meshtype) && Number(flags.shadow) !== 0),
      uvU: uv ? Number(uv[0]) || 0 : Number(flags.uvx) || 0,
      uvV: uv ? Number(uv[1]) || 0 : Number(flags.uvy) || 0,
      uvSpeed: uv ? Number(uv[2]) || 0 : Number(flags.uvspeed) || 0,
    };
    const meshKey = await firstExisting(r.candidates.mesh);
    if (!meshKey) { g.state = 'failed'; return; }
    const tpackKey = await firstExisting(r.candidates.tpack);
    const opts = { tpackKey: tpackKey || null, twoSide: g.flags.twoSide, transparent: g.flags.transparent, maxDiffuse: g.flags.maxDiffuse, fog: g.flags.fog, objectBump: g.flags.objectBump, objectShininess: g.flags.objectShininess };
    const model = await this.models.loadStatic(meshKey, opts);
    if (this._disposed) return;
    if (!model || !model.parts?.length) { g.state = 'failed'; return; }
    g.model = model;
    g.meshKey = meshKey;
    g.opts = opts;
    g.radius = Math.max(0.5, model.radius || 1);
    this._setCullSpheres(g, model);
    for (const p of model.parts) {
      applyShade(p.material);   // the client's sun fall-off (shade.js)
      this.game.hudOptions?.effects?.applyMaterial?.(p.material);
    }
    const inst = model.createInstanced(g.n);
    inst.object.name = `obj:${g.name}`;
    inst.object.traverse(o => {
      if (o.isMesh) { o.castShadow = false; o.receiveShadow = true; }
    });
    this.group.add(inst.object);
    freezeStatic(inst.object);
    g.inst = inst;
    // texture scroll
    if (g.flags.uvSpeed && (g.flags.uvU || g.flags.uvV)) this._setupUV(g);
    // walkable helper surfaces
    if (this.ground && model.helperList) {
      const hs = model.helperList.filter(h => /^ground/i.test(h.name) && h.positions && h.indices);
      if (hs.length) {
        for (let k = 0; k < g.n; k++) {
          const mm = g.mats.subarray(k * 16, k * 16 + 16);
          g.helperRanges.set(k, hs.map(h => this.ground.addMesh(h.positions, h.indices, mm)));
        }
        this.stats.groundTris = this.ground.size;
      }
    }
    // animated objects: skeleton + clip load with the mesh, so the bind pose is never drawn for one whose animation loads
    if (r.animated && r.candidates.skel.length && r.candidates.anim.length) {
      g.anim = { state: 'idle', model: null, clip: null, live: new Map(), rigs: null, skelCands: r.candidates.skel, animCands: r.candidates.anim, animTime: r.animTime };
      await this._ensureAnimModel(g);
      if (this._disposed) return;
    }
    g.state = 'ready';
  }

  /**
   * (opt-2 review) Hook the meshes of a static group (instanced parts, and the plain meshes finish() makes of mirrored placements:
   * another program variant) so that _staticCold knows when every material has been drawn once in each form that exists.
   */
  _hookStaticWarm(g) {
    if (!g.inst?.meshes || g.anim?.rigs) return;       // (a test stub of createInstanced may not expose the meshes: nothing to hook, nothing is held back)
    if (!g.warmI) { g.warmI = new Set(); g.warmM = new Set(); g.needMats = new Set(g.inst.meshes.map(m => m.material)).size; g.hasMir = false; }
    if (g.warmI.size >= g.needMats && g.warmM.size >= g.needMats) return;
    if (g.warmI.size < g.needMats) for (const m of g.inst.meshes) hookWarm(m, g.warmI);
    g.hasMir = false;
    for (const c of g.inst.object.children) {
      if (c.isInstancedMesh || c.isRig || !c.isMesh) continue;
      g.hasMir = true;
      if (g.warmM.size < g.needMats) hookWarm(c, g.warmM);
    }
  }

  /** (opt-2 review) true while some form of a static group (instanced / mirrored) that has instances was never drawn yet. */
  _staticCold(g) {
    if (!g.warmI) return !!g.inst?.meshes;               // hooks not installed yet: hold the cull back (no meshes to hook: a stub, never held back)
    return (g.inst.meshes[0]?.count > 0 && g.warmI.size < g.needMats) || (g.hasMir && g.warmM.size < g.needMats);
  }

  /** (opt-2) One bounding sphere per placement (FILE frame: centre xyz, radius) for the per-group frustum test of _cullDraw. */
  _setCullSpheres(g, model) {
    g.sph = null;
    if (!g.mats || !(g.mats.length >= g.n * 16)) return;
    const r = modelCullRadius(model);
    if (r === null) return;
    const c = model.center, sph = new Float32Array(g.n * 4), e = new Float32Array(16);
    for (let i = 0; i < g.n; i++) {
      for (let k = 0; k < 16; k++) e[k] = g.mats[i * 16 + k];
      sph[i * 4] = e[0] * c.x + e[4] * c.y + e[8] * c.z + e[12];
      sph[i * 4 + 1] = e[1] * c.x + e[5] * c.y + e[9] * c.z + e[13];
      sph[i * 4 + 2] = e[2] * c.x + e[6] * c.y + e[10] * c.z + e[14];
      sph[i * 4 + 3] = r * maxSingular3(e);
    }
    g.sph = sph;
  }

  _setupUV(g) {
    const maps = [];
    g.inst.object.traverse(o => {
      if (!o.isMesh || !o.material || Array.isArray(o.material)) return;
      if (!o.material.map) return;
      const mat = o.material.clone();
      mat.map = o.material.map.clone();
      mat.map.wrapS = mat.map.wrapT = THREE.RepeatWrapping;
      mat.map.needsUpdate = true;
      if (mat.normalMap && mat.userData.dkObjectNormalBasis) {
        mat.normalMap = mat.normalMap.clone();
        mat.normalMap.needsUpdate = true;
        patchObjectNormalBasis(mat);
        maps.push(mat.normalMap);
      }
      applyShade(mat);
      this.game.hudOptions?.effects?.applyMaterial?.(mat);
      o.material = mat;
      maps.push(mat.map);
      (g.ownMaterials = g.ownMaterials || []).push(mat);
    });
    if (maps.length) this._uvGroups.push({ g, maps });
  }

  // ------------------------------------------------------------------------------------ visibility
  _limit(g, k) {
    const distance = g.flags?.fog === false ? (this.viewDistance ?? this.cullDistance) : this.cullDistance;
    const d = distance + g.radius * g.sc[k];
    return d * d;
  }

  /** Rewrite the visible instances of one name (only when the visible set changed, unless force). */
  _rebuildGroup(g, force = false) {
    if (!g.inst) return;
    const cx = this._cam.x, cz = this._cam.z;
    const list = this._tmpList || (this._tmpList = new Int32Array(1024));
    let ids = list.length >= g.n ? list : (this._tmpList = new Int32Array(Math.max(g.n, list.length * 2)));
    let k = 0;
    const live = g.anim && g.anim.live;
    for (let i = 0; i < g.n; i++) {
      const dx = g.xz[i * 2] - cx, dz = g.xz[i * 2 + 1] - cz;
      if (dx * dx + dz * dz > this._limit(g, i)) continue;
      if (live && live.has(i)) continue;
      if (g.occ && g.occ.has(i)) continue;          // (playgate) between the camera and the player: see _occlusion
      ids[k++] = i;
    }
    if (!force && k === g.visCount) {
      let same = true;
      for (let i = 0; i < k; i++) if (g.visible[i] !== ids[i]) { same = false; break; }
      if (same) return;
    }
    if (g.visible.length < k) g.visible = new Int32Array(Math.max(k, 8));
    g.visible.set(ids.subarray(0, k));
    g.visCount = k;
    const m = this._tmpM || (this._tmpM = new THREE.Matrix4());
    for (let i = 0; i < k; i++) { m.fromArray(g.mats, ids[i] * 16); g.inst.setMatrixAt(i, m); }
    g.inst.finish(k);
    g.inst.object.visible = k > 0;
    g.inst.object.traverse(o => { if (o.isMesh && !o.isInstancedMesh) { o.castShadow = false; o.receiveShadow = true; } });
    if (g.anim?.state === 'ready') this._fillRigs(g, ids, k);
    this._hookStaticWarm(g);
    if (g.inst.object.matrixWorldAutoUpdate === false) freezeStatic(g.inst.object);   // mirrored meshes may be new
  }

  _rebuildAll(force = false) {
    let vis = 0;
    for (const g of this.groups) {
      if (g.state !== 'ready') continue;
      this._rebuildGroup(g, force);
      vis += Math.max(0, g.visCount);
    }
    this.stats.visible = vis;
  }

  /** Height-only native placements retain model/material/animation/visibility identities.
   * Includes pending groups: later helper loading uses their updated matrices. */
  prepareTerrainHeights(affectedCells, width, height) {
    const result = [];
    for (const g of this.groups) for (let i = 0; i < g.n; i++) {
      const x = g.xz[i * 2], z = g.xz[i * 2 + 1];
      const cx = Math.max(0, Math.min(width - 1, Math.floor(x))), cz = Math.max(0, Math.min(height - 1, Math.floor(z)));
      if (!affectedCells.has(cz * width + cx)) continue;
      if (!g.heightOffsets || !g.helperRanges) throw Error('Native placement height tracking unavailable.');
      const before = g.mats[i * 16 + 13], after = Math.fround(this.heightAt(x, z) + g.heightOffsets[i]);
      if (!Number.isFinite(after)) throw Error('Invalid native placement floor.');
      if (before !== after) result.push({ g, i, before, after, live: g.anim?.live?.get(i), liveY: g.anim?.live?.get(i)?.inst?.root?.position.y });
    }
    return result;
  }

  applyTerrainHeights(plan, restore = false) {
    const groups = new Set();
    for (const p of plan) {
      const y = restore ? p.before : p.after;
      if (p.g.sph) p.g.sph[p.i * 4 + 1] += y - p.g.mats[p.i * 16 + 13];     // (opt-2) the culling sphere follows the placement
      p.g.mats[p.i * 16 + 13] = y;
      for (const range of p.g.helperRanges.get(p.i) || []) this.ground.setMeshY(range, y);
      const root = p.live?.inst?.root;
      if (root) { root.position.y = restore ? p.liveY : p.liveY + y - p.before; root.updateMatrix(); root.updateMatrixWorld(true); }
      groups.add(p.g);
    }
    for (const g of groups) if (g.state === 'ready') this._rebuildGroup(g, true);
    return plan.length;
  }

  // ------------------------------------------------------------------------------------ animated objects
  async _ensureAnimModel(g) {
    const a = g.anim;
    if (a.state !== 'idle') return;
    a.state = 'loading';
    try {
      const [skelKey, animKey] = await Promise.all([firstExisting(a.skelCands), firstExisting(a.animCands)]);
      if (!skelKey || !animKey || this._disposed) { a.state = 'failed'; return; }
      const model = await this.models.loadSkinned({ skelKey, parts: [{ meshKey: g.meshKey, ...g.opts }] });
      if (!model || model.missingSkeleton) { a.state = 'failed'; return; }
      const dur = Number(a.animTime) > 0 ? Number(a.animTime) : undefined;
      const clip = await this.models.loadClip(animKey, model, { duration: dur });
      const Animator = await loadAnimator();
      if (!clip || !Animator || !clip.tracks.length) { a.state = 'failed'; return; }
      a.model = model; a.clip = clip; a.Animator = Animator;
      a.state = 'ready';
    } catch (err) {
      console.warn('[world] animated object failed', g.name, err);
      a.state = 'failed';
    }
  }

  /**
   * (graphics) ANIMATED OBJECT RIGS. Every placement inside the draw distance is drawn animated (no LOD stand-in: the
   * object tables give no LOD distance). Placement i belongs to rig i % PHASES; each rig = one skeleton + one looping
   * Animator whose clip time is the layer clock + the rig's phase offset (so the pose is continuous across visibility
   * changes, rebuilds and map-time). Each rig draws its placements with one InstancedSkinnedMesh per part; mirrored
   * placements (negative scale) get their own set whose object matrix mirrors back, so the renderer's front-face rule
   * holds. The bind-pose InstancedMesh stays (hidden) for raycasts. Returns false when the rig cannot be built.
   */
  _buildRigs(g) {
    const a = g.anim, model = a.model;
    if (!model?.parts?.length || !a.clip || !a.Animator) return false;
    const K = Math.max(1, Math.min(PHASES, g.n)), m = new THREE.Matrix4();
    const keyOf = new Int32Array(g.n), counts = new Map();
    for (let i = 0; i < g.n; i++) {
      m.fromArray(g.mats, i * 16);
      const key = (i % K) * 2 + (m.determinant() < 0 ? 1 : 0);
      keyOf[i] = key;
      counts.set(key, (counts.get(key) || 0) + 1);
    }
    const sphere = new THREE.Sphere(model.sphere.center.clone(), model.sphere.radius * 1.6 + 0.5);
    const setIndex = new Map();
    a.rigs = []; a.sets = []; a.setOf = new Int32Array(g.n);
    for (let k = 0; k < K; k++) {
      const inst = model.instantiate();
      inst.skeleton.update = rigSkeletonUpdate;         // (opt-2) bone matrices / bone texture only after a pose
      const animator = new a.Animator(inst);
      animator.play(a.clip, { loop: true, fade: 0 });
      const rig = { inst, animator, offset: (k / K) * a.clip.duration, sets: [], need: true, stale: false };
      a.rigs.push(rig);
      if (k === 0) a.reach = rigReach(model, inst, animator, a.clip);    // (opt-2) before the first pose; leaves rig 0 posed at the last sample
      for (const mirror of [false, true]) {
        const key = k * 2 + (mirror ? 1 : 0), n = counts.get(key) || 0;
        if (!n) continue;
        const matrix = new THREE.InstancedBufferAttribute(new Float32Array(n * 16), 16).setUsage(THREE.DynamicDrawUsage);
        const meshes = model.parts.map(part => {
          applyShade(part.material);       // the client's sun fall-off (shade.js), as on every other world material
          const h = new InstancedSkinnedMesh(shareGeometry(part.geometry), part.material, matrix, inst.skeleton, sphere);
          h.name = `rig:${part.name}`;
          h.castShadow = !!g.flags.shadow; h.receiveShadow = true;
          if (mirror) h.scale.x = -1;
          g.inst.object.add(h);
          return h;
        });
        setIndex.set(key, a.sets.length);
        const set = { meshes, matrix, mirror, count: 0, rig, sph: new Float32Array(n * 4), drawn: true, warmMain: new Set(), warmShad: new Set(), needMats: new Set(meshes.map(h => h.material)).size };
        for (const h of meshes) { hookWarm(h, set.warmMain); hookWarm(h, set.warmShad, true); }    // (opt-2 review) see hookWarm (the shadow hook only ever fires for a caster)
        rig.sets.push(set);
        a.sets.push(set);
      }
    }
    for (let i = 0; i < g.n; i++) a.setOf[i] = setIndex.get(keyOf[i]);
    g._gi = this.groups.indexOf(g);
    this._rigGroups.push(g);
    this._poseRigs(g);
    return true;
  }

  /** Write the visible placements (ids[0..k)) into the rig sets and hide the bind-pose draw. */
  _fillRigs(g, ids, k) {
    const a = g.anim;
    if (!a.rigs && !this._buildRigs(g)) return;
    const m = this._tmpM || (this._tmpM = new THREE.Matrix4());
    const c = a.model.sphere.center, R = Number.isFinite(a.reach) ? Math.max(a.reach, a.model.sphere.radius) * RIG_REACH_SCALE + RIG_REACH_ADD : Infinity;
    for (const s of a.sets) s.count = 0;
    for (let j = 0; j < k; j++) {
      const i = ids[j], s = a.sets[a.setOf[i]];
      m.fromArray(g.mats, i * 16);
      if (s.mirror) m.premultiply(MIRROR_X);     // the set's own matrix mirrors it back (instance determinant > 0)
      m.toArray(s.matrix.array, s.count * 16);
      // (opt-2) culling sphere of this instance in the mesh's own frame: the reach of the animated vertices around the bind centre
      const e = m.elements, q = s.count * 4;
      s.sph[q] = e[0] * c.x + e[4] * c.y + e[8] * c.z + e[12];
      s.sph[q + 1] = e[1] * c.x + e[5] * c.y + e[9] * c.z + e[13];
      s.sph[q + 2] = e[2] * c.x + e[6] * c.y + e[10] * c.z + e[14];
      s.sph[q + 3] = R * maxSingular3(e);
      s.count++;
    }
    for (const s of a.sets) {
      s.matrix.needsUpdate = true;
      s.drawn = s.count > 0;
      for (const h of s.meshes) { h.count = s.count; h.visible = s.count > 0; }
    }
    for (const c of g.inst.object.children) if (!c.isRig) c.visible = false;
  }

  /** Rig poses at the layer clock: clip time = (layer time + rig offset) mod duration. */
  _poseRigs(g, onlyDrawn = false) {
    const a = g.anim;
    for (const r of a.rigs) {
      if (onlyDrawn && !r.need) { r.stale = true; continue; }    // (opt-2) no set of this rig is drawn: _cullDraw poses it when one is
      this._poseRig(a, r);
    }
  }

  _poseRig(a, r) {
    const dur = a.clip.duration;
    r.animator.current.time = dur > 0 ? (((this._time + r.offset) % dur) + dur) % dur : 0;
    r.animator.update(0);
    r.inst.root.updateMatrixWorld(true);
    r.inst.skeleton._dkPoseDirty = true;        // (opt-2) rigSkeletonUpdate rebuilds the bone matrices once for this pose
    r.stale = false;
  }

  _updateAnimated() {
    let drawn = 0;
    this._animFrame = (this._animFrame || 0) + 1;
    const lod = ANIM_OBJECT_LOD, lodOff = globalThis.__dekaronNoAnimLod === true;
    const cx = this._cam.x, cz = this._cam.z;
    const rigGroups = this._rigGroups;
    for (let n = 0; n < rigGroups.length; n++) {
      const g = rigGroups[n], gi = g._gi;
      if (!g.anim?.rigs || !(g.visCount > 0)) { if (g.anim?.rigs) for (const r of g.anim.rigs) r.stale = true; continue; }     // nothing drawn: the clock keeps the phase meanwhile
      // ANIMATION LOD (2.2.1, like the actors' in actor.js): a group whose nearest drawn placement is far from the camera is
      // re-posed every 2nd / 3rd frame. Poses are at the layer clock (absolute time), so a skipped frame costs nothing in phase.
      // Every drawn rig walked its whole matrix tree each frame: 1.7 ms of every 16.7 ms frame in Ardeca (measured).
      if (!lodOff) {
        let best = Infinity;
        for (let i = 0; i < g.visCount; i++) { const id = g.visible[i], dx = g.xz[id * 2] - cx, dz = g.xz[id * 2 + 1] - cz, d = dx * dx + dz * dz; if (d < best) best = d; }
        const every = best < lod.near * lod.near ? 1 : best < lod.far * lod.far ? 2 : 3;
        if (every > 1 && (this._animFrame + gi) % every !== 0) { drawn += g.visCount; continue; }
      }
      this._poseRigs(g, true);
      drawn += g.visCount;
    }
    this.stats.animated = drawn;
  }

  /**
   * (opt-2) Run by three.js inside every render of the scene (RigCullNode.update), with the camera of that render. For the game
   * camera: a static group is drawn when one of its distance-visible placements (sphere = the model's part spheres) touches the
   * camera frustum; a rig set is drawn when one of its instances (sphere = reach of the animated vertices) touches it, and
   * casts a shadow when one touches the sun's depth frustum (the frustum the depth pass of THIS render uses: the shadow box
   * was snapped by ShadowTuner.update before the render). Anything else (another camera, the warm-up draw, the kill switch):
   * everything is drawn as before. A rig with a drawn set whose pose was skipped meanwhile is posed now, before it is projected.
   */
  _cullDraw(camera) {
    if (this._disposed) return;
    const game = this.game;
    const cull = camera === game?.camera && globalThis.__dekaronNoRigCull !== true && !this._cullBroken;
    let fr = null, frS = null, shadowOn = false;
    if (cull) {
      this._pm.multiplyMatrices(camera.projectionMatrix, camera.matrixWorldInverse);
      fr = planesOf(this._frC.setFromProjectionMatrix(this._pm), this._pc);
      const env = this.environment || game?.world?.environment, sun = env?.sun;
      shadowOn = !!(sun && sun.castShadow && game?.renderer?.shadowMap?.enabled);
      if (shadowOn) {
        // the depth pass's camera, rebuilt the way LightShadow.updateMatrices does (sun position, looking at its target, the shadow
        // camera's box) on a private camera: sun.shadow.matrix / camera are three.js' and ShadowTuner's and are not touched here
        const sc = sun.shadow.camera, c = this._shCam || (this._shCam = new THREE.OrthographicCamera());
        if (c.left !== sc.left || c.right !== sc.right || c.top !== sc.top || c.bottom !== sc.bottom || c.near !== sc.near || c.far !== sc.far || c.zoom !== sc.zoom) {
          c.left = sc.left; c.right = sc.right; c.top = sc.top; c.bottom = sc.bottom; c.near = sc.near; c.far = sc.far; c.zoom = sc.zoom;
          c.updateProjectionMatrix();
        }
        c.up.copy(sc.up);
        c.position.setFromMatrixPosition(sun.matrixWorld);
        c.lookAt(this._look.setFromMatrixPosition(sun.target.matrixWorld));
        c.updateMatrixWorld();
        frS = planesOf(this._frS.setFromProjectionMatrix(this._pm.multiplyMatrices(c.projectionMatrix, c.matrixWorldInverse)), this._ps);
      }
    }
    // every object under the layer's group has an identity local matrix (a rig set: x = -1 when mirrored), so they all stretch
    // a sphere by the same factor as the group itself (tools/test-rig-draw-path.mjs checks it on real objects)
    const ws = cull ? maxSingular3(this.group.matrixWorld.elements) : 1;
    // static groups (one InstancedMesh per part + mirrored copies under one object): hide the object when nothing of it is in view
    let groupsShown = 0, groupsHidden = 0;
    for (const g of this.groups) {
      if (g.state !== 'ready' || !g.inst || g.anim?.rigs) continue;
      const o = g.inst.object;
      let show = g.visCount > 0;
      if (cull && show && g.sph && !this._staticCold(g)) {      // (opt-2 review) never drawn yet: three.js decides, as before the cull
        const mw = o.matrixWorld.elements, sph = g.sph, vis = g.visible;
        show = false;
        for (let k = 0, n = g.visCount; k < n; k++) {
          const q = vis[k] * 4, x = sph[q], y = sph[q + 1], z = sph[q + 2];
          if (sphereInPlanes(fr, mw[0] * x + mw[4] * y + mw[8] * z + mw[12], mw[1] * x + mw[5] * y + mw[9] * z + mw[13], mw[2] * x + mw[6] * y + mw[10] * z + mw[14], sph[q + 3] * ws + RIG_CULL_PAD)) { show = true; break; }
        }
      }
      if (o.visible !== show) o.visible = show;
      if (show) groupsShown++; else if (g.visCount > 0) groupsHidden++;
    }
    this.stats.groupsDrawn = groupsShown; this.stats.groupsCulled = groupsHidden;
    let sets = 0, shown = 0;
    for (const g of this._rigGroups) {
      const a = g.anim;
      if (!a?.sets) continue;
      const caster = !!g.flags.shadow;
      for (const s of a.sets) {
        sets++;
        let main = true, shad = caster;
        if (cull && s.count > 0) {
          const h0 = s.meshes[0], mw = h0.matrixWorld.elements, sph = s.sph;
          main = false; shad = false;
          const needShadow = shadowOn && caster;
          for (let j = 0, n = s.count; j < n; j++) {
            const x = sph[j * 4], y = sph[j * 4 + 1], z = sph[j * 4 + 2], rr = sph[j * 4 + 3] * ws + RIG_CULL_PAD;
            const wx = mw[0] * x + mw[4] * y + mw[8] * z + mw[12], wy = mw[1] * x + mw[5] * y + mw[9] * z + mw[13], wz = mw[2] * x + mw[6] * y + mw[10] * z + mw[14];
            if (!main && sphereInPlanes(fr, wx, wy, wz, rr)) main = true;
            if (needShadow && !shad && sphereInPlanes(frS, wx, wy, wz, rr)) shad = true;
            if (main && (shad || !needShadow)) break;
          }
          if (!needShadow) shad = caster;               // no depth pass for this sun: leave the flag as it was
          // (opt-2 review) a set whose materials were never drawn (main pass / depth pass) is drawn in the next render whatever the frustum
          // says: its first-draw cost belongs to the streaming time, not to the moment the camera turns to it (see hookWarm)
          if (s.warmMain.size < s.needMats) main = true;
          if (needShadow && s.warmShad.size < s.needMats) shad = true;
        }
        const draw = s.count > 0 && (main || shad);
        s.drawn = draw;
        if (draw) shown++;
        for (const h of s.meshes) { h.visible = draw; h.castShadow = shad; }
      }
      for (const r of a.rigs) {
        let need = false;
        for (const s of r.sets) if (s.drawn) { need = true; break; }
        r.need = need;
        if (need && r.stale) this._poseRig(a, r);
      }
    }
    this.stats.rigSets = sets; this.stats.rigSetsDrawn = shown;
  }

  // ------------------------------------------------------------------------------------ frame
  /**
   * @param {number} dt
   * @param {number} camX FILE X of the camera (or of the player)
   * @param {number} camZ FILE Z
   * @param {number} cullDistance world units
   */
  update(dt, camX, camZ, cullDistance, viewDistance = cullDistance) {
    if (this._disposed) return;
    this._time += dt;
    this._cam.x = camX; this._cam.z = camZ;
    this._prioTimer -= dt;
    if (this._prioTimer <= 0) {
      this._prioTimer = PRIORITY_INTERVAL;
      if (this._queue.length) { this._prioritise(); this._pump(); }
    }
    this._cullTimer -= dt;
    const moved = Math.hypot(camX - this._lastCull.x, camZ - this._lastCull.z);
    if (this._cullTimer <= 0 && (moved > 1.5 || Math.abs(cullDistance - this._lastCull.dist) > 0.5 || viewDistance !== this._lastCull.view)) {
      this._cullTimer = CULL_INTERVAL;
      this.cullDistance = cullDistance;
      this.viewDistance = viewDistance;
      this._lastCull = { x: camX, z: camZ, dist: cullDistance, view: viewDistance };
      this._rebuildAll(false);
    }
    try { this._occlusion(dt); } catch (err) { if (!this._occErr) { this._occErr = true; console.warn('[world] occlusion', err); } }
    this._updateAnimated(dt);
    for (const u of this._uvGroups) {
      const f = u.g.flags, t = this._time * f.uvSpeed * UV_RATE;
      for (const map of u.maps) map.offset.set((t * f.uvU) % 1, (t * f.uvV) % 1);
    }
  }

  /**
   * (playgate) CAMERA OCCLUSION: props standing between the camera and the player (tree trunks and canopies, rocks,
   * pillars, fences - bounding radius up to OCC_MAX_R) leave the visible set while they block the line of sight and
   * come back once it is clear, so the character never disappears behind a tree or the camera sits inside a canopy
   * (Dead Front forests, Ardeca trees). Checked every OCC_INTERVAL s against the visible instances plus the hidden ones.
   */
  _occlusion(dt) {
    const game = this.game, p = game?.player, cam = game?.camera;
    // This assist only belongs to the orbit view. A short eye/head segment or a remote GM view must not erase
    // nearby scenery, and an old orbit exclusion must be restored before its timer can delay the next check.
    if (!p || !cam || p.disposed || game.cam?.mode === 'first-person' || game.gm?.freecam?.on) {
      this._clearOcclusion();
      return;
    }
    const ax = cam.position.x, ay = cam.position.y, az = -cam.position.z;          // THREE -> FILE frame
    const bx = p.x, by = (Number(p.y) || 0) + Math.min(1.6, (p.height || 1.8) * 0.8), bz = p.z;
    const dx = bx - ax, dy = by - ay, dz = bz - az;
    const len2 = dx * dx + dy * dy + dz * dz;
    if (!(len2 > 0.01)) { this._clearOcclusion(); return; }
    this._occT = (this._occT || 0) - dt;
    if (this._occT > 0) return;
    this._occT = OCC_INTERVAL;
    const minX = Math.min(ax, bx) - OCC_MAX_R, maxX = Math.max(ax, bx) + OCC_MAX_R;
    const minZ = Math.min(az, bz) - OCC_MAX_R, maxZ = Math.max(az, bz) + OCC_MAX_R;
    const v = this._occV || (this._occV = new THREE.Vector3());
    const m = this._occM || (this._occM = new THREE.Matrix4());
    const test = (g, i) => {
      const x = g.xz[i * 2], z = g.xz[i * 2 + 1];
      if (x < minX || x > maxX || z < minZ || z > maxZ) return false;
      const sc = g.sc?.[i] || 1;
      const r = (g.model.radius || 1) * sc * OCC_SHRINK;
      if (!(r > 0.3) || r > this._occLimit(g)) return false;   // (tall trees too; buildings: cameraClip)
      v.copy(g.model.center || v.set(0, 0, 0)).applyMatrix4(m.fromArray(g.mats, i * 16));
      // closest point of the camera -> head segment to the centre (the part right next to the head does not count:
      // the player may stand against a tree without it vanishing)
      const t = ((v.x - ax) * dx + (v.y - ay) * dy + (v.z - az) * dz) / len2;
      if (t <= 0 || t >= 0.92) return false;
      const qx = ax + dx * t - v.x, qy = ay + dy * t - v.y, qz = az + dz * t - v.z;
      return qx * qx + qy * qy + qz * qz < r * r;
    };
    for (const g of this.groups) {
      if (g.state !== 'ready' || !g.inst || !g.model || !g.xz) continue;
      let next = null;
      for (let k = 0; k < g.visCount; k++) { const i = g.visible[k]; if (test(g, i)) (next || (next = new Set())).add(i); }
      if (g.occ) for (const i of g.occ) if (test(g, i)) (next || (next = new Set())).add(i);
      const prev = g.occ;
      const same = (!prev || !prev.size) ? !next : (next && next.size === prev.size && [...next].every(i => prev.has(i)));
      if (same) continue;
      g.occ = next;
      this._rebuildGroup(g, true);
    }
  }

  _clearOcclusion() {
    this._occT = 0;
    for (const g of this.groups) {
      if (!g.occ?.size) continue;
      g.occ = null;
      this._rebuildGroup(g, true);
    }
  }

  /** Radius above which a placement is never hidden by _occlusion (buildings, walls, bridges). */
  _occLimit(g) {
    if (OCC_SOLID.has(g.cat)) return 0;             // buildings, houses, walls, bridges: the camera pulls in instead
    // Native gates/entrances also occur under field_extra. Their open arch has a
    // loose sphere across the doorway; proximity must not erase the whole gate.
    if (g.cat === 'field_extra' && /(?:gate|entrance)(?!_lamp)/i.test(g.name)) return 0;
    // Keep trees as scenery while approaching. Loose canopy spheres otherwise
    // erase the entire trunk/leaves at a distance threshold; use cameraClip instead.
    if (g.cat === 'tree' || /tree/i.test(g.name)) return 0;
    // Authored ground triangles also support movement. Hiding the owning floor/stair mesh would leave an
    // invisible surface under the player, including native stairs filed under the otherwise eligible 'etc'.
    if (g.model?.helperList?.some(h => /^ground/i.test(h.name) && h.positions && h.indices)) return 0;
    return g.cat === 'plant' || g.cat === 'tree' || /tree/i.test(g.name) ? OCC_MAX_R * 1.8 : OCC_MAX_R;
  }

  /**
   * (playgate) Camera collision against the big props _occlusion never hides (buildings, roofs, walls): the free
   * fraction (0..1) of the look -> camera segment, both THREE-frame points. The ray runs from the camera to the
   * player (single-sided walls face the camera) and the hit closest to the player wins.
   */
  cameraClip(look, pos) {
    if (this._disposed) return 1;
    if (!this._clipC || this._time - (this._clipAt ?? -9) > 0.3) { this._clipAt = this._time; this._clipC = this._clipCandidates(look); }
    if (!this._clipC.length) return 1;
    const dir = this._clipDir || (this._clipDir = new THREE.Vector3());
    dir.subVectors(look, pos);
    const len = dir.length();
    if (!(len > 0.8)) return 1;
    dir.divideScalar(len);
    const rc = this._clipRc || (this._clipRc = new THREE.Raycaster());
    rc.set(pos, dir); rc.near = 0; rc.far = len - 0.5;
    let far = -1;
    const hits = this._clipHits || (this._clipHits = []);
    for (const o of this._clipC) {
      hits.length = 0;
      rc.intersectObject(o, true, hits);
      for (const h of hits) if (h.distance > far) far = h.distance;
    }
    if (far < 0) return 1;
    return Math.max(0.05, (len - far - 0.4) / len);
  }

  _clipCandidates(look) {
    const fx = look.x, fz = -look.z;                  // THREE -> FILE
    const out = [];
    for (const g of this.groups) {
      if (g.state !== 'ready' || !g.inst || !g.model || !(g.visCount > 0)) continue;
      const lim = this._occLimit(g), R = g.model.radius || 0;
      let near = false;
      for (let k = 0; k < g.visCount && !near; k++) {
        const i = g.visible[k], r = R * (g.sc[i] || 1);
        if (r * OCC_SHRINK <= lim) continue;           // small props are hidden instead
        if (Math.hypot(g.xz[i * 2] - fx, g.xz[i * 2 + 1] - fz) < r + 32) near = true;
      }
      if (near) out.push(g.inst.object);
    }
    return out;
  }

  /**
   * @param {{releaseGPU?:boolean}} [opts] releaseGPU: also free the GPU copies of the geometries and textures of the
   *   models this map used. They belong to the shared Model/TextureCache, which keep the CPU data: three.js simply
   *   re-uploads them if a later map (or actor) draws them again. Without this, GPU memory grows with every map.
   */
  dispose({ releaseGPU = true } = {}) {
    this._disposed = true;
    this._queue = [];
    const geoms = new Set(), texs = new Set();
    const collect = (model) => {
      for (const p of model?.parts || []) {
        if (p.geometry) geoms.add(p.geometry);
        if (p.texture) texs.add(p.texture);
      }
    };
    for (const g of this.groups) {
      if (g._onDone) { const cb = g._onDone; g._onDone = null; cb(); }
      if (g.anim) {
        for (const e of g.anim.live.values()) { e.animator.dispose(); e.inst.dispose(); }
        for (const r of g.anim.rigs || []) { r.animator.dispose(); r.inst.dispose(); }
        for (const s of g.anim.sets || []) for (const h of s.meshes) { h.dispose(); releaseSharedGeometry(h.geometry); }
        collect(g.anim.model);
      }
      if (g.inst) g.inst.dispose();
      collect(g.model);
      for (const m of g.ownMaterials || []) { m.map?.dispose(); if (m.userData.dkObjectNormalBasis) m.normalMap?.dispose(); m.dispose(); }
    }
    if (releaseGPU) {
      for (const x of geoms) x.dispose();
      for (const t of texs) t.dispose();
    }
    this.groups = [];
    this._rigGroups = [];
    this.group.removeFromParent();
  }
}
