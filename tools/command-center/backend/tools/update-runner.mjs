// Runs the ENGINE's own updater functions (tools/release-update.mjs) for the update card.
//  - Installed (DKCC_MODE=install): the real GitHub release feed for this installation and the real per-user cache.
//  - Preview: a fixture release feed; LOCALAPPDATA must be redirected into the preview's sandbox, so the updater
//    cache/preferences/workers never touch the real "DK Engine Updates" folder.
// usage: node update-runner.mjs <engine> <fixture.json | -> <op> [installRoot]
//   op = check | cache | live-check | live-check-auto | cache-live | apply | status | prefs | enable | disable
import fs from 'node:fs';
import path from 'node:path';
import {Readable} from 'node:stream';
import {pathToFileURL} from 'node:url';

const [engine, fixtureFile, op, installRoot] = process.argv.slice(2);
const out = value => process.stdout.write(JSON.stringify(value) + '\n');
const install = process.env.DKCC_MODE === 'install';
if (!install) {
  // LOCALAPPDATA must be a "localappdata" folder inside this preview's sandbox (any preview profile), never the real one.
  const SANDBOX_DIR = path.resolve(import.meta.dirname, '..', '..', '..', 'sandbox');
  const redirected = process.env.LOCALAPPDATA ? path.resolve(process.env.LOCALAPPDATA) : '';
  const rel = redirected ? path.relative(SANDBOX_DIR, redirected) : '..';
  if (!redirected || path.basename(redirected).toLowerCase() !== 'localappdata' || rel.startsWith('..') || path.isAbsolute(rel) || !/[\\/]launcher-redesign-preview[\\/]sandbox[\\/]/i.test(redirected)) { console.error('Refusing to run the updater without the preview LOCALAPPDATA redirect.'); process.exit(2); }
}
if (install && ['check', 'cache'].includes(op)) { console.error('Fixture operations are not available in an installation.'); process.exit(2); }
const updater = await import(pathToFileURL(path.join(engine, 'tools', 'release-update.mjs')).href);
const fixture = fixtureFile && fixtureFile !== '-' ? JSON.parse(fs.readFileSync(fixtureFile, 'utf8')) : {scenario: 'live'};
const current = JSON.parse(fs.readFileSync(path.join(installRoot || engine, 'package.json'), 'utf8')).version;
const fetchMetadata = async () => { if (fixture.scenario === 'offline') throw Error('Fixture: update service offline.'); return fixture.release; };
const openStream = async () => {
  if (fixture.scenario === 'download-fail') throw Error('Fixture: download interrupted.');
  const bytes = fs.readFileSync(fixture.zip);
  if (fixture.scenario === 'hash-mismatch') bytes[bytes.length - 1] ^= 0xff;
  let sent = 0; const chunk = 64 * 1024;
  return Readable.from((function* () { while (sent < bytes.length) { const part = bytes.subarray(sent, sent + chunk); sent += part.length; if (fixture.progressFile) try { fs.writeFileSync(fixture.progressFile, JSON.stringify({bytes: sent, total: bytes.length})); } catch {} yield part; } })());
};
try {
  if (op === 'check') out(await updater.checkRelease({currentVersion: current, fetchMetadata, force: true}));
  else if (op === 'live-check') out(await updater.checkRelease({currentVersion: current, force: true}));          // GitHub, read-only
  else if (op === 'live-check-auto') out(await updater.checkRelease({currentVersion: current, force: false}));    // honours "check on launch"
  else if (op === 'cache') { const c = await updater.checkRelease({currentVersion: current, fetchMetadata, force: true}); if (c.status !== 'available') { out(c); } else out(await updater.cacheRelease(c.candidate, {cache: updater.cacheForInstall(installRoot), openStream})); }
  else if (op === 'cache-live') { if (!install) throw Error('Live downloads are installation-only.'); const c = await updater.checkRelease({currentVersion: current, force: true}); if (c.status !== 'available') { out(c); } else out({...(await updater.cacheRelease(c.candidate, {cache: updater.cacheForInstall(installRoot)})), candidate: c.candidate}); }
  else if (op === 'apply') { const cache = updater.cacheForInstall(installRoot), candidate = await updater.cachedCandidate({cache}); if (!candidate) throw Error('No verified cached release.'); out(await updater.scheduleApply({installRoot, candidate, cache, nodeExecutable: process.execPath})); }
  else if (op === 'status') out(await updater.updateStatus({installRoot}));
  else if (op === 'prefs') out(await updater.preferences());
  else if (op === 'enable') out(await updater.setPreferences({checkOnLaunch: true}));
  else if (op === 'disable') out(await updater.setPreferences({checkOnLaunch: false}));
  else throw Error('Unknown updater operation.');
} catch (error) { console.error(error.message); process.exitCode = 1; }
