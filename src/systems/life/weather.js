// Weather per map: the light key's weather_value (map/light_*.txt: enabled, rate %, scene, duration ms) plays scene
// N of weather effect 100 (property/effect/effectscene.com.txt <cate> 10): 1 rain, 2 snow, 3 sandstorm, 4 shower,
// 5 blossom, 6 festival pollen. Each scene enables some of the effect's units (life.json weather.scenes/units):
//   weather units (effectdata.com/.map `unittype weather`): a particle volume around the viewer. The particle rules
//     (spawn, per-age control keys, wrap, flat splashes) are the Global ones documented above weatherSpawn below.
//   sound units (effectdata.snd): sn_rain (40 %, looped while it rains), sn_thunder (control lifetime 500..1000 of
//     the scene with randomstart: one clap at a random moment of the second half of every scene cycle),
//     sn_wind_desert3 (sandstorm).
// A weather key rolls `rate` % once per `duration` ms (rate 100 = always). On a change the old scene stops emitting
// and its particles run out their life before the next scene starts. Particles are kept in FILE space and drawn in
// game.scene (outside the mirrored worldRoot) at (x, y, -z).
import * as THREE from 'three';
import { fetchText } from '../../engine/assets.js';
import { globalWeatherEmitCount, globalStepRotation, globalAgeFraction, GLOBAL_WEATHER_SPAWN_ROTATION } from '../skills/global-particle-rules.js'; // LANE-63

const VERT = /* glsl */`
attribute vec3 iPos;
attribute vec2 iSize;
attribute vec4 iCol;
attribute float iRot;
uniform int mode;
varying vec2 vUv;
varying vec4 vC;
void main() {
  vUv = uv;
  vC = iCol;
  vec2 c = position.xy;
  float cs = cos(iRot), sn = sin(iRot);
  c = vec2(c.x * cs - c.y * sn, c.x * sn + c.y * cs);
  vec3 wp;
  if (mode == 0) {
    vec3 right = vec3(viewMatrix[0][0], viewMatrix[1][0], viewMatrix[2][0]);
    vec3 up = vec3(viewMatrix[0][1], viewMatrix[1][1], viewMatrix[2][1]);
    wp = iPos + right * c.x * iSize.x + up * c.y * iSize.y;
  } else if (mode == 1) {
    vec3 toCam = cameraPosition - iPos; toCam.y = 0.0;
    vec3 right = length(toCam) > 1e-4 ? normalize(cross(vec3(0.0, 1.0, 0.0), toCam)) : vec3(1.0, 0.0, 0.0);
    wp = iPos + right * c.x * iSize.x + vec3(0.0, 1.0, 0.0) * c.y * iSize.y;
  } else {
    wp = iPos + vec3(c.x * iSize.x, 0.0, c.y * iSize.y);
  }
  gl_Position = projectionMatrix * viewMatrix * vec4(wp, 1.0);
}`;
const FRAG = /* glsl */`
uniform sampler2D map;
varying vec2 vUv;
varying vec4 vC;
void main() {
  vec4 t = texture2D(map, vUv);
  float a = t.a * vC.a;
  if (a <= 0.0) discard;
  gl_FragColor = vec4(t.rgb * vC.rgb, a);
}`;

// ---- Global weather element (Ghost::DollStage::Effect::Unit::Weather, decompile 32-bit decompile; constants read from
// the 32-bit memory image: 0.001 ms->s (DAT_01b7e0cc), 0.999 (_DAT_01b7e1b4), 999 key scale (_DAT_01b7e3bc),
// 1e-6 (DAT_01b7e0b8), 0.05 (DAT_01b7e100)). Data offsets from the effectdata parser (~390886..391072).
//   spawn FUN_011a9eb0: life = ftol(rand x (max-min) + min) ms; size = particlesize rand when either value > 0, else
//     the unit `size`; alpha/colour/scale start at 1 then take the control keys at time 0; rotation 0;
//     position = centre + normalize(rand3 in [-1,1]) x rand(startrange), y = centre y; speed = rand(velocity);
//     direction = normalize(normalize(rand3) * spawndirection); gravity velocity = (0, rand x 0.999 + 0.001, 0)
//     when gravity is non-zero, else 0; texture frame = random.
//   step FUN_011aa570: remaining -= dt; age = 1 - remaining/total; control alpha/colour/scale keys sampled at
//     ftol(age x 999); rotation = addrotate x age; speed = max(0, speed - acceleration x dt);
//     gravity velocity += gravity x dt; pos += dir x speed x dt + gravity velocity x dt (y only once a flat element
//     has visited the drop); then FUN_011aa990 wraps x/z into centre +- startrange[1].
//   centre (FUN_011a9900) = control position + the camera target (the player).
//   flat FUN_011c8190 (rain): visits drops in order, marks each, stops after flatmaxelementcount; a drop with
//     remaining/total < flatrenderrate gets a ground quad of flatscale x 2 x (remaining/total) / flatrenderrate,
//     colour flatcolor/255, lifted 0.05.
// Particles die when their life runs out (no ground kill); there is no per-particle fade or y jitter.
export const WEATHER_MS_TO_S = 0.001;
export const WEATHER_GRAVITY_LIFT = [0.999, 0.001];
export const WEATHER_KEY_SCALE = 999;
export const WEATHER_EPS = 1e-6;
export const WEATHER_FLAT_LIFT = 0.05;

const rnd = (rand, a, b) => rand() * (b - a) + a;
function norm3(v) { const l = Math.hypot(v[0], v[1], v[2]); return l > 0 ? [v[0] / l, v[1] / l, v[2] / l] : [0, 0, 0]; }

/** Control key track [[t, v...]] (t 0..999) sampled at integer key time t; null when the control has no track. */
export function weatherKey(keys, t, n) {
  if (!keys || !keys.length) return null;
  if (t <= keys[0][0]) return keys[0].slice(1, 1 + n);
  for (let i = 1; i < keys.length; i++) {
    const a = keys[i - 1], b = keys[i];
    if (t <= b[0]) { const f = (t - a[0]) / (b[0] - a[0] || 1); return a.slice(1, 1 + n).map((v, k) => v + ((b[k + 1] ?? v) - v) * f); }
  }
  return keys[keys.length - 1].slice(1, 1 + n);
}

function sampleControl(q, ctl, t) {
  const a = weatherKey(ctl.alpha, t, 1); if (a) q.alpha = a[0];
  const c = weatherKey(ctl.color, t, 3); if (c) q.color = c;
  const s = weatherKey(ctl.scale, t, 3); if (s) q.scale = s;
}

/** FUN_011a9eb0. U = life.json weather unit, ctl = scene control, c = centre {x,y,z} in file space. */
export function weatherSpawn(U, ctl, c, rand = Math.random, texCount = 1) {
  const life = U.life || [], ps = U.psize || [], range = U.range || [], vel = U.velocity || [], sd = U.dir || [0, 0, 0], g = U.gravity || [0, 0, 0];
  const total = Math.trunc(rnd(rand, life[0] || 0, life[1] ?? life[0] ?? 0));
  const size = (ps[0] > 0 || ps[1] > 0) ? rnd(rand, ps[0] || 0, ps[1] || 0) : U.size;
  const r = rnd(rand, range[0] || 0, range[1] ?? range[0] ?? 0);
  const n = norm3([rand() * 2 - 1, rand() * 2 - 1, rand() * 2 - 1]);
  let d = [0, 0, 0];
  if (sd[0] * sd[0] + sd[1] * sd[1] + sd[2] * sd[2] > WEATHER_EPS) {
    const m = norm3([rand() * 2 - 1, rand() * 2 - 1, rand() * 2 - 1]);
    d = [m[0] * sd[0], m[1] * sd[1], m[2] * sd[2]];
    if (d[0] * d[0] + d[1] * d[1] + d[2] * d[2] > WEATHER_EPS) d = norm3(d);
  }
  const gv = (g[0] || g[1] || g[2]) ? [0, rand() * WEATHER_GRAVITY_LIFT[0] + WEATHER_GRAVITY_LIFT[1], 0] : [0, 0, 0];
  const q = { x: c.x + n[0] * r, y: c.y, z: c.z + n[2] * r, total, rem: total, age: 0, size, alpha: 1, color: [1, 1, 1], scale: [1, 1, 1],
    rot: GLOBAL_WEATHER_SPAWN_ROTATION, speed: rnd(rand, vel[0] || 0, vel[1] ?? vel[0] ?? 0), d, gv, flat: false,
    tex: texCount > 1 ? Math.trunc(rand() * texCount) : 0 };
  sampleControl(q, ctl, 0);
  return q;
}

/** FUN_011aa570 + FUN_011aa990. Returns false when the particle has no life left (removed). */
export function weatherStep(q, U, ctl, dtMs, c) {
  if (!(q.rem > 0)) return false;
  q.rem = Math.max(0, q.rem - dtMs);
  const frac = q.total > 0 ? q.rem / q.total : 0;
  q.age = Math.min(1, Math.max(0, 1 - frac));
  q.frac = frac;
  sampleControl(q, ctl, Math.trunc(q.age * WEATHER_KEY_SCALE));
  q.rot = globalStepRotation(U.rotate, globalAgeFraction(q.total - q.rem, q.total), q.rot);
  const dt = dtMs * WEATHER_MS_TO_S, g = U.gravity || [0, 0, 0];
  q.speed = Math.max(0, q.speed - (U.accel || 0) * dt);
  q.gv[0] += dt * (g[0] || 0); q.gv[1] += dt * (g[1] || 0); q.gv[2] += dt * (g[2] || 0);
  const s = q.speed * dt;
  if (!q.flat) { q.x += q.d[0] * s + q.gv[0] * dt; q.z += q.d[2] * s + q.gv[2] * dt; }
  q.y += q.d[1] * s + q.gv[1] * dt;
  const R = (U.range || [])[1] ?? (U.range || [])[0] ?? 0;
  if (q.x > c.x + R) q.x = c.x - R; else if (q.x < c.x - R) q.x = c.x + R;
  if (q.z > c.z + R) q.z = c.z - R; else if (q.z < c.z - R) q.z = c.z + R;
  return true;
}

/** One particle emitter of a weather unit (one GPU draw per texture). Particles live in FILE space (x, y, z);
 *  drawing maps them to THREE as (x, y, -z). */
class Emitter {
  constructor(game, unit, ctl, textures) {
    this.game = game;
    this.u = unit;
    this.ctl = ctl;
    this.max = Math.max(0, unit.max | 0);                     // maxelementcount = the free pool (FUN_011a9b80)
    this.parts = [];
    this.emitAcc = 0;
    this.meshes = [];
    const mode = unit.billboard === 'yaxis' ? 1 : 0;
    const blending = unit.blend === 'add' ? THREE.AdditiveBlending : THREE.NormalBlending;
    for (const tex of textures.length ? textures : [null]) this.meshes.push(this._mesh(tex, mode, blending, Math.max(1, this.max)));
    if (unit.flat && unit.flatTexture) this.flatMesh = this._mesh(unit.flatTexture, 2, blending, Math.max(1, (unit.flat.max | 0) + 1));
  }

  _mesh(tex, mode, blending, count) {
    const base = new THREE.PlaneGeometry(1, 1);
    const g = new THREE.InstancedBufferGeometry();
    g.index = base.index;
    g.setAttribute('position', base.getAttribute('position'));
    g.setAttribute('uv', base.getAttribute('uv'));
    const mk = (n) => { const a = new THREE.InstancedBufferAttribute(new Float32Array(count * n), n); a.setUsage(THREE.DynamicDrawUsage); return a; };
    const pos = mk(3), size = mk(2), col = mk(4), rot = mk(1);
    g.setAttribute('iPos', pos); g.setAttribute('iSize', size); g.setAttribute('iCol', col); g.setAttribute('iRot', rot);
    g.instanceCount = 0;
    const white = new THREE.DataTexture(new Uint8Array([255, 255, 255, 255]), 1, 1); white.needsUpdate = true;
    const mat = new THREE.ShaderMaterial({
      vertexShader: VERT, fragmentShader: FRAG, transparent: true, depthWrite: false, depthTest: true, blending, side: THREE.DoubleSide,
      uniforms: { map: { value: tex || white }, mode: { value: mode } },
    });
    const m = new THREE.Mesh(g, mat);
    m.frustumCulled = false;
    m.renderOrder = 900;
    m.name = `weather:${this.u.name}`;
    this.game.scene.add(m);
    return { mesh: m, pos, size, col, rot, cap: count, white };
  }

  /** c = centre in file space; ground(xFile, zFile) = terrain y; emitting = the scene is still playing. */
  update(dt, c, ground, emitting) {
    const U = this.u, ctl = this.ctl, dtMs = Math.max(0, dt) * 1000;
    if (emitting) {
      // Global weather emit FUN_011a9d00 (LANE-63): emitrate = ms per particle, unsigned accumulator, no per-tick cap.
      let k = globalWeatherEmitCount(this, dtMs, U.emit);
      for (; k > 0 && this.parts.length < this.max; k--) this.parts.push(weatherSpawn(U, ctl, c, Math.random, this.meshes.length));
    } else this.emitAcc = 0;
    for (let i = 0; i < this.parts.length; i++) {
      if (!weatherStep(this.parts[i], U, ctl, dtMs, c)) { this.parts.splice(i, 1); i--; }
    }
    const counts = this.meshes.map(() => 0);
    for (const q of this.parts) {
      const m = this.meshes[q.tex] || this.meshes[0];
      const k = counts[q.tex]++;
      if (k >= m.cap) continue;
      m.pos.setXYZ(k, q.x, q.y, -q.z);
      m.size.setXY(k, q.scale[0] * q.size, q.scale[2] * q.size);      // Sprite FUN_011c7530: w = scale.x x size, h = scale.z x size
      m.col.setXYZW(k, q.color[0], q.color[1], q.color[2], q.alpha);
      m.rot.setX(k, q.rot);
    }
    this.meshes.forEach((m, i) => {
      m.mesh.geometry.instanceCount = Math.min(counts[i], m.cap);
      m.pos.needsUpdate = m.size.needsUpdate = m.col.needsUpdate = m.rot.needsUpdate = true;
    });
    if (this.flatMesh) {
      const F = this.flatMesh, fl = U.flat, sc = fl.scale || [], fc = fl.color || [], rate = fl.rate;
      let n = 0, visited = 0;
      for (const q of this.parts) {
        q.flat = true;
        if ((fl.max | 0) < visited) break;
        if (q.frac < rate && n < F.cap) {
          const f = (1 / rate) * q.frac * 2;
          F.pos.setXYZ(n, q.x, ground(q.x, q.z) + WEATHER_FLAT_LIFT, -q.z);
          F.size.setXY(n, (sc[0] || 0) * f, (sc[1] ?? sc[0] ?? 0) * f);
          F.col.setXYZW(n, (fc[0] ?? 0) / 255, (fc[1] ?? 0) / 255, (fc[2] ?? 0) / 255, (fc[3] ?? 0) / 255);
          F.rot.setX(n, 0);
          n++;
        }
        visited++;
      }
      F.mesh.geometry.instanceCount = n;
      F.pos.needsUpdate = F.size.needsUpdate = F.col.needsUpdate = F.rot.needsUpdate = true;
    }
  }

  get alive() { return this.parts.length; }

  dispose() {
    for (const m of [...this.meshes, this.flatMesh].filter(Boolean)) {
      m.mesh.removeFromParent(); m.mesh.geometry.dispose(); m.mesh.material.dispose(); m.white.dispose();
    }
    this.meshes = []; this.flatMesh = null;
  }
}

export class Weather {
  constructor(game, data) {
    this.game = game;
    this.W = data;                 // life.json weather
    this.scene = 0;                // playing scene id (0 = none)
    this.emitting = false;         // the scene's units emit; when the weather changes they stop and live particles finish (FUN_011a96a0)
    this.emitters = [];
    this.sounds = [];
    this.cycle = 0;                // s into the current scene cycle
    this.forced = null;            // GM / debug: scene id, 0 = clear, null = follow the map
    this._roll = { key: null, until: 0, on: false };
    this._texCache = new Map();
    this._loading = null;
  }

  /** The weather the map's current light key asks for: {scene, rate, duration} or null. */
  _keyWeather() {
    const env = this.game.world?.environment;
    const w = env?.current?.weather;
    if (!w || !w.enabled || !(w.scene > 0)) return null;
    return { scene: w.scene, rate: Number(w.rate) || 0, duration: Number(w.duration) > 0 ? Number(w.duration) : 0, key: env.current.blend?.from ?? 0 };
  }

  get name() { return this.W?.names?.[this.scene] || 'clear'; }

  /** Force a weather scene (1..6), 0 = clear, null = back to the map's light keys. */
  force(scene) { this.forced = scene == null ? null : Number(scene) || 0; }

  update(dt) {
    if (!this.W || !this.game.world || !this.game.player) return;
    let target = 0;
    if (this.forced != null) target = this.forced;
    else {
      const k = this._keyWeather();
      if (k) {
        const now = performance.now();
        if (this._roll.key !== `${this.game.world.info.index}:${k.key}:${k.scene}` || now >= this._roll.until) {
          this._roll = { key: `${this.game.world.info.index}:${k.key}:${k.scene}`, until: k.duration > 0 ? now + k.duration : Infinity, on: Math.random() * 100 < k.rate };
        }
        if (this._roll.on) target = k.scene;
      }
    }
    // the settings can turn weather effects off (options: "weather effect")
    if (this.game.settings?.weather === false) target = 0;
    if (target !== this.scene) {
      // stop emitting and stop the sounds; the new scene starts once the old particles have run out their life
      if (this.emitting) { this.emitting = false; for (const snd of this.sounds) snd.handle?.stop?.(); this.sounds = []; }
      if (!this.emitters.some((e) => e.alive)) this._start(target);
    }
    // particles (file space; the centre follows the player, FUN_011a9900)
    const pl = this.game.player;
    const py = pl.y ?? this.game.world.heightAt(pl.x, pl.z);
    const ground = (x, z) => { try { return this.game.world?.heightAt(x, z) ?? py; } catch { return py; } };
    const dur = (this._keyWeather()?.duration || 0) / 1000;
    this.cycle += dt;
    if (dur > 0 && this.cycle > dur) { this.cycle -= dur; this._scheduleOneShots(dur); }
    for (const e of this.emitters) {
      const sp = e.ctl.pos || [0, 0, 0];
      e.update(dt, { x: pl.x + (sp[0] || 0), y: py + (sp[1] || 0), z: pl.z + (sp[2] || 0) }, ground, this.emitting);
    }
    // one-shot sounds (thunder) inside the scene cycle
    for (const s of this.sounds) {
      if (!s.loop && s.at != null && this.cycle >= s.at && !s.fired) { s.fired = true; this._play(s, false); }
    }
  }

  async _start(scene) {
    this._stop();
    this.scene = scene;
    this.cycle = 0;
    if (!scene) return;
    const def = this.W.scenes?.[scene];
    if (!def) return;
    const token = (this._loading = {});
    const emitters = [], sounds = [];
    for (const ctl of def.controls || []) {
      const unit = this.W.units?.[String(ctl.res || '').toLowerCase()];
      if (!unit) continue;
      if (unit.type === 'sound') {
        const loop = !ctl.random && (ctl.life?.[0] ?? 0) === 0;
        sounds.push({ path: unit.sound.path, vol: (unit.sound.vol ?? 0) / 100, loop, life: ctl.life || [0, 1000], random: !!ctl.random });
      } else {
        const tex = await this._textures(unit);
        const flatTex = unit.flat?.texture ? await this._tex(unit.flat.texture) : null;
        if (token !== this._loading) return;
        emitters.push(new Emitter(this.game, { ...unit, flatTexture: flatTex }, ctl, tex));
      }
    }
    if (token !== this._loading) { for (const e of emitters) e.dispose(); return; }
    this.emitters = emitters;
    this.sounds = sounds;
    this.emitting = true;
    const dur = (this._keyWeather()?.duration || 0) / 1000;
    if (dur > 0) this._scheduleOneShots(dur);
    for (const s of sounds) if (s.loop) this._play(s, true);
    this.game.events?.emit?.('life:weather', { scene, name: this.name });
  }

  _scheduleOneShots(dur) {
    for (const s of this.sounds) {
      if (s.loop) continue;
      const a = (s.life[0] || 0) / 1000, b = (s.life[1] || 1000) / 1000;
      s.at = (s.random ? a + Math.random() * (b - a) : a) * dur;
      s.fired = false;
    }
  }

  _play(s, loop) {
    const audio = this.game.audio;
    if (!audio?.sfx) return;
    Promise.resolve(audio.sfx(s.path, { volume: s.vol, loop })).then((h) => { if (loop) { if (this.sounds.includes(s)) s.handle = h; else h?.stop?.(); } });
  }

  _stop() {
    this._loading = null;
    for (const e of this.emitters) e.dispose();
    this.emitters = [];
    for (const s of this.sounds) s.handle?.stop?.();
    this.sounds = [];
    if (this.scene) this.game.events?.emit?.('life:weather', { scene: 0, name: 'clear' });
    this.scene = 0;
  }

  async _tex(key) {
    if (!key) return null;
    if (!this._texCache.has(key)) {
      this._texCache.set(key, (async () => {
        const t = await this.game.textures?.load?.(key, { repeat: false }).catch(() => null);
        if (t) { t.flipY = false; t.colorSpace = THREE.NoColorSpace; }
        return t || null;
      })());
    }
    return this._texCache.get(key);
  }

  async _textures(unit) {
    if (unit.texture) { const t = await this._tex(unit.texture); return t ? [t] : []; }
    if (unit.tpack) {
      try {
        const txt = await fetchText(unit.tpack);
        let dir = '';
        const files = [];
        for (const line of txt.split(/\r?\n/)) {
          const m = /^\s*(\S+)\s+"([^"]*)"/.exec(line); if (!m) continue;
          if (/^_?texpath$/i.test(m[1])) dir = m[2].replace(/\\/g, '/').toLowerCase();
          else if (/^\d+$/.test(m[1]) && m[2]) files.push(`texture/${dir ? dir + '/' : ''}${m[2].toLowerCase()}`);
        }
        const ts = await Promise.all(files.map((f) => this._tex(f)));
        return ts.filter(Boolean);
      } catch { return []; }
    }
    return [];
  }

  /** Map change: drop the particles (the new map's keys decide again). */
  onMap() { this._stop(); this._roll = { key: null, until: 0, on: false }; }

  dispose() { this._stop(); this._texCache.clear(); }   // textures belong to the shared TextureCache
}
