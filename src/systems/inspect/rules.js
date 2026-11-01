// Inspect player rules (pure, node-testable): who /inspect and the player menu open, and the zoom slider mapping.
// Window: game2/previewplayer/ui_previewplayerwnd.txt. ENGINE-CHOSEN values: src/config/engine-chosen-inspect.js.
import { INSPECT_ENGINE_CHOSEN as C } from '../../config/engine-chosen-inspect.js';

export const INSPECT_SCRIPT = 'game2/previewplayer/ui_previewplayerwnd.txt';
export const INSPECT_WINDOW = 'previewplayer';
/** sld_zoom range of the script (min 1, max 76). */
export const SLIDER = Object.freeze({ min: 1, max: 76 });

const clamp = (v, a, b) => Math.max(a, Math.min(b, v));

/** Slider value (1..76) -> camera zoom (zoomRange.min..max, linear). */
export function sliderToZoom(v, s = SLIDER) {
  const f = (clamp(Number(v) || s.min, s.min, s.max) - s.min) / Math.max(1, s.max - s.min);
  return C.zoomRange.min + f * (C.zoomRange.max - C.zoomRange.min);
}
/** Camera zoom -> nearest slider value. */
export function zoomToSlider(z, s = SLIDER) {
  const f = (clamp(Number(z) || 1, C.zoomRange.min, C.zoomRange.max) - C.zoomRange.min) / (C.zoomRange.max - C.zoomRange.min);
  return Math.round(s.min + f * (s.max - s.min));
}
/** btn_zoom_in (+1) / btn_zoom_out (-1): the slider value after one press. */
export function stepSlider(v, dir, s = SLIDER) {
  return clamp(Math.round(Number(v) || s.min) + Math.sign(dir) * C.zoomButtonStep, s.min, s.max);
}
/** Zoom buttons are disabled at the slider's ends (their script has a disable image). */
export function zoomButtons(v, s = SLIDER) { return { out: Number(v) > s.min, in: Number(v) < s.max }; }

/** A character that can be inspected: a player actor that is still in the world. */
export const inspectable = a => !!a && a.kind === 'player' && !a.disposed;

/**
 * Who /inspect [name] opens: a named connected character (case-insensitive, among the ones the client sees), else
 * with no name the selected player, else yourself. -> { actor } or { error: 'notFound' | 'none' }.
 */
export function resolveInspectTarget({ name = '', target = null, player = null, players = [] } = {}) {
  const n = String(name || '').trim().toLowerCase();
  if (n) {
    if (player && String(player.name || '').toLowerCase() === n) return { actor: player };
    const hit = [...players].find(p => inspectable(p) && String(p.name || '').toLowerCase() === n);
    return hit ? { actor: hit } : { error: 'notFound' };
  }
  if (inspectable(target) && target !== player) return { actor: target };
  if (C.emptyCommandTarget === 'target-or-self' && inspectable(player)) return { actor: player };
  return { error: 'none' };
}

/** The pcpop row: shown for another player only. */
export const menuVisible = (t, player) => inspectable(t) && t !== player;

/** What the preview draws for an actor: its class, equipment meshes, weapon and wing (changes re-draw the window). */
export function lookSignature(actor, wing = null) {
  if (!actor) return '';
  const eq = actor.save?.equipment || {};
  const parts = Object.keys(eq).sort().map(k => [k, eq[k]?.mesh || null, eq[k]?.tpack || null, eq[k]?.none ? 1 : 0]);
  return JSON.stringify([actor.classDef?.skeleton || null, Number(actor.classIndex ?? -1), parts, wing ?? null]);
}

export { C as INSPECT_ENGINE_CHOSEN };