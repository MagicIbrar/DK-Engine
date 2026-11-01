// UIManager: the window manager of the UI platform (docs/UIWIN.md).
//   registry (registerWindow / registerHotkey / registerMenuButton), open/close/toggle, z-order & focus,
//   drag by title (window.js), Esc closes the top window, remembered positions, modal windows (the only
//   ones that block game input), tooltips, drag-and-drop, interface scale, message boxes.
import { atlas } from '../atlas.js';
import { strings } from './strings.js';
import { loadFonts } from './fonts.js';
import { loadScriptSpecs, scriptKey } from './spec.js';
import { compiledScriptCache } from './spec-cache.js';
import { UIWindow } from './window.js';
import { DragDrop } from './dnd.js';
import { Tooltips } from './tooltip.js';
import { injectCSS } from './css.js';
import { div } from './controls.js';
import { fetchText, fetchJSON, soundURL } from '../../engine/assets.js';
import { createPanelPrewarm } from './prewarm.js';
import { createPanelPrebuild } from './prebuild.js';

const SPEC_CACHE = new Map();   // script key -> Promise<specs> (shared by every manager)
const LS_POS = 'dekaron.uiwin.pos';
const LS_KEYS = 'dekaron.uiwin.keys';
const loadLS = (k, d) => { try { const v = JSON.parse(globalThis.localStorage?.getItem(k) || 'null'); return v ?? d; } catch { return d; } };
const saveLS = (k, v) => { try { globalThis.localStorage?.setItem(k, JSON.stringify(v)); } catch { /* private mode */ } };

/** Z bands: bottom < hud < normal < system < modal. */
const BAND = { bottom: 1, hud: 2, normal: 3, system: 4, modal: 5 };
/** HUD menu ids of hud.js (data-id) -> original mainmenu button ids. */
const MENU_ALIAS = { supply: 'btn_supplymachine', single_supply: 'btn_single_supplymachine' };

/** Collect every string reference of a spec tree (to preload the tables). */
export function collectRefs(spec, out = []) {
  if (!spec) return out;
  for (const t of spec.titles || []) if (t.ref) out.push(t.ref);
  for (const k of ['ref', 'tooltip', 'stringRef', 'initRef']) if (spec[k]) out.push(spec[k]);
  for (const n of spec.extra?.nodes || []) { if (n.ref) out.push(n.ref); if (n.tooltip) out.push(n.tooltip); }
  for (const ii of spec.extra?.iteminfo || []) for (const it of ii.items || []) if (it.ref) out.push(it.ref);
  for (const c of spec.children || []) collectRefs(c, out);
  return out;
}

export class UIManager {
  /**
   * @param game    the Game (or null for tools such as the gallery)
   * @param rootEl  element to mount the layer in (game.ui); document.body by default
   * @param opts    { scale }
   */
  constructor(game = null, rootEl = null, opts = {}) {
    injectCSS();
    this.game = game;
    this.opts = opts;   // { scale, size: {w, h} fixed screen (tools), embedded: layer positioned inside rootEl }
    this.rootEl = rootEl || document.body;
    this.layer = div('uw-layer', this.rootEl);
    this.strings = strings;
    this.atlas = atlas;
    this.scale = Number(opts.scale ?? game?.settings?.uiScale ?? 1) || 1;
    this.screen = { w: 1024, h: 768 };
    this.defs = new Map();
    this.wins = new Map();
    this.openList = [];
    this.hotkeys = new Map();       // code -> [{action, name, mods}]
    this.menu = new Map();          // button id -> action
    this.anims = new Set();
    this.missing = [];
    this._h = Object.create(null);
    this._specs = SPEC_CACHE;
    this._popups = [];
    this._focusSeq = 0;
    // LANE18: only a plain object can hold per-window entries (a corrupt primitive/array store threw or silently
    // dropped every later save); hotkey overrides and other preferences are read independently and stay untouched.
    const pos = loadLS(LS_POS, {});
    this.positions = pos && typeof pos === 'object' && !Array.isArray(pos) ? pos : {};
    this.keyOverrides = loadLS(LS_KEYS, {});
    this.backdrop = div('uw-backdrop', this.layer);
    this.backdrop.style.display = 'none';
    this.backdrop.addEventListener('pointerdown', (e) => { e.stopPropagation(); e.preventDefault(); });
    this.dnd = new DragDrop(this);
    this.tooltips = new Tooltips(this);
    this._onResize = () => this.resize();
    addEventListener('resize', this._onResize);
    this._onDocDown = (e) => { if (this._popups.length && !this._popups.some(p => p.el.contains(e.target))) this.closePopups(); };
    addEventListener('pointerdown', this._onDocDown, true);
    this.resize();
    // without a game (tools, front-end screens) the manager handles Esc itself; in game, game.js calls handleEscape()
    if (!game) {
      this._onKey = (e) => { if (e.key === 'Escape' && (this.dnd.active || this._popups.length || this.topWindow(true))) { if (this.handleEscape()) e.preventDefault(); } };
      addEventListener('keydown', this._onKey);
    }
    this.ready = Promise.all([atlas.load(), loadFonts(), strings.loadList()]);
    if (game?.events?.on) game.events.on('settings', () => { const s = Number(game.settings?.uiScale); if (s && s !== (this.baseScale ?? this.scale)) this.setScale(s); });
    if (game && this.rootEl) this._exposeOnRoot();
  }

  // ------------------------------------------------------------------ events
  on(ev, fn) { (this._h[ev] ||= []).push(fn); return this; }
  off(ev, fn) { const a = this._h[ev]; if (a) this._h[ev] = fn ? a.filter(f => f !== fn) : []; return this; }
  emit(ev, ...args) { for (const f of (this._h[ev] || []).slice()) { try { f(...args); } catch (err) { console.error(`[uiwin] ${ev} listener`, err); } } this.game?.events?.emit?.(`ui:${ev}`, ...args); }

  // ------------------------------------------------------------------ scale & screen
  resize() {
    const fixed = this.opts?.size;
    // Auto-fit (the F1 slot bar was off the screen unless fullscreen). Keep authored pixels at desktop sizes >= 1024x720; on
    // smaller windows the whole interface scales down uniformly; settings.uiScale multiplies on top.
    if (!fixed && !this.opts?.embedded) {
      if (this.baseScale == null) this.baseScale = this.scale;
      const fit = Math.min(1, (globalThis.innerWidth || 1024) / 1024, (globalThis.innerHeight || 768) / 720);
      // min(): hud-options may already store a fitted uiScale; never apply the fit twice
      this.scale = Math.max(0.35, Math.min(3, Math.min(this.baseScale, fit * Math.max(1, this.baseScale))));
    }
    const vw = fixed ? fixed.w * this.scale : globalThis.innerWidth || 1024, vh = fixed ? fixed.h * this.scale : globalThis.innerHeight || 768;
    this.screen = { w: Math.round(vw / this.scale), h: Math.round(vh / this.scale) };
    const s = this.layer.style;
    if (this.opts?.embedded) s.position = 'absolute';
    s.width = `${this.screen.w}px`; s.height = `${this.screen.h}px`;
    s.transform = this.scale === 1 ? '' : `scale(${this.scale})`;
    for (const w of this.openList) w.place();
    this.emit('resize', this.screen);
  }
  /** Interface scale (settings.uiScale); every window scales uniformly. */
  setScale(s) { this.baseScale = Math.max(0.5, Math.min(3, Number(s) || 1)); this.scale = this.baseScale; this.resize(); return this; }
  /** Client (CSS px) point -> layer reference px. */
  toLayer(cx, cy) {
    const r = this.opts?.embedded ? this.layer.getBoundingClientRect() : { left: 0, top: 0 };
    return { x: (cx - r.left) / this.scale, y: (cy - r.top) / this.scale };
  }

  // ------------------------------------------------------------------ scripts
  /** Parsed specs of a script (cached). key: 'game2/msgbox/ui_msgbox.txt' | 'UI/Game2/...' | 'script/ui/...'. */
  loadScript(script) {
    const key = scriptKey(script);
    if (!this._specs.has(key)) {
      const request = compiledScriptCache.load(key, () => loadScriptSpecs(key, k => fetchText(k, true).catch(error => {
        if (error?.missing) return null;
        throw error;
      }))).catch(error => {
        // A broken transport or malformed declared encoding is not a missing window.
        // Allow a later attempt once the asset source/cache has recovered.
        if (this._specs.get(key) === request) this._specs.delete(key);
        throw error;
      });
      this._specs.set(key, request);
    }
    return this._specs.get(key);
  }

  /**
   * Build a window (not opened). script = path of the window script or a window spec.
   * opts: { name, window (pick a <window> by name/index when the file has several), modal, escClose, hud,
   *         remember, pos:{x,y}, movable, autoClose (default true: btn_exit/btn_close close it) }
   */
  async create(script, opts = {}, slice = null) {
    await this.ready;
    let spec = null, key = '';
    if (script && typeof script === 'object' && script.kind === 'window') spec = script;
    else {
      key = scriptKey(script);
      const r = await this.loadScript(key);
      if (opts.window != null) spec = typeof opts.window === 'number' ? r.windows[opts.window] : r.windows.find(w => w.name === opts.window || w.id === opts.window);
      spec ||= r.windows[0];
      if (!spec && r.fragments.length) spec = { kind: 'window', type: 'window', name: key.split('/').pop(), rect: null, anchor: null, center: [0, 0], titlerect: null, layer: 100, layertype: 'normal', enable: true, visible: true, children: r.fragments, images: [], titles: [], props: {}, file: key };
      if (!spec) throw new Error(`[uiwin] no window in ${key}`);
    }
    await this.strings.need(collectRefs(spec));
    // `slice` (uiwin/prebuild.js): build the controls in idle-time slices instead of in one go
    if (slice) { if (slice.over()) await slice.yield(); slice.begin(); }
    const win = new UIWindow(this, spec, { ...opts, key: key || spec.file, ...(slice ? { deferBuild: true } : {}) });
    if (slice) { await win.buildSliced(slice); delete win.opts.deferBuild; }
    // Specialized purchase/service prompts also use create(), bypassing msgbox().
    // Back their translucent native frame with the same legible prompt surface.
    if (win.modal && /(?:^|\/)msgbox\//i.test(key || spec.file || '')) win.el.style.backgroundColor = '#17130f';
    this.layer.insertBefore(win.el, this.dnd.icon);
    this._autoWire(win);
    if (opts.name) this.wins.set(opts.name, win);
    this.emit('create', win);
    slice?.end('construct');
    return win;
  }
  /** create() + open(). */
  async show(script, opts = {}, arg) { const w = await this.create(script, opts); this.openWindow(w, arg); return w; }

  _autoWire(win) {
    if (win.opts.autoClose !== false) {
      for (const id of ['btn_exit', 'btn_close', 'btn_x', 'btn_cancel_x']) {
        const c = win.find(id);
        if (c && !c._autoClose) { c._autoClose = true; c.on('click', () => { if (win.opts.autoClose !== false) win.close('close'); }); }
      }
    }
    for (const [id] of this.menu) {
      // Native scripts reuse menu IDs for local controls, such as the Party chat tab.
      if (win.opts.menuExclude?.includes(id)) continue;
      const c = win.find(id);
      if (c && !c._menuWired) { c._menuWired = true; c.on('click', () => this.menuAction(id)); }
    }
  }

  // ------------------------------------------------------------------ registry
  /**
   * Register an original window by name.
   * def: { script, window, hotkey ('KeyI' | 'Alt+KeyI'), menuButton ('btn_inven'), modal, escClose, hud, remember,
   *        pos, movable, create(win, mgr), onOpen(win, arg), beforeClose(win, result) (false keeps it open),
   *        onClose(win, result), update(win, dt), replaces ('inventory') }
   */
  registerWindow(name, def = {}) {
    this.defs.set(name, { ...def });
    if (def.hotkey) this.registerHotkey(def.hotkey, name, { name });
    if (def.menuButton) this.registerMenuButton(def.menuButton, name);
    if (def.replaces && def.replaces !== name) this.defs.set(def.replaces, { ...def, alias: name });
    this.emit('register', name, def);
    return this;
  }
  unregisterWindow(name) { const w = this.wins.get(name); if (w) { this.closeWindow(w); w.dispose(); this.wins.delete(name); } this.defs.delete(name); return this; }
  /** Is a window registered under this name? */
  has(name) { return this.defs.has(name); }
  registered() { return [...this.defs.keys()]; }
  prewarm(options = {}) {
    const result = (this._prewarm ||= createPanelPrewarm(this)).request(options);
    // the full prewarm is requested once the world is ready: from then on build the windows during idle time
    if (!options.priorityOnly && options.prebuild !== false) this.prebuild();
    return result;
  }
  /** Start (once) building every registered window during idle time (uiwin/prebuild.js); resolves with its status when done. */
  prebuild(options) {
    if (globalThis.__dekaronPrebuild === false) return Promise.resolve(null);   // debug switch (test-client audits that need untouched windows)
    return (this._prebuild ||= createPanelPrebuild(this, options)).start();
  }
  prebuildStatus() { return this._prebuild ? this._prebuild.status() : null; }
  _resolve(name) { const d = this.defs.get(name); return d?.alias ? this._resolve(d.alias) : { name, def: d }; }

  /** The instance of a registered window (created on first use). */
  async get(name) {
    const { name: n, def } = this._resolve(name);
    if (this.wins.has(n)) return this.wins.get(n);
    if (!def) throw new Error(`[uiwin] unknown window "${name}"`);
    if (def._creating) { if (def._slice) def._slice.urgent = true; return def._creating; }   // someone is waiting: stop slicing a pre-build
    return this._construct(n, def, null);
  }
  /** Build a registered window (create + def.create, never onOpen). `slice` = idle-time pre-build (uiwin/prebuild.js). */
  async _construct(n, def, slice) {
    def._slice = slice;
    def._creating = (async () => {
      const script = def.resolveScript ? await def.resolveScript(this) : def.script;
      const win = await this.create(script, { ...def, name: n }, slice);
      slice?.begin();
      try {
        const pending = def.create?.(win, this);
        slice?.end('create');                                  // the synchronous part of create() (up to its first await)
        await pending;
      } catch (err) { win._creationError=err;console.error(`[uiwin] ${n}.create`, err); }
      return win;
    })();
    try { return await def._creating; } finally { def._creating = null; def._slice = null; }
  }
  /** Open a registered window (or a UIWindow). arg is passed to onOpen and the 'open' event. */
  async open(name, arg) {
    const win = typeof name === 'string' ? await this.get(name) : name;
    return this.openWindow(win, arg);
  }
  close(name, result) {
    const win = typeof name === 'string' ? this.wins.get(this._resolve(name).name) : name;
    if (win) this.closeWindow(win, result);
    return this;
  }
  async toggle(name, arg) {
    const win = typeof name === 'string' ? this.wins.get(this._resolve(name).name) : name;
    if (win?.isOpen) { this.closeWindow(win); return false; }
    await this.open(name, arg);
    return true;
  }
  isOpen(name) { const w = this.wins.get(this._resolve(name).name); return !!w?.isOpen; }
  /** The instance if it was already created (sync), else null. */
  window(name) { return this.wins.get(this._resolve(name).name) || null; }

  openWindow(win, arg) {
    if (!win) return null;
    if (!win.el.parentNode) this.layer.insertBefore(win.el, this.dnd.icon);
    const def = this.defs.get(win.name);
    if (!win.isOpen) {
      win.isOpen = true;
      win.el.classList.remove('uw-hidden');
      win.place();
      this.openList.push(win);
    }
    try { def?.onOpen?.(win, arg); } catch (err) { console.error(`[uiwin] ${win.name}.onOpen`, err); }
    win.emit('open', arg);
    this.focus(win);
    this.emit('open', win);
    return win;
  }
  closeWindow(win, result) {
    if (!win || !win.isOpen) return;
    const def = this.defs.get(win.name);
    // A server-owned service may need confirmation before its controls disappear.
    try { if (def?.beforeClose?.(win, result) === false) return; }
    catch (err) { console.error(`[uiwin] ${win.name}.beforeClose`, err); return; }
    win.isOpen = false;
    win.el.classList.add('uw-hidden');
    this.openList = this.openList.filter(w => w !== win);
    if (this.tooltips.owner && win.el.contains(this.tooltips.owner.el)) this.tooltips.hide();
    this.closePopups();
    try { def?.onClose?.(win, result); } catch (err) { console.error(`[uiwin] ${win.name}.onClose`, err); }
    win.emit('close', result);
    this._restack();
    this.emit('close', win, result);
    if (win.opts.disposeOnClose) { win.dispose(); for (const [k, v] of this.wins) if (v === win) this.wins.delete(k); }
  }
  /** Close every open window except HUD windows (map change, death...). */
  closeAll({ includeHud = false } = {}) {
    for (const w of this.openList.slice().reverse()) if (includeHud || !w.opts.hud) this.closeWindow(w, 'closeAll');
    this.emit('closeAll');   // pending NPC service creation also belongs to this cancellation boundary
  }
  /** Open windows, bottom to top. */
  openWindows() { return this.openList.slice(); }
  get anyOpen() { return this.openList.some(w => !w.opts.hud); }
  /** True while a modal window is open or a text field of the UI has focus (game input must pause). */
  get capturesInput() {
    if (this.openList.some(w => w.modal)) return true;
    const a = document.activeElement;
    return !!(a && (a.tagName === 'INPUT' || a.tagName === 'TEXTAREA') && this.layer.contains(a));
  }
  get allowsDirectionalMovement() {
    const modals = this.openList.filter(w => w.modal);
    if (!modals.length || modals.some(w => !w.opts.allowDirectionalMovement)) return false;
    const a = document.activeElement;
    return !(a && (a.tagName === 'INPUT' || a.tagName === 'TEXTAREA') && this.layer.contains(a));
  }
  get modalOpen() { return this.openList.some(w => w.modal); }

  _band(w) {
    if (w.modal) return BAND.modal;
    if (w.opts.band) return BAND[w.opts.band] || BAND.normal;
    if (w.opts.hud) return BAND.hud;
    const lt = w.spec.layertype;
    return BAND[lt] || BAND.normal;
  }
  focus(win) {
    if (!win) return;
    win._focus = ++this._focusSeq;
    this._restack();
    if (this._top !== win) { this._top?.emit('blur'); this._top = win; win.emit('focus'); }
  }
  _restack() {
    const sorted = this.openList.slice().sort((a, b) => this._band(a) - this._band(b) || (a._focus || 0) - (b._focus || 0));
    this.openList = sorted;
    sorted.forEach((w, i) => { w.el.style.zIndex = String(this._band(w) * 10000 + i * 2 + 2); });
    const topModal = [...sorted].reverse().find(w => w.modal);
    if (topModal) {
      this.backdrop.style.display = '';
      this.backdrop.style.zIndex = String(Number(topModal.el.style.zIndex) - 1);
    } else this.backdrop.style.display = 'none';
  }
  /** Top-most open window (optionally only Esc-closable ones). */
  topWindow(escOnly = false) {
    for (let i = this.openList.length - 1; i >= 0; i--) { const w = this.openList[i]; if (!escOnly || w.escClose) return w; }
    return null;
  }

  // ------------------------------------------------------------------ keys
  /**
   * Esc: cancel a drag, close a dropdown, else close the top Esc-closable window (a modal message box answers
   * 'cancel'). Returns true when it did something (game.js then skips its own Esc handling).
   */
  handleEscape() {
    if (this.dnd.active) { this.dnd.cancel(); return true; }
    if (this._popups.length) { this.closePopups(); return true; }
    const a = document.activeElement;
    if (a && this.layer.contains(a) && (a.tagName === 'INPUT' || a.tagName === 'TEXTAREA')) { a.blur(); return true; }
    const w = this.topWindow(true);
    if (w) { this.closeWindow(w, 'escape'); return true; }
    return false;
  }
  /**
   * Hotkey: code = KeyboardEvent.code ('KeyI', 'F1', 'Digit1'), optionally with modifiers 'Alt+KeyI' / 'Ctrl+KeyS'.
   * action = registered window name (toggled) or a function(mgr).
   */
  registerHotkey(code, action, { name = typeof action === 'string' ? action : '' } = {}) {
    const k = this._keyOf(name, code);
    const parsed = parseKey(k);
    for (const [c, list] of this.hotkeys) this.hotkeys.set(c, list.filter(h => !(name && h.name === name)));
    if (!this.hotkeys.has(parsed.code)) this.hotkeys.set(parsed.code, []);
    this.hotkeys.get(parsed.code).push({ action, name, mods: parsed.mods, spec: k, def: code });
    this.emit('hotkeys');
    return this;
  }
  _keyOf(name, dflt) { return (name && this.keyOverrides[name]) || dflt; }
  /** Rebind a named hotkey (keymap window); persisted. code null restores the default. */
  setHotkey(name, code) {
    let entry = null;
    for (const list of this.hotkeys.values()) for (const h of list) if (h.name === name) entry = h;
    if (!entry) return this;
    if (code) this.keyOverrides[name] = code; else delete this.keyOverrides[name];
    saveLS(LS_KEYS, this.keyOverrides);
    return this.registerHotkey(entry.def, entry.action, { name });
  }
  /** Is a key code (no modifiers) bound by a registered hotkey? game.js then skips its built-in binding. */
  hasHotkey(code) { return (this.hotkeys.get(code) || []).some(h => !h.mods.alt && !h.mods.ctrl); }
  /** [{name, code, default}] of every registered hotkey. */
  listHotkeys() { const out = []; for (const list of this.hotkeys.values()) for (const h of list) out.push({ name: h.name, code: h.spec, default: h.def }); return out; }
  /** Called by game.js every frame with its Input (fires hotkeys; ignored while typing or when a modal is open). */
  handleKeys(input) {
    if (!input || this.capturesInput) return false;
    let fired = false;
    for (const [code, list] of this.hotkeys) {
      if (!input.hit(code)) continue;
      const alt = input.down('AltLeft') || input.down('AltRight');
      const ctrl = input.down('ControlLeft') || input.down('ControlRight');
      const shift = input.down('ShiftLeft') || input.down('ShiftRight');
      for (const h of list) {
        if (!!h.mods.alt !== alt || !!h.mods.ctrl !== ctrl || (h.mods.shift != null && !!h.mods.shift !== shift)) continue;
        this._run(h.action);
        fired = true;
      }
    }
    return fired;
  }
  _run(action) {
    try {
      if (typeof action === 'function') action(this);
      else if (typeof action === 'string') {
        if (this.defs.has(action)) this.toggle(action);
        else this.game?.windows?.toggle?.(action);
      }
    } catch (err) { console.error('[uiwin] hotkey action', err); }
  }

  // ------------------------------------------------------------------ menu buttons
  /** Bind an original main-menu button id (btn_inven, btn_character, ...) to a window name or a function. */
  registerMenuButton(id, action) {
    this.menu.set(id, action);
    for (const w of this.wins.values()) this._autoWire(w);
    this._syncHudMenu();
    this.emit('menubuttons');
    return this;
  }
  hasMenuButton(id) { return this.menu.has(MENU_ALIAS[id] || id); }
  /** Run a menu button's action. Accepts the original id or the hud.js data-id. Returns true if bound. */
  menuAction(id) {
    const key = this.menu.has(id) ? id : this.menu.has(MENU_ALIAS[id]) ? MENU_ALIAS[id] : this.menu.has(`btn_${id}`) ? `btn_${id}` : null;
    if (!key) return false;
    this._run(this.menu.get(key));
    return true;
  }
  /** Enable the matching buttons of hud.js's menu column (they show dimmed until something is bound). */
  _syncHudMenu() {
    if (typeof document === 'undefined') return;
    for (const b of document.querySelectorAll('.dk-menu-btn[data-id]')) {
      const id = b.dataset.id;
      if (this.hasMenuButton(`btn_${id}`) || this.hasMenuButton(id)) { b.classList.remove('off'); if (b.title) b.title = b.title.replace(/ \(not available yet\)$/, ''); }
    }
  }

  // ------------------------------------------------------------------ popups (combobox dropdowns)
  popup(el, onClose) { this._popups.push({ el, onClose }); el.style.zIndex = '400000'; }
  closePopups() { const p = this._popups; this._popups = []; for (const x of p) { x.el.remove(); x.onClose?.(); } }

  // ------------------------------------------------------------------ positions
  // LANE18: both coordinates must be finite numbers; an invalid entry falls back to that window's script placement only.
  savedPosition(name) { const p = Object.hasOwn(this.positions, name) ? this.positions[name] : null; return p && Number.isFinite(p.x) && Number.isFinite(p.y) ? p : null; }
  savePosition(name, pos) {
    if (!name) return;
    if (pos) this.positions[name] = { x: Math.round(pos.x), y: Math.round(pos.y) }; else delete this.positions[name];
    saveLS(LS_POS, this.positions);
  }
  /** Forget every remembered position. */
  resetPositions() { this.positions = {}; saveLS(LS_POS, {}); for (const w of this.openList) { w._pos = null; w.place(); } }

  // ------------------------------------------------------------------ per-frame
  animate(ctrl) { this.anims.add(ctrl); }
  unanimate(ctrl) { this.anims.delete(ctrl); }
  update(dt) {
    for (const c of this.anims) { try { c.tick(dt); } catch (err) { this.anims.delete(c); console.error('[uiwin] anim', err); } }
    for (const w of this.openList) {
      const def = this.defs.get(w.name);
      // (playgate) a throwing window update is logged once and kept; only one that throws 300 frames in a row is dropped
      if (def?.update) {
        try { def.update(w, dt, this); def._fails = 0; } catch (err) {
          if (!def._fails) console.error(`[uiwin] ${w.name}.update`, err);
          def._fails = (def._fails || 0) + 1;
          if (def._fails >= 300) def.update = null;
        }
      }
      try { w.emit('update', dt); } catch (err) { if (!w._updErr) { w._updErr = true; console.error(`[uiwin] ${w.name} 'update' listener`, err); } }
    }
  }

  // ------------------------------------------------------------------ sound
  /** UI sound: script `sound N` code (0 common click, 1 main button), or 'open'/'close'. */
  sound(code) {
    if (code == null) return;
    const audio = this.game?.audio;
    const kind = code === 'open' ? 'boxOpen' : code === 'close' ? 'boxClose' : String(code) === '1' ? 'buttonMain' : 'buttonCommon';
    if (audio?.ui) { try { audio.ui(kind); } catch { /* ignore */ } return; }
    if (!this.soundsEnabled) return;
    this._soundTable ||= fetchJSON('/gamedata/sound.json').catch(() => null);
    this._soundTable.then(t => {
      const ui = t?.ui || {};
      const list = kind === 'buttonMain' ? ui.buttonMain : kind === 'boxOpen' ? ui.boxOpen : kind === 'boxClose' ? ui.boxClose : ui.buttonCommon;
      const r = Array.isArray(list) ? list[0] : list;
      const path = r?.path || (kind === 'buttonMain' ? 'ui_press_main_00.wav' : 'ui_com_button.wav');
      try { const a = new globalThis.Audio(soundURL(path)); a.volume = 0.5; a.play().catch(() => {}); } catch { /* no audio */ }
    });
  }

  missingSprite(img, ctrl) { this.missing.push({ screen: img.screen, index: img.index, window: ctrl.win.name, control: ctrl.id }); }

  // ------------------------------------------------------------------ message boxes
  /**
   * Original message boxes. kind: 'ok' (msgbox/ui_resultbox.txt), 'yesno' | 'okcancel' (msgbox/ui_msgbox_ok.txt),
   * 'edit' (msgbox/ui_msgbox_edit.txt, resolves the text or null), 'progress' (ui_msgbox_progress.txt, returns
   * {win, set(frac), close()} immediately).
   * Resolves 'yes' | 'no' | 'ok' | 'cancel' | text.
   */
  async msgbox(text, { title = '', kind = 'ok', yes, no, value = '', script, window: winName, name, scripted = false, body: bodyId } = {}) {
    const file = script || (kind === 'ok' ? 'game2/msgbox/ui_resultbox.txt' : kind === 'edit' ? 'game2/msgbox/ui_msgbox_edit.txt' : kind === 'progress' ? 'game2/msgbox/ui_msgbox_progress.txt' : 'game2/msgbox/ui_msgbox_ok.txt');
    // `name` registers the box (until it closes) so the caller can close() it by name, e.g. an invitation that was withdrawn
    const win = await this.create(file, { window: winName, name, modal: true, escClose: true, remember: false, disposeOnClose: true, autoClose: true });
    // Keep prompts legible immediately while their original frame sprites decode.
    win.el.style.backgroundColor = '#17130f';
    // scripted: a Global msgbox script keeps its own text2 title/message; only non-empty overrides apply
    if (!scripted || title) (win.find('lbl_title'))?.setText(title);
    // (playgate) client strings carry markup (<color=ffff00>...): render it instead of printing the tags
    const body = (bodyId && win.find(bodyId)) || win.find('lbl_text') || win.find('lbl_msg');
    if (body && !(scripted && (text == null || text === ''))) {
      if (/<\/?color|<center>|<br>/i.test(String(text ?? '')) && typeof body.setRichText === 'function') body.setRichText(text);
      else body.setText(text);
    }
    if (yes) win.find('btn_yes')?.setText(yes);
    if (no) win.find('btn_no')?.setText(no);
    if (kind === 'progress') {
      this.openWindow(win);
      const bar = win.find('processbar');
      return { win, set: (f) => bar?.setGauge(f), close: () => win.close('done') };
    }
    const edit = win.find('edit_text');
    if (edit) edit.setValue(value);
    return new Promise((resolve) => {
      win.once('close', (r) => {
        if (r === 'yes') resolve(kind === 'edit' ? edit?.getValue() ?? '' : kind === 'ok' ? 'ok' : 'yes');
        else if (r === 'no') resolve(kind === 'edit' ? null : 'no');
        else resolve(kind === 'edit' ? null : kind === 'ok' ? 'ok' : 'cancel');
      });
      win.find('btn_yes')?.on('click', () => win.close('yes'));
      win.find('btn_ok')?.on('click', () => win.close('yes'));
      win.find('btn_no')?.on('click', () => win.close('no'));
      // renewed Global boxes name the pair btn_confirm / btn_cancel (e.g. party/ui_partynameinputwnd_renew, inven/ui_savemoney)
      win.find('btn_confirm')?.on('click', () => win.close('yes'));
      win.find('btn_cancel')?.on('click', () => win.close('no'));
      edit?.on('enter', () => win.close('yes'));
      this.openWindow(win);
      if (edit) setTimeout(() => edit.focus(), 0);
    });
  }

  // ------------------------------------------------------------------ misc
  _exposeOnRoot() {
    const el = this.rootEl;
    const api = {
      uiwin: this,
      registerWindow: (n, d) => this.registerWindow(n, d),
      registerHotkey: (c, a, o) => this.registerHotkey(c, a, o),
      registerMenuButton: (i, a) => this.registerMenuButton(i, a),
      openWindow: (n, a) => this.open(n, a),
      closeWindow: (n, r) => this.close(n, r),
      toggleWindow: (n, a) => this.toggle(n, a),
      createWindow: (s, o) => this.create(s, o),
      msgbox: (t, o) => this.msgbox(t, o),
    };
    for (const [k, v] of Object.entries(api)) {
      try { Object.defineProperty(el, k, { value: v, configurable: true, writable: true, enumerable: false }); } catch { /* frozen */ }
    }
  }
  dispose() {
    this._prebuild?.stop();
    removeEventListener('resize', this._onResize);
    removeEventListener('pointerdown', this._onDocDown, true);
    if (this._onKey) removeEventListener('keydown', this._onKey);
    this.tooltips.dispose();
    this.dnd.dispose();
    for (const w of this.wins.values()) w.dispose();
    this.layer.remove();
  }
}

/** 'Alt+KeyI' -> {code:'KeyI', mods:{alt:true}} */
export function parseKey(s) {
  const parts = String(s).split('+').map(p => p.trim()).filter(Boolean);
  const mods = {};
  let code = parts.pop() || '';
  for (const p of parts) { const l = p.toLowerCase(); if (l === 'alt') mods.alt = true; else if (l === 'ctrl' || l === 'control') mods.ctrl = true; else if (l === 'shift') mods.shift = true; }
  return { code, mods };
}
