// Structured JSON-lines logger. Console sink always on; file sink opt-in (file option or DEKARON_LOG_FILE).
import fs from 'node:fs';
import { pipelineClient } from './pipeline/client.mjs'; // PIPELINE-SPLIT
export const LEVELS = Object.freeze({ debug: 10, info: 20, warn: 30, error: 40 });
const CONSOLE = { debug: 'debug', info: 'log', warn: 'warn', error: 'error' };
export function formatRecord(level, msg, context, fields, now = new Date()) {
  const rec = { ts: now.toISOString(), level, msg: String(msg), ...context, ...fields };
  for (const [k, v] of Object.entries(rec)) if (v instanceof Error) rec[k] = { name: v.name, message: v.message, stack: v.stack };
  return JSON.stringify(rec);
}
export function createLogger({ level = process.env.DEKARON_LOG_LEVEL || 'info', context = {}, file = process.env.DEKARON_LOG_FILE || null, console: out = globalThis.console, clock = () => new Date() } = {}) {
  if (!(level in LEVELS)) throw new Error(`Unknown log level: ${level}`);
  const min = LEVELS[level];
  const sinks = [(lvl, line) => out[CONSOLE[lvl]](line)];
  const pc = pipelineClient(); // PIPELINE-SPLIT: under ServerOn every line also goes to the LogFiles service (bus BULK lane, async)
  if (pc) sinks.push((_, line) => pc.log(line));
  if (file) sinks.push((_, line) => fs.appendFileSync(file, line + '\n'));
  const make = ctx => {
    const log = {};
    for (const lvl of Object.keys(LEVELS)) log[lvl] = (msg, fields = {}) => {
      if (LEVELS[lvl] < min) return false;
      const line = formatRecord(lvl, msg, ctx, fields, clock());
      for (const s of sinks) s(lvl, line);
      return true;
    };
    log.child = extra => make({ ...ctx, ...extra });
    log.level = level;
    return log;
  };
  return make({ ...context });
}
