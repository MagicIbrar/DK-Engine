// Continuous time for a worn effect that loops. A looping scene wraps its own clock every `periodMs` (ScenePlay.update:
// `this.t %= T`), so anything driven by that clock restarts from zero at each wrap. Keyed values (alpha, scale) are meant to
// restart; a texture SCROLL (mesh_status `a b`: `b` UV per second along `a` degrees) is not keyed, it is a running speed, so it
// must be driven by elapsed real time. Without this the scroll snapped back by b * period UV every loop (weapon: 0.2 * 3.5 s = 0.7 UV).
export class LoopClock {
  constructor() { this.base = 0; this.last = 0; }
  /** Elapsed ms since the first call, given the wrapping scene clock `ms` and its period (0 / unknown = no unwrap). */
  tick(ms, periodMs = 0) {
    ms = Number(ms) || 0;
    if (ms + 1e-6 < this.last && periodMs > 0) this.base += periodMs;
    this.last = ms;
    return this.base + ms;
  }
}
