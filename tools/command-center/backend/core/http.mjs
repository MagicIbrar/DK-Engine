// Loopback bridge between the embedded page and the backend.
// - Listens on 127.0.0.1 only (ephemeral port); the Host header must match exactly (DNS-rebinding guard).
// - The window injects a one-time boot code before page scripts run; the page trades it for an HttpOnly, SameSite=Strict
//   session cookie. The code never appears in a URL or log, and expires after first use or 60 s.
// - Every API call needs that cookie AND the X-DKCC header (forces a CORS preflight that this server never grants).
import http from 'node:http';
import fs from 'node:fs';
import path from 'node:path';
import {randomBytes, timingSafeEqual, createHash} from 'node:crypto';
import {UI} from './paths.mjs';
import {call, isQuiet} from './rpc.mjs';
import {event} from './events.mjs';
import {redact} from './util.mjs';

const TYPES = {'.html': 'text/html; charset=utf-8', '.js': 'text/javascript; charset=utf-8', '.mjs': 'text/javascript; charset=utf-8', '.css': 'text/css; charset=utf-8', '.svg': 'image/svg+xml', '.png': 'image/png', '.ico': 'image/x-icon', '.json': 'application/json; charset=utf-8', '.woff2': 'font/woff2', '.txt': 'text/plain; charset=utf-8'};
const CSP = "default-src 'none'; script-src 'self'; style-src 'self'; img-src 'self' data: blob:; font-src 'self'; connect-src 'self'; base-uri 'none'; form-action 'none'; frame-ancestors 'none'; manifest-src 'none'; worker-src 'none'; media-src 'none'; object-src 'none'";
const SECURITY = {'Content-Security-Policy': CSP, 'X-Content-Type-Options': 'nosniff', 'Referrer-Policy': 'no-referrer', 'Cross-Origin-Opener-Policy': 'same-origin', 'Cross-Origin-Resource-Policy': 'same-origin', 'Permissions-Policy': 'camera=(), microphone=(), geolocation=(), usb=(), serial=(), hid=(), payment=()'};

export function createBridge({onSessionStart} = {}) {
  let port = 0, boot = randomBytes(24).toString('hex'), bootUntil = Date.now() + 60000, bootUsed = false;
  const session = randomBytes(32).toString('hex'), cookieName = 'dkcc_session';
  const stats = {requests: 0, apiCalls: 0, rejected: 0, slowest: 0, byMethod: {}};
  const etags = new Map();
  const same = (a, b) => { const x = Buffer.from(String(a)), y = Buffer.from(String(b)); return x.length === y.length && timingSafeEqual(x, y); };
  const reply = (res, status, body, headers = {}) => { const text = JSON.stringify(body); res.writeHead(status, {'Content-Type': 'application/json; charset=utf-8', 'Cache-Control': 'no-store', ...SECURITY, ...headers}); res.end(text); };
  const cookie = req => { const m = String(req.headers.cookie || '').split(';').map(s => s.trim()).find(s => s.startsWith(cookieName + '=')); return m ? m.slice(cookieName.length + 1) : ''; };
  async function body(req, limit = 256 * 1024) {
    const chunks = []; let size = 0;
    for await (const c of req) { size += c.length; if (size > limit) throw Object.assign(new Error('Request too large.'), {status: 413}); chunks.push(c); }
    const text = Buffer.concat(chunks).toString('utf8'); if (!text) return {};
    try { return JSON.parse(text); } catch { throw Object.assign(new Error('Expected JSON.'), {status: 400}); }
  }
  function staticFile(req, res, pathname) {
    let rel = pathname === '/' ? 'index.html' : decodeURIComponent(pathname.slice(1));
    if (rel.includes('\0') || rel.includes('..')) { res.writeHead(400, SECURITY); return res.end(); }
    const file = path.resolve(UI, rel);
    if (!file.toLowerCase().startsWith(UI.toLowerCase() + path.sep)) { res.writeHead(404, SECURITY); return res.end(); }
    fs.stat(file, (err, st) => {
      if (err || !st.isFile()) { res.writeHead(404, {...SECURITY, 'Content-Type': 'text/plain'}); return res.end('Not found'); }
      const key = file + ':' + st.mtimeMs + ':' + st.size;
      let tag = etags.get(file); if (!tag || tag.key !== key) { tag = {key, value: '"' + createHash('sha1').update(key).digest('hex').slice(0, 16) + '"'}; etags.set(file, tag); }
      const headers = {...SECURITY, 'Content-Type': TYPES[path.extname(file).toLowerCase()] || 'application/octet-stream', 'ETag': tag.value, 'Cache-Control': rel === 'index.html' ? 'no-cache' : 'no-cache'};
      if (req.headers['if-none-match'] === tag.value) { res.writeHead(304, headers); return res.end(); }
      res.writeHead(200, {...headers, 'Content-Length': st.size});
      if (req.method === 'HEAD') return res.end();
      fs.createReadStream(file).pipe(res);
    });
  }
  const server = http.createServer({keepAliveTimeout: 5000}, (req, res) => {
    stats.requests++;
    void (async () => {
      const expectedHost = `127.0.0.1:${port}`;
      if (req.headers.host !== expectedHost) { stats.rejected++; res.writeHead(421, SECURITY); return res.end(); }
      const url = new URL(req.url, `http://${expectedHost}`), p = url.pathname;
      // Test mode only (DKCC_TEST=1, set by automated tests or `--test`): trade the single-use boot code for the session
      // cookie through a navigation, for browsers that cannot inject a script before the page runs.
      if (p === '/__test/boot' && process.env.DKCC_TEST === '1' && req.method === 'GET') {
        const code = url.searchParams.get('code') || '';
        if (bootUsed || Date.now() > bootUntil || !same(code, boot)) { res.writeHead(401, SECURITY); return res.end('expired'); }
        bootUsed = true; boot = randomBytes(24).toString('hex'); onSessionStart?.();
        res.writeHead(303, {...SECURITY, 'Set-Cookie': `${cookieName}=${session}; HttpOnly; SameSite=Strict; Path=/`, Location: '/' + (url.searchParams.get('hash') ? '#' + url.searchParams.get('hash') : '')}); return res.end();
      }
      if (!p.startsWith('/api/')) { if (!['GET', 'HEAD'].includes(req.method)) { res.writeHead(405, SECURITY); return res.end(); } return staticFile(req, res, p); }
      const origin = req.headers.origin;
      if ((origin !== undefined && origin !== `http://${expectedHost}`) || req.headers['sec-fetch-site'] === 'cross-site' || req.headers['sec-fetch-site'] === 'same-site') { stats.rejected++; return reply(res, 403, {error: 'Cross-origin requests are refused.'}); }
      if (req.method !== 'POST' || req.headers['x-dkcc'] !== '1' || !/^application\/json/.test(req.headers['content-type'] || '')) { stats.rejected++; return reply(res, 400, {error: 'Use the DK Command Center window.'}); }
      if (p === '/api/session') {
        const input = await body(req, 1024);
        if (bootUsed || Date.now() > bootUntil || typeof input.code !== 'string' || !same(input.code, boot)) {
          if (same(cookie(req), session)) return reply(res, 200, {ok: true, resumed: true});
          stats.rejected++; event('warn', 'app', 'Refused a page session without a valid boot code'); return reply(res, 401, {error: 'Open DK Command Center from its own window.'});
        }
        bootUsed = true; boot = randomBytes(24).toString('hex');
        onSessionStart?.();
        return reply(res, 200, {ok: true}, {'Set-Cookie': `${cookieName}=${session}; HttpOnly; SameSite=Strict; Path=/`});
      }
      if (!same(cookie(req), session)) { stats.rejected++; return reply(res, 401, {error: 'Session expired. Reopen DK Command Center.', sessionExpired: true}); }
      if (p !== '/api/call') return reply(res, 404, {error: 'Unknown endpoint.'});
      const input = await body(req);
      if (typeof input.method !== 'string' || input.method.length > 80) return reply(res, 400, {error: 'Missing operation.'});
      stats.apiCalls++; const started = performance.now();
      try {
        const result = await call(input.method, input.params);
        const ms = performance.now() - started; stats.slowest = Math.max(stats.slowest, ms);
        const m = stats.byMethod[input.method] ||= {n: 0, totalMs: 0, maxMs: 0}; m.n++; m.totalMs += ms; m.maxMs = Math.max(m.maxMs, ms);
        reply(res, 200, {ok: true, result, ms: Math.round(ms * 10) / 10});
      } catch (error) {
        let status = error.status && error.status >= 400 && error.status < 600 ? error.status : 500;
        if (status === 408) status = 409; // Chromium re-sends a POST answered with 408, which would repeat the operation
        if (status >= 500 && !isQuiet(input.method)) event('error', 'app', `${input.method} failed`, error.stack || error.message);
        reply(res, status, {ok: false, error: redact(error.message || 'Operation failed.'), field: error.field, busyJob: error.busyJob, code: error.code});
      }
    })().catch(error => { try { reply(res, error.status || 500, {ok: false, error: redact(error.message)}); } catch {} });
  });
  server.headersTimeout = 10000; server.requestTimeout = 120000;
  return {
    server, stats,
    listen() { return new Promise((resolve, reject) => { server.once('error', reject); server.listen(0, '127.0.0.1', () => { port = server.address().port; resolve(port); }); }); },
    get port() { return port; }, get boot() { return boot; },
    testBoot() { return boot; },
  };
}
