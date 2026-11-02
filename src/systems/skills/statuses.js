// Statuses (buffs / debuffs) of every unit: share/skill/status.csv via skills_status.json (docs/formats/skills.md §8).
//
// Storage (compatible with progression.sumStatus, combat.statusValue and the HUD):
//   player   game.save.buffs (persisted with the character; player.statuses points at the same array)
//   others   actor.statuses
// Entry: { key, statusIndex, skillIndex, level, name, description, iconIndex, options:[{code, value}], duration,
//          remaining, tick, stacks, maxStack, group, buff, mapMoveDelete, sourceId }   (plain JSON: no actor refs)
//
// Rules:
//   - non-stacking helpful skill variants with the same native icon/group/style/option-code set share one effect,
//     including single/party versions; otherwise family = skill + icon, else icon + description. Reapplication refreshes.
//     The levels of one skill share their effect family; native maxStack > 0 statuses stack (options x stacks).
//   - options apply while the status lasts (stat modifiers are read by progression / combat / the stat layer)
//   - ticks every second: HP_DECREASE_ADD (value/100 HP), HP_DECREASERATE_MUL (% max HP), MP_DECREASE_ADD
//     (value/100 MP), MP_DECREASERATE_MUL (% max MP); for non-players also HP/MP_RECOVERY_ADD (value/200 per s, as
//     progression does for the player) and SHIELD_RECOVERY_ADD
//     JUDGMENT (lane70c 2026-10-29): the 1 s tick and the /100 and /200 divisors are not stated by any Global file, the
//     Global decompiles (option names are not even present as strings there) or the server-ref data; kept as the most
//     credible reading because removing them would leave every DoT / regen status without any effect.
//   - control flags: ACTION_SLEEP / ACTION_PURGE / ADD_ACTION_* imply no move + no attack; SUFFER_DAMAGE_DELETE_STATUS_RATIO
//     = % chance a hit removes the status (sleep breaks); ACTION_INVISIBLE hides the unit from monster AI
//   - modeleffect 19 start (code4 1) on apply, keep (code4 2) while it lasts, end (code4 3) on removal. Each row is
//     played with its OWN eff_loop flag (GLOBAL DATA modeleffect.csv + GLOBAL DECOMPILE 32-bit FUN_00813050: the row's
//     loop byte is handed to the effect handler with the effect id/scene/time): eff_loop 0 = persistent until the
//     status ends, 1 = one shot for eff_time (the 0/1 meaning is the data reading: 430 of 431 end rows are 1, 356 of
//     400 keep rows are 0, and the 31 start rows with 0 are the authored "_Keep" / guardian-stone auras). lane70c.
//   - mapMoveDelete statuses end on map change; cleanse/dispel remove by status group (statusgroup.csv)
import { SHARE_OPTION, sharePercent, isDeferredSelfBuff } from './damage-share.js';

const DOT_TICK = 1;
const IMPLIES_LOCK = ['ACTION_SLEEP', 'ACTION_PURGE', 'ADD_ACTION_SECOND_SURRENDER', 'ADD_ACTION_MENTAL_BREAKDOWN', 'ADD_ACTION_PANIC'];

const num = v => (Number.isFinite(+v) ? +v : 0);

// Native non-stacking helpful effect identity. Single and party applications
// can use different skill/status indices for the same authored icon/options.
export function nativeStatusFamily(def,skill=null){
 if(skill&&Number(def?.property)===1&&num(def.maxStack)===0&&num(def.iconIndex)>0&&(def.options||[]).length)return `b${def.group}|${def.iconIndex}|${def.style}|${[...new Set(def.options.map(o=>o.code))].sort().join(',')}`;
 return skill?`s${skill.index}|${def?.iconIndex}`:`i${def?.iconIndex}|${def?.description}`;
}
export function nativeStatusEquivalent(a,b){
 if(!a||!b||!nativeStatusFamily(a,{index:0}).startsWith('b')||!nativeStatusFamily(b,{index:0}).startsWith('b')||Number(a.group)!==Number(b.group)||Number(a.iconIndex)!==Number(b.iconIndex)||Number(a.style)!==Number(b.style))return false;
 const x=new Set(a.options.map(o=>o.code)),y=new Set(b.options.map(o=>o.code));
 // Higher native levels can add an option to the same visible effect.
 return [...x].every(c=>y.has(c))||[...y].every(c=>x.has(c));
}

export function optionSum(list, code) {
  if (!list || !list.length) return 0;
  let v = 0;
  for (const s of list) {
    if (!s || (s.remaining != null && s.remaining <= 0)) continue;
    for (const o of s.options || []) if (o.code === code) v += num(o.value);
  }
  return v;
}

/** Movement / attack / skill / item locks of a status list (pure; StatusSystem.flags and the server monster AI use it). */
// LANE1-PERF: one pass over the list instead of ~14 optionSum passes. Per-code sums
// keep optionSum's exact skip rules and summation order (parity-tested).
const FLAG_CODES = new Set(['ACTION_DISALLOW_MOVE', 'ACTION_DISALLOW_ALL', 'ACTION_DISALLOW_ATTACK', 'ACTION_DISALLOW_ITEM',
  'ACTION_DISALLOW_TARGET', 'SKILL_USESKILL', 'ACTION_SLEEP', 'ACTION_FINAL_RESET_STAND', 'ACTION_INVISIBLE', ...IMPLIES_LOCK]);
export function flagsOf(L) {
  const sums = new Map();
  if (L && L.length) {
    for (const s of L) {
      if (!s || (s.remaining != null && s.remaining <= 0)) continue;
      for (const o of s.options || []) if (FLAG_CODES.has(o.code)) sums.set(o.code, (sums.get(o.code) || 0) + num(o.value));
    }
  }
  const v = c => (sums.get(c) || 0) !== 0;
  const lock = IMPLIES_LOCK.some(v);
  return {
    move: v('ACTION_DISALLOW_MOVE') || v('ACTION_DISALLOW_ALL') || lock,
    attack: v('ACTION_DISALLOW_ATTACK') || lock,
    item: v('ACTION_DISALLOW_ITEM') || lock,
    target: v('ACTION_DISALLOW_TARGET'),
    skill: v('SKILL_USESKILL') && !!L?.some(s => s.blocksSkills),
    sleep: v('ACTION_SLEEP'),
    // ACTION_FINAL_RESET_STAND is the "return to the stand pose when this ends" marker carried by 429 lock statuses (stun, sleep,
    // faint, shock, restrain, ...). It is not a knock-down: mapping it to the knockdown clip made every stun flip the character.
    resetStand: v('ACTION_FINAL_RESET_STAND'),
    invisible: v('ACTION_INVISIBLE'),
    lock,
  };
}

export class StatusSystem {
  constructor(game, data, fx) {
    this.game = game;
    this.data = data;
    this.fx = fx;
    this.handles = new WeakMap();        // entry -> { keep: ScenePlay }
    this.tracked = new Set();            // non-player actors with statuses
    this.pending = new Set();           // lazy definitions waiting to apply
  }

  // ------------------------------------------------------------------------------------------ lists
  listOf(actor, create = true) {
    if (!actor) return null;
    const g = this.game;
    if (actor === g.player) {
      if (!Array.isArray(g.save.buffs)) g.save.buffs = [];
      actor.statuses = g.save.buffs;
      return g.save.buffs;
    }
    if (!actor.statuses && create) actor.statuses = [];
    if (actor.statuses) this.tracked.add(actor);
    return actor.statuses || null;
  }

  value(actor, code) { return optionSum(this.listOf(actor, false), code); }
  has(actor, code) { return this.value(actor, code) !== 0; }
  /** Movement / attack / skill / item locks of a unit. */
  flags(actor) {
    return flagsOf(this.listOf(actor, false));
  }

  /** Repair persisted duplicate non-stacking skill effects using native rows. */
  reconcile(actor){
    const list=this.listOf(actor,false);if(!list?.length)return 0;
    const newest=new Map(),duplicates=new Set();
    for(const entry of list){const def=this.data.status(entry.statusIndex);if(!def||entry.skillIndex==null)continue;const family=nativeStatusFamily(def,{index:entry.skillIndex});if(!family.startsWith('b'))continue;
      entry.family=family;entry.key=`${family}:${entry.statusIndex}`;
      const old=[...newest.values()].find(s=>nativeStatusEquivalent(this.data.status(s.statusIndex),def)||s.skillIndex===entry.skillIndex&&Number(this.data.status(s.statusIndex)?.iconIndex)===Number(def.iconIndex));if(!old)newest.set(family,entry);else if(num(entry.at)>=num(old.at)){duplicates.add(old);newest.delete(old.family);newest.set(family,entry);}else duplicates.add(entry);
    }
    return duplicates.size?this.remove(actor,s=>duplicates.has(s),'duplicate'):0;
  }

  // ------------------------------------------------------------------------------------------ add / remove
  /**
   * Apply status `statusIndex` for durationMs. opts: {source (actor), skill, level, name, stacks, noEffects,
   * durationScale}. Returns the entry or null (unknown status / no duration).
   */
  add(actor, statusIndex, durationMs, opts = {}) {
    const g = this.game;
    if (!actor || actor.disposed || actor.dead && !opts.onDead) return null;
    // Divide Pain / Force: the blue self status (cast step 2) belongs to the moment the caster RECEIVES shared damage
    // (skilldesc + O2), so the cast itself does not apply it. damage-share.js applies it with divideReceipt.
    if (opts.skill && !opts.divideReceipt && opts.source && (opts.source === actor || opts.source.id != null && opts.source.id === actor.id)
      && isDeferredSelfBuff(opts.skill, opts.level, statusIndex)) return null;
    const def = this.data.status(statusIndex);
    if (!def) {
      // unknown to the class pack: apply once the full table arrives
      const request = { actor, cancelled: false, mapMove: false };
      this.pending.add(request);
      this.data.statusAsync(statusIndex).then(d => {
        if (d && !request.cancelled && !(request.mapMove && num(d.mapMoveDelete)) && !actor.dead && !actor.disposed) {
          this.add(actor, statusIndex, durationMs, opts);
        }
      }).finally(() => this.pending.delete(request));
      return null;
    }
    const dur = num(durationMs) / 1000;
    if (!(dur > 0)) return null;
    const list = this.listOf(actor);
    const skill = opts.skill || null;
    // one family = the same effect: the level rows of a skill share its icon; two statuses one cast applies (Air
    // spirit's buff + its 1-s effect status, Point target's mark + its stun) have different icons and coexist
    const family = nativeStatusFamily(def,skill);
    const same=s=>s.family===family||(skill&&Number(s.skillIndex)===Number(skill.index)&&Number(this.data.status(s.statusIndex)?.iconIndex)===Number(def.iconIndex))||(family.startsWith('b')&&s.skillIndex!=null&&nativeStatusEquivalent(this.data.status(s.statusIndex),def));
    const i = list.findIndex(s => same(s) && (skill ? true : s.statusIndex === statusIndex || s.iconIndex === def.iconIndex));
    const maxStack = num(def.maxStack);
    let stacks = 1;
    if (i >= 0 && maxStack > 0) stacks = Math.min(maxStack, num(list[i].stacks || 1) + (opts.stacks || 1));
    // JUDGMENT (lane70c): stacked statuses scale every option value by the stack count; no Global file states it.
    const mul = stacks;
    const options = (def.options || []).map(o => ({ code: o.code, value: num(o.value) * mul }));
    for (const c of IMPLIES_LOCK) {
      if (options.some(o => o.code === c && o.value)) {
        if (!options.some(o => o.code === 'ACTION_DISALLOW_MOVE')) options.push({ code: 'ACTION_DISALLOW_MOVE', value: 1, implied: true });
        if (!options.some(o => o.code === 'ACTION_DISALLOW_ATTACK')) options.push({ code: 'ACTION_DISALLOW_ATTACK', value: 1, implied: true });
        break;
      }
    }
    const entry = {
      key: `${family}:${statusIndex}`, family, statusIndex: Number(statusIndex),
      skillIndex: skill?.index ?? null, level: opts.level ?? null,
      name: opts.name || skill?.name || shortName(def.description),
      description: def.description || '', iconIndex: def.iconIndex ?? null,
      options, duration: dur, remaining: dur, tick: 0, stacks, maxStack,
      group: def.group ?? null, buff: Number(def.property) === 1, mapMoveDelete: !!num(def.mapMoveDelete),
      type: def.type ?? 0, sourceId: opts.source?.id ?? null, at: g.time || 0,
    };
    // fields the HUD buff windows (hud-options hudwins.js statusKind / stack text) read
    entry.debuff = !entry.buff;
    entry.stack = stacks;
    // Divide Pain / Force protection: the holder is the protected unit, sourceId the caster; the percent comes from the
    // cast row (the status itself carries SHARE_DAMAGE_PARTY with value 0), so it is recorded with the entry.
    if (options.some(o => o.code === SHARE_OPTION)) entry.sharePct = sharePercent(skill, opts.level, statusIndex);
    if (opts.item || opts.itemIndex != null) { entry.fromItem = true; entry.itemIndex = opts.itemIndex ?? null; }
    if (opts.rune) entry.rune = true;
    if (opts.blocksSkills) entry.blocksSkills = true;
    if (actor !== g.player && opts.source) Object.defineProperty(entry, 'source', { value: opts.source, enumerable: false, writable: true, configurable: true });
    const old = i >= 0 ? list[i] : null;
    if (old) { this._stopEffects(old, false); list[i] = entry; } else list.push(entry);
    if(family.startsWith('b'))this.remove(actor,s=>s!==entry&&same(s),'duplicate');
    // DAMAGE_MP_ADD on a debuff ("Shock / Mana Decrease", Mana shock): the application takes `value` MP off the target once.
    // JUDGMENT (lane70c; was ENGINE-CHOSEN): reading of the status text, no Global file states the formula (the single
    // buff row that carries the code is not an MP drain and is skipped).
    const mpDrain = entry.buff ? 0 : options.filter(o => o.code === 'DAMAGE_MP_ADD').reduce((sum, o) => sum + num(o.value), 0);
    if (mpDrain > 0 && Number.isFinite(Number(actor.mp))) actor.mp = Math.max(0, num(actor.mp) - mpDrain);
    if (!opts.noEffects) this._startEffects(actor, entry, def, !old);
    this._changed(actor, entry, true);
    return entry;
  }

  /** Remove entries matching pred (entry => bool) or an entry. Returns the number removed. */
  remove(actor, which, reason = 'removed') {
    const list = this.listOf(actor, false);
    if (!list || !list.length) return 0;
    let n = 0;
    for (let i = list.length - 1; i >= 0; i--) {
      const s = list[i];
      const hit = typeof which === 'function' ? which(s) : s === which;
      if (!hit) continue;
      list.splice(i, 1);
      n++;
      this._stopEffects(s, reason !== 'silent', actor);
      this._changed(actor, s, false, reason);
    }
    return n;
  }

  /** Remove up to `count` statuses of status group `group` (cleanse); debuffsOnly for friendly cleanses. */
  removeGroup(actor, groups, count = 1, { buffs = null } = {}) {
    const gs = new Set((Array.isArray(groups) ? groups : [groups]).map(Number));
    const list = this.listOf(actor, false);
    if (!list) return 0;
    const cands = list.filter(s => gs.has(Number(s.group)) && (buffs == null || s.buff === buffs)).sort((a, b) => b.at - a.at);
    const pick = new Set(cands.slice(0, Math.max(1, count)));
    return this.remove(actor, s => pick.has(s), 'cleansed');
  }

  clear(actor, { mapMove = false } = {}) {
    for (const request of this.pending) if (request.actor === actor) {
      if (mapMove) request.mapMove = true;
      else { request.cancelled = true; this.pending.delete(request); }
    }
    return this.remove(actor, s => !mapMove || s.mapMoveDelete, 'silent');
  }

  // ------------------------------------------------------------------------------------------ frame
  update(dt) {
    const g = this.game;
    const p = g.player;
    if (p) this._tickActor(p, dt);
    for (const a of [...this.tracked]) {
      if (a === p) continue;
      if (a.disposed || !a.statuses || !a.statuses.length) {
        if (a.disposed && a.statuses) for (const s of a.statuses) this._stopEffects(s, false);
        this.tracked.delete(a);
        continue;
      }
      this._tickActor(a, dt);
    }
  }

  _tickActor(a, dt) {
    const list = this.listOf(a, false);
    if (!list || !list.length) return;
    const g = this.game;
    let changed = false;
    // FXLIFE fix: walk a SNAPSHOT. A DoT tick can kill the owner and the death hook then removes several entries at once,
    // so a live `list[i]` read by a stale index returned undefined (TypeError on `s.keepOnDeath`) or a different entry.
    const snap = list.slice();
    for (let k = snap.length - 1; k >= 0; k--) {
      const s = snap[k];
      if (!list.includes(s)) continue;                                   // removed meanwhile (death hook / another status' tick)
      if (a.dead && !s.keepOnDeath) { list.splice(list.indexOf(s), 1); this._stopEffects(s, false, a); changed = true; continue; }
      s.remaining = num(s.remaining) - dt;
      s.tick = num(s.tick) + dt;
      while (s.tick >= DOT_TICK && !a.dead) {
        s.tick -= DOT_TICK;
        this._tick(a, s);
      }
      // FXLIFE: a DoT tick can kill the owner, and the death hook then removes every status of it (stopping their visuals)
      // while this loop still holds `s`: without this check the keep loop below was restarted for an entry that no longer
      // exists (an aura that stayed on the dead / respawned unit forever), and `list.splice(i, 1)` hit the wrong index.
      if (!list.includes(s)) continue;
      if (s.remaining <= 0) {
        list.splice(list.indexOf(s), 1);
        this._stopEffects(s, true, a);
        this._changed(a, s, false, 'expired');
        changed = true;
      } else if (!this.handles.get(s) && s.keepWanted !== false) {
        // restored from a save / out of view: (re)start the keep loop
        const def = this.data.status(s.statusIndex);
        if (def) this._startEffects(a, s, def, false);
      }
    }
    if (changed && a === g.player) g.refreshPlayerStats?.(false);
  }

  _tick(a, s) {
    const g = this.game;
    const isPlayer = a === g.player;
    let dmg = 0, mp = 0;
    for (const o of s.options) {
      const v = num(o.value);
      switch (o.code) {
        case 'HP_DECREASE_ADD': dmg += v / 100; break;
        case 'HP_DECREASERATE_MUL': dmg += num(a.maxHp) * v / 100; break;
        case 'MP_DECREASE_ADD': mp += v / 100; break;
        case 'MP_DECREASERATE_MUL': mp += num(a.maxMp) * v / 100; break;
        case 'HP_RECOVERY_ADD': if (!isPlayer && !a.dead) a.hp = Math.min(num(a.maxHp), num(a.hp) + v / 200); break;
        case 'MONSTER_HEAL_HP_MAX_MUL': if (!isPlayer && !a.dead) a.hp = Math.min(num(a.maxHp), num(a.hp) + num(a.maxHp) * v / 100); break;
        default: break;
      }
    }
    if (mp > 0) a.mp = Math.max(0, num(a.mp) - mp);
    if (dmg > 0 && !a.dead) {
      const src = s.source || (s.sourceId != null ? this._actorById(s.sourceId) : null) || null;
      this.game.skills?.dotDamage?.(src, a, Math.max(1, Math.round(dmg)), s);
    }
  }

  _actorById(id) {
    for (const x of this.game.actors?.() || []) if (x.id === id) return x;
    for (const x of this.game.skills?.summons?.list || []) if (x.id === id) return x;
    return null;
  }

  /** Native hiding (763 / 1563) ends when its owner starts an accepted hostile action. */
  onAttack(actor) {
    return this.remove(actor, s => optionSum([s], 'ACTION_INVISIBLE') > 0, 'attack');
  }

  /** A hit landed on `a`: sleep-type statuses may break (SUFFER_DAMAGE_DELETE_STATUS_RATIO %). */
  onDamaged(a, amount) {
    if (!(amount > 0)) return;
    const list = this.listOf(a, false);
    if (!list || !list.length) return;
    this.remove(a, s => {
      const r = optionSum([s], 'SUFFER_DAMAGE_DELETE_STATUS_RATIO');
      return r > 0 && Math.random() * 100 < r;
    }, 'broken');
  }

  /** Map change: end mapMoveDelete statuses, restart visuals later. */
  onMapChange() {
    const p = this.game.player;
    for (const request of this.pending) {
      if (request.actor === p) request.mapMove = true;
      else { request.cancelled = true; this.pending.delete(request); }
    }
    if (p) {
      this.remove(p, s => s.mapMoveDelete, 'map');
      for (const s of this.listOf(p) || []) this._stopEffects(s, false);
    }
    this.tracked.clear();
  }

  // ------------------------------------------------------------------------------------------ visuals / events
  _startEffects(actor, entry, def, fresh) {
    const fx = this.fx;
    const e = def.effects || this.data.modelEffects?.status?.[def.iconIndex] || null;
    if (!fx || !e || actor.disposed) { if (!e) entry.keepWanted = false; return; }
    // lane70c: every row plays with its own Global eff_loop (0 = persistent, 1 = one shot), see the header. A
    // persistent start row is part of the lasting look, so it is restarted with the keep row (restore / back in view);
    // a one-shot start only plays on a fresh application.
    const persists = ref => !!ref && Number(ref.loop) === 0;
    const h = { actor };
    if (e.start && (fresh || persists(e.start))) { const s = fx.play(actor, e.start, { loop: persists(e.start) }); if (s && persists(e.start)) h.start = s; }
    if (e.keep) { const k = fx.play(actor, e.keep, { loop: persists(e.keep) }); if (k) h.keep = k; }
    if (!persists(e.start) && !persists(e.keep)) entry.keepWanted = false;
    if (h.start || h.keep) this.handles.set(entry, h);
    else entry.keepWanted = false;
  }

  _stopEffects(entry, playEnd, actor) {
    const h = this.handles.get(entry);
    if (h?.keep) h.keep.stop(true);
    if (h?.start) h.start.stop(true);
    this.handles.delete(entry);
    if (playEnd && this.fx && actor && !actor.disposed) {
      const def = this.data.status(entry.statusIndex);
      const e = def?.effects || this.data.modelEffects?.status?.[entry.iconIndex];
      // JUDGMENT (lane70c): the end row always plays once - nothing could stop a persistent end row after the status is
      // gone (the only end row with eff_loop 0 is 7419, the auto-hunt finish).
      if (e?.end) this.fx.play(actor, e.end, { loop: false });
    }
  }

  _changed(actor, entry, on, reason) {
    const g = this.game;
    if (actor === g.player) {
      if (Object.prototype.hasOwnProperty.call(entry, 'source')) delete entry.source;
      g.refreshPlayerStats?.(false);
    }
    actor.invisible = optionSum(this.listOf(actor, false), 'ACTION_INVISIBLE') > 0;
    g.events?.emit('status', { actor, status: entry, on, reason });
  }
}

/** "Enhance / Defense + / All ..." -> "Enhance" style short names are poor: keep the first two parts. */
export function shortName(desc) {
  const parts = String(desc || 'Status').split('/').map(s => s.trim()).filter(Boolean);
  return parts.slice(0, 2).join(' / ') || 'Status';
}
