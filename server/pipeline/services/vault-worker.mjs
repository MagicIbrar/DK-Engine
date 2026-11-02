// Vault worker: the account-store persistence writer (Phase B, DK_VAULT=1). Clean-room, our own code.
// Owns the disk for one account store: the per-record journal (append + fsync), the full-store checkpoint (temp + fsync +
// rename via writeAtomicStore) and journal compaction. It keeps its OWN copy of the store (the "mirror"), rebuilt from disk at
// start exactly like a restart would (checkpoint + journal replay) and then kept current from the dirty-record deltas Realm
// streams to it. Realm never hands over the whole store; checkpoints are serialized here, off Realm's main thread.
import { parentPort, workerData } from 'node:worker_threads';
import fsp from 'node:fs/promises';
import { createEntityJournal, applyJournalRecord } from '../../accounts/entity-journal.mjs';
import { writeAtomicStore } from '../../accounts/atomic-store.mjs';

const { file, checkpointMs, checkpointBytes, expectSeq } = workerData;
const journal = createEntityJournal({ file, checkpointMs, checkpointBytes, writeCheckpoint: value => writeAtomicStore(file, value, { accountNpcProfiles: true }) });
let mirror = null;
const ready = (async () => {
  try { mirror = JSON.parse(await fsp.readFile(file, 'utf8')); }
  catch (error) { if (error.code !== 'ENOENT') throw error; mirror = { version: 1, users: {}, sessions: {} }; }
  await journal.recover(mirror);
  if (journal.seq !== expectSeq) throw Object.assign(new Error(`Vault start seq ${journal.seq} does not match Realm seq ${expectSeq}.`), { code: 'EVAULTSEQ' });
})().catch(error => { throw Object.assign(error instanceof Error ? error : new Error(String(error)), { vaultInit: true }); });
ready.catch(() => {});
const replaces = new Map();
const ok = (id, extra = {}) => parentPort.postMessage({ id, ok: true, s: journal.seq, ...extra });
const bad = (id, error) => parentPort.postMessage({ id, ok: false, error: String(error?.message || error), code: error?.code || 'EVAULT', fatal: error?.code === 'EVAULTSEQ' || error?.vaultInit === true });

parentPort.on('message', msg => {
  switch (msg.op) {
    case 'append': {
      // msg.text is Realm's JSON.stringify of the dirty-record delta {c,t}: the exact record the in-process journal writes.
      ready.then(async () => {
        const rec = JSON.parse(msg.text);
        await journal.append(rec);              // one line, fsynced (datasync) before it resolves
        applyJournalRecord(mirror, rec);        // only after the line is durable, same order as the journal
        ok(msg.id);
      }).catch(error => bad(msg.id, error));
      break;
    }
    case 'checkpoint': {
      ready.then(async () => {
        const t0 = performance.now(), at = journal.seq;
        await journal.checkpoint(mirror, at);   // fuzzy checkpoint: later appends replay idempotently (absolute set/delete ops)
        ok(msg.id, { at, ms: performance.now() - t0 });
      }).catch(error => bad(msg.id, error));
      break;
    }
    case 'replaceBegin': replaces.set(msg.id, []); break;
    case 'replaceChunk': replaces.get(msg.id)?.push(msg.text); break;
    case 'replaceEnd': {
      // Full-store transaction (rare admin paths): Realm streamed its new store as sliced JSON text. Parse it here and make it
      // the checkpoint at msg.at; the mirror switches only after that checkpoint is durable.
      const parts = replaces.get(msg.rid); replaces.delete(msg.rid);
      ready.then(async () => {
        if (!parts) throw new Error('Vault replace stream missing.');
        const next = JSON.parse(parts.join(''));
        if (journal.seq !== msg.at) throw Object.assign(new Error(`Vault replace at ${msg.at} but journal is at ${journal.seq}.`), { code: 'EVAULTSEQ' });
        const t0 = performance.now();
        await journal.checkpoint(next, msg.at);
        mirror = next;
        ok(msg.id, { at: msg.at, ms: performance.now() - t0 });
      }).catch(error => bad(msg.id, error));
      break;
    }
    case 'close': {
      ready.catch(() => {}).then(() => journal.close()).then(() => ok(msg.id), error => bad(msg.id, error));
      break;
    }
    case 'crash': if (workerData.testHooks) process.exit(9); break;   // test-only (DK_VAULT_TEST_HOOKS=1)
  }
});
