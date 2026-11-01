// The item builder window (layout.js script): binds the editor pages, the pickers and the live preview to a draft
// record. The draft is applied to the items database as item DRAFT_INDEX on every change, so the 3D preview, the
// inventory icon and the tooltip use exactly the game's own code paths; Save writes it into the library under its
// own custom index (registry.js), where it is a real item for the inventory, equipment, shops and the GM spawner.
import { builderSpec, PICK_TABS, PAGES, MODES, PREVIEW } from './layout.js';
import { ItemPreview, ANIMS } from './preview.js';
import { Catalog } from './catalog.js';
import { openMeshyImport } from './meshy.js';
import {
  applyItem, normalizeRecord, recordFromItem, blankRecord, cleanAsset, slotForKind, BASE_INDEX, DRAFT_INDEX, isCustomIndex,
} from './registry.js';

const clone = (o) => (o == null ? o : JSON.parse(JSON.stringify(o)));
const base = (k) => (k ? String(k).split('/').pop() : '-');
const n = (v) => { const x = Number(String(v ?? '').trim()); return Number.isFinite(x) ? x : 0; };
const GRADES = [['normal', 'Normal'], ['magic', 'Magic'], ['noble', 'Noble'], ['divine', 'Divine Noble']];
const SLOT_LABEL = {
  weapon: 'Weapon (main hand)', offhand: 'Off hand (shield / guard arm / ammo)', helmet: 'Helmet', armor: 'Armor (coat)', pants: 'Pants',
  glove: 'Gloves', boots: 'Boots', costume: 'Costume', accessory: 'Ring / necklace', earring: 'Earring', bracelet: 'Bracelet',
  belt: 'Belt', emblem: 'Emblem', talisman: 'Talisman', wing: 'Wings', grow: 'Grow / EXP amulet', vehicle: 'Mount', pet: 'Pet', force: 'Force stone',
};
const NUM_FIELDS = {
  edit_price: 'price', edit_sell: 'sell', edit_stack: 'stack', edit_w: 'w', edit_h: 'h', edit_sockets: 'sockets', edit_reqlv: 'reqLv',
  edit_maxlv: 'maxLv', edit_reqstr: 'reqStr', edit_reqdex: 'reqDex', edit_reqspr: 'reqSpr', edit_pvpdmg: 'pvpDmg', edit_pvpdef: 'pvpDef',
  edit_block: 'block', edit_range: 'range', edit_speed: 'speed', edit_crit: 'crit', edit_itemlv: 'itemLv', edit_period: 'period',
};
const PAIRS = ['melee', 'magic', 'ranged', 'def'];

export class BuilderWindow {
  constructor(sys) {
    this.sys = sys;
    this.game = sys.game;
    this.db = sys.db;
    this.cat = new Catalog(sys.db);
    this.draft = null;
    this.editing = null;        // library index being edited (null = a new item)
    this.dirty = false;
    this.pickTab = 'lib';
    this.page = 'general';
    this.mode = 'character';
    this.lookClass = 'all';
    this.material = 0;
    this.target = 'main';
    this.pickRows = [];
    this.preview = null;
  }
  get g() { return this.game; }

  // ------------------------------------------------------------------------------------------ registration
  register() {
    const names = (this.db.enums.classes || []).map(c => c.name);
    this.names = names;
    const spec = builderSpec(names);
    this.game.uiwin.registerWindow('itembuilder', {
      script: spec,
      hotkey: 'Ctrl+KeyB',
      create: (win) => this.create(win),
      onOpen: (win, arg) => this.onOpen(win, arg),
      onClose: () => this.onClose(),
    });
  }

  // ------------------------------------------------------------------------------------------ create
  create(win) {
    this.win = win;
    const c = (id) => win.control(id);
    const db = this.db;
    // tabs
    for (const [k] of PICK_TABS) c(`btn_pick_${k}`).onClick(() => this.setPickTab(k));
    for (const [k] of PAGES) c(`btn_tab_${k}`).onClick(() => this.setPage(k));
    for (const [k] of MODES) c(`btn_mode_${k}`).onClick(() => this.setMode(k));
    // pickers
    c('btn_search').onClick(() => this.fillPicker());
    c('edit_search').on('enter', () => this.fillPicker());
    c('edit_search').on('change', () => { clearTimeout(this._st); this._st = setTimeout(() => this.fillPicker(), 250); });
    c('com_pickfilter').on('change', () => this.fillPicker());
    c('lst_pick').on('select', (i, it) => this.pickInfo(it));
    c('lst_pick').on('dblclick', (i, it) => this.pickUse(it, false));
    c('btn_pick_use').onClick(() => this.pickUse(this.pickRows[c('lst_pick').getSelected()], false));
    c('btn_pick_clone').onClick(() => this.pickUse(this.pickRows[c('lst_pick').getSelected()], true));
    // general
    c('edit_name').on('change', (v) => this.set('name', v));
    c('edit_desc').on('change', (v) => this.set('desc', v));
    c('com_kind').setItems(this.cat.kinds().map(k => ({ text: k.text, value: k.value })));
    c('com_kind').on('change', (i, it) => this.setKind(it?.value));
    c('com_rank').setItems(Object.entries(db.enums.rankNames || {}).map(([k, v]) => ({ text: `${v} (${k})`, value: Number(k) })));
    c('com_rank').on('change', (i, it) => this.set('rank', it?.value ?? 0));
    c('com_grade').setItems(GRADES.map(([v, t]) => ({ text: t, value: v })));
    c('com_grade').on('change', (i, it) => this.set('grade', it?.value || 'normal'));
    for (let ci = 0; ci < 15; ci++) c(`chk_cls_${ci}`).on('change', (on) => this.setClassBit(ci, on));
    c('btn_cls_all').onClick(() => { this.draft.classMask = 32767; this.fillClasses(); this.changed(); });
    c('btn_cls_none').onClick(() => { this.draft.classMask = 0; this.fillClasses(); this.changed(); });
    c('chk_trade').on('change', (on) => this.set('trade', on ? 1 : 0));
    c('chk_roll').on('change', (on) => this.set('roll', !!on));
    for (const [id, key] of Object.entries(NUM_FIELDS)) c(id).on('change', (v) => this.set(key, n(v)));
    for (const p of PAIRS) for (const k of [0, 1]) c(`edit_${p}${k}`).on('change', (v) => { const a = (this.draft[p] || [0, 0]).slice(); a[k] = n(v); this.set(p, a); });
    c('edit_usehp').on('change', (v) => this.setUse('hp', n(v)));
    c('edit_usemp').on('change', (v) => this.setUse('mp', n(v)));
    // options
    const optItems = [{ text: '(none)', value: 0 }].concat(Object.entries(db.options?.optionTypes || {}).filter(([k]) => Number(k) > 0)
      .map(([k, o]) => ({ text: `${o.label && o.label !== o.name ? o.label : o.name} (${k})`, value: Number(k) })));
    for (let k = 0; k < 6; k++) {
      c(`com_opt_${k}`).setItems(optItems);
      c(`com_opt_${k}`).on('change', () => this.readOptions('options', 'opt', 6));
      c(`edit_optv_${k}`).on('change', () => this.readOptions('options', 'opt', 6));
    }
    for (let k = 0; k < 7; k++) {
      c(`com_exo_${k}`).setItems(optItems);
      c(`com_exo_${k}`).on('change', () => this.readOptions('exOptions', 'exo', 7));
      c(`edit_exov_${k}`).on('change', () => this.readOptions('exOptions', 'exo', 7));
    }
    const sets = db.equipment.unionSets || {};
    c('com_set').setItems([{ text: '(none)', value: 0 }].concat(Object.entries(sets).map(([k, s]) => ({ text: `${s.name || 'Set'} (#${k})`, value: Number(k) }))));
    c('com_set').on('change', (i, it) => { this.set('union', it?.value || 0); this.fillSetInfo(); });
    // look
    c('com_lookclass').setItems([{ text: 'All classes', value: 'all' }].concat(this.names.map((t, i) => ({ text: t, value: i }))));
    c('com_lookclass').on('change', (i, it) => { this.lookClass = it?.value ?? 'all'; if (this.lookClass !== 'all') this.setPreviewClass(this.lookClass); this.fillLook(); if (this.pickTab === 'models') this.fillPicker(); });
    c('com_mat').setItems([0, 1, 2, 3, 4, 5, 6, 7].map(i => ({ text: `#${i}`, value: i })));
    c('com_mat').on('change', (i, it) => { this.material = it?.value ?? 0; this.fillLook(); });
    c('com_target').setItems([{ text: 'Equipped model (main)', value: 'main' }, { text: 'Second model (left hand)', value: 'left' }, { text: 'Inventory model (icon)', value: 'inv' }]);
    c('com_target').on('change', (i, it) => { this.target = it?.value || 'main'; this.fillLook(); });
    c('btn_tex_reset').onClick(() => this.setTexture(null));
    c('btn_meshy').onClick(() => openMeshyImport(this));
    c('btn_mesh_clear').onClick(() => this.setAsset(null));
    c('btn_left_clear').onClick(() => { delete this.draft.look.left; delete this.draft.look.leftItem; delete this.draft.look.leftAction; this.lookChanged(); });
    c('btn_inv_same').onClick(() => { const a = this.targetAsset('main'); if (a) { this.draft.shape.inv = clone(a); delete this.draft.shape.invAnim; delete this.draft.shape.invSkel; this.lookChanged(); } });
    c('btn_inv_clear').onClick(() => { delete this.draft.shape.inv; delete this.draft.shape.invAnim; delete this.draft.shape.invSkel; this.lookChanged(); });
    c('btn_action_clear').onClick(() => { delete this.draft.look.action; delete this.draft.look.leftAction; this.draft.action = 0; this.lookChanged(); });
    c('btn_meshkey').onClick(() => { const k = c('edit_meshkey').getValue().trim().toLowerCase().replace(/\\/g, '/'); if (/\.mesh$/.test(k)) this.setAsset({ mesh: k }); else this.msg('Enter a mesh data key, e.g. mesh/item/weapon/sword/att_equ_swd_21.mesh'); });
    c('edit_meshkey').on('enter', () => c('btn_meshkey').emit('click'));
    c('btn_texkey').onClick(() => { const k = c('edit_texkey').getValue().trim().toLowerCase().replace(/\\/g, '/'); if (/\.(dds|tga|bmp|png|jpg)$/.test(k)) this.setTexture(k); else this.msg('Enter a texture data key, e.g. texture/item/att_swd_01.dds'); });
    c('edit_texkey').on('enter', () => c('btn_texkey').emit('click'));
    // preview
    c('com_pvclass').setItems(this.names.map((t, i) => ({ text: t, value: i })));
    c('com_pvclass').on('change', (i, it) => this.setPreviewClass(it?.value ?? 0));
    c('com_pvanim').setItems(ANIMS.map(a => ({ text: a.text, value: a.id })));
    c('com_pvanim').on('change', (i, it) => this.preview?.set({ anim: it?.value || 'idle' }));
    // bottom buttons
    c('btn_new').onClick(() => this.newItem());
    c('btn_save').onClick(() => this.save(false));
    c('btn_saveas').onClick(() => this.save(true));
    c('btn_delete').onClick(() => this.remove());
    c('btn_spawn').onClick(() => this.spawn(false));
    c('btn_equip').onClick(() => this.spawn(true));
    c('btn_export').onClick(() => this.sys.exportFile());
    c('btn_import').onClick(() => this.sys.importFile());
    c('btn_close').onClick(() => win.close());
    for (const id of ['btn_save', 'btn_saveas', 'btn_delete', 'btn_spawn', 'btn_equip', 'btn_export', 'btn_import', 'btn_new'])
      c(id).setTooltip({ btn_save: 'Save the item into your custom item library', btn_saveas: 'Save a copy under a new item index', btn_delete: 'Delete this custom item (and every copy you own)',
        btn_spawn: 'Put one into your inventory', btn_equip: 'Put one into your inventory and equip it', btn_export: 'Download the whole library as a JSON file',
        btn_import: 'Load items from a JSON library file', btn_new: 'Start a new item' }[id]);
    this.setPickTab('lib', true);
    this.setPage('general');
  }

  // ------------------------------------------------------------------------------------------ open / close
  onOpen(win, arg) {
    this._closed = false;
    const g = this.game;
    if (!this.preview) {
      this.preview = new ItemPreview(g, this.db);
      this.preview.onStatus = (t) => this.win.control('lbl_pvstatus').setText(t || '');
    }
    this.preview.mount(win.control('pan_view').el, PREVIEW.w - 8, PREVIEW.h - 8);
    if (arg?.index != null && isCustomIndex(arg.index)) this.load(arg.index);
    else if (arg?.clone != null) this.cloneFrom(arg.clone);
    else if (!this.draft) this.newItem(true);
    else this.refreshAll();
    this.setMode(this.mode);
    this._onResize ||= () => this.preview?.resize(PREVIEW.w - 8, PREVIEW.h - 8);
    g.events?.on?.('settings', this._onResize);
  }
  onClose() {
    this._closed = true;
    clearTimeout(this._st); clearTimeout(this._ap);
    this._st = this._ap = null;
    this._pickTok = null;
    this._meshyClose?.();
    this.preview?.unmount();
    this.game.events?.off?.('settings', this._onResize);
  }

  // ------------------------------------------------------------------------------------------ draft lifecycle
  newItem(silent = false) {
    const k = this.draft ? [this.draft.type, this.draft.code] : [4, 1];
    this.draft = normalizeRecord(blankRecord(this.db, k[0], k[1]), this.db);
    this.draft.name = 'New Item';
    this.editing = null;
    this.dirty = !silent && false;
    this.lookClass = 'all';
    this.setPreviewClass(Number(this.game.save?.classIndex) || 0, true);
    this.refreshAll();
  }
  load(index) {
    const r = this.sys.lib.items.find(x => x.index === Number(index));
    if (!r) return false;
    this.draft = normalizeRecord(clone(r), this.db);
    this.editing = r.index;
    this.dirty = false;
    this.lookClass = 'all';
    this.pickPreviewClass();
    this.refreshAll();
    return true;
  }
  cloneFrom(itemIndex) {
    const rec = recordFromItem(this.db, itemIndex);
    if (!rec) { this.msg(`No item #${itemIndex}`); return false; }
    if (isCustomIndex(itemIndex)) { const lr = this.sys.lib.items.find(x => x.index === Number(itemIndex)); if (lr) Object.assign(rec, clone(lr)); }
    rec.name = isCustomIndex(itemIndex) ? `${rec.name} (copy)` : rec.name;
    rec.base = isCustomIndex(itemIndex) ? (rec.base || 0) : Number(itemIndex);
    delete rec.index; delete rec.created; delete rec.updated;
    this.draft = normalizeRecord(rec, this.db);
    this.editing = null;
    this.dirty = true;
    this.lookClass = 'all';
    this.pickPreviewClass();
    this.refreshAll();
    return true;
  }
  /** Preview class: the player's class when the item allows it, else the first allowed class. */
  pickPreviewClass() {
    const mask = Number(this.draft?.classMask) || 0;
    const me = Number(this.game.save?.classIndex) || 0;
    let ci = (mask >>> me) & 1 ? me : -1;
    if (ci < 0) for (let k = 0; k < 15; k++) if ((mask >>> k) & 1) { ci = k; break; }
    this.setPreviewClass(ci < 0 ? me : ci, true);
  }
  setPreviewClass(ci, silent = false) {
    this.pvClass = Number(ci) || 0;
    this.win?.control('com_pvclass').selectValue(this.pvClass);
    if (!silent) this.preview?.set({ classIndex: this.pvClass });
  }

  set(key, v) { if (!this.draft) return; this.draft[key] = v; this.changed(); }
  setUse(k, v) { const u = { ...(this.draft.use || {}) }; if (v) u[k] = v; else delete u[k]; this.draft.use = Object.keys(u).length ? u : undefined; this.changed(); }
  setClassBit(ci, on) { const m = Number(this.draft.classMask) || 0; this.draft.classMask = on ? (m | (1 << ci)) : (m & ~(1 << ci)); this.changed(); }
  setKind(kind) {
    if (kind == null) return;
    const type = Math.floor(kind / 256), code = kind % 256;
    const d = this.draft;
    d.type = type; d.code = code;
    const slot = slotForKind(this.db, type, code);
    // a typical footprint for the kind when switching (weapons are tall, armour 1x2, the rest 1x1)
    if (!this._kindTouched) {
      const sample = this.cat.items('', kind, 1)[0];
      const sd = sample != null ? this.db.def(sample) : null;
      if (sd) { d.w = sd.w; d.h = sd.h; if (!d.stack && sd.stack > 1) d.stack = sd.stack; }
    }
    this.win.control('lbl_slot').setText(SLOT_LABEL[slot] || (slot || 'not equippable'));
    this.changed();
    this.fillGeneralSizes();
    if (this.pickTab === 'models' || this.pickTab === 'items') this.fillPicker();
  }
  readOptions(key, pfx, count) {
    const c = (id) => this.win.control(id);
    const out = [];
    for (let k = 0; k < count; k++) {
      const t = Number(c(`com_${pfx}_${k}`).getValue()) || 0;
      const v = n(c(`edit_${pfx}v_${k}`).getValue());
      if (t > 0 && v) out.push([t, v]);
    }
    this.draft[key] = out;
    this.changed();
  }

  /** The draft changed: re-apply it as the preview item (debounced) and mark unsaved. */
  changed() {
    this.dirty = true;
    this.status();
    clearTimeout(this._ap);
    this._ap = setTimeout(() => this.applyDraft(), 120);
  }
  applyDraft() {
    if (!this.draft) return;
    try { applyItem(this.db, this.draft, DRAFT_INDEX); } catch (err) { console.error('[itembuilder] apply draft', err); return; }
    this.sys.clearIcon(DRAFT_INDEX);
    this.preview?.set({ itemIndex: DRAFT_INDEX, classIndex: this.pvClass, mode: this.mode, force: true });
    this.fillIcon();
    this.fillInfo();
  }

  // ------------------------------------------------------------------------------------------ fill the form
  refreshAll() {
    if (!this.win || !this.draft) return;
    const c = (id) => this.win.control(id);
    const d = this.draft;
    c('edit_name').setValue(d.name);
    c('edit_desc').setValue(d.desc || '');
    c('com_kind').selectValue(d.type * 256 + d.code);
    c('lbl_slot').setText(SLOT_LABEL[slotForKind(this.db, d.type, d.code)] || 'not equippable');
    c('com_rank').selectValue(Number(d.rank) || 0);
    c('com_grade').selectValue(d.grade || 'normal');
    this.fillClasses();
    c('chk_trade').setChecked(Number(d.trade ?? 1) !== 0);
    c('chk_roll').setChecked(!!d.roll);
    for (const [id, key] of Object.entries(NUM_FIELDS)) c(id).setValue(d[key] ?? 0);
    for (const p of PAIRS) { const a = d[p] || [0, 0]; c(`edit_${p}0`).setValue(a[0] || 0); c(`edit_${p}1`).setValue(a[1] || 0); }
    c('edit_usehp').setValue(d.use?.hp || 0);
    c('edit_usemp').setValue(d.use?.mp || 0);
    for (const [key, pfx, count] of [['options', 'opt', 6], ['exOptions', 'exo', 7]]) {
      for (let k = 0; k < count; k++) {
        const o = (d[key] || [])[k];
        c(`com_${pfx}_${k}`).selectValue(o ? o[0] : 0);
        if (o && Number(c(`com_${pfx}_${k}`).getValue()) !== o[0]) { const cb = c(`com_${pfx}_${k}`); cb.setItems([...cb.items, { text: `Option ${o[0]}`, value: o[0] }], true); cb.selectValue(o[0]); }
        c(`edit_${pfx}v_${k}`).setValue(o ? o[1] : '');
      }
    }
    c('com_set').selectValue(Number(d.union) || 0);
    this.fillSetInfo();
    c('com_lookclass').selectValue(this.lookClass);
    c('com_mat').selectValue(this.material);
    c('com_target').selectValue(this.target);
    this.fillLook();
    this.status();
    this.applyDraft();
    if (this.pickTab === 'lib') this.fillPicker();
  }
  fillGeneralSizes() {
    const c = (id) => this.win.control(id);
    c('edit_w').setValue(this.draft.w); c('edit_h').setValue(this.draft.h); c('edit_stack').setValue(this.draft.stack || 0);
  }
  fillClasses() { for (let ci = 0; ci < 15; ci++) this.win.control(`chk_cls_${ci}`).setChecked(((Number(this.draft.classMask) || 0) >>> ci) & 1); }
  fillSetInfo() {
    const s = this.db.equipment.unionSets?.[this.draft.union];
    const lines = [];
    if (s) for (const t of s.tiers || []) lines.push(`(${t.need}) ${(t.effects || []).map(([ty, v]) => `${this.db.optionName ? (this.db.options?.optionTypes?.[ty]?.label || ty) : ty} ${v}`).join(', ')}`);
    this.win.control('lbl_setinfo').setText(lines.join('\n'));
  }
  status() {
    const d = this.draft;
    const idx = this.editing ? `#${this.editing}` : 'new item';
    this.win?.control('lbl_status').setText(`${idx}${this.dirty ? '  - unsaved changes' : ''}`);
  }
  fillInfo() {
    const c = (id) => this.win.control(id);
    const def = this.db.def(DRAFT_INDEX);
    if (!def) return;
    c('lbl_info_index').setText(this.editing ? `Item #${this.editing}` : 'Not saved yet');
    c('lbl_info_kind').setText(`${this.db.kindName(def) || 'Kind'} - ${this.db.rankName(def) || ''}`);
    c('lbl_info_slot').setText(def.slot ? (SLOT_LABEL[def.slot] || def.slot) : 'Not equippable');
    c('lbl_info_size').setText(`${def.w} x ${def.h} cells${def.stack > 1 ? `, stack ${def.stack}` : ''}`);
    c('lbl_info_lib').setText(`${this.sys.lib.items.length} custom item(s)`);
  }
  async fillIcon() {
    const def = this.db.def(DRAFT_INDEX);
    const ctl = this.win.control('pan_icon');
    if (!def) { ctl.setIcon(null); return; }
    const cw = Math.max(1, def.w | 0), ch = Math.max(1, def.h | 0);
    const s = Math.min(1, 96 / (cw * 32), 96 / (ch * 32));
    const pw = Math.round(cw * 32 * s), ph = Math.round(ch * 32 * s);
    ctl.setRect(Math.round((100 - pw) / 2), Math.round((102 - ph) / 2), pw, ph);
    const tok = (this._iconTok = {});
    const r = await this.game.items?.icon?.(DRAFT_INDEX, pw, ph);
    if (this._iconTok === tok) ctl.setIcon(r?.url ? { url: r.url } : null);
    ctl.setTooltip(() => this.game.items?.tooltip?.({ uid: 'ib-draft', itemIndex: DRAFT_INDEX, count: 1, grade: this.draft.grade || 'normal', sockets: this.draft.sockets ? new Array(this.draft.sockets).fill(0) : undefined }) || def.name);
  }

  // ------------------------------------------------------------------------------------------ look editing
  /** The asset of a look target ('main' = look.all or the selected class's, 'left', 'inv'). */
  targetAsset(t = this.target) {
    const L = this.draft.look ||= {};
    const S = this.draft.shape ||= {};
    if (t === 'left') return L.left || null;
    if (t === 'inv') return S.inv || null;
    if (this.lookClass !== 'all') return L.byClass?.[this.lookClass] || L.all || null;
    return L.all || null;
  }
  setAsset(asset, meta = null) {
    const L = this.draft.look ||= {};
    const S = this.draft.shape ||= {};
    const a = asset ? cleanAsset(asset) : null;
    if (this.target === 'left') { if (a) L.left = a; else delete L.left; if (meta?.action != null) L.leftAction = meta.action; else if (a) delete L.leftAction; }
    else if (this.target === 'inv') {
      if (a) { S.inv = a; if (meta?.invAnim) S.invAnim = meta.invAnim; else delete S.invAnim; if (meta?.invSkel) S.invSkel = meta.invSkel; else delete S.invSkel; if (meta?.invAnimTime) S.invAnimTime = meta.invAnimTime; S.invTwoSide = meta?.invTwoSide !== false; }
      else { delete S.inv; delete S.invAnim; delete S.invSkel; }
    } else {
      if (this.lookClass !== 'all') { L.byClass ||= {}; if (a) L.byClass[this.lookClass] = a; else delete L.byClass[this.lookClass]; if (!Object.keys(L.byClass).length) delete L.byClass; }
      else { if (a) { L.all = a; S.game = clone(a); } else { delete L.all; delete S.game; } }
      // an animated (skinned) weapon / wing needs the action table of the model it was picked from
      if (meta && 'action' in meta) { if (meta.action != null) { L.action = meta.action; this.draft.action = meta.action; } else { delete L.action; this.draft.action = 0; } }
      if (meta?.left) { L.left = cleanAsset(meta.left); if (meta.leftAction != null) L.leftAction = meta.leftAction; }
    }
    this.lookChanged();
  }
  setTexture(key) {
    const a = this.targetAsset();
    if (!a) { this.msg('Pick a model first.'); return; }
    if (/\.glb$/i.test(a.mesh || '')) { this.msg('GLB uses its embedded materials. Adjust Material tint in the GLB importer or choose a native model for texture overrides.'); return; }
    const copy = clone(a);
    const tex = (copy.textures || []).filter(t => t.material !== this.material);
    if (key) tex.push({ material: this.material, diffuse: key });
    copy.textures = tex.sort((x, y) => x.material - y.material);
    if (!copy.textures.length) delete copy.textures;
    const L = this.draft.look, S = this.draft.shape;
    if (this.target === 'left') L.left = copy;
    else if (this.target === 'inv') S.inv = copy;
    else if (this.lookClass !== 'all') { L.byClass ||= {}; L.byClass[this.lookClass] = copy; }
    else { L.all = copy; S.game = clone(copy); }
    this.lookChanged();
  }
  lookChanged() { this.fillLook(); this.changed(); }
  fillLook() {
    if (!this.win || !this.draft) return;
    const c = (id) => this.win.control(id);
    const a = this.targetAsset();
    const L = this.draft.look || {}, S = this.draft.shape || {};
    c('lbl_mesh').setText(a ? base(a.mesh) : '-').setTooltip(a?.mesh || null);
    c('lbl_tpack').setText(a?.tpack ? base(a.tpack) : a ? '(automatic)' : '-');
    const t = (a?.textures || []).find(x => x.material === this.material);
    c('lbl_tex').setText(t?.diffuse ? base(t.diffuse) : a ? '(from the pack)' : '-').setTooltip(t?.diffuse || null);
    c('lbl_left').setText(L.left ? base(L.left.mesh) : '-');
    c('lbl_inv').setText(S.inv ? base(S.inv.mesh) : '(game model)');
    c('lbl_action').setText(L.action != null ? `#${L.action}${L.leftAction != null ? ` / #${L.leftAction}` : ''}` : '-');
    const names = { main: this.lookClass === 'all' ? 'Equipped model' : `Equipped model (${this.names[this.lookClass]})`, left: 'Second model', inv: 'Inventory model' };
    c('lbl_lookhint').setText(`Double-click a model, texture or icon on the left: ${names[this.target]}.`);
  }

  // ------------------------------------------------------------------------------------------ pickers
  setPickTab(k, silent = false) {
    this.pickTab = k;
    const c = (id) => this.win.control(id);
    for (const [t] of PICK_TABS) c(`btn_pick_${t}`).setChecked(t === k);
    const F = {
      lib: [{ text: 'All my items', value: 'all' }, { text: 'Weapons', value: 'weapon' }, { text: 'Armour / costumes', value: 'armor' }, { text: 'Other', value: 'other' }],
      items: [{ text: 'Same kind as this item', value: 'same' }, { text: 'Every kind', value: 'all' }],
      models: [{ text: 'Models of this kind (and class)', value: 'kind' }, { text: 'Every item model', value: 'all' }],
      tex: [{ text: 'texture/item', value: 'texture/item' }, { text: 'texture/character', value: 'texture/character' }],
      icons: [{ text: 'Every inventory model', value: 'all' }],
    }[k];
    c('com_pickfilter').setItems(F);
    c('btn_pick_clone').setEnabled(k === 'lib' || k === 'items');
    c('btn_pick_use').setText({ lib: 'Edit', items: 'Use its look', models: 'Use model', tex: 'Use texture', icons: 'Use icon' }[k]);
    c('btn_pick_clone').setText(k === 'lib' ? 'Duplicate' : 'Clone');
    if (k === 'models' || k === 'icons') { this.target = k === 'icons' ? 'inv' : (this.target === 'inv' ? 'main' : this.target); c('com_target').selectValue(this.target); this.fillLook(); }
    if (!silent || this.draft) this.fillPicker();
  }
  async fillPicker() {
    if (this._closed || !this.win || !this.draft) return;
    const c = (id) => this.win.control(id);
    const q = c('edit_search').getValue();
    const f = c('com_pickfilter').getValue();
    const db = this.db;
    const d = this.draft;
    const kind = d.type * 256 + d.code;
    const slot = slotForKind(db, d.type, d.code);
    let rows = [];
    const tok = (this._pickTok = {});
    if (this.pickTab === 'lib') {
      const s = String(q || '').toLowerCase();
      rows = this.sys.lib.items.filter(r => {
        const sl = slotForKind(db, r.type, r.code);
        if (f === 'weapon' && sl !== 'weapon' && sl !== 'offhand') return false;
        if (f === 'armor' && !['helmet', 'armor', 'pants', 'glove', 'boots', 'costume'].includes(sl)) return false;
        if (f === 'other' && ['weapon', 'offhand', 'helmet', 'armor', 'pants', 'glove', 'boots', 'costume'].includes(sl)) return false;
        return !s || r.name.toLowerCase().includes(s) || String(r.index).includes(s);
      }).map(r => ({ kind: 'lib', index: r.index, cols: [{ text: r.name, width: 150, color: r.index === this.editing ? '#ffd24a' : null }, { text: `#${r.index - BASE_INDEX}`, width: 60, align: 'right', color: '#8c8c8c' }] }));
    } else if (this.pickTab === 'items') {
      const list = this.cat.items(q, f === 'same' ? kind : null, 500);
      rows = list.map(i => { const it = db.items[i]; return { kind: 'item', index: i, cols: [{ text: it.name || `#${i}`, width: 158, color: it.custom ? '#9ad0ff' : null }, { text: String(i), width: 58, align: 'right', color: '#8c8c8c' }] }; });
    } else if (this.pickTab === 'models') {
      const ci = this.lookClass !== 'all' ? this.lookClass : this.pvClass;
      const list = this.cat.models(q, { all: f === 'all', slot: this.target === 'inv' ? null : slot, weaponType: d.type === 4 ? 1024 + d.code : null, classIndex: ci });
      rows = list.slice(0, 1500).map(e => ({ kind: 'model', e, cols: [{ text: e.name, width: 150 }, { text: e.folder, width: 66, align: 'right', color: '#8c8c8c' }] }));
      if (list.length > 1500) rows.push({ kind: 'more', text: `... ${list.length - 1500} more (refine the search)` });
    } else if (this.pickTab === 'tex') {
      const list = await this.cat.textures(q, f || 'texture/item');
      if (this._pickTok !== tok) return;
      rows = list.slice(0, 3000).map(k => ({ kind: 'tex', key: k, text: base(k) }));
      if (list.length > 3000) rows.push({ kind: 'more', text: `... ${list.length - 3000} more (refine the search)` });
    } else if (this.pickTab === 'icons') {
      const list = this.cat.invModels(q);
      rows = list.slice(0, 1500).map(e => ({ kind: 'icon', e, cols: [{ text: e.name, width: 150 }, { text: e.folder, width: 66, align: 'right', color: '#8c8c8c' }] }));
      if (list.length > 1500) rows.push({ kind: 'more', text: `... ${list.length - 1500} more (refine the search)` });
    }
    if (this._pickTok !== tok) return;
    this.pickRows = rows;
    c('lst_pick').setItems(rows.map(r => (r.cols ? { cols: r.cols, data: r } : { text: r.text, data: r, color: r.kind === 'more' ? '#8c8c8c' : null })));
    c('lst_pick').select(-1);
    c('lbl_pickinfo').setText(`${rows.filter(r => r.kind !== 'more').length} ${{ lib: 'custom items', items: 'items', models: 'models', tex: 'textures', icons: 'inventory models' }[this.pickTab]}`);
  }
  pickInfo(row) {
    const c = (id) => this.win.control(id);
    if (!row) return;
    const r = row.data || row;
    const db = this.db;
    let t = '';
    if (r.kind === 'item' || r.kind === 'lib') { const d = db.def(r.index); t = d ? `${db.kindName(d)} - Lv ${d.reqLv || 0} - ${d.w}x${d.h}` : ''; }
    else if (r.kind === 'model') t = `${r.e.asset.mesh.replace(/^mesh\/item\//, '')}${r.e.sample ? ` (${db.items[r.e.sample]?.name || ''})` : ''}`;
    else if (r.kind === 'icon') t = `${r.e.inv.mesh.replace(/^mesh\/item\//, '')}${r.e.sample ? ` (${db.items[r.e.sample]?.name || ''})` : ''}`;
    else if (r.kind === 'tex') t = r.key;
    c('lbl_pickinfo').setText(t).setTooltip(t || null);
  }
  pickUse(row, cloneIt) {
    const r = row?.data || row;
    if (!r || r.kind === 'more') { this.msg('Select an entry of the list first.'); return; }
    if (r.kind === 'lib') {
      if (cloneIt) { this.load(r.index); this.editing = null; this.draft.name = `${this.draft.name} (copy)`; delete this.draft.created; this.dirty = true; this.refreshAll(); }
      else this.load(r.index);
      return;
    }
    if (r.kind === 'item') {
      if (cloneIt) { this.cloneFrom(r.index); return; }
      // "use its look": the model(s), inventory model and animation of that item
      const lk = recordFromItem(this.db, r.index, { lookOnly: true });
      if (!lk) return;
      this.draft.look = lk.look; this.draft.shape = lk.shape; this.draft.action = lk.action || 0;
      this.lookChanged();
      this.msg(`Using the look of ${this.db.name(r.index)}.`);
      return;
    }
    if (r.kind === 'model') {
      const e = r.e;
      const L = e.sample != null ? this.db.look(e.sample) : null;
      const meta = { action: null };
      if (L && L.all === e.id && L.action != null) meta.action = L.action;
      if (L && L.all === e.id && L.left != null && this.target === 'main') { meta.left = this.db.asset(L.left); meta.leftAction = L.leftAction; }
      this.setAsset(e.asset, this.target === 'main' ? meta : { action: meta.action });
      return;
    }
    if (r.kind === 'icon') { const prev = this.target; this.target = 'inv'; this.setAsset(r.e.inv, r.e); this.target = prev; return; }
    if (r.kind === 'tex') this.setTexture(r.key);
  }

  // ------------------------------------------------------------------------------------------ pages / modes
  setPage(k) {
    this.page = k;
    for (const [t] of PAGES) { this.win.control(`btn_tab_${t}`).setChecked(t === k); this.win.control(`pan_page_${t}`).setVisible(t === k); }
  }
  setMode(k) {
    this.mode = k;
    for (const [t] of MODES) this.win.control(`btn_mode_${t}`).setChecked(t === k);
    this.win.control('com_pvanim').setVisible(k === 'character');
    this.preview?.set({ mode: k, itemIndex: DRAFT_INDEX, classIndex: this.pvClass });
  }

  // ------------------------------------------------------------------------------------------ actions
  msg(t) { this.sys.msg(t); }
  save(asNew) {
    if(this._saving)return this._saving;
    const draft=this.draft,editing=this.editing,sent=clone(draft),signature=JSON.stringify(sent);
    const task=Promise.resolve().then(()=>this.sys.saveRecord(sent,asNew?null:editing)).then(r=>{
      if(!r)return null;
      if(this.draft===draft&&this.editing===editing){
        this.editing=r.index;
        if(JSON.stringify(this.draft)===signature){this.draft=normalizeRecord(clone(r),this.db);this.dirty=false;}
        else{this.draft.index=r.index;this.dirty=true;}
        this.status();this.fillInfo();
      }
      if(this.pickTab==='lib')this.fillPicker();
      this.msg(`Saved "${r.name}" as item #${r.index}${this.dirty?' (newer draft edits remain unsaved)':''}.`);
      return r;
    }).finally(()=>{if(this._saving===task)this._saving=null;});
    this._saving=task;return task;
  }
  async remove() {
    if(this._saving)return;
    if (!this.editing) { this.newItem(); return; }
    const r = this.sys.lib.items.find(x => x.index === this.editing);
    const question=this.game.save?.authority==='server'?`Archive the server custom item "${r?.name||this.editing}" and remove this character's copies? Other characters keep existing copies; this definition can no longer be spawned.`:`Delete the custom item "${r?.name || this.editing}"? Every copy you own is removed too.`;
    const ans = await this.game.uiwin.msgbox(question, { kind: 'yesno', title: 'Item Builder' });
    if (ans !== 'yes') return;
    const cnt = await this.sys.deleteRecord(this.editing);if(cnt==null)return;
    this.msg(`Deleted item #${this.editing}${cnt ? ` (${cnt} copies removed)` : ''}.`);
    this.editing = null;
    this.dirty = true;
    this.status();
    if (this.pickTab === 'lib') this.fillPicker();
  }
  async spawn(equip) {
    if (!this.editing || this.dirty) { if (!await this.save(false)||this.dirty) return; }
    const res = await this.sys.spawn(this.editing, 1, { equip });
    if (res?.ok) this.msg(equip ? (res.equipped ? `Equipped ${this.draft.name}.` : `${this.draft.name} added to the inventory (could not equip: requirements).`) : `${this.draft.name} added to the inventory.`);
  }
}
