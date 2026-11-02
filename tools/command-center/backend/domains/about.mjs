// Settings & About: versions, documentation, licenses, contributors, app summary.
import fs from 'node:fs';
import fsp from 'node:fs/promises';
import path from 'node:path';
import {ENGINE, MAIN, PREVIEW, WORLD_PORT, INSTALL, APP} from '../core/paths.mjs';
import {define, v} from '../core/rpc.mjs';
import {readText, readJson, redact} from '../core/util.mjs';
import {shellInfo, hasShell} from '../core/shell.mjs';

export const CONTRIBUTORS = ['DEV ShadoW', 'CYBER', 'Magic Ibrar'];
const version = dir => { try { return JSON.parse(fs.readFileSync(path.join(dir, 'package.json'), 'utf8')).version; } catch { return null; } };
async function docs() {
  const out = [];
  for (const n of (await fsp.readdir(path.join(ENGINE, 'docs')).catch(() => [])).sort()) if (/^[A-Z0-9.-]+\.md$/i.test(n)) out.push({name: n, title: n.replace(/\.md$/, '').replace(/-/g, ' ')});
  out.push({name: 'START-HERE.txt', title: 'Start here'}, {name: 'THIRD_PARTY_NOTICES.md', title: 'Third-party notices'});
  return out;
}
define('about.info', {input: v.object({}), run: async () => ({
  ...(INSTALL
    ? {product: 'DK Command Center', edition: null, appVersion: version(ENGINE), identity: 'DK.CommandCenter', engineVersion: version(ENGINE), installedVersion: null, published: null, sandbox: null, install: {engine: redact(ENGINE), app: path.relative(ENGINE, APP).replaceAll('\\', '/'), worldPort: WORLD_PORT}}
    : {product: 'DK Command Center', edition: 'Test Preview', previewVersion: '0.9.0', identity: 'DK.CommandCenter.TestPreview (separate from DK.Engine.Launcher)', engineVersion: version(ENGINE), installedVersion: version(MAIN), published: '4.0.1', sandbox: {engine: path.relative(PREVIEW, ENGINE), worldPort: WORLD_PORT}, install: null}),
  node: process.version, webview2: shellInfo().webview2 || null, window: hasShell(), contributors: CONTRIBUTORS, docs: await docs(),
  licenses: [{name: 'Three.js 0.170.0', license: 'MIT', file: 'node_modules/three/LICENSE'}, {name: 'Node.js 24 runtime', license: 'MIT and bundled dependency licenses', file: 'runtime/LICENSE'}, {name: 'qrcodegen (Project Nayuki)', license: 'MIT', file: 'tools/vendor/qrcodegen.mjs'}, {name: 'Microsoft Edge WebView2 Runtime', license: 'Microsoft software license (installed with Windows)', file: null}, {name: 'Engine code', license: 'No project-wide open-source license selected (see THIRD_PARTY_NOTICES.md)', file: 'THIRD_PARTY_NOTICES.md'}],
})});
define('about.doc', {input: v.object({name: v.string({max: 80, pattern: /^[A-Za-z0-9._-]+$/})}), run: async ({name}) => {
  const allowed = (await docs()).map(d => d.name); if (!allowed.includes(name)) throw Object.assign(new Error('Unknown document.'), {status: 404});
  const file = ['START-HERE.txt', 'THIRD_PARTY_NOTICES.md'].includes(name) ? path.join(ENGINE, name) : path.join(ENGINE, 'docs', name);
  return {name, text: (await readText(file, '')).slice(0, 200000)};
}});
