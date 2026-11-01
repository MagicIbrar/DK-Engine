// Stash (storage NPC, npcs.json jobType 3 STORAGE): game2/storage/ui_storagewnd.txt.
//   tabs I..IV (btn_tab_0..3, 190:2-5; tabs III and IV need Storage Mastery, 2 uses per character) + Shared
//   (btn_tab_4, 190:6, account-wide, Storage Keeper's Key); 10 x 10 cells of 32 px (slotitem 7,49 319x319).
//   Storing costs formula.ini stStorageCostPerUnit (10) dil per item (190:8 when short). Dil: btn_payment
//   withdraws (ui_withdrawalwnd.txt); while the stash is open the inventory's dil box deposits.
//   Opening the stash opens the inventory beside it; walking away from the NPC closes it.
import { gridItems, footprintAt, itemPayload, itemSwapResult, cursorActionResult, fmt } from './common.js';
import { buildTooltip } from '../tooltip.js';
import { askAmount, askDeposit, confirmSort } from './dialogs.js';
import { placeWithBag } from './craft.js';

const TAB_TEXT = [2, 3, 4, 5, 6];
const SHARED = 4;

/** Can an instance be dropped exactly at `at` of a container (free footprint, or onto the same item to stack)? */
function droppable(c, inst, at, w, h) {
  if (!(at.page >= 0 && at.page < c.unlocked) || !c.inside(at.x, at.y, w, h)) return false;
  const occ = c.occupants(at.page, at.x, at.y, w, h, inst);
  return occ.length === 0 || (occ.length === 1 && occ[0].itemIndex === inst.itemIndex && c.db.stackSize(c.db.def(inst.itemIndex)) > 1);
}
// Clicking any cell of an existing footprint targets its origin, including the
// invisible parked footprint of a carried item after a canonical swap.
export function storageFootprint(grid, event, w, h) {
  const cell=grid.cellAt(event.clientX,event.clientY),item=cell&&grid.itemAt(cell.x,cell.y);
  return item ? {x:item.x??item.data.x,y:item.y??item.data.y} : footprintAt(grid,event,w,h);
}

export function registerStorage(sys) {
  const g = sys.game;
  const st = { tab: 0, search: '', win: null, npc: null };
  sys.storageTab=()=>st.tab;
  const cont = () => (st.tab === SHARED ? sys.shared : sys.stash);
  const page = () => (st.tab === SHARED ? 0 : st.tab);
  const unlockedTab = (i) => (i === SHARED ? !!sys.account().sharedStash : i < sys.stash.unlocked);
  const fee = () => Number(sys.db.equipment.formula?.stStorageCostPerUnit) || 10;

  /** Deposit an instance from the bag into the open stash tab (first free spot, or (x, y)). */
  sys.stashDeposit = (inst, at = null) => {
    const def = sys.db.def(inst.itemIndex);
    if (st.tab === SHARED && (inst.bound || Number(def?.trade) === 0)) { sys.msg(190, 7); return false; }
    const c = cont();
    const [w, h] = c.size(inst);
    // dropped on a spot: only that spot (free, or the same stackable item); an invalid spot sends the item back to its
    // cell instead of jumping to the first free one (fb-items 2o)
    if (at && !droppable(c, inst, at, w, h)) return false;
    const spot = at || c.findSpot(w, h, { page: page() }) || c.findSpot(w, h);
    if (!spot) { sys.msg(190, st.tab === SHARED ? 16 : 15); return false; }
    if (!sys.spendDil(fee())) { sys.msg(190, 8); return false; }
    const it = sys.bag.take(inst);
    const r = c.placeAt(it, spot.page, spot.x, spot.y) || (!at && c.add(it).ok ? 'moved' : null);
    if (!r) { sys.bag.add(it); sys.addDil(fee()); return false; }
    if (r === 'partial') sys.bag.add(it);
    sys.msg(null, null, `${sys.str(260, 23) || 'The following item has been stored: ['}${def?.name}]`);
    sys.changed('stash');
    return true;
  };
  sys.stashWithdraw = (inst, at = null) => {
    const c = sys.shared.list.includes(inst) ? sys.shared : sys.stash;
    const [w, h] = sys.bag.size(inst);
    if (at && !droppable(sys.bag, inst, at, w, h)) return false;   // invalid drop spot: back to its stash cell
    const spot = at || sys.bag.findSpot(w, h);
    if (!spot) { sys.msg(40, 77); return false; }
    const it = c.take(inst);
    const r = sys.bag.placeAt(it, spot.page, spot.x, spot.y) || (!at && sys.bag.add(it).ok ? 'moved' : null);
    if (!r) { c.add(it); sys.msg(40, 77); return false; }
    if (r === 'partial') c.add(it);
    sys.msg(null, null, `${sys.str(260, 22) || 'The following item has been withdrawn: ['}${sys.db.name(inst.itemIndex)}]`);
    sys.changed('stash');
    return true;
  };
  sys.stashIsOpen = () => !!st.win?.isOpen;
  sys.stashDepositDil = async () => {
    const n = await askDeposit(sys, sys.dil);   // Global inven/ui_savemoney ("Inventory DIL Stash Storing")
    if (!n) return;
    if(g.save.authority==='server'){if(st.tab===SHARED)return sys.sharedBank('deposit',n);return g.network.action('bank',{direction:'deposit',amount:n});}
    if (!sys.spendDil(n)) { sys.msg(190, 13); return; }
    if (st.tab === SHARED) { sys.account().sharedDil += n; sys.saveAccount(); } else g.save.stashDil = (Number(g.save.stashDil) || 0) + n;
    sys.changed('dil');
  };

  const render = () => {
    const win = st.win;
    if (!win?.isOpen) return;
    const q = st.search;
    const match = (inst) => !!q && String(inst.name || sys.db.name(inst.itemIndex)).toLowerCase().includes(q);
    for (let i = 0; i < 6; i++) {
      const tab = win.control(`btn_tab_${i}`);
      const shown = i <= SHARED;
      tab.setVisible(shown);
      if (!shown) continue;
      if (!tab.data.titled) { tab.data.titled = true; tab.setText(sys.str(190, TAB_TEXT[i]) || ['I', 'II', 'III', 'IV', 'Shared'][i]); }
      tab.setChecked(i === st.tab);
      win.control(`btn_lock_${i}`).setVisible(!unlockedTab(i));
      const c = i === SHARED ? sys.shared : sys.stash;
      win.control(`pan_searchmark_${i}`).setVisible(!!q && c.items(i === SHARED ? 0 : i).some(match));
    }
    const grid = win.control('slotitem');
    const held=st.held?.from===(st.tab===SHARED?'shared':'stash')?st.held.uid:null;
    grid.setItems(unlockedTab(st.tab) ? gridItems(sys, grid, cont(), page(), { dim: q ? (x) => !match(x) : null, mark: q ? match : null, held, referenceStock:false }).items : []);
    win.control('lbl_money').setDil(st.tab === SHARED ? sys.account().sharedDil : g.save.stashDil);
  };

  g.uiwin.registerWindow('storage', {
    script: 'game2/storage/ui_storagewnd.txt',
    create(win) {
      st.win = win;
      const grid = win.control('slotitem');
      // the art is a 10 x 10 grid of 32 px cells; the script rect is 1 px short of 320
      grid.setRect(7, 49, 320, 320);
      grid._itemsRefresh = render;
      for (let i = 0; i < 6; i++) {
        win.control(`btn_tab_${i}`).onClick(() => { if (unlockedTab(i)) { st.tab = i; render(); } });
        win.control(`btn_lock_${i}`).onClick(() => sys.openShop());
        win.control(`btn_tab_${i}`).acceptDrop({
          accept: (d) => d?.kind === 'item' && unlockedTab(i),
          drop: async (d) => { const prev = st.tab; st.tab = i; try {
            if(d.from==='cursor'){
              const c=cont(),[w,h]=c.sizeOf(d.itemIndex),spot=c.findSpot(w,h,{page:page()});
              if(!spot){sys.msg(40,77);st.tab=prev;render();return false;}
              const result=await cursorActionResult(sys,sys.cursorPlace(i===SHARED?'shared':'stash',{page:page(),x:spot.x,y:spot.y,targetUid:null}));
              if(!result&&st.tab===i)st.tab=prev;render();return result;
            }
            const ok = d.from === 'bag' ? await sys.stashDeposit(d.inst) : false; if (!ok && st.tab === i) st.tab = prev; render(); return !!ok;
          } catch { if(st.tab===i)st.tab=prev;render();return false; } },
        });
      }
      grid.setItemTooltip(it => it._held ? null : buildTooltip(sys, it.data, { where: 'storage' }));
      grid.makeDraggable((e, gr) => {
        const c = gr.cellAt(e.clientX, e.clientY), it = c && gr.itemAt(c.x, c.y);
        return it && !it._held ? itemPayload(sys, it.data, st.tab === SHARED ? 'shared' : 'stash', { page: page() }, [gr.cw, gr.ch]) : null;
      });
      grid.acceptDrop({
        accept: (d) => d?.kind === 'item' && unlockedTab(st.tab),
        hover: (d, e) => { const [w, h] = cont().sizeOf(d.itemIndex); const p = storageFootprint(grid, e, w, h); grid.highlight(p.x, p.y, w, h, cont().inside(p.x, p.y, w, h) && cont().occupants(page(), p.x, p.y, w, h, d.inst).length <= 1); },
        leave: () => grid.highlight(null),
        drop: (d, e) => {
          grid.highlight(null);
          const c = cont();
          const [w, h] = c.sizeOf(d.itemIndex);
          const p = storageFootprint(grid, e, w, h);
          if(d.from==='cursor'){
            const occ=c.occupants(page(),p.x,p.y,w,h);if(occ.length>1)return false;
            return cursorActionResult(sys,sys.cursorPlace(c===sys.shared?'shared':'stash',{page:page(),x:p.x,y:p.y,targetUid:occ[0]?.uid??null}));
          }
          if ((d.from === 'stash' && c === sys.stash) || (d.from === 'shared' && c === sys.shared)) {
            const inst=c.list.find(item=>item.uid===(d.uid||d.inst?.uid));
            if(!inst)return false;
            const occupants=c.occupants(page(),p.x,p.y,w,h,inst);
            const displacedUid=occupants.length===1?occupants[0].uid:null;
            const result=c.moveTo(inst,page(),p.x,p.y);
            if(!result?.then&&result)sys.changed('stash');
            return itemSwapResult(sys,result,{...d,inst},displacedUid);
          }
          if (d.from === 'bag') return sys.stashDeposit(d.inst, { page: page(), x: p.x, y: p.y });
          if (d.from === 'stash' || d.from === 'shared') return sys.transfer(d, c, page(), p.x, p.y);
          return false;
        },
      });
      grid.on('cellrclick', (c, it) => { if (it) sys.stashWithdraw(it.data); });
      win.control('btn_payment').onClick(async () => {
        const have = st.tab === SHARED ? sys.account().sharedDil : Number(g.save.stashDil) || 0;
        const n = await askAmount(sys, sys.str(260, 10) || 'Withdraw', have);
        if (!n || n > have) { if (n) sys.msg(190, 10); return; }
        if (sys.dil + n > 10_000_000_000) { sys.msg(190, 11); return; }
        if(g.save.authority==='server'){if(st.tab===SHARED)return sys.sharedBank('withdraw',n);return g.network.action('bank',{direction:'withdraw',amount:n});}
        if (st.tab === SHARED) { sys.account().sharedDil -= n; sys.saveAccount(); } else g.save.stashDil = have - n;
        sys.addDil(n);
        sys.changed('dil');
      });
      const search = win.control('pan_itemsearch');
      win.control('btn_search_open').onClick(() => { search.show(); win.control('btn_search_open').hide(); win.control('btn_search_close').show(); });
      win.control('btn_search_close').onClick(() => { search.hide(); win.control('btn_search_close').hide(); win.control('btn_search_open').show(); st.search = ''; render(); });
      const doSearch = () => { st.search = String(win.control('edit_text').getValue?.() || '').trim().toLowerCase(); render(); };
      win.control('btn_itemsearch').onClick(doSearch);
      win.control('edit_text').on('enter', doSearch);
      win.control('btn_initsearch').onClick(() => { win.control('edit_text').setValue?.(''); st.search = ''; render(); });
      // sorting (btn_alignment: this tab, btn_alignment_all: every tab; 190:19/20 confirmations)
      // the confirmation is Global's sort warning window (dialogs.js confirmSort, option sortMsg), lbl_msg = which sort
      win.control('btn_alignment').onClick(async () => { if (await confirmSort(sys, sys.str(190, 19) || '')) { const ok=await cont().sort(page()); if(ok!==false)sys.changed('stash'); } });
      win.control('btn_alignment_all').onClick(async () => { if (await confirmSort(sys, sys.str(190, 20) || '')) { const ok=await sys.stash.sort(); if(unlockedTab(SHARED))await sys.shared.sort(); if(ok!==false)sys.changed('stash'); } });
      g.events.on('inventory', render);
      g.events.on('dil', render);
      g.uiwin.on?.('dragstart',payload=>{const d=payload?.data;if(d?.kind==='item'&&['stash','shared'].includes(d.from)){st.held={uid:d.uid,from:d.from};render();}});
      g.uiwin.on?.('dragend',()=>{if(st.held){st.held=null;render();}});
    },
    onOpen(win, npc) {
      st.npc = npc && npc.kind === 'npc' ? npc : null;
      if (!unlockedTab(st.tab)) st.tab = 0;
      render();
      placeWithBag(sys, win);   // the stash left of the centre, the bag right of it
    },
    onClose() { st.npc = null; },
    update(win) {
      const p = g.player, n = st.npc;
      if (n && p && Math.hypot(n.x - p.x, n.z - p.z) > 10) win.close('away');
    },
  });
}
