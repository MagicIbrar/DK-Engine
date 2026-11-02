// PvP rules (PvP foundation). ONE place for every player-vs-player value.
//
// Global data used (an untouched Global client install was compared: its data is byte-identical to this copy):
//   share/formula.ini   fPCDamageRatio 1.0, fPCDefenseRatio 1.0, byPKBlockRate 90, byPKGuardRate 50,
//                       dwWinPVPPointRatio 2, dwLosePVPPointRatio 1, dwLossPVPPointRatio 2, fLimitWinPVPRatio 1.2,
//                       dwPVPReviveTick 1, byReviveHPRatio 100, byReviveMPRatio 100,
//                       dwNonPKTime 30000, dwSeigeNonPKTime 20000, dwArenaNonPKTime 10000, dwUrbanWarfareNonPKTime 20000,
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
// Lane 51 g: every value carries SOURCE / ONLINE (labelled) or JUDGMENT (no source; reasoning given, listed in LANE-51-REPORT.md).
// The owner can change any of them here; the host (server/world/pvp.mjs) and the tests read only this module.

import {normalizeOptionName} from '../systems/items/option-identities.js';
import {penetratedDefense,blockChance as masteryBlockChance,guardChance as masteryGuardChance,combatOptionValue,combatOptionCapped,GLOBAL_STAT_MAX} from './combat.js';

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
  /** JUDGMENT (lane 51 g; no reading in Global data, the FINAL decompiles, the older server reference or the guides):
   *  PC_*_DAMAGERATE is the percent by which a hit on a player is reduced, looked up for the ATTACKER's class and the hit's
   *  kind (melee/range = physical, magic = magical). Reasoning: pcclass.csv keys the rows per class and splits them by
   *  the same physical / magical kind the attacker's attack type carries. */
  classRateOwner: 'attacker',
  /** JUDGMENT (lane 51 g; no source gives the order): the PvE order (adds, ratio, defence) first, then the PvP-only
   *  stages, shield last (tooltip 23:37: the shield takes PvP damage first, before HP). */
  pipeline: 'flat adds -> fPCDamageRatio x rate adds -> defence (x fPCDefenseRatio) -> class rate -> tolerance -> PC resist -> block/guard -> shield',
  /** JUDGMENT (lane 51 g; the formula is in no source): how the PvP option codes combine. The data names the codes ("PvP Attack +10%",
   *  "PK Damage Resistance Increase") and their values but not the formula: PVPDAMAGE_PVP_DAMAGE_MUL joins the percent adds of
   *  stage 2 (summed with PVPDAMAGE_PVP_DAMAGERATE_ADD and PC_DAMAGE_DAMAGE_MUL); PC_DAMAGE_ARMOR_MUL (and, for physical hits,
   *  PC_DAMAGE_ALLPHYSICSRESIST_MUL) is a percent on the defender's PvP defence points. Status and passive / mastery options
   *  are summed with the item options. Values of the mastery tables are read as written in the data. */
  pvpOptionReading: 'PVP_DAMAGE_MUL joins the percent adds; PC_DAMAGE_ARMOR_MUL / ALLPHYSICSRESIST_MUL scale the defence points',
  /** JUDGMENT (lane 51 g; reasoning: the same resist scale the skill engine uses for a player's element resist): PC_DAMAGE_ALLMAGICRESIST_* (magic hits) and PC_DAMAGE_<element>RESIST_* (the element of a
   *  skill hit) are resist points on the engine's resist scale (percent = points / 10, cap 75, the same as a player's element
   *  resist in the skill engine); the *_MUL code raises the points by that percent; the percent removes that share of the hit
   *  (the element part of an elemental skill hit, the whole hit for all-magic). */
  pcResistReading: 'resist points / 10 = percent (cap 75); *_MUL raises the points; applies to the element share / magic hits',
  /** JUDGMENT (lane 51 g; reasoning: one skill engine for PvE and PvP, the PvP stages added on top): a skill hit on a duel opponent keeps the skill engine's PvE result (its own
   *  defence, element and crit rules) as the raw amount, then runs the PvP stages with only the PvP defence adds. */
  skillReading: 'PvE skill result -> PvP stages (PvP defence adds only)',
  /** SOURCE (chance): older server reference Computer 0x586ff0 / 0x5870a0 (MATH-VERIFY 4.3.2 row 14). JUDGMENT (lane 51 g,
   *  amount): byPKBlockRate / byPKGuardRate are the percent of damage removed by a PvP block / guard (NOT PvE
   *  guardEfficiency), the only percent the formula.ini PK keys can mean. Chance = min(COMPETENCE_PVP_*_RATE_MAX, defender rate + map ability-cap
   *  Blocking/Guard columns) then mastery reduction (MATH-VERIFY 4.3.2 row 14 / Computer 0x586ff0 / 0x5870a0). */
  blockGuardReading: 'byPK*Rate = % damage removed; chance = min(COMPETENCE_PVP_*_RATE_MAX, rate + abilityCap.blocking|guard)',
  /** JUDGMENT (lane 51 g; no source gives a unit; a flat value is the plain reading of a column without a percent code): the item
   *  "PVP Option Damage/Defence" columns are flat damage / defence. */
  itemPvpColumns: 'flat',
  /** MATH-VERIFY 4.3.2 row 14: Global Calculator applies map ability caps to PC->PC (miss + damageMul + Blocking/Guard).
   *  Host: server/world/pvp.mjs pvpCap -> applyAbilityCap; pvpDamage consumes cap.blocking/guard for chance. */
  applyMapCaps: true,
  // --- 1:1 duel ---------------------------------------------------------------------------------------
  /** SOURCE: older server reference DekaronServer.exe GameProcess::State::Process::PVP::OnRequest 0x61fd20 ("Out of Range X/Y" -> result 0x5220003) and
   *  OnResponse 0x61f450 (0x61f7ae / 0x61f7bf): both players within +-0x1000 server units on EACH axis. Server positions are
   *  u16 in 1/128 cell (same scale as wDamageLinkRange 2560 = 20 cells, damage-share.js), so 0x1000 = 32 cells, a square box. */
  requestRange: 32,
  requestShape: 'box',
  /** SOURCE (lane 51 g, FINAL 64-bit decompile): PVPRequestWaitWnd update FUN_7ff670cfc9c0 closes the wait window (the same
   *  close as its Cancel button) once more than 9999 ms have passed, i.e. 10 s (guide 9: the request auto-cancels). */
  acceptTimeoutSec: 10,
  /** SOURCE (lane 51 g, FINAL 64-bit decompile): PVP State Ready init FUN_7ff6713330d0 sets a 5000 ms deadline and posts
   *  ShowCounterUI(1, 5000, ...); FUN_7ff671333220 sends CN_Start 0x5220008 when it passes (older server reference OnStart
   *  0x620c20 starts the fight on that packet). */
  countdownSec: 5,
  /** SOURCE: older server reference DekaronServer.exe PVP::OnCheckRange 0x61f170: a duellist counts as inside while within +-0x1000 server units (32 cells)
   *  of the PVP flag on EACH axis (square box; the flag stands at the midpoint of the two). */
  areaRadius: 32,
  areaShape: 'box',
  /** SOURCE: older server reference DekaronServer.exe OnCheckRange 0x61f339 (cmp edi, 0x2710): outside the area for 10000 ms -> Perform EndBattle 0x5d6dc0
   *  with the other duellist as winner. */
  outsideForfeitSec: 10,
  // Duel time limit REMOVED (f pass): no source; older server reference DekaronServer.exe has no duel timer (a duel ends only by OnEnd 0x620e60,
  // the area forfeit or OnCancel), so the host no longer ends a fight as a draw on time.
  // Points: SOURCE older server reference DekaronServer.exe PVP point routine 0x845c20 (formula struct offsets from the formula.ini parser):
  //   A = max(1, floor(dwWinPVPPointRatio x winner points / 100)); B = max(1, floor(dwLosePVPPointRatio x loser points / 100));
  //   winner +max(1, trunc((A + B) / fLimitWinPVPRatio)); loser -B (floored at 0). dwLossPVPPointRatio is not read there.
  //   basePoints / pointsReading REMOVED.
  /** SOURCE (lane 51 g, FINAL 64-bit decompile): DeadRestoreWnd FUN_7ff670cfcbb0 starts a 15000 ms wait (count label 15);
   *  FUN_7ff670cfcd00 / cf40 count the seconds down (40:125) and then enable the restore button. Replaces the former
   *  reviveTickUnit reading of dwPVPReviveTick (still parsed as reviveTick; no apply site reads it). */
  restoreWaitSec: 15,
  /** JUDGMENT (lane 51 g; no source gives the duel-start shield): the shield starts each duel full. Reasoning: maxShield is a
   *  PvP-only pool, so a match starting with a partial pool would carry state from an earlier fight. */
  shieldAtStart: 'full',
  /** SOURCE (lane 51 g, FINAL 64-bit decompile): PVPBattleWnd update FUN_7ff670cfb450 closes the result window after 5000 ms. */
  resultShowSec: 5,
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
    // Safe Time / NonPK windows (formula.ini). stringtable_pc 1003:10 states field Safe Time is 30 seconds;
    // dwNonPKTime=30000. Mode-specific keys authored the same way for siege/arena/urban warfare.
    nonPkTimeMs: need('dwNonPKTime', f('dwNonPKTime')),
    siegeNonPkTimeMs: need('dwSeigeNonPKTime', f('dwSeigeNonPKTime')),
    arenaNonPkTimeMs: need('dwArenaNonPKTime', f('dwArenaNonPKTime')),
    urbanWarfareNonPkTimeMs: need('dwUrbanWarfareNonPKTime', f('dwUrbanWarfareNonPKTime')),
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
export function pvpDamage(rules, { attacker, defender, raw, kind = 'melee', random = Math.random, defenceApplied = false, element = null, elementShare = 1, cap = null }) {
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
  // Caps: Global share/pc/statmaxvalue.csv - rows 176/177 melee/ranged resist equip 75 / skill 75, row 63 damage
  // reduction equip 75 / skill 90, each part capped on its own (scan-fix 2026-10-29; was a single unlabelled 90).
  const capped = code => combatOptionCapped(defender, code, ...GLOBAL_STAT_MAX[code]);
  if (kind === 'melee') dmg *= Math.max(0, 1 - capped('RESIST_DISTANCE_MELEEDAMAGE') / 100);
  if (kind === 'range') dmg *= Math.max(0, 1 - capped('RESIST_DISTANCE_RANGEDAMAGE') / 100);
  dmg *= Math.max(0, 1 - capped('DAMAGERATE_DAMAGEHP_MUL') / 100);
  // 5b. PvP-only resists of the defender (PC_DAMAGE_*RESIST_*): all-magic on magic hits, the element on an elemental skill hit
  const share = Math.min(1, Math.max(0, num(elementShare, 1))), el = PC_RESIST_ELEMENT[element];
  const resistCut = (code, part) => { const pts = opt(d, `${code}_ADD`) * (1 + opt(d, `${code}_MUL`) / 100); return pts > 0 ? part * Math.min(75, pts / 10) / 100 : 0; };
  const cut = (kind === 'magic' ? resistCut('PC_DAMAGE_ALLMAGICRESIST', 1) : 0) + (el ? resistCut(`PC_DAMAGE_${el}RESIST`, share) : 0);
  if (cut > 0) dmg *= Math.max(0, 1 - cut);
  // 6. PvP block / guard (MATH-VERIFY row 14: ability-cap Blocking/Guard columns add to chance; byPK*Rate = % removed)
  const dc = Math.max(0, Math.round(num(defender.classIndex)));
  const blockRate = Math.max(0, num(d.blockRate) + (Number(cap?.blocking) || 0));
  const guardRate = Math.max(0, num(d.guardRate, rules.guardRate[dc]) + (Number(cap?.guard) || 0));
  const blockChance = masteryBlockChance(attacker,defender,Math.min(num(rules.blockCap[dc], 0), blockRate),{pvp:true});
  const guardChance = masteryGuardChance(attacker,defender,Math.min(num(rules.guardCap[dc], 0), guardRate),{pvp:true});
  let block = false, guard = false;
  if (random() * 100 < blockChance) { block = true; dmg *= 1 - rules.pkBlockRate / 100; }
  else if (random() * 100 < guardChance) { guard = true; dmg *= 1 - rules.pkGuardRate / 100; }
  let total = Math.max(0, Math.round(dmg));   // engine minimum-damage floor removed (f pass: no source)
  // Share damage only when the host supplies an actual living owned servant.
  // This follows the existing solo ordering (share before the PvP shield).
  // The pure rule reports the transfer; only the host mutates servant HP.
  // ENGINE-DEFAULT (configurable): DAMAGE_OWNERSHIP cap 90 - statmaxvalue.csv has no row for this option, so Global sets no cap.
  const sharedDamage = defender.ownedServant ? Math.round(total * Math.max(0, Math.min(90, combatOptionValue(defender, 'DAMAGE_OWNERSHIP'))) / 100) : 0;
  total -= sharedDamage;
  // 7. shield first (tooltip 23:37), then HP
  const shield = Math.max(0, num(defender.shield));
  // SHIELD_TARGET_DAMAGE_ADD ("Additional Shield Damage", Rapid Fire and others): the attacker's status takes that many extra points off
  // a standing shield. JUDGMENT (lane 51 g) reading of the status text: the HP damage stays exactly what the shield did not absorb.
  const absorbed = Math.min(shield, total);
  const shieldDamage = shield > 0 ? Math.min(shield, total + Math.max(0, combatOptionValue(attacker, 'SHIELD_TARGET_DAMAGE_ADD'))) : 0;
  return { amount: total - absorbed, shieldDamage, block, guard, ...(sharedDamage ? {sharedDamage} : {}), detail: { rate, defense: Math.round(defense), blockChance, guardChance } };
}

/** Points after a decided duel ({winnerGain, loserLoss}). SOURCE: older server reference DekaronServer.exe 0x845c20 (see ENGINE_CHOSEN notes). */
export function duelPoints(rules, winner, loser) {
  const wp = Math.max(0, num(winner.points)), lp = Math.max(0, num(loser.points));
  const a = Math.max(1, Math.floor(rules.winRatio * wp / 100));
  const b = Math.max(1, Math.floor(rules.loseRatio * lp / 100));
  const winnerGain = Math.max(1, Math.trunc((a + b) / rules.limitWinRatio));
  const loserLoss = Math.min(lp, b);
  return { winnerGain, loserLoss, limited: false };
}

/** Per-axis (square) range test used by the server reference (|dx| and |dz| each within r cells). */
export function withinBox(a, b, r) { return Math.abs(a.x - b.x) <= r && Math.abs(a.z - b.z) <= r; }

/** The list of ENGINE_CHOSEN keys and values (SOURCE / JUDGMENT labelled above; for evidence / UI). */
export function engineChosenList() { return Object.entries(ENGINE_CHOSEN).map(([k, v]) => `${k}=${typeof v === 'string' ? JSON.stringify(v) : v}`); }

// ---------------------------------------------------------------------------------------------------- PARTY-PVP
// Party Match (share/article/partypvp.csv + game2/partypvp windows). The csv defines the modes, arenas, WaitTime,
// TimeLimit, EntryLimit and the Entry Fee range; the battle window offers Time Limit of Battle 280:60-62 (15 / 30 / 60
// minutes). What the data leaves open is chosen here, tagged the same way as ENGINE_CHOSEN above.
export const PARTY_PVP_CHOSEN = Object.freeze({
  /** JUDGMENT (lane 51 g; no rule in Global data, the decompiles, the server reference or the guides): the requesting party is BLUE TEAM (280:22) and starts at Start_0, the
   *  challenged party is RED TEAM (280:23) at Start_1 (the csv's four start points are unlabeled; 2 and 3 unused). */
  teamStarts: 'BLUE = requester at Start_0, RED = challenged party at Start_1',
  /** JUDGMENT (lane 51 g; no rule in Global data, the decompiles, the server reference or the guides): partypvp.csv EntryLimit caps the participants of both parties together. */
  entryLimitReading: 'both parties together',
  /** JUDGMENT (lane 51 g; no rule in Global data, the decompiles, the server reference or the guides): the Entry Fee (280:32, EntryPointType 0 = DIL) is paid by every participant. */
  feeReading: 'every participant pays the fee when the match starts',
  /** JUDGMENT (lane 51 g; no rule in Global data, the decompiles, the server reference or the guides): Prize Money (280:27) = every fee paid, split evenly (floor) among the winning
   *  team's participants still in the arena, the remainder to its leader; a DRAW (280:80) refunds every fee. */
  prizeReading: 'all fees split evenly among the winners, remainder to their leader; DRAW refunds',
  /** JUDGMENT (lane 51 g; no rule in Global data, the decompiles, the server reference or the guides): Total Points (280:24) / lbl_score = this many points per enemy downed. */
  pointsPerKill: 10,
  /** JUDGMENT (lane 51 g; no rule in Global data, the decompiles, the server reference or the guides): when the Time Limit of Battle runs out, more Survived (280:25) wins, then more
   *  Total Points, otherwise DRAW. */
  timeDecision: 'more survivors, then more Total Points, else DRAW',
  /** JUDGMENT (lane 51 g; no rule in Global data, the decompiles, the server reference or the guides): in the Annihilation battle a downed participant stays down until the end. */
  downedRule: 'Annihilation stays down; Buff Mode permits skill resurrection and reapplies selected buffs (1008:40)',
  buffAlternatives: 'one selection per BaseStatusIndex (JUDGMENT; current Global rows have unique bases)',
  observerEntry: 'native observer confirmation via /observeparty near requesting leader location; Start_2 seats observers (JUDGMENT affordance/seat)',
  /** REMOVED (lane 47; closed lane 51 g): finishWaitSec. Global partypvp.csv has only WaitTime(SEC) and TimeLimit(MIN), no
   *  "Waiting to finish" (280:51) duration, so the host transfers everyone out as soon as the result is decided. */
  /** JUDGMENT (lane 51 g; no rule in Global data, the decompiles, the server reference or the guides): everybody leaves the arena at the spot where the requesting leader stood when
   *  the request was accepted, revived with formula.ini byReviveHPRatio / byReviveMPRatio. */
  exitPoint: 'requesting leader spot at accept, revived by byRevive*Ratio',
  /** Native partypvp.csv modes with executable rules: Annihilation and Buff Mode (1008:40). */
  offeredModes: '0 (Annihilation battle), 4 (Buff Mode)',
  /** JUDGMENT (lane 51 g; no rule in Global data, the decompiles, the server reference or the guides): arenas offered on this field server: the csv rows on maps below 200 (56/57/58);
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
  /** JUDGMENT (lane 51 g; no rule in Global data, the decompiles, the server reference or the guides): parties that enter a war map at its officer while a war of that map opened by a
   *  party waits to start (waitStart) join it, in arrival order, until RecordEnableCount (field maxParties) teams; a later party opens
   *  a new war. A solo entrant (no party) keeps its own run. The original registration / selection rule (#100|105
   *  selected, #100|106 not selected) is not shipped. */
  troopSelection: 'first parties to arrive during waitStart fill the teams; a later party opens a new war; solo entrants run alone',
  /** JUDGMENT (lane 51 g; no rule in Global data, the decompiles, the server reference or the guides): the k-th team uses StartPoint k, Dead Front lane A-D / Ice Castle corner k,
   *  PvPPoint k and the team colour k of the strings (Purple, Orange, Yellow, Blue). */
  teamSlots: 'team k = StartPoint k = lane / corner k = PvPPoint k = colour k',
  /** JUDGMENT (lane 51 g; no rule in Global data, the decompiles, the server reference or the guides): retained Ice Castle hostile phases. Dead Front has its separate
   *  publisher-backed final-battle-only gate below; contested supply depots do not establish player damage. */
  hostilePhases: Object.freeze(['fortress', 'pvp', 'extension']),
  /** JUDGMENT (lane 51 g; no rule in Global data, the decompiles, the server reference or the guides): objective points (result.csv kill points) go to the team of the player who
   *  earned them: the depot occupier, the last hitter of the monster or brick. */
  pointsCredit: 'the team of the occupier / last hitter',
  /** JUDGMENT (lane 51 g; no rule in Global data, the decompiles, the server reference or the guides): retained Ice Castle final timing; Dead Front requires final objective
   *  completion before its two-team PvP. Team placement and the single-team result remain reconstructed. */
  finalBattle: 'two or more teams: waitPvp at PvPPoint k, then pvp; Dead Front first requires its final boss; one team: uncontested result',
  /** ONLINE (lane 51 g, official JP publisher Dead Front guide dk.brabragames.jp/guide no=1&pno=5): the party battle is won
   *  when every other party is down; undecided at the time limit = "draw" and a rematch (config.csv waitExtension +
   *  extension, run once: JUDGMENT, the data has one extension phase). */
  extensionTrigger: 'two or more teams still standing when the pvp time ends',
  /** JUDGMENT (lane 51 g; no rule in Global data, the decompiles, the server reference or the guides): place order = more standing members, then more points, then more player
   *  kills, then the earlier team. */
  placeOrder: 'standing members, then points, then kills, then team order',
  /** JUDGMENT (lane 51 g; no rule in Global data, the decompiles, the server reference or the guides): result PvPPoint_k is added to the points of the team placed k-th; place 1
   *  wins (WinRPoint + winExp4PvP / winRPoint4PvP, winnerRespawn), the others lose (lost columns, loserRespawn). */
  placementPoints: 'PvPPoint_k to the k-th team; place 1 wins',
  /** JUDGMENT (lane 51 g; no rule in Global data, the decompiles, the server reference or the guides): a player downed in the final battle stays down until the result, then is
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
