// PING WORKER: answers the HUD ping on its own thread + port, so a long world tick on the main event loop cannot delay the pong.
// Pure network round trip: no auth, no body, no world access. Fails soft: the client falls back to /api/world/ping.
import { Worker, isMainThread, parentPort, workerData } from 'node:worker_threads';
import http from 'node:http';
if (!isMainThread && workerData?.pingWorker) {
  const headers = { 'Cache-Control': 'no-store', 'Access-Control-Allow-Origin': '*', 'Timing-Allow-Origin': '*', 'Content-Length': '0' };
  const srv = http.createServer({ noDelay: true, keepAliveTimeout: 65000 }, (req, res) => {
    if (req.method !== 'GET' && req.method !== 'HEAD') { res.writeHead(405, headers); res.end(); return; }
    res.writeHead(req.url?.startsWith('/ping') ? 204 : 404, headers); res.end();
  });
  srv.headersTimeout = 10000; srv.requestTimeout = 10000; srv.on('upgrade', (_q, s) => s.destroy());
  srv.once('error', e => parentPort.postMessage({ ok: false, error: String(e?.code || e) }));
  srv.listen(workerData.port, workerData.host, () => parentPort.postMessage({ ok: true, port: srv.address().port }));
}
export function startPingWorker({ host, port }) {
  return new Promise(resolve => {
    let w; try { w = new Worker(new URL(import.meta.url), { workerData: { pingWorker: true, host, port } }); } catch (e) { resolve({ ok: false, error: String(e) }); return; }
    w.unref(); w.once('error', e => resolve({ ok: false, error: String(e) }));
    w.once('message', m => { if (m.ok) { process.env.DEKARON_PING_PORT_ACTIVE = String(m.port); superviseWorker(w, host, m.port); } else w.terminate(); resolve(m); });
  });
}
// STABILITY: a ping worker that dies is started again on the same port (at most 5 times in 5 minutes); before, the HUD lost
// its fast pong for the rest of the session. While it is down or given up, clients fall back to /api/world/ping.
const workerRestarts = [];
function superviseWorker(w, host, port) {
  w.on('error', e => { try { console.error('[ping-worker] error:', e?.message || e); } catch {} });
  w.once('exit', code => {
    const now = Date.now(); while (workerRestarts.length && now - workerRestarts[0] > 300000) workerRestarts.shift();
    if (workerRestarts.length >= 5) { delete process.env.DEKARON_PING_PORT_ACTIVE; console.error(`[ping-worker] exited (${code}) too often; HUD ping uses /api/world/ping`); return; }
    workerRestarts.push(now); console.error(`[ping-worker] exited (${code}); restarting`);
    setTimeout(() => { startPingWorker({ host, port }).then(r => { if (!r.ok) { delete process.env.DEKARON_PING_PORT_ACTIVE; console.error('[ping-worker] restart failed:', r.error); } }); }, 1000).unref();
  });
}
