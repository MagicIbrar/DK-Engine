// Realm side of LINK + BEACON (Phase B step 3): publishes who is online, and where, to the Beacon worker.
// Only under ServerOn (pipelineClient() is null otherwise) and only when DK_BEACON is not '0'.
// Cost on Realm: one pass over world.players every DK_BEACON_MS (default 1000 ms), and a publish only when the table changed
// (plus a 10 s heartbeat). Full tables on the coalesced STATE lane: if Beacon is slow, only the newest table is kept.
import { pipelineClient } from './client.mjs';
export function startPresenceFeed(world, { client = pipelineClient(), everyMs = Number(process.env.DK_BEACON_MS) || 1000, heartbeatMs = 10000 } = {}) {
  if (!client || process.env.DK_BEACON === '0' || !world?.players) return null;
  let last = '', lastAt = 0, revision = 0;
  const table = () => {
    const rows = [];
    for (const p of world.players.values()) {
      if (!p || p.leaving) continue;
      rows.push([String(p.id), String(p.account ?? ''), String(p.characterId ?? ''), String(p.profile?.name ?? ''), Number(p.map) || 0, Number(p.channel ?? 0) || 0, p.instanceId ? 1 : 0]);
    }
    return rows;
  };
  const tick = () => {
    try {
      const rows = table(), sig = rows.map(r => r.join('\u0001')).join('\u0002'), now = Date.now();
      if (sig === last && now - lastAt < heartbeatMs) return;
      last = sig; lastAt = now;
      client.endpoint.publish('beacon.presence', { at: now, revision: ++revision, rows }, client.PRIO.STATE, 'beacon.presence');
    } catch { /* presence is advisory; never disturb the world tick */ }
  };
  const timer = setInterval(tick, everyMs); timer.unref?.();
  tick();
  return { stop() { clearInterval(timer); }, tick };
}
