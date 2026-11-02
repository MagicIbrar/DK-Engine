// Zuto's Battlefield (map 650) and Zuto's Phantom Castle (653): portable battle rules from the original client files.
// On Global the factions are source servers (World_Index 1 / 2). This single-server engine has no source-world identity,
// so it uses a disclosed, owner-directed single-server adaptation:
// ZUTO_ADAPTATION below. The side is HOST-ASSIGNED and stored durably at registration; no client, profile or account
// field ever chooses it. Phantom Castle 653 is closed:
// Global data gives it no entrance, so lane 57 removed the engine-chosen Checkpoint 5913 entrance.
//
// AUTHENTICATED NATIVE SOURCES (data/unpacked/data; the Events lane hashed the same files against the Global packs):
//   share/urbanwarfare/respawn.csv    650: PCCount 100, levels 150-250, World_Index_Red 1 / Ally_Red 1 at 97,258 dir 255,
//                                     World_Index_Blue 2 / Ally_Blue 2 at 412,254 dir 87, result icons buffer 92 / 115, Range 5
//   share/urbanwarfare/takestone.csv  ConquestTime 15 s, Buff 50100 for 15 s (status 50100 "Seizing / Status Effect
//                                     Resistance Decrease", RATING_ANTI_STATUS_ADD -200)
//   share/urbanwarfare/wincondition.csv  FightTime 1800 s, ConquestMin/MaxWinCount 5, ConquestWinTime 60 s, Win 4000863 x50
//                                     (Z Coin), Lose 4000863 x5, Achieve 4002241 x1 (Awakened Zuto Weapon Ex-Box), Join 4002254
//                                     x1 (Zuto's Battlefield Supply Box), Attend 4002356 x1 (Mark of the battlefield),
//                                     LobbyIndex_Red/Blue 651, CastWorldIndex 1, DeathPoint 100, KillPoint 300, ConquestPoint
//                                     500, PointReward 0, WinPointRatio 0
//   share/urbanwarfare/time.csv       Day 2 and Day 6 at 23:40; script/contents_timetable.csv "Zuto's battlefield" week 3/7 0:00
//   share/map/650_urbanwarfare/npc_650_urbanwarfare.csv  stones 5906-5910 (job 119 index 0-4), exit Checkpoints 5914 (job 97)
//   script/ui/game2/dksquare/ui_urbanwarfarehelp.txt + texture/ui/game/dksquare/urbanwafarehelp.dds (436 x 610 help art):
//     win by collecting all stones; on time-out 1) most stones occupied 2) most kills 3) the faction that captured the last
//     stone 4) draw; equal result -> both get the loser reward; Victory 50 / Loser(equal) 5 Z Coins; achievement awards
//     "Arrow of battlefield, Lord of the Guardian Stone" -> 1 Awakened Zuto's Weapon Box; additional: Battle Supply item;
//     expelled when not resurrecting in time, or when staying at the army for more than 2 minutes; "100 vs 100 every Saturday"
//   script/string/map/stringtable_map_string_02.txt cate 650 (comments in EUC-KR): 1013 initialization "(30 minutes before)",
//     1014 entry possible "(10 minutes before)", 1015 battle start, 1018 start countdown (effectui 2031), 2000/2001 Helion /
//     Arc Server won, 10000-10008 entry refusals (10008 "Unable to enter while in a party."), 65000/65100 exits
//   script/string/normal/stringtable_dksquare.txt cate 160: 601-663 battlefield UI (603 "Your team conquered 5 Conquer
//     Stone.", 604 "The battle ends unless conquest situation does not change for __minutes.", 606-610 stone names, 614
//     "Slayer of the Battlefield", 615 "Ruler of the Guardian Stone", 620 "Attempting to conquer!", 621 "You succeeded to
//     conquer!", 622 "Conquering process of Guardian Stone has stopped.", 623 "Your team already conquered this Guardian
//     Stone.", 633 "There is no winning side in Zuto's Battlefield.", 636 "Moving to the saved place. You'll be exited in 1
//     minute if you don't revivie.", 637/638 ver.2019 "Miseria Won!" / "Riketz Won!"). 160:647-654 is the Draco Battleground
//     block (648/649/651 name it); its 653 "Only one character can enter per PC." is not a Zuto line (ZUTO_RULE_STATUS).
//   script/string/quest/stringtable_quest_6000.txt cate 6010 "[TEST] Server Check" (share/quest/quest_06010_loa_battlefield_test,
//     10000 "Test Menu for current server."): 11001 Helion, 11010 Arc, 60000 "Server
//     cannot be identified."; cate 6011 Phantom Castle Admission Ticket Issuance: 200,000 Dil, "must be used within 60 minutes",
//     500 "You already have more than one of the Admission Tickets."
//   share/item/itemetc.csv 4000861 "Zuto's Phantom Castle Ticket" ReqLv 170; stringtable_exchange 4000861 "Entrance Ticket that
//     allows Zuto's battle participants to enter Zuto's Phantom Castle as a reward." (Non-Tradeable)
//   share/dungeonlist.csv 653 SOLO, ExpireTime 30, KickType WORLDBY 651/652 at 272,62, Ticket 1
//   share/dkmaplist.csv 650 "DK Server" DK_Index 100 (respawn DEFAULT 256,246); 651/652 "Server 1" DK_Index 100
import {serverDate,serverTimestamp} from './server-time.js';
export const ZUTO = Object.freeze({
  battlefield: 650, lobbies: Object.freeze([651, 652]), phantom: 653,
  stoneJob: 119, stones: Object.freeze([5906, 5907, 5908, 5909, 5910]), exitNpc: 5914, exitJob: 97,
  phantomTicket: 4000861, phantomQuest: 6011,
  mapText: Object.freeze({ init: 1013, entry: 1014, start: 1015, countdown: 1018, redWon: 2000, blueWon: 2001, unavailable: 10000, initializing: 10001, full: 10002, level: 10003, partyStatus: 10004, inParty: 10008 }),
  ui: Object.freeze({ cate: 160, five: 603, holdWarning: 604, almost: 605, stoneName: 606, achieve: 611, slayer: 614, ruler: 615, attempting: 620, captured: 621, stopped: 622, own: 623, others: 624, neutral: 625, conquering: 634, draw: 633, reviveExit: 636 }),
  identity: Object.freeze({ cate: 6010, helion: 11001, arc: 11010, unknown: 60000 }),
});

// DELIBERATE ENGINE CHOICES used by the host controller (each is bounded and documented; none is presented as native).
export const ZUTO_ENGINE_CHOICES = Object.freeze([
  'Seizing requires standing within 3 cells of the stone NPC; leaving that range, dying or leaving the battle stops it (622). The original names the 15 s time and the seizer status, not the interruption predicate.',
  'A stone already held by the seizer\'s team refuses with 623; a stone being seized by another player refuses with 624 ("already been conquered by others" is read as "taken by another seizer").',
  'Base camping: a member counts as "at the army" within respawn.csv Range (5 cells) of its own Ally point.',
  'Rewards go to members still in the battle at the end (left or expelled members receive none). Item grants are one atomic profile save per member, recorded by battle id, retried while the member is online.',
  'The start countdown (1018, effectui 2031 5000 ms) is sent 5 s before the start.',
  'Capture completion follows its15-second deadline, independent of stone iteration order. Equal completion timestamps use the later server-accepted capture intent for the last-captor tie break; the original does not define simultaneous capture ordering.',
  'Schedule reading (not authenticated): time.csv 23:40 is the 1013 initialization at T-30, contents_timetable 0:00 the next day is the 1014 entry at T-10, so the battle starts at 00:10 and fights 1800 s. time.csv Day uses 0 = Sunday (Day 6 = Saturday, matching the help art); contents_timetable week 3/7 then reads 1 = Monday. Shared fixed server time UTC+1; the time-row phase interpretation remains ENGINE-CHOSEN (it is the only reading that puts both tables on the 1013 "30 minutes before" / 1014 "10 minutes before" instants, but no source names the phase of time.csv).',
  'ENGINE-CHOSEN achievement ties (the criteria are the literal reading recorded in ZUTO_RULE_STATUS): Achievement winners are the most kills and most captures respectively; one holder per title; an equal score goes to the member who reached that final score first, an equal instant to the earlier accepted kill / capture intent. Positive scores are required. Each title grants the native 4002241 x1.',
  'Faction banners, labels and full-team refusals use red Ricchez (160:644/638,650:10006) and blue Miseria (160:643/637,650:10005), matching their original effect IDs.',
  'OWNER-DIRECTED SINGLE-SERVER ADAPTATION (Global splits sides by home server World_Index 1 / 2; this engine has one server). See ZUTO_ADAPTATION.',
]);

// OWNER-DIRECTED ENGINE CHOICE: how one server stands in for two.
// Nothing here is a Global rule; every native value (capacity, timers, rewards, refusals) still comes from the tables.
export const ZUTO_ADAPTATION = Object.freeze({
  enabled: true,
  label: 'ENGINE CHOICE (owner-directed single-server adaptation; Global uses home servers World_Index 1 / 2)',
  rules: Object.freeze([
    'Registration: at native Ardeca Jerome (121), job31/65000, label150:65000 and prompt150:65100. It stands in for the Global server transfer and moves the character to its side\'s Zuto\'s Road lobby on the DK channel (red 651, blue 652: dungeonlist 653 WORLDBY KickToMap_0/_1 order; wincondition lists 651 for both and is preserved).',
    'The side is HOST-ASSIGNED and DURABLE: one atomic social-document transaction stores the season registry entry and the character\'s profile.zuto.registration together. Client, profile, account and channel fields are never read as a side.',
    'Guilds: every member of a guild gets the side the guild received at its first registration of the season (a guild belongs to one server on Global).',
    'Guildless characters, and a guild\'s first registrant, go to the side with fewer registered characters this season; equal counts go to red (World_Index 1, the lower index).',
    'No switching: a character keeps its registered side for the whole season even if it changes guild, and an active battle member keeps its battle side.',
    'Uniqueness: one registration per character per season. The registry row is authoritative; registering again is idempotent and rewrites a lost or edited profile half to the registered side. Characters of one account register independently (Global sides are per character server); no per-PC or per-account side or entry rule is added, and the session layer admits one live character per account.',
    'Season: one calendar month of fixed server time UTC+1. While a battle window [1013 initialization T-30, end) is open, the season is that of its initialization, so a battle crossing a month boundary neither invalidates nor resets its own registrations.',
    'Battlefield entry stays the native Checkpoint (Entrance) 5913 teleport 133 (100,000 DIL, Lv.185) and the native 100-per-side cap (10005/10006); arrival is the member\'s own respawn.csv Ally base (the help art\'s "army").',
    'Level band: the in-game map 650 row (170-250) plus the teleport 133 row (185); respawn.csv 150-250 is preserved as a table discrepancy.',
    'Members return to their saved place 60 s after the battle\'s rewards settle; a reconnect never resumes the DK battlefield (existing DK rule).',
  ]),
});

// DEPENDENCIES (not in the supplied data; never invented).
export const ZUTO_DEPENDENCIES = Object.freeze([
  'Trusted source-world identity (World_Index 1 = Helion / red, 2 = Arc / blue). The engine is one server; 6010:60000 "Server cannot be identified." is the original text for this condition. Replaced on this host only by the owner-directed ZUTO_ADAPTATION.',
  'Global per-PC / per-account Zuto entry rule: none in Zuto\'s own refusal set (650:10000-10008); 160:653 belongs to the Draco block and the host has no trusted machine identity.',
  'Phantom Castle 653 has no recovered original entry issuer. Global binds the quest6011 issuance dialogue (200,000 DIL, one-hour 4000862) to no NPC and no table issues 4000862 or the reward ticket 4000861, so the guessed issuer, price and daily quota were removed (lane 57). Global has no entrance to 653 either (no NPC job, warp, teleport or location targets it), so the engine-chosen Checkpoint5913 entrance was removed (lane 57 follow-up 3); all admission to 653 stays closed.',
  'Lobby routing: wincondition gives 651 for both sides while dungeonlist 653 exits to 651/652; level ranges conflict (respawn 150-250, map 170-250, teleport 133 level 185).',
  'Help art "every Saturday / 100 vs 100" versus time.csv Day 2 and Day 6.',
]);

// Native multi-world origin: REMOVED (lane 71: no Global, older-server or online source). The separately documented,
// owner-directed ZUTO_ADAPTATION uses one host's persisted balanced assignments;
// it does not claim to recover the missing authenticated source-world resolver.
export const ZUTO_FACTION_PROPOSAL = Object.freeze({
  enabled: false,
  label: 'REMOVED (no source): authenticated native source-world membership is unavailable, so this proposal stays disabled.',
  options: Object.freeze(['authenticated source-world membership supplied by the host account backend']),
});

// Rule status of the uniqueness / achievement / phase / point rules (owner rules: in-game value wins, an ambiguous value takes
// its literal reading, absent data gets one labelled ENGINE-CHOSEN default). Sources are the Global client files unless named
// otherwise; each ENGINE-CHOSEN row lists what was checked. Global client executables are packed and the 2011 server/DB
// archive predates Zuto, so neither can settle a rule. None of these rows claims proven Global server behaviour.
const CHECKED = 'share/urbanwarfare/{respawn,takestone,time,wincondition}.csv; strings 650:1-65101, 651/652, 160:601-669, 6010, 6011; script/ui/game2/dksquare/ui_urban{dashboard,noticeboard,statewnd,waiting,warfarehelp}.txt; help art urbanwafarehelp.dds; guide images gameguide_114/115 and tutorial_23/24 (no rule text); Rising strings 160 and 650-653 (corroboration only); packed client executables (unreadable); 2011 server binaries and DB DDL (predate Zuto, no Zuto procedure)';
export const ZUTO_RULE_STATUS = Object.freeze([
  { id: 'side-identity', status: 'ENGINE-CHOSEN', rule: 'Owner-directed ZUTO_ADAPTATION: host-assigned durable side per character (guild side, else fewer side, equal -> red).',
    sources: ['Native unit is the character\'s home server: respawn.csv World_Index_Red 1 / Blue 2; 6010 "[TEST] Server Check" reads the current server (11001 Helion / 11010 Arc / 60000); 650:2000/2001 and 160:631/632 "server won"; DB DDL FN_GetServerID/FN_GetServerName (world 1 -> 100 -> HELION) and per-guild guild_serv_id. One host has one server, so the native rule cannot apply.', CHECKED] },
  { id: 'entry-uniqueness', status: 'ENGINE-CHOSEN', rule: 'No per-PC or per-account Zuto refusal. The only account bound is the session layer: one live character per account; a re-join replaces the session and that character\'s battle membership ends as left.',
    sources: ['Zuto\'s own entry refusals 650:10000-10008 contain no per-PC or per-account line.', '160:653 "[message] Only one character can enter per PC." sits in the Draco Battleground block 160:647-654 (648/649/651 name Draco Battleground; Rising 653 reads "per personal computer"); the Zuto block 160:627-641 is commented "Zuto\'s Battlefield" and 653 is not. Other per-PC lines are mode-specific: OX 654:107, Monster Carnival 161:216, Dead Front/Ice Castle partywar strings, Colosseum, arena partywarui. No trusted machine identity exists on this host (same as OX).', CHECKED] },
  { id: 'duplicate-registration', status: 'ENGINE-CHOSEN', rule: 'One registration per character per season; registry row authoritative; re-registration idempotent, repairs a lost or edited profile half to the registered side; no switching by guild change or battle.',
    sources: ['Global has no registration step: a character\'s side is its fixed home server (see side-identity), which the no-switching rule mirrors.', CHECKED] },
  { id: 'season-boundary', status: 'ENGINE-CHOSEN', rule: 'Season = calendar month of fixed UTC+1; an open battle window [T-30, end) keeps the season of its 1013 initialization.',
    sources: ['No Zuto source has a season; time.csv Day 6 23:40 can fall on the last day of a month (31 Oct 2026), so the window anchor keeps one battle\'s registrations valid.', CHECKED] },
  { id: 'achievement-criteria', status: 'LITERAL READING', rule: 'Slayer of the Battlefield = most kills, Ruler of the Guardian Stone = most captures, at least one required; members of both sides are eligible; one 4002241 x1 per title held (one member holding both gets two).',
    sources: ['160:614 "Slayer of the Battlefield" / 615 "Ruler of the Guardian Stone" (Rising "Battlefield Slaughterer" / "Ruler of the Guardian Stone").', 'ui_urbannoticeboard.txt achievement rows carry exactly two counts: lbl_h_occupation 160:613 "Conquer" and lbl_h_kill 160:612 "Defeat" (Rising: "extermination", i.e. kills).', 'Help art lists the achievement awards apart from Victory/Loser rewards; wincondition AchieveRewardItemIndex 4002241, AchieveRewardItemCount 1.'] },
  { id: 'achievement-eligibility', status: 'ENGINE-CHOSEN', rule: 'Only members still in the battle at the end (not left, not expelled) can hold a title, the same eligibility as every Zuto reward.', sources: [CHECKED] },
  { id: 'achievement-ties', status: 'ENGINE-CHOSEN', rule: 'One holder per title. Equal scores: the member who reached that final score first; an equal instant: the earlier accepted kill / capture intent.',
    sources: ['Derived from the native time-out order\'s chronology step ("the last Guardian Stone is occupied", help art). No tie text, tie column or shared-award row exists.', CHECKED] },
  { id: 'phase', status: 'ENGINE-CHOSEN', rule: 'time.csv row = 1013 initialization (T-30), entry T-10, start T, FightTime 1800 s.',
    sources: ['time.csv Day 2/6 23:40; contents_timetable Zuto week 3/7 0:00 (Draco week 1/3/5 = playtime DAY 1/3/5); 650:1013 comment "initialization (30 minutes before)", 1014 "entry possible (10 minutes before)". Only this reading puts both tables on native instants; no source names the phase of time.csv.', CHECKED] },
  { id: 'server-clock', status: 'ENGINE-CHOSEN', rule: 'Fixed server time UTC+1 (owner-decided shared clock).', sources: ['Siege 100:10/11 "Central European Time (UTC+1)"; no Zuto source names a zone.'] },
  { id: 'point-conversion', status: 'LITERAL READING', rule: 'PointReward 0 and WinPointRatio 0 convert battle points to no reward and no winner ratio; DeathPoint/KillPoint/ConquestPoint stay inert and no window shows points. zutoConfig refuses a non-zero PointReward or WinPointRatio instead of inventing a conversion.',
    sources: ['wincondition.csv PointReward 0, WinPointRatio 0, DeathPoint 100, KillPoint 300, ConquestPoint 500 (Rising, both copies: the same 0/0); no other share table has these columns.', 'ui_urbandashboard / ui_urbanstatewnd / ui_urbannoticeboard show kill, stone and capture counts only.'] },
]);

const num = (v, d = 0) => { const n = Number(v); return Number.isFinite(n) ? n : d; };
const first = (rows, map) => (rows || []).find(r => num(r.MapIndex) === map) || null;

/** Native battlefield configuration for map 650, or null when a table row is missing. */
export function zutoConfig(mode) {
  const R = first(mode?.respawn, ZUTO.battlefield), T = first(mode?.takeStone, ZUTO.battlefield), W = first(mode?.winCondition, ZUTO.battlefield);
  if (!R || !T || !W) return null;
  const side = c => ({ world: num(R[`World_Index_${c}`]), ally: num(R[`Ally_${c}`]), base: { x: num(R[`Ally_X_${c}`]) + .5, z: num(R[`Ally_Y_${c}`]) + .5, dirDeg: num(R[`Ally_Dir_${c}`]) }, icon: [R[`Result_Icon_Name_${c}`], num(R[`Result_Icon_Index_${c}`])], lobby: num(W[`LobbyIndex_${c}`]) });
  const item = k => [num(W[`${k}RewardItemIndex`]), num(W[`${k}RewardItemCount`])];
  const cfg = {
    map: ZUTO.battlefield, capacity: num(R.PCCount), levels: [num(R.Min_Level), num(R.Max_Level)], range: num(R.Range),
    sides: { red: side('Red'), blue: side('Blue') },
    captureMs: num(T['ConquestTime(Sec)']) * 1000, seizeStatus: num(T.Buff), seizeStatusMs: num(T['BuffTime(Sec)']) * 1000,
    fightMs: num(W['FightTime(Sec)']) * 1000, winCount: num(W.ConquestMinWinCount), maxWinCount: num(W.ConquestMaxWinCount), holdMs: num(W['ConquestWinTime(Sec)']) * 1000,
    // Literal reading (ZUTO_RULE_STATUS point-conversion): PointReward 0 / WinPointRatio 0 convert points to nothing.
    points: { death: num(W.DeathPoint), kill: num(W.KillPoint), conquest: num(W.ConquestPoint), reward: num(W.PointReward, NaN), winRatio: num(W.WinPointRatio, NaN), inert: true },
    rewards: { win: item('Win'), lose: item('Lose'), achieve: item('Achieve'), join: item('Join'), attend: item('Attend') },
    castWorld: num(W.CastWorldIndex), schedule: (mode.time || []).filter(r => num(r.MapIndex) === ZUTO.battlefield).map(r => ({ day: num(r.Day), hour: num(r.Hour), min: num(r.Min) })),
  };
  const valid = cfg.capacity > 0 && cfg.captureMs > 0 && cfg.fightMs > 0 && cfg.holdMs > 0 && cfg.winCount > 0 && cfg.sides.red.world > 0 && cfg.sides.blue.world > 0 && cfg.sides.red.world !== cfg.sides.blue.world
    && cfg.levels[0]>0&&cfg.levels[1]>=cfg.levels[0]&&cfg.range>0&&cfg.maxWinCount>=cfg.winCount&&cfg.maxWinCount<=ZUTO.stones.length
    && cfg.points.reward === 0 && cfg.points.winRatio === 0   // a non-zero value would need an unrecovered conversion: fail closed
    && Object.values(cfg.rewards).every(([i, c]) => Number.isInteger(i)&&i > 0&&Number.isInteger(c)&&c > 0);
  return valid ? cfg : null;
}

/** The five guardian stones from the original placements: [{npc, index, x, z}] by job 119 index. */
export function zutoStones(rows, npcs) {
  const out = [];
  for (const id of ZUTO.stones) {
    const job = npcs?.[id]?.jobs?.find(([t]) => num(t) === ZUTO.stoneJob), row = (rows || []).find(r => num(r[0]) === id);
    if (!job || !row) return null;
    out.push({ npc: id, index: num(job[1]), x: num(row[1]), z: num(row[2]) });
  }
  return out.every(s=>Number.isFinite(s.x)&&Number.isFinite(s.z)&&Number.isInteger(s.index)&&s.index>=0&&s.index<5)
    &&new Set(out.map(s=>s.index)).size===5?out.sort((a, b) => a.index - b.index):null;
}

/** 'red' | 'blue' for an origin world index (World_Index_Red / World_Index_Blue), else null. */
export function zutoSideOfWorld(cfg, worldIndex) {
  if(!cfg?.sides?.red||!cfg?.sides?.blue)return null;
  const w = num(worldIndex, NaN);
  return w === cfg.sides.red.world ? 'red' : w === cfg.sides.blue.world ? 'blue' : null;
}

/** A side holding at least ConquestMinWinCount stones, or null. */
export function zutoHoldingSide(cfg, owners) {
  for (const side of ['red', 'blue']) if (owners.filter(o => o === side).length >= cfg.winCount) return side;
  return null;
}

/** Time-out result by the original help art order: stones held, kills, last stone captor, draw. */
export function zutoTimeoutOutcome({ owners, kills, lastCaptor }) {
  const stones = s => owners.filter(o => o === s).length;
  if (stones('red') !== stones('blue')) return { winner: stones('red') > stones('blue') ? 'red' : 'blue', reason: 'stones' };
  if ((kills.red || 0) !== (kills.blue || 0)) return { winner: kills.red > kills.blue ? 'red' : 'blue', reason: 'kills' };
  if (lastCaptor === 'red' || lastCaptor === 'blue') return { winner: lastCaptor, reason: 'lastCaptor' };
  return { winner: null, reason: 'draw' };
}

/** Reward rows for one member: win, or the loser reward for a loss/draw ("If the result is equal, both ... loser's rewards"), plus join and attend. */
export function zutoRewardRows(cfg, outcome, side) {
  const result = outcome.winner && outcome.winner === side ? ['win', cfg.rewards.win] : ['lose', cfg.rewards.lose];
  return [result, ['join', cfg.rewards.join], ['attend', cfg.rewards.attend]].map(([kind, [item, count]]) => ({ kind, item, count }));
}

/** Phase of a scheduled start T: 'init' from T-30 min (1013), 'entry' from T-10 min (1014), 'battle' for FightTime, then 'end'. */
export function zutoPhaseAt(cfg, now, startAt) {
  if (now < startAt - 30 * 60000) return 'idle';
  if (now < startAt - 10 * 60000) return 'init';
  if (now < startAt) return 'entry';
  if (now < startAt + cfg.fightMs) return 'battle';
  return 'end';
}

// ------------------------------------------------------------------ owner-directed single-server adaptation (ENGINE CHOICE)
export const ZUTO_SIDES = Object.freeze(['red', 'blue']);
/** Registration season: one calendar month of fixed server time UTC+1 ('YYYY-MM'). */
export function zutoSeason(now) {
  const d = serverDate(now);
  return `${d.getUTCFullYear()}-${String(d.getUTCMonth() + 1).padStart(2, '0')}`;
}
/** The registration season at `now`: while `battle`'s window [1013 initialization T-30, end) is open, its initialization's season. */
export function zutoSeasonAt(now, battle = null) {
  const init = Number(battle?.startAt) - 30 * 60000, end = Number(battle?.endAt);
  return zutoSeason(battle && battle.phase !== 'closed' && Number.isFinite(init) && Number.isFinite(end) && now >= init && now < end ? init : now);
}
/** Registered characters per side in a season registry {season, members:{ref:{side}}, guilds:{id:side}}. */
export function zutoSideCounts(registry) {
  const out = { red: 0, blue: 0 };
  for (const row of Object.values(registry?.members || {})) if (ZUTO_SIDES.includes(row?.side)) out[row.side]++;
  return out;
}
/**
 * The host-assigned side for a registering character (ZUTO_ADAPTATION). Inputs are host state only: the season registry,
 * the character's social reference, its durable guild id (or null) and its side in a running battle (or null).
 * @returns {{side:'red'|'blue', reason:string}}
 */
export function zutoAssignSide({ registry, ref, guildId = null, battleSide = null }) {
  const own = registry?.members?.[ref]?.side;
  if (ZUTO_SIDES.includes(own)) return { side: own, reason: 'registered' };
  if (ZUTO_SIDES.includes(battleSide)) return { side: battleSide, reason: 'battle' };
  const guildSide = guildId != null ? registry?.guilds?.[guildId] : null;
  if (ZUTO_SIDES.includes(guildSide)) return { side: guildSide, reason: 'guild' };
  const n = zutoSideCounts(registry);
  return { side: n.red <= n.blue ? 'red' : 'blue', reason: guildId != null ? 'guild-first' : 'balance' };
}
/** Side lobby: red -> 651, blue -> 652 (dungeonlist 653 WORLDBY KickToMap_0 / KickToMap_1). */
export const zutoLobbyOf = side => side === 'blue' ? 652 : 651;
/**
 * The scheduled battle whose window [init, start + FightTime) contains `now`, from time.csv rows {day, hour, min}
 * (Day 0 = Sunday; the row time is the 1013 initialization at T-30), in fixed server time UTC+1. null outside every window.
 */
export function zutoScheduledStart(cfg, now) {
  if (!cfg?.schedule?.length || !(cfg.fightMs > 0)) return null;
  const today = serverDate(now);
  let best = null;
  for (let shift = -2; shift <= 1; shift++) {
    const d = new Date(Date.UTC(today.getUTCFullYear(), today.getUTCMonth(), today.getUTCDate() + shift));
    for (const row of cfg.schedule) {
      if (d.getUTCDay() !== row.day || !Number.isInteger(row.hour) || !Number.isInteger(row.min)) continue;
      const init = serverTimestamp(d.getUTCFullYear(), d.getUTCMonth(), d.getUTCDate(), row.hour, row.min), startAt = init + 30 * 60000;
      if (now >= init && now < startAt + cfg.fightMs && (!best || startAt > best)) best = startAt;
    }
  }
  return best;
}
