// Vault: the persistence writer service (SERVER-SPLIT-DESIGN.md Phase B step 2). Clean-room, our own code.
// Opt-in with DK_VAULT=1. Without it nothing here runs and the account store keeps today's in-process journal.
//
// Realm side of the stream. Same interface as createEntityJournal (recover / append / checkpoint / due / busy / seq / stats /
// close), so accounts/api.mjs only chooses the factory. What changes when it is on:
//  * append(rec): Realm stringifies only the dirty records of one commit group (the delta it already journals today) and posts
//    that string to the Vault worker. The worker appends + fsyncs the journal line and applies the delta to its own copy of
//    the store. The commit is acknowledged only after that line is durable, exactly as before.
//  * checkpoint(): the worker serializes ITS copy and writes temp + fsync + rename, then compacts the journal. Realm's main
//    thread does no store serialization and no file I/O for it (today: ~140 ms of 3-14 ms slices + 4 MiB buffer copies).
//  * checkpoint(store, at, {replace:true}) (rare full-store transactions): Realm streams the new store as the same sliced JSON
//    text the old checkpoint produced (same slice budget), never as one structured clone.
//  * If the worker dies or rejects its start, Vault drops journal lines that were never acknowledged and continues with the
//    in-process journal from the last acknowledged seq (the old path), logged once.
import { Worker } from 'node:worker_threads';
import fsp from 'node:fs/promises';
import path from 'node:path';
import { createEntityJournal } from '../../accounts/entity-journal.mjs';
import { serializeStoreChunks } from '../../accounts/atomic-store.mjs';
import { assertPrivateAccountDirectory } from '../../accounts/private-directory.mjs';
import { setImmediate as yieldTurn } from 'node:timers/promises';

import { vaultAllowed } from './cores.mjs';   // NETX4: Vault only when the worker budget allows it (cores.mjs)
export const vaultEnabled = (env = process.env) => vaultAllowed(env);

// ENGINE-CHOSEN main-thread budget per slice while turning a delta into text (one record is never split).
const DELTA_SLICE_MS = 1;
const plain = v => v !== null && typeof v === 'object' && !Array.isArray(v) && [Object.prototype, null].includes(Object.getPrototypeOf(v)) && !Object.hasOwn(v, 'toJSON');
/** Byte-identical to JSON.stringify(rec) for journal records {c:{collection:{key:value}}, t:{key:value}}: written piece by piece
 *  (account records down DELTA_DEPTH levels into plain objects/arrays, so a 300 KB account is not one piece) and
 *  yielding after each ~1 ms so a big commit group (up to 128 bot profiles) never blocks the tick in one piece.
 *  Leaves go through JSON.stringify itself, so escaping/toJSON/omission rules are the same. Committed values do not change while we yield. */
const DELTA_DEPTH = 4;
const isArr = v => Array.isArray(v) && Object.getPrototypeOf(v) === Array.prototype && !Object.hasOwn(v, 'toJSON');
export async function deltaText(rec, sliceMs = DELTA_SLICE_MS) {
  const start = performance.now();
  let t0 = start, slices = 1, maxSlice = 0, total = 0;
  const tick = async () => {
    const now = performance.now();
    if (now - t0 >= sliceMs) { maxSlice = Math.max(maxSlice, now - t0); total += now - t0; await yieldTurn(); t0 = performance.now(); slices++; }
  };
  // returns undefined where JSON.stringify would (undefined / function / symbol values)
  const val = async (v, depth) => {
    if (depth > 0 && plain(v)) {
      const out = [];
      for (const k of Object.keys(v)) {
        const s = await val(v[k], depth - 1);
        if (s !== undefined) out.push(JSON.stringify(k) + ':' + s);
        await tick();
      }
      return '{' + out.join(',') + '}';
    }
    if (depth > 0 && isArr(v)) {
      const out = new Array(v.length);
      for (let i = 0; i < v.length; i++) { const s = await val(v[i], depth - 1); out[i] = s === undefined ? 'null' : s; await tick(); }
      return '[' + out.join(',') + ']';
    }
    return JSON.stringify(v);
  };
  let text;
  if (!plain(rec) || Object.keys(rec).join() !== 'c,t' || !plain(rec.c) || !plain(rec.t) || !Object.values(rec.c).every(plain)) text = JSON.stringify(rec);
  else {
    // Small records (bot profiles ~5 KB, sessions) are one JSON.stringify each: cheapest in total. Only account records
    // (up to ~300 KB) are written field by field, so one of them is never a multi-ms piece.
    const cols = [];
    for (const col of Object.keys(rec.c)) {
      const coll = rec.c[col], out = [], depth = col === 'users' ? DELTA_DEPTH : 0;
      for (const k of Object.keys(coll)) { const s = await val(coll[k], depth); if (s !== undefined) out.push(JSON.stringify(k) + ':' + s); await tick(); }
      cols.push(JSON.stringify(col) + ':{' + out.join(',') + '}');
    }
    text = '{"c":{' + cols.join(',') + '},"t":' + await val(rec.t, 1) + '}';
  }
  const tail = performance.now() - t0;
  deltaText.lastSlices = slices; deltaText.lastMaxSliceMs = Math.max(maxSlice, tail); deltaText.lastTotalMs = total + tail;
  return text;
}

export function createVaultJournal({ file, writeCheckpoint, checkpointMs = 30000, checkpointBytes = 64 * 1024 * 1024, log = message => console.error(message), onCheckpoint = null } = {}) {
  const journalFile = file + '.journal';
  let seq = 0, bytes = 0, lastCheckpoint = Date.now(), checkpointing = null, closed = false;
  let worker = null, nextId = 1, inner = null, failing = null;
  const pending = new Map();
  const vault = { mode: 'worker', started: false, posts: 0, mainMsTotal: 0, mainMsMax: 0, mainOver2: 0, slicesMax: 0, ackMsMax: 0, workerCheckpointMs: null, failures: 0, lastError: null };
  const stats = { appends: 0, appendBytes: 0, checkpoints: 0, lastCheckpointMs: null, replayed: 0, vault };

  function start() {
    const w = new Worker(new URL('./vault-worker.mjs', import.meta.url), {
      workerData: { file, checkpointMs, checkpointBytes, expectSeq: seq, testHooks: process.env.DK_VAULT_TEST_HOOKS === '1' },
      // The private-directory pin is a process-wide OS handle; Realm checks it (assertPrivateAccountDirectory) before every
      // checkpoint request, the worker's own module copy has no pin table of its own.
      env: { ...process.env, DEKARON_PRIVATE_ACCOUNT_DIR: '0' },
    });
    w.unref();
    w.on('message', m => {
      const p = pending.get(m.id); if (!p) return;
      pending.delete(m.id); if (!pending.size) w.unref();
      if (m.ok) p.resolve(m);
      else { const error = Object.assign(new Error(m.error || 'Vault write failed.'), { code: m.code || 'EVAULT' }); p.reject(error); if (m.fatal) fail(w, error); }
    });
    w.on('error', error => fail(w, error));
    w.on('messageerror', error => fail(w, error));
    w.on('exit', code => { if (!closed || pending.size) fail(w, new Error(`Vault worker exited (${code}).`)); });
    worker = w; vault.started = true;
  }
  function post(msg) { if (failing) return; if (!worker) start(); worker.postMessage(msg); }
  function send(msg) {
    if (failing) return Promise.reject(Object.assign(new Error(`Vault unavailable: ${vault.lastError}`), { code: 'EVAULT' }));
    if (!worker) start();
    const id = nextId++, w = worker;
    return new Promise((resolve, reject) => { if (!pending.size) w.ref(); pending.set(id, { resolve, reject }); w.postMessage({ ...msg, id }); });
  }
  function fail(w, error) {
    if (w !== worker || failing) return;
    vault.failures++; vault.lastError = String(error?.message || error);
    for (const p of pending.values()) p.reject(Object.assign(new Error(`Vault unavailable: ${vault.lastError}`), { code: 'EVAULT' }));
    pending.clear();
    failing = switchToInProcess(w, error);
    failing.catch(e => log(`[vault] fallback failed; account saves will error: ${e?.message || e}`));
  }
  // Disk after an acknowledged seq S is: checkpoint + journal lines <= S, plus possibly lines the worker wrote but never
  // acknowledged (their transactions were rolled back in memory). Drop those, then keep journaling in-process from S.
  async function switchToInProcess(w, error) {
    const S = seq; vault.mode = 'fallback';
    log(`[vault] worker failed (${error?.message || error}); continuing with the in-process journal from seq ${S}`);
    await w.terminate().catch(() => {});
    await new Promise(r => setTimeout(r, 50));   // let fs requests already queued by the worker settle
    await truncateJournalAfter(S);
    const j = createEntityJournal({ file, writeCheckpoint, checkpointMs, checkpointBytes, log, onCheckpoint });
    await j.recover({ journalSeq: S });
    if (j.seq !== S) throw new Error(`Vault fallback seq ${j.seq} != ${S}`);
    inner = j;
  }
  async function truncateJournalAfter(S) {
    let text = ''; try { text = await fsp.readFile(journalFile, 'utf8'); } catch (e) { if (e.code === 'ENOENT') return; throw e; }
    const lines = text.split('\n'), keep = [];
    let dropped = 0;
    for (const l of lines) { if (!l) continue; let s = null; try { s = JSON.parse(l).s; } catch {} if (Number.isInteger(s) && s <= S) keep.push(l); else dropped++; }
    if (!dropped) return;
    const tmp = journalFile + '.vault.tmp', h = await fsp.open(tmp, 'w', 0o600);
    try { await h.write(keep.length ? keep.join('\n') + '\n' : ''); await h.sync(); } finally { await h.close(); }
    await fsp.rename(tmp, journalFile);
    try { const d = await fsp.open(path.dirname(journalFile), 'r'); try { await d.sync(); } finally { await d.close(); } } catch {}
    log(`[vault] dropped ${dropped} unacknowledged journal line(s) after seq ${S}`);
  }
  const viaInner = fn => (failing || Promise.reject(new Error('Vault unavailable.'))).then(() => fn(inner));

  return {
    journalFile, stats,
    get seq() { return inner ? inner.seq : seq; },
    get busy() { return inner ? inner.busy : !!checkpointing; },
    /** Main-thread recovery, identical to createEntityJournal.recover; the worker rebuilds its copy from the same files. */
    async recover(state) {
      const j = createEntityJournal({ file, writeCheckpoint: async () => {} });
      await j.recover(state); seq = j.seq; stats.replayed = j.stats.replayed;
      try { bytes = (await fsp.stat(journalFile)).size; } catch { bytes = 0; }
      return state;
    },
    /** Durable when it resolves: the worker fsynced the line. Main thread: the delta's text in <= ~1 ms slices + one postMessage. */
    append(rec) {
      if (inner || failing) return viaInner(j => j.append(rec));
      const t0 = performance.now();
      return deltaText(rec).then(async text => {
        const lastSlice = deltaText.lastMaxSliceMs || 0;
        if (text.length > 65536) await yieldTurn();   // big delta: the postMessage copy gets its own turn, not stacked on the last slice
        if (inner || failing) return viaInner(j => j.append(rec));
        const t1 = performance.now(), p = send({ op: 'append', text }), postMs = performance.now() - t1;
        const sliceMs = text.length > 65536 ? Math.max(lastSlice, postMs) : lastSlice + postMs;   // worst synchronous piece of this save
        vault.posts++; vault.mainMsTotal += (deltaText.lastTotalMs || 0) + postMs; if (sliceMs > vault.mainMsMax) vault.mainMsMax = sliceMs;
        if (sliceMs > 2) vault.mainOver2++;
        if ((deltaText.lastSlices || 1) > vault.slicesMax) vault.slicesMax = deltaText.lastSlices || 1;
        return p.then(m => { seq = m.s; const n = text.length + 12; bytes += n; stats.appends++; stats.appendBytes += n; const ack = performance.now() - t0; if (ack > vault.ackMsMax) vault.ackMsMax = ack; });
      });
    },
    checkpoint(snapshot, at = this.seq, options = {}) {
      if (inner || failing) return viaInner(j => j.checkpoint(snapshot, at));
      if (checkpointing) return checkpointing.then(() => this.checkpoint(snapshot, at, options));
      assertPrivateAccountDirectory(file);
      const t0 = Date.now(), before = bytes;
      checkpointing = (async () => {
        let m;
        if (options?.replace) {
          // Same 4 ms / 512-step sliced serializer the in-process checkpoint runs on this thread today; chunks are strings.
          const rid = nextId++; post({ op: 'replaceBegin', id: rid });
          for await (const chunk of serializeStoreChunks(snapshot, null, true)) post({ op: 'replaceChunk', id: rid, text: chunk });
          m = await send({ op: 'replaceEnd', rid, at });
        } else m = await send({ op: 'checkpoint' });
        bytes = Math.max(0, bytes - before); lastCheckpoint = Date.now(); stats.checkpoints++; stats.lastCheckpointMs = Date.now() - t0; vault.workerCheckpointMs = m.ms ?? null;
        onCheckpoint?.(m.at ?? at);
      })().finally(() => { checkpointing = null; });
      return checkpointing;
    },
    due() {
      if (inner) return inner.due();
      return !closed && !failing && !checkpointing && seq > 0 && (bytes >= checkpointBytes || Date.now() - lastCheckpoint >= checkpointMs);
    },
    async close() {
      if (inner || failing) { closed = true; return viaInner(j => j.close()).catch(() => {}); }
      await checkpointing?.catch(() => {});
      closed = true;
      if (worker) { await send({ op: 'close' }).catch(() => {}); await worker.terminate().catch(() => {}); }
    },
    /** Test hook only (DK_VAULT_TEST_HOOKS=1): make the worker thread exit as if it crashed. */
    _testCrashWorker() { if (process.env.DK_VAULT_TEST_HOOKS === '1' && worker) worker.postMessage({ op: 'crash' }); },
  };
}
