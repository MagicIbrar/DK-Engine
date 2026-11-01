// Updates & Diagnostics backend: live log reader, health checks, timeline, performance, developer data, redacted support
// export, recovery information, and the read-only code & file finder (text + hex viewer).
import fs from 'node:fs';
import fsp from 'node:fs/promises';
import path from 'node:path';
import os from 'node:os';
import {createHash, randomBytes} from 'node:crypto';
import {monitorEventLoopDelay} from 'node:perf_hooks';
import {execFile} from 'node:child_process';
import {promisify} from 'node:util';
import {INSTALL, ENGINE, APP, PREVIEW, PROFILE, LOGS, MAIN, LOCALAPPDATA, EVIDENCE, SANDBOX, WORLD_PORT, HOSTED_PORT, writable, inside} from '../core/paths.mjs';
import {define, v, methodNames} from '../core/rpc.mjs';
import {events} from '../core/events.mjs';
import {listJobs, cancelJob, startJob} from '../core/jobs.mjs';
import {ownedChildren, runTool} from '../core/proc.mjs';
import {native} from '../core/native.mjs';
import {hasShell, request, shellInfo} from '../core/shell.mjs';
import {readJson, readText, redact, clip, isPortFree, UserError, writeJson} from '../core/util.mjs';
import {writeZip} from '../core/zip.mjs';
import {settings, paths} from './settings.mjs';
import {storageConfig} from './storage.mjs';

const run = promisify(execFile);
let bridgeStats = null; export const setBridgeStats = s => { bridgeStats = s; };
const loop = monitorEventLoopDelay({resolution: 10}); loop.enable();
let cpuPrev = {usage: process.cpuUsage(), at: Date.now()};
const uiPerf = [];

// ---- log sources
async function newest(dir, re) { const names = (await fsp.readdir(dir).catch(() => [])).filter(n => re.test(n)); let best = null; for (const n of names) { const st = await fsp.stat(path.join(dir, n)).catch(() => null); if (st && (!best || st.mtimeMs > best.m)) best = {f: path.join(dir, n), m: st.mtimeMs}; } return best?.f || null; }
// Short display path: preview-relative in the preview; engine- or profile-relative when installed.
const shown = f => !INSTALL ? path.relative(PREVIEW, f).replaceAll('\\', '/') : inside(f, PROFILE) ? 'profile/' + path.relative(PROFILE, f).replaceAll('\\', '/') : inside(f, ENGINE) ? path.relative(ENGINE, f).replaceAll('\\', '/') : redact(f);
const fullFiles = new Map(); // source id -> absolute file
async function sources() {
  const {world} = await import('./world.mjs');
  const updates = path.join(LOCALAPPDATA, 'DK Engine Updates', 'installs');
  let updateLog = null;
  if (INSTALL) { const f = path.join(updates, createHash('sha256').update(path.resolve(ENGINE).toLowerCase()).digest('hex').slice(0, 24), 'update-status.log'); if (fs.existsSync(f)) updateLog = f; }
  else for (const d of await fsp.readdir(updates).catch(() => [])) { const f = path.join(updates, d, 'update-status.log'); if (fs.existsSync(f)) updateLog = f; }
  const list = [
    {id: 'world', label: 'World server (output)', file: world.logs?.out || await newest(LOGS, /^world-.*(?<!\.err)\.log$/)},
    {id: 'world-err', label: 'World server (errors)', file: world.logs?.err || await newest(LOGS, /^world-.*\.err\.log$/)},
    {id: 'backend', label: 'Launcher backend', file: path.join(LOGS, 'backend.err.log')},
    {id: 'shell', label: 'Launcher window', file: path.join(LOGS, 'shell.log')},
    {id: 'game', label: 'DX11 game window', file: path.join(ENGINE, 'runtime', 'native-profiles', 'native-client.log')},
    {id: 'updater', label: INSTALL ? 'Updater' : 'Updater (fixture install)', file: updateLog},
    {id: 'timeline', label: 'Event timeline', file: path.join(LOGS, 'timeline.jsonl')},
  ];
  const out = [];
  for (const s of list) { let size = null, mtime = null; if (s.file) { fullFiles.set(s.id, s.file); const st = await fsp.stat(s.file).catch(() => null); if (st) { size = st.size; mtime = st.mtimeMs; } } else fullFiles.delete(s.id); out.push({...s, exists: size !== null, size, mtime, file: s.file ? shown(s.file) : null}); }
  return out;
}
const LEVEL = line => /\b(error|exception|fatal|failed|unhandled|ERR!|TypeError|ReferenceError|RangeError|SyntaxError)\b/i.test(line) ? 'error' : /\b(warn(ing)?|deprecated|retry|timed out|timeout)\b/i.test(line) ? 'warn' : 'info';
const errorCounts = {}; // id -> {errors, warnings, scannedTo}
async function tail({source, cursor = -1, maxBytes = 65536, level = 'all', search = ''}) {
  const s = (await sources()).find(x => x.id === source); if (!s) throw new UserError('Unknown log.', 404);
  if (!s.exists) return {source, lines: [], cursor: 0, size: 0, exists: false};
  const file = fullFiles.get(source), st = await fsp.stat(file); const size = st.size;
  let start = cursor < 0 ? Math.max(0, size - maxBytes) : cursor, reset = false;
  if (start > size) { start = Math.max(0, size - maxBytes); reset = true; } // truncated / rotated
  const length = Math.min(maxBytes, size - start);
  const fd = await fsp.open(file, 'r'); let buf; try { buf = Buffer.alloc(length); await fd.read(buf, 0, length, start); } finally { await fd.close(); }
  let text = buf.toString('utf8'); let consumed = length;
  const lastNl = text.lastIndexOf('\n'); if (start + length < size && lastNl >= 0) { text = text.slice(0, lastNl + 1); consumed = Buffer.byteLength(text); }
  if (cursor < 0 && start > 0) { const first = text.indexOf('\n'); if (first >= 0) text = text.slice(first + 1); }
  const q = search.toLowerCase();
  let lines = text.split(/\r?\n/).filter(Boolean).map(raw => { let line = raw; if (source === 'timeline') { try { const e = JSON.parse(raw); line = `${e.at} [${e.area}] ${e.message}${e.detail ? ' — ' + e.detail : ''}`; return {text: redact(line), level: e.level === 'error' ? 'error' : e.level === 'warn' ? 'warn' : 'info', at: e.at}; } catch {} } return {text: redact(clip(line, 4000)), level: LEVEL(line)}; });
  const c = errorCounts[source] ||= {errors: 0, warnings: 0, scannedTo: 0};
  if (start + consumed > c.scannedTo && start <= c.scannedTo) { for (const l of lines) { if (l.level === 'error') c.errors++; else if (l.level === 'warn') c.warnings++; } c.scannedTo = start + consumed; }
  if (level !== 'all') lines = lines.filter(l => level === 'error' ? l.level === 'error' : l.level !== 'info');
  if (q) lines = lines.filter(l => l.text.toLowerCase().includes(q));
  return {source, lines: lines.slice(-2000), cursor: start + consumed, size, reset, more: start + consumed < size, counts: c};
}
// Background scan keeps per-source error counters current without the reader open (bounded to 256 KB per tick).
setInterval(async () => { for (const s of await sources().catch(() => [])) { if (!s.exists || s.id === 'timeline') continue; const c = errorCounts[s.id] ||= {errors: 0, warnings: 0, scannedTo: Math.max(0, s.size - 65536)}; if (s.size > c.scannedTo) await tail({source: s.id, cursor: c.scannedTo, maxBytes: 262144}).catch(() => {}); else if (s.size < c.scannedTo) Object.assign(c, {scannedTo: 0}); } }, 5000).unref();

// ---- health
async function sc(name) { try { const {stdout} = await run('sc.exe', ['query', name], {windowsHide: true}); return /RUNNING/.test(stdout) ? 'running' : /STOPPED/.test(stdout) ? 'stopped' : 'unknown'; } catch { return 'not installed'; } }
async function health() {
  const checks = [], add = (area, name, state, detail) => checks.push({area, name, state, detail});
  add('runtime', 'Node.js', Number(process.versions.node.split('.')[0]) >= 24 ? 'ok' : 'warn', 'v' + process.versions.node + (INSTALL ? ' (engine runtime/node.exe)' : ' (sandbox runtime/node.exe)'));
  try { const i = (await native('sys.info', {}, 8000)).info; add('runtime', 'WebView2 runtime', i.webview2 ? 'ok' : 'error', i.webview2 || 'missing'); for (const d of i.drives) add('system', 'Disk ' + d.name, d.free / d.total < 0.05 ? 'warn' : 'ok', `${(d.free / 1073741824).toFixed(1)} GB free of ${(d.total / 1073741824).toFixed(0)} GB`); add('runtime', 'Native helper', 'ok', 'SQL, DPAPI and process statistics available'); }
  catch (e) { add('runtime', 'Native helper', 'error', e.message); }
  add('runtime', 'Launcher window', hasShell() ? 'ok' : 'warn', hasShell() ? `attached (shell pid ${shellInfo().pid || '?'})` : 'headless mode: dialogs and outside-job processes use fallbacks');
  const {preparedReadiness, world, refresh} = await import('./world.mjs'); await refresh().catch(() => {});
  const r = await preparedReadiness(); add('content', 'Prepared Global data', r.ready ? 'ok' : 'error', r.ready ? `${r.generation} (${INSTALL ? 'read-only' : 'read-only from Main'}), ${r.ms} ms check` : (r.reason || 'missing ' + (r.missing || []).join(', ')));
  add('world', INSTALL ? 'Local world' : 'Sandbox world', world.status === 'running' ? 'ok' : world.status === 'stopped' ? 'info' : 'warn', world.status + (world.port ? ` on port ${world.port}` : ''));
  const portChecks = INSTALL ? [[WORLD_PORT, `Local world port ${WORLD_PORT}`], [HOSTED_PORT, `Hosted world port ${HOSTED_PORT}`]] : [[WORLD_PORT, 'Preview world port 17996'], [HOSTED_PORT, 'Hosted port 7778 (shared with installed game)'], [7996, 'Installed game local port 7996']];
  for (const [port, label] of portChecks) { const free = await isPortFree(port); add('network', label, free ? 'ok' : (port === world.port) ? 'ok' : 'info', free ? 'free' : 'in use' + (port === world.port ? (INSTALL ? ' (by this world)' : ' (by the sandbox world)') : '')); }
  const st = await storageConfig(); add('sql', 'Storage for next start', 'info', st.mode === 'sqlserver' ? `SQL Server ${st.instance}` : 'local files');
  for (const n of ['MSSQL$SQLEXPRESS', 'MSSQL$DEKARONBETA', 'SQLBrowser']) add('sql', n, (await sc(n)) === 'running' ? 'ok' : 'info', await sc(n));
  if (INSTALL) add('safety', 'Writes confined to installation and profile', 'ok', 'Every write passes the paths.writable() guard: this installation and its DK Command Center profile only.');
  else {
    add('safety', 'Updater cache redirect', LOCALAPPDATA.toLowerCase().includes('launcher-redesign-preview') ? 'ok' : 'error', path.relative(PREVIEW, LOCALAPPDATA));
    add('safety', 'Writes confined to preview folder', 'ok', 'All preview writes pass the paths.writable() guard; Main is refused.');
  }
  const mu = process.memoryUsage(); add('launcher', 'Backend memory', mu.rss > 600 * 1048576 ? 'warn' : 'ok', `${Math.round(mu.rss / 1048576)} MB RSS, ${Math.round(mu.heapUsed / 1048576)} MB heap`);
  add('launcher', 'Event loop delay', loop.percentile(99) / 1e6 > 200 ? 'warn' : 'ok', `p50 ${(loop.percentile(50) / 1e6).toFixed(1)} ms, p99 ${(loop.percentile(99) / 1e6).toFixed(1)} ms`);
  return {at: Date.now(), checks, summary: {error: checks.filter(c => c.state === 'error').length, warn: checks.filter(c => c.state === 'warn').length, ok: checks.filter(c => c.state === 'ok').length}};
}

// ---- performance & developer data
function backendPerf() {
  const now = Date.now(), u = process.cpuUsage(cpuPrev.usage), ms = now - cpuPrev.at; cpuPrev = {usage: process.cpuUsage(), at: now};
  const mu = process.memoryUsage();
  return {at: now, cpuPercent: ms > 0 ? Math.round((u.user + u.system) / 1000 / ms / os.cpus().length * 1000) / 10 : null, cpuNote: 'backend process, share of all logical CPUs since the previous sample', rssMB: Math.round(mu.rss / 1048576), heapMB: Math.round(mu.heapUsed / 1048576), loopDelayMs: {p50: +(loop.percentile(50) / 1e6).toFixed(1), p99: +(loop.percentile(99) / 1e6).toFixed(1), max: +(loop.max / 1e6).toFixed(1)}, uptimeS: Math.round(process.uptime())};
}
async function dev() {
  const {snapshot} = await import('./world.mjs');
  let shell = null; if (hasShell()) shell = await request('shell.metrics', {}, 3000).catch(() => null);
  const kids = ownedChildren(); let stats = [];
  const pids = [process.pid, ...kids.map(k => k.pid), ...(snapshot().pid ? [snapshot().pid] : [])].filter(Boolean);
  try { stats = (await native('proc.stats', {pids}, 4000)).processes; } catch {}
  return {backend: backendPerf(), shell, bridge: bridgeStats ? {...bridgeStats, byMethod: Object.fromEntries(Object.entries(bridgeStats.byMethod).map(([k, m]) => [k, {n: m.n, avgMs: +(m.totalMs / m.n).toFixed(1), maxMs: +m.maxMs.toFixed(1)}]))} : null,
    jobs: listJobs(), processes: stats.map(p => ({...p, role: p.pid === process.pid ? 'backend' : p.pid === snapshot().pid ? 'world server (outside job)' : kids.find(k => k.pid === p.pid)?.tool || 'child'})), world: snapshot(),
    env: {node: process.version, platform: `${os.type()} ${os.release()} ${os.arch()}`, cpus: os.cpus().length, memoryGB: +(os.totalmem() / 1073741824).toFixed(1), mode: INSTALL ? 'install' : 'preview', preview: PREVIEW, paths: paths(), ports: {world: WORLD_PORT, hosted: HOSTED_PORT}, methods: methodNames().length, test: process.env.DKCC_TEST === '1'},
    uiPerf: uiPerf.slice(-50)};
}

// ---- support export (redacted)
async function supportExport({toFile}) {
  const stamp = new Date().toISOString().replace(/[:.]/g, '-');
  let target = path.join(EVIDENCE, 'support', `DK-CommandCenter-support-${stamp}.zip`);
  if (toFile && hasShell()) { const pick = await request('dialog.save', {title: 'Save support export', filter: 'ZIP archive|*.zip', name: path.basename(target)}); if (!pick.path) return {saved: false}; if (inside(pick.path, MAIN)) throw new UserError(INSTALL ? 'Choose a folder outside the game installation.' : 'Choose a folder outside the installed game.'); target = pick.path; }
  else { writable(target); await fsp.mkdir(path.dirname(target), {recursive: true}); }
  const entries = [], put = (name, value) => entries.push({name, data: typeof value === 'string' ? redact(value) : redact(JSON.stringify(value, null, 2))});
  put('README.txt', (INSTALL ? 'DK Command Center' : 'DK Command Center Test Preview') + ' support export.\r\nAll text is redacted: home paths, user names, tokens, passwords, cookies, tickets and 64-hex secrets are removed.\r\nNo account stores, saved logins, SQL passwords or game data are included.\r\n');
  put('health.json', await health()); put('developer.json', await dev()); put('timeline.json', events({limit: 2000}));
  const s = await settings(); put('settings.json', s); put('storage.json', await storageConfig());
  for (const src of await sources()) { if (!src.exists || src.id === 'timeline') continue; const t = await tail({source: src.id, cursor: -1, maxBytes: 200 * 1024}); put(`logs/${src.id}.log`, t.lines.map(l => l.text).join('\r\n')); }
  writeZip(target, entries);
  return {saved: true, file: target, entries: entries.length, bytes: (await fsp.stat(target)).size};
}

// ---- recovery information
async function recovery() {
  const parent = path.dirname(MAIN), out = {rollbacks: [], sqlSetupBackups: [], notes: []};
  const own = path.basename(MAIN).toLowerCase() + '.rollback';
  for (const n of await fsp.readdir(parent).catch(() => [])) if (/\.rollback$/i.test(n) && (!INSTALL || n.toLowerCase() === own)) { const st = await fsp.stat(path.join(parent, n)).catch(() => null); out.rollbacks.push({name: n, modified: st?.mtime, note: INSTALL ? 'Previous version kept by the updater; restored automatically if an update is interrupted.' : 'Installed-game rollback folder created by the existing updater (read-only here).'}); }
  for (const n of await fsp.readdir(path.join(ENGINE, 'run')).catch(() => [])) if (/^sql-setup-account-backup-/.test(n)) out.sqlSetupBackups.push(n);
  if (!INSTALL) { const {FIXTURE_INSTALL} = await import('./updates.mjs'); if (fs.existsSync(FIXTURE_INSTALL + '.rollback')) out.rollbacks.push({name: path.relative(PREVIEW, FIXTURE_INSTALL + '.rollback'), note: 'Fixture installation rollback from the update rehearsal.'}); }
  out.backups = (await readJson(path.join(PROFILE, 'backups.json'), [])).slice(-10).reverse();
  out.notes.push('The updater keeps <install>.rollback and restores it automatically if an update is interrupted (upgrade-dedicated-install.mjs recoverInterruptedUpgrade).');
  if (INSTALL) out.notes.push('Settings → "Use the classic launcher" switches Client.exe back to the original launcher at any time; DK Command Center keeps its settings in %LOCALAPPDATA%\\DK Command Center.', 'Disposable restore and write-test databases are named DKTEST_*; your world databases are never dropped by this app.');
  else out.notes.push('The preview itself is removed by deleting its folder; it changes nothing outside it except DKPREVIEW_* test databases on .\\SQLEXPRESS.');
  return out;
}

// ---- code & file finder (read-only)
const DENY = [/^server\/accounts\/.+\.(json|sqlite)$/i, /^server\/saved-logins\.json$/i, /^server\/launcher-control.*\.json$/i, /^server\/friends-host\.json$/i, /^server\/launcher-preferences\.json$/i, /(^|\/)secrets\//i, /^profile\/(webview|localappdata|secrets)\//i, /sql-profiles\.json$/i, /^runtime\//i, /\.(pem|key|sqlite|db)$/i, /^run\/sql-setup-account-backup-/i, /^hosting-setup\//i];
// Installed, the app's own folder sits inside the engine (tools/command-center); it is listed once, under its own root.
const OWN_APP_REL = INSTALL && inside(APP, ENGINE) ? path.relative(ENGINE, APP).replaceAll('\\', '/') : null;
const ROOTS = () => INSTALL
  ? [{id: 'engine', label: 'Engine code', base: ENGINE}, {id: 'preview', label: 'DK Command Center', base: APP}]
  : [{id: 'engine', label: 'Sandbox engine code', base: ENGINE}, {id: 'preview', label: 'Preview app', base: APP}];
let preparedIndex = null;
async function preparedFiles() {
  if (preparedIndex) return preparedIndex;
  const {clientSource} = await import(new URL('file:///' + path.join(ENGINE, 'server', 'client-source.mjs').replaceAll('\\', '/')).href);
  const s = clientSource(ENGINE), roots = {data: s.dataRoot, gamedata: s.gamedataRoot, 'site-assets': s.siteAssetRoot, ...(s.looseSoundRoot ? {'sound-assets': s.looseSoundRoot} : {})};
  const run = path.join(MAIN, 'run'); let receipt = null;
  for (const n of await fsp.readdir(run).catch(() => [])) if (/^asset-preload-[a-f0-9]{64}\.json$/.test(n)) { const j = JSON.parse(await fsp.readFile(path.join(run, n), 'utf8')); if (j.sourceVersion === s.version) receipt = j; }
  preparedIndex = {roots, files: receipt ? receipt.entries.map(e => ({rel: e.file, size: e.bytes, sha256: e.sha256})) : null};
  return preparedIndex;
}
const searches = new Map();
async function walk(base, rel, out, budget) { let names; try { names = await fsp.readdir(path.join(base, rel), {withFileTypes: true}); } catch { return; } for (const e of names) { const r = rel ? rel + '/' + e.name : e.name; if (e.isSymbolicLink()) continue; if (DENY.some(d => d.test(r))) continue; if (e.isDirectory()) { if (e.name === 'node_modules' && !budget.nodeModules) continue; if (e.name === 'bin' && base === APP) continue; if (OWN_APP_REL && base === ENGINE && r === OWN_APP_REL) continue; await walk(base, r, out, budget); } else out.push(r); if (out.length > 60000) return; } }
const TEXT = /\.(m?js|cjs|ts|json|jsonl|md|txt|csv|ini|xml|html|css|ps1|cs|cmd|bat|yaml|yml|log|manifest|svg|glsl|vert|frag|tsv|lst)$/i;
function startSearch({query, mode = 'both', roots = ['engine', 'preview', 'prepared'], exact = false, caseSensitive = false, ext = '', nodeModules = false, limit = 500}) {
  const id = randomBytes(8).toString('hex'), s = {id, results: [], done: false, cancelled: false, scanned: 0, bytes: 0, started: Date.now(), error: null, query};
  searches.set(id, s); if (searches.size > 10) searches.delete(searches.keys().next().value);
  const q = caseSensitive ? query : query.toLowerCase(), words = exact ? [q] : q.split(/\s+/).filter(Boolean);
  const hit = text => { const t = caseSensitive ? text : text.toLowerCase(); return words.every(w => t.includes(w)); };
  const extOk = r => !ext || r.toLowerCase().endsWith(ext.toLowerCase().startsWith('.') ? ext.toLowerCase() : '.' + ext.toLowerCase());
  (async () => {
    try {
      for (const root of ROOTS().filter(r => roots.includes(r.id))) {
        const files = []; await walk(root.base, '', files, {nodeModules});
        for (const rel of files) {
          if (s.cancelled || s.results.length >= limit) break; if (!extOk(rel)) continue; s.scanned++;
          if (mode !== 'content' && hit(rel)) s.results.push({root: root.id, rel, kind: 'name'});
          if (mode !== 'name' && TEXT.test(rel)) {
            const full = path.join(root.base, rel); const st = await fsp.stat(full).catch(() => null); if (!st || st.size > 8 * 1048576) continue;
            const text = await fsp.readFile(full, 'utf8').catch(() => ''); s.bytes += st.size;
            // Each hit carries its exact byte offset, so the hex view can open on the matching bytes.
            const lines = text.split(/\r?\n/); let n = 0, charPos = 0;
            for (let i = 0; i < lines.length && n < 20; i++) {
              const L = lines[i];
              if (hit(L)) {
                const col = Math.max(0, (caseSensitive ? L : L.toLowerCase()).indexOf(words[0]));
                const offset = Buffer.byteLength(text.slice(0, charPos)) + Buffer.byteLength(L.slice(0, col));
                s.results.push({root: root.id, rel, kind: 'content', line: i + 1, column: col + 1, offset, matchBytes: Buffer.byteLength(words[0]), text: redact(clip(L.trim(), 300)), before: lines[i - 1]?.slice(0, 200) ?? null, after: lines[i + 1]?.slice(0, 200) ?? null}); n++;
                if (s.results.length >= limit) break;
              }
              charPos += L.length + (text[charPos + L.length] === '\r' ? 2 : 1);
            }
          }
          if (s.scanned % 200 === 0) await new Promise(r => setImmediate(r));
        }
      }
      if (roots.includes('prepared') && !s.cancelled && s.results.length < limit && mode !== 'content') {
        const idx = await preparedFiles();
        if (idx.files) for (const f of idx.files) { if (s.results.length >= limit || s.cancelled) break; if (extOk(f.rel) && hit(f.rel)) s.results.push({root: 'prepared', rel: f.rel, kind: 'name', size: f.size}); }
        else s.error = INSTALL ? 'Prepared data names come from the verification receipt written when the game data is prepared; there is none for this generation yet.' : 'Prepared data names are listed from Main\'s verification receipt, which does not exist for this generation.';
      }
    } catch (e) { s.error = e.message; } finally { s.done = true; s.ms = Date.now() - s.started; }
  })();
  return {id};
}
function pollSearch({id, from = 0}) { const s = searches.get(id); if (!s) throw new UserError('Search expired.', 404); return {id, results: s.results.slice(from, from + 500), total: s.results.length, done: s.done, scanned: s.scanned, bytes: s.bytes, ms: s.ms ?? Date.now() - s.started, error: s.error, truncated: s.done && s.results.length >= 500}; }
async function resolveFile(root, rel) {
  if (typeof rel !== 'string' || rel.includes('\0') || rel.split('/').some(p => p === '..')) throw new UserError('Invalid path.');
  if (root === 'prepared') { const idx = await preparedFiles(); const slash = rel.indexOf('/'); const base = idx.roots[rel.slice(0, slash)]; if (!base) throw new UserError('Unknown prepared root.'); const full = path.join(base, rel.slice(slash + 1)); if (!inside(full, base)) throw new UserError('Invalid path.'); return {full, known: idx.files?.find(f => f.rel === rel) || null}; }
  const r = ROOTS().find(x => x.id === root); if (!r) throw new UserError('Unknown root.');
  if (DENY.some(d => d.test(rel))) throw new UserError('This file can hold secrets and is not shown.', 403);
  const full = path.join(r.base, rel); if (!inside(full, r.base)) throw new UserError('Invalid path.'); return {full, known: null};
}
const shaCache = new Map();
async function openFile({root, rel, offset = 0, length = 65536, view = 'auto'}) {
  const {full, known} = await resolveFile(root, rel); const st = await fsp.stat(full).catch(() => null); if (!st?.isFile()) throw new UserError('File not found.', 404);
  const len = Math.max(0, Math.min(view === 'hex' ? 65536 : 524288, length, st.size - offset));
  const fd = await fsp.open(full, 'r'); const buf = Buffer.alloc(len); try { await fd.read(buf, 0, len, offset); } finally { await fd.close(); }
  const sniff = buf.subarray(0, 8192); const binary = view === 'hex' || (view === 'auto' && (sniff.includes(0) || !TEXT.test(rel)));
  const out = {root, rel, size: st.size, modified: st.mtime, offset, length: len, binary, textFile: !sniff.includes(0) && TEXT.test(rel), sha256: known?.sha256 || shaCache.get(full + st.mtimeMs) || null, readOnly: true};
  if (binary) { const rows = []; for (let i = 0; i < len; i += 16) { const chunk = buf.subarray(i, i + 16); rows.push({offset: offset + i, hex: [...chunk].map(b => b.toString(16).padStart(2, '0')).join(' '), ascii: [...chunk].map(b => b >= 32 && b < 127 ? String.fromCharCode(b) : '.').join('')}); } out.rows = rows; }
  else out.text = redact(buf.toString('utf8'));
  return out;
}
async function hashFile({root, rel}) {
  const {full, known} = await resolveFile(root, rel); if (known?.sha256) return {sha256: known.sha256, source: INSTALL ? 'prepared-data verification receipt' : 'Main verification receipt'};
  const st = await fsp.stat(full); if (st.size > 1024 * 1048576) throw new UserError('Files over 1 GB are not hashed here.');
  const h = createHash('sha256'); for await (const c of fs.createReadStream(full)) h.update(c); const sha = h.digest('hex'); shaCache.set(full + st.mtimeMs, sha); return {sha256: sha, source: 'computed now'};
}

// ---- sandbox file-write watcher (Test Bench "file watcher")
// Preview: the whole sandbox. Installed: the engine folder and this app's profile, shown as engine/… and profile/….
const fsEvents = []; let fsSeq = 0, watcher = null;
const WATCH = () => INSTALL ? [[ENGINE, 'engine/'], [PROFILE, 'profile/']] : [[SANDBOX, '']];
function startFsWatch() {
  if (watcher) return {watching: true};
  const list = WATCH().map(([base, prefix]) => fs.watch(base, {recursive: true}, (type, name) => {
    if (!name) return; const rel = prefix + name.replaceAll('\\', '/');
    if (/^profile\/(webview|logs\/timeline)|^engine\/runtime\/(native-profiles\/[^/]+\/|browser-profiles\/)/i.test(rel)) return; // browser caches are noise
    const ev = {seq: ++fsSeq, at: Date.now(), type, rel}; try { const st = fs.statSync(path.join(base, name)); ev.size = st.size; ev.dir = st.isDirectory(); } catch { ev.removed = true; }
    if (DENY.some(d => d.test(rel.replace(/^engine\//, '')))) ev.private = true; // name only; contents never shown
    fsEvents.push(ev); if (fsEvents.length > 3000) fsEvents.splice(0, fsEvents.length - 3000);
  }));
  watcher = {close: () => list.forEach(w => w.close())};
  return {watching: true};
}
function stopFsWatch() { watcher?.close(); watcher = null; return {watching: false}; }

define('diag.sources', {input: v.object({}), quiet: true, run: async () => ({sources: await sources(), counts: errorCounts})});
define('diag.tail', {input: v.object({source: v.string({max: 40}), cursor: v.optional(v.int({min: -1, max: Number.MAX_SAFE_INTEGER})), maxBytes: v.optional(v.int({min: 1024, max: 262144})), level: v.optional(v.enum(['all', 'warn', 'error'])), search: v.optional(v.string({max: 200}))}), quiet: true, run: tail});
define('diag.health', {input: v.object({}), timeoutMs: 40000, run: health});
define('diag.timeline', {input: v.object({after: v.optional(v.int({min: 0, max: 1e12})), area: v.optional(v.string({max: 20})), level: v.optional(v.enum(['info', 'ok', 'warn', 'error'])), limit: v.optional(v.int({min: 1, max: 1000}))}), quiet: true, run: async p => ({events: events(p)})});
define('diag.dev', {input: v.object({}), quiet: true, timeoutMs: 15000, run: dev});
define('diag.perf', {input: v.object({}), quiet: true, run: async () => ({backend: backendPerf(), ui: uiPerf.slice(-200)})});
define('diag.perf.report', {input: v.object({name: v.string({max: 60}), ms: v.number({min: 0, max: 600000}), detail: v.optional(v.string({max: 200}))}), quiet: true, run: async m => { uiPerf.push({...m, at: Date.now()}); if (uiPerf.length > 500) uiPerf.shift(); return {ok: true}; }});
define('diag.export', {input: v.object({toFile: v.optional(v.bool())}), timeoutMs: 30 * 60 * 1000, run: supportExport});
define('diag.recovery', {input: v.object({}), run: recovery});
define('diag.jobs.cancel', {input: v.object({id: v.string({max: 32})}), run: async ({id}) => cancelJob(id)});
define('diag.openFolder', {input: v.object({which: v.enum(['logs', 'evidence', 'sandbox', 'hosting'])}), run: async ({which}) => { const target = {logs: LOGS, evidence: EVIDENCE, sandbox: SANDBOX || ENGINE, hosting: path.join(ENGINE, 'hosting-setup')}[which]; await fsp.mkdir(writable(target), {recursive: true}); await request('open.external', {url: target, folder: true}); return {opened: which}; }});
// Preview only: proves the separate installed game was never written.
if (!INSTALL) define('diag.mainUnchanged', {input: v.object({}), run: async () => startJob({kind: 'diag.main', key: 'diag.main', area: 'diag', title: 'Verify Main unchanged', run: async ctx => {
  ctx.phase('Snapshot', 'Read-only file metadata, hashes of mutable state and SQL row counts');
  const after = path.join(EVIDENCE, 'main-snapshot-latest.json'); writable(after);
  const r1 = await runTool(path.join(PREVIEW, 'tools', 'main-snapshot.mjs'), [after], {timeoutMs: 300000}); if (r1.code !== 0) throw new Error(clip(r1.stderr, 300));
  ctx.phase('Compare', 'Comparing with the baseline taken before the preview existed');
  const r2 = await runTool(path.join(PREVIEW, 'tools', 'main-snapshot.mjs'), ['--compare', path.join(EVIDENCE, 'main-baseline-before.json'), after], {timeoutMs: 120000});
  return JSON.parse(r2.stdout);
}})});
define('find.start', {input: v.object({query: v.string({min: 2, max: 200}), mode: v.optional(v.enum(['name', 'content', 'both'])), roots: v.optional(v.array(v.enum(['engine', 'preview', 'prepared']), {max: 3})), exact: v.optional(v.bool()), caseSensitive: v.optional(v.bool()), ext: v.optional(v.string({max: 12, pattern: /^\.?[a-z0-9]{1,10}$/i})), nodeModules: v.optional(v.bool()), limit: v.optional(v.int({min: 10, max: 2000}))}), run: async p => startSearch(p)});
define('find.poll', {input: v.object({id: v.string({max: 32}), from: v.optional(v.int({min: 0, max: 1e6}))}), quiet: true, run: async p => pollSearch(p)});
define('find.cancel', {input: v.object({id: v.string({max: 32})}), run: async ({id}) => { const s = searches.get(id); if (s) s.cancelled = true; return {cancelled: !!s}; }});
define('find.open', {input: v.object({root: v.enum(['engine', 'preview', 'prepared']), rel: v.string({max: 1000}), offset: v.optional(v.int({min: 0, max: Number.MAX_SAFE_INTEGER})), length: v.optional(v.int({min: 1, max: 524288})), view: v.optional(v.enum(['auto', 'text', 'hex']))}), run: openFile});
define('find.hash', {input: v.object({root: v.enum(['engine', 'preview', 'prepared']), rel: v.string({max: 1000})}), timeoutMs: 120000, run: hashFile});
define('watch.fs.start', {input: v.object({}), run: async () => startFsWatch()});
define('watch.fs.stop', {input: v.object({}), run: async () => stopFsWatch()});
define('watch.fs.poll', {input: v.object({after: v.optional(v.int({min: 0, max: 1e12}))}), quiet: true, run: async ({after = 0}) => ({watching: !!watcher, events: fsEvents.filter(e => e.seq > after).slice(-500)})});
