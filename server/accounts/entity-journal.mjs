// PERSIST-PERF per-entity persistence for the atomic JSON account store (GG decision, 2026-10-19).
// Each commit group appends ONE fsynced line holding only the entities it changed (users / sessions / npcProfiles entries and
// changed top-level values), like Global's per-object Flush pipelines. The full store file becomes a checkpoint, written in the
// background (temp + fsync + rename via writeAtomicStore) every `checkpointMs` or `checkpointBytes` of journal, and at shutdown.
// Recovery = checkpoint + replay of journal lines with seq > checkpoint.journalSeq. Ops are absolute "set key = value / delete",
// so replaying over a checkpoint that already contains a later change is idempotent (fuzzy checkpoint is safe).
// A torn last line (crash during append) was never fsynced, hence never acknowledged, and is ignored.
import fsp from 'node:fs/promises';
import fs from 'node:fs';
import path from 'node:path';
export const JOURNAL_COLLECTIONS = ['users', 'sessions', 'npcProfiles'];

export function applyJournalRecord(state, rec) {
  for (const [col, entries] of Object.entries(rec.c || {})) {
    const target = (state[col] && typeof state[col] === 'object') ? state[col] : (state[col] = {});
    for (const [k, v] of Object.entries(entries)) { if (v === null) delete target[k]; else target[k] = v; }
  }
  for (const [k, v] of Object.entries(rec.t || {})) { if (v === null) delete state[k]; else state[k] = v; }
  return state;
}

/** Diff two store states. `hint` = { users, sessions, npcProfiles } sets of keys known dirty; a collection without a hint whose
 *  object identity changed is diffed by reference over its keys (no hashing, no cloning). Returns null when nothing changed. */
export function diffStores(prev, next, hint = null) {
  const c = {}, t = {}; let any = false;
  for (const col of JOURNAL_COLLECTIONS) {
    const a = prev?.[col] || {}, b = next?.[col] || {};
    const keys = hint?.[col] ? [...hint[col]] : (a === b ? [] : [...new Set([...Object.keys(a), ...Object.keys(b)])]);
    for (const k of keys) {
      const has = Object.hasOwn(b, k), was = Object.hasOwn(a, k);
      if (has && (!was || a[k] !== b[k] || hint?.[col])) { (c[col] ||= {})[k] = b[k]; any = true; }
      else if (!has && was) { (c[col] ||= {})[k] = null; any = true; }
    }
  }
  for (const k of new Set([...Object.keys(prev || {}), ...Object.keys(next || {})])) {
    if (JOURNAL_COLLECTIONS.includes(k) || k === 'journalSeq') continue;
    if (prev?.[k] !== next?.[k]) { t[k] = Object.hasOwn(next, k) ? next[k] : null; any = true; }
  }
  return any ? { c, t } : null;
}

/** Read-only durable view of an account store: the checkpoint file with every journal line after its journalSeq applied, which
 *  is what a restart recovers. For readers outside the live accounts API (permissions, backups, offline tools): the file alone
 *  can be up to one checkpoint interval behind. Returns { state, seq } (state without journalSeq; seq = last applied line).
 *  A background checkpoint that compacts the journal between the two reads shows up as a gap and is retried. */
export async function readDurableAccountStore(file, { attempts = 5 } = {}) {
  for (let attempt = 1; ; attempt++) {
    const state = JSON.parse(await fsp.readFile(file, 'utf8'));
    const journal = createEntityJournal({ file, writeCheckpoint: async () => {} });
    try { await journal.recover(state); return { state, seq: journal.seq }; }
    catch (error) { if (attempt >= attempts || !/journal gap/.test(error.message)) throw error; await new Promise(resolve => setTimeout(resolve, 25 * attempt)); }
  }
}

export function createEntityJournal({ file, writeCheckpoint, checkpointMs = 30000, checkpointBytes = 64 * 1024 * 1024, log = () => {}, onCheckpoint = null }) {
  const journalFile = file + '.journal';
  let seq = 0, bytes = 0, handle = null, chain = Promise.resolve(), lastCheckpoint = Date.now(), checkpointing = null, closed = false;
  const stats = { appends: 0, appendBytes: 0, checkpoints: 0, lastCheckpointMs: null, replayed: 0 };
  const serial = (fn) => { const p = chain.then(fn); chain = p.catch(() => {}); return p; };
  async function open() { if (!handle) handle = await fsp.open(journalFile, 'a', 0o600); }
  return {
    journalFile, stats,
    get seq() { return seq; },
    /** Replay the journal onto the parsed checkpoint (mutates and returns it). */
    async recover(state) {
      const base = Number(state.journalSeq) || 0; delete state.journalSeq; seq = base;
      let text = ''; try { text = await fsp.readFile(journalFile, 'utf8'); } catch (e) { if (e.code !== 'ENOENT') throw e; }
      const lines = text.split('\n');
      for (let i = 0; i < lines.length; i++) {
        if (!lines[i]) continue; let rec;
        try { rec = JSON.parse(lines[i]); } catch { if (i >= lines.length - 2) { log('[journal] ignoring torn last line'); break; } throw new Error(`Account journal line ${i + 1} is corrupt; checkpoint and journal preserved.`); }
        if (rec.s <= base) continue;
        if (rec.s !== seq + 1) throw new Error(`Account journal gap at seq ${rec.s} (expected ${seq + 1}); checkpoint and journal preserved.`);
        applyJournalRecord(state, rec); seq = rec.s; stats.replayed++;
      }
      bytes = Buffer.byteLength(text);
      return state;
    },
    /** Append one record and fsync it. Resolves only when the line is durable. */
    append(rec) {
      return serial(async () => {
        await open(); const line = JSON.stringify({ s: seq + 1, ...rec }) + '\n';
        await handle.write(line); await handle.datasync(); seq++; bytes += Buffer.byteLength(line);
        stats.appends++; stats.appendBytes += Buffer.byteLength(line);
      });
    },
    /** Drop journal lines <= upTo (they are inside a durable checkpoint). Atomic: temp + fsync + rename. */
    compact(upTo) {
      return serial(async () => {
        if (handle) { await handle.close(); handle = null; }
        let text = ''; try { text = await fsp.readFile(journalFile, 'utf8'); } catch (e) { if (e.code !== 'ENOENT') throw e; }
        const keep = text.split('\n').filter(l => { if (!l) return false; try { return JSON.parse(l).s > upTo; } catch { return false; } });
        const tmp = journalFile + '.compact.tmp', h = await fsp.open(tmp, 'w', 0o600);
        try { await h.write(keep.length ? keep.join('\n') + '\n' : ''); await h.sync(); } finally { await h.close(); }
        await fsp.rename(tmp, journalFile);
        try { const d = await fsp.open(path.dirname(journalFile), 'r'); try { await d.sync(); } finally { await d.close(); } } catch {}
        bytes = keep.reduce((n, l) => n + Buffer.byteLength(l) + 1, 0);
      });
    },
    /** Write a checkpoint of `snapshot` (state at seq `at`) then compact. Background unless awaited. */
    checkpoint(snapshot, at = seq) {
      if (checkpointing) return checkpointing.then(() => this.checkpoint(snapshot, at));
      const t0 = Date.now();
      checkpointing = (async () => {
        await writeCheckpoint({ ...snapshot, journalSeq: at });
        await this.compact(at); lastCheckpoint = Date.now(); stats.checkpoints++; stats.lastCheckpointMs = Date.now() - t0; onCheckpoint?.(at);
      })().finally(() => { checkpointing = null; });
      return checkpointing;
    },
    due() { return !closed && !checkpointing && seq > 0 && (bytes >= checkpointBytes || Date.now() - lastCheckpoint >= checkpointMs); },
    get busy() { return !!checkpointing; },
    async close() { closed = true; await checkpointing?.catch(() => {}); await serial(async () => { if (handle) { await handle.close(); handle = null; } }); },
  };
}
