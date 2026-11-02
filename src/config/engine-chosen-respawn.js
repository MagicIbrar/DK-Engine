// USER-REQUESTED / ENGINE-CHOSEN ordinary town return wait (ms).
// Evidence ranking (Lane 22 / 09):
//   - formula.ini dwReviveTick=4000 loads into the native client formula struct (offset +0x58) but has NO
//     client apply site that drives the ordinary death-window Accept countdown (load-only in decompile).
//   - dwPVPReviveTick=1 is the duel/event reincarnate delay (no apply site reads it; the duel restore wait is pvp-rules restoreWaitSec 15, decompile DeadRestoreWnd) — different key.
//   - dwLosingRightTime=10000 is a different formula key (ownership/right timer), not the death-window wait.
//   - Guide Normal Death Window documents Accept / Life Bead / Blessed options, not a universal ms duration.
// Left at 10000 until a native apply site evidences another value. Do not substitute dwReviveTick.
export const ORDINARY_RESPAWN_WAIT_MS=10000;
