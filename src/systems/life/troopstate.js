// Expedition member status HUD: the original game2/ui_troopstatewnd.txt ("troop_state", anchored right-top at -340 / 217,
// 347 x 393, hidden by its script until the client shows it). Shown while the character is in an expedition; every value
// comes from the server snapshot (network.expedition, server/world/expedition.mjs row + memberStatuses), nothing here
// changes game state.
//   rows      the OTHER members of the character's own corp in corp order, cloned from the template pan_state (0 24 340 32):
//             pan_pcname = name, pan_class = small class icon (imagetable etc_01 200 + class: 200..214 are the 15 classes in
//             the order of the large icons 100..114), processbar_hp = HP / max HP (party #10 "HP bar"),
//             processbar_shield = shield / max shield (party #9 "shield bar").
//             The window is 393 px high = 24 header + 6 rows of 54 (32 row + 22 status strip): the 6 other members of a
//             7-member corp. A whole expedition (20 others) cannot fit, so the window lists the corp, as the party state
//             window it copies (game2/party/ui_partystate.txt) lists the party.
//   statuses  pan_buffstatus: up to 8 buffs from the left (pan_bufficon_0..7), pan_debuffstatus: up to 8 debuffs from the
//             right (pan_debufficon_0 is the right-most); both hidden by the script until the header's plus button opens them,
//             minus closes them; an opened row takes 32 + 22 px.
//   header    btn_lock "Lock window motion" (71:3) stops dragging by the title bar; btn_state_hide collapses the window to
//             state_menu2 (btn_state_show) and back.
// NOT DERIVABLE (documented, not invented): btn_state_mid (a third header state no data describes: stays hidden as the
// script has it); btn_follow "Follow" (70:160 / tooltip 2000:81; the only rule text is 70:161 "The target should be in the
// same channel.", no follow distance or re-path rule exists in the client files): shown disabled; what a click on a row does.
import { LS } from '../hud-options/util.js';

export const TROOP_STATE_SCRIPT = 'game2/ui_troopstatewnd.txt';
export const ROWS = 6, ROW_Y = 24, ROW_H = 32, STRIP_H = 22, ICONS = 8;

/** The other members of `myId`'s corp, in corp order ([] when not in an expedition). */
export function corpMates(st, myId) {
  if (!st?.active) return [];
  const corp = (st.corps || []).find(c => (c || []).some(m => m.id === myId));
  return (corp || []).filter(m => m.id !== myId);
}

/** Buff / debuff icon lists of a member row (max 8 each, in the server's order). */
export function statusStrips(statuses) {
  const list = Array.isArray(statuses) ? statuses : [];
  return { buffs: list.filter(s => s.buff).slice(0, ICONS), debuffs: list.filter(s => !s.buff).slice(0, ICONS) };
}

/** Top of row i (window coordinates): 32 px rows, 54 px when the status strips are open. */
export function rowY(i, expanded) { return ROW_Y + i * (ROW_H + (expanded ? STRIP_H : 0)); }

/** Small class icon of the troop state rows: imagetable etc_01 200 + class index (15 classes), else the script's 200. */
export function classSmallIcon(classIndex) {
  const i = Number(classIndex);
  return Number.isInteger(i) && i >= 0 && i <= 14 ? 200 + i : 200;
}

const ratio = (v, max) => (Number(max) > 0 ? Math.max(0, Math.min(1, Number(v) / Number(max))) : 0);

export class TroopState {
  constructor(game, expedition) {
    this.game = game; this.expedition = expedition; this.win = null; this.rows = [];
    const saved = LS.load(this.key, null) || {};
    this.expanded = !!saved.expanded; this.hidden = !!saved.hidden; this.locked = !!saved.locked;
  }
  get key() { return `dekaron.troopstate.${this.game.save?.id || 'guest'}`; }
  _save() { LS.save(this.key, { expanded: this.expanded, hidden: this.hidden, locked: this.locked }); }

  install() {
    this.game.uiwin.registerWindow('troop_state', {
      script: TROOP_STATE_SCRIPT, hud: true, escClose: false,
      create: w => this._create(w), onOpen: () => this.render(),
    });
  }

  /** Follow the expedition state: open while in an expedition, closed otherwise, rows refreshed. */
  sync() {
    const ui = this.game.uiwin, st = this.expedition.st;
    if (!st?.active) { if (ui.isOpen('troop_state')) ui.close('troop_state'); return; }
    if (!ui.isOpen('troop_state')) { void ui.open('troop_state'); return; }
    this.render();
  }

  _create(w) {
    this.win = w;
    const c = id => w.control(id);
    c('btn_state_plus').onClick(() => this.setExpanded(true));
    c('btn_state_minus').onClick(() => this.setExpanded(false));
    c('btn_state_hide').onClick(() => this.setHidden(true));
    c('btn_state_show').onClick(() => this.setHidden(false));
    c('btn_lock').onClick(() => this.setLocked(!this.locked));
    const tpl = c('pan_state');
    this.rows = [];
    for (let i = 0; i < ROWS; i++) {
      const row = tpl.cloneAs(`_${i}`, { x: 0, y: rowY(i, this.expanded), visible: false });
      row.setEnabled(true);
      w.control(`btn_follow_${i}`).setEnabled(false);
      this.rows.push(row);
    }
    tpl.hide();
    this.setLocked(this.locked, false);
  }

  setExpanded(on) { this.expanded = !!on; this._save(); this.render(); }
  setHidden(on) { this.hidden = !!on; this._save(); this.render(); }
  setLocked(on, save = true) {
    this.locked = !!on;
    if (this.win) this.win.opts.movable = this.locked ? false : undefined;
    if (save) this._save();
  }

  render() {
    const w = this.win;
    if (!w) return;
    const c = id => w.control(id);
    c('state_menu').setVisible(!this.hidden);
    c('state_menu2').setVisible(this.hidden);
    c('btn_state_plus').setVisible(!this.expanded);
    c('btn_state_minus').setVisible(this.expanded);
    c('btn_state_mid').setVisible(false);
    const mates = corpMates(this.expedition.st, this.expedition.myId);
    this.rows.forEach((row, i) => {
      const m = mates[i];
      row.setVisible(!!m && !this.hidden);
      if (!m || this.hidden) return;
      row.setRect(0, rowY(i, this.expanded));
      c(`pan_pcname_${i}`).setText(m.name || '');
      c(`pan_class_${i}`).setImage('none', 'etc_01', classSmallIcon(m.classIndex));
      c(`processbar_hp_${i}`).setGauge(ratio(m.hp, m.maxHp));
      c(`processbar_shield_${i}`).setGauge(ratio(m.shield, m.maxShield));
      const { buffs, debuffs } = statusStrips(m.statuses);
      c(`pan_buffstatus_${i}`).setVisible(this.expanded);
      c(`pan_debuffstatus_${i}`).setVisible(this.expanded);
      for (let k = 0; k < ICONS; k++) {
        const b = buffs[k], d = debuffs[k];
        const bi = c(`pan_bufficon_${k}_${i}`), di = c(`pan_debufficon_${k}_${i}`);
        bi.setVisible(!!b); if (b) bi.setImage('none', b.group || 'buffer', b.icon);
        di.setVisible(!!d); if (d) di.setImage('none', d.group || 'buffer', d.icon);
      }
    });
  }

  dispose() { this.win = null; this.rows = []; }
}
