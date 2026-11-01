import fs from 'node:fs';
import path from 'node:path';
import { createHash } from 'node:crypto';
export function engineIdentity(engine) {
  const canonical = fs.realpathSync.native(engine);
  return createHash('sha256').update(process.platform === 'win32' ? canonical.toLowerCase() : canonical).digest('hex');
}
// Prepared asset generations can stay unchanged while gameplay code is updated.
// Compare executable source separately so Start never reuses an older server.
export function runtimeVersion(engine) {
  const hash = createHash('sha256');
  const files = [];
  const walk = relative => {
    const directory = path.join(engine, relative);
    if (!fs.existsSync(directory)) return;
    for (const entry of fs.readdirSync(directory, { withFileTypes: true })) {
      if (entry.name.startsWith('.') || ['node_modules', 'runtime'].includes(entry.name)) continue;
      const name = `${relative}/${entry.name}`;
      if (entry.isSymbolicLink()) throw new Error('Runtime source must not contain linked files.');
      if (entry.isDirectory()) walk(name);
      else if (entry.isFile() && /\.(?:m?js|css)$/i.test(entry.name)) files.push(name);
    }
  };
  walk('src'); walk('server');
  for (const entry of ['server.mjs', 'package.json']) if (fs.existsSync(path.join(engine, entry))) files.push(entry);
  for (const name of files.sort()) hash.update(name).update('\0').update(fs.readFileSync(path.join(engine, name))).update('\0');
  return hash.digest('hex');
}
export function clientStatus(engine, version, pid = process.pid) {
  return { app: 'dekaron-engine', engineId: engineIdentity(engine), version, runtimeVersion: runtimeVersion(engine), pid };
}
export function accountCookieName(engine, accountStore) {
  let canonical;
  try { canonical = fs.realpathSync.native(accountStore); }
  catch (error) { if (error.code !== 'ENOENT') throw error; canonical = path.resolve(accountStore); }
  if (process.platform === 'win32') canonical = canonical.toLowerCase();
  return `dekaron_session_${createHash('sha256').update(engineIdentity(engine) + '\0' + canonical).digest('hex').slice(0,24)}`;
}
export function handleClientStatus(req, res, status) {
  if (req.method !== 'GET') { res.writeHead(405, { Allow: 'GET', 'Cache-Control': 'no-store' }); res.end(); return; }
  res.writeHead(200, { 'Content-Type': 'application/json; charset=utf-8', 'Cache-Control': 'no-store' });
  res.end(JSON.stringify(status));
}
