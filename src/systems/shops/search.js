// The Middleman's player market (JobType 46 "[Broker] I want to use the Consignment Shop", docs/formats/shops.md 3.4):
//   search       store/ui_new_storesearch_2.txt   the item category tree (shops_search.json taxonomy = shoplist.dat),
//                                                 name / grade / level / reinforcement filters, the result board
//   consignment  store/ui_storeconsignment_2.txt  my registered items; Register -> store/ui_storeconsignregist_2.txt
//   receipt      store/ui_receiptwnd_2.txt        sold / expired registrations: receive the DIL (and the deposit)
// Solo: there are no other players, so the market holds only the player's own registrations (a seller cannot buy
// his own items, 2010/81). Registered items are bought by the town's NPC buyers after a while when the unit price is
// reasonable (at most 4 x the NPC sell price: within 10 min; at most 10 x: within 2 h; else never) - a solo stand-in
// for the other players (documented). Registration: 1,000,000 DIL deposit (2009/104), 5 % fee (2010/17), up to
// 5 items (the consignment skill's cap, 2010/67), 7 days; cancelling before the end keeps the deposit (2010/69).
// Online (shared world): the same windows run on network.consignment (src/systems/network/consignment.js ->
// server/world/consignment.mjs). The host owns the listings, the escrowed items, the receipts, the bag and the DIL;
// other players' listings appear on the search board with their seller and can be bought (store/ui_storebuyconfirm_2).
// There are no NPC buyers online, and nothing here touches the local save.
import { T, loadSearch, itemInfo, itemInfoFull, setFootprintIcon, itemTooltip, bag, dil, addDil, str, say, notice, confirmBox, fmtNum, COLORS } from './common.js';

import {repairConsignmentCancel} from './native-consignment-cancel.js';
import {installConsignmentDetails} from './consignment-details.js';

const DEPOSIT = 1000000, FEE = 5, MAX_LISTINGS = 5, PERIOD_DAYS = 7, RECEIPT_DAYS = 15;
const S9 = (game, c, fb = '') => str(game, 2009, c, T.search?.strings?.searchstore?.[2009]?.[c] ?? fb);
const S10 = (game, c, fb = '') => str(game, 2010, c, T.search?.strings?.consignment?.[2010]?.[c] ?? fb);
const cleanMsg = s => String(s || '').replace(/^\[message\]\s*/i, '').replace(/<\/?center>/g, '');

export function createSearch(game, api) {
  const M = () => ((game.save.consign ||= { listings: [], receipts: [] }));
  const st = { page: 'search', pos: null, npc: null, remote: false, results: [], node: null };
  // shared world: the host-backed market (null offline = the solo market above)
  const online = () => !!game.network?.active;
  const B = () => (online() ? game.network.consignment || null : null);
  const blocked = () => { if (!online() || B()?.available()) return false; notice(game, 'This server has no durable consignment service.'); return true; };
  const P = () => B()?.policy?.() || { deposit: DEPOSIT, fee: FEE, max: MAX_LISTINGS, days: PERIOD_DAYS, receiptDays: RECEIPT_DAYS };
  const myListings = () => (online() ? B()?.listings?.() || [] : M().listings);
  const myReceipts = () => (online() ? B()?.receipts?.() || [] : M().receipts);
  const entryOf = (l) => l.entry || l.item || null;
  const openDetails = installConsignmentDetails(game, {
    info: index => itemInfoFull(game, index),
    icon: (slot, index) => setFootprintIcon(game, slot, index),
    tooltip: row => itemTooltip(game, row.itemIndex, [], entryOf(row)),
    funds: () => dil(game), format: fmtNum,
    available: () => online() && !blocked(),
    purchase: row => openBuy(row),
  });

  // ------------------------------------------------------------------------------------------ market clock
  function tick() {
    if (online()) return;   // the host sweeps expiries
    const m = M(), now = Date.now();
    for (let i = m.listings.length - 1; i >= 0; i--) {
      const l = m.listings[i];
      if (l.sellAt && now >= l.sellAt) {
        m.listings.splice(i, 1);
        const sales = Math.floor(l.unit * l.count * (100 - FEE) / 100);
        m.receipts.push({ id: l.id, itemIndex: l.itemIndex, count: l.count, sales, deposit: l.deposit, at: now, kind: 'sold' });
        say(game, `${itemInfo(game, l.itemIndex).name}: ${S10(game, 4, 'Sold Items')} (+${fmtNum(sales)} DIL)`, 'item');
      } else if (now >= l.expires) {
        m.listings.splice(i, 1);
        m.receipts.push({ id: l.id, itemIndex: l.itemIndex, count: l.count, sales: 0, deposit: l.deposit, at: now, kind: 'expired', entry: l.entry });
        say(game, cleanMsg(S10(game, 72, 'Registered Sales have expired')), 'sys');
      }
    }
    m.receipts = m.receipts.filter(r => now - r.at < RECEIPT_DAYS * 86400000 || r.kind === 'expired');
  }
  setInterval(() => { if (game.save) tick(); }, 15000);

  // ------------------------------------------------------------------------------------------ the three pages
  const pages = { search: 'shops.storesearch', consignment: 'shops.consignment', receipt: 'shops.receipt' };
  function tabs(win) {
    win.control('btn_tap_search').onClick(() => go('search'));
    win.control('btn_tap_consignment').onClick(() => go('consignment'));
    win.control('btn_tap_receipt').onClick(() => go('receipt'));
    win.on('move', (p) => { st.pos = p; });
  }
  async function go(page) {
    const cur = game.uiwin.window(pages[st.page]);
    const pos = cur?.isOpen ? { x: cur.box.x, y: cur.box.y } : st.pos;
    if (cur?.isOpen && st.page !== page) cur.close('tab');
    st.page = page;
    const w = await game.uiwin.open(pages[page]);
    if (pos && w) w.setPosition(pos.x, pos.y, false);
  }
  const money = (w) => w.control('lbl_Money').setDil(dil(game));

  // ---- search
  game.uiwin.registerWindow(pages.search, {
    script: 'game2/store/ui_new_storesearch_2.txt',
    async create(win) {
      tabs(win);
      await loadSearch();
      const tree = win.control('multi_tree');
      // the whole shoplist.dat tree (24 355 nodes; only open branches are laid out)
      const mk = (n, depth = 0) => ({ text: n.n, state: depth === 0 ? 'head' : n.c ? 'sub' : 'finish', data: n, children: n.c ? n.c.map(c => mk(c, depth + 1)) : undefined, open: false, selectable: true });
      tree.setNodes((T.search?.taxonomy || []).map(n => mk(n)));
      tree.on('select', (node) => { if (!node) return; st.node = node.data; win.control('lbl_search_node').setText(pathOf(node)); if (node.children && !node.open) tree.toggle(node, true); runSearch(win); });
      const grade = win.control('com_itemgrade');
      grade.setItems([S9(game, 800, 'All Grades'), 'Normal', 'Magic', 'Noble', 'Divine'].map((t, i) => ({ text: t, value: i - 1 })));
      win.control('btn_search').onClick(() => runSearch(win));
      win.control('edit_search').on('enter', () => runSearch(win));
      win.control('btn_init').onClick(() => {
        for (const id of ['edit_search', 'edit_minlevel', 'edit_maxlevel', 'edit_minreinforce', 'edit_maxreinforce']) win.control(id).setValue?.('');
        grade.select(0); st.node = null; win.control('lbl_search_node').setText(''); runSearch(win, true);
      });
      const board = win.control('freeboard');
      board.on('cellclick', (i, ci) => {
        const r = st.results[i];
        if (!r || ci !== board.cols.length - 1) return;
        if (online() && !r.mine) { openDetails(r); return; }
        notice(game, S10(game, 81, 'Item selected is your registered item.'));
      });
      board.on('select', (i) => { const r = st.results[i]; if (r) game.uiwin.tooltips.show(itemTooltip(game, r.itemIndex, [`${S9(game, 11, 'Seller :')} ${online() ? r.sellerName || '' : game.save?.name || ''}`], online() ? entryOf(r) : undefined), innerWidth / 2, innerHeight / 2); });
      win.control('btn_guide').setTooltip(() => S9(game, 104, ''));
    },
    onOpen(win, arg) {
      if (arg?.npc !== undefined) st.npc = arg.npc;
      win.control('btn_tap_search').setChecked(true);
      money(win);
      runSearch(win, true);
    },
  });
  function pathOf(node) { const p = []; for (let n = node; n; n = n.parent) p.unshift(n.text); return p.join(' > '); }
  function itemsUnder(n, out = new Set()) { if (!n) return out; for (const i of n.i || []) out.add(Number(i)); for (const c of n.c || []) itemsUnder(c, out); return out; }
  async function runSearch(win, quiet = false) {
    tick();
    const q = String(win.control('edit_search').getValue?.() || '').trim().toLowerCase();
    if (q && q.length < 2) { notice(game, S9(game, 27, 'Type 2 letters or more to search.')); return; }
    const minL = Number(win.control('edit_minlevel').getValue?.()) || 0, maxL = Number(win.control('edit_maxlevel').getValue?.()) || 999;
    const allowed = st.node ? itemsUnder(st.node) : null;
    const list = [];
    let source = M().listings;
    if (online()) {
      if (blocked()) return;
      source = await B().search();
      if (!source) { if (!quiet) notice(game, S9(game, 25, 'Search has failed.')); return; }
    }
    for (const l of source) {
      const it = await itemInfoFull(game, l.itemIndex);
      if (allowed && !allowed.has(l.itemIndex)) continue;
      if (q && !it.name.toLowerCase().includes(q)) continue;
      const lv = Number(it.reqLv) || 0;
      if (lv < minL || lv > maxL) continue;
      list.push(l);
    }
    st.results = list;
    win.control('freeboard').setRows(list.map(l => ({ cells: [itemInfo(game, l.itemIndex).name, String(itemInfo(game, l.itemIndex).reqLv || 1), fmtNum(l.count), fmtNum(l.unit), fmtNum(l.unit * l.count), { text: S9(game, 4, 'Buy'), color: online() && !l.mine ? '#ffffff' : '#808080' }], data: l })));
    win.control('lbl_Boardtitle').setText(list.length ? `${list.length} ${S9(game, 22, 'items were searched.')}` : S9(game, 7, 'Display search result'));
    if (!list.length && !quiet) notice(game, S9(game, 21, 'Nothing matches the search criteria.'));
  }

  // ---- consignment
  game.uiwin.registerWindow(pages.consignment, {
    script: 'game2/store/ui_storeconsignment_2.txt',
    create(win) {
      tabs(win);
      win.control('btn_regist').onClick(() => openRegister());
      win.control('btn_init').onClick(() => renderConsign(win));
      win.control('freeboard').on('cellclick', async (i, ci) => {
        const l = myListings()[i];
        if (!l || ci !== win.control('freeboard').cols.length - 1) return;
        const r = await confirmBox(game, cleanMsg(S10(game, 69, 'Do you want to cancel the registration?')), S10(game, 68, 'Cancel'));
        if (r !== 'yes') return;
        if (online()) {
          if (blocked()) return;
          if (await B().cancel(l.id)) notice(game, S10(game, 57, 'Cancellation Successful'));
          renderConsign(win);
          return;
        }
        if (!bag.canAdd(game, l.itemIndex, l.count)) { notice(game, S10(game, 56, 'Insufficient inventory space')); return; }
        M().listings.splice(M().listings.indexOf(l), 1);
        bag.add(game, l.itemIndex, l.count, { from: 'consignment', grade: l.entry?.grade, options: l.entry?.options });
        notice(game, S10(game, 57, 'Cancellation Successful'));
        renderConsign(win);
      });
      win.control('btn_guide').setTooltip(() => S9(game, 104, ''));
    },
    onOpen(win) { win.control('btn_tap_consignment').setChecked(true); renderConsign(win); },
  });
  function renderConsign(win) {
    tick();
    money(win);
    const now = Date.now();
    win.control('freeboard').setRows(myListings().map(l => ({ cells: [
      S10(game, 25, '%d days').replace('%d', Math.max(0, Math.ceil((l.expires - now) / 86400000))),
      itemInfo(game, l.itemIndex).name, String(itemInfo(game, l.itemIndex).reqLv || 1), fmtNum(l.count), fmtNum(l.unit), fmtNum(l.unit * l.count),
      { text: S10(game, 11, 'Cancel'), color: '#ffffff' }] })));
    win.control('lbl_search_node').setText(`${myListings().length} / ${P().max}`);
  }

  // ---- registration
  const reg = { win: null, entry: null };
  game.uiwin.registerWindow('shops.consignregist', {
    script: 'game2/store/ui_storeconsignregist_2.txt',
    modal: true,
    create(win) {
      reg.win = win;
      const slot = win.control('select_item');
      slot.acceptDrop({ referenceSource:'bag',referenceLabel:'Shop item search',accept: d => !!api.bagEntryOf(d), drop: d => { setEntry(api.bagEntryOf(d)); return true; } });
      slot.setTooltip(() => (reg.entry ? itemTooltip(game, reg.entry.itemIndex, [], reg.entry) : S10(game, 14, 'Item Registration')));
      slot.onClick(() => pickFromBag());
      win.control('edit_price').on('change', () => upd());
      win.control('checkbox').setChecked(true);
      win.control('btn_regist').onClick(() => doRegister());
      win.find('btn_cancel')?.onClick(() => win.close('cancel'));
      repairConsignmentCancel(win);
    },
    onOpen(win, arg) { setEntry(arg?.entry || null); win.control('edit_price').setValue?.(''); upd(); },
  });
  function setEntry(e) {
    reg.entry = e;
    const w = reg.win;
    if (!w) return;
    w.control('lbl_item').setText(e ? `${itemInfo(game, e.itemIndex).name}${e.count > 1 ? ` x${e.count}` : ''}` : S10(game, 14, 'Item Registration'));
    setFootprintIcon(game, w.control('select_item'), e ? e.itemIndex : null);
    upd();
  }
  /** Without a drag: the first tradable bag entry (click again cycles). */
  function pickFromBag() {
    const list = bag.entries(game).filter(e => e && itemInfo(game, e.itemIndex).trade !== 0);
    if (!list.length) { notice(game, S10(game, 55, 'There are no item(s).')); return; }
    const i = reg.entry ? (list.indexOf(reg.entry) + 1) % list.length : 0;
    setEntry(list[i]);
  }
  function upd() {
    const w = reg.win;
    if (!w) return;
    const unit = Math.floor(Number(String(w.control('edit_price').getValue?.() || '').replace(/[^0-9]/g, '')) || 0);
    const count = Math.max(1, Number(reg.entry?.count) || 1);
    const total = unit * count;
    w.control('lbl_taxtitle').setText(S10(game, 17, 'Fee (<COUNT>%)').replace('<COUNT>', P().fee));
    w.control('lbl_tax').setText(fmtNum(Math.ceil(total * P().fee / 100)));
    w.control('lbl_totalprice').setText(fmtNum(total));
    w.control('lbl_regprice').setText(fmtNum(P().deposit));
    w.control('lbl_curMycash').setDil(dil(game));
    w.control('btn_regist').setEnabled(!!reg.entry && unit > 0);
  }
  async function doRegister() {
    const w = reg.win, e = reg.entry;
    if (!e) return;
    const it = await itemInfoFull(game, e.itemIndex);
    const unit = Math.floor(Number(String(w.control('edit_price').getValue?.() || '').replace(/[^0-9]/g, '')) || 0);
    if (!(unit > 0)) { notice(game, S10(game, 58, 'Please select the amount.')); return; }
    if (online()) {
      if (blocked()) return;
      if (myListings().length >= P().max) { notice(game, S10(game, 67, 'User has exceeded the maximum number of registrations')); return; }
      if (dil(game) < P().deposit) { notice(game, S10(game, 70, 'Insufficient Deposit')); return; }
      if (!e.uid) { notice(game, S10(game, 65, 'This item cannot be registered')); return; }
      const done = await B().register(e.uid, Math.max(1, Number(e.count) || 1), unit);
      if (!done) return;
      w.close('done');
      notice(game, S10(game, 64, 'Item registration is completed.'));
      const cw = game.uiwin.window(pages.consignment);
      if (cw?.isOpen) renderConsign(cw);
      return;
    }
    if (unit > 2000000000) { notice(game, S10(game, 59, 'The desired amount has exceeded the limit.')); return; }
    if (M().listings.length >= MAX_LISTINGS) { notice(game, S10(game, 67, 'User has exceeded the maximum number of registrations')); return; }
    if (Number(it.type) === 0 && /quest/i.test(it.name) || Number(it.eventType) > 0) { notice(game, S10(game, 60, 'Quest/Event items cannot be registered.')); return; }
    if (e.bound || it.trade === 0) { notice(game, S10(game, 61, 'Binded Items cannot be registered')); return; }
    if (e.expires || Number(it.period) > 0) { notice(game, S10(game, 62, 'Periodical/Timed Items cannot be registered')); return; }
    if (dil(game) < DEPOSIT) { notice(game, S10(game, 70, 'Insufficient Deposit')); return; }
    const count = Math.max(1, Number(e.count) || 1);
    if (!bag.removeEntry(game, e)) { notice(game, S10(game, 65, 'This item cannot be registered')); return; }
    addDil(game, -DEPOSIT);
    const now = Date.now();
    const npcUnit = api.store.sellQuote({ ...e, count: 1 }).price || 1;
    const ratio = unit / Math.max(1, npcUnit);
    const delay = ratio <= 4 ? (2 + Math.random() * 8) * 60000 : ratio <= 10 ? (20 + Math.random() * 100) * 60000 : null;
    M().listings.push({ id: `cs${now.toString(36)}`, itemIndex: Number(e.itemIndex), count, unit, deposit: DEPOSIT, listedAt: now, expires: now + PERIOD_DAYS * 86400000, sellAt: delay ? now + delay : null, entry: { ...e } });
    w.close('done');
    notice(game, S10(game, 64, 'Item registration is completed.'));
    const cw = game.uiwin.window(pages.consignment);
    if (cw?.isOpen) renderConsign(cw);
  }
  function openRegister(entry = null) {
    if (blocked()) return;
    if (myListings().length >= P().max) { notice(game, S10(game, 67, 'User has exceeded the maximum number of registrations')); return; }
    game.uiwin.open('shops.consignregist', { entry });
  }

  // ---- receipt
  game.uiwin.registerWindow(pages.receipt, {
    script: 'game2/store/ui_receiptwnd_2.txt',
    create(win) {
      tabs(win);
      win.control('btn_init').onClick(() => renderReceipt(win));
      win.control('btn_receivepage').onClick(async () => {
        if (online()) { if (!blocked() && myReceipts().length && await B().receive(true)) notice(game, S10(game, 54, 'Item has been received successfully')); renderReceipt(win); return; }
        for (const r of M().receipts.slice()) receive(r, true); renderReceipt(win);
      });
      win.control('freeboard').on('cellclick', async (i, ci) => { const r = myReceipts()[i]; if (r && ci === win.control('freeboard').cols.length - 1) { await receive(r); renderReceipt(win); } });
      win.control('btn_guide').setTooltip(() => S9(game, 104, ''));
    },
    onOpen(win) { win.control('btn_tap_receipt').setChecked(true); renderReceipt(win); },
  });
  async function receive(r, quiet = false) {
    if (online()) {
      if (blocked()) return false;
      const done = await B().receive(r.id);
      if (done && !quiet) notice(game, S10(game, 54, 'Item has been received successfully'));
      return !!done;
    }
    const m = M();
    if (r.kind === 'expired') {
      if (!bag.canAdd(game, r.itemIndex, r.count)) { if (!quiet) notice(game, S10(game, 56, 'Insufficient inventory space')); return false; }
      bag.add(game, r.itemIndex, r.count, { from: 'consignment', grade: r.entry?.grade, options: r.entry?.options });
    }
    addDil(game, (r.sales || 0) + (r.deposit || 0));
    m.receipts.splice(m.receipts.indexOf(r), 1);
    if (!quiet) notice(game, S10(game, 54, 'Item has been received successfully'));
    return true;
  }
  function renderReceipt(win) {
    tick();
    money(win);
    const now = Date.now();
    win.control('freeboard').setRows(myReceipts().map(r => ({ cells: [
      S10(game, 25, '%d days').replace('%d', Math.max(0, P().receiptDays - Math.floor((now - r.at) / 86400000))),
      itemInfo(game, r.itemIndex).name, String(itemInfo(game, r.itemIndex).reqLv || 1), fmtNum(r.count), fmtNum(r.deposit), fmtNum(r.sales),
      { text: S10(game, 33, 'Receive DIL'), color: '#ffffff' }] })));
    const n = myReceipts().length;
    win.find('lbl_text')?.setText(S10(game, 34, ''));
    win.find('lbl_search_node')?.setText(n ?S10(game, 73, 'There are <COUNT> sales that have not been received.').replace('<COUNT>', n) : S10(game, 74, 'There are no completed sales to be received'));
  }

  // ---- purchase (online): store/ui_storebuyconfirm_2.txt (Confirm Purchase 2009:82, Buy Amount 2009:90)
  const buy = { win: null, selection: null };
  const buyLease = () => [game.save?.id, game.network, game.network?.token, B()];
  const buyCurrent = s => !!s && buy.selection === s && buy.win?.isOpen &&
    online() && s.lease.every((v, i) => v === buyLease()[i]) && !!s.bridge?.available?.();
  game.uiwin.registerWindow('shops.consignbuy', {
    script: 'game2/store/ui_storebuyconfirm_2.txt',
    modal: true,
    create(win) {
      buy.win = win;
      win.control('edit_buy_count').on('change', () => updBuy());
      win.control('btn_yes').onClick(() => doBuy());
      win.control('btn_no').onClick(() => win.close('cancel'));
    },
    onOpen(win, arg) {
      const lease = arg?.lease || buyLease();
      const s = { row: arg?.row ? structuredClone(arg.row) : null, lease, bridge: lease[3], pending: false };
      buy.selection = s;
      if (!s.row || s.row.mine || !buyCurrent(s)) { win.close('unavailable'); return; }
      const r = s.row;
      win.control('lbl_item_name').setText(r ? itemInfo(game, r.itemIndex).name : '');
      win.control('lbl_sellername').setText(r?.sellerName || '');
      win.control('lbl_servername').setText(game.network?.serverName || '');
      win.control('edit_buy_count').setValue?.(String(r?.count || 1));
      updBuy();
    },
    onClose() { buy.selection = null; },
  });
  const buyCount = () => { const r = buy.selection?.row; const n = Math.floor(Number(String(buy.win?.control('edit_buy_count').getValue?.() || '').replace(/[^0-9]/g, '')) || 0); return r ? Math.max(0, Math.min(r.count, n)) : 0; };
  function updBuy() {
    const w = buy.win, s = buy.selection, r = s?.row;
    if (!w || !r) return;
    const n = buyCount();
    w.control('lbl_stack_count').setText(`/ ${fmtNum(r.count)} ${S9(game, 80, 'pieces')}`);
    w.control('lbl_unit_price').setText(fmtNum(r.unit));
    // the consignment fee is the seller's (2010:17); the data gives no buyer-side tax rate
    w.control('lbl_tax').setText(fmtNum(0));
    w.control('lbl_total_price').setText(fmtNum(r.unit * n));
    w.control('lbl_my_money').setText(fmtNum(dil(game)));
    w.control('btn_yes').setEnabled(buyCurrent(s) && n > 0 && !s.pending && !s.bridge.busy);
  }
  async function doBuy() {
    const w = buy.win, s = buy.selection, r = s?.row, n = buyCount();
    if (!buyCurrent(s) || s.pending || s.bridge.busy || !r || !(n > 0)) return;
    if (dil(game) < r.unit * n) { notice(game, S9(game, 56, 'You do not have enough DIL.')); return; }
    s.pending = true;
    updBuy();
    try {
      // Keep the original bridge/session. A reconnect must not transfer an old
      // confirmation to another character or let its reply close a new window.
      const done = await s.bridge.buy(r.id, n);
      if (!done || !buyCurrent(s)) return;
      w.close('done');
      const sw = game.uiwin.window(pages.search);
      if (sw?.isOpen) { sw.control('lbl_Money').setDil(dil(game)); runSearch(sw, true); }
    } finally {
      s.pending = false;
      if (buyCurrent(s)) updBuy();
    }
  }
  function openBuy(row) { if (!online() || blocked()) return; game.uiwin.open('shops.consignbuy', { row, lease: buyLease() }); }
  // host snapshots: sales / expiries that happened meanwhile (also while offline), and open windows follow them
  game.events?.on?.('consign', ({ fresh = [] } = {}) => {
    for (const r of fresh) {
      if (r.kind === 'sold') say(game, `${itemInfo(game, r.itemIndex).name}: ${S10(game, 4, 'Sold Items')} (+${fmtNum(r.sales)} DIL)`, 'item');
      else if (r.kind === 'expired') say(game, cleanMsg(S10(game, 72, 'Registered Sales have expired')), 'sys');
    }
    const cw = game.uiwin.window(pages.consignment), rw = game.uiwin.window(pages.receipt);
    if (cw?.isOpen) renderConsign(cw);
    if (rw?.isOpen) renderReceipt(rw);
    if (buy.win?.isOpen) updBuy();
  });

  return {
    /** Open the market (Middleman NPC, or the Almighty's Agency with opts.remote). */
    open(npc = null, opts = {}) { st.npc = npc; st.remote = !!opts.remote; st.page = 'search'; return game.uiwin.open(pages.search, { npc }); },
    openConsignment: () => go('consignment'),
    openReceipt: () => go('receipt'),
    register: openRegister,
    tick,
    get market() { return M(); },
  };
}
