import fs from 'node:fs';
import fsp from 'node:fs/promises';
import path from 'node:path';
import os from 'node:os';
import {randomBytes} from 'node:crypto';
import {writable, PREVIEW, MAIN, ENGINE, INSTALL} from './paths.mjs';

export const sleep = ms => new Promise(r => setTimeout(r, ms));
export const now = () => Date.now();
export class UserError extends Error { constructor(message, code = 400, extra = {}) { super(message); this.status = code; Object.assign(this, extra); } }

export async function readJson(file, fallback = null, maxBytes = 8 * 1024 * 1024) {
  try { const st = await fsp.stat(file); if (st.size > maxBytes) throw new UserError('File too large: ' + path.basename(file)); return JSON.parse((await fsp.readFile(file, 'utf8')).replace(/^﻿/, '')); }
  catch (e) { if (e.code === 'ENOENT') return fallback; throw e; }
}
/** Atomic write to a writable() location only, no BOM. */
export async function writeJson(file, value) {
  writable(file); await fsp.mkdir(path.dirname(file), {recursive: true});
  const temp = file + '.' + randomBytes(6).toString('hex') + '.tmp';
  try { await fsp.writeFile(temp, JSON.stringify(value, null, 2) + '\n', {flag: 'wx'}); await fsp.rename(temp, file); }
  finally { await fsp.rm(temp, {force: true}).catch(() => {}); }
}
export async function writeText(file, text) {
  writable(file); await fsp.mkdir(path.dirname(file), {recursive: true});
  const temp = file + '.' + randomBytes(6).toString('hex') + '.tmp';
  try { await fsp.writeFile(temp, text, {flag: 'wx'}); await fsp.rename(temp, file); } finally { await fsp.rm(temp, {force: true}).catch(() => {}); }
}
export async function readText(file, fallback = null) { try { return (await fsp.readFile(file, 'utf8')).replace(/^﻿/, ''); } catch (e) { if (e.code === 'ENOENT') return fallback; throw e; } }

const HOME = os.homedir();
const ROOT_LABELS = INSTALL ? [[ENGINE, '<engine>'], [HOME, '<home>'], [os.tmpdir(), '<temp>']] : [[ENGINE, '<sandbox-engine>'], [PREVIEW, '<preview>'], [MAIN, '<main>'], [HOME, '<home>'], [os.tmpdir(), '<temp>']];
/** Support-safe text: no home paths, user names, tokens, passwords, cookies or tickets. */
export function redact(text) {
  let s = String(text ?? '');
  for (const [root, label] of ROOT_LABELS)
    s = s.split(root).join(label).split(root.replaceAll('\\', '/')).join(label);
  s = s.replace(/([A-Z]:[\\/]Users[\\/])[^\\/\r\n"]+/gi, '$1<user>');
  s = s.replace(/((?:token|password|secret|pwd|cookie|ticket|invite|publicationSecret)["']?\s*[=:]\s*["']?)[^\s,;"'&]+/gi, '$1<redacted>');
  s = s.replace(/#ticket=[a-f0-9]{64}/gi, '#ticket=<redacted>').replace(/\b[a-f0-9]{64}\b/g, m => m.slice(0, 6) + '…');
  return s;
}
export function clip(s, n = 400) { s = String(s ?? ''); return s.length > n ? s.slice(0, n) + '…' : s; }
export function isPortFree(port, host = '127.0.0.1') {
  return new Promise(resolve => {
    import('node:net').then(({default: net}) => {
      const srv = net.createServer(); srv.unref();
      srv.once('error', () => resolve(false));
      srv.listen({port, host, exclusive: true}, () => srv.close(() => resolve(true)));
    });
  });
}
export async function fetchJson(url, {method = 'GET', headers = {}, body, timeoutMs = 5000, signal, redirect = 'manual'} = {}) {
  const ctrl = new AbortController(); const t = setTimeout(() => ctrl.abort(new Error('timeout')), timeoutMs);
  const onAbort = () => ctrl.abort(signal.reason); signal?.addEventListener('abort', onAbort, {once: true});
  const started = performance.now();
  try {
    const res = await fetch(url, {method, headers: {...(body !== undefined ? {'Content-Type': 'application/json; charset=utf-8'} : {}), ...headers}, body: body === undefined ? undefined : JSON.stringify(body), redirect, signal: ctrl.signal});
    const text = await res.text(); let data = null; try { data = text ? JSON.parse(text) : null; } catch { data = {raw: clip(text, 200)}; }
    return {ok: res.ok, status: res.status, data, ms: Math.round((performance.now() - started) * 10) / 10, headers: res.headers};
  } catch (e) {
    const timeout = ctrl.signal.aborted && !signal?.aborted;
    return {ok: false, status: 0, data: null, error: timeout ? 'timeout' : (signal?.aborted ? 'cancelled' : (e.cause?.code || e.message)), ms: Math.round((performance.now() - started) * 10) / 10};
  } finally { clearTimeout(t); signal?.removeEventListener('abort', onAbort); }
}
export function exists(p) { try { fs.accessSync(p); return true; } catch { return false; } }
