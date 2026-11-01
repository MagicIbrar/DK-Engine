// Shared machinery of the item NPC windows (upgrade, sockets, options, brand, crest, accessory upgrade, seal,
// helmet rank, socket stone machine, talisman): material slots that REGISTER bag items the way the original does
// (the item stays in its bag cell, dimmed and locked, until the window uses it or it is taken out again), the
// processing bar (game2/itemupgrade/ui_upgradeprogress.txt), the confirmation box (game2/msgbox/ui_socket.txt),
// system sounds, NPC-distance auto close and the inventory opened beside the window.
import { slotIcon, fmt } from './common.js';
import { buildTooltip } from '../tooltip.js';

/** sound.json system[id] (98 Upgrade_Progress, 100 upgrade_fail.wav, 101 upgrade.wav, 102 socket progress...). */
export function sysSound(sys, id) {
  const a = sys.game.audio;
  const list = a?.S?.system?.[String(id)]?.sfx;
  if (list) { try { a.playAll(list, { volume: 0.9 }); } catch { /* audio optional */ } }
}

/** Client string with the "[Message] " prefix removed (the chat line adds its own). */
export function clean(t) { return String(t || '').replace(/^\s*\[message\]\s*/i, '').trim(); }

/**
 * Put a client string with markup on a label: '\' = line break, <center> / <font=N> / </font> dropped (the label's own
 * alignment and font apply), <color=RRGGBB> runs kept through setRichText.
 */
export function rich(ctrl, text) {
  if (!ctrl) return;
  const t = String(text ?? '').replace(/\\\\?/g, '\n').replace(/<center>|<\/center>|<font=\d+>|<\/font>/gi, '');
  if (/<color=/i.test(t) && ctrl.setRichText) ctrl.setRichText(t); else ctrl.setText?.(t.replace(/<\/?color[^>]*>/gi, ''));
}

/**
 * Open the bag and lay the pair out as the original does: the NPC / storage window left of the centre, the bag right
 * of it (both stay movable afterwards).
 */
export function placeWithBag(sys, win) {
  const g = sys.game;
  const place = () => {
    const inv = g.uiwin.window('inventory');
    if (!inv || !win.isOpen) return;
    const W = g.uiwin.screen.w, H = g.uiwin.screen.h;
    const total = win.box.w + 4 + inv.box.w;
    const x0 = Math.max(0, Math.round((W - total) / 2));
    const y = Math.max(0, Math.min(H - win.box.h, Math.round((H - Math.max(win.box.h, inv.box.h)) / 2)));
    win.setPosition(x0, y);
    inv.setPosition(Math.min(W - inv.box.w, x0 + win.box.w + 4), Math.max(0, Math.min(H - inv.box.h, y)));
  };
  if (!g.uiwin.isOpen('inventory')) return g.uiwin.open('inventory').then(place);
  place();
  return Promise.resolve();
}

/** Registered (reserved) bag items: uid -> owner window name. The bag dims them and refuses to move them. */
export function reservedSet(sys) { return (sys.reserved ||= new Map()); }

// Bag placement may change while a prompt is open; item contents and quantity
// determine the reviewed cost, risk and materials and must remain identical.
function reviewedItem(inst) {
  return inst ? JSON.stringify(Object.fromEntries(Object.entries(inst).filter(([key]) => !['page', 'x', 'y'].includes(key)).sort(([a], [b]) => a.localeCompare(b)))) : null;
}

export class MatSlot {
  /**
   * @param {Crafting} kit
   * @param ctrl  item control
   * @param opts  {accept(inst, def) -> true | [cate, code] | string, onChange(slot), count: bool|fn, view: bool (display only),
   *               click(slot), empty: {sprite|url} icon when empty, tooltip(inst)}
   */
  constructor(kit, ctrl, opts = {}) {
    this.kit = kit; this.ctrl = ctrl; this.opts = opts;
    this.inst = null;
    this.shown = null;          // display-only item index (view slots)
    const sys = kit.sys;
    ctrl.setTooltip?.(() => {
      const it = this.inst || (this.shown != null ? { itemIndex: this.shown, count: 1, grade: 'normal' } : null);
      if (!it) return typeof opts.emptyTip === 'function' ? opts.emptyTip() : opts.emptyTip || null;
      return opts.tooltip ? opts.tooltip(it) : buildTooltip(sys, it, { where: 'craft' });
    });
    if (!opts.view) {
      ctrl.acceptDrop?.({
        referenceSource:'bag',referenceLabel:'This upgrade or crafting service',
        accept: (d) => d?.kind === 'item' && d.from === 'bag',
        drop: (d) => this.put(d.inst),
      });
      ctrl.makeDraggable?.(() => (this.inst ? {
        data: { kind: 'craftslot', slot: this },
        icon: sys.icons.now(this.inst.itemIndex, 32, 32) || null, size: [32, 32],
        onDropOutside: () => { this.clear(true); return true; },
      } : null), { clickPick: false });
      ctrl.onRightClick?.(() => { if (this.inst) this.clear(true); });
    }
    if (opts.click) ctrl.onClick?.(() => opts.click(this));
    ctrl.onDoubleClick?.(() => { if (opts.dblclick) opts.dblclick(this); });
  }
  get def() { return this.inst ? this.kit.sys.db.def(this.inst.itemIndex) : null; }
  /** Register a bag instance here. Returns true when accepted. */
  put(inst, { silent = false } = {}) {
    const sys = this.kit.sys;
    if (this.kit.busy) return false;
    const live = inst && sys.bag.list.find(item => item.uid === inst.uid);
    const now = typeof sys.game.now === 'function' ? sys.game.now() : Date.now();
    if (!live || live.itemIndex !== inst.itemIndex || (live.count ?? 1) < 1 || live.expiresAt && live.expiresAt <= now) { if (!silent) sys.msg(1001, 118); return false; }
    inst = live;
    const R = reservedSet(sys);
    if (R.has(inst.uid) && this.inst?.uid !== inst.uid) {
      // already registered in another slot of this window: move it here
      const other = this.kit.slots.find(s => s.inst?.uid === inst.uid);
      if (other && other !== this) other.clear(false); else if (!other) { if (!silent) sys.msg(311, 26); return false; }
    }
    const def = sys.db.def(inst.itemIndex);
    const ok = this.opts.accept ? this.opts.accept(inst, def, this) : true;
    if (ok !== true) { if (!silent && ok) (Array.isArray(ok) ? sys.msg(ok[0], ok[1]) : sys.msg(null, null, ok)); return false; }
    if (this.inst && this.inst !== inst) R.delete(this.inst.uid);
    this.inst = inst;
    R.set(inst.uid, this.kit.name);
    this.draw();
    sys.game.audio?.ui?.('buttonCommon');
    this.kit.bagChanged();
    this.opts.onChange?.(this);
    return true;
  }
  clear(notify = true) {
    if (notify && this.kit.busy) return;
    const sys = this.kit.sys;
    if (this.inst) reservedSet(sys).delete(this.inst.uid);
    this.inst = null;
    this.draw();
    this.kit.bagChanged();
    if (notify) this.opts.onChange?.(this);
  }
  /** Display an item index without registering anything (examples, lists). */
  show(itemIndex, count = null) {
    this.shown = itemIndex ?? null;
    const sys = this.kit.sys;
    slotIcon(sys, this.ctrl, itemIndex != null ? { itemIndex, count: count ?? 1, grade: 'normal' } : null);
    if (count != null) this.ctrl.setCount?.(count > 1 ? fmt(count) : '');
  }
  draw() {
    const sys = this.kit.sys;
    slotIcon(sys, this.ctrl, this.inst);
    if (this.inst && this.opts.count !== false) {
      const n = typeof this.opts.count === 'function' ? this.opts.count(this) : (sys.db.stackSize(this.def) > 1 ? this.inst.count : null);
      this.ctrl.setCount?.(n != null && n !== 1 ? fmt(n) : '');
    }
  }
  /** Still valid? (the item may have been used / sold / dropped meanwhile) */
  validate() {
    const sys = this.kit.sys;
    if (this.inst) {
      const live = sys.bag.list.find(item => item.uid === this.inst.uid);
      const now = typeof sys.game.now === 'function' ? sys.game.now() : Date.now();
      if (!live || live.itemIndex !== this.inst.itemIndex || (live.count ?? 1) < 1 || live.expiresAt && live.expiresAt <= now) { this.clear(false); return false; }
      this.inst = live;
      if (this.opts.accept && this.opts.accept(live, this.def, this) !== true) { this.clear(false); return false; }
      this.draw();
    }
    return true;
  }
}

export class Crafting {
  constructor(sys, win, name) {
    this.sys = sys; this.win = win; this.name = name;
    this.slots = [];
    this.npc = null;
    this.busy = false;
    // the client strings of these windows use '\' as a line break (350:139 "Normal Gear\Normal Accessory") and
    // <center> / <font=N> / <color=...> markup (1001:271 "<color=fdb602><center>Protector")
    this.fixMarkup();
  }
  /** Client markup in the script texts (runs again on open: text2 strings may arrive after create). */
  fixMarkup() {
    try {
      for (const c of this.win.controls(() => true) || []) {
        const t = c.getText?.();
        if (typeof t === 'string' && /\\|<center>|<font=|<color=/i.test(t)) rich(c, t);
      }
    } catch { /* optional cosmetic pass */ }
  }
  slot(idOrCtrl, opts) {
    const ctrl = typeof idOrCtrl === 'string' ? this.win.control(idOrCtrl) : idOrCtrl;
    const s = new MatSlot(this, ctrl, opts);
    this.slots.push(s);
    return s;
  }
  releaseAll() { for (const s of this.slots) if (s.inst) s.clear(false); this.bagChanged(); }
  validate() { let ok = true; for (const s of this.slots) if (!s.validate()) ok = false; return ok; }
  bagChanged() { this.sys.inv?.renderBag?.(); }
  /** Count of an item index in the bag, not counting instances registered elsewhere. */
  have(itemIndex) { return this.sys.bag.count(itemIndex); }
  /** First bag instance of any of these item indices (smallest stack first). */
  findInBag(indices, pred = null) {
    const set = new Set([].concat(indices).map(Number));
    const R = reservedSet(this.sys);
    return this.sys.bag.list.filter(i => set.has(i.itemIndex) && !R.has(i.uid) && (!pred || pred(i)))
      .sort((a, b) => (a.count || 1) - (b.count || 1))[0] || null;
  }
  /** Consume n of a registered stack (or the instance). */
  consume(inst, n = 1) {
    if (!inst) return;
    const sys = this.sys;
    if ((inst.count || 1) <= n) reservedSet(sys).delete(inst.uid);
    sys.bag.take(inst, n);
  }

  /** Open hooks: remember the NPC, open the bag beside the window, route bag right-clicks here. */
  opened(win, arg, offer) {
    const g = this.sys.game;
    const npc = arg?.npc || arg;
    this.npc = npc && npc.kind === 'npc' ? npc : null;
    this.sys.craftOffer = offer ? (inst) => (win.isOpen ? offer(inst) : false) : null;
    this.sys.craftWin = this.name;
    this.fixMarkup();
    placeWithBag(this.sys, win);
  }
  closed() {
    this.releaseAll();
    if (this.sys.craftWin === this.name) { this.sys.craftOffer = null; this.sys.craftWin = null; }
    this.npc = null;
  }
  /** Walked away from the NPC (10 m, like the stash) -> close. */
  tick(win) {
    const p = this.sys.game.player, n = this.npc;
    if (n && p && Math.hypot(n.x - p.x, n.z - p.z) > 10) win.close('away');
  }

  /** Keep an online confirmation bound to its reviewed slots and session until the response. */
  async review(text, title, send, valid = () => true) {
    if (this.busy || !this.validate()) return null;
    const g = this.sys.game, network = g.network, lease = network?.token, character = g.save?.id;
    const selection = this.slots.map(slot => reviewedItem(slot.inst));
    const sessionCurrent = () => g.save?.authority === 'server' && g.save?.id === character && g.network === network &&
      network?.token === lease && !network?.disposed && network?.ready !== false && network?.active !== false && typeof network?.action === 'function';
    this.busy = true;
    try {
      if (!sessionCurrent()) { this.sys.msg(1001, 118); return null; }
      if (!(await this.confirm(text, title))) return null;
      if (!sessionCurrent() || this.win.isOpen === false || !this.validate() ||
        this.slots.some((slot, i) => reviewedItem(slot.inst) !== selection[i]) || !valid()) {
        this.sys.msg(1001, 118); return null;
      }
      return await send(network);
    } finally { this.busy = false; }
  }

  /** The processing bar (seconds), resolves when full. */
  async progress(seconds = 1.5, soundId = 98) {
    const g = this.sys.game;
    this.busy = true;
    sysSound(this.sys, soundId);
    let win = null;
    try {
      win = await g.uiwin.create('game2/itemupgrade/ui_upgradeprogress.txt', { modal: true, escClose: false, remember: false, disposeOnClose: true, band: 'system' });
      g.uiwin.openWindow ? g.uiwin.openWindow(win) : win.open();
      win.center?.();
      const bar = win.control('processbar');
      const t0 = performance.now();
      await new Promise((resolve) => {
        const step = () => {
          const f = Math.min(1, (performance.now() - t0) / (seconds * 1000));
          bar.setGauge?.(f);
          if (f >= 1) resolve(); else requestAnimationFrame(step);
        };
        step();
      });
    } catch (err) { console.warn('[items] progress window', err); await new Promise(r => setTimeout(r, seconds * 1000)); }
    finally { try { win?.close('done'); } catch { /* closed */ } this.busy = false; }
  }

  /** Yes/No confirmation in the original ui_socket.txt box (short text) or the message box (long text). */
  async confirm(text, title = null) {
    const g = this.sys.game;
    const t = String(text || '');
    if (t.split('\n').length > 1 || t.length > 40) return (await g.uiwin.msgbox(t, { kind: 'yesno', title })) === 'yes';
    let win = null;
    try { win = await g.uiwin.create('game2/msgbox/ui_socket.txt', { modal: true, escClose: true, remember: false, disposeOnClose: true, band: 'system' }); } catch { win = null; }
    if (!win) return (await g.uiwin.msgbox(t, { kind: 'yesno', title })) === 'yes';
    if (title) win.control('lbl_title').setText(title);
    win.control('pan_notifylabel').setText(t);
    return new Promise((resolve) => {
      let done = false;
      const fin = (v) => { if (done) return; done = true; resolve(v); try { win.close('done'); } catch { /* closed */ } };
      win.control('btn_yes').onClick(() => fin(true));
      win.control('btn_no').onClick(() => fin(false));
      win.control('btn_exit').onClick(() => fin(false));
      win.once('close', () => fin(false));
      g.uiwin.openWindow ? g.uiwin.openWindow(win) : win.open();
      win.center?.();
    });
  }
}

/** Walk the +N chain of an item index to the index of level `lv` (prev / next links). */
export function indexAtLevel(db, itemIndex, lv) {
  let d = db.def(itemIndex);
  let guard = 0;
  while (d && (d.itemLv || 0) > lv && d.prev && guard++ < 40) d = db.def(d.prev);
  while (d && (d.itemLv || 0) < lv && d.next && guard++ < 80) d = db.def(d.next);
  return d?.index ?? itemIndex;
}

/** Replace an instance's item index in place (upgrade / level down / grade change): options, sockets... stay. */
export function morph(sys, inst, newIndex) {
  const def = sys.db.def(newIndex);
  if (!def) return false;
  inst.itemIndex = Number(newIndex);
  inst.name = def.name;
  return true;
}

/** Deduct n of an item index from the bag (unregistered stacks first, then registered). */
export function spendItems(sys, itemIndex, n) {
  const R = reservedSet(sys);
  const list = sys.bag.list.filter(i => i.itemIndex === Number(itemIndex)).sort((a, b) => (R.has(a.uid) - R.has(b.uid)) || ((a.count || 1) - (b.count || 1)));
  let left = n;
  for (const it of list) {
    if (left <= 0) break;
    const k = Math.min(left, it.count || 1);
    if (k >= (it.count || 1)) R.delete(it.uid);
    sys.bag.take(it, k);
    left -= k;
  }
  return n - left;
}
