import {gameplayPreferences} from '../../game/gameplay-preferences.js';
// Inventory adapter used by quests and boxes. The inventory belongs to the items system (game.items: add / count /
// remove / canAddAll / consume / addDil / dil, src/systems/items); without it this works on the core inventory
// (game.loot.addItem / canFit + save.inventory entries {uid, itemIndex, name, count, stack, grade}).
// Every change made here emits game.events 'inventory' {reason, itemIndex, count} (the items system emits its own).

const MAX_FALLBACK = 48;   // loot.js MAX_INVENTORY (8 x 6 bag)
const num = v => Number(v) || 0;
const okOf = r => (r && typeof r === 'object' && 'ok' in r ? !!r.ok && !(num(r.left) > 0) : r !== false && r != null);

export class InventoryAdapter {
  constructor(game, db) { this.game = game; this.db = db; }

  /** The items system when it is installed and ready. */
  get items() { const it = this.game.items; return it && typeof it.add === 'function' && typeof it.count === 'function' && it.bag ? it : null; }

  /** How many of an item the player carries (bag). */
  count(itemIndex) {
    const i = Number(itemIndex);
    const it = this.items;
    if (it) { try { return num(it.count(i)); } catch { return 0; } }
    let n = 0;
    for (const e of this.game.save?.inventory || []) if (e && Number(e.itemIndex ?? e.index) === i) n += e.count == null ? 1 : num(e.count);
    return n;
  }

  /** Would all of these fit? list = [{item, count}] */
  canFit(list) {
    const items = (list || []).filter(x => x && x.item != null && num(x.count || 1) > 0);
    if (!items.length) return true;
    const it = this.items;
    const noStack=items.some(x=>x.reason==='questReward')&&(this.game.options?.get?.('stackQuestReward')??gameplayPreferences(this.game.save?.gameplayPreferences).stackQuestReward)===false;
    if (it?.canAddAll) { try { return !!it.canAddAll(items.map(x => [Number(x.item), Math.max(1, num(x.count || 1))]),{noStack}); } catch { /* fall back */ } }
    // core inventory simulation: fill existing stacks, then one entry per stack
    const inv = (this.game.save?.inventory || []).filter(Boolean);
    let free = MAX_FALLBACK - inv.length;
    const room = new Map();
    for (const e of inv) {
      const idx = Number(e.itemIndex ?? e.index);
      const max = this.db.itemStack(idx);
      if (!noStack && e.stack && max > 1) room.set(idx, (room.get(idx) || 0) + Math.max(0, max - num(e.count)));
    }
    for (const x of items) {
      const idx = Number(x.item);
      let left = num(x.count || 1);
      const max = this.db.itemStack(idx);
      if (max > 1) {
        const r = room.get(idx) || 0;
        const use = Math.min(r, left);
        room.set(idx, r - use);
        left -= use;
        while (left > 0) { free--; const put = Math.min(max, left); left -= put; room.set(idx, (room.get(idx) || 0) + (max - put)); }
      } else free -= left;
      if (free < 0) return false;
    }
    return free >= 0;
  }

  /**
   * Give an item. opts: {period (s: custom lifetime, e.g. quest timed items), bound, grade, sockets, reason}.
   * Returns true when everything was added.
   */
  add(itemIndex, count = 1, opts = {}) {
    const g = this.game;
    const idx = Number(itemIndex);
    const n = Math.max(1, Math.round(num(count) || 1));
    const it = this.items;
    if (it) {
      let r;
      try { r = it.add(idx, n, { grade: opts.grade, bound: opts.bound, sockets: opts.sockets, source: opts.reason || 'quest', noStack:opts.reason==='questReward'&&(g.options?.get?.('stackQuestReward')??gameplayPreferences(g.save?.gameplayPreferences).stackQuestReward)===false, silent: false }); }
      catch (err) { console.warn('[quests] items.add failed', err); return false; }
      if (opts.period > 0) for (const p of r?.placed || []) { const inst = p?.inst || p; if (inst && typeof inst === 'object') inst.expiresAt = Date.now() + opts.period * 1000; }
      return okOf(r);
    }
    const name = this.db.itemName(idx);
    const period = opts.period ?? this.db.itemPeriod(idx);
    const expiresAt = period > 0 ? Date.now() + period * 1000 : null;
    const max = this.db.itemStack(idx);
    const entry = g.loot?.addItem?.({ itemIndex: idx, name, count: n, stack: max > 1, grade: opts.grade || 'normal' });
    let ok = !!entry;
    if (!g.loot) {
      (g.save.inventory ||= []).push({ uid: `q${Date.now().toString(36)}${Math.random().toString(36).slice(2, 6)}`, itemIndex: idx, name, count: n, stack: max > 1, grade: 'normal', expiresAt });
      ok = true;
    } else if (entry && expiresAt) entry.expiresAt = expiresAt;
    if (ok) g.events?.emit?.('inventory', { reason: opts.reason || 'quest', itemIndex: idx, count: n, added: true });
    return ok;
  }

  /** Remove `count` of an item (from any stacks). Returns true when that many were removed. */
  remove(itemIndex, count = 1, opts = {}) {
    const g = this.game;
    const idx = Number(itemIndex);
    let left = Math.max(1, Math.round(num(count) || 1));
    if (this.count(idx) < left) return false;
    const it = this.items;
    if (it) { try { return !!it.remove(idx, left); } catch (err) { console.warn('[quests] items.remove failed', err); return false; } }
    const inv = g.save.inventory || [];
    for (let i = inv.length - 1; i >= 0 && left > 0; i--) {
      const e = inv[i];
      if (!e || Number(e.itemIndex ?? e.index) !== idx) continue;
      const have = e.count == null ? 1 : num(e.count);
      const take = Math.min(have, left);
      left -= take;
      if (have - take <= 0) inv.splice(i, 1); else e.count = have - take;
    }
    g.events?.emit?.('inventory', { reason: opts.reason || 'quest', itemIndex: idx, count, removed: true });
    return left <= 0;
  }

  /** Consume `count` of one specific inventory entry / instance (a used box). */
  consumeEntry(entry, count = 1) {
    const g = this.game;
    const it = this.items;
    if (it && entry && typeof entry === 'object') {
      try {
        if ((entry.count ?? 1) >= count && it.where?.(entry)) { it.consume(entry, count); return true; }
        return this.remove(entry.itemIndex, count);
      } catch (err) { console.warn('[quests] items.consume failed', err); return false; }
    }
    const inv = g.save.inventory || [];
    if (entry && inv.includes(entry)) {
      const have = entry.count == null ? 1 : num(entry.count);
      if (have < count) return this.remove(entry.itemIndex ?? entry.index, count, { reason: 'use' });
      if (have - count <= 0) inv.splice(inv.indexOf(entry), 1); else entry.count = have - count;
      g.events?.emit?.('inventory', { reason: 'use', itemIndex: Number(entry.itemIndex ?? entry.index), count, removed: true });
      return true;
    }
    return this.remove(entry?.itemIndex ?? entry?.index ?? entry, count, { reason: 'use' });
  }

  get dil() { const it = this.items; return it ? num(it.dil) : num(this.game.save?.dil); }
  addDil(n) {
    const g = this.game;
    const it = this.items;
    if (it?.addDil) { it.addDil(n); return; }
    g.save.dil = Math.max(0, num(g.save.dil) + num(n));
    g.events?.emit?.('dil', { amount: n });
  }
}
