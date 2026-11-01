// Read only the host-issued recovery ledger from a fresh authenticated self
// snapshot. The local save is never a source of accepted attack authority.
export function captureAttackRecovery(network, snapshot, now = performance.now()) {
  const self = snapshot?.self, profile = self?.profile, phase = profile?.combatRecovery?.attackStep;
  if (!network.token || network.disposed || !Number.isFinite(now) ||
      !Number.isSafeInteger(snapshot?.sequence) || snapshot.sequence < (network.sequence || 0) ||
      !Number.isFinite(snapshot.serverTime) || profile?.id !== network.game?.save?.id ||
      self?.characterId !== profile?.id || typeof self?.id !== 'string' || !self.id ||
      !Number.isSafeInteger(self.map) || !Number.isSafeInteger(self.channel ?? 0) ||
      profile?.combatRecovery?.version !== 1 || !phase || typeof phase.key !== 'string' || phase.key.length > 256 ||
      !Number.isInteger(phase.step) || phase.step < 0 || phase.step > 63 ||
      ![phase.slot, phase.wallAt, phase.speed, phase.timing?.next, phase.timing?.hitAt, phase.timing?.len].every(Number.isFinite) ||
      phase.speed <= 0 || phase.timing.len <= 0 || phase.timing.hitAt < 0 || phase.timing.next < phase.timing.hitAt ||
      phase.wallAt > snapshot.serverTime) return false;
  const old = network._attackAuthority;
  const sameLease = old?.token === network.token && old.generation === network._leaseGeneration &&
    old.actorId === self.id && old.characterId === profile.id;
  if (sameLease && (phase.wallAt < old.wallAt || phase.wallAt === old.wallAt &&
      (phase.key !== old.key || phase.step !== old.step))) return false;
  const sameScene = sameLease && old.map === self.map && old.instanceId === (self.instanceId || null) && old.channel === (self.channel ?? 0);
  // Duplicate snapshots cannot shorten or restart the recovery already paid.
  if (sameScene && phase.wallAt === old.wallAt) return true;
  const recovery = Math.max(0, phase.timing.next - phase.timing.hitAt) * 1000;
  // Pay the full authored recovery, including any host jitter debt. Receipt
  // latency makes this conservative; it cannot grant an early server hit.
  const readyAt = now + Math.max(0, Math.max(phase.slot, phase.wallAt) + recovery - snapshot.serverTime);
  if (!Number.isFinite(readyAt)) return false;
  network._attackAuthority = {
    token: network.token, generation: network._leaseGeneration, actorId: self.id, characterId: profile.id,
    map: self.map, instanceId: self.instanceId || null, channel: self.channel ?? 0,
    key: phase.key, step: phase.step, wallAt: phase.wallAt, readyAt,
  };
  return true;
}

// undefined: no current authoritative record; null: its recovery is still due.
export function authoritativeAttackStep(network, characterId, classDef, count, now = performance.now()) {
  const phase = network?._attackAuthority, self = network?.self;
  if (!phase || phase.token !== network.token || phase.generation !== network._leaseGeneration ||
      phase.characterId !== characterId || phase.actorId !== self?.id || phase.map !== self?.map ||
      phase.instanceId !== (self?.instanceId || null) || phase.channel !== (self?.channel ?? 0) ||
      !Number.isInteger(count) || count < 1) return undefined;
  if (now < phase.readyAt) return null;
  const scene = self.instanceId ? `${self.map}@${self.instanceId}` : self.channel ? `${self.map}#${self.channel}` : Number(self.map);
  const key = `${scene}|${classDef?.index}|${classDef?.style}|${count}`;
  return phase.key === key ? (phase.step + 1) % count : 0;
}
