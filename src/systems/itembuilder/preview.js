// Live 3D preview of the item builder: its own small WebGLRenderer (a canvas inside the builder window) drawing with
// the game's ModelCache / TextureCache, so what it shows is exactly what the game renders (tools/viewer.js setup:
// mirror root, DX9 gamma-space colours, Lambert x PI lights).
//
// Modes:
//   'character'  the class body (classes.json parts) wearing the item through the items system's own Equipment
//                (Equipment.view / weaponView: per-class look, weapon bones of items.json weaponBones battle/peace
//                columns, left/right/both hands, animated weapon skeleton + loop, costume parts) and the stance
//                animation set of the weapon style (items/look.js styledClass): stand battle / stand peace / run /
//                walk / attack, the weapon moving between the hand and the sheath bone like the Player does.
//   'item'       the equipped model alone (weapon mesh, or the armour part on the class skeleton), turning.
//   'icon'       the inventory model (items-visual shapes[].inv = the item's "icon"), turning.
// Drag = rotate, wheel = zoom, double click = reset.
import * as THREE from 'three';
import { WORLD_MIRROR, fileToThree } from '../../engine/space.js';
import { Animator } from '../../engine/animator.js';
import { Equipment } from '../items/equip.js';
import { styledClass } from '../items/look.js';

const normKey = k => String(k || '').trim().replace(/\\/g, '/').replace(/^\/+/, '').toLowerCase();
export const ANIMS = [
  { id: 'idle', text: 'Stand (battle)' },
  { id: 'idlePeace', text: 'Stand (peace)' },
  { id: 'run', text: 'Run' },
  { id: 'walk', text: 'Walk' },
  { id: 'attack0', text: 'Attack 1' },
  { id: 'attack1', text: 'Attack 2' },
  { id: 'attack2', text: 'Attack 3' },
];

export class ItemPreview {
  constructor(game, db) {
    this.game = game;
    this.db = db;
    this.mode = 'character';
    this.classIndex = 0;
    this.anim = 'idle';
    this.itemIndex = null;
    this.spin = true;
    this.view = { yaw: 0.45, pitch: 0.12, zoom: 1 };
    this._token = 0;
    this.cur = null;            // { object, instance, animator, disposers[], box, weaponObjs, stanceBones }
    this.status = '';
    this.onStatus = null;
  }

  // ---------------------------------------------------------------------------------------------- mount
  /** Create the renderer inside `el` (w x h CSS px of the window's reference space). */
  mount(el, w, h) {
    if (this.renderer) return;
    const canvas = document.createElement('canvas');
    canvas.className = 'ib-preview';
    Object.assign(canvas.style, { position: 'absolute', left: '0', top: '0', width: `${w}px`, height: `${h}px`, cursor: 'grab', pointerEvents: 'auto' });
    el.appendChild(canvas);
    this.canvas = canvas;
    const r = new THREE.WebGLRenderer({ canvas, antialias: true, alpha: true, preserveDrawingBuffer: true });
    r.outputColorSpace = THREE.LinearSRGBColorSpace;
    r.toneMapping = THREE.NoToneMapping;
    r.setClearColor(0x000000, 0);
    this.renderer = r;
    this.scene = new THREE.Scene();
    this.camera = new THREE.PerspectiveCamera(32, w / h, 0.02, 500);
    // three.js r155+ Lambert = albedo/PI * irradiance: scale by PI so intensity 1 == D3D "diffuse * light" (viewer.js)
    this.scene.add(new THREE.AmbientLight(0xffffff, 0.6 * Math.PI));
    const sun = new THREE.DirectionalLight(0xffffff, 0.75 * Math.PI);
    fileToThree(-4, 9, -7, sun.position);
    this.scene.add(sun);
    const back = new THREE.DirectionalLight(0x8899bb, 0.25 * Math.PI);
    fileToThree(5, 4, 8, back.position);
    this.scene.add(back);
    this.root = new THREE.Group();
    this.root.scale.copy(WORLD_MIRROR);
    this.scene.add(this.root);
    this.holder = new THREE.Group();
    this.root.add(this.holder);
    // a faint floor ring under the character
    const ring = new THREE.Mesh(new THREE.RingGeometry(0.35, 0.62, 48), new THREE.MeshBasicMaterial({ color: 0x6a5a3a, transparent: true, opacity: 0.35, side: THREE.DoubleSide, depthWrite: false }));
    ring.rotation.x = -Math.PI / 2;
    ring.position.y = 0.005;
    this.ring = ring;
    this.root.add(ring);
    this.size = { w, h };
    this._wireInput(canvas);
    this.resize(w, h);
    this._last = performance.now();
    const loop = () => {
      if (!this.renderer) return;
      this._raf = requestAnimationFrame(loop);
      this._frame();
    };
    this._raf = requestAnimationFrame(loop);
    // background tabs starve rAF: a slow timer keeps automated captures alive
    this._timer = setInterval(() => { if (performance.now() - this._last > 250) this._frame(); }, 60);
  }

  resize(w, h) {
    if (!this.renderer) return;
    this.size = { w, h };
    const scale = Number(this.game.uiwin?.scale) || 1;
    this.renderer.setPixelRatio(Math.min(3, (globalThis.devicePixelRatio || 1) * scale));
    this.renderer.setSize(w, h, false);
    this.canvas.style.width = `${w}px`; this.canvas.style.height = `${h}px`;
    this.camera.aspect = w / Math.max(1, h);
    this.camera.updateProjectionMatrix();
  }

  unmount() {
    clearTimeout(this._deb);
    cancelAnimationFrame(this._raf);
    clearInterval(this._timer);
    this._token++;
    this._clear();
    this.ring?.geometry.dispose();
    this.ring?.material.dispose();
    if (this.renderer) {
      try { this.renderer.dispose(); this.renderer.forceContextLoss(); } catch { /* ignore */ }
    }
    this.canvas?.remove();
    this.renderer = null; this.canvas = null;
  }

  _wireInput(c) {
    let drag = null;
    c.addEventListener('pointerdown', (e) => {
      e.stopPropagation(); e.preventDefault();
      drag = { x: e.clientX, y: e.clientY, yaw: this.view.yaw, pitch: this.view.pitch };
      this.spin = false;
      try { c.setPointerCapture(e.pointerId); } catch { /* ignore */ }
      c.style.cursor = 'grabbing';
    });
    c.addEventListener('pointermove', (e) => {
      if (!drag) return;
      this.view.yaw = drag.yaw + (e.clientX - drag.x) * 0.012;
      this.view.pitch = Math.max(-0.6, Math.min(1.1, drag.pitch + (e.clientY - drag.y) * 0.006));
    });
    const up = (e) => { drag = null; c.style.cursor = 'grab'; try { c.releasePointerCapture(e.pointerId); } catch { /* ignore */ } };
    c.addEventListener('pointerup', up);
    c.addEventListener('pointercancel', up);
    c.addEventListener('mousedown', (e) => e.stopPropagation());
    c.addEventListener('wheel', (e) => { e.preventDefault(); e.stopPropagation(); this.view.zoom = Math.max(0.25, Math.min(3, this.view.zoom * (e.deltaY > 0 ? 1.1 : 1 / 1.1))); }, { passive: false });
    c.addEventListener('dblclick', (e) => { e.stopPropagation(); this.view = { yaw: 0.45, pitch: 0.12, zoom: 1 }; this.spin = true; });
    c.addEventListener('contextmenu', (e) => { e.preventDefault(); e.stopPropagation(); });
  }

  // ---------------------------------------------------------------------------------------------- state
  /** Change what is shown: {mode, classIndex, anim, itemIndex}. Rebuilds (debounced) when needed. */
  set(opts = {}) {
    let rebuild = false;
    for (const k of ['mode', 'classIndex', 'itemIndex']) if (opts[k] !== undefined && opts[k] !== this[k]) { this[k] = opts[k]; rebuild = true; }
    if (opts.force) rebuild = true;
    if (opts.anim !== undefined && opts.anim !== this.anim) { this.anim = opts.anim; if (!rebuild) this._playAnim(); }
    if (rebuild) this.refresh();
  }
  /** Rebuild the model (after the draft item changed). */
  refresh() {
    clearTimeout(this._deb);
    if (!this.renderer) return;
    this._deb = setTimeout(() => {
      const work = this._build(), token = this._token;
      work.catch(err => {
        if (token !== this._token || !this.renderer) return;
        console.warn('[itembuilder] preview', err); this._setStatus(`preview failed: ${err.message || err}`);
      });
    }, 60);
  }
  _setStatus(t) { this.status = t; try { this.onStatus?.(t); } catch { /* ignore */ } }

  classDef(ci) {
    const d = this.game.data;
    const m = d?.classByIndex;
    return (m instanceof Map ? m.get(Number(ci)) : null) || (d?.classes || []).find(c => Number(c.index) === Number(ci)) || null;
  }

  /** The items system's Equipment for class ci wearing only item `index` (the game's own look rules). */
  equipmentFor(ci, index) {
    const db = this.db;
    const def = db.def(index);
    const save = { classIndex: ci, level: 999, equip: { active: 0, presets: [{}, {}, {}, {}, {}], items: {}, locked: false } };
    const E = new Equipment({ db, game: { save, settings: { showCostume: true } } });
    if (def?.slot) {
      const g = db.equipment.slotGroups?.[def.slot] || [];
      const slot = g[0];
      if (slot != null) {
        const inst = { uid: 'ib-preview', itemIndex: Number(index), count: 1, grade: 'normal' };
        save.equip.items[inst.uid] = inst;
        save.equip.presets[0][slot] = inst.uid;
      }
    }
    return E;
  }

  _clear() {
    const c = this.cur;
    this.cur = null;
    if (!c) return;
    try { c.animator?.dispose(); } catch { /* ignore */ }
    for (const a of c.extraAnimators || []) { try { a.dispose(); } catch { /* ignore */ } }
    for (const i of c.extraInstances || []) { try { i.dispose(); } catch { /* ignore */ } }
    try { c.instance?.dispose(); } catch { /* ignore */ }
    c.object?.removeFromParent();
    c.dispose?.();
  }
  showImported(imported) {
    clearTimeout(this._deb);++this._token;this._clear();
    const wrapper=new THREE.Group();wrapper.scale.z=-1;wrapper.add(imported.object);
    this.cur={object:wrapper,kind:'glb',box:new THREE.Box3().setFromObject(wrapper),dispose:imported.dispose};
    this.holder.add(wrapper);this.ring.visible=false;this._frameCamera();
    this._setStatus(`GLB: ${imported.report.triangles.toLocaleString()} triangles / ${imported.report.images} textures`);
  }

  reframeImported() {
    if (this.cur?.kind !== 'glb') return;
    this.holder.updateWorldMatrix(true, true);
    const inverse = this.holder.matrixWorld.clone().invert(), box = new THREE.Box3();
    this.cur.object.traverse(node => {
      if (!node.isMesh) return;
      node.geometry.computeBoundingBox();
      box.union(node.geometry.boundingBox.clone().applyMatrix4(new THREE.Matrix4().multiplyMatrices(inverse, node.matrixWorld)));
    });
    this.cur.box = box;
    this._frameCamera();
  }

  async _build() {
    const token = ++this._token;
    if (!this.renderer) return;
    const idx = this.itemIndex;
    const db = this.db;
    const def = idx != null ? db.def(idx) : null;
    const models = this.game.models;
    this._setStatus('loading...');
    let built = null;
    if (this.mode === 'character') built = await this._buildCharacter(def);
    else if (this.mode === 'icon') built = await this._buildInventory(def);
    else built = await this._buildItem(def);
    if (token !== this._token || !this.renderer) { this._disposeBuilt(built); return; }
    this._clear();
    this.cur = built;
    if (built?.object) this.holder.add(built.object);
    this.ring.visible = this.mode === 'character';
    this._frameCamera();
    if (built?.animator) await this._playAnim();
    if (token !== this._token || !this.renderer || this.cur !== built) return;
    this._setStatus(built?.status || (built ? '' : 'no model'));
    void models;
  }
  _disposeBuilt(b) {
    if (!b) return;
    try { b.animator?.dispose(); } catch { /* ignore */ }
    try { b.instance?.dispose(); } catch { /* ignore */ }
    for (const a of b.extraAnimators || []) { try { a.dispose(); } catch { /* ignore */ } }
    for (const i of b.extraInstances || []) { try { i.dispose(); } catch { /* ignore */ } }
    b.object?.removeFromParent();
    b.dispose?.();
  }

  /** Weapon model: rigid, or skinned on the item action skeleton playing its loop (player.js weaponModel). */
  async _weaponModel(mesh, opts, skel, anim, animTime) {
    const models = this.game.models;
    if (skel && anim) {
      const m = await models.loadSkinned({ skelKey: skel, parts: [{ meshKey: mesh, tpackKey: opts.tpackKey || null, textures: opts.textures || null }] }).catch(() => null);
      if (m && !m.empty) {
        const clip = await models.loadClip(anim, m, { duration: animTime || 2 }).catch(() => null);
        const inst = m.instantiate();
        inst.root.traverse(o => { if (o.isSkinnedMesh) o.frustumCulled = false; });
        const an = clip ? new Animator(inst) : null;
        if (an) an.play(clip, { loop: true, fade: 0 });
        return { object: inst.root, animator: an, instance: inst };
      }
    }
    const sm = await models.loadStatic(mesh, opts).catch(() => null);
    return sm ? { object: sm.instantiate(), animator: null } : null;
  }

  async _buildCharacter(def) {
    const ci = this.classIndex;
    const cd0 = this.classDef(ci);
    if (!cd0?.skeleton) return { status: 'class has no model' };
    const db = this.db, models = this.game.models;
    const E = def ? this.equipmentFor(ci, def.index) : this.equipmentFor(ci, -1);
    const view = E.view(null);
    const style = E.style();
    const cd = styledClass(cd0, db, style);
    const parts = (cd0.parts || []).map(p => { const e = view[p.slot]; const src = e && e.mesh ? e : p; return { meshKey: src.mesh, tpackKey: src.tpack || null, textures: src.textures || null }; }).filter(p => p.meshKey);
    const w = view.weapon && !view.weapon.none ? view.weapon : null;
    const same = w && w.leftMesh && w.leftMesh === w.mesh;
    const leftOpts = (w?.leftTpack || w?.leftTextures) ? { tpackKey: w.leftTpack || null, textures: w.leftTextures || null }
      : same ? { tpackKey: w.tpack || null, textures: w.textures || null } : {};
    const [model, main, second, wing] = await Promise.all([
      models.loadSkinned({ skelKey: cd0.skeleton, parts }),
      w?.mesh ? this._weaponModel(w.mesh, { tpackKey: w.tpack || null, textures: w.textures || null }, w.skel, w.anim, w.animTime) : null,
      w?.leftMesh ? this._weaponModel(w.leftMesh, leftOpts, w.leftSkel, w.leftAnim, w.leftAnimTime) : null,
      view.wing ? this._wingModel(view.wing) : null,
    ]);
    if (!model) return { status: 'character model failed' };
    const inst = model.instantiate();
    inst.root.traverse(o => { if (o.isSkinnedMesh) o.frustumCulled = false; });
    const scale = Number(cd0.scale) > 0 ? Number(cd0.scale) : 1;
    inst.root.scale.setScalar(scale);
    const animator = new Animator(inst);
    const weapons = [];
    if (main) weapons.push({ ...main, hand: 'main' });
    if (second) weapons.push({ ...second, hand: 'second' });
    const out = {
      kind: 'character', object: inst.root, instance: inst, animator, model, classDef: cd, weaponDef: w, weapons,
      extraAnimators: [...weapons.map(x => x.animator), wing?.animator].filter(Boolean), clips: new Map(),
      extraInstances: [...weapons.map(x => x.instance), wing?.instance].filter(Boolean),
      box: new THREE.Box3().copy(model.bbox).applyMatrix4(new THREE.Matrix4().makeScale(scale, scale, scale)),
    };
    if (wing?.object && !inst.attach(wing.object, view.wing.bone || 'weaponW')) wing.object.removeFromParent();
    this._placeWeapons(out, 'battle');
    const miss = [];
    if (def?.slot && !w && (def.slot === 'weapon' || def.slot === 'offhand')) miss.push('this weapon has no model for this class');
    if (def && !((Number(def.classMask) >>> ci) & 1)) miss.push('class not allowed');
    out.status = miss.join(' / ');
    return out;
  }

  async _wingModel(wv) {
    const A = this.db._actionsData;
    const t = wv.action != null && A ? A.item?.[wv.action] : null;
    if (t?.skel) {
      const row = t.rows?.find(r => r[0] === 0 && r[1] === 1) || t.rows?.[0];
      const anim = row ? A.anims?.[row[3]] : null;
      const r = await this._weaponModel(wv.mesh, { tpackKey: wv.tpack || null, textures: wv.textures || null }, t.skel, anim, Number(row?.[4]) || 2);
      if (r) return r;
    }
    const sm = await this.game.models.loadStatic(wv.mesh, { tpackKey: wv.tpack || null, textures: wv.textures || null, twoSide: true }).catch(() => null);
    if (!sm) return null;
    const object = sm.instantiate();
    return { object, animator: object.userData?.wingMotion || null };
  }

  /** Weapons on the battle (hand) or peace (sheath) bones, like Player._placeWeapons. */
  _placeWeapons(c, stance) {
    const d = c.weaponDef || {};
    const peace = stance === 'peace';
    for (const e of c.weapons || []) {
      const bone = e.hand === 'main' ? (peace ? d.bonePeace || d.bone : d.bone) : (peace ? d.bonePeaceLeft || d.boneLeft : d.boneLeft);
      if (!bone || !c.instance.getBone(bone)) { e.object.visible = false; continue; }
      e.object.visible = true;
      if (e.object.parent !== c.instance.getBone(bone)) { c.instance.detach(e.object); c.instance.attach(e.object, bone); }
    }
    c.stance = stance;
  }

  async _playAnim() {
    const c = this.cur;
    if (!c?.animator || !c.model) return;
    const A = c.classDef?.anims || {};
    let e = null;
    const k = this.anim;
    if (k === 'idlePeace') e = A.idlePeace || A.idle;
    else if (k === 'run') e = A.run || A.runPeace;
    else if (k === 'walk') e = A.walk || A.walkPeace;
    else if (/^attack\d$/.test(k)) e = (A.attack || [])[Number(k.slice(6))] || (A.attack || [])[0];
    else e = A.idle || A.idlePeace;
    if (c.kind !== 'character') e = A.idle || A.idlePeace || null;
    if (!e?.anim) return;
    const key = `${e.anim}|${e.timeLength}`;
    let clip = c.clips?.get(key);
    if (!clip) {
      clip = await this.game.models.loadClip(normKey(e.anim), c.model, { duration: e.timeLength > 0 ? e.timeLength : null }).catch(() => null);
      c.clips?.set(key, clip);
    }
    if (this.cur !== c || !this.renderer || this.anim !== k || !clip) return;
    // the weapon sits in the hand for battle clips and on the sheath bone for peace (style 0) clips
    if (c.kind === 'character') this._placeWeapons(c, Number(e.style) === 0 ? 'peace' : 'battle');
    c.animator.play(clip, { loop: true, fade: 0.2 });
  }

  async _buildItem(def) {
    if (!def) return null;
    const ci = this.classIndex, db = this.db, models = this.game.models;
    const E = this.equipmentFor(ci, def.index);
    const L = db.look(def.index);
    const slot = def.slot;
    // Wings use their own skeleton/action loop, including when previewed without the character.
    if (slot === 'wing') {
      const view = E.view(null).wing;
      const wing = view ? await this._wingModel(view) : null;
      if (!wing?.object) return { status: 'wing model failed' };
      return { kind: 'object', object: wing.object, extraAnimators: [wing.animator].filter(Boolean),
        extraInstances: [wing.instance].filter(Boolean), box: boxOf(wing.object) };
    }
    // armour / costume parts are skinned to the class skeleton: show the part alone, in the class stand pose
    if (L?.parts?.length && (slot && slot !== 'weapon' && slot !== 'offhand' && slot !== 'wing')) {
      const a = E.assetFor(def.index);
      const cd0 = this.classDef(ci);
      if (a?.mesh && cd0?.skeleton) {
        const model = await models.loadSkinned({ skelKey: cd0.skeleton, parts: [{ meshKey: a.mesh, tpackKey: a.tpack || null, textures: a.textures || null }] });
        if (model) {
          const inst = model.instantiate();
          inst.root.traverse(o => { if (o.isSkinnedMesh) o.frustumCulled = false; });
          return { kind: 'part', object: inst.root, instance: inst, animator: new Animator(inst), model, classDef: styledClass(cd0, db, 1), clips: new Map(), box: model.bbox.clone() };
        }
      }
    }
    // weapons: the main mesh (and the left one) side by side, animated weapons playing their loop
    const w = (slot === 'weapon' || slot === 'offhand') ? E.weaponView() : null;
    if (w && !w.none) {
      const g = new THREE.Group();
      const parts = await Promise.all([
        this._weaponModel(w.mesh, { tpackKey: w.tpack || null, textures: w.textures || null }, w.skel, w.anim, w.animTime),
        w.leftMesh ? this._weaponModel(w.leftMesh, { tpackKey: w.leftTpack || null, textures: w.leftTextures || null }, w.leftSkel, w.leftAnim, w.leftAnimTime) : null,
      ]);
      const anims = [];
      parts.forEach((p, i) => { if (!p) return; g.add(p.object); if (i === 1) p.object.position.x = 0.35; if (p.animator) anims.push(p.animator); });
      if (!g.children.length) return { status: 'model failed' };
      return { kind: 'object', object: g, extraAnimators: anims, extraInstances: parts.map(p => p?.instance).filter(Boolean), box: boxOf(g) };
    }
    const a = E.assetFor(def.index) || db.shape(def)?.game || db.shape(def)?.inv;
    if (!a?.mesh) return { status: 'this item has no model' };
    const sm = await models.loadStatic(a.mesh, { tpackKey: a.tpack || null, textures: a.textures || null, twoSide: true });
    if (!sm) return { status: 'model failed' };
    const o = sm.instantiate();
    return { kind: 'object', object: o, box: sm.bbox.clone() };
  }

  async _buildInventory(def) {
    if (!def) return null;
    const m = this.game.items?.icons?.model?.(def.index);
    if (!m?.mesh) return { status: 'no inventory model' };
    const models = this.game.models;
    if (m.anim && m.skel) {
      const model = await models.loadSkinned({ skelKey: m.skel, parts: [{ meshKey: m.mesh, tpackKey: m.tpack || null, textures: m.textures || null }] });
      if (model) {
        const inst = model.instantiate();
        const clip = await models.loadClip(m.anim, model, { duration: m.animTime || 2 }).catch(() => null);
        const an = new Animator(inst);
        if (clip) an.play(clip, { loop: true, fade: 0 });
        inst.root.traverse(o => { if (o.isSkinnedMesh) o.frustumCulled = false; if (o.material && m.twoSide) for (const mt of [].concat(o.material)) mt.side = THREE.DoubleSide; });
        return { kind: 'object', object: inst.root, instance: inst, extraAnimators: [an], box: model.bbox.clone() };
      }
    }
    const sm = await models.loadStatic(m.mesh, { tpackKey: m.tpack || null, textures: m.textures || null, twoSide: m.twoSide !== false });
    if (!sm) return { status: 'inventory model failed' };
    const object = sm.instantiate();
    return { kind: 'object', object, extraAnimators: [object.userData?.wingMotion].filter(Boolean), box: sm.bbox.clone() };
  }

  // ---------------------------------------------------------------------------------------------- camera + frame
  _frameCamera() {
    const b = this.cur?.box;
    const box = b && !b.isEmpty() ? b : new THREE.Box3(new THREE.Vector3(-0.5, 0, -0.5), new THREE.Vector3(0.5, 1.8, 0.5));
    const c = box.getCenter(new THREE.Vector3()), s = box.getSize(new THREE.Vector3());
    const r = Math.max(s.x, s.y, s.z) || 1;
    // objects are re-centred on the turntable; characters stand on the floor
    if (this.cur?.object && this.cur.kind === 'object') { this.cur.object.position.set(-c.x, -c.y, -c.z); this._target = new THREE.Vector3(0, 0, 0); }
    else this._target = this.cur?.kind === 'glb' ? fileToThree(c.x, c.y, c.z) : fileToThree(0, c.y, 0);
    this._dist = (r / 2) / Math.tan((this.camera.fov * Math.PI) / 360) * 1.15 + r * 0.25;
  }

  _frame() {
    const now = performance.now();
    const dt = Math.min(0.1, (now - this._last) / 1000);
    this._last = now;
    const c = this.cur;
    if (c) {
      try { c.animator?.update(dt); } catch { /* ignore */ }
      for (const a of c.extraAnimators || []) { try { a.update(dt); } catch { /* ignore */ } }
    }
    if (this.spin && this.mode !== 'character') this.view.yaw += dt * 0.6;
    this.holder.rotation.y = -this.view.yaw;
    const t = this._target || new THREE.Vector3(0, 1, 0);
    const d = (this._dist || 3) * this.view.zoom;
    const p = this.view.pitch;
    // the model faces FILE -Z = three +Z: the camera sits on the +Z side
    this.camera.position.set(t.x, t.y + Math.sin(p) * d, t.z + Math.cos(p) * d);
    this.camera.near = Math.max(0.01, d / 200);
    this.camera.far = d * 20 + 10;
    this.camera.updateProjectionMatrix();
    this.camera.lookAt(t);
    try { this.renderer.render(this.scene, this.camera); } catch (err) { console.warn('[itembuilder] preview render', err); cancelAnimationFrame(this._raf); }
  }

  /** PNG data URL of the current preview frame. */
  snapshot() { try { this.renderer.render(this.scene, this.camera); return this.canvas.toDataURL('image/png'); } catch { return null; } }
}

function boxOf(obj) {
  obj.updateMatrixWorld(true);
  const box = new THREE.Box3();
  obj.traverse(n => {
    if (n.isSkinnedMesh) { n.geometry.computeBoundingBox?.(); if (n.geometry.boundingBox) box.union(n.geometry.boundingBox.clone()); }
    else if (n.isMesh) { n.geometry.computeBoundingBox?.(); const b = n.geometry.boundingBox?.clone().applyMatrix4(n.matrixWorld); if (b) box.union(b); }
  });
  return box;
}
