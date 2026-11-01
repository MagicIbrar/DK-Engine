// lane-perf: Global's map preload list (share/maplist.csv `Preloading` -> property/preload/*.pre, parsed by global-preload.js)
// fetched behind the loading screen through the engine's own caches (ModelCache.mesh / tpack / anim, assets.js buffers), so the
// first draw of anything Global preloads finds it parsed. Missing includes are reported, never substituted.
import {fetchText, fetchBuffer} from './assets.js';
import {parsePreload} from './global-preload.js';
const DIR = {mesh: 'mesh/', tpack: 'texturepack/', anim: 'anim/', skel: 'skel/', texture: 'texture/'};
export async function collectPreload(entry, read, {includeCommon = true} = {}) {
  const seen = new Set(), assets = {tpack: [], mesh: [], anim: [], skel: [], texture: []}, keys = new Set(), missing = [];
  const visit = async rel => { const k = rel.toLowerCase(); if (seen.has(k)) return; seen.add(k);
    let text = null; try { text = await read(rel); } catch { text = null; }
    if (text == null) { missing.push(rel); return; }
    const p = parsePreload(text);
    for (const kind of Object.keys(assets)) for (const a of p[kind]) { const ak = kind + ':' + a.toLowerCase(); if (!keys.has(ak)) { keys.add(ak); assets[kind].push(a); } }
    for (const sub of p.pre) await visit(sub); };
  if (includeCommon) { await visit('common.pre'); await visit('common_effect.pre'); }
  if (entry) await visit(entry);
  return {files: [...seen], assets, missing};
}
/** Work items = every listed asset; onProgress(done,total) after each one finishes (success or failure). */
export async function prewarmGlobalPreload(game, entry, {onProgress = () => {}, lanes = 6, read = rel => fetchText('property/preload/' + rel.replace(/\\/g, '/'), true)} = {}) {
  const list = await collectPreload(entry, read);
  const m = game?.models, jobs = [];
  for (const [kind, items] of Object.entries(list.assets)) for (const a of items) {
    const key = DIR[kind] + a.replace(/\\/g, '/');
    jobs.push(kind === 'mesh' && m?.mesh ? () => m.mesh(key) : kind === 'tpack' && m?.tpack ? () => m.tpack(key) : kind === 'skel' && m?.skeleton ? () => m.skeleton(key) : kind === 'anim' && m?.anim ? () => m.anim(key) : () => fetchBuffer(key));
  }
  let next = 0, done = 0; const failed = [];
  onProgress(0, jobs.length);
  await Promise.all(Array.from({length: Math.min(lanes, jobs.length)}, async () => {
    while (next < jobs.length) { const i = next++; try { await jobs[i](); } catch (e) { failed.push(i); } onProgress(++done, jobs.length); }
  }));
  if (list.missing.length) console.info('[preload] Global preload includes absent from the data:', list.missing.join(', '));
  return {entry, items: jobs.length, failed: failed.length, missing: list.missing};
}
