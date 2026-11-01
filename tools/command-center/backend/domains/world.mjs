// This installation's world server (or, in the preview, the sandbox engine's): start, adopt, readiness, status, stop - ported from client-ui.ps1
// Invoke-ClientLaunch / Stop-ClientDashboard / Get-LauncherControl with the same identity and ownership rules.
import fs from 'node:fs';
import fsp from 'node:fs/promises';
import path from 'node:path';
import os from 'node:os';
import {pathToFileURL} from 'node:url';
import {ENGINE, NODE, WORLD_PORT, HOSTED_PORT, LOGS, MAIN, INSTALL, inside, writable} from '../core/paths.mjs';
import {define, v} from '../core/rpc.mjs';
import {startJob, laneBusy} from '../core/jobs.mjs';
import {event} from '../core/events.mjs';
import {spawnOutside, runTool, alive} from '../core/proc.mjs';
import {native} from '../core/native.mjs';
import {UserError, readJson, readText, writeText, fetchJson, sleep, isPortFree, clip} from '../core/util.mjs';
import {settings} from './settings.mjs';
import {storageConfig, assertWorldDatabase, prepareSqlWorld} from './storage.mjs';
import {hostingEnvironment, onWorldStarted, onWorldStopping} from './hosting.mjs';

const mod = async rel => import(pathToFileURL(path.join(ENGINE, rel)).href);
const {engineIdentity, runtimeVersion} = await mod('server/client-identity.mjs');
const {clientSource} = await mod('server/client-source.mjs');

export const world = {
  status: 'stopped', mode: null, url: null, port: null, pid: null, owned: false, adopted: false, startedAt: null,
  control: null, identity: null, lastStatus: null, lastStatusAt: 0, lastError: null, failures: 0, logs: null,
  latency: [], spawnedPids: new Set(), cpu: null,
};
export function plan() {
  const source = clientSource(ENGINE);
  return {engine: ENGINE, engineId: engineIdentity(ENGINE), version: source.version, runtimeVersion: runtimeVersion(ENGINE), dataRoot: source.dataRoot, gamedataRoot: source.gamedataRoot, manifest: source.manifest};
}
let cachedPlan = null, planAt = 0;
export function currentPlan(force = false) { if (force || !cachedPlan || Date.now() - planAt > 30000) { cachedPlan = plan(); planAt = Date.now(); } return cachedPlan; }
const api = port => `http://127.0.0.1:${port}/`;
const sameIdentity = (s, p) => s && s.app === 'dekaron-engine' && s.engineId === p.engineId && s.version === p.version && (!p.runtimeVersion || s.runtimeVersion === p.runtimeVersion) && Number(s.pid) > 0;

async function controlFor(port) {
  let file = path.join(ENGINE, 'server', `launcher-control-${port}.json`);
  if (!fs.existsSync(file)) file = path.join(ENGINE, 'server', 'launcher-control.json');
  const c = await readJson(file, null, 16384);
  if (!c) return null;
  let u; try { u = new URL(c.url); } catch { return null; }
  if (u.protocol !== 'http:' || !['127.0.0.1', 'localhost'].includes(u.hostname) || !/^[a-f0-9]{64}$/.test(c.token || '')) return null;
  return {...c, controlUrl: c.controlUrl || c.url};
}
async function launcher(route, {method = 'GET', body, timeoutMs = 4000, control = world.control} = {}) {
  if (!control) throw new UserError('The world is not running.', 409);
  const r = await fetchJson(new URL('api/launcher/' + route, control.controlUrl.replace('localhost', '127.0.0.1')).href, {method, body, timeoutMs, headers: {'x-dekaron-launcher-token': control.token}});
  if (route === 'status' && method === 'GET') { world.latency.push(r.ms); if (world.latency.length > 120) world.latency.shift(); }
  return r;
}
export async function launcherCall(route, opts) { const r = await launcher(route, opts); if (!r.ok) throw new UserError(r.data?.error || (r.error === 'timeout' ? 'The world did not answer in time.' : 'The world did not confirm the request.'), r.status || 503); return r.data; }

/** Probe this launcher's ports for a server of THIS engine (identity + private control). Never touches other servers. */
export async function discover() {
  const p = currentPlan();
  for (const port of [WORLD_PORT, HOSTED_PORT]) {
    const pub = await fetchJson(api(port) + 'api/client/status', {timeoutMs: 800});
    if (!pub.ok || pub.data?.app !== 'dekaron-engine') continue;
    if (pub.data.engineId !== p.engineId) { if (world.port === port && world.status !== 'stopped') { world.status = 'stopped'; } continue; } // not ours (e.g. Main on 7778): ignored
    const control = await controlFor(port);
    if (!control || control.pid !== pub.data.pid || control.engineId !== p.engineId) { world.lastError = 'A server of this engine answers on port ' + port + ' but its private control file cannot be verified. Nothing was stopped.'; continue; }
    const st = await launcher('status', {control});
    if (!st.ok || Number(st.data?.pid) !== control.pid) continue;
    if (world.status === 'stopped' || world.pid !== control.pid) {
      Object.assign(world, {status: st.data.stopping ? 'stopping' : 'running', port, url: api(port), pid: control.pid, control, identity: pub.data, mode: pub.data.accountScope === 'friends' ? 'hosted' : 'local', owned: world.spawnedPids.has(control.pid), adopted: !world.spawnedPids.has(control.pid), startedAt: st.data.startedAt || Date.now()});
      if (world.adopted) event('info', 'world', `Found this engine's world already running on port ${port} (pid ${control.pid}); it is attached, not owned.`);
    }
    world.lastStatus = st.data; world.lastStatusAt = Date.now(); return world;
  }
  if (world.status === 'running' || world.status === 'stopping') { event(world.status === 'stopping' ? 'info' : 'warn', 'world', world.status === 'stopping' ? 'World stopped.' : 'The world is no longer answering.'); }
  if (world.status !== 'starting') Object.assign(world, {status: 'stopped', pid: null, control: null, url: null, port: null, owned: false, adopted: false, lastStatus: null});
  return world;
}

let refreshing = null, lastRefresh = null;
export async function refresh({maxAgeMs = 1500} = {}) {
  if (Date.now() - world.lastStatusAt < maxAgeMs && world.status !== 'stopped') return world;
  if (refreshing) return refreshing;
  // Clear the in-flight marker only after it was stored: a refresh that completes synchronously (for example while
  // the world is still starting) must not leave a settled promise behind, or no later refresh would ever run.
  const run = (async () => {
    if (world.control && world.status !== 'starting') {
        const st = await launcher('status');
        lastRefresh = {at: Date.now(), ok: st.ok, status: st.status, error: st.error || null, pid: st.data?.pid ?? null, controlPid: world.control.pid};
        if (st.ok && Number(st.data?.pid) === world.control.pid) { world.lastStatus = st.data; world.lastStatusAt = Date.now(); world.failures = 0; world.status = st.data.stopping ? 'stopping' : 'running'; return world; }
        world.failures++;
        if (!alive(world.control.pid)) { await discover(); return world; }
        world.lastError = st.error === 'timeout' ? 'The world is busy and did not answer the last status check.' : (st.data?.error || 'Status unavailable.');
        return world;
    }
    if (world.status !== 'starting') await discover();
    return world;
  })();
  refreshing = run;
  run.then(() => { if (refreshing === run) refreshing = null; }, () => { if (refreshing === run) refreshing = null; });
  return run;
}

function population(s) {
  const ok = n => Number.isInteger(n) && n >= 0 && n <= 100000;
  if (!s) return {known: false};
  const total = ok(s.players) ? s.players : null;
  const split = total !== null && ok(s.realPlayers) && ok(s.botPlayers) && s.realPlayers + s.botPlayers === total;
  return {known: split, total, humans: split ? s.realPlayers : null, bots: split ? s.botPlayers : null, connectedClients: ok(s.connectedClients) ? s.connectedClients : null};
}
export function snapshot() {
  const s = world.lastStatus, stale = world.status === 'running' && Date.now() - world.lastStatusAt > 8000;
  return {status: world.status, mode: world.mode, storageMode: s?.storageMode || null, storage: s?.storage || null, url: world.url, port: world.port, pid: world.pid, owned: world.owned, adopted: world.adopted,
    startedAt: world.startedAt, uptimeMs: world.startedAt && world.status === 'running' ? Date.now() - world.startedAt : null,
    name: s?.name || null, population: population(s), stale, lastStatusAt: world.lastStatusAt || null, lastError: world.lastError,
    ownerAvailable: !!s?.ownerAvailable, accountsAvailable: !!s?.accountsAvailable, settingsAvailable: !!s?.settingsAvailable, builderReady: !!s?.builderReady, primary: s?.primary || null,
    hostMode: world.identity?.hostMode || null, listenHost: world.identity?.listenHost || null, relayEnabled: !!world.identity?.relayEnabled, adminGuild: s?.adminGuild || null,
    busy: laneBusy('world')};
}

// ---- start
function serverArgs() {
  const cap = readJsonSync(path.join(ENGINE, 'server', 'capacity.json'));
  const mb = Number(cap?.memoryMB);
  return Number.isInteger(mb) && mb >= 1024 && mb <= 1048576 ? [`--max-old-space-size=${mb}`, 'server.mjs'] : ['server.mjs'];
}
function readJsonSync(f) { try { return JSON.parse(fs.readFileSync(f, 'utf8')); } catch { return null; } }

export async function preparedReadiness() {
  // Read-only equivalent of client-ready for a dedicated copy: the active prepared generation resolves, its manifest
  // matches, and the release-required tables exist and parse. (client-ready.mjs itself only knows engines with their own cache.)
  const t0 = performance.now();
  try {
    const {READY_TABLES} = await mod('tools/client-ready.mjs');
    const s = clientSource(ENGINE);
    if (!s.manifest) return {ready: false, reason: 'No validated prepared generation is active.', ms: 0};
    const missing = [];
    for (const name of READY_TABLES) { const f = path.join(s.gamedataRoot, name); try { const st = await fsp.stat(f); if (!st.isFile()) missing.push(name); else if (st.size < 1024 * 1024 * 64) JSON.parse(await fsp.readFile(f, 'utf8')); } catch { missing.push(name); } }
    if (!fs.existsSync(path.join(s.dataRoot, 'share', 'maplist.csv'))) missing.push('data/share/maplist.csv');
    return {ready: !missing.length, missing, generation: s.manifest.generation, fingerprint: s.version, sourceKind: s.manifest.source?.kind, dataRoot: s.dataRoot, ms: Math.round(performance.now() - t0)};
  } catch (e) { return {ready: false, reason: e.message, ms: Math.round(performance.now() - t0)}; }
}

async function prestart(operation, scope, value) {
  const r = await runTool(path.join(ENGINE, 'tools', 'client-prestart-settings.mjs'), [operation, scope], {input: value === undefined ? 'null' : value, timeoutMs: 30000});
  if (r.code !== 0) throw new UserError(clip((r.stderr || r.stdout).trim(), 400) || 'Offline settings were not confirmed.');
  return JSON.parse(r.stdout.trim().split(/\r?\n/).at(-1));
}
export const offlineSettings = prestart;

async function measureUpload(ctx) {
  ctx.phase('Measure upload', 'Measuring this PC\'s upload with the engine\'s speed test (random bytes only)');
  const r = await runTool(path.join(ENGINE, 'tools', 'net-speed-test.mjs'), ['--seconds', '4'], {timeoutMs: 60000, signal: ctx.signal});
  const reply = JSON.parse((r.stdout || '{}').trim().split(/\r?\n/).at(-1) || '{}');
  if (r.code !== 0 || reply.ok !== true || !(reply.uploadMbps > 0)) throw new Error('The internet test did not finish. Saved upload settings were kept.');
  const upload = Math.round(reply.uploadMbps * 10) / 10;
  await prestart('capacitySet', 'local', {uploadMbps: upload});
  ctx.log(`Host connection: upload ${reply.uploadMbps} Mbps, download ${reply.downloadMbps} Mbps, latency ${reply.latencyMs} ms. Upload budget saved.`);
  return reply;
}

export function startWorld({mode = 'local', reviewed = false} = {}) {
  return startJob({kind: 'world.start', key: 'world.start', lane: 'world', area: 'world', title: mode === 'hosted' ? 'Start hosted world' : 'Start world', run: async ctx => {
    const port = mode === 'hosted' ? HOSTED_PORT : WORLD_PORT;
    ctx.phase('Verify installation', INSTALL ? 'Checking the engine and its prepared Global data' : 'Checking the sandbox engine and its prepared Global data');
    if (!fs.existsSync(path.join(ENGINE, 'server.mjs')) || !fs.existsSync(NODE)) throw new Error(INSTALL ? 'This DK Engine installation is incomplete. Restore the complete Engine download.' : 'The sandbox engine is incomplete. Run Setup-Preview.cmd.');
    if (!INSTALL && inside(ENGINE, MAIN)) throw new Error('Refusing to run a world inside the installed game.');
    const p = currentPlan(true);
    const ready = await preparedReadiness();
    if (!ready.ready) throw new Error('Prepared Global data is not usable: ' + (ready.reason || ('missing ' + ready.missing.slice(0, 3).join(', '))));
    ctx.log(`Prepared generation ${ready.generation} (${ready.sourceKind}), ${ready.ms} ms read-only check.`);
    await discover();
    if (world.status === 'running') {
      if (world.mode !== mode) throw new Error(`A ${world.mode} world is already running. Stop it first; nothing was stopped.`);
      if (!sameIdentity(world.identity, p)) throw new Error('The running world uses older code or data. Stop it deliberately, then start again. Nothing was stopped.');
      ctx.log('Existing world identity confirmed; attaching instead of starting a second writer.');
      return {attached: true, ...snapshot()};
    }
    ctx.phase('Check storage', 'Confirming the storage this world will use');
    const storage = await storageConfig();
    const env = {PORT: String(port), DEKARON_HOST: '127.0.0.1', DEKARON_LAUNCHER_PID: String(process.pid), DEKARON_PRIVATE_ACCOUNT_DIR: '0'};
    if (storage.mode === 'sqlserver') {
      const db = mode === 'hosted' ? storage.hostedDatabase : storage.localDatabase;
      assertWorldDatabase(storage.instance, db);
      const rows = await native('sql.query', {server: storage.instance, database: 'master', mode: 'catalog', sql: "SELECT DB_ID(@db) AS id", params: {db}, timeout: 10});
      // First SQL start stays one click: create the disposable DKPREVIEW_ test database with the engine's own schema.
      if (!rows.sets?.[0]?.rows?.[0]?.[0]) { ctx.phase('Set up SQL test database', `Creating ${db} on ${storage.instance} with the engine's schema`); await prepareSqlWorld(ctx, {scope: mode === 'hosted' ? 'hosted' : 'local'}); }
      Object.assign(env, {DEKARON_DEDICATED_STORAGE: 'sqlserver', DEKARON_SQL_INSTANCE: storage.instance, DEKARON_DEDICATED_SQL_DB: db});
      ctx.log(`SQL storage: ${db} on ${storage.instance}${INSTALL ? '' : ' (preview test database)'}.`);
    } else ctx.log(INSTALL ? 'Local file storage: server/accounts.' : 'Local file storage: sandbox/engine/server/accounts.');
    ctx.phase('Review world settings', 'First start requires the existing world-settings review');
    const scope = mode === 'hosted' ? 'friends' : 'local';
    const review = await prestart('read', scope);
    if (!review.reviewed && !reviewed) { const e = new Error('Review this world\'s settings before its first start.'); e.code = 'review-required'; e.settings = review.settings; throw e; }
    if (!review.reviewed) await prestart('review', scope);
    if (mode === 'hosted') Object.assign(env, await hostingEnvironment(ctx));
    ctx.phase('Reserve address', `Checking that port ${port} is free`);
    if (!await isPortFree(port)) throw new Error(`Port ${port} is used by another program or installation. Other servers are never stopped from here. Close it there, then retry.`);
    if (mode !== 'hosted' && (await settings()).measureUploadBeforeStart) {
      try { await measureUpload(ctx); } catch (e) { ctx.log('Host internet test unavailable; saved upload setting kept. ' + e.message); }
    }
    ctx.throwIfCancelled();
    ctx.phase('Start server', 'Starting the world process');
    const run = new Date().toISOString().replace(/[:.]/g, '-');
    const out = path.join(LOGS, `world-${run}.log`), err = path.join(LOGS, `world-${run}.err.log`);
    writable(out);
    const h = await spawnOutside({exe: NODE, args: serverArgs(), cwd: ENGINE, env, stdout: out, stderr: err});
    world.spawnedPids.add(h.pid);
    Object.assign(world, {status: 'starting', mode, port, logs: {out, err}, lastError: null});
    event('info', 'world', `World process started (pid ${h.pid}, port ${port}${h.breakaway ? ', outside the launcher job' : ''}).`);
    ctx.uncancellable();
    let url = null; const deadline = Date.now() + (storage.mode === 'sqlserver' ? 60000 : 30000);
    while (Date.now() < deadline) {
      await sleep(150);
      if (!alive(h.pid)) { const text = await readText(err, '') || await readText(out, ''); world.status = 'stopped'; throw new Error('The world exited before it was ready. ' + clip(text.trim().split(/\r?\n/).slice(-4).join(' '), 400)); }
      const m = /Dekaron (?:Online|Dedicated) running at (http:\/\/\S+)/.exec(await readText(out, '')); if (m) { url = m[1]; break; }
    }
    if (!url) { world.status = 'unknown'; throw new Error('World readiness was not confirmed in time. Check the world log before starting another copy. Nothing was stopped.'); }
    const pub = await fetchJson(api(port) + 'api/client/status', {timeoutMs: 3000});
    if (!sameIdentity(pub.data, p) || pub.data.pid !== h.pid) { world.status = 'unknown'; throw new Error('The started world identity could not be verified. Nothing was stopped.'); }
    const control = await controlFor(port);
    if (!control || control.pid !== h.pid) { world.status = 'unknown'; throw new Error('The world started but its private control file could not be verified.'); }
    Object.assign(world, {status: 'running', url: api(port), pid: h.pid, control, identity: pub.data, owned: true, adopted: false, startedAt: Date.now()});
    ctx.phase('Prepare world', 'Waiting for the shared world to finish preparing');
    let polls = 0;
    while (true) {
      const r = await launcher('preparation', {timeoutMs: 10000});
      if (!r.ok) { if (++polls > 60) throw new Error('The world did not answer preparation checks for 10 minutes.'); await sleep(250); continue; }
      polls = 0; const st = r.data?.preparation;
      if (!st || typeof st.ready !== 'boolean') throw new Error('Invalid world preparation response.');
      if (st.ready) break;
      if (st.phase === 'failed') throw new Error('World preparation failed. Review the world log, then retry deliberately.');
      if (st.progress && Number.isInteger(st.progress.admitted) && Number.isInteger(st.progress.target) && st.progress.target > 0) { ctx.progress(st.progress.admitted, st.progress.target, 'bots admitted'); ctx.message(`Preparing native bots: ${st.progress.admitted} of ${st.progress.target}`); }
      await sleep(Math.min(3000, Math.max(250, Number(st.retryAfterMs) || 500)));
    }
    ctx.phase('Open dashboard', 'Registering this launcher run');
    await launcher('begin', {method: 'POST', body: {}});
    if (mode === 'hosted') await onWorldStarted(ctx, world);
    await refresh({maxAgeMs: 0});
    event('ok', 'world', `World ready at ${world.url} (${mode}).`);
    return snapshot();
  }});
}

// ---- stop
export async function stopWorld({reason = 'Stop'} = {}) {
  return startJob({kind: 'world.stop', key: 'world.stop', lane: 'world', area: 'world', title: 'Stop world', run: async ctx => {
    await refresh({maxAgeMs: 0});
    if (world.status === 'stopped') return {alreadyStopped: true};
    if (!world.control) throw new Error('The world control could not be verified. Nothing was stopped.');
    ctx.phase('Check sessions', 'Making sure nobody is still connected');
    const st = await launcher('status', {timeoutMs: 5000});
    if (!st.ok) throw new Error('The world did not answer. Nothing was stopped; retry shortly.');
    const connected = Math.max(Number(st.data.connectedClients) || 0, Number(st.data.realPlayers) || 0);
    if (connected > 0) { const e = new Error(`Disconnect all clients first (${connected} connected). Sign out of the lobby too, or wait one minute after closing a client.`); e.code = 'clients-connected'; throw e; }
    await onWorldStopping(ctx);
    ctx.phase('Save and stop', 'Saving every character, then stopping');
    ctx.uncancellable();
    world.status = 'stopping';
    const r = await launcher('stop', {method: 'POST', body: {}, timeoutMs: 60000});
    if (!r.ok || !r.data?.stopped || !r.data?.saved) { world.status = 'running'; throw new Error(r.data?.error || 'The world did not confirm that characters were saved. It has not been terminated.'); }
    ctx.phase('Wait for exit', 'Waiting (bounded, never killing) for the process to exit');
    const pid = world.control.pid, until = Date.now() + 10000;
    while (alive(pid) && Date.now() < until) await sleep(100);
    const exited = !alive(pid);
    event('ok', 'world', `World saved and stopped (${reason})${exited ? '' : '; process still exiting'}.`);
    Object.assign(world, {status: 'stopped', pid: null, control: null, url: null, port: null, owned: false, adopted: false, lastStatus: null, startedAt: null});
    return {stopped: true, saved: true, exited};
  }});
}

// ---- metrics (real measurements only)
let lastCpu = null;
export async function metrics() {
  await refresh();
  const out = {at: Date.now(), world: snapshot(), process: null, capacity: null, latency: null, backend: {rssMB: Math.round(process.memoryUsage().rss / 1048576), heapMB: Math.round(process.memoryUsage().heapUsed / 1048576), uptimeS: Math.round(process.uptime())}};
  const lat = [...world.latency].sort((a, b) => a - b);
  if (lat.length) out.latency = {samples: lat.length, p50: lat[Math.floor(lat.length * .5)], p95: lat[Math.min(lat.length - 1, Math.floor(lat.length * .95))], max: lat.at(-1), unit: 'ms', what: 'launcher status request round trip'};
  if (world.pid && world.status === 'running') {
    try {
      const r = await native('proc.stats', {pids: [world.pid]}, 5000); const p = r.processes[0];
      if (p?.alive) {
        const t = Date.now(); let cpuPercent = null;
        if (lastCpu && lastCpu.pid === p.pid && t > lastCpu.t) cpuPercent = Math.max(0, Math.round(((p.cpuMs - lastCpu.cpuMs) / (t - lastCpu.t)) / os.cpus().length * 1000) / 10);
        lastCpu = {pid: p.pid, cpuMs: p.cpuMs, t};
        out.process = {pid: p.pid, cpuPercent, cpuNote: 'share of all logical CPUs since the previous sample', workingSetMB: Math.round(p.workingSet / 1048576), privateMB: Math.round(p.private / 1048576), threads: p.threads, handles: p.handles};
      }
    } catch (e) { out.processError = e.message; }
    const cap = await launcher('capacity', {timeoutMs: 4000});
    if (cap.ok) out.capacity = cap.data; else out.capacityError = cap.data?.error || cap.error;
  }
  return out;
}

// ---- RPC
define('world.status', {input: v.object({fresh: v.optional(v.bool())}), quiet: true, run: async ({fresh}) => { await refresh({maxAgeMs: fresh ? 0 : 1500}); return snapshot(); }});
define('world.plan', {input: v.object({}), run: async () => { const p = currentPlan(true); return {...p, readiness: await preparedReadiness(), mainPreparedReadOnly: true}; }});
define('world.start', {input: v.object({mode: v.optional(v.enum(['local', 'hosted'])), reviewed: v.optional(v.bool())}), run: async p => startWorld(p)});
define('world.stop', {input: v.object({}), run: async () => stopWorld()});
define('world.restart', {input: v.object({}), run: async () => startJob({kind: 'world.restart', key: 'world.restart', area: 'world', title: 'Restart world', run: async ctx => {
  const mode = world.mode || 'local';
  ctx.phase('Stop', 'Saving and stopping'); const s = await stopWorld({reason: 'Restart'}); await waitJob(s.id, ctx);
  ctx.phase('Start', 'Starting again'); const j = startWorld({mode, reviewed: true}); return await waitJob(j.id, ctx);
}})});
define('world.metrics', {input: v.object({}), quiet: true, run: metrics});
if (process.env.DKCC_TEST === '1') define('world.debug', {input: v.object({}), run: async () => ({status: world.status, pid: world.pid, controlPid: world.control?.pid ?? null, controlUrl: world.control?.controlUrl ?? null, lastStatusAt: world.lastStatusAt, failures: world.failures, refreshing: !!refreshing, lastRefresh, lastError: world.lastError})});
define('world.logs', {input: v.object({}), run: async () => ({logs: world.logs, port: world.port})});
async function waitJob(id, ctx) { const {getJob} = await import('../core/jobs.mjs'); for (;;) { const j = getJob(id); if (j.state === 'succeeded') return j.result; if (j.state !== 'running') throw new Error(j.error || j.state); ctx?.message(j.message); await sleep(250); } }
export {waitJob};
