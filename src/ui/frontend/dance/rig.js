// Login dance: pose layer on the real Azure Knight PC rig (skel/character/swd.skel, 46 Bip01 bones).
//
// The dance is NOT a game clip. Every dance move is an authored keyframe clip (moves.js) evaluated here as an additive
// layer over a base game pose (the peace stand swd_non_stand_01, so the body keeps its native proportions/stance):
//   * bone rotations are authored in BODY space (x = character right, y = up, z = forward; degrees, Euler XYZ), so a
//     move reads the same on any Bip01 rig; the body frame is measured from the rig itself (shoulders, pelvis, head);
//   * hips/root translation in body space (metres);
//   * feet are planted by a two-bone IK (thigh-calf-foot) at targets in body space, so a hip wiggle bends the knees
//     instead of sliding the feet; a move may lift / slide a foot target (shuffle, strut).
// The mixer of the actor is re-evaluated (mixer.update(0)) before the layer is added, so the layer never accumulates
// across frames even when the actor's animation LOD skips an update.
import * as THREE from 'three';

export const BONES = {
  root: 'Bip01', pelvis: 'Bip01 Pelvis', spine: 'Bip01 Spine', chest: 'Bip01 Spine1', neck: 'Bip01 Neck', head: 'Bip01 Head',
  lClav: 'Bip01 L Clavicle', lArm: 'Bip01 L UpperArm', lFore: 'Bip01 L Forearm', lHand: 'Bip01 L Hand',
  rClav: 'Bip01 R Clavicle', rArm: 'Bip01 R UpperArm', rFore: 'Bip01 R Forearm', rHand: 'Bip01 R Hand',
  lThigh: 'Bip01 L Thigh', lCalf: 'Bip01 L Calf', lFoot: 'Bip01 L Foot', rThigh: 'Bip01 R Thigh', rCalf: 'Bip01 R Calf', rFoot: 'Bip01 R Foot',
};
// parents before children (rotation order of the layer)
const ORDER = ['pelvis', 'spine', 'chest', 'neck', 'head', 'lClav', 'lArm', 'lFore', 'lHand', 'rClav', 'rArm', 'rFore', 'rHand', 'lThigh', 'lCalf', 'lFoot', 'rThigh', 'rCalf', 'rFoot'];
const D2R = Math.PI / 180;
const _m = new THREE.Matrix4(), _inv = new THREE.Matrix4(), _q = new THREE.Quaternion(), _q2 = new THREE.Quaternion(), _q3 = new THREE.Quaternion();
const _v = new THREE.Vector3(), _v2 = new THREE.Vector3(), _v3 = new THREE.Vector3(), _e = new THREE.Euler();

export class DanceRig {
  /** @param {import('../../../engine/models.js').SkinnedInstance} instance */
  constructor(instance) {
    this.inst = instance;
    this.root = instance.root;
    this.b = {};
    for (const [k, n] of Object.entries(BONES)) this.b[k] = instance.getBone(n);
    this.ok = !!(this.b.root && this.b.pelvis && this.b.lThigh && this.b.rThigh);
    this.basis = null;          // body -> rig-root rotation
    this.feet = null;           // planted foot targets (rig-root space) captured from the stance
  }

  /** Rig-root-space matrix of a bone (the mirrored world root cancels out). */
  rel(bone, out = new THREE.Matrix4()) {
    this.root.updateMatrixWorld(true);
    _inv.copy(this.root.matrixWorld).invert();
    return out.multiplyMatrices(_inv, bone.matrixWorld);
  }
  pos(bone, out = new THREE.Vector3()) { return out.setFromMatrixPosition(this.rel(bone, _m)); }
  quat(bone, out = new THREE.Quaternion()) { this.rel(bone, _m).decompose(_v3, out, _v2); return out; }

  /** Measure the body frame on the current (stand) pose; capture planted foot positions. */
  calibrate() {
    if (!this.ok) return false;
    const l = this.pos(this.b.lArm, new THREE.Vector3()), r = this.pos(this.b.rArm, new THREE.Vector3());
    const pel = this.pos(this.b.pelvis, new THREE.Vector3()), head = this.pos(this.b.head, new THREE.Vector3());
    const x = r.clone().sub(l).normalize();
    const y0 = head.clone().sub(pel).normalize();
    const z = new THREE.Vector3().crossVectors(x, y0).normalize();
    const y = new THREE.Vector3().crossVectors(z, x).normalize();
    this.basis = new THREE.Matrix4().makeBasis(x, y, z);
    this.basisQ = new THREE.Quaternion().setFromRotationMatrix(this.basis);
    this.basisInvQ = this.basisQ.clone().invert();
    this.feet = { l: this.pos(this.b.lFoot, new THREE.Vector3()), r: this.pos(this.b.rFoot, new THREE.Vector3()) };
    this.legLen = this.pos(this.b.lThigh, new THREE.Vector3()).distanceTo(this.feet.l);
    // root-space units per metre (the rig may be authored in other units than the body scale)
    this.unit = 1;
    return true;
  }

  bodyToRoot(v, out = new THREE.Vector3()) { return out.copy(v).applyQuaternion(this.basisQ); }

  /** Rotate a bone by a rig-root-space rotation about its own pivot. */
  rotateRoot(bone, R) {
    const W = this.quat(bone, _q2);                         // current rig-root-space rotation
    // local' = local * (W^-1 R W)
    _q3.copy(W).invert().multiply(R).multiply(W);
    bone.quaternion.multiply(_q3).normalize();
    bone.updateMatrixWorld(true);
  }

  /** Body-space Euler (degrees) -> rig-root quaternion. */
  bodyRot(deg, out = new THREE.Quaternion()) {
    _e.set((deg[0] || 0) * D2R, (deg[1] || 0) * D2R, (deg[2] || 0) * D2R, 'YXZ');
    out.setFromEuler(_e);
    return out.premultiply(this.basisQ).multiply(this.basisInvQ);
  }

  /**
   * Apply one evaluated pose: { root:[x,y,z] m, bones:{alias:[x,y,z] deg}, lFoot:[x,y,z] m, rFoot:[x,y,z] m, ik:boolean }.
   * Call after the base clip was evaluated this frame.
   */
  apply(pose, weight = 1) {
    if (!this.ok || !this.basis || !pose || weight <= 0) return;
    const w = Math.min(1, weight);
    if (pose.root) {
      const d = this.bodyToRoot(_v.set(pose.root[0] * w, pose.root[1] * w, pose.root[2] * w));
      const p = this.b.root.parent;
      // Bip01's parent is the rig root (or a static helper under it): convert the root-space delta into its frame
      if (p && p !== this.root) { const pm = this.rel(p, new THREE.Matrix4()); const pr = new THREE.Quaternion(); pm.decompose(_v2, pr, _v3); d.applyQuaternion(pr.invert()).divide(_v3); }
      else d.divide(this.root.scale.clone().set(1, 1, 1));
      this.b.root.position.add(d);
      this.b.root.updateMatrixWorld(true);
    }
    const bones = pose.bones || {};
    for (const k of ORDER) {
      const deg = bones[k];
      if (!deg || !this.b[k]) continue;
      this.rotateRoot(this.b[k], this.bodyRot([deg[0] * w, deg[1] * w, deg[2] * w], _q));
    }
    if (pose.ik !== false && this.feet) {
      for (const side of ['l', 'r']) {
        const off = pose[side + 'Foot'];
        const t = this.bodyToRoot(_v.set(off?.[0] * w || 0, off?.[1] * w || 0, off?.[2] * w || 0)).add(this.feet[side]);
        this.solveLeg(side, t);
      }
    }
  }

  /** Analytic two-bone IK (thigh, calf) to put the foot at rig-root point t; keeps the knee in its current bend plane. */
  solveLeg(side, t) {
    const A = this.b[side + 'Thigh'], B = this.b[side + 'Calf'], C = this.b[side + 'Foot'];
    if (!A || !B || !C) return;
    const footQ = this.quat(C, new THREE.Quaternion());     // keep the foot's orientation (sole stays flat)
    const a = this.pos(A, new THREE.Vector3()), b = this.pos(B, new THREE.Vector3()), c = this.pos(C, new THREE.Vector3());
    const lab = a.distanceTo(b), lcb = b.distanceTo(c);
    const lat = Math.max(0.01, Math.min(a.distanceTo(t), (lab + lcb) * 0.999));
    const ac = c.clone().sub(a), ab = b.clone().sub(a), bc = c.clone().sub(b), at = t.clone().sub(a);
    const acL = ac.length() || 1e-6;
    const ac_ab0 = Math.acos(THREE.MathUtils.clamp(ac.dot(ab) / (acL * lab), -1, 1));
    const ba_bc0 = Math.acos(THREE.MathUtils.clamp(ab.clone().negate().dot(bc) / (lab * lcb), -1, 1));
    const ac_at0 = Math.acos(THREE.MathUtils.clamp(ac.dot(at) / (acL * at.length() || 1), -1, 1));
    const ac_ab1 = Math.acos(THREE.MathUtils.clamp((lcb * lcb - lab * lab - lat * lat) / (-2 * lab * lat), -1, 1));
    const ba_bc1 = Math.acos(THREE.MathUtils.clamp((lat * lat - lab * lab - lcb * lcb) / (-2 * lab * lcb), -1, 1));
    let axis0 = new THREE.Vector3().crossVectors(ac, ab);
    if (axis0.lengthSq() < 1e-10) axis0 = this.bodyToRoot(new THREE.Vector3(1, 0, 0));
    axis0.normalize();
    const axis1 = new THREE.Vector3().crossVectors(ac, at);
    this.rotateRoot(A, new THREE.Quaternion().setFromAxisAngle(axis0, ac_ab1 - ac_ab0));
    this.rotateRoot(B, new THREE.Quaternion().setFromAxisAngle(axis0, ba_bc1 - ba_bc0));
    if (axis1.lengthSq() > 1e-10) this.rotateRoot(A, new THREE.Quaternion().setFromAxisAngle(axis1.normalize(), ac_at0));
    // restore the foot's rig-root orientation
    const now = this.quat(C, new THREE.Quaternion());
    this.rotateRoot(C, footQ.multiply(now.invert()));
  }
}
