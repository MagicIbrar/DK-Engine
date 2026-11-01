// Collision grid for one map: the .mac attribute grid (share/mapredcell/<MapAttribute>, docs/formats/mac.md,
// coords.md). FILE frame: cell (cx, cy) covers X in [cx, cx+1), Z in [cy, cy+1); out of grid = blocked.
// Pure module (no three.js), usable from Node.
import { parseMac, nearestWalkable as macNearestWalkable } from '../formats/mac.js';

export class Collision {
  /**
   * @param {object|null} grid  parseMac() result (or null/empty = no collision data)
   * @param {number} width      map width in cells (terrain size; used when the grid is missing)
   * @param {number} height
   */
  constructor(grid, width = 512, height = 512) {
    this.grid = grid && !grid.empty && grid.width > 0 ? grid : null;
    this.width = this.grid ? this.grid.width : width;
    this.height = this.grid ? this.grid.height : height;
    // movement mask: 1 = blocked. Without data everything inside the map is walkable.
    this.cells = this.grid ? this.grid.cells : new Uint8Array(this.width * this.height);
    this.hasData = !!this.grid;
    this.walkableCount = 0;
    for (let i = 0; i < this.cells.length; i++) if (!this.cells[i]) this.walkableCount++;
  }

  /** Parse a .mac buffer (ArrayBuffer/Uint8Array or null). */
  static fromBuffer(buf, width = 512, height = 512) {
    let grid = null;
    if (buf) {
      try { grid = parseMac(buf); } catch (err) { console.warn('[world] .mac parse failed', err); }
    }
    return new Collision(grid, width, height);
  }

  inBounds(x, z) { return x >= 0 && z >= 0 && x < this.width && z < this.height; }

  /** Cell index or -1. Accepts continuous FILE coordinates (floored). */
  index(x, z) {
    const cx = Math.floor(x), cz = Math.floor(z);
    return cx >= 0 && cz >= 0 && cx < this.width && cz < this.height ? cz * this.width + cx : -1;
  }

  /** Inside the map and not blocked. */
  isWalkable(x, z) {
    const i = this.index(x, z);
    return i >= 0 && this.cells[i] === 0;
  }

  /** Cell-index variant (no flooring, no allocation). */
  walkableCell(cx, cz) {
    return cx >= 0 && cz >= 0 && cx < this.width && cz < this.height && this.cells[cz * this.width + cx] === 0;
  }

  /** Raw .mac attribute (share/arrange/cell.csv index), -1 outside, 0 without data. */
  attrAt(x, z) {
    const i = this.index(x, z);
    if (i < 0) return -1;
    return this.grid ? this.grid.attrs[i] : 0;
  }

  /** Attribute row of share/arrange/cell.csv (safety zone, fishing, ...), or null. */
  info(x, z) { return this.grid ? this.grid.info(x, z) : null; }

  /**
   * Nearest walkable cell centre to (x, z) (Chebyshev rings), or null.
   * @returns {{x:number, z:number, distance:number}|null}  FILE frame, cell centre
   */
  nearestWalkable(x, z, maxRadius = 32) {
    if (this.isWalkable(x, z)) return { x, z, distance: 0 };
    if (!this.walkableCount) return null;
    const g = { width: this.width, height: this.height, cells: this.cells };
    const r = macNearestWalkable(g, Math.max(0, Math.min(this.width - 1, x)), Math.max(0, Math.min(this.height - 1, z)), maxRadius);
    return r ? { x: r.x + 0.5, z: r.y + 0.5, distance: r.distance } : null;
  }

  /**
   * Grid line of sight for movement: true when every cell the segment touches is walkable (supercover traversal:
   * when the segment passes exactly through a cell corner both side cells must be walkable, so paths never slip
   * between two diagonal blockers).
   */
  lineOfSight(x0, z0, x1, z1) {
    let cx = Math.floor(x0), cz = Math.floor(z0);
    const ex = Math.floor(x1), ez = Math.floor(z1);
    if (!this.walkableCell(cx, cz)) return false;
    const dx = x1 - x0, dz = z1 - z0;
    const sx = dx > 0 ? 1 : dx < 0 ? -1 : 0, sz = dz > 0 ? 1 : dz < 0 ? -1 : 0;
    const tdx = sx ? Math.abs(1 / dx) : Infinity, tdz = sz ? Math.abs(1 / dz) : Infinity;
    let tmx = sx > 0 ? (cx + 1 - x0) * tdx : sx < 0 ? (x0 - cx) * tdx : Infinity;
    let tmz = sz > 0 ? (cz + 1 - z0) * tdz : sz < 0 ? (z0 - cz) * tdz : Infinity;
    let guard = Math.abs(ex - cx) + Math.abs(ez - cz) + 4;
    while ((cx !== ex || cz !== ez) && guard-- > 0) {
      if (Math.abs(tmx - tmz) < 1e-9) {
        // exactly through a corner: both neighbours must be free
        if (!this.walkableCell(cx + sx, cz) || !this.walkableCell(cx, cz + sz)) return false;
        cx += sx; cz += sz; tmx += tdx; tmz += tdz;
      } else if (tmx < tmz) { cx += sx; tmx += tdx; }
      else { cz += sz; tmz += tdz; }
      if (!this.walkableCell(cx, cz)) return false;
    }
    return true;
  }
}
