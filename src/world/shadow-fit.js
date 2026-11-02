// Sun shadow framing of the Global client (LANE-66 rev c): a behavioural port of the light view/projection builder
// FUN_01541680 (32-bit) / FUN_7ff671678530 (64-bit), with its helpers FUN_015413c0 (bounds), FUN_01541a50 (far
// distance + virtual eye), FUN_01541c10 (view body) and FUN_01542400 (light-space perspective fit). Written from the
// observed behaviour, not from the decompiled code. Pure functions, browser + Node.
//
// Everything here works in the FILE frame (D3D, left handed: x = col, y = up, z = row) with D3D row-vector matrices
// (16 numbers, row major, p' = p x M). toThreeShadowMatrix() converts the result for three.js (worldRoot mirrors z).
//
// Constants (32-bit data address / 64-bit cross-check):
//   MIN_RADIUS 10      @DAT_01b7e2c4  (64-bit same value)   simple branch: half size = max(10, eye distance)
//   ORTHO_NEAR 1, ORTHO_FAR 800        FUN_01541680 / 64-bit 0x44480000 (800.0)
//   EYE_LIFT 4         @DAT_01b7e278   complex branch: virtual eye / look-at height above the target
//   CLOSE_DIST 10      @DAT_01b7e2c4   (same constant, compare at 0x01541854) below it the virtual eye moves in:
//                      c = cos((d/10) x pi/2) (pi/2 @DAT_01b7e1dc, cos 0x0077ba50), far -= (far - 2) c (2 @DAT_01b7e228)
//   NEAR_PUSH 1.1      @DAT_01b7e1cc (64-bit 0x7ff671e84f5c)  view-body expansion of the near face; far face 0.1
//   LISP_B -2          @DAT_01b7e438 (64-bit 0x7ff671e85240)  -2(n+dY)n/dY of the warp matrix
//   AABB_INIT 100000   FUN_01542400 helper (64-bit 9240) min/max start values
export const SHADOW_FIT = Object.freeze({
  MIN_RADIUS: 10, ORTHO_NEAR: 1, ORTHO_FAR: 800, EYE_LIFT: 4, CLOSE_DIST: 10, NEAR_PUSH: 1.1, FAR_PUSH: 0.1,
  LISP_B: -2, AABB_INIT: 100000, CLOSE_MIN_FAR: 2,
});

// ------------------------------------------------------------------ small vector / matrix helpers (FILE frame)
const sub = (a, b) => [a[0] - b[0], a[1] - b[1], a[2] - b[2]];
const add = (a, b) => [a[0] + b[0], a[1] + b[1], a[2] + b[2]];
const mul = (a, s) => [a[0] * s, a[1] * s, a[2] * s];
const dot = (a, b) => a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
const cross = (a, b) => [a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]];
const len = a => Math.hypot(a[0], a[1], a[2]);
const norm = a => { const l = len(a); return l > 1e-12 ? mul(a, 1 / l) : [0, 0, 0]; };

export function matMul(a, b) {
  const o = new Array(16).fill(0);
  for (let r = 0; r < 4; r++) for (let c = 0; c < 4; c++) {
    let s = 0;
    for (let k = 0; k < 4; k++) s += a[r * 4 + k] * b[k * 4 + c];
    o[r * 4 + c] = s;
  }
  return o;
}
/** Row vector [x y z 1] x M, divided by w (D3DXVec3TransformCoord). */
export function transformCoord(p, m) {
  const x = p[0] * m[0] + p[1] * m[4] + p[2] * m[8] + m[12];
  const y = p[0] * m[1] + p[1] * m[5] + p[2] * m[9] + m[13];
  const z = p[0] * m[2] + p[1] * m[6] + p[2] * m[10] + m[14];
  const w = p[0] * m[3] + p[1] * m[7] + p[2] * m[11] + m[15];
  return [x / w, y / w, z / w];
}
export function matInvert(m) {
  const a = m.slice(), inv = [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1];
  for (let c = 0; c < 4; c++) {
    let p = c;
    for (let r = c + 1; r < 4; r++) if (Math.abs(a[r * 4 + c]) > Math.abs(a[p * 4 + c])) p = r;
    if (Math.abs(a[p * 4 + c]) < 1e-20) return null;
    if (p !== c) for (let k = 0; k < 4; k++) { [a[c * 4 + k], a[p * 4 + k]] = [a[p * 4 + k], a[c * 4 + k]]; [inv[c * 4 + k], inv[p * 4 + k]] = [inv[p * 4 + k], inv[c * 4 + k]]; }
    const d = a[c * 4 + c];
    for (let k = 0; k < 4; k++) { a[c * 4 + k] /= d; inv[c * 4 + k] /= d; }
    for (let r = 0; r < 4; r++) if (r !== c) {
      const f = a[r * 4 + c];
      if (f) for (let k = 0; k < 4; k++) { a[r * 4 + k] -= f * a[c * 4 + k]; inv[r * 4 + k] -= f * inv[c * 4 + k]; }
    }
  }
  return inv;
}
/** D3DXMatrixLookAtLH. */
export function lookAtLH(eye, at, up) {
  const z = norm(sub(at, eye)), x = norm(cross(up, z)), y = cross(z, x);
  return [x[0], y[0], z[0], 0, x[1], y[1], z[1], 0, x[2], y[2], z[2], 0, -dot(x, eye), -dot(y, eye), -dot(z, eye), 1];
}
/** D3DXMatrixOrthoLH. */
export function orthoLH(w, h, zn, zf) {
  return [2 / w, 0, 0, 0, 0, 2 / h, 0, 0, 0, 0, 1 / (zf - zn), 0, 0, 0, zn / (zn - zf), 1];
}
/** D3DXMatrixPerspectiveFovLH (fovy in radians). */
export function perspectiveFovLH(fovy, aspect, zn, zf) {
  const ys = 1 / Math.tan(fovy / 2), xs = ys / aspect;
  return [xs, 0, 0, 0, 0, ys, 0, 0, 0, 0, zf / (zf - zn), 1, 0, 0, -zn * zf / (zf - zn), 0];
}
function aabb(points, m) {
  const I = SHADOW_FIT.AABB_INIT;
  const mn = [I, I, I], mx = [-I, -I, -I];
  for (const p of points) {
    const q = transformCoord(p, m);
    for (let k = 0; k < 3; k++) { if (q[k] < mn[k]) mn[k] = q[k]; if (q[k] > mx[k]) mx[k] = q[k]; }
  }
  return { mn, mx };
}
// D3DX LookAt needs an up vector that is not parallel to the view direction; Global passes (0,1,0) and would build a
// degenerate matrix for a sun exactly overhead. [judgment] a tiny z tilt keeps the matrix finite in that one case.
function safeUp(dir) {
  const d = norm(dir);
  return Math.abs(d[1]) > 0.999999 ? [0, 1, 1e-4] : [0, 1, 0];
}

// ------------------------------------------------------------------ FUN_015413c0 + simple branch (level <= 1)
/**
 * Simple framing: light eye = target + L x d, centred orthographic box of side max(w, h) + 1 where (w, h) is the
 * rectangle [max(0, t - r), t + r] (r = max(10, d)) truncated to whole cells and clamped to the map extent.
 * @returns {{view:number[], proj:number[], matrix:number[], size:number, eye:number[]}|null}
 */
export function simpleShadowFit({ target, camPos, lightDir, bounds }) {
  const L = norm(lightDir), d = len(sub(camPos, target));
  if (!(d > 1e-6) || !len(L)) return null;   // eye on the target: LookAtLH has no direction
  const r = Math.max(SHADOW_FIT.MIN_RADIUS, d);
  // [judgment] the clamp rectangle lives at the shadow object +0x288..+0x294 (source not traced); the map extent is used
  const bx1 = bounds ? bounds.maxX : Infinity, bz1 = bounds ? bounds.maxZ : Infinity;
  const x0 = Math.trunc(Math.max(0, target[0] - r)), x1 = Math.trunc(Math.min(bx1, target[0] + r));
  const z0 = Math.trunc(Math.max(0, target[2] - r)), z1 = Math.trunc(Math.min(bz1, target[2] + r));
  const size = Math.max(x1 - x0, z1 - z0) + 1;
  const eye = add(target, mul(L, d));
  const view = lookAtLH(eye, target, safeUp(L));
  const proj = orthoLH(size, size, SHADOW_FIT.ORTHO_NEAR, SHADOW_FIT.ORTHO_FAR);
  return { view, proj, matrix: matMul(view, proj), size, eye, branch: 'simple' };
}

// ------------------------------------------------------------------ FUN_01541a50: far distance + virtual eye
/**
 * @param {{target:number[], camPos:number[], camView:number[], camNear:number, sceneCorners:number[][]}} o
 *   camView = the main camera's LH view matrix (FILE frame), sceneCorners = the 8 corners of the scene box
 */
export function virtualEye({ target, camPos, camView, camNear, sceneCorners }) {
  let maxZ = 0;
  for (const p of sceneCorners) { const q = transformCoord(p, camView); if (q[2] > maxZ) maxZ = q[2]; }
  let far = camNear + Math.max(0, maxZ);
  const d = len(sub(camPos, target));
  let dirH = norm([camPos[0] - target[0], 0, camPos[2] - target[2]]);
  if (!len(dirH)) dirH = [0, 0, -1];   // [judgment] camera straight above the target: Global normalises a zero vector
  let eye, at;
  if (d >= SHADOW_FIT.CLOSE_DIST) {
    eye = [camPos[0], target[1] + SHADOW_FIT.EYE_LIFT, camPos[2]];
    at = [target[0], target[1] + SHADOW_FIT.EYE_LIFT, target[2]];
  } else {
    const c = Math.cos((d / SHADOW_FIT.CLOSE_DIST) * Math.PI / 2);
    far = far - (far - SHADOW_FIT.CLOSE_MIN_FAR) * c;
    const n3 = norm(sub(target, camPos));
    eye = add(target, mul(dirH, 2 * Math.abs(n3[1]) + c + len(dirH)));
    at = target.slice();
  }
  return { eye, at, far, dist: d };
}

// ------------------------------------------------------------------ FUN_01541c10: the view body
export function viewBody({ view, fovy, near, far }) {
  const vp = matMul(view, perspectiveFovLH(fovy, 1.0, near, far));
  const inv = matInvert(vp);
  if (!inv) return null;
  const face = z => [[-1, -1, z], [1, -1, z], [1, 1, z], [-1, 1, z]].map(p => transformCoord(p, inv));
  const grow = (pts, k) => {
    const c = mul(pts.reduce((s, p) => add(s, p), [0, 0, 0]), 0.25);
    return pts.map(p => add(p, mul(sub(p, c), k)));
  };
  return [...grow(face(0), SHADOW_FIT.NEAR_PUSH), ...grow(face(1), SHADOW_FIT.FAR_PUSH)];
}

// ------------------------------------------------------------------ FUN_01542400: light-space perspective fit
export function lispFit({ eye, at, lightDir, body }) {
  const L = norm(lightDir);
  const v = norm(sub(at, eye));
  const up = norm(cross(cross(L, v), L));
  if (!len(up)) return null;   // view direction parallel to the light: no warp axis
  const lightView = lookAtLH(eye, sub(eye, L), up);
  const b0 = aabb(body, lightView);
  const sinG = Math.sin(Math.abs(Math.acos(Math.max(-1, Math.min(1, dot(v, L))))));
  if (!(sinG > 1e-6)) return null;
  const zn = 1 / sinG, dY = Math.abs(b0.mx[1] - b0.mn[1]);
  if (!(dY > 1e-9)) return null;
  const n = (Math.sqrt((dY * sinG + zn) * zn) + zn) / sinG;
  const pos = sub(eye, mul(up, n - 1));
  const view = lookAtLH(pos, sub(pos, L), up);
  const lisp = [1, 0, 0, 0, 0, (2 * n + dY) / dY, 0, 1, 0, 0, 1, 0, 0, SHADOW_FIT.LISP_B * (n + dY) * n / dY, 0, 0];
  const b1 = aabb(body, matMul(view, lisp));
  const dx = b1.mx[0] - b1.mn[0], dy = b1.mx[1] - b1.mn[1], dz = b1.mx[2] - b1.mn[2];
  if (!(dx > 1e-12 && dy > 1e-12 && dz > 1e-12)) return null;
  const fit = [2 / dx, 0, 0, 0, 0, 2 / dy, 0, 0, 0, 0, 2 / dz, 0,
    -(b1.mn[0] + b1.mx[0]) / dx, -(b1.mn[1] + b1.mx[1]) / dy, -(b1.mn[2] + b1.mx[2]) / dz, 1];
  const zfix = [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0.5, 0, 0, 0, 0.5, 1];
  const proj = matMul(matMul(lisp, fit), zfix);
  return { view, proj, matrix: matMul(view, proj), n, dY, sinG, pos, up };
}

/**
 * FUN_01541680: shadow level <= 1 -> simple orthographic framing; level >= 2 -> virtual eye + view body + LiSPSM fit.
 * Degenerate complex cases (light parallel to the view, empty body) use the simple framing [judgment: Global would
 * build a non-finite matrix there].
 * @param {object} o {level, target, camPos, lightDir, bounds:{maxX,maxZ,minY,maxY}, camView, camNear, fovy}
 */
export function globalShadowFit(o) {
  if (!(o.level >= 2)) return simpleShadowFit(o);
  const b = o.bounds;
  const corners = [];
  for (const x of [0, b.maxX]) for (const y of [b.minY, b.maxY]) for (const z of [0, b.maxZ]) corners.push([x, y, z]);
  const ve = virtualEye({ target: o.target, camPos: o.camPos, camView: o.camView, camNear: o.camNear, sceneCorners: corners });
  const view = lookAtLH(ve.eye, ve.at, [0, 1, 0]);
  const body = ve.far > o.camNear ? viewBody({ view, fovy: o.fovy, near: o.camNear, far: ve.far }) : null;
  const fit = body && lispFit({ eye: ve.eye, at: ve.at, lightDir: o.lightDir, body });
  const ok = fit && fit.matrix.every(Number.isFinite);
  if (!ok) return simpleShadowFit(o);
  return { ...fit, branch: 'lispsm', virtual: ve, body, eye: add(o.target, mul(norm(o.lightDir), ve.dist)) };
}

/**
 * three.js clip matrix (column-vector, GL depth -1..1) of a FILE-frame D3D world -> clip matrix, for objects whose
 * three world position is FILE (x, y, -z). Returns 16 numbers in THREE.Matrix4.set() order (row major).
 */
export function toThreeShadowMatrix(m) {
  // column form C = M^T; GL depth z' = 2z - w; the worldRoot mirror negates the z input column
  const C = [m[0], m[4], m[8], m[12], m[1], m[5], m[9], m[13], m[2], m[6], m[10], m[14], m[3], m[7], m[11], m[15]];
  for (let c = 0; c < 4; c++) C[8 + c] = 2 * C[8 + c] - C[12 + c];
  for (let r = 0; r < 4; r++) C[r * 4 + 2] = -C[r * 4 + 2];
  return C;
}
