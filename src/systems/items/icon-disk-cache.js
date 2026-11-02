// ICON-DISK-CACHE (2026-10-30): finished item icon bakes (stills and spin sprite sheets) persist in the client's
// browser profile (CacheStorage of the WebView2 profile, origin http://127.0.0.1:7996), so a later session reads a
// small PNG from disk instead of re-rendering the item's 3D inventory model on the GPU and re-encoding it.
//
// Key: the served content version (the asset manifest hash from /api/server/info) + ICON_BAKE_REV + the exact
// Icons model key (mesh, tpack, skeleton, animation, textures, scale, refinement, size, cell span, socket glow, bloom).
// A new client build / asset generation therefore opens a new cache and deletes the old ones; a stale icon can never
// be shown. Custom (item builder / server library) items are never persisted: their assets are not covered by the
// content version.
// Kill switch: globalThis.__dekaronNoIconDiskCache = true
import { initializeContentVersion } from '../../engine/assets.js';
import { isCustomIndex } from '../itembuilder/registry.js';

// Bump when the bake output changes (lighting, materials, sprite sheet layout, PNG export).
export const ICON_BAKE_REV = 2;   // 2: icon tier halos / fortify rim / glow halo back on (gfx-b-switches GLOW-RESTORE 2026-10-30)
const PREFIX = 'dk-item-icons:';
const URL_BASE = '/__dk-icon-disk/';

export const iconDiskStats = { opened: false, name: null, hits: 0, misses: 0, writes: 0, writeErrors: 0, readErrors: 0, readMs: 0, bytesRead: 0, bytesWritten: 0 };
let opened = null;

export function iconDiskDisabled() {
  return globalThis.__dekaronNoIconDiskCache === true || typeof caches === 'undefined' || globalThis.isSecureContext === false;
}
/** May this item's icon be persisted at all? (custom items are not covered by the content version) */
export function iconDiskEligible(itemIndex) { return !iconDiskDisabled() && !isCustomIndex(itemIndex); }

function openStore() {
  if (iconDiskDisabled()) return Promise.resolve(null);
  return opened ||= (async () => {
    try {
      const version = await initializeContentVersion();
      if (!version) return null;   // unknown/legacy server generation: nothing safe to key on
      const name = `${PREFIX}r${ICON_BAKE_REV}:${version}`;
      const store = await caches.open(name);
      iconDiskStats.opened = true; iconDiskStats.name = name;
      // Older generations are never read again.
      void caches.keys().then(keys => Promise.all(keys.filter(k => k.startsWith(PREFIX) && k !== name).map(k => caches.delete(k)))).catch(() => {});
      return store;
    } catch { return null; }
  })();
}
/** Resolve once the disk store is open (or known unavailable). */
export function iconDiskReady() { return openStore().then(store => !!store); }

// Two independent 32-bit FNV/murmur style hashes + length: a short request URL. The full key is stored in a header
// and compared on read, so a hash collision is a miss, never a wrong icon.
function hashKey(s) {
  let a = 0x811c9dc5, b = 0x9747b28c;
  for (let i = 0; i < s.length; i++) {
    const c = s.charCodeAt(i);
    a = Math.imul(a ^ c, 16777619);
    b = Math.imul(b ^ c, 0x5bd1e995); b ^= b >>> 15;
  }
  return `${(a >>> 0).toString(36)}${(b >>> 0).toString(36)}${s.length.toString(36)}`;
}
const requestURL = (key, part) => `${URL_BASE}${hashKey(key)}.${part}`;
const headerKey = key => encodeURIComponent(key);

async function matchPart(store, key, part) {
  const response = await store.match(requestURL(key, part));
  if (!response || response.headers.get('x-dk-key') !== headerKey(key)) return null;
  return response;
}

/**
 * The persisted icon for an Icons model key, or null. Spin: {url (frame-zero still), spin:{url, cols, rows, n, period}}.
 * A still request is also served by the still half of a persisted spin bake of the same model ('s|' + key).
 * Returned URLs are fresh blob URLs owned by the caller (Icons registers them in its PreviewCache).
 */
export async function readIcon(modelKey, spin) {
  const store = await openStore();
  if (!store) return null;
  const t0 = performance.now();
  try {
    let still = null, sheet = null;
    if (spin) {
      sheet = await matchPart(store, modelKey, 'sheet');
      if (sheet) still = await matchPart(store, modelKey, 'still');
    } else {
      still = await matchPart(store, modelKey, 'still') || await matchPart(store, `s|${modelKey}`, 'still');
    }
    if (!still || (spin && !sheet)) { iconDiskStats.misses++; return null; }
    let meta = null;
    if (sheet) {
      meta = JSON.parse(sheet.headers.get('x-dk-spin') || 'null');
      if (!meta || !(meta.cols > 0) || !(meta.rows > 0) || !(meta.n > 0)) { iconDiskStats.misses++; return null; }
    }
    const [stillBlob, sheetBlob] = await Promise.all([still.blob(), sheet ? sheet.blob() : null]);
    if (!stillBlob.size || (sheet && !sheetBlob.size)) { iconDiskStats.misses++; return null; }
    const out = { url: URL.createObjectURL(stillBlob) };
    if (sheetBlob) out.spin = { url: URL.createObjectURL(sheetBlob), cols: meta.cols, rows: meta.rows, n: meta.n, period: meta.period };
    iconDiskStats.hits++; iconDiskStats.bytesRead += stillBlob.size + (sheetBlob?.size || 0);
    return out;
  } catch {
    iconDiskStats.readErrors++; return null;
  } finally { iconDiskStats.readMs += performance.now() - t0; }
}

/** Persist a finished bake (the caller keeps its blob URLs alive until this resolves). */
export async function writeIcon(modelKey, icon) {
  if (!icon?.url) return false;
  const store = await openStore();
  if (!store) return false;
  try {
    const blobOf = url => fetch(url).then(response => { if (!response.ok) throw Error('icon blob'); return response.blob(); });
    const [stillBlob, sheetBlob] = await Promise.all([blobOf(icon.url), icon.spin?.url ? blobOf(icon.spin.url) : null]);
    const headers = { 'content-type': 'image/png', 'x-dk-key': headerKey(modelKey) };
    // The sheet is written last: a reader only accepts a spin once both halves exist.
    await store.put(requestURL(modelKey, 'still'), new Response(stillBlob, { headers }));
    if (sheetBlob) {
      const { cols, rows, n, period } = icon.spin;
      await store.put(requestURL(modelKey, 'sheet'), new Response(sheetBlob, { headers: { ...headers, 'x-dk-spin': JSON.stringify({ cols, rows, n, period }) } }));
    }
    iconDiskStats.writes++; iconDiskStats.bytesWritten += stillBlob.size + (sheetBlob?.size || 0);
    return true;
  } catch {
    iconDiskStats.writeErrors++; return false;
  }
}

/** Test/diagnostic helper: delete every persisted icon generation. */
export async function clearIconDisk() {
  opened = null;
  if (typeof caches === 'undefined') return 0;
  const keys = (await caches.keys()).filter(k => k.startsWith(PREFIX));
  await Promise.all(keys.map(k => caches.delete(k)));
  return keys.length;
}