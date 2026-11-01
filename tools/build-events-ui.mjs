#!/usr/bin/env node
// Builds gamedata/events_effectui.json: the full-screen UI effect banners (`@<effectui>id,a,ms,b` of the event and
// dungeon message strings) = effect scenes of <cate> 8 UI in property/effect/effectscene.{01,02,03,com,map}.txt with
// their units from effectdata.*.txt (sprites / particles: texture, size, blend) and the control timelines
// (lifetime, scale / alpha / rotation / position keyframes, 0..999 per control lifetime). Texture keys are verified on
// disk and carry the DDS width / height (the banner renderer keeps the texture aspect).
//   node tools/build-events-ui.mjs [--data <unpacked data root>] [--out <dir>]
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { parseEffectScenes, parseEffectData, describeControl, describeUnit } from './build-skills.mjs';

const here = path.dirname(fileURLToPath(import.meta.url));
const args = process.argv.slice(2);
const arg = (k, d) => { const i = args.indexOf(k); return i >= 0 ? args[i + 1] : d; };
const DATA = path.resolve(arg('--data', path.join(here, '..', '..', 'data', 'unpacked', 'data')));
const OUT = path.resolve(arg('--out', path.join(here, '..', 'gamedata')));
const FILES = ['01', '02', '03', 'com', 'map'];

const norm = p => String(p || '').trim().replace(/\\/g, '/').replace(/^\/+/, '').toLowerCase();
const exists = k => { try { return fs.statSync(path.join(DATA, k)).isFile(); } catch { return false; } };
function ddsSize(k) {
  try {
    const fd = fs.openSync(path.join(DATA, k), 'r');
    const b = Buffer.alloc(24); fs.readSync(fd, b, 0, 24, 0); fs.closeSync(fd);
    if (b.toString('latin1', 0, 4) !== 'DDS ') return null;
    return [b.readUInt32LE(16), b.readUInt32LE(12)];
  } catch { return null; }
}

// 1) referenced ids
const ids = new Set();
const evText = JSON.parse(fs.readFileSync(path.join(OUT, 'events_text.json'), 'utf8'));
for (const tab of Object.values(evText.tables || {})) for (const cate of Object.values(tab)) for (const s of Object.values(cate)) for (const e of s.effectUi || []) ids.add(Number(e.id));
try {
  const dg = JSON.parse(fs.readFileSync(path.join(OUT, 'dungeons.json'), 'utf8'));
  for (const m of Object.values(dg.maps || {})) for (const msg of Object.values(m.messages || {})) for (const f of msg.fx || []) if (f.ui) ids.add(Number(f.ui));
} catch { /* optional */ }

// 2) scenes (cate 8) + units
const scenes = new Map();
const units = new Map();
for (const f of FILES) {
  const sp = path.join(DATA, 'property', 'effect', `effectscene.${f}.txt`);
  const dp = path.join(DATA, 'property', 'effect', `effectdata.${f}.txt`);
  if (fs.existsSync(sp)) for (const e of parseEffectScenes(fs.readFileSync(sp), f)) if (e.cate === 8 && !scenes.has(e.id)) scenes.set(e.id, e);
  if (fs.existsSync(dp)) for (const u of parseEffectData(fs.readFileSync(dp), f)) { const k = u.name.toLowerCase(); if (!units.has(k)) units.set(k, u); }
}

const res = {
  texture(file) {
    const k = norm(`texture/${file}`);
    if (exists(k)) return k;
    const alt = [k.replace(/\.(tga|bmp|png)$/, '.dds'), norm(file)];
    return alt.find(exists) || null;
  },
  tpack(file) { const k = norm(`texturepack/${file}`); return exists(k) ? { key: k, frames: [] } : null; },
  path(kind, file) { const k = norm(`${kind}/${file}`); return exists(k) ? k : null; },
  sound() { return null; },
};

const out = { format: 'dekaron-solo/events-effectui@1', generatedBy: 'tools/build-events-ui.mjs', note: 'effectscene cate 8 UI effects: scenes[].controls keyframe times 0..999 over the control lifetime (ms); units[slot] sprite/particle texture (+ [w,h]); the caller stretches the scene timeline to the ms of @<effectui>id,a,ms,b', effects: {}, missing: [] };
for (const id of [...ids].sort((a, b) => a - b)) {
  const e = scenes.get(id);
  if (!e) { out.missing.push(id); continue; }
  const uOut = {};
  for (const [slot, name] of Object.entries(e.res)) {
    const u = units.get(String(name).toLowerCase());
    if (!u) { uOut[slot] = { name, missing: true }; continue; }
    const d = describeUnit(u, res);
    const o = { name, type: d.type, size: d.size ?? 1, blend: d.blend || 'modulate' };
    if (d.billboard) o.billboard = d.billboard;
    if (d.texture) { o.texture = d.texture; const s = ddsSize(d.texture); if (s) o.tex = s; }
    if (d.emitter) o.emitter = { state: d.emitter.state, lifetimeMs: d.emitter.lifetimeMs, max: d.emitter.max, rate: d.emitter.rate, particleSize: d.emitter.particleSize, startRange: d.emitter.startRange };
    uOut[slot] = o;
  }
  out.effects[id] = {
    name: e.name, file: e.file, units: uOut,
    scenes: e.scenes.map(s => ({ id: s.sceneId, name: s.name, controls: s.controls.map(describeControl) })),
  };
}
fs.writeFileSync(path.join(OUT, 'events_effectui.json'), JSON.stringify(out));
console.log(`events_effectui.json: ${Object.keys(out.effects).length} effects, ${out.missing.length} missing ids (${out.missing.slice(0, 20).join(', ')})`);
