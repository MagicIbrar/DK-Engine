// ARENA rules (pure): share/arena/*.csv as parsed into gamedata/events.json modes.arena, the battlefield map rows and
// the original texts (stringtable_dksquare.txt cate 160 / 162). Gaps the data leaves open: src/config/engine-chosen-arena.js.
// Global parity: no scaling, multiplier or modifier is applied to any data value.
import { ARENA_CHOSEN as C } from '../../config/engine-chosen-arena.js';
import {serverDate,serverTimestamp} from '../../game/server-time.js';

export const ARENA_JOBS = Object.freeze({ draco: 130, lostHorizon: 111 });
export const SUNSTONE_JOB = 52;                       // npc 6054 Sunstone, role ARENA_CONQUEST
export const ARENA_SCRIPTS = Object.freeze({
  info: 'game2/dksquare/ui_battleinfownd_renew2.txt', icon: 'game2/dksquare/ui_conquesticon.txt',
  mission: 'game2/dksquare/ui_missionwnd.txt', points: 'game2/dksquare/ui_dksquareactivitypointwnd.txt',
  gauge: 'game2/dksquare/ui_circleprogresswnd.txt', horizon: 'game2/dksquare/ui_losthorizon.txt', board: 'game2/dksquare/ui_rankboardwnd.txt',
});
/** String codes (cate 160 unless noted) the windows read. */
export const ARENA_STRINGS = Object.freeze({
  infoTitle: [160, 100], rankCol: [160, 103], nameCol: [160, 104], jobCol: [160, 105], serverCol: [160, 106], levelCol: [160, 107],
  gradeCol: [160, 108], battleCol: [160, 109], missionCol: [160, 110], bonusCol: [160, 111], totalCol: [160, 112], mine: [160, 113],
  missionTitle: [160, 120], viewInfo: [160, 40], result: [160, 618], reward: [160, 652], winLose: [160, 639], kill: [160, 661], death: [160, 662],
  dpDelta: [160, 665], rankScore: [160, 666], apOk: [160, 667], apNo: [160, 668], tier: [160, 700], untilWin: [160, 602], conquering: [160, 634],
  neutral: [160, 625], moveOut: [160, 70], leaveNow: [160, 71], timeLeft: [161, 1],
  boardRank: [162, 1], boardName: [162, 2], boardClass: [162, 3], boardLevel: [162, 4], boardTier: [162, 5], boardDp: [162, 6],
});
export const TEAM_NAME_CODES = Object.freeze([643, 644, 645, 646]);     // Miseria / Ricchez / Rebel / Terra (160)
export const GRADE_NAME_CODES = Object.freeze([50, 51, 52, 53, 54, 55, 56]); // Newbie (1/7) .. Star (7/7) (160)
export const TEAM_COLOURS = Object.freeze(['blue', 'red', 'green', 'yellow']); // ui_battleinfownd_renew2 pan_top_<colour>_*
/** Original texts (cate 160 unless noted). */
export const ARENA_TEXT = Object.freeze({
  closed: 'Draco Desert Battlefield only opens during select hours.\nView the Content Timetable to see when the next battle begins.', // 160:133
  level: 'Your level is not eligible to enter.',                                    // 160:33
  full: 'Battlefield is full.',                                                     // 160:300
  penalty: '[message] Cannot join Draco Battleground while under War Fury.',        // 160:651
  busy: 'You are in some condition that prohibits you from\nentering the lobby. Please abort or finish your\ncurrent activity, and then try again.', // 160:84
  dead: 'Dead characters cannot enter the lobby.',                                  // 160:81
  already: 'You are already waiting in the lobby.\nPlease check the Lobby Waiting icon.', // 160:41
  cancelled: 'You have canceled entering the Battlefield.',                         // 160:49
  cannotLeave: 'You cannot leave right now.',                                       // 160:72
  communing: 'Your communication with Solar Protection Stone\nhas begun. The stone is radiating...', // 160:206
  someoneElse: '[Message] Someone else is communicating with the stone.',           // 160:203
  blocked: '[Message] You are currently blocked from the stone.',                   // 160:204
  unavailable: '[message]Sunstone communion is unavailable at this time.',          // 160:205
  needScore: 'You do not have enough Personal Score points to\ncommunicate with the stone.', // 160:208
  ownStone: 'Your team already conquered this Guardian Stone.',                     // 160:623
  stopped: 'Conquering process of Guardian Stone has stopped.',                     // 160:622
  conquered: 'You succeeded to conquer!',                                           // 160:621
  attempting: 'Attempting to conquer!',                                             // 160:620
  started: 'The battle has been started.',                                          // 160:630 (effect suffix dropped)
  noWinner: 'There is no winning side in Zuto\'s Battlefield.',                     // 160:633
  bagFull: '[message]Your bag is full.',                                            // 161:212
  failed: 'Failed to execute the command.',                                         // 160:62
  revive: 'Moving to the saved place.\nYou\'ll be exited in 1 minute if you don\'t revivie.', // 160:636 (colour tags dropped)
});
/** Broadcast texts with the team name (<ALLY>) / character (<NAME>) filled in. */
export const ARENA_BROADCAST = Object.freeze({
  trying: '[message]<ALLY> is trying to communicate on Protection Stons of the Sun!!',                       // 160:200
  failedTeam: '[Message] <NAME> in the <ALLY> Army failed to communicate with the Solar Protection Stone; the <ALLY> Army is blocked from the stone for 30 seconds.', // 160:201
  occupied: '[message]<ALLY> has occupied Protection Stons of the Sun!!',                                   // 160:202
});
export const fillAlly = (s, ally, name = '') => String(s).replace(/<ALLY>/g, ally).replace(/<NAME>/g, name);

const n = v => { const x = Number(v); return Number.isFinite(x) ? x : 0; };
const rowsOf = (table, key) => (table || []).find(r => r?.[0] === key);
/** share/arena/activity.csv -> grades, rank blocks (S 8 / A 7 / B 6 / N 0) of GradePoint/Grade/EXP/Purchase/Coin/Proof. */
export function parseActivity(table) {
  const count = n(rowsOf(table, 'Count')?.[1]) || 7, take = r => (r || []).slice(1, 1 + count).map(n);
  const out = { penaltyStatus: n(rowsOf(table, 'PaneltyStatus')?.[1]), penaltySec: n(rowsOf(table, 'StatusTime(Sec)')?.[1]),
    coinIndex: n(rowsOf(table, 'CoinIndex')?.[1]), proofIndex: n(rowsOf(table, 'ProofIndex')?.[1]), count,
    ratio: take(rowsOf(table, 'Ratio')), strings: take(rowsOf(table, 'String')), ranks: {} };
  let rank = null;
  for (const r of table || []) {
    if (r?.[0] === 'Rank') { rank = n(r[1]); out.ranks[rank] = {}; continue; }
    const m = rank != null && /^[A-Z]_(.+)$/.exec(String(r?.[0] || ''));
    if (m) out.ranks[rank][m[1]] = take(r);
  }
  return out;
}
const ACTION_KEYS = Object.freeze({ 1: 'killPc', 2: 'dead', 3: 'destroyStone', 4: 'killMonster', 5: 'move', 6: 'hitSkill' });
/** share/arena/dkactionpoint.csv -> {minReward, moveSec, points:{killPc, dead, destroyStone, killMonster, move, hitSkill}}. */
export function parseActionPoints(table) {
  const head = table?.[1] || [], points = {};
  for (const r of (table || []).slice(3)) { const k = ACTION_KEYS[n(r[0])]; if (k) points[k] = n(r[1]); }
  return { minReward: n(head[0]), moveSec: n(head[1]), points };
}
const squadsOf = f => {
  const out = [];
  for (let i = 1; i <= n(f.SquadCount); i++) {
    const k = String(i).padStart(2, '0');
    out.push({ squad: i, ally: n(f[`Squad_AllyType_${k}`]), start: { x: n(f[`Pos_${k}_X`]), z: n(f[`Pos_${k}_Y`]) }, revive: { x: n(f[`Revive_Pos_${k}_X`]), z: n(f[`Revive_Pos_${k}_Y`]) } });
  }
  return out;
};
/**
 * Both venues from modes.arena and the battlefield map records ({702: {npcs}, 548: {dungeon}}).
 * draco = conquest Mode 3 + field Type 3; lostHorizon = losthorizon Mode 100 + field Type 2 + rank.csv Rank 100.
 */
export function buildArenaVenues(arena, maps = {}) {
  if (!arena?.conquest || !arena?.field) return {};
  const fieldOf = t => arena.field.find(f => n(f.Type) === t), rankOf = r => (arena.rank || []).find(x => n(x.Rank) === r);
  const missions = f => [f.MainMissionStringCode, f.SubMissionStringCode_1, f.SubMissionStringCode_2, f.SubMissionStringCode_3].map(n).filter(Boolean);
  const out = {};
  const cq = arena.conquest.find(r => n(r.Mode) === 3), fd = fieldOf(3);
  if (cq && fd) {
    const rk = rankOf(n(cq.Rank)) || {}, sun = (maps[fd.MapIndex]?.npcs || []).find(r => n(r[0]) === 6054);
    out.draco = { key: 'draco', name: String(maps[fd.MapIndex]?.name || ''), job: ARENA_JOBS.draco, mode: 3, rank: n(cq.Rank), map: n(fd.MapIndex), title: n(fd.TitleStringCode), missions: missions(fd),
      radius: n(fd.Pos_Radius), squads: squadsOf(fd), minLevel: n(rk.Min_Level), maxLevel: n(rk.Max_Level), enterCost: n(cq.EnterCost),
      fightSec: n(cq['FightTime(Sec)']), activeScore: n(cq.ActiveScore), startPlayers: n(cq.StartPCCount), maxPlayers: n(cq.MaxPCCount),
      conquestWaitSec: n(cq['ConquestWaitTime(Sec)']), conquestSec: n(cq['ConquestTime(Sec)']), coolSec: n(cq['CoolTime(Sec)']),
      buff: n(cq.Buff), buffSec: n(cq['BuffTime(Sec)']), keepMin: n(cq.KeepTime), openCount: n(cq.OpenCount), openHour: n(cq.OpenTime_1),
      sunstone: sun ? { npc: 6054, x: n(sun[1]), z: n(sun[2]) } : null };
  }
  const lh = (arena.lostHorizon || []).find(r => n(r.Mode) === 100), fl = fieldOf(2);
  if (lh && fl) {
    const rk = rankOf(100) || {}, dg = maps[fl.MapIndex]?.dungeon || {};
    out.lostHorizon = { key: 'lostHorizon', name: String(maps[fl.MapIndex]?.name || ''), job: ARENA_JOBS.lostHorizon, mode: 100, rank: 100, map: n(fl.MapIndex), title: n(fl.TitleStringCode), missions: missions(fl),
      radius: n(fl.Pos_Radius), squads: squadsOf(fl), minLevel: n(rk.Min_Level), maxLevel: n(rk.Max_Level), maxPlayers: n(rk.Max_Room),
      startPlayers: n(dg.requestMember), fightSec: n(dg.expireTime) * 60, needItemType: n(lh.NeedItemType), needItemCount: n(lh.NeedItemCount),
      needDil: n(lh.NeedDil), waitSec: n(lh.WaitTime), openHour: 24, activeScore: 0,
      // callmonster_548_lost_horizon.csv call 1: [monster, x, z, ...] (the stone images of both bases)
      stoneCalls: ((maps[fl.MapIndex]?.calls || {})[1] || []).map(r => r.map(n)) };
  }
  return out;
}
/** Opening window at `nowMs` (UTC+1): OpenTime_1 24 = all day; else the hour's opening lasting FightTime. */
export function openWindow(venue, nowMs) {
  if (!venue) return { open: false };
  if (!(venue.openHour < 24)) return { open: true, startsAt: null, endsAt: null };
  const d = serverDate(nowMs), start = serverTimestamp(d.getUTCFullYear(), d.getUTCMonth(), d.getUTCDate(), venue.openHour);
  const end = start + venue.fightSec * 1000;
  if (nowMs >= start && nowMs < end) return { open: true, startsAt: start, endsAt: end };
  const next = nowMs < start ? start : serverTimestamp(d.getUTCFullYear(), d.getUTCMonth(), d.getUTCDate() + 1, venue.openHour);
  return { open: false, startsAt: next, endsAt: next + venue.fightSec * 1000 };
}
export const levelAllowed = (venue, level) => n(level) >= venue.minLevel && n(level) <= venue.maxLevel;
/** ENGINE-CHOSEN teamAssign: the squad with the fewest members, ties to the lower squad. */
export function assignTeam(counts) { let best = 0; for (let i = 1; i < counts.length; i++) if (counts[i] < counts[best]) best = i; return best; }
/** Activity grade (0..count-1) of `points` on a rank block. */
export function gradeOf(points, block) {
  const gp = block?.GradePoint || []; let g = 0;
  for (let i = 0; i < gp.length; i++) if (n(points) >= gp[i]) g = i;
  return g;
}
/** Settlement of one participant (rows as written; nothing scaled). outcome: win | lose | draw. */
export function settle({ activity, rank, points, outcome, minReward }) {
  const block = activity?.ranks?.[rank], grade = gradeOf(points, block), side = outcome === 'win' ? 'Win' : C.drawRow;
  const achieved = n(points) >= n(minReward);
  const pick = k => (achieved && block?.[`${k}_${side}`] ? n(block[`${k}_${side}`][grade]) : 0);
  return { grade, ratio: activity?.ratio?.[grade] ?? 0, gradeString: activity?.strings?.[grade] ?? GRADE_NAME_CODES[grade], achieved, hasRows: !!block,
    rankScore: pick('Grade'), exp: pick('EXP'), coin: pick('Coin'), proof: pick('Proof'), coinIndex: activity?.coinIndex || 0, proofIndex: activity?.proofIndex || 0 };
}
/** dkkillpoint KillCount -> DkPoint (the last row above the table). */
export function dkPointFor(kills, table) {
  const rows = table || []; if (!rows.length) return 0; const k = Math.max(0, Math.floor(n(kills)));
  const row = rows.find(r => n(r[0]) === k) || (k > n(rows[rows.length - 1][0]) ? rows[rows.length - 1] : null);
  return row ? n(row[1]) : 0;
}
/** dktierbuff: highest tier of the rank whose DKPoint <= dp (null when the rank has no rows or dp is below Soldier). */
export function tierFor(dp, rows, rank) {
  let best = null;
  for (const r of rows || []) if (n(r.Rank) === n(rank) && n(dp) >= n(r.DKPoint) && (!best || n(r.Tier) > best.tier)) best = { tier: n(r.Tier), name: String(r.Name) };
  return best;
}
/** ENGINE-CHOSEN winRule. teams[i] = {points, present}; sun = {owner}. Returns the winning team index or -1 (draw). */
export function decideWinner(teams, sun = {}, reason = 'time') {
  const present = teams.map((t, i) => (t.present > 0 ? i : -1)).filter(i => i >= 0);
  if (reason === 'alone' && present.length === 1) return present[0];
  if (sun?.owner != null && sun.owner >= 0 && (reason === 'keep' || reason === 'time')) return sun.owner;
  const best = Math.max(...teams.map(t => n(t.points)));
  const top = teams.map((t, i) => (n(t.points) === best ? i : -1)).filter(i => i >= 0);
  return top.length === 1 ? top[0] : -1;
}
/** Rank board rows: DP Score high to low, then name. */
export function boardRows(entries, limit = C.boardRows) {
  return [...entries].sort((a, b) => n(b.dp) - n(a.dp) || String(a.name).localeCompare(String(b.name))).slice(0, limit).map((e, i) => ({ ...e, rank: i + 1 }));
}
export const fmtClock = ms => { const s = Math.max(0, Math.ceil(n(ms) / 1000)); return `${String(Math.floor(s / 60)).padStart(2, '0')}:${String(s % 60).padStart(2, '0')}`; };
