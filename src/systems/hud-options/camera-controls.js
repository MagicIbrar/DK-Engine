/** Shared one-press camera-mode action. Gameplay sticks pan/move; no controller button toggles this mode. */
export function toggleGameplayCamera(game) {
  const a = typeof document === 'undefined' ? null : document.activeElement;
  const typing = a && (a.isContentEditable || /INPUT|TEXTAREA|SELECT/.test(a.tagName));
  if (!game.player || game.player.dead || game.player.disposed || game.paused || game._loadingMap
    || game._worldReady === false || game.uiwin?.capturesInput || game.uiwin?.isOpen?.('keymap')
    || game.gm?.freecam?.on || game.input?.enabled === false || typing
    || (typeof document !== 'undefined' && (document.hidden || (document.hasFocus && !document.hasFocus())))) return false;
  if (!game.options || !game.cam?.setMode) return false;
  game.options.set({ cameraMode: game.cam.mode === 'first-person' ? 'third-person' : 'first-person' });
  return true;
}

export function dispatchCameraToggle(game, keymap) {
  if (!keymap.raw || !keymap.hit(keymap.get('cameraView'))) return false;
  return toggleGameplayCamera(game);
}
