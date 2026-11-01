// script/producer/char_selectinfo.txt: how the client stages a character in its class-select map - the scene of the
// character-select screen (the selected character) and of the character-create screen (the chosen class).
// One block per class index:
//
//   stand          <cls> <sec>        length of the class-select STAND motion (classes.json anims.createPose)
//   stand_special  <cls> <sec>        (2.7 for all; kept raw)
//   mapindex       <cls> <map>        maplist index of the class-select map (100 Knight ... 113)
//   scale          <cls> <s>          model scale in the scene (1.1 .. 1.4)
//   horizon        <cls> <rad>        camera yaw: look direction = (-sin h, 0, cos h) in the FILE frame
//   vertical       <cls> <rad>        camera pitch (small; positive looks up)
//   cameratarget   <cls> <x> <y> <z>  camera EYE position (FILE frame, absolute height)
//   position       <cls> <x> <z>      where the character stands (FILE frame)
//   direction      <cls> <deg>        character facing: FILE direction (sin d, 0, -cos d)  ->  rotation.y = -d
//
// Verified against the eight maps: the eye lies 7-8 m in front of `position`, `horizon` points it at the character,
// and `direction` turns the character towards the camera (e.g. class 5: eye at x 92.1, character at x 98.0,
// direction -81.8 deg -> faces -X). The file has one typo key ("vertical7"), read as "vertical".
//
// script/producer/char_previewinfo.txt: the close-up of the create screen's "Preview" tab, per class:
//   target_x         camera distance from the character (negative = in front; 2.65 .. 4.8, the 1540 mount 7.0)
//   target_y         look-at height (0.84 .. 1.5, the mount 2.0)      target_z   small sideways shift
//   target_height    eye height (1.2 for all)                         target_rotate  character turn (deg, 90 = facing
//   the camera: 70..100 = a three-quarter view)                        target_style 1 = battle stance (weapon drawn)
//   The pairs grow with the creature's size, which is how the fields were identified.
import { fetchText } from '../../engine/assets.js';

export const SELECTINFO_KEY = 'script/producer/char_selectinfo.txt';
export const PREVIEWINFO_KEY = 'script/producer/char_previewinfo.txt';

/** Parse the text -> Map<classIndex, {stand, standSpecial, mapIndex, scale, horizon, vertical, eye:{x,y,z}, x, z, direction}> */
export function parseSelectInfo(text) {
  const out = new Map();
  for (const raw of String(text || '').split(/\r?\n/)) {
    const t = raw.trim().split(/\s+/);
    if (t.length < 3) continue;
    const key = t[0].toLowerCase().replace(/\d+$/, '');
    const cls = Number(t[1]);
    if (!Number.isFinite(cls)) continue;
    const v = t.slice(2).map(Number);
    const e = out.get(cls) || { classIndex: cls };
    switch (key) {
      case 'stand': e.stand = v[0]; break;
      case 'stand_special': e.standSpecial = v[0]; break;
      case 'mapindex': e.mapIndex = v[0]; break;
      case 'scale': e.scale = v[0]; break;
      case 'horizon': e.horizon = v[0]; break;
      case 'vertical': e.vertical = v[0]; break;
      case 'cameratarget': e.eye = { x: v[0], y: v[1], z: v[2] }; break;
      case 'position': e.x = v[0]; e.z = v[1]; break;
      case 'direction': e.direction = v[0]; break;
      case 'target_height': e.targetHeight = v[0]; break;
      case 'target_x': e.targetX = v[0]; break;
      case 'target_y': e.targetY = v[0]; break;
      case 'target_z': e.targetZ = v[0]; break;
      case 'target_rotate': e.targetRotate = v[0]; break;
      case 'target_style': e.targetStyle = v[0]; break;
      default: continue;
    }
    out.set(cls, e);
  }
  return out;
}

let cache = null;
/** Load once; resolves an empty Map when the file is unavailable. */
export function loadSelectInfo() {
  if (!cache) cache = fetchText(SELECTINFO_KEY).then(parseSelectInfo).catch(() => new Map());
  return cache;
}

let pcache = null;
/** char_previewinfo.txt (same format, target_* keys). */
export function loadPreviewInfo() {
  if (!pcache) pcache = fetchText(PREVIEWINFO_KEY).then(parseSelectInfo).catch(() => new Map());
  return pcache;
}

/** Character yaw (rotation.y under the mirror root) from a selectinfo direction in degrees. */
export function selectYaw(directionDeg) {
  return (-(Number(directionDeg) || 0) * Math.PI) / 180;
}

/** Camera look direction (FILE frame unit vector) from horizon / vertical. */
export function selectLookDir(horizon = 0, vertical = 0) {
  const cp = Math.cos(vertical);
  return { x: -Math.sin(horizon) * cp, y: Math.sin(vertical), z: Math.cos(horizon) * cp };
}

/**
 * The class-select camera {eye, target, fov} of a selectinfo entry (target 10 m along the look direction).
 * One entry is inconsistent in the file: the Segita Hunter / Shooter block (classes 1 and 8, map 101) repeats the
 * Knight's angles (horizon 0.01, direction 360.42) although its character stands 7 m on the -Z side of the eye, so
 * the camera would look away and the character would show its back. When the look direction points away from the
 * character (or the character faces away from the camera) the angle is turned by 180 deg - a no-op for every other class.
 */
export function selectView(si, fov = 37.24) {
  let h = Number(si.horizon) || 0;
  const to = { x: si.x - si.eye.x, z: si.z - si.eye.z };
  const d0 = selectLookDir(h, 0);
  if (Number.isFinite(to.x) && d0.x * to.x + d0.z * to.z < 0) h += Math.PI;
  const d = selectLookDir(h, si.vertical);
  return { eye: { ...si.eye }, target: { x: si.eye.x + d.x * 10, y: si.eye.y + d.y * 10, z: si.eye.z + d.z * 10 }, fov };
}

/**
 * Keep the staged character in frame: the file's pitch (`vertical`) is kept while the character's feet and head both
 * fit between the letterbox bars; otherwise the camera tilts (from the same eye) just enough to show the head, or
 * centres on the body when it cannot show both. The file stages several classes with the eye at their feet level
 * (Bagi 0.56 m, Aloken 0.31 m, Summoner 0.11 m above the stand) for a low heroic angle, where a 1.2x model's head
 * would leave the frame.
 * @param {{eye, target, fov}} view   selectView() result (FILE frame)
 * @param {{x:number, z:number, feet:number, head:number}} body
 * @param {number} margin   fraction of the half FOV kept free (letterbox bars 80 of 768 px)
 */
export function fitView(view, body, margin = 0.8) {
  const e = view.eye, t = view.target;
  const dx = t.x - e.x, dz = t.z - e.z;
  const hl = Math.hypot(dx, dz) || 1;
  let pitch = Math.atan2(t.y - e.y, hl);
  const d = Math.max(0.5, Math.hypot(body.x - e.x, body.z - e.z));
  const aFeet = Math.atan2(body.feet - e.y, d), aHead = Math.atan2(body.head - e.y, d);
  const half = ((view.fov * Math.PI) / 360) * margin;
  if (aHead - aFeet > 2 * half) pitch = aHead - half;                 // cannot show both: keep the head in
  else if (aHead > pitch + half) pitch = aHead - half;
  else if (aFeet < pitch - half) pitch = aFeet + half;
  const ux = dx / hl, uz = dz / hl, c = Math.cos(pitch);
  return { ...view, target: { x: e.x + ux * c * 10, y: e.y + Math.sin(pitch) * 10, z: e.z + uz * c * 10 } };
}

/** The front-end windows' letterbox bars (ui_charselectwnd / ui_classselectwnd: 48 + 32 px of 768, top and bottom). */
export const LETTERBOX = 80 / 768;
/** Share of the picture between the bars the staged body (helmet and weapon included) may fill: head and foot room. */
export const FRAME_FILL = 0.8;
/** 768-px window row -> NDC y (the windows scale uniformly with the height, so this holds at 16:9 and 4:3). */
const rowNdc = px => 1 - (2 * px) / 768;
/**
 * The picture band the body stands in (NDC y [low, high]) between the screen's own windows, as the original frames it:
 *  create: below the class title plate (pan_class_title 143 + 43 = 186 px) and above the name box (pan_character_name,
 *          drawn from 590 px): a 2.4 m class at the file's 7.2 m spans ~380 of these 404 px, as in the client;
 *  select: below the name plate (pan_select_char 60 + 86 = 146 px) and above the rotate / Connect bar (pan_connect,
 *          bottom-aligned at -160: 567 px).
 */
export const CREATE_BAND = [rowNdc(590), rowNdc(186)];
export const SELECT_BAND = [rowNdc(567), rowNdc(146)];
/** Free space kept between the body and the band's edges (NDC; 0.04 = 15 of 768 px). */
export const BAND_MARGIN = 0.04;

/** maplist Camera_Height of a scene map row (1.3 m on the class-select maps, 1.0 on the Hunter / Bagi maps). */
export function rowCamHeight(row, fallback = 1.3) {
  const h = Number(row?.Camera_Height);
  return h > 0 && h < 5 ? h : fallback;
}

/**
 * The select / create camera, framed like the original client:
 *  - char_selectinfo `cameratarget` is the camera's ANCHOR, not its eye: for every class it lies on the stage floor
 *    (0.06 .. 0.56 m above the surface the character stands on; 0.12 m below it for the Magician map), and the client
 *    raises it by the map's maplist Camera_Height as it does in the world (camera.js) -> a chest-high eye.
 *  - it looks from there at the character (horizon: the flip of classes 1 / 8 is implied) with the file's pitch
 *    (`vertical`), turned just enough that the whole body - measured from the posed model, helmet and weapon
 *    included - stands inside `band` (the picture between the screen's title / name plate and its bottom controls,
 *    CREATE_BAND / SELECT_BAND; by default FRAME_FILL of the picture between the letterbox bars) with BAND_MARGIN of
 *    head and foot room, centred in it horizontally.
 *  - a body too tall for the file's distance (the 1.2x Bagi is 3.3 m tall at 5.9 m) backs the eye off along the same
 *    line until it fits (at most `maxBack` m); beyond that the feet stay on the band's lower edge.
 * The vertical FOV is fixed and the windows scale with the height, so the framing is the same at 16:9 and 4:3.
 * @param {object} si     selectinfo entry
 * @param {{x:number, z:number, bottom:number, top:number}} body   FILE frame bounds of the staged model
 * @param {number} fov    vertical FOV (degrees)
 * @param {number} camHeight  maplist Camera_Height of the scene map
 * @returns {{eye, target, fov}}
 */
export function frameView(si, body, fov = 37.24, camHeight = 1.3, {
  band = null, margin = BAND_MARGIN, maxBack = 6,
} = {}) {
  const tanHalf = Math.tan((fov * Math.PI) / 360);
  const lim = FRAME_FILL * (1 - 2 * LETTERBOX);
  const [b0, b1] = Array.isArray(band) ? band : [-lim, lim];
  const lo = Math.min(b0, b1) + margin, hi = Math.max(lo + 0.2, Math.max(b0, b1) - margin);
  const aLo = Math.atan(lo * tanHalf), aHi = Math.atan(hi * tanHalf);   // band edges as angles off the optical axis
  let ux = body.x - si.eye.x, uz = body.z - si.eye.z;
  let d0 = Math.hypot(ux, uz);
  if (!(d0 > 0.3)) {                                           // degenerate entry: the file's own look direction
    const v = selectView(si, fov);
    ux = v.target.x - v.eye.x; uz = v.target.z - v.eye.z;
    const l = Math.hypot(ux, uz) || 1;
    ux /= l; uz /= l; d0 = 7;
  } else { ux /= d0; uz /= d0; }
  const bottom = Number(body.bottom), top = Math.max(bottom + 0.3, Number(body.top));
  const H = top - bottom;
  const need = H / ((hi - lo) * tanHalf);                      // distance at which the body spans the band
  const d = Math.min(d0 + maxBack, Math.max(d0, need * 1.03));
  const eye = { x: body.x - ux * d, y: si.eye.y + camHeight, z: body.z - uz * d };
  const aB = Math.atan2(bottom - eye.y, d), aT = Math.atan2(top - eye.y, d);
  // the pitch p must satisfy aT - p <= aHi and aB - p >= aLo: keep the file's pitch when it does, else the nearest.
  // A body still too tall (backing off capped) keeps its feet on the band's lower edge and lets the top (a weapon
  // raised during the STAND motion) run into the title band - never past FRAME_FILL of the letterbox picture.
  const pMin = aT - aHi, pMax = aB - aLo;
  let p = Math.max(-0.2, Math.min(0.2, Number(si.vertical) || 0));
  if (pMin <= pMax) p = Math.max(pMin, Math.min(pMax, p));
  else p = Math.max(pMax, aT - Math.atan(lim * tanHalf));
  const c = Math.cos(p);
  return { eye, target: { x: eye.x + ux * c * 10, y: eye.y + Math.sin(p) * 10, z: eye.z + uz * c * 10 }, fov };
}

/** The character's rotation.y in the class-select scene (selectYaw(direction), turned to the camera if needed). */
export function selectCharYaw(si) {
  let yaw = selectYaw(si.direction);
  const toEye = { x: si.eye.x - si.x, z: si.eye.z - si.z };
  if (-Math.sin(yaw) * toEye.x + -Math.cos(yaw) * toEye.z < 0) yaw += Math.PI;
  return yaw;
}

/**
 * The Preview-tab close-up: camera placed from the character's position along the axis towards the class-select
 * eye (|target_x| m), target_y high, shifted target_z sideways, looking at target_height (scaled with the model);
 * the character turns (target_rotate - 90) deg away from facing the camera, so it is seen three-quarter.
 * @returns {{eye, target, fov, yaw}} yaw = the character's rotation.y
 */
export function previewView(si, pi, ground, scale = 1, fov = 37.24) {
  const toEye = { x: si.eye.x - si.x, z: si.eye.z - si.z };
  const len = Math.hypot(toEye.x, toEye.z) || 1;
  const fx = toEye.x / len, fz = toEye.z / len;          // unit: character -> camera
  const sx = -fz, sz = fx;                                // sideways
  // distance |target_x| and the look-at height target_y grow with the creature (Bagi 4.8 / 1.5, the 1540 mount
  // 7.0 / 2.0), target_height is the eye height; the whole rig scales with the model like the showcase scale
  const dist = Math.abs(Number(pi?.targetX) || 3.5) * scale;
  const h = (Number(pi?.targetHeight) || 1.2) * scale;
  const side = (Number(pi?.targetZ) || 0) * scale;
  const look = (Number(pi?.targetY) || 1.1) * scale;
  const eye = { x: si.x + fx * dist + sx * side, y: ground + h, z: si.z + fz * dist + sz * side };
  const target = { x: si.x + sx * side, y: ground + look, z: si.z + sz * side };
  const face = Math.atan2(-fx, -fz);                      // rotation.y that faces the camera (models face local -Z)
  const yaw = face + (((Number(pi?.targetRotate) || 90) - 90) * Math.PI) / 180;
  return { eye, target, fov, yaw };
}

/** Hunter/Shooter's native camera anchor contradicts its horizon and character
 * direction: it is behind the character and looks away. The supplied Global
 * reference shows the golden hall behind the character, agreeing with horizon
 * and direction. Keep the authored distance/height, on the matching side of the
 * character; do not rotate the whole view toward the empty outside of the hall.
 * Used by both character selection and creation.
 * All other native class anchors already agree and are returned unchanged. */
export function classSceneInfo(si) {
  if (!si?.eye) return si;
  const look = selectLookDir(si.horizon, 0);
  const dx = si.x - si.eye.x, dz = si.z - si.eye.z;
  if (!(Number.isFinite(dx) && Number.isFinite(dz)) || dx * look.x + dz * look.z >= 0) return si;
  return {...si, eye:{...si.eye, x:2*si.x-si.eye.x, z:2*si.z-si.eye.z}};
}

