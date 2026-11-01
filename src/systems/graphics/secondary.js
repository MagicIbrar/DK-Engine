// Secondary motion for explicitly named accessories: hair / ponytails (Bone_hair_*,
// Bone_pony_*, Hair_*), capes and cloaks (Cloak_*, Cape_*), skirt and
// tasset panels (bone_fl/fr/bl/br/ff/bb, Bone_pat_*) and tails (Bip01 Tail*,
// Bip01_Tail_*, Bip01 Ponytail*). The clips key these bones (the authored cloth swing); on top of that each bone's tip
// follows its animated position through a damped spring, so the pieces trail behind when the body accelerates, turns or
// stops, and settle back onto the animation. Nothing is added while the body moves steadily (the spring is driven by
// the animated tip's velocity) - only the inertia of starts, stops and turns, plus a little air drag.
//
// Frame: the simulation runs in the FILE frame (worldRoot local; the mirror cancels, so rotations are proper), and the
// rotation offset is applied to the bone's local quaternion for this render only: restore() puts the animated values
// back after the frame is drawn, so the mixer and every bone reader see the pure animation.
//
// Budget: the player plus the nearest visible actors (MAX_ACTORS) within RANGE of the camera; culled actors skip.
import * as THREE from 'three';

const RANGE = 30;
const MAX_ACTORS = 10;
const EXCLUDE = /weapon|position|rotate|^bal_|^sis_|^sht_|^swd_|^att_|^cel_|^pos_|plane|nub$|^del_|^bone_cl|footsteps|picking|dummy|effect|^bip01 (l|r) |^bip01 (spine|neck|head|pelvis)|^bip01$/i;
const INCLUDE_BIP = /^bip01[ _]?(ponytail|tail)/i;
// Anonymous BoneNN chains can be facial rigging, armour, or anatomical controls.
// Authored animation already drives them; only explicitly named accessories get extra inertia.
const ACCESSORY = /^(?:bone[ _])?(?:hair|pony(?:tail)?|cloak|cape|cot|tail)(?:[ _\d]|$)|^bone_(?:fl|fr|bl|br|ff|bb|pat)(?:_|\d|$)/i;

// per-kind spring: stiffness K (1/s^2), damping ratio, max swing (rad), drag
const KINDS = {
  hair: { k: 170, zeta: 0.9, max: 0.2, drag: 1.2 },
  cloth: { k: 240, zeta: 0.9, max: 0.16, drag: 1.6 },
  skirt: { k: 330, zeta: 0.9, max: 0.12, drag: 1.0 },
  tail: { k: 140, zeta: 0.9, max: 0.25, drag: 0.8 },
};

function kindOf(name, anchorName) {
  const n = name.toLowerCase(), a = (anchorName || '').toLowerCase();
  if (/tail/.test(n)) return 'tail';
  if (/hair|pony/.test(n) || /head|neck/.test(a)) return 'hair';
  if (/cloak|cape|cot_/.test(n) || /spine/.test(a)) return 'cloth';
  return 'skirt';
}

const _m = new THREE.Matrix4(), _inv = new THREE.Matrix4(), _pm = new THREE.Matrix4();
const _h = new THREE.Vector3(), _t = new THREE.Vector3(), _a = new THREE.Vector3(), _b = new THREE.Vector3();
const _q = new THREE.Quaternion(), _pq = new THREE.Quaternion(), _pqi = new THREE.Quaternion(), _s = new THREE.Vector3(), _p = new THREE.Vector3();

const _byDistance = (x, y) => x.d - y.d;

/** Dangling chains of a SkinnedInstance: [{bone, child, kind, spring state}] in parent-before-child order. */
function findChains(inst) {
  const bones = inst.bones || [];
  const isDangling = new Map();
  const nodes = [];
  for (const b of bones) {
    const raw = String(b.name || '');
    const parent = b.parent;
    const pname = String(parent?.name || '');
    let ok = false, anchor = null;
    // Skeleton exports use both spaces and underscores for the anatomical Bip01 names.
    // Never put the spine/head/limbs into the cloth spring: that moves the entire body.
    const anatomical = raw.replace(/_/g, ' ');
    if ((EXCLUDE.test(raw) || EXCLUDE.test(anatomical)) && !INCLUDE_BIP.test(raw)) ok = false;
    else if (isDangling.get(parent)) { ok = true; anchor = isDangling.get(parent).anchor; }
    else if (ACCESSORY.test(raw) || INCLUDE_BIP.test(raw)) { ok = true; anchor = pname; }
    if (!ok) continue;
    const e = { bone: b, anchor, kind: kindOf(raw, anchor) };
    isDangling.set(b, e);
    nodes.push(e);
  }
  // each bone needs a child bone as its tip (leaves without one are end markers)
  const out = [];
  for (const e of nodes) {
    const child = e.bone.children.find(c => c.isBone);
    if (!child) continue;
    e.child = child;
    e.cfg = KINDS[e.kind];
    e.p = new THREE.Vector3(); e.v = new THREE.Vector3(); e.prevT = new THREE.Vector3();
    e.init = false;
    e.saved = new THREE.Quaternion();
    out.push(e);
  }
  return out;
}

export class SecondaryMotion {
  constructor(game) {
    this.game = game;
    this.enabled = true;
    this.modified = [];        // entries whose bone quaternion is offset for the current render
    this.stats = { actors: 0, bones: 0 };
    this._frameNo = 0;         // simulated frames so far (the carried time of a skipped body is only valid on the very next frame)
    this._pool = [];           // reused candidate records (no per-frame allocation)
    this._cand = [];
  }

  _chains(actor) {
    const inst = actor.instance;
    if (!inst) return null;
    if (inst._dkChains === undefined) inst._dkChains = findChains(inst);
    return inst._dkChains;
  }

  /** Simulate and offset the bones for this frame (call after every actor updated its animation, before render). */
  update(dt) {
    // (restore() runs after every render; a frame whose render was skipped keeps its offsets for one more frame)
    if (this.modified.length) this.restore();
    if (!this.enabled || !(dt > 0)) return;
    const g = this.game;
    const root = g.worldRoot, cam = g.camera;
    if (!root || !cam) return;
    const cx = cam.position.x, cz = -cam.position.z;
    let list = [];
    try { list = g.actors ? g.actors() : []; } catch { list = []; }
    for (const s of g.skills?.summons?.all?.() || []) list.push(s);
    const fn = ++this._frameNo;
    const pool = this._pool;
    let n = 0;
    for (const a of list) {
      if (!a || a.disposed || a.culled) continue;
      const inst = a.instance;
      if (!inst) continue;
      let ch = inst._dkChains;
      if (ch !== undefined && ch.length === 0) continue;       // known body without hair / cape / tail chains: nothing to simulate (no distance maths)
      if (inst.frozen) {
        // animation-LOD frame of a still body (actor.js): it is not simulated, but the time it did not simulate is carried to its next
        // simulated frame (opt-4: a body re-posed every 2nd / 3rd frame must integrate its spring over the time the animation advanced)
        inst._dkSecAcc = (inst._dkSecFrame === fn - 1 ? inst._dkSecAcc : 0) + dt; inst._dkSecFrame = fn;
        continue;
      }
      if (a.group?.visible === false || a.faded) continue;
      const d = Math.hypot(a.x - cx, a.z - cz);
      if (a !== g.player && d > RANGE) continue;
      if (ch === undefined) ch = this._chains(a);
      if (!ch || !ch.length) continue;
      const c = pool[n] || (pool[n] = { a: null, d: 0, ch: null, dt: 0 });
      c.a = a; c.d = a === g.player ? -1 : d; c.ch = ch;
      c.dt = dt + (inst._dkSecFrame === fn - 1 ? inst._dkSecAcc : 0);   // 0 + dt = dt exactly for a body that was simulated last frame too
      inst._dkSecAcc = 0; inst._dkSecFrame = fn;
      n++;
    }
    this.stats.actors = 0; this.stats.bones = 0;
    if (!n) return;                                   // nobody to simulate: no world-matrix refresh either (the render does it)
    const cand = this._cand; cand.length = n;
    for (let i = 0; i < n; i++) cand[i] = pool[i];
    cand.sort(_byDistance);
    if (cand.length > MAX_ACTORS) cand.length = MAX_ACTORS;
    root.updateWorldMatrix(true, false);
    _inv.copy(root.matrixWorld).invert();
    let bones = 0;
    for (const { a, ch, dt: dtA } of cand) {
      const h = Math.min(dtA, 1 / 20);
      const steps = h > 1 / 90 ? 2 : 1;
      const sdt = h / steps;
      a.group.updateMatrixWorld(true);
      for (const e of ch) {
        const b = e.bone, parent = b.parent;
        // animated head / tip in the FILE frame (parents already offset this frame)
        _m.multiplyMatrices(_inv, b.matrixWorld); _h.setFromMatrixPosition(_m);
        _m.multiplyMatrices(_inv, e.child.matrixWorld); _t.setFromMatrixPosition(_m);
        const L = _h.distanceTo(_t);
        if (!(L > 1e-4)) continue;
        if (!e.init || dtA > 0.1 || e.prevT.distanceTo(_t) > 3) {
          e.p.copy(_t); e.v.set(0, 0, 0); e.prevT.copy(_t); e.init = true; continue;
        }
        // target velocity (feed-forward) - steady motion adds no lag
        _a.subVectors(_t, e.prevT).divideScalar(h);
        e.prevT.copy(_t);
        const { k, zeta, max, drag } = e.cfg;
        const c = 2 * zeta * Math.sqrt(k);
        for (let i = 0; i < steps; i++) {
          // acc = k (T - p) + c (vT - v) - drag v
          _b.subVectors(_t, e.p).multiplyScalar(k);
          _b.x += c * (_a.x - e.v.x) - drag * e.v.x;
          _b.y += c * (_a.y - e.v.y) - drag * e.v.y;
          _b.z += c * (_a.z - e.v.z) - drag * e.v.z;
          e.v.addScaledVector(_b, sdt);
          e.p.addScaledVector(e.v, sdt);
        }
        // keep the bone length; limit the swing
        _b.subVectors(e.p, _h);
        const bl = _b.length();
        if (!(bl > 1e-5)) { e.p.copy(_t); continue; }
        _b.divideScalar(bl);
        _a.subVectors(_t, _h).divideScalar(L);
        let ang = Math.acos(Math.max(-1, Math.min(1, _a.dot(_b))));
        if (ang > max) {
          // rotate the animated direction towards the simulated one by `max`
          _p.crossVectors(_a, _b);
          if (_p.lengthSq() < 1e-10) { e.p.copy(_t); continue; }
          _p.normalize();
          _q.setFromAxisAngle(_p, max);
          _b.copy(_a).applyQuaternion(_q);
          ang = max;
          e.v.multiplyScalar(0.5);
        }
        e.p.copy(_h).addScaledVector(_b, L);
        if (ang < 0.002) continue;
        // world (FILE) rotation offset q: a -> b; local' = parentRot^-1 q parentRot local
        _q.setFromUnitVectors(_a, _b);
        _pm.multiplyMatrices(_inv, parent.matrixWorld);
        _pm.decompose(_p, _pq, _s);
        _pqi.copy(_pq).invert();
        e.saved.copy(b.quaternion);
        b.quaternion.premultiply(_pq).premultiply(_q).premultiply(_pqi);
        b.updateMatrixWorld(true);
        this.modified.push(e);
        bones++;
      }
    }
    this.stats.actors = cand.length;
    this.stats.bones = bones;
  }

  /** Put the animated local rotations back (after the render). */
  restore() {
    const M = this.modified;
    for (let i = M.length - 1; i >= 0; i--) M[i].bone.quaternion.copy(M[i].saved);
    M.length = 0;
  }
}
