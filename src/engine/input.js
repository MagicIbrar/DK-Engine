// Keyboard + mouse state with per-frame edge detection and click-vs-drag separation.
const DRAG_THRESHOLD = 5; // px
const GAMEPAD_DEAD_ZONE = 0.2;

function activeGamepad(pads) {
  const pad = Array.from(pads || []).find(p => p?.connected !== false && p?.mapping === 'standard' && p.axes?.length >= 2)
    || Array.from(pads || []).find(p => p?.connected !== false && p?.axes?.length >= 2);
  return pad || null;
}

function stick(pad, axis) {
  const x = Number(pad?.axes?.[axis]) || 0, y = Number(pad?.axes?.[axis + 1]) || 0;
  const length = Math.hypot(x, y);
  if (!Number.isFinite(length) || length < GAMEPAD_DEAD_ZONE) return { x: 0, y: 0 };
  const strength = Math.min(1, (length - GAMEPAD_DEAD_ZONE) / (1 - GAMEPAD_DEAD_ZONE));
  return { x: x ? x / length * strength : 0, y: y ? y / length * strength : 0 };
}

export function gamepadMovement(pads) {
  const pad = activeGamepad(pads), move = stick(pad, 0), look = stick(pad, 2);
  return { moveX: move.x, moveY: -move.y || 0, lookX: look.x, lookY: look.y };
}

export class Input {
  constructor(canvas) {
    this.canvas = canvas;
    this.keys = new Set();
    this.pressed = new Set();   // went down this frame
    this.released = new Set();
    this.mouse = { x: 0, y: 0, nx: 0, ny: 0, buttons: 0, wheel: 0, dx: 0, dy: 0 };
    this.clicks = [];            // [{button, x, y, nx, ny, shift, ctrl}] completed clicks (not drags) this frame
    this.held = { left: false, right: false, middle: false };
    this.dragging = { left: false, right: false, middle: false };
    this.mobile = { moveX: 0, moveY: 0 };
    this.gamepad = { moveX: 0, moveY: 0, lookX: 0, lookY: 0 };
    this._down = {};
    this.enabled = true;

    const isTyping = () => {
      const el = document.activeElement;
      return el && (el.tagName === 'INPUT' || el.tagName === 'TEXTAREA' || el.isContentEditable);
    };
    window.addEventListener('keydown', e => {
      if (isTyping()) return;
      const k = e.code;
      if (!this.keys.has(k)) this.pressed.add(k);
      this.keys.add(k);
      if (['Tab', 'Space', 'F1', 'F2', 'F3', 'F4', 'F5'].includes(k) || (e.ctrlKey && k !== 'KeyC' && k !== 'KeyV')) e.preventDefault();
    });
    window.addEventListener('keyup', e => {
      this.keys.delete(e.code); this.released.add(e.code);
      if (['KeyW','KeyA','KeyS','KeyD'].includes(e.code) && !['KeyW','KeyA','KeyS','KeyD'].some(key => this.keys.has(key))) canvas.dispatchEvent(new Event('inputrelease'));
    }, true);
    const releaseHeld = () => {
      for (const key of this.keys) this.released.add(key);
      this.keys.clear(); this.pressed.clear();
      this.held.left = this.held.right = this.held.middle = false;
      this.dragging.left = this.dragging.right = this.dragging.middle = false;
      this._down = {}; this.clicks.length = 0;
      this.mobile.moveX = this.mobile.moveY = 0;
      this.gamepad.moveX = this.gamepad.moveY = this.gamepad.lookX = this.gamepad.lookY = 0;
      this._touch = null;
      canvas.dispatchEvent(new Event('inputrelease'));
    };
    window.addEventListener('blur', releaseHeld);
    window.addEventListener('pagehide', releaseHeld);
    document.addEventListener('visibilitychange', () => { if (document.hidden) releaseHeld(); });
    document.addEventListener('focusin', () => { if (isTyping()) releaseHeld(); });

    const btnName = b => (b === 0 ? 'left' : b === 2 ? 'right' : 'middle');
    const isTextField = el => el && (el.tagName === 'INPUT' || el.tagName === 'TEXTAREA' || el.isContentEditable);
    // Never show the browser's context menu in-game (the original client has none); text fields keep theirs.
    window.addEventListener('contextmenu', e => { if (!isTextField(e.target)) e.preventDefault(); });
    const press = e => {
      this.mouse.x=e.clientX;this.mouse.y=e.clientY;Object.assign(this.mouse,this._ndc(e.clientX,e.clientY));
      const n = btnName(e.button);
      this.held[n] = true;
      this._down[n] = { x: e.clientX, y: e.clientY, moved: 0 };
    };
    canvas.addEventListener('mousedown', e => { press(e); canvas.focus?.(); });
    // Right/middle-drag turns the camera from anywhere on screen, even when it starts over a HUD panel
    // (small viewports are mostly covered by the 1024x768-sized interface). Left clicks stay canvas-only.
    window.addEventListener('mousedown', e => {
      if (e.target === canvas || e.button === 0 || isTextField(e.target)) return;
      press(e);
    });
    const scrollableUnder = el => {
      for (; el && el !== document.body; el = el.parentElement) {
        const s = getComputedStyle(el);
        if (/(auto|scroll)/.test(s.overflowY) && el.scrollHeight > el.clientHeight) return true;
      }
      return false;
    };
    // Wheel zoom also works over non-scrolling HUD pieces; scrollable lists (chat, windows) keep their scroll.
    window.addEventListener('wheel', e => {
      if (e.target === canvas || scrollableUnder(e.target) || isTextField(e.target)) return;
      this.mouse.wheel += Math.sign(e.deltaY);
    }, { passive: true });
    window.addEventListener('mouseup', e => {
      const n = btnName(e.button);
      const d = this._down[n];
      if (d && this.held[n] && !this.dragging[n] && e.target === canvas) {
        this.clicks.push({ button: n, x: e.clientX, y: e.clientY, ...this._ndc(e.clientX, e.clientY), shift: e.shiftKey, ctrl: e.ctrlKey });
      }
      this.held[n] = false; this.dragging[n] = false; this._down[n] = null;
    });
    window.addEventListener('mousemove', e => {
      this.mouse.dx += e.movementX; this.mouse.dy += e.movementY;
      this.mouse.x = e.clientX; this.mouse.y = e.clientY;
      Object.assign(this.mouse, this._ndc(e.clientX, e.clientY));
      for (const n of ['left', 'right', 'middle']) {
        const d = this._down[n];
        if (d && !this.dragging[n] && Math.hypot(e.clientX - d.x, e.clientY - d.y) > DRAG_THRESHOLD) this.dragging[n] = true;
      }
    });
    canvas.addEventListener('wheel', e => { this.mouse.wheel += Math.sign(e.deltaY); e.preventDefault(); }, { passive: false });
    // A tap is the same world click as a mouse release. A drag turns the camera;
    // it must not issue a move/attack order at the start of a camera gesture.
    if (canvas.style) canvas.style.touchAction = 'none';
    canvas.addEventListener('pointerdown', e => {
      if (e.pointerType !== 'touch' || this._touch) return;
      e.preventDefault();
      this._touch = { id: e.pointerId, x: e.clientX, y: e.clientY, lastX: e.clientX, lastY: e.clientY, dragging: false };
      canvas.setPointerCapture?.(e.pointerId);
    });
    window.addEventListener('pointermove', e => {
      const t = this._touch;
      if (!t || e.pointerId !== t.id) return;
      e.preventDefault();
      if (!t.dragging && Math.hypot(e.clientX - t.x, e.clientY - t.y) > DRAG_THRESHOLD) {
        t.dragging = true;
        this.held.right = true;
      }
      if (t.dragging) {
        this.mouse.dx += e.clientX - t.lastX;
        this.mouse.dy += e.clientY - t.lastY;
      }
      t.lastX = e.clientX; t.lastY = e.clientY;
    });
    const endTouch = (e, canceled = false) => {
      const t = this._touch;
      if (!t || e.pointerId !== t.id) return;
      e.preventDefault();
      if (!canceled && !t.dragging) {
        const ndc = this._ndc(e.clientX, e.clientY);
        this.mouse.x = e.clientX; this.mouse.y = e.clientY;
        Object.assign(this.mouse, ndc);
        this.clicks.push({ button: 'left', x: e.clientX, y: e.clientY, ...ndc, shift: false, ctrl: false });
      }
      this.held.right = false;
      this._touch = null;
      if (canvas.hasPointerCapture?.(e.pointerId)) canvas.releasePointerCapture?.(e.pointerId);
    };
    window.addEventListener('pointerup', e => endTouch(e));
    window.addEventListener('pointercancel', e => endTouch(e, true));
    this.mouseOverCanvas = true;
    canvas.addEventListener('mouseenter', () => { this.mouseOverCanvas = true; });
    canvas.addEventListener('mouseleave', () => { this.mouseOverCanvas = false; });
  }

  _ndc(x, y) {
    const r = this.canvas.getBoundingClientRect();
    return { nx: ((x - r.left) / r.width) * 2 - 1, ny: -((y - r.top) / r.height) * 2 + 1 };
  }

  down(code) { return this.enabled && this.keys.has(code); }
  hit(code) { return this.enabled && this.pressed.has(code); }

  pollGamepad(getGamepads = () => globalThis.navigator?.getGamepads?.() || []) {
    const focused = globalThis.document?.activeElement;
    const typing = focused && (focused.tagName === 'INPUT' || focused.tagName === 'TEXTAREA' || focused.isContentEditable);
    if (!this.enabled || globalThis.document?.hidden || typing) {
      this.gamepad.moveX = this.gamepad.moveY = this.gamepad.lookX = this.gamepad.lookY = 0;
      return;
    }
    try { Object.assign(this.gamepad, gamepadMovement(getGamepads())); }
    catch { this.gamepad.moveX = this.gamepad.moveY = this.gamepad.lookX = this.gamepad.lookY = 0; }
  }

  /** Call once at the end of every frame. */
  endFrame() {
    this.pressed.clear(); this.released.clear(); this.clicks.length = 0;
    this.mouse.wheel = 0; this.mouse.dx = 0; this.mouse.dy = 0;
  }
}
