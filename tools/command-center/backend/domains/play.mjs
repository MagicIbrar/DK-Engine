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
import {settings} from './settings.mjs';
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
async function openNative(url, account, borderless) {
  const u = withQuery(url, {client: 'desktop', shell: 'native'}, ['client', 'shell']);
  const profile = /^[a-z0-9_-]{1,32}$/.test(account) ? account : 'player';
  const h = await spawnOutside({exe: path.join(ENGINE, 'GameWindow.exe'), args: ['--url', u, '--profile', profile, borderless ? '--borderless' : '--windowed'], cwd: ENGINE, window: true});
  games.set(h.pid, {pid: h.pid, target: borderless ? 'native-fullscreen' : 'native', account, startedAt: Date.now(), server: new URL(url).origin});
  return h.pid;
}
async function openDesktop(url, account) {
  const exe = browserPath(); if (!exe) throw new UserError('Install Microsoft Edge or Google Chrome to open independent game windows.');
  const root = path.join(ENGINE, 'runtime', 'browser-profiles'); fs.mkdirSync(writable(root), {recursive: true});
  const profile = path.join(root, 'client-' + randomBytes(16).toString('hex')); fs.mkdirSync(profile);
  const u = withQuery(url, {client: 'desktop'}, ['client']);
  const perf = ['--ignore-gpu-blocklist', '--enable-gpu-rasterization', '--enable-zero-copy', '--disable-renderer-backgrounding', '--disable-background-timer-throttling', '--disable-backgrounding-occluded-windows', '--disable-features=CalculateNativeWinOcclusion'];
  if ((await settings()).uncappedFps) perf.push('--disable-frame-rate-limit', '--disable-gpu-vsync');
  const h = await spawnOutside({exe, args: [`--user-data-dir=${profile}`, `--app=${u}`, '--window-size=1280,720', '--no-first-run', '--no-default-browser-check', ...perf], cwd: path.dirname(exe), window: true});
  games.set(h.pid, {pid: h.pid, target: 'desktop', account, startedAt: Date.now(), profile, server: new URL(url).origin});
  return h.pid;
}
async function openBrowser(url) { if (!hasShell()) throw new UserError('Opening the default browser needs the DK Command Center window.'); await request('open.external', {url}); }

// Local DX11 in a dedicated copy: one native window shows installed-byte verification, then frontend readiness, then login.
async function nativePreload(ctx, base, account, borderless) {
  const art = path.join(PROFILE, 'logs', 'dk-loading-' + randomBytes(8).toString('hex') + '.png');
  const made = await runTool(path.join(ENGINE, 'tools', 'native-preload-art.mjs'), [ENGINE, art], {timeoutMs: 30000});
  if (made.code !== 0 || !exists(art)) throw new UserError('The installed native loading artwork could not be prepared.');
  const profile = /^[a-z0-9_-]{1,32}$/.test(account) ? account : 'player';
  // DKClient.cs accepts only a loopback http origin that exactly matches the later LAUNCH ticket URL.
  const h = await spawnOutside({exe: path.join(ENGINE, 'GameWindow.exe'), args: ['--preload-image', art, '--preload-origin', new URL(base).origin, '--profile', profile, borderless ? '--borderless' : '--windowed'], cwd: ENGINE, stdinPipe: true, stdoutPipe: true, window: true});
  await new Promise((resolve, reject) => { const t = setTimeout(() => reject(new UserError('The native loading window did not become ready.')), 20000); h.once('line', l => { clearTimeout(t); l === 'PRELOAD_READY' ? resolve() : reject(new UserError('The native loading window handshake failed.')); }); h.once('exit', () => { clearTimeout(t); reject(new UserError('The native loading window closed.')); }); });
  return {h, art};
}
async function verifyAssets(ctx, onState) {
  const phase = path.join(PROFILE, 'logs', 'asset-warm-' + randomBytes(6).toString('hex') + '.json');
  const run = runTool(path.join(ENGINE, 'tools', 'verify-warm-assets.mjs'), ['--engine', ENGINE, '--progress', phase], {timeoutMs: 20 * 60 * 1000, signal: ctx.signal});
  let done = false; run.finally(() => { done = true; });
  while (!done) { await sleep(150); try { const st = JSON.parse(fs.readFileSync(phase, 'utf8')); onState(st); } catch {} }
  const r = await run; try { fs.rmSync(phase, {force: true}); } catch {}
  if (r.code !== 0) throw new UserError('Full asset verification did not complete. Game launch stopped. ' + clip(r.stderr, 200));
  const reply = JSON.parse(r.stdout.trim().split(/\r?\n/).at(-1)); if (!reply.verified || reply.bytes !== reply.totalBytes) throw new UserError('Full asset verification did not complete. Game launch stopped.');
  onState(reply); return reply;
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
export async function prepareOwner(ctx) {
  ctx.phase('Prepare owner', 'Preparing owner characters and guild before opening the game');
  const {launcherCall} = await import('./world.mjs');
  await launcherCall('owner-launch', {method: 'POST', body: {}, timeoutMs: 60000}); // discarded: a fresh ticket follows
  const until = Date.now() + 20 * 60 * 1000; let stall = Date.now() + 180000, best = 0;
  for (;;) {
    ctx.throwIfCancelled(); if (Date.now() > until || Date.now() > stall) throw new UserError('Owner guild preparation timed out. Check host setup status, then retry owner sign-in.');
    const st = await launcherCall('status', {timeoutMs: 10000}); const r = st.adminGuild || {};
    const n = (Number(r.enrolled) || 0) + (Number(r.actions) || 0); if (n > best) { best = n; stall = Date.now() + 180000; }
    if (Number(r.eligible) > 0) { ctx.progress(Number(r.enrolled) || 0, Number(r.eligible), 'characters enrolled'); ctx.message(`Preparing owner guild: ${r.enrolled}/${r.eligible} characters enrolled`); }
    if (r.complete === true && r.phase === 'complete') return;
    const pending = ['queued', 'running'].includes(r.phase) || (r.phase === 'deferred' && ['world-not-ready', 'human-admission-or-host-stopping', 'human-admission-or-setup-budget'].includes(r.reason));
    if (!pending) throw new UserError('Owner guild preparation could not finish. Check other owner sessions, then retry owner sign-in.');
    await sleep(250);
  }
}
export async function ownerTicketUrl(base) {
  const {launcherCall} = await import('./world.mjs');
  const t = await launcherCall('owner-launch', {method: 'POST', body: {}, timeoutMs: 60000});
  if (!/^[a-f0-9]{64}$/.test(t.ticket || '') || ![45, 180].includes(t.expiresIn)) throw new UserError('The owner handoff could not be verified.');
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
    if (friends && (meta?.requiresInvite || (local && meta?.hostMode === 'friends'))) {
      ctx.phase('Invite password', 'Entering the server password');
      if (!p.invitePassword) throw new UserError('This server requires its invite password.', 400, {field: 'invitePassword'});
      await call(base, 'api/friends/join', {j, body: {password: p.invitePassword}});
    }
    const id = String(p.id || '').trim().toLowerCase();
    if (p.signup) {
      ctx.phase('Create account', 'Registering on this server');
      if (!ACCOUNT_ID.test(id) || id === '__proto__') throw new UserError('Use an ID of 3-32 letters, numbers, underscores or dashes.', 400, {field: 'id'});
      if (id === 'admin') throw new UserError('This account is reserved for the installation owner launcher.', 400, {field: 'id'});
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
      await prepareOwner(ctx);
      account = 'admin';
    }
    // Native preload (dedicated local DX11) runs before the final ticket so the window shows real verification progress.
    let preload = null;
    const nativeTarget = p.target === 'native' || p.target === 'native-fullscreen', borderless = p.target === 'native-fullscreen';
    try {
      if (local && nativeTarget && preloadSupported()) {
        ctx.phase('Open game window', 'Opening the native loading window');
        preload = await nativePreload(ctx, base, account || id, borderless);
        ctx.phase('Verify installed assets', 'Reading every installed byte once (warms the disk cache)');
        await verifyAssets(ctx, st => {
          if (st.phase === 'inventory') { if (st.totalFiles > 0) { ctx.progress(st.files, st.totalFiles, 'files counted'); preload.h.write(`INVENTORY ${st.files} ${st.totalFiles}`).catch(() => {}); } return; }
          if (st.totalBytes > 0 && st.totalFiles > 0) { ctx.progress(Math.round(st.bytes / 1048576), Math.round(st.totalBytes / 1048576), 'MiB verified'); preload.h.write(`VERIFY ${st.files} ${st.totalFiles} ${st.bytes} ${st.totalBytes}`).catch(() => {}); }
        });
      }
      ctx.phase('Sign in', 'Authenticating');
      if (account === 'admin') ticketUrl = await ownerTicketUrl(base);
      else {
        if (!ACCOUNT_ID.test(id) || id === 'admin') throw new UserError('Enter your account ID.', 400, {field: 'id'});
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
      ctx.phase('Open game', 'Handing the one-use ticket to the game window');
      let pid = null;
      if (preload) { const u = new URL(ticketUrl); u.search = 'client=desktop&shell=native'; await preload.h.write('LAUNCH ' + u.href); await preload.h.closeStdin(); games.set(preload.h.pid, {pid: preload.h.pid, target: p.target, account, startedAt: Date.now(), server: new URL(base).origin}); pid = preload.h.pid; preload.handedOff = true; }
      else if (nativeTarget) pid = await openNative(ticketUrl, account, borderless);
      else if (p.target === 'desktop') pid = await openDesktop(ticketUrl, account);
      else await openBrowser(ticketUrl);
      event('ok', 'play', `Game opened for ${account === 'admin' ? 'the local admin' : 'account ' + account} (${targets()[p.target]?.label}).`);
      return {account, target: p.target, pid, server: new URL(base).origin};
    } finally {
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

const signinInput = v.object({server: v.string({max: 600}), target: v.enum(['native', 'native-fullscreen', 'desktop', 'browser']), id: v.optional(v.string({max: 32})), password: v.optional(v.secret({max: 128})), confirm: v.optional(v.secret({max: 128})), invitePassword: v.optional(v.secret({max: 128})), remember: v.optional(v.bool()), owner: v.optional(v.bool()), signup: v.optional(v.bool())});
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
