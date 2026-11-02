// GATE service (front door). Own thread, does only I/O: answers the HUD ping instantly on the game port (the ping port
// has its own thread: services/gate-ping.mjs),
// and streams every other request (HTTP + the SSE snapshot stream) to Realm's private loopback port unchanged.
// It never parses game payloads and never waits on the world, so a long world tick cannot delay a ping here.
import http from 'node:http';
import { workerData } from 'node:worker_threads';
import { connectWorker } from '../worker-endpoint.mjs';
import { PRIO } from '../bus.mjs';
const { host, port, pingPort, worldPort, statsToken } = workerData;
// Bounded upstream pool: under overload requests queue here (cheap) instead of opening thousands of sockets to Realm.
const agent = new http.Agent({ keepAlive: true, maxSockets: Number(workerData.maxSockets) || 1024, maxFreeSockets: 512, scheduling: 'lifo' });
const pingHeaders = { 'Cache-Control': 'no-store', 'Access-Control-Allow-Origin': '*', 'Timing-Allow-Origin': '*', 'Content-Length': '0', 'X-Dekaron-Ping-Port': String(pingPort) };
const counters = { requests: 0, pings: 0, streams: 0, upstreamErrors: 0, lastUpstreamError: null, open: 0, inFlight: 0, shed: 0 };
// Backpressure: when Realm falls behind, short requests beyond this many in flight get an instant 503 + Retry-After
// instead of queueing until they are stale (a move queued for seconds is useless; the client simply sends the next one).
// Event streams are long-lived and never counted or shed.
const MAX_IN_FLIGHT = Number(workerData.maxInFlight) || 512;
const ep = connectWorker('Gate', {
  'gate.stats': () => ({ ...counters, agentSockets: Object.values(agent.sockets).reduce((n, a) => n + a.length, 0) }),
}, ['gate.*']);
const isPing = url => url === '/api/world/ping' || url.startsWith('/api/world/ping?') || url === '/ping' || url.startsWith('/ping?');
function pong(req, res) { counters.pings++; res.writeHead(req.method === 'GET' || req.method === 'HEAD' ? 204 : 405, pingHeaders); res.end(); }
function proxy(req, res) {
  const stream = String(req.headers.accept || '').includes('text/event-stream');
  if (!stream && counters.inFlight >= MAX_IN_FLIGHT) { counters.shed++; res.writeHead(503, { 'Content-Type': 'application/json; charset=utf-8', 'Cache-Control': 'no-store', 'Retry-After': '1' }); res.end('{"error":"The world server is busy. Try again."}'); return; }
  counters.requests++; counters.open++; if (!stream) counters.inFlight++;
  let done = false; const finish = () => { if (!done) { done = true; counters.open--; if (!stream) counters.inFlight--; } };
  const up = http.request({ host: '127.0.0.1', port: worldPort, method: req.method, path: req.url, headers: req.headers, agent, setHost: false }, upRes => {
    if (String(upRes.headers['content-type'] || '').startsWith('text/event-stream')) counters.streams++;
    res.writeHead(upRes.statusCode, upRes.statusMessage, upRes.rawHeaders);
    res.flushHeaders?.();
    upRes.pipe(res);
    upRes.on('error', () => res.destroy());
  });
  up.on('socket', s => s.setNoDelay(true));
  up.on('error', e => { counters.upstreamErrors++; counters.lastUpstreamError = String(e?.code || e?.message || e); finish(); if (!res.headersSent) { res.writeHead(503, { 'Content-Type': 'application/json; charset=utf-8', 'Cache-Control': 'no-store', 'Retry-After': '2' }); res.end('{"error":"The world server is starting or unavailable."}'); } else res.destroy(); });
  res.on('close', () => { finish(); if (!res.writableFinished) up.destroy(); });
  req.pipe(up);
}
async function pipelineStats(req, res) {
  const remote = String(req.socket.remoteAddress || '').replace(/^::ffff:/i, '');
  if (!['127.0.0.1', '::1'].includes(remote) || req.headers['x-dekaron-pipeline-token'] !== statsToken) { res.writeHead(403); res.end(); return; }
  try { const v = await ep.request('hub.stats', null, { p: PRIO.REALTIME, timeoutMs: 2000 }); res.writeHead(200, { 'Content-Type': 'application/json', 'Cache-Control': 'no-store' }); res.end(JSON.stringify(v)); }
  catch (e) { res.writeHead(503); res.end(JSON.stringify({ error: e.message })); }
}
const front = http.createServer({ noDelay: true, keepAliveTimeout: 65000 }, (req, res) => {
  if (isPing(req.url) && req.headers['sec-fetch-site'] !== 'cross-site') return pong(req, res);
  if (req.url === '/api/pipeline/stats') return void pipelineStats(req, res);
  proxy(req, res);
});
front.headersTimeout = 70000; front.requestTimeout = 0;
front.on('upgrade', (_q, s) => s.destroy());
const listen = (srv, p) => new Promise((resolve, reject) => { srv.once('error', reject); srv.listen(p, host, resolve); });
try {
  await listen(front, port);
  ep.publish('hub.ready', { service: 'Gate', port }, PRIO.REALTIME);
} catch (e) { ep.publish('hub.fatal', { service: 'Gate', error: String(e?.code || e) }, PRIO.REALTIME); }
