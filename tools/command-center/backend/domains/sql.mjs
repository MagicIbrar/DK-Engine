// Integrated SQL command center: profiles, explorer, live monitor, query workspace, backup / verify / restore rehearsal,
// migration preview. Production instances are read-only: only vetted catalog/monitor SELECTs built here run there.
// User-authored SQL runs only as a database user WITHOUT LOGIN (EXECUTE AS ... WITH NO REVERT), enforced by SQL Server.
import path from 'node:path';
import {createHash, randomBytes} from 'node:crypto';
import {pathToFileURL} from 'node:url';
import {PROFILE, ENGINE, INSTALL, TEST_DB_PREFIX} from '../core/paths.mjs';
import {define, v, SQL_INSTANCE, DB_NAME} from '../core/rpc.mjs';
import {readJson, writeJson, UserError, clip} from '../core/util.mjs';
import {native, protect} from '../core/native.mjs';
import {startJob} from '../core/jobs.mjs';
import {event} from '../core/events.mjs';
import {settings} from './settings.mjs';
import {isProduction, TEST_PREFIX, ensurePrincipals, ensureReader, normInstance, storageConfig} from './storage.mjs';

const PROFILES = path.join(PROFILE, 'sql-profiles.json'), HISTORY = path.join(PROFILE, 'query-history.json'), BACKUP_LOG = path.join(PROFILE, 'backups.json');
const DEFAULT_PROFILES = [
  {id: 'main-readonly', name: 'Installed game (Main) - read only', server: '.\\DEKARONBETA', defaultDatabase: 'DEKARON_DEDICATED', auth: 'windows', encrypt: false, verifyCertificate: false},
  {id: 'preview-test', name: 'Preview test instance (SQLEXPRESS)', server: '.\\SQLEXPRESS', defaultDatabase: 'DKPREVIEW_TEST_WORLD', auth: 'windows', encrypt: false, verifyCertificate: false},
];
const qi = name => '[' + String(name).replace(/]/g, ']]') + ']';

async function profiles() {
  const saved = await readJson(PROFILES, null);
  let list;
  if (INSTALL) {
    // Installed: the first connection is always this world's own SQL Server (from Storage); custom ones follow.
    const cfg = await storageConfig();
    list = [{id: 'world', name: `This world's SQL Server (${cfg.instance})`, server: cfg.instance, defaultDatabase: 'DEKARON_DEDICATED', auth: 'windows', encrypt: false, verifyCertificate: false, builtIn: true}, ...(Array.isArray(saved) ? saved.filter(p => p.id !== 'world') : [])];
  } else { list = Array.isArray(saved) && saved.length ? saved : DEFAULT_PROFILES; if (!saved) await writeJson(PROFILES, list); }
  return list.map(p => ({...p, production: isProduction(p.server), hasSecret: !!p.secret}));
}
async function profile(id) { const p = (await profiles()).find(x => x.id === id); if (!p) throw new UserError('Choose a saved SQL connection profile.', 404); return p; }
function connection(p, database) { return {server: p.server, database: database || p.defaultDatabase || 'master', auth: p.auth, user: p.user, secret: p.secret, profile: p.id, encrypt: !!p.encrypt, verifyCertificate: !!p.verifyCertificate, connectTimeout: 8}; }
function rowsOf(set) { return set ? set.rows.map(r => Object.fromEntries(set.columns.map((c, i) => [c.name, r[i]]))) : []; }
async function vetted(p, sql, {database, params = {}, timeout = 15, maxRows = 2000, maxChars = 4000, app = 'DK Command Center'} = {}) {
  const r = await native('sql.query', {...connection(p, database), mode: 'catalog', sql, params, timeout, maxRows, maxChars, app}, (timeout + 25) * 1000);
  return {sets: r.sets || [], rows: rowsOf(r.sets?.[0]), r};
}
const testDatabase = (p, db) => !p.production && TEST_PREFIX.test(db || '');

// ---- schema knowledge (from server/sql/engine-schema.mjs and engine-sql-store.mjs)
const KNOWN = {
  engine_account: {role: 'authoritative', note: 'Accounts (salt/digest, revision). Written by the engine write-behind mirror; the in-memory/JSON working copy hydrates from it.'},
  engine_character: {role: 'authoritative', note: 'profile_json is the complete authoritative character record. Other columns are indexed copies of it.'},
  engine_character_extra: {role: 'derived', note: 'Projection of profile_json (inventory, storage, equipment). Rebuilt on every account write; never edit it.'},
  engine_cash: {role: 'derived', note: 'Projection of profile_json (DKC, VIP points, cash inventory). Rebuilt on every account write; never edit it.'},
  engine_social: {role: 'authoritative', note: 'Single row of guild/social state (JSON).'},
  engine_meta: {role: 'metadata', note: 'Schema metadata (schema_version).'},
  engine_sync_log: {role: 'log', note: 'Engine sync log.'},
};
const LEGACY = new Set(['account', 'CHARACTER', 'cash', 'dkrmanagedb', 'dkrstoredb', 'RANKINGDB']);
function classifyDb(name) {
  if (/^DEKARON_DEDICATED(_HOSTED)?$/i.test(name)) return {kind: 'engine-world', label: 'DK Engine world database'};
  if (TEST_PREFIX.test(name)) return {kind: 'preview-test', label: INSTALL ? 'Test database (disposable)' : 'Preview test database (disposable)'};
  if (/^DEKARON_ENGINE/i.test(name)) return {kind: 'engine-legacy', label: 'Earlier engine database (not a supported world target)'};
  if (LEGACY.has(name) || /^FARIUS_/i.test(name)) return {kind: 'original-server', label: 'Original-server schema (not used by DK Engine worlds)'};
  if (['master', 'model', 'msdb', 'tempdb'].includes(name)) return {kind: 'system', label: 'SQL Server system database'};
  return {kind: 'other', label: 'Other database'};
}

// ---- explorer
async function databases(p) {
  const {rows} = await vetted(p, `SELECT d.name, d.database_id AS id, d.state_desc AS state, d.is_read_only AS readOnly, d.recovery_model_desc AS recovery, CONVERT(varchar(19), d.create_date, 126) AS created,
    CAST(SUM(CASE WHEN f.type = 0 THEN f.size ELSE 0 END) * 8.0 / 1024 AS decimal(18,1)) AS dataMB, CAST(SUM(CASE WHEN f.type = 1 THEN f.size ELSE 0 END) * 8.0 / 1024 AS decimal(18,1)) AS logMB,
    HAS_DBACCESS(d.name) AS access FROM sys.databases d LEFT JOIN sys.master_files f ON f.database_id = d.database_id GROUP BY d.name, d.database_id, d.state_desc, d.is_read_only, d.recovery_model_desc, d.create_date ORDER BY d.database_id`, {database: 'master'});
  return rows.map(r => ({...r, dataMB: Number(r.dataMB), logMB: Number(r.logMB), ...classifyDb(r.name)}));
}
async function objects(p, database, {search = ''} = {}) {
  const {rows} = await vetted(p, `SET LOCK_TIMEOUT 3000; SELECT s.name AS [schema], o.name, o.type_desc AS type, o.object_id AS id, CONVERT(varchar(19), o.modify_date, 126) AS modified,
      (SELECT SUM(pt.rows) FROM sys.partitions pt WHERE pt.object_id = o.object_id AND pt.index_id IN (0,1)) AS approxRows,
      (SELECT CAST(SUM(a.total_pages) * 8.0 / 1024 AS decimal(18,2)) FROM sys.partitions pt JOIN sys.allocation_units a ON a.container_id = pt.partition_id WHERE pt.object_id = o.object_id) AS sizeMB
    FROM sys.objects o JOIN sys.schemas s ON s.schema_id = o.schema_id WHERE o.type IN ('U','V') AND o.is_ms_shipped = 0 AND (@q = '' OR o.name LIKE '%' + @q + '%' OR s.name LIKE '%' + @q + '%') ORDER BY s.name, o.name`, {database, params: {q: search}});
  const reader = await principals(p, database);
  return {database, ...classifyDb(database), principals: reader, objects: rows.map(r => ({...r, approxRows: r.approxRows === null ? null : Number(r.approxRows), sizeMB: r.sizeMB === null ? null : Number(r.sizeMB), ...(KNOWN[r.name] && r.schema === 'dbo' && /^(DEKARON_DEDICATED|DKPREVIEW_)/i.test(database) ? KNOWN[r.name] : {role: 'unclassified'})}))};
}
async function resolveObject(p, database, schema, name) {
  const {rows} = await vetted(p, `SELECT o.object_id AS id, s.name AS [schema], o.name, o.type FROM sys.objects o JOIN sys.schemas s ON s.schema_id = o.schema_id WHERE s.name = @s AND o.name = @n AND o.type IN ('U','V')`, {database, params: {s: schema, n: name}});
  if (!rows.length) throw new UserError(`${schema}.${name} is not available in ${database}.`, 404, {code: 'unavailable'});
  return rows[0];
}
async function describe(p, database, schema, name) {
  const o = await resolveObject(p, database, schema, name);
  const [cols, idx, fks] = await Promise.all([
    vetted(p, `SELECT c.column_id AS ord, c.name, t.name AS type, c.max_length AS maxLength, c.precision, c.scale, c.is_nullable AS nullable, c.is_identity AS [identity], c.is_computed AS computed,
      OBJECT_DEFINITION(c.default_object_id) AS [default], CASE WHEN EXISTS (SELECT 1 FROM sys.index_columns ic JOIN sys.indexes i ON i.object_id = ic.object_id AND i.index_id = ic.index_id WHERE i.is_primary_key = 1 AND ic.object_id = c.object_id AND ic.column_id = c.column_id) THEN 1 ELSE 0 END AS pk
      FROM sys.columns c JOIN sys.types t ON t.user_type_id = c.user_type_id WHERE c.object_id = @id ORDER BY c.column_id`, {database, params: {id: o.id}}),
    vetted(p, `SELECT i.name, i.type_desc AS type, i.is_unique AS [unique], i.is_primary_key AS pk, i.has_filter AS filtered, i.filter_definition AS [filter],
      STUFF((SELECT ', ' + c.name + CASE WHEN ic.is_descending_key = 1 THEN ' DESC' ELSE '' END FROM sys.index_columns ic JOIN sys.columns c ON c.object_id = ic.object_id AND c.column_id = ic.column_id WHERE ic.object_id = i.object_id AND ic.index_id = i.index_id AND ic.is_included_column = 0 ORDER BY ic.key_ordinal FOR XML PATH('')), 1, 2, '') AS columns
      FROM sys.indexes i WHERE i.object_id = @id AND i.type > 0 ORDER BY i.index_id`, {database, params: {id: o.id}}),
    vetted(p, `SELECT fk.name, OBJECT_SCHEMA_NAME(fk.parent_object_id) + '.' + OBJECT_NAME(fk.parent_object_id) AS [from], COL_NAME(fkc.parent_object_id, fkc.parent_column_id) AS fromColumn,
      OBJECT_SCHEMA_NAME(fk.referenced_object_id) + '.' + OBJECT_NAME(fk.referenced_object_id) AS [to], COL_NAME(fkc.referenced_object_id, fkc.referenced_column_id) AS toColumn
      FROM sys.foreign_keys fk JOIN sys.foreign_key_columns fkc ON fkc.constraint_object_id = fk.object_id WHERE fk.parent_object_id = @id OR fk.referenced_object_id = @id`, {database, params: {id: o.id}}),
  ]);
  return {object: o, known: KNOWN[o.name] && o.schema === 'dbo' ? KNOWN[o.name] : null, columns: cols.rows, indexes: idx.rows, foreignKeys: fks.rows};
}
async function rows(p, database, schema, name, {offset = 0, limit = 50, filterColumn, filter = '', orderBy, desc = false} = {}) {
  const info = await describe(p, database, schema, name);
  const names = new Set(info.columns.map(c => c.name));
  if (filterColumn && !names.has(filterColumn)) throw new UserError('Unknown filter column.');
  if (orderBy && !names.has(orderBy)) throw new UserError('Unknown sort column.');
  const pk = info.columns.filter(c => c.pk).map(c => c.name);
  const order = orderBy ? qi(orderBy) + (desc ? ' DESC' : '') : (pk.length ? pk.map(qi).join(', ') : '(SELECT NULL)');
  const where = filterColumn && filter ? `WHERE CAST(${qi(filterColumn)} AS nvarchar(4000)) LIKE '%' + @f + '%'` : '';
  const lim = Math.max(1, Math.min(200, limit));
  const r = await vetted(p, `SET LOCK_TIMEOUT 3000; SET TRANSACTION ISOLATION LEVEL READ COMMITTED; SELECT * FROM ${qi(schema)}.${qi(name)} ${where} ORDER BY ${order} OFFSET @o ROWS FETCH NEXT @n ROWS ONLY`, {database, params: {o: Math.max(0, offset), n: lim + 1, f: filter}, maxRows: lim + 1, maxChars: 600, timeout: 15});
  const set = r.sets[0] || {columns: [], rows: []}; const more = set.rows.length > lim;
  return {columns: set.columns, rows: set.rows.slice(0, lim), offset, limit: lim, more, elapsedMs: r.r.elapsedMs, cellsTruncated: r.r.cellsTruncated, known: info.known, readNote: 'READ COMMITTED with a 3 s lock timeout; cells longer than 600 characters are shortened.'};
}
async function principals(p, database) {
  try { const {rows} = await vetted(p, "SELECT DATABASE_PRINCIPAL_ID('dkpreview_reader') AS reader, DATABASE_PRINCIPAL_ID('dkpreview_writer') AS writer", {database}); return {reader: rows[0]?.reader ? 'dkpreview_reader' : null, writer: rows[0]?.writer && testDatabase(p, database) ? 'dkpreview_writer' : null}; }
  catch { return {reader: null, writer: null}; }
}

// ---- live monitor (bounded, last-good retained, backoff on failure)
const monitorState = new Map();
async function monitor(p, database) {
  const key = p.id + '|' + database, st = monitorState.get(key) || {failures: 0, lastGood: null, lastGoodAt: null, lastTry: 0, prevCounters: null, overheadMs: []};
  monitorState.set(key, st);
  const interval = (await settings()).sqlMonitorSeconds * 1000, wait = interval * Math.min(8, 2 ** st.failures) - 1000;
  if (st.lastGood && Date.now() - st.lastTry < Math.max(1000, st.failures ? wait : 1500)) return {...st.lastGood, cached: true, stale: Date.now() - st.lastGoodAt > interval * 2.5, failures: st.failures, lastGoodAt: st.lastGoodAt, backoffSeconds: st.failures ? Math.round(wait / 1000) : 0};
  st.lastTry = Date.now(); const t0 = performance.now(), limitations = [];
  try {
    const base = await vetted(p, `SELECT CAST(SERVERPROPERTY('ProductVersion') AS nvarchar(64)) AS version, CAST(SERVERPROPERTY('Edition') AS nvarchar(128)) AS edition, CONVERT(varchar(19), sqlserver_start_time, 126) AS started,
      HAS_PERMS_BY_NAME(NULL, NULL, 'VIEW SERVER STATE') AS viewServerState, IS_SRVROLEMEMBER('sysadmin') AS sysadmin, DB_ID(@db) AS dbid FROM sys.dm_os_sys_info`, {database: 'master', params: {db: database}, timeout: 10}).catch(async e => { if (/VIEW SERVER STATE|permission/i.test(e.message)) { limitations.push('VIEW SERVER STATE is not granted: server-wide sessions, waits and query statistics are unavailable.'); return vetted(p, "SELECT CAST(SERVERPROPERTY('ProductVersion') AS nvarchar(64)) AS version, CAST(SERVERPROPERTY('Edition') AS nvarchar(128)) AS edition, NULL AS started, 0 AS viewServerState, 0 AS sysadmin, DB_ID(@db) AS dbid", {database: 'master', params: {db: database}}); } throw e; });
    const b = base.rows[0]; const out = {at: Date.now(), profile: p.id, database, connectMs: base.r.connectMs, roundTripMs: base.r.elapsedMs, server: {version: b.version, edition: b.edition, started: b.started}, permissions: {viewServerState: !!b.viewServerState}, limitations, databaseExists: !!b.dbid};
    if (b.viewServerState) {
      const live = await vetted(p, `SET LOCK_TIMEOUT 2000;
        SELECT COUNT(*) AS sessions, SUM(CASE WHEN s.status = 'running' THEN 1 ELSE 0 END) AS running, SUM(CASE WHEN s.database_id = DB_ID(@db) THEN 1 ELSE 0 END) AS dbSessions FROM sys.dm_exec_sessions s WHERE s.is_user_process = 1;
        SELECT TOP 25 r.session_id AS session, r.status, r.command, DB_NAME(r.database_id) AS db, r.wait_type AS wait, r.wait_time AS waitMs, r.blocking_session_id AS blockedBy, r.total_elapsed_time AS elapsedMs, r.cpu_time AS cpuMs, r.logical_reads AS reads, r.percent_complete AS pct,
          s.program_name AS program, LEFT(REPLACE(REPLACE(SUBSTRING(t.text, r.statement_start_offset/2 + 1, CASE WHEN r.statement_end_offset = -1 THEN 400 ELSE (r.statement_end_offset - r.statement_start_offset)/2 + 1 END), CHAR(10), ' '), CHAR(13), ' '), 400) AS statement
          FROM sys.dm_exec_requests r JOIN sys.dm_exec_sessions s ON s.session_id = r.session_id OUTER APPLY sys.dm_exec_sql_text(r.sql_handle) t WHERE s.is_user_process = 1 AND r.session_id <> @@SPID ORDER BY r.total_elapsed_time DESC;
        SELECT RTRIM(counter_name) AS name, cntr_value AS value, cntr_type AS type FROM sys.dm_os_performance_counters WHERE (object_name LIKE '%SQL Statistics%' AND counter_name IN ('Batch Requests/sec', 'SQL Compilations/sec')) OR (object_name LIKE '%General Statistics%' AND counter_name IN ('User Connections')) OR (object_name LIKE '%Buffer Manager%' AND counter_name = 'Page life expectancy') OR (object_name LIKE '%Locks%' AND instance_name = '_Total' AND counter_name IN ('Lock Waits/sec', 'Number of Deadlocks/sec', 'Lock Timeouts/sec'));
        SELECT TOP 10 qs.execution_count AS executions, CAST(qs.total_elapsed_time / 1000.0 / qs.execution_count AS decimal(18,1)) AS avgMs, CAST(qs.max_elapsed_time / 1000.0 AS decimal(18,1)) AS maxMs, CONVERT(varchar(19), qs.last_execution_time, 126) AS last,
          LEFT(REPLACE(REPLACE(SUBSTRING(t.text, qs.statement_start_offset/2 + 1, CASE WHEN qs.statement_end_offset = -1 THEN 300 ELSE (qs.statement_end_offset - qs.statement_start_offset)/2 + 1 END), CHAR(10), ' '), CHAR(13), ' '), 300) AS statement
          FROM sys.dm_exec_query_stats qs CROSS APPLY sys.dm_exec_sql_text(qs.sql_handle) t WHERE t.dbid = DB_ID(@db) ORDER BY qs.max_elapsed_time DESC`, {database: 'master', params: {db: database}, timeout: 10, maxRows: 50, maxChars: 400});
      const [sess, req, counters, slow] = live.sets.map(rowsOf);
      out.sessions = sess[0] || null;
      out.requests = req.map(r => ({...r, statement: normalizeSql(r.statement)}));
      out.blocking = req.filter(r => r.blockedBy > 0).map(r => ({session: r.session, blockedBy: r.blockedBy, waitMs: r.waitMs, wait: r.wait}));
      const c = Object.fromEntries(counters.map(x => [x.name, Number(x.value)])), now = Date.now();
      const rate = n => st.prevCounters && c[n] !== undefined && st.prevCounters.c[n] !== undefined ? Math.max(0, Math.round((c[n] - st.prevCounters.c[n]) / ((now - st.prevCounters.at) / 1000) * 10) / 10) : null;
      out.counters = {batchRequestsPerSec: rate('Batch Requests/sec'), compilationsPerSec: rate('SQL Compilations/sec'), lockWaitsPerSec: rate('Lock Waits/sec'), lockTimeoutsPerSec: rate('Lock Timeouts/sec'), deadlocksPerSec: rate('Number of Deadlocks/sec'), userConnections: c['User Connections'] ?? null, pageLifeExpectancyS: c['Page life expectancy'] ?? null, note: st.prevCounters ? 'Rates are averaged since the previous sample.' : 'Rates appear after the second sample.'};
      st.prevCounters = {c, at: now};
      out.slowQueries = slow.map(r => ({...r, avgMs: Number(r.avgMs), maxMs: Number(r.maxMs), statement: normalizeSql(r.statement)}));
    }
    if (b.dbid) {
      try {
        const dbq = await vetted(p, `SET LOCK_TIMEOUT 2000; SELECT name, type_desc AS type, CAST(size * 8.0 / 1024 AS decimal(18,1)) AS sizeMB, CAST(FILEPROPERTY(name, 'SpaceUsed') * 8.0 / 1024 AS decimal(18,1)) AS usedMB FROM sys.database_files;
          SELECT CASE WHEN OBJECT_ID('dbo.engine_account') IS NOT NULL THEN APPLOCK_TEST('public', N'DekaronDedicatedWorld', 'Exclusive', 'Session') END AS worldLockFree`, {database, timeout: 10});
        out.files = rowsOf(dbq.sets[0]).map(f => ({...f, sizeMB: Number(f.sizeMB), usedMB: f.usedMB === null ? null : Number(f.usedMB)}));
        const lock = rowsOf(dbq.sets[1])[0]?.worldLockFree; out.worldLock = lock === null || lock === undefined ? 'not an engine world' : (Number(lock) === 1 ? 'free (no world owns this database)' : 'held (a running world owns this database)');
      } catch (e) { limitations.push('Database details unavailable: ' + clip(e.message, 160)); }
    }
    out.overheadMs = Math.round(performance.now() - t0); st.overheadMs.push(out.overheadMs); if (st.overheadMs.length > 60) st.overheadMs.shift();
    out.overheadAvgMs = Math.round(st.overheadMs.reduce((a, x) => a + x, 0) / st.overheadMs.length);
    st.failures = 0; st.lastGood = out; st.lastGoodAt = Date.now();
    return {...out, stale: false, failures: 0, lastGoodAt: st.lastGoodAt};
  } catch (e) {
    st.failures = Math.min(st.failures + 1, 6);
    event('warn', 'sql', `Monitor refresh failed for ${p.name}: ${clip(e.message, 160)}`);
    if (st.lastGood) return {...st.lastGood, stale: true, failures: st.failures, error: clip(e.message, 300), lastGoodAt: st.lastGoodAt, backoffSeconds: Math.round(interval * Math.min(8, 2 ** st.failures) / 1000)};
    throw new UserError('SQL monitor unavailable: ' + clip(e.message, 300), 503);
  }
}

// ---- query workspace
export function normalizeSql(s) { return String(s ?? '').replace(/'(?:[^']|'')*'/g, "'?'").replace(/\b0x[0-9a-f]+\b/gi, '0x?').replace(/(?<![\w@#$])-?\d+(?:\.\d+)?\b/g, '?').replace(/\s+/g, ' ').trim(); }
const pendingPlans = new Map();
async function addHistory(entry) {
  const keep = (await settings()).keepQueryText; const list = await readJson(HISTORY, []);
  list.push({...entry, sql: keep ? clip(entry.sql, 20000) : clip(normalizeSql(entry.sql), 4000), normalized: !keep});
  await writeJson(HISTORY, list.slice(-200));
}
function planSummary(xmlSets) {
  const xml = xmlSets.flatMap(s => s.rows.map(r => String(r[0] ?? ''))).join('\n');
  const statements = [...xml.matchAll(/<StmtSimple[^>]*StatementText="([^"]*)"[^>]*StatementType="([^"]+)"[^>]*?(?:StatementEstRows="([^"]+)")?/g)].map(m => ({type: m[2], text: clip(m[1].replace(/&#x[0-9A-F]+;|&\w+;/g, ' '), 200), estimatedRows: m[3] ? Math.round(Number(m[3])) : null}));
  const objects = [...new Set([...xml.matchAll(/<Object Database="\[([^\]]+)\]" Schema="\[([^\]]+)\]" Table="\[([^\]]+)\]"/g)].map(m => `${m[1]}.${m[2]}.${m[3]}`))];
  const destructive = statements.filter(s => /DELETE|UPDATE|TRUNCATE|DROP|ALTER|MERGE/i.test(s.type));
  return {statements, objects, destructive: destructive.length > 0};
}
async function runQuery({profileId, database, sql, mode = 'read', planToken, requestId}) {
  const p = await profile(profileId), s = await settings(), started = Date.now();
  const pr = await principals(p, database);
  const base = {...connection(p, database), sql, timeout: s.queryTimeoutSeconds, maxRows: s.queryRowLimit, maxChars: 4000, request: requestId, app: 'DK Command Center Preview (query)'};
  let r;
  try {
    if (mode === 'read') {
      if (!pr.reader) throw new UserError(p.production || !testDatabase(p, database) ? (INSTALL ? 'This database has no read-only query user yet. Add it from the Query tab (it can only read), or use the explorer.' : 'Arbitrary queries are disabled here: this database has no read-only principal. The preview never creates one in a non-test database. Use the explorer, or restore a backup into a disposable DKPREVIEW_ database.') : 'Prepare the read-only principal for this test database first.', 409, {code: 'no-reader'});
      r = await native('sql.query', {...base, mode: 'readonly', reader: pr.reader}, (s.queryTimeoutSeconds + 30) * 1000);
    } else {
      if (!testDatabase(p, database)) throw new UserError(`Write mode is available only for ${TEST_DB_PREFIX} test databases${INSTALL ? ' (restore a backup into one to experiment)' : ' on a non-production instance'}.`, 403);
      if (!pr.writer) throw new UserError('Prepare the test writer principal first.', 409, {code: 'no-writer'});
      if (!planToken) {
        let summary;
        try { const plan = await native('sql.query', {...base, mode: 'plan', writer: pr.writer, maxChars: 200000}, (s.queryTimeoutSeconds + 30) * 1000); summary = planSummary(plan.sets || []); }
        catch (e) {
          // SQL Server cannot estimate a batch that uses objects created earlier in the same batch. Show a statement
          // summary instead, clearly marked, so the review step still happens.
          const bare = String(sql).replace(/'(?:[^']|'')*'/g, "''").replace(/--[^\n]*|\/\*[\s\S]*?\*\//g, ' ');
          const statements = [...bare.matchAll(/\b(SELECT|INSERT|UPDATE|DELETE|MERGE|TRUNCATE|CREATE|ALTER|DROP|EXEC(?:UTE)?)\b[^;]*/gi)].map(m => ({type: m[1].toUpperCase(), text: clip(m[0].replace(/\s+/g, ' ').trim(), 200), estimatedRows: null}));
          summary = {statements, objects: [], destructive: /\b(DELETE|UPDATE|TRUNCATE|DROP|ALTER|MERGE)\b/i.test(bare), planUnavailable: clip(e.message, 300)};
        }
        const token = randomBytes(12).toString('hex');
        pendingPlans.set(token, {hash: createHash('sha256').update(profileId + '\0' + database + '\0' + sql).digest('hex'), at: Date.now()});
        return {needsConfirmation: true, planToken: token, plan: summary, principal: pr.writer};
      }
      const pend = pendingPlans.get(planToken); pendingPlans.delete(planToken);
      if (!pend || Date.now() - pend.at > 10 * 60000 || pend.hash !== createHash('sha256').update(profileId + '\0' + database + '\0' + sql).digest('hex')) throw new UserError('Review the plan again: the statement or connection changed after review.', 409, {code: 'plan-mismatch'});
      r = await native('sql.query', {...base, mode: 'write', writer: pr.writer}, (s.queryTimeoutSeconds + 30) * 1000);
      event('warn', 'sql', `Write-mode statement executed on test database ${database} as ${pr.writer}.`);
    }
    await addHistory({at: started, profile: p.id, database, mode, sql, elapsedMs: r.elapsedMs, rows: r.rowCount, outcome: 'ok'});
    return {sets: r.sets, rowCount: r.rowCount, rowsAffected: r.rowsAffected, truncated: r.truncated, cellsTruncated: r.cellsTruncated, elapsedMs: r.elapsedMs, connectMs: r.connectMs, messages: r.messages, principal: r.principal, limits: {rows: s.queryRowLimit, timeoutSeconds: s.queryTimeoutSeconds}};
  } catch (e) {
    const outcome = e.cancelled ? 'cancelled' : (/timeout/i.test(e.message) ? 'timeout' : 'error');
    if (!(e instanceof UserError) || e.code !== 'no-reader') await addHistory({at: started, profile: p.id, database, mode, sql, elapsedMs: Date.now() - started, rows: 0, outcome, error: clip(e.message, 300)}).catch(() => {});
    if (e instanceof UserError) throw e;
    throw new UserError((outcome === 'cancelled' ? 'Query cancelled.' : outcome === 'timeout' ? `Query timed out after ${s.queryTimeoutSeconds} s.` : 'SQL error: ') + (outcome === 'error' ? clip(e.message, 500) : ''), outcome === 'error' ? 400 : 409, {code: outcome}); // never 408: browsers silently re-send a POST answered with 408
  }
}

// ---- backup / verify / restore rehearsal
async function backupLog(entry) { const list = await readJson(BACKUP_LOG, []); if (entry) { list.push(entry); await writeJson(BACKUP_LOG, list.slice(-100)); } return list; }
async function defaults(p) { const {rows} = await vetted(p, "SELECT CAST(SERVERPROPERTY('InstanceDefaultBackupPath') AS nvarchar(400)) AS [backup], CAST(SERVERPROPERTY('InstanceDefaultDataPath') AS nvarchar(400)) AS [data], CAST(SERVERPROPERTY('InstanceDefaultLogPath') AS nvarchar(400)) AS [log]", {database: 'master'}); return rows[0]; }
async function watchPercent(p, command, ctx, done) {
  while (!done.value) {
    await new Promise(r => setTimeout(r, 700));
    try { const {rows} = await vetted(p, 'SELECT TOP 1 percent_complete AS pct FROM sys.dm_exec_requests WHERE command LIKE @c ORDER BY start_time DESC', {database: 'master', params: {c: command + '%'}, timeout: 5}); if (rows[0]) ctx.progress(Math.round(Number(rows[0].pct)), 100, '% (reported by SQL Server)'); } catch {}
  }
}
function backupJob({profileId, database, confirmProduction}) {
  return startJob({kind: 'sql.backup', key: 'sql.backup:' + profileId + ':' + database, area: 'sql', title: `Back up ${database}`, run: async ctx => {
    const p = await profile(profileId);
    if (p.production && !confirmProduction) throw new UserError('Backing up a production database writes a COPY_ONLY backup file and one msdb history row. Confirm to continue.', 409, {code: 'confirm-production'});
    ctx.phase('Prepare', 'Reading the instance default backup folder');
    const d = await defaults(p); if (!d?.backup) throw new Error('The instance has no default backup folder.');
    const file = d.backup.replace(/[\\/]$/, '') + '\\' + `${database}_DKCC_${new Date().toISOString().replace(/[-:T.]/g, '').slice(0, 14)}.bak`;
    ctx.phase('Back up', `COPY_ONLY backup with CHECKSUM to the instance default folder`); ctx.uncancellable();
    const done = {value: false}; const w = watchPercent(p, 'BACKUP', ctx, done);
    let r; try { r = await native('sql.query', {...connection(p, 'master'), mode: 'catalog', sql: 'BACKUP DATABASE @db TO DISK = @file WITH COPY_ONLY, CHECKSUM, INIT, FORMAT, NAME = @name, STATS = 10', params: {db: database, file, name: `DK Command Center${INSTALL ? '' : ' preview'} copy of ${database}`}, timeout: 1800}, 1900 * 1000); } finally { done.value = true; await w; }
    ctx.phase('Verify', 'RESTORE VERIFYONLY with CHECKSUM');
    const verify = await native('sql.query', {...connection(p, 'master'), mode: 'catalog', sql: 'RESTORE VERIFYONLY FROM DISK = @file WITH CHECKSUM', params: {file}, timeout: 1800}, 1900 * 1000);
    const head = await vetted(p, 'RESTORE HEADERONLY FROM DISK = @file', {database: 'master', params: {file}, timeout: 120});
    const h = head.rows[0] || {};
    const entry = {at: Date.now(), profile: p.id, server: p.server, database, file, sizeBytes: Number(h.BackupSize) || null, verified: true, copyOnly: true, checksum: true, backupFinish: h.BackupFinishDate || null, messages: [...(r.messages || []), ...(verify.messages || [])].slice(-6), elapsedMs: r.elapsedMs, verifyMs: verify.elapsedMs};
    await backupLog(entry); event('ok', 'sql', `Backup verified: ${database} (${Math.round((entry.sizeBytes || 0) / 1048576)} MB).`);
    return entry;
  }});
}
function restoreJob({profileId, file, sourceDatabase}) {
  return startJob({kind: 'sql.restore', key: 'sql.restore:' + file, area: 'sql', title: 'Restore rehearsal', run: async ctx => {
    const p = await profile(profileId);
    if (p.production) throw new UserError('Restore rehearsals run only on a test instance. Copy the backup to the test instance\'s backup folder first.', 403);
    const target = TEST_DB_PREFIX + 'RESTORE_' + new Date().toISOString().replace(/[-:T.]/g, '').slice(0, 14);
    ctx.phase('Read backup', 'RESTORE FILELISTONLY');
    const list = await vetted(p, 'RESTORE FILELISTONLY FROM DISK = @file', {database: 'master', params: {file}, timeout: 120});
    const d = await defaults(p); const dataFile = list.rows.find(f => f.Type === 'D'), logFile = list.rows.find(f => f.Type === 'L');
    if (!dataFile || !logFile) throw new Error('The backup does not contain one data and one log file.');
    ctx.phase('Restore', `Restoring into a new disposable database ${target}`); ctx.uncancellable();
    const done = {value: false}; const w = watchPercent(p, 'RESTORE', ctx, done);
    try { await native('sql.query', {...connection(p, 'master'), mode: 'catalog', sql: 'RESTORE DATABASE @target FROM DISK = @file WITH MOVE @ld TO @lp, MOVE @gd TO @gp, CHECKSUM, STATS = 10', params: {target, file, ld: dataFile.LogicalName, lp: d.data.replace(/[\\/]$/, '') + '\\' + target + '.mdf', gd: logFile.LogicalName, gp: (d.log || d.data).replace(/[\\/]$/, '') + '\\' + target + '_log.ldf'}, timeout: 1800}, 1900 * 1000); }
    finally { done.value = true; await w; }
    ctx.phase('Compare', 'Comparing table row counts and schema version with the source');
    const counts = async db => (await vetted(p, "SELECT o.name, SUM(pt.rows) AS n FROM sys.objects o JOIN sys.partitions pt ON pt.object_id = o.object_id AND pt.index_id IN (0,1) WHERE o.type = 'U' GROUP BY o.name ORDER BY o.name", {database: db})).rows;
    const restored = await counts(target);
    let source = null; try { if (sourceDatabase && !(await profiles()).find(x => x.id === profileId).production) source = await counts(sourceDatabase); } catch {}
    const diff = source ? restored.map(r => ({table: r.name, restored: Number(r.n), source: Number(source.find(s => s.name === r.name)?.n ?? NaN)})).filter(x => x.restored !== x.source) : null;
    const meta = await vetted(p, "IF OBJECT_ID('dbo.engine_meta') IS NOT NULL SELECT v FROM dbo.engine_meta WHERE k = 'schema_version' ELSE SELECT NULL AS v", {database: target}).catch(() => ({rows: []}));
    const entry = {at: Date.now(), kind: 'restore-rehearsal', profile: p.id, file, target, tables: restored.length, rows: restored.reduce((a, r) => a + Number(r.n), 0), schemaVersion: meta.rows[0]?.v ?? null, matchesSource: diff ? diff.length === 0 : null, differences: diff?.slice(0, 20) || null};
    await backupLog(entry); event('ok', 'sql', `Restore rehearsal into ${target}: ${entry.tables} tables, ${entry.rows} rows${diff ? (diff.length ? `, ${diff.length} differ` : ', matches source') : ''}.`);
    return entry;
  }});
}
async function dropDisposable({profileId, database, confirm}) {
  const p = await profile(profileId);
  if (p.production || !new RegExp('^' + TEST_DB_PREFIX + 'RESTORE_\\d{14}$').test(database)) throw new UserError(`Only disposable ${TEST_DB_PREFIX}RESTORE_ rehearsal databases can be dropped here.`, 403);
  if (confirm !== database) throw new UserError('Type the database name exactly to confirm.', 400, {field: 'confirm'});
  await native('sql.query', {...connection(p, 'master'), mode: 'catalog', sql: "DECLARE @s nvarchar(400) = N'ALTER DATABASE ' + QUOTENAME(@db) + N' SET SINGLE_USER WITH ROLLBACK IMMEDIATE; DROP DATABASE ' + QUOTENAME(@db) + N';'; IF @db LIKE N'" + TEST_DB_PREFIX.replace(/_/g, '[_]') + "RESTORE[_]%' EXEC (@s); SELECT DB_ID(@db) AS still", params: {db: database}, timeout: 60}, 90000);
  event('warn', 'sql', `Disposable database ${database} dropped.`); return {dropped: database};
}

// ---- migration preview
async function migrationPreview({profileId, database}) {
  const p = await profile(profileId);
  const {SCHEMA_VERSION, SCHEMA_STATEMENTS} = await import(pathToFileURL(path.join(ENGINE, 'server', 'sql', 'engine-schema.mjs')).href);
  const expectedTables = [...new Set(SCHEMA_STATEMENTS.map(s => /OBJECT_ID\('dbo\.(\w+)'\) IS NULL CREATE TABLE/.exec(s)?.[1]).filter(Boolean))];
  const expectedIndexes = [...new Set(SCHEMA_STATEMENTS.map(s => /name='(\w+)'/.exec(s)?.[1]).filter(Boolean))];
  const t = await vetted(p, "SELECT name FROM sys.tables; SELECT name FROM sys.indexes WHERE name LIKE 'IX[_]engine%'; IF OBJECT_ID('dbo.engine_meta') IS NOT NULL SELECT v FROM dbo.engine_meta WHERE k='schema_version' ELSE SELECT NULL AS v", {database});
  const tables = new Set(rowsOf(t.sets[0]).map(r => r.name)), indexes = new Set(rowsOf(t.sets[1]).map(r => r.name)), current = rowsOf(t.sets[2])[0]?.v ?? null;
  const missingTables = expectedTables.filter(x => !tables.has(x)), missingIndexes = expectedIndexes.filter(x => !indexes.has(x));
  const backups = (await backupLog()).filter(b => b.database === database && b.verified && Date.now() - b.at < 24 * 3600000);
  const rehearsal = (await backupLog()).filter(b => b.kind === 'restore-rehearsal' && backups.some(x => x.file === b.file));
  const {world} = await import('./world.mjs');
  const prerequisites = [
    {name: 'World stopped', ok: world.status === 'stopped', detail: world.status === 'stopped' ? 'No world is running.' : 'Stop the world first.'},
    {name: 'Verified backup within 24 h', ok: backups.length > 0, detail: backups.length ? backups.at(-1).file : 'Run Back up (verifies with CHECKSUM).'},
    {name: 'Restore rehearsal from that backup', ok: rehearsal.length > 0, detail: rehearsal.length ? rehearsal.at(-1).target : 'Run a restore rehearsal into a disposable database.'},
    INSTALL ? {name: 'Engine world or test database', ok: /^DEKARON_DEDICATED(_HOSTED)?$/i.test(database) || testDatabase(p, database), detail: 'Schema changes apply only to this engine\'s world databases or ' + TEST_DB_PREFIX + ' test databases.'} : {name: 'Disposable test database', ok: testDatabase(p, database), detail: testDatabase(p, database) ? 'DKPREVIEW_ database on a test instance.' : 'Production or non-test database: the preview only previews, never applies.'},
  ];
  const needed = current === String(SCHEMA_VERSION) && !missingTables.length && !missingIndexes.length ? [] : [...missingTables.map(x => `CREATE TABLE dbo.${x}`), ...missingIndexes.map(x => `CREATE INDEX ${x}`), ...(current !== String(SCHEMA_VERSION) ? [`Backfill projections (engine_character_extra, engine_cash) for missing rows only`, `Set engine_meta.schema_version = ${SCHEMA_VERSION}`] : [])];
  return {database, currentVersion: current, targetVersion: SCHEMA_VERSION, upToDate: !needed.length, steps: needed, prerequisites, canApply: needed.length > 0 && prerequisites.every(x => x.ok),
    rollback: 'Restore the verified pre-migration backup into the original database name while the world is stopped (the rehearsal proves that backup restores). The engine schema statements are additive: they create missing objects and never drop or overwrite rows.',
    production: p.production, note: p.production ? 'Production databases are never migrated by the preview. In the integrated launcher the existing guarded "Set up SQL world" applies these additive statements after a backup.' : null};
}

// ---- RPC
const profileInput = v.object({id: v.optional(v.string({max: 40, pattern: /^[a-z0-9-]{3,40}$/})), name: v.string({min: 1, max: 80}), server: v.string({min: 1, max: 200, pattern: SQL_INSTANCE}), defaultDatabase: v.optional(v.string({max: 128, pattern: DB_NAME})), auth: v.enum(['windows', 'sql']), user: v.optional(v.string({max: 128})), password: v.optional(v.secret({max: 256})), encrypt: v.optional(v.bool()), verifyCertificate: v.optional(v.bool())});
define('sql.profiles', {input: v.object({}), run: async () => ({profiles: (await profiles()).map(({secret, ...p}) => p), production: [...new Set((await profiles()).filter(p => p.production).map(p => normInstance(p.server)))]})});
define('sql.profile.save', {input: profileInput, run: async input => {
  if (INSTALL && input.id === 'world') throw new UserError('This world\'s connection follows SQL & Storage; change the SQL instance there.', 400);
  const list = await profiles(); const id = input.id || (input.name.toLowerCase().replace(/[^a-z0-9]+/g, '-').replace(/^-|-$/g, '').slice(0, 30) || 'profile') + '-' + randomBytes(2).toString('hex');
  const old = list.find(p => p.id === id); const next = {id, name: input.name, server: input.server, defaultDatabase: input.defaultDatabase || 'master', auth: input.auth, encrypt: !!input.encrypt, verifyCertificate: !!input.verifyCertificate};
  if (input.auth === 'sql') { next.user = input.user; if (input.password) next.secret = await protect('dkcc-sql:' + id, input.password); else if (old?.secret && old.user === input.user) next.secret = old.secret; else throw new UserError('Enter the SQL login password (stored with Windows DPAPI for your user only).', 400, {field: 'password'}); }
  const clean = list.filter(p => p.id !== id && !p.builtIn).map(({production, hasSecret, builtIn, ...p}) => p); clean.push(next); await writeJson(PROFILES, clean);
  event('info', 'sql', `SQL profile saved: ${next.name}${next.secret ? ' (password protected with DPAPI)' : ''}.`); return {id};
}});
define('sql.profile.delete', {input: v.object({id: v.string({max: 40})}), run: async ({id}) => { if (INSTALL && id === 'world') throw new UserError('This world\'s connection cannot be deleted.', 400); const list = (await profiles()).filter(p => p.id !== id && !p.builtIn).map(({production, hasSecret, builtIn, ...p}) => p); await writeJson(PROFILES, list); return {deleted: id}; }});
define('sql.test', {input: v.object({profileId: v.string({max: 40}), database: v.optional(v.string({max: 128, pattern: DB_NAME}))}), timeoutMs: 40000, run: async ({profileId, database}) => {
  const p = await profile(profileId); const t0 = Date.now();
  try { const r = await vetted(p, "SELECT CAST(SERVERPROPERTY('ServerName') AS nvarchar(128)) AS server, CAST(SERVERPROPERTY('Edition') AS nvarchar(128)) AS edition, CAST(SERVERPROPERTY('ProductVersion') AS nvarchar(64)) AS version, SUSER_SNAME() AS login, DB_NAME() AS db, IS_SRVROLEMEMBER('sysadmin') AS sysadmin", {database: database || p.defaultDatabase, timeout: 10}); return {ok: true, ...r.rows[0], connectMs: r.r.connectMs, elapsedMs: Date.now() - t0, production: p.production}; }
  catch (e) { return {ok: false, error: clip(e.message, 400), number: e.number, elapsedMs: Date.now() - t0, production: p.production}; }
}});
const dbArgs = v.object({profileId: v.string({max: 40}), database: v.string({max: 128, pattern: DB_NAME})});
define('sql.databases', {input: v.object({profileId: v.string({max: 40})}), timeoutMs: 40000, run: async ({profileId}) => ({databases: await databases(await profile(profileId))})});
define('sql.objects', {input: v.object({profileId: v.string({max: 40}), database: v.string({max: 128, pattern: DB_NAME}), search: v.optional(v.string({max: 64}))}), timeoutMs: 40000, run: async ({profileId, database, search}) => objects(await profile(profileId), database, {search})});
define('sql.describe', {input: v.object({profileId: v.string({max: 40}), database: v.string({max: 128, pattern: DB_NAME}), schema: v.string({max: 128}), name: v.string({max: 128})}), timeoutMs: 40000, run: async ({profileId, database, schema, name}) => describe(await profile(profileId), database, schema, name)});
define('sql.rows', {input: v.object({profileId: v.string({max: 40}), database: v.string({max: 128, pattern: DB_NAME}), schema: v.string({max: 128}), name: v.string({max: 128}), offset: v.optional(v.int({min: 0, max: 1e9})), limit: v.optional(v.int({min: 1, max: 200})), filterColumn: v.optional(v.string({max: 128})), filter: v.optional(v.string({max: 200})), orderBy: v.optional(v.string({max: 128})), desc: v.optional(v.bool())}), timeoutMs: 40000, run: async ({profileId, database, schema, name, ...rest}) => rows(await profile(profileId), database, schema, name, rest)});
define('sql.monitor', {input: dbArgs, quiet: true, timeoutMs: 40000, run: async ({profileId, database}) => monitor(await profile(profileId), database)});
define('sql.query', {input: v.object({profileId: v.string({max: 40}), database: v.string({max: 128, pattern: DB_NAME}), sql: v.string({min: 1, max: 200000, trim: false, oneLine: false}), mode: v.optional(v.enum(['read', 'write'])), planToken: v.optional(v.string({max: 40})), requestId: v.string({min: 8, max: 64, pattern: /^[a-z0-9-]+$/})}), timeoutMs: 320000, run: runQuery});
define('sql.cancel', {input: v.object({requestId: v.string({min: 8, max: 64, pattern: /^[a-z0-9-]+$/})}), run: async ({requestId}) => native('sql.cancel', {request: requestId}, 5000)});
define('sql.history', {input: v.object({}), run: async () => ({history: (await readJson(HISTORY, [])).slice(-100).reverse()})});
define('sql.history.clear', {input: v.object({}), run: async () => { await writeJson(HISTORY, []); return {cleared: true}; }});
define('sql.principals.prepare', {input: v.object({profileId: v.string({max: 40}), database: v.string({max: 128, pattern: DB_NAME}), confirm: v.optional(v.string({max: 128}))}), timeoutMs: 40000, run: async ({profileId, database, confirm}) => { const p = await profile(profileId);
  if (INSTALL && !testDatabase(p, database)) { if (confirm !== database) throw new UserError('Type the database name to add a read-only query user to it.', 400, {field: 'confirm', code: 'confirm-reader'}); return ensureReader(p.server, database); }
  if (!testDatabase(p, database)) throw new UserError('Principals are created only in DKPREVIEW_ databases on a test instance. For other databases an administrator can review and run the script below.', 403, {code: 'production'}); return ensurePrincipals(p.server, database); }});
define('sql.principals.script', {input: v.object({database: v.string({max: 128, pattern: DB_NAME})}), run: async ({database}) => ({script: `-- Review before running. Creates a database-only read principal (no login) that DK Command Center impersonates\n-- WITH NO REVERT for ad-hoc read-only queries. Run as an administrator of ${database}.\nUSE ${qi(database)};\nIF DATABASE_PRINCIPAL_ID('dkpreview_reader') IS NULL CREATE USER dkpreview_reader WITHOUT LOGIN;\nALTER ROLE db_datareader ADD MEMBER dkpreview_reader;\nGRANT VIEW DEFINITION TO dkpreview_reader;\nGRANT SHOWPLAN TO dkpreview_reader;\n-- Undo: DROP USER dkpreview_reader;`})});
define('sql.backup', {input: v.object({profileId: v.string({max: 40}), database: v.string({max: 128, pattern: DB_NAME}), confirmProduction: v.optional(v.bool())}), run: async p => backupJob(p)});
define('sql.backups', {input: v.object({}), run: async () => ({entries: (await backupLog()).slice(-50).reverse()})});
define('sql.backup.history', {input: dbArgs, timeoutMs: 30000, run: async ({profileId, database}) => ({rows: (await vetted(await profile(profileId), "SELECT TOP 20 CONVERT(varchar(19), backup_finish_date, 126) AS finished, type, is_copy_only AS copyOnly, CAST(backup_size / 1048576.0 AS decimal(18,1)) AS sizeMB, has_backup_checksums AS checksums, name FROM msdb.dbo.backupset WHERE database_name = @db ORDER BY backup_finish_date DESC", {database: 'master', params: {db: database}})).rows})});
define('sql.restore.rehearse', {input: v.object({profileId: v.string({max: 40}), file: v.string({max: 400}), sourceDatabase: v.optional(v.string({max: 128, pattern: DB_NAME}))}), run: async p => { const known = (await backupLog()).some(b => b.file === p.file && b.verified); if (!known) throw new UserError('Choose a backup this launcher created and verified.', 400); return restoreJob(p); }});
define('sql.drop.disposable', {input: v.object({profileId: v.string({max: 40}), database: v.string({max: 128, pattern: DB_NAME}), confirm: v.string({max: 128})}), timeoutMs: 90000, run: dropDisposable});
define('sql.migration.preview', {input: dbArgs, timeoutMs: 40000, run: migrationPreview});
define('sql.migration.apply', {input: dbArgs, run: async ({profileId, database}) => {
  const prev = await migrationPreview({profileId, database}); if (!prev.canApply) throw new UserError(prev.upToDate ? 'This database is already at the current schema.' : 'Prerequisites are not met: ' + prev.prerequisites.filter(x => !x.ok).map(x => x.name).join(', '), 409);
  const p = await profile(profileId);
  return startJob({kind: 'sql.migrate', key: 'sql.migrate:' + database, lane: 'world', area: 'sql', title: `Migrate ${database}`, run: async ctx => {
    ctx.phase('Apply additive schema', 'engine-schema.mjs ensureEngineSchema'); ctx.uncancellable();
    const {ensureEngineSchema} = await import(pathToFileURL(path.join(ENGINE, 'server', 'sql', 'engine-schema.mjs')).href);
    const {createSqlClient} = await import(pathToFileURL(path.join(ENGINE, 'server', 'sql', 'sql-client.mjs')).href);
    const sql = createSqlClient({instance: p.server, database: 'master'}); try { await ensureEngineSchema({sql, database}); } finally { await sql.close(); }
    return migrationPreview({profileId, database});
  }});
}});
