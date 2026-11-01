// Frame-rate pacing for the Options "Max fps" limit (apply.js _installFrameLimiter).
//
// requestAnimationFrame fires once per display refresh (239 Hz on a high-refresh monitor = a tick every ~4.18 ms). A limiter
// that only asks "has 1000/limit ms passed since the last frame?" can only ever deliver whole divisions of the display rate:
// on a 239 Hz display a limit of 144 (6.94 ms) skipped every second tick and really ran at ~120 fps, 165 ran at ~120 too.
//
// This pacer keeps a TARGET time that advances by exactly 1000/limit per accepted frame, and accepts a tick when it is within
// half a display interval of that target. The delivered rate therefore averages the requested limit (individual frames
// are at most half a refresh early or late) and a limit above the display rate simply accepts every tick. A long stall
// (tab switch, loading hitch) resets the target instead of paying it back as a burst of catch-up frames.
//
// limit 0 (unlimited) is NOT routed through here by the caller: it stays a pure pass-through with no extra work.
// ENGINE-CHOSEN: the half-interval acceptance window and the 0.1 smoothing of the display-interval estimate are engineering
// choices, not game data; nothing here comes from the game files.

const SMOOTH = 0.1;          // ENGINE-CHOSEN: weight of a new tick interval in the display-interval estimate
const MAX_TICK_MS = 100;     // a gap this long is a stall / mode change, not the display cadence

export class FramePacer {
  constructor() {
    this.target = 0;         // time at which the next frame is due
    this.tickMs = 0;         // smoothed time between two rAF ticks (the display interval); 0 until measured
    this._lastTick = 0;
  }

  /**
   * Called once per rAF tick while a limit is active. Returns true when the game should run a frame for this tick.
   * now = the rAF timestamp (ms); limit = frames per second (> 0).
   */
  accept(now, limit) {
    const d = now - this._lastTick;
    this._lastTick = now;
    if (d > 0 && d < MAX_TICK_MS) this.tickMs = this.tickMs ? this.tickMs + (d - this.tickMs) * SMOOTH : d;
    const period = 1000 / limit;
    // a stall, or a limit that was just raised (target far in the future), must not hold the next frame back
    if (this.target > now + period) this.target = now;
    if (now < this.target - this.tickMs / 2) return false;
    this.target += period;
    // far behind (a stall, or a limit above the display rate): restart the schedule from this frame, no catch-up burst
    if (now - this.target > period) this.target = now + period;
    return true;
  }
}

export function createFramePacer() { return new FramePacer(); }
