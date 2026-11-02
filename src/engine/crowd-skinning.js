// Crowd skinning (overnight 43.19, phase 3): GPU skinning + instancing for monster bodies.
//
// A monster whose animation is exactly ONE fully-weighted clip (no cross-fade running, no per-instance material, nothing
// attached to its bones, no secondary-motion chain simulated on it) is not skinned on the CPU: the clip is baked once per
// (model, clip) into a float texture of bone-matrix rows (BAKE_RATE samples per second, the same numbers the CPU path
// computes: fround(bone.matrixWorld x boneInverse) in the body's root frame), and every visible such body of that model is
// drawn by ONE instanced skinned draw per part (shared geometry buffers, the shared part material, one shadow draw).
// The body's AnimationMixer still runs every frame (advanceOnly: three's own AnimationAction._updateTime / _updateWeight /
// time scale / start time, so loops, the LoopOnce clamp and the 'finished' events are the CPU path's), only the
// interpolation, the bone world matrices and the skeleton upload are skipped. The pose drawn is the clip at the action's
// time, linearly interpolated between the two nearest baked samples.
// Every other case stays on the unchanged CPU path, per body: cross-fades, play/stop, death fades and highlight (own
// materials), getBone/attach users (effects on bones), chain bodies within the secondary-motion range of the camera.
// Kill switches: globalThis.__dekaronNoCrowdSkin = true (every body stays / returns to the CPU path);
// __dekaronCrowd.setEnabled(false) demotes every body synchronously (bit-identical CPU pose at the same mixer time).
import * as THREE from 'three';
import { SkinnedInstance, freezeMatrices, isFrozen } from './models.js';
import { waitProgramsTouched } from './shader-prewarm.js';

const BAKE_RATE = globalThis.__dkCrowdBakeRate > 0 ? globalThis.__dkCrowdBakeRate : 120;          // samples per second of clip
const START_ROWS = 1024;        // atlas rows per model (grows x2 up to MAX_ROWS)
const MAX_ROWS = 8192;
const INIT_CAP = 64;            // instances per batch (grows x2)
const HOLD_MS = 1500;           // a body that needed its bones (getBone / attach / chain) stays on the CPU this long
const CHAIN_RANGE = 30;         // systems/graphics/secondary.js RANGE
const CHAIN_MARGIN = 4;
const HOLD_WHY = new Set(['getBone', 'attach', 'chain', 'boneChild']);
const BUDGET_PLAY_MS = 1.0, BUDGET_LOAD_MS = 40;

let runtimeOff = false;
const off = () => runtimeOff || globalThis.__dekaronNoCrowdSkin === true;

// ------------------------------------------------------------------------------------------------ shader chunks
// Only programs that are skinned AND instanced AND carry instanceColor take the crowd path (the crowd batches always set an
// all-ones instanceColor: diffuse x 1.0 is exact). Every other skinned program (incl. world/objects.js InstancedSkinnedMesh,
// instanceColor null) compiles the original r170 code.
let chunkOk = false;
(function patchChunks() {
  const C = THREE.ShaderChunk;
  const pars = C.skinning_pars_vertex;
  if (pars.includes('dkCrowd')) { chunkOk = true; return; }
  const i = pars.indexOf('mat4 getBoneMatrix'), j = pars.lastIndexOf('#endif');
  if (i < 0 || j < i) return;
  const ls = pars.lastIndexOf('\n', i) + 1;
  const crowd = [
    '\t#if defined( USE_INSTANCING ) && defined( USE_INSTANCING_COLOR )',
    '\tattribute vec4 dkCrowd;',
    '\tmat4 getBoneMatrix( const in float i ) {',
    '\t\tint x = int( i ) * 3;',
    '\t\tivec2 a = ivec2( x, int( dkCrowd.x ) );',
    '\t\tivec2 b = ivec2( x, int( dkCrowd.y ) );',
    '\t\tvec4 r0 = mix( texelFetch( boneTexture, a, 0 ), texelFetch( boneTexture, b, 0 ), dkCrowd.z );',
    '\t\tvec4 r1 = mix( texelFetch( boneTexture, a + ivec2( 1, 0 ), 0 ), texelFetch( boneTexture, b + ivec2( 1, 0 ), 0 ), dkCrowd.z );',
    '\t\tvec4 r2 = mix( texelFetch( boneTexture, a + ivec2( 2, 0 ), 0 ), texelFetch( boneTexture, b + ivec2( 2, 0 ), 0 ), dkCrowd.z );',
    '\t\treturn mat4( r0.x, r1.x, r2.x, 0.0, r0.y, r1.y, r2.y, 0.0, r0.z, r1.z, r2.z, 0.0, r0.w, r1.w, r2.w, 1.0 );',
    '\t}',
    '\t#else',
    '',
  ].join('\n');
  C.skinning_pars_vertex = pars.slice(0, ls) + crowd + pars.slice(ls, j) + '\t#endif\n' + pars.slice(j);
  chunkOk = true;
})();

// ------------------------------------------------------------------------------------------------ state
const S = {
  game: null, models: new Map(), slots: new Set(), gpu: new Set(), jobs: [],
  installedScene: null, lastBuildTime: NaN, lastPumpTime: NaN, dirty: true,
  st: { promotes: 0, demotes: {}, callers: {}, bakes: 0, bakeMs: 0, uploads: 0, grows: 0, drawn: 0, draws: 0, builds: 0, buildMs: 0, maxBuildMs: 0, ev: [] },
};
const _m = new THREE.Matrix4(), _inv = new THREE.Matrix4();
const IDENT = new THREE.Matrix4();

class CrowdMesh extends THREE.SkinnedMesh {
  constructor(geometry, material, skeleton) {
    super(geometry, material);
    this.isInstancedMesh = true;
    this.instanceMatrix = null; this.instanceColor = null; this.morphTexture = null; this.count = 0; this.cap = 0; this._nCast = 0; this._full = 0;
    this.bind(skeleton, IDENT); this.bindMode = THREE.DetachedBindMode;
    this.frustumCulled = false; this.castShadow = true; this.receiveShadow = false;
    this.boundingSphere = new THREE.Sphere(new THREE.Vector3(), 1e9);
    this.name = 'crowd:' + (material?.name || '');
    this.userData.dkCrowd = true;
    this._grow(INIT_CAP);
  }
  _grow(cap) {
    const old = this.cap, n = this.count;
    const im = new THREE.InstancedBufferAttribute(new Float32Array(cap * 16), 16); im.setUsage(THREE.DynamicDrawUsage);
    const ic = new THREE.InstancedBufferAttribute(new Float32Array(cap * 3).fill(1), 3);
    const cr = new THREE.InstancedBufferAttribute(new Float32Array(cap * 4), 4); cr.setUsage(THREE.DynamicDrawUsage);
    if (old) { im.array.set(this.instanceMatrix.array.subarray(0, n * 16)); cr.array.set(this.geometry.attributes.dkCrowd.array.subarray(0, n * 4)); }
    this.instanceMatrix = im; this.instanceColor = ic; this.geometry.setAttribute('dkCrowd', cr);
    this.cap = cap;
  }
  // shadow pass: only the casting instances (they are packed first)
  onBeforeShadow() { this._full = this.count; if (this._compiled) this.count = this._nCast; }
  onAfterShadow() { this.count = this._full; }
  raycast() {}
}

// The batch draws with a PROXY of the part's shared material (Object.create: every property, hook and version is read
// live from the shared material, so the shader and uniforms are the same) that has its own identity in three's per-material
// state: the shared material's program (skinned, not instanced) and the batch's (skinned + instanced) never swap per draw
// (measured: a shared material alternating between both re-ran getParameters/getProgram on every draw).
let _proxyId = 0x40000000;
function proxyMaterial(shared) {
  const m = Object.create(shared);
  Object.defineProperty(m, 'id', { value: _proxyId++ });
  m.uuid = THREE.MathUtils.generateUUID();
  m._listeners = {};
  // the shader hooks always stay the shared material's: a scene-wide patch pass (applyShade / object-normal ...) that
  // meets the proxy would otherwise wrap a fresh hook around the proxy and drop the shared chain (measured: specular lost)
  for (const k of ['onBeforeCompile', 'customProgramCacheKey']) {
    Object.defineProperty(m, k, { get() { return shared[k]; }, set() { /* the shared material owns its hooks */ }, configurable: true });
  }
  return m;
}

// diagnostics only (globalThis.__dkCrowdDiag): tally why three swapped an object's program between two of its draws
if (globalThis.__dkCrowdDiag) {
  // diagnostics only: three re-links (getParameters/getProgram) twice per draw for transparent DoubleSide materials without forceSinglePass
  const ob = THREE.Material.prototype.onBeforeRender;
  THREE.Material.prototype.onBeforeRender = function (r, sc, cam, geo, obj, grp) {
    if (this.transparent === true && this.side === THREE.DoubleSide && this.forceSinglePass === false) {
      let n = obj, path = [];
      while (n && path.length < 4) { if (n.name) path.push(String(n.name).slice(0, 24)); n = n.parent; }
      const k = 'ds2pass ' + this.type + ' ' + (this.name || '') + ' @' + path.join('<') + (obj.layers.mask !== 1 ? ' L' + obj.layers.mask : '');
      const d = S.st.diag || (S.st.diag = {}); d[k] = (d[k] || 0) + 1;
    }
    return ob.call(this, r, sc, cam, geo, obj, grp);
  };
}
function diagHook(o, r0, tag) {
  let before = null;
  const pb = o.onBeforeRender, pa = o.onAfterRender;
  const tally = (k) => { const d = S.st.diag || (S.st.diag = {}); d[tag + ' ' + k] = (d[tag + ' ' + k] || 0) + 1; };
  o.onBeforeRender = function (r, sc, cam, geo, mat, grp) {
    pb.call(this, r, sc, cam, geo, mat, grp);
    const mp = r0.properties.get(mat), rt = r0.getRenderTarget();
    tally('draws');
    const why = [];
    if (mp.__version === undefined) why.push('new');
    else if (mat.version !== mp.__version) why.push('version');
    else {
      const cs = rt === null ? r0.outputColorSpace : THREE.LinearSRGBColorSpace;
      if (mp.outputColorSpace !== cs) why.push('colorSpace:' + mp.outputColorSpace + '>' + cs);
      if (!!this.isInstancedMesh !== !!mp.instancing) why.push('instancing');
      if (!!this.isSkinnedMesh !== !!mp.skinning) why.push('skinning');
      if (this.isInstancedMesh && !!mp.instancingColor !== (this.instanceColor !== null)) why.push('instColor');
      const tm = mat.toneMapped && rt === null ? r0.toneMapping : THREE.NoToneMapping;
      if (mp.toneMapping !== tm) why.push('toneMapping:' + mp.toneMapping + '>' + tm);
      if (mat.fog === true && mp.fog !== sc.fog) why.push('fog');
      const va = mat.vertexColors === true && !!geo.attributes.color && geo.attributes.color.itemSize === 4;
      if (mp.vertexAlphas !== va) why.push('vertexAlphas');
      const vt = !!geo.attributes.tangent && (!!mat.normalMap || mat.anisotropy > 0);
      if (mp.vertexTangents !== vt) why.push('vertexTangents');
    }
    before = { lsv: mp.lightsStateVersion, prog: mp.currentProgram, why };
  };
  o.onAfterRender = function (r, sc, cam, geo, mat, grp) {
    pa.call(this, r, sc, cam, geo, mat, grp);
    if (!before) return;
    const mp = r0.properties.get(mat);
    if (mp.lightsStateVersion !== before.lsv) before.why.push('lights');
    if (mp.currentProgram !== before.prog) before.why.push('progSwap');
    if (before.why.length) tally(before.why.join(','));
    before = null;
  };
}

function sharedGeometry(src) {
  const g = new THREE.BufferGeometry();
  for (const k of Object.keys(src.attributes)) g.setAttribute(k, src.attributes[k]);
  if (src.index) g.setIndex(src.index);
  for (const gr of src.groups) g.addGroup(gr.start, gr.count, gr.materialIndex);
  g.drawRange.start = src.drawRange.start; g.drawRange.count = src.drawRange.count;
  g.boundingSphere = new THREE.Sphere(new THREE.Vector3(), 1e9);
  return g;
}

const SHADOW_SIDE = { 0: 1, 1: 0, 2: 2 };   // three's WebGLShadowMap shadowSide (not VSM)

function freeAtlas(r, tex) {
  const p = r.properties.get(tex);
  if (p.__webglTexture) r.getContext().deleteTexture(p.__webglTexture);
  r.properties.remove(tex);
}

class ModelCrowd {
  constructor(model) {
    this.model = model;
    const parts = model.parts || [];
    this.ok = !model.empty && parts.length > 0 && parts.every(p => p.geometry?.attributes?.skinIndex && p.geometry?.attributes?.skinWeight
      && p.material && !Array.isArray(p.material) && !p.material.transparent);
    this.nb = (model._bones?.length || 0) + 1;
    this.W = this.nb * 3;
    const maxTex = S.game?.renderer?.capabilities?.maxTextureSize || 4096;
    if (this.W > maxTex) this.ok = false;
    this.rows = 0; this.cap = 0; this.data = null; this.tex = null;
    this.bakes = new Map();
    this.batches = null; this.ready = false; this.rig = null; this.mixer = null;
  }
  ensureRows(need) {
    if (need > MAX_ROWS) return false;
    if (need <= this.cap) return true;
    let cap = Math.max(START_ROWS, this.cap);
    while (cap < need) cap *= 2;
    const data = new Float32Array(this.W * cap * 4);
    if (this.data) data.set(this.data.subarray(0, this.rows * this.W * 4));
    // The atlas is a GL texture this module owns: storage is allocated (texStorage2D, nothing uploaded) and only baked rows
    // are ever sent (texSubImage2D). A DataTexture handed to three would upload all cap rows (~4 MB per model) at once;
    // measured as 100-160 ms GPU-process stalls at spawn. three binds it through its texture properties (version 0:
    // three never uploads or owns it).
    const tex = new THREE.DataTexture(null, this.W, cap, THREE.RGBAFormat, THREE.FloatType);
    tex.minFilter = tex.magFilter = THREE.NearestFilter; tex.generateMipmaps = false; tex.flipY = false;
    tex.name = 'dk-crowd-bones';
    const r = S.game?.renderer;
    if (!r) return false;
    const gl = r.getContext();
    const glTex = gl.createTexture();
    r.state.bindTexture(gl.TEXTURE_2D, glTex);
    gl.texStorage2D(gl.TEXTURE_2D, 1, gl.RGBA32F, this.W, cap);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.CLAMP_TO_EDGE);
    r.state.unbindTexture();
    r.properties.get(tex).__webglTexture = glTex;
    const oldTex = this.tex;
    ev('grow', `${this.W}x${cap} ${(this.W * cap * 16 / 1048576).toFixed(1)}MB`);
    this.data = data; this.tex = tex; this.cap = cap; this.glTex = glTex;
    if (this.rows > 0) this.uploadRows(0, this.rows);
    for (const b of this.batches || []) b.skeleton.boneTexture = tex;
    if (oldTex) freeAtlas(r, oldTex);
    S.st.grows++;
    return true;
  }
  uploadRows(row0, n) {
    const r = S.game?.renderer;
    if (!r || !this.glTex || n <= 0) return;
    const gl = r.getContext();
    r.state.bindTexture(gl.TEXTURE_2D, this.glTex);
    gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, false);
    gl.pixelStorei(gl.UNPACK_PREMULTIPLY_ALPHA_WEBGL, false);
    gl.pixelStorei(gl.UNPACK_ALIGNMENT, 4);
    gl.pixelStorei(gl.UNPACK_ROW_LENGTH, 0);
    gl.pixelStorei(gl.UNPACK_SKIP_PIXELS, 0);
    gl.pixelStorei(gl.UNPACK_SKIP_ROWS, 0);
    gl.texSubImage2D(gl.TEXTURE_2D, 0, 0, row0, this.W, n, gl.RGBA, gl.FLOAT, this.data, row0 * this.W * 4);
    r.state.unbindTexture();
    S.st.uploads++;
  }
  makeBatches() {
    if (this.batches || !this.ok) return;
    const g = S.game;
    this.ensureRows(1);
    this.batches = this.model.parts.map(p => {
      const sk = new THREE.Skeleton([], []);
      sk.boneTexture = this.tex; sk.update = () => {}; sk.dispose = () => {};
      const b = new CrowdMesh(sharedGeometry(p.geometry), globalThis.__dkT_noProxy ? p.material : proxyMaterial(p.material), sk);
      // own depth material (same parameters as WebGLShadowMap's shared one: RGBA packing; side/map/alphaTest copied per pass)
      if (!globalThis.__dkT_noDepth) b.customDepthMaterial = new THREE.MeshDepthMaterial({ depthPacking: THREE.RGBADepthPacking });
      b._compiled = false; b.visible = false; b._warmLeft = 3;
      b.onAfterRender = () => { b._compiled = true; };
      if (globalThis.__dkCrowdDiag) diagHook(b, g.renderer, 'batch');
      return b;
    });
    ev('batches', `${this.batches.length}`);
    const show = () => { ev('show', `${this.batches.length}`); for (const b of this.batches) { if (b.parent !== g.worldRoot) g.worldRoot.add(b); b.visible = true; } };
    const r = g.renderer;
    if (!g._loadingMap && typeof r?.compileAsync === 'function' && g.camera) {
      // in play: link the batch programs in parallel (KHR_parallel_shader_compile) before they ever draw
      // + their shadow-depth variants (WebGLShadowMap copies side / map / alphaTest onto the depth material per pass: the same here, no fog),
      // then wait for the first-use set-up of the new programs (shader-prewarm: one per frame, after the link): a batch's first draw in a
      // play frame never runs a synchronous link wait (measured 100-160 ms spawn frames without this)
      const tmp = new THREE.Group(), depthTmp = new THREE.Group();
      for (const b of this.batches) {
        tmp.add(b);
        const dm = b.customDepthMaterial;
        if (dm) {
          const m = b.material;
          dm.side = m.shadowSide !== null && m.shadowSide !== undefined ? m.shadowSide : (SHADOW_SIDE[m.side] ?? m.side);
          dm.alphaMap = m.alphaMap; dm.alphaTest = m.alphaTest; dm.map = m.map;
          depthTmp.add(new CrowdMesh(b.geometry, dm, b.skeleton));
        }
      }
      const fog = g.scene.fog;
      const linked = (async () => {
        const p1 = r.compileAsync(tmp, g.camera, g.scene);
        g.scene.fog = null;
        let p2;
        try { p2 = depthTmp.children.length ? r.compileAsync(depthTmp, g.camera, g.scene) : null; } finally { g.scene.fog = fog; }
        await Promise.all([p1, p2]);
        await waitProgramsTouched(g, { maxMs: 3000 });
      })();
      Promise.race([linked, new Promise(res => setTimeout(res, 6000))]).then(show, show);
    } else show();
  }
  get compiled() { return !!this.batches && this.batches.every(b => b._compiled); }
}

function modelCrowd(model) {
  let mc = S.models.get(model);
  if (!mc) { mc = new ModelCrowd(model); S.models.set(model, mc); }
  return mc;
}

// ------------------------------------------------------------------------------------------------ baking
function queueBake(mc, clip) {
  if (!clip || mc.bakes.has(clip)) return;
  const dur = clip.duration > 0 ? clip.duration : 0;
  const n = dur > 0 ? Math.max(2, Math.ceil(dur * BAKE_RATE) + 1) : 1;
  const b = { clip, dur, n, row0: -1, ready: false, failed: false, k: 0 };
  mc.bakes.set(clip, b);
  if (!mc.ensureRows(mc.rows + n)) { b.failed = true; return; }
  b.row0 = mc.rows; mc.rows += n;
  S.jobs.push({ mc, b });
}

function pump(budgetMs) {
  if (!S.jobs.length) return;
  const t0 = performance.now(), end = t0 + budgetMs;
  while (S.jobs.length && performance.now() < end) {
    const { mc, b } = S.jobs[0];
    if (!mc.rig) { mc.rig = mc.model.instantiate(); mc.mixer = new THREE.AnimationMixer(mc.rig.root); }
    const mixer = mc.mixer, rig = mc.rig;
    const action = mixer.clipAction(b.clip);
    if (!action.isRunning() && b.k === 0) {
      action.reset(); action.setLoop(THREE.LoopOnce, 1); action.clampWhenFinished = true; action.setEffectiveWeight(1); action.play();
    }
    const bones = rig.skeleton.bones, inv = rig.skeleton.boneInverses, W4 = mc.W * 4, data = mc.data, nb = mc.nb;
    while (b.k < b.n && performance.now() < end) {
      const k = b.k++;
      action.time = b.n > 1 ? (k === b.n - 1 ? b.dur : k * b.dur / (b.n - 1)) : 0;
      mixer.update(0);
      rig.root.updateMatrixWorld(true);
      let o = (b.row0 + k) * W4;
      for (let i = 0; i < nb; i++, o += 12) {
        const e = _m.multiplyMatrices(bones[i].matrixWorld, inv[i]).elements;
        data[o] = e[0]; data[o + 1] = e[4]; data[o + 2] = e[8]; data[o + 3] = e[12];
        data[o + 4] = e[1]; data[o + 5] = e[5]; data[o + 6] = e[9]; data[o + 7] = e[13];
        data[o + 8] = e[2]; data[o + 9] = e[6]; data[o + 10] = e[10]; data[o + 11] = e[14];
      }
    }
    if (b.k >= b.n) {
      action.stop(); mixer.uncacheAction(b.clip);
      mc.uploadRows(b.row0, b.n);
      ev('baked', `${b.n}r`);
      b.ready = true; S.jobs.shift(); S.st.bakes++;
    }
  }
  S.st.bakeMs += performance.now() - t0;
}

// ------------------------------------------------------------------------------------------------ per body
/** Called by Actor._afterLoad for monsters. */
export function crowdRegister(actor) {
  const inst = actor?.instance;
  if (globalThis.__dekaronNoCrowdSkin === true) return;      // startup kill switch: the original CPU path, untouched
  if (!chunkOk || !inst || !(inst instanceof SkinnedInstance) || inst._dkCrowd || actor.kind !== 'monster') return;
  const g = actor.game;
  if (!g?.worldRoot || !g?.renderer || !g?.scene) return;
  if (S.game !== g) resetFor(g);
  install(g);
  const mc = modelCrowd(inst.model);
  if (!mc.ok) return;
  mc.makeBatches();
  const s = { actor, inst, mc, gpu: false, hold: 0, clip: null, time: 0, vis: inst.meshes.map(() => true), kids: null, foreign: false };
  inst._dkCrowd = s;
  // something parented to a bone (effects, weapons) needs the CPU bones: such a body stays on the CPU
  for (const bone of inst.bones) {
    bone.add = function (...o) { s.foreign = true; if (s.gpu) demote(s, true, 'boneChild'); return THREE.Object3D.prototype.add.apply(this, o); };
  }
  if (globalThis.__dkCrowdDiag) for (const m of inst.meshes) { m._dkDiag = true; diagHook(m, g.renderer, 'cpu'); }
  S.slots.add(s);
  const clip = actor.animator?.current?._clip;
  if (clip) {
    queueBake(mc, clip);
    if (g._loadingMap) pump(BUDGET_LOAD_MS);
  }
}

function unregister(s) {
  if (!s) return;
  if (s.gpu) demote(s, false, 'dispose');
  S.slots.delete(s); S.gpu.delete(s);
  s.inst._dkCrowd = null;
}

function chainBlocked(s) {
  const a = s.actor, g = S.game, sec = g?.gfx?.secondary;
  if (!sec || sec.enabled === false) return false;
  const inst = s.inst;
  let ch = inst._dkChains;
  if (ch === undefined && typeof sec._chains === 'function') { try { ch = sec._chains(a); } catch { ch = null; } }
  if (!ch || !ch.length) return false;
  const cam = g.camera;
  if (!cam) return true;
  return Math.hypot(a.x - cam.position.x, a.z + cam.position.z) <= CHAIN_RANGE + CHAIN_MARGIN;
}

function eligible(s) {
  s.why = whyNot(s);
  return s.why === null;
}
function whyNot(s) {
  if (off()) return 'off';
  if (!s.mc.ready) return 'compiling';
  const a = s.actor, inst = s.inst;
  if (a.instance !== inst || inst.model !== s.mc.model) return 'replaced';
  if (s.foreign || inst._attached.size) return 'boneChild';
  if (inst._own) return 'ownMaterial';
  if (s.hold && performance.now() < s.hold) return 'hold';
  const an = a.animator, cur = an?.current;
  if (!cur) return 'noClip';
  if (an._layers.length !== 1 || an._layers[0].action !== cur || an.mixer._nActiveActions !== 1) return 'fade';
  if (!cur.enabled || cur.getEffectiveWeight() !== 1 || cur.weight !== 1) return 'weight';
  for (const m of inst.meshes) if (m.layers.mask !== 1) return 'layers';
  const b = s.mc.bakes.get(cur._clip);
  if (!b) { queueBake(s.mc, cur._clip); return 'baking'; }
  if (b.failed) return 'bakeFull';
  if (!b.ready) return 'baking';
  if (chainBlocked(s)) return 'chain';
  return null;
}

function promote(s) {
  const inst = s.inst;
  s.kids = inst.root.children.slice();
  for (const c of s.kids) freezeMatrices(c, true, false);
  inst.meshes.forEach((m, i) => { s.vis[i] = m.visible; m.visible = false; });
  // the bone hierarchies draw nothing (no foreign children on a GPU body): hidden, three's per-frame projectObject walk
  // skips their whole subtree (~50-100 bones per monster). Restored on demote.
  s.kidVis = s.kids.map(c => c.visible);
  if (!globalThis.__dkT_noHide) for (const c of s.kids) if (!c.isMesh) c.visible = false;
  s.gpu = true; S.gpu.add(s); S.dirty = true; S.st.promotes++;
  const cur = s.actor.animator.current;
  s.clip = cur._clip; s.time = cur.time;
}

/** Back to the CPU path. sync: re-pose the bones now (a caller is about to read them / change the animation). */
function demote(s, sync, why) {
  if (!s.gpu) return;
  s.gpu = false; S.gpu.delete(s); S.dirty = true;
  S.st.demotes[why] = (S.st.demotes[why] || 0) + 1;
  const inst = s.inst;
  (s.kids || []).forEach((c, i) => { if (!c.isMesh) c.visible = s.kidVis[i]; freezeMatrices(c, false); });
  s.kids = null; s.kidVis = null;
  inst.meshes.forEach((m, i) => { m.visible = s.vis[i]; });
  if (sync) {
    const t0 = performance.now();   // PERF-CROWD diagnostics: per-frame cost of synchronous re-poses
    try { s.actor.animator?.mixer.update(0); } catch { /* ignore */ }
    for (const c of inst.root.children) c.updateMatrixWorld(true);
    const sk = inst.skeleton;
    if (sk._dkFrozen) { sk._dkFrozen = false; try { sk.update(); } finally { sk._dkFrozen = true; } }
    const d = performance.now() - t0, ft = S.game?.time; S.st.syncMs = (S.st.syncMs || 0) + d; S.st.syncN = (S.st.syncN || 0) + 1;
    if (S._syncT !== ft) { S._syncT = ft; S._syncF = 0; S._syncFN = 0; } S._syncF += d; S._syncFN++;
    if (S._syncF > (S.st.maxSyncFrameMs || 0)) { S.st.maxSyncFrameMs = +S._syncF.toFixed(2); S.st.maxSyncFrameN = S._syncFN; }
  }
  if (HOLD_WHY.has(why)) s.hold = performance.now() + HOLD_MS;
}

/** Actor.update, right before animator.update (only on frames the animation advances). */
export function crowdTick(actor) {
  const s = actor?.instance?._dkCrowd;
  if (!s) return;
  if (eligible(s)) { if (!s.gpu) promote(s); }
  else if (s.gpu) demote(s, false, off() ? 'off' : 'tick');
}

/** Before an Animator changes / stops its actions, or anyone reads the bones: the body returns to the CPU path first. */
export function crowdDemoteSync(instance, why = 'sync') {
  const s = instance?._dkCrowd;
  if (!s?.gpu) return;
  if (why === 'getBone' || why === 'play') {   // diagnostics: who needed the CPU bones (first src frame outside this module / models.js)
    const fr = String(new Error().stack).split('\n').find(l => l.includes('/src/') && !l.includes('crowd-skinning') && !l.includes('models.js') && !l.includes('animator.js'));
    const k = why + ' ' + (fr ? fr.trim().replace(/^at /, '').replace(/https?:\/\/[^/]+/, '') : '?');
    S.st.callers[k] = (S.st.callers[k] || 0) + 1;
  }
  demote(s, true, why);
}

/** Animator.update for a GPU body: the mixer's own time / weight / loop / finish logic without the pose evaluation. */
export function crowdAdvance(animator, dt) {
  const s = animator.instance?._dkCrowd;
  const mixer = animator.mixer;
  if (!s?.gpu) { mixer.update(dt); return; }
  dt *= mixer.timeScale;
  const actions = mixer._actions, n = mixer._nActiveActions;
  const time = mixer.time += dt, dir = Math.sign(dt);
  mixer._accuIndex ^= 1;
  for (let i = 0; i !== n; ++i) {
    const a = actions[i];
    if (!a.enabled) { a._updateWeight(time); continue; }
    let d = dt;
    if (a._startTime !== null) {
      const tr = (time - a._startTime) * dir;
      if (tr < 0 || dir === 0) d = 0; else { a._startTime = null; d = dir * tr; }
    }
    d *= a._updateTimeScale(time);
    a._updateTime(d);
    a._updateWeight(time);
  }
  const cur = animator.current;
  if (!cur || mixer._nActiveActions !== 1 || !cur.enabled || cur.weight !== 1 || mixer._actions[0] !== cur) { demote(s, true, 'advance'); return; }
  s.clip = cur._clip; s.time = cur.time;
}

/** True when this instance is drawn by a crowd batch (its CPU skin meshes are hidden). */
export function crowdIsGpu(instance) { return !!instance?._dkCrowd?.gpu; }

// ------------------------------------------------------------------------------------------------ per render
function shown(o) {
  for (; o; o = o.parent) { if (!o.visible) return false; if (o.isScene) return true; }
  return false;
}

function build() {
  const g = S.game;
  if (!g) return;
  const t0 = performance.now();
  if (globalThis.__dkCrowdDiag && (S._diagT = (S._diagT || 0) + 1) % 30 === 1) g.scene.traverse(o => {
    if (!o.isMesh && !o.isPoints && !o.isLine && !o.isSprite) return;
    if (o._dkDiag) return; o._dkDiag = true;
    if (o.isInstancedMesh && o.geometry?.attributes?.dkCrowd) return;
    const m = Array.isArray(o.material) ? o.material[0] : o.material;
    diagHook(o, g.renderer, 'scene:' + o.type + '/' + (m?.type || '?') + '/' + String(o.name || '').slice(0, 20));
  });
  if (g.time !== S.lastPumpTime) { S.lastPumpTime = g.time; pump(g._loadingMap ? BUDGET_LOAD_MS : BUDGET_PLAY_MS); }
  for (const mc of S.models.values()) if (!mc.ready && mc.batches && mc.compiled) mc.ready = true;
  if (g.time === S.lastBuildTime && !S.dirty) return;
  S.lastBuildTime = g.time; S.dirty = false;
  for (const mc of S.models.values()) if (mc.batches) for (const b of mc.batches) { b.count = 0; b._nCast = 0; }
  let drawn = 0;
  if (S.gpu.size) {
    const wr = g.worldRoot;
    _inv.copy(wr.matrixWorld).invert();
    const list = S._list || (S._list = []);
    list.length = 0;
    for (const s of S.gpu) {
      const inst = s.inst, root = inst.root;
      if (!shown(root)) continue;
      let ext = false;
      for (const m of inst.meshes) if (m.visible) ext = true;
      if (ext) { demote(s, true, 'visible'); continue; }
      const b = s.mc.bakes.get(s.clip);
      if (!b?.ready) { demote(s, true, 'nobake'); continue; }
      let ra = b.row0, rb = b.row0, f = 0;
      if (b.n > 1 && b.dur > 0) {
        let u = (s.time / b.dur) * (b.n - 1);
        if (!(u > 0)) u = 0; else if (u > b.n - 1) u = b.n - 1;
        const k = Math.min(Math.floor(u), b.n - 2);
        f = u - k; ra = b.row0 + k; rb = ra + 1;
      }
      s._ra = ra; s._rb = rb; s._f = f;
      (s._mat || (s._mat = new THREE.Matrix4())).multiplyMatrices(_inv, root.matrixWorld);
      list.push(s);
      drawn++;
    }
    // shadow casters first: the shadow pass draws only the first _nCast instances of a batch (onBeforeShadow)
    for (const cast of [true, false]) {
      for (const s of list) {
        const batches = s.mc.batches, inst = s.inst;
        for (let p = 0; p < batches.length; p++) {
          if (!s.vis[p] || !!inst.meshes[p].castShadow !== cast) continue;
          const bt = batches[p];
          if (bt.count >= bt.cap) bt._grow(bt.cap * 2);
          const i = bt.count++;
          s._mat.toArray(bt.instanceMatrix.array, i * 16);
          const cr = bt.geometry.attributes.dkCrowd.array, o = i * 4;
          cr[o] = s._ra; cr[o + 1] = s._rb; cr[o + 2] = s._f; cr[o + 3] = 0;
          if (cast) bt._nCast = bt.count;
        }
      }
    }
  }
  let draws = 0;
  for (const mc of S.models.values()) {
    if (!mc.batches) continue;
    for (const bt of mc.batches) {
      if (bt.parent !== g.worldRoot) { if (!mc.ready) continue; g.worldRoot.add(bt); bt.updateMatrixWorld(true); }
      if (!bt._compiled) { bt.castShadow = true; continue; }     // count 0: draws nothing, links its programs (loading screen)
      // first real draws: ANGLE (D3D11) builds a program's draw-time shader variants (input layout / output) at its first non-empty
      // draw, synchronously in the GPU process (measured 60-130 ms frames at spawn). One degenerate instance (zero matrix:
      // gl_Position 0, nothing rasterised) is drawn in the main and shadow passes for a few frames right after the link, under the loading screen.
      if (!bt.count && bt._warmLeft > 0 && mc.ready && !globalThis.__dkT_noWarm) {
        bt._warmLeft--;
        bt.instanceMatrix.array.fill(0, 0, 16);
        bt.count = 1; bt._nCast = 1;
      }
      if (bt.count) {
        const im = bt.instanceMatrix, cr = bt.geometry.attributes.dkCrowd;
        im.clearUpdateRanges(); im.addUpdateRange(0, bt.count * 16); im.needsUpdate = true;
        cr.clearUpdateRanges(); cr.addUpdateRange(0, bt.count * 4); cr.needsUpdate = true;
        draws++;
      }
      bt.visible = bt.count > 0 && mc.ready;
      bt.castShadow = bt._nCast > 0;
    }
  }
  const ms = performance.now() - t0;
  S.st.drawn = drawn; S.st.draws = draws; S.st.builds++; S.st.buildMs += ms; if (ms > S.st.maxBuildMs) S.st.maxBuildMs = ms;
}

function install(g) {
  const scene = g.scene;
  if (S.installedScene !== scene) {
    const prev = scene.onBeforeRender;
    scene.onBeforeRender = function (...args) {
      try { prev?.apply(this, args); } finally { try { build(); } catch (err) { console.error('[crowd] build failed', err); disableAll('error'); } }
    };
    S.installedScene = scene;
  }
  const sec = g.gfx?.secondary;
  if (sec && !sec._dkCrowdWrapped) {
    const orig = sec.update;
    sec.update = function (dt) {
      // a chain body this update would simulate needs its CPU bones before it reads them
      if (S.gpu.size && this.enabled && dt > 0 && g.camera) {
        const cx = g.camera.position.x, cz = -g.camera.position.z;
        for (const s of S.gpu) {
          const a = s.actor, ch = s.inst._dkChains;
          if (ch !== undefined && ch !== null && ch.length === 0) continue;
          if (a.culled || a.group?.visible === false) continue;
          if (Math.hypot(a.x - cx, a.z - cz) <= CHAIN_RANGE + 0.5) demote(s, true, 'chain');
        }
      }
      return orig.call(this, dt);
    };
    sec._dkCrowdWrapped = true;
  }
}

function resetFor(g) {
  for (const s of [...S.slots]) unregister(s);
  for (const mc of S.models.values()) {
    for (const b of mc.batches || []) b.removeFromParent();
    if (mc.tex && S.game?.renderer) freeAtlas(S.game.renderer, mc.tex);
  }
  S.models.clear(); S.jobs.length = 0; S.game = g; S.installedScene = null; S.dirty = true;
}

function disableAll(why) {
  runtimeOff = true;
  for (const s of [...S.gpu]) demote(s, true, why);
  S.dirty = true;
}

// SkinnedInstance hooks: everything that reads or re-parents bones, changes materials, or disposes returns to the CPU path first.
{
  const P = SkinnedInstance.prototype;
  const wrap = (name, pre) => { const f = P[name]; if (typeof f !== 'function' || f._dkCrowd) return; const w = function (...a) { pre(this, a); return f.apply(this, a); }; w._dkCrowd = true; P[name] = w; };
  wrap('getBone', i => crowdDemoteSync(i, 'getBone'));
  wrap('attach', i => crowdDemoteSync(i, 'attach'));
  wrap('setOpacity', (i, a) => { if (!(Number(a[0]) >= 1) || i._own) crowdDemoteSync(i, 'opacity'); });
  wrap('setHighlight', (i, a) => { if (a[0] != null && a[0] !== false) crowdDemoteSync(i, 'highlight'); });
  wrap('replaceParts', i => { crowdDemoteSync(i, 'parts'); unregister(i._dkCrowd); });
  wrap('dispose', i => unregister(i._dkCrowd));
}

// ------------------------------------------------------------------------------------------------ diagnostics
function verify({ samples = 7, maxVerts = 4000 } = {}) {
  const out = [];
  const v = new THREE.Vector3(), a = new THREE.Vector3(), c = new THREE.Vector3(), w = new THREE.Vector3();
  for (const mc of S.models.values()) {
    if (!mc.ok || !mc.data) continue;
    const rig = mc.model.instantiate(), mixer = new THREE.AnimationMixer(rig.root);
    const nb = mc.nb, W4 = mc.W * 4;
    const cpu = new Float32Array(nb * 12), gpu = new Float32Array(nb * 12);
    for (const b of mc.bakes.values()) {
      if (!b.ready) continue;
      const action = mixer.clipAction(b.clip);
      action.reset(); action.setLoop(THREE.LoopOnce, 1); action.clampWhenFinished = true; action.play();
      let maxErr = 0, sumErr = 0, cnt = 0, maxExact = 0;
      const times = [];
      for (let i = 0; i < samples; i++) times.push([b.dur * (i + 0.37) / samples, false]);
      if (b.n > 1) for (const k of [0, Math.floor(b.n / 2), b.n - 1]) times.push([k * b.dur / (b.n - 1), true]);
      for (const [t, exact] of times) {
        action.time = t; mixer.update(0); rig.root.updateMatrixWorld(true);
        const bones = rig.skeleton.bones, inv = rig.skeleton.boneInverses;
        for (let i = 0; i < nb; i++) {
          const e = _m.multiplyMatrices(bones[i].matrixWorld, inv[i]).elements, o = i * 12;
          cpu[o] = e[0]; cpu[o + 1] = e[4]; cpu[o + 2] = e[8]; cpu[o + 3] = e[12]; cpu[o + 4] = e[1]; cpu[o + 5] = e[5]; cpu[o + 6] = e[9]; cpu[o + 7] = e[13]; cpu[o + 8] = e[2]; cpu[o + 9] = e[6]; cpu[o + 10] = e[10]; cpu[o + 11] = e[14];
        }
        let ra = b.row0, rb = b.row0, f = 0;
        if (b.n > 1 && b.dur > 0) { let u = Math.min(b.n - 1, Math.max(0, t / b.dur * (b.n - 1))); const k = Math.min(Math.floor(u), b.n - 2); f = Math.fround(u - k); ra = b.row0 + k; rb = ra + 1; }
        for (let i = 0; i < nb * 12; i++) { const x = mc.data[ra * W4 + i], y = mc.data[rb * W4 + i]; gpu[i] = Math.fround(x * (1 - f) + y * f); }
        for (const part of mc.model.parts) {
          const ga = part.geometry.attributes, P = ga.position, SI = ga.skinIndex, SW = ga.skinWeight, N = P.count, step = Math.max(1, Math.floor(N / maxVerts));
          for (let vi = 0; vi < N; vi += step) {
            v.fromBufferAttribute(P, vi); a.set(0, 0, 0); c.set(0, 0, 0);
            for (let j = 0; j < 4; j++) {
              const wt = SW.getComponent(vi, j); if (!wt) continue;
              const bi = SI.getComponent(vi, j), o = bi * 12;
              for (const [M, acc] of [[cpu, a], [gpu, c]]) {
                w.set(M[o] * v.x + M[o + 1] * v.y + M[o + 2] * v.z + M[o + 3], M[o + 4] * v.x + M[o + 5] * v.y + M[o + 6] * v.z + M[o + 7], M[o + 8] * v.x + M[o + 9] * v.y + M[o + 10] * v.z + M[o + 11]);
                acc.addScaledVector(w, wt);
              }
            }
            const err = a.distanceTo(c);
            if (exact) { if (err > maxExact) maxExact = err; }
            else { if (err > maxErr) maxErr = err; sumErr += err; cnt++; }
          }
        }
      }
      action.stop(); mixer.uncacheAction(b.clip);
      const radius = mc.model.sphere?.radius || 1;
      out.push({ model: mc.model.skelKey, clip: b.clip.name, dur: +b.dur.toFixed(3), samples: b.n, maxErr: +maxErr.toPrecision(3), meanErr: +(sumErr / Math.max(1, cnt)).toPrecision(3), maxErrAtSample: +maxExact.toPrecision(3), radius: +radius.toFixed(2), maxRelPct: +(100 * maxErr / radius).toPrecision(3) });
    }
    mixer.stopAllAction(); mixer.uncacheRoot(rig.root);
  }
  return out;
}

function ev(type, info) { const e = S.st.ev; if (e.length < 120) e.push([+performance.now().toFixed(1), type, info]); }

function stats() {
  let slots = 0, gpu = 0, models = 0, ready = 0, rows = 0, bakes = 0, eligibleModels = 0;
  const cpuWhy = {};
  for (const s of S.slots) { slots++; if (s.gpu) gpu++; else { const w = s.actor.culled ? 'culled' : (s.why ?? 'notTicked'); cpuWhy[w] = (cpuWhy[w] || 0) + 1; } }
  for (const mc of S.models.values()) { models++; if (mc.ok) eligibleModels++; if (mc.ready) ready++; rows += mc.rows; bakes += [...mc.bakes.values()].filter(b => b.ready).length; }
  return { enabled: !off(), chunkOk, models, eligibleModels, readyModels: ready, slots, gpu, cpu: slots - gpu, bakes, rows, jobs: S.jobs.length, ...S.st,
    bakeMs: +S.st.bakeMs.toFixed(1), buildMs: +S.st.buildMs.toFixed(1), maxBuildMs: +S.st.maxBuildMs.toFixed(2), demotes: { ...S.st.demotes }, ev: S.st.ev.slice(), diag: S.st.diag, callers: Object.fromEntries(Object.entries(S.st.callers).sort((a, b) => b[1] - a[1]).slice(0, 8)), cpuWhy };
}

globalThis.__dekaronCrowd = {
  stats, verify,
  setEnabled(on) { if (on) { runtimeOff = false; S.dirty = true; } else disableAll('off'); },
  get state() { return S; },
};
