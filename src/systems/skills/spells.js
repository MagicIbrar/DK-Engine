// Spells (Aloken / Alokes "spell" skills: Increase range, Mana shock, Blow attack, Decrease damage, Kanssimo, Delamo
// ...): result codes 4200001..4200006 name a row of share/article/spell.csv, NOT a status.csv row:
//
//   INDEX, STATUSINDEX, COUNT, RATE, DES, PCEFFECTID/SCENE/TIME, MONSTEREFFECTID/SCENE/TIME, RESULTCODE, SPELLICON,
//   STATUSTIME, TARGETTYPE
//
// Casting puts the spell on the caster (4200001 / 4200003) or on everyone of the party within Arg3/128 m with Arg2 %
// (4200002 / 4 / 5 / 6). A spell holds COUNT charges; every trigger rolls RATE % and each proc spends one charge (the
// spell ends at 0, or after 10 minutes). Triggers: the offensive spells (4200001 / 2 / 5) on every landed hit of the
// owner, the defensive ones (4200003 / 4 / 6) on every monster hit the owner takes (before its damage applies).
// The proc (spell RESULTCODE, the cate-150 texts of SPELLICON say what each does):
//   4500001  STATUSTIME 0: normal damage to every enemy within DES/128 m of the owner ("Increase range"); else the
//            STATUSINDEX buff on the owner for STATUSTIME ms (Delamo "when being hit")
//   4500002  STATUSINDEX on the struck target (TARGETTYPE 0: Blow attack, Mana shock, Armor smash ...) or on the owner
//            (TARGETTYPE 1: Rebellions sword, Kanssimo) for STATUSTIME ms
//   4500004  STATUSINDEX on the owner for STATUSTIME ms (0 = for the hit being taken: Decrease damage absorbs, Reflect
//            damage reflects it)
// Visuals: PCEFFECT on the owner and MONSTEREFFECT on the target at each proc; the looping spell aura
// modelEffects.spell[SPELLICON] (modeleffect 41) while it lasts. Buff bar icon: imagetable Spell_B[SPELLICON]; the
// stack number shows the charges left.
import { fetchCSVObjects } from '../../engine/assets.js';
import { resolveAttack, applyDamage, isAlive, rand } from '../../game/combat.js';

const num = v => (Number.isFinite(+v) ? +v : 0);
const OFFENSIVE = new Set([4200001, 4200002, 4200005]);
const PARTY = new Set([4200002, 4200004, 4200005, 4200006]);
const SPELL_LIFE = 600;              // s - JUDGMENT (lane70c): "or after 10 minutes" is not stated by spell.csv or any Global file

export class SpellSystem {
  constructor(engine) {
    this.engine = engine;
    this.game = engine.game;
    this.rows = new Map();
    this.texts = {};
    this.handles = new WeakMap();    // entry -> aura effect handle
  }

  async load() {
    try {
      const rows = await fetchCSVObjects('share/article/spell.csv', true);
      for (const r of rows) {
        const i = num(r.INDEX);
        if (!(i > 0)) continue;
        this.rows.set(i, {
          index: i, status: num(r.STATUSINDEX), count: num(r.COUNT), rate: num(r.RATE), des: num(r.DES),
          pcEffect: num(r.PCEFFECTID) > 0 ? { cate: 100, id: num(r.PCEFFECTID), scene: num(r.PCSCENEID) || 1, timeMs: num(r.PCEFFECTTIME) || 500 } : null,
          monsterEffect: num(r.MONSTEREFFECTID) > 0 ? { cate: 100, id: num(r.MONSTEREFFECTID), scene: num(r.MONSTERSCENEID) || 1, timeMs: num(r.MONSTEREFFECTTIME) || 500 } : null,
          result: num(r.RESULTCODE), icon: num(r.SPELLICON), statusTime: num(r.STATUSTIME), targetType: num(r.TARGETTYPE),
        });
      }
    } catch (err) { console.warn('[skills] spell.csv', err); }
    this.texts = this.engine.messages || {};
    return this;
  }

  spell(i) { return this.rows.get(Number(i)) || null; }
  name(row) {
    const t = this.engine.messages?.[`150:${row.icon}`] || '';
    return String(t).replace(/<[^>]+>/g, '').trim() || `Spell ${row.index}`;
  }

  /** A spell result landed: put the spell on the caster / the party members in range. */
  cast(ctx, r) {
    const e = this.engine, caster = ctx.caster;
    const code = num(r.resultCode);
    const row = this.spell(r.args?.[0] ?? r.statusIndex);
    if (!row || !caster) return 0;
    const party = PARTY.has(code);
    const chance = party ? (num(r.args?.[1]) || 100) : 100;
    const radius = party ? (num(r.args?.[2]) / 128 || 7) : 0;
    const list = party ? e.unitsNear({ x: caster.x, z: caster.z }, radius, caster, 'ally') : [caster];
    if (party && !list.includes(caster)) list.unshift(caster);
    let n = 0;
    for (const u of list) {
      if (!isAlive(u) || rand() * 100 >= chance) continue;
      this._put(u, row, OFFENSIVE.has(code) ? 'attack' : 'defend', ctx.skill);
      n++;
    }
    return n;
  }

  _put(unit, row, trigger, skill) {
    const st = this.engine.statuses;
    const L = st.listOf(unit);
    // one spell per SPELLICON kind: a new cast replaces the old one
    for (let i = L.length - 1; i >= 0; i--) if (L[i].spell && L[i].spellIcon === row.icon) { this._stopAura(L[i]); L.splice(i, 1); }
    const entry = {
      key: `spell:${row.index}`, spell: row.index, spellIcon: row.icon, trigger, skillIndex: skill?.index ?? null,
      name: skill?.name || this.name(row), description: this.name(row),
      iconGroup: 'Spell_B', iconIndex: row.icon, options: [], duration: SPELL_LIFE, remaining: SPELL_LIFE, tick: 0,
      charges: row.count, stack: row.count, stacks: 1, buff: true, debuff: false, keepWanted: false, at: this.game.time || 0,
    };
    L.push(entry);
    const aura = this.engine.data.modelEffects?.spell?.[row.icon];
    // lane70c: the aura scene runs on its own Global eff_time (modeleffect 41: 1000 / 2000 / 4000 ms). It used to be
    // stretched to SPELL_LIFE (600 000 ms), which slowed its authored timeline 150-600x. JUDGMENT: all 12 modeleffect 41
    // rows say eff_loop 1 yet are described "keep"; the aura keeps looping for the spell's life as before.
    if (aura) { const h = this.engine.fx?.play(unit, aura, { loop: true }); if (h) this.handles.set(entry, h); }
    this.game.events?.emit('status', { actor: unit, status: entry, on: true });
  }

  _stopAura(entry) { const h = this.handles.get(entry); if (h) { h.stop?.(true); this.handles.delete(entry); } }

  _spend(unit, entry) {
    entry.charges = num(entry.charges) - 1;
    entry.stack = entry.charges;
    if (entry.charges <= 0) {
      const L = this.engine.statuses.listOf(unit, false) || [];
      const i = L.indexOf(entry);
      if (i >= 0) L.splice(i, 1);
      this._stopAura(entry);
      this.game.events?.emit('status', { actor: unit, status: entry, on: false, reason: 'spent' });
    }
  }

  _spells(unit, trigger) {
    const L = unit?.statuses;
    if (!L || !L.length) return [];
    return L.filter(s => s.spell && s.trigger === trigger && !(s.remaining <= 0) && num(s.charges) > 0);
  }

  _rate(owner, row) {
    // Native Spell Mastery option185 and Reinforce status9301..9309 are
    // SPELL_ADD_RATE. Their authored values add to spell.csv RATE (%).
    return row.rate + this.engine.optionValue(owner, 'SPELL_ADD_RATE');
  }

  /** The owner landed a hit on `target`. */
  onAttack(owner, target) {
    for (const s of this._spells(owner, 'attack')) {
      const row = this.spell(s.spell);
      if (!row || rand() * 100 >= this._rate(owner, row)) continue;
      this._proc(owner, target, row);
      this._spend(owner, s);
    }
  }

  /** A monster hit is about to land on the owner (called from the beforeDamage hook, before the reductions). */
  onHurt(owner, attacker) {
    for (const s of this._spells(owner, 'defend')) {
      const row = this.spell(s.spell);
      if (!row || rand() * 100 >= this._rate(owner, row)) continue;
      this._proc(owner, attacker, row);
      this._spend(owner, s);
    }
  }

  _proc(owner, other, row) {
    const e = this.engine, g = this.game;
    if (row.pcEffect) e.fx?.play(owner, row.pcEffect, {});
    const st = e.statuses;
    const on = (u, ms) => { if (u && isAlive(u) && row.status) st.add(u, row.status, ms, { source: owner, name: this.name(row) }); };
    switch (row.result) {
      case 4500001:
        if (row.statusTime > 0) { on(owner, row.statusTime); break; }
        for (const t of e.unitsNear({ x: owner.x, z: owner.z }, Math.max(1, row.des / 128), owner, 'enemy')) {
          const res = resolveAttack(owner, t, { data: g.data });
          res.attackKey = 'spell';
          applyDamage(g, owner, t, res);
          if (row.monsterEffect) e.fx?.play(t, row.monsterEffect, {});
        }
        break;
      case 4500002:
        if (row.targetType === 1) on(owner, row.statusTime || 3000);
        else { on(other, row.statusTime || 3000); if (other && row.monsterEffect) e.fx?.play(other, row.monsterEffect, {}); }
        break;
      case 4500004:
        on(owner, row.statusTime || 1000);
        break;
      default:
        on(owner, row.statusTime || 3000);
    }
  }

  /** The aura of spells restored from a save / after a map change. */
  restore(unit) {
    for (const s of unit?.statuses || []) {
      if (!s.spell || this.handles.get(s)) continue;
      const aura = this.engine.data.modelEffects?.spell?.[s.spellIcon];
      if (aura) { const h = this.engine.fx?.play(unit, { ...aura, timeMs: Math.max(1, num(s.remaining)) * 1000 }, { loop: true }); if (h) this.handles.set(s, h); }
    }
  }
}
