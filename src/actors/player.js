// The player character (docs/ARCHITECTURE.md §3.5): class skeleton + 5 skinned parts + a rigid weapon.
//
// Data: gamedata/classes.json classes[i] (docs/formats/characters.md):
//   skeleton, parts[5] {slot, mesh, tpack, textures}   (save.equipment[slot] with a .mesh replaces a part: equipment)
//   weapon {mesh, tpack, textures, leftMesh, bone, bonePeace, boneLeft, bonePeaceLeft}
//   anims {idlePeace, idlePeaceAlt, walkPeace, runPeace, idle, idleAlt, walk, run, die, revive, knockdown, stun, sleep,
//          block, guard, createPose, sitDown, sit, standUp, attack[], hit[], blocked[], emotes[]}
//
// States (play): 'idle' = peace stand (anims.idlePeace), 'idleCombat' = battle stand (anims.idle), 'run'/'walk' = battle
// or peace locomotion depending on the stance (below; the playback rate follows the ground speed, Actor LOCOMOTION
// SYNC; groundSpeed() = the clip's root-motion stride / TimeLength x buffs is the speed the controller moves at), 'attack' (opts.variant = combo step k -> anims.attack[k], stretched to opts.timeLength),
// 'hit' (variant 0|1 -> anims.hit[v]), 'die', 'skill'/'cast' (opts.anim = any anim key, loaded on demand and stretched
// to opts.timeLength), 'emote' (opts.variant = emote name or index) and every other anims key by name ('revive',
// 'sitDown', 'sit', 'standUp', 'createPose', 'knockdown', ...).
//
// Required attachment: weapons stay on weapon.bone / weapon.boneLeft for every clip style, including explicit
// peace idle and emotes. Clip style still records 'peace' / 'battle' in stance; it does not select sheath bones.
// An equipped main weapon selects armed locomotion. Unarmed locomotion uses battle clips for STANCE_SECONDS after
// the last combat action (lastCombat, set by combat.js) or while a living monster is targeted, otherwise peace clips.
import { Actor, LOOP_STATES, STANCE_SECONDS, interFade, clipEntry } from './actor.js';
import { Animator } from '../engine/animator.js';
import { walkSpeedRatio } from '../game/progression.js';
import { isUnderwaterMap } from '../game/swimming.js';

const FIDGET_MIN = 9;     // s of standing still before the idle "look around" variant plays once
const FIDGET_MAX = 16;
const SWING_DONE = 0.9;   // ENGINE-CHOSEN: fraction of an attack clip after which a new clip no longer counts as cutting the swing (_cutAttackEffects)
const normKey = k => String(k || '').trim().replace(/\\/g, '/').replace(/^\/+/, '').toLowerCase();

const weaponVisualKey = (def, hand) => {
  if (!def) return null;
  if (hand === 'main') return def.mesh ? JSON.stringify([def.mesh, def.tpack, def.textures, def.skel, def.anim, def.animTime, def.attachSkel]) : null;
  if (!def.leftMesh) return null;
  const same = def.leftMesh === def.mesh, explicit = def.leftTpack || def.leftTextures;
  return JSON.stringify([def.leftMesh, explicit ? def.leftTpack : same ? def.tpack : null, explicit ? def.leftTextures : same ? def.textures : null,
    def.leftSkel, def.leftAnim, def.leftAnimTime, def.leftAttachSkel]);
};

/**
 * Weapon model: rigid (StaticModel) or, for animated weapons (items system weaponView: skel + anim = the item action
 * table's skeleton and loop clip, items.md 7.3), a skinned instance playing its loop, attached to the hand bone the
 * same way. Returns an object with instantiate() -> Object3D (userData.weaponAnimator is updated by Player.update).
 */
function weaponModel(models, mesh, opts, skel, anim, animTime, attachSkel = null) {
  const animated = !!(skel && anim);
  if (!animated && attachSkel && models.loadSkinned) {
    // The item's own action skeleton supplies effect attachment bones even when it has no motion rows.
    // Keep the rigid mesh and itemmesh.fx material path: skinning it would select boneanimation.fx/env materials.
    // Reuse the native model builder for bind-pose/shear/alias handling, retaining only its bone hierarchy.
    return Promise.all([
      models.loadStatic(mesh, opts),
      models.loadSkinned({ skelKey: attachSkel, parts: [{ meshKey: mesh, tpackKey: opts.tpackKey || null, textures: opts.textures || null }] }),
    ]).then(([rigid, rig]) => {
      if (!rigid || !rig || rig.empty || rig.missingSkeleton) return rigid;
      return { instantiate() {
        const object = rigid.instantiate(), inst = rig.instantiate();
        for (const part of inst.meshes) part.removeFromParent();
        inst.meshes.length = 0;
        inst.bones.forEach((bone, i) => { bone.userData.raw = rig.skel?.bones?.[i]?.name || bone.name; });
        // There are no skinned draws or animations on this attachment; no bone texture is needed.
        inst.skeleton.dispose();
        object.add(inst.root);
        return object;
      } };
    }).catch(() => models.loadStatic(mesh, opts));
  }
  if (!animated || !models.loadSkinned) return models.loadStatic(mesh, opts);
  return models.loadSkinned({ skelKey: skel, parts: [{ meshKey: mesh, tpackKey: opts.tpackKey || null, textures: opts.textures || null }] })
    .then(async (m) => {
      if (!m || m.empty) return models.loadStatic(mesh, opts);
      const clip = await models.loadClip(anim, m, { duration: animTime || 2 }).catch(() => null);
      return {
        skinned: true,
        instantiate() {
          const inst = m.instantiate();
          inst.root.traverse(o => { if (o.isSkinnedMesh) o.frustumCulled = false; });
          const an = clip ? new Animator(inst) : null;
          if (an) an.play(clip, { loop: true, fade: 0 });
          inst.root.userData.weaponAnimator = an;
          return inst.root;
        },
      };
    })
    .catch(() => models.loadStatic(mesh, opts));
}

/** anim key -> action style, from the class's skill steps (skill clips carry their own weapon style). */
function skillStyleMap(classDef) {
  const m = new Map();
  for (const s of classDef?.skills || []) {
    const add = a => { if (a?.anim && a.style != null && !m.has(normKey(a.anim))) m.set(normKey(a.anim), Number(a.style)); };
    add(s.ready?.anim);
    for (const st of s.steps || []) add(st.anim);
    for (const L of s.levels || []) for (const st of L?.steps || []) add(st.anim);
  }
  return m;
}

export class Player extends Actor {
  /**
   * @param {object} game
   * @param {object} save      save.js character record (name, level, classIndex, equipment, ...)
   * @param {object} classDef  classes.json classes[i]
   */
  constructor(game, save = {}, classDef = {}) {
    super(game, { kind: 'player', name: save?.name || classDef?.name || 'Player', level: Number(save?.level) || 1 });
    this.save = save || {};
    this.classDef = classDef || {};
    this.classIndex = Number(this.classDef.index ?? this.save.classIndex ?? 0);
    this.radius = 0.4;                                        // humanoid body radius (combat reach, picking)
    this.height = Number(this.classDef.bindHeight) > 0 ? Number(this.classDef.bindHeight) : 1.9;
    this.scale = Number(this.classDef.scale) > 0 ? Number(this.classDef.scale) : 1;
    const l1 = this.classDef.level1 || {};
    this.maxHp = this.hp = Number(l1.hp) > 0 ? Number(l1.hp) : 100;   // game.refreshPlayerStats() overwrites these
    this.maxMp = this.mp = Number(l1.mp) > 0 ? Number(l1.mp) : 20;
    this.stance = 'peace';
    this.weapon = null;                                       // { def, main: StaticModel|null, second: StaticModel|null }
    this._weaponObjs = [];                                    // [{ obj, hand: 'main'|'second' }]
    this._moveStance = null;
    this._idleT = 0;
    this._fidgetAt = FIDGET_MIN + Math.random() * (FIDGET_MAX - FIDGET_MIN);
    this._skillStyles = skillStyleMap(this.classDef);
  }

  get anims() { return this.classDef?.anims || {}; }

  _ringColor() { return 0x9cff7a; }

  // ---------------------------------------------------------------------------------------- appearance
  /** Skinned parts: the class defaults, replaced per slot by save.equipment[slot] when it names a mesh. */
  partDefs() {
    const eq = this.save?.equipment || {};
    // A costume covering several parts (items.json costypeParts 11111) is ONE mesh that the equipment view names in
    // every covered part: draw it once (remote players have no mounts-system CostumeLook wrapper to do this).
    const costumes = new Set();
    return (this.classDef?.parts || []).map(p => {
      const e = eq[p.slot];
      const src = e && e.mesh ? e : p;
      if (e?.costume && e.mesh) { const key = String(e.mesh).toLowerCase(); if (costumes.has(key)) return null; costumes.add(key); }
      return { meshKey: src.mesh, tpackKey: src.tpack || null, textures: src.textures || null };
    }).filter(p => p?.meshKey);
  }

  /** Weapon: the class starter weapon, or save.equipment.weapon when it names a mesh (bones default to the class's). */
  weaponDef() {
    const base = this.classDef?.weapon || null;
    const e = this.save?.equipment?.weapon;
    if (e && e.none) return null;   // items system: bare hands (no weapon equipped)
    if (e && e.mesh) return { ...(base || {}), leftMesh: null, ...e };
    return base;
  }

  async _loadVisuals() {
    const models = this.game?.models;
    if (!models || !this.classDef?.skeleton) return null;
    const w = this.weaponDef();
    const same = w && w.leftMesh && w.leftMesh === w.mesh;
    // the second mesh (dual wield, shield, left half of a two-mesh weapon) loads with its own texture pack when given
    const leftOpts = (w?.leftTpack || w?.leftTextures) ? { tpackKey: w.leftTpack || null, textures: w.leftTextures || null }
      : same ? { tpackKey: w.tpack || null, textures: w.textures || null } : {};
    const [model, main, second] = await Promise.all([
      models.loadSkinned({ skelKey: this.classDef.skeleton, parts: this.partDefs() }),
      w?.mesh ? weaponModel(models, w.mesh, { tpackKey: w.tpack || null, textures: w.textures || null }, w.skel, w.anim, w.animTime, w.attachSkel) : null,
      w?.leftMesh ? weaponModel(models, w.leftMesh, leftOpts, w.leftSkel, w.leftAnim, w.leftAnimTime, w.leftAttachSkel) : null,
    ]);
    return { model, weapon: w ? { def: w, main, second } : null };
  }

  async _load() {
    const v = await this._loadVisuals();
    if (this.disposed || !v?.model) return;
    this._install(v);
    await this._preloadAnims();
  }

  _install({ model, weapon }) {
    this._setSkinned(model);
    if (model.height > 0) this.height = model.height;
    this.weapon = weapon;
    this._weaponObjs = [];
    this._placeWeapons();
    this._visualAnims = JSON.stringify(this.anims);
    this._installedEquipment = structuredClone(this._equipmentPreview?.equipment || this.save?.equipment || {});
    this._equipmentVisualRevision = (this._equipmentVisualRevision || 0) + 1;
  }

  /** 2u: every idle / locomotion / attack / hit / death clip of the CURRENT weapon style (this.anims = the styled
   *  class), resolved for `model` before anything plays them. */
  async _preloadAnims(model = this.model, A = this.anims) {
    this._warmAttackEffects(A);
    const list = [A.idlePeace, A.idle, A.runPeace, A.run, A.walkPeace, A.walk, A.swimIdle, A.swimIdleCombat, A.swimWalk, A.swimRun, A.die, A.dieAlt, A.idlePeaceAlt, A.idleAlt,
      A.revive, ...(A.attack || []), ...(A.hit || [])];
    await Promise.all(list.filter(e => e?.anim).map(e =>
      clipEntry(this.game?.models, model, normKey(e.anim), e.timeLength > 0 ? e.timeLength : null).promise));
  }

  /**
   * Rebuild the body after an equipment change (save.equipment). Keeps position, state, highlight and opacity.
   * 2u: the new body's clips are resolved BEFORE the swap, so the old body keeps animating meanwhile and the new one
   * starts on its clip in the same frame (never a bind-pose frame, never a clip that is still loading).
   * @returns {Promise<boolean>}
   */
  async refreshAppearance() {
    const generation = this._appearanceGeneration = (this._appearanceGeneration || 0) + 1;
    // Capture the exact authored candidate before asynchronous asset work. A
    // later canonical equip must not mix its style with this candidate's body.
    const candidate = Object.create(this);
    candidate.classDef = this.classDef;
    candidate.save = { ...this.save, equipment: structuredClone(this._equipmentPreview?.equipment || this.save?.equipment || {}) };
    const v = await candidate._loadVisuals();
    if (this.disposed || generation !== this._appearanceGeneration || !v?.model) return false;
    await this._preloadAnims(v.model, candidate.anims);
    if (this.disposed || generation !== this._appearanceGeneration) return false;
    const keepT = Number(this.animator?.current?.time) || 0;     // a loop continues in phase (no stride restart)
    // Ordinary equipment changes keep the existing live skeleton and mixer.
    // Unchanged armor, wings and the other hand retain their objects and clocks.
    if (this.instance?.replaceParts?.(v.model)) {
      const changeClip = this._visualAnims !== JSON.stringify(candidate.anims) || !!this.weapon?.main !== !!v.weapon?.main;
      this.model = v.model;
      if (v.model.height > 0) this.height = v.model.height;
      this._replaceWeapons(v.weapon);
      this._installedEquipment = candidate.save.equipment;
      this._equipmentVisualRevision = (this._equipmentVisualRevision || 0) + 1;
      this._visualAnims = JSON.stringify(candidate.anims);
      if (changeClip && LOOP_STATES.has(this.state)) {
        this.stateOpts = { ...(this.stateOpts || {}), startAt: keepT };
        this.play(this.state || 'idle', { ...this.stateOpts, onEnd: null, noEffect: true });
        this.animator?.update(0);
      }
      return true;
    }
    // Keep the old body on screen until the new instance has its first pose.
    // Disposing it before _install/play creates an empty (or bind-pose) frame
    // during every equipment change, visible as a full-model flash.
    const oldAnimator = this.animator, oldInstance = this.instance;
    this.animator = null; this.instance = null; this.clip = null;
    this._install(v);
    this._installedEquipment = candidate.save.equipment;
    if (keepT > 0 && LOOP_STATES.has(this.state)) this.stateOpts = { ...(this.stateOpts || {}), startAt: keepT };
    if (this.highlighted) this.setHighlight(true);
    if (this.opacity < 1) this.setOpacity(this.opacity);
    this.play(this.state || 'idle', { ...(this.stateOpts || {}), onEnd: null, noEffect: true });   // same swing on the new body: its effect already runs
    try { this.animator?.update(0); } catch { /* pose now, not on the next frame */ }
    try { oldAnimator?.dispose(); } catch { /* ignore */ }
    try { oldInstance?.dispose(); } catch { /* ignore */ }
    return true;
  }

  // ---------------------------------------------------------------------------------------- weapon / stance
  _replaceWeapons(weapon) {
    const old = this.weapon;
    const kept = [];
    for (const entry of this._weaponObjs) {
      if (weapon?.[entry.hand] && weaponVisualKey(old?.def, entry.hand) === weaponVisualKey(weapon.def, entry.hand)) kept.push(entry);
      else {
        this.instance.detach(entry.obj);
        entry.obj.removeFromParent();
        entry.obj.userData.weaponAnimator?.dispose();
        entry.obj.userData.instance?.dispose();
      }
    }
    this.weapon = weapon;
    this._weaponObjs = kept;
    this._placeWeapons();
  }

  /** Keep on-foot weapons in hand; riding uses authored holster bones only. */
  _placeWeapons() {
    const inst = this.instance, w = this.weapon;
    if (!inst || !w) return;
    {
      for (const [hand, m] of [['main', w.main], ['second', w.second]]) {
        if (!m || this._weaponObjs.some(entry => entry.hand === hand)) continue;
        const obj = m.instantiate();
        obj.name = `weapon:${hand}`;
        obj.traverse(o => { if (o.isMesh) { o.castShadow = true; o.receiveShadow = false; } });
        this._weaponObjs.push({ obj, hand });
      }
    }
    const d = w.def || {};
    // On foot hand attachments are required in every stance. Riding uses
    // the native holster mapping; an absent mapping hides rather than invents a grip.
    const peace = !!(this.game.mounts?.system?.riding?.active && this.game.mounts.system.riding.player === this);
    for (const e of this._weaponObjs) {
      const authoredBone = e.hand === 'main'
        ? (peace ? d.bonePeace : d.bone)
        : (peace ? d.bonePeaceLeft : d.boneLeft);
      // Presentation correction: these two native mappings are
      // floating rigs. Use their own class's existing palm helpers on foot;
      // keep authored animation/timing, item transforms and riding holsters.
      const grip = !peace && e.hand === 'main'
        ? this.classIndex === 13 && authoredBone === 'SIS_01' ? 'weaponR1'
          : this.classIndex === 14 && authoredBone === 'weapon_C02' ? 'weaponL2' : null
        : null;
      const bone = grip && inst.getBone(grip) ? grip : authoredBone;
      const b = bone ? inst.getBone(bone) : null;
      if (!b) { e.obj.visible = false; continue; }
      e.obj.visible = true;
      if (e.obj.parent !== b) inst.attach(e.obj, bone);
    }
  }

  /** Record the clip's 'peace' | 'battle' style while retaining hand attachments. */
  setStance(stance) {
    stance = stance === 'battle' ? 'battle' : 'peace';
    if (stance === this.stance && this._weaponObjs.every(e => e.obj.parent)) return;
    this.stance = stance;
    this._placeWeapons();
  }

  _onClipStart(spec) {
    if (spec.style === 0) this.setStance('peace');
    else if (spec.style != null && Number.isFinite(Number(spec.style))) this.setStance('battle');
  }

  /** Armed locomotion while equipped; unarmed combat uses the recent-combat / living-target rule. */
  inBattle() {
    // with a weapon equipped, keep the weapon-holding (battle-style) idle/run so the grip matches the weapon in hand
    if (this.weapon?.main) return true;
    const now = this.game?.time ?? 0;
    if (this.lastCombat != null && now - this.lastCombat < STANCE_SECONDS) return true;
    const t = this.target;
    return !!(t && !t.dead && !t.disposed && t.kind === 'monster');
  }

  // ---------------------------------------------------------------------------------------- movement speed
  /** anims key of the walk/run clip for a stance ('run' | 'runPeace' | 'walk' | 'walkPeace'), or null. */
  locomotionKey(state = 'run', battle = this.inBattle()) {
    const A = this.anims;
    if (this.isSwimming()) {
      const swim = state === 'walk' ? 'swimWalk' : 'swimRun';
      if (A[swim]) return swim;
    }
    const pk = `${state}Peace`;
    const k = battle ? (A[state] ? state : pk) : (A[pk] ? pk : state);
    return A[k] ? k : null;
  }

  isSwimming() { return isUnderwaterMap(this.game?.world?.info?.row); }

  /**
   * Real ground speed (units = cells = m per second) for walking or running, as the original derives it:
   * the locomotion clip's root-motion stride per cycle / its action-table TimeLength (classes.json
   * stats.speedFromRootMotion; e.g. Azure Knight run 3.4454 / 1.0 s = 3.445 u/s, Dragon Knight 3.991 / 0.933 s
   * = 4.278 u/s), for the clip of the current stance, times the speed buffs (stats.moveSpeedMul) and the map's
   * maplist MoveSpeedFactor (0.8 under water). Moving at this speed keeps the feet planted.
   */
  groundSpeed(state = 'run', battle = this.inBattle()) {
    // Shared run stride comes from the authoritative host, including buffs and caps.
    // Do not multiply local buff/map/stance values into this already resolved speed.
    const network=this.game?.network,shared=network?.ready&&network?.self;
    const speed=Number(shared?.moveSpeed);
    if(this===this.game?.player&&!this.remote&&state==='run'&&network?.active&&Number.isFinite(speed)&&speed>0)return speed;
    // Online walk (R): the host's run speed x the class walk/run stride ratio, exactly what the host moves at.
    if(this===this.game?.player&&!this.remote&&state==='walk'&&network?.active&&Number.isFinite(speed)&&speed>0)return speed*walkSpeedRatio(this.classDef,!battle);
    const k = this.locomotionKey(state, battle);
    const sfr = this.classDef?.stats?.speedFromRootMotion || {};
    let base = k && sfr[k] > 0 ? Number(sfr[k]) : 0;
    if (!(base > 0) && k) {
      const a = this.anims[k];
      const rm = Array.isArray(a?.rootMotion) ? Math.hypot(a.rootMotion[0] || 0, a.rootMotion[2] || 0) : 0;
      if (rm > 0.05 && a.timeLength > 0) base = rm / a.timeLength;
    }
    if (!(base > 0)) base = state === 'walk' ? 1.851 : 3.445;
    return base * (Number(this.scale) > 0 ? Number(this.scale) : 1) * this.moveSpeedMul();
  }

  /** Speed multiplier from buffs/debuffs (progression stats.moveSpeedMul) and the map's MoveSpeedFactor. */
  moveSpeedMul() {
    const buff = Number(this.stats?.moveSpeedMul);
    const map = Number(this.game?.world?.info?.row?.MoveSpeedFactor);
    return (buff > 0 ? buff : 1) * (map > 0 ? map : 1);
  }

  /** Actor LOCOMOTION SYNC start rate (2u): the speed the controller will move at for this loop. */
  _nominalSpeed(state) { return this.groundSpeed(state === 'walk' ? 'walk' : 'run'); }

  _styleForAnim(anim) {
    const s = this._skillStyles.get(normKey(anim));
    return s != null ? s : Number(this.classDef?.style ?? 1);
  }

  // ---------------------------------------------------------------------------------------- animation
  play(state, opts = {}) {
    if (!opts?.noEffect) this._cutAttackEffects();   // any new clip (a swing restarting included) first removes the effect of a swing it cuts short
    const result = super.play(state, opts);
    if (state === 'attack' && !opts?.noEffect) this._attackEffect(opts);
    return result;
  }
  /**
   * 2.2.1: a normal attack plays its ATTACK record's action Effect, as skill steps already do (skill-playback.js actionEffect):
   * the record's Effect id -> modeleffect.csv 25/0 -> skills common modelEffects.pcActionEffects (tools/build-skills.mjs).
   * In the data only four classes have one: Segnale 821-824 (the blood whip lash, scene 100:3094), Segita Shooter 2438,
   * Alokes 3208-3218, Trie Muse 2802; every other class's swing has no Effect. Local and remote players both come here.
   */
  _attackEffect(opts) {
    // A body that is not built yet keeps the call in Actor._pendingPlay, which replays play() when the body is ready: the effect
    // starts then (once), never twice. A disposed / dead actor swings nothing.
    if (this.disposed || this.dead || !this.animator) return;
    const L = this.anims?.attack || [];
    if (!L.length) return;
    const entry = L[((Number(opts?.variant) | 0) % L.length + L.length) % L.length];
    const fx = this.game?.effects, ref = entry?.effect != null ? fx?.data?.modelEffects?.pcActionEffects?.[entry.effect] : null;
    if (!ref?.id || typeof fx?.play !== 'function') return;
    const seconds = Number(opts?.timeLength) > 0 ? Number(opts.timeLength) : Number(entry.timeLength) || 1;
    const live = this._attackFx || (this._attackFx = new Set());
    try {
      let handle = null;
      handle = fx.play(this, { cate: ref.cate, id: ref.id, scene: ref.scene, timeMs: ref.timeMs || seconds * 1000, loop: false },
        { loop: false, onEnd: () => live.delete(handle) });
      if (handle) live.add(handle);
    } catch (error) { console.warn('[player] attack effect failed', error); }
  }
  /**
   * ENGINE-CHOSEN (the data has no cancel rule): a swing cut short by another clip (move order, hit reaction, a skill, death)
   * removes its action effect at once, as the skill system does for a cancelled cast (skills/engine.js a.handles). A swing that
   * played to its end (animator progress >= SWING_DONE) lets the effect finish: its data timeMs equals the clip TimeLength.
   */
  _cutAttackEffects() {
    const live = this._attackFx;
    if (!live?.size || this.state !== 'attack') return;
    const a = this.animator;
    if (a && (a.finished || a.progress >= SWING_DONE)) return;
    for (const handle of [...live]) { try { handle.stop?.(true); } catch { /* ignore */ } }
    live.clear();
  }
  /** Warm the lazy effect library (data.js scene() starts the one-time skills_effects.json fetch on a miss) so the first swing shows its effect. */
  _warmAttackEffects(A = this.anims) {
    const fx = this.game?.effects, table = fx?.data?.modelEffects?.pcActionEffects;
    if (!table || typeof fx?.data?.scene !== 'function') return;
    for (const entry of A?.attack || []) {
      const ref = entry?.effect != null ? table[entry.effect] : null;
      if (ref?.id) { try { fx.data.scene(`${Number(ref.cate ?? 100)}:${Number(ref.id)}`); } catch { /* ignore */ } }
    }
  }
  _specFor(state, opts) {
    const A = this.anims;
    const e = (entry, extra) => (entry && entry.anim ? {
      key: entry.anim, duration: entry.timeLength > 0 ? entry.timeLength : null, style: entry.style,
      fade: interFade(entry.startInter), split: entry.split || 0, timing: entry.timing || 0, ...extra,
    } : null);
    const v = opts?.variant;
    switch (state) {
      case 'idle': return e((this.isSwimming() && A.swimIdle) || A.idlePeace, { loop: true });
      case 'idleCombat': return e((this.isSwimming() && (A.swimIdleCombat || A.swimIdle)) || A.idle, { loop: true });
      case 'run': case 'walk': {
        const battle = this.inBattle();
        const k = this.locomotionKey(state, battle);
        if (!k) return null;
        this._moveStance = battle ? 'battle' : 'peace';
        // the playback rate follows the ground speed (Actor LOCOMOTION SYNC); groundSpeed() moves the player at
        // exactly this clip's root-motion stride / TimeLength (x buffs), so it plays at rate 1 unbuffed
        return e(A[k], { loop: true });
      }
      case 'attack': {
        const L = A.attack || [];
        if (!L.length) return null;
        const k = ((Number(v) | 0) % L.length + L.length) % L.length;
        return e(L[k], { loop: false });
      }
      case 'hit': {
        const L = A.hit || [];
        return e(L[Number(v) | 0] || L[0], { loop: false });
      }
      case 'die': return e(A.die, { loop: false });
      case 'skill': case 'cast': return null;    // opts.anim is handled by Actor._candidates; else falls back to attack
      case 'emote': {
        const L = A.emotes || [];
        const hit = typeof v === 'string' ? L.find(x => x.name === v) : L.find(x => x.index === v) || L[Number(v) | 0];
        return e(hit, { loop: false, style: 0 });
      }
      default: {
        const x = A[state];
        if (!x || Array.isArray(x)) return Array.isArray(x) ? e(x[Number(v) | 0] || x[0], { loop: LOOP_STATES.has(state) }) : null;
        return e(x, { loop: LOOP_STATES.has(state) });
      }
    }
  }

  _restState() {
    if (this.dead) return null;
    if (LOOP_STATES.has(this.state)) return this.state;
    return this.inBattle() ? 'idleCombat' : 'idle';
  }

  update(dt) {
    super.update(dt);
    // animated weapons (legend meshes with their own skeleton) loop their clip
    for (const e of this._weaponObjs) e.obj.userData.weaponAnimator?.update(dt);
    if (this.disposed || !this.animator || this.dead) { this._idleT = 0; return; }
    const st = this.state;
    // combat started / ended mid-run: switch between the peace and battle locomotion clips (same gait, so the stride continues
    // at the phase it was in instead of restarting from the top)
    if ((st === 'run' || st === 'walk') && this._moveStance) {
      const want = this.inBattle() ? 'battle' : 'peace';
      if (want !== this._moveStance) this.play(st, { ...(this.stateOpts || {}), moveSpeed: this.groundSpeed(st, want === 'battle'), startAt: 0, startPhase: this._locoGround > 0 ? this.animator.progress : 0 });
    }
    // standing still for a while: play the stand variant once ("looking around"), then back to the loop
    if ((st === 'idle' || st === 'idleCombat') && this._clipLoop) {
      this._idleT += dt > 0 ? dt : 0;
      if (this._idleT >= this._fidgetAt) {
        this._idleT = 0;
        this._fidgetAt = FIDGET_MIN + Math.random() * (FIDGET_MAX - FIDGET_MIN);
        const alt = st === 'idle' ? this.anims.idlePeaceAlt : this.anims.idleAlt;
        if (alt?.anim) {
          const spec = { key: normKey(alt.anim), duration: alt.timeLength > 0 ? alt.timeLength : null, style: alt.style,
            fade: interFade(alt.startInter), loop: false, state: st };
          this._tryCandidates([spec], 0, {}, ++this._playSeq);
        }
      }
    } else if (st !== 'idle' && st !== 'idleCombat') this._idleT = 0;
  }

  dispose() {
    for (const handle of this._attackFx || []) { try { handle.stop?.(true); } catch { /* ignore */ } }
    this._attackFx?.clear();
    this._weaponObjs = [];
    super.dispose();
  }
}
