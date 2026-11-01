// SiegeRenew castle services beside the Guardian Stone battle: schedule zone, guard (sentry) deployment, observers, brokerage
// tax and the defender-skill evidence. Pure rules; the host is server/world/siege-renew-controller.mjs.
// Labels: AUTHENTICATED NATIVE RULE = original data or the official guide; ENGINE CHOICE = this engine's stated reading.
// A rule whose predicate is absent from every source stays CLOSED and names its exact dependency below.

// ------------------------------------------------------------------ schedule
// AUTHENTICATED NATIVE RULE: script/string/siege/stringtable_siege.txt 100:10 / 100:11 (the castle entrance text) reads
// "<Siege Battle> * Every Sunday * 7:00 PM to 8:00PM Central European Time (UTC+1)". It names the zone of the raw
// share/siege_renew/config.csv START_WEEK 0 / START_HOUR 19 / PLAY_KEEP_TIME 3600 (one hour), so the weekly start is
// Sunday 19:00 at UTC+1 (18:00 UTC). The text states a fixed UTC+1 offset; no daylight-saving rule is applied.
// CONFLICT (in-game value kept): the official guide 32 shows "Every Sunday 9 to 10PM", channel "Server 2". The guide names
// no zone; the in-game hour/zone and the native castle channel 100 are kept.
const PM = /(\d{1,2}):(\d{2})\s*PM\s*to\s*(\d{1,2}):(\d{2})\s*PM[^(]*\(UTC\s*([+-])\s*(\d{1,2})(?::?(\d{2}))?\)/i;
/** {offsetMin, startHour, endHour} read from the native entrance text, or null when the text does not state the raw hour. */
export function renewScheduleZone(text, cfg) {
  const m = PM.exec(String(text || ''));
  if (!m) return null;
  const start = (Number(m[1]) % 12) + 12, end = (Number(m[3]) % 12) + 12, offsetMin = (m[5] === '-' ? -1 : 1) * (Number(m[6]) * 60 + Number(m[7] || 0));
  if (start !== Number(cfg?.startHour) || (end - start) * 3600000 !== Number(cfg?.durationMs) || Number(m[2]) || Number(m[4])) return null;
  return { offsetMin, startHour: start, endHour: end };
}

// ------------------------------------------------------------------ guard (sentry) deployment
// AUTHENTICATED NATIVE RULES:
//   who    700:93 "Only the defending guild can position guards.", 700:94 / 701:205 master only; guide 32: the lord deploys
//          through Lorenzo (job 126 SENTRY_OPEN on 6008 / 6009 / 6010)
//   when   701:213 "Can only place guards during Preparation phase.", 700:92 "Cannot position guard during the battle."; guide 32:
//          "not possible during the siege, but rather before it starts or during the waiting period before defense" and
//          "Upon becoming the defending guild, a 2-minute preparation time is granted to deploy guards"
//   cost   config SENTRY_UPGRADE_COST 100000 per guard (guide 32: "Guards cost 100,000 DIL each")
//   limit  config MAXSENTRY 100 (701:218 "All guards have been deployed.", 700:106 "Exceeded the max number of guards.")
//   types  config SENTRY_INDEX 50001-50006 = share/creature/sentry.csv records (window: six buttons of ui_siegeguardwnd.txt)
//   rules  320:106 "Guard will be deployed & DIL spent if location is valid. Guards cannot be moved or recalled once deployed.";
//          guide 32: deployed guards reset when the defending guild changes
// ENABLED: native mask/cell, sentry stats/actions/results, host guard lifecycle
// and the native deployment window are integrated. Missing prepared guard data
// still refuses before any debit or placement.
// CONFLICT (in-game config/guide kept): 100:30-33 describe Squad 30 / Troop 60 / Company 100 guards for 300,000 / 600,000 /
//   1,000,000 DIL with upgrade offsets; the Renew config, the Renew window and the guide charge 100,000 DIL per guard.
/** 'peace' (no battle) | 'preparation' (the 2-minute window after a capture) | 'battle' (deployment refused). */
export function renewGuardWindow({ battle = null, now = 0 } = {}) {
  if (!battle) return 'peace';
  return battle.phase === 'battle' && now < Number(battle.prepUntil || 0) ? 'preparation' : 'battle';
}
/** First native refusal [cate, code] of a guard intent; null allows cell/data/wallet validation. */
export function renewGuardRefusal({ window, guild, owner, master }) {
  if (window === 'battle') return [701, 213];
  if (!guild) return [701, 203];
  if (owner !== guild) return [701, 204];
  if (!master) return [701, 205];
  return null;
}
export const RENEW_GUARD_DEPENDENCIES = Object.freeze([]);

// ------------------------------------------------------------------ observer (spectator) entrance
// AUTHENTICATED NATIVE RULES: castle entrances 6014 / 6015 / 6016 carry job 36 ENTER_SIEGE_OBSERVER with the castle index;
// config OBSERVER_COUNT 200; stringtable_siegeUI.txt 290:129-135 are the spectator refusals ("There are no available regions
// to move to.", "This is not a siege war area.", "You cannot enter siege war spectator mode.", "It is not the scheduled time
// for the siege war.", "You cannot spectate while mounted on a vehicle.", "The maximum number of spectators has been
// exceeded.", "Failed to enter spectator mode due to an unknown reason."). No guild, level or fee condition is stated.
// Renew has no observer/info rows. The active service explicitly adapts native
// castle travel locations plus classic ticket/camera/delay values; see
// src/config/engine-chosen-siege-renew-observer.js. This is not an original region list.
export const RENEW_OBSERVER_TEXT = Object.freeze({ noRegions: [290, 129], notArea: [290, 130], cannot: [290, 131], notTime: [290, 132], mounted: [290, 133], full: [290, 134], unknown: [290, 135] });
export function renewObserverRefusal({ battle, mounted, count = 0, capacity = 0, regions = 0 }) {
  if (!battle) return RENEW_OBSERVER_TEXT.notTime;
  if (mounted) return RENEW_OBSERVER_TEXT.mounted;
  if (capacity > 0 && count >= capacity) return RENEW_OBSERVER_TEXT.full;
  if (!(regions > 0)) return RENEW_OBSERVER_TEXT.cannot;
  return null;
}
export const RENEW_OBSERVER_DEPENDENCIES = Object.freeze([]);

// ------------------------------------------------------------------ brokerage tax
// AUTHENTICATED NATIVE RULES: config TAX_RATIO 0.4, TAX_HOUR 0 / TAX_MINUTE 5 (guide 32: "taxes ... are paid and collected at
// 00:05"), TAX_CAL 0:00-0:10; tax window ui_siegetaxwnd.txt Day 1..Day 7 + Collect / Collect all (320:200-209); 701:380
// "Tax information cannot be checked while Siege is in progress.", 701:400-405 receive / maximum / already / not updated /
// none / guild server; guide 32: the lord collects through Lorenzo (job 125 TAX_INFO) from the brokerage fees of the server,
// the previous day's tax until the next siege, all accumulated tax resets at each siege start; guide 24: brokerage
// (consignment) commission is 5% of the sale (= share/formula.ini fConsignmentCommissionRatio 5.0).
// Enabled after owner approval 2026-10-13: literal40% of the existing sale fee
// per castle, ledger in the sale transaction, carried lord DIL on collection.
// ENGINE-CHOSEN allocation is explicit; no extra buyer/seller fee is charged.
export const RENEW_TAX_DEPENDENCIES = Object.freeze([]);

// ------------------------------------------------------------------ defender skills (enabled native service)
// AUTHENTICATED NATIVE RULES (in addition to SIEGE 100:42 and status 50160-50162 recorded by
// src/game/siege-renew-defender-skill-rules.js): the castle map scripts' message tables share/dungeon/dungeon_193/194/195_
// zenoa_castle_*.csv bind strings script/string/dungeon/stringtable_dungeon_06.txt cate 193 / 194 / 195: 100 "Use Siege
// skill." with menu 101-103 "<Castle> Guardian / Power / Domination", 110 "Siege skill conditions not met.", 111 "Only usable
// during Siege.", 112 "Siege skill only usable by guild leader.", 113 "Incorrect Channel.", 114 "Insufficient level.", 115
// "Siege skills only usable by defending guild.", 116 "Insufficient DIL.", 117 "Not yet available.", 118 "Siege skill only
// available during Siege battles.", 119 "[message] Preparation time elapsed.", 300 / 301 Preparation / Battle timers.
// The skill cost is paid from the acting lord's carried DIL. Castle-owned durable
// cooldown custody remains explicitly ENGINE-CHOSEN.
export const RENEW_SKILL_MESSAGES = Object.freeze({ menu: 100, conditions: 110, onlySiege: 111, leaderOnly: 112, channel: 113, level: 114, defendingOnly: 115, dil: 116, notYet: 117, battleOnly: 118, prepElapsed: 119 });
