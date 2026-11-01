// Animator: per-instance clip playback with cross-fades (docs/ARCHITECTURE.md §3.3).
//
// Wraps one THREE.AnimationMixer on SkinnedInstance.root. Cross-fades are driven here (not with
// AnimationAction.crossFadeTo) so that a new clip can interrupt a fade that is still running without a pop:
// every frame the current action's weight rises and all others fall at 1/fade per second, and the weights are
// renormalised to sum to 1. Faded-out actions are stopped. Root motion is ignored (the game moves actors itself).
import * as THREE from 'three';

export class Animator {
  /** @param {import('./models.js').SkinnedInstance} instance */
  constructor(instance) {
    this.instance = instance;
    this.root = instance?.root || instance;
    this.mixer = new THREE.AnimationMixer(this.root);
    this.current = null;          // THREE.AnimationAction
    this._fade = 0.15;
    this._layers = [];            // [{ action, w }]
    this._onFinish = null;
    this._finished = false;
    this._loop = true;
    this._onMixerFinished = e => {
      if (e.action === this.current) this._finished = true;
    };
    this.mixer.addEventListener('finished', this._onMixerFinished);
  }

  /** The clip currently playing (or null). */
  get clip() { return this.current ? this.current.getClip() : null; }

  /** Seconds into the current clip. */
  get time() { return this.current ? this.current.time : 0; }

  /** 0..1 of the current clip (wraps for loops, holds 1 after a one-shot ended). */
  get progress() {
    const a = this.current;
    if (!a) return 0;
    const d = a.getClip().duration;
    if (!(d > 0)) return this._finished ? 1 : 0;
    if (this._finished) return 1;
    return Math.max(0, Math.min(1, a.time / d));
  }

  get finished() { return this._finished; }

  /**
   * Play a clip, cross-fading from whatever is playing.
   * Playing the clip that is already looping only updates its speed (no restart); so does asking a loop to loop again while it
   * is still fading out from an earlier play() (it takes over with its phase and weight).
   * @param {THREE.AnimationClip} clip
   * @param {{loop?:boolean, fade?:number, speed?:number, clampWhenFinished?:boolean, restart?:boolean, startAt?:number}} [opts]
   */
  play(clip, { loop = true, fade = 0.15, speed = 1, clampWhenFinished = true, restart = false, startAt = 0 } = {}) {
    if (!clip) return;
    const action = this.mixer.clipAction(clip);
    if (action === this.current && loop && this._loop && !restart && action.isRunning()) {
      action.timeScale = speed;
      return;
    }
    const prev = this.current;
    this._fade = Math.max(0, fade || 0);
    // (a one-shot, or a loop with an explicit restart / start time, that is still fading out from an earlier play() restarts
    //  from the top and keeps its current weight; reset() does not touch weights)
    const layer = this._layers.find(l => l.action === action);
    // A LOOP that is still fading out and is asked to loop again (stop / start flicker, a late host pose) takes over where it is:
    // it keeps its phase as well as its weight. Restarting it from the top while it still carries weight is a visible pose jump.
    const resume = !!layer && !!prev && action !== prev && this._fade > 0 && loop && !restart && !(startAt > 0)
      && action.loop === THREE.LoopRepeat && action.isRunning();
    if (resume) action.timeScale = speed;
    else {
      action.reset();
      action.setLoop(loop ? THREE.LoopRepeat : THREE.LoopOnce, Infinity);
      action.clampWhenFinished = clampWhenFinished;
      action.timeScale = speed;
      if (startAt > 0) action.time = Math.min(startAt, clip.duration);
      action.play();
    }

    if (action === prev || this._fade <= 0 || !prev) {
      // hard switch
      for (const l of this._layers) if (l.action !== action) l.action.stop();
      this._layers = [{ action, w: 1 }];
      action.setEffectiveWeight(1);
    } else if (!layer) {
      this._layers.push({ action, w: 0 });
      action.setEffectiveWeight(0);
    }
    this.current = action;
    this._loop = loop;
    this._finished = false;
    this._onFinish = null;
  }

  /** Call cb once when the current (non-looping) clip ends. Replaced by the next play(). */
  onFinish(cb) {
    this._onFinish = typeof cb === 'function' ? cb : null;
  }

  /** Stop everything (bones keep their last pose). */
  stop() {
    this.mixer.stopAllAction();
    this._layers = [];
    this.current = null;
    this._onFinish = null;
    this._finished = false;
  }

  /** Change the playback speed of the current clip. */
  setSpeed(speed) {
    if (this.current) this.current.timeScale = speed;
  }

  update(dt) {
    if (!(dt > 0)) dt = 0;
    if (this._layers.length > 1) {
      const step = this._fade > 0 ? dt / this._fade : 1;
      let sum = 0;
      for (const l of this._layers) {
        l.w = l.action === this.current ? Math.min(1, l.w + step) : Math.max(0, l.w - step);
        sum += l.w;
      }
      const keep = [];
      for (const l of this._layers) {
        const w = sum > 0 ? l.w / sum : (l.action === this.current ? 1 : 0);
        if (l.action !== this.current && w <= 1e-4) { l.action.stop(); continue; }
        l.action.setEffectiveWeight(w);
        keep.push(l);
      }
      this._layers = keep;
      if (keep.length === 1) { keep[0].w = 1; keep[0].action.setEffectiveWeight(1); }
    }
    this.mixer.update(dt);
    if (this._finished && this._onFinish) {
      const cb = this._onFinish;
      this._onFinish = null;
      try { cb(); } catch (err) { console.error('[animator] onFinish callback failed', err); }
    }
  }

  dispose() {
    this.mixer.removeEventListener('finished', this._onMixerFinished);
    this.mixer.stopAllAction();
    this.mixer.uncacheRoot(this.root);
    this._layers = [];
    this.current = null;
    this._onFinish = null;
  }
}
