// serveroff: saves every character and stops the world through its private launcher control (same path DK Command Center uses).
// Realm exits after the save; ServerOn then stops Gate, Archive and Monitor by itself. Never kills a process.
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
const ENGINE = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..', '..');
const PORT = Number(process.argv[2] || process.env.PORT || 7777);
const file = path.join(ENGINE, 'server', `launcher-control-${PORT}.json`);
let control; try { control = JSON.parse(fs.readFileSync(file, 'utf8')); } catch { console.log(`No running world on port ${PORT} (no ${path.basename(file)}).`); process.exit(0); }
const url = new URL('api/launcher/stop', control.controlUrl.replace('localhost', '127.0.0.1'));
const r = await fetch(url, { method: 'POST', headers: { 'content-type': 'application/json', 'x-dekaron-launcher-token': control.token }, body: '{}' }).catch(e => ({ ok: false, statusText: e.message }));
const body = r.json ? await r.json().catch(() => ({})) : {};
if (!r.ok || !body.stopped) { console.error('World did not stop: ' + (body.error || r.statusText || r.status)); process.exit(1); }
console.log(`World saved (${body.saved ? 'all characters saved' : 'save not confirmed'}) and stopping; services follow it down.`);
const until = Date.now() + 15000; const alive = pid => { try { process.kill(pid, 0); return true; } catch (e) { return e.code === 'EPERM'; } };
while (alive(control.pid) && Date.now() < until) await new Promise(r => setTimeout(r, 200));
console.log(alive(control.pid) ? 'Still exiting.' : 'Stopped.');
