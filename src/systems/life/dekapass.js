// Deka Pass (share/dekapass: dekapassconfig / dekapassmission / dekapassreward, strings StringTable_DekaPass
// 3200-3206). Windows (game2/dekapass): dekapass (ui_dekapasswnd: 30 reward levels on 6 pages of 5, normal +
// premium row, level digits, point bar, Receive all, Mission list, Go to purchase pass), dekapassmissionlist
// (daily + season missions: name, progress, points, clear overlay, help tooltips), dekapassalarm (screen button).
// Rules: missions give `point` when their `count` is reached (daily missions reset every day and give at most
// DailyMaxPoint a day; season missions once a season); the season holds SeasonMaxPoint points = 30 levels of
// SeasonMaxPoint / 30. Every reached level unlocks its basic reward; the premium reward needs the premium pass
// (a "Premium Holy Water of Almighty" premiere item active). The season runs startTime..endTime (YYYYMMDD).
// Mission categories (csv side table): main/sub = LOGIN 0, QUEST 1, DUNGEON 2, DKSQUARE 3, REINFORCEM 4, ITEM 5,
// COSTUME 6, SOCKET 7, FISH 8, SOUL 9, WING 10, OPTION 11, CLEAR 12, SOLO 13, PARTY 14, TROOP 15, PARTICIPATE 16,
// WEAPON 17, ARMOR 18, ACCESSORY 19, WIN 20, LOOSE 21, USE 22, CREATE 23, SHAPECHANGE 24, GET 25, DISASSEMBLE 26,
// PET 27, TRANSPORTATION 28, UPGRADE 29, DAY 30, MONSTER 31, KILL 32, BUY 33, RELIVE 34, GUILD 35, DYNAMIC_OPTION 36;
// value = a list of map / quest / item / monster indexes the event must match (0 = any).
// Progress sources: play time (LOGIN), monster kills ('death'), 'quest:complete', 'dungeon:clear', 'fish',
// 'itemuse' / 'item:use', 'life:craft', and game.life.dekapass.progress(main, sub, value, count) for the other
// systems (upgrades, sockets, wings, mounts, DK Square, battlefields ...).
import { str, strNow, msgRef, state, itemIcon, itemTooltip, setMarkup, giveItem, canGive, itemInfo, dayKey, box } from './common.js';

import { DekaPassRewardAssets } from './dekapass-reward-assets.js';
import { premiumPassActive } from '../shops/premium-rules.js';
import { borrowPreviewIcon } from '../../ui/preview-cache.js';

const PER_PAGE = 5;
// Native mission help (stringtable_dekapass 3206): 3206:27 "Defeat 100,000 Monsters ... * Only kills by you or your party members
// count." (season mission 27); 3206:30 says party kills do NOT count for mission 30. Every other kill mission has no party rule in
// the data and counts only the player's own kills. [mission_type, index] of dekapassmission.csv.
export const PARTY_KILL_MISSIONS = Object.freeze([[1, 27]]);

export class DekaPass {
  constructor(game, life) {
    this.game = game;
    this.life = life;
    this.D = life.data?.dekapass || null;
    this.page = 0;
    this.rewardAssets = new DekaPassRewardAssets(async (id, { background = false } = {}) => {
      // Prefetch pages are background icon work: the loading screen's icons.queue wait skips them (items/preview-queue.js).
      const icons = this.game.items?.icons;
      const icon = await (background && icons?.background ? icons.background(() => itemIcon(this.game, id, 60, 60)) : itemIcon(this.game, id, 60, 60)); if (!icon?.url) return null;
      const release = borrowPreviewIcon(icon);
      try {
        if (typeof Image === 'function') { const image = new Image(); image.src = icon.url; await image.decode?.(); }
        return icon;
      } finally { release(); }
    }, { generation: () => this.game.items?.icons?.cache?.generation || 0 });
  }

  get cfg() { return this.D?.config || {}; }
  get season() { return Number(this.cfg.season) || 0; }
  get maxPoint() { return Number(this.cfg.SeasonMaxPoint) || 6000; }
  get levels() { return this.D?.rewards?.length || 30; }
  get perLevel() { return this.maxPoint / this.levels; }
  get now() { return typeof this.game.now==='function'?this.game.now():Date.now(); }

  get st() {
    const s = state(this.game);
    if (!s.dekapass || s.dekapass.season !== this.season) s.dekapass = { season: this.season, points: 0, day: 0, dayPoints: 0, daily: {}, dailyDone: {}, seasonProg: {}, seasonDone: {}, claimed: {}, claimedP: {}, playSec: 0 };
    const st = s.dekapass;
    const today = dayKey(new Date(this.now));
    if (st.day !== today) { st.day = today; st.dayPoints = 0; st.daily = {}; st.dailyDone = {}; st.playSec = 0; }
    return st;
  }
  get active() {
    const d = dayKey(new Date(this.now));
    return !!this.D && d >= (Number(this.cfg.startTime) || 0) && d <= (Number(this.cfg.endTime) || 99999999);
  }
  get level() { return Math.min(this.levels, Math.floor(this.st.points / this.perLevel)); }
  get premium() {
    // 3200:2 (premium-rules.js premiumPassActive): the premium services (save.premium = the server profile online) or the
    // solo item-use record (save.premiere) must hold an active Premium Holy Water of Almighty.
    const s = this.game.save, nameOf = i => itemInfo(this.game, i)?.name;
    return premiumPassActive(s?.premium, this.now, nameOf) || premiumPassActive(s?.premiere ? [s.premiere] : [], this.now, nameOf);
  }

  async install() {
    const g = this.game;
    if (!this.D) return;
    const refs = [];
    for (let c = 3200; c <= 3206; c++) refs.push(str(g, c, 1));
    await Promise.all(refs);
    g.ui?.registerWindow?.('dekapass', { script: 'game2/dekapass/ui_dekapasswnd.txt', create: (w) => this._create(w), onOpen: (w) => this._refresh(w), onClose: () => this._rewardAbort?.abort() });
    g.ui?.registerWindow?.('dekapassmissionlist', { script: 'game2/dekapass/ui_dekapassmissionlistwnd.txt', create: (w) => this._createMissions(w), onOpen: (w) => this._refreshMissions(w) });
    g.ui?.registerWindow?.('dekapassalarm', { script: 'game2/dekapass/ui_dekapassalarmwnd.txt', hud: true, escClose: false, remember: false,
      create: (w) => w.control('btn_alarm').onClick(() => g.uiwin.toggle('dekapass')) });
    (g._interfaceIconTasks ||= []).push(this.prewarm());
    this._rewardCatalogOff = g.events?.on?.('server:customitems', () => {
      this.rewardAssets.sync();
      if (this.win?.isOpen) void this._refresh(this.win);
      const ready = this.prewarm();
      if (!g._worldReady) (g._interfaceIconTasks ||= []).push(ready);
    });
    // progress sources
    const ev = g.events;
    ev.on('death', ({ actor, killer }) => { if (actor?.kind === 'monster' && (killer === g.player || !killer)) this.progress(31, 32, actor.def?.index ?? actor.monsterIndex ?? 0, 1); });
    ev.on('quest:complete', ({ id }) => this.progress(1, 12, id, 1));
    ev.on('dungeon:clear', (e) => { const map = e?.map ?? g.world?.info?.index; this.progress(2, 12, map, 1); this.progress(2, { solo: 13, party: 14, troop: 15 }[e?.kind || e?.type || 'solo'] || 13, map, 1); });
    ev.on('fish', (e) => { if (e?.item) this.progress(8, 25, e.item, 1); });
    ev.on('itemuse', (e) => this.progress(5, 22, e?.item?.itemIndex ?? e?.def?.index ?? 0, 1));
    ev.on('item:use', (e) => this.progress(5, 22, e?.itemIndex ?? e?.item?.itemIndex ?? 0, 1));
    ev.on('life:craft', (e) => { if (e.phase === 'receive' && e.success > 0) this.progress(0, 23, e.item, e.success); });
    ev.on('item:upgrade', (e) => { const sub = { weapon: 17, armor: 18, accessory: 19 }[e?.kind]; if (sub) this.progress(4, sub, 0, 1); });
    ev.on('life:dekapass:event', (e) => this.progress(e.main, e.sub, e.value ?? 0, e.count ?? 1));
  }

  /** A game event: main/sub category, the matched value (map / quest / item / monster index), how many. `party` = a kill made
   *  by another party member: only the missions whose native help says party kills count (PARTY_KILL_MISSIONS) advance. */
  progress(main, sub, value = 0, count = 1, { party = false } = {}) {
    if (!this.active) return;
    const st = this.st;
    let changed = false;
    for (const m of this.D.missions) {
      if (m.main !== Number(main) || m.sub !== Number(sub)) continue;
      if (party && !PARTY_KILL_MISSIONS.some(([type, index]) => m.type === type && m.index === index)) continue;
      if (m.value.length && !m.value.includes(Number(value))) continue;
      const daily = m.type === 0;
      const prog = daily ? st.daily : st.seasonProg, done = daily ? st.dailyDone : st.seasonDone;
      if (done[m.index]) continue;
      prog[m.index] = Math.min(m.count, (prog[m.index] || 0) + count);
      changed = true;
      if (prog[m.index] >= m.count) this._complete(m);
    }
    if (changed) this._dirty = true;
  }

  _complete(m) {
    const g = this.game, st = this.st;
    const daily = m.type === 0;
    (daily ? st.dailyDone : st.seasonDone)[m.index] = true;
    let pts = m.point;
    if (daily) { const cap = Number(this.cfg.DailyMaxPoint) || 200; pts = Math.max(0, Math.min(pts, cap - st.dayPoints)); st.dayPoints += pts; }
    const before = this.level;
    st.points = Math.min(this.maxPoint, st.points + pts);
    const name = strNow(g, daily ? 3201 : 3202, m.index);
    g.hud?.log?.(`[Deka Pass] ${name} (+${pts})`, 'exp');
    if (this.level > before) g.hud?.log?.(`[Deka Pass] Lv. ${this.level}`, 'exp');
    this._alarm();
    g.events?.emit?.('life:dekapass', { mission: m.index, daily, points: st.points, level: this.level });
  }

  // =========================================================================================== reward window
  _create(w) {
    const g = this.game;
    this.win = w;
    for (let i = 0; i < 4; i++) w.control(`btn_LoadingIcon_${i}`).hide();       // server-wait spinners
    w.control('btn_missionlist').onClick(() => g.uiwin.open('dekapassmissionlist'));
    w.control('btn_receiveall').onClick(() => this.claimAll());
    w.control('btn_buypass').onClick(() => this._buyPass());
    w.control('btn_buypass').setTooltip(() => strNow(g, 3200, 2));
    const info = w.control('pan_rewardinfo');
    info.control('btn_prepage').onClick(() => { this.page = Math.max(0, this.page - 1); this._refresh(w); });
    info.control('btn_nextpage').onClick(() => { this.page = Math.min(this._pages() - 1, this.page + 1); this._refresh(w); });
    // 5 reward columns from the template pan_reward_ (usetrail): 128 wide, 131 apart
    const tpl = info.control('pan_reward_');
    tpl.hide();
    this.cols = [];
    for (let k = 0; k < PER_PAGE; k++) {
      const c = tpl.cloneAs(`_${k}`, { x: 26 + k * 131, y: 0 });
      this.cols.push(c);
      c.control(`btn_normal_${k}`).onClick(() => this.claim(this.page * PER_PAGE + k + 1, false));
      c.control(`btn_premium_${k}`).onClick(() => this.claim(this.page * PER_PAGE + k + 1, true));
    }
    for (let p = 0; p < 6; p++) info.control('pan_page').control(`pan_page_${p}`).on('click', () => { this.page = p; this._refresh(w); });
  }

  async prewarm() {
    // Repeat only when the server catalog invalidated a preparation already in flight.
    for (let attempt = 0; attempt < 3; attempt++) {
      const generation = this.rewardAssets.sync();
      const values = await this.rewardAssets.page(this.D?.rewards || [], 0, { priority: 1 });
      if (this.rewardAssets.disposed || generation === this.rewardAssets.sync()) return values;
    }
    return [];
  }
  dispose() { this._rewardAbort?.abort(); this._rewardCatalogOff?.(); this.rewardAssets.dispose(); }

  _rewardIcon(control, index, count, signal) {
    // Clear previous-page art and update selected identity before asynchronous work.
    control.setIcon?.(index ? this.rewardAssets.now(index) : null);
    control.setCount?.(index && count > 1 ? count : null);
    control.setTooltip?.(index ? () => itemTooltip(this.game, index, count) : null);
    if (!index) return Promise.resolve(null);
    return this.rewardAssets.visible(index, {
      signal, owner: control, isVisible: () => !signal.aborted && !!this.win?.isOpen,
      onReady: icon => {
        control.setIcon?.(icon);
        const box = control.box || {}, el = control._icon;
        if (el && box.w && box.h && (60 < box.w || 60 < box.h)) Object.assign(el.style, {
          left: Math.round((box.w - 60) / 2) + 'px', top: Math.round((box.h - 60) / 2) + 'px', width: '60px', height: '60px'
        });
      }
    });
  }

  _pages() { return Math.ceil(this.levels / PER_PAGE); }

  _digits(ctlT, ctlU, n, yellow) {
    const base = yellow ? 100 : 110;
    const t = Math.floor(n / 10) % 10, u = n % 10;
    ctlT.setVisible(n >= 10); if (n >= 10) ctlT.setImage('none', 'DekaPass', base + t);
    ctlU.setImage('none', 'DekaPass', base + u);
  }

  async _refresh(w) {
    const g = this.game, st = this.st;
    this._rewardAbort?.abort();
    const signal = (this._rewardAbort = new AbortController()).signal;
    const lv = this.level;
    // current level + point bar (points inside the level)
    const rl = w.control('pan_rewardlevel');
    this._digits(rl.control('pan_tensdigit'), rl.control('pan_unitdigit'), lv, true);
    const inLv = lv >= this.levels ? this.perLevel : st.points - lv * this.perLevel;
    w.control('processbar').setGauge(Math.max(0, Math.min(1, inLv / this.perLevel)));
    w.control('lbl_point').setText('%d / %d', Math.round(inLv), Math.round(this.perLevel));
    w.control('lbl_point').setTooltip(() => `${st.points} / ${this.maxPoint}`);
    w.control('pan_possiblereceiveall').setVisible(this._claimable().length > 0);
    const info = w.control('pan_rewardinfo');
    info.control('btn_prepage').setEnabled(this.page > 0);
    info.control('btn_nextpage').setEnabled(this.page < this._pages() - 1);
    for (let p = 0; p < 6; p++) info.control('pan_page').control(`pan_page_${p}`).setVisible(p < this._pages()).setImage('none', 'DekaPass', p === this.page ? 17 : 18);   // PageActive / PageDeactive
    const prem = this.premium;
    for (let k = 0; k < PER_PAGE; k++) {
      const c = this.cols[k];
      const L = this.page * PER_PAGE + k + 1;
      const row = this.D.rewards[L - 1];
      c.setVisible(!!row);
      if (!row) continue;
      const five = L % 5 === 0, cur = L === lv + 1 || (L === lv && lv === this.levels);
      c.control(`pan_rewardlevel_${k}`).setImage('none', 'DekaPass', five ? 33 : 32);
      // cloneAs renames template ids ending in '_' with the digits: pan_tensdigit_ -> pan_tensdigit_<k>
      this._digits(w.control(`pan_tensdigit_${k}`), w.control(`pan_unitdigit_${k}`), L, L <= lv);
      w.control(`pan_leveltag_${k}`).setImage('none', 'DekaPass', L <= lv ? 98 : 99);
      // normal
      const nClaimed = !!st.claimed[L];
      c.control(`pan_normal_${k}`).setImage('none', 'DekaPass', nClaimed ? 19 : five ? (cur ? 23 : 22) : (cur ? 21 : 20));
      setMarkup(c.control(`lbl_normal_${k}`), strNow(g, 3203, L) || itemInfo(g, row.basic[0])?.name || '');
      void this._rewardIcon(c.control(`item_normal_${k}`), row.basic[0], row.basic[1], signal);
      c.control(`btn_normal_${k}`).setEnabled(L <= lv && !nClaimed);
      // premium
      const hasP = row.premium[0] > 0;
      const pClaimed = !!st.claimedP[L];
      c.control(`pan_premium_${k}`).setImage('none', 'DekaPass', pClaimed ? 25 : five ? (cur ? 29 : 28) : (cur ? 27 : 26));
      setMarkup(c.control(`lbl_premium_${k}`), hasP ? (strNow(g, 3204, L) || itemInfo(g, row.premium[0])?.name || '') : '');
      void this._rewardIcon(c.control(`item_premium_${k}`), hasP ? row.premium[0] : 0, row.premium[1], signal);
      c.control(`pan_premiumlock_${k}`).setVisible(hasP && !prem && !pClaimed);
      c.control(`btn_premium_${k}`).setEnabled(hasP && prem && L <= lv && !pClaimed);
    }
    void this.rewardAssets.neighbors(this.D.rewards, this.page, { signal });
  }

  _claimable() {
    const st = this.st, lv = this.level, out = [];
    for (let L = 1; L <= lv; L++) {
      const row = this.D.rewards[L - 1];
      if (!row) continue;
      if (!st.claimed[L]) out.push([L, false]);
      if (this.premium && row.premium[0] > 0 && !st.claimedP[L]) out.push([L, true]);
    }
    return out;
  }

  claim(L, premium = false) {
    const g = this.game, st = this.st;
    const row = this.D.rewards[L - 1];
    if (!row || L > this.level) return false;
    const [item, count] = premium ? row.premium : row.basic;
    if (!item) return false;
    if (premium && !this.premium) { box(g, strNow(g, 3200, 2), { title: strNow(g, 3200, 1) }); return false; }
    if ((premium ? st.claimedP : st.claimed)[L]) return false;
    if (!canGive(g, item, count)) { msgRef(g, 260, 1, 'NORMAL', 'err').catch(() => {}); g.hud?.log?.('Your inventory is full.', 'err'); return false; }
    if (!giveItem(g, item, count, { source: 'dekapass' })) return false;
    (premium ? st.claimedP : st.claimed)[L] = true;
    g.persist?.();
    if (this.win?.isOpen) this._refresh(this.win);
    this._alarm();
    return true;
  }

  claimAll() { let n = 0; for (const [L, p] of this._claimable()) if (this.claim(L, p)) n++; return n; }

  _buyPass() {
    const g = this.game;
    // "Go to purchase pass": the D-Shop (shops system) where the premium Holy Water is sold
    if (g.uiwin.has?.('dshop')) g.uiwin.open('dshop', { search: 'Premium Holy Water' });
    else if (g.uiwin.has?.('cashshop')) g.uiwin.open('cashshop');
    else g.uiwin.menuAction?.('btn_cash') || box(g, strNow(g, 3200, 2), { title: strNow(g, 3200, 1) });
  }

  // =========================================================================================== missions window
  _createMissions(w) {
    this.mwin = w;
    for (const kind of ['daily', 'season']) {
      const pan = w.control(`pan_${kind}`);
      const tpl = pan.control(`pan_${kind}mission_`);
      tpl.hide();
      const list = this.D.missions.filter((m) => (m.type === 0) === (kind === 'daily'));
      const rows = list.map((m, i) => {
        const r = tpl.cloneAs(`_${i}`, { x: 0, y: i * 45 });
        r.data.mission = m;
        const help = strNow(this.game, kind === 'daily' ? 3205 : 3206, m.index);
        const hb = r.control(`btn_${kind}missionhelp_${i}`);
        hb.setVisible(!!help);
        if (help) hb.setTooltip(help);
        return r;
      });
      pan.setClip?.(true);
      const sc = w.control(`vscroll_${kind}`);
      const view = 7;
      let top = 0;
      const place = () => rows.forEach((r, i) => r.setRect(0, (i - top) * 45, 380, 45));
      const setTop = (t) => { top = Math.max(0, Math.min(Math.max(0, rows.length - view), Math.round(t))); place(); sc.setValue?.(top); };
      sc.setRange?.(Math.max(0, rows.length - view), view);
      sc.on('change', (v) => { if (v !== top) setTop(v); });
      pan.el.addEventListener('wheel', (e) => { e.preventDefault(); e.stopPropagation(); setTop(top + Math.sign(e.deltaY)); }, { passive: false });
      w.data[`${kind}Rows`] = rows;
      w.data[`${kind}SetTop`] = setTop;
      setTop(0);
    }
  }

  _refreshMissions(w) {
    const g = this.game, st = this.st;
    for (const kind of ['daily', 'season']) {
      const rows = w.data[`${kind}Rows`] || [];
      let done = 0;
      rows.forEach((r, i) => {
        const m = r.data.mission;
        const daily = kind === 'daily';
        const prog = (daily ? st.daily : st.seasonProg)[m.index] || 0;
        const isDone = !!(daily ? st.dailyDone : st.seasonDone)[m.index];
        if (isDone) done++;
        r.control(`lbl_${kind}mission_${i}`).setText(strNow(g, daily ? 3201 : 3202, m.index));
        r.control(`lbl_${kind}mission_count_${i}`).setText(m.main === 0 && m.sub === 0 ? `${Math.floor(Math.min(prog, m.count) / 60)} / ${Math.floor(m.count / 60)} min` : `${Math.min(prog, m.count)} / ${m.count}`);
        r.control(`lbl_${kind}mission_point_${i}`).setText(`+${m.point}`);
        r.control(`pan_${kind}mission_done_${i}`).setVisible(isDone);
      });
      w.control(`lbl_${kind}mission_donecount`).setText(`${done} / ${rows.length}`);
    }
  }

  _alarm() {
    const g = this.game;
    const w = g.uiwin.window('dekapassalarm');
    w?.control('btn_alarm').setBlink(this._claimable().length > 0);
  }

  update(dt) {
    if (!this.D || !this.game.world) return;
    if (this.active && !this._alarmShown) { this._alarmShown = true; this.game.uiwin.open('dekapassalarm').then(() => this._alarm()); }
    // LOGIN: 30 minutes of play a day
    const st = this.st;
    st.playSec = (st.playSec || 0) + dt;
    this._lt = (this._lt || 0) + dt;
    if (this._lt >= 5) { const add = Math.floor(this._lt); this._lt -= add; this.progress(0, 0, 0, add); }
    this._rt = (this._rt || 0) + dt;
    if (this._rt >= 0.5) {
      this._rt = 0;
      if (this._dirty) {
        this._dirty = false;
        if (this.win?.isOpen) this._refresh(this.win);
        if (this.mwin?.isOpen) this._refreshMissions(this.mwin);
      }
    }
  }
}
