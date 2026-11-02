import * as THREE from 'three';
import {evalKeys} from '../skills/effects.js';
import {SOCKET_GLOW_CHOSEN as CHOSEN, socketPhase} from '../../config/engine-chosen-socket-glow.js';
import {auraValue} from '../../config/engine-chosen-aura.js';

// Gem glow of an equipped weapon (see src/config/engine-chosen-socket-glow.js for what is data and what is ENGINE-CHOSEN):
//  - weaponBlade / weaponStations: where each socket sits on the weapon (its own traceline / weaponline, else mesh bounds);
//  - WeaponGemGlow: the additive gem-coloured pass over the weapon meshes (the coloured glow ON the weapon).
// The authored socket sprites themselves are played by AuthoredEquipmentEffects through the ordinary EffectPlayer.

const _m = new THREE.Matrix4(), _inv = new THREE.Matrix4(), _box = new THREE.Box3(), _tmp = new THREE.Box3();

function polyline(points) {
  const cum = [0];
  for (let i = 1; i < points.length; i++) cum.push(cum[i - 1] + points[i].distanceTo(points[i - 1]));
  return {points, cum, length: cum[cum.length - 1]};
}
/** Named weapon lines of a weapon object (Float32Array strips of the model(s) it carries) as weapon-local point lists. */
function namedStrips(root, name) {
  const out = [], seen = new Set();
  root.updateWorldMatrix(true, true);
  _inv.copy(root.matrixWorld).invert();
  root.traverse(node => {
    const model = node.userData?.model;
    if (!model || seen.has(model)) return;
    seen.add(model);
    _m.multiplyMatrices(_inv, node.matrixWorld);
    for (const line of model.lines || []) {
      if (String(line.name).toLowerCase() !== name) continue;
      for (const strip of line.strips || []) {
        const flat = strip?.positions || strip;
        if (!flat || flat.length < 6) continue;
        const points = [];
        for (let i = 0; i + 2 < flat.length; i += 3) points.push(new THREE.Vector3(flat[i], flat[i + 1], flat[i + 2]).applyMatrix4(_m));
        out.push(points);
      }
    }
  });
  return out;
}
/** Local-space bounds of the weapon's meshes (bind pose of skinned ones). */
function localBounds(root) {
  root.updateWorldMatrix(true, true);
  _inv.copy(root.matrixWorld).invert();
  const box = new THREE.Box3();
  root.traverse(node => {
    if (!node.isMesh || !node.geometry || node.userData?.ownMat) return;
    if (!node.geometry.boundingBox) node.geometry.computeBoundingBox();
    _tmp.copy(node.geometry.boundingBox).applyMatrix4(_m.multiplyMatrices(_inv, node.matrixWorld));
    box.union(_tmp);
  });
  return box;
}
/** The line a weapon's sockets sit on, tip end first: {points, cum, length} in weapon-local space, or null for a mesh-less object.
 * ENGINE-CHOSEN source order: traceline (its blade strip), weaponline (longest strip), the long axis of the mesh bounds. */
export function weaponBlade(root) {
  if (!root) return null;
  if (root.userData._gemBlade !== undefined) return root.userData._gemBlade;
  let points = null;
  for (const name of ['traceline', 'weaponline']) {
    const strips = namedStrips(root, name).map(polyline).filter(line => line.length > 1e-3).sort((a, b) => b.length - a.length);
    if (strips.length) { points = strips[0].points; break; }
  }
  if (!points) {
    const box = localBounds(root);
    if (!box.isEmpty()) {
      const size = box.getSize(new THREE.Vector3()), axis = size.x >= size.y && size.x >= size.z ? 'x' : size.y >= size.z ? 'y' : 'z';
      const centre = box.getCenter(new THREE.Vector3()), lo = centre.clone(), hi = centre.clone();
      lo[axis] = box.min[axis]; hi[axis] = box.max[axis];
      points = [lo, hi];
    }
  }
  if (!points || points.length < 2) return (root.userData._gemBlade = null);
  // The end farther from the weapon origin (the grip) is the tip.
  if (points[points.length - 1].lengthSq() > points[0].lengthSq()) points = points.slice().reverse();
  const line = polyline(points);
  return (root.userData._gemBlade = line.length > 1e-3 ? line : null);
}
function sampleLine(line, distance) {
  const d = Math.max(0, Math.min(line.length, distance));
  let i = 1;
  while (i < line.points.length - 1 && line.cum[i] < d) i++;
  const span = line.cum[i] - line.cum[i - 1], t = span > 0 ? (d - line.cum[i - 1]) / span : 0;
  return line.points[i - 1].clone().lerp(line.points[i], t);
}
/** Socket stations of a weapon: [{index, local, spacing}] (local = weapon-space point, spacing = metres between neighbours). */
export function weaponStations(blade, capacity) {
  if (!blade || !(capacity > 0)) return [];
  const [from, to] = CHOSEN.STATION_SPAN, spacing = blade.length * (to - from) / capacity;
  return Array.from({length: capacity}, (_, index) => ({index, local: sampleLine(blade, blade.length * (from + (to - from) * (index + .5) / capacity)), spacing}));
}

/** Native blade socket attach bones from weapon skels and item_upgrade_10* scenes (SWD_W01..SWD_W04, _L twins).
 * Prefer the socket-index bone SWD_W0{index+1}, then authored mid-blade SWD_W02, then SWD_W01 / SWD_W.
 * Returns weapon-local Vector3 from the bone's world matrix — never invented constants. */
export function socketBoneLocal(weapon, slot, index) {
  if (!weapon) return null;
  const n = Math.max(1, Math.min(4, (Number(index) | 0) + 1));
  const left = slot === 'left';
  const candidates = left
    ? [`SWD_W0${n}_L`, 'SWD_W02_L', 'SWD_W01_L', 'SWD_W_L']
    : [`SWD_W0${n}`, 'SWD_W02', 'SWD_W01', 'SWD_W'];
  for (const name of candidates) {
    let bone = null;
    weapon.traverse(o => {
      if (!bone && o.isBone && (o.userData?.raw === name || o.name === name)) bone = o;
    });
    if (!bone) continue;
    weapon.updateWorldMatrix(true, true);
    bone.updateWorldMatrix(true, false);
    const local = new THREE.Vector3().setFromMatrixPosition(bone.matrixWorld);
    _inv.copy(weapon.matrixWorld).invert();
    return local.applyMatrix4(_inv);
  }
  return null;
}

/** Metres the station mist sprites are depth-shifted toward the camera (see SOCKET_GLOW_CHOSEN.MIST_DEPTH_BIAS); 0 without a mesh. */
export function weaponDepthBias(root) {
  if (!root) return 0;
  const box = localBounds(root);
  if (box.isEmpty()) return 0;
  const extent = box.getSize(new THREE.Vector3()).toArray().sort((a, b) => a - b)[1];
  const scale = Math.abs(root.getWorldScale(new THREE.Vector3()).x) || 1;
  const {FRACTION, MAX} = CHOSEN.MIST_DEPTH_BIAS;
  return Math.min(MAX, FRACTION * extent * scale);
}
/** Authored sprite scale multiplier of a station (see SOCKET_GLOW_CHOSEN.SPRITE_SPACING). */
export function stationScale(spacing) {
  return Math.max(CHOSEN.SPRITE_MIN_SCALE, Math.min(CHOSEN.SPRITE_MAX_SCALE, spacing / CHOSEN.SPRITE_SPACING));
}

const MAX_GEMS = 4;
/** Additive gem-coloured pass over a weapon's meshes. stations: [{local:Vector3 (weapon space), rgb:[r,g,b]}] (<= 4);
 * the pulse is the authored socket alpha track, so it breathes in step with the mist sprites. Handle contract of
 * AuthoredEquipmentEffects: {owner, update(dt), stop()}. */
export class WeaponGemGlow {
  constructor({weapon, owner, stations, capacity = stations.length, spacing = .5, alphaKeys = [[0, .5], [500, .8], [999, .5]], timeMs = 1000, glow = null}) {
    this.owner = owner; this.weapon = weapon; this.alphaKeys = alphaKeys; this.timeMs = timeMs; this.t = 0; this.glow = glow;
    this.peak = Math.max(...alphaKeys.map(k => k[1]), 1e-3);
    this.overlays = []; this.disposed = false;
    const gems = stations.slice(0, MAX_GEMS), mean = [0, 0, 0];
    // gem phases (see SOCKET_GLOW_CHOSEN.PHASE): the more of the sockets are filled, the stronger the whole weapon glows
    this.phase = {value: socketPhase(gems.length, capacity)};
    for (const g of gems) for (let i = 0; i < 3; i++) mean[i] += g.rgb[i] / Math.max(1, gems.length);
    this.pulse = {value: 1};
    const W = CHOSEN.WEAPON_WASH, range = Math.max(W.RANGE_MIN, spacing * W.RANGE_SPACING);
    weapon.updateWorldMatrix(true, true);
    const sources = [];
    weapon.traverse(node => { if (node.isMesh && !node.userData.ownMat && node.parent) sources.push(node); });
    for (const src of sources) {
      // Socket points in this mesh's own space (the shader compares them with the un-skinned vertex position).
      src.updateWorldMatrix(true, false);
      _inv.copy(src.matrixWorld).invert().multiply(weapon.matrixWorld);
      const uniforms = {
        dkCol: {value: Array.from({length: MAX_GEMS}, (_, i) => new THREE.Vector3(...(gems[i]?.rgb || [0, 0, 0])))},
        dkPos: {value: Array.from({length: MAX_GEMS}, (_, i) => (gems[i] ? gems[i].local.clone().applyMatrix4(_inv) : new THREE.Vector3(1e6, 1e6, 1e6)))},
        dkCount: {value: gems.length}, dkMean: {value: new THREE.Vector3(...mean)}, dkRange: {value: range}, dkPulse: this.pulse, dkPhase: this.phase,
      };
      const material = new THREE.MeshBasicMaterial({
        transparent: true, depthWrite: false, side: THREE.FrontSide, color: 0xffffff,
        // Premultiplied-alpha 'over': dst x (1 - tint) + gem colour x light. The artwork is recoloured toward the gem hue AND
        // lit by it, where a purely additive pass leaves an already bright blade white.
        blending: THREE.CustomBlending, blendEquation: THREE.AddEquation, blendSrc: THREE.OneFactor, blendDst: THREE.OneMinusSrcAlphaFactor,
        polygonOffset: true, polygonOffsetFactor: W.POLYGON_OFFSET[0], polygonOffsetUnits: W.POLYGON_OFFSET[1],
      });
      material.customProgramCacheKey = () => `socket-weapon-wash:${[W.SHELL, W.BASE, W.LOCAL, W.RIM, W.GAIN, W.MEAN_BLEND, W.TINT_BASE, W.TINT_LOCAL, W.TINT_RIM, W.TINT_CAP, W.LIGHT_CAP].join('|')}`;
      material.onBeforeCompile = shader => {
        Object.assign(shader.uniforms, uniforms);
        shader.vertexShader = shader.vertexShader
          .replace('#include <common>', '#include <common>\nvarying vec3 dkP; varying vec3 dkView;')
          .replace('#include <begin_vertex>', `#include <begin_vertex>\ndkP = position;\ntransformed += normalize(normal) * ${W.SHELL.toFixed(4)};`)
          .replace('#include <project_vertex>', '#include <project_vertex>\ndkView = -mvPosition.xyz;');
        shader.fragmentShader = shader.fragmentShader
          .replace('#include <common>', `#include <common>
varying vec3 dkP; varying vec3 dkView;
uniform vec3 dkCol[${MAX_GEMS}]; uniform vec3 dkPos[${MAX_GEMS}]; uniform float dkCount; uniform vec3 dkMean; uniform float dkRange; uniform float dkPulse; uniform float dkPhase;`)
          .replace('#include <opaque_fragment>', `
vec3 dkN = normalize(cross(dFdx(dkView), dFdy(dkView)));
float dkRim = pow(1.0 - abs(dot(dkN, normalize(dkView))), 1.6);
vec3 dkSum = vec3(0.0); float dkW = 0.0;
for (int i = 0; i < ${MAX_GEMS}; i++) {
  if (float(i) < dkCount) { float d = distance(dkP, dkPos[i]) / dkRange; float w = exp(-d * d); dkSum += dkCol[i] * w; dkW += w; }
}
vec3 dkColor = (dkSum + dkMean * ${W.MEAN_BLEND.toFixed(3)}) / (dkW + ${W.MEAN_BLEND.toFixed(3)});
float dkNear = clamp(dkW, 0.0, 1.0);
float dkLight = ${W.GAIN.toFixed(3)} * dkPulse * dkPhase * (${W.BASE.toFixed(3)} + ${W.LOCAL.toFixed(3)} * dkNear) * (0.55 + ${W.RIM.toFixed(3)} * dkRim);
outgoingLight = dkColor * min(dkLight, ${W.LIGHT_CAP.toFixed(3)});
diffuseColor.a = clamp((${W.TINT_BASE.toFixed(3)} + ${W.TINT_LOCAL.toFixed(3)} * dkNear + ${W.TINT_RIM.toFixed(3)} * dkRim) * (0.7 + 0.3 * dkPulse) * dkPhase, 0.0, ${W.TINT_CAP.toFixed(3)});
#include <opaque_fragment>`);
      };
      const mesh = src.isSkinnedMesh ? new THREE.SkinnedMesh(src.geometry, material) : new THREE.Mesh(src.geometry, material);
      if (src.isSkinnedMesh) mesh.bind(src.skeleton, src.bindMatrix);
      mesh.position.copy(src.position); mesh.quaternion.copy(src.quaternion); mesh.scale.copy(src.scale);
      mesh.frustumCulled = false; mesh.renderOrder = 10; mesh.userData.ownMat = true; mesh.userData.socketWash = true;
      src.parent.add(mesh);
      this.overlays.push(mesh);
      // aura: this wash is also a source of the soft glow buffer (graphics/glow-pass.js), in the mean gem hue, phased like the wash
      glow?.add(mesh, {hue: mean, gain: () => this.pulse.value * this.phase.value * auraValue('WEAPON_GEM')});
    }
    this.update(0);
  }
  update(dt) {
    if (this.disposed) return;
    this.t = (this.t + Math.max(0, dt) * 1000) % this.timeMs;
    this.pulse.value = (evalKeys(this.alphaKeys, this.t / this.timeMs * 999, 1)?.[0] ?? this.peak) / this.peak;
  }
  stop() { this.dispose(); }
  dispose() {
    if (this.disposed) return;
    this.disposed = true;
    for (const mesh of this.overlays) { this.glow?.remove(mesh); mesh.removeFromParent(); mesh.material.dispose(); }
    this.overlays = [];
  }
}

