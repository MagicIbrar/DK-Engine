// Private launcher service only. Wire behind its installation-owner + private-token boundary.
// No browser/world command, client role, or delegated GM permission authorizes this service.
import fs from 'node:fs/promises';
import { accountPermissions, canonicalAccount, permissionFile, setAccountRole } from './permissions.mjs';
import {sqliteAccountIds} from './sqlite-store.mjs';
import {readDurableAccountStore} from './entity-journal.mjs';

export function ownerAccountForHost(config) {
  if (config == null) return 'admin';
  if (typeof config.account !== 'string') throw new Error('Friends host owner account is missing.');
  return canonicalAccount(config.account);
}

export function createOwnerGMGrants({ accountStore, file = permissionFile(accountStore), revokeLease, ownerAccount = 'admin', registeredAccounts = null }) {
  if (typeof revokeLease !== 'function') throw new Error('Owner GM management requires a live world lease revocation hook.');
  const protectedAccounts = new Set(['admin', canonicalAccount(ownerAccount)]);
  let pending = Promise.resolve();
  return {
    async list() {
      const ids = registeredAccounts ? await registeredAccounts() : process.env.DEKARON_ACCOUNT_SQLITE ? sqliteAccountIds(process.env.DEKARON_ACCOUNT_SQLITE) : Object.keys((await readDurableAccountStore(accountStore)).state.users || {}).sort();
      return Promise.all(ids.filter(id => !protectedAccounts.has(id)).map(async id => {
        if (canonicalAccount(id) !== id) throw new Error('Invalid registered account.');
        const access = await accountPermissions(file, id);
        return { id, role: access.role };
      }));
    },
    set(input) {
      const work = async () => {
        if (!input || typeof input !== 'object' || Array.isArray(input) || Object.keys(input).some(key => !['account', 'role'].includes(key))) throw new Error('Expected registered account and player or gm role.');
        const account = canonicalAccount(input.account);
        if (typeof input.account !== 'string' || typeof input.role !== 'string') throw new Error('Expected registered account and player or gm role.');
        if (protectedAccounts.has(account)) throw new Error('The installation owner cannot be changed by delegated GM management.');
        if (registeredAccounts && !(await registeredAccounts()).includes(account)) throw new Error('That registered account does not exist. No permission was changed.');
        const result = await setAccountRole({ accountStore, file, account, role: input.role });
        // Durable permission change comes first. The next authenticated request already sees it.
        await revokeLease(result.id);
        return result;
      };
      const next = pending.catch(() => {}).then(work);
      pending = next;
      return next;
    },
  };
}
