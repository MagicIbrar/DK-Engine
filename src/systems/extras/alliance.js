import { declineBlockedInvitation } from '../hud-options/invitation-policy.js';
// ALLIANCE: the original guild alliance windows (game2/alliance/*), driven by the host (server/world/alliance.mjs) through the
// guild snapshot field network.guild.alliance and guild operations alliance*. Rules + original sources: alliance-rules.js;
// values the data does not define (timeouts, commands, executives, nameplate, Glory display): src/config/engine-chosen-guild.js.
//   guild window tab btn_alliance -> alliance window (A.Name, A.Cdr, mark, notice, member guilds, Delegate / Expel Guild row popup,
//   Edit Notice, Quit); formation: /ainvite <guild master> -> requester waits (ui_alliancerequest), target answers
//   (ui_allianceinvitewnd 140:12 / 140:16) -> requester names it (ui_alliancename, 2,000,000 DIL 140:58); NPC jobs 77 (alliance mark,
//   ui_alliancemarkselect + confirm) and 78 (delete the Alliance of Glory 140:55); '$' alliance chat; Alliance of Glory items.
import { randomUUID } from '../network/web-crypto.js';
import { SCRIPTS, JOB, STR, TEXT, ROW_HEIGHT, MAX_GUILDS, NOTICE_EDIT_MAX, NAME_MAX, plain, fill } from './alliance-rules.js';
import { ALLIANCE_CHOSEN } from '../../config/engine-chosen-guild.js';
import { setItemIcon, numText, msg } from '../life/common.js';
import { atlas } from '../../ui/atlas.js';

const ref = ([cate, code]) => ({ group: 'NORMAL', cate, code });
const NAMES = { main: 'alliancemain', request: 'alliancerequest', invite: 'allianceinvite', name: 'alliancename', leader: 'allianceleader',
  notice: 'alliancenotice', mark: 'alliancemark', markConfirm: 'alliancemarkconfirm' };
const MARK_RANGE = { bg: 221, icon: 783 }, MARK_PAGE = 60, MARK_COLS = 20;   // = server/world/guilds.mjs GUILD_MARK_RANGE (guildbg / guildicon atlases)
const ROW_TOP = 22;   // ui_alliancewnd.txt btn_record rect y (row template below the column heads)
const TEXT_KEY = new Map(Object.entries(TEXT).map(([k, v]) => [v, k]));

export class Alliance {
  constructor(game) { this.game = game; this.wins = {}; this.rows = []; this.busy = false; this.last = null; this.selected = -1; this.prompted = new Set(); this.pick = { bg: 1, icon: 1 }; }

  async install() {
    const g = this.game, W = g.uiwin;
    if (!W?.registerWindow) return;
    const reg = (key, create, onOpen = () => {}, extra = {}) => W.registerWindow(NAMES[key], { script: SCRIPTS[key], escClose: true, ...extra,
      create: w => { this.wins[key] = w; create.call(this, w); }, onOpen: (w, arg) => onOpen.call(this, w, arg) });
    reg('main', this._createMain, this._renderMain);
    reg('request', this._createRequest, this._renderPrompts);
    reg('invite', this._createInvite, this._renderPrompts);
    reg('name', this._createName, w => { w.control('edit_text').setValue?.(''); w.data = { id: this.state?.outgoing?.find(r => r.stage === 'naming')?.id }; });
    reg('leader', this._createLeader, this._openLeader);
    reg('notice', this._createNotice, w => w.control('textbox').setText?.(this.current?.notice || ''));
    reg('mark', this._createMark, this._openMark);
    reg('markConfirm', this._createMarkConfirm, this._openMarkConfirm);
    try { await W.strings?.need?.(Object.values(STR).map(ref)); } catch { /* strings load lazily */ }
    this._wireNpc();
    g.events?.on?.('systems', () => this._wireNpc());
    const C = ALLIANCE_CHOSEN.COMMANDS;
    g.chat?.registerCommand?.(C.invite, name => { void this.invite(name); return true; }, 'Invite a guild master to form / join your Alliance: /ainvite Name');
    g.chat?.registerCommand?.(C.leave, () => { void this.leave(); return true; }, 'Leave the Alliance (guild master).');
    g.chat?.registerCommand?.(C.window, () => { void this.open(); return true; }, 'Open the Alliance window.');
    g.alliance = this;
  }

  _wireNpc() {
    const s = this.game.npcServices;
    if (!s?.register || this._services === s) return;
    this._services = s;
    s.register(JOB.mark, () => { void this.openMark(); return true; });
    s.register(JOB.deleteMark, () => { void this.deleteGlory(); return true; });
  }

  // ------------------------------------------------------------------ shared
  get gs() { return this.game.network?.guild || null; }
  get state() { return this.gs?.alliance || null; }
  get current() { return this.state?.current || null; }
  get online() { return this.game.save?.authority === 'server' && !!this.game.network; }
  t(pair, fallback = '') { return this.game.uiwin?.strings?.get?.(ref(pair)) ?? fallback; }
  say(pair, ...args) { return plain(fill(this.t(pair, ''), ...args)); }
  note(text, kind = 'sys') { if (text) msg(this.game, text, kind); }
  box(text, kind = 'ok') { return this.game.uiwin.msgbox(text, { kind }); }
  async ask(text) { return (await this.box(text, 'yesno')) === 'yes'; }
  /** A host refusal: the original 140:x / 130:x string when the host answered with its TEXT, else the host message. */
  errorText(message) { const key = TEXT_KEY.get(message); return key && STR[key] ? this.say(STR[key]) || message : message; }
  async send(operation, fields = {}) {
    const n = this.game.network, s = this.gs;
    if (!this.online || !s?.available) { this.note('This server has no durable guild service.', 'err'); return null; }
    if (this.busy) return null;
    this.busy = true;
    try {
      const r = await n.action('guild', { operation, revision: s.revision, requestId: randomUUID(), ...fields });
      if (!r && n._lastCommandError?.message) this.note(this.errorText(n._lastCommandError.message), 'err');
      return r;
    } finally { this.busy = false; this.refresh(); }
  }

  // ------------------------------------------------------------------ live hooks
  update() {
    const g = this.game, n = g.network;
    if (n && this._net !== n && typeof n._event === 'function') {
      this._net = n;
      const event = n._event.bind(n);
      n._event = record => {
        if (record?.type === 'allianceNotice' && Array.isArray(record.code)) { this.note(this.say(record.code, ...(record.args || [])).replace(/\n+/g, ' ')); return; }
        if (record?.type === 'chat' && record.channel === 'alliance') { g.chat?.say?.('alliance', record.name || 'Player', record.text); return; }
        event(record);
      };
    }
    const chat = g.chat;
    if (chat && this._chat !== chat && typeof chat._channel === 'function') {
      this._chat = chat;
      const channel = chat._channel.bind(chat);
      chat._channel = (type, text) => {
        if (type !== 'alliance' || !this.online || !this.gs?.available) return channel(type, text);
        if (!this.current) { chat.system?.(this.say(STR.leaveNotAllied) || TEXT.leaveNotAllied, 'err'); return true; }
        const body = String(text || '').trim(); if (!body) return true;
        void n.action('guild', { operation: 'allianceChat', text: body }).then(r => { if (!r && n._lastCommandError?.message) this.note(this.errorText(n._lastCommandError.message), 'err'); });
        return true;
      };
    }
    const guild = g.guild;
    if (guild && this._guild !== guild) {   // chat.js reads game.guild.alliance ('$' channel)
      this._guild = guild;
      try { Object.defineProperty(guild, 'alliance', { configurable: true, get: () => this.current }); } catch { /* frozen */ }
    }
    const gw = guild?.win;
    if (gw && gw._allianceWired !== gw) {   // guild window tab btn_alliance (ui_guildwnd_base.txt) -> the alliance window
      gw._allianceWired = gw;
      gw.control('btn_alliance')?.onClick?.(() => { gw.control('btn_alliance').setChecked?.(false); if (this.open()) gw.close(); });
    }
    const s = this.gs;
    if (s !== this.last) { this.last = s; this.refresh(); void this._prompts(); }
    this._gauges();
  }

  refresh() {
    const w = this.wins;
    if (w.main?.isOpen) this._renderMain(w.main);
    if (w.request?.isOpen || w.invite?.isOpen) this._renderPrompts();
    const naming = this.state?.outgoing?.find(r => r.stage === 'naming');
    if (w.name?.isOpen && (!naming || naming.id !== w.name.data?.id)) w.name.close();
  }

  // ------------------------------------------------------------------ requests
  async invite(name) {
    const who = String(name || '').trim();
    if (!who) { this.note(this.say(STR.noGuild) || TEXT.noGuild, 'err'); return null; }
    return this.send('allianceInvite', { name: who });
  }
  async _prompts() {
    const st = this.state, W = this.game.uiwin;
    if (!st || !W) return;
    const incoming = st.incoming?.[0], outgoing = st.outgoing?.find(r => r.stage === 'invite'), naming = st.outgoing?.find(r => r.stage === 'naming');
    if (incoming && declineBlockedInvitation(this.game,'blockAlliance',incoming.id,()=>this.send('allianceDecline',{id:incoming.id}))) { this.wins.invite?.close?.(); return; }
    if (incoming && !this.wins.invite?.isOpen && !this.prompted.has(incoming.id)) { this.prompted.add(incoming.id); await W.open(NAMES.invite); }
    if (!incoming && this.wins.invite?.isOpen) this.wins.invite.close();
    if (outgoing && !this.wins.request?.isOpen && !this.prompted.has(outgoing.id)) { this.prompted.add(outgoing.id); await W.open(NAMES.request); }
    if (!outgoing && this.wins.request?.isOpen) this.wins.request.close();
    if (naming && !this.wins.name?.isOpen && !this.prompted.has(`name:${naming.id}`)) {
      this.prompted.add(`name:${naming.id}`); await W.open(NAMES.name);
    }
  }
  _createRequest(w) {
    w.control('btn_cancel').onClick(async () => { const r = w.data?.request; if (r) await this.send('allianceCancel', { id: r.id }); w.close(); });
  }
  _createInvite(w) {
    const answer = async yes => { const r = w.data?.request; w.close(); if (r) await this.send(yes ? 'allianceAccept' : 'allianceDecline', { id: r.id }); };
    w.control('btn_yes').onClick(() => answer(true)); w.control('btn_no').onClick(() => answer(false));
  }
  _renderPrompts() {
    const st = this.state, req = this.wins.request, inv = this.wins.invite;
    if (req?.isOpen) {
      const r = st?.outgoing?.find(x => x.stage === 'invite');
      if (!r) req.close(); else { req.data = { request: r }; req.control('lbl_text').setText(this.say(STR.invited, r.guildName)); }
    }
    if (inv?.isOpen) {
      const r = st?.incoming?.[0];
      if (!r) inv.close(); else { inv.data = { request: r }; inv.control('lbl_text').setText(r.kind === 'join' ? this.say(STR.invitedTo, r.allianceName) : this.say(STR.inviteAsk, r.guildName)); }
    }
    this._gauges();
  }
  _gauges() {
    const total = this.state?.inviteTimeoutMs || ALLIANCE_CHOSEN.INVITE_TIMEOUT_MS, clock = this.game.network?._serverClock, now = clock ? clock.time + (performance.now() - clock.at) : Date.now();
    for (const key of ['request', 'invite']) {
      const w = this.wins[key], r = w?.isOpen && w.data?.request;
      if (r) w.control('processbar').setGauge?.(Math.max(0, Math.min(1, (r.expiresAt - now) / total)));
    }
  }
  _createName(w) {
    const create = async () => {
      const r = this.state?.outgoing?.find(x => x.stage === 'naming'); if (!r) { w.close(); return; }
      const name = String(w.control('edit_text').getValue?.() || '').trim();
      if (!name || [...name].length > NAME_MAX) { this.note(this.say(STR.nameBad) || TEXT.nameBad, 'err'); return; }
      const cost = this.state?.formCost;
      if (!await this.ask(`${this.t([140, 2], 'A.Name')}: ${name}${cost ? `\n${numText(cost)} DIL` : ''}`)) return;
      if (await this.send('allianceCreate', { id: r.id, name })) w.close();
    };
    const cancel = async () => { const r = this.state?.outgoing?.find(x => x.stage === 'naming'); w.close(); if (r) await this.send('allianceCancel', { id: r.id }); };
    w.control('btn_yes').onClick(create); w.control('btn_no').onClick(cancel); w.control('btn_exit')?.onClick?.(cancel);
  }

  // ------------------------------------------------------------------ alliance window
  open() {
    const s = this.gs;
    if (!this.online || !s?.available) { void this.box('This server has no durable guild service.'); return false; }
    if (!s.founded) { this.note(this.say(STR.leaveNoGuild) || TEXT.leaveNoGuild, 'err'); return false; }
    return this.game.uiwin.open(NAMES.main);
  }
  _createMain(w) {
    // The window loads the guild window frame (loadchild ui_guildwnd_base.txt: pan_top / pan_mid / pan_bottom, layer 1) BEFORE its own
    // layer-1 panels; the original draws equal layers in script order, so the frame stays underneath (the guild window's own panels
    // are layer 2). Keep the loaded frame below this window's panels.
    for (const id of ['pan_top', 'pan_mid', 'pan_bottom']) { const el = w.control(id)?.el; if (el) el.style.zIndex = '0'; }
    this.rows = Array.from({ length: MAX_GUILDS }, (_, i) => w.clone('btn_record', `_${i}`, { x: 0, y: ROW_TOP + i * ROW_HEIGHT, visible: false }));
    this.rows.forEach((row, i) => { const b = w.control(`btn_record_${i}`); b?.setEnabled?.(true); b?.onClick?.(() => this._selectRow(w, i)); });   // the scripted template is disabled
    const pop = w.control('pan_recordpop');
    w.control('btn_leaderchange').onClick(() => { pop.setVisible(false); const row = this.current?.guilds?.[this.selected]; if (row) void this.game.uiwin.open(NAMES.leader, row); });
    w.control('btn_kick').onClick(async () => {
      pop.setVisible(false); const row = this.current?.guilds?.[this.selected]; if (!row) return;
      if (await this.ask(this.say(STR.expelAsk, row.name))) await this.send('allianceKick', { id: row.id });
    });
    w.control('btn_notice').onClick(() => { void this.game.uiwin.open(NAMES.notice); });
    w.control('btn_secede').onClick(() => { void this.leave(); });
    w.control('btn_exit').onClick(() => w.close());
    w.control('textbox').setEnabled?.(true);   // read-only display; scrolling stays available
    // guild window tabs: Guild, Participant / Skills / War Status (src/systems/extras/guildextras.js)
    const X = () => this.game.guildExtras, main = () => this.game.uiwin.open('guild');
    const tabs = { btn_guild: main, btn_member: () => X() ? X().openMembers() : main(), btn_guildskill: () => X() ? X().openSkills() : main(), btn_warhistory: () => X() ? X().openWarHistory() : main() };
    for (const [id, go] of Object.entries(tabs)) w.control(id)?.onClick?.(() => { w.control(id).setChecked?.(false); if (go()) w.close(); });
    w.control('btn_history')?.onClick?.(() => { if (this.game.guildBoard?.openHistory?.()) w.close(); });
    w.control('btn_alliance')?.onClick?.(() => w.control('btn_alliance').setChecked?.(true));
  }
  _selectRow(w, i) {
    const a = this.current, row = a?.guilds?.[i], pop = w.control('pan_recordpop');
    this.selected = row ? i : -1;
    for (let j = 0; j < this.rows.length; j++) w.control(`btn_record_${j}`)?.setChecked?.(j === this.selected);
    if (!row || !a.isCommander || row.id === a.commanderGuild) { pop.setVisible(false); return; }
    pop.move?.(176, 160 + 133 + ROW_TOP + (i + 1) * ROW_HEIGHT); pop.setVisible(true);   // under the clicked row (pan_body 160 + pan_memList 133 + btn_record 22)
  }
  _renderMain(w) {
    const a = this.current;
    w.control('btn_alliance')?.setChecked?.(true);
    w.control('lbl_alliancename').setText(a?.name || '');
    w.control('lbl_leadername').setText(a?.commanderName || '');
    const mark = a?.mark;
    w.control('pan_markback').setVisible(!!mark); w.control('pan_markfront').setVisible(!!mark);
    if (mark) { w.control('pan_markback').setImage('none', 'guildbg', mark.bg); w.control('pan_markfront').setImage('none', 'guildicon', mark.icon); }
    // ENGINE-CHOSEN GLORY_DISPLAY: the Alliance of Glory item in pan_iconimg (44x44 over the 40x40 mark), only while one is set
    w.control('pan_iconimg').setVisible(!!a?.glory); setItemIcon(this.game, w.control('pan_iconimg'), a?.glory?.itemIndex || 0, 0, 44, 44);
    w.control('textbox').setText?.(a?.notice || '');
    const rows = a?.guilds || [];
    this.rows.forEach((slot, i) => {
      const row = rows[i]; slot?.setVisible?.(!!row); if (!row) return;
      w.control(`lbl_recnumber_${i}`).setText(String(i + 1));
      w.control(`lbl_recguildname_${i}`).setText(row.id === a.commanderGuild ? `${row.name} *` : row.name);
      w.control(`lbl_reccapname_${i}`).setText(row.masterName || '');
      w.control(`lbl_recmemcount_${i}`).setText(String(row.members));
    });
    if (this.selected >= rows.length || !a?.isCommander) { this.selected = -1; w.control('pan_recordpop').setVisible(false); }
    const enable = (id, v) => { const c = w.control(id); if (c && c.enabled !== v) c.setEnabled?.(v); };
    enable('btn_notice', !!a?.isCommander && !this.busy);
    enable('btn_secede', !!a?.isExecutive && !a?.isCommander && !this.busy);
  }
  async leave() {
    const a = this.current;
    if (!a) { this.note(this.say(STR.leaveNotAllied) || TEXT.leaveNotAllied, 'err'); return null; }
    if (!await this.ask(this.say(STR.leaveAsk))) return null;
    return this.send('allianceLeave');
  }

  // delegate: type the target's name (140:113 / 140:114)
  _createLeader(w) {
    const go = async () => {
      const row = w.data?.row, typed = String(w.control('edit_text').getValue?.() || '').trim();
      if (!row) { w.close(); return; }
      if (typed !== row.masterName) { this.note(`${row.masterName}${this.say(STR.delegateMustType)}`, 'err'); return; }
      if (await this.send('allianceDelegate', { name: row.masterName })) w.close();
    };
    w.control('btn_confirm').onClick(go); w.control('btn_cancel').onClick(() => w.close());
  }
  _openLeader(w, row) { w.data = { row }; w.control('lbl_text').setText(this.say(STR.delegateType, row?.masterName || '')); w.control('edit_text').setValue?.(''); }

  _createNotice(w) {
    w.control('btn_deleteAll').onClick(() => w.control('textbox').setText?.(''));
    w.control('btn_regist').onClick(async () => {
      const notice = String(w.control('textbox').getText?.() || '').slice(0, NOTICE_EDIT_MAX);
      if (await this.send('allianceNotice', { notice })) w.close();
    });
    w.control('btn_exit')?.onClick?.(() => w.close());
  }

  // ------------------------------------------------------------------ NPC 77: alliance mark
  openMark() {
    const a = this.current;
    if (!this.online || !this.gs?.available) { this.note('This server has no durable guild service.', 'err'); return false; }
    if (!a) { this.note(this.say(STR.markNotMember) || TEXT.markNotMember, 'err'); return false; }
    if (!a.isCommander) { this.note(this.say(STR.markPermission) || TEXT.markPermission, 'err'); return false; }
    return this.game.uiwin.open(NAMES.mark);
  }
  _createMark(w) {
    const grids = { bg: { panel: 'pan_markbg', cursor: 'pan_bgCursor', small: 'guildbg_s' }, icon: { panel: 'pan_mark', cursor: 'pan_iconCursor', small: 'guildicon_s' } };
    this.markCells = { bg: [], icon: [] }; this.markPage = { bg: 0, icon: 0 };
    const pages = kind => Math.ceil(MARK_RANGE[kind] / MARK_PAGE);
    this._paintMark = () => {
      for (const kind of ['bg', 'icon']) {
        const gdef = grids[kind];
        this.markCells[kind].forEach((cell, i) => {
          const index = this.markPage[kind] * MARK_PAGE + i + 1, token = cell._tok = {};
          cell.style.backgroundImage = ''; cell.style.visibility = index <= MARK_RANGE[kind] ? '' : 'hidden';
          if (index <= MARK_RANGE[kind]) void atlas.sprite(gdef.small, index).then(sp => { if (cell._tok === token && sp) cell.style.backgroundImage = `url("${sp.url}")`; });
        });
        const at = this.pick[kind] - 1 - this.markPage[kind] * MARK_PAGE, cursor = w.control(gdef.cursor);
        cursor.setVisible(at >= 0 && at < MARK_PAGE);
        if (at >= 0 && at < MARK_PAGE) cursor.move((at % MARK_COLS) * 24, Math.floor(at / MARK_COLS) * 24);
      }
      w.control('pan_selectalliancemarkbg').setImage('none', 'guildbg', this.pick.bg); w.control('pan_selectalliancemark').setImage('none', 'guildicon', this.pick.icon);
    };
    for (const kind of ['bg', 'icon']) {
      const host = w.control(grids[kind].panel).el;
      for (let i = 0; i < MARK_PAGE; i++) {
        const cell = document.createElement('div');
        cell.style.cssText = `position:absolute;left:${(i % MARK_COLS) * 24}px;top:${Math.floor(i / MARK_COLS) * 24}px;width:24px;height:24px;pointer-events:auto;cursor:pointer;background-size:100% 100%;background-repeat:no-repeat`;
        cell.dataset.markKind = kind; cell.dataset.markCell = String(i);
        cell.addEventListener('click', () => { const index = this.markPage[kind] * MARK_PAGE + i + 1; if (index <= MARK_RANGE[kind] && !this.busy) { this.pick[kind] = index; this._paintMark(); } });
        host?.appendChild(cell); this.markCells[kind].push(cell);
      }
    }
    for (const [kind, left, right] of [['bg', 'btn_bgLeft', 'btn_bgRight'], ['icon', 'btn_iconLeft', 'btn_iconRight']]) {
      w.control(left).onClick(() => { this.markPage[kind] = (this.markPage[kind] + pages(kind) - 1) % pages(kind); this._paintMark(); });
      w.control(right).onClick(() => { this.markPage[kind] = (this.markPage[kind] + 1) % pages(kind); this._paintMark(); });
    }
    w.control('btn_exit').onClick(() => w.close());
    w.control('btn_regist').onClick(() => { void this.game.uiwin.open(NAMES.markConfirm); });
  }
  _openMark(w) {
    const cur = this.current?.mark;
    this.pick = { bg: cur?.bg || 1, icon: cur?.icon || 1 };
    this.markPage = { bg: Math.floor((this.pick.bg - 1) / MARK_PAGE), icon: Math.floor((this.pick.icon - 1) / MARK_PAGE) };
    w.control('pan_alliancemarkbg').setVisible(!!cur); w.control('pan_alliancemark').setVisible(!!cur);
    if (cur) { w.control('pan_alliancemarkbg').setImage('none', 'guildbg', cur.bg); w.control('pan_alliancemark').setImage('none', 'guildicon', cur.icon); }
    this._paintMark?.();
  }
  _createMarkConfirm(c) {
    c.control('btn_no').onClick(() => c.close()); c.control('btn_exit')?.onClick?.(() => c.close());
    c.control('btn_yes').onClick(async () => { if (await this.send('allianceMark', { bg: this.pick.bg, icon: this.pick.icon })) { c.close(); this.wins.mark?.close(); } });
  }
  _openMarkConfirm(c) {
    c.control('pan_markBg').setImage('none', 'guildbg', this.pick.bg); c.control('pan_markIcon').setImage('none', 'guildicon', this.pick.icon);
    c.control('lbl_msg').setText(plain(this.t([130, 230], 'Register this mark?')));   // the cost follows in 140:68
  }

  // ------------------------------------------------------------------ NPC 78 / Alliance of Glory
  async deleteGlory() {
    const a = this.current;
    if (!a) { this.note(this.say(STR.gloryNotInAlliance) || TEXT.gloryNotInAlliance, 'err'); return null; }
    if (!a.isCommander) { this.note(this.say(STR.gloryDeletePermission) || TEXT.gloryDeletePermission, 'err'); return null; }
    if (!a.glory) { this.note(this.say(STR.gloryNone) || TEXT.gloryNone, 'err'); return null; }
    if (!await this.ask(this.say(STR.gloryDeleteAsk))) { this.note(this.say(STR.gloryDeleteCancel)); return null; }
    return this.send('allianceDeleteGlory');
  }
  /** items/use.js Type 0 Code 30: the host checks the commander and spends the item. Returns true when handled. */
  useGlory(inst, def) {
    if (!this.online || !this.gs?.available) return false;
    const a = this.current;
    if (!a) { this.note(this.say(STR.gloryNotInAlliance) || TEXT.gloryNotInAlliance, 'err'); return true; }
    if (!a.isCommander) { this.note(this.say(STR.gloryPermission) || TEXT.gloryPermission, 'err'); return true; }
    void (async () => { if (await this.ask(`${def?.name || 'Alliance of Glory'}?`)) await this.send('allianceGlory', { uid: inst.uid }); })();
    return true;
  }
  dispose() { for (const w of Object.values(this.wins)) { try { w?.close?.(); } catch { /* ignore */ } } }
}
