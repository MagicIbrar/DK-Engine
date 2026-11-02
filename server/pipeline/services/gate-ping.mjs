// GATE PING lane: the dedicated ping port on its own thread. Nothing else runs here, so neither a long world tick
// nor Gate's proxy/SSE traffic can delay a pong. Same contract as /api/world/ping: 204, no-store, CORS, X-Dekaron-Ping-Port.
// Folds in the old server/ping-worker.mjs role under ServerOn (server.mjs alone still starts ping-worker itself).
import http from 'node:http';
import { workerData } from 'node:worker_threads';
import { connectWorker } from '../worker-endpoint.mjs';
import { PRIO } from '../bus.mjs';
const { host, pingPort } = workerData;
const headers = { 'Cache-Control': 'no-store', 'Access-Control-Allow-Origin': '*', 'Timing-Allow-Origin': '*', 'Content-Length': '0', 'X-Dekaron-Ping-Port': String(pingPort) };
let pings = 0;
const ep = connectWorker('GatePing', { 'gateping.stats': () => ({ pings }) }, ['gateping.*']);
const isPing = url => url === '/api/world/ping' || url.startsWith('/api/world/ping?') || url === '/ping' || url.startsWith('/ping?');
const srv = http.createServer({ noDelay: true, keepAliveTimeout: 65000 }, (req, res) => {
  if (!isPing(req.url)) { res.writeHead(404, headers); res.end(); return; }
  pings++; res.writeHead(req.method === 'GET' || req.method === 'HEAD' ? 204 : 405, headers); res.end();
});
srv.headersTimeout = 10000; srv.requestTimeout = 10000; srv.on('upgrade', (_q, s) => s.destroy());
srv.once('error', e => ep.publish('hub.fatal', { service: 'GatePing', error: String(e?.code || e) }, PRIO.REALTIME));
srv.listen(pingPort, host, () => ep.publish('hub.ready', { service: 'GatePing', pingPort }, PRIO.REALTIME));
