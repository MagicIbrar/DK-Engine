// The D-Shop ("Deka Shop", cashshop/ui_cashshopwnd_search.txt, 994x751) and its sister, the VIP shop
// (vipshop/ui_vipshopwnd_search.txt), both built on the same layout (docs/formats/shops.md 4):
//   * main tabs btn_hot / btn_item / btn_petvehicle / btn_costume (VIP: btn_main_all / btn_premium_equipment /
//     btn_unique) with their sub-tab panels pan_hot / pan_item / ... (dshop.json tabs[].subs[].button)
//   * the product cells: pan_goodsinfo (242x121, cashshop#19) instantiated 3 x 3 under the banner (x 15 + 242 c,
//     y 338 + 121 r; the template sits at y 217, one cell above, hidden by the 740x176 banner), paged with pan_page
//   * per cell: the item model (item_goods), name, the variant combo "N ea/price" (220/23) or "D days/price" (220/24),
//     notice/limit badges (pan_limitevent: HOT #31 / NEW #32 / EVENT #65 224/n, Lv. %d #30 225/2, Buy %d/%d #29 225/1),
//     Buy (220/25) = put in the cart, Preview (220/16)
//   * the cart: 7 x 4 slots of 33 px (item_cart template at 753,470) measured on cashshopwnd#9; right-click removes
//   * balances (EU labels: Total Cash 171/1, Non Refundable 171/44, Total Buying 220/21, Remaining 220/22):
//     UNLIMITED coins (solo) - the balance never runs out
//   * Buy (220/17) buys the whole cart -> confirm (msgbox/cashitem/ui_confirmbuy.txt) -> Cash Inventory ->
//     result (ui_resultbuy_cashinventory.txt); Send as Gift (220/18) -> ui_cashgiftwnd.txt (another local character)
//   * Refill Cash (220/19) shows the client's DKC text (171/37)
//   * search: 3 combos (main 210, sub 220/211/212, class 213) + name -> results paged with pan_searchpage
//   * "View Probability" (btn_link 220/47) -> notice/ui_randomboxinfownd.txt
//   * clicking a product box -> the box info window (cashshop/ui_cashshopboxinfownd.txt)
// Purchase warnings (product.warning) show msgbox/cashitem/ui_waringbuycashitem.txt with the item's text first.
import { createControl } from '../../ui/uiwin/controls.js';
import { nextTask } from '../../engine/yield.js';
import { PREBUILD } from '../../config/engine-chosen-loading.js';
import { measureText } from '../../ui/uiwin/fonts.js';
import { T, loadDshop, itemInfo, itemInfoFull, itemIcon, itemTooltip, str, say, notice, fmtNum, COLORS, uiSound, periodText, maxStackOf, cleanMarkup } from './common.js';
import {atlas} from '../../ui/atlas.js';
import {repairNativeShopStateArt} from '../../ui/native-shop-state-art.js';
import { ModelPreview } from './preview.js';
import { ShopPageAssets } from './page-assets.js';
import { afterWorldReady } from '../../engine/after-load.js';
import { borrowPreviewIcon } from '../../ui/preview-cache.js';
import { fitVipCartCaptions } from './vip-cart-captions.js';
import { shopNameLayout } from './shop-name-layout.js';
import { WING_SHOP_MAIN } from '../../content/wing-items.js';
import { nativeWingPurchasePrice } from '../../content/native-wing-shop.js';
import { SHOP_WINDOW_SCRIPTS, PURCHASE_PASSWORD_MAX, PURCHASE_PASSWORD_TEXT, purchasePasswordRequired, VIP_BOX_ROWS, PREVIEW_ZOOM } from './shop-windows-rules.js';
import { GIFT_TEXT, giftRecipient } from './gift-rules.js';
import { randomUUID } from '../network/web-crypto.js';

export const UNLIMITED = 999999999;
// ENGINE-CHOSEN (2.2.1, measured in the real client, not game data): how many
// icon jobs the shop pages run at once. A distinct wing's icon costs 270-730 ms of model load (mesh + textures, mostly IO) and
// only ~50 ms of drawing; 9 loads in parallel took 0.61 s against ~3.3 s one after the other, so a single prefetch slot
// (concurrency 2 = 1 background + 1 visible) could not keep up with a player paging at 0.3-0.7 s per page. While the shop window
// is OPEN the pool is 4 (3 background + 1 visible); the visible page always has a slot (page-assets.js) and the shared preparation
// queue (items/preview-queue.js) caps live bakes at 4. Closed (the idle prewarm during play) it stays at the 2.2.0 value of 2.
const SHOP_ICON_CONCURRENCY_IDLE = 2, SHOP_ICON_CONCURRENCY_OPEN = 4;
const WING_WARM_PAGES = 12;   // ICON-PRELOAD: Wings-tab pages kept ready at startup (prewarm below)
const PER_PAGE = 9, COLS = 3, CELL_W = 242, CELL_H = 121, CELL_X = 15, CELL_Y = 338;
const CART_COLS = 7, CART_ROWS = 4, CART_X = 753, CART_Y = 470, SLOT = 33;
const NAME_RECT = [84, 32, 143, 14];                     // lbl_itemname in pan_goodsinfo
const NOTICE_SPRITE = { 1: 31, 2: 32, 4: 65 };           // Best Selling -> HOT, New -> NEW, Event -> EVENT
const NOTICE_LABEL = { 1: [224, 1, 'HOT'], 2: [224, 2, 'NEW'], 3: [221, 3, 'On Sale'], 4: [224, 3, 'EVENT'] };
const PANELS = { hot: 'pan_hot', item: 'pan_item', petvehicle: 'pan_petvehicle', costume: 'pan_costume', wings: 'pan_wings' };
const nl = s => String(s ?? '').replace(/\\/g, '\n');

// Use the original empty subtab artwork and font. Main-category sprites have
// their original words baked into the texture, so those cannot label a new tab.
function addWingsControls(win) {
  if (win.find('btn_wings')) return;
  const original = win.control('btn_all').spec;
  const add = (spec, parent = win.root) => {
    const control = createControl(win, spec, parent);
    parent.children.push(control); parent.el.appendChild(control.el);
    control.layout(parent.box);
    return control;
  };
  const button = (id, rect) => ({ ...original, id, rect, visible: true,
    images: original.images.map(image => ({ ...image })),
    titles: original.titles.map(title => ({ ...title })), props: { ...original.props }, children: [] });
  add(button('btn_wings', [530, 81, 80, 28])).setText('Wings');
  const panel = add({ type: 'panel', id: 'pan_wings', rect: [10, 107, 739, 55],
    layer: 20, enable: true, visible: false, images: [], titles: [], props: {}, children: [] });
  add(button('btn_all_wings', [16, 15, 80, 28]), panel).setText('All wings');
  add({ type: 'label', id: 'lbl_wings_catalog', rect: [115, 15, 610, 28],
    enable: true, visible: true, images: [], titles: [], props: {}, children: [] }, panel)
    .setFont(4).setTextColor('#e8dac4').setText('50 wings');
  win._indexControls();
}

/** Build one cash-shop window (D-Shop or VIP shop). */
function makeCashShop(game, api, cfg) {
  const iconGeneration = () => game.items?.icons?.cache?.generation ?? 0;
  const st = {
    win: null, main: 0, sub: 0, page: 0, cells: [], cart: [], cartSlots: [], search: null, spage: 0, tok: 0,
    preview: null, previewItem: null, classFilter: -1, iconCache: null, pageAbort: null, renderedKey: null, iconGeneration: iconGeneration(),
  };
  const decodedURLs = new Map();
  st.decodedURLs = decodedURLs;
  // mode: 'foreground' | 'background' (prefetch bake) | 'disk' (ICON-PRELOAD: memory / persistent icon cache only, no bake)
  const prepareProduct = async (i, mode = 'foreground') => {
    const generation = iconGeneration();
    await itemInfoFull(game, i);
    const icons = game.items?.icons;
    const request = () => itemIcon(game, i, 60, 60);
    const icon = await (mode === 'disk' && icons?.diskOnly ? icons.diskOnly(request) : mode === 'background' && icons?.background ? icons.background(request) : request());
    if (generation !== iconGeneration()) return null;
    const release = borrowPreviewIcon(icon);
    try {
    if (icon?.url && typeof Image !== 'undefined') {
      let decoded = decodedURLs.get(icon.url);
      if (!decoded) {
        const image = new Image(); image.src = icon.url;
        decoded = Promise.resolve().then(() => image.decode?.());
        decodedURLs.set(icon.url, decoded);
        while (decodedURLs.size > 400) decodedURLs.delete(decodedURLs.keys().next().value);
        decoded.catch(() => { if (decodedURLs.get(icon.url) === decoded) decodedURLs.delete(icon.url); });
      } else { decodedURLs.delete(icon.url); decodedURLs.set(icon.url, decoded); }
      await decoded;
    }
    return generation === iconGeneration() && icon?.url ? icon : null;
    } finally { release(); }
  };
  const assets = new ShopPageAssets((i, { background = false } = {}) => prepareProduct(i, background ? 'background' : 'foreground'),
    { concurrency: SHOP_ICON_CONCURRENCY_IDLE, paused: () => game._loadingMap === true });   // 2.2.1: no prefetch bakes while a map loads (page-assets.js)
  st.iconCache = assets.cache; st.assets = assets;
  function syncIconGeneration() {
    const generation = iconGeneration();
    if (generation === st.iconGeneration) return false;
    st.iconGeneration = generation; st.iconCache.clear(); decodedURLs.clear(); st.renderedKey = null;
    st.pageAbort?.abort(); st.prefetchAbort?.abort(); ++st.tok;
    // Only resident controls are invalidated; canonical Icons owns all URLs.
    for (const c of st.cells) if (c.product) c.goods.setIcon(null, { inset: 1 });
    for (const slot of st.cartSlots) slot.setIcon(null);
    return true;
  }
  function cachedShopIcon(i) {
    syncIconGeneration();
    const native = game.items?.icons, exact = native?.now?.(i, 60, 60);
    const decoded = st.iconCache.get(i);
    if (decoded) {
      const original = exact || native?.cached?.(i);
      if (!native || original?.url === decoded.url) return decoded;
      st.iconCache.delete(i);
    }
    return exact || null;
  }
  const offCatalog = game.events?.on?.('server:customitems', () => {
    if (!syncIconGeneration() || !st.win?.isOpen) return;
    void renderCells(); renderCart();
  });
  const D = () => T.dshop;
  const tabs = () => (cfg.vip ? D().vipShop.tabs.map(t => ({ ...t, key: t.button, subs: [{ sub: 0, name: 'All', button: cfg.vipSubs[t.main] }] })) : D().tabs);
  const products = () => (cfg.vip ? D().vipShop.products : D().products);
  // D-Shop fields come from dshop.json items (item.dat cash / stack-per-purchase / period), not the bag stack size
  const dItem = (i) => ({ ...itemInfo(game, i), ...(D().items?.[i] || {}) });
  // dItem(i).nativeWing without copying the whole merged record for every catalogue product (the prewarm filters
  // ran it over the full Wings tab during loading): the dshop.json row wins over itemInfo, as in the spread above.
  const isNativeWing = (i) => { const own = D().items?.[i]; return (own && Object.hasOwn(own, 'nativeWing') ? own.nativeWing : itemInfo(game, i).nativeWing) === true; };
  const priceOf = (i) => { const record=dItem(i);return record.nativeWing?nativeWingPurchasePrice(record):(cfg.vip ? Number(record.vipCost) || Number(record.cash) || 0 : Number(record.cash) || 0); };
  const unitsOf = (i) => Math.max(1, Number(D().items?.[i]?.stack ?? 1) || 1);
  const bought = () => ((game.save.dshopBought ||= {}));
  // the coin balance: UNLIMITED unless the GM coin editor (/gm dkc) set one
  const online = () => game.save?.authority === 'server';
  const balance = () => { if(online())return cfg.vip?(Number(game.save.vipPoints)||0):(game.accountPermissions?.capabilities?.includes('gm:commands')?UNLIMITED:Number(game.save.dkc)||0);const b = game.gm?.dshopBalance?.(); return b == null ? UNLIMITED : b; };

  game.uiwin.registerWindow(cfg.name, {
    script: cfg.script,
    menuButton: cfg.menuButton,
    async create(win) {
      st.win = win;
      win.once('dispose', () => {
        st.pageAbort?.abort(); st.prefetchAbort?.abort(); ++st.tok; assets.dispose(); decodedURLs.clear(); offCatalog?.();
        st.preview?.dispose?.(); st.win = null;
      });
      await loadDshop();
      if (st.win !== win) return;
      if (cfg.vip) fitVipCartCaptions(win);
      else addWingsControls(win);
      // ---- main tabs + sub tabs
      tabs().forEach((t) => {
        win.control(t.button).onClick(() => selectTab(t.main, t.subs.find(s => !s.legacyOnly)?.sub ?? 0));
        for (const s of t.subs) if (!s.legacyOnly) win.control(s.button).onClick(() => selectTab(t.main, s.sub));
      });
      // ---- product cells from the template
      const tpl = win.control('pan_goodsinfo');
      for (let k = 0; k < PER_PAGE; k++) {
        const root = tpl.cloneAs(`_${k}`, { x: CELL_X + (k % COLS) * CELL_W, y: CELL_Y + Math.floor(k / COLS) * CELL_H, visible: false });
        const c = {
          k, root, goods: win.control(`item_goods_${k}`), name: win.control(`lbl_itemname_${k}`), combo: win.control(`com_item_${k}`),
          cart: win.control(`btn_cart_${k}`), prev: win.control(`btn_preview_${k}`), limit: win.control(`pan_limitevent_${k}`),
          event: win.control(`pan_event_${k}`), img: [0, 1, 2].map(i => win.control(`pan_image${i}_${k}`)), txt: [0, 1, 2].map(i => win.control(`lbl_text${i}_${k}`)),
          product: null,
        };
        c.combo.on('change', () => { if (c.product) c.variant = c.product.items[c.combo.getSelected()] ?? c.product.items[0]; updCell(c); });
        c.cart.onClick(() => { if (c.product) addToCart(c.product, c.variant); });
        c.prev.onClick(() => { if (c.product) showPreview(c.variant); });
        c.goods.setTooltip(() => (c.product ? productTip(c.variant) : null));
        // the VIP shop has its own box info window (vipshop/ui_vipshopboxinfownd.txt, SHOP-WINDOWS)
        c.goods.onClick(() => { if (c.product) (cfg.vip && api.vipBoxInfo ? api.vipBoxInfo : api.boxInfo).show(c.variant); });
        c.goods.onRightClick(() => { if (c.product) addToCart(c.product, c.variant); });
        st.cells.push(c);
      }
      // ---- cart slots
      const ctpl = win.control('item_cart');
      for (let r = 0; r < CART_ROWS; r++) for (let q = 0; q < CART_COLS; q++) {
        const k = r * CART_COLS + q;
        const s = ctpl.cloneAs(`_${k}`, { x: CART_X + q * SLOT, y: CART_Y + r * SLOT, visible: true });
        s.setEnabled(true);
        s.setTooltip(() => { const e = st.cart[k]; return e ? productTip(e.itemIndex) : null; });
        const drop = () => { if (st.cart[k]) { st.cart.splice(k, 1); renderCart(); } };
        s.onRightClick(drop); s.onDoubleClick(drop);
        st.cartSlots.push(s);
      }
      // ---- balances (EU client labels)
      for (const id of ['lbl_tagcurrentcash', 'lbl_currentcash', 'lbl_tagallpaycash', 'lbl_allpaycash', 'lbl_tagremaincash', 'lbl_remaincash']) if (!cfg.vip) win.control(id).hide();
      // ---- buttons (the VIP window has no gift / refill / probability buttons)
      win.control('btn_allbuy').onClick(() => buyCart());
      win.find('btn_allgift')?.onClick(() => giftCart());
      win.find('btn_cashcharge')?.onClick(() => notice(game, online()?'Your DKC balance is managed by the server. This private engine has no payment or refill service.':`${nl(str(game, 171, 37, ''))}\n\n(Dekaron Online: your D-Shop coins are unlimited.)`, str(game, 220, 19, 'Refill Cash')));
      win.find('btn_link')?.onClick(() => api.probability.open());
      win.control('btn_prev').onClick(() => { if (st.page > 0) { st.page--; renderCells(); } });
      win.control('btn_next').onClick(() => { if (st.page < pageCount(listNow()) - 1) { st.page++; renderCells(); } });
      win.control('btn_searchprev').onClick(() => { if (st.spage > 0) { st.spage--; renderCells(); } });
      win.control('btn_searchnext').onClick(() => { if (st.spage < pageCount(listNow()) - 1) { st.spage++; renderCells(); } });
      // ---- search
      setupSearch(win);
      // ---- costume class filter (com_norclass; class names cate 222, 14 = All)
      if (!cfg.vip) {
        const cls = win.control('com_norclass');
        cls.setItems([{ text: str(game, 222, 14, 'All'), value: -1 }, ...classOptions()]);
        cls.on('change', () => { st.classFilter = Number(cls.getValue()); st.page = 0; renderCells(); });
        win.control('com_preclass').hide();
      }
      // ---- the preview pane (cashshop/ui_previewwnd.txt embedded in the right column)
      if (!cfg.vip) await embedPreview(win);
      else win.control('pan_web_banner').setImage('none', 'banner_vip', 0);
      if (st.win !== win) return;
      // Populate the resident hidden default page during loading. Opening reveals ready cells.
      await renderCells();
    },
    onOpen(win, arg) {
      st.search = null;
      assets.setConcurrency(SHOP_ICON_CONCURRENCY_OPEN);
      if (arg?.main != null) selectTab(Number(arg.main), Number(arg.sub ?? 0));
      else selectTab(st.main ?? 0, st.sub ?? 0);
      renderCart();
      game.events?.emit?.('dshop:open', { vip: !!cfg.vip });
      if (st.deepWarm) { const w = st.deepWarm; st.deepWarm = null; w(); }   // PERF-CROWD2: deferred deep-page prefetch
    },
    onClose() { assets.setConcurrency(SHOP_ICON_CONCURRENCY_IDLE); st.pageAbort?.abort(); st.prefetchAbort?.abort(); ++st.tok; game.uiwin.tooltips.hide(); if (st.preview) st.preview.auto = false; },
    update(win, dt) { if (st.preview && st.previewItem != null) { st.preview.auto = true; st.preview.tick(dt); } },
  });

  // ---------------------------------------------------------------------------------------------- tabs / cells
  function selectTab(main, sub) {
    const w = st.win;
    if (!w) return;
    st.main = main; st.sub = sub; st.page = 0; st.search = null; st.wingSearch = false;
    if (!cfg.vip && main === WING_SHOP_MAIN) st.clearWingFilters?.();
    for (const t of tabs()) {
      const on = t.main === main;
      w.control(t.button).setChecked(on);
      w.control(cfg.vip ? cfg.vipPanels[t.main] : PANELS[t.key]).setVisible(on);
      for (const s of t.subs) if (!s.legacyOnly) w.control(s.button).setChecked(on && s.sub === sub);
    }
    if (!cfg.vip) {
      const isCos = main === 3 && sub === 29;
      w.control('com_norclass').setVisible(isCos);
      if (!isCos) { st.classFilter = -1; w.control('com_norclass').select(0); }
    }
    w.control('pan_page').show();
    w.control('pan_searchpage').hide();
    return renderCells();
  }
  function listNow() {
    if (st.search) return st.search;
    let list = products().filter(p => p.main === st.main && (cfg.vip || p.sub === st.sub));
    if (st.classFilter >= 0) list = list.filter(p => classOk(p.items[0], st.classFilter));
    return list;
  }
  const classOk = (item, c) => { const m = Number(itemInfo(game, item).classMask ?? 32767); return !m || ((m >> c) & 1) === 1; };
  const pageCount = (list) => Math.max(1, Math.ceil(list.length / PER_PAGE));
  function classOptions() {
    const classes = game.items?.db?.enums?.classes || game.items?.sys?.db?.enums?.classes;
    return Array.isArray(classes) && classes.length ? classes.map(c => ({ text: c.name, value: c.index }))
      : Array.from({ length: 15 }, (_, i) => ({ text: i === 14 ? 'Trie Muse' : str(game, 213, i + 2, `Class ${i}`), value: i }));
  }

  async function renderCells(catalogAttempt = 0) {
    syncIconGeneration();
    const generation = iconGeneration();
    const w = st.win;
    if (!w) return;
    st.pageAbort?.abort();
    const signal = (st.pageAbort = new AbortController()).signal;
    const tok = ++st.tok;
    const list = listNow();
    const page = st.search ? st.spage : st.page;
    if (!cfg.vip && (st.main === WING_SHOP_MAIN || st.wingSearch)) {
      const total = products().filter(p => p.main === WING_SHOP_MAIN).length;
      w.control('lbl_wings_catalog').setText(st.search
        ? `${list.length} ${st.wingSearch ? `of ${total} wings` : 'search results'} · filtered · page ${page + 1} / ${pageCount(list)} · All wings clears filters`
        : `${total} wings · page ${page + 1} / ${pageCount(list)}`);
    }
    const slice = list.slice(page * PER_PAGE, page * PER_PAGE + PER_PAGE);
    const key = JSON.stringify([!!st.search, page, slice.map(p => p.id)]);
    if (st.renderedKey === key) {
      st.cells.forEach(c => { if (c.product) updCell(c); });
      return;
    }
    // Select only the nine visible variants. Alternate variants use table metadata
    // for their labels and are prepared when chosen, never ahead of the visible page.
    const ids = slice.map(p => p.items[0]);
    // The panel never waits for artwork: names, prices and buttons appear at once and each icon
    // drops in when its render is ready (updCell -> assets.visible), so pages open instantly.
    const cold = ids.filter(i => !cachedShopIcon(i) && !game.items?.icons?.cached?.(i));
    if (cold.length) void assets.page(cold, { signal, priority: 0 }).catch(() => {});
    if (generation !== iconGeneration()) {
      syncIconGeneration();
      if (w === st.win && catalogAttempt < 2) return renderCells(catalogAttempt + 1);
      return;
    }
    if (signal.aborted || tok !== st.tok || w !== st.win) return;
    st.renderedKey = key;
    st.cells.forEach((c, k) => {
      const p = slice[k] || null;
      c.product = p;
      c.root.setVisible(!!p);
      if (!p) return;
      c.variant = p.items[0];
      c.combo.setItems(p.items.map(i => ({ text: variantLabel(i), value: i })));
      c.combo.select(0);
      setCellName(c, itemInfo(game, p.items[0]).name);
      c.goods.setIcon(cachedShopIcon(c.variant) || game.items?.icons?.cached?.(c.variant) || null, { inset: 1 });
      updCell(c);
    });
    const pages = pageCount(list);
    const lbl = st.search ? 'lbl_searchpagenumber' : 'lbl_pagenumber';
    w.control(lbl).setText(`${page + 1} / ${pages}`);
    w.control(st.search ? 'btn_searchprev' : 'btn_prev').setEnabled(page > 0);
    w.control(st.search ? 'btn_searchnext' : 'btn_next').setEnabled(page < pages - 1);
    // Next/previous pages prepare under a list-level signal: paging keeps the queued neighbours alive (so the next
    // click finds its icons ready) and only a different tab, filter or search retires them.
    const listKey = JSON.stringify([!!st.search, st.main, st.sub, st.classFilter, list.length, list[0]?.id]);
    if (st.prefetchKey !== listKey || !st.prefetchAbort || st.prefetchAbort.signal.aborted) {
      st.prefetchAbort?.abort(); st.prefetchAbort = new AbortController(); st.prefetchKey = listKey;
    }
    void assets.neighbors(list.map(p => p.items[0]), page, PER_PAGE, { signal: st.prefetchAbort.signal });
    if (st.search && !list.length) notice(game, str(game, 220, 39, 'No results found.'));
  }
  /**
   * lbl_itemname is 143 x 14 (fontIndex 4, centred) in the D-Shop and most product names are wider ("New Type Formal
   * Suit Costume Ex-Box"). The VIP shop's copy of the same cell is scripted `multiline / autoline, lineheight 15` at
   * y 22 (ui_vipshopwnd_search.txt): the client wraps these names. A D-Shop name that does not fit gets that same
   * autoline treatment (the label grows upward into the free band above it); a name that fits keeps the script rect.
   */
  function setCellName(c, name) {
    name = String(name || '').trim();
    const sp = c._nameSpec || (c._nameSpec = c.name.spec || {});
    if (!cfg.vip && dItem(c.variant).nativeWing) {
      const layout = shopNameLayout(name, text => measureText(text, 4), { rect: sp.rect || NAME_RECT, comboY: c.combo.spec?.rect?.[1] || 57 });
      c.name.spec = { ...sp, props: { ...(sp.props || {}), multiline: ['true'], autoline: ['true'], lineheight: [String(layout.lineHeight)] } };
      c.name.setRect(layout.x, layout.y, layout.width, layout.height); c.name.resetText(); c.name.setText(name);
      c.name.setTooltip(() => name);
      if (c.name.txt) { c.name.txt.style.overflow = 'hidden'; if (c.name.txt.firstChild) c.name.txt.firstChild.style.overflowWrap = 'anywhere'; }
      return;
    }
    c.name.setTooltip(null);
    if (c.name.txt) { c.name.txt.style.overflow = ''; if (c.name.txt.firstChild) c.name.txt.firstChild.style.overflowWrap = ''; }
    if (/^true/i.test(String(sp.props?.autoline?.[0] ?? sp.props?.multiline?.[0] ?? ''))) {
      c.name.spec = sp; c.name.setRect(...(sp.rect || NAME_RECT)); c.name.resetText(); c.name.setText(name); return;
    }
    c._wrapSpec ||= { ...sp, props: { ...(sp.props || {}), multiline: ['true'], autoline: ['true'], lineheight: ['15'] } };
    const [x, y, w, h] = Array.isArray(sp.rect) && sp.rect.length >= 4 ? sp.rect : NAME_RECT;
    const fits = measureText(name, 4) <= w;
    c.name.spec = fits ? sp : c._wrapSpec;
    c.name.setRect(x, fits ? y : y - 8, w, fits ? h : 30);
    c.name.resetText();
    c.name.setText(name);
  }
  function variantLabel(i) {
    const it = dItem(i);
    const price = priceOf(i);
    if (Number(it.period) > 0) return str(game, 220, 24, '%u days/%u').replace('%u', Math.max(1, Math.round(it.period / 86400))).replace('%u', fmtNum(price));
    return str(game, 220, 23, '%u ea/%u').replace('%u', unitsOf(i)).replace('%u', fmtNum(price));
  }
  function updCell(c) {
    syncIconGeneration();
    const p = c.product, i = c.variant;
    if (!p) return;
    const generation = iconGeneration();
    const it = dItem(i);
    const tok = st.tok;
    setCellName(c, it.name);
    const cached = cachedShopIcon(i);
    if (cached) c.goods.setIcon(cached, { inset: 1 });
    if (!cached) {
      const original = game.items?.icons?.cached?.(i);
      c.goods.setIcon(original || null, { inset: 1 });
      assets.visible(i, {
        signal: st.pageAbort?.signal, owner: c,
        isVisible: () => generation === iconGeneration() && tok === st.tok && c.variant === i && !!st.win?.isOpen,
        onReady: ic => c.goods.setIcon(ic, { inset: 1 }),
      });
    }
    // badges (right to left): notice, level, purchase limit
    const badges = [];
    if (p.notice && NOTICE_LABEL[p.notice]) { const [ca, co, fb] = NOTICE_LABEL[p.notice]; badges.push({ spr: NOTICE_SPRITE[p.notice] ?? null, text: str(game, ca, co, fb) }); }
    if (Number(it.purchaseLimitLv) > 0) badges.push({ spr: 30, text: str(game, 225, 2, 'Lv. %d').replace('%d', it.purchaseLimitLv) });
    if (Number(it.purchaseLimit) > 0) badges.push({ spr: 29, text: str(game, 225, 1, 'Buy %d/%d').replace('%d', bought()[i] || 0).replace('%d', it.purchaseLimit) });
    c.limit.setVisible(badges.length > 0);
    c.event.hide();
    for (let s = 0; s < 3; s++) {
      const b = badges[s];
      c.img[s].setVisible(!!b?.spr);
      c.txt[s].setVisible(!!b);
      if (b?.spr) c.img[s].setImage('none', 'cashshop', b.spr);
      if (b) c.txt[s].setText(b.text);
    }
    c.prev.setEnabled(previewable(i));
  }
  function previewable(i) {
    const it = itemInfo(game, i);
    const t = Number(it.type);
    if (it.slot === 'wing') return true;
    if (t === 4 || t === 5 || t === 10 || t === 2) return true;   // weapons, armour, costumes, accessories
    return !!D().boxes?.[i] && D().boxes[i].list?.some(([x]) => [4, 5, 10].includes(Number(itemInfo(game, x).type)));
  }
  function productTip(i) {
    const it = dItem(i);
    const lines = [{ text: `${fmtNum(priceOf(i))} ${cfg.vip ? 'VIP' : D().currency?.name || 'DKC'}`, color: COLORS.GOLD }];
    if (unitsOf(i) > 1) lines.push({ text: `x${unitsOf(i)}`, color: COLORS.WHITE });
    if (Number(it.period) > 0) lines.push({ text: periodText(it.period), color: COLORS.GREEN });
    else lines.push({ text: str(game, 220, 37, 'Permanent'), color: COLORS.GREEN });
    if (D().boxes?.[i] || D().packages?.[i]) lines.push({ text: '(click: contents)', color: COLORS.GREY });
    return itemTooltip(game, i, lines);
  }

  // ---------------------------------------------------------------------------------------------- cart
  async function addToCart(p, i) {
    const it = dItem(i);
    if (Number(it.purchaseLimitLv) > 0 && (game.save?.level || 1) < it.purchaseLimitLv) {
      notice(game, str(game, 225, 2, 'Lv. %d').replace('%d', it.purchaseLimitLv)); return false;
    }
    const inCart = st.cart.filter(e => e.itemIndex === i).length;
    if (Number(it.purchaseLimit) > 0 && (bought()[i] || 0) + inCart >= it.purchaseLimit) {
      notice(game, str(game, 225, 1, 'Buy %d/%d').replace('%d', (bought()[i] || 0) + inCart).replace('%d', it.purchaseLimit)); return false;
    }
    if (st.cart.length >= CART_COLS * CART_ROWS) { notice(game, nl(str(game, 220, 31, 'Cannot add more items because your cart is full.'))); return false; }
    if (p.warning || D().warnings?.[i]) {
      const r = await warningBox(D().warnings?.[i] || str(game, 171, 34, ''));
      if (r !== 'yes') return false;
    }
    st.cart.push({ itemIndex: i, price: priceOf(i), units: unitsOf(i), product: p.id });
    uiSound(game, 'buttonCommon');
    renderCart();
    return true;
  }
  async function warningBox(text) {
    const win = await game.uiwin.create('game2/msgbox/cashitem/ui_waringbuycashitem.txt', { modal: true, remember: false, disposeOnClose: true });
    return new Promise((resolve) => {
      win.control('lbl_text').setRichText(cleanMarkup(nl(text)));
      win.control('lbl_text').setRect(6, 26, 220, 100);
      win.once('close', r => resolve(r === 'yes' ? 'yes' : 'no'));
      win.control('btn_yes').onClick(() => win.close('yes'));
      win.control('btn_no').onClick(() => win.close('no'));
      game.uiwin.openWindow(win);
    });
  }
  const cartTotal = () => st.cart.reduce((s, e) => s + e.price, 0);
  function renderCart() {
    syncIconGeneration();
    const generation = iconGeneration();
    const w = st.win;
    if (!w) return;
    const tok = st.tok;
    st.cartSlots.forEach((s, k) => {
      const e = st.cart[k];
      s.setIcon(null); s.setCount(null);
      if (!e) return;
      s.setCount(e.units > 1 ? e.units : null);
      // the product cell's picture shows at once; the 33 px render replaces it when ready
      const cached = cachedShopIcon(e.itemIndex);
      if (cached) s.setIcon(cached);
      itemIcon(game, e.itemIndex, SLOT, SLOT).then(ic => { if (ic && generation === iconGeneration() && st.win === w && st.cart[k] === e) s.setIcon(ic); });
    });
    const total = cartTotal();
    if (cfg.vip) {
      w.control('lbl_currentcash').setText(fmtNum(online()?balance():UNLIMITED));
      w.control('lbl_allpaycash').setText(fmtNum(total));
      w.control('lbl_remaincash').setText(fmtNum((online()?balance():UNLIMITED) - total));
    } else {
      w.control('lbl_totalcashEU').setText(fmtNum(balance()));
      w.control('lbl_nonrefundablecashEU').setText('0');
      w.control('lbl_allpaycashEU').setText(fmtNum(total));
      w.control('lbl_remaincashEU').setText(fmtNum(balance() - total));
    }
    void tok;
  }
  async function confirmCart(title) {
    const win = await game.uiwin.create('game2/msgbox/cashitem/ui_confirmbuy.txt', { modal: true, remember: false, disposeOnClose: true });
    // The translated purchase question needs two lines inside the original frame.
    const question = win.find('lbl_quest');
    if (question) {
      question.spec = { ...question.spec, props: { ...question.spec.props, autoline: ['true'], lineheight: ['14'] } };
      question.setRect(17, 110, 197, 28);
    }
    return new Promise((resolve) => {
      const first = itemInfo(game, st.cart[0].itemIndex).name;
      win.control('multilbl_0').setText(st.cart.length > 1 ? `${first} (+${st.cart.length - 1})` : first);
      win.control('multilbl_1').setText(fmtNum(cartTotal()));
      win.control('multilbl_2').setText(fmtNum((cfg.vip && !online()?UNLIMITED:balance()) - cartTotal()));
      if (title) win.control('lbl_top').setText(title);
      win.once('close', r => resolve(r === 'yes' ? 'yes' : 'no'));
      win.control('btn_yes').onClick(() => win.close('yes'));
      win.control('btn_no').onClick(() => win.close('no'));
      game.uiwin.openWindow(win);
    });
  }
  async function resultBox(n, total, text) {
    const win = await game.uiwin.create('game2/msgbox/cashitem/ui_resultbuy_cashinventory.txt', { modal: true, remember: false, disposeOnClose: true });
    return new Promise((resolve) => {
      win.control('multilbl_0').setText(`${n}`);
      win.control('multilbl_1').setText(fmtNum(total));
      win.control('multilbl_2').setText(fmtNum(cfg.vip && !online()?UNLIMITED:balance()));
      win.control('lbl_notice').setRichText(nl(text));
      win.once('close', () => resolve('ok'));
      win.control('btn_yes').onClick(() => win.close('yes'));
      game.uiwin.openWindow(win);
    });
  }
  // ---------------------------------------------------------------------------- purchase password (SHOP-WINDOWS)
  async function passwordWanted() {
    try { const { currentAccountId } = await import('../../game/save.js'); return purchasePasswordRequired(currentAccountId()); } catch { return false; }
  }
  /** cashshop/ui_buypasswordwnd.txt: Confirm Password (100:131), the withdrawal guide (220:38), 'Enter your password.' (220:29),
   *  'Password:' (220:30); resolves the typed password, or null on Cancel. */
  async function passwordBox() {
    const win = await game.uiwin.create(SHOP_WINDOW_SCRIPTS.buyPasswordWnd, { modal: true, remember: false, disposeOnClose: true });
    st.passwordWin = win;
    return new Promise((resolve) => {
      const edit = win.control('edit_text');
      if (edit.input) edit.input.maxLength = PURCHASE_PASSWORD_MAX;
      edit.setValue?.('');
      const confirm = () => {
        const v = String(edit.getValue?.() ?? '');
        if (!v) { notice(game, str(game, 220, 29, PURCHASE_PASSWORD_TEXT.enter)); edit.focus?.(); return; }
        win.close('yes');
      };
      win.once('close', r => { st.passwordWin = null; const v = String(edit.getValue?.() ?? ''); edit.setValue?.(''); resolve(r === 'yes' && v ? v : null); });
      win.control('btn_confirm').onClick(confirm);
      win.control('btn_cancel').onClick(() => win.close('no'));
      edit.on('enter', confirm);
      game.uiwin.openWindow(win);
      setTimeout(() => edit.focus?.(), 0);
    });
  }
  /** msgbox/cashitem/ui_errpwd.txt: 'Password is not correct. Your order has been cancelled.' (171:30). */
  async function wrongPasswordBox() {
    const win = await game.uiwin.create(SHOP_WINDOW_SCRIPTS.wrongPasswordWnd, { modal: true, remember: false, disposeOnClose: true });
    return new Promise((resolve) => {
      win.control('lbl_errMsg').setText(nl(str(game, 171, 30, PURCHASE_PASSWORD_TEXT.wrong)).replace(/\n+/g, '\n'));
      win.once('close', () => resolve('ok'));
      win.control('btn_yes').onClick(() => win.close('yes'));
      win.find('btn_exit')?.onClick(() => win.close('no'));
      game.uiwin.openWindow(win);
    });
  }
  async function buyCart() {
    if (!st.cart.length) { notice(game, str(game, 220, 34, 'The cart is empty.')); return false; }
    // D-Shop coins: unlimited unless the GM coin editor set a balance (game.gm.dshopBalance, "Not enough DKC." 101:3)
    if (!cfg.vip && cartTotal() > balance()) { notice(game, game.uiwin?.strings?.get?.({ group: 'SYSTEM', cate: 101, code: 3 }) || 'Not enough DKC.'); return false; }
    if (await confirmCart() !== 'yes') return false;
    const n = st.cart.length, total = cartTotal();
    if(online()) {
      // SHOP-WINDOWS: the account password after the confirmation (ui_buypasswordwnd.txt); the host checks it and a wrong one
      // cancels the order (ui_errpwd.txt). A host that asks for it anyway (account unknown here) gets the window and one retry.
      const lastError=since=>{const e=game.network?._lastCommandError;return e&&e.at>=since?e.message:null;};
      const send=password=>game.network?.action('dshopbuy',{vip:!!cfg.vip,cart:st.cart.map(entry=>({product:entry.product,itemIndex:entry.itemIndex})),...(password!=null?{password}:{})});
      let password=await passwordWanted()?await passwordBox():undefined;
      if(password===null)return false;
      let since=Date.now(),result=await send(password);
      if(!result&&password===undefined&&lastError(since)===PURCHASE_PASSWORD_TEXT.enter){password=await passwordBox();if(password===null)return false;since=Date.now();result=await send(password);}
      if(!result){if(password!=null&&lastError(since)===PURCHASE_PASSWORD_TEXT.wrong)await wrongPasswordBox();return false;}
      st.cart=[];renderCart();renderCells();game.events?.emit?.('cashinventory',{reason:'server'});game.events?.emit?.('inventory',{reason:'server'});
      say(game,str(game,900,6,'Your purchase is stored in the Cash Inventory.'),'item');
      await resultBox(n,total,'Your server purchase is stored in the Cash Inventory.');return true;
    }
    if (!cfg.vip) game.gm?.dshopSpend?.(total);
    for (const e of st.cart) {
      api.cash.add(e.itemIndex, e.units, { shop: cfg.name, price: e.price });
      bought()[e.itemIndex] = (bought()[e.itemIndex] || 0) + 1;
      game.events?.emit?.('dshop:buy', { vip: !!cfg.vip, itemIndex: e.itemIndex, count: e.units, price: e.price });
    }
    game.save.dshopSpent = (game.save.dshopSpent || 0) + (cfg.vip ? 0 : total);
    st.cart = [];
    renderCart();
    renderCells();
    say(game, str(game, 900, 6, 'The item you purchsed will be stored in the Cash Inventory.'), 'item');
    await resultBox(n, total, `${n > 1 ? str(game, 220, 33, 'Cart item (%u/%u)\nis successfully purchased.').replace('%u', n).replace('%u', n) : str(game, 220, 32, 'Item is successfully purchased.')}\n${str(game, 900, 6, '')}`);
    return true;
  }
  /** cashshop/ui_cashgiftconfirmwnd.txt: 220:44 "[ %s ] will receive %s from you. Will you continue?" */
  async function giftConfirm(targetName) {
    const cw = await game.uiwin.create('game2/cashshop/ui_cashgiftconfirmwnd.txt', { modal: true, remember: false, disposeOnClose: true });
    return new Promise((resolve) => {
      const first = itemInfo(game, st.cart[0].itemIndex).name + (st.cart.length > 1 ? ` (+${st.cart.length - 1})` : '');
      cw.control('lbl_text').setRichText(str(game, 220, 44, GIFT_TEXT.confirm).replace('%s', targetName).replace('%s', first));
      cw.once('close', r => resolve(r === 'yes'));
      cw.control('btn_confirm').onClick(() => cw.close('yes'));
      cw.control('btn_cancel').onClick(() => cw.close('no'));
      game.uiwin.openWindow(cw);
    });
  }
  /** Online Send as Gift (server/world/dshop-gifts.mjs): the host resolves the recipient, charges DKC with the same account
   *  password as Buy and escrows the gift for the recipient's Cash Inventory (171:43). Nothing changes locally until it commits. */
  async function giftOnline(typed) {
    const named = giftRecipient(typed);
    if (named.error) { notice(game, named.error === GIFT_TEXT.noName ? str(game, 220, 35, GIFT_TEXT.noName) : nl(str(game, 171, 29, GIFT_TEXT.noCharacter))); return false; }
    if (!(await giftConfirm(named.name))) return false;
    const lastError=since=>{const e=game.network?._lastCommandError;return e&&e.at>=since?e.message:null;};
    const send=password=>game.network?.action('dshopgift',{operation:'send',cart:st.cart.map(entry=>({product:entry.product,itemIndex:entry.itemIndex})),recipient:named.name,
      revision:Number(game.network?.mail?.revision)||0,requestId:randomUUID(),...(password!=null?{password}:{})});
    let password=await passwordWanted()?await passwordBox():undefined;
    if(password===null)return false;
    let since=Date.now(),result=await send(password);
    if(!result&&password===undefined&&lastError(since)===PURCHASE_PASSWORD_TEXT.enter){password=await passwordBox();if(password===null)return false;since=Date.now();result=await send(password);}
    if(!result){if(password!=null&&lastError(since)===PURCHASE_PASSWORD_TEXT.wrong)await wrongPasswordBox();else if(lastError(since)===GIFT_TEXT.noCharacter)notice(game,nl(str(game,171,29,GIFT_TEXT.noCharacter)));return false;}
    st.cart=[];renderCart();renderCells();
    notice(game, nl(str(game, 171, 43, GIFT_TEXT.sent)));
    return true;
  }
  async function giftCart() {
    if (!st.cart.length) { notice(game, str(game, 220, 34, 'The cart is empty.')); return false; }
    if (cfg.vip) { notice(game, GIFT_TEXT.vip); return false; }   // the original VIP window has no gift button
    const win = await game.uiwin.create('game2/cashshop/ui_cashgiftwnd.txt', { modal: true, remember: false, disposeOnClose: true });
    const name = await new Promise((resolve) => {
      const edit = win.control('edit_text');
      win.once('close', r => resolve(r === 'yes' ? String(edit.getValue?.() || '').trim() : null));
      win.control('btn_confirm').onClick(() => win.close('yes'));
      win.control('btn_cancel').onClick(() => win.close('no'));
      edit.on('enter', () => win.close('yes'));
      game.uiwin.openWindow(win);
      setTimeout(() => edit.focus?.(), 0);
    });
    if (name == null) return false;
    if (!name) { notice(game, str(game, 220, 35, 'No character name is entered.')); return false; }
    if (online()) return giftOnline(name);
    const { listCharacters, saveCharacter } = await import('../../game/save.js');
    const target = listCharacters().find(c => String(c.name).toLowerCase() === name.toLowerCase());
    if (!target) { notice(game, nl(str(game, 171, 29, 'No such character exists.'))); return false; }
    if (!(await giftConfirm(target.name))) return false;
    if (target.id === game.save.id) {
      for (const e of st.cart) api.cash.add(e.itemIndex, e.units, { shop: cfg.name, gift: game.save.name, price: e.price });
    } else if (api.cash.external && api.cash.makeFor) {
      target.cashInv ||= [];
      for (const e of st.cart) {
        const single = maxStackOf(game, e.itemIndex) <= 1;
        for (let k = 0; k < (single ? e.units : 1); k++) { const inst = api.cash.makeFor(e.itemIndex, single ? 1 : e.units, game.save.name); if (inst) { inst.gift = game.save.name; target.cashInv.push(inst); } }
      }
      saveCharacter(target);
    } else {
      target.cashInventory ||= [];
      for (const e of st.cart) target.cashInventory.push({ id: `ci${Date.now().toString(36)}${Math.random().toString(36).slice(2, 7)}`, itemIndex: e.itemIndex, count: e.units, period: Number(itemInfo(game, e.itemIndex).period) || 0, bought: Date.now(), buyer: game.save.name, gift: game.save.name, shop: cfg.name, price: e.price });
      saveCharacter(target);
    }
    st.cart = [];
    renderCart();
    notice(game, nl(str(game, 171, 43, 'The gift has been sent to the recipient entered above.\nGifts are sent to the Cash Inventory.')));
    return true;
  }

  // ---------------------------------------------------------------------------------------------- search
  function setupSearch(win) {
    const c0 = win.control('combobox_item_0'), c1 = win.control('combobox_item_1'), c2 = win.control('combobox_item_2');
    if (cfg.vip) c0.setItems([{ text: str(game, 214, 1, 'Total'), value: -1 }, ...D().vipShop.tabs.map((t, i) => ({ text: str(game, 214, i + 1, t.name), value: t.main })).slice(1)]);
    else c0.setItems([{ text: str(game, 210, 1, 'ALL'), value: -1 }, ...D().tabs.map((t, i) => ({ text: t.main === WING_SHOP_MAIN ? t.name : str(game, 210, i + 2, t.name), value: t.main }))]);
    const subsFor = (main) => {
      if (cfg.vip || main < 0) return [{ text: str(game, 210, 1, 'ALL'), value: -1 }];
      const t = D().tabs.find(x => x.main === main);
      const all = main === 2 ? str(game, 211, 1, 'ALL') : main === 3 ? str(game, 212, 1, 'ALL') : str(game, 220, 1, 'All');
      return [{ text: all, value: -1 }, ...t.subs.filter(s => !s.legacyOnly && s.products > 0).map(s => ({ text: s.name, value: s.sub }))];
    };
    c1.setItems(subsFor(-1));
    c0.on('change', () => c1.setItems(subsFor(Number(c0.getValue()))));
    c2.setItems([{ text: str(game, 213, 1, 'ALL'), value: -1 }, ...classOptions()]);
    const edit = win.control('edit_search');
    st.clearWingFilters = () => {
      edit.setValue?.(''); c0.select(D().tabs.findIndex(t => t.main === WING_SHOP_MAIN) + 1);
      c1.setItems(subsFor(WING_SHOP_MAIN)); c2.select(0);
    };
    const run = () => {
      const q = String(edit.getValue?.() || '').trim().toLowerCase();
      const main = Number(c0.getValue() ?? -1), sub = Number(c1.getValue() ?? -1), cls = Number(c2.getValue() ?? -1);
      st.wingSearch = !cfg.vip && main === WING_SHOP_MAIN;
      if (st.wingSearch) for (const t of tabs()) win.control(PANELS[t.key]).setVisible(t.main === WING_SHOP_MAIN);
      const seen = new Set();
      st.search = products().filter(p => {
        if (main >= 0 && p.main !== main) return false;
        if (sub >= 0 && p.sub !== sub) return false;
        if (cls >= 0 && !classOk(p.items[0], cls)) return false;
        if (q && !p.items.some(i => itemInfo(game, i).name.toLowerCase().includes(q))) return false;
        const key = p.items.join(',');           // HOT repeats products of the other tabs
        if (seen.has(key)) return false;
        seen.add(key);
        return true;
      });
      st.spage = 0;
      win.control('pan_page').hide();
      win.control('pan_searchpage').show();
      for (const t of tabs()) win.control(t.button).setChecked(false);
      renderCells();
    };
    win.control('btn_search').onClick(run);
    edit.on('enter', run);
    win.control('btn_refresh').onClick(() => {
      edit.setValue?.(''); c0.select(0); c1.setItems(subsFor(-1)); c2.select(0);
      selectTab(st.main, st.sub);
    });
  }

  // ---------------------------------------------------------------------------------------------- preview
  async function embedPreview(win) {
    const r = await game.uiwin.loadScript('game2/cashshop/ui_previewwnd.txt');
    if (st.win !== win) return;
    const spec = r?.windows?.[0];
    if (!spec) return;
    const host = win.root;
    const pspec = { type: 'panel', id: 'pan_previewwnd', rect: [753, 157, 231, 282], anchor: null, layer: 60, enable: true, visible: true, intersect: true, images: [], titles: [], props: {}, children: spec.children || [] };
    const c = createControl(win, pspec, host);
    host.children.push(c); host.el.appendChild(c.el);
    win._indexControls();
    c.layout(host.box);
    st.preview = new ModelPreview(game, 231, 236);
    const bg = win.control('pan_bg');
    bg.setIcon({ canvas: st.preview.canvas });
    bg._icon && (bg._icon.style.height = '236px');
    win.control('btn_leftrot').onClick(() => { st.preview.auto = false; st.preview.rotate(-0.3); });
    win.control('btn_rightrot').onClick(() => { st.preview.auto = false; st.preview.rotate(0.3); });
    win.control('pan_mark').hide();
  }
  async function showPreview(i) {
    if (!st.preview) return;
    let item = i;
    const box = D().boxes?.[i];
    if (box) { const pick = box.list?.find(([x]) => [4, 5, 10, 2].includes(Number(itemInfo(game, x).type))); if (pick) item = pick[0]; }
    st.previewItem = item;
    st.preview.auto = true;
    await st.preview.show(item);
  }

  return {
    async prewarm() {
      syncIconGeneration();
      await loadDshop();
      if (!D()) return;
      const first = tabs()[0];
      if (!first) return;
      const sub = first.subs.find(s => !s.legacyOnly)?.sub ?? 0;
      // UI-PRELOAD-NOLAG: first tab pages 1-3 + first wings page join the loading barrier (priority 0).
      const ids = products().filter(p => p.main === first.main && (cfg.vip || p.sub === sub))
        .slice(0, PER_PAGE * 3).map(p => p.items[0]).filter(i => i != null);
      const wings = cfg.vip ? [] : products().filter(p => p.main === WING_SHOP_MAIN && isNativeWing(p.items[0]))
        .slice(0, PER_PAGE * 2).map(p => p.items[0]);
      // Also barrier-warm page 1 of every other main tab so tab switches open hot.
      const tabHomes = cfg.vip ? [] : tabs().slice(1).flatMap(t => {
        const s = t.subs.find(x => !x.legacyOnly)?.sub ?? 0;
        return products().filter(p => p.main === t.main && p.sub === s).slice(0, PER_PAGE).map(p => p.items[0]);
      }).slice(0, PER_PAGE * 6);
      for (let attempt = 0; attempt < 3; attempt++) {
        syncIconGeneration();
        const generation = iconGeneration();
        await assets.page([...ids, ...wings, ...tabHomes], { priority: 0 });
        if (generation === iconGeneration()) break;
      }
      // ICON-PRELOAD (2026-10-30): EVERY product of every authored tab / sub-tab / page is retained (the pool used to keep 72).
      // The source-native Wings tab lists ~9,400 original wings (1,000+ pages): its first WING_WARM_PAGES pages are
      // warmed the same way; deeper Wings pages keep the existing page-ahead prefetch (baking all of them would cost
      // ~1 hour of GPU time and hundreds of MB of disk and memory).
      // Products whose icon an earlier session already baked (persistent icon cache, items/icon-disk-cache.js) are
      // read from disk inside the loading barrier, so any page opens complete. The rest bake one at a time after the
      // world is shown (paused while a map loads; PERF-CROWD2 burst concern) and are persisted for the next start.
      // Kill switch for the disk pass: globalThis.__dekaronNoShopDiskWarm = true
      // Per Wings sub-tab, in the order its pages list them (listNow).
      const wingWarm = cfg.vip ? [] : tabs().filter(t => t.main === WING_SHOP_MAIN).flatMap(t => t.subs.filter(s => !s.legacyOnly)
        .flatMap(s => products().filter(p => p.main === t.main && p.sub === s.sub).slice(0, PER_PAGE * WING_WARM_PAGES)));
      const all = [...new Set([...products().filter(p => cfg.vip || p.main !== WING_SHOP_MAIN), ...wingWarm]
        .map(p => p.items?.[0]).filter(i => i != null))];
      assets.limit = Math.max(assets.limit, all.length + PER_PAGE * 2);
      const report = { products: all.length, cached: 0, missing: 0, ms: 0 };
      if (globalThis.__dekaronNoShopDiskWarm !== true && game.items?.icons?.diskOnly) {
        const t0 = performance.now(), generation = iconGeneration(), todo = all.filter(i => !assets.now(i));
        let cursor = 0;
        const worker = async () => {
          while (cursor < todo.length && generation === iconGeneration()) {
            const i = todo[cursor++];
            try { const icon = await prepareProduct(i, 'disk'); if (icon && !assets.now(i)) { assets.cache.set(i, icon); report.cached++; } } catch { /* idle bake below */ }
          }
        };
        await Promise.all(Array.from({ length: 8 }, worker));
        report.ms = Math.round(performance.now() - t0);
      }
      report.missing = all.filter(i => !assets.now(i)).length;
      game[cfg.vip ? '_vipIconWarm' : '_dshopIconWarm'] = report;
      if (!st.idleBake && report.missing) {
        st.idleBake = true;
        const idleBake = () => {
          const missing = all.filter(i => !assets.now(i));
          let k = 0;
          const next = async () => {
            if (k >= missing.length) { st.idleBake = false; return; }
            if (game._loadingMap || !game._worldReady) { setTimeout(next, 250); return; }
            const i = missing[k++];
            if (!assets.now(i)) await assets.get(i, { priority: 4 }).catch(() => null);
            setTimeout(next, 32);
          };
          void next();
        };
        afterWorldReady(game, idleBake, { timeout: 4000 });
      }
    },
    open: (arg) => game.uiwin.open(cfg.name, arg),
    get cart() { return st.cart; },
    addToCart: (i) => { const p = products().find(x => x.items.includes(Number(i))) || { id: -1, items: [Number(i)] }; return addToCart(p, Number(i)); },
    buyCart, giftCart, selectTab, state: st, priceOf,
  };
}

// ============================================================================================ box info window
/** cashshop/ui_cashshopboxinfownd.txt: the contents of a box / package (view, or select mode for Ex-Boxes). */
export function createBoxInfo(game) {
  const st = { win: null, item: null, box: null, entries: [], top: 0, sel: new Set(), mode: 'view', resolve: null, preview: null, hot: -1 };
  const ROWS = 15;
  game.uiwin.registerWindow('shops.boxinfo', {
    script: 'game2/cashshop/ui_cashshopboxinfownd.txt',
    modal: true,
    create(win) {
      st.win = win;
      for (let k = 0; k < ROWS; k++) {
        const cb = win.control(`check_item_${k}`);
        cb.on('change', (v) => {
          const i = st.top + k;
          if (st.mode !== 'select') { cb.setChecked(false); showDetail(i); return; }
          if (v) { if (st.sel.size >= (st.box?.give || 1)) { cb.setChecked(false); return; } st.sel.add(i); } else st.sel.delete(i);
          updInfo();
          showDetail(i);
        });
        cb.on('over', () => showDetail(st.top + k));
        cb.setTooltip(() => { const e = st.entries[st.top + k]; return e ? itemTooltip(game, e[0], e[1] > 1 ? [`x${e[1]}`] : []) : null; });
      }
      const sc = win.control('body_scroll');
      sc.on?.('change', v => { st.top = v; render(); });
      win.control('pan_body').el?.addEventListener('wheel', (e) => { e.preventDefault(); st.top = Math.max(0, Math.min(Math.max(0, st.entries.length - ROWS), st.top + Math.sign(e.deltaY))); render(); }, { passive: false });
      win.control('check_detail').on('change', (v) => win.control('pan_preview').setVisible(!!v));
      win.control('btn_ok').onClick(() => win.close('close'));   // the X of pan_top
      win.control('btn_use').onClick(() => { if (st.mode === 'select' && st.sel.size === (st.box?.give || 1)) win.close('use'); });
      win.control('btn_cancel').onClick(() => win.close('cancel'));
      st.preview = new ModelPreview(game, 336, 336);
      // pan_preview_bg (common #65500: no sprite, the client's 3D render slot) sits under pan_effect_bg (Itemchoice
      // #21, a stretched 2x2 black); the client draws the model after the UI, so the view goes on top of the black
      win.control('pan_effect_bg').setIcon({ canvas: st.preview.canvas });
      win.control('pan_mark').hide();
    },
    onOpen(win) {
      win.control('lbl_title').setText(cleanMarkup(str(game, 81, 86, 'Item List')).trim());
      win.control('pan_preview').setVisible(win.control('check_detail').isChecked());
      render();
    },
    onClose(win, result) {
      const r = st.resolve; st.resolve = null;
      if (r) r(result === 'use' ? [...st.sel].sort((a, b) => a - b).map(i => st.entries[i]) : null);
    },
    update(win, dt) { if (win.control('pan_preview').isVisible()) st.preview.tick(dt); },
  });
  function entriesOf(i) {
    const D = T.dshop || {};
    const box = D.boxes?.[i];
    if (box) {
      const list = box.list || [];
      if (box.type === 5 && D.randomBoxes?.keyBoxes?.[i]) return { box, entries: D.randomBoxes.keyBoxes[i].entries.map(([x, n, c]) => [x, n, c / 10000]) };
      if (box.type === 1 || box.type === 2 || box.type === 4) {
        let prev = 0;
        return { box, entries: list.map(([x, n, cum]) => { const p = (cum - prev) / 100; prev = cum; return [x, n, p]; }) };
      }
      return { box, entries: list.map(([x, n]) => [x, n, null]) };
    }
    const pk = D.packages?.[i];
    if (pk) return { box: { type: 8, give: pk.items.length }, entries: pk.items.map(([x, n]) => [x, n, null]) };
    return null;
  }
  function updInfo() {
    const w = st.win, b = st.box;
    const give = b?.give || 1;
    let text;
    if (b?.type === 0 && give < st.entries.length) text = str(game, 600, 1, 'Select <COUNT> / <MAXCOUNT>').replace('<COUNT>', st.sel.size).replace('<MAXCOUNT>', give);
    else if (b?.type === 1 || b?.type === 2 || b?.type === 4 || b?.type === 5) text = str(game, 600, 2, 'Randomly distribute <COUNT> items from the list below').replace(/<COUNT>/g, give);
    else text = str(game, 81, 85, 'To receive all the items below, click confirm.').replace(/\s*\n\s*/g, ' ');   // every entry
    w.control('lbl_info').setRichText(cleanMarkup(`${itemInfo(game, st.item).name}\n${text}`));
    w.control('lbl_check_info').setText(st.mode === 'select' ? `${st.sel.size} / ${give}` : '');
    w.control('btn_use').setEnabled(st.mode === 'select' && st.sel.size === give);
  }
  function render() {
    const w = st.win;
    if (!w) return;
    const max = Math.max(0, st.entries.length - ROWS);
    st.top = Math.min(st.top, max);
    const sc = w.control('body_scroll');
    sc.setRange?.(max, ROWS); sc.setValue?.(st.top);
    sc.setVisible(max > 0);
    for (let k = 0; k < ROWS; k++) {
      const cb = w.control(`check_item_${k}`);
      const i = st.top + k;
      const e = st.entries[i];
      cb.setVisible(!!e);
      if (!e) continue;
      const pct = e[2] != null ? `  ${e[2].toFixed(T.dshop?.randomBoxes?.showDigit?.[st.item] ?? 2)}%` : '';
      cb.setText(`${itemInfo(game, e[0]).name}${e[1] > 1 ? ` x${e[1]}` : ''}${pct}`);
      cb.setEnabled(true);
      cb.setChecked(st.sel.has(i));
    }
    const sel = st.mode === 'select';
    w.control('btn_use').setVisible(sel);
    w.control('btn_cancel').setVisible(sel);
    w.control('btn_close').setVisible(!sel);
    updInfo();
  }
  function showDetail(i) {
    const e = st.entries[i];
    if (!e || st.hot === i) return;
    st.hot = i;
    st.win.control('lbl_preview').setText(itemInfo(game, e[0]).name);
    st.preview.show(e[0]);
  }
  return {
    /** Show a box's contents. opts.select = true: the player picks `give` entries; resolves them (or null). */
    async show(itemIndex, { select = false } = {}) {
      await loadDshop();
      const r = entriesOf(Number(itemIndex));
      if (!r) return null;
      await Promise.all([Number(itemIndex), ...r.entries.map(e => e[0])].map(i => itemInfoFull(game, i)));
      st.item = Number(itemIndex); st.box = r.box; st.entries = r.entries; st.top = 0; st.sel = new Set(); st.hot = -1;
      st.mode = select ? 'select' : 'view';
      const p = new Promise(res => { st.resolve = res; });
      await game.uiwin.open('shops.boxinfo');
      if (st.entries[0]) showDetail(0);
      return p;
    },
    has: (i) => !!(T.dshop?.boxes?.[i] || T.dshop?.packages?.[i]),
    /** [itemIndex, count, percent|null] rows of a box / package (null when it is neither); shared with the VIP box info. */
    entries: (i) => entriesOf(Number(i)),
  };
}

// ============================================================================================ VIP box info window
/** vipshop/ui_vipshopboxinfownd.txt (SHOP-WINDOWS): the VIP shop's own box contents window, view only. 10 rows (check_item_0..9)
 *  scrolled by body_scroll / the wheel, lbl_info = box name + its distribution line (600:1 / 600:2 / 81:85 as the D-Shop window),
 *  the preview pane always shown (no Detail checkbox in this script): the hovered entry's model, btn_leftrot / btn_rightrot rotate,
 *  btn_camera_plus / btn_camera_minus zoom; btn_my_chara 'My Character' (2000:83) toggles the player's own body (wearing the hovered
 *  entry when it is a costume or a wing; other entries leave the current look); btn_ok 'Ok' (2000:15) closes. */
export function createVipBoxInfo(game, boxInfo) {
  const st = { win: null, item: null, box: null, entries: [], top: 0, hot: -1, last: 0, preview: null, body: null, mine: false };
  const ROWS = VIP_BOX_ROWS;
  game.uiwin.registerWindow('shops.vipboxinfo', {
    script: SHOP_WINDOW_SCRIPTS.vipBoxInfo,
    modal: true,
    create(win) {
      repairNativeShopStateArt(win.control('body_scroll_downbtn'),'vipDown',atlas.table);
      st.win = win;
      for (let k = 0; k < ROWS; k++) {
        const cb = win.control(`check_item_${k}`);
        cb.on('over', () => showDetail(st.top + k));
        cb.setTooltip(() => { const e = st.entries[st.top + k]; return e ? itemTooltip(game, e[0], e[1] > 1 ? [`x${e[1]}`] : []) : null; });
      }
      const sc = win.control('body_scroll');
      sc.on?.('change', v => { st.top = v; render(); });
      win.control('pan_body').el?.addEventListener('wheel', (e) => { e.preventDefault(); st.top = Math.max(0, Math.min(Math.max(0, st.entries.length - ROWS), st.top + Math.sign(e.deltaY))); render(); }, { passive: false });
      win.control('btn_ok').onClick(() => win.close('close'));
      win.control('btn_my_chara').onClick(() => { st.mine = !st.mine; win.control('btn_my_chara').setChecked?.(st.mine); st.hot = -1; showDetail(st.last); });
      st.preview = new ModelPreview(game, 336, 336);
      win.control('pan_effect_bg').setIcon({ canvas: st.preview.canvas });
      win.control('pan_mark').hide();
      const turn = d => { if (st.mine && st.body) st.body.rotate(d); else { st.preview.auto = false; st.preview.rotate(d); } };
      const zoom = f => { if (st.mine && st.body) st.body.setZoom(st.body.zoom * f); else st.preview.setZoom(st.preview.zoom * f); };
      win.control('btn_leftrot').onClick(() => turn(-0.3));
      win.control('btn_rightrot').onClick(() => turn(0.3));
      win.control('btn_camera_plus').onClick(() => zoom(PREVIEW_ZOOM.step));
      win.control('btn_camera_minus').onClick(() => zoom(1 / PREVIEW_ZOOM.step));
      // The script nests these four buttons beside pan_effect_bg (layer 1000) inside pan_preview_bg, so their own layers (100/110)
      // would put them under the model canvas; the client draws them over the preview, so lift them above it.
      for (const id of ['btn_leftrot', 'btn_rightrot', 'btn_camera_plus', 'btn_camera_minus']) { const el = win.control(id).el; if (el) el.style.zIndex = '1001'; }
    },
    onOpen(win) {
      win.control('lbl_title').setText(cleanMarkup(str(game, 81, 86, 'Item List')).trim());
      render();
    },
    onClose() { st.mine = false; st.body?.clear(); },
    update(win, dt) { if (st.mine) st.body?.tick(dt); else st.preview.tick(dt); },
  });
  function updInfo() {
    const b = st.box, give = b?.give || 1;
    let text;
    if (b?.type === 0 && give < st.entries.length) text = str(game, 600, 1, 'Select <COUNT> / <MAXCOUNT>').replace('<COUNT>', 0).replace('<MAXCOUNT>', give);
    else if (b?.type === 1 || b?.type === 2 || b?.type === 4 || b?.type === 5) text = str(game, 600, 2, 'Randomly distribute <COUNT> items from the list below').replace(/<COUNT>/g, give);
    else text = str(game, 81, 85, 'To receive all the items below, click confirm.').replace(/\s*\n\s*/g, ' ');
    st.win.control('lbl_info').setRichText(cleanMarkup(`${itemInfo(game, st.item).name}\n${text}`));
  }
  function render() {
    const w = st.win;
    if (!w) return;
    const max = Math.max(0, st.entries.length - ROWS);
    st.top = Math.min(st.top, max);
    const sc = w.control('body_scroll');
    sc.setRange?.(max, ROWS); sc.setValue?.(st.top);
    sc.setVisible(max > 0);
    for (let k = 0; k < ROWS; k++) {
      const cb = w.control(`check_item_${k}`), e = st.entries[st.top + k];
      cb.setVisible(!!e);
      if (!e) continue;
      const pct = e[2] != null ? `  ${e[2].toFixed(T.dshop?.randomBoxes?.showDigit?.[st.item] ?? 2)}%` : '';
      cb.setText(`${itemInfo(game, e[0]).name}${e[1] > 1 ? ` x${e[1]}` : ''}${pct}`);
      cb.setChecked(st.top + k === st.last);
    }
    updInfo();
  }
  async function showDetail(i) {
    const e = st.entries[i];
    if (!e || st.hot === i) return;
    st.hot = i; st.last = i;
    st.win.control('lbl_preview').setText(st.mine ? (game.save?.name || '') : itemInfo(game, e[0]).name);
    render();
    const panel = st.win.control('pan_effect_bg');
    if (!st.mine) { st.body?.clear(); panel.setIcon({ canvas: st.preview.canvas }); await st.preview.show(e[0]); return; }
    const sys = game.mounts?.system;
    if (!sys || !game.player) return;
    if (!st.body) { const { ModelPreview: BodyPreview } = await import('../mounts/ui-util.js'); st.body = new BodyPreview(sys, panel, { w: 336, h: 336 }); }
    panel.setIcon(null);
    const cls = Number(game.player.classIndex ?? 0);
    await st.body.showPlayer({ costume: sys.data?.costume?.(e[0], cls) ? e[0] : null, wing: sys.data?.wing?.(e[0]) ? e[0] : null });
  }
  return {
    /** Show a box's contents in the VIP window (falls back to nothing when the item is not a box / package). */
    async show(itemIndex) {
      await loadDshop();
      const r = boxInfo.entries(Number(itemIndex));
      if (!r) return null;
      await Promise.all([Number(itemIndex), ...r.entries.map(e => e[0])].map(i => itemInfoFull(game, i)));
      st.item = Number(itemIndex); st.box = r.box; st.entries = r.entries; st.top = 0; st.hot = -1; st.last = 0; st.mine = false;
      await game.uiwin.open('shops.vipboxinfo');
      if (st.entries[0]) await showDetail(0);
      return st.entries;
    },
    get state() { return st; },
  };
}

// ============================================================================================ probability window
/** notice/ui_randomboxinfownd.txt: "Probability Info" of every D-Shop random box (randomboxinfo.csv show digits). */
export function createProbability(game) {
  const st = { win: null, rows: [], top: 0, lines: [] };
  const ROW = 20;
  game.uiwin.registerWindow('shops.probability', {
    script: 'game2/notice/ui_randomboxinfownd.txt',
    modal: true,
    async create(win) {
      st.win = win;
      await loadDshop();
      const D = T.dshop;
      const boxes = Object.keys(D.randomBoxes?.showDigit || {}).map(Number);
      await Promise.all(boxes.map(i => itemInfoFull(game, i)));
      const lines = [];
      for (const b of boxes) {
        const digits = D.randomBoxes.showDigit[b] ?? 2;
        let entries = null;
        const kb = D.randomBoxes.keyBoxes?.[b];
        if (kb) entries = kb.entries.map(([x, n, c]) => [x, n, c / 10000]);
        else if (D.boxes?.[b]) { let prev = 0; entries = (D.boxes[b].list || []).map(([x, n, cum]) => { const p = (cum - prev) / 100; prev = cum; return [x, n, p]; }); }
        if (!entries?.length) continue;
        await Promise.all(entries.map(e => itemInfoFull(game, e[0])));
        entries.forEach((e, k) => lines.push({ box: k === 0 ? itemInfo(game, b).name : '', name: itemInfo(game, e[0]).name, count: e[1], pct: `${e[2].toFixed(digits)}%`, first: k === 0 }));
      }
      st.lines = lines;
      const content = win.control('pan_content');
      content.setRect(0, 0, 810, lines.length * ROW + 10);
      const tpl = { item: win.control('lbl_item'), res: win.control('lbl_resultitem'), cnt: win.control('lbl_count'), pct: win.control('lbl_percent'), line: win.control('pan_hline_long'), sub: win.control('pan_hline') };
      // Index each completed time slice once, not the entire growing window after every clone.
      // Keep native row order/IDs, and restore a complete index even if construction fails.
      let sliceStarted = performance.now();
      let disposed = false;
      const onDispose = () => { disposed = true; };
      win.on('dispose', onDispose);
      try { for (let k = 0; k < lines.length; k++) {
        if (disposed) throw new Error('Probability panel was disposed during preparation.');
        const l = lines[k];
        const y = k * ROW;
        const opts = { parent: content, reindex: false };
        if (l.first && k > 0) tpl.line.cloneAs(`_r${k}`, { ...opts, x: 8, y: y - 1 });
        else if (k > 0) tpl.sub.cloneAs(`_r${k}`, { ...opts, x: 302, y: y - 1 });
        tpl.item.cloneAs(`_r${k}`, { ...opts, x: 0, y: y + 4 }).setText(l.box);
        tpl.res.cloneAs(`_r${k}`, { ...opts, x: 300, y: y + 4 }).setText(l.name);
        tpl.cnt.cloneAs(`_r${k}`, { ...opts, x: 600, y: y + 4 }).setText(String(l.count));
        tpl.pct.cloneAs(`_r${k}`, { ...opts, x: 670, y: y + 4 }).setText(l.pct);
        if (k + 1 < lines.length && performance.now() - sliceStarted >= PREBUILD.budgetMs) {
          win._indexControls();
          await nextTask();
          sliceStarted = performance.now();
        }
      } } finally { win.off('dispose', onDispose); win._indexControls(); }
      const vis = Math.floor(523 / ROW);
      const sc = win.control('list_scroll');
      sc.setRange?.(Math.max(0, lines.length - vis), vis);
      const setTop = (t) => { st.top = Math.max(0, Math.min(Math.max(0, lines.length - vis), t)); content.setRect(0, -st.top * ROW, 810, lines.length * ROW + 10); sc.setValue?.(st.top); };
      sc.on?.('change', v => setTop(v));
      const cbg = win.control('pan_content_bg');
      cbg.setClip?.(true);
      if (cbg.el) cbg.el.style.zIndex = '400';   // the rows draw over the frame art (notice_2 pieces come later in the script)
      win.el.addEventListener('wheel', (e) => { e.preventDefault(); setTop(st.top + Math.sign(e.deltaY) * 3); }, { passive: false });
    },
  });
  return { open: () => game.uiwin.open('shops.probability') };
}

export function createCashShops(game, api) {
  const dshop = makeCashShop(game, api, { name: 'dshop', script: 'game2/cashshop/ui_cashshopwnd_search.txt', menuButton: 'btn_cash', vip: false });
  const vip = makeCashShop(game, api, {
    name: 'vipshop', script: 'game2/vipshop/ui_vipshopwnd_search.txt', menuButton: 'btn_vipshop', vip: true,
    vipSubs: { 0: 'btn_sub_all', 1: 'btn_premium_equipment_all', 2: 'btn_unique_all' },
    vipPanels: { 0: 'pan_all', 1: 'pan_premium_equipment', 2: 'pan_unique' },
  });
  return { dshop, vip };
}
