// Rules shared by the host (server/world/guild-extras.mjs) and the client (src/systems/extras/guildextras.js) for the
// guild remainder: guild skills, the member list / member info / delegate windows, online member state and guild war
// declaration / acceptance. Sources (all in the shipped Global client data):
//   share/guild/guildskill.csv (72 rows; gamedata life.json guild.skills: id, group, level, name, desc, icon, needLevel, gpoint =
//     Pay_Gpoint, adv = Pay_ADvpoint, dil = Pay_Dil, status = Status_ID, sec = Apply_Sec)
//   skills_status 7160..7171 (StatusIndex of every guild skill): all in status group 125, so ONE guild skill runs at a time and a
//     new one replaces the current one (130:373 "The current Guild Skill will be removed, and the new skill effect will be applied.")
//   game2/guild/ui_gskillwnd_renew.txt (btn_item0 = Group 1 Fast Growth, btn_item1 = Group 2 Superior Combat; Level / Time
//     selectors; Cost GPoint / Point / Guild DIL; Asset Info), ui_guildmemberwnd.txt, ui_memberinfownd.txt, ui_delegatewnd.txt,
//   ui_guildwarhistorywnd.txt, game2/guildwar/ui_declarationofwarwnd.txt / ui_acceptanceofwarwnd.txt / ui_guildwarboardwnd.txt
//   (NPC role DECLARE_WAR, the Guild signs), stringtable_guild cates 130 / 135, pcpop 240:13 "Declare War".
// Values the data does not define: src/config/engine-chosen-guild.js GUILD_SKILL_CHOSEN / GUILD_WAR_CHOSEN / GUILD_MEMBER_CHOSEN.

export const SCRIPTS = {
  member: 'game2/guild/ui_guildmemberwnd.txt',
  memberInfo: 'game2/guild/ui_memberinfownd.txt',
  delegate: 'game2/guild/ui_delegatewnd.txt',
  skill: 'game2/guild/ui_gskillwnd_renew.txt',
  warHistory: 'game2/guild/ui_guildwarhistorywnd.txt',
  declare: 'game2/guildwar/ui_declarationofwarwnd.txt',
  accept: 'game2/guildwar/ui_acceptanceofwarwnd.txt',
  board: 'game2/guildwar/ui_guildwarboardwnd.txt',
};
/** The NPC service window name quests/services.js opens for role DECLARE_WAR (registered first by the client module). */
export const BOARD_WINDOW = 'npc_guildwarboard';
export const SKILL_ICON = 'guild_skillicon';   // imagetable guild_skillicon 107..118 (guildskill.csv IconID)
export const SKILL_GROUPS = [1, 2];            // btn_item0 / btn_item1
/** Original war durations: 135:100..103 (the ui_declarationofwarwnd list_selectday entries). */
export const WAR_DAYS = [3, 7, 15, 30];
export const WAR_DAY_CODES = [100, 101, 102, 103];
/** Host war states -> the 135:110..113 status words. A declined (or unanswered) declaration is a loss of the target (135:26). */
export const WAR_STATUS = { pending: 110, active: 111, surrendered: 112, ended: 113 };
export const MEMBER_ROWS = 21, HISTORY_ROWS = 19, BOARD_ROWS = 9, MY_BOARD_ROWS = 4, ROW_HEIGHT = 19, BOARD_ROW_HEIGHT = 24;

/** [cate, code] of every original string used (stringtable_guild 130 / 135, button 2000, title 100). */
export const STR = {
  inUse: [130, 462], enableSkill: [130, 360], applyAsk: [130, 371], replaceAsk: [130, 373], usedGpoint: [130, 376], usedPoint: [130, 377],
  usedDil: [130, 378], skillApplied: [130, 379], skillError: [130, 380], skillNoDil: [130, 413], skillNoPoint: [130, 414], skillNoGpoint: [130, 415],
  skillMissing: [130, 416], guildMissing: [130, 417], skillAuthority: [130, 418], skillLevel: [130, 419], day: [130, 355], time: [130, 356], minutes: [130, 357],
  none: [130, 482], delegatePrompt: [130, 225], chgGrade: [130, 74], kick: [130, 75], whisper: [130, 76], location: [130, 77], info: [130, 78], appoint: [130, 79],
  warDeclare: [135, 1], warAccept: [135, 2], declareAsk: [135, 3], noGuildPlayer: [135, 4], targetDead: [135, 5], warArea: [135, 6], targetNoGuild: [135, 7],
  declarePermission: [135, 8], declareMax: [135, 9], declareNoDil: [135, 10], declareNoGp: [135, 11], ownGuild: [135, 12], alliedGuild: [135, 13],
  alreadyAtWar: [135, 14], declaredOn: [135, 15], declareFailed: [135, 16], acceptAsk: [135, 21], surrenderAsk: [135, 22], boardLine: [135, 23],
  declareInfo: [135, 25], acceptInfo: [135, 26], warNotification: [135, 28], nDeclared: [135, 29], nBegun: [135, 30], nEnded: [135, 31],
  nSurrendered: [135, 32], atWarWith: [135, 33], disbandAtWar: [135, 34], renameAtWar: [135, 35], declinedNotice: [135, 36], targetMax: [135, 37],
  acceptPermission: [135, 38], dkSquare: [135, 39], historyLine: [135, 200], decline: [2000, 4], surrender: [260, 7],
};
/** Host refusal texts = the original strings without markup (the client shows the original string for a matching host message). */
export const TEXT = {
  skillNoDil: 'Insufficient DIL to purchase guild skill.', skillNoPoint: 'Insufficient Point to purchase guild skill.',
  skillNoGpoint: 'Insufficient Gpoint to purchase guild skill.', skillMissing: 'Guild skill does not exist.', guildMissing: 'Guild does not exist.',
  skillAuthority: 'You do not have the authority to request for selection.', skillLevel: 'Insufficient guild level to purchase guild skill.',
  noGuildPlayer: 'You cannot declare war on a player without a guild.', targetDead: 'You cannot declare war on a dead character.',
  warArea: 'War cannot be declared in the current area.', targetNoGuild: 'The target is not in a guild.',
  declarePermission: 'You don’t have permission to declare war.', declareMax: 'You have exceeded the maximum number of war declarations.',
  declareNoDil: 'Not enough DIL to declare war.', declareNoGp: 'Not enough guild points to declare war.',
  ownGuild: 'You cannot declare war on a member of your own guild.', alliedGuild: 'You cannot declare war on an allied guild.',
  alreadyAtWar: 'This guild is already at war.', declareFailed: 'Failed to declare war.',
  disbandAtWar: 'Cannot disband the guild during war declaration or active war.', renameAtWar: 'Guild name cannot be changed during pending or active war.',
  targetMax: 'Target guild has exceeded the maximum number of active wars.', acceptPermission: 'You don’t have permission to accept war.',
  dkSquare: 'You cannot declare war while participating in DK Square.',
};
export const plain = s => String(s ?? '').replace(/<[^>]+>/g, '').replace(/\[message\]/gi, '').replace(/\\\\|\\/g, '\n').trim();
export function fill(s, ...args) { let i = 0; return String(s ?? '').replace(/%(lld|d|s)/g, () => String(args[i++] ?? '')); }
/** 130:225 "To Appoint the Guild Mastership, please enter '<color>I appoint</color>'." -> the phrase the delegate must type. */
export function delegatePhrase(text) { const m = /'(?:<[^>]*>)*([^<']+)(?:<[^>]*>)*'/.exec(String(text || '')); return m ? m[1].trim() : ''; }

/** guildskill.csv rows of one group: {levels: [1..6], times(level) -> rows sorted by Apply_Sec}. */
export function skillGroup(rows, group) {
  const mine = (rows || []).filter(r => r.group === group);
  const levels = [...new Set(mine.map(r => r.level))].sort((a, b) => a - b);
  return { levels, times: level => mine.filter(r => r.level === level).sort((a, b) => a.sec - b.sec) };
}
export const skillById = (rows, id) => (rows || []).find(r => r.id === id) || null;
/** Guild skill DIL reduction by guild level. Official Global guide 5 (webapi-dekaron.ubifungames.com GetGameGuidePost?guideNo=5,
 *  "8. Guild Skill"): "Guild skill consumption DIL is reduced after guild level 11. Level 11 : 5% / 12 : 7% / 13 : 10% /
 *  14 : 12% / 15 : 15%". The shipped skill window has the matching controls: ui_gskillwnd_renew lbl_dil_discount and the
 *  pan_bottom_dil_desc columns 130:453 "Guild Level" / 130:454 "Reduction Rate" / 130:455 "Discount". Only Pay_Dil is reduced. */
export const SKILL_DIL_DISCOUNT = Object.freeze({ 11: 5, 12: 7, 13: 10, 14: 12, 15: 15 });
export const skillDilDiscount = level => SKILL_DIL_DISCOUNT[Number(level)] || 0;
/** The DIL a guild of `level` pays for a skill row: Pay_Dil minus the level's reduction, rounded down (ENGINE-CHOSEN rounding;
 *  every shipped Pay_Dil is a multiple of 100,000, so the listed percentages divide it exactly). */
export function skillDilCost(row, level) { const dil = Number(row?.dil) || 0; return Math.floor(dil * (100 - skillDilDiscount(level)) / 100); }
export function durationText(sec, words = {}) {
  const d = Math.floor(sec / 86400), h = Math.floor((sec % 86400) / 3600), m = Math.floor((sec % 3600) / 60);
  if (d) return `${d}${words.day || 'D'}`;
  if (h) return `${h}H`;
  return `${m}${words.minutes || 'M'}`;
}
/** Start / End Date of a declaration nobody answered: ONLINE (official JP notice 2025-07-04, GUILD_WAR_CHOSEN.PENDING_TIMEOUT_MS)
 *  it is accepted automatically when the reply time ends and then runs its full duration. */
export function autoAcceptTimes(w, pendingMs) {
  const startAt = w.declaredAt + pendingMs;
  return { startAt, endAt: startAt + (Number(w.days) || 0) * 86400000 };
}
/** Effective state of a host war record at `now` (pending past the reply time = automatically accepted, then ended after its
 *  duration; active past End Date = ended). A missing / non-finite pendingMs never resolves a pending war. */
export function warState(w, now, pendingMs) {
  if (!w) return null;
  if (w.status === 'pending' && Number.isFinite(pendingMs) && now >= w.declaredAt + pendingMs) return now >= autoAcceptTimes(w, pendingMs).endAt ? 'ended' : 'active';
  if (w.status === 'active' && now >= w.endAt) return 'ended';
  return w.status;
}
export const isOpenWar = (w, now, pendingMs) => ['pending', 'active'].includes(warState(w, now, pendingMs));
