// Character transfer ("Character Move"): game2/chartradewnd (ui_chartradewnd "Transfer Character"
// 100:85, ui_chartradeinfownd "Character Transfer Information" 100:84, ui_invitechartrade 100:37) and
// msgbox/ui_chartradeinvite (100:38 + 556:58), strings stringtable_chartrade 556:0-60, player menu 240:103.
// Values the shipped client data does not contain. Every value here is ENGINE-CHOSEN (not in Global data): the
// original server and its web-site authorization (556:56) are not shipped. Shared by the host
// (server/world/char-trade.mjs, server/accounts/char-transfer.mjs) and the client (src/systems/chartrade).
export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';
export const CHAR_TRADE_ENGINE_CHOSEN = Object.freeze({
  tag: ENGINE_CHOSEN_TAG,
  // who: the requester GIVES one of their account's characters ("wants to transfer his character to you" 556:58),
  // the invited player receives it (556:1 "is receiver of Character.") and may pay with items + DIL
  sellerIsRequester: true,
  // which characters can move: the seller's other server characters (never the one being played, so the moved
  // character is always offline); none -> 556:12 "No tradeable character."
  movePlayedCharacter: false,
  // a character still referenced by shared records (guild roster, mail, listings, receipts ...) keeps those records
  // valid only on its account: it is refused with 556:50 "This character is restricted from transfer."
  refuseReferencedCharacters: true,
  receiverMaxCharacters: 100,   // = the account character limit of character creation; full -> 556:49
  range: 12,                    // cells between the two players (= the item trade)
  inviteMs: 60000,              // invitation lifetime (= the item trade)
  sessionMs: 300000,            // open window lifetime, renewed by every change (= the item trade)
  safetyMs: 5000,               // both confirmed -> conditions locked (556:39), Approve after this safety time
  noTradeInInstances: true,     // instanced maps (dungeons, events) refuse with 556:37
  paymentGrid: Object.freeze({ cols: 10, rows: 5 }),   // payment items fit the 10 x 5 grid of the item trade
  maxPaymentDil: 10_000_000_000,
  // after the move both players stay connected (the original logs the seller out to save, 556:14 / 556:59; the
  // engine store commits the move and both profiles in one write): seller 556:40, receiver 556:15
  logoutAfterMove: false,
  // lbl_charInfo (multiline, 187 x 51) keeps the original one stat line per 556:16-29 string; the lines that do not
  // fit its rect scroll with the wheel (the only gap: the shipped client's overflow behaviour is not in the data)
  charInfoColumns: 1,
  // which strings each step shows (stringtable_chartrade 556)
  msg: Object.freeze({ cancelled: 41, done: 40, received: 15, noCharacter: 12, restricted: 50, slotsFull: 49, inventoryFull: 42,
    failed: 43, self: 54, trading: 52, otherBusy: 53, busy: 38, map: 37, notFound: 55, confirmFirst: 45, wait: 36, locked: 39, requesting: 57, wants: 58 }),
});