// lane-perf: per-stream row deltas for SSE snapshots (server/world/core.mjs snapshotText(p, rowCache)).
// A stream snapshot carrying `rowsDelta` lists an UNCHANGED row of `players` / `monsters` by its id string instead of the
// whole row; the row is byte-identical to the one this same stream received last frame. Expanding restores exactly the
// object JSON.parse(full snapshot) would have produced (tools/lane-perf/test-rows-delta-equivalence.mjs).
export const DELTA_FIELDS = ['players', 'monsters'];
export class RowsDeltaDecoder {
  constructor() { this.key = null; this.rows = new Map(DELTA_FIELDS.map(f => [f, new Map()])); }
  reset() { this.key = null; this.roster = undefined; for (const m of this.rows.values()) m.clear(); }   // NETX2: roster
  /** Mutates and returns snapshot with every delta field expanded to full rows. Throws on a reference it cannot resolve. */
  expand(snapshot) {
    const key = snapshot?.rowsDelta;
    if (key === undefined) return snapshot;
    if (key !== this.key) { this.reset(); this.key = key; }
    // NETX2 (server DK_NETX_ROSTER, rd=2): party.connected "$s" = the same roster this stream received last
    const party = snapshot.party;
    if (party && typeof party === 'object') { if (party.connected === '$s') { if (this.roster === undefined) throw Error('rowsDelta: roster $s before a roster'); party.connected = structuredClone(this.roster); } else if (Array.isArray(party.connected)) this.roster = structuredClone(party.connected); }
    for (const field of DELTA_FIELDS) {
      const list = snapshot[field]; if (!Array.isArray(list)) continue;
      const prior = this.rows.get(field), next = new Map();
      for (let i = 0; i < list.length; i++) {
        let row = list[i];
        if (typeof row === 'string') { const kept = prior.get(row); if (kept === undefined) throw Error(`rowsDelta: unknown ${field} row ${row}`); row = structuredClone(kept); list[i] = row; }
        // NETX (server DK_NETX_FIELD_DELTA, stream opened with rd=2): {"$p":id, changed keys, "$d":[removed keys]} against last frame's row
        else if (row && typeof row === 'object' && Object.hasOwn(row, '$p')) { const kept = prior.get(row.$p); if (kept === undefined) throw Error(`rowsDelta: unknown ${field} patch ${row.$p}`); const merged = structuredClone(kept); for (const k of Object.keys(row)) if (k !== '$p' && k !== '$d') merged[k] = row[k]; for (const k of row.$d || []) delete merged[k]; row = merged; list[i] = row; }
        if (row && typeof row === 'object' && row.id !== undefined) next.set(row.id, structuredClone(row));
      }
      this.rows.set(field, next);
    }
    delete snapshot.rowsDelta;
    return snapshot;
  }
}
