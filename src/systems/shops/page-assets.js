import { PreviewReferences } from '../../ui/preview-cache.js';
// Only requested page icons are baked. Shared item/model caches own their image URLs.
export class ShopPageAssets {
  // load(id, {background}): background = a prefetch job (priority > 0). paused(): while true no prefetch job starts
  // (2.2.1: the shops pass "a map is loading", so prefetch bakes never compete with the loading screen).
  constructor(load, { concurrency = 2, limit = 72, yieldWork = () => new Promise(r => setTimeout(r, 0)), retryDelayMs = 1100, visibleAttempts = 3, scheduleRetry = setTimeout, cancelRetry = clearTimeout, paused = () => false, pausePollMs = 250 } = {}) {
    this.load = load; this.concurrency = concurrency; this.limit = limit; this.yieldWork = yieldWork;
    this.paused = paused; this.pausePollMs = pausePollMs; this.pauseTimer = null;
    this.visibleScopes = new Map(); this.retryDelayMs = Math.max(1100, retryDelayMs); this.visibleAttempts = Math.max(1, Math.min(3, visibleAttempts)); this.scheduleRetry = scheduleRetry; this.cancelRetry = cancelRetry;
    this.cache = new PreviewReferences(); this.pending = new Map(); this.jobs = []; this.active = 0; this.background = 0; this.disposed = false;
    this.unsorted = false; this.pumpQueued = false;
  }
  now(id) { return this.cache.get(id) || null; }
  // 2.2.1: the pool can grow while the shop window is open (dshop.js). Background jobs always use at most concurrency - 1 slots.
  setConcurrency(n) { this.concurrency = Math.max(2, Math.floor(Number(n)) || 2); if (!this.disposed) this.pump(); }
  get(id, { signal, priority = 0 } = {}) {
    if (this.disposed || signal?.aborted) return Promise.resolve(null);
    const hit = this.now(id);
    if (hit) { this.cache.delete(id); this.cache.set(id, hit); return Promise.resolve(hit); }
    let job = this.pending.get(id);
    if (!job) {
      job = { id, priority, users: [], started: false };
      job.promise = new Promise(resolve => { job.resolve = resolve; });
      this.pending.set(id, job); this.jobs.push(job); this.unsorted = true;
    }
    if (priority < job.priority) { job.priority = priority; this.unsorted = true; }
    job.users.push(signal);
    // One pump per batch of requests: a pump per request re-sorted the whole queue each time (a 2,000-icon page()
    // call took 2.2 s of one task in the 2.2.0 loading screen).
    if (!this.pumpQueued) { this.pumpQueued = true; queueMicrotask(() => { this.pumpQueued = false; this.pump(); }); }
    return job.promise;
  }
  // At most three attempts per item/page visibility, with no repaint/click required.
  visible(id, { signal, onReady, isVisible = () => true, owner = onReady } = {}) {
    if (this.disposed || signal?.aborted) return Promise.resolve(null);
    if (!signal) return this.get(id).then(value => { if (value && isVisible()) onReady?.(value); return value; });
    let scope = this.visibleScopes.get(signal);
    if (!scope) {
      scope = { jobs: new Map(), abort: () => {
        for (const job of scope.jobs.values()) this.stopVisible(job, null);
        this.visibleScopes.delete(signal); signal.removeEventListener('abort', scope.abort);
      } };
      this.visibleScopes.set(signal, scope); signal.addEventListener('abort', scope.abort, { once: true });
    }
    let job = scope.jobs.get(id);
    if (job?.done) { if (job.value && isVisible()) onReady?.(job.value); return job.promise; }
    if (!job) {
      // A page has nine products. Also bound retained exhausted variant jobs.
      if (scope.jobs.size >= this.limit) {
        const oldest = scope.jobs.keys().next().value;
        this.stopVisible(scope.jobs.get(oldest), null); scope.jobs.delete(oldest);
      }
      job = { id, signal, users: new Map(), attempts: 0, timer: null, done: false };
      job.promise = new Promise(resolve => { job.resolve = resolve; });
      scope.jobs.set(id, job);
    }
    job.users.set(owner, { onReady, isVisible });
    if (!job.started) { job.started = true; void this.attemptVisible(job); }
    return job.promise;
  }
  async attemptVisible(job) {
    const active = () => [...job.users.values()].filter(user => user.isVisible());
    if (job.done || this.disposed || job.signal.aborted || !active().length) { this.stopVisible(job, null); return; }
    job.timer = null; job.attempts++;
    const value = await this.get(job.id, { signal: job.signal, priority: 0 });
    if (job.done || this.disposed || job.signal.aborted || !active().length) { this.stopVisible(job, null); return; }
    if (value) { for (const user of active()) user.onReady?.(value); this.stopVisible(job, value); return; }
    if (job.attempts >= this.visibleAttempts) { this.stopVisible(job, null); return; }
    job.timer = this.scheduleRetry(() => { void this.attemptVisible(job); }, this.retryDelayMs * job.attempts);
  }
  stopVisible(job, value) {
    if (!job || job.done) return;
    job.done = true; job.value = value;
    if (job.timer !== null) this.cancelRetry(job.timer);
    job.timer = null; job.users.clear(); job.resolve(value);
  }
  async page(ids, options) { return Promise.all([...new Set(ids)].map(id => this.get(id, options))); }
  neighbors(ids, page, size, { signal } = {}) {
    // Prefetch a wider ring so D-Shop page flips stay cache-hot (next 3 + previous 2).
    const slices = [];
    for (let d = 1; d <= 3; d++) slices.push({ ids: ids.slice((page + d) * size, (page + d + 1) * size), priority: d });
    for (let d = 1; d <= 2; d++) {
      if (page - d < 0) continue;
      slices.push({ ids: ids.slice((page - d) * size, (page - d + 1) * size), priority: 3 + d });
    }
    return Promise.all(slices.map(s => this.page(s.ids, { signal, priority: s.priority }))).then(rows => rows.flat());
  }
  pump() {
    // Stable sort: re-sorting an already sorted queue never changes its order, so only new or re-prioritised jobs need it.
    if (this.unsorted) { this.jobs.sort((a, b) => a.priority - b.priority); this.unsorted = false; }
    const paused = !this.disposed && !!this.paused();
    while (this.active < this.concurrency && this.jobs.length) {
      const next = this.jobs.findIndex(job => job.priority === 0 || (this.background < Math.max(1, this.concurrency - 1) && !(paused && job.priority > 0)));
      if (next < 0) {
        // Only paused prefetch jobs remain: look again once the pause (a map load) is over.
        if (paused && this.pauseTimer === null) this.pauseTimer = setTimeout(() => { this.pauseTimer = null; this.pump(); }, this.pausePollMs);
        return;
      }
      const job = this.jobs.splice(next, 1)[0];
      if (this.disposed || job.users.every(s => s?.aborted)) { this.finish(job, null); continue; }
      job.started = true; job.background = job.priority > 0; this.active++; if (job.background) this.background++;
      Promise.resolve().then(() => this.load(job.id, { background: job.background })).then(value => {
        if (!this.disposed && value) {
          this.cache.set(job.id, value);
          while (this.cache.size > this.limit) this.cache.delete(this.cache.keys().next().value);
        }
        this.finish(job, this.disposed ? null : value);
      }, () => this.finish(job, null)).finally(async () => {
        // Yield between preparations so category changes can replace queued work.
        await this.yieldWork(); this.active--; if (job.background) this.background--; this.pump();
      });
    }
  }
  finish(job, value) { this.pending.delete(job.id); job.resolve(value); }
  dispose() {
    this.disposed = true; this.cache.clear();
    if (this.pauseTimer !== null) { clearTimeout(this.pauseTimer); this.pauseTimer = null; }
    for (const scope of [...this.visibleScopes.values()]) scope.abort();
    for (const job of this.jobs.splice(0)) this.finish(job, null);
  }
}
