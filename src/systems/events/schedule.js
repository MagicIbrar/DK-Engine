// Contents timetable (script/contents_timetable.csv -> events.json schedule.timetable; TAB 1 daily, 2 weekly
// battlefields, 3 field boss, 4 DK Square) in the original window game2/notice/ui_contentsnoticerenewwnd.txt
// ("contentsnotice": tabs btn_tab1..4, header pan_column, row template pan_list, frame pieces ContentsTable 0/1/2),
// opened by the chat window's btn_contentsview (registered menu button). Clicking a row offers to start that event now
// (any event can be started on demand): Dead Front / Ice Castle go to the lobby officer of the tier that fits the
// character's level, the field boss is called in Mitera, the other PvE contents travel to their map, the PvP ones answer
// with the original "No ongoing matches" text.
// The real clock drives the original announcements: party war application / entry / battle countdown messages
// (partywar #100/#200 at the config.csv offsets from time.csv) and the Saturday field boss (Mitera, 23:00).
import { plain, hudLog } from './text.js';
import { partyWarWindow, partyWarLobbyTimer } from './partywar-clock.js';
import {serverDate} from '../../game/server-time.js';

const ROW_H = 25;

export class Schedule {
  constructor(game, sys) {
    this.game = game;
    this.sys = sys;
    this.tab = 1;
    this._lastMin = -1;
    const ui = game.uiwin;
    ui?.registerWindow('ev_timetable', {
      script: 'game2/notice/ui_contentsnoticerenewwnd.txt',
      create: (win) => this._create(win),
      onOpen: (win) => this._fill(win),
    });
    ui?.registerMenuButton?.('btn_contentsview', 'ev_timetable');
  }

  get rows() { return this.sys.data?.ev?.schedule?.timetable || []; }
  open() { return this.game.uiwin?.open('ev_timetable'); }

  _create(win) {
    for (let i = 1; i <= 5; i++) {
      const b = win.control(`btn_tab${i}`);
      const has = this.rows.some(r => Number(r.TAB) === i);
      if (!has) { b.setVisible(false); continue; }
      b.onClick(() => { this.tab = i; this._fill(win); });
    }
    win.data.rows = [];
    win.data.mids = [];
  }

  _fill(win) {
    for (let i = 1; i <= 5; i++) win.control(`btn_tab${i}`).setChecked(i === this.tab);
    const rows = this.rows.filter(r => Number(r.TAB) === this.tab);
    const boss = this.tab === 3;
    const hasEnd = rows.some(r => r.EndTime);
    const col = id => win.control(id);
    col('lbl_column_time').setVisible(true);
    col('lbl_column_endtime').setVisible(hasEnd);
    for (const id of ['lbl_column_subject', 'lbl_column_map', 'lbl_column_level']) col(id).setVisible(!boss);
    for (const id of ['lbl_column_subject3', 'lbl_column_map3', 'lbl_column_level3']) col(id).setVisible(boss);
    // rows: clones of pan_list below the header, the frame grows with mid pieces (ContentsTable 1) before the bottom
    for (const r of win.data.rows) r.remove();
    win.data.rows = [];
    const tpl = win.control('pan_list');
    tpl.setVisible(false);
    const week = ['', 'Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'];
    rows.forEach((r, i) => {
      const c = tpl.cloneAs(`_${i}`, { x: 88, y: 30 + ROW_H * (i + 1), visible: true });
      const day = r.week ? `${week[Number(r.week)] || ''} ` : '';
      c.control(`lbl_time_${i}`).setText(`${day}${r.Time}`);
      c.control(`lbl_endtime_${i}`).setText(r.EndTime || '');
      c.control(`lbl_subject_${i}`).setText(r.Name || '');
      c.control(`lbl_map_${i}`).setText(r.Map || '');
      c.control(`lbl_level_${i}`).setText(r.Level || '');
      c.el.style.cursor = 'pointer';
      c.el.classList.add('uw-hit');
      c.el.style.pointerEvents = 'auto';
      c.el.title = `${r.Name} - ${r.Map}`;
      c.el.addEventListener('pointerenter', () => { c.el.style.background = 'rgba(255,255,255,0.08)'; });
      c.el.addEventListener('pointerleave', () => { c.el.style.background = ''; });
      c.el.addEventListener('click', (e) => { e.stopPropagation(); this._askStart(r); });
      win.data.rows.push(c);
    });
    const bodyEnd = Math.max(405, 30 + ROW_H * (rows.length + 1) + 5);
    for (const m of win.data.mids) m.remove();
    win.data.mids = [];
    const mid = win.control('pan_mid');
    for (let y = 130, k = 0; y < bodyEnd; y += ROW_H, k++) win.data.mids.push(mid.cloneAs(`_${k}`, { x: 0, y, visible: true }));
    win.control('pan_bottom').setRect(0, bodyEnd, 620, 25);
    win.control('pan_bg').setRect(0, 0, 620, bodyEnd + 25);
  }

  async _askStart(r) {
    const ui = this.game.uiwin;
    if (!ui) return;
    const ans = await ui.msgbox(`${r.Name}\n${r.Map} (${r.Level})\n\nStart now?`, { kind: 'yesno' });
    if (ans !== 'yes') return;
    ui.close('ev_timetable');
    this.startNow(r);
  }

  // ------------------------------------------------------------------------------------------ start on demand
  /** kind: a timetable row or one of 'deadFront' | 'iceCastle' | 'fieldBoss' | 'colosseumArena' | 'infiniteBattle' | map name. */
  async startNow(kind, opts = {}) {
    const d = this.sys.data;
    const name = typeof kind === 'string' ? kind : String(kind?.Name || '');
    const lv = Number(this.game.save?.level) || 1;
    const key = /dead ?front/i.test(name) ? 'deadFront' : /ice ?castle/i.test(name) ? 'iceCastle' : /field ?boss|mitera/i.test(name) ? 'fieldBoss'
      : /colosseum ?arena|colosseumArena/i.test(name) ? 'colosseumArena' : /infinite/i.test(name) ? 'infiniteBattle'
        : /draco|zuto|dk ?square|battle ?royal|guild|3v3|terra/i.test(name) ? 'pvp' : name;
    if (key === 'deadFront' || key === 'iceCastle') {
      const M = d.modes[key];
      const live = new Set((d.solo?.[key]?.liveMaps || []).map(Number));
      let best = null;
      for (const t of M.tiers || []) for (const m of t.maps || []) {
        if (!live.has(Number(m.map)) || !m.officerPlaced) continue;
        const [lo, hi] = m.entryLevel || [1, 250];
        if (lv >= lo && lv <= hi && (!best || (m.variant === 'normal' && best.variant !== 'normal'))) best = { ...m, tier: t };
      }
      const officer = best ? (M.officers || []).find(o => Number(o.npc) === Number(best.officers?.[0])) : null;
      const at = officer?.placed?.[0];
      const lobby = at ? Number(at[0]) : M.lobbies?.[0];
      if (!best) hudLog(this.game, plain(d.txt(key === 'iceCastle' ? 'stringtable_partywar2.txt' : 'stringtable_partywar.txt', 100, 2)).replace(/\n/g, ' '), 'err');
      await this.game.travel(lobby, at ? { x: Number(at[1]) + 1.5, z: Number(at[2]) + 1.5 } : null);
      if (officer) this._openNpcLater(Number(officer.npc));
      return;
    }
    if (key === 'fieldBoss') {
      const fb = d.dg?.fieldBosses?.[0] || {};
      this.sys.pending = null;
      await this.sys.enter(Number(fb.map) || 533, { mode: 'fieldBoss', x: (Number(fb.x) || 53) + 12.5, z: (Number(fb.y) || 57) + 12.5, entry: opts.entry || 'demand', startIn: opts.startIn ?? 10 });
      return;
    }
    if (key === 'colosseumArena' || key === 'infiniteBattle') {
      await this.game.travel(162, { x: 300.5, z: 213.5 });
      this._openNpcLater(5931);
      return;
    }
    if (key === 'pvp') {
      const t = plain(d.txt('stringtable_partywarui.txt', 2011, 554));
      this.game.uiwin?.msgbox(t, { kind: 'ok' });
      return;
    }
    // any other content (Elonohm: the Shrine of Elonohm with the dungeon guide Zurupas; Deadlands: the field): travel to
    // the map of that name. Names are compared by word set / squashed ("Shrine of Elonohm" = "Elonohm Shrine",
    // "The Dead Lands" = "The Deadlands").
    const words = s => String(s || '').toLowerCase().replace(/[^a-z0-9 ]/g, ' ').split(/\s+/).filter(w => w && !['the', 'of'].includes(w));
    const same = (a, b) => { const A = words(a), B = words(b); if (!A.length || !B.length) return false;
      return A.join('') === B.join('') || [...A].sort().join() === [...B].sort().join() || B.join(' ').includes(A.join(' ')); };
    const target = kind?.Map || name;
    for (const row of this.game.data?.maps?.values?.() || []) {
      const n = String(row.Name || '');
      if (n && !/test/i.test(n) && same(target, n)) { await this.game.travel(Number(row.Index)); return; }
    }
    hudLog(this.game, `${name}: no map found.`, 'err');
  }

  _openNpcLater(npcIndex) {
    let tries = 0;
    const tick = () => {
      const n = this.game.npcs?.find(x => Number(x.npcIndex) === npcIndex);
      if (n && !this.game._loadingMap) { this.game.windows?.openNpc?.(n); return; }
      if (tries++ < 40) setTimeout(tick, 250);
    };
    setTimeout(tick, 300);
  }

  // ------------------------------------------------------------------------------------------ clock
  update() {
    const epoch=Date.now(),now = serverDate(epoch);
    this._lobbyTimer(epoch);
    const min = now.getUTCHours() * 60 + now.getUTCMinutes();
    if (min === this._lastMin) return;
    this._lastMin = min;
    if (!this.sys.data || !this.game.player) return;
    this._partyWarClock('deadFront', now);
    this._partyWarClock('iceCastle', now);
    this._fieldBossClock(now);
  }

  _partyWarClock(mode, now) {
    const M = this.sys.data.modes[mode];
    const C = M?.config || {};
    const file = mode === 'iceCastle' ? 'stringtable_partywar2.txt' : 'stringtable_partywar.txt';
    const secNow = now.getUTCHours() * 3600 + now.getUTCMinutes() * 60;
    for (const s of M?.schedule || []) {
      const [h, m] = String(s.cycleStart).split(':').map(Number);
      const base = h * 3600 + m * 60;
      // config.csv column -> partywar string (column name + arithmetic). This local clock has minute granularity, so the
      // 30-second cue (BattleBefor30S 1770 -> 200:102) is host-only (server/world/events.mjs partyWarAnnouncements).
      const at = [[C.RecordBefore, 100, 100], [C.RecordTime, 100, 101], [C.RecordBeforeEnd, 100, 102], [C.RecordEndTime, 100, 103], [C.ChooseTime, 200, 7], [C.BattleBefor3M, 200, 100], [C.BattleBefor1M, 200, 101]];
      for (const [off, cate, code] of at) {
        if (off == null) continue;
        if (Math.floor(((base + Number(off)) % 86400) / 60) === Math.floor(secNow / 60)) {
          const e = this.sys.data.str(file, cate, code);
          if (e) this.sys.msg.say(e, { notice: cate === 100 });
        }
      }
    }
  }

  _lobbyTimer(now) {
    const world = this.game.world, map = Number(world?.info?.index), data = this.sys.data;
    const mode = !this.sys.run && ['deadFront', 'iceCastle'].find(key => data?.modes?.[key]?.lobbies?.includes(map));
    const clock = mode && partyWarLobbyTimer(mode, partyWarWindow(data.modes[mode], now, { upcoming: true }), now);
    if (!clock) { this._lobbyKey = null; this.sys.ui.close('ev_remaintime'); return; }
    const seconds = Math.ceil(Math.max(0, clock.until - now) / 1000), key = `${map}:${mode}:${clock.phase}:${seconds}`;
    if (this._lobbyKey === key && this.sys.ui._win('ev_remaintime')?.isOpen) return;
    this._lobbyKey = key;
    const fmt = data.txt(mode === 'iceCastle' ? 'stringtable_partywar2.txt' : 'stringtable_partywar.txt', clock.cate, clock.code);
    void this.sys.ui.lobbyTimer(fmt, seconds, { isCurrent: () => !this.sys.run && this.game.world === world && this._lobbyKey === key });
  }

  _fieldBossClock(now) {
    const fb = this.sys.data.dg?.fieldBosses?.[0];
    if (!fb || now.getUTCDay() !== Number(fb.day)) return;
    const min = now.getUTCHours() * 60 + now.getUTCMinutes();
    const start = Number(fb.start?.[0]) * 60 + Number(fb.start?.[1] || 0);
    const here = Number(this.game.world?.info?.index) === Number(fb.map);
    if (min === start - 5) { const e = this.sys.data.mapStr(Number(fb.map), 120); if (e) this.sys.msg.say(e); }
    if (min === start && here && !this.sys.run) this.sys.enter(Number(fb.map), { mode: 'fieldBoss', x: this.game.player.x, z: this.game.player.z, entry: 'schedule', startIn: 1 });
  }
}
