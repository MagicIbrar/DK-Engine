import {AuthoredEffectsData, refinementEffect, upgradeEffectMode} from './authored-effects-data.js';
import {MeshStatusUnit} from '../skills/fx-units.js';
import {evalKeys} from '../skills/effects.js';

/** Colour of a refinement family = the colour of its tier texture (eff_upgrade_13 silver, 46 blue, 79 gold, 1114 red, 15 purple). */
const FAMILY_HUE = {1: [0.82, 0.88, 1.0], 2: [0.45, 0.65, 1.0], 3: [1.0, 0.62, 0.18], 4: [1.0, 0.22, 0.15], 5: [0.85, 0.15, 1.0]};
export const tierHue = tier => FAMILY_HUE[upgradeEffectMode(tier)] || null;
/** ENGINE-CHOSEN look of the weapon aura on inventory icons (the pulse itself is the authored UI scene alpha track):
 *  a tier-coloured share of the artwork plus soft halos of its silhouette behind it. */
export const TIER_AURA = Object.freeze({TINT: 0.06, HALOS: Object.freeze([[3, 0.9], [7, 0.7]])});   // [blur in reference px, strength]: an outer aura, the art stays visible

/** Composite the tier aura into every frame of an icon sheet. alphaAt(phase) = authored alpha of the refinement scene. */
export function compositeTierAura(base, hue, alphaAt, {W, H, cols, rows, frames, S}) {
  const make = () => { const c = document.createElement('canvas'); c.width = W; c.height = H; return c; };
  const output = document.createElement('canvas'); output.width = base.width; output.height = base.height;
  const out = output.getContext('2d'), frame = make(), tint = make(), f = frame.getContext('2d'), t = tint.getContext('2d');
  const colour = `rgb(${hue.map(v => Math.round(Math.max(0, Math.min(1, v)) * 255)).join(',')})`;
  for (let k = 0; k < frames; k++) {
    const col = k % cols, row = Math.floor(k / cols), a = Math.max(0, Math.min(1, alphaAt(k / frames)));
    f.clearRect(0, 0, W, H); f.drawImage(base, col * W, row * H, W, H, 0, 0, W, H);
    t.globalCompositeOperation = 'source-over'; t.clearRect(0, 0, W, H); t.drawImage(frame, 0, 0);
    t.globalCompositeOperation = 'source-atop'; t.fillStyle = colour; t.fillRect(0, 0, W, H);
    out.save(); out.beginPath(); out.rect(col * W, row * H, W, H); out.clip(); out.translate(col * W, row * H);
    out.globalCompositeOperation = 'source-over'; out.globalAlpha = 1; out.drawImage(frame, 0, 0);
    out.globalCompositeOperation = 'source-atop'; out.globalAlpha = Math.min(1, TIER_AURA.TINT * a); out.drawImage(tint, 0, 0);
    out.globalCompositeOperation = 'destination-over';
    for (const [blur, strength] of TIER_AURA.HALOS) { out.filter = `blur(${blur * S}px)`; out.globalAlpha = Math.min(1, strength * a); out.drawImage(tint, 0, 0); }
    out.filter = 'none'; out.restore();
  }
  return output;
}

/** Dedicated authored UI upgrade scene, sampled into cached icon sheets. */
export function previewRefinement(def) {
  const entry = refinementEffect(def);
  return entry?.upgrade >= 1 ? {tier: entry.upgrade, weapon: entry.weapon} : null;
}

export async function preparePreviewRefinement(game, root, spec, data = new AuthoredEffectsData()) {
  if (!spec) return null;
  const ref = await data.inventoryUpgradeReference(spec.tier);
  if (!ref) return null;
  const scene = data.scene(`${ref.cate}:${ref.id}`);
  const controls = scene?.scenes[ref.scene]?.controls || [];
  const meshes = [];
  root.traverse(node => { if (node.isMesh) meshes.push(node); });
  if (!meshes.length) return null;
  const units = [];
  try {
    for (const control of controls) {
      const unit = data.unit(scene.res[control.unit]);
      if (control.active === false || unit?.type !== 'meshstatus') continue;
      // UI scenes supply their own color, alpha and tiny shell; worn shine is a separate effect.
      const overlay = new MeshStatusUnit({game}, unit, {instance: {meshes}});
      units.push({overlay, control});
      await overlay.readyTask;
      if (!overlay.ready) throw new Error('Original refinement texture is unavailable');
      overlay.overlays.forEach((mesh, index) => {
        const material = meshes[index].material;
        // Inventory shape flags deliberately render some meshes on both sides.
        mesh.material.side = (Array.isArray(material) ? material[0] : material).side;
        // The authored UI shell (0.0001) is far thinner than the icon camera's depth resolution: without a depth bias the
        // overlay z-fights behind its own item and the item reads flat. Same bias as worn gear (fx-units MeshStatusUnit).
        mesh.material.polygonOffset = true; mesh.material.polygonOffsetFactor = -4; mesh.material.polygonOffsetUnits = -16;
      });
    }
  } catch (error) {
    for (const {overlay} of units) overlay.dispose();
    throw error;
  }
  return {
    padding: Math.max(0, ...units.map(({overlay}) => Number(overlay.unit.size) || 0)),
    weapon: !!spec.weapon, hue: tierHue(spec.tier),
    /** Authored scene time (ms) of a sheet frame. The authored loop is `lifetime 0 1000` (one second); a sheet spanning `period`
     *  seconds holds `period` whole pulses (the real rate) and loops seamlessly. Phase 0 is the pulse peak (what a still shows). */
    timeAt(phase, period = 1) {
      const loop = ref.timeMs;
      return (((phase * period * 1000 + loop / 2) % loop) + loop) % loop;
    },
    /** Authored alpha of the refinement scene at a sheet frame (drives the aura of weapons on top of the overlay). */
    alphaAt(phase, period = 1) {
      const control = units[0]?.control, ms = this.timeAt(phase, period);
      return control ? (evalKeys(control.alpha, Math.min(999, ms / ref.timeMs * 999), 1)?.[0] ?? 1) : 1;
    },
    sample(phase, period = 1) {
      const ms = this.timeAt(phase, period);
      for (const {overlay, control} of units) {
        const start = (Number(control.life?.[0]) || 0) * ref.timeMs / 1000;
        const end = Number(control.life?.[1] ?? 1000) * ref.timeMs / 1000;
        const live = ms >= start && ms < end;
        for (const mesh of overlay.overlays) mesh.visible = live;
        const age = Math.max(0, ms - start), life = Math.max(1, end - start);
        const key = Math.min(999, age / life * 999);
        // A cached sheet cannot scroll seamlessly (b is per second, the loop is not a whole number of scrolls): the texture stays
        // put (ms 0) and only the authored alpha/colour pulse plays, at its real rate.
        overlay.apply({ms: 0, life, alpha: evalKeys(control.alpha, key, 1)?.[0] ?? 1, color: evalKeys(control.color, key, 3)});
      }
    },
    dispose() { for (const {overlay} of units) overlay.dispose(); },
  };
}
