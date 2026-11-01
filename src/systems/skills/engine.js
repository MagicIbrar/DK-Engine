// SkillEngine: the full skill system for every class (docs/formats/skills.md Â§10, Â§13). It replaces the early
// src/game/skills.js SkillSystem as game.skills and keeps its interface (controller / HUD / windows call use(slot),
// useSlot, useSkill, busy, skillLevel, cooldownFraction, cooldownRemaining, learn, cancel, addStatus, update, clear).
//
// CAST PIPELINE (Â§10.3): learned + not passive -> control locks (stun / silence) -> weapon style in `styles` ->
// trans-up stage (awakeningCheck) -> NeedType -> cooldown (+ group skills) -> HP / MP / fury -> target by targetMask
// (4 enemy, 1 area, 16 self, 2 ally, 8 ground point, 32 dead ally, 64 own summon) -> range (walks into range first
// through the controller) -> costs + cooldown (x SPEED_COOLTIME_MUL, fSkillCoolTimeRate) -> castMs / ready / charge
// -> the level's combo steps, each exactly durationMs with its SKILL clip (skillActions[actionIndex][style]), its
// caster effect and the clip's action effect; the step result lands at the clip timing (0.5 when absent; 1-3 ms
// steps are instant markers). NO_CANCEL steps own the character (busy); ACTION steps may be cancelled by moving.
// One skill pressed during another is queued.
//
// RESULTS (Â§7): every family of the table - damage (single / area / elemental / +status / knock-back / DoT),
// projectile + ground areas (remotes.js), status (target / self / area enemy / area party / share target), heal
// (target / self / area / party / shield), summon + totem (summons.js), transform (trans-up look), cleanse, dispel,
// dash, teleport, recall, stealth, detect, sleep / shock, surrender, cooldown reset / lock, spells (proc buffs),
// damage share, auto revive, resurrect, servant explode. Solo adaptations (Â§13.10): party = the player and own
// summons; pvpDamageRate is unused.
import { skillTargetable } from '../../game/monster-rules.js';
import { resolveAttack, applyDamage, playOnce, heal as healActor, isAlive, rand, combatOptionValue, combatOptionPercent, combatClassRaw, modifyHitDamage, elementResistance } from '../../game/combat.js';
import { formulaOf } from '../../game/progression.js';
import { hateValue, addHate as addHateEntry } from '../../game/hate.js';
import { RemoteSystem } from './remotes.js';
import { SpellSystem } from './spells.js';
import { optionSum } from './statuses.js';
import {meisterRank,meisterRequirement} from './rank.js';
import {skillWeaponCompatible} from './skill-weapon.js';
import { followAura } from './follow-aura.js';
import { rootMotionCurves, rootKey, sampleRootCurve, rootToWorld } from './root-motion.js';
import { isPartyRecallSkill, withinRecallRange } from './party-recall.js';

export const INSTANT_STEP = 0.004; // s: TimeTick 1-3 ms rows are result markers (no clip); shared with network/skill-playback.js
const ROOT_SWEEP_STEP = 0.1;       // m: walkability is tested along root motion at this spacing (actor.js knockback uses the same)
const T_AREA = 1, T_ALLY = 2, T_ENEMY = 4, T_GROUND = 8, T_SELF = 16, T_DEAD = 32, T_SUMMON = 64;
const KIND_OF = { melee: 'melee', range: 'range', magic: 'magic' };
const ELEMENT_RATE = { fire: 'DAMAGERATE_FIRE_ADD', ice: 'DAMAGERATE_ICE_ADD', lightning: 'DAMAGERATE_LIGHTNING_ADD', poison: 'DAMAGERATE_POISON_ADD', curse: 'DAMAGERATE_CURSE_ADD', dark: 'DAMAGERATE_DARK_ADD', 'dark?': 'DAMAGERATE_DARK_ADD' };
const MONSTER_RESIST_INDEX = { fire: 1, ice: 2, lightning: 3, poison: 4, curse: 5, dark: 6, 'dark?': 6 };
const num = v => (Number.isFinite(+v) ? +v : 0);
const normKey = k => String(k || '').trim().replace(/\\/g, '/').replace(/^\/+/, '').toLowerCase();

/** Native CastTick gates the optional prepare templates. A zero CastTick enters
 * the authored combo directly. For example 544's combo already contains its
 * Lightning Circle ready/action clips; its header retains Fire Bolt templates.
 * Playing those as extra phases added 2520 ms not present in the level's cast
 * time or combo. Shared by caster, server and observer; no duration is guessed.
 * Global executable behaviour is unknown (owner prohibits unpacking it).
 */
export function skillPhases(skill, L) {
  const phases = [], castMs = Math.max(0, num(L?.castMs ?? skill?.castMs));
  if (castMs > 0) {
    const ready = skill?.ready;
    if (ready && num(ready.durationMs ?? ready.timeTick) > 0) phases.push({kind:'ready',act:ready,durationMs:num(ready.durationMs ?? ready.timeTick)});
    phases.push({kind:'cast',act:skill?.charge||null,durationMs:castMs});
  }
  for (const st of L?.steps || skill?.steps || []) phases.push({kind:'step',st,durationMs:num(st.durationMs)});
  return phases;
}

/** Magic Power's native header and first two combo clips reuse the same ready/charge FX scenes.
 * Keep one charge scene through those two clips so it does not flash off and restart twice. */
export function castVisualRef(skill,phases,index,ref) {
 if(!ref||Number(skill?.index)!==441)return ref;
 const phase=phases[index],same=(a,b)=>Number(a?.id)>0&&Number(a.id)===Number(b?.id)&&Number(a.scene??1)===Number(b?.scene??1);
 if(phase?.kind==='step'){
  if(Number(phase.st?.actionIndex)===40&&same(ref,skill.ready?.effect))return null;
  if(Number(phase.st?.actionIndex)===41&&same(ref,skill.charge?.effect))return null;
 }
 if(phase?.kind==='cast'&&same(ref,skill.charge?.effect)){
  const next=phases.slice(index+1,index+3);
  if(next.length===2&&next[0].kind==='step'&&Number(next[0].st?.actionIndex)===40&&next[1].kind==='step'&&Number(next[1].st?.actionIndex)===41)
   return {...ref,timeMs:Number(phase.durationMs)+Number(next[0].durationMs)+Number(next[1].durationMs)};
 }
 return ref;
}

export class SkillEngine {
  constructor(game, sys) {
    this.game = game;
    this.data = sys.data;
    this.fx = sys.fx;
    this.statuses = sys.statuses;
    this.summons = null;              // set by index.js (summons.js)
    this.remotes = new RemoteSystem(this);
    this.spells = new SpellSystem(this);      // spell.csv procs (index.js loads the table)
    this.cooldowns = new Map();       // skillIndex -> {start, end}
    this.active = null;
    this.queued = null;
    this.castProgress = null;         // {skill, t, dur} while a cast bar runs (HUD ActGage)
    this.lastUsed = new Map();        // skillIndex -> game time (NeedType 101/104 follow-ups)
    this._msgAt = -9;
    this._seq = 0;
    this._effectGeneration = 0;
    this.projectiles = [];            // compat (old field); remotes live in this.remotes
    this.messages = null;             // stringtable <cate> 60 (index.js fills it)
  }

  // ------------------------------------------------------------------------------------------ lookups
  get save() { return this.game.save; }
  get hotbar() { return this.save?.hotbar || []; }
  get busy() { return !!this.active && (this.active.noCancel || this.active.phase === 'cast'); }
  get casting() { return !!this.active; }
  /** The class skill list (skills.json records, compat fields included). */
  get list() { return this.game.classDef?.skills || []; }
  skillDef(i) { return this.data.skill(i); }
  levelData(skill, L) { return this.data.level(skill, L); }

  isPassive(skill) { return !!skill && ((num(skill.typeMask) & 3) !== 0 || skill.kind === 'passive' || skill.kind === 'mastery'); }

  /** Learned level (0 = not learned). */
  learnedLevel(index) {
    const v = this.save?.skills?.[index];
    const lv = typeof v === 'object' && v ? num(v.level) : num(v);
    return lv > 0 ? lv : 0;
  }
  /** Usable level: learned, capped by what the character level / meister path allows. */
  skillLevel(index) {
    const s = this.skillDef(index);
    if (!s) return 0;
    let lv = this.learnedLevel(s.index);
    const cap = this.maxLevelFor(s);
    if (lv > cap) lv = cap;
    return lv;
  }

  meisterPath() { return this.save?.meister?.path || null; }
  /** Highest level this character may reach: normal, or up to the chosen meister path's maximum. */
  maxLevelFor(skill) {
    if(meisterRank(this.save)<meisterRequirement(skill))return 0;
    const m = skill?.maxLevel || {};
    let max = num(m.normal);
    const p = this.meisterPath();
    if (p === 'A') max = Math.max(max, num(m.a));
    if (p === 'B') max = Math.max(max, num(m.b));
    if (skill?.tree?.window === 'meister') {
      if (skill.tree.path && skill.tree.path !== p) return 0;
      max = Math.max(max, p === 'B' ? num(m.b) : num(m.a));
    }
    return Math.min(max, skill?.levels?.length || max);
  }

  equippedStyle() {
    // the items system knows the worn weapon's stance (equip.style(): style -> 1 bare hands -> 0)
    const eq = this.game.items?.equip;
    if (typeof eq?.style === 'function') {
      try { const s = Number(eq.style()); if (Number.isFinite(s) && s >= 0) return s; } catch { /* fall back */ }
    }
    const p = this.game.player;
    const w = p?.weaponDef?.() || this.game.classDef?.weapon || {};
    const s = Number(w.style ?? w.styleIndex ?? this.save?.equipment?.weapon?.style);
    if (Number.isFinite(s) && s > 0) return s;
    return Number(this.game.classDef?.style ?? 1) || 1;
  }

  points(type = 'skill') { return type === 'attribute' ? num(this.save?.attrPoints) : num(this.save?.skillPoints); }

  // ------------------------------------------------------------------------------------------ learning
  /** Can the next level be bought? {ok, reason (message code / text), level, cost, pointType, via} */
  canLevel(index) {
    const s = this.skillDef(index), save = this.save;
    if (!s || !save) return { ok: false, reason: 50 };
    if (s.hidden) return { ok: false, reason: 50 };
    const cur = this.learnedLevel(s.index);
    const next = cur + 1;
    const L = this.levelData(s, next);
    const pointType = s.pointType === 'attribute' ? 'attribute' : 'skill';
    const out = { ok: false, level: next, cost: num(L?.spCost), pointType, via: 'points' };
    if (!L || next > this.maxLevelFor(s)) {
      if (s.tree?.window === 'meister' && !this.meisterPath()) return { ...out, reason: 59 };
      return { ...out, reason: 30, max: true };
    }
    if (s.tree?.window === 'meister') {
      if (!this.meisterPath()) return { ...out, reason: 59 };
      if (cur >= 1) return { ...out, reason: 65, via: 'reinforce' };       // meister levels come from reinforcement
    }
    if (L.availability && L.availability !== 'all') {
      const p = this.meisterPath();
      const okPath = L.availability === 'path A' ? p === 'A' : L.availability === 'path B' ? p === 'B' : !!p;
      if (!okPath) return { ...out, reason: 59 };
    }
    if (num(save.level) < num(L.reqLevel)) return { ...out, reason: 53, reqLevel: L.reqLevel };
    for (const pr of L.prereqs || []) {
      if (this.learnedLevel(pr.skill) < num(pr.level)) return { ...out, reason: 53, prereq: pr };
    }
    if (num(L.grade) > num(save.grade ?? save.transGrade)) return { ...out, reason: 53, grade: L.grade };
    if (this.points(pointType) < out.cost) return { ...out, reason: 82 };
    return { ...out, ok: true };
  }

  /** Buy the next level (spends points). Returns the new level or 0. */
  learn(index, { silent = false } = {}) {
    const s = this.skillDef(index);
    const chk = this.canLevel(index);
    if (!chk.ok) { if (!silent) this._msg(chk.reason); return 0; }
    const save = this.save;
    if (chk.cost > 0) {
      if (chk.pointType === 'attribute') save.attrPoints = num(save.attrPoints) - chk.cost;
      else save.skillPoints = num(save.skillPoints) - chk.cost;
    }
    save.skills = save.skills || {};
    save.skills[s.index] = chk.level;
    this._afterLearn(s, chk.level, silent);
    return chk.level;
  }

  /**
   * Skill book used from the bag (items use.js: def.use.meisterSkill / .skill = skill index). Meister books ("Right-click
   * to acquire Skill Lv.1") teach level 1 of a skill of the chosen meister path; later levels come from reinforcement
   * (the book goes into the reinforce window). Other skill books (riding / boarding mastery) raise the next level
   * when the character level allows it. Returns true when the book was used.
   */
  learnFromBook(index, def = null) {
    const s = this.skillDef(index);
    if (!s || !this.list.some(x => x.index === s.index)) { this._msg(45); return false; }
    const cur = this.learnedLevel(s.index);
    if (s.tree?.window === 'meister') {
      if (!this.meisterPath() || (s.tree.path && s.tree.path !== this.meisterPath())||this.maxLevelFor(s)<1) { this._msg(59); return false; }
      if (cur >= 1) { this._msg(65); return false; }
      const first=this.levelData(s,1);
      if(!first||num(this.save?.level)<num(first.reqLevel)||(first.prereqs||[]).some(pr=>this.learnedLevel(pr.skill)<num(pr.level))||num(first.grade)>num(this.save?.grade??this.save?.transGrade)){this._msg(53);return false;}
      this.setLevel(s.index, 1);
      return true;
    }
    const L = this.levelData(s, cur + 1);
    if (!L || cur + 1 > this.maxLevelFor(s)) { this._msg(30); return false; }
    if (num(this.save?.level) < num(L.reqLevel)) { this._msg(53); return false; }
    if ((L.prereqs || []).some(pr => this.learnedLevel(pr.skill) < num(pr.level)) || num(L.grade) > num(this.save?.grade ?? this.save?.transGrade)) { this._msg(53); return false; }
    if (L.availability && L.availability !== 'all') {
      const path = this.meisterPath();
      if (!(L.availability === 'path A' ? path === 'A' : L.availability === 'path B' ? path === 'B' : !!path)) { this._msg(59); return false; }
    }
    this.setLevel(s.index, cur + 1);
    void def;
    return true;
  }

  /** Set a level directly (meister reinforcement, GM tools, boxes). */
  setLevel(index, level, { silent = false } = {}) {
    const s = this.skillDef(index);
    if (!s) return 0;
    const save = this.save;
    save.skills = save.skills || {};
    const lv = Math.max(0, Math.min(s.levels?.length || 0, Math.floor(num(level))));
    if (lv <= 0) delete save.skills[s.index]; else save.skills[s.index] = lv;
    this._afterLearn(s, lv, silent);
    return lv;
  }

  _afterLearn(s, level, silent) {
    const g = this.game;
    if (!silent) {
      const text = level <= 1 ? this.msg(25) : this.msg(26);
      g.hud?.log?.(`${text}${s.name}]`, 'sys');
      const fx = (this.data.modelEffects?.game || []).find(r => r.code?.[0] === 41)?.effect;
      if (fx && g.player) this.fx?.play(g.player, fx, {});
    }
    this.refreshPassives();
    // announced: the client message (stringtable 60: 25 / 26) was already printed above
    g.events?.emit('skilllearn', { skill: s, level, announced: !silent });
  }

  /** Reset every learned skill of a point type; returns the points given back. */
  resetPoints(type = 'skill') {
    const save = this.save;
    let back = 0;
    for (const [k, v] of Object.entries(save.skills || {})) {
      const s = this.skillDef(k);
      if (!s) continue;
      const pt = s.pointType === 'attribute' ? 'attribute' : 'skill';
      if (pt !== type || s.tree?.window === 'meister') continue;
      if (this.isPassive(s) && (s.levels || []).every(l => !Number(l.spCost))) continue;   // level gifts stay
      const lv = typeof v === 'object' ? num(v.level) : num(v);
      for (let i = 1; i <= lv; i++) back += num(this.levelData(s, i)?.spCost);
      delete save.skills[k];
    }
    if (type === 'attribute') save.attrPoints = num(save.attrPoints) + back;
    else save.skillPoints = num(save.skillPoints) + back;
    this.refreshPassives();
    this.game.events?.emit('skilllearn', { reset: type });
    return back;
  }

  // ------------------------------------------------------------------------------------------ cooldowns
  cooldownRemaining(index) {
    const c = this.cooldowns.get(Number(index));
    return c ? Math.max(0, c.end - (this.game?.time || 0)) : 0;
  }
  cooldownFraction(index) {
    const c = this.cooldowns.get(Number(index));
    if (!c) return 0;
    const total = c.end - c.start;
    if (!(total > 0)) return 0;
    return Math.max(0, Math.min(1, (c.end - (this.game?.time || 0)) / total));
  }
  resetCooldowns(index = null) {
    if (index == null) this.cooldowns.clear(); else this.cooldowns.delete(Number(index));
  }
  _startCooldown(skill, L) {
    const g = this.game, p = g.player;
    const F = formulaOf(g.data);
    // Original pcclass caps this total (worn + buff + passive) at25% for all
    // current classes. Keep the raw values and the existing duration floor.
    const red = Math.min(num(combatClassRaw(p).SPEED_COOLTIME_MUL_MAX) || 25, this.optionValue(p, 'SPEED_COOLTIME_MUL'));
    let cd = num(L?.cooldownMs ?? skill.cooldownMs) / 1000 * num(F.fSkillCoolTimeRate ?? 1);
    cd *= Math.max(0.1, 1 - red / 100);
    const now = g.time || 0;
    const set = i => this.cooldowns.set(Number(i), { start: now, end: now + cd });
    set(skill.index);
    // group skills (share/groupskill/skillgroup.csv): members of a group share the cooldown
    const grp = this.data.groupSkills?.[skill.index];
    if (grp) for (const [k, v] of Object.entries(this.data.groupSkills)) if (v.group === grp.group && v.classIndex === grp.classIndex) set(k);
  }

  // ------------------------------------------------------------------------------------------ use
  use(slotOrIndex) {
    if (slotOrIndex && typeof slotOrIndex === 'object') {
      if (slotOrIndex.type === 'item') return this.game?.loot?.useItem?.(slotOrIndex) ?? false;
      return this.useSkill(slotOrIndex.skillIndex ?? slotOrIndex.index);
    }
    const n = Number(slotOrIndex);
    if (Number.isInteger(n) && n >= 0 && n < 10) {
      const e = this.hotbar[n];
      if (!e) return false;
      if (e.type === 'skill') return this.useSkill(e.index);
      if (e.type === 'item') return this.game?.loot?.useItem?.(e) ?? false;
      return false;
    }
    return this.useSkill(n);
  }
  useSlot(slot) { return this.use(Number(slot)); }

  /**
   * UI usability check for a learned active skill (2k, no side effects / no messages): grey exactly when this
   * returns {ok: false} - wrong or no weapon type, MP/HP/fury short, cooldown, mounted/dead/silenced (stunned,
   * asleep, purged), or the level/learn requirement isn't met (not learned). Lit ({ok: true}) otherwise.
   */
  usability(index) {
    const s = this.skillDef(index), p = this.game.player;
    if (!s || !p) return { ok: false, reason: 'unknown' };
    const lv = this.skillLevel(s.index);
    if (lv <= 0) return { ok: false, reason: 'unlearned' };
    if (p.dead) return { ok: false, reason: 'dead' };
    if (this.game.mounts?.isMounted?.()) return { ok: false, reason: 'mounted' };
    const fl = this.statuses.flags(p);
    if (fl.sleep || fl.skill || fl.lock || fl.attack) return { ok: false, reason: 'silenced' };
    const style = this.equippedStyle();
    if (!skillWeaponCompatible(s, style)) return { ok: false, reason: 'weapon' };
    const need = num(s.awakeningCheck);
    if (need > 0 && num(p.transUpStage) < need) return { ok: false, reason: 'stage' };
    if (this.cooldownRemaining(s.index) > 0) return { ok: false, reason: 'cooldown' };
    const L = this.levelData(s, lv) || {};
    if (this._missingTransform(s, L)) return { ok: false, reason: 'unsupported' };
    const mpRed = this.optionValue(p, 'MP_DECREASE_SPENDRESOURCE');
    const mpCost = Math.max(0, Math.round(num(L.mp ?? s.mpCost) * (1 - mpRed / 100)));
    if (mpCost > 0 && num(p.mp) < mpCost) return { ok: false, reason: 'mp' };
    const hpCost = num(L.hp ?? s.hpCost);
    if (hpCost > 0 && num(p.hp) <= hpCost) return { ok: false, reason: 'hp' };
    const furyCost = num(L.fury ?? s.furyCost);
    if (furyCost > 0 && num(p.fury) < furyCost) return { ok: false, reason: 'fury' };
    return { ok: true, reason: null };
  }

  /**
   * Cast a skill of the player. opts: {target, point, free (no costs / cooldown), level, fromProc}.
   * Returns true when it started (or the character walks into range to start it).
   */
  useSkill(index, opts = {}) {
    const g = this.game, p = g.player;
    if (!p || p.dead) return false;
    const skill = this.skillDef(index);
    if (!skill) return false;
    const level = opts.level || this.skillLevel(skill.index);
    if (level <= 0) { this._msg(45); return false; }
    if (this.isPassive(skill)) { this._msg(55); return false; }
    if (this.active && !opts.fromProc) {
      if (this.active.skill !== skill) this.queued = { index: skill.index, opts };
      return false;
    }
    const L = this.levelData(skill, level) || {};
    if (this._missingTransform(skill, L)) { this._msg('Transformation data is unavailable for this skill.'); return false; }
    const fl = this.statuses.flags(p);
    if (fl.attack || fl.sleep || fl.skill || fl.lock) { this._msg(42); return false; }
    if (g.player?.transformItem) { this._msg(86); return false; }
    // weapon style
    const style = this.equippedStyle();
    if (!skillWeaponCompatible(skill, style)) { this._msg(23); return false; }
    // trans-up stage
    const need = num(skill.awakeningCheck);
    if (need > 0 && num(p.transUpStage) < need) { this._msg(need >= 3 ? 73 : need === 2 ? 58 : 54); return false; }
    // NeedType
    const nt = this._needType(skill);
    if (nt !== true) { this._msg(nt); return false; }
    // cooldown
    if (!opts.free && this.cooldownRemaining(skill.index) > 0) { this._msg(42); return false; }
    // costs
    const mpRed = this.optionValue(p, 'MP_DECREASE_SPENDRESOURCE');
    const mpCost = Math.max(0, Math.round(num(L.mp ?? skill.mpCost) * (1 - mpRed / 100)));
    const hpCost = num(L.hp ?? skill.hpCost);
    const furyCost = num(L.fury ?? skill.furyCost);
    if (!opts.free) {
      if (num(p.mp) < mpCost) { if (this._msg(20)) this.game.audio?.ui?.('lackOfMana'); return false; }
      if (hpCost > 0 && num(p.hp) <= hpCost) { this._msg(21); return false; }
      if (furyCost > 0 && num(p.fury) < furyCost) { this._msg(41); return false; }
    }
    // target
    const tgt = this._pickTarget(skill, opts);
    if (tgt.error) { this._msg(tgt.error); return false; }
    const { target, point } = tgt;
    // range: walk into range first
    if (target && target !== p) {
      const range = Math.max(1.5, num(skill.range) || 3);
      const reach = range + (target.radius || 0.5) + 0.3;
      const contact = g.skillTargetPoint?.(target, p) || target;
      if (Math.hypot(p.x - contact.x, p.z - contact.z) > reach) {
        const ctl = g.controller;
        if (ctl?.approach && this._hostile(target)) { ctl.approach(target, range, () => this.useSkill(skill.index, opts)); return true; }
        this._msg(42);
        return false;
      }
    } else if (point && (num(skill.targetMask) & T_GROUND)) {
      const range = Math.max(2, num(skill.range) || 10);
      const d = Math.hypot(point.x - p.x, point.z - p.z);
      if (d > range) { point.x = p.x + (point.x - p.x) * range / d; point.z = p.z + (point.z - p.z) * range / d; }
    }
    // Resource readiness precedes all costs, cooldowns and authored playback clocks.
    if (this.effectResources?.defer(skill.index, opts, next => this.useSkill(skill.index, next))) return true;
    // pay + cooldown
    if (!opts.free) {
      p.mp = Math.max(0, num(p.mp) - mpCost);
      if (hpCost > 0) p.hp = Math.max(1, num(p.hp) - hpCost);
      if (furyCost > 0) p.fury = Math.max(0, num(p.fury) - furyCost);
      this._startCooldown(skill, L);
    }
    this.lastUsed.set(skill.index, g.time || 0);
    if (target && target !== p) p.faceTowards?.(target.x, target.z);
    else if (point) p.faceTowards?.(point.x, point.z);
    p.lastCombat = skill.avail ? (g.time || 0) : p.lastCombat;
    // Eligibility (including Blitz's hidden-state check) and all refusals precede consumption.
    if (skill.avail) this.statuses.onAttack?.(p);
    g.controller?.onSkillStart?.(skill, target);
    this._begin(skill, level, L, target, point, style, opts);
    g.events?.emit('skill', { actor: p, skill, level, target });
    return true;
  }

  _needType(skill) {
    const t = num(skill.needType);
    if (!t) return true;
    const [v1, v2] = (skill.needVars || []).map(Number);
    const p = this.game.player;
    const hasRange = () => (this.statuses.listOf(p, false) || []).some(s => s.statusIndex >= v1 && s.statusIndex <= v2);
    switch (t) {
      case 1: return this.summons?.servantOf(p) ? true : 56;
      case 2: case 5: return hasRange() ? true : 42;
      case 6: return hasRange() ? 42 : true;
      case 101: case 104: {
        const at = this.lastUsed.get(v1);
        return at != null && (this.game.time - at) * 1000 <= v2 ? true : 42;
      }
      case 3: {
        // Global skilldesc/concerra.csv: Blitz (1551) starts "In a hidden state".
        // Its native NeedType is 3; Invisible Shadow (1563) supplies ACTION_INVISIBLE.
        if (num(skill.index) === 1551) return this.statuses.flags(p).invisible ? true : 42;
        // Preserve Coup de grace's existing target rule; NeedType 3 is not uniformly stealth.
        const tg = p.target;
        return tg && this.statuses.flags(tg).move ? true : 42;
      }
      default: return true;
    }
  }

  _missingTransform(skill, L) {
    return (L.steps || skill.steps || []).some(step => {
      const r = step.result;
      if (r?.family !== 'transform') return false;
      const source = this.data.skill(r.transformSkill) || skill;
      return !(source.transform || []).some(row => num(row.level) === num(r.transformLevel));
    });
  }

  /** {target, point} for the skill's target mask, or {error: messageCode}. */
  _pickTarget(skill, opts) {
    const g = this.game, p = g.player;
    if (isPartyRecallSkill(skill)) return this._validRecallTarget(skill, opts.target) ? {target: opts.target, point: null} : {error: 50};
    const mask = num(skill.targetMask) || (skill.target || []).reduce((a, b) => a | b, 0);
    // Pure self actions (including Trans Up) cannot inherit a selected enemy.
    if ((mask & T_SELF) && !(mask & (T_ALLY | T_ENEMY | T_GROUND | T_DEAD | T_SUMMON))) return { target: p, point: { x: p.x, z: p.z } };
    if (opts.target) {
      const target = opts.target;
      if (target.disposed || target.kind === 'npc' || this.statuses.flags(target).target) return { error: 50 };
      if (mask & T_DEAD) {
        if (!target.dead || !['player', 'servant'].includes(target.kind)) return { error: 42 };
      } else {
        if (!isAlive(target)) return { error: 50 };
        const enemy = (mask & T_ENEMY) && this._hostile(target) && (target.kind !== 'monster' || !target.def || skillTargetable(target.def));
        const ally = (mask & T_ALLY) && ['player', 'servant'].includes(target.kind);
        const self = (mask & T_SELF) && target === p;
        const summon = (mask & T_SUMMON) && target.kind === 'servant' && target.owner === p;
        if (!(enemy || ally || self || summon)) {
          if (mask & T_GROUND) return { target: null, point: opts.point || { x: target.x, z: target.z } };
          return { error: 50 };
        }
      }
      return { target, point: opts.point || null };
    }
    if (mask & T_ENEMY) {
      const t = p.target;
      if (isAlive(t) && this._hostile(t) && !this.statuses.flags(t).target) return { target: t, point: { x: t.x, z: t.z } };
      if (mask & (T_SELF | T_GROUND)) return { target: p, point: this._frontPoint(p, 0) };
      if (mask & T_AREA) {
        // area skills without a selected enemy: the nearest enemy in range (else refused)
        const near = this.unitsNear(p, Math.max(3, num(skill.range) || 3) + 2, p, 'enemy')[0];
        if (near) { g.controller?.setTarget?.(near); return { target: near, point: { x: near.x, z: near.z } }; }
      }
      return { error: 50, target: null };
    }
    if (mask & T_GROUND) {
      const pt = opts.point || this._mouseGround() || this._frontPoint(p, Math.min(num(skill.range) || 8, 8));
      return { target: null, point: pt };
    }
    if (mask & T_DEAD) {
      const dead = this.summons?.deadServantOf?.(p);
      if (dead) return { target: dead, point: null };
      return { error: 42 };
    }
    if ((mask & T_SUMMON) && !(mask & (T_SELF | T_ALLY))) {
      const sv = this.summons?.servantOf(p);
      return sv ? { target: sv, point: null } : { error: 56 };
    }
    return { target: p, point: { x: p.x, z: p.z } };
  }

  // Offline has no other live party member; an explicit party snapshot can supply one.
  // The authoritative subclass validates records/scene/membership rather than trusting this display state.
  _validRecallTarget(skill, target) {
    const g=this.game,p=g.player,party=g.network?.party||g.party?.serverState||g.party;
    const id=a=>a?.networkId??a?.id,ids=(party?.members||[]).map(m=>typeof m==='object'?m.id:m);
    return !!party?.active&&target!==p&&target?.kind==='player'&&isAlive(target)&&!target.disposed&&!this.statuses.flags(target).target
      &&ids.includes(id(p))&&ids.includes(id(target))&&withinRecallRange(skill,p,target)&&!this._hostile(target);
  }

  _recallPartyMember(ctx) {
    const t=ctx.target,p=ctx.caster,w=this.game.world;
    if(!this._validRecallTarget(ctx.skill,t)||!w?.isWalkable?.(p.x,p.z))return false;
    t.setPosition?.(p.x,p.z);
    if(Array.isArray(t.path))t.path=[];
    return true;
  }

  _mouseGround() {
    const g = this.game, m = g.input?.mouse;
    if (!m || m.nx == null) return null;
    try { return g.pickGround?.({ x: m.nx, y: m.ny }) || null; } catch { return null; }
  }

  _frontPoint(p, d) {
    const yaw = p.yaw || 0;
    return { x: p.x - Math.sin(yaw) * d, z: p.z - Math.cos(yaw) * d };
  }

  // ------------------------------------------------------------------------------------------ playback
  _begin(skill, level, L, target, point, style, opts) {
    if (this.active) this.cancel();
    const p = this.game.player;
    // Native charwin32 and pcclass ACCELERATE_MAX: Acceleration only reduces
    // skill casting time. It stays distinct from attack/combo speed.
    const acceleration = Math.max(0, Math.min(num(combatClassRaw(p).ACCELERATE_MAX) || 20, this.optionValue(p, 'STATUS_EX_SPEED_SKILL_MUL')));
    const castMul = Math.max(0.1, 1 - (this.optionValue(p, 'SPEED_CASTING_MUL') + acceleration) / 100);
    const phases = skillPhases(skill, L).map(phase => phase.kind === 'cast' ? { ...phase, durationMs: phase.durationMs * castMul } : phase);
    this.active = {
      id: ++this._seq, skill, level, L, target, point, style, phases, i: -1, cur: null, noCancel: false,
      startX: p.x, startZ: p.z, opts, caster: p,
      handles: [], loops: [], cancelled: false, effectGeneration: this._effectGeneration,
      root: null, rootYaw: null,
    };
    this._rootLedger = { id: this.active.id, caster: p, x: 0, z: 0 };
    try { this._next(0); } catch (error) { this._abortPlayback(); throw error; }
  }

  _next(carry) {
    const a = this.active;
    if (!a) return;
    const g = this.game, p = g.player;
    a.i++;
    a.root = null;
    this._endLoops(a, a.i);
    if (a.i >= a.phases.length) { this._finish(); return; }
    const ph = a.phases[a.i];
    const dur = Math.max(0, ph.durationMs / 1000);
    a.phase = ph.kind;
    a.cur = { t: carry, dur, hitAt: null, done: true, ph };
    a.noCancel = true;
    const now = g.time || 0;
    if (ph.kind === 'cast') {
      this.castProgress = { skill: a.skill, t: 0, dur };
      if (ph.act) {
        const clip = this.data.clipForAction(a.skill, ph.act, a.style);
        const cyc = Math.max(0.05, num(ph.act.durationMs ?? ph.act.timeTick) / 1000 || dur);
        if (clip?.anim) this._playClip(p, clip, cyc, true);
        if (ph.act.effect) {const ref=castVisualRef(a.skill,a.phases,a.i,ph.act.effect);if(ref)this._playCastEffect(a, { ...ref, timeMs: ref.timeMs || ph.durationMs }, { loop: false });}
      } else {
        const first = a.phases.find(x => x.kind === 'step');
        const clip = first ? this.data.clipFor(a.skill, first.st, a.style) : null;
        if (clip?.anim) this._playClip(p, clip, dur, true);
      }
      return;
    }
    if (ph.kind === 'ready') {
      const clip = this.data.clipForAction(a.skill, ph.act, a.style);
      if (clip?.anim && dur >= INSTANT_STEP) { this._playClip(p, clip, dur); this._startRootMotion(a, ph, clip); }
      if (ph.act?.effect) this._playCastEffect(a, { ...ph.act.effect, timeMs: ph.act.effect.timeMs || ph.durationMs }, {});
      return;
    }
    // combo step
    const st = ph.st;
    a.noCancel = st.type !== 'ACTION';
    const clip = this.data.clipFor(a.skill, st, a.style);
    const timing = clip?.timing > 0 && clip.timing <= 1 ? clip.timing : 0.5;
    a.cur.hitAt = st.result ? (dur < INSTANT_STEP ? 0 : timing * dur) : null;
    a.cur.done = !st.result;
    if (dur >= INSTANT_STEP && clip?.anim) { this._playClip(p, clip, dur); this._startRootMotion(a, ph, clip); }
    // caster visuals: the step effect and the clip's action effect (once when they are the same id)
    if (st.effect) {const ref=castVisualRef(a.skill,a.phases,a.i,st.effect);if(ref)this._playCastEffect(a, ref, {});}
    const ae = clip?.actionEffect;
    if (ae && (!st.effect || Number(st.effect.id) !== Number(ae.id))) {const ref=castVisualRef(a.skill,a.phases,a.i,ae);if(ref)this._playCastEffect(a, { ...ref, timeMs: ref.timeMs || dur * 1000 }, {});}
    // movement steps (dash) start moving at the step start
    if (st.result?.family === 'dash') this._startDash(a, dur);
    // meister direction skills (moveskill.csv Front / Retour / Droit / Gauche): "Move 3m forward" ... relative to the
    // camera like the W / S / D / A keys that trigger them (a double tap)
    const mdir = this._moveSkillDir(a.skill);
    if (mdir != null && a.phases.indexOf(ph) === a.phases.findIndex(x => x.kind === 'step')) this._startMoveDash(a, mdir, dur);
    if (a.cur.hitAt === 0) this._land(a, st);
    void now;
  }

  _playClip(actor, clip, dur, loop = false) {
    const key = normKey(clip.anim);
    try { actor._skillStyles?.set?.(key, Number(clip.style ?? 1)); } catch { /* ignore */ }
    playOnce(actor, 'skill', { anim: clip.anim, timeLength: dur, loop, variant: clip.clipIndex }, this.game.time || 0, dur);
  }

  // Cosmetic asset failures must not discard the accepted cast's result timeline.
  _playCastEffect(a, ref, opts) {
    const phase = a.i;
    const retain = handle => {
      if (!handle) return;
      if (a.cancelled || a.effectGeneration !== this._effectGeneration) { try { handle.stop?.(true); } catch (error) { console.warn('[skills] effect stop failed', error); } }
      else if (handle.loop && this.active !== a) { try { handle.stop?.(false); } catch (error) { console.warn('[skills] effect stop failed', error); } }
      else { a.handles.push(handle); if (handle.loop) (a.loops ||= []).push({ handle, phase }); }
    };
    try {
      const handle = this.fx?.play(a.caster, ref, opts);
      if (handle?.then) void Promise.resolve(handle).then(retain).catch(error => console.warn('[skills] caster effect failed', error));
      else retain(handle);
    } catch (error) { console.warn('[skills] caster effect failed', error); }
  }

  _land(a, st) {
    a.cur.done = true;
    try { this.applyResult(this._ctx(a), st.result, st); } catch (err) { console.warn('[skills] result failed', a.skill.name, err); }
  }

  _ctx(a) {
    return { caster: a.caster, skill: a.skill, level: a.level, target: a.target, point: a.point, owner: this.game.player };
  }

  // A cast effect the data marks `loop 0` (EffectPlayer plays it as a loop: the clip's charge circle, 16 of the 574 clip
  // actionEffects) restarts every timeMs until somebody stops it, and nothing did: it stayed on the caster after the skill
  // (Vicious Summoner summon circle). The data has no stop rule, so ENGINE-CHOSEN: a looping
  // action effect lives while the phase (combo step) that started it runs and is stopped softly (particles fade) at the
  // next phase boundary (_next, which also runs once after the last phase). One-shot effects keep their authored length (never shortened).
  _endLoops(a, upto) {
    if (!a.loops?.length) return;
    const rest = [];
    for (const entry of a.loops) {
      if (entry.phase < upto) { try { entry.handle.stop?.(false); } catch (error) { console.warn('[skills] effect stop failed', error); } }
      else rest.push(entry);
    }
    a.loops = rest;
  }

  _finish() {
    const a = this.active;
    this.active = null;
    this.castProgress = null;
    const g = this.game;
    if (a.caster?._gpState === 'skill') { a.caster._gpState = null; a.caster._gpHold = 0; }
    try { g.controller?.onSkillEnd?.(a.skill, a.target); } catch (err) { console.warn(err); }
    g.events?.emit('skill:end', { actor: g.player, skill: a.skill });
    if (this.queued) {
      const q = this.queued;
      this.queued = null;
      this.useSkill(q.index, q.opts || {});
    }
  }

  cancel(reason = null) {
    this.effectResources?.cancel();
    const a = this.active;
    this._effectGeneration = (this._effectGeneration || 0) + 1;
    this.active = null;
    this.queued = null;
    this.castProgress = null;
    this._dashes = (this._dashes || []).filter(d => d.actor !== this.game.player && d.actor !== a?.caster);
    for (const player of new Set([this.game.player, a?.caster])) {
      if (player?._gpState === 'skill') { player._gpState = null; player._gpHold = 0; }
    }
    if (a) {
      a.cancelled = true;
      for (const handle of a.handles || []) { try { handle?.stop?.(true); } catch (error) { console.warn('[skills] effect stop failed', error); } }
      a.handles = [];
      if (reason) this._msg(reason === 'dead' ? 19 : 18);
    }
  }

  // ------------------------------------------------------------------------------------------ frame
  update(dt) {
    try { this._updateFrame(Math.max(0, num(dt))); } catch (error) { this._abortPlayback(); throw error; }
  }

  /**
   * Following auras (Dual Chakra, both summoner classes): "two Sacras float around you" for the skill's long self status while
   * their party/enemy statuses last only 3 s. Totem Chakras use the same convention in the same data (aura durationMs 3000,
   * tickMs 1000), so while the carrier status lives the area result is re-applied around the caster every second. Without this
   * the aura of a 63 s skill ended 3 s after the cast.
   */
  _startFollowAura(ctx, r, ms) {
    const list = this._followAuras ||= [];
    const key = `${ctx.caster?.id ?? ctx.caster?.name ?? 'c'}:${ctx.skill?.index}:${r.family}`;
    for (let i = list.length - 1; i >= 0; i--) if (list[i].key === key) list.splice(i, 1);
    const now = this.game.time || 0;
    list.push({ key, ctx: { caster: ctx.caster, skill: ctx.skill, level: ctx.level, target: null, point: null }, r, carrier: ms.status, until: now + ms.durationMs / 1000, next: now + 1, started: now, seen: false });
  }

  _updateFollowAuras() {
    const list = this._followAuras;
    if (!list?.length) return;
    const now = this.game.time || 0;
    for (let i = list.length - 1; i >= 0; i--) {
      const a = list[i], caster = a.ctx.caster;
      const carrier = (this.statuses.listOf(caster, false) || []).some(s => num(s.statusIndex) === a.carrier && !(s.remaining != null && s.remaining <= 0));
      // the carrier self status lands a step after the area steps: wait for it (5 s grace), then end with it
      if (carrier) a.seen = true;
      if (now >= a.until || !isAlive(caster) || caster.disposed || (a.seen ? !carrier : now > a.started + 5)) { list.splice(i, 1); continue; }
      if (now < a.next) continue;
      a.next += 1;
      if (a.next <= now) a.next = now + 1;
      this.applyImpact(a.ctx, a.r, null, { x: caster.x, z: caster.z });
    }
  }

  // A failed animation/effect must not leave NO_CANCEL active forever while the
  // outer game loop catches the same exception on every subsequent frame.
  _abortPlayback() {
    this.cancel();
  }

  _updateFrame(dt) {
    const g = this.game, p = g.player;
    if (p && g.save) {
      if (!Array.isArray(g.save.buffs)) g.save.buffs = [];
      p.statuses = g.save.buffs;
    }
    this.statuses.update(dt);
    this.remotes.update(dt);
    this._updateFollowAuras(dt);
    this._updateDashes(dt);
    this._updateTransUp();
    const a = this.active;
    if (!a) return;
    if (!p || p.dead || p.disposed || p !== a.caster) { this.cancel('dead'); return; }
    // ACTION steps: moving cancels the rest of the chain
    if (!a.noCancel && !a.dashing && Math.hypot(p.x - a.startX, p.z - a.startZ) > 0.35) { this.cancel(); return; }
    const fl = this.statuses.flags(p);
    if (fl.lock || fl.sleep) { this.cancel(18); return; }
    let budget = dt, guard = 0;
    while (this.active === a && a.cur && guard++ < 64) {
      const c = a.cur;
      const need = c.dur - c.t;
      const step = Math.min(budget, Math.max(0, need));
      c.t += step;
      budget -= step;
      // the origin moves before this frame's result lands: range / area centres use the moved position
      this._advanceRootMotion(a, c);
      if (this.active !== a) break;
      if (this.castProgress && c.ph.kind === 'cast') this.castProgress.t = c.t;
      if (!c.done && c.hitAt != null && c.t >= c.hitAt - 1e-9) this._land(a, c.ph.st);
      if (c.t >= c.dur - 1e-9) {
        if (c.ph.kind === 'cast') this.castProgress = null;
        a.startX = p.x; a.startZ = p.z;
        this._next(0);
      } else break;
      if (budget <= 0 && this.active === a && a.cur && a.cur.dur >= INSTANT_STEP) break;
    }
  }

  // ------------------------------------------------------------------------------------------ units
  sideOf(u) { return !u ? null : u.kind === 'monster' ? 'monster' : 'player'; }
  /** A unit the player's skills treat as an enemy: monsters, plus a PvP duel opponent (game.isPvpHostile, PVP-DUEL). */
  _hostile(u) { return !!u && (u.kind === 'monster' || (u.kind === 'player' && !!this.game?.isPvpHostile?.(u))); }
  /** Enemies / allies of `ref` within radius of point (sorted by distance). side: 'enemy' | 'ally'. */
  unitsNear(point, radius, ref, side = 'enemy') {
    const g = this.game;
    const refSide = this.sideOf(ref) || 'player';
    const want = side === 'enemy' ? (refSide === 'player' ? 'monster' : 'player') : refSide;
    const pool = want === 'monster' ? (g.spawner?.monsters || []) : [g.player, ...(this.summons?.all() || [])];
    const out = [];
    for (const u of pool) {
      if (!isAlive(u) || u.kind === 'npc') continue;
      if (want === 'monster' && u.def && !skillTargetable(u.def)) continue;
      const d = Math.hypot(u.x - point.x, u.z - point.z);
      if (d <= radius + (u.radius || 0.5) * 0.5) out.push([d, u]);
    }
    out.sort((a, b) => a[0] - b[0]);
    return out.map(e => e[1]);
  }

  // ------------------------------------------------------------------------------------------ results
  /** Apply a step result for a cast context (ctx: caster, skill, level, target, point). */
  applyResult(ctx, r, st = null) {
    if (!r) return;
    const fam = r.family;
    // (no hostility at launch: the impact applies the hoisted result, which adds it once; a launch-time add doubled the flat
    // part and the first-hit bonus of e.g. code 2104)
    if (fam === 'projectile') { this.remotes.launch(ctx, r); return; }
    if (fam === 'area_status_party' || fam === 'area_status_enemy') {
      const follow = followAura(ctx.skill, ctx.level);
      if (follow) this._startFollowAura(ctx, r, follow);
    }
    const primary = ctx.target && ctx.target !== ctx.caster ? ctx.target : null;
    this.applyImpact(ctx, r, primary, ctx.point || (primary ? { x: primary.x, z: primary.z } : { x: ctx.caster.x, z: ctx.caster.z }));
    void st;
  }

  /**
   * Apply a result (a step result or a remote impact) on `unit` and/or around `point`.
   * extra: {contactEffect, maxUnits}
   */
  applyImpact(ctx, r, unit, point, extra = {}) {
    const g = this.game, caster = ctx.caster;
    if (!caster || !r) return;
    const fam = r.family;
    const radius = num(r.radius);
    const enemiesAt = (pt, rad) => {
      let list = rad > 0 ? this.unitsNear(pt, rad, caster, 'enemy') : [];
      if (unit && isAlive(unit) && this._hostile(unit) && !list.includes(unit)) list.unshift(unit);
      if (extra.maxUnits > 0) list = list.slice(0, extra.maxUnits);
      return list;
    };
    const alliesAt = (pt, rad) => {
      const list = rad > 0 ? this.unitsNear(pt, rad, caster, 'ally') : [caster];
      if (!list.includes(caster) && isAlive(caster) && Math.hypot(caster.x - pt.x, caster.z - pt.z) <= rad) list.unshift(caster);
      return extra.maxUnits > 0 ? list.slice(0, extra.maxUnits) : list;
    };
    const center = point || (unit ? { x: unit.x, z: unit.z } : { x: caster.x, z: caster.z });
    // totems and launch-6 ground areas (remotes.js, AREA STAYS) pulse around their own fixed centre (extra.center), everything else around the caster
    const selfCenter = extra.center ? { x: extra.center.x, z: extra.center.z } : { x: caster.x, z: caster.z };
    const isSelfSkill = (num(ctx.skill?.targetMask) & T_ENEMY) === 0;
    const areaCenter = isSelfSkill && !unit ? selfCenter : center;
    const onHit = (t) => {
      const he = r.hitEffect || extra.contactEffect;
      if (he && t) this.fx?.play(t, he, {});
    };
    switch (fam) {
      case 'damage':
      case 'damage_special':
      case 'servant_explode': {
        if (r.shape === 'area_dot' && r.dotStatusIndex) {
          // area damage over time: the DoT status on every enemy in the area
          for (const t of enemiesAt(areaCenter, radius || 3)) { this.statuses.add(t, r.dotStatusIndex, num(r.statusDurationMs) || 5000, { source: caster, skill: ctx.skill }); onHit(t); this._aggro(ctx, r, t, 0); }
          break;
        }
        let rad = radius;
        if (fam === 'damage_special' && !r.addDamage && r.args?.[2]) rad = 0;
        const origin = fam === 'servant_explode' ? (this.summons?.servantOf(caster) || caster) : null;
        const targets = enemiesAt(origin ? { x: origin.x, z: origin.z } : areaCenter, rad);
        for (const t of targets) {
          const res = this.skillDamage(ctx, t, r);
          onHit(t);
          applyDamage(g, caster, t, res);
          this._aggro(ctx, r, t, res.amount);
          if (!res.miss) this._secondary(ctx, r, t);
        }
        if (origin && origin !== caster) this.summons?.explode(origin);
        break;
      }
      case 'status': {
        const self = r.target === 'self' || (r.target !== 'target' && isSelfSkill);
        const t = self ? caster : (unit || ctx.target || primaryEnemy(ctx));
        if (t) this._applyStatusResult(ctx, r, t, onHit);
        break;
      }
      case 'area_status_enemy': case 'sleep_shock': case 'surrender': {
        const list = (fam === 'area_status_enemy' || r.resultCode === 7000004 || radius > 0) ? enemiesAt(areaCenter, radius || 2) : (unit ? [unit] : []);
        for (const t of list) this._applyStatusResult(ctx, r, t, onHit);
        break;
      }
      case 'share_target': {
        // Point target is an invitation to party members, never an enemy-area
        // status. The host owns consent, target binding and buff lifetime.
        g.shareTarget?.(ctx,r,unit||ctx.target);
        break;
      }
      case 'area_status_party': {
        const list = alliesAt(!isSelfSkill && unit ? center : selfCenter, radius || 5);
        let rr = r;
        // "impossible to know which buff will be applied" (Jiquve): no status, Arg5 = random_buff.csv pool
        const pool = !num(r.statusIndex) ? num(r.args?.[4]) : 0;
        if (pool > 0) {
          const opts = this.data.randomBuff?.[pool] || [];
          const pick = opts[Math.floor(rand() * opts.length)];
          if (pick) rr = { ...r, statusIndex: pick.statusIndex };
        }
        for (const t of list) this._applyStatusResult(ctx, rr, t, onHit);
        break;
      }
      case 'spell_self': case 'spell_party': {
        // Arg1 = share/article/spell.csv row (spells.js), not a status
        if (this.spells?.cast(ctx, r)) onHit(caster);
        break;
      }
      case 'auto_revive': case 'stealth': case 'damage_share': {
        const list = fam === 'spell_party' || fam === 'damage_share' ? alliesAt(selfCenter, radius || 20) : [caster];
        for (const t of list) this._applyStatusResult(ctx, { ...r, chance: r.chance || 100, durationMs: r.durationMs || this._statusDefaultMs(r) }, t, onHit);
        break;
      }
      case 'heal': case 'heal_area': case 'shield_heal': {
        const list = fam === 'heal_area' ? alliesAt(r.target === 'target_area' && unit ? center : selfCenter, radius || 7)
          : [r.target === 'self' || !unit || this.sideOf(unit) !== this.sideOf(caster) ? caster : unit];
        const spr = num(caster.stats?.spr ?? g.save?.stats?.spr);
        const mul = Math.max(0, 1 + (this.optionValue(caster, 'HP_FLUCTUATE_PLUSE_MUL') - this.optionValue(caster, 'HP_FLUCTUATE_REDUCE_MUL')) / 100);
        const flat = this.optionValue(caster, 'HP_FLUCTUATE_PLUSE_ADD') - this.optionValue(caster, 'HP_FLUCTUATE_REDUCE_ADD');
        for (const t of list) {
          const amount = Math.max(0, Math.round((num(r.amount) + num(r.perSpr) * spr + flat) * mul));
          if (fam === 'shield_heal') {
            t.shield = Math.min(num(t.maxShield) || amount, num(t.shield) + amount);
            g.events?.emit('heal', { source: caster, target: t, amount, shield: true });
          } else {
            if (this.statuses.value(t, 'HP_RECOVERY_IMPOSSIBLE')) continue;
            const got = healActor(g, caster, t, amount);
            this._aggro(ctx, r, null, got);
          }
          onHit(t);
        }
        break;
      }
      case 'resurrect': {
        const t = unit && unit.dead ? unit : this.summons?.deadServantOf?.(caster);
        if (t && t.dead && t.revive) { t.revive(0.3); onHit(t); }
        break;
      }
      case 'summon': {
        const pending = this.summons?.summon(ctx, r);
        if (pending?.then) void Promise.resolve(pending).catch(error => console.warn('[skills] summon failed', error));
        break;
      }
      case 'totem': this.summons?.totem(ctx, r); break;
      case 'transform': this._transform(ctx, r); break;
      case 'cleanse': {
        const list = r.resultCode === 7000009 ? alliesAt(selfCenter, radius || 5) : [unit && this.sideOf(unit) === this.sideOf(caster) ? unit : caster];
        for (const t of list) {
          if (rand() * 100 >= (num(r.chance) || 100)) continue;
          this.statuses.removeGroup(t, r.statusGroup, num(r.count) || 1);
          onHit(t);
        }
        break;
      }
      case 'dispel': {
        const t = unit || primaryEnemy(ctx);
        if (t && rand() * 100 < (num(r.chance) || 100)) {
          this.statuses.removeGroup(t, r.statusGroups || [], num(r.count) || 1, { buffs: true });
          onHit(t);
        }
        this._aggro(ctx, r, t, 0);
        break;
      }
      case 'dash': break;                                   // movement ran from the step start (_startDash)
      case 'teleport': {
        const pt = ctx.point;
        const w = g.world;
        if (pt && caster === g.player && (!w?.isWalkable || w.isWalkable(pt.x, pt.z))) {
          caster.setPosition(pt.x, pt.z);
          g.cam?.snap?.();
          g.controller?.stop?.();
          onHit(caster);
        }
        break;
      }
      case 'recall': this._recallPartyMember(ctx); break;
      case 'detect': {
        for (const m of g.spawner?.monsters || []) {
          if (!m.invisible) continue;
          if (Math.hypot(m.x - caster.x, m.z - caster.z) <= (radius || 10)) this.statuses.remove(m, s => optionSum([s], 'ACTION_INVISIBLE') > 0, 'detected');
        }
        break;
      }
      case 'cooldown_reset': {
        if (r.all) this.resetCooldowns(); else if (r.skillIndex) this.resetCooldowns(r.skillIndex);
        break;
      }
      case 'cooldown_lock': {
        // "turns the target's skill cooldowns by force": the target's special attacks wait their full delay again
        const t = unit || primaryEnemy(ctx);
        if (t?.brain) { t.brain.specialReadyAt = (g.time || 0) + 10; t.brain.powerReadyAt = (g.time || 0) + 10; }
        break;
      }
      case 'shield_break': {
        const t = unit || primaryEnemy(ctx);
        if (t) { t.shield = 0; onHit(t); }
        break;
      }
      default: {
        if (num(r.addDamage) > 0) for (const t of enemiesAt(areaCenter, radius)) { const res = this.skillDamage(ctx, t, r); onHit(t); applyDamage(g, caster, t, res); }
      }
    }
  }

  _statusDefaultMs(r) {
    const d = this.data.status(r.statusIndex);
    return d ? 600000 : 0;                                  // spell buffs without a duration last 10 minutes
  }

  /** Status part of a result on one unit (chance, statusIndex, duration; statusIndex2 / chance2). */
  _applyStatusResult(ctx, r, t, onHit) {
    if (!t || (t.dead && r.family !== 'resurrect')) return;
    const caster = ctx.caster;
    const hostile = this.sideOf(t) !== this.sideOf(caster);
    const ms = num(r.durationMs || r.statusDurationMs);
    const chance = r.chance == null ? 100 : num(r.chance);
    let applied = false;
    if (r.statusIndex && ms > 0 && (!hostile || rand() * 100 < this._statusChance(caster, t, chance))) {
      this.statuses.add(t, r.statusIndex, ms, { source: caster, skill: ctx.skill, level: ctx.level, blocksSkills: r.family === 'surrender' });
      applied = true;
    }
    if (r.statusIndex2 && ms > 0 && (!hostile || rand() * 100 < this._statusChance(caster, t, num(r.chance2) || 100))) {
      this.statuses.add(t, r.statusIndex2, ms, { source: caster, skill: ctx.skill, level: ctx.level });
      applied = true;
    }
    if (hostile) {
      this._aggro(ctx, r, t, 0);
      if (applied) t.brain?.onDamaged?.(caster, 0);
      if (applied && this.statuses.value(t, 'AI_PROVOKE') > 0 && t.brain) t.brain.engage?.(caster);
    }
    if (applied || !hostile) onHit(t);
  }

  /** Status landing chance vs the target's abnormal-status resistance (RATING_ANTI_STATUS_ADD / ANTI_ANTI_RATE). */
  _statusChance(caster, t, chance) {
    const res = this.optionValue(t, 'RATING_ANTI_STATUS_ADD') + num(t.def?.antiStatusRate);
    const ignore = this.optionValue(caster, 'ANTI_ANTI_SUB') + this.optionPercent(caster, 'ANTI_ANTI_RATE');
    return Math.max(0, Math.min(100, chance - Math.max(0, res - ignore)));
  }

  /** Status / knock-back riding on a landed damage result. */
  _secondary(ctx, r, t) {
    if (r.statusIndex && t && !t.dead) this._applyStatusResult(ctx, { ...r, durationMs: r.statusDurationMs || r.durationMs }, t, () => {});
    if (r.randomDebuffs > 0) {
      const pool = this.data.randomBuff?.[r.randomDebuffs] || this.data.randomBuff?.[1] || [];
      const pick = pool[Math.floor(rand() * pool.length)];
      if (pick) this.statuses.add(t, pick.statusIndex, num(r.statusDurationMs) || 5000, { source: ctx.caster, skill: ctx.skill });
    }
    if (r.shape === 'area_status' && t && !t.dead && !this.statuses.has(t, 'KNOCKBACK_OFF') && t.kind === 'monster' && !t.def?.antiKnockBack) {
      // area + knock-back: push 1.5 m away from the caster
      const c = ctx.caster;
      const dx = t.x - c.x, dz = t.z - c.z, d = Math.hypot(dx, dz) || 1;
      if (typeof t.knockback === 'function') t.knockback(dx / d, dz / d, 1.5, 0.22);
      else {
        const nx = t.x + dx / d * 1.5, nz = t.z + dz / d * 1.5;
        if (!this.game.world?.isWalkable || this.game.world.isWalkable(nx, nz)) t.setPosition(nx, nz);
      }
    }
  }

  /**
   * Damage of one skill hit (combat.resolveAttack with the skill's damage class, addDamage and the weapon %),
   * plus the elemental part (elementPct % of it, x the caster's DAMAGERATE_<element> and the target's resistance)
   * and the boss bonus. Returns a combat result.
   */
  skillDamage(ctx, t, r) {
    const caster = ctx.caster;
    const kind = KIND_OF[r.damageClass] || KIND_OF[ctx.skill?.type] || undefined;
    const mult = num(r.damagePct) > 0 ? num(r.damagePct) / 100 : 1;
    const res = resolveAttack(caster, t, { skill: ctx.skill, kind, addDamage: num(r.addDamage), multiplier: mult, data: this.game.data, noMiss: r.family === 'servant_explode', deferFinalModifiers: true });
    res.skill = ctx.skill;
    if (res.miss || !(res.amount > 0)) return res;
    let amt = res.amount;
    const el = r.element;
    if (el && ELEMENT_RATE[el]) {
      res.element = el; res.elementShare = (num(r.elementPct) || 100) / 100;   // read by the PvP stage (pvp-rules PC_DAMAGE_<element>RESIST_*)
      const part = amt * (num(r.elementPct) || 100) / 100;
      const bonus = this.optionValue(caster, ELEMENT_RATE[el]) / 100;
      const resist = elementResistance(t, el === 'dark?' ? 'dark' : el, MONSTER_RESIST_INDEX[el]);
      amt += part * bonus - part * resist / 100;
    }
    res.amount = modifyHitDamage(caster, t, amt);
    return res;
  }

  /**
   * Basic-attack combo step with a result of its own (share/combo/combo.csv via hooks.js): the bow / crossbow arrow
   * (3000001 -> remote 1 "basic arrow", the damage lands on contact) and the Dragon Knight's area swings (1000201,
   * 1 m around the target). Plain single hits stay with the controller.
   */
  basicAttack(target, row) {
    const g = this.game, p = g.player, r = row?.result;
    if (!p || !r || !isAlive(target)) return false;
    const ctx = { caster: p, skill: null, level: 1, target, point: { x: target.x, z: target.z }, owner: p, basic: true };
    if (r.family === 'projectile') { this.remotes.launch(ctx, { ...r }); return true; }
    const list = this.unitsNear({ x: target.x, z: target.z }, Math.max(0.5, num(r.radius)), p, 'enemy');
    if (!list.includes(target)) list.unshift(target);
    for (const t of list) {
      const res = resolveAttack(p, t, { data: g.data });
      applyDamage(g, p, t, res);
    }
    return true;
  }

  /** Damage-over-time tick from a status (statuses.js). */
  dotDamage(src, target, amount, status) {
    if (!target || target.dead) return;
    applyDamage(this.game, src || null, target, { amount, miss: false, dot: true, kind: 'magic', status });
  }

  // ------------------------------------------------------------------------------------------ aggro
  /** Hostility from a landed result (aggroaccount.csv units: 3 = x damage / (unit 4 value), 1 = flat): src/game/hate.js. */
  _aggro(ctx, r, t, amount) {
    if (!t || t.kind !== 'monster') return;
    this.addHate(t, ctx.caster, hateValue(amount, r?.aggro, this.data.aggro));
  }

  /**
   * Add hostility of `who` on monster `m` (aggrosetting.csv cap / first-hit bonus), stored on the monster record itself
   * (m.hate, shared with the server's authoritative records; the client brain's `hate` is the same Map). A servant's
   * hostility is credited to its owner on the server (ENGINE-CHOSEN: server monsters target players only); offline the
   * servant keeps its own entry and may be attacked (whether the original did either is not in the data).
   */
  addHate(m, who, v) {
    if (!m || !who) return;
    const rec = m._record || m;
    if (!(rec.hate instanceof Map)) rec.hate = m.brain?.hate instanceof Map ? m.brain.hate : new Map();
    if (m.brain) m.brain.hate = rec.hate;
    const key = who._record?.id ?? who.owner?._record?.id ?? who;
    addHateEntry(rec, key, v, this.data.aggro, (this.game.time || 0) * 1000);
  }

  // ------------------------------------------------------------------------------------------ movement
  _startDash(a, dur) {
    const p = a.caster, t = a.target;
    if (!t || t === p) return;
    const dx = t.x - p.x, dz = t.z - p.z, d = Math.hypot(dx, dz);
    const stop = (t.radius || 0.5) + (p.radius || 0.4) + 0.3;
    if (d <= stop) return;
    const len = d - stop;
    this._dashes = this._dashes || [];
    this._dashes.push({ actor: p, ux: dx / d, uz: dz / d, left: len, speed: len / Math.max(0.12, Math.min(dur || 0.3, 0.6)) });
    a.dashing = true;
  }

  /** 0 front, 1 back, 2 right, 3 left for the class's meister move skills; null otherwise. */
  _moveSkillDir(skill) {
    const ms = this.data.classRec?.moveSkills || {};
    for (const list of Object.values(ms)) {
      const i = (list || []).map(Number).indexOf(Number(skill?.index));
      if (i >= 0 && i < 4) return i;
    }
    return null;
  }

  _startMoveDash(a, dir, dur) {
    const g = this.game, p = a.caster;
    const m = /(\d+(?:\.\d+)?)\s*m\b/i.exec(a.skill.description || '');
    const dist = m ? Number(m[1]) : 3;
    const b = g.cam?.groundBasis?.();
    let fx, fz, rx, rz;
    if (b) { fx = b.forward.x; fz = -b.forward.z; rx = b.right.x; rz = -b.right.z; }
    else { fx = -Math.sin(p.yaw || 0); fz = -Math.cos(p.yaw || 0); rx = -fz; rz = fx; }
    const v = [[fx, fz], [-fx, -fz], [rx, rz], [-rx, -rz]][dir];
    const len = Math.hypot(v[0], v[1]) || 1;
    this._dashes = this._dashes || [];
    this._dashes.push({ actor: p, ux: v[0] / len, uz: v[1] / len, left: dist, speed: dist / Math.max(0.12, dur || 0.5) });
    a.dashing = true;
  }

  _updateDashes(dt) {
    if (!this._dashes?.length) return;
    const w = this.game.world;
    this._dashes = this._dashes.filter(d => {
      if (!d.actor || d.actor.dead || d.actor.disposed) return false;
      const s = Math.min(d.left, d.speed * dt);
      const nx = d.actor.x + d.ux * s, nz = d.actor.z + d.uz * s;
      if (w?.isWalkable && !w.isWalkable(nx, nz)) return false;
      d.actor.setPosition(nx, nz);
      d.left -= s;
      if (this.active?.caster === d.actor) { this.active.startX = d.actor.x; this.active.startZ = d.actor.z; }
      return d.left > 1e-3;
    });
  }

  // ------------------------------------------------------------------------------------------ root motion
  // A played ready / combo-step clip moves the caster along its own authored root curve (root-motion.js; Global's
  // share/movecache.csv is the native End - Start table of the same displacement). One movement owner per phase: an
  // explicit dash / teleport result and the meister direction skills keep their own movement and play no root curve.
  // The looping charge clip of a cast bar never moves. Walls stop the origin at the first blocked 0.1 m step; the
  // refused part is dropped, never stored for a later burst. Host, offline engine and the caster's own prediction run
  // this same code; observers receive the host's moved pose (server/world/movement-authority.mjs).
  _rootOwned(a, ph) {
    if (this._moveSkillDir(a.skill) != null) return true;
    const family = ph.kind === 'step' ? ph.st?.result?.family : null;
    return family === 'dash' || family === 'teleport';
  }

  _startRootMotion(a, ph, clip) {
    a.root = null;
    if (ph.kind === 'cast' || this._rootOwned(a, ph)) return;
    const curve = (this.data.rootMotionCurves || rootMotionCurves).get(rootKey(clip?.anim));
    if (!curve) return;
    const p = a.caster;
    // one combo, one frame: the clips of a combo continue one authored curve, so the facing at the first moving
    // clip holds for the whole cast (the target was faced when the cast started)
    if (a.rootYaw == null) a.rootYaw = Number.isFinite(p.targetYaw) ? p.targetYaw : (Number(p.yaw) || 0);
    a.root = { curve, ph, lx: 0, lz: 0, blocked: false };
  }

  _advanceRootMotion(a, c) {
    const r = a.root;
    if (!r || r.ph !== c.ph) return;
    const s = sampleRootCurve(r.curve, c.dur > 0 ? c.t / c.dur : 1);
    const lx = s.x - r.lx, lz = s.z - r.lz;
    r.lx = s.x; r.lz = s.z;
    if (!(Math.abs(lx) > 1e-7 || Math.abs(lz) > 1e-7)) return;
    const w = rootToWorld(lx, lz, a.rootYaw);
    const p = a.caster, bx = p.x, bz = p.z;
    if (!this._rootStep(p, w.x, w.z)) return;
    const dx = p.x - bx, dz = p.z - bz;
    a.startX = p.x; a.startZ = p.z;
    const ledger = this._rootLedger;
    if (ledger?.id === a.id) { ledger.x += dx; ledger.z += dz; }
    const d = this._rootDelta ||= { x: 0, z: 0 };
    d.x += dx; d.z += dz;
    this._rootMovedAt = this.game.time || 0;
  }

  /** The cast's root curve is moving the caster, or moved it within `seconds` (a client keeps its own body meanwhile). */
  rootHolding(seconds = 0.3) {
    return !!this.active?.root || (this.game.time || 0) - (this._rootMovedAt ?? -Infinity) < seconds;
  }

  /** Move `actor` by (dx, dz), tested for walkability every ROOT_SWEEP_STEP; stops at the first blocked step. */
  _rootStep(actor, dx, dz) {
    const len = Math.hypot(dx, dz);
    if (!(len > 0) || !actor || actor.dead || actor.disposed) return false;
    const w = this.game.world, n = Math.max(1, Math.ceil(len / ROOT_SWEEP_STEP));
    const sx = actor.x, sz = actor.z;
    let x = sx, z = sz;
    for (let i = 1; i <= n; i++) {
      const nx = sx + dx * i / n, nz = sz + dz * i / n;
      if (w?.isWalkable && !w.isWalkable(nx, nz)) break;
      x = nx; z = nz;
    }
    if (x === sx && z === sz) return false;
    actor.setPosition(x, z);
    return actor.x !== sx || actor.z !== sz;
  }

  /** Host: the root displacement applied since the last call ({x, z}); resets it. */
  takeRootDelta() {
    const d = this._rootDelta;
    this._rootDelta = null;
    return d && (d.x || d.z) ? d : null;
  }

  /** A NO_CANCEL / ready phase is moving the caster along its root curve (movement reports then belong to the cast). */
  rootLocked() {
    const a = this.active;
    return !!(a?.root && a.noCancel);
  }

  /** Take back the root displacement of cast `id` (a predicted cast the host refused). Returns true when moved back. */
  undoRootMotion(id) {
    const ledger = this._rootLedger;
    if (!ledger || ledger.id !== id || !(Math.abs(ledger.x) > 1e-6 || Math.abs(ledger.z) > 1e-6)) return false;
    const p = ledger.caster, x = p?.x - ledger.x, z = p?.z - ledger.z;
    ledger.x = 0; ledger.z = 0;
    if (!p || p.dead || p.disposed || !Number.isFinite(x) || !Number.isFinite(z)) return false;
    const w = this.game.world;
    if (w?.isWalkable && !w.isWalkable(x, z)) return false;
    p.setPosition(x, z);
    return true;
  }

  // ------------------------------------------------------------------------------------------ trans-up
  _queueAppearanceRefresh(player) {
    if (!player?.refreshAppearance) return;
    // Appearance rebuilds resolve meshes, materials and animation clips. Keep
    // that work off the input/cast stack so TransUp and a simultaneous POV
    // switch never stall the click frame. Coalesce stage changes into one swap.
    player._appearanceRefreshQueued = true;
    if (player._appearanceRefreshTimer) return;
    const run = () => {
      player._appearanceRefreshTimer = null;
      if (!player._appearanceRefreshQueued || player.disposed) return;
      player._appearanceRefreshQueued = false;
      Promise.resolve(player.refreshAppearance()).catch(error => console.warn('[skills] appearance refresh', error));
    };
    player._appearanceRefreshTimer = setTimeout(run, 0);
  }

  _transform(ctx, r) {
    const p = ctx.caster;
    const skill = this.data.skill(r.transformSkill) || ctx.skill;
    const rows = skill?.transform || [];
    const row = rows.find(x => num(x.level) === num(r.transformLevel));
    if (!row) return false;
    const look = row?.shapeshift;
    const ms = num(r.durationMs) || 60000;
    p.transUpStage = Math.max(1, num(row?.transType) || 1);
    p.transUpUntil = (this.game.time || 0) + ms / 1000;
    this.game.save.transUp = { skill: skill?.index, level: r.transformLevel, until: (this.game._world?.now?.() ?? Date.now()) + ms, stage: p.transUpStage };
    if (look?.mesh && p.refreshAppearance) {
      p.transformLook = look;
      this._queueAppearanceRefresh(p);
    }
    this.game.events?.emit('transup', { actor: p, stage: p.transUpStage, on: true });
  }

  _updateTransUp() {
    const p = this.game.player;
    if (!p?.transUpStage) return;
    if ((this.game.time || 0) < num(p.transUpUntil)) return;
    p.transUpStage = 0;
    this.game.save.transUp = null;
    if (p.transformLook) { p.transformLook = null; this._queueAppearanceRefresh(p); }
    const skill = this.list.find(s => s.transform);
    const end = skill?.transform?.[0]?.endEffect;
    if (end) this.fx?.play(p, { id: end, scene: 1, timeMs: 1500 }, {});
    this.game.events?.emit('transup', { actor: p, stage: 0, on: false });
  }

  // ------------------------------------------------------------------------------------------ passives
  /**
   * Passive layer (Â§10.2): the options of learned passive / mastery levels while the equipped weapon style is one of
   * the skill's styles, plus weaponstatus.csv statuses of those masteries for the style. Returned as status-like
   * entries (never expire) so progression.sumStatus reads them with the buffs.
   */
  passiveEntries() {
    if (this._passives) return this._passives;
    const out = [];
    const style = this.equippedStyle();
    for (const [k, v] of Object.entries(this.save?.skills || {})) {
      const s = this.skillDef(k);
      if (!s || !this.isPassive(s)) continue;
      const lv = Math.min(typeof v === 'object' ? num(v.level) : num(v), this.maxLevelFor(s));
      if (lv <= 0) continue;
      const styles = (s.styles || []).map(Number);
      if (styles.length && !styles.includes(style) && !styles.includes(0)) continue;
      const L = this.levelData(s, lv);
      const opts = (L?.options || []).filter(o => o.code && isNaN(Number(o.code))).map(o => ({ code: o.code, value: num(o.value) }));
      if (opts.length) out.push({ key: `passive:${s.index}`, passive: true, skillIndex: s.index, name: s.name, options: opts, remaining: Infinity });
      const ws = this.data.weaponStatus?.[s.index]?.[style];
      if (ws) {
        const d = this.data.status(ws);
        if (d) out.push({ key: `wstatus:${s.index}`, passive: true, skillIndex: s.index, name: s.name, options: (d.options || []).map(o => ({ code: o.code, value: num(o.value) })), remaining: Infinity });
      }
    }
    this._passives = out;
    return out;
  }
  passiveValue(code) { return optionSum(this.passiveEntries(), code); }
  /** Runtime-only options: do not use for fields already folded by deriveStats. */
  optionValue(actor, code) {
    const other = actor === this.game.player ? this : actor?.game?.skills;
    return combatOptionValue(actor, code, { statuses: this.statuses?.listOf?.(actor, false) ?? actor?.statuses ?? [], passiveEntries: other?.game?.player === actor && other.data ? other.passiveEntries() : [] });
  }
  optionPercent(actor, code) {
    const other = actor === this.game.player ? this : actor?.game?.skills;
    return combatOptionPercent(actor, code, { statuses: this.statuses?.listOf?.(actor, false) ?? actor?.statuses ?? [], passiveEntries: other?.game?.player === actor && other.data ? other.passiveEntries() : [] });
  }
  refreshPassives() {
    this._passives = null;
    // before the first map the player does not exist yet (install-time migrations); its stats derive on creation
    if (this.game.player) this.game.refreshPlayerStats?.(false);
  }

  // ------------------------------------------------------------------------------------------ compat + misc
  /** Old API: apply status.csv entry to an actor (items / quests / GM use it too). */
  addStatus(actor, skill, statusIndex, durationMs, source = null) {
    return this.statuses.add(actor, statusIndex, durationMs, { skill: skill && typeof skill === 'object' ? skill : null, source });
  }

  /** Client message text (<cate> 60) or the code itself. */
  msg(code) {
    if (typeof code === 'string') return code;
    const t = this.messages?.[code];
    return t != null ? t.replace(/<center>|<\/?font[^>]*>/gi, '').replace(/^\s*\[message\]/i, '') : `(${code})`;
  }
  _msg(code) {
    const text = this.msg(code);
    const now = this.game?.time || 0;
    // The "Not enough mana" message used to repeat on every press; it now shows at most once every 4 s.
    this._msgTimes = this._msgTimes || new Map();
    if (now - (this._msgTimes.get(text) ?? -1e9) < 4) return false;
    this._msgTimes.set(text, now);
    try { this.game?.hud?.log?.(text, 'err'); } catch { /* HUD optional */ }
    return true;
  }

  clear() {
    this.cancel();
    this._dashes = [];
    this.remotes.clear();
  }
}

function primaryEnemy(ctx) {
  const t = ctx.target;
  return t && t !== ctx.caster && !t.dead ? t : null;
}


