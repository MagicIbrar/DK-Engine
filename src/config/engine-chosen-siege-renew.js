// SiegeRenew guard deployment: native mask/import, actor/combat, client window,
// persistence and refusal acceptance completed 2026-10-13. Remaining engine
// choices are named below; paid defender skills have an independent native gate.
export const SIEGE_RENEW_PROPOSED = Object.freeze({
  /** Guard deployment readiness only; does not control paid defender skills. */
  ENABLED: true,
  /** Native minimap red alpha authorizes all cells of the native 3x3 footprint;
   * ENGINE-CHOSEN solid MAC and overlap checks add wall/stack safety. */
  guardBoundary: 'native-alpha-mask',
  /** 2. Paying wallet for guards and defender skills: the acting guild master's own character DIL (never Guild DIL). */
  wallet: 'master-character-dil',
  /** Literal approved scope; Guardian reaches living online guild members across
   * scenes. Power/Domination reach same-castle attackers, including allied guilds. */
  recipients: 'online-owner-guild-or-same-castle-attackers',
  /** 4. Defender-skill cooldown: owned by the castle per skill, durable, starting at activation; it survives capture,
   *  master change, reconnect and restart, and is cleared only by the battle-end record. */
  cooldown: 'castle-per-skill-durable',
});

/** One line per recovered rule / explicit engine choice for the report. */
export const SIEGE_RENEW_PROPOSED_DEFAULTS = Object.freeze([
  Object.freeze({ item: 'Guard placement boundaries', default: 'native alpha mask covers the complete 3x3 footprint; solid MAC and overlap checks', rationale: 'recovered source mask replaces the unsupported radius/Stone-distance rule' }),
  Object.freeze({ item: 'Paying wallet', default: 'the acting guild master\'s own character DIL', rationale: 'the lord who chooses the spend pays it, as the native "Available funds" window and the classic fee choice already do; Guild DIL is never touched' }),
  Object.freeze({ item: 'Exact skill recipients', default: 'Guardian -> living online owner guild; Power / Domination -> all living same-castle attackers', rationale: 'literal native descriptions; cross-scene guild scope explicitly approved by owner 2026-10-13' }),
  Object.freeze({ item: 'Cooldown ownership / reset', default: 'per castle and skill, durable from activation, kept through capture / master change / reconnect / restart, cleared at the battle end', rationale: 'the most restrictive custody: no reset path can be used to recast early' }),
]);

/** Production readiness switch. A world override exists only for disposable
 *  fixtures that also exercise the emergency-disabled refusal path. */
export function siegeRenewProposedEnabled(world) {
  if (typeof world?.siegeRenewProposedDefaults === 'boolean') return world.siegeRenewProposedDefaults;
  return SIEGE_RENEW_PROPOSED.ENABLED === true;
}
