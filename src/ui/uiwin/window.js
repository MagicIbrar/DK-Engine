// UIWindow: one original window built from its script spec (docs/UIWIN.md "Windows").
import { UIControl, NullControl, div } from './controls.js';
import { computeWindowBox, clampToScreen, REF_W, REF_H } from './layout.js';
import { UIScroll, UISlider } from './lists.js';
import { beginPanelDrag } from '../panel-drag.js';

/** The window's root container (a control whose children are the script's top-level controls). */
class UIWindowRoot extends UIControl {
  get hitTest() { return Object.keys(this.images).length > 0; }
}

export class UIWindow {
  /**
   * @param mgr   UIManager
   * @param spec  window spec (spec.js)
   * @param opts  { name, key, modal, escClose, hud, remember, pos:{x,y}, anchor, title }
   */
  constructor(mgr, spec, opts = {}) {
    this.mgr = mgr;
    this.spec = spec;
    this.key = opts.key || spec.file || '';
    this.name = opts.name || spec.name || spec.id || this.key.split('/').pop();
    this.opts = opts;
    this.modal = opts.modal ?? !!spec.modal;
    this.escClose = opts.escClose ?? !opts.hud;
    this.isOpen = false;
    this.data = {};
    this._h = Object.create(null);
    this.el = div('uw-win uw-hidden');
    this.el.dataset.win = this.name;
    this.el._uwWin = this;
    const rootSpec = {
      type: '#root', id: '', rect: [0, 0, 0, 0], anchor: null, layer: 0, enable: spec.enable !== false, visible: true, intersect: spec.intersect !== false,
      moveable: false, align: null, images: spec.images || [], titles: spec.titles || [], props: spec.props || {}, children: spec.children || [],
    };
    this.root = new UIWindowRoot(this, rootSpec, null);
    this.el.appendChild(this.root.el);
    this.box = { x: 0, y: 0, w: 0, h: 0 };
    // opts.deferBuild: the caller finishes the build with buildSliced() (idle-time pre-building)
    if (opts.deferBuild) return;
    this.root.build();
    this._indexControls();
    this._wireDrag();
  }
  /** Finish a deferBuild window in slices (see UIControl.buildSliced). */
  async buildSliced(slice) {
    await this.root.buildSliced(slice);
    this._indexControls();
    this._wireDrag();
    return this;
  }

  // ------------------------------------------------------------ strings
  str(ref) { return this.mgr.strings.get(ref); }
  needStr(ref) { return this.mgr.strings.resolve(ref); }

  // ------------------------------------------------------------ controls
  _indexControls() {
    this.byId = new Map();
    this.byExactId = new Map();
    this.all = [];
    const walk = (c) => {
      for (const k of c.children) {
        k.el._uw = k;
        this.all.push(k);
        if (k.id && !this.byExactId.has(k.id)) this.byExactId.set(k.id, k);
        const id = k.id.toLowerCase();
        if (id && !this.byId.has(id)) this.byId.set(id, k);
        walk(k);
      }
    };
    walk(this.root);
  }
  /** A control by id (case-insensitive). Unknown ids return a NullControl (every call is a no-op) and warn once. */
  control(id) {
    const c = this.byExactId?.get(String(id)) || this.byId.get(String(id).toLowerCase());
    if (c) return c;
    (this._warned ||= new Set());
    if (!this._warned.has(id)) { this._warned.add(id); console.warn(`[uiwin] ${this.name}: no control "${id}"`); }
    return new NullControl(this, id);
  }
  /** Instantiate a template control: win.clone('slot', '_3', {x, y}) -> control 'slot_3' (see UIControl.cloneAs). */
  clone(id, suffix, opts) { const t = this.find(id); return t ? t.cloneAs(suffix, opts) : new NullControl(this, `${id}${suffix}`); }
  /** Like control() but returns null when missing. */
  find(id) { return this.byExactId?.get(String(id)) || this.byId.get(String(id).toLowerCase()) || null; }
  has(id) { return this.byExactId?.has(String(id)) || this.byId.has(String(id).toLowerCase()); }
  /** Controls whose id matches a prefix / RegExp / predicate. */
  controls(filter) { return this.root.controls(filter); }
  /** Every id in the window (for discovery/debugging). */
  ids() { return [...this.byId.keys()]; }
  /** Shorthand binder: win.bind({ btn_ok: () => ..., lbl_title: 'text', chk_x: {checked: true, change: fn} }) */
  bind(map) {
    for (const [id, v] of Object.entries(map)) {
      const c = this.control(id);
      if (typeof v === 'function') c.on('click', v);
      else if (typeof v === 'string' || typeof v === 'number') c.setText(v);
      else if (v && typeof v === 'object') for (const [k, x] of Object.entries(v)) {
        if (k === 'text') c.setText(x); else if (k === 'checked') c.setChecked(x); else if (k === 'visible') c.setVisible(x);
        else if (k === 'enabled') c.setEnabled(x); else if (k === 'tooltip') c.setTooltip(x); else if (k === 'icon') c.setIcon(x);
        else if (k === 'gauge') c.setGauge(x); else if (k === 'value') c.setValue(x); else if (k === 'items') (c.setItems || c.setNodes || c.setRows)?.call(c, x);
        else if (typeof x === 'function') c.on(k, x);
      }
    }
    return this;
  }
  focusNext(ctrl, dir = 1) {
    const edits = this.all.filter(c => c.input && c.isVisible() && c.enabled);
    const i = edits.indexOf(ctrl);
    if (edits.length) edits[(i + dir + edits.length) % edits.length].focus();
  }

  // ------------------------------------------------------------ placement
  /** Default box from the script (anchors/centre/edges; unanchored windows keep their relative place). */
  defaultBox() {
    const scr = this.mgr.screen;
    const b = computeWindowBox(this.spec, scr);
    const s = this.spec;
    if (this.opts.pos) return { ...b, x: this.opts.pos.x, y: this.opts.pos.y };
    if (!s.anchor && !s.center && !s.edges && !s.legacy && s.rect) {
      const [x1, y1] = s.rect;
      if (x1 === 0 && y1 === 0 && (b.w < scr.w || b.h < scr.h)) { b.x = Math.round((scr.w - b.w) / 2); b.y = Math.round((scr.h - b.h) / 2); }
      else {
        // designed for 1024x768: keep the same relative place on larger/smaller screens
        if (REF_W > b.w && scr.w !== REF_W) b.x = Math.round((x1 / (REF_W - b.w)) * (scr.w - b.w));
        if (REF_H > b.h && scr.h !== REF_H) b.y = Math.round((y1 / (REF_H - b.h)) * (scr.h - b.h));
      }
    }
    return b;
  }
  get movable() {
    const t = this.spec.titlerect;
    return this.opts.movable ?? (!!t && (t[2] - t[0] > 0) && (t[3] - t[1] > 0) && this.spec.moveable !== false);
  }
  /** Compute the box and lay out every control. */
  place() {
    const b = this.defaultBox();
    let { x, y } = b;
    const saved = this.opts.remember !== false && this.movable && !b.stretchW && !b.stretchH ? this.mgr.savedPosition(this.name) : null;
    if (this._pos) ({ x, y } = this._pos);
    else if (saved) ({ x, y } = saved);
    if (this._pos || saved || this.movable || this.opts.hud) ({ x, y } = clampToScreen(x, y, b.w, b.h, this.mgr.screen));
    this.box = { x, y, w: b.w, h: b.h };
    const st = this.el.style;
    st.left = `${x}px`; st.top = `${y}px`; st.width = `${b.w}px`; st.height = `${b.h}px`;
    this.root._rectOverride = [0, 0, b.w, b.h];
    this.root.layout({ x: 0, y: 0, w: b.w, h: b.h });
    return this;
  }
  /** Move to (x, y) reference px (remembered when the window is movable). */
  setPosition(x, y, remember = true) {
    const c = clampToScreen(x, y, this.box.w, this.box.h, this.mgr.screen);
    this._pos = c;
    this.box.x = c.x; this.box.y = c.y;
    this.el.style.left = `${c.x}px`; this.el.style.top = `${c.y}px`;
    if (remember && this.movable && this.opts.remember !== false) this.mgr.savePosition(this.name, c);
    this.emit('move', c);
    return this;
  }
  /** Forget the moved position and go back to the script placement. */
  resetPosition() { this._pos = null; this.mgr.savePosition(this.name, null); return this.place(); }
  center() { return this.setPosition(Math.round((this.mgr.screen.w - this.box.w) / 2), Math.round((this.mgr.screen.h - this.box.h) / 2), false); }

  _wireDrag() {
    this.on('close', () => this._cancelPanelDrag?.());
    this.el.addEventListener('pointerdown', () => this.mgr.focus(this), true);
    this.el.addEventListener('pointerdown', (e) => {
      if (e.button !== 0 || e.isPrimary === false || this._cancelPanelDrag) return;
      let c = e.target;
      while (c && !c._uw && c !== this.el) c = c.parentElement;
      const ctl = c?._uw;
      if (ctl && ctl.interactive) return;
      const sc = this.mgr.scale;
      const r = this.el.getBoundingClientRect();
      const lx = (e.clientX - r.left) / sc, ly = (e.clientY - r.top) / sc;
      const t = this.spec.titlerect;
      const inTitle = t && lx >= t[0] && lx < t[2] && ly >= t[1] && ly < t[3];
      const handle = ctl && ctl.spec.moveable && !(ctl.parent instanceof UIScroll) && !(ctl.parent instanceof UISlider);
      if (!(this.movable && inTitle) && !handle) return;
      const sx = e.clientX, sy = e.clientY, ox = this.box.x, oy = this.box.y;
      this._cancelPanelDrag = beginPanelDrag(e, {
        surface: this.el,
        move: ev => this.setPosition(Math.round(ox + (ev.clientX - sx) / sc), Math.round(oy + (ev.clientY - sy) / sc), false),
        finish: () => {
          this._cancelPanelDrag = null;
          if (this.opts.remember !== false) this.mgr.savePosition(this.name, { x: this.box.x, y: this.box.y });
        },
      });
    });
  }

  // ------------------------------------------------------------ open / close
  open(arg) { return this.mgr.openWindow(this, arg); }
  close(result) { return this.mgr.closeWindow(this, result); }
  toggle(arg) { return this.isOpen ? this.close() : this.open(arg); }
  focus() { this.mgr.focus(this); return this; }

  // ------------------------------------------------------------ events
  on(ev, fn) { (this._h[ev] ||= []).push(fn); return this; }
  off(ev, fn) { const a = this._h[ev]; if (a) this._h[ev] = fn ? a.filter(f => f !== fn) : []; return this; }
  once(ev, fn) { const w = (...a) => { this.off(ev, w); fn(...a); }; return this.on(ev, w); }
  emit(ev, ...args) { for (const f of (this._h[ev] || []).slice()) { try { f.call(this, ...args, this); } catch (err) { console.error(`[uiwin] ${this.name} ${ev} handler`, err); } } }

  dispose() {
    this._cancelPanelDrag?.();
    this.root.dispose();
    this.el.remove();
    this.emit('dispose');
  }
}
