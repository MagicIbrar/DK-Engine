const clamp = value => Math.max(0, Math.min(1, Number(value) || 0));

// Use the host clock, including while temporarily disconnected. Rendering never
// starts a timer: only a canonical deadline or an offline accepted action does.
export function serverNow(game) {
  const clock = game.network?._serverClock;
  return clock ? clock.time + performance.now() - clock.at : Date.now();
}

export function recoveryGroup(def) {
  const use = def?.use || {};
  if (use.hp || use.hpPct) return use.mp || use.mpPct ? 'hpmp' : 'hp';
  if (use.mp || use.mpPct) return 'mp';
  if (use.shield || use.shieldPct) return 'shield';
  if (use.stamina) return 'stamina';
  return Number.isSafeInteger(use.itemStatus) && use.itemStatus >= 0 ? `buff:${use.itemStatus}` : null;
}

export function sharedItemCooldown(game, itemIndex) {
  const def = game.items?.db?.def?.(itemIndex), group = recoveryGroup(def);
  const timers = game.network?.self?.itemCooldowns ?? game.save?.itemCooldowns;
  const timer = group && timers?.[group];
  const end = Number(timer?.endsAt), duration = Number(timer?.durationMs);
  const remaining = Number.isFinite(end) ? Math.max(0, end - serverNow(game)) / 1000 : 0;
  return { remaining, fraction: duration > 0 ? clamp(remaining * 1000 / duration) : 0 };
}

export function itemCooldownFraction(game, itemIndex) {
  if (game.network?.active) return sharedItemCooldown(game, itemIndex).fraction;
  return clamp(game.items?.uses?.cooldownFraction?.(itemIndex));
}

const anchors = new WeakMap();
export function statusRemaining(game, status) {
  if (!status) return 0;
  if (!game.network?.active) return Number(status.remaining);
  const end = Number(status.expiresAt);
  if (end) return Math.max(0, end - serverNow(game)) / 1000;
  // Skill statuses are authoritative remaining-time entries; `at` is the apply
  // timestamp, not an expiry deadline (the host can pause ticking during rejoin).
  // Each replacement snapshot gets a new anchor. Interpolate without mutation.
  const remaining = Number(status.remaining);
  if (!Number.isFinite(remaining)) return remaining;
  let anchor = anchors.get(status);
  if (anchor === undefined) { anchor = performance.now(); anchors.set(status, anchor); }
  return Math.max(0, remaining - (performance.now() - anchor) / 1000);
}

export function statusFraction(game, status) {
  const duration = Number(status?.duration);
  return duration > 0 ? clamp(statusRemaining(game, status) / duration) : 0;
}

export function cooldownBackground(fraction) {
  const f = clamp(fraction);
  return f > 0 ? `conic-gradient(rgba(96,96,96,.68) ${f * 360}deg, transparent 0)` : '';
}
