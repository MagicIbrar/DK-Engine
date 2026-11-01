// Boxes, packages, random / keyed / summon boxes, pet eggs and the level-up box chains (gamedata/boxes.json,
// docs/formats/boxes.md §7). game.boxes = { ready, isBox(i), info(i), open(instOrIndex) -> Promise<bool>, showInfo(i) }.
// The items system calls game.boxes.open(inst) when a box item is used (right click / double click / quick slot).
// Windows (original scripts):
//   select / all   game2/ui_new_randomboxwnd.txt   "Select Item": 14 checkbox rows + scroll, lbl_info = messagebox 81:83 / 81:85
//   package        game2/msgbox/ui_msgbox_ok.txt   "Open Package" (80:65) + the binding warning (81:65)
//   egg            game2/msgbox/ui_hatch.txt       hatch confirmation
//   keyed chest    game2/randombox/ui_cashrandomboxwnd_renew.txt   box + key -> result, number of units, Max / Init, Exchange
//   probability    game2/notice/ui_randomboxinfownd.txt  "Probability Info" (Probability Item / Item Name / QTY / Probability)
import {RuneBoxWarning} from './rune-warning.js';
import { loadBoxes } from './data.js';
import { spawnMonster } from './engine.js';
import { plainText } from './markup.js';
import { borrowPreviewIcon } from '../../ui/preview-cache.js';
import { globalNotice } from '../../ui/uiwin/global-windows.js';

const N = (cate, code) => ({ group: 'NORMAL', cate, code });
const SYS = (cate, code) => ({ group: 'SYSTEM', cate, code });
const num = v => Number(v) || 0;
const ROWS = 14;

export class BoxSystem {
  constructor(sys) {
    this.sys = sys;
    this.game = sys.game;
    this.B = null;
    this.ready = loadBoxes().then(b => { this.B = b; this.sys.db.B = b; return b; }).catch(err => { console.warn('[boxes] boxes.json unavailable', err); this.B = { boxes: {} }; return this.B; });
    // Prepare actual reward models during entry, before boxes can be used. The
    // transaction itself must never wait for rendering or choose a reward locally.
    (this.game._interfaceIconTasks ||= []).push(this.ready.then(() => this._warmCarriedBoxVisuals()));
    this.busy = false;
    this.runeWarning = new RuneBoxWarning(this.game);
    this._warmOff = ['inventory', 'systems'].map(event => this.game.events?.on?.(event, () => {
      if (this.B && !this._disposed) void this._warmCarriedBoxVisuals();
    })).filter(Boolean);
  }
  get db() { return this.sys.db; }
  get inv() { return this.sys.inv; }
  get W() { return this.game.uiwin; }
  str(ref, fb = '') { return this.W?.strings?.get(ref) ?? fb; }
  say(text, kind = 'sys') { if (text) this.sys.engine.say(plainText(String(text)), kind); }

  isBox(i) { const b = this.B?.boxes?.[i]; return !!b && !b.orphan; }
  info(i) { return this.B?.boxes?.[i] || null; }

  // Native candidate art only; no roll, reward grant or authoritative action waits for GPU.
  _warmCarriedBoxVisuals() {
    if (this._disposed || !this.game.items?.icons) return Promise.resolve([]);
    const carried = this.game.items?.bag?.list || this.game.save?.inventory || [];
    const ids = [...new Set(carried.map(entry => Number(entry.itemIndex)))];
    return Promise.all(ids.map(id => this._warmBoxVisuals(this.info(id))));
  }
  _rewardVisualIds(b) {
    if (!b || b.orphan || b.k === 'summon') return [];
    const ids = [], cls = Number(this.game.save?.classIndex) || 0;
    // Class hints affect recommendation order, not reward eligibility: packages
    // and selections can still grant another class's item through the server.
    const entries = this.entries(b).sort((a, z) =>
      Number(Array.isArray(a.ec) && !a.ec.includes(cls)) - Number(Array.isArray(z.ec) && !z.ec.includes(cls)));
    for (const entry of entries) {
      if (b.k === 'itemset') {
        for (const row of this.B?.itemSets?.[entry.item]?.e || []) if (this._valid(row[0])) ids.push(Number(row[0]));
      } else ids.push(entry.item);
    }
    if (b.bonus && this._valid(b.bonus[0])) ids.push(Number(b.bonus[0]));
    return [...new Set(ids)];
  }
  _warmBoxVisuals(b) {
    const icons = this.game.items?.icons;
    if (this._disposed || !icons || !b || b.k === 'summon') return Promise.resolve([]);
    const grid = this.game.uiwin?.window?.('inventory')?.control?.('slotbag');
    const cell = [grid?.cw || 37, grid?.ch || 36];
    const ids = new Set(this._rewardVisualIds(b));
    // One further package layer covers the next immediately-openable box without
    // traversing every future level-up chain or the whole item catalogue.
    for (const id of [...ids]) {
      const next = this.info(id), level = Number(this.game.save?.level) || 1;
      if (next && level >= (Number(next.lv) || 1) && (!next.maxLv || level <= next.maxLv)) {
        for (const child of this._rewardVisualIds(next)) ids.add(child);
      }
    }
    return Promise.all([...ids].map(id => {
      const def = this.game.items?.def?.(id);
      return icons.get(id, Math.max(1, def?.w || 1) * cell[0], Math.max(1, def?.h || 1) * cell[1])
        .then(icon => this._decodeRewardVisual(icon)).catch(() => null);
    }));
  }
  _decodeRewardVisual(icon) {
    if (this._disposed || !icon?.url) return Promise.resolve(null);
    if (typeof Image === 'undefined') return Promise.resolve(icon);
    const decoded = this._decodedRewards ||= new WeakMap();
    if (!decoded.has(icon)) {
      const pending = this._rewardDecodes ||= new Set();
      const entry = { image: null, release: borrowPreviewIcon(icon), cancelled: false };
      pending.add(entry);
      const cancelled = new Promise(resolve => { entry.cancel = () => resolve(null); });
      const decode = Promise.resolve().then(async () => {
        if (this._disposed || entry.cancelled || !icon.url) return null;
        const image = entry.image = new Image();
        image.src = icon.url;
        if (typeof image.decode === 'function') await image.decode();
        return !this._disposed && !entry.cancelled && icon.url ? icon : null;
      }).catch(() => { decoded.delete(icon); return null; });
      entry.ready = Promise.race([decode, cancelled]).finally(() => {
        entry.release(); pending.delete(entry); entry.image = null;
      });
      decoded.set(icon, entry);
    }
    return decoded.get(icon).ready;
  }
  dispose() {
    this._disposed = true;
    for (const entry of this._rewardDecodes || []) {
      entry.cancelled = true;
      try { if (entry.image) entry.image.src = ''; } catch { /* Cancel even if the image adapter throws. */ }
      entry.image = null; entry.release(); entry.cancel();
    }
    this._rewardDecodes?.clear();
    for (const off of this._warmOff || []) off();
    this._warmOff = []; this._decodedRewards = null;
  }
  // ------------------------------------------------------------------ public: use a box
  /** Use a box item (an inventory entry / instance, or an item index). Resolves true when something was opened. */
  async open(instOrIndex) {
    await this.ready;
    const inst = typeof instOrIndex === 'object' ? instOrIndex : null;
    const idx = Number(inst ? inst.itemIndex ?? inst.index : instOrIndex);
    const b = this.info(idx);
    if (!b || this.busy) return false;
    const g = this.game;
    const lv = num(g.save.level) || 1, cls = num(g.save.classIndex);
    await this.W?.strings?.need?.([N(1002, 65), N(1002, 66), N(1002, 67), N(1002, 68), N(1002, 40), SYS(101, 214), N(80, 65), N(81, 65), N(81, 83), N(81, 85), N(100, 79), N(100, 15), N(81, 86)]).catch(() => {});
    if (lv < num(b.lv) || (b.maxLv && lv > num(b.maxLv)) || (Array.isArray(b.job) && !b.job.includes(cls))) { this.say(this.str(SYS(101, 214), 'Cannot use due to unmatched rank and level.'), 'err'); return false; }
    const take = Math.max(1, num(b.take) || 1);
    if (this.inv.count(idx) < take) { this.say(this.str(N(1002, 65), 'Not enough boxes. Cannot open more.'), 'err'); return false; }
    if (b.k === 'keyed' && !this._keyOwned(b)) { this.say(this.str(N(1002, 66), 'Not enough keys. Cannot open more.'), 'err'); return false; }
    if (b.k === 'summon' && Number(g.world?.info?.row?.PeaceZone ?? g.mapRow?.(g.world?.info?.index)?.PeaceZone) === 1) { this.say(this._safeZoneText(), 'err'); return false; }
    void this._warmBoxVisuals(b);
    this.busy = true;
    try {
      switch (b.k) {
        case 'select': return await this._select(b, idx, inst, false);
        case 'all': return await this._select(b, idx, inst, true);
        case 'package': return await this._package(b, idx, inst);
        case 'keyed': return await this._keyed(b, idx, inst);
        case 'egg': return await this._egg(b, idx, inst);
        default: return await this._openNow(b, idx, inst);   // random, itemset, summon
      }
    } finally { this.busy = false; }
  }

  // ------------------------------------------------------------------ resolution
  _valid(item) {
    const it = this.game.items;
    if (it?.def) return !!it.def(item);
    return true;
  }
  /** Entries usable in this client: [{item, count, w, i, ec}] (missing items dropped, count 0 -> 1). */
  entries(b) {
    const miss = new Set((b.missing || []).map(Number));
    return (b.e || []).map((e, i) => ({ item: Number(e[0]), count: Math.max(1, num(e[1]) || 1), w: num(e[2]), i, ec: b.ec?.[i] ?? null }))
      .filter(e => (b.k === 'itemset' || b.k === 'summon') ? true : !miss.has(e.item) && this._valid(e.item));
  }
  /** One weighted roll over entries (renormalised when entries were dropped; the empty remainder is kept). */
  roll(b, list = this.entries(b), rng = Math.random) {
    const allSum = (b.e || []).reduce((a, e) => a + num(e[2]), 0);
    const sum = list.reduce((a, e) => a + e.w, 0);
    if (!(sum > 0)) return list.length ? list[Math.floor(rng() * list.length)] : null;
    let total = num(b.total) || allSum;
    if (allSum > 0 && sum < allSum) total = total * (sum / allSum);
    if (b.k === 'keyed' || b.k === 'egg' || b.k === 'itemset' || b.k === 'summon') total = Math.min(total, sum) || sum;   // paid rolls always yield
    const r = rng() * Math.max(total, sum);
    let acc = 0;
    for (const e of list) { acc += e.w; if (acc > r) return e; }
    return null;
  }
  /** Roll an item set (itemSets[set].e: [item, ratio, ...]) by ratio. */
  rollSet(setIndex, rng = Math.random) {
    const s = this.B?.itemSets?.[setIndex];
    const list = (s?.e || []).filter(e => this._valid(e[0]));
    const sum = list.reduce((a, e) => a + num(e[1]), 0);
    if (!list.length) return null;
    let r = rng() * (sum || list.length), acc = 0;
    for (const e of list) { acc += sum ? num(e[1]) : 1; if (acc > r) return { item: Number(e[0]), count: Math.max(1, num(e[3]) || 1) }; }
    return { item: Number(list[0][0]), count: 1 };
  }

  _openNow(b, idx, inst) {
    if(this.game.save.authority==='server') return this._serverOpen(b,idx,inst);
    const g = this.game;
    const got = [];
    if (b.k === 'random') {
      for (let k = 0; k < Math.max(1, num(b.give) || 1); k++) { const e = this.roll(b); if (e) got.push({ item: e.item, count: e.count }); }
    } else if (b.k === 'itemset') {
      const e = this.roll(b);
      const r = e ? this.rollSet(e.item) : null;
      if (r) got.push(r);
      if (b.bonus) got.push({ item: Number(b.bonus[0]), count: Math.max(1, num(b.bonus[1]) || 1) });
    } else if (b.k === 'summon') {
      const e = this.roll(b);
      if (!e) return false;
      if (!this._consumeBox(b, idx, inst)) return false;
      const p = g.player;
      const f = { x: -Math.sin(p.yaw || 0), z: -Math.cos(p.yaw || 0) };
      for (let k = 0; k < e.count; k++) spawnMonster(g, e.item, p.x + f.x * 2.5 + (k ? Math.random() * 2 - 1 : 0), p.z + f.z * 2.5 + (k ? Math.random() * 2 - 1 : 0));
      this._opened(b, idx, [], { summon: e.item });
      return true;
    } else {
      for (const e of this.entries(b)) got.push({ item: e.item, count: e.count });
    }
    return this._give(b, idx, inst, got);
  }

  /** Space check, give, consume, log. */
  async _give(b, idx, inst, got, { key = null } = {}) {
    if(this.game.save.authority==='server') {
      const choices=b.k==='select' ? got.map(e => Number.isInteger(e.i) ? e.i : this.entries(b).find(row => row.item===e.item && row.count===e.count)?.i) : undefined;
      return this._serverOpen(b,idx,inst,choices);
    }
    if (!await this._confirmRuneRewards(got)) return false;
    if (!this.inv.canFit(got)) { this.say(this.str(N(1002, 67), 'Your inventory is full. Cannot open more.'), 'err'); return false; }
    if (!this._consumeBox(b, idx, inst)) return false;
    if (key != null) this.inv.remove(key, 1, { reason: 'boxKey' });
    for (const x of got) this.inv.add(x.item, x.count, { reason: 'box' });
    this._opened(b, idx, got);
    return true;
  }
  _consumeBox(b, idx, inst) {
    const take = Math.max(1, num(b.take) || 1);
    if (inst && typeof inst === 'object' && (inst.count ?? 1) >= take) return this.inv.consumeEntry(inst, take);
    return this.inv.remove(idx, take, { reason: 'box' });
  }
  _opened(b, idx, got, extra = {}) {
    const fmt = this.str(N(1002, 68), '<color=0xFFE08C>%s</color> %dx obtained.');
    for (const x of got) this.say(fmt.replace('%s', this.db.itemName(x.item)).replace('%d', x.count), 'item');
    // rare results are broadcast by the server: solo, the announcement goes to the system chat
    if (b.msg || got.some(x => x.notify === 2)) {
      const an = this.str(N(1002, 40), '[message] %s has opened %s and obtained %s.');
      for (const x of got) if (b.msg || x.notify === 2) this.say(an.replace('%s', this.game.save?.name || '').replace('%s', this.db.itemName(idx)).replace('%s', this.db.itemName(x.item)));
    }
    if (b.fx) this.game.events?.emit?.('effect', { owner: this.game.player, scene: b.fx });
    this.game.audio?.itemUse?.({ itemIndex: idx });
    this.game.events?.emit?.('box:open', { item: idx, got, ...extra });
  }
  _keyOwned(b) { return (b.keys || []).find(k => this.inv.count(k) > 0) ?? null; }
  _safeZoneText() {
    const d = this.B?.descs?.[567] || '';
    const s = String(d).split(/(?<=\.)\s*/).find(x => /safety zone/i.test(x));
    return s || 'You cannot summon the monster in the Safety Zone.';
  }
  async _confirmRuneRewards(rewards) {
    try { return await (this.runeWarning??=new RuneBoxWarning(this.game)).confirm(rewards); }
    catch (error) { console.warn('[boxes] rune duplicate check unavailable',error);this.say('Rune duplicate check is unavailable. Try opening the box again.','err');return false; }
  }
  async _serverOpen(b,idx,inst,choices,onResult = null) {
    const item=inst || this.game.items?.bag?.list?.find(e => e.itemIndex===Number(idx));
    if(!item) return false;
    const candidates=b.k==='summon'?[]:this.entries(b).filter(e=>!choices||choices.includes(e.i)).flatMap(e=>b.k==='itemset'?(this.B?.itemSets?.[e.item]?.e||[]).map(row=>({item:Number(row[0])})):[e]);
    if(b.bonus)candidates.push({item:Number(b.bonus[0])});
    if (!await this._confirmRuneRewards(candidates)) return false;
    const intent={uid:item.uid};if(choices)intent.choices=choices;
    const sequence = Number(this.game.network?.sequence) || 0;
    const response=await this.game.network?.action('box',intent);
    if (response?.result?.ok && onResult) {
      const actor = this.game.network?.self?.id;
      const event = (response.events || response.state?.events || []).filter(event => event.type === 'box'
        && event.actorId === actor && Number(event.itemIndex) === Number(idx) && Number(event.sequence) > sequence).at(-1);
      onResult(event?.got || []);
    }
    return !!response?.result?.ok;
  }

  // ------------------------------------------------------------------ package / egg confirmations
  async _package(b, idx, inst) {
    // a cash package (items.json `cash`): Global msgbox/cashitem/ui_warninguseitem (100:95 "Open Package", 171:35 the usable
    // period / binding caution) with its own texts; other packages keep the 80:65 / 81:65 question
    if (this.game.items?.db?.def?.(idx)?.cash) {
      const answer = await this.W.msgbox(null, { kind: 'yesno', script: 'game2/msgbox/cashitem/ui_warninguseitem.txt', scripted: true });
      if (answer !== 'yes') return false;
      return this._openNow(b, idx, inst);
    }
    const r = await this.sys.msgbox(this.str(N(81, 65), ''), { title: this.str(N(80, 65), 'Open Package'), kind: 'yesno' });
    if (r !== 'yes') return false;
    return this._openNow(b, idx, inst);
  }
  /** A hatched pet item in the bag, the equipment or a stash (mount data isPet). */
  _ownsHatchedPet() {
    const pets = this.game.mounts?.system?.data, items = this.game.items;
    if (!pets?.isPet || !items) return false;
    return [items.bag?.list, Object.values(items.equip?.data?.items || {}), items.stash?.list, items.shared?.list]
      .filter(Array.isArray).some(list => list.some(i => i && pets.isPet(i.itemIndex)));
  }
  async _egg(b, idx, inst) {
    // Global msgbox/ui_alreadyhatch (100:79 "Hatch", 330:3 "You already own a pet.", 330:4 "If you possess a hatched pet in the
    // stash or inventory, you cannot hatch another pet."); the host refuses as well (server/world/quests.mjs ownsHatchedPet)
    if (this._ownsHatchedPet()) { await globalNotice(this.game, 'game2:msgbox:ui_alreadyhatch'); return false; }
    const r = await this.W.msgbox('', { script: 'game2/msgbox/ui_hatch.txt', title: this.str(N(100, 79), ''), kind: 'yesno' });
    if (r !== 'yes') return false;
    const e = this.roll(b);
    if (!e) return false;
    return this._give(b, idx, inst, [{ item: e.item, count: e.count }]);
  }

  // ------------------------------------------------------------------ select window
  registerWindows() {
    const self = this;
    const W = this.W;
    W.registerWindow('randombox', {
      script: 'game2/ui_new_randomboxwnd.txt',
      create(win) { self._selCreate(win); },
      onClose(win, result) { const d = self._sel; self._sel = null; d?.resolve?.(result === 'ok' ? d.chosen() : null); },
    });
    W.registerWindow('randombox_renew', {
      script: 'game2/randombox/ui_cashrandomboxwnd_renew.txt',
      create(win) { self._keyCreate(win); },
      onOpen(win, arg) { self._keyOpen(arg); },
      onClose() { self._keyStop = true; },
    });
    W.registerWindow('randomboxinfownd', {
      script: 'game2/notice/ui_randomboxinfownd.txt',
      modal: true,
      create(win) { self._infoCreate(win); },
      onOpen(win, i) { self._infoFill(Number(i)); },
    });
  }

  _selCreate(win) {
    this.selWin = win;
    // the panels are drawn in script order; the rows and header sit on top of pan_center
    win.control('btn_ok').onClick(() => { if (this._sel?.valid()) win.close('ok'); });
    win.control('btn_cancel').onClick(() => win.close('cancel'));
    const wheel = (e, d) => { const s = win.control('body_scroll'); s.setValue(s.getValue() + d, false); };
    for (let r = 0; r < ROWS; r++) {
      const c = win.control(`check_item_${r}`);
      c.on('change', (on) => this._selToggle(r, on));
      c.el.style.zIndex = '120';
      // the rows sit above pan_body: the wheel must scroll the list wherever the cursor is over it
      c.on('wheel', wheel);
    }
    win.control('body_scroll').on('change', v => { if (this._sel) { this._sel.top = v; this._selRender(); } });
    win.control('pan_body').on('wheel', wheel);
  }
  async _select(b, idx, inst, all) {
    const list = this.entries(b);
    void this._warmBoxVisuals(b);
    if (!list.length) return false;
    const give = all ? list.length : Math.max(1, Math.min(list.length, num(b.give) || 1));
    const cls = num(this.game.save.classIndex);
    // Native checkboxes start unchecked (ui_new_randomboxwnd.txt) and the prompt asks the player to select N items; no
    // choice is made for them. Only an "all" list (every entry is granted) is shown fully ticked.
    const picked = new Set();
    if (all) list.forEach((e, i) => picked.add(i));
    const done = new Promise(resolve => {
      this._sel = {
        b, idx, list, give, all, picked, top: 0, cls, resolve,
        valid: () => picked.size === give,
        chosen: () => [...picked].map(i => ({ item: list[i].item, count: list[i].count, i: list[i].i })),
      };
    });
    const win = await this.W.open('randombox');
    win.control('lbl_title').setText(all ? this.str(N(81, 86), 'Item List').replace(/<center>/g, '').trim() : this.str(N(100, 15), 'Select Item'));
    const info = all ? this.str(N(81, 85), '') : this.str(N(81, 83), '').replace('%d', give);
    this.sys.setRich(win.control('lbl_info'), info);
    const scroll = win.control('body_scroll');
    scroll.setRange(Math.max(0, list.length - ROWS), ROWS);
    scroll.setValue(0);
    this._selRender();
    const chosen = await done;
    if (!chosen) return false;
    return this._give(b, idx, inst, chosen);
  }
  _selRender() {
    const s = this._sel, win = this.selWin;
    if (!s || !win) return;
    for (let r = 0; r < ROWS; r++) {
      const c = win.control(`check_item_${r}`);
      const i = s.top + r;
      const e = s.list[i];
      if (!e) { c.hide(); continue; }
      c.show();
      c.setChecked(s.picked.has(i));
      c.setEnabled(!s.all);
      const name = this.db.itemName(e.item);
      c.setText(e.count > 1 ? `${name} x${e.count}` : name);
      // The row's own title colours stay in charge (white, green on hover: ui_new_randomboxwnd.txt); an explicit
      // colour here would pin the text and silence the native hover state.
      c.setTooltip(() => this._tooltip(e.item));
      c.data.entry = i;
    }
    win.control('btn_ok').setEnabled(s.valid());
  }
  _selToggle(r, on) {
    const s = this._sel;
    if (!s || s.all) return;
    const i = s.top + r;
    if (!s.list[i]) return;
    if (on) {
      if (s.give === 1) s.picked.clear();
      if (s.picked.size >= s.give) { this.selWin.control(`check_item_${r}`).setChecked(false); return; }
      s.picked.add(i);
    } else s.picked.delete(i);
    this._selRender();
  }
  _tooltip(item) {
    const it = this.game.items;
    try { const t = it?.tooltip?.(item); if (t) return t; } catch { /* optional */ }
    return this.db.itemName(item);
  }

  // ------------------------------------------------------------------ keyed chest window
  _keyCreate(win) {
    this.keyWin = win;
    const edit = win.control('edit_count');
    const clamp = () => { const k = this._key; if (!k) return; const v = Math.max(1, Math.min(this._keyMax(), Math.floor(Number(edit.getValue?.()) || 1))); edit.setValue?.(String(v)); };
    edit.on('change', () => clamp());
    win.control('btn_minus_count').onClick(() => { edit.setValue(String(Math.max(1, (Number(edit.getValue()) || 1) - 1))); });
    win.control('btn_plus_count').onClick(() => { edit.setValue(String(Math.min(this._keyMax(), (Number(edit.getValue()) || 1) + 1))); });
    win.control('btn_max_count').onClick(() => edit.setValue(String(this._keyMax())));
    win.control('btn_init_count').onClick(() => edit.setValue('1'));
    win.control('btn_open').onClick(() => this._keyRun());
    win.control('btn_open_stop').onClick(() => { this._keyStop = true; });
    win.control('btn_next_open').onClick(() => { this._keyNext?.(); });
    win.control('item_cashrandombox').onClick(() => this.showInfo(this._key?.idx));
  }
  _keyMax() {
    const k = this._key;
    if (!k) return 1;
    const boxes = Math.floor(this.inv.count(k.idx) / Math.max(1, num(k.b.take) || 1));
    const keys = (k.b.keys || []).reduce((a, id) => a + this.inv.count(id), 0);
    return Math.max(1, Math.min(boxes, keys));
  }
  async _keyed(b, idx, inst) {
    await this.W.open('randombox_renew', { b, idx, inst });
    return false;   // the window consumes boxes and keys itself
  }
  async _keyOpen(arg) {
    const { b, idx } = arg || {};
    this._key = { b, idx };
    void this._warmBoxVisuals(b);
    this._keyStop = false;
    const win = this.keyWin;
    win.control('lbl_title').setText(this.db.itemName(idx));
    win.control('pan_wait_setting').hide();
    win.control('pan_open_setting').show();
    win.control('edit_count').setValue?.('1');
    const key = this._keyOwned(b) ?? b.keys?.[0];
    this._keyIcon('item_cashrandombox', idx);
    this._keyIcon('item_key', key);
    win.control('item_result').setIcon(null);
    this._keyCounts();
    const list = this.entries(b);
    const total = num(b.total) || list.reduce((a, e) => a + e.w, 0) || 1;
    this.sys.fillTextBox(win.control('textbox'), list.map(e => `${this.db.itemName(e.item)}${e.count > 1 ? ` x${e.count}` : ''}  <color=b7b7b7>${((e.w / total) * 100).toFixed(e.w / total < 0.001 ? 4 : 2)}%</color>`).join('\n'));
  }
  _keyCounts() {
    const k = this._key, win = this.keyWin;
    if (!k || !win) return;
    win.control('lbl_use_cashbox_count').setText(String(this.inv.count(k.idx)));
    win.control('lbl_use_key_count').setText(String((k.b.keys || []).reduce((a, id) => a + this.inv.count(id), 0)));
  }
  async _keyIcon(ctrlId, item) {
    const c = this.keyWin?.control(ctrlId);
    if (!c || item == null) return;
    c.setTooltip(() => this._tooltip(item));
    const token = c._boxIconToken = {};
    const it = this.game.items;
    const cached = it?.icons?.now?.(item, 33, 33) || it?.icons?.cached?.(item);
    c.setIcon(cached || null);
    try { const ic = await it?.icon?.(item, 33, 33); if (ic?.url && c._boxIconToken === token) c.setIcon(ic); } catch { /* no icon */ }
  }
  async _keyRun() {
    const k = this._key, win = this.keyWin;
    if (!k) return;
    let n = Math.max(1, Math.min(this._keyMax(), Math.floor(Number(win.control('edit_count').getValue?.()) || 1)));
    this._keyStop = false;
    if (n > 1) { win.control('pan_open_setting').hide(); win.control('pan_wait_setting').show(); }
    while (n-- > 0 && !this._keyStop) {
      const key = this._keyOwned(k.b);
      if (key == null) { this.say(this.str(N(1002, 66), 'Not enough keys. Cannot open more.'), 'err'); break; }
      if (this.inv.count(k.idx) < Math.max(1, num(k.b.take) || 1)) { this.say(this.str(N(1002, 65), 'Not enough boxes. Cannot open more.'), 'err'); break; }
      let e;
      if (this.game.save.authority === 'server') {
        // Show the accepted command's canonical grant, never a second local roll.
        if (!await this._serverOpen(k.b, k.idx, null, undefined, got => { e = got[0] || null; })) break;
      } else {
        if (k.b.noTable) { const l = this.entries(k.b); e = l[0] || null; if (!e && k.b.placeholder) e = { item: Number(k.b.placeholder[0][0]), count: 1 }; }
        else e = this.roll(k.b);
        if (!e) break;
        const notify = Array.isArray(k.b.notify) ? k.b.notify[e.i] : 0;
        if (!await this._give(k.b, k.idx, null, [{ item: e.item, count: e.count, notify }], { key })) break;
      }
      if (e) this._keyIcon('item_result', e.item);
      else win.control('item_result').setIcon(null);
      this._keyCounts();
      if (n > 0) await new Promise(res => setTimeout(res, 700));
    }
    win.control('pan_wait_setting').hide();
    win.control('pan_open_setting').show();
    this.game.items?.changed?.('use', { itemIndex: k.idx });
  }

  // ------------------------------------------------------------------ probability window
  /** "Probability Info" of a box (D-Shop / keyed chest item list). */
  showInfo(i) { if (this.info(i)) return this.W.open('randomboxinfownd', i); return null; }
  _infoCreate(win) {
    this.infoWin = win;
    this.infoRows = [];
    win.control('list_scroll').on('change', v => { this._infoTop = v; this._infoRender(); });
    win.control('pan_content_bg').on('wheel', (e, d) => { const s = win.control('list_scroll'); s.setValue(s.getValue() + d, false); });
  }
  _infoFill(i) {
    const b = this.info(i);
    this._info = b ? { i, b, list: b.k === 'summon' ? (b.e || []).map((e, k) => ({ item: Number(e[0]), count: Math.max(1, num(e[1])), w: num(e[2]), i: k, monster: true })) : this.entries(b) } : null;
    this._infoTop = 0;
    const vis = 26;
    this.infoWin.control('list_scroll').setRange(Math.max(0, (this._info?.list.length || 0) - vis), vis);
    this.infoWin.control('list_scroll').setValue(0);
    this._infoRender();
  }
  _infoRender() {
    const win = this.infoWin, I = this._info;
    for (const r of this.infoRows) r.remove();
    this.infoRows = [];
    if (!I) return;
    const tpl = win.find('pan_variable');
    const host = win.find('pan_content');
    if (!tpl || !host) return;
    const total = num(I.b.total) || I.list.reduce((a, e) => a + e.w, 0) || 1;
    const H = 20, vis = 26;
    I.list.slice(this._infoTop, this._infoTop + vis).forEach((e, k) => {
      const row = tpl.cloneAs(`_${k}`, { x: 0, y: k * H, parent: host, visible: true });
      row.setRect(0, k * H, 810, H);
      const name = e.monster ? this.db.monsterName(e.item) : this.db.itemName(e.item);
      row.control(`lbl_item_${k}`)?.setText(k === 0 && this._infoTop === 0 ? this.db.itemName(I.i) : '');
      row.control(`lbl_resultitem_${k}`)?.setText(name);
      row.control(`lbl_count_${k}`)?.setText(String(e.count));
      const pct = I.b.k === 'select' || I.b.k === 'all' || I.b.k === 'package' ? 100 : (e.w / total) * 100;
      row.control(`lbl_percent_${k}`)?.setText(`${pct.toFixed(pct < 0.01 ? 4 : 2)}%`);
      row.control(`pan_hline_${k}`)?.hide();
      this.infoRows.push(row);
    });
  }

  // ------------------------------------------------------------------ starter grant & level-up notices
  /** New character: the New Character Gift Pack + the level-up chain root (boxes.json starter.onCreate), once. */
  async grantStarter() {
    if(this.game.save.authority==='server') return !!this.game.save.quests?.flags?.starterGiven;
    await this.ready;
    const st = this.sys.engine.st;
    if (st.flags.starterGiven) return;
    const list = (this.B?.starter?.onCreate || []).map(x => ({ item: Number(x.item), count: Math.max(1, num(x.count) || 1) }));
    if (!list.length || !this.inv.canFit(list)) return;
    for (const x of list) this.inv.add(x.item, x.count, { reason: 'starter' });
    st.flags.starterGiven = Date.now();
  }
  /** On level-up: name the carried boxes that open at this level (the next level-up stage). */
  levelUp(level) {
    const it = this.game.items;
    const carried = it?.bag?.list || this.game.save?.inventory || [];
    const seen = new Set();
    for (const e of carried) {
      const idx = Number(e?.itemIndex);
      if (seen.has(idx)) continue;
      seen.add(idx);
      const b = this.info(idx);
      if (b && num(b.lv) === Number(level)) this.say(`[Lv.${level}] ${this.db.itemName(idx)}`, 'item');
    }
  }
}
