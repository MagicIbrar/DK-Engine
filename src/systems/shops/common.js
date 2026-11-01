// Shared helpers of the shops system: data tables, item info, the inventory adapter (bag), dil, item icons,
// item tooltips and client strings. Everything the shop windows need from other systems goes through here, so the
// windows keep working whatever the inventory / items systems look like (all their hooks are probed at run time).
import { fetchJSON } from '../../engine/assets.js';
import { renderItemIcon } from '../../ui/frontend/itemicon.js';
import { withWingShop } from '../../content/wing-items.js';
import { withNativeWingShop } from '../../content/native-wing-shop.js';
import { ItemDB } from '../items/db.js';

// ------------------------------------------------------------------------------------------ data tables
const J = {
  shops: '/gamedata/shops.json',
  dshop: '/gamedata/dshop.json',
  search: '/gamedata/shops_search.json',
  items: '/gamedata/items.json',
  visual: '/gamedata/items-visual.json',
};
export const T = { shops: null, dshop: null, search: null, items: null, itemDefaults: null, visual: null };
const loading = {};
function load(k) {
  if (!loading[k]) loading[k] = fetchJSON(J[k]).then(async v => {
    if(k==='dshop'){const [db,mounts]=await Promise.all([ItemDB.load(),fetchJSON('/gamedata/mounts.json')]);v=withNativeWingShop(withWingShop(v),{core:db.core,looks:db.looks,visual:db.visual,mounts});}
    T[k]=v;return T[k];
  }).catch(err => { console.warn(`[shops] ${J[k]} unavailable`, err); loading[k] = null; return null; });
  return loading[k];
}
export const loadShops = () => load('shops');
export const loadDshop = () => load('dshop');
export const loadSearch = () => load('search');
/** The full item database (items.json, ~30 MB; shared with any other fetchJSON user of the same URL). */
export async function loadItemDB(game) {
  const ext = extItems(game);
  if (ext?.sys) { await ext.sys.ready; return ext; }
  if (ext) return ext;
  const db = await load('items');
  if (db && !T.itemDefaults) T.itemDefaults = db.itemDefaults || {};
  return db;
}
export const loadVisual = () => load('visual');

/** The items system (src/systems/items: game.items.def/add/count/remove/tooltip/icon...), when installed. */
export function itemsSys(game) {
  const g = game?.items;
  return g && typeof g.def === 'function' && typeof g.add === 'function' ? g : null;
}
/** An item database another system exposes, probed by a few likely names. */
function extItems(game) {
  const s = itemsSys(game);
  if (s) return { get: (i) => { try { return s.def(i); } catch { return null; } }, sys: s };
  const g = game?.itemDB || null;
  return g && (typeof g.get === 'function' || g.items) ? g : null;
}

// ------------------------------------------------------------------------------------------ item info
const infoCache = new Map();
/**
 * Everything known about an item, merged from the shop tables (icons, cash prices) and the full item database
 * (price, sell, npcSell, w/h, stack, period...). Sync: returns what is loaded now ({} fields missing until loaded).
 */
export function itemInfo(game, idx) {
  idx = Number(idx);
  const hit = infoCache.get(idx);
  if (hit && hit._full) return hit;
  const out = { index: idx };
  const ext = extItems(game);
  let full = null;
  if (ext?.get) { try { full = ext.get(idx); } catch { full = null; } }
  else if (ext?.items) full = ext.items[idx] ? { ...(ext.itemDefaults || {}), ...ext.items[idx] } : null;
  if (!full && T.items?.items?.[idx]) full = { ...(T.itemDefaults || T.items.itemDefaults || {}), ...T.items.items[idx] };
  if (full) Object.assign(out, full);
  const s = T.shops?.items?.[idx], d = T.dshop?.items?.[idx];
  if (s) for (const [k, v] of Object.entries(s)) if (out[k] == null || k === 'icon') out[k] = v;
  if (d) for (const [k, v] of Object.entries(d)) if (out[k] == null || k === 'icon' || k === 'vipCost') out[k] = v;
  if (out.w == null) out.w = 1;
  if (out.h == null) out.h = 1;
  if (!out.name) out.name = `Item ${idx}`;
  out._full = !!full;
  infoCache.set(idx, out);
  return out;
}
/** itemInfo after making sure the full database is loaded. */
export async function itemInfoFull(game, idx) {
  if (!itemInfo(game, idx)._full) {
    const sys = itemsSys(game);
    if (sys) await sys.ready; else await loadItemDB(game);
    infoCache.delete(Number(idx));
  }
  return itemInfo(game, idx);
}
export function itemName(game, idx) { return itemInfo(game, idx).name; }
/** Units a stack of this item can hold in the bag (1 = does not stack). */
export function maxStackOf(game, idx) {
  const sys = itemsSys(game);
  if (sys?.db?.stackSize) { try { const d = sys.def(Number(idx)); if (d) return Math.max(1, Number(sys.db.stackSize(d)) || 1); } catch { /* fall back */ } }
  const it = itemInfo(game, idx);
  return Math.max(1, Number(it.maxStack) || 0, Number(game?.loot?.stackMax?.(idx)) || 0);
}

// ------------------------------------------------------------------------------------------ icons
/** Inventory model of an item -> {mesh, tpack} (shop tables icon [mesh, tpack, scale], else items-visual shapes). */
export async function iconModel(game, idx) {
  const it = itemInfo(game, idx);
  if (Array.isArray(it.icon) && it.icon[0]) return { mesh: it.icon[0], tpack: it.icon[1] || null, scale: it.icon[2] || 1 };
  const ext = game?.items?.iconModel || game?.inventory?.iconModel;
  if (typeof ext === 'function') { try { const m = await ext.call(game.items || game.inventory, idx); if (m?.mesh) return m; } catch { /* fall through */ } }
  let shape = it.shape;
  if (shape == null) { await itemInfoFull(game, idx); shape = itemInfo(game, idx).shape; }
  if (!shape) return null;
  const V = await loadVisual();
  const inv = V?.shapes?.[shape]?.inv;
  return inv?.mesh ? { mesh: inv.mesh, tpack: inv.tpack || null, textures: inv.textures || null } : null;
}
/** An icon descriptor ({url}) of the item's inventory model rendered into a w x h px cell; null when unavailable. */
export async function itemIcon(game, idx, w, h) {
  const sys = itemsSys(game);
  if (sys && typeof sys.icon === 'function') {
    try { const r = await sys.icon(Number(idx), Math.round(w), Math.round(h)); return r ? (typeof r === 'string' ? { url: r } : r) : null; } catch (error) { console.warn('[shops] canonical item icon', idx, error); return null; }
  }
  const inv = await iconModel(game, idx);
  if (!inv) return null;
  const url = await renderItemIcon({ renderer: game.renderer, models: game.models }, inv, w, h);
  return url ? { url } : null;
}

/**
 * Paint an item into a "suit" item slot (cellsize 32: ui_storebuyitem_renew select_item 67x131, the consignment
 * register slot...) at its inventory footprint (w x h cells of 32 px), centred, as the bag draws it - not stretched.
 */
export async function setFootprintIcon(game, slot, idx, cell = 32) {
  if (!slot?.setIcon) return;
  slot.setIcon(null);
  if (idx == null) return;
  const inf = await itemInfoFull(game, idx);
  const w = Math.max(1, Number(inf.w) || 1) * cell, h = Math.max(1, Number(inf.h) || 1) * cell;
  const ic = await itemIcon(game, idx, w, h);
  if (!ic) return;
  slot.setIcon(ic);
  const s = slot._icon?.style;
  if (!s) return;
  const bw = slot.box?.w || w, bh = slot.box?.h || h;
  const k = Math.min(1, bw / w, bh / h);          // a footprint taller than the slot is scaled down to fit
  const dw = Math.round(w * k), dh = Math.round(h * k);
  s.width = `${dw}px`; s.height = `${dh}px`;
  s.left = `${Math.round((bw - dw) / 2)}px`; s.top = `${Math.round((bh - dh) / 2)}px`;
}

// ------------------------------------------------------------------------------------------ strings
/** A client string (NORMAL group) once loaded; `fallback` until then. */
export function str(game, cate, code, fallback = '') {
  const s = game?.uiwin?.strings?.get?.({ group: 'NORMAL', cate, code });
  return s == null ? fallback : s;
}
export async function strAsync(game, cate, code, fallback = '') {
  try { const s = await game?.uiwin?.strings?.resolve?.({ group: 'NORMAL', cate, code }); return s == null ? fallback : s; } catch { return fallback; }
}
export function fmtNum(n) { return Math.round(Number(n) || 0).toLocaleString('en-US'); }
/** Drop the client markup the UI text renderer does not draw (<center>, <font=N>, <set=..>); colours are kept. */
export function cleanMarkup(s) { return String(s ?? '').replace(/<\/?center>|<font=\d+>|<\/font>|<set=[^>]*>/gi, ''); }

/** System-log / HUD message. */
export function say(game, text, kind = 'sys') {
  if (!text) return;
  try { game?.hud?.log?.(String(text).replace(/<[^>]+>/g, ''), kind); } catch { /* optional */ }
}
/** The original result message box (msgbox/ui_resultbox.txt). */
export function notice(game, text, title = '') {
  if (!game?.uiwin) { say(game, text, 'err'); return Promise.resolve('ok'); }
  return game.uiwin.msgbox(String(text ?? ''), { title, kind: 'ok' }).catch(() => 'ok');
}
export function confirmBox(game, text, title = '') {
  if (!game?.uiwin) return Promise.resolve('yes');
  return game.uiwin.msgbox(String(text ?? ''), { title, kind: 'yesno' }).catch(() => 'no');
}

// ------------------------------------------------------------------------------------------ dil
export const MAX_DIL = 2000000000;   // client u32 money field capped by the server at 2,000,000,000 (store msg 7 when reached)
export function dil(game) { return Math.max(0, Math.floor(Number(game?.save?.dil) || 0)); }
export function addDil(game, n) {
  const s = game?.save;
  if (!s) return false;
  const inv = itemsSys(game) || game.inventory;
  if (typeof inv?.addDil === 'function') { try { inv.addDil(n); game.events?.emit?.('inventory', { reason: 'dil' }); return true; } catch { /* fall back */ } }
  s.dil = Math.min(MAX_DIL, Math.max(0, dil(game) + Math.round(n)));
  game.events?.emit?.('dil', { dil: s.dil, delta: n });
  game.events?.emit?.('inventory', { reason: 'dil' });
  return true;
}

// ------------------------------------------------------------------------------------------ the bag (inventory adapter)
// The inventory system is probed first: game.inventory.{add|addItem, canAdd|canFit, count, remove, entries}.
// Without it the loot.js bag (save.inventory entries {uid, itemIndex, name, count, stack, grade}) is used.
function invApi(game) { return game?.inventory || game?.systems?.get?.('inventory')?.api || null; }
function call(api, names, ...args) {
  for (const n of names) if (typeof api?.[n] === 'function') return { ok: true, v: api[n](...args) };
  return { ok: false };
}
/** The bag through the items system (preferred): instances {uid, itemIndex, count, grade, rnd, sockets, bound, expiresAt}. */
const sysBag = {
  entries: (s) => s.bag?.list || [],
  count: (s, idx) => s.count(idx),
  canAdd: (s, idx, n) => s.canAdd(idx, n),
  canAddAll: (s, list) => (typeof s.canAddAll === 'function' ? s.canAddAll(list) : list.every(([i, c]) => s.canAdd(i, c))),
  add(game, s, idx, count, extra) {
    const opts = { source: extra.from || 'shop', silent: true };
    if (extra.bound) opts.bound = true;
    if (extra.grade) opts.grade = extra.grade;
    if (extra.to) opts.to = extra.to;
    if (extra.purchaser) opts.purchaser = extra.purchaser;
    if (extra.inst) {
      const inst = { ...extra.inst, count };
      delete inst.page; delete inst.x; delete inst.y;
      return s.add(inst, opts).ok !== false;
    }
    const r = s.add(Number(idx), count, opts);
    if (r?.ok && extra.expires && r.placed) for (const p of r.placed) p.expiresAt = extra.expires;
    return !!r?.ok;
  },
  remove: (s, idx, n) => s.remove(idx, n),
  removeEntry: (s, e, n) => !!s.removeInst(e, n),
};
export const bag = {
  /** Bag entries (read-only view). */
  entries(game) {
    const s = itemsSys(game);
    if (s) return sysBag.entries(s);
    const api = invApi(game);
    const r = call(api, ['entries', 'list', 'items'], {});
    if (r.ok && Array.isArray(r.v)) return r.v;
    return Array.isArray(game?.save?.inventory) ? game.save.inventory : [];
  },
  /** Units of an item in the bag. */
  count(game, idx) {
    idx = Number(idx);
    { const s = itemsSys(game); if (s) return sysBag.count(s, idx); }
    const r = call(invApi(game), ['count', 'countItem'], idx);
    if (r.ok && Number.isFinite(Number(r.v))) return Number(r.v);
    let n = 0;
    for (const e of bag.entries(game)) if (e && Number(e.itemIndex) === idx) n += Math.max(1, Number(e.count) || 1);
    return n;
  },
  /** Could `count` units of the item be added? */
  canAdd(game, idx, count = 1) {
    idx = Number(idx);
    { const s = itemsSys(game); if (s) return sysBag.canAdd(s, idx, count); }
    const r = call(invApi(game), ['canAdd', 'canFit', 'hasRoomFor'], idx, count);
    if (r.ok) return !!r.v;
    const it = itemInfo(game, idx);
    const max = maxStackOf(game, idx);
    if (game?.loot?.canFit) return game.loot.canFit({ itemIndex: idx, count, stack: max > 1, name: it.name, grade: 'normal' });
    return true;
  },
  /** Can every [idx, count] pair be added together? (approximation: checked one by one) */
  canAddAll(game, list) {
    { const s = itemsSys(game); if (s) return sysBag.canAddAll(s, list); }
    const r = call(invApi(game), ['canAddAll'], list);
    if (r.ok) return !!r.v;
    return list.every(([i, c]) => bag.canAdd(game, i, c));
  },
  /** Add units; extra = { period (s), bound, from } */
  add(game, idx, count = 1, extra = {}) {
    idx = Number(idx); count = Math.max(1, Math.floor(Number(count) || 1));
    { const s = itemsSys(game); if (s) return sysBag.add(game, s, idx, count, extra); }
    const api = invApi(game);
    const it = itemInfo(game, idx);
    const expires = extra.period > 0 ? Date.now() + extra.period * 1000 : (extra.expires || null);
    const opts = { ...extra, expires, name: it.name };
    let r = call(api, ['add', 'addItem', 'give'], idx, count, opts);
    if (r.ok && r.v !== false && r.v != null) { game.events?.emit?.('inventory', { reason: 'add', itemIndex: idx, count }); return true; }
    if (r.ok) return false;
    const max = maxStackOf(game, idx);
    const entry = { itemIndex: idx, name: it.name, count, stack: max > 1, grade: extra.grade || 'normal' };
    let added = null;
    if (game?.loot?.addItem) added = game.loot.addItem(entry);
    else {
      const inv = (game.save.inventory ||= []);
      added = { uid: `s${Date.now().toString(36)}${Math.random().toString(36).slice(2, 7)}`, ...entry };
      inv.push(added);
    }
    if (added && (expires || extra.bound || extra.options)) {
      // stamp the extra fields on the entry that received the units (a fresh one when it did not stack)
      if (expires) added.expires = expires;
      if (extra.bound) added.bound = true;
      if (extra.options) added.options = extra.options;
    }
    if (added) {
      game.events?.emit?.('inventory', { reason: 'add', itemIndex: idx, count });
      game.events?.emit?.('loot', { name: it.name, count, kind: 'item', itemIndex: idx, silent: true, source: extra.from || 'shop' });
    }
    return !!added;
  },
  /** Remove `count` units of an item (any entries). Returns true when all were removed. */
  remove(game, idx, count = 1) {
    idx = Number(idx);
    { const s = itemsSys(game); if (s) return sysBag.remove(s, idx, count); }
    const r = call(invApi(game), ['remove', 'removeItem', 'take'], idx, count);
    if (r.ok) { game.events?.emit?.('inventory', { reason: 'remove', itemIndex: idx, count }); return r.v !== false; }
    if (bag.count(game, idx) < count) return false;
    const inv = game.save.inventory || [];
    let left = count;
    for (let i = inv.length - 1; i >= 0 && left > 0; i--) {
      const e = inv[i];
      if (!e || Number(e.itemIndex) !== idx) continue;
      const n = Math.max(1, Number(e.count) || 1);
      const k = Math.min(n, left);
      if (k >= n) inv.splice(i, 1); else e.count = n - k;
      left -= k;
    }
    game.events?.emit?.('inventory', { reason: 'remove', itemIndex: idx, count });
    return left <= 0;
  },
  /** Remove (part of) one bag entry. */
  removeEntry(game, entry, count = null) {
    { const s = itemsSys(game); if (s) return sysBag.removeEntry(s, entry, count); }
    const api = invApi(game);
    const n = Math.max(1, Number(entry?.count) || 1);
    const k = count == null ? n : Math.min(n, count);
    const r = call(api, ['removeEntry', 'removeStack'], entry, k);
    if (r.ok) { game.events?.emit?.('inventory', { reason: 'remove', itemIndex: entry?.itemIndex, count: k }); return r.v !== false; }
    const inv = game.save?.inventory || [];
    const i = inv.indexOf(entry) >= 0 ? inv.indexOf(entry) : inv.findIndex(e => e?.uid && e.uid === entry?.uid);
    if (i < 0) return false;
    if (k >= n) inv.splice(i, 1); else inv[i].count = n - k;
    game.events?.emit?.('inventory', { reason: 'remove', itemIndex: entry?.itemIndex, count: k });
    return true;
  },
  /** Find a bag entry by uid / reference. */
  find(game, ref) {
    const list = bag.entries(game);
    if (!ref) return null;
    if (list.includes(ref)) return ref;
    if (ref.uid) return list.find(e => e?.uid === ref.uid) || null;
    return null;
  },
};

/** Pay a list of [itemIndex, count] (items) atomically. Returns false (and takes nothing) when one is short. */
export function payItems(game, list) {
  for (const [i, c] of list) if (bag.count(game, i) < c) return false;
  for (const [i, c] of list) bag.remove(game, i, c);
  return true;
}

// ------------------------------------------------------------------------------------------ tooltips
// stringtable_color.txt white1 / cash / green1 / exceed; GREY (hints) has no colour in the data
const WHITE = '#ffffff', GOLD = '#ffcc00', GREEN = '#00ff00', RED = '#ff0000', GREY = '#b0b0b0';
/**
 * Item tooltip for the shop windows. Uses the items system's tooltip when it has one (the original item tooltip),
 * then appends the shop lines (price, need items).
 */
export function itemTooltip(game, idx, extraLines = [], entry = null, ctx = {}) {
  const it = itemInfo(game, idx);
  let base = null;
  const sys = itemsSys(game);
  if (sys && typeof sys.tooltip === 'function') { try { base = sys.tooltip(entry || Number(idx), { where: 'shop', ...ctx }); } catch { base = null; } }
  if (base && typeof Element !== 'undefined' && base instanceof Element) {
    // the original item tooltip of the items system + the shop lines
    for (const l0 of extraLines) {
      const l = typeof l0 === 'string' ? { text: l0, color: WHITE } : l0;
      if (!l?.text) continue;
      const d = document.createElement('div');
      d.textContent = String(l.text).replace(/<[^>]+>/g, '');
      d.style.color = l.color || WHITE;
      d.style.textAlign = 'center';
      base.appendChild(d);
    }
    return base;
  }
  const lines = [];
  if (base && Array.isArray(base.lines)) lines.push(...base.lines);
  else {
    lines.push({ text: it.name, color: GOLD, font: 4 });
    if (it.reqLv > 1) lines.push({ text: `Required Level ${it.reqLv}`, color: (game?.save?.level || 1) >= it.reqLv ? WHITE : RED });
    if (it.period > 0) lines.push({ text: `Duration: ${periodText(it.period)}`, color: GREEN });
    if (it.maxStack > 1) lines.push({ text: `Stack: ${it.maxStack}`, color: GREY });
    if (it.trade === 0) lines.push({ text: 'Cannot be traded', color: RED });
  }
  for (const l of extraLines) lines.push(typeof l === 'string' ? { text: l, color: WHITE } : l);
  return { lines, width: 260 };
}
export function periodText(sec) {
  sec = Number(sec) || 0;
  if (sec >= 86400) return `${Math.round(sec / 86400)} day(s)`;
  if (sec >= 3600) return `${Math.round(sec / 3600)} hour(s)`;
  if (sec >= 60) return `${Math.round(sec / 60)} minute(s)`;
  return `${sec} second(s)`;
}
export const COLORS = { WHITE, GOLD, GREEN, RED, GREY };

// ------------------------------------------------------------------------------------------ misc
export function clamp(v, a, b) { return Math.max(a, Math.min(b, v)); }
/** Pick from weighted entries: list of [weight, value]. */
export function weightedPick(list, rng = Math.random) {
  const total = list.reduce((s, [w]) => s + Math.max(0, Number(w) || 0), 0);
  if (!(total > 0)) return null;
  let r = rng() * total;
  for (const [w, v] of list) { r -= Math.max(0, Number(w) || 0); if (r < 0) return v; }
  return list[list.length - 1][1];
}
/** UI sound through the audio module (kinds of audio.ui: buttonCommon, buttonMain, boxOpen, boxClose, buy, sell...). */
export function uiSound(game, kind) { try { game?.audio?.ui?.(kind); } catch { /* optional */ } }
