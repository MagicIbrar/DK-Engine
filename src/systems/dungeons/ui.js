// The original dungeon windows (script/ui/game2/dungeon/*.txt), registered on the UI platform (docs/UIWIN.md).
//
//   dungeon_info        ui_dungeoninfownd.txt       "Instance Dungeon Info": dungeon / goal / time limit / progress list
//                                                    (pan_object_check_k ticks, pan_object_fail_k crosses)
//   dungeon_time        ui_dungeontimewnd.txt       up to 5 timer rows "<caption> MMMinSSSec" (system text 99);
//                                                    btn_lock "Lock window motion" (71 3)
//   dungeon_alarm       ui_dungeonalarmwnd.txt      the blinking dungeon button (indun#3..5): opens the info window
//   dungeon_count       ui_dungeoncountwnd.txt      "Kill Count" + counter
//   dungeon_send        ui_dungeonsend.txt          "Enter Dungeon" confirmation (system text 100 <MAPNAME>)
//   dungeon_recv        ui_dungeonrecv.txt          "Result" box for entry errors
//   dungeon_scoreboard  ui_dungeonscoreboardwnd.txt score gauge + gold number + fever mark
//   dungeon_titlecount  ui_titlecountwnd.txt        objective title + current / goal
//   dungeon_vanishtime  ui_vanishtimewnd.txt        one extra timer row
//   dungeon_timeattack  ui_timeattackinfownd.txt    "Remaining Monster" / "Time Passed" image numbers
//   dungeon_taresult    ui_timeattackresultwnd.txt  "Time Attack Result" ranking (the player's own best runs)
//   dungeon_redhole     ui_redholeinfownd.txt       "Red Hole's Energy" 4 lights (API for the field-boss system)
//   dungeon_portaltime  game2/ui_portaltimewnd.txt  siege / portal play time (API)
import { sysText, timeText } from './data.js';

const S = (f) => `game2/dungeon/${f}`;

export class DungeonUI {
  constructor(sys) {
    this.sys = sys;
    this.game = sys.game;
    this.mgr = sys.game.uiwin;
    this.info = null;           // {title, mission, time, missions:[{text, done, failed}]}
    this.timers = [];           // [{caption, sec}]
    this._locked = true;
  }

  register() {
    const mgr = this.mgr;
    if (!mgr) return;
    const self = this;
    mgr.registerWindow('dungeon_info', {
      script: S('ui_dungeoninfownd.txt'),
      create(win) {
        win.control('btn_dungeoninfo_ok').onClick(() => win.close('ok'));
        win.control('list_objectlist').on('select', () => {});
      },
      onOpen(win) { self._fillInfo(win); },
    });
    mgr.registerWindow('dungeon_time', {
      script: S('ui_dungeontimewnd.txt'), hud: true, escClose: false, remember: true,
      create(win) {
        win.control('btn_lock').onClick(() => {
          self._locked = !self._locked;
          // unlocked: the window can be dragged by its top strip (the script has no title rect)
          win.spec.titlerect = self._locked ? null : [0, 0, 164, 14];
          win.control('btn_lock').setChecked(!self._locked);
        });
      },
      onOpen(win) { self._fillTimers(win); },
    });
    mgr.registerWindow('dungeon_alarm', {
      script: S('ui_dungeonalarmwnd.txt'), hud: true, escClose: false, remember: false,
      create(win) {
        win.control('btn_alarm').onClick(() => { win.control('btn_alarm').setBlink(false); mgr.toggle('dungeon_info'); });
      },
    });
    mgr.registerWindow('dungeon_count', { script: S('ui_dungeoncountwnd.txt'), hud: true, escClose: false });
    mgr.registerWindow('dungeon_scoreboard', { script: S('ui_dungeonscoreboardwnd.txt'), hud: true, escClose: false });
    mgr.registerWindow('dungeon_titlecount', { script: S('ui_titlecountwnd.txt'), hud: true, escClose: false });
    mgr.registerWindow('dungeon_vanishtime', { script: S('ui_vanishtimewnd.txt'), hud: true, escClose: false });
    mgr.registerWindow('dungeon_timeattack', { script: S('ui_timeattackinfownd.txt'), hud: true, escClose: false });
    mgr.registerWindow('dungeon_taresult', { script: S('ui_timeattackresultwnd.txt') });
    mgr.registerWindow('dungeon_redhole', { script: S('ui_redholeinfownd.txt'), hud: true, escClose: false });
    mgr.registerWindow('dungeon_portaltime', { script: 'game2/ui_portaltimewnd.txt', hud: true, escClose: false });
  }

  // ------------------------------------------------------------------------------------------ info
  setInfo(info) {
    this.info = info;
    const w = this.mgr?.window('dungeon_info');
    if (w?.isOpen) this._fillInfo(w);
  }

  _fillInfo(win) {
    const i = this.info || {};
    win.control('lbl_dungeon_name2').setText(i.title || '');
    win.control('lbl_misson2').setRichText ? win.control('lbl_misson2').setRichText(i.mission || '') : win.control('lbl_misson2').setText(i.mission || '');
    win.control('lbl_limit_time2').setText(i.time || '');
    const ms = i.missions || [];
    win.control('list_objectlist').setItems?.(ms.map(m => ({ text: m.text, color: m.failed ? 'ff808080' : null })));
    for (let k = 0; k <= 5; k++) {
      win.control(`pan_object_check_${k}`).setVisible(!!ms[k]?.done);
      if (k >= 1) win.control(`pan_object_fail_${k}`).setVisible(!!ms[k]?.failed && !ms[k]?.done);
    }
  }

  openInfo() { return this.mgr?.open('dungeon_info'); }

  // ------------------------------------------------------------------------------------------ timers
  /** rows: [{caption (client markup), sec}] (max 5). */
  setTimers(rows) {
    this.timers = (rows || []).slice(0, 5);
    const w = this.mgr?.window('dungeon_time');
    if (!this.timers.length) { if (w?.isOpen) w.close(); return; }
    if (w?.isOpen) this._fillTimers(w); else this.mgr?.open('dungeon_time');
  }

  _fillTimers(win) {
    for (let k = 1; k <= 5; k++) {
      const r = this.timers[k - 1];
      win.control(`pan_time_${k}`).setVisible(!!r);
      if (!r) continue;
      const text = timeText(r.caption || '', r.sec);
      const tb = win.control(`textbox_time_${k}`);
      if (tb._last !== text) { tb._last = text; tb.setText(text); }
    }
  }

  alarm(on, blink = false) {
    if (!this.mgr) return;
    if (!on) { this.mgr.close('dungeon_alarm'); return; }
    this.mgr.open('dungeon_alarm').then(w => w?.control('btn_alarm').setBlink(!!blink));
  }

  // ------------------------------------------------------------------------------------------ counters
  count(value, label = null) {
    this.mgr?.open('dungeon_count').then(w => {
      if (!w) return;
      if (label != null) w.control('lbl_tagcount').setText(label);
      w.control('lbl_count').setText(String(value));
    });
  }

  titleCount(title, cur, goal) {
    this.mgr?.open('dungeon_titlecount').then(w => {
      if (!w) return;
      w.control('lbl_title').setText(title || '');
      w.control('lbl_temp_count').setText(String(cur ?? 0));
      w.control('lbl_goal_count').setText(String(goal ?? 0));
    });
  }

  scoreboard(frac, score, fever = false) {
    this.mgr?.open('dungeon_scoreboard').then(w => {
      if (!w) return;
      w.control('processbar').setGauge(Math.max(0, Math.min(1, Number(frac) || 0)));
      w.control('number_score').setNumber?.(Math.round(Number(score) || 0));
      w.control('pan_fever').setVisible(!!fever);
    });
  }

  vanish(caption, sec) {
    this.mgr?.open('dungeon_vanishtime').then(w => {
      if (!w) return;
      w.control('pan_time').show();
      w.control('textbox_time').setText(timeText(caption, sec));
    });
  }

  timeAttack(remaining, elapsedSec) {
    this.mgr?.open('dungeon_timeattack').then(w => {
      if (!w) return;
      w.control('number_count').setNumber?.(Math.max(0, remaining | 0));
      w.control('number_timer').setTime?.(Math.max(0, Math.floor(elapsedSec || 0)));
    });
  }

  /** rows: [{rank, name, level, cls, time}] best-first; mine = the same shape. */
  async timeAttackResult(mapName, rows, mine) {
    const w = await this.mgr?.open('dungeon_taresult');
    if (!w) return;
    w.control('lbl_map_name').setText(mapName || '');
    for (let k = 0; k < 10; k++) {
      const r = rows[k];
      w.control(`lbl_number_${k}`).setText(r ? String(r.rank) : '');
      w.control(`lbl_name_${k}`).setText(r?.name || '');
      w.control(`lbl_level_${k}`).setText(r ? String(r.level) : '');
      w.control(`lbl_class_${k}`).setText(r?.cls || '');
      w.control(`lbl_time_${k}`).setText(r?.time || '');
    }
    w.control('lbl_number_mine').setText(mine ? String(mine.rank) : '');
    w.control('lbl_name_mine').setText(mine?.name || '');
    w.control('lbl_level_mine').setText(mine ? String(mine.level) : '');
    w.control('lbl_class_mine').setText(mine?.cls || '');
    w.control('lbl_time_mine').setText(mine?.time || '');
  }

  redHole(lights) {
    this.mgr?.open('dungeon_redhole').then(w => { if (w) for (let k = 0; k < 4; k++) w.control(`pan_light_${k}`).setVisible(k < lights); });
  }

  portalTime(text) {
    this.mgr?.open('dungeon_portaltime').then(w => { if (w) w.control('textbox').setText(text || ''); });
  }

  // ------------------------------------------------------------------------------------------ entry boxes
  /** "Enter Dungeon" box: resolves true on Ok. */
  async confirmEnter(mapName) {
    const mgr = this.mgr;
    const win = await mgr.create(S('ui_dungeonsend.txt'), { name: 'dungeon_send', modal: true, escClose: true, remember: false, disposeOnClose: true });
    win.control('textbox').setText(sysText(100).replace(/<MAPNAME>/g, mapName || ''));
    win.control('btn_yes_dil').hide(); win.control('btn_yes_point').hide(); win.control('btn_no_point').hide();
    return new Promise((resolve) => {
      win.once('close', (r) => resolve(r === 'yes'));
      win.control('btn_yes').onClick(() => win.close('yes'));
      win.control('btn_no').onClick(() => win.close('no'));
      mgr.openWindow(win);
    });
  }

  /** "Result" box (entry refused ...). */
  async result(text, code = '') {
    const mgr = this.mgr;
    const win = await mgr.create(S('ui_dungeonrecv.txt'), { name: 'dungeon_recv', modal: true, escClose: true, remember: false, disposeOnClose: true });
    win.control('textbox').setText(text || '');
    win.control('lbl_errorcode').setText(code ? String(code) : '');
    return new Promise((resolve) => {
      win.once('close', () => resolve(true));
      win.control('btn_no').onClick(() => win.close('ok'));
      mgr.openWindow(win);
    });
  }

  /** Close every dungeon HUD piece (leaving the instance). */
  hideAll() {
    this.info = null; this.timers = [];
    for (const n of ['dungeon_info', 'dungeon_time', 'dungeon_alarm', 'dungeon_count', 'dungeon_scoreboard', 'dungeon_titlecount', 'dungeon_vanishtime', 'dungeon_timeattack']) this.mgr?.close(n);
  }

  update() {
    const w = this.mgr?.window('dungeon_time');
    if (w?.isOpen) this._fillTimers(w);
  }
}
