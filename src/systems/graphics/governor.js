// Adaptive quality governor: keeps the frame rate at the target (60 fps, or the Options "Max fps" limit when that is
// lower) by stepping down, one level at a time, the settings that cost the most GPU/CPU time, and stepping back up
// when there is headroom again. It never goes ABOVE what the Options ask for: every level is a cap on the user's
// choice (shadow size, draw distance, render resolution, bloom size, secondary motion).
//
//   level 0  everything as the Options set it
//   level 1  shadow map <= 2048
//   level 2  draw distance x0.9, bloom 1/8 size
//   level 3  shadow <= 1024, draw distance x0.8
//   level 4  draw distance x0.7, no secondary motion
//   level 5  shadow <= 512, draw distance x0.6
// The render resolution always stays at 100 % (a lower render scale looked fuzzy); the `rs` field is
// kept for completeness. The animation LOD (actor.js / objects.js) and matrix freezing carry the CPU savings.
//
// Down: the smoothed fps stays under 90 % of the target for DOWN_SECONDS. Up: at or above 97 % for UP_SECONDS; an up
// step that drops the rate again within PROBE_SECONDS is undone and the next try waits twice as long (up to 2 min).
// Idle while the tab is hidden, the game is paused / loading, and for SETTLE_SECONDS after a map load.
export const LEVELS = [
  // Lowering the render resolution made the screen look fuzzy. Stay at full resolution (rs 1) and
  // cut shadows, bloom resolution, draw distance and secondary motion instead.
  { rs: 1.0, shadow: 8192, draw: 1.0, bloom: 4, secondary: true },
  { rs: 1.0, shadow: 2048, draw: 1.0, bloom: 4, secondary: true },
  { rs: 1.0, shadow: 2048, draw: 0.9, bloom: 8, secondary: true },
  { rs: 1.0, shadow: 1024, draw: 0.8, bloom: 8, secondary: true },
  { rs: 1.0, shadow: 1024, draw: 0.7, bloom: 8, secondary: false },
  { rs: 1.0, shadow: 512, draw: 0.6, bloom: 8, secondary: false },
];
const DOWN_SECONDS = 1.2;
const UP_SECONDS = 6;
const PROBE_SECONDS = 3;
const SETTLE_SECONDS = 3;
const COOLDOWN = 1.2;

export class Governor {
  constructor() {
    this.enabled = true;
    this.level = 0;
    this.target = 60;
    this.fps = 60;            // smoothed
    this.frameMs = 16.7;
    this._last = 0;
    this._low = 0; this._high = 0;
    this._cool = 0;
    this._settle = SETTLE_SECONDS;
    this._probe = 0;          // > 0: seconds left in which a drop undoes the last up step
    this._backoff = UP_SECONDS;
    this.history = [];        // [{t, from, to, fps}]
  }

  get settings() { return LEVELS[this.level]; }

  /** A map was (re)loaded: shader compiles and uploads make the first seconds unrepresentative. */
  settle(sec = SETTLE_SECONDS) { this._settle = Math.max(this._settle, sec); this._low = this._high = 0; }

  /**
   * Feed one frame. now = performance.now(); active = the game is running in a visible tab.
   * Returns true when the level changed.
   */
  tick(now, active, target = 60) {
    this.target = target;
    const last = this._last;
    this._last = now;
    if (!last) return false;
    const ms = now - last;
    if (!(ms > 0) || ms > 500 || !active) { this._low = this._high = 0; return false; }   // stalls / hidden: ignore
    this.frameMs += (ms - this.frameMs) * 0.08;
    this.fps = 1000 / this.frameMs;
    const dt = ms / 1000;
    if (this._settle > 0) { this._settle -= dt; return false; }
    if (!this.enabled) return false;
    if (this._cool > 0) this._cool -= dt;
    if (this._probe > 0) this._probe -= dt;
    const lo = this.fps < target * 0.9, hi = this.fps >= target * 0.97;
    this._low = lo ? this._low + dt : 0;
    this._high = hi ? this._high + dt : 0;
    if (lo && this._probe > 0 && this.level < LEVELS.length - 1 && this._low > 0.6) {
      // the last up step did not hold: undo it and wait longer before the next try
      this._backoff = Math.min(120, this._backoff * 2);
      return this._set(this.level + 1, now);
    }
    if (this._low >= DOWN_SECONDS && this._cool <= 0 && this.level < LEVELS.length - 1) return this._set(this.level + 1, now);
    if (this._high >= this._backoff && this.level > 0 && this._cool <= 0) {
      const r = this._set(this.level - 1, now);
      this._probe = PROBE_SECONDS;
      return r;
    }
    return false;
  }

  _set(level, now) {
    const from = this.level;
    this.level = Math.max(0, Math.min(LEVELS.length - 1, level));
    this._low = this._high = 0;
    this._cool = COOLDOWN;
    if (this.level < from) { /* up */ } else this._probe = 0;
    this.history.push({ t: Math.round(now), from, to: this.level, fps: Math.round(this.fps) });
    if (this.history.length > 40) this.history.shift();
    return this.level !== from;
  }

  /** Force a level (tests / console); auto keeps adjusting from there unless enabled = false. */
  force(level) { this._set(level, performance.now()); }
}
