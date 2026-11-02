// UI effect banners: `@<effectui>id,a,ms,b` of the event messages = effect scene `id` of <cate> 8 UI
// (property/effect/effectscene.*.txt; gamedata/events_effectui.json by tools/build-events-ui.mjs), drawn at the
// original effect anchor (game2/ui_effectuiwnd.txt, pan_effect: centre top, y 80). The scene timeline (its controls'
// lifetimes, usually 0..1000) is stretched to `ms` (docs/formats/effects.md §1: the caller's time sets the length).
// Each control animates one unit sprite: scale keyframes are [t, x, y, z] — width = size*x, height = size*z
// (same as dungeons/uifx.js / Global UI camera: 1 unit = 64 reference pixels; 1024x64 lettering strips are authored
// at scale 16 x 1). Blend add = additive, modulate = normal. Particles are drawn as their texture sprite.
import { atlas } from '../../ui/atlas.js';
import { UNIT_PX } from '../dungeons/uifx.js';

function lerpKeys(keys, t, n) {
  if (!keys || !keys.length) return null;
  if (t <= keys[0][0]) return keys[0].slice(1, 1 + n);
  for (let i = 1; i < keys.length; i++) {
    const a = keys[i - 1], b = keys[i];
    if (t <= b[0]) {
      const f = (t - a[0]) / Math.max(1e-6, b[0] - a[0]);
      const out = [];
      for (let j = 1; j <= n; j++) out.push((a[j] ?? a[1]) + ((b[j] ?? b[1]) - (a[j] ?? a[1])) * f);
      return out;
    }
  }
  return keys[keys.length - 1].slice(1, 1 + n);
}

export class EffectBanners {
  constructor(game, sys) {
    this.game = game;
    this.sys = sys;
    this.live = [];
  }

  get lib() { return this.sys.data?.effectui?.effects || null; }

  async _host() {
    const ui = this.game.uiwin;
    if (!ui) return null;
    // Open the original effect window for script ownership, but draw on a fixed overlay at the
    // pan_effect anchor (center, top+80). pan_effect's 350x50 rect must not clip authored lettering
    // that is 64+ px tall (Global UI camera billboards are not clipped to that panel).
    const w = ui.window('ev_effect') || await ui.open('ev_effect').catch(() => null);
    if (!w) return null;
    if (!w.isOpen) ui.openWindow(w);
    if (!this.layer || !this.layer.isConnected) {
      this.layer = document.createElement('div');
      this.layer.className = 'ev-effect-banners';
      this.layer.style.cssText = 'position:fixed;left:50%;top:80px;width:0;height:0;overflow:visible;pointer-events:none;z-index:20';
      const root = this.game.ui || document.body;
      root.appendChild(this.layer);
    }
    // Keep pan_effect overflow visible in case a caller still parents into it.
    const pan = w.control('pan_effect');
    if (pan?.el) pan.el.style.overflow = 'visible';
    return this.layer;
  }

  /** Show UI effect `id` for `ms` milliseconds. */
  async show(id, ms = 3000) {
    const eff = this.lib?.[id] || this.lib?.[String(id)];
    if (!eff) return false;
    const host = await this._host();
    if (!host) return false;
    const scene = eff.scenes?.[0];
    if (!scene) return false;
    const len = Math.max(1, ...scene.controls.map(c => (c.life?.[1] ?? 1000)));
    const parts = [];
    for (const c of scene.controls) {
      if (c.active === false) continue;
      const u = eff.units?.[c.unit] || eff.units?.[String(c.unit)];
      if (!u?.texture) continue;
      const el = document.createElement('div');
      el.style.cssText = 'position:absolute;left:0;top:0;background-size:100% 100%;background-repeat:no-repeat;opacity:0;will-change:transform,opacity';
      // Global additive = lighter; plus-lighter is the closest CSS mix-blend (screen under-glows lettering).
      if (u.blend === 'add') el.style.mixBlendMode = 'plus-lighter';
      host.appendChild(el);
      atlas.textureURL(u.texture).then(url => { if (url) el.style.backgroundImage = `url(${url})`; });
      parts.push({ el, c, u });
    }
    if (!parts.length) return false;
    this.live.push({ parts, t: 0, ms: Math.max(100, ms), len });
    return true;
  }

  update(dt) {
    if (!this.live.length) return;
    const scale = Number(this.game.uiwin?.scale || this.game.settings?.uiScale || 1) || 1;
    const PX = UNIT_PX * scale;
    for (const b of this.live.slice()) {
      b.t += dt * 1000;
      const st = (b.t / b.ms) * b.len;            // scene time
      for (const p of b.parts) {
        const [l0, l1] = p.c.life || [0, b.len];
        if (st < l0 || st > l1) { p.el.style.opacity = '0'; continue; }
        const k = ((st - l0) / Math.max(1, l1 - l0)) * 999;
        // Global scale keys are [t, x, y, z]; width uses x, height uses z (uifx.js).
        const sc = lerpKeys(p.c.scale, k, 3) || [1, 1, 1];
        const al = lerpKeys(p.c.alpha, k, 1)?.[0] ?? 1;
        const rot = lerpKeys(p.c.rotation, k, 1)?.[0] ?? 0;
        const pos = lerpKeys(p.c.position, k, 3) || p.c.pos || [0, 0, 0];
        const size = (p.u.size || 1) * PX;
        const w = size * (sc[0] || 0);
        const h = size * (sc[2] ?? sc[1] ?? sc[0] ?? 0);
        const s = p.el.style;
        s.width = `${Math.max(0, w)}px`; s.height = `${Math.max(0, h)}px`;
        s.transform = `translate(${-w / 2 + (pos[0] || 0) * PX}px, ${-h / 2 - (pos[1] || 0) * PX}px) rotate(${rot}deg)`;
        s.opacity = String(Math.max(0, Math.min(1, al)));
      }
      if (b.t >= b.ms) {
        for (const p of b.parts) p.el.remove();
        this.live.splice(this.live.indexOf(b), 1);
      }
    }
  }
}