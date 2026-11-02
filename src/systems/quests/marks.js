// NPC quest marks: the condition effect 11:2220 "NPC_Quest" of property/effect/effectscene.02.txt (skills_effects.json):
//   scene 1  a quest to give        gold scroll (que_goldscroll.mesh + skel + anim, 3000 ms) + rotating back glow
//   scene 2  a quest to turn in     gold box (que_goldbox) + two counter-rotating back glows
//   scene 3  a quest in progress    gray box (que_graybox) + back glows + a spinning crack sprite
// attached at the NPC's "top" + (0, 0.8, 0). Mesh units are unlit and additive (effects.md §5.4: transparent:false),
// the control alpha scales them; the # glow texture uses unit colour; this avoids double-amplifying it in the engine renderer. The loop period is the
// units' own animation length (3000 ms; the effect timeline is normalised, docs/formats/effects.md §5.1).
// Minimap: the NPC's dialog-row icon (renewalquest #31 ! / #34 ? / #32 grey ?) through game.minimapMarkers.
//
// Monster hunt marks use Global's code (43,12,0,0) `quest target monster`:
// effect 8:2589, scene 1, 2000 ms, continuous. Quest eligibility and top
// attachment are existing engine rules; the source data does not establish them.
import * as THREE from 'three';
import { Animator } from '../../engine/animator.js';
import { atlas } from '../../ui/atlas.js';
import { EffectPlayer } from '../skills/effects.js';
import { fxBlendFields, nullTextureColor } from '../skills/fx-units.js';
import { nativeKillBinding } from './objective-credit.js';
// ---- gfx-B (Global 43.19 parity) begin: NPC quest marks from modeleffect.csv code1 18 ----
import { AuthoredEffectsData } from '../items/authored-effects-data.js';
import { gfxB } from '../../config/gfx-b-switches.js';
// Global 43.19 script/effect/modeleffect.csv, code1 18 / code3 0 / code4 0, code2 per quest line and mark state
// (descriptions: 일반 normal 1/2/3, 일일 daily 5/6/7, 메인 main 12/13/14, 메인 2 (성장 동선) growth 15/16/17):
// e.g. 18,1 -> effect 1:2551 "quest_point" (mh_quest_mark_P_yellow, the yellow "!"), scene 1, 2000 ms, attached at "top" +
// (0,1,0) with its own rotation / alpha keys. The 43.19 recording (gfx-compare/g1s/g102.jpg) shows exactly this mark over
// Kedrick (Guard). The rows are read from the data at runtime; only the category grouping below is engine-side:
// quest categories with no own row (weekday/weekly/repeat/ticket/request/wanted/normal) use the 일반 (normal) rows.
// Off switch: globalThis.__dekaronGfxB = { questMarkNative: false } restores the previous 11:2220 build.
const NATIVE_MARK_LINE = { daily: 'daily', main: 'main', growth: 'growth' };
const NATIVE_MARK_CODE2 = { normal: { available: 1, active: 2, complete: 3 }, daily: { available: 5, active: 6, complete: 7 }, main: { available: 12, active: 13, complete: 14 }, growth: { available: 15, active: 16, complete: 17 } };
export function nativeQuestMarkRows(text) {
  const rows = new Map();
  for (const line of String(text || '').split(/\r?\n/)) {
    const c = line.split(',').map(v => v.trim());
    if (Number(c[0]) !== 18 || Number(c[2]) !== 0 || Number(c[3]) !== 0 || !(Number(c[5]) > 0)) continue;
    const code2 = Number(c[1]);
    if (!rows.has(code2)) rows.set(code2, { cate: Number(c[4]), id: Number(c[5]), scene: Number(c[6]) || 1, timeMs: Number(c[7]) || 1000, loop: Number(c[8]) || 0 });
  }
  return rows;
}
export function nativeQuestMarkCode2(state, cat) { return NATIVE_MARK_CODE2[NATIVE_MARK_LINE[cat] || 'normal']?.[state] ?? null; }
// ---- gfx-B end ----

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

// Compiled from the supplied Global effectscene.02/effectdata.02 and
// modeleffect.csv. This metadata-only fallback lets existing prepared installs
// use their own Global texture without downloading or rebuilding their data.
// No packed artwork is distributed. The inactive authored control is kept.
const MONSTER_QUEST_REF = Object.freeze({cate:8,id:2589,scene:1,timeMs:2000,loop:0});
const MONSTER_QUEST_SCENE = Object.freeze({cate:8,id:2589,name:'Mon_Q',file:'02',res:{1:'02:sp_mon_q',2:'02:sp_mon_q_m'},scenes:{1:{name:'1',controls:[
  {unit:1,active:false,life:[0,1000],scale:[[0,.5,.5,.5]],alpha:[[0,1],[450,0],[999,1]]},
  {unit:2,life:[0,1000],scale:[[0,.5,.5,.5]],alpha:[[0,.8],[450,1],[999,.8]]}
]}},refs:1});
const monsterQuestUnit=(name,texture,blend)=>({name,type:'sprite',file:'02',billboard:'camera',size:1,backPrint:false,distort:false,tail:{count:0,a:0,b:0,ms:0,on:true},texture,blend,texLoop:'increase',texAnimMs:0});
const MONSTER_QUEST_UNITS = Object.freeze({
  '02:sp_mon_q':monsterQuestUnit('sp_Mon_Q','texture/effect/ui/quest_q#.dds','add'),
  '02:sp_mon_q_m':monsterQuestUnit('sp_Mon_Q_m','texture/effect/ui/quest_q.dds','modulate'),
});
export function monsterQuestEffectData(data){
  const view=Object.create(data);
  view.scene=key=>key==='8:2589'?MONSTER_QUEST_SCENE:data.scene(key);
  view.unit=key=>MONSTER_QUEST_UNITS[key]||data.unit(key);
  return view;
}
// Global's DDS is top-first; the engine's camera-facing THREE.Sprite UVs
// display this artwork upside down. Correct only this mark using a cached
// texture clone, so every other effect and the shared texture stay unchanged.
export function monsterQuestTextureView(game){
  const source=game.textures;
  if(!source?.load)return {game,dispose(){}};
  let pending=null,owned=null,disposed=false;
  const textures=Object.create(source);
  textures.load=(key,opts)=>{
    if(String(key).toLowerCase()!=='texture/effect/ui/quest_q.dds')return source.load(key,opts);
    if(!pending)pending=Promise.resolve().then(()=>source.load(key,opts)).then(texture=>{
      if(!texture||disposed){pending=null;return null;}
      owned=texture.clone();owned.repeat.y=-1;owned.offset.y=1;owned.needsUpdate=true;return owned;
    }).catch(()=>{pending=null;return null;});
    return pending;
  };
  const view=Object.create(game);view.textures=textures;
  return {game:view,dispose(){disposed=true;owned?.dispose();owned=null;}};
}

// Category remains associated with each target to preserve the existing priority rules.
const QUEST_PROGRESS_CODE2 = {
  main: 13,      // 메인 퀘스트 진행
  growth: 16,    // 메인 2 퀘스트 진행 (성장 동선)
  daily: 6,      // 일일 퀘스트 진행
  weekday: 6,
  ticket: 6,
  weekly: 6,
  repeat: 6,
  request: 2,
  wanted: 2,
  normal: 2,     // 일반 진행
};

export class QuestMarks {
  constructor(sys) {
    this.sys = sys;
    this.game = sys.game;
    this.marks = new Map();     // npc actor -> {state, group, anim, glows, t}
    this.huntMarks = new Map(); // monster actor -> {key, handle, code2}
    this._huntFx = null;
    this._huntData = null;
    this._huntTexture = null;
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

  /**
   * Living monsters that match existing incomplete hunt-target rules. Category priority
   * and attachment are engine behavior, not established native selection logic.
   */
  _huntTargets() {
    const eng = this.eng;
    const map = Number(eng.mapIndex);
    const byMonster = new Map(); // monsterIndex -> { code2, anyMap:boolean } ; anyMap false + mapMatches for killOnMap
    const killOnMap = new Set(); // when set, every living monster on this map is huntable
    let killOnMapCode2 = 2;
    const catRank = { main: 4, growth: 3, daily: 2, weekday: 2, ticket: 2, weekly: 2, repeat: 2, request: 1, wanted: 1, normal: 1 };
    const prefer = (cur, cat, code2) => {
      const r = catRank[cat] || 1;
      if (!cur || r > (cur._rank || 0)) return { code2, _rank: r, cat };
      return cur;
    };
    for (const id of eng.activeIds()) {
      const q = this.db.quest(id);
      if (!q) continue;
      const cat = q.cat || 'normal';
      const code2 = QUEST_PROGRESS_CODE2[cat] ?? QUEST_PROGRESS_CODE2.normal;
      const qMap = q.require?.map;
      for (const o of q.objectives || []) {
        if (eng.objectiveDone(q, o)) continue;
        const om = o.map ?? qMap;
        if (om != null && Number(om) !== map) continue;
        if (o.kind === 'kill') {
          for (const t of o.targets || []) {
            const mi = Number(t.id);
            if (!Number.isFinite(mi)) continue;
            byMonster.set(mi, prefer(byMonster.get(mi), cat, code2));
          }
          if (Array.isArray(o.range) && o.range.length >= 2) {
            const [a, b] = o.range.map(Number);
            for (let mi = a; mi <= b; mi++) byMonster.set(mi, prefer(byMonster.get(mi), cat, code2));
          }
        } else if (o.kind === 'killOnMap') {
          const hit = (o.targets || []).some(t => Number(t.id) === map);
          if (hit) {
            killOnMap.add(true);
            const cur = prefer({ code2: killOnMapCode2, _rank: 0 }, cat, code2);
            killOnMapCode2 = cur.code2;
          }
        } else {
          const binding = nativeKillBinding(id, o);
          if (binding && (binding.map == null || Number(binding.map) === map)) {
            for (const mi of binding.monsters) byMonster.set(Number(mi), prefer(byMonster.get(Number(mi)), cat, code2));
          }
        }
      }
    }
    return { byMonster, killOnMap: killOnMap.size > 0, killOnMapCode2 };
  }

  _questProgressRef() { return MONSTER_QUEST_REF; }

  _ensureHuntFx() {
    const data = this.game.skills?.data;
    if (!data) return null;
    if (this._huntData !== data) {
      this._huntFx?.dispose?.();
      this._huntTexture?.dispose();
      this._huntData = data;
      this._huntTexture=monsterQuestTextureView(this.game);
      this._huntFx = new EffectPlayer(this._huntTexture.game, monsterQuestEffectData(data));
      this._huntFx.soundOn = false;
      this._huntFx.root.name = 'quest hunt marks';
    }
    return this._huntFx;
  }

  refresh() {
    this._dirty = false;
    const npcs = this.game.npcs || [];
    const alive = new Set(npcs);
    for (const [npc, m] of this.marks) if (!alive.has(npc) || npc.disposed) { this._drop(m); this.marks.delete(npc); }
    for (const npc of npcs) {
      const st = this.stateOf(npc);
      const cur = this.marks.get(npc);
      if (cur && cur.state === st?.state && !(cur.native && nativeQuestMarkCode2(cur.state, cur.cat) !== nativeQuestMarkCode2(st.state, st?.cat))) { cur.cat = st?.cat; continue; } // gfx-B: native colour follows the quest line
      if (cur) { this._drop(cur); this.marks.delete(npc); }
      if (st) {
        const m = { state: st.state, cat: st.cat, group: new THREE.Group(), glows: [], anim: null, t: Math.random() * LOOP_MS / 1000 };
        m.group.name = `questmark:${st.state}`;
        this.marks.set(npc, m);
        if (gfxB('questMarkNative')) { m.native = true; this._buildNative(npc, m).catch(err => console.warn('[quests] native mark', err)); } // gfx-B
        else this._build(npc, m).catch(err => console.warn('[quests] mark', err));
      }
    }
    this._refreshHuntMarks();
    this.syncMinimap();
  }

  _refreshHuntMarks() {
    const g = this.game;
    const monsters = g.network?.active ? [...(g.network.monsters?.values?.() || [])] : (g.spawner?.monsters || []);
    const { byMonster, killOnMap, killOnMapCode2 } = this._huntTargets();
    const fx = this._ensureHuntFx();
    const keep = new Set();
    for (const mon of monsters) {
      if (!mon || mon.disposed || mon.dead || mon.kind !== 'monster') continue;
      const mi = Number(mon.monsterIndex ?? mon.def?.index ?? mon.index);
      if (!Number.isFinite(mi)) continue;
      let code2 = null;
      const hit = byMonster.get(mi);
      if (hit) code2 = hit.code2;
      else if (killOnMap) code2 = killOnMapCode2;
      else continue;
      keep.add(mon);
      const cur = this.huntMarks.get(mon);
      if (cur && cur.code2 === code2 && cur.handle && !cur.handle.done) continue;
      if (cur) { cur.handle?.stop?.(true); this.huntMarks.delete(mon); }
      if (!fx) continue;
      const ref = this._questProgressRef(code2);
      if (!ref) continue;
      // Inferred placement: keep the existing top attachment until native placement is verified.
      const handle = fx.play(mon, ref, { bone: 'top', scale: 1, particleSpace: 'attachment' });
      if (handle) this.huntMarks.set(mon, { code2, handle });
    }
    for (const [mon, cur] of this.huntMarks) {
      if (!keep.has(mon) || mon.disposed || mon.dead) {
        cur.handle?.stop?.(true);
        this.huntMarks.delete(mon);
      }
    }
  }

  // ---- gfx-B begin: Global modeleffect 18 quest mark through the shared EffectPlayer path ----
  _nativeFx() {
    if (!this._npcFx) {
      this._npcData ||= this.game.items?.authoredEffects?.data || new AuthoredEffectsData();
      this._npcFx = new EffectPlayer(this.game, this._npcData);
      this._npcFx.soundOn = false;
      this._npcFx.root.name = 'quest npc marks (modeleffect 18)';
    }
    return this._npcFx;
  }
  async _nativeMarkRef(state, cat) {
    const fx = this._nativeFx();
    if (!this._nativeRows) this._nativeRows = fx.data.file('script/effect/modeleffect.csv').then(nativeQuestMarkRows).catch(err => { this._nativeRows = null; throw err; });
    const code2 = nativeQuestMarkCode2(state, cat);
    return code2 == null ? null : (await this._nativeRows).get(code2) || null;
  }
  async _buildNative(npc, m) {
    const ref = await this._nativeMarkRef(m.state, m.cat);
    if (!ref || this.marks.get(npc) !== m) return;
    const fx = this._nativeFx();
    await fx.data.load(ref);
    if (this.marks.get(npc) !== m || !fx.data.scene(`${ref.cate}:${ref.id}`)) return;
    // the mark follows the NPC and hides with it (attachmentVisible); every other field is read through from the NPC
    const owner = Object.create(npc, { attachmentVisible: { get: () => !npc.culled && npc.group?.visible !== false } });
    m.ref = ref; m.owner = owner;
    // Authored effectscene controls use bonename "top"; hunt marks already use attachment.
    // particleSpace attachment + bone top keep the mark on the NPC and share Lane 2 continuous loop retention.
    m.handle = fx.play(owner, ref, { loop: true, bone: 'top', particleSpace: 'attachment' });
  }
  // ---- gfx-B end ----
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
      if (!tex) continue; // Missing additive textures must never become a white sprite.
      const mat = new THREE.SpriteMaterial({ map: tex, transparent: true, opacity: gl.alpha, ...fxBlendFields('add'), depthWrite: false, color: 0xffffff });
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
        // Readability adjustment for the available scroll in this renderer: its base DDS is opaque.
        // Draw that base over the scene, then retain a restrained additive highlight. Global parity is unverified.
        const readableScroll = m.state === 'available';
        return new THREE.MeshBasicMaterial({ map: o?.map || null, transparent: true, depthWrite: false, ...fxBlendFields(readableScroll && !glow && o?.map ? 'modulate' : 'add'), side: THREE.DoubleSide, opacity: readableScroll ? (glow ? 0.15 : 1) : (glow ? 1 : 0.3), color: nullTextureColor(o?.map, THREE.CustomBlending) });
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
      let p;
      p = models ? models.loadSkinned({ skelKey: u.skel, parts: [{ meshKey: u.mesh, tpackKey: u.tpack }, { meshKey: u.mesh, tpackKey: u.tpackGlow }] })
        .catch(err => {
          // Transient transport must not poison the outer Map (CLIP-LOADING-EVIDENCE).
          if (err?.transient && this._models.get(name) === p) this._models.delete(name);
          else console.warn('[quests] mark model', name, err);
          return null;
        }) : Promise.resolve(null);
      this._models.set(name, p);
    }
    return this._models.get(name);
  }
  _clip(name, model) {
    if (!this._clips.has(name)) {
      let p;
      p = this.game.models.loadClipWithStatus(UNIT.mesh(name).anim, model, { duration: LOOP_MS / 1000 })
        .catch(err => {
          if (err?.transient && this._clips.get(name) === p) this._clips.delete(name);
          return null;
        });
      this._clips.set(name, p);
    }
    return this._clips.get(name);
  }
  _texture(key) {
    if (!this._tex.has(key)) {
      let p;
      // textures.load resolves null (never rejects). Transient failures are evicted from
      // TextureCache; permanent misses keep a settled-null promise. Mirror that here.
      p = Promise.resolve().then(async () => {
        const textures = this.game.textures;
        if (!textures?.load) return null;
        const tex = await textures.load(key, { repeat: false });
        if (!tex) {
          const nk = String(key).replace(/\\/g, '/').toLowerCase();
          const still = [...(textures._cache?.keys?.() || [])].some(ck => String(ck).startsWith(`${nk}|`));
          if (!still && this._tex.get(key) === p) this._tex.delete(key);
        }
        return tex || null;
      }).catch(() => {
        if (this._tex.get(key) === p) this._tex.delete(key);
        return null;
      });
      this._tex.set(key, p);
    }
    return this._tex.get(key);
  }

  _drop(m) {
    m.handle?.stop?.(true); m.handle = null; // gfx-B
    m.group.parent?.remove(m.group);
    m.anim?.dispose?.();
    for (const gl of m.glows) gl.sp.material.dispose();
    m.inst?.dispose?.();
  }
  clear() {
    for (const m of this.marks.values()) this._drop(m);
    this.marks.clear();
    for (const cur of this.huntMarks.values()) cur.handle?.stop?.(true);
    this.huntMarks.clear();
    this._huntFx?.dispose?.();this._huntFx=null;this._huntData=null;
    this._npcFx?.dispose?.(); this._npcFx = null; // gfx-B
    this._huntTexture?.dispose();this._huntTexture=null;
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
    // gfx-B: native NPC marks (looping ScenePlays) - re-arm a dropped one, then advance their player once per frame
    if (this._npcFx) {
      for (const [npc, m] of this.marks) if (m.native && m.ref && m.owner && (!m.handle || m.handle.done) && !npc.disposed) m.handle = this._npcFx.play(m.owner, m.ref, { loop: true, bone: 'top', particleSpace: 'attachment' });
      this._npcFx.update(Math.max(0, Number(dt) || 0));
    }
    // Restart finished persistent hunt marks (loop 0 keeps the ScenePlay until stop; still re-arm if dropped).
    if (this.huntMarks.size) {
      for (const [mon, cur] of this.huntMarks) {
        if (mon.disposed || mon.dead) { cur.handle?.stop?.(true); this.huntMarks.delete(mon); continue; }
        if (!cur.handle || cur.handle.done) {
          const fx = this._ensureHuntFx();
          const ref = this._questProgressRef(cur.code2);
          if (fx && ref) cur.handle = fx.play(mon, ref, { bone: 'top', scale: 1, particleSpace: 'attachment' });
        }
      }
      this._huntFx?.update?.(Math.max(0, Number(dt) || 0));
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
