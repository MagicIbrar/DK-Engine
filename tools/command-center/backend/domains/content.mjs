// Global data selection/preparation status, read-only integrity verification, structural compatibility, content overrides,
// per-account game-window state and small content previews from tables the existing loaders already produce.
import fs from 'node:fs';
import fsp from 'node:fs/promises';
import path from 'node:path';
import {createHash} from 'node:crypto';
import {pathToFileURL} from 'node:url';
import {ENGINE, MAIN, PROFILE, INSTALL, writable, inside} from '../core/paths.mjs';
import {define, v, ACCOUNT_ID} from '../core/rpc.mjs';
import {readJson, writeJson, UserError, clip} from '../core/util.mjs';
import {startJob} from '../core/jobs.mjs';
import {event} from '../core/events.mjs';
import {preparedReadiness} from './world.mjs';

const mod = rel => import(pathToFileURL(path.join(ENGINE, rel)).href);
const INTEGRITY = path.join(PROFILE, 'integrity.json');
async function source() {
  const {clientSource} = await mod('server/client-source.mjs'); const s = clientSource(ENGINE);
  const cfg = JSON.parse(await fsp.readFile(path.join(ENGINE, 'dedicated-source.json'), 'utf8'));
  return {...s, sourceEngine: path.resolve(ENGINE, cfg.sourceEngine)};
}
async function globalStatus() {
  const s = await source(), m = s.manifest || {};
  const readiness = await preparedReadiness();
  const last = await readJson(INTEGRITY, null);
  let mainVersion = null; try { mainVersion = JSON.parse(await fsp.readFile(path.join(MAIN, 'package.json'), 'utf8')).version; } catch {}
  return {selected: {kind: 'dedicated prepared generation', sourceEngine: s.sourceEngine, readOnly: true, note: INSTALL ? 'DK Command Center reads this installation\'s prepared Global generation in place; verification never writes it.' : 'The preview reads the installed game\'s prepared Global generation in place. It never prepares, repairs or writes it.'},
    generation: m.generation, fingerprint: s.version, sourceFingerprint: m.sourceFingerprint, sourceKind: m.source?.kind, prepared: m.prepared, files: m.files ?? null, bytes: m.bytes ?? null, portable: !!m.portablePrepared,
    readiness, lastIntegrity: last, installedVersion: INSTALL ? null : mainVersion,
    preparation: {available: false, reason: INSTALL ? 'Preparing or repairing Global data rebuilds a ~10 GB generation from the original Global folder. It runs from the setup path: open Client.exe in the DK download folder (DK-<version>\\Engine); accounts and settings are kept.' : 'Preparing or repairing Global data rebuilds a ~10 GB generation from the original Global folder. In the Test Preview this is disabled so Main\'s prepared data is never rewritten; the integrated launcher keeps the existing Start/Setup preparation path.'}};
}
async function receiptFor(s) {
  const run = path.join(MAIN, 'run'); let best = null;
  for (const name of await fsp.readdir(run).catch(() => [])) {
    if (!/^asset-preload-[a-f0-9]{64}\.json$/.test(name)) continue;
    const st = await fsp.stat(path.join(run, name)); if (st.size > 256 * 1024 * 1024) continue;
    const r = JSON.parse(await fsp.readFile(path.join(run, name), 'utf8'));
    if (r.version === 1 && r.sourceVersion === s.version && Array.isArray(r.entries) && (!best || st.mtimeMs > best.mtime)) best = {name, receipt: r, mtime: st.mtimeMs};
  }
  return best;
}
function verifyJob() {
  return startJob({kind: 'content.verify', key: 'content.verify', area: 'content', title: 'Verify prepared Global data (read-only)', run: async ctx => {
    ctx.phase('Find reference', INSTALL ? 'Looking for this installation\'s verification receipt for this generation' : 'Looking for the installed game\'s own verification receipt for this generation');
    const s = await source(), found = await receiptFor(s);
    if (!found) throw new Error(INSTALL ? 'No verification receipt exists for this generation yet. One is created on the first DX11 game start; play once, then verify.' : 'No verification receipt exists for this generation yet. The installed launcher creates one on its first DX11 start; the preview does not write into Main.');
    const roots = {data: s.dataRoot, gamedata: s.gamedataRoot, ...(s.siteAssetRoot ? {'site-assets': s.siteAssetRoot} : {}), ...(s.looseSoundRoot ? {'sound-assets': s.looseSoundRoot} : {})};
    const entries = found.receipt.entries, total = entries.reduce((a, e) => a + e.bytes, 0);
    ctx.log(`Reference: Main/run/${found.name} (${entries.length} files, ${(total / 1073741824).toFixed(2)} GiB).`);
    ctx.phase('Read and hash', INSTALL ? 'Reading every prepared byte once (SHA-256). Nothing is written.' : 'Reading every prepared byte once (SHA-256). Nothing is written to Main.');
    let bytes = 0, files = 0, cursor = 0; const failures = [], t0 = Date.now();
    const work = async () => {
      while (cursor < entries.length && failures.length < 25) {
        ctx.throwIfCancelled(); const e = entries[cursor++]; const slash = e.file.indexOf('/'), root = roots[e.file.slice(0, slash)];
        if (!root) { failures.push({file: e.file, problem: 'root not present in this generation'}); continue; }
        const full = path.join(root, e.file.slice(slash + 1));
        try {
          const h = createHash('sha256'); let read = 0;
          for await (const chunk of fs.createReadStream(full, {highWaterMark: 256 * 1024})) { h.update(chunk); read += chunk.length; bytes += chunk.length; }
          if (read !== e.bytes) failures.push({file: e.file, problem: `size ${read} != ${e.bytes}`}); else if (h.digest('hex') !== e.sha256) failures.push({file: e.file, problem: 'checksum differs'});
        } catch (err) { failures.push({file: e.file, problem: err.code === 'ENOENT' ? 'missing' : 'unreadable'}); }
        files++; if (files % 200 === 0) { ctx.progress(Math.round(bytes / 1048576), Math.round(total / 1048576), 'MiB verified'); ctx.message(`${files.toLocaleString()} / ${entries.length.toLocaleString()} files`); }
      }
    };
    await Promise.all(Array.from({length: 8}, work));
    ctx.progress(Math.round(bytes / 1048576), Math.round(total / 1048576), 'MiB verified');
    const result = {at: Date.now(), generation: s.manifest?.generation, reference: found.name, files, totalFiles: entries.length, bytes, totalBytes: total, ok: !failures.length && files === entries.length, failures, seconds: Math.round((Date.now() - t0) / 100) / 10, scope: 'SHA-256 of every prepared file compared with ' + (INSTALL ? 'this installation\'s' : 'the installed game\'s own') + ' receipt. Read-only; not a gameplay or rendering test.'};
    await writeJson(INTEGRITY, result);
    event(result.ok ? 'ok' : 'error', 'content', result.ok ? `Prepared data verified: ${files.toLocaleString()} files, ${(bytes / 1073741824).toFixed(2)} GiB in ${result.seconds} s.` : `Prepared data verification found ${failures.length} problem(s).`);
    return result;
  }});
}
async function overrides() {
  const {worldStorageFiles} = await mod('server/world-storage.mjs');
  const out = [];
  for (const [scope, store] of [['Local world', path.join(ENGINE, 'server', 'accounts', 'data.json')], ['Hosted world', path.join(ENGINE, 'server', 'accounts', 'friends-accounts.json')]]) {
    const f = worldStorageFiles({engine: ENGINE, accountStore: store});
    const describe = async (kind, p, isDir) => {
      try { const st = await fsp.stat(p); if (isDir) { const names = await fsp.readdir(p); return {kind, path: path.relative(ENGINE, p), exists: true, entries: names.length}; }
        let items = null, valid = null; try { const j = JSON.parse(await fsp.readFile(p, 'utf8')); items = Array.isArray(j.items) ? j.items.length : null; valid = j.format === 'dekaron-online-custom-items' && j.version === 1; } catch { valid = false; }
        return {kind, path: path.relative(ENGINE, p), exists: true, bytes: st.size, items, valid}; }
      catch { return {kind, path: path.relative(ENGINE, p), exists: false}; }
    };
    out.push({scope, libraries: [await describe('Custom items', f.customItemsFile, false), await describe('Custom models (GLB)', f.customAssetsRoot, true), await describe('Custom maps', f.customMapsRoot, true), await describe('Original-map overlays', f.originalEditRoot, true)]});
  }
  return {worlds: out, precedence: ['Original Global data (read-only, never edited)', 'Prepared generation built from it (read-only here)', 'This world\'s authored libraries: custom items, GLB models, custom maps and overlays on original maps (per account store)'], note: 'Authored content is created in-game with Item Builder and Map Builder and validated by the engine when saved. The launcher lists it; it does not edit it.'};
}
async function windowStates() {
  const dir = path.join(ENGINE, 'runtime', 'native-profiles'); const out = [];
  for (const name of await fsp.readdir(dir).catch(() => [])) { if (!name.endsWith('.window')) continue; const text = (await fsp.readFile(path.join(dir, name), 'utf8')).trim(); const m = /^(\d{3,5})x(\d{3,5})( fullscreen)?$/.exec(text); out.push({profile: name.slice(0, -7), width: m ? +m[1] : null, height: m ? +m[2] : null, fullscreen: !!m?.[3], raw: clip(text, 40)}); }
  return out;
}
async function previews({table, search = ''}) {
  const s = await source(); const q = search.toLowerCase();
  if (table === 'maps') {
    const text = await fsp.readFile(path.join(s.dataRoot, 'share', 'maplist.csv'));
    const {decodeText, parseCSV} = await mod('src/formats/binreader.js'); const rows = parseCSV(decodeText(text, true));
    const head = rows[0] || [], iI = head.indexOf('Index'), iN = head.indexOf('Name'), iF = head.indexOf('MapFile');
    const items = rows.slice(1).filter(r => r.length > 2 && r[iI]).map(r => ({index: r[iI], name: r[iN], file: r[iF]})).filter(r => !q || `${r.index} ${r.name} ${r.file}`.toLowerCase().includes(q));
    return {table, total: items.length, rows: items.slice(0, 200), source: 'data/share/maplist.csv (prepared copy, read-only)'};
  }
  if (table === 'classes') {
    const j = JSON.parse(await fsp.readFile(path.join(s.gamedataRoot, 'classes.json'), 'utf8'));
    const rows = (j.classes || []).map(c => ({index: c.index, name: c.name})).filter(r => !q || `${r.index} ${r.name}`.toLowerCase().includes(q));
    return {table, total: rows.length, rows, source: 'gamedata/classes.json'};
  }
  const st = await fsp.stat(path.join(s.gamedataRoot, 'items.json'));
  return {table: 'items', total: null, rows: [], note: `items.json is ${(st.size / 1048576).toFixed(1)} MB; it is not loaded into the launcher. Use Item Builder in game.`};
}

define('content.global', {input: v.object({}), timeoutMs: 30000, run: globalStatus});
define('content.verify', {input: v.object({}), run: async () => verifyJob()});
define('content.compat', {input: v.object({}), timeoutMs: 120000, run: async () => { const s = await source(); const {inspectGlobalCompatibility} = await mod('tools/client-compatibility.mjs'); const t0 = Date.now(); const r = await inspectGlobalCompatibility({dataRoot: s.dataRoot}); return {...r, inputs: r.inputs.map(({sha256, ...i}) => ({...i, sha256: sha256?.slice(0, 12)})), ms: Date.now() - t0, note: 'Recognizing a layout does not mean a new Global format works; builders and runtime tests remain responsible.'}; }});
define('content.overrides', {input: v.object({}), run: overrides});
define('content.windows', {input: v.object({}), run: async () => ({profiles: await windowStates(), note: 'Saved by the DX11 window per account (Options > resolution / window mode / F11). Resetting restores 1280x720 windowed on next open.'})});
define('content.windows.reset', {input: v.object({profile: v.string({min: 1, max: 40, pattern: /^[a-z0-9_-]{1,40}$/})}), run: async ({profile}) => { const f = path.join(ENGINE, 'runtime', 'native-profiles', profile + '.window'); writable(f); await fsp.rm(f, {force: true}); event('info', 'content', `Game window size reset for ${profile}.`); return {reset: profile}; }});
define('content.preview', {input: v.object({table: v.enum(['maps', 'classes', 'items']), search: v.optional(v.string({max: 64}))}), timeoutMs: 30000, run: previews});
