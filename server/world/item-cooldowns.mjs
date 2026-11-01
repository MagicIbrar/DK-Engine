const GROUPS = new Set(['hp', 'mp', 'hpmp', 'shield', 'stamina']);
const validGroup = group => GROUPS.has(group) || /^buff:\d{1,9}$/.test(group);

/** Only server-issued, finite recovery timers are retained or disclosed. */
export function itemCooldownState(value, now) {
  const result = {};
  if (!value || typeof value !== 'object' || Array.isArray(value)) return result;
  for (const group of Object.keys(value)) {
    if (!validGroup(group)) continue;
    const timer = Object.hasOwn(value, group) && value[group];
    if (!timer || typeof timer !== 'object' || Array.isArray(timer)) continue;
    const {endsAt, durationMs} = timer;
    if (typeof endsAt !== 'number' || !Number.isFinite(endsAt) || typeof durationMs !== 'number' || !Number.isFinite(durationMs) || durationMs <= 0 || endsAt <= now || endsAt - now > durationMs) continue;
    result[group] = {endsAt, durationMs};
  }
  return result;
}

export function itemCooldownEntries(value, now) {
  return Object.entries(itemCooldownState(value, now)).map(([group, timer]) => [group, timer.endsAt / 1000]);
}

export function acceptedItemCooldowns(previous, cooldowns, durationMs, now) {
  const result = itemCooldownState(previous, now);
  for (const [group, end] of cooldowns) {
    const endsAt = Math.round(end * 1000);
    if (!validGroup(group) || !Number.isFinite(endsAt) || endsAt <= now) continue;
    if (result[group]?.endsAt === endsAt) continue;
    if (Number.isFinite(durationMs) && durationMs > 0) result[group] = {endsAt, durationMs};
  }
  return itemCooldownState(result, now);
}
