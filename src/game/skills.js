// Player skills, driven by classes.json classes[].skills (from share/skill/*.csv):
//   reqLevel, mpCost, hpCost, cooldownMs, castMs, range, target flags, type, ready (pre-cast anim),
//   steps[] { durationMs, anim {anim, timing}, result {kind, addDamage, radius, remoteIndex, statusIndex, ...} },
//   levels[] { reqLevel, spCost, mp, cooldownMs, addDamage[per result], statusIndex[], durationMs[], steps? }
//
// use(slot | skillIndex):
//   validates level / MP / cooldown / target / range; out of range -> the controller walks into range first,
//   then the skill fires (like the original). The step clips play back to back over their TimeTick durations;
//   each result lands at its clip `timing` (0.5 when the table has none; 3 ms marker steps fire instantly):
//     damage       weapon damage (skill type: melee/range/magic) + addDamage, single target or radius AoE
//     projectile   the same, delivered after the remote.csv flight time (visual bolt), radius AoE on impact
//     heal         amount + perSpr * SPR on the caster (ally skills target yourself in single player)
//     status       share/skill/status.csv options as a buff on yourself (target 16/2) or a debuff on the enemy (4)
//     area_status  statuses on every enemy (or yourself for party buffs) within the radius
//     summon       not available yet (servants are a later milestone) — refused before any cost is paid
// Skill level: save.skills[index] if learned, else level 1 once the character reaches reqLevel (level 1 costs 0 SP
// in every table). learn(index) spends skill points on the next level.
// Target flags (skill CSV `Target`): 4 enemy, 16 self, 2 ally/party, 1 area (may be cast without a target).
import * as THREE from 'three';
import { resolveAttack, applyDamage, playOnce, heal, isAlive, dist2, rand } from './combat.js';
import { formulaOf } from './progression.js';

const T_AREA = 1, T_ALLY = 2, T_ENEMY = 4, T_SELF = 16;
const SKILL_KIND = { melee: 'melee', range: 'range', magic: 'magic', heal: 'magic', status: 'magic', area_status: 'magic' };
const INSTANT_STEP = 0.05;    // steps shorter than this (3 ms marker rows) do not play a clip
const DEFAULT_PROJECTILE_SPEED = 25;
const DOT_TICK = 1;

export class SkillSystem {
  constructor(game) {
    this.game = game;
    this.cooldowns = new Map();   // skillIndex -> { start, end } in game time
    this.active = null;           // skill being performed
    this.queued = null;           // one skill pressed while another was running
    this.projectiles = [];
    this._msgAt = -9;
    this._seq = 0;
  }

  // ---------------------------------------------------------------- lookups
  get hotbar() { return this.game?.save?.hotbar || []; }
  get busy() { return !!this.active; }
  get list() { return this.game?.classDef?.skills || []; }

  skillDef(index) {
    const i = Number(index);
    return this.list.find(s => Number(s.index) === i) || null;
  }

  /** Current usable level of a skill (0 = not available yet). */
  skillLevel(index) {
    const s = this.skillDef(index);
    if (!s) return 0;
    const lv = Number(this.game?.save?.level) || 1;
    let learned = Number(this.game?.save?.skills?.[s.index]) || 0;
    if (!learned && lv >= (s.reqLevel || 1)) learned = 1;
    // never above what the character level allows
    while (learned > 1 && s.levels?.[learned - 1] && lv < (s.levels[learned - 1].reqLevel || 1)) learned--;
    if (learned === 1 && lv < (s.levels?.[0]?.reqLevel ?? s.reqLevel ?? 1)) return 0;
    return learned;
  }

  levelData(skill, level) {
    return skill?.levels?.[Math.max(0, level - 1)] || null;
  }

  /** Spend skill points on the next level of a skill. Returns the new level or 0. */
  learn(index) {
    const g = this.game, s = this.skillDef(index), save = g?.save;
    if (!s || !save) return 0;
    const cur = this.skillLevel(index);
    const next = this.levelData(s, cur + 1);
    if (!next) { this._msg(`${s.name} is already at its highest level.`); return 0; }
    if ((save.level || 1) < (next.reqLevel || 1)) { this._msg(`${s.name} Lv ${cur + 1} requires character level ${next.reqLevel}.`); return 0; }
    const cost = next.spCost || 0;
    if ((save.skillPoints || 0) < cost) { this._msg('Not enough skill points.'); return 0; }
    save.skillPoints = (save.skillPoints || 0) - cost;
    save.skills = save.skills || {};
    save.skills[s.index] = cur + 1;
    g.events?.emit('skilllearn', { skill: s, level: cur + 1 });
    return cur + 1;
  }

  cooldownRemaining(index) {
    const c = this.cooldowns.get(Number(index));
    return c ? Math.max(0, c.end - (this.game?.time || 0)) : 0;
  }
  /** 1 right after use, falling to 0 when ready. */
  cooldownFraction(index) {
    const c = this.cooldowns.get(Number(index));
    if (!c) return 0;
    const total = c.end - c.start;
    if (!(total > 0)) return 0;
    return Math.max(0, Math.min(1, (c.end - (this.game?.time || 0)) / total));
  }
  resetCooldowns() { this.cooldowns.clear(); }

  // ---------------------------------------------------------------- use
  /**
   * use(slot): hotbar slot 0-9 (keys 1..0). use({skillIndex}) or use(n >= 10) / useSkill(n): a skill by index.
   * Returns true when the skill started (or the character is walking into range to use it).
   */
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

  /** Hotbar slot 0-9 (alias of use(slot), used by the HUD). */
  useSlot(slot) { return this.use(Number(slot)); }

  useSkill(index) {
    const g = this.game, p = g?.player;
    if (!p || p.dead) return false;
    const skill = this.skillDef(index);
    if (!skill) return false;
    const level = this.skillLevel(skill.index);
    if (level <= 0) { this._msg(`${skill.name} requires level ${skill.reqLevel}.`); return false; }
    if (this.active) {
      if (this.active.skill !== skill) this.queued = skill.index;
      return false;
    }
    const L = this.levelData(skill, level) || {};
    const steps = L.steps || skill.steps || [];
    if (steps.some(s => s.result?.kind === 'summon')) { this._msg('Summoning is not available yet.'); return false; }

    const mpCost = Number(L.mp ?? skill.mpCost) || 0;
    const hpCost = Number(L.hp ?? skill.hpCost) || 0;
    const F = formulaOf(g.data);
    const cd = (Number(L.cooldownMs ?? skill.cooldownMs) || 0) / 1000 * (F.fSkillCoolTimeRate ?? 1);
    const left = this.cooldownRemaining(skill.index);
    if (left > 0) { this._msg(`${skill.name} is not ready yet (${left.toFixed(1)}s).`); return false; }
    if ((p.mp || 0) < mpCost) { this._msg('Not enough MP.'); return false; }
    if (hpCost > 0 && (p.hp || 0) <= hpCost) { this._msg('Not enough HP.'); return false; }

    // ---- target
    const flags = skill.target || [];
    const wantsEnemy = flags.includes(T_ENEMY);
    let target = null, center = null;
    if (wantsEnemy) {
      const t = p.target;
      if (isAlive(t) && t.kind === 'monster') target = t;
      else if (flags.includes(T_AREA)) center = this._frontPoint(p, Math.min(skill.range || 3, 2.5));
      else { this._msg('Select a target first.'); return false; }
    } else {
      target = p; // self / ally / party skills land on yourself in single player
    }

    // ---- range: walk into range first, like the original
    if (target && target !== p) {
      const range = Number(skill.range) || 3;
      const reach = range + (target.radius || 0.5);
      if (dist2(p, target) > reach) {
        const ctl = g.controller;
        if (ctl?.approach) {
          ctl.approach(target, range, () => this.useSkill(skill.index));
          return true;
        }
        this._msg('Target is too far away.');
        return false;
      }
    }

    // ---- start
    p.mp = Math.max(0, (p.mp || 0) - mpCost);
    if (hpCost > 0) p.hp = Math.max(1, p.hp - hpCost);
    const now = g.time || 0;
    this.cooldowns.set(Number(skill.index), { start: now, end: now + cd });
    if (target && target !== p) p.faceTowards?.(target.x, target.z);
    else if (center) p.faceTowards?.(center.x, center.z);
    g.controller?.onSkillStart?.(skill, target);

    const phases = [];
    if (skill.ready?.anim?.anim && skill.ready.durationMs > 0) phases.push({ ready: true, durationMs: skill.ready.durationMs, anim: skill.ready.anim });
    let r = 0;
    for (const st of steps) phases.push({ st, resultIdx: st.result ? r++ : -1 });
    this.active = { skill, level, L, phases, i: -1, cur: null, target, center, id: ++this._seq };
    g.events?.emit('skill', { actor: p, skill, level, target });
    this._nextPhase(0);
    return true;
  }

  cancel() {
    this.active = null;
    this.queued = null;
  }

  _frontPoint(p, d) {
    const yaw = p.yaw || 0;
    return { x: p.x - Math.sin(yaw) * d, z: p.z - Math.cos(yaw) * d };
  }

  _nextPhase(carry) {
    const a = this.active;
    const g = this.game, p = g.player;
    a.i++;
    if (a.i >= a.phases.length) { this._finish(); return; }
    const ph = a.phases[a.i];
    const now = g.time || 0;
    if (ph.ready) {
      const dur = ph.durationMs / 1000;
      a.cur = { t: carry, dur, hitAt: null, done: true, ph };
      playOnce(p, 'skill', { anim: ph.anim.anim, timeLength: dur, variant: ph.anim.index }, now, dur);
      return;
    }
    const st = ph.st;
    const dur = Math.max(0, (Number(st.durationMs) || 0) / 1000);
    const timing = st.anim?.timing > 0 && st.anim.timing <= 1 ? st.anim.timing : 0.5;
    a.cur = { t: carry, dur, hitAt: st.result ? timing * dur : null, done: !st.result, ph };
    if (dur >= INSTANT_STEP && st.anim?.anim) {
      playOnce(p, 'skill', { anim: st.anim.anim, timeLength: dur, variant: st.actionIndex }, now, dur);
    }
  }

  _finish() {
    const a = this.active;
    this.active = null;
    const g = this.game;
    try { g.controller?.onSkillEnd?.(a.skill, a.target); } catch (err) { console.warn(err); }
    if (this.queued != null) {
      const q = this.queued;
      this.queued = null;
      this.useSkill(q);
    }
  }

  // ---------------------------------------------------------------- update
  update(dt) {
    const g = this.game;
    const p = g?.player;
    if (p && g.save) {
      if (!Array.isArray(g.save.buffs)) g.save.buffs = [];
      p.statuses = g.save.buffs;
    }
    this._updateStatuses(dt);
    this._updateProjectiles(dt);

    const a = this.active;
    if (!a) return;
    if (!p || p.dead) { this.cancel(); return; }
    let budget = dt;
    let guard = 0;
    while (this.active === a && a.cur && guard++ < 32) {
      const c = a.cur;
      const need = c.dur - c.t;
      const step = Math.min(budget, Math.max(0, need));
      c.t += step;
      budget -= step;
      if (!c.done && c.hitAt != null && c.t >= c.hitAt - 1e-9) {
        c.done = true;
        try { this._applyResult(a, c.ph.st, c.ph.resultIdx); } catch (err) { console.warn('skill result failed', a.skill.name, err); }
      }
      if (c.t >= c.dur - 1e-9) this._nextPhase(0);
      else break;
      if (budget <= 0 && this.active === a && a.cur && a.cur.dur >= INSTANT_STEP) break;
    }
  }

  // ---------------------------------------------------------------- results
  _center(a) {
    const t = a.target;
    if (t && t !== this.game.player && !t.disposed) return { x: t.x, z: t.z };
    if (a.center) return a.center;
    const p = this.game.player;
    return this._frontPoint(p, 1.5);
  }

  _enemiesAround(c, radius) {
    const out = [];
    for (const m of this.game?.spawner?.monsters || []) {
      if (!isAlive(m)) continue;
      if (Math.hypot(m.x - c.x, m.z - c.z) <= radius + (m.radius || 0.5) * 0.5) out.push(m);
    }
    return out;
  }

  _damageTargets(a, radius) {
    const t = a.target && a.target !== this.game.player ? a.target : null;
    if (radius > 0) {
      const list = this._enemiesAround(this._center(a), radius);
      if (t && isAlive(t) && !list.includes(t)) list.unshift(t);
      return list;
    }
    return t && isAlive(t) ? [t] : [];
  }

  _hit(a, target, addDamage) {
    const g = this.game, p = g.player;
    if (!isAlive(target)) return;
    const res = resolveAttack(p, target, { skill: a.skill, kind: SKILL_KIND[a.skill.type], addDamage, data: g.data });
    res.skill = a.skill;
    applyDamage(g, p, target, res);
  }

  _applyResult(a, st, rIdx) {
    const r = st?.result;
    if (!r) return;
    const g = this.game, p = g.player;
    const L = a.L || {};
    const pick = (arr, fallback) => (Array.isArray(arr) && arr[rIdx] != null ? arr[rIdx] : fallback);
    const add = Number(pick(L.addDamage, r.addDamage)) || 0;
    switch (r.kind) {
      case 'damage':
        for (const t of this._damageTargets(a, Number(r.radius) || 0)) this._hit(a, t, add);
        break;
      case 'projectile':
        this._launch(a, r, add, pick(L.remoteIndex, r.remoteIndex));
        break;
      case 'heal': {
        const spr = p.stats?.spr ?? g.save?.stats?.spr ?? 0;
        const amount = (Number(pick(L.addDamage, r.amount)) || 0) + (Number(r.perSpr) || 0) * spr;
        heal(g, p, p, amount);
        break;
      }
      case 'status':
      case 'area_status': {
        const statusIndex = pick(L.statusIndex, r.statusIndex);
        const durationMs = Number(pick(L.durationMs, r.durationMs)) || 0;
        const chance = r.chance ?? 100;
        let targets;
        if (r.kind === 'area_status') {
          targets = r.target === 'enemies' ? this._damageTargets(a, Number(r.radius) || 2) : [p];
        } else {
          targets = (a.skill.target || []).includes(T_ENEMY) ? (a.target && a.target !== p ? [a.target] : []) : [p];
        }
        for (const t of targets) {
          if (!isAlive(t)) continue;
          if (t !== p && rand() * 100 >= chance) continue;
          this.addStatus(t, a.skill, statusIndex, durationMs, p);
          if (t !== p && t.brain?.onDamaged) t.brain.onDamaged(p, 0); // debuffs draw aggro
        }
        break;
      }
      default:
        if (add > 0) for (const t of this._damageTargets(a, Number(r.radius) || 0)) this._hit(a, t, add);
    }
  }

  // ---------------------------------------------------------------- projectiles
  _launch(a, r, add, remoteIndex) {
    const g = this.game, p = g.player;
    const remote = g.data?.classesFile?.remotes?.[remoteIndex] || null;
    const speed = Number(remote?.moveSpeed) > 0 ? Number(remote.moveSpeed) : DEFAULT_PROJECTILE_SPEED;
    const target = a.target && a.target !== p ? a.target : null;
    const to = target ? { x: target.x, z: target.z } : this._center(a);
    const from = { x: p.x, z: p.z, y: (p.y || 0) + (p.height || 1.8) * 0.6 };
    const d = Math.hypot(to.x - from.x, to.z - from.z);
    const pr = {
      a, r, add, target, from, to, t: 0, flight: Math.max(0.05, d / speed), radius: Number(r.radius) || 0, object: null,
    };
    pr.object = this._projectileVisual(from);
    this.projectiles.push(pr);
  }

  _projectileVisual(from) {
    const root = this.game?.worldRoot;
    if (!root) return null;
    const grp = new THREE.Group();
    const core = new THREE.Mesh(new THREE.SphereGeometry(0.14, 10, 8), new THREE.MeshBasicMaterial({ color: 0xbfe6ff }));
    grp.add(core);
    const glow = new THREE.Mesh(new THREE.SphereGeometry(0.32, 10, 8),
      new THREE.MeshBasicMaterial({ color: 0x5fb4ff, transparent: true, opacity: 0.35, blending: THREE.AdditiveBlending, depthWrite: false }));
    grp.add(glow);
    grp.position.set(from.x, from.y, from.z);
    root.add(grp);
    return grp;
  }

  _removeProjectile(pr) {
    const o = pr.object;
    if (o) {
      o.parent?.remove(o);
      o.traverse(n => { n.geometry?.dispose(); n.material?.dispose(); });
      pr.object = null;
    }
  }

  _updateProjectiles(dt) {
    if (!this.projectiles.length) return;
    const keep = [];
    for (const pr of this.projectiles) {
      pr.t += dt;
      const target = pr.target;
      if (target && !target.disposed) { pr.to.x = target.x; pr.to.z = target.z; } // homing, like the original bolts
      const k = Math.min(1, pr.t / pr.flight);
      if (pr.object) {
        const ty = target ? (target.y || 0) + (target.height || 1.5) * 0.55 : pr.from.y;
        pr.object.position.set(pr.from.x + (pr.to.x - pr.from.x) * k, pr.from.y + (ty - pr.from.y) * k, pr.from.z + (pr.to.z - pr.from.z) * k);
      }
      if (k < 1) { keep.push(pr); continue; }
      this._removeProjectile(pr);
      const a = pr.a;
      if (pr.radius > 0) {
        const list = this._enemiesAround(pr.to, pr.radius);
        if (target && isAlive(target) && !list.includes(target)) list.unshift(target);
        for (const t of list) this._hit(a, t, pr.add);
      } else if (target && isAlive(target)) {
        this._hit(a, target, pr.add);
      }
    }
    this.projectiles = keep;
  }

  // ---------------------------------------------------------------- statuses
  /** Apply status.csv entry `statusIndex` to an actor for durationMs (refreshes the same skill's status). */
  addStatus(actor, skill, statusIndex, durationMs, source = null) {
    const g = this.game;
    const def = g?.data?.classesFile?.statuses?.[statusIndex];
    if (!def || !(durationMs > 0)) return null;
    const p = g.player;
    const isPlayer = actor === p;
    let list;
    if (isPlayer) {
      if (!Array.isArray(g.save.buffs)) g.save.buffs = [];
      list = g.save.buffs;
      p.statuses = list;
    } else {
      list = actor.statuses || (actor.statuses = []);
    }
    const key = `${skill?.index ?? 'x'}:${statusIndex}`;
    const i = list.findIndex(s => s.key === key || (s.skillIndex === skill?.index && s.statusIndex === statusIndex));
    const entry = {
      key, skillIndex: skill?.index ?? null, statusIndex, name: skill?.name || def.description || 'Status',
      description: def.description || '', iconIndex: def.iconIndex ?? skill?.iconIndex ?? null,
      options: (def.options || []).map(o => ({ code: o.code, value: o.value })),
      duration: durationMs / 1000, remaining: durationMs / 1000, tick: 0,
    };
    if (i >= 0) list[i] = entry; else list.push(entry);
    if (source && !isPlayer) entry.source = source;
    if (isPlayer) g.refreshPlayerStats?.(false);
    g.events?.emit('status', { actor, status: entry, on: true });
    return entry;
  }

  _updateStatuses(dt) {
    const g = this.game;
    const buffs = g?.save?.buffs;
    if (Array.isArray(buffs) && buffs.length) {
      let changed = false;
      for (let i = buffs.length - 1; i >= 0; i--) {
        const b = buffs[i];
        b.remaining = (Number(b.remaining) || 0) - dt;
        if (b.remaining <= 0) {
          buffs.splice(i, 1);
          changed = true;
          g.events?.emit('status', { actor: g.player, status: b, on: false });
        }
      }
      if (changed && g.player) g.refreshPlayerStats?.(false);
    }
    for (const m of g?.spawner?.monsters || []) {
      const list = m.statuses;
      if (!list || !list.length) continue;
      for (let i = list.length - 1; i >= 0; i--) {
        const s = list[i];
        s.remaining -= dt;
        // damage over time (HP_DECREASE_ADD, e.g. Heartache bleeding: value/100 HP per second)
        const dot = s.options.reduce((v, o) => (o.code === 'HP_DECREASE_ADD' ? v + (Number(o.value) || 0) : v), 0);
        if (dot > 0 && !m.dead) {
          s.tick += dt;
          while (s.tick >= DOT_TICK && !m.dead) {
            s.tick -= DOT_TICK;
            applyDamage(g, s.source || g.player, m, { amount: Math.max(1, Math.round(dot / 100)), miss: false, dot: true, kind: 'magic' });
          }
        }
        if (s.remaining <= 0 || m.dead) {
          list.splice(i, 1);
          g.events?.emit('status', { actor: m, status: s, on: false });
        }
      }
    }
  }

  _msg(text) {
    const now = this.game?.time || 0;
    // The "Not enough MP" message used to repeat on every press; it now shows at most once every 4 s.
    this._msgTimes = this._msgTimes || new Map();
    if (now - (this._msgTimes.get(text) ?? -1e9) < 4) return;
    this._msgTimes.set(text, now);
    this._msgAt = now;
    this._lastMsg = text;
    try { this.game?.hud?.log?.(text, 'err'); } catch { /* HUD optional */ }
  }

  clear() {
    for (const pr of this.projectiles) this._removeProjectile(pr);
    this.projectiles = [];
    this.active = null;
    this.queued = null;
  }
}
