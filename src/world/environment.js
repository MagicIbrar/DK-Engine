// Map environment: time of day, ambient + sun (+ back) lights, fog, sky dome with clouds, optional sun shadows.
// Sources (docs/formats/environment.md): map/<EnvironmentFile> light keys (parseEnvironment / sampleEnvironment),
// script/environment/sky_table.txt (sky gradient + cloud texture per sky_type), maplist Clip_Far / OnedayTime.
// The EnvironmentMap panorama (texture/water/skycube*.dds) is the WATER reflection (water.js), not the sky.
//
// Lights and the sky live in game.scene, OUTSIDE the mirrored worldRoot: FILE directions are converted with
// fileToThree (x, y, -z). Light intensities are PI so that three's Lambert BRDF (diffuse / PI) gives the D3D9
// fixed-function result diffuse x (ambient + sunColour x N.L); colours are raw 0..1 values (no colour management).
import * as THREE from 'three';
import { parseEnvironment, sampleEnvironment, parseSkyTable, DAY_UNITS } from '../formats/environment.js';
import { fetchText } from '../engine/assets.js';
import { loadTexture } from './texload.js';
import '../engine/fog-model.js';   // the client's range + linear fog (data/binary/*.fx GetFogLinear), before any program compiles
import { SKY_DIFFUSE } from '../engine/material-constants.js';

let skyTablePromise = null;
function loadSkyTable() {
  if (!skyTablePromise) skyTablePromise = fetchText('script/environment/sky_table.txt').then(parseSkyTable).catch(() => []);
  return skyTablePromise;
}

export const SKY_VERTEX = /* glsl */`
varying vec3 vDir;
void main() {
  vDir = position;
  vec4 p = projectionMatrix * vec4(mat3(viewMatrix) * position, 1.0);
  gl_Position = p.xyww; // on the far plane
}`;

// data/binary/skybox.fx technique Skybox: COLOR0 = vertex.color x globalColor (SKY_DIFFUSE), Texture[0] = the sky gradient,
// Texture[1] = the cloud layer, no pixel shader. The stage ops are set by the exe: ENGINE-CHOSEN in material-constants.js
// (SKY_STAGE_OPS: stage 0 MODULATE(sky, diffuse), stage 1 BLENDTEXTUREALPHA(cloud)); nothing is added on top.
export const SKY_FRAGMENT = /* glsl */`
uniform vec3 skyDiffuse;
uniform sampler2D skyA;
uniform sampler2D skyB;
uniform float skyMix;
uniform float hasSky;
uniform sampler2D cloudTex;
uniform float cloudAlpha;
uniform vec2 cloudOffset;
uniform vec3 horizonColor;
varying vec3 vDir;
void main() {
  vec3 d = normalize(vDir);
  float elev = asin(clamp(d.y, -1.0, 1.0));
  // sky_*.dds: 512x256 gradient, row 0 = zenith, row 128 = horizon, alpha fades out below the horizon
  // (the gradient is horizontally uniform: a fixed u avoids the atan() seam)
  vec2 uv = vec2(0.5, clamp(0.5 - elev / 3.14159265, 0.002, 0.998));
  vec4 s = mix(texture2D(skyA, uv), texture2D(skyB, uv), skyMix);
  vec3 col = mix(horizonColor, s.rgb * skyDiffuse, s.a * hasSky);
  // cloud layer: plane projection, fades towards the horizon
  if (d.y > 0.0) {
    vec2 cuv = d.xz / (d.y + 0.25) * 0.35 + cloudOffset;
    vec4 c = texture2D(cloudTex, cuv);
    float a = c.a * cloudAlpha * smoothstep(0.02, 0.3, d.y);
    col = mix(col, c.rgb, a);   // BLENDTEXTUREALPHA (the old + 0.25 x alpha lift is not in skybox.fx)
  }
  gl_FragColor = vec4(col, 1.0);
}`;

export class Environment {
  /**
   * @param {object} game   game.scene (+ optional game.settings, game.cam)
   * @param {{envInfo:object, row:object}} opts  envInfo = environment.js mapEnvironmentInfo(row)
   */
  constructor(game, { envInfo, row, lightText = null }) {
    this.game = game;
    this.scene = game.scene;
    this.info = envInfo;
    this.row = row;
    this.lightText = lightText;  // light file text supplied in memory (custom maps, src/systems/mapbuilder)
    this.env = null;
    this.skyTable = [];
    this.dayMinutes = envInfo.onedayMinutes || 90;
    this.clipFar = envInfo.clipFar || 75;
    this.time = 100000;          // game time 0..240000 (10:00)
    this.timeScale = 1;          // multiplier on the real-time day length
    this.fixedTime = null;       // set a number to freeze the clock
    this.current = null;         // last sampleEnvironment() result
    this._objs = [];
    this._skyTex = new Map();    // sky_type -> Promise<Texture|null>
    this._prev = { background: this.scene.background, fog: this.scene.fog };
    this._cloudOffset = new THREE.Vector2();
    this.fogScale = 1;
  }

  async load() {
    const info = this.info;
    const [envText, skyTable] = await Promise.all([
      (async () => {
        if (typeof this.lightText === 'string' && this.lightText.trim()) return this.lightText;
        for (const k of [info.environmentFile, info.environmentFile && info.environmentFile.replace(/_\d+\.txt$/, '.txt'), 'map/light_braiken.txt']) {
          if (!k) continue;
          try { return await fetchText(k); } catch { /* next */ }
        }
        return '';
      })(),
      loadSkyTable(),
    ]);
    this.env = parseEnvironment(envText);
    this.skyTable = skyTable;

    // lights
    this.ambient = new THREE.AmbientLight(0xffffff, Math.PI);
    this.sun = new THREE.DirectionalLight(0xffffff, Math.PI);
    this.sun.name = 'sun';
    this.back = new THREE.DirectionalLight(0x000000, Math.PI);
    this.back.name = 'backlight';
    this.back.visible = false;
    this.scene.add(this.ambient, this.sun, this.sun.target, this.back, this.back.target);
    this._objs.push(this.ambient, this.sun, this.sun.target, this.back, this.back.target);
    this._setupShadows();

    // fog + sky
    this.fog = new THREE.Fog(0x808080, 30, 60);
    this.scene.fog = this.fog;
    this.scene.background = new THREE.Color(0x808080);

    const grey = new THREE.DataTexture(new Uint8Array([128, 128, 128, 0]), 1, 1);
    grey.needsUpdate = true;
    this._grey = grey;
    this.skyUniforms = {
      skyA: { value: grey }, skyB: { value: grey }, skyMix: { value: 0 }, hasSky: { value: 0 },
      cloudTex: { value: grey }, cloudAlpha: { value: 0 }, cloudOffset: { value: this._cloudOffset },
      horizonColor: { value: new THREE.Color(0x808080) },
      skyDiffuse: { value: new THREE.Color(SKY_DIFFUSE, SKY_DIFFUSE, SKY_DIFFUSE) },
    };
    const skyMat = new THREE.ShaderMaterial({
      vertexShader: SKY_VERTEX, fragmentShader: SKY_FRAGMENT, uniforms: this.skyUniforms,
      depthWrite: false, depthTest: true, side: THREE.BackSide, fog: false,
    });
    skyMat.name = 'sky';
    this.sky = new THREE.Mesh(new THREE.SphereGeometry(10, 32, 16), skyMat);
    this.sky.name = 'sky';
    this.sky.frustumCulled = false;
    this.sky.renderOrder = -1000;
    this.scene.add(this.sky);
    this._objs.push(this.sky);

    // preload the sky textures of every key
    const types = new Set(this.env.keys.map(k => k.sky?.type ?? 0));
    await Promise.all([...types].map(t => this._skyTexture(t)));
    const cloudKeys = new Set([...types].map(t => this.skyTable[t]?.cloud).filter(Boolean));
    this._cloudTex = new Map();
    await Promise.all([...cloudKeys].map(async k => this._cloudTex.set(k, await loadTexture(this.game, [k]))));
    this.update(0, null);
  }

  _skyTexture(type) {
    if (!this._skyTex.has(type)) {
      const row = this.skyTable[type];
      this._skyTex.set(type, row && row.sky ? loadTexture(this.game, [row.sky], { repeat: true }) : Promise.resolve(null));
      this._skyTex.get(type).then(t => { this._skyTexResolved = this._skyTexResolved || new Map(); this._skyTexResolved.set(type, t); });
    }
    return this._skyTex.get(type);
  }

  _setupShadows() {
    const s = this.sun;
    s.castShadow = !!this.game.settings?.shadows;
    s.shadow.mapSize.set(2048, 2048);
    const cam = s.shadow.camera;
    cam.left = -32; cam.right = 32; cam.top = 32; cam.bottom = -32; cam.near = 1; cam.far = 400;
    s.shadow.bias = -0.0006;
    s.shadow.normalBias = 0.04;
  }

  /**
   * Current view distance in world units: Clip_Far x settings.drawDistance. The graphics governor's drawScale is
   * NOT applied: it shortened Clip_Far but not the fog, so props, terrain and actors were cut inside the unfogged range
   * (pop-in). Fog and view distance both scale with the player's draw-distance option only.
   */
  get viewDistance() {
    const dd = Number(this.game.settings?.drawDistance) || 1;
    return this.clipFar * dd;
  }

  /** Fog end in world units (objects beyond it are invisible against the fogged background). */
  get fogEnd() { return this.fog ? this.fog.far : this.viewDistance; }

  /** Game time as hours (0..24). */
  get hour() { return (this.time / DAY_UNITS) * 24; }
  setHour(h) { this.time = ((h % 24 + 24) % 24) * (DAY_UNITS / 24); }

  /**
   * @param {number} dt seconds
   * @param {THREE.Vector3|null} focus  THREE-space point the camera looks at (shadow centre); null = camera
   */
  update(dt, focus = null, camPos = null) {
    if (!this.env) return;
    if (this.fixedTime != null) this.time = this.fixedTime;
    else this.time = (this.time + dt * this.timeScale * (DAY_UNITS / (this.dayMinutes * 60))) % DAY_UNITS;
    const e = sampleEnvironment(this.env, this.time);
    this.current = e;
    const keys = this.env.keys;
    const dd = Number(this.game.settings?.drawDistance) || 1;

    this.ambient.color.setRGB(e.ambient[0], e.ambient[1], e.ambient[2]);
    this.sun.color.setRGB(e.sunColor[0], e.sunColor[1], e.sunColor[2]);
    const fc = e.fog.color;
    this.fog.color.setRGB(fc[0], fc[1], fc[2]);
    const fogScale = dd * this.fogScale;
    let near = e.fog.start * fogScale, far = e.fog.end * fogScale;
    if (!(far > near)) far = near + 1;
    this.fog.near = near; this.fog.far = far;
    this.scene.background.copy(this.fog.color);
    this.skyUniforms.horizonColor.value.copy(this.fog.color);

    // camera far plane: at least the fog end and the view distance
    const cam = this.game.camera;
    if (cam && cam.isPerspectiveCamera) {
      const want = Math.max(this.viewDistance, far) * 1.15 + 20;
      if (Math.abs(cam.far - want) > 1) { cam.far = want; cam.updateProjectionMatrix(); }
    }

    // sun direction (FILE frame, points towards the light) -> three
    const c = focus || camPos || this.game.camera?.position || new THREE.Vector3();
    const dir = new THREE.Vector3(e.sunDir[0], e.sunDir[1], -e.sunDir[2]).normalize();
    const dist = Math.min(150, Math.max(40, e.lightDistance || 100));
    this.sun.target.position.copy(c);
    this.sun.position.copy(c).addScaledVector(dir, dist);
    // snap the shadow centre to texels to avoid shimmering
    this.sun.castShadow = !!this.game.settings?.shadows;
    this.sun.target.updateMatrixWorld();
    const b = e.backColor || (keys[e.blend?.from ?? 0]?.backColor);
    const bd = keys[e.blend?.from ?? 0]?.backDir;
    if (b && bd && (b[0] + b[1] + b[2]) > 0.001 && (bd[0] || bd[1] || bd[2])) {
      this.back.visible = true;
      this.back.color.setRGB(b[0], b[1], b[2]);
      this.back.target.position.copy(c);
      this.back.position.copy(c).add(new THREE.Vector3(bd[0], bd[1], -bd[2]).normalize().multiplyScalar(50));
    } else this.back.visible = false;

    // sky: crossfade between the sky types of the surrounding keys
    const ka = keys[e.blend?.from ?? 0] || keys[0], kb = keys[e.blend?.to ?? 0] || ka;
    const ta = this._skyTexResolved?.get(ka?.sky?.type ?? 0) || null;
    const tb = this._skyTexResolved?.get(kb?.sky?.type ?? 0) || ta;
    const u = this.skyUniforms;
    u.skyA.value = ta || this._grey;
    u.skyB.value = tb || ta || this._grey;
    u.skyMix.value = tb && ta && tb !== ta ? (e.blend?.t || 0) : 0;
    u.hasSky.value = ta ? 1 : 0;
    const cloudKey = this.skyTable[ka?.sky?.type ?? 0]?.cloud;
    const ct = cloudKey ? this._cloudTex?.get(cloudKey) : null;
    const craw = ka?.cloud?.raw || [];
    u.cloudTex.value = ct || this._grey;
    u.cloudAlpha.value = ct ? Math.max(0, Math.min(1, (craw[3] ?? 255) / 255)) : 0;
    const speed = 0.004 * (craw[2] || 1);
    this._cloudOffset.x += dt * speed;
    this._cloudOffset.y += dt * speed * 0.35;
    if (camPos) this.sky.position.copy(camPos);
  }

  dispose() {
    for (const o of this._objs) o.removeFromParent();
    this.sun?.shadow?.map?.dispose();
    this.sun?.dispose?.(); this.back?.dispose?.();
    this.sky?.geometry.dispose(); this.sky?.material.dispose();
    this._grey?.dispose();
    // sky / cloud textures are cached (TextureCache): free the GPU copies only
    for (const t of this._skyTexResolved?.values() || []) t?.dispose();
    for (const t of this._cloudTex?.values() || []) t?.dispose();
    if (this.scene.fog === this.fog) this.scene.fog = this._prev.fog || null;
    if (this.scene.background && this._prev.background !== undefined) this.scene.background = this._prev.background;
    this._objs = [];
  }
}
