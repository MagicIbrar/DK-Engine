// Small modal dialogs of the shops, each the original window script:
//   askQuantity     store/ui_storebuyitem_renew.txt  ("Buy Item": price per item, quantity, purchase price, my funds)
//   exchangeConfirm msgbox/ui_buyexchangeitem.txt    ("Buy Item": item, 170/9 one at a time)
//   buyConfirm      msgbox/ui_buyitem.txt            ("Purchase Information": 110/17 Would you like to purchase?)
//   sellConfirm     msgbox/ui_sellitem.txt           ("Sales Information": 340/11 Would you like to sell?)
//   exchangeWindow  exchangeshop/ui_confirmwnd.txt   ("Exchange Window": name, pay item, count, 2006/4)
import { setFootprintIcon, fmtNum, str } from './common.js';

async function modal(game, script, setup) {
  const win = await game.uiwin.create(script, { modal: true, escClose: true, remember: false, disposeOnClose: true, autoClose: true });
  return new Promise((resolve) => {
    let done = false;
    const finish = (v) => { if (done) return; done = true; resolve(v); };
    win.once('close', (r) => finish(r === 'yes' ? (win.data.value ?? 'yes') : null));
    setup(win, (v) => { win.data.value = v; win.close('yes'); });
    win.find('btn_no')?.on('click', () => win.close('no'));
    win.find('btn_cancel')?.on('click', () => win.close('no'));
    game.uiwin.openWindow(win);
  });
}

export function createDialogs(game) {
  return {
    /** Quantity popup. Resolves the quantity (>= 1) or null. */
    askQuantity({ itemIndex, name, unitPrice = 0, funds = 0, max = 9999, currency = 'Dil' }) {
      return modal(game, 'game2/store/ui_storebuyitem_renew.txt', (win, ok) => {
        const edit = win.control('edit_buynum');
        const sfx = currency === 'Dil' ? '' : ` ${currency}`;
        win.control('lbl_item').setText(name);
        win.control('lbl_pricenum').setText(fmtNum(unitPrice) + sfx);
        if (currency === 'Dil') win.control('lbl_moneynum').setDil(funds);
        else win.control('lbl_moneynum').setText(fmtNum(funds) + sfx);
        const slot = win.find('select_item');
        if (slot) void setFootprintIcon(game, slot, itemIndex).catch(() => {});
        const limit = Math.max(1, Math.min(9999, Math.floor(Number(max)) || 9999)); // Native edit maxlength4.
        const cap = Math.max(0, Math.min(limit, unitPrice > 0 ? Math.floor(funds / unitPrice) : limit));
        const read = () => {
          const value = String(edit.getValue?.() ?? '');
          return /^\d{1,4}$/.test(value) ? Math.min(limit, Number(value)) : 0;
        };
        const allowed = n => n > 0 && n <= cap;
        const upd = () => {
          const n = read(), total = n * unitPrice;
          win.control('lbl_totalpricenum').setText(fmtNum(total) + sfx).setTextColor(total > funds ? 'ffff4040' : 'ffffffff');
          win.control('btn_yes').setEnabled(allowed(n));
        };
        const submit = () => { const n = read(); if (allowed(n)) ok(n); };
        edit.setValue?.('1');
        edit.on('change', upd);
        edit.on('enter', submit);
        upd();
        win.control('btn_yes').on('click', submit);
        setTimeout(() => { edit.focus?.(); try { edit.el.querySelector('input')?.select?.(); } catch { /* ignore */ } }, 0);
        win.data.cap = cap;
      });
    },
    /** Exchange-priced purchase: one at a time. Resolves 'yes' or null. */
    exchangeConfirm({ name }) {
      return modal(game, 'game2/msgbox/ui_buyexchangeitem.txt', (win, ok) => {
        win.control('lbl_text').setText(name);
        win.control('btn_yes').on('click', () => ok('yes'));
      });
    },
    /** Purchase confirmation (repurchase, supply machine...). */
    buyConfirm({ name, price }) {
      return modal(game, 'game2/msgbox/ui_buyitem.txt', (win, ok) => {
        const lbl = win.control('pan_notifylabel');
        const q = str(game, 110, 17, 'Would you like to purchase?');
        lbl.setText(price != null ? `${name} (${fmtNum(price)} Dil) - ${q}` : `${name} - ${q}`);
        lbl.setRect(8, 60, 216, 14);
        win.control('btn_yes').on('click', () => ok('yes'));
      });
    },
    /** Sell confirmation. */
    sellConfirm({ name, price }) {
      return modal(game, 'game2/msgbox/ui_sellitem.txt', (win, ok) => {
        const lbl = win.control('pan_notifylabel');
        lbl.setText(`${name}: ${fmtNum(price)} Dil - ${str(game, 340, 11, 'Would you like to sell?')}`);
        lbl.setRect(8, 60, 216, 14);
        win.control('btn_yes').on('click', () => ok('yes'));
      });
    },
    /** Exchange-center confirmation window. */
    exchangeWindow({ name, payName, payCount }) {
      return modal(game, 'game2/exchangeshop/ui_confirmwnd.txt', (win, ok) => {
        win.control('lbl_exchangename').setText(name);
        win.control('lbl_payname').setText(payName);
        win.control('lbl_paycount').setText(`x ${fmtNum(payCount)}`);
        win.control('btn_yes').on('click', () => ok('yes'));
        win.find('btn_close')?.on('click', () => win.close('no'));
      });
    },
  };
}
