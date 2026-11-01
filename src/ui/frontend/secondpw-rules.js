// 2nd password (PIN) rules: Global script/ui/game2/ui_secondpwwnd.txt (window `secondpw`: lbl_secondpw 30:103, btn_ok 30:106,
// btn_change 30:105, btn_backtosecondpwwnd 30:122, lbl_explain, lbl_password) and ui_blankpwwnd.txt (window `login`,
// pan_error / lbl_message for the result text). Every text and limit below is stringtable_loginmsg.txt cate 30:
//   103 "2nd Password", 104 enter, 107 set, 108 change, 109 new, 110 re-enter new, 111 current,
//   112 "Incorrect password. Wrong input count : %d/%d", 113 not exist, 115 already set, 116 more than 5 wrong (locked),
//   118 change failed, 119 register failed, 120 "must be between 4 & 12 digits", 121 the two entries differ.
// The legacy offline fixture below stores a salted SHA-256 locally. The live
// ServerSecondPassword path uses the signed-in account API and server-side scrypt.
export const SECONDPW_SCRIPT = 'game2/ui_secondpwwnd.txt';
export const SECONDPW_RESULT_SCRIPT = 'game2/ui_blankpwwnd.txt';
export const SECONDPW_CATE = 30;
export const SECONDPW_TEXT = {
  103: '2nd Password', 104: 'Please enter your 2nd Password', 105: 'Change', 106: 'Confirm', 107: 'Set a 2nd Password',
  108: 'Change your 2nd Password', 109: 'Please enter your new 2nd Password', 110: 'Please reenter your new 2nd Password',
  111: 'Please enter your current 2nd Password', 112: 'Incorrect password. Wrong input count : %d/%d', 113: '2nd password is not exist',
  115: '2nd password was set already', 116: 'Wrong PIN is entered more than 5 times', 118: 'Cannot change 2nd Password',
  114: 'Unidentified error', 117: 'Server error', 119: 'Cannot regist 2nd Password', 120: '2nd password must be between 4 & 12 digits', 121: 'The two passwords you entered are different', 122: 'Back',
};
export const MIN_DIGITS = 4, MAX_DIGITS = 12, MAX_WRONG = 5;   // 30:120 and 30:116

export const validPin = pin => typeof pin === 'string' && new RegExp(`^\\d{${MIN_DIGITS},${MAX_DIGITS}}$`).test(pin);

async function digest(salt, pin) {
  const bytes = new TextEncoder().encode(`${salt}:${pin}`);
  const h = await globalThis.crypto.subtle.digest('SHA-256', bytes);
  return [...new Uint8Array(h)].map(b => b.toString(16).padStart(2, '0')).join('');
}
const newSalt = () => [...globalThis.crypto.getRandomValues(new Uint8Array(16))].map(b => b.toString(16).padStart(2, '0')).join('');
const fmt = (s, ...v) => { let i = 0; return s.replace(/%d/g, () => String(v[i++])); };

/**
 * State machine over a record `{salt, hash, wrong}` held by `store` ({get(), set(rec)}).
 * Every result is {ok, code, text} with code = the 30:xxx string to show.
 */
export class SecondPassword {
  constructor(store) { this.store = store; }
  get record() { return this.store.get() || null; }
  get exists() { return !!this.record?.hash; }
  get locked() { return (this.record?.wrong || 0) >= MAX_WRONG; }
  /** The prompt the window opens with: 104 enter when set, 107 set when not. */
  prompt() { return this.exists ? r(true, 104) : r(true, 107); }

  async set(pin, again) {
    if (this.exists) return r(false, 115);
    if (!validPin(pin)) return r(false, 120);
    if (pin !== again) return r(false, 121);
    const salt = newSalt();
    try { this.store.set({ salt, hash: await digest(salt, pin), wrong: 0 }); } catch { return r(false, 119); }
    return r(true, 106);
  }

  async verify(pin) {
    const rec = this.record;
    if (!rec?.hash) return r(false, 113);
    if (this.locked) return r(false, 116);
    if (validPin(pin) && await digest(rec.salt, pin) === rec.hash) { this.store.set({ ...rec, wrong: 0 }); return r(true, 106); }
    const wrong = (rec.wrong || 0) + 1;
    this.store.set({ ...rec, wrong });
    return wrong >= MAX_WRONG ? r(false, 116) : { ok: false, code: 112, text: fmt(SECONDPW_TEXT[112], wrong, MAX_WRONG), wrong };
  }

  async change(current, pin, again) {
    if (!this.exists) return r(false, 113);
    const v = await this.verify(current);
    if (!v.ok) return v;
    if (!validPin(pin)) return r(false, 120);
    if (pin !== again) return r(false, 121);
    const salt = newSalt();
    try { this.store.set({ salt, hash: await digest(salt, pin), wrong: 0 }); } catch { return r(false, 118); }
    return r(true, 106);
  }
}
function r(ok, code) { return { ok, code, text: SECONDPW_TEXT[code] }; }

/**
 * Server-backed 2nd password (Global ui_secondpwwnd is checked by the server: 30:114 / 30:117). Same interface as
 * SecondPassword so secondpw-window.js is unchanged; the PIN is sent once over the signed-in session and only a salted
 * scrypt hash, the wrong count and the lock live on the server account record. Old localStorage PINs are ignored.
 */
export class ServerSecondPassword {
  static async open(fetchImpl = globalThis.fetch) { const p = new ServerSecondPassword(fetchImpl); await p.refresh(); return p; }
  constructor(fetchImpl = globalThis.fetch) {
    // Browser fetch requires its Window receiver. Storing it directly as an
    // instance method causes Chromium/WebView2 to throw before sending a request.
    this.fetch = (...args) => Reflect.apply(fetchImpl, globalThis, args);
    this.status = { exists: false, locked: false, verified: false }; this.required = true;
    this.statusReady = false; this.statusError = null; this.authenticated = false;
  }
  async call(path, body) {
    let res, data;
    try {
      res = await this.fetch(`/api/auth/secondpw${path}`, { credentials: 'same-origin', ...(body === undefined ? {} : { method: 'POST', headers: { 'Content-Type': 'application/json' }, body: JSON.stringify(body) }) });
      data = await res.json();
    } catch { return r(false, 117); }
    const code = SECONDPW_TEXT[data?.code] ? data.code : (res.status >= 500 ? 117 : 114);
    if (code === 112) return { ok: false, code, text: fmt(SECONDPW_TEXT[112], data.wrong, data.max || MAX_WRONG), wrong: data.wrong };
    return { ...r(!!data?.ok, code), httpStatus: res.status, ...(data?.required === false ? { required: false } : {}), ...(typeof data?.verified === 'boolean' ? { verified: data.verified } : {}), ...(data && typeof data.exists === 'boolean' ? { exists: data.exists, locked: !!data.locked } : {}) };
  }
  // required is false for accounts the server exempts (owner launcher, NPC) and when there is no signed-in account session
  // (a local character); the server's world-join check (server/world/api.mjs requireSecondPw) stays the real gate.
  async refresh() {
    const s = await this.call('');
    this.authenticated = s.httpStatus === 200;
    this.statusReady = s.httpStatus === 401 || (s.httpStatus === 200 && (s.required === false || typeof s.exists === 'boolean'));
    this.statusError = this.statusReady ? null : s;
    this.required = !(s.required === false || s.httpStatus === 401);
    if (this.statusReady && 'exists' in s) this.status = { exists: s.exists, locked: s.locked, verified: s.verified === true };
    else this.status.verified = false;
    return s;
  }
  get exists() { return this.status.exists; }
  get locked() { return this.status.locked; }
  get verified() { return this.statusReady && this.status.verified === true; }
  prompt() { return this.locked ? r(false, 116) : this.exists ? r(true, 104) : r(true, 107); }
  async after(res) { if (res.ok) this.status = { exists: true, locked: false }; else if (res.code === 116) this.status = { exists: true, locked: true }; else if (res.code === 113) this.status = { exists: false, locked: false }; return res; }
  async set(pin, again) { if (!validPin(pin)) return r(false, 120); if (pin !== again) return r(false, 121); return this.after(await this.call('/set', { pin, again })); }
  async verify(pin) { return this.after(await this.call('/verify', { pin: String(pin) })); }
  async change(current, pin, again) { return this.after(await this.call('/change', { current: String(current), pin, again })); }
}
