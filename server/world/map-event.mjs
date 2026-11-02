// Server side of Global dungeon map-event cinematics (Lane 49).
// Global client starts on opcode 0x05260021 (u32 index at packet +0x10). Older server-ref
// DekaronServer_A11.exe does NOT contain 0x05260021 (dungeon opcodes observed through ~0x05260012;
// OnEventScript@Dungeon sends 0x0526000c = dungeon text, not the cinematic). Without a Global
// server binary, Lane 64 binds indices 1-5 to map 706 from Global data (map-event-rules.js MAP_EVENT_BINDING).
// This module only emits the 4.2.0 high-level event the client runner already understands.

export const MAP_EVENT_SCHEMAS = Object.freeze({
  mapEvent: ['token', 'type', 'operation', 'index'],
});

export const MAP_EVENT_DECISIONS = Object.freeze([
  'Binary 0x05260021 is not emulated: the older server reference (A11) has no 0x05260021 and 4.2.0 clients use the action bus (removed as a binary path; bus record dungeon:map-event kept).',
  'Indices 1-5 belong to map 706 Hidden Mansion of Kastotica (source: Global data). No source gives the in-dungeon trigger moment, so there is no automatic host trigger (removed); GM start stays.',
  'Client start request: Global has no client->server start opcode (0x05260021 is server->client only); the player "start" operation was removed by lane 64.',
  'Skip (0x05260022 / map-event-skip): the host answers with the 0x05260023 end for the skipping player (source: Global client, the only server-side terminator).',
]);
/** Kept for old imports: nothing is left open. */
export const MAP_EVENT_UNRESOLVED = Object.freeze([]);

function fail(text, status = 400) { throw Object.assign(Error(text), { status }); }

/** Emit dungeon:map-event to everyone on the instance map (or a plain map channel). */
export function startMapEvent(world, target, index) {
  const idx = Number(index);
  if (!Number.isFinite(idx) || idx <= 0) fail('map-event index must be a positive script index (loader skips 0).');
  const map = Number(target?.map ?? target);
  if (!Number.isFinite(map)) fail('map-event needs an instance or map.');
  const record = { type: 'dungeon:map-event', index: idx };
  if (target?.id != null) record.instanceId = target.id;
  if (target?.stageEvents) {
    target.stageEvents.push([map, record]);
    return { index: idx, staged: true };
  }
  world.emit?.(map, record);
  return { index: idx, staged: false };
}

/** 4.2.0 bus form of Global 0x05260023 (header only): the client ends the event on its next tick, only while actions are still pending. */
export function endMapEvent(world, target) {
  const map = Number(target?.map ?? target);
  if (!Number.isFinite(map)) return false;
  const record = { type: 'dungeon:map-event-end' };
  if (target?.id != null) record.instanceId = target.id;
  if (target?.stageEvents) { target.stageEvents.push([map, record]); return true; }
  world.emit?.(map, record);
  return true;
}

/** Client skip (Global 0x05260022 header-only). The reply carries the 0x05260023 end for this player (Global client: only server-side terminator). */
export async function dispatchMapEvent(world, player, input) {
  const op = String(input.operation || '');
  if (op === 'skip') {
    return { ok: true, operation: 'skip', end: true, endOpcode: 0x05260023 };
  }
  fail(`Unknown mapEvent operation ${op}`);
}
