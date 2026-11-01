// The front-end's link to the UI platform (src/ui/uiwin, docs/UIWIN.md): every login / select / create / loading
// window is the original window script built by uiwin. This adds what the front-end screens need on top of it:
//   frontUI(root)                  a UIManager without a Game (sounds on, interface scale fitted to small screens)
//   cloneTemplate(win, id, ...)    instantiate a template control at runtime (the client clones btn_serverlist /
//                                  pan_char_list per server / class; their scripts ship them enable false visible false)
//   rich(text)                     client string markup -> uiwin rich text (<center> lines are centred by the
//                                  control's own align; literal "\n" -> line breaks)
import { UIManager, createControl } from '../uiwin/index.js';

/** A UIManager for the front-end (no Game). The layer scales down below the 1024x700 reference, 1:1 above. */
export function frontUI(rootEl) {
  const mgr = new UIManager(null, rootEl, { scale: 1 });
  mgr.soundsEnabled = true;
  // The UIManager now auto-fits itself to the window (manager.resize); the base scale stays 1 here so it isn't fitted twice.
  const fit = () => { if (mgr.baseScale !== 1) mgr.setScale(1); else mgr.resize(); };
  fit();
  globalThis.addEventListener?.('resize', fit);
  const dispose = mgr.dispose.bind(mgr);
  mgr.dispose = () => { globalThis.removeEventListener?.('resize', fit); dispose(); };
  return mgr;
}

const deepCopySpec = s => {
  const out = Array.isArray(s) ? [] : {};
  for (const [k, v] of Object.entries(s)) out[k] = v && typeof v === 'object' ? deepCopySpec(v) : v;
  return out;
};

/**
 * A new control built from the spec of a template control (same parent), shown and enabled.
 * @param {import('../uiwin/window.js').UIWindow} win
 * @param {string} id       template control id
 * @param {string} newId
 * @param {number[]} [rect] [x, y, w, h] parent-relative
 */
export function cloneTemplate(win, id, newId, rect = null) {
  const src = win.find(id);
  if (!src?.parent) return null;
  const spec = deepCopySpec(src.spec);
  spec.id = newId;
  spec.visible = true;
  spec.enable = true;
  if (rect) spec.rect = rect.slice();
  const c = createControl(win, spec, src.parent);
  src.parent.children.push(c);
  src.parent.el.appendChild(c.el);
  if (src.parent.box) c.layout(src.parent.box);
  win._indexControls?.();
  return c;
}

/** Client markup -> uiwin rich text: literal "\n" become line breaks, <center> is dropped (the label centres). */
export function rich(text) {
  return String(text ?? '').replace(/\\n/g, '\n').replace(/<center>/gi, '').replace(/<\/center>/gi, '');
}
