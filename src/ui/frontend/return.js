export const RETURN_KEY = 'dekaron-solo:return-to';
export const CREDENTIAL_KEY = 'dekaron-solo:credential-entry';
export const SERVER_MENU_PATH = '/web/public/index.html';
// Read only by the launcher for the exact browser process it opened. No account or token is included.
export const DESKTOP_RETURN_TITLE = 'Dekaron - Return to Client';

function isNativeOrDesktopClient(location = globalThis.location) {
  try {
    const q = new URL(location.href).searchParams;
    return q.get('client') === 'desktop' || q.get('shell') === 'native';
  } catch { return false; }
}

export function returnToDesktopClient({ window = globalThis.window, document = globalThis.document, history = globalThis.history } = {}) {
  try { history?.replaceState(null, '', '/?client=desktop&shell=native'); } catch { /* No navigation is needed to return. */ }
  if (document?.body) {
    document.title = DESKTOP_RETURN_TITLE;
    const message = document.createElement('main');
    message.setAttribute('role', 'status');
    message.style.cssText = 'min-height:100vh;display:grid;place-content:center;text-align:center;padding:32px;background:#080d18;color:#f0e9da;font:16px/1.7 Segoe UI,sans-serif';
    const heading = document.createElement('h1'), detail = document.createElement('p');
    heading.textContent = 'Closing Dekaron';
    detail.textContent = 'Exiting cleanly. This window will close.';
    message.append(heading, detail); document.body.replaceChildren(message);
  }
  // Chromium can refuse script closure. The native GameWindow Poll() sees DESKTOP_RETURN_TITLE and Close()s.
  // World-select (/web/public/index.html) must NEVER appear from native / desktop exit.
  try { window?.close(); } catch { /* Keep the signed-out return message available. */ }
}

/** Fixed same-origin destinations carry no credentials, tickets or caller-provided return URLs. */
export function frontEndDestination(screen, location = globalThis.location) {
  // Native / desktop GameWindow: never route Exit Game to the public world-select portal.
  if (screen !== 'select' && isNativeOrDesktopClient(location)) {
    const url = new URL('/', location.href);
    url.searchParams.set('client', 'desktop');
    url.searchParams.set('shell', 'native');
    return url;
  }
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
  // DX11 GameWindow (shell=native) and desktop Client: Exit / titlebar-driven quit must close, never world-select.
  if (screen === 'login' && isNativeOrDesktopClient(location)) {
    game?.renderer?.setAnimationLoop?.(null);
    stage?.stop?.();
    returnToDesktopClient({ window, document, history });
    return;
  }
  location.replace(frontEndDestination(screen, location).href);
}