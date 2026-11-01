// The guild remainder windows, driven by the host (server/world/guild-extras.mjs) through the guild snapshot
// (network.guild.members[].online / map / lastSeen, network.guild.extras) and guild operations guildSkill / war*. Rules + original
// sources: guildextras-rules.js; values the data does not define: src/config/engine-chosen-guild.js.
//   guild window tabs (ui_guildwnd_base.txt): btn_member -> Participant list (ui_guildmemberwnd: Name / Class / Rank / Contribution /
//     Last Login, row popup Change ranks / Expel / Whisper / Current Location / See Info (ui_memberinfownd) / Appoint Guild
//     (ui_delegatewnd, type 130:225 'I appoint')); btn_guildskill -> Guild Skills (ui_gskillwnd_renew, guildskill.csv);
//     btn_warhistory -> War Status (ui_guildwarhistorywnd).
//   guild war: player menu 240:13 Declare War (and /gwar Name) -> ui_declarationofwarwnd (135:3, 3/7/15/30 days, 135:25) ->
//     the target guild master answers in ui_acceptanceofwarwnd (135:21 / 135:26); Guild sign NPC (DECLARE_WAR) -> ui_guildwarboardwnd.
import { randomUUID } from '../network/web-crypto.js';
import { SCRIPTS, BOARD_WINDOW, SKILL_ICON, SKILL_GROUPS, WAR_DAYS, WAR_DAY_CODES, WAR_STATUS, MEMBER_ROWS, HISTORY_ROWS, BOARD_ROWS, MY_BOARD_ROWS,
  ROW_HEIGHT, BOARD_ROW_HEIGHT, STR, TEXT, plain, fill, delegatePhrase, skillGroup, skillById, skillDilCost, skillDilDiscount, durationText } from './guildextras-rules.js';
import { GUILD_WAR_CHOSEN } from '../../config/engine-chosen-guild.js';
import { numText, msg } from '../life/common.js';
import { installPcPop } from '../pvp/duel.js';
import { repairGuildDurationClones } from './guild-ui-clone-repair.js';
import {guildWindowSurface} from '../../ui/guild-window-surface.js';

const ref = ([cate, code]) => ({ group: 'NORMAL', cate, code });
const FRAME_KEYS = ['member', 'skill', 'warHistory'];
const NAMES = { member: 'guildmembers', memberInfo: 'guildmemberinfo', delegate: 'guilddelegate', skill: 'guildskills', warHistory: 'guildwarhistory',
  declare: 'guildwardeclare', accept: 'guildwaraccept', board: BOARD_WINDOW };
const TEXT_KEY = new Map(Object.entries(TEXT).map(([k, v]) => [v, k]));
const TABS = ['btn_guild', 'btn_member', 'btn_guildskill', 'btn_alliance', 'btn_history', 'btn_warhistory'];
const pad = n => String(n).padStart(2, '0');
const dateText = ms => { if (!Number.isFinite(ms)) return '-'; const d = new Date(ms); return `${d.getFullYear()}-${pad(d.getMonth() + 1)}-${pad(d.getDate())} ${pad(d.getHours())}:${pad(d.getMinutes())}`; };
const cmp = (a, b) => (typeof a === 'string' || typeof b === 'string') ? String(a ?? '').localeCompare(String(b ?? '')) : (a ?? -Infinity) - (b ?? -Infinity);

export class GuildExtras {
  constructor(game) {
    this.game = game; this.wins = {}; this.busy = false; this.last = null; this.prompted = new Set();
    this.member = { rows: [], sort: { key: 'rank', dir: 1 }, top: 0, list: [], selected: null };
    this.history = { rows: [], sort: { key: 'start', dir: -1 }, top: 0, list: [] };
    this.board = { page: 0, rows: [], mine: [] };
    this.sel = {};
  }

  async install() {
    const g = this.game, W = g.uiwin;
    if (!W?.registerWindow) return;
    const reg = (key, create, onOpen = () => {}, extra = {}) => W.registerWindow(NAMES[key], { script: SCRIPTS[key], escClose: true, ...extra,
      create: w => { this.wins[key] = w; create.call(this, w); }, onOpen: (w, arg) => { if (FRAME_KEYS.includes(key)) this._closeFrames(key); return onOpen.call(this, w, arg); } });
    reg('member', this._createMember, this._openMember);
    reg('memberInfo', this._createInfo, this._openInfo);
    reg('delegate', this._createDelegate, this._openDelegate);
    reg('skill', this._createSkill, this._renderSkill);
    reg('warHistory', this._createHistory, this._openHistory);
    reg('declare', this._createDeclare, this._openDeclare);
    reg('accept', this._createAccept, this._openAccept);
    reg('board', this._createBoard, this._openBoard);
    try { await W.strings?.need?.([...Object.values(STR), ...WAR_DAY_CODES.map(c => [135, c]), ...Object.values(WAR_STATUS).map(c => [135, c]),
      ...this.skills.map(r => [130, r.desc]), [130, 160], [100, 53]].map(ref)); } catch { /* strings load lazily */ }
    const pop = g.pcpop || installPcPop(g);
    pop.add({ code: 13, visible: t => this._canDeclareOn(t), run: t => { void this.declare(t); } });
    g.chat?.registerCommand?.(GUILD_WAR_CHOSEN.COMMAND, name => { void this.declareByName(name); return true; }, 'Declare guild war on a nearby character\'s guild: /gwar Name');
    g.guildExtras = this;
  }

  // ------------------------------------------------------------------ shared
  get gs() { return this.game.network?.guild || null; }
  get ex() { return this.gs?.extras || null; }
  get lifeGuild() { return this.game.life?.guild || this.game.guild || null; }
  get skills() { return this.lifeGuild?.G?.skills || this.game.data?.life?.guild?.skills || []; }
  get online() { return this.game.save?.authority === 'server' && !!this.game.network; }
  t(pair, fallback = '') { return this.game.uiwin?.strings?.get?.(ref(pair)) ?? fallback; }
  say(pair, ...args) { return plain(fill(this.t(pair, ''), ...args.map(a => Array.isArray(a) ? plain(this.t(a, '')) : a))); }
  note(text, kind = 'sys') { if (text) msg(this.game, text, kind); }
  box(text, kind = 'ok') { return this.game.uiwin.msgbox(text, { kind }); }
  async ask(text) { return (await this.box(text, 'yesno')) === 'yes'; }
  errorText(message) { const key = TEXT_KEY.get(message); return key && STR[key] ? this.say(STR[key]) || message : message; }
  serverNow() { const c = this.game.network?._serverClock; return c ? c.time + (performance.now() - c.at) : Date.now(); }
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
  className(i) { return this.game.data?.classByIndex?.get?.(Number(i))?.name || ''; }
  mapName(m) { return String(this.game.mapRow?.(m)?.Name || this.game.data?.map?.(m)?.name || `Map ${m}`).trim(); }
  statusWord(s) { return plain(this.t([135, WAR_STATUS[s] || 113], s || '')); }
  /** Guild window frame (loadchild ui_guildwnd_base.txt, layer 1) below the window's own layer-1 panels; tab row wiring. */
  _frame(w, current) {
    guildWindowSurface(w);
    for (const id of ['pan_top', 'pan_mid', 'pan_bottom']) { const el = w.control(id)?.el; if (el) el.style.zIndex = '0'; }
    const go = { btn_guild: () => this.game.uiwin.open('guild'), btn_member: () => this.openMembers(), btn_guildskill: () => this.openSkills(),
      btn_alliance: () => this.game.alliance?.open?.(), btn_history: () => this.game.guildBoard?.openHistory?.(), btn_warhistory: () => this.openWarHistory() };
    for (const id of TABS) w.control(id)?.onClick?.(() => { if (id === current) { w.control(id).setChecked?.(true); return; } w.control(id).setChecked?.(false); if (go[id]?.()) w.close(); });
    w.control('btn_exit')?.onClick?.(() => w.close());
  }
  /** The guild frame windows share one screen spot: opening one tab window closes the others (and the main guild window). */
  _closeFrames(keep) {
    for (const k of FRAME_KEYS) if (k !== keep && this.wins[k]?.isOpen) this.wins[k].close();
    const gw = this.lifeGuild?.win; if (keep && gw?.isOpen) gw.close?.();
  }
  _tabState(w, current) { for (const id of TABS) w.control(id)?.setChecked?.(id === current); }
  _need() {
    const s = this.gs;
    if (!this.online || !s?.available) { void this.box('This server has no durable guild service.'); return false; }
    if (!s.founded) { this.note(this.say(STR.guildMissing) || TEXT.guildMissing, 'err'); return false; }
    return true;
  }

  // ------------------------------------------------------------------ live hooks
  update() {
    const g = this.game, n = g.network;
    if (n && this._net !== n && typeof n._event === 'function') {
      this._net = n;
      const event = n._event.bind(n);
      n._event = record => {
        if (record?.type === 'guildNotice' && Array.isArray(record.code)) { this.note(this.say(record.code, ...(record.args || [])).replace(/\n+/g, ' ')); return; }
        if (record?.type === 'guildNotice' && typeof record.text === 'string') { this.note(record.text); return; }   // guild war PvP kill (server/world/guild-war-pvp.mjs)
        event(record);
      };
    }
    // Guild war PvP: members of a guild at active war are hostile on PvP-allowed open maps (host list extras.warFoes).
    if (!g.isPvpHostile?._chained?.has('guildWar')) { const prev = g.isPvpHostile, f = a => this.isWarFoe(a) || !!prev?.(a); f._chained = new Set([...(prev?._chained || []), 'guildWar']); g.isPvpHostile = f; }
    const gw = this.lifeGuild?.win;
    if (gw && gw._extrasWired !== gw) {   // the guild window's tabs (mail-guild.js wires btn_history / ALLIANCE wires btn_alliance)
      gw._extrasWired = gw;
      for (const [id, open] of [['btn_member', () => this.openMembers()], ['btn_guildskill', () => this.openSkills()], ['btn_warhistory', () => this.openWarHistory()]])
        gw.control(id)?.onClick?.(() => { gw.control(id).setChecked?.(false); if (open()) gw.close(); });
    }
    const gwOpen = !!gw?.isOpen; if (gwOpen && !this._gwOpen) this._closeFrames(null); this._gwOpen = gwOpen;
    const s = this.gs;
    if (s !== this.last) { this.last = s; this.refresh(); void this._prompts(); }
    const sk = this.wins.skill; if (sk?.isOpen && this.ex?.skill && (this._tick = (this._tick || 0) + 1) % 30 === 0) this._renderSkill(sk);
  }
  refresh() {
    const w = this.wins;
    if (w.member?.isOpen) this._renderMember(w.member);
    if (w.skill?.isOpen) this._renderSkill(w.skill);
    if (w.warHistory?.isOpen) this._renderHistory(w.warHistory);
    if (w.board?.isOpen) this._renderBoard(w.board);
    if (w.accept?.isOpen && !this.ex?.incoming?.some(r => r.id === w.accept.data?.war?.id)) w.accept.close();
  }
  async _prompts() {
    const next = this.ex?.incoming?.find(r => !this.prompted.has(r.id));
    if (next && !this.wins.accept?.isOpen) { this.prompted.add(next.id); await this.game.uiwin.open(NAMES.accept, next); }
  }

  // ------------------------------------------------------------------ Participant (member list)
  openMembers() { if (!this._need()) return false; return this.game.uiwin.open(NAMES.member); }
  _createMember(w) {
    this._frame(w, 'btn_member');
    const list = w.control('pan_memList'), M = this.member;
    M.rows = Array.from({ length: MEMBER_ROWS }, (_, i) => w.clone('btn_record', `_${i}`, { x: 0, y: 25 + i * ROW_HEIGHT, parent: list, visible: false }));
    M.rows.forEach((row, i) => { row.setEnabled?.(true); row.onClick?.(() => this._selectMember(w, i)); });
    const cols = [['btn_col_name', 'name'], ['btn_col_class', 'classIndex'], ['btn_col_rank', 'rank'], ['btn_col_contribution', 'contribution'], ['btn_col_conn', 'conn']];
    for (const [id, key] of cols) for (const sfx of ['', '_asc', '_desc']) w.control(id + sfx).onClick(() => { M.sort = { key, dir: M.sort.key === key ? -M.sort.dir : 1 }; this._renderMember(w); });
    const sc = w.control('memList_scroll'); sc.on?.('change', v => { M.top = Number(v) || 0; this._renderMember(w, true); });
    list.on?.('wheel', (e, d) => { sc.setValue?.((Number(sc.getValue?.()) || 0) + d, false); });
    const pop = w.control('pan_memberPop'), member = () => M.selected && this.gs?.members?.find(m => m.ref === M.selected);
    const act = fn => () => { pop.setVisible(false); const m = member(); if (m) fn(m); };
    w.control('btn_chgGrade').onClick(act(m => { void this.lifeGuild?._setRank?.(m.name); }));
    w.control('btn_kick').onClick(act(async m => { if (await this.ask(`${plain(this.t(STR.kick, 'Expel'))}: ${m.name}?`)) await this.send('kick', { targetRef: m.ref }); }));
    w.control('btn_whisper').onClick(act(m => { this.game.chat?.openInput?.(`"${m.name} `); }));
    w.control('btn_curPos').onClick(act(m => { this.note(`${m.name}: ${m.online && m.map != null ? this.mapName(m.map) : plain(this.t(STR.none, 'None'))}`); }));
    w.control('btn_desc').onClick(act(m => { void this.game.uiwin.open(NAMES.memberInfo, m); }));
    w.control('btn_delegate').onClick(act(m => { void this.game.uiwin.open(NAMES.delegate, m); }));
  }
  _openMember(w) { this.member.top = 0; this.member.selected = null; w.control('pan_memberPop').setVisible(false); this._renderMember(w); }
  _memberRows() {
    const M = this.member, rows = [...(this.gs?.members || [])].map(m => ({ ...m, conn: m.online ? Infinity : (m.lastSeen ?? -Infinity) }));
    return rows.sort((a, b) => cmp(a[M.sort.key], b[M.sort.key]) * M.sort.dir || a.name.localeCompare(b.name));
  }
  _renderMember(w, scrolled = false) {
    const M = this.member; this._tabState(w, 'btn_member');
    M.list = this._memberRows();
    const max = Math.max(0, M.list.length - MEMBER_ROWS);
    if (!scrolled) w.control('memList_scroll').setRange?.(max, MEMBER_ROWS);
    M.top = Math.min(M.top, max);
    const cols = { name: 'btn_col_name', classIndex: 'btn_col_class', rank: 'btn_col_rank', contribution: 'btn_col_contribution', conn: 'btn_col_conn' };
    for (const [key, id] of Object.entries(cols)) { const on = M.sort.key === key; w.control(id).setVisible(!on); w.control(`${id}_asc`).setVisible(on && M.sort.dir > 0); w.control(`${id}_desc`).setVisible(on && M.sort.dir < 0); }
    M.rows.forEach((row, i) => {
      const m = M.list[M.top + i]; row.setVisible(!!m); if (!m) return;
      row.setChecked?.(m.ref === M.selected);
      w.control(`lbl_recName_${i}`).setText(m.name);
      w.control(`lbl_recClass_${i}`).setText(this.className(m.classIndex));
      w.control(`lbl_recGrade_${i}`).setText(m.grade || '');
      w.control(`lbl_recConRatio_${i}`).setText(numText(m.contribution || 0));
      w.control(`lbl_recConn_${i}`).setText(m.online ? 'Online' : m.lastSeen ? dateText(m.lastSeen).slice(5, 10) : '-');
      w.control(`lbl_recConn_${i}`).setColor?.(m.online ? '#64ff64' : '');
    });
    const s = this.gs, sel = M.list.find(m => m.ref === M.selected);
    const me = s?.myRef, perm = s?.permissions || {}, master = s?.master === me;
    const en = (id, v) => { const c = w.control(id); if (c && c.enabled !== v) c.setEnabled?.(v); };
    en('btn_chgGrade', !!sel && !!perm.changeRank && sel.ref !== me && sel.ref !== s?.master && !this.busy);
    en('btn_kick', !!sel && !!perm.kick && sel.ref !== me && sel.ref !== s?.master && !this.busy);
    en('btn_whisper', !!sel && sel.ref !== me); en('btn_curPos', !!sel); en('btn_desc', !!sel);
    en('btn_delegate', !!sel && master && sel.ref !== me && !this.busy);
    if (!sel) w.control('pan_memberPop').setVisible(false);
  }
  _selectMember(w, i) {
    const M = this.member, m = M.list[M.top + i], pop = w.control('pan_memberPop');
    M.selected = m ? m.ref : null; this._renderMember(w);
    if (!m) { pop.setVisible(false); return; }
    pop.move?.(150, Math.min(443 - 132, 25 + (i + 1) * ROW_HEIGHT)); pop.setVisible(true);
  }
  _createInfo(w) { for (const id of ['btn_yes', 'btn_exit']) w.control(id).onClick(() => w.close()); }
  _openInfo(w, m) {
    const cur = this.gs?.members?.find(x => x.ref === m?.ref) || m || {};
    w.control('lbl_memberName').setText(cur.name || ''); w.control('lbl_class').setText(this.className(cur.classIndex));
    w.control('lbl_grade').setText(cur.grade || ''); w.control('lbl_level').setText(cur.level ? String(cur.level) : '-');
    w.control('lbl_Contribution').setText(numText(cur.contribution || 0));
  }
  _createDelegate(w) {
    const go = async () => {
      const m = w.data?.member, typed = String(w.control('edit_text').getValue?.() || '').trim(), phrase = delegatePhrase(this.t(STR.delegatePrompt, "'I appoint'")) || 'I appoint';
      if (!m) { w.close(); return; }
      if (typed.toLowerCase() !== phrase.toLowerCase()) { this.note(this.say(STR.delegatePrompt).replace(/\n+/g, ' '), 'err'); return; }
      if (await this.send('transfer', { targetRef: m.ref })) w.close();
    };
    w.control('btn_yes').onClick(go); w.control('btn_no').onClick(() => w.close()); w.control('btn_exit').onClick(() => w.close());
  }
  _openDelegate(w, m) { w.data = { member: m }; w.control('lbl_title').setText(`${plain(this.t(STR.appoint, 'Appoint Guild'))}: ${m?.name || ''}`); w.control('edit_text').setValue?.('');
    w.control('lbl_text').setText(plain(this.t(STR.delegatePrompt, "To Appoint the Guild Mastership, please enter 'I appoint'.")).replace(/\s*\n\s*/g, ' ')); }

  // ------------------------------------------------------------------ Guild Skills (guildskill.csv)
  openSkills() { if (!this._need()) return false; return this.game.uiwin.open(NAMES.skill); }
  _item(w, i) { return w.find?.(`btn_item${i}`) || null; }
  _pick(group) {
    const G = skillGroup(this.skills, group), s = this.sel[group] ||= { li: 0, ti: 0 };
    const running = skillById(this.skills, this.ex?.skill?.id);
    if (!s.touched && running?.group === group) { s.li = Math.max(0, G.levels.indexOf(running.level)); s.ti = Math.max(0, G.times(running.level).findIndex(r => r.id === running.id)); }
    s.li = Math.max(0, Math.min(G.levels.length - 1, s.li)); const times = G.times(G.levels[s.li]); s.ti = Math.max(0, Math.min(times.length - 1, s.ti));
    return { G, s, row: times[s.ti] || null, times };
  }
  _createSkill(w) {
    this._frame(w, 'btn_guildskill');
    w.control('vscroll')?.setVisible?.(false);   // both groups fit the list
    SKILL_GROUPS.forEach((group, i) => {
      const item = this._item(w, i); if (!item) return;
      repairGuildDurationClones(item);
      item.setEnabled?.(true);
      const step = (key, d) => () => { const s = this.sel[group] ||= { li: 0, ti: 0 }; s.touched = true; s[key] += d; if (key === 'li') s.ti = Math.max(0, s.ti); this._renderSkill(w); };
      item.control('btn_minus_level')?.onClick?.(step('li', -1)); item.control('btn_plus_level')?.onClick?.(step('li', 1));
      item.control('btn_minus_time')?.onClick?.(step('ti', -1)); item.control('btn_plus_time')?.onClick?.(step('ti', 1));
      item.control('btn_use')?.onClick?.(() => { void this.enableSkill(group); });
    });
  }
  _renderSkill(w) {
    this._tabState(w, 'btn_guildskill');
    const s = this.gs || {}, ex = this.ex || {}, now = this.serverNow(), running = ex.skill && ex.skill.expiresAt > now ? skillById(this.skills, ex.skill.id) : null;
    const words = { day: plain(this.t(STR.day, 'Day')), minutes: plain(this.t(STR.minutes, 'Minutes')) };
    SKILL_GROUPS.forEach((group, i) => {
      const item = this._item(w, i); if (!item) return;
      const { G, s: sel, row, times } = this._pick(group), c = id => item.control(id);
      if (!row) { item.setVisible?.(false); return; }
      item.setVisible?.(true);
      c('lbl_name')?.setText?.(row.name);
      c('lbl_info')?.setText?.(plain(this.t([130, row.desc], '')));
      c('pan_iconimg')?.setImage?.('none', SKILL_ICON, row.icon);
      c('lbl_skill_level')?.setText?.(String(G.levels[sel.li]));
      c('lbl_skill_time')?.setText?.(durationText(row.sec, words));
      // Guild DIL less the guild-level reduction (official guide 5, rules SKILL_DIL_DISCOUNT); lbl_dil_discount names the rate
      // with the 130:455 "Discount" word (ENGINE-CHOSEN line format; the data has the control, not its text layout).
      const lv = s.level || 1, pct = skillDilDiscount(lv);
      c('lbl_gpoint_use')?.setText?.(numText(row.gpoint)); c('lbl_point_use')?.setText?.(numText(row.adv)); c('lbl_dil_use')?.setText?.(numText(skillDilCost(row, lv)));
      c('lbl_dil_discount')?.setText?.(pct ? `${plain(this.t([130, 455], 'Discount'))} ${pct}%` : '');
      const inUse = running?.group === group;
      c('pan_used')?.setVisible?.(inUse);
      const left = inUse ? Math.max(0, Math.floor((ex.skill.expiresAt - now) / 1000)) : 0;
      c('lbl_time')?.setText?.(inUse ? `${plain(this.t(STR.time, 'Time'))}: ${Math.floor(left / 86400)}${words.day} ${pad(Math.floor(left % 86400 / 3600))}:${pad(Math.floor(left % 3600 / 60))}` : '');
      const en = (id, v) => { const x = c(id); if (x && x.enabled !== v) x.setEnabled?.(v); };
      en('btn_minus_level', sel.li > 0); en('btn_plus_level', sel.li < G.levels.length - 1); en('btn_minus_time', sel.ti > 0); en('btn_plus_time', sel.ti < times.length - 1);
      en('btn_use', !!ex.isMaster && !this.busy && (s.level || 1) >= row.needLevel);
    });
    w.control('lbl_gpoint_my').setText(numText(s.activityPoints || 0)); w.control('lbl_point_my').setText(numText(s.gpoint || 0)); w.control('lbl_dil_my').setText(numText(s.dil || 0));
  }
  async enableSkill(group) {
    const { row } = this._pick(group); if (!row) return null;
    const ex = this.ex || {}, now = this.serverNow(), running = ex.skill && ex.skill.expiresAt > now ? skillById(this.skills, ex.skill.id) : null;
    const q = running ? plain(this.t(STR.replaceAsk, '')).replace('[SKILL_PRE]', running.name).replace('[SKILL]', row.name) : plain(this.t(STR.applyAsk, 'Apply current Guild Skill?'));
    if (!await this.ask(`${q}\n${row.name}\n${plain(this.t([130, 363]))} ${numText(row.gpoint)} / ${plain(this.t([130, 364]))} ${numText(row.adv)} / ${plain(this.t([130, 365]))} ${numText(skillDilCost(row, this.gs?.level || 1))}`)) return null;
    return this.send('guildSkill', { skillId: row.id });
  }

  // ------------------------------------------------------------------ War Status
  openWarHistory() { if (!this._need()) return false; return this.game.uiwin.open(NAMES.warHistory); }
  _createHistory(w) {
    this._frame(w, 'btn_warhistory');
    const list = w.control('pan_memList'), H = this.history;
    w.control('pan_memberPop')?.setVisible?.(false);
    H.rows = Array.from({ length: HISTORY_ROWS }, (_, i) => w.clone('btn_record', `_${i}`, { x: 0, y: 25 + i * ROW_HEIGHT, parent: list, visible: false }));
    H.rows.forEach((row, i) => { row.setEnabled?.(true); row.onClick?.(() => { void this._historyRow(i); }); });
    const cols = [['btn_col_start_time', 'start'], ['btn_col_name', 'name'], ['btn_col_state', 'status'], ['btn_col_end_time', 'end']];
    for (const [id, key] of cols) for (const sfx of ['', '_asc', '_desc']) w.control(id + sfx).onClick(() => { H.sort = { key, dir: H.sort.key === key ? -H.sort.dir : 1 }; this._renderHistory(w); });
    // ui_guildwarhistorywnd has no scrollbar: the mouse wheel over the list pages the records
    list?.el?.addEventListener?.('wheel', e => { e.preventDefault(); const max = Math.max(0, (H.list?.length || 0) - HISTORY_ROWS); H.top = Math.max(0, Math.min(max, H.top + Math.sign(e.deltaY) * 3)); this._renderHistory(w); }, { passive: false });
  }
  _openHistory(w) { this.history.top = 0; this._renderHistory(w); }
  _opponent(r) { const mine = this.gs?.id; return r.from === mine ? r.toName : r.fromName; }
  isWarFoe(a) { return !!a && a.kind === 'player' && a !== this.game.player && (this.ex?.warFoes || []).includes(a.networkId); }
  /** Status word plus the war's PvP kill score (own:opponent, or from:to on the public board). */
  warState(r, mine = this.gs?.id) {
    const k = r?.kills || {}, word = this.statusWord(r.status);
    if (!Object.keys(k).length && r.status !== 'active') return word;
    const a = mine === r.to ? r.to : r.from, b = a === r.from ? r.to : r.from;
    return `${word} ${k[a] || 0}:${k[b] || 0}`;
  }
  _renderHistory(w) {
    const H = this.history; this._tabState(w, 'btn_warhistory');
    const key = { start: r => r.startAt ?? r.declaredAt, name: r => this._opponent(r), status: r => WAR_STATUS[r.status], end: r => r.endAt ?? Infinity }[H.sort.key];
    H.list = [...(this.ex?.mine || [])].sort((a, b) => cmp(key(a), key(b)) * H.sort.dir);
    H.top = Math.min(H.top, Math.max(0, H.list.length - HISTORY_ROWS));
    const cols = { start: 'btn_col_start_time', name: 'btn_col_name', status: 'btn_col_state', end: 'btn_col_end_time' };
    for (const [k, id] of Object.entries(cols)) { const on = H.sort.key === k; w.control(id).setVisible(!on); w.control(`${id}_asc`).setVisible(on && H.sort.dir > 0); w.control(`${id}_desc`).setVisible(on && H.sort.dir < 0); }
    H.rows.forEach((row, i) => {
      const r = H.list[H.top + i]; row.setVisible(!!r); if (!r) return;
      w.control(`lbl_start_time_${i}`).setText(dateText(r.startAt ?? r.declaredAt));
      w.control(`lbl_state_${i}`).setText(this.say(STR.historyLine, this._opponent(r), this.warState(r)));
      w.control(`lbl_end_time_${i}`).setText(dateText(r.endAt));
    });
  }
  async _historyRow(i) {
    const r = this.history.list[this.history.top + i]; if (!r || !this.ex?.isMaster) return null;
    if (r.status === 'pending' && r.to === this.gs?.id) return this.game.uiwin.open(NAMES.accept, r);
    if (r.status === 'active') return this.surrender(r);
    return null;
  }
  async surrender(r) { if (!await this.ask(this.say(STR.surrenderAsk, this._opponent(r)))) return null; return this.send('warSurrender', { id: r.id }); }

  // ------------------------------------------------------------------ declaration / acceptance
  _canDeclareOn(t) {
    return !!t && t.kind === 'player' && t !== this.game.player && !!this.game.network?.active && !!this.gs?.founded && !!this.ex?.isMaster
      && !!t.nameplate?.guild?.name && t.nameplate.guild.id !== this.gs.id;
  }
  async declareByName(name) {
    const key = String(name || '').trim().toLowerCase();
    const t = key && [...(this.game.network?.players?.values?.() || [])].find(a => String(a?.name || a?.save?.name || a?.nameplate?.name || '').toLowerCase() === key);
    if (!t) { this.note('Choose a character on your map: /gwar Name', 'err'); return null; }
    return this.declare(t);
  }
  declare(t) {
    if (!this._need()) return false;
    if (!this.ex?.isMaster) { this.note(this.say(STR.declarePermission) || TEXT.declarePermission, 'err'); return false; }
    if (!t?.nameplate?.guild?.name) { this.note(this.say(STR.noGuildPlayer) || TEXT.noGuildPlayer, 'err'); return false; }
    return this.game.uiwin.open(NAMES.declare, t);
  }
  _createDeclare(w) {
    const pan = w.control('pan_selectday'), list = w.control('list_selectday');
    list.setItems?.(WAR_DAYS.map((d, i) => ({ text: plain(this.t([135, WAR_DAY_CODES[i]], String(d))), value: d })));
    list.on?.('select', i => { if (WAR_DAYS[i]) { w.data.days = WAR_DAYS[i]; pan.setVisible(false); this._paintDeclare(w); } });
    w.control('btn_showlist').onClick(() => pan.setVisible(!pan.isVisible?.()));
    w.control('lbl_showlist').onClick?.(() => pan.setVisible(!pan.isVisible?.()));
    w.control('btn_no').onClick(() => w.close());
    w.control('btn_yes').onClick(async () => {
      const t = w.data?.target; if (!t) { w.close(); return; }
      const r = await this.send('warDeclare', { targetId: t.networkId ?? t.id, days: w.data.days });
      if (r) w.close();
    });
  }
  _openDeclare(w, t) {
    w.data = { target: t, days: WAR_DAYS[0] };
    w.control('pan_selectday').setVisible(false);
    w.control('lbl_title').setText(plain(this.t(STR.warDeclare, 'Declare War')));
    w.control('lbl_text').setText(this.say(STR.declareAsk, t?.nameplate?.guild?.name || ''));
    this._paintDeclare(w);
  }
  _paintDeclare(w) {
    const d = w.data.days, C = this.ex?.war?.costPerDay || GUILD_WAR_CHOSEN.COST_PER_DAY;
    w.control('lbl_showlist').setText(String(d));
    w.control('lbl_warning').setText(this.say(STR.declareInfo, d, numText(C.dil * d), C.guildPoints * d));
  }
  _createAccept(w) {
    const answer = async op => { const r = w.data?.war; w.close(); if (r) await this.send(op, { id: r.id }); };
    w.control('btn_yes').onClick(() => answer('warAccept'));
    w.control('btn_no').onClick(() => answer('warDecline'));
    w.control('btn_cancel').onClick(() => w.close());   // answer later (War Status row / Guild sign board)
  }
  _openAccept(w, r) {
    w.data = { war: r };
    w.control('lbl_title').setText(plain(this.t(STR.warAccept, 'Accept War')));
    w.control('lbl_text').setText(this.say(STR.acceptAsk, r?.fromName || ''));
    w.control('lbl_warning').setText(this.say(STR.acceptInfo, r?.days || 0));
  }

  // ------------------------------------------------------------------ Guild sign: war board (NPC role DECLARE_WAR)
  _createBoard(w) {
    const B = this.board;
    const ROW = ['btn_confirm', 'lbl_server_name1', 'lbl_server_name2', 'lbl_guild_name1', 'lbl_guild_name2', 'pan_guild_markbg1', 'pan_guild_markbg2',
      'pan_guild_mark1', 'pan_guild_mark2', 'lbl_versus', 'lbl_start_date', 'lbl_end_date', 'lbl_war_state', 'btn_state_confirm'];
    // labels / marks nested in the row button (btn_confirm) ride along in the button's clone (cloneAs copies children with the suffix)
    const rowsOf = (name, n) => Array.from({ length: n }, (_, i) => {
      const btn = w.find(name('btn_confirm'));
      return Object.fromEntries(ROW.map(id => {
        const t = w.find(name(id)); if (!t) return [id, null];
        if (btn && id !== 'btn_confirm' && t.parent === btn) return [id, w.find(`${name(id)}_${i}`)];
        const c = w.clone(name(id), `_${i}`, { x: t.spec.rect[0], y: t.spec.rect[1] + (i + 1) * BOARD_ROW_HEIGHT, visible: false });
        c.setEnabled?.(true); return [id, c];
      }));
    });
    B.rows = rowsOf(id => id, BOARD_ROWS);
    // the lower table's ids carry "my_guild_" after the "lbl_" / "pan_" / "btn_" part
    B.mine = rowsOf(id => id.replace(/^(lbl|pan|btn)_/, '$1_my_guild_'), MY_BOARD_ROWS);
    B.mine.forEach((row, i) => row.btn_state_confirm?.onClick?.(() => { void this._boardAction(i); }));
    w.control('btn_prev_page').onClick(() => { B.page = Math.max(0, B.page - 1); this._renderBoard(w); });
    w.control('btn_next_page').onClick(() => { B.page += 1; this._renderBoard(w); });
    w.control('btn_exit').onClick(() => w.close());
    w.control('btn_cancel_register')?.setVisible?.(false);
  }
  _openBoard(w) { this.board.page = 0; this._renderBoard(w); }
  _paintRow(row, r) {
    for (const c of Object.values(row)) c?.setVisible?.(!!r);
    if (!r) return;
    row.btn_confirm?.setChecked?.(false);   // the row button carries the guild names / marks / VS (its children)
    row.lbl_guild_name1?.setText?.(r.fromName); row.lbl_guild_name2?.setText?.(r.toName); row.lbl_versus?.setText?.('VS');
    row.lbl_server_name1?.setText?.(''); row.lbl_server_name2?.setText?.('');
    for (const [n, mark] of [[1, r.fromMark], [2, r.toMark]]) {
      row[`pan_guild_markbg${n}`]?.setVisible?.(!!mark); row[`pan_guild_mark${n}`]?.setVisible?.(!!mark);
      if (mark) { row[`pan_guild_markbg${n}`]?.setImage?.('none', 'guildbg_s', mark.bg); row[`pan_guild_mark${n}`]?.setImage?.('none', 'guildicon_s', mark.icon); }
    }
    row.lbl_start_date?.setText?.(dateText(r.startAt ?? r.declaredAt)); row.lbl_end_date?.setText?.(dateText(r.endAt));
    row.lbl_war_state?.setText?.(this.warState(r, null)); row.btn_state_confirm?.setVisible?.(false);
  }
  _renderBoard(w) {
    const B = this.board, all = this.ex?.board || [], pages = Math.max(1, Math.ceil(all.length / BOARD_ROWS));
    B.page = Math.min(B.page, pages - 1);
    B.rows.forEach((row, i) => this._paintRow(row, all[B.page * BOARD_ROWS + i]));
    w.control('lbl_page').setText(`${B.page + 1} / ${pages}`);
    w.control('btn_prev_page').setVisible(B.page > 0); w.control('btn_next_page').setVisible(B.page < pages - 1);
    B.list = (this.ex?.mine || []).filter(r => ['pending', 'active'].includes(r.status)).slice(0, MY_BOARD_ROWS);
    B.mine.forEach((row, i) => {
      const r = B.list[i]; this._paintRow(row, r); if (!r) return;
      const label = !this.ex?.isMaster ? null : r.status === 'pending' && r.to === this.gs?.id ? STR.warAccept : r.status === 'active' ? STR.surrender : null;
      row.lbl_war_state?.setVisible?.(!label);
      if (label) { row.btn_state_confirm?.setText?.(plain(this.t(label, ''))); row.btn_state_confirm?.setVisible?.(true); }
    });
  }
  async _boardAction(i) {
    const r = this.board.list?.[i]; if (!r) return null;
    if (r.status === 'pending' && r.to === this.gs?.id) return this.game.uiwin.open(NAMES.accept, r);
    if (r.status === 'active') return this.surrender(r);
    return null;
  }
  dispose() { for (const w of Object.values(this.wins)) { try { w?.close?.(); } catch { /* ignore */ } } }
}
