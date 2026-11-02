// Dekaron-style player controls (FILE frame throughout; only the camera basis is converted).
//
//   Left-click ground      path-find there and run (holding the button keeps re-pathing to the cursor)
//   Left-click monster     target it, run into weapon range, then auto-attack with the class combo
//                          (classes.json combo: step timeLength / attack speed; damage at `timing`, the next step
//                          starts at `timing2`; the 5-step chain loops while the target lives, then idleCombat)
//   Shift + left-click     attack in place (never moves; hits only land when the target is within reach)
//   Left-click NPC         walk to it, then open its window (game.windows.openNpc)
//   Left-click a drop      walk to it and pick it up
//   WASD / left gamepad stick   camera-relative running, blocked by world.isWalkable (slides along walls)
//   Tab                    nearest living monster (again: next nearest)
//   Esc / right-click on empty ground   clear the target
//   1..0                   hotbar skills (game.skills.use(slot))
//   Z (Space by default)   pick up ONE drop per press: the nearest one in reach, else walk to the nearest one; a press while
//                          that pickup is still walking / waiting is ignored (no second item, no new target)
// Input is ignored while a window captures it or the player is dead; orders already running keep going.
import { combatOptionValue,resolveAttack, applyDamage, playOnce, playLoop, resetAnimState, isAlive, dist2, rand } from './combat.js';
import { playerDefeatReaction, eventDefeat, defeatSeconds } from './hit-reaction.js';
import {NORMAL_ATTACK_CONTACT as NORMAL_CONTACT} from '../config/engine-chosen-normal-attack.js';
import { comboStepTiming } from './attack-timing.js';
import { authoritativeAttackStep } from './attack-recovery.js';
import { MoveMarker } from '../actors/movemarker.js';
import { rootMotionCurves, attackStepAnim, startRootRun, advanceRootRuns, rootToWorld, sweepRoot } from '../systems/skills/root-motion.js';
import { MOVEMENT_SYNC } from '../systems/network/movement-config.js';

// Current engines expose holdsBody; older source snapshots expose active.
const skillOwnsBody = game => !!(game?.skills?.holdsBody || game?.skills?.active);

const HOLD_REPATH = 0.2;       // s between re-paths while the left button is held on the ground
const CHASE_REPATH = 0.5;      // s between re-paths while chasing a target around obstacles
const NPC_REACH = 3.2;
const PICKUP_REACH = 1.3;
const PICKUP_ORDER_MAX = 8;    // s a walking pickup order blocks further presses of the pickup key (a stuck walk must not lock it)
const TAB_RANGE = 30;
const STANCE_SECONDS = 10;     // battle stance lingers this long after the last hit
const TARGET_CLEAR_DELAY = 2.5; // s a dead target stays selected
const DIGITS = ['Digit1', 'Digit2', 'Digit3', 'Digit4', 'Digit5', 'Digit6', 'Digit7', 'Digit8', 'Digit9', 'Digit0'];
const DEFAULT_COMBO = [{ timeLength: 0.8, timing: 0.5, timing2: 1 }];
const AIM_WINDOW = 0.5;        // s of target motion the walking-target velocity is measured over
const AIM_MIN_SPAN = 0.2;      // s of history before a velocity is trusted (a standing target reads as 0)
const LEAD_RTT_MAX = 0.3;      // s of measured host round trip folded into the swing lead
const SWING_POSE_AGE = 0.1;    // s the newest host pose of a target can already be old (the host publishes every 100 ms)
const SWING_MARGIN = 0.12;     // cells of slack on top of the measured walk-away lead (velocity noise, frame pacing)
const SWING_MIN_REACH = 0.4;   // a swing never needs the body closer than this fraction of its normal reach

export class PlayerController {
  constructor(game) {
    this.game = game;
    this.order = null;    // {type:'move'|'attack'|'npc'|'pickup'|'approach', ...}
    this.combo = null;    // current basic-attack swing
    this._prevHeld = false;
    this._pressHandled = false;
    this._holdMove = false;
    this._holdTimer = 0;
    this._wasd = false;
    this._inputIntentRevision = 0; // Explicit input invalidates a skill awaiting movement acceptance.
    this._moveClick = null;
    this._attackRuns = [];  // basic-attack swings still carrying the body along their clip root curve
    this._attackRootEpoch = 0;
  }

  get player() { return this.game?.player || null; }
  get now() { return this.game?.time || 0; }

  // ---------------------------------------------------------------- helpers
  _walkable(x, z) {
    const w = this.game?.world;
    return w && typeof w.isWalkable === 'function' ? w.isWalkable(x, z) : true;
  }
  _lineClear(ax, az, bx, bz) {
    const collision = this.game?.world?.collision;
    if (collision?.lineOfSight) return collision.lineOfSight(ax, az, bx, bz);
    const d = Math.hypot(bx - ax, bz - az);
    const n = Math.ceil(d / 0.5);
    for (let i = 1; i <= n; i++) {
      const t = i / n;
      if (!this._walkable(ax + (bx - ax) * t, az + (bz - az) * t)) return false;
    }
    return true;
  }
  _findPath(x, z) {
    const p = this.player, w = this.game?.world;
    if(this._walkable(x,z)&&this._lineClear(p.x,p.z,x,z))return [{x,z}];
    let path = null;
    if (w && typeof w.findPath === 'function') {
      try { path = w.findPath(p.x, p.z, x, z); } catch (err) { console.warn('findPath failed', err); }
    }
    if ((!path || !path.length) && this._walkable(x, z) && this._lineClear(p.x, p.z, x, z)) path = [{ x, z }];
    return path && path.length ? path.map(q => ({ x: q.x, z: q.z })) : null;
  }
  /** Walk to an NPC: its placement interact point (npc.js interactPoint: the original warp/talk point, walkable, on
   *  the NPC's open side) - an NPC usually stands on a blocked cell, so pathing to its own cell can snap to the wrong
   *  side of a counter/wall or fail for a far NPC. Falls back to the NPC position. */
  _npcOrder(npc) {
    const ip = npc.interactPoint;
    const usable = ip && Number.isFinite(ip.x) && Number.isFinite(ip.z) && this._walkable(ip.x, ip.z);
    const path = (usable ? this._findPath(ip.x, ip.z) : null) || this._findPath(npc.x, npc.z);
    return { type: 'npc', npc, goal: usable ? { x: ip.x, z: ip.z } : null, path, i: 0 };
  }
  _inputBlocked() {
    const w = this.game?.windows;
    if (!w) return false;
    if (typeof w.capturesInput === 'boolean') return w.capturesInput;
    return !!w.anyOpen;
  }
  _stats() { return this.player?.stats || {}; }
  /** Run speed: the root-motion speed of the run clip of the current stance x buffs x map factor (Player.groundSpeed). */
  _speed() {
    const p = this.player;
    const v = typeof p?.groundSpeed === 'function' ? p.groundSpeed('run') : 0;
    return v > 0 ? v : (this._stats().moveSpeed || 3.445);
  }
  _runOpts() { return { moveSpeed: this._speed() }; }
  reachFor(target) {
    const p = this.player;
    const reach = (this._stats().attackRange || 2) + (target?.radius || 0.5) * 0.8 + (p?.radius || 0.4) * 0.25 + 0.2;
    return this.game.network?.active ? Math.min(reach, this._sharedAttackRange()) : reach;
  }
  _sharedAttackRange() { return Math.min(8, this._stats().attackRange || 5) + 0.5; }
  _sharedAttackTarget(target) {
    const pose = target?._serverPose;
    return Number.isFinite(pose?.tx) && Number.isFinite(pose?.tz) ? { x: pose.tx, z: pose.tz } : target;
  }
  /** Client-predicted movement mode (MOVE-NO-RUBBERBAND): the host adopts the pose this client reports for its own body, so
   *  the local body IS the position the host will measure from. The host echo (net.self) lags the body by about a round trip. */
  _bodyIsAuthoritative() {
    const net = this.game.network;
    return !!(net?.active && Number.isInteger(net.self?.posRev));
  }
  /** The single point the chase and the range test aim at. Client-predicted: the host's newest pose of the target (a mover's
   *  shown pose trails it), so "arrived" and "in range" can never disagree. Host-driven movement: the shown actor, as before. */
  _attackAim(target) { return this._bodyIsAuthoritative() ? this._sharedAttackTarget(target) : target; }
  _sharedAttackInRange(target) {
    const net = this.game.network;
    if (!net?.active || !net.self) return true;
    return dist2(this._bodyIsAuthoritative() ? this.player : net.self, this._sharedAttackTarget(target)) <= this._sharedAttackRange();
  }
  // PVP-DUEL: a duel opponent is a valid enemy while the host's duel is in its fight phase (game.isPvpHostile).
  _validEnemy(t) { return isAlive(t) && (t.kind === 'monster' || (t.kind === 'player' && t !== this.player && !!this.game?.isPvpHostile?.(t))); }
  _comboSteps() {
    const c = this.game?.classDef;
    return (c?.combo?.length ? c.combo : c?.anims?.attack?.length ? c.anims.attack : DEFAULT_COMBO);
  }
  /** Timing of combo step k (the clip is stretched to `len`; damage at `hitAt`, the next step may start at `next`).
   *  src/game/attack-timing.js: the shared-world host admits hits by the same numbers. */
  _stepTiming(k) {
    const steps = this._comboSteps();
    return { n: steps.length, ...comboStepTiming(steps[k % steps.length], this._stats().attackSpeed) };
  }
  _attackPhaseKey() {
    const c = this.game.classDef, s = this.game.network?.self;
    return `${s?.map}|${s?.instanceId}|${s?.channel ?? 0}|${c?.index}|${c?.style}|${this._comboSteps().length}`;
  }
  _resumeAttackStep() {
    const net = this.game.network;
    if (!net?.active) return 0;
    // A new target is a new order, not a fresh host combo. Resolve outstanding
    // hits before choosing its phase; stop/target clicks cannot erase recovery.
    if (net._attackPending > 0) return null;
    const authoritative = authoritativeAttackStep(net, this.game.save?.id, this.game.classDef, this._comboSteps().length);
    if (authoritative !== undefined) return authoritative;
    const phase = this._acceptedAttackPhase;
    if (!phase || phase.player !== this.player || phase.net !== net || phase.token !== net.token) return 0;
    if (performance.now() < phase.nextAt) return null;
    return phase.key === this._attackPhaseKey() ? (phase.step + 1) % this._comboSteps().length : 0;
  }
  _attackSettlement(c) {
    const player = this.player, net = this.game.network, token = net.token, key = this._attackPhaseKey();
    const sequence = this._attackReceiptSequence = (this._attackReceiptSequence || 0) + 1;
    return accepted => {
      if (!accepted || player !== this.player || net !== this.game.network || token !== net.token ||
          sequence <= (this._acceptedAttackPhase?.sequence || 0)) return;
      this._acceptedAttackPhase = { player, net, token, key, sequence, step: c.k,
        nextAt: performance.now() + Math.max(0, c.next - c.hitAt) * 1000 };
    };
  }
  /** Velocity (u/s) of the point the attack aims at (the target's newest host pose, else its shown pose), least-squares slope
   *  over the last AIM_WINDOW seconds: the host pose arrives in steps every 100 ms, so two end points would read it 10-25 %
   *  slow depending on where in a step they fall. 0 until it has been watched for AIM_MIN_SPAN (a standing target reads 0).
   *  Fed every frame of an attack order, swinging or chasing. */
  _trackAim(t, aim) {
    let tr = this._aimTrack;
    if (!tr || tr.t !== t) tr = this._aimTrack = { t, s: [], vx: 0, vz: 0 };
    const s = tr.s, now = this.now;
    if (s.length && now - s[s.length - 1].at > AIM_WINDOW) s.length = 0; // tracking paused (skill, WASD, ...): old samples say nothing about now
    s.push({ at: now, x: aim.x, z: aim.z });
    while (s.length > 2 && now - s[0].at > AIM_WINDOW) s.shift();
    tr.vx = tr.vz = 0;
    if (s.length < 3 || now - s[0].at < AIM_MIN_SPAN) return;
    let mt = 0, mx = 0, mz = 0;
    for (const q of s) { mt += q.at; mx += q.x; mz += q.z; }
    mt /= s.length; mx /= s.length; mz /= s.length;
    let vt = 0, cx = 0, cz = 0;
    for (const q of s) { const dt = q.at - mt; vt += dt * dt; cx += dt * (q.x - mx); cz += dt * (q.z - mz); }
    if (vt > 1e-9) { tr.vx = cx / vt; tr.vz = cz / vt; }
  }
  /** How much further from the (standing) body the target's aim point is when the HIT FRAME of combo step k lands than it is
   *  now: its measured walk over the wind-up, the host pose age (SWING_POSE_AGE) and the host round trip, plus a little margin.
   *  0 for a standing target or one walking closer. A swing begun at the very edge of reach on a target that keeps walking
   *  away finishes its animation but its hit never lands (the host judges range again at the hit frame; its contact allowance
   *  is only 0.5 cell), so the chase aims to start the swing this much nearer. */
  _swingLead(t, aim, k = 0) {
    const tr = this._aimTrack;
    if (!tr || tr.t !== t || (!tr.vx && !tr.vz)) return 0;
    const p = this.player, net = this.game?.network;
    const rtt = net?.active ? Math.min(LEAD_RTT_MAX, Math.max(0, Number(net._moveRoundTrip) || 0) / 1000) + SWING_POSE_AGE : 0;
    const T = this._stepTiming(k).hitAt + rtt;
    const lead = Math.hypot(aim.x + tr.vx * T - p.x, aim.z + tr.vz * T - p.z) - dist2(p, aim);
    return lead > 0 ? lead + SWING_MARGIN : 0;
  }
  /** Distance to the aim point at which a swing of step k should start: the normal reach less the target's walk-away lead. */
  _swingReach(t, aim, reach, k = 0) {
    return Math.max(reach * SWING_MIN_REACH, reach - this._swingLead(t, aim, k));
  }

  /** Move the player up to `dist` towards (tx, tz); returns the distance left to the point. */
  _advance(tx, tz, dist) {
    const p = this.player;
    const dx = tx - p.x, dz = tz - p.z;
    const d = Math.hypot(dx, dz);
    if (d < 1e-4) return 0;
    p.faceTowards(tx, tz);
    if (this.game.network?.active) {
      // The host receives the local path one corner at a time (the next waypoint): the host A* has a smaller search
      // budget (server/world/data.mjs 20000 nodes) and reaches only 63-79 % of the far destinations the client paths
      // (measured on maps 150/7/0, test-npc-click-pathing), so a whole far destination would stop short; a near
      // corner is always reachable and the host never waits at one (worst measured stall 8 ms).
      this.game.network.move(tx, tz);
      this.game.network.predictAdvance?.(tx, tz, dist);
      return Math.hypot(tx-p.x,tz-p.z);
    }
    if (dist >= d) { p.setPosition(tx, tz); return 0; }
    p.setPosition(p.x + (dx / d) * dist, p.z + (dz / d) * dist);
    return d - dist;
  }
  /** Follow o.path; returns true when the end is reached. */
  _followPath(o, dt) {
    const p = this.player;
    let budget = this._speed() * dt;
    while (budget > 1e-6 && o.i < o.path.length) {
      const w = o.path[o.i];
      const d = Math.hypot(w.x - p.x, w.z - p.z);
      if (d <= budget) {
        const remaining = this._advance(w.x, w.z, d);
        if (this.game.network?.active && remaining > 1e-4) { budget = 0; break; }
        budget -= d; o.i++;
      } else { this._advance(w.x, w.z, budget); budget = 0; }
    }
    playLoop(p, 'run', this._runOpts(), this.now, true);
    return o.i >= o.path.length;
  }
  /** Move towards a (possibly moving) actor until within `reach`. Returns true when in reach. */
  _approachActor(o, target, reach, dt) {
    const p = this.player;
    const d = dist2(p, target);
    if (d <= reach) return true;
    if (this._lineClear(p.x, p.z, target.x, target.z)) {
      o.path = null;
      this._advance(target.x, target.z, Math.min(this._speed() * dt, d - reach * 0.9));
      playLoop(p, 'run', this._runOpts(), this.now, true);
      return false;
    }
    const goalMoved = !o.goal || Math.hypot(o.goal.x - target.x, o.goal.z - target.z) > 1.5;
    if (!o.path || o.i >= o.path.length || (this.now >= (o.repathAt || 0) && goalMoved)) {
      o.path = this._findPath(target.x, target.z);
      o.i = 0;
      o.goal = { x: target.x, z: target.z };
      o.repathAt = this.now + CHASE_REPATH;
      if (!o.path) { o.fail = (o.fail || 0) + 1; return false; }
    }
    this._followPath(o, dt);
    return dist2(p, target) <= reach;
  }

  // ---------------------------------------------------------------- public API
  setTarget(actor) {
    const g = this.game, p = this.player;
    if (!p) return;
    // other players are selectable in the shared world (target plate -> pcpop player menu, PVP-DUEL); never yourself
    if (actor && actor.kind === 'player' && (actor === p || !g.network?.active)) actor = null;
    if (p.target === actor) return;
    this._cancelUnsentAttackRoots();
    this._inputIntentRevision++;
    try { p.target?.setHighlight?.(false); } catch { /* ignore */ }
    p.target = actor || null;
    try { actor?.setHighlight?.(true); } catch { /* ignore */ }
    g.events?.emit('target', { actor: actor || null });
  }

  stop() {
    this._moveClick?.dispose();this._moveClick=null;
    this._cancelUnsentAttackRoots();
    this._inputIntentRevision++;
    if (this.game.network?.active) this.game.network.stop();
    this.order = null;
    this.combo = null;
    this._holdMove = false;
    this._attackRuns.length = 0;
  }

  /** Path-find to (x, z) and run there. */
  moveTo(x, z) {
    this._cancelUnsentAttackRoots();
    this._inputIntentRevision++;
    const path = this._findPath(x, z);
    this.combo = null;
    if (!path) { this.order = null; return false; }
    this.order = { type: 'move', path, i: 0 };
    if(this.game.network?.active){const goal=path[0];this.game.network.move(goal.x,goal.z);}
    this.game?.events?.emit('moveorder', { x: path[path.length - 1].x, z: path[path.length - 1].z });
    return true;
  }

  attack(target, { inPlace = false } = {}) {
    if (!this._validEnemy(target)) return false;
    this._cancelUnsentAttackRoots();
    this._inputIntentRevision++;
    this.setTarget(target);
    if (this.order?.type === 'attack' && this.order.target === target) { this.order.inPlace = inPlace; return true; }
    this.combo = null;
    this.order = { type: 'attack', target, inPlace, path: null, i: 0 };
    return true;
  }

  /** Walk into `range` of target, then call onArrive (used by skills). */
  approach(target, range, onArrive, options = {}) {
    this._cancelUnsentAttackRoots();
    this._attackRootEpoch++;
    const resume = null; // A skill owns this approach; it does not start basic attacks afterward.
    this.combo = null;
    this.order = { type: 'approach', target, range, onArrive, resume, path: null, i: 0, ...options };
  }

  cycleTarget() {
    const p = this.player;
    const list = (this.game.network?.active ? [...this.game.network.monsters.values()] : this.game?.spawner?.monsters || [])
      .filter(m => isAlive(m) && dist2(m, p) <= TAB_RANGE)
      .sort((a, b) => dist2(a, p) - dist2(b, p));
    if (!list.length) return null;
    const i = list.indexOf(p.target);
    const next = i >= 0 ? list[(i + 1) % list.length] : list[0];
    this.setTarget(next);
    return next;
  }

  /** The pickup key (Space): ONE press = ONE drop. A drop in reach is taken at once (online: one request); otherwise the
   *  character walks to the nearest one. While that pickup is still walking, or its request is unanswered, further presses
   *  do nothing: no second drop, no new target (no bouncing from item to item). The next press takes the next drop. */
  pickupNearby() {
    const g = this.game, p = this.player, loot = g?.loot;
    if (!p || !loot) return 0;
    const o = this.order;
    if (o?.type === 'pickup' && loot.drops?.includes(o.drop) && this.now - (o.at ?? this.now) < PICKUP_ORDER_MAX) return 0;
    const n = loot.pickupNearby?.() || 0;
    // Network pickup is asynchronous: 0 does not mean nothing was requested.
    if (n || loot.pickupBusy?.()) return n;
    const d = loot.pickupOrder ? loot.pickupOrder(p.x, p.z, 12)[0] : loot.nearest?.(p.x, p.z, 12);
    if (d) { this.combo = null; this.order = { type: 'pickup', drop: d, path: this._findPath(d.x, d.z), i: 0, at: this.now }; }
    else if (!n && loot.reservedNear?.(p.x, p.z, 12)) loot._msg?.('This drop is temporarily reserved for its owner.');
    return n;
  }

  /** Esc: clear the target (and an attack / approach order). Returns true when something was cleared. game.js opens the
   *  system menu on the same press (2.2.1; guide_info_system.txt 1301:1 + shortkey.txt SYSTEMMENU esc). */
  onEscape() {
    this._inputIntentRevision++;
    const p = this.player;
    if (p?.target) {
      this.setTarget(null);
      if (this.order?.type === 'attack' || this.order?.type === 'approach') { this.order = null; this.combo = null; }
      return true;
    }
    return false;
  }

  // ---------------------------------------------------------------- callbacks from other systems
  onSkillStart() {
    this._clearDirectionalState();
    this._cancelUnsentAttackRoots();
    this._attackRootEpoch++;
    this.combo = null;
    this.order = null;
    this._holdMove = false;
  }
  onSkillEnd(skill, target) {
    // Skill completion leaves auto-attack cancelled until another explicit attack.
  }

  onDamaged(source, amount, event) {
    const p = this.player;
    if (!p || p.dead || !(amount>0)) return;
    // Online the host picks the DEFEAT row once for the victim and every observer (event.defeat; absent =
    // no reaction); offline the same rule rolls locally. The body is held for that row's TimeLength (classes.json).
    const variant = this.game?.network?.active ? eventDefeat(event) : playerDefeatReaction({defeatResistance:combatOptionValue(p,'DEFENSE_DEFEATRATE_MUL')},rand);
    if (variant == null) return;
    const idle = !this.order && !this.combo && !this._wasd && !skillOwnsBody(this.game);
    if (idle) playOnce(p, 'hit', { variant }, this.now, defeatSeconds(p, variant));
  }
  onPlayerDeath() {
    this.stop();
    this._wasd = false;
  }

  // ---------------------------------------------------------------- per frame
  update(dt) {
    const g = this.game, p = this.player, inp = g?.input;
    this._updateMoveClick(dt);
    if (!p) return;
    if (g.network?.active && !g.network.ready) {
      this.order = null; this.combo = null; this._wasd = false; this._holdMove = false; this._attackRuns.length = 0;
      this._idle(); return;
    }
    if (p.dead) {
      this._attackRuns.length = 0;
      if (this.order || this.combo) this.stop();
      this._prevHeld = !!inp?.held?.left;
      return;
    }
    if (p._gpState === 'die') resetAnimState(p); // revived by game.revive()
    // Hold the seller while their shop is operating, and a buyer only while another player's shop window is open.
    if (g.network?.pcShop?.open === true || g.personalShop?.viewOpen?.()) {
      if (this.order || this.combo || this._wasd) { if (this._wasd && g.network?.active) g.network.stop(); this.order = null; this.combo = null; this._wasd = false; this._holdMove = false; }
      this._pressHandled = false; this._prevHeld = !!inp?.held?.left;
      return;
    }
    this._maintainTarget();

    if (inp) {
      if (inp.hit?.('Escape')) this.onEscape();
      if (!this._inputBlocked()) this._handleInput(dt, inp);
      else if (g.windows?.allowsDirectionalMovement) {
        this._holdMove = false; this._pressHandled = false;
        this._handleDirectionalInput(dt, inp);
      } else { if (this._wasd && g.network?.active) g.network.stop(); this._holdMove = false; this._wasd = false; this._pressHandled = false; }
      this._prevHeld = !!inp.held?.left;
    }

    this._advanceAttackRoot(dt);
    if (skillOwnsBody(g)) return; // skillMotion / holdsBody: every phase + attackHoldUntil owns the body (not just NO_CANCEL)
    if (this._wasd) return;
    this._runOrder(dt);
  }

  // BASIC-ATTACK ROOT MOTION: Global's share/movecache.csv lists the normal-attack combo clips as moving clips (e.g.
  // Swordmans LSW ATTACK_01..05: 6.7 m forward over the combo, each step starting where the last one ended). Every swing
  // carries the body along its own clip's whole root curve (root-motion.js), stretched over the step length, in the facing
  // the swing started with; walls stop it (0.1 m sweep). Input movement, an explicit stop, a skill or death end the runs.
  // Online the host moves the canonical record along the same curve when it accepts the hit (attack-root-motion.mjs).
  _startAttackRoot(k, len) {
    const p = this.player, curve = rootMotionCurves.get(attackStepAnim(p?.classDef || this.game?.classDef, k));
    if (!curve) return null;
    const run = startRootRun(this._attackRuns, curve, Number(p.yaw) || 0, len), net = this.game.network;
    if (run && net?.active) run.prediction = {
      status: 'windup', x: 0, z: 0, controller: this, player: p, network: net, world: this.game.world,
      intent: this._inputIntentRevision, epoch: this._attackRootEpoch, revision: net.self?.posRev,
      lease: net.token, leaseGeneration: net._leaseGeneration, map: net.self?.map,
      instance: net.self?.instanceId, channel: net.self?.channel,
    };
    return run;
  }
  /** Settle only this swing's prediction. Never move a new actor/scene/intent for a late reply. */
  settleAttackRoot(run, accepted) {
    const r = run?.prediction;
    if (!r || r.controller !== this || r.status === 'accepted' || r.status === 'rejected') return;
    r.status = accepted ? 'accepted' : 'rejected';
    if (accepted) return;
    const i = this._attackRuns.indexOf(run); if (i >= 0) this._attackRuns.splice(i, 1);
    const p = this.player, net = this.game.network;
    if (p !== r.player || p?.dead || p?.disposed || net !== r.network || !net?.ready ||
        this.game.world !== r.world || this._inputIntentRevision !== r.intent || this._attackRootEpoch !== r.epoch ||
        net.token !== r.lease || net._leaseGeneration !== r.leaseGeneration || net.self?.posRev !== r.revision ||
        net.self?.map !== r.map || net.self?.instanceId !== r.instance || net.self?.channel !== r.channel) return;
    const x = p.x - r.x, z = p.z - r.z;
    if ((Math.abs(r.x) > 1e-9 || Math.abs(r.z) > 1e-9) && this._walkable(x, z) && this._lineClear(p.x, p.z, x, z)) p.setPosition(x, z);
  }
  _cancelUnsentAttackRoots() {
    for (const run of [...this._attackRuns]) if (run.prediction?.status === 'windup') this.settleAttackRoot(run, false);
  }
  _advanceAttackRoot(dt) {
    const runs = this._attackRuns, p = this.player, o = this.order;
    if (!runs.length || !p) return;
    if (p.dead || this.game?.skills?.active || this._wasd || (o && o.type !== 'attack')) { runs.length = 0; return; }
    const before = runs.filter(r => r.prediction && r.prediction.status !== 'accepted').map(run => ({run, x:run.lx, z:run.lz}));
    const d = advanceRootRuns(runs, dt);
    const to = sweepRoot(p.x, p.z, d.x, d.z, (x, z) => this._walkable(x, z));
    // Preserve the existing summed/swept motion. Attribute only the fraction actually travelled
    // to each pending swing, including a run that completed before its HTTP answer arrived.
    // Opposite simultaneous curves may sum to zero; retain both contributions so refusing one
    // still leaves the accepted swing's displacement, rather than losing both receipts.
    const distance = Math.hypot(d.x,d.z);
    const fraction = distance > 1e-9 ? Math.min(1, Math.hypot(to.x-p.x,to.z-p.z) / distance) : 1;
    for (const old of before) {
      const run = old.run, delta = rootToWorld(run.lx-old.x,run.lz-old.z,run.yaw), receipt = run.prediction;
      receipt.x += delta.x*fraction; receipt.z += delta.z*fraction;
    }
    if (to.x === p.x && to.z === p.z) return;
    p.setPosition(to.x, to.z);
    this._attackRootAt = this.now;
  }
  /** A swing is carrying the body, or did within `seconds` (network reconciliation keeps the local body meanwhile). */
  attackRootHolding(seconds = 0.3) {
    return this._attackRuns.length > 0 || this.now - (this._attackRootAt ?? -Infinity) < seconds;
  }

  _maintainTarget() {
    const p = this.player, t = p.target;
    if (!t) return;
    if (t.disposed || (t.dead && this.now - (t.diedAt ?? this.now) > TARGET_CLEAR_DELAY)) this.setTarget(null);
  }

  _handleInput(dt, inp) {
    const g = this.game, p = this.player;
    if (inp.hit('Tab')) this.cycleTarget();
    for (let i = 0; i < DIGITS.length; i++) if (inp.hit(DIGITS[i])) g.skills?.use(i);
    if (inp.hit('KeyZ')) this.pickupNearby();

    // mouse: act on the press (so holding keeps moving); quick clicks between frames arrive as clicks
    const held = !!inp.held?.left;
    const shift = inp.down('ShiftLeft') || inp.down('ShiftRight');
    if (held && !this._prevHeld) {
      this._press({ x: inp.mouse.nx, y: inp.mouse.ny }, shift);
      this._pressHandled = true;
    }
    let leftClick = false;
    for (const c of inp.clicks || []) {
      if (c.button === 'left') {
        leftClick = true;
        if (this._pressHandled) this._pressHandled = false;
        else this._press({ x: c.nx, y: c.ny }, !!c.shift);
      } else if (c.button === 'right') {
        const a = g.pickActor?.({ x: c.nx, y: c.ny });
        if (!a) {
          this.setTarget(null);
          if (this.order?.type === 'attack' || this.order?.type === 'approach') { this.order = null; this.combo = null; }
        }
      }
    }
    if (!held) { this._holdMove = false; if (!leftClick) this._pressHandled = false; }
    if (held && this._holdMove && !skillOwnsBody(g)) {
      this._holdTimer -= dt;
      if (this._holdTimer <= 0) {
        this._holdTimer = HOLD_REPATH;
        const gp = g.pickGround?.({ x: inp.mouse.nx, y: inp.mouse.ny });
        if (gp && Math.hypot(gp.x - p.x, gp.z - p.z) > 0.3 && this.moveTo(gp.x, gp.z)) this._showMoveClick(gp.x,gp.z);
      }
    }

    this._handleDirectionalInput(dt, inp);
  }

  _clearDirectionalState() {
    this._wasd = false;
    this._wasdReleaseAt = 0;
    this._wasdDx = this._wasdDz = null;
    this._directBlocked = false;
  }

  _handleDirectionalInput(dt, inp) {
    const g = this.game, p = this.player;
    // Skill animation/root motion owns this frame; release debounce is not a
    // fresh movement intent and must never force run or send a stop over it.
    if (skillOwnsBody(g)) { this._clearDirectionalState(); return; }
    // Keyboard, touch and left gamepad stick share camera-relative movement.
    // groundBasis() is THREE space: FILE = (x, -z).
    const fwd = Math.max(-1, Math.min(1, (inp.down('KeyW') ? 1 : 0) - (inp.down('KeyS') ? 1 : 0) + (inp.mobile?.moveY || 0) + (inp.gamepad?.moveY || 0)));
    const side = Math.max(-1, Math.min(1, (inp.down('KeyD') ? 1 : 0) - (inp.down('KeyA') ? 1 : 0) + (inp.mobile?.moveX || 0) + (inp.gamepad?.moveX || 0)));
    if ((fwd || side) && !skillOwnsBody(g)) {
      const b = g.cam?.groundBasis?.();
      let dx, dz;
      if (b) {
        dx = b.forward.x * fwd + b.right.x * side;
        dz = -(b.forward.z * fwd + b.right.z * side);
      } else { dx = side; dz = fwd; }
      const len = Math.hypot(dx, dz);
      if (len > 1e-6) {
        dx /= len; dz /= len;
        if (!this._wasd) { this._cancelUnsentAttackRoots(); this._inputIntentRevision++; }
        this.order = null;
        this.combo = null;
        this._holdMove = false;
        this._wasd = true;
        this._wasdDx = dx; this._wasdDz = dz; this._wasdReleaseAt = 0;
        this._stepDirect(dx, dz, this._speed() * dt);
        playLoop(p, 'run', this._runOpts(), this.now, true);
      }
    } else if (this._wasd) {
      // MOVE-NO-RUBBERBAND: ignore sub-frame WASD gaps (A/S or W/S spam) — keep last heading briefly, then stop.
      const now = performance.now();
      if (!this._wasdReleaseAt) this._wasdReleaseAt = now;
      const debounce = Number(MOVEMENT_SYNC?.WASD_RELEASE_DEBOUNCE_MS) || 66;
      if (now - this._wasdReleaseAt < debounce && this._wasdDx != null) {
        this._stepDirect(this._wasdDx, this._wasdDz, this._speed() * dt);
        playLoop(p, 'run', this._runOpts(), this.now, true);
      } else {
        this._wasd = false;
        this._wasdReleaseAt = 0;
        this._wasdDx = this._wasdDz = null;
        this._directBlocked = false;
        if (this.game.network?.active) this.game.network.stop();
      }
    }
  }

  /** Direct movement with wall sliding. */
  _stepDirect(dx, dz, s) {
    const p = this.player;
    p.faceTowards(p.x + dx, p.z + dz);
    if (this.game.network?.active) {
      // Held directional input owns facing immediately. Click/attack turns and
      // remote actors keep their authored/normal turn interpolation.
      if(Number.isFinite(p.targetYaw))p.yaw=p.targetYaw;
      // Resolve the same wall slide as solo movement before sending a goal.
      // A blocked short goal would otherwise snap behind the player in A*.
      const clear=(x,z)=>this._walkable(x,z)&&this._lineClear(p.x,p.z,x,z);
      let mx=dx,mz=dz;
      if(!clear(p.x+mx*s,p.z+mz*s)){
        if(Math.abs(dx)>.15&&clear(p.x+dx*s,p.z))mz=0;
        else if(Math.abs(dz)>.15&&clear(p.x,p.z+dz*s))mx=0;
        else{if(!this._directBlocked)this.game.network.stop?.();this._directBlocked=true;return false;}
      }
      this._directBlocked=false;
      let distance=this._speed()*.3;
      if(!clear(p.x+mx*distance,p.z+mz*distance)){
        let low=0,high=distance;
        for(let i=0;i<16;i++){const mid=(low+high)/2;if(clear(p.x+mx*mid,p.z+mz*mid))low=mid;else high=mid;}
        distance=low;
      }
      const tx=p.x+mx*distance,tz=p.z+mz*distance;
      this.game.network.move(tx, tz, { direct: true });
      // The server advances a reachable goal at its canonical run speed, including
      // tangent goals. Prediction must use that same speed to avoid drift at walls.
      return this.game.network.predictAdvance?.(tx, tz, s) || false;
    }
    const nx = p.x + dx * s, nz = p.z + dz * s;
    if (this._walkable(nx, nz)&&this._lineClear(p.x,p.z,nx,nz)) { p.setPosition(nx, nz); return true; }
    if (Math.abs(dx) > 0.15 && this._walkable(nx, p.z)&&this._lineClear(p.x,p.z,nx,p.z)) { p.setPosition(nx, p.z); return true; }
    if (Math.abs(dz) > 0.15 && this._walkable(p.x, nz)&&this._lineClear(p.x,p.z,p.x,nz)) { p.setPosition(p.x, nz); return true; }
    return false;
  }

  _press(ndc, shift) {
    const g = this.game;
    const drop = g.loot?.pickAt?.(ndc);
    if (drop) {
      this.combo = null;
      this._holdMove = false;
      this.order = { type: 'pickup', drop, path: this._findPath(drop.x, drop.z), i: 0, at: this.now };
      return;
    }
    const a = g.pickActor?.(ndc);
    if (a && a.kind === 'monster' && isAlive(a)) {
      this._holdMove = false;
      if (shift || this.player.target === a) this.attack(a, { inPlace: shift });
      else { this.stop(); this.setTarget(a); }
      return;
    }
    // shared world: click another player = select (target plate); a duel opponent is attacked like a monster
    if (a && a.kind === 'player' && a !== this.player && isAlive(a) && g.network?.active) {
      this._holdMove = false;
      if (!shift && !g.network?.fieldPk?.isEnemy?.(a) && g.personalShop?.requestBrowse?.(a)) return;
      if (this._validEnemy(a) && (shift || this.player.target === a || g.network?.fieldPk?.isEnemy?.(a))) this.attack(a, { inPlace: shift });   // Ctrl (Force Attack) attacks a player at once
      else { this.stop(); this.setTarget(a); }
      return;
    }
    if (a && a.kind === 'npc') {
      this._holdMove = false;
      this.combo = null;
      if (this.order?.type === 'npc' && this.order.npc === a) return;
      this.order = this._npcOrder(a);
      return;
    }
    const gp = g.pickGround?.(ndc);
    if (gp) {
      if (this.moveTo(gp.x, gp.z)) this._showMoveClick(gp.x, gp.z);
      this._holdMove = true;
      this._holdTimer = HOLD_REPATH;
    }
  }

  _showMoveClick(x, z) {
    const g = this.game;
    if (!g?.worldRoot || !Number.isFinite(x) || !Number.isFinite(z)) return;
    if(this._moveClick?.disposed||this._moveClick?.world!==g.world){this._moveClick?.dispose();this._moveClick=null;}
    this._moveClick ||= new MoveMarker(g);
    this._moveClick.show(x,z);
  }

  _updateMoveClick(dt) {
    const g=this.game,p=this.player;
    const held=this._holdMove&&!!g.input?.held?.left&&!skillOwnsBody(g)&&!this._inputBlocked();
    if(!p||p.dead||p.disposed||(g.network?.active&&!g.network.ready)||(!held&&this.order?.type!=='move')){
      this._moveClick?.dispose();this._moveClick=null;return;
    }
    if(held){
      const gp=g.pickGround?.({x:g.input.mouse.nx,y:g.input.mouse.ny});
      if(gp&&this._walkable(gp.x,gp.z))this._showMoveClick(gp.x,gp.z);
      else {this._moveClick?.dispose();this._moveClick=null;return;}
    }
    // Lane 60 (Global Target::State::Ground, movemarker.js): a held button re-sets the ground target every frame, which
    // restarts the field_target scene at its first frame (static circle); only after release does the scene play on.
    this._moveClick?.update(held?0:dt);
    if(this._moveClick?.disposed)this._moveClick=null;
  }

  // ---------------------------------------------------------------- orders
  _idle() {
    const p = this.player;
    const stance = typeof p.inBattle === 'function' ? p.inBattle()
      : (p.lastCombat != null && this.now - p.lastCombat < STANCE_SECONDS) || (p.target && !p.target.dead);
    playLoop(p, stance ? 'idleCombat' : 'idle', {}, this.now);
  }

  _runOrder(dt) {
    const o = this.order;
    if (this.combo && (!o || o.type !== 'attack')) this.combo = null;
    if (!o) { this._idle(); return; }
    switch (o.type) {
      case 'move':
        if (this._followPath(o, dt)) { this.order = null; this._idle(); }
        break;
      case 'attack':
        this._runAttack(o, dt);
        break;
      case 'approach': {
        const t = o.target;
        if (!isAlive(t) || (o.valid && !o.valid())) { this.stop(); this._idle(); break; }
        const reach = (o.range || 2) + (t.radius || 0.5) * 0.9;
        // Only confirmed ranged skill orders use the completed basic-attack
        // body/host-pose correction. Other approaches retain their existing aim.
        const predictedRanged = o.predictedRangedSkill && this._bodyIsAuthoritative();
        const aim = predictedRanged ? this._sharedAttackTarget(t) : t;
        if (this._approachActor(o, aim, reach, dt)) {
          const canonical = predictedRanged ? this.player : this.game.network?.self;
          if (o.authoritativeRange && canonical && dist2(canonical, aim) > o.authoritativeRange) { this.game.network.move(aim.x, aim.z); break; }
          // The ranged adapter awaits settleMovement before dispatching cast.
          // Stopping here would clear moving before that awaited flush starts.
          if (!predictedRanged && o.authoritativeRange && this.game.network?.active) this.game.network.stop();
          this.order = o.resume || null;
          const cb = o.onArrive;
          this._idle();
          try { cb?.(); } catch (err) { console.warn('approach callback failed', err); }
        } else if ((o.fail || 0) > 3) { this.order = null; this._idle(); }
        break;
      }
      case 'npc': {
        const n = o.npc, p = this.player;
        if (!n || n.disposed) { this.stop(); this._idle(); break; }
        if (dist2(p, n) > NPC_REACH && o.path && !this._followPath(o, dt)) break; // still walking
        this.stop();
        this._idle();
        if (dist2(p, n) <= NPC_REACH + 3 || (o.goal && dist2(p, o.goal) <= 1.5)) { // NPCs often stand on blocked cells: the path ends next to them
          p.faceTowards(n.x, n.z);
          try { n.faceTowards?.(p.x, p.z); } catch { /* static NPCs */ }
          this.game.windows?.openNpc?.(n);
        }
        break;
      }
      case 'pickup': {
        const loot = this.game.loot, dr = o.drop, p = this.player;
        if (!dr || !loot?.drops?.includes(dr)) { this.order = null; this._idle(); break; }
        const far = () => Math.hypot(dr.x - p.x, dr.z - p.z);
        if (far() > PICKUP_REACH && o.path && !this._followPath(o, dt)) break; // still walking
        this.order = null;
        if (far() <= PICKUP_REACH + 0.8) loot.pickup(dr);
        this._idle();
        break;
      }
      default:
        this.order = null;
    }
  }

  _runAttack(o, dt) {
    const p = this.player, t = o.target;
    const aim = this._attackAim(t); // chase and range test share one point: a moving target cannot be "in reach" for one and out of range for the other
    if (this._validEnemy(t)) this._trackAim(t, aim);
    if (this.combo) { this._updateCombo(dt); return; }
    if (!this._validEnemy(t)) { this.order = null; this._idle(); return; }
    const reach = this.reachFor(t);
    const d = dist2(p, aim);
    // A target that keeps walking away is chased until the swing's HIT frame will still reach it (swingReach <= reach): a swing
    // started at the edge of reach finishes its full animation but its hit never lands, and the chase resumes a frame later.
    const swingReach = o.inPlace ? reach : this._swingReach(t, aim, reach);
    if (d > swingReach && !o.inPlace) {
      if (!this._approachActor(o, aim, swingReach, dt)) {
        if ((o.fail || 0) > 3) { this.order = null; this._idle(); }
        return;
      }
    }
    // Host-driven movement: prediction can arrive before the server, keep the chase until its accepted pose is in range.
    // Client-predicted movement judges the same body and point as the chase above, so it cannot disagree with it here
    // (no stalled body re-sending moves every frame); only a Shift attack, which never chases, can still be out of range.
    if (!this._sharedAttackInRange(t)) {
      if (!o.inPlace && !this._bodyIsAuthoritative()) {
        const target = this._sharedAttackTarget(t);
        this.game.network.move(target.x, target.z);
      }
      return;
    }
    const step = this._resumeAttackStep();
    if (step == null) return;
    if (this.game.network?.active) this.game.network.stop();
    p.faceTowards(t.x, t.z);
    this._startCombo(step, t);
  }

  _startCombo(k, target, carry = 0) {
    const p = this.player;
    // Combat starts aimed at the approved enemy; normal movement turns retain smoothing.
    if (this._validEnemy(target) && Math.hypot(target.x-p.x,target.z-p.z)>1e-6) {
      p.faceTowards(target.x, target.z);
      if (Number.isFinite(p.targetYaw)) p.yaw = p.targetYaw;
    }
    const st = this._stepTiming(k), len = st.len;
    this.combo = { k: k % st.n, n: st.n, t: 0, len, hitAt: st.hitAt, next: st.next, hit: false, target };
    // Only an already in-range predicted monster swing may use the small hit allowance.
    if(this._bodyIsAuthoritative()&&target?.kind==='monster'&&this._sharedAttackInRange(target)){
      const net=this.game.network,aim=this._sharedAttackTarget(target);
      this.combo.contact={at:performance.now(),player:p,targetId:target.networkId,revision:net.self.posRev,map:net.self.map,instance:net.self.instanceId,channel:net.self.channel,intent:this._inputIntentRevision,from:{x:p.x,z:p.z},aim:{x:aim.x,z:aim.z}};
    }
    playOnce(p, 'attack', { variant: this.combo.k, timeLength: len }, this.now - carry, len);
    this.combo.rootPrediction = this._startAttackRoot(this.combo.k, len);
    this.game?.events?.emit('attack', { actor: p, target, step: this.combo.k });
    if (carry > 0) this._updateCombo(Math.min(carry, len * 0.5)); // keep the chain on the table's timing
  }

  _updateCombo(dt) {
    const c = this.combo, p = this.player, t = c.target, o = this.order;
    c.t += dt;
    const alive = this._validEnemy(t);
    if (alive) p.faceTowards(t.x, t.z);
    const reach = this.reachFor(t);
    if (!c.hit && c.t >= c.hitAt) {
      c.hit = true;
      let submitted = false;
      if (alive && dist2(p, t) <= reach * 1.35 + 0.3) {
        if (this.game.network?.active) {
          const contact=c.contact,net=this.game.network,aim=this._sharedAttackTarget(t);
          const recentContact=contact&&t.kind==='monster'&&this._bodyIsAuthoritative()&&contact.player===p&&contact.targetId===t.networkId&&
            contact.revision===net.self.posRev&&contact.map===net.self.map&&contact.instance===net.self.instanceId&&contact.channel===net.self.channel&&contact.intent===this._inputIntentRevision&&
            performance.now()-contact.at>=0&&performance.now()-contact.at<=NORMAL_CONTACT.recentMs&&
            dist2(contact.from,contact.aim)<=this._sharedAttackRange()&&
            dist2(p,contact.from)<=NORMAL_CONTACT.extraCells&&dist2(aim,contact.aim)<=NORMAL_CONTACT.extraCells&&
            dist2(p,aim)<=this._sharedAttackRange()+NORMAL_CONTACT.extraCells;
          if (this._sharedAttackInRange(t)||recentContact) submitted = this.game.network.attack(t, { step: c.k, rootPrediction: c.rootPrediction, onSettled: this._attackSettlement(c) });   // the host moves its record by this step's clip
        }
        else {
          const res = resolveAttack(p, t, { data: this.game?.data });
          applyDamage(this.game, p, t, res);
        }
      }
      if (this.game.network?.active && !submitted) this.settleAttackRoot(c.rootPrediction, false);
    }
    if (c.t < c.next) return;
    const stillOrdered = o && o.type === 'attack' && o.target === t;
    const targetOk = this._validEnemy(t);
    // the next step only chains while the target is still near enough that THAT step's hit frame reaches it (see _swingReach)
    if (stillOrdered && targetOk && this._sharedAttackInRange(t) && (o.inPlace || dist2(p, this._attackAim(t)) <= this._swingReach(t, this._attackAim(t), reach, c.k + 1))) {
      this._startCombo(c.k + 1, t, c.t - c.next);
      return;
    }
    if (!targetOk) {
      this.combo = null;
      if (stillOrdered) this.order = null;
      playLoop(p, 'idleCombat', {}, this.now, c.t >= c.len);
      return;
    }
    if (c.t >= c.len) this.combo = null; // finish the swing, then chase / follow the new order
  }
}
