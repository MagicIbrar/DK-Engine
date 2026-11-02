// Lane 64: 4.2.0 render consumer for map-event FadeInOut (Global Ghost::UIHandler::Handler::Environment::FadeWnd).
// Sources (Global client + Global data, read-only):
//   - game2/ui_fadewnd.txt: window "fadewnd", layer 5000, alwaysontop, rect 0 0 0 0 (full screen), panel pan_back
//     image color FF010101. 4.2.0 uiwin maps a Global layer to the CSS z-index 1:1 (src/ui/uiwin/controls.js).
//   - FadeShowMsg 0x30050001 opens it, FadeMsg 0x30050003 {byte dir, u32 ms} drives alpha, FadeHideMsg 0x30050002 closes it.
//   - dir 1 (FadeInOut mode 1, slot 0xe0): alpha (1-t)*255 then the window hides; dir 0 (mode 0, slot 0xe8): alpha t*255,
//     stays opaque. t = clamp(elapsed/ms). Frame deltas over 1000 ms are ignored.
//   - Reference End (FUN_7ff6714e4020) calls the same fade owner slot 0xf0 (hide), so a map-event end clears the fade.
import { MAP_EVENT_FADE, mapEventFadeAlpha } from './map-event-runner.js';

export const FADEWND_SPEC = Object.freeze({
  script: 'game2/ui_fadewnd.txt', window: 'fadewnd', layer: 5000, alwaysOnTop: true, colorArgb: 0xff010101, css: 'rgb(1, 1, 1)',
});

/** FadeWnd consumer. doc is optional (Node tests run without a DOM). */
export function createFadeWnd({ doc = globalThis.document, mount = null } = {}) {
  const st = { visible: false, mode: null, duration: 0, elapsed: 0, alpha: 0, el: null, log: [] };
  const element = () => {
    if (st.el || !doc?.createElement) return st.el;
    const d = doc.createElement('div');
    if (d.dataset) d.dataset.globalWindow = FADEWND_SPEC.window;
    Object.assign(d.style || (d.style = {}), {
      position: 'fixed', left: '0', top: '0', width: '100%', height: '100%', background: FADEWND_SPEC.css,
      pointerEvents: 'none', zIndex: String(FADEWND_SPEC.layer), opacity: '0', display: 'none',
    });
    (mount || doc.body)?.appendChild?.(d);
    st.el = d;
    return d;
  };
  const paint = () => {
    const d = element();
    if (!d) return;
    d.style.display = st.visible ? 'block' : 'none';
    d.style.opacity = String(st.alpha / 255);
  };
  const api = {
    state: st,
    show() { st.visible = true; st.log.push(MAP_EVENT_FADE.messages.show); paint(); },
    hide() { st.visible = false; st.mode = null; st.alpha = 0; st.elapsed = 0; st.log.push(MAP_EVENT_FADE.messages.hide); paint(); },
    fade(mode, durationMs) {
      if (mode !== 0 && mode !== 1) return;
      if (!st.visible) api.show();
      st.mode = mode; st.duration = Math.max(0, Number(durationMs) || 0); st.elapsed = 0;
      st.alpha = mapEventFadeAlpha(mode, 0, st.duration);
      st.log.push(MAP_EVENT_FADE.messages.fade);
      paint();
    },
    update(dtMs) {
      if (!st.visible || st.mode == null) return;
      const d = Number(dtMs);
      if (!(d >= 0) || d > MAP_EVENT_FADE.maxFrameDeltaMs) return; // Global ignores frame deltas over 1000 ms
      st.elapsed += d;
      st.alpha = mapEventFadeAlpha(st.mode, st.elapsed, st.duration);
      if (st.mode === 1 && st.elapsed >= st.duration) { api.hide(); return; } // dir 1 hides when done
      paint();
    },
    dispose() { st.el?.remove?.(); st.el = null; },
  };
  return api;
}