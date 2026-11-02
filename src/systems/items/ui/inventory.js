// The original inventory + equipment window: game2/inven/ui_invenwnd_renew.txt (-> ui_invenwnd_base_renew.txt).
//   top:    5 equipment presets (btn_preset_1..5 / pan_Preset_1..5 with the suititem_N slots), weapon tab I/II,
//           armour / costume view, equipment lock, preset preview, costume bag
//   bottom: 7 bags (btn_changebag_0..6; bags 3-7 locked until a Traveler's Backpack is used) of 10 x 5 cells
//           (slotbag 370x180, cellsize 37x36), bag lock, item search, dil and the dil Drop button.
// Items occupy their w x h cells; drag & drop / click-pick move, swap and merge them (model.js Container rules),
// Shift+drag splits a stack (ui_stackdivide.txt), right click uses or equips, dropping outside discards to the
// ground (ui_dropmsgwnd.txt confirmation), Ctrl shows the equipped item next to the tooltip, Shift the proven
// Rank/Brand option ranges (stringtable_itemdesc 910:17).
import { gridItems, setReadyGridItems, footprintAt, slotIcon, itemPayload, itemSwapResult, cursorActionResult, fmt, isCtrl, isShift } from './common.js';
import { buildTooltip, buildCompare } from '../tooltip.js';
import {comparisonTargets} from '../compare.js';
import { cursorStoneTarget, cursorStoneInsert } from './cursor-stone-insert.js';
import { Equipment, S } from '../equip.js';
import { confirmSort } from './dialogs.js';
import { clonePresetSelect, unequipSelect } from './preset-select.js';

const SLOT_IDS = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 18, 19, 20, 24, 25, 26, 27, 28, 33, 34, 35, 36];
export const returnsToSourceSlot = (drag, target, preset) => drag?.from === 'equip' && drag.slot === target && drag.preset === preset;
export function inventoryFootprint(grid, event, drag, w, h) {
  const cell = grid.cellAt(event.clientX, event.clientY);
  const target = cell && grid.itemAt(cell.x, cell.y);
  // The carried UID remains parked in the authoritative bag until placement.
  // Its hidden footprint is also a valid return target: centring a multi-cell
  // icon on an edge of that footprint would shift it into a neighbouring item.
  return target ? { x: target.x ?? target.data.x, y: target.y ?? target.data.y } : footprintAt(grid, event, w, h);
}

export function registerInventory(sys) {
  const g = sys.game;
  const st = { page: 0, costumeView: false, search: '', win: null };
  st.dropOutside = (inst) => sys.discardAsk(inst); // Global 008931d0: a world release only drops; it never wears the item
  sys.invState = st;

  g.uiwin.registerWindow('inventory', {
    script: 'game2/inven/ui_invenwnd_renew.txt',
    hotkey: 'KeyI',
    menuButton: 'btn_inven',
    create(win) {
      st.win = win;
      const bag = win.control('slotbag');
      bag._itemsRefresh = () => { if (win.isOpen) renderBag(); };

      // ---------------------------------------------------------------- bag tabs
      for (let i = 0; i < 7; i++) {
        const tab = win.control(`btn_changebag_${i}`);
        tab.onClick(() => { if (i < sys.bag.unlocked) { st.page = i; renderBag(); } });
        const lock = tab.control('btn_lock');
        lock.onClick(() => sys.openShop?.());
        tab.acceptDrop({
          accept: (d) => d?.kind === 'item' && i < sys.bag.unlocked,
          drop: (d) => {
            const [w, h] = sys.bag.sizeOf(d.itemIndex);
            const spot = sys.bag.findSpot(w, h, { page: i, ignore: d.from === 'bag' ? d.inst : null });
            if (!spot) { sys.msg(40, 77); return false; }
            return dropOnBag(d, i, spot.x, spot.y);
          },
        });
      }
      // ---------------------------------------------------------------- bag grid
      // Original 910:15 Ctrl comparison and 910:17 Shift option ranges; Shift never pins or cycles comparisons.
      bag.setItemTooltip(item => {
        if (item._held && !item._heldReference) return null;
        const options={where:'bag',optionRanges:!!g.uiwin?.tooltips?._shiftDown||isShift(g)};
        return(isCtrl(g)||!!g.uiwin?.tooltips?._ctrlKey)?buildCompare(sys,item.data,options):buildTooltip(sys,item.data,options);
      });
      bag.makeDraggable((e, grid) => {
        const c = grid.cellAt(e.clientX, e.clientY);
        const it = c && grid.itemAt(c.x, c.y);
        if (!it || it._held || sys.bag.locked) return null;
        const inst = it.data;
        if (g.chatLinks?.fromClick?.(inst, e)) return null;   // CHAT-LINKS: Shift + click with the chat input open = link it
        if (sys.reserved?.has(inst.uid)) return null;   // registered in an item NPC window: locked in place
        // Global: Shift + click a stack opens StackDivideWnd first; the divided part then sticks to the cursor
        if ((e?.shiftKey || isShift(g)) && (inst.count || 1) > 1) { void sys.splitPickup?.(inst); return null; }
        const payload = itemPayload(sys, inst, 'bag', { page: st.page }, [grid.cw, grid.ch]);
        // The item already painted in this cell is the immediate cursor image.
        // A cold full-size render may replace it later, never leave pickup blank.
        if (!payload.icon) payload.icon = it.icon || null;
        return {
          ...payload,
          // released over the world: Global ground-drop flow (state gate, costume bag, map, binding, DropMsg confirm)
          onDropOutside: (ev) => st.dropOutside(inst, ev),
        };
      });
      bag.acceptDrop({
        accept: (d) => d?.kind === 'item' || d?.kind === 'craftslot' || d?.kind === 'shopItem' || d?.kind === 'shopRebuy',
        hover: (d, e) => {
          if (d.kind !== 'item') return;
          const [w, h] = sys.bag.sizeOf(d.itemIndex);
          const p = inventoryFootprint(bag, e, d, w, h);
          const inside = sys.bag.inside(p.x, p.y, w, h);
          const occ = inside ? sys.bag.occupants(st.page, p.x, p.y, w, h, d.from === 'bag' ? d.inst : null) : [];
          bag.highlight(p.x, p.y, w, h, inside && occ.length <= 1);
        },
        leave: () => bag.highlight(null),
        drop: (d, e) => {
          bag.highlight(null);
          if (d.kind === 'craftslot') { d.slot?.clear(true); return true; }   // taken back out of an NPC window slot
          if (d.kind === 'shopItem' || d.kind === 'shopRebuy') { d.buy?.(); return true; }   // an NPC shop item dropped on the bag = buy it
          const [w, h] = sys.bag.sizeOf(d.itemIndex);
          const p = inventoryFootprint(bag, e, d, w, h);
          return dropOnBag(d, st.page, p.x, p.y);
        },
      });
      bag.on('cellrclick', (cell, item) => { if (item) sys.rightClick(item.data, 'bag'); });
      bag.on('celldbl', (cell, item) => { if (item) sys.rightClick(item.data, 'bag'); });

      // ---------------------------------------------------------------- equipment slots of every preset
      for (let pi = 0; pi < 5; pi++) {
        const pan = win.control(`pan_Preset_${pi + 1}`);
        for (const id of SLOT_IDS) {
          const ctrl = pan.control(`suititem_${id}`);
          if (ctrl.missing) continue;
          ctrl.data.slot = id; ctrl.data.preset = pi;
          wireSlot(ctrl, pi);
        }
      }
      // an item released anywhere over the equipment / character area (not on a slot) is worn in its own slot
      win.control('pan_bg_equip').acceptDrop({
        accept: (d) => d?.kind === 'item' && d.from !== 'equip' && !!sys.db.def(d.itemIndex)?.slot,
        drop: (d) => {
          const slot = sys.equip.autoSlot(sys.db.def(d.itemIndex));
          const displaced = sys.equip.get(slot)?.uid;
          if(d.from==='cursor')return cursorActionResult(sys,sys.cursorPlace('equip',{slot,preset:sys.equip.data.active,targetUid:displaced??null}));
          return itemSwapResult(sys, sys.equipItem(d.inst), d, displaced);
        },
      });
      // the held item leaves its bag cell / equipment slot empty while it is on the cursor
      g.uiwin.on('dragstart', (p) => {
        const d = p?.data;
        if (d?.kind !== 'item' || (d.from !== 'bag' && d.from !== 'equip')) return;
        st.held = { uid: d.uid, from: d.from, slot: d.slot, preset: d.preset };
        if (d.from === 'equip' && d.preset === sys.equip.data.active && g.player) {
          // Preview the item lifted off the character without changing server
          // ownership, combat stats, or the canonical save while it is held.
          const equip = g.save.equip;
          const presets = equip.presets.map((row, index) => index === d.preset ? { ...row } : row);
          delete presets[d.preset][d.slot];
          const previewSys = Object.create(sys);
          previewSys.game = { save: { ...g.save, equip: { ...equip, presets } }, settings: g.settings, now: g.now?.bind(g) };
          const preview = new Equipment(previewSys);
          g.player._equipmentPreview = { equipment: preview.view(sys.itemStats), style: preview.style(), equip: previewSys.game.save.equip };
          void sys.look.apply();
        }
        if (win.isOpen) render();
      });
      g.uiwin.on('dragend', () => {
        if (!st.held) return;
        st.held = null;
        if (g.player?._equipmentPreview) { g.player._equipmentPreview = null; void sys.look.apply(); }
        if (win.isOpen) render();
      });
      // ---------------------------------------------------------------- buttons
      for (let pi = 0; pi < 5; pi++) win.control(`btn_preset_${pi + 1}`).onClick(() => sys.setPreset(pi));
      win.control('btn_weapontab_0').onClick(() => { if (sys.equip.data.weaponTab) sys.swapWeaponTab(); });
      win.control('btn_weapontab_1').onClick(() => { if (!sys.equip.data.weaponTab) sys.swapWeaponTab(); });
      win.control('btn_ArmorTab').onClick(() => { st.costumeView = false; renderEquip(); });
      win.control('btn_CostumeTab').onClick(() => { st.costumeView = true; renderEquip(); });
      win.control('btn_equip_lock').onClick(() => { sys.equip.data.locked = true; renderEquip(); });
      win.control('btn_equip_unlock').onClick(() => { sys.equip.data.locked = false; renderEquip(); });
      win.control('btn_preview_off').onClick(() => sys.windows.open('presetpreview'));
      win.control('btn_preview_on').onClick(() => sys.windows.close('presetpreview'));
      win.control('btn_CostumeBag').onClick(() => g.uiwin.toggle('costumebag'));
      const lockBag = () => { sys.bag.locked = !sys.bag.locked; renderBag(); };
      win.control('btn_LockBag').onClick(lockBag).onRightClick(lockBag);
      win.control('btn_drop').onClick(() => sys.dropDilAsk());
      // ui_invenwnd_base_renew btn_alignment (tooltip 2000:60) sorts the open bag, btn_alignment_all (2000:61) every unlocked
      // bag; both confirm with Global's sort warning window, lbl_msg = 260:41 (current) / 260:42 (all), not the 2000:60/61 tooltips, (dialogs.js confirmSort, option sortMsg). Online the host sorts
      // (network/items.js sortitems), offline the bag model (model.js sort).
      const sortBag = async (all) => {
        if (!await confirmSort(sys, sys.str(260, all ? 42 : 41) || '')) return;
        const ok = await sys.bag.sort(all ? null : st.page);
        if (ok !== false) { sys.changed?.('inventory'); renderBag(); }
      };
      win.control('btn_alignment').onClick(() => void sortBag(false));
      win.control('btn_alignment_all').onClick(() => void sortBag(true));
      // while the stash is open, clicking the dil box deposits dil into it (260:9 "Deposit")
      const deposit = () => { if (sys.stashIsOpen?.()) sys.stashDepositDil(); };
      win.control('pan_moneymark').onClick(deposit);
      win.control('lbl_money').onClick(deposit);
      const search = win.control('pan_itemsearch');
      win.control('btn_search_open').onClick(() => { search.show(); win.control('btn_search_open').hide(); win.control('btn_search_close').show(); });
      win.control('btn_search_close').onClick(() => { search.hide(); win.control('btn_search_close').hide(); win.control('btn_search_open').show(); st.search = ''; renderBag(); });
      const doSearch = () => { st.search = String(win.control('edit_text').getValue?.() || '').trim().toLowerCase(); renderBag(); };
      win.control('btn_itemsearch').onClick(doSearch);
      win.control('edit_text').on('enter', doSearch);
      win.control('btn_initsearch').onClick(() => { win.control('edit_text').setValue?.(''); st.search = ''; renderBag(); });

      // Keep the hidden inventory's current page/equipment sheets warm after canonical rewards/equipment arrive.
      const refresh = () => render();
      g.events.on('inventory', refresh);
      g.events.on('equip', refresh);
      g.events.on('dil', () => { if (win.isOpen) win.control('lbl_money').setDil(g.save.dil); });
      g.events.on('levelup', refresh);
    },
    onOpen() { render(); },
    update(win) {
      // Only repaint when an expiry actually changes appearance, rather than rebuilding every 120 frames.
      if (Date.now() >= (st.nextExpiry || Infinity)) renderBag();
    },
  });

  /** Is the pointer of a (release) event over the player's own character in the 3D view? */
  function overPlayer(ev) {
    const cv = g.canvas || g.renderer?.domElement;
    if (!ev || !cv || !g.player || typeof g.pickActor !== 'function') return false;
    const r = cv.getBoundingClientRect();
    if (!r.width || !r.height) return false;
    const ndc = { x: ((ev.clientX - r.left) / r.width) * 2 - 1, y: -((ev.clientY - r.top) / r.height) * 2 + 1 };
    try { return g.pickActor(ndc, a => a === g.player) === g.player; } catch { return false; }
  }

  function dropOnBag(d, page, x, y) {
    if(d.from==='cursor'){
      const [w,h]=sys.bag.sizeOf(d.itemIndex),occ=sys.bag.occupants(page,x,y,w,h);
      if(occ.length>1||sys.bag.locked||occ.some(item=>sys.reserved?.has(item.uid)))return false;
      const stoneTarget=cursorStoneTarget(sys,d.itemIndex,occ);if(stoneTarget)return cursorStoneInsert(sys,stoneTarget);
      return cursorActionResult(sys,sys.cursorPlace('bag',{page,x,y,targetUid:occ[0]?.uid??null}));
    }
    // A server profile refresh can replace instance objects while the cursor
    // stays held. Resolve the owned bag item again before footprint/swap work.
    if (d.from === 'bag') {
      const current = sys.bag.list.find(item => item.uid === (d.uid || d.inst?.uid));
      if (!current) return false;
      d = { ...d, inst: current };
    }
    if (d.from === 'bag') {
      if (d.split) { sys.splitAsk(d.inst, page, x, y); return true; }
      // a socket stone dropped on an item with sockets is inserted into it (socket.js insertStone)
      const sd = sys.db.def(d.itemIndex);
      if (sd && Number(sd.type) === 1 && Number(sd.code) === 0 && sys.insertStone) {
        const [w, h] = sys.bag.sizeOf(d.itemIndex);
        const occ = sys.bag.occupants(page, x, y, w, h, d.inst);
        const tdef = occ.length === 1 ? sys.db.def(occ[0].itemIndex) : null;
        if (tdef?.slot) { sys.insertStone(d.inst, occ[0]); return true; }
      }
      const [w, h] = sys.bag.size(d.inst);
      const displaced = sys.bag.occupants(page, x, y, w, h, d.inst);
      const displacedUid = displaced.length === 1 ? displaced[0].uid : null;
      const r = sys.bag.moveTo(d.inst, page, x, y);
      if (r?.then) return displacedUid ? itemSwapResult(sys, r, d, displacedUid) : r;
      if (!r) return false;
      sys.changed('move');
      return displacedUid ? itemSwapResult(sys, true, d, displacedUid) : true;
    }
    if (d.from === 'equip') {
      const [w, h] = sys.bag.sizeOf(d.itemIndex);
      const displaced = sys.bag.occupants(page, x, y, w, h);
      return itemSwapResult(sys, sys.receiveInBag(d, page, x, y), d, displaced.length === 1 ? displaced[0].uid : null);
    }
    return sys.receiveInBag(d, page, x, y);
  }

  function wireSlot(ctrl, pi) {
    // weapon tab II swaps the pair into slots 4/5 (Equipment.swapWeaponTab), so a slot control always shows its own id
    const slotOf = () => ctrl.data.slot;
    ctrl.setTooltip(() => {
      const inst = sys.equip.get(slotOf(), pi);
      return inst ? buildTooltip(sys, inst, { where: 'equip' }) : null;
    });
    ctrl.makeDraggable((e) => {
      const inst = sys.equip.get(slotOf(), pi);
      if (!inst) return null;
      if (g.chatLinks?.fromClick?.(inst, e)) return null;   // CHAT-LINKS: Shift + click with the chat input open = link it
      // Ctrl + left click registers the equipped item in other preset tabs (preset tooltip 910:18): Global's Select Preset box
      if (e?.ctrlKey || isCtrl(g)) { void clonePresetSelect(sys, inst, slotOf(), pi); return null; }
      if (sys.equip.data.locked) return null;
      const payload = itemPayload(sys, inst, 'equip', { slot: slotOf(), preset: pi });
      if (!payload.icon) payload.icon = ctrl._itemIconPainted || null;
      return { ...payload, onDropOutside: () => false };
    });
    ctrl.acceptDrop({
      accept: (d) => d?.kind === 'item' && (d.from === 'cursor' || d.from === 'bag' || d.from === 'equip' || d.from === 'costume'),
      drop: (d) => {
        // Explicit drops use the selected slot; right-click still chooses its own slot.
        const def = sys.db.def(d.itemIndex);
        const target = slotOf();
        if(d.from==='cursor')return cursorActionResult(sys,sys.cursorPlace('equip',{slot:target,preset:pi,targetUid:sys.equip.get(target,pi)?.uid??null}));
        // Putting a held item back where it came from cancels the pickup. It
        // must not send an equip swap from a slot to itself: the host rejects
        // that request and the cursor remains stuck holding the item.
        if (returnsToSourceSlot(d, target, pi)) return true;
        const base = target === 104 ? 4 : target === 105 ? 5 : target;
        if (!sys.equip.slotsFor(def).includes(base)) {
          sys.msg(40, 56);
          return false;
        }
        const displaced = sys.equip.get(target, pi)?.uid;
        return itemSwapResult(sys, sys.equipFromDrag(d, target, pi), d, displaced);
      },
    });
    // an item registered in several presets asks which to remove it from (inven/ui_selectpresetunequipwnd)
    ctrl.onRightClick(() => unequipSelect(sys, slotOf(), pi));
  }

  function render() {
    const win = st.win;
    if (!win) return;
    renderEquip();
    renderBag();
    const tips = win.mgr?.tooltips;
    if (tips?.owner?.win === win) tips.refresh?.();
  }

  function renderEquip() {
    const win = st.win;
    const E = sys.equip.data;
    for (let pi = 0; pi < 5; pi++) {
      win.control(`btn_preset_${pi + 1}`).setChecked(pi === E.active);
      const pan = win.control(`pan_Preset_${pi + 1}`);
      pan.setVisible(pi === E.active);
      if (pi !== E.active) continue;
      for (const id of SLOT_IDS) {
        const ctrl = pan.control(`suititem_${id}`);
        if (ctrl.missing) continue;
        const inst = sys.equip.get(id, pi);
        const held = st.held?.from === 'equip' && st.held.slot === id && st.held.preset === pi;
        slotIcon(sys, ctrl, held ? null : inst);
        if (id === S.armor) ctrl.setVisible(!st.costumeView);
        if (id === S.costume) ctrl.setVisible(st.costumeView);
      }
    }
    win.control('btn_weapontab_0').setChecked(!E.weaponTab);
    win.control('btn_weapontab_1').setChecked(!!E.weaponTab);
    win.control('btn_ArmorTab').setChecked(!st.costumeView);
    win.control('btn_CostumeTab').setChecked(st.costumeView);
    win.control('pan_CostumeBG').setVisible(st.costumeView);
    win.control('btn_equip_lock').setVisible(!E.locked);
    win.control('btn_equip_unlock').setVisible(!!E.locked);
    win.control('pan_equip_lock_0').setVisible(!!E.locked);
    const pv = g.uiwin.isOpen('presetpreview');
    win.control('btn_preview_off').setVisible(!pv);
    win.control('btn_preview_on').setVisible(pv);
  }

  function renderBag() {
    const win = st.win;
    if (!win) return;
    const unlocked = sys.bag.unlocked;
    if (st.page >= unlocked) st.page = 0;
    const q = st.search;
    const match = (inst) => !!q && String(inst.name || sys.db.name(inst.itemIndex)).toLowerCase().includes(q);
    for (let i = 0; i < 7; i++) {
      const tab = win.control(`btn_changebag_${i}`);
      tab.setChecked(i === st.page);
      tab.control('btn_lock').setVisible(i >= unlocked);
      win.control(`pan_searchmark_${i}`).setVisible(!!q && sys.bag.items(i).some(match));
    }
    const bag = win.control('slotbag');
    const held = st.held?.from === 'bag' ? st.held.uid : null;
    const { items } = gridItems(sys, bag, sys.bag, st.page, { dim: q ? (inst) => !match(inst) : null, mark: q ? match : null, held });
    void setReadyGridItems(sys, bag, items);
    st.nextExpiry = Infinity;
    const now = Date.now();
    for (const item of items) if (item.data.expiresAt > now) st.nextExpiry = Math.min(st.nextExpiry, item.data.expiresAt);
    win.control('pan_LockBag').setVisible(!!sys.bag.locked);
    win.control('lbl_money').setDil(g.save.dil);
  }

  return { render, renderBag, renderEquip, state: st };
}
