// L17 migration runner for the SQLite store (and checksum listing for the mssql scripts, which are review-only).
// Applies sql/fixes/<dialect>/NNNN_*.sql in order, each in its own transaction, recording sha256 in schema_migration.
// Refuses to run if an already-applied script changed on disk. Intended for COPIES / throwaway databases.
import fs from 'node:fs'; import path from 'node:path'; import { createHash } from 'node:crypto';
const ROOT = new URL('../../sql/fixes/', import.meta.url);
export function listMigrations(dialect) {
  const dir = new URL(dialect + '/', ROOT);
  return fs.readdirSync(dir).filter(f => /^\d{4}_.+\.sql$/.test(f)).sort().map(f => {
    const text = fs.readFileSync(new URL(f, dir), 'utf8');
    return { id: Number(f.slice(0, 4)), name: f, text, sha256: createHash('sha256').update(text).digest('hex') };
  });
}
export function applySqlite(db, { log = () => {} } = {}) {
  const all = listMigrations('sqlite');
  db.exec(all[0].text); // 0001 creates the tracking table (idempotent)
  const done = new Map(db.prepare('SELECT id, sha256 FROM schema_migration').all().map(r => [r.id, r.sha256]));
  const applied = [];
  for (const m of all) {
    if (done.has(m.id)) { if (done.get(m.id) !== m.sha256) throw new Error(`migration ${m.name} changed after it was applied`); continue; }
    db.exec('BEGIN');
    try { db.exec(m.text); db.prepare('INSERT INTO schema_migration(id,name,sha256) VALUES (?,?,?)').run(m.id, m.name, m.sha256); db.exec('COMMIT'); }
    catch (e) { db.exec('ROLLBACK'); throw e; }
    applied.push(m.name); log(`applied ${m.name}`);
  }
  return applied;
}
