// Launcher preferences for the active installation or isolated preview profile.
import path from 'node:path';
import {PROFILE, PREVIEW, ENGINE, LOGS, BACKUPS, MAIN, INSTALL} from '../core/paths.mjs';
import {define, v} from '../core/rpc.mjs';
import {readJson, writeJson, writeText} from '../core/util.mjs';
import {event} from '../core/events.mjs';
import {request, hasShell} from '../core/shell.mjs';

const FILE = path.join(PROFILE, 'settings.json');
// key: [validator, default, applies: 'now' | 'next-start' | 'next-launch' | 'next-game-window', group, label, description]
export const SCHEMA = {
  theme: [v.enum(['dark', 'light', 'system']), 'dark', 'now', 'Appearance', 'Theme', 'Dark charcoal (default), light, or follow Windows.'],
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
  uncappedFps: [v.bool(), false, 'next-game-window', 'Play', 'Uncapped frame rate (benchmark)', 'Existing opt-in (DEKARON_UNCAPPED_FPS=1) for Desktop App windows only: lifts the frame cap and vsync. The picture will tear.'],
  statusPollSeconds: [v.int({min: 2, max: 30}), 3, 'now', 'Advanced', 'World status refresh (s)', 'How often visible pages refresh world status. Hidden pages and a minimized window do not poll.'],
  sqlMonitorSeconds: [v.int({min: 5, max: 120}), 10, 'now', 'Advanced', 'SQL monitor refresh (s)', 'Bounded refresh for the live SQL monitor; failures back off up to 8x.'],
  queryRowLimit: [v.int({min: 50, max: 5000}), 500, 'now', 'Advanced', 'Query row limit', 'Maximum rows returned to the query workspace and table browser.'],
  queryTimeoutSeconds: [v.int({min: 5, max: 300}), 30, 'now', 'Advanced', 'Query timeout (s)', 'SQL Server cancels a query after this long.'],
  keepQueryText: [v.bool(), false, 'now', 'Advanced', 'Keep full query text in history', 'Off: history keeps statements with literal values replaced by ?, so passwords or names typed into queries are not retained.'],
};
let cache = null;
export async function settings() {
  if (!cache) { const saved = await readJson(FILE, {}); cache = {}; for (const [k, [check, def]] of Object.entries(SCHEMA)) { try { cache[k] = saved[k] === undefined ? def : check(saved[k], k); } catch { cache[k] = def; } } }
  return {...cache};
}
export async function updateSettings(patch) {
  const current = await settings(), changed = [];
  for (const [k, value] of Object.entries(patch)) {
    if (!SCHEMA[k]) throw Object.assign(new Error(`Unknown setting ${k}.`), {status: 400});
    const clean = SCHEMA[k][0](value, k); if (current[k] !== clean) { current[k] = clean; changed.push(k); }
  }
  await writeJson(FILE, current); cache = current;
  if (changed.includes('theme')) { await writeText(path.join(PROFILE, 'theme.txt'), current.theme === 'light' ? 'light' : 'dark'); if (hasShell()) request('window.theme', {theme: current.theme === 'light' ? 'light' : 'dark'}).catch(() => {}); }
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
