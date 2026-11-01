// Following auras: skills whose party/enemy area statuses last only a few seconds while a self status carries the real
// duration (Dual Chakra 3194 / 3434: area 3,000 ms, self status 63,000 ms). The totem Chakras use the same convention
// (aura durationMs 3000 re-applied every tickMs 1000), so the area result is re-applied every second for the self status.
const num = v => (Number.isFinite(Number(v)) ? Number(v) : 0);
export const FOLLOW_AREA_MAX_MS = 6000;
export const FOLLOW_CARRIER_MIN_MS = 20000;

/** {status, durationMs} of the carrier self status when `skill` at `level` is a following aura, else null. */
export function followAura(skill, level) {
  if (!skill || skill.type !== 'area_status' || !Array.isArray(skill.levels)) return null;
  const row = skill.levels.find(l => num(l.level) === num(level)) || skill.levels[num(level) - 1];
  const steps = (row?.steps || []).map(s => s?.result).filter(Boolean);
  if (!steps.length || steps.some(r => r.family === 'totem')) return null;
  const areas = steps.filter(r => r.family === 'area_status_party' || r.family === 'area_status_enemy');
  if (!areas.length || !areas.every(r => num(r.durationMs) > 0 && num(r.durationMs) <= FOLLOW_AREA_MAX_MS)) return null;
  const carrier = steps.filter(r => r.family === 'status' && r.target === 'self' && num(r.durationMs) >= FOLLOW_CARRIER_MIN_MS && num(r.statusIndex) > 0)
    .sort((a, b) => num(b.durationMs) - num(a.durationMs))[0];
  return carrier ? { status: num(carrier.statusIndex), durationMs: num(carrier.durationMs) } : null;
}
