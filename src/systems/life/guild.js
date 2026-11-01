// Guild - the solo-meaningful parts (share/guild/*.csv via gamedata/life.json `guild`). A single-player game has no
// other members to recruit, so this is a personal guild: found it (game2/guild/ui_nameinputwnd.txt, the original
// name-entry box), then the main info window (game2/guild/ui_guildwnd.txt: name, level, member count, contribution,
// GP bar, guild Dil, notice board) tracks its own progress from Dil you deposit and items you turn in
// (guild_deliver.csv, `donate()`), leaving out everything that needs a second player (invites, wars, alliances,
// the member list/ranking windows). `config.LEVELSTEP<n>` (cumulative GP) gates the guild level, `LEVEL<n>_MEMBER`
// is the (unreachable solo) member cap shown for flavour. Guild skills (guildskill.csv, `ui_gskillwnd.txt`) and
// the member-management windows are a known gap - no second member ever needs them, and the exact GP/ADV point
// split (config ADVPOINTRATIO/DILTOCON) is not recoverable from client csvs alone (see docs/formats/life.md).
import { str, strNow, box, msg, state, spendDil, dil, takeItem, countItem, rejectUnsupportedOnline } from './common.js';
import {guildWindowSurface} from '../../ui/guild-window-surface.js';
import { globalAsk } from '../../ui/uiwin/global-asks.js';

export class Guild {
  constructor(game, life) {
    this.game = game;
    this.life = life;
    this.G = life.data?.guild || null;
  }

  get cfg() { return this.G?.config || {}; }
  get st() {
    if(this.game.save?.authority==='server')return this.game.save.life?.guild || { founded: false, name: '', gpoint: 0, dil: 0, contribution: 0, notice: '' };
    const s = state(this.game);
    if (!s.guild) s.guild = { founded: false, name: '', gpoint: 0, dil: 0, contribution: 0, notice: '' };
    return s.guild;
  }
  get founded() { return !!this.st.founded; }
  get level() {
    let lv = 1;
    for (let n = 1; n <= 15; n++) { const need = Number(this.cfg[`LEVELSTEP${n}`]); if (Number.isFinite(need) && this.st.gpoint >= need) lv = n; }
    return lv;
  }
  memberCap() { return Number(this.cfg[`LEVEL${this.level}_MEMBER`]) || 50; }
  levelStep(n) { return Number(this.cfg[`LEVELSTEP${n}`]) || 0; }
  /** hud-options chat.js reads game.guild.name / .members / .alliance directly. */
  get name() { return this.founded ? this.st.name : ''; }
  get members() { return this.founded ? [{ name: this.game.save?.name || this.game.player?.name || 'You', grade: 'Guild Master' }] : []; }
  get alliance() { return null; }

  async install() {
    const g = this.game;
    if (!this.G) return;
    await Promise.all([str(g, 100, 49), str(g, 250, 1)]);
    g.ui?.registerWindow?.('guild', { script: 'game2/guild/ui_guildwnd.txt', menuButton: 'btn_guild', create: (w) => this._create(w), onOpen: (w) => this._open(w), update: (w) => this._tick(w) });
    g.guild = this;
  }

  _create(w) {
    this.win = w;
    guildWindowSurface(w);
    w.control('btn_ranking').onClick(() => box(this.game, strNow(this.game, 130, 41) || 'The guild ranking needs other guilds online.'));
    w.control('btn_manage').onClick(() => { const p = w.control('pan_managePop'); p.setVisible(!p.isVisible()); w.control('pan_funcPop').hide(); });
    w.control('btn_func').onClick(() => { const p = w.control('pan_funcPop'); p.setVisible(!p.isVisible()); w.control('pan_managePop').hide(); });
    w.control('btn_power').onClick(() => box(this.game, 'You are the only member.'));
    w.control('btn_notice').onClick(() => this._editNotice());
    w.control('btn_bestbattle').onClick(() => box(this.game, 'No guild battles have been recorded.'));
    w.control('btn_secede').onClick(() => this._disband());
    w.control('btn_state').onClick(() => box(this.game, 'You are the only member.'));
    w.control('btn_advanture').onClick(() => box(this.game, this._dungeonGradeText()));
    w.control('btn_dilpoint').onClick(() => this._deposit());
    w.control('textbox').setText?.(this.st.notice || '');
  }

  async _open(w) {
    if(rejectUnsupportedOnline(this.game,'Guild management'))return false;
    if (!this.founded) { w.close(); return this._createFlow(); }
    this._refresh(w);
  }

  async _createFlow() {
    const g = this.game;
    if(rejectUnsupportedOnline(g,'Guild management'))return false;
    const cost = Number(this.cfg.MONEY) || 1000000, minLv = Number(this.cfg.LEVEL) || 1;
    const myLv = Number(g.save?.level) || 1;
    if (myLv < minLv) { msg(g, `Guild founding needs character level ${minLv}.`, 'err'); return; }
    const win = await g.uiwin.create('game2/guild/ui_nameinputwnd.txt', { modal: true, name: 'guildcreate' });
    win.control('lbl_msg').setText(`Found a guild for ${cost.toLocaleString('en-US')} Dil?`);
    win.control('btn_no').onClick(() => win.close());
    win.control('btn_yes').onClick(() => {
      if(rejectUnsupportedOnline(g,'Guild management'))return false;
      const name = win.control('edit_text').getValue?.() || win.control('edit_text').getText?.() || '';
      if (!name.trim()) return;
      if (dil(g) < cost) { msg(g, 'Not enough Dil.', 'err'); return; }
      if (!spendDil(g, cost)) { msg(g, 'Not enough Dil.', 'err'); return false; }
      const st = this.st;
      st.founded = true; st.name = name.trim().slice(0, 16); st.gpoint = 0; st.dil = 0; st.contribution = 0;
      win.close();
      msg(g, `[Guild] "${st.name}" founded.`, 'sys');
      g.persist?.();
      g.events?.emit?.('life:guild', { founded: true, name: st.name });
    });
    win.open();
  }

  _refresh(w) {
    const g = this.game, st = this.st;
    w.control('lbl_guildName').setText(st.name);
    w.control('lbl_memberCnt').setText(`1 / ${this.memberCap()}`);
    w.control('lbl_guildLevel').setText(String(this.level));
    w.control('lbl_advanNum').setText(String(Math.floor(st.gpoint)));
    w.control('lbl_mygrade').setText('Guild Master');
    w.control('lbl_dungeonclass').setText('-');
    w.control('lbl_mycontribute').setText(String(Math.floor(st.contribution)));
    const nextNeed = this.levelStep(this.level + 1);
    const base = this.levelStep(this.level);
    const frac = nextNeed > base ? Math.max(0, Math.min(1, (st.gpoint - base) / (nextNeed - base))) : 1;
    w.control('BAR_GPOINT').setGauge(frac);
    w.control('lbl_BARPER').setText(`${Math.round(frac * 100)}%`);
    w.control('lbl_GUILD_GPOINT').setText(String(Math.floor(st.gpoint)));
    w.control('lbl_Guild_DIL').setDil(st.dil);
    w.control('textbox').setText?.(st.notice || '');
  }
  _tick(w) { if (w.isOpen) this._refresh(w); }

  async _editNotice() {
    const g = this.game;
    if(rejectUnsupportedOnline(g,'Guild management'))return false;
    const v = await g.uiwin.msgbox(this.st.notice || '', { kind: 'edit', title: strNow(g, 250, 9) || 'Guild Notice' });
    if(rejectUnsupportedOnline(g,'Guild management'))return false;
    if (v != null) { this.st.notice = String(v).slice(0, 200); g.persist?.(); if (this.win?.isOpen) this._refresh(this.win); }
  }

  async _disband() {
    const g = this.game;
    if(rejectUnsupportedOnline(g,'Guild management'))return false;
    const r = await globalAsk(g, 'disbandGuild') ? 'yes' : 'no';
    if(rejectUnsupportedOnline(g,'Guild management'))return false;
    if (r !== 'yes') return;
    const st = this.st;
    st.founded = false; st.name = ''; st.gpoint = 0; st.dil = 0; st.contribution = 0; st.notice = '';
    g.uiwin.close('guild');
    msg(g, '[Guild] disbanded.', 'sys');
    g.persist?.();
    g.events?.emit?.('life:guild', { founded: false });
  }

  async _deposit() {
    const g = this.game;
    if(rejectUnsupportedOnline(g,'Guild management'))return false;
    const v = await g.uiwin.msgbox('Deposit how much Dil into the guild fund?', { kind: 'edit', title: 'Guild Dil' });
    if(rejectUnsupportedOnline(g,'Guild management'))return false;
    const n = Math.max(0, Math.floor(Number(v) || 0));
    if (!n) return;
    if (!spendDil(g, n)) { msg(g, 'Not enough Dil.', 'err'); return; }
    this.st.dil += n;
    this.st.gpoint += n / (Number(this.cfg.DILTOCON) || 100000) * (Number(this.cfg.ADVPOINTRATIO) || 1000) / 1000;
    g.persist?.();
    if (this.win?.isOpen) this._refresh(this.win);
  }

  _dungeonGradeText() {
    const row = (this.G?.dungeonGrade || [])[0];
    return row ? JSON.stringify(row) : 'No guild dungeon record.';
  }

  /** Turn in a guild_deliver.csv item for GP/contribution/(character) exp - called by other systems if they want to. */
  donate(itemIndex, count = 1) {
    if(rejectUnsupportedOnline(this.game,'Guild management'))return false;
    if (!this.founded) return false;
    const row = (this.G?.deliver || []).find((r) => r.item === Number(itemIndex));
    if (!row || countItem(this.game, itemIndex) < count) return false;
    takeItem(this.game, itemIndex, count);
    this.st.gpoint += (row.dr || 0) * count / 100;
    this.st.contribution += (row.contribution || 0) * count;
    this.game.persist?.();
    return true;
  }
}
