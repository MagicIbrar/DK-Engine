import { askSecondPassword, ServerSecondPassword } from './secondpw-window.js';

/**
 * Authorize the signed-in session before loading character selection/creation.
 * Never cache success locally: the host's current session is the authority.
 * The independent server world-entry check remains mandatory.
 */
export async function authorizeCharacterScreen(front, {
  open = () => ServerSecondPassword.open(),
  ask = askSecondPassword,
} = {}) {
  const account = front.account;
  const stillCurrent = async () => front.account === account
    && await front.restoreAccount() === account && front.account === account;
  try {
    let pw = await open();
    if (!pw.statusReady) {
      throw new Error((pw.statusError?.text || 'Unable to check your 2nd Password.') + ' Please sign in and try again.');
    }
    // A signed-in flow must not treat a lost session as the legacy local exemption.
    if (account && !pw.authenticated) {
      throw new Error('Your account session expired. Please sign in again.');
    }
    if (pw.required && !pw.verified) {
      const accepted = await ask(front.uim, pw, { text: (code, cate) => front.texts?.raw?.(cate, code) });
      if (!accepted || !await stillCurrent()) return false;
      // A successful old request may belong to a session replaced while the
      // dialog was open. Read the current cookie's status again before proceeding.
      pw = await open();
      if (!pw.statusReady || (account && !pw.authenticated) || (pw.required && !pw.verified)) {
        throw new Error('Your 2nd Password session could not be confirmed. Please sign in and try again.');
      }
    }
    if (!await stillCurrent()) return false;
    return true;
  } catch (error) {
    await front.messageBox(error?.message || 'Unable to verify your account. Please sign in and try again.');
    return false;
  }
}
