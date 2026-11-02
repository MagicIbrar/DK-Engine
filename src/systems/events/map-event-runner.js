// Map-event (dungeon cinematic) action runner, reimplemented for 4.2.0 from Global client evidence.
// Lane 49. Data: Global data/script/eventinfo/mapevent.csv (normalized by ./map-event-rules.js).
//
// Native evidence (read-only decompile/dekaron64 decompile + RTTI of the Global x64 client):
//   Loader  Ghost::DriverKernel::Table::MapEvent::Provider (FUN_7ff6708a9350): MapEvent.csv, >=14 columns,
//           index 0 rows skipped, eventType kept when (eventType-1) < 100, rows grouped by index, CSV order kept.
//   Runner  Ghost::GameHandler::Dungeon::Reference (ctor FUN_7ff6714e31c0):
//           Start(index)  FUN_7ff6714e3850  - End() first, then one action object per row (FUN_7ff6714e39f0),
//                                             Init(row) at start; type 100 creates no object and sets the
//                                             "no presentation mode" flag.
//           Tick          FUN_7ff6714e4240  - every action whose fire time <= now runs Execute once and is
//                                             deleted (single shot); after the pass a pending Leave runs End.
//           End           FUN_7ff6714e4020  - drops actions, removes every actor spawned by Enter, restores UI.
//           Skip          FUN_7ff6714e3e70  - client->server opcode 0x05260022, header only (ESC chain
//                                             FUN_7ff670986560 while a map event is playing).
//   Trigger server->client opcode 0x05260021 (dungeon handler FUN_7ff6714e5880, case 0x21): u32 index at
//           packet offset 0x10 (after the 16-byte header) -> Start(index).
//   Action classes (names from the client RTTI type descriptors; Init / Execute):
//     1 Enter       7ff671633fd0 / 7ff6716340d0     2 Move        7ff671634400 / 7ff671634540
//     5 SetAction   7ff671634c70 / 7ff671634d60     6 Talk        7ff671635640 / 7ff671635750
//     7 SetCamera   7ff671635010 / 7ff6716352c0     9 Leave       7ff671634fc0 / 7ff671635000
//    10 FadeInOut   7ff671635970 / 7ff6716359b0    11 ShowAllUI   7ff671635a20 / 7ff671635a60
//    12 BrickAction 7ff671635a90 / 7ff671635ae0   100 (no object; presentation-mode suppression flag)
//   Lane 40's MAP_EVENT_FACTORY attribution (FUN_7ff6708a1010) is NOT the map-event factory: its RTTI is
//   Ghost::DriverKernel::Data::Mesh / IData. The real factory is FUN_7ff6714e39f0.
//
// The runner only decodes rows and schedules them; every visible effect goes through injected hooks, so the
// 4.2.0 scene/camera/UI owners decide how to render. Values that the client computes are computed here exactly;
// Lane 64: former gaps are closed in MAP_EVENT_RUNNER_DECISIONS (value + source); nothing is guessed.

const n = (v) => { const x = Number(v); return Number.isFinite(x) ? x : 0; };
// Native Init uses atoi/atof on param strings: atoi truncates toward zero.
const i32 = (v) => { const x = Number.parseInt(String(v ?? '0').trim(), 10); return Number.isFinite(x) ? x | 0 : 0; };
const f32 = (v) => Math.fround(n(v));
export const DEG_TO_RAD = Math.fround(0.017453292); // constant in Enter/SetAction/SetCamera Init
export const RAD_TO_DEG = Math.fround(57.2957763671875); // float constant multiplied after atan2f in Move Execute
const EPS = Math.fround(9.99999997e-7);                    // Move absolute-target / auto-heading threshold (signed compares)
const TWO_PI = Math.fround(6.2831854820251465);           // DAT_7ff671e8504c: facing wrap, camera yaw wrap
const BYTE_TO_RAD = Math.fround(TWO_PI * 0.00390625);     // actor facing byte -> radians (DAT_..504c * DAT_..4e0c)
// Lane 64: Global facing convention. An actor's direction vector (actor data +0x24, IActor slot 0x58) is
// (-sin(theta), -cos(theta)) (remote actor build FUN_7ff6709cc2e0); Enter stores the same pair from p4 and
// Execute recovers theta with atan2f(sin, cos); Move auto-heading inverts it with atan2f(-nx, -ny).
const f32sin = (r) => Math.fround(Math.sin(Math.fround(r)));
const f32cos = (r) => Math.fround(Math.cos(Math.fround(r)));
/** Global direction vector for an angle in radians: (-sin, -cos). */
export function mapEventDirVector(rad) { return { x: Math.fround(-f32sin(rad)), y: Math.fround(-f32cos(rad)) }; }
/** Move auto-heading in degrees, exactly as Move Execute: atan2f(-nx, -ny) * 57.2957763671875. */
export function mapEventHeadingDeg(dx, dy) {
  const len = Math.hypot(dx, dy);
  const nx = len > 0 ? Math.fround(dx / len) : 0, ny = len > 0 ? Math.fround(dy / len) : 0;
  return Math.fround(Math.fround(Math.atan2(-nx, -ny)) * RAD_TO_DEG);
}

export const MAP_EVENT_OPCODES = Object.freeze({
  START: 0x05260021, // server -> client, u32 index at packet offset 0x10
  SKIP: 0x05260022,  // client -> server, 16-byte header only
  STOP: 0x05260023,  // server -> client, header only: Reference slot 0x140 (FUN_7ff6714e3ed0) requests End
  UNKNOWN_23: 0x05260023, // legacy alias kept for old callers (lane 49 name); same opcode as STOP
});
// Lane 64: FadeInOut owner. Reference+0x60 is a CFadeProducer; it opens Ghost::UIHandler::Handler::Environment::
// FadeWnd (window id 0x50) with FadeShowMsg 0x30050001, drives it with FadeMsg 0x30050003 {byte dir, u32 ms} and
// closes it with FadeHideMsg 0x30050002. FadeInOut Execute always hides first (Reference slot 0xf0), then
// mode 1 -> slot 0xe0 (FadeMsg dir 1: alpha (1-t)*255, black -> clear, window hidden when done) and
// mode 0 -> slot 0xe8 (FadeMsg dir 0: alpha t*255, clear -> black, stays opaque). t = clamp(elapsed/ms, 0, 1);
// per-frame deltas above 1000 ms are ignored by the producer.
export const MAP_EVENT_FADE = Object.freeze({
  owner: 'Ghost::UIHandler::Handler::Environment::FadeWnd', windowId: 0x50, producer: 'CFadeProducer (Reference+0x60)',
  messages: Object.freeze({ show: 0x30050001, hide: 0x30050002, fade: 0x30050003 }), maxFrameDeltaMs: 1000,
});
/** Global FadeWnd alpha (0..255) for a FadeInOut mode at elapsed ms. */
export function mapEventFadeAlpha(mode, elapsedMs, durationMs) {
  const d = n(durationMs);
  let t = d > 0 ? n(elapsedMs) / d : 1; t = t < 0 ? 0 : t > 1 ? 1 : t;
  return mode === 1 ? (1 - t) * 255 : mode === 0 ? t * 255 : null;
}
// Lane 64: SetCamera owners. Camera = Ghost::DollStage::Camera::CameraImpl (DAT_7ff6726f5300); its param block
// (slot 0x18 get / slot 0x28 set, FUN_7ff67124e280) is [f0, f1, f2, f3, f4, flag]: f0 clamped to Camera::Limit
// [l0,l1], f1 clamped to [l2,l3], f2 wrapped into [0, 2pi). Map events write f0..f2 from p4, p5(deg->rad), p6(deg->rad).
export const MAP_EVENT_CAMERA = Object.freeze({
  owner: 'Ghost::DollStage::Camera::CameraImpl', limit: 'Ghost::DollStage::Camera::Limit::LimitImpl (DAT_7ff6726f5308 slot 0x10)',
  modes: Object.freeze({ 0: 'restore', 1: 'set', 2: 'drift' }),
});
export const MAP_EVENT_HEADER_BYTES = 16;
export const MAP_EVENT_START_MESSAGE = Object.freeze([0xa10, 1, 10000, 1]); // posted when the action list is non-empty

export const MAP_EVENT_ACTION_CLASSES = Object.freeze({
  1: Object.freeze({ name: 'Enter', init: 'FUN_7ff671633fd0', execute: 'FUN_7ff6716340d0' }),
  2: Object.freeze({ name: 'Move', init: 'FUN_7ff671634400', execute: 'FUN_7ff671634540' }),
  5: Object.freeze({ name: 'SetAction', init: 'FUN_7ff671634c70', execute: 'FUN_7ff671634d60' }),
  6: Object.freeze({ name: 'Talk', init: 'FUN_7ff671635640', execute: 'FUN_7ff671635750' }),
  7: Object.freeze({ name: 'SetCamera', init: 'FUN_7ff671635010', execute: 'FUN_7ff6716352c0' }),
  9: Object.freeze({ name: 'Leave', init: 'FUN_7ff671634fc0', execute: 'FUN_7ff671635000' }),
  10: Object.freeze({ name: 'FadeInOut', init: 'FUN_7ff671635970', execute: 'FUN_7ff6716359b0' }),
  11: Object.freeze({ name: 'ShowAllUI', init: 'FUN_7ff671635a20', execute: 'FUN_7ff671635a60' }),
  12: Object.freeze({ name: 'BrickAction', init: 'FUN_7ff671635a90', execute: 'FUN_7ff671635ae0' }),
});
export const MAP_EVENT_NO_PRESENTATION_TYPE = 100;
export const MAP_EVENT_NATIVE = Object.freeze({
  loader: 'FUN_7ff6708a9350', provider: 'Ghost::DriverKernel::Table::MapEvent::Provider',
  runner: 'Ghost::GameHandler::Dungeon::Reference', start: 'FUN_7ff6714e3850', factory: 'FUN_7ff6714e39f0',
  tick: 'FUN_7ff6714e4240', end: 'FUN_7ff6714e4020', skip: 'FUN_7ff6714e3e70', packetHandler: 'FUN_7ff6714e5880',
  lane40FactoryCorrection: 'FUN_7ff6708a1010 is DriverKernel::Data::Mesh/IData, not the map-event factory',
});

export const MAP_EVENT_RUNNER_DECISIONS = Object.freeze([
  'Index binding: indices 1-5 = map 706 Hidden Mansion of Kastotica (source: Global data, see map-event-rules.js MAP_EVENT_BINDING). No automatic host trigger moment (no source; removed). GM start stays.',
  'Skip 0x05260022: answered by the host with the 0x05260023 end for that player, the only server-side terminator the Global client has (source: Global client).',
  'SetCamera f0/f1/f2 = distance/pitch/yaw via the 4.2.0 maplist mapping (source: Global client + Global maplist); CameraImpl+0x10d carried as data only (removed as behaviour).',
  'SetCamera mode 2 deltas: applied once per 4.2.0 camera update (per frame), the same cadence as Global (source: Global client FUN_7ff6714e4480 / FUN_7ff6714e3f70).',
  'Talk category 3000: Global stringtable_event.txt cate 3000 codes 1-6 (source: Global data).',
]);
/** Kept for old imports: nothing is left open. */
export const MAP_EVENT_RUNNER_UNRESOLVED = Object.freeze([]);

/** Decode one normalized row (map-event-rules.js mapEventRow shape) into the native Init fields. */
export function decodeMapEventAction(row) {
  if (!row) return null;
  const type = n(row.eventType);
  const cls = MAP_EVENT_ACTION_CLASSES[type];
  if (!cls) return null;
  const base = { type, name: cls.name, time: n(row.time), index: n(row.index) };
  switch (type) {
    case 1: { // Enter
      const deg = f32(row.p4);
      const rad = Math.fround(deg * DEG_TO_RAD);
      return { ...base, id: n(row.id), monster: n(row.monster), p1: i32(row.p1), x: f32(row.p2), y: f32(row.p3), dirDeg: deg, dirRad: rad };
    }
    case 2: // Move
      return { ...base, id: n(row.id), motion: n(row.monster), p1: i32(row.p1), targetX: f32(row.p2), targetY: f32(row.p3),
        p4: f32(row.p4), p5: f32(row.p5), p6: f32(row.p6), p7: f32(row.p7), p8: f32(row.p8) };
    case 5: // SetAction
      return { ...base, id: n(row.id), mode: n(row.monster), action: i32(row.p1) & 0xff,
        dirRad: Math.fround(f32(row.p2) * DEG_TO_RAD), duration: f32(row.p3) / 1000 };
    case 6: { // Talk
      const mode = n(row.id);
      const t = { ...base, mode, target: n(row.monster), category: i32(row.p1), textIndex: i32(row.p2), p3: i32(row.p3) };
      if (mode === 0) t.p4 = i32(row.p4);
      else if (mode === 1) Object.assign(t, { p4: f32(row.p4), p5: f32(row.p5), p6: f32(row.p6), p7: f32(row.p7) });
      return t;
    }
    case 7: { // SetCamera
      const mode = n(row.id);
      const c = { ...base, mode };
      if (mode === 1 || mode === 2) Object.assign(c, {
        f10: f32(row.p2), f14: f32(row.p1), f18: f32(row.p3), f1c: f32(row.p4),
        rad20: Math.fround(f32(row.p5) * DEG_TO_RAD), rad24: Math.fround(f32(row.p6) * DEG_TO_RAD),
        flag28: String(row.p7 ?? '').trim() === '1', // compared with the literal "1" (DAT_7ff671d3f0c4)
      });
      if (mode === 2) Object.assign(c, { driftA: i32(row.p8), driftB: i32(row.p9) });
      if (mode === 1 || mode === 2) {
        c.target = { x: c.f10, y: c.f14, z: c.f18 };            // Reference +0xac..+0xb4 (mode 1) or per-frame delta +0xc4.. (mode 2)
        c.params = [c.f1c, c.rad20, c.rad24];                    // CameraImpl f0..f2 (mode 1) or per-frame delta +0xdc.. (mode 2)
      }
      return c;
    }
    case 9: return { ...base };
    case 10: return { ...base, mode: n(row.id), duration: n(row.monster) };
    case 11: return { ...base, mode: n(row.id) };
    case 12: return { ...base, brick: n(row.id), p1: i32(row.p1) };
    default: return null;
  }
}

/** Enter: world float -> u16 cell (x * 0.001953125 * 65536, clamped 0..0xffff; float->int truncation). */
export function mapEventCell(v) {
  const t = Math.trunc(f32(v) * 0.001953125 * 65536);
  return t < 0 ? 0 : t > 0xffff ? 0xffff : t;
}
/** Enter: facing byte, float32 steps of Enter Execute: a -= trunc(a/2pi)*2pi; if a<0 a+=2pi; byte = trunc(a/2pi*256). */
export function mapEventFacingByte(rad) {
  const a0 = Math.fround(n(rad));
  const q = Math.trunc(Math.fround(a0 / TWO_PI));
  let a = Math.fround(a0 - Math.fround(q * TWO_PI));
  if (a < 0) a = Math.fround(a + TWO_PI);
  return Math.trunc(Math.fround(Math.fround(a / TWO_PI) * 256)) & 0xff;
}

export function encodeMapEventSkip() {
  const b = new Uint8Array(MAP_EVENT_HEADER_BYTES);
  new DataView(b.buffer).setUint32(0, MAP_EVENT_OPCODES.SKIP, true);
  return b;
}
/** Read the index from a Global-layout 0x05260021 packet (u32 little-endian at offset 0x10). */
export function decodeMapEventStart(bytes) {
  const u = bytes instanceof Uint8Array ? bytes : new Uint8Array(bytes || []);
  if (u.length < MAP_EVENT_HEADER_BYTES + 4) return null;
  return new DataView(u.buffer, u.byteOffset, u.byteLength).getUint32(MAP_EVENT_HEADER_BYTES, true);
}

/**
 * createMapEventRunner({ rows, now, hooks }) — rows: normalized mapEventRow list (all indices).
 * hooks (all optional): spawnActor, removeActor, resolveActor, actorPos, moveActor, setAction, stopAction,
 *   talk, dialog, camera, fade, showAllUI, brickAction, onStart, enterPresentation, endPresentation,
 *   sendSkip, log. Lane 64 adds: actorDir (IActor slot 0x58 vector), cameraParams (CameraImpl f0..f2), fadeHide.
 */
export function createMapEventRunner({ rows = [], now = () => 0, hooks = {} } = {}) {
  const byIndex = new Map();
  for (const r of rows) {
    if (!r || !(n(r.index) !== 0) || !(n(r.eventType) - 1 < 100 && n(r.eventType) >= 1)) continue; // loader rules
    const k = n(r.index);
    if (!byIndex.has(k)) byIndex.set(k, []);
    byIndex.get(k).push(r);
  }
  const h = hooks;
  const st = { playing: false, index: null, actions: [], actors: new Map(), leave: false, noPresentation: false, executed: [], cameraSaved: null };

  const actorFor = (id) => (st.actors.has(id) ? st.actors.get(id) : h.resolveActor?.(id) ?? null);

  function end() {
    const was = st.playing;
    st.actions = [];
    for (const handle of st.actors.values()) h.removeActor?.(handle);
    st.actors.clear();
    st.leave = false; st.noPresentation = false; st.cameraSaved = null;
    st.playing = false; st.index = null;
    if (was) { h.showAllUI?.(true); h.endPresentation?.(); }
  }

  function start(index) {
    end();
    const list = byIndex.get(n(index));
    if (!list) return false;
    const t0 = n(now());
    for (const r of list) {
      if (n(r.eventType) === MAP_EVENT_NO_PRESENTATION_TYPE) { st.noPresentation = true; continue; }
      const a = decodeMapEventAction(r);
      if (!a) continue;
      // SetCamera mode 1 Init saves the current CameraImpl f0..f2 (Reference slot 0xd0) for a later mode 0 restore.
      if (a.type === 7 && a.mode === 1) { const p = h.cameraParams?.(); if (Array.isArray(p) && p.length >= 3) st.cameraSaved = p.slice(0, 3).map(Number); }
      st.actions.push({ ...a, fireAt: t0 + a.time }); // row.time is milliseconds (Time::Provider slot 0x58)
    }
    st.index = n(index); st.playing = true;
    if (st.actions.length) h.onStart?.({ index: st.index, message: MAP_EVENT_START_MESSAGE });
    if (!st.noPresentation) h.enterPresentation?.({ index: st.index });
    return true;
  }

  function exec(a) {
    switch (a.type) {
      case 1: {
        if (st.actors.has(a.id)) return;
        // Init stores (-sin, -cos) of p4 radians; Execute recovers theta = atan2f(sin, cos) and wraps it.
        const dv = mapEventDirVector(a.dirRad);
        const theta = Math.fround(Math.atan2(-dv.x, -dv.y));
        const facing = mapEventFacingByte(theta);
        const handle = h.spawnActor?.({ id: a.id, monster: a.monster, p1: a.p1, x: a.x, y: a.y,
          cellX: mapEventCell(a.x), cellY: mapEventCell(a.y), dirRad: a.dirRad, facing, dir: dv, transparency: 1 });
        if (handle != null) st.actors.set(a.id, handle);
        return;
      }
      case 2: {
        if (a.motion > 0x36) return;
        const handle = actorFor(a.id); if (handle == null) return;
        const pos = h.actorPos?.(handle) || { x: 0, y: 0 };
        // Global: absolute iff p2 >= eps OR p3 >= eps (signed compares, not magnitude).
        const absolute = a.targetX >= EPS || a.targetY >= EPS;
        let target = null, dx = 0, dy = 0, dist = 0, heading = a.p7, headingDeg = null;
        if (absolute) {
          target = { x: a.targetX, y: a.targetY };
          dx = Math.fround(a.targetX - pos.x); dy = Math.fround(a.targetY - pos.y);
          dist = Math.fround(Math.sqrt(dx * dx + dy * dy));
          if (a.p7 < EPS) { headingDeg = mapEventHeadingDeg(dx, dy); heading = headingDeg; } // written back into p7
        } else {
          // Relative: target = actor position (IActor slot 0x50) + actor direction vector (slot 0x58); dist stays 0.
          const dir = h.actorDir?.(handle);
          if (dir && Number.isFinite(dir.x) && Number.isFinite(dir.y)) target = { x: Math.fround(pos.x + dir.x), y: Math.fround(pos.y + dir.y) };
        }
        // CActorEnterMoveMsg: {handle, motion, p1, pos, target, 5, p4, [dist, p5, p7(heading), p6, p8]}
        h.moveActor?.({ handle, id: a.id, motion: a.motion, p1: a.p1, absolute, from: { x: pos.x, y: pos.y }, target,
          dist, dx, dy, headingDeg, p4: a.p4, p5: a.p5, p6: a.p6, p7: heading, p8: a.p8,
          message: 'CActorEnterMoveMsg', kind: 5, floats: [dist, a.p5, heading, a.p6, a.p8] });
        return;
      }
      case 5: {
        const handle = actorFor(a.id); if (handle == null) return;
        if (a.mode === 1) h.setAction?.({ handle, action: Math.min(a.action, 0x37), dirRad: a.dirRad, duration: a.duration });
        else if (a.mode === 0) h.stopAction?.({ handle });
        return;
      }
      case 6: {
        const text = { category: a.category, index: a.textIndex };
        if (a.mode === 0) h.talk?.({ handle: actorFor(a.target), target: a.target, text, p3: a.p3, p4: a.p4 });
        else if (a.mode === 1) h.dialog?.({ text, p3: a.p3, p4: a.p4, p5: a.p5, p6: a.p6, p7: a.p7 });
        return;
      }
      case 7: {
        // SetCamera Execute (FUN_7ff6716352c0).
        if (a.mode === 1) h.camera?.({ ...a, op: 'set', override: true, cameraFlag: a.flag28, saved: st.cameraSaved });
        else if (a.mode === 2) h.camera?.({ ...a, op: 'drift', targetDelta: a.target, targetMs: a.driftA, paramsDelta: a.params, paramsMs: a.driftB });
        else h.camera?.({ ...a, op: 'restore', override: false, cameraFlag: true, params: st.cameraSaved ? st.cameraSaved.slice() : null });
        return;
      }
      case 9: st.leave = true; return;
      case 10: {
        // FadeInOut Execute (FUN_7ff6716359b0): FadeHide first, then mode 1 fade-in (from black) / mode 0 fade-out (to black).
        h.fadeHide?.({ owner: MAP_EVENT_FADE.owner });
        if (a.mode === 0 || a.mode === 1) h.fade?.({ mode: a.mode, duration: a.duration, direction: a.mode === 1 ? 'in' : 'out',
          fromAlpha: a.mode === 1 ? 255 : 0, toAlpha: a.mode === 1 ? 0 : 255, hideWhenDone: a.mode === 1,
          owner: MAP_EVENT_FADE.owner, windowId: MAP_EVENT_FADE.windowId });
        return;
      }
      case 11: if (a.mode === 1) h.showAllUI?.(true); else if (a.mode === 0) h.showAllUI?.(false); return;
      case 12: {
        const handle = actorFor(a.brick); if (handle == null) return;
        if (a.p1 === 1) h.brickAction?.({ handle, brick: a.brick, code: 0x18 });
        else if (a.p1 === 0) h.brickAction?.({ handle, brick: a.brick, code: 0x19 });
        return;
      }
      default:
    }
  }

  function tick() {
    if (!st.playing) return 0;
    const t = n(now());
    let fired = 0;
    const keep = [];
    for (const a of st.actions) {
      if (a.fireAt <= t) { exec(a); st.executed.push(a); fired++; } else keep.push(a);
    }
    st.actions = keep;
    if (st.leave) { st.leave = false; end(); }
    return fired;
  }

  function skip() {
    if (!st.playing) return false;
    h.sendSkip?.(encodeMapEventSkip());
    return true;
  }

  /** Global 0x05260023 (FUN_7ff6714e3ed0): only when actions are pending, set the end flag; End runs on the next tick. */
  function serverStop() {
    if (!st.playing || !st.actions.length) return false;
    st.leave = true;
    return true;
  }

  function onPacket(opcode, bytes) {
    if (opcode === MAP_EVENT_OPCODES.STOP) return serverStop();
    if (opcode !== MAP_EVENT_OPCODES.START) return false;
    const idx = decodeMapEventStart(bytes);
    return idx == null ? false : start(idx);
  }

  return {
    start, tick, end, skip, onPacket, serverStop,
    get playing() { return st.playing; }, get index() { return st.index; },
    get pending() { return st.actions.length; }, get noPresentation() { return st.noPresentation; },
    get actors() { return new Map(st.actors); }, get executed() { return st.executed.slice(); },
    indices: () => [...byIndex.keys()],
  };
}
