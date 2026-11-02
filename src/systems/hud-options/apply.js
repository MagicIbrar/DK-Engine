import { disposeFirstPersonBody } from '../../engine/native-first-person-presentation.js';
// What every option actually does to the game (graphics, sound, camera, interface scale). OptionStore values in,
// engine state out. Installed once; re-applied on every change and after every map load.
import * as THREE from 'three';
import { EffectComposer } from 'three/addons/postprocessing/EffectComposer.js';
import { RenderPass } from 'three/addons/postprocessing/RenderPass.js';
import { UnrealBloomPass } from 'three/addons/postprocessing/UnrealBloomPass.js';
import { FRAME_LIMITS, BG_FRAMES, QUAKE_SCALE, effectiveFrameLimit } from './settings.js';
import { setOptionTriFilter } from '../../engine/sampler-state.js';
import { createFramePacer } from './frame-pacer.js';
import { saveSettings } from '../../game/save.js';
import { clamp } from './util.js';
import { requestGameFullscreen, releaseFullscreenKeys } from '../../ui/fullscreen-keys.js';
import { withLocalAvatarHidden } from '../../engine/camera.js';

/** Standard display modes offered by the resolution list (the client lists the adapter's modes). */
export const DISPLAY_MODES = [
  [800, 600], [1024, 768], [1152, 864], [1280, 720], [1280, 768], [1280, 800], [1280, 960], [1280, 1024],
  [1360, 768], [1366, 768], [1440, 900], [1600, 900], [1600, 1200], [1680, 1050], [1920, 1080], [1920, 1200],
  [2560, 1080], [2560, 1440], [3440, 1440], [3840, 2160],
];
/**
 * 1024x768 by default (DEFAULTS.resolution and Global data/shadow.txt [init] display_width/height) unless the user changes it, saves and applies it; the next time it starts it is the resolution they saved. A chosen display mode (Options > resolution, Apply / OK; restored from the saved options
 * at start) sizes the game window itself in the desktop clients: Dekaron.exe reads globalThis.__dekaronWindowSize (it polls
 * it, sets its client area and remembers it for the next start, tools/DekaronClient.cs); the Desktop App window is resized
 * by script. A plain browser tab keeps its size ('native' = the window as it is, everywhere).
 */
let windowRequest = null;
export function requestClientWindow(w, h, win = globalThis) {
  if (!(w > 0 && h > 0) || (windowRequest && windowRequest.w === w && windowRequest.h === h)) return false;
  const q = new URLSearchParams(win.location?.search || '');
  windowRequest = { w, h, v: (windowRequest?.v || 0) + 1 };
  if (q.get('shell') === 'native') { win.__dekaronWindowSize = { ...windowRequest }; return true; }
  if (q.get('client') === 'desktop') {
    // a mode that does not fit the desktop as a window is not applied to the window (the client's note 2001:78 shows instead)
    const fw = Math.max(0, win.outerWidth - win.innerWidth), fh = Math.max(0, win.outerHeight - win.innerHeight);
    if (w + fw > (win.screen?.availWidth || Infinity) || h + fh > (win.screen?.availHeight || Infinity)) return false;
    try { win.resizeTo?.(w + fw, h + fh); } catch { /* the browser refused */ }
    return true;
  }
  return false;
}
// com_shadow combo index = Global rc_shadowlevel (LANE-66): the option window sends its +0x47 byte unchanged as
// "rc_shadowlevel %d" (FUN_00b43310; combo writer FUN_00b40370 stores the selection, presets FUN_00b42c00 2/1/0).
// RenderTexture::Shadow (FUN_0159c5f0 / FUN_0159c810): level 0 -> no shadow pass at all, 1 -> 256, 2 -> 512, 3 -> 1024
// (levels >= 2 also use a separate depth surface). Global option.txt default shadowlevel 2. WebGL has depth textures, so
// the exe's no-depth-caps clamp (core +0x132 false -> level <= 2 / presets <= 1) never applies.
export const GLOBAL_SHADOW_MAP = Object.freeze([0, 256, 512, 1024]);
const SHADOW_MAP = GLOBAL_SHADOW_MAP;
// Quality-tier multiplier on Environment.viewDistance (= map Clip_Far / env.clipFar, default 75).
// Global option.txt clipfar 75.00 matches that base (environment.js clipFar || 75); not an OptionStore key (no ui_optionwnd control).
const DRAW_DISTANCE = { good: 1, average: 0.85, poor: 0.7 };
const BLOOM_STRENGTH = [0.45, 0.8, 1.2];

export class OptionEffects {
  constructor(game, store) {
    this.game = game;
    this.store = store;
    this._lastFrame = 0;
    this._shake = null;
    this._materials = new WeakMap();   // material -> original {specular, bumpScale}
    this._waterBase = new WeakMap();   // uniform vec4 -> original amplitude
    this._installFrameLimiter();
    this._installRenderHook();
    this._installCameraHooks();
    this._installAudioHooks();
    this._onResize = () => this.applyResolution();
    addEventListener('resize', this._onResize);
    this._onFs = () => {
      const fs = !!document.fullscreenElement;
      if (!fs && store.get('winmode') === false) store.set({ winmode: true });
    };
    document.addEventListener('fullscreenchange', this._onFs);
    store.on('change', (patch) => this.apply(patch));
    // game.setSettings (other callers) resets the sfx bus to settings.sfxVolume: put the category mix back after it
    if (typeof game.setSettings === 'function' && !game._hoSetSettings) {
      const orig = game.setSettings.bind(game);
      game._hoSetSettings = true;
      game.setSettings = (patch) => { const r = orig(patch); this.applySound(); if (patch && 'shadows' in patch) this.applyShadows(); return r; };
    }
    game.events?.on?.('map', () => { this._camSaved && store.get('saveCamera') && this._restoreCamera(); this.applyWorld(); });
    game.events?.on?.('teleport', () => this.applyWorld());
    this.apply(null);
  }

  // ------------------------------------------------------------------ apply
  /** Apply everything (patch null) or just what a patch touches. */
  apply(patch) {
    const has = k => !patch || k in patch;
    if (has('resolution') || has('winmode')) this.applyResolution();
    if (has('winmode') && patch) this.applyFullscreen();
    if (has('gamma')) this.applyGamma();
    if (has('shadow') || has('quality') || has('highShadow')) this.applyShadows();
    if (has('triFilter')) this.applyTriFilter();
    if (has('quality')) this.applyQuality();
    if (has('bloom') || has('bloomLevel')) this.applyBloom();
    if (['bgm', 'bgmMute', 'effect', 'effectMute', 'ambient', 'ambientMute', 'skillSound', 'skillSoundMute', 'servant', 'servantMute'].some(has)) this.applySound();
    if (['cloud', 'specular', 'bump', 'water', 'quality'].some(has)) this.applyWorld();
    if (has('charName') || has('allShow')) this.applyNames();
    if (has('cameraMode') || has('firstPersonFov')) {
      this.game.cam?.setFirstPersonFov?.(this.store.get('firstPersonFov'));
      this.game.cam?.setMode?.(this.store.get('cameraMode'));
    }
  }

  // ------------------------------------------------------------------ resolution & interface scale
  /**
   * Resolution: 'native' renders at the window size with the interface at 1:1 (auto-fit down to 1024x720 on small
   * windows); an explicit mode sizes the desktop window to WxH (Global windowed) and renders at that many pixels;
   * fullscreen still stretches the mode buffer (as the client does). If the window did not take WxH,
   * render at window pixels so the view is not upscaled; UI still lays out on the virtual WxH screen.
   */
  applyResolution() {
    const g = this.game, r = g.renderer;
    const vw = innerWidth, vh = innerHeight;
    const res = String(this.store.get('resolution') || 'native');
    const m = /^(\d+)x(\d+)$/.exec(res);
    if (m) requestClientWindow(Number(m[1]), Number(m[2]));
    let scale;
    if (m) {
      const w = Number(m[1]), h = Number(m[2]);
      const matched = Math.abs(vw - w) <= 2 && Math.abs(vh - h) <= 2;
      const stretch = matched || !!document.fullscreenElement;
      if (stretch) {
        r?.setPixelRatio?.(1);
        r?.setSize?.(w, h, false);
      } else {
        // Windowed but shell did not take WxH (tab / maximize): avoid upscaling a small buffer.
        r?.setPixelRatio?.(Math.min(devicePixelRatio || 1, 2));
        r?.setSize?.(vw, vh, false);
      }
      scale = Math.min(vw / w, vh / h);
    } else {
      r?.setPixelRatio?.(Math.min(devicePixelRatio || 1, 2));
      r?.setSize?.(vw, vh, false);
      scale = Math.min(1, vw / 1024, vh / 720);
    }
    if (g.camera) { g.camera.aspect = vw / vh; g.camera.updateProjectionMatrix(); }
    this._composer?.setSize?.(r.domElement.width, r.domElement.height);
    scale = Math.round(clamp(scale, 0.3, 3) * 1000) / 1000;
    if (Number(g.settings?.uiScale) !== scale) {
      g.settings.uiScale = scale;
      g.events?.emit?.('settings', g.settings);
    }
  }
  applyFullscreen() {
    const want = this.store.get('winmode') === false;
    // Dekaron.exe owns its window: it polls this request, switches its own border / bounds and remembers the choice for the
    // next start (tools/DekaronClient.cs AskMode); the Fullscreen API is not used there.
    if (new URLSearchParams(globalThis.location?.search || '').get('shell') === 'native') {
      globalThis.__dekaronWindowMode = { fullscreen: want, v: (globalThis.__dekaronWindowMode?.v || 0) + 1 };
      return;
    }
    try {
      if (want && !document.fullscreenElement) requestGameFullscreen().catch(() => this.store.set({ winmode: true }));
      else if (!want && document.fullscreenElement) { releaseFullscreenKeys(); document.exitFullscreen?.().catch(() => {}); }
    } catch { /* not allowed without a user gesture */ }
  }

  // ------------------------------------------------------------------ brightness
  applyGamma() {
    const c = this.game.canvas;
    if (!c) return;
    const v = Number(this.store.get('gamma'));
    const k = 0.5 + clamp(Number.isFinite(v) ? v : 50, 0, 100) / 100;   // 0 -> 0.5, 50 -> 1, 100 -> 1.5
    c.style.filter = Math.abs(k - 1) < 0.005 ? '' : `brightness(${k.toFixed(3)})`;
  }

  // ------------------------------------------------------------------ shadows / quality
  applyShadows() {
    const g = this.game;
    const q = Math.round(Number(this.store.get('shadow')) || 0);
    // high_shadow (option +0x12) is stored only: FUN_00a28080 is a UI layout clamp, not a shadow-size gate (LANE-66),
    // so it no longer changes the shadow tier.
    const high = !!this.store.get('highShadow');
    const tier = clamp(q, 0, 3);
    const on = tier > 0;                  // Global level 0 = no shadow pass (FUN_0159c810)
    g.settings.shadows = on;              // environment.js reads it every update
    g.settings.highShadow = high;
    g.renderer.shadowMap.enabled = on;
    // One filter for every level (WebGL sampling of the depth map; Global samples its shadow texture in shadowobject.fx).
    g.renderer.shadowMap.type = THREE.PCFShadowMap;
    const sun = g.world?.environment?.sun || g.world?.env?.sun;
    const size = SHADOW_MAP[tier] || 0;
    g.settings.shadowMapSize = size;      // environment.js _setupShadows uses it for a newly loaded map
    if (sun?.shadow && size && sun.shadow.mapSize.x !== size) {
      sun.shadow.mapSize.set(size, size);
      sun.shadow.map?.dispose?.();
      sun.shadow.map = null;
    }
  }
  /**
   * tri_filter (option.txt / decompile +0x11): force trilinear + anisotropic sampler state on TextureCache.
   * No ui_optionwnd control; defaults false. Does not change the approved options UI layout.
   */
  applyTriFilter() {
    const on = !!this.store.get('triFilter');
    setOptionTriFilter(on);
    this.game.settings.triFilter = on;
    const cache = this.game.textures || this.game.models?.textures;
    if (cache?.setSampler) {
      try { cache.setSampler(cache.sampler); } catch { /* textures may not be ready yet */ }
    }
  }
  applyQuality() {
    const dd = DRAW_DISTANCE[this.store.get('quality')] ?? 1;
    this.game.settings.drawDistance = dd;   // environment.js / world.js read it every update
  }

  // ------------------------------------------------------------------ world (clouds, specular, bump, water)
  /** Apply current preferences to a newly arrived material without walking the
   * world. Keep its authored scale before suppression, including UV clones. */
  applyMaterial(m) {
    if (!m || !(m.specular || m.bumpMap || m.normalMap)) return;
    let base = this._materials.get(m);
    if (!base) {
      const nativeScale = m.userData?.dkObjectNormalScale;
      const normalScale = Array.isArray(nativeScale) && nativeScale.length === 2 && nativeScale.every(Number.isFinite)
        ? new THREE.Vector2(...nativeScale) : m.normalScale?.clone?.();
      base = { specular: m.specular?.clone?.(), bumpScale: m.bumpScale, normalScale };
      this._materials.set(m, base);
    }
    const spec = !!this.store.get('specular'), bump = !!this.store.get('bump');
    if (m.specular && base.specular) { if (spec) m.specular.copy(base.specular); else m.specular.setRGB(0, 0, 0); }
    if (m.bumpMap && base.bumpScale != null) m.bumpScale = bump ? base.bumpScale : 0;
    if (m.normalMap && base.normalScale) { if (bump) m.normalScale.copy(base.normalScale); else m.normalScale.set(0, 0); }
  }

  /** Per-map state: wraps the environment update (clouds) and walks the scene's materials once. */
  applyWorld() {
    const g = this.game, w = g.world;
    if (!w) return;
    const env = w.environment || w.env;
    if (env && !env._hoCloudWrap && typeof env.update === 'function') {
      const orig = env.update.bind(env);
      env.update = (...a) => { const r = orig(...a); if (!this.store.get('cloud') && env.skyUniforms?.cloudAlpha) env.skyUniforms.cloudAlpha.value = 0; return r; };
      env._hoCloudWrap = true;
    }
    if (env?.skyUniforms?.cloudAlpha && !this.store.get('cloud')) env.skyUniforms.cloudAlpha.value = 0;
    // data/binary/water.fx: waves are an on/off bool per technique (Water/WaterWave, WaterEnv/WaterEnvWave,
    // WaterRefNoWave/WaterRefWave = vsWaterBasic/vsEnvWater/vsWaterRef( bWave )); no technique scales the amplitude.
    // Low = the no-wave technique, Middle / High keep the light file's full wave.
    const waterK = [0, 1, 1][clamp(Math.round(Number(this.store.get('water')) || 0), 0, 2)];
    g.worldRoot?.traverse?.(o => {
      const mats = o.material ? (Array.isArray(o.material) ? o.material : [o.material]) : [];
      for (const m of mats) {
        if (!m) continue;
        this.applyMaterial(m);
        const u = m.uniforms;
        if (u?.wave1?.value?.isVector4) {
          for (const k of ['wave1', 'wave2']) {
            const v = u[k]?.value;
            if (!v) continue;
            if (!this._waterBase.has(v)) this._waterBase.set(v, v.y);
            v.y = this._waterBase.get(v) * waterK;
          }
        }
      }
    });
    this.applyShadows();
  }

  applyNames() {
    const h = this.game.hud;
    // The original guild/alliance/title controls depend on Show character name.
    // View all is a child preference and must not defeat the name master/V key.
    if (h) h.showNameplates = !!this.store.get('charName');
  }

  // ------------------------------------------------------------------ bloom
  _installRenderHook() {
    const g = this.game, r = g.renderer;
    if (!r || r._hoBloom) return;
    const orig = r.render.bind(r);
    r._hoBloom = true;
    r.render = (scene, camera) => withLocalAvatarHidden(scene === g.scene && camera === g.camera ? g : {}, () => {
      if (this._bloomOn && this._composer && !this._inComposer && scene === g.scene && camera === g.camera) {
        this._inComposer = true;
        try { this._composer.render(); } catch (err) { console.warn('[hud-options] bloom off', err); this._bloomOn = false; } finally { this._inComposer = false; }
        return;
      }
      orig(scene, camera);
    });
  }
  applyBloom() {
    const g = this.game;
    const on = !!this.store.get('bloom');
    // the graphics system (src/systems/graphics, game.gfx) draws the client's own bloom (bloomeffect.fx) from these
    // two options every frame; the UnrealBloom composer below is only the fallback when that system is absent
    if (g.gfx) { this._bloomOn = false; return; }
    this._bloomOn = on;
    if (!on) return;
    const lvl = clamp(Math.round(Number(this.store.get('bloomLevel')) || 0), 0, 2);
    if (!this._composer) {
      const c = new EffectComposer(g.renderer);
      c.addPass(new RenderPass(g.scene, g.camera));
      const size = new THREE.Vector2(g.renderer.domElement.width, g.renderer.domElement.height);
      this._bloomPass = new UnrealBloomPass(size, BLOOM_STRENGTH[lvl], 0.35, 0.78);
      c.addPass(this._bloomPass);
      this._composer = c;
    }
    this._composer.setPixelRatio?.(1);
    this._composer.setSize(g.renderer.domElement.width, g.renderer.domElement.height);
    this._bloomPass.strength = BLOOM_STRENGTH[lvl];
  }

  // ------------------------------------------------------------------ frame limits
  _installFrameLimiter() {
    const g = this.game;
    if (g._hoFrameWrap || typeof g._frame !== 'function') return;
    const orig = g._frame.bind(g);
    g._hoFrameWrap = true;
    const pacer = (this._framePacer ||= createFramePacer());
    g._frame = (now) => {
      const bg = document.hidden || (typeof document.hasFocus === 'function' && !document.hasFocus());
      const lim = effectiveFrameLimit(this.store.get('frameLimit'), this.store.get('bgFrame'), bg);
      // lim 0 (unlimited) is a pure pass-through: nothing below runs. A limit is paced against a target time that advances by
      // exactly 1000/lim per frame (frame-pacer.js), so 144 / 165 really average 144 / 165 on a 239 Hz display instead of
      // snapping to every 2nd refresh (~120). game._frame measures its own dt from the timestamps it is handed, so skipped
      // ticks are simply a longer dt there (no double counting).
      if (lim > 0 && !pacer.accept(now, lim)) return;
      this._lastFrame = now;
      orig(now);
    };
  }

  // ------------------------------------------------------------------ camera: shake, saved view, middle-click reset
  _installCameraHooks() {
    const g = this.game, cam = g.cam;
    if (!cam || cam._hoWrap) return;
    cam._hoWrap = true;
    const origUpdate = cam.update.bind(cam);
    cam.update = (dt) => {
      origUpdate(dt);
      const s = this._shake;
      if (s) {
        s.t += dt;
        if (s.t >= s.dur) this._shake = null;
        else {
          const k = s.amp * (1 - s.t / s.dur);
          g.camera.position.x += (Math.random() * 2 - 1) * k;
          g.camera.position.y += (Math.random() * 2 - 1) * k;
          g.camera.position.z += (Math.random() * 2 - 1) * k;
        }
      }
      this._camSaved = cam.thirdPersonView();
    };
    const origConfigure = cam.configure.bind(cam);
    cam.configure = (row) => {
      const keep = this.store.get('saveCamera') && this._camSaved ? { ...this._camSaved } : null;
      origConfigure(row);
      this._defaultView = cam.thirdPersonView();
      if (keep) cam.restoreThirdPersonView(keep);
    };
    this._defaultView = cam.thirdPersonView();
  }
  _restoreCamera() { /* configure() already kept the view */ }
  /** Screen shake (Screen Shake Effect + Display shaking effect strength). amp in world units. */
  shake(amp = 0.25, dur = 0.35) {
    if (!this.store.get('quake')) return;
    const k = QUAKE_SCALE[clamp(Number(this.store.get('quakeOption')) || 0, 0, 3)];
    this._shake = { amp: amp * k, dur, t: 0 };
  }
  /** Middle mouse click: back to the map's default view (the client's wheel-button reset). */
  resetCamera() {
    const cam = this.game.cam, d = this._defaultView;
    if (!cam || !d) return;
    cam.restoreThirdPersonView(d);
    if (cam.mode === 'first-person') cam.pitch = 0;
  }

  // ------------------------------------------------------------------ sound categories
  _installAudioHooks() {
    const a = this.game.audio;
    if (!a || a._hoWrap) return;
    a._hoWrap = true;
    this._audioCategoryGains = new Map(['effect', 'ambient', 'skill', 'servant'].map(c => [c, this._catGain(c)]));
    const origSfx = a.sfx.bind(a);
    const origSkill = a.playSkill?.bind(a);
    let cat = null;
    if (origSkill) a.playSkill = (...args) => { const prev = cat; cat = 'skill'; try { return origSkill(...args); } finally { cat = prev; } };
    a.sfx = (path, opts = {}) => {
      const p = String(path || '').toLowerCase();
      const declared = ['ambient', 'skill', 'servant', 'effect'].includes(opts.category) ? opts.category : null;
      const c = cat || declared || (p.startsWith('ambient/') ? 'ambient' : /servant|summon/.test(p) ? 'servant' : p.startsWith('skill/') ? 'skill' : 'effect');
      const k = this._catGain(c);
      if (k <= 0) return Promise.resolve(null);
      return origSfx(path, { ...opts, category: c, mixGain: () => this._catGain(c) });
    };
  }
  _catGain(c) {
    const S = this.store;
    const pick = (v, m) => (S.get(m) ? 0 : clamp(Number(S.get(v)) || 0, 0, 100) / 100);
    if (c === 'ambient') return pick('ambient', 'ambientMute');
    if (c === 'skill') return pick('skillSound', 'skillSoundMute');
    if (c === 'servant') return pick('servant', 'servantMute');
    return pick('effect', 'effectMute');
  }
  applySound() {
    const g = this.game, S = this.store;
    if (this._audioCategoryGains) for (const [category, previous] of this._audioCategoryGains) {
      const current = this._catGain(category);
      if (previous > 0 && current <= 0) g.audio?.cancelPendingSfx?.(category);
      this._audioCategoryGains.set(category, current);
    }
    const music = S.get('bgmMute') ? 0 : clamp(Number(S.get('bgm')) || 0, 0, 100) / 100;
    // the sfx bus stays at full gain; every sound is scaled by its own category (effect / ambient / skill / summon)
    g.audio?.setVolumes?.({ music, sfx: 1 });
    // the front-end (login/select music and clicks) keeps reading these two
    Object.assign(g.settings, { musicVolume: music, sfxVolume: this._catGain('effect') });
    try { saveSettings(g.settings); } catch { /* storage */ }
  }

  dispose() {
    disposeFirstPersonBody(this.game);
    this.game.cam?.setMode?.('third-person');
    removeEventListener('resize', this._onResize);
    document.removeEventListener('fullscreenchange', this._onFs);
  }
}
