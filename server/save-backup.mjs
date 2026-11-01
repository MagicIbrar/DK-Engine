// Save backup + rotation for the engine's persisted state (lane L17). Node >= 22.5 for SQLite (node:sqlite backup()).
// Consistency:
//  * atomic JSON stores (accounts/atomic-store.mjs, permissions, settings, rates, items ...) are only ever replaced by
//    write-tmp + rename, so one open() sees exactly one complete generation; the snapshot is read through that single fd
//    and must JSON.parse. *.tmp siblings (in-flight writers) are never copied.
//  * SQLite (accounts/sqlite-store.mjs, WAL) is copied with the SQLite online backup API (node:sqlite backup), never a
//    raw file copy; the copy must pass PRAGMA integrity_check.
// A backup set is written to <dest>/.<stamp>.partial and renamed to <dest>/<stamp> only after every file verified,
// with manifest.json (sha256/size/kind/source/verification). Rotation keeps `keepLast` newest + newest per day for
// `keepDaily` days + newest per ISO week for `keepWeeks` weeks; partial/corrupt sets are never counted as kept.
import fs from 'node:fs/promises'; import fss from 'node:fs'; import path from 'node:path'; import { createHash } from 'node:crypto';
import { readDurableAccountStore } from './accounts/entity-journal.mjs';

const sha = b => createHash('sha256').update(b).digest('hex');
async function sqlite() { return import('node:sqlite'); }
export const DEFAULT_POLICY = Object.freeze({ keepLast: 10, keepDaily: 7, keepWeeks: 4 });

/** Default sources next to the account store: the store itself + its sibling JSON stores + optional SQLite file. */
export async function discoverSources({ accountStore, sqliteFile = null, extra = [] }) {
  const out = [], dir = path.dirname(accountStore), base = path.basename(accountStore);
  for (const n of (await fs.readdir(dir).catch(() => [])).sort()) {
    if (n.endsWith('.tmp') || !(n === base || (n.startsWith(base + '.') && n.endsWith('.json')))) continue;
    out.push({ kind: 'json', file: path.join(dir, n) });
  }
  if (sqliteFile && fss.existsSync(sqliteFile)) out.push({ kind: 'sqlite', file: sqliteFile });
  for (const e of extra) out.push(e);
  return out;
}

async function snapshotJson(src, dst) {
  let buf;
  // an account store with a save journal (accounts/entity-journal.mjs, 4.1.0): the file is only the last checkpoint, so the
  // backup holds the durable state (checkpoint + journal, what a restart recovers) as one self-contained JSON file
  if (fss.existsSync(`${src}.journal`)) buf = Buffer.from(JSON.stringify((await readDurableAccountStore(src)).state));
  else { const h = await fs.open(src, 'r'); try { buf = await h.readFile(); } finally { await h.close(); } }
  JSON.parse(buf.toString('utf8')); // a torn/partial file is a hard error, never a "backup"
  await fs.writeFile(dst, buf, { flag: 'wx', mode: 0o600 }); return buf;
}
async function snapshotSqlite(src, dst) {
  const { DatabaseSync, backup } = await sqlite();
  const db = new DatabaseSync(src, { readOnly: true });
  try { await backup(db, dst); } finally { db.close(); }
  verifySqliteFile(dst, DatabaseSync); return fs.readFile(dst);
}
function verifySqliteFile(file, DatabaseSync) {
  const db = new DatabaseSync(file, { readOnly: true });
  try { const r = db.prepare('PRAGMA integrity_check').all(); if (r.length !== 1 || Object.values(r[0])[0] !== 'ok') throw new Error(`integrity_check failed: ${JSON.stringify(r).slice(0, 200)}`);
    return db.prepare("SELECT name FROM sqlite_master WHERE type='table' ORDER BY name").all().map(x => x.name); } finally { db.close(); }
}
const stampOf = (d) => d.toISOString().replace(/[:.]/g, '-');

export async function createBackup({ sources, dest, now = new Date() }) {
  await fs.mkdir(dest, { recursive: true, mode: 0o700 });
  const stamp = stampOf(now), tmp = path.join(dest, `.${stamp}.partial`), final = path.join(dest, stamp);
  await fs.rm(tmp, { recursive: true, force: true }); await fs.mkdir(tmp, { mode: 0o700 });
  const files = [];
  try {
    for (const [i, s] of sources.entries()) {
      const name = `${String(i).padStart(2, '0')}-${path.basename(s.file)}`, dst = path.join(tmp, name);
      const buf = s.kind === 'sqlite' ? await snapshotSqlite(s.file, dst) : await snapshotJson(s.file, dst);
      files.push({ name, kind: s.kind, source: path.resolve(s.file), size: buf.length, sha256: sha(buf) });
    }
    await fs.writeFile(path.join(tmp, 'manifest.json'), JSON.stringify({ version: 1, createdAt: now.toISOString(), files }, null, 1), { flag: 'wx', mode: 0o600 });
    await fs.rename(tmp, final);
  } catch (e) { await fs.rm(tmp, { recursive: true, force: true }); throw e; }
  return { set: final, stamp, files };
}

export async function verifyBackup(set) {
  const m = JSON.parse(await fs.readFile(path.join(set, 'manifest.json'), 'utf8')); const problems = [];
  for (const f of m.files) {
    const p = path.join(set, f.name); let b; try { b = await fs.readFile(p); } catch { problems.push(`${f.name}: missing`); continue; }
    if (b.length !== f.size || sha(b) !== f.sha256) { problems.push(`${f.name}: checksum mismatch`); continue; }
    try { if (f.kind === 'json') JSON.parse(b.toString('utf8')); else verifySqliteFile(p, (await sqlite()).DatabaseSync); } catch (e) { problems.push(`${f.name}: ${e.message}`); }
  }
  return { ok: problems.length === 0, problems, manifest: m };
}

export async function listSets(dest) {
  const out = [];
  for (const n of (await fs.readdir(dest).catch(() => [])).sort()) {
    if (n.startsWith('.')) continue; const set = path.join(dest, n);
    try { const m = JSON.parse(await fs.readFile(path.join(set, 'manifest.json'), 'utf8')); out.push({ set, name: n, createdAt: new Date(m.createdAt) }); } catch { out.push({ set, name: n, createdAt: null }); }
  }
  return out.sort((a, b) => (b.createdAt?.getTime() ?? 0) - (a.createdAt?.getTime() ?? 0));
}
const isoWeek = (d) => { const t = new Date(Date.UTC(d.getUTCFullYear(), d.getUTCMonth(), d.getUTCDate())); const day = t.getUTCDay() || 7; t.setUTCDate(t.getUTCDate() + 4 - day); const y = t.getUTCFullYear(); return `${y}-W${Math.ceil(((t - Date.UTC(y, 0, 1)) / 864e5 + 1) / 7)}`; };
/** Decide which sets to keep (pure). Unverifiable sets (no manifest) are never kept and never count. */
export function planRotation(sets, policy = DEFAULT_POLICY, now = new Date()) {
  const good = sets.filter(s => s.createdAt), keep = new Set();
  good.slice(0, policy.keepLast).forEach(s => keep.add(s.set));
  const days = new Set(), weeks = new Set();
  for (const s of good) { const age = (now - s.createdAt) / 864e5; const d = s.createdAt.toISOString().slice(0, 10), w = isoWeek(s.createdAt);
    if (age < policy.keepDaily && !days.has(d)) { days.add(d); keep.add(s.set); }
    if (age < policy.keepWeeks * 7 && !weeks.has(w)) { weeks.add(w); keep.add(s.set); } }
  return { keep: sets.filter(s => keep.has(s.set)).map(s => s.set), remove: sets.filter(s => !keep.has(s.set)).map(s => s.set) };
}
export async function rotate(dest, policy = DEFAULT_POLICY, now = new Date()) {
  const plan = planRotation(await listSets(dest), policy, now);
  for (const s of plan.remove) { if (path.dirname(path.resolve(s)) !== path.resolve(dest)) throw new Error('rotation escaped backup dir'); await fs.rm(s, { recursive: true, force: true }); }
  for (const n of await fs.readdir(dest)) if (/^\..*\.partial$/.test(n)) await fs.rm(path.join(dest, n), { recursive: true, force: true }); // crashed runs
  return plan;
}
/** Run once: backup, verify, rotate. Rotation only runs after the new set verified. */
export async function runBackupJob({ sources, dest, policy = DEFAULT_POLICY, now = new Date() }) {
  const b = await createBackup({ sources, dest, now }); const v = await verifyBackup(b.set);
  if (!v.ok) throw new Error(`new backup failed verification: ${v.problems.join('; ')}`);
  const r = await rotate(dest, policy, now); return { ...b, verified: true, rotation: r };
}
/**
 * Restore a verified set into `target` (a directory). Each file is written as tmp + rename so the result is atomic per
 * file. Refuses to overwrite existing files unless overwrite=true. Stop the server first (see docs/SAVE-BACKUP.md).
 * Files are restored under their original basenames.
 */
export async function restoreBackup({ set, target, overwrite = false }) {
  const v = await verifyBackup(set); if (!v.ok) throw new Error(`refusing to restore an unverified set: ${v.problems.join('; ')}`);
  await fs.mkdir(target, { recursive: true }); const restored = [];
  for (const f of v.manifest.files) {
    const out = path.join(target, path.basename(f.source));
    if (!overwrite && fss.existsSync(out)) throw new Error(`target exists: ${out}`);
    const tmp = `${out}.restore-${Date.now()}.tmp`; await fs.copyFile(path.join(set, f.name), tmp); await fs.rename(tmp, out);
    if (f.kind === 'sqlite') for (const s of ['-wal', '-shm']) await fs.rm(out + s, { force: true }); // stale WAL must not replay over the restore
    if (f.kind === 'json') await fs.rm(`${out}.journal`, { force: true }); // nor a stale account save journal (the set is self-contained)
    restored.push(out);
  }
  return restored;
}
