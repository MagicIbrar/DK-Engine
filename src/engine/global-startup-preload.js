// 4.3.2 workstream E: Global's .pre preload lists, loaded IN GLOBAL'S ORDER behind a loading bar.
//   - collectOrderedPreload: fetch every .pre the roots reach (includes followed, typo aliases from
//     config/global-preload-aliases.js), then list the assets in file order (global-preload.js resolvePreloadOrdered).
//   - warmOrderedPreload: start the items in that order (N lanes; item i never starts before item i-1), each through the
//     engine's own caches so the later real use is a cache hit: mesh/skeleton/anim parse in the asset workers,
//     tpack parse, texture fetch + worker DDS decode + GPU upload (TextureCache.load), raw bytes cached by assets.js.
//     onProgress(done, total, item) after each item (work-proportional bar).
// GLOBAL_STARTUP_PRE (DATA-INFERRED, see LOAD-VERIFY.md): the .pre files in g2 that no map's maplist Preloading reaches
// and that are not map lists: common.pre and common_effect.pre (every map's Preloading in this engine also visits them
// first), and the three skill/*.pre. Which .pre Global's client opens at launch, and in what order, is UNKNOWN until
// the owner's Procmon trace (procmon-compare.mjs lists the .pre files Global opened, in order). The login map (110,
// MAL_Login.map) has no Preloading entry.
import { fetchText, fetchBuffer } from './assets.js';
import { breathe } from './yield.js';
import { resolvePreloadOrdered, parsePreloadOrdered } from './global-preload.js';
import { PRELOAD_INCLUDE_ALIASES } from '../config/global-preload-aliases.js';

export const GLOBAL_STARTUP_PRE = Object.freeze(['common.pre', 'common_effect.pre', 'skill/archeress_skill.pre', 'skill/sorceress_skill.pre', 'skill/sword_skill.pre']);
export const PRELOAD_DIR = Object.freeze({ mesh: 'mesh/', tpack: 'texturepack/', anim: 'anim/', skel: 'skel/', texture: 'texture/' });
export const preloadAssetKey = item => PRELOAD_DIR[item.kind] + String(item.path).replace(/\\/g, '/');
const defaultRead = rel => fetchText('property/preload/' + String(rel).trim().replace(/\\/g, '/'), true).catch(e => { if (e?.missing) return null; throw e; });

/** Fetch all .pre text the roots reach (in parallel per include level), then resolve in Global's file order. */
export async function collectOrderedPreload(roots, { read = defaultRead, aliases = globalThis.__dkPreloadNoAliases ? null : PRELOAD_INCLUDE_ALIASES } = {}) {
  const texts = new Map(), key = r => String(r).trim().replace(/\//g, '\\').toLowerCase();
  let level = [...new Set([].concat(roots || []).filter(Boolean))];
  while (level.length) {
    const fresh = level.filter(r => !texts.has(key(r)));
    fresh.forEach(r => texts.set(key(r), undefined));
    const got = await Promise.all(fresh.map(async r => {
      let t = await read(r);
      const a = t == null && aliases?.[key(r)];
      if (a?.kind === 'GLOBAL-TYPO-ALIAS' && !texts.has(key(a.to))) { const at = await read(a.to); texts.set(key(a.to), at); }
      texts.set(key(r), t);
      return t;
    }));
    const next = [];
    for (const t of [...got, ...[...texts.values()].filter(v => typeof v === 'string')]) if (t) for (const it of parsePreloadOrdered(t).items) if (it.kind === 'pre' && !texts.has(key(it.path))) next.push(it.path);
    level = [...new Set(next)];
  }
  return resolvePreloadOrdered(roots, r => texts.get(key(r)) ?? null, { aliases });
}

function jobFor(item, { models, textures }) {
  const k = preloadAssetKey(item);
  switch (item.kind) {
    case 'mesh': return models?.mesh ? () => models.mesh(k) : () => fetchBuffer(k);
    case 'tpack': return models?.tpack ? () => models.tpack(k) : () => fetchBuffer(k);
    case 'skel': return models?.skeleton ? () => models.skeleton(k) : () => fetchBuffer(k);
    case 'anim': return models?.anim ? () => models.anim(k) : () => fetchBuffer(k);
    case 'texture': return textures?.load ? () => textures.load(k) : () => fetchBuffer(k);
    default: return () => fetchBuffer(k);
  }
}

/** Load `order` (from collectOrderedPreload) in that order through the caches. Never rejects; returns a ledger. */
export async function warmOrderedPreload(order, { models = null, textures = null, lanes = 8, onProgress = () => {}, onStart = null, current = () => true, yieldTask = breathe } = {}) {
  const started = performance.now(), ledger = { items: order.length, done: 0, failed: [], missing: [], startedOrder: [], ms: 0 };
  let next = 0;
  onProgress(0, order.length, null);
  await Promise.all(Array.from({ length: Math.max(1, Math.min(lanes, order.length)) }, async () => {
    while (next < order.length && current()) {
      const i = next++, item = order[i];
      ledger.startedOrder.push(i); onStart?.(item, i);
      try { const v = await jobFor(item, { models, textures })(); if (v == null) ledger.missing.push(preloadAssetKey(item)); }
      catch (e) { (e?.missing ? ledger.missing : ledger.failed).push(preloadAssetKey(item)); }
      ledger.done++; onProgress(ledger.done, order.length, item);
      // Cached work can resolve entirely in microtasks; periodically let the host observe completed work.
      await yieldTask();
    }
  }));
  ledger.ms = Math.round(performance.now() - started);
  return ledger;
}
