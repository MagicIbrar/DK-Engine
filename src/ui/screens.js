// Screens outside the world. The login / character select / character create screens are the 3D front-end
// (src/ui/frontend/, docs/ARCHITECTURE.md §3.9, started by src/main.js). This module keeps the LOADING screen the
// Game shows while it enters the world and changes maps (game.js showLoading), never before the login screen.
//
// Loading screen = the original window script/ui/game2/ui_loadwnd.txt, built by the UI platform (src/ui/uiwin):
//   pan_map        the map's loading art, imagetable group `loadingmap`, index = maplist index (1024x768, stretched
//                  over the screen like the client; maps without an entry keep the script's index 0)
//   pan_load1 + pan_bar1 / pan_loading / pro_loading / pan_loadend   the original progress bar (group Loading #1-#3
//                  frame, #10 / #11 blue fill, process bar maxsize 547); the end cap (colour 00000000 in the script)
//                  lights up when loading completes
//   pan_info + lbl_infostr   the tip band (movemaptip#1) with a tip of script/loading_map_info.csv for the map
//                  (Map_Index 65535 = any map)
// The map is known before the tables load: setLoadingMap() (the front-end hand-off) or title(name, mapIndex).
import { UIManager } from './uiwin/index.js';
import { texts } from './frontend/texts.js';
import { atlas } from './atlas.js';
import { fetchCSVObjects } from '../engine/assets.js';
import { loadingArtGate } from './loading-art.js';
import { startupDisplayProgress } from '../engine/startup-progress.js';

const LOADWND = 'game2/ui_loadwnd.txt';
let pendingMap = null;
let mapRows = null;

/** The front-end stylesheet (fade / loading layers; also keeps #ui's uiwin layer transparent to the mouse). */
export function ensureFrontCSS() {
  if (typeof document === 'undefined' || document.querySelector('link[data-fe-css]')) return;
  const l = document.createElement('link');
  l.rel = 'stylesheet';
  l.href = '/src/ui/frontend/frontend.css';
  l.dataset.feCss = '1';
  document.head.appendChild(l);
}

/** The map the next loading screen is for (set by the front-end hand-off before the Game starts). */
export function setLoadingMap(index) { pendingMap = index == null ? null : Number(index); }

/** Optional: the maplist rows (Map index -> row) so title(name) can find the map by name. */
export function setMapNames(maps) { if (maps) mapRows = Promise.resolve(maps); }

function mapIndexByName(name) {
  if (!mapRows) {
    mapRows = fetchCSVObjects('share/maplist.csv').then(rows => {
      const m = new Map();
      for (const r of rows) if (r.MapFile && Number.isFinite(Number(r.Index))) m.set(Number(r.Index), r);
      return m;
    }).catch(() => new Map());
  }
  return mapRows.then(maps => {
    for (const [i, r] of maps) if (String(r.Name || '').trim() === String(name || '').trim()) return i;
    return null;
  });
}

/**
 * Decode the loading art of a map and the bar / tip sprites ahead of time (the 1024x768 DDS takes a moment), so the
 * loading screen appears complete at once. The front-end hand-off awaits it while the scene fades out.
 */
export async function preloadLoading(mapIndex) {
  await Promise.all([atlas.load(), texts.load()]);
  const idx = mapIndex != null && atlas.rect('loadingmap', mapIndex) ? Number(mapIndex) : 0;
  await Promise.all([
    mapIndex != null ? atlas.sprite('loadingmap', idx) : null,
    ...[1, 2, 3, 10, 11].map(i => atlas.sprite('Loading', i)),
    atlas.sprite('movemaptip', 1),
  ].map(p => Promise.resolve(p).catch(() => null)));
}

/** Client markup of a tip -> uiwin rich text. */
const tipText = s => String(s || ' ').replace(/\\n/g, '\n').replace(/<\/?center>/gi, '');

// ENGINE-CHOSEN loading guidance; no completion-time promise or raw error echo.
const LOADING_WAIT='Preparing the game, map and nearby players. Please wait.';
const LOADING_FAILED='Loading stopped unexpectedly. Retry once; if it stops again, report the loading stage.';
const LOADING_ERRORS=new Map([
 ['Shared network installation did not complete. Retry loading.','Network installation did not finish. Retry loading.'],
 ['Shared world preparation did not complete before network installation. Retry loading.','Server preparation did not finish. Retry loading.'],
 ['Shared world preparation is not ready. Retry loading.','Server preparation is not ready. Retry loading.'],
 ['Shared world admission is not ready. Retry loading.','World connection is not ready. Retry loading.'],
 ['Shared map loading did not complete. Retry loading.','Map loading did not finish. Retry loading.'],
 ['Shared admission or map changed before entry. Retry loading.','World connection or map changed before entry. Retry loading.'],
 ['Shared admission or map changed during loading. Retry loading.','World connection or map changed during loading. Retry loading.'],
 ['Initial shared actor admission changed. Retry loading.','Nearby player admission changed. Retry loading.'],
 ['Initial shared actor scene or lease changed. Retry loading.','Nearby player scene or connection changed. Retry loading.'],
 ['An initial shared actor body did not finish loading. Retry loading.','Nearby character model did not finish loading. Retry loading.'],
 ['An initial shared actor weapon did not finish loading. Retry loading.','Nearby character weapon did not finish loading. Retry loading.'],
 ['An initial shared actor animation did not finish loading. Retry loading.','Nearby character animation did not finish loading. Retry loading.'],
 ['Invalid world readiness response.','Server preparation response was invalid. Retry loading.'],
 ['Network installation was cancelled. Retry loading.','Network installation was cancelled. Retry loading.'],
]);
function loadingFailureText(reason, phase){
 if(reason?.missing)return 'A required game file is missing. Repair or reinstall the client, then retry. (FILE-MISSING)';
 if([401,403].includes(reason?.status))return 'Your server sign-in expired or was denied. Sign in again, then retry. (SIGN-IN)';
 if([429,502,503,504].includes(reason?.status))return 'The game server is busy or unavailable. Wait a moment, then retry. (SERVER-BUSY)';
 if(reason?.status>=500)return 'The game server could not provide a required file. Retry shortly. (SERVER-ERROR)';
 if(reason?.name==='AbortError')return 'A loading request timed out or was cancelled. Retry loading. (TIMEOUT)';
 if(reason?.networkCategory==='incompatible'||reason?.networkCategory==='protocol')return 'This server did not provide a valid game response. Check that the client and server versions match. (PROTOCOL)';
 if(reason?.networkCategory==='network')return 'The game could not reach the server. Check the connection and retry. (CONNECTION)';
 if(reason?.networkCategory==='client')return 'The game could not finish joining after the server answered. Retry loading. (CLIENT)';
 if(reason?.networkCategory==='conflict')return 'Your world connection changed while joining. Retry loading. (CONNECTION-CHANGED)';
 const message=typeof reason==='string'?reason:typeof reason?.message==='string'?reason.message:'';
 if(message.length<=256&&LOADING_ERRORS.has(message))return LOADING_ERRORS.get(message);
 if(reason?.transient||/^(?:Failed to fetch|NetworkError when attempting to fetch resource\.)$/.test(message))
  return 'A game file or server request was interrupted. Check the connection and retry. (CONNECTION)';
 const stage=typeof phase==='string'&&phase.length<=80?phase:'Loading';
 return stage+' '+LOADING_FAILED;
}
const LOADING_SYSTEM_LABELS=Object.freeze({warpzones:'Warp zones',items:'Items',life:'Life skills',shops:'Shops',mounts:'Mounts',dungeons:'Dungeons',quests:'Quests',events:'Events',skills:'Skills',graphics:'Graphics',
 'hud-options':'Interface',mapbuilder:'Map tools',itembuilder:'Item tools',charwin:'Character panel',gm:'GM panel',network:'World connection',extras:'Help panels',inspect:'Inspect panel',chartrade:'Character trade',skillmaster:'Skill learning'});
function loadingPhaseText(what){
 const text=typeof what==='string'&&what.length<=256?what:'';
 const panels=/^Preparing interface panels\.\.\. (\d+)\/(\d+)$/.exec(text);
 if(panels&&Number(panels[1])<=Number(panels[2]))return `Preparing interface panels (${panels[1]}/${panels[2]}).`;
 const system=/^Starting systems\.\.\. (\d{1,2})\/(\d{1,2}) \(([a-z-]+)\)$/.exec(text);
 if(system&&Object.hasOwn(LOADING_SYSTEM_LABELS,system[3])){
  const done=Number(system[1]),total=Number(system[2]);
  if(done<=total&&total>0&&total<=20)return 'Starting game systems: '+LOADING_SYSTEM_LABELS[system[3]]+' ('+done+'/'+total+').';
 }
 if(['Reading the map','Placing objects','World ready'].includes(text))return 'Preparing map content.';
 if(['Ground tiles','Ground decals','Ground ready'].includes(text))return 'Preparing ground textures.';
 const objects=/^Objects (\d+)\/(\d+)$/.exec(text);
 if(objects&&Number(objects[1])<=Number(objects[2]))return 'Preparing nearby map objects ('+objects[1]+'/'+objects[2]+').';
 const phases=[['Reading ','Reading game tables.'],['Starting systems','Starting game systems.'],['Summoning your character','Preparing your character.'],['Placing townsfolk','Preparing townsfolk.'],['Waking the monsters','Preparing creatures.'],['Preparing interface artwork','Preparing interface artwork.'],['Preparing inventory and skill icons','Preparing inventory and skill icons.'],['Preparing nearby players and creatures','Preparing nearby players and creatures.'],['Preparing the scene','Preparing the scene.']];
 return phases.find(([prefix])=>text.startsWith(prefix))?.[1]||'Preparing game/map and players.';
}

/**
 * Show the loading screen. Returns { set(frac, what), title(name, mapIndex?), map(index), close() }.
 * @param {HTMLElement} root
 * @param {string} title       map name (only used to find the map when no index is known)
 * @param {number} [mapIndex]
 */
export function showLoading(root, title = '', mapIndex = null, {artwork = null, startup = false} = {}) {
  ensureFrontCSS();
  const scr = document.createElement('div');
  scr.className = 'fe-loading';
  root.appendChild(scr);
  const state = { frac: 0, map: mapIndex != null ? Number(mapIndex) : pendingMap, closed: false, win: null, shownMap: undefined, lit: null, phase: loadingPhaseText(''), failureText: null };
  pendingMap = null;
  let mapRequest=0;
  let displayed=0,progressFrame=null,progressAt=null;
  const stopProgress=()=>{if(progressFrame!==null)globalThis.cancelAnimationFrame?.(progressFrame);progressFrame=null;progressAt=null;};
  const mgr = new UIManager(null, scr, { scale: 1 });
  mgr.layer.style.opacity='0';
  const artGate=loadingArtGate({
    load:index=>startup?atlas.sprite('preloading',1):artwork?atlas.sprite(artwork.screen,artwork.index):index==null||!atlas.rect('loadingmap',index)?null:atlas.sprite('loadingmap',index),
    paint:sprite=>state.win?.control(startup?'pan_back':'pan_map').setImage('none',sprite?{url:sprite.url}:null),
    hide:()=>{mgr.layer.style.opacity='0';},
    show:()=>{mgr.layer.style.opacity='';},
  });

  const apply = () => {
    const w = state.win;
    if (!w || state.closed) return;
    if(startup){
      w.control('lbl_count').setText(`LOADING...${displayed===1?'100.0':(Math.floor(displayed*1000)/10).toFixed(1)}%`);
      // Native script contains an FMOD logo; this engine does not use FMOD.
      w.control('pan_fmod').hide();
      if(state.shownMap!==state.map){state.shownMap=state.map;void artGate.select(state.map);}
      return;
    }
    w.control('pro_loading').setGauge(state.frac);
    // pan_loadend (Loading #3) is the RIGHT end of the bar frame (pan_load1 is the left end). The script's colour 00000000
    // reads as "no tint", not "invisible": without it the end of the loading bar goes missing. Always drawn.
    if (!state.lit) {
      state.lit = true;
      w.control('pan_loadend').setImage('none', { screen: 'Loading', index: 3, color: 'ffffffff' });
    }
    // pan_map contains the bar/tip; cover the layer rather than hiding that panel.
    if(state.shownMap!==state.map){state.shownMap=state.map;void artGate.select(state.map);}
    w.control('lbl_infostr').setRichText(state.phase+'\n'+(state.failed?state.failureText.textContent:LOADING_WAIT));
  };

  const animateProgress=at=>{
    progressFrame=null;
    if(state.closed||state.failed)return;
    displayed=startupDisplayProgress(displayed,state.frac,progressAt===null?16:at-progressAt);
    progressAt=at;apply();
    if(displayed<state.frac)progressFrame=globalThis.requestAnimationFrame(animateProgress);
    else progressAt=null;
  };

  // open once the art is decoded (a black screen for that moment, never a half-drawn window)
  const artReady = Promise.race([(startup?atlas.sprite('preloading',1):preloadLoading(state.map)).catch(() => null), new Promise(r => setTimeout(r, 2500))]);
  const ready = Promise.all([texts.load(), mgr.ready, artReady])
    .then(() => mgr.create(startup?'game2/ui_preloadwnd.txt':LOADWND, { name: startup?'preloadwnd':'loadwnd', escClose: false, remember: false, autoClose: false }))
    .then(win => {
      if (state.closed) { win.dispose(); return; }
      state.win = win;
      mgr.openWindow(win);
      apply();
    })
    .catch(err => console.warn('[loading] window unavailable', err));

  if (state.map == null && title) {const request=++mapRequest;mapIndexByName(title).then(i => { if (!state.closed&&request===mapRequest&&i != null && state.map == null) { state.map = i; apply(); } });}

  return {
    ready,
    set(frac, what = '') {
      if (state.closed||state.failed) return;
      const next = Math.max(0, Math.min(1, Number(frac) || 0));
      if (next < state.frac) return; // Late phase callbacks must never rewind the bar or label.
      state.frac = next;
      if(startup){
        if(next===1||typeof globalThis.requestAnimationFrame!=='function'){stopProgress();displayed=next;}
        else if(progressFrame===null)progressFrame=globalThis.requestAnimationFrame(animateProgress);
      }
      state.phase=loadingPhaseText(what);
      scr.dataset.what = state.phase;
      apply();
    },
    title(name, index = null) {
      const request=++mapRequest;
      if (index != null) { state.map = Number(index); apply(); }
      else if (name) mapIndexByName(name).then(i => { if (!state.closed&&request===mapRequest&&i != null) { state.map = i; apply(); } });
    },
    map(index) { mapRequest++;state.map = Number(index); apply(); },
    async presentComplete() {
      if(!startup||state.closed||state.failed||state.frac!==1)return;
      if(typeof globalThis.requestAnimationFrame==='function')await new Promise(resolve=>globalThis.requestAnimationFrame(()=>globalThis.requestAnimationFrame(resolve)));
    },
    fail(reason=null) {
      // ENGINE-CHOSEN fixed categories; never render arbitrary server details.
      if(state.closed)return;
      stopProgress();
      const label=loadingFailureText(reason,state.phase);
      if(state.failed)return;
      if(!state.failed){
        state.failed=true;
        const message=document.createElement('div'),text=document.createElement('span'),retry=document.createElement('button');
        message.setAttribute('role','alert');
        Object.assign(message.style,{position:'absolute',left:'50%',top:'65%',transform:'translateX(-50%)',zIndex:'100',color:'#efe0c2',background:'#16151c',padding:'16px',textAlign:'center'});
        state.failureText=text;message.appendChild(text);
        retry.type='button';retry.textContent='Retry loading';retry.onclick=()=>globalThis.location?.reload();
        message.appendChild(document.createElement('br'));message.appendChild(retry);scr.appendChild(message);
      }
      state.failureText.textContent=label;state.phase='Loading stopped.';apply();
    },
    close() {
      stopProgress();
      state.closed = true;
      artGate.close();
      scr.classList.add('out');
      setTimeout(() => { try { mgr.dispose(); } catch { /* ignore */ } scr.remove(); }, 260);
    },
  };
}

