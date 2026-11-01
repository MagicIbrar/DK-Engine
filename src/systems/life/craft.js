// Crafting system ("Crafting System", share/craft/craft.csv + craft_exp.csv, script/product/product_list_*.csv,
// strings stringtable_craft 2900 / 2901). Windows (game2/production):
//   craft          ui_product.txt       tabs: 1 = the chosen mastery's tree (Weapon / Armor / Alchemy), 2 = Common,
//                                       3 = In-progress; right: the recipe (result item, required mastery level,
//                                       earned mastery, cost, time, success rate, ingredients with have/need),
//                                       count - / + / MAX, Craft, Receive all, search + refresh. Hotkey Ctrl+R /
//                                       main menu btn_craft.
//   craftprogress  ui_productinfo.txt   the 3 craft slots: remaining time, Cancel Crafting / Receive Item, the
//                                       catalyst clock, "Add Craft Slot" (Dora's Workshop item, type 1 code 34).
//   craftmastery   ui_productlean.txt   choose / change the mastery (NPC Dora, job SELECT_CRAFT_TYPE 116);
//                                       the 1st change is free, then 10 000 / 100 000 / 1 000 000 / 10 000 000 dil.
//   craftcatalyst  ui_productcatalyst.txt  shorten a craft with a Catalyst (type 1 code 33, value2 = seconds).
//   craftalarm     ui_product_alarm.txt a screen button while something is crafting (blinks when ready).
// Rules (craft.csv): Type 1 weapon / 2 armor / 3 alchemy (the mastery's recipes) / 11 common; need_point = the
// required craft level, reward_point = mastery exp per success, dil and time (s) per unit, Probability % success,
// Max_count per order, item_1..10 / count_1..10 ingredients. Craft level: 1 + the craft_exp.csv rows reached.
// Crafts run on real time (they finish while the game is closed, as on the server); the result is received from
// the progress list. Cancel returns the ingredients and dil (2900:223: equipment ingredients come back as new items).
import { str, strNow, msgRef, box, fmt, itemInfo, countItem, takeItem, giveItem, canGiveAll, dil, spendDil, addDil,
  state, setItemIcon, numText } from './common.js';
import { placeAlarmButton } from '../extras/alarm-slots.js';

const TYPE_TAB = { 1: 'weapon', 2: 'armor', 3: 'alchemy' };
const TYPE_STR = { 1: 1, 2: 2, 3: 3 };           // 2900:1..3 tab captions
const S = (game, code) => strNow(game, 2900, code);
const M = (game, code) => strNow(game, 2901, code);

function timeText(sec) {
  sec = Math.max(0, Math.ceil(sec));
  const d = Math.floor(sec / 86400), h = Math.floor((sec % 86400) / 3600), m = Math.floor((sec % 3600) / 60), s = sec % 60;
  const p = (n) => String(n).padStart(2, '0');
  return d > 0 ? `${d}D ${p(h)}:${p(m)}:${p(s)}` : `${p(h)}:${p(m)}:${p(s)}`;
}

export class Craft {
  constructor(game, life) {
    this.game = game;
    this.life = life;
    this.C = life.data?.craft || null;
    this.tab = 1;
    this.sel = null;              // selected recipe index
    this.count = 1;
    this.filter = '';
    this.win = null;
  }

  get st() {
    const s = state(this.game);
    if (!s.craft) s.craft = { type: null, exp: 0, resets: 0, slots: this.C?.slots?.base || 1, jobs: [] };
    return s.craft;
  }
  get level() {
    const ex = this.st.exp || 0;
    let lv = 1;
    for (const r of this.C?.exp || []) if (r.level === lv && ex >= r.exp) lv = r.level + 1;
    return Math.min(lv, (this.C?.exp?.length || 10));
  }
  /** exp progress inside the current level: {cur, need, frac} */
  levelProgress() {
    const lv = this.level, rows = this.C?.exp || [];
    const need = rows.find((r) => r.level === lv)?.exp || 0;
    const prev = rows.find((r) => r.level === lv - 1)?.exp || 0;
    const ex = this.st.exp || 0;
    if (!need || lv >= rows.length && ex >= need) return { cur: ex, need: need || ex, frac: 1 };
    return { cur: ex - prev, need: need - prev, frac: Math.max(0, Math.min(1, (ex - prev) / Math.max(1, need - prev))) };
  }
  recipe(i) { return this.C?.recipes?.[String(i)] || null; }

  async install() {
    const g = this.game;
    if (!this.C) return;
    await Promise.all([str(g, 2900, 1), str(g, 2901, 1)]);
    g.ui?.registerWindow?.('craft', { script: 'game2/production/ui_product.txt', menuButton: 'btn_craft',
      create: (w) => this._createMain(w), onOpen: (w) => this._openMain(w), update: (w, dt) => this._tickMain(w, dt) });
    g.ui?.registerWindow?.('craftprogress', { script: 'game2/production/ui_productinfo.txt',
      create: (w) => this._createProgress(w), onOpen: (w) => this._refreshProgress(w), update: (w) => this._refreshProgress(w, true) });
    g.ui?.registerWindow?.('craftmastery', { script: 'game2/production/ui_productlean.txt', create: (w) => this._createMastery(w) });
    g.ui?.registerWindow?.('craftcatalyst', { script: 'game2/production/ui_productcatalyst.txt', modal: true,
      create: (w) => this._createCatalyst(w), onOpen: (w, slot) => this._openCatalyst(w, slot) });
    g.ui?.registerWindow?.('craftalarm', { script: 'game2/production/ui_product_alarm.txt', hud: true, escClose: false, remember: false,
      create: (w) => w.control('btn_alarm').onClick(() => g.uiwin.toggle('craftprogress')) });
    this._alarmCheck();
  }

  registerServices(reg) {
    reg.register(116, () => { this.game.uiwin.open('craftmastery'); return true; });
    reg.register('SELECT_CRAFT_TYPE', () => { this.game.uiwin.open('craftmastery'); return true; });
  }

  // =========================================================================================== main window
  _createMain(w) {
    this.win = w;
    for (let t = 1; t <= 3; t++) w.control(`btn_tab${t}`).onClick(() => this._setTab(w, t));
    for (let t = 1; t <= 3; t++) {
      const tree = w.control(`pan_tab${t}`).control('multi_tree');
      tree.on('select', (n) => { if (n?.data?.recipe) this._select(w, n.data.recipe, n.data.job); });
    }
    w.control('btn_minus').onClick(() => this._setCount(w, this.count - 1));
    w.control('btn_plus').onClick(() => this._setCount(w, this.count + 1));
    w.control('btn_max').onClick(() => this._setCount(w, this._maxCount(this.sel)));
    w.control('btn_make').onClick(() => this.make(this.sel, this.count));
    w.control('btn_receiveall').setText(S(this.game, 109)).onClick(() => this.receiveAll());
    w.control('btn_receiveall').setTooltip(() => S(this.game, 109));
    w.control('btn_refresh').setTooltip(() => 'Refresh').onClick(() => { w.control('edit_search').setValue?.(''); this.filter = ''; this._fillTrees(w); });
    const doSearch = () => { this.filter = String(w.control('edit_search').getValue?.() || '').trim().toLowerCase(); this._fillTrees(w); };
    w.control('btn_search').onClick(doSearch);
    w.control('edit_search').on('enter', doSearch);
    // ingredient rows: the textbox's 6 row templates (pan_line1..6), 4 more cloned for 7..10 ingredients
    const tb = w.control('textbox');
    for (let k = 7; k <= 10; k++) tb.control('pan_line1').cloneAs(`_x${k}`, { y: (k - 1) * 40, visible: false });
    tb.setClip?.(true);
    this._lineTop = 0;
    tb.scroll?.on('change', (v) => { this._lineTop = v; this._placeLines(w); });
    tb.el.addEventListener('wheel', () => setTimeout(() => { this._lineTop = tb.top || 0; this._placeLines(w); }, 0));
  }

  _lineCtl(w, k) { const tb = w.control('textbox'); return k <= 6 ? tb.control(`pan_line${k}`) : tb.control(`pan_line1_x${k}`); }

  _openMain(w) {
    const g = this.game;
    if (!this.st.type) {
      // no mastery yet: 2901:149 "Please learn the Craft mastery first from Dora ..." (the common tab still works)
      msgRef(g, 2901, 149, 'NORMAL', 'err');
    }
    w.control('btn_tab1').setText(this.st.type ? S(g, TYPE_STR[this.st.type]) : S(g, 1));
    w.control('btn_tab1').setEnabled(!!this.st.type);
    if (!this.st.type && this.tab === 1) this.tab = 2;
    this._fillTrees(w);
    this._setTab(w, this.tab);
    this._refreshLevel(w);
    this._select(w, this.sel);
  }

  _setTab(w, t) {
    this.tab = t;
    for (let k = 1; k <= 3; k++) { w.control(`btn_tab${k}`).setChecked(k === t); w.control(`pan_tab${k}`).setVisible(k === t); }
    if (t === 3) this._fillProgressTree(w);
  }

  /** Build the recipe trees of tab 1 (mastery) and tab 2 (common) from the product lists. */
  _fillTrees(w) {
    const g = this.game, T = this.C.trees;
    const build = (rows) => {
      const root = [];
      const stack = [];
      for (const r of rows) {
        const rec = r.code ? this.recipe(r.code) : null;
        const node = { text: r.name, state: r.depth <= 1 ? 'head' : rec ? 'none' : 'sub', children: [], data: rec ? { recipe: r.code } : null, selectable: !!rec };
        if (rec) {
          const lvOk = this.level >= (rec.needPoint || 1);
          node.color = lvOk ? null : '#8c8c8c';
          node.text = rec.name || r.name;
        }
        while (stack.length && stack[stack.length - 1].depth >= r.depth) stack.pop();
        const parent = stack[stack.length - 1]?.node;
        (parent ? parent.children : root).push(node);
        stack.push({ depth: r.depth, node });
      }
      // search filter: keep branches with a matching recipe
      const f = this.filter;
      const prune = (list) => list.filter((n) => {
        if (n.children.length) { n.children = prune(n.children); if (!n.children.length) delete n.children; }
        const hit = !f || String(n.text).toLowerCase().includes(f);
        return n.data ? hit : !!n.children?.length || (!f && n.children);
      });
      const out = prune(root);
      const tidy = (list) => { for (const n of list) { if (Array.isArray(n.children) && !n.children.length) delete n.children; else if (n.children) tidy(n.children); if (f) n.open = true; } };
      tidy(out);
      return out;
    };
    const t1 = this.st.type ? T[TYPE_TAB[this.st.type]] || [] : [];
    w.control('pan_tab1').control('multi_tree').setNodes(build(t1));
    w.control('pan_tab2').control('multi_tree').setNodes(build(T.common || []));
    this._fillProgressTree(w);
    void g;
  }

  _fillProgressTree(w) {
    const nodes = this.st.jobs.map((j, i) => {
      const rec = this.recipe(j.recipe);
      const left = Math.max(0, (j.end - Date.now()) / 1000);
      return { text: `${rec?.name || j.recipe} x${j.count}`, right: left > 0 ? timeText(left) : S(this.game, 109), state: left > 0 ? 'none' : 'finish', data: { recipe: j.recipe, job: i }, selectable: true };
    });
    w.control('pan_tab3').control('multi_tree').setNodes(nodes.length ? nodes : [{ text: M(this.game, 18), state: 'unknown' }]);
  }

  _refreshLevel(w) {
    const g = this.game;
    const lv = this.level, pr = this.levelProgress();
    w.control('lbl_production_level').setText(fmt(S(g, 17), lv));
    w.control('pan_gauge').setGauge(pr.frac);
    w.control('lbl_line_submemo').setText(`${numText(pr.cur)} / ${numText(pr.need)}`);
  }

  _maxCount(ri) {
    const rec = this.recipe(ri);
    if (!rec) return 1;
    let n = Math.max(1, rec.max || 1);
    for (const [it, c] of rec.mats) n = Math.min(n, Math.floor(countItem(this.game, it) / c));
    if (rec.dil > 0) n = Math.min(n, Math.floor(dil(this.game) / rec.dil));
    return Math.max(1, n);
  }

  _setCount(w, n) {
    const rec = this.recipe(this.sel);
    const max = rec ? Math.max(1, rec.max || 1) : 1;
    this.count = Math.max(1, Math.min(max, Math.round(n) || 1));
    w.control('lbl_count').setText(String(this.count));
    this._select(w, this.sel, null, true);
  }

  async _select(w, ri, job = null, keepCount = false) {
    const g = this.game;
    this.sel = ri ?? null;
    if (!keepCount) this.count = 1;
    const rec = this.recipe(ri);
    w.control('lbl_count').setText(String(this.count));
    const info = w.control('pan_ItemInfo');
    const set = (id, t) => info.control(id).setText(t);
    if (!rec) {
      for (const id of ['lbl_item_name', 'txt_req_lv', 'txt_get_exp', 'txt_req_money', 'txt_req_time', 'txt_succes_per']) set(id, '');
      setItemIcon(g, info.control('giveItem'), 0);
      for (let k = 1; k <= 10; k++) this._lineCtl(w, k).setVisible(false);
      w.control('btn_make').setEnabled(false);
      return;
    }
    const n = this.count;
    const it = itemInfo(g, rec.item);
    set('lbl_item_name', `${it?.name || rec.name}${rec.count > 1 ? ` x${rec.count}` : ''}`);
    const lvOk = this.level >= (rec.needPoint || 1);
    set('txt_req_lv', String(rec.needPoint || 1));
    info.control('txt_req_lv').setTextColor(lvOk ? 'ffffffff' : 'ffff4040');
    set('txt_get_exp', numText(rec.rewardPoint * n));
    set('txt_req_money', numText(rec.dil * n));
    info.control('txt_req_money').setTextColor(dil(g) >= rec.dil * n ? 'ffffffff' : 'ffff4040');
    set('txt_req_time', timeText(rec.time * n));
    set('txt_succes_per', `${rec.prob}%`);
    const iw = Math.max(1, it?.w || 1) * 32, ih = Math.max(1, it?.h || 1) * 32;
    await setItemIcon(g, info.control('giveItem'), rec.item, rec.count, Math.min(66, iw), Math.min(134, ih));
    // ingredients
    let enough = true;
    for (let k = 1; k <= 10; k++) {
      const row = this._lineCtl(w, k);
      const m = rec.mats[k - 1];
      if (!m) { row.setVisible(false); continue; }
      const have = countItem(g, m[0]), need = m[1] * n;
      if (have < need) enough = false;
      row.setVisible(true);
      row.control(k <= 6 ? 'lbl_line_title' : `lbl_line_title_x${k}`).setText(`${itemInfo(g, m[0])?.name || m[0]} (${numText(have)} / ${numText(need)})`)
        .setTextColor(have >= need ? 'ffffffff' : 'ffff4040');
      setItemIcon(g, row.control(k <= 6 ? 'item_resource' : `item_resource_x${k}`), m[0], 0, 32, 32);
    }
    const tb = w.control('textbox');
    tb.scroll?.setRange(Math.max(0, rec.mats.length - 6), 6);
    this._lineTop = 0; tb.scroll?.setValue(0); this._placeLines(w);
    const busy = job != null;
    w.control('btn_make').setEnabled(!busy && lvOk && enough && dil(g) >= rec.dil * n && this._typeOk(rec));
  }

  _placeLines(w) {
    for (let k = 1; k <= 10; k++) {
      const row = this._lineCtl(w, k);
      row.setRect(3, (k - 1 - this._lineTop) * 40, 280, 40);
    }
  }

  _typeOk(rec) { return rec.type === 11 || rec.type === this.st.type; }

  _tickMain(w, dt) {
    this._acc = (this._acc || 0) + dt;
    if (this._acc < 0.5) return;
    this._acc = 0;
    if (this.tab === 3) this._fillProgressTree(w);
  }

  // =========================================================================================== crafting
  /** Start `count` crafts of recipe ri in a free slot. */
  async make(ri, count = 1) {
    const g = this.game;
    const rec = this.recipe(ri);
    if (!rec) { msgRef(g, 2901, 14, 'NORMAL', 'err'); return false; }
    if (!this.st.type && rec.type !== 11) { msgRef(g, 2901, 149, 'NORMAL', 'err'); return false; }
    if (!this._typeOk(rec)) { msgRef(g, 2901, 2, 'NORMAL', 'err'); return false; }
    if (this.level < (rec.needPoint || 1)) { msgRef(g, 2901, 11, 'NORMAL', 'err'); return false; }
    if (count > (rec.max || 1)) { msgRef(g, 2901, 141, 'NORMAL', 'err'); return false; }
    if (this.st.jobs.length >= this.st.slots) { msgRef(g, 2901, 13, 'NORMAL', 'err'); return false; }
    for (const [it, c] of rec.mats) if (countItem(g, it) < c * count) { msgRef(g, 2901, 9, 'NORMAL', 'err'); return false; }
    if (dil(g) < rec.dil * count) { msgRef(g, 2901, 10, 'NORMAL', 'err'); return false; }
    // pay
    if (rec.dil > 0 && !spendDil(g, rec.dil * count)) { msgRef(g, 2901, 10, 'NORMAL', 'err'); return false; }
    for (const [it, c] of rec.mats) takeItem(g, it, c * count);
    const now = Date.now();
    const total = Math.max(0, rec.time * count) * 1000;
    this.st.jobs.push({ recipe: Number(ri), count, start: now, end: now + total, total });
    msgRef(g, 2901, 7, 'NORMAL', 'sys');
    g.events?.emit?.('life:craft', { phase: 'start', recipe: Number(ri), count });
    g.persist?.();
    if (this.win?.isOpen) { this._select(this.win, ri); this._fillProgressTree(this.win); }
    this._alarmCheck();
    const pw = g.uiwin.window('craftprogress');
    if (pw?.isOpen) this._refreshProgress(pw);
    return true;
  }

  /** Receive the result of job i (when its time is over). */
  async receive(i) {
    const g = this.game;
    const j = this.st.jobs[i];
    if (!j) { msgRef(g, 2901, 18, 'NORMAL', 'err'); return false; }
    if (Date.now() < j.end) { msgRef(g, 2901, 17, 'NORMAL', 'err'); return false; }
    const rec = this.recipe(j.recipe);
    if (!rec) { this.st.jobs.splice(i, 1); return false; }
    let ok = 0;
    for (let k = 0; k < j.count; k++) if (Math.random() * 100 < rec.prob) ok++;
    if (ok > 0 && !canGiveAll(g, [[rec.item, rec.count * ok]])) { msgRef(g, 2901, 140, 'NORMAL', 'err'); return false; }
    const lvBefore = this.level;
    if (ok > 0) giveItem(g, rec.item, rec.count * ok, { source: 'craft' });
    this.st.exp = (this.st.exp || 0) + rec.rewardPoint * ok;
    this.st.jobs.splice(i, 1);
    if (ok > 0) { msgRef(g, 2901, 16, 'NORMAL', 'item'); msgRef(g, 2900, 138, 'NORMAL', 'item'); }
    if (ok < j.count) msgRef(g, 2901, 15, 'NORMAL', 'err');
    if (this.level > lvBefore) msgRef(g, 2901, 143, 'NORMAL', 'exp');
    g.events?.emit?.('life:craft', { phase: 'receive', recipe: j.recipe, count: j.count, success: ok, item: rec.item, type: rec.type });
    g.persist?.();
    this._afterJobChange();
    return true;
  }

  async receiveAll() {
    const now = Date.now();
    let any = false;
    for (let i = this.st.jobs.length - 1; i >= 0; i--) if (this.st.jobs[i].end <= now) { any = true; await this.receive(i); }
    if (!any) msgRef(this.game, 2901, 17, 'NORMAL', 'err');
  }

  /** Cancel job i: ingredients and dil come back (2900:221/222; 2901:142 when under a minute is left). */
  async cancel(i) {
    const g = this.game;
    const j = this.st.jobs[i];
    if (!j) return false;
    const left = (j.end - Date.now()) / 1000;
    if (left <= 0) return this.receive(i);
    if (left < 60) { msgRef(g, 2901, 142, 'NORMAL', 'err'); return false; }
    const rec = this.recipe(j.recipe);
    const equipIngredient = rec?.mats.some(([it]) => (itemInfo(g, it)?.slot));
    const r = await box(g, S(g, equipIngredient ? 223 : 222), { title: S(g, 221), kind: 'yesno' });
    if (r !== 'yes') return false;
    const back = (rec?.mats || []).map(([it, c]) => [it, c * j.count]);
    if (!canGiveAll(g, back)) { msgRef(g, 2901, 140, 'NORMAL', 'err'); return false; }
    for (const [it, c] of back) giveItem(g, it, c, { source: 'craft', silent: true });
    if (rec?.dil) addDil(g, rec.dil * j.count);
    this.st.jobs.splice(i, 1);
    msgRef(g, 2901, 139, 'NORMAL', 'sys');
    g.events?.emit?.('life:craft', { phase: 'cancel', recipe: j.recipe });
    g.persist?.();
    this._afterJobChange();
    return true;
  }

  _afterJobChange() {
    if (this.win?.isOpen) { this._fillProgressTree(this.win); this._refreshLevel(this.win); this._fillTrees(this.win); if (this.sel) this._select(this.win, this.sel); }
    const pw = this.game.uiwin.window('craftprogress');
    if (pw?.isOpen) this._refreshProgress(pw);
    this._alarmCheck();
  }

  // =========================================================================================== progress window
  _createProgress(w) {
    const g = this.game;
    for (let t = 1; t <= 3; t++) w.control(`btn_tab${t}`).onClick(() => { g.uiwin.open('craft').then((m) => this._setTab(m, t)); w.close(); });
    w.control('btn_tab1').setText(this.st.type ? S(g, TYPE_STR[this.st.type]) : S(g, 1));
    for (let s = 1; s <= 3; s++) {
      const pan = w.control(`pan_resultItem${s}`);
      pan.control(`btn_complete_${s}`).onClick(() => { const i = s - 1; const j = this.st.jobs[i]; if (!j) return; if (Date.now() >= j.end) this.receive(i); else this.cancel(i); });
      pan.control(`btn_Catalyst_${s}`).onClick(() => { if (this.st.jobs[s - 1]) g.uiwin.open('craftcatalyst', s - 1); else msgRef(g, 2901, 26, 'NORMAL', 'err'); });
      pan.control('btn_add').onClick(() => this.addSlot());
    }
  }

  _refreshProgress(w, tick = false) {
    const g = this.game;
    if (tick) { this._pacc = (this._pacc || 0) + 1; if (this._pacc % 15) return; }
    w.control('btn_tab3').setChecked(true);
    for (let s = 1; s <= 3; s++) {
      const pan = w.control(`pan_resultItem${s}`);
      const unlocked = s <= this.st.slots;
      const j = this.st.jobs[s - 1];
      const rec = j ? this.recipe(j.recipe) : null;
      pan.control('btn_add').setVisible(!unlocked);
      for (const c of pan.children) if (c.id !== 'btn_add') c.setVisible(unlocked);
      if (!unlocked) continue;
      pan.setImage('none', 'production', 3);
      const set = (id, t) => pan.control(id).setText(t);
      if (!rec) {
        set('lbl_item_name', M(g, 18)); set('txt_req_lv', ''); set('txt_get_exp', ''); set('txt_req_money', ''); set('txt_req_time', ''); set('txt_succes_per', '');
        setItemIcon(g, pan.control('giveitem'), 0);
        pan.control(`btn_complete_${s}`).setVisible(false); pan.control(`btn_Catalyst_${s}`).setVisible(false);
        continue;
      }
      const left = Math.max(0, (j.end - Date.now()) / 1000);
      set('lbl_item_name', itemInfo(g, rec.item)?.name || rec.name);
      set('txt_req_lv', String(rec.needPoint || 1));
      set('txt_get_exp', numText(rec.rewardPoint * j.count));
      set('txt_req_money', String(j.count));
      set('txt_req_time', left > 0 ? timeText(left) : S(g, 109));
      set('txt_succes_per', `${rec.prob}%`);
      if (pan.data.item !== rec.item) { pan.data.item = rec.item; const it = itemInfo(g, rec.item); setItemIcon(g, pan.control('giveitem'), rec.item, rec.count, Math.min(65, (it?.w || 1) * 32), Math.min(132, (it?.h || 1) * 32)); }
      const btn = pan.control(`btn_complete_${s}`);
      btn.setVisible(true).setText(left > 0 ? S(g, 107) : S(g, 109));
      pan.control(`btn_Catalyst_${s}`).setVisible(left > 0);
    }
  }

  async addSlot() {
    const g = this.game;
    if (this.st.slots >= (this.C.slots?.max || 3)) return false;
    const r = await box(g, S(g, 216), { title: S(g, 215), kind: 'yesno' });
    if (r !== 'yes') return false;
    const item = (this.C.workshops || []).find((i) => countItem(g, i) > 0);
    if (!item) { msgRef(g, 2901, 31, 'NORMAL', 'err'); return false; }
    takeItem(g, item, 1);
    this.st.slots = Math.min(this.C.slots?.max || 3, this.st.slots + 1);
    g.persist?.();
    const pw = g.uiwin.window('craftprogress');
    if (pw?.isOpen) this._refreshProgress(pw);
    return true;
  }

  // =========================================================================================== catalyst
  _createCatalyst(w) {
    w.control('btn_ok').onClick(() => this._applyCatalyst(w));
  }
  _catalystItem() { return Object.keys(this.C.catalysts || {}).map(Number).find((i) => countItem(this.game, i) > 0) || null; }
  _openCatalyst(w, slot) {
    const g = this.game;
    w.data.slot = slot;
    const j = this.st.jobs[slot];
    const it = this._catalystItem();
    w.data.item = it;
    setItemIcon(g, w.control('useitem'), it || 0, it ? countItem(g, it) : 0, 32, 32);
    w.control('lbl_count').setText(it ? String(countItem(g, it)) : '0');
    w.control('txt_short_time').setText(it ? timeText(this.C.catalysts[String(it)]) : '');
    w.control('txt_have_time').setText(j ? timeText((j.end - Date.now()) / 1000) : '');
    w.control('btn_ok').setEnabled(!!it && !!j);
    if (!it) msgRef(g, 2901, 32, 'NORMAL', 'err');
  }
  _applyCatalyst(w) {
    const g = this.game;
    const j = this.st.jobs[w.data.slot];
    const it = w.data.item;
    if (!j) { msgRef(g, 2901, 26, 'NORMAL', 'err'); w.close(); return; }
    if (!it || !takeItem(g, it, 1)) { msgRef(g, 2901, 32, 'NORMAL', 'err'); return; }
    j.end = Math.max(Date.now(), j.end - this.C.catalysts[String(it)] * 1000);
    msgRef(g, 2901, 25, 'NORMAL', 'sys');
    g.persist?.();
    w.close();
    this._afterJobChange();
  }

  // =========================================================================================== mastery
  _createMastery(w) {
    for (let k = 1; k <= 3; k++) w.control(`btn_select_${k}`).onClick(() => this.chooseMastery(k));
  }
  _refreshMastery(w) {
    for (let k = 1; k <= 3; k++) w.control(`pan_resultItem${k}`).control('pan_select').setVisible(this.st.type === k);
  }
  async chooseMastery(type) {
    const g = this.game;
    if (this.st.type === type) return false;
    if (this.st.jobs.length) { msgRef(g, 2901, 6, 'NORMAL', 'err'); return false; }
    const n = this.st.type ? (this.st.resets || 0) + 1 : 0;       // the first choice is not a change
    const cost = this.st.type ? (this.C.resetCost?.[Math.min(n, this.C.resetCost.length) - 1] ?? 10000000) : 0;
    const text = fmt(S(g, 210 + type), this.st.type ? n : 1) + (cost > 0 ? `\n${numText(cost)} DIL` : '');
    const r = await box(g, text, { title: S(g, 210), kind: 'yesno' });
    if (r !== 'yes') return false;
    if (cost > 0 && !spendDil(g, cost)) { msgRef(g, 2901, 4, 'NORMAL', 'err'); return false; }
    if (this.st.type) { this.st.resets = n; this.st.exp = 0; }        // "Existing mastery will be reset upon mastery change"
    this.st.type = type;
    msgRef(g, 2901, 1, 'NORMAL', 'sys');
    g.persist?.();
    const mw = g.uiwin.window('craftmastery');
    if (mw?.isOpen) this._refreshMastery(mw);
    if (this.win?.isOpen) this._openMain(this.win);
    g.events?.emit?.('life:craft', { phase: 'mastery', type });
    return true;
  }

  // =========================================================================================== alarm
  _alarmCheck() {
    const g = this.game;
    const has = this.st.jobs.length > 0;
    if (has && !g.uiwin.isOpen('craftalarm')) g.uiwin.open('craftalarm');
    else if (!has && g.uiwin.isOpen('craftalarm')) g.uiwin.close('craftalarm');
  }

  update(dt) {
    this._t = (this._t || 0) + dt;
    if (this._t < 1) return;
    this._t = 0;
    const ready = this.st.jobs.some((j) => j.end <= Date.now());
    if (ready !== this._ready) {
      this._ready = ready;
      const a = this.game.uiwin.window('craftalarm');
      a?.control('btn_alarm').setBlink(ready);
    }
    if (!this._alarmChecked && this.game.world) { this._alarmChecked = true; this._alarmCheck(); }
    // ui_product_alarm and ui_dungeonalarmwnd share rect 130 60; the dungeon button keeps it, the craft button takes
    // the next free slot of the row (alarm-slots.js). Attendance / Reward Event yield to it (excluded here).
    const aw = this.game.uiwin.window('craftalarm');
    if (aw?.isOpen) placeAlarmButton(this.game.uiwin, aw, aw.control('btn_alarm'), ['attendance_alarm', 'connectreward_alarm']);
    const mw = this.game.uiwin.window('craftmastery');
    if (mw?.isOpen) this._refreshMastery(mw);
  }
}
