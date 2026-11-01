// Measures this PC's internet upload and download against Cloudflare's public speed-test endpoints
// (speed.cloudflare.com/__down and /__up, the ones its own web speed test uses). Only random bytes go out - nothing about this
// PC, its accounts or the game. The local launcher runs this before starting a new game server;
// a failed test keeps the previous upload budget and never blocks startup.
// usage: node tools/net-speed-test.mjs [--seconds 6] [--base https://speed.cloudflare.com]
//   -> one JSON line: {ok, uploadMbps, downloadMbps, latencyMs, seconds, server} (or {ok:false, error})
import {randomBytes} from 'node:crypto';
import {performance} from 'node:perf_hooks';

const arg = (name, fallback) => { const i = process.argv.indexOf('--' + name); return i > 0 ? process.argv[i + 1] : fallback; };
const SECONDS = Math.min(20, Math.max(2, Number(arg('seconds', 6)) || 6));
const BASE = String(arg('base', 'https://speed.cloudflare.com')).replace(/\/+$/, '');
if (!/^https:\/\/[a-z0-9.-]+(:\d+)?$/i.test(BASE) && !/^http:\/\/(127\.0\.0\.1|localhost)(:\d+)?$/i.test(BASE)) { console.log(JSON.stringify({ok: false, error: 'The speed test server must be an HTTPS origin.'})); process.exit(1); }
const STREAMS = 4, UPLOAD_CHUNK = 2 * 1024 * 1024, DOWNLOAD_CHUNK = 25 * 1000 * 1000;

async function latency() {
  const times = [];
  for (let i = 0; i < 5; i++) {
    const t = performance.now(), r = await fetch(`${BASE}/__down?bytes=0`, {cache: 'no-store', signal: AbortSignal.timeout(5000)}); await r.arrayBuffer();
    if (!r.ok) throw new Error(`speed test server answered ${r.status}`);
    times.push(performance.now() - t);
  }
  times.sort((a, b) => a - b); return times[2];
}
/** Run `worker(signal, add)` on STREAMS parallel loops for `seconds`; bytes counted as they complete. Returns megabits per second. */
async function measure(seconds, worker) {
  const stop = new AbortController(), began = performance.now(); let bytes = 0;
  const timer = setTimeout(() => stop.abort(), seconds * 1000);
  const add = n => { bytes += n; };
  await Promise.all(Array.from({length: STREAMS}, async () => { while (!stop.signal.aborted) { try { await worker(stop.signal, add); } catch (error) { if (!stop.signal.aborted) throw error; } } }));
  clearTimeout(timer);
  const elapsed = (performance.now() - began) / 1000;
  return bytes * 8 / 1e6 / elapsed;
}
try {
  const latencyMs = await latency();
  const downloadMbps = await measure(SECONDS / 2, async (signal, add) => {
    const r = await fetch(`${BASE}/__down?bytes=${DOWNLOAD_CHUNK}`, {cache: 'no-store', signal});
    if (!r.ok) throw new Error(`download answered ${r.status}`);
    for await (const chunk of r.body) add(chunk.length);   // partial chunks count too
  });
  const payload = randomBytes(UPLOAD_CHUNK);
  const uploadMbps = await measure(SECONDS / 2, async (signal, add) => {
    const r = await fetch(`${BASE}/__up`, {method: 'POST', body: payload, headers: {'Content-Type': 'application/octet-stream'}, signal});
    await r.arrayBuffer();
    if (!r.ok) throw new Error(`upload answered ${r.status}`);
    add(payload.length);   // only completed uploads count (the server received them)
  });
  console.log(JSON.stringify({ok: true, uploadMbps: Number(uploadMbps.toFixed(1)), downloadMbps: Number(downloadMbps.toFixed(1)), latencyMs: Math.round(latencyMs), seconds: SECONDS, server: new URL(BASE).host}));
  process.exit(0);
} catch (error) {
  console.log(JSON.stringify({ok: false, error: `The internet test could not finish (${error?.message || error}). Type your upload speed instead.`}));
  process.exit(1);
}
