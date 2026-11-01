// Older hosts and bots OFF may send null. A newer host separately marks whether
// this exact scene requires preparation, even before its checkpoint exists.
// Never turn malformed or incomplete preparation into a ready scene.
export function scenePreparation(raw, viewer, required = false) {
  if (typeof required !== 'boolean') throw new Error('Scene preparation is invalid. Retry loading.');
  if (raw == null) return null;
  const integer = (n, max = Number.MAX_SAFE_INTEGER) => Number.isSafeInteger(n) && n >= 0 && n <= max;
  if (!raw || typeof raw !== 'object' || Array.isArray(raw) ||
      !integer(raw.map) || raw.map !== Number(viewer?.map) ||
      !integer(raw.channel) || raw.channel !== (viewer?.channel ?? 0) ||
      !(raw.instanceId === null || typeof raw.instanceId === 'string') ||
      raw.instanceId !== (viewer?.instanceId || null) ||
      !['warming', 'ready', 'incomplete'].includes(raw.phase) ||
      !integer(raw.target, 1250) || !integer(raw.active, 1250) ||
      !integer(raw.ceiling, 1250) || !integer(raw.eligible, 1250) ||
      raw.target !== Math.min(raw.ceiling, raw.eligible) ||
      !integer(raw.revision) || !integer(raw.startedAt) || !integer(raw.updatedAt) ||
      typeof raw.complete !== 'boolean' ||
      ![null, 'scene-changed', 'capacity', 'native-admission', 'target-changed'].includes(raw.failed) ||
      (raw.failed === 'target-changed' && raw.phase !== 'incomplete') ||
      (raw.phase === 'ready' && (!raw.complete || raw.failed !== null || raw.active < raw.target)) ||
      (raw.phase !== 'ready' && raw.complete)) throw new Error('Scene preparation is invalid. Retry loading.');
  return Object.freeze({ map: raw.map, instanceId: raw.instanceId, channel: raw.channel,
    phase: raw.phase, target: raw.target, active: raw.active, ceiling: raw.ceiling, eligible: raw.eligible,
    complete: raw.complete, failed: raw.failed, revision: raw.revision,
    startedAt: raw.startedAt, updatedAt: raw.updatedAt });
}
