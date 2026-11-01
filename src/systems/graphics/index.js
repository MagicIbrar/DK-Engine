// Graphics system: the original client's look without losing
// frame rate. game.gfx = this module's Graphics:
//
//   bloom      bloom.js - binary/bloomeffect.fx (pow -> 7-tap blur x/y -> add) at 1/4 size, per-map parameters from the
//              light file's bloom_value (time-of-day interpolated), Options "Bloom" + "Bloom brightness".
//   specular   src/engine/matfx.js - specular maps (env reflection on skinned bodies, blinn on items) and glow maps;
//              here: the map's environment panorama + the Options "Reflection" switch (SPEC.gain).
//   shadows    shadows.js - texel-snapped sun shadow box sized to the camera, map size capped by the governor.
//   secondary  secondary.js - spring bones for hair / capes / skirts / tails.
//   governor   governor.js - adaptive quality: render scale, shadow size, draw distance, bloom size.
//
// Rendering: renderer.render(game.scene, game.camera) is wrapped (any caller - the frame loop, the map warm-up, the
// screenshot key - gets the same image): pre-render tuning, the scene straight into the antialiased canvas, then the
// bloom on top, then the secondary-motion bones are restored to their animated values.
//
// Console: dekaron.gfx.stats(), dekaron.gfx.governor.force(n), dekaron.gfx.governor.enabled = false.
import { Bloom, bloomFromEnvironment, BLOOM_LEVELS } from './bloom.js';
import { GlowPass } from './glow-pass.js';
import { ShadowTuner } from './shadows.js';
import { SecondaryMotion } from './secondary.js';
import { Governor, LEVELS } from './governor.js';
import { SPEC, setEnvironment, loadEnvironmentCube } from '../../engine/matfx.js';
import { samplerFromMapRow } from '../../engine/sampler-state.js';
import { freezeMatrices } from '../../engine/models.js';
import { effectiveFrameLimit } from '../hud-options/settings.js';
import { assetWorkStats } from '../../engine/asset-work.js';

const MIGRATE_KEY = 'dekaron-solo:gfx:v1';

export class Graphics {
  constructor(game) {
    this.game = game;
    this.bloom = new Bloom(game.renderer);
    this.glow = new GlowPass(game.renderer);   // aura of glowing gear (glow.fx buffer + blurglow.fx composite), see glow-pass.js
    this.shadows = new ShadowTuner(game);
    this.secondary = new SecondaryMotion(game);
    this.governor = new Governor();
    this.drawScale = 1;              // environment.js multiplies the draw distance by this (governor)
    this.renderScale = 1;
    this._basePR = null;             // pixel ratio the Options / resize set (before our render scale)
    this._appliedPR = null;
    this._bloomEnv = { enabled: true, pow: 2.06, weight: 4.41, strength: 0.4 };
    this._stats = { sceneMs: 0, bloomMs: 0, calls: 0, triangles: 0, frames: 0 };
    this._pacing = { framesOver20Ms: 0, maxFrameMs: 0, longTasks: 0, maxLongTaskMs: 0 };
    game.settings && game.settings.adaptiveQuality === false && (this.governor.enabled = false);
  }

  install() {
    const g = this.game, r = g.renderer;
    if (!r || r._dkGfx) return;
    r._dkGfx = true;
    try {
      if (typeof PerformanceObserver === 'function' && PerformanceObserver.supportedEntryTypes?.includes('longtask')) {
        this._longTasks = new PerformanceObserver(list => {
          if (g._loadingMap || g.paused || document.hidden) return;
          for (const entry of list.getEntries()) {
            this._pacing.longTasks++;
            this._pacing.maxLongTaskMs = Math.max(this._pacing.maxLongTaskMs, entry.duration);
          }
        });
        this._longTasks.observe({ type: 'longtask', buffered: false });
      }
    } catch { /* optional browser diagnostic */ }
    const orig = r.render.bind(r);
    this._origRender = orig;
    r.render = (scene, camera) => {
      if (this._inRender || scene !== g.scene || camera !== g.camera) return orig(scene, camera);
      this._inRender = true;
      try {
        this._beforeRender();
        const t0 = performance.now();
        orig(scene, camera);
        const t1 = performance.now();
        const info = r.info.render;
        this._stats.calls = info.calls; this._stats.triangles = info.triangles;
        this._stats.sceneMs += ((t1 - t0) - this._stats.sceneMs) * 0.1;
        // aura first, so the bloom (which copies the frame) also sees it. Kill switch: globalThis.__dekaronNoAura = true
        if (this.glow.active && !globalThis.__dekaronNoAura && this._opt('aura', true) && this._opt('quality', 'good') !== 'poor') {
          try { this.glow.render(scene, camera); } catch (err) { console.warn('[graphics] aura failed; off', err); this.glow.broken = true; }
        }
        if (this._bloomActive()) {
          try { this.bloom.apply(); } catch (err) { console.warn('[graphics] bloom failed; off', err); this._bloomBroken = true; }
          this._stats.bloomMs += (this.bloom.lastMs - this._stats.bloomMs) * 0.1;
        }
        this._stats.frames++;
      } finally {
        this.secondary.restore();
        this._inRender = false;
      }
    };
    loadEnvironmentCube(g.models?.textures);   // armour env cube, also for the front-end stage
    g.events?.on?.('map', () => this._onMap());
    g.events?.on?.('options', ({ changed } = {}) => this._onOptions(changed || {}));
    if (g.world) this._onMap();
  }

  // ------------------------------------------------------------------ options
  _opt(k, def) {
    const O = this.game.options;
    const v = O?.get ? O.get(k) : undefined;
    return v === undefined ? def : v;
  }

  _migrate() {
    // Retain the legacy migration marker without overriding an explicit saved preference.
    const O = this.game.options;
    if (this._migrated || !O?.set) return;
    this._migrated = true;
    let done = null;
    try { done = localStorage.getItem(MIGRATE_KEY); } catch { /* storage */ }
    if (done) return;
    try { localStorage.setItem(MIGRATE_KEY, '1'); } catch { /* storage */ }
    // DEFAULTS supplies bloom for new stores; an explicit saved false is a user choice.
  }

  _onOptions(changed) {
    if ('specular' in changed || 'quality' in changed) this._applySpecular();
  }

  _applySpecular() { SPEC.gain.value = this._opt('specular', true) ? 1 : 0; }

  _bloomActive() {
    return !this._bloomBroken && !!this._opt('bloom', false) && this._bloomEnv.enabled && this.bloom.params.intensity > 0.001;
  }

  // ------------------------------------------------------------------ map
  async _onMap() {
    const g = this.game, w = g.world;
    this.governor.settle();
    this.glow.invalidateLights();   // the new map's environment makes its own lights (glow-pass.js keeps the scene's light list)
    this._applySpecular();
    // the map's texture sampler state (share/maplist.csv MipMap* / Max / MinFilter, sampler-state.js)
    try { (g.textures || g.models?.textures)?.setSampler?.(samplerFromMapRow(w?.info?.row)); }
    catch (err) { console.warn('[graphics] sampler state failed', err); }
    // static map geometry: computed once, then skipped by the per-frame scene matrix walk (models.js freezeMatrices)
    try {
      if (w?.terrain?.group) freezeMatrices(w.terrain.group, true, true);
      if (w?.water?.group) freezeMatrices(w.water.group, true, true);
    } catch (err) { console.warn('[graphics] freeze failed', err); }
    // the environment the armour specular maps reflect (boneanimation.fx BoneAnimEnv texCUBE): the data's only cube map,
    // texture/environment/cube/test=.dds (matfx.js / material-constants.js). The map's EnvironmentMap strip is the
    // water reflection only.
    const tex = await loadEnvironmentCube(g.models?.textures);
    if (g.world === w) setEnvironment(tex);
  }

  // ------------------------------------------------------------------ frame
  update(dt) {
    const g = this.game;
    if (!this._migrated) this._migrate();
    // governor
    // the limit in force right now, background caps included (the same rule as the limiter in hud-options/apply.js): an unfocused
    // window capped at 15 / 30 fps must not read as lag and cost the player quality when they come back. Unlimited = aim for 60.
    const bg = document.hidden || (typeof document.hasFocus === 'function' && !document.hasFocus());
    const lim = effectiveFrameLimit(this._opt('frameLimit', 0), this._opt('bgFrame', 1), bg) || 0;
    const target = lim > 0 ? Math.min(60, lim) : 60;
    const active = !document.hidden && !g.paused && !g._loadingMap;
    const now = performance.now();
    if (active && this._frameAt != null) {
      const elapsed = now - this._frameAt;
      if (elapsed > 20) this._pacing.framesOver20Ms++;
      this._pacing.maxFrameMs = Math.max(this._pacing.maxFrameMs, elapsed);
    }
    this._frameAt = active ? now : null;
    if (this.governor.tick(performance.now(), active, target)) this._applyLevel();
    else if (this._appliedPR != null && Math.abs(g.renderer.getPixelRatio() - this._appliedPR) > 1e-3) this._applyLevel();   // resized / Options resolution
    // bloom parameters: the environment's current sample
    const env = g.world?.environment?.current;
    if (env) this._bloomEnv = bloomFromEnvironment(env);
    const lvl = Math.max(0, Math.min(2, Math.round(Number(this._opt('bloomLevel', 1)))));
    const b = this.bloom.params;
    b.pow = this._bloomEnv.pow; b.weight = this._bloomEnv.weight;
    b.intensity = this._bloomEnv.strength * BLOOM_LEVELS[lvl];
  }

  _applyLevel() {
    const g = this.game, r = g.renderer, L = LEVELS[this.governor.level];
    // render scale on top of the pixel ratio the Options / resize handler chose
    const cur = r.getPixelRatio();
    if (this._appliedPR == null || Math.abs(cur - this._appliedPR) > 1e-3) this._basePR = cur;
    const pr = Math.max(0.35, this._basePR * L.rs);
    this.renderScale = L.rs;
    if (Math.abs(pr - cur) > 1e-3) r.setPixelRatio(pr);
    this._appliedPR = r.getPixelRatio();
    this.shadows.cap = L.shadow;
    this.drawScale = L.draw;
    this.bloom.scale = L.bloom;
    this.secondary.enabled = L.secondary;
  }

  /**
   * three.js reads renderer.shadowMap.type only while it builds a material's program parameters (SHADOWMAP_TYPE_* define) and does
   * not watch it: a change needs material.needsUpdate. Options > Shadow (hud-options/apply.js applyShadows) flips it between
   * PCFShadowMap (1) and PCFSoftShadowMap (2, 3) and sets no needsUpdate. Until the aura pass kept the lights in step (glow-pass.js
   * STABLE_LIGHT_STATE) the per-frame light-state churn re-checked every lit material in frames with an aura source and so picked the
   * change up by accident (never in frames without one); now it is done on purpose, once per change: every material of the world
   * scene is re-checked. (shadowMap.enabled needs no such hook: applyShadows also flips settings.shadows, which flips sun.castShadow,
   * which changes the shadow count and with it the light-state version.) ENGINE-CHOSEN behaviour (a correctness guard, no data value).
   */
  _syncShadowType(scene) {
    const type = this.game.renderer.shadowMap.type;
    if (this._shadowType === undefined) { this._shadowType = type; return; }
    if (this._shadowType === type) return;
    this._shadowType = type;
    const seen = new Set();
    scene.traverse(o => {
      const m = o.material;
      if (!m) return;
      if (Array.isArray(m)) { for (const x of m) if (x && !seen.has(x)) { seen.add(x); x.needsUpdate = true; } }
      else if (!seen.has(m)) { seen.add(m); m.needsUpdate = true; }
    });
  }

  _beforeRender() {
    const g = this.game;
    try { this._syncShadowType(g.scene); } catch (err) { if (!this._stErr) { this._stErr = true; console.warn('[graphics] shadow type sync failed', err); } }
    try { this.shadows.update(); } catch (err) { if (!this._shErr) { this._shErr = true; console.warn('[graphics] shadow tuning failed', err); } }
    // secondary motion: right before drawing, after every actor / system / the camera updated this frame
    const t = Number(g.time) || 0;
    const dt = this._secT == null ? 0 : t - this._secT;
    this._secT = t;
    if (dt > 0 && !g.paused) {
      try { this.secondary.update(dt); } catch (err) { if (!this._secErr) { this._secErr = true; console.warn('[graphics] secondary motion failed', err); } }
    }
  }

  /** Numbers for tests and the console. */
  stats() {
    const g = this.game, r = g.renderer, s = this._stats;
    return {
      fps: +this.governor.fps.toFixed(1), frameMs: +this.governor.frameMs.toFixed(2), level: this.governor.level,
      renderScale: this.renderScale, pixelRatio: r.getPixelRatio(), drawScale: this.drawScale,
      shadowMap: g.world?.environment?.sun?.shadow?.mapSize?.x ?? null, shadowBox: this.shadows.half,
      bloom: this._bloomActive(), bloomParams: { ...this.bloom.params }, bloomScale: this.bloom.scale,
      aura: { sources: this.glow.sources.size, drawn: this.glow.drawn, ms: +this.glow.lastMs.toFixed(2), broken: this.glow.broken, supported: this.glow.supported },
      sceneMs: +s.sceneMs.toFixed(2), bloomMs: +s.bloomMs.toFixed(2), calls: s.calls, triangles: s.triangles,
      programs: r.info.programs?.length, textures: r.info.memory.textures, geometries: r.info.memory.geometries,
      secondary: { ...this.secondary.stats }, specGain: SPEC.gain.value, history: this.governor.history.slice(-6),
      pacing: { ...this._pacing }, assetWorkers: { ...assetWorkStats }, textureUploads: { ...g.textures?.uploads?.stats },
    };
  }

  dispose() {
    this._longTasks?.disconnect();
    this.bloom.dispose();
    this.glow.dispose();
    this.secondary.restore();
  }
}

export async function install(game) {
  const gfx = new Graphics(game);
  game.gfx = gfx;
  gfx.install();
  gfx._applySpecular();
}

export function update(dt, game) { game.gfx?.update(dt); }

export function dispose(game) { game.gfx?.dispose(); }
