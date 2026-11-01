// edit control (single/multi-line text input) and the legacy tool-UI controls (create_control scripts).
import { atlas } from '../atlas.js';
import { UIControl, registerControlType, div, rgba, applySprite, hexArgb } from './controls.js';
import { applyFont } from './fonts.js';

/**
 * edit: `font_type` fontIndex, `color`, `maxlength`, `input_type` (0 any, 2 digits only, 4 letters/digits
 * only), `passwd`, `multiline`, `align`, `init_text` (initial value), `init_text2 cate code AARRGGBB`
 * (placeholder string + colour). Events: change(value), enter(value), focus, blur. getValue/setValue/focus.
 */
export class UIEdit extends UIControl {
  get interactive() { return true; }
  init() {
    const p = this.spec.props || {};
    const multi = /^true/i.test(p.multiline?.[0] || '');
    const inp = document.createElement(multi ? 'textarea' : 'input');
    inp.className = 'uw-edit';
    if (!multi) inp.type = /^true/i.test(p.passwd?.[0] || '') ? 'password' : 'text';
    inp.spellcheck = false;
    inp.autocomplete = 'off';
    const font = Number(p.font_type?.[0] ?? p.fonttype?.[0]) || 2;
    applyFont(inp, font);
    inp.style.lineHeight = multi ? '' : `${Math.max(1, this.spec.rect[3])}px`;
    inp.style.color = p.color ? rgba(hexArgb(p.color[0])) : '#fff';
    const ml = Number(p.maxlength?.[0]);
    if (ml > 0) inp.maxLength = ml;
    this.inputType = Number(p.input_type?.[0]) || 0;
    if (this.inputType === 2) inp.inputMode = 'numeric';
    const al = this.spec.align?.h || 'left';
    inp.style.textAlign = al;
    if (p.init_text) inp.value = p.init_text.join(' ');
    if (this.spec.initRef) {
      const ph = this.win.str(this.spec.initRef);
      if (ph) inp.placeholder = ph;
      if (this.spec.initRef.color) inp.style.setProperty('--ph', rgba(this.spec.initRef.color));
    }
    inp.addEventListener('input', () => {
      if (this.inputType === 2) { const v = inp.value.replace(/[^0-9]/g, ''); if (v !== inp.value) inp.value = v; }
      if (this.inputType === 4) { const v = inp.value.replace(/[^0-9A-Za-z]/g, ''); if (v !== inp.value) inp.value = v; }
      this.emit('change', inp.value);
    });
    inp.addEventListener('keydown', (e) => {
      e.stopPropagation();
      if (e.key === 'Enter' && !multi) { e.preventDefault(); this.emit('enter', inp.value); }
      if (e.key === 'Escape') { inp.blur(); this.emit('escape'); }
      if (e.key === 'Tab') { e.preventDefault(); this.win.focusNext?.(this, e.shiftKey ? -1 : 1); }
    });
    inp.addEventListener('focus', () => this.emit('focus'));
    inp.addEventListener('blur', () => this.emit('blur'));
    inp.addEventListener('pointerdown', (e) => e.stopPropagation());
    this.input = inp;
    this.el.appendChild(inp);
    this.el.classList.add('uw-hit');
    if (!this.enabled) inp.disabled = true;
  }
  paintText() {}
  setEnabled(v) { super.setEnabled(v); if (this.input) this.input.disabled = !this.enabled; return this; }
  getValue() { return this.input.value; }
  getText() { return this.input ? this.input.value : ''; }
  getNumber() { return Number(this.input.value) || 0; }
  setValue(v) { this.input.value = v == null ? '' : String(v); return this; }
  setText(v) { return this.setValue(v); }
  setPlaceholder(t) { this.input.placeholder = t ?? ''; return this; }
  focus() { this.input.focus(); try { this.input.select(); } catch { /* textarea */ } return this; }
  blur() { this.input.blur(); return this; }
  clear() { this.input.value = ''; return this; }
}
registerControlType('edit', UIEdit);

// ------------------------------------------------------------------------------------------ legacy tool UI
/**
 * Controls of the old create_control scripts (maptool, effecttool, environment window, mode menu).
 * control_image <flags> tex x y w h: flags = which of normal/over/down/disable exist ('o'), laid out side by side
 * in the texture (w apart). control_drawdiv xy N / x N: nine-/three-slice with N-pixel borders. control_color true
 * a r g b: solid fill. control_text dx dy text + control_textcolor r g b + control_textfont small|normal.
 */
export class UILegacy extends UIControl {
  get interactive() { return ['button', 'textbutton', 'tabbutton', 'buttonpress', 'checkbox', 'combobox', 'combobox2', 'list', 'spin'].includes(this.type) || !!this.spec.legacy?.style; }
  init() {
    const L = this.spec.legacy || {};
    if (L.color?.on) {
      const [a, r, g, b] = L.color.argb;
      this.el.style.background = `rgba(${r},${g},${b},${(a / 255).toFixed(3)})`;
    }
    if (this.type === 'edit' || this.type === 'spin') {
      const inp = document.createElement('input');
      inp.className = 'uw-edit';
      inp.style.font = '11px Tahoma, Verdana, sans-serif';
      inp.style.color = '#000';
      inp.style.background = '#fff';
      const len = Number(L.cedit_length?.[0]); if (len) inp.maxLength = len;
      if (L.cedit_initvalue) inp.value = L.cedit_initvalue[0];
      inp.addEventListener('keydown', e => { e.stopPropagation(); if (e.key === 'Enter') this.emit('enter', inp.value); });
      inp.addEventListener('input', () => this.emit('change', inp.value));
      inp.addEventListener('pointerdown', e => e.stopPropagation());
      this.input = inp; this.el.appendChild(inp);
    }
    if (L.style === 'checked' || L.style === 'radio') this.toggle = L.style;
  }
  activate(e) {
    if (this.toggle === 'checked') this.setChecked(!this.checked, false);
    else if (this.toggle === 'radio') { for (const s of this.parent?.children || []) if (s !== this && s.toggle === 'radio' && s.spec.legacy?.group === this.spec.legacy?.group) s.setChecked(false); this.setChecked(true, false); }
    this.emit('click', e);
  }
  get state() { return !this.enabled ? 'disable' : this.pressed || this.checked ? 'down' : this.hover && this.interactive ? 'over' : 'none'; }
  paintImage() {
    const L = this.spec.legacy || {};
    if (!L.image) return;
    if (!this.bg) { this.bg = div('uw-bg'); this.el.insertBefore(this.bg, this.el.firstChild); }
    const flags = String(L.image.flags || 'oxxx');
    const order = ['none', 'over', 'down', 'disable'];
    let k = order.indexOf(this.state);
    if (k < 0 || flags[k] !== 'o') k = 0;
    const { tex, x, y, w, h } = L.image;
    const tok = (this._tok = {});
    atlas.region(tex, x + k * w, y, w, h).then(s => {
      if (this._tok !== tok || !s) return;
      const n = L.div ? Number(L.div[1]) || 0 : 0;
      const horizontalOnly = L.div && String(L.div[0]).toLowerCase() === 'x';
      if (n > 0) {
        const t = horizontalOnly ? 0 : n;
        const b = this.bg.style;
        b.backgroundImage = 'none'; b.borderStyle = 'solid';
        b.borderWidth = `${t}px ${n}px ${t}px ${n}px`;
        b.borderImage = `url("${s.url}") ${t} ${n} ${t} ${n} fill / ${t}px ${n}px ${t}px ${n}px stretch`;
      } else applySprite(this.bg, s, this.box.w, this.box.h);
    });
  }
  getText() { return this._text !== undefined ? this._text : this.spec.legacy?.text?.text || ''; }
  paintText() {
    const L = this.spec.legacy || {};
    const text = this.getText();
    if (!text && !this.txt) return;
    if (!this.txt) { this.txt = div('uw-t', this.el); this.txt.appendChild(document.createElement('span')); }
    const c = L.textColor || [255, 255, 255];
    this.txt.style.font = `${L.font === 'normal' ? 12 : 11}px Tahoma, Verdana, sans-serif`;
    this.txt.style.color = this._color ? rgba(this._color) : `rgb(${c[0]},${c[1]},${c[2]})`;
    this.txt.style.paddingLeft = `${L.text?.x || 0}px`;
    this.txt.style.paddingTop = `${L.text?.y || 0}px`;
    this.txt.firstChild.textContent = text;
  }
  getValue() { return this.input ? this.input.value : this.checked; }
  setValue(v) { if (this.input) this.input.value = String(v ?? ''); else this.setChecked(!!v); return this; }
}
registerControlType('#legacy', UILegacy);
