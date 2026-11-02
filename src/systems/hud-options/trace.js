// Weapon trace (Graphics tab "Trace Effect": N/A / Character / All): the ribbon a held weapon leaves while its owner swings.
// Global behaviour (LANE-70b, docs/global-parity-420/WEAPON-EFFECTS.md, every value labelled):
//  - GLOBAL DECOMPILE (32-bit main, CLinkedBody FUN_011d5e80): the trace is built ONLY from the weapon mesh's own authored lines
//    "traceline" (and "traceline2" when present), first and last point of each. A mesh without "traceline" returns early and draws
//    no trace. There is no weaponline / bounding-box fallback (the old one was engine-invented and is removed).
//    GLOBAL DATA (counted by tools/test-weapon-effects-lane70b.mjs): 668 of 2,066 data/mesh/item/weapon meshes author a drawable
//    traceline (523 also traceline2); 25 more author one with non-finite points and draw nothing (JUDGMENT). Bows, crossbows,
//    staffs, shields and guardarms author none, orbs and wands only a few: per type see docs/global-parity-420/WEAPON-EFFECTS.md.
//  - GLOBAL DECOMPILE (CTraceUnit FUN_011ec640): every trace sample lives 300 ms (stored lifetime 300, aged per tick by
//    FUN_011ecb70 and dropped once its age passes it). The sample count is whatever 300 ms of movement leaves: no count cap.
//  - GLOBAL DECOMPILE (CTraceUnit ctor FUN_011ec1e0) + GLOBAL DATA: the texture is texturepack/effect/hit/eff_swordtrace.tpack,
//    frame per sample: 0 eff_trace_normal, 1 fire, 2 ice, 3 electric, 4 poison, 5 curse, 6 white.
//  - GLOBAL DECOMPILE (FUN_008b50d0 -> FUN_008b5ea0 / FUN_008b5f10 / FUN_008b6050, message UpdateTrace): the frame starts at 6
//    (white) for both hands; it becomes the stone attribute (item Attribute column, 0..5) only when every socket of that hand's
//    weapon holds a stone and all of them share one attribute; mixed stones keep 6. The old "blue for skills" texture
//    (texture/effect/common/eff_trace_blue.dds, an inference) is removed: CTraceUnit never loads that pack.
//  - Ranged weapons are not excluded by an attack-range rule (removed, engine-invented): they simply author no traceline.
//  JUDGMENT (labelled): alpha fades linearly 1 -> 0 over the 300 ms (Global's falloff constants sit in the packed exe's data
//    section, unreadable here); additive blending (binary/trace.fx "Tracer" sets no blend state itself); the trace is sampled
//    while the owner is in an attack/skill state outside peace stance; each hand uses its own weapon's sockets (the UpdateTrace
//    message carries one frame for R_Weapon and one for L_Weapon); "traceline2" draws a second ribbon on the same weapon.
// "Character" = your own character, "All" = every player character in view.
import * as THREE from 'three';

export const TRACE_LINES = Object.freeze(['traceline', 'traceline2']);
export const TRACE_SAMPLE_MS = 300;
export const TRACE_TPACK = 'texturepack/effect/hit/eff_swordtrace.tpack';
export const TRACE_TEXTURES = Object.freeze(['normal', 'fire', 'ice', 'electric', 'poison', 'curse', 'white'].map(n => `texture/effect/hit/eff_trace_${n}.dds`));
export const TRACE_DEFAULT_FRAME = 6;
const LIFE = TRACE_SAMPLE_MS / 1000;   // game.time is in seconds
const _a = new THREE.Vector3(), _b = new THREE.Vector3();
const viewFor = actor => actor?._equipmentPreview?.equipment || actor?.save?.equipment || {};

/** Trace frame of one hand (see header): the shared stone attribute when every socket is filled with one attribute, else 6. */
export function traceTextureIndex(sockets, db) {
  if (!Array.isArray(sockets) || !sockets.length) return TRACE_DEFAULT_FRAME;
  let attribute = null;
  for (const id of sockets.slice(0, 4)) {
    const stone = Number(id) > 0 ? db?.def?.(Number(id)) : null;
    if (!stone) return TRACE_DEFAULT_FRAME;
    const a = Number(stone.attribute) || 0;
    if (attribute === null) attribute = a;
    else if (a !== attribute) return TRACE_DEFAULT_FRAME;
  }
  return attribute >= 0 && attribute <= 5 ? attribute : TRACE_DEFAULT_FRAME;
}

/** The authored trace segments of a weapon model: [{name, base, tip}] for traceline and traceline2, first/last point each.
 *  Empty when the mesh authors no traceline (Global draws nothing then). */
export function traceSegments(lines) {
  const out = [];
  const list = Array.isArray(lines) ? lines : [];
  if (!list.some(l => String(l?.name).toLowerCase() === TRACE_LINES[0])) return out;
  for (const name of TRACE_LINES) {
    const line = list.find(l => String(l?.name).toLowerCase() === name);
    const points = line?.strips?.find(s => s && s.length >= 6);
    if (!points) continue;
    const tip = new THREE.Vector3().fromArray(points, 0);
    const base = new THREE.Vector3().fromArray(points, points.length - 3);
    if (tip.distanceToSquared(base) > 1e-12) out.push({ name, base, tip });
  }
  return out;
}

export class WeaponTraces {
  constructor(game, ctx) {
    this.game = game;
    this.ctx = ctx;
    this.trails = new Map();       // weapon Object3D -> [trail per authored line]
    this.mats = [];
    this.root = new THREE.Group();
    this.root.name = 'weapon traces (FILE frame)';
    this.root.renderOrder = 5;
    game.worldRoot?.add(this.root);
  }

  _mat(frame) {
    if (this.mats[frame]) return this.mats[frame];
    const mat = new THREE.MeshBasicMaterial({ transparent: true, depthWrite: false, side: THREE.DoubleSide, vertexColors: true, blending: THREE.AdditiveBlending });
    this.mats[frame] = mat;
    Promise.resolve(this.game.textures?.load?.(TRACE_TEXTURES[frame], { repeat: false })).then(t => { if (t) { mat.map = t; mat.needsUpdate = true; } }).catch(() => {});
    return mat;
  }

  /** Authored segments of a weapon object (cached per object). */
  _segments(obj) {
    if (obj.userData._hoTrace !== undefined) return obj.userData._hoTrace;
    obj.userData._hoTrace = traceSegments(obj.userData.model?.lines);
    return obj.userData._hoTrace;
  }

  _alloc(t, capacity) {
    const geo = new THREE.BufferGeometry();
    geo.setAttribute('position', new THREE.BufferAttribute(new Float32Array(capacity * 6), 3).setUsage(THREE.DynamicDrawUsage));
    geo.setAttribute('color', new THREE.BufferAttribute(new Float32Array(capacity * 8), 4).setUsage(THREE.DynamicDrawUsage));
    geo.setAttribute('uv', new THREE.BufferAttribute(new Float32Array(capacity * 4), 2).setUsage(THREE.DynamicDrawUsage));
    const idx = [];
    for (let i = 0; i < capacity - 1; i++) { const a = i * 2; idx.push(a, a + 1, a + 2, a + 1, a + 3, a + 2); }
    geo.setIndex(idx);
    if (t.geo) t.geo.dispose();
    t.geo = geo; t.capacity = capacity;
    if (t.mesh) t.mesh.geometry = geo;
  }

  _trails(obj, count) {
    let list = this.trails.get(obj);
    if (list && list.length === count) return list;
    if (list) for (const t of list) this._dropTrail(t);
    list = [];
    for (let i = 0; i < count; i++) {
      const t = { samples: [], geo: null, capacity: 0, mesh: null };
      this._alloc(t, 16);
      t.mesh = new THREE.Mesh(t.geo, this._mat(TRACE_DEFAULT_FRAME));
      t.mesh.frustumCulled = false;
      t.mesh.renderOrder = 5;
      this.root.add(t.mesh);
      list.push(t);
    }
    this.trails.set(obj, list);
    return list;
  }

  _actors(mode) {
    const g = this.game, p = g.player;
    if (!p || mode <= 0) return [];
    if (mode === 1) return [p];
    let list = [];
    try { list = g.actors ? g.actors() : [p]; } catch { list = [p]; }
    return list.filter(a => a && a.kind === 'player' && !a.dead);
  }

  _frames(a) {
    const w = viewFor(a).weapon || {}, db = this.game.items?.db || null;
    const main = traceTextureIndex(w.sockets, db);
    const left = traceTextureIndex(w.leftSockets ?? (w.leftItemIndex ? null : w.sockets), db);
    return { main, second: left };
  }

  update(dt) {
    const mode = Number(this.ctx.options.get('trace')) || 0;
    const now = this.game.time || 0;
    const live = new Set();
    for (const a of this._actors(mode)) {
      const swinging = (a.state === 'attack' || a.state === 'skill') && a.stance !== 'peace' && !a.dead;
      const objs = a._weaponObjs || [];
      const frames = objs.length ? this._frames(a) : null;
      for (const e of objs) {
        const obj = e.obj;
        if (!obj?.parent || !obj.visible) continue;
        const segments = this._segments(obj);
        if (!segments.length) continue;   // no traceline authored: Global draws no trace
        live.add(obj);
        const trails = this._trails(obj, segments.length);
        const frame = e.hand === 'second' ? frames.second : frames.main;
        if (swinging) obj.updateWorldMatrix(true, false);
        segments.forEach((seg, i) => {
          const t = trails[i];
          t.mesh.material = this._mat(frame);
          if (swinging) {
            _a.copy(seg.base).applyMatrix4(obj.matrixWorld);
            _b.copy(seg.tip).applyMatrix4(obj.matrixWorld);
            this.root.worldToLocal(_a); this.root.worldToLocal(_b);   // THREE space -> FILE frame of worldRoot
            t.samples.unshift({ base: _a.clone(), tip: _b.clone(), t: now });
          }
          this._build(t, now);
        });
      }
    }
    for (const [obj, list] of this.trails) {
      if (live.has(obj)) continue;
      if (!obj.parent) { this._drop(obj); continue; }
      for (const t of list) this._build(t, now);
      if (list.every(t => !t.samples.length)) this._drop(obj);
    }
  }

  _build(t, now) {
    const S = t.samples;
    while (S.length && now - S[S.length - 1].t > LIFE) S.pop();
    const n = S.length;
    t.mesh.visible = n >= 2;
    if (n < 2) return;
    if (n > t.capacity) this._alloc(t, Math.max(n, t.capacity * 2));
    const pos = t.geo.attributes.position.array, col = t.geo.attributes.color.array, uv = t.geo.attributes.uv.array;
    for (let i = 0; i < n; i++) {
      const s = S[i];
      const k = 1 - Math.min(1, (now - s.t) / LIFE);
      const u = i / Math.max(1, n - 1);
      const o = i * 6;
      pos[o] = s.tip.x; pos[o + 1] = s.tip.y; pos[o + 2] = s.tip.z;
      pos[o + 3] = s.base.x; pos[o + 4] = s.base.y; pos[o + 5] = s.base.z;
      const c = i * 8;
      col[c] = col[c + 1] = col[c + 2] = 1; col[c + 3] = k;
      col[c + 4] = col[c + 5] = col[c + 6] = 1; col[c + 7] = k;
      const q = i * 4;
      uv[q] = u; uv[q + 1] = 0; uv[q + 2] = u; uv[q + 3] = 1;
    }
    t.geo.attributes.position.needsUpdate = true;
    t.geo.attributes.color.needsUpdate = true;
    t.geo.attributes.uv.needsUpdate = true;
    t.geo.setDrawRange(0, (n - 1) * 6);
  }

  _dropTrail(t) { t.mesh.removeFromParent(); t.geo.dispose(); }

  _drop(obj) { for (const t of this.trails.get(obj) || []) this._dropTrail(t); this.trails.delete(obj); }

  clear() { for (const obj of [...this.trails.keys()]) this._drop(obj); }

  dispose() { this.clear(); this.root.removeFromParent(); for (const m of this.mats) m?.dispose(); }
}
