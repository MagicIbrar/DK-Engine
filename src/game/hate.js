// Monster hostility (hate) table, shared by the offline skill engine / brain and the authoritative server.
//
// Data (skills.json / skills/common.json `aggro`, built by tools/build-skills.mjs from share/ai):
//   settings   share/ai/aggrosetting.csv  dwMAXAggro 2500000 (cap), dwFirstAggroValue 7500 (first-hit bonus),
//              dwAggroKeepingTick 30000 (an entry is forgotten after 30 s without new hostility),
//              byAggroChangePercent 20 (the monster switches only to a unit with 20 % more hostility than its current one).
//              byOwnershipWeight 120 and byMonsterAggroList / byPCAggroList 36 are NOT applied: meaning unconfirmed.
//   codes      share/ai/aggroaccount.csv  AggroCode -> units [[unit, value], ...]. Unit meanings are INFERRED from the row
//              structure (only units 1 / 3 / 4 occur; 4 is always 100 and always follows 3): 3 = x value, 4 = / value, 1 = flat.
//   classDamage share/ai/damageaggrocode.csv  class index 0-13 (and servant index 4001+) -> the code of a plain hit.
// Storage: record.hate = Map(who -> {v, t}); `who` is whatever key the caller uses (an actor offline, a player id online).
// Time is milliseconds on both sides.
const num = v => (Number.isFinite(+v) ? +v : 0);

export function hateSettings(aggro) {
  const S = aggro?.settings || {};
  return {
    cap: num(S.dwMAXAggro) || 2500000,
    first: num(S.dwFirstAggroValue) || 7500,
    keepMs: num(S.dwAggroKeepingTick) || 30000,
    switchPct: num(S.byAggroChangePercent) || 20,
  };
}

/** Hostility of a landed result: aggroaccount.csv units applied to `amount`; no / unknown code -> the amount itself. */
export function hateValue(amount, code, aggro) {
  const def = code != null ? aggro?.codes?.[code] : null;
  const amt = Math.max(0, num(amount));
  if (!def) return amt;
  let mul = 0, div = 0, flat = 0;
  for (const [u, val] of def.units || []) {
    if (u === 3) mul = num(val);
    else if (u === 4) div = num(val);
    else if (u === 1) flat += num(val);
  }
  return flat + (mul ? amt * mul / (div || 1) : 0);
}

/** Hostility of a plain hit by a class (0-13) or servant (4001+): damageaggrocode.csv -> aggroaccount.csv. Missing row -> x1 (ENGINE-CHOSEN). */
export function plainHitHate(amount, sourceIndex, aggro) {
  const code = sourceIndex != null ? aggro?.classDamage?.[sourceIndex] : undefined;
  return code != null && aggro?.codes?.[code] ? hateValue(amount, code, aggro) : Math.max(0, num(amount));
}

/** Add hostility of `who` on `record` (first entry gets dwFirstAggroValue; the total is capped at dwMAXAggro). */
export function addHate(record, who, value, aggro, nowMs = 0) {
  if (!record || who == null) return null;
  const S = hateSettings(aggro);
  const hate = record.hate instanceof Map ? record.hate : (record.hate = new Map());
  const cur = hate.get(who);
  const entry = { v: Math.min(S.cap, (cur?.v || 0) + (cur ? 0 : S.first) + Math.max(0, num(value))), t: nowMs };
  hate.set(who, entry);
  return entry;
}

/**
 * The unit the monster should fight: the highest valid hostility, kept on `current` unless another unit has at least
 * byAggroChangePercent more. Expired (dwAggroKeepingTick) and invalid entries are dropped. Returns null when nothing is left.
 */
export function pickTarget(record, current, aggro, nowMs = 0, isValid = () => true) {
  const hate = record?.hate;
  if (!(hate instanceof Map) || !hate.size) return null;
  const S = hateSettings(aggro);
  let best = null, bv = -1;
  for (const [who, h] of hate) {
    if (nowMs - h.t > S.keepMs || !isValid(who)) { hate.delete(who); continue; }
    if (h.v > bv) { bv = h.v; best = who; }
  }
  if (best === null) return null;
  if (current != null && current !== best && hate.has(current)) {
    const cv = hate.get(current).v;
    if (bv < cv * (1 + S.switchPct / 100)) return current;
  }
  return best;
}

export function clearHate(record) { if (record?.hate instanceof Map) record.hate.clear(); }
export function hasHate(record) { return record?.hate instanceof Map && record.hate.size > 0; }
