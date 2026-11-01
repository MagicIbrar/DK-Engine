// Monster AI, driven by monsters.json (share/ai/info.csv radii + delays, patterninfo aggressive flag,
// monsterbattle attack blocks, [walk, run] speeds). All distances are map cells = world units (FILE frame).
// The per-monster rules (sight, pursuit, speeds, reach, attack choice, call-team, statuses) are the shared pure functions of
// src/game/monster-rules.js, which the authoritative server (server/world/core.mjs) uses as well; the engine-chosen
// constants (fallbacks, paddings, the explore anchor) are in src/config/engine-chosen-monster-ai.js.
//
// States:  idle ÃƒÂ¢Ã¢â‚¬ÂÃ¢â€šÂ¬ÃƒÂ¢Ã¢â‚¬ÂÃ¢â€šÂ¬(explore delay)ÃƒÂ¢Ã¢â‚¬ÂÃ¢â€šÂ¬ÃƒÂ¢Ã¢â‚¬ÂÃ¢â€šÂ¬> wander ÃƒÂ¢Ã¢â‚¬ÂÃ¢â€šÂ¬ÃƒÂ¢Ã¢â‚¬ÂÃ¢â€šÂ¬(arrived / timeout)ÃƒÂ¢Ã¢â‚¬ÂÃ¢â€šÂ¬ÃƒÂ¢Ã¢â‚¬ÂÃ¢â€šÂ¬> idle          (idle + wander = the table's mode EXPLORE)
//            ÃƒÂ¢Ã¢â‚¬ÂÃ¢â‚¬Å¡  aggressive & player within `sight` (and within `pursuit` of home), or hit (any pattern: UNDER_ATTACK -> RAGE)
//            v
//          chase (run) ÃƒÂ¢Ã¢â‚¬ÂÃ¢â€šÂ¬ÃƒÂ¢Ã¢â‚¬ÂÃ¢â€šÂ¬(within attack reach)ÃƒÂ¢Ã¢â‚¬ÂÃ¢â€šÂ¬ÃƒÂ¢Ã¢â‚¬ÂÃ¢â€šÂ¬> attack (swing every attack delay, damage at clip timing)
//            ÃƒÂ¢Ã¢â‚¬ÂÃ¢â‚¬Å¡  beyond `pursuit` from home, target dead / gone, or stuck = PERSUIT_OUT: the table's NEXT_STATE
//            ÃƒÂ¢Ã¢â‚¬ÂÃ¢â‚¬Å¡  (FEAR / UNCARING, `tableState`) + mode EXPLORE = back to idle / wander
//            v
//          idle
// There is NO "return home" state: share/ai lists none. PERSUIT_OUT only ends the chase; the monster then does its ordinary
// EXPLORE movement (walk speed, explore stand delay) around WHERE THE CHASE ENDED: `this.anchor` (the roaming centre) is null until a
// give-up (then the monster roams around its spawn) and the monster's position at the give-up afterwards (ENGINE-CHOSEN, engine-chosen-monster-ai.js explore.anchor 'ended'). The pursuit range / leash origin is the
// same point (`_centre()` = anchor || home): the leash
// follows the monster at every give-up, so it keeps following a player it still sees and never walks back. `this.home` (= `monster.home`)
// stays the ORIGINAL spawn; only death returns the monster there (respawn = a new monster + brain at the spawn).
// It takes normal damage, never regenerates, never heals to full and is never teleported; a hit re-engages it.
// "Call" patterns (NegativeCall / PositiveCall / RangeCall) pull `callTeam[1]` idle neighbours within `callTeam[2]` cells on
// the first hit they take while calm (UNDER_ATTACK,{REST,FEAR,UNCARING,ANNOYED} -> CALLTEAM; re-armed by PERSUIT_OUT).
// Objects (treasure boxes, statues: role 'object', patterns 7/13) never move or attack.
import { resolveAttack, applyDamage, playOnce, playLoop, rand, monsterDef, isAlive, dist2 } from './combat.js';
import * as R from './monster-rules.js';
import { clearHate } from './hate.js';
import { FollowBook, followLimit, hatedAlternatives } from './follow-cap.js';
import { MONSTER_AI_ENGINE_CHOSEN as C } from '../config/engine-chosen-monster-ai.js';

const DEFAULT_DELAYS = [2000, 2000, 1200, 1000]; // exploreStand, exploreMove, stand, move (ms) ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â monsters.json defaults
const ATTACK_INDEX = R.ATTACK_INDEX;
const STEER_ANGLES = [0, 0.45, -0.45, 0.9, -0.9, 1.35, -1.35];
const STUCK_GIVEUP = C.chaseStuckGiveUpSec;   // seconds without progress before a chase / wander gives up
const HIT_FLINCH = 0.35;    // seconds a monster pauses after a hit reaction
// follower cap (follow-cap.js): a book member still follows `key` while its brain chases / attacks it
const FOLLOWING = (o, key) => !o.dead && !o.disposed && !!o.brain && o.brain.target === key && (o.brain.state === 'chase' || o.brain.state === 'attack');

export class MonsterBrain {
  constructor(game, monster) {
    this.game = game;
    this.m = monster;
    const def = (this.def = monsterDef(monster) || {});
    const ai = def.ai || {};
    const dbDefaults = game?.data?.monsters?.defaults || {};
    // `this.home` = the ORIGINAL spawn, never changed here (the spawner re-creates the monster at its spawn record after death);
    // `this.anchor` = the roaming centre AND the pursuit / leash origin once a chase has ended (_leash, _centre()), null = the spawn
    this.home = {
      x: monster.home?.x ?? monster.spawn?.x ?? monster.x ?? 0,
      z: monster.home?.z ?? monster.spawn?.z ?? monster.z ?? 0,
    };
    this.anchor = null;
    monster.home = monster.home || { ...this.home };
    this.pattern = ai.pattern ?? 2;
    this.aggressive = !!ai.aggressive;
    // info.csv DwSight / DwPersuitRange as they are (0 stays 0; only a missing row falls back): monster-rules.js
    this.sight = R.aggroRadius(def);
    this.explore = R.exploreRange(def);
    this.pursuit = R.leashRange(def);
    this.delays = (Array.isArray(ai.delays) && ai.delays.length >= 4 ? ai.delays : dbDefaults['ai.delays']) || DEFAULT_DELAYS;
    this.walkSpeed = R.walkSpeed(def);
    this.runSpeed = R.chaseSpeed(def);
    // objects (boxes, statues, traps) never fight; immobile creatures (speed 0, e.g. plants) fight without moving
    this.isObject = R.isNonCombatant(def);
    this.immobile = R.isImmobile(def);
    this.stationary = this.isObject || this.immobile;
    this.canAttack = R.canAttack(def);
    this.callTeam = Array.isArray(ai.callTeam) ? ai.callTeam : null;
    this.called = false;

    this.state = 'idle';
    this.tableState = R.REST_STATE;   // share/ai/pattern CURRENT_STATE: REST at spawn, RAGE when hit, NEXT_STATE of PERSUIT_OUT after a give-up
    this.timer = this._standDelay() * rand(); // desynchronise neighbours
    this.target = null;
    this.pending = null;        // a target wanted (hit by / provoked by it) while the follower cap of that target was full: retried every frame
    this.cooldown = 0;          // seconds until the next swing may start
    this.swing = null;          // current attack animation {key, t, len, hitAt, done}
    this.flinch = 0;
    this.stuck = 0;
    this.wanderTo = null;
    this.moveTime = 0;
    this.specialReadyAt = 0;
    this.powerReadyAt = 0;
    this._moveLocked = false;
  }

  // ---------------------------------------------------------------- queries
  get now() { return this.game?.time || 0; }
  _walkable(x, z) {
    const w = this.game?.world;
    return w && typeof w.isWalkable === 'function' ? w.isWalkable(x, z) : true;
  }
  _standDelay() { return (this.delays[0] || 2000) / 1000 * (0.6 + rand() * 0.8); }
  /** The roaming centre = the origin of the pursuit range / leash: where the last chase ended, else the spawn. */
  _centre() { return this.anchor || this.home; }
  distHome() { return Math.hypot(this.m.x - this.home.x, this.m.z - this.home.z); }

  /** Reach (centre to centre) for an attack block. */
  reach(key, target = this.target) {
    return R.reach(this.def, key, this.m.radius, target?.radius);
  }
  /** Distance at which the chase stops: the longest base attack (range monsters stop at bow range). */
  preferredReach(target = this.target) {
    return R.preferredReach(this.def, this.m.radius, target?.radius);
  }
  /** The effective radii of this brain (events may raise sight / pursuit on the instance) for the shared rules. */
  _ranges(target = this.target) {
    return { sight: this.sight, pursuit: this.pursuit, immobile: this.immobile, forgetRange: Math.max(this.sight, this.preferredReach(target)) };
  }

  _validTarget(t) {
    return isAlive(t) && t.kind !== 'monster' && t.kind !== 'npc';
  }

  // ---------------------------------------------------------------- events from combat.js
  onDamaged(attacker, amount) {
    const m = this.m;
    if (m.dead) return;
    if (this.canAttack && this._validTarget(attacker)) {
      // UNDER_ATTACK from REST / FEAR / UNCARING / ANNOYED -> RAGE in every pattern table (negative_attack.csv:2-5)
      if (this.target !== attacker || (this.state !== 'chase' && this.state !== 'attack')) { if (this.engage(attacker)) this.tableState = R.UNDER_ATTACK_STATE; }
    }
    // Call patterns: UNDER_ATTACK from a calm state (REST / FEAR / UNCARING / ANNOYED) -> CALLTEAM, once until re-armed
    // (negativecall_attack.csv:2-5, positivecall_attack.csv:2-5, rangecall_attack.csv:2-5). DwCallTeamPossibelHP is not
    // applied (meaning unknown; see engine-chosen-monster-ai.js callTeam).
    if (this.callTeam && !this.called) this._callForHelp(attacker);
    // hit reaction (DEFEAT clip) when not mid-swing
    if (amount > 0 && !this.swing) {
      playOnce(m, 'hit', { variant: 0 }, this.now, HIT_FLINCH);
      this.flinch = HIT_FLINCH;
    }
  }
  onDeath() {
    this.state = 'dead';
    this.swing = null;
    this.target = null;
    this.pending = null;
    this._unfollow();
    clearHate(this.m);
    this.called = false;
  }

  /** The follower book of this game (follow-cap.js), created on first use; null for a brain without a game (unit tests). */
  _book() { const g = this.game; return g ? (g.followBook || (g.followBook = new FollowBook())) : null; }
  /** Stop counting as a follower of anyone (death, leash, target gone, disposal). */
  _unfollow() { this._book()?.release(this.m); }
  /** Dispose hook (spawner._disposeMonster): the slot is freed with the monster. */
  dispose() { this.pending = null; this._unfollow(); }

  /**
   * Take `target`; returns true when the brain really switched to it. FOLLOWER CAP (follow-cap.js, ENGINE-CHOSEN meaning of info.csv
   * dwFollowTarget): refused while `target` already has dwFollowTarget followers - the monster then keeps its state (it still takes
   * damage and explores) and, when `pend` is set, remembers the target so it takes the first free slot (_retryPending).
   */
  engage(target, pend = true) {
    if (!this._validTarget(target) || !this.canAttack) return false;
    const book = this._book();
    if (book && !book.claim(this.m, target, followLimit(this.def), FOLLOWING)) {
      if (!pend || this.target) return false;
      this.pending = target;
      // fix: the most hated target is full - try the other targets this monster hates (most hated first; a party member / servant is a
      // separate target) before it waits; with none free it keeps `pending` = the first choice (_retryPending takes it when it has room)
      const alts = hatedAlternatives(this.m, target, this.game?.skills?.data?.aggro, (this.game?.time || 0) * 1000,
        who => this._validTarget(who) && !who.invisible && !R.shouldLeash(this._ranges(who), this.m, this._centre(), who, { attacking: false }));
      if (!alts) return false;
      const lim = followLimit(this.def);
      const alt = alts.find(who => book.claim(this.m, who, lim, FOLLOWING));
      if (alt === undefined) return false;
      target = alt;
    }
    this.pending = null;
    this.target = target;
    this.m.target = target;
    this.state = 'chase';
    this.stuck = 0;
    return true;
  }

  _callForHelp(target) {
    this.called = true;
    const rule = R.callTeamRule(this.def);
    if (!rule || !this._validTarget(target)) return;
    const list = this.game?.spawner?.monsters || [];
    // engine-chosen filter (engine-chosen-monster-ai.js callTeam): idle fighters of any species in this scene
    R.recruitCallTeam(list, this.m, rule, {
      canAnswer: o => !o.dead && o.brain && o.brain.canAttack && !o.brain.target && o.brain.state !== 'chase' && o.brain.state !== 'attack',
      engage: o => o.brain.engage(target, false),   // a recruit with no free slot on that target simply does not answer the call
    });
  }

  /**
   * PERSUIT_OUT (the target is gone / dead / unreachable / beyond the pursuit range): the pattern table's NEXT_STATE (FEAR or
   * UNCARING, persuitOutRule) with mode EXPLORE. The monster stops chasing, drops its hostility, re-arms the call pattern and
   * resumes ordinary EXPLORE movement (idle -> wander). Nothing else changes: HP, hittability and position are untouched.
   * RE-HOME (ENGINE-CHOSEN; explore.anchor 'ended'): a monster that roams
   * (explore range and WalkSpeed > 0) takes the point where it stands as its ROAMING centre (`this.anchor`), so it roams around where it
   * ended and does not walk back. The same point is the origin of its pursuit range / leash (`_centre()`): a player can pull it across
   * the whole map; only death (a new monster at the spawn) returns it.
   * Only here (never in an explore leg); a hit makes it chase again and the next give-up re-homes it again.
   */
  _leash() {
    if (R.rehomes(this.def)) this.anchor = { x: this.m.x, z: this.m.z };
    const rule = R.persuitOutRule(this.def);
    this.tableState = rule ? rule.state : R.REST_STATE;
    this.state = 'idle';
    this.timer = this._standDelay();
    this.wanderTo = null;
    this.target = null;
    this.m.target = null;
    this.swing = null;
    this.stuck = 0;
    this.pending = null;
    this._unfollow();
    clearHate(this.m);
    this.called = false;
  }

  // ---------------------------------------------------------------- movement
  /** Straight-line step towards (tx,tz) with simple steering around blocked cells. Returns true when arrived. */
  step(tx, tz, speed, dt, stopAt = 0.15) {
    const m = this.m;
    if (this._moveLocked) return false;   // rooted (ACTION_DISALLOW_MOVE): stands, without counting as stuck
    speed *= this.speedMul();
    const dx = tx - m.x, dz = tz - m.z;
    const d = Math.hypot(dx, dz);
    if (d <= stopAt) return true;
    const s = Math.min(d - stopAt * 0.5, speed * dt);
    if (s <= 0) return true;
    const ux = dx / d, uz = dz / d;
    for (const a of STEER_ANGLES) {
      const c = Math.cos(a), sn = Math.sin(a);
      const rx = ux * c - uz * sn, rz = ux * sn + uz * c;
      const nx = m.x + rx * s, nz = m.z + rz * s;
      if (this._walkable(nx, nz)) {
        m.faceTowards(m.x + rx, m.z + rz);
        m.setPosition(nx, nz);
        if (a === 0) this.stuck = Math.max(0, this.stuck - dt); else this.stuck += dt * 0.25;
        return d - s <= stopAt;
      }
    }
    this.stuck += dt;
    return false;
  }

  /** Movement multiplier from the monster's statuses (skill slows / hastes: SPEED_MOVE_MUL / SPEED_MOVE_SUB, %). */
  speedMul() {
    return R.statusSpeedMul(this.m.statuses);
  }

  _pickWanderPoint() {
    const r = this.explore, c = this.anchor || this.home;   // roaming centre: the spawn, or where the last chase ended (re-homed)
    for (let i = 0; i < 8; i++) {
      const a = rand() * Math.PI * 2, d = r * Math.sqrt(rand());
      const x = c.x + Math.cos(a) * d, z = c.z + Math.sin(a) * d;
      if (this._walkable(x, z)) return { x, z };
    }
    return null;
  }

  // ---------------------------------------------------------------- attacks
  /** Pick an attack block (shared rule, monster-rules.js chooseAttack): power / special attacks by their HP threshold +
   *  rate + cooldown, aggro-table attacks by aggroRates, otherwise the base melee / range block that reaches the target. */
  chooseAttack(dist) {
    const m = this.m;
    const hpPct = m.maxHp > 0 ? (m.hp / m.maxHp) * 100 : 100;
    const pick = R.chooseAttack(this.def, {
      dist, hpPct, nowMs: this.now * 1000, specialReadyAt: this.specialReadyAt * 1000, powerReadyAt: this.powerReadyAt * 1000,
      rng: rand, mRadius: m.radius, tRadius: this.target?.radius,
    });
    if (!pick) return null;
    this.specialReadyAt = pick.specialReadyAt / 1000;
    this.powerReadyAt = pick.powerReadyAt / 1000;
    return pick.key;
  }

  /** {len, hitAt} of the ATTACK clip for an attack block, from the monster's action set. */
  clipFor(key) {
    const db = this.game?.data?.monsters;
    const set = db?.actionSets?.[this.def.act];
    const idx = ATTACK_INDEX[key] ?? 0;
    let ci = set?.actions?.ATTACK?.[idx];
    if (ci == null || ci < 0) ci = set?.states?.attack?.[0];
    const clip = ci != null && ci >= 0 ? set?.clips?.[ci] : null;
    const len = clip && clip[1] > 0 ? clip[1] : 1;
    const timing = clip && clip[4] > 0 && clip[4] <= 1 ? clip[4] : 0.5;
    return { len, hitAt: len * timing, variant: idx };
  }

  _startSwing(key) {
    const m = this.m, t = this.target;
    const a = this.def.attacks?.[key];
    const { len, hitAt, variant } = this.clipFor(key);
    const delay = a ? num(a[5], 2000) / 1000 : 2;
    this.swing = { key, t: 0, len, hitAt, done: false };
    this.cooldown = Math.max(delay, len);
    if (t) m.faceTowards(t.x, t.z);
    playOnce(m, 'attack', { variant, timeLength: len }, this.now, len);
    this.game?.events?.emit('attack', { actor: m, target: t, attackKey: key });
  }

  _updateSwing(dt) {
    const s = this.swing, m = this.m, t = this.target;
    s.t += dt;
    if (!s.done && s.t >= s.hitAt) {
      s.done = true;
      if (this._validTarget(t) && dist2(m, t) <= this.reach(s.key, t) * 1.3 + 0.5) {
        const res = resolveAttack(m, t, { attackKey: s.key, data: this.game?.data });
        applyDamage(this.game, m, t, res);
      }
    }
    if (s.t >= s.len) this.swing = null;
  }

  // ---------------------------------------------------------------- main loop
  update(dt) {
    const m = this.m;
    if (!m || m.dead) { this.state = 'dead'; return; }
    if (!(dt > 0)) return;
    const now = this.now;
    this.cooldown = Math.max(0, this.cooldown - dt);
    if (this.flinch > 0) this.flinch -= dt;

    // skill statuses: stunned / asleep (move + attack lock) stand still; a root (move only) still swings at a target in
    // reach; an attack lock (e.g. status 2221) still follows but never swings ÃƒÂ¢Ã¢â€šÂ¬Ã¢â‚¬Â shared monster-rules.js statusFlags
    const F = R.statusFlags(m.statuses);
    this._moveLocked = F.move;
    if (F.lock || (F.move && F.attack)) { this.swing = null; playLoop(m, 'idleCombat', {}, now); return; }
    if (F.attack && this.swing) this.swing = null;
    if (this.swing) { this._updateSwing(dt); return; }
    if (this.flinch > 0) return;

    const player = this.game?.player;
    switch (this.state) {
      case 'idle': {
        playLoop(m, 'idle', {}, now);
        if (this._aggroCheck(player)) break;
        if (this.stationary) break;
        this.timer -= dt;
        // EXPLORE: only a monster that roams at all (explore range > 0 and WalkSpeed > 0, as before) picks explore points around
        // its roaming centre (ENGINE-CHOSEN anchor 'ended': the spawn, re-homed to where the last chase ended by _leash), so after a
        // give-up it simply roams there (walk-back only exists for anchor 'home': a chase left it outside that area).
        // A monster that never roamed gets no new movement (no walk back, no RunSpeed borrowed): it stays where the chase ended.
        if (this.timer <= 0 && R.roamsInExplore(this.def)) {
          this.wanderTo = this._pickWanderPoint();
          if (this.wanderTo) {
            this.state = 'wander'; this.moveTime = 0; this.stuck = 0;
            this.wanderMax = Math.max(3, Math.max(this.explore * 2, Math.hypot(this.wanderTo.x - m.x, this.wanderTo.z - m.z)) / Math.max(0.1, this.walkSpeed) + 1);
          } else this.timer = this._standDelay();
        }
        break;
      }
      case 'wander': {
        if (this._aggroCheck(player)) break;
        const legSpeed = this.walkSpeed;
        playLoop(m, 'walk', { moveSpeed: legSpeed * this.speedMul() }, now, true);
        this.moveTime += dt;
        const arrived = !this.wanderTo || this.step(this.wanderTo.x, this.wanderTo.z, legSpeed, dt, 0.2);
        const maxMove = this.wanderMax || 3;
        if (arrived || this.stuck > STUCK_GIVEUP || this.moveTime > maxMove) {
          this.state = 'idle';
          this.timer = this._standDelay();
          this.wanderTo = null;
        }
        break;
      }
      case 'chase': {
        const t = this.target;
        if (!this._validTarget(t)) { this._leash(); break; }
        const d = dist2(m, t);
        const stop = this.preferredReach(t);
        if (R.shouldLeash(this._ranges(t), m, this._centre(), t, { attacking: d <= stop })) { this._leash(); break; }
        if (d <= stop) { this.state = 'attack'; this.stuck = 0; break; }
        if (this.immobile) { // cannot follow: wait while the target is near (shouldLeash forgets it when it leaves)
          playLoop(m, 'idleCombat', {}, now);
          break;
        }
        playLoop(m, 'run', { moveSpeed: this.runSpeed * this.speedMul() }, now, true);
        this.step(t.x, t.z, this.runSpeed, dt, 0.1);
        if (this.stuck > STUCK_GIVEUP) this._leash();
        break;
      }
      case 'attack': {
        const t = this.target;
        if (!this._validTarget(t)) { this._leash(); break; }
        if (R.shouldLeash(this._ranges(t), m, this._centre(), t, { attacking: true })) { this._leash(); break; }
        const d = dist2(m, t);
        if (d > this.preferredReach(t) * 1.15 + 0.3) {
          this.state = 'chase';
          break;
        }
        m.faceTowards(t.x, t.z);
        if (this.cooldown <= 0 && !F.attack) {
          const key = this.chooseAttack(d);
          if (key) { this._startSwing(key); break; }
        }
        playLoop(m, 'idleCombat', {}, now);
        break;
      }
      default:
        this.state = 'idle';
    }
  }

  /**
   * A target this monster wanted but whose follower cap was full (engage): while the same tests that end a chase still hold, take it
   * as soon as a follower died / dropped it (a free slot). Cheap: one claim per frame.
   */
  _retryPending() {
    const t = this.pending;
    if (!t) return false;
    if (!this._validTarget(t) || R.shouldLeash(this._ranges(t), this.m, this._centre(), t, { attacking: false })) { this.pending = null; return false; }
    if (!this.engage(t)) return false;
    this.tableState = R.UNDER_ATTACK_STATE;
    return true;
  }

  _aggroCheck(player) {
    if (this.pending && this._retryPending()) return true;
    if (!this.aggressive || !this.canAttack || !this._validTarget(player)) return false;
    if (!R.canAcquire(this._ranges(player), this.m, this._centre(), player)) return false;
    // SIGHT_IN -> ANNOYED + PERSUIT (positive_attack.csv SIGHT_IN rows); no free follower slot on this player = it stays calm
    if (!this.engage(player, false)) return false;
    this.tableState = 'ANNOYED';
    return true;
  }
}

function num(v, d = 0) { return Number.isFinite(+v) ? +v : d; }
