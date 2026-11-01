// Character name change + guild name change: the original item flows. Shared by the client windows (namechange.js) and the
// host (server/world/name-change.mjs + the guild 'rename' operation of server/world/guilds.mjs). Every rule and its source:
//   items   share/item/itemcash.csv Type 0 Code 23 = character name change ('Change Character Name' 1752274/1761544, 'New Namer
//           Seed' 60135, 'New Name Seed' 1761903; description 20:352) and Type 0 Code 80 = 'Guild Name Change' (1761059, 1761543,
//           1761902; description 20:1864 "Only usable by guild leader. Maximum length of 20 characters. Cannot be used if guild
//           currently owns Siege castle. Cannot be used by dead characters. Cannot select a name already in use.").
//   windows game2/changecharname/ui_changecharnamewnd.txt (edt_name maxlength 20), game2/msgbox/ui_changecharnameconfirm.txt,
//           ui_changecharnamecaution.txt, ui_changecharnameerror.txt; game2/changeguildname/ui_changeguildnamewnd.txt (edt_name
//           maxlength 20), game2/msgbox/ui_changeguildnameconfirm.txt.
//   texts   string/cash/stringtable_cashitem.txt 170:6 name/level/class, 170:8 + 170:89 prompts, 170:10 conditions, 170:11 redirect
//           notice, 170:40..44 + 170:46 refusals, 170:88 guild name line; string/normal/stringtable_guild.txt 130:7 / 130:8 / 130:23 /
//           130:310 / 130:315 / 130:318; string/normal/stringtable_loginmsg.txt 30:51 / 30:52 / 30:54 / 30:59 (the character
//           creation messages, reused for the new name).
// NAME_TEXT holds the English text of those refusal strings for the host's error messages; tools/test-name-change.mjs asserts
// every entry equals the original string table (markup removed), so no message is invented.
import { normalizeCharacterName, characterNameKey } from '../../game/character-name.js';

export const CHAR_NAME_ITEM_CODE = 23;
export const GUILD_NAME_ITEM_CODE = 80;
// Guild name changes: msgbox/ui_guildchangenamecaution 130:313 + 130:314 "Changed: <VALUE>/1 Time" (one change), refusal 130:317;
// Guild Master's Mistake (Type 0 Code 27, title 100:19) resets the history: msgbox/ui_guildchangenameclearcount 170:14 "This will
// allow you to change the guild name for 1 time", refused while nothing changed (130:316 "The Guild Name has changed 0 times.").
export const GUILD_MISTAKE_ITEM_CODE = 27;
export const GUILD_NAME_CHANGES_MAX = 1;
export const NAME_MAX = 20;   // edt_name maxlength of both name-change windows (and 20:1864 "Maximum length of 20 characters")

export const SCRIPTS = {
  charName: 'game2/changecharname/ui_changecharnamewnd.txt',
  charConfirm: 'game2/msgbox/ui_changecharnameconfirm.txt',
  charCaution: 'game2/msgbox/ui_changecharnamecaution.txt',
  charError: 'game2/msgbox/ui_changecharnameerror.txt',
  guildName: 'game2/changeguildname/ui_changeguildnamewnd.txt',
  guildConfirm: 'game2/msgbox/ui_changeguildnameconfirm.txt',
  guildCaution: 'game2/msgbox/ui_guildchangenamecaution.txt',
  guildClearCount: 'game2/msgbox/ui_guildchangenameclearcount.txt',
};

/** [cate, code] of every text the flows show (NORMAL group). */
export const NAME_STRINGS = {
  charLine: [170, 6], charPrompt: [170, 8], conditions: [170, 10], redirect: [170, 11],
  sameName: [170, 40], friends: [170, 41], guild: [170, 42], party: [170, 43], expedition: [170, 44], map: [170, 46],
  guildLine: [170, 88], guildPrompt: [170, 89],
  guildNameTaken: [130, 7], guildNameInvalid: [130, 8], noGuild: [130, 23], guildRetyped: [130, 310], guildLeaderOnly: [130, 315],
  guildCount: [130, 318], guildChangeAsk: [130, 313], guildChanged: [130, 314], guildZeroChanges: [130, 316], guildLimit: [130, 317],
  guildResetAsk: [170, 14],
  nameEmpty: [30, 51], nameWord: [30, 52], nameChars: [30, 54], nameTaken: [30, 59],
};

/** Plain text of the refusal strings (asserted against the string tables by the test). */
export const NAME_TEXT = {
  sameName: "This name is identical to the character's current one.",
  friends: 'The character still has friends remaining in the Friend List.',
  guild: 'The character is in a Guild.',
  party: 'The character is in a Party.',
  expedition: 'The character is in an Expedition.',
  guildNameTaken: 'The guild name is already in use.',
  guildNameInvalid: 'The guild name cannot be used.',
  noGuild: 'You are not in a guild.',
  guildLeaderOnly: 'Only the Guild Leader can use this menu.',
  guildZeroChanges: 'The Guild Name has changed 0 times.',
  guildLimit: 'You have exceeded the maximum limit for changing the Guild Name.',
  nameEmpty: 'Please enter a character name.',
  nameChars: 'Only alphanumeric characters can be used.',
  nameTaken: 'This name is already in use.',
};

const itemCode = (def, code) => !!def && Number(def.type) === 0 && Number(def.code) === code;
export const isCharNameItem = def => itemCode(def, CHAR_NAME_ITEM_CODE);
export const isGuildNameItem = def => itemCode(def, GUILD_NAME_ITEM_CODE);
export const isGuildMistakeItem = def => itemCode(def, GUILD_MISTAKE_ITEM_CODE);

/** Character-side conditions of 170:10 / 20:352. Returns the NAME_STRINGS key or null. An expedition corp is also a party,
 *  so the expedition (170:44) is named before the party (170:43). */
export function charNameBlocker({ party = false, expedition = false, guild = false, friends = 0 } = {}) {
  if (expedition) return 'expedition';
  if (party) return 'party';
  if (guild) return 'guild';
  if (Number(friends) > 0) return 'friends';
  return null;
}

/**
 * Validate a new character name: the character creation rules (src/game/character-name.js) within the window's
 * maxlength 20, not the current name, no word of script/producer/filtering.txt (as at creation: create.js validateName).
 * Returns {name} or {error: NAME_STRINGS key, word?}.
 */
export function checkNewCharacterName(value, { current = '', filter = [] } = {}) {
  if (!String(value ?? '').trim()) return { error: 'nameEmpty' };
  let name;
  try { name = normalizeCharacterName(String(value)); } catch { return { error: 'nameChars' }; }
  if ([...name].length > NAME_MAX) return { error: 'nameChars' };
  const key = characterNameKey(name);
  if (current && key === characterNameKey(current)) return { error: 'sameName' };
  const word = (filter || []).find(w => /^[a-z0-9]+$/.test(w) && key.includes(w));
  if (word) return { error: 'nameWord', word };
  return { name };
}

/** Validate a new guild name: 1..20 characters (20:1864 / edt_name maxlength 20), no control characters, not taken. */
export function checkNewGuildName(value, { taken = () => false } = {}) {
  const name = typeof value === 'string' ? value.normalize('NFC').trim() : '';
  if (!name || [...name].length > NAME_MAX || /[\p{Cc}\p{Cf}\p{Cs}]/u.test(name)) return { error: 'guildNameInvalid' };
  if (taken(name.toLowerCase())) return { error: 'guildNameTaken' };
  return { name };
}

/** Fill the <NAME> / <VALUE> / <CLASS> placeholders of 170:6 / 170:11 / 170:88. */
export function fillName(text, { name = '', level = '', className = '' } = {}) {
  return String(text ?? '').replace(/<NAME>/g, name).replace(/<VALUE>/g, String(level)).replace(/<CLASS>/g, className);
}
