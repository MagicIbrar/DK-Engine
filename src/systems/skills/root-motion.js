// SKILL ROOT MOTION. A .anim keeps the displacement of the character origin apart from the Bip01 bone track
// (formats/anim.js: the bone tracks play in place). Global's own share/movecache.csv is the table of that End - Start
// displacement per animation (4,692 rows, every one >= 0.1 m: skill, basic-attack, damage, death and monster clips;
// e.g. SWD_SKL_COM_VIOLENCEFRICK_01..05 end 13.1 m forward, SWD_SKL_DUL_EIGENDASH_06 returns 5.6 m): the origin travels
// with the clip. One pure sampler shared by the offline engine, the host and the caster's prediction, so the
// accepted cast moves the same way everywhere.
//
// Curves are relative to the clip's first key (1,692 files continue an absolute combo curve, anim.js), sampled at the
// phase's normalised time (the clip is stretched over the phase, actor.js), and rotated by the caster's yaw in the FILE
// frame (models face local -Z: local (lx, lz) -> (lx cos + lz sin, -lx sin + lz cos)). Vertical root motion (7 of the
// 2,464 skill clips) is not applied to the ground position.

const EPS = 1e-4;

/** Table key of an anim path (as written in the class packs: anim/character/...). */
export function rootKey(anim) {
  return String(anim || '').trim().replace(/\\/g, '/').replace(/^\/+/, '').toLowerCase();
}

/** Horizontal root curve of a parsed rootMotion block, relative to its first key; null when it never leaves the origin. */
export function rootCurve(rm) {
  const n = rm?.times?.length || 0;
  if (n < 2) return null;
  const keys = [];
  for (let i = 0; i < n; i++) {
    const t = Number(rm.times[i]), x = Number(rm.x?.[i] ?? 0), z = Number(rm.z?.[i] ?? 0);
    if (Number.isFinite(t) && Number.isFinite(x) && Number.isFinite(z)) keys.push([t, x, z, i]);
  }
  if (keys.length < 2) return null;
  keys.sort((a, b) => a[0] - b[0] || a[3] - b[3]);
  const x0 = keys[0][1], z0 = keys[0][2];
  let moves = false;
  const t = [], x = [], z = [];
  for (const k of keys) {
    const dx = k[1] - x0, dz = k[2] - z0;
    if (Math.abs(dx) > EPS || Math.abs(dz) > EPS) moves = true;
    t.push(Math.min(1, Math.max(0, k[0]))); x.push(dx); z.push(dz);
  }
  return moves ? { t, x, z } : null;
}

/** Displacement {x, z} (model space) at normalised clip time u, linear between keys, clamped at both ends. */
export function sampleRootCurve(curve, u, out = { x: 0, z: 0 }) {
  const t = curve?.t;
  if (!t?.length) { out.x = 0; out.z = 0; return out; }
  const v = Math.min(1, Math.max(0, Number(u) || 0)), last = t.length - 1;
  if (v <= t[0]) { out.x = curve.x[0]; out.z = curve.z[0]; return out; }
  if (v >= t[last]) { out.x = curve.x[last]; out.z = curve.z[last]; return out; }
  let lo = 0, hi = last;
  while (hi - lo > 1) { const mid = (lo + hi) >> 1; if (t[mid] <= v) lo = mid; else hi = mid; }
  const span = t[hi] - t[lo], k = span > 0 ? (v - t[lo]) / span : 1;
  out.x = curve.x[lo] + (curve.x[hi] - curve.x[lo]) * k;
  out.z = curve.z[lo] + (curve.z[hi] - curve.z[lo]) * k;
  return out;
}

/** Model-space (lx, lz) -> FILE-frame (x, z) for an actor facing `yaw` (actor.js THE MIRROR RULE). */
export function rootToWorld(lx, lz, yaw, out = { x: 0, z: 0 }) {
  const c = Math.cos(yaw || 0), s = Math.sin(yaw || 0);
  out.x = lx * c + lz * s;
  out.z = -lx * s + lz * c;
  return out;
}

/** Anim of basic-attack combo step k of a (styled) class: the clip Player plays for 'attack' variant k (player.js _specFor). */
export function attackStepAnim(classDef, step) {
  const list = classDef?.anims?.attack || [];
  if (!list.length || !Number.isFinite(Number(step))) return null;
  const k = ((Number(step) | 0) % list.length + list.length) % list.length;
  return list[k]?.anim || null;
}

/** Root runs of overlapping clips: a combo step chains at its timing2 while the previous clip still plays to its end
 *  (movecache: each attack clip starts where the previous one ENDED), so every step's whole curve is travelled. */
export function startRootRun(runs, curve, yaw, len) {
  if (!curve || !(len > 0) || !Number.isFinite(yaw)) return null;
  const run = { curve, yaw, len, t: 0, lx: 0, lz: 0 };
  runs.push(run);
  return run;
}
/** Advance every run by dt; returns the summed FILE-frame displacement {x, z} and drops finished runs. */
export function advanceRootRuns(runs, dt, out = { x: 0, z: 0 }) {
  out.x = 0; out.z = 0;
  const s = { x: 0, z: 0 }, w = { x: 0, z: 0 };
  for (let i = runs.length - 1; i >= 0; i--) {
    const r = runs[i];
    r.t = Math.min(r.len, r.t + Math.max(0, Number(dt) || 0));
    sampleRootCurve(r.curve, r.t / r.len, s);
    rootToWorld(s.x - r.lx, s.z - r.lz, r.yaw, w);
    r.lx = s.x; r.lz = s.z;
    out.x += w.x; out.z += w.z;
    if (r.t >= r.len) runs.splice(i, 1);
  }
  return out;
}
/** Swept move from (x, z) by (dx, dz): walkable(x, z) is tested every `step` m; stops at the first blocked point. */
export function sweepRoot(x, z, dx, dz, walkable, step = 0.1) {
  const len = Math.hypot(dx, dz), n = Math.max(1, Math.ceil(len / step));
  let ax = x, az = z;
  if (!(len > 0)) return { x, z };
  for (let i = 1; i <= n; i++) {
    const nx = x + dx * i / n, nz = z + dz * i / n;
    if (walkable && !walkable(nx, nz)) break;
    ax = nx; az = nz;
  }
  return { x: ax, z: az };
}

/** Compact wire form {key: [t0, x0, z0, t1, x1, z1, ...]} rounded to 0.1 mm. */
export function encodeRootCurves(entries) {
  const out = {}, r = v => Math.round(v * 1e5) / 1e5;
  for (const [key, curve] of entries) {
    if (!curve) continue;
    const flat = [];
    for (let i = 0; i < curve.t.length; i++) flat.push(r(curve.t[i]), r(curve.x[i]), r(curve.z[i]));
    out[key] = flat;
  }
  return out;
}
export function decodeRootCurve(flat) {
  if (!Array.isArray(flat) || flat.length < 6 || flat.length % 3) return null;
  const t = [], x = [], z = [];
  for (let i = 0; i < flat.length; i += 3) {
    const a = Number(flat[i]), b = Number(flat[i + 1]), c = Number(flat[i + 2]);
    if (!Number.isFinite(a) || !Number.isFinite(b) || !Number.isFinite(c)) return null;
    t.push(a); x.push(b); z.push(c);
  }
  return { t, x, z };
}

/**
 * Process-wide table anim key -> curve (null = the clip was read and does not move). The host fills it from the
 * prepared data (server/skill-root-motion.mjs); a browser fills it from the same table per class pack (SkillData).
 * Anim paths are unique per class folder, so one table serves every class, caster and observer.
 */
const TABLE = new Map();
export const rootMotionCurves = {
  get(anim) { return TABLE.get(rootKey(anim)) || null; },
  known(anim) { return TABLE.has(rootKey(anim)); },
  set(anim, curve) { TABLE.set(rootKey(anim), curve || null); },
  /** Merge a decoded wire table ({key: flat}); entries already known keep their value. Returns the count added. */
  load(encoded) {
    let added = 0;
    for (const [key, flat] of Object.entries(encoded || {})) {
      const k = rootKey(key);
      if (TABLE.has(k)) continue;
      TABLE.set(k, decodeRootCurve(flat));
      added++;
    }
    return added;
  },
  clear() { TABLE.clear(); },
  get size() { return TABLE.size; },
};
