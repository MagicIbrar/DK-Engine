// Remotes (share/creature/remote.csv via skills.json remotes; docs/formats/skills.md §7): projectiles and ground
// areas launched by skill results 3000xxx. The impact is the remote's ResultType with the step's Arg2..Arg8
// (hoisted onto the step result by the builder: radius, addDamage, statusIndex, chance, durations, element ...).
//
// Launch (last digits of the result code):
//   1 straight   flies from the caster to the target at moveSpeed (homing), max maxDistance; hits the first unit
//                within `size`; maxPiercing > 0 lets it continue through up to that many more units (each with
//                piercingRate %) along the same line
//   5 target     a ground area at the target position: pulses every hitCycleMs (one strike + maxPiercing
//                repeats); each pulse applies the impact around the point
//   6 area       a fixed area at the validated target / point; pure self skills use the caster's cast position.
//                The target mask, rather than the launch digit, determines its origin.
//   7 multi      as 5 (several units around the target point are hit by each pulse)
//   8 delayed    as 5, the first pulse after one hitCycleMs
// AREA STAYS: ground areas keep their launch centre, except Mage Emitted Flash (548 / remote 553).
// Its native self-target description places the five continuing strikes around the caster.
// Other areas (including Segnale Curse Field) keep their launch centre.
// The launch digit alone does not imply following: remote.csv has no general follow column.
// The exception uses the exact native self skill and remote, rather than every launch-5 area.
// Visuals: `effect` on the flying anchor / area point (area lifetime = effect.timeMs), `contactEffect` on each unit
// hit, `piercingEffect` on pierced units, `warningEffect` on the ground before the first pulse.
const DEFAULT_SPEED = 25;

export class RemoteSystem {
  constructor(engine) {
    this.engine = engine;
    this.game = engine.game;
    this.list = [];
  }

  /**
   * Launch a remote. ctx = cast context {caster, skill, level, target, point}; res = step result (projectile family).
   */
  launch(ctx, res) {
    const e = this.engine;
    const rm = e.data.remote(res.remoteIndex);
    if (!rm) {
      // no remote row: apply the impact directly on the target
      e.applyImpact(ctx, { ...res, family: res.impact?.family || 'damage', kind: res.impact?.kind || 'damage', shape: res.impact?.shape }, ctx.target || ctx.caster, ctx.point);
      return;
    }
    const launch = Number(res.launch) || Number(String(res.resultCode).slice(-1)) || 1;
    const caster = ctx.caster;
    const target = ctx.target && ctx.target !== caster ? ctx.target : null;
    const impact = { ...(rm.impact || {}), ...pickHoisted(res) };
    if (!impact.family) impact.family = 'damage';
    const speed = Number(rm.moveSpeed) > 0 ? Number(rm.moveSpeed) : 0;
    const cyc = Math.max(0, Number(rm.hitCycleMs) || 0) / 1000;
    const life = Math.max(0, Number(rm.lifetimeMs ?? rm.effect?.timeMs) || 0) / 1000;
    const r = {
      ctx, res, rm, impact, launch, t: 0, done: false, fx: null, hits: new Set(),
      pierce: Math.max(0, Number(rm.maxPiercing) || 0), pierceRate: Number(rm.piercingRate) || 0,
      speed: speed || DEFAULT_SPEED, maxDist: Math.max(1, Number(rm.maxDistance) || 14), size: Math.max(0.5, Number(rm.size) || 1),
      target,
    };
    const from = { x: caster.x, y: (caster.y || 0) + (caster.height || 1.8) * (caster.scale || 1) * 0.6, z: caster.z };
    if (launch === 1 && (target || ctx.point)) {
      r.mode = 'fly';
      r.pos = { ...from };
      const to = target ? { x: target.x, z: target.z } : ctx.point;
      const dx = to.x - from.x, dz = to.z - from.z, d = Math.hypot(dx, dz) || 1;
      r.dir = { x: dx / d, z: dz / d };
      r.travel = 0;
      r.anchor = { x: r.pos.x, y: r.pos.y, z: r.pos.z, yaw: Math.atan2(-r.dir.x, -r.dir.z), height: 0, scale: 1, remote: true };
      if (rm.effect) r.fx = e.fx?.play(r.anchor, rm.effect, { loop: true, followPoint: true });
    } else {
      r.mode = 'area';
      const center = target || ctx.point || caster;
      r.followCaster = Number(ctx.skill?.index) === 548 && Number(ctx.skill?.class) === 2 &&
        Number(res.remoteIndex) === 553 && launch === 5 && Number(ctx.skill?.targetMask) === 16 && !target;
      r.center = { x: center.x, z: center.z };
      const d = Math.hypot(r.center.x - caster.x, r.center.z - caster.z);
      const delay = launch === 8 ? cyc : (speed > 0 && launch !== 6 ? Math.min(1.5, d / speed) : 0);
      r.nextPulse = delay;
      // Native MaxPiercing counts repeats after the first strike, not enemies:
      // remote 63 = 2 -> Lightning Circle's description says three strikes;
      // 43 = 3 -> Winder Firing four, 115 = 5 -> Hell Bust six. Lifetime is the
      // remote's expiry/visual bound, not a request to add extra damage pulses.
      r.pulses = cyc > 0 ? r.pierce + 1 : 1;
      r.cycle = cyc;
      r.life = Math.max(life, delay + (r.pulses - 1) * cyc + 0.05);
      r.anchor = { x: r.center.x, z: r.center.z, y: undefined, yaw: caster.yaw || 0, height: 0, scale: 1, remote: true };
      const w = this.game.world;
      r.anchor.y = w?.heightAt ? w.heightAt(r.anchor.x, r.anchor.z) : caster.y || 0;
      if (rm.warningEffect && delay > 0.05) e.fx?.play(r.anchor, rm.warningEffect, { loop: false });
      if (rm.effect) r.fx = e.fx?.play(r.anchor, { ...rm.effect, timeMs: Math.max(Number(rm.effect.timeMs) || 1000, r.life * 1000) }, { loop: false, followPoint: r.followCaster });
    }
    this.list.push(r);
  }

  update(dt) {
    if (!this.list.length) return;
    const keep = [];
    for (const r of this.list) {
      try { this._step(r, dt); } catch (err) { console.warn('[skills] remote failed', r.rm?.index, err); r.done = true; }
      if (!r.done) keep.push(r); else r.fx?.stop(false);
    }
    this.list = keep;
  }

  _step(r, dt) {
    const e = this.engine;
    r.t += dt;
    if (r.mode === 'fly') {
      const tgt = r.target && !r.target.disposed && !r.target.dead ? r.target : null;
      if (tgt && !r.hits.has(tgt)) {
        // homing towards the first target
        const dx = tgt.x - r.pos.x, dz = tgt.z - r.pos.z, d = Math.hypot(dx, dz) || 1;
        r.dir = { x: dx / d, z: dz / d };
      }
      const step = r.speed * dt;
      r.pos.x += r.dir.x * step; r.pos.z += r.dir.z * step;
      r.travel += step;
      const ty = tgt ? (tgt.y || 0) + (tgt.height || 1.5) * (tgt.scale || 1) * 0.55 : r.pos.y;
      r.pos.y += (ty - r.pos.y) * Math.min(1, dt * 6);
      Object.assign(r.anchor, { x: r.pos.x, y: r.pos.y, z: r.pos.z, yaw: Math.atan2(-r.dir.x, -r.dir.z) });
      // contact
      const hitList = e.unitsNear(r.pos, r.size, r.ctx.caster, 'enemy').filter(u => !r.hits.has(u));
      if (tgt && !r.hits.has(tgt) && Math.hypot(tgt.x - r.pos.x, tgt.z - r.pos.z) <= r.size + (tgt.radius || 0.5) && !hitList.includes(tgt)) hitList.unshift(tgt);
      for (const u of hitList) {
        const first = r.hits.size === 0;
        if (!first) {
          if (r.pierce <= 0 || r.hits.size > r.pierce) break;
          if (r.pierceRate > 0 && r.pierceRate < 100 && Math.random() * 100 >= r.pierceRate) continue;
        }
        r.hits.add(u);
        if (r.rm.contactEffect) e.fx?.play(u, r.rm.contactEffect, {});
        else if (!first && r.rm.piercingEffect) e.fx?.play(u, r.rm.piercingEffect, {});
        e.applyImpact(r.ctx, r.impact, u, { x: u.x, z: u.z });
        if (r.pierce <= 0) { r.done = true; return; }
      }
      if (r.hits.size > r.pierce && r.hits.size > 0) { r.done = true; return; }
      if (r.travel >= r.maxDist + 2) {
        // reached the end without hitting its target (it moved away): an area impact still lands at the end point
        if (!r.hits.size && r.impact.radius > 0) e.applyImpact(r.ctx, r.impact, null, { x: r.pos.x, z: r.pos.z });
        r.done = true;
      }
      return;
    }
    // The exact self-owned Mage pulse uses current host/local caster geometry.
    // DestroyWhenDie remains native: a remote without that flag keeps its authored lifetime.
    if (r.followCaster && !r.ctx.caster.disposed) {
      const caster = r.ctx.caster;
      r.center.x = caster.x; r.center.z = caster.z;
      Object.assign(r.anchor, r.center, { y: this.game.world?.heightAt?.(caster.x, caster.z) ?? caster.y ?? 0 });
    }
    while (r.pulses > 0 && r.t >= r.nextPulse) {
      r.pulses--;
      r.nextPulse += r.cycle > 0 ? r.cycle : 1e9;
      // self-target skills (Protection sanctuary, Shield field ...) pulse around extra.center instead of the caster's current spot
      e.applyImpact(r.ctx, r.impact, null, { x: r.center.x, z: r.center.z }, { contactEffect: r.rm.contactEffect, center: r.center });
    }
    if (r.pulses <= 0 && r.t >= r.life) r.done = true;
    if (r.t > r.life + 0.1) r.done = true;
  }

  clear() {
    for (const r of this.list) r.fx?.stop(true);
    this.list = [];
  }
}

const HOIST = ['radius', 'addDamage', 'statusIndex', 'chance', 'statusDurationMs', 'durationMs', 'damageClass', 'element',
  'elementPct', 'damagePct', 'target', 'hitEffect', 'aggro', 'statusIndex2', 'chance2', 'dotStatusIndex', 'amount', 'perSpr'];
function pickHoisted(res) {
  const o = {};
  for (const k of HOIST) if (res[k] !== undefined) o[k] = res[k];
  return o;
}

