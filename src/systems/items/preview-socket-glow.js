import {evalKeys} from '../skills/effects.js';
import {SOCKET_GLOW_CHOSEN, socketPhase} from '../../config/engine-chosen-socket-glow.js';
import {gfxB} from '../../config/gfx-b-switches.js'; // LANE-70b: iconSocketWashOff

// Socket glow of an inventory / equipment / drag icon (weapons with stones). Baked into the icon sheet like the refinement halo
// (preview-glow.js), so every paint path (bag grid, equipment slot, drag icon, tooltips) shows it with no extra DOM work.
//
// DATA: which scene -> modeleffect group24 attribute -> effectscene.com cate 8 (UI) ids 1..6, the UI twin of the cate 7 socket
// scene: sprite sp_soket_<element> (size .9, texture/Effect/soket/socket_*.dds, additive), scale keys (1.5,1,1.5)(1.8,2,1.8)
// (1.5,1,1.5), alpha keys (.5)(.8)(.5), 1000 ms loop. The gem hue is socketHueOf(that texture).
// ENGINE-CHOSEN (src/config/engine-chosen-socket-glow.js ICON): the UI scene authors no position, so one sprite sits on each
// filled socket marker; one UI unit = marker size x SPRITE_UNIT (JUDGMENT: Global authors no UI-unit-to-icon-pixel scale).
// LANE-70b: the gem-coloured tint/wash over the artwork, its halo stack and SPRITE_GAIN are ENGINE-CHOSEN with no Global source;
// gfx-B iconSocketWashOff (default on) removes them, leaving the authored sprite at its authored alpha.

// Position in the authored 1000 ms pulse of sheet frame k. frame 0 = authored alpha peak (still thumbnails show the effect). The sheet
// is the 2 s spin loop and must loop seamlessly, so it holds ONE pulse (it used to hold one per second: 2 per loop).
// The in-hand socket loop is the authored modeleffect group 24 eff_time (1000 ms, LANE-63).
const pulseMs = (k, frames) => (500 + k / Math.max(1, frames) * 1000) % 1000;

/** Everything one socket glow needs from the data: per attribute {hue, texture canvas, scale/alpha keys, unit size}. */
export async function prepareSocketGlow(data, glow) {
  const assets = new Map();
  for (const attribute of new Set(glow.gems.map(g => g.attribute))) {
    const [ui, texture] = await Promise.all([data.inventorySocketReference(attribute), data.socketGlowTexture(attribute)]);
    if (!ui || !texture) throw new Error('Original socket glow assets are unavailable');
    const canvas = document.createElement('canvas');
    canvas.width = texture.width; canvas.height = texture.height;
    canvas.getContext('2d').putImageData(new ImageData(new Uint8ClampedArray(texture.rgba), texture.width, texture.height), 0, 0);
    assets.set(attribute, {hue: texture.hue, canvas, scale: ui.control.scale, alpha: ui.control.alpha, size: Number(ui.unit?.size) || .9, timeMs: ui.timeMs});
  }
  return assets;
}

const rgb = (hue, scale = 255) => `rgb(${hue.map(v => Math.round(Math.max(0, Math.min(1, v)) * scale)).join(',')})`;

/** Composite the glow into every frame of a sheet (cols x rows frames of W x H, glow gems in reference px, S = sheet px per
 * reference px). Returns a new canvas of the same size. */
export function compositeSocketGlow(base, assets, glow, {W, H, cols, rows, frames, S, period}) {
  const C = SOCKET_GLOW_CHOSEN.ICON, authoredOnly = gfxB('iconSocketWashOff');
  const output = document.createElement('canvas'); output.width = base.width; output.height = base.height;
  const out = output.getContext('2d');
  const mk = () => { const c = document.createElement('canvas'); c.width = W; c.height = H; return c; };
  const frame = mk(), tint = mk(), halo = mk(), f = frame.getContext('2d'), t = tint.getContext('2d'), h = halo.getContext('2d');
  const gems = glow.gems.map(g => ({...g, x: g.x * S, y: g.y * S, size: g.size * S, asset: assets.get(g.attribute)}));
  // gem phases (SOCKET_GLOW_CHOSEN.PHASE): the wash, halo and sprites are the look of a full weapon, scaled by how many sockets are filled
  const phase = socketPhase(gems.length, glow.capacity || gems.length);
  const mean = [0, 0, 0];
  for (const g of gems) for (let i = 0; i < 3; i++) mean[i] += g.asset.hue[i] / gems.length;
  for (let k = 0; k < frames; k++) {
    const col = k % cols, row = Math.floor(k / cols), ms = pulseMs(k, frames, period), key = ms / 1000 * 999;
    f.globalCompositeOperation = 'source-over'; f.globalAlpha = 1; f.clearRect(0, 0, W, H);
    f.drawImage(base, col * W, row * H, W, H, 0, 0, W, H);
    // The artwork's silhouette coloured by the gems nearest to each pixel.
    t.globalCompositeOperation = 'source-over'; t.globalAlpha = 1; t.clearRect(0, 0, W, H);
    t.drawImage(frame, 0, 0);
    t.globalCompositeOperation = 'source-atop';
    t.fillStyle = rgb(mean); t.fillRect(0, 0, W, H);
    for (const g of gems) {
      const radius = Math.max(1, C.RANGE * g.size), grad = t.createRadialGradient(g.x, g.y, 0, g.x, g.y, radius), colour = rgb(g.asset.hue);
      grad.addColorStop(0, colour); grad.addColorStop(1, colour.replace('rgb', 'rgba').replace(')', ',0)'));
      t.fillStyle = grad; t.fillRect(0, 0, W, H);
    }
    const pulse = (evalKeys(gems[0].asset.alpha, key, 1)?.[0] ?? .8) / .8;
    out.save();
    out.beginPath(); out.rect(col * W, row * H, W, H); out.clip();
    out.translate(col * W, row * H);
    out.globalCompositeOperation = 'source-over'; out.globalAlpha = 1; out.drawImage(frame, 0, 0);
    if (!authoredOnly) {
    // recolour a share of the artwork, then light it with the gem colour
    out.globalCompositeOperation = 'source-atop'; out.globalAlpha = Math.min(1, C.TINT * pulse * phase); out.drawImage(tint, 0, 0);
    out.globalCompositeOperation = 'lighter'; out.globalAlpha = Math.min(1, C.WASH * pulse * phase); out.drawImage(tint, 0, 0);
    // ghost halo behind the art: stacked blurred copies of the gem-coloured silhouette, from tight to wide
    out.globalCompositeOperation = 'destination-over';
    for (const [blur, strength] of C.HALOS || [[C.HALO_BLUR, 1]]) {
      h.globalCompositeOperation = 'source-over'; h.globalAlpha = 1; h.clearRect(0, 0, W, H);
      h.filter = `blur(${blur * S}px)`; h.drawImage(tint, 0, 0); h.filter = 'none';
      out.globalAlpha = Math.min(1, C.HALO * strength * pulse * phase); out.drawImage(halo, 0, 0);
    }
    }
    // the authored UI sprite on every filled socket marker
    out.globalCompositeOperation = 'lighter';
    for (const g of gems) {
      const a = g.asset, scale = evalKeys(a.scale, key, 3) || [1, 1, 1], alpha = evalKeys(a.alpha, key, 1)?.[0] ?? 1;
      const unit = g.size * C.SPRITE_UNIT * a.size, width = unit * scale[0], height = unit * (scale[1] ?? scale[0]);
      out.globalAlpha = Math.max(0, Math.min(1, alpha * (authoredOnly ? 1 : C.SPRITE_GAIN)));
      out.drawImage(a.canvas, g.x - width / 2, g.y - height / 2, width, height);
    }
    out.restore();
  }
  return output;
}
