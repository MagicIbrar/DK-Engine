// Background work that must never compete with the loading screen (2.2.1 load-time work): the
// page's idle callback fires on its timeout while a map is still loading (the loading screen keeps the main thread busy,
// so it never idles), which ran a 2.2 s D-Shop icon bake in the middle of "Placing objects". afterWorldReady() waits
// until the world is shown (game._worldReady, no map load in progress), then for a real idle period (or the timeout),
// and re-checks before it runs, so a map change that starts meanwhile defers the work again.
const READY_POLL_MS = 250;

export function worldShown(game) {
  return !!game && game._worldReady === true && game._loadingMap !== true;
}

/** Run fn once after the world is shown and the page is idle. Returns a cancel function. */
export function afterWorldReady(game, fn, { timeout = 2000 } = {}) {
  let cancelled = false, timer = null, idle = null;
  const run = () => { idle = null; if (cancelled) return; if (!worldShown(game)) { wait(); return; } fn(); };
  function wait() {
    if (cancelled) return;
    if (!worldShown(game)) { timer = setTimeout(wait, READY_POLL_MS); return; }
    timer = null;
    if (typeof globalThis.requestIdleCallback === 'function') idle = globalThis.requestIdleCallback(run, { timeout });
    else timer = setTimeout(run, 50);
  }
  wait();
  return () => {
    cancelled = true;
    if (timer !== null) clearTimeout(timer);
    if (idle !== null) globalThis.cancelIdleCallback?.(idle);
  };
}
