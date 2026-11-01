#!/usr/bin/env node
// share/server lists -> gamedata/server-lists.json (FEATURE-CENSUS D11). The gradelist PW column is never written.
import fs from 'node:fs'; import path from 'node:path'; import { pathToFileURL } from 'node:url';
import { SERVER_LISTS } from '../src/formats/server-lists.js';
export function buildServerLists(dataRoot) {
  const out = { version: 1, source: 'share/server', lists: {}, missing: [] };
  for (const [name, parse] of Object.entries(SERVER_LISTS)) {
    const file = path.join(dataRoot, 'share/server', name + '.csv');
    if (!fs.existsSync(file)) { out.missing.push(name); continue; }
    out.lists[name] = parse(fs.readFileSync(file));
  }
  return out;
}
const arg = (k, d) => { const i = process.argv.indexOf(k); return i > 0 ? process.argv[i + 1] : d; };
if (process.argv[1] && import.meta.url === pathToFileURL(process.argv[1]).href) {
  const data = arg('--data', process.env.DEKARON_DATA), out = arg('--out', process.env.DEKARON_GAMEDATA);
  if (!data || !out) { console.error('usage: build-server-lists.mjs --data <root> --out <gamedata dir>'); process.exit(2); }
  const r = buildServerLists(data); fs.mkdirSync(out, { recursive: true }); fs.writeFileSync(path.join(out, 'server-lists.json'), JSON.stringify(r));
  console.log(`server-lists: ${Object.keys(r.lists).join(', ')}${r.missing.length ? '; missing ' + r.missing.join(', ') : ''}`);
}
