// Original mouse cursors (script/ui/mouse.csv -> texturepack/mouse/*.tpack -> texture/etc/*.dds, 32x32,
// hotspot top-left; docs/formats/ui.md §4). Animated cursors swap frames every 150 ms.
import { atlas } from './atlas.js';

export const CURSORS = {
  normal: ['texture/etc/cursor_01.dds'],
  attack: ['texture/etc/attack1.dds', 'texture/etc/attack2.dds', 'texture/etc/attack3.dds'],
  talk: ['texture/etc/talk_01.dds', 'texture/etc/talk_02.dds', 'texture/etc/talk_03.dds'],
  grip: ['texture/etc/cursor_05-1.dds', 'texture/etc/cursor_05-2.dds'],
};
const FALLBACK = { normal: 'default', attack: 'crosshair', talk: 'pointer', grip: 'grabbing' };
const FRAME_MS = 150;

// 2.2.1: the game cursor over the DOM UI too (the map and quest windows showed the Windows arrow). Every window
// lives in #ui, a sibling of the canvas, so the canvas's inline cursor (CursorManager below) never reached them, and the
// controls' own cursor:pointer / auto showed the OS cursor. One injected rule gives #ui and everything in it the original
// normal cursor (mouse.csv 'normal' = normal.tpack = cursor_01.dds, a single frame). The canvas keeps its animated attack /
// talk cursors (its inline style beats this plain #game rule); the front-end's busy cursor (frontend.css body.fe-wait
// !important) still wins; the GM tool panels (.gmk, engine-only) keep their crosshair / grab cursors. Where the original
// shows its other cursor kinds (input, minimap, tooltip...) is not in the data (the window scripts never name a cursor).
const UI_CURSOR_CSS = ':root.dk-gcur body:not(.fe-wait) #ui, :root.dk-gcur body:not(.fe-wait) #ui *:not(.gmk):not(.gmk *) { cursor: var(--dk-cur-normal) !important; }\n'
  + ':root.dk-gcur #game { cursor: var(--dk-cur-normal); }';
let uiCursorInstall = null;
/** Install the normal cursor on the page's UI and canvas (main.js, at boot: login, select and loading screens too). */
export function installUICursor() {
  if (uiCursorInstall) return uiCursorInstall;
  uiCursorInstall = (async () => {
    try {
      const doc = globalThis.document, root = doc?.documentElement;
      if (!doc?.head || typeof doc.createElement !== 'function' || typeof root?.style?.setProperty !== 'function' || !root.classList?.add) return false;
      const t = await atlas.texture(CURSORS.normal[0]).catch(() => null);
      const url = t?.canvas?.toDataURL ? t.canvas.toDataURL('image/png') : null;
      if (!url) return false;
      if (!(typeof doc.getElementById === 'function' && doc.getElementById('dk-cursor-css'))) {
        const style = doc.createElement('style');
        style.id = 'dk-cursor-css';
        style.textContent = UI_CURSOR_CSS;
        doc.head.appendChild(style);
      }
      root.style.setProperty('--dk-cur-normal', `url("${url}") 0 0, ${FALLBACK.normal}`);
      root.classList.add('dk-gcur');
      return true;
    } catch { return false; }   // no DOM (tests) or a storage / decode failure: the OS cursor stays, as before
  })();
  return uiCursorInstall;
}

export class CursorManager {
  constructor(el) {
    this.el = el;
    this.kind = null;
    this.frames = {};      // kind -> [css cursor strings]
    this._frame = -1;
    this._t = 0;
    this._loading = this._load();
    this._loading.catch(() => {});
  }

  async _load() {
    for (const [kind, keys] of Object.entries(CURSORS)) {
      const frames = [];
      for (const k of keys) {
        const t = await atlas.texture(k).catch(() => null);
        let url = null;
        try { url = t?.canvas?.toDataURL ? t.canvas.toDataURL('image/png') : null; } catch { url = null; }
        if (url) frames.push(`url("${url}") 0 0, ${FALLBACK[kind]}`);
      }
      if (frames.length) this.frames[kind] = frames;
    }
    this._frame = -1; // force refresh
  }

  set(kind) {
    if (kind !== this.kind) { this.kind = kind; this._t = 0; this._frame = -1; }
  }

  update(dt) {
    if (!this.el?.style) return;
    const frames = this.frames[this.kind || 'normal'];
    let css;
    if (frames && frames.length) {
      this._t += dt * 1000;
      const f = Math.floor(this._t / FRAME_MS) % frames.length;
      if (f === this._frame) return;
      this._frame = f;
      css = frames[f];
    } else {
      css = FALLBACK[this.kind || 'normal'];
      if (this._frame === -2 && this._css === css) return;
      this._frame = -2;
    }
    if (this._css !== css) { this._css = css; this.el.style.cursor = css; }
  }
}
