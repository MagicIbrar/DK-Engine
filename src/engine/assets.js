// Asset access layer: every game file is fetched from the local server (/data/<path>)
// through a small concurrency-limited, de-duplicating cache.
import { CONTENT_VERSION_TIMEOUT_MS, CONTENT_VERSION_RETRY_MS } from '../config/engine-chosen-loading.js';
import { decodeText, parseCSV } from '../formats/binreader.js';

export const DATA_URL = '/data/';
export const SOUND_URL = '/sound/';
const MAX_CONCURRENT = 12;
const RETRY_BASE_MS = 1000;
const RETRY_MAX_MS = 30000;

/** Normalise a game-internal path ("Monster\\Foo.DDS") to a server-relative key ("monster/foo.dds"). */
export function normPath(p) {
  return String(p).trim().replace(/\\/g, '/').replace(/^\.\/+/, '').replace(/^\/+/, '').replace(/\/{2,}/g, '/').toLowerCase();
}

// Establish the served client generation before any eligible browser request. Unknown/legacy
// servers keep unversioned validator requests; custom account assets never receive this query.
let contentVersionPromise, contentVersionRetryAt = Infinity;
export function initializeContentVersion() {
  if (contentVersionPromise && performance.now() >= contentVersionRetryAt) {
    contentVersionPromise = null; contentVersionRetryAt = Infinity;
  }
  if (!contentVersionPromise) contentVersionPromise = (async () => {
    const controller = typeof AbortController === 'function' ? new AbortController() : null;
    let timer;
    // Race the complete response/body parse; an ignored abort or hanging json() cannot stall assets.
    const metadata = Promise.resolve().then(async () => {
      try {
        const response = await fetch('/api/server/info', {cache: 'no-store', ...(controller ? {signal: controller.signal} : {})});
        if (!response.ok) return {version: null, retry: true};
        const value = (await response.json()).contentVersion;
        return {version: typeof value === 'string' && value && value !== 'legacy' ? value : null, retry: false};
      } catch { return {version: null, retry: true}; }
    });
    const deadline = new Promise(resolve => {
      timer = setTimeout(() => { resolve({version: null, retry: true}); controller?.abort(); }, CONTENT_VERSION_TIMEOUT_MS);
    });
    try {
      const result = await Promise.race([metadata, deadline]);
      if (result.retry) contentVersionRetryAt = performance.now() + CONTENT_VERSION_RETRY_MS;
      return result.version;
    } finally { clearTimeout(timer); }
  })();
  return contentVersionPromise;
}
export async function versionedContentURL(url) {
  if (!/^\/(data|gamedata)\//.test(url)) return url;
  const version = await ((contentVersionPromise || typeof window === 'object') ? initializeContentVersion() : Promise.resolve(null));
  if (!version) return url;
  return `${url}${url.includes('?') ? '&' : '?'}v=${encodeURIComponent(version)}`;
}

let active = 0;
const waiting = [];
function schedule(task) {
  return new Promise((resolve, reject) => {
    const run = () => {
      active++;
      task().then(resolve, reject).finally(() => {
        active--;
        const next = waiting.shift();
        if (next) next();
      });
    };
    if (active < MAX_CONCURRENT) run(); else waiting.push(run);
  });
}

const bufCache = new Map();
const bufFailures = new Map();
const missing = new Set();
export const stats = { requested: 0, loaded: 0, failed: 0, bytes: 0 };

function responseError(res, key) {
  // Only explicit absence is a candidate-path miss. A busy/disconnected server
  // or denied custom asset is not proof that the original file does not exist.
  const absent = res.status === 404 || res.status === 204 || !!res.headers?.get?.('X-Missing');
  if (res.ok && !absent) return null;
  const error = new Error(absent ? `missing asset: ${key}` : `asset request failed (${res.status}): ${key}`);
  error.missing = absent;
  error.transient = !absent;
  error.status = res.status;
  return error;
}

// Retry on a later consumer request, with bounded exponential backoff. Keep
// concurrent consumers deduplicated even while a failure is cooling down.
export function cachedAssetRequest(cache, failures, key, load, onFailure = null) {
  const previous = failures.get(key);
  if (previous && performance.now() >= previous.retryAt) { cache.delete(key); failures.delete(key); }
  let promise = cache.get(key);
  if (promise) return promise;
  promise = Promise.resolve().then(load).then(value => {
    if (cache.get(key) === promise) failures.delete(key);
    return value;
  }, error => {
    if (error && typeof error === 'object' && !error.missing) error.transient = true;
    onFailure?.(error);
    if (cache.get(key) === promise && !error?.missing) {
      const count = (previous?.count || 0) + 1;
      failures.set(key, {count, retryAt: performance.now() + Math.min(RETRY_MAX_MS, RETRY_BASE_MS * 2 ** Math.min(count - 1, 5))});
    }
    throw error;
  });
  cache.set(key, promise);
  return promise;
}

// Request recorder (engine/prefetch.js: the per-map asset lists replayed at character select); null = off.
let recorder = null;
export function setAssetRecorder(fn) { recorder = typeof fn === 'function' ? fn : null; }

/**
 * Fetch a data file as ArrayBuffer. Rejects with an Error whose .missing is true on 404.
 * @param {string} rel
 * @param {{priority?:'high'|'low'|'auto'|null}} [opts]  fetch priority hint (prefetch uses 'low')
 */
export function fetchBuffer(rel, { priority = null } = {}) {
  const key = normPath(rel);
  if (recorder) recorder(key);
  return cachedAssetRequest(bufCache, bufFailures, key, () => {
    stats.requested++;
    return schedule(async () => {
      // ?opt=1: server.mjs answers a missing file with 204 + X-Missing (no console error for probed fallbacks)
      const custom = /^custom\/glb\/[a-f0-9]{64}\.glb$/.test(key);
      const url = custom ? `/api/world/custom-assets/${key.split('/').at(-1)}` : await versionedContentURL(DATA_URL + key.split('/').map(encodeURIComponent).join('/') + '?opt=1');
      const res = await (priority ? fetch(url, { priority }) : fetch(url));
      const error = responseError(res, key);
      if (error) throw error;
      const buf = await res.arrayBuffer();
      missing.delete(key);
      stats.loaded++; stats.bytes += buf.byteLength;
      return buf;
    });
  }, error => { stats.failed++; if (error?.missing) missing.add(key); });
}

/** A required map file gets one fresh attempt after a transient transport failure.
 * The shared cache cools down failed requests for one second, so an immediate
 * second fetch would only receive the same rejected promise. Missing files are
 * never retried; they need a repaired installation.
 */
export async function fetchRequiredMapBuffer(rel) {
  try { return await fetchBuffer(rel); }
  catch (error) {
    if (!error?.transient || error?.missing || (error.status >= 400 && error.status < 500 && ![408,429].includes(error.status))) throw error;
    await new Promise(resolve => setTimeout(resolve, RETRY_BASE_MS + 25));
    return fetchBuffer(rel);
  }
}

/** Like fetchBuffer but resolves null instead of rejecting when the file does not exist. */
export function tryFetchBuffer(rel, opts) {
  return fetchBuffer(rel, opts).catch(e => { if (e.missing) return null; throw e; });
}

/** Try candidate paths in order, returning { path, buffer } for the first that exists (or null). */
export async function fetchFirst(candidates) {
  for (const c of candidates) {
    if (!c) continue;
    const buf = await tryFetchBuffer(c);
    if (buf) return { path: normPath(c), buffer: buf };
  }
  return null;
}

export async function fetchText(rel, korean = false) {
  return decodeText(new Uint8Array(await fetchBuffer(rel)), korean);
}

export async function fetchCSV(rel, korean = false) {
  return parseCSV(await fetchText(rel, korean));
}

/** CSV with a header row -> array of objects keyed by header name. */
export async function fetchCSVObjects(rel, korean = false) {
  const rows = await fetchCSV(rel, korean);
  const head = rows.shift() || [];
  return rows.filter(r => r.length > 1 || (r[0] && r[0].trim())).map(r => {
    const o = {};
    head.forEach((h, i) => { o[h.trim()] = r[i]; });
    return o;
  });
}

const jsonCache = new Map();
const jsonFailures = new Map();
/** Engine-side JSON (e.g. /gamedata/monsters.json), not game data. */
export function fetchJSON(url) {
  return cachedAssetRequest(jsonCache, jsonFailures, url, async () => {
    const res = await fetch(await versionedContentURL(url)), error = responseError(res, url);
    if (error) throw error;
    return res.json();
  });
}

export function listDir(rel) {
  return fetch(`/api/ls?dir=${encodeURIComponent(normPath(rel))}`).then(r => (r.ok ? r.json() : []));
}

export function soundURL(rel) {
  return SOUND_URL + normPath(rel).split('/').map(encodeURIComponent).join('/');
}

export function isMissing(rel) { return missing.has(normPath(rel)); }

/** Drop cached buffers (e.g. when leaving a map) to keep memory bounded. */
export function clearBufferCache(filter = () => true) {
  for (const k of [...bufCache.keys()]) if (filter(k)) { bufCache.delete(k); bufFailures.delete(k); missing.delete(k); }
}
