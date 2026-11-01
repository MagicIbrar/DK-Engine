// Client for the native helper (DKCommandCenterPreview.exe --native-helper): SQL with real cancellation, DPAPI, process stats.
import {spawn} from 'node:child_process';
import readline from 'node:readline';
import {SHELL_EXE} from './paths.mjs';
import {cleanEnv} from './proc.mjs';
import {event} from './events.mjs';

let child = null, ready = null, nextId = 1;
const pending = new Map();
function start() {
  if (ready) return ready;
  ready = new Promise((resolve, reject) => {
    child = spawn(SHELL_EXE, ['--native-helper'], {windowsHide: true, stdio: ['pipe', 'pipe', 'pipe'], env: cleanEnv()});
    const rl = readline.createInterface({input: child.stdout, crlfDelay: Infinity});
    const timer = setTimeout(() => reject(new Error('The native helper did not start.')), 15000);
    rl.on('line', line => {
      let m; try { m = JSON.parse(line); } catch { return; }
      if (m.id === 0 && m.ready) { clearTimeout(timer); resolve(m); return; }
      const p = pending.get(m.id); if (!p) return; pending.delete(m.id); clearTimeout(p.timer);
      if (m.ok) p.resolve(m); else p.reject(Object.assign(new Error(m.error || 'Native helper error.'), {number: m.number, sqlClass: m.class, cancelled: !!m.cancelled}));
    });
    child.stderr.on('data', d => event('warn', 'app', 'native helper: ' + String(d).trim().slice(0, 300)));
    child.on('exit', code => {
      clearTimeout(timer); const was = ready; ready = null; child = null;
      for (const p of pending.values()) { clearTimeout(p.timer); p.reject(new Error('The native helper stopped.')); }
      pending.clear(); if (code) event('warn', 'app', `Native helper exited (${code}); it restarts on next use.`); void was;
      reject(new Error('The native helper stopped.'));
    });
    child.on('error', e => { clearTimeout(timer); reject(e); });
  });
  ready.catch(() => { ready = null; });
  return ready;
}
export async function native(op, body = {}, timeoutMs = 60000) {
  await start();
  const id = nextId++;
  return new Promise((resolve, reject) => {
    const timer = setTimeout(() => { pending.delete(id); reject(Object.assign(new Error('The native helper did not answer in time.'), {timeout: true})); }, timeoutMs);
    pending.set(id, {resolve, reject, timer});
    child.stdin.write(JSON.stringify({id, op, ...body}) + '\n');
  });
}
export function stopNative() { try { child?.stdin.end(); } catch {} setTimeout(() => { try { child?.kill(); } catch {} }, 1500).unref(); }
export const protect = async (purpose, text) => (await native('dpapi.protect', {purpose, text})).blob;
export const unprotect = async (purpose, blob) => (await native('dpapi.unprotect', {purpose, blob})).text;
