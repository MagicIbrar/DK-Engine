// CLI: node tools/save-backup.mjs run|verify|list|restore ...  (node >= 22.5)
//   run     --dest DIR [--store data.json] [--sqlite file] [--keep-last N --keep-daily D --keep-weeks W]
//   verify  --set DIR          list --dest DIR          restore --set DIR --to DIR [--overwrite]
import path from 'node:path'; import { fileURLToPath } from 'node:url';
import { discoverSources, runBackupJob, verifyBackup, listSets, restoreBackup, DEFAULT_POLICY } from '../server/save-backup.mjs';
const HERE = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const a = process.argv.slice(2), cmd = a[0], arg = (k, d = null) => { const i = a.indexOf(k); return i >= 0 ? a[i + 1] : d; };
const store = path.resolve(arg('--store', process.env.DEKARON_ACCOUNT_STORE || path.join(HERE, 'server/accounts/data.json')));
const sq = arg('--sqlite', process.env.DEKARON_ACCOUNT_SQLITE || null);
try {
  if (cmd === 'run') { const policy = { keepLast: +arg('--keep-last', DEFAULT_POLICY.keepLast), keepDaily: +arg('--keep-daily', DEFAULT_POLICY.keepDaily), keepWeeks: +arg('--keep-weeks', DEFAULT_POLICY.keepWeeks) };
    const r = await runBackupJob({ sources: await discoverSources({ accountStore: store, sqliteFile: sq }), dest: path.resolve(arg('--dest')), policy });
    console.log(JSON.stringify({ set: r.set, files: r.files.length, removed: r.rotation.remove.length })); }
  else if (cmd === 'verify') { const v = await verifyBackup(path.resolve(arg('--set'))); console.log(JSON.stringify({ ok: v.ok, problems: v.problems })); process.exitCode = v.ok ? 0 : 1; }
  else if (cmd === 'list') for (const s of await listSets(path.resolve(arg('--dest')))) console.log(s.name, s.createdAt?.toISOString() ?? 'NO-MANIFEST');
  else if (cmd === 'restore') console.log((await restoreBackup({ set: path.resolve(arg('--set')), target: path.resolve(arg('--to')), overwrite: a.includes('--overwrite') })).join('\n'));
  else { console.error('usage: run|verify|list|restore (see header)'); process.exitCode = 2; }
} catch (e) { console.error(`save-backup: ${e.message}`); process.exitCode = 1; }
