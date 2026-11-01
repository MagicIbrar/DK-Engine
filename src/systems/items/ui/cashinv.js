// Cash inventory (btn_cashinven): game2/ui_cashinvenwnd.txt. Purchases of the D-Shop / VIP shop wait here
// (900:6 "The item you purchased will be stored in the Cash Inventory.") until received into the bag:
// 5 visible rows (template pan_slot_ with item_icon_ / lbl_title_ = 900:2 "<ITEM_NAME> Purchaser: <NAME>
// Purchase Date: <DATE>"), slot_scroll, btn_sort (900:13/14 by date), btn_receiveall (900:3, confirm 900:9).
// Right / double click (or dragging a row into the bag) receives one entry.
import { slotIcon, itemPayload } from './common.js';
import { buildTooltip } from '../tooltip.js';
import { placeWithBag } from './craft.js';

const ROWS = 5, ROW_H = 66, TOP = 51;

export function registerCashInventory(sys) {
  const g = sys.game;
  const st = { top: 0, asc: false, win: null, rows: [] };
  const list = () => {
    const l = sys.cashList();
    return l.slice().sort((a, b) => (st.asc ? 1 : -1) * ((a.boughtAt || 0) - (b.boughtAt || 0)));
  };
  const render = () => {
    const win = st.win;
    if (!win?.isOpen) return;
    const L = list();
    const max = Math.max(0, L.length - ROWS);
    st.top = Math.max(0, Math.min(st.top, max));
    const sc = win.control('slot_scroll');
    sc.setRange?.(max, ROWS); sc.setValue?.(st.top);
    for (let i = 0; i < ROWS; i++) {
      const r = st.rows[i];
      const inst = L[st.top + i] || null;
      r.data.inst = inst;
      r.control(`item_icon_${i}`).setVisible(!!inst);
      r.control(`lbl_title_${i}`).setVisible(!!inst);
      r.control(`lbl_server_${i}`).setVisible(false);
      r.control(`pan_not_${i}`).setVisible(!inst);
      if (inst) {
        slotIcon(sys, r.control(`item_icon_${i}`), inst);
        const date = new Date(inst.boughtAt || Date.now());
        const t = (sys.str(900, 2) || '<ITEM_NAME>').replace('<ITEM_NAME>', `${inst.name}${(inst.count || 1) > 1 ? ` x${inst.count}` : ''}`)
          .replace('<NAME>', inst.purchaser || g.save.name).replace('<DATE>', `${date.getFullYear()}-${String(date.getMonth() + 1).padStart(2, '0')}-${String(date.getDate()).padStart(2, '0')} ${String(date.getHours()).padStart(2, '0')}:${String(date.getMinutes()).padStart(2, '0')}`);
        r.control(`lbl_title_${i}`).setRichText(t);
      }
    }
    win.control('btn_sort').setText(sys.str(900, st.asc ? 14 : 13) || (st.asc ? 'Sort by date\u2191' : 'Sort by date\u2193'));
  };
  g.uiwin.registerWindow('cashinven', {
    script: 'game2/ui_cashinvenwnd.txt',
    menuButton: 'btn_cashinven',
    create(win) {
      st.win = win;
      const tpl = win.control('pan_slot_');
      for (let i = 0; i < ROWS; i++) {
        const r = tpl.cloneAs(`_${i}`, { y: TOP + i * ROW_H });
        st.rows.push(r);
        const icon = r.control(`item_icon_${i}`);
        icon.setTooltip(() => (r.data.inst ? buildTooltip(sys, r.data.inst, { where: 'cash' }) : null));
        icon.makeDraggable(() => (r.data.inst ? itemPayload(sys, r.data.inst, 'cash') : null));
        const take = () => { if (r.data.inst) sys.receiveCash(r.data.inst); };
        icon.onRightClick(take); icon.onDoubleClick(take);
        r.onDoubleClick(take); r.onRightClick(take);
      }
      tpl.hide();
      const sc = win.control('slot_scroll');
      sc.on('change', (v) => { st.top = Math.round(Number(v) || 0); render(); });
      win.root?.el?.addEventListener('wheel', (e) => { st.top += Math.sign(e.deltaY); render(); }, { passive: true });
      win.control('btn_sort').onClick(() => { st.asc = !st.asc; render(); });
      win.control('btn_receiveall').onClick(async () => {
        if (!sys.cashList().length) return;
        const r = await g.uiwin.msgbox(sys.str(900, 9) || 'All items will be moved to your inventory. Do you wish to proceed?', { kind: 'yesno' });
        if (r !== 'yes') return;
        for (const inst of [...list()]) if (!await sys.receiveCash(inst, { quiet: true })) break;
      });
      g.events.on('inventory', render);
    },
    onOpen(win) {
      render();
      // receiving by drag goes into the bag: keep the two side by side
      placeWithBag(sys, win);
    },
  });
}
