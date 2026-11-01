// PvP rules (PvP foundation). ONE place for every player-vs-player value.
//
// Global data used (an untouched Global client install was compared: its data is byte-identical to this copy):
//   share/formula.ini   fPCDamageRatio 1.0, fPCDefenseRatio 1.0, byPKBlockRate 90, byPKGuardRate 50,
//                       dwWinPVPPointRatio 2, dwLosePVPPointRatio 1, dwLossPVPPointRatio 2, fLimitWinPVPRatio 1.2,
//                       dwPVPReviveTick 1, byReviveHPRatio 100, byReviveMPRatio 100,
//                       nPKDamageRate 0 / nPKDefeatRate 50 (named PK = non-consensual kills; not used by duels)
//   share/pc/pcclass.csv PC_PHYSICAL_DAMAGERATE / PC_MAGICAL_DAMAGERATE (per class), GUARD_RATE, GUARD_EFFICIENCY,
//                       COMPETENCE_PVP_BLOCK_RATE_MAX 20, COMPETENCE_PVP_GUARD_RATE_MAX 30
//   option names        share/item/itemoption_*.csv, petoption.csv, vehicleoption.csv descriptions:
//                       PVPDAMAGE_PVP_DAMAGE_ADD "PVP Attack +", PVPDAMAGE_PVP_DAMAGERATE_ADD "PVP Damage Increase Rate +%",
//                       PC_DAMAGE_DAMAGE_ADD "Antipersonnel Attack Power +", PC_DAMAGE_DAMAGE_MUL "Antipersonnel Attack Power +%",
//                       PC_DAMAGE_ARMOR_ADD "Antipersonnel Defense +", KNIGHT_SPECIAL_PC_TOLERANCE "PVP DMG res:%"
//   PvP option codes    every PVPDAMAGE_ / PC_DAMAGE_ code and KNIGHT_SPECIAL_PC_TOLERANCE in the share csv tables (22, PVP_OPTION_CODES):
//                       items (itemoption_*, itemmunzang_*, incuse, costume, pet, vehicle, optionchange), buff statuses
//                       (share/skill/status.csv: "PvP Attack +10%" = PVPDAMAGE_PVP_DAMAGE_MUL 10, "DEF Decrease" = DEFENSE_SUB 5 +
//                       PC_DAMAGE_ARMOR_MUL -5) and passive / mastery skills (k_5_1_passive_att_6 / def_6, <class>_10_1_pvp_damage_power,
//                       <class>_10_3_pvp_damage_tolerance). Items reach stats.itemOptions; deriveStats sums the status / passive ones
//                       into stats.pvpOptions (progression.js). Both are read here.
//   item columns        "PVP Option Damage" / "PVP Option Defence" (tools/build-items.mjs -> pvpDmg / pvpDef)
//   tooltip 23:37       the shield is the first line of defence in PvP; HP takes damage once it is depleted
//   strings 1008:16     re-request after a refusal: "Please try again in 30 seconds."
//   maplist.csv IsPvP   1 = duels allowed on the map (280:106 otherwise)
//
// Everything tagged ENGINE-CHOSEN (not in Global data) is a reading or a value the shipped data does not define.
// The owner can change any of them here; the host (server/world/pvp.mjs) and the tests read only this module.

import {normalizeOptionName} from '../systems/items/option-identities.js';
import {penetratedDefense,blockChance as masteryBlockChance,guardChance as masteryGuardChance,guardEfficiency,combatOptionValue} from './combat.js';

/** Every PvP option code of the Global data (a test scans every csv table under share and fails when a code is missing here). */
export const PVP_OPTION_CODES = Object.freeze([
  'PVPDAMAGE_PVP_DAMAGE_ADD', 'PVPDAMAGE_PVP_DAMAGE_MUL', 'PVPDAMAGE_PVP_DAMAGERATE_ADD',
  'PC_DAMAGE_DAMAGE_ADD', 'PC_DAMAGE_DAMAGE_MUL', 'PC_DAMAGE_ARMOR_ADD', 'PC_DAMAGE_ARMOR_MUL', 'KNIGHT_SPECIAL_PC_TOLERANCE',
  'PC_DAMAGE_ALLMAGICRESIST_ADD', 'PC_DAMAGE_ALLMAGICRESIST_MUL', 'PC_DAMAGE_ALLPHYSICSRESIST_ADD', 'PC_DAMAGE_ALLPHYSICSRESIST_MUL',
  'PC_DAMAGE_FIRERESIST_ADD', 'PC_DAMAGE_FIRERESIST_MUL', 'PC_DAMAGE_ICERESIST_ADD', 'PC_DAMAGE_ICERESIST_MUL',
  'PC_DAMAGE_LIGHTINGRESIST_ADD', 'PC_DAMAGE_LIGHTINGRESIST_MUL', 'PC_DAMAGE_POSIONRESIST_ADD', 'PC_DAMAGE_POSIONRESIST_MUL',
  'PC_DAMAGE_CURSERESIST_ADD', 'PC_DAMAGE_CURSERESIST_MUL', 'PC_DAMAGE_DARKRESIST_ADD', 'PC_DAMAGE_DARKRESIST_MUL',
]);
// skill-engine element name -> the element part of the PC_DAMAGE_<X>RESIST_* codes (the data spells two of them LIGHTING / POSION)
const PC_RESIST_ELEMENT = { fire: 'FIRE', ice: 'ICE', lightning: 'LIGHTING', poison: 'POSION', curse: 'CURSE', dark: 'DARK', 'dark?': 'DARK' };

export const ENGINE_CHOSEN = Object.freeze({
  // --- damage composition -------------------------------------------------------------------------------
  /** ENGINE-CHOSEN (not in Global data): PC_*_DAMAGERATE is the percent by which a hit on a player is reduced,
   *  looked up for the ATTACKER's class and the hit's kind (melee/range = physical, magic = magical). */
  classRateOwner: 'attacker',
  /** ENGINE-CHOSEN (not in Global data): order of the PvP pipeline (see pvpDamage below). */
  pipeline: 'flat adds -> fPCDamageRatio x rate adds -> defence (x fPCDefenseRatio) -> class rate -> tolerance -> PC resist -> block/guard -> shield',
  /** ENGINE-CHOSEN (not in Global data): how the PvP option codes combine. The data names the codes ("PvP Attack +10%",
   *  "PK Damage Resistance Increase") and their values but not the formula: PVPDAMAGE_PVP_DAMAGE_MUL joins the percent adds of
   *  stage 2 (summed with PVPDAMAGE_PVP_DAMAGERATE_ADD and PC_DAMAGE_DAMAGE_MUL); PC_DAMAGE_ARMOR_MUL (and, for physical hits,
   *  PC_DAMAGE_ALLPHYSICSRESIST_MUL) is a percent on the defender's PvP defence points. Status and passive / mastery options
   *  are summed with the item options. Values of the mastery tables are read as written in the data. */
  pvpOptionReading: 'PVP_DAMAGE_MUL joins the percent adds; PC_DAMAGE_ARMOR_MUL / ALLPHYSICSRESIST_MUL scale the defence points',
  /** ENGINE-CHOSEN (not in Global data): PC_DAMAGE_ALLMAGICRESIST_* (magic hits) and PC_DAMAGE_<element>RESIST_* (the element of a
   *  skill hit) are resist points on the engine's resist scale (percent = points / 10, cap 75, the same as a player's element
   *  resist in the skill engine); the *_MUL code raises the points by that percent; the percent removes that share of the hit
   *  (the element part of an elemental skill hit, the whole hit for all-magic). */
  pcResistReading: 'resist points / 10 = percent (cap 75); *_MUL raises the points; applies to the element share / magic hits',
  /** ENGINE-CHOSEN (not in Global data): a skill hit on a duel opponent keeps the skill engine's PvE result (its own
   *  defence, element and crit rules) as the raw amount, then runs the PvP stages with only the PvP defence adds. */
  skillReading: 'PvE skill result -> PvP stages (PvP defence adds only)',
  /** ENGINE-CHOSEN (not in Global data): byPKBlockRate / byPKGuardRate are the percent of damage removed by a PvP
   *  block / guard; the PvP block / guard CHANCE is the defender's own rate capped by COMPETENCE_PVP_*_RATE_MAX. */
  blockGuardReading: 'byPK*Rate = % damage removed; chance = min(defender rate, COMPETENCE_PVP_*_RATE_MAX)',
  /** ENGINE-CHOSEN (not in Global data): the item "PVP Option Damage/Defence" columns are flat damage / defence. */
  itemPvpColumns: 'flat',
  /** ENGINE-CHOSEN (not in Global data): map level-difference ability caps are not applied to PvP hits. */
  applyMapCaps: false,
  /** ENGINE-CHOSEN (not in Global data): smallest damage of a landed PvP hit. */
  minDamage: 1,
  // --- 1:1 duel ---------------------------------------------------------------------------------------
  /** ENGINE-CHOSEN (not in Global data): request distance for 1008:1 / 1008:9 (world units; trade uses 12). */
  requestRange: 12,
  /** ENGINE-CHOSEN (not in Global data): seconds before an unanswered request auto-cancels (pvp_acceptwait bar). */
  acceptTimeoutSec: 15,
  /** ENGINE-CHOSEN (not in Global data): countdown of pvp_countui ("Your match will begin shortly." N sec). */
  countdownSec: 5,
  /** ENGINE-CHOSEN (not in Global data): radius of the limited area around the duel flag (midpoint of the two). */
  areaRadius: 25,
  /** ENGINE-CHOSEN (not in Global data): seconds a duellist may stay outside the area before forfeiting. */
  outsideForfeitSec: 5,
  /** ENGINE-CHOSEN (not in Global data): duel time limit; when it runs out the duel is a draw (no points). */
  timeLimitSec: 300,
  /** ENGINE-CHOSEN (not in Global data): the base PvP point value that the formula.ini ratios multiply. */
  basePoints: 10,
  /** ENGINE-CHOSEN (not in Global data): reading of the four point values:
   *  winner +Win x base, or +Lose x base when winner level > loser level x fLimitWinPVPRatio; loser -Loss x base (floor 0). */
  pointsReading: 'win=+Win*base (Lose*base if winnerLv > loserLv*Limit); loser -Loss*base, floored at 0',
  /** ENGINE-CHOSEN (not in Global data): dwPVPReviveTick is seconds before the loser's Reincarnate button works. */
  reviveTickUnit: 'seconds',
  /** ENGINE-CHOSEN (not in Global data): the shield starts each duel full (its regeneration rule is not in the data). */
  shieldAtStart: 'full',
  /** ENGINE-CHOSEN (not in Global data): seconds the pvpbattlewnd result panel stays on screen. */
  resultShowSec: 6,
});

const num = (v, d = 0) => (Number.isFinite(Number(v)) ? Number(v) : d);

/** Build the rules from parsed formula.ini ({key:value}) and pcclass.csv rows ({KEY:[per class]}). */
export function buildPvpRules(formula = {}, pcclass = {}) {
  const f = k => num(formula[k], NaN);
  const need = (k, v) => { if (!Number.isFinite(v)) throw new Error(`PvP rules: ${k} is missing from the data.`); return v; };
  const row = k => { const r = pcclass[k]; if (!Array.isArray(r) || !r.length) throw new Error(`PvP rules: pcclass ${k} is missing.`); return r.map(Number); };
  return Object.freeze({
    pcDamageRatio: need('fPCDamageRatio', f('fPCDamageRatio')),
    pcDefenseRatio: need('fPCDefenseRatio', f('fPCDefenseRatio')),
    pkBlockRate: need('byPKBlockRate', f('byPKBlockRate')),
    pkGuardRate: need('byPKGuardRate', f('byPKGuardRate')),
    winRatio: need('dwWinPVPPointRatio', f('dwWinPVPPointRatio')),
    loseRatio: need('dwLosePVPPointRatio', f('dwLosePVPPointRatio')),
    lossRatio: need('dwLossPVPPointRatio', f('dwLossPVPPointRatio')),
    limitWinRatio: need('fLimitWinPVPRatio', f('fLimitWinPVPRatio')),
    reviveTick: need('dwPVPReviveTick', f('dwPVPReviveTick')),
    reviveHpRatio: need('byReviveHPRatio', f('byReviveHPRatio')),
    reviveMpRatio: need('byReviveMPRatio', f('byReviveMPRatio')),
    physicalRate: row('PC_PHYSICAL_DAMAGERATE'), magicalRate: row('PC_MAGICAL_DAMAGERATE'),
    blockCap: row('COMPETENCE_PVP_BLOCK_RATE_MAX'), guardCap: row('COMPETENCE_PVP_GUARD_RATE_MAX'),
    guardRate: row('GUARD_RATE'),
    reRequestSec: 30,                                    // string 1008:16 "Please try again in 30 seconds."
    ...ENGINE_CHOSEN,
  });
}

/** Parse formula.ini text ("key ,value" lines). */
export function parseFormulaIni(text) {
  const out = {};
  for (const line of String(text).split(/\r?\n/)) { const m = /^\s*([A-Za-z_]\w*)\s*,\s*([-\d.]+)/.exec(line); if (m) out[m[1]] = Number(m[2]); }
  return out;
}
/** Parse pcclass.csv (KEY,class0,class1,...). */
export function parsePcclass(text) {
  const out = {};
  for (const line of String(text).split(/\r?\n/)) { const c = line.split(','); if (c.length > 2 && /^[A-Z_]/.test(c[0])) out[c[0]] = c.slice(1).filter(v => v !== ''); }
  return out;
}

const opt = (stats, name) => {
  const canonical=normalizeOptionName(name);
  return [stats?.itemOptions,stats?.pvpOptions].reduce((sum,options)=>sum+Object.entries(options||{}).reduce((part,[code,value])=>part+(normalizeOptionName(code)===canonical?num(value):0),0),0);
};

/**
 * One player-vs-player hit. attacker / defender: {classIndex, level, stats, shield}. raw: the attacker's rolled raw damage
 * before defence (the same roll the host uses for monsters). kind: 'melee' | 'range' | 'magic'. random(): [0,1).
 * Returns {amount (HP damage), shieldDamage, block, guard, detail}.
 */
export function pvpDamage(rules, { attacker, defender, raw, kind = 'melee', random = Math.random, defenceApplied = false, element = null, elementShare = 1 }) {
  const a = attacker.stats || {}, d = defender.stats || {};
  // 1. flat PvP attack adds (options + the item "PVP Option Damage" column)
  let dmg = Math.max(0, num(raw)) + opt(a, 'PVPDAMAGE_PVP_DAMAGE_ADD') + opt(a, 'PC_DAMAGE_DAMAGE_ADD') + num(a.pvpDamage);
  // 2. fPCDamageRatio and the percent adds
  dmg *= rules.pcDamageRatio * Math.max(0, 1 + (opt(a, 'PVPDAMAGE_PVP_DAMAGERATE_ADD') + opt(a, 'PC_DAMAGE_DAMAGE_MUL') + opt(a, 'PVPDAMAGE_PVP_DAMAGE_MUL')) / 100);
  // 3. defence: the host's defence curve, defence scaled by fPCDefenseRatio plus the PvP defence adds, then the percent codes
  // (skills: the skill engine already applied the defender's normal defence; only the PvP defence adds remain)
  const defMul = Math.max(0, 1 + (opt(d, 'PC_DAMAGE_ARMOR_MUL') + (kind === 'magic' ? 0 : opt(d, 'PC_DAMAGE_ALLPHYSICSRESIST_MUL'))) / 100);
  const defense = penetratedDefense(attacker, Math.max(0, ((defenceApplied ? 0 : num(d.defense)) + opt(d, 'PC_DAMAGE_ARMOR_ADD') + (kind === 'magic' ? 0 : opt(d, 'PC_DAMAGE_ALLPHYSICSRESIST_ADD')) + num(d.pvpDefense)) * rules.pcDefenseRatio * defMul), kind);
  dmg = dmg * 100 / (100 + defense);
  // 4. class damage rate of the attacker's class (percent reduction of hits on players)
  const cls = Math.max(0, Math.round(num(attacker.classIndex)));
  const rate = (kind === 'magic' ? rules.magicalRate : rules.physicalRate)[rules.classRateOwner === 'attacker' ? cls : Math.max(0, Math.round(num(defender.classIndex)))] || 0;
  dmg *= Math.max(0, 1 - rate / 100);
  // 5. PvP damage tolerance of the defender
  dmg *= Math.max(0, 1 - opt(d, 'KNIGHT_SPECIAL_PC_TOLERANCE') / 100);
  // Generic incoming-damage options also protect against players. Read their
  // live status/passive/item sources once here; the shared skill hook does not
  // run the monster-only incomingSkillDamage path for these targets.
  if (kind === 'melee') dmg *= 1 - Math.max(0, Math.min(90, combatOptionValue(defender, 'RESIST_DISTANCE_MELEEDAMAGE'))) / 100;
  if (kind === 'range') dmg *= 1 - Math.max(0, Math.min(90, combatOptionValue(defender, 'RESIST_DISTANCE_RANGEDAMAGE'))) / 100;
  dmg *= 1 - Math.max(0, Math.min(90, combatOptionValue(defender, 'DAMAGERATE_DAMAGEHP_MUL'))) / 100;
  // 5b. PvP-only resists of the defender (PC_DAMAGE_*RESIST_*): all-magic on magic hits, the element on an elemental skill hit
  const share = Math.min(1, Math.max(0, num(elementShare, 1))), el = PC_RESIST_ELEMENT[element];
  const resistCut = (code, part) => { const pts = opt(d, `${code}_ADD`) * (1 + opt(d, `${code}_MUL`) / 100); return pts > 0 ? part * Math.min(75, pts / 10) / 100 : 0; };
  const cut = (kind === 'magic' ? resistCut('PC_DAMAGE_ALLMAGICRESIST', 1) : 0) + (el ? resistCut(`PC_DAMAGE_${el}RESIST`, share) : 0);
  if (cut > 0) dmg *= Math.max(0, 1 - cut);
  // 6. PvP block / guard
  const dc = Math.max(0, Math.round(num(defender.classIndex)));
  const blockChance = masteryBlockChance(attacker,defender,Math.min(num(rules.blockCap[dc], 0), Math.max(0, num(d.blockRate))),{pvp:true});
  const guardChance = masteryGuardChance(attacker,defender,Math.min(num(rules.guardCap[dc], 0), Math.max(0, num(d.guardRate, rules.guardRate[dc]))),{pvp:true});
  let block = false, guard = false;
  if (random() * 100 < blockChance) { block = true; dmg *= 1 - rules.pkBlockRate / 100; }
  else if (random() * 100 < guardChance) { guard = true; dmg *= 1 - guardEfficiency(defender,rules.pkGuardRate) / 100; }
  let total = Math.max(rules.minDamage, Math.round(dmg));
  // Share damage only when the host supplies an actual living owned servant.
  // This follows the existing solo ordering (share before the PvP shield).
  // The pure rule reports the transfer; only the host mutates servant HP.
  const sharedDamage = defender.ownedServant ? Math.round(total * Math.max(0, Math.min(90, combatOptionValue(defender, 'DAMAGE_OWNERSHIP'))) / 100) : 0;
  total -= sharedDamage;
  // 7. shield first (tooltip 23:37), then HP
  const shield = Math.max(0, num(defender.shield));
  // SHIELD_TARGET_DAMAGE_ADD ("Additional Shield Damage", Rapid Fire and others): the attacker's status takes that many extra points off
  // a standing shield. ENGINE-CHOSEN reading of the status text: the HP damage stays exactly what the shield did not absorb.
  const absorbed = Math.min(shield, total);
  const shieldDamage = shield > 0 ? Math.min(shield, total + Math.max(0, combatOptionValue(attacker, 'SHIELD_TARGET_DAMAGE_ADD'))) : 0;
  return { amount: total - absorbed, shieldDamage, block, guard, ...(sharedDamage ? {sharedDamage} : {}), detail: { rate, defense: Math.round(defense), blockChance, guardChance } };
}

/** Points after a decided duel. Returns {winnerGain, loserLoss}. */
export function duelPoints(rules, winner, loser) {
  const wl = Math.max(1, num(winner.level, 1)), ll = Math.max(1, num(loser.level, 1));
  const farm = wl > ll * rules.limitWinRatio;
  const winnerGain = Math.round((farm ? rules.loseRatio : rules.winRatio) * rules.basePoints);
  const loserLoss = Math.min(Math.max(0, num(loser.points)), Math.round(rules.lossRatio * rules.basePoints));
  return { winnerGain, loserLoss, limited: farm };
}

/** The list of ENGINE-CHOSEN keys and values (for evidence / UI). */
export function engineChosenList() { return Object.entries(ENGINE_CHOSEN).map(([k, v]) => `${k}=${typeof v === 'string' ? JSON.stringify(v) : v}`); }

// ---------------------------------------------------------------------------------------------------- PARTY-PVP
// Party Match (share/article/partypvp.csv + game2/partypvp windows). The csv defines the modes, arenas, WaitTime,
// TimeLimit, EntryLimit and the Entry Fee range; the battle window offers Time Limit of Battle 280:60-62 (15 / 30 / 60
// minutes). What the data leaves open is chosen here, tagged the same way as ENGINE_CHOSEN above.
export const PARTY_PVP_CHOSEN = Object.freeze({
  /** ENGINE-CHOSEN (not in Global data): the requesting party is BLUE TEAM (280:22) and starts at Start_0, the
   *  challenged party is RED TEAM (280:23) at Start_1 (the csv's four start points are unlabeled; 2 and 3 unused). */
  teamStarts: 'BLUE = requester at Start_0, RED = challenged party at Start_1',
  /** ENGINE-CHOSEN (not in Global data): partypvp.csv EntryLimit caps the participants of both parties together. */
  entryLimitReading: 'both parties together',
  /** ENGINE-CHOSEN (not in Global data): the Entry Fee (280:32, EntryPointType 0 = DIL) is paid by every participant. */
  feeReading: 'every participant pays the fee when the match starts',
  /** ENGINE-CHOSEN (not in Global data): Prize Money (280:27) = every fee paid, split evenly (floor) among the winning
   *  team's participants still in the arena, the remainder to its leader; a DRAW (280:80) refunds every fee. */
  prizeReading: 'all fees split evenly among the winners, remainder to their leader; DRAW refunds',
  /** ENGINE-CHOSEN (not in Global data): Total Points (280:24) / lbl_score = this many points per enemy downed. */
  pointsPerKill: 10,
  /** ENGINE-CHOSEN (not in Global data): when the Time Limit of Battle runs out, more Survived (280:25) wins, then more
   *  Total Points, otherwise DRAW. */
  timeDecision: 'more survivors, then more Total Points, else DRAW',
  /** ENGINE-CHOSEN (not in Global data): in the Annihilation battle a downed participant stays down until the end. */
  downedRule: 'Annihilation stays down; Buff Mode permits skill resurrection and reapplies selected buffs (1008:40)',
  buffAlternatives: 'one selection per BaseStatusIndex (engine chosen; current Global rows have unique bases)',
  observerEntry: 'native observer confirmation via /observeparty near requesting leader location; Start_2 seats observers (engine chosen affordance/seat)',
  /** ENGINE-CHOSEN (not in Global data): seconds of "Waiting to finish" (280:51) after the result before transfer out. */
  finishWaitSec: 10,
  /** ENGINE-CHOSEN (not in Global data): everybody leaves the arena at the spot where the requesting leader stood when
   *  the request was accepted, revived with formula.ini byReviveHPRatio / byReviveMPRatio. */
  exitPoint: 'requesting leader spot at accept, revived by byRevive*Ratio',
  /** Native partypvp.csv modes with executable rules: Annihilation and Buff Mode (1008:40). */
  offeredModes: '0 (Annihilation battle), 4 (Buff Mode)',
  /** ENGINE-CHOSEN (not in Global data): arenas offered on this field server: the csv rows on maps below 200 (56/57/58);
   *  maps 240-242 are the 'DK' copies of the same arenas for the DK server channel. */
  offeredMaps: 'csv rows with MapIndex < 200',
});

/** share/article/partypvp.csv -> rows. mapNames: index -> name (gmcommands_lists maps), optional. */
export function parsePartyPvpCsv(text, mapNames = {}) {
  const lines = String(text).split(/\r?\n/).filter(l => l.trim());
  const head = lines.shift().split(',').map(s => s.trim());
  const col = name => { const lo = name.toLowerCase(), exact = head.findIndex(h => h.toLowerCase() === lo), i = exact >= 0 ? exact : head.findIndex(h => h.toLowerCase().startsWith(lo + '(')); if (i < 0) throw new Error(`partypvp.csv: ${name} is missing`); return i; };
  const at = { index: col('Index'), mode: col('Mode'), name: col('ModeName'), map: col('MapIndex'), img: col('MapImgIndex'), wait: col('WaitTime'),
    limit: col('TimeLimit'), entry: col('EntryLimit'), min: col('EntryPointMin'), max: col('EntryPointMax'), type: col('EntryPointType'), obs: col('ObserverSpeed') };
  return lines.map(l => {
    const c = l.split(',').map(s => s.trim()), n = i => Number(c[i]);
    const starts = [0, 1, 2, 3].map(k => ({ x: n(col(`Start_X_${k}`)) + 0.5, z: n(col(`Start_Y_${k}`)) + 0.5 }));
    return { index: n(at.index), mode: n(at.mode), modeName: c[at.name], map: n(at.map), mapName: mapNames[n(at.map)] || '', imgIndex: n(at.img), waitSec: n(at.wait), limitMin: n(at.limit),
      entryLimit: n(at.entry), feeMin: n(at.min), feeMax: n(at.max), feeType: n(at.type), observerSpeed: n(at.obs), starts };
  }).filter(r => Number.isFinite(r.index) && Number.isFinite(r.map));
}

/** Winner of a party match: 'blue' | 'red' | 'draw'. teams: {blue: {alive, points}, red: {alive, points}}. */
export function partyPvpOutcome({ blue, red }, reason) {
  if (reason !== 'time') { if (blue.alive > 0 && red.alive === 0) return 'blue'; if (red.alive > 0 && blue.alive === 0) return 'red'; if (!blue.alive && !red.alive) return 'draw'; }
  if (blue.alive !== red.alive) return blue.alive > red.alive ? 'blue' : 'red';
  if (blue.points !== red.points) return blue.points > red.points ? 'blue' : 'red';
  return 'draw';
}

/** Prize split: {pot, each, remainder}. */
export function partyPvpPrize(fee, participants, winners) {
  const pot = Math.max(0, Math.floor(fee)) * Math.max(0, participants);
  if (!winners) return { pot, each: 0, remainder: pot };
  const each = Math.floor(pot / winners);
  return { pot, each, remainder: pot - each * winners };
}

export function partyPvpChosenList() { return Object.entries(PARTY_PVP_CHOSEN).map(([k, v]) => `${k}=${typeof v === 'string' ? JSON.stringify(v) : v}`); }
// ---------------------------------------------------------------------------------------------------- PARTY-WAR
// Party War (Dead Front / Ice Castle, share/partywar). config.csv gives every phase time (LimitStarDelay 180,
// LimitStarTime 1800, LimitPvPDelay 30, LimitPvPTime 240, LimitExtensionDelay 10, LimitExtension 60, LimitEndDelay 300),
// field.csv the team starts (StartPoint1..4), the final-battle points (PvPPoint1..4), the winner / loser / end respawns,
// RecordEnableCount (maxParties) and WinRPoint, result.csv the objective kill points, PvPPoint_1..4 and the
// win / lost EXP and R-point columns. The rules between those numbers are not in the data and are chosen here.
export const PARTY_WAR_CHOSEN = Object.freeze({
  /** ENGINE-CHOSEN (not in Global data): parties that enter a war map at its officer while a war of that map opened by a
   *  party waits to start (waitStart) join it, in arrival order, until RecordEnableCount (field maxParties) teams; a later party opens
   *  a new war. A solo entrant (no party) keeps its own run. The original registration / selection rule (#100|105
   *  selected, #100|106 not selected) is not shipped. */
  troopSelection: 'first parties to arrive during waitStart fill the teams; a later party opens a new war; solo entrants run alone',
  /** ENGINE-CHOSEN (not in Global data): the k-th team uses StartPoint k, Dead Front lane A-D / Ice Castle corner k,
   *  PvPPoint k and the team colour k of the strings (Purple, Orange, Yellow, Blue). */
  teamSlots: 'team k = StartPoint k = lane / corner k = PvPPoint k = colour k',
  /** ENGINE-CHOSEN (not in Global data): retained Ice Castle hostile phases. Dead Front has its separate
   *  publisher-backed final-battle-only gate below; contested supply depots do not establish player damage. */
  hostilePhases: Object.freeze(['fortress', 'pvp', 'extension']),
  /** ENGINE-CHOSEN (not in Global data): objective points (result.csv kill points) go to the team of the player who
   *  earned them: the depot occupier, the last hitter of the monster or brick. */
  pointsCredit: 'the team of the occupier / last hitter',
  /** ENGINE-CHOSEN (not in Global data): retained Ice Castle final timing; Dead Front requires final objective
   *  completion before its two-team PvP. Team placement and the single-team result remain reconstructed. */
  finalBattle: 'two or more teams: waitPvp at PvPPoint k, then pvp; Dead Front first requires its final boss; one team: uncontested result',
  /** ENGINE-CHOSEN (not in Global data): the final battle ends at once when only one team has a standing member; when
   *  LimitPvPTime runs out with two or more standing teams, waitExtension + extension run once. */
  extensionTrigger: 'two or more teams still standing when the pvp time ends',
  /** ENGINE-CHOSEN (not in Global data): place order = more standing members, then more points, then more player
   *  kills, then the earlier team. */
  placeOrder: 'standing members, then points, then kills, then team order',
  /** ENGINE-CHOSEN (not in Global data): result PvPPoint_k is added to the points of the team placed k-th; place 1
   *  wins (WinRPoint + winExp4PvP / winRPoint4PvP, winnerRespawn), the others lose (lost columns, loserRespawn). */
  placementPoints: 'PvPPoint_k to the k-th team; place 1 wins',
  /** ENGINE-CHOSEN (not in Global data): a player downed in the final battle stays down until the result, then is
   *  revived at the winner / loser respawn; a player kill gives no points (kills only break ties). */
  finalDowned: 'downed stay down until the result; player kills score no points',
});
/** Official Papaya instance guide and Japanese publisher play guide: final boss, then party PvP.
 *  These phase gates do not claim an undisclosed Global damage/reward equation. */
export const DEAD_FRONT_PARTY_RULES=Object.freeze({hostilePhases:Object.freeze(['pvp','extension']),finalRequiresObjective:true});
export function partyWarHostilePhase(kind,phase){return (kind==='deadFront'?DEAD_FRONT_PARTY_RULES.hostilePhases:PARTY_WAR_CHOSEN.hostilePhases).includes(phase);}
/** Final-battle places: teams [{index, standing, score, kills}] -> the same objects in place order (PARTY_WAR_CHOSEN.placeOrder). */
export function partyWarPlaces(teams) {
  return [...teams].sort((a, b) => (b.standing - a.standing) || (b.score - a.score) || ((b.kills || 0) - (a.kills || 0)) || (a.index - b.index));
}
export function partyWarChosenList() { return Object.entries(PARTY_WAR_CHOSEN).map(([k, v]) => `${k}=${typeof v === 'string' ? JSON.stringify(v) : JSON.stringify(v)}`); }
