// World storage: local files or SQL Server, using the same files as the classic launcher (run/dashboard-storage.txt and
// run/dashboard-sql-instance.txt).
//  - Installed: the engine's own world databases (DEKARON_DEDICATED for the local world, DEKARON_DEDICATED_HOSTED for the
//    hosted world), set up by the engine's tools/setup-dedicated-sql.mjs and, when SQL Express is missing, installed by
//    tools/install-dedicated-sql.ps1 after the Microsoft terms are accepted (Windows asks for permission).
//  - Preview: worlds and write operations only ever target disposable DKPREVIEW_* databases on a non-production
//    instance; Main's instance is always read-only.
import path from 'node:path';
import fs from 'node:fs';
import os from 'node:os';
import {pathToFileURL} from 'node:url';
import {ENGINE, MAIN, PROFILE, INSTALL, TEST_DB_PREFIX, WORLD_PORT} from '../core/paths.mjs';
import {define, v, SQL_INSTANCE, DB_NAME} from '../core/rpc.mjs';
import {readText, writeText, readJson, writeJson, UserError, clip} from '../core/util.mjs';
import {startJob} from '../core/jobs.mjs';
import {native} from '../core/native.mjs';
import {runTool} from '../core/proc.mjs';
import {event} from '../core/events.mjs';
import {copyFileSync} from 'node:fs';

const STORAGE = path.join(ENGINE, 'run', 'dashboard-storage.txt'), INSTANCE = path.join(ENGINE, 'run', 'dashboard-sql-instance.txt');
const NAMES = path.join(PROFILE, 'storage.json');
const ENGINE_DATABASES = {local: 'DEKARON_DEDICATED', hosted: 'DEKARON_DEDICATED_HOSTED'};
export const TEST_PREFIX = new RegExp('^' + TEST_DB_PREFIX + '[A-Z0-9_]{1,100}$', 'i');
export const normInstance = s => String(s || '').trim().replace(/^\(local\)|^localhost/i, '.').replace(/^127\.0\.0\.1/, '.').toUpperCase();
/** Instances whose data this launcher must only read. Installed: none (it manages its own world). Preview: Main's. */
export function productionInstances() {
  const set = new Set();
  if (INSTALL) return set;
  try { const t = fs.readFileSync(path.join(MAIN, 'run', 'dashboard-sql-instance.txt'), 'utf8').trim(); if (t) set.add(normInstance(t)); } catch {}
  set.add(normInstance('.\\DEKARONBETA'));
  return set;
}
export const isProduction = instance => productionInstances().has(normInstance(instance));
export function assertWorldDatabase(instance, db) {
  if (!SQL_INSTANCE.test(instance)) throw new UserError('Enter a SQL host, host\\instance or host,port.');
  if (INSTALL) { if (!Object.values(ENGINE_DATABASES).includes(db)) throw new UserError('Choose the Local world or Hosted world database.'); return; }
  if (isProduction(instance)) throw new UserError(`${instance} is the installed game's SQL instance. The preview only reads it; its worlds use a disposable test database on another instance.`, 403);
  if (!TEST_PREFIX.test(db)) throw new UserError(`The preview only writes to databases named DKPREVIEW_…; ${db} is refused.`, 403);
}
export function validateInstance(value) {
  const s = String(value || '').trim();
  if (s.length > 200 || !SQL_INSTANCE.test(s)) throw new UserError('Enter a SQL host, host\\instance, or host,port. Credentials and connection-string options are not accepted.');
  const m = /,([0-9]+)$/.exec(s); if (m && Number(m[1]) > 65535) throw new UserError('SQL port must be between 1 and 65535.');
  return s;
}
export async function storageConfig() {
  const mode = (await readText(STORAGE, 'json')).trim() === 'sqlserver' ? 'sqlserver' : 'json';
  const instance = (await readText(INSTANCE, '.\\SQLEXPRESS')).trim() || '.\\SQLEXPRESS';
  if (INSTALL) return {mode, instance, localDatabase: ENGINE_DATABASES.local, hostedDatabase: ENGINE_DATABASES.hosted, production: []};
  const names = await readJson(NAMES, {});
  return {mode, instance, localDatabase: names.localDatabase || 'DKPREVIEW_TEST_WORLD', hostedDatabase: names.hostedDatabase || 'DKPREVIEW_TEST_HOSTED', production: [...productionInstances()]};
}
async function assertStopped() { const {world} = await import('./world.mjs'); if (world.status !== 'stopped') throw new UserError('Stop the world before changing its storage.', 409); }

async function setStorage({mode, instance, localDatabase, hostedDatabase}) {
  await assertStopped();
  const next = await storageConfig();
  if (instance !== undefined) next.instance = validateInstance(instance);
  if (INSTALL && (localDatabase !== undefined || hostedDatabase !== undefined)) throw new UserError('The engine uses DEKARON_DEDICATED for the local world and DEKARON_DEDICATED_HOSTED for the hosted world.');
  if (localDatabase !== undefined) { if (!TEST_PREFIX.test(localDatabase)) throw new UserError('Preview world databases must start with DKPREVIEW_.'); next.localDatabase = localDatabase; }
  if (hostedDatabase !== undefined) { if (!TEST_PREFIX.test(hostedDatabase)) throw new UserError('Preview world databases must start with DKPREVIEW_.'); next.hostedDatabase = hostedDatabase; }
  if (mode === 'sqlserver' && isProduction(next.instance)) throw new UserError(`${next.instance} belongs to the installed game. Choose a test instance such as .\\SQLEXPRESS for the preview world.`, 403);
  if (mode !== undefined) await writeText(STORAGE, mode);
  await writeText(INSTANCE, next.instance);
  if (!INSTALL) await writeJson(NAMES, {localDatabase: next.localDatabase, hostedDatabase: next.hostedDatabase});
  event('info', 'sql', `Storage for the next world start: ${mode ?? next.mode}${(mode ?? next.mode) === 'sqlserver' ? ` (${next.instance})` : ''}. Switching storage does not merge or migrate data.`);
  return storageConfig();
}

const engineModule = rel => import(pathToFileURL(path.join(ENGINE, rel)).href);
export async function catalog(instance, sql, params = {}, database = 'master', timeout = 15) {
  const r = await native('sql.query', {server: instance, database, mode: 'catalog', sql, params, timeout, maxRows: 2000, app: 'DK Command Center'}, (timeout + 20) * 1000);
  const set = r.sets?.[0]; return {rows: set ? set.rows.map(row => Object.fromEntries(set.columns.map((c, i) => [c.name, row[i]]))) : [], raw: r};
}

/** Existing "Check SQL": reachability, edition and whether the selected world database exists (read-only). */
export async function checkSqlWorld({scope = 'local'} = {}) {
  const cfg = await storageConfig(), db = scope === 'hosted' ? cfg.hostedDatabase : cfg.localDatabase;
  const t0 = Date.now();
  const info = await catalog(cfg.instance, "SELECT CAST(SERVERPROPERTY('Edition') AS nvarchar(128)) AS edition, CAST(SERVERPROPERTY('ProductVersion') AS nvarchar(64)) AS version, DB_ID(@db) AS dbid", {db});
  const row = info.rows[0] || {}; let accounts = null, schemaVersion = null, tables = [];
  if (row.dbid) {
    tables = (await catalog(cfg.instance, "SELECT name FROM sys.tables WHERE name LIKE 'engine[_]%' ORDER BY name", {}, db)).rows.map(r => r.name);
    if (tables.includes('engine_account')) accounts = (await catalog(cfg.instance, 'SELECT COUNT(*) AS n FROM dbo.engine_account', {}, db)).rows[0]?.n ?? null;
    if (tables.includes('engine_meta')) schemaVersion = (await catalog(cfg.instance, "SELECT v FROM dbo.engine_meta WHERE k='schema_version'", {}, db)).rows[0]?.v ?? null;
  }
  return {instance: cfg.instance, database: db, installed: !!row.dbid, edition: row.edition, version: row.version, accounts, schemaVersion, tables, production: isProduction(cfg.instance), ms: Date.now() - t0};
}

/** Existing "Set up SQL world". */
export function setupSqlWorld({scope = 'local'} = {}) {
  return startJob({kind: 'sql.world.setup', key: 'sql.world.setup', lane: 'world', area: 'sql', title: INSTALL ? 'Set up SQL world' : 'Set up SQL test world', run: async ctx => { await assertStopped(); return prepareSqlWorld(ctx, {scope}); }});
}
/** The setup steps themselves; also run inline by "Start world" when SQL storage is chosen and the database is new. */
export async function prepareSqlWorld(ctx, {scope = 'local'} = {}) {
  const cfg = await storageConfig(), db = scope === 'hosted' ? cfg.hostedDatabase : cfg.localDatabase;
  assertWorldDatabase(cfg.instance, db);
  if (INSTALL) {
    // Exactly what the classic launcher runs: the engine's own setup tool (it reserves the stopped world, backs up the
    // account file to run/, then creates or checks the schema).
    ctx.phase('Set up SQL world', `${db} on ${cfg.instance} (engine setup tool)`);
    const r = await runTool(path.join(ENGINE, 'tools', 'setup-dedicated-sql.mjs'), ['--setup'], {cwd: ENGINE, env: {DEKARON_SQL_INSTANCE: cfg.instance, DEKARON_DEDICATED_SQL_DB: db}, timeoutMs: 180000});
    if (r.code !== 0) throw new UserError(clip((r.stderr || r.stdout).trim(), 500) || 'SQL setup failed.');
    const reply = JSON.parse(r.stdout.trim().split(/\r?\n/).at(-1));
    event('ok', 'sql', `SQL world ready: ${reply.database} on ${reply.instance} (${reply.accounts ?? 0} accounts).`);
    return checkSqlWorld({scope});
  }
  ctx.phase('Check SQL', `${cfg.instance}`);
  const before = await checkSqlWorld({scope});
  if (before.installed) {
    ctx.phase('Check ownership', 'Making sure no running world owns this database');
    const lock = await catalog(cfg.instance, "SELECT APPLOCK_TEST('public', N'DekaronDedicatedWorld', 'Exclusive', 'Session') AS free", {}, db);
    if (Number(lock.rows[0]?.free) !== 1) throw new Error('A world currently owns this SQL database. Stop it first.');
  }
  ctx.phase('Back up local account file', 'Copying the sandbox account file before setup');
  const source = path.join(ENGINE, 'server', 'accounts', scope === 'hosted' ? 'friends-accounts.json' : 'data.json');
  if (fs.existsSync(source)) { const backup = path.join(ENGINE, 'run', `sql-setup-account-backup-${new Date().toISOString().replace(/[:.]/g, '-')}.json`); copyFileSync(source, backup); if (fs.existsSync(source + '.journal')) copyFileSync(source + '.journal', backup + '.journal'); ctx.log('Account file backed up to run/' + path.basename(backup)); }
  ctx.phase('Create schema', `Creating or checking ${db} with the engine's own schema statements`);
  const {ensureEngineSchema} = await engineModule('server/sql/engine-schema.mjs');
  const {createSqlClient} = await engineModule('server/sql/sql-client.mjs');
  const sql = createSqlClient({instance: cfg.instance, database: 'master'});
  try { const r = await ensureEngineSchema({sql, database: db}); ctx.log(r.created ? `Created database ${db}.` : `Database ${db} already existed; schema checked.`); }
  finally { await sql.close(); }
  ctx.phase('Prepare query principals', 'Creating database-only read and write principals for the query workspace');
  await ensurePrincipals(cfg.instance, db);
  const after = await checkSqlWorld({scope});
  event('ok', 'sql', `SQL test world ready: ${db} on ${cfg.instance} (${after.accounts ?? 0} accounts).`);
  return after;
}

/** Users WITHOUT LOGIN inside a disposable test database: the query workspace impersonates them WITH NO REVERT. */
export async function ensurePrincipals(instance, db) {
  if (!TEST_PREFIX.test(db) || isProduction(instance)) throw new UserError(`Read and write query users are only created in ${TEST_DB_PREFIX} test databases.`, 403);
  const q = `IF DATABASE_PRINCIPAL_ID('dkpreview_reader') IS NULL CREATE USER dkpreview_reader WITHOUT LOGIN;
ALTER ROLE db_datareader ADD MEMBER dkpreview_reader; GRANT VIEW DEFINITION TO dkpreview_reader; GRANT SHOWPLAN TO dkpreview_reader;
IF DATABASE_PRINCIPAL_ID('dkpreview_writer') IS NULL CREATE USER dkpreview_writer WITHOUT LOGIN;
ALTER ROLE db_datareader ADD MEMBER dkpreview_writer; ALTER ROLE db_datawriter ADD MEMBER dkpreview_writer; ALTER ROLE db_ddladmin ADD MEMBER dkpreview_writer; GRANT VIEW DEFINITION TO dkpreview_writer; GRANT SHOWPLAN TO dkpreview_writer;
SELECT 1 AS ok;`;
  await catalog(instance, q, {}, db, 30);
  return {reader: 'dkpreview_reader', writer: 'dkpreview_writer'};
}
/** Installed only: a read-only query user (no login, db_datareader) in the world database, created on explicit request. */
export async function ensureReader(instance, db) {
  if (!INSTALL || isProduction(instance)) throw new UserError('The preview never adds users to non-test databases.', 403);
  await catalog(instance, `IF DATABASE_PRINCIPAL_ID('dkpreview_reader') IS NULL CREATE USER dkpreview_reader WITHOUT LOGIN;
ALTER ROLE db_datareader ADD MEMBER dkpreview_reader; GRANT VIEW DEFINITION TO dkpreview_reader; GRANT SHOWPLAN TO dkpreview_reader; SELECT 1 AS ok;`, {}, db, 30);
  event('info', 'sql', `Read-only query user added to ${db} (database-only user without a login; reads and query plans only).`);
  return {reader: 'dkpreview_reader'};
}

const rel = p => path.relative(path.dirname(ENGINE), p).replaceAll('\\', '/');
define('storage.get', {input: v.object({}), run: async () => ({...(await storageConfig()), engineFiles: {storage: rel(STORAGE), instance: rel(INSTANCE)}, note: 'Applies on the next world start. Changing storage never merges or migrates existing progress.'})});
define('storage.set', {input: v.object({mode: v.optional(v.enum(['json', 'sqlserver'])), instance: v.optional(v.string({max: 200})), localDatabase: v.optional(v.string({max: 110, pattern: DB_NAME})), hostedDatabase: v.optional(v.string({max: 110, pattern: DB_NAME}))}), run: setStorage});
define('storage.check', {input: v.object({scope: v.optional(v.enum(['local', 'hosted']))}), timeoutMs: 60000, run: checkSqlWorld});
define('storage.setup', {input: v.object({scope: v.optional(v.enum(['local', 'hosted']))}), run: async p => setupSqlWorld(p)});
define('storage.prepareAutomatically', {input: v.object({instance: v.string({max: 200}), acceptLicense: v.optional(v.bool())}), run: async ({instance, acceptLicense}) => {
  // Existing feature: install or reuse a local named SQL Express instance, then set up the world database.
  const s = validateInstance(instance); const m = /^(?:\.|\(local\)|localhost)\\([A-Za-z][A-Za-z0-9_]{0,15})$/i.exec(s);
  if (!m || ['MSSQLSERVER', 'DEFAULT'].includes(m[1].toUpperCase())) throw new UserError('Automatic setup requires a local named instance such as .\\SQLEXPRESS.');
  if (isProduction(s)) throw new UserError('That instance belongs to the installed game; the preview will not prepare a world there.', 403);
  const name = m[1].toUpperCase();
  const svc = await import('node:child_process').then(({execFileSync}) => { try { return execFileSync('sc.exe', ['query', 'MSSQL$' + name], {encoding: 'utf8', windowsHide: true}); } catch { return ''; } });
  const installed = /SERVICE_NAME/i.test(svc);
  if (!INSTALL && !/STATE\s*:\s*\d+\s+RUNNING/i.test(svc)) throw new UserError(`MSSQL$${name} is not installed or not running. Installing SQL Server Express is disabled in the Test Preview because it changes this PC; it remains available in the integrated launcher.`, 409, {code: 'install-disabled'});
  if (INSTALL && !installed && !acceptLicense) throw new UserError('Review and accept the Microsoft SQL Server Express license terms and privacy notice before automatic installation.', 409, {code: 'license-required'});
  await assertStopped(); await setStorage({instance: s});
  return startJob({kind: 'sql.prepare', key: 'sql.prepare', lane: 'world', area: 'sql', title: `Prepare SQL (${s})`, run: async ctx => {
    if (INSTALL) {
      // The engine's own installer: Microsoft media over HTTPS, signature check, unattended install; Windows asks for
      // administrator permission. Progress lines come from its progress file.
      ctx.phase(installed ? 'Start SQL Server' : 'Install SQL Server Express', installed ? `Making sure MSSQL$${name} is running` : 'Downloading and installing Microsoft SQL Server 2019 Express (Windows asks for permission)');
      const progress = path.join(os.tmpdir(), `dekaron-sql-phase-${Date.now().toString(16)}${Math.random().toString(16).slice(2, 10)}.txt`);
      let stop = false; const watch = (async () => { let last = ''; while (!stop) { await new Promise(r => setTimeout(r, 500)); try { const t = fs.readFileSync(progress, 'utf8').trim(); if (t && t !== last) { last = t; ctx.message(clip(t, 200)); ctx.log(clip(t, 300)); } } catch {} } })();
      try {
        const r = await runTool(null, ['-NoProfile', '-ExecutionPolicy', 'Bypass', '-File', path.join(ENGINE, 'tools', 'install-dedicated-sql.ps1'), '-InstanceName', name, '-ProgressFile', progress, ...(acceptLicense ? ['-AcceptLicense'] : [])], {exe: 'powershell.exe', cwd: ENGINE, timeoutMs: 60 * 60 * 1000, signal: ctx.signal});
        if (r.code !== 0) throw new UserError(clip((r.stderr || r.stdout).trim(), 500) || 'SQL Server preparation failed.');
      } finally { stop = true; await watch; try { fs.rmSync(progress, {force: true}); } catch {} }
    }
    const result = await prepareSqlWorld(ctx, {scope: 'local'});
    await setStorage({mode: 'sqlserver'});
    ctx.log('SQL storage selected for the next world start.');
    return result;
  }});
}});
