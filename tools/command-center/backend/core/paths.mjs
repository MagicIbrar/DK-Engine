// Every location the launcher may touch, for both ways it runs:
//  - "install": the real DK Command Center inside a DK Engine installation (Engine/tools/command-center). It manages that
//    installation: its own world, accounts, SQL world databases and updates. Its profile lives in
//    %LOCALAPPDATA%\DK Command Center\<install id> so it survives engine updates.
//  - "preview": the isolated Test Preview (launcher-redesign-preview) that drives a sandbox copy of the engine and only
//    reads the installed game (Main); every write is confined to the preview folder.
import path from 'node:path';
import fs from 'node:fs';
import {fileURLToPath} from 'node:url';

const HERE = path.dirname(fileURLToPath(import.meta.url));
export const MODE = process.env.DKCC_MODE === 'install' ? 'install' : 'preview';
export const INSTALL = MODE === 'install';
const key = p => path.resolve(p).toLowerCase();
export const inside = (p, root) => { const r = path.relative(key(root), key(p)); return r === '' || (!r.startsWith('..') && !path.isAbsolute(r)); };

// The command center's own code folder (backend, ui, executable).
export const APP = INSTALL ? path.resolve(process.env.DKCC_APP || path.join(HERE, '..', '..')) : path.resolve(process.env.DKCC_PREVIEW || path.join(HERE, '..', '..', '..'), 'app');
export const UI = path.join(APP, 'ui');
export const PREVIEW = INSTALL ? APP : path.dirname(APP);               // root used to show short relative paths
export const SANDBOX = INSTALL ? null : path.join(PREVIEW, 'sandbox');
export const ENGINE = INSTALL ? path.resolve(process.env.DKCC_ENGINE || path.join(APP, '..', '..')) : path.join(SANDBOX, 'engine');
export const PROFILE = path.resolve(process.env.DKCC_PROFILE || (INSTALL ? path.join(process.env.LOCALAPPDATA || ENGINE, 'DK Command Center', 'default') : path.join(SANDBOX, 'profile')));
export const LOGS = path.join(PROFILE, 'logs');
export const SECRETS = path.join(PROFILE, 'secrets');
// Preview: updater cache redirected away from the real one. Install: the real per-user updater cache.
export const LOCALAPPDATA = INSTALL ? (process.env.LOCALAPPDATA || path.join(PROFILE, 'localappdata')) : path.join(PROFILE, 'localappdata');
export const BACKUPS = INSTALL ? path.join(PROFILE, 'backups') : path.join(SANDBOX, 'backups');
export const UPDATE_FIXTURE = INSTALL ? null : path.join(SANDBOX, 'update-fixture');
export const EVIDENCE = INSTALL ? path.join(PROFILE, 'captures') : path.join(PREVIEW, 'evidence');
export const NODE = path.join(ENGINE, 'runtime', 'node.exe');
export const SHELL_EXE = INSTALL ? path.join(APP, 'DKCommandCenter.exe') : path.join(APP, 'bin', 'DKCommandCenterPreview.exe');
// "The installed game": in the preview the separate Main installation (read only); installed, the engine itself.
const previewInstalledGame = () => {
  try {
    const cfg = JSON.parse(fs.readFileSync(path.join(ENGINE, 'dedicated-source.json'), 'utf8'));
    return path.resolve(ENGINE, cfg.sourceEngine, '..', '..');
  } catch { return path.resolve(process.env.DKCC_MAIN || path.join(PREVIEW, 'missing-installed-game')); }
};
export const MAIN = INSTALL ? ENGINE : previewInstalledGame();
export const STAGED_SOURCE = INSTALL ? null : path.resolve(PREVIEW, '..', 'release-candidate-20261016', 'Engine');
export const PUBLISHED_ZIP = INSTALL ? null : path.resolve(PREVIEW, '..', 'release-candidate-20261016', 'DK-4.0.1.zip');
export const WORLD_PORT = INSTALL ? 7996 : 17996;   // local world (the installed engine's own port; the preview uses 17996)
export const HOSTED_PORT = 7778;                    // fixed by engine contracts (configure-friends-host.mjs, friends-gate.mjs)
// Disposable database names: restore rehearsals and write-mode test databases.
export const TEST_DB_PREFIX = INSTALL ? 'DKTEST_' : 'DKPREVIEW_';

/** Throws unless the target is a place this launcher may write. Every write goes through this. */
export function writable(target) {
  const p = path.resolve(target);
  if (INSTALL) {
    // Installed: its own profile, its engine (run/, server/ state the classic launcher also writes) and captures.
    if (!inside(p, PROFILE) && !inside(p, ENGINE) && !inside(p, EVIDENCE)) throw Error('DK Command Center writes only inside its installation and its profile.');
  } else {
    if (inside(p, MAIN)) throw Error('The preview never writes inside the installed game.');
    if (!inside(p, PREVIEW)) throw Error('The preview writes only inside its own folder.');
  }
  for (let at = p; ; at = path.dirname(at)) { try { if (fs.lstatSync(at).isSymbolicLink()) throw Error('Linked paths are refused.'); } catch (e) { if (e.code !== 'ENOENT') throw e; } if (path.dirname(at) === at) break; }
  return p;
}
for (const dir of [PROFILE, LOGS, SECRETS, BACKUPS, EVIDENCE, ...(INSTALL ? [] : [LOCALAPPDATA, UPDATE_FIXTURE])]) fs.mkdirSync(writable(dir), {recursive: true});
