import {SERVER_TIME_OFFSET_MINUTES} from '../game/server-time.js';
// ENGINE-CHOSEN guild-family values: every value in this module is tagged ENGINE-CHOSEN (not in Global data). The shipped Global
// client data (data/unpacked/data, re-checked against an untouched Global client install) does not
// define them; they are server rules of the original game. Each one is a reasonable engine value, kept here in ONE place so it can be
// replaced the moment a real value is known. Everything that IS in the data stays in the *-rules.js modules with its source.
// LANE-61: values since re-sourced are labelled GLOBAL / DECOMPILE / OLDER SERVER REFERENCE / ONLINE (with the URL), or REMOVED.

/** Alliance (ALLIANCE gate: server/world/alliance.mjs, src/systems/extras/alliance.js). */
export const ALLIANCE_CHOSEN = Object.freeze({
  /** REMOVED (LANE-61): no request lifetime exists in Global (no timeout string in stringtable_alliance 140; the request /
   *  invite windows' progress bar has no duration), the decompiles or the older server reference. A request now ends only the
   *  Global ways (140:120-129): the requester cancels, goes offline or stops being the guild master, or a guild is gone.
   *  null = no timeout (an old host may still send a number; the client then animates the bar). */
  INVITE_TIMEOUT_MS: null,
  /** REMOVED (LANE-61): no naming-step lifetime in any source; the naming step ends as above or by 140:61 (requester cancels). */
  NAMING_TIMEOUT_MS: null,
  /** OLDER SERVER REFERENCE + GLOBAL (LANE-61): "Alliance Executives" (Global 140:81 / 140:112) = the Guild Masters of the member
   *  guilds: server-ref SP_ALLIANCE_ALLIANCEMASTER_UPDATE only accepts a member guild's master (peerage_code 0). */
  EXECUTIVES: 'member guild masters',
  /** GLOBAL + OLDER SERVER REFERENCE (LANE-61): only the Alliance Commander edits the notice: Global 140 "You do not have permission
   *  to change the notice" + server-ref ALLIANCE_INFO holds one leader and SP_ALLIANCE_UPDATE writes the notice for it. */
  NOTICE_EDITOR: 'commander',
  /** GLOBAL + OLDER SERVER REFERENCE (LANE-61): only the Alliance Commander changes / deletes the alliance mark and effect (Global
   *  140:71 / 140:74 permission refusals; server-ref SP_ALLIANCE_UPDATE mark1/mark2/effect on the single-leader ALLIANCE_INFO row). */
  MARK_EDITOR: 'commander',
  /** ENGINE-CHOSEN (not in Global data): the original opens the request from the target guild master's player menu (not in the
   *  scripts); the engine uses chat commands next to the existing /ginvite: /ainvite <character>, /aleave. */
  COMMANDS: Object.freeze({ invite: '/ainvite', leave: '/aleave', window: '/awin' }),   // '/alliance' and '/a' are chat channel words
  /** OLDER SERVER REFERENCE (LANE-61): an alliance that falls below 2 guilds (helper 1746) is disbanded with its mark and nothing is
   *  refunded: server-ref SP_ALLIANCE_DELETE only archives the row to ALLIANCE_INFO_SECEDE (no DIL return). ONLINE (dekarons.com
   *  guild wiki, labelled): founding costs 2,000,000 DIL, guild level 2+, at most 4 guilds (alliance.csv MONEY / MAX already). */
  DISBAND_REFUND: 0,
  /** ENGINE-CHOSEN (not in Global data): nameplate line for the alliance: the alliance mark (24 px guildbg_s/guildicon_s cells, as the
   *  guild mark) + the alliance name, above the guild line, shown while Options > View > Alliance name is on. */
  NAMEPLATE: 'mark + name above the guild line',
  /** ENGINE-CHOSEN (not in Global data): Alliance of Glory (itemcash Type 0 Code 30, 15 items) sets the alliance effect; the data has
   *  no description of the effect's drawing, so the engine stores and shows the chosen effect item (alliance window icon pan_iconimg). */
  GLORY_DISPLAY: 'item icon in the alliance window',
});

/** Guild Frontier ranking (GUILD-DUNGEON-RANK: server/world/guild-frontier.mjs, src/systems/extras/guildrank-rules.js). */
export const FRONTIER_CHOSEN = Object.freeze({
  /** Thursday from132:101/500,03:00 from551:106. Fixed UTC+1 is the shared native server-clock reading.
   *  ENGINE-CHOSEN:551's03:00 wins over hideout552's conflicting01:00 so one durable settlement owns both awards.
   *  Already-open immutable donation ledgers retain their historical deadline until they close. */
  MAINTENANCE: Object.freeze({ weekday: 4, hour: 3, minute: 0, offsetMinutes: SERVER_TIME_OFFSET_MINUTES }),
  /** Native UI/db evidence supports shared competition ranks; ties receive the first shared rank's Dungeon_Grade.
   *  A zero-point guild earns no award. */
  TIE_RULE: 'competition-shared-rank',
  /** ENGINE-CHOSEN (not in Global data): the production server policy = the MAINTENANCE week above (server/world/data.mjs
   *  loadWorldData guildPolicy). An explicit guildPolicy.frontierPeriod still wins (fixtures / a recovered real schedule). */
  PRODUCTION_POLICY: Object.freeze({ frontierSchedule: 'engine-chosen' }),
  /** ENGINE-CHOSEN (not in Global data): the original settles the ranking inside its maintenance; the engine's host tick looks for a
   *  closed, unsettled period every FINALIZE_POLL_MS (server/world/guild-frontier.mjs tickGuildFrontier). Only the timing is
   *  chosen; the settlement itself is the existing durable accounts-document CAS. */
  FINALIZE_POLL_MS: 10_000,
  /** ENGINE-CHOSEN (not in Global data): wait after a failed durable settlement save before the tick retries it. */
  FINALIZE_RETRY_MS: 60_000,
});

/** Frontier weekly reset: Thursday 03:00, fixed server UTC+1. Day/hour are native; shared server zone is disclosed. */
export function engineFrontierWeek(now, M = FRONTIER_CHOSEN.MAINTENANCE) {
  const offset=M.offsetMinutes*60000, local=now+offset,d=new Date(local);
  const back=(d.getUTCDay()-M.weekday+7)%7;
  let start=Date.UTC(d.getUTCFullYear(),d.getUTCMonth(),d.getUTCDate()-back,M.hour,M.minute);
  if(start>local)start-=7*86400000;
  return {id:'engine-cet-week-'+new Date(start).toISOString().slice(0,10),opensAt:start-offset,closesAt:start+7*86400000-offset};
}

/** Guild skills (server/world/guild-extras.mjs, src/systems/extras/guildextras.js). */
export const GUILD_SKILL_CHOSEN = Object.freeze({
  /** GLOBAL (LANE-61): who may press Enable Skill = ranks with the ui_gradewnd box 12 'Enable Skill' (GradeManageWnd bit 0x100); refusal 130:418.
   *  Default grades (older server reference GUILD_PEERAGE template): only the master. */
  ENABLER: 'grade permission enableSkill (0x100)',
  /** ENGINE-CHOSEN (not in Global data): replacing the running guild skill (130:373) refunds nothing of the old skill's cost. */
  REPLACE_REFUND: 0,
  /** ENGINE-CHOSEN (not in Global data): the skill's status (Status_ID) runs on every guild member, online now or on their next
   *  login, until its Apply_Sec ends; leaving / being expelled from the guild removes it. */
  MEMBERS: 'every member while the skill runs',
  // The guild-level DIL reduction is NOT engine-chosen: official Global guide 5 gives levels 11-15 = 5/7/10/12/15 % and the
  // skill window has lbl_dil_discount (src/systems/extras/guildextras-rules.js SKILL_DIL_DISCOUNT).
});

/** Online source used below (tier 4, labelled ONLINE): the official DEKARON JP operator notice of 2025-07-04 (Guild War
 *  implementation), https://dekaron-hangame.brabragames.jp/news/notice.html?mode=read&no=1168 . */
export const WAR_SOURCE_URL = 'https://dekaron-hangame.brabragames.jp/news/notice.html?mode=read&no=1168';

/** Guild war declaration / acceptance. Durations 3 / 7 / 15 / 30 days ARE in the data (135:100..103). */
export const GUILD_WAR_CHOSEN = Object.freeze({
  /** ONLINE (LANE-61, WAR_SOURCE_URL "期間別ギルド戦争申請時に必要財貨"): the cost of a declaration by duration, taken at declaration
   *  from the guild's DIL (the DIL Donation treasury) and the guild's Guild Points (135:25 "Required DIL" / "Required Guild
   *  Points"; 135:10 / 135:11 when short). Replaces the former engine-chosen 1,000,000 DIL + 1 GP per day. */
  COST_BY_DAYS: Object.freeze({
    3: Object.freeze({ dil: 100_000_000, guildPoints: 300 }),
    7: Object.freeze({ dil: 217_000_000, guildPoints: 700 }),
    15: Object.freeze({ dil: 425_000_000, guildPoints: 1_500 }),
    30: Object.freeze({ dil: 700_000_000, guildPoints: 3_000 }),
  }),
  /** ONLINE (LANE-61, WAR_SOURCE_URL 4-6): a guild may declare on at most 3 guilds (alliances) at once (pending + active; 135:9). */
  MAX_DECLARATIONS: 3,
  /** ONLINE (LANE-61, WAR_SOURCE_URL 4-6 "no further declaring / accepting" at the limit): open wars a target guild may be in (135:37). */
  MAX_TARGET_WARS: 3,
  /** GLOBAL (LANE-61): who declares (135:8) / accepts or surrenders (135:38) = ranks with ui_gradewnd box 9 'Declare War' (0x200) /
   *  box 11 'Accept War' (0x400). Default grades: only the master. Surrender uses the Accept War right: DECOMPILE
   *  AcceptanceOfWarWnd (FUN_00d5a370) sends accept 1 / decline 2 / surrender 3 on one packet (0x58 / 0x48000005) from one
   *  window, and FUN_014b93c0 answers 135:38; ONLINE (WAR_SOURCE_URL 1-2): surrender is chosen by clicking the [In progress] war. */
  AUTHORITY: 'grade permissions declareWar (0x200) / acceptWar (0x400, also surrender)',
  /** ONLINE (LANE-61, WAR_SOURCE_URL 1-①): the target answers within 3 days; with no answer the war is AUTOMATICALLY ACCEPTED and
   *  starts (it runs its full duration from the end of the 3 days). Replaces the former engine-chosen 24 h lapse-as-loss. */
  PENDING_TIMEOUT_MS: 259_200_000,
  /** ONLINE (LANE-61, WAR_SOURCE_URL 1-①): what an unanswered declaration becomes when PENDING_TIMEOUT_MS passes. */
  PENDING_RESOLVE: 'accept',
  /** JUDGMENT (lane 51 g; no source defines the area): "current area" of 135:6 / 135:39 read as the map: no declaration from inside an instance (dungeon,
   *  DK Square, siege); the target must be a character on the declarer's map. */
  AREA_RULE: 'not inside an instance; target on the same map',
  /** ONLINE (lane 51 g, official JP notice dekaron-hangame.jp no=1168): during a war the two guilds may fight each other without
   *  limit in the field (excluded regions below), party / allies cannot be attacked, war kills raise no Niete, and content such as
   *  DK Square / Dead Front keeps its own rules. JUDGMENT (damage): the PvP pipeline of pvp-rules.js. In the engine, members of two
   *  guilds at an ACTIVE war (status 135:111) are hostile to each other (server/world/guild-war-pvp.mjs registerPvpMode): basic
   *  attacks and skills hit them with the PvP damage of src/game/pvp-rules.js (pvpDamage, shield first), a down is an ordinary
   *  death (profile.deaths, the normal revive), and the kill counts once for the killer's guild on the war record. */
  COMBAT: 'active wars are hostile on PvP-allowed open maps; pvp-rules.js damage; kills recorded on the war',
  /** ONLINE (no=1168: content keeps its own rules -> no instances) + JUDGMENT (lane 51 g: "field" read as the Global maplist PvP
   *  flags, so a map the data marks non-PvP stays non-PvP): where war members may fight: maplist IsPvP 1 and PVP_PeaceZone 0, never inside an
   *  instance (dungeon, DK Square, event run). Towns with PVP_PeaceZone 1 (Braiken 0, Loa 7, Ardeca 150) stay safe via that flag. */
  COMBAT_MAP: Object.freeze({ isPvP: 1, pvpPeaceZone: 0, instances: false }),
  /** ONLINE (LANE-61 / cleanup, WAR_SOURCE_URL excluded-region table): no war combat in Braiken Castle (0), Loa Castle (7),
   *  Morse Yawalai / Mors (50), The Qualines / Quarin Islands (51), Ardeca (150). Braiken/Loa/Ardeca are also PVP_PeaceZone 1;
   *  Morse and Qualines are IsPvP 1 / Peace 0 so they need this explicit list. Names show red there but attacks are refused. */
  SAFE_MAP_INDEXES: Object.freeze([0, 7, 50, 51, 150]),
  /** ONLINE (WAR_SOURCE_URL) + GLOBAL stringtable_color red1=FF3300: enemy guild (and auto-joined alliance) character names
   *  draw in red while the war is active, including on SAFE_MAP_INDEXES where combat is refused. */
  ENEMY_NAME_COLOR: '#ff3300',
  /** JUDGMENT (lane 51 g; reasoning: the same last-hit owner the duel and field PK use; no source names the war killer): a war kill = the character who landed the last PvP hit (pvpLastHit) belongs to the
   *  other guild of an active war with the downed character's guild; one count per death, stored as war.kills[guildId]. */
  KILL_CREDIT: 'last PvP hitter, once per death',
  /** JUDGMENT (lane 51 g; storage cadence only, not a gameplay value): kills wait in host memory and are folded into the durable war record by the next guild
   *  write or the host war tick (at most KILL_FLUSH_MS later). */
  KILL_FLUSH_MS: 2_000,
  /** GLOBAL + DECOMPILE (LANE-61): the guild kill notice 130:476 "In %s %s was killed by %s." (map name, victim, killer): the
   *  client's guild packet 0x1103000a handler (FUN_01396f00) fills it with the map (short +0x9a), the victim (+0x46) and the killer
   *  (+0x70) and prints it on chat channel 8. Replaces the former engine text '[Guild War] %s defeated %s.'. */
  KILL_NOTICE: Object.freeze([130, 476]),
  // COMMAND '/gwar' REMOVED (lane 51 g): no source for a chat declaration; the player menu 240:13 is the Global route.
  // HISTORY_LIMIT 50 REMOVED (lane 51 g): no source for a cap; War Status keeps every closed war (newest first).
});

/** Guild / Alliance of Glory emblem illumination (src/ui/guild-nameplate-art.js). The scene itself is native: itemcash Type 0
 *  Code 16/30 EventType -> property/effect/effectscene cate 8 ("UI") scene 1, its controls, keys, units, textures and blends.
 *  The Global data holds no nameplate binding for it (no UI script, modeleffect row or @<effectui> tag), so the values below
 *  attach that native scene to the nameplate emblem. */
export const GUILD_GLORY_ART_CHOSEN = Object.freeze({
  /** ENGINE-CHOSEN (not in Global data): one pass of the scene's normalized 0..1000 timeline lasts 1000 ms and repeats while the
   *  Glory item is registered (the most common cate-8 eff_time in script/effect/modeleffect.csv: 6 of 11 rows are 1000 ms). */
  CYCLE_MS: 1000,
  /** ENGINE-CHOSEN (not in Global data; derived from it): the emblem's edge is the scene coordinate +-0.3. Native UI-attached cate-8
   *  scenes appear to be scaled per control so authored edge coordinates land on the control's edges (8:1125's top/bottom highlight
   *  lines at y +.07/-.08 meet the 35/41 px button edges when the script's 5th "effect" value 500/580 is read as the px width of 2
   *  scene units; that reading is an inference), and every Glory scene draws its border
   *  at +-0.27..0.31: 3019 side flashes and 3022 side lines at +-0.3, 3004/3007/3017 corner lights at (-0.3,0.29..0.35), 3004's
   *  orbit at +-0.31, 1104's corner stars at +-0.27, the GuildMark_line_01# frame's peak at +-0.2945 and mark_eff_26's at +-0.29.
   *  So one scene unit = emblem side / 0.6 (18 px base -> 30 px; the 24 px Glory crest -> 40 px on screen). */
  EMBLEM_BORDER_UNITS: 0.3,
  /** ENGINE-CHOSEN (not in Global data): the effect draws over the whole emblem (background and symbol), its 'add' units as added
   *  light (CSS plus-lighter), the way a UI-attached cate-8 effect draws over its control (8:1125's flash is only visible on top
   *  of its opaque button). The nameplate draw order itself is executable behaviour. */
  DRAW_OVER_EMBLEM: true,
  // Native startpositions are preserved, including Majesty x -0.7 and Best Guild x -0.8 beside the crest.
  /** ENGINE-CHOSEN (not in Global data): backing-store cap and the farthest scene distance kept on the canvas (Melody 3024's notes
   *  start 1 unit out and fly up to 2 s at 1 unit/s; Flash 3019's size-3 side beams, Darkness 3020's streaks, Purple Crack 3025's x6 crack and
   *  Best Guild 1120's x5 particles also reach it). 4 units = 160 on-screen px from the 24 px crest centre; ink beyond is clipped. */
  MAX_DPR: 2,
  MAX_EXTENT_UNITS: 4,
  /** ENGINE-CHOSEN (not in Global data): longest particle integration step; a plate hidden longer resumes from its live state. */
  MAX_STEP_MS: 100,
});

/** Member list / member info. */
export const GUILD_MEMBER_CHOSEN = Object.freeze({
  /** ENGINE-CHOSEN (not in Global data): "Last Login" (130:160) = the last time the host saw the member online (it records the
   *  time while the member is online, committed with the next guild write); an online member shows "Online". */
  LAST_LOGIN: 'last seen online by the host',
  LAST_SEEN_STEP_MS: 60_000,
  /** ENGINE-CHOSEN (not in Global data): "Current Location" (130:77) of an online member = their map name; offline: 130:482 None. */
  LOCATION: 'map name while online',
  /** GLOBAL + ONLINE (LANE-61): Guild storage = the guild's DIL treasury (Global DIL Donation 130:326-353, Asset Info "Guild DIL"),
   *  spent by guild skills (Pay_Dil) and war declarations (ONLINE WAR_SOURCE_URL: war costs come from the guild DIL; dekarons.com guild
   *  wiki: DIL is donated in 100,000 units). The Global data has no guild item warehouse (no window, NPC role or string). */
  STORAGE: 'guild DIL treasury',
});

