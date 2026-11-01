const MAX_PENDING = 4, MAX_BYTES = 4096 * 4096 * 4;
const CANCELLED = Symbol('preview encoder disposed');
let worker, idleTimer, nextId = 0, failures = 0, retryAt = 0;
const pending = new Map();
const stats = { requests: 0, succeeded: 0, cancelled: 0, createdWorkers: 0, terminatedWorkers: 0, pendingHighWater: 0, fallbackReasons: {} };
export function previewEncoderStats() { return { ...stats, fallbackReasons: { ...stats.fallbackReasons }, pending: pending.size, workerLive: !!worker, failures, retryAt }; }
function fallback(reason, count = 1) { stats.fallbackReasons[reason] = (stats.fallbackReasons[reason] || 0) + count; return Promise.resolve(null); }

function stopWorker(result) {
  clearTimeout(idleTimer); idleTimer = null;
  const previous = worker; worker = null;
  if (previous) { previous.terminate(); stats.terminatedWorkers++; }
  for (const entry of pending.values()) { clearTimeout(entry.timer); entry.resolve(result); }
  pending.clear();
}
/** Game teardown cancels exports; existing icon generation guards own published URLs. */
export function disposePreviewEncoder() {
  stats.cancelled += pending.size;
  stopWorker(CANCELLED); failures = 0; retryAt = 0;
}
function failedWorker(reason) {
  void fallback(reason, Math.max(1, pending.size));
  failures++; retryAt = Date.now() + 1000; stopWorker(null);
}
function settle(id, blob) {
  const entry = pending.get(id); if (!entry) return;
  clearTimeout(entry.timer); pending.delete(id); entry.resolve(blob);
  if (!pending.size) idleTimer = setTimeout(() => stopWorker(null), 1000);
}
function encodeInWorker(canvas) {
  stats.requests++;
  if (typeof Worker !== 'function' || typeof OffscreenCanvas !== 'function') return fallback('unsupported');
  if (pending.size >= MAX_PENDING) return fallback('capacity');
  if (failures >= 2) return fallback('disabled-after-two-failures');
  if (Date.now() < retryAt) return fallback('failure-cooldown');
  const width = canvas.width, height = canvas.height, bytes = width * height * 4;
  if (!Number.isInteger(width) || !Number.isInteger(height) || width < 1 || height < 1 || bytes > MAX_BYTES) return fallback('pixel-budget');
  let pixels;
  try {
    // getImageData owns a fresh buffer; only that copy is transferred, never the source canvas.
    pixels = canvas.getContext('2d').getImageData(0, 0, width, height).data;
    if (pixels.byteLength !== bytes) return fallback('source-pixel-size');
    if (pixels.byteOffset || pixels.buffer.byteLength !== bytes) pixels = pixels.slice();
  } catch { return fallback('source-pixel-read'); }
  try {
    if (!worker) {
      const current = worker = new Worker(new URL('./preview-export-worker.js', import.meta.url), { type: 'module' });
      stats.createdWorkers++;
      current.onmessage = ({ data }) => {
        if (worker !== current || data?.kind !== 'preview-png-result') return;
        if (!pending.has(data.id)) return;
        if (data.error) { failedWorker('worker-encode-error'); return; }
        const valid = data.blob instanceof Blob && data.blob.type === 'image/png' && data.blob.size;
        if (valid) stats.succeeded++; else void fallback('invalid-worker-blob');
        settle(data.id, valid ? data.blob : null);
      };
      current.onerror = event => { event.preventDefault?.(); if (worker === current) failedWorker('worker-runtime-error'); };
      current.onmessageerror = () => { if (worker === current) failedWorker('worker-message-error'); };
    }
  } catch { failures++; retryAt = Date.now() + 1000; return fallback('worker-constructor'); }
  clearTimeout(idleTimer); idleTimer = null;
  return new Promise(resolve => {
    const id = ++nextId;
    const timer = setTimeout(() => { if (pending.has(id)) failedWorker('worker-timeout'); }, 2000);
    pending.set(id, { resolve, timer });
    stats.pendingHighWater = Math.max(stats.pendingHighWater, pending.size);
    try { worker.postMessage({ kind: 'preview-png', id, width, height, rgba: pixels.buffer }, [pixels.buffer]); }
    catch { failedWorker('worker-post-error'); }
  });
}

/** Lossless worker PNG; unsupported/failed worker keeps the existing canvas fallback. */
export async function previewBlobUrl(canvas) {
  let blob = await encodeInWorker(canvas);
  if (blob === CANCELLED) return null;
  let offscreen;
  if (!blob) {
    try {
      if (typeof OffscreenCanvas === 'function') {
        offscreen = new OffscreenCanvas(canvas.width, canvas.height);
        const context = offscreen.getContext('2d');
        if (context && typeof offscreen.convertToBlob === 'function') {
          context.drawImage(canvas, 0, 0);
          blob = await offscreen.convertToBlob({ type: 'image/png' });
        }
      }
    } catch { /* Preserve the original HTML fallback. */ }
    finally { if (offscreen) { try { offscreen.width = offscreen.height = 0; } catch {} } }
  }
  if (!blob) blob = await new Promise(resolve => { try { canvas.toBlob(resolve, 'image/png'); } catch { resolve(null); } });
  return blob ? URL.createObjectURL(blob) : canvas.toDataURL('image/png');
}
