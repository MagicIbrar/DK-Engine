// Scrolling / list-type controls: vscroll, slidebar, combobox, listbox, textbox/chattextbox, treectrl family,
// freeboardctrl (tables), maillist (+casebox template), itemslot (item grid). docs/UIWIN.md "Controls".
import { atlas } from '../atlas.js';
import { UIControl, UIPanel, UIButton, registerControlType, div, rgba, applySprite, paintIcon } from './controls.js';
import { applyFont, measureText } from './fonts.js';
import { markupRuns } from './strings.js';

const endsWith = (c, re) => re.test(c.id || '');
const titleStyle = (el, t, fallbackFont = 2, lh = 0) => {
  applyFont(el, t?.font ?? fallbackFont, lh);
  el.style.color = rgba(t?.color, '#fff');
};
function spriteOf(img, cb) {
  if (!img || !img.screen || img.index < 0) { cb(null); return; }
  const s = atlas.tintedNow(img.screen, img.index, img.color);
  if (s) cb(s); else atlas.tinted(img.screen, img.index, img.color).then(cb);
}
function paintBox(el, img, w, h) { spriteOf(img, s => applySprite(el, s, w, h)); }

// ------------------------------------------------------------------------------------------ vscroll
/**
 * vscroll: up button (*_upbtn), down button (*_downbtn), thumb panel (*_bar). Range 0..max (`maxvalue`), step
 * `buttontick`. The thumb keeps its script height and travels between the buttons. Linked to its parent list.
 */
export class UIScroll extends UIControl {
  get interactive() { return true; }
  init() {
    const p = this.spec.props || {};
    this.max = Math.max(0, Number(p.maxvalue?.[0]) || 0);
    this.tick = Math.max(1, Number(p.buttontick?.[0]) || 1);
    this.value = 0;
    this.up = this.children.find(c => endsWith(c, /_?up(btn)?$/i) || endsWith(c, /upbtn/i));
    this.down = this.children.find(c => endsWith(c, /_?down(btn)?$/i) || endsWith(c, /downbtn/i));
    this.bar = this.children.find(c => c instanceof UIPanel && endsWith(c, /_bar$/i)) || this.children.find(c => c instanceof UIPanel && c.spec.moveable);
    this.up?.on('click', () => this.setValue(this.value - this.tick, false));
    this.down?.on('click', () => this.setValue(this.value + this.tick, false));
    if (this.bar) {
      this.bar.el.classList.add('uw-hit');
      this.bar.el.addEventListener('pointerdown', (e) => {
        if (e.button !== 0) return;
        e.stopPropagation();
        this.bar.pressed = true; this.bar.refresh();
        const y0 = e.clientY, v0 = this.value;
        const sc = this.win.mgr?.scale || 1;
        const move = (ev) => {
          const tr = this._track();
          const span = tr.len - (this.bar.box.h || 0);
          if (span <= 0 || !this.max) return;
          this.setValue(Math.round(v0 + ((ev.clientY - y0) / sc / span) * this.max), false);
        };
        const up = () => { this.bar.pressed = false; this.bar.refresh(); removeEventListener('pointermove', move); removeEventListener('pointerup', up); };
        addEventListener('pointermove', move); addEventListener('pointerup', up);
      });
    }
    this.el.addEventListener('wheel', (e) => { e.preventDefault(); e.stopPropagation(); this.setValue(this.value + Math.sign(e.deltaY) * this.tick, false); }, { passive: false });
  }
  activate(e) {
    // click on the track: page towards the click
    if (!this.bar || !e) return;
    const r = this.bar.el.getBoundingClientRect();
    if (e.clientY < r.top) this.setValue(this.value - Math.max(this.tick, this.page || 1), false);
    else if (e.clientY > r.bottom) this.setValue(this.value + Math.max(this.tick, this.page || 1), false);
  }
  _partBox(c) {
    let [x, y, w, h] = c.spec.rect;
    if (x > 0 && x === this.spec.rect[0]) x = 0;          // a few scripts give the parts in the list's space
    if (y < 0) y = this.box.h + y;
    if (!w || !h) { const r = c.images.none && atlas.rect(c.images.none.screen, c.images.none.index); if (r) { w ||= r.w; h ||= r.h; } }
    if (!w) w = this.box.w;
    return { x, y, w, h };
  }
  _track() {
    const ub = this.up ? this.up.box : { y: 0, h: 0 };
    const top = this.up ? ub.y + ub.h : 0;
    const bottom = this.down ? this.down.box.y : this.box.h;
    return { top, len: Math.max(0, bottom - top) };
  }
  layout(parentBox) {
    // a vscroll with an empty rect sizes itself from its parent (right edge, full height)
    let [x, y, w, h] = this.spec.rect;
    const kids = this.children.map(c => c.spec.rect);
    if (!w) w = Math.max(0, ...kids.map(r => r[2])) || 12;
    if (!h) h = parentBox.h - y * 2;
    const tall = Math.max(0, ...kids.map(r => (r[1] > 0 ? r[1] + r[3] : 0)));
    if (tall > h + 1 && this.spec.rect[3] > 0) h = Math.min(parentBox.h - y, tall);
    this._rectOverride = [x, y, w, h];
    super.layout(parentBox);
  }
  afterLayout() {
    for (const c of [this.up, this.down, this.bar]) {
      if (!c) continue;
      const b = this._partBox(c);
      c.box = b;
      const s = c.el.style; s.left = `${b.x}px`; s.top = `${b.y}px`; s.width = `${b.w}px`; s.height = `${b.h}px`;
    }
    this._placeThumb();
  }
  _placeThumb() {
    if (!this.bar) return;
    const tr = this._track();
    const bh = this.bar.box.h || 0;
    const y = tr.top + (this.max ? (this.value / this.max) * Math.max(0, tr.len - bh) : 0);
    this.bar.box.y = y;
    this.bar.el.style.top = `${Math.round(y)}px`;
    this.bar.el.style.visibility = this.max > 0 || this.showEmptyThumb ? '' : 'hidden';
    this.up?.setEnabled(this.value > 0 || !this.max ? this.value > 0 : true);
    this.down?.setEnabled(this.value < this.max);
  }
  /** Range 0..max (e.g. lines - visibleLines). page = visible lines (track click step). */
  setRange(max, page) {
    this.max = Math.max(0, Math.floor(Number(max) || 0));
    if (page != null) this.page = page;
    if (this.value > this.max) this.value = this.max;
    this._placeThumb();
    return this;
  }
  setValue(v, silent = true) {
    const nv = Math.max(0, Math.min(this.max, Math.round(Number(v) || 0)));
    if (nv === this.value) { this._placeThumb(); return this; }
    this.value = nv;
    this._placeThumb();
    if (!silent) this.emit('change', nv);
    return this;
  }
  getValue() { return this.value; }
}

// ------------------------------------------------------------------------------------------ slidebar
/** slidebar: value min..max, thumb x in `minmaxpos` [x0, x1]; minus/plus buttons step 1 (auto-repeat). */
export class UISlider extends UIControl {
  get interactive() { return true; }
  init() {
    const p = this.spec.props || {};
    this.min = Number(p.min?.[0]) || 0; this.max = Number(p.max?.[0] ?? 100);
    const mm = p.minmaxpos || [0, this.spec.rect[2]];
    this.x0 = Number(mm[0]) || 0; this.x1 = Number(mm[1]) || this.spec.rect[2];
    this.step = 1;
    this.value = this.min;
    this.thumb = this.children.find(c => c instanceof UIPanel && (c.spec.moveable || /_bar$/i.test(c.id)));
    const btns = this.children.filter(c => c instanceof UIButton);
    this.minus = btns.find(b => /minus|left|down/i.test(b.id)) || btns[0];
    this.plus = btns.find(b => /plus|right|up/i.test(b.id)) || btns[1];
    const interval = Number(p.repeat_interval?.[0]) || 100;
    for (const [b, d] of [[this.minus, -1], [this.plus, 1]]) {
      if (!b) continue;
      b.repeat = true;
      b.pressStart = () => { this.setValue(this.value + d * this.step, false); b._repT = setTimeout(() => { b._rep = setInterval(() => { if (b.pressed) this.setValue(this.value + d * this.step, false); }, interval); }, 350); };
      b.activate = () => {};
    }
    if (this.thumb) {
      this.thumb.el.classList.add('uw-hit');
      this.thumb.el.addEventListener('pointerdown', (e) => {
        if (e.button !== 0) return;
        e.stopPropagation();
        this.thumb.pressed = true; this.thumb.refresh();
        const x0 = e.clientX, v0 = this.value, sc = this.win.mgr?.scale || 1;
        const move = (ev) => {
          const span = this.x1 - this.x0;
          if (span <= 0) return;
          this.setValue(v0 + ((ev.clientX - x0) / sc / span) * (this.max - this.min), false);
        };
        const up = () => { this.thumb.pressed = false; this.thumb.refresh(); removeEventListener('pointermove', move); removeEventListener('pointerup', up); this.emit('commit', this.value); };
        addEventListener('pointermove', move); addEventListener('pointerup', up);
      });
    }
  }
  activate(e) {
    if (!e || !this.thumb) return;
    const r = this.el.getBoundingClientRect(), sc = this.win.mgr?.scale || 1;
    const x = (e.clientX - r.left) / sc - (this.thumb.box.w || 0) / 2;
    this.setValue(this.min + ((x - this.x0) / Math.max(1, this.x1 - this.x0)) * (this.max - this.min), false);
    this.emit('commit', this.value);
  }
  afterLayout() { this._place(); }
  _place() {
    if (!this.thumb) return;
    const f = this.max > this.min ? (this.value - this.min) / (this.max - this.min) : 0;
    const x = Math.round(this.x0 + f * (this.x1 - this.x0));
    this.thumb.box.x = x;
    this.thumb.el.style.left = `${x}px`;
  }
  setRange(min, max) { this.min = Number(min); this.max = Number(max); return this.setValue(this.value); }
  setValue(v, silent = true) {
    let nv = Math.max(this.min, Math.min(this.max, Number(v) || 0));
    nv = Math.round(nv / this.step) * this.step;
    const changed = nv !== this.value;
    this.value = nv;
    this._place();
    if (changed && !silent) this.emit('change', nv);
    return this;
  }
  getValue() { return this.value; }
}

// ------------------------------------------------------------------------------------------ combobox
/**
 * combobox: iteminfo rect = the selected-text box; nodeinfo selrect = one dropdown row, btnrect = the arrow,
 * images board_body (dropdown panel), btn_none/btn_over/btn_down (arrow). setItems/select/getValue, 'change'.
 */
export class UICombo extends UIControl {
  get interactive() { return true; }
  init() {
    const ex = this.spec.extra || {};
    this.info = ex.iteminfo?.[0] || { rect: [0, 0, this.spec.rect[2], this.spec.rect[3]], items: [] };
    this.node = ex.nodeinfo || { selrect: [0, 0, this.spec.rect[2], 16], btnrect: [this.spec.rect[2] - 14, 2, 12, 12], images: [] };
    this.nimg = Object.fromEntries((this.node.images || []).map(i => [i.key, i]));
    // item captions: literal `text`, or a string-table `string cate code` ref (preloaded by collectRefs)
    this.items = (this.info.items || []).map(it => ({ text: it.text ?? (it.ref ? this.win?.mgr?.strings?.get(it.ref) ?? '' : ''), value: it.data ?? it.index, id: it.id, ref: it.ref }));
    this.index = this.items.length ? 0 : -1;
    this.label = div('uw-t', this.el);
    this.label.appendChild(document.createElement('span'));
    this.arrow = div('uw-bg', this.el);
    this.arrow.style.zIndex = '2';
    this._arrowState = 'btn_none';
    this.el.addEventListener('pointerenter', () => { this._arrowState = 'btn_over'; this._paintArrow(); });
    this.el.addEventListener('pointerleave', () => { this._arrowState = 'btn_none'; this._paintArrow(); });
  }
  imageFor() { return null; }   // the combobox itself has no body sprite (its panel sits behind it)
  pressStart() { this._arrowState = 'btn_down'; this._paintArrow(); }
  pressEnd() { this._arrowState = this.hover ? 'btn_over' : 'btn_none'; this._paintArrow(); }
  activate() { this.win.mgr?.sound?.(0); if (this._drop) this.closeList(); else this.openList(); }
  afterLayout() {
    const [ix, iy, iw, ih] = this.info.rect;
    const s = this.label.style; s.left = `${ix}px`; s.top = `${iy}px`; s.width = `${iw || this.box.w}px`; s.height = `${ih || this.box.h}px`;
    s.alignItems = 'center'; s.paddingLeft = '3px';
    const [bx, by, bw, bh] = this.node.btnrect;
    const a = this.arrow.style; a.left = `${bx}px`; a.top = `${by}px`; a.width = `${bw}px`; a.height = `${bh}px`;
    this._paintArrow();
    this._paintLabel();
  }
  _paintArrow() { const img = this.nimg[this._arrowState] || this.nimg.btn_none; paintBox(this.arrow, img, this.node.btnrect[2], this.node.btnrect[3]); }
  _font() { const t = this.titles.none; return t?.font ?? 2; }
  _paintLabel() {
    const t = this.titles.none;
    titleStyle(this.label, t, 2);
    this.label.firstChild.textContent = this.index >= 0 ? String(this.items[this.index]?.text ?? '') : '';
  }
  paintText() {}
  /** items: array of strings or {text, value}. */
  setItems(items, keepIndex = false) {
    this.items = (items || []).map(it => (typeof it === 'object' && it ? { ...it, text: it.text ?? String(it.value ?? '') } : { text: String(it), value: it }));
    if (!keepIndex || this.index >= this.items.length) this.index = this.items.length ? 0 : -1;
    this._paintLabel();
    return this;
  }
  select(i, silent = true) {
    const n = Math.max(-1, Math.min(this.items.length - 1, Number(i)));
    const changed = n !== this.index;
    this.index = n; this._paintLabel();
    if (changed && !silent) this.emit('change', n, this.items[n]);
    return this;
  }
  /** Select the item whose value equals v. */
  selectValue(v, silent = true) { const i = this.items.findIndex(it => it.value === v || String(it.value) === String(v)); return i >= 0 ? this.select(i, silent) : this; }
  getSelected() { return this.index; }
  getValue() { return this.items[this.index]?.value; }
  getText() { return this.items[this.index]?.text ?? ''; }
  openList() {
    const mgr = this.win.mgr;
    if (!mgr) return;
    mgr.closePopups?.();
    const [, , sw, sh] = this.node.selrect;
    const rowH = sh || 16, w = sw || this.box.w;
    const drop = div('uw-drop', mgr.layer);
    const r = this.el.getBoundingClientRect();
    const tl = mgr.toLayer(r.left, r.top), br = mgr.toLayer(r.right, r.bottom);
    const maxRows = 12;
    const n = Math.min(this.items.length, maxRows);
    const h = Math.max(rowH, n * rowH);
    let top = br.y;
    if (top + h > mgr.screen.h) top = tl.y - h;
    drop.style.left = `${Math.round(tl.x)}px`; drop.style.top = `${Math.round(top)}px`;
    drop.style.width = `${w}px`; drop.style.height = `${h}px`;
    const body = div('uw-bg', drop);
    paintBox(body, this.nimg.board_body, w, h);
    if (!this.nimg.board_body) body.style.background = 'rgba(12,10,8,.95)';
    const rows = div('uw-rows', drop);
    rows.style.pointerEvents = 'auto';
    let first = Math.max(0, Math.min(this.index - Math.floor(maxRows / 2), this.items.length - maxRows));
    const paint = () => {
      rows.replaceChildren();
      for (let k = 0; k < n; k++) {
        const i = first + k;
        const it = this.items[i];
        if (!it) break;
        const row = div('uw-row', rows);
        row.style.top = `${k * rowH}px`; row.style.height = `${rowH}px`; row.style.width = `${w}px`; row.style.lineHeight = `${rowH}px`; row.style.paddingLeft = '3px';
        applyFont(row, this._font(), rowH);
        row.style.color = rgba(i === this.index ? this.titles.check?.color || this.titles.over?.color : this.titles.none?.color, '#fff');
        row.textContent = String(it.text ?? '');
        row.addEventListener('pointerdown', (e) => { e.stopPropagation(); });
        row.addEventListener('click', (e) => { e.stopPropagation(); this.closeList(); this.select(i, false); });
      }
    };
    paint();
    drop.addEventListener('wheel', (e) => { e.preventDefault(); first = Math.max(0, Math.min(this.items.length - n, first + Math.sign(e.deltaY))); paint(); }, { passive: false });
    this._drop = drop;
    mgr.popup?.(drop, () => { this._drop = null; });
  }
  closeList() { if (this._drop) { this._drop.remove(); this._drop = null; } }
  disposed() { this.closeList(); }
}

// ------------------------------------------------------------------------------------------ listbox
/**
 * listbox: rows `nodeheight` high and `nodewidth` wide, text inset `offset`; titles none/over/check style the
 * rows; its vscroll child scrolls. setItems([...]) with strings or {text, color, cols:[{text,width,align,color}], data}.
 */
export class UIList extends UIControl {
  get interactive() { return true; }
  init() {
    const p = this.spec.props || {};
    this.rowH = Number(p.nodeheight?.[0]) || 16;
    this.rowW = Number(p.nodewidth?.[0]) || 0;
    this.offset = Number(p.offset?.[0]) || 0;
    this.items = [];
    this.top = 0;
    this.sel = -1;
    this.hot = -1;
    this.rows = div('uw-rows');
    this.el.insertBefore(this.rows, this.el.firstChild);
    this.rowActions = null;   // optional [{ label: string | (i, item) => string, onClick(i, item), show?(i, item), badge? }]: small green buttons on the hovered AND the selected row
    this.scroll = this.children.find(c => c instanceof UIScroll) || null;
    this.scroll?.on('change', v => { this.top = v; this.render(); });
    this.el.addEventListener('wheel', (e) => { e.preventDefault(); e.stopPropagation(); this.scrollBy(Math.sign(e.deltaY)); }, { passive: false });
  }
  /** Show row actions on `row` (item i). `interactive=false` keeps badge-only actions (Global world-map EVENT purple badge always far-right). */
  _attachActions(row, i, interactive = true) {
    const acts = this.rowActions; if (!acts?.length || !row) return;
    if (row.closest('.uw-map-npc-list')) {
      const mode = interactive ? 'interactive' : 'badges';
      if (row.dataset.uwMapActions === mode) return;
      row.dataset.uwMapActions = mode;
    }
    row.querySelector(':scope > .uw-rowactions')?.remove();
    const it = this.items[i], box = document.createElement('div'); box.className = 'uw-rowactions';
    for (const a of acts) {
      if (a.show && !a.show(i, it)) continue;
      if (!interactive && !a.badge) continue;
      const b = document.createElement('div'), label = typeof a.label === 'function' ? a.label(i, it) : a.label;
      b.className = a.badge ? 'uw-rowbadge' : 'uw-rowaction'; b.textContent = label;
      if(a.badge && a.sprite){
        b.setAttribute('aria-label',label);b.classList.add('uw-rowbadge-sprite');
        const [screen,index]=a.sprite;
        spriteOf({screen,index},sprite=>{if(sprite){applySprite(b,sprite,37,14,'natural');b.textContent='';}});
      }
      if (!a.badge) {
        b.addEventListener('pointerdown', (e) => e.stopPropagation());
        b.addEventListener('click', (e) => { e.stopPropagation(); this.win.mgr?.sound?.(0); this.select(i, false); a.onClick?.(i, this.items[i]); });
        b.addEventListener('dblclick', (e) => e.stopPropagation());
      }
      box.appendChild(b);
    }
    if (box.childElementCount) row.appendChild(box);
  }
  _detachActions(row, i) {
    if (i === this.sel) return;
    // Drop interactive buttons on leave, keep badges always visible (Global EVENT / siege badge).
    if (this.rowActions?.some(a => a.badge)) this._attachActions(row, i, false);
    else row.querySelector(':scope > .uw-rowactions')?.remove();
  }
  // Rows are laid out over the vscroll child's height when the script gives it one (Global ui_new_mapwnd.txt list_npclist:
  // listbox 478 tall, vscroll 460 with its down button at 448 = 32 rows of 14; the 18 px under it belong to the
  // Transparency row lbl_silde / pan_silde at y 530). Lists without a sized vscroll keep their own height.
  get visibleRows() { const sh = this.scroll?.box?.h; const h = sh > 0 ? Math.min(this.box.h, sh) : this.box.h; return Math.max(1, Math.floor(h / this.rowH)); }
  scrollBy(d) { this.setTop(this.top + d); }
  setTop(t) {
    this.top = Math.max(0, Math.min(Math.max(0, this.items.length - this.visibleRows), t));
    this.scroll?.setValue(this.top);
    this.render();
    return this;
  }
  afterLayout() { this._range(); this.render(); }
  _range() { this.scroll?.setRange(Math.max(0, this.items.length - this.visibleRows), this.visibleRows); }
  setItems(items) {
    this.items = (items || []).map(it => (typeof it === 'object' && it ? it : { text: String(it) }));
    if (this.sel >= this.items.length) this.sel = -1;
    this._range();
    this.setTop(this.top);
    return this;
  }
  addItem(it) { this.items.push(typeof it === 'object' ? it : { text: String(it) }); this._range(); this.render(); return this; }
  clear() { this.items = []; this.sel = -1; this.top = 0; this._range(); this.render(); return this; }
  select(i, silent = true) {
    this.sel = Math.max(-1, Math.min(this.items.length - 1, Number(i)));
    if (this.sel >= 0 && (this.sel < this.top || this.sel >= this.top + this.visibleRows)) this.setTop(this.sel);
    this.render();
    if (!silent) this.emit('select', this.sel, this.items[this.sel]);
    return this;
  }
  getSelected() { return this.sel; }
  getValue() { return this.items[this.sel]?.data ?? this.items[this.sel]?.value; }
  rowTitle(i) {
    const t = i === this.sel ? (this.titles.check || this.titles.over) : i === this.hot ? this.titles.over : null;
    return { ...(this.titles.none || {}), ...(t || {}) };
  }
  paintText() {}
  paintImage() {}
  render() {
    if (!this.rows) return;
    this.rows.replaceChildren();
    const n = this.visibleRows;
    const w = this.rowW || this.box.w;
    for (let k = 0; k < n; k++) {
      const i = this.top + k;
      const it = this.items[i];
      if (!it) break;
      const row = div('uw-row', this.rows);
      row.style.top = `${k * this.rowH}px`; row.style.height = `${this.rowH}px`; row.style.width = `${w}px`;
      const t = this.rowTitle(i);
      titleStyle(row, t, 2, this.rowH);
      if (it.color) row.style.color = Array.isArray(it.color) ? rgba(it.color) : it.color;
      if (i === this.sel && this.images.check) { const b = div('uw-bg', row); paintBox(b, this.images.check, w, this.rowH); }
      if (it.cols) {
        let x = this.offset;
        for (const c of it.cols) {
          const cell = div('uw-cell', row);
          cell.style.left = `${x}px`; cell.style.width = `${c.width || 60}px`; cell.style.textAlign = c.align || 'left';
          if (c.color) cell.style.color = Array.isArray(c.color) ? rgba(c.color) : c.color;
          cell.textContent = String(c.text ?? '');
          x += c.width || 60;
        }
      } else {
        const s = document.createElement('span');
        s.style.position = 'absolute'; s.style.left = `${this.offset}px`; s.style.right = '0';
        const align = this.spec.align?.h || t.align?.h;
        if (align === 'center') { s.style.left = '0'; s.style.textAlign = 'center'; }
        if (it.icon) { const ic = div('uw-icon', row); ic.style.left = `${this.offset}px`; ic.style.top = '1px'; ic.style.width = ic.style.height = `${this.rowH - 2}px`; paintIcon(ic, it.icon); s.style.left = `${this.offset + this.rowH + 2}px`; }
        s.textContent = String(it.text ?? '');
        row.appendChild(s);
      }
      // hover restyles in place (a full render() here swallowed clicks: the row was replaced mid-click)
      const restyle = () => { titleStyle(row, this.rowTitle(i), 2, this.rowH); if (it.color) row.style.color = Array.isArray(it.color) ? rgba(it.color) : it.color; };
      row.addEventListener('pointerenter', () => { this.hot = i; restyle(); this._attachActions(row, i); });
      row.addEventListener('pointerleave', () => { if (this.hot === i) { this.hot = -1; restyle(); } this._detachActions(row, i); });
      row.addEventListener('pointerdown', (e) => { if (e.button === 0) e.stopPropagation(); });
      row.addEventListener('click', (e) => { e.stopPropagation(); this.win.mgr?.sound?.(0); this.select(i, false); });
      row.addEventListener('dblclick', (e) => { e.stopPropagation(); this.emit('dblclick', i, this.items[i]); });
      row.addEventListener('contextmenu', (e) => { e.preventDefault(); e.stopPropagation(); this.emit('rclick', i, this.items[i], e); });
      // Badges always on; interactive rowActions only on hovered / selected (Global world-map EVENT badge).
      if (this.rowActions) this._attachActions(row, i, i === this.hot || i === this.sel);
    }
  }
}

// ------------------------------------------------------------------------------------------ textbox
/**
 * textbox / chattextbox: lines of text (`fonttype` font, `color`, `lineheight`, `margin mx my`, `autoline`
 * wrap, `maxline` cap) scrolled by its vscroll child. inputmode true makes it an editable text area.
 * addLine(text, color) / setText / clear / scrollToEnd; getText() for input boxes.
 */
export class UITextBox extends UIControl {
  get interactive() { return true; }
  init() {
    const p = this.spec.props || {};
    this.font = Number(p.fonttype?.[0] ?? p.font_type?.[0]) || 2;
    this.color = p.color?.[0] || 'ffffffff';
    this.lh = Number(p.lineheight?.[0]) || 15;
    this.margin = [Number(p.margin?.[0]) || 0, Number(p.margin?.[1]) || 0];
    this.wrap = !/^false/i.test(p.autoline?.[0] || 'true');
    this.maxLines = Number(p.maxline?.[0]) || 0;
    this.input = /^true/i.test(p.inputmode?.[0] || '');
    this.lines = [];
    this.scroll = this.children.find(c => c instanceof UIScroll) || null;
    this.view = div('uw-rows');
    this.el.insertBefore(this.view, this.el.firstChild);
    this.content = div('', this.view);
    this.content.style.position = 'absolute'; this.content.style.left = '0'; this.content.style.right = '0';
    applyFont(this.content, this.font, this.lh);
    this.content.style.color = rgba(hex(this.color));
    this.content.style.whiteSpace = this.wrap ? 'pre-wrap' : 'pre';
    this.content.style.wordBreak = 'break-word';
    this.top = 0;
    this.scroll?.on('change', v => { this.top = v; this._place(); });
    this.el.addEventListener('wheel', (e) => { e.preventDefault(); e.stopPropagation(); this.setTop(this.top + Math.sign(e.deltaY) * 2); }, { passive: false });
    if (this.input) {
      this.area = document.createElement('textarea');
      this.area.className = 'uw-edit';
      applyFont(this.area, this.font, this.lh);
      this.area.style.color = rgba(hex(this.color));
      const ml = Number(p.maxlength?.[0]); if (ml) this.area.maxLength = ml;
      this.area.addEventListener('input', () => this.emit('change', this.area.value));
      this.area.addEventListener('keydown', (e) => { e.stopPropagation(); if (e.key === 'Escape') this.area.blur(); });
      this.view.appendChild(this.area);
      this.content.style.display = 'none';
    }
  }
  paintText() {}
  afterLayout() {
    const [mx, my] = this.margin;
    const sw = this.scroll ? this.scroll.box.w : 0;
    const v = this.view.style;
    v.left = `${mx}px`; v.top = `${my}px`; v.right = `${mx + sw}px`; v.bottom = `${my}px`;
    this._range();
  }
  get visibleLines() { return Math.max(1, Math.floor((this.box.h - this.margin[1] * 2) / this.lh)); }
  _totalLines() { if (this._dirty) this._syncLines(); return Math.max(this.lines.length, Math.round((this.content.scrollHeight || 0) / this.lh)); }
  /** Apply what the lines added since the last sync owe the view (scrollbar range, scroll-to-end): once per batch, not once per line. */
  _syncLines() {
    this._dirty = false; this._trimmed = false;
    this._range();
    if (this._atEnd) this.scrollToEnd();
  }
  _range() { this.scroll?.setRange(Math.max(0, this._totalLines() - this.visibleLines), this.visibleLines); this._place(); }
  _place() { this.content.style.top = `${-this.top * this.lh}px`; }
  setTop(t) { this.top = Math.max(0, Math.min(Math.max(0, this._totalLines() - this.visibleLines), Math.round(t))); this.scroll?.setValue(this.top); this._place(); return this; }
  scrollToEnd() { return this.setTop(1e9); }
  _renderLine(l) {
    const d = document.createElement('div');
    d.style.minHeight = `${this.lh}px`;
    if (l.color) d.style.color = Array.isArray(l.color) ? rgba(l.color) : /^[0-9a-f]{8}$/i.test(l.color) ? rgba(hex(l.color)) : l.color;
    for (const r of markupRuns(l.text)) {
      if (r.br) { d.appendChild(document.createElement('br')); continue; }
      const s = document.createElement('span'); s.textContent = r.text; if (r.color) s.style.color = r.color; d.appendChild(s);
    }
    return d;
  }
  /** Append a line (client markup allowed); keeps the view at the end if it was there. */
  addLine(text, color = null) {
    // The line is in the DOM at once (callers read content.lastChild); the layout reads that follow it (line count, scrollbar range,
    // scroll-to-end) are batched: they run once for all the lines added in the same task (microtask, i.e. before the next paint), or at
    // once when anything reads the view (_totalLines / _range / setTop / scrollToEnd). Same end state as doing them line by line:
    //  - the view was at the end before the batch: it stays at the end through every line, so one scroll-to-end after the last one;
    //  - it was scrolled up and nothing was trimmed: the line count only grows, so it stays scrolled up, one range update;
    //  - it was scrolled up and the line cap trimmed a line (the count can shrink): synced line by line like the old code.
    if (!this._dirty || (this._trimmed && !this._atEnd)) {
      if (this._dirty) this._syncLines();
      this._atEnd = this.top >= this._totalLines() - this.visibleLines - 1;
    }
    const l = { text: String(text ?? ''), color };
    this.lines.push(l);
    this.content.appendChild(this._renderLine(l));
    if (this.maxLines && this.lines.length > this.maxLines) { this.lines.shift(); this.content.firstChild?.remove(); this._trimmed = true; }
    this._dirty = true;
    if (this.frameLineSync) return this; // The owning chat window flushes once in its frame update.
    if (!this._queued) { this._queued = true; queueMicrotask(() => { this._queued = false; if (this._dirty) this._syncLines(); }); }
    return this;
  }
  flushFrameLines() { if(this._dirty)this._syncLines(); }
  setText(text) {
    if (this.area) { this.area.value = String(text ?? ''); return this; }
    this.clear();
    for (const line of String(text ?? '').split('\n')) this.addLine(line);
    this.setTop(0);
    return this;
  }
  getText() { return this.area ? this.area.value : this.lines.map(l => l.text).join('\n'); }
  clear() { this._dirty = false; this._trimmed = false; this.lines = []; this.content.replaceChildren(); this.top = 0; this._range(); return this; }
  focus() { this.area?.focus(); return this; }
}
function hex(v) {
  const h = String(v || 'ffffffff').replace(/^0x/i, '').padStart(8, 'f');
  return [parseInt(h.slice(0, 2), 16), parseInt(h.slice(2, 4), 16), parseInt(h.slice(4, 6), 16), parseInt(h.slice(6, 8), 16)];
}

// ------------------------------------------------------------------------------------------ trees
/**
 * treectrl / multitreectrl / skilltree / messengertree: nodes {text, children, open, state, color, icon, data,
 * checked}. Rows `nodeheight`, indent `offset` per depth, +/- sprites (images plus/minus, `btnsize`), selected
 * row painted with the `check` image; row text styled by the title of the node state (none/over/check/head/
 * sub/finish/unknown/complete/...). Events: select(node), toggle(node), dblclick(node), check(node).
 */
export class UITree extends UIControl {
  get interactive() { return true; }
  init() {
    const p = this.spec.props || {};
    this.rowH = Number(p.nodeheight?.[0]) || 18;
    this.rowW = Number(p.nodewidth?.[0]) || 0;
    this.indent = Number(p.offset?.[0]) || 14;
    this.btn = Number(p.btnsize?.[0]) || 12;
    this.iconSize = Number(p.itemiconsize?.[0]) || 0;
    this.checkSize = Number(p.checkboxsize?.[0]) || 0;
    this.autoOpen = /^true/i.test(p.autoopen?.[0] || '');
    this.nodes = [];
    this.flat = [];
    this.top = 0;
    this.sel = null;
    this.hot = null;
    this.rows = div('uw-rows');
    this.el.insertBefore(this.rows, this.el.firstChild);
    this.scroll = this.children.find(c => c instanceof UIScroll) || null;
    this.scroll?.on('change', v => { this.top = v; this.render(); });
    this.el.addEventListener('wheel', (e) => { e.preventDefault(); e.stopPropagation(); this.setTop(this.top + Math.sign(e.deltaY)); }, { passive: false });
  }
  paintText() {}
  paintImage() {}
  get visibleRows() { return Math.max(1, Math.floor(this.box.h / this.rowH)); }
  setNodes(nodes) {
    const prep = (list, depth, parent) => list.map(n => { const o = typeof n === 'object' ? n : { text: String(n) }; o.depth = depth; o.parent = parent; if (o.open == null) o.open = this.autoOpen; if (o.children) o.children = prep(o.children, depth + 1, o); return o; });
    this.nodes = prep(nodes || [], 0, null);
    this._flatten();
    return this;
  }
  _flatten() {
    this.flat = [];
    const walk = (list) => { for (const n of list) { this.flat.push(n); if (n.children?.length && n.open) walk(n.children); } };
    walk(this.nodes);
    this.scroll?.setRange(Math.max(0, this.flat.length - this.visibleRows), this.visibleRows);
    this.setTop(this.top);
  }
  setTop(t) { this.top = Math.max(0, Math.min(Math.max(0, this.flat.length - this.visibleRows), t)); this.scroll?.setValue(this.top); this.render(); return this; }
  toggle(node, open = !node.open) { node.open = open; this._flatten(); this.emit('toggle', node); return this; }
  select(node, silent = true) {
    this.sel = typeof node === 'number' ? this.flat[node] : node;
    this.render();
    if (!silent) this.emit('select', this.sel);
    return this;
  }
  getSelected() { return this.sel; }
  afterLayout() { this._flatten(); }
  render() {
    if (!this.rows) return;
    this.rows.replaceChildren();
    // The authored scrollbar sits inside the tree rectangle. Keep labels out
    // of its lane (the messenger's Online/Offline text was underneath it).
    const scrollX=this.scroll?.box?.x;
    const w = Math.min(this.rowW || this.box.w,Number.isFinite(scrollX)&&scrollX>0?scrollX:this.box.w);
    for (let k = 0; k < this.visibleRows; k++) {
      const n = this.flat[this.top + k];
      if (!n) break;
      const row = div('uw-row', this.rows);
      row.style.top = `${k * this.rowH}px`; row.style.height = `${this.rowH}px`; row.style.width = `${w}px`;
      if (n === this.sel && this.images.check) { const b = div('uw-bg', row); paintBox(b, this.images.check, w, this.rowH); }
      else if (this.images.none) { const b = div('uw-bg', row); paintBox(b, this.images.none, w, this.rowH); }
      const stateT = this.titles[n.state] || null;
      const t = { ...(this.titles.none || {}), ...(stateT || {}), ...(n === this.sel ? this.titles.check || {} : n === this.hot ? this.titles.over || {} : {}) };
      titleStyle(row, t, 2, this.rowH);
      const nodeColor = Array.isArray(n.color) ? rgba(n.color) : /^[0-9a-f]{8}$/i.test(n.color) ? rgba(hex(n.color)) : n.color;
      if (nodeColor) row.style.color = nodeColor;
      let x = n.depth * this.indent;
      if (n.children?.length) {
        const b = div('uw-bg', row);
        const bs = this.btn;
        b.style.left = `${x}px`; b.style.top = `${Math.round((this.rowH - bs) / 2)}px`; b.style.width = `${bs}px`; b.style.height = `${bs}px`; b.style.pointerEvents = 'auto';
        paintBox(b, n.open ? this.images.minus : this.images.plus, bs, bs);
        b.addEventListener('click', (e) => { e.stopPropagation(); this.toggle(n); });
        x += bs + 3;
      } else if (n.depth > 0 || this.nodes.some(r => r.children?.length)) x += this.btn + 3;
      if (this.checkSize && n.checked != null) {
        const c = div('uw-bg', row);
        c.style.left = `${x}px`; c.style.top = `${Math.round((this.rowH - this.checkSize) / 2)}px`; c.style.width = c.style.height = `${this.checkSize}px`; c.style.pointerEvents = 'auto';
        // Global multitreectrl: images nonebox (etc_01#303) / checkbox (etc_01#304) — not CSS placeholders.
        const boxImg = n.checked
          ? (this.images.checkbox || this.images.check || this.images.nonebox)
          : (this.images.nonebox || this.images.none);
        paintBox(c, boxImg, this.checkSize, this.checkSize);
        c.addEventListener('click', (e) => { e.stopPropagation(); n.checked = !n.checked; this.render(); this.emit('check', n); });
        x += this.checkSize + 3;
      }
      if (n.icon) {
        const is = this.iconSize || this.rowH - 2;
        const ic = div('uw-icon', row);
        ic.style.left = `${x}px`; ic.style.top = `${Math.round((this.rowH - is) / 2)}px`; ic.style.width = ic.style.height = `${is}px`;
        paintIcon(ic, n.icon);
        x += is + 3;
      }
      const text = div('',row);
      Object.assign(text.style,{position:'absolute',left:`${x}px`,right:'4px',height:`${this.rowH}px`,display:'flex',gap:'6px',overflow:'hidden'});
      const s = document.createElement('span');
      Object.assign(s.style,{minWidth:'0',flex:'1 1 auto',overflow:'hidden',textOverflow:'ellipsis',whiteSpace:'nowrap',lineHeight:`${this.rowH}px`});
      s.textContent = String(n.text ?? '');
      text.appendChild(s);
      if (n.right != null) { const r = document.createElement('span'); r.style.flex='0 0 auto'; r.style.lineHeight = `${this.rowH}px`; r.textContent = String(n.right); text.appendChild(r); }
      // Hover restyles the row IN PLACE. A full render() here replaced the row under the cursor between pointerdown and
      // pointerup, so the click never fired (clicking through the quest list did not allow clicking other quests).
      const tBase = { ...(this.titles.none || {}), ...(stateT || {}), ...(n === this.sel ? this.titles.check || {} : {}) };
      row.addEventListener('pointerenter', () => {
        this.hot = n;
        if (n !== this.sel && this.titles.over) { titleStyle(row, { ...tBase, ...this.titles.over }, 2, this.rowH); if (nodeColor) row.style.color = nodeColor; }
      });
      row.addEventListener('pointerleave', () => {
        if (this.hot === n) this.hot = null;
        if (n !== this.sel && this.titles.over) { titleStyle(row, tBase, 2, this.rowH); if (nodeColor) row.style.color = nodeColor; }
      });
      row.addEventListener('pointerdown', (e) => { if (e.button === 0) e.stopPropagation(); });
      row.addEventListener('click', (e) => { e.stopPropagation(); this.win.mgr?.sound?.(0); if (n.children?.length && !n.selectable) this.toggle(n); this.select(n, false); });
      row.addEventListener('dblclick', (e) => { e.stopPropagation(); this.emit('dblclick', n); });
      row.addEventListener('contextmenu', (e) => { e.preventDefault(); e.stopPropagation(); this.emit('rclick', n, e); });
    }
  }
}

// ------------------------------------------------------------------------------------------ freeboardctrl
/**
 * freeboardctrl: a table. Columns = the <node> blocks (width, header text2, sort, align, cell <element>s);
 * `titleheight` header row, `nodeheight` rows, `topmargin`, `offset`. setRows([[cell...]] | [{cells, data, color}]),
 * select(i); events select(i,row), sort(col, asc), cellclick(i, col, row).
 */
export class UIBoard extends UIControl {
  get interactive() { return true; }
  init() {
    const p = this.spec.props || {};
    this.rowH = Number(p.nodeheight?.[0]) || 20;
    this.headH = Number(p.titleheight?.[0]) || 20;
    this.topMargin = Number(p.topmargin?.[0]) || 0;
    this.offset = Number(p.offset?.[0]) || 0;
    this.cols = (this.spec.extra?.nodes || []).map(n => ({ ...n }));
    this.rowsData = [];
    this.top = 0;
    this.sel = -1;
    this.sortCol = -1; this.sortAsc = true;
    this.head = div('uw-rows', this.el);
    this.body = div('uw-rows', this.el);
    this.scroll = this.children.find(c => c instanceof UIScroll) || null;
    this.scroll?.on('change', v => { this.top = v; this.render(); });
    this.el.addEventListener('wheel', (e) => { e.preventDefault(); e.stopPropagation(); this.setTop(this.top + Math.sign(e.deltaY)); }, { passive: false });
  }
  paintText() {}
  paintImage() {}
  get visibleRows() { return Math.max(1, Math.floor((this.box.h - this.headH - this.topMargin) / this.rowH)); }
  afterLayout() {
    this.head.style.height = `${this.headH}px`; this.head.style.bottom = 'auto';
    this.body.style.top = `${this.headH + this.topMargin}px`;
    this._header();
    this._range();
  }
  _header() {
    this.head.replaceChildren();
    let x = this.offset;
    const t = this.titles.title || this.titles.none;
    this.cols.forEach((c, i) => {
      const cell = div('uw-row', this.head);
      cell.style.left = `${x}px`; cell.style.top = '0'; cell.style.width = `${c.width}px`; cell.style.height = `${this.headH}px`; cell.style.textAlign = 'center';
      titleStyle(cell, t, 2, this.headH);
      cell.textContent = c.ref ? (this.win.str(c.ref) ?? '') : '';
      if (c.sort) cell.addEventListener('click', (e) => { e.stopPropagation(); this.sortAsc = this.sortCol === i ? !this.sortAsc : true; this.sortCol = i; this.emit('sort', i, this.sortAsc); });
      if (c.tooltip) { cell.title = this.win.str(c.tooltip) ?? ''; }
      x += c.width;
    });
  }
  _range() { this.scroll?.setRange(Math.max(0, this.rowsData.length - this.visibleRows), this.visibleRows); this.render(); }
  setTop(t) { this.top = Math.max(0, Math.min(Math.max(0, this.rowsData.length - this.visibleRows), t)); this.scroll?.setValue(this.top); this.render(); return this; }
  setRows(rows) { this.rowsData = (rows || []).map(r => (Array.isArray(r) ? { cells: r } : r)); if (this.sel >= this.rowsData.length) this.sel = -1; this._range(); this.setTop(this.top); return this; }
  select(i, silent = true) { this.sel = i; this.render(); if (!silent) this.emit('select', i, this.rowsData[i]); return this; }
  getSelected() { return this.sel; }
  render() {
    if (!this.body) return;
    this.body.replaceChildren();
    const w = this.cols.reduce((a, c) => a + c.width, 0) || this.box.w;
    for (let k = 0; k < this.visibleRows; k++) {
      const i = this.top + k;
      const r = this.rowsData[i];
      if (!r) break;
      const row = div('uw-row', this.body);
      row.style.top = `${k * this.rowH}px`; row.style.height = `${this.rowH}px`; row.style.width = `${w + this.offset}px`;
      const t = { ...(this.titles.none || {}), ...(i === this.sel ? this.titles.check || this.titles.over || {} : {}) };
      titleStyle(row, t, 2, this.rowH);
      if (r.color) row.style.color = Array.isArray(r.color) ? rgba(r.color) : r.color;
      if (i === this.sel) row.style.background = this.images.check ? '' : 'rgba(255,255,255,.10)';
      if (i === this.sel && this.images.check) { const b = div('uw-bg', row); paintBox(b, this.images.check, w, this.rowH); }
      let x = this.offset;
      this.cols.forEach((c, ci) => {
        const v = r.cells?.[ci];
        const cell = div('uw-cell', row);
        cell.style.left = `${x}px`; cell.style.width = `${c.width}px`;
        const al = (v && v.align) || c.align?.h || c.elements?.[0]?.align?.h || 'center';
        cell.style.textAlign = al;
        if (v && typeof v === 'object') {
          if (v.icon) { const ic = div('uw-icon', cell); const sz = Math.min(this.rowH - 2, c.width); ic.style.left = `${Math.round((c.width - sz) / 2)}px`; ic.style.top = '1px'; ic.style.width = ic.style.height = `${sz}px`; paintIcon(ic, v.icon); }
          if (v.color) cell.style.color = Array.isArray(v.color) ? rgba(v.color) : v.color;
          if (v.text != null) cell.appendChild(document.createTextNode(String(v.text)));
        } else cell.textContent = v == null ? '' : String(v);
        cell.addEventListener('click', (e) => { e.stopPropagation(); this.emit('cellclick', i, ci, r); });
        x += c.width;
      });
      row.addEventListener('pointerdown', (e) => { if (e.button === 0) e.stopPropagation(); });
      row.addEventListener('click', () => { this.win.mgr?.sound?.(0); this.select(i, false); });
      row.addEventListener('dblclick', (e) => { e.stopPropagation(); this.emit('dblclick', i, r); });
    }
  }
}

// ------------------------------------------------------------------------------------------ maillist
/**
 * maillist: rows built from its <casebox> template (icon / title / content / time rects and colours),
 * `nodeheight` + `gab` spacing, `topmargin`. setItems([{icon, title, content, time, read, data}]).
 */
export class UIMailList extends UIControl {
  get interactive() { return true; }
  init() {
    const p = this.spec.props || {};
    this.rowH = Number(p.nodeheight?.[0]) || 45;
    this.gap = Number(p.gab?.[0]) || 0;
    this.topMargin = Number(p.topmargin?.[0]) || 0;
    this.tpl = this.children.find(c => c.type === 'casebox') || null;
    this.items = [];
    this.top = 0; this.sel = -1;
    this.rows = div('uw-rows');
    this.el.insertBefore(this.rows, this.el.firstChild);
    this.scroll = this.children.find(c => c instanceof UIScroll) || null;
    this.scroll?.on('change', v => { this.top = v; this.render(); });
    this.el.addEventListener('wheel', (e) => { e.preventDefault(); e.stopPropagation(); this.setTop(this.top + Math.sign(e.deltaY)); }, { passive: false });
  }
  paintText() {}
  paintImage() {}
  get step() { return this.rowH + this.gap; }
  get visibleRows() { return Math.max(1, Math.floor((this.box.h - this.topMargin) / this.step)); }
  setItems(items) { this.items = items || []; this.scroll?.setRange(Math.max(0, this.items.length - this.visibleRows), this.visibleRows); this.setTop(this.top); return this; }
  setTop(t) { this.top = Math.max(0, Math.min(Math.max(0, this.items.length - this.visibleRows), t)); this.scroll?.setValue(this.top); this.render(); return this; }
  select(i, silent = true) { this.sel = i; this.render(); if (!silent) this.emit('select', i, this.items[i]); return this; }
  afterLayout() { this.render(); }
  render() {
    if (!this.rows) return;
    this.rows.replaceChildren();
    const tp = this.tpl?.spec.props || {};
    const R = (k, d) => { const t = tp[k]; return t ? t.map(Number) : d; };
    const [cw, chh] = this.tpl ? [this.tpl.spec.rect[2], this.tpl.spec.rect[3]] : [this.box.w, this.rowH];
    const icon = R('icon', [4, 4, 40, 40]), title = R('title', [48, 4, cw, 18]), content = R('content', [48, 20, cw, 34]), time = R('time', [48, 34, cw, 48]);
    const col = (k, d) => (tp[k] ? rgba(hex(tp[k][0])) : d);
    for (let k = 0; k < this.visibleRows; k++) {
      const i = this.top + k;
      const it = this.items[i];
      if (!it) break;
      const row = div('uw-row', this.rows);
      row.style.top = `${this.topMargin + k * this.step}px`; row.style.width = `${cw}px`; row.style.height = `${chh}px`;
      // row art = the casebox's <image> entries only (its <iconimg> is the icon, never the row background)
      const rim = k => { const x = this.tpl?.images[k]; return x && x.tag !== 'iconimg' && x.tag !== 'iconimage' ? x : null; };
      const img = i === this.sel ? (rim('check') || rim('over') || rim('none')) : rim('none');
      if (img) { const b = div('uw-bg', row); paintBox(b, img, cw, chh); }
      const put = (r, text, color) => { const e = div('uw-cell', row); e.style.left = `${r[0]}px`; e.style.top = `${r[1]}px`; e.style.width = `${Math.max(0, r[2] - r[0])}px`; e.style.height = `${Math.max(0, r[3] - r[1])}px`; applyFont(e, 2); e.style.color = color; e.textContent = text ?? ''; return e; };
      if (it.icon || this.tpl?.images) {
        const ic = div('uw-icon', row);
        ic.style.left = `${icon[0]}px`; ic.style.top = `${icon[1]}px`; ic.style.width = `${icon[2] - icon[0] || icon[2]}px`; ic.style.height = `${icon[3] - icon[1] || icon[3]}px`;
        const tplIcon = Object.values(this.tpl?.images || {}).find(x => x.tag === 'iconimg' || x.tag === 'iconimage');
        paintIcon(ic, it.icon || (tplIcon ? { sprite: [tplIcon.screen, tplIcon.index] } : null));
      }
      put(title, it.title, it.read ? col('readcolor', '#b7b7b7') : col('titlecolor', '#fcb602'));
      put(content, it.content, it.read ? col('readcolor', '#b7b7b7') : col('contentcolor', '#fff'));
      if (time[2] > time[0]) put(time, it.time, it.read ? col('readcolor', '#b7b7b7') : '#fff');
      row.addEventListener('pointerdown', (e) => { if (e.button === 0) e.stopPropagation(); });
      row.addEventListener('click', () => { this.win.mgr?.sound?.(0); this.select(i, false); });
      row.addEventListener('dblclick', (e) => { e.stopPropagation(); this.emit('dblclick', i, it); });
    }
  }
}
/** casebox: the maillist row template (never drawn itself). */
export class UICaseBox extends UIControl { init() { this.visible = false; } get hitTest() { return false; } }

// ------------------------------------------------------------------------------------------ itemslot (grid)
/**
 * itemslot: a cell grid (`cellsize` cw ch) filling its rect. Items {x, y, w=1, h=1, icon, count, data, tooltip,
 * color} occupy w x h cells. setItems/clear/itemAt/cellAt/highlight; events cellclick/cellrclick/celldbl/cellover
 * (cell, item, event). Drag & drop: makeDraggable(fn(item, cell, e) -> payload) / acceptDrop({accept, drop, hover})
 * — hover() receives the cell under the pointer; highlight(x, y, w, h, ok) shows the footprint.
 */
export class UIGrid extends UIControl {
  get interactive() { return true; }
  init() {
    const cs = this.spec.props?.cellsize || [32, 32];
    this.cw = Number(cs[0]) || 32; this.ch = Number(cs[1]) || 32;
    this.items = [];
    this.layerEl = div('uw-rows', this.el);
    this.layerEl.style.zIndex = '1';
    this.foot = null;
    this.el.addEventListener('pointermove', (e) => { const c = this.cellAt(e.clientX, e.clientY); if (c && (!this._hc || c.x !== this._hc.x || c.y !== this._hc.y)) { this._hc = c; this.emit('cellover', c, this.itemAt(c.x, c.y), e); } });
    this.el.addEventListener('pointerleave', () => { this._hc = null; this.emit('cellout'); });
    this.el.addEventListener('click', (e) => { const c = this.cellAt(e.clientX, e.clientY); if (c) this.emit('cellclick', c, this.itemAt(c.x, c.y), e); });
    this.el.addEventListener('contextmenu', (e) => { e.preventDefault(); const c = this.cellAt(e.clientX, e.clientY); if (c) this.emit('cellrclick', c, this.itemAt(c.x, c.y), e); });
    this.el.addEventListener('dblclick', (e) => { const c = this.cellAt(e.clientX, e.clientY); if (c) this.emit('celldbl', c, this.itemAt(c.x, c.y), e); });
  }
  paintText() {}
  get cols() { return Math.max(1, Math.floor(this.box.w / this.cw)); }
  get rowsN() { return Math.max(1, Math.floor(this.box.h / this.ch)); }
  /** Cell {x, y} under a client point, or null. */
  cellAt(clientX, clientY) {
    const r = this.el.getBoundingClientRect();
    const sc = this.win.mgr?.scale || 1;
    const x = Math.floor((clientX - r.left) / sc / this.cw), y = Math.floor((clientY - r.top) / sc / this.ch);
    return x >= 0 && y >= 0 && x < this.cols && y < this.rowsN ? { x, y } : null;
  }
  itemAt(x, y) { return this.items.find(it => x >= it.x && x < it.x + (it.w || 1) && y >= it.y && y < it.y + (it.h || 1)) || null; }
  setItems(items) { this.items = items || []; this.render(); return this; }
  clear() { return this.setItems([]); }
  afterLayout() {
    // Window open/place and parent visibility run layout again. Cell-sized icon nodes
    // need rebuilding only when their cell dimensions change, not when the window moves.
    if (this._renderCellW !== this.cw || this._renderCellH !== this.ch) this.render();
  }
  render() {
    if (!this.layerEl) return;
    this._renderCellW = this.cw; this._renderCellH = this.ch;
    this.layerEl.replaceChildren();
    for (const it of this.items) {
      const e = div('uw-icon', this.layerEl);
      const w = (it.w || 1) * this.cw, h = (it.h || 1) * this.ch;
      e.style.left = `${it.x * this.cw}px`; e.style.top = `${it.y * this.ch}px`; e.style.width = `${w}px`; e.style.height = `${h}px`;
      if (it.color) e.style.boxShadow = `inset 0 0 0 1px ${Array.isArray(it.color) ? rgba(it.color) : it.color}`;
      if (it.dim) e.style.opacity = '0.45';
      paintIcon(e, it.icon);
      if (it.count != null && it.count !== 1) { const c = div('uw-count', e); c.textContent = String(it.count); }
      it._el = e;
    }
  }
  /** Footprint preview (cells) — ok: true green, false red; null clears. */
  highlight(x, y, w = 1, h = 1, ok = true) {
    if (x == null) { this.foot?.remove(); this.foot = null; return this; }
    if (!this.foot) this.foot = div('uw-foot', this.el);
    const s = this.foot.style;
    s.left = `${x * this.cw}px`; s.top = `${y * this.ch}px`; s.width = `${w * this.cw}px`; s.height = `${h * this.ch}px`;
    this.foot.className = `uw-foot ${ok ? 'ok' : 'bad'}`;
    return this;
  }
  /** Tooltip per item: the item's .tooltip (string/fn) or a function(item) given here. */
  tooltip() {
    const c = this._hc && this.itemAt(this._hc.x, this._hc.y);
    if (!c) return null;
    if (this._itemTip) return this._itemTip(c);
    return typeof c.tooltip === 'function' ? c.tooltip(c) : c.tooltip ?? null;
  }
  setItemTooltip(fn) { this._itemTip = fn; this.el.classList.add('uw-hit'); return this; }
}

registerControlType('vscroll', UIScroll);
registerControlType('slidebar', UISlider);
registerControlType('combobox', UICombo);
registerControlType('listbox', UIList);
registerControlType('textbox', UITextBox);
registerControlType('chattextbox', UITextBox);
registerControlType('treectrl', UITree);
registerControlType('multitreectrl', UITree);
registerControlType('skilltree', UITree);
registerControlType('messengertree', UITree);
registerControlType('freeboardctrl', UIBoard);
registerControlType('maillist', UIMailList);
registerControlType('casebox', UICaseBox);
registerControlType('itemslot', UIGrid);
export { measureText };
