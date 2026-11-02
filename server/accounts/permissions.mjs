// Private host-managed grants. Browser signup, characters and snapshots cannot write this file.
import fs from 'node:fs/promises';
import {isStaffBracketAccount} from './staff-brackets.mjs';
import path from 'node:path';
import { randomBytes } from 'node:crypto';
import {sqliteAccountIds} from './sqlite-store.mjs';
import {readDurableAccountStore} from './entity-journal.mjs';
export const ROLE_CAPABILITIES = Object.freeze({ player: Object.freeze([]), gm: Object.freeze(['gm:panel', 'gm:commands']) });
/** Admin, GM, and Dev are one max-staff privilege set (aliases of role `gm`). Not a fourth tier. */
export const STAFF_ROLE_ALIASES = Object.freeze({ admin: 'gm', gm: 'gm', dev: 'gm' });
export const STAFF_ROLE_LABEL = 'Admin / GM / Dev';
export function normalizeAccountRole(role) {
  const key = String(role ?? '').trim().toLowerCase();
  if (key === 'player') return 'player';
  if (Object.hasOwn(STAFF_ROLE_ALIASES, key)) return STAFF_ROLE_ALIASES[key];
  throw new Error('Role must be player or Admin/GM/Dev (stored as gm).');
}
export function isStaffRole(role) {
  try { return normalizeAccountRole(role) === 'gm'; } catch { return false; }
}
export function canonicalAccount(id) {
  const value = String(id || '').trim().toLowerCase();
  // Staff brackets include `gm` (2 chars); allow those exact ids.
  if (isStaffBracketAccount(value)) return value;
  if (!/^[a-z0-9_-]{3,32}$/.test(value) || value === '__proto__') throw new Error('Invalid account ID.');
  return value;
}
export function permissionFile(accountStore) { return process.env.DEKARON_PERMISSION_STORE || `${accountStore}.permissions.json`; }
async function read(file) {
  let value;
  try {
    if ((await fs.lstat(file)).isSymbolicLink()) throw new Error('Permission store cannot be a link.');
    value = JSON.parse(await fs.readFile(file, 'utf8'));
  } catch (error) { if (error.code === 'ENOENT') return { version: 1, accounts: {} }; throw error; }
  if (value?.version !== 1 || !value.accounts || typeof value.accounts !== 'object' || Array.isArray(value.accounts)) throw new Error('Invalid permission store.');
  for (const [id, entry] of Object.entries(value.accounts)) if (canonicalAccount(id) !== id || !entry || !Object.hasOwn(ROLE_CAPABILITIES, entry.role)) throw new Error('Invalid account permission grant.');
  return value;
}
// STABILITY-PING: every authenticated request (each move/cast) did lstat + readFile + JSON.parse of this file on the libuv
// thread pool. Grants change through setAccountRole (drops the cache at once) or a host tool editing the file (seen within 1 s).
const PERMISSION_CACHE = new Map(), PERMISSION_CACHE_MS = 1000;
function cachedRead(file) {
  const at = Date.now(), cacheKey = path.resolve(file); let hit = PERMISSION_CACHE.get(cacheKey);
  if (!hit || at - hit.at > PERMISSION_CACHE_MS) {
    hit = { at, value: read(file) }; PERMISSION_CACHE.set(cacheKey, hit);
    hit.value.catch(() => { if (PERMISSION_CACHE.get(cacheKey) === hit) PERMISSION_CACHE.delete(cacheKey); });
  }
  return hit.value;
}
export async function accountPermissions(file, id) {
  const grants = await cachedRead(file), key = canonicalAccount(id);
  const role = Object.hasOwn(grants.accounts, key) ? grants.accounts[key].role : 'player';
  return { role, capabilities: [...ROLE_CAPABILITIES[role]] };
}
// Serialize read/modify/write grants within the running host, including separate service instances.
const writes = new Map();
export async function setAccountRole(options) {
  const file = options.file ?? permissionFile(options.accountStore), key = path.resolve(file);
  const previous = writes.get(key) ?? Promise.resolve();
  const pending = previous.catch(() => {}).then(() => writeAccountRole({ ...options, file }));
  writes.set(key, pending);
  try { return await pending; }
  finally { if (writes.get(key) === pending) writes.delete(key); }
}
async function writeAccountRole({ accountStore, file, account, role: requestedRole }) {
  const id = canonicalAccount(account);
  const role = normalizeAccountRole(requestedRole);
  if (!Object.hasOwn(ROLE_CAPABILITIES, role)) throw new Error('Role must be player or Admin/GM/Dev (gm).');
  if (process.env.DEKARON_ACCOUNT_SQLITE) {
    if (!sqliteAccountIds(process.env.DEKARON_ACCOUNT_SQLITE).includes(id)) throw new Error('That registered account does not exist. No permission was changed.');
  } else {
    const db = (await readDurableAccountStore(accountStore)).state;   // checkpoint + save journal (an account may exist only in the journal yet)
    if (!db.users || !Object.hasOwn(db.users, id)) throw new Error('That registered account does not exist. No permission was changed.');
  }
  const grants = await read(file);
  if (role === 'player') delete grants.accounts[id]; else grants.accounts[id] = { role };
  await fs.mkdir(path.dirname(file), { recursive: true });
  const stat = await fs.lstat(file).catch(error => { if (error.code === 'ENOENT') return null; throw error; });
  if (stat && (!stat.isFile() || stat.isSymbolicLink() || stat.nlink > 1)) throw new Error('Permission store must be an ordinary unlinked file.');
  const temporary = `${file}.${randomBytes(6).toString('hex')}.tmp`;
  try { await fs.writeFile(temporary, JSON.stringify(grants, null, 2), { mode: 0o600, flag: 'wx' }); await fs.rename(temporary, file); PERMISSION_CACHE.delete(path.resolve(file)); }
  finally { await fs.rm(temporary, { force: true }).catch(() => {}); }
  return { id, role, capabilities: [...ROLE_CAPABILITIES[role]] };
}
