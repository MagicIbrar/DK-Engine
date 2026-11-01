// Server-badge particle layer (server-select screen). Around and over the breathing logo (additive, so it only brightens): rising embers, small sparks and
// a few glow motes, drawn additively on one small 2D canvas.
//
// Emitters are taken from Global's own login-scene effects (property/effect/effectdata.map.txt, effectscene.map.txt):
//   embers  = pt_log_fire_01  (scene 20138 unit 1, placed by map/login.mel): tex effect\back\log_fire_01.dds, add,
//             lifetime 1400-1800 ms, maxelementcount 25, velocity 0.5-0.8, gravity 0 1 0, startrange 0.15-0.3,
//             particlesize 1.5-2.3; scene curves alpha (0,.2)(150,.5)(600,.7)(999,0), scale (0,.5)(600,1)(999,.4).
//   sparks  = pt_log_fire_02  (scene 20138 unit 2): same texture, add, lifetime 700-900, max 10, velocity 0.4-0.6,
//             gravity 0 0.6 0, startrange 0.18-0.28, particlesize 1.5-2.5; alpha (0,.5)(150,.5)(700,.7)(999,0),
//             scale (0,.5)(600,1.3)(999,.4).
//   motes   = pt_pi_star_02   (scene 20177, map/new_login_night.mel): tex effect\back\pi_star_01.dds, add,
//             particlesize 0.2-0.3, velocity 0; alpha (0,1)(250,.5)(500,1)(750,.5)(999,0).
// Engine choices (not in Global data): world->px scale, emitter strip across the slot's lower edge, layer drawn over the logo, mote lifetime = the 3.2 s
// logo-breathe cycle (Global's is 100-200 s), mote brightness coupled to that pulse, small sideways drift, warm
// tint on the (bluish) star texture, ALPHA_GAIN on texture alpha, larger on-screen sprite size, and spawning at the max count instead of the raw emitrate.
export const PX_PER_UNIT = 12;
export const PULSE_MS = 3200;
/** Engine choice: texture alpha gain so the faint (max alpha 119/255) fire sprite reads at 122 px badge size. */
export const ALPHA_GAIN = 2.2;
export const EMITTERS = {
  ember: { tex: 'texture/effect/back/log_fire_01.dds', life: [1400, 1800], max: 25, vel: [0.5, 0.8], grav: 1.0, start: [0.15, 0.3], size: [1.5, 2.3],
    alpha: [[0, .2], [150, .5], [600, .7], [999, 0]], scale: [[0, .5], [600, 1], [999, .4]] },
  spark: { tex: 'texture/effect/back/log_fire_01.dds', life: [700, 900], max: 10, vel: [0.4, 0.6], grav: 0.6, start: [0.18, 0.28], size: [1.5, 2.5],
    alpha: [[0, .5], [150, .5], [700, .7], [999, 0]], scale: [[0, .5], [600, 1.3], [999, .4]] },
  mote: { tex: 'texture/effect/back/pi_star_01.dds', life: [PULSE_MS, PULSE_MS], max: 8, vel: [0, 0], grav: 0, start: [0, 3.5], size: [0.2, 0.3] ,
    alpha: [[0, 1], [250, .5], [500, 1], [750, .5], [999, 0]], scale: [[0, 1], [999, 1]] },
};
export const MAX_PARTICLES = Object.values(EMITTERS).reduce((s, e) => s + e.max, 0);

/** Piecewise-linear Dekaron keyframe curve; t in 0..999. */
export function curve(keys, t) {
  if (t <= keys[0][0]) return keys[0][1];
  for (let i = 1; i < keys.length; i++) if (t <= keys[i][0]) { const [a, va] = keys[i - 1], [b, vb] = keys[i]; return va + (vb - va) * (t - a) / (b - a); }
  return keys[keys.length - 1][1];
}
const rnd = (r, [a, b]) => a + (b - a) * r();

/** Pure simulation (no DOM): w,h = layer px; origin = emitter centre px. */
export function createSim({ w, h, rand = Math.random }) {
  const ps = [];
  const ox = w / 2, oy = h * 0.78;
  const spawn = (kind, now) => {
    const e = EMITTERS[kind]; const life = rnd(rand, e.life);
    const ang = rand() * Math.PI * 2, rad = rnd(rand, e.start) * PX_PER_UNIT * (kind === 'mote' ? 1 : 4);
    const p = { kind, born: now - (kind === 'mote' ? 0 : rand() * life), life, size: rnd(rand, e.size) * PX_PER_UNIT * (kind === 'mote' ? 1.4 : 0.9),
      x: kind === 'mote' ? w / 2 + Math.cos(ang) * rad * 9 : ox + (rand() - .5) * w * 0.9 + Math.cos(ang) * rad,
      y: kind === 'mote' ? h * 0.5 + Math.sin(ang) * rad * 7 : oy + Math.sin(ang) * rad * 0.3,
      vy: -rnd(rand, e.vel) * PX_PER_UNIT / 1000, ay: -e.grav * PX_PER_UNIT / 1e6 * 18, vx: (rand() - .5) * 0.006 };
    ps.push(p);
  };
  return {
    ps,
    step(now, dt) {
      for (let i = ps.length - 1; i >= 0; i--) {
        const p = ps[i];
        if (now - p.born >= p.life) { ps.splice(i, 1); continue; }
        p.vy += p.ay * dt; p.x += p.vx * dt; p.y += p.vy * dt;
      }
      for (const k in EMITTERS) { let n = 0; for (const p of ps) if (p.kind === k) n++; while (n++ < EMITTERS[k].max && ps.length < MAX_PARTICLES) spawn(k, now); }
    },
    /** Draw params per particle: {kind,x,y,size,alpha}. */
    view(now) {
      const pulse = 0.5 - 0.5 * Math.cos((now % PULSE_MS) / PULSE_MS * Math.PI * 2);
      return ps.map(p => { const e = EMITTERS[p.kind]; const t = Math.min(999, (now - p.born) / p.life * 999);
        let alpha = curve(e.alpha, t); if (p.kind === 'mote') alpha *= 0.25 + 0.75 * pulse;
        return { kind: p.kind, x: p.x, y: p.y, size: p.size * curve(e.scale, t), alpha }; });
    },
  };
}

function toCanvas(img, tint, gain = ALPHA_GAIN) {
  const c = document.createElement('canvas'); c.width = img.width; c.height = img.height;
  const g = c.getContext('2d'); const id = g.createImageData(img.width, img.height); id.data.set(img.data);
  if (tint) for (let i = 0; i < id.data.length; i += 4) { const l = Math.max(id.data[i], id.data[i + 1], id.data[i + 2]); id.data[i] = l; id.data[i + 1] = l * .78; id.data[i + 2] = l * .45; }
  for (let i = 3; i < id.data.length; i += 4) id.data[i] = Math.min(255, id.data[i] * gain);
  g.putImageData(id, 0, 0); return c;
}

/** Mount on a .fe-server-badge. Runs only while badge[data-animate="true"]; nothing under reduced motion. */
export function mountLogoParticles(badge, { loadRGBA, reducedMotion = matchMedia('(prefers-reduced-motion: reduce)').matches } = {}) {
  if (reducedMotion || !loadRGBA) return () => {};
  const canvas = document.createElement('canvas'); canvas.className = 'fe-server-particles'; canvas.setAttribute('aria-hidden', 'true');
  badge.appendChild(canvas);
  let sim = null, tex = null, raf = 0, last = 0, dead = false;
  Promise.all([loadRGBA([EMITTERS.ember.tex]), loadRGBA([EMITTERS.mote.tex])]).then(([fire, star]) => {
    if (dead || !fire || !star) return;       // no Global texture -> no particles (nothing invented)
    tex = { ember: toCanvas(fire), spark: tex?.spark, mote: toCanvas(star, true) }; tex.spark = tex.ember; sync();
  });
  const frame = now => {
    raf = 0; if (dead || badge.dataset.animate !== 'true' || !tex) return;
    const w = badge.clientWidth | 0, h = badge.clientHeight | 0;
    if (canvas.width !== w || canvas.height !== h) { canvas.width = w; canvas.height = h; sim = null; }
    if (!sim) sim = createSim({ w, h });
    sim.step(now, Math.min(50, last ? now - last : 16)); last = now;
    const g = canvas.getContext('2d'); g.clearRect(0, 0, w, h); g.globalCompositeOperation = 'lighter';
    for (const p of sim.view(now)) { if (p.alpha <= 0) continue; g.globalAlpha = Math.min(1, p.alpha); const s = p.size; g.drawImage(tex[p.kind], p.x - s / 2, p.y - s / 2, s, s); }
    raf = requestAnimationFrame(frame);
  };
  const sync = () => { if (!raf && badge.dataset.animate === 'true' && tex) { last = 0; raf = requestAnimationFrame(frame); } };
  const mo = new MutationObserver(sync); mo.observe(badge, { attributes: true, attributeFilter: ['data-animate'] });
  return () => { dead = true; mo.disconnect(); if (raf) cancelAnimationFrame(raf); canvas.remove(); };
}
