// NPC quest marks: the condition effect 11:2220 "NPC_Quest" of property/effect/effectscene.02.txt (skills_effects.json):
//   scene 1  a quest to give        gold scroll (que_goldscroll.mesh + skel + anim, 3000 ms) + rotating back glow
//   scene 2  a quest to turn in     gold box (que_goldbox) + two counter-rotating back glows
//   scene 3  a quest in progress    gray box (que_graybox) + back glows + a spinning crack sprite
// attached at the NPC's "top" + (0, 0.8, 0). Mesh units are unlit and additive (effects.md §5.4: transparent:false),
// the control alpha scales them; the # glow unit is drawn twice (units 2 + 3) = colour x2. The loop period is the
// units' own animation length (3000 ms; the effect timeline is normalised, docs/formats/effects.md §5.1).
// Minimap: the NPC's dialog-row icon (renewalquest #31 ! / #34 ? / #32 grey ?) through game.minimapMarkers.
import * as THREE from 'three';
import { Animator } from '../../engine/animator.js';
import { atlas } from '../../ui/atlas.js';

const LOOP_MS = 3000;
const OFFSET_Y = 0.8;
const MESH_SIZE = 1.5;       // effectdata unit size of mh_QUEST_GOLDSCROLL / GOLDBOX / GRAYBOX
const SCENES = {
  available: { mesh: 'goldscroll', glows: [{ tex: 'back', alpha: 0.4, scale: 0.7, rot: 360 }] },
  complete: { mesh: 'goldbox', glows: [{ tex: 'back', alpha: 0.2, scale: 1, rot: -360 }, { tex: 'back', alpha: 0.4, scale: 0.7, rot: 360 }] },
  active: { mesh: 'graybox', meshScale: 1.02, glows: [{ tex: 'back', alpha: 0.3, scale: 1, rot: -360 }, { tex: 'back', alpha: 0.4, scale: 0.7, rot: 360 }, { tex: 'crack', alpha: 0.4, scale: 1, rot: -720, size: 1 }] },
};
const UNIT = {
  mesh: n => ({ mesh: `mesh/effect/quest/que_${n}.mesh`, skel: `skel/effect/quest/que_${n}.skel`, anim: `anim/effect/quest/que_${n}.anim`, tpack: `texturepack/effect/quest/que_${n}.tpack`, tpackGlow: `texturepack/effect/quest/que_${n}#.tpack` }),
  back: 'texture/effect/quest/que_eff_02#.dds',
  crack: 'texture/effect/monster/crack_yellow#.dds',
};
const MINI_ROW = { available: 31, availableMain: 30, availableRepeat: 51, complete: 34, completeMain: 33, completeRepeat: 52, active: 32 };

export class QuestMarks {
  constructor(sys) {
    this.sys = sys;
    this.game = sys.game;
    this.marks = new Map();     // npc actor -> {state, group, anim, glows, t}
    this._models = new Map();   // mesh name -> Promise<SkinnedModel>
    this._clips = new Map();
    this._tex = new Map();
    this._mini = {};
    this._t = 0;
    this._dirty = true;
  }
  get eng() { return this.sys.engine; }
  get db() { return this.sys.db; }

  install() {
    const g = this.game;
    g.events?.on?.('map', () => { this.clear(); this._dirty = true; });
    g.events?.on?.('quest:changed', () => { this._dirty = true; });
    g.events?.on?.('levelup', () => { this._dirty = true; });
    // minimap icons: the 16 x 16 icon cell of the dialog-row sprites, registered as their own atlas sprites
    // ('questicon#N' = the left 16 px of renewalquest#N) for game.minimap.setMarker (hud-options minimap)
    atlas.load().then(() => {
      for (const k of Object.values(MINI_ROW)) {
        const row = atlas.rect('renewalquest', k);
        if (row && atlas.table && !atlas.table.has(`questicon#${k}`)) atlas.table.set(`questicon#${k}`, { ...row, group: 'questicon', index: k, w: 16, h: 16, m: [0, 0, 0, 0] });
      }
    });
    this._mm = new Set();
  }

  /** Mark state of an NPC: 'complete' | 'available' | 'active' | null, plus the quest category for the colour. */
  stateOf(npc) {
    const n = Number(npc?.npcIndex ?? npc?.index);
    if (!Number.isFinite(n)) return null;
    const dlg = this.sys.dialog;
    let best = null, cat = null;
    const rank = { complete: 3, available: 2, active: 1 };
    const set = (s, q) => { if (!best || rank[s] > rank[best]) { best = s; cat = q?.cat; } };
    for (const e of dlg.menuEntries(n)) {
      if (e.kind !== 'quest') continue;
      const q = this.db.quest(e.id);
      if (e.state === 'available') { if (!this.eng._instant(q)) set('available', q); }
      else if (e.state === 'complete' && dlg._isTurnIn(q, n)) set('complete', q);
      else if (e.state === 'active' || e.state === 'complete') {
        // talking to this NPC finishes the quest: show it as ready
        const wouldFinish = dlg._isTurnIn(q, n) && (q.objectives || []).every(o => this.eng.objectiveDone(q, o) || (o.kind === 'talk' && (o.targets || []).some(t => Number(t.id) === n)));
        set(wouldFinish ? 'complete' : 'active', q);
      }
    }
    return best ? { state: best, cat } : null;
  }

  refresh() {
    this._dirty = false;
    const npcs = this.game.npcs || [];
    const alive = new Set(npcs);
    for (const [npc, m] of this.marks) if (!alive.has(npc) || npc.disposed) { this._drop(m); this.marks.delete(npc); }
    for (const npc of npcs) {
      const st = this.stateOf(npc);
      const cur = this.marks.get(npc);
      if (cur && cur.state === st?.state) { cur.cat = st?.cat; continue; }
      if (cur) { this._drop(cur); this.marks.delete(npc); }
      if (st) {
        const m = { state: st.state, cat: st.cat, group: new THREE.Group(), glows: [], anim: null, t: Math.random() * LOOP_MS / 1000 };
        m.group.name = `questmark:${st.state}`;
        this.marks.set(npc, m);
        this._build(npc, m).catch(err => console.warn('[quests] mark', err));
      }
    }
    this.syncMinimap();
  }

  async _build(npc, m) {
    const sc = SCENES[m.state];
    const g = this.game;
    const parent = npc.group;
    if (!parent) return;
    parent.add(m.group);
    this._place(npc, m);
    // glow sprites
    for (const gl of sc.glows) {
      const tex = await this._texture(UNIT[gl.tex]);
      if (!this.marks.has(npc) || this.marks.get(npc) !== m) return;
      const mat = new THREE.SpriteMaterial({ map: tex || null, transparent: true, opacity: gl.alpha, blending: THREE.AdditiveBlending, depthWrite: false, color: 0xffffff });
      const sp = new THREE.Sprite(mat);
      const size = (gl.size ?? 1.5) * gl.scale;
      sp.scale.set(size, size, 1);
      sp.renderOrder = 20;
      m.group.add(sp);
      m.glows.push({ sp, rot: gl.rot });
    }
    // the prop (skinned + animated)
    const model = await this._model(sc.mesh);
    if (!model || !this.marks.has(npc) || this.marks.get(npc) !== m) return;
    const inst = model.instantiate();
    const holder = new THREE.Group();
    holder.add(inst.root);
    holder.scale.setScalar(MESH_SIZE * (sc.meshScale || 1));   // unit `size 1.5` x control scale
    m.holder = holder;
    m.inst = inst;
    inst.meshes.forEach((mesh, i) => {
      const old = mesh.material;
      const list = Array.isArray(old) ? old : [old];
      const mats = list.map(o => {
        const glow = /#/.test(o?.map?.userData?.key || '') || (inst.meshes.length > 1 && i >= inst.meshes.length / 2);
        return new THREE.MeshBasicMaterial({ map: o?.map || null, transparent: true, depthWrite: false, blending: THREE.AdditiveBlending, side: THREE.DoubleSide, opacity: glow ? 1 : 0.3, color: glow ? new THREE.Color(2, 2, 2) : new THREE.Color(1, 1, 1) });
      });
      mesh.material = Array.isArray(old) ? mats : mats[0];
      mesh.renderOrder = 21;
      mesh.frustumCulled = false;
    });
    m.group.add(holder);
    const clip = await this._clip(sc.mesh, model);
    if (clip && this.marks.get(npc) === m) {
      m.anim = new Animator(inst);
      m.anim.play(clip, { loop: true, fade: 0 });
    }
  }
  _place(npc, m) {
    const h = Math.max(1.2, Number(npc.height) || 1.8);
    m.group.position.set(0, h + OFFSET_Y, 0);
  }

  _model(name) {
    if (!this._models.has(name)) {
      const u = UNIT.mesh(name);
      const models = this.game.models;
      // one skeleton, two parts: the base texture (unit 1) and the # glow texture (units 2 + 3)
      const p = models ? models.loadSkinned({ skelKey: u.skel, parts: [{ meshKey: u.mesh, tpackKey: u.tpack }, { meshKey: u.mesh, tpackKey: u.tpackGlow }] })
        .catch(err => { console.warn('[quests] mark model', name, err); return null; }) : Promise.resolve(null);
      this._models.set(name, p);
    }
    return this._models.get(name);
  }
  _clip(name, model) {
    if (!this._clips.has(name)) this._clips.set(name, this.game.models.loadClip(UNIT.mesh(name).anim, model, { duration: LOOP_MS / 1000 }).catch(() => null));
    return this._clips.get(name);
  }
  _texture(key) {
    if (!this._tex.has(key)) this._tex.set(key, (this.game.textures?.load(key, { repeat: false }) || Promise.resolve(null)).catch(() => null));
    return this._tex.get(key);
  }

  _drop(m) {
    m.group.parent?.remove(m.group);
    m.anim?.dispose?.();
    for (const gl of m.glows) gl.sp.material.dispose();
    m.inst?.dispose?.();
  }
  clear() {
    for (const m of this.marks.values()) this._drop(m);
    this.marks.clear();
    const mm = this.game.minimap;
    if (mm?.removeMarker) for (const id of this._mm || []) mm.removeMarker(id);
    this._mm = new Set();
  }

  update(dt) {
    this._t += dt;
    if (this._dirty || this._t > 1) { this._t = 0; this.refresh(); }
    const g = this.game, p = g.player;
    for (const [npc, m] of this.marks) {
      if (!m.group.parent || npc.culled || npc.group?.visible === false) continue;
      m.t = (m.t + dt) % (LOOP_MS / 1000);
      const f = m.t / (LOOP_MS / 1000);
      for (const gl of m.glows) gl.sp.material.rotation = (gl.rot * f * Math.PI) / 180;
      m.anim?.update(dt);
      // billboard "camera": the prop faces the camera around the vertical axis (FILE frame under the mirror)
      if (m.holder && g.camera) {
        const cx = g.camera.position.x, cz = -g.camera.position.z;
        const wx = npc.x, wz = npc.z;
        const yawWorld = Math.atan2(-(cx - wx), -(cz - wz));
        m.holder.rotation.y = yawWorld - (npc.group.rotation?.y || 0);
      }
      if (p && Math.abs(npc.height - (m._h || 0)) > 0.01) { m._h = npc.height; this._place(npc, m); }
    }
  }

  /** Quest icons on the minimap (game.minimap.setMarker of the hud-options minimap). */
  syncMinimap() {
    const mm = this.game.minimap;
    if (!mm?.setMarker) return;
    const map = this.game.world?.info?.index;
    const keep = new Set();
    for (const [npc, m] of this.marks) {
      const main = m.cat === 'main', rep = ['daily', 'repeat', 'weekday', 'weekly', 'ticket', 'request', 'wanted'].includes(m.cat);
      const key = m.state === 'active' ? MINI_ROW.active
        : m.state === 'complete' ? (main ? MINI_ROW.completeMain : rep ? MINI_ROW.completeRepeat : MINI_ROW.complete)
          : (main ? MINI_ROW.availableMain : rep ? MINI_ROW.availableRepeat : MINI_ROW.available);
      const id = `quest:${map}:${npc.npcIndex ?? npc.index}`;
      keep.add(id);
      mm.setMarker(id, { x: npc.x, z: npc.z, sprite: ['questicon', key], size: [12, 12], map, tip: npc.name });
    }
    for (const id of this._mm) if (!keep.has(id)) mm.removeMarker(id);
    this._mm = keep;
  }
}
