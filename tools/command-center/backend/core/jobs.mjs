// Long-running operations with honest progress: a phase name always, a determinate count only when the total is known.
import {randomBytes} from 'node:crypto';
import {event} from './events.mjs';
import {UserError, redact, clip} from './util.mjs';

const jobs = new Map(), lanes = new Map();
const KEEP = 60;
export function startJob({kind, key = kind, lane = null, title, area = 'app', run}) {
  for (const j of jobs.values()) if (j.state === 'running' && j.key === key) return j.public(); // repeated click: same job
  if (lane && lanes.has(lane)) { const busy = jobs.get(lanes.get(lane)); if (busy?.state === 'running') throw new UserError(`Wait for "${busy.title}" to finish first.`, 409, {busyJob: busy.id}); }
  const id = randomBytes(8).toString('hex'), ctrl = new AbortController();
  const job = {id, kind, key, lane, title, area, state: 'running', phase: null, phases: [], message: '', progress: null, log: [], startedAt: Date.now(), endedAt: null, result: null, error: null, cancellable: true, ctrl,
    public() { return {id, kind, key, title, area, state: this.state, phase: this.phase, phases: this.phases, message: this.message, progress: this.progress, log: this.log.slice(-60), startedAt: this.startedAt, endedAt: this.endedAt, result: this.result, error: this.error, errorCode: this.errorCode || null, errorData: this.errorData || null, cancellable: this.cancellable && this.state === 'running'}; }};
  jobs.set(id, job); if (lane) lanes.set(lane, id);
  const ctx = {
    signal: ctrl.signal,
    phase(name, message = '') { job.phase = name; job.message = message; job.progress = null; const last = job.phases.at(-1); if (last && !last.endedAt) last.endedAt = Date.now(); job.phases.push({name, startedAt: Date.now(), endedAt: null}); ctx.log(name + (message ? ': ' + message : '')); },
    message(text) { job.message = clip(redact(text), 300); },
    progress(done, total, unit = 'items') { job.progress = Number.isFinite(total) && total > 0 && done >= 0 ? {done: Math.min(done, total), total, unit} : null; },
    log(line) { job.log.push({at: Date.now(), line: clip(redact(line), 500)}); if (job.log.length > 400) job.log.splice(0, job.log.length - 400); },
    uncancellable() { job.cancellable = false; },
    throwIfCancelled() { if (ctrl.signal.aborted) throw Object.assign(new Error('Cancelled.'), {cancelled: true}); },
  };
  event('info', area, `${title}: started`);
  Promise.resolve().then(() => run(ctx)).then(result => {
    job.state = 'succeeded'; job.result = result ?? null; event('ok', area, `${title}: done`);
  }, error => {
    job.state = error?.cancelled || ctrl.signal.aborted ? 'cancelled' : 'failed';
    job.error = clip(redact(error?.message || String(error)), 600);
    if (error?.code && typeof error.code === 'string' && !/^E[A-Z]+$/.test(error.code)) { job.errorCode = error.code; job.errorData = error.settings ?? error.data ?? null; }
    event(job.state === 'cancelled' ? 'warn' : 'error', area, `${title}: ${job.state}`, job.error);
  }).finally(() => {
    job.endedAt = Date.now(); const last = job.phases.at(-1); if (last && !last.endedAt) last.endedAt = job.endedAt;
    if (lane && lanes.get(lane) === id) lanes.delete(lane);
    const done = [...jobs.values()].filter(j => j.state !== 'running'); if (done.length > KEEP) for (const j of done.slice(0, done.length - KEEP)) jobs.delete(j.id);
  });
  return job.public();
}
export function getJob(id) { const j = jobs.get(id); if (!j) throw new UserError('That operation is no longer tracked.', 404); return j.public(); }
export function cancelJob(id) { const j = jobs.get(id); if (!j) throw new UserError('That operation is no longer tracked.', 404); if (j.state !== 'running') return j.public(); if (!j.cancellable) throw new UserError('This step cannot be cancelled safely now; it will finish shortly.', 409); j.ctrl.abort(new Error('Cancelled.')); return j.public(); }
export function listJobs({running} = {}) { return [...jobs.values()].filter(j => !running || j.state === 'running').map(j => j.public()); }
export function laneBusy(lane) { const id = lanes.get(lane); const j = id && jobs.get(id); return j && j.state === 'running' ? j.public() : null; }
export function cancelAll() { for (const j of jobs.values()) if (j.state === 'running' && j.cancellable) j.ctrl.abort(new Error('Cancelled.')); }
