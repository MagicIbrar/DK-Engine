// Bounded polling: never overlaps, pauses while the page/tab is hidden or the window is minimized, backs off on failure,
// keeps the last good value, and stops cleanly (aborting any request in flight).
const all = new Set();
export function poller(fn, {interval = 3000, maxBackoff = 8, active = () => true, immediate = true, name = ''} = {}) {
  let timer = null, running = false, stopped = true, failures = 0, ctrl = null;
  const p = {
    last: null, lastAt: 0, error: null, name,
    get failures() { return failures; },
    get stale() { return p.lastAt > 0 && Date.now() - p.lastAt > interval * 3; },
    start() { if (!stopped) return p; stopped = false; all.add(p); if (immediate) tick(); else schedule(); return p; },
    stop() { stopped = true; all.delete(p); clearTimeout(timer); timer = null; ctrl?.abort(); ctrl = null; return p; },
    now() { clearTimeout(timer); if (!running) tick(); return p; },
    setInterval(ms) { interval = ms; return p; },
    get running() { return !stopped; },
  };
  function schedule() { clearTimeout(timer); if (stopped) return; const wait = interval * Math.min(maxBackoff, 2 ** failures); timer = setTimeout(tick, wait); }
  async function tick() {
    if (stopped || running) return;
    if (document.hidden || !active()) { schedule(); return; }
    running = true; ctrl = new AbortController();
    try { p.last = await fn(ctrl.signal, p.last); p.lastAt = Date.now(); p.error = null; failures = 0; }
    catch (e) { if (!ctrl.signal.aborted) { p.error = e; failures = Math.min(failures + 1, 6); } }
    finally { running = false; ctrl = null; schedule(); }
  }
  return p;
}
document.addEventListener('visibilitychange', () => { if (!document.hidden) for (const p of all) p.now(); });
export const activePollers = () => [...all].map(p => p.name);
