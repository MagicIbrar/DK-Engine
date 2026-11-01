// Inspect player: the original "Preview" window of another character (game2/previewplayer/
// ui_previewplayerwnd.txt). Opens from the player menu of the target plate (pcpop, row "Preview" 2000:16) and with
// /inspect [Name]. Window + 3D preview: window.js; pure rules: rules.js; ENGINE-CHOSEN values:
// src/config/engine-chosen-inspect.js. Public API: game.inspect = { open(actor), openName(name), state() }.
import { installPcPop } from '../pvp/duel.js';
import { needStrings } from '../hud-options/util.js';
import { registerInspectWindow } from './window.js';
import { resolveInspectTarget, menuVisible, INSPECT_ENGINE_CHOSEN as C } from './rules.js';

let API = null;

export async function install(game) {
  if (!game.uiwin) return null;
  const mounts = game.mounts?.system || { game, data: null };
  const win = registerInspectWindow(game, mounts);
  const players = () => [...(game.network?.players?.values?.() || [])];
  const openName = (name) => {
    const r = resolveInspectTarget({ name, target: game.player?.target || null, player: game.player || null, players: players() });
    if (r.actor) { void win.open(r.actor); return true; }
    game.chat?.system?.(C.messages.usage, 'err');
    return false;
  };
  void needStrings([['NORMAL', 2000, 16], ['NORMAL', 2000, 15]]).catch(() => {});
  try {
    installPcPop(game).add({ code: C.menu.order, cate: C.menu.cate, label: C.menu.code, visible: t => menuVisible(t, game.player), run: t => { void win.open(t); } });
  } catch (error) { console.warn('[inspect] player menu', error); }
  game.chat?.registerCommand?.(C.command, (args) => { openName(args); return true; }, C.messages.help);
  API = game.inspect = { open: (actor) => win.open(actor), openName, state: () => win.state(), window: () => win.window() };
  return API;
}

/** Keep the target plate's player-menu button in step with the selected player (the script hides it). */
export function update(dt, game) { game?.pcpop?.syncButton?.(); }

export function dispose(game) { if (game?.inspect === API) game.inspect = null; API = null; }