import * as THREE from 'three';
import { gfxB } from '../../config/gfx-b-switches.js'; // gfx-B2 round 3

// ENGINE-CHOSEN blur/composite: Global supplies glow/upgrade textures, but the
// original blurglow.fx weights and offsets are runtime values, absent from data.
// Only those authored colors enter this pass; ordinary item pixels never glow.
export const PREVIEW_GLOW_RADIUS = 3;
export const PREVIEW_GLOW_STRENGTH = 0.9;

export function preparePreviewGlow(root, refinement = false) {
  const entries = [], owned = [];
  let active = false;
  root.traverse(mesh => {
    if (!mesh.isMesh) return;
    if (refinement && mesh.userData.ownMat) { active = true; return; }
    const convert = source => {
      const glow = source.emissiveMap && source.emissive && source.emissive.getHex() !== 0;
      if (glow) active = true;
      const material = new THREE.MeshBasicMaterial({
        map: glow ? source.emissiveMap : source.map,
        color: glow ? source.emissive.clone().multiplyScalar(source.emissiveIntensity ?? 1) : 0x000000,
        colorWrite: !!glow, depthWrite: source.depthWrite, depthTest: source.depthTest,
        transparent: source.transparent, opacity: source.opacity, alphaTest: source.alphaTest,
        side: source.side, toneMapped: false,
      });
      owned.push(material); return material;
    };
    entries.push({mesh, material: mesh.material, glow: Array.isArray(mesh.material) ? mesh.material.map(convert) : convert(mesh.material)});
  });
  if (!active) { for (const material of owned) material.dispose(); return null; }
  return {
    // 2.2.1: the glow variants of the materials link in parallel before the first slice draws them (the bake used to link them inside the draw:
    // a 138 ms frame on the first pick-up of an item kind, measured). Kill switch globalThis.__dekaronNoPrewarm.
    async compile(renderer, scene, camera) {
      if (globalThis.__dekaronNoPrewarm === true || typeof renderer?.compileAsync !== 'function') return;
      try { for (const entry of entries) entry.mesh.material = entry.glow; await renderer.compileAsync(scene, camera); }
      catch { /* the draw compiles as before */ }
      finally { for (const entry of entries) entry.mesh.material = entry.material; }
    },
    render(renderer, scene, camera) {
      try { for (const entry of entries) entry.mesh.material = entry.glow; renderer.render(scene, camera); }
      finally { for (const entry of entries) entry.mesh.material = entry.material; }
    },
    dispose() { for (const material of owned) material.dispose(); },
  };
}

// Additive GL buffers may carry emitted RGB without matching coverage alpha.
// Represent the same RGB energy as straight RGBA before Canvas premultiplies it;
// retaining the old alpha here would multiply the authored effect alpha twice.
export function previewGlowRGBA(pixels, output = new Uint8ClampedArray(pixels.length)) {
  for (let i = 0; i < pixels.length; i += 4) {
    const coverage = Math.max(pixels[i], pixels[i + 1], pixels[i + 2]);
    output[i] = coverage ? pixels[i] * 255 / coverage : 0;
    output[i + 1] = coverage ? pixels[i + 1] * 255 / coverage : 0;
    output[i + 2] = coverage ? pixels[i + 2] * 255 / coverage : 0;
    output[i + 3] = coverage;
  }
  return output;
}

/** Composite each frame independently so a sprite-sheet neighbour cannot bleed. */
export function compositePreviewGlow(base, glow, width, height, cols, rows, pixelScale = 2) {
  if (gfxB('previewGlowHaloOff')) return base;   // gfx-B2 round 3: engine-chosen blur halo off; base already carries the emissive glow map
  const frame = document.createElement('canvas'); frame.width = width; frame.height = height;
  const output = document.createElement('canvas'); output.width = base.width; output.height = base.height;
  const f = frame.getContext('2d'), out = output.getContext('2d');
  for (let y = 0; y < rows; y++) for (let x = 0; x < cols; x++) {
    f.clearRect(0, 0, width, height);
    f.save(); f.filter = `blur(${PREVIEW_GLOW_RADIUS * pixelScale}px)`; f.globalAlpha = PREVIEW_GLOW_STRENGTH;
    f.drawImage(glow, x * width, y * height, width, height, 0, 0, width, height); f.restore();
    f.drawImage(base, x * width, y * height, width, height, 0, 0, width, height);
    out.drawImage(frame, x * width, y * height);
  }
  return output;
}
