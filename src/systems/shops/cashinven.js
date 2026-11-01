// Cash Inventory: script/ui/game2/ui_cashinvenwnd.txt (320x478, cashinventory#0..#2; string cate 900).
// D-Shop / VIP purchases and gifts land here ({itemIndex, count, period, bought, buyer, gift}); a row is moved to the
// bag by clicking it (or right-click / double-click), "Receive All to Inventory" (900/3) moves everything
// (confirm 900/9). The sort button toggles "Sort by date↓ / ↑" (900/13, 900/14). The purchase time counts toward a
// limited-time item's period (171/28: the duration begins its countdown upon purchase).
import { itemInfo, itemInfoFull, itemIcon, itemTooltip, bag, str, say, notice, confirmBox, fmtNum, COLORS, uiSound, periodText, itemsSys } from './common.js';

const ROWS = 5, ROW_H = 66;
const S = (game, code, fb = '') => str(game, 900, code, fb);

export function createCashInventory(game, api) {
  // The items system owns the real Cash Inventory (save.cashInv + its 'cashinven' window): deliver there.
  const sys = itemsSys(game);
  if (sys && typeof sys.cashList === 'function') {
    return {
      get list() { return sys.cashList(); },
      add(itemIndex, count = 1, extra = {}) {
        const r = sys.add(Number(itemIndex), Math.max(1, Math.floor(count) || 1), { to: 'cash', purchaser: extra.gift || extra.buyer || game.save?.name, silent: true, source: extra.shop || 'dshop' });
        const inst = r?.placed?.[r.placed.length - 1] || null;
        if (inst && extra.gift) inst.gift = extra.gift;
        if (inst && extra.shop) inst.shop = extra.shop;
        game.events?.emit?.('cashinventory', { reason: 'add', row: inst });
        return inst;
      },
      take: (inst, opts) => sys.receiveCash(inst, opts),
      async takeAll() { let n = 0; for (const inst of sys.cashList().slice()) { if (sys.receiveCash(inst, { quiet: true })) n++; else break; } return n; },
      open: () => game.uiwin.open('cashinven'),
      refresh() {},
      /** A cash-inventory entry for another (saved) character, in the items system's format. */
      makeFor(itemIndex, count, purchaser) {
        const inst = sys.create(Number(itemIndex), { count: Math.max(1, count || 1) });
        if (!inst) return null;
        delete inst.page; delete inst.x; delete inst.y;
        return Object.assign(inst, { boughtAt: Date.now(), purchaser });
      },
      external: true,
    };
  }
  const st = { win: null, rows: [], top: 0, desc: true, tok: 0 };
  const list = () => ((game.save.cashInventory ||= []));

  /** Deliver to the cash inventory (the D-Shop, VIP shop, gifts). Returns the new row. */
  function add(itemIndex, count = 1, extra = {}) {
    const it = itemInfo(game, itemIndex);
    const row = {
      id: `ci${Date.now().toString(36)}${Math.random().toString(36).slice(2, 7)}`,
      itemIndex: Number(itemIndex), count: Math.max(1, Math.floor(count) || 1),
      period: Number(extra.period ?? it.period) || 0, bought: extra.bought || Date.now(),
      buyer: extra.buyer || game.save?.name || '', gift: extra.gift || null, shop: extra.shop || 'dshop', price: extra.price || 0,
    };
    list().push(row);
    game.events?.emit?.('cashinventory', { reason: 'add', row });
    if (st.win?.isOpen) render();
    return row;
  }
  /** Move one row into the bag. */
  function take(row, { quiet = false } = {}) {
    const rows = list();
    const i = rows.indexOf(row);
    if (i < 0) return false;
    if (!bag.canAdd(game, row.itemIndex, row.count)) { uiSound(game, 'lackOfSpace'); if (!quiet) notice(game, S(game, 8, 'A problem occurred in the Cash Inventory while receiving an item.')); return false; }
    const remaining = row.period > 0 ? Math.max(0, row.period - (Date.now() - row.bought) / 1000) : 0;
    if (row.period > 0 && remaining <= 0) {
      rows.splice(i, 1);
      if (!quiet) notice(game, `${itemInfo(game, row.itemIndex).name}: expired.`);
      render();
      return false;
    }
    const ok = bag.add(game, row.itemIndex, row.count, { from: 'cashinventory', expires: row.period > 0 ? row.bought + row.period * 1000 : null, cash: true });
    if (!ok) return false;
    rows.splice(i, 1);
    if (!quiet) say(game, S(game, 7, 'You received an item.'), 'item');
    game.events?.emit?.('cashinventory', { reason: 'take', row });
    render();
    return true;
  }
  async function takeAll() {
    if (!list().length) return 0;
    const r = await confirmBox(game, S(game, 9, 'All items will be moved to your inventory. Do you wish to proceed?'), S(game, 1, 'Cash Inventory'));
    if (r !== 'yes') return 0;
    let n = 0;
    for (const row of sorted().slice()) { if (take(row, { quiet: true })) n++; else break; }
    if (n) say(game, S(game, 7, 'You received an item.'), 'item');
    if (list().length) notice(game, S(game, 8, 'A problem occurred in the Cash Inventory while receiving an item.'));
    render();
    return n;
  }
  const sorted = () => list().slice().sort((a, b) => (st.desc ? b.bought - a.bought : a.bought - b.bought));

  // ---------------------------------------------------------------------------------------------- window
  const def = {
    script: 'game2/ui_cashinvenwnd.txt',
    menuButton: 'btn_cashinven',
    create(win) {
      st.win = win;
      const tpl = win.control('pan_slot_');
      for (let k = 0; k < ROWS; k++) {
        const r = tpl.cloneAs(`_${k}`, { x: 0, y: 51 + k * ROW_H, visible: false });
        const row = { root: r, k, icon: win.control(`item_icon_${k}`), title: win.control(`lbl_title_${k}`), server: win.control(`lbl_server_${k}`), not: win.control(`pan_not_${k}`) };
        const pick = () => { if (row.data) take(row.data); };
        row.icon.onClick(pick); row.icon.onRightClick(pick); row.icon.onDoubleClick(pick);
        r.on('dblclick', pick); r.on('rclick', pick); r.on('click', pick);
        row.icon.setTooltip(() => row.data ? tip(row.data) : null);
        st.rows.push(row);
      }
      const sc = win.control('slot_scroll');
      sc.on?.('change', v => { st.top = v; render(); });
      win.el.addEventListener('wheel', (e) => { if (!win.isOpen) return; e.preventDefault(); setTop(st.top + Math.sign(e.deltaY)); }, { passive: false });
      win.control('btn_receiveall').onClick(() => takeAll());
      win.control('btn_sort').onClick(() => { st.desc = !st.desc; render(); });
    },
    onOpen() { render(); },
  };
  // the items system may bring its own cash inventory window: take the 'cashinven' name only when nobody did,
  // else (or when it is taken later) this one lives on as 'shops.cashinven'
  def._shops = true;
  const winName = () => (game.uiwin.defs?.get?.('cashinven')?._shops ? 'cashinven' : 'shops.cashinven');
  if (!game.uiwin.has('cashinven')) game.uiwin.registerWindow('cashinven', def);
  else game.uiwin.registerWindow('shops.cashinven', { ...def, menuButton: null });
  const ensure = () => { const n = winName(); if (!game.uiwin.has(n)) game.uiwin.registerWindow(n, { ...def, menuButton: null }); return n; };

  function setTop(t) {
    const max = Math.max(0, list().length - ROWS);
    st.top = Math.max(0, Math.min(max, t));
    render();
  }
  function tip(row) {
    const lines = [];
    if (row.period > 0) {
      const left = Math.max(0, row.period - (Date.now() - row.bought) / 1000);
      lines.push({ text: `Remaining: ${periodText(left)}`, color: COLORS.GREEN });
    }
    if (row.count > 1) lines.push({ text: `x${fmtNum(row.count)}`, color: COLORS.WHITE });
    if (row.gift) lines.push({ text: `Gift from ${row.gift}`, color: COLORS.GOLD });
    return itemTooltip(game, row.itemIndex, lines);
  }
  function render() {
    const w = st.win;
    if (!w?.isOpen) return;
    const tok = ++st.tok;
    const rows = sorted();
    const max = Math.max(0, rows.length - ROWS);
    if (st.top > max) st.top = max;
    const sc = w.control('slot_scroll');
    sc.setRange?.(max, ROWS); sc.setValue?.(st.top);
    w.control('btn_sort').setText(S(game, st.desc ? 13 : 14, st.desc ? 'Sort by date↓' : 'Sort by date↑'));
    w.control('btn_receiveall').setEnabled(rows.length > 0);
    st.rows.forEach((row, k) => {
      const d = rows[st.top + k] || null;
      row.data = d;
      row.root.setVisible(!!d);
      if (!d) return;
      const name = itemInfo(game, d.itemIndex).name + (d.count > 1 ? ` x${fmtNum(d.count)}` : '');
      const date = new Date(d.bought);
      const ds = `${date.getFullYear()}-${String(date.getMonth() + 1).padStart(2, '0')}-${String(date.getDate()).padStart(2, '0')} ${String(date.getHours()).padStart(2, '0')}:${String(date.getMinutes()).padStart(2, '0')}`;
      row.title.setRichText(S(game, 2, '<color=00ff00><ITEM_NAME></color>\n\nPurchaser: <NAME>\nPurchase Date: <DATE>')
        .replace('<ITEM_NAME>', name).replace('<NAME>', d.gift ? `${d.gift}` : d.buyer).replace('<DATE>', ds));
      row.server.setText(d.shop === 'vipshop' ? 'VIP' : d.gift ? str(game, 171, 27, 'Gift') : '');
      row.not.setVisible(false);
      row.icon.setIcon(null);
      itemInfoFull(game, d.itemIndex).then(() => itemIcon(game, d.itemIndex, 64, 64)).then(ic => { if (tok === st.tok && row.data === d) row.icon.setIcon(ic, { inset: 1 }); });
    });
  }
  game.events?.on?.('inventory', () => { if (st.win?.isOpen) render(); });

  return {
    get list() { return list(); },
    add, take, takeAll, open: () => game.uiwin.open(ensure()),
    refresh: render,
  };
}
