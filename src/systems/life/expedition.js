// Expedition (troop) presentation: the original management window `game2/troop/ui_troopfooting.txt` (hotkey O / the
// Expedition menu button), the name-input window `game2/troop/ui_troopnameinputwnd.txt`, and the invitation prompt.
// Texts: stringtable_troop.txt (cate 555). The server owns every rule (server/world/expedition.mjs); this module only
// sends intents and paints the authoritative snapshot (network.expedition). Offline there is nobody to form an
// expedition with, so the window shows the empty "Create" state and Create explains that it needs a server.
//
// Window mapping (ui_troopfooting.txt): three corps of seven rows at y = label + 20 + 24 k (labels at 55 / 245 / 439),
// row template `pan_troop_corp` (class icon, name, HP bar, expel `btn_forceleave`, shift `btn_posmove`), role panels
// none / trooper / leader, item-distribution combo, popup of three corps for Shift. "Form" toggles the Shift buttons;
// "Move All" compacts every member into corps in order. The original left panel (pan_left_bg) is a staging list this
// engine does not need: it stays hidden. ASSUMPTION: on the leader's own row the red cross disbands the expedition.
import { str, strNow, msg } from './common.js';
import { TroopState } from './troopstate.js';
import { globalAsk } from '../../ui/uiwin/global-asks.js';

const CORPS = 3, CORP_ROWS = 7, ROW_PITCH = 24, LABEL_Y = [55, 245, 439], ROW_X = 235;
const T = {
  0: 'EXPD', 5: 'Modify', 8: 'Leader', 16: 'Create', 20: 'Quit', 23: 'is inviting you to join an expedition.', 24: 'Accept', 25: 'Reject',
  17: 'Expd Form', 28: 'Are you sure you want to withdraw from the\nexpedition?', 29: 'Please, choose an expedition member\nfor the commission of authority.',
  30: 'Do you want to disband the expedition?', 31: 'Please, decide on an expedition name.', 26: 'Expedition Name Change',
  65: 'You are not allowed to form a party since you\nhave already joined an expedition.', 67: 'You are not allowed to form an expedition since\nyou have already joined a party.',
  90: 'Basic Distribution', 91: 'Orderly Distribution', 92: 'Free Distribution', 93: 'Random Distribution', 112: 'Only an expedition leader has the authority.',
};
const text = (game, code) => (strNow(game, 555, code) || T[code] || '').replace(/<[^>]+>/g, '');

export class Expedition {
  constructor(game, life) { this.game = game; this.life = life; this.state = null; this.selected = null; this.footing = false; this.rows = []; }

  get server() { return this.game.save?.authority === 'server' && !!this.game.network; }
  get st() { return this.server ? (this.game.network.expedition || this.state) || { active: false, corps: [[], [], []], itemway: 0 } : { active: false, corps: [[], [], []], itemway: 0 }; }
  get active() { return !!this.st.active; }
  get myId() { return this.game.network?.self?.id; }
  get isLeader() { return this.active && this.st.leaderId === this.myId; }

  async install() {
    const g = this.game;
    await Promise.all([0, 5, 8, 16, 17, 20, 23, 24, 25, 26, 28, 29, 30, 31, 90, 91, 92, 93].map(code => str(g, 555, code).catch(() => {})));
    g.uiwin.registerWindow('expedition', { script: 'game2/troop/ui_troopfooting.txt', menuButton: 'btn_expedition', create: w => this._create(w), onOpen: w => this._refresh(w), update: w => this._tick(w) });
    g.expedition = this;
    this.troopState = new TroopState(g, this);
    this.troopState.install();
    // The life system installs before the network system creates game.network (and before hud-options creates game.chat),
    // so the server hooks key on the character's authority, not on this.server (which needs game.network).
    if (g.save?.authority === 'server') {
      g.events?.on?.('server:expedition', s => this.apply(s));
      if (g.network?.expedition) this.apply(g.network.expedition);
      const command = () => {
        if (this._chatCommand || !g.chat?.registerCommand) return;
        this._chatCommand = true;
        g.chat.registerCommand('/expd', args => { void this.chatCommand(args); return true; }, 'Expedition: /expd create <name> | invite <name> | leave | disband');
      };
      command();
      g.events?.on?.('systems', command);
    }
  }

  async command(operation, values = {}) {
    if (!this.server) { msg(this.game, 'Expeditions need a server world.', 'err'); return false; }
    const result = await this.game.network.action('expedition', { operation, ...values });
    return !!result;
  }
  async chatCommand(args) {
    const [op, ...rest] = String(args || '').trim().split(/\s+/), arg = rest.join(' ').trim();
    if (op === 'create') return this.create(arg);
    if (op === 'invite') return this.inviteName(arg);
    if (op === 'leave') return this.leave(false);
    if (op === 'disband') return this.disband(false);
    msg(this.game, '/expd create <name> | invite <name> | leave | disband', 'err'); return false;
  }
  async inviteName(name) {
    const lower = String(name || '').trim().toLowerCase(), candidates = (this.game.network?.party?.connected || []).filter(p => p.name.toLowerCase() === lower && p.id !== this.myId);
    if (candidates.length !== 1) { msg(this.game, candidates.length ? 'More than one connected character has that name.' : 'That character is not connected.', 'err'); return false; }
    return this.command('invite', { targetId: candidates[0].id });
  }
  async create(name) {
    if (this.game.network?.party?.active) { msg(this.game, text(this.game, 67), 'err'); return false; }
    const value = name || await this._askName(text(this.game, 31), '', 17);   // 555:17 "Expd Form" (Global msgbox/ui_troopunion)
    if (!value) return false;
    return this.command('create', { name: value });
  }
  async leave(confirm = true) {
    if (confirm && !await globalAsk(this.game, 'troopLeave')) return false;
    return this.command('leave');
  }
  async disband(confirm = true) {
    if (confirm && !await globalAsk(this.game, 'troopDisband')) return false;
    return this.command('disband');
  }

  /** The original name-input window; resolves the entered name or null. Title: 555:17 "Expd Form" when forming,
   *  555:26 "Expedition Name Change" when renaming (the titles of Global's msgbox/ui_troopunion and msgbox/ui_trooptitle). */
  async _askName(prompt, initial, titleCode = 26) {
    const g = this.game;
    const w = await g.uiwin.create('game2/troop/ui_troopnameinputwnd.txt', { name: 'expeditionname', modal: true, escClose: true, remember: false, disposeOnClose: true });
    return new Promise(resolve => {
      let done = false;
      const finish = value => { if (done) return; done = true; if (w.isOpen) w.close(); resolve(value); };
      w.control('lbl_title')?.setText(text(g, titleCode));
      w.control('lbl_text')?.setText(prompt);
      w.control('edit_text')?.setValue(initial || '');
      w.control('btn_confirm').onClick(() => { const v = String(w.control('edit_text').getValue?.() || '').trim(); if (v) finish(v.slice(0, 24)); });
      w.control('btn_cancel').onClick(() => finish(null));
      w.once?.('close', () => finish(null));
      w.open();
      setTimeout(() => w.control('edit_text')?.focus?.(), 30);
    });
  }

  apply(s) {
    this.state = s;
    if (this.win?.isOpen) this._refresh(this.win);
    this.troopState?.sync();
    const invitation = s?.invite;
    if (invitation && this._shownInvite !== invitation.id) {
      this._shownInvite = invitation.id;
      Promise.resolve(globalAsk(this.game, 'troopInvite', invitation.from)).then(yes => {
        if (this.st.invite?.id === invitation.id) void this.command(yes ? 'accept' : 'decline');
      });
    } else if (!invitation) this._shownInvite = null;
    if (!s?.active && this.selected) this.selected = null;
  }

  _create(w) {
    this.win = w;
    const g = this.game, c = id => w.control(id);
    c('pan_left_bg').hide();
    c('lbl_wndname').setText(text(g, 0));
    c('btn_exit').onClick(() => w.close());
    c('btn_troopunion').onClick(() => void this.create(''));
    c('btn_leave').onClick(() => void this.leave());
    c('btn_changeleader').onClick(() => {
      if (!this.isLeader) { msg(g, text(g, 112), 'err'); return; }
      if (!this.selected || this.selected === this.myId) { msg(g, text(g, 29), 'err'); return; }
      void this.command('lead', { targetId: this.selected });
    });
    c('btn_footing').onClick(() => { this.footing = !this.footing; this._refresh(w, true); });
    c('btn_allmove').onClick(() => void this.command('allmove'));
    c('btn_editname').onClick(async () => { const v = await this._askName(text(g, 31), this.st.name); if (v) void this.command('rename', { name: v }); });
    const combo = c('combo_troopitemway');
    combo.onChange?.(i => { if (this.isLeader && i !== this.st.itemway) void this.command('itemway', { itemway: i }); });
    // Shift popup: three corp buttons + cancel
    const pop = c('pan_popup');
    pop.hide();
    for (let corp = 0; corp < CORPS; corp++) c(`btn_popup_group${corp + 1}`).onClick(() => { pop.hide(); if (this.selected) void this.command('shift', { targetId: this.selected, corp }); });
    c('btn_popup_cancel').onClick(() => pop.hide());
    // 3 x 7 member rows cloned from the row template
    const tpl = c('pan_troop_corp');
    this.rows = [];
    for (let corp = 0; corp < CORPS; corp++) for (let k = 0; k < CORP_ROWS; k++) {
      const idx = corp * CORP_ROWS + k, y = LABEL_Y[corp] + 20 + ROW_PITCH * k;
      const row = tpl.cloneAs(`_${idx}`, { x: ROW_X, y });
      row.setEnabled(true);
      for (const id of ['pan_classtype', 'pan_pcname', 'pan_hp_background', 'progress_hp', 'btn_forceleave', 'btn_posmove']) c(`${id}_${idx}`)?.show?.();
      row.onClick(() => { const m = this._member(idx); if (m) { this.selected = m.id; this._refresh(w, true); } });
      c(`btn_forceleave_${idx}`).onClick(e => {
        e?.stopPropagation?.(); const m = this._member(idx); if (!m) return;
        if (m.id === this.myId) void this.disband(); else if (this.isLeader) void this.command('kick', { targetId: m.id });
      });
      c(`btn_posmove_${idx}`).onClick(e => {
        e?.stopPropagation?.(); const m = this._member(idx); if (!m) return; this.selected = m.id;
        const [x, y2] = row.rect(); pop.setRect(x - 70, y2 + 20); pop.show();
      });
      this.rows.push({ idx, corp, k, row });
    }
    tpl.hide();
  }

  _member(idx) { const corp = Math.floor(idx / CORP_ROWS), k = idx % CORP_ROWS; return this.st.corps?.[corp]?.[k] || null; }

  _refresh(w, force = false) {
    const g = this.game, st = this.st, c = id => w.control(id);
    const signature = JSON.stringify([st, this.selected, this.footing, this.myId]);
    if (!force && w.data.signature === signature) return;
    w.data.signature = signature;
    const active = !!st.active, leader = this.isLeader;
    c('pan_right_bg_none').setVisible(!active);
    c('pan_right_bg_trooper').setVisible(active && !leader);
    c('pan_right_bg_leader').setVisible(active && leader);
    c('pan_troopname').setText(active ? st.name : '');
    for (let corp = 0; corp < CORPS; corp++) c(`lbl_corp${corp + 1}`).setVisible(active);
    const combo = c('combo_troopitemway');
    combo.setVisible(active);
    combo.select?.(st.itemway || 0);
    combo.setEnabled?.(leader);
    for (const { idx, row } of this.rows) {
      const m = this._member(idx);
      row.setVisible(!!m);
      if (!m) continue;
      c(`pan_pcname_${idx}`).setText(`${m.leader ? '★ ' : ''}${m.name}  Lv ${m.level}${m.id === this.selected ? '  <' : ''}`);
      const ci = Number(m.classIndex);
      c(`pan_classtype_${idx}`).setSprite('etc_01', Number.isInteger(ci) && ci >= 0 && ci <= 14 ? 100 + ci : 34);
      c(`progress_hp_${idx}`).setGauge(m.maxHp > 0 ? Math.max(0, Math.min(1, m.hp / m.maxHp)) : 0);
      c(`btn_forceleave_${idx}`).setVisible(leader && !m.instance);
      c(`btn_posmove_${idx}`).setVisible(leader && this.footing);
    }
    if (!active || !leader) c('pan_popup').hide();
  }
  _tick(w) { if (w.isOpen) this._refresh(w); }
  dispose() { this.win = null; }
}
