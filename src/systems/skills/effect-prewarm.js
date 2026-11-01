// Effect primitives are absent from the world until the first cast. Build their
// real shader shapes and GPU first draws while the map's loading screen is up.
import * as THREE from 'three';
import {SpriteUnit, ParticleUnit, DecalUnit, cameraFrame} from './fx-units.js';
import {lockedDraw, drawWithWorldLights, touchPrograms} from '../../engine/warm-draw.js';

export function effectPrimitiveCandidates(units) {
  const found = new Map();
  for (const unit of units || []) {
    if (!unit?.texture && !unit?.frames?.length) continue;
    const kind = unit.type === 'sprite' ? (unit.billboard === 'camera' || !unit.billboard ? 'sprite-camera' : 'sprite-plane')
      : unit.type === 'particle' ? 'particle' : unit.type === 'decal' ? 'decal' : null;
    if (kind && !found.has(kind)) found.set(kind, unit);
  }
  return [...found];
}

export async function prewarmEffectPrimitives(game, {current = () => true, onProgress = () => {}} = {}) {
  const renderer = game?.renderer;
  if (!renderer?.compileAsync || !game.effects?.data?.units || !game.scene || !game.camera) return {variants: 0};
  const candidates = effectPrimitiveCandidates(game.effects.data.units.values());
  const before = renderer.info.programs.length, began = performance.now();
  const root = new THREE.Group(); root.scale.set(1, 1, -1);
  const anchor = new THREE.Group(); root.add(anchor);
  const context = {game, fx: {root, cam: cameraFrame(game.camera)}, control: {}, play: {}};
  const units = [], extraMaterials = [];
  let variants = 0, skipped = 0;
  try {
    for (const [kind, definition] of candidates) {
      if (!current()) return {variants, skipped, obsolete: true};
      onProgress(variants + skipped, candidates.length, kind);
      const unit = kind === 'particle' ? new ParticleUnit(context, definition, anchor)
        : kind === 'decal' ? new DecalUnit(context, definition, anchor)
          : new SpriteUnit(context, definition, anchor);
      units.push(unit);
      await unit.readyTask;
      if (!current()) return {variants, skipped, obsolete: true};
      if (!unit.ready) { skipped++; continue; }
      unit.apply({scale: [1, 1, 1], alpha: 1, color: [1, 1, 1], ms: 0, rot: 0});
      if (kind === 'particle') {
        // Actual RGBA particle attributes, plus the mixed-facing two-pass variant.
        unit._spawn(1); unit._build();
        const material = unit.mesh.material.clone(); material.forceSinglePass = false;
        const mixed = new THREE.Mesh(unit.mesh.geometry, material);
        mixed.frustumCulled = false; root.add(mixed); extraMaterials.push(material);
      }
      variants++;
    }
    if (!variants || !current()) return {variants, skipped, obsolete: !current()};
    await renderer.compileAsync(root, game.camera, game.scene);
    if (!current()) return {variants, skipped, obsolete: true};
    touchPrograms(renderer);
    lockedDraw(renderer, () => drawWithWorldLights(game, [root], null, {sprites: true}));
    touchPrograms(renderer);
    onProgress(candidates.length, candidates.length, 'ready');
    return {variants, skipped, programs: renderer.info.programs.length - before, ms: performance.now() - began};
  } finally {
    root.removeFromParent();
    for (const material of extraMaterials) material.dispose();
    for (const unit of units) unit.dispose();
  }
}
