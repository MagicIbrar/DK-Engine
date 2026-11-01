// Integration hooks of the skills system into the shared game modules, added at run time (no rewrite of their files):
//   stats     game.refreshPlayerStats wrapper: passive / mastery options (engine.passiveEntries) are read with the
//             buffs; STAT_*_ADD raise the base stats; option codes progression does not know are applied on top
//             (HP/MP max, all-attack, min/max damage, hit, critical, guard, block, resistances, shield)
//   combat    game.combatHooks.beforeDamage (combat.applyDamage): damage-taken statuses of the player and servants
//             (melee / range / monster tolerance, damage decrease, MP transition, shield absorb, damage share with
//             the summon, damage share with a Divide caster: damage-share.js), reflect; statuses that break on damage (sleep)
//   ai        MonsterBrain: hidden (ACTION_INVISIBLE) units cannot be targeted; a hate list (aggroaccount.csv via
//             engine.addHate; aggrosetting: first-hit bonus, 30 s memory, 20 % to pull, cap) picks the target;
//             ACTION_DISALLOW_ATTACK stops swings; provoke (AI_PROVOKE) forces the target
//   combos    basic-attack combo rows with a result of their own (share/combo/combo.csv): bow arrows (remote 1) fly and
//             hit on contact, the Dragon Knight's area swings hit everything within 1 m of the target
//   player    rooted units ignore small moves (ACTION_DISALLOW_MOVE); stunned / asleep players do nothing (controller);
//             Player.partDefs shows the trans-up look (transformLook) while a transform lasts
//   events    map change (statuses, effects, summons), level up (attribute points from 200, level-up effect),
//             plain hits (combat hit / block effects), monster deaths, auto revive (STATUS_REVIVE), weapon changes
//   keys      meister move skills (Front / Retour / Droit / Gauche) on a double tap of W / S / D / A
import { MonsterBrain } from '../../game/ai.js';
import { PlayerController } from '../../game/controller.js';
import { Player } from '../../actors/player.js';
import { applyDamage, isAlive, combatOptionValue } from '../../game/combat.js';
import { optionSum } from './statuses.js';
import { planShare, shareEntries } from './damage-share.js';
import { refreshDerivedShield } from '../../game/progression.js';
import { pickTarget, plainHitHate } from '../../game/hate.js';

const num = v => (Number.isFinite(+v) ? +v : 0);
const ELEMENTS = [['fire', 'FIRE'], ['ice', 'ICE'], ['lightning', 'LIGHTNINH'], ['poison', 'POISON'], ['curse', 'CURSE'], ['dark', 'DARK']];

export function installHooks(game, sys) {
  const { engine, statuses, fx, summons, data } = sys;

  // ============================================================================================ stats layer
  const origRefresh = game.refreshPlayerStats?.bind(game);
  if (origRefresh && !game._skillsStatsHook) {
    game._skillsStatsHook = true;
    game.refreshPlayerStats = function (fill) {
      const save = this.save, p = this.player;
      if (!save || !p) return origRefresh(fill);
      const buffs = Array.isArray(save.buffs) ? save.buffs : (save.buffs = []);
      const passives = engine.passiveEntries();
      const all = buffs.concat(passives);
      const v = code => optionSum(all, code);
      const statsBak = save.stats;
      const add = { str: v('STAT_STR_ADD'), dex: v('STAT_DEX_ADD'), con: v('STAT_CON_ADD'), spr: v('STAT_SPR_ADD') };
      save.buffs = all;
      if (statsBak && (add.str || add.dex || add.con || add.spr)) {
        save.stats = { ...statsBak, str: num(statsBak.str) + add.str, dex: num(statsBak.dex) + add.dex, con: num(statsBak.con) + add.con, spr: num(statsBak.spr) + add.spr };
      }
      const hpBefore = p.hp, mpBefore = p.mp;
      try { origRefresh(fill); } finally { save.buffs = buffs; save.stats = statsBak; p.statuses = buffs; }
      const st = p.stats;
      if (!st) return;
      // option codes progression does not read
      const hpMax = Math.round((st.maxHp + v('HP_MAX_ADD')) * (1 + v('HP_MAX_MUL') / 100));
      const mpMax = Math.round((st.maxMp + v('MP_MAX_ADD')) * (1 + v('MP_MAX_MUL') / 100));
      st.maxHp = Math.max(1, hpMax); st.maxMp = Math.max(0, mpMax);
      p.maxHp = st.maxHp; p.maxMp = st.maxMp;
      if (fill) { p.hp = p.maxHp; p.mp = p.maxMp; } else { p.hp = Math.min(hpBefore ?? p.hp, p.maxHp); p.mp = Math.min(mpBefore ?? p.mp, p.maxMp); }
      const allAdd = v('COMBINE_OPTION_COMBINE_ADD');
      const allMul = 1 + (v('COMBINE_OPTION_COMBINE_MUL') - v('COMBINE_OPTION_COMBINE_SUB')) / 100;
      const adj = (lo, hi, addLo, addHi) => {
        st[lo] = Math.max(0, Math.round((num(st[lo]) + allAdd + addLo) * allMul));
        st[hi] = Math.max(st[lo], Math.round((num(st[hi]) + allAdd + addHi) * allMul));
      };
      adj('meleeMin', 'meleeMax', 0, v('DAMAGE_MAXPHYSICAL_ADD'));
      adj('rangeMin', 'rangeMax', v('RANGE_DAMAGE_MINRANGECAL_ADD'), v('RANGE_DAMAGE_MAXRANGECAL_ADD'));
      adj('magicMin', 'magicMax', v('DAMAGE_MINMAGICAL_ADD'), v('DAMAGE_MAXMAGICAL_ADD'));
      st.attackMin = st.attackType === 'range' ? st.rangeMin : st.meleeMin;
      st.attackMax = st.attackType === 'range' ? st.rangeMax : st.meleeMax;
      st.defense = Math.max(0, Math.round(num(st.defense) + v('DEFENSE_MIN_ADD') + v('DEFENSE_MAX_ADD') / 2));
      st.hitRate = Math.round(num(st.hitRate) + v('BALANCE_MARK_ADD') + v('RATING_ATTACK_ADD'));
      st.critRate = Math.max(0, Math.min(70, num(st.critRate) + v('RATING_CRITICAL_ADD') + v('BALANCE_DEATHBLOW_ADD') / 100));
      st.critMultiplier = Math.max(1, num(st.critMultiplier) + v('DAMAGERATE_CRITICAL_ADD') / 100);
      st.guardRate = Math.max(0, num(st.guardRate) + v('RATING_GUARD_ADD'));
      st.blockRate = Math.max(0, num(st.blockRate) + v('RATING_BLOCKING_ADD') + v('BALANCE_BLOCKING_ADD') / 10);
      const allRes = v('POSITIVE_ALLRESIST_ADD');
      st.resist = { ...st.resist };
      for (const [el, code] of ELEMENTS) st.resist[el] = num(st.resist[el]) + allRes + v(`POSITIVE_${code}RESIST_ADD`);
      st.magicResist = num(st.magicResist) + v('BALANCE_MAGIC_REGIST_ADD') + allRes;
      st.vitality = num(st.vitality) + v('BALANCE_VITALITY_ADD');
      // Keep captured item/buff/passive options, but use the final HP above.
      refreshDerivedShield(st);
      p.maxShield = st.maxShield;
      p.shield = Math.min(num(p.shield), p.maxShield);
    };
  }

  // ============================================================================================ combat
  game.combatHooks = game.combatHooks || {};
  const before = game.combatHooks.beforeDamage || (game.combatHooks.beforeDamage = []);
  before.push((attacker, defender, result) => {
    if (!defender || result.miss) return;
    let amt = num(result.amount);
    if (!(amt > 0)) return;
    const onPlayerSide = defender === game.player || defender.kind === 'servant';
    if (onPlayerSide && !result.dot) {
      // defensive spells proc before the hit applies (Decrease damage absorbs, Reflect damage reflects this hit)
      if (attacker?.kind === 'monster') { try { engine.spells?.onHurt(defender, attacker); } catch (err) { console.warn('[skills] spell', err); } }
      const L = statuses.listOf(defender, false) || [];
      const v = code => combatOptionValue(defender, code, { statuses: L, passiveEntries: defender === game.player ? engine.passiveEntries() : [] });
      const kind = result.kind || 'melee';
      if (kind === 'melee') amt *= 1 - Math.min(90, v('RESIST_DISTANCE_MELEEDAMAGE')) / 100;
      if (kind === 'range') amt *= 1 - Math.min(90, v('RESIST_DISTANCE_RANGEDAMAGE')) / 100;
      // Native STATUS_EX2_ALL_TOLERANCE rows all describe invincibility: a flag, not 1%.
      if (attacker?.kind === 'monster' && v('STATUS_EX2_ALL_TOLERANCE') > 0) amt = 0;
      if (attacker?.kind === 'monster') amt *= 1 - Math.min(90, v('KNIGHT_SPECIAL_MONSTER_TOLERANCE')) / 100;
      amt *= 1 - Math.min(90, v('DAMAGERATE_DAMAGEHP_MUL')) / 100;
      // damage share with the own summon (DAMAGE_OWNERSHIP "Share damage with Summoned Monster"); SHARE_DAMAGE_PARTY is a
      // different option (Divide Pain / Force) and never reaches a summon
      const share = v('DAMAGE_OWNERSHIP');
      const sv = defender === game.player ? summons.servantOf(defender) : null;
      if (share > 0 && sv && isAlive(sv)) {
        const part = Math.round(amt * Math.min(90, share) / 100);
        amt -= part;
        sv.hp = Math.max(1, sv.hp - part);
      }
      // Divide Pain / Force (damage-share.js): the protected player's SHARE_DAMAGE_PARTY entry passes sharePct of the hit to
      // the status' caster. Offline a player is its own 1-member party, so no other caster exists and nothing moves; the
      // lookup is kept so a caster present in game.actors() (never the protected unit itself) would receive the share.
      if (defender === game.player && amt > 0) {
        const plan = planShare({
          entries: shareEntries(L), amount: amt, protectedId: defender.id,
          protectorFor: entry => {
            const caster = (game.actors?.() || []).find(a => a.id != null && a.id === entry.sourceId && a !== defender && a.kind === 'player');
            return caster && isAlive(caster) ? caster : null;
          },
        });
        for (const t of plan.transfers) t.protector.hp = Math.max(1, num(t.protector.hp) - t.part);
        amt = plan.kept;
      }
      // mana shield
      const toMp = Math.min(90, v('DAMAGE_TRANSITION_MP_MUL'));
      if (toMp > 0 && num(defender.mp) > 0) {
        const part = Math.min(num(defender.mp), Math.round(amt * toMp / 100));
        defender.mp -= part; amt -= part;
      }
      // Native tooltip 23:37 identifies the PvP shield; monster hits bypass it.
      if (attacker?.kind !== 'monster' && num(defender.shield) > 0) {
        const part = Math.min(num(defender.shield), amt);
        defender.shield -= part; amt -= part;
      }
      // reflect
      const refl = amt * v('REFLECT_DAMAGEHP_MUL') / 100 + v('REFLECT_DAMAGEHP_ADD');
      if (refl >= 1 && attacker && isAlive(attacker) && attacker.kind === 'monster' && !result.reflected) {
        const r = Math.round(refl);
        queueMicrotask(() => { if (isAlive(attacker)) applyDamage(game, defender, attacker, { amount: r, miss: false, kind: 'magic', reflected: true, attackKey: 'reflect' }); });
      }
    }
    result.amount = Math.max(result.dot ? 1 : 0, Math.round(amt));
  });

  // ============================================================================================ monster AI
  const P = MonsterBrain.prototype;
  if (!P._skillsHooked) {
    P._skillsHooked = true;
    const validTarget = P._validTarget;
    P._validTarget = function (t) {
      if (t && t.invisible) return false;
      return validTarget.call(this, t);
    };
    const onDamaged = P.onDamaged;
    P.onDamaged = function (attacker, amount, result) {
      const eng = this.game?.skills;
      let who = attacker;
      if (eng?.addHate && attacker && attacker.kind !== 'monster') {
        // plain hits: damage x the class's damageaggrocode.csv -> aggroaccount.csv units (Azure Knight x1.15, Segnale x0.95 ...);
        // a servant's own hit is valued by summons.js with the servant's code, not here
        if (result && !result.skill && amount > 0 && attacker.kind !== 'servant') eng.addHate(this.m, attacker, plainHitHate(amount, this.game?.save?.classIndex, eng.data?.aggro));
        who = pickHated(this, attacker);
      }
      return onDamaged.call(this, who, amount, result);
    };
    const upd = P.update;
    P.update = function (dt) {
      const m = this.m;
      const L = m?.statuses;
      if (L && L.length) {
        const lockAtk = optionSum(L, 'ACTION_DISALLOW_ATTACK') > 0 || optionSum(L, 'ACTION_SLEEP') > 0;
        if (lockAtk && this.swing) this.swing = null;
        if (lockAtk && optionSum(L, 'ACTION_DISALLOW_MOVE') > 0) {
          // stunned / asleep: stand still (ai.js isDisabled covers the move flag; keep it from swinging too)
          return upd.call(this, dt);
        }
      }
      if (this.target && this.target.invisible) { this.target = null; this.m.target = null; this.state = 'return'; this._unfollow?.(); }
      return upd.call(this, dt);
    };
  }

  // ============================================================================================ player control
  const C = PlayerController.prototype;
  if (!C._skillsHooked) {
    C._skillsHooked = true;
    const cu = C.update;
    C.update = function (dt) {
      const p = this.player;
      const st = this.game?.statuses;
      if (p && !p.dead && st) {
        const f = st.flags(p);
        if (f.lock || (f.move && f.attack)) {
          this.order = null; this.combo = null; this._wasd = false; this._holdMove = false;
          if (p._gpState !== 'stun') {
            const state = f.sleep ? 'sleep' : 'stun';
            try { p.play(state, { loop: true }); } catch { /* ignore */ }
            p._gpState = 'stun'; p._gpHold = 0;
          }
          return;
        }
        if (p._gpState === 'stun') { p._gpState = null; p._gpHold = 0; }
      }
      return cu.call(this, dt);
    };
    // basic-attack combo rows with their own result (combo.csv): arrows fly (damage on contact), area swings
    const ucb = C._updateCombo;
    C._updateCombo = function (dt) {
      const c = this.combo;
      const eng = this.game?.skills;
      if (c && !c.hit && c.t + dt >= c.hitAt && eng?.basicAttack) {
        const row = eng.data?.comboRow?.(eng.equippedStyle(), c.k);
        const r = row?.result;
        if (r && (r.family === 'projectile' || (r.family === 'damage' && num(r.radius) > 0))) {
          c.hit = true;
          const p = this.player, t = c.target;
          if (this._validEnemy(t) && Math.hypot(p.x - t.x, p.z - t.z) <= this.reachFor(t) * 1.35 + 0.3) eng.basicAttack(t, row);
        }
      }
      return ucb.call(this, dt);
    };
  }
  const PP = Player.prototype;
  if (!PP._skillsHooked) {
    PP._skillsHooked = true;
    const sp = PP.setPosition;
    PP.setPosition = function (x, z) {
      const st = this.game?.statuses;
      if (st && !this.dead && Math.hypot(Number(x) - this.x, Number(z) - this.z) < 4 && !this._forceMove) {
        const L = this.statuses;
        if (L && L.length && optionSum(L, 'ACTION_DISALLOW_MOVE') > 0) return;
      }
      return sp.call(this, x, z);
    };
    const pd = PP.partDefs;
    PP.partDefs = function () {
      const look = this.transformLook;
      if (look?.mesh) return [{ meshKey: look.mesh, tpackKey: look.tpack || null, textures: null }];
      return pd.call(this);
    };
  }

  // ============================================================================================ events
  const ev = game.events;
  ev?.on('attack', ({ actor } = {}) => {
    // Online combo starts are predicted; only the host may consume canonical hiding.
    if (!game.network?.active && actor === game.player) statuses.onAttack(actor);
  });
  const combatFx = code => (data.modelEffects?.combat || []).find(r => r.code?.[0] === code[0] && r.code?.[1] === code[1] && r.code?.[2] === code[2])?.effect || null;
  const gameFx = (c0, c1 = 0) => (data.modelEffects?.game || []).find(r => r.code?.[0] === c0 && (r.code?.[1] ?? 0) === c1)?.effect || null;
  ev?.on('map', () => {
    engine.cancel();
    engine.remotes.clear();
    fx.clear();
    statuses.onMapChange();
    const p = game.player;
    for (const t of summons.totems) t.destroy(false);
    summons.totems = [];
    for (const sv of summons.all()) {
      if (!p) break;
      const s = summons._spot(p, 1.8);
      sv.setPosition(s.x, s.z);
      sv.target = null;
    }
    if (p?.transformLook && !p.transUpStage) { p.transformLook = null; p.refreshAppearance?.(); }
  });
  ev?.on('teleport', () => engine.cancel());
  ev?.on('network', ({ state } = {}) => { if (['connecting', 'disconnected', 'expired'].includes(state)) engine.cancel(); });
  // modeleffect 21 (combat): block [2,0,0]; a normal hit is [1,1,0] and a critical hit is [1,2,0] (same effect id, scene 2).
  const hitSpark = (target, e) => {
    const f = e.guard || e.block ? combatFx([2, 0, 0]) : e.crit ? (combatFx([1, 2, 0]) || combatFx([1, 1, 0])) : combatFx([1, 1, 0]);
    if (f) fx.play(target, f, { bone: 'body_u' });
  };
  // ONLINE: the host's damage event arrives as the cosmetic 'server:damage' (no local reward hooks), so the plain-hit /
  // crit / block spark is played from it; skill hits already play their own hitEffect through the skill event.
  ev?.on('server:damage', e => {
    const { target, source, miss, dot, skill } = e || {};
    if (!target || miss || dot || skill || !source || source.kind === 'monster') return;
    hitSpark(target, e);
  });
  ev?.on('damage', e => {
    const { target, source, amount, miss, guard, dot, skill } = e || {};
    if (!target) return;
    if (amount > 0 && !dot) statuses.onDamaged(target, amount);
    if (miss || dot) return;
    // plain (non-skill) hits: the combat hit / block spark on the struck unit (modeleffect 21)
    if (!skill && source && (source === game.player || source.kind === 'servant')) hitSpark(target, e);
    // the player's servant defends the player
    if (target === game.player && source?.kind === 'monster') for (const sv of summons.all()) if (!sv.target) sv.target = source;
    // offensive spells (Increase range, Blow attack ...) roll on every landed hit of their owner
    if (amount > 0 && target.kind === 'monster' && source && (source === game.player || source.kind === 'servant')
      && !['force', 'spell', 'reflect'].includes(e.attackKey)) {
      try { engine.spells?.onAttack(source, target); } catch (err) { console.warn('[skills] spell', err); }
    }
  });
  // spell auras: stop with the spell, come back after a map change
  ev?.on('status', ({ actor, status, on } = {}) => { if (!on && status?.spell) engine.spells?._stopAura(status); void actor; });
  ev?.on('map', () => { if (engine.spells) { engine.spells.handles = new WeakMap(); engine.spells.restore(game.player); } });
  ev?.on('death', ({ actor }) => {
    if (!actor) return;
    if (actor.kind === 'monster') {
      const f = gameFx(51);
      if (f) fx.play(actor, f, {});
    }
    if (actor === game.player) {
      engine.cancel('dead');
      const L = statuses.listOf(actor, false) || [];
      const revive = L.find(s => s.options.some(o => o.code === 'STATUS_REVIVE' && o.value));
      if (revive) {
        // auto revive (Recover Routine / revival buffs): stand up in place after 3 s
        setTimeout(() => {
          const p = game.player;
          if (!p || !p.dead) return;
          p.dead = false;
          p.hp = Math.max(1, Math.round(p.maxHp * 0.3));
          p.mp = Math.max(p.mp, Math.round(p.maxMp * 0.3));
          statuses.remove(p, revive, 'used');
          try { p.play('revive', { loop: false }); } catch { /* ignore */ }
          const f = gameFx(14);
          if (f) fx.play(p, f, {});
          ev.emit('revive', { actor: p, inPlace: true });
        }, 3000);
      } else {
        statuses.remove(actor, s => !s.keepOnDeath, 'silent');
      }
    }
  });
  ev?.on('revive', ({ actor } = {}) => {
    if (actor === game.player) { const f = gameFx(14); if (f) fx.play(actor, f, {}); }
  });
  ev?.on('levelup', ({ level, actor = game.player, server = false } = {}) => {
    const s = game.save;
    if (!server && actor === game.player && level >= 200) s.attrPoints = num(s.attrPoints) + 1;
    const f = gameFx(Number(actor?.classDef?.index ?? game.classDef?.index ?? 0) + 1) || gameFx(1);
    if (f && actor) fx.play(actor, f, {});
  });
  ev?.on('remote:levelup', ({ actor, server = false } = {}) => {
    if(!server||!actor||actor===game.player||actor.disposed)return;
    const f=gameFx(Number(actor.classDef?.index??0)+1)||gameFx(1);
    if(f)fx.play(actor,f,{});
  });
  for (const e of ['equip', 'unequip', 'inventory:equip', 'weapon']) ev?.on(e, () => engine.refreshPassives());

  // ============================================================================================ keys: move skills
  const tap = { key: null, t: -9 };
  const DIRS = { KeyW: 0, KeyS: 1, KeyD: 2, KeyA: 3 };
  sys.hookUpdate = () => {
    const inp = game.input, p = game.player;
    if (!inp || !p || p.dead || game.uiwin?.capturesInput) return;
    if (game.save?.settings?.lockMoveSkills) return;
    for (const [code, dir] of Object.entries(DIRS)) {
      if (!inp.hit?.(code)) continue;
      const now = game.time || 0;
      if (tap.key === code && now - tap.t < 0.3) {
        tap.key = null;
        const path = engine.meisterPath();
        const list = data.classRec?.moveSkills?.[path] || [];
        const idx = list[dir];
        if (idx && engine.skillLevel(idx) > 0) engine.useSkill(idx, { target: p, point: engine._frontPoint(p, 3) });
      } else { tap.key = code; tap.t = now; }
    }
  };
}

/** Highest-hate valid target of a brain (switches only when 20 % above the current one; 30 s memory): src/game/hate.js. */
function pickHated(brain, attacker) {
  const m = brain.m, hate = m?.hate instanceof Map ? m.hate : brain.hate;
  if (!hate || !hate.size) return attacker;
  const best = pickTarget({ hate }, brain.target, brain.game?.skills?.data?.aggro, (brain.game?.time || 0) * 1000, who => isAlive(who) && !who.invisible);
  return best || attacker;
}
