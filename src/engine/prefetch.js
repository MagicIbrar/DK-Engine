// 2.2.1 instant loading (measured): work the loading screen used to do that needs no world is
// pulled forward into the screens where the player is already waiting (the login -> select fade, character select), so
// "Enter" has less left to do.
//
//   prefetchGameTables(names)     parses gamedata JSON (engine-chosen-loading.js STARTUP_JSON, the class skills) one file
//                                 per macrotask, biggest first. JSON.parse runs on the main thread (a worker + structured
//                                 clone measured SLOWER than parse: items.json 303 ms parse vs 497 ms deserialize), so the
//                                 chain starts when the login succeeds: the first and biggest parses land in the fade-out /
//                                 busy scene load, where a stall is invisible. The systems' own fetchJSON calls hit the cache.
//   startAssetRecording / finishAssetRecording(mapIndex)
//                                 game.js records every buffer / texture request of a map load (assets.js recorder hook,
//                                 TextureCache.load) and keeps the list per map in localStorage: a hint list, refreshed on
//                                 every load, never trusted for correctness (a missing file resolves null as usual).
//   prefetchMapAssets(mapIndex, {textures, row})
//                                 replays that list at character select: buffers into the asset cache, textures decoded (asset
//                                 workers) and uploaded with the TARGET map's sampler state, so World/graphics setSampler
//                                 finds them matching and re-uploads nothing. Low fetch priority: the select scene's own
//                                 requests go first. stopMapPrefetch() (the hand-off) stops issuing new requests.
import { fetchJSON, tryFetchBuffer, setAssetRecorder } from './assets.js';
import { nextTask } from './yield.js';
import { samplerFromMapRow } from './sampler-state.js';
import { PREFETCH } from '../config/engine-chosen-loading.js';
import {mapDataPaths} from '../formats/spawn.js';

const STORE_PREFIX = 'dekaron:prefetch:v1:map:';
const STORE_INDEX = 'dekaron:prefetch:v1:maps';
const STORE_UI = 'dekaron:prefetch:v1:ui';   // the window art requests (map-independent: HUD + priority panels), replayed at login

// ------------------------------------------------------------------------------------------ game tables
const queued = new Set();
let tablesChain = Promise.resolve();
export const prefetchStats = { tables: 0, recorded: null, replayed: null, uiArt: null };

// A parse per idle period: the login / select scenes keep rendering between files. The timeout bounds the wait when the page
// never idles (a scene load), so the chain still finishes before a quick Enter.
const idleSlot = () => new Promise(resolve => {
  if (typeof globalThis.requestIdleCallback === 'function') globalThis.requestIdleCallback(() => resolve(), { timeout: PREFETCH.tableIdleTimeoutMs });
  else nextTask().then(resolve);
});

/** Queue gamedata table names ('items', 'skills/class_0'); each parses in its own idle period. Returns the chain. */
export function prefetchGameTables(names) {
  for (const name of names || []) {
    const url = `/gamedata/${name}.json`;
    if (queued.has(url)) continue;
    queued.add(url);
    tablesChain = tablesChain.then(async () => {
      await idleSlot();
      try { await fetchJSON(url); prefetchStats.tables++; } catch { /* the system that needs it reports it */ }
    });
  }
  return tablesChain;
}

// ------------------------------------------------------------------------------------------ recording
let recording = null;

/** Start recording buffer / texture / UI-art requests (game.js: at Game.start and at every map change). */
export function startAssetRecording() {
  recording = { keys: new Set(), textures: new Map(), ui: new Map() };
  setAssetRecorder(key => { recording?.keys.add(key); });
  return recording;
}
export const assetRecordingActive = () => !!recording;

/** TextureCache.load reports every request with its normalised options (the cache key's option part). */
export function recordTextureRequest(key, o) {
  if (!recording) return;
  const id = `${key}|${o.repeat ? 1 : 0}${o.anisotropy}${o.mipmaps}${o.decode ? 1 : 0}|${JSON.stringify(o.fixedSampler || null)}`;
  if (!recording.textures.has(id)) recording.textures.set(id, [key, o.repeat ? 1 : 0, o.anisotropy, o.mipmaps, o.decode ? 1 : 0, o.fixedSampler || null]);
}

/** ui/atlas.js reports its sprite / tinted / texture requests (the window art decoded and cropped for the HUD). */
export function recordAtlasRequest(method, args) {
  if (!recording) return;
  const entry = [method, ...args];
  const id = JSON.stringify(entry);
  if (!recording.ui.has(id)) recording.ui.set(id, entry);
}

/** Stop recording; with a map index, store the list for that map (null discards, e.g. a failed load). */
export function finishAssetRecording(mapIndex) {
  const r = recording;
  recording = null;
  setAssetRecorder(null);
  if (!r || mapIndex == null) return null;
  const tex = [...r.textures.values()];
  const ui = [...r.ui.values()];
  const texKeys = new Set(tex.map(t => t[0]));
  const uiKeys = new Set(ui.filter(e => e[0] === 'texture').map(e => e[1]));
  const manifest = { at: Date.now(), keys: [...r.keys].filter(k => !texKeys.has(k) && !uiKeys.has(k)), tex, ui };
  prefetchStats.recorded = { map: Number(mapIndex), keys: manifest.keys.length, textures: tex.length, ui: ui.length };
  storeManifest(mapIndex, manifest);
  storeUIList(ui);
  return manifest;
}

// The window art is the same whatever the map (HUD windows, the priority panels): one list, merged over the loads, replayed
// as soon as the login hall is shown (prefetchUIArt). Newest requests first; capped.
function storeUIList(ui) {
  if (typeof localStorage === 'undefined' || !ui.length) return;
  try {
    const seen = new Set(), merged = [];
    for (const entry of [...ui, ...(readUIList() || [])]) {
      const id = JSON.stringify(entry);
      if (seen.has(id)) continue;
      seen.add(id); merged.push(entry);
      if (merged.length >= PREFETCH.maxUIEntries) break;
    }
    localStorage.setItem(STORE_UI, JSON.stringify(merged));
  } catch { /* storage unavailable or full */ }
}
export function readUIList() {
  if (typeof localStorage === 'undefined') return null;
  try { const list = JSON.parse(localStorage.getItem(STORE_UI) || 'null'); return Array.isArray(list) ? list : null; } catch { return null; }
}
let uiArtJob = null;
/** Decode and crop the recorded window art through ui/atlas.js's shared instance (login screen). Once per session. */
export function prefetchUIArt(atlas, { lanes = PREFETCH.lanes } = {}) {
  if (uiArtJob) return uiArtJob;
  const list = (readUIList() || []).filter(e => typeof atlas?.[e[0]] === 'function');
  const stats = { entries: list.length, done: 0 };
  let cursor = 0;
  uiArtJob = Promise.all(Array.from({ length: Math.max(1, lanes) }, async () => {
    while (cursor < list.length) {
      const [method, ...args] = list[cursor++];
      try { await atlas[method](...args); stats.done++; } catch { /* a hint only */ }
    }
  })).then(() => { prefetchStats.uiArt = stats; return stats; });
  return uiArtJob;
}

function readIndex() {
  try { const list = JSON.parse(localStorage.getItem(STORE_INDEX) || '[]'); return Array.isArray(list) ? list.map(Number).filter(Number.isFinite) : []; }
  catch { return []; }
}
function storeManifest(mapIndex, manifest) {
  if (typeof localStorage === 'undefined') return;
  try {
    const text = JSON.stringify(manifest);
    if (text.length > PREFETCH.maxManifestBytes) return;
    localStorage.setItem(STORE_PREFIX + Number(mapIndex), text);
    const list = readIndex().filter(i => i !== Number(mapIndex));
    list.unshift(Number(mapIndex));
    for (const old of list.splice(PREFETCH.maxMaps)) localStorage.removeItem(STORE_PREFIX + old);
    localStorage.setItem(STORE_INDEX, JSON.stringify(list));
  } catch { /* storage unavailable or full: the next load runs as before */ }
}
/** The stored request list of a map, or null. */
export function readMapManifest(mapIndex) {
  if (typeof localStorage === 'undefined') return null;
  try {
    const m = JSON.parse(localStorage.getItem(STORE_PREFIX + Number(mapIndex)) || 'null');
    return m && Array.isArray(m.keys) && Array.isArray(m.tex) && (m.ui === undefined || Array.isArray(m.ui)) ? m : null;
  } catch { return null; }
}

// ------------------------------------------------------------------------------------------ replay
let current = null;
const replayed = new Set();   // maps whose list finished replaying this session (the caches keep their assets)
/** A stored request list exists for this map (a visited map). */
export const hasMapManifest = mapIndex => readMapManifest(mapIndex) !== null;

/**
 * Load a map's recorded assets into the caches (character select). One replay at a time: a new map stops the old one.
 * Order: the UI art first (the loading screen waits for the priority panels' sprites), then the world's textures, then
 * the remaining buffers (meshes, scripts, tables).
 * @param {number} mapIndex
 * @param {{textures?:import('./textures.js').TextureCache, atlas?:object, row?:object, lanes?:number}} [opts]
 *   row = the maplist row (sampler state); atlas = ui/atlas.js's shared instance
 * @returns {Promise<{hit:boolean, ui:number, textures:number, buffers:number, stopped:boolean}>}
 */
export function prefetchMapAssets(mapIndex, { textures = null, atlas = null, row = null, lanes = PREFETCH.lanes } = {}) {
  const map = Number(mapIndex);
  if (current && current.map === map) return current.done;
  if (replayed.has(map)) return Promise.resolve({ hit: true, ui: 0, textures: 0, buffers: 0, stopped: false, cached: true });
  current?.stop();
  const m = readMapManifest(map);
  const job = { map, stopped: false, stats: { hit: !!m, ui: 0, textures: 0, buffers: 0, stopped: false }, stop() { job.stopped = true; job.stats.stopped = true; } };
  current = job;
    if (!m) {
      // First visits have no recorded manifest yet. Start the actual map's core
      // files at character selection instead of waiting for Enter to fetch them.
      const paths=row?mapDataPaths(row):{},keys=[paths.map,paths.mac,paths.mol].filter(Boolean);
      job.done=Promise.all(keys.map(async key=>{if(job.stopped)return;try{await tryFetchBuffer(key,{priority:'low'});job.stats.buffers++;}catch{/* Required map loading reports/retries failures at Enter. */}})).then(()=>job.stats);
      return job.done;
    }
  const sampler = row ? samplerFromMapRow(row) : null;
  // the window art is done by prefetchUIArt (login, the merged list of every map); this map's own entries only when that never ran
  const tasks = [
    ...(atlas && !uiArtJob ? (m.ui || []).filter(e => typeof atlas[e[0]] === 'function').map(([method, ...args]) => async () => {
      await atlas[method](...args);
      job.stats.ui++;
    }) : []),
    ...m.tex.map(([key, repeat, anisotropy, mipmaps, decode, fixedSampler]) => async () => {
      if (textures) await textures.load(key, { repeat: !!repeat, anisotropy, mipmaps, decode: !!decode, fixedSampler, sampler, priority: 'low', _quiet: true });
      else await tryFetchBuffer(key, { priority: 'low' });
      job.stats.textures++;
    }),
    ...m.keys.map(key => async () => { await tryFetchBuffer(key, { priority: 'low' }); job.stats.buffers++; }),
  ];
  let cursor = 0;
  job.done = Promise.all(Array.from({ length: Math.max(1, lanes) }, async () => {
    while (!job.stopped && cursor < tasks.length) {
      const task = tasks[cursor++];
      try { await task(); } catch { /* a hint only */ }
    }
  })).then(() => { if (current === job) current = null; if (!job.stopped) replayed.add(map); prefetchStats.replayed = { map, ...job.stats }; return job.stats; });
  return job.done;
}

/** Stop issuing prefetch requests (the hand-off to the game: its own loads take over at normal priority). */
export function stopMapPrefetch() { current?.stop(); current = null; }
