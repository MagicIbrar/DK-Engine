// Private host-managed grants. Browser signup, characters and snapshots cannot write this file.
import fs from 'node:fs/promises';
import path from 'node:path';
import { randomBytes } from 'node:crypto';
import {sqliteAccountIds} from './sqlite-store.mjs';
import {readDurableAccountStore} from './entity-journal.mjs';
export const ROLE_CAPABILITIES = Object.freeze({ player: Object.freeze([]), gm: Object.freeze(['gm:panel', 'gm:commands']) });
export function canonicalAccount(id) {
  const value = String(id || '').trim().toLowerCase();
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
export async function accountPermissions(file, id) {
  const grants = await read(file), key = canonicalAccount(id);
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
async function writeAccountRole({ accountStore, file, account, role }) {
  const id = canonicalAccount(account);
  if (!Object.hasOwn(ROLE_CAPABILITIES, role)) throw new Error('Role must be player or gm.');
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
  try { await fs.writeFile(temporary, JSON.stringify(grants, null, 2), { mode: 0o600, flag: 'wx' }); await fs.rename(temporary, file); }
  finally { await fs.rm(temporary, { force: true }).catch(() => {}); }
  return { id, role, capabilities: [...ROLE_CAPABILITIES[role]] };
}
