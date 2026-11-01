// Player mailbox rules shared by the online host (server/world/mail.mjs) and the solo mailbox (src/systems/life/mail.js).
// AUTHENTICATED NATIVE RULES only; each value names its source:
//   script/string/normal/stringtable_mail.txt (cate 250) and the official Global Mailbox guide
//   (webapi-dekaron.ubifungames.com/gameGuide/GetGameGuidePost?guideNo=25).
// Recorded source conflicts (not resolved here): guide 25 section 3 says received letters "are kept for 30 days" while its
// section 1 and 250:16 say 15 days (the client string wins: mail-policies.mjs INBOX_RETENTION_MS); guide 25 says DIL cannot be
// received above a 1,000,000,000 holding, but the engine-wide balance cap is 10,000,000,000 (server/world/inventory.mjs
// addDil), a cross-cutting choice this module does not change.

/** 250:20 "Postage: 100 DIL"; guide 25 "The shipping fee is 100 DIL." */
export const MAIL_POSTAGE_DIL = 100;
/** Guide 25 "The attached amount is limited to a maximum of 100 million DIL." (quick buttons 250:17-19: 1 M / 100000 / 10000). */
export const MAIL_ATTACH_DIL_MAX = 100_000_000;
/** 250:73 "Sent Mail box will save up to 10 recent mails." */
export const MAIL_SENT_KEEP = 10;

export const MAIL_TEXT = Object.freeze({
  noRecipient: 'Please type in the receiver.',        // 250:28
  notFound: 'Cannot find the recipient.',             // 250:36
  noDil: 'You don\'t have enough Dils.',              // 250:31
  sent: 'Mail has been sent.',                        // 250:35
  attachMax: 'The attached amount is limited to a maximum of 100,000,000 DIL.',   // guide 25 (no client string)
  deleteItem: 'The mail cannot be deleted because it has an item attachment.',  // 250:64
  deleteDil: 'The mail cannot be deleted because it has a dil attachment.',     // 250:65
  dilFull: 'Exceeded the maximum DIL you can possess.', // 250:27
});

/** Validate the DIL a player attaches (whole, 0..MAIL_ATTACH_DIL_MAX). Returns an error text or null. */
export function mailAttachError(dil) {
  if (!Number.isSafeInteger(dil) || dil < 0) return 'Enter a whole DIL amount.';
  return dil > MAIL_ATTACH_DIL_MAX ? MAIL_TEXT.attachMax : null;
}
/** Total a sender pays: the attached DIL plus the flat postage (no percentage tax exists in the original). */
export const mailSendCost = dil => dil + MAIL_POSTAGE_DIL;
/** Keep the most recent MAIL_SENT_KEEP sent records (oldest dropped first). */
export const trimSent = list => list.slice(-MAIL_SENT_KEEP);
/** Why a received mail cannot be deleted yet (250:24 / 250:64 / 250:65), or null. */
export function mailDeleteError(record) {
  if (record?.attachment || record?.item) return MAIL_TEXT.deleteItem;
  if (record?.dil) return MAIL_TEXT.deleteDil;
  return null;
}
