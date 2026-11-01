// Original login UI backed by existing server accounts or a verified website session.
import { configureAccountSaves, flushCharacterSaves } from '../../game/save.js';
const LAST_ID_KEY = 'dekaron-solo:last-id';
async function api(path, body) {
  const r = await fetch(path, { credentials: 'same-origin', ...(body === undefined ? {} : { method: 'POST', headers: { 'Content-Type': 'application/json' }, body: JSON.stringify(body) }) });
  const data = await r.json();
  if (!r.ok) throw new Error(data.error || 'Account service unavailable.');
  return data;
}

export class LocalAccounts {
  constructor({ request = api, configure = configureAccountSaves, flush = flushCharacterSaves } = {}) {
    this.request = request; this.configure = configure; this.flush = flush;
  }
  async restore({ configure = true } = {}) {
    let data;
    try { data = await this.request('/api/auth/me'); } catch { await this.configure(null); return null; }
    if (!data.id) { await this.configure(null); return null; }
    if (configure) await this.configure(data.id);
    return data.id;
  }
  async login(id, password, { configure = true } = {}) {
    const typed = String(id || '').trim();
    try {
      let account;
      if (password) {
        const data = await this.request('/api/auth/login', { id: typed, password });
        if (!data.id) throw new Error('The server did not confirm an account.');
        if (configure) await this.configure(data.id); account = data.id;
      } else {
        account = await this.restore({ configure });
        if (!account) return { ok: false, message: 'Enter your account ID and password. Use Sign Up in the launcher or on the website to create an account first.' };
        if (typed && typed.toLowerCase() !== String(account).toLowerCase()) return { ok: false, message: 'Enter the password for this account, or use the ID already signed in on the website.' };
      }
      try { globalThis.localStorage?.setItem(LAST_ID_KEY, account); } catch { /* private mode */ }
      return { ok: true, account };
    } catch (err) { return { ok: false, message: err.message || 'Login failed. Please try again.' }; }
  }

  /** The ID typed at the last login (the client pre-fills it). */
  lastId() {
    try { return globalThis.localStorage?.getItem(LAST_ID_KEY) || ''; } catch { return ''; }
  }

  async logout() {
    if (await this.flush() === false) throw new Error('Character saves could not finish. Your local backup is retained.');
    await this.request('/api/auth/logout', {});
    await this.configure(null);
  }
}
