// Updates: the embedded update card's backend. Every check, download, verification and deferred installation uses the
// ENGINE's own updater code (tools/release-update.mjs + its detached worker).
//  - Installed: the GitHub release feed for this installation; "Install now" downloads and verifies (size + SHA-256),
//    then the engine's deferred installer waits until this launcher, its world and its game windows are closed,
//    installs, and keeps the previous version as <install>.rollback. Saves and settings are preserved by the engine.
//  - Preview: LOCALAPPDATA is redirected into the preview profile, the feed is a clearly labelled TEST FIXTURE (or a
//    read-only live check) and the only install target is a disposable fixture installation.
import fs from 'node:fs';
import fsp from 'node:fs/promises';
import path from 'node:path';
import {pathToFileURL} from 'node:url';
import {ENGINE, NODE, APP, UPDATE_FIXTURE, LOCALAPPDATA, LOGS, MAIN, PROFILE, INSTALL, writable} from '../core/paths.mjs';
import {define, v} from '../core/rpc.mjs';
import {readJson, writeJson, readText, UserError, clip, sleep} from '../core/util.mjs';
import {runTool, spawnOutside, alive} from '../core/proc.mjs';
import {startJob} from '../core/jobs.mjs';
import {event} from '../core/events.mjs';
import {settings} from './settings.mjs';

const RUNNER = path.join(APP, 'backend', 'tools', 'update-runner.mjs');
const FIXTURE = INSTALL ? null : path.join(UPDATE_FIXTURE, 'fixture.json');
const STATE = INSTALL ? path.join(PROFILE, 'updates-state.json') : path.join(UPDATE_FIXTURE, 'state.json');
export const FIXTURE_INSTALL = INSTALL ? null : path.join(UPDATE_FIXTURE, 'install');      // preview: disposable owned installation
const TARGET = INSTALL ? ENGINE : FIXTURE_INSTALL;                                            // the only installation this page updates
const SCENARIOS = ['available', 'current', 'offline', 'download-fail', 'hash-mismatch'];
const state = {checking: false, lastCheck: null, available: null, notes: null, scenario: 'available', mode: INSTALL ? 'live' : 'fixture', dismissed: null, error: null, history: []};
try { Object.assign(state, JSON.parse(fs.readFileSync(STATE, 'utf8'))); } catch {}
if (INSTALL) state.mode = 'live';
const persist = () => writeJson(STATE, {scenario: state.scenario, mode: state.mode, dismissed: state.dismissed, history: state.history.slice(-50)}).catch(() => {});
const runnerEnv = () => INSTALL ? {DKCC_MODE: 'install'} : {LOCALAPPDATA};

async function runner(op, {installRoot = TARGET, timeoutMs = 120000} = {}) {
  let feed = '-';
  if (!INSTALL) {
    const fixture = await readJson(FIXTURE, null);
    if (!fixture && op !== 'live-check' && !['prefs', 'enable', 'disable'].includes(op)) throw new UserError('The update test fixture is not built yet. Use "Build test fixture" first.', 409, {code: 'no-fixture'});
    feed = path.join(UPDATE_FIXTURE, 'fixture.run.json');
    await writeJson(feed, fixture ? {...fixture, scenario: state.scenario, progressFile: path.join(UPDATE_FIXTURE, 'download-progress.json')} : {scenario: 'live'});
  }
  const r = await runTool(RUNNER, [ENGINE, feed, op, ...(installRoot ? [installRoot] : [])], {env: runnerEnv(), timeoutMs});
  if (r.code !== 0) throw new UserError(clip(r.stderr.trim() || r.stdout.trim(), 400) || 'Updater command failed.');
  return JSON.parse(r.stdout.trim().split(/\r?\n/).at(-1));
}
function versionOf(dir) { try { return JSON.parse(fs.readFileSync(path.join(dir, 'package.json'), 'utf8')).version; } catch { return null; } }

export async function check({mode = state.mode, auto = false} = {}) {
  if (state.checking) return status();
  if (INSTALL) mode = 'live';
  state.checking = true; state.mode = mode; state.error = null;
  try {
    const op = mode === 'live' ? (INSTALL && auto ? 'live-check-auto' : 'live-check') : 'check';
    const r = await runner(op, {installRoot: mode === 'live' && !INSTALL ? ENGINE : (INSTALL || fs.existsSync(FIXTURE_INSTALL) ? TARGET : ENGINE)});
    state.lastCheck = {at: Date.now(), status: r.status, mode, message: r.message || null};
    if (r.status === 'available') { state.available = {...r.candidate, fixture: mode !== 'live'}; const fx = INSTALL ? null : await readJson(FIXTURE, null); state.notes = mode === 'live' ? null : fx?.release?.body || null; }
    else if (r.status === 'current') state.available = null;
    else if (r.status === 'offline') state.error = 'Update check unavailable. You can keep using this installation.' + (r.message ? ' (' + clip(r.message, 120) + ')' : '');
    if (r.status !== 'disabled') { state.history.push({at: Date.now(), kind: 'check', mode, status: r.status, version: r.candidate?.version || null}); persist(); }
    event('info', 'update', `Update check (${mode === 'live' ? 'GitHub' + (INSTALL ? '' : ', read-only') : 'test fixture: ' + state.scenario}): ${r.status}${r.candidate ? ' ' + r.candidate.version : ''}.`);
  } catch (e) { state.error = e.message; state.lastCheck = {at: Date.now(), status: 'error', mode}; }
  finally { state.checking = false; }
  return status();
}
export async function status() {
  let worker = null; if (TARGET && fs.existsSync(TARGET)) { try { worker = await runner('status', {timeoutMs: 20000}); } catch {} }
  let prefs = null; try { prefs = await runner('prefs', {installRoot: null, timeoutMs: 20000}); } catch {}
  const fx = INSTALL ? null : await readJson(FIXTURE, null);
  let notesInstalled = null; try { notesInstalled = clip(await readText(path.join(ENGINE, 'docs', `UPDATE-${versionOf(ENGINE)}.md`), ''), 6000); } catch {}
  return {mode: state.mode, install: INSTALL, installed: INSTALL ? {engine: versionOf(ENGINE)} : {sandbox: versionOf(ENGINE), main: versionOf(MAIN), fixtureInstall: versionOf(FIXTURE_INSTALL)},
    scenario: INSTALL ? null : state.scenario, scenarios: INSTALL ? [] : SCENARIOS, checking: state.checking, lastCheck: state.lastCheck,
    available: state.available, notes: state.notes, dismissed: state.dismissed, notify: !!(state.available && state.dismissed !== state.available.version && (await settings()).notifyUpdates),
    error: state.error, worker, preferences: prefs, fixture: fx ? {version: fx.release?.tag_name, zip: path.basename(fx.zip), bytes: fx.release?.assets?.[0]?.size, builtAt: fx.builtAt} : null,
    fixtureInstallExists: INSTALL ? false : fs.existsSync(FIXTURE_INSTALL), history: state.history.slice(-30).reverse(), notesInstalled,
    safety: INSTALL ? 'Updates are downloaded from the official GitHub release, checked for size and SHA-256, and installed only after DK Command Center, the world and game windows are closed. The previous version is kept for rollback.' : 'Updater cache redirected to the preview profile. Only the disposable fixture installation can be updated; Main and the sandbox engine are never changed by this page.'};
}
async function downloadWatcher(ctx, total) {
  // Real progress: the fixture writes its own byte count; a live download grows a ".download-*" file in the cache.
  let cacheDir = null;
  if (INSTALL) { try { cacheDir = (await import(pathToFileURL(path.join(ENGINE, 'tools', 'release-update.mjs')).href)).cacheForInstall(ENGINE); } catch {} }
  const progressFile = INSTALL ? null : path.join(UPDATE_FIXTURE, 'download-progress.json');
  if (progressFile) await fsp.rm(progressFile, {force: true});
  let done = false;
  const loop = (async () => { while (!done) { await sleep(200); try {
    if (progressFile) { const p = JSON.parse(fs.readFileSync(progressFile, 'utf8')); ctx.progress(p.bytes, p.total, 'bytes'); }
    else if (cacheDir && total) { const part = fs.readdirSync(cacheDir).find(n => n.startsWith('.download-')); if (part) ctx.progress(Math.min(total, fs.statSync(path.join(cacheDir, part)).size), total, 'bytes'); }
  } catch {} } })();
  return async () => { done = true; await loop; };
}
function installJob() {
  return startJob({kind: 'update.install', key: 'update.install', area: 'update', title: `Install ${state.available?.version || 'update'}${INSTALL ? '' : ' (test fixture)'}`, run: async ctx => {
    if (!state.available) throw new UserError('No verified update is available.', 409);
    if (!INSTALL && !state.available.fixture) throw new UserError('Installing live releases is disabled in the Test Preview. Live checks are read-only.', 403);
    if (!INSTALL && !fs.existsSync(FIXTURE_INSTALL)) throw new UserError('Build the update test fixture first.', 409, {code: 'no-fixture'});
    ctx.phase('Download', INSTALL ? `Downloading ${state.available.name} from the official GitHub release` : 'Downloading through the engine updater (fixture transport)');
    const stop = await downloadWatcher(ctx, state.available.bytes);
    const dl0 = Date.now(); let cached; try { cached = await runner(INSTALL ? 'cache-live' : 'cache', {timeoutMs: 45 * 60 * 1000}); } finally { await stop(); }
    if (cached.status !== 'cached') throw new UserError('The update was not cached: ' + (cached.status || 'unknown'));
    ctx.log(`Downloaded ${state.available.bytes} bytes in ${Date.now() - dl0} ms${INSTALL ? '' : ' (fixture transport, local file)'}.`);
    ctx.phase('Verify', 'Size and SHA-256 matched the release metadata (checked by the engine updater)');
    ctx.log(`Cached ${state.available.name} (${state.available.bytes} bytes, sha256 ${state.available.sha256.slice(0, 12)}…).`);
    ctx.phase('Schedule', 'Starting the deferred installer outside the launcher so it can wait for closure');
    const out = path.join(LOGS, 'update-schedule.out.log'), err = path.join(LOGS, 'update-schedule.err.log');
    for (const f of [out, err]) await fsp.writeFile(writable(f), '');
    const feed = INSTALL ? '-' : path.join(UPDATE_FIXTURE, 'fixture.run.json');
    const h = await spawnOutside({exe: NODE, args: [RUNNER, ENGINE, feed, 'apply', TARGET], cwd: path.dirname(RUNNER), env: runnerEnv(), stdout: out, stderr: err});
    const until = Date.now() + 60000; while (alive(h.pid) && Date.now() < until) await sleep(200);
    const text = (await readText(out, '')).trim(); if (!text) throw new UserError('The deferred installer did not confirm scheduling. ' + clip(await readText(err, ''), 300));
    const r = JSON.parse(text.split(/\r?\n/).at(-1));
    state.history.push({at: Date.now(), kind: 'install-requested', version: state.available.version, status: r.status}); persist();
    event('ok', 'update', INSTALL ? `Update ${state.available.version} is ready (${r.status}). Close DK Command Center to install it; the world saves and stops first.` : `Update ${state.available.version} scheduled (${r.status}). Installation waits until the fixture installation's world, game and launcher are closed.`);
    return {...r, closeToInstall: INSTALL};
  }});
}

define('updates.status', {input: v.object({}), timeoutMs: 45000, quiet: true, run: status});
define('updates.check', {input: v.object({mode: v.optional(v.enum(['fixture', 'live']))}), timeoutMs: 60000, run: check});
define('updates.dismiss', {input: v.object({version: v.string({max: 20, pattern: /^\d{1,5}\.\d{1,5}\.\d{1,5}$/})}), run: async ({version}) => { state.dismissed = version; state.history.push({at: Date.now(), kind: 'dismissed', version}); persist(); event('info', 'update', `Update notice for ${version} dismissed (no installation consent). It stays available in Updates.`); return {dismissed: version}; }});
define('updates.install', {input: v.object({}), run: async () => installJob()});
define('updates.preferences', {input: v.object({checkOnLaunch: v.bool()}), timeoutMs: 30000, run: async ({checkOnLaunch}) => runner(checkOnLaunch ? 'enable' : 'disable', {installRoot: null})});
if (!INSTALL) {
  define('updates.scenario', {input: v.object({scenario: v.enum(SCENARIOS)}), run: async ({scenario}) => { state.scenario = scenario; state.available = null; state.dismissed = null; persist(); return check({mode: 'fixture'}); }});
  define('updates.fixture.build', {input: v.object({}), run: async () => startJob({kind: 'update.fixture', key: 'update.fixture', area: 'update', title: 'Build update test fixture', run: async ctx => {
    ctx.phase('Build', 'Staging a disposable owned installation (4.0.1) and a 4.0.2 TEST FIXTURE release');
    const r = await runTool(path.join(APP, '..', 'tools', 'make-update-fixture.mjs'), [], {timeoutMs: 15 * 60 * 1000, signal: ctx.signal, onLine: l => ctx.log(l)});
    if (r.code !== 0) throw new UserError(clip(r.stderr || r.stdout, 600));
    return JSON.parse(r.stdout.trim().split(/\r?\n/).at(-1));
  }})});
}

// Existing behaviour: a check when the launcher opens and every five minutes (installed: honours "check on launch";
// preview: the fixture feed, no network).
setTimeout(() => { check({auto: true}).catch(() => {}); setInterval(() => check({auto: true}).catch(() => {}), 5 * 60 * 1000).unref(); }, 4000).unref();
