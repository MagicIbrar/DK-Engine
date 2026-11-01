// Summons (docs/formats/skills.md §9, §13.6): the summoner classes' servants (share/creature/servant.csv via
// skills.json servants: shape mesh + skeleton + stand/move/attack/hit/die clips, combat blocks with damage, range,
// delay and result code) as fighting companions with AI, and the Sacra / Chakra totems (totem.csv: aura result
// pulsed every FLUSHTIME for TOTALTIME).
//
// Servant AI (solo): follows its owner (stays ~2.5 m behind, teleports back beyond 30 m / on map change); attacks the
// owner's enemy target, a monster attacking the owner or itself, or an aggressive monster close to the owner; picks
// its attack block by availability (great > special > power > base, each on its own AttackDelay); melee blocks swing
// at the clip timing, range blocks launch their remote (the block's result code); damage = the block's min..max
// (+ absolute) through combat.resolveAttack. Monsters target servants like players (ai.js _validTarget) and kills
// give the owner exp (combat.kill: killer.owner === player). One servant at a time (a new one replaces it); one totem
// per totem type. The explicit recall API brings the servant to its owner; native skill result4500010 instead
// recalls a selected party member (handled by SkillEngine). servant_explode (Fury explosion) consumes the servant.
import { Actor, interFade } from '../../actors/actor.js';
import { resolveAttack, applyDamage, playOnce, playLoop, isAlive, rand } from '../../game/combat.js';
import { plainHitHate } from '../../game/hate.js';
import { fetchCSVObjects } from '../../engine/assets.js';
import { parseServantGauges, servantGaugeGain } from './servant-gauge-rules.js';
import {servantEffects} from './servant-effects.js';

const FOLLOW_DIST = 2.5;
const LEASH = 30;
const ASSIST_RANGE = 18;
const num = v => (Number.isFinite(+v) ? +v : 0);

// ============================================================================================ servant actor
export class Servant extends Actor {
  constructor(game, def, owner, sys) {
    super(game, { kind: 'servant', name: def.name, level: num(def.level) || 1 });
    this.owner = owner;
    this.sys = sys;
    this.maxMp = this.mp = 0;
    this.radius = 0.6;
    this.fadeOnDeath = true;
    this._applyDef(def, false);
    this.state = 'follow';
    this.target = null;
    this.readyAt = {};
    this.swing = null;
    this.born = game.time || 0;
  }

  /**
   * Everything derived from the servant row (servant.csv via skills.json servants). `late` = the row arrived after the actor was made
   * (a remote servant whose class pack was fetched on demand, RemoteServant): the host's hp / maxHp stay as they are.
   */
  _applyDef(def, late = true) {
    this.def = def;
    this.servantIndex = def.index;
    const r = def.raw || {};
    if (!late) this.maxHp = this.hp = num(def.maxHp) || num(r.MaxHP) || 1000;
    this.walkSpeed = num(r.WalkSpeed) || 2;
    this.runSpeed = num(r.RunSpeed) || 5;
    this.attacks = (def.attackResults || []).filter(a => a.max > 0 || a.result);
    const base = this.attacks[0] || { min: 10, max: 20 };
    const isRange = /range/.test(base.block || '');
    // stats read by combat.resolveAttack (attacker) and defenceProfile (defender)
    this.stats = {
      attackType: isRange ? 'range' : 'melee', meleeMin: base.min, meleeMax: base.max, rangeMin: base.min, rangeMax: base.max,
      magicMin: base.min, magicMax: base.max, attackMin: base.min, attackMax: base.max,
      hitRate: this.level * 14, critRate: 5, critMultiplier: 1.5,
      defense: (num(r.Defence_Min) + num(r.Defence_Max)) / 2, dodge: this.level * 10,
      guardRate: num(r.GuardRate), guardEfficiency: num(r.GuardEfficiency), magicResist: num(r.MagicResist),
    };
  }

  async _load() {
    const d = this.def, models = this.game.models;
    if (!models || !d.shape?.mesh) return;
    const model = await models.loadSkinned({ skelKey: d.skeleton, parts: [{ meshKey: d.shape.mesh, tpackKey: d.shape.tpack || null }] });
    if (!model || this.disposed) return;
    this._setSkinned(model);
    if (model.height > 0) this.height = model.height;
    await this._preload([['idle'], ['run'], ['attack']]);
    if(!this.disposed)await servantEffects(this.game).prepare(this).catch(error=>console.warn('[skills] servant action effects',error));
  }

  _specFor(state, opts = {}) {
    const A = this.def.anims || {};
    const e = (x, loop, actionId) => (x?.anim ? { key: x.anim, duration: x.timeLength > 0 ? x.timeLength : null, loop, fade: interFade(4), timing: x.timing || 0, servantAction:x, servantActionId:actionId } : null);
    switch (state) {
      case 'idle': case 'idleCombat': return e(A.stand, true, 1);
      case 'walk': case 'run': return e(A.move, true, 2);
      case 'attack': case 'skill': {
        const at = (this.def.attacks || [])[opts.variant | 0];
        return e(at || A.attack, false, 6);
      }
      case 'hit': return e(A.hit, false, 7);
      case 'die': return e(A.die, false, 8);
      default: return null;
    }
  }

  play(state,opts){this.game.servantEffects?.stop(this);return super.play(state,opts);}
  _onClipStart(spec,clip,opts){super._onClipStart(spec,clip,opts);servantEffects(this.game).start(this,spec,clip,opts);}
  updateEffects(dt){this.game.servantEffects?.tick(dt,this);}
  update(dt){super.update(dt);this.updateEffects(dt);}

  startStatusEffect() {
    if (this.disposed || !this.def.statusEffect) return null;
    if (this._statusFx && !this._statusFx.done) return this._statusFx;
    const fx = this.sys?.engine?.fx || this.game.skills?.fx || this.game.effects;
    this._statusFx = fx?.play(this, this.def.statusEffect, {}) || null;
    return this._statusFx;
  }

  dispose() {
    this.game.servantEffects?.stop(this);
    try { this._statusFx?.stop(true); } catch (error) { console.warn('[skills] servant effect stop failed', error); }
    this._statusFx = null;
    super.dispose();
  }

  revive(frac = 0.3) {
    this.dead = false;
    this.hp = Math.max(1, Math.round(this.maxHp * frac));
    this.play('idle', { loop: true });
  }
}

// ============================================================================================ totem object
class Totem {
  constructor(sys, def, owner, pos) {
    this.sys = sys;
    this.game = sys.game;
    this.def = def;
    this.owner = owner;
    this.kind = 'totem';
    this.name = def.name;
    this.x = pos.x; this.z = pos.z; this.y = pos.y ?? 0; this.yaw = owner.yaw || 0;
    this.height = 2; this.scale = 1; this.radius = 0.8;
    this.until = (this.game.time || 0) + (num(def.lifeSec) || 60);
    this.tick = num(def.tickMs) / 1000 || 1;
    this.nextTick = 0;
    this.object = null;
    this.alive = true;
    this.fx = null;
    const models = this.game.models;
    if (def.shape?.mesh && models) {
      models.loadStatic(def.shape.mesh, { tpackKey: def.shape.tpack || null }).then(m => {
        if (!m || !this.alive) return;
        this.object = m.instantiate();
        this.object.position.set(this.x, this.y, this.z);
        this.object.rotation.y = this.yaw;
        this.game.worldRoot?.add(this.object);
      }).catch(() => {});
    }
    try { if (def.standEffect) this.fx = sys.engine.fx?.play(this, def.standEffect, { loop: true }); } catch (error) { console.warn('[skills] totem effect failed', error); }
  }
  update(dt) {
    if (!this.alive) return;
    const now = this.game.time || 0;
    this.nextTick -= dt;
    if (this.nextTick <= 0) {
      this.nextTick += this.tick;
      const aura = this.def.aura;
      if (aura) {
        const ctx = { caster: this.owner, skill: { index: this.def.index, name: this.def.name, targetMask: 16 }, level: 1, target: null, point: { x: this.x, z: this.z } };
        // the aura is centred on the totem, not the caster
        const r = { ...aura };
        const fake = { ...this.owner, x: this.x, z: this.z, kind: this.owner.kind };
        this.sys.engine.applyImpact({ ...ctx, caster: this.owner }, r, null, { x: this.x, z: this.z }, { center: fake });
      }
    }
    if (now >= this.until) this.destroy(true);
  }
  destroy(timeout) {
    if (!this.alive) return;
    this.alive = false;
    try { this.fx?.stop(true); } catch (error) { console.warn('[skills] totem effect stop failed', error); }
    const e = timeout ? this.def.dieEffect || this.def.leaveEffect : this.def.leaveEffect;
    try { if (e) this.sys.engine.fx?.playAt({ x: this.x, y: this.y, z: this.z }, e); } catch (error) { console.warn('[skills] totem effect failed', error); }
    if (this.object) { this.object.removeFromParent(); this.object = null; }
  }
}

// ============================================================================================ summon system
export class SummonSystem {
  constructor(engine) {
    this.engine = engine;
    this.game = engine.game;
    this.servants = [];
    this.totems = [];
    this.gauges = new Map();
    // orders (ui_servantwnd buttons / key map "Order Summon" Shift+Q W E R A, stringtable_servant 400):
    //   assist  default: attacks what the owner fights and whoever attacks the owner or itself
    //   attack  "Attack Command": attacks the owner's current target now, then assists again
    //   free    "Independence": engages any monster near it on its own
    //   call    "Call": runs back to the owner (ignoring enemies), then assists again
    //   stop    "Stop": holds its spot until another order; fights only what reaches it
    this.mode = 'assist';
  }

  /** Give an order to the player's servant: 'attack' | 'free' | 'call' | 'stop' | 'destroy' | 'assist'. */
  command(mode) {
    const o = this.game.player;
    const sv = this.servantOf(o);
    if (!sv) return false;
    if (mode === 'destroy') { this.dismiss(sv, true); return true; }
    this.mode = mode;
    sv.holdAt = null;
    sv.forced = null;
    if (mode === 'attack') {
      const t = o.target;
      if (this._enemyOk(t)) { sv.forced = t; sv.target = t; } else this.mode = 'assist';
    } else if (mode === 'stop') { sv.target = null; sv.holdAt = { x: sv.x, z: sv.z }; }
    else if (mode === 'call') sv.target = null;
    this.game.events?.emit('servant:order', { servant: sv, mode: this.mode });
    return true;
  }

  async loadGauges() {
    try { this.gauges = parseServantGauges(await fetchCSVObjects('share/article/gage.csv', true)); }
    catch (error) { this.gauges = new Map(); console.warn('[skills] servant gauge table unavailable', error); }
  }
  gaugeRow(sv) {
    if (!sv || sv.owner !== this.game.player) return null;
    const row = this.gauges.get(`${Number(this.game.save?.classIndex ?? this.game.classDef?.index)}:${Number(sv.servantIndex)}`);
    return row && this.engine.learnedLevel(row.skill) >= 1 ? row : null;
  }
  greatBlock(sv) { return this.gaugeRow(sv) ? sv?.attacks?.find(a => /^great/.test(a.block || '')) || null : null; }
  onDamage(source, target, result) {
    if (!source || !this.servants.includes(source) || source.dead || source.disposed ||
      !this.greatBlock(source) || result.miss || result.dot || !(result.amount > 0) ||
      /^great/.test(result.skill?.servantBlock || '') || target?.isBrick || target?._record?.isBrick) return;
    source.charge = Math.min(1, num(source.charge) + servantGaugeGain(this.gaugeRow(source),
      { kind: target?.kind, killed: target?.hp <= 0 }));
  }
  greatCharge(sv) { return Math.max(0, Math.min(1, num(sv?.charge))); }
  useGreat() {
    const o = this.game.player;
    const sv = this.servantOf(o);
    const blk = this.greatBlock(sv);
    if (!sv || !blk) return false;
    if (this.greatCharge(sv) < 1) { this.game.hud?.log?.(this.strings?.[31] || 'Able to use when gauge has reached 100%', 'err'); return false; }
    const t = this._enemyOk(sv.target) ? sv.target : this._enemyOk(o.target) ? o.target : null;
    if (!t) { this.game.hud?.log?.(this.engine.msg(50), 'err'); return false; }
    sv.pendingGreat = t;
    sv.target = t;
    return true;
  }

  get list() { return this.servants; }
  all() { return this.servants.filter(s => !s.disposed); }
  servantOf(owner) { return this.servants.find(s => s.owner === owner && !s.dead && !s.disposed) || null; }
  deadServantOf(owner) { return this.servants.find(s => s.owner === owner && s.dead && !s.disposed) || null; }

  /** summon result {servantIndex, summonLevel}. */
  async summon(ctx, r) {
    const def = this.engine.data.servant(r.servantIndex);
    const owner = ctx.caster;
    if (!def || !owner) return null;
    // one servant at a time
    for (const s of this.servants.filter(s => s.owner === owner)) this.dismiss(s, false);
    const sv = new Servant(this.game, def, owner, this);
    sv.skillIndex = ctx.skill?.index ?? null;
    const p = this._spot(owner, 1.8);
    sv.setPosition(p.x, p.z);
    sv.yaw = owner.yaw || 0;
    this.servants.push(sv);
    this.game.save.servant = { index: def.index, skill: sv.skillIndex };
    try { await sv.load(); } catch (error) { console.warn('[skills] servant visual failed', error); }
    if (sv.disposed) return null;
    // The servant may have moved while its model loaded. Keep its current pose.
    try {
      if (def.enterEffect) this.engine.fx?.play(sv, def.enterEffect, {});
      // Entry and status use separate native variants; EffectPlayer honors each row's loop flag.
      sv.startStatusEffect();
    } catch (error) { console.warn('[skills] servant effect failed', error); }
    sv.play('idle', { loop: true });
    this.game.events?.emit('summon', { owner, servant: sv, on: true });
    return sv;
  }

  dismiss(sv, effect = true) {
    if (!sv || sv.disposed) return;
    this.servants = this.servants.filter(s => s !== sv);
    if (this.game.save?.servant?.index === sv.servantIndex) this.game.save.servant = null;
    try { if (effect && sv.def.leaveEffect) this.engine.fx?.playAt({ x: sv.x, y: sv.y, z: sv.z }, sv.def.leaveEffect); } catch (error) { console.warn('[skills] servant effect failed', error); }
    try { sv._statusFx?.stop(true); } catch (error) { console.warn('[skills] servant effect stop failed', error); }
    try { sv.dispose(); } catch { /* ignore */ }
    this.game.events?.emit('summon', { owner: sv.owner, servant: sv, on: false });
  }

  /** Fury explosion: the servant blows up (the damage itself is applied by the engine around it). */
  explode(sv) {
    if (!sv) return;
    sv.hp = 0; sv.dead = true;
    this.dismiss(sv, true);
  }

  recall(owner) {
    const sv = this.servantOf(owner);
    if (!sv) return;
    const p = this._spot(owner, 1.5);
    sv.setPosition(p.x, p.z);
    sv.target = null;
    sv.state = 'follow';
  }

  totem(ctx, r) {
    const def = this.engine.data.totem(r.totemIndex);
    const owner = ctx.caster;
    if (!def || !owner) return null;
    // one totem per chakra type (the index family: same name)
    for (const t of this.totems.filter(t => t.owner === owner && t.def.name === def.name)) t.destroy(false);
    this.totems = this.totems.filter(t => t.alive);
    const p = this._spot(owner, 1.2);
    const w = this.game.world;
    p.y = w?.heightAt ? w.heightAt(p.x, p.z) : owner.y;
    const t = new Totem(this, def, owner, p);
    this.totems.push(t);
    return t;
  }

  _spot(owner, d) {
    const yaw = owner.yaw || 0;
    // behind-right of the owner, walkable
    const w = this.game.world;
    for (const a of [2.4, 3.9, 0.8, Math.PI]) {
      const x = owner.x - Math.sin(yaw + a) * d, z = owner.z - Math.cos(yaw + a) * d;
      if (!w?.isWalkable || w.isWalkable(x, z)) return { x, z };
    }
    return { x: owner.x, z: owner.z };
  }

  /** Map change: servants follow the owner to the new map (re-summoned), totems end. */
  onMapChange() {
    for (const t of this.totems) t.destroy(false);
    this.totems = [];
    const keep = this.servants.filter(s => !s.dead && !s.disposed).map(s => ({ def: s.def, owner: s.owner, hp: s.hp, skill: s.skillIndex }));
    for (const s of [...this.servants]) { try { s._statusFx?.stop(true); } catch { /* continue cleanup */ } this.servants = this.servants.filter(x => x !== s); try { s.dispose(); } catch { /* ignore */ } }
    this._respawn = keep;
  }

  /** After the new map loaded (the player is placed). */
  afterMapLoad() {
    const list = this._respawn || [];
    this._respawn = null;
    for (const k of list) {
      void this.summon({ caster: this.game.player, skill: k.skill != null ? { index: k.skill } : null }, { servantIndex: k.def.index }).then(sv => { if (sv) sv.hp = Math.min(sv.maxHp, k.hp); }).catch(error => console.warn('[skills] servant map restore failed', error));
    }
  }

  // ------------------------------------------------------------------------------------------ frame
  update(dt) {
    for (const t of this.totems) t.update(dt);
    if (this.totems.some(t => !t.alive)) this.totems = this.totems.filter(t => t.alive);
    for (const sv of [...this.servants]) {
      if (sv.disposed) { this.servants = this.servants.filter(s => s !== sv); continue; }
      try { this._think(sv, dt); } catch (err) { console.warn('[skills] servant AI', err); }
      sv.update(dt);
      if (sv.dead && (sv.fadeDone || (this.game.time - (sv.diedAt || 0)) > 6)) this.dismiss(sv, false);
    }
  }

  _enemyOk(m) { return isAlive(m) && m.kind === 'monster' && m.def?.role !== 'invisible' && m.def?.role !== 'object'; }

  _pickTarget(sv) {
    const o = sv.owner;
    const cur = sv.target;
    const mode = this.mode || 'assist';
    if (mode === 'call') return null;
    if (sv.pendingGreat && this._enemyOk(sv.pendingGreat)) return sv.pendingGreat;
    sv.pendingGreat = null;
    if (sv.forced) {
      if (this._enemyOk(sv.forced)) return sv.forced;
      sv.forced = null;
      if (this.mode === 'attack') this.mode = 'assist';
    }
    if (this._enemyOk(cur) && Math.hypot(cur.x - o.x, cur.z - o.z) < LEASH) return cur;
    const ot = o.target;
    if (mode !== 'stop' && this._enemyOk(ot) && Math.hypot(ot.x - o.x, ot.z - o.z) < ASSIST_RANGE && (o.lastCombat != null && this.game.time - o.lastCombat < 8)) return ot;
    if (mode === 'free') {
      // free: engage any monster near the owner on its own
      let best = null, bd = 10;
      for (const m of this.game.spawner?.monsters || []) {
        if (!this._enemyOk(m) || m.dead) continue;
        const d = Math.hypot(m.x - sv.x, m.z - sv.z);
        if (d < bd) { bd = d; best = m; }
      }
      if (best) return best;
    }
    // whoever is fighting the owner or the servant
    let best = null, bd = ASSIST_RANGE;
    for (const m of this.game.spawner?.monsters || []) {
      if (!this._enemyOk(m)) continue;
      const t = m.brain?.target || m.target;
      if (t !== o && t !== sv) continue;
      const d = Math.hypot(m.x - sv.x, m.z - sv.z);
      if (d < bd) { bd = d; best = m; }
    }
    return best;
  }

  _block(sv, dist) {
    const now = this.game.time || 0;
    if (sv.pendingGreat && this.greatBlock(sv)) return this.greatBlock(sv);
    // the Great block only fires on the "Summon Skill" order (gauge at 100 %)
    const order = ['special', 'power', ''];
    for (const pre of order) {
      for (const a of sv.attacks) {
        const nm = a.block || '';
        const tier = nm.startsWith('great') ? 'great' : nm.startsWith('special') ? 'special' : nm.startsWith('power') ? 'power' : '';
        if (tier !== pre) continue;
        if (!(a.delayMs > 0) && tier) continue;
        if ((sv.readyAt[nm] || 0) > now) continue;
        const reach = Math.max(1.5, num(a.range) || 2) + (sv.radius || 0.5) * 0.5 + 0.5;
        if (dist > reach + 0.5 && tier) continue;
        if (tier && rand() > 0.35) continue;         // specials fire now and then, like monster power attacks
        return a;
      }
    }
    return sv.attacks.find(a => !/^(great|special|power)/.test(a.block || '')) || sv.attacks.find(a => !/^great/.test(a.block || '')) || null;
  }

  _think(sv, dt) {
    const g = this.game, o = sv.owner, now = g.time || 0;
    if (sv.dead || !o) return;
    if (o.dead) { sv.target = null; }
    const dOwner = Math.hypot(o.x - sv.x, o.z - sv.z);
    if (dOwner > LEASH + 10) { const p = this._spot(o, 1.5); sv.setPosition(p.x, p.z); sv.target = null; return; }
    // swing in progress
    if (sv.swing) {
      const s = sv.swing;
      s.t += dt;
      if (!s.hit && s.t >= s.hitAt) {
        s.hit = true;
        this._hit(sv, s.block, s.target);
      }
      if (s.t >= s.dur) sv.swing = null;
      return;
    }
    const tgt = o.dead ? null : this._pickTarget(sv);
    sv.target = tgt;
    if (tgt) {
      const blk = this._block(sv, Math.hypot(tgt.x - sv.x, tgt.z - sv.z));
      const reach = Math.max(1.5, num(blk?.range) || 2) + (sv.radius || 0.5) * 0.5 + (tgt.radius || 0.5);
      const d = Math.hypot(tgt.x - sv.x, tgt.z - sv.z);
      if (!blk) { playLoop(sv, 'idleCombat', {}, now); return; }
      if (d > reach) {
        if (this.mode === 'stop') { sv.target = null; playLoop(sv, 'idle', {}, now); return; }   // holds its spot
        this._move(sv, tgt.x, tgt.z, sv.runSpeed, dt, reach * 0.9);
        playLoop(sv, 'run', { moveSpeed: sv.runSpeed }, now, true);
        return;
      }
      sv.faceTowards(tgt.x, tgt.z);
      const nm = blk?.block || '';
      const great = /^great/.test(nm);
      if (!great && ((sv.readyAt[nm] || 0) > now || (sv.nextSwing || 0) > now)) { playLoop(sv, 'idleCombat', {}, now); return; }
      if (great && (sv.nextSwing || 0) > now) { playLoop(sv, 'idleCombat', {}, now); return; }
      if (great) { sv.charge = 0; sv.pendingGreat = null; this.game.events?.emit('servant:great', { servant: sv, target: tgt }); }
      const idx = Math.max(0, sv.attacks.indexOf(blk));
      const clip = (sv.def.attacks || [])[idx] || sv.def.anims?.attack || {};
      const dur = Math.max(0.4, num(clip.timeLength) || 1);
      sv.swing = { block: blk, target: tgt, t: 0, dur, hitAt: (num(clip.timing) || 0.5) * dur, hit: false };
      sv.readyAt[nm] = now + Math.max(dur, num(blk?.delayMs) / 1000 || 1.5);
      sv.nextSwing = now + Math.max(dur, 1);
      playOnce(sv, 'attack', { variant: idx, timeLength: dur }, now, dur);
      sv.lastCombat = now;
      return;
    }
    // stop: hold the spot; call: come back (then follow)
    if (this.mode === 'stop' && sv.holdAt) {
      const dh = Math.hypot(sv.holdAt.x - sv.x, sv.holdAt.z - sv.z);
      if (dh > 0.5) { this._move(sv, sv.holdAt.x, sv.holdAt.z, sv.runSpeed, dt, 0.3); playLoop(sv, 'run', { moveSpeed: sv.runSpeed }, now, true); }
      else playLoop(sv, 'idle', {}, now);
      return;
    }
    if (this.mode === 'call' && dOwner <= FOLLOW_DIST + 1) { this.mode = 'assist'; this.game.events?.emit('servant:order', { servant: sv, mode: 'assist' }); }
    // follow
    if (dOwner > FOLLOW_DIST + 1) {
      const p = this._spot(o, FOLLOW_DIST);
      this._move(sv, p.x, p.z, dOwner > 8 ? sv.runSpeed * 1.2 : sv.runSpeed, dt, 0.3);
      playLoop(sv, 'run', { moveSpeed: sv.runSpeed }, now, true);
    } else {
      playLoop(sv, 'idle', {}, now);
    }
  }

  _move(sv, tx, tz, speed, dt, stop) {
    const dx = tx - sv.x, dz = tz - sv.z, d = Math.hypot(dx, dz);
    if (d <= stop) return true;
    const s = Math.min(d - stop, speed * dt);
    const nx = sv.x + dx / d * s, nz = sv.z + dz / d * s;
    const w = this.game.world;
    sv.faceTowards(tx, tz);
    if (!w?.isWalkable || w.isWalkable(nx, nz)) sv.setPosition(nx, nz);
    else if (w.isWalkable(nx, sv.z)) sv.setPosition(nx, sv.z);
    else if (w.isWalkable(sv.x, nz)) sv.setPosition(sv.x, nz);
    return false;
  }

  _hit(sv, blk, tgt) {
    if (!blk || !isAlive(tgt)) return;
    const g = this.game, e = this.engine;
    sv.stats.meleeMin = sv.stats.rangeMin = sv.stats.magicMin = blk.min;
    sv.stats.meleeMax = sv.stats.rangeMax = sv.stats.magicMax = blk.max;
    const kind = /range/.test(blk.block) ? 'range' : 'melee';
    const r = blk.result;
    const ctx = { caster: sv, skill: { index: -sv.servantIndex, name: sv.name, targetMask: 5, servantBlock: blk.block }, level: 1, target: tgt, point: { x: tgt.x, z: tgt.z }, owner: sv.owner };
    if (r && r.family === 'projectile') {
      e.remotes.launch(ctx, { ...r, addDamage: 0, damageClass: kind });
      return;
    }
    const res = resolveAttack(sv, tgt, { kind, data: g.data });
    res.skill = ctx.skill;
    if (!res.miss) res.amount += Math.round(blk.absMin + rand() * Math.max(0, blk.absMax - blk.absMin));
    applyDamage(g, sv, tgt, res);
    // the servant's own hostility code: damageaggrocode.csv 4001+ -> aggroaccount.csv 11000+ (x1 damage); hooks.js skips
    // servant hits so this is the only add (indices without a row, Musfel 4181+ ..., fall back to x1)
    e.addHate(tgt, sv, plainHitHate(res.amount, sv.servantIndex, e.data?.aggro));
    if (!res.miss && r && r.statusIndex && rand() * 100 < num(r.chance || 100)) {
      e.statuses.add(tgt, r.statusIndex, num(r.statusDurationMs) || 3000, { source: sv });
    }
  }

  clear() {
    this._respawn = null;
    for (const t of this.totems) t.destroy(false);
    this.totems = [];
    for (const s of [...this.servants]) this.dismiss(s, false);
  }
}
