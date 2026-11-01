// World chat / shout / super chat (Megaphone) rules, shared by the host (server/world/social.mjs, megaphone.mjs)
// and the client (hud-options/chat.js, superchat.js). Every value below comes from the client data:
//   * stringtable_chat 230:69 "You can Shout only once every 10 seconds."                      -> SHOUT_COOLDOWN_MS (map shout '!')
//   * 230:90 "World chat can be used once every 30 seconds. (<TIME>~ seconds left)" and share/formula.ini
//     dwShoutDelay 30000 (bShout 1 = enabled)                                                   -> WORLD_CHAT_COOLDOWN_MS (world '%')
//   * 230:89 names a world chat item "purchased from merchant NPC": share/item/*.csv has no such item (no name, no item
//     code), so world chat needs no item here (documented reading).
//   * Megaphone = item Type 0 Code 38 (itemdesc 104:38, name 173:38, notes 174:38, item description 294), DK Megaphone =
//     Code 39 (173:39, 174:39, 295). 294: "all regions across the same server will be able to send messages (Except DK
//     Server)"; 295: "To deliver messages in DK Server, Megaphone must be used in the DK Server"; 174:38 note 2 "only
//     while in the Normal maps (Cannot be used in the DK areas)", 174:39 note 1 the reverse. A DK area = a DK channel
//     (share/dkmaplist.csv, server/world/channels.mjs), so the Megaphone works off DK channels and reaches every
//     player who is not on a DK channel; the DK Megaphone works only on a DK channel and reaches that DK server.
//   * 174:38 note 6 "You can broadcast the same message up to 5 times. (5 Megaphones consumed)"  -> MEGAPHONE_MAX_REPEAT,
//     one Megaphone per broadcast; 294 caution (4) "Same messages can only be sent 5 times a day" -> MEGAPHONE_SAME_PER_DAY;
//     174:38 note 4 "displayed in order that they are submitted" -> one server-wide FIFO; note 5 "If the server is
//     terminated ... pending Megaphone broadcasts are deleted" -> the queue lives in memory only.
//   * window game2/chat/ui_superchatinputwnd.txt: lbl_title 100:126 / 100:127, pan_megaphone imagetable megaphone 2 / 3,
//     edt_input maxlength 160, btn_left / btn_right + lbl_repeat, btn_open -> pan_color (8 swatches btn_color_1..8, the
//     colours sampled from texture/ui/game/chat/megaphone.dds at the cells of imagetable megaphone 4), btn_enter,
//     btn_exit, btn_type (IME toggle, 230:78 "ENG"). Caution box 80:69 + 81:69 (Megaphone), 80:70 + 81:70 (DK Megaphone).
//     Results 170:59 sent, 170:60 failed, 175:1 "Not a usable map.", 175:2 "You do not have the item.".
//   * window game2/chat/ui_superchatwnd.txt: pan_output (20 px band), pan_pop name pop-up lbl_name + btn_invite 240:4,
//     btn_whisper 240:3, btn_friend 240:1 (294: "When character's name is clicked ... invite party, whisper, and request
//     to add to friend list").
// Engine choices (the data gives no value): one broadcast is on the band for MEGAPHONE_SLOT_MS and the queue releases the
// next one after it; the default colour is the white swatch (8); "a day" is the UTC calendar day; the caution box is the
// confirmation before each broadcast.
export const SHOUT_COOLDOWN_MS = 10000;
export const WORLD_CHAT_COOLDOWN_MS = 30000;
export const MEGAPHONE_CODES = Object.freeze({ 38: 'normal', 39: 'dk' });
export const MEGAPHONE_MAX_TEXT = 160;
export const MEGAPHONE_MAX_REPEAT = 5;
export const MEGAPHONE_SAME_PER_DAY = 5;
export const MEGAPHONE_SLOT_MS = 10000;
/** btn_color_1..8 (sampled from megaphone.dds, imagetable megaphone 4: 4 x 2 cells of 20 px at 1,1). */
export const MEGAPHONE_COLORS = Object.freeze(['ff0000', 'f3fc00', '00fff6', '6495ed', '00ff00', 'ff9c00', 'ff00ff', 'ffffff']);
export const MEGAPHONE_DEFAULT_COLOR = 7;
export const SUPERCHAT_SCRIPTS = Object.freeze({ input: 'game2/chat/ui_superchatinputwnd.txt', output: 'game2/chat/ui_superchatwnd.txt' });
/** Client string ids (group NORMAL). */
export const SUPERCHAT_STRINGS = Object.freeze({
  shoutWait: [230, 69], worldWait: [230, 90], worldItem: [230, 89], eng: [230, 78],
  title: { 38: [100, 126], 39: [100, 127] }, name: { 38: [173, 38], 39: [173, 39] }, notes: { 38: [174, 38], 39: [174, 39] },
  cautionTitle: { 38: [80, 69], 39: [80, 70] }, caution: { 38: [81, 69], 39: [81, 70] },
  sent: [170, 59], failed: [170, 60], badMap: [175, 1], noItem: [175, 2],
  invite: [240, 4], whisper: [240, 3], friend: [240, 1],
});
/** The host's copies of those strings (tools/test-superchat.mjs checks them against the string tables). */
export const SUPERCHAT_TEXT = Object.freeze({
  shoutWait: 'You can Shout only once every 10 seconds.',
  worldWait: 'World chat can be used once every 30 seconds. (<TIME>~ seconds left)',
  sent: 'Megaphone broadcast sent.',
  failed: 'Failed to send Megaphone broadcast.',
  badMap: 'Not a usable map.',
  noItem: 'You do not have the item.',
});
export const worldWaitText = (msLeft, text = SUPERCHAT_TEXT.worldWait) => String(text).replace('<TIME>', String(Math.max(1, Math.ceil(msLeft / 1000))));
export const isDkChannelValue = channel => typeof channel === 'string' && /^dk\d+$/.test(channel);
/** "Same server" of 294 / 295: every non-DK channel is one server, each DK channel its own. */
export const serverScope = channel => isDkChannelValue(channel) ? channel : 'field';
export const megaphoneCode = def => (def && Number(def.type) === 0 && MEGAPHONE_CODES[Number(def.code)]) ? Number(def.code) : 0;
/** 175:1 when the item does not fit the area: the Megaphone off DK channels, the DK Megaphone on one. */
export function megaphoneMapBlocker(code, channel) {
  const dk = isDkChannelValue(channel);
  if (Number(code) === 38) return dk ? 'badMap' : null;
  if (Number(code) === 39) return dk ? null : 'badMap';
  return 'noItem';
}
/** Clean + validate one broadcast. Returns {text, color, repeat} or {error}. */
export function checkMegaphone({ text, color = MEGAPHONE_DEFAULT_COLOR, repeat = 1 } = {}) {
  if (typeof text !== 'string') return { error: 'failed' };
  const clean = text.replace(/[\x00-\x1f\x7f]/g, ' ').replace(/\s+/g, ' ').trim();
  if (!clean || clean.length > MEGAPHONE_MAX_TEXT) return { error: 'failed' };
  if (!Number.isInteger(color) || color < 0 || color >= MEGAPHONE_COLORS.length) return { error: 'failed' };
  if (!Number.isInteger(repeat) || repeat < 1 || repeat > MEGAPHONE_MAX_REPEAT) return { error: 'failed' };
  return { text: clean, color, repeat };
}
export const megaphoneDay = ms => new Date(ms).toISOString().slice(0, 10);
export const sameKey = text => String(text).toLowerCase();
/** How many more times this text may go out today (294 caution 4), given {day, sent: {key: n}}. */
export function sameLeft(state, text, now) {
  const day = megaphoneDay(now);
  const used = state?.day === day ? Number(state.sent?.[sameKey(text)]) || 0 : 0;
  return Math.max(0, MEGAPHONE_SAME_PER_DAY - used);
}
export function recordSame(state, text, count, now) {
  const day = megaphoneDay(now);
  const next = state?.day === day ? { day, sent: { ...(state.sent || {}) } } : { day, sent: {} };
  const k = sameKey(text);
  next.sent[k] = (Number(next.sent[k]) || 0) + count;
  return next;
}
