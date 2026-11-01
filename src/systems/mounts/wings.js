// Wings: the equipped wing (equipment slot 7) on the character's `weaponW` bone (items.json equipment.wingBone, a child
// of Bip01 Spine1 in every class skeleton), animated with its own action table (share/action/action/item/<Action_Index>)
// in step with the character: STAND rows while standing, MOVE index 0 / 1 while walking / running, on the row of the
// character's current weapon style (fallback style 0). While riding, the wing uses the skeleton of its wingrider table
// (share/action/action/wingrider/<n>.dat) and its authored animation rows/timings. Wings without an action table are rigid meshes in the
// bone's frame (like weapons). docs/MOUNTS.md.
// The rig comes from Action_Index (a share/action/list.csv table). COMPATIBILITY (nativeDispatchVerified:false, docs/WING-BINDING.md):
// an Action_Index-0 wing uses its own per-class, per-item table wing<cls>.act.<itemID>.dat when tools/build-mounts.mjs validated one
// (mounts.json key "i<item>"); without one it stays rigid. A listed table whose skeleton file is absent from Global (e.g. 1070 ->
// wing_equ_ego_2024g_mid.skel) also draws the mesh rigid. How the packed client draws these cases is not observable.
import { Animator } from '../../engine/animator.js';
import { ACT, EQUIP_SLOT } from './data.js';
import { equippedItem } from './riding.js';

const normKey = k => String(k || '').trim().replace(/\\/g, '/').replace(/^\/+/, '').toLowerCase();
const transformedBody = p => !!(p.transformLook || p.transformed || p.transform || Number(p.transUpStage) > 0);

export class WingVisual {
  constructor(sys) {
    this.sys = sys;
    this.game = sys.game;
    this.data = sys.data;
    this.item = null;            // equipped wing item index
    this.w = null;               // { item, riding, object, model, inst, animator, clips, playing }
    this._building = null;
    this.hidden = false;         // hidden by a costume that hides wings (none in the data) or a transformation
  }

  get player() { return this.game.player; }

  /** The wing item whose LOOK is shown: the equipped wing, or its appearance (wing shape change window). */
  equipped() {
    const held = this.game.items?.invState?.held;
    if (held?.from === 'equip' && held.slot === EQUIP_SLOT.wing && held.preset === this.game.items.equip.data.active) return null;
    const e = equippedItem(this.game, EQUIP_SLOT.wing, 'wing');
    if (e && this.data.wing(e.index)) {
      const app = Number(e.inst?.appearance) || 0;
      return app && this.data.wing(app) ? app : e.index;
    }
    return this.sys.testWing && this.data.wing(this.sys.testWing) ? this.sys.testWing : null;
  }

  update(dt) {
    const p = this.player;
    if (!p || !p.instance || p.disposed) { this._building = null; if (this.w) this._remove(); return; }
    const item = this.equipped();
    const riding = !!this.sys.riding?.active;
    // another system already hangs a wing on the bone (e.g. a future items-system look): do not draw a second one
    const bone = p.instance.getBone?.(this.data.core?.wingBone || 'weaponW');
    const foreign = bone?.children?.some(o => !o.isBone && !o.userData?.mountsWing);
    const info = item != null ? this.data.wing(item) : null;
    // Equipment stays owned, but wings must not overlay the temporary Trans Up body.
    const blocked = transformedBody(p) || (info?.design && p.dead);
    const need = item != null && !this.hidden && !foreign && !blocked;
    const cur = this.w;
    // (re)build on change: other wing, rebuilt character (refreshAppearance), mounted skeleton switch
    if (!need) { this._building = null; if (cur) this._remove(); return; }
    const skelFor = r => (r && info.table?.riderSkel) || info.table?.skel || null;
    if (!cur || cur.item !== item || cur.player !== p || cur.skel !== skelFor(riding) || !cur.object.parent || !this._attachedTo(cur, p)) {
      if (this._building?.item === item && this._building.skel === skelFor(riding) && this._building.player === p && this._building.instance === p.instance) return;
      this._build(p, item, info, skelFor(riding));
      return;
    }
    if (cur.motion) { cur.motion.bindEffects?.(this.game); cur.motion.setEffectsVisible?.(!p.culled); }
    if (!p.culled) this._animate(cur, dt);
  }

  _attachedTo(w, p) {
    let o = w.object.parent;
    while (o) { if (o === p.instance.root) return true; o = o.parent; }
    return false;
  }

  async _build(p, item, info, skel) {
    const token = { item, skel, player: p, instance: p.instance };
    this._building = token;
    const models = this.game.models;
    const a = info.asset;
    let w = null;
    try {
      if (skel) {
        const model = await models.loadSkinned({ skelKey: skel, parts: [{ meshKey: a.mesh, tpackKey: a.tpack || null, textures: a.textures || null }] });
        if (model && !model.empty) {
          const inst = model.instantiate();
          w = { item, skel, player: p, model, inst, object: inst.root, animator: new Animator(inst), table: info.table, clips: new Map(), playing: null };
        }
      }
      if (!w) {
        const sm = await models.loadStatic(a.mesh, { tpackKey: a.tpack || null, textures: a.textures || null, twoSide: true });
        if (sm) { const object = sm.instantiate(); w = { item, skel: skel || null, player: p, model: sm, object, motion: object.userData.wingMotion || null, design: info.design || null, table: null, clips: new Map(), playing: null }; }
      }
    } catch (err) { console.warn('[mounts] wing build failed', item, err); }
    if (this._building !== token || p.disposed || p.instance !== token.instance || this.equipped() !== item || this.hidden || transformedBody(p) || (info.design && p.dead)) { if (this._building === token) this._building = null; this._disposeW(w); return; }
    this._building = null;
    if (!w) return;
    this._remove();
    w.object.name = `wing:${item}`;
    w.object.userData.mountsWing = true;
    w.object.traverse(o => { if (o.isMesh) { o.castShadow = true; o.receiveShadow = false; } });
    const bone = this.data.core?.wingBone || 'weaponW';
    if (!p.instance || !p.instance.attach(w.object, bone)) { console.warn('[mounts] no wing bone', bone); this._disposeW(w); return; }
    this.w = w;
    this.item = item;
    this._animate(w, 0);
  }

  _animate(w, dt) {
    const p = this.player;
    if (w.motion) { w.motion.bindEffects?.(this.game); w.motion.update(dt, { moving: p.state === 'run' || p.state === 'walk', riding: !!this.sys.riding?.active, dead: !!p.dead }); return; }
    if (!w.animator) return;
    const riding = !!this.sys.riding?.active;
    const st = p.state;
    const riderRows = riding && w.table?.riderRows;
    const moving = (!riding || !!riderRows) && (st === 'run' || st === 'walk');
    const action = moving ? ACT.MOVE : ACT.STAND;
    const index = moving ? (st === 'walk' ? 0 : 1) : 0;
    const style = riding ? 0 : Number(p.clipSpec?.style ?? (p.stance === 'peace' ? 0 : p.classDef?.style ?? 0)) || 0;
    const key = `${riderRows ? 'rider' : 'item'}:${action}:${index}:${style}`;
    if (w.playing !== key) {
      w.playing = key;
      const e = this._clip(w, action, index, style, !!riderRows);
      const go = () => { if (this.w === w && w.playing === key && e.clip) w.animator.play(e.clip, { loop: true, fade: 0.2 }); };
      if (e.done) go(); else e.promise.then(go);
    }
    // The selected wing/wingrider row already supplies its own TimeLength in
    // _clip. Player locomotion rate corrects the body's planted feet; copying it
    // here accelerates the wing rig (and its effect attachment bones) under a
    // movement buff, while the separately authored effect scene keeps normal time.
    const cur = w.animator.current;
    if (cur && cur.timeScale !== 1) cur.timeScale = 1;
    w.animator.update(dt > 0 ? dt : 0);
  }

  _clip(w, action, index, style, riding = false) {
    const k = `${riding ? 'rider' : 'item'}:${action}:${index}:${style}`;
    if (w.clips.has(k)) return w.clips.get(k);
    const table = riding ? { rows: w.table.riderRows } : w.table;
    const row = this.data.row(table, action, index, style);
    const e = { done: false, clip: null };
    e.promise = row ? Promise.resolve(this.game.models.loadClip(normKey(row.anim), w.model, { duration: row.timeLength })).catch(() => null)
      .then(c => { e.clip = c || null; e.done = true; return e; }) : Promise.resolve((e.done = true, e));
    w.clips.set(k, e);
    return e;
  }

  _remove() {
    const w = this.w;
    this.w = null;
    this.item = null;
    if (!w) return;
    try { w.player?.instance?.detach?.(w.object); } catch { /* ignore */ }
    this._disposeW(w);
  }

  _disposeW(w) {
    if (!w) return;
    try { w.animator?.dispose(); } catch { /* ignore */ }
    try { w.inst?.dispose(); } catch { /* ignore */ }
    try { w.motion?.dispose(); } catch { /* ignore */ }
    w.object?.removeFromParent();
  }

  dispose() { this._building = null; this._remove(); }
}
