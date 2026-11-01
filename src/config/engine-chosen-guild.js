import {SERVER_TIME_OFFSET_MINUTES} from '../game/server-time.js';
// ENGINE-CHOSEN guild-family values: every value in this module is tagged ENGINE-CHOSEN (not in Global data). The shipped Global
// client data (data/unpacked/data, re-checked against an untouched Global client install) does not
// define them; they are server rules of the original game. Each one is a reasonable engine value, kept here in ONE place so it can be
// replaced the moment a real value is known. Everything that IS in the data stays in the *-rules.js modules with its source.

/** Alliance (ALLIANCE gate: server/world/alliance.mjs, src/systems/extras/alliance.js). */
export const ALLIANCE_CHOSEN = Object.freeze({
  /** ENGINE-CHOSEN (not in Global data): lifetime of an alliance formation / admission request (ui_alliancerequest.txt and
   *  ui_allianceinvitewnd.txt draw a progress bar but the data holds no duration). Same 60 s as the engine's guild invitations. */
  INVITE_TIMEOUT_MS: 60_000,
  /** ENGINE-CHOSEN (not in Global data): the requester names the alliance (ui_alliancename.txt) after the target accepted; the
   *  naming step expires after this long (140:61 "The Alliance formation has been cancelled."). */
  NAMING_TIMEOUT_MS: 120_000,
  /** ENGINE-CHOSEN (not in Global data): "Alliance Executives" (140:81, 140:112) = the Guild Masters of the member guilds. */
  EXECUTIVES: 'member guild masters',
  /** ENGINE-CHOSEN (not in Global data): only the Alliance Commander edits the notice (140:85 names a permission, no table). */
  NOTICE_EDITOR: 'commander',
  /** ENGINE-CHOSEN (not in Global data): only the Alliance Commander changes / deletes the alliance mark (140:71 / 140:74). */
  MARK_EDITOR: 'commander',
  /** ENGINE-CHOSEN (not in Global data): the original opens the request from the target guild master's player menu (not in the
   *  scripts); the engine uses chat commands next to the existing /ginvite: /ainvite <character>, /aleave. */
  COMMANDS: Object.freeze({ invite: '/ainvite', leave: '/aleave', window: '/awin' }),   // '/alliance' and '/a' are chat channel words
  /** ENGINE-CHOSEN (not in Global data): when the commander's guild leaves (after delegating) nothing else changes; when an
   *  alliance falls below 2 guilds (helper 1746) it is disbanded and its mark is removed with it (no refund of the 2,000,000 DIL). */
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
  /** ENGINE-CHOSEN (not in Global data): who may press Enable Skill (130:418 names an authority but no rank table): the Guild Master. */
  ENABLER: 'guild master',
  /** ENGINE-CHOSEN (not in Global data): replacing the running guild skill (130:373) refunds nothing of the old skill's cost. */
  REPLACE_REFUND: 0,
  /** ENGINE-CHOSEN (not in Global data): the skill's status (Status_ID) runs on every guild member, online now or on their next
   *  login, until its Apply_Sec ends; leaving / being expelled from the guild removes it. */
  MEMBERS: 'every member while the skill runs',
  // The guild-level DIL reduction is NOT engine-chosen: official Global guide 5 gives levels 11-15 = 5/7/10/12/15 % and the
  // skill window has lbl_dil_discount (src/systems/extras/guildextras-rules.js SKILL_DIL_DISCOUNT).
});

/** Guild war declaration / acceptance. Durations 3 / 7 / 15 / 30 days ARE in the data (135:100..103). */
export const GUILD_WAR_CHOSEN = Object.freeze({
  /** ENGINE-CHOSEN (not in Global data): 135:25 shows "Required DIL" and "Required Guild Points" without a table: per war day,
   *  paid at declaration from the guild's DIL (the guild treasury of the DIL Donation) and the guild's Guild Points. */
  COST_PER_DAY: Object.freeze({ dil: 1_000_000, guildPoints: 1 }),
  /** ENGINE-CHOSEN (not in Global data): open (pending + active) declarations a guild may have made (135:9). */
  MAX_DECLARATIONS: 3,
  /** ENGINE-CHOSEN (not in Global data): open wars a target guild may be in (135:37). */
  MAX_TARGET_WARS: 3,
  /** ENGINE-CHOSEN (not in Global data): who declares (135:8) / accepts or surrenders (135:38): the Guild Master. */
  AUTHORITY: 'guild master',
  /** ENGINE-CHOSEN (not in Global data): an unanswered declaration lapses after 24 h and counts as rejected (a loss, 135:26). */
  PENDING_TIMEOUT_MS: 86_400_000,
  /** ENGINE-CHOSEN (not in Global data): "current area" of 135:6 / 135:39: no declaration from inside an instance (dungeon,
   *  DK Square, siege); the target must be a character on the declarer's map. */
  AREA_RULE: 'not inside an instance; target on the same map',
  /** ENGINE-CHOSEN (not in Global data): the original's war fighting rules are server code. In the engine, members of two
   *  guilds at an ACTIVE war (status 135:111) are hostile to each other (server/world/guild-war-pvp.mjs registerPvpMode): basic
   *  attacks and skills hit them with the PvP damage of src/game/pvp-rules.js (pvpDamage, shield first), a down is an ordinary
   *  death (profile.deaths, the normal revive), and the kill counts once for the killer's guild on the war record. */
  COMBAT: 'active wars are hostile on PvP-allowed open maps; pvp-rules.js damage; kills recorded on the war',
  /** ENGINE-CHOSEN (not in Global data): where war members may fight: maplist IsPvP 1 and PVP_PeaceZone 0, never inside an
   *  instance (dungeon, DK Square, event run). Towns (IsPvP 0, e.g. Braiken 0, Loa 7, Ardeca 150) stay safe. */
  COMBAT_MAP: Object.freeze({ isPvP: 1, pvpPeaceZone: 0, instances: false }),
  /** ENGINE-CHOSEN (not in Global data): a war kill = the character who landed the last PvP hit (pvpLastHit) belongs to the
   *  other guild of an active war with the downed character's guild; one count per death, stored as war.kills[guildId]. */
  KILL_CREDIT: 'last PvP hitter, once per death',
  /** ENGINE-CHOSEN (not in Global data): kills wait in host memory and are folded into the durable war record by the next guild
   *  write or the host war tick (at most KILL_FLUSH_MS later). */
  KILL_FLUSH_MS: 2_000,
  /** ENGINE-CHOSEN (not in Global data): there is no original kill notice string; the war board / War Status show "kills : kills"
   *  and both guilds get this system line. */
  KILL_NOTICE: '[Guild War] %s defeated %s.',
  /** ENGINE-CHOSEN (not in Global data): besides the player menu (pcpop 240:13) a chat command declares on a named character. */
  COMMAND: '/gwar',
  /** ENGINE-CHOSEN (not in Global data): closed wars kept per guild for War Status (newest first). */
  HISTORY_LIMIT: 50,
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
  /** ENGINE-CHOSEN (not in Global data): Guild storage = the guild's DIL treasury (DIL Donation, Asset Info "Guild DIL"), spent by
   *  guild skills (Pay_Dil) and war declarations. The Global data has no guild item warehouse (no window, NPC role or string). */
  STORAGE: 'guild DIL treasury',
});

