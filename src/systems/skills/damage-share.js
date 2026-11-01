// Divide Pain (WAR 1126) / Divide Force (WAR 1128): a party member's damage is shared with the CASTER.
//
// Native rows (Global gamedata/skills/class_5.json, read 2026-10-17; docs in lanes-20261017/LANE-A-REPORT.md):
//   Pain  1126  target mask 64, range 5,  step 1 = result 2000502 args [0, 40, 8400+L, 45000]  (family damage_share)
//   Force 1128  target mask 8,  range 20, step 1 = result 2000501 args [2560, 25, 8400+L, 30000] (2560 / 128 = 20 m)
//   both        step 2 = result 4000003, chance 100, target self: status 8260+L (Pain) / 8280+L (Force) for 15000 ms
//   status 8401..8410 carries ONE option, SHARE_DAMAGE_PARTY with value 0 (icon 232, group 104): the percent is NOT in the
//   status, it is args[1] of the cast row (40 at every Pain level, 25 at every Force level).
//   skilldesc (native text, level rows 2..10 identical in wording): "Transfer to yourself 40% of the damage suffered by the
//   selected party member for 45s. Receiving damage from this effect increases your attack power by N% and your defense by
//   M% for 15s." Observation O2 (lanes-20261016): the Force caster shows the gold 8401 aura and no blue at cast.
//
// Direction: the holder of an 8401..8410 entry is the PROTECTED unit; the status' sourceId is the caster; the caster takes
// sharePct of the damage the protected unit suffers and the protected unit keeps the remainder. The blue self status
// (step 2) is applied to the caster when it receives shared damage, not at cast.
//
// ENGINE-CHOSEN (the data is silent): (1) the share is taken from the damage the protected unit would suffer after its
// multiplicative resists, before mana shield / PvP shield, the same position the summon share always had; (2) shared damage
// is never lethal for the caster (at most hp - 1 is transferred, the rest stays with the protected unit); (3) shared damage
// is final HP damage on the caster (not re-run through the caster's defence, not absorbed by its PvP shield); (4) damage
// over time does not share; (5) no distance limit after the cast (the range belongs to the cast only).
//
// Pure rules only: the host (server/world/damage-share.mjs) and the offline hooks (hooks.js) supply the live lookups.

export const SHARE_OPTION = 'SHARE_DAMAGE_PARTY';
const FAMILY = 'damage_share';
const num = v => (Number.isFinite(+v) ? +v : 0);

const levelRow = (skill, level) => {
  const rows = skill?.levels;
  if (!Array.isArray(rows) || !rows.length) return null;
  const n = Number(level);
  return Number.isInteger(n) && n >= 1 ? rows[n - 1] || null : null;
};
/** Level rows to search: the cast level when known, else every level of the skill. */
const rowsFor = (skill, level) => {
  const row = levelRow(skill, level);
  return row ? [row] : Array.isArray(skill?.levels) ? skill.levels : [];
};
const stepsOf = row => (Array.isArray(row?.steps) ? row.steps : []);

export function isDamageShareSkill(skill) {
  return stepsOf({ steps: skill?.steps }).concat(...(skill?.levels || []).map(stepsOf)).some(s => s?.result?.family === FAMILY);
}

/** The damage_share result row of a cast (matched by status index when given). */
export function shareResult(skill, level, statusIndex = null) {
  for (const row of rowsFor(skill, level)) {
    for (const step of stepsOf(row)) {
      const r = step?.result;
      if (r?.family === FAMILY && (statusIndex == null || Number(r.statusIndex) === Number(statusIndex))) return r;
    }
  }
  return null;
}

/** Percent of the protected unit's damage the caster takes: args[1] of the cast row (sharePct). 0 when the row is unknown. */
export function sharePercent(skill, level, statusIndex = null) {
  const r = shareResult(skill, level, statusIndex);
  if (!r) return 0;
  const pct = num(r.sharePct ?? r.args?.[1]);
  return pct > 0 ? Math.min(100, pct) : 0;
}

/** Radius in metres of the share cast: args[0] / 128. 0 = the selected party member only (Pain), 20 m around the caster (Force). */
export function shareRadius(result) {
  const raw = num(result?.args?.[0]);
  return raw > 0 ? raw / 128 : 0;
}

/** The self status step (4000003) of a damage-share cast: {statusIndex, durationMs, chance}, or null. */
export function selfBuffStep(skill, level, shareStatusIndex = null) {
  for (const row of rowsFor(skill, level)) {
    const steps = stepsOf(row);
    if (!steps.some(s => s?.result?.family === FAMILY && (shareStatusIndex == null || Number(s.result.statusIndex) === Number(shareStatusIndex)))) continue;
    for (const step of steps) {
      const r = step?.result;
      if (r?.family === 'status' && r.target === 'self' && num(r.statusIndex) > 0) return { statusIndex: Number(r.statusIndex), durationMs: num(r.durationMs), chance: r.chance == null ? 100 : num(r.chance) };
    }
  }
  return null;
}

/** True when statusIndex is the blue self status of a damage-share skill (applied on receiving shared damage, not at cast). */
export function isDeferredSelfBuff(skill, level, statusIndex) {
  if (!skill || !(num(statusIndex) > 0)) return false;
  for (const row of rowsFor(skill, level)) {
    const steps = stepsOf(row);
    if (!steps.some(s => s?.result?.family === FAMILY)) continue;
    if (steps.some(s => s?.result?.family === 'status' && s.result.target === 'self' && Number(s.result.statusIndex) === Number(statusIndex))) return true;
  }
  return false;
}

/** Active entries of a status list that protect their holder (option SHARE_DAMAGE_PARTY, a known percent). */
export function shareEntries(list) {
  const out = [];
  for (const s of list || []) {
    if (!s || (s.remaining != null && s.remaining <= 0) || !(num(s.sharePct) > 0)) continue;
    if ((s.options || []).some(o => o.code === SHARE_OPTION)) out.push(s);
  }
  return out;
}

/**
 * Split `amount` between the protected unit and the casters of its share entries.
 *   entries      shareEntries(list) of the protected unit
 *   protectedId  id of the protected unit; an entry whose sourceId is the holder itself transfers nothing
 *   protectorFor entry -> {hp, ...} of an ELIGIBLE caster (alive, present, same scene, same party), or null
 * Returns { kept, part, transfers: [{ entry, protector, part, pct }] }; kept + part === amount.
 */
export function planShare({ entries, amount, protectedId, protectorFor }) {
  const total = Math.max(0, num(amount));
  const result = { kept: total, part: 0, transfers: [] };
  if (!(total > 0) || !entries?.length || typeof protectorFor !== 'function') return result;
  let moved = 0;
  for (const entry of entries) {
    if (entry.sourceId == null || entry.sourceId === protectedId) continue;
    const protector = protectorFor(entry);
    if (!protector) continue;
    const room = Math.floor(num(protector.hp) - 1);
    const part = Math.min(Math.round(total * num(entry.sharePct) / 100), room, Math.floor(total - moved));
    if (!(part > 0)) continue;
    moved += part;
    result.transfers.push({ entry, protector, part, pct: num(entry.sharePct) });
  }
  result.part = moved;
  result.kept = total - moved;
  return result;
}
