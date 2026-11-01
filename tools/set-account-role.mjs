// Explicit local administrator tool. No HTTP route calls this grant operation.
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { setAccountRole } from '../server/accounts/permissions.mjs';
const args = process.argv.slice(2), arg = name => { const at = args.indexOf(name); return at >= 0 ? args[at + 1] : undefined; };
try {
  if (!arg('--account') || !arg('--role')) throw new Error('Usage: node tools/set-account-role.mjs --account ID --role gm|player [--store account-file] [--permissions permission-file]');
  const accountStore = path.resolve(arg('--store') || process.env.DEKARON_ACCOUNT_STORE || fileURLToPath(new URL('../server/accounts/data.json', import.meta.url)));
  const result = await setAccountRole({ accountStore, ...(arg('--permissions') ? { file: path.resolve(arg('--permissions')) } : {}), account: arg('--account'), role: arg('--role') });
  console.log(`Account ${result.id}: role ${result.role}; capabilities ${result.capabilities.join(', ') || '(none)'}.`);
} catch (error) { console.error(error.message); process.exitCode = 1; }
