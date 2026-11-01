// Player hit reaction: one decision on the host, played the same on every screen.
//
// Data: a player's hit reaction is the DEFEAT action of its class action table (share/action/action/pc/*.act ->
// gamedata/classes.json anims.hit[] = DEFEAT rows 0..3; every class: rows 0/2 = <cls>_com_damage_01, rows 1/3 =
// <cls>_com_damage_02, TimeLength 0.64 s). The clip is stretched to that TimeLength, so the reaction holds the body
// for exactly anims.hit[v].timeLength on the victim's own screen and on every observer's screen.
//
// Not in the data (documented, not invented as data): which DEFEAT row the original client picks for a given hit.
// The engine keeps its earlier rule (one of the two distinct clips, rows 0|1, at random), but the HOST now picks it
// once per damage event (event.defeat) instead of each client rolling its own (the victim used to roll 0|1 while
// observers always showed row 0 for 0.25 s, cutting the 0.64 s clip).
//
// When a reaction plays (the engine's existing local rule, now applied from the host's authoritative state so the
// victim and observers agree): only a standing player flinches. Moving (host path), a basic-attack swing in
// progress (now < attackAt), a skill cast (casting), sitting or fishing => no reaction (event.defeat absent).
export const PC_DEFEAT_VARIANTS = 2;
export const DEFAULT_DEFEAT_SECONDS = 0.64;

/** Host decision for a damage event whose target is a player record. Returns the DEFEAT row or null (no reaction). */
export function playerDefeatReaction(state = {}, random = Math.random) {
  if (!state || state.dead || state.moving || state.attacking || state.casting || state.sitting || state.fishing) return null;
  // ENGINE-CHOSEN: native DEFENSE_DEFEATRATE_MUL is Defeat Resistance (%).
  // Suppress that share of otherwise eligible flinches. The private Global
  // threshold equation is absent; do not reinterpret resistance as guard.
  const resistance=Math.max(0,Math.min(100,Number(state.defeatResistance)||0));
  if(resistance>0&&Number(random())*100<resistance)return null;
  const r = Number(random());
  return Math.min(PC_DEFEAT_VARIANTS - 1, Math.max(0, Math.floor((Number.isFinite(r) ? r : 0) * PC_DEFEAT_VARIANTS)));
}

/** Valid DEFEAT row carried by a damage event (integer >= 0), else null. */
export function eventDefeat(event) {
  const v = event?.defeat;
  return Number.isInteger(v) && v >= 0 && v < 16 ? v : null;
}

/** Seconds the reaction holds the body: the DEFEAT row's TimeLength from the class action table. */
export function defeatSeconds(actor, variant) {
  const L = actor?.anims?.hit || [];
  const row = L[Number(variant) | 0] || L[0];
  const t = Number(row?.timeLength);
  return t > 0 ? t : DEFAULT_DEFEAT_SECONDS;
}
