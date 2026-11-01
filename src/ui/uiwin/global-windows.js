// Registers every remaining active Global window (bench/UI-GAP-403.md) on the UIManager, loaded verbatim from
// its Global script/ui file, so systems open them by key: game.uiwin.open('game2:msgbox:ui_seal').
// Message boxes go through UIManager.msgbox with the script's own text2 strings (scripted).
import { GLOBAL_WINDOWS } from './global-windows-table.js';
export { GLOBAL_WINDOWS };
export const GLOBAL_WINDOW_BY_KEY = new Map(GLOBAL_WINDOWS.map(w => [w.key, w]));

export function installGlobalWindows(ui) {
  if (!ui?.registerWindow) return 0;
  let n = 0;
  for (const w of GLOBAL_WINDOWS) { if (ui.has?.(w.key)) continue; ui.registerWindow(w.key, { script: w.script, globalWindow: w.window, prebuild: false }); n++; }
  return n;
}

/** Opens a Global message box by key; resolves 'yes' / 'no' / 'ok' as UIManager.msgbox does. */
export async function globalMessage(game, key, text = null, { kind, body, value } = {}) {
  const w = GLOBAL_WINDOW_BY_KEY.get(key);
  if (!w) throw new Error(`unknown Global window ${key}`);
  const ui = game?.uiwin; if (!ui?.msgbox) return null;
  const yesno = kind || (w.buttons.some(b => /yes|ok|accept|confirm/i.test(b)) && w.buttons.some(b => /no|cancel|decline|close/i.test(b)) ? 'yesno' : 'ok');
  return ui.msgbox(text, { kind: yesno, script: w.script, name: w.window, scripted: true, body, ...(value != null ? { value } : {}) });
}
/** A Global yes/no box: resolves true on its accept button (btn_yes / btn_ok / btn_confirm). */
export async function globalConfirm(game, key, text = null, { body } = {}) { return (await globalMessage(game, key, text, { kind: 'yesno', body })) === 'yes'; }
/** A Global box with its own edit_text: resolves the entered text, or null when cancelled or closed. */
export async function globalPrompt(game, key, { value = '', text = null, body } = {}) { return globalMessage(game, key, text, { kind: 'edit', body, value: String(value ?? '') }); }
/** A Global one-button information box: resolves when it closes. */
export async function globalNotice(game, key, text = null, { body } = {}) { return globalMessage(game, key, text, { kind: 'ok', body }); }
