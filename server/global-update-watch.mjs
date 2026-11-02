// Live Global update detection (lane L2). DETECT + PARSE ONLY: never swaps live gameplay data.
// Watches the operator Global data root (DEKARON_DATA, else <engine>/../data - the same rule as tools/prepare-client.mjs
// discoverSource). Cheap tick: fs.stat of share/version.ini, pack.hdr and pack.dNN (size+mtime); nothing is read or
// hashed until a stat changes. A change must stay stable for debounceMs before analysis (copy/patch in progress).
// Analysis: diff the index (added/changed/removed), dual-load each changed file - OLD bytes from the applied prepared
// generation (clientSource().dataRoot), NEW bytes from the Global source - with the engine parsers, and table-compat
// the changed tables (old header manifest vs new). Apply = explicit operator action; it only records the accepted
// version (getAppliedGlobalVersion) for the login version gate; regenerating data stays tools/prepare-client.mjs.
import fs from 'node:fs/promises'; import path from 'node:path'; import { createHash } from 'node:crypto';
import { inspectPack } from '../tools/client-pack.mjs';
import { parseMesh } from '../src/formats/mesh.js';
import { parseSkel } from '../src/formats/skel.js';
import { parseAnim } from '../src/formats/anim.js';
import { parseTpack } from '../src/formats/tpack.js';
import { parseMap } from '../src/formats/map.js';
import { parseMel } from '../src/formats/mel.js';
import { parseMal } from '../src/formats/mal.js';
import { parseMac } from '../src/formats/mac.js';
import { parseMonsterDat } from '../tools/build-monsters.mjs';
import { csvHeader, DAT_STRIDES } from '../tools/lib/table-compat.mjs';

const VERSION_KEY = 'share/version.ini';
export function parseVersionIni(buf) {
  if (!buf) return null; const t = Buffer.from(buf).toString('latin1');
  const m = /^\s*VERSION\s*,\s*([^\r\n]+?)\s*$/im.exec(t); return m ? m[1] : null;
}
const PARSERS = { mesh: parseMesh, skel: parseSkel, anim: parseAnim, map: parseMap, mel: parseMel, mal: parseMal, mac: parseMac,
  tpack: b => parseTpack(Buffer.from(b).toString('latin1')) };
const ext = k => (/\.([a-z0-9]+)$/.exec(k) || [, ''])[1];
const word0 = b => b && b.length >= 4 ? '0x' + Buffer.from(b).readUInt32LE(0).toString(16) : null;
/** Format detection + parse with the engine parser; returns {family, version, ok, error} */
export function detectAndParse(key, buf) {
  if (!buf) return null; const e = ext(key); const out = { family: e, version: null, ok: true, error: null };
  try {
    if (['mesh', 'skel', 'anim', 'map'].includes(e)) out.version = word0(buf);
    if (/share\/creature\/monster(64)?\.dat$/.test(key)) { parseMonsterDat(buf); out.version = `record=${buf.length % 4323 === 0 && /64/.test(key) ? 4323 : 2643}`; }
    else if (e === 'dat' && DAT_STRIDES[key]) { if (!DAT_STRIDES[key].some(s => buf.length && buf.length % s === 0)) throw new Error(`size ${buf.length} not a multiple of ${DAT_STRIDES[key]}`); out.version = `stride=${DAT_STRIDES[key]}`; }
    else if (/^share\/skill\/skill\/\d+\.dat$/.test(key)) { if (![12294, 12290].includes(buf.length)) throw new Error(`skill dat size ${buf.length}`); out.version = `size=${buf.length}`; }
    else if (PARSERS[e]) PARSERS[e](new Uint8Array(buf.buffer, buf.byteOffset, buf.length));
  } catch (err) { out.ok = false; out.error = String(err.message || err).slice(0, 200); }
  return out;
}

async function statSig(file) { try { const s = await fs.stat(file); return `${s.size}:${Math.floor(s.mtimeMs)}`; } catch { return '-'; } }
/** Cheap signature of the watched root (no reads). */
export async function rootSignature(root) {
  let names = []; try { names = (await fs.readdir(root)).filter(n => /^pack\.(hdr|d\d\d)$/i.test(n)).sort(); } catch {}
  const parts = [`v=${await statSig(path.join(root, VERSION_KEY))}`];
  for (const n of names) parts.push(`${n}=${await statSig(path.join(root, n))}`);
  return parts.join('|');
}

/** Index of the source: pack -> Map(key -> {pack,offset,size}); loose -> Map(key -> {size,mtime}). */
export async function buildIndex(root) {
  const map = new Map();
  if (await fs.stat(path.join(root, 'pack.hdr')).then(() => true, () => false)) {
    const p = await inspectPack(root); for (const e of p.entries) map.set(e.rel, { pack: e.pack, offset: e.offset, size: e.size });
    return { kind: 'pack', map };
  }
  const walk = async (rel) => { for (const d of await fs.readdir(path.join(root, rel), { withFileTypes: true }).catch(() => [])) {
    const r = rel ? `${rel}/${d.name}` : d.name; if (d.isSymbolicLink()) continue;
    if (d.isDirectory()) await walk(r); else if (d.isFile()) { const s = await fs.stat(path.join(root, r)); map.set(r.toLowerCase(), { file: r, size: s.size, mtime: Math.floor(s.mtimeMs) }); } } };
  await walk(''); return { kind: 'loose', map };
}
async function readEntry(root, idx, key) {
  const e = idx.map.get(key); if (!e) return null;
  if (idx.kind === 'loose') return fs.readFile(path.join(root, e.file));
  const h = await fs.open(path.join(root, e.pack), 'r'); try { const b = Buffer.alloc(e.size); await h.read(b, 0, e.size, e.offset); return b; } finally { await h.close(); }
}
const sha = b => createHash('sha256').update(b).digest('hex');
export async function diffIndex(root, oldIdx, newIdx) {
  const added = [], removed = [], changed = [];
  for (const k of newIdx.map.keys()) if (!oldIdx.map.has(k)) added.push(k);
  for (const k of oldIdx.map.keys()) if (!newIdx.map.has(k)) removed.push(k);
  for (const [k, n] of newIdx.map) { const o = oldIdx.map.get(k); if (!o) continue;
    if (oldIdx.kind === 'loose' && newIdx.kind === 'loose') { if (o.size !== n.size || o.mtime !== n.mtime) changed.push(k); }
    else if (o.size !== n.size || o.offset !== n.offset || o.pack !== n.pack) changed.push(k); }
  return { added: added.sort(), removed: removed.sort(), changed: changed.sort() };
}

export function createGlobalUpdateWatch({ root, appliedDataRoot = null, intervalMs = 5000, debounceMs = 15000, now = () => Date.now(), maxParse = 20000, log = () => {} } = {}) {
  const state = { root: root ? path.resolve(root) : null, status: 'idle', baseline: null, report: null, appliedVersion: null, pendingSince: null, ticks: 0, analyses: 0, lastError: null };
  let sig = null, pendSig = null, timer = null, busy = false, baseIdx = null;
  async function readVersion(idx = baseIdx) { // loose share/version.ini first, else the packed entry (pack.d04 in Global)
    const loose = await fs.readFile(path.join(state.root, VERSION_KEY)).catch(() => null);
    return parseVersionIni(loose ?? (idx ? await readEntry(state.root, idx, VERSION_KEY).catch(() => null) : null)); }
  async function init() {
    if (!state.root) { state.status = 'unconfigured'; return; }
    sig = await rootSignature(state.root); baseIdx = await buildIndex(state.root).catch(e => (state.lastError = e.message, null));
    state.baseline = { version: await readVersion(), signature: sig, files: baseIdx?.map.size ?? 0, at: new Date(now()).toISOString() };
    state.appliedVersion ??= state.baseline.version; state.status = 'watching';
  }
  async function analyze(newSig) {
    state.status = 'analyzing'; const t0 = process.cpuUsage(); const w0 = performance.now();
    const newIdx = await buildIndex(state.root); const d = await diffIndex(state.root, baseIdx, newIdx);
    // Same pack slot (pack/offset/size) inside a pack file whose stat changed may still hold new bytes (in-place patch).
    // Hash only those slots, and only for tables/scripts/version (share/, script/) up to 1 MiB, against the applied generation;
    // other same-slot entries are counted as unverifiedSameSlot (old bytes are gone once the pack is rewritten).
    let unverifiedSameSlot = 0;
    if (newIdx.kind === 'pack') {
      const oldParts = new Map(String(state.baseline.signature).split('|').map(x => x.split('='))), newParts = new Map(String(newSig).split('|').map(x => x.split('=')));
      const touched = new Set([...newParts.keys()].filter(k => /^pack\.d\d\d$/i.test(k) && oldParts.get(k) !== newParts.get(k)));
      const already = new Set([...d.added, ...d.changed]);
      for (const [k, n] of newIdx.map) {
        if (already.has(k) || !touched.has(n.pack) || !baseIdx.map.has(k)) continue;
        if (!appliedDataRoot || !/^(share|script)\//.test(k) || n.size > 1 << 20) { unverifiedSameSlot++; continue; }
        const ob = await fs.readFile(path.join(appliedDataRoot, k)).catch(() => null), nb = await readEntry(state.root, newIdx, k);
        if (!ob) { unverifiedSameSlot++; continue; } if (sha(ob) !== sha(nb)) d.changed.push(k);
      }
      d.changed.sort();
    }
    const files = [...d.added, ...d.changed].slice(0, maxParse), results = [], failures = [], compat = [];
    // PING-FLAT: yield every 8 parses so move/command handlers are not stalled by a long analyze on the event loop.
    for (let fi = 0; fi < files.length; fi++) {
      const k = files[fi];
      const nb = await readEntry(state.root, newIdx, k);
      const ob = appliedDataRoot ? await fs.readFile(path.join(appliedDataRoot, k)).catch(() => null) : null;
      if (ob && nb && ob.length === nb.length && sha(ob) === sha(nb) && d.changed.includes(k)) { results.push({ key: k, same: true }); if ((fi & 7) === 7) await new Promise(r => setImmediate(r)); continue; }
      const oldR = detectAndParse(k, ob), newR = detectAndParse(k, nb);
      results.push({ key: k, old: oldR, new: newR });
      if (newR && !newR.ok) failures.push({ key: k, family: newR.family, version: newR.version, error: newR.error, oldVersion: oldR?.version ?? null });
      if (k.endsWith('.csv') && ob && nb) { const oc = csvHeader(ob), nc = new Set(csvHeader(nb)); const missing = oc.filter(c => c && !nc.has(c));
        if (missing.length) compat.push({ file: k, code: 'columns-missing', columns: missing.slice(0, 20) }); }
      if ((fi & 7) === 7) await new Promise(r => setImmediate(r));
    }
    for (const k of d.removed) compat.push({ file: k, code: 'table-missing' });
    const cpu = process.cpuUsage(t0);
    state.report = { detectedAt: new Date(now()).toISOString(), root: state.root, oldVersion: state.baseline.version, newVersion: await readVersion(newIdx),
      counts: { added: d.added.length, changed: d.changed.length, removed: d.removed.length, parsed: results.length, identical: results.filter(r => r.same).length, parseFailures: failures.length, compatIssues: compat.length, truncated: Math.max(0, d.added.length + d.changed.length - files.length), unverifiedSameSlot },
      added: d.added.slice(0, 500), changed: d.changed.slice(0, 500), removed: d.removed.slice(0, 500), failures: failures.slice(0, 500), compat: compat.slice(0, 500),
      versions: results.filter(r => !r.same && (r.old?.version || r.new?.version) && r.old?.version !== r.new?.version).slice(0, 500).map(r => ({ key: r.key, old: r.old?.version ?? null, new: r.new?.version ?? null })),
      cost: { cpuUserMs: cpu.user / 1000, cpuSystemMs: cpu.system / 1000, wallMs: Math.round(performance.now() - w0) }, applied: false };
    state.pending = { signature: newSig, index: newIdx }; state.analyses++; state.status = 'update-detected';
    log(`[global-update] ${state.report.oldVersion} -> ${state.report.newVersion}: +${d.added.length} ~${d.changed.length} -${d.removed.length}, ${failures.length} parse failures`);
  }
  async function tick() {
    if (busy || !state.root) return; busy = true; state.ticks++;
    try {
      if (!sig) await init();
      const s = await rootSignature(state.root);
      const ref = state.pending?.signature ?? sig;
      if (s === ref) { pendSig = null; state.pendingSince = null; return; }
      if (s !== pendSig) { pendSig = s; state.pendingSince = now(); state.status = state.report ? state.status : 'change-pending'; return; } // restart debounce
      if (now() - state.pendingSince < debounceMs) return;
      pendSig = null; state.pendingSince = null; await new Promise(r => setImmediate(r)); await analyze(s); // PING-FLAT: leave watch interval before heavy parse
    } catch (e) { state.lastError = String(e.message || e); state.status = 'error'; } finally { busy = false; }
  }
  /** Operator action: accept the detected update. No live data is swapped; the login gate version follows. */
  function apply() {
    if (!state.report || !state.pending) return { ok: false, error: 'No detected update to apply.' };
    state.appliedVersion = state.report.newVersion; state.report.applied = true; state.report.appliedAt = new Date(now()).toISOString();
    sig = state.pending.signature; baseIdx = state.pending.index; state.baseline = { version: state.report.newVersion, signature: sig, files: baseIdx.map.size, at: state.report.appliedAt };
    state.pending = null; state.status = 'watching';
    return { ok: true, appliedVersion: state.appliedVersion, next: 'Run tools/prepare-client.mjs to build a new generation, then restart; live data was not changed.' };
  }
  function status() { const { pending, ...s } = state; return { ...s, report: state.report }; }
  return {
    start() { if (!timer && state.root) { timer = setInterval(() => void tick(), intervalMs); timer.unref?.(); void tick(); } return this; },
    stop() { clearInterval(timer); timer = null; }, tick, init, apply, status,
    getAppliedGlobalVersion: () => state.appliedVersion,
    /** HTTP: GET /api/global-update/status, POST /api/global-update/apply (loopback only; caller enforces). */
    async handle(req, res, pathname, { isLocal = false } = {}) {
      if (!pathname.startsWith('/api/global-update/')) return false;
      const send = (c, v) => { res.writeHead(c, { 'Content-Type': 'application/json; charset=utf-8', 'Cache-Control': 'no-store' }); res.end(JSON.stringify(v)); };
      if (!isLocal || req.relay) { send(403, { error: 'Private local status only.' }); return true; }
      if (pathname === '/api/global-update/status' && req.method === 'GET') { send(200, status()); return true; }
      if (pathname === '/api/global-update/apply' && req.method === 'POST') { const r = apply(); send(r.ok ? 200 : 409, r); return true; }
      send(404, { error: 'not found' }); return true;
    },
  };
}
