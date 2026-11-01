// Server-load values the Global client data does not contain (the original ran a different network design). ENGINE-CHOSEN.
// Measured with a server benchmark (real accounts + world API, real spawn tables, 10-100 players).
export const SERVER_LOAD_ENGINE_CHOSEN = Object.freeze({
  // The radius (cells) a viewer's snapshot lists monsters in. 100 is the value the snapshot always used (core.mjs); the
  // monster tick uses the same radius to let unseen idle monsters stand instead of wandering.
  viewCells: 100,
  // At most this many monsters per snapshot, the nearest ones. Past ~10,000 rows (~89 bytes each) a snapshot went over the
  // 1 MiB stream guard (server/world/api.mjs) and the player received nothing at all; no real spawn table comes near 1,000
  // monsters within 100 cells of one spot (the densest original field map has 1,001 rows on the whole map).
  snapshotMonsterCap: 1000,
  // World event ring (attack / damage / chat ... events a snapshot carries). It was 200 for the whole world: with thousands of
  // monsters fighting, 2,000-20,000 events a second were emitted (measured), so most fell out before the next snapshot and
  // damage numbers went missing. 16,384 holds more than one slowest snapshot interval (400 ms) at 20,000 events a second.
  eventRing: 16384,
  eventRingTrim: 4096,        // trimmed in blocks of this many so a push stays cheap
  // At most this many events in one snapshot: every event of the viewer itself is kept, then the newest others.
  eventSnapshotCap: 1000,
});
