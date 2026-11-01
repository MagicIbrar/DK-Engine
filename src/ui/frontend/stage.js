// Front-end 3D stage: one WebGL renderer + scene + mirror root shared by the login, character-select and
// character-create screens, then handed to the Game (docs/ARCHITECTURE.md §3.9). It looks enough like `game` for
// World (src/world/world.js) and Player (src/actors/player.js) to run unchanged:
//   renderer, scene, camera, worldRoot (scale z = -1, FILE frame), textures, models, data (maplist rows + sound,
//   later the full GameData), settings, world, cam.target (THREE space: shade/shadow centre), time, save = null.
//
// THE MIRROR RULE: the scene maps and the characters live under worldRoot in the raw FILE frame; only the camera is
// placed in THREE space (fileToThree). THE COLOUR RULE: identical renderer set-up to game.js (no colour management,
// linear output, NoColorSpace textures from the shared TextureCache).
//
// Frames: renderer.setAnimationLoop (requestAnimationFrame) plus a timer fallback, so a tab that gets no animation
// frames (background / non-composited) still animates and renders.
import * as THREE from 'three';
import { WORLD_MIRROR, fileToThree } from '../../engine/space.js';
import { TextureCache } from '../../engine/textures.js';
import { ModelCache } from '../../engine/models.js';
import { fetchCSVObjects, fetchJSON } from '../../engine/assets.js';
import { World } from '../../world/world.js';
import { loadSettings } from '../../game/save.js';
import { ItemDB } from '../../systems/items/db.js';
import { FrontPresentation } from './presentation.js';
import { AuthoredEquipmentEffects, equippedEffectIds } from '../../systems/items/authored-effects.js';
import { hasWornEquip } from './character.js';

/** The renderer exactly as game.js sets it up (shared so the canvas keeps a single WebGL context). */
export function createRenderer(canvas, settings = {}) {
  const r = new THREE.WebGLRenderer({ canvas, antialias: true, powerPreference: 'high-performance' });
  configureRenderer(r, settings);
  return r;
}

/** DX9-era look: no colour management, linear output (ARCHITECTURE.md §1); idempotent. */
export function configureRenderer(r, settings = {}) {
  r.setPixelRatio(Math.min(globalThis.devicePixelRatio || 1, 2));
  r.setSize(globalThis.innerWidth || 1024, globalThis.innerHeight || 768, false);
  THREE.ColorManagement.enabled = false;
  r.outputColorSpace = THREE.LinearSRGBColorSpace;
  r.toneMapping = THREE.NoToneMapping;
  r.shadowMap.enabled = !!settings.shadows;
  r.shadowMap.type = THREE.PCFSoftShadowMap;
  return r;
}

/** maplist FOV column (radians of vertical field of view, 0.65 on most rows) -> degrees. */
export function rowFovDeg(row, fallback = 37.2) {
  const f = Number(row?.FOV);
  return f > 0.2 && f < 2.5 ? (f * 180) / Math.PI : fallback;
}

/** Minimal data facade until the full GameData is ready: World only needs mapByIndex (+ optional tables). */
export class FrontData {
  constructor() {
    this.maps = new Map();
    this.sound = null;
    this.classesFile = null;
    this.classes = [];
    this.classByIndex = new Map();
    this.monsters = null;
    this.npcs = null;
  }
  async load() {
    const [rows, sound] = await Promise.all([
      fetchCSVObjects('share/maplist.csv').catch(() => []),
      fetchJSON('/gamedata/sound.json').catch(() => null),
    ]);
    for (const row of rows) {
      const idx = Number(row.Index);
      if (Number.isFinite(idx) && row.MapFile) this.maps.set(idx, row);
    }
    this.sound = sound;
    return this;
  }
  async loadClasses() {
    if (!this._classes) {
      this._classes = fetchJSON('/gamedata/classes.json').then(f => {
        this.classesFile = f;
        this.classes = f.classes || [];
        this.classByIndex = new Map(this.classes.map(c => [Number(c.index), c]));
        return this;
      });
    }
    return this._classes;
  }
  mapByIndex(i) { return this.maps.get(Number(i)) || null; }
}

export class FrontStage {
  /**
   * @param {{canvas:HTMLCanvasElement, renderer?:THREE.WebGLRenderer, settings?:object}} opts
   */
  constructor({ canvas, renderer = null, settings = null } = {}) {
    this.canvas = canvas;
    this.settings = settings || loadSettings();
    this.renderer = renderer || createRenderer(canvas, this.settings);
    this.scene = new THREE.Scene();
    this.scene.background = new THREE.Color(0x000000);
    this.presentation = new FrontPresentation(this);
    this.camera = new THREE.PerspectiveCamera(37.2, this._aspect(), 0.1, 1200);
    this.worldRoot = new THREE.Group();
    this.worldRoot.name = 'worldRoot (FILE frame, Z mirrored)';
    this.worldRoot.scale.copy(WORLD_MIRROR);
    this.scene.add(this.worldRoot);
    this.textures = new TextureCache(this.renderer);
    this.models = new ModelCache(this.textures);
    this.data = new FrontData();
    this.save = null;                         // World reads game.save (continue position); none here
    this.cam = { target: new THREE.Vector3() };
    this.world = null;
    this.worldIndex = null;
    this.time = 0;
    this.actors = new Set();                  // objects with update(dt) (FrontCharacter, ...)
    this.raycaster = new THREE.Raycaster();
    this._frameCbs = new Set();
    this._running = false;
    this._lastTick = 0;
    this._disposed = false;
    this._onResize = () => this.resize();
    globalThis.addEventListener?.('resize', this._onResize);
  }

  _aspect() {
    const w = globalThis.innerWidth || 1024, h = globalThis.innerHeight || 768;
    return w / Math.max(1, h);
  }

  resize() {
    if (this._disposed) return;
    this.renderer.setSize(globalThis.innerWidth || 1024, globalThis.innerHeight || 768, false);
    this.camera.aspect = this._aspect();
    this.camera.updateProjectionMatrix();
  }

  // ---------------------------------------------------------------------------------------- world
  /**
   * Load a front-end scene map (maplist index) under worldRoot, replacing the current one.
   * Reuses the loaded map when it is already the current one.
   * @returns {Promise<World|null>}
   */
  async loadWorld(mapIndex, { focus = null, onProgress = () => {} } = {}) {
    mapIndex = Number(mapIndex);
    // Classes can share a map. The world is assigned before its asynchronous load completes: await that load,
    // rather than treating a half-built backdrop as ready for floor/character framing.
    if (this._worldJob?.mapIndex === mapIndex && this._worldJob.seq === this._worldSeq) return this._worldJob.promise;
    if (!this._worldJob && this.world && this.worldIndex === mapIndex && !this.world._disposed) return this.world;
    const seq = (this._worldSeq = (this._worldSeq || 0) + 1);
    const previous = this._worldJob;
    const job = { mapIndex, seq, promise: null };
    job.promise = this._loadWorld(mapIndex, { focus, onProgress }, seq, previous).finally(() => {
      if (this._worldJob === job) this._worldJob = null;
    });
    this._worldJob = job;
    return job.promise;
  }

  _makeWorld() { return new World({ game: this }); }

  async _loadWorld(mapIndex, { focus, onProgress }, seq, previous) {
    // Serializing replacement avoids disposing an environment while it is still adding its async lights/sky.
    if (previous) await previous.promise.catch(() => null);
    if (seq !== this._worldSeq || this._disposed) return null;
    this.world?.dispose();
    const w = this._makeWorld();
    this.world = w;                           // heightAt works as soon as the terrain is parsed
    this.worldIndex = mapIndex;
    try {
      await w.load(mapIndex, onProgress, focus ? { focus } : {});
      await this.presentation?.setWorld(w);
    } catch (err) {
      console.warn('[frontend] scene map failed to load', mapIndex, err);
      try { w.dispose(); } catch { /* ignore */ }
      if (this.world === w) { this.world = null; this.worldIndex = null; }
      throw err;
    }
    if (seq !== this._worldSeq || this._disposed) {
      w.dispose();
      if (this.world === w) { this.world = null; this.worldIndex = null; }
      return null;
    }
    // the projection's near plane: maplist Camera_Near_Distance (1 m for the class-select maps, 2 m for MAL_Login).
    // It matters: the Bagi / Half Bagi eye (map 106) sits inside a broken slab 1 m in front of it, which the
    // client's near plane clips away.
    const near = Number(this.data.mapByIndex(mapIndex)?.Camera_Near_Distance);
    this.camera.near = near > 0 && near < 10 ? near : 0.1;
    this.camera.updateProjectionMatrix();
    return w;
  }

  unloadWorld() {
    this._worldSeq = (this._worldSeq || 0) + 1;
    const world = this.world;
    if (world) {
      const release = () => { try { world.dispose(); } catch (err) { console.warn('[frontend] world dispose', err); } };
      if (this._worldJob) void this._worldJob.promise.then(release, release);
      else release();
    }
    this.world = null;
    this.worldIndex = null;
  }

  /** Ground height at a FILE point of the current scene map (0 when none). */
  heightAt(x, z, refY = null) {
    try { return this.world ? this.world.heightAt(x, z, refY) : 0; } catch { return 0; }
  }

  // ---------------------------------------------------------------------------------------- camera
  /** Place the camera: eye and target in the FILE frame; optional vertical FOV in degrees. */
  lookFrom(eye, target, fovDeg = null) {
    fileToThree(eye.x, eye.y, eye.z, this.camera.position);
    const t = fileToThree(target.x, target.y, target.z, new THREE.Vector3());
    this.camera.lookAt(t);
    if (fovDeg && Math.abs(this.camera.fov - fovDeg) > 1e-3) { this.camera.fov = fovDeg; this.camera.updateProjectionMatrix(); }
    this.cam.target.copy(t);
  }

  // ---------------------------------------------------------------------------------------- actors
  addActor(a) {
    if (a) {
      this.actors.add(a);
      if (a.showcaseEffectEntries?.()?.length || Object.values(a.save?.equipment || {}).some(e => Number(e?.itemIndex) > 0) || hasWornEquip(a.save)) this._ensureEquipmentEffects();
    }
    return a;
  }

  _ensureEquipmentEffects() {
    if (this._equipmentEffects || this._equipmentEffectsLoad || this._disposed) return;
    const pending = ItemDB.load().then(db => {
      if (this._disposed) return;
      // FrontStage keeps a Set; the equipped-effect renderer expects the gameplay actors() facade.
      const game = Object.create(this);
      game.actors = () => [...this.actors];
      Object.defineProperty(game, 'player', { get: () => [...this.actors].find(a => a.kind === 'player') || null });
      this._equipmentEffects = new AuthoredEquipmentEffects(game, db, {
        entriesForActor: actor => actor.showcaseEffectEntries?.() ?? equippedEffectIds(db, actor.save?.equipment, actor.save?.equip),
      });
    }).catch(err => console.warn('[frontend] equipped effects', err)).finally(() => {
      if (this._equipmentEffectsLoad === pending) this._equipmentEffectsLoad = null;
    });
    this._equipmentEffectsLoad = pending;
  }
  removeActor(a, dispose = true) {
    if (!a) return;
    this.actors.delete(a);
    this._equipmentEffects?.clear(a);
    if (dispose) { try { a.dispose(); } catch { /* ignore */ } }
  }
  clearActors() { for (const a of [...this.actors]) this.removeActor(a, true); }

  /** Closest actor (of `list`) under a screen point (ndc), testing a few spheres stacked along each body. */
  pickActor(ndc, list = [...this.actors]) {
    this.raycaster.setFromCamera(ndc, this.camera);
    const ray = this.raycaster.ray;
    const c = new THREE.Vector3();
    let best = null, bestT = Infinity;
    for (const a of list) {
      if (!a || a.disposed || !a.group?.visible) continue;
      const s = Number(a.scale) > 0 ? Number(a.scale) : 1;
      const h = (a.pickHeight || a.height || 2) * s;
      const r = Math.max(0.45, (a.radius || 0.4) * 1.15 * s);
      const n = Math.max(2, Math.round(h / (r * 1.5)));
      for (let i = 0; i < n; i++) {
        fileToThree(a.x, (a.y || 0) + (h * (i + 0.5)) / n, a.z, c);
        const rr = Math.max(r, h / (2 * n));
        if (ray.distanceSqToPoint(c) > rr * rr) continue;
        const t = c.clone().sub(ray.origin).dot(ray.direction);
        if (t > 0 && t < bestT) { bestT = t; best = a; }
      }
    }
    return best;
  }

  // ---------------------------------------------------------------------------------------- loop
  onFrame(cb) { this._frameCbs.add(cb); return () => this._frameCbs.delete(cb); }

  start() {
    if (this._running || this._disposed) return;
    this._running = true;
    this._last = performance.now();
    this._lastTick = this._last;
    const tick = () => {
      if (!this._running) return;
      const now = performance.now();
      if (now - this._lastTick < 4) return;       // rAF and the fallback timer both fired
      this._lastTick = now;
      this._frame(now);
    };
    this._tick = tick;
    this.renderer.setAnimationLoop(tick);
    // fallback when requestAnimationFrame is starved (hidden / non-composited tab)
    this._fallback = setInterval(() => { if (performance.now() - this._lastTick > 120) tick(); }, 60);
  }

  stop() {
    this._running = false;
    this.renderer.setAnimationLoop(null);
    clearInterval(this._fallback);
    this._fallback = null;
  }

  /** Advance and render one frame by hand (tests / deterministic captures). */
  step(dt = 1 / 30) {
    this._last = performance.now() - dt * 1000;
    this._frame(performance.now());
  }

  _frame(now) {
    const dt = Math.min(0.1, Math.max(0, (now - this._last) / 1000));
    this._last = now;
    this.time += dt;
    for (const cb of [...this._frameCbs]) {
      try { cb(dt, this.time); } catch (err) { console.error('[frontend] frame callback', err); }
    }
    for (const a of [...this.actors]) {
      try { a.update(dt); } catch (err) { console.warn('[frontend] actor update', err); }
    }
    if (this.world) {
      try { this.world.update(dt, this.camera.position); } catch (err) { console.warn('[frontend] world update', err); }
    }
    this._equipmentEffects?.update(dt);
    if (this.presentation) this.presentation.render();
    else this.renderer.render(this.scene, this.camera);
  }

  // ---------------------------------------------------------------------------------------- hand-off
  /**
   * Stop, free the scene and give the renderer + caches to the Game (the canvas keeps its single WebGL context,
   * and models/textures already loaded for the characters are reused in the world).
   */
  handoff() {
    this.stop();
    this.presentation?.dispose();
    this.clearActors();
    this._equipmentEffects?.dispose();
    this._equipmentEffects = null;
    this.unloadWorld();
    this._disposed = true;
    globalThis.removeEventListener?.('resize', this._onResize);
    this.scene.clear();
    return { renderer: this.renderer, textures: this.textures, models: this.models };
  }

  dispose() {
    this.handoff();
    try { this.renderer.dispose(); } catch { /* ignore */ }
  }
}
