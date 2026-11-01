// Walkable object surfaces (bridges, decks, frozen lakes, sky platforms): the triangles of the mesh helpers named
// 'ground*' (docs/formats/mesh.md, coords.md "Height and collision"), placed with the object's .mol transform
// in the FILE frame. Stored in a 2D bucket grid for fast height queries.
// Rule (coords.md): Y = max(terrain, highest ground-helper hit <= current Y + step).
// Pure module (no three.js).

export class GroundSurfaces {
  constructor(width = 512, height = 512, bucket = 8) {
    this.bucket = bucket;
    this.bw = Math.ceil((width + 32) / bucket) + 1;
    this.bh = Math.ceil((height + 32) / bucket) + 1;
    this.off = 16; // allow slightly off-map objects
    this.tris = new Float32Array(9 * 1024);
    this.count = 0;
    this.buckets = new Map(); // bucket index -> number[] of triangle ids
  }

  get size() { return this.count; }

  _bucketIndex(bx, bz) { return bz * this.bw + bx; }

  /**
   * Add a helper's triangles.
   * @param {Float32Array} positions  model-space positions (xyz), FILE frame
   * @param {Uint16Array|Uint32Array|number[]} indices  triangle list
   * @param {ArrayLike<number>} m  column-major 4x4 FILE-frame placement matrix (THREE.Matrix4.elements)
   */
  addMesh(positions, indices, m) {
    const start = this.count;
    const tp = (i) => {
      const x = positions[i * 3], y = positions[i * 3 + 1], z = positions[i * 3 + 2];
      return [m[0] * x + m[4] * y + m[8] * z + m[12], m[1] * x + m[5] * y + m[9] * z + m[13], m[2] * x + m[6] * y + m[10] * z + m[14]];
    };
    const n = indices ? indices.length : positions.length / 3;
    for (let k = 0; k + 2 < n; k += 3) {
      const a = tp(indices ? indices[k] : k), b = tp(indices ? indices[k + 1] : k + 1), c = tp(indices ? indices[k + 2] : k + 2);
      // keep walkable (upward or downward facing, i.e. not vertical) faces only
      const ux = b[0] - a[0], uy = b[1] - a[1], uz = b[2] - a[2];
      const vx = c[0] - a[0], vy = c[1] - a[1], vz = c[2] - a[2];
      const nx = uy * vz - uz * vy, ny = uz * vx - ux * vz, nz = ux * vy - uy * vx;
      const len = Math.hypot(nx, ny, nz);
      if (!(len > 1e-9) || Math.abs(ny) / len < 0.35) continue;
      this._push(a, b, c);
    }
    const count = this.count - start, baseY = new Float32Array(count * 3);
    for (let i = 0; i < count; i++) for (let k = 0; k < 3; k++) baseY[i * 3 + k] = this.tris[(start + i) * 9 + k * 3 + 1];
    return { start, count, baseY, placementY: m[13] };
  }

  /** Pure Y translation keeps XZ bucket membership and triangle identity intact.
   * Always derive from immutable helper Y values, so cancel cannot accumulate drift. */
  setMeshY(range, placementY) {
    if (!range || !Number.isInteger(range.start) || !Number.isInteger(range.count) || range.start < 0 || range.start + range.count > this.count || range.baseY?.length !== range.count * 3 || !Number.isFinite(placementY)) throw Error('Invalid ground-helper range.');
    const delta = placementY - range.placementY;
    for (let i = 0; i < range.count; i++) for (let k = 0; k < 3; k++) this.tris[(range.start + i) * 9 + k * 3 + 1] = range.baseY[i * 3 + k] + delta;
  }

  _push(a, b, c) {
    if ((this.count + 1) * 9 > this.tris.length) {
      const t = new Float32Array(this.tris.length * 2); t.set(this.tris); this.tris = t;
    }
    const id = this.count++, o = id * 9;
    this.tris.set(a, o); this.tris.set(b, o + 3); this.tris.set(c, o + 6);
    const B = this.bucket, off = this.off;
    const x0 = Math.floor((Math.min(a[0], b[0], c[0]) + off) / B), x1 = Math.floor((Math.max(a[0], b[0], c[0]) + off) / B);
    const z0 = Math.floor((Math.min(a[2], b[2], c[2]) + off) / B), z1 = Math.floor((Math.max(a[2], b[2], c[2]) + off) / B);
    for (let bz = Math.max(0, z0); bz <= Math.min(this.bh - 1, z1); bz++) {
      for (let bx = Math.max(0, x0); bx <= Math.min(this.bw - 1, x1); bx++) {
        const k = this._bucketIndex(bx, bz);
        let list = this.buckets.get(k);
        if (!list) this.buckets.set(k, (list = []));
        list.push(id);
      }
    }
  }

  /**
   * Highest surface height at (x, z) that is <= maxY, or -Infinity.
   * @param {number} x FILE X
   * @param {number} z FILE Z
   * @param {number} [maxY=Infinity]
   */
  heightAt(x, z, maxY = Infinity) { return this.surfaceAt(x, z, maxY)?.height ?? -Infinity; }

  surfaceAt(x, z, maxY = Infinity) {
    const B = this.bucket;
    const bx = Math.floor((x + this.off) / B), bz = Math.floor((z + this.off) / B);
    if (bx < 0 || bz < 0 || bx >= this.bw || bz >= this.bh) return null;
    const list = this.buckets.get(this._bucketIndex(bx, bz));
    if (!list) return null;
    const T = this.tris;
    let best = -Infinity, id = -1;
    for (let i = 0; i < list.length; i++) {
      const o = list[i] * 9;
      const ax = T[o], ay = T[o + 1], az = T[o + 2];
      const bxv = T[o + 3] - ax, byv = T[o + 4] - ay, bzv = T[o + 5] - az;
      const cxv = T[o + 6] - ax, cyv = T[o + 7] - ay, czv = T[o + 8] - az;
      const px = x - ax, pz = z - az;
      const den = bxv * czv - bzv * cxv;
      if (Math.abs(den) < 1e-12) continue;
      const u = (px * czv - pz * cxv) / den;
      const v = (bxv * pz - bzv * px) / den;
      if (u < -1e-5 || v < -1e-5 || u + v > 1 + 1e-5) continue;
      const y = ay + u * byv + v * cyv;
      if (y <= maxY && y > best) { best = y; id = list[i]; }
    }
    return id < 0 ? null : { id, height: best };
  }

  triangleHeightAt(id, x, z) {
    if (!Number.isInteger(id) || id < 0 || id >= this.count) throw Error('Invalid ground triangle.');
    const T = this.tris, o = id * 9, ax = T[o], az = T[o + 2];
    const bx = T[o + 3] - ax, bz = T[o + 5] - az, cx = T[o + 6] - ax, cz = T[o + 8] - az;
    const den = bx * cz - bz * cx, px = x - ax, pz = z - az;
    return T[o + 1] + (px * cz - pz * cx) / den * (T[o + 4] - T[o + 1]) + (bx * pz - bz * px) / den * (T[o + 7] - T[o + 1]);
  }

  clear() { this.count = 0; this.buckets.clear(); }
}
