// Active SiegeRenew castles 193 Imperial / 194 Golden / 195 Conbelton: controller rules on top of the native data shape
// in src/game/siege-renew-rules.js (read-only here). Supported facts only; conflicts and gaps are listed below.
//
// AUTHENTICATED NATIVE SOURCES (data/unpacked/data; byte-identical to the Global packs per parallel-siege-renew evidence):
//   share/siege_renew/config.csv   LEVEL 10, MEMBERCOUNT 30, ENTERPCCOUNT 300, START_WEEK 0, START_HOUR 19, PLAY_KEEP_TIME
//                                  3600, MAP_1..3 193/194/195 channel 100, TAX_HOUR 0 / TAX_MINUTE 5, TAX_RATIO 0.4,
//                                  TAX_CAL 0:00-0:10, MAXSENTRY 100, SENTRY_UPGRADE_COST 100000, SENTRY_INDEX 50001-50006,
//                                  OBSERVER_COUNT 200
//   share/siege_renew/location.csv type 1 defending position, 2 attacking position, 3 return (Ardeca 303,136), 4 gate
//                                  strongholds, 5 Castellan Room, 6 Ardeca, 99 battlefield arrival of the warp stone
//   share/map/19x_siege_new_*/brick_*.csv  crystal UID 19308/19412/19503 (bricks 36995/36996/36997, HP 5000, all resists 94,
//                                  IsCreate 1); the gate UIDs of gateupgradeinfo.csv have no placement (dependency)
//   share/creature/npc.csv         castle entrances 6014/6015/6016 (job 21 SIEGE_TELEPORT + 36 observer, index = castle) placed
//                                  on maps 150 / 63 / 17; Lorenzo 6008/6009/6010 jobs 125 TAX_INFO, 126 SENTRY_OPEN, 127
//                                  SIEGE_DEFENDER_TELEPORT, 128 SIEGE_MASTER_TELEPORT, 129 SIEGE_DEFENDER_SKILL (index = castle);
//                                  warp stones 6204-6206 quest 405-407 "[Move] Enter the Battlefield" (warp 11925->11926,
//                                  11927->11928, 11929->11930); Jegarr 6030-6032 quest 474-476 "[Move] Leave Castellan's chamber"
//   share/dkmaplist.csv            193/194/195 "Siege War" DK_Index 100, RespawnType NONE
//   script/string/siege/stringtable_siege.txt  700:150/151/152 "Siege begins in 30/10/5 minutes.", 700:124 "The Siege Battle
//                                  will start now.", 700:6 "Insufficient guild level.", 700:10 "Insufficient guild members.",
//                                  700:107 "Cannot enter the Siege map at this time.", 700:145 "Not yet available.", 701:203
//                                  "Only available for guild members.", 701:217 "Siege not in progress.", 701:300 "[siege]The [%s]
//                                  Guild has destroyed the Guardian Stone. You will be moved to the field shortly.", 701:302
//                                  "[<GUILDNAME>] is victorious in the Siege of <MAPNAME>.", 701:303 "The Siege has ended.", 701:380
//   Official Global guide guideNo=32 (webapi-dekaron.ubifungames.com, contents SHA-256 db3ebaa5...): enter through each Castle
//     Entrance NPC after the Siege War begins; max 300 players; all guild members regardless of guild level; destroying the
//     Guardian Stone makes the guild the defending guild; 2-minute preparation; the guild holding the castle at the end of the
//     1-hour siege keeps it; defenders teleport to each stronghold through Lorenzo; reconnecting during the siege starts from
//     Ardeca; guards 100,000 DIL each, reset when the defending guild changes; taxes from brokerage fees paid at 00:05, reset at
//     each siege start; weekly lord's treasure chest. Schedule shown there: Sunday 9 to 10 PM, channel 2.
export const RENEW = Object.freeze({
  castles: Object.freeze([193, 194, 195]),
  entranceJob: 21, observerJob: 36, taxJob: 125, sentryJob: 126, defenderTeleportJob: 127, masterTeleportJob: 128, skillJob: 129,
  warpStones: Object.freeze({ 193: 6204, 194: 6205, 195: 6206 }), jegarr: Object.freeze({ 193: 6030, 194: 6031, 195: 6032 }),
  warpStoneQuest: Object.freeze({ 193: 405, 194: 406, 195: 407 }), jegarrQuest: Object.freeze({ 193: 474, 194: 475, 195: 476 }),
  guardian: Object.freeze({193: Object.freeze([19308,36995]),194: Object.freeze([19412,36996]),195: Object.freeze([19503,36997])}),
  preparationMs: 120000,   // official guide 32: "a 2-minute preparation time is granted"
  text: Object.freeze({ in30: [700, 150], in10: [700, 151], in5: [700, 152], startNow: [700, 124], started: [700, 55], guildLevel: [700, 6],
    guildMembers: [700, 10], cannotEnter: [700, 107], notYet: [700, 145], guildOnly: [701, 203], notInProgress: [701, 217], destroyed: [701, 300],
    victorious: [701, 302], ended: [701, 303], taxInBattle: [701, 380], noInfo: [701, 214],
    inBattle: [700, 87], inventoryFull: [700, 84], siegeMapOnly: [701, 202], defendingOnly: [701, 204], leaderOnly: [701, 205], guardPrep: [701, 213] }),
});

// DELIBERATE ENGINE CHOICES (bounded; none is presented as a native rule).
export const RENEW_ENGINE_CHOICES = Object.freeze([
  'Start time (AUTHENTICATED zone since round 3): native START_WEEK 0 / START_HOUR 19 / PLAY_KEEP_TIME 3600 at the UTC+1 offset that the native entrance text 100:10 / 100:11 states ("Every Sunday 7:00 PM to 8:00PM Central European Time (UTC+1)"), read at run time by src/game/siege-renew-service-rules.js. Only when that text is missing or disagrees with the raw hour does the controller fall back to UTC (the classic controller\'s zone). The guide\'s Sunday 21:00-22:00 names no zone; the in-game value is kept.',
  'Eligibility: native LEVEL 10 / MEMBERCOUNT 30 are read like the classic keys (guild level, guild member count; 700:6 / 700:10). The guide sentence "all members of the guild can participate, regardless of guild level" conflicts; the in-game values are kept (owner rule) and the conflict is recorded.',
  'Outside the battle only the castle owner\'s guild may enter (native 100:10 / 100:11 "Only the defending guild can enter outside Siege battle."). Engine reading: the owner guild enters a per-castle peace scene at the defending position; at the next start that scene becomes the battle scene with its occupants as defenders, and a member who no longer belongs to the owner guild is returned to Ardeca.',
  'Sides: the castle owner\'s guild defends; every other eligible guild attacks; guilds of one alliance never hit each other, and an attacker allied with the owner cannot damage the crystal.',
  'The crystal takes damage only from attackers outside the 2-minute preparation. Damage authorization and its native brick resists (94) run before HP mutation; a capture repairs it to native maximum HP for the next owner.',
  '701:300 "You will be moved to the field shortly." is applied as: after a takeover, the new defenders move to the defending position (type 1) and everybody else to the attacking position (type 2).',
  'Attackers cannot enter during the preparation (700:107); defenders can enter at any time during the battle.',
  'Revive inside a castle: defenders at type 1, attackers at type 2 (no REVIVALTICK exists in the renew config; the ordinary revive wait applies).',
  'Participants may leave to the castle return point (type 3) at any time; at the end every participant is moved there. A reconnect resumes nowhere: the saved castle instance resolves to the same return point in Ardeca (guide: "start from Ardeca").',
  'Capacity: ENTERPCCOUNT 300 participants per castle; a full castle refuses with 700:107.',
  'Gate reconstruction: all 20 native gate UIDs use original brick models, five upgrade prices, default/max HP and resistances. Doorway cells, UID-to-model bindings, native-size half-extents, linear HP steps between source endpoints, capture-reset levels and Lorenzo guard-service access are explicit ENGINE-CHOSEN adaptations because supplied clients omit those bindings. Upgrades are atomic from carried lord DIL only during peace/preparation; closed gates block native castle paths and enemy damage opens them without ordinary rewards.',
  'Lorenzo tax125, native guard deployment126 and defender skills129 are active. Owner-approved tax allocation is40% of the existing brokerage fee per castle into carried lord DIL. Guard pool100, survivor full-HP recreation, collision-safe1.5m knockback and castle-owned skill cooldown custody are ENGINE-CHOSEN.',
  'Observer36 attaches to the actual running castle instance, hidden/noncombat and separate from participants. ENGINE-CHOSEN: native attack/stronghold/defend/Guardian points serve as regions; native200 capacity is per castle; classic54501 ticket,1000ms cooldown and10 camera speed are reused. Entry excludes owner/participating guilds, exit/end/reconnect return to native Ardeca. No original Renew region table is claimed.',
  'Lord\'s Treasure Chest: native trigger/drop/item-set tables (src/game/siege-renew-chest-rules.js); regenerated for the castle owner in the same durable write as the battle end; claimed once by the owner guild master in the peace scene; the reward enters the bag atomically with the claim.',
]);

// DEPENDENCIES (absent from the supplied data; nothing is invented for them).
export const RENEW_DEPENDENCIES = Object.freeze([
  'The guide channel "Server 2" versus native castle channel 100 (dkmaplist DK 100); the native channel is kept.',
]);

const num = (v, d = 0) => { const n = Number(v); return Number.isFinite(n) ? n : d; };

/** The castle's location of a type (1 defend, 2 attack, 3 return, 5 castellan room, 99 warp arrival), or null. */
export function renewLocation(castle, type) {
  if (type === 3 || type === 6) return castle.locations.find(l => l.type === type) || null;
  return castle.locations.find(l => l.type === type && l.map === castle.map) || null;
}
/** Gate stronghold teleport points (type 4) of a castle. */
export const renewStrongholds = castle => castle.locations.filter(l => l.type === 4 && l.map === castle.map);

/** Guild eligibility (classic key reading): [cate, code] of the refusal or null. */
export function renewGuildRefusal(cfg, { guild, level, members }) {
  if (!guild) return RENEW.text.guildOnly;
  if (!(num(level) >= cfg.guildLevel)) return RENEW.text.guildLevel;
  if (!(num(members) >= cfg.members)) return RENEW.text.guildMembers;
  return null;
}

/** 'defender' when the guild owns the castle, else 'attacker' (the caller checks eligibility first). */
export const renewSide = (ownerGuild, guild) => (ownerGuild && ownerGuild === guild ? 'defender' : 'attacker');

/** Next weekly start at or after now and the battle phase. START_WEEK / START_HOUR are wall-clock values at zoneOffsetMin
 * minutes east of UTC (the native entrance text states UTC+1; 0 = the UTC fallback). */
export function renewNextStart(now, cfg, zoneOffsetMin = 0) {
  const offset = (Number(zoneOffsetMin) || 0) * 60000, local = new Date(now + offset);
  const base = Date.UTC(local.getUTCFullYear(), local.getUTCMonth(), local.getUTCDate(), cfg.startHour) - offset;
  let t = base + ((cfg.startWeekday - local.getUTCDay() + 7) % 7) * 86400000;
  if (t + cfg.durationMs <= now) t += 7 * 86400000;
  return t;
}
export const renewPhaseAt = (now, startAt, cfg) => (now < startAt ? 'idle' : now < startAt + cfg.durationMs ? 'battle' : 'over');
/** Countdown minute marks before the start (700:150 / 151 / 152). */
export const RENEW_COUNTDOWN = Object.freeze([[30, RENEW.text.in30], [10, RENEW.text.in10], [5, RENEW.text.in5]]);
