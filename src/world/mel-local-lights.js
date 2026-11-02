// MEL category 9 = local light placements (effectscene.map.txt cate 9, effectdata unittype=light).
// Global geometry.fx defines PointLight uniforms (max 3) but vsMapMainLight has the PointLight() call
// commented out; boneanimation.fx has no point-light technique (docs/overnight-43.19/GFX-PARITY.md row 13).
// 4.2.0 therefore does not invent THREE.PointLight construction from these rows. This module only
// extracts authored placement + resolved unit fields for inventory, tests, and future evidenced wiring
// (local fog/bloom overlays remain UNRESOLVED — no native falloff mapping recovered).

import { parseMel, melToThree, EFFECT_CATEGORY } from '../formats/mel.js';
import { parseEffectData, describeUnit, parseEffectScenes, describeControl } from '../systems/items/native-effect-parser.js';

export const MEL_LIGHT_CATEGORY = 9;

/** Stub resource resolver: light units never call texture/mesh helpers. */
const LIGHT_RES = {
  texture() { return null; },
  tpack() { return null; },
  path() { return null; },
  sound() { return null; },
};

/** True when a .mel entry is a cate-9 local light placement with a usable transform. */
export function isMelLocalLightEntry(e) {
  return !!e && e.category === MEL_LIGHT_CATEGORY && e.effectId > 0
    && [e.x, e.z, e.y, e.scale, e.qx, e.qy, e.qz, e.qw].every(Number.isFinite) && e.scale > 0;
}

/** Cate-9 entries from a .mel buffer (same filter shape as nativeVisualPlacements, category 9 only). */
export function nativeLightPlacements(melBuf) {
  return parseMel(melBuf).entries.filter(isMelLocalLightEntry).map(e => ({
    ...e,
    categoryName: EFFECT_CATEGORY[e.category] || 'light',
    ref: { cate: e.category, id: e.effectId, scene: 1 },
    three: melToThree(e, 0),
  }));
}

/**
 * Resolve cate-9 placements against effectscene.map + effectdata.map unit tables.
 * @param {Uint8Array|ArrayBuffer} melBuf
 * @param {{ scenesText: string|Uint8Array, unitsText: string|Uint8Array }} tables
 * @returns {{ placements: object[], unresolvedScene: object[], unresolvedUnit: object[] }}
 */
export function resolveMelLocalLights(melBuf, tables) {
  const scenes = parseEffectScenes(tables.scenesText, 'map')
    .filter(s => s.cate === MEL_LIGHT_CATEGORY);
  const units = parseEffectData(tables.unitsText, 'map');
  const unitByName = new Map();
  for (const u of units) {
    if (!u?.name) continue;
    const key = u.name.toLowerCase();
    if (!unitByName.has(key)) unitByName.set(key, describeUnit(u, LIGHT_RES));
  }
  const sceneByKey = new Map();
  for (const s of scenes) {
    const key = `${s.cate}:${s.id}`;
    if (!sceneByKey.has(key)) sceneByKey.set(key, s);
  }
  const placements = [];
  const unresolvedScene = [];
  const unresolvedUnit = [];
  for (const p of nativeLightPlacements(melBuf)) {
    const key = `${p.ref.cate}:${p.ref.id}`;
    const scene = sceneByKey.get(key);
    if (!scene) { unresolvedScene.push({ key, x: p.x, z: p.z }); continue; }
    const resNames = Object.values(scene.res || {}).filter(Boolean);
    const unitName = resNames[0] || null;
    // LANE-54 pass 4: the control that plays this unit (Global: `lifetime A B` -> Unit::Light start / end)
    const resId = Object.entries(scene.res || {}).find(([, n]) => n === unitName)?.[0];
    const control = (scene.scenes || []).flatMap(s => (s.controls || []).map(describeControl))
      .find(c => c.active !== false && String(c.unit) === String(resId)) || null;
    const unit = unitName ? unitByName.get(String(unitName).toLowerCase()) : null;
    if (!unit || unit.type !== 'light') {
      unresolvedUnit.push({ key, scene: scene.name, unitName, unitType: unit?.type || null });
      continue;
    }
    placements.push({
      x: p.x, y: p.y, z: p.z, scale: p.scale,
      qx: p.qx, qy: p.qy, qz: p.qz, qw: p.qw,
      effectId: p.effectId,
      sceneName: scene.name,
      unitName,
      light: unit.light || null,
      dirlight: unit.dirlight || null,
      bloom: unit.bloom || null,
      fog: unit.fog || null,
      lightEnable: unit.lightEnable,
      bloomEnable: unit.bloomEnable,
      fogEnable: unit.fogEnable,
      range: unit.range,
      fadeRange: unit.fadeRange,
      fadeMs: unit.fadeMs,
      life: control?.life || null,
      period: p.period, periodRandom: p.periodRandom,
      three: p.three,
    });
  }
  return { placements, unresolvedScene, unresolvedUnit };
}

/**
 * LANE-54: LightStart message (global-effect-light.js GlobalEffectLights.start) for one resolved placement. Pass 4: Global's
 * light unit sends duration = (lifetime end - start) x scene time scale (every Global lt_ control is `lifetime 0 1000`);
 * pass durationMs for that (MapEffectLights does, with the 4.2.0 map-scene scale period / 1000). Without it the record is
 * untimed (durationMs null) and the caller sends stop(id). The payload is the authored light / dirlight / bloom / fog targets.
 */
export function melLightStartMessage(p, id, durationMs = null) {
  return {
    id, durationMs, fadeMs: p.fadeMs ?? 0, range: p.range ?? 0, fadeRange: p.fadeRange ?? 0, pos: [p.x, p.y, p.z],
    payload: { light: p.light, dirlight: p.dirlight, bloom: p.bloom, fog: p.fog,
      lightEnable: p.lightEnable, bloomEnable: p.bloomEnable, fogEnable: p.fogEnable },
  };
}
