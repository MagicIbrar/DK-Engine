// Boot (docs/ARCHITECTURE.md §3.9): straight to the original 3D LOGIN screen (no loading screen before it) ->
// CHARACTER SELECT <-> CREATE -> the original loading screen -> the world. Everything runs locally.
//   ?screen=select | create   start the front-end at that screen (dev convenience; the login stays the default)
// globalThis.dekaronReturnTo('select' | 'login') leaves the world for that screen (the system menu's "Character
// select" / "Log out"): the page restarts once at that screen, as the client returns without a new log-in.
import { runFrontEnd } from './ui/frontend/frontend.js';
import { flushCharacterSaves } from './game/save.js';
import { LocalAccounts } from './ui/frontend/accounts.js';
import { returnToFrontEnd, RETURN_KEY } from './ui/frontend/return.js';
import { installBrowserFullscreen, fitDesktopWindow, installNativeFullscreenKey } from './ui/browser-fullscreen.js';
import { installUICursor } from './ui/cursor.js';
import { installMobileControls } from './ui/mobile-controls.js';
import { reportCrash, installCrashHandlers } from './ui/crash-log.js';

const ui = document.getElementById('ui');
const canvas = document.getElementById('game');
installBrowserFullscreen();
fitDesktopWindow();
installNativeFullscreenKey();
void installUICursor();   // the original cursor over every window and screen, not only the 3D canvas (ui/cursor.js)

function fatal(err) {
  console.error(err);
  // The in-world loading screen already owns recovery for a failed map entry.
  // A second generic fatal panel would sit underneath it and offer no context.
  if (ui.querySelector('.fe-loading [role="alert"]')) return;
  // Open + show a shareable crash log (download, in-page viewer, notepad on local host).
  void reportCrash(err, { where: 'fatal' });
}
installCrashHandlers({ onFatal: () => {} });

globalThis.dekaronReturnTo = async (screen = 'select') => {
  try { await returnToFrontEnd(screen, { game: window.dekaron, accounts: new LocalAccounts(), flush: flushCharacterSaves }); }
  catch (err) { window.dekaron?.hud?.log(err.message, 'err'); }
};

function startScreen() {
  let s = null;
  try { s = sessionStorage.getItem(RETURN_KEY); sessionStorage.removeItem(RETURN_KEY); } catch { /* ignore */ }
  const q = new URLSearchParams(location.search).get('screen');
  const pick = s || q;
  return ['select', 'create'].includes(pick) ? pick : 'login';
}

async function boot() {
  const { character, initialChannel, renderer, textures, models, data } = await runFrontEnd({ canvas, ui, startAt: startScreen() });
  const { Game } = await import('./game/game.js');
  const game = new Game({ canvas, ui, character, initialChannel, renderer, textures, models, data });
  window.dekaron = game; // handy for debugging from the console
  await game.start();
  installMobileControls(game);
  let lastSaveWarning = '';
  window.addEventListener('dekaron:save-status', ({ detail }) => {
    if (['offline', 'conflict', 'error', 'recovered'].includes(detail.state) && detail.message !== lastSaveWarning) {
      lastSaveWarning = detail.message; game.hud.log(detail.message, 'err');
    } else if (detail.state === 'synced') lastSaveWarning = '';
  });
}

boot().catch(fatal);
