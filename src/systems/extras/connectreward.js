// Reward Event: the original window game2/connectreward/ui_new_connectrewardwnd.txt, the HUD gift box
// ui_connectreward_alarm.txt (btn_alarm, tooltip 5000:0 "Reward Event") and the tracker ui_connectreward_assist.txt.
// Rules, data sources and assumptions: connectreward-rules.js. Online the host owns the progress (connected seconds,
// hunted monsters) and the claim (server/world/support-rewards.mjs); the window shows game.save.life.connectReward and sends
// {type:'connectreward', event}. Offline (sandbox) the same rules run on the local save.
import * as CR from './connectreward-rules.js';
import { placeAlarmButton } from './alarm-slots.js';
import { loadBoxes } from '../quests/data.js';
import { itemIcon, itemTooltip, setMarkup, strNow, str, msg, countItem, canGive, giveItem } from '../life/common.js';
import {RewardPanelAssets} from './reward-panel-assets.js';

export const WIN = 'connectreward', ALARM = 'connectreward_alarm', ASSIST = 'connectreward_assist';
const LS_SHOW = 'dekaron:connectreward:show';
const ASSIST_TOP = 20;      // under the assist title strip (titlerect 0 0 120 20)
const ASSIST_ROW = 26;      // pan_gauge_base 5 5 108 21 -> one row per 26 px
export class ConnectReward {
  constructor(game) { this.game = game; this.events = []; this.win = null; this.assist = null; this.lines = []; this.rows = []; this._t = 0; this._local = 0; this.shown = this._loadShown();
    this.rewardAssets=new RewardPanelAssets((id,w,h)=>itemIcon(game,id,w,h),{generation:()=>game.items?.icons?.cache?.generation||0,tooltip:(id,count)=>()=>itemTooltip(game,id,count)});
  }

  get online() { return this.game.save?.authority === 'server' || !!this.game.network?.active; }
  /** Host time when connected (snapshot serverTime), else the local clock. */
  now() { const c = this.game.network?._serverClock; return c ? c.time + (performance.now() - c.at) : Date.now(); }
  state() { return CR.normalizeState(this.game.save?.life?.connectReward, this.now()); }
  S(code) { return strNow(this.game, CR.CONNECT_REWARD_CATE, code); }

  async install() {
    const g = this.game, ui = g.uiwin;
    if (!ui) return;
    try { this.events = CR.connectRewardEvents((await loadBoxes())?.connectReward); } catch (err) { console.error('[connectreward] boxes.json', err); this.events = []; }
    if (!this.events.length) return;
    await str(g, CR.CONNECT_REWARD_CATE, 0);   // load cate 5000 once (strNow afterwards)
    await str(g, CR.REWARD_MESSAGE_CATE, 20);
    ui.registerWindow(WIN, { script: CR.CONNECT_REWARD_SCRIPT, create: w => this._create(w), onOpen: () => this.refresh() });
    ui.registerWindow(ALARM, { script: CR.CONNECT_REWARD_ALARM_SCRIPT, hud: true, band: 'hud', escClose: false, remember: false, create: w => this._createAlarm(w), onOpen: () => this.refresh() });
    ui.registerWindow(ASSIST, { script: CR.CONNECT_REWARD_ASSIST_SCRIPT, hud: true, band: 'hud', escClose: false, pos: { x: 10, y: 180 },
      create: w => this._createAssist(w), onOpen: () => this._renderAssist(), onClose: () => { if (!this._closingAssist) { this.shown.clear(); this._saveShown(); this.refresh(); } } });
    g.events?.on?.('map', () => this.syncAlarm());
    g.events?.on?.('server:profile', () => this.refresh());
    g.events?.on?.('inventory', () => this.refresh());
    if (!this.online) g.events?.on?.('death', ({ actor, killer }) => this._localKill(actor, killer));
    g.connectReward = this;
    this.syncAlarm();
  }

  // ------------------------------------------------------------------ HUD gift box
  _createAlarm(w) {
    const b = w.control('btn_alarm');
    // the script ships the gift box enable false / visible false: the client shows it while the event runs (always: the
    // data has no period). btn_alarm_pcroom (Internet Cafe Playtime Reward 5000:19/20) and btn_jumpguide (28:5 "To the
    // Jumping Character Guide.") belong to other services and stay hidden.
    b.setVisible(true); b.setEnabled(true);
    w.control('btn_alarm_pcroom').setVisible(false);
    w.control('btn_jumpguide').setVisible(false);
    b.onClick(() => { void this.game.uiwin.toggle(WIN); });
  }
  async syncAlarm() {
    const ui = this.game.uiwin;
    if (!ui || !this.events.length || !this.game.player) return;
    if (!ui.isOpen(ALARM) && !this._opening) { this._opening = true; try { await ui.open(ALARM); } finally { this._opening = false; } }
    this.placeAlarm();
  }
  placeAlarm() {
    const ui = this.game.uiwin, w = ui?.window(ALARM);
    if (w?.isOpen) placeAlarmButton(ui, w, w.control('btn_alarm'), ['attendance_alarm']);
  }

  // ------------------------------------------------------------------ main window
  async _create(w) {
    this.win = w;
    // 5000:12 carries <center><color=FF0000> markup: render it like the client instead of printing the tags
    setMarkup(w.control('lbl_warning'), this.S(12));
    const tpl = w.control('pan_line');
    this.lines = this.events.map((e, i) => {
      const line = tpl.cloneAs(`_${i}`, { y: tpl.spec.rect[1] + i * tpl.spec.rect[3], visible: true });
      const c = id => line.control(`${id}_${i}`);
      c('btn_complete').onClick(() => { void this.claim(e.index); });
      c('check_show').onClick(() => { if (c('check_show').isChecked()) this.shown.add(e.index); else this.shown.delete(e.index); this._saveShown(); void this._syncAssist(); });
      return { event: e, line, c };
    });
    w.place();
    // Hidden panel creation is awaited by prepareEntryPanels. Bake every native
    // stage (including required key items), not only the current claimed stage.
    const requests=this.lines.flatMap(({event,c})=>event.steps.flatMap(step=>[
      {index:step.item,control:c('item_reward')},
      ...(event.type===CR.TYPE_KEYITEM?[{index:step.value1,control:c('item_require')}]:[]),
    ]));
    await this.rewardAssets.prepare(requests);
    const st=this.state(),count=i=>countItem(this.game,i);
    for(const line of this.lines)this._paintLine(line,CR.lineView(CR.eventLine(line.event,st,count),code=>this.S(code)));
  }
  refresh() {
    const st = this.state(), count = i => countItem(this.game, i);
    const ready = this.events.some(e => CR.eventLine(e, st, count).ready);
    if (this.win?.isOpen) for (const L of this.lines) this._paintLine(L, CR.lineView(CR.eventLine(L.event, st, count), code => this.S(code)));
    const alarm = this.game.uiwin?.window(ALARM)?.control('btn_alarm');
    if (alarm && alarm._crReady !== ready) { alarm._crReady = ready; alarm.setBlink(ready); }
    if (this.assist?.isOpen) this._renderAssist(st);
  }
  _paintLine({ line, c, event }, v) {
    line.setImage('none', 'ConnectRewardwnd', v.image);
    setMarkup(c('lbl_line_title'), v.title);
    setMarkup(c('lbl_line_memo'), v.memo);
    this.rewardAssets.paint(c('item_reward'), v.rewardItem);
    c('lbl_rewarditem_count').setText(v.rewardCount > 1 ? String(v.rewardCount) : '');
    const key = v.keyItem;
    for (const id of ['pan_gauge', 'lbl_line_subtitle', 'lbl_line_submemo']) c(id).setVisible(!key);
    for (const id of ['item_require', 'lbl_requireitem_count', 'pan_gauge_item', 'lbl_line_subtitle_item', 'lbl_line_submemo_item']) c(id).setVisible(key);
    c(key ? 'pan_gauge_item' : 'pan_gauge').setGauge(v.gauge);
    setMarkup(c(key ? 'lbl_line_subtitle_item' : 'lbl_line_subtitle'), v.subtitle);
    setMarkup(c(key ? 'lbl_line_submemo_item' : 'lbl_line_submemo'), v.submemo);
    if (key) { this.rewardAssets.paint(c('item_require'), v.requireItem); c('lbl_requireitem_count').setText(String(v.requireCount)); }
    c('btn_complete').setEnabled(v.button);
    c('pan_clear').setVisible(v.clear);
    c('check_show').setChecked(this.shown.has(event.index));
  }

  async claim(eventIndex) {
    const g = this.game;
    if (this.online) {
      const r = await g.network?.action?.('connectreward', { event: eventIndex });
      if (r?.supportRewardResult) msg(g, this._message('received'), 'item');
    } else {
      const st = this.state();
      const check = CR.checkClaim(this.events, st, eventIndex, { countItem: i => countItem(g, i), hasItem: i => !!g.items?.def?.(i) || !!g.items?.db?.def?.(i) });
      if (!check.ok) msg(g, this._message(check.error), 'err');
      else if (!canGive(g, check.step.item, check.step.stack) || !giveItem(g, check.step.item, check.step.stack, { source: 'connectreward' })) msg(g, this._message('bagFull'), 'err');
      else { CR.markClaimed(st, check.event); this._save(st); msg(g, this._message('received'), 'item'); }
    }
    this.refresh();
  }
  _message(key) { const m = CR.REWARD_MESSAGES[key] || CR.REWARD_MESSAGES.unknown; return strNow(this.game, CR.REWARD_MESSAGE_CATE, m.code) || m.text; }
  _save(st) { const s = this.game.save; if (!s) return; s.life ||= {}; s.life.connectReward = st; }

  // ------------------------------------------------------------------ assist tracker (check_show)
  _createAssist(w) {
    this.assist = w;
    w.root.setClip?.(false);
    this.assistTpl = w.control('pan_object');   // btn_close is auto-wired; closing the tracker clears the ticks (onClose)
  }
  async _syncAssist() {
    const ui = this.game.uiwin;
    if (this.shown.size && !ui.isOpen(ASSIST)) await ui.open(ASSIST);
    else if (!this.shown.size && ui.isOpen(ASSIST)) { this._closingAssist = true; ui.close(ASSIST); this._closingAssist = false; }
    else this._renderAssist();
  }
  _renderAssist(st = this.state()) {
    const w = this.assist;
    if (!w || !this.assistTpl) return;
    for (const r of this.rows) r.remove?.();
    this.rows = [];
    const count = i => countItem(this.game, i);
    this.events.filter(e => this.shown.has(e.index)).forEach((e, k) => {
      const v = CR.lineView(CR.eventLine(e, st, count), code => this.S(code));
      const row = this.assistTpl.cloneAs(`_${k}`, { y: ASSIST_TOP + k * ASSIST_ROW, visible: true });
      row.control(`pan_gauge_${k}`)?.setGauge(v.gauge);
      setMarkup(row.control(`lbl_gauge_${k}`), v.clear ? '' : v.submemo);
      this.rows.push(row);
    });
  }
  _loadShown() { try { return new Set(JSON.parse(localStorage.getItem(LS_SHOW) || '[]').filter(Number.isInteger)); } catch { return new Set(); } }
  _saveShown() { try { localStorage.setItem(LS_SHOW, JSON.stringify([...this.shown])); } catch { /* private mode */ } }

  // ------------------------------------------------------------------ offline (sandbox) progress
  _localKill(actor, killer) {
    if (this.online || actor?.kind !== 'monster' || (killer && killer !== this.game.player)) return;
    const st = this.state();
    if (CR.countKill(st, this.events, Number(this.game.save?.level), Number(actor.def?.level))) { this._save(st); this.refresh(); }
  }
  update(dt) {
    if (!this.events.length) return;
    if (!this.online && this.game.player && Number.isFinite(dt) && dt > 0) {
      this._local += dt;
      if (this._local >= 5) { const s = Math.floor(this._local); this._local -= s; const st = this.state(); if (CR.addOnline(st, this.events, s) || st.day !== this.game.save?.life?.connectReward?.day) this._save(st); }
    }
    this._t += dt;
    if (this._t < 1) return;
    this._t = 0;
    const ui = this.game.uiwin;
    if (this.game.player && ui && !ui.isOpen(ALARM)) void this.syncAlarm();
    this.placeAlarm();
    if (this.win?.isOpen || this.assist?.isOpen || ui?.isOpen(ALARM)) this.refresh();
  }
  dispose() { this.rewardAssets.dispose(); this.win = null; this.assist = null; }
}
