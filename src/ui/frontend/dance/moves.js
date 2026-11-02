// Login dance move clips: OUR OWN keyframed remake of the signature moves of the LMFAO "Sexy and I Know It" video,
// authored for the Azure Knight Bip01 rig (rig.js). No game dance clip and no third-party animation is used.
//
// A move is a loop of `beats` beats. Each key: { b: beat within the loop, root:[x,y,z] m, bones:{alias:[x,y,z] deg},
// lFoot / rFoot:[x,y,z] m (IK foot target offset from the planted stance) }. Body space: x = character right, y = up,
// z = forward. Rotations (Euler YXZ, degrees): +x leans / swings a part forward-down, +y turns it to the right,
// +z rolls it towards its left (for an arm: rArm +z / lArm -z raise the arm out sideways).
// Missing channels in a key hold 0. Keys are eased with a cosine (ease: 'smooth') or Catmull-Rom (ease: 'spline').
// These are first drafts, to be refined against the move-by-move breakdown of the video (choreography.json).
// AMPLIFIED 1.85x (2026-10-27) so throne-character dance reads clearly in preview; tune down after reference watch.

/** Elbows bent, fists by the chest (shared arm shape for the wiggle). */
const ARMS_UP = { lArm: [-46.25, 0, -64.75], rArm: [-46.25, 0, 64.75], lFore: [-175.8, 0, 0], rFore: [-175.8, 0, 0] };
const add = (a, b) => { const o = { ...a }; for (const [k, v] of Object.entries(b)) o[k] = o[k] ? o[k].map((x, i) => x + (v[i] || 0)) : v; return o; };

export const MOVES = {
  // ---- the core move: hips wiggle side to side, one side per beat, knees soft, upper body counters
  wiggle: {
    label: 'Hip wiggle', beats: 2, ease: 'smooth',
    keys: [
      { b: 0,   root: [0.1573, -0.1295, 0], bones: add(ARMS_UP, { pelvis: [0, -18.5, 20.35], chest: [0, 11.1, -25.9], head: [0, 0, 9.25], lArm: [0, 0, -11.1] }) },
      { b: 0.5, root: [0, -0.06475, 0], bones: add(ARMS_UP, { pelvis: [0, 0, 0], chest: [0, 0, 0] }) },
      { b: 1,   root: [-0.1573, -0.1295, 0], bones: add(ARMS_UP, { pelvis: [0, 18.5, -20.35], chest: [0, -11.1, 25.9], head: [0, 0, -9.25], rArm: [0, 0, 11.1] }) },
      { b: 1.5, root: [0, -0.06475, 0], bones: add(ARMS_UP, { pelvis: [0, 0, 0], chest: [0, 0, 0] }) },
    ],
  },
  // ---- shuffle / running man: one knee comes up while the other foot slides back, a step per beat, arms pump
  shuffle: {
    label: 'Shuffle (running man)', beats: 2, ease: 'smooth',
    keys: [
      { b: 0,    root: [0, -0.1665, 0], lFoot: [0, 0, 0],        rFoot: [0, 0, -0.296], bones: { chest: [14.8, 0, 0], lArm: [-64.75, 0, -14.8], rArm: [55.5, 0, 14.8], lFore: [-148, 0, 0], rFore: [-148, 0, 0] } },
      { b: 0.5,  root: [0, -0.0555, 0], lFoot: [0, 0, -0.148],    rFoot: [0, 0.296, 0.185], bones: { chest: [9.25, 0, 0], lFore: [-148, 0, 0], rFore: [-148, 0, 0] } },
      { b: 1,    root: [0, -0.1665, 0], lFoot: [0, 0, -0.296],    rFoot: [0, 0, 0],      bones: { chest: [14.8, 0, 0], lArm: [55.5, 0, -14.8], rArm: [-64.75, 0, 14.8], lFore: [-148, 0, 0], rFore: [-148, 0, 0] } },
      { b: 1.5,  root: [0, -0.0555, 0], lFoot: [0, 0.296, 0.185],   rFoot: [0, 0, -0.148],  bones: { chest: [9.25, 0, 0], lFore: [-148, 0, 0], rFore: [-148, 0, 0] } },
    ],
  },
  // ---- the strut: chin up, chest out, a swaggering step per beat with hip and shoulder roll (in place, or travelling
  //      when a section gives it a path; the controller then moves the body along it)
  strut: {
    label: 'Strut walk', beats: 2, ease: 'smooth', stride: 0.77,
    keys: [
      { b: 0,   root: [0.074, -0.0555, 0], lFoot: [0, 0, 0.259],  rFoot: [0, 0, -0.259], bones: { pelvis: [0, -16.65, 7.4],  chest: [-14.8, 22.2, -5.55], head: [-18.5, -11.1, 0], lArm: [40.7, 0, -18.5], rArm: [-33.3, 0, 18.5], rFore: [-46.25, 0, 0], lFore: [-18.5, 0, 0] } },
      { b: 0.5, root: [0, 0.0185, 0],  lFoot: [0, 0, 0],     rFoot: [0, 0.222, 0],  bones: { chest: [-14.8, 0, 0], head: [-18.5, 0, 0] } },
      { b: 1,   root: [-0.074, -0.0555, 0], lFoot: [0, 0, -0.259], rFoot: [0, 0, 0.259],  bones: { pelvis: [0, 16.65, -7.4],  chest: [-14.8, -22.2, 5.55], head: [-18.5, 11.1, 0], lArm: [-33.3, 0, -18.5], rArm: [40.7, 0, 18.5], lFore: [-46.25, 0, 0], rFore: [-18.5, 0, 0] } },
      { b: 1.5, root: [0, 0.0185, 0],  lFoot: [0, 0.222, 0],  rFoot: [0, 0, 0],     bones: { chest: [-14.8, 0, 0], head: [-18.5, 0, 0] } },
    ],
  },
  // ---- arm / chest pose moments: double-biceps flex held, then pec pops on the beat with a head nod
  chestPose: {
    label: 'Flex + chest pop', beats: 4, ease: 'smooth',
    keys: [
      { b: 0,    root: [0, -0.074, 0], bones: { chest: [-18.5, 0, 0], head: [-11.1, 0, 0], lArm: [0, 0, -151.7], rArm: [0, 0, 151.7], lFore: [0, 0, -175.8], rFore: [0, 0, 175.8] } },
      { b: 1.75, root: [0, -0.0925, 0], bones: { chest: [-22.2, 0, 0], head: [-14.8, 0, 0], lArm: [0, 0, -159.1], rArm: [0, 0, 159.1], lFore: [0, 0, -194.2], rFore: [0, 0, 194.2] } },
      { b: 2,    root: [0, -0.037, 0], bones: { chest: [-29.6, 0, 0], head: [7.4, 0, 0], lArm: [-18.5, 0, -74], rArm: [-18.5, 0, 74], lFore: [-185, 0, 0], rFore: [-185, 0, 0] } },
      { b: 2.5,  root: [0, -0.0925, 0], bones: { chest: [-7.4, 0, 0], head: [-11.1, 0, 0], lArm: [-18.5, 0, -70.3], rArm: [-18.5, 0, 70.3], lFore: [-185, 0, 0], rFore: [-185, 0, 0] } },
      { b: 3,    root: [0, -0.037, 0], bones: { chest: [-29.6, 0, 0], head: [7.4, 0, 0], lArm: [-18.5, 0, -74], rArm: [-18.5, 0, 74], lFore: [-185, 0, 0], rFore: [-185, 0, 0] } },
      { b: 3.5,  root: [0, -0.0925, 0], bones: { chest: [-7.4, 0, 0], head: [-11.1, 0, 0], lArm: [-9.25, 0, -111], rArm: [-9.25, 0, 111], lFore: [-55.5, 0, -111], rFore: [-55.5, 0, 111] } },
    ],
  },
  // neutral dance stance (used to blend in / out of sections)
  stance: { label: 'Stance', beats: 1, ease: 'smooth', keys: [{ b: 0, root: [0, -0.0555, 0] }] },
};

const CHANNELS = ['root', 'lFoot', 'rFoot'];
function lerp3(a, b, t) { return [0, 1, 2].map(i => (a?.[i] || 0) + ((b?.[i] || 0) - (a?.[i] || 0)) * t); }
function cr(p0, p1, p2, p3, t) { const t2 = t * t, t3 = t2 * t; return 0.5 * (2 * p1 + (-p0 + p2) * t + (2 * p0 - 5 * p1 + 4 * p2 - p3) * t2 + (-p0 + 3 * p1 - 3 * p2 + p3) * t3); }
function spline3(a, b, c, d, t) { return [0, 1, 2].map(i => cr(a?.[i] || 0, b?.[i] || 0, c?.[i] || 0, d?.[i] || 0, t)); }

/** Evaluate a move at `beat` (beats since the move started; it loops). Returns a pose for DanceRig.apply. */
export function evalMove(move, beat) {
  const keys = move.keys, n = keys.length, L = move.beats;
  if (n === 1) return clonePose(keys[0]);
  const ph = ((beat % L) + L) % L;
  let i = n - 1;
  for (let k = 0; k < n; k++) if (keys[k].b <= ph) i = k;
  const k1 = keys[i], k2 = keys[(i + 1) % n];
  const span = (i + 1 < n ? k2.b : k2.b + L) - k1.b;
  let t = span > 0 ? (ph - k1.b) / span : 0;
  if (move.ease === 'spline') {
    const k0 = keys[(i - 1 + n) % n], k3 = keys[(i + 2) % n];
    const out = { bones: {} };
    for (const c of CHANNELS) out[c] = spline3(k0[c], k1[c], k2[c], k3[c], t);
    for (const name of boneNames(k0, k1, k2, k3)) out.bones[name] = spline3(k0.bones?.[name], k1.bones?.[name], k2.bones?.[name], k3.bones?.[name], t);
    return out;
  }
  t = 0.5 - 0.5 * Math.cos(Math.PI * t);
  return mixPose(k1, k2, t);
}

function boneNames(...ks) { const s = new Set(); for (const k of ks) for (const n of Object.keys(k.bones || {})) s.add(n); return s; }
export function clonePose(k) { return { root: lerp3(k.root, k.root, 0), lFoot: lerp3(k.lFoot, k.lFoot, 0), rFoot: lerp3(k.rFoot, k.rFoot, 0), bones: Object.fromEntries(Object.entries(k.bones || {}).map(([n, v]) => [n, [...v]])) }; }
/** Blend two poses (t = 0 -> a, 1 -> b). */
export function mixPose(a, b, t) {
  const out = { bones: {} };
  for (const c of CHANNELS) out[c] = lerp3(a?.[c], b?.[c], t);
  for (const name of boneNames(a || {}, b || {})) out.bones[name] = lerp3(a?.bones?.[name], b?.bones?.[name], t);
  return out;
}
