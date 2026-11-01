// Tab weapon swap in the first-person view (Tab weapon-swap animation + delay, first-person only).
//
// DATA FACT: the game data defines NO swap clip and NO swap delay. The PC action tables (share/action/pc/*.act.*.csv) hold
// only STAND / MOVE / ATTACK / SKILL / ... rows per weapon style, and "Tab: Switch Weapons" exists only as a tutorial string
// (stringtable_quest_400). So every number below is ENGINE-CHOSEN (the swap is made to take time and be visible);
// nothing here claims to be Global's timing. Third person is untouched: it keeps swapping at once.
//
// What it does: the first-person arms + weapon are lowered out of view (LOWER_SEC), the real swap (items.swapWeaponTab) runs
// at the low point, the arms are held down until the new weapon set is on the rig (or HOLD_MAX_SEC passes), then they are
// raised (RAISE_SEC). A Tab pressed while a swap is running is ignored, which is the delay.
import * as THREE from 'three';

// ENGINE-CHOSEN
export const FP_SWAP = Object.freeze({
  LOWER_SEC: 0.22,    // arms going down
  RAISE_SEC: 0.28,    // arms coming back up
  HOLD_MAX_SEC: 0.45, // longest wait at the low point for the new weapon models (network round trip + model load)
  DROP: 0.55,         // metres the arms sink in camera space at the low point
  PITCH: 0.85,        // radians the arms tilt down at the low point
});

const smooth = x => x * x * (3 - 2 * x);

export class FirstPersonSwap {
  /** @param {object} game  @param {{now?:()=>number, setTimer?:Function, clearTimer?:Function}} [clock] seconds clock + timers (tests inject fakes) */
  constructor(game, clock = {}) {
    this.game = game;
    this.now = clock.now || (() => performance.now() / 1000);
    this.setTimer = clock.setTimer || ((fn, ms) => setTimeout(fn, ms));
    this.clearTimer = clock.clearTimer || (id => clearTimeout(id));
    this.state = null;
    this._m = new THREE.Matrix4(); this._q = new THREE.Quaternion(); this._v = new THREE.Vector3(); this._s = new THREE.Vector3(1, 1, 1); this._e = new THREE.Euler();
  }
  get active() { return !!this.state; }
  /**
   * Take over a Tab swap. Returns true when the swap is handled here (running, or already running and this press is
   * swallowed); false when the caller must swap at once (not eligible).
   * @param {()=>void} commit  performs the real swap
   * @param {boolean} eligible first-person, native arm rig live, on foot, not free-cam
   * @param {()=>string} [signature] identifies the worn weapon set; the raise waits until it differs from the one at commit
   */
  begin(commit, eligible, signature = null) {
    if (this.state) return true;
    if (!eligible) return false;
    const t0 = this.now();
    this.state = { t0, commit, signature, committed: false, sig0: null, tCommit: 0, timer: null };
    this._arm(FP_SWAP.LOWER_SEC);
    return true;
  }
  _arm(sec) { const s = this.state; s.timer = this.setTimer(() => this._tick(), Math.max(0, sec * 1000)); }
  _tick() {
    const s = this.state; if (!s) return;
    const t = this.now();
    if (!s.committed) {
      if (t - s.t0 < FP_SWAP.LOWER_SEC - 1e-6) { this._arm(FP_SWAP.LOWER_SEC - (t - s.t0)); return; }
      s.sig0 = s.signature ? s.signature() : null; s.committed = true; s.tCommit = t;
      try { s.commit(); } catch (err) { console.warn('[first-person-swap] swap failed', err); this.cancel(); return; }
      this._arm(0.05); return;
    }
    // held at the low point until the weapon set changed (or the cap), then the raise phase is timed from here
    if (s.tRaise == null) {
      const changed = s.signature ? s.signature() !== s.sig0 : true;
      if (changed || t - s.tCommit >= FP_SWAP.HOLD_MAX_SEC) s.tRaise = t; else { this._arm(0.05); return; }
    }
    if (t - s.tRaise >= FP_SWAP.RAISE_SEC) { this.state = null; return; }
    this._arm(0.05);
  }
  /** 0 = arms in their normal place, 1 = fully lowered. */
  amount() {
    const s = this.state; if (!s) return 0;
    const t = this.now();
    if (s.tRaise != null) return 1 - smooth(Math.min(1, Math.max(0, (t - s.tRaise) / FP_SWAP.RAISE_SEC)));
    if (!s.committed) return smooth(Math.min(1, Math.max(0, (t - s.t0) / FP_SWAP.LOWER_SEC)));
    return 1;
  }
  /** Camera-space offset applied to the arm rig, or null when idle. The returned matrix is reused; copy it if you keep it. */
  matrix() {
    const a = this.amount(); if (!(a > 0)) return null;
    this._q.setFromEuler(this._e.set(-FP_SWAP.PITCH * a, 0, 0));
    return this._m.compose(this._v.set(0, -FP_SWAP.DROP * a, 0), this._q, this._s);
  }
  cancel() { const s = this.state; if (s?.timer != null) this.clearTimer(s.timer); this.state = null; }
  dispose() { this.cancel(); }
}
