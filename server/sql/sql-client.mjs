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

// F1 (4.3.2): `pool` hosts behind the same interface. Default 1 = the previous single pipe (same FIFO dispatch). close() now
// really sends 'bye' before killing (it used to mark itself closed first, so the 'bye' call always threw and was skipped). With pool > 1 (DEKARON_SQL_POOL, 1..8) each call goes to the host with the fewest calls in flight
// (ties: lowest index); `{pin:n}` forces host n for session-scoped state such as sp_getapplock. Every host uses the same
// connection string built inside sql-host.ps1 (Integrated Security; no credentials pass through Node).
// Ordering: with pool 1 calls run FIFO. With pool > 1 two concurrent calls may finish in either order; the engine store's
// writes stay ordered because its pump is single-flight (one batch in flight at a time).
export function sqlPoolSize(value = process.env.DEKARON_SQL_POOL) { const n = Number(value ?? 1); return Number.isInteger(n) && n >= 1 && n <= 8 ? n : 1; }
const spawnPowerShell = (instance) => spawn('powershell.exe', ['-NoProfile', '-NonInteractive', '-ExecutionPolicy', 'Bypass', '-File', HOST_SCRIPT, '-Instance', instance],
  { stdio: ['pipe', 'pipe', 'pipe'], windowsHide: true });

function createSqlHost({ instance, log, spawnHost, label, readyTimeoutMs }) {
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
    child = spawnHost(instance);
    child.stdout.setEncoding('ascii');
    child.stdout.on('data', (chunk) => {
      buffer += chunk;
      let i;
      while ((i = buffer.indexOf('\n')) >= 0) { const line = buffer.slice(0, i); buffer = buffer.slice(i + 1); onLine(line); }
    });
    child.stderr.on('data', (d) => log(`[sql-host${label}] ${String(d).trim()}`));
    child.on('exit', (code) => {
      const was = child; child = null; starting = null; buffer = '';
      if (!closed) log(`[sql-host${label}] exited (${code})`);
      failAll(new SqlError(`SQL host stopped (${code}).`));
      void was;
    });
    starting = new Promise((resolve, reject) => {
      pending.set('ready', { resolve, reject });
      setTimeout(() => { if (pending.has('ready')) { pending.delete('ready'); reject(new SqlError(`SQL host did not start within ${Math.round(readyTimeoutMs / 1000)} s.`)); } }, readyTimeoutMs).unref?.();
    });
    return starting;
  }
  let flights = 0; // counted synchronously so a burst of calls spreads over the pool before any host replies
  function call(op, payload = {}) { flights++; return send(op, payload).finally(() => { flights--; }); }
  async function send(op, payload) {
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
    call,
    inFlight: () => flights,
    async close() {
      if (closed) return; const c = child;
      if (c) { try { await Promise.race([call('bye'), new Promise((r) => setTimeout(r, 2000))]); } catch { /* host already gone */ } }
      closed = true;
      try { c?.kill(); } catch { /* ignore */ }
      child = null;
    },
  };
}

export function createSqlClient({ instance = process.env.DEKARON_SQL_INSTANCE || '.\\SQLEXPRESS', database = 'master', log = () => {}, pool = sqlPoolSize(), spawnHost = null, readyTimeoutMs = 30000 } = {}) {
  if (!spawnHost) assertSqlBridgePlatform();
  const size = sqlPoolSize(pool);
  const hosts = Array.from({ length: size }, (_, i) => createSqlHost({ instance, log, spawnHost: spawnHost || spawnPowerShell, label: size > 1 ? `#${i}` : '', readyTimeoutMs }));
  let closed = false;
  const pick = (pin) => {
    if (pin != null) { if (!Number.isInteger(pin) || pin < 0 || pin >= size) throw new SqlError(`SQL pool has no host ${pin}.`); return hosts[pin]; }
    let best = hosts[0];
    for (let i = 1; i < size; i++) if (hosts[i].inFlight() < best.inFlight()) best = hosts[i];
    return best;
  };
  const call = (op, payload, pin) => { if (closed) return Promise.reject(new SqlError('SQL client is closed.')); return pick(pin).call(op, payload); };
  return {
    /** Run SQL and return the rows of the first result set (array of plain objects). Parameters are always bound, never spliced. */
    async query(sql, params = {}, { db = database, timeout = 60, pin } = {}) { return (await call('query', { db, sql, params, timeout }, pin)).sets[0] ?? []; },
    /** Run SQL and return every result set plus rows affected. */
    async run(sql, params = {}, { db = database, timeout = 60, pin } = {}) { const r = await call('query', { db, sql, params, timeout }, pin); return { sets: r.sets, rowsAffected: r.rows }; },
    async ping({ pin } = {}) { return (await call('ping', {}, pin)).pong === true; },
    async close() {
      if (closed) return;
      await Promise.all(hosts.map((h) => h.close()));
      closed = true;
    },
    instance, database, poolSize: size,
  };
}
export const sqlHostPath = HOST_SCRIPT;
export const sqlHostDir = path.dirname(HOST_SCRIPT);
