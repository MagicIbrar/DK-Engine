// Hosting, joining, LAN, relay, public listing, invitations, phone QR and hosting setup kits.
// Ported from client-friends.ps1 / client-dashboard.ps1 / client-qr.ps1 / client-hosting-setup.ps1 with the same rules.
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import zlib from 'node:zlib';
import {randomBytes} from 'node:crypto';
import {pathToFileURL} from 'node:url';
import {spawn} from 'node:child_process';
import readline from 'node:readline';
import {ENGINE, NODE, HOSTED_PORT, WORLD_PORT, writable, MAIN, inside} from '../core/paths.mjs';
import {define, v, ACCOUNT_ID} from '../core/rpc.mjs';
import {readJson, writeJson, writeText, fetchJson, UserError, clip, isPortFree} from '../core/util.mjs';
import {runTool, cleanEnv} from '../core/proc.mjs';
import {event} from '../core/events.mjs';
import {request, hasShell} from '../core/shell.mjs';

const PREFS = path.join(ENGINE, 'server', 'launcher-preferences.json');
const mod = rel => import(pathToFileURL(path.join(ENGINE, rel)).href);

// ---- addresses (ConvertTo-FriendsUrl, ConvertTo-ClientRelayOrigin)
const privateV4 = h => { const p = h.split('.').map(Number); return p.length === 4 && p.every(n => Number.isInteger(n) && n >= 0 && n <= 255) && (p[0] === 10 || p[0] === 127 || (p[0] === 172 && p[1] >= 16 && p[1] <= 31) || (p[0] === 192 && p[1] === 168)); };
export function friendsUrl(value) {
  let text = String(value || '').trim(); if (!text) throw new UserError('Paste the address your host sent you.');
  if (!/^https?:\/\//i.test(text)) {
    const host = text.replace(/\/+$/, '').split(':')[0];
    if (/^\d{1,3}(\.\d{1,3}){3}$/.test(host) || host.toLowerCase() === 'localhost') { text = 'http://' + text; if (!/:\d+\/?$/.test(text)) text = text.replace(/\/+$/, '') + ':7778/'; }
    else text = 'https://' + text;
  }
  let u; try { u = new URL(text); } catch { throw new UserError('Use the host LAN address and port 7778, without credentials or extra paths.'); }
  if (!['http:', 'https:'].includes(u.protocol) || u.username || u.password || u.search || u.hash || u.pathname !== '/') throw new UserError('Use the host LAN address and port 7778, without credentials or extra paths.');
  if (u.protocol === 'http:' && !(u.hostname === 'localhost' || privateV4(u.hostname))) throw new UserError('Plain HTTP joining is limited to LAN/private VPN addresses. Internet hosting needs a trusted HTTPS address.');
  return u.href;
}
export function relayOrigin(value) {
  let u; try { u = new URL(String(value || '').trim()); } catch { throw new UserError('Use a public HTTPS hostname without credentials or extra paths.'); }
  const h = u.hostname.toLowerCase();
  if (u.protocol !== 'https:' || u.username || u.password || u.search || u.hash || u.pathname !== '/' || u.port || h === 'localhost' || h.endsWith('.localhost') || /^\d+(\.\d+){3}$/.test(h) || h.includes(':') || !/^([a-z0-9](?:[a-z0-9-]{0,61}[a-z0-9])?\.)+[a-z]{2,63}$/.test(h) || h.length > 253) throw new UserError('Use a public HTTPS hostname without credentials or extra paths.');
  return u.origin;
}
export function lanAddresses(port = HOSTED_PORT) {
  const out = [];
  for (const list of Object.values(os.networkInterfaces())) for (const a of list || []) if (a.family === 'IPv4' && !a.internal && privateV4(a.address) && !a.address.startsWith('127.')) out.push(`http://${a.address}:${port}/`);
  return [...new Set(out)];
}

// ---- saved preferences (ConvertTo-SafeClientPreferences)
function safeConsent(c) {
  if (!c || c.version !== 1) return null;
  const when = Date.parse(c.acceptedAt); if (!Number.isFinite(when) || when > Date.now() + 86400000 || when < Date.parse('2026-01-01')) return null;
  try { return {version: 1, acceptedAt: new Date(when).toISOString().replace(/\.\d{3}Z$/, 'Z'), directory: relayOrigin(c.directory) + '/'}; } catch { return null; }
}
function safeHosting(h) {
  if (!h) return null; if (!['invite', 'open'].includes(h.mode)) throw new UserError('Invalid saved host mode.');
  const out = {mode: h.mode}; const consent = safeConsent(h.listingConsent); if (consent) out.listingConsent = consent;
  if (h.listDirectory) { try { out.listDirectory = relayOrigin(h.listDirectory) + '/'; } catch {} }
  out.allowLan = h.allowLan === true;
  if (h.relay) {
    const origin = relayOrigin(h.relay.publicOrigin);
    if (typeof h.relay.publish !== 'boolean') throw new UserError('Invalid saved public listing choice.');
    const token = String(h.relay.tokenFile || '');
    if (!token || token.length > 1024 || /[\x00-\x1f\x7f]/.test(token) || !/^[a-z]:[\\/]/i.test(token)) throw new UserError('Choose a private local token-file path.');
    let directory = ''; if (h.relay.directory) { try { directory = relayOrigin(h.relay.directory) + '/'; } catch (e) { if (h.relay.publish) throw e; } }
    if (h.relay.publish && !directory) throw new UserError('Public listing needs an HTTPS directory root.');
    const listed = h.relay.publish && consent && consent.directory === directory;
    out.relay = {publicOrigin: origin, tokenFile: path.resolve(token), publish: !!listed, directory};
  }
  return out;
}
export async function readPrefs() {
  const raw = await readJson(PREFS, null, 16384); if (!raw) return {version: 2, kind: 'local', servers: [], hosting: null};
  if (![1, 2].includes(raw.version) || !['local', 'remote', 'host'].includes(raw.kind)) throw new UserError('Invalid saved hosting preferences.');
  const entries = raw.version === 1 && raw.kind === 'remote' ? [{url: raw.url, name: raw.url}] : (raw.servers || []);
  const servers = [], seen = new Set();
  for (const e of entries) { try { const url = friendsUrl(e.url); if (seen.has(url)) continue; seen.add(url); let name = String(e.name || '').replace(/[\x00-\x1f\x7f]/g, '').trim() || url; servers.push({url, name: name.slice(0, 96)}); if (servers.length >= 12) break; } catch {} }
  return {version: 2, kind: raw.kind, url: raw.kind === 'remote' ? friendsUrl(raw.url) : undefined, servers, hosting: raw.version === 2 && raw.hosting ? safeHosting(raw.hosting) : null};
}
export async function savePrefs(patch) {
  const cur = await readPrefs(); const next = {version: 2, kind: patch.kind ?? cur.kind, servers: cur.servers, hosting: patch.hosting !== undefined ? patch.hosting : cur.hosting};
  if (patch.addServer) { const url = friendsUrl(patch.addServer.url); next.servers = [{url, name: String(patch.addServer.name || url).slice(0, 96)}, ...cur.servers.filter(s => s.url !== url)].slice(0, 12); }
  if (patch.removeServer) next.servers = next.servers.filter(s => s.url !== patch.removeServer);
  if (next.kind === 'remote') next.url = friendsUrl(patch.url ?? cur.url);
  if (next.hosting) next.hosting = safeHosting(next.hosting);
  await writeJson(PREFS, next); return readPrefs();
}

// ---- friends host configuration (configure-friends-host.mjs)
export async function hostStatus() {
  const r = await runTool(path.join(ENGINE, 'tools', 'configure-friends-host.mjs'), ['--status'], {timeoutMs: 20000});
  if (r.code !== 0) { let msg = 'Friends host configuration could not be read.'; try { msg = JSON.parse(r.stderr).error || msg; } catch {} return {configured: false, error: msg}; }
  return JSON.parse(r.stdout);
}
async function configureHost(credentials) {
  const r = await runTool(path.join(ENGINE, 'tools', 'configure-friends-host.mjs'), [], {input: credentials, timeoutMs: 30000});
  if (r.code !== 0) { let msg = 'Friends host configuration failed.'; try { msg = JSON.parse(r.stderr).error || msg; } catch {} throw new UserError(msg); }
  const cfg = JSON.parse(r.stdout);
  if (cfg.port !== 7778) throw new UserError('The friends host configuration has an unexpected port.');
  for (const [k, rel] of [['accountStore', 'server/accounts/friends-accounts.json'], ['permissionsFile', 'server/accounts/friends-accounts.json.permissions.json']]) if (path.resolve(cfg[k]).toLowerCase() !== path.join(ENGINE, rel).toLowerCase()) throw new UserError('Friends host configuration escaped its private account folder.');
  return cfg;
}

// ---- relay + publication state for the running hosted world
const relay = {config: null, process: null, publicOrigin: null, publisher: null, listed: false};
function relayCommand(value, timeoutMs = 240000) {
  if (!relay.process || relay.process.exitCode !== null) return Promise.reject(new UserError('The owned relay is not running.'));
  const id = randomBytes(8).toString('hex'); value.id = id;
  return new Promise((resolve, reject) => {
    const t = setTimeout(() => { cleanup(); reject(new UserError('Relay readiness timed out.')); }, timeoutMs);
    const onLine = line => { let m; try { m = JSON.parse(line); } catch { return; } if (m.id !== id) return; cleanup(); m.ok ? resolve(m) : reject(new UserError(m.error || 'The relay could not be verified.')); };
    const cleanup = () => { clearTimeout(t); relay.lines.off('line', onLine); };
    relay.lines.on('line', onLine); relay.process.stdin.write(JSON.stringify(value) + '\n');
  });
}
export async function hostingEnvironment(ctx) {
  const cfg = await hostStatus();
  if (!cfg.configured || cfg.port !== 7778) throw new UserError('Configure the host first (Play & Connect > Host): an Admin / GM / Dev (max staff) account and access mode.');
  const prefs = await readPrefs(), h = prefs.hosting || {mode: cfg.mode};
  const rates = cfg.rates || {exp: 1, dil: 1, drop: 1};
  const env = {PORT: String(HOSTED_PORT), DEKARON_HOST: h.allowLan ? '0.0.0.0' : '127.0.0.1', DEKARON_LOCAL_DEMO: '0', DEKARON_ACCOUNT_STORE: cfg.accountStore, DEKARON_PERMISSION_STORE: cfg.permissionsFile, DEKARON_SERVER_MODE: 'friends', DEKARON_FRIENDS_GATE: '1', DEKARON_EXP_RATE: String(rates.exp), DEKARON_DIL_RATE: String(rates.dil), DEKARON_DROP_RATE: String(rates.drop)};
  relay.config = null;
  if (h.relay) {
    if (!fs.existsSync(h.relay.tokenFile)) throw new UserError('Select your private cloudflared token file (Host > Online relay).');
    relay.config = {publicOrigin: h.relay.publicOrigin, tokenFile: h.relay.tokenFile, secret: randomBytes(32).toString('hex'), mode: 'named', publish: h.relay.publish, directory: h.relay.directory};
    Object.assign(env, {DEKARON_HOST: '127.0.0.1', DEKARON_RELAY_SECRET: relay.config.secret, DEKARON_RELAY_ORIGIN: relay.config.publicOrigin});
    ctx.log('Online relay configured: ' + relay.config.publicOrigin);
  }
  ctx.log(`Hosted world: ${cfg.mode === 'open' ? 'open (accounts required)' : 'invite only'}, ${env.DEKARON_HOST === '0.0.0.0' ? 'direct LAN allowed' : 'this PC only (relay-only default)'}.`);
  return env;
}
export async function onWorldStarted(ctx, world) {
  if (!relay.config) return;
  ctx.phase('Start relay', 'Starting your private online relay (cloudflared, outbound only)');
  relay.process = spawn(NODE, [path.join(ENGINE, 'tools', 'client-relay.mjs')], {cwd: ENGINE, windowsHide: true, stdio: ['pipe', 'pipe', 'pipe'], env: cleanEnv()});
  relay.lines = readline.createInterface({input: relay.process.stdout});
  const config = {publicOrigin: relay.config.publicOrigin, tokenFile: relay.config.tokenFile, secret: relay.config.secret, mode: 'named', backend: world.url, engineId: world.identity.engineId, pid: world.pid, gatewayPort: 7840};
  try {
    const reply = await relayCommand({command: 'start', config});
    if (reply.state !== 'online' || reply.publicOrigin !== relay.config.publicOrigin) throw new UserError('Managed relay readiness did not match your selected hostname.');
    relay.publicOrigin = reply.publicOrigin; event('ok', 'host', 'Online relay ready: ' + reply.publicOrigin);
    if (relay.config.publish) await enableListing(world);
  } catch (e) { await stopRelay(); throw e; }
}
async function enableListing(world) {
  const {launcherCall} = await import('./world.mjs');
  const approval = await launcherCall('publication', {method: 'POST', body: {enabled: true, url: relay.publicOrigin + '/'}, timeoutMs: 10000});
  if (!approval.enabled || !/^[a-f0-9]{64}$/.test(approval.publicationSecret || '')) throw new UserError('Publication proof was not verified.');
  const p = spawn(NODE, [path.join(ENGINE, 'tools', 'publish-server.mjs'), '--watch'], {cwd: ENGINE, windowsHide: true, stdio: ['pipe', 'pipe', 'pipe'], env: cleanEnv()});
  relay.publisher = p; p.stdin.write(JSON.stringify({directory: relay.config.directory, url: relay.publicOrigin + '/', publicationSecret: approval.publicationSecret}) + '\n');
  const first = await new Promise((resolve, reject) => { const t = setTimeout(() => reject(new UserError('Directory publication timed out.')), 15000); readline.createInterface({input: p.stdout}).once('line', l => { clearTimeout(t); resolve(l); }); p.once('exit', () => { clearTimeout(t); reject(new UserError('The directory did not accept your server.')); }); });
  if (!JSON.parse(first).registered) throw new UserError('The directory did not accept your server.');
  relay.listed = true; event('ok', 'host', 'Public listing active on ' + relay.config.directory);
}
async function withdrawListing() {
  if (relay.listed || relay.publisher) {
    try { const {launcherCall} = await import('./world.mjs'); await launcherCall('publication', {method: 'POST', body: {enabled: false}, timeoutMs: 5000}); } catch {}
    try { relay.publisher?.stdin.end(); } catch {}
    const p = relay.publisher; relay.publisher = null; relay.listed = false;
    if (p) setTimeout(() => { if (p.exitCode === null) p.kill(); }, 12000).unref();
    event('info', 'host', 'Public listing withdrawn. The server leaves the list shortly.');
  }
}
async function stopRelay() {
  await withdrawListing();
  if (relay.process) { try { await relayCommand({command: 'stop'}, 10000); } catch {} try { relay.process.stdin.end(); } catch {} const p = relay.process; setTimeout(() => { if (p.exitCode === null) p.kill(); }, 5000).unref(); }
  relay.process = null; relay.publicOrigin = null;
}
export async function onWorldStopping() { await stopRelay(); }

// ---- live status of other servers (/api/friends/status)
export function population(s) {
  const ok = n => Number.isInteger(n) && n >= 0 && n <= 100000;
  const state = {online: !!s, total: null, humans: null, bots: null, known: false, name: null};
  if (!s) return state;
  if (ok(s.players)) state.total = s.players;
  if (state.total !== null && ok(s.realPlayers) && ok(s.botPlayers) && s.realPlayers + s.botPlayers === state.total) Object.assign(state, {humans: s.realPlayers, bots: s.botPlayers, known: true});
  if (typeof s.name === 'string' && s.name.length <= 64 && !/[\x00-\x1f\x7f]/.test(s.name)) state.name = s.name.trim();
  return state;
}
function compatible(s) { return s?.app === 'dekaron-engine' && s.protocol === 1 && s.version === 1 && typeof s.requiresInvite === 'boolean' && ((s.hostMode === 'friends' && s.requiresInvite) || (s.hostMode === 'open' && !s.requiresInvite)); }
export async function probeServer(url, timeoutMs = 3000) {
  const r = await fetchJson(new URL('api/friends/status', url).href, {timeoutMs});
  if (!r.ok || r.data?.app !== 'dekaron-engine') return {url, online: false, ms: r.ms, error: r.error || (r.status ? 'HTTP ' + r.status : 'unreachable')};
  return {url, online: true, compatible: compatible(r.data), ms: r.ms, ...population(r.data), hostMode: r.data.hostMode, requiresInvite: r.data.requiresInvite, rates: r.data.rates || null};
}
async function assertServerSwitch(url) {
  const {world} = await import('./world.mjs');
  if (world.status !== 'running') return;
  const target = new URL(url).host.toLowerCase(), mine = new Set([`127.0.0.1:${world.port}`, `localhost:${world.port}`]); if (relay.publicOrigin) mine.add(new URL(relay.publicOrigin).host);
  if (!mine.has(target)) throw new UserError('Stop all hosted servers before connecting to another server.', 409);
}
export async function joinCheck(address) {
  const url = friendsUrl(address); await assertServerSwitch(url);
  const r = await fetchJson(new URL('api/friends/status', url).href, {timeoutMs: 5000});
  if (!r.ok) throw new UserError('The host did not respond directly. Check the address, LAN/VPN and firewall; redirects are not accepted.');
  if (!compatible(r.data)) throw new UserError('This address is not a compatible invite-only or open Dekaron friends server.');
  return {url, metadata: {name: population(r.data).name, rates: r.data.rates || null, hostMode: r.data.hostMode, requiresInvite: r.data.requiresInvite, gameGuardRequired:typeof r.data.gameGuardRequired==='boolean'?r.data.gameGuardRequired:null, ...population(r.data)}, ms: r.ms};
}

// ---- public directory (ConvertFrom-PublicDirectoryContent)
const directoryCache = new Map();
export async function fetchDirectory(address, force = false) {
  const origin = (() => { try { const u = new URL(String(address).trim()); if (u.protocol !== 'https:' || u.username || u.password || u.search || u.hash || u.pathname !== '/') throw 0; return u.origin + '/'; } catch { throw new UserError('Use the directory HTTPS root address, for example https://directory.example.com/.'); } })();
  const hit = directoryCache.get(origin);
  if (!force && hit && Date.now() - hit.at < 60000) return {...hit.value, cached: true};
  const r = await fetchJson(origin + 'api/servers', {timeoutMs: 8000});
  if (!r.ok) throw new UserError('The directory did not answer correctly (' + (r.error || 'HTTP ' + r.status) + ').');
  const d = r.data; if (d?.app !== 'dekaron-directory' || d.version !== 1 || d.protocol !== 1) throw new UserError('Incompatible server directory.');
  const servers = [];
  for (const e of d.servers || []) { try { if (!compatible({...e, app: 'dekaron-engine'})) continue; const url = friendsUrl(e.url); if (!url.startsWith('https:')) continue; servers.push({name: String(e.name || url).slice(0, 96), url, players: Number.isInteger(e.players) ? e.players : null, rates: e.rates || null, hostMode: e.hostMode, requiresInvite: e.requiresInvite}); } catch {} }
  const value = {directory: origin, servers, at: Date.now()}; directoryCache.set(origin, {at: Date.now(), value}); return value;
}

// ---- phone/tablet QR (Get-ClientPhoneShare + client-qr.mjs)
export async function phoneShare() {
  const {world, refresh} = await import('./world.mjs'); await refresh({maxAgeMs: 0});
  if (world.status !== 'running' || !world.identity) throw new UserError('Start your own hosted world before sharing its phone QR.', 409);
  const s = world.identity;
  if (!['open', 'friends'].includes(s.hostMode)) throw new UserError('Phone QR shares a hosted world (Host friends). A local world accepts only this PC.', 409);
  let addresses = [];
  if (relay.publicOrigin) addresses = [relay.publicOrigin + '/'];
  else if (s.listenHost === '0.0.0.0') addresses = lanAddresses(world.port);
  if (!addresses.length) throw new UserError('This running world has no shareable listener. Enable direct LAN connections for the next host start, or use the managed HTTPS relay.', 409);
  const {connectionQr} = await mod('tools/client-qr.mjs');
  return {addresses: addresses.map(a => { try { const q = connectionQr(a); return {address: q.address, payload: q.payload, size: q.size, quietZone: q.quietZone, matrix: q.matrix}; } catch (e) { return {address: a, error: e.message}; } })};
}
function crc32(buf) { let c, crc = 0xffffffff; for (let n = 0; n < buf.length; n++) { c = (crc ^ buf[n]) & 0xff; for (let k = 0; k < 8; k++) c = c & 1 ? 0xedb88320 ^ (c >>> 1) : c >>> 1; crc = (crc >>> 8) ^ c; } return (crc ^ 0xffffffff) >>> 0; }
function pngFromMatrix(matrix, quiet = 4, scale = 8) {
  const n = matrix.length, size = (n + quiet * 2) * scale, rows = [];
  for (let y = 0; y < size; y++) { const row = Buffer.alloc(1 + size); for (let x = 0; x < size; x++) { const mx = Math.floor(x / scale) - quiet, my = Math.floor(y / scale) - quiet; const dark = mx >= 0 && my >= 0 && mx < n && my < n && matrix[my][mx] === '1'; row[1 + x] = dark ? 0 : 255; } rows.push(row); }
  const chunk = (type, data) => { const len = Buffer.alloc(4); len.writeUInt32BE(data.length); const td = Buffer.concat([Buffer.from(type), data]); const crc = Buffer.alloc(4); crc.writeUInt32BE(crc32(td)); return Buffer.concat([len, td, crc]); };
  const ihdr = Buffer.alloc(13); ihdr.writeUInt32BE(size, 0); ihdr.writeUInt32BE(size, 4); ihdr[8] = 8; ihdr[9] = 0; ihdr[10] = 0; ihdr[11] = 0; ihdr[12] = 0;
  return Buffer.concat([Buffer.from([137, 80, 78, 71, 13, 10, 26, 10]), chunk('IHDR', ihdr), chunk('IDAT', zlib.deflateSync(Buffer.concat(rows))), chunk('IEND', Buffer.alloc(0))]);
}

// ---- hosting setup kits (New-HostingSetupKit); written into the sandbox engine only
function kit(route, relayInput, directoryInput) {
  let relayUrl = 'https://world.example.com/', directory = 'https://directory.example.com/'; const placeholders = [];
  try { relayUrl = relayOrigin(relayInput) + '/'; } catch { placeholders.push('relay hostname (world.example.com)'); }
  try { directory = relayOrigin(directoryInput) + '/'; } catch { placeholders.push('directory address (directory.example.com)'); }
  const host = new URL(relayUrl).host, note = placeholders.length ? `PLACEHOLDERS: this kit uses example values for the ${placeholders.join(' and ')}. Replace them with yours and press the button again to regenerate.\r\n\r\n` : '';
  const metadata = JSON.stringify({version: 1, relayOrigin: relayUrl, directoryOrigin: directory, approvedRelayHosts: [host], hostMode: 'open', gatewayPort: 7840, directoryPort: 7790}, null, 2);
  const files = {};
  if (route === 'local') files['README.txt'] = note + `HOST ON THIS PC (relay-only by default)\r\n\r\n1. Play & Connect > Host: create your host (name, Admin / GM / Dev account, access mode).\r\n2. For other people to join over the Internet WITHOUT revealing your home IP, use an outbound relay: enable 'Online relay (managed HTTPS)' and give it your relay hostname + token file (see the Cloudflare kit for how to get them).\r\n3. Without a relay your server listens on 127.0.0.1 only: nobody else can join. To allow friends on your own network instead, enable 'Allow direct LAN connections'. That shows your LAN address and is not hidden from them.\r\n4. To appear in a public list, use Host > Public listing (you will get a warning first).\r\n`;
  if (route === 'vps') { files['README.txt'] = note + `OWN VPS: run a server list (directory) and/or your world on a machine you control\r\n\r\nA. Directory (the public list)\r\n   1. Copy this engine folder to the VPS (Node 24 is required).\r\n   2. Run start-directory.ps1 (Windows) or the same commands in a shell: it sets DEKARON_DIRECTORY_TOKEN, DEKARON_DIRECTORY_RELAY_HOSTS and starts tools/start-directory.mjs on 127.0.0.1:7790.\r\n   3. Put an HTTPS reverse proxy (Caddy, nginx, Cloudflare Tunnel...) in front so the public address is ${directory}\r\n   4. Keep the generated token private. Hosts do not need it; they register with their own publication proof.\r\n   5. To accept ANY relay under a suffix (community lists), set DEKARON_DIRECTORY_RELAY_HOSTS to '*.your-relay-domain.tld'. Exact names are safer.\r\n   6. The directory limits each address to 60 list requests a minute and 10 registrations a minute.\r\n\r\nB. Players: Host > Public listing > Directory address = ${directory} then 'Test connection'.\r\n\r\nC. metadata.json is non-secret. Check it with: node tools\\permanent-hosting-plan.mjs --manifest hosting-setup\\vps\\metadata.json (prints a review plan, deploys nothing).\r\n\r\nMore: docs\\HOSTING.md (Persistent Docker world, Railway/Render templates).\r\n`; files['start-directory.ps1'] = `# Starts the server-list directory on loopback. Put an HTTPS reverse proxy in front of 127.0.0.1:7790.\r\n$env:DEKARON_DIRECTORY_TOKEN = (node -e "process.stdout.write(require('node:crypto').randomBytes(32).toString('hex'))")\r\n$env:DEKARON_DIRECTORY_RELAY_HOSTS = '${host}'\r\n$env:HOST = '127.0.0.1'\r\n$env:PORT = '7790'\r\nnode tools/start-directory.mjs\r\n`; files['metadata.json'] = metadata; }
  if (route === 'vercel') files['README.txt'] = note + `VERCEL: player portal only\r\n\r\nWhat Vercel can do here: serve the static connector (engine\\web) so players open one friendly address that checks a host and sends them to it. It contains no game files and no accounts.\r\nWhat it cannot do: run the server list (the directory is a small always-on Node process holding the list in memory) or the game world. Use the 'My own VPS' kit for the directory.\r\n\r\n1. Install the Vercel CLI and log in yourself.\r\n2. In a terminal: cd engine\\web ; vercel --prod  (Framework: Other; the included vercel.json serves 'public'; no build/install command).\r\n3. Share the resulting address. Players still sign up on the game server they choose.\r\n\r\nSee docs\\HOSTING.md, 'Static connector'. This project verified one static Vercel deployment earlier; it does not deploy anything for you.\r\n`;
  if (route === 'cloudflare') { files['README.txt'] = note + `CLOUDFLARE: relay (hides your home IP) and optional portal\r\n\r\nRelay for your world (outbound-only, your IP is not published):\r\n  1. In your Cloudflare account create a NAMED tunnel (Zero Trust area, Tunnels) and copy its token into a plain file on this PC.\r\n  2. Add a public hostname for the tunnel (for example ${host}) whose service is http://127.0.0.1:7840 .\r\n  3. Play & Connect > Host > Online relay: enable it, enter ${relayUrl} and pick the token file.\r\n  4. Start your host. The relay is the part that can be attacked; Cloudflare's own filtering sits in front of it, and Cloudflare sees every player's IP.\r\n  (Dashboard wording can change; this project has not verified the live dashboard steps.)\r\n\r\nPortal on Cloudflare Pages: upload engine\\web\\public as a Pages project (build command 'exit 0'). Same limits as the Vercel portal.\r\n\r\nSee docs\\HOSTING.md, 'Managed HTTPS relay and IP privacy'.\r\n`; files['metadata.json'] = metadata; }
  return {route, files, placeholders};
}

// ---- RPC
define('host.status', {input: v.object({}), run: async () => {
  const [cfg, prefs, port] = await Promise.all([hostStatus(), readPrefs().catch(e => ({error: e.message})), isPortFree(HOSTED_PORT)]);
  return {config: cfg, prefs, hostedPort: HOSTED_PORT, hostedPortFree: port, lan: lanAddresses(), relay: {running: !!relay.process, publicOrigin: relay.publicOrigin, listed: relay.listed}, note: 'Hosted worlds use the engine\'s fixed port 7778. The preview refuses to host while another program (for example the installed game) uses it.'};
}});
define('host.configure', {input: v.object({id: v.string({min: 3, max: 32, pattern: ACCOUNT_ID}), password: v.secret({min: 12, max: 128}), confirmPassword: v.secret({max: 128}), serverPassword: v.optional(v.secret({max: 128})), name: v.string({min: 1, max: 64}), mode: v.enum(['invite', 'open']), rates: v.object({exp: v.number({min: 0.1, max: 100}), dil: v.number({min: 0.1, max: 100}), drop: v.number({min: 0.1, max: 100})})}), timeoutMs: 40000, run: async p => {
  const cfg = await configureHost({...p, ...(p.mode === 'open' ? {serverPassword: undefined} : {})});
  const prefs = await readPrefs(); await savePrefs({kind: 'host', hosting: {...(prefs.hosting || {}), mode: p.mode}});
  event('ok', 'host', `Host configured: ${p.mode === 'open' ? 'open' : 'invite only'}, Admin / GM / Dev account ${p.id}.`);
  return {configured: cfg.configured, mode: cfg.mode, name: cfg.name, rates: cfg.rates};
}});
define('host.prefs.set', {input: v.object({allowLan: v.optional(v.bool()), mode: v.optional(v.enum(['invite', 'open'])), relay: v.optional(v.object({enabled: v.bool(), publicOrigin: v.optional(v.string({max: 300})), tokenFile: v.optional(v.string({max: 1024})), publish: v.optional(v.bool()), directory: v.optional(v.string({max: 300}))})), listDirectory: v.optional(v.string({max: 300}))}), run: async p => {
  const prefs = await readPrefs(); const h = {...(prefs.hosting || {mode: p.mode || 'invite', allowLan: false})};
  if (p.mode) h.mode = p.mode; if (p.allowLan !== undefined) h.allowLan = p.allowLan;
  if (p.listDirectory !== undefined) h.listDirectory = p.listDirectory ? relayOrigin(p.listDirectory) + '/' : undefined;
  if (p.relay) {
    if (!p.relay.enabled) delete h.relay;
    else {
      const publish = !!p.relay.publish, directory = p.relay.directory ? relayOrigin(p.relay.directory) + '/' : '';
      if (publish && !(h.listingConsent && h.listingConsent.directory === directory)) throw new UserError('Confirm the public-listing warning for this directory first.', 409, {code: 'consent-required'});
      h.relay = {publicOrigin: relayOrigin(p.relay.publicOrigin), tokenFile: p.relay.tokenFile || '', publish, directory};
    }
  }
  const saved = await savePrefs({hosting: h});
  event('info', 'host', 'Hosting preferences saved for the next host start.'); return saved;
}});
define('host.listing.consent', {input: v.object({directory: v.string({max: 300}), accepted: v.bool()}), run: async ({directory, accepted}) => {
  const dir = relayOrigin(directory) + '/'; const prefs = await readPrefs(); const h = {...(prefs.hosting || {mode: 'invite', allowLan: false})};
  if (accepted) h.listingConsent = {version: 1, acceptedAt: new Date().toISOString().replace(/\.\d{3}Z$/, 'Z'), directory: dir};
  else { delete h.listingConsent; if (h.relay) h.relay.publish = false; }
  await savePrefs({hosting: h}); event('info', 'host', accepted ? 'Public listing warning accepted for ' + dir : 'Public listing consent withdrawn.'); return {consent: accepted ? h.listingConsent : null};
}});
define('host.listing.set', {input: v.object({enabled: v.bool()}), timeoutMs: 40000, run: async ({enabled}) => {
  const {world} = await import('./world.mjs');
  if (world.status !== 'running' || world.mode !== 'hosted') throw new UserError('Start your own hosted world first. Only the host can list it.', 409);
  if (!relay.publicOrigin) throw new UserError('Public listing needs the online relay, so your home address is never published.', 409);
  if (enabled) { const prefs = await readPrefs(); const dir = prefs.hosting?.relay?.directory || prefs.hosting?.listDirectory; if (!dir || prefs.hosting?.listingConsent?.directory !== dir) throw new UserError('Confirm the public-listing warning for this directory first.', 409, {code: 'consent-required'}); relay.config.directory = dir; await enableListing(world); }
  else await withdrawListing();
  return {listed: relay.listed};
}});
define('host.listing.warning', {input: v.object({directory: v.string({max: 300})}), run: async ({directory}) => ({directory: relayOrigin(directory) + '/', text: `If you continue, anyone who uses this directory will see your server:\n${relayOrigin(directory)}/\n\nShown publicly: your server name, your relay address, how many players are online, your EXP / DIL / Drop rates, and whether a server password is required.\n\n- Open worlds allow anyone to create accounts and join. Password-protected worlds still require your server password; that password is never listed.\n- Your home IP address is never published, because players connect through your relay. Your relay provider does see every player's IP address.\n- A relay can still be attacked. Nothing is impossible to DDoS.\n- You are responsible for who you let in and for the game files your server sends (see docs\\HOSTING.md).\n- You can turn listing off at any time. Your server then leaves the list within about 90 seconds.\n\nNothing is listed unless you press the button below.`})});
define('host.invite', {input: v.object({}), run: async () => {
  const {world} = await import('./world.mjs'); const prefs = await readPrefs();
  if (relay.publicOrigin) return {address: relay.publicOrigin + '/', kind: 'relay', note: 'Share this relay address. Your home IP is not listed. Send the invite password separately.'};
  if (!prefs.hosting?.allowLan) return {address: null, kind: 'none', note: 'Relay-only: your LAN address is hidden and not copied. Turn on the online relay, or allow direct LAN connections for the next host start.'};
  const lan = lanAddresses(world.port || HOSTED_PORT);
  return {address: lan[0] || null, all: lan, kind: 'lan', note: lan.length > 1 ? 'Multiple networks found. Pick the address on your friends\' network.' : (lan.length ? 'Host stays running while this launcher is open. Send the invite password separately.' : 'No private LAN/VPN address found. Connect to a private network first.')};
}});
define('host.qr', {input: v.object({}), run: phoneShare});
define('host.qr.save', {input: v.object({address: v.string({max: 600})}), timeoutMs: 30 * 60 * 1000, run: async ({address}) => {
  const share = await phoneShare(); const hit = share.addresses.find(a => a.address === address && !a.error);
  if (!hit) throw new UserError('That address is no longer shared by the running world.', 409);
  const chosen = await request('dialog.save', {title: 'Save server QR', filter: 'PNG image|*.png', name: 'Dekaron-server-QR.png'});
  if (!chosen.path) return {saved: false};
  if (inside(chosen.path, MAIN)) throw new UserError('Choose a folder outside the installed game.');
  fs.writeFileSync(chosen.path, pngFromMatrix(hit.matrix, hit.quietZone)); event('info', 'host', 'Phone QR image saved (address only, no password).');
  return {saved: true};
}});
define('host.kit', {input: v.object({route: v.enum(['local', 'vps', 'vercel', 'cloudflare']), relay: v.optional(v.string({max: 300})), directory: v.optional(v.string({max: 300}))}), run: async ({route, relay: r, directory}) => {
  const k = kit(route, r || '', directory || '');
  const folder = path.join(ENGINE, 'hosting-setup', route); writable(folder); fs.mkdirSync(folder, {recursive: true});
  for (const [name, text] of Object.entries(k.files)) { if (!/^[A-Za-z0-9._-]{1,64}$/.test(name)) throw new UserError('Invalid kit file name.'); await writeText(path.join(folder, name), text); }
  if (hasShell()) request('open.external', {url: folder, folder: true}).catch(() => {});
  event('info', 'host', `Hosting setup kit "${route}" written to sandbox/engine/hosting-setup/${route}`);
  return {folder, files: Object.keys(k.files), placeholders: k.placeholders, note: 'Nothing was deployed or contacted. The kit only contains files you run yourself.'};
}});
define('play.servers', {input: v.object({}), run: async () => { const prefs = await readPrefs(); return {saved: prefs.servers, kind: prefs.kind, remote: prefs.kind === 'remote' ? prefs.url : null, directory: prefs.hosting?.listDirectory || null}; }});
define('play.server.remove', {input: v.object({url: v.string({max: 600})}), run: async ({url}) => savePrefs({removeServer: url})});
define('play.connect', {input: v.object({address: v.string({max: 600}), save: v.optional(v.bool())}), timeoutMs: 10000, run: async ({address, save}) => {
  const r = await joinCheck(address);
  if (save !== false) await savePrefs({kind: 'remote', url: r.url, addServer: {url: r.url, name: r.metadata.name || r.url}});
  event('info', 'play', `Connected to ${r.metadata.name || r.url} (${r.metadata.hostMode}).`); return r;
}});
define('play.local', {input: v.object({}), run: async () => { await savePrefs({kind: 'local'}); return {kind: 'local'}; }});
define('play.probe', {input: v.object({urls: v.array(v.string({max: 600}), {max: 24})}), quiet: true, timeoutMs: 8000, run: async ({urls}) => ({results: await Promise.all(urls.map(u => { try { return probeServer(friendsUrl(u)); } catch { return {url: u, online: false, error: 'invalid address'}; } }))})});
define('play.directory', {input: v.object({address: v.string({max: 300}), force: v.optional(v.bool())}), timeoutMs: 12000, run: async ({address, force}) => fetchDirectory(address, force)});
define('play.directory.save', {input: v.object({address: v.string({max: 300})}), run: async ({address}) => {
  const dir = relayOrigin(address) + '/'; const prefs = await readPrefs(); const h = {...(prefs.hosting || {mode: 'invite', allowLan: false})};
  const changed = h.listDirectory && h.listDirectory !== dir; h.listDirectory = dir; if (changed && h.relay?.publish) h.relay.publish = false;
  await savePrefs({hosting: h}); return {directory: dir, listingTurnedOff: !!(changed && relay.listed)};
}});
