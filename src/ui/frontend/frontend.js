import { preloadSystemModules } from '../../systems/index.js';
// Front-end flow (docs/ARCHITECTURE.md §3.9), as in the original client:
//   startup readiness screen -> LOGIN (3D MAL_Login throne room with the seated figure; server list, then
//   ID / PW) -> CHARACTER SELECT (the selected character in its class-select map, original slot list) <-> CHARACTER
//   CREATE (own screen: the class-select maps 100..113 of char_selectinfo.txt, showcase outfits, Preview tab)
//   -> hand-off to Game.start (the original per-map loading screen, screens.js showLoading).
//
// Every window is the original window script built by the UI platform (src/ui/uiwin, docs/UIWIN.md) through a
// UIManager of the front-end's own (ui.js frontUI). runFrontEnd() owns one FrontStage (renderer + scene + caches).
// On "enter world" it frees the scene and resolves { character, renderer, textures, models, data }: main.js passes
// these to new Game(...), so the canvas keeps a single WebGL context and the loaded models / textures are reused.
//
// Shared services for the screens (this object): stage, uim (UIManager), texts, audio (BGM), accounts, data,
// fade / busy, showWindow / hideWindow, messageBox (ui_errorbox.txt), sfx, systemText(), classes(), gameData().
import { FrontStage } from './stage.js';
import { texts, parseCategorised } from './texts.js';
import { frontUI } from './ui.js';
import { LocalAccounts } from './accounts.js';
import { authorizeCharacterScreen } from './secondpw-gate.js';
import { Audio } from '../../game/audio.js';
import { GameData, ARDECA_MAP } from '../../game/data.js';
import { setLoadingMap, ensureFrontCSS, preloadLoading, showLoading } from '../screens.js';
import { prepareStartupCatalogs, prepareStartupScene, STARTUP_CATALOGS } from '../../engine/startup-preload.js';
import { runLaunchDataSync } from '../../engine/launch-data-sync.js';
import { launchProgress } from '../../engine/loading-pacer.js';
import { LAUNCH_PACING } from '../../config/engine-chosen-launch-pacing.js';
import { collectOrderedPreload, warmOrderedPreload, GLOBAL_STARTUP_PRE } from '../../engine/global-startup-preload.js';
import { prepareStartupUIScripts } from '../../engine/startup-ui.js';
import { STARTUP_UI_SCRIPTS } from '../../config/engine-chosen-startup-ui.js';
import { fetchText, soundURL } from '../../engine/assets.js';
import { prefetchGameTables, prefetchMapAssets, prefetchUIArt, stopMapPrefetch } from '../../engine/prefetch.js';
import { STARTUP_JSON } from '../../config/engine-chosen-loading.js';
import { atlas } from '../atlas.js';
import { CREDENTIAL_KEY, returnToFrontEnd } from './return.js';
import { flushCharacterSaves } from '../../game/save.js';
import { phonePresentationRequested, verifiedSession, accountDestination } from '../../../web/public/connect.js';
import { importWithNetRetry } from '../../engine/net-retry-import.js';

const wait = ms => new Promise(r => setTimeout(r, ms));

/** Phone presentation never supplies an account. Only the current server session can do so. */
export async function phoneSessionPreflight({location=globalThis.location,storage=globalThis.sessionStorage,request=globalThis.fetch,phone=phonePresentationRequested()}={}){
  if(!phone)return {phone:false};
  let force=new URLSearchParams(location.search||'').get('credentials')==='1';
  try{force ||= storage?.getItem(CREDENTIAL_KEY)==='1';}catch{/* private browsing */}
  const login=accountDestination(location.origin,'login',{phone:true});
  if(force){login.searchParams.set('credentials','1');try{storage?.removeItem(CREDENTIAL_KEY);}catch{/* query still enforces explicit login */}return {phone:true,redirect:login.href};}
  const account=await verifiedSession(location.origin,request);
  return account?{phone:true,account}:{phone:true,redirect:login.href};
}

function phoneSessionRetry(ui){
  return new Promise(resolve=>{
    const panel=document.createElement('div');panel.setAttribute('role','alert');panel.style.cssText='position:fixed;inset:0;z-index:1000;display:grid;align-content:center;gap:16px;padding:24px;background:#0c1013;color:#f1f0e9;font:16px/1.5 system-ui';
    const text=document.createElement('p');text.textContent='Could not check your account session. Check your connection and retry.';
    const retry=document.createElement('button');retry.type='button';retry.textContent='Retry';retry.style.cssText='min-height:48px;font:16px system-ui';
    const back=document.createElement('a');back.href=new URL('/join?client=phone',location.origin).href;back.textContent='Back to server';back.style.cssText='min-height:44px;color:#ebca9f;display:flex;align-items:center';
    retry.addEventListener('click',()=>{panel.remove();resolve();},{once:true});panel.append(text,retry,back);ui.append(panel);
  });
}

export function markPhoneCharacterLoading(front,character,document=globalThis.document){
  if(!front.phone||!front.account||character?.authority!=='server')return false;
  document.documentElement.dataset.dekaronStage='loading';return true;
}

export class FrontEnd {
  /**
   * @param {{canvas:HTMLCanvasElement, ui:HTMLElement, settings?:object}} opts
   */
  constructor({ canvas, ui, settings = null }) {
    this.canvas = canvas;
    this.ui = ui;
    this.stage = new FrontStage({ canvas, settings });
    this.settings = this.stage.settings;
    this.data = this.stage.data;
    this.texts = texts;
    this.accounts = new LocalAccounts();
    this.phone = phonePresentationRequested();
    this.account = null;
    this.requireCredentials = new URLSearchParams(globalThis.location?.search || '').get('credentials') === '1';
    try { this.requireCredentials ||= sessionStorage.getItem(CREDENTIAL_KEY) === '1'; sessionStorage.removeItem(CREDENTIAL_KEY); } catch { /* private mode */ }
    this.audio = null;
    this.uim = null;
    this._gameData = null;
    this.selectedId = null;     // character id to pre-select on the select screen
  }

  // ---------------------------------------------------------------------------------------- boot
  async boot() {
    ensureFrontCSS();
    this._startupLoadTimes={started:performance.now()};
    // Always show native startup loading cover (Global ESC Character/Exit: purple systemwait then this bar).
    // Do not invent skip-cover for return-to-character.
    this.preload = showLoading(this.ui, '', ARDECA_MAP, {startup:true,pacing:LAUNCH_PACING,trackReal:true,onDisplay:d=>{if(globalThis.__dkStartupLoad)globalThis.__dkStartupLoad.displayed=d;}});
    // Native parent-owned preload continues in this same window through real GPU readiness.
    globalThis.__dkStartupLoad={fraction:0,displayed:0,ready:false,failed:false,times:this._startupLoadTimes};
    const setStartup=this.preload.set.bind(this.preload),failStartup=this.preload.fail.bind(this.preload);
    this.preload.set=(fraction,label)=>{if(globalThis.__dkStartupLoad.failed)return;globalThis.__dkStartupLoad.fraction=fraction;return setStartup(fraction,label);};
    this.preload.fail=error=>{globalThis.__dkStartupLoad.failed=true;return failStartup(error);};
    // Work-weighted stages (config/engine-chosen-launch-pacing.js): datasync (server table sync hook), interface, preload (Global's startup .pre set),
    // scene (MAL_Login), shaders. The bar is paced by that table and never runs ahead of this real fraction.
    this._startupProgress=launchProgress(LAUNCH_PACING,(fraction,label)=>this.preload?.set(fraction,label));
    const preloadArt = atlas.sprite('preloading',1);
    // Count catalog preparation and script discovery in the existing first phase.
    // An absent optional panel completes discovery; its real boot consumer (if
    // any) still requires the window. No login/scene readiness is inferred here.
    // These are work units, not a byte percentage or an elapsed-time forecast.
    const startupWork={catalogs:0,scripts:0},startupTotal=STARTUP_CATALOGS.length+STARTUP_UI_SCRIPTS.length;
    const prepared=(kind,done)=>{startupWork[kind]=done;this._startupProgress('interface',(startupWork.catalogs+startupWork.scripts)/startupTotal,'Preparing client data and interface');};
    // Paint the native 0% before bulk JSON parsing can occupy the UI thread.
    const coverReady=Promise.resolve(this.preload.ready).then(()=>typeof globalThis.requestAnimationFrame==='function'
      ?new Promise(resolve=>globalThis.requestAnimationFrame(()=>globalThis.requestAnimationFrame(resolve))):undefined);
    // 'datasync' stage: the registered server table sync (engine/launch-data-sync.js) runs first; everything that reads
    // /gamedata (catalogs, FrontData) waits for it. Nothing registered = completes at once.
    const dataSynced=coverReady.then(()=>runLaunchDataSync({current:()=>!this.stage._disposed,
      onProgress:fraction=>this._startupProgress('datasync',fraction,'Synchronising game data')}))
      .then(report=>{this._startupDataSync=report;this._startupLoadTimes.dataSyncMs=report.ms;return report;});
    const catalogs = dataSynced.then(()=>prepareStartupCatalogs({onProgress:(done,total)=>
      prepared('catalogs',done)}));
    this.fadeEl = document.createElement('div');
    this.fadeEl.className = 'fe-fade';
    this.busyEl = document.createElement('div');
    this.busyEl.className = 'fe-busy';
    this.ui.append(this.fadeEl, this.busyEl);
    this.uim = frontUI(this.ui);
    this.uim.layer.classList.add('fe-uw');
    const scriptsStarted=performance.now();
    const scripts=coverReady.then(()=>prepareStartupUIScripts(this.uim,{current:()=>!this.stage._disposed,onProgress:done=>prepared('scripts',done)}))
      .then(report=>{this._startupUIReport=report;this._startupLoadTimes.uiScriptsMs=Math.round(performance.now()-scriptsStarted);return report;});
    // Start the front-end scene as soon as its dependencies are ready. Keep all
    // catalog/UI preparation in the final readiness barrier, overlapping scene
    // I/O instead of making the scene wait for every unrelated panel to parse.
    // Global's startup .pre set, in .pre order, through the stage caches the login scene and the Game share
    // (engine/global-startup-preload.js). Textures upload as tasks while the cover is up.
    const preloadStarted=performance.now();
    const startupSet=coverReady.then(()=>collectOrderedPreload(GLOBAL_STARTUP_PRE)).then(set=>{
      this._startupSet=set;this.stage.textures?.uploads?.setPreloading?.(true);
      return warmOrderedPreload(set.order,{models:this.stage.models,textures:this.stage.textures,current:()=>!this.stage._disposed,
        onProgress:(done,total)=>this._startupProgress('preload',total?done/total:1,'Loading game data')});
    }).then(ledger=>{this._startupLedger=ledger;if(ledger.failed.length)console.warn('[preload] startup asset failures',{count:ledger.failed.length,examples:ledger.failed.slice(0,10)});},error=>{this._startupLedger={error:String(error?.message||error)};console.warn('[preload] startup .pre set',error);})
      .finally(()=>{this._startupLoadTimes.preloadMs=Math.round(performance.now()-preloadStarted);this._startupProgress('preload',1,'Loading game data');});
    this._startupPreparation=Promise.all([catalogs,scripts,startupSet]).then(()=>{
      this._startupLoadTimes.catalogsAndInterfaceMs=Math.round(performance.now()-this._startupLoadTimes.started);
    }).catch(error=>{this._startupError=error;this.preload?.fail(error);});
    try { await Promise.all([dataSynced.then(()=>this.data.load()), texts.load(), this.uim.ready, preloadArt]); }
    catch(error){this.preload?.fail(error);throw error;}
    if(this._startupError)throw this._startupError;
    this._startupProgress('scene',0,'Preparing the login scene');
    // Additional reusable UI/map requests may warm while the player signs in.
    globalThis.addEventListener?.('dekaron:login-ready', () => this.warmTables(), { once: true });
    this.audio = new Audio({ data: this.data, settings: this.settings, events: null, player: null });
    this.audio.setVolumes({ music: this.settings.musicVolume, sfx: this.settings.sfxVolume });
    // The opaque startup cover hides the canvas until finishPreload: advance frames without drawing (stage.holdRender).
    // Skip-cover return-to-char leaves the canvas free so select can paint as soon as its scene is ready.
    if(this.preload)this.stage.holdRender?.(true);
    this.stage.start();
    return this;
  }

  startupSceneProgress(fraction,label) {
    const times=this._startupLoadTimes;if(times){times.sceneStarted??=performance.now();if(fraction>=1)times.sceneMs=Math.round(performance.now()-times.sceneStarted);}
    this._startupProgress?.('scene',fraction,label);
  }

  async finishPreload() {
    if (!this.preload) return;
    const panel=this.preload;
    await this._startupPreparation;
    if(this._startupError)throw this._startupError;
    const graphicsStarted=performance.now();
    this._startupProgress('shaders',0,'Preparing startup graphics');
    try { await prepareStartupScene(this.stage,{onProgress:(fraction,label)=>this._startupProgress('shaders',fraction,label)}); }
    catch(error){panel.fail(error);throw error;}
    this.stage.holdRender?.(false); // drawn once by prepareStartupScene; draw every frame again before the cover lifts
    if(this._startupLoadTimes){this._startupLoadTimes.graphicsMs=Math.round(performance.now()-graphicsStarted);this._startupLoadTimes.totalMs=Math.round(performance.now()-this._startupLoadTimes.started);}
    panel.set(1,'');
    // Give the completed label a paint before releasing the cover, including a
    // cached startup that finishes within a frame. No artificial seconds added.
    await panel.presentComplete?.();
    panel.close();
    this.stage.textures?.uploads?.setPreloading?.(false);
    const ledger=this._startupLedger,set=this._startupSet;
    Object.assign(globalThis.__dkStartupLoad,{startupSet:set?{roots:[...GLOBAL_STARTUP_PRE],files:set.files.length,assets:set.order.length,missingIncludes:set.missing.length,unparsedEntries:set.unparsed.length,keys:set.order.map(o=>o.kind+':'+o.path)}:null,
      ledger:ledger?{done:ledger.done,missing:ledger.missing,failed:ledger.failed,ms:ledger.ms,error:ledger.error}:null,
      programsAtReady:this.stage.renderer?.info?.programs?.length??null,readyAt:performance.now()});
    globalThis.__dkStartupLoad.ready=true;
    if(this.preload===panel)this.preload=null;
  }

  /** classes.json (loaded once). */
  async classes() {
    await this.data.loadClasses();
    return this.data.classes;
  }

  /** The full GameData, loaded in the background once the player has logged in; reused by the Game. */
  gameData() {
    preloadSystemModules();
    if (!this._gameData) {
      this._gameData = new GameData().load().catch(err => { console.warn('[frontend] game data preload failed', err); return null; });
    }
    return this._gameData;
  }

  /**
   * 2.2.1 instant loading (engine/prefetch.js): the game tables parse while the player is still in the front-end. Called when
   * the login succeeds, so the biggest parses (items.json) land in the fade-out / busy select-scene load.
   */
  warmTables() {
    void this.gameData();
    // dungeons/events: the solo systems AND the shared-world bridges (network/dungeons.js loadData, events/data.js) parse them
    void prefetchGameTables([...STARTUP_JSON, 'dungeons', 'events']);
    void prefetchUIArt(atlas);   // the HUD / priority-panel sprites recorded by the last load (the same for every map)
  }
  /** The selected character's class skills and the recorded asset list of the map it will enter. */
  warmForCharacter(save) {
    if (!save) return;
    void prefetchGameTables([`skills/class_${Number(save.classIndex) || 0}`]);
    const target = save.map != null ? Number(save.map) : ARDECA_MAP;
    void prefetchMapAssets(target, { textures: this.stage.textures, atlas, row: this.data.mapByIndex(target) });
  }

  /** stringtable_system.txt (connection-process messages, <cate> 100 of that file). */
  systemText() {
    if (!this._sys) this._sys = fetchText('script/string/system/stringtable_system.txt', true).then(parseCategorised).catch(() => new Map());
    return this._sys;
  }

  // ---------------------------------------------------------------------------------------- services
  /**
   * Fade the black overlay to `to` (1 = black) over ms (scenefadein/out.txt: 500 ms). By default it covers only
   * the 3D scene (the windows stay visible: the login window shows at once while its scene loads); over = true
   * covers the windows too.
   */
  async fade(to, ms = 500, { over = false } = {}) {
    const f = this.fadeEl;
    if (!f) return;
    f.style.zIndex = over ? '45' : '15';
    f.style.transitionDuration = `${ms}ms`;
    void f.offsetWidth;
    f.style.opacity = String(to);
    await wait(ms + 30);
  }

  /** The client's loading cursor while a scene loads (mouse.csv "trigger" = gear_loading). */
  busy(on) {
    document.body.classList.toggle('fe-wait', !!on);
  }

  /** Open a screen window with the 500 ms fade-in of scenefadein.txt. */
  showWindow(win) {
    if (!win) return;
    win.el.classList.add('fe-screen-win');
    this.uim.openWindow(win);
    requestAnimationFrame(() => requestAnimationFrame(() => win.el.classList.add('fe-in')));
    setTimeout(() => win.el.classList.add('fe-in'), 60);
  }

  /** Fade a screen window out (scenefadeout.txt) and close it. */
  async hideWindow(win) {
    if (!win) return;
    win.el.classList.remove('fe-in');
    await wait(450);
    this.uim.closeWindow(win);
  }

  /** ui_errorbox.txt: a message (client markup) with the Ok button. Title 100:1 "Error" (or `titleCode`). */
  async messageBox(text, onClose = null, { titleCode = 1 } = {}) {
    const win = await this.uim.create('game2/msgbox/ui_errorbox.txt', { name: 'fe_msgbox', modal: true, remember: false, disposeOnClose: true, autoClose: false });
    win.control('lbl_title').setText(this.texts.get(100, titleCode, 'Error'));
    win.control('lbl_text').setRichText(text);
    const done = () => { this.uim.closeWindow(win, 'ok'); };
    win.once('close', () => { globalThis.removeEventListener('keydown', key, true); onClose?.(); });
    const key = e => { if (e.key === 'Enter' || e.key === 'Escape') { e.preventDefault(); e.stopPropagation(); done(); } };
    globalThis.addEventListener('keydown', key, true);
    win.control('btn_yes').onClick(done);
    this.uim.openWindow(win);
    return win;
  }

  /** A sound file under sound/ (e.g. etc_login_button.wav) at the effects volume. */
  sfx(path) {
    const v = Number(this.settings.sfxVolume ?? 0.7);
    if (!v) return;
    try { const a = new globalThis.Audio(soundURL(path)); a.volume = Math.max(0, Math.min(1, v)); a.play().catch(() => {}); } catch { /* no audio */ }
  }

  /** 'login' -> sound.json bgmSpecial.login (9999); 'charSelect' -> the playlist of the class-select map. */
  playBGM(kind, mapIndex = null) {
    const special = this.data.sound?.bgmSpecial?.[kind];
    let idx = Array.isArray(special) ? special[0] : special;
    if (kind === 'charSelect' && mapIndex != null && Array.isArray(special) && special.map(String).includes(String(mapIndex))) idx = mapIndex;
    if (idx != null) this.audio?.playBGM(String(idx));
  }

  // ---------------------------------------------------------------------------------------- flow
  async restoreAccount(){
    if(!this.phone)return this.accounts.restore({ configure: false });
    return verifiedSession(location.origin);
  }
  phoneLogin(force=false){
    const target=accountDestination(location.origin,'login',{phone:true});if(force)target.searchParams.set('credentials','1');
    location.replace(target.href);return new Promise(()=>{});
  }
  /** Save and sign out on this origin before returning to the shared server picker. */
  async serverMenu() {
    await returnToFrontEnd('login', { accounts: this.accounts, flush: flushCharacterSaves, stage: this.stage });
    this.account = null; this.requireCredentials = true;
    return new Promise(() => {}); // The next document owns the flow; do not hand an empty character to main.js.
  }

  /**
   * Run login -> select <-> create until the player enters the world.
   * @param {{startAt?:'login'|'select'|'create'}} [opts]
   * @returns {Promise<{character:object, renderer, textures, models, data}>}
   */
  async run({ startAt = 'login' } = {}) {
    // A dropped module request rejects import() with a TypeError; fetch it again (engine/net-retry-import.js).
    const { LoginScreen } = await importWithNetRetry(() => import('./login.js'));
    const { SelectScreen } = await importWithNetRetry(() => import('./select.js'));
    const { CreateScreen } = await importWithNetRetry(() => import('./create.js'));
    let next = startAt;
    // Restore the account before select/create reads character slots, including a return from the game.
    try { this.account = await this.restoreAccount(); }
    catch (err) { if(this.phone){await phoneSessionRetry(this.ui);return this.run({startAt});}await this.messageBox(err.message); next = 'login'; }
    if (!this.account) next = 'login';
    if(this.phone){if(this.requireCredentials||!this.account)return this.phoneLogin(this.requireCredentials);if(next==='login')next='select';}
    let character = null;
    while (!character) {
      // Every entry path (credentials, remembered launcher session, phone, direct
      // select/create URL and return from the world) passes the same host check.
      if (next === 'select' || next === 'create') {
        if (!await authorizeCharacterScreen(this)) {
          this.requireCredentials = true;
          try { await this.accounts.logout(); } catch (error) { await this.messageBox(error.message); }
          this.account = null; next = 'login';
          if (this.phone) return this.phoneLogin(true);
          continue;
        }
        try { await this.accounts.configure(this.account); }
        catch (error) { await this.messageBox(error.message); this.requireCredentials = true; next = 'login'; continue; }
      }
      if (next === 'login') {
        const r = await new LoginScreen(this).run();
        this.account = r.account;
        if (!this.account) { next = 'login'; continue; }
        next = 'select';
      } else if (next === 'select') {
        this.warmTables();
        const r = await new SelectScreen(this).run({ selectId: this.selectedId });
        if (r.action === 'enter') {
          let authenticated;
          try{authenticated=await this.restoreAccount();}catch(err){if(this.phone){await phoneSessionRetry(this.ui);next='select';continue;}throw err;}
          if (!authenticated || authenticated !== this.account) {
            this.account = authenticated; next = 'login';
            if(this.phone)return this.phoneLogin(true);
            await this.messageBox('Your account session changed or expired. Log in again.');
          } else if (r.character?.authority !== 'server') {
            next = 'select';
            await this.messageBox('This is a saved local character. Create an online character to enter the shared world. Your saved character is preserved.');
          } else if (!await authorizeCharacterScreen(this)) {
            this.requireCredentials = true;
            try { await this.accounts.logout(); } catch (error) { await this.messageBox(error.message); }
            this.account = null; next = 'login';
            if (this.phone) return this.phoneLogin(true);
          } else {character = r.character;this.selectedChannel=r.channel;}
        }
        else if (r.action === 'create') next = 'create';
        else {
          try { await this.serverMenu(); }
          catch (err) { await this.messageBox(err.message); next = 'select'; }
        }
      } else if (next === 'create') {
        const r = await new CreateScreen(this).run();
        if (r.action === 'created') this.selectedId = r.character?.id || null;
        if (r.action === 'logout') {
          try { await this.serverMenu(); }
          catch (error) { await this.messageBox(error.message); next = 'select'; }
        } else next = 'select';
      } else next = 'login';
    }
    return this.handoff(character);
  }

  /** Fade out, stop the front-end music, free the scene; the renderer and caches go to the Game. */
  async handoff(character) {
    // Native shell orientation follows accepted character handoff, after session/authority validation.
    markPhoneCharacterLoading(this,character);
    stopMapPrefetch();   // the game's own loads take over at normal priority
    // the loading screen shows the art of the map the character enters (new characters: Ardeca, map 150);
    // its sprites decode while the scene fades out
    const target = character.map != null ? Number(character.map) : ARDECA_MAP;
    const art = preloadLoading(target).catch(() => null);
    await this.fade(1, 500, { over: true });
    this.audio?.stopBGM(900);
    await Promise.race([art, wait(4000)]);
    const dataP = this.gameData();
    setLoadingMap(target);
    const { renderer, textures, models } = this.stage.handoff();
    try { renderer.setClearColor(0x000000, 1); renderer.clear(); } catch { /* ignore */ }
    const audio = this.audio;
    this.audio = null;
    setTimeout(() => { try { audio?.dispose(); } catch { /* ignore */ } }, 1000);
    try { this.uim.dispose(); } catch { /* ignore */ }
    this.uim = null;
    this.busy(false);
    this.busyEl?.remove();
    // the Game's loading screen covers the canvas from its first synchronous step; drop the fade after that
    const fadeEl = this.fadeEl;
    setTimeout(() => fadeEl?.remove(), 400);
    // the game tables finish loading behind the Game's loading screen (data: a promise of GameData | null)
    return { character, initialChannel:this.selectedChannel, renderer, textures, models, data: dataP.then(d => (d && d.classes ? d : null)) };
  }
}

/** Convenience entry for main.js. */
export async function runFrontEnd({ canvas, ui, startAt = 'login', settings = null } = {}) {
  let plan;
  for(;;){try{plan=await phoneSessionPreflight();break;}catch{await phoneSessionRetry(ui);}}
  if(plan.redirect){location.replace(plan.redirect);return new Promise(()=>{});}
  if(plan.phone){const target=new URL(location.href);target.searchParams.set('client','phone');try{history.replaceState(null,'',target.href);}catch{/* presentation still uses the touch browser */}}
  const fe = new FrontEnd({ canvas, ui, settings });
  await fe.boot();
  globalThis.dekaronFrontEnd = fe;     // debugging from the console
  return fe.run({ startAt });
}

