// Effect player (docs/formats/effects.md §5, §10): plays effect scenes {cate, id, scene, timeMs} from the effect
// library (gamedata/skills*.json via SkillData) on an owner actor or a ground point.
//
//   const h = game.effects.play(ownerActorOrPoint, { cate: 100, id: 1014, scene: 1, timeMs: 500 }, { loop, bone, yaw })
//   h.stop()                 // status end / remote death: remove at once (particles fade out)
//
// TIMELINE (§5.1): scene time is normalised to 1000. A control lives from life[0] * timeMs / 1000 to
// life[1] * timeMs / 1000; its keyframes (t 0..999) span that interval. One-shots end at timeMs (or the last control);
// loops restart every timeMs while the handle lives.
// ATTACH (§5.3): control `bone` = a bone of the owner (raw game names), or the virtual points top / center / movement /
// "" (feet). Missing bones fall back to Bip01 Spine1 -> Bip01 -> origin + half height. `follow:false` / `absPos`
// freezes the spawn transform; `absDir` ignores the owner's rotation. `bone_animation` rides a bone of a separate
// effect skeleton playing its own anim (motion paths). startposition / position keys are in the owner's local frame.
// SOUND: sound units of the scene, plus the `.snd` half of the same key (sound.json skill[id] / effectSound[cate][id]).
import * as THREE from 'three';
import {makeShearable, SHEAR_INDICES} from '../../engine/models.js';
import { SpriteUnit, DecalUnit, MeshUnit, ParticleUnit, MeshStatusUnit, SoundUnit, QuakeUnit, cameraFrame } from './fx-units.js';
import {MapSnowWeatherUnit} from './map-weather-unit.js';
import { COLOR_OVERRANGE, BONE_ALIASES } from '../../config/engine-chosen-skill-fx.js';

const MIRROR = new THREE.Matrix4().makeScale(1, 1, -1);
const _m = new THREE.Matrix4();
const _p = new THREE.Vector3();
const _q = new THREE.Quaternion();
const _s = new THREE.Vector3();
const _off = new THREE.Vector3();
const _yq = new THREE.Quaternion();
let _mirrorX = 1;                // reflection of the last attachFrame bone (-1: mirrored bone), see attachFrame
const UP = new THREE.Vector3(0, 1, 0);
const MAX_ACTIVE = 220;          // scene plays alive at once (oldest one-shots are dropped beyond it)
const CULL_DIST = 90;            // no new effects beyond this distance from the camera target
const quakeScenes = new WeakMap();

/** Linear keyframes [[t, v1, v2, ...]] (t 0..999) at u; holds the first / last value. */
export function evalKeys(keys, u, arity) {
  if (!keys || !keys.length) return null;
  const k0 = keys[0];
  if (u <= k0[0] || keys.length === 1) return k0.slice(1, 1 + arity);
  for (let i = 1; i < keys.length; i++) {
    const b = keys[i];
    if (u <= b[0]) {
      const a = keys[i - 1];
      const span = b[0] - a[0];
      const f = span > 0 ? (u - a[0]) / span : 1;
      const out = [];
      for (let j = 1; j <= arity; j++) {
        const va = a[j] ?? a[a.length - 1], vb = b[j] ?? b[b.length - 1];
        out.push(va + (vb - va) * f);
      }
      return out;
    }
  }
  return keys[keys.length - 1].slice(1, 1 + arity);
}

// ============================================================================================ bone-animation paths
/** A bare effect skeleton (no mesh) playing an anim: gives the moving bone a unit rides on (§5.3 bone_animation). */
export function canPlayBonePath(spec) {
  // An authored empty clip uses the skeleton's static pose. A missing file
  // recorded by the builder is a different case and remains unresolved.
  return !!(spec?.skel && (spec.anim || !spec.missing?.length));
}

class BonePath {
  constructor(game, spec, lifeSec) {
    this.game = game;
    this.spec = spec;
    this.root = new THREE.Group();
    this.bone = null;
    this.mixer = null;
    this.len = 0;
    this.lifeSec = lifeSec;
    // Skeleton/clip requests are asynchronous; a missing path must not become
    // an unhandled rejection after the caller's playback recovery has returned.
    this.readyTask = this._load().catch(() => { this.failed = true; });
  }
  async _load() {
    const models = this.game.models;
    if (!models?.skeleton) return;
    const skel = await models.skeleton(this.spec.skel);
    if (!skel || this.disposed) return;
    const bones = skel.bones.map(b => {
      const S = b.scaleMatrix;
      const o = makeShearable(new THREE.Bone(), S ? SHEAR_INDICES.map(i => S[i]) : null);
      if (S) o.scale.set(S[0], S[5], S[10]);
      o.name = THREE.PropertyBinding.sanitizeNodeName(b.name);
      o.userData.raw = b.name;
      o.position.fromArray(b.position);
      o.quaternion.set(b.rotation[0], b.rotation[1], b.rotation[2], b.rotation[3]).normalize();
      return o;
    });
    skel.bones.forEach((b, i) => (b.parent >= 0 ? bones[b.parent] : this.root).add(bones[i]));
    const want = String(this.spec.bone || '').toLowerCase();
    this.bone = bones.find(b => String(b.userData.raw).toLowerCase() === want) || bones.find(b => b.name.toLowerCase() === want) || null;
    if (!this.spec.anim) return; // Static authored skeleton: no clip request.
    // clip through ModelCache with a minimal model facade (skel + bone names)
    const facade = { skelKey: this.spec.skel, skel, boneNames: bones.map(b => b.name), supportsShear: true, _bones: skel.bones.map(b => { const sh = b.scaleMatrix ? SHEAR_INDICES.map(i => b.scaleMatrix[i]) : null; return {sh: sh?.some(v => Math.abs(v) > 1e-7) ? sh : null}; }) };
    const ms = Number(this.spec.params?.[1]) || 0;
    const dur = ms > 0 ? ms / 1000 : this.lifeSec > 0 ? this.lifeSec : null;
    try {
      const clip = await models.loadClip(this.spec.anim, facade, { duration: dur });
      if (clip && !this.disposed) {
        this.mixer = new THREE.AnimationMixer(this.root);
        const act = this.mixer.clipAction(clip);
        act.setLoop(THREE.LoopRepeat, Infinity);
        act.play();
        this.len = clip.duration;
      }
    } catch { /* keep the bind pose */ }
  }
  /** Local transform of the path bone relative to the path root at time t (s) into out Matrix4, or false. */
  sample(t, out) {
    if (!this.bone) return false;
    if (this.mixer) { this.mixer.setTime(this.len > 0 ? t % this.len : t); }
    this.root.updateMatrixWorld(true);
    out.copy(this.bone.matrixWorld);
    return true;
  }
  dispose() { this.disposed = true; try { this.mixer?.stopAllAction(); } catch { /* ignore */ } }
}

/** Control colour key as the native fixed-function stage sees it. billboard.fx / trace.fx / tracemesh.fx hand the key to
 *  the rasteriser as COLOR0 (vs_1_1 oD0), which D3D9 saturates to [0, 1] per channel, so an authored 1.5 draws as 1.0.
 *  COLOR_OVERRANGE 'boost' keeps the unclamped float (the previous client look, brighter than native). Pure. */
export function controlColour(c, mode = COLOR_OVERRANGE) {
  if (!c) return null;
  if (mode === 'boost') return c;
  return c.map(v => Math.max(0, Math.min(1, Number(v) || 0)));
}

// ============================================================================================ attach
/** Authored bone name after the verified typo aliases (src/config/engine-chosen-skill-fx.js BONE_ALIASES). Pure. */
export function attachBoneName(bone) {
  const b = bone == null ? '' : String(bone);
  return Object.prototype.hasOwnProperty.call(BONE_ALIASES, b) ? BONE_ALIASES[b] : b;
}

/** COMPATIBILITY (nativeDispatchVerified:false). A control without bonename/animpath whose bone_animation path skeleton file
 *  is absent from Global rides the owner bone that path names ("Bip01 L Finger0", "Bip01 Spine1") when the owner has that
 *  bone; otherwise the previous attach point stays. The paths are character rigs playing the caster's own skill clip; the
 *  same units attach to those bones by bonename in the sibling effects 100:3273/3274/3287; the native Flame Gusher /
 *  Blast Phoenix clips show the glows at hand height. Moves 5 shipped controls: 100:1117 #33, 100:2411 #1/#7,
 *  100:3108 #7/#8. false restores the previous behaviour (unit at the owner origin). */
export const MISSING_PATH_SKELETON_ATTACH = true;

/** Owner bone for a control under MISSING_PATH_SKELETON_ATTACH, or null (the control then keeps controlBone's choice).
 *  Never overrides a bonename or animpath. */
export function missingPathSkeletonBone(def, owner = null) {
  const b = def?.boneAnim;
  if (!MISSING_PATH_SKELETON_ATTACH || def?.bone != null || def?.animPath || !b?.bone || b.skel) return null;
  if (!b.missing?.some(m => String(m).startsWith('missing:skel/'))) return null;
  return owner?.instance?.getBone?.(attachBoneName(b.bone)) ? b.bone : null;
}

/** Attach bone of a control: bonename, else animpath, else the play's bone. `animpath` (4 controls in Global data, all
 *  without a bonename) names an owner biped bone ("Bip01", "Bip01 L Hand", "Bip01 R Finger0": a sword glow on the sword
 *  hand, a ready sound at the hand), so it is read as the attach point. [medium confidence: native semantics unstated] */
export function controlBone(def, fallback = null) {
  return def?.bone ?? (def?.animPath ? def.animPath : null) ?? fallback;
}

/** Reflection (x sign, 1 or -1) of the bone frame resolved by the last attachFrame call. Exported for tests. */
export function attachReflection() { return _mirrorX; }

/** FILE-frame attach transform of an owner (actor or point) at a bone / virtual point. */
function attachFrame(owner, bone, outPos, outQuat) {
  _mirrorX = 1;
  const yaw = Number(owner?.yaw) || 0;
  outQuat.setFromAxisAngle(UP, yaw);
  if(Array.isArray(owner?.quaternion)&&owner.quaternion.length===4&&owner.quaternion.every(Number.isFinite)&&owner.quaternion.some(v=>v!==0))outQuat.fromArray(owner.quaternion).normalize();
  const sc = Number(owner?.scale) > 0 ? Number(owner.scale) : 1;
  const h = (Number(owner?.height) || 1.8) * sc;
  const ox = Number(owner?.x) || 0, oy = Number(owner?.y) || 0, oz = Number(owner?.z) || 0;
  outPos.set(ox, oy, oz);
  const b = attachBoneName(bone);
  if (!b || b === 'movement') return true;
  if (b === 'top') { outPos.y += h; return true; }
  if (b === 'center') { outPos.y += h * 0.55; return true; }
  const inst = owner?.instance;
  let node = inst?.getBone?.(b) || null;
  if (!node && inst) node = inst.getBone('Bip01 Spine1') || inst.getBone('Bip01') || null;
  if (!node) { outPos.y += h * 0.5; return true; }
  node.updateWorldMatrix(true, false);
  _m.copy(MIRROR).multiply(node.matrixWorld);            // THREE world -> FILE frame (worldRoot is the mirror)
  _m.decompose(outPos, outQuat, _s);
  // A mirrored bone (negative-determinant frame: 3ds Max mirror, e.g. every Bone_R_* / Jet_02 of the mechanic wing skel, skel
  // scaleMatrix -I) decomposes to a rotation plus scale.x < 0. The native attach uses the whole bone matrix, so keep that
  // reflection for the control's local offset and drawn unit (see attachReflection / ControlPlay._placeAnchor).
  _mirrorX = _s.x < 0 ? -1 : 1;
  // a skinned body whose group is hidden (culled) still has valid bones; nothing else to do
  return true;
}

// ============================================================================================ control
class ControlPlay {
  constructor(play, def, index) {
    this.play = play;
    this.def = def;
    this.index = index;
    this.unitDef = null;
    this.unit = null;
    this.state = 'wait';         // wait | live | done
    this.anchor = null;
    this.path = null;
    const res = play.scene.res?.[def.unit];
    if (typeof res === 'string') this.unitDef = play.fx.data.unit(res);
    const T = play.timeMs;
    this.start = (Number(def.life?.[0]) || 0) * T / 1000 / 1000;          // seconds
    this.end = (Number(def.life?.[1] ?? 1000)) * T / 1000 / 1000;
    if (this.end <= this.start) this.end = this.start + 0.001;
  }

  get fx() { return this.play.fx; }

  // Map preload only: allocate late controls without advancing their authored timeline.
  prepare(){
    if(this.state!=='wait'||!this.unitDef||this.def.active===false)return;
    this._spawn();if(!this.anchor)return;this.prepared=true;this.state='wait';
    this.anchor.visible=false;if(this.unit?.object)this.unit.object.visible=false;
  }
  _spawn() {
    if(this.prepared){this.prepared=false;this.state='live';this.anchor.visible=true;if(this.unit?.object)this.unit.object.visible=true;this._placeAnchor(true);this.basePosition=this.anchor.position.clone();this.baseQuaternion=this.anchor.quaternion.clone();this._pose(0);return;}
    const u = this.unitDef, d = this.def, fx = this.fx;
    this.state = 'live';
    if (!u || d.active === false) return;
    const anchor = new THREE.Group();
    anchor.matrixAutoUpdate = true;
    fx.root.add(anchor);
    this.anchor = anchor;
    // Worn equipment effects (talisman ground sigil, emblem overhead art) travel with their wearer even when the
    // scene control is authored `follow false` for cast-at-a-spot use.
    const worn = this.play.particleSpace === 'attachment' && this.play.ownerIsActor;
    this.frozen = !worn && (d.follow === false || !!d.absPos || (!this.play.ownerIsActor && !this.play.followPoint));
    this._placeAnchor(true);
    this.basePosition = anchor.position.clone();
    this.baseQuaternion = anchor.quaternion.clone();
    if (canPlayBonePath(d.boneAnim)) this.path = new BonePath(fx.game, d.boneAnim, this.end - this.start);
    const ctx = { game: fx.game, fx, control: this, play: this.play };
    const at = { x: anchor.position.x, z: anchor.position.z };
    try {
      switch (u.type) {
        case 'sprite': this.unit = new SpriteUnit(ctx, u, anchor); break;
        case 'decal': this.unit = new DecalUnit(ctx, u, anchor); break;
        case 'mesh': this.unit = new MeshUnit(ctx, u, anchor, this.end - this.start); break;
        case 'particle': this.unit = new ParticleUnit(ctx, u, anchor); break;
        case 'weather': if(Number(this.play.owner?.mapPlacementScale)>0)this.unit = new MapSnowWeatherUnit(ctx, u, anchor); break;
        case 'meshstatus': if (this.play.ownerIsActor) this.unit = new MeshStatusUnit(ctx, u, this.play.owner); break;
        case 'sound': this.unit = new SoundUnit(ctx, u, at); break;
        case 'quake': this.unit = new QuakeUnit(ctx, u, at); break;
        default: break;
      }
    } catch (err) { console.warn('[effects] unit failed', u?.name, err); this.unit = null; }
    this._pose(0);
  }

  _placeAnchor(first) {
    const a = this.anchor, d = this.def, owner = this.play.owner;
    if (!a) return;
    // Opt-in worn owners outside their source object's tree retain visibility
    // through global and first-person attachment passes. Other effects are unchanged.
    const visible = owner?.attachmentVisible;
    if (visible !== undefined) a.visible = visible !== false;
    if (!first && this.frozen) { a.position.copy(this.basePosition); a.quaternion.copy(this.baseQuaternion); return; }
    attachFrame(owner, missingPathSkeletonBone(d, owner) ?? controlBone(d, this.play.bone), _p, _q);
    let mirror = _mirrorX;
    if (d.absDir) { _q.identity(); mirror = 1; }
    if (this.play.yawOverride != null) { _q.setFromAxisAngle(UP, this.play.yawOverride); mirror = 1; }
    a.position.copy(_p);
    a.quaternion.copy(_q);
    // Mirrored bone: drawn units (children of the anchor) inherit the reflection; world-space particles/decals keep an
    // unreflected anchor and get it on their offset only (_pose).
    this.mirrorX = mirror;
    const worldSpace = this.unitDef?.type === 'particle' || this.unitDef?.type === 'weather' || this.unitDef?.type === 'decal';
    a.scale.set(worldSpace ? 1 : mirror, 1, 1);
    a.userData.yaw = d.absDir ? 0 : (this.play.yawOverride ?? (Number(owner?.yaw) || 0));
  }

  _pose(ms) {
    const u = this.unit;
    if (!u || !u.object && !(u instanceof ParticleUnit) && !(u instanceof MeshStatusUnit)) return;
    const d = this.def;
    const life = (this.end - this.start) * 1000;
    const k = life > 0 ? Math.max(0, Math.min(999, (ms / life) * 999)) : 0;
    const scale = evalKeys(d.scale, k, 3) || [1, 1, 1];
    const alphaK = evalKeys(d.alpha, k, 1);
    const color = controlColour(evalKeys(d.color, k, 3));
    const rotK = evalKeys(d.rotation, k, 1);
    const posK = d.position ? evalKeys(d.position, k, 3) : null;
    const base = posK || d.pos || [0, 0, 0];
    // Opt-in map placement TRS: scale control offsets as well as drawn units.
    const mapScale = Number(this.play.owner?.mapPlacementScale)>0?Number(this.play.owner.mapPlacementScale):1;
    const obj = u.object;
    if (obj && !(u instanceof ParticleUnit) && !(u instanceof DecalUnit)) {
      // local offset in the owner frame (anchor carries the rotation); a bone path adds its animated transform
      if (this.path && this.path.sample(ms / 1000, _m)) {
        _m.decompose(_off, _yq, _s);
        obj.position.set((base[0] + _off.x)*mapScale, (base[1] + _off.y)*mapScale, (base[2] + _off.z)*mapScale);
        obj.quaternion.copy(_yq);
      } else {
        obj.position.set(base[0]*mapScale, base[1]*mapScale, base[2]*mapScale);
      }
    } else if (u instanceof DecalUnit || u instanceof ParticleUnit) {
      // Rebuild from the attachment frame: preload may pose the same control
      // repeatedly without a timeline update, so offsets must not accumulate.
      this._placeAnchor(false);
      _off.set(base[0], base[1], base[2]);
      const pathReady = this.path && this.path.sample(ms / 1000, _m);
      if (pathReady) {
        _m.decompose(_p, _yq, _s);
        _off.add(_p);
      }
      _off.x *= this.mirrorX || 1;
      _off.multiplyScalar(mapScale).applyQuaternion(this.anchor.quaternion);
      this.anchor.position.add(_off);
      if (pathReady) this.anchor.quaternion.multiply(_yq);
    }
    const scaleMul = this.play.scale;
    const st = {
      scale: [scale[0] * scaleMul, (scale[1] ?? scale[0]) * scaleMul, (scale[2] ?? scale[0]) * scaleMul],
      alpha: (alphaK ? alphaK[0] : 1) * this.play.alpha,
      color, rot: rotK ? rotK[0] : 0, ms, life, frac: k / 999,
      animTime: d.animTime, randomStart: d.randomStart,
    };
    try { u.apply(st); } catch (err) { /* a unit must never break the frame */ }
  }

  update(t, dt) {
    if (this.state === 'wait') {
      // A soft stop only preserves already-emitted tails. Do not start a future
      // control (including a sound/quake) after the cast/owner has ended.
      if (this.play.stopping) { this._dispose(); return; }
      if (t < this.start) return;
      this._spawn();
    }
    if (this.state === 'live') {
      if (t >= this.end || this.play.stopping) {
        this._end();
        return;
      }
      this._placeAnchor(false);
      this._pose((t - this.start) * 1000);
      try { this.unit?.update?.(dt); } catch { /* ignore */ }
    } else if (this.state === 'fading') {
      try { this.unit?.update?.(dt); } catch { /* ignore */ }
      if (!this.unit || !this.unit.finishing()) this._dispose();
    }
  }

  _end() {
    const u = this.unit;
    // Particles and tailstep trails keep their live copies after the control ends (they fade on their own schedule).
    if (u && u.finishing() && !this.play.hardStop) {
      u.stopEmitting();
      this.state = 'fading';
      return;
    }
    this._dispose();
  }

  _dispose() {
    this.state = 'done';
    try { this.unit?.dispose(); } catch { /* ignore */ }
    this.unit = null;
    this.path?.dispose();
    this.path = null;
    if (this.anchor) { this.anchor.removeFromParent(); this.anchor = null; }
  }

  reset() { this._dispose(); this.state = 'wait'; }
  get finished() { return this.state === 'done'; }
}

// ============================================================================================ scene selection
/** Scene key an effect draws for a requested scene id: that scene when it exists, else the effect's first scene (the
 *  existing visual fallback, unchanged), else null. Pure. */
export function playedSceneKey(scene, sceneId) {
  const scenes = scene?.scenes;
  if (!scenes) return null;
  if (sceneId != null && scenes[sceneId]) return String(sceneId);
  const first = Object.keys(scenes)[0];
  return first != null && scenes[first] ? first : null;
}

/** Scene key of the `.snd` half (sound.json skill[id] / effectSound[cate][id] .scenes) for a requested scene id.
 *  S0 (lanes-20261016 lane-A-scenes REPORT "scene 0 = first scene", decided from data: Judge of Helion 185/3013/3025 and
 *  Fire ball 463 author their only visual at scene 0, and no Global effect library defines a scene 0): a scene-0 request
 *  plays the effect's first scene, and the `.snd` half of the same key belongs to that scene, so its sound list is taken
 *  from the played scene too (judgeofhelion.wav, dreadnail_boom.wav, ...; 10 remote rows author scene 0). Any other
 *  requested id keeps its own key: a missing scene above 0 still draws the first scene but plays no `.snd` list
 *  (unchanged; the native reading of that case is unproven). Pure. */
export function soundSceneKey(sceneId, playedKey) {
  return Number(sceneId) === 0 && sceneId !== null && sceneId !== '' && playedKey != null ? playedKey : sceneId;
}

// ============================================================================================ scene play
export class ScenePlay {
  constructor(fx, owner, scene, sceneId, ref, opts) {
    this.fx = fx;
    this.owner = owner;
    this.ownerIsActor = !!(owner && (owner.group || owner.instance || owner.kind));
    this.scene = scene;
    this.key = `${ref.cate ?? 100}:${ref.id}`;
    this.sceneId = sceneId;
    this.timeMs = Number(ref.timeMs) > 0 ? Number(ref.timeMs) : 1000;
    this.loop = !!opts.loop;
    this.followPoint = !!opts.followPoint;
    this.bone = opts.bone ?? null;
    this.yawOverride = opts.yaw ?? null;
    this.scale = Number(opts.scale) > 0 ? Number(opts.scale) : (this.ownerIsActor ? Math.min(3, Math.max(0.5, Number(owner.scale) || 1)) : 1);
    // Equipment attachment is an engine policy; ordinary skill particles remain world-space.
    this.particleSpace = opts.particleSpace === 'attachment' ? 'attachment' : 'world';
    this.depthBias = Math.max(0, Number(opts.depthBias) || 0);   // metres: camera sprites are depth-shifted toward the camera (SpriteUnit)
    this.alpha = 1;
    this.t = 0;
    this.stopping = false;
    this.hardStop = false;
    this.done = false;
    this.onEnd = opts.onEnd || null;
    const visualKey = playedSceneKey(scene, sceneId);
    this.playedSceneId = visualKey;            // scene key actually drawn (requested id, else the first scene)
    const sc = visualKey != null ? scene.scenes[visualKey] : null;
    // An optional caller filter retains source control indices and leaves scene sound selection unchanged.
    this.controls = (sc?.controls || []).flatMap((c, i) => !opts.controlFilter || opts.controlFilter(c, i) ? [new ControlPlay(this, c, i)] : []);
    this.length = Math.max(this.timeMs / 1000, ...this.controls.map(c => c.end));
    this.oneShotLength = this.timeMs / 1000;
    if (!this.loop) this.length = Math.max(this.oneShotLength, ...this.controls.map(c => c.end));
    this._sound(ref);
  }

  _sound(ref) {
    const fx = this.fx, S = fx.game.audio?.S;
    if (!fx.soundOn || !S || !fx.game.audio?.playAll) return;
    const cate = Number(ref.cate ?? 100);
    const id = String(ref.id);
    const book = cate === 100 ? S.skill?.[id] : S.effectSound?.[cate]?.[id];
    const scenes = book?.scenes;
    if (!scenes) return;
    const list = scenes[String(soundSceneKey(this.sceneId, this.playedSceneId))] || (this.sceneId == null ? Object.values(scenes)[0] : null);
    if (!list) return;
    const o = this.owner;
    this._soundHandles = [];
    const onHandle = handle => {
      if (!handle) return;
      if (!this._soundHandles.includes(handle)) this._soundHandles.push(handle);
      if (this.stopping || this.done) this._stopSounds();
    };
    const pending = fx.game.audio.playAll(list, {
      at: o ? { x: Number(o.x) || 0, z: Number(o.z) || 0 } : null,
      isCurrent: rec => !this.stopping && !this.owner?.disposed && (!this.done || rec?.unkFlag !== 0),
      category: this.owner?.kind === 'servant' ? 'servant' : cate === 100 ? 'skill' : undefined,
      onHandle,
    });
    Promise.resolve(pending).then(handles => {
      for (const handle of handles || []) onHandle(handle);
    });
  }

  /** A worn-equipment control that spans the whole loop keeps its unit across cycles (no despawn flicker). */
  _continuous(c) {
    const T = this.timeMs / 1000;
    return this.particleSpace === 'attachment' && c.state === 'live' && c.unit && c.start <= 1e-6 && c.end >= T - 1e-6
      && !(c.unit instanceof SoundUnit) && !(c.unit instanceof QuakeUnit);
  }

  update(dt) {
    if (this.done) return;
    this.t += dt;
    if (this.ownerIsActor && (this.owner.disposed) && !this.stopping) this.stop(true);
    if (this.particleSpace === 'attachment' && this.loop && !this.stopping && this.t >= this.timeMs / 1000) {
      // Wrap before updating so a full-length worn unit is never ended at the loop boundary.
      const T = this.timeMs / 1000;
      this.t %= T;
      for (const c of this.controls) if (c.state !== 'fading' && !this._continuous(c)) c.reset();
    }
    let allDone = true;
    for (const c of this.controls) {
      c.update(this.t, dt);
      if (!c.finished) allDone = false;
    }
    if (this.loop && !this.stopping && this.t >= this.timeMs / 1000) {
      // restart the timeline; units still alive end on their own schedule
      this.t = 0;
      for (const c of this.controls) if (c.state !== 'fading') c.reset();
      return;
    }
    if ((allDone && (this.t >= this.oneShotLength || this.stopping)) || (this.stopping && this.hardStop)) this._finish();
  }

  /** Stop now (hard: remove every unit; soft: stop spawning / let particles finish). */
  stop(hard = false) {
    if (this.done) return;
    this.stopping = true;
    this.loop = false;
    if (hard) this.hardStop = true;
    this._stopSounds();
    if (hard) {
      this.hardStop = true;
      for (const c of this.controls) c._dispose();
      this._finish();
    }
  }

  _stopSounds() {
    const now = this.fx.game.audio?.ctx?.currentTime ?? Infinity;
    for (const handle of this._soundHandles || []) {
      // Pending timeline cues cannot start after cancellation. Hard teardown also
      // ends audible cues; soft particle completion retains ordinary sound tails.
      if (this.hardStop || handle.voice?.stateBound || (this.stopping && handle.voice?.t > now)) handle.stop?.();
    }
  }

  _finish() {
    if (this.done) return;
    this.done = true;
    this._stopSounds();
    for (const c of this.controls) c._dispose();
    this.fx._removed(this);
    try { this.onEnd?.(); } catch { /* ignore */ }
  }
}

// ============================================================================================ player
export class EffectPlayer {
  constructor(game, data) {
    this.game = game;
    this.data = data;
    this.root = new THREE.Group();
    this.root.name = 'effects (FILE frame)';
    game.worldRoot?.add(this.root);
    this.active = new Set();
    this.cam = {};
    this.quakes = new Set();
    this.soundOn = true;          // sound units + .snd scenes (audio.js skips its own skill sounds, see index.js)
    this.enabled = true;
    this._installQuake();
  }

  /**
   * Play an effect.
   * @param owner  Actor (bones, follows it) or a FILE point {x, y?, z, yaw?} (ground effects)
   * @param ref    {cate=100, id, scene, timeMs, loop?}
   * @param opts   {loop, bone, yaw, scale, onEnd}
   * @returns ScenePlay | null
   */
  play(owner, ref, opts = {}) {
    if (!this.enabled || !ref || !(Number(ref.id) > 0) || !owner) return null;
    const cate = Number(ref.cate ?? 100);
    const scene = this.data.scene(`${cate}:${Number(ref.id)}`);
    if (!scene) return null;
    if (owner && !(owner.group || owner.instance) && owner.y == null) {
      const w = this.game.world;
      owner = { ...owner, y: w?.heightAt ? w.heightAt(owner.x, owner.z) : 0 };
    }
    // distance cull (new effects only)
    const t = this.game.player;
    if (t && owner.mapPlacementScale == null && Math.hypot((owner.x || 0) - t.x, (owner.z || 0) - t.z) > CULL_DIST) return null;
    const sceneId = ref.scene ?? 1;
    const loop = opts.loop != null ? !!opts.loop : ref.loop === 0;
    const play = new ScenePlay(this, owner, scene, sceneId, ref, { ...opts, loop });
    if (!play.controls.length) return null;
    this.active.add(play);
    if (this.active.size > MAX_ACTIVE) {
      for (const p of this.active) { if (!p.loop) { p.stop(true); break; } }
    }
    return play;
  }

  /** Play at a ground point (FILE frame). */
  playAt(point, ref, opts = {}) {
    if (!point) return null;
    return this.play({ x: point.x, y: point.y, z: point.z, yaw: point.yaw ?? opts.yaw ?? 0, quaternion:point.quaternion, height: 0 }, ref, opts);
  }

  _removed(p) { this.active.delete(p); }

  update(dt) {
    if (!this.active.size && !this.quakes.size) return;
    if (this.game.camera) cameraFrame(this.game.camera, this.cam);
    for (const p of [...this.active]) {
      try { p.update(dt); } catch (err) { console.warn('[effects] play failed', p.key, err); p.stop(true); }
    }
  }

  /** Remove everything (map change). */
  clear() {
    for (const p of [...this.active]) p.stop(true);
    this.active.clear();
    this.quakes.clear();
  }

  // ---------------------------------------------------------------------------------------- camera quake
  addQuake(q) { q.t0 = this.game.time || 0; this.quakes.add(q); }
  removeQuake(q) { this.quakes.delete(q); }
  _installQuake() {
    const scene = this.game.scene;
    if (!scene) return;
    let record = quakeScenes.get(scene);
    if (record) { record.sources.add(this); this._quakeScene = record; return; }
    const prevB = scene.onBeforeRender, prevA = scene.onAfterRender;
    const off = new THREE.Vector3();
    record = {scene, prevB, prevA, sources: new Set([this])};
    record.before = (...args) => {
      try { prevB?.apply(scene, args); } catch { /* ignore */ }
      off.set(0, 0, 0);
      let amp = 0, f = 10, source = null;
      for (const fx of record.sources) for (const q of fx.quakes) if (q.amp > amp) { amp = q.amp; f = q.freq; source = fx; }
      if (source) {
        const now = source.game.time || 0;
        if (amp > 0) {
          const t = now * f * Math.PI * 2;
          off.set(Math.sin(t) * amp, Math.sin(t * 1.37 + 1) * amp, Math.cos(t * 0.93) * amp * 0.5);
          const cam = args[2] || source.game.camera;
          record.camera = cam;
          cam.position.add(off);
          cam.updateMatrixWorld();
        }
      }
    };
    record.after = (...args) => {
      try { prevA?.apply(scene, args); } catch { /* ignore */ }
      if (off.lengthSq() > 0) {
        const cam = record.camera;
        cam.position.sub(off);
        cam.updateMatrixWorld();
        off.set(0, 0, 0);
        record.camera = null;
      }
    };
    scene.onBeforeRender = record.before;
    scene.onAfterRender = record.after;
    quakeScenes.set(scene, record);
    this._quakeScene = record;
  }

  dispose() {
    this.clear();
    this.root.removeFromParent();
    const record = this._quakeScene;
    if (record) {
      record.sources.delete(this);
      if (!record.sources.size) {
        if (record.scene.onBeforeRender === record.before) record.scene.onBeforeRender = record.prevB;
        if (record.scene.onAfterRender === record.after) record.scene.onAfterRender = record.prevA;
        quakeScenes.delete(record.scene);
      }
      this._quakeScene = null;
    }
  }
}
