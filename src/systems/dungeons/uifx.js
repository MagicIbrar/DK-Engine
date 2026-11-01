// UI effect scenes (<cate> 8 of property/effect/effectscene.*.txt, pre-built into gamedata/dungeons_uifx.json by
// tools/build-dungeon-uifx.mjs): the full-screen flashes the dungeon scripts trigger with "@<effectui>id,1,ms,1"
// (2023 Mission_Start, 2026 cleared, 2019 failed, 2082.. tower flash lines, 2093 perfect clear ...).
//
// The client draws them in its UI camera: sprite units are camera billboards whose size is `size` x the control's
// scale (x = width, z = height; y is depth), 1 unit = 64 reference pixels (the 1024x64 text strips are authored at
// scale 16 x 1), origin at the screen centre, x right / y up. Every control lives from lifetime[0] to lifetime[1] of
// the scene timeline (0..1000 = the duration the caller gives), its keyframes t = 0..999 run over its own life.
// Blend 'add' = additive, 'modulate' = alpha blend. Particles (pt_*) are drawn as additive sprite bursts
// (emitrate < 0 = burst size, maxelementcount cap, lifetime / velocity / gravity / particlesize ranges).
import { fetchJSON } from '../../engine/assets.js';
import { atlas } from '../../ui/atlas.js';

export const UNIT_PX = 64;
const URL = '/gamedata/dungeons_uifx.json';

let table = null;
const loadTable = () => (table ||= fetchJSON(URL).catch(() => ({ effects: {}, units: {} })));

function sample(keys, t, n) {
  if (!keys || !keys.length) return null;
  if (t <= keys[0][0]) return keys[0].slice(1, 1 + n);
  for (let i = 1; i < keys.length; i++) {
    const a = keys[i - 1], b = keys[i];
    if (t <= b[0]) {
      const f = (t - a[0]) / Math.max(1e-6, b[0] - a[0]);
      const out = [];
      for (let k = 1; k <= n; k++) { const va = a[k] ?? a[a.length - 1], vb = b[k] ?? b[b.length - 1]; out.push(va + (vb - va) * f); }
      return out;
    }
  }
  const l = keys[keys.length - 1];
  return l.slice(1, 1 + n);
}

export class UIEffects {
  constructor(game) {
    this.game = game;
    this.active = [];
    this.canvas = null;
    this.ctx = null;
    this._tex = new Map();
  }

  _ensureCanvas() {
    if (this.canvas || typeof document === 'undefined') return;
    const cv = document.createElement('canvas');
    cv.className = 'dg-uifx';
    Object.assign(cv.style, { position: 'fixed', left: '0', top: '0', width: '100vw', height: '100vh', pointerEvents: 'none', zIndex: '15' });
    const root = this.game.ui || document.body;
    const layer = root.querySelector?.('.uw-layer');
    if (layer) root.insertBefore(cv, layer); else root.appendChild(cv);
    this.canvas = cv;
    this.ctx = cv.getContext('2d');
  }

  _texture(key) {
    if (!key) return null;
    if (!this._tex.has(key)) {
      const e = { canvas: null };
      this._tex.set(key, e);
      atlas.texture(key).then(t => { e.canvas = t?.canvas || null; }).catch(() => {});
    }
    return this._tex.get(key).canvas;
  }

  /** Play UI effect `id` (cate 8) for `ms` milliseconds. opts.offset = {x, y} units. */
  async play(id, ms = 3000, opts = {}) {
    const t = await loadTable();
    const eff = t.effects?.[String(id)];
    if (!eff) return false;
    this._ensureCanvas();
    const scene = eff.scenes.find(s => s.id === (opts.scene || 1)) || eff.scenes[0];
    if (!scene) return false;
    const units = {};
    for (const [slot, name] of Object.entries(eff.res || {})) {
      const u = t.units?.[String(name).toLowerCase()];
      if (u) { units[slot] = u; if (u.tex && !u.texMissing) this._texture(u.tex); }
    }
    this.active.push({ id, eff, scene, units, ms: Math.max(100, Number(ms) || 3000), t: 0, parts: new Map(), offset: opts.offset || { x: 0, y: 0 } });
    return true;
  }

  clear() { this.active = []; this._draw(); }

  /** The effect record (name, res, scenes) of a UI effect id, or null. */
  async info(id) { const t = await loadTable(); return t.effects?.[String(id)] || null; }

  update(dt) {
    if (!this.active.length) { if (this._dirty) this._draw(); return; }
    for (const a of this.active) a.t += dt * 1000;
    this.active = this.active.filter(a => a.t < a.ms);
    this._draw(dt);
  }

  _draw(dt = 0) {
    const cv = this.canvas;
    if (!cv) return;
    const dpr = Math.min(2, globalThis.devicePixelRatio || 1);
    const W = Math.round((globalThis.innerWidth || 1024) * dpr), H = Math.round((globalThis.innerHeight || 768) * dpr);
    if (cv.width !== W || cv.height !== H) { cv.width = W; cv.height = H; }
    const ctx = this.ctx;
    ctx.setTransform(1, 0, 0, 1, 0, 0);
    ctx.clearRect(0, 0, W, H);
    this._dirty = this.active.length > 0;
    if (!this.active.length) return;
    const scale = Number(this.game.uiwin?.scale || this.game.settings?.uiScale || 1) || 1;
    const U = UNIT_PX * scale * dpr;
    const cx = W / 2, cy = H / 2;
    for (const a of this.active) {
      const T = (a.t / a.ms) * 1000;
      for (let ci = 0; ci < a.scene.controls.length; ci++) {
        const c = a.scene.controls[ci];
        const [l0, l1] = c.life || [0, 1000];
        if (T < l0 || T > l1) continue;
        const u = a.units[String(c.unit)];
        if (!u) continue;
        const lt = ((T - l0) / Math.max(1e-6, l1 - l0)) * 999;
        const alpha = sample(c.alpha, lt, 1)?.[0] ?? 1;
        if (alpha <= 0.003) continue;
        const sc = sample(c.scale, lt, 3) || [1, 1, 1];
        const pos = sample(c.position, lt, 3) || c.pos || [0, 0, 0];
        const rot = sample(c.rotation, lt, 1)?.[0] || 0;
        const x = cx + ((pos[0] || 0) + a.offset.x) * U, y = cy - ((pos[1] || 0) + a.offset.y) * U;
        const img = this._texture(u.tex);
        if (!img) continue;
        ctx.globalCompositeOperation = u.blend === 'add' ? 'lighter' : 'source-over';
        if (u.type === 'particle') { this._particles(ctx, a, ci, c, u, img, x, y, U, lt, alpha, dt, sc); continue; }
        const size = Number(u.size) || 1;
        const w = size * (sc[0] || 0) * U, h = size * (sc[2] ?? sc[1] ?? sc[0] ?? 0) * U;
        if (w <= 0 || h <= 0) continue;
        ctx.save();
        ctx.globalAlpha = Math.max(0, Math.min(1, alpha));
        ctx.translate(x, y);
        if (rot) ctx.rotate((rot * Math.PI) / 180);
        ctx.drawImage(img, -w / 2, -h / 2, w, h);
        ctx.restore();
      }
    }
    ctx.globalCompositeOperation = 'source-over';
    ctx.globalAlpha = 1;
  }

  _particles(ctx, a, ci, c, u, img, x, y, U, lt, alpha, dt, sc) {
    let ps = a.parts.get(ci);
    if (!ps) {
      ps = [];
      const n = Math.max(1, Math.min(Number(u.max) || 8, Number(u.emitrate) < 0 ? -Number(u.emitrate) : Number(u.max) || 8));
      const [l0, l1] = u.plife || [400, 600];
      const [v0, v1] = u.velocity || [2, 3];
      const [s0, s1] = u.psize || [1, 2];
      const [r0, r1] = u.startrange || [0, 0];
      for (let i = 0; i < n; i++) {
        const ang = Math.random() * Math.PI * 2, sp = v0 + Math.random() * (v1 - v0), r = r0 + Math.random() * (r1 - r0);
        ps.push({ x: Math.cos(ang) * r, y: Math.sin(ang) * r, vx: Math.cos(ang) * sp, vy: Math.sin(ang) * sp, life: (l0 + Math.random() * (l1 - l0)) / 1000, t: 0,
          size: s0 + Math.random() * (s1 - s0), rot: Math.random() * Math.PI * 2 });
      }
      a.parts.set(ci, ps);
    }
    const g = u.gravity || [0, 0, 0];
    const k = Math.max(0.2, (sc[0] || 1) * 0.25);
    for (const p of ps) {
      p.t += dt;
      if (p.t > p.life) continue;
      p.vx += (g[0] || 0) * dt; p.vy += (g[1] || 0) * dt;
      p.x += p.vx * dt; p.y += p.vy * dt;
      const f = 1 - p.t / p.life;
      const s = p.size * (Number(u.size) || 1) * k * U;
      ctx.save();
      ctx.globalAlpha = Math.max(0, Math.min(1, alpha * f));
      ctx.translate(x + p.x * U * 0.25, y - p.y * U * 0.25);
      ctx.rotate(p.rot + (Number(u.addrotate) || 0) * p.t * 0.1);
      ctx.drawImage(img, -s / 2, -s / 2, s, s);
      ctx.restore();
    }
  }

  dispose() { this.active = []; this.canvas?.remove(); this.canvas = null; }
}
