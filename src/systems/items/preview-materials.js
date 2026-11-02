// Inventory bones animate an item mesh; they do not turn it into a world character.
// Original binary/itemmesh.fx ItemMeshSpecular uses the authored specular mask and
// viewer light. Reuse ModelCache materials so previews never modify world materials.
import { reapplySpecular } from '../../engine/matfx.js';
import { gfxB } from '../../config/gfx-b-switches.js'; // gfx-B2 round 3

const variants = new WeakMap();
export function refinementTier(def, shape) {
  // Shape-authored effects take precedence. The generic native +tier curve is
  // compiled into the client, so this restrained mask-based enhancement is an
  // engine approximation, not a reconstructed original tier palette.
  return shape?.effect || shape?.effectAdd ? 0 : Math.min(10, Math.max(0, Number(def?.itemLv) || 0));
}
export const FORTIFY_STRENGTH = 0.4;
export function fortifiedMaterial(base, tier) {
  if (gfxB('previewFortifyOff')) return base;   // gfx-B2 round 3: engine approximation off (no Global tier curve in data)
  if (!(tier >= 4) || !base.specularMap || base.userData?.maxDiffuse) return base;
  let cache = variants.get(base);
  if (!cache) variants.set(base, cache = new Map());
  if (cache.has(tier)) return cache.get(tier);
  const material = reapplySpecular(base, base.clone());
  const strength = FORTIFY_STRENGTH * Math.min(1, (tier - 3) / 7);
  const previous = material.onBeforeCompile;
  material.onBeforeCompile = function(shader, renderer) {
    previous.call(this, shader, renderer);
    shader.uniforms.dkFortify = { value: strength };
    shader.fragmentShader = shader.fragmentShader
      .replace('#include <common>', '#include <common>\nuniform float dkFortify;')
      .replace('dkSpecAdd *= dkSpecGain;', `
      dkSpecAdd *= dkSpecGain;
      float dkEdge = pow(1.0 - max(dot(normalize(normal), normalize(vViewPosition)), 0.0), 3.0);
      // Original specular mask + diffuse color retain the armor's own palette.
      dkSpecAdd += dkSpecGain * dkFortify * specularStrength * diffuseColor.rgb * dkEdge;
      dkSpecAdd *= 1.0 + dkFortify;`);
  };
  const key = material.customProgramCacheKey;
  material.customProgramCacheKey = function() { return `${key.call(this)}|dkfortify1`; };
  material.userData.dkFortifyTier = tier;
  cache.set(tier, material);
  return material;
}
// Item icon lighting = original binary/itemmesh.fx: COLOR0 = saturate(ambient + max(N.L, 0) x light) modulates the
// texture, so a lit item is never drawn brighter than its texture and a surface facing the light shows exactly its
// texture colour. three r170 divides light by PI (BRDF_Lambert), so the icon lights are given in the same x PI units
// as the world (environment.js); ICON_LIGHT keeps the engine's ambient / key ratio (the exe sets the inventory light,
// it is not in the data). The world gets the same clamp from shade.js, whose sun fall-off icons must not use.
export const ICON_LIGHT = { ambient: 0.75 * Math.PI, key: 1.15 * Math.PI };
const CLAMP = 'outgoingLight = min(outgoingLight - totalEmissiveRadiance, diffuseColor.rgb) + totalEmissiveRadiance;\n#include <opaque_fragment>';
const clamped = new WeakMap();
function addClamp(material) {
  const previous = Object.prototype.hasOwnProperty.call(material, 'onBeforeCompile') ? material.onBeforeCompile : null;
  material.onBeforeCompile = function(shader, renderer) {
    if (previous) previous.call(this, shader, renderer);
    shader.fragmentShader = shader.fragmentShader.replace('#include <opaque_fragment>', CLAMP);
  };
  const key = Object.prototype.hasOwnProperty.call(material, 'customProgramCacheKey') ? material.customProgramCacheKey : null;
  material.customProgramCacheKey = function() { return `${key ? key.call(this) : ''}|dkiconclamp1`; };
  material.userData.dkIconClamp = true;
  material.needsUpdate = true;
  return material;
}
/** The icon-only clamped variant of a lit item material (shared ModelCache materials are never modified). */
export function iconMaterial(base) {
  if (!base || base.userData?.maxDiffuse || base.userData?.dkIconClamp || !(base.isMeshLambertMaterial || base.isMeshPhongMaterial)) return base;
  if (base.userData?.dkFortifyTier) return addClamp(base);   // fortified variants already exist only for icons
  let material = clamped.get(base);
  if (!material) clamped.set(base, material = addClamp(reapplySpecular(base, base.clone())));
  return material;
}
export function iconMaterials(root) {
  root.traverse(node => { if (node.isMesh && node.material) node.material = Array.isArray(node.material) ? node.material.map(iconMaterial) : iconMaterial(node.material); });
}
export function inventoryMaterials(root, models, twoSide, tier = 0) {
  root.traverse(node => {
    if (!node.isMesh || !node.material) return;
    // Original itemmesh.fx blends partial-alpha item textures (potion glass over its liquid). A 0.5 cut-out drew
    // that glass as opaque grey patches with jagged edges; smooth alpha blends, 1-bit alpha stays cut out.
    const blended = material => material.transparent || (material.map?.userData?.alphaKind === 'smooth' && !material.userData?.maxDiffuse);
    const convert = material => iconMaterial(fortifiedMaterial(models.material(material.map, {
      twoSide: !!twoSide,
      transparent: blended(material),
      alphaTest: blended(material) && !material.transparent ? null : material.alphaTest,
      depthWrite: blended(material) && !material.transparent ? false : material.depthWrite,
      maxDiffuse: !!material.userData?.maxDiffuse,
      specularMap: material.specularMap,
      specKind: 'item',
      glowMap: material.emissiveMap,
    }), tier));
    node.material = Array.isArray(node.material) ? node.material.map(convert) : convert(node.material);
  });
}
