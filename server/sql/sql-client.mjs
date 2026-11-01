// Node side of the SQL host: spawns sql-host.ps1 once and speaks line-delimited base64 JSON over stdio.
// No npm packages, no network drivers: Windows PowerShell's built-in SqlClient talks to SQL Server with Windows auth.
import { spawn } from 'node:child_process';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const HOST_SCRIPT = fileURLToPath(new URL('./sql-host.ps1', import.meta.url));

export function assertSqlBridgePlatform(platform=process.platform){if(platform!=='win32')throw new Error('SQL Server storage requires the Windows PowerShell SqlClient bridge; use a Windows host for SQL Server, or local JSON/SQLite storage on Linux.');}

/** Parameter helpers for values that JSON cannot carry unambiguously. */
export const sqlHex = (hex) => ({ $hex: String(hex).toUpperCase() });
export const sqlBig = (n) => ({ $big: String(n) });
export const sqlDate = (d) => ({ $dt: (d instanceof Date ? d : new Date(d)).toISOString() });

export class SqlError extends Error {
  constructor(message, number = 0) { super(message); this.name = 'SqlError'; this.number = number; }
}

export function createSqlClient({ instance = process.env.DEKARON_SQL_INSTANCE || '.\\SQLEXPRESS', database = 'master', log = () => {} } = {}) {
  assertSqlBridgePlatform();
  let child = null, buffer = '', nextId = 1, starting = null, closed = false;
  const pending = new Map();

  function failAll(error) {
    for (const [, p] of pending) p.reject(error);
    pending.clear();
  }
  function onLine(line) {
    if (!line.trim()) return;
    let msg;
    try { msg = JSON.parse(Buffer.from(line.trim(), 'base64').toString('utf8')); }
    catch { log('[sql] unreadable reply line'); return; }
    if (msg.id === 0 && msg.ready) { pending.get('ready')?.resolve(msg); pending.delete('ready'); return; }
    const p = pending.get(msg.id);
    if (!p) return;
    pending.delete(msg.id);
    if (msg.ok) p.resolve(msg); else p.reject(new SqlError(msg.error || 'SQL error', msg.number || 0));
  }
  function start() {
    if (child) return starting;
    child = spawn('powershell.exe', ['-NoProfile', '-NonInteractive', '-ExecutionPolicy', 'Bypass', '-File', HOST_SCRIPT, '-Instance', instance],
      { stdio: ['pipe', 'pipe', 'pipe'], windowsHide: true });
    child.stdout.setEncoding('ascii');
    child.stdout.on('data', (chunk) => {
      buffer += chunk;
      let i;
      while ((i = buffer.indexOf('\n')) >= 0) { const line = buffer.slice(0, i); buffer = buffer.slice(i + 1); onLine(line); }
    });
    child.stderr.on('data', (d) => log(`[sql-host] ${String(d).trim()}`));
    child.on('exit', (code) => {
      const was = child; child = null; starting = null;
      if (!closed) log(`[sql-host] exited (${code})`);
      failAll(new SqlError(`SQL host stopped (${code}).`));
      void was;
    });
    starting = new Promise((resolve, reject) => {
      pending.set('ready', { resolve, reject });
      setTimeout(() => { if (pending.has('ready')) { pending.delete('ready'); reject(new SqlError('SQL host did not start within 30 s.')); } }, 30000).unref?.();
    });
    return starting;
  }
  async function call(op, payload = {}) {
    if (closed) throw new SqlError('SQL client is closed.');
    await start();
    const id = nextId++;
    const body = Buffer.from(JSON.stringify({ id, op, ...payload }), 'utf8').toString('base64');
    return new Promise((resolve, reject) => {
      pending.set(id, { resolve, reject });
      child.stdin.write(body + '\n', (err) => { if (err) { pending.delete(id); reject(new SqlError(String(err.message || err))); } });
    });
  }
  return {
    /** Run SQL and return the rows of the first result set (array of plain objects). Parameters are always bound, never spliced. */
    async query(sql, params = {}, { db = database, timeout = 60 } = {}) { return (await call('query', { db, sql, params, timeout })).sets[0] ?? []; },
    /** Run SQL and return every result set plus rows affected. */
    async run(sql, params = {}, { db = database, timeout = 60 } = {}) { const r = await call('query', { db, sql, params, timeout }); return { sets: r.sets, rowsAffected: r.rows }; },
    async ping() { return (await call('ping')).pong === true; },
    async close() {
      closed = true;
      if (!child) return;
      try { await Promise.race([call('bye'), new Promise((r) => setTimeout(r, 2000))]); } catch { /* host already gone */ }
      try { child.kill(); } catch { /* ignore */ }
      child = null;
    },
    instance, database,
  };
}
export const sqlHostPath = HOST_SCRIPT;
export const sqlHostDir = path.dirname(HOST_SCRIPT);
