// The host's upload budget for the shared world: the measured / entered upload speed x the share the game
// may use (the rest of the network stays free). Every second the bytes the world actually sent (compressed snapshots + command
// replies) are compared with the budget; over it, each client gets a snapshot every 2nd / 3rd / 4th tick (10 -> 5 -> 3.3 -> 2.5
// per second; the client's interpolation adapts, src/systems/network/movement-config.js INTERP_DELAY_* up to 800 ms), back up
// when there is room. The same step-down happens when the tick + broadcast work itself takes too long (CPU). Clients are spread
// over the ticks by their stream slot, so a slower rate also spreads the work. When even the slowest rate does not fit, new
// joins wait (players already in keep playing).
// ENGINE-CHOSEN: thresholds below (no original value exists; the original client ran a different network design).
export const STREAM_BUDGET = Object.freeze({
  MAX_DIVISOR: 4,            // slowest: a snapshot every 4th tick (2.5 per second at the 100 ms tick)
  OVER: 0.95,                // step down above 95% of the budget ...
  UNDER: 0.75,               // ... step back up when the faster rate would stay under 75%
  WORK_MS_HIGH: 70,          // tick + broadcast EWMA above this (of the 100 ms tick) also steps down
  WORK_MS_LOW: 40,           // and allows stepping back up only below this
  FULL_SECONDS: 5,           // over budget at the slowest rate this long: new joins wait
  DEFAULT_SHARE: 0.7,        // share of the upload the game may use by default
});

export function createStreamBudget({ uploadMbps = 0, share = STREAM_BUDGET.DEFAULT_SHARE, tickMs = 100, now = () => performance.now() } = {}) {
  let divisor = 1, windowAt = now(), windowBytes = 0, rate = 0, work = 0, overSince = null, full = false;
  let budget = 0;
  const configure = (mbps, fraction) => {
    uploadMbps = Number(mbps) > 0 ? Number(mbps) : 0;
    share = Math.min(0.95, Math.max(0.1, Number(fraction) || STREAM_BUDGET.DEFAULT_SHARE));
    budget = uploadMbps > 0 ? uploadMbps * 1e6 / 8 * share : Infinity;
  };
  configure(uploadMbps, share);
  return {
    configure,
    /** Bytes put on the wire (after compression). */
    count(bytes) { if (bytes > 0) windowBytes += bytes; },
    /** Duration (ms) of one tick + snapshot broadcast. */
    work(ms) { if (Number.isFinite(ms)) work = work ? work * 0.8 + ms * 0.2 : ms; },
    /** Whether the stream with this slot gets a snapshot on this tick. */
    due(tick, slot) { return divisor === 1 || (tick + slot) % divisor === 0; },
    /** Once a second (called every tick): re-measure and adjust the rate. */
    update() {
      const t = now(), seconds = (t - windowAt) / 1000;
      if (seconds < 1) return false;
      rate = windowBytes / seconds; windowAt = t; windowBytes = 0;
      const overBytes = rate > budget * STREAM_BUDGET.OVER, overWork = work > STREAM_BUDGET.WORK_MS_HIGH;
      if ((overBytes || overWork) && divisor < STREAM_BUDGET.MAX_DIVISOR) divisor++;
      else if (divisor > 1 && !overBytes && work < STREAM_BUDGET.WORK_MS_LOW && rate * divisor / (divisor - 1) < budget * STREAM_BUDGET.UNDER) divisor--;
      if ((overBytes || overWork) && divisor === STREAM_BUDGET.MAX_DIVISOR) { overSince ??= t; full = t - overSince >= STREAM_BUDGET.FULL_SECONDS * 1000; }
      else { overSince = null; full = false; }
      return true;
    },
    /** New joins wait while the slowest rate still does not fit. */
    get full() { return full; },
    get divisor() { return divisor; },
    state() {
      return { uploadMbps, share, budgetKBps: Number.isFinite(budget) ? Math.round(budget / 1024) : null, sentKBps: Math.round(rate / 1024), snapshotsPerSecond: Number((1000 / tickMs / divisor).toFixed(1)), workMs: Number(work.toFixed(1)), full };
    },
  };
}
