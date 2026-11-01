// Items system (src/systems/items): the original inventory / equipment / stash / cash inventory with real item
// instances from gamedata/items*.json (docs/formats/items.md), weapon holding per class and weapon type, item use,
// the item NPC windows (upgrade, sockets, brand, crest, options, accessories, helmet rank, amplify, disassemble...)
// and the loot integration. Public API = game.items.
import { ItemDB } from './db.js';
import { Container, createItem, cloneItem, newUid } from './model.js';
import { Equipment, emptyEquip, S, clonePresetTo } from './equip.js';
import { computeItemStats, applyPost } from './stats.js';
import { Look, styledClass } from './look.js';
import { Icons } from './icons.js';
import { borrowPreviewIcon } from '../../ui/preview-cache.js';
import {AuthoredEquipmentEffects} from './authored-effects.js';
import {installWeaponTargetSounds} from './weapon-target-sound.js';
import { ItemUse } from './use.js';
import { buildTooltip } from './tooltip.js';
import { installGround, dropToGround } from './ground.js';
import { registerInventory } from './ui/inventory.js';
import { askSplit, askDropDil, confirmDiscard } from './ui/dialogs.js';
import { statProviders, statPostHooks } from '../../game/progression.js';
import { strings } from '../../ui/uiwin/strings.js';
import { atlas } from '../../ui/atlas.js';
import { warmIcons } from '../../ui/icon-prewarm.js';
import { disposePreviewEncoder } from './preview-export.js';
import {applyCursorOperation,cursorState} from './cursor-custody.js';
import {restoreCursor} from './ui/common.js';
import { confirmItemUse } from './use-confirm.js';

const ACCOUNT_KEY = 'dekaron-solo:account:v1';
const BAG = { pages: 7, cols: 10, rows: 5 };
const STASH = { pages: 4, cols: 10, rows: 10 };
const COSTUME_BAG = { pages: 1, cols: 6, rows: 8 };
const CASH = { pages: 1, cols: 8, rows: 6 };
const MAX_DIL = 10_000_000_000;

let SYS = null;

class ItemsSystem {
  constructor(game) {
    this.game = game;
    this.db = null;
    this.windows = { open: (n, a) => game.uiwin?.open(n, a), close: (n) => game.uiwin?.close(n), toggle: (n, a) => game.uiwin?.toggle(n, a) };
    this.itemStats = null;
    this._dirty = false;
    this.ready = null;
  }

  // ------------------------------------------------------------------------------------ setup
  async init() {
    const g = this.game;
    this.db = await ItemDB.load();
    this.db.tables();                         // start loading the upgrade/socket/... tables in the background
    // animated weapons need items-actions.json (skeleton + loop clip); the look is rebuilt once it is in
    this.db.actions().then(a => { if (!a) return; this.db._actionsData = a; if (this.equip) { this._recompute(); if (this.game.player) this.look.apply(); } });
    strings.need([{ cate: 40 }, { cate: 260 }, { cate: 190 }, { cate: 2000 }, { cate: 25 }, { cate: 20 }]).catch(() => {});
    this.icons = new Icons(this);
    this.authoredEffects = new AuthoredEquipmentEffects(g,this.db);
    this.targetSounds = installWeaponTargetSounds(g, this.db);   // native item_shape Targeteffect -> modeleffect 38/1 attack sounds
    this.uses = new ItemUse(this);
    this.equip = new Equipment(this);
    this.look = new Look(this);
    this._migrate();
    const s = g.save;
    this.bag = new Container(s.inventory, this.db, { ...BAG, unlocked: () => s.bagsUnlocked || 2, name: 'bag' });
    this.stash = new Container(s.storage, this.db, { ...STASH, unlocked: () => s.stashUnlocked || 2, name: 'stash' });
    this.shared = new Container(this.account().shared, this.db, { pages: 1, cols: 10, rows: 10, unlocked: () => (this.account().sharedStash ? 1 : 0) || 1, name: 'shared' });
    this.costumeBag = new Container(s.costumeBag, this.db, { ...COSTUME_BAG, name: 'costume', accept: (d) => d.slot === 'costume' });
    for (const c of [this.bag, this.stash, this.costumeBag]) c.normalize();
    this.shared.normalize();
    this.shared.onChange = () => this.saveAccount();
    // stats hooks (progression.js deriveStats)
    statProviders.push((save) => (save === g.save && this.itemStats ? this.itemStats.statuses : null));
    statPostHooks.push((out, save) => { if (save === g.save && this.itemStats) applyPost(out, this.itemStats); });
    this._recompute();
    // the character is built after install: give it the stance of its weapon right away
    g.classDef = styledClass(g.classDef, this.db, this.equip.style());
    installGround(this);
    this.inv = registerInventory(this);
    await this._registerMore();
    this._wireServices();
    g.events.on('map', () => { this._expire(); });
    g.events.on('levelup', () => this.changed('level', null, { look: false }));
    g.events.on('stats', () => { this._recompute(); });
    g.events.on('life:title', () => { this._recompute(); });
    (g._interfaceIconTasks ||= []).push(this._warm()); // overlap map loading, finish before play
    restoreCursor(this);
    return this;
  }

  /**
   * Warm-up during the loading screen (fb-items, user note 11:55): the inventory window is built (script, controls,
   * layout), the spinning icon sheets of the visible bag page and worn equipment plus stills of all carried pages are rendered, and the tooltip
   * art / strings / defs are touched, so the bag opens with its models and shows tooltips the moment it is hovered.
   */
  async _warm() {
    const g = this.game;
    try {
      for (const i of [66, 67, 305]) atlas.sprite('etc_01', i)?.catch?.(() => {});
      const win = await g.uiwin?.get?.('inventory');
      if (win && !win.isOpen) { win.place(); this.inv?.render?.(); }
      for (const inst of this.bag.items(this.inv?.state?.page || 0)) { try { buildTooltip(this, inst, { where: 'bag' }); } catch { /* warm only */ } }
      for (const { inst } of this.equip.entries()) { try { buildTooltip(this, inst, { where: 'equip' }); } catch { /* warm only */ } }
      await this.icons.queue; // Keep selected-page and worn rotations first.
      // Other owned bag pages must have real stills ready before play, too.
      // The finite carried list excludes storage and the unowned item catalogue.
      const grid = win?.control?.('slotbag'), cw = grid?.cw || 37, ch = grid?.ch || 36;
      const carried = [...new Map(this.bag.list.map(inst => [inst.itemIndex, inst])).values()];
      await warmIcons(carried, async inst => {
        const [w, h] = this.bag.size(inst);
        const icon = await this.icons.get(inst.itemIndex, w * cw, h * ch);
        if (!icon?.url || typeof Image === 'undefined') return;
        const release = borrowPreviewIcon(icon);
        try { const image = new Image(); image.src = icon.url;
          if (typeof image.decode === 'function') await image.decode().catch(() => {});
        } finally { release(); }
      }, { concurrency: 2 });
      await this.icons.queue;
    } catch (err) { console.warn('[items] warm-up', err); }
  }

  /** Save fields of the items system (old saves and new characters). */
  _migrate() {
    const s = this.game.save;
    s.inventory = Array.isArray(s.inventory) ? s.inventory : [];
    s.storage = Array.isArray(s.storage) ? s.storage : [];
    s.costumeBag = Array.isArray(s.costumeBag) ? s.costumeBag : [];
    s.cashInv = Array.isArray(s.cashInv) ? s.cashInv : [];
    s.bagsUnlocked = s.bagsUnlocked || 2;
    s.stashUnlocked = s.stashUnlocked || 2;
    s.dil = Number(s.dil) || 0;
    s.stashDil = Number(s.stashDil) || 0;
    // older loot entries: {uid, itemIndex, name, count, stack, grade}
    s.inventory = s.inventory.filter(e => e && this.db.def(e.itemIndex)).map(e => {
      const o = { ...e, uid: e.uid || newUid(), count: Math.max(1, Number(e.count) || 1), grade: e.grade || 'normal' };
      delete o.stack;
      return o;
    });
    if (!s.equip || !Array.isArray(s.equip.presets)) {
      s.equip = emptyEquip();
      const w = this.starterWeapon();
      if (w) {
        const inst = createItem(this.db, w, {});
        if (inst) { s.equip.items[inst.uid] = inst; s.equip.presets[0][S.weapon] = inst.uid; }
      }
    }
  }

  /** The class's starter weapon item (classes.json weapon.itemIndex, or the same rule on items.json for the classes
   *  whose weapons exist only in item.dat: lowest ReqLv >= 1, rank 0, the class's weapon code). */
  starterWeapon() {
    const cd = this.game.classDef?._base || this.game.classDef;
    const ci = Number(this.game.save.classIndex) || 0;
    const idx = Number(cd?.weapon?.itemIndex);
    const ok = (d) => d && Number(d.type) === 4 && ((Number(d.classMask) >>> ci) & 1);
    if (idx && ok(this.db.def(idx))) return idx;
    const code = Number(cd?.weapon?.code);
    let best = null;
    for (const k in this.db.items) {
      const it = this.db.items[k];
      if (it.type !== 4 || it.code !== code) continue;
      const d = this.db.def(k);
      if (!ok(d) || d.rank !== 0 || !(d.reqLv >= 1) || d.period || /\+|\(|\[|test|event/i.test(d.name || '') || /[^\x00-\x7f]/.test(d.name || '')) continue;
      if (!best || d.reqLv < best.reqLv || (d.reqLv === best.reqLv && d.index < best.index)) best = d;
    }
    return best?.index ?? null;
  }

  account() {
    if (!this._acct) {
      try { this._acct = JSON.parse(localStorage.getItem(ACCOUNT_KEY) || '{}'); } catch { this._acct = {}; }
      this._acct.shared = Array.isArray(this._acct.shared) ? this._acct.shared : [];
      this._acct.sharedDil = Number(this._acct.sharedDil) || 0;
    }
    return this._acct;
  }
  saveAccount() { try { localStorage.setItem(ACCOUNT_KEY, JSON.stringify(this._acct || {})); } catch { /* private mode */ } }

  async _registerMore() {
    const mods = [
      ['./ui/costumebag.js', 'registerCostumeBag'],
      ['./ui/storage.js', 'registerStorage'],
      ['./ui/cashinv.js', 'registerCashInventory'],
      ['./ui/preset.js', 'registerPresetPreview'],
      ['./ui/upgrade.js', 'registerUpgrade'],
      ['./ui/socket.js', 'registerSockets'],
      ['./ui/enchant.js', 'registerEnchant'],
      ['./ui/exchange.js', 'registerExchange'],
    ];
    // 2.2.1: the eight modules are fetched together (each import used to wait for the previous one's round trip); they
    // still register in this order, one after the other, exactly as before.
    const loaded = mods.map(([file]) => import(file).catch(err => err));
    for (const [i, [file, fn]] of mods.entries()) {
      try {
        const m = await loaded[i];
        if (m instanceof Error) throw m;
        if (typeof m[fn] === 'function') await m[fn](this);
      } catch (err) {
        if (!/Failed to fetch|Cannot find module|error loading dynamically imported module/i.test(String(err?.message))) console.error(`[items] ${file}`, err);
      }
    }
  }

  /** NPC menu entries (quests system's game.npcServices; jobtype names from npcs.json). */
  _wireServices() {
    const g = this.game;
    const reg = () => {
      const svc = g.npcServices;
      if (!svc?.register || this._svcDone) return !!this._svcDone;
      this._svcDone = true;
      const open = (name) => (npc) => { this.npc = npc; g.uiwin.open(name, npc); return true; };
      // (wing upgrade / wing shape / costume cycle windows belong to the mounts system, material exchange to shops)
      const map = {
        STORAGE: 'storage', ITEMUPGRADE: 'upgrade', ITEMADDSOCKET: 'addsocket', ITEM_REMOVE_STONE: 'removestone',
        ITEMOPTIONUPGRADE: 'optionupgrade', ITEMINCUSE: 'incuse', MUNZANG_MAN: 'munzang', ACCESSORYUPGRADE: 'accupgrade',
        HELMET_RANK_CHANGE: 'helmetrank', ITEM_CHANGE: 'itemchange', TALISMAN_EFFECT_TRANSFORM: 'talisman',
        ITEM_SOCKETSTONE_CRUSHER: 'stonegamble', ITEM_SOCKETSTONE_PRODUCE: 'stonegamble', DYNAMIC_OPTION: 'optionupgrade',
      };
      for (const [role, win] of Object.entries(map)) {
        if (g.uiwin.has(win)) svc.register(role, (npc, info) => { this.npc = npc; g.uiwin.open(win, { npc, ...(info || {}) }); return true; });
      }
      svc.register('REPAIR', () => { g.uiwin.msgbox(this.str(40, 38)?.replace(/\[Message\]\s*/, '') || 'Your equipment does not need repairs.'); return 'keep'; });
      return true;
    };
    if (!reg()) {
      g.events.on('systems', reg);
      g.events.on('npc:open', reg);
      setTimeout(reg, 2000);
    }
  }

  /** Item sound (sound.json item.{drop|pick|equip|get|use}[quality or item index]). */
  sound(kind, def, at = null) {
    const a = this.game.audio;
    const T = a?.S?.item?.[kind];
    if (!T || !def) return;
    const list = T[String(def.index)] || T[String(def.quality)] || (kind === 'pick' || kind === 'get' ? T['0'] : null);
    if (list) { try { a.playOne(list, at ? { at } : {}); } catch { /* audio optional */ } }
  }

  // ------------------------------------------------------------------------------------ strings / messages
  str(cate, code) { return strings.get({ group: 'NORMAL', cate, code }); }
  /** HUD message from a client string (cate, code) or a text. */
  msg(cate, code, text = null) {
    let t = text;
    if (t == null && cate != null) {
      t = this.str(cate, code);
      if (t == null) { strings.resolve({ group: 'NORMAL', cate, code }).then(v => v && this.msg(null, null, v)); return; }
    }
    if (!t) return;
    t = String(t).replace(/<[^>]+>/g, '');
    const now = this.game.time || 0;
    if (t === this._lastMsg && now - (this._msgAt ?? -9) < 1) return;
    this._lastMsg = t; this._msgAt = now;
    try { this.game.hud?.log?.(t, 'err'); } catch { /* optional */ }
  }

  // ------------------------------------------------------------------------------------ state changes
  _recompute() {
    const g = this.game;
    this.itemStats = computeItemStats(this);
    g.save.equipment = this.equip.view(this.itemStats);
    if (g.player) g.refreshPlayerStats?.(false);
  }
  /** Something changed: recompute stats / look, notify windows, persist soon. */
  changed(reason, detail = null, { look = true } = {}) {
    const g = this.game;
    const equipish = /equip|weapontab|costume|preset|level|upgrade|socket|brand|crest|expire/.test(reason);
    if (equipish) {
      this._recompute();
      if (look && g.player) {
        g.classDef = styledClass(g.classDef, this.db, this.equip.style());
        this.look.apply();
      }
      g.events.emit('equip', { reason, ...(detail || {}) });
    }
    g.events.emit('inventory', { reason, ...(detail || {}) });
    this._dirty = true;
  }

  // ------------------------------------------------------------------------------------ public API
  def(i) { return this.db.def(i); }
  name(i) { return this.db.name(i); }
  create(itemIndex, opts = {}) { return createItem(this.db, itemIndex, opts); }
  get dil() { return Number(this.game.save.dil) || 0; }
  set dil(v) { this.game.save.dil = Math.max(0, Math.min(MAX_DIL, Math.floor(Number(v) || 0))); this.game.events.emit('dil', { total: this.game.save.dil }); }
  addDil(n) { const before = this.dil; this.dil = before + Number(n || 0); this.game.events.emit('dil', { amount: this.dil - before, total: this.dil }); return this.dil - before; }
  spendDil(n) { n = Math.floor(Number(n) || 0); if (n < 0 || this.dil < n) return false; this.dil = this.dil - n; return true; }

  /**
   * Add an item: add(inst) or add(itemIndex, count, {grade, roll, bound, opts}). Leftovers that do not fit are
   * dropped at the player's feet when opts.dropLeft (the original "dropped to the ground" rule), else refused.
   * Returns {ok, placed, left}.
   */
  add(instOrIndex, count = null, opts = {}) {
    if (typeof count === 'object' && count) { opts = count; count = null; }
    if (typeof instOrIndex !== 'object' && (count || 1) > 1 && this.db.stackSize(this.db.def(instOrIndex)) <= 1) {
      // several non-stackable pieces: one instance each
      const all = { ok: true, placed: [], left: 0 };
      for (let k = 0; k < count; k++) {
        const r = this.add(instOrIndex, 1, opts);
        all.placed.push(...r.placed); all.left += r.left; if (!r.ok) all.ok = false;
      }
      return all;
    }
    const inst = typeof instOrIndex === 'object' ? instOrIndex : this.create(instOrIndex, { count: count || 1, ...opts });
    if (!inst) return { ok: false, placed: [], left: 0 };
    const def = this.db.def(inst.itemIndex);
    if (opts.to === 'cash') {
      // D-Shop / VIP purchases wait in the cash inventory (900:6) until received
      Object.assign(inst, { boughtAt: Date.now(), purchaser: opts.purchaser || this.game.save.name });
      delete inst.page; delete inst.x; delete inst.y;
      this.game.save.cashInv.push(inst);
      this.changed('cash', { item: inst });
      if (!opts.silent) this.msg(900, 6);
      return { ok: true, placed: [inst], left: 0 };
    }
    const target = this.bag;
    const r = target.add(inst, { page: opts.page, noStack:opts.noStack===true });
    if (r.left > 0 && opts.dropLeft) { dropToGround(this, { kind: 'item', itemIndex: inst.itemIndex, name: def?.name, count: r.left, inst: { ...inst, count: r.left } }); this.msg(null, null, `${def?.name}${this.str(40, 101) || ' dropped to the ground.'}`); }
    else if (r.left > 0 && !opts.silent) this.msg(40, 77);
    if (r.placed.length) {
      this.changed('add', { item: inst });
      this.game.events.emit('item:add', { itemIndex: inst.itemIndex, count: (count || inst.count || 1) - r.left, source: opts.source || null });
    }
    return r;
  }
  canAdd(itemIndex, count = 1) { return this.bag.canAdd(itemIndex, count); }
  /** Can every [itemIndex, count] of a list fit at once? */
  canAddAll(list, opts = {}) {
    // simulate on a copy of the bag
    const copy = new Container(JSON.parse(JSON.stringify(this.bag.list)), this.db, { ...BAG, unlocked: () => this.bag.unlocked });
    for (const [i, c] of list) {
      const single = this.db.stackSize(this.db.def(i)) <= 1;
      for (let k = 0; k < (single ? Math.max(1, c || 1) : 1); k++) {
        const t = this.create(i, { count: single ? 1 : c });
        if (t && !copy.add(t,{noStack:opts.noStack===true}).ok) return false;
      }
    }
    return true;
  }
  count(itemIndex) { return this.bag.count(itemIndex); }
  has(itemIndex, n = 1) { return this.count(itemIndex) >= n; }
  /** Remove n of an item index from the bag. Returns true when all were there. */
  remove(itemIndex, n = 1) {
    if (this.count(itemIndex) < n) return false;
    this.bag.removeIndex(itemIndex, n);
    this.changed('remove', { itemIndex });
    return true;
  }
  /** Remove n of an instance wherever it sits (bag, stash, costume bag, cash). */
  removeInst(inst, n = null) {
    for (const c of [this.bag, this.stash, this.shared, this.costumeBag]) {
      if (c.list.includes(inst)) { const out = c.take(inst, n); this.changed('remove', { item: inst }); return out; }
    }
    const cl = this.game.save.cashInv, k = cl.indexOf(inst);
    if (k >= 0) { cl.splice(k, 1); this.changed('cash'); return inst; }
    return null;
  }
  consume(inst, n = 1) { return this.removeInst(inst, n); }
  /** Where an instance is: 'bag' | 'stash' | 'shared' | 'costume' | 'cash' | 'equip' | null. */
  where(inst) {
    for (const [k, c] of [['bag', this.bag], ['stash', this.stash], ['shared', this.shared], ['costume', this.costumeBag]]) if (c.list.includes(inst)) return k;
    if (this.game.save.cashInv.includes(inst)) return 'cash';
    return this.equip.isEquipped(inst?.uid) ? 'equip' : null;
  }
  findInst(uid) {
    for (const c of [this.bag, this.stash, this.shared, this.costumeBag]) { const f = c.byUid(uid); if (f) return f; }
    return this.game.save.cashInv.find(i => i.uid === uid) || this.equip.data.items[uid] || null;
  }
  containerOf(from) { return { bag: this.bag, stash: this.stash, shared: this.shared, costume: this.costumeBag }[from] || null; }

  // ------------------------------------------------------------------------------------ cash inventory
  cashList() { return this.game.save.cashInv; }
  /** Receive a cash inventory entry into the bag (900:7). */
  receiveCash(inst, { at = null, quiet = false } = {}) {
    const cl = this.game.save.cashInv;
    const k = cl.indexOf(inst);
    if (k < 0) return false;
    const it = { ...inst }; delete it.boughtAt; delete it.purchaser;
    if (at) {
      const [w, h] = this.bag.size(it);
      if (!this.bag.fits(at.page, at.x, at.y, w, h)) return false;
      Object.assign(it, at); this.bag.list.push(it);
    } else {
      if (!this.bag.canAdd(it)) { this.msg(40, 77); return false; }
      this.bag.add(it);
    }
    cl.splice(k, 1);
    if (!quiet) this.msg(900, 7);
    this.changed('cash', { item: it });
    this.game.events.emit('item:add', { itemIndex: it.itemIndex, count: it.count || 1, source: 'cash' });
    return true;
  }

  /** Move a dragged instance from its container into another container at (page, x, y). */
  transfer(d, target, page, x, y) {
    if (d.from === 'cash') {
      if (target !== this.bag) return false;
      return this.receiveCash(d.inst, { at: { page, x, y } });
    }
    const src = this.containerOf(d.from);
    if (!src || !src.list.includes(d.inst)) return false;
    const def = this.db.def(d.itemIndex);
    if (!target.accept(def)) return false;
    const [w, h] = target.size(d.inst);
    const occ = target.inside(x, y, w, h) ? target.occupants(page, x, y, w, h) : null;
    if (!occ || occ.length > 1) return false;
    if (occ.length === 1 && !(occ[0].itemIndex === d.inst.itemIndex)) return false;
    const inst = src.take(d.inst);
    const r = target.placeAt(inst, page, x, y);
    if (!r) { src.add(inst); return false; }
    if (r === 'partial') src.add(inst);
    this.changed('move');
    return true;
  }
  /** Unequip into a container at a spot (costume bag, bag). */
  unequipTo(target, slot, presetIdx, at) {
    if (!this._equipmentTransactionActive) return this._equipmentAtomic(() => this.unequipTo(target, slot, presetIdx, at), [], [target]);
    if (target === this.bag) return this.unequip(slot, presetIdx, at);
    const E = this.equip, inst = E.get(slot, presetIdx);
    if (!inst || E.data.locked || !target.accept(this.db.def(inst.itemIndex))) return false;
    const [w, h] = target.size(inst);
    const spot = at && target.fits(at.page, at.x, at.y, w, h) ? at : target.findSpot(w, h);
    if (!spot) return false;
    const r = E.remove(slot, presetIdx);
    if (r?.inst) { Object.assign(r.inst, spot); target.list.push(r.inst); }
    for (const x of r?.extra || []) if (!this.bag.add(x, { noStack: true }).ok) { this.msg(40, 77); return false; }
    this.changed('unequip', { slot, inst });
    return true;
  }

  tooltip(instOrIndex, ctx) { return buildTooltip(this, instOrIndex, ctx); }
  icon(itemIndex, w = 32, h = 32) { return this.icons.get(itemIndex, w, h); }

  /** NPC sell price (items.md 6.8). */
  sellPrice(inst, shop = null) {
    const def = this.db.def(inst?.itemIndex);
    if (!def || def.npcSell === 0) return 0;
    let p = def.sell > 0 ? def.sell : Math.floor((def.price || 0) * (shop?.sellRatio ?? 3) / 10);
    if (!(def.sell > 0)) {
      const rows = this.db.T?.sellPrice?.rows;
      const socks = (inst.sockets || []).length;
      const row = rows?.find(r => Number(r.SOCKETCOUNT) === socks);
      const col = def.rank === 3 ? 'LEGEND' : inst.grade === 'magic' ? ((inst.rnd || []).length >= 2 ? 'MAGIC2' : 'MAGIC1') : inst.grade === 'noble' ? 'NORBLE' : inst.grade === 'divine' ? 'DIVINE' : 'NORMAL';
      if (row && row[col]) p = Math.floor(p * Number(row[col]) / 100);
      p = Math.min(p, shop?.maxSellCost ?? 500000);
    }
    return p * Math.max(1, inst.count || 1);
  }

  // ------------------------------------------------------------------------------------ equipment actions
  cursorPickup(source) { return this._cursorApply({operation:'pickup',container:source.from,uid:source.uid,...(source.slot==null?{}:{slot:source.slot}),...(source.preset==null?{}:{preset:source.preset}),...(source.parentUid==null?{}:{parentUid:source.parentUid})}); }
  cursorPlace(container,point) { return this._cursorApply({operation:'place',container,...point,uid:this.game.save.itemCursor?.item?.uid}); }
  cursorCancel() { return this._cursorApply({operation:'cancel',uid:this.game.save.itemCursor?.item?.uid}); }
  cursorDiscard(uid,revision) { return this._cursorApply({operation:'discard',uid,revision}); }
  _cursorApply(input) {
    if(this.game.save.authority==='server')return false; // Shared adapters must obtain a host commit.
    const save=this.game.save,profile=structuredClone(save),account=structuredClone(this.account());profile.accountFeatures=account;
    try {
      if(input.operation==='discard'&&Number(this.game.world?.info?.row?.ItemDrop??1)===0)throw Error('This map does not allow ground drops.');
      const discarded=input.operation==='discard'?structuredClone(profile.itemCursor?.item):null;
      if(discarded&&!discarded.bound&&Number(this.db.def(discarded.itemIndex)?.trade)!==0&&(!this.game.player||!this.game.loot?.spawnDrop))throw Error('Ground items are unavailable here.');
      applyCursorOperation(profile,this.db,{...input,revision:input.revision??cursorState(save).revision},{stats:this.game.player?.stats,access:(name,operation,item,origin)=>{
        if(name==='bag'&&this.bag.locked)throw Error('Inventory is locked.');
        if(operation==='pickup'&&this.reserved?.has(item.uid))throw Error('That item is registered in another window.');
        if(name==='shared'&&!account.sharedStash)throw Error('Unlock account-shared storage first.');
        if(name==='shared'&&operation==='place'&&origin?.container!=='shared'&&(item.bound||Number(this.db.def(item.itemIndex)?.trade)===0||item.pet?.active||item.pet?.inv?.length))throw Error('That item cannot enter account-shared storage.');
        if(['stash','shared'].includes(name)&&operation==='place'&&origin?.container!==name){const fee=Number(this.db.equipment.formula?.stStorageCostPerUnit)||10;if((profile.dil||0)<fee)throw Error('Not enough DIL for storage.');profile.dil-=fee;}
      }});
      for(const [field,c]of [['inventory',this.bag],['storage',this.stash],['costumeBag',this.costumeBag]])c.list.splice(0,c.list.length,...profile[field]||[]);
      save.equip=profile.equip;save.potionBelt=profile.potionBelt||[];save.cashInv=profile.cashInv||[];save.itemCursor=profile.itemCursor;save.dil=profile.dil;
      const liveAccount=this.account();liveAccount.shared=profile.accountFeatures.shared||[];this.shared.list=liveAccount.shared;this.saveAccount();
      this.changed('cursor');
      if(discarded&&!discarded.bound&&Number(this.db.def(discarded.itemIndex)?.trade)!==0)dropToGround(this,{kind:'item',itemIndex:discarded.itemIndex,name:this.db.def(discarded.itemIndex)?.name,count:discarded.count,inst:discarded});
      return true;
    }catch(error){this.msg(null,null,error.message);return false;}
  }

  /** Offline equipment changes are one ownership transaction, including dependent off-hand items.
   * A full bag refuses the entire operation; it must never turn an equipment swap into ground loot.
   * Retain object identities on refusal so an already-held cursor still owns the same instance.
   */
  _equipmentAtomic(action, extra = [], targets = []) {
    const containers = [...new Set([this.bag, this.costumeBag, this.cash, ...targets].filter(Boolean))];
    const lists = containers.map(c => [c, c.list.slice(), c.onChange]);
    const data = this.equip.data, equipment = { ...structuredClone(data), items: { ...data.items } };
    const instances = [...new Set([...lists.flatMap(([, list]) => list), ...Object.values(data.items), ...extra].filter(Boolean))];
    const snapshots = instances.map(inst => [inst, structuredClone(inst)]);
    const changed = this.changed, containerChanges = new Map();
    let notification = null, committed = false;
    this._equipmentTransactionActive = true;
    this.changed = (...args) => { notification = args; };
    for (const [c] of lists) c.onChange = reason => containerChanges.set(c, reason);
    try { committed = action() === true; return committed; }
    finally {
      if (!committed) {
        for (const [inst, snapshot] of snapshots) { for (const key of Object.keys(inst)) delete inst[key]; Object.assign(inst, snapshot); }
        for (const [c, list] of lists) c.list.splice(0, c.list.length, ...list);
        for (const key of Object.keys(data)) delete data[key];
        Object.assign(data, equipment);
      }
      this.changed = changed;
      this._equipmentTransactionActive = false;
      for (const [c, , onChange] of lists) c.onChange = onChange;
      if (committed) for (const [c, reason] of containerChanges) c.changed(reason);
      if (committed && notification) changed.apply(this, notification);
    }
  }

  /** Equip an instance from the bag / costume bag into a slot (default: its automatic slot). */
  equipItem(inst, slot = null, presetIdx = this.equip.data.active) {
    if (!this._equipmentTransactionActive) return this._equipmentAtomic(() => this.equipItem(inst, slot, presetIdx), [inst]);
    const E = this.equip;
    if (E.data.locked) return false;
    const def = this.db.def(inst?.itemIndex);
    if (!def?.slot) return false;
    // right click = the item's own slot (a weapon replaces the main weapon; dual wield = drag onto the off-hand slot)
    if (slot == null) slot = E.autoSlot(def, presetIdx);
    const chk = E.check(inst, slot, this.game.player?.stats, presetIdx);
    if (!chk.ok) { this._msgArr(chk.msg, def); return false; }
    const from = this.where(inst);
    const src = from === 'bag' ? this.bag : from === 'costume' ? this.costumeBag : from === 'cash' ? this.cash : null;
    const pos = src ? { page: inst.page, x: inst.x, y: inst.y } : null;
    if (src) src.take(inst);
    delete inst.page; delete inst.x; delete inst.y;
    if (def.belong === 1) inst.bound = true;
    const r = E.place(inst, slot, presetIdx);
    for (const d of r.displaced) {
      // the replaced item takes the new item's old place when it fits, else any free spot
      let res = null;
      if (pos && src === this.bag) res = this.bag.placeAt(d, pos.page, pos.x, pos.y);
      if (!res && !this.bag.add(d, { noStack: true }).ok) { this.msg(40, 77); return false; }
    }
    this.sound('equip', def);
    this.changed('equip', { slot, inst });
    return true;
  }
  _msgArr(m, def) { if (Array.isArray(m)) this.msg(m[0], m[1]); else if (m) this.msg(null, null, m); void def; }

  /** Unequip a slot to the bag (at (page,x,y) when given). */
  unequip(slot, presetIdx = this.equip.data.active, at = null) {
    if (!this._equipmentTransactionActive) return this._equipmentAtomic(() => this.unequip(slot, presetIdx, at));
    const E = this.equip;
    if (E.data.locked) return false;
    const inst = E.get(slot, presetIdx);
    if (!inst) return false;
    if (!E.isEquipped(inst.uid)) return false;
    // enough room? (the item leaves every preset only when this was its last reference)
    const refs = E.data.presets.filter(p => Object.values(p).includes(inst.uid)).length;
    if (refs <= 1) {
      const [w, h] = this.bag.size(inst);
      if (at && !this.bag.fits(at.page, at.x, at.y, w, h)) {
        // Clicking an occupied bag cell swaps bag contents. It must never
        // equip the clicked wing, box, or other unrelated item in this slot.
        const occ = this.bag.inside(at.x, at.y, w, h) ? this.bag.occupants(at.page, at.x, at.y, w, h) : [];
        const o = occ.length === 1 ? occ[0] : null;
        if (!o || this.bag.locked || this.reserved?.has(o.uid)) return false;
        const original=this.bag.list.map(item=>({...item})),equip=structuredClone(E.data);
        const restore=()=>{this.bag.list.splice(0,this.bag.list.length,...original);Object.assign(E.data,equip);};
        this.bag.take(o);
        const r=E.remove(slot,presetIdx);
        if(!r?.inst||!this.bag.placeAt(r.inst,at.page,at.x,at.y)||!this.bag.add(o,{noStack:true}).ok){restore();return false;}
        for(const extra of r.extra)if(!this.bag.add(extra,{noStack:true}).ok){restore();return false;}
        this.changed('unequip',{slot,inst});return true;
      }
      const spot = at || this.bag.findSpot(w, h);
      if (!spot) { this.msg(40, 77); return false; }
      const r = E.remove(slot, presetIdx);
      if (r?.inst) { Object.assign(r.inst, spot); this.bag.list.push(r.inst); }
      for (const x of r?.extra || []) if (!this.bag.add(x, { noStack: true }).ok) { this.msg(40, 77); return false; }
    } else E.remove(slot, presetIdx);
    this.changed('unequip', { slot, inst });
    return true;
  }
  /** A drag payload dropped on an equipment slot. */
  equipFromDrag(d, slot, presetIdx) {
    if (d.from === 'equip') {
      if (d.slot === slot && d.preset === presetIdx) return true;
      // move between the paired slots (rings, earrings, bracelets, force stones) of the same preset
      const E = this.equip;
      const def = this.db.def(d.itemIndex);
      if (d.preset !== presetIdx || !E.slotsFor(def).includes(slot)) return false;
      const p = E.preset(presetIdx);
      const other = p[slot];
      p[slot] = d.uid;
      if (other) p[d.slot] = other; else delete p[d.slot];
      this.changed('equip', { slot });
      return true;
    }
    if (presetIdx !== this.equip.data.active) {
      // a bag item dropped on another preset's slot registers it there (Ctrl + right click in the original)
      return this.equipItem(d.inst, slot, presetIdx);
    }
    return this.equipItem(d.inst, slot, presetIdx);
  }
  setPreset(i) {
    const E = this.equip;
    if (i === E.data.active) return;
    if (this.game.player?.dead) return;
    E.data.active = i;
    this.changed('preset');
  }
  swapWeaponTab() { this.equip.swapWeaponTab(); this.changed('weapontab'); }
  /**
   * Ctrl + left click: register an equipped item in other preset tabs too. `targets` = the presets ticked in Global's
   * inven/ui_selectpresetequipwnd (ui/preset-select.js); without them the next free preset takes it.
   */
  clonePreset(inst, slot, fromPreset, targets) {
    const E = this.equip;
    if (Array.isArray(targets)) {
      const done = clonePresetTo(E, slot, fromPreset, targets);
      if (done.length) this.changed('preset');
      return done.length > 0;
    }
    for (let k = 1; k < 5; k++) {
      const pi = (fromPreset + k) % 5;
      if (E.preset(pi)[slot] === inst.uid) continue;
      if (!E.preset(pi)[slot]) { E.preset(pi)[slot] = inst.uid; this.msg(null, null, (this.str(260, 51) || 'Do you want to register %s?').replace('%s', inst.name).replace('Do you want to register', 'Registered').replace('?', ` (${this.str(260, 53 + pi) || `Preset ${pi + 1}`})`)); this.changed('preset'); return true; }
    }
    return false;
  }

  // ------------------------------------------------------------------------------------ bag actions
  /** Right click on a bag item: equip it, use it, or move it to an open stash / cash inventory. */
  rightClick(inst, where = 'bag') {
    const g = this.game;
    const def = this.db.def(inst.itemIndex);
    if (!def) return;
    if (where === 'bag' && this.reserved?.has(inst.uid)) return;   // registered in an item NPC window
    // an item NPC window is open (upgrade, sockets, options...): right click registers the item there
    if (where === 'bag' && this.craftOffer && this.craftOffer(inst)) return;
    if (where === 'bag' && g.uiwin.isOpen('storage') && this.stashDeposit) { this.stashDeposit(inst); return; }
    if (where === 'bag' && g.uiwin.isOpen('shop') && g.shops?.sell) { g.shops.sell(inst); return; }
    if (def.slot) { this.equipItem(inst); return; }
    if (this.uses.usable(def)) { this._confirmedUse(inst).then(ok => { if (ok) this.changed('use', { item: inst }); }); }
  }
  /** Old-style use(ref): inventory index | uid | {type:'item', uid | itemIndex} | instance. */
  useRef(ref) {
    let inst = null;
    if (ref && typeof ref === 'object' && ref.itemIndex != null && this.bag.list.includes(ref)) inst = ref;
    else if (typeof ref === 'number') inst = this.bag.list[ref] || null;
    else if (typeof ref === 'string') inst = this.bag.byUid(ref);
    else if (ref?.uid) inst = this.bag.byUid(ref.uid);
    if (!inst && ref?.itemIndex != null) {
      // hotbar: any stack of that item (the smallest first, like the original quick slot)
      inst = this.bag.list.filter(i => i.itemIndex === Number(ref.itemIndex)).sort((a, b) => (a.count || 1) - (b.count || 1))[0] || null;
    }
    if (!inst) return false;
    const def = this.db.def(inst.itemIndex);
    if (def?.slot) return this.equipItem(inst);
    if (!this.uses.usable(def)) return false;
    if (this.uses.cooldownLeft(inst.itemIndex) > 0) return false;
    this._confirmedUse(inst).then(ok => { if (ok) this.changed('use', { item: inst }); });
    return true;
  }
  use(inst) { return this._confirmedUse(inst); }
  /** Offline: Global's cash item confirmation first (use-confirm.js). Online uses.use is the network intent, which asks it. */
  async _confirmedUse(inst) {
    if (this.game.save?.authority !== 'server' && !await confirmItemUse(this.game, inst, this.db.def(inst?.itemIndex))) return false;
    return this.uses.use(inst);
  }

  /** A payload from another container / the equipment dropped into the bag at (page, x, y). */
  receiveInBag(d, page, x, y) {
    if (d.from === 'equip') return this.unequip(d.slot, d.preset, { page, x, y });
    if ((d.from === 'stash' || d.from === 'shared') && this.stashWithdraw) return this.stashWithdraw(d.inst, { page, x, y });
    return this.transfer(d, this.bag, page, x, y);
  }

  async splitAsk(inst, page, x, y) {
    const bag=this.bag,uid=inst?.uid,itemIndex=inst?.itemIndex,g=this.game;
    const characterId=g.save.id,authority=g.save.authority,network=g.network,lease=network?.token;
    const owned=typeof uid==='string'&&bag.byUid(uid);
    if(!owned||owned.itemIndex!==itemIndex||bag.locked||this.reserved?.has(uid))return;
    const n = await askSplit(this, owned);
    // Shared snapshots replace instances while the quantity dialog is open.
    // Resolve the same owned UID again, with current count and lease guards.
    const current=this.bag===bag&&bag.byUid(uid);
    if(!Number.isSafeInteger(n)||n<=0||!current||current.itemIndex!==itemIndex||n>=(current.count||1)||bag.locked||this.reserved?.has(uid)||g.save.id!==characterId||g.save.authority!==authority||g.network!==network||network?.token!==lease)return;
    if(authority==='server')return network.action('split',{uid,count:n,page,x,y});
    inst=current;
    const [w, h] = this.bag.size(inst);
    let spot = this.bag.fits(page, x, y, w, h) ? { page, x, y } : this.bag.findSpot(w, h);
    if (!spot) { this.msg(40, 77); return; }
    const part = this.bag.take(inst, n);
    Object.assign(part, spot);
    this.bag.list.push(part);
    this.changed('split');
  }
  async discardAsk(inst) {
    const def = this.db.def(inst.itemIndex);
    const w = this.game.world?.info?.row;
    if (w && Number(w.ItemDrop ?? 1) === 0) { this.msg(40, 9); return false; }
    if (def?.type === 0 && def.code === 4) { this.msg(40, 80); return false; }
    if (inst.bound || Number(def?.trade) === 0) {
      // bound / untradeable items are destroyed instead of dropped
      if (!(await confirmDiscard(this, inst))) return false;
      this.removeInst(inst);
      this.msg(null, null, `${def?.name}${this.str(40, 52) || ''}`.replace(' has been used.', ' has been destroyed.'));
      return true;
    }
    if (!(await confirmDiscard(this, inst))) return false;
    if (!this.bag.list.includes(inst)) return false;
    const it = this.bag.take(inst);
    dropToGround(this, { kind: 'item', itemIndex: it.itemIndex, name: def?.name, count: it.count || 1, inst: it });
    this.msg(null, null, (this.str(40, 78) || 'Discarded Item:  [<ITEMNAME>]').replace('<ITEMNAME>', def?.name || ''));
    this.changed('discard');
    return true;
  }
  async dropDilAsk() {
    const w = this.game.world?.info?.row;
    if (w && Number(w.ItemDrop ?? 1) === 0) { this.msg(40, 9); return; }
    const n = await askDropDil(this);
    if (!n || n > this.dil) return;
    if(this.game.save.authority==='server')return this.game.network.action('dropdil',{amount:n});
    this.dil = this.dil - n;
    dropToGround(this, { kind: 'dil', amount: n });
    this.msg(null, null, (this.str(40, 91) || 'Discard DIL: [ %lld DIL].').replace('%lld', n.toLocaleString('en-US')));
    this.changed('dil');
  }
  openShop() { const g = this.game; if (g.uiwin.has('cashshop')) g.uiwin.open('cashshop'); else if (g.uiwin.has('dshop')) g.uiwin.open('dshop'); else g.uiwin.menuAction?.('btn_cash'); }

  // ------------------------------------------------------------------------------------ time
  _expire() {
    const now = Date.now();
    let any = false;
    for (const c of [this.bag, this.stash, this.costumeBag]) {
      for (const it of [...c.list]) if (it.expiresAt && it.expiresAt < now && this.db.def(it.itemIndex)?.periodBreak) {
        c.take(it); any = true;
        this.msg(null, null, (this.str(40, 105) || 'The following item has expired: [<NAME>].').replace('<NAME>', it.name));
      }
    }
    for (const { slot, inst } of this.equip.entries()) if (inst.expiresAt && inst.expiresAt < now) { this.equip.remove(slot); any = true; }
    if (any) this.changed('expire');
  }
  update(dt) {
    this.authoredEffects?.update(dt);
    this._t = (this._t || 0) + dt;
    if (this._t > 30) { this._t = 0; this._expire(); }
  }
}

export async function install(game) {
  SYS = new ItemsSystem(game);
  game.items = SYS;
  SYS.ready = SYS.init();
  await SYS.ready;
  return SYS;
}
export function update(dt) { SYS?.update(dt); }
export function dispose() { SYS?.icons?.cache.clear(); disposePreviewEncoder(); SYS?.authoredEffects?.dispose(); SYS?.targetSounds?.dispose(); SYS = null; }
export { ItemsSystem };
void cloneItem;
