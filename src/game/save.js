import {normalizeCharacterName, normalizeCharacterNameColor, characterNameKey} from './character-name.js';
import { CHAR_TRADE_ENGINE_CHOSEN } from '../config/engine-chosen-char-trade.js';
// Guest saves remain local. Signed-in accounts use a durable local cache plus versioned server snapshots.
const KEY = 'dekaron-solo:characters:v1';
let active = null, pending = null, retryTimer = null;
let status = { state: 'local', message: 'Saved on this browser.' };
const accountKey = id => `dekaron-solo:account:${id}:v1`;
function notice(state, message) {
  status = { state, message, account: active?.id || null };
  if (typeof globalThis.dispatchEvent === 'function' && typeof CustomEvent === 'function') globalThis.dispatchEvent(new CustomEvent('dekaron:save-status', { detail: status }));
}
export function getSaveStatus() { return { ...status }; }
function stored(key, fallback) { try { return JSON.parse(localStorage.getItem(key) || 'null') ?? fallback; } catch { return fallback; } }
function cache(ctx) {
  try { localStorage.setItem(accountKey(ctx.id), JSON.stringify({ revision: ctx.revision, dirty: ctx.dirty, characters: ctx.characters })); return true; }
  catch { notice('error', 'Browser save storage is full. Keep this page open and download an account backup.'); return false; }
}
async function request(url, opts = {}) {
  const res = await fetch(url, { credentials: 'same-origin', ...opts });
  const data = await res.json();
  if (!res.ok) { const err = new Error(data.error || 'Character sync failed.'); err.status = res.status; throw err; }
  return data;
}
export function getLocalCharacters() {
  const rows = stored(KEY, []); return Array.isArray(rows) ? rows : [];
}
export function exportCharacterBackup() {
  return { account: active?.id || null, characters: readAll(), conflicts: active ? stored(`${accountKey(active.id)}:conflicts`, []) : [] };
}
/** The account this client is signed in to (null = none). */
export function currentAccountId() { return active?.id || null; }
// Every client window names its account in its title (title bar / taskbar), so several
// clients on one PC can be told apart. The original client has no such line.
function showAccount(id) { try { if (globalThis.document) globalThis.document.title = id ? `Dekaron Online - ${id}` : 'Dekaron Online'; } catch { /* no DOM */ } }
export async function configureAccountSaves(id) {
  clearTimeout(retryTimer);
  if (pending) await pending;
  if (!id) { active = null; showAccount(null); notice('local', 'Saved on this browser.'); return; }
  id = String(id).toLowerCase();
  if (active?.id === id) return;
  const remote = await request('/api/characters');
  if (remote.account !== id || !Array.isArray(remote.characters)) throw new Error('Account changed. Log in again.');
  const previous = stored(accountKey(id), null);
  let recovered = false;
  if (previous?.dirty && previous.revision !== remote.revision) {
    // Retain every conflicting snapshot before accepting the server's newer version.
    const backupKey = `${accountKey(id)}:conflicts`;
    const backups = stored(backupKey, []);
    backups.push({ savedAt: Date.now(), ...previous });
    localStorage.setItem(backupKey, JSON.stringify(backups));
    recovered = true;
  }
  const useLocal = previous?.dirty && previous.revision === remote.revision && Array.isArray(previous.characters);
  active = { id, revision: remote.revision, dirty: !!useLocal, characters: useLocal ? previous.characters : remote.characters, generation: 0, blocked: false };
  showAccount(id);
  if (!cache(active)) throw new Error(status.message);
  notice(recovered ? 'recovered' : 'synced', recovered ? 'Another session saved newer characters. Your earlier changes are retained in the account backup on the website.' : 'Characters loaded from your account.');
  if (active.dirty) await flushCharacterSaves();
}
export async function importLocalCharacters() {
  if (!active) throw new Error('Log in before copying local characters.');
  const rows = readAll(), ids = new Set(rows.map(c => c.id)), before = rows.length; let imported = 0, skipped = 0;
  for (const ch of getLocalCharacters()) {
    if (ids.has(ch.id)) { skipped++; continue; }
    rows.push(ch); ids.add(ch.id); imported++;
  }
  // MIGRATION-4.1.x: an account carried over from 4.1.x with more than 18 characters keeps them; only growth past the cap is refused.
  if (imported && rows.length > Math.max(CHAR_TRADE_ENGINE_CHOSEN.receiverMaxCharacters, before)) throw new Error(`An account can hold at most ${CHAR_TRADE_ENGINE_CHOSEN.receiverMaxCharacters} characters.`);
  if (!writeAll(rows) || !await flushCharacterSaves()) throw new Error(status.message || 'Could not sync copied characters.');
  return { imported, skipped };
}
/** Server-created characters are the only records admitted to the shared world. */
export async function createAccountCharacter({ name, classIndex, nameColor, staffPrivileges = false, staffRole = undefined } = {}) {
  name=normalizeCharacterName(name);nameColor=normalizeCharacterNameColor(nameColor);
  if (!active) throw new Error('Log in before creating an online character.');
  if (!await flushCharacterSaves()) throw new Error(status.message);
  const body = { account: active.id, name, nameColor, classIndex };
  if (staffPrivileges === true) { body.staffPrivileges = true; if (staffRole != null) body.staffRole = staffRole; }
  const result = await request('/api/characters', { method: 'POST', headers: { 'Content-Type': 'application/json' }, body: JSON.stringify(body) });
  if (result.account !== active.id) throw new Error('Account changed. Log in again.');
  active.revision = result.revision; active.characters = result.characters; active.dirty = false;
  cache(active); notice('synced', 'Online character created by the server.');
  return result.character;
}
export function applyServerCharacter(profile) {
  if (!active || !profile || profile.authority !== 'server') return false;
  const i = active.characters.findIndex(c => c.id === profile.id && c.authority === 'server');
  if (i < 0) return false;
  active.characters[i] = profile;
  if (Date.now() - (active.lastOnlineCache || 0) < 5000) return true;
  active.lastOnlineCache = Date.now();
  return cache(active);
}
export async function flushCharacterSaves({ keepalive = false } = {}) {
  if (pending) { await pending; if (active?.dirty && !active.blocked) return flushCharacterSaves({ keepalive }); return !active?.dirty; }
  const ctx = active;
  if (!ctx || !ctx.dirty) return true;
  if (ctx.blocked) return false;
  clearTimeout(retryTimer);
  pending = (async () => {
    try {
      while (ctx === active && ctx.dirty) {
        const generation = ctx.generation;
        const payload = JSON.stringify({ account: ctx.id, revision: ctx.revision, characters: ctx.characters });
        notice('syncing', 'Saving characters to your account…');
        const result = await request('/api/characters', { method: 'PUT', headers: { 'Content-Type': 'application/json' }, body: payload, keepalive: keepalive && new TextEncoder().encode(payload).length < 60000 });
        if (result.account !== ctx.id) throw new Error('Account changed during sync.');
        ctx.revision = result.revision; ctx.dirty = generation !== ctx.generation;
        if (!cache(ctx)) return false;
      }
      notice('synced', 'Characters saved to your account.');
      return true;
    } catch (err) {
      ctx.blocked = err.status === 401 || err.status === 409;
      notice(ctx.blocked ? 'conflict' : 'offline', ctx.blocked ? `${err.message} A local backup is saved in this browser.` : 'Server sync unavailable. Progress is saved in this browser and will retry.');
      if (!ctx.blocked) retryTimer = setTimeout(() => { void flushCharacterSaves(); }, 15000);
      return false;
    } finally { pending = null; }
  })();
  return pending;
}

function readAll() {
  return active ? [...active.characters] : getLocalCharacters();
}
function writeAll(list) {
  if (active) {
    const previous = { characters: active.characters, dirty: active.dirty, generation: active.generation };
    active.characters = list; active.dirty = true; active.generation++;
    const ok = cache(active);
    if (!ok) { Object.assign(active, previous); return false; }
    clearTimeout(retryTimer);
    if (!active.blocked) retryTimer = setTimeout(() => { void flushCharacterSaves(); }, 250);
    return ok;
  }
  try { localStorage.setItem(KEY, JSON.stringify(list)); return true; } catch { return false; }
}

export function listCharacters() {
  return readAll().sort((a, b) => (b.lastPlayed || 0) - (a.lastPlayed || 0));
}

export function getCharacter(id) {
  return readAll().find(c => c.id === id) || null;
}

export function createCharacter({ name, classIndex, className, nameColor }) {
  const list = readAll();name=normalizeCharacterName(name);nameColor=normalizeCharacterNameColor(nameColor);
  if(list.some(c=>characterNameKey(c.name)===characterNameKey(name)))throw new Error('That character name is already taken.');
  const ch = {
    id: `c${Date.now().toString(36)}${Math.floor(Math.random() * 1e6).toString(36)}`,
    name, nameColor, classIndex, className,
    level: 1, exp: 0, dil: 0,
    hp: null, mp: null,               // null = full on first load
    statPoints: 0, skillPoints: 0,
    stats: null,                      // filled from class base stats on first load
    map: null, pos: null,             // null = class start point
    inventory: [], equipment: {}, hotbar: [], skills: {}, starterSkillPending: true,
    kills: 0, deaths: 0, playSeconds: 0,
    created: Date.now(), lastPlayed: Date.now(),
  };
  list.push(ch);
  if (!writeAll(list)) throw new Error('Character could not be saved. Browser storage may be full.');
  return ch;
}

export function saveCharacter(ch) {
  const list = readAll();
  const i = list.findIndex(c => c.id === ch.id);
  ch.lastPlayed = Date.now();
  if (i >= 0) list[i] = ch; else list.push(ch);
  if (active && ch.authority === 'server') {
    // Multiplayer persistence is written only by the world server, never a browser snapshot.
    active.characters = list;
    return cache(active);
  }
  return writeAll(list);
}

export function deleteCharacter(id) {
  if (getCharacter(id)?.authority === 'server') throw new Error('Online characters are managed by the server; browser deletion is disabled.');
  if (!writeAll(readAll().filter(c => c.id !== id))) throw new Error('Character deletion could not be saved.');
}
/** Character select > Delete. An ONLINE character is removed by the server (it re-checks the typed name and refuses while the account is
 *  in the world or the character is in a guild); a browser-only character is removed locally as before. */
export async function deleteAccountCharacter(id, typedName) {
  const ch = getCharacter(id);
  if (!ch) throw new Error('That character no longer exists.');
  if (ch.authority !== 'server') { deleteCharacter(id); return; }
  if (!active) throw new Error('Log in before deleting an online character.');
  if (!await flushCharacterSaves()) throw new Error(status.message || 'Characters could not be synced before the deletion.');
  const result = await request('/api/characters', { method: 'DELETE', headers: { 'Content-Type': 'application/json' }, body: JSON.stringify({ account: active.id, id, name: typedName }) });
  if (result.account !== active.id || !Array.isArray(result.characters)) throw new Error('Account changed. Log in again.');
  active.revision = result.revision; active.characters = result.characters; active.dirty = false;
  if (!cache(active)) throw new Error(status.message || 'The character list could not be saved in this browser.');
  notice('synced', 'Online character deleted by the server.');
}

/** Clear host-supplied pendingDeleteAt (Global client action 5 / btn_delete_cancel).
 *  Does not invent a delay; only strips pending fields when present.
 *  Browser chars: rewrite local list. Server chars: ask host DELETE with cancelPending:true
 *  (host clears fields only — no character removal). */
export async function cancelAccountCharacterPending(id) {
  const strip = (ch) => {
    if (!ch || typeof ch !== 'object') return ch;
    const next = { ...ch };
    delete next.pendingDeleteAt; delete next.deleteAt; delete next.pending_delete_at;
    return next;
  };
  const ch = getCharacter(id);
  if (!ch) throw new Error('That character no longer exists.');
  const at = ch.pendingDeleteAt ?? ch.deleteAt ?? ch.pending_delete_at;
  if (at == null || at === '' || at === 0 || at === false) return ch;
  if (ch.authority !== 'server') {
    const list = readAll().map(c => c.id === id ? strip(c) : c);
    if (!writeAll(list)) throw new Error('Pending deletion could not be cancelled locally.');
    return getCharacter(id);
  }
  if (!active) throw new Error('Log in before cancelling an online pending deletion.');
  if (!await flushCharacterSaves()) throw new Error(status.message || 'Characters could not be synced before cancel.');
  const result = await request('/api/characters', {
    method: 'DELETE',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify({ account: active.id, id, cancelPending: true }),
  });
  if (result.account !== active.id || !Array.isArray(result.characters)) throw new Error('Account changed. Log in again.');
  active.revision = result.revision; active.characters = result.characters; active.dirty = false;
  if (!cache(active)) throw new Error(status.message || 'The character list could not be saved in this browser.');
  notice('synced', 'Pending character deletion cancelled.');
  return getCharacter(id);
}

if (typeof globalThis.addEventListener === 'function') {
  globalThis.addEventListener('pagehide', () => { void flushCharacterSaves({ keepalive: true }); });
  globalThis.addEventListener('online', () => { void flushCharacterSaves(); });
}

const SETTINGS_KEY = 'dekaron-solo:settings:v1';
export function loadSettings() {
  try { return { musicVolume: 0.5, sfxVolume: 0.7, drawDistance: 1, shadows: true, ...JSON.parse(localStorage.getItem(SETTINGS_KEY) || '{}') }; }
  catch { return { musicVolume: 0.5, sfxVolume: 0.7, drawDistance: 1, shadows: true }; }
}
export function saveSettings(s) {
  try { localStorage.setItem(SETTINGS_KEY, JSON.stringify(s)); } catch { /* ignore */ }
}
