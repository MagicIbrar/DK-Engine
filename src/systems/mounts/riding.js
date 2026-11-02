// Riding: summon / dismiss the equipped mount (equipment slot 20), the mount model with its own action table, the
// rider on the mount's 'ride' bone playing the rider pose table, mounted movement speed, the riding restrictions and
// the rider's name-tag height (docs/MOUNTS.md).
//
// Data (gamedata/mounts.json, tools/build-mounts.mjs):
//   vehicles[item]           {bone ('ride'), fs FootStyle, act (vehicleActions key), all|byClass mesh, o (options while
//                            riding: SPEED_MOVE_MUL 43 = the movement speed bonus %), xo (options while equipped), csv}
//   vehicleActions[act]      the mount's skeleton + rows [style, action, index, anim, timeLength]:
//                            STAND 1 / MOVE 2 (index 0 walk, 1 run) / DEFEAT 7 / BLOCKING-BLOCKED-GUARDING 12-14 /
//                            SM_STAND 26 / SM_MOVE 28 (swimming mounts)
//   riderActions[code + fs]  the character's mounted poses (same actions), e.g. 'swd3' = Azure Knight on a FootStyle-3 mount
//
// Frames (ARCHITECTURE.md §1): the mount's root is a child of player.group (FILE frame under worldRoot, faces local -Z
// like every model). Every frame, after the mount animator ran, the rider's skinned root (player.instance.root) is
// placed on the mount's ride bone expressed in player.group space.
//
// Speed: mounted run speed = the character's own run speed (root-motion stride / TimeLength, Player.groundSpeed, with
// buffs and the map's MoveSpeedFactor) x (1 + the mount's SPEED_MOVE_MUL / 100) - the item text "increases the
// character's movement speed by X%". The mount's MOVE clip plays at (measured speed) / (its root-motion speed) so its
// feet stay planted; the local rider uses nominal controller speed and remote riders use measured speed. MOVE clips
// without root motion play at ActionSpeedMul % (vehicle.csv) scaled by the speed ratio.
// The rider's clip follows the mount clip's phase.
import * as THREE from 'three';
import { Animator } from '../../engine/animator.js';
import { clipGroundSpeed, clipEntry } from '../../actors/actor.js';
import { ACT, EQUIP_SLOT } from './data.js';
import { prewarmFirstPersonRiding, firstPersonLookSignature, transientLook } from '../../engine/native-first-person-presentation.js';
import { applyShadeTree } from '../../world/shade.js';
import { nativeMountEffects, nativeVehicleEffect } from './native-effects.js';

const _inv = new THREE.Matrix4();
const _m = new THREE.Matrix4();
const _p = new THREE.Vector3();
const _q = new THREE.Quaternion();
const _s = new THREE.Vector3();
const RATE_MIN = 0.2, RATE_MAX = 4;
const normKey = k => String(k || '').trim().replace(/\\/g, '/').replace(/^\/+/, '').toLowerCase();

/** The item index of an equipment entry (items system instance, plain index, legacy {itemIndex}). */
export function itemIndexOf(e) {
  if (e == null) return null;
  if (typeof e === 'number') return e;
  const v = e.index ?? e.itemIndex ?? e.item?.index ?? e.id;
  return Number.isFinite(Number(v)) ? Number(v) : null;
}

/** Equipped item of an equipment slot id (save.equip of the items system, save.equipment fallbacks). */
export function equippedItem(game, slotId, key) {
  const s = game?.save;
  if (!s) return null;
  let e = null;
  // items system: save.equip = {active, presets: [{slotId: uid}], items: {uid: inst}} (src/systems/items/equip.js)
  const E = s.equip;
  if (E && E.presets) {
    const uid = E.presets[E.active || 0]?.[slotId];
    e = uid ? E.items?.[uid] || null : null;
  } else if (E && E[slotId] != null) e = E[slotId];
  if (e == null && !(E && E.presets)) e = s.equipment?.[key] ?? s.equipment?.[slotId] ?? null;
  const idx = itemIndexOf(e);
  return idx != null ? { index: idx, inst: typeof e === 'object' ? e : null } : null;
}

export class Riding {
  constructor(sys) {
    this.sys = sys;
    this.game = sys.game;
    this.data = sys.data;
    this.state = 'off';          // off | summoning | on | dismounting
    this.item = null;            // item index of the ridden mount
    this.rig = null;             // { root, model, inst, animator, bone, table, rider, clips }
    this._loading = null;
    this._vstate = null;
    this._riderPlayed = null;
    this._orig = null;           // original player methods (restored on dismount)
  }

  get active() { return this.state === 'on' && !!this.rig; }
  get player() { return this.game.player; }

  /** The equipped mount item (index) or null. */
  equipped() {
    const e = equippedItem(this.game, EQUIP_SLOT.vehicle, 'vehicle');
    return e && this.data.isVehicle(e.index) ? e : (this.sys.testVehicle ? { index: this.sys.testVehicle, inst: null } : null);
  }

  mapAllows(row = this.game.world?.info?.row) {
    if (!row) return true;
    const v = String(row.IsVehicle ?? '1').trim();
    return v === '' || Number(v) !== 0;
  }
  /** Underwater map (maplist MoveSpeedFactor < 1): only mounts with swimming rows (SM_STAND / SM_MOVE) can be used. */
  underwater(row = this.game.world?.info?.row) {
    const f = Number(row?.MoveSpeedFactor);
    return f > 0 && f < 1;
  }
  canSwim(item) { return !!this.data.vehicleTable(item)?.rows?.some(r => r[1] === ACT.SM_MOVE); }

  // ------------------------------------------------------------------ summon / dismiss
  /** Mount the equipped mount (with the original checks and casting bar). Resolves true when riding. */
  async mount() {
    const g = this.game, p = this.player, sys = this.sys;
    if (!p || p.dead) return false;
    if (this.state === 'on') { sys.say('already'); return false; }
    if (this.state !== 'off') return false;
    const eq = this.equipped();
    if (!eq) { sys.say('noMount'); return false; }
    if (!this.mapAllows()) { sys.say('noArea'); return false; }
    if (this.underwater() && !this.canSwim(eq.index)) { sys.say('ground'); return false; }
    if (g.skills?.busy) { sys.say('skillBusy'); return false; }
    if (sys.isFishing()) { sys.say('fishing'); return false; }
    if (sys.isTransformed()) { sys.say('transform'); return false; }
    if ((p.moveVelocity || 0) > 0.3 || g.controller?.order?.type === 'move') { sys.say('moving'); return false; }
    if (sys.pet?.busy) { sys.say('busy'); return false; }
    const { start } = this.data.vehicleDelays(eq.index);
    this.state = 'summoning';
    const warm = this._takeWarm(eq.index);
    const load = warm ? Promise.resolve(warm) : this._build(eq.index);   // the pre-loaded rig, else load the model while the bar runs
    g.controller?.stop?.();
    const ok = await sys.castDelay(sys.text('summoning'), start);
    if (!ok) { this.state = 'off'; void load.then(rig => this._disposeRig(rig)); sys.say('canceled'); return false; }
    const rig = await load;
    if (!rig || this.state !== 'summoning' || p.dead || p !== this.player) { this._disposeRig(rig); this.state = 'off'; return false; }
    this._attach(eq.index, rig);
    return true;
  }

  /** Dismount (casting bar of EndDelay ms when it is long enough to show). */
  async dismount({ instant = false } = {}) {
    if (this.state !== 'on') return false;
    const { end } = this.data.vehicleDelays(this.item);
    if (!instant && end >= 100) {
      this.state = 'dismounting';
      const ok = await this.sys.castDelay(this.sys.text('deactivating'), end);
      if (!ok) { if (this.state === 'dismounting') this.state = 'on'; return false; }
    }
    this._detach();
    return true;
  }

  toggle() { return this.state === 'on' ? this.dismount() : this.mount(); }

  // ------------------------------------------------------------------ model
  async _build(item) {
    const g = this.game, p = this.player;
    const classIndex = Number(p?.classIndex ?? g.save?.classIndex ?? 0);
    const look = this.data.vehicleLook(item, classIndex);
    const table = this.data.vehicleTable(item);
    const rider = this.data.riderTable(item, classIndex);
    if (!look?.mesh || !table?.skel) { console.warn('[mounts] mount without model/table', item); return null; }
    const model = await g.models.loadSkinned({ skelKey: table.skel, parts: [{ meshKey: look.mesh, tpackKey: look.tpack || null, textures: look.textures || null }] });
    if (!model) return null;
    const inst = model.instantiate();
    inst.root.name = `mount:${item}`;
    inst.root.traverse(o => { if (o.isMesh) { o.castShadow = true; o.receiveShadow = false; } });
    const v = this.data.vehicle(item);
    const rig = { item, model, inst, root: inst.root, animator: new Animator(inst), bone: inst.getBone(v?.bone || 'ride'), table, rider, clips: new Map(), riderClips: new Map() };
    rig.effects = nativeMountEffects(g);
    rig.effectOwner = Object.create(p);
    Object.defineProperties(rig.effectOwner, {
      instance: { value: inst }, group: { value: p.group }, model: { value: model },
      scale: { value: 1 }, height: { value: Math.max(.3, model.bbox?.max?.y || 1) },
      disposed: { get: () => !!rig.disposed || !!p.disposed },
    });
    rig.actionEffectToken = {};
    try { rig.effectSource = await rig.effects.vehicleSource(item, table, look, classIndex, v?.act); }
    catch (error) { rig.effects.warn(`vehicle-source:${item}`, error); }
    if (!rig.bone) console.warn('[mounts] mount has no ride bone', v?.bone, table.skel);
    // preload the loops of the mount and of the rider (so the first steps do not show the standing pose)
    await Promise.all([ACT.STAND, ACT.MOVE].flatMap(a => [0, 1].flatMap(i => [this._clip(rig, 'v', a, i).promise, this._clip(rig, 'r', a, i).promise])));
    return rig;
  }

  /** Load (cached) a clip of the mount ('v') or the rider ('r') for (action, index). Resolves {clip, row}. */
  _clip(rig, who, action, index = 0, style = 0) {
    const cache = who === 'v' ? rig.clips : rig.riderClips;
    const k = `${action}:${index}:${style}`;
    if (cache.has(k)) return cache.get(k);
    const table = who === 'v' ? rig.table : rig.rider;
    const row = this.data.row(table, action, index, style);
    const e = { done: false, clip: null, row };
    const model = who === 'v' ? rig.model : this.player?.model;
    e.promise = row && model ? this.game.models.loadClipWithStatus(normKey(row.anim), model, { duration: row.timeLength })
      .then(c => { e.clip = c || null; e.done = true; return e; })
      .catch(err => {
        // Evict outer mount/rider entry on transient so a later play can retry.
        if (err?.transient) cache.delete(k);
        e.clip = null; e.done = true; return e;
      }) : Promise.resolve((e.done = true, e));
    cache.set(k, e);
    return e;
  }

  _attach(item, rig) {
    const p = this.player;
    this.item = item;
    this.rig = rig;
    const sc = Number(p.scale) > 0 ? Number(p.scale) : 1;
    rig.root.scale.setScalar(1 / sc);         // mounts are not scaled by the class scale
    p.group.add(rig.root);
    rig.effects?.bind(rig, rig.effectOwner, 'vehicle', rig.effectSource?.shape);
    this._hookPlayer(p);
    this.state = 'on';
    p._placeWeapons?.();
    this._vstate = null;
    this._riderPlayed = null;
    p.play(p.state === 'run' || p.state === 'walk' ? p.state : 'idle', { loop: true });
    this.update(0);
    this.sys.setMenuChecked('btn_vehicle', true);
    this.game.events?.emit('mount', { on: true, item });
    this.sys.onStatsChanged();
  }

  _detach() {
    const p = this.player;
    const item = this.item;
    this._unhookPlayer(p);
    this._disposeRig(this.rig);
    this.rig = null;
    this.item = null;
    this.state = 'off';
    p?._placeWeapons?.();
    if (p && !p.dead) p.play(p.state === 'run' || p.state === 'walk' ? p.state : 'idle', { loop: true });
    this.sys.setMenuChecked('btn_vehicle', false);
    this.game.events?.emit('mount', { on: false, item });
    this.sys.onStatsChanged();
  }

  _disposeRig(rig) {
    if (!rig) return;
    rig.disposed = true;
    rig.effects?.stop(rig); rig.effects?.stop(rig.actionEffectToken);
    try { rig.animator?.dispose(); } catch { /* ignore */ }
    try { rig.inst?.dispose(); } catch { /* ignore */ }
    rig.root?.removeFromParent();
  }

  // A spike when summoning a mount in first person. Measured with the test client (frame timing + profiler): one
  // 418 ms frame + 200 / 142 ms frames on the FIRST summon only, most of it getProgramInfoLog = the driver building the mount's
  // shaders on its first draw, plus the model load. The equipped mount is loaded, compiled AND drawn once (colour / depth
  // locked, warm-draw.js) during the map load (prewarmNow, from game.js _warmUp, under the loading screen: ANGLE builds the
  // D3D11 shaders on the first draw); while playing on foot it is re-warmed when the look changes; the next summon uses
  // that same rig.
  _maybePrewarm(dt) {
    // the local rider only: other players' riders are Riding instances too (network/mounts.js actorMount, on a game facade)
    if (this.game.mounts?.system?.riding !== this) return;
    this._warmCheck = (this._warmCheck || 0) - dt;
    if (this._warmCheck > 0) return;
    this._warmCheck = 1;   // once a second
    // drawn too when the look settles after the load / changes, but never during a Trans Up (a transient body; see
    // native-first-person-presentation.js transientLook)
    if (!this.game._loadingMap) void this._prewarm({ draw: !transientLook(this.player) });
  }
  /** Map load: pre-load, compile with this map's lights and draw once. Resolves when done (false: nothing to warm). */
  prewarmNow() {
    if (this.game.mounts?.system?.riding !== this || this.state !== 'off') return Promise.resolve(false);
    return this._prewarm({ draw: true, force: true });
  }
  _prewarm({ draw = false, force = false } = {}) {
    const p = this.player, item = this.equipped()?.index ?? null;
    if (this._warm && (this._warm.item !== item || this._warm.player !== p)) { this._disposeRig(this._warm.rig); this._warm = null; }
    if (item == null || !p || p.dead || p.disposed || this.state !== 'off') return Promise.resolve(false);
    // a map load waits for a running pre-load, then warms again with this map's lights; the idle check just skips
    if (this._warming) return force ? this._warming.then(() => this._prewarm({ draw, force })) : this._warming;
    const g = this.game, warm = this._warm, look = firstPersonLookSignature(p);
    let job;
    if (warm) {
      // the look changed since (refine shells arrive after the gear, another weapon), or a new map (its lights): again
      if (!force && look === warm.look) return Promise.resolve(true);
      job = this._compileRig(warm.rig).then(() => prewarmFirstPersonRiding(g, warm.rig.root, { draw })).then(ok => { if (ok) warm.look = look; return ok; });
    } else {
      job = this._build(item).then(async rig => {
        if (!rig) return false;
        if (this._disposed || this.state !== 'off' || this.equipped()?.index !== item || this.player !== p) { this._disposeRig(rig); return false; }
        // the world's sun fall-off patch first (world.js gives it to everything under the world root every 0.5 s, shade.js):
        // without it the pre-built programs were not the ones the attached mount draws with (seen in a test-client mount-summon run: |dkshade2)
        applyShadeTree(rig.root);
        await this._compileRig(rig);
        // plus the first-person riding variants of the mount and weapons (and with `draw` one warm draw of both looks)
        const riding = await prewarmFirstPersonRiding(g, rig.root, { draw });
        if (this._disposed || this.equipped()?.index !== item || this.player !== p || this._warm) { this._disposeRig(rig); return false; }
        this._warm = { item, rig, player: p, look: riding ? look : null };
        return true;
      });
    }
    const running = this._warming = job.catch(error => { console.warn('[mounts] mount pre-load failed', error); return false; })
      .finally(() => { if (this._warming === running) this._warming = null; });
    return running;
  }
  _compileRig(rig) {
    const g = this.game;
    return typeof g.renderer?.compileAsync === 'function' && g.scene && g.camera ? g.renderer.compileAsync(rig.root, g.camera, g.scene) : Promise.resolve();
  }
  _takeWarm(item) {
    const warm = this._warm;
    if (!warm) return null;
    this._warm = null;
    if (warm.item === item && warm.player === this.player) return warm.rig;
    this._disposeRig(warm.rig); return null;
  }

  // ------------------------------------------------------------------ player hooks
  // Installed once per Player (instance-level wrappers that chain to whatever was there, so other systems' own
  // wrappers keep working); they only change anything while riding.
  ensureHooks(p) {
    if (!p || p.__mountsRideHooks) return;
    p.__mountsRideHooks = true;
    const self = this;
    const specFor = p._specFor, groundSpeed = p.groundSpeed, head = p.headWorldPosition;
    p._specFor = function (state, opts) {
      if (self.active && this === self.player) return self.riderSpec(state, opts);
      return specFor.call(this, state, opts);
    };
    // mounted: the peace run clip's speed x stats.moveSpeedMul, which holds the mount's SPEED_MOVE_MUL while riding
    // (items system stats / the mounts stat provider)
    p.groundSpeed = function (state = 'run', battle) {
      if (self.active && this === self.player) return groundSpeed.call(this, state, false);
      return groundSpeed.call(this, state, battle);
    };
    p.headWorldPosition = function (out = new THREE.Vector3()) {
      if (!(self.active && this === self.player)) return head.call(this, out);
      out.set(this.x, this.y + self.nameHeight(), -this.z);            // FILE -> THREE
      return out;
    };
  }

  _hookPlayer(p) { this.ensureHooks(p); }

  _unhookPlayer(pl) {
    if (!pl) return;
    pl._fidgetAt = 9 + Math.random() * 7;
    const r = pl.instance?.root;
    if (r) { r.position.set(0, 0, 0); r.quaternion.identity(); r.scale.set(1, 1, 1); }
    pl._locoGround = 0;
    const a = pl.animator?.current;
    if (a) a.timeScale = 1;
  }

  /** Rider pose clip spec for a Player state while mounted (Actor._candidates format). */
  riderSpec(state, opts = {}) {
    const rig = this.rig;
    if (!rig) return null;
    const swim = this.underwater() && this.canSwim(this.item);
    let action, index = 0, loop = true;
    switch (state) {
      case 'idle': case 'idleCombat': case 'sit': case 'guard': case 'block':
        action = swim ? ACT.SM_STAND : ACT.STAND; break;
      case 'run': action = swim ? ACT.SM_MOVE : ACT.MOVE; index = 1; break;
      case 'walk': action = swim ? ACT.SM_MOVE : ACT.MOVE; index = 0; break;
      case 'hit': case 'blocked': case 'knockdown': case 'stun': action = ACT.DEFEAT; loop = false; break;
      default: return null;                    // attack / skill / emote ... fall back to the stand (Actor FALLBACKS)
    }
    const row = this.data.row(rig.rider, action, index, 0) || this.data.row(rig.rider, action === ACT.SM_MOVE ? ACT.MOVE : ACT.STAND, index, 0);
    if (!row) return null;
    return { key: row.anim, duration: row.timeLength, style: 0, fade: 0.15, loop, rider: true };
  }

  /**
   * Height of the rider's name tag above the ground: the seated rider's head (Bip01 Head) + the tag clearance.
   * (script/ridingheightcorrection/emblemheight.csv / charbubbleheight.csv hold the guild emblem and chat bubble
   * placement per mount and class; they are exposed as game.mounts.emblemHeight() / bubbleOffset().)
   */
  nameHeight() {
    const p = this.player;
    const head = p?.instance?.getBone?.('Bip01 Head');
    if (head) {
      head.updateWorldMatrix(true, false);
      _p.setFromMatrixPosition(head.matrixWorld);                     // THREE space
      return _p.y - (p.y || 0) + 0.45;
    }
    const r = p?.instance?.root;
    return (r ? r.position.y : 1) + (p?.height || 1.8) * (Number(p?.scale) || 1);
  }

  // ------------------------------------------------------------------ per frame
  update(dt) {
    const p = this.player, rig = this.rig;
    // Departure effects must finish even after the last mount/pet is removed.
    this.game.nativeMountEffects?.tick(dt);
    if (this.state === 'off') this._maybePrewarm(dt);
    if (!rig || this.state === 'off' || this.state === 'summoning') return;
    if (!p || p.disposed) return;
    if (!rig.root.parent || rig.root.parent !== p.group) p.group.add(rig.root);
    // mount clip from the rider's state
    const st = p.state;
    const swim = this.underwater() && this.canSwim(this.item);
    const moving = st === 'run' || st === 'walk';
    if (moving) this._stationaryRiderXZ = null;
    const want = st === 'hit' || st === 'blocked' ? 'hit' : moving ? (st === 'walk' ? 'walk' : 'run') : 'stand';
    if (want !== this._vstate || swim !== this._vswim) this._playVehicle(want, swim);
    const cur = rig.animator.current;
    // locomotion rate of the mount (planted feet) and of the rider (same phase)
    let rate = 1;
    if (moving && cur) {
      const clip = cur.getClip();
      const ground = clipGroundSpeed(clip);
      // Local movement uses the controller's known speed from the first step, like Player locomotion.
      // Remote actors retain measured speed for interpolation and corrections.
      const v = !p.remote ? p.groundSpeed(st) : (p.moveVelocity || 0);
      if (ground > 0) rate = v > 0.05 ? v / ground : 1;
      else {
        const asm = Number(this.data.vehicle(this.item)?.csv?.asm) > 0 ? Number(this.data.vehicle(this.item).csv.asm) / 100 : 1;
        const nominal = p.groundSpeed('run') || 1;
        rate = asm * (v > 0.05 ? v / nominal : 1);
      }
      rate = Math.max(RATE_MIN, Math.min(RATE_MAX, rate));
      if (Math.abs(cur.timeScale - rate) > 0.005) cur.timeScale = rate;
    }
    rig.animator.update(dt > 0 ? dt : 0);
    // rider: never the class fidget / locomotion sync while mounted; follow the mount's phase on loops
    p._fidgetAt = 1e9;
    p._locoGround = 0;
    const ra = p.animator?.current;
    const riderMoving = p.clipSpec?.rider && (p.clipSpec.state === 'run' || p.clipSpec.state === 'walk');
    if (ra && cur && p._clipLoop && moving && riderMoving) {
      const vd = cur.getClip().duration, rd = ra.getClip().duration;
      if (vd > 0 && rd > 0) {
        ra.timeScale = cur.timeScale * (rd / vd);
        const want = ((cur.time % vd) / vd) * rd;
        if (Math.abs(want - ra.time) > 0.05 * rd) ra.time = want;
      }
    } else if (ra && p._clipLoop && Math.abs(ra.timeScale - 1) > 1e-3 && !moving) ra.timeScale = 1;
    // rider on the ride bone
    const inst = p.instance;
    if (inst && rig.bone) {
      p.group.updateWorldMatrix(true, false);
      rig.root.updateMatrixWorld(true);
      _inv.copy(p.group.matrixWorld).invert();
      _m.multiplyMatrices(_inv, rig.bone.matrixWorld);
      _m.decompose(_p, _q, _s);
      // Some authored mount idle clips translate the ride bone a few pixels.
      // That motion is visual bob, not travel: while the player is stationary
      // keep the rider's local X/Z seat anchor fixed so the character cannot
      // slide across the saddle or phase through its mount.
      if (!moving) {
        if (!this._stationaryRiderXZ) this._stationaryRiderXZ = { x: _p.x, z: _p.z };
        _p.x = this._stationaryRiderXZ.x;
        _p.z = this._stationaryRiderXZ.z;
      }
      inst.root.position.copy(_p);
      inst.root.quaternion.copy(_q);
      inst.root.scale.set(1, 1, 1);
    }
    // opacity follows the rider (death fade, stealth ...)
    const op = p.opacity ?? 1;
    if (rig._op !== op) { rig._op = op; try { rig.inst.setOpacity(op); } catch { /* ignore */ } }
  }

  _playVehicle(want, swim) {
    const rig = this.rig;
    this._vstate = want;
    this._vswim = swim;
    let action = swim ? ACT.SM_STAND : ACT.STAND, index = 0, loop = true;
    if (want === 'run') { action = swim ? ACT.SM_MOVE : ACT.MOVE; index = 1; }
    else if (want === 'walk') { action = swim ? ACT.SM_MOVE : ACT.MOVE; index = 0; }
    else if (want === 'hit') { action = ACT.DEFEAT; loop = false; }
    const e = this._clip(rig, 'v', action, index);
    const go = () => {
      if (this.rig !== rig || this._vstate !== want) return;
      let selected = e, clip = e.clip;
      if (!clip && action !== ACT.STAND) { selected = this._clip(rig, 'v', ACT.STAND, 0); clip = selected.clip; }
      if (!clip) return;
      rig.animator.play(clip, { loop, fade: 0.15, speed: 1 });
      const effect = selected.row?.effect ?? nativeVehicleEffect(rig.effectSource?.native, selected.row);
      rig.effects?.bind(rig.actionEffectToken, rig.effectOwner, 'vehicle', effect === rig.effectSource?.shape ? 0 : effect);
      if (!loop) rig.animator.onFinish(() => { if (this.rig === rig && this._vstate === 'hit') this._vstate = null; });
    };
    if (e.done) go(); else e.promise.then(go);
  }

  /** Dispose everything (system dispose / map rebuild of the player). */
  dispose() {
    this._disposed = true;
    if (this.state !== 'off') this._detach();
    this._disposeRig(this._warm?.rig); this._warm = null;
  }
}
