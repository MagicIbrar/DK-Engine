// HUD game-server HTTP round trip, measured by the browser network stack.
// Includes host processing/body transfer; excludes frame scheduling, SQL-only probes and SSE.
// Unknown/stale measurements stay unknown. Rising samples show immediately; recovery is smoothed.
export const API_PREFIX = '/api/world/';
/** this many finished requests without one usable timing entry -> the network figure is considered gone and the label remains unavailable */
export const STALE_AFTER = 24;
export const STALE_MS = 10000;
const SMOOTH_OLD = 0.8, SMOOTH_NEW = 0.2;   // the same smoothing as client.js _noteRoundTrip

/** Network round trip (ms) of one PerformanceResourceTiming entry of an /api/world/ fetch, or null when it is not one / not usable. */
export function entryNetworkMs(entry, origin = globalThis.location?.origin) {
  if (!entry || typeof entry.name !== 'string') return null;
  let url; try { url = new URL(entry.name); } catch { return null; }
  if (origin && url.origin !== origin) return null;
  if (!url.pathname.startsWith(API_PREFIX)) return null;
  const route = url.pathname.slice(API_PREFIX.length);
  if (entry.initiatorType && entry.initiatorType !== 'fetch') return null;          // EventSource ('other'), scripts, images
  if (route === 'events') return null;          // the SSE stream: its entry would span the whole stream
  const start = Number(entry.requestStart), end = Number(entry.responseEnd);
  if (!(start > 0) || !(end > 0) || end < start) return null;                       // 0 = hidden by the browser (cross-origin without Timing-Allow-Origin)
  if (entry.transferSize === 0 && entry.decodedBodySize > 0) return null;           // answered from a cache: no network round trip happened
  const ms = end - start;
  return ms >= 0 && ms < 15000 ? ms : null;
}

export class NetRttMeter {
  constructor({ ObserverClass = globalThis.PerformanceObserver, perf = globalThis.performance, origin = globalThis.location?.origin, now = () => performance.now() } = {}) {
    this.ObserverClass = ObserverClass; this.perf = perf; this.origin = origin; this.now = now; this.lastAt = -Infinity; this.latest = null;
    this.rtt = null; this.samples = 0; this.unsampled = 0; this.observer = null; this._full = null;
  }
  /** start listening; false when the browser cannot give resource timings (the label remains unavailable) */
  start() {
    if (this.observer) return true;
    try {
      const O = this.ObserverClass;
      if (typeof O !== 'function' || !O.supportedEntryTypes?.includes('resource')) return false;
      const observer = new O(list => { try { for (const entry of list.getEntries()) this.sample(entry); } catch { /* keep the page alive */ } });
      observer.observe({ type: 'resource', buffered: false });
      this.observer = observer;
      if (typeof this.perf?.addEventListener === 'function' && typeof this.perf.clearResourceTimings === 'function') {
        this._full = () => { try { this.perf.clearResourceTimings(); } catch { /* ignore */ } };
        this.perf.addEventListener('resourcetimingbufferfull', this._full);
      }
      return true;
    } catch { this.observer = null; return false; }
  }
  sample(entry) {
    const ms = entryNetworkMs(entry, this.origin);
    if (ms == null) return false;
    this.rtt = Number.isFinite(this.rtt) ? this.rtt * SMOOTH_OLD + ms * SMOOTH_NEW : ms;
    this.latest = ms; this.lastAt = Math.min(this.now(), Number(entry.responseEnd));
    this.samples++; this.unsampled = 0;
    return true;
  }
  /** one game request finished (client.js _request): counts requests that did not produce a timing sample since the last one */
  noteRequest() { if (this.observer) this.unsampled++; }
  /** smoothed network round trip in ms, or null when unavailable or stale */
  value() {
    if (!this.observer || !Number.isFinite(this.rtt) || this.unsampled > STALE_AFTER || this.now() - this.lastAt >= STALE_MS) return null;
    return Math.max(this.latest, this.rtt);
  }
  dispose() {
    try { this.observer?.disconnect(); } catch { /* ignore */ }
    try { if (this._full) this.perf?.removeEventListener?.('resourcetimingbufferfull', this._full); } catch { /* ignore */ }
    this.observer = null; this._full = null;
  }
}

