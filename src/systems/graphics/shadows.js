// Sun shadow tuning (the client only shadows skinned models: data/binary/shadowobject.fx has ShadowBone techniques
// only; static shadows are baked into the terrain vertex colours - objects.js). environment.js places the sun and its
// 64 x 64 m shadow box around the camera target every frame; here, just before each render:
//   * the box follows the camera distance (a close camera gets a tighter box = sharper texels),
//   * the box centre is snapped to whole shadow texels along the light's right/up axes, so the shadow edges do not
//     crawl as the player moves (the classic shimmering of a moving orthographic shadow map),
//   * the map size is min(Options "Shadow" size, the adaptive governor's cap),
//   * UPDATE RATE: at >= ~120 fps the depth map is redrawn every 2nd
//     frame only (60+ shadow refreshes a second, the same moving-caster lag as one 60 fps frame); below that every frame,
//     exactly as before. A skipped frame must sample the old map with the matrix that map was DRAWN with. three.js rewrites
//     sun.shadow.matrix on its own (LightShadow.updateMatrices) and src/world/objects.js _cullRigs calls it inside every
//     render, before the depth pass, from the sun's raw un-snapped position; so the hook below saves the matrix after each
//     drawn pass and writes it back when it drops a pass. The box centre is not re-snapped on skip frames (update frames
//     run the unchanged snapping code).
import * as THREE from 'three';

const _f = new THREE.Vector3(), _r = new THREE.Vector3(), _u = new THREE.Vector3(), _d = new THREE.Vector3();
const UP = new THREE.Vector3(0, 1, 0);

// ENGINE-CHOSEN thresholds (every 2nd frame when the frame interval is <~8.4 ms (>= 120 fps), every
// frame below that). SKIP_LEAVE_MS is a hysteresis so a frame time hovering at the threshold does not flap.
export const SHADOW_SKIP_ENTER_MS = 12.5;    // PERF-SHADOWRATE: was 8.4 (>=120 fps); now >= 80 fps -> alternate-frame updates (40+ refreshes/s)
export const SHADOW_SKIP_LEAVE_MS = 14;      // PERF-SHADOWRATE: was 9.2; smoothed frame interval above this -> every frame again
const EMA = 0.15;                            // ENGINE-CHOSEN smoothing of the frame interval (~7 frames to settle)
const MAX_DT_MS = 50;                        // ENGINE-CHOSEN: a hitch / pause counts as 50 ms (it still ends the skip mode)
const SAME_FRAME_MS = 1;                     // ENGINE-CHOSEN: a second main-scene render < 1 ms after the last one (map warm-up,
                                             // screenshot key) is not a new frame: always draw it, never count it

// Smallest Global shadow texture: rc_shadowlevel 1 = 256 (RenderTexture::Shadow FUN_0159c5f0; LANE-66). The old 512 floor
// overrode Global's level-1 size.
export const GLOBAL_MIN_SHADOW_MAP = 256;

export class ShadowTuner {
  constructor(game) {
    this.game = game;
    this.cap = 4096;          // governor cap on the map size
    this.userSize = 512;      // what the Options asked for (hud-options apply.js sets mapSize; remembered here). 512 = Global default level 2
    this.half = 32;
    this.now = () => performance.now();       // replaceable clock (tests)
    this.frameMs = 1000 / 60;                 // smoothed interval between main-scene renders (starts at "60 fps": every frame)
    this.skipping = false;                    // alternate-frame mode on
    this.stats = { drawn: 0, skipped: 0 };
    this._lastAt = null;
    this._lastSkipped = false;
    this._live = false;                       // shadows were active at the previous update()
    this._sun = null;
    this._type = null;
    this._skipScene = null;                   // set by update() on a skip frame: the next depth pass of this scene / camera is skipped
    this._skipCamera = null;
    this._drawn = null;                       // { sun, matrix }: the shadow matrix of the last depth pass that really ran for game.scene / game.camera
  }

  /** Sun light of the loaded world (or null). */
  sun() { return this.game.world?.environment?.sun || null; }

  /**
   * Wrap renderer.shadowMap.render once: on a skip frame the main-scene depth pass is dropped (the same early return three.js
   * takes for autoUpdate=false), every other caller (map warm-up, previews, the aura pass, the map editor) is untouched.
   * Used instead of shadowMap.autoUpdate=false so those other callers keep their automatic update.
   * Matrix: a dropped pass puts back the shadow matrix of the last real pass (see the header); a real main pass records it.
   */
  _hook(r) {
    const sm = r.shadowMap;
    if (sm._dkShadowRate) { sm._dkShadowRate.tuner = this; return; }
    const slot = sm._dkShadowRate = { tuner: this, orig: sm.render };
    sm.render = function (lights, scene, camera) {
      const t = slot.tuner;
      if (t._skipScene !== null && scene === t._skipScene && camera === t._skipCamera) {
        t._skipScene = null; t._skipCamera = null;       // one pass only
        const d = t._drawn, sun = t.sun();
        if (d && sun === d.sun) sun.shadow.matrix.copy(d.matrix);   // undo the updateMatrices() of _cullRigs (raw sun position)
        return undefined;
      }
      // would three.js really run this depth pass? (its early returns: disabled, autoUpdate off without needsUpdate, no shadow light;
      // the aura pass renders the main scene again with shadows disabled: that call must NOT record the matrix _cullRigs just rewrote)
      const g = t.game, sun = t.sun();
      const runs = this.enabled !== false && (this.autoUpdate !== false || this.needsUpdate === true) && !!sun && lights.includes(sun);
      const res = slot.orig.call(this, lights, scene, camera);
      if (runs && scene === g.scene && camera === g.camera && sun.shadow.map) {   // a real main pass ran: its matrix is what the map holds
        if (t._drawn && t._drawn.sun === sun) t._drawn.matrix.copy(sun.shadow.matrix);
        else t._drawn = { sun, matrix: sun.shadow.matrix.clone() };
      }
      return res;
    };
  }

  /** Call once per frame before rendering the main scene (the aura pass's second render() must not call it). */
  update() {
    const g = this.game, sun = this.sun(), r = g.renderer;
    this._skipScene = null; this._skipCamera = null;
    if (!sun || !r?.shadowMap?.enabled || !sun.castShadow) { this._live = false; this._lastAt = null; return; }
    if (!r.shadowMap._dkShadowRate || r.shadowMap._dkShadowRate.tuner !== this) this._hook(r);
    const sh = sun.shadow;
    // frame interval -> alternate-frame mode (with hysteresis)
    const now = this.now();
    let sameFrame = false;
    if (this._lastAt != null) {
      const dt = now - this._lastAt;
      if (dt < SAME_FRAME_MS) sameFrame = true;
      else this.frameMs += (Math.min(dt, MAX_DT_MS) - this.frameMs) * EMA;
    }
    this._lastAt = now;
    const rate = globalThis.__dekaronShadowRate;      // tuning / A-B hook (console): 1 = every frame, 2 = alternate frames
    if (rate === 1) this.skipping = false;
    else if (rate === 2) this.skipping = true;
    else if (this.skipping) { if (this.frameMs > SHADOW_SKIP_LEAVE_MS) this.skipping = false; }
    else if (this.frameMs < SHADOW_SKIP_ENTER_MS) this.skipping = true;
    // anything that can make the old map wrong is a forced draw: shadows just (re)activated, another sun (new map), no map
    // yet / a freshly disposed one, a changed filter type, no recorded matrix of a real pass for this sun, a duplicate render inside one frame
    let force = !this._live || sun !== this._sun || sameFrame || !sh.map || r.shadowMap.type !== this._type || !this._drawn || this._drawn.sun !== sun;
    this._live = true; this._sun = sun; this._type = r.shadowMap.type;
    // size: the Options value (whatever apply.js last set, while it is above our cap) capped by the governor
    const cur = sh.mapSize.x;
    if (cur !== this._setSize) { this.userSize = cur; force = true; }   // changed by someone else (Options, map load)
    const want = Math.max(GLOBAL_MIN_SHADOW_MAP, Math.min(this.userSize, this.cap));
    if (cur !== want) {
      sh.mapSize.set(want, want);
      sh.map?.dispose?.();
      sh.map = null;
      force = true;
    }
    this._setSize = want;
    if (!force && this.skipping && !this._lastSkipped) {
      // skip frame: keep map + matrix + box (never two skips in a row, so a map is at most one frame old)
      this._lastSkipped = true; this.stats.skipped++;
      this._skipScene = g.scene; this._skipCamera = g.camera;
      return;
    }
    if (!sameFrame) { this._lastSkipped = false; this.stats.drawn++; }    // a duplicate render of one frame draws but does not move the alternation
    // box: follows the camera distance
    const camDist = Number(g.cam?.distance) || 12;
    const half = Math.round(Math.max(14, Math.min(40, 8 + camDist * 1.35)));
    const cam = sh.camera;
    if (cam.right !== half) {
      cam.left = -half; cam.right = half; cam.top = half; cam.bottom = -half;
      cam.updateProjectionMatrix();
    }
    this.half = half;
    // texel snapping of the box centre (light space right / up axes)
    _f.subVectors(sun.target.position, sun.position);
    const len = _f.length();
    if (!(len > 1e-3)) return;
    _f.divideScalar(len);
    _r.crossVectors(Math.abs(_f.y) > 0.99 ? _d.set(0, 0, 1) : UP, _f).normalize();
    _u.crossVectors(_f, _r).normalize();
    const texel = (2 * half) / want;
    const c = sun.target.position;
    const sx = c.dot(_r), sy = c.dot(_u);
    const dx = Math.round(sx / texel) * texel - sx, dy = Math.round(sy / texel) * texel - sy;
    _d.copy(_r).multiplyScalar(dx).addScaledVector(_u, dy);
    sun.position.add(_d);
    sun.target.position.add(_d);
    sun.target.updateMatrixWorld();
    // depth range: just what the box needs (better depth precision than 1..400)
    const near = Math.max(0.5, len - 90), far = len + 60;
    if (Math.abs(cam.near - near) > 0.5 || Math.abs(cam.far - far) > 0.5) { cam.near = near; cam.far = far; cam.updateProjectionMatrix(); }
  }
}
