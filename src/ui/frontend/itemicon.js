import { readRenderTargetPixels } from '../../engine/pixel-pack-readback.js';
// Item "icons" of the original UI: the client draws each item slot with the item's inventory 3D model
// (items-visual.json shapes[shape].inv, docs/formats/items.md §7, ui.md §1), not a 2D sprite. This renders that model
// once into an offscreen target of the shared renderer (orthographic, fitted to the slot, lit from the front) and
// returns an image URL for the slot element. Mirror + colour rules as the world: the model sits in the FILE frame
// under a z-mirrored root, textures are NoColorSpace (TextureCache).
import * as THREE from 'three';
import { WORLD_MIRROR } from '../../engine/space.js';
import { ICON_LIGHT, iconMaterials } from '../../systems/items/preview-materials.js';

const caches = new WeakMap();
const failed = new WeakMap();

/**
 * @param {{renderer:THREE.WebGLRenderer, models:object}} stage  anything with the shared renderer + ModelCache
 * @param {{mesh:string, tpack?:string, textures?:Array, twoSide?:boolean}} inv
 * @param {number} w  slot width (css px)
 * @param {number} h  slot height (css px)
 * @returns {Promise<string|null>}
 */
export function renderItemIcon(stage, inv, w, h) {
  if (!inv?.mesh || !stage?.renderer || !stage?.models) return Promise.resolve(null);
  let cache = caches.get(stage.renderer), failures = failed.get(stage.renderer);
  if (!cache) { cache = new Map(); failures = new Map(); caches.set(stage.renderer, cache); failed.set(stage.renderer, failures); }
  const key = JSON.stringify([inv.mesh, inv.tpack || null, inv.textures || null, inv.twoSide !== false, inv.scale || 1, Math.round(w), Math.round(h)]);
  const previous = failures.get(key);
  if (previous && previous.count < 3 && performance.now() >= previous.retryAt) { cache.delete(key); failures.delete(key); }
  if (cache.has(key)) return cache.get(key);
  const promise = draw(stage, inv, w, h).catch(error => { console.warn('[itemicon]', inv.mesh, error); return null; }).then(value => {
    if (value) failures.delete(key);
    else failures.set(key, { count: (previous?.count || 0) + 1, retryAt: performance.now() + 1100 * ((previous?.count || 0) + 1) });
    return value;
  });
  cache.set(key, promise); return promise;
}

async function draw(stage, inv, w, h) {
  const model = await stage.models.loadStatic(inv.mesh, { tpackKey: inv.tpack || null, textures: inv.textures || null, twoSide: inv.twoSide !== false });
  if (!model) return null;
  const S = 2;                                   // supersample
  const W = Math.max(8, Math.round(w * S)), H = Math.max(8, Math.round(h * S));
  const scene = new THREE.Scene();
  const root = new THREE.Group();
  root.scale.copy(WORLD_MIRROR);
  scene.add(root);
  const obj = model.instantiate();
  root.add(obj);
  // itemmesh.fx lighting (preview-materials.js ICON_LIGHT): x PI light units + materials clamped to their texture
  iconMaterials(obj);
  scene.add(new THREE.AmbientLight(0xffffff, ICON_LIGHT.ambient));
  const sun = new THREE.DirectionalLight(0xffffff, ICON_LIGHT.key);
  sun.position.set(-0.4, 0.8, 1);
  scene.add(sun);
  // fit the bounding box (THREE space after the mirror) into the slot, keeping the aspect
  root.updateMatrixWorld(true);
  const box = new THREE.Box3().setFromObject(root);
  if (box.isEmpty()) { obj.userData.wingMotion?.dispose(); return null; }
  const c = box.getCenter(new THREE.Vector3()), sz = box.getSize(new THREE.Vector3());
  const aspect = W / H;
  let halfH = Math.max(sz.y / 2, sz.x / 2 / aspect) * 1.08;
  const halfW = halfH * aspect;
  const cam = new THREE.OrthographicCamera(-halfW, halfW, halfH, -halfH, 0.01, 1000);
  cam.position.set(c.x, c.y, c.z + Math.max(sz.z, 1) * 4 + 5);
  cam.lookAt(c);
  const r = stage.renderer;
  const rt = new THREE.WebGLRenderTarget(W, H, { depthBuffer: true });
  const prevTarget = r.getRenderTarget();
  const prevColor = r.getClearColor(new THREE.Color());
  const prevAlpha = r.getClearAlpha();
  const pixels = new Uint8Array(W * H * 4);
  try {
    r.setRenderTarget(rt);
    r.setClearColor(0x000000, 0);
    r.clear(true, true, true);
    r.render(scene, cam);
    readRenderTargetPixels(r, rt, 0, 0, W, H, pixels);
  } finally {
    r.setRenderTarget(prevTarget);
    r.setClearColor(prevColor, prevAlpha);
    rt.dispose();
    obj.userData.wingMotion?.dispose();
  }
  const cv = document.createElement('canvas');
  cv.width = W; cv.height = H;
  const g = cv.getContext('2d');
  const img = g.createImageData(W, H);
  for (let y = 0; y < H; y++) img.data.set(pixels.subarray((H - 1 - y) * W * 4, (H - y) * W * 4), y * W * 4);   // GL rows are bottom-up
  g.putImageData(img, 0, 0);
  return cv.toDataURL('image/png');
}
