// The original event windows (docs/UIWIN.md), registered on the UI platform and driven by the event runs.
//   ev_message    game2/ui_eventmessagewnd.txt            centre event message: up to 5 stacked lines, oldest drops after 15 s
//                 (decompile FUN_00b341b0 / FUN_00b34220 / FUN_00b34270; EventMessageQueue in mode-ui-rules.js)
//   ev_limittime  game2/partywar/ui_limittimewnd.txt      Dead Front / Ice Castle phase timer ("Waiting to Start : 02 Min 59 Sec")
//   ev_remaintime game2/partywar/ui_remainwartimewnd.txt separate application / entry timer in the lobby
//   ev_partyinfo  game2/partywar/ui_mypartyinfownd.txt    score / rank
//   ev_result     game2/partywar/ui_resultwnd.txt         result window (rank, party, score, additional EXP)
//   ev_tower      game2/partywar/ui_towerwnd.txt          Tower of Shield gauge (vertical)
//   ev_attach     game2/partywar/ui_attachprocesswnd.txt  channel gauge (supply depot capture, slate deciphering)
//   ev_dtime      game2/dungeon/ui_dungeontimewnd.txt     dungeon timers (Colosseum Arena, Infinite Battle): 5 rows
//   ev_score      game2/dungeon/ui_dungeonscoreboardwnd.txt  combo gauge + number + fever
//   ev_count      game2/dungeon/ui_dungeoncountwnd.txt    accumulation counter (Infinite Battle)
//   ev_matching   game2/colosseum/ui_matchingwait.txt     "waiting for a match" (PvP modes; no opponent ever comes)
//   ev_fbtime     game2/fieldboss/ui_fieldbosstimewnd.txt field boss timers
//   ev_effect     game2/ui_effectuiwnd.txt                pan_effect: the effect UI banners (effectui.js)
// Timer strings use the client's own formats (%02d Min %02d Sec), so the printf fill here pads like C.
import { hudLog } from './text.js';
import { EventMessageQueue } from './mode-ui-rules.js';

/** C printf subset: %d %02d %s %u %% (zero/width), then the remaining args ignored. */
export function pf(fmt, ...args) {
  let i = 0;
  return String(fmt ?? '').replace(/%(%|[-0]?\d*(?:\.\d+)?[dsuif])/g, (m, spec) => {
    if (spec === '%') return '%';
    const v = args[i++];
    if (v == null) return m;
    const w = /^(-?)(0?)(\d*)(?:\.(\d+))?([dsuif])$/.exec(spec);
    if (!w) return String(v);
    let s = w[5] === 'f' ? Number(v).toFixed(w[4] != null ? Number(w[4]) : 6) : /[diu]/.test(w[5]) ? String(Math.trunc(Number(v))) : String(v);
    const width = Number(w[3]) || 0;
    if (s.length < width) s = w[1] ? s.padEnd(width) : (w[2] ? s.padStart(width, '0') : s.padStart(width));
    return s;
  });
}

const MS = s => [Math.floor(Math.max(0, s) / 60), Math.floor(Math.max(0, s) % 60)];

export class EventUI {
  constructor(game, sys) {
    this.game = game;
    this.sys = sys;
    this.ui = game.uiwin;
    this._msgQ = new EventMessageQueue();
    this._channel = null;
    this._result = null;
    this._timerRequests = new Map();
    this._reg();
  }

  _reg() {
    const ui = this.ui;
    if (!ui) return;
    const hud = { hud: true, escClose: false, remember: false, band: 'hud' };
    ui.registerWindow('ev_message', { script: 'game2/ui_eventmessagewnd.txt', ...hud, band: 'system' });
    ui.registerWindow('ev_limittime', { script: 'game2/partywar/ui_limittimewnd.txt', ...hud });
    ui.registerWindow('ev_remaintime', { script: 'game2/partywar/ui_remainwartimewnd.txt', ...hud });
    ui.registerWindow('ev_partyinfo', { script: 'game2/partywar/ui_mypartyinfownd.txt', ...hud });
    ui.registerWindow('ev_tower', { script: 'game2/partywar/ui_towerwnd.txt', ...hud });
    ui.registerWindow('ev_attach', { script: 'game2/partywar/ui_attachprocesswnd.txt', ...hud });
    ui.registerWindow('ev_dtime', { script: 'game2/dungeon/ui_dungeontimewnd.txt', hud: true, escClose: false, band: 'hud',
      create: (win) => this._lockable(win) });
    ui.registerWindow('ev_score', { script: 'game2/dungeon/ui_dungeonscoreboardwnd.txt', ...hud, remember: true });
    ui.registerWindow('ev_count', { script: 'game2/dungeon/ui_dungeoncountwnd.txt', ...hud, remember: true });
    ui.registerWindow('ev_fbtime', { script: 'game2/fieldboss/ui_fieldbosstimewnd.txt', hud: true, escClose: false, band: 'hud',
      create: (win) => this._lockable(win) });
    ui.registerWindow('ev_effect', { script: 'game2/ui_effectuiwnd.txt', ...hud, band: 'system' });
    ui.registerWindow('ev_result', {
      script: 'game2/partywar/ui_resultwnd.txt', escClose: true,
      create: (win) => { win.control('btn_ok').onClick(() => win.close('ok')); },
      onClose: (win, r) => { const cb = win.data.onClose; win.data.onClose = null; cb?.(r); },
    });
    ui.registerWindow('ev_matching', {
      script: 'game2/colosseum/ui_matchingwait.txt', escClose: true,
      create: (win) => { win.control('btn_cancel').onClick(() => win.close('cancel')); },
      onClose: (win, r) => { const cb = win.data.onClose; win.data.onClose = null; cb?.(r); },
    });
  }

  /** btn_lock of the timer windows: toggles whether the window can be dragged (tooltip 71|3). */
  _lockable(win) {
    const b = win.control('btn_lock');
    win.data.locked = false;
    b.onClick(() => {
      win.data.locked = !win.data.locked;
      win.opts.movable = !win.data.locked;
      b.setChecked(win.data.locked);
    });
  }

  async _open(name, arg) { try { return await this.ui?.open(name, arg); } catch (err) { console.warn(`[events] ${name}`, err); return null; } }
  _win(name) { return this.ui?.window(name) || null; }
  close(name) { this._timerRequests.delete(name); this.ui?.close(name); }
  closeAll() {
    this._result = null;
    for (const n of ['ev_remaintime', 'ev_limittime', 'ev_partyinfo', 'ev_tower', 'ev_attach', 'ev_result', 'ev_dtime', 'ev_score', 'ev_count', 'ev_fbtime', 'ev_matching']) this.close(n);
    this._channelCancel('closed');
  }

  // ---------------------------------------------------------------------------------------- centre message
  /** Add one line to the Global EventMessage stack (5 lines, shared 15 s age; see EventMessageQueue). */
  async notice(text) {
    const line = String(text ?? '');
    this._msgQ.push(line);
    const w = await this._paintNotice();
    if (!w) this._msgQ.drop(line);
  }
  /** Remove one queued line (OX quiz wall-time expiry) and repaint or hide. */
  dropNotice(text) {
    if (!this._msgQ.drop(text)) return false;
    void this._paintNotice();
    return true;
  }
  async _paintNotice() {
    if (!this._msgQ.visible) { this.close('ev_message'); return null; }
    const w = await this._open('ev_message');
    if (!w) return null;
    if (!this._msgQ.visible) { this.close('ev_message'); return null; }
    w.control('lbl_message').setRichText(this._msgQ.display);
    return w;
  }

  // ---------------------------------------------------------------------------------------- phase timer
  /** Party-war timer: fmt = partywar #300|3-9 ("<color=..>Waiting to Start :</color> %02d Min %02d Sec"). */
  timer(fmt, seconds, options) { return this._countdown('ev_limittime', fmt, seconds, options); }
  lobbyTimer(fmt, seconds, options) { return this._countdown('ev_remaintime', fmt, seconds, options); }
  async _countdown(name, fmt, seconds, { isCurrent = () => true } = {}) {
    const request = {};
    this._timerRequests.set(name, request);
    const w = this._win(name) || await this._open(name);
    if (!w) return;
    if (this._timerRequests.get(name) !== request || !isCurrent()) {
      if (!this._timerRequests.has(name) || this._timerRequests.get(name) === request) this.close(name);
      return;
    }
    if (!w.isOpen) this.ui.openWindow(w);
    const [m, s] = MS(seconds);
    w.control('lbl_text').setRichText(pf(fmt, m, s));
  }

  async partyInfo(point, rank) {
    const w = this._win('ev_partyinfo') || await this._open('ev_partyinfo');
    if (!w) return;
    if (!w.isOpen) this.ui.openWindow(w);
    w.control('lbl_point').setText(String(point));
    w.control('lbl_rank').setText(String(rank));
  }

  async tower(frac) {
    const w = this._win('ev_tower') || await this._open('ev_tower');
    if (!w) return;
    if (!w.isOpen) this.ui.openWindow(w);
    w.control('pan_HorizenGage').setGauge(Math.max(0, Math.min(1, frac)), { vertical: true });
  }

  /**
   * Result window (partywarui 2008): rows [{rank, party, point, exp}] (max 4). Resolves when closed.
   */
  async result(rows, msg = null, {isCurrent = () => true} = {}) {
    this.close('ev_result');
    const request = this._result = {};
    const w = await this._open('ev_result');
    if (!w) return null;
    if (this._result !== request || !isCurrent()) {
      if (this._result === request) this._result = null;
      if (!this._result) this.close('ev_result');
      return null;
    }
    for (let i = 1; i <= 4; i++) {
      const r = rows[i - 1];
      w.control(`lbl_Rank${i}`).setText(r ? String(r.rank ?? '') : '');
      w.control(`lbl_Party${i}`).setText(r ? String(r.party) : '');
      w.control(`lbl_Point${i}`).setText(r ? String(r.point) : '');
      w.control(`lbl_Exp${i}`).setText(r ? Number(r.exp || 0).toLocaleString('en-US') : '');
      // Keep long party names and rewards inside the original table columns.
      for (const field of ['Rank', 'Party', 'Point', 'Exp']) {
        const control = w.control(`lbl_${field}${i}`);
        if (control.el?.style) control.el.style.overflow = 'hidden';
        if (control.txt?.style) control.txt.style.overflow = 'hidden';
        const span = control.txt?.firstChild;
        if (span?.style) Object.assign(span.style, { minWidth: '0', maxWidth: '100%', overflow: 'hidden', textOverflow: 'ellipsis', whiteSpace: 'nowrap' });
        if (control.el) control.el.title = control.getText?.() || '';
      }
    }
    if (msg != null) w.control('lbl_msg').setText(msg);
    return new Promise(res => { w.data.onClose = value => { if(this._result === request)this._result = null;res(value); }; });
  }

  // ---------------------------------------------------------------------------------------- channel gauge
  /**
   * The original channel bar (attachprocesswnd): `text` over a `ms` progress bar. Moving, being hit or leaving
   * cancels it (partywar #300|124-126). Resolves true when it completes, false when cancelled; `onFail(why)` gets the
   * cancel reason ('moved' | 'hit' | ...) so the caller prints the original reason line.
   */
  channel(text, ms, {server = null, onFail = null} = {}) {
    this._channelCancel('replaced');
    const p = this.game.player;
    return new Promise(async (resolve) => {
      const ch = { t: 0, ms: Math.max(100, ms), x: p?.x, z: p?.z, hp: p?.hp, resolve, done: false, server, onFail };
      this._channel = ch;
      const w = await this._open('ev_attach');
      if (this._channel !== ch || server && !server.isCurrent()) {
        if(this._channel === ch)this._channelCancel('scope');
        else if(!this._channel)this.close('ev_attach');
        return;
      }
      w?.control('lbl_name').setText(String(text || ''));
      w?.control('processbar').setGauge(0);
      ch.win = w;
    });
  }
  endServerChannel(channelId, completed = false) {
    const ch = this._channel;
    if (!ch?.server || ch.server.channelId !== channelId) return;
    this._channel = null;ch.done = true;this.close('ev_attach');ch.resolve(!!completed);
  }
  _channelCancel(why) {
    const ch = this._channel;
    if (!ch) return;
    this._channel = null;
    ch.done = true;
    this.close('ev_attach');
    ch.resolve(false);
    if (ch.onFail) { ch.onFail(why); return; }
    if (why === 'moved' || why === 'hit') hudLog(this.game, why === 'moved' ? 'Cancelled: you moved.' : 'Cancelled: you were attacked.', 'err');
  }
  get channelling() { return !!this._channel; }

  // ---------------------------------------------------------------------------------------- dungeon windows
  /** Dungeon timer rows (max 5): lines = [text | null]. */
  async dungeonTimes(lines) {
    const w = this._win('ev_dtime') || await this._open('ev_dtime');
    if (!w) return;
    if (!w.isOpen) this.ui.openWindow(w);
    for (let i = 1; i <= 5; i++) {
      const t = lines[i - 1];
      const pan = w.control(`pan_time_${i}`);
      if (t == null || t === '') { pan.setVisible(false); continue; }
      pan.setVisible(true);
      const tb = w.control(`textbox_time_${i}`);
      if (tb._last !== t) { tb._last = t; tb.setText?.(''); tb.clear?.(); tb.addLine?.(t); }
    }
  }
  async fieldBossTimes(lines) {
    const w = this._win('ev_fbtime') || await this._open('ev_fbtime');
    if (!w) return;
    if (!w.isOpen) this.ui.openWindow(w);
    for (let i = 1; i <= 3; i++) {
      const t = lines[i - 1];
      const pan = w.control(`pan_time_${i}`);
      if (t == null || t === '') { pan.setVisible(false); continue; }
      pan.setVisible(true);
      const tb = w.control(`textbox_time_${i}`);
      if (tb._last !== t) { tb._last = t; tb.clear?.(); tb.addLine?.(t); }
    }
  }
  /** Combo scoreboard: gauge 0..1 (hold time left), number (combo), fever (multiplier active). */
  async scoreboard(gauge, number, fever) {
    const w = this._win('ev_score') || await this._open('ev_score');
    if (!w) return;
    if (!w.isOpen) this.ui.openWindow(w);
    w.control('processbar').setGauge(Math.max(0, Math.min(1, gauge)));
    w.control('number_score').setNumber(number);
    w.control('pan_fever').setVisible(!!fever);
  }
  async counter(tag, text) {
    const w = this._win('ev_count') || await this._open('ev_count');
    if (!w) return;
    if (!w.isOpen) this.ui.openWindow(w);
    if (tag != null) w.control('lbl_tagcount').setText(tag);
    w.control('lbl_count').setText(text);
  }

  /** "Waiting for a match" window (PvP modes). Resolves when the player cancels / closes it. */
  async matching(title, text) {
    const w = await this._open('ev_matching');
    if (!w) return null;
    if (title) w.control('lbl_title').setText(title);
    w.control('lbl_text').setText(text || '');
    return new Promise(res => { w.data.onClose = res; });
  }

  // ---------------------------------------------------------------------------------------- frame
  update(dt) {
    if (this._msgQ.tick(dt * 1000)) void this._paintNotice();
    const ch = this._channel;
    if (ch && ch.win) {
      if(ch.server){
        if(!ch.server.isCurrent()){this._channelCancel('scope');return;}
        ch.win.control('processbar').setGauge(Math.max(0, Math.min(1, (ch.server.now()-ch.server.startedAt)/ch.ms)));
        // Canonical end closes the display; reaching 100% grants no objective.
        return;
      }
      const p = this.game.player;
      if (!p || p.dead || Math.hypot(p.x - ch.x, p.z - ch.z) > 0.3) { this._channelCancel('moved'); return; }
      if (p.hp < ch.hp) { this._channelCancel('hit'); return; }
      ch.t += dt * 1000;
      ch.win.control('processbar').setGauge(Math.min(1, ch.t / ch.ms));
      if (ch.t >= ch.ms) {
        this._channel = null;
        this.close('ev_attach');
        ch.resolve(true);
      }
    }
  }
}
