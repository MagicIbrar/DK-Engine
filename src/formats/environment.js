// Dekaron per-map environment: day/night light keys, fog, sky, clouds, weather, bloom, water, camera.
//
// Sources (all text, latin1):
//   share/maplist.csv                 per map: EnvironmentFile, EnvironmentMap, OnedayTime(Min), Clip_Far, Camera_*, Reflect_Height,...
//   map/<EnvironmentFile>             e.g. map/light_braiken.txt — one <light>...</light> block per time-of-day key
//   texture/<EnvironmentMap>          e.g. texture/water/skycube=.dds — 768x128 strip: a cyclic 360-degree sky panorama cut into
//                                     6 slices (NOT a real cube; see skyStripToEquirect / SKYCUBE_FACE_ORDER)
//   script/environment/sky_table.txt  sky_type index -> sky dome texture, cloud texture, flare set
//   script/environment/sky.txt        lens-flare sets (<SKYEFFECT> timeofday N)
//   property/effect/water/*.txt       water surface materials (referenced by name from the .map file's water section)
//   property/map/*.txt                legacy per-map property file (only loa.txt exists)
// Pure functions: no three.js, no Node APIs. See docs/formats/environment.md.

import { parseCSV, decodeText } from './binreader.js';

const toText = (src) => (typeof src === 'string' ? src : decodeText(src instanceof ArrayBuffer ? new Uint8Array(src) : src));

/** Light-key time scale: one game day = 240000 units (10000 per game hour). */
export const DAY_UNITS = 240000;
export const UNITS_PER_HOUR = 10000;

const nums = (a) => a.map(Number);
function normalize3(v) {
  const l = Math.hypot(v[0], v[1], v[2]);
  return l > 1e-9 ? [v[0] / l, v[1] / l, v[2] / l] : [0, 1, 0];
}

/**
 * Parse a map light/environment file (map/light_*.txt).
 * @returns {{ keys: Array<object>, dayUnits:number }}
 * Each key:
 *   time (0..240000), hour (time/10000)
 *   lightDistance            'lightdistance'   (distance of the virtual sun from the focus point; shadow projection)
 *   ambient [r,g,b] 0..1     'ambient_color'
 *   sunColor [r,g,b]         'dirlight_color'
 *   sunDir [x,y,z]           'dirlight_dir'  normalised, FILE frame, points FROM the scene TOWARDS the light (y>0 = above)
 *   sunDirRaw                as written (some files are not normalised, e.g. 46.8 80.1 0)
 *   backColor/backDir        'dirbacklight_color'/'dirbacklight_dir' (optional 2nd directional light; [0,0,0] = off)
 *   fog {start, end, color}  'fog_value' start end (world units, same as positions), 'fog_color'
 *   weather {enabled, rate, scene, duration, raw}   'weather_value' a b c d:
 *        a 0/1 = weather on, b = rate/probability (100), c = scene id inside weather effect 100 (cate 10):
 *        1 rain, 2 snow, 3 sandstorm, 4 shower, 5 blossom, 6 festival_pollen; d = duration ms (100000)
 *   bloom {enabled, params:[p1..p4]}  'bloom_value' (p1..p4 kept raw: brightness/threshold-like values)
 *   sky {type, unk}          'sky_type' N [M]: N = row of script/environment/sky_table.txt; M raw (0/1, optional)
 *   cloud {raw:[5 numbers]}  'cloud_type' (a b c alpha(0..255) e) kept raw
 *   night boolean            'night'
 *   interior raw[4]|null     'interior' (last line seen while this key was open; kept raw for tools)
 * File level: interiors [[x0,z0,x1,z1],...] every 'interior' line (Global appends each to one list, FUN_0097ea10;
 *   see interiorAt). Key defaults are Global's light-key reset FUN_0081bc90 (see newKey).
 *   extra {key: values}      anything unknown
 */
export function parseEnvironment(src) {
  const text = toText(src);
  const keys = [];
  const interiors = [];
  let cur = null;
  for (const raw of text.split(/\r?\n/)) {
    const line = raw.trim();
    if (!line || line.startsWith('//') || line.startsWith('#')) continue;
    const low = line.toLowerCase();
    if (low === '<light>') { cur = newKey(); continue; }
    if (low === '</light>') { if (cur) keys.push(finishKey(cur)); cur = null; continue; }
    const t = line.split(/\s+/);
    const k = t[0].toLowerCase();
    const v = t.slice(1);
    if (k === 'interior') { const r = nums(v.slice(0, 4)); if (r.length === 4 && r.every(Number.isFinite)) interiors.push(r); }
    if (!cur) continue;
    switch (k) {
      case 'time': cur.time = Number(v[0]); break;
      case 'lightdistance': cur.lightDistance = Number(v[0]); break;
      case 'ambient_color': cur.ambient = nums(v.slice(0, 3)); break;
      case 'dirlight_color': cur.sunColor = nums(v.slice(0, 3)); break;
      case 'dirlight_dir': cur.sunDirRaw = nums(v.slice(0, 3)); break;
      case 'dirbacklight_color': cur.backColor = nums(v.slice(0, 3)); break;
      case 'dirbacklight_dir': cur.backDirRaw = nums(v.slice(0, 3)); break;
      case 'fog_value': cur.fog.start = Number(v[0]); cur.fog.end = Number(v[1]); break;
      case 'fog_color': cur.fog.color = nums(v.slice(0, 3)); break;
      case 'weather_value': {
        const w = nums(v);
        cur.weather = { enabled: w[0] === 1, rate: w[1], scene: w[2], duration: w[3], raw: w };
        break;
      }
      case 'bloom_value': { const b = nums(v); cur.bloom = { enabled: b[0] === 1, params: b.slice(1), raw: b }; break; }
      case 'sky_type': { const s = nums(v); cur.sky = { type: s[0], unk: s.length > 1 ? s[1] : null, raw: s }; break; }
      case 'cloud_type': cur.cloud = { raw: nums(v) }; break;
      case 'night': cur.night = Number(v[0]) === 1; break;
      case 'interior': cur.interior = nums(v); break;
      default: cur.extra[k] = v;
    }
  }
  keys.sort((a, b) => a.time - b.time);
  return { keys, dayUnits: DAY_UNITS, interiors };
}

// Defaults = Global's light-key reset at each <light> (32-bit FUN_0081bc90, field offsets from the parser stores in
// FUN_0097e4xx: fog_value -> +0/+4, fog_color -> +8..+0x10, dirlight_dir -> +0x14, dirlight_color -> +0x20,
// dirbacklight_dir -> +0x2c, dirbacklight_color -> +0x38, ambient_color -> +0x44, lightdistance -> +0x50):
// fog 50 / 70, fog colour 0 0 0, sun dir (0, 1, 5), sun colour 1 1 1, back dir (0, 1, -5), back colour 0 0 0 (= off),
// ambient 1 1 1, lightdistance 1000. (All 283 Global keys set every field except the back light, 236 keys omit it.)
export const GLOBAL_LIGHT_KEY_DEFAULTS = Object.freeze({
  fogStart: 50, fogEnd: 70, fogColor: [0, 0, 0], sunDirRaw: [0, 1, 5], sunColor: [1, 1, 1],
  backDirRaw: [0, 1, -5], backColor: [0, 0, 0], ambient: [1, 1, 1], lightDistance: 1000,
});
function newKey() {
  const D = GLOBAL_LIGHT_KEY_DEFAULTS;
  return {
    time: 0, hour: 0, lightDistance: D.lightDistance, ambient: D.ambient.slice(), sunColor: D.sunColor.slice(),
    sunDir: normalize3(D.sunDirRaw), sunDirRaw: null,
    backColor: null, backDir: null, backDirRaw: null,   // unset = Global's (0,0,0) back colour = no back light
    fog: { start: D.fogStart, end: D.fogEnd, color: D.fogColor.slice() },
    weather: { enabled: false, rate: 0, scene: 0, duration: 0, raw: [] }, bloom: { enabled: false, params: [], raw: [] },
    sky: { type: 0, unk: null, raw: [] }, cloud: { raw: [] }, night: false, interior: null, extra: {},
  };
}
function finishKey(k) {
  k.hour = k.time / UNITS_PER_HOUR;
  if (k.sunDirRaw) k.sunDir = normalize3(k.sunDirRaw);
  if (k.backDirRaw) k.backDir = Math.hypot(...k.backDirRaw) > 1e-9 ? normalize3(k.backDirRaw) : [0, 0, 0];
  return k;
}

const lerp = (a, b, t) => a + (b - a) * t;
const lerp3 = (a, b, t) => [lerp(a[0], b[0], t), lerp(a[1], b[1], t), lerp(a[2], b[2], t)];

/**
 * Environment at a time of day (0..240000, wraps). Continuous values are linearly interpolated between the
 * surrounding keys (cyclic); discrete values (sky, cloud, weather, night, bloom.enabled) come from the previous key.
 */
export function sampleEnvironment(env, time) {
  const keys = env.keys;
  if (!keys.length) return finishKey(newKey());
  if (keys.length === 1) return { ...keys[0], time, fogKey: keys[0].fog, fogDirect: true };
  const T = env.dayUnits || DAY_UNITS;
  const t = ((time % T) + T) % T;
  let i = keys.length - 1;
  for (let k = 0; k < keys.length; k++) if (keys[k].time <= t) i = k;
  const a = keys[i];
  const b = keys[(i + 1) % keys.length];
  let span = b.time - a.time; if (span <= 0) span += T;
  let dt = t - a.time; if (dt < 0) dt += T;
  const f = span > 0 ? Math.min(1, dt / span) : 0;
  const out = {
    ...a, time: t, hour: t / UNITS_PER_HOUR, blend: { from: i, to: (i + 1) % keys.length, t: f },
    lightDistance: lerp(a.lightDistance, b.lightDistance, f),
    ambient: lerp3(a.ambient, b.ambient, f),
    sunColor: lerp3(a.sunColor, b.sunColor, f),
    sunDir: normalize3(lerp3(a.sunDir, b.sunDir, f)),
    fog: { start: lerp(a.fog.start, b.fog.start, f), end: lerp(a.fog.end, b.fog.end, f), color: lerp3(a.fog.color, b.fog.color, f) },
    // Global fog: the current key A approached from the last sent fog (stepGlobalFog), not a lerp A -> B. `fog` above is
    // kept for tools; Environment.update drives the scene fog from fogKey / blend.t (LANE-66).
    fogKey: a.fog, fogDirect: dt === 0,
    bloom: { ...a.bloom, params: a.bloom.params.map((p, k) => (b.bloom.params[k] !== undefined ? lerp(p, b.bloom.params[k], f) : p)) },
  };
  if (a.backColor && b.backColor) out.backColor = lerp3(a.backColor, b.backColor, f);
  return out;
}

/**
 * Global's per-update fog step (LANE-66; decompile/32-bit-main SystemModel::Environment::Provider,
 * update FUN_0081d010 + apply FUN_0081ddd0, disassembly 0081d2d1..0081d34c). The exe does NOT interpolate fog between
 * the surrounding keys: with f = the key blend factor (sampleEnvironment blend.t) and P = the fog it last sent
 * (provider +0x24: near, far, r, g, b), it computes  out = P + (keyA - P) * f  for the CURRENT key A, and sends it
 * (CMapFogMsg, FUN_0081e470) only when the colour or the near/far pair moved by more than 0.001 (DAT_01b7e0cc,
 * Euclidean); then P = out. Exactly on a key time, or with a single key, key A is applied directly (out = A).
 * @param {{start:number,end:number,color:number[]}|null} last  P (null = nothing sent yet)
 * @param {{start:number,end:number,color:number[]}} key  the current key's fog (sampleEnvironment fogKey)
 * @param {number} f  blend factor 0..1 (1 when the key is applied directly)
 * @returns {{fog:{start:number,end:number,color:number[]}, sent:boolean}}
 */
export const GLOBAL_FOG_SEND_EPS = 0.001;
export function stepGlobalFog(last, key, f) {
  if (!last) return { fog: { start: key.start, end: key.end, color: key.color.slice(0, 3) }, sent: true };
  const t = Number.isFinite(f) ? f : 1;
  const out = {
    start: last.start + (key.start - last.start) * t, end: last.end + (key.end - last.end) * t,
    color: [0, 1, 2].map(i => last.color[i] + (key.color[i] - last.color[i]) * t),
  };
  const dc = Math.hypot(out.color[0] - last.color[0], out.color[1] - last.color[1], out.color[2] - last.color[2]);
  const dv = Math.hypot(out.start - last.start, out.end - last.end);
  if (dc > GLOBAL_FOG_SEND_EPS || dv > GLOBAL_FOG_SEND_EPS) return { fog: out, sent: true };
  return { fog: { start: last.start, end: last.end, color: last.color.slice(0, 3) }, sent: false };
}

/**
 * Global interior rectangles (LANE-66): Environment::Provider tests the camera focus (CameraImpl +0x58 / +0x60, the
 * look-at pivot; 32-bit vfunc +0x18, 64-bit +0x30) against the light file's interior list (Sketch +0x94, 64-bit +0xa0):
 * (int)x in [x0, x1) and (int)z in [z0, z1) -> sky_type 0 (no sky dome / cloud / flare). FILE frame.
 */
export function interiorAt(env, fileX, fileZ) {
  const list = env && env.interiors;
  if (!list || !list.length || !Number.isFinite(fileX) || !Number.isFinite(fileZ)) return false;
  const x = Math.trunc(fileX), z = Math.trunc(fileZ);
  for (const r of list) if (x >= r[0] && x < r[2] && z >= r[1] && z < r[3]) return true;
  return false;
}

/**
 * Global sky selection (LANE-66): the sky packet carries the CURRENT key's sky_type (FUN_0081d010, not interpolated),
 * forced to 0 inside an interior rect. The dome / cloud plane switch through a Blender (FUN_0159c000) set to
 * flag ? 10000 : 10 ms, and the flag (QMap +0xbd, 64-bit +0x121) is only ever written 0 (ctor 011611c0 /
 * 7ff67123a2e0) -> every sky change is a 10 ms fade (GLOBAL_SKY_FADE_MS), i.e. a switch.
 */
export const GLOBAL_SKY_FADE_MS = 10;
export function globalSkyType(env, key, fileX, fileZ) {
  if (interiorAt(env, fileX, fileZ)) return 0;
  const t = key && key.sky ? key.sky.type : 0;
  return Number.isFinite(t) ? t : 0;
}

/**
 * Global cloud plane scroll (CloudPlane ctor 01586c70 / 01586e10: speed 0.002, direction (1, 0); update FUN_01586e70:
 * offset += ms * 0.002 * 0.002 along the direction, wrapped to [0, 1)) = +0.004 UV per second on u, v fixed.
 * cloud_type values do not change the speed.
 */
export const GLOBAL_CLOUD_UV_PER_MS = 0.002 * 0.002;
export function stepGlobalCloud(offset, dtMs) {
  const u = (offset && Number.isFinite(offset.u) ? offset.u : 0) + (Number.isFinite(dtMs) ? dtMs : 0) * GLOBAL_CLOUD_UV_PER_MS;
  return { u: u - Math.floor(u), v: offset && Number.isFinite(offset.v) ? offset.v - Math.floor(offset.v) : 0 };
}

/** Convert a FILE-frame direction/position to three.js (mirror Z). */
export function toThreeDir(v) { return [v[0], v[1], -v[2]]; }

/** Game-time units for a real-time clock: OnedayTime(Min) real minutes per 240000-unit day. */
export function gameTimeFromRealMs(realMs, onedayMinutes = 90, startTime = 0) {
  const perMs = DAY_UNITS / (onedayMinutes * 60000);
  return (startTime + realMs * perMs) % DAY_UNITS;
}

/**
 * script/environment/sky_table.txt: INDEX,SKYTEX,CLOUDTEX,FLARE,DESC
 * @returns {Array<{index:number, sky:string, cloud:string, flare:number, desc:string}>} sky/cloud as data keys (texture/...)
 */
export function parseSkyTable(src) {
  const rows = parseCSV(toText(src));
  const out = [];
  for (let i = 1; i < rows.length; i++) {
    const r = rows[i];
    if (!r || r.length < 4 || r[0].trim() === '') continue;
    out[Number(r[0])] = {
      index: Number(r[0]),
      sky: texKey(r[1]), cloud: texKey(r[2]), flare: Number(r[3]), desc: (r[4] || '').trim(),
    };
  }
  return out;
}
function texKey(p) {
  const n = String(p || '').trim().replace(/\\/g, '/').toLowerCase();
  return n ? (n.startsWith('texture/') ? n : `texture/${n}`) : '';
}

/**
 * script/environment/sky.txt: lens-flare sets.
 * @returns {Array<{timeofday:number, textures:string[], flares:Array<{size:number, linepos:number, color:number[], obscured:boolean, textureid:number}>}>}
 *   indexed by timeofday (= sky_table FLARE column)
 */
export function parseSkyEffects(src) {
  const text = toText(src);
  const out = [];
  let cur = null, flare = null;
  for (const raw of text.split(/\r?\n/)) {
    const line = raw.trim();
    if (!line) continue;
    const low = line.toLowerCase();
    if (low === '<skyeffect>') { cur = { timeofday: 0, textures: [], flares: [] }; continue; }
    if (low === '</skyeffect>') { if (cur) out[cur.timeofday] = cur; cur = null; continue; }
    if (!cur) continue;
    if (low === '<flare>') { flare = { size: 0, linepos: 0, color: [255, 255, 255], obscured: false, textureid: 0 }; continue; }
    if (low === '</flare>') { if (flare) cur.flares.push(flare); flare = null; continue; }
    if (low.startsWith('<')) continue;
    const t = line.split(/\s+/);
    const k = t[0].toLowerCase();
    if (k === 'timeofday') cur.timeofday = Number(t[1]);
    else if (k === 'texturefile') cur.textures.push(texKey(line.slice(t[0].length).trim().replace(/^"|"$/g, '')));
    else if (flare) {
      if (k === 'size' || k === 'linepos' || k === 'textureid') flare[k] = Number(t[1]);
      else if (k === 'color') flare.color = nums(t.slice(1, 4));
      else if (k === 'obscured') flare.obscured = t[1].toLowerCase() === 'true';
    }
  }
  return out;
}

/** Parse "(t,v) (t,v) ..." curves used by water alpha and effect scenes. */
export function parseCurve(s) {
  const out = [];
  const re = /\(\s*([-\d.eE+]+)\s*,\s*([-\d.eE+]+)\s*\)/g;
  let m;
  while ((m = re.exec(s))) out.push([Number(m[1]), Number(m[2])]);
  return out;
}

/** 'AARRGGBB' hex -> {a,r,g,b} 0..1 */
export function parseARGB(hex) {
  const v = parseInt(String(hex).trim(), 16) >>> 0;
  return { a: ((v >>> 24) & 255) / 255, r: ((v >>> 16) & 255) / 255, g: ((v >>> 8) & 255) / 255, b: (v & 255) / 255, hex: String(hex).trim() };
}

/**
 * property/effect/water/<name>.txt water surface material.
 *   texture N <path>        diffuse animation frames (path relative to texture/)
 *   time <ms>               frame time
 *   type <n>                shader type (-1..4; 3 reflect-only, 4 floor)
 *   bumptex <path>          normal/noise map (texture/...)
 *   attenuation r g b       depth attenuation (may be commented with #)
 *   wave1/wave2 speed amplitude wavelength direction(deg)
 *   color AARRGGBB          tint
 *   alpha (t,v)...          alpha curve over a 0..999 cycle
 */
export function parseWater(src) {
  const text = toText(src);
  const o = { textures: [], time: null, type: null, bumptex: '', attenuation: null, waves: [], color: null, alpha: [], extra: {} };
  for (const raw of text.split(/\r?\n/)) {
    const line = raw.trim();
    if (!line || line.startsWith('#') || line.startsWith('//')) continue;
    const t = line.split(/\s+/);
    const k = t[0].toLowerCase();
    switch (k) {
      case 'texture': o.textures.push({ index: Number(t[1]), path: texKey(t.slice(2).join(' ')) }); break;
      case 'time': o.time = Number(t[1]); break;
      case 'type': o.type = Number(t[1]); break;
      case 'bumptex': o.bumptex = texKey(t.slice(1).join(' ')); break;
      case 'attenuation': o.attenuation = nums(t.slice(1, 4)); break;
      case 'color': o.color = parseARGB(t[1]); break;
      case 'alpha': o.alpha = parseCurve(line.slice(t[0].length)); break;
      default:
        if (/^wave\d+$/.test(k)) {
          const w = nums(t.slice(1, 5));
          o.waves.push({ id: Number(k.slice(4)), speed: w[0], amplitude: w[1], wavelength: w[2], direction: w[3] });
        } else o.extra[k] = t.slice(1);
    }
  }
  return o;
}

/**
 * EnvironmentMap strip (texture/water/skycube*.dds, 9 files, all 768x128, plain 2D DDS without the cubemap flag):
 * six 128x128 slices side by side. The slices are NOT six views of a proper cube. They are consecutive 60-degree
 * pieces of one horizontally continuous, cyclic sky panorama (horizon at the bottom of every slice, sky at the top).
 * The right edge of slice i continues into slice i+1, and slice 5 wraps to slice 0; this was checked numerically on all
 * 9 files. No slice is a zenith or nadir view.
 * The water shaders (binary/water.fx, geoenvwater.fx) sample it with texCUBE, so the client copies the slices into a
 * cube texture. The copy order is presumably the D3DCUBEMAP_FACES order below (unverified: the loader is in the exe).
 * To mimic the game, feed the slices to a CubeTexture in this order. For a seamless reflection, use
 * skyStripToEquirect() instead.
 */
export const SKYCUBE_FACE_ORDER = ['px', 'nx', 'py', 'ny', 'pz', 'nz']; // presumed game copy order (+X,-X,+Y,-Y,+Z,-Z)
/** Pixel rectangle of slice i in a strip image of width w, height h. */
export function skyCubeFaceRect(i, w, h) { const s = Math.floor(w / 6) || h; return { x: i * s, y: 0, w: s, h: Math.min(s, h) }; }

/**
 * Resample the EnvironmentMap panorama strip into an equirectangular RGBA image for three.js
 * (texture.mapping = EquirectangularReflectionMapping).
 *   azimuth:   strip x in [0,w) maps linearly to equirect u in [0,1) and wraps. The absolute orientation is unknown
 *              and does not matter for a cloud panorama.
 *   elevation: the strip's bottom row is the horizon (0 deg) and its top row is `topElevationDeg` (default 90 = zenith).
 *              Directions below the horizon get one flat colour (`belowColor` [r,g,b] 0..255; default = the mean of
 *              the strip's bottom row). Water reflections only look upwards.
 * Rows are written bottom-up (row 0 = elevation -90 deg), matching a THREE.DataTexture with its default
 * flipY = false. Pass { topDown: true } for image order (row 0 = zenith).
 * @param {Uint8Array|Uint8ClampedArray} rgba  decoded strip (e.g. dds.js decodeToRGBA(parseDDS(buf)).data)
 * @returns {{width:number, height:number, data:Uint8Array}}
 */
export function skyStripToEquirect(rgba, w, h, { width = w, height = Math.max(2, Math.round(width / 2)), topElevationDeg = 90, topDown = false, belowColor = null } = {}) {
  const out = new Uint8Array(width * height * 4);
  if (!belowColor) {
    belowColor = [0, 0, 0];
    for (let x = 0; x < w; x++) for (let c = 0; c < 3; c++) belowColor[c] += rgba[((h - 1) * w + x) * 4 + c] / w;
  }
  const sample = (fx, fy, c) => { // bilinear, x wraps, y clamps
    const x0 = Math.floor(fx), y0 = Math.max(0, Math.min(h - 1, Math.floor(fy)));
    const y1 = Math.min(h - 1, y0 + 1), tx = fx - x0, ty = Math.max(0, Math.min(1, fy - y0));
    const xa = ((x0 % w) + w) % w, xb = (xa + 1) % w;
    const p = (x, y) => rgba[(y * w + x) * 4 + c];
    return (p(xa, y0) * (1 - tx) + p(xb, y0) * tx) * (1 - ty) + (p(xa, y1) * (1 - tx) + p(xb, y1) * tx) * ty;
  };
  for (let r = 0; r < height; r++) {
    const elev = ((r + 0.5) / height) * 180 - 90; // bottom-up
    const e = Math.max(0, Math.min(topElevationDeg, elev));
    const fy = (1 - e / topElevationDeg) * h - 0.5; // strip row (0 = top)
    const row = topDown ? height - 1 - r : r;
    for (let x = 0; x < width; x++) {
      const fx = ((x + 0.5) / width) * w - 0.5;
      const o = (row * width + x) * 4;
      for (let c = 0; c < 3; c++) out[o + c] = Math.round(elev < 0 ? belowColor[c] : sample(fx, fy, c));
      out[o + 3] = 255;
    }
  }
  return { width, height, data: out };
}

/**
 * Environment-related columns of one share/maplist.csv row.
 * @param {Record<string,string>|string[]} row  object keyed by header, or raw array + headers
 * @param {string[]} [headers]
 */
export function mapEnvironmentInfo(row, headers = null) {
  const get = (name) => {
    if (Array.isArray(row)) { const i = headers ? headers.findIndex(h => h.trim().toLowerCase() === name.toLowerCase()) : -1; return i >= 0 ? row[i] : undefined; }
    if (name in row) return row[name];
    const k = Object.keys(row).find(h => h.trim().toLowerCase() === name.toLowerCase());
    return k ? row[k] : undefined;
  };
  const n = (name) => { const v = get(name); const x = Number(String(v ?? '').trim()); return v === undefined || String(v).trim() === '' || !Number.isFinite(x) ? null : x; };
  const s = (name) => String(get(name) ?? '').trim();
  let envFile = s('EnvironmentFile');
  if (envFile && !/\.txt$/i.test(envFile)) envFile += '.txt'; // 2 rows omit the extension
  const envMap = s('EnvironmentMap');
  return {
    index: n('Index'), name: s('Name'),
    environmentFile: envFile ? `map/${envFile.toLowerCase()}` : '',
    environmentMap: envMap ? texKey(envMap) : '',
    onedayMinutes: n('OnedayTime(Min)'),
    clipFar: n('Clip_Far'),
    reflectHeight: n('Reflect_Height'), // water reflection plane height (world Y). -1000 = none
    roofHeight: n('Roof_Height'),
    fov: n('FOV'), // 0.65 on every row; most likely radians (~37 deg vertical FOV) — unverified
    viewType: n('viewType'),
    camera: {
      nearDistance: n('Camera_Near_Distance'), farDistance: n('Camera_Far_Distance'), height: n('Camera_Height'),
      minAngle: n('Camera_MinAngle'), maxAngle: n('Camera_MaxAngle'), defaultZoom: n('DefaultZoom'),
      defaultHAngle: n('Default_H_Angle'), defaultVAngle: n('Default_V_Angle'),
    },
    cull: {
      base: n('Cull_Base'), plant: n('Cull_Plant'), tree: n('Cull_Tree'), rock: n('Cull_Rock'), fieldExtra: n('Cull_FieldExtra'),
      wall: n('Call_Wall'), building: n('Cull_Building'), buildingExtra: n('Cull_BuildingExtra'), effect: n('Cull_Effect'),
    },
    mipmap: { enable: n('MipMapEnable'), bias: n('MipMapBias'), filter: n('MipMapFilter'), maxFilter: n('MaxFilter'), minFilter: n('MinFilter') },
    files: {
      map: s('MapFile') ? `map/${s('MapFile').toLowerCase()}` : '',
      mol: s('MapObject') ? `map/${s('MapObject').toLowerCase()}` : '',
      mel: s('MapEffect') ? `map/${s('MapEffect').toLowerCase()}` : '',
      // collision grids live in share/mapredcell/ (map/ holds only two all-zero stubs) — same rule as spawn.js mapDataPaths()
      mac: s('MapAttribute') ? `share/mapredcell/${s('MapAttribute').toLowerCase()}` : '',
      // 3 rows (nunvice_01..03.pre) name preload files that do not exist; treat a 404 as "nothing to preload"
      preload: s('Preloading') ? `property/preload/${s('Preloading').toLowerCase()}` : '',
    },
  };
}

/** Parse share/maplist.csv into row objects keyed by header (header names trimmed). */
export function parseMapList(src) {
  const rows = parseCSV(toText(src));
  const head = (rows.shift() || []).map(h => h.trim());
  return rows.filter(r => r.length > 1).map(r => { const o = {}; head.forEach((h, i) => { o[h] = r[i]; }); return o; });
}

/**
 * Legacy property/map/*.txt (and property/*_field.txt): "key values..." lines, optional [section]..[/section] blocks.
 * @returns {{ sections: Record<string, Record<string, string[]>>, values: Record<string, string[]>, multi: Record<string, string[][]> }}
 */
export function parseMapProperty(src) {
  const text = toText(src);
  const out = { sections: {}, values: {}, multi: {} };
  let sec = null;
  for (const raw of text.split(/\r?\n/)) {
    const line = raw.trim();
    if (!line || line.startsWith('//')) continue;
    let m = /^\[\/(.+)\]$/.exec(line);
    if (m) { sec = null; continue; }
    m = /^\[(.+)\]$/.exec(line);
    if (m) { sec = m[1].toLowerCase(); out.sections[sec] = out.sections[sec] || {}; continue; }
    const t = line.match(/"[^"]*"|\S+/g).map(x => x.replace(/^"|"$/g, ''));
    const k = t[0].toLowerCase();
    const target = sec ? out.sections[sec] : out.values;
    target[k] = t.slice(1);
    (out.multi[k] = out.multi[k] || []).push(t.slice(1));
  }
  return out;
}
