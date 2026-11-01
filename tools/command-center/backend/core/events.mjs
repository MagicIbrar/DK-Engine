// Timeline of what the preview actually did and observed. Bounded in memory and on disk; text is redacted on write.
import fs from 'node:fs';
import path from 'node:path';
import {LOGS} from './paths.mjs';
import {redact, clip} from './util.mjs';

const FILE = path.join(LOGS, 'timeline.jsonl');
const MAX = 2000, ring = [];
let seq = 0;
try {
  const lines = fs.readFileSync(FILE, 'utf8').trim().split(/\r?\n/).slice(-400);
  for (const l of lines) { try { const e = JSON.parse(l); ring.push(e); seq = Math.max(seq, e.seq || 0); } catch {} }
  if (fs.statSync(FILE).size > 2 * 1024 * 1024) fs.writeFileSync(FILE, ring.map(e => JSON.stringify(e)).join('\n') + '\n');
} catch {}

/** level: info | ok | warn | error ; area: world | play | host | sql | content | update | diag | app */
export function event(level, area, message, detail) {
  const e = {seq: ++seq, at: new Date().toISOString(), level, area, message: clip(redact(message), 300), ...(detail !== undefined ? {detail: clip(redact(typeof detail === 'string' ? detail : JSON.stringify(detail)), 2000)} : {})};
  ring.push(e); if (ring.length > MAX) ring.splice(0, ring.length - MAX);
  try { fs.appendFileSync(FILE, JSON.stringify(e) + '\n'); } catch {}
  return e;
}
export function events({after = 0, limit = 200, area, level} = {}) {
  return ring.filter(e => e.seq > after && (!area || e.area === area) && (!level || e.level === level)).slice(-limit);
}
export function lastSeq() { return seq; }
