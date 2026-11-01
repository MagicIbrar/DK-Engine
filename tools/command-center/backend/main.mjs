// DK Command Center backend entry (installed launcher or Test Preview). Started by the desktop window (or by tests in headless mode).
import fs from 'node:fs';
import path from 'node:path';
import {attachShell, send, shellEvents, hasShell, request} from './core/shell.mjs';
import {INSTALL, MODE, ENGINE, writable} from './core/paths.mjs';
import {createBridge} from './core/http.mjs';
import {define, v} from './core/rpc.mjs';
import {event} from './core/events.mjs';
import {getJob, cancelJob, listJobs, cancelAll} from './core/jobs.mjs';
import {killOwned} from './core/proc.mjs';
import {stopNative} from './core/native.mjs';

const started = performance.now();
const shell = attachShell();
// Domain modules register their operations on import.
await import('./domains/settings.mjs');
await import('./domains/storage.mjs');
const {world, refresh, stopWorld, waitJob, discover} = await import('./domains/world.mjs');
await import('./domains/hosting.mjs');
await import('./domains/play.mjs');
await import('./domains/bench.mjs');
await import('./domains/admin.mjs');
await import('./domains/sql.mjs');
await import('./domains/content.mjs');
await import('./domains/updates.mjs');
const diag = await import('./domains/diagnostics.mjs');
await import('./domains/about.mjs');
const {settings} = await import('./domains/settings.mjs');

define('jobs.get', {input: v.object({id: v.string({max: 32})}), quiet: true, run: async ({id}) => getJob(id)});
define('jobs.cancel', {input: v.object({id: v.string({max: 32})}), run: async ({id}) => cancelJob(id)});
define('jobs.list', {input: v.object({running: v.optional(v.bool())}), quiet: true, run: async p => ({jobs: listJobs(p)})});
define('shell.pick', {input: v.object({kind: v.enum(['file', 'folder']), title: v.string({max: 200}), filter: v.optional(v.string({max: 200}))}), timeoutMs: 30 * 60 * 1000, run: async ({kind, title, filter}) => {
  const r = await request(kind === 'file' ? 'dialog.open' : 'dialog.folder', {title, ...(filter ? {filter} : {})});
  return {path: r.path || null};
}});
define('shell.openExternal', {input: v.object({url: v.enum(['https://www.microsoft.com/en-us/useterms', 'https://learn.microsoft.com/sql/sql-server/sql-server-privacy', 'https://developers.cloudflare.com/cloudflare-one/connections/connect-networks/', 'https://github.com/waveforgemp3app-cmyk/Tool/releases'])}), run: async ({url}) => { await request('open.external', {url}); return {opened: true}; }});
// --resume / --setup from Client.exe (the classic launcher's "start the local world now" entries): honoured once per run.
let autostart = process.env.DKCC_AUTOSTART === '1';
const engineVersion = (() => { try { return JSON.parse(fs.readFileSync(path.join(ENGINE, 'package.json'), 'utf8')).version; } catch { return null; } })();
define('app.boot', {input: v.object({}), run: async () => { const a = autostart; autostart = false; return {settings: await settings(), shell: hasShell(), test: process.env.DKCC_TEST === '1', mode: MODE, engineVersion, autostart: a, backendStartMs: Math.round(bootMs), pid: process.pid}; }});
// Installed only: Client.exe opens the original launcher instead of this one while run/classic-launcher.flag exists.
const CLASSIC_FLAG = path.join(ENGINE, 'run', 'classic-launcher.flag');
define('app.classic', {input: v.object({}), quiet: true, run: async () => ({available: INSTALL, enabled: INSTALL && fs.existsSync(CLASSIC_FLAG)})});
define('app.classic.set', {input: v.object({enabled: v.bool()}), run: async ({enabled}) => {
  if (!INSTALL) throw new Error('The classic-launcher switch belongs to an installation; the preview never changes it.');
  if (enabled) { fs.mkdirSync(path.dirname(writable(CLASSIC_FLAG)), {recursive: true}); fs.writeFileSync(CLASSIC_FLAG, 'Client.exe opens the original DK launcher while this file exists. Delete this file to return to DK Command Center.\r\n'); event('info', 'app', 'Client.exe will open the classic launcher from its next start.'); }
  else { fs.rmSync(writable(CLASSIC_FLAG), {force: true}); event('info', 'app', 'Client.exe will open DK Command Center.'); }
  return {available: true, enabled};
}});
define('app.close', {input: v.object({decision: v.enum(['stop-and-close', 'close', 'cancel'])}), timeoutMs: 170000, run: async ({decision}) => {
  if (decision === 'cancel') { if (hasShell()) await request('close.cancel'); return {closing: false}; }
  if (decision === 'stop-and-close' && world.status === 'running' && world.owned) {
    // The Test Bench client belongs to this window: close it and give its session time to end (the engine refuses to
    // stop while a client is connected and drops a closed client within about a minute).
    if (await (await import('./domains/bench.mjs')).closeBenchIfOpen()) {
      const until = Date.now() + 75000;
      while (Date.now() < until) { await refresh({maxAgeMs: 0}).catch(() => {}); const s = world.lastStatus || {}; if (!(Number(s.connectedClients) > 0 || Number(s.realPlayers) > 0)) break; await new Promise(r => setTimeout(r, 1000)); }
    }
    const j = await stopWorld({reason: 'Launcher closed'});
    await waitJob(j.id); // throws (and the window stays open) if clients are still connected or saving failed
  }
  shutdown('window closed');
  if (hasShell()) await request('close.proceed');
  return {closing: true};
}});
define('app.closeState', {input: v.object({}), run: async () => { await refresh({maxAgeMs: 0}).catch(() => {}); return {world: world.status, owned: world.owned, adopted: world.adopted, confirm: (await settings()).confirmClose, jobs: listJobs({running: true}).map(j => j.title)}; }});

const bridge = createBridge({onSessionStart: () => event('info', 'app', 'Launcher page connected.')});
diag.setBridgeStats(bridge.stats);
const port = await bridge.listen();
const bootMs = performance.now() - started;
event('info', 'app', `DK Command Center${INSTALL ? '' : ' Test Preview'} backend ready on 127.0.0.1:${port} in ${Math.round(bootMs)} ms (${shell ? 'window attached' : 'headless'}).`);
if (shell) send('ready', {port, boot: bridge.boot});
else process.stdout.write(JSON.stringify({t: 'ready', port, boot: bridge.boot, headless: true}) + '\n');
discover().catch(() => {});

let closing = false;
function shutdown(reason) {
  if (closing) return; closing = true;
  event('info', 'app', 'Backend shutting down: ' + reason);
  cancelAll(); killOwned(); stopNative();
  // The world (if running) watches this process (DEKARON_LAUNCHER_PID) and saves + stops on its own when we exit.
  setTimeout(() => process.exit(0), 600).unref();
}
let pendingClose = null;
shellEvents.on('close-requested', async () => {
  try {
    const s = await (await import('./core/rpc.mjs')).call('app.closeState', {});
    event('info', 'app', 'Close requested from the window.');
    // Nothing running that a close would affect: close at once. Otherwise the page asks (it polls app.pendingClose).
    if (s.world !== 'running' && !s.jobs.length) { shutdown('window closed'); await request('close.proceed'); return; }
    pendingClose = s; await request('window.front').catch(() => {});
  } catch { shutdown('close fallback'); request('close.proceed').catch(() => {}); }
});
define('app.pendingClose', {input: v.object({}), quiet: true, run: async () => { const p = pendingClose; return {pending: !!p, state: p}; }});
define('app.pendingClose.clear', {input: v.object({}), quiet: true, run: async () => { pendingClose = null; return {ok: true}; }});
shellEvents.on('eof', () => shutdown('window pipe closed'));
process.on('SIGINT', () => shutdown('SIGINT'));
process.on('uncaughtException', e => { event('error', 'app', 'Backend error: ' + e.message, e.stack); });
process.on('unhandledRejection', e => { event('error', 'app', 'Backend promise error: ' + (e?.message || e), e?.stack); });
