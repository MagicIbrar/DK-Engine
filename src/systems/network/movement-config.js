// MOVE-NO-RUBBERBAND: every tunable of client-predicted shared movement in one place.
//
// The original Global client data does not ship any server movement-validation threshold (share/pc/pcclass.csv only
// has Speed_WALK 2.5; no speed-hack / latency / correction values exist in the install), so EVERY value below is
// ENGINE-CHOSEN. Movement SPEED itself is never chosen here: it stays the host's canonical speed
// (server/world/movement-speed.mjs: class run stride x buffs x GM x native vehicle option 43).
//
// Model: the local player is client-predicted. Each move/stop intent carries the position the client is actually at
// (px/pz), a movement sequence (mseq), the last forced-correction revision it has seen (prev) and its estimate of the
// server clock (mt). The host accepts that position when it is physically possible (distance budget below, walkable,
// line of sight or a short path) and echoes it back; the client acknowledges the echo WITHOUT moving the body.
// The body only moves to the host's pose when the host bumps posRev: a forced displacement (teleport, map change,
// revive, knockback, GM summon) or a truly impossible report (anti-cheat).
export const MOVEMENT_SYNC = Object.freeze({
  // ---- anti-cheat bound (host) - ENGINE-CHOSEN
  /** Refill uses canonical host speed. Bunched delivery spends the finite burst bank below; it cannot double sustained speed. */
  SPEED_TOLERANCE: 1.0,
  /** Unused travel allowance banks for at most this many seconds (absorbs latency spikes / bunched delivery). */
  BURST_SECONDS: 1.5,
  /** Maximum rounding debt (float error, client/host collision rounding); every distance spent must be repaid by host time. */
  SLACK_CELLS: 0.5,
  /** The fastest speed seen in this window still counts (buff expiry, dismount, slow debuff landing mid-move). */
  SPEED_MEMORY_MS: 2000,
  /** A report may end this close to a blocked cell (client/host collision rounding at wall edges). */
  COLLISION_TOLERANCE_CELLS: 0.75,
  /** Reports already in flight when a skill lock / mount cast starts on the host are still accepted for this long. */
  BLOCK_GRACE_MS: 400,
  /** ENGINE-CHOSEN (RUBBERBAND-RELEASE): the host clears a finished skill/mount lock only on its next 100 ms tick, while
   *  the client resumes the moment its own lock ends. A report that arrives while the host still holds the lock and has
   *  moved at most this long at full speed from the last accepted pose is deferred (not applied, not punished); the
   *  next report after the host releases is measured from the same pose, so cheating gains nothing. */
  BLOCK_RELEASE_MS: 300,
  /** ENGINE-CHOSEN: a rejected report closer than this to the host pose is eased back (tween), not hard-snapped. */
  REJECT_SMOOTH_CELLS: 3,
  /** A reporting player who sends nothing for this long is no longer "moving" for remote viewers. */
  REPORT_IDLE_MS: 350,
  /** ENGINE-CHOSEN: ... but never shorter than this many times the mover's own report arrival spacing (peak-held,
   *  slow decay), which stretches on a slow link; the same window decides when pose time re-anchors to host arrival. */
  REPORT_IDLE_SPACING_FACTOR: 2,
  /** ENGINE-CHOSEN: upper bound of that adaptive idle window. */
  REPORT_IDLE_MAX_MS: 1200,
  /** Pose timestamps follow the mover's own send spacing but never lag the host's arrival clock by more than this. */
  POSE_TIME_MAX_LAG_MS: 250,
  /** ENGINE-CHOSEN: a report pose time may run this far ahead of the host clock before it is rebased (uplink jitter
   *  on the first report must not compress the published motion timeline). */
  POSE_TIME_MAX_LEAD_MS: 250,

  // ---- client send / prediction - ENGINE-CHOSEN
  /** While moving the client reports its position every this many ms (10 Hz = one per host tick). */
  SEND_INTERVAL_MS: 100,
  /** Minimum spacing between two movement reports (early turn reports, final arrival report). */
  MIN_SEND_SPACING_MS: 66,
  /** ENGINE-CHOSEN: at most this many move reports in flight. A browser keeps ~6 HTTP/1.1 connections per host
   *  (one carries the event stream) and each report holds one for a full round trip, so at high latency more
   *  reports than this only queue in the browser and arrive late in bursts. Each report carries the full pose
   *  plus the previous report's point, so skipping intermediate ones loses nothing. */
  MAX_INFLIGHT_REPORTS: 3,
  /** ENGINE-CHOSEN: on a slow link the periodic report spacing stretches to measured round trip / this divisor, so
   *  reports stay evenly spaced (about 2.5 in flight) instead of bursting into the in-flight cap and pausing. */
  SEND_INTERVAL_RTT_DIVISOR: 2.5,
  /** Local lead over the last ACKED report may not exceed speed x this factor x time since that report was sent
   *  (+ LEAD_BASE_CELLS). Legit movement can never reach it; it only stops a runaway body while the host is gone. */
  LEAD_SPEED_FACTOR: 1.5,
  LEAD_BASE_CELLS: 0.25,
  /** Polling transport (relay without SSE) refresh interval while connected. Was 500 ms. */
  POLL_INTERVAL_MS: 150,
  /** ENGINE-CHOSEN: brief hold after WASD/stick release before stop/report, so 1-frame A/S or W/S gaps never stop+restart (rubberband). */
  WASD_RELEASE_DEBOUNCE_MS: 66,
  /** ENGINE-CHOSEN: on a true heading reverse within one report spacing, refund this fraction of the spent travel so zigzag spam does not exhaust the burst bank and snap. */
  REVERSE_BUDGET_REFUND: 0.85,

  // ---- remote players (viewer) - ENGINE-CHOSEN
  /** Remote players render this far behind the smoothed host clock at minimum ... */
  INTERP_DELAY_MIN_MS: 150,
  /** ... at most this far (adaptive: observed snapshot lateness + margin). On a slow link reports are spaced by the
   *  in-flight cap (MAX_INFLIGHT_REPORTS per round trip), so lateness can reach spacing + pose-time lag + a tick. */
  INTERP_DELAY_MAX_MS: 800,
  INTERP_DELAY_MARGIN_MS: 25,   // lane-core: tick/4 (SEND_INTERVAL 100); sim.mjs: errVsLive p50/p99 -0.1 cell at jitter 0/60/150, shapeErr p99 stays 0
  /** ... plus this share of the observed lateness spread (worst - best) as extra headroom for jitter tails. */
  INTERP_SPREAD_HEADROOM: 0.25,
  /** Until this many poses have been measured, a newly seen remote is buffered at least INTERP_DELAY_START_MS. */
  INTERP_WARMUP_SAMPLES: 6,
  INTERP_DELAY_START_MS: 220,
  /** When the buffer runs dry a moving remote continues on its last velocity for at most this long. */
  EXTRAPOLATE_MS: 250,
  /** Typical run stride (cells/s) used to time how a standing remote sets off toward its first moving pose. */
  REMOTE_START_SPEED: 4,
  // ENGINE-CHOSEN: how long the worst observed pose lateness is remembered when sizing the remote buffer, and how
  // fast the render clock may slow down (25 %) or catch up (10 %) when that buffer size changes.
  INTERP_MEMORY_MS: 6000,
  RENDER_SLOW_RATE: 0.25,
  RENDER_FAST_RATE: 0.1,
  // ENGINE-CHOSEN: after an extrapolated overshoot a remote holds still (never steps back) for at most this long.
  OVERSHOOT_HOLD_MS: 300,
  /** Larger jumps than this between two samples are teleports: placed directly, never tweened across the map. */
  TELEPORT_CELLS: 10,
});
