// Events (share/event, script/eventinfo, script/contents_timetable.csv + contents_daystable.csv).
//
//  * Content timetable ("Content Timetable", title string 100:140; the chat window's btn_contentsview "You can view
//    a Time Table for contents that you can participate." 23:53): the client draws it in code from the
//    ContentsTable sprites of texture/ui/game/notice/contents_timetable.dds (Top 620x130 = title bar, the tab
//    column and the header row + 3 rows, Add_Mid 620x25 per extra row, Bottom 620x25, view / no_view 88x30 tab
//    states, close n/o/p, ? n/o/p). It is built here as a window script in the client's own tag format (the
//    same parser as every script/ui file). Tabs = csv TAB 1 daily contents, 2 weekly battlefields (+ the days
//    table), 3 field boss, 4 DK Square; the entry running now is green, the next one yellow.
//  * Virus / vaccine events (share/event/virus_event.csv): carrying the event item (type 0 code 43 "Start Event":
//    Vaccine Sample Bottle, Evidence Collection Card, Rudolph's Favour Card, New Year Virus Card) opens its
//    window: Type 0 = game2/event/ui_vaccine_event.txt (the Silk Filter gauge), Type 1 = ui_pointcard.txt (the
//    card with 10 stamps). Kills raise it: Increase_Normal per monster while the player level <= LevelCap,
//    Increase_Event_0/1 for the event monsters Event_Monster_Min..Max; at Object_Value the button gives
//    RewardItem_Index (type 0: "Reward") or summons RewardMosnter_Index next to the player (type 1: "Trace",
//    2300:8 "There's a mysterious-looking bundle somewhere around you."); the event item is used up.
//  * OX quiz (share/event/oxevent.csv MAX_USER, oxlist.csv 89 questions; maps 22 Undo Stadion / 654 Theme Park;
//    window game2/event/ui_oxquizwnd.txt; strings 2300:28-32): 15 rounds; the answer is the side of the arena the
//    player stands on when time is up - map 22's .mol marks it (ar_line_O / ar_flag_O north of the ar_line centre
//    row, ar_line_X / ar_flag_X south); maps without markers take the answer from chat ("O" / "X"). A wrong answer
//    sends the player out (the map's return point). Question 20 s, solution 8 s (the GM paced these live).
//  * Event message window (ui_eventmessagewnd.txt "EventMessageWnd"): the big centred announcement line.
//  * Event time (event_time.csv) is disabled in this client (Used 0); the publisher candy drops (china_7ongame,
//    korea_gamehi, korea_http, proxy) belong to other regions' services; script/eventinfo/info.csv disables the
//    event information screen (enable false). These are respected (not shown), see docs/formats/life.md.
import { parseTagScript, buildSpecs } from '../../ui/uiwin/index.js';
import { parseMol } from '../../formats/mol.js';
import { mapEnvironmentInfo } from '../../formats/environment.js';
import { fetchBuffer } from '../../engine/assets.js';
import { str, strNow, msg, msgRef, fmt, state, countItem, takeItem, giveItem, canGive, itemInfo, spawnMonster, registerChat, rejectUnsupportedOnline } from './common.js';

const TAB_NAMES = { 1: 'Daily', 2: 'Battlefield', 3: 'Field Boss', 4: 'DK Square' };
const DAY_NAMES = { 0: 'Sun', 1: 'Mon', 2: 'Tue', 3: 'Wed', 4: 'Thu', 5: 'Fri', 6: 'Sat', 7: 'Sun' };
const COLS = [[88, 88], [176, 89], [265, 178], [443, 104], [547, 73]];   // x, width of the 5 table columns
const OX_Q_SEC = 20, OX_A_SEC = 8, OX_ROUNDS = 15;

/** The timetable window script (client tag format) for `rows` data rows. */
function timetableScript(rows) {
  const R = Math.max(3, rows);
  const H = 130 + 25 * (R - 3) + 25;
  const L = [];
  const img = (screen, index, key = 'none') => `<image>\nkey ${key}\nscreen ${screen}\nindex ${index}\n</image>`;
  const title = (opts) => `<title>\nstate ${opts.state || 'none'}\ncolor ${opts.color || 'ffffffff'}\nfontindex ${opts.font ?? 2}\nposition ${opts.pos || '0 0'}\n${opts.text2 ? `text2 ${opts.text2}` : `text "${opts.text || ''}"`}\n</title>`;
  L.push('<window>', 'name contents_timetable', `rect 0 0 620 ${H}`, 'titlerect 0 0 620 28', 'layer 100');
  L.push('<panel>', 'id pan_top', 'rect 0 0 620 130', 'intersect true', img('ContentsTable', 0), '</panel>');
  for (let r = 3; r < R; r++) L.push('<panel>', `id pan_mid_${r}`, `rect 0 ${130 + 25 * (r - 3)} 620 25`, img('ContentsTable', 1), '</panel>');
  L.push('<panel>', 'id pan_bottom', `rect 0 ${130 + 25 * (R - 3)} 620 25`, img('ContentsTable', 2), '</panel>');
  L.push('<label>', 'id lbl_title', 'rect 0 6 620 18', 'align center', 'layer 10', title({ color: 'fff4be3d', font: 3, text2: '100 140' }), '</label>');
  L.push('<button>', 'id btn_close', 'rect 598 7 15 15', 'layer 10', 'sound 2', img('ContentsTable', 5), img('ContentsTable', 6, 'over'), img('ContentsTable', 7, 'down'), '</button>');
  L.push('<button>', 'id btn_help', 'rect 578 7 15 15', 'layer 10', 'tooltip 23 53', img('ContentsTable', 8), img('ContentsTable', 9, 'over'), img('ContentsTable', 10, 'down'), '</button>');
  for (let t = 1; t <= 4; t++) {
    L.push('<button>', `id btn_tab${t}`, `rect 0 ${30 + (t - 1) * 30} 88 30`, 'layer 5', 'align center center', img('ContentsTable', 4), img('ContentsTable', 3, 'check'),
      title({ text: TAB_NAMES[t], color: 'ffb4b4b4' }), title({ state: 'check', text: TAB_NAMES[t], color: 'ffffe08c' }), '</button>');
  }
  const heads = ['Time', 'End / Day', 'Content', 'Map', 'Level'];
  COLS.forEach(([x, w], c) => L.push('<label>', `id lbl_head_${c}`, `rect ${x} 30 ${w} 23`, 'align center center', 'layer 5', title({ text: heads[c], color: 'ffffe08c', font: 3 }), '</label>'));
  for (let r = 0; r < R; r++) {
    COLS.forEach(([x, w], c) => L.push('<label>', `id lbl_${r}_${c}`, `rect ${x} ${55 + 25 * r} ${w} 25`, 'align center center', 'layer 5', title({ text: '' }), '</label>'));
  }
  L.push('</window>');
  return L.join('\n');
}

export class LifeEvents {
  constructor(game, life) {
    this.game = game;
    this.life = life;
    this.E = life.data?.events || null;
    this.tab = 1;
    this.ox = null;
  }

  get st() { if(this.game.save?.authority==='server')return this.game.save.life?.events || { virus: {} };const s = state(this.game); if (!s.events) s.events = { virus: {} }; return s.events; }

  async install() {
    const g = this.game;
    if (!this.E) return;
    await Promise.all([str(g, 2300, 1), str(g, 100, 140), str(g, 23, 53)]);
    // content timetable (synthetic script from the client's sprites)
    const rows = Math.max(...[1, 2, 3, 4].map((t) => this._ttRows(t).length));
    const parsed = parseTagScript(timetableScript(rows), { file: 'life/contents_timetable' });
    const spec = buildSpecs(parsed.roots, { file: 'life/contents_timetable' }).windows[0];
    g.ui?.registerWindow?.('timetable', { script: spec, create: (w) => this._createTT(w), onOpen: (w) => this._fillTT(w) });
    g.uiwin?.registerMenuButton?.('btn_contentsview', 'timetable');
    // virus / vaccine
    g.ui?.registerWindow?.('vaccine', { script: 'game2/event/ui_vaccine_event.txt', create: (w) => w.control('btn_reward').onClick(() => this._reward()) });
    g.ui?.registerWindow?.('pointcard', { script: 'game2/event/ui_pointcard.txt', create: (w) => w.control('btn_reward').onClick(() => this._reward()) });
    g.events.on('death', ({ actor, killer }) => { if (actor?.kind === 'monster' && (killer === g.player || !killer)) this._kill(actor); });
    g.events.on('inventory', () => { this._invDirty = true; });
    // OX quiz
    g.ui?.registerWindow?.('oxquiz', { script: 'game2/event/ui_oxquizwnd.txt', hud: true, escClose: false, remember: false });
    g.ui?.registerWindow?.('eventmessage', { script: 'game2/ui_eventmessagewnd.txt', hud: true, escClose: false, remember: false });
    registerChat(g, (t) => this._oxChat(t));
  }

  // ------------------------------------------------------------------------------------------- announcements
  async announce(text, sec = 5) {
    const g = this.game;
    const w = await g.uiwin.open('eventmessage');
    w.control('lbl_message').setRichText(String(text || '').replace(/<\/?center>/gi, ''));
    w.control('lbl_message').spec = { ...w.control('lbl_message').spec, align: { h: 'center', v: 'top' } };
    clearTimeout(this._annT);
    this._annT = setTimeout(() => g.uiwin.close('eventmessage'), sec * 1000);
  }

  // ------------------------------------------------------------------------------------------- timetable
  _ttRows(tab) {
    const rows = this.E.timetable.filter((r) => r.tab === tab);
    if (tab === 2) for (const d of this.E.daystable || []) rows.push({ ...d, tab: 2, end: '' });
    return rows;
  }
  _createTT(w) {
    for (let t = 1; t <= 4; t++) w.control(`btn_tab${t}`).onClick(() => { this.tab = t; this._fillTT(w); });
  }
  _fillTT(w) {
    const rows = this._ttRows(this.tab);
    for (let t = 1; t <= 4; t++) w.control(`btn_tab${t}`).setChecked(t === this.tab);
    const now = new Date();
    const mins = now.getHours() * 60 + now.getMinutes();
    const dow = now.getDay() || 7;
    const toMin = (s) => { const m = /^(\d+):(\d+)/.exec(String(s || '')); return m ? (+m[1]) * 60 + (+m[2]) : null; };
    // running = within the hour (or until EndTime), next = the first later start today
    let nextIdx = -1, best = 1e9;
    rows.forEach((r, i) => { const s = toMin(r.time); if (s == null || (r.week && Number(r.week) !== dow)) return; const d = s - mins; if (d > 0 && d < best) { best = d; nextIdx = i; } });
    for (let i = 0; i < 40; i++) {
      const r = rows[i];
      for (let c = 0; c < 5; c++) {
        const ctl = w.find(`lbl_${i}_${c}`);
        if (!ctl) continue;
        if (!r) { ctl.setText(''); continue; }
        const s = toMin(r.time), e = toMin(r.end);
        const today = !r.week || Number(r.week) === dow;
        const running = today && s != null && (e != null ? (e > s ? mins >= s && mins < e : mins >= s || mins < e) : mins >= s && mins < s + 60);
        const txt = [r.time, r.end || (r.week ? DAY_NAMES[r.week] : ''), r.name, r.map, r.level][c];
        ctl.setText(txt || '').setTextColor(running ? 'ff00ff00' : i === nextIdx ? 'ffffff00' : 'ffffffff');
      }
    }
  }

  // ------------------------------------------------------------------------------------------- virus / vaccine
  _activeVirus() {
    for (const [i, r] of (this.E.virus || []).entries()) if (r.ItemIndex && countItem(this.game, r.ItemIndex) > 0) return { i, r };
    return null;
  }
  _winName(r) { return Number(r.Type) === 1 ? 'pointcard' : 'vaccine'; }
  _kill(m) {
    if(rejectUnsupportedOnline(this.game,'Vaccine and point-card progress',true))return false;
    const a = this._activeVirus();
    if (!a) return;
    const r = a.r, st = this.st;
    const idx = Number(m.def?.index ?? m.monsterIndex ?? 0);
    const lv = Number(this.game.save.level) || 1;
    let add = 0;
    if (r.Event_Monster_Min_0 && idx >= r.Event_Monster_Min_0 && idx <= r.Event_Monster_Max_0) add += Number(r.Increase_Event_0) || 0;
    else if (r.Event_Monster_Min_1 && idx >= r.Event_Monster_Min_1 && idx <= r.Event_Monster_Max_1) add += Number(r.Increase_Event_1) || 0;
    else if (lv <= (Number(r.LevelCap) || 250)) add += Number(r.Increase_Normal) || 0;
    if (!add) return;
    const key = String(r.Index);
    st.virus[key] = Math.min(Number(r.Object_Value) || 100, (st.virus[key] || 0) + add);
    this._refreshVirus();
  }
  async _refreshVirus() {
    const g = this.game;
    const a = this._activeVirus();
    for (const n of ['vaccine', 'pointcard']) if ((!a || this._winName(a.r) !== n) && g.uiwin.isOpen(n)) g.uiwin.close(n);
    if (!a) return;
    const r = a.r;
    const target = Number(r.Object_Value) || 100;
    const v = this.st.virus[String(r.Index)] || 0;
    const w = g.uiwin.isOpen(this._winName(r)) ? g.uiwin.window(this._winName(r)) : await g.uiwin.open(this._winName(r));
    if (Number(r.Type) === 1) {
      w.control('lbl_title').setText(strNow(g, 2300, r.ItemIndex === 1602718 ? 12 : 9));
      const stamps = Math.floor((v / target) * 10);
      for (let k = 1; k <= 10; k++) w.control(`point_${k}`).setImage('none', 'eventcard', k <= stamps ? 12 : 2);
      w.control('btn_reward').setEnabled(v >= target);
    } else {
      w.control('lbl_percent').setText(`${Math.floor((v / target) * 100)}%`);
      w.control('vaccine_HorizenGage').setGauge(v / target, { vertical: true });
      w.control('btn_reward').setEnabled(v >= target);
    }
  }
  async _reward() {
    const g = this.game;
    if(rejectUnsupportedOnline(g,'Vaccine and point-card rewards'))return false;
    const a = this._activeVirus();
    if (!a) { msgRef(g, 2300, 11, 'NORMAL', 'err'); return; }
    const r = a.r, key = String(r.Index);
    if ((this.st.virus[key] || 0) < (Number(r.Object_Value) || 100)) { msgRef(g, 2300, 16, 'NORMAL', 'err'); return; }
    if (r.RewardItem_Index) {
      if (!canGive(g, r.RewardItem_Index, 1)) { msgRef(g, 2300, 15, 'NORMAL', 'err'); return; }
      takeItem(g, r.ItemIndex, 1);
      giveItem(g, r.RewardItem_Index, 1, { source: 'event' });
      msgRef(g, 2300, 20, 'NORMAL', 'item');
    } else if (r.RewardMosnter_Index) {
      takeItem(g, r.ItemIndex, 1);
      const p = g.player;
      const ang = Math.random() * Math.PI * 2;
      const pt = g.world?.nearestWalkable?.(p.x + Math.cos(ang) * 3, p.z + Math.sin(ang) * 3, 6) || { x: p.x + 1, z: p.z };
      spawnMonster(g, r.RewardMosnter_Index, pt.x, pt.z);
      msgRef(g, 2300, 8, 'NORMAL', 'sys');
    }
    this.st.virus[key] = 0;
    g.persist?.();
    this._refreshVirus();
  }

  // ------------------------------------------------------------------------------------------- OX quiz
  isOxMap(i = this.game.world?.info?.index) { return (this.E.ox?.maps || []).includes(Number(i)); }

  async _oxZones(mapIndex) {
    try {
      const row = this.game.mapRow?.(mapIndex);
      const key = mapEnvironmentInfo(row)?.files?.mol;
      if (!key) return null;
      const mol = parseMol(await fetchBuffer(key));
      const find = (re) => mol.objects.find((o) => re.test(String(o.name || '')));
      const o = find(/ar_line_o$|ar_flag_o$/i), x = find(/ar_line_x$|ar_flag_x$/i);
      return o && x ? { o: { x: o.x, z: o.z }, x: { x: x.x, z: x.z } } : null;
    } catch { return null; }
  }

  async _oxStart() {
    const g = this.game;
    if(rejectUnsupportedOnline(g,'OX quiz',true))return false;
    const zones = await this._oxZones(g.world.info.index);
    if(rejectUnsupportedOnline(g,'OX quiz',true))return false;
    const used = new Set();
    this.ox = { round: 0, phase: 'wait', t: 8, zones, used, chat: null, map: g.world.info.index };
    this.announce(fmt(strNow(g, 2300, 32), 0));
  }

  _oxSide() {
    const O = this.ox, p = this.game.player;
    if (O.zones) {
      const dO = Math.hypot(p.x - O.zones.o.x, p.z - O.zones.o.z), dX = Math.hypot(p.x - O.zones.x.x, p.z - O.zones.x.z);
      return dO <= dX ? 'O' : 'X';
    }
    return O.chat;
  }

  _oxChat(text) {
    if(rejectUnsupportedOnline(this.game,'OX quiz',true))return false;
    if (!this.ox || this.ox.zones || this.ox.phase !== 'question') return false;
    const t = String(text || '').trim().toUpperCase();
    if (t !== 'O' && t !== 'X') return false;
    this.ox.chat = t;
    msg(this.game, t, 'chat');
    return true;
  }

  async _oxTick(dt) {
    if(rejectUnsupportedOnline(this.game,'OX quiz',true))return false;
    const O = this.ox, g = this.game;
    if (!O) return;
    if (!this.isOxMap() || g.world?.info?.index !== O.map) { this._oxEnd(); return; }
    O.t -= dt;
    const w = g.uiwin.window('oxquiz');
    if (O.phase === 'question' && w?.isOpen) w.control('lbl_desc').setText(`${fmt(strNow(g, 2300, 32), O.round)}   ${Math.max(0, Math.ceil(O.t))}`);
    if (O.t > 0) return;
    if (O.phase === 'wait' || O.phase === 'answer') {
      if (O.phase === 'answer' && O.eliminated) { this._oxEnd(true); return; }
      if (O.round >= OX_ROUNDS) { this._oxEnd(false, true); return; }
      const pool = this.E.ox.questions.filter((q) => !O.used.has(q.index));
      const q = pool[Math.floor(Math.random() * pool.length)] || this.E.ox.questions[0];
      O.used.add(q.index);
      O.q = q; O.round++; O.phase = 'question'; O.t = OX_Q_SEC; O.chat = null;
      const win = await g.uiwin.open('oxquiz');
      win.control('lbl_number').setRichText(fmt(strNow(g, 2300, 28), { COUNT: O.round }));
      win.control('lbl_desc').setText(fmt(strNow(g, 2300, 32), O.round));
      win.control('lbl_question').setText(q.q.replace(/^\[|\]$/g, ''));
      msg(g, fmt(strNow(g, 2300, 31), { COUNT: 1, MAX_COUNT: 1 }), 'sys');
    } else if (O.phase === 'question') {
      const side = this._oxSide();
      O.eliminated = side !== O.q.a;
      O.phase = 'answer'; O.t = OX_A_SEC;
      const win = g.uiwin.window('oxquiz');
      win?.control('lbl_number').setRichText(fmt(strNow(g, 2300, 29), { COUNT: O.round }));
      win?.control('lbl_desc').setText(fmt(strNow(g, 2300, 30), { ANSWER: O.q.a }));
      win?.control('lbl_question').setText(String(O.q.why || '').replace(/^\[|\]$/g, ''));
      msg(g, fmt(strNow(g, 2300, 31), { COUNT: O.eliminated ? 0 : 1, MAX_COUNT: 1 }), O.eliminated ? 'err' : 'sys');
    }
  }

  _oxEnd(eliminated = false, won = false) {
    const g = this.game;
    if(rejectUnsupportedOnline(g,'OX quiz',true))return false;
    const O = this.ox;
    this.ox = null;
    g.uiwin.close('oxquiz');
    if (won) this.announce(`${fmt(strNow(g, 2300, 31), { COUNT: 1, MAX_COUNT: 1 })}`, 6);
    if (eliminated && O && g.world?.info?.index === O.map) {
      const t = g.respawnTarget?.();
      if (t) g.travel(t.mapIndex, t);
    }
  }

  onMap(index) {
    if (this.ox && this.ox.map !== index) this._oxEnd();
    if (this.isOxMap(index)) this._oxStart();
    this._invDirty = true;
  }

  update(dt) {
    if (!this.E) return;
    if (this.ox) this._oxTick(dt);
    this._vt = (this._vt || 0) + dt;
    if (this._invDirty || this._vt > 3) { this._invDirty = false; this._vt = 0; this._refreshVirus(); }
    const tw = this.game.uiwin.window('timetable');
    if (tw?.isOpen) { this._tt = (this._tt || 0) + dt; if (this._tt > 20) { this._tt = 0; this._fillTT(tw); } }
  }
}
