// SIEGE: pure rules of the classic Zenoa Castle siege war (map 23), shared by the host (server/world/siege.mjs) and the client
// (src/systems/extras/siege.js). Every number comes from the Global data:
//   gamedata/events.json modes.siege   share/siege/config.csv (MONEY, LEVEL, MEMBERCOUNT, MAPINDEX, GATEMAXHP, UPGRAGECOST,
//                                       UPGRADEGATEHP, ZEOLITENONPKTIME, WARTIME, ENDWARACTIONTIME, REVIVALTICK, REIGNOCCUPYTIME,
//                                       REIGNMAXDISTANCE, ...), location.csv (1 inner / 2 outer castle, 101..105 pendants, 201 end),
//                                       tax.csv (Buy/Sell 6), taxratio.csv
//   events.json maps[23].bricks         30001..30003 East / West / South Gate, 31001..31005 guardian stones (Pendant of Spirit /
//                                       Earth / Water / Wind / Fire), events.json bricks (maxHP, defaultHP, resists, lifeTime)
//   events.json modes.siegeRenew.config START_WEEK 0 / START_HOUR 19 (the only start time in the data)
//   script/string/siege/stringtable_siege.txt (group SIEGE) 100 / 500 / 510 / 700 / 701 / 800, stringtable_siegeUI.txt 290 / 320
// Gaps the data leaves open are in src/config/engine-chosen-siege.js (tagged ENGINE-CHOSEN (not in Global data)).

const first = v => Array.isArray(v) ? v[0] : v;
const n = v => { const x = Number(first(v)); return Number.isFinite(x) ? x : 0; };

export const SIEGE_MAP = 23;
export const GATES = Object.freeze([30001, 30002, 30003]);              // East / West / South Gate (Lorenzo jobs 27 / 28 / 29)
export const STONES = Object.freeze([31001, 31002, 31003, 31004, 31005]); // Pendant of Spirit / Earth / Water / Wind / Fire
export const GATE_JOBS = Object.freeze({ 27: 30001, 28: 30002, 29: 30003 });
export const JOBS = Object.freeze({ TELEPORT: 21, ENTRY: 22, SEAL: 23, STARTTIME: 24, REIGN: 25, INFO: 26, GATE1: 27, GATE2: 28, GATE3: 29,
  GATEINFO: 30, READYSEAL: 32, TAX: 125 });
/** Pendant location rows (location.csv 101..105) of each guardian stone; respawn names 510:7..11. */
export const STONE_LOCATION = Object.freeze({ 31001: 101, 31002: 102, 31003: 103, 31004: 104, 31005: 105 });

/** Original strings: [cate, code] of group SIEGE (stringtable_siege.txt) unless noted. */
export const S = Object.freeze({
  infoFree: [100, 10], infoHeld: [100, 11], infoPrep: [100, 12], infoBattle: [100, 13],
  info: [500, 200], infoTime: [500, 201], infoSeals: [500, 202], infoNoTime: [500, 203], infoSealOpen: [500, 205], infoSealList: [500, 206],
  infoStarted: [500, 207], infoSealClosed: [500, 208],
  respawnHelp: [510, 1], inner: [510, 2], outer: [510, 4], pendant: [510, 7],
  registered: [700, 1], feePaid: [700, 2], noDil: [700, 3], notMember: [700, 4], masterOnly: [700, 5], guildLevel: [700, 6],
  cannotRegister: [700, 7], cannotNow: [700, 8], members: [700, 10], confirmed: [700, 13], markRequired: [700, 22],
  alreadyStarted: [700, 29], timeChanged: [700, 30], badTime: [700, 32], notAnnounceTime: [700, 33], notDefender: [700, 34],
  notMaster: [700, 35], alreadyAnnounced: [700, 37], timeAnnounced: [700, 40], notAuthorized: [700, 44], cannotMove: [700, 48],
  waitStart: [700, 49], respawnWait: [700, 54], started: [700, 55], notInSiege: [700, 56], otherEmpathy: [700, 57],
  empathyEnded: [700, 58], offenceOnly: [700, 60], twoPendants: [700, 62], tooFar: [700, 71], died: [700, 72], noPendant: [700, 73],
  failed: [700, 74], won: [700, 75], empathizing: [700, 76], leftMap: [700, 79], defenderOnly: [700, 86], inBattle: [700, 87],
  defenderCannot: [700, 97], notRegistered: [700, 99], sealsFull: [700, 109], noTunnel: [700, 102], cannotEnter: [700, 107],
  alreadyRequested: [700, 112], youWon: [700, 122], youLost: [700, 123], startNow: [700, 124], stoneDestroyed: [700, 127],
  empathyStart: [700, 128], empathyLeft: [700, 129], empathyFailed: [700, 130], notYet: [700, 145], onlySiege: [700, 146],
  insufficientDil: [700, 147], in30: [700, 150], in10: [700, 151], in5: [700, 152],
  guardianDestroyed: [701, 300], victorious: [701, 302], ended: [701, 303],
  taxInBattle: [701, 380], taxReceived: [701, 400], taxMax: [701, 401], taxAlready: [701, 402], taxNotYet: [701, 403], taxNone: [701, 404],
  gateLow: [800, 4], noPvp: [800, 60],
});
/** stringtable_siegeUI.txt (group NORMAL): announce / respawn / tax window texts. */
export const UI = Object.freeze({ confirmTitle: [290, 1], willStart: [290, 2], announceTitle: [290, 6], date: [290, 8], dateTime: [290, 7], hour: [290, 9],
  respawnTitle: [290, 40], respawnIn: [290, 41], empathyLeft: [290, 42], day: [320, 200], collect: [320, 207], collectAll: [320, 208], done: [320, 209],
  maxDur: [320, 1], curDur: [320, 2], perPoint: [320, 6] });

/** Numbers of config.csv / tax.csv (modes.siege). */
export function siegeConfig(mode, renew = null) {
  const c = mode?.config || {}, t = mode?.tax || {}, r = renew?.config || {};
  return {
    fee: n(c.MONEY), guildLevel: n(c.LEVEL), members: n(c.MEMBERCOUNT), map: n(c.MAPINDEX) || SIEGE_MAP,
    gateMaxHp: n(c.GATEMAXHP), upgradeCost: n(c.UPGRAGECOST), upgradeHp: n(c.UPGRADEGATEHP),
    stoneNonPkMs: n(c.ZEOLITENONPKTIME), damageBonusRatio: n(c.DAMAGEBONUSRATIO), endLocation: n(c.ENDWARLOCATIONINDEX),
    warMs: n(c.WARTIME) * 1000, endActionMs: n(c.ENDWARACTIONTIME) * 1000, revivalMs: n(c.REVIVALTICK),
    reignMs: n(c.REIGNOCCUPYTIME) * 1000, reignDistance: n(c.REIGNMAXDISTANCE), alarmSec: n(c.INFORMALARMTIME),
    decreaseTickPerStone: n(c.DESCREASETICKPERZEOLITE), reignFailStones: n(c.REGINFAILZEOLITECOUNT), decreaseGuildLevel: n(c.DECREASEGUILDLEVEL),
    attachStatus: n(c.ATTACHSTATUSINDEX),
    tax: { buy: n(t.BuyRatio), sell: n(t.SellRatio), portal: n(t.PotalRatio), socket: n(t.AddSocketRatio), upgrade: n(t.ItemUpgradeRatio) },
    startWeekday: n(r.START_WEEK), startHour: n(r.START_HOUR),
  };
}

/** location.csv rows resolved -> {index: {x, z, dirDeg, desc}} (map 23 cells, +0.5 = cell centre). */
export function siegeLocations(mode) {
  const out = {};
  for (const r of mode?.locationsResolved || []) if (r.location) out[r.Index] = { index: r.Index, x: r.location.x + 0.5, z: r.location.y + 0.5, dirDeg: r.location.directionDeg || 0, desc: r.DescIndex };
  return out;
}

/** The castle's bricks (maps[23].bricks rows [uid, brick, x, z, dir, isCreate, revival, ...]) joined with their definitions. */
export function siegeObjects(mapRow, bricks) {
  return (mapRow?.bricks || []).filter(r => GATES.includes(Number(r[1])) || STONES.includes(Number(r[1]))).map(r => {
    const def = bricks?.[r[1]] || bricks?.[String(r[1])] || {};
    return { uid: r[0], brick: Number(r[1]), x: r[2], z: r[3], dir: r[4], kind: GATES.includes(Number(r[1])) ? 'gate' : 'stone', name: def.name || '',
      maxHp: Number(def.maxHP) || 0, defaultHp: Number(def.defaultHP) || Number(def.maxHP) || 0, lifeTimeMs: Number(def.lifeTime) || 0, def };
  });
}

/** A gate's HP at the battle start: brick defaultHP + the fortified HP, capped at the brick maxHP. */
export function gateHp(obj, fortified = 0) { return Math.min(obj.maxHp, obj.defaultHp + Math.max(0, Math.floor(fortified) || 0)); }
/** Fortification: every UPGRAGECOST DIL adds UPGRADEGATEHP HP (320:6 "1,000 DIL = 1 durability point"), up to the brick maxHP. */
export function fortifyQuote(cfg, obj, fortified, dil) {
  const units = Math.floor((Number(dil) || 0) / cfg.upgradeCost);
  if (!(cfg.upgradeCost > 0) || !(cfg.upgradeHp > 0) || units < 1 || units * cfg.upgradeCost !== Number(dil)) return { error: 'amount' };
  const room = Math.max(0, obj.maxHp - gateHp(obj, fortified)), add = units * cfg.upgradeHp;
  if (add > room) return { error: 'max', room, maxDil: Math.floor(room / cfg.upgradeHp) * cfg.upgradeCost };
  return { units, cost: units * cfg.upgradeCost, add, hp: gateHp(obj, fortified) + add };
}
/** Damage left after a brick's resist percentages (the same reading as the event objects of server/world/event-object-combat.mjs). */
export function brickDamage(def, amount, kind = 'melee') {
  const pct = v => Math.max(0, Math.min(100, Number(v) || 0));
  const typed = kind === 'magic' ? def?.magicResist : kind === 'range' ? def?.rangeDamageResist : def?.meleeDamageResist;
  const resist = Math.max(pct(typed), kind === 'magic' ? 0 : pct(def?.physicalResist));
  return Math.max(0, Math.round((Number(amount) || 0) * (100 - resist) / 100));
}
/** Tax on a DIL amount at a tax.csv ratio (percent). */
export const taxOf = (amount, ratio) => Math.max(0, Math.floor((Number(amount) || 0) * (Number(ratio) || 0) / 100));

/** Start of the next weekly battle at/after `now`: weekday + hour in UTC (ENGINE-CHOSEN zone). hour overrides the default hour. */
export function nextStart(now, cfg, hour = null, zoneOffsetMin = 0) {
  const h = Number.isInteger(hour) ? hour : cfg.startHour, local = new Date(now + zoneOffsetMin * 60000);
  const day = local.getUTCDay(), base = Date.UTC(local.getUTCFullYear(), local.getUTCMonth(), local.getUTCDate(), h) - zoneOffsetMin * 60000;
  let t = base + ((cfg.startWeekday - day + 7) % 7) * 86400000;
  if (t + cfg.warMs <= now) t += 7 * 86400000;
  return t;
}
/** Phase of a scheduled battle at `now`: 'idle' (before) / 'battle' / 'over' (after WARTIME). */
export function phaseAt(now, startAt, cfg) { return now < startAt ? 'idle' : now < startAt + cfg.warMs ? 'battle' : 'over'; }
/** Countdown notices 700:150 / 151 / 152: the minute marks before the start. */
export const COUNTDOWN = Object.freeze([[30, S.in30], [10, S.in10], [5, S.in5]]);

/** Registration check (700:x). ctx: {guild, isMaster, level, members, dil, owner, registrations, seals, phase, hasMark}. */
export function registrationError(cfg, ctx, maxSeals) {
  if (!ctx.guild) return 'notMember';
  if (!ctx.isMaster) return 'masterOnly';
  if (ctx.phase === 'battle') return 'alreadyStarted';
  if (ctx.owner && ctx.owner === ctx.guild) return 'defenderCannot';
  if (ctx.registrations.includes(ctx.guild)) return 'alreadyRequested';
  if (ctx.level < cfg.guildLevel) return 'guildLevel';
  if (ctx.members < cfg.members) return 'members';
  if (!ctx.hasMark) return 'markRequired';
  if (ctx.registrations.length >= maxSeals) return 'sealsFull';
  if (!(ctx.dil >= cfg.fee)) return 'noDil';
  return null;
}
/** Empathy with Juto (REIGN_SYSOP): offending guild master with >= 2 pendants (700:60 / 62 / 73), no other empathy (700:57). */
export function empathyError(ctx) {
  if (!ctx.battle) return 'onlySiege';
  if (!ctx.guild || !ctx.attacker) return 'offenceOnly';
  if (!ctx.isMaster) return 'masterOnly';
  if (ctx.other) return 'otherEmpathy';
  if (!ctx.pendants) return 'noPendant';
  if (ctx.pendants < 2) return 'twoPendants';
  return null;
}
/** Is a map row a field where guild-war members may fight (IsPvP 1 and PVP_PeaceZone 0)? */
export const isPvpField = row => Number(row?.IsPvP) === 1 && Number(row?.PVP_PeaceZone) === 0;
/** Fill %s / %d / %lld and <NAME>-style tags in order. */
export function fillText(text, ...args) {
  let i = 0;
  return String(text || '').replace(/%(?:lld|ld|d|s|0?\d*d)|<[A-Z_]+[0-9]?>/g, m => (i < args.length ? String(args[i++]) : m));
}
/** Strip the string-table markup ([message], [siege], @<effectui>..., <color=...>, <center>, <font=..>). */
export const plainText = t => String(t || '').replace(/@<[^>]*>[^@]*/g, '').replace(/^\[(message|siege)\]\s*/i, '').replace(/<\/?(color|center|font|set|overlab|img)[^>]*>/gi, '').replace(/\s*\/\s*/g, ' ').trim();
