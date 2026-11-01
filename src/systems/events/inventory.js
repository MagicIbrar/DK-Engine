// Inventory / currency adapter for the events (tickets, Map of Fortress, Castle Keys, rewards, DIL fees).
// Prefers the item system's API when one is installed (game.items / game.inventory: count/remove/add), else works on
// save.inventory entries {itemIndex, name, count} through game.loot.addItem (src/game/loot.js).
// Event currencies that have no item (R-points, Colosseum points, battle-royale points) live in save.eventPoints.

const api = (game) => {
  for (const o of [game.items, game.inventory, game.bag]) {
    if (o && typeof o.count === 'function' && typeof o.remove === 'function') return o;
  }
  return null;
};

const idxOf = (e) => Number(e?.itemIndex ?? e?.index ?? e?.id);

/** How many of an item the player carries. */
export function itemCount(game, itemIndex) {
  const a = api(game);
  if (a) { try { return Number(a.count(Number(itemIndex))) || 0; } catch { /* fall through */ } }
  let n = 0;
  for (const e of game.save?.inventory || []) if (e && idxOf(e) === Number(itemIndex)) n += Number(e.count) || 1;
  return n;
}

/** Remove `count` of an item. Returns true when the player had enough (and they were removed). */
export function removeItem(game, itemIndex, count = 1) {
  if (itemCount(game, itemIndex) < count) return false;
  const a = api(game);
  if (a) { try { const r = a.remove(Number(itemIndex), count); if (r !== false) { emitInv(game); return true; } } catch { /* fall through */ } }
  const inv = game.save?.inventory || [];
  let left = count;
  for (let i = inv.length - 1; i >= 0 && left > 0; i--) {
    const e = inv[i];
    if (!e || idxOf(e) !== Number(itemIndex)) continue;
    const take = Math.min(left, Number(e.count) || 1);
    e.count = (Number(e.count) || 1) - take;
    left -= take;
    if (e.count <= 0) inv.splice(i, 1);
  }
  emitInv(game);
  return left <= 0;
}

/** Give an item (stacks). Returns true on success, false when the bag is full. */
export function addItem(game, itemIndex, count = 1, name = '') {
  const a = api(game);
  if (a && typeof a.add === 'function') {
    try {
      const r = a.add(Number(itemIndex), count, { source: 'events', dropLeft: true });
      const ok = r && typeof r === 'object' ? (r.ok !== false || (r.placed?.length > 0)) : r !== false && r != null;
      if (ok) { emitInv(game); return true; }
      return false;
    } catch { /* fall through */ }
  }
  const loot = game.loot;
  const entry = { itemIndex: Number(itemIndex), name: name || `Item ${itemIndex}`, count, grade: 'normal', stack: count > 1 };
  if (loot?.canFit && !loot.canFit(entry)) return false;
  const r = loot?.addItem ? loot.addItem(entry) : null;
  if (!r) {
    const inv = (game.save.inventory ||= []);
    inv.push({ uid: `ev${Date.now().toString(36)}${Math.floor(Math.random() * 1e6).toString(36)}`, ...entry });
  }
  game.events?.emit?.('loot', { name: entry.name, count, kind: 'item', itemIndex: Number(itemIndex) });
  emitInv(game);
  return true;
}

function emitInv(game) { try { game.events?.emit?.('inventory', { source: 'events' }); } catch { /* ignore */ } }

export function dil(game) { return Number(game.save?.dil) || 0; }
export function payDil(game, amount) {
  const s = game.save;
  if (!s || dil(game) < amount) return false;
  s.dil = dil(game) - amount;
  game.events?.emit?.('dil', { amount: -amount, source: 'events' });
  return true;
}
export function giveDil(game, amount) {
  const s = game.save;
  if (!s || !(amount > 0)) return;
  s.dil = dil(game) + amount;
  game.events?.emit?.('dil', { amount, source: 'events' });
}

/** Event point balances (save.eventPoints): rPoint, colosseumPoint, brPoint, ... */
export function points(game) { return (game.save.eventPoints ||= {}); }
export function addPoints(game, kind, amount) {
  const p = points(game);
  p[kind] = (Number(p[kind]) || 0) + (Number(amount) || 0);
  game.events?.emit?.('eventpoints', { kind, amount, total: p[kind] });
  return p[kind];
}
