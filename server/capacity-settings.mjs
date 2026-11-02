// The installation owner's capacity settings, saved beside the server (server/capacity.json, never shipped):
//   maxPlayers   player cap of this server (the owner / GM accounts can always join their own world)
//   memoryMB     the server's memory limit (Node heap, --max-old-space-size); the launcher applies it when it STARTS the
//                server - the running process reports the limit it really has (runtimeMemory), so the dashboard shows it
//   uploadMbps   the host's upload speed (internet test or typed in); 0 = not set (no bandwidth limit)
//   uploadShare  the share of that upload the game may use (the rest of the network stays free)
// Ranges / defaults are ENGINE-CHOSEN (no original server setting exists).
import fs from 'node:fs/promises';
import os from 'node:os';
import path from 'node:path';
import v8 from 'node:v8';
import {randomBytes} from 'node:crypto';

export const CAPACITY_DEFAULTS = Object.freeze({ maxPlayers: 100, memoryMB: 0, uploadMbps: 0, uploadShare: 0.7 });
export const CAPACITY_RANGE = Object.freeze({ maxPlayers: [1, 500], uploadMbps: [0, 10000], uploadShare: [0.1, 0.95] });
const STEP = 256;

/** Memory slider range for this machine: 1 GB .. 75% of the RAM (the rest stays for Windows and the game client), recommended 1/4 of the RAM within 2-16 GB. */
export function memoryRange(totalBytes = os.totalmem()) {
  const totalMB = Math.floor(totalBytes / 1048576), max = Math.max(1024, Math.floor(totalMB * 0.75 / STEP) * STEP);
  const recommended = Math.min(max, Math.max(2048, Math.min(16384, Math.round(totalMB / 4 / STEP) * STEP)));
  return { min: 1024, max, step: STEP, recommended, totalMB };
}

/** Validate an owner input; returns the full normalized settings or throws a readable message. memoryMB 0 = automatic (Node's own limit). */
export function normalizeCapacity(input, { totalBytes = os.totalmem(), base = CAPACITY_DEFAULTS } = {}) {
  if (!input || typeof input !== 'object' || Array.isArray(input)) throw new Error('Expected capacity settings.');
  const allowed = Object.keys(CAPACITY_DEFAULTS), extra = Object.keys(input).filter(k => !allowed.includes(k));
  if (extra.length) throw new Error('Unknown capacity setting: ' + extra[0]);
  const out = { ...CAPACITY_DEFAULTS, ...base };
  const number = (key, value) => { const n = Number(value); if (typeof value === 'boolean' || value === null || value === '' || !Number.isFinite(n)) throw new Error(`${key} must be a number.`); return n; };
  if (input.maxPlayers !== undefined) { const n = number('maxPlayers', input.maxPlayers); if (!Number.isInteger(n) || n < CAPACITY_RANGE.maxPlayers[0] || n > CAPACITY_RANGE.maxPlayers[1]) throw new Error('Max players must be a whole number from 1 to 500.'); out.maxPlayers = n; }
  if (input.uploadMbps !== undefined) { const n = number('uploadMbps', input.uploadMbps); if (n < 0 || n > CAPACITY_RANGE.uploadMbps[1]) throw new Error('Upload speed must be 0 (not set) to 10000 Mbps.'); out.uploadMbps = Math.round(n * 10) / 10; }
  if (input.uploadShare !== undefined) { const n = number('uploadShare', input.uploadShare); if (n < CAPACITY_RANGE.uploadShare[0] || n > CAPACITY_RANGE.uploadShare[1]) throw new Error('The game may use 10% to 95% of the upload.'); out.uploadShare = Math.round(n * 100) / 100; }
  if (input.memoryMB !== undefined) {
    const n = number('memoryMB', input.memoryMB), range = memoryRange(totalBytes);
    if (n !== 0 && (!Number.isInteger(n) || n < range.min || n > range.max)) throw new Error(`Server memory must be automatic or ${range.min}-${range.max} MB on this PC.`);
    out.memoryMB = n === 0 ? 0 : Math.round(n / STEP) * STEP;
  }
  return out;
}

export function capacityFile(engine) { return path.join(engine, 'server', 'capacity.json'); }

/** Saved settings (defaults when missing or unreadable), then DEKARON_MAX_PLAYERS / DEKARON_UPLOAD_MBPS / DEKARON_UPLOAD_SHARE overrides. */
export async function readCapacitySettings(file, { env = process.env, totalBytes = os.totalmem() } = {}) {
  let saved = {};
  try { saved = normalizeCapacity(JSON.parse(await fs.readFile(file, 'utf8')), { totalBytes }); }
  catch (error) { if (error.code !== 'ENOENT') console.warn('[capacity] settings unreadable; using defaults:', error.message); saved = { ...CAPACITY_DEFAULTS }; }
  const overrides = {};
  for (const [key, name] of [['maxPlayers', 'DEKARON_MAX_PLAYERS'], ['uploadMbps', 'DEKARON_UPLOAD_MBPS'], ['uploadShare', 'DEKARON_UPLOAD_SHARE']]) if (env[name] !== undefined && env[name] !== '') overrides[key] = Number(env[name]);
  try { return normalizeCapacity(overrides, { totalBytes, base: saved }); } catch (error) { console.warn('[capacity] environment override ignored:', error.message); return saved; }
}

/** Atomic save (temporary file + rename). */
export async function writeCapacitySettings(file, settings, { totalBytes = os.totalmem() } = {}) {
  const value = normalizeCapacity(settings, { totalBytes });
  await fs.mkdir(path.dirname(file), { recursive: true });
  const temporary = `${file}.${randomBytes(6).toString('hex')}.tmp`;
  try { await fs.writeFile(temporary, JSON.stringify(value, null, 2), { flag: 'wx' }); await fs.rename(temporary, file); }
  finally { await fs.rm(temporary, { force: true }).catch(() => {}); }
  return value;
}

/** What this running server process really has (the dashboard's proof that the memory setting applied). */
let cpuCount = null;   // STABILITY-PING: os.cpus() costs milliseconds on Windows and the count never changes; read it once
export function runtimeMemory() {
  const heap = v8.getHeapStatistics(), usage = process.memoryUsage();
  return { heapLimitMB: Math.round(heap.heap_size_limit / 1048576), heapUsedMB: Math.round(usage.heapUsed / 1048576), rssMB: Math.round(usage.rss / 1048576), totalMB: Math.floor(os.totalmem() / 1048576), cpus: cpuCount ??= os.cpus().length };
}

// LANE1-PERF: NPC backpressure budgets. Environment-only (NOT part of capacity.json
// or the dashboard schema, so normalizeCapacity is unchanged). Only consulted while
// bots are enabled; bots stay OFF by default.
//   DEKARON_NPC_BACKPRESSURE=0|1, DEKARON_NPC_BP_LOOP_P99_MS, DEKARON_NPC_BP_HUMAN_P95_MS
export function readNpcBackpressureSettings(env = process.env) {
  const out = { enabled: env.DEKARON_NPC_BACKPRESSURE !== '0' };
  const ms = (name, key, low, high) => { const raw = env[name]; if (raw === undefined || raw === '') return; const n = Number(raw); if (Number.isFinite(n) && n >= low && n <= high) out[key] = n; else console.warn(`[capacity] ${name} ignored (expected ${low}-${high}).`); };
  ms('DEKARON_NPC_BP_LOOP_P99_MS', 'eventLoopP99Ms', 5, 1000);
  ms('DEKARON_NPC_BP_HUMAN_P95_MS', 'humanP95Ms', 5, 5000);
  return out;
}
