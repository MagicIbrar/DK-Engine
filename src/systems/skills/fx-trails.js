// tailstep trails (src/config/engine-chosen-skill-fx.js TRAIL documents the field reading and its evidence).
//   sprite   -> TracerBillboard (binary/trace.fx): a camera-facing ribbon through the unit's past positions, per-vertex
//               colour/alpha, the sprite's own texture and blend. Width = the sprite's drawn size at each sample.
//   mesh     -> TracerMesh (binary/tracemesh.fx): frozen copies of the effect mesh drawn with one global colour
//               (f4GlobalColor), fading out. Skinned meshes are baked at the emitted pose (CPU, capped vertices).
//   particle -> per-particle copies left behind at past positions (fx-units.js ParticleUnit uses trailSchedule).
// Everything lives under the effect root in the FILE frame, like ParticleUnit.
import * as THREE from 'three';
import { TRAIL, trailCopyCap } from '../../config/engine-chosen-skill-fx.js';

const _inv = new THREE.Matrix4(), _m = new THREE.Matrix4(), _p = new THREE.Vector3(), _q = new THREE.Quaternion(), _s = new THREE.Vector3();
const _a = new THREE.Vector3(), _b = new THREE.Vector3(), _c = new THREE.Vector3();

/** Inverse world matrix of the effect root: maps a THREE world matrix into the root's FILE frame. */
export function rootInverse(fx, out) { fx.root.updateWorldMatrix(true, false); return out.copy(fx.root.matrixWorld).invert(); }
/** FILE-frame position of a THREE object (relative to the effect root). */
export function fileFramePosition(fx, object, out) {
  object.updateWorldMatrix(true, false);
  return out.setFromMatrixPosition(rootInverse(fx, _inv).multiply(object.matrixWorld));
}

/** Trail parameters of a unit, or null when the unit authors no trail (on false or count 0). Pure. */
export function trailSpec(unit) {
  const t = unit?.tail;
  if (!t || t.on !== true) return null;
  const count = Math.floor(Number(t.count) || 0);
  if (count <= 0) return null;
  const a = Math.max(0, Number(t.a) || 0), b = Math.max(0, Number(t.b) || 0);
  let life = Math.max(0, Number(t.ms) || 0);
  if (!(life > 0)) life = count * (a > 0 ? a : TRAIL.FRAME_MS);
  const interval = a > 0 ? a : (b > 0 ? 0 : life / count);     // ms between samples (0 = distance driven only)
  return { count: Math.min(count, trailCopyCap()), authoredCount: count, interval, spacing: b, life };
}

/** Emission clock shared by every trail kind. Pure (no THREE objects): tested by tools/test-skill-fx-trails.mjs. */
export class TrailSchedule {
  constructor(spec) { this.spec = spec; this.sinceMs = Infinity; this.last = null; }
  /** Advance by dtMs with the source at (x, y, z); true when a sample must be emitted now. */
  step(dtMs, x, y, z) {
    const s = this.spec;
    this.sinceMs += dtMs;
    let due = false;
    if (this.last == null) due = true;
    else {
      if (s.interval > 0 && this.sinceMs >= s.interval) due = true;
      if (s.spacing > 0 && Math.hypot(x - this.last[0], y - this.last[1], z - this.last[2]) >= s.spacing) due = true;
    }
    if (due) { this.sinceMs = 0; this.last = [x, y, z]; }
    return due;
  }
}

/** Fade of a sample of age `ageMs` over the trail life: 1 when new, 0 at the end (linear). Pure. */
export const trailFade = (ageMs, lifeMs) => lifeMs > 0 ? Math.max(0, 1 - ageMs / lifeMs) : 0;

// ============================================================================================ sprite ribbon
export class SpriteRibbon {
  constructor(fx, unit, spec, blending) {
    this.fx = fx; this.spec = spec; this.clock = new TrailSchedule(spec);
    this.points = [];               // {p: Vector3 FILE, w, r, g, b, a, age}
    this._side = new THREE.Vector3(); // continuous ribbon orientation through stationary/reversing motion
    this._buildSide = new THREE.Vector3();
    const n = spec.count + 1;       // samples + the live head
    this.pos = new Float32Array(n * 2 * 3); this.col = new Float32Array(n * 2 * 4); this.uv = new Float32Array(n * 2 * 2);
    const idx = new Uint16Array(Math.max(0, n - 1) * 6);
    for (let i = 0; i < n - 1; i++) { const v = i * 2; idx.set([v, v + 1, v + 2, v + 1, v + 3, v + 2], i * 6); }
    const geo = new THREE.BufferGeometry();
    geo.setAttribute('position', new THREE.BufferAttribute(this.pos, 3).setUsage(THREE.DynamicDrawUsage));
    geo.setAttribute('color', new THREE.BufferAttribute(this.col, 4).setUsage(THREE.DynamicDrawUsage));
    geo.setAttribute('uv', new THREE.BufferAttribute(this.uv, 2).setUsage(THREE.DynamicDrawUsage));
    geo.setIndex(new THREE.BufferAttribute(idx, 1));
    geo.setDrawRange(0, 0);
    // blending may be a THREE blending enum or fxBlendFields() object (Global SrcAlpha, One).
    const blendProps = (blending && typeof blending === 'object') ? blending : { blending };
    this.material = new THREE.MeshBasicMaterial({ transparent: true, depthWrite: false, ...blendProps, side: THREE.DoubleSide, vertexColors: true, fog: true });
    this.material.visible = false;
    this.mesh = new THREE.Mesh(geo, this.material);
    this.mesh.frustumCulled = false; this.mesh.renderOrder = 10;
    fx.root.add(this.mesh);
    this.emitting = true;
  }
  /** head: {p (FILE Vector3), w, color [r,g,b], alpha, map}; dt seconds. */
  update(dt, head) {
    const ms = dt * 1000, s = this.spec;
    for (const q of this.points) q.age += ms;
    while (this.points.length && this.points[0].age >= s.life) this.points.shift();
    if (head && this.emitting && this.clock.step(ms, head.p.x, head.p.y, head.p.z)) {
      const c = head.color || [1, 1, 1];
      this.points.push({ p: head.p.clone(), w: head.w, r: c[0], g: c[1], b: c[2], a: head.alpha, age: 0 });
      while (this.points.length > s.count) this.points.shift();
    }
    if (head?.map && this.material.map !== head.map) { this.material.map = head.map; this.material.needsUpdate = true; }
    this._build(this.emitting ? head : null);
  }
  stop() { this.emitting = false; }
  get alive() { return this.points.length > 0; }
  _build(head) {
    const pts = this.points.slice();
    if (head) pts.push({ p: head.p, w: head.w, r: head.color?.[0] ?? 1, g: head.color?.[1] ?? 1, b: head.color?.[2] ?? 1, a: head.alpha, age: 0 });
    const n = pts.length, geo = this.mesh.geometry;
    if (n < 2 || !this.material.map) { geo.setDrawRange(0, 0); this.material.visible = false; return; }
    const cam = this.fx.cam?.pos || _c.set(0, 10, 10), P = this.pos, C = this.col, U = this.uv, life = this.spec.life;
    let hasSide = this._side.lengthSq() > 0;
    const previousSide = this._buildSide.copy(this._side);
    for (let i = 0; i < n; i++) {
      const q = pts[i], prev = pts[Math.max(0, i - 1)].p, next = pts[Math.min(n - 1, i + 1)].p;
      _a.copy(next).sub(prev);
      _b.copy(cam).sub(q.p);
      _a.cross(_b);
      if (_a.lengthSq() < 1e-10) {
        if (hasSide) _a.copy(previousSide);
        else _a.copy(this.fx.cam?.right || _b.set(1, 0, 0));
      }
      _a.normalize();
      // Reversing a gently bobbing emblem used to exchange left/right ribbon
      // edges, folding a bright full-width triangle across the sprite each frame.
      if (hasSide && _a.dot(previousSide) < 0) _a.negate();
      previousSide.copy(_a); hasSide = true;
      if (i === 0) this._side.copy(_a);
      _a.multiplyScalar(0.5 * q.w);
      const v = i * 2;
      P[v * 3] = q.p.x - _a.x; P[v * 3 + 1] = q.p.y - _a.y; P[v * 3 + 2] = q.p.z - _a.z;
      P[v * 3 + 3] = q.p.x + _a.x; P[v * 3 + 4] = q.p.y + _a.y; P[v * 3 + 5] = q.p.z + _a.z;
      const alpha = Math.max(0, Math.min(1, q.a)) * trailFade(q.age, life);
      for (let k = 0; k < 2; k++) { const c = (v + k) * 4; C[c] = q.r; C[c + 1] = q.g; C[c + 2] = q.b; C[c + 3] = alpha; }
      const along = n > 1 ? 1 - i / (n - 1) : 0;    // 0 at the head, 1 at the oldest sample
      U[v * 2] = 0; U[v * 2 + 1] = along; U[v * 2 + 2] = 1; U[v * 2 + 3] = along;
    }
    for (const a of ['position', 'color', 'uv']) geo.attributes[a].needsUpdate = true;
    geo.setDrawRange(0, (n - 1) * 6);
    this.material.visible = true;
  }
  dispose() { this.mesh.removeFromParent(); this.mesh.geometry.dispose(); this.material.dispose(); this.points = []; }
}

// ============================================================================================ mesh copies
const BAKE_MAX_VERTICES = 6000;
export class MeshTrail {
  constructor(fx, spec) { this.fx = fx; this.spec = spec; this.clock = new TrailSchedule(spec); this.copies = []; this.emitting = true; }
  /** source: the MeshUnit object (Group); mats: its live materials (alpha/colour are copied). */
  update(dt, source, alpha, color) {
    const ms = dt * 1000;
    for (const c of this.copies) {
      c.age += ms;
      const f = trailFade(c.age, this.spec.life);
      for (const m of c.meshes) m.material.opacity = c.alpha * f;
    }
    while (this.copies.length && this.copies[0].age >= this.spec.life) this._drop(this.copies.shift());
    if (!source || !this.emitting) return;
    source.updateWorldMatrix(true, true);
    rootInverse(this.fx, _inv);
    _m.copy(_inv).multiply(source.matrixWorld); _m.decompose(_p, _q, _s);
    if (!this.clock.step(ms, _p.x, _p.y, _p.z)) return;
    const meshes = [];
    source.traverse(o => {
      if (!o.isMesh || !o.visible || !o.material) return;
      const mat = o.material.clone(); mat.opacity = alpha; if (color) mat.color.setRGB(color[0], color[1], color[2]);
      let geo = o.geometry, own = false;
      if (o.isSkinnedMesh) { geo = bakeSkinned(o); own = true; if (!geo) return; }
      const g = new THREE.Mesh(geo, mat);
      g.matrixAutoUpdate = false;
      g.matrix.copy(_inv).multiply(o.matrixWorld);
      g.renderOrder = o.renderOrder; g.frustumCulled = false; g.userData.ownGeo = own;
      this.fx.root.add(g); meshes.push(g);
    });
    if (!meshes.length) return;
    this.copies.push({ meshes, age: 0, alpha });
    while (this.copies.length > this.spec.count) this._drop(this.copies.shift());
  }
  stop() { this.emitting = false; }
  get alive() { return this.copies.length > 0; }
  _drop(c) { for (const m of c.meshes) { m.removeFromParent(); m.material.dispose(); if (m.userData.ownGeo) m.geometry.dispose(); } }
  dispose() { for (const c of this.copies) this._drop(c); this.copies = []; }
}

/** Positions of a skinned mesh at its current pose, in the mesh's local frame (THREE applyBoneTransform). */
export function bakeSkinned(mesh) {
  const src = mesh.geometry, pos = src.attributes.position;
  if (!pos || pos.count > BAKE_MAX_VERTICES) return null;
  const out = new Float32Array(pos.count * 3), v = new THREE.Vector3();
  for (let i = 0; i < pos.count; i++) { v.fromBufferAttribute(pos, i); mesh.applyBoneTransform(i, v); out[i * 3] = v.x; out[i * 3 + 1] = v.y; out[i * 3 + 2] = v.z; }
  const geo = new THREE.BufferGeometry();
  geo.setAttribute('position', new THREE.BufferAttribute(out, 3));
  // own copies: disposing this geometry frees the GL buffers of every attribute it holds, so sharing the source's
  // uv/index would delete them under the live mesh (WebGL "no buffer is bound to enabled attribute")
  if (src.attributes.uv) geo.setAttribute('uv', src.attributes.uv.clone());
  if (src.index) geo.setIndex(src.index.clone());
  for (const g of src.groups) geo.addGroup(g.start, g.count, g.materialIndex);
  return geo;
}
