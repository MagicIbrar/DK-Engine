// Loot integration of the items system (game.loot, src/game/loot.js stays the drop-table roller):
//  * every item drop becomes a real instance when it hits the ground (grade -> rank options, socket roll)
//  * drops show the item's field model (items-visual.json shapes[shape].field | game, drop.pos/scale/rot) and dil
//    piles show money_shape.csv piles (5 sizes), with the name above in the grade colour
//  * picking up goes into the bag (w x h placement, stacking); the old loot.addItem/canFit/useItem/itemCooldown/
//    stackMax calls are routed to the items system so every older caller keeps working
import * as THREE from 'three';
import { GRADE_COLOR } from './tooltip.js';
import {dilPickupText} from '../hud-options/chat-notice-colors.js';
import { warmDropModel } from '../../engine/shader-prewarm.js';

const DIL_THRESH = [100, 1000, 10000, 100000];

// Ground size of a dropped item (vouchers and potions were ~50x taller than a player).
// Inventory models are authored at 64 units per bag cell (icons.js); world meshes (equipped armour / weapons, dil
// piles) are in metres. An inventory model is shown at INV_CELL_M metres per cell, and every drop is clamped so its
// longest side stays between MIN_LEN and MAX_LEN metres (a 1x1 potion ~0.4 m, a great sword ~1.4 m).
const INV_UNITS_PER_CELL = 64;
const INV_CELL_M = 0.4;
const MIN_LEN = 0.22, MAX_LEN = 1.4;

/** Scale factor for a model whose longest side is maxDim (model units). */
export function groundScale(maxDim, dropScale = 1) {
  if (!(maxDim > 0)) return 1;
  let k = (maxDim > 8 ? INV_CELL_M / INV_UNITS_PER_CELL : 1) * (Number(dropScale) > 0 ? Number(dropScale) : 1);
  const len = maxDim * k;
  if (len > MAX_LEN) k *= MAX_LEN / len;
  else if (len < MIN_LEN) k *= MIN_LEN / len;
  return k;
}

/**
 * The model of a drop, centred on its bounds, turned by drop.rot ([axis, degrees] of item_shape.csv), scaled by
 * groundScale and set down on the ground. Returns {pivot, top (height of its top above the ground)} or null.
 */
function placeOnGround(model, d) {
  const obj = model.instantiate();
  obj.updateMatrixWorld(true);
  const box = new THREE.Box3().setFromObject(obj);
  if (box.isEmpty()) return null;
  const size = box.getSize(new THREE.Vector3()), c = box.getCenter(new THREE.Vector3());
  obj.position.sub(c);
  const pivot = new THREE.Group();
  pivot.name = 'drop-model';
  pivot.add(obj);
  const rot = d.rot || ['y', 0];
  const ang = (Number(rot[1]) || 0) * Math.PI / 180;
  const ax = String(rot[0] || 'y').toLowerCase();
  if (ax === 'x') pivot.rotation.x = ang; else if (ax === 'z') pivot.rotation.z = ang; else pivot.rotation.y = ang;
  pivot.scale.setScalar(groundScale(Math.max(size.x, size.y, size.z), d.scale));
  pivot.updateMatrixWorld(true);
  const b = new THREE.Box3().setFromObject(pivot);
  pivot.position.y = -b.min.y + 0.02;
  return { pivot, top: b.max.y - b.min.y + 0.02 };
}

// A kill-all snapshot with 300-700 new drops built every name label (a canvas,
// font measure, stroke + fill, texture) in the frame that received it (80-95 ms in onsnapshot, 150-255 ms frames). Two changes, the pixels are the same:
//  * a label canvas is drawn once per (colour, text) and shared by the textures of equal labels (nobody writes to it after the draw; the cache is bounded);
//  * the labels of a burst are built at most LABEL_BUDGET_MS per frame, in the order the drops arrived; the first ones of a frame are built at once, as
//    before, so a normal kill (1-5 drops) is unchanged. The drop itself (its marker group, model, pick-up) never waits for its label.
// Kill switch: globalThis.__dekaronNoDropLabelSpread = true (set before the world loads) gives the old behaviour exactly.
const LABEL_BUDGET_MS = 3;        // per frame at a normal frame rate ...
const LABEL_BUDGET_MAX_MS = 8;    // ... up to this when frames are long (10 % of the time since the last frame), so a burst is done within about a second at any frame rate
const LABEL_CACHE_MAX = 256;
const labelCanvases = new Map();
const labelJobs = { queue: [], head: 0, spent: 0, budget: LABEL_BUDGET_MS, lastPump: 0, timer: 0 };
const labelSpreadOff = () => globalThis.__dekaronNoDropLabelSpread === true;
const labelNow = () => (typeof performance !== 'undefined' && performance.now ? performance.now() : Date.now());

/** Run queued label jobs until `budgetMs` is used (at least one job); returns the time spent. */
export function runLabelJobs(budgetMs = LABEL_BUDGET_MS) {
  const J = labelJobs, t0 = labelNow();
  while (J.head < J.queue.length) {
    const job = J.queue[J.head]; J.queue[J.head++] = null;
    try { job(); } catch { /* a label is cosmetic: the drop stays pick-able */ }
    if (labelNow() - t0 >= budgetMs) break;
  }
  if (J.head >= J.queue.length) { J.queue.length = 0; J.head = 0; }
  return labelNow() - t0;
}
/** Once per frame (the items system's update): the new frame's budget starts, queued labels go first. */
export function pumpDropLabels() {
  const J = labelJobs, now = labelNow();
  J.budget = Math.min(LABEL_BUDGET_MAX_MS, Math.max(LABEL_BUDGET_MS, (J.lastPump ? now - J.lastPump : 0) * 0.1));
  J.lastPump = now;
  J.spent = J.head < J.queue.length ? runLabelJobs(J.budget) : 0;
}
export function pendingDropLabels() { return labelJobs.queue.length - labelJobs.head; }
// the frame loop is not running (hidden page, paused update): do not leave labels unbuilt for ever
function armLabelGuard() {
  const J = labelJobs;
  if (J.timer || typeof setTimeout === 'undefined') return;
  J.timer = setTimeout(() => { J.timer = 0; if (J.head >= J.queue.length) return; if (labelNow() - J.lastPump > 250) J.spent = runLabelJobs(LABEL_BUDGET_MAX_MS); armLabelGuard(); }, 100);
}
/** Build a drop's label now when this frame still has budget and nothing waits, else later (same order). */
function scheduleLabel(build) {
  const J = labelJobs;
  if (labelSpreadOff() || (J.head >= J.queue.length && J.spent < J.budget)) {
    const t0 = labelNow();
    build(false);
    J.spent += labelNow() - t0;
    return;
  }
  J.queue.push(() => build(true));
  armLabelGuard();
}

function labelCanvas(text, color) {
  const key = `${color}|${text}`, cached = labelSpreadOff() ? null : labelCanvases.get(key);
  if (cached) return cached;
  const c = document.createElement('canvas');
  const ctx = c.getContext('2d');
  const font = 'bold 26px Tahoma, "Segoe UI", sans-serif';
  ctx.font = font;
  c.width = Math.min(1024, Math.ceil(ctx.measureText(text).width) + 16); c.height = 36;
  ctx.font = font; ctx.textAlign = 'center'; ctx.textBaseline = 'middle';
  ctx.lineWidth = 4; ctx.strokeStyle = 'rgba(0,0,0,0.9)'; ctx.strokeText(text, c.width / 2, 19);
  ctx.fillStyle = color; ctx.fillText(text, c.width / 2, 19);
  if (!labelSpreadOff()) {
    if (labelCanvases.size >= LABEL_CACHE_MAX) labelCanvases.delete(labelCanvases.keys().next().value);
    labelCanvases.set(key, c);
  }
  return c;
}

function labelSprite(text, color) {
  if (typeof document === 'undefined') return null;
  const c = labelCanvas(text, color);
  const tex = new THREE.CanvasTexture(c);
  tex.colorSpace = THREE.NoColorSpace;
  const s = new THREE.Sprite(new THREE.SpriteMaterial({ map: tex, transparent: true, depthWrite: false, depthTest: false }));
  const h = 0.3;
  s.scale.set((h * c.width) / c.height, h, 1);
  s.renderOrder = 20;
  s.userData.ownMaterial = true;
  return s;
}

export function installGround(sys) {
  const g = sys.game, loot = g.loot;
  if (!loot || loot._itemsPatched) return;
  loot._itemsPatched = true;
  const db = sys.db;

  // ---- compat routes
  loot.addItem = (e) => {
    const inst = e.inst || sys.create(e.itemIndex, { count: e.count || 1, grade: e.grade, roll: false });
    if (!inst) return null;
    const r = sys.add(inst, { source: 'loot' });
    return r.placed[r.placed.length - 1] || null;
  };
  loot.canFit = (e) => sys.bag.canAdd(e.inst || e.itemIndex, e.inst ? null : e.count || 1);
  loot.useItem = (ref) => sys.useRef(ref);
  loot.itemCooldown = (itemIndex) => sys.uses.cooldownLeft(itemIndex);
  loot.stackMax = (itemIndex) => db.stackSize(db.def(itemIndex));

  // ---- real instances on the ground
  const spawn = loot.spawnDrop.bind(loot);
  loot.spawnDrop = (entry, x, z) => {
    if (entry.kind === 'item' && !entry.inst) {
      const inst = sys.create(entry.itemIndex, { count: entry.count || 1, grade: entry.grade, roll: true });
      if (inst) { entry.inst = inst; entry.name = inst.name; }
    }
    return spawn(entry, x, z);
  };
  const pickup = loot.pickup.bind(loot);
  loot.pickup = (drop) => {
    if (drop?.entry?.kind === 'dil') {
      const cap = 10_000_000_000;
      if ((Number(g.save.dil) || 0) + drop.entry.amount > cap) { sys.msg(40, 87); return false; }
    }
    const ok = pickup(drop);
    if (ok && drop.entry.kind === 'dil') { g.events.emit('dil', { amount: drop.entry.amount, total: g.save.dil }); g.hud?.log?.(dilPickupText(sys.str(40, 83) || 'Acquired DIL: [ %lld DIL].', drop.entry.amount), 'item'); }
    else if (ok) sys.changed('pickup');
    return ok;
  };

  // ---- visuals
  loot._makeMarker = (drop) => {
    const root = g.worldRoot;
    if (!root) return null;
    const e = drop.entry;
    const group = new THREE.Group();
    group.name = `drop:${drop.label}`;
    group.position.set(drop.x, drop.y, drop.z);
    group.userData.drop = drop;
    let vis = null, color = '#ffffff', text = drop.label;
    if (e.kind === 'dil') {
      const k = DIL_THRESH.findIndex(t => e.amount < t);
      vis = db.visual?.money?.[k < 0 ? 4 : k];
      if (vis) vis = { model: vis.field, drop: vis.drop };
      color = '#ffcf40';
    } else {
      const def = db.def(e.itemIndex);
      const sh = db.shape(def);
      // item_shape.csv has no field mesh for any item (the column is empty in all 9,545 rows): equipment lies on the
      // ground as its equipped mesh (world scale), everything else as its inventory model (64 units per bag cell,
      // scaled down by groundScale below). Items without a shape use property/item/noitem.txt.
      const m = sh?.field?.mesh ? sh.field : def?.slot && sh?.game?.mesh ? sh.game : sh?.inv?.mesh ? sh.inv : sh?.game?.mesh ? sh.game : null;
      const ni = db.visual?.noItem;
      const fallback = ni?.field || ni?.game || ni?.inv || (ni?.mesh ? ni : null);
      if (m?.mesh) vis = { model: m, drop: sh.drop || { pos: sh.fieldPos, rot: sh.fieldRot, scale: 1 }, twoSide: sh.fieldTwoSide ?? sh.invTwoSide };
      else if (fallback?.mesh) vis = { model: fallback, drop: {}, twoSide: true };
      color = GRADE_COLOR[e.inst?.grade || e.grade] || (def ? `#${String(db.tooltipLayout(def)?.color || 'ffffff').slice(-6)}` : '#ffffff');
      text = e.inst && e.inst.count > 1 ? `${def?.name || e.name} x${e.inst.count}` : def?.name || e.name;
    }
    drop.labelText = text; drop.labelColor = color;   // what the label shows (the Alt drop-names key, hud-options/dropnames.js, shows the same text and colour)
    let label = null, labelY = 0.9;
    scheduleLabel(deferred => {
      if (deferred && drop.object !== group) return;   // picked up / removed / re-skinned while it waited: nothing to build
      label = labelSprite(text, color);
      if (!label) return;
      label.position.y = labelY; group.add(label); drop.labelSprite = label;
      if (deferred && group.children.length > 1) group.children.unshift(group.children.pop());   // first child, as when it is built at once
    });
    if (vis?.model?.mesh && g.models) {
      // transparent: partial-alpha item textures (potion glass) blend like itemmesh.fx; 1-bit alpha stays cut out.
      g.models.loadStatic(vis.model.mesh, { tpackKey: vis.model.tpack || null, textures: vis.model.textures || null, twoSide: vis.twoSide !== false, transparent: true }).then(async model => {
        // 2.2.1: the first drop of a model kind used to build up to seven shader programs in the frame that first drew it (226-234 ms frames): compile and
        // draw them once, hidden, before the model is put down (engine/shader-prewarm.js; later drops of the kind resolve at once, at most 220 ms; kill switch globalThis.__dekaronNoPrewarm)
        if (model && drop.object) await warmDropModel(g, model).catch(() => false);
        if (!model || !drop.object) return;
        const placed = placeOnGround(model, vis.drop || {});
        if (!placed) return;
        placed.pivot.traverse(o => { if (o.isMesh) { o.castShadow = true; o.userData.shared = true; } });
        group.add(placed.pivot);
        drop.model = placed.pivot;
        labelY = Math.max(0.55, placed.top + 0.3);
        if (label) label.position.y = labelY;
      }).catch(() => {});
    }
    root.add(group);
    return group;
  };
  loot._removeDrop = (drop) => {
    const i = loot.drops.indexOf(drop);
    if (i >= 0) loot.drops.splice(i, 1);
    const o = drop.object;
    if (o) {
      o.parent?.remove(o);
      o.traverse(n => { if (n.userData?.ownMaterial && n.material) { n.material.map?.dispose(); n.material.dispose(); } });
      drop.object = null;
    }
  };
  // blink before vanishing (loot.update only animates its old gem markers)
  const upd = loot.update.bind(loot);
  // This frame's share of the queued drop labels. The items system's update runs every frame in solo and online play
  // (updateSystems); loot.update does not run when the server owns the save (game.js: save.authority === 'server').
  if (typeof sys.update === 'function' && !sys._dropLabelPump) {
    sys._dropLabelPump = true;
    const sysUpdate = sys.update.bind(sys);
    sys.update = (dt) => { try { pumpDropLabels(); } catch { /* cosmetic */ } return sysUpdate(dt); };
  }
  loot.update = (dt) => {
    upd(dt);
    const now = g.time || 0;
    for (const d of loot.drops) {
      if (!d.object) continue;
      const age = now - d.born;
      d.object.visible = !(age > 170 && Math.floor(now * 4) % 2 === 0);
    }
  };
  // re-skin drops that are already on the ground (none at install time, but keep it safe)
  for (const d of [...loot.drops]) { const o = d.object; if (o) o.parent?.remove(o); d.object = loot._makeMarker(d); }
}

/** Put an instance (or dil) on the ground at the player's feet (discard / drop). */
export function dropToGround(sys, entry) {
  const g = sys.game, p = g.player;
  if (!g.loot || !p) return null;
  const a = Math.random() * Math.PI * 2, r = 0.6 + Math.random() * 0.5;
  return g.loot.spawnDrop(entry, p.x + Math.cos(a) * r, p.z + Math.sin(a) * r);
}
