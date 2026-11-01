// FILE frame (Dekaron/D3D: X = column, Z = row, Y up) <-> three.js world space.
// Everything in the world is parented under a mirror root (scale z = -1), so gameplay code
// never negates Z; only the camera/lights (outside the mirror) need these conversions.
import * as THREE from 'three';

export const WORLD_MIRROR = new THREE.Vector3(1, 1, -1);

export function fileToThree(x, y, z, out = new THREE.Vector3()) { return out.set(x, y, -z); }
export function threeToFile(v) { return { x: v.x, y: v.y, z: -v.z }; }

/** Yaw (rotation.y under the mirror root) that makes a model face FILE direction (dx, dz). */
export function yawTowards(dx, dz) { return Math.atan2(-dx, -dz); }

/** Facing vector (FILE frame) of a model with rotation.y = yaw. */
export function facingOf(yaw) { return { x: -Math.sin(yaw), z: -Math.cos(yaw) }; }

export function dist2D(ax, az, bx, bz) { return Math.hypot(ax - bx, az - bz); }
