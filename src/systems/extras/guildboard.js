// GUILD-BOARD: the original guild publicity / record / Best Guild War windows, all server-authoritative online (host:
// server/world/guild-board.mjs inside the guild social transaction; snapshot fields of network.guild). Rules + sources:
// guildboard-rules.js.
//   board    Guild sign NPC (job 134) -> game2/guild/ui_guildboardwnd.txt: 20 rows (pan_column_value clones, 24 px rows between the
//            column header and the page line at 505), sortable columns, paging, the selected guild's detail panel (mark, name, master,
//            level, members, date of establishment, recruitment classes, promotion title) + btn_detail; the bottom line 134:31 +
//            btn_cancel_register while the character has a pending application.
//   detail   btn_detail -> ui_guildrequestjoinwnd.txt: terms of accession, subscription type, expiry, promotion content, application
//            message (edit_comment) + Apply (134:34); btn_delete only for the leader viewing the own guild's promotion (134:45).
//   manage   Blake (job 135) -> ui_guildmanagejoinwnd.txt: tab 134:8 promotion form (level, rating combos, 15 classes, Select All,
//            subscription type, 7 days / 1,000,000 DIL, guild DIL, title, content, Reset, Register 134:35 / modify 134:44) and tab
//            134:9 List of Applications (17 rows: level, class icon, rating, name, message, approve 134:47 / refuse 134:48).
//   history  guild window tab btn_history -> ui_guildhistorywnd.txt: 22 rows (btn_record clones, 19 px) of 130:464 / 130:481, sortable.
//   best     guild window btn_bestbattle -> ui_bestguildwnd.txt: BEST_GUILD (7) representatives from the member list, one per class.
import { SCRIPTS, JOB, STR, TEXT, ROWS, PROMOTION_COST, LEVEL_MAX, CLASS_COUNT, DIVISIONS, STEPS, CLASS_ICON, plain, gradeOf, divisionOf, classIcon,
  checkPromotion, historyLine, sortRows, pageCount, dateText, timeText } from './guildboard-rules.js';
import { numText } from '../life/common.js';
import { randomUUID } from '../network/web-crypto.js';

const ref = ([cate, code]) => ({ group: 'NORMAL', cate, code });
const NAMES = { board: 'guildboard', detail: 'guildboarddetail', manage: 'guildmanagejoin', history: 'guildhistory', best: 'bestguild' };

export class GuildBoard {
  constructor(game) {
    this.game = game; this.busy = false; this.wins = {}; this.last = null;
    this.board = { page: 0, sort: { key: 'registeredAt', dir: -1 }, selected: null, rows: [] };
    this.requests = { page: 0, rows: [] };
    this.history = { top: 0, sort: { key: 'at', dir: -1 }, rows: [] };
    this.best = { picked: [], top: 0, sort: { key: 'classIndex', dir: 1 }, guildId: null };
  }

  async install() {
    const g = this.game, W = g.uiwin;
    if (!W?.registerWindow) return;
    const reg = (key, create, onOpen) => W.registerWindow(NAMES[key], { script: SCRIPTS[key], escClose: true, create: w => { this.wins[key] = w; create.call(this, w); }, onOpen: (w, arg) => onOpen.call(this, w, arg) });
    reg('board', this._createBoard, this._openBoard);
    reg('detail', this._createDetail, this._openDetail);
    reg('manage', this._createManage, this._openManage);
    reg('history', this._createHistory, this._openHistory);
    reg('best', this._createBest, this._openBest);
    const codes = [...Object.values(STR), ...Array.from({ length: DIVISIONS }, (_, i) => [134, 1000 + i]), ...Array.from({ length: STEPS }, (_, i) => [134, 1100 + i]), [134, 1], [134, 3], [134, 13], [134, 14]];
    try { await W.strings?.need?.(codes.map(ref)); } catch { /* strings load lazily */ }
    this._wireNpc();
    g.events?.on?.('systems', () => this._wireNpc());
    g.guildBoard = this;
  }

  _wireNpc() {
    const s = this.game.npcServices;
    if (!s?.register || this._services === s) return;
    this._services = s;
    s.register(JOB.list, npc => { void this.openBoard(npc); return true; });
    s.register(JOB.manage, npc => { void this.openManage(npc); return true; });
  }

  // ------------------------------------------------------------------ shared
  get gs() { return this.game.network?.guild || null; }
  get online() { return this.game.save?.authority === 'server' && !!this.game.network; }
  t(pair, fallback = '') { return this.game.uiwin?.strings?.get?.(ref(pair)) ?? fallback; }
  say(pair, vars = {}, fallback = '') { let s = this.t(pair, fallback); for (const [k, v] of Object.entries(vars)) s = s.split(`<${k}>`).join(v); return s.replace(/\[message\]/gi, '').replace(/\\/g, '\n'); }
  box(text, kind = 'ok') { return this.game.uiwin.msgbox(text, { kind }); }
  async ask(text) { return (await this.box(text, 'yesno')) === 'yes'; }
  rating(grade) {
    const d = divisionOf(grade); if (!d) return plain(this.t(STR.noLimit, 'No Restrictions'));
    const div = Math.min(d.division, DIVISIONS);
    return `${plain(this.t([134, 1100 + d.step - 1]))} ${plain(this.t([134, 1000 + div - 1]))}`.trim();
  }
  async send(operation, fields = {}) {
    const n = this.game.network, s = this.gs;
    if (!this.online || !s?.available) { await this.box('This server has no durable guild service.'); return null; }
    if (this.busy) return null;
    this.busy = true;
    try {
      const r = await n.action('guild', { operation, revision: s.revision, requestId: randomUUID(), ...fields });
      if (!r && n._lastCommandError?.message) void this.box(n._lastCommandError.message);
      return r;
    } finally { this.busy = false; this.refresh(); }
  }
  update() { const s = this.gs; if (s !== this.last) { this.last = s; this.refresh(); } }
  refresh() {
    const w = this.wins;
    if (w.board?.isOpen) this._renderBoard(w.board);
    if (w.detail?.isOpen) this._renderDetail(w.detail);
    if (w.manage?.isOpen) this._renderRequests(w.manage);
    if (w.history?.isOpen) this._renderHistory(w.history);
    if (w.best?.isOpen) this._renderBest(w.best);
  }
  _fillGuildDetail(w, row) {
    const c = id => w.control(id);
    c('pan_markback').setVisible(!!row?.mark); c('pan_markfront').setVisible(!!row?.mark);
    if (row?.mark) { c('pan_markback').setImage('none', 'guildbg', row.mark.bg); c('pan_markfront').setImage('none', 'guildicon', row.mark.icon); }
    c('lbl_guildname_detail').setText(row?.name || '');
    c('lbl_guildmaster_detail').setText(row?.master || '');
    c('lbl_guildlevel_detail').setText(row ? `${plain(this.t([134, 1]))} ${row.level}` : '');
    c('lbl_guildmember_detail').setText(row ? `${row.members} / ${row.cap}` : '');
    c('lbl_guildstartdate_detail').setText(row ? dateText(row.createdAt) : '');
    for (let i = 0; i < CLASS_COUNT; i++) c(`btn_class_${i}`).setChecked(!!row?.classes?.includes(i));
    c('lbl_notice_title').setText(row?.title || '');
  }

  // ------------------------------------------------------------------ board (Guild sign)
  openBoard(npc = null) { return this.game.uiwin.open(NAMES.board, { npc }); }
  _createBoard(w) {
    const main = w.control('pan_main');
    this.board.slots = Array.from({ length: ROWS.board }, (_, i) => {
      const row = w.clone('pan_column_value', `_${i}`, { x: 0, y: 24 + i * 24, parent: main, visible: false });
      row.setEnabled(true); row.onClick(() => { const r = this.board.view[i]; if (r) { this.board.selected = r.guildId; this._renderBoard(w); } });
      return row;
    });
    const cols = [['btn_guild_level', 'level'], ['btn_guild_name', 'name'], ['btn_guild_member_count', 'members'], ['btn_guild_level_limit', 'levelLimit'], ['btn_guild_grade_limit', 'grade'], ['btn_guild_date', 'expiresAt']];
    for (const [id, key] of cols) w.control(id).onClick(() => { const s = this.board.sort; this.board.sort = { key, dir: s.key === key ? -s.dir : 1, id }; this._renderBoard(w); });
    w.control('btn_page_left').onClick(() => { this.board.page = Math.max(0, this.board.page - 1); this._renderBoard(w); });
    w.control('btn_page_right').onClick(() => { this.board.page = Math.min(pageCount(this.board.rows.length, ROWS.board) - 1, this.board.page + 1); this._renderBoard(w); });
    w.control('btn_detail').onClick(() => { const r = this.board.rows.find(x => x.guildId === this.board.selected); if (r) void this.game.uiwin.open(NAMES.detail, { guildId: r.guildId }); });
    w.control('btn_cancel_register').onClick(async () => {
      const a = this.gs?.application; if (!a) return;
      if (await this.ask(this.say(STR.cancelAsk, { GUILD: a.guildName }))) { if (await this.send('cancelApply')) void this.box(plain(this.t(STR.canceled))); }
    });
    w.control('btn_exit').onClick(() => w.close());
  }
  _openBoard(w) { this.board.page = 0; this._renderBoard(w); }
  _renderBoard(w) {
    const B = this.board, s = this.gs, rows = B.rows = sortRows(s?.board || [], B.sort.key, B.sort.dir);
    B.page = Math.min(B.page, pageCount(rows.length, ROWS.board) - 1);
    if (!rows.some(r => r.guildId === B.selected)) B.selected = rows[0]?.guildId || null;
    B.view = rows.slice(B.page * ROWS.board, (B.page + 1) * ROWS.board);
    const none = plain(this.t(STR.noLimit, 'No Restrictions'));
    B.slots.forEach((slot, i) => {
      const r = B.view[i]; slot.setVisible(!!r); if (!r) return;
      const set = (id, v) => w.control(`${id}_${i}`).setText(String(v));
      set('lbl_guild_level', r.level); set('lbl_guild_name', r.name); set('lbl_guild_member_count', `${r.members}/${r.cap}`);
      set('lbl_guild_level_limit', r.levelLimit || none); set('lbl_guild_grade_limit', this.rating(r.grade)); set('lbl_guild_date', dateText(r.expiresAt));
      for (const id of ['lbl_guild_level', 'lbl_guild_name', 'lbl_guild_member_count', 'lbl_guild_level_limit', 'lbl_guild_grade_limit', 'lbl_guild_date']) w.control(`${id}_${i}`).setTextColor?.(r.guildId === B.selected ? 'fffcfc00' : 'ffffffff');   // selection: palette yellow1 (stringtable_color.txt); the row highlight is not in the script
    });
    w.control('lbl_page').setText(`${B.page + 1} / ${pageCount(rows.length, ROWS.board)}`);
    const head = B.sort.id && w.control(B.sort.id), asc = w.control('pan_sort_asc'), dec = w.control('pan_sort_dec');
    asc.setVisible(!!head && B.sort.dir > 0); dec.setVisible(!!head && B.sort.dir < 0);
    if (head) { const b = head.spec.rect; for (const p of [asc, dec]) p.move?.(b[0] + b[2] - 18, 6); }
    const sel = rows.find(r => r.guildId === B.selected) || null;
    this._fillGuildDetail(w, sel);
    w.control('btn_detail').setVisible(!!sel);
    const a = s?.application;
    w.control('lbl_reg_desc').setVisible(!!a); w.control('btn_cancel_register').setVisible(!!a);
    if (a) w.control('lbl_reg_desc').setRichText?.(this.say(STR.applying, { GUILD: a.guildName }));
  }

  // ------------------------------------------------------------------ detail / apply
  _createDetail(w) {
    w.control('btn_exit').onClick(() => w.close());
    w.control('btn_regist').onClick(async () => {
      const r = this._detailRow(); if (!r) return;
      if (!await this.ask(this.say(STR.applyAsk, { GUILD: r.name }))) return;
      const comment = String(w.control('edit_comment').getValue?.() || '');
      if (await this.send('apply', { guildId: r.guildId, comment })) {
        void this.box(this.say(this.gs?.founded ? STR.joined : STR.applied, { GUILD: r.name }));
        w.close();
      }
    });
    w.control('btn_delete').onClick(async () => {
      const r = this._detailRow(); if (!r) return;
      if (await this.ask(this.say(STR.deleteAsk, { GUILD: r.name })) && await this.send('deletePromotion')) { void this.box(plain(this.t(STR.deleted))); w.close(); }
    });
  }
  _detailRow() { return (this.gs?.board || []).find(r => r.guildId === this.detailId) || null; }
  _openDetail(w, arg) { this.detailId = arg?.guildId || this.board.selected; w.control('edit_comment').setValue?.(''); this._renderDetail(w); }
  _renderDetail(w) {
    const r = this._detailRow(), s = this.gs;
    if (!r) { w.close(); return; }
    this._fillGuildDetail(w, r);
    const c = id => w.control(id), none = plain(this.t(STR.noLimit, 'No Restrictions'));
    c('lbl_guild_level_limit').setText(String(r.levelLimit || none));
    c('lbl_guild_grade_limit').setText(this.rating(r.grade));
    c('lbl_reg_type_value').setText(plain(this.t(r.approval ? STR.approval : STR.immediate)));
    c('lbl_guild_date_limit').setText(dateText(r.expiresAt));
    c('textbox_content').setText?.(r.content || '');
    const own = !!(s?.founded && s.id === r.guildId && s.master === s.myRef);
    c('btn_delete').setVisible(own);
    c('btn_regist').setEnabled(!s?.founded && !s?.application && !this.busy);
  }

  // ------------------------------------------------------------------ manage (Blake)
  async openManage(npc = null) {
    const s = this.gs;
    if (!this.online || !s?.available) { await this.box('This server has no durable guild service.'); return null; }
    if (!s.founded) { await this.box(plain(this.t(STR.noGuild, TEXT.noGuild))); return null; }
    if (s.master !== s.myRef) { await this.box(plain(this.t(STR.leaderOnly, TEXT.leaderOnly))); return null; }
    return this.game.uiwin.open(NAMES.manage, { npc });
  }
  _createManage(w) {
    const c = id => w.control(id);
    const tab = key => { c('pan_manage').setVisible(key === 'manage'); c('pan_request').setVisible(key === 'request'); c('btn_manage').setChecked(key === 'manage'); c('btn_request').setChecked(key === 'request'); this.manageTab = key; };
    this._tab = tab;
    c('btn_manage').onClick(() => tab('manage')); c('btn_request').onClick(() => tab('request'));
    c('com_grade0').setItems(Array.from({ length: STEPS }, (_, i) => ({ text: plain(this.t([134, 1100 + i])), value: i + 1 })));
    c('com_grade1').setItems([{ text: plain(this.t(STR.noLimit, 'No Restrictions')), value: 0 }, ...Array.from({ length: DIVISIONS }, (_, i) => ({ text: plain(this.t([134, 1000 + i])), value: i + 1 }))]);
    c('btn_select_all_class').onClick(() => { const all = !this._allClasses(w); for (let i = 0; i < CLASS_COUNT; i++) c(`btn_class_${i}`).setChecked(all); this._selectAllLabel(w); });
    for (let i = 0; i < CLASS_COUNT; i++) c(`btn_class_${i}`).on('change', () => this._selectAllLabel(w));
    c('check_reg_approve').on('change', v => c('check_reg_immediately').setChecked(!v));
    c('check_reg_immediately').on('change', v => c('check_reg_approve').setChecked(!v));
    c('btn_deleteAll').onClick(() => { c('edit_notice_title').setValue?.(''); c('textbox_content').setText?.(''); });
    c('btn_confirm').onClick(() => this._register(w));
    const host = c('pan_request');
    this.requests.slots = Array.from({ length: ROWS.requests }, (_, i) => {
      const row = w.clone('pan_column_value', `_${i}`, { x: 0, y: 49 + i * 24, parent: host, visible: false });
      row.setEnabled(true);
      w.control(`btn_acceept_${i}`).onClick(() => this._decide(i, true));
      w.control(`btn_decline_${i}`).onClick(() => this._decide(i, false));
      return row;
    });
    c('btn_page_left').onClick(() => { this.requests.page = Math.max(0, this.requests.page - 1); this._renderRequests(w); });
    c('btn_page_right').onClick(() => { this.requests.page = Math.min(pageCount(this.requests.rows.length, ROWS.requests) - 1, this.requests.page + 1); this._renderRequests(w); });
    c('btn_exit').onClick(() => w.close());
  }
  _allClasses(w) { for (let i = 0; i < CLASS_COUNT; i++) if (!w.control(`btn_class_${i}`).isChecked()) return false; return true; }
  _selectAllLabel(w) { w.control('btn_select_all_class').setText(plain(this.t(this._allClasses(w) ? [134, 14] : [134, 13]))); }
  _openManage(w) {
    const c = id => w.control(id), pr = this.gs?.promotion;
    this._tab(pr ? 'request' : 'manage');
    c('edit_level_limit').setValue?.(String(pr?.levelLimit ?? 0));
    const d = divisionOf(pr?.grade || 0);
    c('com_grade0').selectValue?.(d?.step || 1); c('com_grade1').selectValue?.(d?.division || 0);
    for (let i = 0; i < CLASS_COUNT; i++) c(`btn_class_${i}`).setChecked(pr ? pr.classes.includes(i) : true);
    this._selectAllLabel(w);
    c('check_reg_approve').setChecked(pr ? pr.approval : true); c('check_reg_immediately').setChecked(pr ? !pr.approval : false);
    c('edit_notice_title').setValue?.(pr?.title || ''); c('textbox_content').setText?.(pr?.content || '');
    this.requests.page = 0; this._renderRequests(w);
  }
  _form(w) {
    const c = id => w.control(id), division = Number(c('com_grade1').getValue()) || 0;
    return { levelLimit: Number(String(c('edit_level_limit').getValue?.() ?? '0').trim() || 0), grade: division ? gradeOf(division, Number(c('com_grade0').getValue()) || 1) : 0,
      classes: Array.from({ length: CLASS_COUNT }, (_, i) => i).filter(i => c(`btn_class_${i}`).isChecked()), approval: !!c('check_reg_approve').isChecked(),
      title: String(c('edit_notice_title').getValue?.() || ''), content: String(c('textbox_content').getText?.() || '') };
  }
  async _register(w) {
    const form = this._form(w), checked = checkPromotion(form);
    if (checked.error) { await this.box(plain(this.t(STR.conditions, TEXT.conditions))); return; }
    const edit = !!this.gs?.promotion;
    if (!await this.ask(plain(this.t(edit ? STR.modifyAsk : STR.registerAsk)))) return;
    if (await this.send(edit ? 'editPromotion' : 'promote', checked.value)) {
      void this.box(edit ? plain(this.t(STR.processed)) : `${plain(this.t(STR.registered))}\n${String(this.t(STR.costDeducted)).replace('%lld', numText(PROMOTION_COST))}`);
    }
  }
  async _decide(i, approve) {
    const a = this.requests.view?.[i]; if (!a) return;
    if (!await this.ask(this.say(approve ? STR.approveAsk : STR.rejectAsk, { JOINUSER: a.name }))) return;
    if (await this.send(approve ? 'approve' : 'reject', { id: a.id })) void this.box(this.say(approve ? STR.approved : STR.refused, { JOINUSER: a.name }));
  }
  _renderRequests(w) {
    const R = this.requests, rows = R.rows = sortRows(this.gs?.applications || [], 'at', 1);
    R.page = Math.min(R.page, pageCount(rows.length, ROWS.requests) - 1);
    R.view = rows.slice(R.page * ROWS.requests, (R.page + 1) * ROWS.requests);
    R.slots?.forEach((slot, i) => {
      const a = R.view[i]; slot.setVisible(!!a); if (!a) return;
      w.control(`lbl_player_level_${i}`).setText(String(a.level));
      w.control(`pan_player_class_${i}`).setImage('none', CLASS_ICON.group, classIcon(a.classIndex));
      w.control(`lbl_player_grade_${i}`).setText(a.grade > 0 ? this.rating(Math.min(a.grade, DIVISIONS * STEPS)) : plain(this.t(STR.none, 'None')));   // no awakening grade: 134:49 None
      w.control(`lbl_player_name_${i}`).setText(a.name); w.control(`lbl_player_comment_${i}`).setText(a.comment || '');
    });
    w.control('lbl_page').setText(`${R.page + 1} / ${pageCount(rows.length, ROWS.requests)}`);
    const dilLabel = w.control('lbl_Guild_DIL'); if (dilLabel.setDil) dilLabel.setDil(this.gs?.dil || 0); else dilLabel.setText(numText(this.gs?.dil || 0));
  }

  // ------------------------------------------------------------------ history (guild window tab)
  openHistory() { if (!this.gs?.founded) return null; return this.game.uiwin.open(NAMES.history); }
  _createHistory(w) {
    const list = w.control('pan_memList');
    this.history.slots = Array.from({ length: ROWS.history }, (_, i) => w.clone('btn_record', `_${i}`, { x: 0, y: 25 + i * 19, parent: list, visible: false }));
    const cols = [['btn_col_date', 'at'], ['btn_col_name', 'name'], ['btn_col_type', 'type'], ['btn_col_contribution', 'amount']];
    for (const [id, key] of cols) for (const sfx of ['', '_asc', '_desc']) w.control(id + sfx).onClick(() => { const s = this.history.sort; this.history.sort = { key, dir: s.key === key ? -s.dir : -1 }; this._renderHistory(w); });
    const sc = w.control('memList_scroll'); sc.on?.('change', v => { this.history.top = Number(v) || 0; this._renderHistory(w, true); });
    list.on?.('wheel', (e, d) => { sc.setValue?.((Number(sc.getValue?.()) || 0) + d, false); });
    w.control('btn_guild').onClick(() => { w.close(); this.game.uiwin.open('guild'); });
    // (src/systems/extras/guildextras.js) Participant / Skills / War Status, ALLIANCE tab
    for (const [id, go] of [['btn_member', () => this.game.guildExtras?.openMembers?.()], ['btn_guildskill', () => this.game.guildExtras?.openSkills?.()],
      ['btn_warhistory', () => this.game.guildExtras?.openWarHistory?.()], ['btn_alliance', () => this.game.alliance?.open?.()]])
      w.control(id)?.onClick?.(() => { w.control(id).setChecked?.(false); if (go()) w.close(); });
    w.control('btn_exit').onClick(() => w.close());
  }
  _openHistory(w) { this.history.top = 0; w.control('btn_history').setChecked(true); w.control('btn_guild').setChecked(false); this._renderHistory(w); }
  _renderHistory(w, scrolled = false) {
    const H = this.history, cols = { at: 'btn_col_date', name: 'btn_col_name', type: 'btn_col_type', amount: 'btn_col_contribution' };
    H.rows = sortRows(this.gs?.history || [], H.sort.key, H.sort.dir);
    const max = Math.max(0, H.rows.length - ROWS.history);
    if (!scrolled) w.control('memList_scroll').setRange?.(max, ROWS.history);
    H.top = Math.min(H.top, max);
    for (const [key, id] of Object.entries(cols)) { const on = H.sort.key === key; w.control(id).setVisible(!on); w.control(`${id}_asc`).setVisible(on && H.sort.dir > 0); w.control(`${id}_desc`).setVisible(on && H.sort.dir < 0); }
    const text = (cate, code) => this.t([cate, code]);
    H.slots.forEach((slot, i) => {
      const e = H.rows[H.top + i]; slot.setVisible(!!e); if (!e) return;
      w.control(`lbl_recDate_${i}`).setText(timeText(e.at));
      const line = historyLine(e, text, numText), lbl = w.control(`lbl_recHistory_${i}`);
      if (lbl.setRichText) lbl.setRichText(line); else lbl.setText(plain(line));
    });
  }

  // ------------------------------------------------------------------ Best Guild War (guild window btn_bestbattle)
  async openBest() {
    const s = this.gs;
    if (!s?.founded) return null;
    if (s.master !== s.myRef) { await this.box(plain(this.t(STR.bestMaster, TEXT.bestMaster))); return null; }
    return this.game.uiwin.open(NAMES.best);
  }
  _createBest(w) {
    const c = id => w.control(id), count = () => this.gs?.bestGuild?.count || 7;
    for (let i = 0; i < 7; i++) {
      c(`btn_garbage_${i}`).onClick(() => { this.best.picked.splice(i, 1); this._renderBest(w); });
      c(`btnsublist_${i}`).onClick(() => {
        const m = this.best.view?.[i]; if (!m) return;
        const B = this.best;
        if (B.picked.includes(m.ref)) return;
        if (B.picked.length >= count()) { void this.box(plain(this.t(STR.bestCount, TEXT.bestCount))); return; }
        const members = this.gs?.members || [];
        if (B.picked.some(r => members.find(x => x.ref === r)?.classIndex === m.classIndex)) { void this.box(plain(this.t(STR.bestClass, TEXT.bestClass))); return; }
        B.picked.push(m.ref); this._renderBest(w);
      });
    }
    const cols = [['btn_col_class', 'classIndex'], ['btn_col_lv', 'level'], ['btn_col_name', 'name']];
    for (const [id, key] of cols) for (const sfx of ['', '_h', '_l']) c(id + sfx).onClick(() => { const s = this.best.sort; this.best.sort = { key, dir: s.key === key ? -s.dir : 1 }; this._renderBest(w); });
    c('vscroll').on?.('change', v => { this.best.top = Number(v) || 0; this._renderBest(w, true); });
    c('btn_ok').onClick(async () => {
      if (this.best.picked.length !== count()) { void this.box(plain(this.t(STR.bestCount, TEXT.bestCount))); return; }
      if (await this.send('bestGuild', { members: [...this.best.picked] })) { void this.box(plain(this.t(STR.bestDone))); w.close(); }
    });
    c('btn_cancel').onClick(() => w.close()); c('btn_exit').onClick(() => w.close());
  }
  _openBest(w) { const s = this.gs; this.best.picked = [...(s?.bestGuild?.members || [])].filter(r => s.members.some(m => m.ref === r)); this.best.top = 0; this._renderBest(w); }
  _renderBest(w, scrolled = false) {
    const B = this.best, members = this.gs?.members || [], c = id => w.control(id);
    const fill = (row, m) => { row.setVisible(true); row.control('pan_class').setVisible(!!m); row.control('lbl_lv').setText(m ? String(m.level || '') : ''); row.control('lbl_name').setText(m?.name || ''); if (m) row.control('pan_class').setImage('none', CLASS_ICON.group, classIcon(m.classIndex)); };
    for (let i = 0; i < 7; i++) { const m = members.find(x => x.ref === B.picked[i]); fill(c(`btnmainlist_${i}`), m); c(`btn_garbage_${i}`).setVisible(!!m); }
    const rest = sortRows(members.filter(m => !B.picked.includes(m.ref)), B.sort.key, B.sort.dir), max = Math.max(0, rest.length - 7);
    if (!scrolled) c('vscroll').setRange?.(max, 7);
    B.top = Math.min(B.top, max); B.view = rest.slice(B.top, B.top + 7);
    for (let i = 0; i < 7; i++) { const m = B.view[i], row = c(`btnsublist_${i}`); fill(row, m); row.setEnabled(!!m); }
    for (const [key, id] of Object.entries({ classIndex: 'btn_col_class', level: 'btn_col_lv', name: 'btn_col_name' })) { const on = B.sort.key === key; c(id).setVisible(!on); c(`${id}_h`).setVisible(on && B.sort.dir > 0); c(`${id}_l`).setVisible(on && B.sort.dir < 0); }
    c('btn_ok').setEnabled(!this.busy);   // a wrong count answers 130:445 (click handler)
  }
}
