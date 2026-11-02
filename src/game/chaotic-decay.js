// Native chaotic (Niete / karma) decay of a map: share/maplist.csv wChaoticDecrease points per dwChaoticDecreasePeriod ms.
// Active maps carry 3/60000 (132 maps), 1/60000 (52), 2/60000 (601-603) or 0/60000 (11 dungeons: 105-107, 176, 177, 180, 181,
// 249, 253, 256, 614). The engine applies the same amount per period as a continuous rate (ENGINE-CHOSEN smoothing of the native
// periodic step); callers pass fallback 0, so a row without the two native columns decays nothing (no engine-chosen rate).
const field = value => value !== undefined && value !== null && String(value).trim() !== '' ? Number(value) : NaN;
export function chaoticDecayPerSec(row, fallback) {
  const amount = field(row?.wChaoticDecrease), period = field(row?.dwChaoticDecreasePeriod);
  if (Number.isFinite(amount) && amount >= 0 && Number.isFinite(period) && period > 0) return amount * 1000 / period;
  return fallback;
}
