// CHAR-TRADE client rules (pure: no DOM, no game). Windows: index.js. ENGINE-CHOSEN values:
// src/config/engine-chosen-char-trade.js.
import { CHAR_TRADE_ENGINE_CHOSEN as C } from '../../config/engine-chosen-char-trade.js';
export { C as CHAR_TRADE_ENGINE_CHOSEN };

export const CHAR_TRADE_SCRIPTS = Object.freeze({
  main: 'game2/chartradewnd/ui_chartradewnd.txt',        // 100:85 "Transfer Character"
  info: 'game2/chartradewnd/ui_chartradeinfownd.txt',    // 100:84 "Character Transfer Information"
  wait: 'game2/chartradewnd/ui_invitechartrade.txt',     // 100:37 "Character Account Transfer" + 556:57 "Requesting..."
  invite: 'game2/msgbox/ui_chartradeinvite.txt',          // 100:38 + <name> + 556:58 + Accept 2000:24 / Decline 2000:25
});
export const STRING_CATE = 556;                            // string/normal/stringtable_chartrade.txt
// Global PcPopWnd row 11 (label 240:11 "Expedition", verbatim Global label) sends RequestCharTrade; 240:103 is not a pcpop row in Global (lane 62).
export const MENU = Object.freeze({ cate: 240, label: 11, order: 11 });
export const BUSY_PARTY_PVP = 38;                          // 556:38 "You cannot make a character transfer while performing other activities."
export const INVITE_TITLE = Object.freeze({ cate: 100, code: 38 });
export const COMMAND = '/chartrade';
// lbl_charInfo: 556:16-29 "<LABEL> : <VALUE>" lines, filled from the character summary (server/accounts/char-transfer.mjs)
export const INFO_LINES = Object.freeze([[16, 'str'], [17, 'dex'], [18, 'con'], [19, 'spr'], [20, 'statPoints'], [21, 'skillPoints'], [22, 'hp'],
  [23, 'mp'], [24, 'shield'], [25, 'advPoints'], [26, 'exp'], [27, 'pk'], [28, 'pvp'], [29, 'tendency']]);
// the suititem_N slots of every pan_Preset_N (same ids as the inventory / preset preview)
export const SLOT_IDS = Object.freeze([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 18, 19, 20, 24, 25, 26, 27, 28, 33, 34, 35, 36]);
// every 556 string the windows and messages use (preloaded once)
export const STRING_CODES = Object.freeze([...new Set([0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 15, ...INFO_LINES.map(r => r[0]), ...Object.values(C.msg)])]);

/** The original string id a host refusal carries ("[556:n] ..."), or null. */
export function errorMsg(message) { const m = /\[556:(\d+)\]/.exec(String(message ?? '')); return m ? Number(m[1]) : null; }

/** pcpop row: another connected player only. */
export function menuVisible(target, player, online) { return !!online && target?.kind === 'player' && target !== player && !target.dead; }

/** What the main window shows for a host snapshot (network.charTrade). */
export function charTradeView(s, now = 0) {
  if (!s) return null;
  const seller = s.role === 'seller', open = s.phase === 'open', locked = s.phase === 'locked', me = s.role;
  return {
    seller, open, locked,
    receiver: s.buyer?.name || '', giver: s.seller?.name || '',
    // pan_infoshield covers the character side for whoever cannot change it; pan_slotshield the payment side
    infoShield: !(seller && open), slotShield: !(!seller && open),
    accept1: !!s.confirmed?.seller, accept2: !!s.confirmed?.buyer,   // btn_accept1 = character side, btn_accept2 = payment side
    canConfirm: open && !!s.character && !s.confirmed?.[me],
    canApprove: locked && (!!s.unlocked || (s.lockUntil > 0 && now >= s.lockUntil)) && !s.approved?.[me],
    progress: locked,
    list: seller ? (s.characters || []) : (s.character ? [s.character] : []),
    selected: s.character?.id ?? null,
    dil: Number(s.payment?.dil) || 0,
    items: s.payment?.items || [],
  };
}

/** Safety-lock gauge 0..1 (556:39) from the server clock. */
export function lockProgress(s, now) {
  if (!s || s.phase !== 'locked') return 0;
  if (s.unlocked) return 1;
  return Math.max(0, Math.min(1, 1 - (s.lockUntil - now) / C.safetyMs));
}

/** Combobox caption of a character summary. */
export function characterCaption(c) { return c ? `${c.name}  Lv.${c.level}${c.className ? ' ' + c.className : ''}` : ''; }

/** lbl_charInfo text: every 556:16-29 line with <VALUE> replaced. text(code) -> original string. */
export function charInfoText(c, text) {
  if (!c) return '';
  const info = c.detail?.info || {};
  return INFO_LINES.map(([code, key]) => String(text(code) || '').replace('<VALUE>', String(info[key] ?? 0))).join('\n');
}

/** lbl_charInfo as shown: one original line per stat (C.charInfoColumns = 1), whitespace runs collapsed. */
export function charInfoColumns(c, text) {
  const lines = charInfoText(c, text).split('\n').filter(Boolean).map(l => l.replace(/\s+/g, ' ').replace(' :', ':'));
  const out = [];
  const n = Math.max(1, C.charInfoColumns || 1);
  for (let i = 0; i < lines.length; i += n) out.push(lines.slice(i, i + n).map((l, k) => (k < n - 1 ? l.padEnd(18, ' ') : l)).join(''));
  return out.join('\n');
}

/** The equipped item of one preset slot of a character summary (weapon tab II = slot + 100). */
export function presetItem(equip, preset, slot) {
  const uid = equip?.presets?.[preset]?.[slot];
  return uid ? equip.items?.[uid] || null : null;
}

/** Chat/system line for a host event (type 'chartrade'): the 556 string to show, or null. */
export function eventMsg(record) {
  if (record?.type !== 'chartrade' || record.msg == null) return null;
  if (record.reason === 'invited' || record.reason === 'locked') return null;   // the windows show these
  return Number(record.msg);
}