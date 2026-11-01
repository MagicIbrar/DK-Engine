// Test Bench: a real game client embedded in the launcher (preview-owned WebView2 view, own profile), signed in as the
// sandbox world's local admin, plus the action/file watcher fed by that view's DevTools protocol events and a
// filesystem watcher on the sandbox. Only the sandbox world can be shown; Main is never involved.
import path from 'node:path';
import {PROFILE, EVIDENCE} from '../core/paths.mjs';
import {define, v} from '../core/rpc.mjs';
import {startJob} from '../core/jobs.mjs';
import {event} from '../core/events.mjs';
import {request, hasShell, shellEvents} from '../core/shell.mjs';
import {UserError, redact, clip} from '../core/util.mjs';
import {prepareOwner, ownerTicketUrl} from './play.mjs';

const bench = {open: false, watching: false, account: null, origin: null, openedAt: null, closedAt: null};
const ring = []; let seq = 0; const pending = new Map();
const counts = {asset: 0, api: 0, console: 0, error: 0, nav: 0};
function push(entry) { entry.seq = ++seq; entry.at = entry.at || Date.now(); ring.push(entry); if (ring.length > 4000) ring.splice(0, ring.length - 4000); counts[entry.kind] = (counts[entry.kind] || 0) + 1; return entry; }
function fileFor(url) {
  try {
    const u = new URL(url); if (bench.origin && u.origin !== bench.origin) return null;
    const p = decodeURIComponent(u.pathname);
    if (p.startsWith('/data/')) return {root: 'prepared', rel: 'data/' + p.slice(6)};
    if (p.startsWith('/gamedata/')) return {root: 'prepared', rel: 'gamedata/' + p.slice(10)};
    if (p.startsWith('/sound/')) return {root: 'prepared', rel: 'data/sound/' + p.slice(7)};
    if (/^\/(src|vendor|site|web)\//.test(p) || /^\/[a-z-]+\.html$/.test(p)) return {root: 'engine', rel: p.slice(1)};
  } catch {}
  return null;
}
function summarizeBody(text) {
  if (!text) return null;
  try { const j = JSON.parse(text); const walk = (o, d = 0) => { if (d > 3 || !o || typeof o !== 'object') return o; const out = Array.isArray(o) ? [] : {}; for (const [k, val] of Object.entries(o)) out[k] = /pass|token|secret|ticket|cookie|invite|digest|salt/i.test(k) ? '<redacted>' : walk(val, d + 1); return out; }; return clip(JSON.stringify(walk(j)), 400); }
  catch { return clip(redact(text), 200); }
}
// A refused world action: fetch the server's reply so the feed says why (for example a cast without a valid skill).
let explaining = 0;
async function explainFailure(requestId, e) {
  if (explaining > 4) return; explaining++;
  try {
    const r = await request('bench.responseBody', {requestId}, 5000); const body = JSON.parse(r.json || '{}');
    const text = body.base64Encoded ? '(binary reply)' : summarizeBody(body.body || '');
    e.reply = text;
    const type = /"type":"([^"]+)"/.exec(e.body || '')?.[1];
    push({kind: 'error', level: 'action', text: `Action ${type ? '"' + type + '" ' : ''}refused (${e.status}): ${text || 'no reply text'}`, source: e.url.replace(/^https?:\/\/[^/]+/, '').split('?')[0]});
  } catch {} finally { explaining--; }
}
shellEvents.on('bench.cdp', m => {
  let p; try { p = JSON.parse(m.params); } catch { return; }
  switch (m.method) {
    case 'Network.requestWillBeSent': {
      const url = p.request?.url || ''; if (url.startsWith('data:') || url.startsWith('blob:')) return;
      const isApi = /\/api\//.test(url), file = fileFor(url);
      const e = {kind: isApi ? 'api' : 'asset', url: redact(url.split('#')[0]), method: p.request?.method, type: p.type, file, start: p.timestamp, state: 'pending', ...(isApi && p.request?.postData ? {body: summarizeBody(p.request.postData)} : {})};
      pending.set(p.requestId, push(e)); if (pending.size > 3000) pending.delete(pending.keys().next().value); break;
    }
    case 'Network.responseReceived': { const e = pending.get(p.requestId); if (e) { e.status = p.response?.status; e.mime = p.response?.mimeType; e.cache = p.response?.fromDiskCache ? 'disk' : p.response?.fromServiceWorker ? 'worker' : p.response?.fromPrefetchCache ? 'prefetch' : 'network'; } break; }
    case 'Network.loadingFinished': { const e = pending.get(p.requestId); if (e) { e.state = 'done'; e.bytes = p.encodedDataLength; e.ms = e.start ? Math.round((p.timestamp - e.start) * 10000) / 10 : null; pending.delete(p.requestId); if (e.kind === 'api' && e.status >= 400 && bench.watching) explainFailure(p.requestId, e); } break; }
    case 'Network.loadingFailed': { const e = pending.get(p.requestId); if (e) { e.state = p.canceled ? 'cancelled' : 'failed'; e.error = clip(p.errorText, 120); pending.delete(p.requestId); if (!p.canceled) push({kind: 'error', text: `Load failed: ${e.url} (${e.error})`, file: e.file}); } break; }
    case 'Runtime.consoleAPICalled': { if (!['error', 'warning', 'warn', 'assert'].includes(p.type) && counts.console > 2000) return; const text = (p.args || []).slice(0, 4).map(a => a.value !== undefined ? String(a.value) : a.description || a.type).join(' '); push({kind: p.type === 'error' || p.type === 'assert' ? 'error' : 'console', level: p.type, text: clip(redact(text), 600), source: p.stackTrace?.callFrames?.[0] ? `${p.stackTrace.callFrames[0].url.split('/').slice(-2).join('/')}:${p.stackTrace.callFrames[0].lineNumber + 1}` : null}); break; }
    case 'Runtime.exceptionThrown': { const d = p.exceptionDetails || {}; push({kind: 'error', level: 'exception', text: clip(redact(d.exception?.description || d.text || 'Uncaught exception'), 1200), source: d.url ? `${d.url.split('/').slice(-2).join('/')}:${(d.lineNumber || 0) + 1}` : null}); break; }
    case 'Log.entryAdded': { const e = p.entry || {}; push({kind: e.level === 'error' ? 'error' : 'console', level: e.level, text: clip(redact(e.text), 600), source: e.url ? e.url.split('/').slice(-2).join('/') : null}); break; }
    case 'Page.frameNavigated': { if (!p.frame?.parentId) push({kind: 'nav', text: 'Page: ' + redact((p.frame?.url || '').split('#')[0])}); break; }
  }
});
shellEvents.on('bench.failed', m => { push({kind: 'error', text: `Embedded client process failed (kind ${m.kind}). Use Reload.`}); event('error', 'play', 'Test Bench client process failed.'); });

async function rect(p) { return {x: p.x, y: p.y, width: p.width, height: p.height, visible: p.visible !== false, ...(p.clipWidth !== undefined ? {clipX: p.clipX, clipY: p.clipY, clipWidth: p.clipWidth, clipHeight: p.clipHeight} : {})}; }
const clipFields = {clipX: v.optional(v.number({min: -20000, max: 20000})), clipY: v.optional(v.number({min: -20000, max: 20000})), clipWidth: v.optional(v.number({min: 0, max: 20000})), clipHeight: v.optional(v.number({min: 0, max: 20000}))};
/** Closing the launcher closes its own embedded client first; returns true when one was open. */
export async function closeBenchIfOpen() {
  if (!bench.open) return false;
  try { if (hasShell()) await request('bench.close'); } catch {}
  Object.assign(bench, {open: false, watching: false, closedAt: Date.now()}); push({kind: 'nav', text: 'Test Bench closed because the launcher is closing.'});
  return true;
}
define('bench.status', {input: v.object({}), quiet: true, run: async () => ({...bench, shell: hasShell(), counts})});
define('bench.open', {input: v.object({x: v.number({min: -20000, max: 20000}), y: v.number({min: -20000, max: 20000}), width: v.number({min: 0, max: 20000}), height: v.number({min: 0, max: 20000}), ...clipFields}), run: async p => {
  if (!hasShell()) throw new UserError('The Test Bench needs the DK Command Center window (it embeds a real game view).', 409);
  const {world, refresh} = await import('./world.mjs'); await refresh({maxAgeMs: 0});
  if (world.status !== 'running') throw new UserError('Start the sandbox world first.', 409);
  if (world.mode !== 'local' || !world.lastStatus?.ownerAvailable) throw new UserError('The Test Bench signs in as the local admin, which is available only on your local sandbox world.', 409);
  return startJob({kind: 'bench.open', key: 'bench.open', area: 'play', title: 'Open Test Bench client', run: async ctx => {
    // Reopening right after closing: the world keeps the admin session for about a minute. When that session was this
    // bench's own, wait for it instead of failing; any other signed-in admin client still stops the open.
    for (let waited = 0; ; waited += 3000) {
      try { await prepareOwner(ctx); break; }
      catch (e) {
        const own = bench.closedAt && Date.now() - bench.closedAt < 150000;
        if (!/already connected/i.test(e.message) || !own || waited > 90000) throw e;
        if (!waited) ctx.phase('Wait for previous session', 'The world is releasing the previous Test Bench session (about a minute)');
        await new Promise(r => setTimeout(r, 3000)); ctx.throwIfCancelled();
      }
    }
    ctx.phase('Sign in', 'Owner handoff ticket for the embedded view');
    const url = new URL(await ownerTicketUrl(world.url)); url.search = 'client=desktop';
    bench.origin = new URL(world.url).origin;
    ctx.phase('Open view', 'Embedding the game in this window');
    await request('bench.open', {url: url.href, ...(await rect(p))}, 30000);
    Object.assign(bench, {open: true, account: 'admin', openedAt: Date.now()});
    push({kind: 'nav', text: 'Test Bench opened as local admin on ' + bench.origin});
    event('ok', 'play', 'Test Bench client opened (local admin, sandbox world).');
    return {opened: true};
  }});
}});
define('bench.bounds', {input: v.object({x: v.number({min: -20000, max: 20000}), y: v.number({min: -20000, max: 20000}), width: v.number({min: 0, max: 20000}), height: v.number({min: 0, max: 20000}), visible: v.bool(), ...clipFields}), quiet: true, run: async p => { if (!bench.open) return {open: false}; await request('bench.bounds', await rect(p)); return {open: true}; }});
define('bench.close', {input: v.object({}), run: async () => { if (hasShell()) await request('bench.close'); Object.assign(bench, {open: false, watching: false, closedAt: Date.now()}); push({kind: 'nav', text: 'Test Bench closed.'}); return {open: false}; }});
const needOpen = () => { if (!bench.open) throw new UserError('Open the embedded client first.', 409); };
define('bench.reload', {input: v.object({}), run: async () => { needOpen(); await request('bench.reload'); push({kind: 'nav', text: 'Reloaded.'}); return {ok: true}; }});
define('bench.devtools', {input: v.object({}), run: async () => { needOpen(); await request('bench.devtools'); return {ok: true}; }});
define('bench.screenshot', {input: v.object({}), run: async () => { needOpen(); const file = path.join(EVIDENCE, 'bench', `bench-${new Date().toISOString().replace(/[:.]/g, '-')}.png`); const r = await request('bench.screenshot', {file}, 20000); event('info', 'play', 'Test Bench screenshot saved.'); return {file: r.file}; }});
define('bench.watch', {input: v.object({enabled: v.bool()}), run: async ({enabled}) => {
  const diag = await import('../core/rpc.mjs');
  if (enabled) { if (!bench.open) throw new UserError('Open the embedded client first.', 409); await request('bench.watch'); bench.watching = true; await diag.call('watch.fs.start', {}); push({kind: 'nav', text: 'Watcher on: assets, actions, console and sandbox file writes.'}); }
  else { bench.watching = false; await diag.call('watch.fs.stop', {}); push({kind: 'nav', text: 'Watcher paused (DevTools events stop being shown).'}); }
  return {watching: bench.watching};
}});
define('bench.events', {input: v.object({after: v.optional(v.int({min: 0, max: 1e12})), limit: v.optional(v.int({min: 1, max: 1000}))}), quiet: true, run: async ({after = 0, limit = 400}) => ({events: bench.watching || !after ? ring.filter(e => e.seq > after).slice(-limit) : [], counts, watching: bench.watching, open: bench.open, last: seq})});
// Test mode only: drive the embedded client like a player (mouse, keys, text) and read its page state.
if (process.env.DKCC_TEST === '1') define('bench.test.cdp', {input: v.object({method: v.enum(['Input.dispatchMouseEvent', 'Input.dispatchKeyEvent', 'Input.insertText', 'Runtime.evaluate']), params: v.any()}), timeoutMs: 30000, run: async ({method, params}) => { const r = await request('bench.test.cdp', {method, params: JSON.stringify(params || {})}, 20000); try { return JSON.parse(r.json || '{}'); } catch { return {raw: r.json}; } }});
define('bench.clear', {input: v.object({}), run: async () => { ring.length = 0; for (const k of Object.keys(counts)) counts[k] = 0; return {cleared: true}; }});
