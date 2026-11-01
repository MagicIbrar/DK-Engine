// Builds gamedata/dungeons_uifx.json: every UI effect scene (<cate> 8 of property/effect/effectscene.*.txt) plus
// the effectdata units they use. The dungeon system plays them as full-screen UI flashes (message fx
// "@<effectui>2082,1,7000,1": docs/formats/dungeons.md). Grammar: docs/formats/effects.md §3/§4.
//   node tools/build-dungeon-uifx.mjs
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const HERE = path.dirname(fileURLToPath(import.meta.url));
const ENGINE = path.resolve(HERE, '..');
const DATA = process.env.DEKARON_DATA || path.resolve(ENGINE, '../data/unpacked/data');
const GD = process.env.DEKARON_GAMEDATA || path.join(ENGINE, 'gamedata');
const FX = path.join(DATA, 'property/effect');
const ORDER = ['01', '02', '03', 'com', 'map'];   // first file wins (effects.md §2)

const lines = (f) => fs.readFileSync(f, 'latin1').split(/\r?\n/);
const num = (v) => { const x = Number(v); return Number.isFinite(x) ? x : null; };

/** '(0,1,1,1) (999,4,4,4)' or '(0 7 7 7)(999 1 1 1)' -> [[t, v...], ...] */
function keys(v) {
  const out = [];
  for (const m of String(v).matchAll(/\(([^)]*)\)/g)) {
    const n = m[1].split(/[\s,]+/).filter(Boolean).map(Number).filter(Number.isFinite);
    if (n.length) out.push(n);
  }
  return out;
}

function parseScenes(file, effects) {
  let cate = null, eff = null, scene = null, ctl = null, inList = false;
  for (const raw of lines(file)) {
    const s = raw.trim();
    if (!s || s.startsWith('#')) continue;
    let m;
    if ((m = /^<cate>\s+(\d+)/i.exec(s))) { cate = Number(m[1]); continue; }
    if (/^<\/cate>/i.test(s)) { cate = null; continue; }
    if (cate !== 8) continue;
    if (/^<effect>/i.test(s)) { eff = { id: null, name: '', res: {}, scenes: [] }; continue; }
    if (/^<\/effect>/i.test(s)) { if (eff?.id != null && !effects[eff.id]) effects[eff.id] = eff; eff = null; continue; }
    if (!eff) continue;
    if (/^<list>/i.test(s)) { inList = true; continue; }
    if (/^<\/list>/i.test(s)) { inList = false; continue; }
    if (inList) { if ((m = /^res\s+(\d+)\s+(\S+)/i.exec(s))) eff.res[m[1]] = m[2]; continue; }
    if (/^<scene>/i.test(s)) { scene = { id: 1, name: '', controls: [] }; continue; }
    if (/^<\/scene>/i.test(s)) { if (scene) eff.scenes.push(scene); scene = null; continue; }
    if (/^<control>/i.test(s)) { ctl = {}; continue; }
    if (/^<\/control>/i.test(s)) { if (scene && ctl && ctl.active !== false) scene.controls.push(ctl); ctl = null; continue; }
    const kv = /^(\S+)\s+(.*)$/.exec(s);
    if (!kv) continue;
    const [, k, v] = kv;
    if (ctl) {
      switch (k.toLowerCase()) {
        case 'unitid': ctl.unit = num(v); break;
        case 'active': ctl.active = !/^false/i.test(v); break;
        case 'startposition': ctl.pos = v.trim().split(/\s+/).map(Number); break;
        case 'lifetime': ctl.life = v.trim().split(/\s+/).map(Number); break;
        case 'animtime': ctl.animtime = num(v); break;
        case 'scale': ctl.scale = keys(v); break;
        case 'alpha': ctl.alpha = keys(v); break;
        case 'color': ctl.color = keys(v); break;
        case 'rotation': ctl.rotation = keys(v); break;
        case 'position': ctl.position = keys(v); break;
        case 'follow': ctl.follow = !/^false/i.test(v); break;
        case 'randomstart': ctl.randomstart = /^true/i.test(v); break;
        default: break;
      }
    } else if (scene) {
      if (/^sceneid$/i.test(k)) scene.id = num(v); else if (/^name$/i.test(k)) scene.name = v.trim();
    } else if (/^id$/i.test(k) && eff.id == null) eff.id = num(v);
    else if (/^name$/i.test(k)) eff.name = v.trim();
  }
}

function parseUnits(file, want, units) {
  let u = null;
  for (const raw of lines(file)) {
    const s = raw.trim();
    if (!s || s.startsWith('#')) continue;
    if (/^<effectdata>/i.test(s)) { u = {}; continue; }
    if (/^<\/effectdata>/i.test(s)) {
      const key = String(u?.name || '').toLowerCase();
      if (key && want.has(key) && !units[key]) units[key] = u;
      u = null; continue;
    }
    if (!u) continue;
    const kv = /^(\S+)\s+(.*)$/.exec(s);
    if (!kv) continue;
    const k = kv[1].toLowerCase(), v = kv[2].trim();
    switch (k) {
      case 'name': u.name = v; break;
      case 'unittype': u.type = v.toLowerCase(); break;
      case 'size': u.size = num(v); break;
      case 'texturefile': u.tex = v ? `texture/${v.replace(/\\/g, '/')}`.toLowerCase() : ''; break;
      case 'texturepack': u.tpack = v ? v.replace(/\\/g, '/').toLowerCase() : ''; break;
      case 'blendtype': u.blend = v.toLowerCase(); break;
      case 'textureloop': u.loop = v.toLowerCase(); break;
      case 'texanimtime': u.texanim = num(v); break;
      case 'billboardtype': u.billboard = v.toLowerCase(); break;
      case 'lifetime': u.plife = v.split(/\s+/).map(Number); break;
      case 'emitrate': u.emitrate = num(v); break;
      case 'maxelementcount': u.max = num(v); break;
      case 'velocity': u.velocity = v.split(/\s+/).map(Number); break;
      case 'gravity': u.gravity = v.split(/\s+/).map(Number); break;
      case 'particlesize': u.psize = v.split(/\s+/).map(Number); break;
      case 'startrange': u.startrange = v.split(/\s+/).map(Number); break;
      case 'spawndirection': u.spawndir = v.split(/\s+/).map(Number); break;
      case 'addrotate': u.addrotate = num(v); break;
      case 'colorrange': u.colorrange = num(v); break;
      case 'mesh': case 'meshfile': u.mesh = v; break;
      default: break;
    }
  }
}

const effects = {};
for (const f of ORDER) {
  const p = path.join(FX, `effectscene.${f}.txt`);
  if (fs.existsSync(p)) parseScenes(p, effects);
}
const want = new Set();
for (const e of Object.values(effects)) for (const n of Object.values(e.res)) want.add(String(n).toLowerCase());
const units = {};
for (const f of ORDER) {
  const p = path.join(FX, `effectdata.${f}.txt`);
  if (fs.existsSync(p)) parseUnits(p, want, units);
}
let texMissing = 0;
for (const u of Object.values(units)) {
  if (u.tex && !fs.existsSync(path.join(DATA, u.tex))) { u.texMissing = 1; texMissing++; }
}
const out = {
  format: 'dekaron-solo/uifx@1', generatedBy: 'tools/build-dungeon-uifx.mjs', doc: 'docs/formats/effects.md (cate 8 UI)',
  note: 'UI effect scenes: 1 unit = 64 reference px (1024-wide text strips are authored at scale 16); x right, y up; lifetime/keys 0..1000 of the scene/control time',
  effects, units,
  report: { effects: Object.keys(effects).length, units: Object.keys(units).length, unitsMissing: [...want].filter(n => !units[n]), texMissing },
};
fs.writeFileSync(path.join(GD, 'dungeons_uifx.json'), JSON.stringify(out));
console.log(`uifx: ${out.report.effects} effects, ${out.report.units} units, ${out.report.unitsMissing.length} units missing, ${texMissing} textures missing`);
