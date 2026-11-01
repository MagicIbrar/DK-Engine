import { prefetchGameJSON } from '../engine/loading-prefetch.js';
import {awaitLoadingStage} from '../engine/loading-deadline.js';
import { finishInterfaceWarmup } from '../engine/loading-interface.js';
import { startAssetRecording, finishAssetRecording, assetRecordingActive } from '../engine/prefetch.js';
import { LOADING, phaseFraction } from '../config/engine-chosen-loading.js';
import { nativeEyeHeight, nativeAvatarEyeOffset, prewarmFirstPersonBody } from '../engine/native-first-person-presentation.js';
import { keepShaderPrograms, flushWarmDraws, touchPrograms, warmWholeScene } from '../engine/warm-draw.js';
import { prewarmTransformLooks } from '../systems/skills/transform-prewarm.js';
import { prewarmEffectPrimitives } from '../systems/skills/effect-prewarm.js';
import { applyDungeonArrivalView } from '../systems/network/dungeon-arrival.js';
import { tickShaderPrewarm, settleShaderPrewarm, markProgramsTouched } from '../engine/shader-prewarm.js';
import { prewarmDilPiles } from '../systems/items/drop-prewarm.js';
import { prewarmGlobalPreload } from '../engine/global-preload-warm.js';
import { compileSceneInParts } from '../engine/scene-compile.js';
// Game orchestrator: owns the renderer, the frame loop, map transfer and saving.
// Module contracts: docs/ARCHITECTURE.md.
import * as THREE from 'three';
import { Input } from '../engine/input.js';
import { Bloom } from '../engine/bloom.js';
import { FollowCamera } from '../engine/camera.js';
import { Emitter } from '../engine/events.js';
import { fileToThree, WORLD_MIRROR } from '../engine/space.js';
import { TextureCache } from '../engine/textures.js';
import { ModelCache } from '../engine/models.js';
import { GameData, ARDECA_MAP } from './data.js';
import { World, legacyMapRow } from '../world/world.js';
import { Player } from '../actors/player.js';
import { NPC } from '../actors/npc.js';
import { PlayerController } from './controller.js';
import { Spawner } from './spawner.js';
import { SkillSystem } from './skills.js';
import { LootSystem } from './loot.js';
import { deriveStats, tickRegen } from './progression.js';
import { HUD } from '../ui/hud.js';
import { Windows } from '../ui/windows.js';
import { Audio } from './audio.js';
import { showLoading } from '../ui/screens.js';
import { saveCharacter, loadSettings, saveSettings } from './save.js';
import { UIManager } from '../ui/uiwin/index.js';
import { installGlobalWindows } from '../ui/uiwin/global-windows.js';
import { installSystems, updateSystems, preloadSystemModules } from '../systems/index.js';

const AUTOSAVE_SECONDS = 20;

/** A FILE-frame position with finite x and z. */
const validPos = p => !!p && p.x != null && p.z != null && Number.isFinite(Number(p.x)) && Number.isFinite(Number(p.z));

export class Game {
  constructor({ canvas, ui, character, initialChannel = undefined, renderer = null, textures = null, models = null, data = null }) {
    this.canvas = canvas;
    this.ui = ui;
    this.save = character;
    this.initialChannel=initialChannel;
    // from the 3D front-end (src/ui/frontend): the canvas keeps its single WebGL context and loaded assets are reused;
    // data may be a GameData or a promise of one (null = load it here)
    this._shared = { renderer, textures, models, data };
    this.settings = loadSettings();
    this.events = new Emitter();
    this.time = 0;
    this.paused = false;
    this.npcs = [];
    this.world = null;
    this.player = null;
    this._saveTimer = 0;
    this._loadingMap = false;
  }

  // ------------------------------------------------------------------ boot
  async start() {
    startAssetRecording();   // 2.2.1: the first map's request list, replayed at character select next time (engine/prefetch.js)
    preloadSystemModules();
    this._initRenderer();
    const loading = showLoading(this.ui, 'Dekaron');
    try {
      loading.set(LOADING.tables[0], 'Reading game tables…');
      this.data = (await Promise.resolve(this._shared.data).catch(() => null))
        || await new GameData().load((f, what) => loading.set(phaseFraction(LOADING.tables, f), `Reading ${what}…`));
      this.classDef = this.data.classByIndex.get(Number(this.save.classIndex)) || this.data.classes[0];
      this._initSave();

      this.textures = this._shared.textures || new TextureCache(this.renderer);
      this.models = this._shared.models || new ModelCache(this.textures);
      this.hud = new HUD(this, this.ui);
      this.windows = new Windows(this, this.ui);
      this.uiwin = new UIManager(this, this.ui); installGlobalWindows(this.uiwin);   // original windows platform (docs/UIWIN.md); game.ui.registerWindow(...)
      this.audio = new Audio(this);
      this.audio.setVolumes({ music: this.settings.musicVolume, sfx: this.settings.sfxVolume });
      this.skills = new SkillSystem(this);
      this.loot = new LootSystem(this);
      this.spawner = new Spawner(this);
      this.controller = new PlayerController(this);
      this._startupJSON = prefetchGameJSON(this.save);
      loading.set(LOADING.systems[0], 'Starting systems…');
      const systems = await installSystems(this, (done, total, name) => loading.set(phaseFraction(LOADING.systems, total ? done / total : 1), `Starting systems... ${done}/${total}${name ? ` (${name})` : ''}`));   // src/systems/index.js (one line per system)
      // Optional windows may fail independently, but an incomplete item/skill
      // engine (or missing online authority adapter) must not enter a live world.
      const required = ['items', 'skills', ...(this.save.authority === 'server' ? ['network'] : [])];
      const missing = required.filter(name => !systems.installed.includes(name));
      if (missing.length) {
        const error = new Error('Required game data is not ready. Please retry loading.');
        error.code = 'GAME-SYSTEMS-NOT-READY'; error.systems = missing;
        throw error;
      }
      this._uiArtReady = Promise.all([this.uiwin.prewarm({ priorityOnly: true }), this.hud._nameplateArtReady]);

      // saved position > saved map (its start point, e.g. tools/play.html ?map=N) > the new-character start (Ardeca)
      const start = this.save.map != null && this.save.pos
        ? { mapIndex: this.save.map, x: this.save.pos.x, z: this.save.pos.z, dirDeg: this.save.pos.dirDeg ?? 0 }
        : this.save.map != null && this.mapRow(this.save.map)
          ? { mapIndex: Number(this.save.map), x: null, z: null, dirDeg: 0 }
          : this.data.startFor(this.save.classIndex);
      await this.enterMap(start.mapIndex, start, loading);
    } catch (err) {
      if(this.save.authority==='server'){if(!this._worldReady)loading.fail?.(err);}
      else loading.close();
      throw err;
    }
    this._wireEvents();
    window.addEventListener('beforeunload', () => this.persist());
    this._last = performance.now();
    this.renderer.setAnimationLoop(t => this._frame(t));
  }

  _initRenderer() {
    const r = this._shared.renderer || new THREE.WebGLRenderer({ canvas: this.canvas, antialias: true, powerPreference: 'high-performance' });
    r.setPixelRatio(Math.min(window.devicePixelRatio, 2));
    r.setSize(window.innerWidth, window.innerHeight, false);
    // DX9-era look: the original lit and blended in gamma space with no colour management.
    // Textures use NoColorSpace and output is written as-is (see docs/ARCHITECTURE.md §1).
    THREE.ColorManagement.enabled = false;
    r.outputColorSpace = THREE.LinearSRGBColorSpace;
    r.toneMapping = THREE.NoToneMapping;
    r.shadowMap.enabled = !!this.settings.shadows;
    r.shadowMap.type = THREE.PCFSoftShadowMap;
    keepShaderPrograms(r);   // no destroy / recompile cycles of the same shader (engine/warm-draw.js)
    this.renderer = r;
    window.addEventListener('pagehide', () => this.bloom?.dispose(), { once: true });

    this.scene = new THREE.Scene();
    this.scene.background = new THREE.Color(0x6f8fb0);
    this.camera = new THREE.PerspectiveCamera(50, window.innerWidth / window.innerHeight, 0.1, 1200);
    this.worldRoot = new THREE.Group();
    this.worldRoot.name = 'worldRoot (FILE frame, Z mirrored)';
    this.worldRoot.scale.copy(WORLD_MIRROR);
    this.scene.add(this.worldRoot);

    this.input = new Input(this.canvas);
    this.cam = new FollowCamera(this.camera, this.input, {
      heightAt: (x, z) => (this.world ? this.world.heightAt(x, -z) : 0),
      eyeHeight: () => nativeEyeHeight(this.player),
      eyeOffset: () => nativeAvatarEyeOffset(this.player, this.cam?.yaw),
      // Camera push-in on buildings (world/objects.js cameraClip) is OFF. The whole frame bobbed while
      // running through town: the pull-in fired on and off between buildings. The original camera does not do this.
      // Small occluders (trees/props) still fade out of the way (objects.js _occlusion).
      collide: null,
    });
    this.raycaster = new THREE.Raycaster();

    window.addEventListener('resize', () => {
      this.renderer.setSize(window.innerWidth, window.innerHeight, false);
      this.camera.aspect = window.innerWidth / window.innerHeight;
      this.camera.updateProjectionMatrix();
    });
  }

  _initSave() {
    const s = this.save;
    const c = this.classDef;
    if (!s.stats) s.stats = { ...(c.stats?.base || { str: 5, dex: 5, con: 5, spr: 5 }) };
    s.level = s.level || 1;
    s.exp = s.exp || 0;
    s.dil = s.dil || 0;
    s.statPoints = s.statPoints || 0;
    s.inventory = s.inventory || [];
    s.hotbar = Array.isArray(s.hotbar) ? s.hotbar : [];   // user: new characters start with an EMPTY bar (no auto setup)
    s.skills = s.skills || {};
  }

  _wireEvents() {
    this.events.on('death', ({ actor }) => {
      if (actor === this.player) {
        this.save.deaths = (this.save.deaths || 0) + 1;
        this.hud.showDeath(() => this.revive());
      } else if (actor?.kind === 'monster') {
        this.save.kills = (this.save.kills || 0) + 1;
      }
    });
    this.events.on('levelup', () => { this.refreshPlayerStats(true); this.persist(); });
  }

  // ------------------------------------------------------------------ maps
  /** maplist row of a map, or the synthesised row of a legacy field map (world.js LEGACY_MAPS), or null. */
  mapRow(mapIndex) {
    return this.data.mapByIndex(mapIndex) || legacyMapRow(mapIndex, this.data.mapByIndex(0));
  }

  /**
   * Load a map and place the player. pos = FILE-frame {x, z, dirDeg}, or null / non-walkable for the map's start
   * point (opts.respawn: its respawn point).
   */
  async enterMap(mapIndex, pos = null, loading = null, opts = {}) {
    if (this.save.authority === 'server' && this.network?.ready && this.world && !opts.serverTransfer && Number(mapIndex) !== Number(this.network.self?.map)) return this.network.travel(mapIndex);
    if (this._loadingMap) return;
    const shared=this.save.authority==='server',network=this.network;
    const requestedMap=Number(mapIndex),entry=this._mapLoadGeneration=(this._mapLoadGeneration||0)+1;
    const mapTimes=this._mapLoadTimes={map:requestedMap};
    const started=performance.now();let previous=started;
    const lap=name=>{const now=performance.now();mapTimes[name]=Math.round(now-previous);previous=now;};
    let complete=false,entryWorld=null;
    this._loadingMap = true;
    this.textures?.uploads?.setPreloading(true);
    this._worldReady = false;
    this._launcherReadiness?.invalidate();
    if (!assetRecordingActive()) startAssetRecording();   // a map change: its own request list
    const row = this.mapRow(mapIndex) || this.data.mapByIndex(0);
    mapIndex = Number(row.Index);
    const ownLoading = !loading;
    loading = loading || showLoading(this.ui, row.Name || 'Dekaron');
    loading.title(row.Name || 'Dekaron', mapIndex);
    this.paused = true;
    try {
      if(shared&&(network!==this.network||network?._installationComplete!==true))
        throw new Error('Shared network installation did not complete. Retry loading.');
      this._resetTravelState();
      this.windows?.closeAll();
      this.spawner?.clear();
      this.loot?.clear?.();
      for (const n of this.npcs) n.dispose();
      this.npcs = [];
      if (this.world) { this.world.dispose(); this.world = null; }

      const world = new World({ game: this });
      // objects load nearest-first around where the player will appear (e.g. a new character's Ardeca 203,247)
      entryWorld=world;
      const loaded=await world.load(mapIndex, (f, what) => loading.set(phaseFraction(LOADING.world, f), what), validPos(pos) ? { focus: { x: Number(pos.x), z: Number(pos.z) } } : {});
      lap('world');
      if(shared&&(this.world!==null||!loaded?.loaded||loaded.world!==world||loaded.mapIndex!==requestedMap||world._disposed||Number(world.info?.index)!==requestedMap||entry!==this._mapLoadGeneration))
        throw new Error('Shared map loading did not complete. Retry loading.');
      this.world = world;
      this.cam.configure(row);

      if (!this.player) {
        loading.set(LOADING.player, 'Summoning your character…');
        // 2u: the starting equipment look (items-actions.json: animated weapons) is settled during loading, so no
        // body rebuild runs after spawn; the build below then records its look (items look.prime)
        try {
          const acts = this.items?.db?.actions?.();
          if (acts) await Promise.race([acts, new Promise(r => setTimeout(r, 5000))]);
        } catch { /* items optional */ }
        this.player = new Player(this, this.save, this.classDef);
        await this.player.load();
        try { this.items?.look?.prime?.(); } catch { /* items optional */ }
        this.refreshPlayerStats(false);
        if (this.save.hp == null || this.save.hp <= 0) this.player.hp = this.player.maxHp;
        else this.player.hp = Math.min(this.save.hp, this.player.maxHp);
        this.player.mp = this.save.mp == null ? this.player.maxMp : Math.min(this.save.mp, this.player.maxMp);
      }
      const p = validPos(pos) && world.isWalkable(pos.x, pos.z) ? pos : world.startPoint(!!opts.respawn);
      // A new map has a new ground frame, even when its arrival X/Z is nearby.
      this.player._grounded = false;
      this.player._knockback = null;
      this.player._serverPose = null;
      this.player.setPosition(p.x, p.z);
      this.player.yaw = ((p.dirDeg || 0) * Math.PI) / 180;
      this.player.target = null;
      this.cam.snap();
      lap('player');

      loading.set(LOADING.npcs, 'Placing townsfolk…');
      // 2.2.1: the shared-world join (a server round trip + the first snapshot) runs while the townsfolk are placed; it only
      // needs the player and the world index, both set above (~250 ms off the loading screen, measured)
      const joined = this.network?.joinMap?.();
      await this._spawnNpcs(world);
      lap('npcs');
      loading.set(LOADING.monsters, 'Waking the monsters…');
      if (this.save.authority !== 'server') {
        this.spawner.start(world.spawns);
        try { await this.spawner.prewarm?.(6000); } catch { /* the spawner fills in during play */ }
      }
      // lane-perf: everything Global's own preload list for this map names (maplist Preloading + common.pre), through the
      // same model/texture caches the actors use; progress counts finished items (src/engine/global-preload-warm.js)
      try { mapTimes.globalPreload = await prewarmGlobalPreload(this, row?.Preloading || '', { onProgress: (done, total) => loading.set(LOADING.monsters, `Loading map assets… ${done}/${total}`) }); }
      catch (error) { console.warn('[preload] Global preload list failed', error?.message || error); }
      lap('globalPreload');
      const admission=await joined;
      lap('admission');
      if(shared&&!admission?.ok){
        // The network layer intentionally keeps only allowlisted failure facts;
        // never put an arbitrary server response on the loading screen.
        const failure=admission?.failure;
        const error=new Error(admission?.error||'Shared world admission is not ready. Retry loading.');
        if(Number.isInteger(failure?.status))error.status=failure.status;
        if(typeof failure?.category==='string')error.networkCategory=failure.category;
        if(failure?.name==='AbortError')error.name='AbortError';
        throw error;
      }
      const currentEntry=()=>{
        if(entry!==this._mapLoadGeneration||this.world!==world||world._disposed||Number(world.info?.index)!==mapIndex)return false;
        if(!shared)return true;
        const current=network?.admission?.();
        return this.save.authority==='server'&&network===this.network&&network._installationComplete===true&&current?.ok&&admission?.ok&&
          current.generation===admission.generation&&current.token===admission.token&&current.actorId===admission.actorId&&
          current.characterId===admission.characterId&&current.map===requestedMap&&admission.map===requestedMap;
      };
      if(shared&&!currentEntry())throw new Error('Shared admission or map changed before entry. Retry loading.');
      const initialActors=shared?network.captureInitialActors(admission):null;

      this.hud.setMinimap(world);
      this.audio.playBGM(mapIndex);
      this.save.map = mapIndex;
      this.events.emit('map', { index: mapIndex });
      this.hud.toast(row.Name || '');
      this.persist();
      loading.set(LOADING.artwork[0], 'Preparing interface artwork…');
      const interfaceReady=await finishInterfaceWarmup(this,{onArtworkProgress:(done,total)=>
        loading.set(phaseFraction([LOADING.artwork[0],0.86],total?done/total:0),`Preparing interface artwork... ${done}/${total}`),
        onPanelProgress:(done,total)=>loading.set(phaseFraction([0.86,LOADING.artwork[1]],total?done/total:0),`Preparing interface panels... ${done}/${total}`),
        onIconProgress:(done,total)=>loading.set(phaseFraction(LOADING.artwork,total?done/total:0),`Preparing NPC shop images... ${done}/${total}`),
        onWaiting:({pending})=>loading.set(LOADING.artwork[1],pending.includes('artwork')?'Preparing interface artwork…':'Preparing inventory and skill images…')});
      for(const [name,ready]of Object.entries(interfaceReady))mapTimes[name+'Deferred']=!ready;
      mapTimes.interfaceTasks=this._interfaceWarmupTimings;
      lap('interface');
      loading.set(LOADING.icons, 'Preparing inventory and skill icons…');
      if(shared){loading.set(LOADING.scene,'Preparing nearby players and creatures…');await network.awaitInitialActors(initialActors,{onProgress:state=>
        loading.set(LOADING.scene,state.phase==='warming'?`Preparing players on this map…${state.target?` ${state.active}/${state.target}`:''}`:'Preparing nearby players and creatures…')});}
      lap('actors');
      await this._warmUp(loading,{current:currentEntry});
      lap('warm');
      if(shared&&!currentEntry())throw new Error('Shared admission or map changed during loading. Retry loading.');
      // Public-map arrivals can also start behind a wall (for example the
      // Dead Front officers in Chain of Fire). Check the authored angle once
      // after nearby geometry is ready, without continuous camera push-in.
      this._arrivalView = applyDungeonArrivalView(this);
      // A saved corpse is placed by joinMap before the first world snapshot. In
      // that case the snapshot sees an already-dead actor and has no death edge
      // on which to open the native revive window.
      if (shared && network?.self?.dead && this.player?.dead && !this.uiwin?.window?.('death')?.isOpen)
        this.hud?.showDeath?.(() => this.revive());
      complete=true;
      mapTimes.total=Math.round(performance.now()-started);
      if(mapTimes.total>15000)console.warn('[game] slow map entry '+JSON.stringify(mapTimes));
      this._worldReady = true;
      finishAssetRecording(mapIndex);
      loading.set(LOADING.complete, '');
    } catch(err) {
      mapTimes.total=Math.round(performance.now()-started);
      mapTimes.error=String(err?.message||err);
      if(shared&&!complete)loading.fail?.(err);
      throw err;
    } finally {
      if(entry===this._mapLoadGeneration)this.textures?.uploads?.setPreloading(false);
      if (assetRecordingActive()) finishAssetRecording(null);   // the load failed: keep the previous list
      if(entry===this._mapLoadGeneration){
        if(!shared||complete){if(ownLoading||loading)loading.close();}
        else {loading.fail?.();if(entryWorld&&this.world!==entryWorld)entryWorld.dispose();}
      }
      void prefetchGameJSON({ deferred: true });
      void this.uiwin?.prewarm().catch(error => console.warn('[ui] background artwork failed', error));
      if(entry===this._mapLoadGeneration){this.paused=shared&&!complete;this._loadingMap=shared&&!complete;}
    }
  }

  /**
   * Performance: compile the new map's shader programs (in parallel where the driver supports it) and upload its
   * textures with one render while the loading screen still covers the canvas, instead of a 100-300 ms hitch on the
   * first visible frame.
   */
  async _warmUp(loading,{current=()=>true}={}) {
    const times = this._warmUpTimes = {};   // per-step ms (the load-time measurement reads them)
    const t = performance.now();
    let last = t;
    const lap = name => { const now = performance.now(); times[name] = Math.round(now - last); last = now; };
    try {
      loading?.set?.(LOADING.scene, 'Preparing the scene…');
      if (this.player) fileToThree(this.player.x, this.player.y, this.player.z, this.cam.target);
      this.cam.snap();
      this.cam.update(0);
      this.world?.update(0, this.camera.position);
      const dilWarm = prewarmDilPiles(this);   // 2.2.1 fix-4: started now, runs beside the scene compile below (GPU work in parallel), awaited before the pre-build queue settles (systems/items/drop-prewarm.js)
      if (typeof this.renderer.compileAsync === 'function') await awaitLoadingStage(()=>compileSceneInParts(this.renderer,this.scene,this.camera,(done,total)=>loading?.set?.(LOADING.scene,`Preparing scene graphics (${done}/${total})…`)),{
        current:()=>current()&&!this.renderer.getContext?.()?.isContextLost?.(),stage:'Scene graphics'});
      lap('compile');
      // the first-person arm / body shader variants too, so the first switch to first person does not stall
      keepShaderPrograms(this.renderer);   // again after a lost / restored context (a new program list)
      loading?.set?.(LOADING.scene,'Preparing first-person graphics…');
      await prewarmFirstPersonBody(this,{draw:true,current:()=>current()&&!this.renderer.getContext?.()?.isContextLost?.()}).catch(err=>{
        if(err?.loadingStageFailure&&err.loadingStageReason==='changed')throw err;
        times.firstPersonDeferred=true;console.warn('[game] first-person shader pre-build deferred',err);
      });
      if(!current())throw Object.assign(new Error('Map loading changed. Retry loading.'),{loadingStageFailure:true});
      lap('firstPerson');
      // the equipped mount (with its first-person riding look) and the learned Trans Up bodies: loaded, compiled and drawn once
      // here, under the loading screen. Capped: a slow load finishes in the background.
      await Promise.race([
        Promise.all([this.mounts?.system?.riding?.prewarmNow?.(), prewarmTransformLooks(this, { draw: true })])
          .catch(err => console.warn('[game] mount / Trans Up pre-load failed', err)),
        new Promise(resolve => setTimeout(resolve, 6000)),
      ]);
      lap('mountTransUp');
      times.effectPrimitives = await awaitLoadingStage(() => prewarmEffectPrimitives(this, {
        current,
        onProgress: (done, total) => loading?.set?.(LOADING.scene, `Preparing effect graphics (${done}/${total})…`),
      }), {current, stage: 'Effect graphics'});
      lap('effectGraphics');
      times.dilPiles = (await dilWarm).ms;   // the five Dil pile models (the first kill's drop) built under the loading screen, not at the first death (kill switch globalThis.__dekaronNoDropPrewarm)
      await settleShaderPrewarm(this, 2500);   // the corpse-fade variants of the bodies loaded so far, still under the loading screen (engine/shader-prewarm.js; kill switch globalThis.__dekaronNoPrewarm)
      touchPrograms(this.renderer);   // their first-use setup now, not when the object first comes into view
      markProgramsTouched(this);      // (the play-time first-use set-up of new programs, one per frame, starts from here: engine/shader-prewarm.js)
      // lane-perf: the one hidden-scene draw of a load (under the cover), so the first visible frame meets no first-draw stall
      try { if (this.settings.bloom) (this.bloom ||= new Bloom(this.renderer)).render(this.scene, this.camera); else this.renderer.render(this.scene, this.camera); times.warmDraws = (times.warmDraws || 0) + 1; } catch (err) { console.warn('[game] warm draw failed', err); }
      warmWholeScene(this);           // and one hidden draw of everything (texture uploads), the view-culled parts too
      this.renderer.render(this.scene, this.camera);
      flushWarmDraws(this);   // their first draw too, still under the loading screen
      tickShaderPrewarm(this, { all: true });   // and their first draws
      lap('warmDraws');
    } catch (err) { if(err?.loadingStageFailure)throw err;console.warn('[game] warm-up render failed', err); }
    times.total = Math.round(performance.now() - t);
  }

  async _spawnNpcs(world) {
    const list = world.npcPlacements || [];
    const defs = this.data.npcs?.npcs || {};
    const focus={x:Number(this.player?.x)||0,z:Number(this.player?.z)||0};
    const distance2=pl=>(pl.x-focus.x)**2+(pl.z-focus.z)**2;
    const near=[];
    for(const pl of [...list].sort((a,b)=>distance2(a)-distance2(b))){
      const def = defs[pl.npcIndex];
      if (!def) continue;
      try {
        const npc = new NPC(this, { index: pl.npcIndex, ...def }, pl);
        if(this.world!==world){npc.dispose();continue;}
        this.npcs.push(npc);
        const job=npc.load().catch(err=>console.warn('npc failed',pl.npcIndex,err));
        if(distance2(pl)<=32*32)near.push(job);
      } catch (err) { console.warn('npc failed', pl.npcIndex, err); }
    }
    // Nearby service bodies are prioritised; the rest keep streaming after
    // entry. All authored NPC identities are present for map/quest lookups.
    let timer;
    try{await Promise.race([Promise.all(near),new Promise(resolve=>{timer=setTimeout(resolve,5000);})]);}
    finally{clearTimeout(timer);}
  }

  /**
   * Teleport to another map (or another spot on this one). pos = FILE {x, z, dirDeg}; null / invalid = the map's
   * start point (opts.respawn: its respawn point).
   */
  travel(mapIndex, pos = null, opts = {}) {
    if (this.save.authority === 'server' && !opts.serverTransfer) return this.network?.travel(mapIndex, opts.gateId) || Promise.resolve();
    if (this.world && Number(mapIndex) === this.world.info.index && !this._loadingMap) {
      const w = this.world;
      const p = validPos(pos) && w.isWalkable(pos.x, pos.z) ? pos
        : validPos(pos) ? (w.nearestWalkable(pos.x, pos.z, 8) || w.startPoint(!!opts.respawn))
          : w.startPoint(!!opts.respawn);
      this._resetTravelState();
      this.player.setPosition(p.x, p.z);
      if (Number.isFinite(p.dirDeg)) this.player.yaw = (p.dirDeg * Math.PI) / 180;
      if (this.controller?.setTarget) this.controller.setTarget(null); else this.player.target = null;
      this.controller?.stop?.();
      this.cam.snap();
      this.events.emit('teleport', { index: w.info.index, x: p.x, z: p.z });
      return Promise.resolve();
    }
    return this.enterMap(mapIndex, validPos(pos) ? pos : null, null, opts);
  }

  /** A transfer ends actions in the old location and samples the destination's floor without the old Y limit. */
  _resetTravelState() {
    this.audio?.resetWorldAudio?.();
    this.skills?.cancel?.();
    this.controller?.stop?.();
    if (this.controller?.setTarget) this.controller.setTarget(null);
    const p = this.player;
    if (!p) return;
    p.target = null;
    p._grounded = false;
    p._knockback = null;
    p._serverPose = null;
    p._gpState = null;
    p._gpHold = 0;
  }

  /**
   * Where the player returns after death ("Revive in town"): share/arrange/maprespawn.csv for instance maps, else
   * the maplist return point (RetMapIndex/RetX/RetY, ignoring the (11,11) corner placeholders of arena rows), else
   * Ardeca's town return point (portallocation "Ardeca" 349,129), as on the user's server.
   */
  respawnTarget(mapIndex = this.world?.info?.index) {
    const rows = this.world?._tables?.maprespawn || [];
    const n = v => { const x = Number(String(v ?? '').trim()); return Number.isFinite(x) ? x : null; };
    for (const r of rows) {
      if (n(r.MapIndex) !== Number(mapIndex)) continue;
      const m = n(r.RespawnMap), x = n(r.LocationX_1), z = n(r.LocationY_1);
      if (m != null && this.mapRow(m) && x > 0 && z > 0) return { mapIndex: m, x: x + 0.5, z: z + 0.5, dirDeg: 0 };
    }
    const row = this.mapRow(mapIndex);
    const ret = n(row?.RetMapIndex), rx = n(row?.RetX), ry = n(row?.RetY);
    if (row && ret != null && this.mapRow(ret) && (rx > 16 || ry > 16)) return { mapIndex: ret, x: rx + 0.5, z: ry + 0.5, dirDeg: n(row.RetDirection) || 0 };
    const r = this.data.respawnFor(ARDECA_MAP);
    return { mapIndex: r.mapIndex, x: r.x, z: r.z, dirDeg: r.dirDeg || 0 };
  }

  revive() {
    if (this.save.authority === 'server') return this.network?.revive();
    const p = this.player;
    const F = this.data.classesFile?.formula || {};
    const hpPct = Number(F.byRespawnHPRatio) > 0 ? Number(F.byRespawnHPRatio) : 100;
    const mpPct = Number(F.byRespawnMPRatio) > 0 ? Number(F.byRespawnMPRatio) : 100;
    const r = this.respawnTarget();
    p.dead = false;
    p.hp = Math.max(1, Math.round(p.maxHp * hpPct / 100));
    p.mp = Math.round(p.maxMp * mpPct / 100);
    if (this.controller?.setTarget) this.controller.setTarget(null); else p.target = null;
    p.lastCombat = null;
    p.play('idle', { loop: true });
    this.events.emit('revive', { actor: p });
    return this.travel(r.mapIndex, r, { respawn: true });
  }

  refreshPlayerStats(fill) {
    const st = deriveStats(this.save, this.classDef, this.data);
    this.player.stats = st;
    this.player.maxHp = st.maxHp;
    this.player.maxMp = st.maxMp;
    this.player.level = this.save.level;
    if (fill) { this.player.hp = st.maxHp; this.player.mp = st.maxMp; }
    this.player.hp = Math.min(this.player.hp ?? st.maxHp, st.maxHp);
    this.player.mp = Math.min(this.player.mp ?? st.maxMp, st.maxMp);
  }

  // ------------------------------------------------------------------ queries
  actors() {
    const list = [];
    if (this.player) list.push(this.player);
    for (const m of this.spawner?.monsters || []) list.push(m);
    for (const n of this.npcs) list.push(n);
    for (const a of this.network?.actors?.() || []) list.push(a);
    return list;
  }

  /** Closest actor under the screen point (ndc), using a capsule-ish sphere per actor. */
  pickActor(ndc, filter = a => a !== this.player) {
    this.raycaster.setFromCamera(ndc, this.camera);
    const ray = this.raycaster.ray;
    // The native first-person camera aims from eye height, while the original
    // actor pick volume is centred on the torso.  A strict torso sphere makes
    // a target disappear from the click path whenever the crosshair is over
    // its shoulder/weapon.  Keep the normal third-person pick volume exact and
    // add a small, bounded aim assist only for first-person input.
    const firstPerson = this.cam?.mode === 'first-person';
    const aimScale = firstPerson ? 1.45 : 1;
    const c = new THREE.Vector3();
    let best = null, bestT = Infinity;
    for (const a of this.actors()) {
      if (!filter(a) || !a.group?.visible) continue;
      const h = a.height || 2;
      const r = Math.max(0.6, (a.radius || 0.5) * 1.1);
      // test a few spheres stacked along the body
      const n = Math.max(1, Math.round(h / (r * 1.5)));
      for (let i = 0; i < n; i++) {
        fileToThree(a.x, (a.y || 0) + (h * (i + 0.5)) / n, a.z, c);
        const rr = Math.max(r, h / (2 * n)) * (a.dead ? 0.8 : 1);
        const d2 = ray.distanceSqToPoint(c);
        if (d2 > (rr * aimScale) * (rr * aimScale)) continue;
        const t = c.clone().sub(ray.origin).dot(ray.direction);
        if (t > 0 && t < bestT) { bestT = t; best = a; }
      }
    }
    return best;
  }

  /** FILE-frame ground point under the screen point, or null. */
  pickGround(ndc) {
    this.raycaster.setFromCamera(ndc, this.camera);
    return this.world ? this.world.pickGround(this.raycaster) : null;
  }

  // ------------------------------------------------------------------ loop
  _frame(now) {
    const dt = Math.min(0.1, Math.max(0, (now - this._last) / 1000));
    this._last = now;
    this.time += dt;
    const inp = this.input;
    inp.pollGamepad?.();
    // playgate: every step is guarded, so one module throwing (a bad monster, a system bug) is logged and skipped
    // instead of freezing the whole frame loop (a frozen canvas = a soft-lock for the player)
    const safe = this._safeStep || (this._safeStep = (name, fn) => {
      try { fn(); } catch (err) {
        const key = `${name}:${err?.message}`;
        const seen = (this._frameErrors ||= new Map());
        if (!seen.has(key)) console.error(`[game] ${name} threw (logged once; the frame goes on)`, err);
        seen.set(key, (seen.get(key) || 0) + 1);
      }
    });

    let updateBubbles=false;
    if (!this.paused && this.world && this.player) {
      updateBubbles=true;
      safe('keys', () => {
        this.uiwin?.handleKeys(inp);   // hotkeys registered by systems (a registered key replaces the built-in one below)
        // LANE17: like handleKeys, the built-in window keys pause while a modal dialog or UI text field owns input.
        const uiOwnsKeys = !!this.uiwin?.capturesInput;
        if (!uiOwnsKeys && inp.hit('KeyC') && !this.uiwin?.hasHotkey('KeyC')) this.windows.toggle('character');
        if (!uiOwnsKeys && inp.hit('KeyK') && !this.uiwin?.hasHotkey('KeyK')) this.windows.toggle('skills');
        if (!uiOwnsKeys && inp.hit('KeyI') && !this.uiwin?.hasHotkey('KeyI')) this.windows.toggle('inventory');
        if (!uiOwnsKeys && inp.hit('KeyM') && !this.uiwin?.hasHotkey('KeyM')) this.windows.toggle('map');
        if (inp.hit('Escape')) {
          if (this.uiwin?.handleEscape()) { /* a drag, dropdown or original window took it */ }
          else if (this.windows.anyOpen) this.windows.closeAll();
          // one press: release the target (guide_info_system.txt 1301:1 "ESC: close popups and, with a target set, release the
          // target") AND open the system menu (producer/shortkey.txt "SYSTEMMENU esc"). 2.2.0 needed a second press with a target.
          else { this.controller.onEscape?.(); this.windows.toggle('settings'); }
        }
      });

      safe('controller', () => this.controller.update(dt));
      safe('skills', () => this.skills.update(dt));
      if (this.save.authority !== 'server') safe('spawner', () => this.spawner.update(dt));
      for (const n of this.npcs) safe('npc', () => n.update(dt));
      safe('player', () => this.player.update(dt));
      if (this.save.authority !== 'server') safe('loot', () => this.loot.update(dt));
      updateSystems(this, dt);
      if (this.save.authority !== 'server') safe('regen', () => tickRegen(this, dt));

      safe('camera', () => {
        fileToThree(this.player.x, this.player.y, this.player.z, this.cam.target);
        this.cam.update(dt);
      });
      // (a map change started during this frame - warp zone, return scroll - has already dropped the old world)
      safe('world', () => this.world?.update(dt, this.camera.position));
      safe('audio', () => this.audio.update?.(dt));

      this._saveTimer += dt;
      if (this._saveTimer > AUTOSAVE_SECONDS) safe('persist', () => this.persist());
    }
    safe('hud', () => this.hud.update(dt));
    // Speech shares this frame's camera and projected nameplate. Retain the
    // same pause/map-loading timer gate as the other world systems above.
    if(updateBubbles)safe('bubbles',()=>this.hudOptions?.bubbles?.update(dt));
    safe('uiwin', () => this.uiwin?.update(dt));
    safe('render', () => {
      // lane-perf: while a map loads behind the opaque loading cover the scene is not drawn every frame (nothing of it is visible;
      // its programs are compiled by _warmUp via compileAsync and drawn once there). Pre-build work below still runs.
      const covered = this._loadingMap === true && this._worldReady === false;
      if (covered) this._coveredFramesSkipped = (this._coveredFramesSkipped || 0) + 1;
      else if (this.settings.bloom) (this.bloom ||= new Bloom(this.renderer)).render(this.scene, this.camera);
      else this.renderer.render(this.scene, this.camera);
      flushWarmDraws(this);   // queued first draws of pre-built shaders, no pixels (engine/warm-draw.js)
      tickShaderPrewarm(this);   // background pre-builds (corpse fades, drops, status shells): one first draw per frame, no pixels (engine/shader-prewarm.js)
      this._launcherReadiness?.rendered();
    });
    inp.endFrame();
  }

  persist() {
    if (!this.player || !this.world) return;
    this._saveTimer = 0;
    const s = this.save;
    s.map = this.world.info.index;
    s.pos = { x: +this.player.x.toFixed(2), z: +this.player.z.toFixed(2), dirDeg: +((this.player.yaw * 180) / Math.PI).toFixed(1) };
    s.hp = Math.round(this.player.hp);
    s.mp = Math.round(this.player.mp);
    // real play time since the last save (persist also runs on map changes / level-ups, not only every 20 s)
    const played = Math.max(0, this.time - (this._persistTime ?? 0));
    this._persistTime = this.time;
    s.playSeconds = Math.round((s.playSeconds || 0) + played);
    saveCharacter(s);
    this.events.emit('save');
  }

  setSettings(patch) {
    Object.assign(this.settings, patch);
    saveSettings(this.settings);
    this.audio.setVolumes({ music: this.settings.musicVolume, sfx: this.settings.sfxVolume });
    this.renderer.shadowMap.enabled = !!this.settings.shadows;
  }
}
