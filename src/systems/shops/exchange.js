// Item-for-item trade windows opened by NPC jobs (docs/formats/shops.md 3.3):
//   exchange       EXCHANGE (35)          exchangeshop/ui_exchangeshopwnd.txt + ui_confirmwnd.txt  (shops.json exchanges)
//   exchangestore  EXCHANGE_STORE (166)   store/ui_exchangestorewnd.txt                            (exchangeStores)
//   materialex     EXCHANGE_MATERIAL (168) itemupgrade/ui_materialexchangewnd.txt                  (materialExchanges)
import { T, itemInfo, itemInfoFull, itemIcon, itemTooltip, bag, dil, addDil, str, say, notice, fmtNum, COLORS, uiSound } from './common.js';

const msgX = (game, code, fb = '') => str(game, 2006, code, T.shops?.messages?.exchange?.[code] ?? fb);
const msgS = (game, code, fb = '') => str(game, 340, code, T.shops?.messages?.store?.[code] ?? fb);

/** Pay `count` units choosing among alternative currencies (either pays; mixing allowed, main first). */
function payAlt(game, items, count) {
  const have = items.map(i => bag.count(game, i));
  if (have.reduce((a, b) => a + b, 0) < count) return false;
  let left = count;
  items.forEach((i, k) => { const n = Math.min(have[k], left); if (n > 0) { bag.remove(game, i, n); left -= n; } });
  return left <= 0;
}
const altCount = (game, items) => items.reduce((a, i) => a + bag.count(game, i), 0);

export function createExchanges(game, api) {
  let pending = false;
  const shared = () => game.save?.authority === 'server';
  const identity = npc => Number(npc?.npcIndex ?? npc?.index ?? npc?.def?.index);
  async function purchase(kind, catalog, row, count, npc) {
    if (pending) return null;
    const network=game.network;
    if (!network?.action) { notice(game, 'Shared world connection is unavailable.'); return null; }
    pending=true;
    try { return await network.action('exchangebuy', {kind,catalog:Number(catalog),row,count,npcIndex:identity(npc)}); }
    finally { pending=false; }
  }
  // =========================================================================================== exchange center
  const ex = { win: null, id: null, def: null, npc: null };
  game.uiwin.registerWindow('exchange', {
    script: 'game2/exchangeshop/ui_exchangeshopwnd.txt',
    create(win) {
      ex.win = win;
      const menu = win.control('list_menu'), price = win.control('list_price');
      // the two lists scroll and select together (list_price owns the visible scroll bar)
      price.scroll?.on('change', v => { if (menu.top !== v) menu.setTop(v); });
      menu.el?.addEventListener('wheel', () => setTimeout(() => price.setTop(menu.top), 0));
      price.el?.addEventListener('wheel', () => setTimeout(() => menu.setTop(price.top), 0));
      const pick = (i) => { menu.select(i); price.select(i); const e = ex.def?.entries?.[i]; if (e) trade(e); };
      menu.on('select', i => pick(i));
      price.on('select', i => pick(i));
      for (const l of [menu, price]) {
        l.el?.addEventListener('pointermove', (ev) => {
          const r = l.el.getBoundingClientRect();
          const k = Math.floor((ev.clientY - r.top) / (game.uiwin.scale || 1) / l.rowH) + l.top;
          const e = ex.def?.entries?.[k];
          if (e && ex._tipRow !== k) { ex._tipRow = k; game.uiwin.tooltips.show(entryTip(e), ev.clientX, ev.clientY); }
          if (!e) { ex._tipRow = -1; game.uiwin.tooltips.hide(); }
        });
        l.el?.addEventListener('pointerleave', () => { ex._tipRow = -1; game.uiwin.tooltips.hide(); });
      }
    },
    async onOpen(win, arg) {
      ex.id = String(arg?.exchange);
      ex.def = T.shops?.exchanges?.[ex.id] || null;
      ex.npc = arg?.npc || null;
      if (!ex.def) { win.close(); notice(game, msgX(game, 31, 'There are no items available for sale.')); return; }
      win.control('lbl_title').setText(str(game, 2006, Number(ex.id), ex.def.name) || ex.def.name);
      await Promise.all([ex.def.priceItem, ...(ex.def.priceItemAlt || []), ...ex.def.entries.map(e => e[0])].map(i => itemInfoFull(game, i)));
      const pays = [ex.def.priceItem, ...(ex.def.priceItemAlt || [])];
      win.control('lbl_pay_name').setText(pays.map(i => itemInfo(game, i).name).join(' / '));
      fill();
    },
    onClose() { game.uiwin.tooltips.hide(); },
  });
  function fill() {
    const w = ex.win, d = ex.def;
    if (!w || !d) return;
    w.control('list_menu').setItems(d.entries.map(([give, giveCount]) => ({ text: `${itemInfo(game, give).name}${giveCount > 1 ? ` x${giveCount}` : ''}` })));
    w.control('list_price').setItems(d.entries.map(([, , priceCount]) => ({ text: fmtNum(priceCount) })));
  }
  function entryTip([give, giveCount, priceCount, take]) {
    const d = ex.def;
    const pays = [d.priceItem, ...(d.priceItemAlt || [])];
    const have = altCount(game, pays);
    const lines = [{ text: str(game, 340, 35, 'Materials'), color: COLORS.GOLD },
      { text: `${pays.map(i => itemInfo(game, i).name).join(' / ')} ${fmtNum(have)} / ${fmtNum(priceCount)}`, color: have >= priceCount ? COLORS.GREEN : COLORS.RED }];
    if (take) { const h = bag.count(game, take); lines.push({ text: `${itemInfo(game, take).name} ${h} / 1`, color: h >= 1 ? COLORS.GREEN : COLORS.RED }); }
    if (giveCount > 1) lines.unshift({ text: `x${giveCount}`, color: COLORS.WHITE });
    return itemTooltip(game, give, lines);
  }
  async function trade([give, giveCount, priceCount, take]) {
    if(pending)return;
    const d = ex.def;
    const npc=ex.npc,id=ex.id,lease=game.network?.token;
    const pays = [d.priceItem, ...(d.priceItemAlt || [])];
    const r = await api.windows.exchangeWindow({ name: `${itemInfo(game, give).name}${giveCount > 1 ? ` x${giveCount}` : ''}`, payName: pays.map(i => itemInfo(game, i).name).join(' / '), payCount: priceCount });
    if (r !== 'yes') return;
    if(shared()){
      if(d!==ex.def||npc!==ex.npc||lease!==game.network?.token||!ex.win?.isOpen)return;
      const row=d.entries.findIndex(e=>e[0]===give&&e[1]===giveCount&&e[2]===priceCount&&e[3]===take);
      await purchase('exchange',id,row,1,npc);return;
    }
    if (take && bag.count(game, take) < 1) { notice(game, `${msgX(game, 12, 'Something is missing.')} (${itemInfo(game, take).name})`); return; }
    if (altCount(game, pays) < priceCount) { notice(game, msgX(game, 13)); return; }
    if (!bag.canAdd(game, give, giveCount)) { uiSound(game, 'lackOfSpace'); notice(game, msgX(game, 11)); return; }
    if (take && !bag.remove(game, take, 1)) { notice(game, msgX(game, 10)); return; }
    if (!payAlt(game, pays, priceCount)) { notice(game, msgX(game, 10)); return; }
    bag.add(game, give, giveCount, { from: 'exchange' });
    say(game, msgX(game, 15, 'Items Exchanged - <ITEMNAME>').replace('<ITEMNAME>', itemInfo(game, give).name), 'item');
    game.events?.emit?.('shop:exchange', { exchange: ex.id, itemIndex: give, count: giveCount });
  }

  // =========================================================================================== exchange store
  const PER_PAGE = 12, COLS = 4, CELL_X = 17, CELL_Y = 10, STRIDE_X = 192, STRIDE_Y = 172;
  const es = { win: null, stores: [], cur: null, page: 0, npc: null, cells: [], tabs: [], tok: 0 };
  const limits = () => ((game.save.shopLimits ||= {}));
  game.uiwin.registerWindow('exchangestore', {
    script: 'game2/store/ui_exchangestorewnd.txt',
    create(win) {
      es.win = win;
      win.control('btn_prev').onClick(() => { if (es.page > 0) { es.page--; renderStore(); } });
      win.control('btn_next').onClick(() => { if (es.page < pages() - 1) { es.page++; renderStore(); } });
      const help = win.control('tb_help');
      win.control('btn_help').onClick(() => { help.setVisible(!help.isVisible()); });
      help.setText([
        str(game, 340, 32, 'Item Exchange'),
        `${str(game, 340, 33, 'QTY per item')} / ${str(game, 340, 34, 'Total Req.')}`,
        str(game, 340, 38, '* Exchange unavailable. Limit reached.'),
      ].join('\n'));
      win.control('pan_chart').hide();
      // build the 12 goods cells from the hidden template
      const tpl = win.control('pan_goods');
      for (let k = 0; k < PER_PAGE; k++) {
        const c = tpl.cloneAs(`_${k}`, { x: CELL_X + (k % COLS) * STRIDE_X, y: CELL_Y + Math.floor(k / COLS) * STRIDE_Y, visible: false });
        const cell = { root: c, k };
        cell.goods = win.control(`item_goods_${k}`); cell.name = win.control(`lbl_goods_${k}`); cell.lim = win.control(`pan_Limits_${k}`);
        cell.limLbl = win.control(`lbl_LimitCount_${k}`); cell.mtrl = win.control(`item_mtrl_${k}`); cell.num = win.control(`lbl_mtrlnum_${k}`);
        cell.btn = win.control(`btn_exchange_${k}`);
        cell.btn.onClick(() => { if (cell.entry) buyStore(cell.entry); });
        cell.goods.setTooltip(() => cell.entry ? itemTooltip(game, cell.entry[0], [{ text: `x${cell.entry[3] || 1}`, color: COLORS.WHITE }]) : null);
        cell.mtrl.setTooltip(() => cell.entry ? itemTooltip(game, cell.entry[1], [{ text: `${fmtNum(altCount(game, needItems(cell.entry)))} / ${fmtNum(cell.entry[2])}`, color: COLORS.GOLD }]) : null);
        es.cells.push(cell);
      }
      win.control('item_mymtrl').setTooltip(() => es.cur ? itemTooltip(game, es.cur.currency) : null);
      win.control('btn_tap').hide();
    },
    onOpen(win, arg) {
      es.npc = arg?.npc || null;
      // every exchange store of this NPC is a tab; the clicked one is selected
      const npcStores = (T.shops?.npcs?.[arg?.npcIndex]?.jobs || []).filter(j => j.store != null).map(j => String(j.store));
      const ids = npcStores.length ? npcStores : [String(arg?.store)];
      if (!ids.includes(String(arg?.store)) && arg?.store != null) ids.unshift(String(arg.store));
      es.stores = ids.map(id => ({ id, ...(T.shops?.exchangeStores?.[id] || {}) })).filter(s => s.entries);
      if (!es.stores.length) { win.close(); notice(game, msgX(game, 31, 'There are no items available for sale.')); return; }
      es.cur = es.stores.find(s => s.id === String(arg?.store)) || es.stores[0];
      es.page = 0;
      buildTabs();
      renderStore();
    },
    onClose() { game.uiwin.tooltips.hide(); },
  });
  function buildTabs() {
    const w = es.win;
    for (const t of es.tabs) t.remove();
    es.tabs = [];
    const tpl = w.control('btn_tap');
    es.stores.forEach((s, i) => {
      const b = tpl.cloneAs(`_${i}`, { x: 17 + i * 124, y: 41 });
      b.setText(itemInfo(game, s.currency).name || s.name);
      b.onClick(() => { es.cur = s; es.page = 0; renderStore(); });
      es.tabs.push(b);
    });
  }
  const pages = () => Math.max(1, Math.ceil((es.cur?.entries?.length || 0) / PER_PAGE));
  const needItems = (e) => [e[1], ...(e[6] || [])];
  async function renderStore() {
    const w = es.win, s = es.cur;
    if (!w || !s) return;
    const tok = ++es.tok;
    es.tabs.forEach((b, i) => b.setChecked(es.stores[i] === s));
    w.control('lbl_title').setText(`${str(game, 341, 151, 'Exchange Shop')} - ${itemInfo(game, s.currency).name || s.name}`);
    const list = s.entries.slice(es.page * PER_PAGE, es.page * PER_PAGE + PER_PAGE);
    await Promise.all([s.currency, ...list.flatMap(e => [e[0], e[1]])].map(i => itemInfoFull(game, i)));
    if (tok !== es.tok) return;
    es.cells.forEach((cell, k) => {
      const e = list[k];
      cell.entry = e || null;
      cell.root.setVisible(!!e);
      if (!e) return;
      const [item, , needCount, returnCount, limit] = e;
      cell.name.setText(`${itemInfo(game, item).name}${returnCount > 1 ? ` x${returnCount}` : ''}`);
      cell.num.setText(fmtNum(needCount)).setTextColor(altCount(game, needItems(e)) >= needCount ? 'ffffffff' : 'ffff4040');
      const used = limits()[`${s.id}:${item}`] || 0;
      cell.lim.setVisible(limit > 0);
      if (limit > 0) cell.limLbl.setText(`${used} / ${limit}`);
      cell.btn.setEnabled(!(limit > 0 && used >= limit));
      cell.goods.setIcon(null); cell.mtrl.setIcon(null);
      itemIcon(game, item, 60, 60).then(ic => { if (tok === es.tok && cell.entry === e) cell.goods.setIcon(ic, { inset: 1 }); });
      itemIcon(game, e[1], 33, 33).then(ic => { if (tok === es.tok && cell.entry === e) cell.mtrl.setIcon(ic); });
    });
    w.control('lbl_page').setText(`${es.page + 1} / ${pages()}`);
    w.control('btn_prev').setEnabled(es.page > 0);
    w.control('btn_next').setEnabled(es.page < pages() - 1);
    w.control('lbl_mymtrlnum').setText(fmtNum(bag.count(game, s.currency)));
    itemIcon(game, s.currency, 33, 33).then(ic => { if (tok === es.tok) w.control('item_mymtrl').setIcon(ic); });
  }
  async function buyStore(e) {
    if(pending)return;
    const s = es.cur;
    const npc=es.npc,lease=game.network?.token;
    const [item, , needCount, returnCount, limit] = e;
    const key = `${s.id}:${item}`;
    const used = limits()[key] || 0;
    if (limit > 0 && used >= limit) { notice(game, msgS(game, 38)); return; }
    const pays = needItems(e);
    const have = altCount(game, pays);
    const maxN = Math.max(0, Math.min(limit > 0 ? limit - used : 9999, Math.floor(have / needCount)));
    if (maxN < 1) { notice(game, msgS(game, 36)); return; }
    let n = 1;
    if (maxN > 1) {
      n = await api.windows.askQuantity({ itemIndex: item, name: itemInfo(game, item).name, unitPrice: needCount, funds: have, max: maxN, currency: itemInfo(game, s.currency).name });
      if (!n) return;
    } else {
      const r = await api.windows.exchangeWindow({ name: `${itemInfo(game, item).name}${returnCount > 1 ? ` x${returnCount}` : ''}`, payName: itemInfo(game, e[1]).name, payCount: needCount });
      if (r !== 'yes') return;
    }
    if(shared()){
      if(s!==es.cur||npc!==es.npc||lease!==game.network?.token||!es.win?.isOpen)return;
      if(await purchase('store',s.id,s.entries.indexOf(e),n,npc))renderStore();return;
    }
    if (altCount(game, pays) < needCount * n) { notice(game, msgS(game, 36)); return; }
    if (!bag.canAdd(game, item, returnCount * n)) { uiSound(game, 'lackOfSpace'); notice(game, msgS(game, 37)); return; }
    if (!payAlt(game, pays, needCount * n)) { notice(game, msgS(game, 36)); return; }
    bag.add(game, item, (returnCount || 1) * n, { from: 'exchangestore' });
    if (limit > 0) limits()[key] = used + n;
    say(game, str(game, 2006, 27, 'You have exchanged %s [%s] items.').replace('%s', itemInfo(game, item).name).replace('%s', fmtNum((returnCount || 1) * n)), 'item');
    game.events?.emit?.('shop:exchange', { store: s.id, itemIndex: item, count: (returnCount || 1) * n });
    renderStore();
  }

  // =========================================================================================== material exchange
  const mx = { win: null, def: null, sel: null, npc: null, count: 1 };
  game.uiwin.registerWindow('materialex', {
    script: 'game2/itemupgrade/ui_materialexchangewnd.txt',
    create(win) {
      mx.win = win;
      win.control('multi_tree_material').on('select', (n) => { if (n?.data) selectMat(n.data); });
      const edit = win.control('edit_count');
      edit.on('change', () => { mx.count = clampCount(Number(edit.getValue?.()) || 0); showMat(); });
      win.control('btn_add_max').onClick(() => { mx.count = maxCount(); edit.setValue?.(String(mx.count)); showMat(); });
      win.control('btn_add_reset').onClick(() => { mx.count = 1; edit.setValue?.('1'); showMat(); });
      win.control('btn_material').onClick(() => doMat());
      win.control('lbl_tag_material_item').setText('');
    },
    async onOpen(win, arg) {
      mx.def = T.shops?.materialExchanges?.[String(arg?.material)] || null;
      mx.npc = arg?.npc || null;
      mx.sel = null; mx.count = 1;
      if (!mx.def) { win.close(); return; }
      await Promise.all(mx.def.entries.flatMap(e => [e[0], e[2], e[3], e[5], e[6]]).filter(Boolean).map(i => itemInfoFull(game, i)));
      win.control('multi_tree_material').setNodes(mx.def.entries.map((e, i) => ({ text: `${itemInfo(game, e[0]).name}${e[1] > 1 ? ` x${e[1]}` : ''}`, state: 'sub', data: { e, i } })));
      showMat();
    },
  });
  const mats = (e) => {
    const [, , evB, evT, evC, mB, mT, mC] = e;
    const out = [];
    if (mC > 0) out.push({ items: [mB, mT].filter(Boolean), count: mC });
    if (evC > 0) out.push({ items: [evB, evT].filter(Boolean), count: evC, event: true });
    return out;
  };
  function maxCount() {
    if (!mx.sel) return 1;
    const e = mx.sel.e;
    let n = 9999;
    for (const m of mats(e)) n = Math.min(n, Math.floor(altCount(game, m.items) / m.count));
    if (e[8] > 0) n = Math.min(n, Math.floor(dil(game) / e[8]));
    return Math.max(1, n);
  }
  const clampCount = (n) => Math.max(1, Math.min(9999, Math.floor(n) || 1));
  function selectMat(d) { mx.sel = d; mx.count = 1; mx.win.control('edit_count').setValue?.('1'); showMat(); }
  function showMat() {
    const w = mx.win;
    if (!w) return;
    const sel = mx.sel;
    w.control('pan_start_bg_material').setVisible(!sel);
    w.control('pan_no_item').setVisible(!sel);
    w.control('lbl_item_desc').setText(sel ? '' : str(game, 350, 198, 'Select an item from the left.'));
    w.control('pan_resultItem').setVisible(!!sel);
    w.control('pan_material').setVisible(!!sel);
    w.control('pan_material_count').setVisible(!!sel);
    w.control('pan_change_cost').setVisible(!!sel && sel.e[8] > 0);
    w.control('btn_material').setEnabled(!!sel);
    for (let i = 0; i < 7; i++) w.control(`pan_line${i}`).setVisible(false);
    if (!sel) { w.control('lbl_desc').setText(''); w.control('lbl_desc_event').setText(''); return; }
    const e = sel.e;
    const n = mx.count;
    const up = w.control('item_upgrade'), res = w.control('item_result');
    const main = mats(e)[0];
    itemIcon(game, main ? main.items[0] : e[0], 64, 64).then(ic => up.setIcon(ic, { inset: 1 }));
    itemIcon(game, e[0], 64, 64).then(ic => res.setIcon(ic, { inset: 1 }));
    up.setTooltip(() => main ? itemTooltip(game, main.items[0]) : null);
    res.setTooltip(() => itemTooltip(game, e[0], [{ text: `x${e[1] * n}`, color: COLORS.WHITE }]));
    const lines = w.controls(/^pan_line\d$/);
    mats(e).forEach((m, k) => {
      const line = lines[k];
      if (!line) return;
      line.setVisible(true);
      const have = altCount(game, m.items);
      const need = m.count * n;
      const lbl = line.control('lbl_line_title');
      lbl?.setText(`${m.items.map(i => itemInfo(game, i).name).join(' / ')}  ${fmtNum(have)} / ${fmtNum(need)}`);
      lbl?.setTextColor(have >= need ? 'ffffffff' : 'ffff4040');
      const slot = line.control('item_resource');
      itemIcon(game, m.items[0], 32, 32).then(ic => slot?.setIcon(ic));
      slot?.setTooltip(() => itemTooltip(game, m.items[0]));
    });
    w.control('txt_change_req_money').setText(`${fmtNum(e[8] * n)} Dil`).setTextColor(dil(game) >= e[8] * n ? 'ffffffff' : 'ffff4040');
    w.control('lbl_desc_max').setText(str(game, 350, 174, '(Maximum %u)').replace('%u', fmtNum(maxCount())));
    // lbl_desc / lbl_desc_event share their rows with the count panel (original rects): the material lines above
    // already name everything, so they stay empty while the count panel is shown
    w.control('lbl_desc').setText('');
    w.control('lbl_desc_event').setText('');
  }
  async function doMat() {
    if(pending)return;
    const sel = mx.sel;
    if (!sel) { notice(game, str(game, 350, 171, 'Target item does not exist.')); return; }
    const e = sel.e, n = mx.count;
    if(shared()){
      const id=Object.entries(T.shops?.materialExchanges||{}).find(([,def])=>def===mx.def)?.[0];
      if(await purchase('material',id,sel.i,n,mx.npc)){mx.count=1;mx.win.control('edit_count').setValue?.('1');showMat();}return;
    }
    for (const m of mats(e)) if (altCount(game, m.items) < m.count * n) { notice(game, str(game, 350, 172, 'There is not enough material to exchange.')); return; }
    if (dil(game) < e[8] * n) { uiSound(game, 'lackOfDil'); notice(game, str(game, 350, 197, 'You do not have enough DIL.')); return; }
    if (!bag.canAdd(game, e[0], e[1] * n)) { uiSound(game, 'lackOfSpace'); notice(game, str(game, 350, 183, 'Item usage failed due to insufficient inventory.')); return; }
    for (const m of mats(e)) payAlt(game, m.items, m.count * n);
    if (e[8] > 0) addDil(game, -e[8] * n);
    bag.add(game, e[0], e[1] * n, { from: 'materialex' });
    say(game, str(game, 350, 170, "You've exchanged materials."), 'item');
    game.events?.emit?.('shop:exchange', { material: true, itemIndex: e[0], count: e[1] * n });
    mx.count = 1; mx.win.control('edit_count').setValue?.('1');
    showMat();
  }

  // refresh the open windows when the bag changes
  game.events?.on?.('inventory', () => {
    if (es.win?.isOpen) renderStore();
    if (mx.win?.isOpen) showMat();
  });

  return {
    openExchange: (exchange, npc) => game.uiwin.open('exchange', { exchange, npc }),
    openExchangeStore: (store, npc, npcIndex) => game.uiwin.open('exchangestore', { store, npc, npcIndex }),
    openMaterial: (material, npc) => game.uiwin.open('materialex', { material, npc }),
  };
}
