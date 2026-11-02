// Using items (right click in the bag, the quick slot, the hotbar): items.md 6.7 "Consumables and use effects".
//   potions (hp / mp / shield, flat or % of max; the re-use delay is the item's Appraisal ms, shared per recovery kind)
//   buffs (itemStatus -> skills_status.json status options, lifeTimeMs), premium services (premiere), skill books,
//   return / teleport scrolls (share/arrange/location.csv; 0 = the town return point), boxes and packages
//   (game.boxes when the boxes system is installed, else the itempackage contents), inventory / stash expansion,
//   stat regenerators and the skill reset, stamina, debuff removal, wing class exchange, etc.
import { fetchJSON, fetchCSV } from '../../engine/assets.js';
import {recoveryGroup} from '../../ui/cooldown.js';
import {recoverStamina,staminaRecoveryCap} from '../hud-options/stamina-rules.js';
import {planMeisterChange} from '../../game/meister-change.js';

const POTION_GROUP = (def) => {
  const u = def.use || {};
  if (u.hp || u.hpPct) return u.mp || u.mpPct ? 'hpmp' : 'hp';
  if (u.mp || u.mpPct) return 'mp';
  if (u.shield || u.shieldPct) return 'shield';
  if (u.stamina) return 'stamina';
  return null;
};
export const STAT_RESET = { 6: 'str', 7: 'con', 8: 'dex', 9: 'spr' };   // Strength / Vitality / Agility / Spirit Regenerator
/** A weapon (def.slot 'weapon') worn in the active preset, either weapon tab: the regenerators need them all off
 *  (Global item text 87..90 "Only can use it after unequipping all weapons"). */
export function wearsWeapon(sys) {
  const e = sys.equip; if (!e?.get) return false;
  return [4, 5, 104, 105].some(slot => sys.db.def(e.get(slot)?.itemIndex)?.slot === 'weapon');
}

export class ItemUse {
  constructor(sys) {
    this.sys = sys;
    this.cooldowns = new Map();   // group -> game time when usable again
    this._statuses = null;
    this._locations = null;
  }
  get game() { return this.sys.game; }
  statuses() {
    if (!this._statuses) this._statuses = fetchJSON('/gamedata/skills_status.json').then(j => {
      if (!j?.statuses || typeof j.statuses !== 'object' || Array.isArray(j.statuses)) throw Error('Item status definitions unavailable');
      return j.statuses;
    }).catch(() => {
      // fetchJSON owns transport backoff. Do not turn a failed request into a
      // permanent empty catalog for this inventory's ItemUse instance.
      this._statuses = null;
      return null;
    });
    return this._statuses;
  }
  locations() {
    return this._locations ||= fetchCSV('share/arrange/location.csv').then(rows => {
      const m = new Map();
      for (const vals of rows.slice(1)) {
        const idx = Number(vals[0]);
        if (!Number.isFinite(idx)) continue;
        m.set(idx, { index: idx, name: vals[1], map: Number(vals[2]), x: Number(vals[3]) + 0.5, z: Number(vals[4]) + 0.5, dirDeg: Number(vals[5]) * 360 / 256 });
      }
      return m;
    }).catch(() => new Map());
  }

  /** Seconds until an item's recovery group can be used again. */
  cooldownLeft(itemIndex) {
    const def = this.sys.db.def(itemIndex);
    const grp = def && recoveryGroup(def);
    if (!grp) return 0;
    return Math.max(0, (this.cooldowns.get(grp) || 0) - (this.game.time || 0));
  }
  cooldownFraction(itemIndex) {
    const def = this.sys.db.def(itemIndex);
    const grp = def && recoveryGroup(def);
    if (!grp) return 0;
    const total = (Number(def.appraisal) || 0) / 1000;
    return total > 0 ? Math.min(1, this.cooldownLeft(itemIndex) / total) : 0;
  }

  /** Is the item usable by right click at all (else right click equips / does nothing)? */
  usable(def) {
    if (!def) return false;
    if (def.use) return true;
    const t = Number(def.type), c = Number(def.code);
    if (t === 0 && [6, 7, 8, 9, 10, 15, 16, 20, 23, 26, 27, 29, 30, 38, 39, 41, 63, 68, 80, 81, 210, 211].includes(c)) return true;
    if (t === 3) return true;
    if (this.game.boxes?.isBox?.(def.index)) return true;
    return false;
  }

  /** Use one of an instance. Returns true when it was consumed / did something. */
  async use(inst) {
    const g = this.game, sys = this.sys, db = sys.db, p = g.player;
    const def = db.def(inst?.itemIndex);
    if (!def || !p) return false;
    if (p.dead) { sys.msg(40, 54); return false; }
    const lv = Number(g.save.level) || 1;
    if ((def.reqLv && lv < def.reqLv) || (def.maxLv > 0 && lv > def.maxLv) || !((Number(def.classMask) >>> (Number(g.save.classIndex) || 0)) & 1)) { sys.msg(40, 56); return false; }
    if (inst.expiresAt && inst.expiresAt < Date.now()) { sys.msg(40, 51); return false; }
    const u = def.use || {};
    const t = Number(def.type), c = Number(def.code);

    // boxes / packages / eggs: the boxes system owns the contents and windows
    if ((u.randomBox != null || u.package != null || (t === 0 && [24, 25, 59].includes(c)) || c >= 200 && c <= 212 && c !== 210 && c !== 211)
      && g.boxes?.open && g.boxes.isBox?.(def.index)) {
      const ok = await g.boxes.open(inst);
      return !!ok;
    }
    // recovery potions
    const grp = POTION_GROUP(def);
    if (grp) {
      const now = g.time || 0;
      if (now < (this.cooldowns.get(grp) || 0)) { sys.msg(40, 53); return false; }
      let hp = (u.hp || 0) + (u.hpPct ? p.maxHp * u.hpPct / 100 : 0);
      let mp = (u.mp || 0) + (u.mpPct ? p.maxMp * u.mpPct / 100 : 0);
      const sh = (u.shield || 0) + (u.shieldPct ? (p.maxShield || 0) * u.shieldPct / 100 : 0);
      if (u.stamina&&!recoverStamina(g.save,Number(u.stamina),staminaRecoveryCap(db,def),typeof g.now==='function'?g.now():Date.now())) return false;
      const hpFull = p.hp >= p.maxHp, mpFull = p.mp >= p.maxMp;
      if (!u.stamina && !sh && !((hp > 0 && !hpFull) || (mp > 0 && !mpFull))) return false;
      if (hp > 0 && !hpFull) { const b = p.hp; p.hp = Math.min(p.maxHp, p.hp + Math.round(hp)); g.hud?.floater?.(p, `+${Math.round(p.hp - b)}`, 'heal'); }
      if (mp > 0 && !mpFull) { const b = p.mp; p.mp = Math.min(p.maxMp, p.mp + Math.round(mp)); g.hud?.floater?.(p, `+${Math.round(p.mp - b)} MP`, 'heal'); }
      if (sh > 0) p.shield = Math.min(p.maxShield || sh, (p.shield || 0) + sh);
      this.cooldowns.set(grp, now + (Number(def.appraisal) || 0) / 1000);
      return this._consume(inst, def);
    }
    // buffs
    if (u.itemStatus != null) {
      const group = recoveryGroup(def), now = g.time || 0;
      if (group && now < (this.cooldowns.get(group) || 0)) { sys.msg(40, 53); return false; }
      await db.tables();
      const st = db.T?.itemStatus?.[u.itemStatus];
      if (!st) { sys.msg(40, 99); return false; }
      if (!await this.applyStatus(st.statusIndex, st.lifeTimeMs, `item:${def.index}`, def.name, st.description)) { sys.msg(40, 99); return false; }
      if (st.hp) p.hp = Math.min(p.maxHp, p.hp + st.hp);
      if (st.mp) p.mp = Math.min(p.maxMp, p.mp + st.mp);
      const consumed = this._consume(inst, def);
      if (consumed && group) this.cooldowns.set(group, now + (Number(def.appraisal) || 0) / 1000);
      return consumed;
    }
    if (u.premiere != null) {
      await db.tables();
      const pr = db.T?.premiere?.[def.index] || db.T?.premiere?.[u.premiere];
      const secs = Number(pr?.Time) || def.period || 86400;
      if (pr?.StatusIndex && !await this.applyStatus(pr.StatusIndex, secs * 1000, `premiere:${def.index}`, def.name)) { sys.msg(40, 99); return false; }
      g.save.premiere = { item: def.index, until: Date.now() + secs * 1000, ...pr };
      sys.msg(null, null, `${def.name}${sys.str(40, 52) || ' has been used.'}`);
      return this._consume(inst, def);
    }
    // skill books
    if (u.skill != null || u.meisterSkill != null) {
      const sk = g.skills;
      const idx = u.skill ?? u.meisterSkill;
      const ok = sk?.learnFromBook ? sk.learnFromBook(idx, def) : sk?.learn ? sk.learn(idx) : false;
      if (!ok) { sys.msg(40, 56); return false; }
      return this._consume(inst, def);
    }
    // Portal Scroll creates its owned portal; stepping into it is a separate
    // host travel action. Ordinary Return Scroll below remains unchanged.
    if (t === 3 && c === 4) {
      if (!g.createPersonalPortal || !await g.createPersonalPortal(def)) return false;
      return this._consume(inst, def);
    }
    // return / teleport scrolls
    if (u.teleport != null) {
      if (g.world?.info?.row && Number(g.world.info.row.ReturnScroll ?? 1) === 0) { sys.msg(40, 94); return false; }
      let target = null;
      if (Number(u.teleport) === 0) target = g.respawnTarget ? g.respawnTarget() : null;
      else { const L = (await this.locations()).get(Number(u.teleport)); if (L && g.mapRow?.(L.map)) target = { mapIndex: L.map, x: L.x, z: L.z, dirDeg: L.dirDeg }; }
      if (!target) { sys.msg(40, 50); return false; }
      if (!this._consume(inst, def)) return false;
      g.travel(target.mapIndex, target);
      return true;
    }
    if (t === 0) {
      switch (c) {
        case 63: { // Meister Change; the host runs this on its transaction copy.
          const plan = planMeisterChange(g.save, { skills: g.skills?.list || g.classDef?.skills }, g.data?.nameplateGrades || g.life?.grade?.G?.grades || g.life?.data?.grade?.grades);
          if (plan.error) { sys.error = plan.error; sys.msg(null, null, plan.error); return false; }
          sys.consume(inst, 1);
          const { meister, skills, skillPoints, normalSkillResetSuppressed } = plan;
          Object.assign(g.save, { meister, skills, skillPoints, normalSkillResetSuppressed });
          g.skills?.refreshPassives?.();
          g.events?.emit('skilllearn', { reset: 'skill', meisterPath: meister.path });
          g.events?.emit('itemuse', { item: inst, def });
          return true;
        }
        case 15: {   // Traveler's Backpack: +1 bag (7 max; 2 free + 5 uses)
          const s = g.save;
          if ((s.bagsUnlocked || 2) >= 7) { sys.msg(40, 59); return false; }
          s.bagsUnlocked = (s.bagsUnlocked || 2) + 1;
          sys.changed('bags');
          return this._consume(inst, def);
        }
        case 20: {   // Storage Mastery: +1 stash tab (2 uses per character)
          const s = g.save;
          if ((s.stashUnlocked || 2) >= 4) { sys.msg(40, 59); return false; }
          s.stashUnlocked = (s.stashUnlocked || 2) + 1;
          sys.changed('stash');
          return this._consume(inst, def);
        }
        case 29: {   // Storage Keeper's Key: shared stash (once per account)
          if (sys.account().sharedStash) { sys.msg(40, 59); return false; }
          sys.account().sharedStash = true; sys.saveAccount();
          sys.changed('stash');
          return this._consume(inst, def);
        }
        case 6: case 7: case 8: case 9: {   // stat regenerators: the allocated points of one stat come back
          if (wearsWeapon(sys)) { sys.msg(40, 51); sys.error = 'Only can use it after unequipping all weapons.'; return false; }   // item text 87..90
          const key = STAT_RESET[c];
          const base = g.classDef?.stats?.base || {};
          const s = g.save;
          const spent = Math.max(0, (Number(s.stats?.[key]) || 0) - (Number(base[key]) || 0));
          if (!spent) { sys.msg(40, 51); return false; }
          s.stats[key] = Number(base[key]) || 0;
          s.statPoints = (Number(s.statPoints) || 0) + spent;
          g.refreshPlayerStats?.(false);
          g.events?.emit('stats', { reset: key });
          return this._consume(inst, def);
        }
        case 10: {   // Master's Mistake: skill reset (Global item text 86: the first reset is free, further ones use this item)
          // Global 170:25 "Your number of skill resets is already 0; cannot use the Master's Mistake." and 170:26 shows the
          // accumulated reset count going down (the only change a refusal at 0 allows): one reset is taken off the count.
          const resets = Math.max(0, Math.floor(Number(g.save.skillResets) || 0));
          if (!resets) { sys.error = "Your number of skill resets is already 0; cannot use the Master's Mistake."; sys.msg(null, null, sys.error); return false; }
          const ok = g.skills?.resetAll ? g.skills.resetAll() : this._resetSkills();
          if (!ok) return false;
          if (!this._consume(inst, def)) return false;
          g.save.skillResets = resets - 1;
          return true;
        }
        case 210: {  // Rescue Pill: remove debuffs
          const list = g.save.buffs || [];
          const before = list.length;
          g.save.buffs = list.filter(b => !(b.debuff || (b.options || []).some(o => /_SUB$|DECREASE/.test(o.code))));
          if (g.player) g.player.statuses = g.save.buffs;
          if (g.save.buffs.length === before) return false;
          g.refreshPlayerStats?.(false);
          return this._consume(inst, def);
        }
        case 23: case 80: case 27:   // character / guild name change; 27 = Guild Master's Mistake (guild name change history): the original windows (extras/namechange.js) spend the item on success
          if (!g.nameChange?.use?.(inst, def)) sys.msg(40, 51);
          return false;
        case 16:     // Guild of Glory (the glowing guild emblem): the Guild Master registers the effect (network/mail-guild.js, the host spends the item)
          if (!g.life?.guild?.useGlory?.(inst, def)) sys.msg(40, 51);
          return false;
        case 30:     // Alliance of Glory (ALLIANCE): the Alliance Commander sets the alliance effect (extras/alliance.js, host spends the item)
          if (!g.alliance?.useGlory?.(inst, def)) sys.msg(40, 51);
          return false;
        case 41:     // disassembly hammer: the item dismantle page (ui_itemincusewnd_renew.txt tab 0) with the hammer registered
          g.uiwin?.open?.('incuse', { tab: 0 });
          return false;
        case 81:     // wing class exchange ticket (mounts system window)
          if (g.uiwin?.has?.('wingclassexchange')) g.uiwin.open('wingclassexchange', { ticket: inst });
          else sys.msg(40, 51);
          return false;
        case 38: case 39:   // Megaphone / DK Megaphone: the super chat input window (hud-options/superchat.js) spends them per broadcast
          if (g.superchat) g.superchat.use(inst, def); else sys.msg(40, 51);
          return false;
        default: break;
      }
    }
    if (g.boxes?.isBox?.(def.index)) return !!(await g.boxes.open(inst));
    sys.msg(40, 51);
    return false;
  }

  _resetSkills() {
    const g = this.game, s = g.save;
    const refund = Object.values(s.skills || {}).reduce((a, v) => a + (Number(v?.level ?? v) || 0), 0);
    if (!refund) return false;
    s.skills = {};
    s.skillPoints = (Number(s.skillPoints) || 0) + refund;
    g.events?.emit('skills:reset', {});
    return true;
  }

  /** Put a skills_status.json status on the player for ms (same entry shape as skills.js addStatus). */
  async applyStatus(statusIndex, ms, key, name, description = '') {
    const g = this.game;
    const all = await this.statuses();
    const def = all?.[statusIndex];
    if (!def || !(ms > 0)) return null;
    if (!Array.isArray(g.save.buffs)) g.save.buffs = [];
    const list = g.save.buffs;
    const entry = {
      key, statusIndex, name: name || def.description || 'Status', description: description || def.description || '',
      iconIndex: def.iconIndex ?? null, options: (def.options || []).map(o => ({ code: o.code, value: o.value })),
      duration: ms / 1000, remaining: ms / 1000, tick: 0, item: true,
    };
    const i = list.findIndex(s => s.key === key || (s.statusIndex === statusIndex && def.group && s.group === def.group));
    entry.group = def.group;
    if (i >= 0) list[i] = entry; else list.push(entry);
    if (g.player) g.player.statuses = list;
    g.refreshPlayerStats?.(false);
    g.events?.emit('status', { actor: g.player, status: entry, on: true });
    return entry;
  }

  _consume(inst, def) {
    const sys = this.sys;
    sys.consume(inst, 1);
    this.game.events?.emit('itemuse', { item: inst, def });
    return true;
  }
}
