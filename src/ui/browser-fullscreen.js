// Browser chrome belongs to the browser; native launcher windows have their own controls.
import { requestGameFullscreen, releaseFullscreenKeys, fullscreenKeysLocked } from './fullscreen-keys.js';
/**
 * Desktop App window (client=desktop; Dekaron.exe sizes itself): a 1280 x 720 game area by default, or the resolution
 * last applied in Options. Once per window, so a resize by hand is kept until the next start.
 */
export function fitDesktopWindow({ win = window, w = 1280, h = 720 } = {}) {
  const q = new URLSearchParams(win.location.search);
  if (q.get('client') !== 'desktop' || q.get('shell') === 'native') return false;
  try { if (win.sessionStorage.getItem('dekaron:window-fit')) return false; win.sessionStorage.setItem('dekaron:window-fit', '1'); } catch { /* storage */ }
  let saved = null;
  try { saved = JSON.parse(win.localStorage.getItem('dekaron-solo:options:v1') || 'null')?.resolution; } catch { /* storage */ }
  const m = /^(\d+)x(\d+)$/.exec(String(saved || ''));
  const fw = Math.max(0, win.outerWidth - win.innerWidth), fh = Math.max(0, win.outerHeight - win.innerHeight);
  // a saved mode that does not fit the desktop as a window (e.g. the desktop's own size) falls back to the default
  if (m && Number(m[1]) + fw <= (win.screen?.availWidth || Infinity) && Number(m[2]) + fh <= (win.screen?.availHeight || Infinity)) { w = Number(m[1]); h = Number(m[2]); }
  try { win.resizeTo(w + fw, h + fh); } catch { return false; }
  return true;
}
/**
 * Dekaron.exe (shell=native): F11 pressed inside the page counts up globalThis.__dekaronToggleFullscreen; the host polls it
 * and switches its own window (tools/DekaronClient.cs AskMode), in case the WebView takes the key before the form sees it.
 */
export function installNativeFullscreenKey({ win = window } = {}) {
  if (new URLSearchParams(win.location.search).get('shell') !== 'native') return false;
  win.addEventListener('keydown', e => {
    if (e.key !== 'F11') return;
    e.preventDefault();
    win.__dekaronToggleFullscreen = (win.__dekaronToggleFullscreen || 0) + 1;
  });
  return true;
}
export function installBrowserFullscreen({ doc = document, win = window } = {}) {
  if (new URLSearchParams(win.location.search).get('client') === 'desktop' ||
      win.matchMedia?.('(display-mode: standalone)').matches ||
      win.self !== win.top || !doc.fullscreenEnabled || !doc.documentElement.requestFullscreen) return null;
  const button = doc.createElement('button');
  button.id = 'browser-fullscreen';
  button.className = 'browser-fullscreen';
  button.type = 'button';
  button.innerHTML = '<svg viewBox="0 0 24 24" aria-hidden="true"><path d="M8 3H3v5m13-5h5v5M3 16v5h5m13-5v5h-5"/></svg>';
  const sync = () => {
    const active = !!doc.fullscreenElement;
    button.title = active ? (fullscreenKeysLocked(doc) ? 'Exit fullscreen — hold Esc to return to browser' : 'Exit fullscreen') : 'Fullscreen';
    button.setAttribute('aria-label', active ? 'Exit fullscreen' : 'Enter fullscreen');
    button.setAttribute('aria-pressed', String(active));
  };
  let busy = false;
  const click = async event => {
    event.stopPropagation();
    if (busy) return;
    busy = true;
    try {
      // Called directly in the trusted click, as required by the Fullscreen API.
      if (doc.fullscreenElement) { releaseFullscreenKeys(doc); await doc.exitFullscreen(); }
      else await requestGameFullscreen(doc, win);
    } catch {
      button.title = 'Fullscreen is unavailable in this browser window';
    } finally { busy = false; button.blur(); if (doc.fullscreenElement) sync(); }
  };
  button.addEventListener('click', click);
  for (const event of ['pointerdown', 'mousedown', 'mouseup', 'dblclick']) button.addEventListener(event, e => e.stopPropagation());
  doc.addEventListener('fullscreenchange', sync);
  sync();
  doc.body.appendChild(button);
  return { button, dispose() { releaseFullscreenKeys(doc); doc.removeEventListener('fullscreenchange', sync); button.remove(); } };
}
