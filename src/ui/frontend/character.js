// Front-end characters: the real Player assembly (src/actors/player.js: class skeleton + 5 skinned parts + weapon,
// clips through ModelCache / Animator) running on the FrontStage instead of a Game.
//
//  * fromSave(stage, save, classDef)       a saved character, wearing its equipment (save.equipment), as in-game.
//  * showcase(stage, classDef)             the class-select outfit (classes.json showcase.parts = the _14 armour set
//                                          shown by the class-select screen) at the char_selectinfo scale.
//
// Extra behaviour over Player:
//  * frontRest: the loop the character returns to after a one-shot ('createPose' = the class-select STAND motion,
//    'idle' = peace stand, 'idleCombat' = battle stand).
//  * preview equipment (character-create "Preview" tab, gamedata/frontend.json): previewParts {slot: asset} replace
//    skinned parts; previewWeapons {right, left} (frontend.json weapon entries) replace the weapon, attached to the
//    bones of their weapon type (items.json equipment.weaponBones), the left-hand mesh with its own textures.
//  * ground: front-end scenes put 'ground' helper meshes on ceilings (MAL_Login uses a temple floor mesh as its
//    ceiling), so the height is taken from the terrain plus walkable surfaces within a step of it.
//  * standOnFloor(): the posed model is measured (skinned vertices + weapons, measureBody) and lifted / lowered so its
//    feet touch the drawn stage floor at the showcase scale (feetAdjust); the select / create
//    cameras frame those bounds (selectinfo.js frameView).
import * as THREE from 'three';
import { Player } from '../../actors/player.js';
import { fileToThree } from '../../engine/space.js';
import {showcaseSlot,loadShowcaseVisuals} from './showcase.js';
import { ItemDB } from '../../systems/items/db.js';
import { Equipment } from '../../systems/items/equip.js';
import { MountsData, EQUIP_SLOT } from '../../systems/mounts/data.js';
import { WingVisual } from '../../systems/mounts/wings.js';

let mountsData = null;
function loadMountsData() {
  if (!mountsData) { const data = new MountsData(); mountsData = data.load().then(() => data).catch(err => { mountsData = null; throw err; }); }
  return mountsData;
}
/** Server characters store worn gear as save.equip (presets/items); the legacy look view is rebuilt from it. */
export function hasWornEquip(save) {
  const e = save?.equip, preset = e?.presets?.[e.active || 0];
  return !!preset && Object.values(preset).some(uid => e.items?.[uid]);
}

const _v = new THREE.Vector3();
const _n = new THREE.Vector3();
const _box = new THREE.Box3();
const _down = new THREE.Vector3(0, -1, 0);

/** showcase.parts -> save.equipment-style {slot: {mesh, tpack, textures}} (slot from the mesh file name). */
export function showcaseEquipment(classDef) {
  const eq = {};
  for (const p of classDef?.showcase?.parts || []) {
    const slot = showcaseSlot(p);
    if (slot && !eq[slot]) eq[slot] = { mesh: p.mesh, tpack: p.tpack || null, textures: p.textures || null };
  }
  return eq;
}

/**
 * frontend.json weapon entries -> a Player weapon def { mesh, tpack, textures, bone, bonePeace, leftMesh, leftTpack,
 * leftTextures, boneLeft, bonePeaceLeft }. `base` = the class default weapon (used when no right-hand weapon is set).
 */
export function composeWeapon(right, left, base = null) {
  const B = e => e?.bones || {};
  let w = null;
  if (right) {
    const b = B(right);
    const lhand = right.column === 'left';           // bows / cross bows are held in the left hand
    w = {
      mesh: right.main.mesh, tpack: right.main.tpack || null, textures: right.main.textures || null,
      bone: lhand ? b.battleLeft : b.battleRight, bonePeace: lhand ? b.peaceLeft : b.peaceRight,
      leftMesh: null, boneLeft: b.battleLeft, bonePeaceLeft: b.peaceLeft,
    };
    if (right.column === 'both' && right.left) {       // twin swords, gauntlets, dual blades, katars: one mesh per hand
      Object.assign(w, { leftMesh: right.left.mesh, leftTpack: right.left.tpack || null, leftTextures: right.left.textures || null });
    }
  } else if (base) {
    w = { ...base };
  }
  if (left && (!right || (right.hands || 1) < 2)) {
    const b = B(left);
    if (!w) {
      w = { mesh: left.main.mesh, tpack: left.main.tpack || null, textures: left.main.textures || null, bone: b.battleLeft, bonePeace: b.peaceLeft, leftMesh: null };
    } else {
      Object.assign(w, { leftMesh: left.main.mesh, leftTpack: left.main.tpack || null, leftTextures: left.main.textures || null, boneLeft: b.battleLeft, bonePeaceLeft: b.peaceLeft });
    }
  }
  return w;
}

export class FrontCharacter extends Player {
  /**
   * @param {import('./stage.js').FrontStage} stage
   * @param {object} save      save.js record (or a synthetic one for the showcase)
   * @param {object} classDef  classes.json classes[i]
   * @param {{scale?:number, rest?:string}} [opts]
   */
  constructor(stage, save, classDef, { scale = 1, rest = 'idle', standDuration = null } = {}) {
    super(stage, save, classDef);
    this.stage = stage;
    this.scale = Number(scale) > 0 ? Number(scale) : 1;
    this.frontRest = rest;
    this.standDuration = Number(standDuration) > 0 ? Number(standDuration) : null;
    this.pickHeight = this.height;
    this.previewParts = null;      // {slot: {mesh, tpack, textures}}
    this.previewWeapons = null;    // {right, left} frontend.json weapon entries
  }

  static fromSave(stage, save, classDef, opts = {}) {
    return new FrontCharacter(stage, save, classDef, opts);
  }

  static showcase(stage, classDef, opts = {}) {
    const save = { name: classDef?.name || '', classIndex: Number(classDef?.index) || 0, level: 1, equipment: showcaseEquipment(classDef) };
    const scale = Number(classDef?.showcase?.scale) > 0 ? Number(classDef.showcase.scale) : 1;
    const actor = new FrontCharacter(stage, save, classDef, { scale, rest: 'createPose', ...opts });
    actor._showcaseArmor = true;
    return actor;
  }

  // ---------------------------------------------------------------------------------------- appearance
  partDefs() {
    const pv = this.previewParts || {};
    const eq = this.save?.equipment || {};
    return (this.classDef?.parts || []).map(p => {
      const e = pv[p.slot] || eq[p.slot];
      const src = e && e.mesh ? e : p;
      return { meshKey: src.mesh, tpackKey: src.tpack || null, textures: src.textures || null };
    }).filter(p => p.meshKey);
  }

  weaponDef() {
    const pw = this.previewWeapons;
    if (!pw || (!pw.right && !pw.left)) return super.weaponDef();
    return composeWeapon(pw.right, pw.left, super.weaponDef());
  }

  // Player's loader handles independent left-hand textures AND authored weapon skeleton/animation.
  // Keep that path for saved equipment; preview parts/weapon selection is supplied by the methods above.
  async _loadVisuals() {
    if (this._showcaseArmor) {
      const visuals = await loadShowcaseVisuals(this.classDef);
      this.save.equipment = Object.fromEntries(Object.entries(visuals.equipment).map(([slot,asset])=>[slot,{...asset}]));
      this._showcaseEntries = visuals.entries;
      this.showcaseReferences = visuals.references;
    } else if (hasWornEquip(this.save)) {
      // The same worn-item look the world assembles (armour parts, socketed/animated weapons, costume, wing,
      // emblem/talisman), on a copy so the listed character record is never rewritten by the preview.
      try {
        const db = await ItemDB.load();
        db._actionsData ||= await db.actions();
        const save = { ...this.save };
        save.equipment = new Equipment({ db, game: { save, settings: {} } }).view();
        this.save = save;
      } catch (err) { console.warn('[frontend] saved equipment look', err); }
    }
    return super._loadVisuals();
  }

  /** Equipped wing (or its appearance) on the select stage, through the same WingVisual remote players use. */
  _syncWing(dt) {
    if (this._showcaseArmor || this.disposed || !this.instance) return;
    const e = this.save?.equip, uid = e?.presets?.[e.active || 0]?.[EQUIP_SLOT.wing];
    if (!uid || !e.items?.[uid]) return;
    if (!this._wings) {
      if (this._wingsLoading) return;
      this._wingsLoading = loadMountsData().then(data => {
        if (this.disposed) return;
        const facade = Object.create(this.stage);
        Object.defineProperty(facade, 'player', { get: () => this });
        Object.defineProperty(facade, 'save', { get: () => this.save });
        facade.events = { emit() {} };
        this._wings = new WingVisual({ game: facade, data, riding: null });
      }).catch(err => console.warn('[frontend] wing look', err));
      return;
    }
    this._wings.update(dt);
  }

  update(dt) {
    super.update(dt);
    try { this._syncWing(dt); } catch (err) { console.warn('[frontend] wing update', err); }
  }

  dispose() {
    this._wings?.dispose();
    this._wings = null;
    super.dispose();
  }

  showcaseEffectEntries() {
    if (!this._showcaseArmor) return null;
    // Previewing another item never grants it the showcase's maxed grade, even if it reuses a mesh.
    return (this._showcaseEntries || []).filter(entry => !this.previewParts?.[entry.slot]);
  }

  /** Change the preview outfit and rebuild the body (keeps position, yaw and the playing state). */
  async setPreview({ parts, weapons } = {}) {
    if (parts !== undefined) this.previewParts = parts;
    if (weapons !== undefined) this.previewWeapons = weapons;
    if (!this.loaded || this.disposed) return false;
    return this.refreshAppearance();
  }

  _install(v) {
    super._install(v);
    this.pickHeight = this.height;
  }

  /** Peace stance for the char_ct clips; everything else as Player. */
  _styleForAnim(anim) {
    if (/char_ct\//i.test(String(anim || '').replace(/\\/g, '/'))) return 0;
    return super._styleForAnim(anim);
  }

  _specFor(state, opts = {}) {
    const spec = super._specFor(state, opts);
    // The producer's per-class STAND timing belongs to selection/create. Some action-table clips carry
    // much shorter gameplay timings (Alokes 2 s, Trie Muse 1.5 s); use the actual showcase duration here.
    if (spec && state === 'createPose' && this.standDuration && !(Number(opts.timeLength) > 0)) {
      return { ...spec, duration: this.standDuration };
    }
    return spec;
  }

  _restState() {
    if (this.dead) return null;
    return this.frontRest || 'idle';
  }

  /** Front-end characters never enter the combat stance by themselves. */
  inBattle() { return false; }

  /**
   * Terrain + walkable object surfaces (stages, pedestals). With standCap (the class-select scenes: the camera eye +
   * 1.2 m) the highest surface up to it - the stages of the class-select maps stand up to 4.6 m above their terrain
   * (Summoner) and the camera is placed at their level; otherwise surfaces up to ~3 m above the terrain (higher ones
   * are ceilings, e.g. MAL_Login's temple floor mesh 7.9 m above the throne room).
   */
  _heightAt(x, z) {
    const w = this.game?.world;
    if (!w || !w.map) return null;
    try {
      const t = typeof w.terrainHeightAt === 'function' ? w.terrainHeightAt(x, z) : w.heightAt(x, z);
      const h = w.heightAt(x, z, Number.isFinite(this.standCap) ? this.standCap : t + 3);
      return Number.isFinite(h) ? h : (Number.isFinite(t) ? t : null);
    } catch { return null; }
  }

  /** Place at a FILE point and a FILE-frame facing angle (radians, rotation.y under the mirror root). */
  place(x, z, yaw = 0) {
    this.setPosition(x, z);
    this.yaw = yaw;
    this._grounded = false;
    this._snapY(true);
    this._syncGroup();
  }

  /** As Actor, plus the feet adjustment of standOnFloor (this.y stays the surface height). */
  _syncGroup() {
    super._syncGroup();
    if (this.feetAdjust) this.group.position.y += this.feetAdjust;
  }

  /** Wait until the clip of a state is loaded, so a pose measured after play() is the real one. */
  async readyPose(state = 'createPose') {
    try { if (this.animator && this.model) await this._preload([[state, null]]); } catch { /* no clip */ }
  }

  /**
   * Bounds of the posed body (FILE frame; y is not mirrored): bottom = the lowest skinned vertex (the feet), top =
   * the highest point of the skinned parts and the attached weapons (a mesh far off the body - e.g. a weapon whose
   * bone is missing - is left out). `step` > 1 samples every step-th vertex.
   * @returns {{x:number, z:number, bottom:number, top:number}|null}
   */
  measureBody(step = 1) {
    const inst = this.instance;
    if (!inst?.meshes?.length) return null;
    this.group.updateMatrixWorld(true);
    let lo = Infinity, hi = -Infinity;
    for (const m of inst.meshes) {
      const pos = m.visible ? m.geometry?.getAttribute?.('position') : null;
      if (!pos) continue;
      for (let i = 0; i < pos.count; i += step) {
        m.getVertexPosition(i, _v).applyMatrix4(m.matrixWorld);
        if (_v.y < lo) lo = _v.y;
        if (_v.y > hi) hi = _v.y;
      }
    }
    if (!(hi > lo)) return null;
    const h = hi - lo;
    let top = hi;
    for (const o of inst._attached || []) {
      if (!o?.visible) continue;
      _box.setFromObject(o);
      if (_box.isEmpty() || _box.min.y < lo - 1 || _box.max.y > hi + h) continue;
      top = Math.max(top, _box.max.y);
    }
    return { x: this.x, z: this.z, bottom: lo, top };
  }

  /**
   * measureBody over the whole playing clip (the class-select STAND motions raise weapons and step about): the pose
   * is sampled at `samples` times of the clip, then the playing time is restored.
   */
  measureMotion(samples = 16) {
    const anim = this.animator, a = anim?.current;
    const out = this.measureBody();
    const d = a?.getClip?.().duration;
    if (!out || !(d > 0)) return out;
    const t0 = a.time;
    try {
      for (let i = 0; i < samples; i++) {
        a.time = (d * i) / samples;
        anim.mixer.update(0);
        const b = this.measureBody(2);
        if (b) { out.bottom = Math.min(out.bottom, b.bottom); out.top = Math.max(out.top, b.top); }
      }
    } finally {
      a.time = t0;
      anim.mixer.update(0);
    }
    return out;
  }

  /**
   * The drawn floor under (x, z) near `near`: the highest flat face of the scene meshes within 0.3 m of it (the
   * walkable helpers of some stages sit a few cm off the drawn floor). Water, decals and actors are ignored.
   */
  _visualFloor(x, z, near) {
    const root = this.stage?.worldRoot;
    if (!root || !Number.isFinite(near)) return null;
    const skip = new Set([...(this.stage.actors || [])].map(a => a?.group).filter(Boolean));
    skip.add(this.group);
    const meshes = [];
    const walk = o => {
      if (skip.has(o) || o.visible === false || o.userData?.instance) return;
      if (o.isMesh && !o.isSkinnedMesh && !/water|decal/i.test(o.name || '')) meshes.push(o);
      for (const c of o.children) walk(c);
    };
    walk(root);
    const rc = new THREE.Raycaster(fileToThree(x, near + 0.3, z, new THREE.Vector3()), _down, 0, 0.6);
    try {
      for (const hit of rc.intersectObjects(meshes, false)) {
        if (hit.face?.normal && Math.abs(_n.copy(hit.face.normal).transformDirection(hit.object.matrixWorld).y) < 0.6) continue;
        return hit.point.y;
      }
    } catch { /* a mesh that cannot be ray-cast */ }
    return null;
  }

  /**
   * Ground-snap the staged model: play `state` (the class-select STAND motion), measure the body
   * over that motion and lift / lower it so its lowest skinned vertex (the feet, at the showcase scale) touches the
   * drawn stage floor under it. Every class then stands on the same floor, neither floating nor sunk.
   * @returns {{x, z, bottom, top}|null} the body bounds after the snap (FILE frame, whole motion)
   */
  standOnFloor(state = this.frontRest) {
    if (!this.loaded || this.disposed || !this.instance) return null;
    if (state) { this.play(state, { fade: 0 }); this.update(0.05); }   // hard switch: no blend with the idle it loaded in
    this._snapY(true);
    const floor = this._visualFloor(this.x, this.z, this.y) ?? this.y;
    this.feetAdjust = 0;
    this._syncGroup();
    const b = this.measureMotion();
    if (!b) return null;
    const lift = floor - b.bottom;
    this.feetAdjust = Math.abs(lift) < 0.6 ? lift : 0;
    this._syncGroup();
    return { ...b, bottom: b.bottom + this.feetAdjust, top: b.top + this.feetAdjust };
  }
}
