// Base of every event run (one per event map visit): phases with timers, map messages, bricks, scripted waves,
// score, teleports, the exit / kick, and cleanup. Subclasses: deadfront.js, icecastle.js, arena.js, infinite.js,
// defense.js, wreck.js, shackles.js, fieldboss.js, pvp.js.
import { BrickSet } from './bricks.js';
import { Waves } from './waves.js';

export class EventRun {
  /**
   * @param sys   events system (data, ui, msg, dialog)
   * @param map   event map index
   * @param opts  { entry: how the player came in (officer, npc, gm, schedule), team }
   */
  constructor(sys, map, opts = {}) {
    this.sys = sys;
    this.game = sys.game;
    this.data = sys.data;
    this.ui = sys.ui;
    this.msg = sys.msg;
    this.map = Number(map);
    this.info = this.data.map(this.map) || {};
    this.opts = opts;
    this.phase = null;
    this.phaseT = 0;
    this.phaseLen = 0;
    this.score = 0;
    this.ended = false;
    this.started = false;
    this.bricks = new BrickSet(this.game, this.data, this.map);
    this.waves = new Waves(this.game);
    this.timers = [];     // [{t, fn}]
    this.flags = new Set();
  }

  get player() { return this.game.player; }
  get time() { return this.game.time || 0; }

  /** Called once the map is loaded and the player is placed. */
  async start() { this.started = true; }

  // ---------------------------------------------------------------------------------------- messages
  /** Say a map-table code (stringtable of this map). */
  say(code, opts = {}) {
    const e = this.data.mapStr(this.map, code);
    if (e) this.msg.say(e, opts);
    return e;
  }
  sayIn(file, cate, code, opts = {}) {
    const e = this.data.str(file, cate, code);
    if (e) this.msg.say(e, opts);
    return e;
  }
  text(code, dflt = '') { return this.data.mapTxt(this.map, code, dflt); }

  // ---------------------------------------------------------------------------------------- timers
  after(sec, fn) { const t = { t: sec, fn }; this.timers.push(t); return t; }
  setPhase(id, sec) {
    this.phase = id;
    this.phaseLen = sec;
    this.phaseT = sec;
    this.onPhase?.(id);
  }

  update(dt, clockDt = dt) {
    if (this.ended) return;
    if (this.phaseT > 0) {
      this.phaseT = Math.max(0, this.phaseT - clockDt);
      if (this.phaseT <= 0) this.onPhaseEnd?.(this.phase);
    }
    for (const t of this.timers.slice()) {
      t.t -= clockDt;
      if (t.t <= 0) { this.timers.splice(this.timers.indexOf(t), 1); try { t.fn(); } catch (err) { console.error('[events] timer', err); } }
    }
    this.bricks.update(dt);
    this.tick?.(dt);
  }

  // ---------------------------------------------------------------------------------------- movement
  /** Move the player on this map (or to another map: that ends the run). point = {map?, x, z}. */
  teleport(p) {
    if (!p) return Promise.resolve();
    const map = p.map ?? this.map;
    if (Number(map) !== this.map) return this.leave(p);
    return this.game.travel(this.map, { x: p.x, z: p.z, dirDeg: p.dirDeg ?? 0 });
  }
  /** Leave the event map to `p` ({map, x, z}); the run ends when the map changes. */
  leave(p) {
    this.leaving = true;
    return this.game.travel(p.map, p.x != null ? { x: p.x, z: p.z, dirDeg: p.dirDeg ?? 0 } : null);
  }

  // ---------------------------------------------------------------------------------------- hooks (subclasses)
  /** An NPC of this map was clicked: return a dialog page (dialog.js) or null for the default dialog. */
  npcPage() { return null; }
  onDeath() {}
  onDamage() {}
  /** Where "Revive in town" sends a dead player on this map (null = the game's default). */
  respawnTarget() { return null; }

  // ---------------------------------------------------------------------------------------- end
  end(reason = 'end') {
    if (this.ended) return;
    this.ended = true;
    this.endReason = reason;
    try { this.onEnd?.(reason); } catch (err) { console.error('[events] onEnd', err); }
    this.timers = [];
    this.waves.dispose();
    this.bricks.dispose();
    this.ui?.closeAll();
  }
}
