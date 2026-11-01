// Pure native effect parsers/normalizers ported unchanged from tools/build-skills.mjs.
import {decodeText} from '../../formats/binreader.js';
export function normPath(p) {
  return String(p ?? '').trim().replace(/^"|"$/g, '').replace(/\\/g, '/').replace(/^(\.\/)+/, '').replace(/^\/+/, '').replace(/\/{2,}/g, '/').toLowerCase();
}
/** Game path relative to a type root ("Effect\\Skill\\x.mesh") -> data key ("mesh/effect/skill/x.mesh"). */
export function gamePathToData(root, p) {
  const n = normPath(p);
  if (!n) return null;
  const r = normPath(root).replace(/\/$/, '');
  return n.startsWith(r + '/') ? n : `${r}/${n}`;
}
const toU8 = (b) => (b instanceof Uint8Array ? b : new Uint8Array(b));
const toText = (src, korean = true) => (typeof src === 'string' ? src : decodeText(toU8(src), korean));

// ---------------------------------------------------------------------------------------------------------------

export function parseKeyframes(s) {
  const out = [];
  for (const m of String(s).matchAll(/\(([^)]*)\)/g)) {
    const v = m[1].split(/[\s,]+/).filter(x => x !== '').map(Number).filter(x => Number.isFinite(x));
    if (v.length) out.push(v);
  }
  return out;
}
const tokens = (s) => {
  const out = [];
  for (const m of String(s).matchAll(/"([^"]*)"|(\S+)/g)) out.push(m[1] !== undefined ? m[1] : m[2]);
  return out;
};
const num = (v) => { const x = Number(String(v ?? '').trim()); return Number.isFinite(x) ? x : null; };
const bool = (v) => /^(true|ture|1)$/i.test(String(v ?? '').trim());

/**
 * property/effect/effectscene.<file>.txt -> array of effects
 * { cate, id, name, file, res: {unitId: unitName}, scenes: [{ sceneId, name, controls: [...] }] }
 * Control keys are kept verbatim (keyframe lists parsed, see parseKeyframes); docs/formats/effects.md lists them.
 */
export function parseEffectScenes(src, file = '') {
  const text = toText(src, true);
  const effects = [];
  let cate = null, eff = null, scene = null, ctl = null, inList = false;
  for (const raw of text.split(/\r?\n/)) {
    const line = raw.trim();
    if (!line || line[0] === '#') continue;
    const low = line.toLowerCase();
    let m;
    if ((m = /^<cate>\s*(-?\d+)/i.exec(line))) { cate = +m[1]; continue; }
    if (low.startsWith('</cate>')) continue;
    if (low.startsWith('<effect>')) { eff = { cate, id: null, name: '', file, res: {}, scenes: [] }; scene = null; ctl = null; inList = false; continue; }
    if (low.startsWith('</effect>')) { if (eff && eff.id !== null) effects.push(eff); eff = null; continue; }
    if (!eff) continue;
    if (low.startsWith('<list>')) { inList = true; continue; }
    if (low.startsWith('</list>')) { inList = false; continue; }
    if (low.startsWith('<scene>')) { scene = { sceneId: null, name: '', controls: [] }; eff.scenes.push(scene); continue; }
    if (low.startsWith('</scene>')) { scene = null; continue; }
    if (low.startsWith('<control>')) { ctl = {}; if (scene) scene.controls.push(ctl); continue; }
    if (low.startsWith('</control>')) { ctl = null; continue; }
    const sp = line.search(/\s/);
    const key = (sp < 0 ? line : line.slice(0, sp)).toLowerCase();
    const val = sp < 0 ? '' : line.slice(sp).trim();
    if (ctl) {
      if (key in ctl && key === 'active') continue; // every control repeats "active" at its end with the same value
      ctl[key] = val;
      continue;
    }
    if (scene) {
      if (key === 'sceneid') scene.sceneId = num(val);
      else if (key === 'name') scene.name = val;
      continue;
    }
    if (inList && key === 'res') { const t = val.split(/\s+/); eff.res[num(t[0])] = t.slice(1).join(' '); continue; }
    if (key === 'id' && eff.id === null) eff.id = num(val);
    else if (key === 'name' && !eff.name) eff.name = val;
  }
  return effects;
}

/**
 * property/effect/effectdata.<file>.txt -> array of units { name, unittype, file, fields: {key: value} }.
 * Units are addressed by `name` (case-insensitive) from the `res` lists of effect scenes.
 */
export function parseEffectData(src, file = '') {
  const text = toText(src, true);
  const units = [];
  let cur = null, cate = null;
  for (const raw of text.split(/\r?\n/)) {
    const line = raw.trim();
    if (!line || line[0] === '#') continue;
    let m;
    if ((m = /^<cate>\s*(-?\d+)/i.exec(line))) { cate = +m[1]; continue; }
    if (/^<effectdata>/i.test(line)) { cur = { name: '', unittype: '', file, cate, tag: num(line.replace(/^<effectdata>/i, '')), fields: {} }; continue; }
    if (/^<\/effectdata>/i.test(line)) { if (cur && cur.name) units.push(cur); cur = null; continue; }
    if (!cur) continue;
    const sp = line.search(/\s/);
    const key = (sp < 0 ? line : line.slice(0, sp)).toLowerCase();
    const val = sp < 0 ? '' : line.slice(sp).trim();
    if (key === 'name') cur.name = val;
    else if (key === 'unittype') cur.unittype = val.toLowerCase();
    else cur.fields[key] = val;
  }
  return units;
}


const vec = (s) => String(s ?? '').trim().split(/[\s,]+/).filter(x => x !== '').map(Number).filter(Number.isFinite);

/** Turn a raw effectdata unit into a typed, engine-friendly object (asset paths resolved by `res`). */
export function describeUnit(u, res) {
  // every field the switch below does not read is kept verbatim in o.raw (Proxy records the reads)
  const used = new Set();
  const f = new Proxy(u.fields, { get(t, k) { used.add(k); return t[k]; } });
  const o = { type: u.unittype || 'unknown', file: u.file };
  if (u.tag) o.flag = u.tag; // the number after "<effectdata>" (0, or 1 on 389 units; meaning unknown)
  const finish = () => {
    if (o.raw === u.fields) return o;
    for (const k of Object.keys(u.fields)) if (!used.has(k) && u.fields[k] !== '') (o.raw ??= {})[k] = u.fields[k];
    return o;
  };
  const tex = () => {
    if (f.texturefile) { const k = res.texture(f.texturefile, u); if (k) o.texture = k; }
    if (f.texturepack) { const tp = res.tpack(f.texturepack, u); if (tp) { o.tpack = tp.key; o.frames = tp.frames; } }
    if (f.blendtype) o.blend = f.blendtype.toLowerCase();
    if (f.textureloop) o.texLoop = f.textureloop.toLowerCase();
    if (f.texanimtime !== undefined) o.texAnimMs = num(f.texanimtime) || 0;
  };
  const common = () => {
    if (f.billboardtype !== undefined) o.billboard = f.billboardtype.toLowerCase();
    if (f.size !== undefined) o.size = num(f.size);
    if (f.backprint !== undefined) o.backPrint = bool(f.backprint);
    if (f.disort !== undefined) o.distort = bool(f.disort);
    if (f.tailstep !== undefined) { const t = tokens(f.tailstep); o.tail = { count: num(t[0]), a: num(t[1]), b: num(t[2]), ms: num(t[3]), on: bool(t[4]) }; }
  };
  const meshPart = () => {
    if (f.mesh) { const k = res.path('mesh', f.mesh, u); if (k) o.mesh = k; }
    if (f.animation) { const k = res.path('anim', f.animation, u); if (k) o.anim = k; }
    if (f.skeleton) { const k = res.path('skel', f.skeleton, u); if (k) o.skel = k; }
    if (f.animlength !== undefined) o.animLengthMs = num(f.animlength);
    if (f.twoside !== undefined) o.twoSide = bool(f.twoside);
    if (f.transparent !== undefined) o.transparent = bool(f.transparent);
    if (f.mesh_status !== undefined) { const t = tokens(f.mesh_status); o.meshStatus = { mode: num(t[0]), a: num(t[1]), b: num(t[2]), line: t[3] || '' }; }
  };
  switch (o.type) {
    case 'sprite': common(); tex(); break;
    case 'decal': common(); tex(); break;
    case 'mesh': common(); meshPart(); if (f.texturepack) { const tp = res.tpack(f.texturepack, u, true); if (tp) { o.tpack = tp.key; o.textures = tp.textures; } } break;
    case 'particle': case 'weather': {
      common(); tex();
      if (f.leaftype) o.leaf = f.leaftype.toLowerCase();
      const e = {};
      if (f.activestate) e.state = f.activestate.toLowerCase();
      if (f.lifetime !== undefined) e.lifetimeMs = vec(f.lifetime);
      if (f.emitrate !== undefined) e.rate = num(f.emitrate);
      if (f.maxelementcount !== undefined) e.max = num(f.maxelementcount);
      if (f.addrotate !== undefined) e.addRotate = num(f.addrotate);
      if (f.velocity !== undefined) e.velocity = vec(f.velocity);
      if (f.acceleration !== undefined) e.acceleration = num(f.acceleration);
      if (f.spawndirection !== undefined) e.spawnDir = vec(f.spawndirection);
      if (f.gravity !== undefined) e.gravity = vec(f.gravity);
      if (f.colorrange !== undefined) e.colorRange = num(f.colorrange);
      if (f.startrange !== undefined) e.startRange = vec(f.startrange);
      if (f.endposition !== undefined) e.endPos = vec(f.endposition);
      if (f.particlesize !== undefined) e.particleSize = vec(f.particlesize);
      if (f.followdirection !== undefined) e.followDir = bool(f.followdirection);
      if (f.spawndirabs !== undefined) e.spawnDirAbs = bool(f.spawndirabs);
      if (f.trianglerender !== undefined) e.triangleRender = bool(f.trianglerender);
      for (const k of ['flatmaxelementcount', 'flatscale', 'flatcolor', 'flatrenderrate']) if (f[k] !== undefined) e[k] = vec(f[k]);
      if (f.flattexturefile) e.flatTexture = res.texture(f.flattexturefile, u);
      o.emitter = e;
      if (o.leaf === 'mesh' || f.mesh) meshPart();
      break;
    }
    case 'sound': {
      const t = tokens(f.sound);
      o.subtype = (f.subtype || '').toLowerCase();
      if (t[0]) { o.soundFile = t[0]; const k = res.sound(t[0], u); if (k) o.sound = k; }
      o.flagA = num(t[1]); o.volume = num(t[2]); o.range = num(t[3]); o.lengthMs = num(t[4]); o.exclusive = bool(t[5]);
      if (f.playintv) o.playInterval = vec(f.playintv);
      break;
    }
    case 'quake': { const t = vec(f.camera); o.camera = { a: t[0], amplitude: t[1], frequency: t[2] }; break; }
    case 'meshstatus': {
      common(); tex();
      if (f.mesh_status !== undefined) { const t = tokens(f.mesh_status); o.meshStatus = { mode: num(t[0]), a: num(t[1]), b: num(t[2]), line: t[3] || '' }; }
      if (f.mesh_color !== undefined) o.color = vec(f.mesh_color);
      break;
    }
    case 'light': {
      for (const k of ['light', 'dirlight', 'bloom', 'fog']) if (f[k] !== undefined) o[k] = vec(f[k]);
      for (const k of ['light_enable', 'bloom_enable', 'fog_enable']) if (f[k] !== undefined) o[k.replace('_enable', 'Enable')] = bool(f[k]);
      if (f.light_fadetime !== undefined) o.fadeMs = num(f.light_fadetime);
      if (f.light_range !== undefined) o.range = num(f.light_range);
      if (f.light_faderange !== undefined) o.fadeRange = num(f.light_faderange);
      break;
    }
    default: o.raw = u.fields;
  }
  return finish();
}

/** Effect-scene control -> compact object (defaults omitted). Keyframe times: 0..999 over the control's lifetime. */
export function describeControl(c) {
  const o = { unit: num(c.unitid) };
  if (c.active !== undefined && !bool(c.active)) o.active = false;
  const sp = vec(c.startposition);
  if (sp.some(v => v)) o.pos = sp;
  if (c.lifetime !== undefined) o.life = vec(c.lifetime);
  if (c.animtime !== undefined && num(c.animtime)) o.animTime = num(c.animtime);
  if (c.bonename !== undefined) o.bone = tokens(c.bonename)[0] ?? '';
  if (c.follow !== undefined) o.follow = bool(c.follow);
  if (c.randomstart !== undefined && bool(c.randomstart)) o.randomStart = true;
  if (c.absdir !== undefined) o.absDir = bool(c.absdir);
  if (c.abspos !== undefined) o.absPos = bool(c.abspos);
  if (c.animpath !== undefined) o.animPath = tokens(c.animpath)[0] ?? '';
  if (c.bone_animation !== undefined) {
    const t = tokens(c.bone_animation);
    o.boneAnim = { bone: t[0], skel: t[1] ? gamePathToData('skel', t[1]) : null, anim: t[2] ? gamePathToData('anim', t[2]) : null, params: t.slice(3).map(Number) };
  }
  for (const [k, n] of [['scale', 'scale'], ['alpha', 'alpha'], ['color', 'color'], ['rotation', 'rotation'], ['position', 'position']]) {
    if (c[k] !== undefined) o[n] = parseKeyframes(c[k]);
  }
  const known = new Set(['unitid', 'active', 'startposition', 'lifetime', 'animtime', 'bonename', 'follow', 'randomstart', 'absdir', 'abspos', 'animpath', 'bone_animation', 'scale', 'alpha', 'color', 'rotation', 'position']);
  for (const k of Object.keys(c)) if (!known.has(k)) (o.raw ??= {})[k] = c[k];
  return o;
}

// ---------------------------------------------------------------------------------------------------------------
