// CHANNEL-SWITCH / dungeon / PvP map bar: WIRED into enterMap showLoading (game.js + screens.js).
// t104u: map bar MUST track REAL load (screens.js trackReal). MAP_PACING still validates stage
// shares for presentComplete finish polish; catch-up is near-instant so displayed ~= real.
// Methodology matches GLOBAL-TRACE launch pacing (engine-chosen-launch-pacing.js): steady stage
// fill, near-instant catch-up, short finish — constant faster feel, no idle/hold spikes.
// Stage ms remain ENGINE-CHOSEN until a travel Procmon fills true Global map-change timings.
import { MAP_CHANGE_HITCH } from '../engine/map-change-hitch.js';

export const MAP_PACING_PROCMON_BLOCKED = true;

export const MAP_PACING = Object.freeze([
  Object.freeze({ stage: 'world',         share: 0.28, targetMs: 600,  source: 'ENGINE-CHOSEN (constant/no-spike; Global travel Procmon pending)' }),
  Object.freeze({ stage: 'actors',        share: 0.18, targetMs: 340,  source: 'ENGINE-CHOSEN (constant/no-spike; Global travel Procmon pending)' }),
  Object.freeze({ stage: 'globalPreload', share: 0.14, targetMs: 270,  source: 'ENGINE-CHOSEN (constant/no-spike; Global travel Procmon pending)' }),
  Object.freeze({ stage: 'artwork',       share: 0.18, targetMs: 400,  source: 'ENGINE-CHOSEN (constant/no-spike; Global travel Procmon pending)' }),
  Object.freeze({ stage: 'shaders',       share: 0.22, targetMs: MAP_CHANGE_HITCH.settleShaderMs, source: 'ENGINE-CHOSEN (constant/no-spike; Global travel Procmon pending)' }),
]);

/** Near-instant catch-up so the map bar tracks real work (t104u / launch-pacing methodology). */
export const MAP_CATCH_UP_MS = 16;
export const MAP_FINISH_MS = 120;
export const MAP_MAX_STEP_MS = 50;
