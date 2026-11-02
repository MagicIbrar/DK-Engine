// Login-hall props for the login dance: the throne seat (from the hall's own MAL_Login_Sit .mol placement), hiding the
// hall's seated Alokes figure so the player's character takes the throne, and the glowing purple path down the carpet.
import * as THREE from 'three';
import { THRONE } from '../login.js';

/** Default seat (FILE frame); refined from the .mol placement by hideHallFigure(): x/y/z + scale + figureYaw from the
 *  MAL_Login_Sit matrix (255.847, 19.03, 271.63, scale 1.36, yaw 0). yaw = the character's standing facing (towards the
 *  login camera), which is PI for the Player rig while the sit clip's own Bip01 track supplies the figure's facing. */
export const CHAIR = { x: THRONE.x, z: THRONE.z, yaw: Math.PI };

const FIG = /mal_login_sit/i;

/** Hide the seated hall figure (all its rigs) and read its placement into CHAIR. Returns the object group or null. */
export function hideHallFigure(world, stage = null) {
  const layer = world?.objects;
  const g = layer?.groups?.find(x => FIG.test(x.name));
  if (!g) return null;
  if (g.mats?.length >= 16) {
    const m = new THREE.Matrix4().fromArray(g.mats, 0), p = new THREE.Vector3(), qq = new THREE.Quaternion(), s = new THREE.Vector3();
    m.decompose(p, qq, s);
    const fwd = new THREE.Vector3(0, 0, 1).applyQuaternion(qq);
    CHAIR.x = p.x; CHAIR.z = p.z; CHAIR.y = p.y; CHAIR.scale = s.x;
    CHAIR.figureYaw = Math.atan2(fwd.x, fwd.z);
  }
  // the object layer owns visibility / counts / matrices; moving the meshes to an unused render layer is what sticks
  const hide = () => { const o = g.inst?.object; if (o) o.traverse(c => { if (c.layers.mask !== 1 << 30) c.layers.set(30); }); };
  hide();
  g._danceHide = hide;
  g._danceOff = stage?.onFrame(hide);
  return g;
}

/** A soft purple glowing strip from the throne down the carpet to the dance mark (+ a ring on the mark). */
export function addPurplePath(stage, { chair = CHAIR, length = 2.6, width = 0.9, y = null } = {}) {
  const root = stage.world?.root || stage.scene;
  const floorY = y ?? (Number.isFinite(chair.y) ? chair.y : 19.03);    // (heightAt hits the hall's ceiling 'ground' mesh)
  const grp = new THREE.Group(); grp.name = 'dance:purple-path';
  const c = document.createElement('canvas'); c.width = 64; c.height = 256;
  const x = c.getContext('2d');
  const gr = x.createLinearGradient(0, 0, 64, 0);
  gr.addColorStop(0, 'rgba(150,60,255,0)'); gr.addColorStop(0.3, 'rgba(170,90,255,0.55)'); gr.addColorStop(0.5, 'rgba(215,160,255,0.9)');
  gr.addColorStop(0.7, 'rgba(170,90,255,0.55)'); gr.addColorStop(1, 'rgba(150,60,255,0)');
  x.fillStyle = gr; x.fillRect(0, 0, 64, 256);
  const tex = new THREE.CanvasTexture(c); tex.colorSpace = THREE.SRGBColorSpace;
  const mat = new THREE.MeshBasicMaterial({ map: tex, transparent: true, depthWrite: false, blending: THREE.AdditiveBlending, side: THREE.DoubleSide, toneMapped: false });
  const strip = new THREE.Mesh(new THREE.PlaneGeometry(width, length + 0.6), mat);
  const dx = Math.sin(chair.yaw), dz = Math.cos(chair.yaw);
  strip.rotation.set(-Math.PI / 2, 0, chair.yaw + Math.PI, 'YXZ');
  strip.rotation.order = 'YXZ'; strip.rotation.y = chair.yaw; strip.rotation.z = 0;
  strip.position.set(chair.x + dx * (length / 2 + 0.2), floorY + 0.03, chair.z + dz * (length / 2 + 0.2));
  grp.add(strip);
  const ring = new THREE.Mesh(new THREE.RingGeometry(0.45, 0.62, 48), new THREE.MeshBasicMaterial({ color: 0xb070ff, transparent: true, opacity: 0.8, depthWrite: false, blending: THREE.AdditiveBlending, side: THREE.DoubleSide, toneMapped: false }));
  ring.rotation.x = -Math.PI / 2;
  ring.position.set(chair.x + dx * length, floorY + 0.035, chair.z + dz * length);
  grp.add(ring);
  root.add(grp);
  let t = 0;
  grp.userData.off = stage.onFrame(dt => { t += dt || 0; mat.opacity = 0.75 + 0.25 * Math.sin(t * 2.2); ring.scale.setScalar(1 + 0.05 * Math.sin(t * 4.4)); });
  return grp;
}
