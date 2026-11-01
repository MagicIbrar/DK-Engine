// Triggers: clickable state objects of the instance maps (treasure boxes, levers, doors, books):
// share/map/*/TRIGGER_*.csv placed on share/creature/trigger.csv (docs/formats/dungeons.md "Triggers").
//
//   states[k] (1-based in the table: StateChangeNum points at the next state number)
//     {type, index, next, text (gauge caption), ms (StateChangeTime), visible, clickable}
//   clips   STAND_<k> (loop in state k), TRIGGERCHANGE_<k> (played when state k changes)
// A click on a clickable state shows the gauge `text` for `ms` (the player plays the interactive action of
// triggerinteractiveaction.csv when the table gives one), plays TRIGGERCHANGE_k and moves to state `next`.
// Chests roll their triggerdropitem.csv row when opened: cond 'Click' at once, '<map>_KillMainBoss' / '<map>_Siege'
// only after the floor is cleared (the director enables them).
// Triggers are kind 'npc' actors in game.npcs so the controller walks to them on click and game.js updates and
// disposes them; windows.openNpc(trigger) is routed back here by the dungeon system.
import { Actor } from '../../actors/actor.js';

export class Trigger extends Actor {
  constructor(game, def, place, mapIndex) {
    super(game, { kind: 'npc', name: def?.name || 'Trigger', level: 0 });
    this.isDungeonObject = true;
    this.isTrigger = true;
    this.trig = def || {};
    this.place = place || {};
    this.map = mapIndex;
    this.tstate = 1;
    this.busy = false;
    this.locked = false;          // KillMainBoss chests stay locked until the director clears the floor
    this.opened = false;
    this.hp = this.maxHp = 1;
    this.invulnerable = true;
    this.def = { index: -1, name: this.name, jobs: [], roles: [], mapVisible: def?.mapVisible ?? 0, nameVisible: def?.nameVisible ?? 1, minimapColor: def?.minimapColor ?? 0 };
    this.jobs = []; this.roles = [];
    this.yaw = ((Number(place?.dir) || 0) * Math.PI) / 180;
    this.setPosition(Number(place?.x) || 0, Number(place?.y) || 0);
  }

  get stateDef() { return this.trig?.states?.[this.tstate - 1] || null; }
  get clickable() { const s = this.stateDef; return !!s && !!s.clickable && !this.busy && !this.locked && !this.opened; }
  get interactPoint() { const f = this.facing(); return { x: this.x + f.x * 1.2, z: this.z + f.z * 1.2 }; }
  faceTowards() {}

  _clip(name) { return this.trig?.act?.clips?.[name] || null; }

  async _load() {
    const t = this.trig, models = this.game?.models;
    if (!models || !t.mesh) return;
    const skel = t.act?.skel;
    if (skel) {
      const model = await models.loadSkinned({ skelKey: skel, parts: [{ meshKey: t.mesh, tpackKey: t.tpack || null }] });
      if (this.disposed) return;
      if (model && !model.empty) this._setSkinned(model);
    } else {
      const model = await models.loadStatic(t.mesh, { tpackKey: t.tpack || null });
      if (this.disposed) return;
      if (model) this._setStatic(model);
    }
    const m = this.model;
    if (m?.bbox && !m.bbox.isEmpty()) { this.height = Math.max(0.8, m.bbox.max.y); this.radius = Math.max(0.5, Math.min(2.5, (m.bbox.max.x - m.bbox.min.x) * 0.5)); }
    else { this.height = 1.2; this.radius = 0.6; }
  }

  _specFor(state) {
    const s = this.stateDef;
    const k = s?.index > 0 ? s.index : this.tstate;
    if (state === 'idle' || state === 'idleCombat') {
      const c = this._clip(`STAND_${k}`) || this._clip(`STAND_${this.tstate}`) || this._clip('STAND_1');
      return c ? { key: c.anim, duration: c.len > 0 ? c.len : null, loop: true } : null;
    }
    if (state === 'change') {
      const c = this._clip(`TRIGGERCHANGE_${k}`) || this._clip(`TRIGGERCHANGE_${this.tstate}`);
      return c ? { key: c.anim, duration: c.len > 0 ? c.len : null, loop: false } : null;
    }
    return null;
  }

  _restState() { return 'idle'; }

  /** Advance to the next state (after the gauge). Returns the new state number. */
  advance() {
    const s = this.stateDef;
    const next = Number(s?.next) || 0;
    this.play('change', { loop: false, onEnd: () => { if (!this.disposed) this.play('idle', {}); } });
    if (next > 0 && next !== this.tstate) this.tstate = next;
    const ns = this.stateDef;
    if (ns && ns.visible === 0) this.group.visible = false;
    if (!ns || !ns.clickable || next === 0) this.opened = true;
    return this.tstate;
  }
}
