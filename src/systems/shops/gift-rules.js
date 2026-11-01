// D-Shop "Send as Gift" rules shared by the D-Shop window (src/systems/shops/dshop.js) and the host
// (server/world/dshop-gifts.mjs).
//
// AUTHENTICATED NATIVE RULES (original client):
//   * entry: D-Shop Send as Gift (220:18) -> cashshop/ui_cashgiftwnd.txt: "Recipient:" (220:28) edit_text maxlength 20,
//     "Send a gift to the recipient entered above." (220:27); empty name -> 220:35 "No character name is entered.";
//     unknown name -> msgbox/cashitem/ui_errcharacter.txt 171:29 "No such character exists."
//   * confirmation: cashshop/ui_cashgiftconfirmwnd.txt 220:44 "[ %s ] will receive %s from you. Will you continue?";
//     msgbox/cashitem/ui_confirmgift.txt 171:28 "Caution: The duration of Limited-Time items begins its countdown upon
//     purchase." -> a limited item's period is counted from the purchase, not from the recipient's receipt
//   * account password, as for every D-Shop order (171:31, cashshop/ui_buypasswordwnd.txt; wrong -> 171:30)
//   * arrival: msgbox/cashitem/ui_resultgift_cashinventory.txt 171:43 "The gift has been sent to the recipient entered above.
//     Gifts are sent to the Cash Inventory." (the older ui_resultgift.txt 171:33 Mailbox variant is not the Cash Inventory
//     generation this client's D-Shop uses); the row shows "Purchaser: <NAME>" (900:2) = the sender, tagged Gift (171:27)
//   * the VIP shop window has no gift button (vipshop/ui_vipshopwnd_search.txt), so gifts are D-Shop only
//   * 220:38 #5 "You cannot withdraw gift items that you gave or have received." (no refund path; none exists in the engine)
// DELIBERATE ENGINE CHOICES (no original rule is shipped or published; each is refused rather than guessed):
//   * the sender's own character cannot be the recipient (use Buy); other characters of the same account may receive
//   * no recipient level / friend / guild restriction exists in the client data, so none is applied
//   * the buyer's purchase rules apply unchanged (D-Shop catalog row, Lv. limit 225:2 and Buy %d/%d limit 225:1 of the buyer)
//   * Holy Water of Almighty premium services are not giftable: their activation belongs to the recipient's profile, which a
//     gift escrow cannot change atomically with the buyer's payment
//   * at most GIFT_PENDING_MAX unaccepted gift rows wait per recipient; the recipient's client moves them into its Cash
//     Inventory (the existing 1,000-row cap), from where the existing receive path moves them to the bag
export const GIFT_NAME_MAX = 20;
export const GIFT_PENDING_MAX = 100;
export const GIFT_TEXT = Object.freeze({
  noName: 'No character name is entered.',                           // 220:35
  noCharacter: 'No such character exists.',                          // 171:29
  confirm: '[ %s ] will receive %s from you. Will you continue?',    // 220:44 (markup removed)
  period: 'Caution: The duration of Limited-Time items begins its countdown upon purchase.',   // 171:28 (second line)
  sent: 'The gift has been sent to the recipient entered above.\nGifts are sent to the Cash Inventory.',   // 171:43
  self: 'Choose another character to receive this gift.',            // engine
  vip: 'VIP Shop items cannot be sent as gifts.',                    // engine (no native gift button)
  premium: 'Holy Water of Almighty services cannot be sent as gifts.', // engine
  pending: 'The recipient has too many unaccepted gifts. Try again later.', // engine
  none: 'There is no gift to receive.',                              // engine
});
/** Normalize the typed recipient (ui_cashgiftwnd edit_text, maxlength 20). Returns {name} or {error}. */
export function giftRecipient(raw) {
  if (typeof raw !== 'string') return { error: GIFT_TEXT.noName };
  const name = raw.trim();
  if (!name) return { error: GIFT_TEXT.noName };
  if (name.length > GIFT_NAME_MAX || /[\x00-\x1f\x7f]/.test(name)) return { error: GIFT_TEXT.noCharacter };
  return { name };
}
/** Expiry of a gifted limited item: counted from the purchase time (171:28). */
export const giftExpiry = (boughtAt, periodSeconds) => (periodSeconds > 0 ? boughtAt + periodSeconds * 1000 : undefined);
