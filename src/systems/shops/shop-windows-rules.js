// SHOP-WINDOWS: the cash-shop purchase password and the shop info windows (shared by the client and the host).
//   * cashshop/ui_buypasswordwnd.txt "Confirm Password" (100:131): the item withdrawal guide (220:38), "Enter your password."
//     (220:29), "Password:" (220:30), a password edit, Confirm (2000:22) / Cancel (2000:14).
//   * msgbox/cashitem/ui_errpwd.txt "Confirm Password" (100:92): "Password is not correct. Your order has been cancelled." (171:30).
// Rule (original Global D-Shop flow, 2moons.acclaim.com shop guide: "Confirm your purchase on the windows that pop up and
// finally enter your user password (the same one you use to log in to the game) to confirm"; 171:31 "For your protection,
// please enter your account password."): every D-Shop / VIP shop order asks for the ACCOUNT password after the purchase
// confirmation; the HOST checks it against the account store and refuses the whole order when it is wrong (nothing changes).
// Engine (documented): the installation owner account is signed in by the private owner launcher, which takes no credentials
// (server/accounts/api.mjs ownerLaunch; its stored password is a discarded random one), so that account has no password to
// enter and is not asked; every other account signs in with its own password and is asked on every order.
export const SHOP_WINDOW_SCRIPTS = {
  buyPasswordWnd: 'game2/cashshop/ui_buypasswordwnd.txt',
  wrongPasswordWnd: 'game2/msgbox/cashitem/ui_errpwd.txt',
  vipBoxInfo: 'game2/vipshop/ui_vipshopboxinfownd.txt',
  cashBoxInfo: 'game2/cashshop/ui_cashshopboxinfownd.txt',
  receipt: 'game2/store/ui_receiptwnd_2.txt',
};
export const OWNER_ACCOUNT = 'admin';
// The account store accepts 6..128 character passwords (server/accounts/api.mjs signup); the script's maxlength 20 is the
// original account rule, so the field takes this server's account maximum instead (else long passwords could never buy).
export const PURCHASE_PASSWORD_MAX = 128;
export const PURCHASE_PASSWORD_STRINGS = { title: [100, 131], guide: [220, 38], enter: [220, 29], tag: [220, 30], wrong: [171, 30], wrongTitle: [100, 92], confirm: [2000, 22], cancel: [2000, 14] };
// The host's refusal texts = the original strings (171:30's '\\' line breaks become spaces).
export const PURCHASE_PASSWORD_TEXT = { enter: 'Enter your password.', wrong: 'Password is not correct. Your order has been cancelled.' };
export const purchasePasswordRequired = account => typeof account === 'string' && account !== '' && account !== OWNER_ACCOUNT;
/** Host-side shape check of the typed password: {password} | {error:'enter'|'wrong'}. */
export function checkPurchasePassword(password) {
  if (typeof password !== 'string' || !password.length) return { error: 'enter' };
  if (password.length > PURCHASE_PASSWORD_MAX) return { error: 'wrong' };
  return { password };
}
// Store receipt (store/ui_receiptwnd_2.txt, the consignment "Sold Items" page): 2010:34 "When the 15-day storage period for
// the receipt of sales expires, the stored DIL will be deleted."; board columns 2010:27..33.
export const RECEIPT_DAYS = 15;
export const RECEIPT_COLUMNS = [[2010, 27], [2010, 28], [2010, 29], [2010, 30], [2010, 31], [2010, 32], [2010, 33]];
/** Days left of a receipt's storage period (the board's first column, "%d days" 2010:25). */
export const receiptDaysLeft = (at, now) => Math.max(0, RECEIPT_DAYS - Math.floor((now - at) / 86400000));
// VIP shop box info (vipshop/ui_vipshopboxinfownd.txt): 10 list rows (check_item_0..9, 21 px apart), the preview always shown
// (no Detail checkbox), rotate (btn_leftrot / btn_rightrot), zoom (btn_camera_plus / btn_camera_minus), Ok (2000:15) closes,
// My Character (2000:83) shows the player's own body (with the selected costume or wing on it).
export const VIP_BOX_ROWS = 10;
export const PREVIEW_ZOOM = { min: 0.5, max: 3, step: 1.25 };
export const clampZoom = z => Math.max(PREVIEW_ZOOM.min, Math.min(PREVIEW_ZOOM.max, Number(z) || 1));
