// Weapon trace (Graphics tab "Trace Effect": N/A / Character / All). The client draws a textured ribbon behind the
// blade while a character swings (binary/trace.fx "Tracer": position + uv + vertex colour, texture
// texture/effect/common/eff_trace_white.dds, eff_trace_blue.dds). Here: every frame of an attack or skill clip, the
// blade line of each held melee weapon (its mesh's long axis, from 30% of the length to the tip, in weapon space) is
// sampled in world space; the last samples make a strip whose alpha fades with age. White for plain attacks, blue for
// skills [inference: the two textures of the client]. "Character" = your own character, "All" = every player
// character in view (and their servants have no weapons). Ranged weapons (bows, crossbows, magic bolts) leave none.
import * as THREE from 'three';

const LIFE = 0.24;          // seconds a sample stays visible
const MAX = 24;             // samples per trail
const TEX = { white: 'texture/effect/common/eff_trace_white.dds', blue: 'texture/effect/common/eff_trace_blue.dds' };
const _a = new THREE.Vector3(), _b = new THREE.Vector3(), _m = new THREE.Matrix4();

export class WeaponTraces {
  constructor(game, ctx) {
    this.game = game;
    this.ctx = ctx;
    this.trails = new Map();       // weapon Object3D -> trail
    this.mats = {};
    this.root = new THREE.Group();
    this.root.name = 'weapon traces (FILE frame)';
    this.root.renderOrder = 5;
    game.worldRoot?.add(this.root);
    for (const [k, key] of Object.entries(TEX)) {
      const mat = new THREE.MeshBasicMaterial({ transparent: true, depthWrite: false, side: THREE.DoubleSide, vertexColors: true, blending: THREE.AdditiveBlending });
      this.mats[k] = mat;
      Promise.resolve(game.textures?.load?.(key, { repeat: false })).then(t => { if (t) { mat.map = t; mat.needsUpdate = true; } }).catch(() => {});
    }
  }

  /** The blade line of a weapon object in its own space: [base, tip] (cached per object). */
  _blade(obj) {
    if (obj.userData._hoBlade !== undefined) return obj.userData._hoBlade;
    // The client authored these points in mesh space: traceline runs tip first, base last.
    // Prefer it to a bounding-box axis, which includes handles/guards and misreads curved blades.
    const lines = obj.userData.model?.lines || [];
    const line = lines.find(l => /^traceline$/i.test(l.name)) || lines.find(l => /^weaponline$/i.test(l.name));
    const points = line?.strips?.find(s => s.length >= 6);
    if (points) {
      const tip = new THREE.Vector3().fromArray(points, 0);
      const base = new THREE.Vector3().fromArray(points, points.length - 3);
      if (tip.distanceToSquared(base) > 1e-6) {
        obj.userData._hoBlade = [base, tip];
        return obj.userData._hoBlade;
      }
    }
    obj.updateMatrixWorld(true);
    const inv = _m.copy(obj.matrixWorld).invert();
    const box = new THREE.Box3();
    const tmp = new THREE.Box3(), mm = new THREE.Matrix4();
    obj.traverse(o => {
      if (!o.isMesh || !o.geometry) return;
      if (!o.geometry.boundingBox) o.geometry.computeBoundingBox();
      tmp.copy(o.geometry.boundingBox).applyMatrix4(mm.multiplyMatrices(inv, o.matrixWorld));
      box.union(tmp);
    });
    if (box.isEmpty()) { obj.userData._hoBlade = null; return null; }
    const size = box.getSize(new THREE.Vector3());
    const axis = size.x >= size.y && size.x >= size.z ? 'x' : size.y >= size.z ? 'y' : 'z';
    const far = Math.abs(box.max[axis]) >= Math.abs(box.min[axis]) ? box.max[axis] : box.min[axis];
    const c = box.getCenter(new THREE.Vector3());
    const tip = c.clone(); tip[axis] = far;
    const base = c.clone(); base[axis] = far * 0.3;
    const len = Math.abs(far);
    obj.userData._hoBlade = len > 0.25 ? [base, tip] : null;
    return obj.userData._hoBlade;
  }

  _trail(obj) {
    let t = this.trails.get(obj);
    if (t) return t;
    const geo = new THREE.BufferGeometry();
    const pos = new Float32Array(MAX * 2 * 3), col = new Float32Array(MAX * 2 * 4), uv = new Float32Array(MAX * 2 * 2);
    geo.setAttribute('position', new THREE.BufferAttribute(pos, 3).setUsage(THREE.DynamicDrawUsage));
    geo.setAttribute('color', new THREE.BufferAttribute(col, 4).setUsage(THREE.DynamicDrawUsage));
    geo.setAttribute('uv', new THREE.BufferAttribute(uv, 2).setUsage(THREE.DynamicDrawUsage));
    const idx = [];
    for (let i = 0; i < MAX - 1; i++) { const a = i * 2; idx.push(a, a + 1, a + 2, a + 1, a + 3, a + 2); }
    geo.setIndex(idx);
    const mesh = new THREE.Mesh(geo, this.mats.white);
    mesh.frustumCulled = false;
    mesh.renderOrder = 5;
    this.root.add(mesh);
    t = { mesh, geo, samples: [] };
    this.trails.set(obj, t);
    return t;
  }

  _actors(mode) {
    const g = this.game, p = g.player;
    if (!p || mode <= 0) return [];
    if (mode === 1) return [p];
    let list = [];
    try { list = g.actors ? g.actors() : [p]; } catch { list = [p]; }
    return list.filter(a => a && a.kind === 'player' && !a.dead);
  }

  update(dt) {
    const mode = Number(this.ctx.options.get('trace')) || 0;
    const now = this.game.time || 0;
    const live = new Set();
    for (const a of this._actors(mode)) {
      const swinging = (a.state === 'attack' || a.state === 'skill') && a.stance !== 'peace' && !a.dead && !this._ranged(a);
      for (const e of a._weaponObjs || []) {
        const obj = e.obj;
        if (!obj?.parent || !obj.visible) continue;
        live.add(obj);
        const t = this._trail(obj);
        if (swinging) {
          const blade = this._blade(obj);
          if (blade) {
            obj.updateWorldMatrix(true, false);
            _a.copy(blade[0]).applyMatrix4(obj.matrixWorld);
            _b.copy(blade[1]).applyMatrix4(obj.matrixWorld);
            // THREE space -> FILE frame of worldRoot
            this.root.worldToLocal(_a); this.root.worldToLocal(_b);
            t.samples.unshift({ base: _a.clone(), tip: _b.clone(), t: now });
            if (t.samples.length > MAX) t.samples.length = MAX;
            t.mesh.material = a.state === 'skill' ? this.mats.blue : this.mats.white;
          }
        }
        this._build(t, now);
      }
    }
    for (const [obj, t] of this.trails) {
      if (live.has(obj)) continue;
      if (!obj.parent) { this._drop(obj, t); continue; }
      this._build(t, now);
      if (!t.samples.length) this._drop(obj, t);
    }
  }

  _ranged(a) {
    const r = Number(a.stats?.attackRange ?? this.game.stats?.attackRange);
    return Number.isFinite(r) && r > 5;
  }

  _build(t, now) {
    const S = t.samples;
    while (S.length && now - S[S.length - 1].t > LIFE) S.pop();
    const n = S.length;
    t.mesh.visible = n >= 2;
    if (n < 2) return;
    const pos = t.geo.attributes.position.array, col = t.geo.attributes.color.array, uv = t.geo.attributes.uv.array;
    for (let i = 0; i < MAX; i++) {
      const s = S[Math.min(i, n - 1)];
      const k = 1 - Math.min(1, (now - s.t) / LIFE);
      const u = i / Math.max(1, n - 1);
      const o = i * 6;
      pos[o] = s.tip.x; pos[o + 1] = s.tip.y; pos[o + 2] = s.tip.z;
      pos[o + 3] = s.base.x; pos[o + 4] = s.base.y; pos[o + 5] = s.base.z;
      const c = i * 8, al = i < n ? k : 0;
      col[c] = col[c + 1] = col[c + 2] = 1; col[c + 3] = al;
      col[c + 4] = col[c + 5] = col[c + 6] = 1; col[c + 7] = al;
      const q = i * 4;
      uv[q] = u; uv[q + 1] = 0; uv[q + 2] = u; uv[q + 3] = 1;
    }
    t.geo.attributes.position.needsUpdate = true;
    t.geo.attributes.color.needsUpdate = true;
    t.geo.attributes.uv.needsUpdate = true;
    t.geo.setDrawRange(0, (n - 1) * 6);
  }

  _drop(obj, t) { t.mesh.removeFromParent(); t.geo.dispose(); this.trails.delete(obj); }

  clear() { for (const [obj, t] of [...this.trails]) this._drop(obj, t); }

  dispose() { this.clear(); this.root.removeFromParent(); for (const m of Object.values(this.mats)) m.dispose(); }
}
