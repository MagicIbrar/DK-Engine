// Black Wizard orbs keep orbiting whatever the character is doing (it used to stay stuck in place in the loading screen and froze mid-air while the character ran, moving again only in idle).
//
// DATA (measured, tools/test-weapon-orbit.mjs re-derives it from the original files):
//  * skel/character/bwz.skel: the two orbs hang on two dedicated pivots of the CLASS skeleton: BAL_R < BAL_position < Bip01 and
//    BAL_L < BAL_Rotate < Bip01 (script/weapon_bonename.csv: ORB = BAL_L / BAL_R). Their orbit is authored in the class clips, as
//    rotation of the two pivots:  bwz_bal_stand_01 (battle stand): quaternion range 1.84 (a full orbit, 3 s loop);
//    bwz_bal_attack_01: 1.74;  bwz_bal_run_01: 0.12 and bwz_bal_walk_01: 0.06 (the pivots hardly turn: the orbit stops);
//    bwz_com_create_01 (the class-select / create STAND clip): no BAL_* track at all (the orbs rest at the bind pose).
//    The peace clips (bwz_non_*) keep the pivots constant, which hides the orb (docs/ENGINE_NOTES.md; left as authored).
//  * The weapon's OWN clip (att_equ_*_bal_*.anim on its own skeleton) is not the problem: measured in the real client it advances
//    0.88-1.00 clip-seconds per second in idle, 0.94 while running and 0.90 during an emote.
// ENGINE-CHOSEN presentation (the original run / walk / create-pose clips author no orbit; this is not in the data): while the
// character is in battle style (or in the front-end scenes) and the playing clip does not author the orbit itself, the BAL_*
// tracks of the class's own battle stand clip (anims.idle) keep looping on top, on the same clock, so the orbit continues
// from where the stand left it and goes on across run / walk / skill clips and in the select / create scene.
import * as THREE from 'three';

/** Track names of the two orb pivots and the two orb bones (models.js names tracks `${bone}.${property}`). */
export const ORBIT_TRACK = /^BAL_(position|Rotate|R|L)\./i;
/** ENGINE-CHOSEN threshold on the pivot rotation range (max-min of any quaternion component) above which a clip counts as authoring
 *  the orbit. Measured ranges: stand 1.84, attack 1.74 (authored) vs run 0.12, walk 0.06 (not authored). */
export const ORBIT_AUTHORED_RANGE = 0.5;
const PIVOT_ROTATION = /^BAL_position\.quaternion$/i;

/** The orb tracks of a clip. */
export const orbitTracks = clip => (clip?.tracks || []).filter(t => ORBIT_TRACK.test(t.name));

const rangeCache = new WeakMap();
/** Largest per-component range of the BAL_position pivot rotation in a clip (0 when it has no such track). */
export function pivotRotationRange(clip) {
  if (!clip) return 0;
  if (rangeCache.has(clip)) return rangeCache.get(clip);
  let range = 0;
  const t = (clip.tracks || []).find(x => PIVOT_ROTATION.test(x.name));
  if (t?.values?.length) {
    const mn = [Infinity, Infinity, Infinity, Infinity], mx = [-Infinity, -Infinity, -Infinity, -Infinity];
    for (let i = 0; i < t.values.length; i++) { const c = i % 4; if (t.values[i] < mn[c]) mn[c] = t.values[i]; if (t.values[i] > mx[c]) mx[c] = t.values[i]; }
    range = Math.max(...mx.map((m, c) => m - mn[c]));
  }
  rangeCache.set(clip, range);
  return range;
}
/** Does the clip itself orbit the orbs? */
export const authorsOrbit = clip => pivotRotationRange(clip) >= ORBIT_AUTHORED_RANGE;

/** An actor holding a Black Wizard orb: the class skeleton has the pivots and a weapon object hangs on BAL_R / BAL_L. */
export function wieldsOrb(actor) {
  if (!actor?.instance?.getBone || !actor._weaponObjs?.length) return false;
  // (cheap test first: this runs every frame for every player in view)
  if (!actor._weaponObjs.some(e => /^BAL_[LR]$/i.test(e.obj?.parent?.name || ''))) return false;
  return !!(actor.instance.getBone('BAL_position') && actor.instance.getBone('BAL_Rotate'));
}

/** The orbit loop of one actor: a second mixer on the same skeleton playing only the orb tracks of its battle stand clip. */
export class OrbitLayer {
  constructor(actor, standClip) {
    this.actor = actor;
    this.instance = actor.instance;
    this.stand = standClip;
    const clip = new THREE.AnimationClip(`${standClip.name}|orbit`, standClip.duration, orbitTracks(standClip));
    this.duration = clip.duration;
    this.mixer = new THREE.AnimationMixer(actor.instance.root || actor.instance);
    this.action = this.mixer.clipAction(clip);
    this.action.setLoop(THREE.LoopRepeat, Infinity);
    this.action.play();
    this.applied = false;       // the orbit tracks were applied by this layer this frame
    this.driving = false;       // the layer controlled the pivots last frame (run / walk / create pose ...)
    this.handover = false;      // back on the stand clip: the layer keeps the pivots while the animator cross-fades
  }

  /**
   * One frame, AFTER the actor's own animator ran. `force`: the front-end scenes (their stance is 'peace' by construction).
   * Returns true when the orbit tracks were applied this frame.
   */
  tick(dt, { force = false } = {}) {
    const a = this.actor, an = a.animator, main = an?.clip || null, step = dt > 0 ? dt : 0;
    this.applied = false;
    if (!main || a.dead) { this.driving = this.handover = false; return false; }
    const isStand = main.name === this.stand.name;
    if (!authorsOrbit(main)) {
      this.handover = false;
      if (!force && a.stance !== 'battle') { this.driving = false; return false; }   // peace clips hide the orb on purpose (data): as authored
      this.mixer.update(step);
      this.driving = this.applied = true;
      return true;
    }
    // the playing clip authors the orbit itself (battle stand, attack ...)
    if (this.driving && isStand && this.duration > 0) {
      // back from run / walk onto the stand loop: continue the orbit where the layer left it (the stand clip restarts at 0 otherwise)
      // and keep the layer on the pivots until the animator's cross-fade is over (its blend would pull them toward the run pose)
      try { an.current.time = this.action.time; } catch { /* no current action */ }
      this.handover = true;
    }
    this.driving = false;
    if (this.handover && (an._layers?.length || 0) > 1) { this.mixer.update(step); this.applied = true; return true; }
    this.handover = false;
    // stay on the stand's clock, so a later hand-over starts from the right phase
    if (isStand && this.duration > 0) this.action.time = ((an.time % this.duration) + this.duration) % this.duration;
    return false;
  }

  dispose() { try { this.mixer.stopAllAction(); this.mixer.uncacheRoot(this.instance.root || this.instance); } catch { /* ignore */ } }
}

const layers = new WeakMap();    // actor -> { layer, loading, instance, stamp }
/**
 * Drive the orbit layer of an actor (call once per frame after the actor's update). Loads the class stand clip once per body.
 * Duplicate calls in the same frame (same game.time) are ignored.
 */
export function updateOrbit(actor, dt, opts = {}) {
  if (!actor || actor.disposed || !actor.instance || !wieldsOrb(actor)) { const s = layers.get(actor); if (s && s.instance !== actor?.instance) { s.layer?.dispose(); layers.delete(actor); } return false; }
  let s = layers.get(actor);
  if (s && s.instance !== actor.instance) { s.layer?.dispose(); layers.delete(actor); s = null; }
  if (!s) {
    s = { instance: actor.instance, layer: null, loading: true, stamp: null };
    layers.set(actor, s);
    const idle = actor.anims?.idle, models = actor.game?.models, model = actor.model;
    const load = idle?.anim && models?.loadClip && model ? models.loadClip(idle.anim, model, { duration: idle.timeLength > 0 ? idle.timeLength : null }) : Promise.resolve(null);
    Promise.resolve(load).then(clip => {
      if (clip && layers.get(actor) === s && actor.instance === s.instance && orbitTracks(clip).length) s.layer = new OrbitLayer(actor, clip);
    }).catch(() => {}).finally(() => { s.loading = false; });
    return false;
  }
  if (!s.layer) return false;
  const stamp = actor.game?.time;
  if (stamp != null && s.stamp === stamp) return s.layer.applied;
  s.stamp = stamp;
  return s.layer.tick(dt, opts);
}
/** Drop an actor's layer (its body is being replaced / disposed). */
export function releaseOrbit(actor) { const s = layers.get(actor); if (s) { s.layer?.dispose(); layers.delete(actor); } }
/** The layer of an actor (tests / diagnostics). */
export const orbitLayerOf = actor => layers.get(actor)?.layer || null;
