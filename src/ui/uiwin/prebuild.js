import { PREBUILD, PREBUILD_FIRST, PREBUILD_SKIP } from '../../config/engine-chosen-loading.js';
// Idle-time construction of registered windows (UIManager.get without onOpen): the first real open of a panel then
// finds its window already built. Never invokes onOpen/onClose/update or any service action, only builds the
// window (script -> controls -> def.create wiring). Windows whose create() has side effects, HUD windows (their
// owners build them) and anything flagged `prebuild: false` are skipped. Work is cut into short slices that run in
// requestIdleCallback periods and never while a map is loading.

/** Registered windows that may be built ahead of use, in build order (common panels first). */
export function prebuildPlan(manager, { first = PREBUILD_FIRST, skip = PREBUILD_SKIP } = {}) {
  const skipped = [], names = [];
  const blocked = new Set(skip);
  for (const [name, def] of manager.defs) {
    if (def.alias) continue;                                  // `replaces` copies share the original's window
    if (!def.script) { skipped.push([name, 'no script']); continue; }
    if (def.hud) { skipped.push([name, 'hud']); continue; }
    if (def.prebuild === false) { skipped.push([name, 'prebuild:false']); continue; }
    if (blocked.has(name)) { skipped.push([name, 'side effects or heavy create']); continue; }
    names.push(name);
  }
  const rank = new Map(first.map((name, index) => [name, index]));
  names.sort((a, b) => (rank.has(a) ? rank.get(a) : first.length) - (rank.has(b) ? rank.get(b) : first.length));   // stable: rest keeps registration order
  return { names, skipped };
}

// Entry preparation runs under the loading cover, so it does not wait for the
// idle scheduler's world-ready flag. Build one panel at a time and yield between
// builds; never open it or call onOpen/service actions. User-media scans and
// service requests stay in their panels' onOpen handlers.
export async function prepareEntryPanels(manager, {onProgress=()=>{},yieldTask=()=>new Promise(resolve=>setTimeout(resolve,0))}={}) {
  await manager.ready;
  const {names,skipped}=prebuildPlan(manager,{skip:[]});
  const report={planned:names.length,built:0,already:0,skipped,failed:[]};
  onProgress(0,names.length);
  for(const name of names){
    const existing=manager.wins.has(name);
    try {
      const window=await manager.get(name); // also waits for an existing creation promise
      if(window?._creationError)throw window._creationError;
      if(existing)report.already++;else report.built++;
    } catch(error){
      report.failed.push([name,String(error?.message||error)]);
      manager.entryPreparation=report;
      throw Object.assign(new Error('Interface panel preparation failed. Retry loading.'),{cause:error,panel:name});
    }
    onProgress(report.built+report.already,names.length);
    if(!existing)await yieldTask();
  }
  manager.entryPreparation=report;
  return report;
}

const browserIdle = (callback, timeout) => {
  if (typeof globalThis.requestIdleCallback === 'function') {
    const id = globalThis.requestIdleCallback(callback, { timeout });
    return () => globalThis.cancelIdleCallback?.(id);
  }
  const start = performance.now(), id = setTimeout(() => callback({ didTimeout: true, timeRemaining: () => Math.max(0, 4 - (performance.now() - start)) }), 16);
  return () => clearTimeout(id);
};

/**
 * @param manager  UIManager (defs, wins, loadScript, _construct)
 * @param options  { first, skip, idle(callback, timeout) -> cancel, busy() -> bool, now(), setTimer, clearTimer, ...PREBUILD }
 */
export function createPanelPrebuild(manager, options = {}) {
  const cfg = { ...PREBUILD, ...options };
  const now = options.now || (() => performance.now());
  const idle = options.idle || browserIdle;
  const setTimer = options.setTimer || ((fn, ms) => setTimeout(fn, ms)), clearTimer = options.clearTimer || (id => clearTimeout(id));
  // Map loading (and the loading screen) owns the main thread: wait until the world is ready again.
  const busy = options.busy || (() => { const g = manager.game; return !!g && (g._loadingMap === true || g._worldReady !== true); });
  const stats = { planned: 0, built: 0, already: 0, skipped: [], failed: [], slices: 0, maxChunkMs: 0, chunks: 0, offenders: [], busyWaits: 0, startedAt: 0, doneAt: 0, done: false };
  let stopped = false, started = null, cancelIdle = null, timer = null, wake = null;
  const clock = { t0: 0, budget: 0 };

  const record = (label, ms) => {
    stats.chunks++;
    if (ms > stats.maxChunkMs) stats.maxChunkMs = ms;
    if (ms > cfg.warnMs) stats.offenders.push([label, Math.round(ms * 10) / 10]);
  };
  // One slice object per window: construction asks over() between children and yield()s when the budget is spent.
  const makeSlice = name => {
    let chunkStart = now();
    const slice = {
      urgent: false,                                          // a user is waiting for this window: stop slicing
      over: () => !slice.urgent && now() - clock.t0 >= clock.budget,
      begin: () => { chunkStart = now(); },
      end: label => record(`${name}:${label}`, now() - chunkStart),
      async yield() {
        slice.end('build');
        if (slice.urgent) { slice.begin(); return; }
        await slot();
        slice.begin();
      },
    };
    return slice;
  };

  // Wait for a fresh idle slice (or, when the page never idles, a short starved one) outside map loading.
  function slot() {
    return new Promise(resolve => {
      wake = resolve;
      const tick = () => {
        timer = null;
        if (stopped) { resolve(); return; }
        cancelIdle = idle(deadline => {
          cancelIdle = null;
          if (stopped) { resolve(); return; }
          if (busy()) { stats.busyWaits++; timer = setTimer(tick, cfg.busyPollMs); return; }
          const remaining = deadline.timeRemaining();
          if (!deadline.didTimeout && remaining < cfg.minIdleMs) { tick(); return; }
          clock.t0 = now();
          clock.budget = deadline.didTimeout ? cfg.starvedBudgetMs : Math.max(1, Math.min(cfg.budgetMs, remaining - 1));
          stats.slices++;
          wake = null;
          resolve();
        }, cfg.idleTimeoutMs);
      };
      tick();
    });
  }

  async function run() {
    await manager.ready;
    const plan = prebuildPlan(manager, { first: options.first, skip: options.skip });
    stats.skipped = plan.skipped; stats.planned = plan.names.length;
    // Scripts are small text files: fetch them a few at a time ahead of the builds (the spec cache is shared).
    let next = 0;
    const warm = async () => { while (!stopped && next < plan.names.length) { const def = manager.defs.get(plan.names[next++]); if (typeof def?.script !== 'string') continue; try { await manager.loadScript(def.script); } catch { /* the build reports it */ } } };
    for (let i = 0; i < cfg.scriptLanes; i++) void warm();
    for (const name of plan.names) {
      if (stopped) return;
      const def = manager.defs.get(name);
      if (!def || manager.wins.has(name) || def._creating) { stats.already++; continue; }
      await slot();
      if (stopped) return;
      if (manager.wins.has(name) || def._creating) { stats.already++; continue; }   // opened while we waited
      const slice = makeSlice(name);
      slice.begin();
      try { await manager._construct(name, def, slice); stats.built++; }
      catch (error) { stats.failed.push([name, String(error?.message || error)]); }
    }
  }

  const controller = {
    stats,
    start() {
      if (!started) {
        stats.startedAt = now();
        started = run().catch(error => { stats.failed.push(['(prebuild)', String(error?.message || error)]); }).then(() => { stats.done = !stopped; stats.doneAt = now(); return controller.status(); });
      }
      return started;
    },
    stop() { stopped = true; cancelIdle?.(); if (timer !== null) clearTimer(timer); timer = null; const w = wake; wake = null; w?.(); },
    status() { return { ...stats, skipped: stats.skipped.slice(), failed: stats.failed.slice(), offenders: stats.offenders.slice() }; },
    get done() { return started; },
  };
  return controller;
}
