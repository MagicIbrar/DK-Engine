// ARCHIVE service: every service's log lines arrive on the bus (BULK lane, drop-oldest under pressure) and are written here,
// batched, with async appends. Nothing in the game or world path ever blocks on a disk write for logging.
import fs from 'node:fs/promises';
import path from 'node:path';
import { workerData } from 'node:worker_threads';
import { connectWorker } from '../worker-endpoint.mjs';
const dir = workerData.dir; await fs.mkdir(dir, { recursive: true });
const buffers = new Map(); let writing = false, written = 0, lines = 0;
const day = () => new Date().toISOString().slice(0, 10);
async function drain() {
  if (writing) return; writing = true;
  try { while (buffers.size) { const [svc, list] = buffers.entries().next().value; buffers.delete(svc); const text = list.join('\n') + '\n'; await fs.appendFile(path.join(dir, `${svc}-${day()}.log`), text); written += text.length; } }
  catch (e) { console.error('[Archive] append failed:', e?.message || e); }
  finally { writing = false; }
}
setInterval(drain, 250).unref();
connectWorker('Archive', {
  'archive.write': d => { const svc = String(d?.svc || 'misc').replace(/[^A-Za-z0-9_-]/g, ''); const list = buffers.get(svc) || []; list.push(String(d?.line ?? '')); buffers.set(svc, list); lines++; },
  'archive.stats': () => ({ lines, written, pending: [...buffers.values()].reduce((n, l) => n + l.length, 0) }),
  'archive.flush': () => drain(),
}, ['archive.*']);
