// DK-SQUARE rules (pure): conquest.csv Mode 0 ranks on rank.csv bands, field.csv Type 0, dkschedule.csv windows and the
// lobby rules of stringtable_dksquare.txt cate 160. Gaps: src/config/engine-chosen-dk-square.js. Battle points, settlement,
// DP / tier and the win rule are the shared helpers of src/systems/arena/arena-rules.js. Nothing here scales a data value.
import { DK_SQUARE_CHOSEN as C } from '../../config/engine-chosen-dk-square.js';
import {serverDate,serverTimestamp} from '../../game/server-time.js';

export const DK_SQUARE_JOB = 48;                 // ARENA_SQUARE (npcs 121 / 720 / 5167)
export const SUNSTONE_NPC = 5003;                 // GuardianStone of the Sun on map 67 (job 52 ARENA_CONQUEST)
export const DK_SQUARE_SCRIPTS = Object.freeze({
  select: 'game2/dksquare/ui_selectwnd.txt', create: 'game2/dksquare/ui_createdksquarewnd.txt', alarm: 'game2/dksquare/ui_lobbyalarm.txt',
  waiting: 'game2/dksquare/ui_waitinginfownd.txt', confirm: 'game2/dksquare/ui_confirmwnd.txt', time: 'game2/dksquare/ui_attachtimewnd.txt',
  gauge: 'game2/dksquare/ui_circleprogresswnd.txt', icon: 'game2/dksquare/ui_conquesticon.txt', mission: 'game2/dksquare/ui_missionwnd.txt',
  points: 'game2/dksquare/ui_dksquareactivitypointwnd.txt', info: 'game2/dksquare/ui_battleinfownd_renew2.txt', msgbox: 'game2/dksquare/ui_msgbox.txt',
  active: 'game2/dksquare/ui_activeicon.txt', board: 'game2/dksquare/ui_rankboardwnd.txt',
});
/** Original texts (cate 160). */
export const DK_SQUARE_TEXT = Object.freeze({
  closed: 'DK Square is currently unavailable.\nPlease refer to the Content Guide for the entrance time.', // 160:95
  level: 'Your level is not eligible to enter.',                                      // 160:33
  already: 'You are already waiting in the lobby.\nPlease check the Lobby Waiting icon.', // 160:41
  noMore: 'No more lobbies can be opened.',                                           // 160:45
  below: 'Lobby condition of less than 20 people exists and cannot be created.',     // 160:96
  full: 'The lobby is full; you cannot join the lobby.',                              // 160:28
  battleFull: 'Battlefield is full.',                                                 // 160:300
  noLobby: 'No such lobby exists.',                                                   // 160:80
  closing: 'You cannot join a battle that is being closed.',                          // 160:76
  dead: 'Dead characters cannot enter the lobby.',                                    // 160:81
  busy: 'You are in some condition that prohibits you from\nentering the lobby. Please abort or finish your\ncurrent activity, and then try again.', // 160:84
  berserkJoin: 'You cannot join DK Square while in the Battle Berserk status.',       // 160:85
  berserkOpen: 'You cannot open a DK Square lobby while in the Battle Berserk status.', // 160:86
  draco: 'Cannot join DK Square while waiting for Draco Battleground.',               // 160:649
  dil: 'Insufficient DIL',                                                            // 160:669
  cancelled: 'You have canceled entering the Battlefield.',                           // 160:49
  someCancelled: 'Some participants have canceled; you cannot enter the arena.',      // 160:98
  cannotLeave: 'You cannot leave right now.',                                         // 160:72
  failed: 'Failed to execute the command.',                                           // 160:62
  revive: 'Moving to the saved place.\nYou\'ll be exited in 1 minute if you don\'t revivie.', // 160:636 (colour tags dropped)
});

const n = v => { const x = Number(v); return Number.isFinite(x) ? x : 0; };
const squadsOf = f => {
  const out = [];
  for (let i = 1; i <= n(f.SquadCount); i++) {
    const k = String(i).padStart(2, '0');
    out.push({ squad: i, ally: n(f[`Squad_AllyType_${k}`]), start: { x: n(f[`Pos_${k}_X`]), z: n(f[`Pos_${k}_Y`]) }, revive: { x: n(f[`Revive_Pos_${k}_X`]), z: n(f[`Revive_Pos_${k}_Y`]) } });
  }
  return out;
};
/** DK Square ranks from modes.arena (+ map 67 npcs for the Sunstone): {ranks:{7:{...},8:{...}}, field, schedule}. */
export function buildDkSquare(arena, maps = {}) {
  if (!arena?.conquest || !arena?.field || !arena?.rank) return null;
  const f = arena.field.find(r => n(r.Type) === C.fieldType); if (!f) return null;
  const sun = (maps[f.MapIndex]?.npcs || []).find(r => n(r[0]) === SUNSTONE_NPC);
  const field = { type: n(f.Type), map: n(f.MapIndex), title: n(f.TitleStringCode), radius: n(f.Pos_Radius), squads: squadsOf(f),
    missions: [f.MainMissionStringCode, f.SubMissionStringCode_1, f.SubMissionStringCode_2, f.SubMissionStringCode_3].map(n).filter(Boolean),
    sunstone: sun ? { npc: SUNSTONE_NPC, x: n(sun[1]), z: n(sun[2]) } : null };
  const ranks = {};
  for (const cq of arena.conquest.filter(r => n(r.Mode) === C.conquestMode)) {
    const rk = arena.rank.find(r => n(r.Rank) === n(cq.Rank)); if (!rk) continue;
    ranks[n(cq.Rank)] = { key: 'dkSquare', rank: n(cq.Rank), mode: C.conquestMode, minLevel: n(rk.Min_Level), maxLevel: n(rk.Max_Level), maxRooms: n(rk.Max_Room),
      server: n(rk.Server_00), lobbies: [rk.Lobby_00, rk.Lobby_01, rk.Lobby_02, rk.Lobby03].map(n).filter(Boolean),
      enterCost: n(cq.EnterCost), fightSec: n(cq['FightTime(Sec)']), activeScore: n(cq.ActiveScore), startPlayers: n(cq.StartPCCount), maxPlayers: n(cq.MaxPCCount),
      conquestWaitSec: n(cq['ConquestWaitTime(Sec)']), conquestSec: n(cq['ConquestTime(Sec)']), coolSec: n(cq['CoolTime(Sec)']),
      buff: n(cq.Buff), buffSec: n(cq['BuffTime(Sec)']), keepMin: n(cq.KeepTime),
      map: field.map, title: field.title, missions: field.missions, radius: field.radius, squads: field.squads, sunstone: field.sunstone };
  }
  const schedule = (arena.dkSchedule || []).map(r => ({ index: n(r.Index), start: n(r.Start_Hour) * 60 + n(r.Start_Minute), end: n(r.End_Hour) * 60 + n(r.End_Minute) }));
  return { ranks, field, schedule };
}
/** The Mode 0 rank whose rank.csv band holds `level`, or null (160:33). */
export function rankForLevel(ds, level) {
  const lv = n(level);
  return Object.values(ds?.ranks || {}).find(r => lv >= r.minLevel && lv <= r.maxLevel) || null;
}
/** dkschedule.csv window holding `nowMs` (UTC+1); End before Start = across midnight. */
export function scheduleWindow(schedule, nowMs) {
  const d = serverDate(nowMs), mins = d.getUTCHours() * 60 + d.getUTCMinutes(), day = serverTimestamp(d.getUTCFullYear(), d.getUTCMonth(), d.getUTCDate());
  const at = m => day + m * 60000;
  for (const w of schedule || []) {
    if (w.end > w.start) { if (mins >= w.start && mins < w.end) return { open: true, index: w.index, startsAt: at(w.start), endsAt: at(w.end) }; continue; }
    if (mins >= w.start) return { open: true, index: w.index, startsAt: at(w.start), endsAt: at(w.end + 1440) };
    if (mins < w.end) return { open: true, index: w.index, startsAt: at(w.start - 1440), endsAt: at(w.end) };
  }
  let next = null;
  for (const w of schedule || []) { const s = w.start > mins ? at(w.start) : at(w.start + 1440); if (next == null || s < next) next = s; }
  return { open: false, startsAt: next, endsAt: null };
}
/** 160:45 / 160:96: may a new lobby be opened next to `lobbies` (the rank's live lobbies)? Returns null or the refusal key. */
export function openRefusal(lobbies, rank) {
  if (lobbies.length >= rank.maxRooms) return 'noMore';
  if (lobbies.some(l => l.phase === 'waiting' && l.members.length < C.openBelow)) return 'below';
  return null;
}
/** The dktierbuff row a character holds (ENGINE-CHOSEN tierScope): its level's conquest Mode 0 rank band (rank.csv) and
 *  the highest Tier of that rank whose DKPoint <= its DP Score; null below Soldier or outside the bands. `arena` = modes.arena. */
export function heldDkTier(arena, profile) {
  const lv = n(profile?.level), dp = n(profile?.arena?.dp);
  if (!(dp > 0) || !arena?.dkTierBuff?.length || !arena.conquest || !arena.rank) return null;
  const band = arena.conquest.filter(r => n(r.Mode) === C.conquestMode).map(r => arena.rank.find(x => n(x.Rank) === n(r.Rank))).find(r => r && lv >= n(r.Min_Level) && lv <= n(r.Max_Level));
  let best = null;
  if (band) for (const r of arena.dkTierBuff) if (n(r.Rank) === n(band.Rank) && dp >= n(r.DKPoint) && (!best || n(r.Tier) > n(best.Tier))) best = r;
  return best;
}
/** The held tier's options as native [optionIndex, value] pairs (8 HP_MAX_ADD, 43 SPEED_MOVE_MUL, 316 RESULT_EXP_MUL) for the
 *  host stat pipeline (item-option fold). GradePercentValue is not an option and is not returned (unapplied). */
export function dkTierOptions(arena, profile) {
  const row = heldDkTier(arena, profile); if (!row) return [];
  const out = [];
  for (let i = 1; i <= n(row.OptionCount); i++) { const type = n(row[`OptionIndex${i}`]), value = n(row[`OptionValue${i}`]); if (type && value) out.push([type, value]); }
  return out;
}
/** Native class enumeration of changeshape.csv Class (index = classIndex; checked against each row's wings classMask bit). */
export const CHANGE_SHAPE_CLASSES = Object.freeze(['AZURE_KNIGHT', 'SAGGITA_HUNTER', 'INCAR_MAGICIAN', 'VICIOUS_SUMMONER', 'SEGNALE', 'BAGI_WARRIOR', 'ALOKEN',
  'DRAGON_KNIGHT', 'SAGGITA_SHOOTER', 'BLACK_WIZARD', 'CONCERRA_SUMMONER', 'SEGEURIPER', 'HALF_BAGI', 'NALO', 'TRI']);
const LOOK_SLOT = Object.freeze({ COSTUME_SET: 18, WINGS: 7, TRANFER_EMBLEM: 33 });   // public appearance slots (server/world/appearance.mjs)
/** ENGINE-CHOSEN teamLook: the public appearance rows of a battle participant with the changeshape.csv rows of its squad
 *  (Team = Squad_AllyType) projected on: costume (18) / wings (7) by class, emblem (33), and on a worn weapon / shield
 *  (slots 4 / 5) the Team 0 look item whose value1 equals that item's code (carried as the row's `appearance`). Real rows
 *  are copied, never mutated; sockets of a replaced slot are dropped (the projected item is not the worn one). PET rows
 *  are not projected. weaponCodes = {slot: worn type 4 code}. */
export function teamLookRows(rows, { team, classIndex, weaponCodes = {} }, changeShape, lookItem = () => null) {
  if (!(team > 0) || !Array.isArray(changeShape)) return rows;
  const cls = CHANGE_SHAPE_CLASSES[n(classIndex)], out = (rows || []).map(r => ({ ...r, sockets: [...(r.sockets || [])] }));
  const put = (slot, itemIndex) => { const at = out.findIndex(r => r.slot === slot), row = { slot, itemIndex, appearance: 0, sockets: [], projected: true }; if (at >= 0) out[at] = row; else out.push(row); };
  for (const r of changeShape) {
    const t = n(r.Team), code = String(r.ItemCode || ''), index = n(r.ItemIndex);
    if (!index || (t !== team && t !== 0) || code === 'PET') continue;
    if (LOOK_SLOT[code]) { if (t === team && (r.Class === 'ALL' || r.Class === cls)) put(LOOK_SLOT[code], index); continue; }
    for (const [slot, worn] of Object.entries(weaponCodes)) {
      const w = worn != null && n(lookItem(index)?.value1) === n(worn) && out.find(x => x.slot === Number(slot));
      if (w) { w.appearance = index; w.projected = true; }
    }
  }
  return out.sort((a, b) => a.slot - b.slot);
}
/** 160:2: deal ids at random, alternating Miseria / Ricchez (sizes differ by at most one). random() in [0,1). */
export function dealTeams(ids, random = Math.random) {
  const order = [...ids];
  for (let i = order.length - 1; i > 0; i--) { const j = Math.floor(random() * (i + 1)); [order[i], order[j]] = [order[j], order[i]]; }
  return [order.filter((_, i) => i % 2 === 0), order.filter((_, i) => i % 2 === 1)];
}
