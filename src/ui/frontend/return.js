export const RETURN_KEY = 'dekaron-solo:return-to';
export const CREDENTIAL_KEY = 'dekaron-solo:credential-entry';
export const SERVER_MENU_PATH = '/web/public/index.html';
// Read only by the launcher for the exact browser process it opened. No account or token is included.
export const DESKTOP_RETURN_TITLE = 'Dekaron - Return to Client';

export function returnToDesktopClient({ window = globalThis.window, document = globalThis.document, history = globalThis.history } = {}) {
  try { history?.replaceState(null, '', '/?client=desktop'); } catch { /* No navigation is needed to return. */ }
  if (document?.body) {
    document.title = DESKTOP_RETURN_TITLE;
    const message = document.createElement('main');
    message.setAttribute('role', 'status');
    message.style.cssText = 'min-height:100vh;display:grid;place-content:center;text-align:center;padding:32px;background:#080d18;color:#f0e9da;font:16px/1.7 Segoe UI,sans-serif';
    const heading = document.createElement('h1'), detail = document.createElement('p');
    heading.textContent = 'Return to Client';
    detail.textContent = 'You are signed out. Your dashboard is in Client. You can close this game window.';
    message.append(heading, detail); document.body.replaceChildren(message);
  }
  // Chromium can refuse script closure. The tracked native window then closes through CloseMainWindow;
  // if the launcher is no longer present, the safe signed-out message remains in this same window.
  try { window?.close(); } catch { /* Keep the signed-out return message available. */ }
}

/** Fixed same-origin destinations carry no credentials, tickets or caller-provided return URLs. */
export function frontEndDestination(screen, location = globalThis.location) {
  const url = new URL(screen === 'select' ? '/' : SERVER_MENU_PATH, location.href);
  if (screen === 'select') url.searchParams.set('screen', 'select');
  if (new URL(location.href).searchParams.get('client') === 'desktop') url.searchParams.set('client', 'desktop');
  if (new URL(location.href).searchParams.get('client') === 'phone') url.searchParams.set('client', 'phone');
  if (new URL(location.href).searchParams.get('shell') === 'native') url.searchParams.set('shell', 'native');   // Dekaron.exe
  return url;
}

/** Finish saving before discarding the world; Exit Game always clears the authenticated session. */
export async function returnToFrontEnd(screen, { game, accounts, flush, stage, storage = globalThis.sessionStorage, location = globalThis.location, window = globalThis.window, document = globalThis.document, history = globalThis.history } = {}) {
  screen = screen === 'select' ? 'select' : 'login';
  if (await game?.persist?.() === false) throw new Error('Progress could not be saved. Check the server before exiting.');
  if (game?.network?.active && await game.network.leave() === false) throw new Error('Progress could not be saved. Check the server before exiting.');
  if (await flush?.() === false) throw new Error('Character saves could not finish. Your local backup is retained.');
  if (screen === 'login') await accounts.logout();
  game?.bloom?.dispose?.();
  try {
    storage?.removeItem(RETURN_KEY); storage?.removeItem(CREDENTIAL_KEY);
    if (screen === 'select') storage?.setItem(RETURN_KEY, 'select');
  } catch { /* the fixed destination still selects the requested screen */ }
  if (screen === 'login' && new URL(location.href).searchParams.get('client') === 'desktop') {
    // A refused window.close must not leave the detached game rendering behind the return message.
    game?.renderer?.setAnimationLoop?.(null);
    stage?.stop?.();
    returnToDesktopClient({ window, document, history });
    return;
  }
  location.replace(frontEndDestination(screen, location).href);
}
