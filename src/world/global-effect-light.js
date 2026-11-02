// Global effect light (LANE-54 passes 3-4). Reimplemented from the read-only 43.19 client (not copied):
//  * Light effect unit (64-bit vf11 FUN_7ff671290420 / vf6 FUN_7ff671290520) posts IMessage LightStart (type id 0x60040010,
//    vtable 0x7ff671e5c650) once when the scene time reaches the control start, with duration = end - start, and
//    LightStop (0x60040011) when the time reaches the end, only if end < 1000000; start/end = control `lifetime A B` x the
//    scene time scale (Unit::Light::vf11: unit+0x64 = control+0xc x scale, unit+0xa8 = control+0x10 x scale).
//  * Receiver Ghost::DollStage::Environment::Element::Light (FUN_7ff671242d10). LightStart FUN_7ff6712434d0 keeps 0x80-byte
//    records (list at +0xd8): a record with the same id is refreshed (position, remaining = total = duration, fade-out
//    remaining = fadetime, distance, not stopping), else one is appended. LightStop sets `stopping` on that id.
//  * Tick FUN_7ff671243b40(dt): distance to the viewer is recomputed; not stopping: remaining -= dt (unsigned) and once
//    remaining < fadetime the record is stopping; stopping: fadeLeft -= dt while dt <= fadeLeft and dist < range, else the
//    record is removed. The list is then sorted nearest first (comparator 7ff671242b60).
//    VIEWER (pass 4): _DAT_7ff6726f5300 = DollStage::Camera::CameraImpl; vf+0x30 returns camera+0x38 and the record reads
//    +0x38..0x40 of that = camera+0x70, which CameraImpl::vf02 passes to LookAt as the look-at point (eye = +0x64, up = +0x7c).
//    So distance is measured from the camera look-at target (4.2.0: game.cam.target, the `focus` of Environment.update).
//  * Apply FUN_7ff6712436b0: the FIRST (nearest) record with dist < range and weight > 0 overrides the environment
//    (Sketch::Unit::CEnvironment, handed to the renderer by CEnvironment::vf03 FUN_7ff67129b5d0):
//      time = stopping ? fadeLeft / fadetime : (elapsed < fadetime ? elapsed / fadetime : 1), elapsed = total - remaining
//      dist = dist <= range - faderange ? 1 : (range - dist) / faderange,  w = min(time, dist),  v = base + (target - base) * w
//    Payload -> environment field (pass 4, parser constants 1/255 and 0.1):
//      light  t1 t2 r g b   (light_enable)  t1 -> ambient intensity env+0x54, t2 -> shade distance env+0x64 (base =
//                                           lightdistance), r g b / 255 -> ambient colour env+0x48; shade centre env+0x58 =
//                                           the light position (not lerped) while the light is active
//      dirlight t1 r g b    (light_enable)  t1 -> directional intensity env+0x44, r g b / 255 -> directional colour env+0x2c
//      fog s e t3 r g b     (fog_enable)    s -> fog start env+0x68, e -> fog end env+0x6c, t3 -> env+0x70, r g b / 255 -> colour
//      bloom a b            (bloom_enable)  env+0x84 = a > 0, env+0x88 = lerp(base, a * 0.1), env+0x8c = lerp(base, b * 0.1)
//    WIRED in 4.2.0 (environment.js, pass 5): ambient colour x ambient intensity, directional colour x directional
//    intensity, shade distance + shade centre (shade.js), fog start / end / colour; graphics/index.js: bloom. No THREE lights.
// PASS 5 (every formerly open item, with its source):
//  * ambient / directional intensity (env+0x54 / +0x44) = colour multiplier, base 1.0 [DECOMPILE + GLOBAL .fx]:
//    CEnvironment::vf03 FUN_7ff67129b5d0 hands {rgb, w} pairs to renderer slots +0x40 (ambient) / +0x50 (directional); the
//    LightImpl defaults are 1.0 (FUN_7ff6709123a0 / FUN_7ff6709125f0 with _DAT_7ff671e84f48 = 1.0, the HighRenderer
//    screen-quad texcoord constant of FUN_7ff6716bc6b0) and the map light Provider FUN_7ff670915230 never sets them; the
//    Global shaders (binary/boneanimation.fx, geometry.fx) light with g_f3ambient + max(0, N.L) x g_f3ColorWithIntensity.
//    Global lt_ data agrees: light t1 0.5..2, dirlight t1 2..4 (effectdata, 28 light units) - an intensity scale.
//  * bloom (env+0x84..0x8c) [DECOMPILE]: enable = a > 0, pow = lerp(map pow, a x 0.1, w), weight = lerp(map weight,
//    b x 0.1, w): CEnvironment vf+0x80 -> FUN_7ff67169d080 -> HighRenderer FUN_7ff6716bc8d0 (SetFloat g_fPowValue handle
//    0x3c8 <- f1, g_fWeightValue 0x3e0 <- f2). Applied by graphics/index.js (effectBloomOverride).
//  * fog t3 (env+0x70) and env+0x74: REMOVED. 32-bit CRenderCore fog setter FUN_0151b680 reads only fog start / end and
//    the colour, and every Global .fx takes fog as g_f2FogValue (2 floats); no consumer exists, so the value is dropped.
//  * MEL period -> scene time: time = period ms [DECOMPILE + GLOBAL data]: Unit::Light vf06 LightStop sentinel 1000000 and
//    443 of 524 Global .mel cate-9 periods = 1000000 (lifetime 0 1000 x 1000000 / 1000 = never stopped).
const U32 = v => (Number(v) >>> 0);
const C255 = 1 / 255;
const NEVER_STOP_MS = 1000000;   // Unit::Light vf06: LightStop only when end < 1000000

function dist3(a, b) {
  const dx = (a?.[0] ?? 0) - (b?.[0] ?? 0), dy = (a?.[1] ?? 0) - (b?.[1] ?? 0), dz = (a?.[2] ?? 0) - (b?.[2] ?? 0);
  return Math.sqrt(dx * dx + dy * dy + dz * dz);
}
const vecOf = v => (v && typeof v.x === 'number' ? [v.x, v.y, v.z] : Array.isArray(v) ? v : null);
const num = (v, d = 0) => (Number.isFinite(Number(v)) ? Number(v) : d);

/** FUN_7ff6712436b0 weight of one record (0 when out of range). */
export function effectLightWeight(r) {
  if (!r || !(r.dist < r.range)) return 0;
  let time;
  if (r.stopping) time = r.fadeLeft / r.fadeMs;
  else {
    const elapsed = r.timed ? U32(r.total - r.remaining) : r.elapsedUntimed;
    time = elapsed < r.fadeMs ? elapsed / r.fadeMs : 1;
  }
  const d = r.dist <= r.range - r.fadeRange ? 1 : (r.range - r.dist) / r.fadeRange;
  const w = Math.min(time, d);
  return Number.isFinite(w) ? w : (w === Infinity ? 1 : 0);
}

/** base + (target - base) * w per component (numbers or arrays). */
export function lerpEnv(base, target, w) {
  if (Array.isArray(base) && Array.isArray(target)) return base.map((b, i) => b + ((target[i] ?? b) - b) * w);
  if (typeof base === 'number' && typeof target === 'number') return base + (target - base) * w;
  return base;
}

/** Payload blocks -> environment targets (FUN_7ff6712436b0 field mapping, colours / 255). Missing blocks give null. */
export function effectLightTargets(p) {
  if (!p) return null;
  const L = Array.isArray(p.light) ? p.light : null, D = Array.isArray(p.dirlight) ? p.dirlight : null;
  const F = Array.isArray(p.fog) ? p.fog : null, B = Array.isArray(p.bloom) ? p.bloom : null;
  return {
    lightEnable: p.lightEnable !== false && (!!L || !!D), fogEnable: !!p.fogEnable && !!F, bloomEnable: !!p.bloomEnable && !!B,
    ambientIntensity: L ? num(L[0]) : null,
    shadeDistance: L ? num(L[1]) : null,
    ambient: L ? [num(L[2]) * C255, num(L[3]) * C255, num(L[4]) * C255] : null,
    dirIntensity: D ? num(D[0]) : null,
    sunColor: D ? [num(D[1]) * C255, num(D[2]) * C255, num(D[3]) * C255] : null,
    // fog t3 (F[2]) has no consumer (FUN_0151b680 / g_f2FogValue): not carried
    fog: F ? { start: num(F[0]), end: num(F[1]), color: [num(F[3]) * C255, num(F[4]) * C255, num(F[5]) * C255] } : null,
    bloom: B ? { enable: num(B[0]) > 0, a: num(B[0]) * 0.1, b: num(B[1]) * 0.1 } : null,
  };
}

/**
 * Environment sample (formats/environment.js sampleEnvironment shape: ambient, sunColor, lightDistance, fog{start,end,color})
 * blended toward the target. Returns a new object; `shadePos` is set to the light position while the light block applies.
 * ambientIntensity / dirIntensity (base 1.0) are applied as colour multipliers by environment.js; effectBloom by
 * graphics/index.js (effectBloomOverride).
 */
export function applyEffectLightToEnv(base, record, weight) {
  const out = { ...base, effectLight: null };
  const t = record ? effectLightTargets(record.payload) : null;
  if (!t || !(weight > 0)) return out;
  out.effectLight = { id: record.id, weight };
  if (t.lightEnable) {
    if (t.ambient && Array.isArray(base.ambient)) out.ambient = lerpEnv(base.ambient, t.ambient, weight);
    if (t.shadeDistance != null && Number.isFinite(base.lightDistance)) out.lightDistance = lerpEnv(base.lightDistance, t.shadeDistance, weight);
    if (t.ambient) out.shadePos = [...record.pos];
    if (t.sunColor && Array.isArray(base.sunColor)) out.sunColor = lerpEnv(base.sunColor, t.sunColor, weight);
    out.ambientIntensity = lerpEnv(num(base.ambientIntensity, 1), t.ambientIntensity ?? 1, weight);   // env+0x54, base 1.0
    out.dirIntensity = lerpEnv(num(base.dirIntensity, 1), t.dirIntensity ?? 1, weight);               // env+0x44, base 1.0
  }
  if (t.fogEnable && base.fog) {
    // From the current map key (LANE-66 fogKey) when present. FUN_7ff6712436b0 writes the weighted fog straight into the
    // CEnvironment fog fields, so the result is sent as-is (fogKey + fogDirect) rather than re-stepped by stepGlobalFog.
    const f0 = base.fogKey || base.fog;
    out.fog = { ...f0, start: lerpEnv(f0.start, t.fog.start, weight), end: lerpEnv(f0.end, t.fog.end, weight),
      color: Array.isArray(f0.color) ? lerpEnv(f0.color, t.fog.color, weight) : f0.color };
    if (base.fogKey) { out.fogKey = out.fog; out.fogDirect = true; }
  }
  if (t.bloomEnable) out.effectBloom = { enable: t.bloom.enable, a: t.bloom.a, b: t.bloom.b, weight };   // graphics/index.js
  return out;
}

/** Ambient / directional intensity of an environment sample (base 1.0: LightImpl ctor, map Provider never sets it). */
export function envIntensities(e) {
  return { ambient: num(e?.ambientIntensity, 1), dir: num(e?.dirIntensity, 1) };
}

/**
 * Bloom parameters under an active effect light (FUN_7ff6712436b0 bloom block -> CEnvironment+0x84..0x8c -> HighRenderer
 * FUN_7ff6716bc8d0): enable = a > 0; pow / weight = lerp(map value, a x 0.1 / b x 0.1, weight). mapBloom = bloomFromEnvironment().
 */
export function effectBloomOverride(mapBloom, effectBloom) {
  if (!mapBloom || !effectBloom || !(effectBloom.weight > 0)) return mapBloom;
  const w = effectBloom.weight;
  return { ...mapBloom, enabled: !!effectBloom.enable, pow: lerpEnv(mapBloom.pow, effectBloom.a, w), weight: lerpEnv(mapBloom.weight, effectBloom.b, w) };
}

export class GlobalEffectLights {
  constructor() { this.records = []; this._seq = 0; }

  /** Unique id for a light unit instance (Global keys records by the sender). */
  nextId() { return `fxl${++this._seq}`; }

  /** LightStart. msg: { id, durationMs (null = untimed), fadeMs, range, fadeRange, pos: [x, y, z], payload }. */
  start(msg, viewerPos) {
    const v = vecOf(viewerPos), pos = vecOf(msg.pos) || [0, 0, 0];
    const dist = dist3(v, pos);
    const timed = msg.durationMs != null;
    const dur = timed ? U32(msg.durationMs) : 0;
    const old = this.records.find(r => r.id === msg.id);
    if (old) {
      Object.assign(old, { pos: [...pos], remaining: dur, total: dur, timed, elapsedUntimed: 0, fadeLeft: U32(msg.fadeMs), dist, stopping: false });
      return old;
    }
    const r = { stopping: false, id: msg.id, fadeMs: U32(msg.fadeMs), remaining: dur, fadeLeft: U32(msg.fadeMs), total: dur, timed, elapsedUntimed: 0,
      dist, range: Number(msg.range) || 0, fadeRange: Number(msg.fadeRange) || 0, pos: [...pos], payload: msg.payload || null };
    this.records.push(r);
    return r;
  }

  /** LightStop: begin the fade-out of the record with that id. */
  stop(id) { const r = this.records.find(x => x.id === id); if (r) r.stopping = true; }

  /** Drop every record (map unload). */
  clear() { this.records = []; }

  /** FUN_7ff671243b40: advance by dt ms, drop finished records, sort nearest first. */
  tick(dtMs, viewerPos) {
    const dt = U32(dtMs), v = vecOf(viewerPos);
    const keep = [];
    for (const r of this.records) {
      r.dist = dist3(v, r.pos);
      if (!r.stopping && r.timed) {
        r.remaining = U32(r.remaining - dt);
        if (r.remaining < r.fadeMs) r.stopping = true;
      } else if (!r.stopping) r.elapsedUntimed += dt;   // untimed (no lifetime known): fade-in still runs on elapsed time
      if (r.stopping) {
        if (dt <= r.fadeLeft && r.dist < r.range) r.fadeLeft = U32(r.fadeLeft - dt);
        else continue;
      }
      keep.push(r);
    }
    keep.sort((a, b) => a.dist - b.dist);
    this.records = keep;
  }

  /** FUN_7ff6712436b0 selection: { record, weight } of the nearest active light, or null. */
  active() {
    for (const r of this.records) {
      const w = effectLightWeight(r);
      if (w > 0) return { record: r, weight: w };
    }
    return null;
  }

  /** Environment sample blended toward the active light (applyEffectLightToEnv); base unchanged (copied) when none. */
  blend(base) {
    const a = this.active();
    return a ? applyEffectLightToEnv(base, a.record, a.weight) : { ...base, effectLight: null };
  }
}

/** LightStart message for a light unit: duration = (end - start) ms; payload = the unit's authored blocks. */
export function lightUnitStartMessage(unit, id, pos, durationMs) {
  return {
    id, durationMs: durationMs == null ? null : Math.max(0, Math.round(durationMs)), fadeMs: unit?.fadeMs ?? 0,
    range: unit?.range ?? 0, fadeRange: unit?.fadeRange ?? 0, pos: vecOf(pos) || [0, 0, 0],
    payload: { light: unit?.light ?? null, dirlight: unit?.dirlight ?? null, bloom: unit?.bloom ?? null, fog: unit?.fog ?? null,
      lightEnable: unit?.lightEnable, bloomEnable: unit?.bloomEnable, fogEnable: unit?.fogEnable },
  };
}

/** True when Unit::Light sends LightStop at its end time (end < 1000000 ms). */
export const lightUnitSendsStop = endMs => Number(endMs) < NEVER_STOP_MS;

/**
 * Effect-scene light unit (effects.js ControlPlay, unittype light). Sends LightStart once at spawn (= control start) with
 * duration (end - start) and LightStop when the control ends / is removed (only for end < 1000000 ms). Draws nothing.
 */
export class EffectLightUnit {
  constructor(ctx, unitDef, anchor, startSec, endSec, id = null) {
    this.lights = ctx?.game?.effectLights || null;
    this.object = null;
    this.endMs = endSec * 1000;
    this.id = this.lights ? (id ?? this.lights.nextId()) : null;   // one id per control: a replay refreshes its record
    if (!this.lights) return;
    const p = { x: 0, y: 0, z: 0 };
    if (anchor?.getWorldPosition) { anchor.updateWorldMatrix?.(true, false); const w = anchor.getWorldPosition(new anchor.position.constructor()); p.x = w.x; p.y = w.y; p.z = w.z; }
    const viewer = ctx.game.cam?.target || ctx.game.camera?.position || null;
    this.lights.start(lightUnitStartMessage(unitDef, this.id, [p.x, p.y, p.z], (endSec - startSec) * 1000), viewer);
  }
  apply() { }
  update() { }
  finishing() { return false; }
  stopEmitting() { }
  dispose() { if (this.lights && this.id != null && lightUnitSendsStop(this.endMs)) this.lights.stop(this.id); this.lights = null; }
}

/**
 * Map-placed (.mel cate 9) lights on the same receiver. Each placement replays its scene every `period` ms (the 4.2.0 map
 * scene timing, loop): at life[0] x period / 1000 it sends LightStart (duration = (life[1] - life[0]) x period / 1000, same
 * id every cycle = refresh), at life[1] x period / 1000 LightStop when that is < 1000000.
 */
export class MapEffectLights {
  /** placements: resolveMelLocalLights() rows with { pos: [x, y, z] THREE, period, life }. */
  constructor(placements = []) {
    this.items = placements.filter(p => p && Array.isArray(p.pos) && (p.lightEnable || p.fogEnable || p.bloomEnable)).map((p, i) => {
      const T = Number(p.period) > 0 ? Number(p.period) : NEVER_STOP_MS;
      const life = Array.isArray(p.life) && p.life.length >= 2 ? p.life : [0, 1000];
      const startMs = num(life[0]) * T / 1000, endMs = Math.max(num(life[0]) * T / 1000, num(life[1], 1000) * T / 1000);
      return { p, id: `mel${i}:${p.effectId}`, T, startMs, endMs, t: 0, started: false, stopped: false };
    });
  }

  update(dtMs, lights, viewerPos) {
    if (!lights) return;
    for (const it of this.items) {
      it.t += Math.max(0, Number(dtMs) || 0);
      if (it.t >= it.T) { it.t %= it.T; it.started = false; it.stopped = false; }   // scene loop: the next cycle re-sends
      if (!it.started && it.t >= it.startMs) {
        it.started = true;
        lights.start(lightUnitStartMessage(it.p, it.id, it.p.pos, it.endMs - it.startMs), viewerPos);
      }
      if (it.started && !it.stopped && it.t >= it.endMs && lightUnitSendsStop(it.endMs)) { it.stopped = true; lights.stop(it.id); }
    }
  }
}