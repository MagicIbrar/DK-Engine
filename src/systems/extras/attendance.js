// Attendance Rewards: the original window game2/attendancereward/ui_attendance_event_wnd.txt and its HUD alarm
// ui_attendance_alarm.txt (btn_alarm, tooltip 2300:21). Rules, data sources and assumptions: attendance-rules.js. Online the
// host owns the account board and the day's connection time (server/world/support-rewards.mjs, accountFeatures.attendance)
// and the claim ({type:'attendance', set, no}); offline (sandbox) the same rules run on the local account store.
import * as AT from './attendance-rules.js';
import { REWARD_MESSAGES, REWARD_MESSAGE_CATE, CONNECT_REWARD_CATE, remainingTimeText, fillValues } from './connectreward-rules.js';
import { placeAlarmButton } from './alarm-slots.js';
import { loadBoxes } from '../quests/data.js';
import { itemIcon, itemTooltip, setMarkup, strNow, str, msg, box, fmt, itemName, canGive, giveItem, account, saveAccount } from '../life/common.js';
import {RewardPanelAssets} from './reward-panel-assets.js';

export const WIN = 'attendance', ALARM = 'attendance_alarm';
const INVENTORY_WINDOWS = ['inventory'];

/**
 * Board layout (engine; the exe lays this window out in code). The script puts lbl_notice (14 0 800x76) on the title
 * strip and one 877x120 cell strip (pan_event_bg) at 75 = notice bottom - 1; the 25 cells need several rows and pan_mid
 * (901x0, the 1 px middle sprite) is the stretchable middle. The engine keeps the scripted geometry and moves the notice under
 * the title (title rect 15+25 plus its 5 px text offset = 45), keeps the strip directly under the notice, fills each strip with
 * as many 98 px cells as fit (8), spaced evenly, one strip per 120 px row, and stretches pan_mid to the rows.
 */
export function boardLayout(cellCount, { stripW = 877, stripH = 120, cellW = 98, noticeY = 45, noticeH = 76, topH = 195, bottomH = 19 } = {}) {
  const perRow = Math.max(1, Math.floor(stripW / cellW));
  const stride = perRow > 1 ? Math.floor((stripW - cellW) / (perRow - 1)) : 0;
  const rows = Math.max(1, Math.ceil(cellCount / perRow));
  const stripY = noticeY + noticeH - 1, end = stripY + rows * stripH;
  const midH = Math.max(0, end - topH);
  return { perRow, stride, rows, noticeY, stripY, stripHeight: rows * stripH, midH, bottomY: topH + midH, height: topH + midH + bottomH,
    cell: i => ({ x: (i % perRow) * stride, y: Math.floor(i / perRow) * stripH }) };
}

export class AttendanceReward {
  constructor(game) { this.game = game; this.tables = { sets: [], days: [] }; this.win = null; this.cells = []; this._t = 0; this._local = 0;
    this.rewardAssets=new RewardPanelAssets((id,w,h)=>itemIcon(game,id,w,h),{generation:()=>game.items?.icons?.cache?.generation||0,tooltip:(id,count)=>()=>itemTooltip(game,id,count)});
  }

  get online() { return this.game.save?.authority === 'server' || !!this.game.network?.active; }
  now() { const c = this.game.network?._serverClock; return c ? c.time + (performance.now() - c.at) : Date.now(); }
  rawState() { return this.online ? this.game.save?.accountFeatures?.attendance : account().attendance; }
  state() { return AT.normalizeState(this.rawState(), this.now()); }
  S(cate, code) { return strNow(this.game, cate, code); }
  activeSet() { return AT.activeSet(this.tables, this.now()); }

  async install() {
    const g = this.game, ui = g.uiwin;
    if (!ui) return;
    try { this.tables = AT.attendanceTables((await loadBoxes())?.attendance); } catch (err) { console.error('[attendance] boxes.json', err); }
    if (!this.tables.sets.length) return;
    await str(g, AT.ATTEND_CATE, 21); await str(g, AT.MISSION_CATE, 1001); await str(g, CONNECT_REWARD_CATE, 11);
    ui.registerWindow(WIN, { script: AT.ATTEND_SCRIPT, create: w => this._create(w), onOpen: () => this.refresh() });
    ui.registerWindow(ALARM, { script: AT.ATTEND_ALARM_SCRIPT, hud: true, band: 'hud', escClose: false, remember: false,
      create: w => w.control('btn_alarm').onClick(() => { void this.open(); }) });
    g.events?.on?.('map', () => this.syncAlarm());
    g.events?.on?.('server:profile', () => { if (this.win?.isOpen) this.refresh(); });
    g.attendance = this;
    this.syncAlarm();
  }

  // ------------------------------------------------------------------ HUD alarm: shown only while an event runs
  async syncAlarm() {
    const ui = this.game.uiwin;
    if (!ui || !this.game.player) return;
    const on = !!this.activeSet();
    if (on && !ui.isOpen(ALARM) && !this._opening) { this._opening = true; try { await ui.open(ALARM); } finally { this._opening = false; } }
    else if (!on && ui.isOpen(ALARM)) ui.close(ALARM);
    if (!on && ui.isOpen(WIN)) ui.close(WIN);
    const w = ui.window(ALARM);
    if (w?.isOpen) placeAlarmButton(ui, w, w.control('btn_alarm'));
  }
  /** The alarm: 2300:22 while the inventory is open, 2300:26 outside an event period, else the board. */
  async open() {
    const g = this.game, ui = g.uiwin;
    if (ui.isOpen(WIN)) { ui.close(WIN); return null; }
    if (INVENTORY_WINDOWS.some(n => ui.isOpen(n))) { msg(g, this.S(AT.ATTEND_CATE, 22) || 'Must close inventory window to access Attendance Rewards.', 'err'); return null; }
    if (!this.activeSet()) { msg(g, this._message('waitPeriod'), 'err'); return null; }
    return ui.open(WIN);
  }

  // ------------------------------------------------------------------ window
  async _create(w) {
    this.win = w;
    const count = Math.max(...this.tables.sets.map(s => s.count), 1);
    const L = this.layout = boardLayout(count);
    const notice = w.control('lbl_notice'), nr = notice.spec.rect;
    notice.setRect(nr[0], L.noticeY, nr[2], nr[3]);
    setMarkup(notice, this.S(AT.ATTEND_CATE, 25));   // 2300:25 has <color=FF3300> lines
    const strip = w.control('pan_event_bg'), sr = strip.spec.rect;
    strip.setRect(sr[0], L.stripY, sr[2], L.stripHeight);
    const mid = w.control('pan_mid'), mr = mid.spec.rect;
    mid.setVisible(L.midH > 0); mid.setRect(mr[0], mr[1], mr[2], L.midH);
    const bottom = w.control('pan_bottom'), br = bottom.spec.rect;
    bottom.setRect(br[0], L.bottomY, br[2], br[3]);
    w.control('pan_back').setRect(0, 0, 901, L.height);
    w.spec.rect = [0, 0, 901, L.height];
    const tpl = w.control('pan_event_base');
    this.cells = Array.from({ length: count }, (_, i) => {
      const at = L.cell(i), cell = tpl.cloneAs(`_${i}`, { x: at.x, y: at.y, visible: true });
      const c = id => cell.control(`${id}_${i}`);
      cell.setEnabled(true);   // the template ships enable false
      c('btn_event_click').setEnabled(true);
      c('btn_event_click').onClick(() => { void this.claim(i + 1); });
      c('btn_event_click').setTooltip(() => this._tooltip(i + 1));
      return { cell, c };
    });
    w.place();
    const requests=this.tables.sets.flatMap(set=>AT.boardDays(this.tables,set)).map(day=>({index:day.item,control:this.cells[day.no-1]?.c('item_reward')}));
    await this.rewardAssets.prepare(requests);
    this.refresh();
  }
  refresh() {
    if (!this.win) return;
    const view = AT.boardView(this.tables, this.state(), this.now());
    this.cells.forEach(({ cell, c }, i) => {
      const cv = view.cells[i];
      cell.setVisible(!!cv);
      if (!cv) return;
      c('pan_base_view').setImage('none', 'AttendanceReward', cv.status === 'ready' ? AT.CELL_IMAGE.ready : cv.status === 'locked' ? AT.CELL_IMAGE.locked : AT.CELL_IMAGE.normal);
      c('pan_complate_view').setVisible(cv.status === 'done');
      if (AT.TYPE_ICON[cv.day.type]) c('pan_event_type').setImage('none', 'AttendanceReward', AT.TYPE_ICON[cv.day.type]);
      const item = c('item_reward');
      this.rewardAssets.paint(item, cv.day.item, cv.day.count);
      c('lbl_info').setText(String(cv.day.no));
      c('btn_event_click')._atStatus = cv.status;
    });
  }
  _timeText(seconds) { const t = remainingTimeText(seconds); return fillValues(this.S(CONNECT_REWARD_CATE, t.code), t.values).replace(/<\/?(font|color|center)[^>]*>/gi, ''); }
  /** Cell tooltip: the reward, the day's mission (2310:1001 with its time) and today's remaining time (5000:7). */
  _tooltip(no) {
    const view = AT.boardView(this.tables, this.state(), this.now()), cv = view.cells.find(c => c.day.no === no);
    if (!cv) return null;
    const lines = [{ text: `${itemName(this.game, cv.day.item)}${cv.day.count > 1 ? ` x ${cv.day.count}` : ''}`, color: 'ffffcc66', font: 3 }];
    const mission = AT.TYPE_TEXT[cv.day.type] ? this.S(AT.MISSION_CATE, AT.TYPE_TEXT[cv.day.type]) : '';
    if (mission) for (const l of fmt(mission, this._timeText(cv.day.value1)).split(/\r?\n/)) lines.push({ text: l.replace(/<\/?(font|color|center)[^>]*>/gi, '') });
    if (cv.status === 'today') lines.push({ text: `${this.S(CONNECT_REWARD_CATE, 7).replace(/<[^>]+>/g, '')} ${this._timeText(AT.missionRemaining(cv.day, this.state()))}`, color: 'ffffe08c' });
    return { lines, width: 230 };
  }

  async claim(no) {
    const g = this.game, view = AT.boardView(this.tables, this.state(), this.now()), cv = view.cells.find(c => c.day.no === no);
    if (!cv || cv.status !== 'ready') return false;
    // 2300:24 "%s / Claim this reward? / Only one character per account can claim."
    const answer = await box(g, fmt(this.S(AT.ATTEND_CATE, 24), itemName(g, cv.day.item)).replace(/<\/?font[^>]*>/gi, ''), { kind: 'yesno', name: 'attendance_claim' });
    if (answer !== 'yes') return false;
    let done = false;
    if (this.online) {
      const r = await g.network?.action?.('attendance', { set: view.set.index, no });
      done = !!r?.supportRewardResult;
    } else {
      const st = this.state(), check = AT.checkClaim(this.tables, st, this.now(), view.set.index, no, { hasItem: i => !!g.items?.def?.(i) || !!g.items?.db?.def?.(i) });
      if (!check.ok) msg(g, this._message(check.error), 'err');
      else if (!canGive(g, check.day.item, check.day.count) || !giveItem(g, check.day.item, check.day.count, { source: 'attendance' })) msg(g, this._message('bagFull'), 'err');
      else { AT.markClaimed(st, check.set, this.now()); account().attendance = st; saveAccount(); done = true; }
    }
    if (done) msg(g, this._message('received'), 'item');
    this.refresh();
    return done;
  }
  _message(key) { const m = REWARD_MESSAGES[key] || REWARD_MESSAGES.unknown; return strNow(this.game, REWARD_MESSAGE_CATE, m.code) || m.text; }

  update(dt) {
    if (!this.tables.sets.length) return;
    if (!this.online && this.game.player && Number.isFinite(dt) && dt > 0) {
      this._local += dt;
      if (this._local >= 5) { const s = Math.floor(this._local); this._local -= s; const st = this.state(); if (AT.addSeconds(this.tables, st, this.now(), s) || st.date !== account().attendance?.date) { account().attendance = st; saveAccount(); } }
    }
    this._t += dt;
    if (this._t < 1) return;
    this._t = 0;
    void this.syncAlarm();
    if (this.win?.isOpen) this.refresh();
  }
  dispose() { this.rewardAssets.dispose(); this.win = null; }
}
