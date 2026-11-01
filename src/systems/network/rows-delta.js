// lane-perf: per-stream row deltas for SSE snapshots (server/world/core.mjs snapshotText(p, rowCache)).
// A stream snapshot carrying `rowsDelta` lists an UNCHANGED row of `players` / `monsters` by its id string instead of the
// whole row; the row is byte-identical to the one this same stream received last frame. Expanding restores exactly the
// object JSON.parse(full snapshot) would have produced (tools/lane-perf/test-rows-delta-equivalence.mjs).
export const DELTA_FIELDS = ['players', 'monsters'];
export class RowsDeltaDecoder {
  constructor() { this.key = null; this.rows = new Map(DELTA_FIELDS.map(f => [f, new Map()])); }
  reset() { this.key = null; for (const m of this.rows.values()) m.clear(); }
  /** Mutates and returns snapshot with every delta field expanded to full rows. Throws on a reference it cannot resolve. */
  expand(snapshot) {
    const key = snapshot?.rowsDelta;
    if (key === undefined) return snapshot;
    if (key !== this.key) { this.reset(); this.key = key; }
    for (const field of DELTA_FIELDS) {
      const list = snapshot[field]; if (!Array.isArray(list)) continue;
      const prior = this.rows.get(field), next = new Map();
      for (let i = 0; i < list.length; i++) {
        let row = list[i];
        if (typeof row === 'string') { const kept = prior.get(row); if (kept === undefined) throw Error(`rowsDelta: unknown ${field} row ${row}`); row = structuredClone(kept); list[i] = row; }
        if (row && typeof row === 'object' && row.id !== undefined) next.set(row.id, structuredClone(row));
      }
      this.rows.set(field, next);
    }
    delete snapshot.rowsDelta;
    return snapshot;
  }
}
