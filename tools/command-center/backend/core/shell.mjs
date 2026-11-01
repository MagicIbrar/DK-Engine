// Private stdio channel to the desktop window (dialogs, spawning outside the job, window state).
// Without a window (automated tests) every request fails clearly or uses a documented headless fallback.
import readline from 'node:readline';
import {EventEmitter} from 'node:events';

export const shellEvents = new EventEmitter();
let nextId = 1, attached = false, lastInfo = {};
const pending = new Map();
export function attachShell() {
  if (!process.env.DKCC_SHELL_PID) return false;
  attached = true;
  const rl = readline.createInterface({input: process.stdin, crlfDelay: Infinity});
  rl.on('line', line => {
    let msg; try { msg = JSON.parse(line); } catch { return; }
    if (msg.t === 'res') { const p = pending.get(msg.id); if (p) { pending.delete(msg.id); clearTimeout(p.timer); msg.ok ? p.resolve(msg) : p.reject(new Error(msg.error || 'Window request failed.')); } }
    else if (msg.t === 'evt') { if (msg.name === 'shell') lastInfo = msg; shellEvents.emit(msg.name, msg); }
  });
  rl.on('close', () => { attached = false; for (const p of pending.values()) p.reject(new Error('The window closed.')); pending.clear(); shellEvents.emit('eof'); });
  return true;
}
export const hasShell = () => attached;
export const shellInfo = () => lastInfo;
export function send(type, body) { if (!attached) return; process.stdout.write(JSON.stringify({t: type, ...body}) + '\n'); }
export function request(op, body = {}, timeoutMs = 15000) {
  if (!attached) return Promise.reject(Object.assign(new Error('This action needs the DK Command Center window.'), {status: 409}));
  const id = nextId++;
  return new Promise((resolve, reject) => {
    // Dialogs wait for the person; everything else is short.
    const timer = setTimeout(() => { pending.delete(id); reject(new Error('The window did not answer.')); }, op.startsWith('dialog.') ? 30 * 60 * 1000 : timeoutMs);
    pending.set(id, {resolve, reject, timer});
    send('req', {id, op, ...body});
  });
}
