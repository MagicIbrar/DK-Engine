// A server that the launcher started follows its launcher. If that launcher process disappears without a normal
// stop (killed, crashed, signed out of Windows) the server saves every character and exits instead of lingering.
// Only a server started with DEKARON_LAUNCHER_PID is ever watched; a server started by hand has no such variable.
const alive = pid => {
  try { process.kill(pid, 0); return true; }
  catch (error) { return error?.code === 'EPERM'; }
};
export function launcherPidFromEnv(env = process.env, own = process.pid) {
  const text = env.DEKARON_LAUNCHER_PID;
  if (typeof text !== 'string' || !/^[1-9]\d{0,9}$/.test(text)) return null;
  const pid = Number(text);
  return Number.isSafeInteger(pid) && pid !== own ? pid : null;
}
export function watchLauncherProcess({ pid = launcherPidFromEnv(), stop, isAlive = alive, intervalMs = 1000, setTimer = setInterval, clearTimer = clearInterval, log = () => {} } = {}) {
  if (!pid || typeof stop !== 'function') return null;
  let timer = null, stopping = false;
  const check = () => {
    if (stopping || isAlive(pid)) return;
    stopping = true;
    log(`[launcher] launcher process ${pid} ended; saving progress and stopping this server`);
    Promise.resolve().then(stop).then(() => { clearTimer(timer); }, error => { stopping = false; log('[launcher] automatic save and stop failed; retrying', error); });
  };
  timer = setTimer(check, intervalMs);
  timer?.unref?.();
  check();
  return { pid, check, dispose() { clearTimer(timer); } };
}
