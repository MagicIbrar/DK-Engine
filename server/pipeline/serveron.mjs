// ServerOn: starts Hub (the main pipeline) and every service that has real code, all connected to the one bus.
//   Hub thread (this one)  : routes messages only. No game logic, no disk work.
//   Gate (worker)          : public game port + ping port. I/O + instant ping only.
//   Archive (worker)       : all log writing (server/Archive/<Service>-<date>.log).
//   Monitor (worker)       : diagnostics; measures real ping p50/p99/max against Gate from its own thread.
//   Realm (process)        : server.mjs on a private loopback port (world + everything not split out yet:
//                            Keys/Atrium/Link/Herald/Ladder/Bazaar/Ledger/Mind still run inside it, see docs/SERVER-SPLIT-DESIGN.md).
// Usage: run\ServerOn.bat  (or: runtime\node.exe server\pipeline\serveron.mjs). Same env as server.mjs (PORT, DEKARON_HOST...).
import { Worker, MessageChannel } from 'node:worker_threads';
import { fork } from 'node:child_process';
import { monitorEventLoopDelay } from 'node:perf_hooks';
import { randomBytes } from 'node:crypto';
import fs from 'node:fs';
import net from 'node:net';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { createHub, createEndpoint, PRIO } from './bus.mjs';
const HERE = path.dirname(fileURLToPath(import.meta.url));
const ENGINE = path.resolve(HERE, '..', '..');
const PORT = Number(process.env.PORT || 7777);
const HOST = process.env.DEKARON_HOST || '127.0.0.1';
const LOOPBACK = ['127.0.0.1', 'localhost', '::1'].includes(HOST);
const PING_PORT = Number(process.env.DEKARON_PING_PORT) || PORT + 1;
const STATS_TOKEN = randomBytes(24).toString('hex');
const STATE_FILE = path.join(ENGINE, 'server', `pipeline-${PORT}.state`);
const say = m => console.log('[pipeline] ' + m);
const freePort = () => new Promise((resolve, reject) => { const s = net.createServer(); s.once('error', reject); s.listen(0, '127.0.0.1', () => { const p = s.address().port; s.close(() => resolve(p)); }); });
// LAN / relay hosts keep Realm on the public socket (its loopback-only admin checks rely on the real peer address).
const GATEWAY = LOOPBACK && process.env.DEKARON_PIPELINE_GATEWAY !== '0';
const WORLD_PORT = GATEWAY ? Number(process.env.DEKARON_WORLD_PORT) || await freePort() : PORT;
const hub = createHub({ log: say });
const loop = monitorEventLoopDelay({ resolution: 10 }); loop.enable();
const workers = new Map(); let world = null, lastWorldStats = null, stopping = false;

// The hub's own endpoint ("hub.*" requests: stats, readiness).
const hubEp = createEndpoint('Hub', packet => queueMicrotask(() => feedHub(packet)), { handlers: {
  'hub.stats': async () => {
    const ask = (k) => hubEp.request(k, null, { p: PRIO.REALTIME, timeoutMs: 1500 }).catch(e => ({ error: e.message }));
    const [monitor, gateway, logs, gatePing] = await Promise.all([ask('monitor.ping'), GATEWAY ? ask('gate.stats') : null, ask('archive.stats'), GATEWAY ? ask('gateping.stats') : null]);
    const ms = v => +(v / 1e6).toFixed(2);
    return { at: Date.now(), gateway: GATEWAY, ports: { public: PORT, ping: PING_PORT, world: WORLD_PORT }, hubLoop: { p50: ms(loop.percentile(50)), p99: ms(loop.percentile(99)), max: ms(loop.max) },
      pipeline: hub.snapshot(), monitor, gate: gateway, gatePing, archive: logs, realm: lastWorldStats };
  },
  'hub.ready': d => say(`${d.service} ready${d.port ? ' on ' + d.port : ''}${d.pingPort ? ' (ping ' + d.pingPort + ')' : ''}`),
  'hub.fatal': d => { console.error(`[pipeline] ${d.service} failed: ${d.error}`); if (d.service === 'Gate') stop(1); /* GatePing failing is soft: the client falls back to /api/world/ping on Gate */ },
  'stats.realm': d => { lastWorldStats = d; },
} });
const feedHub = hub.attach('Hub', packet => queueMicrotask(() => hubEp.onPacket(packet)));
hubEp.subscribe(['hub.*', 'stats.*']);

function startWorker(name, file, data) {
  const { port1, port2 } = new MessageChannel();
  const w = new Worker(path.join(HERE, 'services', file), { workerData: { ...data, busPort: port2 }, transferList: [port2], name });
  const feed = hub.attach(name, packet => port1.postMessage(packet));
  port1.on('message', feed);
  w.on('error', e => console.error(`[pipeline] ${name} crashed: ${e?.stack || e}`));
  w.on('exit', code => { hub.detach(name); workers.delete(name); if (!stopping) { console.error(`[pipeline] ${name} exited (${code})`); if (name === 'Gate') stop(1); } });
  workers.set(name, w); return w;
}
startWorker('Archive', 'archive.mjs', { dir: path.join(ENGINE, 'server', 'Archive') });
if (GATEWAY) startWorker('GatePing', 'gate-ping.mjs', { host: HOST === 'localhost' ? '127.0.0.1' : HOST, pingPort: PING_PORT });
if (GATEWAY) startWorker('Gate', 'gate.mjs', { host: HOST === 'localhost' ? '127.0.0.1' : HOST, port: PORT, pingPort: PING_PORT, worldPort: WORLD_PORT, statsToken: STATS_TOKEN });
startWorker('Monitor', 'monitor.mjs', { host: HOST, port: PORT, pingPort: GATEWAY ? PING_PORT : PORT });
if (process.env.DK_BEACON !== '0') startWorker('Beacon', 'beacon.mjs', {});   // NET-REALM: Link+Beacon presence directory (Phase B step 3), fed by Realm (server/pipeline/presence-feed.mjs)

const publicUrl = 'http://' + (HOST === '0.0.0.0' ? 'localhost' : HOST) + ':' + PORT + '/';
// DEKARON_PIPELINE_WORLD_SCRIPT (bench only): run another engine script as Realm, e.g. tools/_split-bench/world-host.mjs.
const WORLD_SCRIPT = (() => { const p = path.resolve(ENGINE, process.env.DEKARON_PIPELINE_WORLD_SCRIPT || 'server.mjs'); if (!p.startsWith(ENGINE + path.sep)) throw new Error('World script must be inside the engine.'); return p; })();
world = fork(WORLD_SCRIPT, process.argv.slice(2), {
  cwd: ENGINE, execArgv: process.execArgv, serialization: 'advanced', stdio: ['inherit', 'inherit', 'inherit', 'ipc'],
  env: { ...process.env, PORT: String(WORLD_PORT), DEKARON_HOST: GATEWAY ? '127.0.0.1' : HOST, DEKARON_PIPELINE_CHILD: '1', DEKARON_PIPELINE_HUB_PID: String(process.pid),
    ...(GATEWAY ? { DEKARON_PUBLIC_URL: publicUrl, DEKARON_PUBLIC_PORT: String(PORT), DEKARON_PING_PORT_ACTIVE: String(PING_PORT), DEKARON_PING_WORKER: '0' } : {}) },
});
const feedWorld = hub.attach('Realm', packet => { if (world.connected) world.send(packet); });
world.on('message', feedWorld);
world.on('exit', (code, signal) => { say(`Realm exited (${code ?? signal}); stopping services`); hub.detach('Realm'); world = null; stop(code ?? 0); });
try { fs.writeFileSync(STATE_FILE, JSON.stringify({ pid: process.pid, port: PORT, pingPort: PING_PORT, worldPort: WORLD_PORT, gateway: GATEWAY, statsToken: STATS_TOKEN, startedAt: Date.now() }), { mode: 0o600 }); } catch {}
say(`main pipeline up (hub pid ${process.pid}); game port ${PORT}${GATEWAY ? ` -> Realm 127.0.0.1:${WORLD_PORT}, ping port ${PING_PORT}` : ' (direct, non-loopback host)'}`);

async function stop(code = 0) {
  if (stopping) return; stopping = true;
  if (world) { say('asking Realm to save and stop'); hubEp.publish('ctl.Realm', { op: 'stop' }, PRIO.REALTIME); await new Promise(r => world ? world.once('exit', r) : r()); }
  await hubEp.request('archive.flush', null, { timeoutMs: 2000 }).catch(() => {});
  for (const w of workers.values()) await w.terminate().catch(() => {});
  try { const s = JSON.parse(fs.readFileSync(STATE_FILE, 'utf8')); if (s.pid === process.pid) fs.unlinkSync(STATE_FILE); } catch {}
  process.exit(code);
}
for (const sig of ['SIGINT', 'SIGTERM', 'SIGBREAK']) process.on(sig, () => { stopping ? null : (world ? stop(0) : process.exit(0)); });
