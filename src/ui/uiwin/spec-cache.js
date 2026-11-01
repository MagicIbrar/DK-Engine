// Optional disk cache of pure compiled UI scripts. Never stores windows, game state or account data.
// The prepared Global fingerprint, engine version and actual compiler bytes all participate in the key.
const PREFIX = 'dekaron-ui-specs-v1-';
// 384 x 256 KiB bounds serialized payload to 96 MiB (browser storage overhead is separate).
export const SPEC_CACHE_LIMITS = Object.freeze({ entries: 384, entryBytes: 256 * 1024, timeoutMs: 1000 });
const COMPILER_FILES = ['spec.js', 'script.js', '../../formats/binreader.js'];

export function createSpecCache({ storage = globalThis.caches, fetcher = globalThis.fetch,
  crypto = globalThis.crypto, limits = SPEC_CACHE_LIMITS } = {}) {
  let ready, writes = Promise.resolve();
  const stats = { hits: 0, misses: 0, writes: 0, skipped: 0, errors: 0 };
  const bounded = async job => {
    let timer;
    try { return await Promise.race([job, new Promise(resolve => { timer = setTimeout(() => resolve(null), limits.timeoutMs); })]); }
    finally { clearTimeout(timer); }
  };
  async function open() {
    if (!storage || !fetcher || !crypto?.subtle) return null;
    const controller = new AbortController();
    const timer = setTimeout(() => controller.abort(), limits.timeoutMs);
    try {
      const response = await fetcher('/api/server/info', { cache: 'no-store', signal: controller.signal });
      if (!response.ok) return null;
      const info = await response.json();
      if (typeof info.contentVersion !== 'string' || !info.contentVersion || ['legacy', 'unknown'].includes(info.contentVersion) ||
          typeof info.engineVersion !== 'string' || !info.engineVersion) return null;
      const sources = await Promise.all(COMPILER_FILES.map(async file => {
        const r = await fetcher(new URL(file, import.meta.url).href, { cache: 'no-cache', signal: controller.signal });
        if (!r.ok) throw Error('UI compiler version unavailable');
        return r.text();
      }));
      const bytes = new TextEncoder().encode(JSON.stringify([info.contentVersion, info.engineVersion, ...sources]));
      const digest = [...new Uint8Array(await crypto.subtle.digest('SHA-256', bytes))].map(v => v.toString(16).padStart(2, '0')).join('');
      const name = PREFIX + digest;
      const cache = await storage.open(name);
      // The cache is expendable. Remove only this feature's older generations.
      for (const old of await storage.keys()) if (old.startsWith(PREFIX) && old !== name) await storage.delete(old);
      return cache;
    } catch { stats.errors++; return null; }
    finally { clearTimeout(timer); }
  }
  const cacheReady = () => ready ||= bounded(open()).catch(() => null);
  function nodeValid(node, depth = 0) {
    if (!node || typeof node !== 'object' || depth > 100 || typeof node.id !== 'string' || typeof node.type !== 'string' ||
        !Array.isArray(node.children) || !Array.isArray(node.images) || !Array.isArray(node.titles) ||
        !node.props || typeof node.props !== 'object' || Array.isArray(node.props)) return false;
    if (node.rect != null && (!Array.isArray(node.rect) || node.rect.length !== 4 || !node.rect.every(Number.isFinite))) return false;
    if (![...node.images, ...node.titles].every(value => value && typeof value === 'object' && !Array.isArray(value))) return false;
    return node.children.every(child => nodeValid(child, depth + 1));
  }
  function valid(value, key) {
    return value?.key === key && ['tags', 'legacy', 'table'].includes(value.format) &&
      Array.isArray(value.windows) && value.windows.every(node => node.kind === 'window' && nodeValid(node)) &&
      Array.isArray(value.fragments) && value.fragments.every(node => nodeValid(node)) &&
      Array.isArray(value.warnings) && !value.warnings.length;
  }
  return {
    stats,
    async load(key, compile) {
      // Only public original UI scripts are cacheable. Custom/service responses never enter this store.
      if (!/^script\/ui\/[a-z0-9_./-]+$/i.test(key) || key.split('/').includes('..')) return compile();
      const cache = await cacheReady();
      const url = new URL('/__dekaron_ui_specs__/' + key, import.meta.url).href;
      if (cache) {
        try {
          const response = await bounded(cache.match(url));
          if (response) {
            const value = await bounded(response.json());
            if (valid(value, key)) { stats.hits++; return value; }
            void cache.delete(url).catch(() => {});
          }
        } catch { stats.errors++; }
      }
      stats.misses++;
      const result = await compile(); // Required parse failures retain their original behaviour.
      if (cache && valid(result, key)) {
        // Snapshot before a manager can mutate a returned spec; write off the readiness path.
        const json = JSON.stringify(result), size = new TextEncoder().encode(json).byteLength;
        if (size <= limits.entryBytes) {
          writes = writes.then(async () => {
            const keys = await cache.keys();
            while (keys.length >= limits.entries) await cache.delete(keys.shift());
            await cache.put(url, new Response(json, { headers: { 'Content-Type': 'application/json' } }));
            stats.writes++;
          }).catch(() => { stats.errors++; });
        } else stats.skipped++;
      } else stats.skipped++;
      return result;
    },
    flush: () => writes,
  };
}

export const compiledScriptCache = createSpecCache();
