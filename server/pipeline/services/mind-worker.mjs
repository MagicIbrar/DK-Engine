// MIND worker (mob / NPC AI service), own thread. Opt-in through DK_MIND=1 (see mind.mjs).
// Input: one world snapshot copied out of Realm's tick (typed arrays, transferred, no JSON):
//   mon   Float64Array, 6 per monster: x, z, homeX, homeZ, sight, pursuit   (only idle aggressive monsters that look for a target)
//   mScene Int32Array, the scene of each monster
//   sOff  Int32Array, scene s owns players sOff[s] .. sOff[s+1]-1 (Realm's insertion order inside the scene)
//   pl    Float64Array, 2 per player: x, z
// Output: one ACQUIRE intent per monster: the players it could take as a target, in Realm's order (cOff / cand).
// The test is the acquisition rule widened by the two margins, so Realm can check the intent against the live world and still
// get exactly the target its own scan would pick (proof in mind.mjs). Realm stays authoritative: the worker never changes state.
import { parentPort, workerData } from 'node:worker_threads';
import { performance } from 'node:perf_hooks';
const PM = Number.isFinite(+workerData?.playerMargin) ? +workerData.playerMargin : 4, MM = Number.isFinite(+workerData?.monsterMargin) ? +workerData.monsterMargin : 4, EPS = 1e-6, CELL = 16;

function plan({ mon, mScene, sOff, pl }) {
  const M = mScene.length, S = sOff.length - 1;
  // per scene: a uniform grid of its players (cells of CELL), player indices kept ascending inside each cell
  const grids = new Array(S);
  for (let s = 0; s < S; s++) {
    const g = new Map();
    for (let i = sOff[s]; i < sOff[s + 1]; i++) {
      const x = pl[2 * i], z = pl[2 * i + 1];
      if (!Number.isFinite(x) || !Number.isFinite(z)) continue;   // Realm treats such a player as "moved" and tests it itself
      const key = Math.floor(x / CELL) * 1048576 + Math.floor(z / CELL);
      let c = g.get(key); if (!c) g.set(key, c = []); c.push(i);
    }
    grids[s] = g;
  }
  const cOff = new Int32Array(M + 1); let cand = new Int32Array(Math.max(64, M * 4)), n = 0;
  const found = [];
  for (let k = 0; k < M; k++) {
    cOff[k] = n;
    const o = 6 * k, mx = mon[o], mz = mon[o + 1], hx = mon[o + 2], hz = mon[o + 3], sight = mon[o + 4], pursuit = mon[o + 5], s = mScene[k];
    if (!(Number.isFinite(mx) && Number.isFinite(mz) && Number.isFinite(hx) && Number.isFinite(hz) && sight >= 0 && pursuit >= 0)) continue;
    if (Math.hypot(mx - hx, mz - hz) > pursuit + MM + EPS) continue;      // the monster itself is too far from its roaming centre
    const r = sight + MM + PM + EPS, rh = pursuit + PM + EPS;
    found.length = 0;
    const g = grids[s];
    if (g.size) {
      const x0 = Math.floor((mx - r) / CELL), x1 = Math.floor((mx + r) / CELL), z0 = Math.floor((mz - r) / CELL), z1 = Math.floor((mz + r) / CELL);
      if ((x1 - x0 + 1) * (z1 - z0 + 1) > g.size * 2) {
        for (let i = sOff[s]; i < sOff[s + 1]; i++) found.push(i);
      } else {
        for (let cx = x0; cx <= x1; cx++) for (let cz = z0; cz <= z1; cz++) { const c = g.get(cx * 1048576 + cz); if (c) for (const i of c) found.push(i); }
        found.sort((a, b) => a - b);
      }
    }
    for (const i of found) {
      const px = pl[2 * i], pz = pl[2 * i + 1];
      if (Math.hypot(px - mx, pz - mz) <= r && Math.hypot(px - hx, pz - hz) <= rh) {
        if (n === cand.length) { const grow = new Int32Array(cand.length * 2); grow.set(cand); cand = grow; }
        cand[n++] = i;
      }
    }
  }
  cOff[M] = n;
  return { cOff, cand: cand.slice(0, n) };
}

parentPort.on('message', msg => {
  if (!msg || msg.op !== 'plan') return;
  const t0 = performance.now();
  let out;
  try { out = plan(msg); } catch (error) { parentPort.postMessage({ op: 'error', gen: msg.gen, message: String(error?.message || error) }); return; }
  const ms = performance.now() - t0;
  parentPort.postMessage({ op: 'intents', gen: msg.gen, cOff: out.cOff, cand: out.cand, ms }, [out.cOff.buffer, out.cand.buffer]);
});
