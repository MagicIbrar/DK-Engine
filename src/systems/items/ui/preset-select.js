// Global boxes of the 5-preset equipment (items/equip.js; save.equip.presets):
//   inven/ui_selectpresetequipwnd     Ctrl + left click on a worn item (itemdesc "Ctrl + Left Click to clone equipped item to
//                                     another preset tab"): 80:97 "Select Preset", 81:118 "Equip this item to the preset slot?",
//                                     a check box per preset and Select All (260:49); 260:75 "Not allowed" where it cannot go
//                                     (equip.js presetCloneStates: the slot holds another item, or the preset's weapons refuse it).
//   inven/ui_selectpresetunequipwnd   right click on a worn item registered in several presets: 81:119 "Remove this item from
//                                     the preset slot?", 260:63 "None" on the presets that do not hold it.
//   messagebox/ui_presetcheckmessagebox  option presetMsg "Item Equipment Info Notification" (check_Option 260:28 "Don't see
//                                     anymore" turns it off): after such a change, 81:117 "An item is equipped in the preset
//                                     slot." with what each preset now wears in that slot (260:59 "No item equipped").
import { PRESETS, presetCloneStates, presetsHolding } from '../equip.js';

const SCRIPTS = Object.freeze({
  equip: 'game2/inven/ui_selectpresetequipwnd.txt',
  unequip: 'game2/inven/ui_selectpresetunequipwnd.txt',
  notice: 'game2/messagebox/ui_presetcheckmessagebox.txt',
});
const itemName = (sys, inst) => sys.db.def(inst?.itemIndex)?.name || inst?.name || '';
const msgStr = (sys, cate, code, fallback) => sys.str?.(cate, code) || fallback;
const sessionGuard = game => {
  const id=game.save?.id,network=game.network,token=network?.token;
  return ()=>game.save?.id===id&&game.network===network&&game.network?.token===token;
};

/**
 * Opens the select box; resolves the ticked presets (array) or null when cancelled. `rows[t]` = {allowed, checked, locked}:
 * allowed rows show a check box, the others their lbl_None_N label; locked rows are ticked and cannot be changed.
 */
async function selectBox(sys, mode, inst, rows, valid) {
  const ui = sys.game.uiwin;
  const win = await ui.create(SCRIPTS[mode], { modal: true, escClose: true, remember: false, disposeOnClose: true });
  if(!valid()){win.close('stale');return null;}
  win.control('lbl_itemName')?.setText?.(itemName(sys, inst));
  const boxes = rows.map((r, t) => {
    const box = win.control(`check_box_${t}`);
    box.setVisible?.(r.allowed || r.locked);
    win.control(`lbl_None_${t}`)?.setVisible?.(!r.allowed && !r.locked);
    box.setChecked?.(!!(r.checked || r.locked));
    box.setEnabled?.(r.allowed && !r.locked);
    return box;
  });
  const all = win.control('check_all_5'), free = rows.map((r, t) => r.allowed && !r.locked ? t : -1).filter(t => t >= 0);
  const syncAll = () => all.setChecked?.(free.length > 0 && free.every(t => boxes[t].isChecked?.()));
  all.setEnabled?.(free.length > 0);
  all.on?.('change', v => { for (const t of free) boxes[t].setChecked?.(v); });
  for (const t of free) boxes[t].on?.('change', syncAll);
  syncAll();
  return new Promise(resolve => {
    let done = false;
    const finish = v => { if (done) return; done = true; resolve(v); win.close('done'); };
    win.control('btn_confirm').onClick(() => finish(valid()?free.filter(t => boxes[t].isChecked?.()):null));
    win.control('btn_cancel').onClick(() => finish(null));
    win.once('close', () => { if (!done) { done = true; resolve(null); } });
    ui.openWindow(win);
  });
}

/** messagebox/ui_presetcheckmessagebox: what each preset wears in `slot` after a registration change. */
export async function presetNotice(sys, inst, slot) {
  const g = sys.game, ui = g.uiwin;
  if (!ui?.create || g.options?.get?.('presetMsg') === false) return;
  const valid=sessionGuard(g);
  const win = await ui.create(SCRIPTS.notice, { modal: true, escClose: true, remember: false, disposeOnClose: true });
  if(!valid()){win.close('stale');return;}
  win.control('lbl_title')?.setText?.(msgStr(sys, 80, 97, 'Select Preset'));
  win.control('lbl_itemName')?.setText?.(itemName(sys, inst));
  win.control('lbl_text')?.setText?.(msgStr(sys, 81, 117, 'An item is equipped in the preset slot.'));
  for (let t = 0; t < PRESETS; t++) {
    const s = sys.equip.findSlot(inst.uid, t) ?? slot, worn = sys.equip.get(s, t);
    win.control(`lbl_EquipItemName_${t}`)?.setText?.(worn ? itemName(sys, worn) : msgStr(sys, 260, 59, 'No item equipped'));
  }
  return new Promise(resolve => {
    const finish = () => { if (valid()&&win.control('check_Option')?.isChecked?.()) g.options?.set?.({ presetMsg: false }); win.close('done'); };
    win.control('btn_confirm').onClick(finish);
    win.once('close', () => resolve());
    ui.openWindow(win);
  });
}

/** Ctrl + left click on a worn item: tick the presets to register it in (Global inven/ui_selectpresetequipwnd). */
export async function clonePresetSelect(sys, inst, slot, fromPreset) {
  const sameSession=sessionGuard(sys.game),uid=inst?.uid;
  const valid=()=>sameSession()&&!!uid&&sys.equip.get(slot,fromPreset)?.uid===uid;
  if(!valid())return false;
  const states = presetCloneStates(sys.equip, slot, fromPreset);
  if (!states || !sys.game.uiwin?.create) return sys.clonePreset(inst, slot, fromPreset);
  const targets = await selectBox(sys, 'equip', inst, states.map(s => ({ allowed: s === 'free', locked: s === 'source' || s === 'holds' })),valid);
  if (!targets?.length||!valid()) return false;
  const ok = await sys.clonePreset(inst, slot, fromPreset, targets);
  if (ok&&valid()) await presetNotice(sys, inst, slot);
  return ok;
}

/** Right click on a worn item: one preset unequips at once, several ask which (Global inven/ui_selectpresetunequipwnd). */
export async function unequipSelect(sys, slot, fromPreset) {
  const sameSession=sessionGuard(sys.game),inst = sys.equip.get(slot, fromPreset),uid=inst?.uid;
  const valid=()=>sameSession()&&!!uid&&sys.equip.get(slot,fromPreset)?.uid===uid;
  if(!valid())return false;
  const holders = inst ? presetsHolding(sys.equip, inst.uid) : [];
  if (holders.length < 2 || !sys.game.uiwin?.create) return sys.unequip(slot, fromPreset);
  const targets = await selectBox(sys, 'unequip', inst, Array.from({ length: PRESETS }, (_, t) => ({ allowed: holders.includes(t), checked: t === fromPreset })),valid);
  if (!targets?.length||!valid()||targets.some(t=>sys.equip.findSlot(uid,t)==null)) return false;
  // the bag receives the item with its last registration (Equipment.remove)
  let ok = true;
  for (const t of targets) {
    if(!sameSession()){ok=false;break;}
    const s=sys.equip.findSlot(uid,t);
    if(s==null||!await sys.unequip(s,t)){ok=false;break;}
  }
  if (sameSession()&&presetsHolding(sys.equip, inst.uid).length) await presetNotice(sys, inst, slot);
  return ok;
}
