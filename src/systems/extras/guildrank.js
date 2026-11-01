// GUILD-DUNGEON-RANK: the original Guild Frontier Ranking window + its help popup, opened from the guild window's btn_ranking
// (132:1204 "Ranking Status"); the guild window's Dungeon Lv (lbl_dungeonclass) is filled by src/systems/network/mail-guild.js
// from the same snapshot. Server-authoritative: every number comes from network.guild.frontierRanking (host:
// server/world/guild-frontier.mjs guildFrontierRanking, inside the durable social state). Rules + sources: guildrank-rules.js.
import { RANK_SCRIPT, HELP_SCRIPT, RANK_ROWS, ROW_HEIGHT, STR, positionText, pointText } from './guildrank-rules.js';

const ref = ([cate, code]) => ({ group: 'NORMAL', cate, code });
const NAMES = { rank: 'guilddungeonranking', help: 'deliveryrankinfo' };

export class GuildRank {
  constructor(game) { this.game = game; this.wins = {}; this.last = null; this.slots = []; }

  async install() {
    const W = this.game.uiwin;
    if (!W?.registerWindow) return;
    W.registerWindow(NAMES.rank, { script: RANK_SCRIPT, escClose: true, create: w => this._create(w), onOpen: w => this._render(w) });
    W.registerWindow(NAMES.help, { script: HELP_SCRIPT, escClose: true, create: w => w.control('btn_exit').onClick(() => w.close()) });
    try { await W.strings?.need?.(Object.values(STR).map(ref)); } catch { /* strings load lazily */ }
    this.game.guildRank = this;
  }

  get gs() { return this.game.network?.guild || null; }
  get online() { return this.game.save?.authority === 'server' && !!this.game.network; }
  box(text) { return this.game.uiwin.msgbox(text, { kind: 'ok' }); }

  /** guild window btn_ranking. */
  open() {
    const s = this.gs;
    if (!this.online || !s?.available) { void this.box('This server has no durable guild service.'); return false; }
    if (!s.founded) return false;
    return this.game.uiwin.open(NAMES.rank);
  }
  update() { const s = this.gs; if (s !== this.last) { this.last = s; if (this.wins.rank?.isOpen) this._render(this.wins.rank); } }

  _create(w) {
    this.wins.rank = w;
    this.slots = Array.from({ length: RANK_ROWS }, (_, i) => w.clone('pan_element', `_${i}`, { x: 0, y: i * ROW_HEIGHT, visible: false }));
    w.control('btn_tab_guildranking').setChecked?.(true);
    w.control('btn_tab_guildranking').onClick(() => { w.control('btn_tab_guildranking').setChecked?.(true); this._render(w); });   // the only tab
    w.control('btn_exit').onClick(() => w.close());
    w.control('btn_confirm').onClick(() => w.close());
    w.control('btn_help').onClick(() => { void this.game.uiwin.open(NAMES.help); });
  }

  _mark(w, back, front, mark) {
    w.control(back).setVisible(!!mark); w.control(front).setVisible(!!mark);
    // 23x23 cells: the 24 px guildbg_s / guildicon_s imagetable marks (as on the nameplate); the scripted image is transparent (0x00000000)
    if (mark) { w.control(back).setImage('none', { screen: 'guildbg_s', index: mark.bg, color: 'ffffffff' }); w.control(front).setImage('none', { screen: 'guildicon_s', index: mark.icon, color: 'ffffffff' }); }
  }

  _render(w) {
    const r = this.gs?.frontierRanking || null, rows = r?.rows || [];
    this.slots.forEach((slot, i) => {
      const row = rows[i]; slot.setVisible(!!row); if (!row) return;
      w.control(`lbl_rank_${i}`).setText(positionText(row.scorePosition));
      this._mark(w, `pan_markback_${i}`, `pan_markfront_${i}`, row.mark);
      w.control(`lbl_guildname_${i}`).setText(row.name);
      w.control(`lbl_drpoint_${i}`).setText(pointText(row.points));
    });
    const s = this.gs;
    w.control('lbl_myrank').setText(positionText(r?.mine?.scorePosition));
    this._mark(w, 'pan_mymarkback', 'pan_mymarkfront', r?.mark ?? s?.mark ?? null);
    w.control('lbl_myguildname').setText(r?.name || s?.name || '');
    w.control('lbl_mydrpoint').setText(pointText(r?.mine?.points ?? 0));
  }
}
