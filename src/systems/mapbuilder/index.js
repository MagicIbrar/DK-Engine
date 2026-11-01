// Map builder - in-game side: custom maps are real game maps.
//
//   * Custom maps (IndexedDB, store.js) get map indices 90001+ and a synthesised maplist row (camera / zone columns
//     of a base map, the map's own name, light file, clip distance, level gates, return point). game.data.mapByIndex
//     answers these rows, so game.travel / enterMap / play.html?map=N / warp code work unchanged.
//   * world.js loads them through row.source(): the stored original-format files (.map v20051216, .mol, .mac) plus
//     the spawns (Spawner, with respawn), NPC placements (with job overrides), start point, edited light keys and
//     the builder's minimap render (registered as imagetable sprite minimap#<index> for the HUD minimap / big map).
//   * Portals (walk-in boxes) of the current custom map travel to any map or custom map; the BGM is the chosen map's.
//   * Entries: the teleport NPC menu (dungeons travel dialog) gets "[Custom Maps]", the big map (M) premium teleport
//     list lists every custom map, chat command /custommap (list | <name or index> | builder), game.customMaps API
//     for the GM panel, tools/mapbuilder.html (the editor itself) has "Play".
//
// Public API: game.customMaps = { list(), refresh(), entry(idOrIndex), play(idOrIndex, pos?), openBuilder(id?),
//   isCustom(index), current(), store } (store = store.js: listMaps/loadMap/saveMap/deleteMap/exportMap/importMap).
import * as store from './store.js';
import { CUSTOM_BASE, isCustomIndex, writeMol } from './format.js';
import { parseMol } from '../../formats/mol.js';
import { atlas } from '../../ui/atlas.js';
import {hasGMPanelPermission,requireGMPanelPermission} from '../gm/permissions.js';

const PORTAL_CHECK = 0.1;
const MSG_LOW = 'Your level is too low to enter.';
const MSG_HIGH = 'You are not in the right level to enter.';

const S = { game: null, context: null, catalog: [], byIndex: new Map(), metaCache: new Map(), portals: [], armed: false, t: 0, mapIndex: -1, current: null };

// ------------------------------------------------------------------------------------------ install
export async function install(game) {
  dispose();S._chatHooked=false;S._mapWinHooked=false;S.metaCache.clear();rowCache.clear();S.off=[];
  S.game = game;
  const context=S.context={game};
  await refresh();
  // maplist rows for custom indices
  const data = game.data;
  if (data && typeof data.mapByIndex === 'function' && !data._customMapsWrapped) {
    const orig = data.mapByIndex.bind(data);
    data._customMapsWrapped = true;
    data.mapByIndex = (i) => orig(i) || customRow(i);
  }
  S.off.push(store.onChange(() => { refresh().catch(() => {}); }));

  game.customMaps = {
    list: () => S.catalog.slice(),
    refresh,
    entry: (k) => entryOf(k),
    play: (k, pos) => play(k, pos),
    openBuilder: (id) => openBuilder(id,context),
    isCustom: (i) => isCustomIndex(i) && S.byIndex.has(Number(i)),
    current: () => S.current,
    store,
    CUSTOM_BASE,
  };

  S.off.push(game.events?.on?.('map', ({ index }) => onMap(index)),game.events?.on?.('teleport', () => { S.armed = false; }),game.events?.on?.('systems', () => hookEntries()));
  hookEntries();
}

export function update(dt, game) {
  if (!S.portals.length || game.paused || game._loadingMap) return;
  const p = game.player, w = game.world;
  if (!p || p.dead || !w || w.info.index !== S.mapIndex) return;
  S.t -= dt;
  if (S.t > 0) return;
  S.t = PORTAL_CHECK;
  const hit = S.portals.find(q => p.x >= q.x0 && p.x < q.x1 && p.z >= q.z0 && p.z < q.z1);
  if (!hit) { S.armed = true; return; }
  if (!S.armed) return;
  S.armed = false;
  const to = hit.to || {};
  const dest = to.custom ? entryOf(to.custom)?.index : Number(to.map);
  if (dest == null || !Number.isFinite(dest) || !game.mapRow?.(dest)) { game.hud?.log?.('This portal leads nowhere.', 'err'); return; }
  if (!levelOk(dest)) return;
  game.controller?.stop?.();
  game.events?.emit?.('warpzone', { from: w.info.index, zone: hit.id, to: { map: dest, x: to.x, z: to.z } });
  const pos = Number.isFinite(Number(to.x)) && Number.isFinite(Number(to.z)) ? { x: Number(to.x), z: Number(to.z), dirDeg: Number(to.dirDeg) || 0 } : null;
  setTimeout(() => { Promise.resolve(game.travel(dest, pos)).catch(err => console.error('[mapbuilder] portal travel', err)); }, 0);
}

export function dispose() { S.context=null;S.portals = [];for(const off of S.off||[])if(typeof off==='function')off();S.off=[];S.game=null; }

// ------------------------------------------------------------------------------------------ catalog + rows
async function refresh() {
  const previous=new Map(S.catalog.map(e=>[e.id,e.modified]));
  // The player client installs systems before its shared map catalog exists.
  // Waiting for a local IndexedDB editor catalog here can stall the loading
  // screen; the server catalog refreshes us as soon as network installs it.
  S.catalog = S.game?.save?.authority==='server' ? (S.game.serverMaps?.list()||[]) : await store.listMaps().catch(() => []);
  for(const e of S.catalog)if(previous.get(e.id)!==e.modified){S.metaCache.delete(e.id);rowCache.delete(Number(e.index));}
  for(const id of S.metaCache.keys())if(!S.catalog.some(e=>e.id===id))S.metaCache.delete(id);
  S.byIndex = new Map(S.catalog.map(e => [Number(e.index), e]));
  for (const e of S.catalog) if (e.minimap) defineMinimap(e.index, e.minimap);
  return S.catalog;
}

function entryOf(k) {
  if (k == null) return null;
  if (typeof k === 'object') return k;
  const n = Number(k);
  if (Number.isFinite(n) && S.byIndex.has(n)) return S.byIndex.get(n);
  const s = String(k).toLowerCase();
  return S.catalog.find(e => e.id === k) || S.catalog.find(e => String(e.name || '').toLowerCase() === s) || null;
}

const rowCache = new Map();
function customRow(i) {
  const e = S.byIndex.get(Number(i));
  if (!e) return null;
  const key = `${e.id}@${e.modified}`;
  const hit = rowCache.get(Number(i));
  if (hit && hit.key === key) return hit.row;
  const data = S.game?.data;
  const base = (data?.maps?.get(Number(e.basedOn)) || data?.maps?.get(150) || data?.maps?.get(0) || {});
  const env = e.env || {};
  const st = e.start || { x: e.size / 2, z: e.size / 2, dirDeg: 0 };
  const idx = Number(e.index);
  const row = {
    ...base,
    Index: String(idx), Name: e.name || `Custom Map ${idx - CUSTOM_BASE}`,
    MapFile: `custom_${idx}.map`, MapObject: `custom_${idx}.mol`, MapEffect: '', MapAttribute: `custom_${idx}.mac`,
    PosFile: '', MapPath: '', MonsterLocatePath: '', NPCLocatePath: '', BrickLocatePath: '', TriggerLocatePath: '',
    CallMonsterPath: '', ScriptName: '', Preloading: '', DungeonIndex: '0', TROOP_LOBBY: '0', Map_Type: '0',
    LimitMinLevel: String(env.minLevel || 1), LimitMaxLevel: String(env.maxLevel || 250),
    RetMapIndex: String(idx), RetX: String(Math.floor(st.x)), RetY: String(Math.floor(st.z)), RetDirection: String(st.dirDeg || 0),
    custom: true, customId: e.id,
    source: () => loadSource(e.id, idx),
  };
  // the environment columns come from the stored meta (loaded lazily); the catalog carries the light file name
  const full = S.metaCache.get(e.id);
  const m = full?.env || env;
  row.EnvironmentFile = m.light || base.EnvironmentFile || 'light_braiken.txt';
  row.EnvironmentMap = m.envMap || base.EnvironmentMap || 'water/skyCube=.dds';
  row['OnedayTime(Min)'] = String(m.dayMinutes || 90);
  row.Clip_Far = String(m.clipFar || 75);
  row.IsReturnScroll = String(m.returnScroll ?? 1);
  rowCache.set(idx, { key, row });
  return row;
}

/** row.source() of a custom map (world.js): the stored files + placements. */
async function loadSource(id, index) {
  const rec = S.game?.save?.authority==='server'&&S.game.serverMaps?await S.game.serverMaps.source(index):await store.loadMap(id);
  if (!rec) throw new Error(`custom map ${id} is missing`);
  const meta = rec.meta || {};
  S.metaCache.set(id, meta);
  let mol = rec.mol;
  const extra = (meta.portals || []).filter(p => p.object).map(p => ({
    name: p.object, x: (p.x0 + p.x1) / 2, z: (p.z0 + p.z1) / 2, y: 0, qx: 0, qy: Math.sin(((p.dirDeg || 0) * Math.PI) / 360), qz: 0, qw: Math.cos(((p.dirDeg || 0) * Math.PI) / 360), scale: p.scale || 1,
  }));
  if (extra.length) {
    try { mol = writeMol([...(mol ? parseMol(mol).objects : []), ...extra]); } catch (err) { console.warn('[mapbuilder] portal objects', err); }
  }
  if (meta.minimap) defineMinimap(index, meta.minimap);
  const spawns = (meta.spawns || []).filter(s => Number.isFinite(Number(s.x)) && Number.isFinite(Number(s.z)))
    .map(s => ({ monsterIndex: Number(s.monsterIndex), x: Number(s.x), z: Number(s.z), respawnSec: Number(s.respawnSec) || 30 }));
  const npcPlacements = (meta.npcs || []).filter(n => Number.isFinite(Number(n.x)) && Number.isFinite(Number(n.z)))
    .map(n => ({ npcIndex: Number(n.npcIndex), x: Number(n.x), z: Number(n.z), dirDeg: Number(n.dirDeg) || 0, warpX: 0, warpZ: 0, isEvent: false, desc: '', custom: { name: n.name || null, jobs: Array.isArray(n.jobs) ? n.jobs : null, id: n.id } }));
  return {
    map: rec.map, mol, mac: rec.mac, spawns, npcPlacements,
    start: meta.start ? { x: Number(meta.start.x), z: Number(meta.start.z), dirDeg: Number(meta.start.dirDeg) || 0 } : null,
    lightText: meta.env?.lightText || null,
    minimap: meta.minimap ? { key: null, url: meta.minimap, transposed: true } : null,
    meta,
  };
}

/** Register the builder's minimap render as imagetable sprite minimap#<index> (HUD minimap / big map windows). */
function defineMinimap(index, url) {
  if (!url || typeof document === 'undefined') return;
  const id = `minimap#${Number(index)}`;
  if (atlas._customMinimaps?.get(id) === url) return;
  (atlas._customMinimaps ||= new Map()).set(id, url);
  const p = new Promise((res) => {
    const img = new Image();
    img.onload = () => {
      const cv = document.createElement('canvas');
      cv.width = img.width; cv.height = img.height;
      cv.getContext('2d').drawImage(img, 0, 0);
      const out = { url, w: img.width, h: img.height, canvas: cv, row: { key: `custom/minimap_${index}.png`, x: 0, y: 0, w: img.width, h: img.height, m: [0, 0, 0, 0] } };
      (atlas._done ||= new Map()).set(id, out);
      res(out);
    };
    img.onerror = () => res(null);
    img.src = url;
  });
  atlas._spr?.set?.(id, p);
  atlas.load?.().then(() => { atlas.table?.set?.(id, { key: `custom/minimap_${index}.png`, x: 0, y: 0, w: 512, h: 512, m: [0, 0, 0, 0] }); }).catch(() => {});
}

// ------------------------------------------------------------------------------------------ map entry
function onMap(index) {
  const g = S.game;
  S.mapIndex = Number(index);
  S.portals = [];
  S.current = null;
  S.armed = false;
  const src = g.world?.source;
  if (!src || !isCustomIndex(index)) return;
  const meta = src.meta || {};
  S.current = { index: Number(index), id: meta.id, name: meta.name };
  S.portals = (meta.portals || []).filter(p => [p.x0, p.z0, p.x1, p.z1].every(v => Number.isFinite(Number(v))))
    .map(p => ({ ...p, x0: Math.min(p.x0, p.x1), x1: Math.max(p.x0, p.x1), z0: Math.min(p.z0, p.z1), z1: Math.max(p.z0, p.z1) }));
  // NPC names / jobs set in the builder
  const jt = g.data?.npcs?.jobTypes || {};
  for (const n of g.npcs || []) {
    const c = n.placement?.custom;
    if (!c) continue;
    if (c.jobs) {
      const jobs = c.jobs.map(([a, b]) => [Number(a), Number(b) || 0]);
      const roles = jobs.map(([a]) => jt[a]?.name).filter(Boolean);
      n.def = { ...n.def, jobs, roles };
      n.jobs = jobs; n.roles = roles;
    }
    if (c.name) { n.name = c.name; n.def = { ...n.def, name: c.name, desc: null }; }
  }
  // BGM of the chosen map
  const bgm = Number(meta.env?.bgmMap);
  const A = g.audio;
  if (A && Number.isFinite(bgm) && A.S?.bgmByMapIndex) {
    A.S.bgmByMapIndex[String(index)] = A.S.bgmByMapIndex[String(bgm)] || [];
    if (A.music) A.music.mapIndex = null;
    try { A.playBGM(Number(index)); } catch { /* ignore */ }
  }
  // fixed time of day
  const env = g.world?.environment;
  const h = meta.env?.fixedHour;
  if (env && h != null && h !== '' && Number.isFinite(Number(h))) { env.setHour(Number(h)); env.fixedTime = env.time; }
}

function levelOk(index) {
  const g = S.game;
  const row = g.mapRow?.(index);
  if (!row) return false;
  const lvl = Number(g.save?.level) || 1;
  const min = Number(row.LimitMinLevel) || 0, max = Number(row.LimitMaxLevel) || 0;
  if (min > 0 && lvl < min) { g.hud?.log?.(MSG_LOW, 'err'); return false; }
  if (max > 0 && lvl > max) { g.hud?.log?.(MSG_HIGH, 'err'); return false; }
  return true;
}

/** Travel to a custom map (its start point, or pos). Resolves false when unknown or level-gated. */
async function play(k, pos = null) {
  await refresh();
  const e = entryOf(k);
  const g = S.game;
  if (!e || !g) return false;
  if(g.save?.authority==='server'){
    if(e.server){
      if(!g.accountPermissions?.capabilities?.includes('gm:commands')){if(!levelOk(e.index))return false;await g.travel(Number(e.index),pos);return true;}
      if(!g.network?.ready)throw new Error('Connect to the shared world before entering a published map.');
      const network=g.network,token=network.token,generation=network._leaseGeneration;
      const result=await network._request('gm',{token,operation:'customMapEnter',index:Number(e.index)});
      if(S.game!==g||g.network!==network||network.token!==token||network._leaseGeneration!==generation||!network.ready||network.disposed)throw new Error('The Map Builder session changed. Reconnect and retry.');
      if(result.state)network._receiveSnapshot(result.state);if(result.message)g.hud?.log?.(result.message,'sys');return true;
    }
    globalThis.open?.(`/tools/map-preview.html?map=${Number(e.index)}`,'_blank');
    g.hud?.log?.('Opened a temporary local map preview. The shared world is unchanged.','sys');return true;
  }
  if (!levelOk(e.index)) return false;
  g.controller?.stop?.();
  await g.travel(Number(e.index), pos);
  return true;
}

function openBuilder(id,context=S.context) {
  const game=context?.game;
  if(!game||S.context!==context||S.game!==game)throw Error('The Map Builder game context changed.');
  requireGMPanelPermission(game);
  const publication=game.serverMaps;
  const url = `/tools/mapbuilder.html${id ? `?map=${encodeURIComponent(id)}` : ''}`;
  const opened=globalThis.open?.(url, '_blank');
  if(opened&&publication)opened.addEventListener?.('load',()=>{
    if(opened.closed||S.context!==context||S.game!==game||game.serverMaps!==publication||!hasGMPanelPermission(game))return;
    opened.mapPublication=publication;opened.dispatchEvent(new opened.Event('mappublicationready'));
  });
  return url;
}

// ------------------------------------------------------------------------------------------ entries
function mapLabel(e) { return `${e.name} [ ${e.size}x${e.size} ]`; }

function hookEntries() {
  const g = S.game,context=S.context;
  // teleport / portal NPCs: "[Custom Maps]" at the end of their menu (dungeons travel dialog)
  const T = g.dungeons?.travel;
  if (T && !T._customMapsWrapped && T.sys?.dialog) {
    T._customMapsWrapped = true;
    const wrap = (name) => {
      const orig = T[name]?.bind(T);
      if (!orig) return;
      T[name] = (npc, ...rest) => {
        const dlg = T.sys.dialog, open = dlg.open;
        if (S.catalog.length) {
          dlg.open = function (opts = {}) {
            dlg.open = open;
            const menu = [...(opts.menu || []), { text: '[Custom Maps] Maps made in the Map Builder', onClick: (d) => customMenu(npc, d) }];
            return open.call(dlg, { ...opts, menu });
          };
        }
        try { return orig(npc, ...rest); } finally { dlg.open = open; }
      };
    };
    wrap('teleportMenu');
    wrap('portalMenu');
  }
  // big map (M): premium teleport list rows
  const mgr = g.uiwin;
  if (mgr && !S._mapWinHooked) {
    S._mapWinHooked = true;
    const hookWin = (win) => {
      if (!win || win.name !== 'map' || win.data?._customMaps) return;
      const tp = win.find?.('list_teleportlist');
      if (!tp || typeof tp.setItems !== 'function') return;
      win.data._customMaps = true;
      const orig = tp.setItems.bind(tp);
      tp.setItems = (items = []) => orig([...items.filter(it => !it?.data?.customMap), ...S.catalog.map(e => ({ text: `[Custom] ${mapLabel(e)}`, data: { customMap: e.id }, color: 'ff9fd7ff' }))]);
      tp.on('dblclick', () => {
        const it = tp.items?.[tp.getSelected?.()];
        if (it?.data?.customMap) { win.close('teleport'); play(it.data.customMap); }
      });
    };
    mgr.on('create', hookWin);
    mgr.on('open', hookWin);
    const w = mgr.window?.('map');
    if (w) hookWin(w);
  }
  // chat command
  if (g.chat?.registerCommand && !S._chatHooked) {
    S._chatHooked = true;
    g.chat.registerCommand('/custommap', (args) => {
      const a = String(args || '').trim();
      if (!a || a === 'list') {
        if (!S.catalog.length) g.chat.system('No custom maps yet. Type /custommap builder to open the Map Builder.');
        for (const e of S.catalog) g.chat.system(`${e.index - CUSTOM_BASE}. ${mapLabel(e)}  (/custommap ${e.index - CUSTOM_BASE})`);
        return true;
      }
      if (a === 'builder' || a === 'edit') { openBuilder(S.current?.id,context); return true; }
      const n = Number(a);
      const e = Number.isFinite(n) ? entryOf(n < CUSTOM_BASE ? CUSTOM_BASE + n : n) : entryOf(a);
      if (!e) { g.chat.system(`No custom map "${a}".`, 'err'); return true; }
      play(e.id);
      return true;
    }, '/custommap [list | number | name | builder]');
  }
}

function customMenu(npc, dlg) {
  const g = S.game, d = dlg || g.dungeons?.travel?.sys?.dialog;
  if (!d) return;
  const lvl = Number(g.save?.level) || 1;
  const menu = S.catalog.map(e => {
    const min = Number(e.env?.minLevel) || 0;
    return { text: `${mapLabel(e)}${min > 1 ? ` Lv.${min}` : ''}${min > lvl ? ' (locked)' : ''}`, onClick: () => { play(e.id); } };
  });
  const page = { title: npc?.name || 'Custom Maps', text: 'Where do you want to go?', menu };
  if (typeof d.push === 'function' && d.isOpen) d.push(page); else d.open(page);
}
