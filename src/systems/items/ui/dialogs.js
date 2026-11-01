// Small item dialogs of the original client:
//   game2/inven/ui_stackdivide.txt   "Split Stack"   (edit_text digits, btn_confirm / btn_cancel)
//   game2/inven/ui_dropmoney.txt     "Drop dil"      (same layout)
//   game2/inven/ui_dropmsgwnd.txt    discard confirmation (lbl_msg item name, lbl_tagmsg, "Do not show this again")
//   game2/storage/ui_withdrawalwnd.txt  stash dil deposit / withdraw amount
// Each resolves a value (number / true) or null when cancelled.

async function amountBox(sys, script, { title = null, text = null, max = Infinity, value = '' } = {}) {
  const g = sys.game;
  const win = await g.uiwin.create(script, { modal: true, escClose: true, remember: false, disposeOnClose: true });
  if (title) win.find('lbl_title')?.setText(title);
  if (text) win.find('lbl_text')?.setText(text);
  const edit = win.control('edit_text');
  edit.setValue?.(String(value));
  return new Promise((resolve) => {
    let done = false;
    const finish = (v) => { if (done) return; done = true; resolve(v); win.close('done'); };
    const ok = () => {
      const n = Math.floor(Number(String(edit.getValue?.() || '').replace(/[^0-9]/g, '')) || 0);
      finish(n > 0 ? Math.min(n, max) : null);
    };
    // (the amount boxes use btn_confirm / btn_cancel, the withdrawal box btn_yes / btn_no)
    win.find('btn_confirm')?.onClick(ok);
    win.find('btn_yes')?.onClick(ok);
    win.find('btn_cancel')?.onClick(() => finish(null));
    win.find('btn_no')?.onClick(() => finish(null));
    edit.on?.('enter', ok);
    win.once('close', () => { if (!done) { done = true; resolve(null); } });
    g.uiwin.openWindow(win);
    setTimeout(() => edit.focus?.(), 0);
  });
}

/** Split Stack: how many to take off the stack (1 .. count-1). */
export function askSplit(sys, inst) {
  return amountBox(sys, 'game2/inven/ui_stackdivide.txt', { max: Math.max(1, (inst.count || 1) - 1), value: Math.floor((inst.count || 1) / 2) });
}
/** Drop dil: amount to discard. */
export function askDropDil(sys) {
  return amountBox(sys, 'game2/inven/ui_dropmoney.txt', { max: Number(sys.game.save.dil) || 0, value: '' });
}
/** Stash deposit / withdraw amount (ui_withdrawalwnd.txt). */
export function askAmount(sys, title, max) {
  return amountBox(sys, 'game2/storage/ui_withdrawalwnd.txt', { title, max, value: '' });
}
/** Inventory DIL into the stash: Global game2/inven/ui_savemoney.txt (100:134 "Deposit", whose title string Global names
 *  "Inventory DIL Stash Storing"; 12-digit field like ui_withdrawalwnd). The script keeps its own texts. */
export function askDeposit(sys, max) {
  return amountBox(sys, 'game2/inven/ui_savemoney.txt', { max, value: '' });
}
/** Inventory / stash sort warning: Global game2/inven/ui_alignmentmsgwnd.txt (2001:187 title, lbl_tagmsg 260:43 "Are you sure
 *  you want to sort them?", checkbox 260:28 "Don't see anymore", Confirm / Cancel). `text` fills lbl_msg (which sort). Skipped
 *  while the option "Inventory/Stash Sort Warning Message" (sortMsg, option check_showalignmentmsg) is off; confirming with the
 *  check box ticked turns that option off. Resolves true to sort. */
export async function confirmSort(sys, text = '') {
  const g = sys.game;
  if (g.options?.get?.('sortMsg') === false) return true;
  const win = await g.uiwin.create('game2/inven/ui_alignmentmsgwnd.txt', { modal: true, escClose: true, remember: false, disposeOnClose: true });
  if (text) win.control('lbl_msg')?.setText?.(text);
  return new Promise((resolve) => {
    let done = false;
    const finish = (v) => {
      if (done) return; done = true;
      if (v && win.control('checkbox').isChecked?.()) g.options?.set?.({ sortMsg: false });
      resolve(v); win.close('done');
    };
    win.control('btn_yes').onClick(() => finish(true));
    win.control('btn_no').onClick(() => finish(false));
    win.once('close', () => { if (!done) { done = true; resolve(false); } });
    g.uiwin.openWindow(win);
  });
}

/** Discard confirmation. Resolves true to discard. Honors "Do not show this again". */
export async function confirmDiscard(sys, inst) {
  const g = sys.game;
  // a cash item (items.json `cash`): Global msgbox/cashitem/ui_dropcashitem (100:24, 1002:6 "Items are automatically deleted
  // when discarded. Would you like to discard this item?", Discard / Cancel). That box has no "Do not show this again".
  if (sys.db.def(inst?.itemIndex)?.cash && g.uiwin?.msgbox) return (await g.uiwin.msgbox(null, { kind: 'yesno', script: 'game2/msgbox/cashitem/ui_dropcashitem.txt', scripted: true })) === 'yes';
  if (g.settings?.skipDiscardConfirm) return true;
  const win = await g.uiwin.create('game2/inven/ui_dropmsgwnd.txt', { modal: true, allowDirectionalMovement: true, escClose: true, remember: false, disposeOnClose: true });
  const def = sys.db.def(inst.itemIndex);
  win.control('lbl_title').setText(sys.str(260, 7) || 'Drop');
  win.control('lbl_msg').setText(`[${def?.name || inst.name}]${(inst.count || 1) > 1 ? ` x${inst.count}` : ''}`);
  return new Promise((resolve) => {
    let done = false;
    const finish = (v) => {
      if (done) return; done = true;
      if (v && win.control('checkbox').isChecked?.()) { g.settings.skipDiscardConfirm = true; g.setSettings?.({ skipDiscardConfirm: true }); }
      resolve(v); win.close('done');
    };
    win.control('btn_yes').onClick(() => finish(true));
    win.control('btn_no').onClick(() => finish(false));
    win.once('close', () => { if (!done) { done = true; resolve(false); } });
    g.uiwin.openWindow(win);
  });
}
