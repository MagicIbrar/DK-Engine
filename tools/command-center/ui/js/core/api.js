// Bridge client: every call is an explicit operation POSTed with the session cookie and the X-DKCC header.
export class ApiError extends Error { constructor(message, info = {}) { super(message); Object.assign(this, info); } }
let sessionLost = false;
export const onSessionLost = new Set();
export async function boot() {
  const code = window.__dkccBoot; try { delete window.__dkccBoot; } catch { window.__dkccBoot = undefined; }
  const r = await fetch('/api/session', {method: 'POST', headers: {'Content-Type': 'application/json', 'X-DKCC': '1'}, body: JSON.stringify({code: code || ''}), credentials: 'same-origin'});
  if (!r.ok) throw new ApiError((await r.json().catch(() => ({}))).error || 'This page only opens inside the DK Command Center window.', {status: r.status});
}
export async function call(method, params = {}, {signal, timeoutMs = 120000} = {}) {
  const ctrl = new AbortController(); const t = setTimeout(() => ctrl.abort(), timeoutMs);
  const relay = () => ctrl.abort(); signal?.addEventListener('abort', relay, {once: true});
  let r;
  try { r = await fetch('/api/call', {method: 'POST', headers: {'Content-Type': 'application/json', 'X-DKCC': '1'}, body: JSON.stringify({method, params}), credentials: 'same-origin', signal: ctrl.signal}); }
  catch (e) { throw new ApiError(signal?.aborted ? 'Cancelled.' : ctrl.signal.aborted ? 'The launcher backend did not answer in time.' : 'The launcher backend is not reachable.', {cancelled: !!signal?.aborted, network: true}); }
  finally { clearTimeout(t); signal?.removeEventListener('abort', relay); }
  const j = await r.json().catch(() => ({ok: false, error: 'Unreadable response.'}));
  if (r.status === 401 && j.sessionExpired && !sessionLost) { sessionLost = true; for (const f of onSessionLost) f(); }
  if (!j.ok) throw new ApiError(j.error || 'Operation failed.', {status: r.status, field: j.field, busyJob: j.busyJob, code: j.code});
  return j.result;
}
/** Wait for a backend job, reporting every state change. Resolves with the final job (any state). */
export async function follow(job, onUpdate, {signal, interval = 400} = {}) {
  let last = '';
  for (;;) {
    if (signal?.aborted) return null;
    let j; try { j = await call('jobs.get', {id: job.id}, {timeoutMs: 15000}); } catch (e) { if (e.status === 404) return {...job, state: 'unknown', error: 'The operation is no longer tracked.'}; await new Promise(r => setTimeout(r, interval * 3)); continue; }
    const key = JSON.stringify([j.state, j.phase, j.message, j.progress, j.log.length]); if (key !== last) { last = key; onUpdate?.(j); }
    if (j.state !== 'running') return j;
    await new Promise(r => setTimeout(r, document.hidden ? interval * 4 : interval));
  }
}
export const reportPerf = (name, ms, detail) => call('diag.perf.report', {name, ms: Math.max(0, Math.round(ms * 10) / 10), ...(detail ? {detail: String(detail).slice(0, 200)} : {})}).catch(() => {});
