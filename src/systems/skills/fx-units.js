// Effect unit renderers (docs/formats/effects.md Ã‚Â§5.4): sprite (camera / yaxis / carpet / stand billboards), decal,
// skinned effect mesh, particle emitter, sound, camera quake and meshstatus (overlay pass).
//
// FRAME: every object here lives under the effect root (a child of game.worldRoot) in the raw FILE frame, like the
// rest of the world (ARCHITECTURE.md Ã‚Â§1). Camera vectors are converted with (x, y, -z). Textures keep NoColorSpace
// and flipY = false (TextureCache does both).
//
// Blending (billboard.fx / tracemesh.fx are fixed-function): 'add' = SrcAlpha, One; 'modulate' = SrcAlpha,
// InvSrcAlpha; meshes are additive unless the unit is `transparent` (then alpha blended). Colour = texture x control
// colour x alpha; no lighting; depth test on, depth write off.
import * as THREE from 'three';
import { AURA, auraValue } from '../../config/engine-chosen-aura.js';
import { LoopClock } from './loop-clock.js';
import { BILLBOARD_SAMPLER } from '../../engine/sampler-state.js';
import { warmThenShow } from '../../engine/shader-prewarm.js';
import { patchSpecular, releaseMaterial } from '../../engine/matfx.js';
import { SKILL_FX_QUALITY } from '../../config/engine-chosen-skill-fx.js';
import { applyDistort } from './fx-distort.js';
import { trailSpec, SpriteRibbon, MeshTrail, TrailSchedule, trailFade, fileFramePosition } from './fx-trails.js';

const _v = new THREE.Vector3();
const _v2 = new THREE.Vector3();
const _q = new THREE.Quaternion();
const _m = new THREE.Matrix4();
const MIRROR = new THREE.Matrix4().makeScale(1, 1, -1);
const UP = new THREE.Vector3(0, 1, 0);
const _leafColor = new THREE.Color(), _leafFwd = new THREE.Vector3(0, 0, 1);

export const blendOf = (b, transparentMesh) => {
  if (b === 'modulate' || transparentMesh) return THREE.NormalBlending;
  return THREE.AdditiveBlending;
};

/** Camera position and axes in the FILE frame (THREE world (x,y,z) -> FILE (x,y,-z)). */
export function cameraFrame(camera, out = {}) {
  out.pos = out.pos || new THREE.Vector3();
  out.right = out.right || new THREE.Vector3();
  out.up = out.up || new THREE.Vector3();
  out.fwd = out.fwd || new THREE.Vector3();
  camera.updateMatrixWorld();
  out.pos.setFromMatrixPosition(camera.matrixWorld); out.pos.z = -out.pos.z;
  const e = camera.matrixWorld.elements;
  out.right.set(e[0], e[1], -e[2]).normalize();
  out.up.set(e[4], e[5], -e[6]).normalize();
  out.fwd.set(-e[8], -e[9], e[10]).normalize();       // camera looks down its -Z
  return out;
}

/** Texture loader shared by all units (TextureCache, cached per key). */
export function loadTex(game, key, fixedSampler = null) {
  if (!key || !game?.textures) return Promise.resolve(null);
  return game.textures.load(key, fixedSampler ? {fixedSampler} : {}).then(t => {
    if (t) { t.flipY = false; t.colorSpace = THREE.NoColorSpace; t.wrapS = t.wrapT = THREE.RepeatWrapping; }
    return t;
  }).catch(() => null);
}

/** Frame index of a flipbook at `ms` (texLoop increase / decrease / cycle over texAnimMs per pass). */
export function flipFrame(unit, ms, nFrames, seed = 0) {
  if (nFrames <= 1) return 0;
  const per = Number(unit.texAnimMs) || 0;
  if (!(per > 0)) return Math.floor(seed * nFrames) % nFrames;       // no animation: a random frame (particles)
  const pos = (ms / per) * nFrames;
  const mode = unit.texLoop || 'increase';
  if (mode === 'cycle') {
    const span = Math.max(1, 2 * nFrames - 2);
    const k = Math.floor(pos) % span;
    return k < nFrames ? k : span - k;
  }
  const k = Math.floor(pos) % nFrames;
  return mode === 'decrease' ? nFrames - 1 - k : k;
}

/** INFERENCE TO REVIEW (CHANGES-4.1.0.md): an effect mesh whose texture failed to load. Native D3D9 leaves a null texture
 * bound, which samples (0,0,0,1); under additive blend that adds nothing. Additive + no map -> black (no white fallback).
 * Any other case keeps white. Textured meshes (incl. mesh-named tpack fallbacks) are unchanged. */
export function nullTextureColor(map, blending) {
  return !map && blending === THREE.AdditiveBlending ? 0x000000 : 0xffffff;
}

/** Whether an effect mesh keeps its source material's env specular (boneanimation.fx psEnvSpecular). 'safe' quality skips it. */
export function keepEffectSpecular(src, quality = SKILL_FX_QUALITY.level) {
  return quality !== 'safe' && !!src?.specularMap && src?.userData?.dkSpec === 'env';
}
/** mesh_status UV scroll of a unit, or null when it authors no motion. Pure. */
export function meshUvScroll(unit) {
  const ms = unit?.meshStatus; if (!ms) return null;
  const a = Number(ms.a) || 0, b = Number(ms.b) || 0;
  return b ? { angle: a, speed: b } : null;
}
/** UV offset after `seconds`: `speed` UV per second along `angle` degrees, wrapped to (-1, 1). Pure. */
export function uvScrollOffset(scroll, seconds) {
  const angle = (Number(scroll?.angle) || 0) * Math.PI / 180, travel = (Number(scroll?.speed) || 0) * seconds;
  return [(Math.sin(angle) * travel) % 1, (Math.cos(angle) * travel) % 1];
}

// ============================================================================================ base
class Unit {
  constructor(ctx, unit) {
    this.ctx = ctx;            // { game, fx (EffectPlayer), control, play (ScenePlay) }
    this.unit = unit;
    this.object = null;        // THREE.Object3D under the control's anchor
    this.disposed = false;
    this.ready = false;
  }
  get game() { return this.ctx.game; }
  /** st: {scale:[x,y,z], alpha, color:[r,g,b], rot (deg), ms (since the control start), life (ms), frac} */
  apply() {}
  update() {}
  finishing() { return !!this.trail?.alive; }   // particles and trails keep living after the control ended
  stopEmitting() { this.trail?.stop(); if (this.object && !this.keepObjectWhileFading) this.object.visible = false; }
  dispose() {
    this.disposed = true;
    if (this.object) {
      this.object.removeFromParent();
      this.object.traverse(o => {
        if (o.isMesh || o.isSprite || o.isPoints) {
          if (o.userData.ownGeo) o.geometry?.dispose();
          const mats = Array.isArray(o.material) ? o.material : [o.material];
          for (const m of mats) if (m && o.userData.ownMat !== false) m.dispose?.();
        }
      });
      this.object = null;
    }
    this.trail?.dispose(); this.trail = null;
  }
}

// ============================================================================================ sprite
/** Billboard quad: camera (faces the camera, rotation = roll), yaxis (cylindrical), carpet (flat, rotation about up),
 *  stand (vertical, fixed). Flipbook from `frames` (tpack slots) or a single `texture`. */
export class SpriteUnit extends Unit {
  constructor(ctx, unit, parent) {
    super(ctx, unit);
    const bb = unit.billboard || 'camera';
    this.bb = bb;
    this.anchor = parent;
    let mesh, mat;
    // `backprint` is read as "no depth test" (docs/formats/effects.md, [low] confidence). The authored gem-socket sprites carry
    // `backprint true`, which drew a worn weapon's gem mist through walls, so sprites worn on gear (equipment effects play with
    // particleSpace 'attachment') are always depth-tested.
    const depthTest = ctx.play?.particleSpace === 'attachment' || !unit.backPrint;
    if (bb === 'camera') {
      // THREE.Sprite faces the camera in the shader whatever the parent transform (mirror / bone rotation)
      mat = new THREE.SpriteMaterial({
        transparent: true, depthWrite: false, blending: blendOf(unit.blend), color: 0xffffff, opacity: 1, fog: true,
        depthTest,
      });
      // A sprite that sits inside its owner's mesh (gem mist on a blade) keeps its place and size but its DEPTH is shifted toward
      // the camera, so the owner's own surface does not clip it while world geometry in front still hides it.
      const bias = ctx.play?.depthBias || 0;
      if (bias > 0) {
        const uniform = { value: bias };
        mat.onBeforeCompile = shader => {
          shader.uniforms.dkDepthBias = uniform;
          shader.vertexShader = shader.vertexShader
            .replace('uniform float rotation;', 'uniform float rotation;\nuniform float dkDepthBias;')
            .replace('gl_Position = projectionMatrix * mvPosition;', `gl_Position = projectionMatrix * mvPosition;
	{ vec4 dkNear = projectionMatrix * vec4( mvPosition.xy, mvPosition.z + dkDepthBias, 1.0 ); gl_Position.z = dkNear.z * gl_Position.w / dkNear.w; }`);
        };
        mat.customProgramCacheKey = () => 'sprite-depth-bias';
      }
      mesh = new THREE.Sprite(mat);
      if (unit.distort) applyDistort(mesh);    // DISTORT.MODE 'off' by default: drawn as an ordinary sprite
    } else {
      mat = new THREE.MeshBasicMaterial({
        transparent: true, depthWrite: false, blending: blendOf(unit.blend), side: THREE.DoubleSide,
        // This single planar quad has only one visible face. The other pass
        // would be entirely culled; retaining DoubleSide preserves both views.
        forceSinglePass: true,
        color: 0xffffff, opacity: 1, fog: true, depthTest,
      });
      const geo = new THREE.PlaneGeometry(1, 1);
      if (bb === 'carpet') geo.rotateX(-Math.PI / 2);
      mesh = new THREE.Mesh(geo, mat);
      mesh.userData.ownGeo = true;
    }
    mat.visible = false;
    mesh.renderOrder = 10;
    mesh.frustumCulled = false;
    this.mesh = mesh;
    this.object = new THREE.Group();
    this.object.add(mesh);
    parent.add(this.object);
    this.textures = [];
    const keys = unit.frames?.length ? unit.frames : unit.texture ? [unit.texture] : [];
    this.seed = Math.random();
    const spec = trailSpec(unit);
    if (spec && ctx.fx?.root) { this.trail = new SpriteRibbon(ctx.fx, unit, spec, blendOf(unit.blend)); this._head = { p: new THREE.Vector3(), w: 1, color: null, alpha: 1, map: null }; }
    this.readyTask = Promise.all(keys.map(k => loadTex(this.game, k, BILLBOARD_SAMPLER))).then(ts => {
      if (this.disposed) return;
      this.textures = ts.filter(Boolean);
      if (!this.textures.length) return;
      mat.map = this.textures[0]; mat.needsUpdate = true;
      mat.visible = true;
      this.ready = true;
    });
  }
  update(dt) {
    if (!this.trail || this.disposed) return;
    const m = this.mesh, h = this._head;
    if (this.trail.emitting && this.ready && m.material.visible) {
      fileFramePosition(this.ctx.fx, m, h.p);
      h.w = Math.abs(m.scale.x);
      h.color = this._color; h.alpha = m.material.opacity; h.map = m.material.map;
      this.trail.update(dt, h);
    } else this.trail.update(dt, null);
  }
  apply(st) {
    const u = this.unit, m = this.mesh, mat = m.material;
    const size = Number(u.size) || 1;
    const s = st.scale || [1, 1, 1];
    this._color = st.color || null;
    mat.opacity = Math.max(0, Math.min(1, st.alpha ?? 1));
    if (st.color) mat.color.setRGB(st.color[0], st.color[1], st.color[2]);
    if (this.textures.length > 1) {
      const f = flipFrame(u, st.ms, this.textures.length, this.seed);
      if (mat.map !== this.textures[f]) { mat.map = this.textures[f]; }
    }
    const rot = THREE.MathUtils.degToRad(st.rot || 0);
    const cam = this.ctx.fx.cam;
    if (this.bb === 'carpet') {
      m.scale.set(size * s[0], 1, size * (s[2] || s[1] || s[0]));
      m.rotation.set(0, rot, 0);
      return;
    }
    m.scale.set(size * s[0], size * (s[1] ?? s[0]), 1);
    if (this.bb === 'camera') { mat.rotation = rot; return; }
    if (this.bb === 'stand') { m.rotation.set(0, rot, 0); return; }
    // yaxis (cylindrical) billboard: turn about the up axis towards the camera, in the FILE frame. The anchor's own
    // rotation (FILE frame, set by the effect player) is cancelled so a bone-attached sprite still stands upright.
    const a = this.anchor;
    a.updateWorldMatrix(true, true);
    const wp = _v.setFromMatrixPosition(m.parent.matrixWorld);         // THREE space
    wp.z = -wp.z;                                                       // -> FILE
    const toCam = _v2.copy(cam.pos).sub(wp);
    const yaw = Math.atan2(toCam.x, toCam.z);                           // plane normal (local +Z) towards the camera
    _q.copy(a.quaternion).invert();
    m.quaternion.setFromAxisAngle(UP, yaw).premultiply(_q);
    m.rotateZ(rot);
    // mirrored-bone anchor (scale.x -1, see ControlPlay._placeAnchor): local = R * P keeps the world facing P, unmirrored
    if (a.scale.x < 0) { const q = m.quaternion; q.set(q.x, -q.y, -q.z, q.w); m.scale.x = -m.scale.x; }
  }
}

// ============================================================================================ decal
/** Ground decal: a small grid lying on the terrain under the anchor, radius = size x scale. */
export class DecalUnit extends Unit {
  constructor(ctx, unit, parent) {
    super(ctx, unit);
    const N = 6;
    const geo = new THREE.PlaneGeometry(2, 2, N, N);
    geo.rotateX(-Math.PI / 2);
    this.base = geo.attributes.position.array.slice();
    const mat = new THREE.MeshBasicMaterial({
      transparent: true, depthWrite: false, blending: blendOf(unit.blend), side: THREE.DoubleSide,
      polygonOffset: true, polygonOffsetFactor: -2, polygonOffsetUnits: -4,
    });
    mat.visible = false;
    const mesh = new THREE.Mesh(geo, mat);
    mesh.userData.ownGeo = true;
    mesh.frustumCulled = false;
    mesh.renderOrder = 5;
    this.mesh = mesh;
    // decals live directly under the effect root (world aligned), positioned from the anchor each frame
    this.object = new THREE.Group();
    this.object.add(mesh);
    ctx.fx.root.add(this.object);
    this.anchor = parent;
    this.textures = [];
    const keys = unit.frames?.length ? unit.frames : unit.texture ? [unit.texture] : [];
    this.readyTask = Promise.all(keys.map(k => loadTex(this.game, k))).then(ts => {
      if (this.disposed) return;
      this.textures = ts.filter(Boolean);
      if (!this.textures.length) return;
      mat.map = this.textures[0]; mat.needsUpdate = true; mat.visible = true; this.ready = true;
    });
  }
  apply(st) {
    const u = this.unit, mat = this.mesh.material;
    mat.opacity = Math.max(0, Math.min(1, st.alpha ?? 1));
    if (st.color) mat.color.setRGB(st.color[0], st.color[1], st.color[2]);
    if (this.textures.length > 1) mat.map = this.textures[flipFrame(u, st.ms, this.textures.length)];
    const s = st.scale || [1, 1, 1];
    const r = (Number(u.size) || 1) * Math.max(0.01, s[0]);
    const rz = (Number(u.size) || 1) * Math.max(0.01, s[2] || s[0]);
    // anchor position in FILE (effect root is identity under worldRoot)
    const a = this.anchor;
    a.updateWorldMatrix(true, false);
    const p = _v.setFromMatrixPosition(a.matrixWorld); p.z = -p.z;
    const yaw = a.userData.yaw || 0;
    const rot = THREE.MathUtils.degToRad(st.rot || 0) + yaw;
    const w = this.game.world;
    const pos = this.mesh.geometry.attributes.position;
    const arr = pos.array, B = this.base;
    const c = Math.cos(rot), sn = Math.sin(rot);
    const y0 = w?.heightAt ? w.heightAt(p.x, p.z) : p.y;
    for (let i = 0; i < arr.length; i += 3) {
      const lx = B[i] * r, lz = B[i + 2] * rz;
      const x = p.x + lx * c + lz * sn, z = p.z - lx * sn + lz * c;
      let y = w?.heightAt ? w.heightAt(x, z, y0) : p.y;
      if (!Number.isFinite(y)) y = y0;
      arr[i] = x; arr[i + 1] = y + 0.04; arr[i + 2] = z;
    }
    pos.needsUpdate = true;
  }
}

// ============================================================================================ mesh
/** Authored `size` of an effect mesh unit: a scale multiplier on the drawn mesh (408 of 3,964 Global mesh units author a
 *  value other than 1). An authored 0 is kept as 0, not read as "unset": exactly two Global mesh units author
 *  `size 0.000000` (01:mh_armerbreaker_ready_02, 03:mh_energyhammer_boom_02) and both also author an empty texturepack,
 *  so the unit has no extent and is not drawn (it was drawn full-size, flat white additive). Absent / invalid -> 1. Pure. */
export function meshUnitSize(unit) {
  const v = unit?.size;
  if (v == null || v === '') return 1;
  const n = Number(v);
  return Number.isFinite(n) ? n : 1;
}

/** Skinned effect mesh (mesh + skel + anim), unlit, additive unless `transparent`, two-sided when `twoSide`. */
export class MeshUnit extends Unit {
  constructor(ctx, unit, parent, animSeconds) {
    super(ctx, unit);
    this.object = new THREE.Group();
    parent.add(this.object);
    this.mixer = null;
    this.action = null;
    this.mats = [];
    this.scrollMaps = [];
    this.loopClock = new LoopClock();
    this.animSeconds = animSeconds;       // how long the anim should take (null = authored)
    // Authored zero size: nothing to draw, so no model, material or trail is created (see meshUnitSize).
    this.zeroSize = meshUnitSize(unit) === 0;
    if (this.zeroSize) { this.object.visible = false; this.ready = true; return; }
    const spec = trailSpec(unit);
    if (spec && ctx.fx?.root) this.trail = new MeshTrail(ctx.fx, spec);
    const models = this.game.models;
    if (!models || !unit.mesh) return;
    const part = { meshKey: unit.mesh, tpackKey: unit.tpack || null, textures: unit.textures || null, twoSide: !!unit.twoSide };
    const skinned = unit.skel ? models.loadSkinned({ skelKey: unit.skel, parts: [part] }) : null;
    this.readyTask = Promise.resolve(skinned).then(async model => {
      if (this.disposed) return;
      if (!model || model.empty) {
        // no skeleton: a static mesh
        const sm = await models.loadStatic(unit.mesh, { tpackKey: unit.tpack || null, textures: unit.textures || null, twoSide: !!unit.twoSide,
          effectSpecular: SKILL_FX_QUALITY.level !== 'safe' && (unit.textures || []).some(t => t?.specular) });
        if (this.disposed || !sm) return;
        const obj = sm.instantiate();
        this._adopt(obj);
        this.object.add(obj);
        this.ready = true;
        return;
      }
      const inst = model.instantiate();
      this.inst = inst;
      this._adopt(inst.root);
      this.object.add(inst.root);
      if (unit.anim) {
        const len = Number(unit.animLengthMs) > 0 ? Number(unit.animLengthMs) / 1000 : null;
        const clip = await models.loadClip(unit.anim, model, { duration: len });
        if (this.disposed) return;
        if (clip) {
          this.mixer = new THREE.AnimationMixer(inst.root);
          this.action = this.mixer.clipAction(clip);
          this.action.setLoop(THREE.LoopRepeat, Infinity);
          this.action.play();
          this.clipLen = clip.duration;
        }
      }
      this.ready = true;
    }).catch(error => { this.loadError=error; });
  }
  _adopt(root) {
    const u = this.unit;
    root.traverse(o => {
      if (!o.isMesh) return;
      const src = o.material;
      const mat = new THREE.MeshBasicMaterial({
        map: src?.map || null, transparent: true, depthWrite: false, blending: blendOf(null, !!u.transparent),
        side: THREE.DoubleSide, color: nullTextureColor(src?.map, blendOf(null, !!u.transparent)), fog: true,
      }); mat.userData.dkNullTexture = nullTextureColor(src?.map, mat.blending) === 0x000000;
      // A skinned effect mesh whose material slot authors a specular texture draws, like every boneanimation.fx body, with
      // psEnvSpecular: diffuse + specularMap x COLOR0 x envCube(reflect). ModelCache built that patch (matfx.js 'env');
      // keep it on the unlit effect material instead of dropping the map. Glow maps ('+' diffuse) ride the emissive slot of
      // lit materials only; none of the effect meshes reachable from skills author one (validator mesh-glow-map: 0).
      if (keepEffectSpecular(src)) {
        mat.specularMap = src.specularMap; mat.envMap = src.envMap || null; mat.combine = THREE.AddOperation; mat.reflectivity = 1;
        patchSpecular(mat, 'env');
        this.specMats = (this.specMats || 0) + 1;
      }
      // mesh_status <mode> a b on an effect mesh: the same authored UV scroll as MeshStatusUnit (b UV per second along a
      // degrees). The map is cloned so the transform never touches the shared TextureCache texture.
      if (mat.map && meshUvScroll(u)) { mat.map = mat.map.clone(); mat.map.wrapS = mat.map.wrapT = THREE.RepeatWrapping; mat.map.needsUpdate = true; this.scrollMaps.push(mat.map); }
      o.material = mat;
      o.renderOrder = 8;
      o.castShadow = false; o.receiveShadow = false;
      o.frustumCulled = false;
      this.mats.push(mat);
    });
  }
  apply(st) {
    const u = this.unit;
    if (this.zeroSize) return;
    const size = meshUnitSize(u);
    const s = st.scale || [1, 1, 1];
    this.object.scale.set(size * s[0], size * (s[1] ?? s[0]), size * (s[2] ?? s[0]));
    this.object.rotation.set(0, THREE.MathUtils.degToRad(st.rot || 0), 0);
    const a = Math.max(0, Math.min(1, st.alpha ?? 1));
    for (const m of this.mats) {
      m.opacity = a;
      if (st.color && !m.userData.dkNullTexture) m.color.setRGB(st.color[0], st.color[1], st.color[2]);   // null texture stays black
    }
    if (this.action && this.clipLen > 0) {
      // animTime: 1 = stretch the anim over the control life, 0 = authored speed, >1 = multiplier
      const at = Number(st.animTime ?? 1);
      let t;
      if (at === 0 || !(st.life > 0)) t = (st.ms / 1000);
      else if (at > 1) t = (st.ms / 1000) * at;
      else t = (st.ms / st.life) * this.clipLen;
      this.action.time = this.clipLen > 0 ? t % (this.clipLen + 1e-6) : 0;
      if (st.randomStart && this._phase == null) this._phase = Math.random() * this.clipLen;
      if (this._phase) this.action.time = (this.action.time + this._phase) % this.clipLen;
      this.mixer.update(0);
    }
    this._alpha = a; this._color = st.color || null;
    const scroll = this.scrollMaps.length ? meshUvScroll(u) : null;
    if (scroll) {
      const seconds = this.loopClock.tick(st.ms, this.ctx.play?.loop ? this.ctx.play.timeMs : 0) / 1000;
      const [x, y] = uvScrollOffset(scroll, seconds);
      for (const map of this.scrollMaps) map.offset.set(x, y);
    }
  }
  update(dt) {
    if (!this.trail || this.disposed) return;
    this.trail.update(dt, this.ready && this.trail.emitting ? this.object : null, this._alpha ?? 1, this._color);
  }
  dispose() {
    try { this.mixer?.stopAllAction(); } catch { /* ignore */ }
    for (const m of this.mats) { releaseMaterial(m); m.dispose(); }
    this.mats = [];
    for (const t of this.scrollMaps) t.dispose();
    this.scrollMaps = [];
    this.trail?.dispose(); this.trail = null;
    try { this.inst?.skeleton?.dispose(); } catch { /* ignore */ }
    if (this.object) { this.object.removeFromParent(); this.object = null; }
    this.disposed = true;
  }
}

// ============================================================================================ particles
// Four vertices per particle in Uint16 topology. Refuse unrepresentable authored
// pools explicitly rather than silently reducing visible density.
export function particleCapacity(emitter){const n=Number(emitter.max);if(!Number.isInteger(n)||n<1||n>16384)throw Error('Unsupported authored particle pool '+emitter.max);return n;}
export function particleEmissionRate(emitter,pool){
 const n=Number(emitter.rate);if(Number.isFinite(n)&&n>=0)return n;
 // Negative emitrate occurs in original data; its native meaning is unproven.
 // Preserve the prior pool/lifetime compatibility only for that unresolved case
 // (and omitted legacy engine fields), rather than suppressing existing effects.
 const life=emitter.lifetimeMs||[500,500],avg=Math.max(.05,(life[0]+(life[1]||life[0]))/2000);
 return (pool??particleCapacity(emitter))/avg;
}
/** Both triangles of every drawn quad must face the same way. Mixed-facing
 * emitters retain Three's back-then-front alpha ordering, without approximation.
 * Use the actual Float32 positions, including signed scale and followDir pose. */
export function consistentParticleFacing(positions,count,cameraPosition){
 if(!cameraPosition)return false;let facing=0;
 for(let i=0;i<count;i++){
  const b=i*12;
  for(let triangle=0;triangle<2;triangle++){
   const a=b,c=b+(triangle?6:3),d=b+(triangle?9:6);
   const ax=positions[c]-positions[a],ay=positions[c+1]-positions[a+1],az=positions[c+2]-positions[a+2];
   const bx=positions[d]-positions[a],by=positions[d+1]-positions[a+1],bz=positions[d+2]-positions[a+2];
   const dot=(ay*bz-az*by)*(cameraPosition.x-positions[a])+(az*bx-ax*bz)*(cameraPosition.y-positions[a+1])+(ax*by-ay*bx)*(cameraPosition.z-positions[a+2]);
   if(!Number.isFinite(dot))return false;const side=Math.sign(dot);if(side){if(facing&&side!==facing)return false;facing=side;}
  }
 }return true;
}
/**
 * CPU particle emitter (effects.md Ã‚Â§5.5), one draw call per emitter: camera-facing (or yaxis / carpet) quads built
 * every frame in the FILE frame. explode* = burst of `max` at start, direct/plane = continuous at authored emitrate
 * per second, gather = from startRange towards endPos. Per particle: velocity along the spawn direction (random in the
 * sphere when spawnDir is 0), acceleration along the velocity, gravity, addRotate spin, size x particleSize,
 * followDir stretching; control colour / alpha / scale multiply; each particle fades over its last 30 %.
 */
export class ParticleUnit extends Unit {
  constructor(ctx, unit, parent) {
    super(ctx, unit);
    const em = unit.emitter || {};
    this.em = em;
    this.anchor = parent;
    this.max = particleCapacity(em);
    this.parts = [];
    // Carry existing equipment particles with the same moving bone as their emitter.
    // Explicit native follow:false / absPos controls retain their frozen spawn frame.
    this.followAttachment = ctx.play?.particleSpace === 'attachment' && !ctx.control?.frozen;
    this.previousAttachment = this.followAttachment ? this._anchorFrame().clone() : null;
    this.attachmentDelta = this.followAttachment ? new THREE.Matrix4() : null;
    this.attachmentRotation = this.followAttachment ? new THREE.Quaternion() : null;
    this.emitAcc = 0;
    this._ms = 0;
    this.burstDone = false;
    this.alive = true;
    const geo = new THREE.BufferGeometry();
    // tailstep on a particle unit: every particle leaves frozen copies at its past positions (fx-trails.js). The copies
    // share the emitter's quad buffer; the Uint16 topology bounds the total, so the per-particle copy count is reduced
    // only when the authored pool times the copies would exceed it (none of the 5 authored particle trails do).
    this.trailSpec = trailSpec(unit);
    this.trailCopies = this.trailSpec ? Math.max(0, Math.min(this.trailSpec.count, Math.floor(16384 / this.max) - 1)) : 0;
    const n = this.max * (1 + this.trailCopies);
    this.quadCapacity = n;
    this.pos = new Float32Array(n * 4 * 3);
    this.uv = new Float32Array(n * 4 * 2);
    this.col = new Float32Array(n * 4 * 4);
    const idx = new Uint16Array(n * 6);
    for (let i = 0; i < n; i++) { const b = i * 4; idx.set([b, b + 1, b + 2, b, b + 2, b + 3], i * 6); this.uv.set([0,1,1,1,1,0,0,0],i*8); }
    geo.setAttribute('position', new THREE.BufferAttribute(this.pos, 3).setUsage(THREE.DynamicDrawUsage));
    geo.setAttribute('uv', new THREE.BufferAttribute(this.uv, 2));
    geo.setAttribute('color', new THREE.BufferAttribute(this.col, 4).setUsage(THREE.DynamicDrawUsage));
    geo.setIndex(new THREE.BufferAttribute(idx, 1));
    geo.setDrawRange(0, 0);
    const mat = new THREE.MeshBasicMaterial({
      transparent: true, depthWrite: false, blending: blendOf(unit.blend), side: THREE.DoubleSide,
      vertexColors: true, fog: true,
    });
    mat.visible = false;
    this.mesh = new THREE.Mesh(geo, mat);
    this.mesh.userData.ownGeo = true;
    this.mesh.frustumCulled = false;
    this.mesh.renderOrder = 12;
    this.object = this.mesh;
    ctx.fx.root.add(this.mesh);            // world-space particles (FILE frame)
    this.textures = [];
    const keys = unit.frames?.length ? unit.frames : unit.texture ? [unit.texture] : [];
    this.readyTask = Promise.all(keys.map(k => loadTex(this.game, k, BILLBOARD_SAMPLER))).then(ts => {
      if (this.disposed) return;
      this.textures = ts.filter(Boolean);
      if (!this.textures.length) return;
      mat.map = this.textures[0]; mat.needsUpdate = true; mat.visible = true; this.ready = true;
    });
    this.st = { scale: [1, 1, 1], alpha: 1, color: [1, 1, 1] };
    // leaftype mesh: every particle is a copy of the unit's mesh (InstancedMesh, one draw call), oriented along its
    // velocity when followDir, else spun by addRotate. The authored skeleton/anim of the leaf mesh is not played.
    if (unit.leaf === 'mesh' && unit.mesh && this.game.models) this._loadLeafMesh(unit);
  }
  async _loadLeafMesh(unit) {
    try {
      const sm = await this.game.models.loadStatic(unit.mesh, { tpackKey: unit.tpack || null, textures: unit.textures || null, twoSide: !!unit.twoSide });
      await this.readyTask;
      if (this.disposed || !sm) return;
      const obj = sm.instantiate();
      let src = null; obj.traverse(o => { if (!src && o.isMesh) src = o; });
      if (!src) return;
      // A leaf mesh whose own tpack resolves no texture (the strikeshot arrows) takes the particle unit's texture.
      const map = src.material?.map || this.textures[0] || null;
      const mat = new THREE.MeshBasicMaterial({ map, transparent: true, depthWrite: false, blending: blendOf(unit.blend), side: THREE.DoubleSide, color: 0xffffff, fog: true });
      const inst = new THREE.InstancedMesh(src.geometry, mat, this.max);
      inst.instanceMatrix.setUsage(THREE.DynamicDrawUsage);
      inst.setColorAt(0, new THREE.Color(1, 1, 1));
      inst.count = 0; inst.frustumCulled = false; inst.renderOrder = 12;
      this.ctx.fx.root.add(inst);
      this.leafMesh = inst;
      this.mesh.material.visible = false;      // the quads are replaced by the mesh copies
    } catch (error) { this.leafError = error; /* keep the quads */ }
  }
  _buildLeafMeshes(alpha, col, scl) {
    const inst = this.leafMesh, n = Math.min(this.parts.length, this.max);
    const m = _m, q = _q, c = _leafColor, fwd = _leafFwd;
    for (let i = 0; i < n; i++) {
      const p = this.parts[i], k = p.t / p.life, fade = k > 0.7 ? 1 - (k - 0.7) / 0.3 : 1;
      if (this.em.followDir && p.v.lengthSq() > 1e-8) q.setFromUnitVectors(fwd, _v.copy(p.v).normalize());
      else q.setFromAxisAngle(UP, p.rot);
      const sz = p.size;
      m.compose(p.p, q, _v2.set(sz * (scl[0] ?? 1), sz * (scl[1] ?? scl[0] ?? 1), sz * (scl[2] ?? scl[0] ?? 1)));
      inst.setMatrixAt(i, m);
      // additive copies: the per-particle fade rides the colour (alpha x colour is the same under SrcAlpha, One)
      const t = p.tint, f = blendOf(this.unit.blend) === THREE.AdditiveBlending ? fade : 1;
      c.setRGB(col[0] * (t ? t[0] : 1) * f, col[1] * (t ? t[1] : 1) * f, col[2] * (t ? t[2] : 1) * f);
      inst.setColorAt(i, c);
    }
    inst.count = n;
    inst.material.opacity = alpha;
    inst.instanceMatrix.needsUpdate = true;
    if (inst.instanceColor) inst.instanceColor.needsUpdate = true;
  }
  dispose() {
    if (this.leafMesh) { this.leafMesh.removeFromParent(); this.leafMesh.material.dispose(); this.leafMesh.dispose?.(); this.leafMesh = null; }
    super.dispose();
  }
  apply(st) { this.st = st; }
  /** The control ended: stop emitting, let live particles finish. */
  stopEmitting() { this.alive = false; }
  finishing() { return this.parts.length > 0; }

  _anchorFrame() {
    const a = this.anchor;
    a.updateWorldMatrix(true, false);
    _m.copy(MIRROR).multiply(a.matrixWorld);          // FILE frame matrix of the anchor
    return _m;
  }

  _spawn(count) {
    const em = this.em, u = this.unit;
    const M = this._anchorFrame();
    const origin = new THREE.Vector3().setFromMatrixPosition(M);
    const rot = new THREE.Quaternion().setFromRotationMatrix(new THREE.Matrix4().extractRotation(M));
    const scl = this.st.scale || [1, 1, 1];
    for (let i = 0; i < count && this.parts.length < this.max; i++) {
      const lr = em.lifetimeMs || [500, 500];
      const life = (lr[0] + Math.random() * Math.max(0, (lr[1] || lr[0]) - lr[0])) / 1000;
      const vr = em.velocity || [0, 0];
      const speed = vr[0] + Math.random() * Math.max(0, (vr[1] ?? vr[0]) - vr[0]);
      const sd = em.spawnDir || [0, 0, 0];
      let dir = new THREE.Vector3(sd[0], sd[1], sd[2]);
      const state = em.state || 'explode';
      const planar = state === 'explodeplane' || state === 'directplane' || state === 'plane';
      if (dir.lengthSq() < 1e-6) {
        dir.set(Math.random() * 2 - 1, planar ? 0 : Math.random() * 2 - 1, Math.random() * 2 - 1);
        if (dir.lengthSq() < 1e-6) dir.set(1, 0, 0);
      } else {
        dir.normalize();
        // a little spread around the given direction
        dir.x += (Math.random() - 0.5) * 0.3; dir.y += (Math.random() - 0.5) * 0.3; dir.z += (Math.random() - 0.5) * 0.3;
      }
      dir.normalize();
      if (!em.spawnDirAbs) dir.applyQuaternion(rot);
      const sr = em.startRange || [0, 0];
      const rad = (sr[0] + Math.random() * Math.max(0, (sr[1] ?? sr[0]) - sr[0])) * (scl[0] || 1);
      let p = origin.clone();
      if (rad > 0) {
        const a = Math.random() * Math.PI * 2;
        let off;
        if (state === 'exploderange' || planar || state === 'gather') off = new THREE.Vector3(Math.cos(a) * rad, 0, Math.sin(a) * rad);
        else off = dir.clone().multiplyScalar(rad);
        if (state === 'gather' && !planar) off.y = (Math.random() - 0.5) * rad;
        p.add(off.applyQuaternion(em.spawnDirAbs ? new THREE.Quaternion() : rot));
      }
      let vel = dir.multiplyScalar(speed);
      if (state === 'gather') {
        const ep = em.endPos || [0, 0, 0];
        const target = new THREE.Vector3(ep[0], ep[1], ep[2]).applyQuaternion(rot).add(origin);
        vel = target.sub(p).divideScalar(Math.max(0.05, life));
      }
      const ps = em.particleSize || [0, 0];
      const sz = (Number(u.size) || 1) * ((ps[0] || ps[1]) ? ps[0] + Math.random() * Math.max(0, (ps[1] ?? ps[0]) - ps[0]) : 1);
      const cr = (Number(em.colorRange) || 0) / 100;
      this.spawned = (this.spawned || 0) + 1;
    this.parts.push({
        p, v: vel, t: 0, life, size: sz, rot: Math.random() * Math.PI * 2, frameSeed: Math.random(),
        trail: this.trailCopies > 0 ? { clock: new TrailSchedule(this.trailSpec), copies: [] } : null,
        tint: cr > 0 ? [1 - Math.random() * cr, 1 - Math.random() * cr, 1 - Math.random() * cr] : null,
      });
    }
  }

  update(dt) {
    if (this.disposed) return;
    if (this.followAttachment) {
      const current = this._anchorFrame();
      this.attachmentDelta.copy(current).multiply(this.previousAttachment.invert());
      this.attachmentRotation.setFromRotationMatrix(this.attachmentDelta);
      for (const particle of this.parts) {
        particle.p.applyMatrix4(this.attachmentDelta);
        if (!this.em.spawnDirAbs) particle.v.applyQuaternion(this.attachmentRotation);
      }
      this.previousAttachment.copy(current);
    }
    this._ms += Math.max(0, dt) * 1000;
    const em = this.em;
    const state = em.state || 'explode';
    const burst = state.startsWith('explode');
    if (this.alive) {
      if (burst) {
        if (!this.burstDone) { this._spawn(this.max); this.burstDone = true; }
      } else {
        // Preserve authored emitrate. Its native time unit still requires validation.
        const rate = particleEmissionRate(em,this.max);
        this.emitAcc += rate * dt;
        const k = Math.floor(this.emitAcc);
        if (k > 0) { this.emitAcc -= k; this._spawn(k); }
      }
    }
    const g = em.gravity || [0, 0, 0];
    const acc = Number(em.acceleration) || 0;
    const spin = THREE.MathUtils.degToRad(Number(em.addRotate) || 0);
    // Stable linear compaction preserves transparent draw order without repeated tail shifts.
    let liveCount=0;
    for (let i = 0; i < this.parts.length; i++) {
      const q = this.parts[i];
      q.t += dt;
      if (q.t >= q.life) continue;
      if (acc && q.v.lengthSq() > 1e-8) q.v.addScaledVector(_v.copy(q.v).normalize(), acc * dt);
      q.v.x += g[0] * dt; q.v.y += g[1] * dt; q.v.z += g[2] * dt;
      q.p.addScaledVector(q.v, dt);
      q.rot += spin * dt;
      if (q.trail) this._trailStep(q, dt * 1000);
      this.parts[liveCount++]=q;
    }
    this.parts.length=liveCount;
    this._build();
  }

  _trailStep(q, ms) {
    const tr = q.trail, life = this.trailSpec.life;
    for (const c of tr.copies) c.age += ms;
    while (tr.copies.length && tr.copies[0].age >= life) tr.copies.shift();
    if (tr.clock.step(ms, q.p.x, q.p.y, q.p.z)) {
      tr.copies.push({ x: q.p.x, y: q.p.y, z: q.p.z, rot: q.rot, k: q.t / q.life, age: 0 });
      while (tr.copies.length > this.trailCopies) tr.copies.shift();
    }
  }

  _build() {
    const cam = this.ctx.fx.cam;
    const st = this.st || {};
    const scl = st.scale || [1, 1, 1];
    const alpha = Math.max(0, Math.min(1, st.alpha ?? 1));
    const col = st.color || [1, 1, 1];
    const bb = this.unit.billboard || 'camera';
    const n = this.parts.length;
    const P = this.pos, C = this.col;
    const nf = this.textures.length;
    let fw = 1, fi = 0;
    // flipbook over a single texture sheet is not used by the data (frames are separate textures): animate the
    // whole emitter's texture by time instead
    if (nf > 1) {
      const f = flipFrame(this.unit, this._ms, nf, 0.5);
      if (this.mesh.material.map !== this.textures[f]) this.mesh.material.map = this.textures[f];
    }
    for (let i = 0; i < n; i++) {
      const q = this.parts[i];
      const k = q.t / q.life;
      const fade = k > 0.7 ? 1 - (k - 0.7) / 0.3 : 1;
      const half = 0.5 * q.size;
      const sx = half * (scl[0] ?? 1), sy = half * (scl[1] ?? scl[0] ?? 1);
      let rx, ry, rz, ux, uy, uz;
      if (bb === 'carpet') {
        const c = Math.cos(q.rot), s = Math.sin(q.rot);
        rx = c; ry = 0; rz = -s; ux = s; uy = 0; uz = c;
      } else if (this.em.followDir && q.v.lengthSq() > 1e-6) {
        // stretched along the velocity, facing the camera
        const d = _v.copy(q.v).normalize();
        const side = _v2.copy(d).cross(cam.fwd).normalize();
        rx = side.x; ry = side.y; rz = side.z;
        ux = d.x * 2; uy = d.y * 2; uz = d.z * 2;                 // streak length x2
      } else if (bb === 'yaxis') {
        const toC = _v.copy(cam.pos).sub(q.p); toC.y = 0; toC.normalize();
        rx = toC.z; ry = 0; rz = -toC.x; ux = 0; uy = 1; uz = 0;
      } else {
        const c = Math.cos(q.rot), s = Math.sin(q.rot);
        const R = cam.right, U = cam.up;
        rx = R.x * c + U.x * s; ry = R.y * c + U.y * s; rz = R.z * c + U.z * s;
        ux = U.x * c - R.x * s; uy = U.y * c - R.y * s; uz = U.z * c - R.z * s;
      }
      const b = i * 12;
      const px = q.p.x, py = q.p.y, pz = q.p.z;
      P[b] = px - rx * sx - ux * sy; P[b + 1] = py - ry * sx - uy * sy; P[b + 2] = pz - rz * sx - uz * sy;
      P[b + 3] = px + rx * sx - ux * sy; P[b + 4] = py + ry * sx - uy * sy; P[b + 5] = pz + rz * sx - uz * sy;
      P[b + 6] = px + rx * sx + ux * sy; P[b + 7] = py + ry * sx + uy * sy; P[b + 8] = pz + rz * sx + uz * sy;
      P[b + 9] = px - rx * sx + ux * sy; P[b + 10] = py - ry * sx + uy * sy; P[b + 11] = pz - rz * sx + uz * sy;
      const a = alpha * fade;
      const t = q.tint;
      const cr = col[0] * (t ? t[0] : 1), cg = col[1] * (t ? t[1] : 1), cb = col[2] * (t ? t[2] : 1);
      for (let v = 0; v < 4; v++) { const cbx = i * 16 + v * 4; C[cbx] = cr; C[cbx + 1] = cg; C[cbx + 2] = cb; C[cbx + 3] = a; }
    }
    // trail copies: camera-facing quads at the particle's past positions, the particle's size and colour, fading over
    // the trail life (fx-trails.js trailFade) times the particle's own fade at the copy's emission
    let quads = n;
    if (this.trailCopies > 0) {
      const R = cam.right, U = cam.up, life = this.trailSpec.life;
      for (let i = 0; i < n && quads < this.quadCapacity; i++) {
        const q = this.parts[i], t = q.tint;
        const half = 0.5 * q.size, sx = half * (scl[0] ?? 1), sy = half * (scl[1] ?? scl[0] ?? 1);
        const cr = col[0] * (t ? t[0] : 1), cg = col[1] * (t ? t[1] : 1), cb = col[2] * (t ? t[2] : 1);
        for (const c of q.trail?.copies || []) {
          if (quads >= this.quadCapacity) break;
          const co = Math.cos(c.rot), si = Math.sin(c.rot);
          const rx = R.x * co + U.x * si, ry = R.y * co + U.y * si, rz = R.z * co + U.z * si;
          const ux = U.x * co - R.x * si, uy = U.y * co - R.y * si, uz = U.z * co - R.z * si;
          const b = quads * 12;
          P[b] = c.x - rx * sx - ux * sy; P[b + 1] = c.y - ry * sx - uy * sy; P[b + 2] = c.z - rz * sx - uz * sy;
          P[b + 3] = c.x + rx * sx - ux * sy; P[b + 4] = c.y + ry * sx - uy * sy; P[b + 5] = c.z + rz * sx - uz * sy;
          P[b + 6] = c.x + rx * sx + ux * sy; P[b + 7] = c.y + ry * sx + uy * sy; P[b + 8] = c.z + rz * sx + uz * sy;
          P[b + 9] = c.x - rx * sx + ux * sy; P[b + 10] = c.y - ry * sx + uy * sy; P[b + 11] = c.z - rz * sx + uz * sy;
          const fadeAt = c.k > 0.7 ? 1 - (c.k - 0.7) / 0.3 : 1;
          const a = alpha * fadeAt * trailFade(c.age, life);
          for (let v = 0; v < 4; v++) { const cbx = quads * 16 + v * 4; C[cbx] = cr; C[cbx + 1] = cg; C[cbx + 2] = cb; C[cbx + 3] = a; }
          quads++;
        }
      }
    }
    if (this.leafMesh) this._buildLeafMeshes(alpha, col, scl);
    const g = this.mesh.geometry;
    const singlePass=consistentParticleFacing(P,quads,cam.pos),material=this.mesh.material;
    if(material.forceSinglePass!==singlePass){material.forceSinglePass=singlePass;material.needsUpdate=true;}
    g.setDrawRange(0, quads * 6);
    // UVs never change. Upload only drawn vertices, retaining every live particle.
    const position=g.attributes.position,color=g.attributes.color;
    position.clearUpdateRanges();color.clearUpdateRanges();
    if(quads){position.addUpdateRange(0,quads*12);color.addUpdateRange(0,quads*16);position.needsUpdate=true;color.needsUpdate=true;}
    void fw; void fi;
  }
}

// ============================================================================================ meshstatus
/**
 * Overlay pass (frozen body, awakening glow, defensive shell): a copy of every skinned mesh of the owner bound to
 * the same skeleton, drawn additively with the unit texture and `mesh_color`, pushed out along the normals by `size`.
 * Upgrade modes use degrees/scroll, rather than interpreting 360 as UV cycles.
 */
export class MeshStatusUnit extends Unit {
  constructor(ctx, unit, owner) {
    super(ctx, unit);
    this.overlays = [];
    this.auraLevel = 0;
    this.loopClock = new LoopClock();
    this.owner = owner;
    const inst = owner?.instance;
    if (!inst?.meshes?.length) return;
    const c = unit.color || [255, 255, 255, 1];
    this.baseColor = new THREE.Color(c[0] / 255, c[1] / 255, c[2] / 255);
    this.baseAlpha = c[3] ?? 1;
    // Refinement overlays (armor purple/gold/silver, weapon grade) are authored at ~0.4 alpha of a grey tint: after the
    // additive blend they sit under the client bloom's pow threshold and never glow. The gain lifts the tier texture
    // into the bloom range (the framebuffer still clamps, so the hue is kept) for equipped gear and inventory icons.
    // Matched by the native tier texture (the unit name carries a file prefix in the real data). Shell size tells the
    // slot apart: armor 0.01, weapon 0.005, inventory 0.0001.
    const tierTex = /effect\/levelup\/eff_upgrade_/i.test(String(unit.texture || '').replace(/\\/g, '/'));
    this.glowGain = !tierTex ? 1 : (Number(unit.size) >= 0.009 ? 2.5 : Number(unit.size) >= 0.004 ? 2 : 2.2);
    // Rim light only on worn gear (shell > 0.004); the tier hue follows the native texture family.
    this.glowRim = tierTex && Number(unit.size) >= 0.004 ? (Number(unit.size) >= 0.009 ? 5 : 4) : 0;
    const tierId = /eff_upgrade_(\d+)/i.exec(String(unit.texture || ''))?.[1];
    const HUES = { 15: [0.85, 0.15, 1.0], 79: [1.0, 0.62, 0.18], 1114: [1.0, 0.22, 0.15], 46: [0.45, 0.65, 1.0], 13: [0.82, 0.88, 1.0] };
    this.glowHue = new THREE.Vector3(...(HUES[tierId] || [1, 1, 1]));
    const shell = Math.max(0, Number(unit.size) || 0);
    this.readyTask = loadTex(this.game, unit.texture).then(async tex => {
      if (this.disposed) return;
      // A missing overlay image must never paint the entire actor solid white.
      if (!tex) { this.failed = true; return; }
      // UV transforms belong to this effect, never the shared TextureCache map.
      this.texture = tex?.clone();
      if(this.texture){this.texture.needsUpdate=true;this.texture.wrapS=this.texture.wrapT=THREE.RepeatWrapping;this.texture.center.set(.5,.5);}
      const fresh = [];   // the overlays of this unit, shown once their programs are built (engine/shader-prewarm.js)
      for (const src of inst.meshes) {
        // The tier texture is the colour source (eff_upgrade_13/46 silver, 79 red-gold, 1114 red, 15 purple);
        // mesh_color is the authored neutral 230 grey. No substitute tint is applied.
        const mat = new THREE.MeshBasicMaterial({
          map: this.texture, transparent: true, depthWrite: false, blending: blendOf(unit.blend || 'add'),
          color: this.baseColor, opacity: this.baseAlpha, side: THREE.FrontSide,
          polygonOffset: true, polygonOffsetFactor: -1, polygonOffsetUnits: -2,
        });
        if (shell > 0) {
          // The generated GLSL embeds the shell constant. Three's default key
          // only hashes callback text, so armor and weapon shells would collide.
          mat.customProgramCacheKey = () => 'meshstatus-shell:' + shell.toFixed(4);
          mat.onBeforeCompile = sh => {
            sh.vertexShader = sh.vertexShader.replace('#include <begin_vertex>',
              `#include <begin_vertex>\n  transformed += normalize(normal) * ${shell.toFixed(4)};`);
          };
        }
        // The 0.005-0.01 shell is far thinner than the armor's depth resolution: pull the overlay towards the camera so
        // the refinement shine is not z-fought away behind its own armor surface.
        if (this.glowRim > 0) { mat.polygonOffsetFactor = -4; mat.polygonOffsetUnits = -16; }
        if (this.glowGain !== 1) {
          // Pure brightness gain in the shader: the authored colour keys, alpha and tier texture stay untouched.
          const gain = this.glowGain, previous = mat.onBeforeCompile, previousKey = mat.customProgramCacheKey.bind(mat);
          mat.customProgramCacheKey = () => previousKey() + '|refine-glow:' + gain.toFixed(2);
          // Worn gear also gets the tier-coloured rim light of the client's refinement shine: a view-dependent edge glow in
          // the tier hue that rides the authored alpha animation, so the armor/weapon surface itself glows into the bloom.
          const rim = this.glowRim, hue = this.glowHue;
          if (rim > 0) mat.customProgramCacheKey = (k => () => k() + '|rim:' + rim.toFixed(2))(mat.customProgramCacheKey);
          mat.onBeforeCompile = (sh, renderer) => {
            previous.call(mat, sh, renderer);
            let frag = sh.fragmentShader;
            if (rim > 0) {
              sh.uniforms.dkRimColor = { value: hue };
              sh.vertexShader = sh.vertexShader.replace('#include <common>', '#include <common>\nvarying vec3 dkView;')
                .replace('#include <project_vertex>', '#include <project_vertex>\ndkView = -mvPosition.xyz;');
              frag = frag.replace('#include <common>', '#include <common>\nvarying vec3 dkView; uniform vec3 dkRimColor;')
                .replace('#include <opaque_fragment>', `
vec3 dkN = normalize(cross(dFdx(dkView), dFdy(dkView)));
float dkRim = pow(1.0 - abs(dot(dkN, normalize(dkView))), 1.6);
diffuseColor.a = opacity;
float dkA = max(opacity, 0.05);
vec3 dkR = dkRimColor * (${rim.toFixed(3)} * (0.03 + 1.5 * dkRim));
dkR *= min(1.0, 1.0 / max(max(dkR.r, dkR.g), max(dkR.b, 1e-4)));   // hue-preserving cap: a strong rim must not clip to white
outgoingLight = outgoingLight * ${gain.toFixed(3)} + dkR / dkA;
#include <opaque_fragment>`);
            } else frag = frag.replace('#include <opaque_fragment>', `outgoingLight *= ${gain.toFixed(3)};\n#include <opaque_fragment>`);
            sh.fragmentShader = frag;
          };
        }
        const m = src.isSkinnedMesh?new THREE.SkinnedMesh(src.geometry, mat):new THREE.Mesh(src.geometry,mat);
        if(src.isSkinnedMesh)m.bind(src.skeleton, src.bindMatrix);
        m.position.copy(src.position);m.quaternion.copy(src.quaternion);m.scale.copy(src.scale);
        m.frustumCulled = false;
        m.renderOrder = 9;
        m.userData.ownMat = true;
        src.parent.add(m);
        m.visible = false; fresh.push(m);   // hidden until its shader programs are built (warmThenShow below; engine/shader-prewarm.js)
        this.overlays.push(m);
        // aura: worn refinement shells are sources of the soft glow buffer (graphics/glow-pass.js), in the tier hue, riding the
        // authored alpha animation (apply() sets auraLevel)
        if (this.glowRim > 0) this.game.gfx?.glow?.add(m, { hue: this.glowHue.toArray(), gain: () => this.auraLevel * (Number(unit.size) >= 0.009 ? auraValue('ARMOR_REFINE') : auraValue('WEAPON_REFINE')) });
      }
      // 2.2.1: the status shell's program (a skinned copy of the body, the first cast of a buff / awakening) used to link in the frame that first drew it
      // (a 59-75 ms frame, measured): build it first, hidden, show the shell at once when it is ready (never later than 220 ms)
      await warmThenShow(this.game, fresh, () => { if (!this.disposed) for (const o of fresh) o.visible = true; });
      this.ready = true;
    });
    this.t = 0;
  }
  apply(st) {
    const a = Math.max(0, Math.min(1, st.alpha ?? 1)) * this.baseAlpha;
    this.auraLevel = Math.min(1, Math.max(0, (st.alpha ?? 1) / auraValue('REFINE_ALPHA_REF')));
    const ms = this.unit.meshStatus || {};
    for (const m of this.overlays) {
      m.material.opacity = a;
      // Preserve the authored RGB key, alpha and texture; do not add a synthetic flash.
      m.material.color.copy(this.baseColor);
      if (st.color) m.material.color.setRGB(this.baseColor.r * st.color[0], this.baseColor.g * st.color[1], this.baseColor.b * st.color[2]);
      if (m.material.map) {
        // mesh_status <mode> a b, as authored and at real time. Across the game's 10,515 mesh_status units `a` is always an angle in
        // degrees (0, +-45, +-90, 135, 180, 190, 200, 360 ...) and `b` a signed speed (+-0.01 .. +-1 per second): the texture scrolls
        // at `b` UV per second along direction `a`. Armor 360 / .15 and weapon 0 / .2 are a slow vertical sweep. No pacing factor.
        const seconds=this.loopClock.tick(st.ms,this.ctx.play?.loop?this.ctx.play.timeMs:0)/1000;
        const [x,y]=uvScrollOffset({angle:ms.a,speed:ms.b},seconds);m.material.map.offset.set(x,y);
      }
    }
  }
  dispose() {
    for (const m of this.overlays) { this.game.gfx?.glow?.remove(m); m.removeFromParent(); m.material.dispose(); }
    this.overlays = [];
    this.texture?.dispose();this.texture=null;
    this.disposed = true;
  }
}

// ============================================================================================ sound / quake
export class SoundUnit extends Unit {
  constructor(ctx, unit, at) {
    super(ctx, unit);
    const a = this.game.audio;
    let path = unit.sound || '';
    path = String(path).replace(/\\/g, '/').replace(/^sound\//i, '');
    if (a?.sfx && path && ctx.fx.soundOn) {
      const p = a.sfx(path, { volume: Number(unit.volume ?? 100) / 100, at, range: Number(unit.range ?? 20),
        category: unit.subtype,
        exclusiveMs: unit.exclusive ? Math.max(0, Number(unit.lengthMs) || 0) : 0,
        isCurrent: () => !this.disposed && !ctx.play?.stopping && !ctx.play?.owner?.disposed });
      Promise.resolve(p).then(h => { if (this.disposed) h?.stop?.(); else this.handle = h; });
    }
    this.ready = true;
  }
  dispose() {
    super.dispose();
    // State-bound sounds end with their emitter. A hard/cancelled scene ends its
    // raw sound units; a naturally ending ordinary one-shot may finish its tail.
    if (this.unit.flagA === 0 || this.ctx.play?.stopping) this.handle?.stop?.();
  }
}

export class QuakeUnit extends Unit {
  constructor(ctx, unit, at) {
    super(ctx, unit);
    const cam = unit.camera || {};
    const p = this.game.player;
    const d = p && at ? Math.hypot(p.x - at.x, p.z - at.z) : 0;
    this.amp = (Number(cam.amplitude) || 0.1) * Math.max(0, 1 - d / 30);
    this.freq = Number(cam.frequency) || 10;
    ctx.fx.addQuake(this);
    this.ready = true;
  }
  dispose() { this.ctx.fx.removeQuake(this); this.disposed = true; }
}


