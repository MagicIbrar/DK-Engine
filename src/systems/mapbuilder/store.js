// Custom map storage: IndexedDB (same origin as the game, so the builder page and the game share it).
//   store 'files'   id -> { id, meta, map, mol, mac }   (the original-format files, format.js)
//   store 'catalog' id -> { id, index, name, size, created, modified, basedOn, counts, minimap }   (fast listing)
// A BroadcastChannel ('dekaron-custommaps') tells other open pages (game <-> builder) that the list changed.
// Without IndexedDB (Node tests, locked-down browsers) an in-memory store is used.
import { CUSTOM_BASE, META_FORMAT, MapDoc, isCustomIndex } from './format.js';
import { packDkmap, unpackDkmap } from './pack.js';
import {validateMapFiles} from './validate.js';

const DB_NAME = 'dekaron-online-custommaps';
const DB_VERSION = 1;
const CHANNEL = 'dekaron-custommaps';

let dbp = null;
const mem = { files: new Map(), catalog: new Map() };

function openDB() {
  if (dbp) return dbp;
  if (!globalThis.indexedDB) { dbp = Promise.resolve(null); return dbp; }
  dbp = new Promise((res) => {
    let req;
    try { req = indexedDB.open(DB_NAME, DB_VERSION); } catch { res(null); return; }
    req.onupgradeneeded = () => {
      const db = req.result;
      if (!db.objectStoreNames.contains('files')) db.createObjectStore('files', { keyPath: 'id' });
      if (!db.objectStoreNames.contains('catalog')) db.createObjectStore('catalog', { keyPath: 'id' });
    };
    req.onsuccess = () => res(req.result);
    req.onerror = () => { console.warn('[mapbuilder] IndexedDB unavailable, using memory', req.error); res(null); };
    req.onblocked = () => res(null);
  });
  return dbp;
}

function tx(db, stores, mode, fn) {
  return new Promise((res, rej) => {
    const t = db.transaction(stores, mode);
    let out;
    t.oncomplete = () => res(out);
    t.onerror = () => rej(t.error);
    t.onabort = () => rej(t.error || new Error('aborted'));
    out = fn(...stores.map(s => t.objectStore(s)));
  });
}

let channel = null;
const listeners = new Set();
function chan() {
  if (!channel && globalThis.BroadcastChannel) {
    channel = new BroadcastChannel(CHANNEL);
    channel.onmessage = (e) => { for (const f of listeners) try { f(e.data); } catch { /* ignore */ } };
  }
  return channel;
}
function notify(msg) { try { chan()?.postMessage(msg); } catch { /* ignore */ } for (const f of listeners) try { f(msg); } catch { /* ignore */ } }
/** Listen for changes made by this or another page: fn({type:'saved'|'deleted', id, index}). */
export function onChange(fn) { chan(); listeners.add(fn); return () => listeners.delete(fn); }
export async function storageStatus(){const db=await openDB();return{persistent:!!db,mode:db?'indexeddb':'memory'};}
const copy=value=>structuredClone(value);

function catalogEntry(meta) {
  return {
    id: meta.id, index: meta.index, name: meta.name, desc: meta.desc || '', size: meta.size, created: meta.created,
    modified: meta.modified, basedOn: meta.basedOn ?? null, minimap: meta.minimap || null,
    counts: { objects: meta.objects || 0, spawns: meta.spawns?.length || 0, npcs: meta.npcs?.length || 0, portals: meta.portals?.length || 0 },
    start: meta.start || null,
    env: {
      bgmMap: meta.env?.bgmMap ?? null, minLevel: meta.env?.minLevel || 0, maxLevel: meta.env?.maxLevel || 0,
      light: meta.env?.light || null, envMap: meta.env?.envMap || null, clipFar: meta.env?.clipFar || 75,
      dayMinutes: meta.env?.dayMinutes || 90, returnScroll: meta.env?.returnScroll ?? 1,
    },
  };
}

/** Every stored custom map (catalog entries, newest first). */
export async function listMaps() {
  const db = await openDB();
  let rows;
  if (db) rows = await new Promise((res) => { const t = db.transaction(['catalog'], 'readonly'); const r = t.objectStore('catalog').getAll(); r.onsuccess = () => res(r.result || []); r.onerror = () => res([]); });
  else rows = copy([...mem.catalog.values()]);
  return rows.sort((a, b) => (b.modified || 0) - (a.modified || 0));
}

/** { meta, map, mol, mac } of one map, or null. */
export async function loadMap(id) {
  const db = await openDB();
  if (!db) return mem.files.has(id)?copy(mem.files.get(id)):null;
  return new Promise((res) => { const t = db.transaction(['files'], 'readonly'); const r = t.objectStore('files').get(id); r.onsuccess = () => res(r.result || null); r.onerror = () => res(null); });
}

/** The stored map with this game map index (90001...), or null. */
export async function loadByIndex(index) {
  const e = (await listMaps()).find(m => Number(m.index) === Number(index));
  return e ? loadMap(e.id) : null;
}

/** Next free custom map index. */
export async function nextIndex() {
  const list = await listMaps();
  return Math.max(CUSTOM_BASE, ...list.map(m => Number(m.index) || 0)) + 1;
}

/**
 * Store a map. files = { meta, map, mol, mac } (format.js MapDoc.toFiles()). A meta without id/index gets new ones.
 * Resolves the stored meta.
 */
let saveQueue=Promise.resolve();
export function saveMap(files){const snapshot=copy(files);const result=saveQueue.catch(()=>{}).then(()=>saveMapNow(snapshot));saveQueue=result;return result;}
async function saveMapNow(files) {
  const meta = { ...files.meta, format: META_FORMAT };
  const list=await listMaps();
  const now = Date.now();
  if (!meta.id) meta.id = `cm${now.toString(36)}${Math.floor(Math.random() * 1e6).toString(36)}`;
  if(!isCustomIndex(meta.index)||list.some(e=>Number(e.index)===Number(meta.index)&&e.id!==meta.id))meta.index=await nextIndex();
  if (!meta.created) meta.created = now;
  meta.modified = Math.max(now,(list.find(e=>e.id===meta.id)?.modified||0)+1);
  const rec = { id: meta.id, meta, map: files.map, mol: files.mol, mac: files.mac };
  const cat = catalogEntry(meta);
  const db = await openDB();
  if (!db) { mem.files.set(meta.id, rec); mem.catalog.set(meta.id, cat); }
  else await new Promise((resolve,reject)=>{
    const transaction=db.transaction(['files','catalog'],'readwrite'),f=transaction.objectStore('files'),c=transaction.objectStore('catalog'),request=c.getAll();
    transaction.oncomplete=resolve;transaction.onerror=()=>reject(transaction.error);transaction.onabort=()=>reject(transaction.error||new Error('Map save aborted.'));
    request.onsuccess=()=>{const rows=request.result||[];if(rows.some(e=>Number(e.index)===Number(meta.index)&&e.id!==meta.id))meta.index=Math.max(CUSTOM_BASE,...rows.map(e=>Number(e.index)||0))+1;meta.modified=Math.max(meta.modified,(rows.find(e=>e.id===meta.id)?.modified||0)+1);f.put(rec);c.put(catalogEntry(meta));};
  });
  notify({ type: 'saved', id: meta.id, index: meta.index });
  return meta;
}

export async function deleteMap(id) {
  const db = await openDB();
  const e = (await listMaps()).find(m => m.id === id);
  if (!db) { mem.files.delete(id); mem.catalog.delete(id); }
  else await tx(db, ['files', 'catalog'], 'readwrite', (f, c) => { f.delete(id); c.delete(id); });
  notify({ type: 'deleted', id, index: e?.index });
  return true;
}

/** Export one stored map as a .dkmap ArrayBuffer. */
export async function exportMap(id) {
  const r = await loadMap(id);
  return r ? packDkmap(r) : null;
}

/**
 * Import a .dkmap (ArrayBuffer). The imported map always gets a new id and index (no overwrite).
 * Resolves the stored meta, or null when the file is not a .dkmap.
 */
export async function importMap(buf, { keepName = true } = {}) {
  const r = unpackDkmap(buf);
  if (!r) return null;
  // Parse before publishing: malformed files must not pollute the saved catalog.
  validateMapFiles(r);
  const doc=MapDoc.fromFiles(r);r.meta=doc.meta;
  const meta = { ...r.meta, id: null, index: null, created: 0 };
  if (!keepName) meta.name = `${meta.name || 'Imported'} (copy)`;
  return saveMap({ ...r, meta });
}
