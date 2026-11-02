// Launch loading bar pacing (4.3.2 workstream E). ONE ROW PER STAGE, in Global Procmon first-open order
// (interface -> scene -> preload), with ENGINE-CHOSEN unknowns (datasync first, shaders last) at their edges.
//   stage    : the engine's launch stage id (the same ids the launch reports progress under, and the ids
//              tools/lane-perf/procmon-compare.mjs prints for Global's trace).
//   share    : the part of the bar (0..1, the column sums to 1) the stage fills.
//   targetMs : how long that part of the bar takes to fill when the load keeps up: the bar's steady fill rate for
//              the stage is share/targetMs. A load running ahead is caught up (catchUpMs); a load running behind
//              holds the bar where the real work is (it never shows more than is done).
//   source   : 'ENGINE-CHOSEN' until a row is replaced by GLOBAL-TRACE numbers from Global's CLIENT load
//              (asset opens / bar %) - never GameGuard limp / grey-screen wait.
//
// WIRED 2026-10-28 ~12:00 AM America/Los_Angeles (owner pt300u / pt310u): Global client 0-100 Procmon
//   CSV: Temp\dekaron-load-compare\global-0-100-20261027-231624.filtered.csv
//   LIVE-COMPARE: 4.1.1\LIVE-COMPARE\global-0-100-20261027-231624.compare.json
//   Global process dekaron.exe launchMs=39500 (end: sound\bgm\bgm_mal_login.mp3)
//   Global chron first-open: interface -> scene -> preload. Concurrent first-opens (interface+scene at t=0)
//   split the early window by file count so interface is not crushed to 1ms (0-10 crawl fix).
//   Catch-up / finish stay near-instant so displayed tracks real work (never idle behind finished work).
export const LAUNCH_PACING = Object.freeze([
  Object.freeze({ stage: 'datasync',  share: 0.05,  targetMs: 400,   source: 'ENGINE-CHOSEN' }), // UNKNOWN in the trace: ENGINE-CHOSEN row kept
  Object.freeze({ stage: 'interface', share: 0.3,   targetMs: 16712, source: 'GLOBAL-TRACE global-0-100-20261027-231624.filtered.csv' }),
  Object.freeze({ stage: 'scene',     share: 0.061, targetMs: 3372,  source: 'GLOBAL-TRACE global-0-100-20261027-231624.filtered.csv' }),
  Object.freeze({ stage: 'preload',   share: 0.349, targetMs: 19416, source: 'GLOBAL-TRACE global-0-100-20261027-231624.filtered.csv' }),
  Object.freeze({ stage: 'shaders',   share: 0.24,  targetMs: 2200,  source: 'ENGINE-CHOSEN' }), // UNKNOWN in the trace: ENGINE-CHOSEN row kept
]);
// Near-instant catch-up so a fast asset load never idles behind finished work (Global client 0-100 feel).
export const LAUNCH_CATCH_UP_MS = 80;
// Once ALL launch work is done, straight run to 100% (at most this long for a full bar).
export const LAUNCH_FINISH_MS = 200;
// The longest frame step the bar integrates (a hidden tab / long task must not jump the bar).
export const LAUNCH_MAX_STEP_MS = 50;
