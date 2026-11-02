// Screen-space clearance between the projected head and the bottom of its nameplate.
// Player head effects rise above that point. Worn emblems use native modeleffect
// art above the head, so the plate needs extra clearance while one is equipped.
// Transparent native quads and held particle trails can extend much farther than
// the visible head art. Keep that clearance within a compact presentation band;
// the native artwork, attachment and animation remain unchanged.
import {nativeOverheadTop} from './native-overhead-bounds.js';

// ENGINE-DEFAULT (configurable), scan-fix 2026-10-29: the screen gaps below (6 px monsters/NPCs, 30 px players, 72..128 px
// with an emblem) are this engine's. Global positions plates in the exe (no ui_*.txt, option.txt or csv carries an overhead
// offset; the exe-side placement was not traced); the emblem art itself is native modeleffect.
export const MAX_EMBLEM_NAMEPLATE_GAP = 128;

export function nameplateHeadGap(actor,game=null,projection=null,viewport=null) {
  if (actor?.kind !== 'player') return 6;
  if(!actor.save?.equipment?.emblem)return 30;
  const top=projection&&nativeOverheadTop(actor,game,viewport);
  return Number.isFinite(top)?Math.min(MAX_EMBLEM_NAMEPLATE_GAP,Math.max(72,projection.y-top+6)):72;
}
