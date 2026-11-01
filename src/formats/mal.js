// Dekaron .mal — two unrelated formats share this extension. parseMal() detects which one it got.
//
// 1) GRID .mal (legacy collision mask; map/*.mal (24), share/mapredcell/*.mal (29): 53 files)
//      u32 width, u32 height, then width*height cells (row-major, index y*width + x, same grid as .mac):
//        u8 per cell, 0 = walkable, 1 = blocked                         (52 files)
//        u16 per cell = .mac attribute values                             (map/avalon.mal only)
//    It is an OLDER export of the collision the .mac carries (braiken: 98.9% of cells agree with "mac value
//    is blocked"; crespo/crevasse/haihaff only block a band along the walkable edges; castor.mal is an
//    unrelated older layout — see mal.md). Not referenced by share/maplist.csv; use the .mac (MapAttribute).
//
// 2) GRAPH .mal (share/map/<NN_name>/mNNN.mal, referenced by maplist column MapPath, 310 files)
//      u16 mapIndex                       // = maplist Index of the owning map (m000 -> 0, m024 -> 24 ...)
//      u32 nodeCount                      // 1024 in 299 files (32 x 32 zones of 16 x 16 cells on a 512 map)
//      nodeCount x { u16 id, u32 count, u16 member[count] }      // zone -> member blocks (identity in 99% of files)
//      nodeCount x { u16 id, u32 count, u16 neighbour[count] }   // zone adjacency
//    Every 1024-node file is the complete 8-neighbour 32x32 lattice (verified 299/299; the check cannot tell
//    id = bx + by*32 from id = by + bx*32, bx + by*32 is assumed), i.e. it carries NO walkability: it is most
//    likely the server's area-of-interest / zone graph (which 16x16-cell zones see each other).
//    Irregular files: dksquare.mal (256 zones of 2x2 blocks), dungeon.mal (1 zone), m565.mal (4096 nodes),
//    7 files truncated by 2 bytes (missing last neighbour count; treated as 0) and 49_cherubim/m049.mal
//    (262144 per-cell nodes, cut off at node 227304) -> result.truncated = true.
//
// Pure functions, no three.js / Node APIs.

import { BinReader, toArrayBuffer } from './binreader.js';
import { readCellGrid, attachGridMethods, DEFAULT_CELL_TABLE } from './mac.js';

/** True when the buffer is a (width, height, cells) grid: size == 8 + w*h*{1,2}. */
export function isGridMal(buf) {
  const ab = toArrayBuffer(buf);
  if (ab.byteLength < 8) return false;
  const dv = new DataView(ab);
  const w = dv.getUint32(0, true), h = dv.getUint32(4, true);
  const n = w * h;
  return w <= 8192 && h <= 8192 && (ab.byteLength === 8 + n || ab.byteLength === 8 + 2 * n);
}

/**
 * Parse either kind of .mal.
 * @param {ArrayBuffer|Uint8Array} buf
 * @returns {GridMal|GraphMal}
 *
 * @typedef {{kind:'grid', width:number, height:number, bytesPerCell:1|2, attrs:Uint16Array, cells:Uint8Array,
 *   blockedCount:number, trailingBytes:number, isBlocked(x,y):boolean, isWalkable(x,y):boolean, attrAt(x,y):number,
 *   inBounds(x,y):boolean}} GridMal
 *   cells: 1 = blocked. For 1-byte files attrs == cells (0/1); for the 2-byte file attrs are .mac values and
 *   cells is derived through the cell table exactly like parseMac().
 *
 * @typedef {{kind:'graph', mapIndex:number, nodeCount:number, side:number|null, blockCells:number|null,
 *   groups:Array<{id:number, members:Uint16Array}>, links:Array<{id:number, neighbours:Uint16Array}>,
 *   identityGroups:boolean, fullLattice:boolean|null, truncated:boolean, bytesConsumed:number, trailingBytes:number}} GraphMal
 *   side = sqrt(nodeCount) when it is a perfect square (32 -> zones of 512/32 = 16 cells: blockCells).
 */
export function parseMal(buf, opts = {}) {
  const ab = toArrayBuffer(buf);
  if (isGridMal(ab)) return parseGridMal(ab, opts);
  return parseGraphMal(ab, opts);
}

export function parseGridMal(buf, opts = {}) {
  const g = readCellGrid(buf);
  const n = g.width * g.height;
  const cells = new Uint8Array(n);
  let blockedCount = 0;
  if (g.bytesPerCell === 2) {
    const table = opts.cellTable || DEFAULT_CELL_TABLE;
    for (let i = 0; i < n; i++) { const t = table.get(g.attrs[i]); const b = t && t.blocked ? 1 : 0; cells[i] = b; blockedCount += b; }
  } else {
    for (let i = 0; i < n; i++) { const b = g.attrs[i] ? 1 : 0; cells[i] = b; blockedCount += b; }
  }
  const out = {
    kind: 'grid', width: g.width, height: g.height, bytesPerCell: g.bytesPerCell, attrs: g.attrs, cells,
    blockedCount, trailingBytes: g.trailingBytes,
  };
  return attachGridMethods(out, opts.cellTable || DEFAULT_CELL_TABLE);
}

export function parseGraphMal(buf, opts = {}) {
  const r = new BinReader(buf);
  if (r.length < 6) throw new Error(`mal: file too small (${r.length} bytes)`);
  const mapIndex = r.u16();
  const nodeCount = r.u32();
  if (nodeCount > 1 << 20) throw new Error(`mal: implausible node count ${nodeCount}`);
  let truncated = false;
  const readSection = () => {
    const list = [];
    for (let i = 0; i < nodeCount; i++) {
      if (r.remaining < 2) { truncated = true; break; }
      const id = r.u16();
      if (r.remaining < 4) {           // 7 files end 2 bytes short: the final count is missing
        truncated = true; r.skip(r.remaining);
        list.push({ id, members: new Uint16Array(0) });
        break;
      }
      const count = r.u32();
      if (count > 65535 || count * 2 > r.remaining) { truncated = true; r.skip(r.remaining); break; }
      list.push({ id, members: r.u16array(count) });
    }
    return list;
  };
  const groups = readSection();
  const linksRaw = truncated ? [] : readSection();
  const links = linksRaw.map(e => ({ id: e.id, neighbours: e.members }));
  const sideF = Math.sqrt(nodeCount);
  const side = Number.isInteger(sideF) ? sideF : null;
  const identityGroups = groups.length === nodeCount && groups.every((g, i) => g.id === i && g.members.length === 1 && g.members[0] === i);
  let fullLattice = null;
  if (side && identityGroups && links.length === nodeCount) {
    fullLattice = true;
    for (const l of links) {
      const x = l.id % side, y = (l.id / side) | 0;
      let expect = 0;
      for (let dy = -1; dy <= 1; dy++) for (let dx = -1; dx <= 1; dx++) {
        if ((dx || dy) && x + dx >= 0 && y + dy >= 0 && x + dx < side && y + dy < side) expect++;
      }
      if (l.neighbours.length !== expect) { fullLattice = false; break; }
      for (const nb of l.neighbours) {
        const nx = nb % side, ny = (nb / side) | 0;
        if (Math.max(Math.abs(nx - x), Math.abs(ny - y)) !== 1) { fullLattice = false; break; }
      }
      if (!fullLattice) break;
    }
  }
  const gridCells = opts.gridCells || 512;
  return {
    kind: 'graph', mapIndex, nodeCount, side, blockCells: side ? gridCells / side : null,
    groups, links, identityGroups, fullLattice, truncated,
    bytesConsumed: r.pos, trailingBytes: r.length - r.pos,
  };
}

/** Zone (graph node) that contains cell (x, y) for a square lattice graph; -1 if not applicable. */
export function malZoneOfCell(graph, x, y) {
  if (!graph.side || !graph.blockCells) return -1;
  const bx = Math.floor(x / graph.blockCells), by = Math.floor(y / graph.blockCells);
  if (bx < 0 || by < 0 || bx >= graph.side || by >= graph.side) return -1;
  return by * graph.side + bx;
}
