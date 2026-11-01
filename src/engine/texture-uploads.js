// Upload before publishing a texture to materials, so first draw cannot upload a burst of assets.
// A single driver upload cannot be preempted; record its cost and stop the slice afterward.
import {nextTask} from './yield.js';
export class TextureUploads {
  constructor(renderer, { budgetMs = 2, maxPerFrame = 4 } = {}) {
    this.renderer = renderer; this.budgetMs = budgetMs; this.maxPerFrame = maxPerFrame;
    this.queue = []; this.scheduled = false; this.preloading = false; this._scheduleId = 0;
    this.stats = { uploaded: 0, pending: 0, maxUploadMs: 0, maxSliceMs: 0 };
  }
  upload(texture) {
    if (typeof this.renderer?.initTexture !== 'function') return Promise.resolve(texture);
    this.stats.pending++;
    return new Promise((resolve, reject) => { this.queue.push({ texture, resolve, reject }); this._schedule(); });
  }
  setPreloading(value) {
    if(this.preloading===!!value)return;
    this.preloading=!!value;
    // A frame queued before the loading screen can stop arriving when the
    // window is occluded. Retire it and schedule the same work as a task.
    this._scheduleId++;this.scheduled=false;this._schedule();
  }
  _schedule() {
    if (this.scheduled || !this.queue.length) return;
    this.scheduled = true;
    const id=++this._scheduleId;
    const run=()=>{if(id===this._scheduleId)this.flush();};
    if (!this.preloading && typeof requestAnimationFrame === 'function' && !globalThis.document?.hidden) requestAnimationFrame(run);
    else void nextTask().then(run);
  }
  flush() {
    this.scheduled = false;
    const start = performance.now();
    let count = 0;
    while (this.queue.length && count < this.maxPerFrame && (count === 0 || performance.now() - start < this.budgetMs)) {
      const job = this.queue.shift(), t = performance.now();
      try { this.renderer.initTexture(job.texture); this.stats.uploaded++; job.resolve(job.texture); }
      catch (err) { job.reject(err); }
      this.stats.maxUploadMs = Math.max(this.stats.maxUploadMs, performance.now() - t);
      this.stats.pending--; count++;
    }
    this.stats.maxSliceMs = Math.max(this.stats.maxSliceMs, performance.now() - start);
    this._schedule();
  }
}
