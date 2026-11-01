// Weather per map: the light key's weather_value (map/light_*.txt: enabled, rate %, scene, duration ms) plays scene
// N of weather effect 100 (property/effect/effectscene.com.txt <cate> 10): 1 rain, 2 snow, 3 sandstorm, 4 shower,
// 5 blossom, 6 festival pollen. Each scene enables some of the effect's units (life.json weather.scenes/units):
//   weather units (effectdata.com/.map `unittype weather`): a particle volume that follows the viewer.
//     startrange    spawn box half-extent around the viewer (X/Z), startposition y = spawn height above him
//     lifetime      particle life ms [min, max]; emitrate particles per 60 Hz tick; maxelementcount cap
//     velocity      start speed [min, max] along spawndirection; gravity = constant acceleration (units/s^2)
//     billboardtype camera (faces the camera) | yaxis (upright streak turned to the camera)
//     blendtype     add | modulate; control scale (t sx sy sz) = particle size, alpha / color keyframes over the
//                   scene timeline; addrotate = random roll (deg); flat* = ground splashes where drops land (rain)
//   sound units (effectdata.snd): sn_rain (40 %, looped while it rains), sn_thunder (control lifetime 500..1000 of
//     the scene with randomstart: one clap at a random moment of the second half of every scene cycle),
//     sn_wind_desert3 (sandstorm).
// A weather key rolls `rate` % once per `duration` ms (rate 100 = always) and fades in/out over 3 s.
// Particles live in THREE space in game.scene (outside the mirrored worldRoot); spawn positions come from the
// FILE-frame player position (x, y, -z).
import * as THREE from 'three';
import { fetchText } from '../../engine/assets.js';

const FADE = 3;                 // s in / out
const TICK = 1 / 60;            // emit rate unit

const VERT = /* glsl */`
attribute vec3 iPos;
attribute vec2 iSize;
attribute float iAlpha;
attribute float iRot;
uniform int mode;
varying vec2 vUv;
varying float vA;
void main() {
  vUv = uv;
  vA = iAlpha;
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
    wp = iPos + vec3(c.x * iSize.x, 0.02, c.y * iSize.y);
  }
  gl_Position = projectionMatrix * viewMatrix * vec4(wp, 1.0);
}`;
const FRAG = /* glsl */`
uniform sampler2D map;
uniform vec3 color;
uniform float opacity;
varying vec2 vUv;
varying float vA;
void main() {
  vec4 t = texture2D(map, vUv);
  float a = t.a * vA * opacity;
  if (a < 0.004) discard;
  gl_FragColor = vec4(t.rgb * color, a);
}`;

/** keyframes [[t, v...], ...] (t 0..999) -> values at u (0..1). */
function keyAt(keys, u, n) {
  if (!keys || !keys.length) return null;
  const t = u * 999;
  if (t <= keys[0][0]) return keys[0].slice(1, 1 + n);
  for (let i = 1; i < keys.length; i++) {
    const a = keys[i - 1], b = keys[i];
    if (t <= b[0]) { const f = (t - a[0]) / Math.max(1e-6, b[0] - a[0]); return a.slice(1, 1 + n).map((v, k) => v + ((b[k + 1] ?? v) - v) * f); }
  }
  return keys[keys.length - 1].slice(1, 1 + n);
}

/** One particle emitter of a weather unit (one GPU draw per texture). */
class Emitter {
  constructor(game, unit, ctl, textures) {
    this.game = game;
    this.u = unit;
    this.ctl = ctl;
    this.max = Math.max(1, Math.min(4000, unit.max || 100));
    this.parts = [];
    this.flat = [];
    this.acc = 0;
    this.meshes = [];
    const mode = unit.billboard === 'yaxis' ? 1 : 0;
    const blending = unit.blend === 'add' ? THREE.AdditiveBlending : THREE.NormalBlending;
    for (const tex of textures.length ? textures : [null]) this.meshes.push(this._mesh(tex, mode, blending, this.max));
    if (unit.flat && unit.flatTexture) {
      const fc = unit.flat.color || [255, 255, 255, 255];
      this.flatMesh = this._mesh(unit.flatTexture, 2, blending, Math.max(1, unit.flat.max || 100), [fc[0] / 255, fc[1] / 255, fc[2] / 255], (fc[3] ?? 255) / 255);
    }
  }

  _mesh(tex, mode, blending, count, col = [1, 1, 1], op = 1) {
    const base = new THREE.PlaneGeometry(1, 1);
    const g = new THREE.InstancedBufferGeometry();
    g.index = base.index;
    g.setAttribute('position', base.getAttribute('position'));
    g.setAttribute('uv', base.getAttribute('uv'));
    const pos = new THREE.InstancedBufferAttribute(new Float32Array(count * 3), 3); pos.setUsage(THREE.DynamicDrawUsage);
    const size = new THREE.InstancedBufferAttribute(new Float32Array(count * 2), 2); size.setUsage(THREE.DynamicDrawUsage);
    const alpha = new THREE.InstancedBufferAttribute(new Float32Array(count), 1); alpha.setUsage(THREE.DynamicDrawUsage);
    const rot = new THREE.InstancedBufferAttribute(new Float32Array(count), 1); rot.setUsage(THREE.DynamicDrawUsage);
    g.setAttribute('iPos', pos); g.setAttribute('iSize', size); g.setAttribute('iAlpha', alpha); g.setAttribute('iRot', rot);
    g.instanceCount = 0;
    const white = new THREE.DataTexture(new Uint8Array([255, 255, 255, 255]), 1, 1); white.needsUpdate = true;
    const mat = new THREE.ShaderMaterial({
      vertexShader: VERT, fragmentShader: FRAG, transparent: true, depthWrite: false, depthTest: true, blending, side: THREE.DoubleSide,
      uniforms: { map: { value: tex || white }, color: { value: new THREE.Color(col[0], col[1], col[2]) }, opacity: { value: op }, mode: { value: mode } },
    });
    const m = new THREE.Mesh(g, mat);
    m.frustumCulled = false;
    m.renderOrder = 900;
    m.name = `weather:${this.u.name}`;
    this.game.scene.add(m);
    return { mesh: m, pos, size, alpha, rot, cap: count, white };
  }

  /** p = viewer THREE position; ground(xThree, zThree) = terrain y; strength 0..1 (fade), u = scene progress 0..1. */
  update(dt, p, ground, strength, u) {
    const U = this.u, ctl = this.ctl;
    const life = U.life?.length ? U.life : [5000, 7000];
    // emit
    if (strength > 0) {
      // continuous emitter: maxelementcount / average lifetime particles per second (effects.md 5.5), so the volume
      // stays at its cap; emitrate only shapes the first second (ramp-up)
      const avgLife = Math.max(0.1, ((life[0] || 1000) + (life[1] || life[0] || 1000)) / 2000);
      this.acc += dt * Math.max(this.max / avgLife, (U.emit || 1) / TICK * 0.25);
      const range = U.range?.length ? U.range : [-30, 30];
      const lo = Math.min(range[0], range[1]), hi = Math.max(range[0], range[1]);
      const half = lo === hi ? Math.abs(hi) : null;
      while (this.acc >= 1 && this.parts.length < this.max) {
        this.acc -= 1;
        const rx = half != null ? (Math.random() * 2 - 1) * half : lo + Math.random() * (hi - lo);
        const rz = half != null ? (Math.random() * 2 - 1) * half : lo + Math.random() * (hi - lo);
        const sp = ctl.pos || [0, 0, 0];
        const v = (U.velocity?.[0] ?? 0.5) + Math.random() * ((U.velocity?.[1] ?? 1) - (U.velocity?.[0] ?? 0.5));
        const d = U.dir?.length ? U.dir : [0, 0, 0];
        this.parts.push({
          x: p.x + rx + sp[0], y: p.y + (sp[1] || 0) + Math.random() * 1.5, z: p.z + rz - (sp[2] || 0),
          vx: d[0] * v, vy: d[1] * v, vz: -(d[2] || 0) * v,
          age: 0, life: (life[0] + Math.random() * Math.max(0, life[1] - life[0])) / 1000,
          rot: (Math.random() * 2 - 1) * ((U.rotate || 0) * Math.PI / 180), spin: (U.rotate ? (Math.random() - 0.5) * 2 : 0),
          tex: Math.floor(Math.random() * this.meshes.length),
        });
      }
      if (this.acc > 4) this.acc = 4;
    } else this.acc = 0;
    // simulate
    const g = U.gravity?.length ? U.gravity : [0, -1, 0];
    const scale = keyAt(ctl.scale, u, 3) || [0.1, 0.1, 0.1];
    const alphaK = keyAt(ctl.alpha, u, 1)?.[0] ?? 1;
    const colK = keyAt(ctl.color, u, 3) || [1, 1, 1];
    const sz = U.size || 1;
    const w = Math.max(0.005, scale[0] * sz * (U.billboard === 'yaxis' ? 1 : 3));
    const h = Math.max(0.005, (U.billboard === 'yaxis' ? scale[2] || scale[1] : scale[1] || scale[0]) * sz * (U.billboard === 'yaxis' ? 1 : 3));
    const counts = this.meshes.map(() => 0);
    for (let i = this.parts.length - 1; i >= 0; i--) {
      const q = this.parts[i];
      q.age += dt;
      // acceleration: the start speed grows by `acceleration` per second along its own direction; gravity is constant
      const ka = 1 + (U.accel || 0) * dt;
      q.vx = q.vx * ka + g[0] * dt; q.vy = q.vy * ka + g[1] * dt; q.vz = q.vz * ka - (g[2] || 0) * dt;
      q.x += q.vx * dt; q.y += q.vy * dt; q.z += q.vz * dt;
      q.rot += q.spin * dt;
      const gy = ground(q.x, q.z);
      if (q.age >= q.life || q.y < gy - 0.2) {
        if (this.flatMesh && q.y < gy + 0.3 && this.flat.length < this.flatMesh.cap && Math.random() < (U.flat.rate ?? 1)) this.flat.push({ x: q.x, y: gy, z: q.z, age: 0 });
        this.parts[i] = this.parts[this.parts.length - 1]; this.parts.pop();
        continue;
      }
    }
    for (const q of this.parts) {
      const m = this.meshes[q.tex] || this.meshes[0];
      const k = counts[q.tex]++;
      if (k >= m.cap) continue;
      const fadeIn = Math.min(1, q.age / 0.25), fadeOut = Math.min(1, (q.life - q.age) / 0.4);
      m.pos.setXYZ(k, q.x, q.y, q.z);
      m.size.setXY(k, w, h);
      m.alpha.setX(k, alphaK * strength * fadeIn * fadeOut);
      m.rot.setX(k, q.rot);
    }
    this.meshes.forEach((m, i) => {
      m.mesh.geometry.instanceCount = Math.min(counts[i], m.cap);
      m.pos.needsUpdate = m.size.needsUpdate = m.alpha.needsUpdate = m.rot.needsUpdate = true;
      m.mesh.material.uniforms.color.value.setRGB(colK[0], colK[1], colK[2]);
    });
    // ground splashes
    if (this.flatMesh) {
      const F = this.flatMesh, fs = U.flat.scale?.[0] || 0.19;
      let n = 0;
      for (let i = this.flat.length - 1; i >= 0; i--) {
        const s = this.flat[i]; s.age += dt;
        if (s.age > 0.35) { this.flat[i] = this.flat[this.flat.length - 1]; this.flat.pop(); continue; }
      }
      for (const s of this.flat) {
        if (n >= F.cap) break;
        const f = s.age / 0.35;
        F.pos.setXYZ(n, s.x, s.y, s.z); F.size.setXY(n, fs * (0.5 + f), fs * (0.5 + f)); F.alpha.setX(n, (1 - f) * strength); F.rot.setX(n, 0);
        n++;
      }
      F.mesh.geometry.instanceCount = n;
      F.pos.needsUpdate = F.size.needsUpdate = F.alpha.needsUpdate = F.rot.needsUpdate = true;
    }
  }

  get alive() { return this.parts.length + this.flat.length; }

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
    this.strength = 0;
    this.want = 0;
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
    return { scene: w.scene, rate: Number(w.rate) || 0, duration: Math.max(10000, Number(w.duration) || 100000), key: env.current.blend?.from ?? 0 };
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
          this._roll = { key: `${this.game.world.info.index}:${k.key}:${k.scene}`, until: now + k.duration, on: Math.random() * 100 < k.rate };
        }
        if (this._roll.on) target = k.scene;
      }
    }
    // the settings can turn weather effects off (options: "weather effect")
    if (this.game.settings?.weather === false) target = 0;
    if (target !== this.scene) {
      this.want = 0;
      if (this.strength <= 0.001) this._start(target);
    } else this.want = this.scene ? 1 : 0;
    const k = dt / FADE;
    this.strength = this.want > this.strength ? Math.min(this.want, this.strength + k) : Math.max(this.want, this.strength - k);
    // particles
    const pl = this.game.player;
    const p = { x: pl.x, y: pl.y ?? this.game.world.heightAt(pl.x, pl.z), z: -pl.z };
    const ground = (x, zThree) => { try { return this.game.world?.heightAt(x, -zThree) ?? p.y; } catch { return p.y; } };
    const dur = (this._keyWeather()?.duration || 100000) / 1000;
    this.cycle += dt;
    if (this.cycle > dur) { this.cycle -= dur; this._scheduleOneShots(dur); }
    const u = Math.min(1, this.cycle / dur);
    for (const e of this.emitters) e.update(dt, p, ground, this.strength, u);
    // sounds
    for (const s of this.sounds) {
      if (s.loop) { if (s.handle?.voice?.gain) s.handle.voice.gain.gain.value = Math.min(1.8, s.vol * this.strength); }
      else if (s.at != null && this.cycle >= s.at && !s.fired && this.strength > 0.5) { s.fired = true; this._play(s, false); }
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
        sounds.push({ path: unit.sound.path, vol: (unit.sound.vol || 100) / 100, loop, life: ctl.life || [0, 1000], random: !!ctl.random });
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
    this._scheduleOneShots((this._keyWeather()?.duration || 100000) / 1000);
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
    Promise.resolve(audio.sfx(s.path, { volume: s.vol * Math.max(0.05, loop ? this.strength || 0.05 : 1), loop })).then((h) => { if (loop) { if (this.sounds.includes(s)) s.handle = h; else h?.stop?.(); } });
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
  onMap() { this._stop(); this.strength = 0; this.want = 0; this._roll = { key: null, until: 0, on: false }; }

  dispose() { this._stop(); this._texCache.clear(); }   // textures belong to the shared TextureCache
}
