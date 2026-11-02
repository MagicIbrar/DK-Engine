// Drag-and-drop layer for icons/items between windows (docs/UIWIN.md "Drag and drop").
//
// Sources: control.makeDraggable(fn, opts) where fn(e, control) returns a payload or null:
//   { data, icon, size: [w, h], hotspot: [x, y], onDrop(target, result), onCancel(), onDropOutside(e), canRetain() }
// An acknowledged item swap may return {heldItem: payload} for the displaced, still-owned item.
// Targets: control.acceptDrop({ accept(data, e, ctrl) -> bool, drop(data, e, ctrl) -> any, hover(data, e, ctrl), leave(ctrl) })
// Both styles of the original work: press-drag-release, and click-to-pick-up then click-to-place (the icon sticks
// to the cursor until the next click). Esc cancels (Global WM_CHAR 0x1b -> CCharEscapeMsgInDS); right click does
// not cancel. The cursor keeps its normal shape: Global 0082f820 only draws the held icon. Releasing over the game canvas (no window)
// calls payload.onDropOutside(e) (e.g. "drop this item on the ground?").
import { div, paintIcon, UIControl } from './controls.js';

// Global 01188d40: a press-drag starts once the squared pointer travel exceeds DAT_01b7e2d8 = 15.0.
const DRAG_START_SQ = 15;
export class DragDrop {
  constructor(mgr) {
    this.mgr = mgr;
    this.cand = null;     // pressed source waiting for movement
    this.cur = null;      // active drag {payload, source, mode: 'hold'|'sticky'}
    this.target = null;
    this.icon = div('uw-dnd');
    this.icon.style.display = 'none';
    mgr.layer.appendChild(this.icon);
    this._move = (e) => this._onMove(e);
    this._up = (e) => this._onUp(e);
    this._down = (e) => this._onDownGlobal(e);
    this._key = (e) => {
      if (e.key !== 'Escape' || !this.cur) return;
      e.stopPropagation(); e.preventDefault();
      // An equip/drop request may still be waiting for the host. Release the
      // cursor when it settles, including when the host refuses the action.
      if (this.cur.pending) this.cur.cancelOnResolve = true;
      else this.cancel();
    };
    addEventListener('pointermove', this._move, true);
    addEventListener('pointerup', this._up, true);
    addEventListener('pointerdown', this._down, true);
    addEventListener('keydown', this._key, true);
    this._ctx = (e) => { if (this.cur && !this.cur.pending) { e.preventDefault();
      // Android can emit contextmenu after a touch hold. That is the same lift
      // gesture, not a separate mouse right-click asking to cancel the item.
      if(this._lastPointer?.pointerType==='touch'&&e.pointerType!=='mouse'){e.stopPropagation();return;}
    } };
    // the click that follows a pick-up / sticky drop must not reach the controls underneath
    this._click = (e) => { this._suppressDoubleClick = !!this._swallow; if (this._swallow) { this._swallow = false; e.stopPropagation(); e.preventDefault(); } };
    // Browsers synthesize dblclick separately even when the preceding click
    // was consumed by pickup/swap. It must not use/equip the newly placed item.
    this._dblclick = (e) => { if(this.cur || this._suppressDoubleClick) { e.stopPropagation(); e.preventDefault(); } this._suppressDoubleClick=false; };
    addEventListener('contextmenu', this._ctx, true);
    addEventListener('click', this._click, true);
    addEventListener('dblclick', this._dblclick, true);
  }
  get active() { return !!this.cur; }
  get data() { return this.cur?.payload?.data; }

  /** Called by a draggable control on pointerdown. Returns true when it took the event. */
  pointerDown(ctrl, e) {
    if (this.cur) return false;   // the global handler deals with sticky drops
    this.cand = { ctrl, x: e.clientX, y: e.clientY, e };
    return true;
  }
  _onMove(e) {
    // Global 01188d40: another button pressed during a press-drag releases the drag first, so the item drops there
    if (this.cur && !this.cur.pending && this.cur.mode === 'hold' && e.button > 0) { this._swallow = true; this.drop(e); return; }
    if (this.cand && !this.cur && (e.clientX - this.cand.x) ** 2 + (e.clientY - this.cand.y) ** 2 > DRAG_START_SQ) {
      const c = this.cand; this.cand = null;
      this.start(c.ctrl, c.e, 'hold');
    }
    if (this.cur && !this.cur.pending) { this._placeIcon(e); this._hover(e); }
  }
  _onUp(e) {
    if (this.cand && !this.cur) {
      const c = this.cand; this.cand = null;
      // a click without movement: pick up (sticky) if allowed, otherwise it is a normal click
      if (c.ctrl._dragOpts?.clickPick !== false && e.button === 0) {
        if (this.start(c.ctrl, c.e, 'sticky')) { this._placeIcon(e); this._swallow = true; return; }
      }
      c.ctrl.emit('click', e);
      return;
    }
    if (this.cur && this.cur.mode === 'hold' && e.button === 0) this.drop(e);
  }
  _onDownGlobal(e) {
    if (this.cur && !this.cur.pending && this.cur.mode === 'hold' && e.button > 0) { e.stopPropagation(); e.preventDefault(); this._swallow = true; this.drop(e); return; }
    if (!this.cur || this.cur.pending || this.cur.mode !== 'sticky') return;
    if (e.button !== 0) return;
    // The inventory toggle and its close button only change panel visibility.
    // Let them work while an owned item is carried so it can be placed after
    // reopening the grid; neither action consumes the item.
    const menu = e.target?.closest?.('.dk-menu-btn[data-id="inventory"]');
    let node = e.target, inventoryButton = false;
    while (node && !inventoryButton) {
      const control = node._uw;
      inventoryButton = control?.id === 'btn_inven' || (control?.win?.name === 'inventory' &&
        ['btn_exit', 'btn_close', 'btn_x', 'btn_cancel_x'].includes(control.id));
      node = node.parentElement;
    }
    if (menu || inventoryButton) return;
    e.stopPropagation(); e.preventDefault();
    this._swallow = true;
    this.drop(e);
  }
  /** Begin dragging from a control (or programmatically with a payload). */
  start(ctrl, e, mode = ctrl instanceof UIControl ? 'hold' : 'sticky') {
    if(this.disposed)return false;
    const payload = ctrl instanceof UIControl ? ctrl._drag?.(e, ctrl) : ctrl;
    if (!payload) return false;
    this.cur = { payload, source: ctrl instanceof UIControl ? ctrl : null, mode };
    const [w, h] = payload.size || [32, 32];
    const st = this.icon.style;
    st.width = `${w}px`; st.height = `${h}px`; st.display = '';
    this._paint(payload, payload.icon);
    // the icon may still be rendering (item models; a still may stand in for the spinning sheet): paint it when it
    // arrives, if this drag is still on
    if (payload.iconAsync?.then) {
      const cur = this.cur;
      payload.iconAsync.then(ic => { if (ic && this.cur === cur) this._paint(payload, ic); }).catch(() => {});
    }
    if (payload.iconSpinAsync?.then) {
      const cur = this.cur;
      payload.iconSpinAsync.then(ic => { if (ic && this.cur === cur) this._paint(payload, ic); }).catch(() => {});
    }
    this.mgr.tooltips?.hide();
    this.mgr.emit('dragstart', payload);
    this._placeIcon(e);
    if(payload.onPickup){
      const cur=this.cur;cur.pending=true;
      Promise.resolve().then(()=>payload.onPickup()).then(result=>{
        if(this.disposed||this.cur!==cur)return;const cancel=cur.cancelOnResolve;cur.cancelOnResolve=false;cur.pending=false;
        if(result?.heldItem){this._finishDrop(cur,null,true,result);if(cancel)this.cancel();}
        else {cur.payload.canRetain=()=>false;this._finishDrop(cur,null,false);}
      },()=>{if(this.cur===cur){cur.pending=false;cur.payload.canRetain=()=>false;this._finishDrop(cur,null,false);}});
    }
    return true;
  }
  /** The held icon: the payload icon stretched over its size (item renders are 2x), plus the stack count. */
  _paint(payload, icon) {
    paintIcon(this.icon, icon);
    const n = Number(payload.count ?? payload.data?.count);
    if (n > 1) { const c = div('uw-count', this.icon); c.textContent = String(n); }
    if(payload.pendingCount>0){const c=div('uw-count',this.icon);c.textContent=`+${payload.pendingCount} waiting`;c.style.bottom='-18px';c.style.whiteSpace='nowrap';this.icon.title=`${payload.pendingCount} dependent item(s) are safely held next. Place this item to continue.`;}
  }
  _placeIcon(e) {
    if (!e) return;
    this._lastPointer = e;
    const p = this.mgr.toLayer(e.clientX, e.clientY);
    const [hx, hy] = this.cur?.payload.hotspot || [(this.cur?.payload.size?.[0] || 32) / 2, (this.cur?.payload.size?.[1] || 32) / 2];
    // Global CCursorControl keeps the held icon's top-left on screen (never negative), centred on the cursor otherwise
    this.icon.style.left = `${Math.max(0, p.x - hx)}px`; this.icon.style.top = `${Math.max(0, p.y - hy)}px`;
  }
  _targetAt(e) {
    let el = document.elementFromPoint(e.clientX, e.clientY);
    while (el) {
      const c = el._uw;
      if (c && c._dropT) return c;
      el = el.parentElement;
    }
    return null;
  }
  _overWindow(e) {
    let el = document.elementFromPoint(e.clientX, e.clientY);
    while (el) { if (el._uw || el._uwWin) return true; if (el === this.mgr.layer) break; el = el.parentElement; }
    return false;
  }
  _hover(e) {
    const t = this._targetAt(e);
    if (t !== this.target) { this.target?._dropT.leave?.(this.target); this.target = t; }
    t?._dropT.hover?.(this.cur.payload.data, e, t);
  }
  drop(e) {
    const cur = this.cur;
    if (!cur || cur.pending) return;
    const t = this._targetAt(e);
    let done = false, result;
    if(t?._dropT.referenceSource==='bag'&&cur.payload.data?.from==='cursor'&&cur.payload.referenceDrop){
      try{result=cur.payload.referenceDrop(t,e);done=result!==false;}catch(err){console.error('[uiwin] service item registration',err);}
    } else if (t && t._dropT.accept?.(cur.payload.data, e, t) !== false) {
      try { result = t._dropT.drop?.(cur.payload.data, e, t); done = result !== false; } catch (err) { console.error('[uiwin] drop handler', err); }
    } else if (!t && !this._overWindow(e)) {
      if (cur.payload.onDropOutside) { try { result = cur.payload.onDropOutside(e); done = result !== false; } catch (err) { console.error(err); } }
    }
    if (result?.then) {
      cur.pending = true;
      void Promise.resolve(result).then(value => this._finishDrop(cur, t, value !== false, value), () => this._finishDrop(cur, t, false));
      return;
    }
    this._finishDrop(cur, t, done, result);
  }
  _finishDrop(cur, t, done, result) {
    if(this.disposed)return;
    if (this.cur !== cur) return;
    if (cur.cancelOnResolve) {
      cur.pending=false;cur.cancelOnResolve=false;
      if(done){this._finishDrop(cur,t,true,result);if(result?.heldItem)this.cancel();}
      else this.cancel();
      return;
    }
    this.target?._dropT.leave?.(this.target);
    this.target = null;
    if (!done && cur.payload.data?.kind === 'item' && cur.payload.canRetain?.() !== false) {
      // A refused placement is not a cancellation. Keep the same owned item held;
      // release-to-drop becomes click-to-place so another target can be chosen.
      cur.pending = false;
      cur.mode = 'sticky';
      return;
    }
    this.cur = null;
    this.icon.style.display = 'none';
    if (done) cur.payload.onDrop?.(t, result); else cur.payload.onCancel?.();
    this.mgr.emit('dragend', { payload: cur.payload, target: t, done });
    const e = this._lastPointer || this.mgr.tooltips?._last;
    if (done && result?.heldItem && !this.cur) { this.start(result.heldItem, e, 'sticky'); return; }
    const target = e && this._targetAt(e);
    if (target && e) { this.mgr.tooltips?.enter(target, e); this.mgr.tooltips?.move(target, e); }
  }
  cancel() {
    const cur = this.cur;
    if (!cur) return;
    if(cur.pending){cur.cancelOnResolve=true;return;}
    if(cur.payload.requestCancel){
      cur.pending=true;
      Promise.resolve().then(()=>cur.payload.requestCancel()).then(result=>{cur.pending=false;cur.cancelOnResolve=false;this._finishDrop(cur,null,result!==false,result);},()=>{cur.pending=false;cur.cancelOnResolve=false;this._finishDrop(cur,null,false);});
      return;
    }
    this.target?._dropT.leave?.(this.target);
    this.target = null; this.cur = null; this.cand = null;
    this.icon.style.display = 'none';
    cur.payload.onCancel?.();
    this.mgr.emit('dragend', { payload: cur.payload, target: null, done: false });
  }
  dispose() {
    this.disposed=true;
    removeEventListener('pointermove', this._move, true);
    removeEventListener('pointerup', this._up, true);
    removeEventListener('pointerdown', this._down, true);
    removeEventListener('keydown', this._key, true);
    removeEventListener('contextmenu', this._ctx, true);
    removeEventListener('click', this._click, true);
    removeEventListener('dblclick', this._dblclick, true);
  }
}

// control mixins
UIControl.prototype.makeDraggable = function (fn, opts = {}) {
  this._drag = fn; this._dragOpts = opts;
  this.el.classList.add('uw-hit');
  return this;
};
UIControl.prototype.acceptDrop = function (handlers) {
  this._dropT = handlers;
  this.el.classList.add('uw-hit');
  return this;
};
