// Running-world facts are separate from saved next-start preferences and old jobs.
export function supersededStartFailure(job, world) {
  return !!(job?.state === 'failed' && ['world.start', 'world.restart'].includes(job.kind) &&
    Number.isFinite(job.endedAt) && job.endedAt > 0 &&
    world?.status === 'running' && !world.stale && !world.lastError && !world.busy &&
    Number.isSafeInteger(world.pid) && world.pid > 0 &&
    Number.isFinite(world.startedAt) && world.startedAt > job.endedAt &&
    Number.isFinite(world.lastStatusAt) && world.lastStatusAt >= world.startedAt);
}

export function storagePresentation(world, next = {}) {
  const running = world?.status === 'running';
  const mode = running ? world.storageMode : next.mode;
  const label = mode === 'sqlserver' ? 'SQL Server' : mode === 'json' ? 'Local files' : 'Checking storage';
  const prefix = running ? world.stale ? 'Last confirmed' : 'Running now' : 'Next start';
  if (mode === 'sqlserver') {
    // Never infer the active database from the settings for a future local start.
    const database = running ? world.storage?.database : next.localDatabase;
    const instance = running ? world.storage?.instance : next.instance;
    return {label, note: database && instance ? `${prefix} · ${database} on ${instance}` : `${prefix} · SQL Server (database details unavailable)`};
  }
  return {label, note: `${prefix} · ${mode === 'json' ? 'local account files' : 'checking storage'}`};
}

/** One inline operation owns its notice. Clearing an older failed notice must
 * never remove a newer operation that replaced it. Job history stays untouched. */
export function worldJobNotice({host, view, job, readWorld, subscribe}) {
  let current = job, disposed = false;
  const check = world => {
    if (!disposed && host.firstChild === view && supersededStartFailure(current, world)) {
      host.hidden = true;
      host.replaceChildren();
    }
  };
  const off = subscribe(check);
  return {
    update(value) { current = value; check(readWorld()); },
    dispose() { if (!disposed) { disposed = true; off(); } },
  };
}
