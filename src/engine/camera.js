import { withLocalAvatarBody, suspendFirstPersonBody, exposeLocalNativeMount, scheduleFirstPersonPrewarm } from './native-first-person-presentation.js';
// Dekaron-style third-person camera: orbits the player, right/middle-drag or arrow keys rotate,
// wheel zooms, never dips under the terrain.
import * as THREE from 'three';
import {exposeLocalBuffShells} from './first-person-buff-visuals.js';
import {lookDownOffsetScale} from '../config/engine-chosen-first-person.js';

export class FollowCamera {
  constructor(camera, input, opts = {}) {
    this.camera = camera;
    this.input = input;
    this.target = new THREE.Vector3();
    this.yaw = opts.yaw ?? Math.PI * 0.75;     // radians around +Y
    this.pitch = opts.pitch ?? 0.55;           // radians above horizon
    this.distance = opts.distance ?? 12;
    this.minDistance = opts.minDistance ?? 2;
    this.maxDistance = opts.maxDistance ?? 30;
    this.minPitch = opts.minPitch ?? -0.15;
    this.maxPitch = opts.maxPitch ?? 1.35;
    this.height = opts.height ?? 1.7;          // look-at offset above the target's feet
    this.followRate = opts.followRate ?? 28;   // tighter horizontal response; terrain height stays independently soft
    this.heightAt = opts.heightAt || null;     // (x, z) => ground height, for camera ground clamp
    this.collide = opts.collide || null;       // (look, cam) => free fraction 0..1 of that segment (buildings)
    this._smoothed = new THREE.Vector3();
    this._first = true;
    this.mode = 'third-person';
    this.firstPersonFov = 70;
    this.eyeOffset = opts.eyeOffset || (() => null);
    this.eyeHeight = opts.eyeHeight || (() => this.height);
  }

  /** Apply per-map camera settings from maplist.csv (Camera_Near_Distance, Camera_Far_Distance, Camera_Height, Camera_MinAngle, Camera_MaxAngle, DefaultZoom). */
  configure(row) {
    const eyePitch = this.mode === 'first-person' ? this.pitch : null;
    if (eyePitch != null) this.pitch = this._thirdPerson.pitch;
    const num = (k, d) => (row && row[k] !== undefined && row[k] !== '' && Number.isFinite(+row[k]) ? +row[k] : d);
    this.minDistance = num('Camera_Near_Distance', this.minDistance);
    this.maxDistance = Math.max(num('Camera_Far_Distance', this.maxDistance), this.minDistance + 1);
    this.height = num('Camera_Height', this.height);
    this.distance = THREE.MathUtils.clamp(num('DefaultZoom', this.distance), this.minDistance, this.maxDistance);
    // (playgate) the map's own vertical view: Camera_MinAngle / Camera_MaxAngle limits and the Default_V_Angle start
    // elevation, in degrees (towns 50: looking down over the roofs; fields / dungeons 15). A few rows carry radian-sized
    // values (0.98, 0.03): read anything under 2 as radians.
    const deg = (v) => (Math.abs(v) < 2 ? v : THREE.MathUtils.degToRad(v));
    const lo = num('Camera_MinAngle', null), hi = num('Camera_MaxAngle', null);
    if (lo != null && hi != null && hi > lo) {
      this.minPitch = Math.max(deg(lo), -0.35);   // never under the player's feet (the ground clamp keeps it above terrain)
      this.maxPitch = Math.min(deg(hi), 1.45);
    }
    const v = num('Default_V_Angle', null);
    if (v != null) this.pitch = THREE.MathUtils.clamp(deg(v), this.minPitch, this.maxPitch);
    if (eyePitch != null) { this._thirdPerson = this.thirdPersonView(false); this.pitch = eyePitch; }
  }

  /** Opt-in presentation only; yaw remains the existing camera-relative movement heading. */
  setMode(mode) {
    mode = mode === 'first-person' ? mode : 'third-person';
    if (mode === this.mode) return;
    if (mode === 'first-person') {
      this._thirdPerson = this.thirdPersonView();
      this._projection = { fov: this.camera.fov, near: this.camera.near };
      this.pitch = 0;
      this.camera.fov = this.firstPersonFov;
      this.camera.near = 0.05;
    } else {
      this.pitch = THREE.MathUtils.clamp(this._thirdPerson.pitch, this.minPitch, this.maxPitch);
      this.distance = THREE.MathUtils.clamp(this._thirdPerson.distance, this.minDistance, this.maxDistance);
      Object.assign(this.camera, this._projection);
      this._projection = null;
    }
    this.mode = mode;
    this.camera.updateProjectionMatrix();
    this.snap();
  }

  setFirstPersonFov(value) {
    const n = Number(value);
    this.firstPersonFov = THREE.MathUtils.clamp(Number.isFinite(n) ? n : 70, 50, 100);
    if (this.mode === 'first-person') { this.camera.fov = this.firstPersonFov; this.camera.updateProjectionMatrix(); }
  }

  thirdPersonView(saved = true) {
    return { yaw: this.yaw, pitch: saved && this.mode === 'first-person' ? this._thirdPerson.pitch : this.pitch, distance: this.distance };
  }

  restoreThirdPersonView(view) {
    this.yaw = view.yaw;
    const pitch = THREE.MathUtils.clamp(view.pitch, this.minPitch, this.maxPitch);
    this.distance = THREE.MathUtils.clamp(view.distance, this.minDistance, this.maxDistance);
    if (this.mode === 'first-person') this._thirdPerson = { ...view, pitch, distance: this.distance };
    else this.pitch = pitch;
  }

  update(dt) {
    const inp = this.input;
    if (inp.held.right || inp.held.middle) {
      this.yaw -= inp.mouse.dx * 0.006;
      this.pitch += inp.mouse.dy * 0.005;
    }
    const rot = 1.8 * dt;
    this.yaw -= (inp.gamepad?.lookX || 0) * rot;
    this.pitch += (inp.gamepad?.lookY || 0) * rot * 0.6;
    if (inp.down('ArrowLeft')) this.yaw += rot;
    if (inp.down('ArrowRight')) this.yaw -= rot;
    if (inp.down('ArrowUp')) this.pitch += rot * 0.6;
    if (inp.down('ArrowDown')) this.pitch -= rot * 0.6;
    const firstPerson = this.mode === 'first-person';
    if (!firstPerson) {
      if (inp.mouse.wheel) this.distance *= Math.pow(1.12, inp.mouse.wheel);
      if (inp.down('PageUp')) this.distance *= 1 - dt;
      if (inp.down('PageDown')) this.distance *= 1 + dt;
    }
    this.distance = THREE.MathUtils.clamp(this.distance, this.minDistance, this.maxDistance);
    this.pitch = THREE.MathUtils.clamp(this.pitch, firstPerson ? -1.45 : this.minPitch, firstPerson ? 1.45 : this.maxPitch);

    if (firstPerson) {
      let height = Number(this.eyeHeight());
      if (!Number.isFinite(height)) height = 1.7;
      const eyeY = this.target.y + Math.max(0.6, height);
      this._eyeY = this._first ? eyeY : this._eyeY + (eyeY - this._eyeY) * (1 - Math.exp(-dt * 5));
      this._first = false;
      const ground = this.heightAt?.(this.target.x, this.target.z);
      // Follow the accepted player XZ pose exactly; soften terrain seams without camera bob from animated bones.
      const pos = new THREE.Vector3(this.target.x, Math.max(this._eyeY, Number.isFinite(ground) ? ground + 0.6 : -Infinity), this.target.z);
      const cp = Math.cos(this.pitch);
      const eyeOffset = this.eyeOffset();
      if (eyeOffset && Number.isFinite(eyeOffset.x) && Number.isFinite(eyeOffset.z)) { const k = lookDownOffsetScale(this.pitch); pos.x += eyeOffset.x * k; pos.z += eyeOffset.z * k; }   // eased back over the body when looking down (config/engine-chosen-first-person.js)
      this.camera.position.copy(pos);
      this.camera.lookAt(pos.clone().add(new THREE.Vector3(-Math.sin(this.yaw) * cp, -Math.sin(this.pitch), -Math.cos(this.yaw) * cp)));
      return;
    }

    const look = (this._look ||= new THREE.Vector3()).copy(this.target); look.y += this.height;   // lane-core: reused scratch (was a clone per frame)
    if (this._first) { this._smoothed.copy(look); this._first = false; }
    // follow tightly in XZ, but softly in height, so small ground-height steps (tile seams, walkable-object surfaces)
    // never bob the whole view
    const kxz = 1 - Math.exp(-dt * this.followRate), ky = 1 - Math.exp(-dt * 5);
    this._smoothed.x += (look.x - this._smoothed.x) * kxz;
    this._smoothed.z += (look.z - this._smoothed.z) * kxz;
    this._smoothed.y += (look.y - this._smoothed.y) * ky;

    const cp = Math.cos(this.pitch);
    const pos = (this._pos ||= new THREE.Vector3()).set(   // lane-core: reused scratch (was a new Vector3 per frame)
      this._smoothed.x + Math.sin(this.yaw) * cp * this.distance,
      this._smoothed.y + Math.sin(this.pitch) * this.distance,
      this._smoothed.z + Math.cos(this.yaw) * cp * this.distance,
    );
    // (playgate) camera collision with buildings / walls (opts.collide: free fraction of the look -> camera segment):
    // pull in at once, ease back out, so the player is never hidden behind a roof or wall
    if (this.collide) {
      let want = 1;
      try { const t = Number(this.collide(this._smoothed, pos)); if (Number.isFinite(t)) want = Math.max(0.05, Math.min(1, t)); } catch { /* no world yet */ }
      const cur = this._clipT ?? 1;
      this._clipT = want < cur ? want : cur + (want - cur) * (1 - Math.exp(-dt * 4));
      if (this._clipT < 0.999) pos.lerpVectors(this._smoothed, pos, this._clipT);
    }
    if (this.heightAt) {
      const g = this.heightAt(pos.x, pos.z);
      if (Number.isFinite(g) && pos.y < g + 0.6) pos.y = g + 0.6;
    }
    this.camera.position.copy(pos);
    this.camera.lookAt(this._smoothed);
  }

  /** Unit vectors on the XZ plane for camera-relative WASD movement. */
  groundBasis() {
    const f = new THREE.Vector3(-Math.sin(this.yaw), 0, -Math.cos(this.yaw));
    const r = new THREE.Vector3(-f.z, 0, f.x);
    return { forward: f, right: r };
  }

  snap() { this._first = true; this._clipT = 1; }
}

/** Hide only the owned avatar for the actual near-eye render, including bloom/screenshot passes. */
export function withLocalAvatarHidden(game, render) {
  if (!game._nativeFirstPersonPass && game.cam?.mode === 'first-person' && !game.gm?.freecam?.on && game.player?.instance && game.player?.model?.instantiate) {
    return withLocalAvatarBody(game, () => { game._nativeFirstPersonPass = true; try { return withLocalAvatarHidden(game, render); } finally { delete game._nativeFirstPersonPass; } });
  }
  if (game.cam?.mode !== 'first-person') { suspendFirstPersonBody(game); scheduleFirstPersonPrewarm(game); }
  const group = game.cam?.mode === 'first-person' && !game.gm?.freecam?.on ? game.player?.group : null;
  if (!group) return render();
  const hidden=new Map(),hide=object=>{if(object&&!hidden.has(object)){hidden.set(object,object.visible);object.visible=false;}};
  const localWing=object=>{let wing=false;for(let node=object;node;node=node.parent){if(node===group)return wing;wing ||= !!node.userData?.mountsWing;}return false;};
  const restoreBuffShells=game._nativeFirstPersonPass ? () => {} : exposeLocalBuffShells(game);
  const restoreMount=exposeLocalNativeMount(game);
  hide(group);
  for(const fx of new Set([game.effects,game.items?.authoredEffects?.fx])){
    if(!fx)continue;
    for(const play of fx.active||[])if(localWing(play.owner?.group))for(const control of play.controls||[]){hide(control.anchor);hide(control.unit?.object);}
    fx.root?.traverse(object=>{const uuid=object.userData?.wingOwnerRoot;if(uuid&&localWing(group.getObjectByProperty('uuid',uuid)))hide(object);});
  }
  try { return render(); } finally { restoreMount(); restoreBuffShells(); for(const [object,visible]of hidden)object.visible=visible; }
}
