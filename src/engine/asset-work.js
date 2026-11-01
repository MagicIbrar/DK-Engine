import { runAssetTask } from './asset-tasks.js';
import { breathe } from './yield.js';
import { assetWorkerCount } from '../config/engine-chosen-loading.js';

// Several workers keep texture encoding from holding up animation/mesh parsing (count: engine-chosen-loading.js). Inputs
// are copied before transfer because assets.js retains its original buffer for equipment/clip reuse.
const queue = [], slots = [];
let serial = 0, disabled = false;
export const assetWorkStats = { workerJobs: 0, fallbackJobs: 0, failures: 0, pending: 0 };
function fallback(job) {
  assetWorkStats.fallbackJobs++;
  breathe().then(() => runAssetTask(job.type, job.buffer, job.options)).then(job.resolve, job.reject);
}
function failWorkers() {
  if (disabled) return;
  disabled = true; assetWorkStats.failures++;
  for (const s of slots) { s.worker.terminate(); if (s.job) { fallback(s.job); s.job = null; } }
  pump();
}
function pump() {
  if (disabled || typeof Worker !== 'function') {
    for (const job of queue.splice(0)) fallback(job);
    return;
  }
  try {
    const count = assetWorkerCount();
    while (slots.length < count) {
      const worker = new Worker(new URL('./asset-worker.js', import.meta.url), { type: 'module' });
      const slot = { worker, job: null }; slots.push(slot);
      worker.onmessage = ({ data }) => {
        const job = slot.job;
        if (!job || data.id !== job.id) return;
        slot.job = null;
        if (data.error) job.reject(new Error(data.error)); else job.resolve(data.value);
        pump();
      };
      worker.onerror = failWorkers;
      worker.onmessageerror = failWorkers;
    }
    for (const slot of slots) {
      if (slot.job || !queue.length) continue;
      const job = slot.job = queue.shift();
      const transfer = job.buffer.slice(0);
      try { slot.worker.postMessage({ id: job.id, type: job.type, buffer: transfer, options: job.options }, [transfer]); assetWorkStats.workerJobs++; }
      catch { failWorkers(); break; }
    }
  } catch {
    failWorkers();
  }
}
export function assetWork(type, buffer, options = {}) {
  assetWorkStats.pending++;
  return new Promise((resolve, reject) => {
    queue.push({ id: ++serial, type, buffer, options, resolve, reject }); pump();
  }).finally(() => { assetWorkStats.pending--; });
}
