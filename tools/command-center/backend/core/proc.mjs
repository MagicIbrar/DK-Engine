// Child processes. Tools run as ordinary children (inside the window's kill-on-close job). Long-lived processes that
// must survive by design (world server, game windows, deferred updater) are started by the window outside that job.
import {spawn} from 'node:child_process';
import fs from 'node:fs';
import path from 'node:path';
import {EventEmitter} from 'node:events';
import {NODE, ENGINE, writable} from './paths.mjs';
import {hasShell, request, shellEvents} from './shell.mjs';
import {clip} from './util.mjs';

const owned = new Set();
export function ownedChildren() { return [...owned].map(c => ({pid: c.pid, tool: c.dkTool})); }
export function cleanEnv(extra = {}) {
  const env = {...process.env};
  for (const k of Object.keys(env)) if (k.startsWith('DEKARON_') || k.startsWith('DKCC_')) delete env[k];
  return {...env, ...extra};
}
/** Run an engine tool to completion with bounded output, timeout and cancellation. */
export function runTool(script, args = [], {cwd = ENGINE, env = {}, input, timeoutMs = 120000, signal, onLine, maxOutput = 2 * 1024 * 1024, exe = NODE} = {}) {
  return new Promise((resolve, reject) => {
    const child = spawn(exe, script ? [script, ...args] : args, {cwd, env: cleanEnv(env), windowsHide: true, stdio: ['pipe', 'pipe', 'pipe']});
    child.dkTool = path.basename(script || exe); owned.add(child);
    let out = '', err = '', done = false, buf = {out: '', err: ''};
    const finish = (fn, value) => { if (done) return; done = true; clearTimeout(timer); signal?.removeEventListener('abort', abort); owned.delete(child); fn(value); };
    const kill = () => { try { child.kill(); } catch {} };
    const abort = () => { kill(); finish(reject, Object.assign(new Error('Cancelled.'), {cancelled: true})); };
    const timer = setTimeout(() => { kill(); finish(reject, Object.assign(new Error(`${child.dkTool} did not finish within ${Math.round(timeoutMs / 1000)} s.`), {timeout: true})); }, timeoutMs);
    signal?.addEventListener('abort', abort, {once: true});
    const feed = (which, chunk) => {
      const text = chunk.toString('utf8');
      if (which === 'out') { if (out.length < maxOutput) out += text; } else if (err.length < maxOutput) err += text;
      if (onLine) { buf[which] += text; let i; while ((i = buf[which].indexOf('\n')) >= 0) { const line = buf[which].slice(0, i).replace(/\r$/, ''); buf[which] = buf[which].slice(i + 1); try { onLine(line, which); } catch {} } }
    };
    child.stdout.on('data', c => feed('out', c)); child.stderr.on('data', c => feed('err', c));
    child.on('error', e => finish(reject, e));
    child.on('close', code => finish(resolve, {code, stdout: out, stderr: err}));
    if (input !== undefined) child.stdin.end(typeof input === 'string' ? input : JSON.stringify(input)); else child.stdin.end();
  });
}
export function killOwned() { for (const c of owned) { try { c.kill(); } catch {} } owned.clear(); }

const outside = new Map();
shellEvents.on('proc.line', m => outside.get(m.proc)?.emit('line', m.line));
shellEvents.on('proc.eof', m => outside.get(m.proc)?.emit('eof'));
shellEvents.on('proc.exit', m => { const h = outside.get(m.proc); if (h) { h.exited = true; h.emit('exit'); outside.delete(m.proc); } });

/** Start a process outside the preview's job (survives the window by design). Output goes to files. */
export async function spawnOutside({exe, args = [], cwd, env = {}, stdout, stderr, stdinPipe = false, stdoutPipe = false, window = false}) {
  for (const f of [stdout, stderr]) if (f) writable(f);
  if (hasShell()) {
    const r = await request('spawn', {exe, args, cwd, env, stdout, stderr, stdinPipe, stdoutPipe, window});
    const h = new EventEmitter(); Object.assign(h, {pid: r.pid, proc: r.proc, breakaway: r.breakaway, exited: false});
    h.write = line => request('proc.write', {proc: r.proc, line});
    h.closeStdin = () => request('proc.closeStdin', {proc: r.proc});
    outside.set(r.proc, h); return h;
  }
  // Headless fallback (tests without a window): detached child with file handles, still never inside Main.
  const fds = [stdinPipe ? 'pipe' : 'ignore', stdoutPipe ? 'pipe' : (stdout ? fs.openSync(stdout, 'a') : 'ignore'), stderr ? fs.openSync(stderr, 'a') : 'ignore'];
  const child = spawn(exe, args, {cwd, env: cleanEnv(env), detached: true, windowsHide: !window, stdio: fds});
  for (const fd of fds) if (typeof fd === 'number') fs.closeSync(fd);
  const h = new EventEmitter(); Object.assign(h, {pid: child.pid, proc: 'local-' + child.pid, breakaway: false, exited: false, headless: true});
  h.write = async line => { child.stdin.write(line + '\n'); };
  h.closeStdin = async () => { child.stdin?.end(); };
  if (stdoutPipe) { let b = ''; child.stdout.on('data', c => { b += c; let i; while ((i = b.indexOf('\n')) >= 0) { h.emit('line', b.slice(0, i).replace(/\r$/, '')); b = b.slice(i + 1); } }); child.stdout.on('end', () => h.emit('eof')); }
  child.on('exit', () => { h.exited = true; h.emit('exit'); });
  child.unref(); return h;
}
export function alive(pid) { if (!Number.isSafeInteger(pid) || pid < 1) return false; try { process.kill(pid, 0); return true; } catch (e) { return e.code === 'EPERM'; } }
export function tail(text, n = 4000) { return clip(String(text).slice(-n), n); }
