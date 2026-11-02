// Sign-in, account creation, saved accounts and every existing way to open the game
// (DX11 window, DX11 fullscreen, Desktop App, Web Browser), ported from client-auth.ps1 / client-dashboard.ps1 /
// client-asset-warm.ps1 with the same credential rules: passwords stay in request bodies, never URLs, logs or arguments.
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import {randomBytes} from 'node:crypto';
import {ENGINE, NODE, PROFILE, writable, inside} from '../core/paths.mjs';
import {define, v, ACCOUNT_ID} from '../core/rpc.mjs';
import {startJob} from '../core/jobs.mjs';
import {event} from '../core/events.mjs';
import {UserError, readJson, writeJson, sleep, clip, exists} from '../core/util.mjs';
import {spawnOutside, runTool, alive} from '../core/proc.mjs';
import {native, protect, unprotect} from '../core/native.mjs';
import {request, hasShell} from '../core/shell.mjs';
import {settings, gameGuardLaunchEnv, frameRateLaunch} from './settings.mjs';
import {friendsUrl, joinCheck} from './hosting.mjs';

const SAVED = path.join(ENGINE, 'server', 'saved-logins.json');
const games = new Map(); // pid -> {pid, target, account, server, startedAt, profile, closeRequested}

// ---- minimal cookie jar per sign-in attempt
function jar() {
  const cookies = new Map();
  return {
    header: () => [...cookies].map(([k, val]) => `${k}=${val}`).join('; '),
    take(res) { for (const c of res.headers.getSetCookie?.() || []) { const [pair] = c.split(';'); const i = pair.indexOf('='); if (i > 0) { const k = pair.slice(0, i).trim(), val = pair.slice(i + 1).trim(); if (/max-age=0/i.test(c) || val === '') cookies.delete(k); else cookies.set(k, val); } } },
  };
}
async function call(base, route, {body, j, timeoutMs = 15000, headers = {}} = {}) {
  const u = new URL(route, base); const ctrl = new AbortController(); const t = setTimeout(() => ctrl.abort(), timeoutMs);
  const api = new URL(u.href); if (api.hostname === 'localhost') api.hostname = '127.0.0.1';
  try {
    const res = await fetch(api, {method: body === undefined ? 'GET' : 'POST', redirect: 'manual', signal: ctrl.signal, headers: {...(body !== undefined ? {'Content-Type': 'application/json; charset=utf-8'} : {}), ...(j ? {Cookie: j.header()} : {}), ...headers}, body: body === undefined ? undefined : JSON.stringify(body)});
    j?.take(res);
    const text = await res.text(); let data = null; try { data = text ? JSON.parse(text) : null; } catch {}
    if (res.status >= 300 && res.status < 400) throw new UserError('The server redirected the request; redirects are not accepted.');
    if (!res.ok) throw new UserError(data?.error || `The account request failed (HTTP ${res.status}).`, res.status === 401 || res.status === 403 || res.status === 409 || res.status === 429 ? res.status : 400);
    return data;
  } catch (e) {
    if (e instanceof UserError) throw e;
    throw new UserError(ctrl.signal.aborted ? 'The account request timed out. Please try again.' : 'The account server could not be reached. Check the address and try again.', 503);
  } finally { clearTimeout(t); }
}
const origin = url => new URL(url).origin.toLowerCase();

// ---- saved accounts (server/saved-logins.json, identical format to the existing launcher; tokens are DPAPI blobs bound to the server origin)
async function savedRows() { const rows = await readJson(SAVED, [], 65536); return Array.isArray(rows) ? rows : []; }
export async function savedAccounts(url) {
  const o = origin(url); return (await savedRows()).filter(r => r.server === o && ACCOUNT_ID.test(r.id || '') && r.id !== 'admin').map(r => ({id: r.id, hasToken: typeof r.token === 'string' && r.token.length >= 20}));
}
async function savedToken(url, id) { const o = origin(url); const row = (await savedRows()).find(r => r.server === o && r.id === id); if (!row?.token) return ''; try { const t = await unprotect('dekaron-saved-login:' + o, row.token); return /^[a-f0-9]{64}$/.test(t) ? t : ''; } catch { return ''; } }
async function saveAccount(url, id, {remove = false, token = '', keepToken = true} = {}) {
  if (!ACCOUNT_ID.test(id) || id === 'admin') return;
  const o = origin(url); let kept = '';
  const rows = (await savedRows()).filter(r => { if (r.server === o && r.id === id) { kept = r.token || ''; return false; } return ACCOUNT_ID.test(r.id || '') && r.id !== 'admin'; });
  if (!remove) { const e = {server: o, id}; if (token) e.token = await protect('dekaron-saved-login:' + o, token); else if (keepToken && kept) e.token = kept; rows.push(e); }
  writable(SAVED); fs.writeFileSync(SAVED, JSON.stringify(rows.slice(-100)));
}

// ---- target URLs and windows
function withQuery(url, add, drop = []) { const u = new URL(url); for (const k of [...drop, ...Object.keys(add)]) u.searchParams.delete(k); for (const [k, val] of Object.entries(add)) u.searchParams.set(k, val); return u.href; }
function browserPath() {
  const c = [path.join(process.env['ProgramFiles(x86)'] || '', 'Microsoft/Edge/Application/msedge.exe'), path.join(process.env.ProgramFiles || '', 'Microsoft/Edge/Application/msedge.exe'), path.join(process.env.LOCALAPPDATA || '', 'Microsoft/Edge/Application/msedge.exe'), path.join(process.env.ProgramFiles || '', 'Google/Chrome/Application/chrome.exe'), path.join(process.env['ProgramFiles(x86)'] || '', 'Google/Chrome/Application/chrome.exe'), path.join(process.env.LOCALAPPDATA || '', 'Google/Chrome/Application/chrome.exe')];
  return c.find(p => p && exists(p)) || null;
}
export function targets() {
  return {
    native: {available: exists(path.join(ENGINE, 'GameWindow.exe')), label: 'DX11 Client', detail: 'Native GameWindow.exe, windowed 1280x720 (Options > resolution is remembered per account).'},
    'native-fullscreen': {available: exists(path.join(ENGINE, 'GameWindow.exe')), label: 'DX11 Fullscreen', detail: 'Same native window, borderless fullscreen. F11 toggles.'},
    desktop: {available: !!browserPath(), label: 'Desktop App', detail: 'Edge or Chrome app window with its own throw-away profile.'},
    browser: {available: hasShell(), label: 'Web Browser', detail: 'A tab in your default browser.'},
  };
}
async function openNative(url, account, borderless, guardRequest) {
  const fr = await frameRateLaunch();
  const u = withQuery(url, {client: 'desktop', shell: 'native', maxfps: String(fr.maxfps)}, ['client', 'shell', 'maxfps']);
  const profile = /^[a-z0-9_-]{1,32}$/.test(account) ? account : 'player';
  const h = await spawnOutside({exe: path.join(ENGINE, 'GameWindow.exe'), args: ['--url', u, '--profile', profile, borderless ? '--borderless' : '--windowed'], cwd: ENGINE, env: {...await gameGuardLaunchEnv(guardRequest), ...fr.env}, window: true});
  games.set(h.pid, {pid: h.pid, target: borderless ? 'native-fullscreen' : 'native', account, startedAt: Date.now(), server: new URL(url).origin});
  return h.pid;
}
async function openDesktop(url, account) {
  const exe = browserPath(); if (!exe) throw new UserError('Install Microsoft Edge or Google Chrome to open independent game windows.');
  const root = path.join(ENGINE, 'runtime', 'browser-profiles'); fs.mkdirSync(writable(root), {recursive: true});
  const profile = path.join(root, 'client-' + randomBytes(16).toString('hex')); fs.mkdirSync(profile);
  const fr = await frameRateLaunch();
  const u = withQuery(url, {client: 'desktop', maxfps: String(fr.maxfps)}, ['client', 'maxfps']);
  const perf = ['--ignore-gpu-blocklist', '--enable-gpu-rasterization', '--enable-zero-copy', '--disable-renderer-backgrounding', '--disable-background-timer-throttling', '--disable-backgrounding-occluded-windows', '--disable-features=CalculateNativeWinOcclusion,IntensiveWakeUpThrottling', '--force-gpu-preference=high-performance'];
  perf.push(...fr.flags);
  const h = await spawnOutside({exe, args: [`--user-data-dir=${profile}`, `--app=${u}`, '--window-size=1280,720', '--no-first-run', '--no-default-browser-check', ...perf], cwd: path.dirname(exe), window: true});
  games.set(h.pid, {pid: h.pid, target: 'desktop', account, startedAt: Date.now(), profile, server: new URL(url).origin});
  return h.pid;
}
async function openBrowser(url) { if (!hasShell()) throw new UserError('Opening the default browser needs the DK Command Center window.'); await request('open.external', {url}); }

function preloadCancelled() { return Object.assign(new Error('The game loading window closed. Launch cancelled.'), {cancelled: true}); }
// Treat a closed window as cancellation, but keep real verification and pipe errors visible.
function trackPreload(ctx, h, art) {
  const controller = new AbortController();
  let closed = false;
  const onClose = () => { closed = true; controller.abort(); };
  const onCancel = () => controller.abort();
  h.once('exit', onClose);
  ctx.signal?.addEventListener('abort', onCancel, {once: true});
  if (h.exited) onClose();
  if (ctx.signal?.aborted) onCancel();
  const check = () => { ctx.throwIfCancelled(); if (closed || h.exited) throw preloadCancelled(); };
  const waitExit = () => new Promise(resolve => {
    if (closed || h.exited) return resolve(true);
    let done = false;
    const finish = value => { if (done) return; done = true; clearTimeout(timer); h.removeListener('exit', exited); resolve(value); };
    const exited = () => finish(true), timer = setTimeout(() => finish(false), 500);
    h.once('exit', exited);
    if (closed || h.exited) finish(true);
  });
  const write = async line => {
    check();
    try { await h.write(line); }
    catch (error) {
      if (closed || h.exited || !alive(h.pid) || (/^No such pipe\.?$/i.test(String(error?.message || error).trim()) && await waitExit())) throw preloadCancelled();
      throw error;
    }
    check();
  };
  return {h, art, write, check, ctx: {...ctx, signal: controller.signal, throwIfCancelled: check},
    get closed() { return closed || h.exited; },
    dispose() { h.removeListener('exit', onClose); ctx.signal?.removeEventListener('abort', onCancel); }};
}

// Subscribe before sending the launch ticket; a fast frontend may become ready immediately.
function watchFrontend(h, signal, timeoutMs = 300000) {
  let finish, settled = false, timer;
  const cleanup = () => { clearTimeout(timer); h.removeListener('line', onLine); h.removeListener('exit', onExit); signal?.removeEventListener('abort', onAbort); };
  const promise = new Promise((resolve, reject) => {
    finish = error => { if (settled) return; settled = true; cleanup(); error ? reject(error) : resolve(); };
    timer = setTimeout(() => finish(new UserError('The game window did not finish loading. Try again.')), timeoutMs);
    h.on('line', onLine); h.once('exit', onExit); signal?.addEventListener('abort', onAbort, {once: true});
    if (h.exited) onExit(); else if (signal?.aborted) onAbort();
  });
  function onLine(line) { if (line === 'FRONTEND_READY') finish(); else if (line === 'FRONTEND_FAILED') finish(new UserError('The game window could not finish loading.')); }
  function onExit() { finish(preloadCancelled()); }
  function onAbort() { finish(Object.assign(new Error('Launch cancelled.'), {cancelled: true})); }
  // A failed write can leave the watcher unawaited; observe rejection immediately.
  promise.catch(() => {});
  return {promise, dispose: cleanup};
}

// Local DX11 in a dedicated copy: one native window shows installed-byte verification, then frontend readiness, then login.
async function nativePreload(ctx, base, account, borderless, guardRequest) {
  const art = path.join(PROFILE, 'logs', 'dk-loading-' + randomBytes(8).toString('hex') + '.png');
  const stable = path.join(ENGINE, 'run', 'native-loading-art.png');
  const made = await runTool(path.join(ENGINE, 'tools', 'native-preload-art.mjs'), [ENGINE, art], {timeoutMs: 30000});
  if (made.code !== 0 || !exists(art)) {
    if (exists(stable)) { try { fs.copyFileSync(stable, art); } catch { /* fall through */ } }
    if (!exists(art)) throw new UserError('The installed native loading artwork could not be prepared.');
  } else {
    try { fs.mkdirSync(path.dirname(stable), {recursive: true}); fs.copyFileSync(art, stable); } catch { /* best-effort cache */ }
  }
  const profile = /^[a-z0-9_-]{1,32}$/.test(account) ? account : 'player';
  // DKClient.cs accepts only a loopback http origin that exactly matches the later LAUNCH ticket URL.
  let h;
  try {
    h = await spawnOutside({exe: path.join(ENGINE, 'GameWindow.exe'), args: ['--preload-image', art, '--preload-origin', new URL(base).origin, '--profile', profile, borderless ? '--borderless' : '--windowed'], cwd: ENGINE, env: {...await gameGuardLaunchEnv(guardRequest), ...(await frameRateLaunch()).env}, stdinPipe: true, stdoutPipe: true, window: true});
    await new Promise((resolve, reject) => {
      const finish = error => { clearTimeout(t); h.removeListener('line', onLine); h.removeListener('exit', onExit); error ? reject(error) : resolve(); };
      const onLine = line => finish(line === 'PRELOAD_READY' ? null : new UserError('The native loading window handshake failed.'));
      const onExit = () => finish(preloadCancelled());
      const t = setTimeout(() => finish(new UserError('The native loading window did not become ready.')), 20000);
      h.once('line', onLine); h.once('exit', onExit); if (h.exited) onExit();
    });
    return trackPreload(ctx, h, art);
  } catch (error) { try { await h?.closeStdin(); } catch {} try { fs.rmSync(art, {force: true}); } catch {} throw error; }
}
async function verifyAssets(ctx, onState) {
  const phase = path.join(PROFILE, 'logs', 'asset-warm-' + randomBytes(6).toString('hex') + '.json');
  const run = runTool(path.join(ENGINE, 'tools', 'verify-warm-assets.mjs'), ['--engine', ENGINE, '--progress', phase], {timeoutMs: 20 * 60 * 1000, signal: ctx.signal});
  let done = false; run.then(() => { done = true; }, () => { done = true; });
  while (!done) { await sleep(150); try { const st = JSON.parse(fs.readFileSync(phase, 'utf8')); onState(st); } catch {} }
  let r; try { r = await run; } finally { try { fs.rmSync(phase, {force: true}); } catch {} }
  if (r.code !== 0) throw new UserError('Full asset verification did not complete. Game launch stopped. ' + clip(r.stderr, 200));
  const reply = JSON.parse(r.stdout.trim().split(/\r?\n/).at(-1)); if (!reply.verified || !Number.isSafeInteger(reply.files) || reply.files < 1 || !Number.isSafeInteger(reply.totalBytes) || reply.totalBytes < 1 || reply.bytes !== reply.totalBytes) throw new UserError('Full asset verification did not complete. Game launch stopped.');
  onState({...reply, totalFiles: reply.files}); return reply;
}

// verify-warm-assets.mjs and native-preload-art.mjs require the prepared data INSIDE the engine folder (and write receipts
// into its run/). The preview sandbox reads Main's prepared data in place, so it must not use them: DX11 opens directly,
// exactly like the existing launcher does for remote worlds. Integration keeps the preload unchanged.
export function preloadSupported() {
  try { return inside(currentSource().dataRoot, ENGINE); } catch { return false; }
}
let sourceCache = null;
function currentSource() { if (!sourceCache) { const f = path.join(ENGINE, 'dedicated-source.json'); const cfg = JSON.parse(fs.readFileSync(f, 'utf8')); const root = path.resolve(ENGINE, cfg.sourceEngine); const cur = JSON.parse(fs.readFileSync(path.join(root, '.client-cache', 'current.json'), 'utf8')); sourceCache = {dataRoot: path.resolve(root, cur.generation, 'data')}; } return sourceCache; }
/** Existing Wait-OwnerLauncherPreparation: owner characters and guild are prepared before the owner game opens. */
export async function prepareOwner(ctx, staffRole = 'admin', onProgress = () => {}) {
  ctx.phase('Prepare owner', 'Preparing owner characters and guild before opening the game');
  const {launcherCall} = await import('./world.mjs');
  const body = staffRole && staffRole !== 'admin' ? {staffRole} : (staffRole === 'admin' ? {staffRole: 'admin'} : {});
  await launcherCall('owner-launch', {method: 'POST', body, timeoutMs: 60000}); // discarded: a fresh ticket follows
  // SOFT_GUILD_PREP: wait briefly for guild; never block Play if prep fails (sessions cleared / retry in background).
  const until = Date.now() + 45000; let stall = Date.now() + 20000, best = 0;
  for (;;) {
    ctx.throwIfCancelled();
    const st = await launcherCall('status', {timeoutMs: 10000}); ctx.throwIfCancelled(); const r = st.adminGuild || {};
    const n = (Number(r.enrolled) || 0) + (Number(r.actions) || 0); if (n > best) { best = n; stall = Date.now() + 20000; }
    if (Number(r.eligible) >= 1) { const total=Math.floor(Number(r.eligible)), done=Math.max(0,Math.min(total,Math.floor(Number(r.enrolled)||0))); ctx.progress(done, total, 'characters enrolled'); onProgress(done,total); ctx.message(`Preparing owner guild: ${done}/${total} characters enrolled`); }
    if (r.complete === true && r.phase === 'complete') return;
    const pending = ['queued', 'running'].includes(r.phase) || (r.phase === 'deferred' && ['world-not-ready', 'human-admission-or-host-stopping', 'human-admission-or-setup-budget'].includes(r.reason));
    if (!pending || Date.now() > until || Date.now() > stall) {
      ctx.message(r.complete ? 'Owner guild ready' : 'Owner guild still preparing — opening Play anyway (will retry in background).');
      return; // SOFT_GUILD_PREP
    }
    await sleep(250);
  }
}
export async function ownerTicketUrl(base, staffRole = 'admin') {
  const {launcherCall} = await import('./world.mjs');
  const body = {staffRole: staffRole || 'admin'};
  const t = await launcherCall('owner-launch', {method: 'POST', body, timeoutMs: 60000});
  if (!/^[a-f0-9]{64}$/.test(t.ticket || '') || ![45, 180].includes(t.expiresIn)) throw new UserError('The owner handoff could not be verified.');
  // ROLE-AUTOLOGIN: the ticket must be for the role that was asked for (an older server answers every request with admin).
  if (t.account !== (staffRole || 'admin') || (t.staffRole ?? 'admin') !== (staffRole || 'admin')) throw new UserError('The owner handoff returned a different staff account. Restart the server and try again.');
  return new URL('launch#ticket=' + t.ticket, base).href;
}
async function localWorld() { const {world, refresh} = await import('./world.mjs'); await refresh({maxAgeMs: 0}); if (world.status !== 'running') throw new UserError('Start the world first (Home > Start world), or connect to another server.', 409); return world; }

export function signIn(p) {
  return startJob({kind: 'play.signin', key: 'play.signin', area: 'play', title: p.signup ? 'Create account' : `Sign in (${targets()[p.target]?.label || p.target})`, run: async ctx => {
    const local = p.server === 'local';
    const w = local ? await localWorld() : null;
    const base = local ? w.url : friendsUrl(p.server);
    const friends = local ? w.mode === 'hosted' : true;
    ctx.phase('Check server', local ? 'Confirming the sandbox world identity' : 'Checking the selected server');
    const j = jar(); let meta = null;
    if (friends && !local) meta = (await joinCheck(base)).metadata;
    else { const s = await call(base, local && friends ? 'api/friends/status' : 'api/client/status', {j}); if (s?.app !== 'dekaron-engine') throw new UserError('The selected address is not a Dekaron engine server.'); meta = s; }
    const guardRequest=typeof meta?.gameGuardRequired==='boolean'?meta.gameGuardRequired:null;
    if (friends && (meta?.requiresInvite || (local && meta?.hostMode === 'friends'))) {
      ctx.phase('Invite password', 'Entering the server password');
      if (!p.invitePassword) throw new UserError('This server requires its invite password.', 400, {field: 'invitePassword'});
      await call(base, 'api/friends/join', {j, body: {password: p.invitePassword}});
    }
    const id = String(p.id || '').trim().toLowerCase();
    if (p.signup) {
      ctx.phase('Create account', 'Registering on this server');
      if (!ACCOUNT_ID.test(id) || id === '__proto__') throw new UserError('Use an ID of 3-32 letters, numbers, underscores or dashes.', 400, {field: 'id'});
      if (id === 'admin' || id === 'gm' || id === 'dev') throw new UserError('This account is reserved for the installation owner launcher.', 400, {field: 'id'});
      if (typeof p.password !== 'string' || p.password.length < 6 || p.password.length > 128) throw new UserError('Use a password of 6-128 characters.', 400, {field: 'password'});
      if (p.password !== p.confirm) throw new UserError('The passwords do not match.', 400, {field: 'confirm'});
      const acct = await call(base, 'api/auth/signup', {j, body: {id, password: p.password}});
      if (acct?.id !== id) throw new UserError('The account response did not match your registration.');
      await call(base, 'api/auth/logout', {j, body: {}}).catch(() => {});
      event('ok', 'play', `Account ${id} created on ${new URL(base).host}.`);
      return {created: id, server: base};
    }
    let ticketUrl, account;
    if (p.owner) {
      if (!local || friends) throw new UserError('Local admin is available only in your local world.');
      const staffRole = ['admin','gm','dev'].includes(String(p.staffRole||'').toLowerCase()) ? String(p.staffRole).toLowerCase() : 'admin';
      account = staffRole;
    }
    // Native preload (dedicated local DX11) runs before the final ticket so the window shows real verification progress.
    let preload = null;
    const nativeTarget = p.target === 'native' || p.target === 'native-fullscreen', borderless = p.target === 'native-fullscreen';
    try {
      // LAUNCH_PARITY 2026-10-29: Global's client window is the first thing shown (take4 video 06:25:49.654); the old order ran
      // owner preparation for ~18 s with nothing on screen (take5 06:40:48.9-06:41:07.5). With the native preload the window
      // opens first and owner preparation runs alongside verification; LAUNCH still waits for both.
      let ownerPrep = null;
      if (p.owner && !(local && nativeTarget && preloadSupported())) { await prepareOwner(ctx, account); ctx.throwIfCancelled(); }
      if (local && nativeTarget && preloadSupported()) {
        ctx.throwIfCancelled();
        ctx.phase('Open game window', 'Opening the native loading window');
        preload = await nativePreload(ctx, base, account || id, borderless, guardRequest);
        ctx.throwIfCancelled();
        if (p.owner) { ownerPrep = prepareOwner({...preload.ctx, phase: () => {}, progress: () => {}}, account); ownerPrep.catch(() => {}); } // runs beside verification; its phase/progress would overwrite the verify bar
      }
      if (preload) {
        // Mark the preparation gate complete only after it returns (or when it was not needed).
        if (!ownerPrep) await preload.write('OWNER 1 1');
        ctx.phase('Verify installed assets', 'Checking installed files and warming the cache');
        const verified = await verifyAssets(preload.ctx, st => {
          if (st.phase === 'inventory') { if (st.totalFiles > 0) { ctx.progress(st.files, st.totalFiles, 'files counted'); preload.h.write(`INVENTORY ${st.files} ${st.totalFiles}`).catch(() => {}); } return; }
          if (st.phase === 'runtime-fingerprint' && st.totalFiles > 0) { ctx.progress(st.files, st.totalFiles, 'engine files checked'); preload.h.write(`FINGERPRINT ${st.files} ${st.totalFiles}`).catch(() => {}); return; }
          if (st.phase === 'receipt-validation') { preload.h.write('STATUS receipt').catch(() => {}); return; }
          // Receipt reuse checks file identity and reads samples, not every byte; report files checked.
          if (st.phase === 'Verify installed assets (receipt)' && st.totalFiles > 0) { ctx.progress(st.files, st.totalFiles, 'files checked'); preload.h.write(`PROGRESS ${st.files} ${st.totalFiles}`).catch(() => {}); return; }
          if (st.totalBytes > 0 && st.totalFiles > 0) { ctx.progress(Math.round(st.bytes / 1048576), Math.round(st.totalBytes / 1048576), 'MiB verified'); preload.h.write(`VERIFY ${st.files} ${st.totalFiles} ${st.bytes} ${st.totalBytes}`).catch(() => {}); }
        });
        if (ownerPrep) { await ownerPrep; preload.check(); await preload.write('OWNER 1 1'); }
        // Ensure the native window receives completed verification before LAUNCH; intermediate progress writes are best-effort.
        await preload.write(`VERIFY ${verified.files} ${verified.files} ${verified.bytes} ${verified.totalBytes}`);
      }
      preload?.check();
      ctx.phase('Sign in', 'Authenticating');
      if (p.owner || ['admin','gm','dev'].includes(account)) ticketUrl = await ownerTicketUrl(base, account);
      else {
        if (!ACCOUNT_ID.test(id) || id === 'admin' || id === 'gm' || id === 'dev') throw new UserError('Enter your account ID.', 400, {field: 'id'});
        let token = ''; if (!p.password) token = await savedToken(base, id);
        if (!p.password && !token) throw new UserError('Enter your password (no saved login exists for this account on this server).', 400, {field: 'password'});
        let acct;
        if (token) { try { acct = await call(base, 'api/auth/remember-login', {j, body: {id, token}}); } catch (e) { await saveAccount(base, id, {keepToken: false}); throw new UserError('Your saved login expired or was revoked on this server. Enter your password.', 401, {field: 'password'}); } }
        else acct = await call(base, 'api/auth/login', {j, body: {id, password: p.password}});
        if (acct?.id !== id) throw new UserError('The account response did not match your login.');
        let fresh = '';
        if (p.remember || token) { try { const issued = await call(base, 'api/auth/remember', {j, body: token ? {replace: token} : {}}); if (/^[a-f0-9]{64}$/.test(issued?.token || '')) fresh = issued.token; } catch {} }
        const hand = await call(base, 'api/auth/launch-ticket', {j, body: {}});
        if (!/^[a-f0-9]{64}$/.test(hand?.ticket || '') || ![45, 180].includes(hand.expiresIn)) throw new UserError('The game handoff could not be verified.');
        ticketUrl = new URL('launch#ticket=' + hand.ticket, base).href; account = id;
        if (p.remember || token) await saveAccount(base, id, fresh ? {token: fresh} : {keepToken: !!token}).catch(() => {});
      }
      preload?.check();
      ctx.phase('Open game', 'Handing the one-use ticket to the game window');
      let pid = null;
      if (preload) {
        const u = new URL(ticketUrl); u.search = 'client=desktop&shell=native&maxfps=' + (await frameRateLaunch()).maxfps;
        const watcher = watchFrontend(preload.h, preload.ctx.signal);
        try {
          await preload.write('LAUNCH ' + u.href);
          ctx.phase('Open game', 'Waiting for the game window to finish loading');
          await watcher.promise; preload.check();
          await preload.h.closeStdin(); preload.check();
          games.set(preload.h.pid, {pid: preload.h.pid, target: p.target, account, startedAt: Date.now(), server: new URL(base).origin}); pid = preload.h.pid; preload.handedOff = true;
        } catch (error) {
          if (!preload.closed) { try { await preload.h.write('CANCEL'); } catch {} }
          throw error;
        } finally { watcher.dispose(); }
      }
      else if (nativeTarget) pid = await openNative(ticketUrl, account, borderless, guardRequest);
      else if (p.target === 'desktop') pid = await openDesktop(ticketUrl, account);
      else await openBrowser(ticketUrl);
      event('ok', 'play', `Game opened for ${['admin','gm','dev'].includes(account) ? 'the local ' + account.toUpperCase() : 'account ' + account} (${targets()[p.target]?.label}).`);
      return {account, target: p.target, pid, server: new URL(base).origin};
    } catch (error) {
      if (preload?.closed && (error?.cancelled || /^No such pipe\.?$/i.test(String(error?.message || error).trim()))) throw preloadCancelled();
      throw error;
    } finally {
      preload?.dispose();
      if (preload && !preload.handedOff) { try { await preload.h.closeStdin(); } catch {} }
      if (preload?.art) setTimeout(() => fs.rm(preload.art, {force: true}, () => {}), 60000).unref();
    }
  }});
}

// "Return to Client": a game page titled "Dekaron - Return to Client" is closed and the launcher comes forward.
setInterval(async () => {
  const pids = [...games.keys()]; if (!pids.length) return;
  try {
    const r = await native('proc.stats', {pids}, 4000);
    for (const s of r.processes) {
      const g = games.get(s.pid); if (!g) continue;
      if (!s.alive) { games.delete(s.pid); event('info', 'play', `Game window closed (${g.account || 'player'}). The world keeps running.`); if (g.profile) setTimeout(() => removeProfile(g.profile), 3000).unref(); continue; }
      if (!g.closeRequested && /^Dekaron - Return to Client( - |$)/.test(s.title || '')) { g.closeRequested = true; await native('proc.close', {pid: s.pid}).catch(() => {}); if (hasShell()) request('window.front').catch(() => {}); }
    }
  } catch {}
}, 1000).unref();
function removeProfile(p) {
  const root = path.join(ENGINE, 'runtime', 'browser-profiles');
  if (path.dirname(p).toLowerCase() !== root.toLowerCase() || !/^client-[0-9a-f]{32}$/.test(path.basename(p))) return;
  for (let i = 0; i < 20; i++) { try { fs.rmSync(p, {recursive: true, force: true}); return; } catch { } }
}

const signinInput = v.object({server: v.string({max: 600}), target: v.enum(['native', 'native-fullscreen', 'desktop', 'browser']), id: v.optional(v.string({max: 32})), password: v.optional(v.secret({max: 128})), confirm: v.optional(v.secret({max: 128})), invitePassword: v.optional(v.secret({max: 128})), remember: v.optional(v.bool()), owner: v.optional(v.bool()), staffRole: v.optional(v.enum(['admin','gm','dev'])), signup: v.optional(v.bool())});
define('play.signin', {input: signinInput, run: async p => signIn(p)});
define('play.signup', {input: v.object({server: v.string({max: 600}), id: v.string({max: 32}), password: v.secret({max: 128}), confirm: v.secret({max: 128}), invitePassword: v.optional(v.secret({max: 128}))}), run: async p => signIn({...p, signup: true, target: 'browser'})});
define('play.targets', {input: v.object({}), run: async () => ({targets: targets(), default: (await settings()).defaultTarget})});
define('play.saved', {input: v.object({server: v.string({max: 600})}), run: async ({server}) => { const {world} = await import('./world.mjs'); const url = server === 'local' ? world.url : friendsUrl(server); if (!url) return {accounts: []}; return {accounts: await savedAccounts(url)}; }});
define('play.saved.forget', {input: v.object({server: v.string({max: 600}), id: v.string({min: 3, max: 32, pattern: ACCOUNT_ID})}), run: async ({server, id}) => {
  const {world} = await import('./world.mjs'); const url = server === 'local' ? world.url : friendsUrl(server); if (!url) throw new UserError('Start the world first.', 409);
  const token = await savedToken(url, id); if (token) await call(url, 'api/auth/remember-revoke', {body: {id, token}}).catch(() => {});
  await saveAccount(url, id, {remove: true}); event('info', 'play', `Saved login for ${id} forgotten${token ? ' and revoked on the server' : ''}.`); return {forgotten: true};
}});
define('play.games', {input: v.object({}), quiet: true, run: async () => ({games: [...games.values()].map(g => ({pid: g.pid, target: g.target, account: g.account, server: g.server, startedAt: g.startedAt}))})});
