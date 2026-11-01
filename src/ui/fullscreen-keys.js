// Capture only Escape when the browser grants Keyboard Lock. Its long-Escape
// escape hatch and our fullscreen button remain available; game menus receive Esc.
const states = new WeakMap();
export function fullscreenKeysLocked(doc = document) { return !!states.get(doc)?.locked; }
export function releaseFullscreenKeys(doc = document) {
  const state = states.get(doc); if (!state) return;
  states.delete(doc); state.locked = false;
  try { state.keyboard?.unlock(); } catch { /* optional browser API */ }
  state.win.removeEventListener('keydown', state.escape, true);
  doc.removeEventListener('fullscreenchange', state.changed);
}
export async function requestGameFullscreen(doc = document, win = window) {
  releaseFullscreenKeys(doc);
  const keyboard = win.navigator?.keyboard;
  const state = { keyboard, win, locked: false };
  state.escape = event => { if (state.locked && doc.fullscreenElement && event.key === 'Escape') event.preventDefault(); };
  state.changed = () => { if (!doc.fullscreenElement) releaseFullscreenKeys(doc); };
  states.set(doc, state);
  doc.addEventListener('fullscreenchange', state.changed);
  win.addEventListener('keydown', state.escape, true);
  try {
    await doc.documentElement.requestFullscreen();
    if (states.get(doc) !== state) return;
    if (!keyboard?.lock || !doc.fullscreenElement) { releaseFullscreenKeys(doc); return; }
    await keyboard.lock(['Escape']);
    if (states.get(doc) === state && doc.fullscreenElement) state.locked = true;
    else if (!states.has(doc)) keyboard.unlock();
  } catch (error) {
    if (states.get(doc) === state) releaseFullscreenKeys(doc);
    if (!doc.fullscreenElement) throw error;
  } // Keyboard permission denied: keep browser fullscreen usable.
}
