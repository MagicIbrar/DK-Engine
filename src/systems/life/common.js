// Shared helpers of the life/social systems (src/systems/life): data, persistent state, client strings, system
// messages, the inventory adapter (works with whatever inventory system is installed, falling back to loot.js +
// save.inventory), item icons (the original 3D inventory models) and the chat-command registry.
import { fetchJSON } from '../../engine/assets.js';
import { currentAccountId } from '../../game/save.js';
import { renderItemIcon } from '../../ui/frontend/itemicon.js';

let DATA = null;
/** gamedata/life.json (tools/build-life.mjs). */
export function lifeData() {
  if (!DATA) DATA = fetchJSON('/gamedata/life.json').catch((err) => { console.error('[life] life.json failed', err); return null; });
  return DATA;
}
let REBIRTH = null;
export function rebirthData() {
  if (!REBIRTH) REBIRTH = fetchJSON('/gamedata/life_rebirth.json').catch(() => null);
  return REBIRTH;
}

// ------------------------------------------------------------------------------------------ persistent state
/** The character's life state (save.life, persisted with the character). */
export function state(game) {
  const s = game.save;
  if (!s.life || typeof s.life !== 'object') s.life = {};
  return s.life;
}
/** Account-wide state (localStorage): friends list, mail of other characters, attendance... */
const LS_ACCOUNT = 'dekaron-solo:life:account:v1';
export function account() {
  if (!account._v) { try { account._v = JSON.parse(localStorage.getItem(LS_ACCOUNT) || '{}') || {}; } catch { account._v = {}; } }
  return account._v;
}
export function saveAccount() { try { localStorage.setItem(LS_ACCOUNT, JSON.stringify(account._v || {})); } catch { /* private mode */ } }

/** Friends are local to the authenticated account/character and serving origin.
 * The shared-world API is same-origin; currentAccountId comes from validated
 * /api/characters saves, and self.id is the host's account:character identity.
 * Unscoped legacy names may migrate only into an ordinary solo character.
 */
export function friendRosterKey(game) {
  const id = game.save?.id;
  if (game.save?.authority === 'server' || game.network?.active) {
    const owner = currentAccountId(), origin = globalThis.location?.origin;
    return owner && id && origin ? 'v2:' + JSON.stringify(['online', origin, owner, id]) : null;
  }
  return 'v2:' + JSON.stringify(['solo', id || String(game.save?.name || game.player?.name || '').trim().toLowerCase()]);
}
export function friendRosterReady(game, network = game.network) {
  if (game.save?.authority !== 'server' && !network?.active) return true;
  const owner = currentAccountId(), id = game.save?.id, self = network?.self;
  return !!(friendRosterKey(game) && network?.active && network.ready && self?.characterId === id && self.profile?.id === id && self.id === owner + ':' + id);
}

// ------------------------------------------------------------------------------------------ strings / messages
/** Client string (script/string tables through the UI platform): str(game, 2900, 19) / str(game, 130, 0, 'SYSTEM'). */
export async function str(game, cate, code, group = 'NORMAL') {
  const S = game.uiwin?.strings;
  if (!S) return '';
  let v = null;
  try { v = S.resolve ? await S.resolve({ group, cate, code }) : (await S.need?.([{ group, cate, code }]), S.get?.({ group, cate, code })); } catch { v = null; }
  return v == null ? '' : String(v);
}
/** Sync lookup (after the table was loaded once). */
export function strNow(game, cate, code, group = 'NORMAL') {
  const S = game.uiwin?.strings;
  const v = S?.get?.({ group, cate, code });
  return v == null ? '' : String(v);
}
/** Strip the client's "[message]" prefix; returns {text, system}. */
export function cleanMsg(s) {
  const t = String(s || '');
  const m = /^\s*\[\s*message\s*\]\s*/i.exec(t);
  return { text: m ? t.slice(m[0].length) : t, system: !!m };
}
/** A chat/system log line. kind: 'sys' | 'err' | 'item' | 'exp' | 'chat'. */
export function msg(game, text, kind = 'sys') {
  // the chat log shows plain text: drop the client's markup tags (<color=..>, <center>, <font=..>) and "\" breaks
  const t = cleanMsg(text).text.replace(/<\/?(color|font|center|b)(=[^>]*)?>/gi, '').replace(/\\n|\\/g, ' ').replace(/\s*\n\s*/g, ' ').trim();
  try { game.hud?.log?.(t, kind); } catch { /* optional */ }
  game.events?.emit?.('life:message', { text: t, kind });
}
/** Unsupported solo mutations must stop even before a network adapter is installed or connected. */
export function rejectUnsupportedOnline(game, feature, quiet = false) {
  if (game.save?.authority !== 'server') return false;
  if (!quiet) msg(game, `${feature} is not available in multiplayer yet.`, 'err');
  return true;
}
/** Log a client string: msgRef(game, 130, 3, 'SYSTEM', 'err', ...printf args) */
export async function msgRef(game, cate, code, group = 'NORMAL', kind = 'sys', ...args) {
  let s = await str(game, cate, code, group);
  s = fmt(s, ...args);
  msg(game, s, kind);
  return s;
}
/** printf-ish fill (%d %s %1..%9) + named tokens <VALUE> <NAME> <COUNT>. */
export function fmt(s, ...args) {
  let i = 0;
  let out = String(s ?? '').replace(/%(\d)|%[-0-9.]*[dsfiu]/g, (m, n) => { const v = n ? args[+n - 1] : args[i++]; return v == null ? m : String(v); });
  if (args.length === 1 && args[0] && typeof args[0] === 'object') {
    out = out.replace(/<([A-Z_]+)>/g, (m, k) => (args[0][k] != null ? String(args[0][k]) : m));
  } else {
    let j = 0;
    out = out.replace(/<(VALUE|COUNT|NAME|NUM|TIME|LEVEL)>/g, (m) => { const v = args[j++]; return v == null ? m : String(v); });
  }
  return out;
}
/**
 * Client markup on a label: <color=RRGGBB>..</color> and \n through setRichText; <center> lines centre the label
 * (the client's rich-text <center> tag), <font=N> tags are dropped.
 */
export function setMarkup(ctrl, text) {
  if (!ctrl?.setRichText) return ctrl;
  let t = String(text ?? '').replace(/\\n/g, '\n');
  if (/<center>/i.test(t)) { t = t.replace(/<center>/gi, ''); ctrl.spec = { ...ctrl.spec, align: { h: 'center', v: ctrl.spec?.align?.v || 'top' } }; }
  t = t.replace(/<\/?font(=[^>]*)?>/gi, '').replace(/<\/?b>/gi, '');
  return ctrl.setRichText(t);
}

/** Original message box (modal). kind 'ok' | 'yesno'. Resolves 'yes'/'no'/'ok'/'cancel'. */
export function box(game, text, opts = {}) {
  return game.uiwin?.msgbox?.(text, opts) ?? Promise.resolve('ok');
}

// ------------------------------------------------------------------------------------------ items
let ITEMS = null;
/** Item info {name, w, h, inv, stack, type, code, value1, reqLv, ...} from life.json, or the installed item system. */
export function itemInfo(game, index) {
  const i = Number(index);
  let sys = null;
  try { sys = game.items?.def?.(i) || game.inventory?.def?.(i) || null; } catch { sys = null; }
  const own = ITEMS?.[i] || ITEMS?.[String(i)] || null;
  if (sys?.name) return own ? { ...own, ...sys, inv: own.inv } : sys;
  return own;
}
export function setItems(items) { ITEMS = items; }
export function itemName(game, index) { return itemInfo(game, index)?.name || `Item ${index}`; }

/** URL of the item's inventory model render (cached), sized w x h css px. */
export async function itemIcon(game, index, w = 32, h = 32) {
  const info = itemInfo(game, index);
  const inv = info?.inv || info?.visual?.inv;
  if (game.items?.icon) { try { const u = await game.items.icon(Number(index), w, h); if (u?.url) return u; } catch { /* fall back */ } }
  if (!inv) return null;
  try { const url = await renderItemIcon(game, inv, w, h); return url ? { url } : null; } catch { return null; }
}
export async function itemIconURL(game, index, w = 32, h = 32) { return (await itemIcon(game, index, w, h))?.url || null; }
/** Put an item icon on a uiwin control, retaining canonical descriptor lifetime. */
const itemIconRequests = new WeakMap();
export async function setItemIcon(game, control, index, count = 0, w, h) {
  if (!control) return;
  const request = {};
  itemIconRequests.set(control, request);
  if (!index) { control.setIcon?.(null); control.setCount?.(null); control.setTooltip?.(null); return; }
  const box = control.box || {};
  const iw = w || box.w || 32, ih = h || box.h || 32;
  const icon = await itemIcon(game, index, iw, ih);
  if (itemIconRequests.get(control) !== request) return;
  control.setIcon?.(icon || null);
  // the model render keeps the item's w x h cell footprint: centre it in the slot instead of stretching
  const el = control._icon;
  if (el && box.w && box.h && (iw < box.w || ih < box.h)) {
    Object.assign(el.style, { left: `${Math.round((box.w - iw) / 2)}px`, top: `${Math.round((box.h - ih) / 2)}px`, width: `${iw}px`, height: `${ih}px` });
  }
  control.setCount?.(count > 1 ? count : null);
  control.setTooltip?.(() => itemTooltip(game, index, count));
}
export function itemTooltip(game, index, count = 0) {
  if (game.items?.tooltip) { try { const t = game.items.tooltip(Number(index)); if (t) return t; } catch { /* fall back */ } }
  const it = itemInfo(game, index);
  if (!it) return `Item ${index}`;
  const lines = [{ text: it.name, color: 'ffffcc66', font: 3 }];
  if (count > 1) lines.push({ text: `x ${count}` });
  if (it.reqLv) lines.push({ text: `Required Level: ${it.reqLv}` });
  return { lines, width: 200 };
}

// ------------------------------------------------------------------------------------------ inventory adapter
// The items system (game.items: add/canAdd/count/remove) is used when installed; the
// fallback is loot.js's bag (save.inventory entries {uid, itemIndex, count, stack}).
function invList(game) { return game.save?.inventory || []; }
function invApi(game) { return (game.items && typeof game.items.count === 'function' && game.items.bag) ? game.items : (game.inventory || null); }
/** How many of an item the character carries. */
export function countItem(game, index) {
  const i = Number(index);
  const api = invApi(game);
  const fn = api?.count || api?.countItem;
  if (typeof fn === 'function') { try { const n = Number(fn.call(api, i)); if (Number.isFinite(n)) return n; } catch { /* fallback */ } }
  let n = 0;
  for (const e of invList(game)) if (e && Number(e.itemIndex ?? e.index) === i) n += Number(e.count) || 1;
  return n;
}
/** Remove count of an item; false (and nothing removed) when there are not enough. */
export function takeItem(game, index, count = 1) {
  const i = Number(index);
  if (countItem(game, i) < count) return false;
  const api = invApi(game);
  const fn = api?.remove || api?.removeItem || api?.take;
  if (typeof fn === 'function') {
    try { const r = fn.call(api, i, count); if (r !== false) { game.events?.emit?.('inventory', { removed: i, count }); return true; } return false; } catch { /* fallback */ }
  }
  const inv = invList(game);
  let left = count;
  for (let k = inv.length - 1; k >= 0 && left > 0; k--) {
    const e = inv[k];
    if (!e || Number(e.itemIndex ?? e.index) !== i) continue;
    const c = Number(e.count) || 1;
    if (c > left) { e.count = c - left; left = 0; } else { inv.splice(k, 1); left -= c; }
  }
  game.events?.emit?.('inventory', { removed: i, count });
  return left <= 0;
}
/** Can count of the item be added? */
export function canGive(game, index, count = 1) {
  const api = invApi(game);
  const fn = api?.canAdd || api?.canFit || api?.hasRoom;
  if (typeof fn === 'function') { try { const r = fn.call(api, Number(index), count); if (typeof r === 'boolean') return r; } catch { /* fallback */ } }
  const info = itemInfo(game, index);
  return game.loot?.canFit ? game.loot.canFit({ itemIndex: Number(index), count, name: info?.name, stack: !!(info?.stack > 1) }) : true;
}
/** Can every [index, count] of a list fit at once? */
export function canGiveAll(game, list) {
  const api = invApi(game);
  if (typeof api?.canAddAll === 'function') { try { return !!api.canAddAll(list); } catch { /* fallback */ } }
  return list.every(([i, c]) => canGive(game, i, c));
}
/** Add an item; returns true when it went into the bag. opts.silent: no loot log line. */
export function giveItem(game, index, count = 1, opts = {}) {
  const i = Number(index);
  const info = itemInfo(game, i);
  const name = info?.name || `Item ${i}`;
  let ok = false, viaApi = false;
  const api = invApi(game);
  const fn = api?.add || api?.addItem || api?.give;
  if (typeof fn === 'function') {
    viaApi = true;
    try {
      const r = fn.call(api, i, count, { source: opts.source || 'life', silent: true, period: opts.period, bound: opts.bound });
      ok = r === true || (r && typeof r === 'object' && (r.ok === true || (Array.isArray(r.placed) && r.placed.length > 0)));
    } catch { ok = false; viaApi = false; }
  }
  if (!ok && !viaApi && game.loot?.addItem) {
    if (!canGive(game, i, count)) return false;
    const e = game.loot.addItem({ itemIndex: i, name, count, stack: !!(info?.stack > 1), grade: 'normal' });
    ok = !!e;
  }
  if (ok) {
    if (!opts.silent) game.events?.emit?.('loot', { name, count, itemIndex: i, source: opts.source || 'life' });
    game.events?.emit?.('inventory', { added: i, count });
  }
  return ok;
}
/** Dil helpers. */
export function dil(game) { return Number(game.save?.dil) || 0; }
export function spendDil(game, n) {
  n = Math.max(0, Math.round(Number(n) || 0));
  if (dil(game) < n) return false;
  if (typeof game.items?.spendDil === 'function') { if (!game.items.spendDil(n)) return false; }
  else { game.save.dil = dil(game) - n; game.events?.emit?.('dil', { amount: -n, total: game.save.dil }); }
  game.events?.emit?.('stats');
  return true;
}
export function addDil(game, n) {
  if (typeof game.items?.addDil === 'function') game.items.addDil(Math.round(Number(n) || 0));
  else { game.save.dil = dil(game) + Math.round(Number(n) || 0); game.events?.emit?.('dil', { amount: n, total: game.save.dil }); }
  game.events?.emit?.('stats');
}
/** Item indexes of everything worn (equipment of the active preset, costumes included). */
export function wornItems(game) {
  const out = new Set();
  try { for (const e of game.items?.equip?.entries?.() || []) { const i = Number(e?.inst?.itemIndex ?? e?.itemIndex); if (i) out.add(i); } } catch { /* optional */ }
  const eq = game.save?.equipment || {};
  for (const e of Object.values(eq)) { const i = Number(e?.itemIndex ?? e?.index ?? (typeof e === 'number' ? e : 0)); if (i) out.add(i); }
  return out;
}
/** Item index of the equipped weapon (right hand), or 0. */
export function equippedWeapon(game) {
  try { const w = game.items?.equip?.get?.(4); if (w?.itemIndex) return Number(w.itemIndex); } catch { /* optional */ }
  const eq = game.save?.equipment || {};
  for (const k of ['weapon', 'rhand', 'right', 'mainhand', '0', 'weapon1']) {
    const e = eq[k];
    const idx = Number(e?.itemIndex ?? e?.index ?? (typeof e === 'number' ? e : 0));
    if (idx > 0) return idx;
  }
  const api = game.equipment || game.items;
  const w = api?.equipped?.('weapon');
  return Number(w?.itemIndex ?? w?.index ?? w) || 0;
}

// ------------------------------------------------------------------------------------------ chat commands
/** Register a chat handler fn(text) -> true when handled. Shared registry game.chatCommands (hud.js calls game.chatCommand). */
export function registerChat(game, fn) {
  if (!Array.isArray(game.chatCommands)) game.chatCommands = [];
  game.chatCommands.push(fn);
  if (!game._chatCommandWrapped) {
    const prev = typeof game.chatCommand === 'function' ? game.chatCommand : null;
    game.chatCommand = (text) => {
      for (const h of game.chatCommands) { try { if (h(text)) return true; } catch (err) { console.error('[chat]', err); } }
      return prev ? prev(text) : false;
    };
    game._chatCommandWrapped = true;
  }
}

// ------------------------------------------------------------------------------------------ monsters
/**
 * A one-off monster at a FILE point (event summons: the "Trace" reward pouches, quiz props): a spawner record
 * that never respawns. Returns the record ({monster} is filled when it has loaded).
 */
export function spawnMonster(game, monsterIndex, x, z) {
  const sp = game.spawner;
  if (!sp?.records) return null;
  const rec = { id: `life${Date.now().toString(36)}${Math.random().toString(36).slice(2, 5)}`, spawn: { monsterIndex: Number(monsterIndex), x, z, respawnSec: 1e9 },
    respawnSec: 1e9, monster: null, loading: false, deadAt: null, respawnAt: 0, failedUntil: 0, skip: false, oneShot: true };
  sp.records.push(rec);
  sp._scan = 0;
  return rec;
}

// ------------------------------------------------------------------------------------------ misc
export const rand = (a, b) => a + Math.random() * (b - a);
export const randInt = (a, b) => Math.floor(a + Math.random() * (b - a + 1));
/** Weighted pick from [[value, weight], ...]. */
export function weighted(list, total = null) {
  const sum = total ?? list.reduce((s, x) => s + (Number(x[1]) || 0), 0);
  let r = Math.random() * sum;
  for (const x of list) { r -= Number(x[1]) || 0; if (r < 0) return x; }
  return null;
}
/** "HH:MM:SS" / "MM:SS" */
export function clockText(sec) {
  sec = Math.max(0, Math.floor(sec));
  const h = Math.floor(sec / 3600), m = Math.floor((sec % 3600) / 60), s = sec % 60;
  const p = (n) => String(n).padStart(2, '0');
  return h ? `${p(h)}:${p(m)}:${p(s)}` : `${p(m)}:${p(s)}`;
}
export function numText(n) { return Number(n || 0).toLocaleString('en-US'); }
/** Local calendar day key (YYYYMMDD) for daily resets. */
export function dayKey(d = new Date()) { return d.getFullYear() * 10000 + (d.getMonth() + 1) * 100 + d.getDate(); }
