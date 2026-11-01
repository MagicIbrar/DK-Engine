// A* path finding on the collision grid (FILE frame, 1 cell = 1 unit).
// 8 directions, no corner cutting (a diagonal step needs both orthogonal neighbours free), binary heap,
// node-expansion cap, then string pulling with the grid line of sight (Collision.lineOfSight).
// The target is snapped to the nearest walkable cell when it is blocked; an unreachable target yields a path to
// the reachable cell closest to it. Pure module (no three.js).

const SQRT2 = Math.SQRT2;
const DIRS = [[1, 0], [-1, 0], [0, 1], [0, -1], [1, 1], [1, -1], [-1, 1], [-1, -1]];

class MinHeap {
  constructor(cap = 4096) { this.ids = new Int32Array(cap); this.f = new Float32Array(cap); this.size = 0; }
  clear() { this.size = 0; }
  push(id, f) {
    if (this.size >= this.ids.length) {
      const ids = new Int32Array(this.ids.length * 2); ids.set(this.ids); this.ids = ids;
      const ff = new Float32Array(this.f.length * 2); ff.set(this.f); this.f = ff;
    }
    let i = this.size++;
    const I = this.ids, F = this.f;
    while (i > 0) {
      const p = (i - 1) >> 1;
      if (F[p] <= f) break;
      I[i] = I[p]; F[i] = F[p]; i = p;
    }
    I[i] = id; F[i] = f;
  }
  pop() { // returns id, or -1
    if (!this.size) return -1;
    const I = this.ids, F = this.f;
    const top = I[0];
    const n = --this.size;
    if (n > 0) {
      const id = I[n], f = F[n];
      let i = 0;
      for (;;) {
        let c = 2 * i + 1;
        if (c >= n) break;
        if (c + 1 < n && F[c + 1] < F[c]) c++;
        if (F[c] >= f) break;
        I[i] = I[c]; F[i] = F[c]; i = c;
      }
      I[i] = id; F[i] = f;
    }
    return top;
  }
}

export class PathFinder {
  /**
   * @param {import('./collision.js').Collision} collision
   * @param {{maxNodes?:number, snapRadius?:number}} [opts]
   */
  constructor(collision, { maxNodes = 80000, snapRadius = 24 } = {}) {
    this.col = collision;
    this.maxNodes = maxNodes;
    this.snapRadius = snapRadius;
    this.W = collision.width; this.H = collision.height;
    this._g = null; this._parent = null; this._seen = null; this._closed = null; this._gen = 0;
    this._heap = new MinHeap();
    this.lastStats = null;
  }

  _alloc() {
    const N = this.W * this.H;
    this._g = new Float32Array(N);
    this._parent = new Int32Array(N);
    this._seen = new Uint32Array(N);   // generation stamp: g/parent valid for this search
    this._closed = new Uint32Array(N); // generation stamp: expanded
  }

  /**
   * @returns {Array<{x:number,z:number}>|null} FILE-frame waypoints (start excluded); last = target or nearest
   *   walkable point. null when nothing walkable is reachable.
   */
  findPath(fx, fz, tx, tz) {
    const col = this.col, W = this.W;
    if (!Number.isFinite(fx + fz + tx + tz)) return null;
    // --- snap start / goal onto walkable cells
    let sx = fx, sz = fz;
    if (!col.isWalkable(sx, sz)) {
      const s = col.nearestWalkable(sx, sz, 6);
      if (!s) return null;
      sx = s.x; sz = s.z;
    }
    let gx = tx, gz = tz;
    if (!col.isWalkable(gx, gz)) {
      const g = col.nearestWalkable(gx, gz, this.snapRadius);
      if (!g) return null;
      gx = g.x; gz = g.z;
    }
    const startCell = Math.floor(sz) * W + Math.floor(sx);
    const goalCell = Math.floor(gz) * W + Math.floor(gx);
    const snappedStart = sx !== fx || sz !== fz;
    const prefix = snappedStart ? [{ x: sx, z: sz }] : [];
    if (startCell === goalCell || col.lineOfSight(sx, sz, gx, gz)) {
      this.lastStats = { expanded: 0, direct: true };
      return [...prefix, { x: gx, z: gz }];
    }

    // --- A*
    if (!this._g) this._alloc();
    const gen = ++this._gen;
    if (gen >= 0xFFFFFFF0) { this._seen.fill(0); this._closed.fill(0); this._gen = 1; }
    const G = this._g, P = this._parent, S = this._seen, C = this._closed, heap = this._heap;
    const H = this.H;
    const goalX = goalCell % W, goalZ = (goalCell / W) | 0;
    const hOf = (c) => {
      const dx = Math.abs((c % W) - goalX), dz = Math.abs(((c / W) | 0) - goalZ);
      return dx > dz ? dx + (SQRT2 - 1) * dz : dz + (SQRT2 - 1) * dx;
    };
    heap.clear();
    G[startCell] = 0; P[startCell] = -1; S[startCell] = gen;
    heap.push(startCell, hOf(startCell));
    let best = startCell, bestH = hOf(startCell);
    let expanded = 0, found = false;
    const cells = col.cells;
    while (heap.size) {
      const c = heap.pop();
      if (C[c] === gen) continue;
      C[c] = gen;
      if (c === goalCell) { found = true; break; }
      const h = hOf(c);
      if (h < bestH) { bestH = h; best = c; }
      if (++expanded > this.maxNodes) break;
      const cx = c % W, cz = (c / W) | 0, gc = G[c];
      for (let k = 0; k < 8; k++) {
        const dx = DIRS[k][0], dz = DIRS[k][1];
        const nx = cx + dx, nz = cz + dz;
        if (nx < 0 || nz < 0 || nx >= W || nz >= H) continue;
        const n = nz * W + nx;
        if (cells[n] || C[n] === gen) continue;
        let cost = 1;
        if (dx && dz) {
          if (cells[cz * W + nx] || cells[nz * W + cx]) continue; // no corner cutting
          cost = SQRT2;
        }
        const ng = gc + cost;
        if (S[n] === gen && ng >= G[n]) continue;
        S[n] = gen; G[n] = ng; P[n] = c;
        heap.push(n, ng + hOf(n));
      }
    }
    this.lastStats = { expanded, found, direct: false };
    let end = found ? goalCell : best;
    if (!found) {
      if (end === startCell) return null;
      gx = (end % W) + 0.5; gz = ((end / W) | 0) + 0.5;
    }
    // --- reconstruct (cell centres), then string-pull
    const chain = [];
    for (let c = end, guard = 0; c !== -1 && guard < W * H; c = P[c], guard++) chain.push(c);
    chain.reverse();
    const pts = chain.map(c => ({ x: (c % W) + 0.5, z: ((c / W) | 0) + 0.5 }));
    pts[0] = { x: sx, z: sz };
    pts[pts.length - 1] = { x: gx, z: gz };
    const out = this._pull(pts);
    return [...prefix, ...out];
  }

  /** Greedy string pulling: from each anchor jump to the farthest point still in line of sight. */
  _pull(pts) {
    const col = this.col, out = [];
    let i = 0;
    while (i < pts.length - 1) {
      let j = i + 1, misses = 0;
      for (let k = i + 2; k < pts.length; k++) {
        if (col.lineOfSight(pts[i].x, pts[i].z, pts[k].x, pts[k].z)) { j = k; misses = 0; }
        else if (++misses > 6) break; // allow short look-ahead past a blocked corner
      }
      out.push(pts[j]);
      i = j;
    }
    return out;
  }
}
