// Item-driven skill procs of the player:
//
// FORCE STONES (items type 11, equipment slots force1 / force2; option 335 = offensive stance, 336 = defensive stance,
// the option value = share/item/force_skill.csv Type_Index, decoded in common.json forceSkills):
//   offensive  every landed hit of the player (basic attacks and skills) rolls Probability / 100000 for each worn
//              offensive force; the result applies to the struck monster
//   defensive  every landed monster hit on the player rolls the worn defensive forces; results that name a target
//              (EffectPos 1) apply to the attacker, the rest to the player
//   CoolTime ms between two procs of the same force; ResultEffect plays on the unit the result lands on.
//   Result codes are the skill ones (engine.applyImpact) plus the two force-only codes the item texts explain:
//   8000000 [_, N] "N true dmg is added when attacking" and 8000001 [hp, mp] "Recovers N HP/MP immediately".
//
// RUNES (share/item/runeitem_check.csv): a rune item in the inventory (IsEquipment 0) or worn (IsEquipment 1, the
// enhanced costume sets) gives, on every monster the player (or the servant) kills, a Rate_Normal per-mille chance of
// its buff (Status_Index1..3 for Status_Time s; Status_Delete1..4 end first; "does not stack": one per RuneGroup) and
// of Critical EXP (Status_Default icon + EXP_Rate % of the kill's exp as a bonus). Players past StandardLevel use the
// *_OverLevel rates / statuses. At most 5 rune buffs at once (stringtable_button "Rune Buffs (Up to 5)").
import { fetchCSVObjects } from '../../engine/assets.js';
import { applyDamage, heal as healActor, isAlive, rand } from '../../game/combat.js';
import { grantExp } from '../../game/progression.js';

const num = v => (Number.isFinite(+v) ? +v : 0);
const OPT_FORCE_ATTACK = 335, OPT_FORCE_DEFENCE = 336;
const MAX_RUNE_BUFFS = 5;

export async function installProcs(game, sys) {
  const { engine, statuses, fx, data } = sys;
  const ev = game.events;
  if (!ev) return;

  // ------------------------------------------------------------------------------------------ force stones
  let forceCache = null;
  const forceList = () => {
    if (forceCache) return forceCache;
    const out = [];
    const items = game.items;
    const worn = items?.equip?.worn?.() || [];
    for (const { inst } of worn) {
      const def = items.def?.(inst?.itemIndex);
      const opts = [...(def?.options || []), ...(Array.isArray(inst?.options) ? inst.options : [])];
      for (const o of opts) {
        const id = Array.isArray(o) ? num(o[0]) : num(o?.id ?? o?.code);
        const val = Array.isArray(o) ? num(o[1]) : num(o?.value);
        if ((id === OPT_FORCE_ATTACK || id === OPT_FORCE_DEFENCE) && data.forceSkills[val]) {
          out.push({ index: val, stance: id === OPT_FORCE_ATTACK ? 'attack' : 'defence', item: inst.itemIndex });
        }
      }
    }
    forceCache = out;
    return out;
  };
  for (const e of ['equip', 'unequip', 'inventory:equip']) ev.on(e, () => { forceCache = null; });

  const cool = new Map();       // force index -> game time when ready
  const proc = (f, foe) => {
    const fs = data.forceSkills[f.index];
    if (!fs) return;
    const now = game.time || 0;
    if ((cool.get(f.index) || 0) > now) return;
    if (!(rand() * 100000 < num(fs.probability))) return;
    cool.set(f.index, now + num(fs.cooldownMs) / 1000);
    const p = game.player;
    const r = fs.result || {};
    const code = num(r.resultCode);
    const on = fs.onTarget && foe && isAlive(foe) ? foe : p;
    if (fs.effect) fx?.play(p, fs.effect, {});
    if (code === 8000000) {
      // true damage added to the hit
      if (foe && isAlive(foe)) applyDamage(game, p, foe, { amount: num(r.args?.[1]), miss: false, kind: 'magic', attackKey: 'force' });
    } else if (code === 8000001) {
      if (!engine.statuses.value(p, 'HP_RECOVERY_IMPOSSIBLE')) healActor(game, p, p, num(r.args?.[0]));
      if (!engine.statuses.value(p, 'MP_RECOVERY_IMPOSSIBLE')) p.mp = Math.min(num(p.maxMp), num(p.mp) + num(r.args?.[1]));
    } else if (r.family) {
      const ctx = { caster: p, skill: { index: -f.index, name: 'Force', targetMask: fs.onTarget ? 4 : 16 }, level: 1, target: on, point: { x: on.x, z: on.z }, owner: p, force: true };
      try { engine.applyResult(ctx, r); } catch (err) { console.warn('[skills] force proc', f.index, err); }
    }
    if (fs.hitEffect) fx?.play(on, fs.hitEffect, {});
  };

  ev.on('damage', e => {
    if (!e || e.miss || e.dot || !(e.amount > 0) || e.attackKey === 'force' || e.attackKey === 'reflect') return;
    const p = game.player;
    if (!p || p.dead) return;
    let stance = null, foe = null;
    if (e.source === p && e.target?.kind === 'monster') { stance = 'attack'; foe = e.target; }
    else if (e.target === p && e.source?.kind === 'monster') { stance = 'defence'; foe = e.source; }
    if (!stance) return;
    const list = forceList();
    if (!list.length) return;
    for (const f of list) if (f.stance === stance) proc(f, foe);
  });

  // ------------------------------------------------------------------------------------------ runes
  let runes = [];
  try {
    const rows = await fetchCSVObjects('share/item/runeitem_check.csv');
    runes = rows.map(r => ({
      item: num(r.ItemIndex), group: num(r.RuneGroup), rate: num(r.Rate_Normal), ratePremium: num(r.Rate_Premium),
      expRate: num(r.EXP_Rate), statusDefault: num(r.Status_Default),
      statuses: [r.Status_Index1, r.Status_Index2, r.Status_Index3].map(num).filter(x => x > 0),
      timeSec: num(r.Status_Time),
      remove: [r.Status_Delete1, r.Status_Delete2, r.Status_Delete3, r.Status_Delete4].map(num).filter(x => x > 0),
      equipment: num(r.IsEquipment) === 1, standardLevel: num(r.StandardLevel),
      rateOver: num(r.Rate_Normal_OverLevel),
      statusesOver: [r.Status_Index1_OverLevel, r.Status_Index2_OverLevel, r.Status_Index3_OverLevel].map(num).filter(x => x > 0),
      maps: [r.Map_Index1, r.Map_Index2, r.Map_Index3].map(num).filter(x => x > 0),
    })).filter(r => r.item > 0);
  } catch (err) { console.warn('[skills] runeitem_check.csv', err); }
  sys.runes = runes;

  const heldRunes = () => {
    const items = game.items;
    if (!items || !runes.length) return [];
    const worn = new Set((items.equip?.worn?.() || []).map(e => Number(e.inst?.itemIndex)));
    const byGroup = new Map();
    for (const r of runes) {
      if (byGroup.has(r.group)) continue;
      if (r.maps.length && !r.maps.includes(Number(game.world?.info?.index))) continue;
      const has = r.equipment ? worn.has(r.item) : num(items.count?.(r.item)) > 0;
      if (has) byGroup.set(r.group, r);
    }
    return [...byGroup.values()];
  };

  let critExp = 0;          // pending Critical EXP rate (%) for the exp event of this kill
  ev.on('death', ({ actor, killer } = {}) => {
    const p = game.player;
    if (!p || !actor || actor.kind !== 'monster') return;
    if (!(killer === p || killer?.owner === p)) return;
    const lv = num(game.save?.level);
    critExp = 0;
    // combat.kill grants the exp right after this event; exp that never comes (grey monsters) is forgotten
    queueMicrotask(() => { critExp = 0; });
    for (const r of heldRunes()) {
      const over = r.standardLevel > 0 && lv > r.standardLevel;
      const rate = over && r.rateOver > 0 ? r.rateOver : r.rate;
      if (!(rand() * 1000 < rate)) continue;
      // the buff
      const list = over && r.statusesOver.length ? r.statusesOver : r.statuses;
      if (list.length && r.timeSec > 0) {
        if (r.remove.length) statuses.remove(p, s => r.remove.includes(Number(s.statusIndex)), 'silent');
        const L = statuses.listOf(p);
        const runeBuffs = L.filter(s => s.rune && !list.includes(Number(s.statusIndex)));
        if (runeBuffs.length >= MAX_RUNE_BUFFS) statuses.remove(p, runeBuffs.sort((a, b) => a.remaining - b.remaining)[0], 'silent');
        for (const si of list) statuses.add(p, si, r.timeSec * 1000, { rune: true, item: true, itemIndex: r.item, name: game.items?.name?.(r.item) || undefined });
      }
      // Critical EXP
      if (r.expRate > 0) {
        critExp = Math.max(critExp, r.expRate);
        if (r.statusDefault) statuses.add(p, r.statusDefault, 3000, { rune: true, item: true, itemIndex: r.item, name: 'Critical EXP' });
      }
    }
  });
  ev.on('exp', e => {
    if (!critExp || !e || e.critical) return;
    const bonus = Math.round(num(e.amount) * critExp / 100);
    critExp = 0;
    if (bonus > 0) {
      try { grantExp(game, bonus); } catch (err) { console.warn('[skills] critical exp', err); }
      game.hud?.log?.(`Critical EXP +${bonus.toLocaleString('en-US')}`, 'exp');
    }
  });

  return { forceList, heldRunes };
}
