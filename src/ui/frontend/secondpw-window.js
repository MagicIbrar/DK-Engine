// The 2nd password window (Global script/ui/game2/ui_secondpwwnd.txt, window `secondpw`) driven by SecondPassword
// (secondpw-rules.js). The frontend asks after account sign-in and before character selection or creation.
// Returning to characters reuses only the current server session's verified status.
// Keypad: btn_number_0..9, btn_backspace, btn_ok (30:106), btn_change (30:105), btn_backtosecondpwwnd (30:122 Back).
// lbl_secondpw = 30:103 title, lbl_explain = the current 30:xxx prompt/result, lbl_password = the masked entry.
// Backed by the server (ServerSecondPassword, /api/auth/secondpw). localPinStore is the old engine-local store, kept only
// for the offline rules test; its data is ignored by the live signed-in flow.
import { SecondPassword, ServerSecondPassword, SECONDPW_SCRIPT, SECONDPW_TEXT, SECONDPW_CATE, MAX_DIGITS } from './secondpw-rules.js';

export function localPinStore(account, storage = globalThis.localStorage) {
  const key = `dk.secondpw.${String(account || 'local')}`;
  return {
    get() { try { return JSON.parse(storage?.getItem(key) || 'null'); } catch { return null; } },
    set(rec) { storage?.setItem(key, JSON.stringify(rec)); },
  };
}

/** Opens the window; resolves true once the PIN is verified (or newly set), false when closed/locked. */
export async function askSecondPassword(uim, pw, { text = (code) => SECONDPW_TEXT[code] } = {}) {
  const win = await uim.create(SECONDPW_SCRIPT, { name: 'secondpw', modal: true, escClose: true, remember: false, disposeOnClose: true });
  const c = id => win.control ? win.control(id) : win.find(id);
  const t = code => text(code, SECONDPW_CATE) || SECONDPW_TEXT[code];
  let entry = '', mode = pw.exists ? 'verify' : 'set1', first = '', current = '';
  const show = () => c('lbl_password')?.setText('*'.repeat(entry.length));
  const say = (codeOrText) => c('lbl_explain')?.setText(typeof codeOrText === 'number' ? t(codeOrText) : codeOrText);
  const start = (m, code) => { mode = m; entry = ''; show(); say(code); };
  c('lbl_secondpw')?.setText(t(103));
  c('btn_change')?.setEnabled?.(pw.exists);
  start(mode, pw.exists ? 104 : 107);
  return new Promise(resolve => {
    let done = false;
    const finish = ok => { if (done) return; done = true; if (win.isOpen !== false) win.close(ok ? 'yes' : 'no'); resolve(ok); };
    win.once?.('close', () => finish(false));
    for (let d = 0; d <= 9; d++) c(`btn_number_${d}`)?.onClick(() => { if (entry.length < MAX_DIGITS) { entry += d; show(); } });
    c('btn_backspace')?.onClick(() => { entry = entry.slice(0, -1); show(); });
    c('btn_backtosecondpwwnd')?.onClick(() => start(pw.exists ? 'verify' : 'set1', pw.exists ? 104 : 107));
    c('btn_change')?.onClick(() => { if (pw.exists) start('cur', 111); });
    c('btn_ok')?.onClick(async () => {
      const v = entry;
      if (mode === 'verify') {
        const res = await pw.verify(v);
        if (res.ok) return finish(true);
        if (res.code === 116) { say(116); return setTimeout(() => finish(false), 0); }
        entry = ''; show(); return say(res.text);
      }
      if (mode === 'set1') { first = v; return start('set2', 110); }
      if (mode === 'set2') { const res = await pw.set(first, v); if (res.ok) return finish(true); return start('set1', res.code); }
      if (mode === 'cur') { current = v; return start('new1', 109); }
      if (mode === 'new1') { first = v; return start('new2', 110); }
      if (mode === 'new2') { const res = await pw.change(current, first, v); start('verify', res.ok ? 104 : res.code); if (res.code === 112) say(res.text); return; }
    });
    uim.openWindow?.(win);
  });
}
export { SecondPassword, ServerSecondPassword };
