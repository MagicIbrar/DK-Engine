// The NPC store: script/ui/game2/store/ui_storewnd.txt (345x471, store_npc_normal#1; repurchase page store_npc_rebuy#1).
//
//  * up to 5 tabs (btn_tab0..4, captions stringtable_storetab cate 2002 = shops.json tabs[].name)
//  * the item grid slotitemlist (33 px cells, 10 columns): sets[set].items [item, stack, x, y] drawn at their cell with
//    the item's inventory model spanning w x h cells
//  * left-click / drag opens the native quantity or confirmation dialog; right-click buys one authored sale unit.
//    A sale unit is max(1, StockCount), not the bag stack capacity. Native exchange-priced items are one at a time
//    (msgbox/ui_buyexchangeitem.txt, 170/9). Input choice is the user-requested engine behavior.
//  * selling: drop a bag item on the window (confirm msgbox/ui_sellitem.txt 340/11); refusals 340/7, 8, 20, 31
//  * repurchase (btn_rebuy / btn_shop): the session's sold items on the store_npc_rebuy page, bought back at the sell
//    price; Max 10 (guide stringtable_helper Shop Trade Repurchase; oldest dropped from top). UI grid is 10x8 layout.
//    Cleared on logout / character select (guide Caution; client notice cate 340).
import {
  T, loadShops, itemInfo, itemInfoFull, itemIcon, itemTooltip, bag, dil, addDil, MAX_DIL, payItems, maxStackOf,
  str, say, notice, fmtNum, COLORS, uiSound, loadItemDB, itemsSys, cleanMarkup,
} from './common.js';
import { dilColor } from '../../ui/item-colors.js';
import { globalConfirm } from '../../ui/uiwin/global-windows.js';
import { ShopPageAssets } from './page-assets.js';
import { retainShopBitmap } from './shop-bitmaps.js';
import { storeEntryPlan, storeCatalogKeys } from './store-entry-plan.js';

const SCRIPT = 'game2/store/ui_storewnd.txt';
const CELL = 33, COLS = 10, ROWS = 10;
const REBUY_COLS = 10, REBUY_ROWS = 8, REBUY_ORIGIN = [8, 37];   // measured on store_4.dds (store_npc_rebuy#1)
const GRID_ORIGIN = [8, 66];
const MSG = (game, code, fb) => str(game, 340, code, T.shops?.messages?.store?.[code] ?? fb ?? '');
const CLOSE_DISTANCE = 6.2;  // match the host's nearby-NPC shop reach (FILE units)

/** Solo policy for slots the client ships without a price (docs/formats/shops.md 3.1-4). */
export const unpricedPolicy = { mode: 'free', dil: 0 };   // mode 'free' | 'dil' (flat price per unit)

/** Sell grade key of sellPriceTable from a bag entry. */
function gradeKey(entry, it) {
  const g = String(entry?.grade || '').toLowerCase();
  const nOpt = Array.isArray(entry?.options) ? entry.options.length : 0;
  if (g === 'legend' || g === 'legendary') return 'LEGEND';
  if (g === 'divine') return 'DIVINE';
  if (g === 'noble' || g === 'norble') return 'NORBLE';
  if (g === 'magic') return nOpt >= 2 ? 'MAGIC2' : 'MAGIC1';
  if (g === 'magic2') return 'MAGIC2';
  if (g === 'magic1') return 'MAGIC1';
  return 'NORMAL';
}

export function createStore(game, api) {
  const st = {
    win: null, shopIndex: -1, shop: null, tab: 0, mode: 'shop', npc: null, remote: false, tok: 0,
    buying: false, iconScope: null,
    rebuy: [],           // [{itemIndex, count, price, entry, x, y, w, h}] (session only)
  };
  // ENGINE-CHOSEN bounded preparations/retries; closing/changing tabs cancels queued obsolete work.
  const decodedImages = new WeakMap();
  // mode: 'foreground' | 'background' (prefetch bake) | 'disk' (ICON-PRELOAD: memory / persistent icon cache only, no bake)
  const prepareKey = async (key, mode = 'foreground') => {
    const [index, w, h] = key.split(':').map(Number);
    const icons = game.items?.icons;
    const request = () => itemIcon(game, index, w, h);
    const rendered = await (mode === 'disk' && icons?.diskOnly ? icons.diskOnly(request) : mode === 'background' && icons?.background ? icons.background(request) : request());
    if (!rendered?.url) return null;
    const icon = await retainShopBitmap(rendered);
    if (!icon?.url) return null;
    if (typeof Image === 'function') {
      const image = new Image(); image.src = icon.url;
      if (typeof image.decode === 'function') await image.decode();
      decodedImages.set(icon, image);
    }
    return icon;
  };
  const newAssets = () => new ShopPageAssets((key, {background = false} = {}) => prepareKey(key, background ? 'background' : 'foreground'),
    { concurrency: 2, limit: COLS * ROWS, paused: () => game._loadingMap || !game._worldReady });
  let assets = newAssets(), catalogGeneration = game.items?.icons?.cache?.generation;
  let backgroundPool = null, backgroundTimer = null, disposed = false;
  const warmJobs = new Map();
  function syncAssets() {
    const next = game.items?.icons?.cache?.generation;
    if (next !== catalogGeneration) {
      catalogGeneration = next; assets.dispose(); assets = newAssets(); warmJobs.clear();
    }
    return assets;
  }
  const entryMap = () => game.world?.info?.index ?? game.network?.self?.map ?? game.save?.map ?? game.data?.startFor?.(game.save?.classIndex)?.mapIndex;
  function prepareOtherPages(pool) {
    if (disposed || backgroundPool === pool) return;
    backgroundPool = pool;
    const keys = storeCatalogKeys(T.shops, index => itemInfo(game, index));
    pool.limit = Math.max(pool.limit, keys.length + COLS * ROWS);
    let cursor = 0;
    const next = async () => {
      backgroundTimer = null;
      if (disposed || pool !== assets) return;
      if (game._loadingMap || !game._worldReady) { backgroundTimer = setTimeout(next, 250); return; }
      while (cursor < keys.length && pool.now(keys[cursor])) cursor++;
      if (cursor >= keys.length) return;
      // One background request at a time; visible requests keep their foreground
      // priority. The existing preview scheduler yields the bake work as well.
      await pool.get(keys[cursor++], {priority: 1});
      if (!disposed && pool === assets) backgroundTimer = setTimeout(next, 32);
    };
    backgroundTimer = setTimeout(next, 250);
  }
  // ICON-PRELOAD (2026-10-30): every NPC store catalogue icon already baked in an earlier session (persistent icon
  // cache, icons/icon-disk-cache.js) is loaded behind the loading screen, so any store / tab / page opens complete.
  // Icons not on disk yet keep the one-at-a-time idle bake after the world is shown (prepareOtherPages), which also
  // persists them for the next start. Kill switch: globalThis.__dekaronNoShopDiskWarm = true
  let diskWarmPool = null;
  async function warmCatalogFromDisk(pool) {
    const icons = game.items?.icons;
    if (diskWarmPool === pool || !icons?.diskOnly || globalThis.__dekaronNoShopDiskWarm === true) return null;
    diskWarmPool = pool;
    const t0 = performance.now();
    const keys = storeCatalogKeys(T.shops, index => itemInfo(game, index));
    pool.limit = Math.max(pool.limit, keys.length + COLS * ROWS);
    const todo = keys.filter(key => !pool.now(key));
    let cursor = 0, loaded = 0;
    const worker = async () => {
      while (cursor < todo.length && pool === assets && !disposed) {
        const key = todo[cursor++];
        try { const icon = await prepareKey(key, 'disk'); if (icon && pool === assets && !pool.now(key)) { pool.cache.set(key, icon); loaded++; } } catch { /* stays for the idle bake */ }
      }
    };
    await Promise.all(Array.from({length: 8}, worker));
    return game._shopDiskWarm = {keys: keys.length, fromDisk: loaded, missing: todo.length - loaded, ms: Math.round(performance.now() - t0)};
  }
  async function prewarm(map = entryMap()) {
    await loadItemDB(game);
    const plan = storeEntryPlan({map, npcs: game.data?.npcs, shops: T.shops,
      placements: Number(game.world?.info?.index) === Number(map) ? game.world?.npcPlacements : undefined,
      itemInfo: index => itemInfo(game, index),
      remoteShops: (api.premium?.active?.() || []).map(service => service.fields?.storeIndex)});
    const pool = syncAssets(), key = JSON.stringify([catalogGeneration, plan.map, plan.shopIds, plan.keys]);
    if (warmJobs.has(key)) return warmJobs.get(key);
    // Retain this map's complete first pages, leaving room for one newly opened
    // tab. Other maps/tabs remain demand-driven and reuse these static images.
    pool.limit = Math.max(pool.limit, plan.keys.length + COLS * ROWS);
    const progress = game._shopIconWarmup = {done: 0, total: plan.keys.length, map: plan.map, shops: plan.shopIds, failed: []};
    game._shopIconProgress?.(progress.done, progress.total);
    const job = Promise.all(plan.keys.map(async iconKey => {
      const icon = await pool.get(iconKey, {priority: 0});
      if (!icon?.url) progress.failed.push(iconKey);
      progress.done++; game._shopIconProgress?.(progress.done, progress.total);
    })).then(() => warmCatalogFromDisk(pool).catch(() => null)).then(() => {
      // A genuinely missing optional native thumbnail keeps the existing
      // visible retry/fallback path; it cannot permanently strand map entry.
      if (progress.failed.length) console.warn('[shops] missing entry images', progress.failed);
      prepareOtherPages(pool);
      return {icons: plan.keys.length, map: plan.map, shops: plan.shopIds, failed: progress.failed};
    }).finally(() => {
      if (warmJobs.get(key) === job) warmJobs.delete(key);
    });
    warmJobs.set(key, job);
    return job;
  }
  // The authoritative arrival can differ from the saved selection map. The map
  // event precedes finishInterfaceWarmup, so its exact pages join that barrier.
  game.events?.on?.('map', ({index} = {}) => {
    const ready = prewarm(index).catch(error => console.warn('[shops] icon preparation', error));
    (game._interfaceIconTasks ||= []).push(ready);
  });
  // The NPC of an online shop request; null for the Holy Water remote store (the server allows it only for a running StoreIndex service)
  const shopNpcIndex = () => (st.remote || !st.npc ? null : Number(st.npc.npcIndex ?? st.npc.def?.index ?? st.npc.index));

  // ---------------------------------------------------------------------------------------------- prices
  /** The price of one unit of a set slot: {kind:'items'|'points'|'dil'|'free', items?, points?, dil?} */
  function priceOf(shop, tab, itemIndex) {
    const set = T.shops.sets[tab.set] || {};
    const costs = set.costs?.[itemIndex];
    if (costs && costs.length) return { kind: 'items', items: costs.map(([i, c]) => [Number(i), Number(c)]) };
    const it = itemInfo(game, itemIndex);
    if (shop.kind === 'ARENA_SHOP' && Number(it.purchasePoint) > 0) return { kind: 'points', points: Number(it.purchasePoint) };
    if (Number(it.price) > 0) return { kind: 'dil', dil: Math.floor(Number(it.price) * (Number(tab.buyRatio) || 10) / 10) };
    if (unpricedPolicy.mode === 'dil' && unpricedPolicy.dil > 0) return { kind: 'dil', dil: unpricedPolicy.dil, unpriced: true };
    return { kind: 'free', unpriced: true };
  }
  /** What an NPC pays for a bag entry (0 = cannot be sold); refusal code of cate 340 when it cannot. */
  function sellQuote(entry) {
    const it = itemInfo(game, entry.itemIndex);
    if (entry.expires || entry.expiresAt || Number(it.period) > 0) return { price: 0, refuse: 8 };
    if (Number(it.type) === 6 && /sentry|siege/i.test(it.name || '')) return { price: 0, refuse: 20 };
    if (it.npcSell === 0 || entry.bound === 'nosell') return { price: 0, refuse: 31 };
    const shop = st.shop || T.shops?.shops?.[5] || { sellRatio: 3, maxSellCost: 500000 };
    const count = Math.max(1, Number(entry.count) || 1);
    const sys = itemsSys(game);
    if (sys?.sellPrice) {
      // the items system's rule (items.md 6.8), same tables
      const price = Math.min(Number(sys.sellPrice(entry, shop)) || 0, Math.max(Number(shop.maxSellCost) || 500000, Number(it.sell) * count || 0));
      return { price, unit: Math.floor(price / count), refuse: price > 0 ? 0 : 31 };
    }
    let unit;
    if (Number(it.sell) > 0) unit = Number(it.sell);
    else {
      const sockets = Math.min(4, Array.isArray(entry.sockets) ? entry.sockets.filter(Boolean).length : Number(entry.sockets) || 0);
      const pct = T.shops?.sellPriceTable?.[sockets]?.[gradeKey(entry, it)] ?? 100;
      unit = Math.floor(Number(it.price || 0) * (Number(shop.sellRatio) || 3) / 10 * pct / 100);
    }
    const price = Math.min(unit * count, Number(shop.maxSellCost) || 500000);
    return { price, unit, refuse: price > 0 ? 0 : (Number(it.price) > 0 ? 0 : 31) };
  }

  // ---------------------------------------------------------------------------------------------- window
  game.uiwin.registerWindow('shop', {   // the name the items system checks (bag right-click sells while 'shop' is open)
    script: SCRIPT,
    create(win) {
      st.win = win;
      for (let i = 0; i < 5; i++) win.control(`btn_tab${i}`).onClick(() => { if (st.mode === 'shop') { st.tab = i; render(); } });
      win.control('btn_rebuy').onClick(() => setMode('rebuy'));
      win.control('btn_shop').onClick(() => setMode('shop'));
      const grid = win.control('slotitemlist');
      grid.setRect(GRID_ORIGIN[0], GRID_ORIGIN[1], COLS * CELL, 358);
      grid.setItemTooltip(it => tooltipFor(it));
      grid.on('cellrclick', (cell, item) => {
        if (!item) return;
        if (st.mode === 'rebuy') { notice(game, MSG(game, 30)); return; }
        void buySlot(item.data, 1);
      });
      grid.on('cellclick', (cell, item) => { if (item) void (st.mode === 'rebuy' ? repurchase(item.data) : buySlot(item.data)); });
      grid.makeDraggable((e) => {
        const c = grid.cellAt(e.clientX, e.clientY);
        const item = c && grid.itemAt(c.x, c.y);
        if (!item) return null;
        const d = item.data;
        return {
          data: { from: 'shop', kind: st.mode === 'rebuy' ? 'shopRebuy' : 'shopItem', itemIndex: d.itemIndex, count: d.count || 1,
            /** the bag calls data.buy() when the shop item is dropped on it */
            buy: () => (st.mode === 'rebuy' ? repurchase(d) : buySlot(d)) },
          icon: item.icon, size: [(item.w || 1) * CELL, (item.h || 1) * CELL],
        };
      }, { clickPick: false });
      const acceptSell = {
        referenceSource:'bag',referenceLabel:'NPC shop selling',
        accept: (data) => st.mode === 'shop' ? !!api.bagEntryOf(data) : true,
        drop: (data) => {
          const entry = api.bagEntryOf(data);
          if (!entry) return false;
          if (st.mode === 'rebuy') { notice(game, MSG(game, 21)); return false; }
          sellEntry(entry, { confirm: true });
          return true;
        },
      };
      grid.acceptDrop(acceptSell);
      win.control('pan_store').acceptDrop(acceptSell);
      win.control('lbl_Infomation').setRichText(cleanMarkup(MSG(game, 29)));
    },
    onOpen(win, arg) {
      st.tok++;
      st.shopIndex = Number(arg?.shop);
      st.shop = T.shops?.shops?.[st.shopIndex] || null;
      st.npc = arg?.npc || null;
      if(game.save?.authority==='server'){st.rebuy=(game.save.shopRebuy||[]).filter(row=>row.shop===st.shopIndex).map(row=>({...row,itemIndex:row.entry.itemIndex,count:row.entry.count}));packRebuy();}
      st.remote = !!arg?.remote;
      st.tab = 0;
      if (!st.shop) { win.close(); notice(game, MSG(game, 3, 'Cannot open the shop.')); return; }
      if (st.npc && !st.remote && game.player && Math.hypot(game.player.x - st.npc.x, game.player.z - st.npc.z) > CLOSE_DISTANCE) {
        win.close('distance'); notice(game, 'Move closer to the shop NPC.'); return;
      }
      const name = str(game, 341, st.shopIndex, st.shop.name || '') || st.shop.name;
      win.control('lbl_title').setText(name || str(game, 2001, 57, 'Shop'));
      setMode('shop');
      // item data for the sell prices of the bag (full database) in the background
      void loadItemDB(game).catch(error => say(game, error.message, 'err'));
    },
    onClose() { st.iconScope?.abort(); st.iconScope = null; st.tok++; game.uiwin?.tooltips?.hide?.(); game.events?.emit?.('shop:close', { shop: st.shopIndex }); },
    update(win) {
      if (!st.npc || st.remote) return;
      const p = game.player;
      if (p && Math.hypot(p.x - st.npc.x, p.z - st.npc.z) > CLOSE_DISTANCE) win.close('distance');
    },
  });

  function setMode(mode) {
    const w = st.win;
    if (!w) return;
    st.mode = mode;
    const rebuy = mode === 'rebuy';
    w.control('pan_store').setImage('none', 'store_npc_' + (rebuy ? 'rebuy' : 'normal'), 1);
    w.control('btn_rebuy').setVisible(!rebuy);
    w.control('btn_shop').setVisible(rebuy);
    w.control('lbl_Infomation').setVisible(rebuy);
    const grid = w.control('slotitemlist');
    if (rebuy) grid.setRect(REBUY_ORIGIN[0], REBUY_ORIGIN[1], REBUY_COLS * CELL, REBUY_ROWS * CELL);
    else grid.setRect(GRID_ORIGIN[0], GRID_ORIGIN[1], COLS * CELL, 358);
    if (rebuy) {
      // the caution text sits under the 8 grid rows
      w.control('lbl_Infomation').setRect(15, REBUY_ORIGIN[1] + REBUY_ROWS * CELL + 12, 321, 110);
    }
    render();
  }

  function render() {
    const w = st.win;
    if (!w || !st.shop) return;
    syncAssets();
    const tok = ++st.tok;
    const tabs = st.shop.tabs || [];
    for (let i = 0; i < 5; i++) {
      const b = w.control(`btn_tab${i}`);
      const t = tabs[i];
      b.setVisible(!!t && st.mode === 'shop');
      if (t) { b.setText(str(game, 2002, t.nameCode, t.name) || t.name); b.setChecked(i === st.tab); }
    }
    const grid = w.control('slotitemlist');
    const items = st.mode === 'rebuy' ? rebuyItems() : shopItems(tabs[st.tab]);
    // Paint retained art in the first layout, not in a later promise callback.
    for (const it of items) it.icon = assets.now(`${it.data.itemIndex}:${it.w * CELL}:${it.h * CELL}`) || game.items?.icons?.cached?.(it.data.itemIndex) || null;
    grid.setItems(items);
    st.iconScope?.abort();
    const scope = st.iconScope = new AbortController();
    const current = () => tok === st.tok && st.win?.isOpen && !scope.signal.aborted;
    let queued = false;
    const repaint = () => { if (queued) return; queued = true; requestAnimationFrame(() => { queued = false; if (current()) grid.setItems(items); }); };
    const prepareIcon = it => {
      const key = `${it.data.itemIndex}:${it.w * CELL}:${it.h * CELL}`;
      const ready = assets.now(key);
      if (ready) { it.icon = ready; return; }
      void assets.visible(key, { signal: scope.signal, owner: it, isVisible: current,
        onReady(ic) { it.icon = ic; repaint(); } });
    };
    // Text, stock and click targets are usable immediately, independently of icon preparation.
    for (const it of items) prepareIcon(it);
    Promise.all(items.map(it => itemInfoFull(game, it.data.itemIndex))).then(() => {
      if (!current()) return;
      let changed = false;
      for (const it of items) {
        const inf = itemInfo(game, it.data.itemIndex);
        if (inf.w !== it.w || inf.h !== it.h) {
          it.w = inf.w || 1; it.h = inf.h || 1; changed = true; prepareIcon(it);
        }
        // Initial metadata may arrive before the full item DB; refresh the actual purchase price too.
        if (st.mode === 'shop') it.data.price = priceOf(st.shop, it.data.tab, it.data.itemIndex);
      }
      if (changed) grid.setItems(items);
    }).catch(() => {});
  }

  function shopItems(tab) {
    if (!tab) return [];
    const set = T.shops.sets[tab.set];
    if (!set) return [];
    return set.items.map(([itemIndex, stack, x, y]) => {
      const inf = itemInfo(game, itemIndex);
      return {
        x, y, w: inf.w || 1, h: inf.h || 1, icon: null, count: stack > 1 ? stack : null,
        data: { stockX: Number(x), stockY: Number(y), itemIndex: Number(itemIndex), stack: Number(stack) || 0, tab, price: priceOf(st.shop, tab, itemIndex) },
      };
    });
  }

  function rebuyItems() {
    return st.rebuy.map(r => ({ x: r.x, y: r.y, w: r.w, h: r.h, icon: null, count: r.count > 1 ? r.count : null, data: r }));
  }

  function tooltipFor(item) {
    const d = item.data;
    const lines = [];
    if (st.mode === 'rebuy') {
      lines.push({ text: `${str(game, 2000, 67, 'Repurchase')}: ${fmtNum(d.price)} Dil`, color: dil(game) >= d.price ? dilColor(d.price) : COLORS.RED });
      return itemTooltip(game, d.itemIndex, lines, d.entry);
    }
    const p = d.price;
    if (p.kind === 'dil' && itemsSys(game)) {
      // the items system's tooltip prints the buy price line itself (stringtable 12/2)
      return itemTooltip(game, d.itemIndex, d.stack > 1 ? [`x${d.stack}`] : [], null, { buyPrice: p.dil });
    }
    if (p.kind === 'dil') lines.push({ text: `Price: ${fmtNum(p.dil)} Dil${d.stack > 1 ? ` (x${d.stack})` : ''}`, color: dil(game) >= p.dil ? dilColor(p.dil) : COLORS.RED });
    else if (p.kind === 'points') lines.push({ text: `Price: ${fmtNum(p.points)} Battle Points`, color: (game.save?.battlePoints || 0) >= p.points ? COLORS.GOLD : COLORS.RED });
    else if (p.kind === 'items') {
      lines.push({ text: str(game, 340, 35, 'Materials'), color: COLORS.GOLD });
      for (const [i, c] of p.items) {
        const have = bag.count(game, i);
        lines.push({ text: `${itemInfo(game, i).name} ${fmtNum(have)} / ${fmtNum(c)}`, color: have >= c ? COLORS.GREEN : COLORS.RED });
      }
    } else lines.push({ text: 'Price: 0 Dil', color: COLORS.GOLD });
    return itemTooltip(game, d.itemIndex, lines);
  }

  // ---------------------------------------------------------------------------------------------- buying
  async function buySlot(d, qty = null) {
    if (!d || !st.win?.isOpen || st.mode !== 'shop' || st.buying) return false;
    if (qty != null && (!Number.isInteger(qty) || qty < 1 || qty > 9999)) return false;
    const context = { tok: st.tok, shop: st.shop, shopIndex: st.shopIndex, npcIndex: shopNpcIndex(),
      tab: st.shop.tabs.indexOf(d.tab), owner: game.save?.id, network: game.network, token: game.network?.token };
    if (context.tab < 0) return false;
    const current = () => st.win?.isOpen && st.mode === 'shop' && st.tok === context.tok &&
      game.save?.id === context.owner && game.network === context.network && game.network?.token === context.token;
    st.buying = true;
    try {
      const it = await itemInfoFull(game, d.itemIndex);
      if (!current()) return false;
      const p = priceOf(context.shop, d.tab, d.itemIndex);
      const per = Math.max(1, d.stack || 0); // Native sale StockCount, independently of inventory capacity.
      const stackable = maxStackOf(game, d.itemIndex) > 1 && p.kind !== 'items';
      let n = qty;
      if (p.kind === 'items') {
        if (n != null && n !== 1) return false;
        if (n == null && await api.windows.exchangeConfirm({ itemIndex: d.itemIndex, name: it.name }) !== 'yes') return false;
        n = 1;
      } else if (stackable && n == null) {
        const unitPrice = p.kind === 'dil' ? p.dil : p.kind === 'points' ? p.points : 0;
        n = await api.windows.askQuantity({ itemIndex: d.itemIndex, name: it.name, unitPrice,
          funds: p.kind === 'points' ? (game.save?.battlePoints || 0) : dil(game),
          currency: p.kind === 'points' ? 'Battle Points' : 'Dil', max: 9999 }); // Native edit maxlength4.
      } else if (n == null && game.mounts?.system?.data?.isVehicle?.(d.itemIndex)) {
        // a transportation item: Global msgbox/ui_buylimititem (2001:58 "Buy Item", lbl_text = the item, 170:9 "This item can only
        // be purchased one at a time." - Global's "UI alert message when buying a Transportation item")
        if (!await globalConfirm(game, 'game2:msgbox:ui_buylimititem', it.name, { body: 'lbl_text' })) return false;
        n = 1;
      } else if (n == null) {
        if (await api.windows.buyConfirm({ itemIndex: d.itemIndex, name: it.name, price: p.kind === 'dil' ? p.dil : null }) !== 'yes') return false;
        n = 1;
      }
      if (!current() || !Number.isInteger(n) || n < 1 || n > 9999) return false;
      if (game.save?.authority === 'server') {
        const result = await context.network?.action('shopbuy', { npcIndex: context.npcIndex, shop: context.shopIndex,
          tab: context.tab, itemIndex: d.itemIndex, stockX: d.stockX, stockY: d.stockY, count: n });
        if (result && current()) render();
        return !!result;
      }
      const units = n * per;
      if (!bag.canAdd(game, d.itemIndex, units)) { uiSound(game, 'lackOfSpace'); notice(game, MSG(game, 37, 'You do not have enough space in your bag.')); return false; }
      if (p.kind === 'dil') {
        const cost = p.dil * n;
        if (dil(game) < cost) { uiSound(game, 'lackOfDil'); notice(game, MSG(game, 1)); return false; }
        addDil(game, -cost);
      } else if (p.kind === 'points') {
        const cost = p.points * n;
        if ((game.save?.battlePoints || 0) < cost) { notice(game, MSG(game, 4)); return false; }
        game.save.battlePoints -= cost;
      } else if (p.kind === 'items') {
        const need = p.items.map(([i, c]) => [i, c * n]);
        if (!payItems(game, need)) { notice(game, MSG(game, 36, 'You do not have enough material items.')); return false; }
      }
      bag.add(game, d.itemIndex, units, { from: 'shop', period: Number(it.period) || 0 });
      say(game, n > 1 ? str(game, 340, 13, 'You have purchased %d items.').replace('%d', n) : MSG(game, 12), 'item');
      game.events?.emit?.('shop:buy', { shop: context.shopIndex, itemIndex: d.itemIndex, count: units, price: p });
      render();
      return true;
    } catch (error) {
      say(game, error?.message || 'Purchase failed.', 'err');
      return false;
    } finally { st.buying = false; }
  }

  // ---------------------------------------------------------------------------------------------- selling
  async function sellEntry(entry, { confirm = true } = {}) {
    if (!st.win?.isOpen) return false;
    await itemInfoFull(game, entry.itemIndex);
    const q = sellQuote(entry);
    if (q.refuse) { notice(game, MSG(game, q.refuse)); return false; }
    if (dil(game) + q.price > MAX_DIL) { notice(game, MSG(game, 7)); return false; }
    if (confirm) {
      const r = await api.windows.sellConfirm({ itemIndex: entry.itemIndex, name: itemInfo(game, entry.itemIndex).name, price: q.price });
      if (r !== 'yes') return false;
    }
    if (!bag.find(game, entry) && !bag.entries(game).includes(entry)) return false;
    if(game.save?.authority==='server'){
      const result=await game.network?.action('shopsell',{npcIndex:shopNpcIndex(),shop:st.shopIndex,uid:entry.uid});
      if(result){st.rebuy=(game.save.shopRebuy||[]).filter(row=>row.shop===st.shopIndex).map(row=>({...row,itemIndex:row.entry.itemIndex,count:row.entry.count||1}));packRebuy();render();}return !!result;
    }
    const count = Math.max(1, Number(entry.count) || 1);
    if (!bag.removeEntry(game, entry)) return false;
    addDil(game, q.price);
    pushRebuy({ itemIndex: Number(entry.itemIndex), count, price: q.price, entry: { ...entry } });
    say(game, `${itemInfo(game, entry.itemIndex).name}${count > 1 ? ` x${count}` : ''}: +${fmtNum(q.price)} Dil`, 'item');
    game.events?.emit?.('shop:sell', { shop: st.shopIndex, itemIndex: entry.itemIndex, count, price: q.price });
    if (st.mode === 'rebuy') render();
    return true;
  }

  // ---------------------------------------------------------------------------------------------- repurchase
  function pushRebuy(r) {
    const inf = itemInfo(game, r.itemIndex);
    r.w = Math.min(REBUY_COLS, inf.w || 1); r.h = Math.min(REBUY_ROWS, inf.h || 1);
    st.rebuy.push(r);
    // Guide Max 10 (stringtable_helper Shop Trade Repurchase); then pack into 10x8 UI grid.
    while (st.rebuy.length > 10) st.rebuy.shift();
    while (!packRebuy() && st.rebuy.length > 1) st.rebuy.shift();
  }
  function packRebuy() {
    const occ = Array.from({ length: REBUY_ROWS }, () => new Array(REBUY_COLS).fill(false));
    const fits = (x, y, w, h) => { for (let j = y; j < y + h; j++) for (let i = x; i < x + w; i++) if (j >= REBUY_ROWS || i >= REBUY_COLS || occ[j][i]) return false; return true; };
    for (const r of st.rebuy) {
      let placed = false;
      for (let y = 0; y < REBUY_ROWS && !placed; y++) for (let x = 0; x < REBUY_COLS && !placed; x++) {
        if (fits(x, y, r.w, r.h)) { for (let j = y; j < y + r.h; j++) for (let i = x; i < x + r.w; i++) occ[j][i] = true; r.x = x; r.y = y; placed = true; }
      }
      if (!placed) return false;
    }
    return true;
  }
  async function repurchase(r) {
    if (!st.rebuy.includes(r)) return false;
    const name = itemInfo(game, r.itemIndex).name;
    const ok = await api.windows.buyConfirm({ itemIndex: r.itemIndex, name, price: r.price });
    if (ok !== 'yes' || !st.rebuy.includes(r)) return false;
    if(game.save?.authority==='server'){
      const result=await game.network?.action('shoprebuy',{npcIndex:shopNpcIndex(),shop:st.shopIndex,receipt:r.id});
      if(result){st.rebuy=(game.save.shopRebuy||[]).filter(row=>row.shop===st.shopIndex).map(row=>({...row,itemIndex:row.entry.itemIndex,count:row.entry.count||1}));packRebuy();render();}return !!result;
    }
    if (!bag.canAdd(game, r.itemIndex, r.count)) { uiSound(game, 'lackOfSpace'); notice(game, MSG(game, 22)); return false; }
    if (dil(game) < r.price) { uiSound(game, 'lackOfDil'); notice(game, MSG(game, 23)); return false; }
    addDil(game, -r.price);
    const e = r.entry || {};
    // the very instance comes back (grade, options, sockets...)
    bag.add(game, r.itemIndex, r.count, { from: 'rebuy', inst: e.uid ? e : null, grade: e.grade, options: e.options, bound: e.bound, expires: e.expires });
    st.rebuy.splice(st.rebuy.indexOf(r), 1);
    packRebuy();
    render();
    return true;
  }

  // the list is per session: cleared when the character leaves the world (logout / character select)
  addEventListener('beforeunload', () => {
    disposed = true; clearTimeout(backgroundTimer); assets.dispose(); st.rebuy.length = 0;
  });

  return {
    state: st,
    priceOf, sellQuote, sellEntry, buySlot,
    prewarm,
    /** Diagnostics/tests (ICON-PRELOAD): the retained catalogue thumbnail pool and its catalogue keys. */
    iconPool: () => syncAssets(),
    catalogKeys: () => storeCatalogKeys(T.shops, index => itemInfo(game, index)),
    /** Open a store: shop index, NPC actor (null for the remote store). */
    open(shop, npc = null, remote = false) { return game.uiwin.open('shop', { shop, npc, remote }); },
    get isOpen() { return !!st.win?.isOpen; },
    get rebuyList() { return st.rebuy; },
    clearRebuy() { st.rebuy.length = 0; if (st.mode === 'rebuy') render(); },
    refresh: render,
  };
}
