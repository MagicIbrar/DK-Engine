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
//   pan_info + lbl_infostr   the tip band (movemaptip#1) with ONLY Global tips from script/loading_map_info.csv
//                  (Map_Index 65535 = any map). Never Engine-authored phase/progress copy.
// The map is known before the tables load: setLoadingMap() (the front-end hand-off) or title(name, mapIndex).
import { UIManager } from './uiwin/index.js';
import { texts } from './frontend/texts.js';
import { atlas } from './atlas.js';
import { fetchCSVObjects } from '../engine/assets.js';
import { loadingArtGate } from './loading-art.js';
import { startupDisplayProgress } from '../engine/startup-progress.js';
import { paceStep } from '../engine/loading-pacer.js';

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

const TIP_ROTATE_MS=8000; // ENGINE-CHOSEN: rotate Global guide tips while the bar advances
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
 if(reason?.name==='AbortError'||reason?.name==='TimeoutError')return 'A loading request timed out or was cancelled. Retry loading. (TIMEOUT)';
 if(reason?.networkCategory==='incompatible'||reason?.networkCategory==='protocol')return 'This server did not provide a valid game response. Check that the client and server versions match. (PROTOCOL)';
 if(reason?.networkCategory==='network')return 'The game could not reach the server. Check the connection and retry. (CONNECTION)';
 if(reason?.networkCategory==='client')return 'The game could not finish joining after the server answered. Retry loading. (CLIENT)';
 if(reason?.networkCategory==='conflict')return 'Your world connection changed while joining. Retry loading. (CONNECTION-CHANGED)';
 const message=typeof reason==='string'?reason:typeof reason?.message==='string'?reason.message:'';
 if(message.length<=256&&LOADING_ERRORS.has(message))return LOADING_ERRORS.get(message);
 if(reason?.transient||/^(?:Failed to fetch|NetworkError when attempting to fetch resource\.)$/.test(message))
  return 'A game file or server request was interrupted. Check the connection and retry. (CONNECTION)';
 // t128u: never echo Engine phase/progress into the failure line.
 return LOADING_FAILED;
}
// t128u: Engine loadingPhaseText / system labels removed. Progress what stays on dataset.what only;
// lbl_infostr shows Global tip (REA / loading_map_info.csv) or failure text — never custom object-prep lines.
/**
 * Show the loading screen. Returns { set(frac, what), title(name, mapIndex?), map(index), close() }.
 * @param {HTMLElement} root
 * @param {string} title       map name (only used to find the map when no index is known)
 * @param {number} [mapIndex]
 */
export function showLoading(root, title = '', mapIndex = null, {artwork = null, startup = false, pacing = null, catchUpMs = undefined, finishMs = undefined, maxStepMs = undefined, onDisplay = null, trackReal = false} = {}) {
  ensureFrontCSS();
  const scr = document.createElement('div');
  scr.className = 'fe-loading';
  root.appendChild(scr);
  const state = { frac: 0, map: mapIndex != null ? Number(mapIndex) : pendingMap, closed: false, win: null, shownMap: undefined, lit: null, phase: '', tip: '', tipTimer: null, failureText: null };
  pendingMap = null;
  let mapRequest=0;
  let displayed=0,progressFrame=null,progressAt=null;
  const paceOpts=()=>({table:pacing,...(catchUpMs!=null?{catchUpMs}:{}),...(finishMs!=null?{finishMs}:{}),...(maxStepMs!=null?{maxStepMs}:{})});
  // t104u: map bar tracks REAL load. Launch (startup) may keep paced Global-feel display.
  const showPaced = !!(pacing && startup && !trackReal);
  const gaugeValue = () => (showPaced ? displayed : state.frac);
  const stopProgress=()=>{if(progressFrame!==null)globalThis.cancelAnimationFrame?.(progressFrame);progressFrame=null;progressAt=null;};
  const mgr = new UIManager(null, scr, { scale: 1 });
  mgr.layer.style.opacity='0';
  const artGate=loadingArtGate({
    load:index=>startup?atlas.sprite('preloading',1):artwork?atlas.sprite(artwork.screen,artwork.index):index==null||!atlas.rect('loadingmap',index)?null:atlas.sprite('loadingmap',index),
    paint:sprite=>state.win?.control(startup?'pan_back':'pan_map').setImage('none',sprite?{url:sprite.url}:null),
    hide:()=>{mgr.layer.style.opacity='0';},
    show:()=>{mgr.layer.style.opacity='';},
  });

  const refreshTip = () => {
    if (state.closed || state.failed) return;
    // Prefer map-specific Global tips; tipFor already mixes any-map (65535) tips.
    const next = tipText(texts.tipFor(state.map));
    if (next && next.trim()) state.tip = next;
    else if (!state.tip) state.tip = '';
  };
  const startTipRotation = () => {
    if (state.tipTimer != null || typeof globalThis.setInterval !== 'function') return;
    refreshTip();
    state.tipTimer = globalThis.setInterval(() => { refreshTip(); apply(); }, TIP_ROTATE_MS);
  };
  const stopTipRotation = () => {
    if (state.tipTimer != null) { try { globalThis.clearInterval(state.tipTimer); } catch {} state.tipTimer = null; }
  };

  const apply = () => {
    const w = state.win;
    if (!w || state.closed) return;
    if(startup){
      w.control('lbl_count').setText(`LOADING...${displayed===1?'100.0':(Math.floor(displayed*1000)/10).toFixed(1)}%`);
      // Native script contains an FMOD logo; this engine does not use FMOD.
      w.control('pan_fmod').hide();
      if(state.shownMap!==state.map){state.shownMap=state.map;refreshTip();void artGate.select(state.map);}
      return;
    }
    w.control('pro_loading').setGauge(gaugeValue());
    // pan_loadend (Loading #3) is the RIGHT end of the bar frame (pan_load1 is the left end). The script's colour 00000000
    // reads as "no tint", not "invisible": without it the end of the loading bar goes missing. Always drawn.
    if (!state.lit) {
      state.lit = true;
      w.control('pan_loadend').setImage('none', { screen: 'Loading', index: 3, color: 'ffffffff' });
    }
    // pan_map contains the bar/tip; cover the layer rather than hiding that panel.
    if(state.shownMap!==state.map){state.shownMap=state.map;refreshTip();void artGate.select(state.map);}
    // t128u: Global tip/status only — never Engine phase like "Preparing nearby map objects (n/n)".
    w.control('lbl_infostr').setRichText(state.failed?(state.failureText?.textContent||' '):tipText(state.tip));
  };

  const animateProgress=at=>{
    progressFrame=null;
    if(state.closed||state.failed)return;
    const dt=progressAt===null?16:at-progressAt;
    progressAt=at;
    // Launch cover: LAUNCH_PACING via paceStep (displayed <= real). Legacy startup path
    // without a pacing table keeps startupDisplayProgress so older callers stay unchanged.
    if(showPaced){
      displayed=paceStep(displayed,state.frac,dt,paceOpts());
      onDisplay?.(displayed);
    }else if(pacing){
      // Map load: displayed tracks real immediately (t104u).
      displayed=state.frac; onDisplay?.(displayed);
    }else{
      displayed=startupDisplayProgress(displayed,state.frac,dt);
    }
    apply();
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
      if (!startup) startTipRotation();
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
      if(startup||pacing){
        // Launch (showPaced): never snap displayed to 1; presentComplete finishes.
        // Map trackReal: displayed follows real every set() so the bar never sits behind work.
        if(!showPaced){stopProgress();displayed=next;onDisplay?.(displayed);}
        else if(!pacing&&(next===1||typeof globalThis.requestAnimationFrame!=='function')){stopProgress();displayed=next;}
        else if(typeof globalThis.requestAnimationFrame!=='function'){
          displayed=paceStep(displayed,next,16,paceOpts());onDisplay?.(displayed);
        }else if(progressFrame===null)progressFrame=globalThis.requestAnimationFrame(animateProgress);
      }
      state.phase=typeof what==='string'&&what.length<=256?what:''; // debug/dataset only
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
      if((!startup&&!pacing)||state.closed||state.failed||state.frac!==1)return;
      // Paced launch: keep animating until the bar shows 100% (finishMs run), then two paint frames.
      if(pacing&&displayed<1-1e-9&&typeof globalThis.requestAnimationFrame==='function'){
        stopProgress();
        await new Promise(resolve=>{
          const tick=at=>{
            if(state.closed||state.failed){progressFrame=null;progressAt=null;return resolve();}
            const dt=progressAt===null?16:at-progressAt;
            progressAt=at;
            displayed=paceStep(displayed,1,dt,paceOpts());
            onDisplay?.(displayed);
            apply();
            if(displayed<1-1e-9)progressFrame=globalThis.requestAnimationFrame(tick);
            else{progressFrame=null;progressAt=null;resolve();}
          };
          progressFrame=globalThis.requestAnimationFrame(tick);
        });
      }else if(pacing){displayed=1;onDisplay?.(displayed);apply();}
      if(typeof globalThis.requestAnimationFrame==='function')await new Promise(resolve=>globalThis.requestAnimationFrame(()=>globalThis.requestAnimationFrame(resolve)));
    },
    fail(reason=null) {
      // ENGINE-CHOSEN fixed categories; never render arbitrary server details.
      if(state.closed)return;
      stopTipRotation();
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
      state.failureText.textContent=label;state.phase='';apply();
    },
    close() {
      stopTipRotation();
      stopProgress();
      state.closed = true;
      artGate.close();
      scr.classList.add('out');
      setTimeout(() => { try { mgr.dispose(); } catch { /* ignore */ } scr.remove(); }, 260);
    },
  };
}

