// Actor base (docs/ARCHITECTURE.md §3.5): the visual body + movement primitives + animation state of a player,
// monster or NPC. Gameplay code (src/game/*) owns the rules; it moves actors with setPosition/faceTowards and asks for
// animation states with play(). docs/GAMEPLAY_NOTES.md "What it needs from other modules" lists the behaviours relied on.
//
// FRAME (THE MIRROR RULE): `group` is a child of game.worldRoot (scale z = -1) and lives in the raw FILE frame:
//   group.position = (x, y, z) FILE, group.rotation.y = yaw, and a model with rotation.y = yaw faces FILE
//   (-sin yaw, 0, -cos yaw) (models face local -Z). To face a FILE direction (dx, dz): yaw = atan2(-dx, -dz).
//   Only headWorldPosition() returns THREE space (fileToThree), for nameplates / floaters outside the mirror.
//
// ANIMATION: play(state, opts) resolves a state to a clip spec through the subclass (_specFor), with fallbacks between
// related states (walk <-> run, idleCombat <-> idle, attack -> idleCombat ...). Clips come from game.models.loadClip
// (cached per anim + skeleton + duration by ModelCache; a per-model sync cache here lets already-loaded clips start on
// the same frame). Each clip is loaded at its action-table TimeLength and played at speed = TimeLength / opts.timeLength
// when the caller stretches it, times opts.speed. Cross-fade length = the table's Start_Inter read as 30 fps frames
// (5 -> 0.17 s for STAND/MOVE, 4 -> 0.13 s for ATTACK/DEFEAT, 1 -> 0.05 s for DEAD), clamped to [0.05, 0.3].
// A one-shot that ended with no new play() request within REST_DELAY returns to the actor's rest state, so nobody
// freezes on the last frame of a swing. Death holds the last pose (clampWhenFinished).
//
// DEATH (monsters: fadeOnDeath): die clip, then CORPSE_HOLD seconds, then a CORPSE_FADE fade-out; when it is done the
// actor sets faded = removable = fadeDone = true and hides its group (spawner.js removes and disposes it; its hard
// limit is 8 s after death, so the fade always starts by CORPSE_FADE_START_MAX). Clearing `dead` (revive) restores it.
//
// Extra fields written by other modules (brain, def, home, statuses, lastCombat, diedAt, killer, disposed,
// _gpState/_gpHold, ...) are plain properties and never interfere with anything here.
//
// LOCOMOTION SYNC (no foot sliding): a walk/run clip's ground speed at playback rate 1 is its
// root-motion stride (anim root-motion end - start, the same value as share/movecache.csv) divided by the clip
// length (action-table TimeLength) times the actor scale. While a walk/run loop plays, update() sets the clip's
// playback rate to (the speed the actor is actually moving at) / (that ground speed), so the feet stay planted at
// any speed (player buffs, map MoveSpeedFactor). The measured speed is the per-frame
// displacement written by gameplay code (controller) before update() runs, lightly smoothed.
// GLOBAL REA (monsters): walk/run/stand play at the action-table TimeLength rate (speed 1 after loadClip
// stretch) � Global does NOT retime monster clips to WalkSpeed/RunSpeed. Monster.kind skips this sync so
// e.g. Crude Nightmare walk (stride ~0.6 / TL 1s vs WalkSpeed 1.3) stays Global-accurate instead of ~2x.
import * as THREE from 'three';
import { Animator } from '../engine/animator.js';
import { crowdRegister, crowdTick } from '../engine/crowd-skinning.js';
import { closeLoopSeam } from '../engine/loopseam.js';
import { freezeMatrices } from '../engine/models.js';
import { fileToThree } from '../engine/space.js';
import { warmActorFade } from '../engine/shader-prewarm.js';
import { spawnSlot } from '../engine/spawn-budget.js';
const COMPILED_MODELS = new WeakSet();   // PERF-CROWD: compileAsync once per model (later bodies share its programs)
import { sampleRootMotion } from '../formats/anim.js';
import { TargetRing } from './targetring.js';
import { TargetMarker } from './targetmarker.js';

export const TURN_RATE = 14;               // 1/s: exponential turn towards the goal yaw (~90 % in 0.16 s)
export const STANCE_SECONDS = 10;          // battle stance lingers this long after the last hit (= controller.js)
export const DEFAULT_FADE = 0.15;          // cross-fade seconds when the table gives no Start_Inter
export const REST_DELAY = 0.3;             // s after a finished one-shot before returning to the rest loop
export const CORPSE_HOLD = 1.8;            // s the corpse lies still after its die clip
export const CORPSE_FADE = 1.5;            // s of fade-out
export const CORPSE_FADE_START_MAX = 5.5;  // fade starts by this time after death at the latest (spawner limit 8 s)
export const HIGHLIGHT_TINT = new THREE.Color(0.30, 0.26, 0.18); // SkinnedInstance adds 0.35 x this as emissive

/** States that loop by default. */
export const LOOP_STATES = new Set(['idle', 'idleCombat', 'walk', 'run', 'sit', 'guard', 'block', 'createPose', 'stun', 'sleep']);
/** Locomotion states whose playback rate follows the actor's ground speed (see LOCOMOTION SYNC). */
export const LOCOMOTION_STATES = new Set(['walk', 'run']);
export const LOCO_RATE_MIN = 0.25;         // playback-rate clamp for the locomotion sync
export const LOCO_RATE_MAX = 3.5;

/**
 * Root-motion stride of a clip: XZ distance its root travels over one playback (units, model space, scale 1).
 * 0 when the anim carries no root motion (in-place loops). Cached on clip.userData.stride.
 */
export function clipStride(clip) {
  const ud = clip?.userData;
  if (!ud) return 0;
  if (ud.stride != null) return ud.stride;
  let d = 0;
  const rm = ud.rootMotion;
  if (rm && rm.times && rm.times.length >= 2) {
    try { const e = sampleRootMotion({ rootMotion: rm }, 1); d = Math.hypot(e[0], e[2]); } catch { d = 0; }
  }
  ud.stride = Number.isFinite(d) ? d : 0;
  return ud.stride;
}

// ------------------------------------------------------------------------------------------ view culling
// Performance: NPCs and monsters beyond the map's draw distance (world.cullDistance = min(Clip_Far x drawDistance,
// fog end + 5), the same limit the objects use) or outside the camera frustum are hidden AND frozen: no mixer
// update, no matrix/bone updates (group.matrixWorldAutoUpdate = false), no shadow/render traversal. Skipped time is
// accumulated and applied when the actor comes back into view, so loops resume in phase. The frustum test uses the
// actor's live position with a margin (shadows, big models), so nothing pops at the screen edges. The player is
// never culled.
const CULL_MARGIN = 4;          // units added to the bounding sphere (cast shadows reach into view)
const MAX_CATCHUP = 5;          // s of skipped animation applied at most when an actor reappears
export const LOD_NEAR = 16;     // animation LOD (see update): every frame within this camera distance,
export const LOD_FAR = 32;      // every 2nd frame up to this one, every 3rd beyond
export const SHADOW_CAST_DIST = 22; // FPS-10X: drop castShadow beyond this camera range (m)
export const HEAVY_ACTOR_PRESSURE = 28; // FPS-10X: when this many bodies share the view, raise every-N sooner
// HIGH-FRAME-RATE FLOOR of the animation LOD (opt-4, ENGINE-CHOSEN - no game file says how often a far body must be re-posed). The
// frame-count LOD above keeps its 16 / 32 m bands and its 1 / 2 / 3 steps, so nothing changes at 60 fps. On top of it a LOOPING clip
// of a body farther than LOD_RATE_NEAR from the camera is re-posed at least LOD_RATE_MID_HZ times a second (LOD_RATE_FAR_HZ beyond
// LOD_RATE_FAR_AT), i.e. every N-th frame with N = floor(frame rate / that rate): at 240 fps a body 6-12 m away is posed every 2nd
// frame (120 Hz), farther than 12 m every 3rd (80 Hz), and below ~120 fps no frame is ever skipped by this rule. The skipped time is
// carried into the next pose exactly like the frame-count LOD (loop phase, locomotion sync and REST_DELAY stay in real time);
// one-shot clips (attack, hit, die ...), the target, the dying and the local player are never throttled by it.
// game.gfx.lodRate = false turns it off (A/B measurements with the test client).
export const LOD_RATE_NEAR = 6;         // m: closer than this the body is posed every frame
export const LOD_RATE_MID_HZ = 120;     // Hz floor for bodies LOD_RATE_NEAR .. LOD_RATE_FAR_AT away
export const LOD_RATE_FAR_AT = 12;      // m
export const LOD_RATE_FAR_HZ = 80;      // Hz floor beyond LOD_RATE_FAR_AT
// SMOOTH-ANIM minimum pose rates of the distance bands (see _lodEvery); ENGINE-CHOSEN.
export const LOD_POSE_MID_HZ = 60;      // LOD_NEAR .. LOD_FAR
export const LOD_POSE_FAR_HZ = 45;      // beyond LOD_FAR
export const LOD_POSE_CROWD_HZ = 40;    // 2x HEAVY_ACTOR_PRESSURE bodies in view
export const LOD_POSE_CROWD_MIN_HZ = 30; // 3x HEAVY_ACTOR_PRESSURE
export const LOD_POSE_ONESHOT_HZ = 60;  // one-shot clips (attack / hit / cast) of any body
const _view = { t: -1, frame: -1, frustum: new THREE.Frustum(), m: new THREE.Matrix4(), cx: 0, cz: 0, dist: 75, ok: false, dtAvg: 0 };
const _sphere = new THREE.Sphere();

/** Camera frustum + draw distance, computed once per game frame (and the smoothed frame time the rate floor uses). */
function viewInfo(game) {
  const cam = game?.camera;
  if (!cam) { _view.ok = false; return _view; }
  const stamp = game.time ?? 0;
  if (_view.t === stamp && _view.game === game) return _view;
  if (_view.game === game && _view.t >= 0) {
    // one sample per game frame (game.time advances by the frame's dt); implausible gaps (pause, load, tab switch) are ignored
    const d = stamp - _view.t;
    if (d > 0 && d < 0.1) _view.dtAvg = _view.dtAvg > 0 ? _view.dtAvg + (d - _view.dtAvg) * 0.1 : d;
  } else _view.dtAvg = 0;
  _view.t = stamp; _view.game = game;
  if (cam.parent === null) cam.updateMatrixWorld();           // also refreshes matrixWorldInverse
  _view.m.multiplyMatrices(cam.projectionMatrix, cam.matrixWorldInverse);
  _view.frustum.setFromProjectionMatrix(_view.m);
  _view.cx = cam.position.x; _view.cz = -cam.position.z;          // THREE -> FILE
  const d = Number(game.world?.cullDistance);
  _view.dist = d > 0 ? d : 75;
  // Count each ready, visible shared monster once per view frame, rather than
  // ignoring the network collection or counting pending/culled bodies.
  const net=game.network;
  if(net?.active){
    let count=0;
    for(const actor of net.monsters?.values?.() || [])
      if(actor?.loaded&&!actor.disposed&&!actor.culled&&actor.group?.visible!==false)count++;
    _view.monsterPressure=count;
  }else _view.monsterPressure=game.monsters?.length || 0;
  _view.ok = true;
  return _view;
}

/** Ground speed (units/s) of a locomotion clip played at rate 1: stride / TimeLength. */
export function clipGroundSpeed(clip) {
  const s = clipStride(clip);
  return s > 0.05 && clip.duration > 0 ? s / clip.duration : 0;
}

/** Fallback chain when a state has no usable clip. */
export const FALLBACKS = {
  idle: ['idleCombat'], idleCombat: ['idle'], walk: ['run', 'idle'], run: ['walk', 'idle'],
  attack: ['idleCombat', 'idle'], skill: ['attack'], cast: ['skill', 'attack'],
  revive: ['idle'], knockdown: ['hit'], stun: ['hit'], sleep: ['idle'], blocked: ['hit'],
  block: ['idleCombat'], guard: ['idleCombat'], createPose: ['idle'],
};

let SEQ = 0;

/** Cross-fade seconds from an action-table Start_Inter value (frames at 30 fps). */
export function interFade(startInter) {
  const v = Number(startInter);
  if (!(v > 0)) return DEFAULT_FADE;
  return Math.max(0.05, Math.min(0.3, v / 30));
}

export function wrapAngle(a) {
  a = (a + Math.PI) % (Math.PI * 2);
  if (a < 0) a += Math.PI * 2;
  return a - Math.PI;
}

const normKey = k => String(k || '').trim().replace(/\\/g, '/').replace(/^\/+/, '').toLowerCase();

// ------------------------------------------------------------------------------------------ clip cache
// SkinnedModel -> Map('<anim>|<duration>' -> { done, clip, promise }). ModelCache already caches the promises; this
// adds synchronous access once a clip has resolved (so play() can switch on the same frame).
const clipCaches = new WeakMap();

export function clipEntry(models, model, key, duration) {
  let m = clipCaches.get(model);
  if (!m) { m = new Map(); clipCaches.set(model, m); }
  const dur = Number(duration) > 0 ? Number(duration) : null;
  const ck = `${key}|${dur ?? 'auto'}`;
  let e = m.get(ck);
  if (!e) {
    e = { done: false, clip: null, promise: null };
    const entry = e;
    let p;
    try {
      const load = models?.loadClipWithStatus || models?.loadClip;
      p = load ? load.call(models, key, model, { duration: dur }) : null;
    } catch (error) { p = Promise.reject(error); }
    entry.promise = Promise.resolve(p).catch(error => {
      entry.error = error;
      if (error?.transient && m.get(ck) === entry) m.delete(ck);
      return null;
    }).then(c => { entry.clip = c || null; entry.done = true; return entry.clip; });
    m.set(ck, e);
  }
  return e;
}

// SKILL-CLIP-COLD 2026-10-30: a resolved clip of the same anim at another length. The caller's timeLength restretches it
// (_applyClip speed = clip.duration / timeLength), so a cast whose length changed (Acceleration / casting-speed options)
// never waits on a reparse of an anim this body already holds.
function readyClipOf(model, key) {
  const m = clipCaches.get(model);
  if (!m) return null;
  const prefix = `${key}|`;
  for (const [ck, e] of m) if (e.done && e.clip && ck.startsWith(prefix)) return e.clip;
  return null;
}
const animNow = () => (globalThis.performance?.now?.() ?? Date.now());
const LATE_CLIP_MIN = 0.02;   // s: a clip resolved later than this joins its timeline mid-way (_applyClip)

/**
 * Clip spec for an action-set state (monsters.json / npcs.json actionSets): used by Monster and NPC.
 * @returns {{key, duration, fade, split, timing, loop}|null}
 */
export function actionSetSpec(set, unbound, state, opts = {}) {
  if (!set) return null;
  const S = set.states || {};
  const C = set.clips || [];
  const arr = v => (Array.isArray(v) ? v : v == null ? [] : [v]);
  const spec = (ci, loop) => {
    if (ci == null || ci < 0 || !C[ci] || !C[ci][0] || unbound?.has(ci)) return null;
    const c = C[ci];
    return { key: c[0], duration: c[1] > 0 ? c[1] : null, fade: interFade(c[2]), timing: c[4] || 0, split: c[5] || 0, loop, clipIndex: ci };
  };
  const v = opts.variant | 0;
  switch (state) {
    case 'idle': return spec(S.idle, true) || spec(S.idleCombat, true);
    case 'idleCombat': return spec(S.idleCombat, true);
    case 'walk': return spec(S.walk, true);
    case 'run': return spec(S.run, true);
    case 'die': return spec(S.die, false);
    case 'hit': { const H = arr(S.hit); return spec(H[v], false) || spec(H[0], false); }
    case 'attack': case 'skill': case 'cast': {
      // opts.variant = ATTACK action index (monsters.json attackActionIndex: 0 melee ... 4 range ... 10-13 aggro)
      const A = set.actions?.ATTACK || [];
      return spec(A[v], false) || spec(arr(S.attack)[0], false);
    }
    default: {
      const x = S[state];
      if (x == null) return null;
      return Array.isArray(x) ? (spec(x[v], LOOP_STATES.has(state)) || spec(x[0], LOOP_STATES.has(state))) : spec(x, LOOP_STATES.has(state));
    }
  }
}

/**
 * Body radius from a bind-pose bounding box (FILE frame): combat reach wants the torso, not the T-pose arms / legs /
 * tail. 0.28 x the narrow horizontal side + 0.12 x the height, clamped to [0.35, 3]:
 * spider 0.44, devil worker 0.46, zombie host 0.37, langrama 0.62, captain parasite 1.06, 6-10 m bosses 1.4-3.
 */
export function bodyRadius(bbox, width = 0) {
  let r = 0.45;
  if (bbox && !bbox.isEmpty()) {
    const sx = bbox.max.x - bbox.min.x, sz = bbox.max.z - bbox.min.z, h = Math.max(0, bbox.max.y);
    r = 0.28 * Math.min(sx, sz) + 0.12 * h;
  }
  if (Number(width) > 0) r = Math.max(r, Number(width) * 0.45);  // monster.dat width (cells blocked by the body)
  return Math.max(0.35, Math.min(3, r));
}

// ============================================================================================ Actor
export class Actor {
  /**
   * @param {object} game  game.worldRoot, game.models, game.world, game.data, game.time
   * @param {{kind?:string, name?:string, level?:number}} [info]
   */
  constructor(game, { kind = 'actor', name = '', level = 1 } = {}) {
    this.game = game || null;
    this.id = ++SEQ;
    this.kind = kind;
    this.name = name ?? '';
    this.level = level;

    this.group = new THREE.Group();
    this.group.name = `${kind}:${this.name || this.id}`;
    this.group.userData.actor = this;
    game?.worldRoot?.add(this.group);

    // FILE frame placement
    this.x = 0; this.z = 0; this.y = 0;
    this._yaw = 0; this._yawGoal = 0;
    this.turnRate = TURN_RATE;
    this.scale = 1;

    this.radius = 0.5;
    this.height = 1.8;
    this.hp = 1; this.maxHp = 1;
    this.mp = 0; this.maxMp = 0;
    this.dead = false;
    this.target = null;

    // visuals
    this.model = null;        // SkinnedModel | StaticModel
    this.instance = null;     // SkinnedInstance
    this.object = null;       // static Object3D (StaticModel.instantiate)
    this.animator = null;
    this.fadeOnDeath = false;
    this.opacity = 1;
    this.faded = false; this.removable = false; this.fadeDone = false;
    this.highlighted = false;
    this.disposed = false;
    this.loaded = false;

    // animation state
    this.state = null;        // last requested state
    this.stateOpts = null;
    this.clip = null;         // THREE.AnimationClip playing
    this.clipSpec = null;
    this._clipLoop = true;
    this._playSeq = 0;
    this._pendingPlay = null;
    this._restT = 0;
    this._fakeEnd = null;
    this._dieLen = null;
    this._deathT = 0;
    this._grounded = false;
    this._ring = null;
    this._loadPromise = null;

    // locomotion sync (see LOCOMOTION SYNC)
    this._locoGround = 0;      // ground speed (units/s) of the playing walk/run loop at rate 1, 0 = not a synced loop
    this._locoRate = 1;        // playback rate the sync last applied
    this._moveVel = 0;         // smoothed measured ground speed (units/s)
    this._px = null; this._pz = null;

    // view culling (see VIEW CULLING); the player sets cullable = false
    this.cullable = kind !== 'player';
    this.culled = false;
    this._skipDt = 0;
  }

  /** True when the actor is outside the draw distance or the camera frustum (never for the player). */
  _outOfView() {
    if (!this.cullable || !this.loaded) return false;
    const v = viewInfo(this.game);
    if (!v.ok) return false;
    const sc = Number(this.scale) > 0 ? Number(this.scale) : 1;
    const r = Math.max(this.height * sc, this.radius * 2 * sc, 1) + CULL_MARGIN;
    if (Math.hypot(this.x - v.cx, this.z - v.cz) > v.dist + r) return true;
    _sphere.center.set(this.x, this.y + this.height * sc * 0.5, -this.z);   // FILE -> THREE
    _sphere.radius = r;
    return !v.frustum.intersectsSphere(_sphere);
  }

  /** Animation LOD step (1 = every frame) from the camera distance; game.gfx.animLod = false turns it off. */
  _lodEvery() {
    const gfx = this.game?.gfx;
    if (!gfx || gfx.animLod === false || this.highlighted || this.dead && !this.faded && this._deathT < 3) return 1;
    const v = viewInfo(this.game);
    if (!v.ok) return 1;
    const d = Math.hypot(this.x - v.cx, this.z - v.cz);
    const near = gfx.lodNear ?? LOD_NEAR, far = gfx.lodFar ?? LOD_FAR;
    // SMOOTH-ANIM (2026-10-30): the bands are minimum POSE RATES, not frame counts. "every 2nd / 3rd frame" (5th under crowd
    // pressure) meant 12-30 Hz poses at 60 fps: mobs and NPCs visibly stepped through their walk cycles. A body is now
    // re-posed at least LOD_POSE_*_HZ times a second whatever the frame rate (every frame at 60 fps), and only frame rates
    // above that floor skip frames. ENGINE-CHOSEN rates; game.gfx.lodLegacy = true restores the frame-count bands (A/B).
    const pressure = _view.monsterPressure + (this.game?.npcs?.length || 0) + (this.game?.network?.players?.size || 0);
    let every = d > far ? 3 : d > near ? 2 : 1;
    if (gfx.lodLegacy === true) {
      if (pressure >= HEAVY_ACTOR_PRESSURE) {
        if (d > near * 0.55) every = Math.max(every, 2);
        if (d > far * 0.65) every = Math.max(every, 3);
        if (pressure >= HEAVY_ACTOR_PRESSURE * 2 && d > near * 0.5) every = Math.max(every, 4);
        if (pressure >= HEAVY_ACTOR_PRESSURE * 3 && d > near) every = Math.max(every, 5);
      }
    } else {
      let hz = d > far ? LOD_POSE_FAR_HZ : d > near ? LOD_POSE_MID_HZ : Infinity;
      if (pressure >= HEAVY_ACTOR_PRESSURE) {
        if (d > near * 0.55) hz = Math.min(hz, LOD_POSE_MID_HZ);
        if (d > far * 0.65) hz = Math.min(hz, LOD_POSE_FAR_HZ);
        if (pressure >= HEAVY_ACTOR_PRESSURE * 2 && d > near * 0.5) hz = Math.min(hz, LOD_POSE_CROWD_HZ);
        if (pressure >= HEAVY_ACTOR_PRESSURE * 3 && d > near) hz = Math.min(hz, LOD_POSE_CROWD_MIN_HZ);
      }
      if (!this._clipLoop) hz = Math.max(hz, LOD_POSE_ONESHOT_HZ);   // attacks, hits, casts: never below 60 Hz
      every = hz === Infinity || !(v.dtAvg > 0) ? 1 : Math.max(1, Math.floor(1 / (v.dtAvg * hz) + 0.25));
    }
    // high-frame-rate floor (see LOD_RATE_*): looping clips only, never while the frame rate is unknown or below ~120 fps
    if (d > LOD_RATE_NEAR && v.dtAvg > 0 && this._clipLoop && gfx.lodRate !== false) {
      const e = Math.floor(1 / (v.dtAvg * (d > LOD_RATE_FAR_AT ? LOD_RATE_FAR_HZ : LOD_RATE_MID_HZ)) + 0.25);
      if (e > every) return e;
    }
    return every;
  }

  
  /** FPS: disable castShadow when far from camera (Global fog/draw unchanged). */
  _updateShadowCast() {
    if (!this.loaded || this.culled) return;
    const v = viewInfo(this.game);
    if (!v.ok) return;
    const d = Math.hypot(this.x - v.cx, this.z - v.cz);
    const on = d <= (this.game?.gfx?.shadowCastDist ?? SHADOW_CAST_DIST);
    if (this._shadowCastOn === on) return;
    this._shadowCastOn = on;
    const apply = (root) => root?.traverse?.(o => { if (o.isMesh) o.castShadow = on; });
    apply(this.instance?.root); apply(this.object);
  }

  /** Hide + freeze (or show + resume) the body. */
  _setCulled(on) {
    if (on === this.culled) return;
    this.culled = on;
    const g = this.group;
    g.matrixWorldAutoUpdate = !on;
    // (graphics) three r170 still walks a hidden subtree in every scene matrix update: skip it entirely while culled
    freezeMatrices(g, on, false);
    if (!on && this.instance?.frozen) this.instance.freeze(false);
    if (on) { this._cullHidden = g.visible; g.visible = false; }
    else g.visible = this._cullHidden !== false && !this.faded;   // matrices refresh in the next render traversal
  }

  /** Measured ground speed (units/s, smoothed) - what the locomotion sync uses. */
  get moveVelocity() { return this._moveVel; }

  // ---------------------------------------------------------------------------------------- facing
  /** Facing angle (FILE frame, rotation.y under the mirror root). Assigning snaps (no smooth turn). */
  get yaw() { return this._yaw; }
  set yaw(v) {
    const a = Number(v);
    if (!Number.isFinite(a)) return;
    this._yaw = this._yawGoal = wrapAngle(a);
    this.group.rotation.y = this._yaw;
  }
  /** The yaw the actor is turning towards. */
  get targetYaw() { return this._yawGoal; }

  /** FILE-frame unit facing vector. */
  facing(out = { x: 0, z: 0 }) { out.x = -Math.sin(this._yaw); out.z = -Math.cos(this._yaw); return out; }

  /** Turn (smoothly, in update) to face FILE point (x, z). */
  faceTowards(x, z) {
    const dx = Number(x) - this.x, dz = Number(z) - this.z;
    if (!(Math.abs(dx) > 1e-6 || Math.abs(dz) > 1e-6)) return;
    this._yawGoal = Math.atan2(-dx, -dz);
  }

  /** Face a FILE direction immediately. */
  faceDirection(dx, dz, snap = true) {
    if (!(Math.abs(dx) > 1e-9 || Math.abs(dz) > 1e-9)) return;
    const a = Math.atan2(-dx, -dz);
    if (snap) this.yaw = a; else this._yawGoal = a;
  }

  // ---------------------------------------------------------------------------------------- placement
  /** Place the actor at FILE (x, z); y follows the ground. */
  setPosition(x, z) {
    x = Number(x); z = Number(z);
    if (!Number.isFinite(x) || !Number.isFinite(z)) return;
    // A brief landed knockback owns movement; AI cannot pull the actor back toward its target mid-push.
    // Explicit teleports still cancel the push immediately.
    if (this._knockback && !this._advancingKnockback) {
      if (Math.hypot(x - this.x, z - this.z) <= 4) return;
      this._knockback = null;
    }
    const jump = !this._grounded || Math.hypot(x - this.x, z - this.z) > 4;
    this.x = x; this.z = z;
    this._snapY(jump);
    this._syncGroup();
    if (this.instance?.frozen) this.instance.freeze(false);   // (graphics) animation-LOD freeze: it moves again
  }

  /** Smooth authoritative ground displacement, with walkability checked along the whole push. */
  knockback(dx, dz, distance = 1.5, duration = 0.22) {
    const length = Math.hypot(dx, dz);
    if (this.dead || this.disposed || !(length > 1e-6) || !(distance > 0)) return false;
    this._knockback = { x: this.x, z: this.z, dx: dx / length * distance, dz: dz / length * distance,
      time: 0, duration: Math.max(0.05, Number(duration) || 0.22) };
    return true;
  }

  _advanceKnockback(dt) {
    const k = this._knockback;
    if (!k) return;
    if (this.dead || this.disposed) { this._knockback = null; return; }
    k.time = Math.min(k.duration, k.time + dt);
    const u = k.time / k.duration, ease = 1 - (1 - u) ** 3;
    const tx = k.x + k.dx * ease, tz = k.z + k.dz * ease;
    const dx = tx - this.x, dz = tz - this.z, steps = Math.max(1, Math.ceil(Math.hypot(dx, dz) / 0.1));
    const startX = this.x, startZ = this.z, world = this.game?.world;
    let x = startX, z = startZ, blocked = false;
    for (let i = 1; i <= steps; i++) {
      const nx = startX + dx * i / steps, nz = startZ + dz * i / steps;
      if (world?.isWalkable && !world.isWalkable(nx, nz)) { blocked = true; break; }
      x = nx; z = nz;
    }
    this._advancingKnockback = true;
    try { this.setPosition(x, z); } finally { this._advancingKnockback = false; }
    if (blocked || k.time >= k.duration) this._knockback = null;
  }

  /** Step up to speed*dt towards FILE (x, z), facing the way it goes. Returns true when arrived. */
  moveTowards(x, z, speed, dt) {
    const dx = x - this.x, dz = z - this.z;
    const d = Math.hypot(dx, dz);
    if (d < 1e-4) return true;
    const step = Math.max(0, Number(speed) || 0) * Math.max(0, Number(dt) || 0);
    this.faceTowards(x, z);
    if (step >= d - 1e-6) { this.setPosition(x, z); return true; }
    this.setPosition(this.x + (dx / d) * step, this.z + (dz / d) * step);
    return false;
  }

  /** XZ distance to an actor or a {x, z} point. */
  distanceTo(o) {
    if (!o) return Infinity;
    return Math.hypot((Number(o.x) || 0) - this.x, (Number(o.z) || 0) - this.z);
  }

  /** Top of the model in THREE space (nameplates, floaters). */
  headWorldPosition(out = new THREE.Vector3()) {
    return fileToThree(this.x, this.y + this.height * this.scale, this.z, out);
  }

  /** Body centre in THREE space. */
  centerWorldPosition(out = new THREE.Vector3()) {
    return fileToThree(this.x, this.y + this.height * this.scale * 0.55, this.z, out);
  }

  _heightAt(x, z, refY) {
    const w = this.game?.world;
    if (!w || typeof w.heightAt !== 'function') return null;
    try {
      const h = w.heightAt(x, z, refY);
      return Number.isFinite(h) ? h : null;
    } catch { return null; }
  }

  _snapY(fresh) {
    const h = this._heightAt(this.x, this.z, fresh ? null : this.y);
    if (h != null) { this.y = h; this._grounded = true; }
  }

  _syncGroup() {
    const g = this.group;
    g.position.set(this.x, this.y, this.z);
    g.rotation.y = this._yaw;
    const s = Number(this.scale) > 0 ? Number(this.scale) : 1;
    if (g.scale.x !== s) g.scale.setScalar(s);
  }

  // ---------------------------------------------------------------------------------------- loading
  /** Loads model + clips (subclasses implement _load). Safe to call more than once. */
  load() {
    if (!this._loadPromise) {
      this._loadPromise = (async () => {
        try { await this._load(); } catch (err) { console.warn(`[actors] ${this.kind} ${this.name} failed to load`, err); }
        if (this.kind === 'monster' && !this.disposed) { const s = spawnSlot(this.game); if (s) await s; }   // PERF-CROWD: spread spawns over frames
        this.loaded = true;
        if (!this.disposed) this._afterLoad();
      })();
    }
    return this._loadPromise;
  }

  async _load() {}

  /** Use a SkinnedModel as the body. */
  _setSkinned(model) {
    this.model = model;
    const inst = model.instantiate();
    this.instance = inst;
    this.group.add(inst.root);
    inst.root.traverse(o => { if (o.isMesh) { o.castShadow = true; o.receiveShadow = false; } });
    this.animator = new Animator(inst);
    return inst;
  }

  /** Use a StaticModel as the body (no skeleton: static NPCs such as mailboxes). */
  _setStatic(model) {
    this.model = model;
    this.object = model.instantiate();
    this.group.add(this.object);
    this.object.traverse(o => { if (o.isMesh) { o.castShadow = true; o.receiveShadow = false; } });
    return this.object;
  }

  /** Wait for the first clip spec of each state (parallel). */
  async _preload(states) {
    if (!this.animator || !this.model) return;
    const jobs = [];
    for (const [state, opts] of states) {
      const spec = this._candidates(state, opts || {})[0];
      if (spec?.key) jobs.push(clipEntry(this.game?.models, this.model, spec.key, spec.duration).promise);
    }
    await Promise.all(jobs);
  }

  /** Start loading (never waits) a body clip at the length it will play: skills warm every phase clip at cast start (engine.js). */
  warmClip(key, duration) {
    if (!key || !this.model || !this.animator) return null;
    return clipEntry(this.game?.models, this.model, normKey(key), Number(duration) > 0 ? Number(duration) : null).promise;
  }

  _afterLoad() {
    this._snapY(true);
    this._syncGroup();
    // 2.2.1: this body's shader variants link in parallel (KHR_parallel_shader_compile) from now on, instead of inside the frame
    // that first draws it (a remote player / monster appearing mid-play linked its programs synchronously: in-frame stalls,
    // measured). The draw still links anything not ready, exactly as before.
    const g = this.game, r = g?.renderer;
    const firstOfModel = !this.model || globalThis.__dekaronNoCompileOnce || globalThis.__dkT_noCompileOnce || !COMPILED_MODELS.has(this.model);
    if (this.model && this.kind === 'monster') COMPILED_MODELS.add(this.model);
    if (firstOfModel && typeof r?.compileAsync === 'function' && g.scene && g.camera) r.compileAsync(this.group, g.camera, g.scene).catch(() => {});
    if (this.fadeOnDeath) warmActorFade(g, this);   // the corpse-fade variants of this body too (engine/shader-prewarm.js; kill switch globalThis.__dekaronNoPrewarm)
    const p = this._pendingPlay;
    this._pendingPlay = null;
    if (p) this.play(p[0], p[1]);
    else if (!this.clip) this.play(this.dead ? 'die' : 'idle', { startAt: Math.random() * 3 }); // desynchronised idles
    if (this.kind === 'monster') crowdRegister(this);   // overnight 43.19 phase 3: GPU crowd skinning (engine/crowd-skinning.js)
  }

  // ---------------------------------------------------------------------------------------- animation
  /** Subclasses: clip spec {key, duration, loop, fade?, style?, speed?} for a state, or null. */
  _specFor() { return null; }

  /** Loop the actor returns to after a one-shot. */
  _restState() {
    if (this.dead) return null;
    if (LOOP_STATES.has(this.state)) return this.state;
    return 'idleCombat';
  }

  /** Ordered clip candidates for a state: explicit opts.anim, the state itself, then its fallbacks. */
  _candidates(state, opts = {}) {
    const out = [];
    if (opts.anim) {
      out.push({ key: normKey(opts.anim), duration: Number(opts.timeLength) > 0 ? Number(opts.timeLength) : null,
        loop: LOOP_STATES.has(state), style: this._styleForAnim?.(opts.anim), state, explicit: true });
    }
    const seen = new Set([state]);
    const queue = [state];
    while (queue.length) {
      const s = queue.shift();
      const primary = s === state;
      let spec = null;
      try { spec = this._specFor(s, primary ? opts : {}); } catch (err) { console.warn('[actors] spec failed', s, err); }
      if (spec && spec.key) out.push({ ...spec, key: normKey(spec.key), state: s, fallback: !primary });
      for (const f of FALLBACKS[s] || []) if (!seen.has(f)) { seen.add(f); queue.push(f); }
    }
    return out;
  }

  /**
   * Play an animation state.
   * @param {string} state 'idle'|'idleCombat'|'walk'|'run'|'attack'|'hit'|'die'|'skill'|'cast' (+ subclass extras)
   * @param {{variant?:number, loop?:boolean, onEnd?:Function, speed?:number, timeLength?:number, anim?:string,
   *          fade?:number, restart?:boolean, startAt?:number, startPhase?:number}} [opts]
   */
  play(state, opts = {}) {
    if (this.disposed || !state) return;
    opts = opts || {};
    this.state = state;
    this.stateOpts = opts;
    this._restT = 0;
    this._fakeEnd = null;
    const seq = ++this._playSeq;
    this._playAt = animNow();
    if (!this.animator) {
      if (!this.loaded) this._pendingPlay = [state, opts];
      else if (typeof opts.onEnd === 'function' && opts.loop === false) this._fakeEnd = { t: Number(opts.timeLength) > 0 ? Number(opts.timeLength) : 0.3, cb: opts.onEnd };
      return;
    }
    // The finished previous clip must not cancel this unresolved request.
    this._clipPending = true;
    this._tryCandidates(this._candidates(state, opts), 0, opts, seq);
  }

  _tryCandidates(cands, i, opts, seq) {
    if (typeof opts._skillPhaseCurrent === 'function' && !opts._skillPhaseCurrent()) {
      if (seq === this._playSeq) this._clipPending = false;
      return;
    }
    if(i===0)this._clipRequested=cands.length>0;
    for (; i < cands.length; i++) {
      const spec = cands[i];
      const e = clipEntry(this.game?.models, this.model, spec.key, spec.duration);
      if (!e.done) {
        // SKILL-CLIP-COLD: the same anim already resolved at another length plays now, restretched to this request
        const ready = spec.explicit && Number(opts.timeLength) > 0 ? readyClipOf(this.model, spec.key) : null;
        if (ready) { this._applyClip(ready, spec, opts); return; }
        const at = i;
        const requestedModel = this.model;
        // Body-owning clips (skill/cast/attack/hit/die), including looping cast/charge
        // phases (engine.js _playClip(..., true)), must not leave prior locomotion at
        // weight 1 while the authored clip cold-loads. Native TDoll CAnimationCmd
        // (ClipCommands size 0x20 @ 0x1168690) takes ownership state 0x18 immediately;
        // MoveAnimationCmd (size 0x21 @ 0x11682b0) alone clears it. Web async load has
        // no native twin — freeze the current pose (same as die _noClip) until apply.
        // Do NOT gate on opts.loop: cast/charge passes loop:true via playOnce spread.
        // Evidence: CLIENT-OPEN-ISSUES; CAST-IDENTITY; decompile 32-bit ClipCommands RTTI.
        if (!LOCOMOTION_STATES.has(this.state) && this.animator) {
          try { this.animator.stop(); } catch { /* ignore */ }
          this._locoGround = 0;
        }
        this._clipFlight = e.promise;
        e.promise.then(() => {
          if (seq !== this._playSeq || this.disposed) return;
          if (typeof opts._skillPhaseCurrent === 'function' && this.model !== requestedModel) { this._clipPending = false; return; }
          // SKILL-CLIP-COLD: a body clip that arrives late (cold load) joins its timeline where it would be by now, so it
          // still ends with its skill phase / swing instead of starting late and being cut, or dropped, at the phase end
          const late = (animNow() - (this._playAt || 0)) / 1000;
          const next = late > LATE_CLIP_MIN && !LOOP_STATES.has(this.state) ? { ...opts, _lateBy: late } : opts;
          this._tryCandidates(cands, e.error?.transient ? at + 1 : at, next, seq);
        });
        return;
      }
      if (e.clip) { this._applyClip(e.clip, spec, opts); return; }
    }
    this._noClip(opts);
  }

  _applyClip(clip, spec, opts) {
    this._clipPending = false;
    const primary = !spec.fallback;
    const loop = primary && opts.loop != null ? !!opts.loop : !!spec.loop;
    let speed = Number(spec.speed) > 0 ? Number(spec.speed) : 1;
    if (primary) {
      if (Number(opts.speed) > 0) speed *= Number(opts.speed);
      const tl = Number(opts.timeLength);
      if (tl > 0 && clip.duration > 0) speed *= clip.duration / tl;     // stretch the clip to the caller's length
    }
    const fade = primary && opts.fade != null ? Math.max(0, Number(opts.fade) || 0) : (spec.fade ?? DEFAULT_FADE);
    // locomotion sync: a walk/run loop plays at (ground speed) / (its root-motion speed) - see LOCOMOTION SYNC
    // Monsters: Global REA keeps authored TimeLength rate (no WalkSpeed/RunSpeed retime).
    const sc = Number(this.scale) > 0 ? Number(this.scale) : 1;
    const locoOk = this.kind !== 'monster';
    this._locoGround = loop && locoOk && LOCOMOTION_STATES.has(spec.state) ? clipGroundSpeed(clip) * sc : 0;
    if (this._locoGround > 0) {
      // (2u) no measured speed yet (first steps after spawn): start at the known stride speed (Player.groundSpeed)
      const nominal = Number(opts.moveSpeed) > 0 ? Number(opts.moveSpeed) : (Number(this._nominalSpeed?.(spec.state)) || 0);
      const v = nominal > 0 ? nominal : this._moveVel;
      if (v > 0) speed = Math.max(LOCO_RATE_MIN, Math.min(LOCO_RATE_MAX, v / this._locoGround));
      this._locoRate = speed;
    }
    this._onClipStart(spec, clip, opts);
    // time the animation LOD / view culling held back belongs to the previous clip: the new one starts now
    this._lodAcc = 0;
    this._skipDt = 0;
    // a looping walk / run (monster move) clip whose last key differs from its first jumps at the wrap: close the seam (loopseam.js)
    if (loop && LOCOMOTION_STATES.has(spec.state)) clip = closeLoopSeam(clip);
    // startPhase (0..1 of the clip): the stance swap of a running body continues the stride instead of restarting it
    const startAt = Number(opts.startAt) > 0 ? Number(opts.startAt) : Number(opts.startPhase) > 0 ? Number(opts.startPhase) * clip.duration : 0;
    // SKILL-CLIP-COLD: time already elapsed since the request (clip seconds); a one-shot stays short of its end so it still finishes (onEnd)
    const lateAt = !(startAt > 0) && Number(opts._lateBy) > 0
      ? (loop ? (opts._lateBy * speed) % Math.max(clip.duration, 1e-3) : Math.min(opts._lateBy * speed, clip.duration * 0.999)) : 0;
    this.animator.play(clip, {
      loop, fade, speed, clampWhenFinished: true, restart: !!opts.restart,
      startAt: startAt > 0 ? (startAt % Math.max(clip.duration, 1e-3)) : lateAt,
    });
    if (!loop) {
      const cb = primary && typeof opts.onEnd === 'function' ? opts.onEnd : null;
      if (cb) this.animator.onFinish(cb);
    }
    if (spec.state === 'die') this._dieLen = clip.duration / Math.max(speed, 1e-3);
    this.clip = clip;
    this.clipSpec = spec;
    this._clipLoop = loop;
    this._restT = 0;
  }

  /** Hook: a clip is about to start (Player moves its weapon between stances here). */
  _onClipStart() {}

  /** No clip for the state or any fallback: keep the current pose, still honour onEnd. */
  _noClip(opts) {
    this._clipPending = false;
    if (this.state === 'die' && this.animator) this.animator.stop();     // freeze where it is
    if (typeof opts.onEnd === 'function' && opts.loop !== true) {
      this._fakeEnd = { t: Number(opts.timeLength) > 0 ? Number(opts.timeLength) : 0.3, cb: opts.onEnd };
    }
  }

  // ---------------------------------------------------------------------------------------- highlight / opacity
  _ringColor() { return 0xffd257; }

  /** Authored overhead selection marker, ground ring and subtle emissive tint. */
  setHighlight(on) {
    on = !!on;
    this.highlighted = on;
    if(on&&!this._targetMarker&&!this.disposed) this._targetMarker=new TargetMarker(this);
    this._targetMarker?.update();
    if (on && !this._ring && this.game?.worldRoot && !this.disposed) this._ring = new TargetRing(this.game.worldRoot, this._ringColor());
    if (this._ring) {
      this._ring.setColor(this._ringColor());
      this._ring.visible = on && !this.faded;
      if (on) this._updateRing();
    }
    try { this.instance?.setHighlight(on ? HIGHLIGHT_TINT : null); } catch { /* visuals optional */ }
  }

  _updateRing() {
    const r = this._ring;
    if (!r) return;
    r.visible = this.highlighted && !this.faded && !this.disposed && this.group.visible !== false;
    if (!r.visible) return;
    const w = this.game?.world;
    const heightAt = w && typeof w.heightAt === 'function' ? (x, z) => this._heightAt(x, z, this.y) : null;
    r.update(this.x, this.y, this.z, Math.max(0.55, this.radius * 1.35) * this.scale, heightAt, this.game?.time ?? 0);
  }

  /** Fade the whole body (weapons included). */
  setOpacity(a) {
    a = Math.max(0, Math.min(1, Number(a)));
    if (!Number.isFinite(a)) a = 1;
    this.opacity = a;
    try { this.instance?.setOpacity(a); } catch { /* ignore */ }
    if (this.object) this.object.visible = a > 0.001;
  }

  // ---------------------------------------------------------------------------------------- frame
  update(dt) {
    if (this.disposed) return;
    dt = Number(dt);
    if (!(dt > 0) || !Number.isFinite(dt)) dt = 0;
    this._advanceKnockback(dt);

    // smooth turning
    const d = wrapAngle(this._yawGoal - this._yaw);
    if (Math.abs(d) > 1e-4) this._yaw = wrapAngle(this._yaw + d * (1 - Math.exp(-dt * this.turnRate)));
    else this._yaw = this._yawGoal;

    // measured ground speed: gameplay code moved the actor (setPosition) before this update
    if (this._px == null) { this._px = this.x; this._pz = this.z; }
    const moved = Math.hypot(this.x - this._px, this.z - this._pz);
    this._px = this.x; this._pz = this.z;
    if (dt > 0) {
      const v = moved > 4 ? 0 : moved / dt;           // a teleport is not movement
      // Per-frame distance is noisy (frame pacing, path
      // corners, frames without a move step); smooth it properly instead of snapping to spikes
      this._moveVel = this._moveVel + (v - this._moveVel) * Math.min(1, dt * 8);
    }

    // ground (setPosition already snapped a moving actor; a standing one re-checks twice a second, e.g. for a
    // bridge / deck surface that finished loading under it)
    this._snapT = (this._snapT ?? 0) - dt;
    const _dg = globalThis.__dkT_spDiag ? performance.now() : 0;   // PERF-CROWD diagnostics (DK_T=spDiag)
    if (!this._grounded || this._snapT <= 0) { this._snapT = 0.5; this._snapY(!this._grounded); }
    this._syncGroup();
    const _dg1 = _dg ? performance.now() : 0;

    // view culling: hidden + frozen outside the draw distance / frustum (VIEW CULLING)
    let animDt = dt;
    if (this._outOfView()) {
      if (!this.culled) this._setCulled(true);
      else if (this.group.visible) { this._cullHidden = true; this.group.visible = false; }
      if (this._clipLoop || !this.animator?.current) {         // loops freeze; one-shots keep time (onEnd callbacks)
        this._skipDt = Math.min(MAX_CATCHUP, this._skipDt + dt);
        animDt = -1;
      }
    } else if (this.culled) {
      this._setCulled(false);
      animDt = dt + this._skipDt;
      this._skipDt = 0;
    }

    // ANIMATION LOD (graphics): beyond LOD_NEAR the mixer advances every 2nd frame, beyond LOD_FAR every 3rd (the
    // skipped time is carried into the next update, loops stay in phase); a body standing still on a skipped frame keeps
    // last frame's bone matrices (SkinnedInstance.freeze: no matrix walk, no skeleton upload). The player, the target
    // (highlighted) and one-shot clips near their end are never throttled.
    if (animDt >= 0 && this.instance && this.cullable) {
      const every = this._lodEvery();
      this._lodN = (this._lodN || 0) + 1;
      if (every > 1 && (this._lodN + this.id) % every !== 0) {
        this._lodAcc = (this._lodAcc || 0) + animDt;
        animDt = -1;
        const still = moved < 1e-5 && this._yaw === this._lodYaw;
        if (still && !this.instance.frozen) this.instance.freeze(true);
        else if (!still && this.instance.frozen) this.instance.freeze(false);
      } else {
        animDt += this._lodAcc || 0;
        this._lodAcc = 0;
        if (this.instance.frozen) this.instance.freeze(false);
      }
      this._lodYaw = this._yaw;
    } else if (this.instance?.frozen) this.instance.freeze(false);
    if (!this.culled) this._updateShadowCast();

    // animation
    if (this.animator && animDt >= 0) {
      if (this._locoGround > 0 && this.animator.current) {
        // The player always moves at its nominal ground speed (controller): use that constant, so the stride never
        // jitters with the measured speed. Monsters and others use the smoothed measurement.
        const nominal = Number(this._nominalSpeed?.(this.clipSpec?.state)) || 0;
        const v = nominal > 0 ? nominal : this._moveVel;
        const rate = Math.max(LOCO_RATE_MIN, Math.min(LOCO_RATE_MAX, v / this._locoGround));
        if (Math.abs(rate - this._locoRate) > 0.005) { this.animator.setSpeed(rate); this._locoRate = rate; }
      }
      const _dg2 = _dg ? performance.now() : 0;
      crowdTick(this);              // GPU crowd path on / off for this frame (before the mixer advances)
      const _dg3 = _dg ? performance.now() : 0;
      this.animator.update(animDt);
      if (_dg) { const D = (globalThis.__dkActDiag ||= {}), t = performance.now(), mx = (k, v) => { if (v > (D[k]?.[0] || 0)) D[k] = [+v.toFixed(2), this.name, this.clip?.name, animDt, this.culled]; }; mx('snap', _dg1 - _dg); mx('preAnim', _dg2 - _dg1); mx('crowdTick', _dg3 - _dg2); mx('mixer', t - _dg3); }
      if (!this._clipPending && this.clip && !this._clipLoop && this.animator.finished && this.state !== 'die' && !this.dead) {
        this._restT += animDt;     // animDt carries the frames the animation LOD skipped: REST_DELAY stays real time
        if (this._restT >= REST_DELAY) {
          this._restT = 0;
          const rest = this._restState();
          if (rest) this.play(rest, {});
        }
      }
    }
    if (this._fakeEnd) {
      this._fakeEnd.t -= dt;
      if (this._fakeEnd.t <= 0) {
        const cb = this._fakeEnd.cb;
        this._fakeEnd = null;
        try { cb(); } catch (err) { console.error('[actors] onEnd failed', err); }
      }
    }

    this._updateDeath(dt);
    if (this._ring) this._updateRing();
    this._targetMarker?.update(dt);
  }

  _updateDeath(dt) {
    if (this.dead && this.fadeOnDeath) {
      this._deathT += dt;
      const start = Math.min(Math.max(this._dieLen ?? 1.2, 0.6) + CORPSE_HOLD, CORPSE_FADE_START_MAX);
      if (this._deathT > start && !this.faded) {
        const a = 1 - (this._deathT - start) / CORPSE_FADE;
        if (a <= 0) {
          this.setOpacity(0);
          this.faded = this.removable = this.fadeDone = true;
          this.group.visible = false;
        } else this.setOpacity(a);
      }
    } else if (!this.dead && (this._deathT > 0 || this.faded)) {
      // revived
      this._deathT = 0;
      this._dieLen = null;
      this.faded = this.removable = this.fadeDone = false;
      if (this.culled) this._cullHidden = true; else this.group.visible = true;
      this.setOpacity(1);
    }
  }

  dispose() {
    if (this._visualDisposed) { this.disposed = true; return; }
    this._visualDisposed = true;
    this.disposed = true;
    this._pendingPlay = null;
    this._fakeEnd = null;
    try { this.animator?.dispose(); } catch { /* ignore */ }
    try { this.instance?.dispose(); } catch { /* ignore */ }
    this.object?.removeFromParent();
    this._ring?.dispose();
    this._targetMarker?.dispose();
    this._targetMarker = null;
    this._ring = null;
    this.group.removeFromParent();
    this.animator = null;
    this.target = null;
  }
}
