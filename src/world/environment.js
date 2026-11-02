// Map environment: time of day, ambient + sun (+ back) lights, fog, sky dome with clouds, optional sun shadows.
// Sources (docs/formats/environment.md): map/<EnvironmentFile> light keys (parseEnvironment / sampleEnvironment),
// script/environment/sky_table.txt (sky gradient + cloud texture + FLARE index per sky_type),
// script/environment/sky.txt (lens-flare sets keyed by that FLARE index), maplist Clip_Far / OnedayTime.
// The EnvironmentMap panorama (texture/water/skycube*.dds) is the WATER reflection (water.js), not the sky.
//
// Lights and the sky live in game.scene, OUTSIDE the mirrored worldRoot: FILE directions are converted with
// fileToThree (x, y, -z). Light intensities are PI so that three's Lambert BRDF (diffuse / PI) gives the D3D9
// fixed-function result diffuse x (ambient + sunColour x N.L); colours are raw 0..1 values (no colour management).
import * as THREE from 'three';
import { parseEnvironment, sampleEnvironment, parseSkyTable, parseSkyEffects, DAY_UNITS, stepGlobalFog, globalSkyType, stepGlobalCloud, GLOBAL_SKY_FADE_MS } from '../formats/environment.js';
import { fetchText } from '../engine/assets.js';
import { loadTexture } from './texload.js';
import { underwaterFog, globalFogGuard, setGlobalFogCenter } from '../engine/fog-model.js';   // the client's range + linear fog (data/binary/*.fx GetFogLinear), before any program compiles
import { SKY_DIFFUSE } from '../engine/material-constants.js';
import { GlobalEffectLights, envIntensities } from './global-effect-light.js';
import { Lensflare, LensflareElement } from 'three/addons/objects/Lensflare.js';
import { globalShadowFit, toThreeShadowMatrix } from './shadow-fit.js';

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
    this.current = null;         // last sampleEnvironment() result (with the Global effect-light override applied)
    this.base = null;            // last sampleEnvironment() result before the effect-light override
    // LANE-54 pass 4: Global DollStage::Environment::Element::Light receiver (global-effect-light.js). Map (.mel cate 9) and
    // effect-scene light units post LightStart / LightStop here through game.effectLights.
    this.effectLights = new GlobalEffectLights();
    game.effectLights = this.effectLights;
    this._objs = [];
    this._skyTex = new Map();    // sky_type -> Promise<Texture|null>
    this._prev = { background: this.scene.background, fog: this.scene.fog };
    this._cloudOffset = new THREE.Vector2();
    this.fogScale = 1;
    this._skyEffects = [];          // parseSkyEffects(sky.txt), indexed by timeofday (= sky_table.flare)
    this._flareTex = new Map();      // texture key -> THREE.Texture
    this._lensflare = null;          // current three.js Lensflare mesh
    this._flareSet = -1;             // last applied sky_table.flare index
    this._sunWorld = new THREE.Vector3();
    this._sunDir = new THREE.Vector3();
    this._sunBeams = null;           // THREE.Group of Global-style volumetric shafts / corona
    this._sunBeamShafts = [];
    this._sunBeamTex = null;         // { shaft, glow, soft } from Global REA textures
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
    await this._loadSkyEffects();
    await this._loadSunBeams();
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
    // Global RenderTexture::Shadow size for the Options level (hud-options apply.js); 512 = Global option.txt shadowlevel 2
    const ms = Number(this.game.settings?.shadowMapSize) > 0 ? Number(this.game.settings.shadowMapSize) : 512;
    s.shadow.mapSize.set(ms, ms);
    // Framing = Global FUN_01541680 (src/world/shadow-fit.js): update() computes the light clip matrix each frame and
    // updateMatrices installs it instead of three's look-at + orthographic box (the old +-32 box / 400 far are gone).
    const shadow = s.shadow, orig = shadow.updateMatrices.bind(shadow), env = this;
    shadow.updateMatrices = function (light, vp) {
      const K = env._shadowClip;
      if (!K) return orig(light, vp);
      const cam = this.camera;
      cam.matrixWorld.identity(); cam.matrixWorldInverse.identity();
      cam.projectionMatrix.copy(K); cam.projectionMatrixInverse.copy(K).invert();
      this._frustum.setFromProjectionMatrix(K);
      this.matrix.set(0.5, 0, 0, 0.5, 0, 0.5, 0, 0.5, 0, 0, 0.5, 0.5, 0, 0, 0, 1).multiply(K);
    };
    // [judgment, LANE-66 rev c] Global compares depth - g_fShadowBias (geometry.fx / boneshadowanimation.fx); the exe's
    // value was not traced, so the WebGL depth / normal offsets stay as before.
    s.shadow.bias = -0.0006;
    s.shadow.normalBias = 0.04;
  }

  /** Global shadow level (rc_shadowlevel) from the applied map size: 256 -> 1, 512 -> 2, 1024 -> 3 (apply.js). */
  _shadowLevel() {
    const ms = Number(this.game.settings?.shadowMapSize) || this.sun?.shadow?.mapSize?.x || 512;
    return ms >= 1024 ? 3 : ms >= 512 ? 2 : 1;
  }

  /** Scene box of the shadow fit (FILE frame): the map extent and its terrain height range (cached per map). */
  _shadowBounds() {
    const m = this.game.world?.map;
    if (!m || !m.heights) return null;
    if (this._sbMap !== m) {
      let lo = Infinity, hi = -Infinity;
      for (let i = 0; i < m.heights.length; i++) { const h = m.heights[i]; if (h < lo) lo = h; if (h > hi) hi = h; }
      this._sbMap = m;
      this._sb = { maxX: m.width, maxZ: m.height, minY: lo, maxY: hi };
    }
    return this._sb;
  }

  /** FUN_01541680 framing for this frame (three clip matrix or null). focus / camPos are three-space points. */
  _fitShadow(focus, camPos, dirFile) {
    const cam = this.game.camera;
    const bounds = this._shadowBounds();
    if (!focus || !camPos || !cam || !cam.isPerspectiveCamera || !bounds) return null;
    cam.updateMatrixWorld();
    // the main camera's view in the FILE frame (LH): three view x mirror, z negated for the LH forward axis
    const V = new THREE.Matrix4().multiplyMatrices(cam.matrixWorldInverse, new THREE.Matrix4().makeScale(1, 1, -1));
    V.premultiply(new THREE.Matrix4().makeScale(1, 1, -1));
    const e = V.elements;   // column-major THREE = row-vector D3D layout
    const fit = globalShadowFit({
      level: this._shadowLevel(),
      target: [focus.x, focus.y, -focus.z], camPos: [camPos.x, camPos.y, -camPos.z], lightDir: dirFile,
      bounds, camView: Array.from(e), camNear: cam.near, fovy: cam.fov * Math.PI / 180,
    });
    if (!fit || !fit.matrix.every(Number.isFinite)) return null;
    this.shadowFit = fit;
    return new THREE.Matrix4().set(...toThreeShadowMatrix(fit.matrix));
  }

  /**
   * Current view distance in world units: Clip_Far x settings.drawDistance. The graphics governor's drawScale is
   * NOT applied: it shortened Clip_Far but not the fog, so props, terrain and actors were cut inside the unfogged range
   * (pop-in). Fog and view distance both scale with the player's draw-distance option only.
   */
  // GLOBAL-HARD-CHECK (coordinate w/ graphics worker): fog = light fog_value x settings.drawDistance;
  // viewDistance = Clip_Far x drawDistance; do NOT invent fog stretch / draw multipliers here (ENV-001/002).
  get viewDistance() {
    const dd = Number(this.game.settings?.drawDistance) || 1;
    return this.clipFar * dd;
  }

  /** Fog end in world units (objects beyond it are invisible against the fogged background). */
  // LANE-66: a reversed Global key (far < near) fogs only what is NEARER than far and is clear beyond near, so it hides
  // nothing at range: culling falls back to the view distance.
  get fogEnd() { return this.fog ? (this.fog.far > this.fog.near ? this.fog.far : this.viewDistance) : this.viewDistance; }

  /** Game time as hours (0..24). */
  get hour() { return (this.time / DAY_UNITS) * 24; }
  setHour(h) { this.time = ((h % 24 + 24) % 24) * (DAY_UNITS / 24); }

  /**
   * @param {number} dt seconds
   * @param {THREE.Vector3|null} focus  THREE-space point the camera looks at (shadow centre); null = camera
   */
  /** script/environment/sky.txt lens-flare sets (Global REA). Missing file => no flares. */
  async _loadSkyEffects() {
    try {
      const text = await fetchText('script/environment/sky.txt');
      this._skyEffects = parseSkyEffects(text) || [];
    } catch {
      this._skyEffects = [];
      return;
    }
    const keys = new Set();
    for (const set of this._skyEffects) {
      if (!set?.textures) continue;
      for (const t of set.textures) if (t) keys.add(t);
    }
    await Promise.all([...keys].map(async k => {
      const tex = await loadTexture(this.game, [k], { repeat: false });
      if (tex) {
        tex.wrapS = tex.wrapT = THREE.ClampToEdgeWrapping;
        tex.generateMipmaps = false;
        tex.minFilter = THREE.LinearFilter;
        tex.magFilter = THREE.LinearFilter;
        tex.needsUpdate = true;
        this._flareTex.set(k, tex);
      }
    }));
  }

  /** Rebuild Lensflare elements for sky_table FLARE index (0 = NONE). */
  _applyFlareSet(flareIndex) {
    const idx = Number(flareIndex) || 0;
    if (idx === this._flareSet) return;
    this._flareSet = idx;
    if (this._lensflare) {
      this._lensflare.removeFromParent();
      const i = this._objs.indexOf(this._lensflare);
      if (i >= 0) this._objs.splice(i, 1);
      this._lensflare = null;
    }
    const set = this._skyEffects[idx];
    if (!set || !set.flares?.length || idx <= 0) return;
    const lf = new Lensflare();
    lf.name = 'sun-lensflare';
    const screen = Math.max(1, this.game.renderer?.domElement?.clientHeight || this.game.renderer?.domElement?.height || 720);
    let added = 0;
    for (const f of set.flares) {
      const texKey = set.textures[f.textureid] || set.textures[0];
      const tex = texKey ? this._flareTex.get(texKey) : null;
      if (!tex) continue;
      // Global size is a fraction of screen height; three.js LensflareElement size is pixels.
      const sizePx = Math.max(1, (Number(f.size) || 0) * screen);
      // Global linepos 1 = at the sun, 0 = opposite through screen centre. three.js distance 0 = light, 1 = opposite.
      const distance = Math.max(0, Math.min(1, 1 - (Number(f.linepos) || 0)));
      const c = f.color || [255, 255, 255];
      const color = new THREE.Color(c[0] / 255, c[1] / 255, c[2] / 255);
      lf.addElement(new LensflareElement(tex, sizePx, distance, color));
      added++;
    }
    if (!added) return;
    this.scene.add(lf);
    this._objs.push(lf);
    this._lensflare = lf;
  }


  /**
   * Global REA volumetric sun beams / god rays (per-map).
   * Scrubbed Global 0.0.1: texture/object/d_sunlight_01.dds is 64x256 (narrow shaft cookie);
   * lighttexture + mapeffect are soft corona cookies. Map cate-9 mel entries are local lights
   * (effectdata unittype=light, e.g. Ardeca 17x light_nun_blue range=30) — not shafts; MapEffects
   * correctly skips cate-9. Shaft angle/strength follow THIS map's light_*.txt sample:
   * dirlight_dir / dirlight_color / bloom / sun elevation — not a single blown-out global fan.
   */
  async _loadSunBeams() {
    const clamp = (tex) => {
      if (!tex) return null;
      tex.wrapS = tex.wrapT = THREE.ClampToEdgeWrapping;
      tex.generateMipmaps = true;
      tex.minFilter = THREE.LinearMipmapLinearFilter;
      tex.magFilter = THREE.LinearFilter;
      tex.needsUpdate = true;
      return tex;
    };
    const [shaft, glow, soft] = await Promise.all([
      loadTexture(this.game, ['texture/object/d_sunlight_01.dds', 'Texture/object/d_sunlight_01.dds'], { repeat: false }),
      loadTexture(this.game, ['texture/lighttexture.dds', 'texture/object/lighttexture+.dds', 'Texture/lighttexture.dds'], { repeat: false }),
      loadTexture(this.game, ['texture/mapeffect.dds', 'texture/effect/monster/n_god_eff01.dds', 'Texture/mapeffect.dds'], { repeat: false }),
    ]);
    this._sunBeamTex = { shaft: clamp(shaft), glow: clamp(glow), soft: clamp(soft) };
    if (!shaft && !glow && !soft) return;

    const mkMat = (map, opacity) => {
      const m = new THREE.MeshBasicMaterial({
        map: map || null,
        color: 0xfff0c8,
        transparent: true,
        opacity,
        blending: THREE.AdditiveBlending,
        depthWrite: false,
        depthTest: true,
        side: THREE.DoubleSide,
        fog: false,
        toneMapped: false,
      });
      m.userData.baseOpacity = opacity;
      return m;
    };

    // REA: 64x256 cookie => keep planes thin (~1:4). Prior 8x wide/hot planes blew out Ardeca.
    // Count 6, tight lateral spread along map sunDir (Ardeca dirlight_dir ~45 deg elev).
    const group = new THREE.Group();
    group.name = 'sun-beams';
    group.visible = false;
    const shafts = [];
    if (this._sunBeamTex.shaft) {
      for (let i = 0; i < 6; i++) {
        const w = 4.5 + (i % 3) * 2.0;          // ENGINE-CHOSEN 2026-10-29: Global Ardeca bands are wide + soft (was 1.6..3.0)
        const h = 48 + (i % 4) * 12;
        const mesh = new THREE.Mesh(
          new THREE.PlaneGeometry(w, h),
          mkMat(this._sunBeamTex.shaft, Number(globalThis.__dkBeamBase) || (0.20 + (i % 3) * 0.06)), // ENGINE-CHOSEN, matched by eye to Global Ardeca 306,126 18:23 (iter3; was 0.038..0.062)
        );
        mesh.frustumCulled = false;
        mesh.renderOrder = -50;
        mesh.userData.lat = (i - 2.5) * 5.5;   /* ENGINE-CHOSEN 2026-10-29 spread across the view; was ((i % 3) - 1) * 1.8 */                 // was ±8.25
        mesh.userData.lat2 = -2 + (i % 2) * 1.5;   /* foot height vs ground (ENGINE-CHOSEN); was (floor(i/3)-0.5)*2 */    // was ±3.5
        mesh.userData.along = 12 + (i % 4) * 5;                  // ENGINE-CHOSEN: 12..27 ahead of the eye (was 42..60 up the sun ray)
        mesh.userData.len = h;
        group.add(mesh);
        shafts.push(mesh);
      }
    }
    if (this._sunBeamTex.glow) {
      const mesh = new THREE.Mesh(new THREE.PlaneGeometry(26, 26), mkMat(this._sunBeamTex.glow, 0.10)); // was 42 @ 0.38
      mesh.name = 'sun-corona';
      mesh.frustumCulled = false;
      mesh.renderOrder = -45;
      group.add(mesh);
    }
    if (this._sunBeamTex.soft) {
      const mesh = new THREE.Mesh(new THREE.PlaneGeometry(36, 36), mkMat(this._sunBeamTex.soft, 0.06)); // was 58 @ 0.24
      mesh.name = 'sun-soft';
      mesh.frustumCulled = false;
      mesh.renderOrder = -46;
      group.add(mesh);
    }
    this.scene.add(group);
    this._objs.push(group);
    this._sunBeams = group;
    this._sunBeamShafts = shafts;
  }

  _updateSunBeams(e, dir, eye) {
    const g = this._sunBeams;
    if (!g) return;
    // Per-map gate from light_*.txt sample (Ardeca: night=false, bloom on, sun ~0.96, elev~0.707).
    const bright = e.sunColor ? (e.sunColor[0] + e.sunColor[1] + e.sunColor[2]) / 3 : 0;
    const elev = dir?.y ?? 0;
    const bloomOn = !!(e.bloom && e.bloom.enabled);
    // Cate-9 local lights do not create shafts; only daytime directional sun does.
    // 2026-10-29 [gfx-parity] Global sky gate: script/environment/sky_table.txt FLARE column of the current light key's sky_type
    // (row 0 = "NONE", flare 0) is where Global draws no sun/lens flare (caves, prisons, Nunvice, Crespo abyss, Tower of Spell ...).
    // The engine-chosen shafts/corona now follow the same gate instead of appearing inside dungeons.
    // OFF SWITCH: globalThis.__dkGfxParity = { sunBeamSkyGate: false }  or  localStorage 'dk.gfx.sunBeamSkyGate' = '0'.
    let skyGate = true;
    try {
      const sw = globalThis.__dkGfxParity?.sunBeamSkyGate ?? (globalThis.localStorage?.getItem?.('dk.gfx.sunBeamSkyGate') === '0' ? false : true);
      if (sw !== false) skyGate = (this._flareIdxNow ?? 1) > 0;
    } catch { /* storage unavailable: keep the gate */ skyGate = (this._flareIdxNow ?? 1) > 0; }
    const on = bright > 0.14 && elev > 0.18 && skyGate;
    g.visible = on;
    if (!on) return;

    const col = new THREE.Color(
      Math.min(1, e.sunColor[0] * 1.02),
      Math.min(1, e.sunColor[1] * 1.0),
      Math.min(1, e.sunColor[2] * 0.96),
    );
    // Map bloom softens/strengthens slightly; never the old 1.35x blowout.
    const bloomMul = bloomOn ? 1.0 : 0.28;
    const intensity = Math.min(1, bright * 0.72) * bloomMul;
    this._sunDir.copy(dir);

    const right = new THREE.Vector3();
    const face = new THREE.Vector3();
    const worldUp = new THREE.Vector3(0, 1, 0);
    const basis = new THREE.Matrix4();
    // 2026-10-29 [flash-sun] ENGINE-CHOSEN placement (Global draws these from the packed exe; d_sunlight_01 is referenced by
    // no mesh/map/script/texturepack). Shafts now stand IN the view: foot on the ground ahead of the camera, long axis up
    // the map dirlight_dir toward the sun, axial billboard facing the eye - like Global Ardeca's soft diagonal bands.
    // (Before: centred 42..60 units up the sun ray = always above the frame, ~0.02 opacity = invisible.)
    const fwd = new THREE.Vector3(0, 0, -1);
    const camObj = this.game?.camera;
    if (camObj?.getWorldDirection) camObj.getWorldDirection(fwd);
    fwd.y = 0;
    if (fwd.lengthSq() < 1e-6) fwd.set(0, 0, -1);
    fwd.normalize();
    const side = new THREE.Vector3().crossVectors(fwd, worldUp).normalize();
    const toEye = new THREE.Vector3();
    const foot = new THREE.Vector3();
    const groundY = Number.isFinite(this._beamGroundY) ? this._beamGroundY : eye.y - 8;

    // 2026-10-29 [gfx2-env screen-shafts] Global's sun rays are PLACED map objects (script/object/field_extra.csv pt_light01/02,
    // cs_light; e.g. 14 in ardeca_halloween.mol around the plaza), now drawn additively by world/objects.js. The recording
    // (global-gfx-session2.mkv) shows rays only in the Ardeca plaza (t=121..160 s), none in the fields/road/lake facing the same
    // sun (t=40..96, 170 s), while these ENGINE-CHOSEN view-anchored shafts appeared at every yaw. Hidden by default; corona/soft
    // glow below unchanged. OFF SWITCH (restore the old shafts): globalThis.__dkGfxParity = { screenSunShafts: true }  or
    // localStorage 'dk.gfx.screenSunShafts' = '1'.
    let screenShafts = false;
    try {
      const v = globalThis.__dkGfxParity?.screenSunShafts;
      screenShafts = v != null ? !!v : globalThis.localStorage?.getItem?.('dk.gfx.screenSunShafts') === '1';
    } catch { /* keep hidden */ }
    for (const mesh of this._sunBeamShafts) {
      mesh.visible = screenShafts;
      if (!screenShafts) continue;
      const along = mesh.userData.along || 40;
      const lat = mesh.userData.lat || 0;
      const lat2 = mesh.userData.lat2 || 0;
      // Long axis = map sunDir (FILE->three already applied by caller). Tight lat keeps pitch REA.
      right.crossVectors(dir, worldUp);
      if (right.lengthSq() < 1e-8) right.crossVectors(dir, new THREE.Vector3(1, 0, 0));
      right.normalize();
      face.crossVectors(right, dir).normalize();
      const len = mesh.userData.len || 60;
      foot.copy(eye).addScaledVector(fwd, along).addScaledVector(side, lat);
      foot.y = groundY + lat2;
      mesh.position.copy(foot).addScaledVector(dir, len * 0.5);
      toEye.subVectors(eye, mesh.position).normalize();
      right.crossVectors(dir, toEye);
      if (right.lengthSq() < 1e-8) right.crossVectors(dir, worldUp);
      right.normalize();
      face.crossVectors(right, dir).normalize();
      // PlaneGeometry XY: Y = long axis along sunDir, X = right, normal = face (toward the eye)
      basis.makeBasis(right, dir, face);
      mesh.quaternion.setFromRotationMatrix(basis);
      if (mesh.material) {
        mesh.material.color.copy(col);
        mesh.material.opacity = (mesh.material.userData.baseOpacity || 0.04) * (0.28 + intensity * 0.42);
      }
    }

    for (const name of ['sun-corona', 'sun-soft']) {
      const mesh = g.getObjectByName(name);
      if (!mesh) continue;
      mesh.position.copy(this._sunWorld);
      mesh.lookAt(eye);
      if (mesh.material) {
        mesh.material.color.copy(col);
        const base = mesh.material.userData.baseOpacity || 0.08;
        mesh.material.opacity = base * (0.30 + intensity * 0.40);
      }
    }
  }


  update(dt, focus = null, camPos = null) {
    if (!this.env) return;
    if (this.fixedTime != null) this.time = this.fixedTime;
    else this.time = (this.time + dt * this.timeScale * (DAY_UNITS / (this.dayMinutes * 60))) % DAY_UNITS;
    const base = sampleEnvironment(this.env, this.time);
    // Global effect light (FUN_7ff671243b40 tick + FUN_7ff6712436b0 apply): distance from the camera look-at target
    // (CameraImpl+0x70 = game.cam.target = focus), nearest active record overrides ambient / directional colour, shade
    // distance + centre and (fog_enable) fog with its fade weight. LANE-54 pass 5: colour x intensity (CEnvironment {rgb, w},
    // base 1.0; g_f3ColorWithIntensity in boneanimation.fx / geometry.fx); the bloom block is applied by graphics/index.js.
    const viewer = focus || camPos || this.game.camera?.position || null;
    this.effectLights.tick(Math.max(0, dt) * 1000, viewer);
    const e = this.effectLights.blend(base);
    this.base = base;
    this.current = e;
    const keys = this.env.keys;
    const dd = Number(this.game.settings?.drawDistance) || 1;

    const ei = envIntensities(e);
    this.ambient.color.setRGB(e.ambient[0] * ei.ambient, e.ambient[1] * ei.ambient, e.ambient[2] * ei.ambient);
    this.sun.color.setRGB(e.sunColor[0] * ei.dir, e.sunColor[1] * ei.dir, e.sunColor[2] * ei.dir);
    // LANE-66 Global fog (decompile/32-bit-main, Environment::Provider FUN_0081d010/FUN_0081ddd0 and the
    // CRenderCore fog setter FUN_0151b680; fog-model.js has the shader side):
    //  - the scene fog follows the CURRENT key, approached from the last sent fog (stepGlobalFog), not a lerp to the next key;
    //  - fog_value near = first, far = second; an authored reversed pair (near > far) gets far = near + 1.0 on the key fog
    //    (FUN_011bcae0 @011bcbb8 / 64-bit FUN_7ff67129b5d0; globalFogGuard), the underwater fog bypasses it;
    //  - camera eye below the water height of its cell: the exe's underwater fog replaces the key fog (underwaterFog),
    //    except when that cell's water entry is definition type 4 (FloorReflect; world.waterTypeAt);
    //  - fog distance is measured from g_f3FogCenterPos = look-at + (0, 4.0 + env[+0x18], 0) (setGlobalFogCenter).
    // OFF SWITCHES (old behaviour): globalThis.__dkGfxParity = { globalFogStep: false, reversedFogGuard: false, underwaterFog: false, fogCenter: false }.
    const gp = globalThis.__dkGfxParity || {};
    let fogSrc = e.fog;
    if (gp.globalFogStep !== false && e.fogKey) {
      const st = stepGlobalFog(this._fogSent || null, e.fogKey, e.fogDirect ? 1 : (e.blend?.t ?? 1));
      this._fogSent = st.fog;
      fogSrc = st.fog;
    }
    if (gp.reversedFogGuard !== false) {
      const gd = globalFogGuard(fogSrc.start, fogSrc.end);
      if (gd.far !== fogSrc.end) fogSrc = { start: gd.near, end: gd.far, color: fogSrc.color };
    }
    const fogScale = dd * this.fogScale;
    let near = fogSrc.start * fogScale, far = fogSrc.end * fogScale, fc = fogSrc.color;
    this.underwater = false;
    if (gp.underwaterFog !== false) {
      const eyeT = camPos || this.game.camera?.position;
      const lvl = eyeT && typeof this.game.world?.waterLevelAt === 'function' ? this.game.world.waterLevelAt(eyeT.x, -eyeT.z) : null;
      const wty = eyeT && typeof this.game.world?.waterTypeAt === 'function' ? this.game.world.waterTypeAt(eyeT.x, -eyeT.z) : null;
      const uw = eyeT ? underwaterFog(lvl, eyeT.y, wty) : null;   // FILE frame: (x, y, -z) of the three-space eye
      if (uw) { near = uw.near; far = uw.far; fc = uw.color; this.underwater = true; }   // fixed in the exe setter: no draw-distance scale
    }
    const fogLook = focus || null;   // camera look-at target (game.cam.target)
    const fogOff = Number.isFinite(e.fogCenterOffset) ? e.fogCenterOffset : 0;   // env[+0x18]: 0 for map keys (CMapFogMsg FUN_01168fa0)
    setGlobalFogCenter(gp.fogCenter !== false ? fogLook : null, fogOff);
    this.fog.color.setRGB(fc[0], fc[1], fc[2]);
    this.fog.near = near; this.fog.far = far;
    // ENGINE-DEFAULT (configurable), scan-fix 2026-10-29: on keys with no sky (sky_table row 0 NONE / interior rects) the
    // backdrop and dome horizon take the key's fog_color. Global's SkyDome Set (FUN_01586370) only switches the dome; the
    // frame clear colour is set inside the render core and was not recovered (searched: sky.txt, sky_table, light_*.txt,
    // maplist, 32-bit decompile SkyDome/CloudPlane/backcolor). Fog colour is what any fully fogged distance shows in Global.
    this.scene.background.copy(this.fog.color);
    this.skyUniforms.horizonColor.value.copy(this.fog.color);

    // camera far plane: at least the fog end and the view distance
    const cam = this.game.camera;
    if (cam && cam.isPerspectiveCamera) {
      const want = Math.max(this.viewDistance, near, far) * 1.15 + 20;   // reversed fog: near is the clear-from range
      if (Math.abs(cam.far - want) > 1) { cam.far = want; cam.updateProjectionMatrix(); }
    }

    // sun direction (FILE frame, points towards the light) -> three
    const c = focus || camPos || this.game.camera?.position || new THREE.Vector3();
    const dir = new THREE.Vector3(e.sunDir[0], e.sunDir[1], -e.sunDir[2]).normalize();
    // lens-flare / sun-beam placement distance (unchanged; not the shadow framing)
    const dist = Math.min(150, Math.max(40, base.lightDistance || 100));
    // shadow framing: Global FUN_01541680 (shadow-fit.js). Light eye = look-at target + L x |camera - target|.
    const eyeNow = camPos || this.game.camera?.position || c;
    const dFit = Math.max(1e-3, eyeNow.distanceTo ? eyeNow.distanceTo(c) : 0);
    this.sun.target.position.copy(c);
    this.sun.position.copy(c).addScaledVector(dir, dFit);
    this.sun.castShadow = !!this.game.settings?.shadows;
    this._shadowClip = this.sun.castShadow ? this._fitShadow(c, eyeNow, [e.sunDir[0], e.sunDir[1], e.sunDir[2]]) : null;
    if (!this._shadowClip) this.sun.castShadow = false;   // no Global framing this frame (no map / eye on the target)
    this.sun.target.updateMatrixWorld();
    // Lens flares: authored in sky.txt, selected by sky_table FLARE for the current sky_type.
    const keyNow = this.env.keys[e.blend?.from ?? 0] || this.env.keys[0];
    // Global sky packet: the current key's sky_type, 0 inside an interior rect of the light file (camera focus, FILE frame)
    const skyType = globalSkyType(this.env, keyNow, c.x, -c.z);
    const flareIdx = this.skyTable[skyType]?.flare ?? 0;
    this._applyFlareSet(flareIdx);
    this._flareIdxNow = flareIdx;   // [gfx-parity] sun-beam sky gate (see _updateSunBeams)
    {
      const eye = camPos || this.game.camera?.position || c;
      // Keep the sun INSIDE the far plane: three's Lensflare occlusion test (and the depth-tested corona) fail for points past
      // camera.far, so the Global sky.txt sun never drew when looked at (sun was at 150, far 106 on map 150).
      const sunFar = cam && cam.isPerspectiveCamera ? cam.far * 0.92 : Infinity;
      this._sunWorld.copy(eye).addScaledVector(dir, Math.min(Math.max(dist, this.viewDistance || 200), sunFar));
      if (this._lensflare) {
        this._lensflare.position.copy(this._sunWorld);
        this._lensflare.visible = !!(e.sunColor && (e.sunColor[0] + e.sunColor[1] + e.sunColor[2]) > 0.05);
      }
      this._beamGroundY = focus && Number.isFinite(focus.y) ? focus.y : NaN;   // shaft feet on the player's ground (ENGINE-CHOSEN)
      this._updateSunBeams(e, dir, eye);
    }
    const b = e.backColor || (keys[e.blend?.from ?? 0]?.backColor);
    const bd = keys[e.blend?.from ?? 0]?.backDir;
    // LANE-66: Global parses dirbacklight_dir/_color but never applies them: the provider's apply (FUN_0081ddd0) sends only
    // dirlight_dir, dirlight_color, ambient_color and lightdistance to the light manager, and its key interpolation
    // (FUN_0081d010) leaves the back-light slots at their constructor defaults. OFF SWITCH: __dkGfxParity.backLight = true.
    if (gp.backLight === true && b && bd && (b[0] + b[1] + b[2]) > 0.001 && (bd[0] || bd[1] || bd[2])) {
      this.back.visible = true;
      this.back.color.setRGB(b[0], b[1], b[2]);
      this.back.target.position.copy(c);
      this.back.position.copy(c).add(new THREE.Vector3(bd[0], bd[1], -bd[2]).normalize().multiplyScalar(50));
    } else this.back.visible = false;

    // sky (LANE-66, Global SkyDome / CloudPlane Set FUN_01586370 / FUN_015875d0): the current key's sky_type (0 inside an
    // interior rect); a change starts a Blender (FUN_0159c000) of GLOBAL_SKY_FADE_MS = 10 ms (the 10000 ms branch needs
    // QMap +0xbd, which is only ever 0), so key changes switch the sky instead of crossfading over the key interval.
    if (this._skyNow === undefined) { this._skyNow = skyType; this._skyFrom = skyType; this._skyFade = 1; }
    else if (skyType !== this._skyNow) { this._skyFrom = this._skyNow; this._skyNow = skyType; this._skyFade = 0; }
    if (this._skyFade < 1) this._skyFade = Math.min(1, this._skyFade + Math.max(0, dt) * 1000 / GLOBAL_SKY_FADE_MS);
    const ta = this._skyTexResolved?.get(this._skyFade < 1 ? this._skyFrom : this._skyNow) || null;
    const tb = this._skyTexResolved?.get(this._skyNow) || null;
    const u = this.skyUniforms;
    u.skyA.value = ta || tb || this._grey;
    u.skyB.value = tb || ta || this._grey;
    u.skyMix.value = this._skyFade < 1 && ta && tb && ta !== tb ? this._skyFade : 0;
    u.hasSky.value = ta || tb ? 1 : 0;
    const cloudKey = this.skyTable[this._skyNow]?.cloud;
    const ct = cloudKey ? this._cloudTex?.get(cloudKey) : null;
    const craw = keyNow?.cloud?.raw || [];
    u.cloudTex.value = ct || this._grey;
    u.cloudAlpha.value = ct ? Math.max(0, Math.min(1, (craw[3] ?? 255) / 255)) : 0;
    // CloudPlane scroll (FUN_01586e70): +0.004 UV/s along (1, 0), wrapped; cloud_type does not change the speed
    const co = stepGlobalCloud({ u: this._cloudOffset.x, v: this._cloudOffset.y }, Math.max(0, dt) * 1000);
    this._cloudOffset.set(co.u, co.v);
    if (camPos) this.sky.position.copy(camPos);
  }

  dispose() {
    for (const o of this._objs) o.removeFromParent();
    this.sun?.shadow?.map?.dispose();
    this._shadowClip = null; this._sb = null; this._sbMap = null;
    this.sun?.dispose?.(); this.back?.dispose?.();
    this.sky?.geometry.dispose(); this.sky?.material.dispose();
    this._grey?.dispose();
    // sky / cloud textures are cached (TextureCache): free the GPU copies only
    for (const t of this._skyTexResolved?.values() || []) t?.dispose();
    for (const t of this._cloudTex?.values() || []) t?.dispose();
    this._flareTex?.clear();
    this._lensflare = null;
    this._flareSet = -1;
    if (this._sunBeams) {
      this._sunBeams.traverse(o => {
        o.geometry?.dispose?.();
        if (o.material) {
          if (Array.isArray(o.material)) o.material.forEach(m => m.dispose?.());
          else o.material.dispose?.();
        }
      });
    }
    this._sunBeams = null;
    this._sunBeamShafts = [];
    this._sunBeamTex = null;
    if (this.scene.fog === this.fog) this.scene.fog = this._prev.fog || null;
    if (this.scene.background && this._prev.background !== undefined) this.scene.background = this._prev.background;
    this._objs = [];
    this.effectLights?.clear();
    if (this.game.effectLights === this.effectLights) this.game.effectLights = null;
  }
}

