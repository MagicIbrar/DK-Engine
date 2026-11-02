// Launcher preferences for the active installation or isolated preview profile.
import fs from 'node:fs';
import path from 'node:path';
import {PROFILE, PREVIEW, ENGINE, LOGS, BACKUPS, MAIN, INSTALL, WORLD_PORT, HOSTED_PORT} from '../core/paths.mjs';
import {define, v} from '../core/rpc.mjs';
import {readJson, writeJson, writeText, isPortFree, UserError} from '../core/util.mjs';
import {laneBusy} from '../core/jobs.mjs';
import {event} from '../core/events.mjs';
import {request, hasShell} from '../core/shell.mjs';

const FILE = path.join(PROFILE, 'settings.json');
// key: [validator, default, applies: 'now' | 'next-start' | 'next-launch' | 'next-game-window', group, label, description]
export const SCHEMA = {
  theme: [v.enum(['dark', 'light', 'system']), 'dark', 'now', 'Appearance', 'Theme', 'Dark charcoal (default), light, or follow Windows.'],
  windowOpacity: [v.int({min: 75, max: 100}), 90, 'now', 'Appearance', 'Window opacity', 'Adjust how much of the desktop shows through the Command Center.'],
  scale: [v.number({min: 0.85, max: 1.5}), 1, 'now', 'Appearance', 'Interface scale', 'Scales text and controls inside the launcher. Windows display scaling still applies on top.'],
  reducedMotion: [v.enum(['system', 'on', 'off']), 'system', 'now', 'Appearance', 'Reduce motion', 'Turns off transitions. "System" follows the Windows animation setting.'],
  density: [v.enum(['comfortable', 'compact']), 'comfortable', 'now', 'Appearance', 'Density', 'Compact reduces padding in lists and tables.'],
  startupPage: [v.enum(['home', 'play', 'server', 'sql', 'content', 'updates', 'settings']), 'home', 'next-launch', 'Launcher', 'Open on', 'Page shown when the launcher opens.'],
  measureUploadBeforeStart: [v.bool(), true, 'next-start', 'Launcher', 'Measure upload before starting a world', 'Existing behaviour: a 4-second test against Cloudflare\'s public speed test (random bytes only) sets the upload budget. Turn off to keep the saved value.'],
  confirmClose: [v.bool(), true, 'now', 'Launcher', 'Ask before closing with a running world', 'Closing saves characters and stops a world this launcher started.'],
  notifyWorld: [v.bool(), true, 'now', 'Notifications', 'World notifications', 'Small notices when the world starts, stops or reports a problem.'],
  notifyUpdates: [v.bool(), true, 'now', 'Notifications', 'Update notice', 'Shows the embedded update card when a newer verified release exists. Updates stay available from Updates & Diagnostics.'],
  flashTaskbar: [v.bool(), false, 'now', 'Notifications', 'Flash taskbar on problems', 'Flashes the taskbar button when an action fails while the window is in the background.'],
  defaultTarget: [v.enum(['native', 'native-fullscreen', 'desktop', 'browser']), 'native', 'now', 'Play', 'Default game window', 'DX11 window (1280x720), DX11 fullscreen (borderless), Desktop App (Edge/Chrome app window) or a browser tab.'],
  frameCap: [v.enum(['60', '120', '144', '165', '240', 'uncapped']), '240', 'next-game-window', 'Play', 'Frame rate cap', 'Highest frame rate of the game window (default 240). With vsync the game never runs faster than your monitor, so a 144 Hz screen shows 144. Uncapped also lifts vsync: the picture can tear. The in-game Options > Max fps can only set a lower limit.'],
  uncappedFps: [v.bool(), false, 'next-game-window', 'Play', 'Uncapped frame rate (benchmark)', 'Existing opt-in (DEKARON_UNCAPPED_FPS=1) for Desktop App windows only: lifts the frame cap and vsync. The picture will tear.'],
  gameGuardEnabled: [v.bool(), true, 'next-game-window', 'Play', 'GameGuard local default', 'Used for the DX11 client if the selected server does not advertise a preference. A server preference overrides this launch only.'],
  serverGameGuardRequired: [v.bool(), true, 'next-start', 'Play', 'Server GameGuard request', 'Set this request for your own server while it is stopped. Guard startup and protection cannot be verified.'],
  statusPollSeconds: [v.int({min: 2, max: 30}), 3, 'now', 'Advanced', 'World status refresh (s)', 'How often visible pages refresh world status. Hidden pages and a minimized window do not poll.'],
  sqlMonitorSeconds: [v.int({min: 5, max: 120}), 10, 'now', 'Advanced', 'SQL monitor refresh (s)', 'Bounded refresh for the live SQL monitor; failures back off up to 8x.'],
  queryRowLimit: [v.int({min: 50, max: 5000}), 500, 'now', 'Advanced', 'Query row limit', 'Maximum rows returned to the query workspace and table browser.'],
  queryTimeoutSeconds: [v.int({min: 5, max: 300}), 30, 'now', 'Advanced', 'Query timeout (s)', 'SQL Server cancels a query after this long.'],
  keepQueryText: [v.bool(), false, 'now', 'Advanced', 'Keep full query text in history', 'Off: history keeps statements with literal values replaced by ?, so passwords or names typed into queries are not retained.'],
};
let cache = null, serverPolicyUpdating = false, settingsUpdateQueue = Promise.resolve();
export function serverPolicyChangeInProgress() { return serverPolicyUpdating; }
export async function settings() {
  if (!cache) { const saved = await readJson(FILE, {}); cache = {}; for (const [k, [check, def]] of Object.entries(SCHEMA)) { try { cache[k] = saved[k] === undefined ? def : check(saved[k], k); } catch { cache[k] = def; } }
    const policy=path.join(ENGINE,'runtime','server-gameguard.enabled'),legacy=path.join(ENGINE,'runtime','gameguard.enabled');
    try{const p=fs.existsSync(policy)?policy:legacy,v=fs.readFileSync(p,'utf8').trim().toLowerCase();cache.serverGameGuardRequired=!['0','off','false'].includes(v);}catch{cache.serverGameGuardRequired=typeof saved.serverGameGuardRequired==='boolean'?saved.serverGameGuardRequired:cache.gameGuardEnabled;}
  }
  return {...cache};
}
export async function updateSettings(patch) {
  // One save may write a full settings snapshot. Serialize all saves so a
  // concurrent unrelated preference cannot restore an older server request.
  const operation = settingsUpdateQueue.catch(() => {}).then(() => updateSettingsSerial(patch));
  settingsUpdateQueue = operation.catch(() => {});
  return operation;
}
async function updateSettingsSerial(patch) {
  if (!Object.hasOwn(patch, 'serverGameGuardRequired')) return saveSettings(patch);
  if (serverPolicyUpdating) throw new UserError('Wait for the server GameGuard setting to finish saving.', 409);
  serverPolicyUpdating = true;
  try {
    const {world, refresh} = await import('./world.mjs');
    if (laneBusy('world')) throw new UserError('Stop your server before changing its GameGuard request.', 409);
    await refresh({maxAgeMs: 0});
    if (laneBusy('world') || world.status !== 'stopped' || !await isPortFree(WORLD_PORT) || !await isPortFree(HOSTED_PORT))
      throw new UserError('Stop your server before changing its GameGuard request. A server address is still in use or could not be checked.', 409);
    if (laneBusy('world')) throw new UserError('Stop your server before changing its GameGuard request.', 409);
    return await saveSettings(patch);
  } finally { serverPolicyUpdating = false; }
}
async function saveSettings(patch) {
  const previous = await settings(), current = {...previous}, changed = [];
  for (const [k, value] of Object.entries(patch)) {
    if (!SCHEMA[k]) throw Object.assign(new Error(`Unknown setting ${k}.`), {status: 400});
    const clean = SCHEMA[k][0](value, k); if (current[k] !== clean) { current[k] = clean; changed.push(k); }
  }
  const serverFlag=path.join(ENGINE,'runtime','server-gameguard.enabled');
  await writeJson(FILE, current);
  try {
    if (changed.includes('serverGameGuardRequired')) { const dir=path.dirname(serverFlag);fs.mkdirSync(dir,{recursive:true});await writeText(serverFlag,current.serverGameGuardRequired?'1':'0'); }
  } catch (error) {
    try { await writeJson(FILE, previous); } catch (restoreError) { error.message += '; settings recovery failed: ' + restoreError.message; }
    throw error;
  }
  cache = current;
  if (changed.includes('theme')) { await writeText(path.join(PROFILE, 'theme.txt'), current.theme === 'light' ? 'light' : 'dark'); if (hasShell()) request('window.theme', {theme: current.theme === 'light' ? 'light' : 'dark'}).catch(() => {}); }
  if (changed.includes('windowOpacity') && hasShell()) request('window.opacity', {opacity: current.windowOpacity}).catch(() => {});
  if (changed.includes('gameGuardEnabled')) { try { const dir = path.join(ENGINE, 'runtime'); fs.mkdirSync(dir, {recursive: true}); await writeText(path.join(dir, 'gameguard.enabled'), current.gameGuardEnabled !== false ? '1' : '0'); } catch {} }
  if (changed.length) event('info', 'app', 'Settings saved: ' + changed.join(', '));
  return {settings: current, changed, applies: Object.fromEntries(changed.map(k => [k, SCHEMA[k][2]]))};
}
export function schemaPublic() { return Object.fromEntries(Object.entries(SCHEMA).map(([k, [, def, applies, group, label, description]]) => [k, {default: def, applies, group, label, description}])); }
export function paths() {
  if (INSTALL) return {installation: ENGINE, profile: PROFILE, logs: LOGS, backups: BACKUPS, preparedData: path.join(ENGINE, 'global-prepared', 'engine') + ' (read-only)'};
  return {preview: PREVIEW, sandboxEngine: ENGINE, profile: PROFILE, logs: LOGS, backups: BACKUPS, preparedData: path.join(MAIN, 'global-prepared', 'engine') + ' (read-only)'};
}

define('settings.get', {input: v.object({}), run: async () => ({settings: await settings(), schema: schemaPublic(), paths: paths()})});
define('settings.set', {input: v.object({patch: v.object(Object.fromEntries(Object.keys(SCHEMA).map(k => [k, v.optional(v.any())])))}), run: async ({patch}) => updateSettings(patch)});
define('settings.reset', {input: v.object({keys: v.array(v.enum(Object.keys(SCHEMA)), {max: 40})}), run: async ({keys}) => updateSettings(Object.fromEntries(keys.map(k => [k, SCHEMA[k][1]])))});

/** The server's advertised preference affects this process only, not owner settings. */
// GameGuard is never shipped in the engine. When it is not beside GameWindow.exe, point GameWindow at the
// player's own Global client (recorded by setup in global-client.json) so the Guard stage still runs.
function gameGuardClientEnv() {
  const out = {};
  for (const k of ['DEKARON_GAMEGUARD_ROOT', 'DEKARON_GLOBAL_CLIENT']) if (process.env[k]) out[k] = process.env[k];
  if (!out.DEKARON_GLOBAL_CLIENT) {
    try {
      const rec = JSON.parse(fs.readFileSync(path.join(ENGINE, 'global-client.json'), 'utf8'));
      if (rec?.version === 1 && typeof rec.root === 'string' && path.isAbsolute(rec.root) && !rec.root.startsWith('\\\\') && fs.existsSync(rec.root)) out.DEKARON_GLOBAL_CLIENT = rec.root;
    } catch { /* no recorded Global client */ }
  }
  return out;
}
/** SMOOTH (2026-10-30): the Play "Frame rate cap" for a game window. uncapped = frameCap 'uncapped' or the older uncappedFps switch. */
export async function frameRateLaunch() {
  const s = await settings();
  const uncapped = s.frameCap === 'uncapped' || s.uncappedFps === true;
  const maxfps = uncapped ? 0 : (Number(s.frameCap) || 240);
  const flags = uncapped ? ['--disable-frame-rate-limit', '--disable-gpu-vsync'] : [];
  // GameWindow.exe (DKClient.cs) appends its own switches to WEBVIEW2_ADDITIONAL_BROWSER_ARGUMENTS, so these reach its WebView2
  const extra = [process.env.WEBVIEW2_ADDITIONAL_BROWSER_ARGUMENTS || '', ...flags].join(' ').trim();
  return {uncapped, maxfps, flags, env: flags.length ? {WEBVIEW2_ADDITIONAL_BROWSER_ARGUMENTS: extra} : {}};
}
export async function gameGuardLaunchEnv(requested=null) {
  const s = await settings();
  const on = typeof requested==='boolean'?requested:s.gameGuardEnabled !== false;
  // LAUNCH_CURVE: pass the loading-bar mode switch (DEKARON_LAUNCH_GLOBAL_CURVE=0 = fast mode) through to GameWindow.
  const curve = process.env.DEKARON_LAUNCH_GLOBAL_CURVE;
  return { ...gameGuardClientEnv(), DEKARON_GAMEGUARD: on ? '1' : '0', ...(curve === '0' || curve === '1' ? {DEKARON_LAUNCH_GLOBAL_CURVE: curve} : {}) };
}

// Recreate the server flag from saved owner settings before starting a world,
// including after upgrades that predate preservation of this flag.
export async function ensureServerGameGuardRequest() {
  const current=await settings(),dir=path.join(ENGINE,'runtime');fs.mkdirSync(dir,{recursive:true});
  await writeText(path.join(dir,'server-gameguard.enabled'),current.serverGameGuardRequired?'1':'0');
  return current.serverGameGuardRequired;
}
