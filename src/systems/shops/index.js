// Shops system: every trading window of the original client.
//   NPC stores (buy / sell / repurchase), exchange center, exchange store, material exchange, supply machines
//   (Orbis of Destiny, field-boss roulette, multi machine), the D-Shop (unlimited coins) with its cart, preview,
//   box info and probability windows, the Cash Inventory, the VIP (mileage) shop, premium services and the
//   Middleman's store search / consignment.
// Public API: game.shops (see the bottom of install()). NPC jobs are served through game.npcServices when the NPC
// dialog system provides it, else through the legacy windows.js dialog.
import { fetchJSON } from '../../engine/assets.js';
import { T, loadShops, loadDshop, bag, itemInfo, str, notice } from './common.js';
import { createDialogs } from './dialogs.js';
import { createStore, unpricedPolicy } from './store.js';
import { createExchanges } from './exchange.js';
import { createCashInventory } from './cashinven.js';
import { createCashShops, createBoxInfo, createVipBoxInfo, createProbability, UNLIMITED } from './dshop.js';
import { createPremium } from './premium.js';
import { createSupply } from './supply.js';
import { createSearch } from './search.js';
import { createCoinShops } from './coin-shops.js';

/** NPC job types served here (npcs.json jobTypes). */
export const JOBS = {
  0: 'SHOP', 33: 'SIEGE_SHOP', 43: 'SUPPLY_SHOP', 51: 'ARENA_SHOP', 83: 'EXCHANGE_SHOP', 102: 'MULTISHOP',
  35: 'EXCHANGE', 166: 'EXCHANGE_STORE', 168: 'EXCHANGE_MATERIAL', 101: 'SUPPLYMACHINE_GAMBLER', 46: 'SEARCH_STORE',
  164: 'EXCHANGE_RANKUP_EXP_COIN', 165: 'EXCHANGE_GOLDITEM',
};
const STORE_JOBS = new Set([0, 33, 43, 51, 83, 102]);

let API = null;

export async function install(game) {
  if (!game.uiwin) { console.warn('[shops] no UI platform'); return; }
  await loadShops();
  const api = { game, T };
  API = api;
  api.windows = createDialogs(game);
  /** The bag entry carried by a drag payload of the inventory (any of the usual shapes), or null. */
  api.bagEntryOf = (data) => {
    if (!data || data.from === 'shop' || data.kind === 'shopItem' || data.kind === 'shopRebuy') return null;
    if (data.from && data.from !== 'bag' && data.from !== 'inventory') return null;   // only bag items are sold / registered
    const cands = [data.inst, data.entry, data.item, data.bagEntry, data];
    for (const c of cands) if (c && typeof c === 'object' && c.itemIndex != null) { const e = bag.find(game, c) || (bag.entries(game).includes(c) ? c : null); if (e) return e; }
    return null;
  };
  api.store = createStore(game, api);
  const ex = createExchanges(game, api);
  Object.assign(api, ex);
  api.cash = createCashInventory(game, api);
  api.boxInfo = createBoxInfo(game);
  api.vipBoxInfo = createVipBoxInfo(game, api.boxInfo);
  api.probability = createProbability(game);
  const cs = createCashShops(game, api);
  api.dshop = cs.dshop;
  api.vip = cs.vip;
  api.premium = createPremium(game, api);
  api.supply = createSupply(game, api);
  api.search = createSearch(game, api);
  api.coinShops = createCoinShops(game, api);

  // ------------------------------------------------------------------------------------------ NPC jobs
  api.handleJob = (npc, job) => {
    const jt = Number(job?.jobType), ji = Number(job?.jobIndex);
    const npcIndex = npc?.def?.index ?? npc?.npcIndex ?? npc?.index ?? job?.npcIndex;
    if (STORE_JOBS.has(jt)) { api.store.open(ji, npc); return true; }
    switch (jt) {
      case 35: api.openExchange(ji, npc); return true;
      case 166: api.openExchangeStore(ji, npc, npcIndex); return true;
      case 168: api.openMaterial(ji, npc); return true;
      case 101: api.supply.openOrbis(); return true;
      case 46: api.search.open(npc); return true;
      // COIN-SHOPS: 164 EXCHANGE_RANKUP_EXP_COIN -> Rankup / Exp Coin windows, 165 EXCHANGE_GOLDITEM -> Sell / Buy currency
      // windows (coin-shops.js; the first tab of each pair is an engine choice in coin-shops-config.js)
      case 164: case 165: api.coinShops.openJob(jt, npc); return true;
      default: return false;
    }
  };
  /** Menu line of a job in the NPC dialog (MULTISHOP lines are the shop names, stringtable_store 341). */
  api.jobLabel = (npcIndex, jobType, jobIndex) => {
    const j = T.shops?.npcs?.[npcIndex]?.jobs?.find(x => Number(x.jobType) === Number(jobType) && Number(x.jobIndex) === Number(jobIndex));
    if (j?.label) return j.label;
    if (Number(jobType) === 102) return str(game, 341, Number(jobIndex), T.shops?.shops?.[jobIndex]?.name || '');
    return null;
  };
  registerNpcServices(game, api);
  labelDialogJobs();

  // ------------------------------------------------------------------------------------------ item use hooks
  // premium-service items start their service when used from any inventory path (loot.useItem is what the bag,
  // the hotbar and the items system call)
  const loot = game.loot;
  if (loot?.useItem && !loot.useItem._shopsWrapped) {
    const base = loot.useItem.bind(loot);
    const wrapped = (ref) => {
      const e = loot._findEntry?.(ref);
      // online the server uses the item and starts the service (server/world/items.mjs), never this client path
      if (e && !game.network?.active && api.premium.isPremium(e.itemIndex)) {
        api.premium.activate(e.itemIndex).then(ok => { if (ok) bag.removeEntry(game, e, 1); });
        return true;
      }
      return base(ref);
    };
    wrapped._shopsWrapped = true;
    loot.useItem = wrapped;
  }
  // the items system consumes premiere items itself (items/use.js: save.premiere + its status) and then emits
  // 'itemuse': the premium service (EXP rate, teleport / return lists, remote store, Holy Water menu) starts here
  game.events?.on?.('itemuse', ({ def } = {}) => {
    const idx = Number(def?.index);
    if (def?.use?.premiere != null && api.premium.isPremium(idx)) api.premium.activate(idx, { external: true });
  });
  // the Almighty premium item is a box for the items system (itemchange_randombox): the boxes system (quests) opens
  // it; it may only be used outside an active service or in its renewal window, and then starts the service
  const wrapBoxes = () => {
    const B = game.boxes;
    if (!B?.open || B.open._shops) return;
    const base = B.open.bind(B);
    const wrapped = async (instOrIndex, ...rest) => {
      const idx = Number(typeof instOrIndex === 'object' ? instOrIndex?.itemIndex : instOrIndex);
      if (!api.premium.isAlmightyItem(idx)) return base(instOrIndex, ...rest);
      await loadDshop();
      if (!api.premium.canActivate(idx)) { await api.premium.activate(idx); return false; }   // the renewal notice
      const ok = await base(instOrIndex, ...rest);
      if (ok) await api.premium.activate(idx, { external: true });
      return ok;
    };
    wrapped._shops = true;
    B.open = wrapped;
  };
  wrapBoxes();
  game.events?.on?.('systems', wrapBoxes);
  // Prepare each shop's first visible page before play; retain real art for later opens.
  const iconsReady = Promise.all([api.store, api.dshop, api.vip].map(shop =>
    shop.prewarm().catch(error => console.warn('[shops] icon preparation', error))));
  (game._interfaceIconTasks ||= []).push(iconsReady);

  // ------------------------------------------------------------------------------------------ public API
  game.shops = {
    api,
    /** Open an NPC store (shop index); npc = actor (null = remote store). */
    openStore: (shop, npc = null, remote = false) => api.store.open(shop, npc, remote),
    openExchange: (i, npc = null) => api.openExchange(i, npc),
    openExchangeStore: (i, npc = null, npcIndex = null) => api.openExchangeStore(i, npc, npcIndex),
    openMaterial: (i, npc = null) => api.openMaterial(i, npc),
    /** COIN-SHOPS: 'rankup' | 'expup' | 'sale' | 'purchase'. */
    openCoinShop: (kind, npc = null) => api.coinShops.open(kind, npc),
    openDshop: (arg) => api.dshop.open(arg),
    openVipShop: (arg) => api.vip.open(arg),
    openCashInventory: () => api.cash.open(),
    openOrbis: () => api.supply.openOrbis(),
    openFieldBossRoulette: () => api.supply.openFieldBoss(),
    openSupplyMachine: () => api.supply.openMachine(),
    openStoreSearch: (npc = null) => api.search.open(npc),
    openProbability: () => api.probability.open(),
    /** Contents of a box / package in the D-Shop box info window; {select:true} resolves the chosen entries. */
    showBoxInfo: (itemIndex, opts) => api.boxInfo.show(itemIndex, opts),
    handleJob: (npc, job) => api.handleJob(npc, job),
    jobLabel: (npcIndex, jobType, jobIndex) => api.jobLabel(npcIndex, jobType, jobIndex),
    /** Sell a bag entry to the open store (the bag calls this on right-click while a store is open). */
    sellFromBag: (entry, opts) => api.store.sellEntry(entry, opts),
    /** items system hook: right-click on a bag item while the 'shop' window is open. */
    sell: (inst) => api.store.sellEntry(inst, { confirm: true }),
    get storeOpen() { return api.store.isOpen; },
    /** The bag calls this on right-click: sells when a store is open. Returns true when it handled the click. */
    onBagRightClick: (entry) => { if (!api.store.isOpen) return false; api.store.sellEntry(entry, { confirm: true }); return true; },
    sellQuote: (entry) => api.store.sellQuote(entry),
    cashInventory: api.cash,
    premium: api.premium,
    unpricedPolicy,
    dshopBalance: UNLIMITED,
    itemInfo: (i) => itemInfo(game, i),
  };
  game.premium ||= api.premium;
  game.cashInventory ||= api.cash;
}

/**
 * The NPC dialog lists a MULTISHOP NPC's shops by name ("[Weapon Shop] Azure Knight", stringtable_store 341; Nicole
 * alone has 15): the dialog table (dialogs.json, shared through the fetchJSON cache) carries no label for those jobs,
 * so the shop labels of shops.json are filled in where a job has none (additive; existing labels are kept).
 */
async function labelDialogJobs() {
  try {
    const D = await fetchJSON('/gamedata/dialogs.json');
    const npcs = D?.npcs || {};
    for (const [n, s] of Object.entries(T.shops?.npcs || {})) {
      const d = npcs[n];
      if (!d?.jobs) continue;
      for (const j of d.jobs) {
        if (!Array.isArray(j) || (j[2] != null && j[2] !== '')) continue;
        const m = s.jobs.find(x => Number(x.jobType) === Number(j[0]) && Number(x.jobIndex) === Number(j[1]));
        if (m?.label) j[2] = m.label;
      }
    }
  } catch (err) { console.warn('[shops] dialog labels', err); }
}

/** Serve the NPC jobs: game.npcServices (NPC dialog system) when present, else the legacy windows.js dialog. */
function registerNpcServices(game, api) {
  const handler = (npc, job) => api.handleJob(npc, job);
  const reg = () => {
    const ns = game.npcServices;
    if (ns?.register) {
      if (ns._shopsRegistered === ns) return true;
      for (const jt of Object.keys(JOBS)) ns.register(Number(jt), handler);
      if (typeof ns.registerLabel === 'function') for (const jt of Object.keys(JOBS)) ns.registerLabel(Number(jt), (npc, job) => api.jobLabel(npc?.def?.index ?? npc?.index, job.jobType, job.jobIndex));
      ns._shopsRegistered = ns;
      return true;
    }
    return false;
  };
  reg();
  game.events?.on?.('systems', () => reg());
  game.events?.on?.('npcservices', () => reg());
  // legacy dialog (windows.js): its option handler learns our roles
  const w = game.windows;
  if (w && typeof w._npcOption === 'function' && !w._npcOption._shops) {
    const base = w._npcOption.bind(w);
    const wrapped = (o) => {
      const npc = w._npc?.npc || null;
      if (o && JOBS[Number(o.jobType)] != null && api.handleJob(npc, o)) { w.close?.('npc'); return; }
      return base(o);
    };
    wrapped._shops = true;
    w._npcOption = wrapped;
  }
}

export function update(dt, game) {
  API?.premium?.update?.(dt);
}

export function dispose() { API = null; }
