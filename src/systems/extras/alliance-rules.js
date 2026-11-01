// ALLIANCE: rules of the guild alliance, shared by the host (server/world/alliance.mjs) and the client
// (src/systems/extras/alliance.js). Original sources (read-only, data/unpacked/data):
//   cost      share/guild/alliance.csv MONEY 2,000,000 (formation, paid by the requester 140:44 / 140:58) and MARKDIL 100,000 (alliance
//             mark, 140:68 / 140:69).
//   limits    140:43 / 140:51 / 140:97 + help string 1744: guild Lv. 2 or higher; 140:94 + help 1744: at most 4 guilds; help 1746: the
//             alliance is disbanded when fewer than 2 guilds remain; 140:86: notice <= 800 characters (ui_alliancenoticewnd.txt
//             textbox maxlength 500 is the client edit limit); ui_alliancename.txt / ui_alliancechangeleaderwnd.txt edit maxlength 20.
//   maps      share/maplist.csv IsCreateAlliance (formation allowed, 140:137/138) and IsInviteAlliance (invitations allowed, 140:116/117/
//             140) per map (gamedata/dungeons.json maps[i].raw).
//   guild     130:218 a Guild Master who is the Alliance Commander cannot hand over the guild; 130:219/322 an allied guild cannot be
//             disbanded; 130:323 nor while it is forming / joining an alliance.
//   windows   game2/alliance/ui_alliancewnd.txt (guild window tab btn_alliance 140:1: A.Name 140:2, A.Cdr 140:3, mark 40x40, notice
//             box 130:58, member list No. 140:4 / Guild 140:5 / Guild Master 140:8 / Guildsman 140:11 btn_record rows 18 px +
//             memList_scroll, Edit Notice 140:19, Quit 130:55, row popup Delegate 140:17 / Expel Guild 140:18), ui_alliancerequest.txt
//             (requester waits, Cancel), ui_allianceinvitewnd.txt (target answers 140:12 / 140:16), ui_alliancename.txt (100:103,
//             A.Name), ui_alliancechangeleaderwnd.txt (100:108, type the name 140:113), ui_alliancenoticewnd.txt (100:43, Reset /
//             Register), ui_alliancemarkselect.txt + ui_alliancemarkconfirm.txt (100:104 / 100:105, guildbg + guildicon atlases as
//             the guild mark), NPC jobs 77 ALLIANCE_MARK / 78 DELETEALLIANCEMARK (Blake 135), chat '$' alliance channel 16
//             (140:112 executives only).
//   glory     itemcash Type 0 Code 30 "Alliance of Glory - ..." (1160001..1160015; stringtable_cash: only Alliance Commanders can
//             use) -> alliance effect 140:132 / 140:133, deleted at DELETEALLIANCEMARK 140:55 / 140:56 / 140:57, none 140:75.
// Values the data does not define live in src/config/engine-chosen-guild.js (ALLIANCE_CHOSEN, tagged ENGINE-CHOSEN).
export const SCRIPTS = {
  main: 'game2/alliance/ui_alliancewnd.txt', request: 'game2/alliance/ui_alliancerequest.txt', invite: 'game2/alliance/ui_allianceinvitewnd.txt',
  name: 'game2/alliance/ui_alliancename.txt', leader: 'game2/alliance/ui_alliancechangeleaderwnd.txt', notice: 'game2/alliance/ui_alliancenoticewnd.txt',
  mark: 'game2/alliance/ui_alliancemarkselect.txt', markConfirm: 'game2/alliance/ui_alliancemarkconfirm.txt',
};
export const JOB = { mark: 77, deleteMark: 78 };
export const MIN_GUILD_LEVEL = 2, MAX_GUILDS = 4, MIN_GUILDS = 2, NOTICE_MAX = 800, NOTICE_EDIT_MAX = 500, NAME_MAX = 20, ROW_HEIGHT = 18;
export const GLORY = { type: 0, code: 30 };
/** Original strings (stringtable_alliance.txt cate 140, stringtable_guild.txt cate 130). */
export const STR = {
  inviteAsk: [140, 12], declinedBy: [140, 13], cancelledOffline: [140, 14], joinedYou: [140, 15], invitedTo: [140, 16], invited: [140, 20],
  onlyCommanderInvite: [140, 22], newCommander: [140, 23], inviteArea: [140, 25], formCancelled: [140, 26], inviteCancelled: [140, 27],
  agreed: [140, 28], declined: [140, 29], youLeft: [140, 30], disbanded: [140, 31], youExpelled: [140, 32], expelled: [140, 33],
  joined: [140, 34], left: [140, 35], reqNoGuild: [140, 42], reqLevel: [140, 43], reqDil: [140, 44], reqBusy: [140, 45], reqSameGuild: [140, 46],
  reqInAlliance: [140, 47], reqNotMaster: [140, 48], targetBusy: [140, 49], noGuild: [140, 50], targetLevel: [140, 51], targetInAlliance: [140, 52],
  targetOffline: [140, 53], gloryDeleteAsk: [140, 55], gloryDeleteCancel: [140, 56], gloryDeleted: [140, 57], formed: [140, 58], nameTaken: [140, 59],
  nameBad: [140, 60], nameCancelled: [140, 61], markChanged: [140, 68], markDil: [140, 69], markNotMember: [140, 70], markPermission: [140, 71],
  gloryNotInAlliance: [140, 73], gloryDeletePermission: [140, 74], gloryNone: [140, 75], delegated: [140, 77], delegatePermission: [140, 79],
  delegateSame: [140, 80], delegateTarget: [140, 81], noticeChanged: [140, 83], noticeNotAllied: [140, 84], noticePermission: [140, 85],
  noticeLong: [140, 86], inviterNotCommander: [140, 92], full: [140, 94], targetForming: [140, 95], noExpel: [140, 101], expelPermission: [140, 103],
  expelCommander: [140, 104], leaveNoGuild: [140, 107], leaveNotAllied: [140, 108], leavePermission: [140, 109], leaveCommander: [140, 110],
  chatExecutives: [140, 112], delegateType: [140, 113], delegateMustType: [140, 114], targetCondition: [140, 115], targetMap: [140, 116],
  inviteMap: [140, 117], expelAsk: [140, 118], leaveAsk: [140, 119], requesterCancelled: [140, 120], admissionCancelled: [140, 125],
  noticeChangedAll: [140, 131], gloryChanged: [140, 132], gloryPermission: [140, 133], createCondition: [140, 137], createMap: [140, 138],
  inviteMapAny: [140, 140],
  guildCommanderTransfer: [130, 218], guildAlliedDisband: [130, 219], guildLeaveAllianceFirst: [130, 322], guildFormingDisband: [130, 323],
};
/** Host-side plain English of the codes the host answers with (= the original text without markup; checked by the test). */
export const TEXT = {
  reqNoGuild: 'The Alliance requester is not in a guild.', reqLevel: "The Alliance requester's guild has not yet reached Level 2.",
  reqDil: 'The Alliance requester does not have enough dil.', reqBusy: 'The Alliance requester already invited you or his guild is currently being invited to another Alliance.',
  reqSameGuild: 'The Alliance requester is in your guild.', reqInAlliance: 'The Alliance requester is already in an Alliance.', reqNotMaster: 'The Alliance requester is not a guild master.',
  targetBusy: 'You already invited the guild or the guild is currently being invited to another Alliance.', noGuild: 'No guilds are available to invite.',
  targetLevel: 'The guild has not yet reached Level 2.', targetInAlliance: 'The guild is already in an Alliance.', targetOffline: "The guild's master is not online.",
  nameTaken: 'This Alliance name already exists.', nameBad: 'This Alliance name is not allowed.', markDil: 'There is not enough dil.',
  markNotMember: 'You are not a member of the Alliance.', markPermission: 'You do not have permission to change the Alliance Mark.',
  gloryNotInAlliance: 'You are not in the Alliance.', gloryDeletePermission: 'You do not have the Delete permission.', gloryNone: 'You do not have an Alliance Mark effect item.',
  delegatePermission: 'You do not have permission to delegate the Alliance Commander authority.', delegateTarget: 'The target is not an executive of the Alliance or is not online.',
  noticeNotAllied: 'You are not allied; you cannot register the notice.', noticePermission: 'You do not have permission to change the notice.',
  noticeLong: 'A notice cannot be longer than 800 characters.', onlyCommanderInvite: 'Only Alliance Commanders can invite guilds.', full: 'An Alliance can contain only up to 4 guilds.',
  targetForming: 'The guild is currently being formed or has been invited to a different Alliance.', noExpel: 'No guilds are available to expel.',
  expelPermission: 'You do not have the Expel permission.', expelCommander: 'Cannot expel the guild of the Alliance Commander.', leaveNoGuild: 'You are not in a guild.',
  leaveNotAllied: 'You are not in the Alliance.', leavePermission: 'You do not have permission to leave the Alliance.',
  leaveCommander: 'Alliance Commanders cannot leave until they delegate their commander authority to someone else.', chatExecutives: 'Only Alliance Executives can use Alliance chat.',
  targetCondition: "The guild's master has not satisfied the condition to accept the Alliance invitation.", targetMap: "The requester/requestee guild's master is in a map in which Alliance invitation is not available.",
  inviteMap: 'You cannot invite guilds to your Alliance while in the current map.', gloryPermission: 'You do not have permission to change the Alliance effect.',
  createMap: 'You can only form an Alliance while in Braiken or Loa Castle.', guildCommanderTransfer: 'Cannot delegate if the Guild Master is the Alliance Commander.',
  guildAlliedDisband: 'Allied guilds cannot be disorganized.', guildFormingDisband: 'Guilds cannot be disorganized while creating/joining an Alliance.',
  delegateSame: 'The target\u2019s name is identical to the current Alliance Commander\u2019s.',
};
/** Original string markup -> plain text (colors, %s / %d / %lld kept for the caller). */
export const plain = s => String(s ?? '').replace(/<[^>]+>/g, '').replace(/\[message\]/gi, '').replace(/\\\\|\\/g, '\n').trim();
/** printf-style fill of %s / %d / %lld in order. */
export function fill(s, ...args) { let i = 0; return String(s ?? '').replace(/%(lld|d|s)/g, () => String(args[i++] ?? '')); }
/** share/maplist.csv alliance flags of a map (gamedata dungeons.json maps[i].raw). */
export function mapAllianceFlags(maps, index) { const raw = maps?.[String(index)]?.raw || {}; return { create: raw.IsCreateAlliance === '1', invite: raw.IsInviteAlliance === '1' }; }
/** Is this item an Alliance of Glory (itemcash Type 0 Code 30)? */
export const isGloryItem = def => !!def && Number(def.type) === GLORY.type && Number(def.code) === GLORY.code;
