// DOM controls of the UI window platform: one class per window-script control type (docs/UIWIN.md "Controls").
// Every control is an absolutely positioned <div> at its script rect (reference pixels), z-index = `layer`,
// painted with the imagetable sprite of its current state (stretched, or nine-sliced when the imagetable row
// has L,T,R,B margins and the rect differs from the sprite size) and its <title> text in the font.csv font.
import { atlas } from '../atlas.js';
import { retainPreviewIcon } from '../preview-cache.js';
import { refreshSpinHover } from './spin-hover.js';
import { controlBox, computeWindowBox } from './layout.js';
import { applyFont, fontOf, measureText } from './fonts.js';
import { markupRuns, formatString } from './strings.js';
import { dilColor, formatDil } from '../item-colors.js';
import { cooldownBackground } from '../cooldown.js';
import { SOCKET_ICON_LAYOUT_CHOSEN } from '../../config/engine-chosen-socket-layout.js';

// ------------------------------------------------------------------------------------------ helpers
export const TYPES = Object.create(null);
/** Register a control class for a script tag. */
export function registerControlType(tag, cls) { TYPES[tag] = cls; }

export function div(cls, parent) {
  const e = document.createElement('div');
  if (cls) e.className = cls;
  if (parent) parent.appendChild(e);
  return e;
}

/** [a,r,g,b] -> css rgba() */
export function rgba(c, fallback = '#fff') {
  if (!c) return fallback;
  return `rgba(${c[1]},${c[2]},${c[3]},${(c[0] / 255).toFixed(3)})`;
}

const IMAGE_CHAIN = {
  none: ['none'], over: ['over', 'none'], down: ['down', 'over', 'none'], disable: ['disable', 'none'],
  check: ['check', 'down', 'none'], check_over: ['check_over', 'check', 'over', 'none'], check_down: ['check', 'down', 'none'],
  blink: ['blink', 'over', 'none'],
};
const TITLE_CHAIN = {
  none: ['none'], over: ['over', 'none'], down: ['down', 'over', 'none'], disable: ['disable', 'none'],
  check: ['check', 'none'], check_over: ['check', 'over', 'none'], check_down: ['check', 'down', 'none'], blink: ['over', 'none'],
};

/** Paint a resolved sprite on an element (stretch / nine-slice). */
export function applySprite(el, s, w, h, mode = 'stretch') {
  if (!s) {
    el.style.backgroundImage = ''; el.style.borderImage = ''; el.style.borderWidth = '0'; el.style.borderStyle = 'none';
    return;
  }
  const m = s.row?.m || [0, 0, 0, 0];
  const nine = mode !== 'natural' && (m[0] || m[1] || m[2] || m[3]) && (w !== s.row.w || h !== s.row.h);
  if (nine) {
    const [l, t, r, b] = m;
    el.style.backgroundImage = 'none';
    el.style.borderStyle = 'solid';
    el.style.borderWidth = `${t}px ${r}px ${b}px ${l}px`;
    el.style.borderImage = `url("${s.url}") ${t} ${r} ${b} ${l} fill / ${t}px ${r}px ${b}px ${l}px stretch`;
  } else {
    el.style.borderStyle = 'none'; el.style.borderWidth = '0'; el.style.borderImage = '';
    el.style.backgroundImage = `url("${s.url}")`;
    el.style.backgroundSize = '100% 100%';
  }
}

/** Resolve an image spec {screen,index,color} to a sprite (sync if decoded, else promise). */
function spriteNow(img) { return img && img.screen && img.index >= 0 ? atlas.tintedNow(img.screen, img.index, img.color) : null; }
function spriteLater(img) { return img && img.screen && img.index >= 0 ? atlas.tinted(img.screen, img.index, img.color) : Promise.resolve(null); }

/**
 * A spinning item icon (items/icons.js spin sheets): `cols x rows` frames played with CSS steps() on the shared
 * clock (negative delay = the current phase), so re-rendering a grid never restarts or desyncs the spin.
 * spin: {url, cols, rows, period (s)}
 */
export function paintSpin(el, s) {
  const cols = Math.max(1, s.cols | 0), rows = Math.max(1, s.rows | 0), T = Math.max(0.1, Number(s.period) || 2);
  const now = (globalThis.document?.timeline?.currentTime ?? globalThis.performance?.now?.() ?? Date.now()) / 1000;
  el._uwSpin = true;
  el.style.backgroundImage = `url("${s.url}")`;
  el.style.backgroundSize = `${cols * 100}% ${rows * 100}%`;
  el.style.backgroundPosition = '0% 0%';
  // User: items spin ONLY while hovered (like the original), otherwise they rest on the first (front) frame.
  // The animation lives in a CSS variable that .uw-spin applies only under :hover (css.js).
  const phase = -now;
  const a = [], tx = T / rows;
  if (cols > 1) a.push(`uwspinx ${tx.toFixed(4)}s steps(${cols}, jump-none) ${(phase % tx).toFixed(4)}s infinite`);
  if (rows > 1) a.push(`uwspiny ${T.toFixed(4)}s steps(${rows}, jump-none) ${(phase % T).toFixed(4)}s infinite`);
  el.style.animation = '';
  el.style.setProperty('--uw-spin', a.join(', ') || 'none');
  el.classList.add('uw-spin');
  refreshSpinHover();
}

/** Rows x columns of the socket stones drawn on one icon, from the item's OWN footprint (item.dat Width x Height in bag
 * cells) and its socket count; nothing is class- or kind-wide (staff 1x4 -> 4 rows x 1 column, wand / sword 1x3 -> 3 x 1,
 * Bagi gauntlet 2x2 -> 2 x 2, shield 2x3 with 4 stones -> 3 rows x 2 columns, bow / great axe 2x4 -> 4 x 1). Stones stack
 * along the longer footprint side and wrap onto the other axis only when that side is too short; a square footprint
 * fills across first. A tall grid fills column by column, a wide / square one row by row (src/config/engine-chosen-socket-layout.js). */
export function socketFootprintGrid(cellsW, cellsH, count) {
  const n=Math.min(SOCKET_ICON_LAYOUT_CHOSEN.MAX_MARKERS,Math.max(0,Math.floor(Number(count)||0)));
  const fw=Math.max(1,Math.floor(Number(cellsW)||1)),fh=Math.max(1,Math.floor(Number(cellsH)||1));
  if(!n)return {rows:0,cols:0,order:'row'};
  if(fh>fw){const rows=Math.min(n,Math.max(Math.min(n,fh),Math.ceil(n/fw)));return {rows,cols:Math.ceil(n/rows),order:'column'};}
  const cols=Math.min(n,Math.max(Math.min(n,fw),Math.ceil(n/fh)));return {rows:Math.ceil(n/cols),cols,order:'row'};
}

/** Keep the native 18px Socket art centred in a 20px viewport. The source
 * frame is 32px with transparent margins; shrinking that whole frame to 10px
 * made its visible gem only 5.6px. width / height = the painted icon box in px,
 * cells = [Width, Height] of the item's footprint (default: the box in 32px cells). */
export function socketMarkerLayout(width, height, count, cells = null) {
  const {MAX_MARKERS,PAD:pad,GAP:gap,MAX_SIZE,NATIVE_CELL}=SOCKET_ICON_LAYOUT_CHOSEN;
  const n=Math.min(MAX_MARKERS,Math.max(0,Math.floor(Number(count)||0)));
  const w=Math.max(1,Number(width)||32),h=Math.max(1,Number(height)||32);
  if(!n)return {size:0,frame:0,points:[]};
  const [cw,ch]=Array.isArray(cells)?cells:[Math.round(w/32),Math.round(h/32)];
  const {rows,cols,order}=socketFootprintGrid(cw,ch,n);
  const size=Math.max(1,Math.min(MAX_SIZE,Math.floor((w-pad*2-gap*(cols-1))/cols),Math.floor((h-pad*2-gap*(rows-1))/rows)));
  const frame=NATIVE_CELL*size/MAX_SIZE,originX=(w-(cols*size+(cols-1)*gap))/2,originY=(h-(rows*size+(rows-1)*gap))/2;
  return {rows,cols,order,size,frame,points:Array.from({length:n},(_,i)=>{const c=order==='column'?Math.floor(i/rows):i%cols,r=order==='column'?i%rows:Math.floor(i/cols);return {x:originX+c*(size+gap),y:originY+r*(size+gap)};})};
}

/** An icon descriptor -> painter. icon: {sprite:[group,index], dx?} | {url} | {spin} | {canvas} | {el} | string url | null */
export function paintIcon(el, icon) {
  // Replacements release their previous lease; connected reused panels stay pinned.
  const tok = (el._iconTok = {});
  const refresh = retainPreviewIcon(el, icon);
  if (refresh) {
    el.style.backgroundImage = '';
    void refresh.then(next => {
      if (el._iconTok !== tok || !next) return;
      const count = el.querySelector?.('.uw-count');
      paintIcon(el, next); if (count) el.appendChild(count);
    });
    return;
  }
  if (icon?.baseIcon && icon.socketMarkers) {
    paintIcon(el, icon.baseIcon);
    // Static native atlas markers sit above the unchanged spinning model. No
    // events, model resources, extra WebGL draws or repeating work are added.
    const row=div('uw-item-sockets',el);
    const [width,height]=icon.socketSize||[32,32],[left,top]=icon.socketOffset||[0,0],layout=socketMarkerLayout(width,height,icon.socketMarkers.length,icon.socketCells);
    row.style.cssText=`position:absolute;left:${left}px;top:${top}px;width:${width}px;height:${height}px;z-index:2;pointer-events:none`;
    for(const [i,marker] of icon.socketMarkers.slice(0,SOCKET_ICON_LAYOUT_CHOSEN.MAX_MARKERS).entries()) {
      const cell=div('uw-item-socket',row),point=layout.points[i];
      cell.style.cssText=`position:absolute;left:${point.x}px;top:${point.y}px;width:${layout.size}px;height:${layout.size}px;background-size:${layout.frame}px ${layout.frame}px;background-position:center;background-repeat:no-repeat;pointer-events:none`;
      // Filled stones glow in their own native colour; empty Socket0 holes stay plain.
      if(marker){cell.setAttribute('aria-label',marker.label);if(marker.index>0)cell.classList.add('uw-gem');paintIcon(cell,{sprite:['Socket',marker.index]});}
    }
    return;
  }
  // Every replacement invalidates an earlier atlas request, including clear/model paints.
  el.style.backgroundImage = '';
  if (el._uwSpin) { el.classList.remove('uw-spin', 'uw-spin-hot'); el.style.removeProperty('--uw-spin'); refreshSpinHover(); el._uwSpin = false; el.style.animation = ''; el.style.backgroundSize = ''; el.style.backgroundPosition = ''; }
  el.replaceChildren();
  if (!icon) return;
  if (icon.pendingLabel) {
    const label = div('uw-item-pending', el);
    label.textContent = icon.pendingLabel;
    label.style.cssText = 'font-size:10px;line-height:12px;overflow:hidden;max-height:100%;background:rgba(12,16,24,.8);pointer-events:none';
    label.style.color = icon.color || '#fff';
    return;
  }
  if (typeof icon === 'string') { el.style.backgroundImage = `url("${icon}")`; return; }
  if (icon.spin?.url) { paintSpin(el, icon.spin); return; }
  if (icon.url) { el.style.backgroundImage = `url("${icon.url}")`; return; }
  if (icon.canvas) { const c = icon.canvas; c.style.width = '100%'; c.style.height = '100%'; el.appendChild(c); return; }
  if (icon.el) { el.appendChild(icon.el); return; }
  if (icon.sprite) {
    const [g, i] = icon.sprite;
    const s = atlas.spriteNow(g, i, icon.dx || 0);
    if (s) { el.style.backgroundImage = `url("${s.url}")`; return; }
    atlas.sprite(g, i, icon.dx || 0).then(sp => { if (el._iconTok === tok && sp) el.style.backgroundImage = `url("${sp.url}")`; });
  }
}

let warnedMissing = new Set();

// ------------------------------------------------------------------------------------------ base control
/**
 * Base of every control. Binding API (docs/UIWIN.md): setText/getText/setTextColor/setFont, onClick/on/off/emit,
 * show/hide/setVisible, setEnabled, setChecked/isChecked, setImage/setImageState, setIcon, setGauge,
 * setTooltip, control(id) (descendant), controls(filter), box(), rect(), setRect/move, focus, data.
 */
export class UIControl {
  constructor(win, spec, parent) {
    this.win = win;
    this.spec = spec;
    this.parent = parent;
    this.type = spec.type;
    this.id = spec.id || '';
    this.children = [];
    this.data = {};          // free slot for systems
    this._h = Object.create(null);
    this.enabled = spec.enable !== false;
    this.visible = spec.visible !== false;
    this.checked = false;
    this.hover = false;
    this.pressed = false;
    this._text = undefined;   // code override of the title text
    this._color = null;       // code override of the title colour
    this._fontIdx = null;
    this._imgOverride = Object.create(null);
    this._rectOverride = null;
    this.images = Object.create(null);
    for (const im of spec.images || []) if (!(im.key in this.images) || im.tag === 'image') this.images[im.key] = im;
    this.titles = Object.create(null);
    for (const t of spec.titles || []) this.titles[t.state] = t;
    this.el = div(`uw-c uw-${this.type}`);
    if (this.id) this.el.dataset.id = this.id;
    this.el.style.zIndex = String(Math.max(0, Math.round(spec.layer || 0)));
    this.bg = null;
    this.txt = null;
    this.box = { x: 0, y: 0, w: 0, h: 0 };
  }

  // ------------------------------------------------------------ construction
  /** Build child controls (after the constructor). */
  build() {
    for (const cs of this.spec.children || []) {
      const c = createControl(this.win, cs, this);
      if (c) { this.children.push(c); this.el.appendChild(c.el); }
    }
    this.init();
    this._wire();
    this.refresh();
    return this;
  }
  /**
   * build() for idle-time pre-building (uiwin/prebuild.js): same result, but between children it asks `slice.over()` and
   * `await slice.yield()`s, and a big child is built the same way (appended first, filled in slices), so one idle slice
   * never constructs a whole large window.
   */
  async buildSliced(slice) {
    for (const cs of this.spec.children || []) {
      if (slice.over()) await slice.yield();
      if (specWeight(cs) < SLICE_NODES) {
        const c = createControl(this.win, cs, this);
        if (c) { this.children.push(c); this.el.appendChild(c.el); }
        continue;
      }
      const c = newControl(this.win, cs, this);
      this.children.push(c); this.el.appendChild(c.el);
      await c.buildSliced(slice);
    }
    this.init();
    this._wire();
    this.refresh();
    return this;
  }
  /** Type hook after children exist. */
  init() {}
  get interactive() { return false; }
  /** Does this control take the mouse? (intersect + image/interaction/tooltip) */
  get hitTest() {
    if (this.spec.intersect === false) return false;
    return this.interactive || Object.keys(this.images).length > 0 || !!this.spec.tooltip || !!this._tip || !!this._h.click || !!this._h.rclick || !!this._h.dblclick || !!this._h.over || !!this._drag || !!this._dropT;
  }
  _wire() {
    if (this._wired) return;
    this._wired = true;
    const el = this.el;
    el.addEventListener('pointerenter', (e) => { this.hover = true; this.refresh(); this.emit('over', e); this.win.mgr?.tooltips?.enter(this, e); });
    el.addEventListener('pointerleave', (e) => { this.hover = false; if (!this._capture) this.pressed = false; this.refresh(); this.emit('out', e); this.win.mgr?.tooltips?.leave(this, e); });
    el.addEventListener('pointermove', (e) => this.win.mgr?.tooltips?.move(this, e));
    el.addEventListener('pointerdown', (e) => this._onDown(e));
    el.addEventListener('pointerup', (e) => this._onUp(e));
    el.addEventListener('dblclick', (e) => { if (!this.enabled) return; if (this._h.dblclick) { e.stopPropagation(); this.emit('dblclick', e); } });
    el.addEventListener('contextmenu', (e) => { e.preventDefault(); if (!this.enabled) return; if (this._h.rclick) { e.stopPropagation(); this.emit('rclick', e); } });
    el.addEventListener('wheel', (e) => { if (this._h.wheel) { e.preventDefault(); e.stopPropagation(); this.emit('wheel', e, Math.sign(e.deltaY)); } }, { passive: false });
  }
  _onDown(e) {
    if (e.button !== 0 || !this.enabled) return;
    if (this._drag && this.win.mgr?.dnd?.pointerDown(this, e)) { e.stopPropagation(); return; }
    if (!this.interactive && !this._h.click && !this._h.down) return;
    e.stopPropagation();
    this.pressed = true;
    this._capture = true;
    try { this.el.setPointerCapture(e.pointerId); } catch { /* synthetic events */ }
    this.refresh();
    this.emit('down', e);
    this.pressStart?.(e);
  }
  _onUp(e) {
    if (e.button !== 0) return;
    if (!this._capture) return;
    this._capture = false;
    try { this.el.releasePointerCapture(e.pointerId); } catch { /* ignore */ }
    const inside = this._inside(e);
    const was = this.pressed;
    this.pressed = false;
    this.refresh();
    this.emit('up', e);
    this.pressEnd?.(e);
    if (was && inside && this.enabled) this.activate(e);
  }
  _inside(e) {
    const r = this.el.getBoundingClientRect();
    return e.clientX >= r.left && e.clientX < r.right && e.clientY >= r.top && e.clientY < r.bottom;
  }
  /** A completed click (type-specific behaviour then the 'click' event). */
  activate(e) { this.win.mgr?.sound?.(this.spec.props?.sound?.[0]); this.emit('click', e); }

  // ------------------------------------------------------------ layout
  /** Place inside the parent content box {w,h}. */
  layout(parentBox) {
    const b = this._rectOverride ? { x: this._rectOverride[0], y: this._rectOverride[1], w: this._rectOverride[2], h: this._rectOverride[3] } : controlBox(this.spec, parentBox);
    if (!b.w || !b.h) {
      const nat = this._naturalSize();
      if (nat) { if (!b.w) b.w = nat.w; if (!b.h) b.h = nat.h; }
    }
    this.box = b;
    const s = this.el.style;
    s.left = `${b.x}px`; s.top = `${b.y}px`; s.width = `${b.w}px`; s.height = `${b.h}px`;
    this.el.classList.toggle('uw-hidden', !this.visible);
    this.el.classList.toggle('uw-hit', this.hitTest);
    for (const c of this.children) c.layout(b);
    // viewport pattern (minimap map 512 in a 158 window, day/night strip 512 in a 45 dial): a control whose child
    // is at least twice its size clips its children. setClip(true|false) forces it.
    const clip = this._clip ?? (this.type !== '#root' && b.w > 0 && b.h > 0 && this.children.some(c => c.visible && (c.box.w >= 2 * b.w || c.box.h >= 2 * b.h)));
    this.el.style.overflow = clip ? 'hidden' : '';
    this.afterLayout?.();
    this.refresh();
  }
  /** Clip children to this control's rect (true), never (false), or automatic (null). */
  setClip(on) { this._clip = on == null ? undefined : !!on; if (this.parent) this.layout(this.parent.box); return this; }
  _naturalSize() {
    const im = this.images.none || Object.values(this.images)[0];
    const r = im && im.screen ? atlas.rect(im.screen, im.index) : null;
    if (r) return { w: r.w, h: r.h };
    return null;
  }

  // ------------------------------------------------------------ state & paint
  get state() {
    // Global checkbox art (etc_01 #303 none / #304 check): a disabled-but-checked box still shows the checkmark.
    // IMAGE_CHAIN.disable falls through to `none`, which hid ticks on "all" lists and cashshop boxinfo rows.
    if (!this.enabled) return this.checked ? 'check' : 'disable';
    if (this._blinkOn) return 'blink';
    if (this.checked) return this.pressed ? 'check_down' : this.hover && this.interactive ? 'check_over' : 'check';
    if (this.pressed) return 'down';
    if (this.hover && (this.interactive || this.images.over || this.titles.over)) return 'over';
    return 'none';
  }
  imageFor(state) {
    const chain = IMAGE_CHAIN[state] || [state, 'none'];
    for (const k of chain) {
      if (this._imgOverride[k] !== undefined) return this._imgOverride[k];
      if (this.images[k]) return this.images[k];
    }
    return this._imgOverride.none !== undefined ? this._imgOverride.none : null;
  }
  titleFor(state) {
    const base = this.titles.none || this.titles.title || Object.values(this.titles)[0] || null;
    const chain = TITLE_CHAIN[state] || [state, 'none'];
    let t = null;
    for (const k of chain) if (this.titles[k]) { t = this.titles[k]; break; }
    if (!base && !t) return null;
    return { ...(base || {}), ...(t || {}) };
  }
  /** Repaint image + text for the current state. */
  refresh() {
    this.paintImage();
    this.paintText();
  }
  paintImage(mode = 'stretch') {
    const img = this.imageFor(this.state);
    if (!img && !this.bg) return;
    if (!this.bg) { this.bg = div('uw-bg'); this.el.insertBefore(this.bg, this.el.firstChild); }
    const w = this.box.w, h = this.box.h;
    if (!img) { applySprite(this.bg, null); this._bgImg = null; return; }
    if (this._bgImg === img && this._bgW === w && this._bgH === h && this._bgPainted) return;
    this._bgImg = img; this._bgW = w; this._bgH = h; this._bgPainted = false;
    if (img.url || img.canvas) { applySprite(this.bg, { url: img.url, row: { w, h, m: [0, 0, 0, 0] } }, w, h); this._bgPainted = true; return; }
    const s = spriteNow(img);
    if (s) { applySprite(this.bg, s, w, h, mode); this._bgPainted = true; this._onSprite?.(s); return; }
    applySprite(this.bg, null);
    spriteLater(img).then(sp => {
      if (this._bgImg !== img) return;
      if (!sp) {
        // screen `null` / index -1 are placeholders the client fills at run time: not reported
        if (!img.screen || img.index < 0 || /^null$/i.test(img.screen)) return;
        const seen = (this.win.mgr && (this.win.mgr._missingSeen ||= new Set())) || warnedMissing;
        const k = `${img.screen}#${img.index}`;
        if (!seen.has(k)) { seen.add(k); this.win.mgr?.missingSprite?.(img, this); }
        return;
      }
      applySprite(this.bg, sp, this.box.w, this.box.h, mode);
      this._bgPainted = true;
      if ((!this.box.w || !this.box.h) && this.parent) this.layout(this.parent.box || this.parent.innerBox || { w: 0, h: 0 });
      this._onSprite?.(sp);
    });
  }
  /** Text of this control: code override, else the title/ref of the script. */
  getText() {
    if (this._text !== undefined) return this._text;
    const t = this.titles.none || this.titles.title || Object.values(this.titles).find(x => x.text != null || x.ref) || null;
    if (t) {
      if (t.text != null) return t.text;
      if (t.ref) return this.win.str(t.ref) ?? '';
    }
    if (this.spec.text != null) return this.spec.text;
    if (this.spec.ref) return this.win.str(this.spec.ref) ?? '';
    return '';
  }
  /** Text layout parameters (overridden by types). */
  textLayout(t) {
    const a = this.spec.align || t.align || { h: 'left', v: 'top' };
    return { h: a.h, v: a.v, x: 0, y: 0, w: this.box.w, hgt: this.box.h };
  }
  paintText() {
    const text = this.getText();
    if ((text == null || text === '') && !this.txt) return;
    const t = this.titleFor(this.state) || {};
    if (!this.txt) { this.txt = div('uw-t'); this.txt.appendChild(document.createElement('span')); this.el.insertBefore(this.txt, this.bg ? this.bg.nextSibling : this.el.firstChild); }
    const span = this.txt.firstChild;
    const L = this.textLayout(t);
    const font = this._fontIdx ?? t.font ?? 2;
    const lh = this.spec.props?.lineheight ? Number(this.spec.props.lineheight[0]) : (t.lineheight || 0);
    applyFont(this.txt, font, lh > 0 ? lh : 0);
    this.txt.style.color = this._color ? rgba(this._color) : rgba(t.color, '#fff');
    const pos = t.pos || [0, 0];
    const s = this.txt.style;
    s.left = `${L.x}px`; s.top = `${L.y}px`; s.width = `${L.w}px`; s.height = `${L.hgt}px`;
    s.justifyContent = L.h === 'center' ? 'center' : L.h === 'right' ? 'flex-end' : 'flex-start';
    s.alignItems = L.v === 'center' ? 'center' : L.v === 'bottom' ? 'flex-end' : 'flex-start';
    s.textAlign = L.h;
    s.paddingLeft = L.h === 'left' ? `${pos[0]}px` : '0';
    s.paddingRight = L.h === 'right' ? `${pos[0]}px` : '0';
    s.paddingTop = L.v === 'top' ? `${pos[1]}px` : '0';
    span.style.transform = L.v !== 'top' && pos[1] ? `translateY(${pos[1]}px)` : '';
    const multi = this.isMultiline(t);
    this.txt.classList.toggle('uw-wrap', multi && this.autoWrap(t));
    let str = multi ? String(text ?? '') : String(text ?? '').replace(/\n/g, ' ');
    // client layout tags in string-table texts ("<center>Enhancement", "<font=4>..."): centre the text, drop the tags
    if (/<\/?(?:center|font)[^>]*>/i.test(str)) {
      if (/<center>/i.test(str)) { s.justifyContent = 'center'; s.textAlign = 'center'; }
      str = str.replace(/<\/?(?:center|font)[^>]*>/gi, '');
    }
    if (this._rich) {
      span.replaceChildren();
      for (const r of markupRuns(str)) {
        if (r.br) { span.appendChild(document.createElement('br')); continue; }
        const e = document.createElement('span'); e.textContent = r.text; if (r.color) e.style.color = r.color; span.appendChild(e);
      }
    } else if (span.textContent !== str) span.textContent = str;
    this.txt.style.display = str ? '' : 'none';
  }
  isMultiline(t) {
    const p = this.spec.props || {};
    return /^true/i.test(p.multiline?.[0] || '') || !!t?.multiline || /^true/i.test(p.autoline?.[0] || '');
  }
  autoWrap(t) {
    const p = this.spec.props || {};
    return /^true/i.test(p.autoline?.[0] || '') || /^true/i.test(p.multiline?.[0] || '') || !!t?.multiline;
  }

  // ------------------------------------------------------------ events
  on(ev, fn) { (this._h[ev] ||= []).push(fn); if (['click', 'rclick', 'dblclick', 'over'].includes(ev)) this.el.classList.toggle('uw-hit', this.hitTest); return this; }
  off(ev, fn) { const a = this._h[ev]; if (a) this._h[ev] = fn ? a.filter(f => f !== fn) : []; return this; }
  once(ev, fn) { const w = (...a) => { this.off(ev, w); fn(...a); }; return this.on(ev, w); }
  emit(ev, ...args) {
    for (const f of (this._h[ev] || []).slice()) { try { f.call(this, ...args, this); } catch (err) { console.error(`[uiwin] ${this.win.name}.${this.id} ${ev} handler`, err); } }
    if (ev === 'click' || ev === 'change' || ev === 'select') this.win.emit?.(`control:${ev}`, this, ...args);
  }
  onClick(fn) { return this.on('click', fn); }
  onRightClick(fn) { return this.on('rclick', fn); }
  onDoubleClick(fn) { return this.on('dblclick', fn); }
  onChange(fn) { return this.on('change', fn); }

  // ------------------------------------------------------------ binding API
  setText(text, ...fmtArgs) {
    const v = text == null ? '' : fmtArgs.length ? formatString(text, ...fmtArgs) : String(text);
    if (this._text === v && !this._rich) return this;
    this._text = v; this._rich = false; this.paintText(); return this;
  }
  /** Text with client markup (<color=RRGGBB>..</color>, \n). */
  setRichText(text) { this._text = String(text ?? ''); this._rich = true; this.paintText(); return this; }
  /** Explicit DIL binding; unrelated points/cash and authored rich text retain their own colors. */
  setDil(value) { return this.setText(formatDil(value)).setTextColor(dilColor(value)); }
  /** Text from a string table: setTextRef({group:'NORMAL', cate, code}, ...printfArgs) */
  setTextRef(ref, ...args) { const s = this.win.str(ref); if (s == null) this.win.needStr(ref).then(() => this.setText(this.win.str(ref) ?? '', ...args)); else this.setText(s, ...args); return this; }
  resetText() { this._text = undefined; this._rich = false; this.paintText(); return this; }
  setTextColor(argbOrCss) { this._color = typeof argbOrCss === 'string' && !/^[0-9a-f]{8}$/i.test(argbOrCss) ? cssToArgb(argbOrCss) : Array.isArray(argbOrCss) ? argbOrCss : hexArgb(argbOrCss); this.paintText(); return this; }
  setFont(fontIndex) { this._fontIdx = fontIndex; this.paintText(); return this; }
  show() { return this.setVisible(true); }
  hide() { return this.setVisible(false); }
  setVisible(v) { v = !!v; if (this.visible === v) return this; this.visible = v; this.el.classList.toggle('uw-hidden', !v); if (v && this.parent) this.layout(this.parent.box); return this; }
  isVisible() { return this.visible && (!this.parent || this.parent.isVisible?.() !== false); }
  setEnabled(v) { const enabled = !!v; if (this.enabled === enabled) return this; this.enabled = enabled; this.pressed = false; this.refresh(); this.el.classList.toggle('uw-disabled', !this.enabled); return this; }
  enable() { return this.setEnabled(true); }
  disable() { return this.setEnabled(false); }
  setChecked(v, silent = true) { v = !!v; if (this.checked === v) return this; this.checked = v; this.refresh(); if (!silent) this.emit('change', v); return this; }
  isChecked() { return this.checked; }
  /** Replace the sprite of a state: setImage('none', 'etc_01', 34) or setImage('none', {url}) or setImage('none', null) to clear. */
  setImage(state, screenOrObj, index) {
    const k = state === 0 || state === '0' ? 'none' : String(state || 'none');
    let img = screenOrObj == null ? null : typeof screenOrObj === 'object' ? { ...screenOrObj } : { screen: screenOrObj, index: Number(index), color: this.images[k]?.color || null };
    if (img && img.color != null && !Array.isArray(img.color)) img.color = hexArgb(img.color);   // 'AARRGGBB' strings accepted
    if (img && img.index == null && img.screen) img.index = 0;
    this._imgOverride[k] = img;
    this._bgImg = undefined; this.el.classList.toggle('uw-hit', this.hitTest); this.refresh(); return this;
  }
  /** Shorthand: setSprite(group, index) sets the normal-state image. */
  setSprite(group, index) { return this.setImage('none', group, index); }
  clearImageOverrides() { this._imgOverride = Object.create(null); this._bgImg = undefined; this.refresh(); return this; }
  /** Icon on top of the control (items/skills): {sprite:[group,index]} | {url} | {canvas} | {el} | url | null. */
  setIcon(icon, { inset = 0 } = {}) {
    if (!this._icon) { this._icon = div('uw-icon', this.el); this._icon.style.zIndex = '1'; }
    const s = this._icon.style; s.left = s.top = `${inset}px`; s.width = s.height = `calc(100% - ${inset * 2}px)`;
    paintIcon(this._icon, icon);
    this._iconDesc = icon;
    return this;
  }
  getIcon() { return this._iconDesc || null; }
  /** Small count text at the bottom-right (stack size). */
  setCount(n) {
    if (!this._cnt) { this._cnt = div('uw-count', this.el); this._cnt.style.zIndex = '3'; }
    this._cnt.textContent = n == null || n === '' || n === 1 ? '' : String(n);
    return this;
  }
  /** Cooldown sweep 0..1 (fraction remaining). */
  setCooldown(frac) {
    if (!this._cool) { this._cool = div('uw-cool', this.el); this._cool.style.zIndex = '2'; }
    // opt-6: written only when it changed (the potion belt calls this with 0 for every empty cell every frame)
    const bg = cooldownBackground(frac);
    if (this._coolBg !== bg) { this._coolBg = bg; this._cool.style.background = bg; }
    return this;
  }
  /** Tooltip: string | ref {group,cate,code} | () => string|Element|{lines:[{text,color,font}]} */
  setTooltip(t) { this._tip = t; this.el.classList.toggle('uw-hit', this.hitTest); return this; }
  tooltip() {
    if (this._tip !== undefined) return typeof this._tip === 'function' ? this._tip(this) : (this._tip && this._tip.cate != null ? this.win.str(this._tip) : this._tip);
    if (this.spec.tooltip) return this.win.str(this.spec.tooltip);
    return null;
  }
  /** Blink between the normal and over/blink sprites (button `blink`/`blinktime`). */
  setBlink(on, ms = Number(this.spec.props?.blinktime?.[0]) || 500) {
    clearInterval(this._blinkT); this._blinkOn = false;
    if (on) this._blinkT = setInterval(() => { this._blinkOn = !this._blinkOn; this.refresh(); }, ms);
    this.refresh(); return this;
  }
  /** Gauge fraction 0..1 (processbar; other controls ignore it). */
  setGauge() { return this; }
  setValue(v) { this.value = v; return this; }
  getValue() { return this.value; }
  /** Override the rect [x, y, w, h] (parent-relative). */
  setRect(x, y, w, h) { this._rectOverride = [x, y, w ?? this.box.w, h ?? this.box.h]; if (this.parent) this.layout(this.parent.box); return this; }
  move(x, y) { return this.setRect(x, y); }
  resetRect() { this._rectOverride = null; if (this.parent) this.layout(this.parent.box); return this; }
  rect() { return [this.box.x, this.box.y, this.box.w, this.box.h]; }
  /** Screen rect in CSS pixels. */
  screenRect() { return this.el.getBoundingClientRect(); }

  // ------------------------------------------------------------ tree
  /** Descendant by id (first match, depth-first). */
  control(id) {
    if (id == null) return null;
    const lid = String(id).toLowerCase();
    for (const c of this.children) { if (c.id.toLowerCase() === lid) return c; }
    for (const c of this.children) { const r = c.control(id); if (r) return r; }
    return null;
  }
  /** Descendants matching a predicate / regex on id / id prefix. */
  controls(filter) {
    const out = [];
    const test = typeof filter === 'function' ? filter : filter instanceof RegExp ? (c) => filter.test(c.id) : filter == null ? () => true : (c) => c.id.toLowerCase().startsWith(String(filter).toLowerCase());
    const walk = (c) => { for (const k of c.children) { if (test(k)) out.push(k); walk(k); } };
    walk(this);
    return out;
  }
  forEach(fn) { const walk = (c) => { for (const k of c.children) { fn(k); walk(k); } }; walk(this); }
  /**
   * Instantiate this control as a template (the client builds rows/slots from hidden template controls such as
   * quickslot `slot`, `pan_dozen`, dekapass `*_` rows with `usetrail`). Every id in the copy gets `suffix`
   * appended ('slot' + '_3' -> 'slot_3', 'slot_base' -> 'slot_base_3'); ids ending in '_' just get the suffix
   * digits ('pan_row_' + '_3' -> 'pan_row_3'). The copy is visible, placed at (x, y) when given, and indexed so
   * win.control('slot_3') finds it. opts: { x, y, parent, visible, reindex }.
   * Bulk builders may pass reindex:false, then must call win._indexControls() before lookup/input or yielding.
   */
  cloneAs(suffix, { x, y, parent = this.parent, visible = true, reindex = true } = {}) {
    const sfx = String(suffix);
    const rename = (id) => (!id ? id : id.endsWith('_') ? id + sfx.replace(/^_/, '') : id + sfx);
    const copy = (s) => ({ ...s, id: rename(s.id), rect: s.rect.slice(), images: s.images.map(i => ({ ...i })), titles: s.titles.map(t => ({ ...t })), props: { ...s.props }, children: (s.children || []).map(copy) });
    const spec = copy(this.spec);
    spec.rect = [x ?? spec.rect[0], y ?? spec.rect[1], spec.rect[2], spec.rect[3]];
    spec.visible = visible;
    spec.cloneOf = this.id;
    const host = parent || this.win.root;
    const c = createControl(this.win, spec, host);
    host.children.push(c);
    host.el.appendChild(c.el);
    if (reindex) this.win._indexControls?.();
    c.layout(host.box);
    return c;
  }
  /** Remove this control (e.g. a clone) from its window. */
  remove() {
    if (this.parent) this.parent.children = this.parent.children.filter(c => c !== this);
    this.el.remove();
    this.dispose();
    this.win._indexControls?.();
  }
  dispose() {
    clearInterval(this._blinkT); clearInterval(this._rep); clearTimeout(this._repT);
    for (const c of this.children) c.dispose();
    this.disposed?.();
  }
}

function hexArgb(v) {
  const h = String(v ?? 'ffffffff').replace(/^#|^0x/i, '');
  const p = h.length <= 6 ? `ff${h.padStart(6, '0')}` : h.padStart(8, '0');
  return [parseInt(p.slice(0, 2), 16), parseInt(p.slice(2, 4), 16), parseInt(p.slice(4, 6), 16), parseInt(p.slice(6, 8), 16)];
}
function cssToArgb(css) {
  if (/^#/.test(css)) return hexArgb(css);
  const m = /rgba?\(([^)]+)\)/.exec(css);
  if (m) { const p = m[1].split(',').map(Number); return [Math.round((p[3] ?? 1) * 255), p[0], p[1], p[2]]; }
  return [255, 255, 255, 255];
}
export { hexArgb };

/** A control that ignores every call (returned by win.control() for unknown ids, so systems never crash). */
export class NullControl {
  constructor(win, id) { this.win = win; this.id = id; this.missing = true; this.children = []; this.data = {}; this.el = null; this.box = { x: 0, y: 0, w: 0, h: 0 }; }
}
const chain = function () { return this; };
for (const k of Object.getOwnPropertyNames(UIControl.prototype)) {
  if (k === 'constructor' || k in NullControl.prototype) continue;
  NullControl.prototype[k] = chain;
}
NullControl.prototype.getText = () => '';
NullControl.prototype.control = function (id) { return new NullControl(this.win, id); };
NullControl.prototype.controls = () => [];
NullControl.prototype.isChecked = () => false;
NullControl.prototype.getValue = () => undefined;
NullControl.prototype.rect = () => [0, 0, 0, 0];

/** A control that is constructed but not built yet (its caller builds it: build() or buildSliced()). */
export function newControl(win, spec, parent) {
  if (spec.kind === 'window') {
    const C = TYPES.window || UIControl;
    return new C(win, spec, parent);
  }
  const C = (spec.legacyKind ? TYPES['#legacy'] : TYPES[spec.type]) || UIControl;
  return new C(win, spec, parent);
}
/** Create a control (or null for property/unknown tags) and build it. */
export function createControl(win, spec, parent) {
  return newControl(win, spec, parent).build();
}

// Spec subtrees at least this large are built in slices by buildSliced(); the node count is cached per spec object.
const SLICE_NODES = 24;
const WEIGHTS = new WeakMap();
function specWeight(spec) {
  let w = WEIGHTS.get(spec);
  if (w == null) {
    w = 1;
    for (const c of spec.children || []) w += specWeight(c);
    WEIGHTS.set(spec, w);
  }
  return w;
}

// ------------------------------------------------------------------------------------------ simple types
export class UIPanel extends UIControl {}

export class UILabel extends UIControl {}

export class UIButton extends UIControl {
  get interactive() { return true; }
  init() {
    this.repeat = String(this.spec.props?.type?.[0]) === '1';
    if (/^true/i.test(this.spec.props?.blink?.[0] || '')) this.setBlink(true);
    this.el.classList.add('uw-hit');
  }
  pressStart() {
    if (!this.repeat) return;
    this.activate();
    this._repT = setTimeout(() => { this._rep = setInterval(() => { if (this.pressed && this.enabled) this.activate(); }, 70); }, 380);
  }
  pressEnd() { clearTimeout(this._repT); clearInterval(this._rep); }
  activate(e) {
    if (this.repeat && e) return;   // already fired on press
    super.activate(e);
  }
  /** Tabs/toggles: a checked button shows its `check` sprite and title. */
  select(v = true) { return this.setChecked(v); }
}

export class UICheckBox extends UIControl {
  get interactive() { return true; }
  init() { this.radio = String(this.spec.props?.type?.[0]) === '1'; }
  activate(e) {
    if (this.radio) {
      if (this.checked) return;
      for (const s of this.parent?.children || []) if (s !== this && s instanceof UICheckBox && s.radio && s.checked) s.setChecked(false, false);
      this.setChecked(true, false);
    } else this.setChecked(!this.checked, false);
    this.win.mgr?.sound?.(this.spec.props?.sound?.[0] ?? 0);
    this.emit('click', e);
  }
  // the box sprite is drawn at its own size (the rect also holds the caption)
  paintImage() {
    const img = this.imageFor(this.state);
    if (!this.bg) { this.bg = div('uw-bg uw-nat'); this.el.insertBefore(this.bg, this.el.firstChild); }
    this._boxImg = img;
    const place = (s) => {
      if (this._boxImg !== img) return;
      const w = s?.row?.w || 0, h = s?.row?.h || 0;
      const a = this.spec.align?.h || 'left';
      this.bg.style.width = `${w}px`; this.bg.style.height = `${h}px`;
      // align center with a caption (chat/ui_chatoption.txt "On Top", ...): the box stays in front of its caption;
      // only a caption-less box (a table cell) is centred in its rect
      const captioned = !!String(this.getText?.() || '').trim();
      this.bg.style.left = `${a === 'right' ? this.box.w - w : a === 'center' && !captioned ? Math.round((this.box.w - w) / 2) : 0}px`;
      this.bg.style.top = `${Math.max(0, Math.round((this.box.h - h) / 2))}px`;
      applySprite(this.bg, s, w, h, 'natural');
      this._boxW = w;
      if (this.txt) this.paintText();
    };
    if (!img) { applySprite(this.bg, null); return; }
    const s = spriteNow(img);
    if (s) place(s); else spriteLater(img).then(place);
  }
  textLayout(t) {
    const a = this.spec.align?.h || 'left';
    const bw = this._boxW || 0;
    if (a === 'right') return { h: 'left', v: 'top', x: 0, y: 0, w: Math.max(0, this.box.w - bw), hgt: this.box.h };
    if (a === 'center') return { h: 'left', v: 'top', x: bw, y: 0, w: this.box.w, hgt: this.box.h };
    return { h: 'left', v: 'top', x: bw, y: 0, w: Math.max(0, this.box.w - bw), hgt: this.box.h };
  }
}

/** processbar: its image is stretched to maxsize * value (min `minsize`) from the rect's left edge. */
export class UIGauge extends UIControl {
  init() { this.value = 1; this.max = Number(this.spec.props?.maxsize?.[0]) || this.spec.rect[2]; this.min = Number(this.spec.props?.minsize?.[0]) || 0; this.vertical = false; }
  setGauge(v, { vertical } = {}) {
    this.value = Math.max(0, Math.min(1, Number(v) || 0));
    if (vertical != null) this.vertical = !!vertical;
    this.afterLayout();
    return this;
  }
  /** setValue(cur, max) */
  setValue(cur, max) { return this.setGauge(max ? cur / max : cur); }
  getValue() { return this.value; }
  afterLayout() {
    if (!this.bg) return;
    const size = this.value > 0 ? Math.max(this.min, Math.round(this.max * this.value)) : 0;
    if (this.vertical) { this.bg.style.width = '100%'; this.bg.style.height = `${size}px`; this.bg.style.top = `${this.box.h - size}px`; }
    else { this.bg.style.width = `${size}px`; this.bg.style.height = '100%'; this.bg.style.top = '0'; }
  }
  paintImage() { super.paintImage(); this.afterLayout(); }
}

/** imagenumber: digits drawn with the ImageNumber_0N sprite fonts. */
const NUMBER_FONTS = { none: 'ImageNumber_01', timer: 'ImageNumber_01', italicblue: 'ImageNumber_02', italicred: 'ImageNumber_03', gold: 'ImageNumber_04', largegold: 'ImageNumber_05', gold_s: 'ImageNumber_06', green_s: 'ImageNumber_07' };
export class UINumber extends UIControl {
  init() {
    const p = this.spec.props || {};
    this.group = NUMBER_FONTS[String(p.fonttype?.[0] || 'none').toLowerCase()] || 'ImageNumber_01';
    this.space = Number(p.space?.[0]) || 12;
    this.kind = String(p.numbertype?.[0] || 'normal').toLowerCase();
    this.digits = Number(p.timerdigit?.[0]) || 4;
    this.row = div('uw-rows', this.el);
    this.value = null;
  }
  paintImage() {}   // the placeholder <image> (common#0, alpha 0) is not drawn
  /** Show a number (or a string of digits, ':' and '.'). */
  setNumber(n) { this.value = n; this._draw(String(n ?? '')); return this; }
  setValue(n) { return this.setNumber(n); }
  setText(t) { return this.setNumber(t); }
  /** Timer display: seconds -> MM:SS (timerdigit 4) or HH:MM:SS (6). */
  setTime(sec) {
    const s = Math.max(0, Math.floor(Number(sec) || 0));
    const hh = Math.floor(s / 3600), mm = Math.floor((s % 3600) / 60), ss = s % 60;
    const p2 = (v) => String(v).padStart(2, '0');
    return this.setNumber(this.digits >= 6 ? `${p2(hh)}:${p2(mm)}:${p2(ss)}` : `${p2(Math.floor(s / 60))}:${p2(ss)}`);
  }
  _draw(str, retried = false) {
    this.row.replaceChildren();
    const chars = [...str].filter(c => /[0-9:.]/.test(c));
    const total = chars.length * this.space;
    const a = this.spec.align?.h || 'left';
    let x = a === 'center' ? Math.round((this.box.w - total) / 2) : a === 'right' ? this.box.w - total : 0;
    // A glyph whose sprite is still loading repaints the whole number once it lands, so a redraw
    // (afterLayout, a new value) that replaced the waiting element never leaves that digit blank.
    const waiting = chars.map(c => (c === ':' ? 10 : c === '.' ? 11 : Number(c))).filter(i => !atlas.spriteNow(this.group, i));
    if (waiting.length && !retried) { const want = str; void Promise.all(waiting.map(i => atlas.sprite(this.group, i).catch(() => null))).then(() => { if (String(this.value ?? '') === want && this.row.isConnected) this._draw(want, true); }); }
    for (const c of chars) {
      const idx = c === ':' ? 10 : c === '.' ? 11 : Number(c);
      const r = atlas.rect(this.group, idx);
      const e = div('uw-icon', this.row);
      const w = r?.w || this.space, h = r?.h || this.box.h;
      e.style.left = `${x}px`; e.style.top = `${Math.round((this.box.h - h) / 2)}px`; e.style.width = `${w}px`; e.style.height = `${h}px`;
      paintIcon(e, { sprite: [this.group, idx] });
      x += this.space;
    }
  }
  afterLayout() { if (this.value != null) this._draw(String(this.value)); }
}

/** timerpanel: its sprite pulses between alphamin and alphamax (`tempo` = speed); start()/stop(). */
export class UITimerPanel extends UIControl {
  init() {
    const p = this.spec.props || {};
    this.aMin = (Number(p.alphamin?.[0]) || 0) / 255; this.aMax = (Number(p.alphamax?.[0] ?? 255)) / 255;
    this.tempo = Number(p.tempo?.[0]) || 4;
    this._t = 0;
    if (this.visible) this.start();
  }
  start(seconds = 0) { this.setVisible(true); this._until = seconds ? performance.now() + seconds * 1000 : 0; this.win.mgr?.animate(this); return this; }
  stop() { this.win.mgr?.unanimate(this); this.el.style.opacity = ''; return this; }
  tick(dt) {
    this._t += dt * this.tempo * 0.5;
    const k = 0.5 - 0.5 * Math.cos(this._t * Math.PI);
    this.el.style.opacity = String(this.aMin + (this.aMax - this.aMin) * k);
    if (this._until && performance.now() > this._until) { this.stop(); this.setVisible(false); }
  }
}

/** pivot: an invisible layout reference rect used by the client code. */
export class UIPivot extends UIControl {
  init() { this.el.style.display = 'none'; }
  get hitTest() { return false; }
}

/** tab: tab1/tab2 sprites = the strip with tab N selected; child buttons *_tab1, *_tab2 pick the tab. */
export class UITab extends UIControl {
  init() {
    this.value = 0;
    this.tabs = this.children.filter(c => /_tab\d+$/i.test(c.id)).sort((a, b) => Number(/(\d+)$/.exec(a.id)[1]) - Number(/(\d+)$/.exec(b.id)[1]));
    this.tabs.forEach((b, i) => { b.images = Object.create(null); b.on('click', () => this.select(i, false)); });
  }
  imageFor() { return this._imgOverride[`tab${this.value + 1}`] || this.images[`tab${this.value + 1}`] || this.images.tab1 || null; }
  select(i, silent = true) { i = Number(i) || 0; if (i === this.value) return this; this.value = i; this._bgImg = undefined; this.refresh(); if (!silent) this.emit('change', i); return this; }
  getValue() { return this.value; }
}

/**
 * Icon slots: `item` (inventory/equipment/reward cell, cellsize = icon size), `quickslot` (hotbar cell with
 * *_skill / *_grd / *_cool sub-panels), `emoti` (emoticon cell), `slotctrl` (character slot with class images).
 * setIcon/setCount/setCooldown; drag & drop via makeDraggable/acceptDrop (dnd.js).
 */
export class UISlot extends UIControl {
  get interactive() { return this.type !== 'slotctrl'; }
  init() {
    const cs = this.spec.props?.cellsize;
    this.cell = cs ? [Number(cs[0]) || 0, Number(cs[1]) || 0] : null;
    this.el.classList.add('uw-hit');
  }
  setIcon(icon, opts = {}) {
    if (this.type === 'quickslot') {
      const sub = this.children.find(c => /_skill$/i.test(c.id));
      if (sub) { sub.setIcon(icon, opts); this._iconDesc = icon; return this; }
    }
    if (this.cell && !opts.inset) {
      super.setIcon(icon, opts);
      const [cw, ch] = this.cell;
      const s = this._icon.style;
      s.width = `${cw}px`; s.height = `${ch}px`;
      s.left = `${Math.round((this.box.w - cw) / 2)}px`; s.top = `${Math.round((this.box.h - ch) / 2)}px`;
      return this;
    }
    return super.setIcon(icon, opts);
  }
  setCooldown(frac) {
    if (this.type === 'quickslot') {
      const sub = this.children.find(c => /_cool$/i.test(c.id));
      if (sub) { UIControl.prototype.setCooldown.call(sub, frac); return this; }
    }
    return super.setCooldown(frac);
  }
  /** slotctrl: show the class image of a class key (swordman, archeress, ...). */
  setClass(key) { this._cls = key; this._bgImg = undefined; this.refresh(); return this; }
  imageFor(state) {
    if (this.type === 'slotctrl') return this._cls != null ? (this.images[String(this._cls).toLowerCase()] || null) : null;
    return super.imageFor(state);
  }
}

/** noticectrl: a notice line scrolling right-to-left inside its rect. */
export class UINotice extends UIControl {
  init() { this.el.style.overflow = 'hidden'; this.m = div('uw-marquee', this.el); this.m.style.top = '0'; }
  setText(t, { font = 4, color = [255, 255, 255, 255], speed = 60 } = {}) {
    this.m.textContent = String(t ?? '');
    applyFont(this.m, font); this.m.style.color = rgba(color);
    this._x = this.box.w; this._speed = speed;
    this.setVisible(!!t);
    this.win.mgr?.animate(this);
    return this;
  }
  tick(dt) {
    const w = measureText(this.m.textContent, 4);
    this._x -= dt * this._speed;
    if (this._x < -w) this._x = this.box.w;
    this.m.style.transform = `translateX(${this._x}px)`;
  }
}

/** A <window> nested inside another window. */
export class UINestedWindow extends UIControl {
  layout(parentBox) {
    const b = computeWindowBox(this.spec, parentBox);
    this._rectOverride = [b.x, b.y, b.w, b.h];
    super.layout(parentBox);
  }
}

registerControlType('panel', UIPanel);
registerControlType('label', UILabel);
registerControlType('button', UIButton);
registerControlType('checkbox', UICheckBox);
registerControlType('processbar', UIGauge);
registerControlType('imagenumber', UINumber);
registerControlType('timerpanel', UITimerPanel);
registerControlType('pivot', UIPivot);
registerControlType('tab', UITab);
registerControlType('item', UISlot);
registerControlType('quickslot', UISlot);
registerControlType('emoti', UISlot);
registerControlType('slotctrl', UISlot);
registerControlType('noticectrl', UINotice);
registerControlType('window', UINestedWindow);
export { fontOf };

