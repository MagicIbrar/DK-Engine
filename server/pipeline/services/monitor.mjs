// MONITOR service: measures what a player would see. Every `everyMs` it times a real HTTP ping to Gate (game port) and
// to the dedicated ping port over keep-alive sockets, from its own thread. Rolling p50/p99/max over the last window.
import http from 'node:http';
import { performance } from 'node:perf_hooks';
import { workerData } from 'node:worker_threads';
import { connectWorker } from '../worker-endpoint.mjs';
const { host, port, pingPort, everyMs = 250, window = 1200 } = workerData;
const agent = new http.Agent({ keepAlive: true, maxSockets: 2 });
const series = { gateway: [], pingPort: [] };
const probe = p => new Promise(resolve => { const t0 = performance.now(); const r = http.get({ host: host === '0.0.0.0' ? '127.0.0.1' : host, port: p, path: '/api/world/ping', agent }, res => { res.resume(); res.on('end', () => resolve(res.statusCode === 204 ? performance.now() - t0 : null)); }); r.setTimeout(5000, () => { r.destroy(); resolve(null); }); r.on('error', () => resolve(null)); });
const push = (list, v) => { if (v !== null) { list.push(v); if (list.length > window) list.shift(); } };
const summary = list => { if (!list.length) return null; const s = [...list].sort((a, b) => a - b), q = f => +s[Math.min(s.length - 1, Math.floor(s.length * f))].toFixed(2); return { n: s.length, p50: q(.5), p99: q(.99), max: +s.at(-1).toFixed(2) }; };
setInterval(async () => { push(series.gateway, await probe(port)); push(series.pingPort, await probe(pingPort)); }, everyMs);
connectWorker('Monitor', {
  'monitor.ping': () => ({ gate: summary(series.gateway), pingPort: summary(series.pingPort) }),
  'monitor.reset': () => { series.gateway.length = 0; series.pingPort.length = 0; return true; },
}, ['monitor.*']);
