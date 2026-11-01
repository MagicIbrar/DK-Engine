// Key bindings (the client's "Change Controls" window, script/ui/game2/keymap/ui_keymapwnd.txt).
//
// The action list is the client's own: script/string/normal/stringtable_keymap.txt cate 2200, new key version
// codes 100..1105 (headers 100, 200, ... 1100), old version codes 0..99. Key names: cate 2201; messages 2202.
// Default keys come from the client's control guide (script/string/help/guide_info_system.txt cate 1301 code 1
// "조작법 및 단축키", and the menu tables of cate 1302): W/A/S/D move, R walk/run, U next target, E self target,
// N nearest NPC, ` auto attack, Ctrl force attack, Shift attack in place, Space pick up, 1..0 - = skill slots,
// F1..F10 potion slots, Z/X skill slot set, Tab weapon, Ctrl+Tab equipment, T pet, L fishing, J mount, H guide,
// Shift+Q/W/E/R/A + \ summon orders, arrows/PageUp/PageDown camera, V names, Alt drop names, F12 screenshot,
// Shift+Z / Shift+X control type A/B, Ctrl+C chat, Ctrl+U follow, C/K/I/Q/P/O/G/F/Y/'/'/M windows, Ctrl+J mount
// manager, Ctrl+R crafting. Bindings persist in localStorage.
//
// How keys reach the game:
//   * window actions are uiwin hotkeys: another system's hotkey registered at the action's default key follows the
//     binding (uiwin keyOverrides); otherwise this module registers its own ('km:<id>') that opens the window by
//     its main-menu button / registered window name.
//   * engine keys hard-coded in controller.js / camera.js / game.js (WASD, Tab, 1..0, Z, Shift, arrows, PageUp/Down,
//     C/K/I/M) are remapped under the Input: a query for the engine's code answers with the bound key's state.
//   * every other action is dispatched here each frame (skill slot keys, potion belt, self target, NPC talk, ...).
import { LS, str, Hub } from './util.js';
import { parseKey } from '../../ui/uiwin/manager.js';

const KEY_BINDINGS = 'dekaron-solo:keymap:v1';
export const MAX_KEYS = 255;

/** Actions: [code, id, default binding | '', kind, extra]. Headers have id null. oldCode = the old version's code. */
const A = (code, id, def, kind, extra = {}) => ({ code, id, def, kind, ...extra });
export const ACTIONS = [
  A(100, null), // Information
  A(101, 'character', 'KeyC', 'win', { menu: 'btn_character', win: 'character', old: 1 }),
  A(102, 'skill', 'KeyK', 'win', { menu: 'btn_skill', win: 'skills', old: 2 }),
  A(103, 'inventory', 'KeyI', 'win', { menu: 'btn_inven', win: 'inventory', old: 3 }),
  A(104, 'quest', 'KeyQ', 'win', { menu: 'btn_quest', win: 'quest', old: 4 }),
  A(105, 'party', 'KeyP', 'win', { menu: 'btn_party', win: 'party', old: 5 }),
  A(106, 'expedition', 'KeyO', 'win', { menu: 'btn_expedition', win: 'expedition', old: 6 }),
  A(107, 'guild', 'KeyG', 'win', { menu: 'btn_guild', win: 'guild', old: 7 }),
  A(108, 'messenger', 'KeyF', 'win', { menu: 'btn_mail', win: 'messenger', old: 8 }),
  A(109, 'pet', 'KeyY', 'win', { menu: 'btn_petinven', win: 'pet', old: 9 }),
  A(110, 'personalshop', 'Slash', 'win', { menu: 'btn_personalshop', win: 'personalshop', old: 10 }),
  A(111, 'map', 'KeyM', 'win', { menu: 'btn_map', win: 'map', old: 11 }),
  A(112, 'help', 'KeyH', 'win', { win: 'help', old: 12 }),
  A(113, 'guide', '', 'win', { win: 'contentsguide', old: 13 }),
  A(114, 'mount', 'Ctrl+KeyJ', 'win', { menu: 'btn_ride', win: 'mount' }),
  A(115, 'craft', 'Ctrl+KeyR', 'win', { menu: 'btn_craft', win: 'craft' }),
  A(116, 'names', 'KeyV', 'act', { old: 94 }),
  A(117, 'dropnames', 'Alt', 'act', { old: 95 }),
  A(118, 'chat', 'Ctrl+KeyC', 'act'),
  A(119, 'autohunt', '', 'win', { win: 'autohunt' }),
  A(200, null), // Character Main Action
  A(201, 'left', 'KeyA', 'engine', { old: 15 }),
  A(202, 'right', 'KeyD', 'engine', { old: 16 }),
  A(203, 'forward', 'KeyW', 'engine', { old: 17 }),
  A(204, 'back', 'KeyS', 'engine', { old: 18 }),
  A(205, 'walk', 'KeyR', 'act', { old: 19 }),
  A(206, 'ride', 'KeyJ', 'act', { menu: 'btn_vehicle', old: 20 }),
  A(207, 'petsummon', 'KeyT', 'act', { menu: 'btn_petsummon', old: 21 }),
  A(208, 'fishing', 'KeyL', 'act', { menu: 'btn_fishing', old: 22 }),
  A(300, null), // Character Assist Action
  A(301, 'autoattack', 'Backquote', 'act', { old: 24 }),
  A(302, 'forceattack', 'Ctrl', 'act', { old: 25 }),
  A(303, 'inplace', 'Shift', 'engine', { old: 26 }),
  A(304, 'autohuntstart', '', 'act'),
  A(305, 'selftarget', 'KeyE', 'act', { old: 27 }),
  A(306, 'nexttarget', 'KeyU', 'engine', { old: 28 }),
  A(307, 'controlA', 'Shift+KeyZ', 'act'),
  A(308, 'controlB', 'Shift+KeyX', 'act'),
  A(309, 'setdown', 'KeyX', 'act'),
  A(310, 'setup', 'KeyZ', 'act', { old: 81 }),
  A(311, 'npctalk', 'KeyN', 'act', { old: 29 }),
  A(312, 'loot', 'Space', 'engine', { old: 30 }),
  A(313, 'weaponswap', 'Tab', 'act', { old: 31 }),
  A(314, 'equipswap', 'Ctrl+Tab', 'act', { old: 33 }),
  A(315, 'follow', 'Ctrl+KeyU', 'act', { old: 32 }),
  A(316, 'hotkey', '', 'act'),
  A(317, 'hotkeyitem', '', 'act'),
  A(400, null), // Order Summon
  A(401, 'sumattack', 'Shift+KeyQ', 'act', { old: 35 }),
  A(402, 'sumauto', 'Shift+KeyW', 'act', { old: 36 }),
  A(403, 'sumcall', 'Shift+KeyE', 'act', { old: 37 }),
  A(404, 'sumstop', 'Shift+KeyR', 'act', { old: 38 }),
  A(405, 'sumdisband', 'Shift+KeyA', 'act', { old: 39 }),
  A(406, 'sumskill', 'Backslash', 'act', { old: 40 }),
];
const SLOT_KEYS = ['Digit1', 'Digit2', 'Digit3', 'Digit4', 'Digit5', 'Digit6', 'Digit7', 'Digit8', 'Digit9', 'Digit0', 'Minus', 'Equal'];
for (const [base, row] of [[500, 0], [600, 1], [700, 2]]) {
  ACTIONS.push(A(base, null));
  for (let i = 0; i < 12; i++) ACTIONS.push(A(base + 1 + i, `slot${row}_${i}`, row === 0 ? SLOT_KEYS[i] : '', 'slot', { row, slot: i, old: (row === 0 ? 42 : row === 1 ? 55 : 68) + i }));
}
ACTIONS.push(A(800, null));
for (let i = 0; i < 10; i++) ACTIONS.push(A(801 + i, `belt${i}`, `F${i + 1}`, 'act', { belt: i, old: 83 + i }));
ACTIONS.push(
  A(900, null), // Display
  A(901, 'screenshot', 'F12', 'act'),
  A(902, 'camdown', 'ArrowUp', 'engine', { old: 96 }),
  A(903, 'camup', 'ArrowDown', 'engine', { old: 97 }),
  A(904, 'camright', 'ArrowLeft', 'engine', { old: 98 }),
  A(905, 'camleft', 'ArrowRight', 'engine', { old: 99 }),
  A(906, 'zoomin', 'PageDown', 'engine'),
  A(907, 'zoomout', 'PageUp', 'engine'),
  A(908, 'itemlink', '', 'act'),
  A(909, 'cameraView', 'KeyB', 'camera', { label: 'Toggle First-Person View' }),
  A(1000, null), // Express Emotion
  A(1001, 'emo_sit', '', 'emote', { motion: 1 }),
  A(1002, 'emo_hi', '', 'emote', { motion: 10 }),
  A(1003, 'emo_respect', '', 'emote', { motion: 11 }),
  A(1004, 'emo_standby', '', 'emote', { motion: 15 }),
  A(1005, 'emo_cheer', '', 'emote', { motion: 16 }),
  A(1006, 'emo_clap', '', 'emote', { motion: 17 }),
  A(1007, 'emo_cry', '', 'emote', { motion: 18 }),
  A(1008, 'emo_dance', '', 'emote', { motion: 19 }),
  A(1009, 'emo_smile', '', 'emote', { motion: 20 }),
  A(1010, 'emo_stretch', '', 'emote', { motion: 21 }),
  A(1011, 'emo_surrender', '', 'emote', { motion: 23 }),
  A(1012, 'emo_despair', '', 'emote', { motion: 24 }),
  A(1013, 'emo_angry', '', 'emote', { motion: 25 }),
  A(1014, 'emo_taunt', '', 'emote', { motion: 26 }),
  A(1015, 'emo_sorry', '', 'emote', { motion: 27 }),
  A(1100, null), // Preset Hotkey
  A(1101, 'preset0', '', 'act', { preset: 0 }), A(1102, 'preset1', '', 'act', { preset: 1 }), A(1103, 'preset2', '', 'act', { preset: 2 }),
  A(1104, 'preset3', '', 'act', { preset: 3 }), A(1105, 'preset4', '', 'act', { preset: 4 }),
);
export const ACTION_BY_ID = new Map(ACTIONS.filter(a => a.id).map(a => [a.id, a]));

/**
 * The engine's own hard-coded key codes -> the action they stand for (their key follows the binding). 'block'
 * = never answer (the action is dispatched by a uiwin hotkey instead: game.js's built-in C/K/I/M).
 */
const ENGINE_CODES = {
  KeyW: 'forward', KeyS: 'back', KeyA: 'left', KeyD: 'right',
  Tab: 'nexttarget', KeyZ: 'loot', ShiftLeft: 'inplace', ShiftRight: 'inplace',
  // the quick slot keys are dispatched by the quick slot window (3 rows x 12, control type A/B)
  Digit1: 'block', Digit2: 'block', Digit3: 'block', Digit4: 'block', Digit5: 'block',
  Digit6: 'block', Digit7: 'block', Digit8: 'block', Digit9: 'block', Digit0: 'block',
  ArrowDown: 'camdown', ArrowUp: 'camup', ArrowLeft: 'camright', ArrowRight: 'camleft', PageUp: 'zoomin', PageDown: 'zoomout',
  KeyC: 'block', KeyK: 'block', KeyI: 'block', KeyM: 'block',
};

// ------------------------------------------------------------------------------------------ key names
const CODE_NAME = {
  ControlLeft: 0, ControlRight: 0, Ctrl: 0, ShiftLeft: 1, ShiftRight: 1, Shift: 1, AltLeft: 2, AltRight: 2, Alt: 2,
  Tab: 3, Space: 4, Backspace: 5, ArrowLeft: 6, ArrowRight: 7, ArrowUp: 8, ArrowDown: 9,
  F1: 10, F2: 11, F3: 12, F4: 13, F5: 14, F6: 15, F7: 16, F8: 17, F9: 18, F10: 19, F11: 20, F12: 21,
  Enter: 22, PageUp: 23, PageDown: 24, Home: 25, End: 26, Insert: 27, Delete: 28, Semicolon: 29, Equal: 30,
  Comma: 31, Minus: 32, Period: 33, Slash: 34, Backquote: 35, Backslash: 36,
  Numpad0: 37, Numpad1: 38, Numpad2: 39, Numpad3: 40, Numpad4: 41, Numpad5: 42, Numpad6: 43, Numpad7: 44, Numpad8: 45, Numpad9: 46,
  NumLock: 47, CapsLock: 49, NumpadMultiply: 50, NumpadSubtract: 51, NumpadAdd: 52, PrintScreen: 53, ScrollLock: 54,
  Pause: 55, BracketLeft: 56, BracketRight: 57, Quote: 58, NumpadDecimal: 59,
};
const ARROWS = { ArrowLeft: '←', ArrowRight: '→', ArrowUp: '↑', ArrowDown: '↓', Backslash: '\\' };
/** Client name of one key code (stringtable_keymap cate 2201; letters/digits as themselves). */
export function keyName(code) {
  if (!code) return str(2201, 48) || 'None';
  if (ARROWS[code]) return ARROWS[code];
  const n = CODE_NAME[code];
  if (n != null) { const s = str(2201, n); if (s) return s.trim(); }
  let m;
  if ((m = /^Key([A-Z])$/.exec(code))) return m[1];
  if ((m = /^Digit(\d)$/.exec(code))) return m[1];
  return code;
}
/** 'Ctrl+KeyU' -> 'Ctrl + U' */
export function bindingName(spec) {
  if (!spec) return str(2201, 48) || 'None';
  const p = parseKey(spec);
  const mods = [];
  if (p.mods.ctrl) mods.push(keyName('Ctrl'));
  if (p.mods.shift) mods.push(keyName('Shift'));
  if (p.mods.alt) mods.push(keyName('Alt'));
  return [...mods, keyName(p.code)].join(' + ');
}
const MOD_ONLY = { Ctrl: ['ControlLeft', 'ControlRight'], Shift: ['ShiftLeft', 'ShiftRight'], Alt: ['AltLeft', 'AltRight'] };
/** Keys the client refuses (2202:115 "This key cannot be used."). */
const FORBIDDEN = new Set(['Escape', 'Enter', 'NumpadEnter', 'MetaLeft', 'MetaRight', 'ContextMenu', 'PrintScreen']);

// ------------------------------------------------------------------------------------------ store
export class KeyMap extends Hub {
  constructor(game) {
    super();
    this.game = game;
    const saved = LS.load(KEY_BINDINGS, {}) || {};
    this.version = saved.version === 1 ? 1 : 2;
    this.bindings = {};
    for (const a of ACTIONS) if (a.id) this.bindings[a.id] = a.def || '';
    Object.assign(this.bindings, saved.bindings || {});
    // A newly introduced default cannot steal a user's existing B assignment.
    if (!Object.hasOwn(saved.bindings || {}, 'cameraView') && this.holder('KeyB', 'cameraView')) this.bindings.cameraView = '';
    this.raw = null;           // unwrapped Input methods
    this._bypass = 0;
  }
  save() { LS.save(KEY_BINDINGS, { version: this.version, bindings: this.bindings }); }
  get(id) { return this.bindings[id] ?? ''; }
  /** Bind (spec '' = none); returns the id previously holding that key (unbound) or null. */
  set(id, spec) {
    this.bindings[id] = spec || '';
    this.save();
    this.emit('change', id, spec);
    return this;
  }
  /** Which action currently holds this binding (other than `except`). */
  holder(spec, except = null) {
    if (!spec) return null;
    for (const [id, s] of Object.entries(this.bindings)) if (id !== except && s === spec) return id;
    return null;
  }
  resetAll() { for (const a of ACTIONS) if (a.id) this.bindings[a.id] = a.def || ''; this.save(); this.emit('change', null); }
  count() { return Object.values(this.bindings).filter(Boolean).length; }
  forbidden(code) { return FORBIDDEN.has(code); }

  // -------------------------------------------------------------- Input remap
  /** Wrap the game's Input so engine-internal codes answer with the bound keys (see file header). */
  install(input) {
    if (!input || input._hoKeymap) return;
    input._hoKeymap = true;
    const raw = { hit: input.hit.bind(input), down: input.down.bind(input) };
    this.raw = raw;
    this.input = input;
    input.hit = (code) => {
      if (this._bypass) return raw.hit(code);
      const a = ENGINE_CODES[code];
      if (a === 'block') return false;
      if (a) return this.hit(this.get(a));
      return raw.hit(code);
    };
    input.down = (code) => {
      if (this._bypass) return raw.down(code);
      const a = ENGINE_CODES[code];
      if (a === 'block') return false;
      if (a) return this.down(this.get(a), true);
      return raw.down(code);
    };
  }
  /** Run fn with the raw (unmapped) key state (uiwin hotkeys test their own bound codes). */
  bypass(fn) { this._bypass++; try { return fn(); } finally { this._bypass--; } }
  _mods() {
    const r = this.raw;
    return {
      ctrl: r.down('ControlLeft') || r.down('ControlRight'),
      shift: r.down('ShiftLeft') || r.down('ShiftRight'),
      alt: r.down('AltLeft') || r.down('AltRight'),
    };
  }
  /** Was a binding pressed this frame? (Ctrl/Alt must match exactly; Shift only when the binding names it.) */
  hit(spec, { allowForceAttack = false } = {}) {
    if (!spec || !this.raw) return false;
    if (MOD_ONLY[spec]) return MOD_ONLY[spec].some(c => this.raw.hit(c));
    const p = parseKey(spec);
    if (!this.raw.hit(p.code)) return false;
    const m = this._mods();
    // Slot keys also work with the held Force Attack modifier. A deliberately
    // bound chord still owns its key; ordinary actions retain exact modifiers.
    const force = allowForceAttack ? this.get('forceattack') : null;
    const chord = [m.ctrl && 'Ctrl', m.shift && 'Shift', m.alt && 'Alt', p.code].filter(Boolean).join('+');
    const ctrl = !!p.mods.ctrl === m.ctrl || (force === 'Ctrl' && m.ctrl && !p.mods.ctrl && !this.holder(`Ctrl+${p.code}`) && !this.holder(chord));
    const alt = !!p.mods.alt === m.alt || (force === 'Alt' && m.alt && !p.mods.alt && !this.holder(`Alt+${p.code}`) && !this.holder(chord));
    return ctrl && alt && (!p.mods.shift || m.shift) && !(m.shift && !p.mods.shift && this._shiftBound(p.code));
  }
  /** Is a binding held? lenient = ignore extra modifiers (movement keys keep working while Shift is held). */
  down(spec, lenient = false) {
    if (!spec || !this.raw) return false;
    if (MOD_ONLY[spec]) return MOD_ONLY[spec].some(c => this.raw.down(c));
    const p = parseKey(spec);
    if (!this.raw.down(p.code)) return false;
    const m = this._mods();
    if (p.mods.ctrl && !m.ctrl) return false;
    if (p.mods.alt && !m.alt) return false;
    if (p.mods.shift && !m.shift) return false;
    if (!lenient && ((m.ctrl && !p.mods.ctrl) || (m.alt && !p.mods.alt))) return false;
    return true;
  }
  /** Some other action is bound to Shift+code (then plain `code` must not fire while Shift is down). */
  _shiftBound(code) { return Object.values(this.bindings).includes(`Shift+${code}`); }
}
