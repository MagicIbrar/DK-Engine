// Aura glow of the character preview windows (Inspect / Preview player). The world draws the aura as a screen-space glow buffer
// (src/systems/graphics/glow-pass.js); a preview draws its model into a private render target and reads it back to a 2D canvas, so
// the same idea is done there: the glowing parts are drawn flat in their glow hue into a second buffer, blurred at three radii
// and added back over the character ('lighter'). Same hues and per-kind strengths as the world (engine-chosen-aura.js); the radii
// are ENGINE-CHOSEN fractions of the preview height (the preview has no fixed screen scale).
import * as THREE from 'three';
import { readRenderTargetPixels } from '../../engine/pixel-pack-readback.js';
import { equippedEffectIds } from '../items/authored-effects.js';
import { AuthoredEffectsData } from '../items/authored-effects-data.js';
import { tierHue } from '../items/preview-refinement.js';
import { socketPhase } from '../../config/engine-chosen-socket-glow.js';
import { auraValue } from '../../config/engine-chosen-aura.js';

/** [blur radius as a fraction of the preview height, layer strength]: tight core, mid, wide tail. ENGINE-CHOSEN. */
export const PREVIEW_AURA_LAYERS = Object.freeze([[0.012, 1], [0.03, 1], [0.06, 0.8]]);
/** How full a refined / gem piece is lit in a preview (the world pulses between about 0.6 and 1; the mean). */
export const PREVIEW_AURA_LEVEL = 0.75;
/** Strength of the light glow laid over the weapon itself (ENGINE-CHOSEN). */
export const PREVIEW_AURA_OVER = 0.55;

const meshesOf = object => { const out = []; object?.traverse?.(n => { if (n.isMesh) out.push(n); }); return out; };
const norm = value => String(value || '').replace(/\\/g, '/').toLowerCase();

/** Sources for one previewed player: [{meshes, hue:[r,g,b], amount}] from the worn gear's refinement tiers and weapon gems.
 *  actor = the snapshot whose save.equipment is shown, inst = its body instance, weapons = the attached weapon objects. */
export async function previewAuraSources(game, actor, inst, weapons = [], data = game?.items?.authoredEffects?.data || new AuthoredEffectsData()) {
  const db = game?.items?.db;
  if (!db || !actor?.save?.equipment) return [];
  let entries;
  try { entries = equippedEffectIds(db, actor.save.equipment, actor.save.equip); } catch { return []; }
  const eq = actor.save.equipment, weaponMeshes = weapons.flatMap(meshesOf);
  const bodyMeshes = slot => {
    const key = norm(eq[slot]?.mesh);
    return key ? (inst?.meshes || []).filter((mesh, i) => norm(inst?.model?.parts?.[i]?.meshKey) === key) : [];
  };
  const out = [];
  for (const e of entries) {
    if (e.upgrade >= 1) {
      const hue = tierHue(e.upgrade);
      if (!hue) continue;
      const weapon = e.slot === 'weapon' || e.slot === 'left';
      const meshes = weapon ? weaponMeshes : bodyMeshes(e.slot);
      if (meshes.length) out.push({ meshes, hue, part: weapon ? 'weapon' : 'armor', amount: PREVIEW_AURA_LEVEL * auraValue(weapon ? 'WEAPON_REFINE' : 'ARMOR_REFINE') });
    } else if (e.socketTint && weaponMeshes.length) {
      const hues = [];
      for (const gem of e.socketTint.gems) { const texture = await data.socketGlowTexture?.(gem.attribute); if (texture?.hue) hues.push(texture.hue); }
      if (!hues.length) continue;
      const hue = [0, 1, 2].map(i => hues.reduce((sum, h) => sum + h[i], 0) / hues.length);
      out.push({ meshes: weaponMeshes, hue, part: 'weapon', amount: PREVIEW_AURA_LEVEL * socketPhase(hues.length, e.socketTint.capacity) * auraValue('WEAPON_GEM') });
    }
  }
  return out;
}

/** Draw only the glowing meshes, flat, into rt (same camera as the model's last draw) and return the RGBA pixels (bottom-up rows). */
export function renderAuraPass(renderer, scene, camera, rt, sources, W, H) {
  const color = new Map();                         // mesh -> summed glow colour (a mesh in two sources, e.g. gems + refinement, adds)
  for (const s of sources) for (const mesh of s.meshes) {
    const c = color.get(mesh) || [0, 0, 0];
    for (let i = 0; i < 3; i++) c[i] = Math.min(1, c[i] + s.hue[i] * s.amount);
    color.set(mesh, c);
  }
  if (!color.size) return null;
  const saved = new Map(), made = [];
  scene.traverse(n => { if (n.isMesh) saved.set(n, { visible: n.visible, material: n.material }); });
  const px = new Uint8Array(W * H * 4);
  try {
    for (const n of saved.keys()) n.visible = color.has(n);
    for (const [mesh, c] of color) {
      if (!saved.has(mesh)) continue;
      const material = new THREE.MeshBasicMaterial({ color: new THREE.Color(c[0], c[1], c[2]), side: THREE.DoubleSide, toneMapped: false, fog: false });
      made.push(material); mesh.material = material; mesh.visible = true;
    }
    renderer.setRenderTarget(rt);
    renderer.setClearColor(0x000000, 0);
    renderer.clear(true, true, true);
    renderer.render(scene, camera);
    readRenderTargetPixels(renderer, rt, 0, 0, W, H, px);
  } finally {
    for (const [n, state] of saved) { n.visible = state.visible; n.material = state.material; }
    for (const m of made) m.dispose();
  }
  return px;
}

/** Add the blurred glow pixels onto a 2D canvas context. Default: the halo goes BEHIND the character ('destination-over'), so the
 *  body keeps its own colours (a flat glow colour laid over armour reads as flat paint). over = true: a light glow ON TOP
 *  ('lighter', one tight layer) - used for the weapon, which has no gem-wash shells in a preview. */
export function compositeAura(ctx, px, W, H, over = false) {
  const layer = document.createElement('canvas'); layer.width = W; layer.height = H;
  const lc = layer.getContext('2d'), img = lc.createImageData(W, H);
  for (let y = 0; y < H; y++) img.data.set(px.subarray((H - 1 - y) * W * 4, (H - y) * W * 4), y * W * 4);
  lc.putImageData(img, 0, 0);
  ctx.save();
  if (over) {
    ctx.globalCompositeOperation = 'lighter';
    ctx.filter = `blur(${Math.max(1, Math.round(PREVIEW_AURA_LAYERS[0][0] * H))}px)`;
    ctx.globalAlpha = PREVIEW_AURA_OVER;
    ctx.drawImage(layer, 0, 0);
  } else {
    ctx.globalCompositeOperation = 'destination-over';
    for (const [fraction, strength] of PREVIEW_AURA_LAYERS) {
      ctx.filter = `blur(${Math.max(1, Math.round(fraction * H))}px)`;
      ctx.globalAlpha = Math.min(1, strength);
      ctx.drawImage(layer, 0, 0);
    }
  }
  ctx.restore();
}