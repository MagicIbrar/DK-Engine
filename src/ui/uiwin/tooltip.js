// Tooltips with the original frame (etc_01#66, 20x20, nine-slice 5/5/5/5; docs/formats/ui.md §3).
// Content: string (client markup allowed), Element, or {lines: [{text, color, font, align}], width}.
// A control's tooltip comes from setTooltip() or its script `tooltip cate code` (NORMAL strings).
import { atlas } from '../atlas.js';
import { div } from './controls.js';
import { applyFont } from './fonts.js';
import { markupRuns } from './strings.js';

// The original shows tooltips (items, skills, buffs, buttons) the moment the pointer is over the control: no delay.
// Per-cell grids (itemslot: bag, stash...) rebuild their tooltip only when the hovered ITEM changes (or a modifier view:
// Ctrl comparison, Shift option ranges), never on every mouse move; the side (right/left, below/above the cursor) is
// chosen once per content and the box is clamped to the screen, so it follows the cursor without flicker or jumping.

const typing=t=>!!t&&(t.tagName==='INPUT'||t.tagName==='TEXTAREA'||!!t.isContentEditable);
// Owners whose item tooltip follows a stationary Shift press/release: item grids (bag, stash, trade...) and single
// item slots (equipment). Other tooltips have no Shift view.
const SHIFT_VIEW=new Set(['itemslot','item']);

export class Tooltips {
  constructor(mgr) {
    this.mgr = mgr;
    this.el = div('uw-tip');
    this.el.style.display = 'none';
    mgr.layer.appendChild(this.el);
    this.owner = null;
    this._shiftDown=false;
    // Ctrl (910:15 comparison) and Shift (910:17 option ranges) only switch the hovered item's view; Shift never pins or
    // cycles anything. A key typed into a text field (Shift for capitals, Shift+Arrow selection) and Shift auto-repeat
    // change nothing; a release always clears; focusing a text field, window blur or a drag never leaves a stale view.
    this._onKey=e=>{if(e.type==='keydown'&&typing(e.target))return;if(e.key==='Control'){this._ctrlHeld(e.type==='keydown');return;}if(e.key!=='Shift'||e.type==='keydown'&&e.repeat)return;this._shiftHeld(e.type==='keydown');};
    this._onFocus=e=>{if(typing(e.target))this._shiftHeld(false);};
    this._onBlur=()=>{this._shiftDown=false;this._ctrlKey=false;this.hide();};
    window.addEventListener('keydown',this._onKey,true);window.addEventListener('keyup',this._onKey);window.addEventListener('blur',this._onBlur);globalThis.document?.addEventListener?.('focusin',this._onFocus);
    this._t = 0;
    atlas.sprite('etc_01', 66).then(s => {
      if (!s) return;
      const [l, t, r, b] = s.row.m.some(Boolean) ? s.row.m : [5, 5, 5, 5];
      this._frame = { image: `url("${s.url}") ${t} ${r} ${b} ${l} fill / ${t}px ${r}px ${b}px ${l}px stretch`, width: `${t}px ${r}px ${b}px ${l}px` };
      this._frameInto(this.el);
      for (const f of this.el.querySelectorAll?.('.uw-tip-frame') || []) this._frameInto(f);
    });
  }
  /** The original etc_01#66 nine-slice on a tooltip box (the manager's own box, or one comparison frame). */
  _frameInto(node) {
    if (!this._frame || !node?.style) return;
    node.style.borderImage = this._frame.image;
    node.style.borderWidth = this._frame.width;
    // Retain a solid reading surface beneath translucent original frame pixels.
    node.style.background = '#100e0b';
  }
  enter(ctrl, e) {
    if (this.mgr.dnd?.cur?.pending) return;
    clearTimeout(this._t);
    this.owner = ctrl;
    this._last = e;
    this._key = undefined;
    // per-cell grids: the pointermove that follows the pointerenter (same position) picks the hovered item
    if (ctrl.type === 'itemslot') { this.el.style.display = 'none'; return; }
    this._showFor(ctrl);
  }
  move(ctrl, e) {
    this._last = e;
    if (this.mgr.dnd?.cur?.pending) return;
    // entered while something was on the cursor (or re-entered after a drop): take the control now, unless a system
    // shows its own tooltip through show() (skill window, exchange lists)
    if (!this.owner) {
      if (this.el.style.display !== 'none') return;
      this.owner = ctrl; this._key = undefined;
      if (ctrl.type !== 'itemslot') { this._showFor(ctrl); return; }
    }
    if (this.owner !== ctrl) return;
    if (ctrl.type === 'itemslot') {
      const it = ctrl._hc ? ctrl.itemAt?.(ctrl._hc.x, ctrl._hc.y) : null;
      const key = it ? (it.data ?? it) : null;
      const ck = !!e.ctrlKey;
      // the pointer's Shift state also corrects a missed key event, except while a text field has focus
      const sk = !!e.shiftKey && !typing(globalThis.document?.activeElement);
      if (key !== this._key || ck !== this._ctrlKey || sk !== !!this._shiftDown) { this._key = key; this._ctrlKey = ck; this._shiftDown = sk; this._showFor(ctrl); return; }
    }
    if (this.el.style.display !== 'none') this._place(e.clientX, e.clientY);
  }
  /** Rebuild an open tooltip after its backing item changes, even with a stationary pointer. */
  refresh(ctrl = this.owner) {
    if (!ctrl || this.owner !== ctrl || this.mgr.dnd?.cur?.pending) return;
    if (ctrl.type === 'itemslot') {
      const it = ctrl._hc ? ctrl.itemAt?.(ctrl._hc.x, ctrl._hc.y) : null;
      this._key = it ? (it.data ?? it) : null;
      this._ctrlKey = !!this._last?.ctrlKey;
    }
    this._showFor(ctrl);
  }
  leave(ctrl) { if (this.owner === ctrl) this.hide(); }
  // Original stringtable_itemdesc 910:15 "Press Ctrl key to compare the item with the equipped item.": pressing or
  // releasing Ctrl over a hovered item cell rebuilds its tooltip at once (the cell's builder reads _ctrlKey / game
  // input after this key event), without waiting for the next pointer move. Key repeat is left alone.
  _ctrlHeld(down){
    if(this.owner?.type!=='itemslot'||this.mgr.dnd?.cur?.pending||!!this._ctrlKey===down)return;
    this._ctrlKey=down;clearTimeout(this._ctrlT);
    this._ctrlT=setTimeout(()=>{if(this.owner?.type==='itemslot'&&this.el.style.display!=='none')this._showFor(this.owner);},0);
  }
  // Original 910:17 "Press SHIFT key to view range of possible Rank & Brand Option values.": pressing or releasing Shift
  // over a hovered item rebuilds it with or without the proven ranges (builders read _shiftDown after this key event).
  // The state always follows the key; a repeat, an active drag or a non-item tooltip never rebuilds.
  _shiftHeld(down){
    if(!!this._shiftDown===down)return;
    this._shiftDown=down;clearTimeout(this._shiftT);
    if(this.mgr.dnd?.cur||!SHIFT_VIEW.has(this.owner?.type))return;
    this._shiftT=setTimeout(()=>{if(!this.mgr.dnd?.cur&&SHIFT_VIEW.has(this.owner?.type)&&this.el.style.display!=='none')this._showFor(this.owner);},0);
  }
  dispose(){window.removeEventListener('keydown',this._onKey,true);window.removeEventListener('keyup',this._onKey);window.removeEventListener('blur',this._onBlur);globalThis.document?.removeEventListener?.('focusin',this._onFocus);this.hide();}
  _showFor(ctrl) {
    let content = null;
    try { content = ctrl.tooltip?.(); } catch (err) { console.error('[uiwin] tooltip', err); }
    if (content == null || content === '') { this.el.style.display = 'none'; return; }
    this.show(content, this._last?.clientX ?? 0, this._last?.clientY ?? 0);
  }
  /** Show arbitrary content at a client point (systems can call this directly). */
  show(content, clientX, clientY) {
    this.el.replaceChildren();
    applyFont(this.el, 2, 14);
    this.el.style.maxWidth = '';
    this.el.style.textAlign = '';
    this.el.style.transform = this.el.style.transformOrigin = this.el.style.width = this.el.style.boxSizing = '';
    // An item comparison (buildCompare, class itt-compare) is the original pan_tooltip + pan_tooltipEx pair: this box
    // turns frameless (css.js .uw-tip-pair) and each item tooltip in it gets its own etc_01#66 frame. The pair is then
    // measured, flipped, clamped and shrunk below exactly like a single tooltip.
    const pair = content instanceof Element && !!content.classList?.contains?.('itt-compare');
    this.el.classList?.toggle?.('uw-tip-pair', pair);
    if (content instanceof Element) { this.el.appendChild(content); if (pair) for (const f of content.querySelectorAll?.('.uw-tip-frame') || []) this._frameInto(f); }
    else if (typeof content === 'object' && content.lines) {
      if (content.width) this.el.style.maxWidth = `${content.width}px`;
      for (const l of content.lines) {
        const d = document.createElement('div');
        if (l.font) applyFont(d, l.font);
        if (l.color) d.style.color = Array.isArray(l.color) ? `rgba(${l.color[1]},${l.color[2]},${l.color[3]},${l.color[0] / 255})` : l.color;
        if (l.align) d.style.textAlign = l.align;
        for (const r of markupRuns(l.text ?? '')) { if (r.br) { d.appendChild(document.createElement('br')); continue; } const s = document.createElement('span'); s.textContent = r.text; if (r.color) s.style.color = r.color; d.appendChild(s); }
        this.el.appendChild(d);
      }
    } else {
      // layout tags of the client strings (script tooltips such as 230:*: "<center>Settings"): alignment, not text
      let text = String(content);
      this.el.style.textAlign = /<center>/i.test(text) ? 'center' : '';
      text = text.replace(/<\/?center>|<left>|<right>|<set=[^>]*>|<\/?font[^>]*>/gi, '');
      for (const r of markupRuns(text)) { if (r.br) { this.el.appendChild(document.createElement('br')); continue; } const s = document.createElement('span'); s.textContent = r.text; if (r.color) s.style.color = r.color; this.el.appendChild(s); }
    }
    this.el.style.display = '';
    // measure once per content and pick the side once (no flip-flopping while the pointer moves)
    // Measure new content away from the previous edge so shrink-to-fit cannot wrap it first.
    this.el.style.left = this.el.style.top = '0px';
    // offsetWidth rounds fractional font bounds down: edge placement can then wrap a new line.
    const rect = this.el.getBoundingClientRect(), scale = this.mgr.scale || 1;
    this._w = Math.ceil(rect.width / scale); this._h = Math.ceil(rect.height / scale);
    // LANE16 (ENGINE-CHOSEN containment): content taller/wider than the interface layer (long authored option lists at
    // 150% UI scale) is shrunk uniformly instead of clipped, so every line stays readable inside the viewport.
    const fit = Math.min(1, this.mgr.screen.w / this._w, this.mgr.screen.h / this._h);
    // Lock the measured border-box width: a transform does not shrink the layout box, so placement near the right
    // edge must not re-wrap (and lengthen) the scaled content.
    if (fit < 1) { this.el.style.boxSizing = 'border-box'; this.el.style.maxWidth = 'none'; this.el.style.width = `${rect.width / scale}px`; this.el.style.transformOrigin = '0 0'; this.el.style.transform = `scale(${fit})`; this._w = Math.ceil(this._w * fit - 1e-6); this._h = Math.ceil(this._h * fit - 1e-6); }
    const p = this.mgr.toLayer(clientX, clientY);
    this._flipX = p.x + 14 + this._w > this.mgr.screen.w;
    this._flipY = p.y + 18 + this._h > this.mgr.screen.h;
    this._place(clientX, clientY);
  }
  _place(cx, cy) {
    const p = this.mgr.toLayer(cx, cy);
    const w = this._w ?? this.el.offsetWidth, h = this._h ?? this.el.offsetHeight;
    const W = this.mgr.screen.w, H = this.mgr.screen.h;
    let x = this._flipX ? p.x - w - 6 : p.x + 14;
    let y = this._flipY ? p.y - h - 6 : p.y + 18;
    x = Math.max(0, Math.min(x, W - w)); y = Math.max(0, Math.min(y, H - h));
    this.el.style.left = `${Math.round(x)}px`; this.el.style.top = `${Math.round(y)}px`;
  }
  hide() { clearTimeout(this._t); this.owner = null; this._key = undefined; this.el.style.display = 'none'; }
}
