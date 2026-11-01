// Target ring: the ground marker under the selected actor (Actor.setHighlight).
//
// A small grid-subdivided quad that lies on the ground in the FILE frame (it is a child of game.worldRoot, NOT of the
// actor group, so the actor's yaw/scale never touch it). Its vertex heights are re-sampled from world.heightAt when the
// actor moves, so the ring hugs slopes and steps instead of cutting into them. The texture (a soft double ring with
// four inward ticks, drawn once on a canvas) rotates slowly; the material colour tints the white parts per actor kind.
// Unlit (MeshBasicMaterial), blended, no depth writes, polygon offset against z-fighting.
import * as THREE from 'three';

const SEG = 10;            // grid resolution of the quad (per side)
const LIFT = 0.04;         // metres above the sampled ground
const SPIN = 0.55;         // texture spin (rad/s)

let sharedTexture;         // undefined = not tried yet, null = no canvas available (Node)

function makeCanvas(size) {
  if (typeof OffscreenCanvas !== 'undefined') return new OffscreenCanvas(size, size);
  if (typeof document !== 'undefined' && document.createElement) {
    const c = document.createElement('canvas');
    c.width = c.height = size;
    return c;
  }
  return null;
}

/** The ring texture (white on transparent, dark rims for contrast on bright ground). Shared by every ring. */
export function ringTexture() {
  if (sharedTexture !== undefined) return sharedTexture;
  sharedTexture = null;
  const S = 256;
  const canvas = makeCanvas(S);
  const ctx = canvas?.getContext?.('2d');
  if (!ctx) return null;
  const c = S / 2;
  ctx.clearRect(0, 0, S, S);
  // soft glow band around the main ring
  const g = ctx.createRadialGradient(c, c, S * 0.30, c, c, S * 0.49);
  g.addColorStop(0, 'rgba(255,255,255,0)');
  g.addColorStop(0.5, 'rgba(255,255,255,0.28)');
  g.addColorStop(1, 'rgba(255,255,255,0)');
  ctx.fillStyle = g;
  ctx.beginPath(); ctx.arc(c, c, S * 0.49, 0, Math.PI * 2); ctx.fill();
  const ring = (r, w) => {
    ctx.lineWidth = w + 4; ctx.strokeStyle = 'rgba(0,0,0,0.45)';
    ctx.beginPath(); ctx.arc(c, c, r, 0, Math.PI * 2); ctx.stroke();
    ctx.lineWidth = w; ctx.strokeStyle = 'rgba(255,255,255,0.95)';
    ctx.beginPath(); ctx.arc(c, c, r, 0, Math.PI * 2); ctx.stroke();
  };
  ring(S * 0.40, 5);
  ring(S * 0.31, 2);
  // four ticks pointing inwards (at 45 deg so they read as corners when the camera looks along an axis)
  for (let k = 0; k < 4; k++) {
    const a = Math.PI / 4 + (k * Math.PI) / 2;
    const ca = Math.cos(a), sa = Math.sin(a);
    const tip = S * 0.335, base = S * 0.465, half = S * 0.05;
    ctx.beginPath();
    ctx.moveTo(c + ca * tip, c + sa * tip);
    ctx.lineTo(c + ca * base - sa * half, c + sa * base + ca * half);
    ctx.lineTo(c + ca * base + sa * half, c + sa * base - ca * half);
    ctx.closePath();
    ctx.lineWidth = 3; ctx.strokeStyle = 'rgba(0,0,0,0.5)'; ctx.stroke();
    ctx.fillStyle = 'rgba(255,255,255,0.95)'; ctx.fill();
  }
  const tex = new THREE.CanvasTexture(canvas);
  tex.colorSpace = THREE.NoColorSpace;   // ARCHITECTURE.md §1 colour rule
  tex.flipY = false;
  tex.center.set(0.5, 0.5);
  tex.anisotropy = 4;
  tex.name = 'target-ring';
  sharedTexture = tex;
  return tex;
}

export class TargetRing {
  /**
   * @param {THREE.Object3D} parent  game.worldRoot (FILE frame)
   * @param {number|string|THREE.Color} color
   */
  constructor(parent, color = 0xffd257) {
    const geo = new THREE.PlaneGeometry(1, 1, SEG, SEG);
    geo.rotateX(-Math.PI / 2);                               // lie in the XZ plane (normal +Y)
    this._base = Float32Array.from(geo.attributes.position.array); // unit quad, y = 0
    this.geometry = geo;
    const map = ringTexture();
    this.material = new THREE.MeshBasicMaterial({
      map, color: new THREE.Color(color), transparent: true, opacity: map ? 0.9 : 0.5, depthWrite: false,
      side: THREE.DoubleSide, polygonOffset: true, polygonOffsetFactor: -2, polygonOffsetUnits: -4,
    });
    if (!map) this.material.wireframe = true;                 // Node / no canvas: still something visible
    this.mesh = new THREE.Mesh(geo, this.material);
    this.mesh.name = 'target-ring';
    this.mesh.renderOrder = 3;
    this.mesh.frustumCulled = false;                          // vertices move; the bounding sphere would go stale
    this.mesh.castShadow = false;
    this.mesh.receiveShadow = false;
    this.mesh.visible = false;
    parent?.add(this.mesh);
    this._key = null;
  }

  get visible() { return this.mesh.visible; }
  set visible(v) { this.mesh.visible = !!v; }

  setColor(color) { this.material.color.set(color); }

  /**
   * Place the ring at FILE (x, y, z) with the given outer radius, conforming to heightAt(x, z) when given.
   * @param {number} time  seconds (drives the spin and a gentle pulse)
   */
  update(x, y, z, radius, heightAt, time = 0) {
    const size = Math.max(0.6, radius) * 2;
    this.mesh.position.set(x, y, z);
    const key = `${x.toFixed(2)}|${y.toFixed(2)}|${z.toFixed(2)}|${size.toFixed(2)}`;
    if (key !== this._key) {
      this._key = key;
      const pos = this.geometry.attributes.position;
      const a = pos.array, b = this._base;
      for (let i = 0; i < a.length; i += 3) {
        const lx = b[i] * size, lz = b[i + 2] * size;
        let h = LIFT;
        if (heightAt) {
          const g = heightAt(x + lx, z + lz);
          if (Number.isFinite(g)) h = Math.max(g - y, -1.5) + LIFT;
        }
        a[i] = lx; a[i + 1] = h; a[i + 2] = lz;
      }
      pos.needsUpdate = true;
    }
    if (this.material.map) this.material.map.rotation = time * SPIN;
    this.material.opacity = (this.material.map ? 0.78 : 0.45) + 0.18 * Math.sin(time * 3.2);
  }

  dispose() {
    this.mesh.removeFromParent();
    this.geometry.dispose();
    this.material.dispose();            // the shared texture stays
  }
}
