// Scripted monster groups (call-monster waves, bosses, treasure boxes) of the event maps.
// docs/formats/events.md §2.4 / §8.2: calls[k] = [[monster, x, y, radius(cells), count], ...] (integer cells: stand at
// x + 0.5, y + 0.5). Each group becomes spawner records (src/game/spawner.js) that never respawn; the spawner still
// builds the monsters lazily around the player (nearest first, load-limited). Spawned group monsters are `persistent`
// (never deactivated) and can get a custom brain. A group is done when every one of its monsters has died (or was
// removed by the script, e.g. a tower attacker that reached the tower).
import { MonsterBrain } from '../../game/ai.js';

let SEQ = 0;
const num = (v, d = 0) => { const x = Number(v); return Number.isFinite(x) ? x : d; };

export class Waves {
  constructor(game) {
    this.game = game;
    this.groups = new Map();     // key -> group
    this.recs = new Set();
    this._onSpawn = ({ actor }) => this._adopt(actor);
    this._onDeath = ({ actor, killer }) => this._death(actor, killer);
    game.events.on('spawn', this._onSpawn);
    game.events.on('death', this._onDeath);
  }

  /**
   * Spawn a group. rows = [[monster, x, y, radius, count], ...] (call table rows) or [{monster, x, z}].
   * opts: { brain(game, m) -> brain, onKill(m, group), onDone(group), aggressive, tag, center: {x,z} (FILE, exact),
   *         noRespawn (default true), dir }
   */
  spawn(key, rows, opts = {}) {
    const g = { key: key ?? `g${++SEQ}`, recs: [], killed: 0, removed: 0, total: 0, done: false, opts, started: this.game.time || 0 };
    const w = this.game.world;
    for (const r of rows || []) {
      const [monster, x, y, radius, count] = Array.isArray(r) ? r : [r.monster, r.x, r.z ?? r.y, r.radius || 0, r.count || 1];
      const def = this.game.data?.monster?.(monster);
      if (!def) continue;
      const n = Math.max(1, num(count, 1));
      for (let i = 0; i < n; i++) {
        let px = num(x) + (Array.isArray(r) && !r.exact ? 0.5 : 0), pz = num(y) + (Array.isArray(r) && !r.exact ? 0.5 : 0);
        const rad = num(radius);
        if (rad > 0) {
          for (let t = 0; t < 8; t++) {
            const a = Math.random() * Math.PI * 2, d = rad * Math.sqrt(Math.random());
            const qx = px + Math.cos(a) * d, qz = pz + Math.sin(a) * d;
            if (!w || w.isWalkable(qx, qz)) { px = qx; pz = qz; break; }
          }
        }
        if (w && !w.isWalkable(px, pz)) { const s = w.nearestWalkable(px, pz, 6); if (s) { px = s.x; pz = s.z; } }
        const rec = {
          id: `ev${++SEQ}`, spawn: { monsterIndex: Number(monster), x: px, z: pz, respawnSec: 0 }, respawnSec: Infinity,
          monster: null, loading: false, deadAt: null, respawnAt: 0, failedUntil: 0, skip: false,
          event: { group: g, killed: false, removed: false },
        };
        g.recs.push(rec);
        this.recs.add(rec);
        this.game.spawner?.records?.push(rec);
      }
    }
    g.total = g.recs.length;
    this.groups.set(g.key, g);
    if (!g.total) this._finish(g);
    return g;
  }

  group(key) { return this.groups.get(key) || null; }
  /** Monsters of a group that are loaded and alive. */
  live(key) { const g = this.groups.get(key); return g ? g.recs.map(r => r.monster).filter(m => m && !m.dead) : []; }
  /** Remaining (not killed / removed) count of a group. */
  left(key) { const g = this.groups.get(key); return g ? g.total - g.killed - g.removed : 0; }
  isDone(key) { const g = this.groups.get(key); return !!g && g.done; }
  /** Total living (spawned or pending) monsters over every group (accumulation limits). */
  aliveCount(filter = null) {
    let n = 0;
    for (const g of this.groups.values()) { if (filter && !filter(g)) continue; n += g.total - g.killed - g.removed; }
    return n;
  }

  _adopt(m) {
    const rec = m?.spawnRecord;
    if (!rec?.event) return;
    m.persistent = true;
    m.eventGroup = rec.event.group;
    const o = rec.event.group.opts || {};
    if (o.dir != null) m.yaw = (num(o.dir) * Math.PI) / 180;
    if (typeof o.brain === 'function') { try { m.brain = o.brain(this.game, m) || m.brain; } catch (err) { console.warn('[events] brain', err); } }
    // ENGINE-CHOSEN event override: an aggressive wave forces aggression; sight / pursuit are raised ONLY when the caller
    // passes them explicitly (arena / infinite / staged / fieldboss values). No implicit floor: a wave spawned with
    // { aggressive: true } alone keeps the monster's own info.csv ranges (e.g. guild-war-hunting invaders 32 / 38,
    // defense.js; the server's HostWaves applies the same rule in server/world/events.mjs).
    if (o.aggressive && m.brain instanceof MonsterBrain) { m.brain.aggressive = true; if (o.sight > 0) m.brain.sight = Math.max(m.brain.sight, o.sight); if (o.pursuit > 0) m.brain.pursuit = Math.max(m.brain.pursuit, o.pursuit); }
    try { o.onSpawn?.(m, rec.event.group); } catch (err) { console.warn('[events] onSpawn', err); }
  }

  _death(m, killer) {
    const rec = m?.spawnRecord;
    if (!rec?.event || rec.event.killed || rec.event.removed) return;
    rec.event.killed = true;
    const g = rec.event.group;
    g.killed++;
    try { g.opts.onKill?.(m, g, killer); } catch (err) { console.warn('[events] onKill', err); }
    if (g.killed + g.removed >= g.total) this._finish(g);
  }

  /** Take a monster out without a kill (e.g. a tower attacker that reached the tower). */
  removeMonster(m) {
    const rec = m?.spawnRecord;
    if (!rec?.event || rec.event.killed || rec.event.removed) return;
    rec.event.removed = true;
    const g = rec.event.group;
    g.removed++;
    m.dead = true; m.hp = 0; m.faded = m.removable = m.fadeDone = true; m.group.visible = false;
    if (this.game.player?.target === m) { if (this.game.controller?.setTarget) this.game.controller.setTarget(null); else this.game.player.target = null; }
    if (g.killed + g.removed >= g.total) this._finish(g);
  }

  _finish(g) {
    if (g.done) return;
    g.done = true;
    try { g.opts.onDone?.(g); } catch (err) { console.warn('[events] onDone', err); }
  }

  /** Remove a whole group (script end / cleanup). Loaded monsters vanish, pending records are dropped. */
  clearGroup(key) {
    const g = this.groups.get(key);
    if (!g) return;
    const recs = this.game.spawner?.records;
    for (const r of g.recs) {
      if (r.monster && !r.monster.dead) this.removeMonster(r.monster);
      r.skip = true;
      if (recs) { const i = recs.indexOf(r); if (i >= 0) recs.splice(i, 1); }
      this.recs.delete(r);
    }
    this.groups.delete(key);
  }

  dispose() {
    this.game.events.off?.('spawn', this._onSpawn);
    this.game.events.off?.('death', this._onDeath);
    const recs = this.game.spawner?.records;
    if (recs) for (const r of this.recs) { r.skip = true; const i = recs.indexOf(r); if (i >= 0) recs.splice(i, 1); }
    this.recs.clear();
    this.groups.clear();
  }
}

/**
 * Tower attacker (Ice Castle tower defence): marches along a path to `target` and, within `reach` cells, hits the
 * Tower of Shield for `damage` and leaves (onArrive). Fights back like a normal monster when attacked, then resumes
 * the march from where it is.
 */
export class MarchBrain extends MonsterBrain {
  constructor(game, m, { target, reach = 9, onArrive }) {
    super(game, m);
    this.goal = target;
    this.goalReach = reach;
    this.onArrive = onArrive;
    this.path = null;
    this.pi = 0;
    this.repath = 0;
    this.aggressive = false;
  }
  update(dt) {
    const m = this.m;
    if (!m || m.dead) return super.update(dt);
    // fighting back: the normal monster behaviour
    if (this.state === 'chase' || this.state === 'attack' || this.swing || this.flinch > 0) return super.update(dt);
    if (Math.hypot(m.x - this.goal.x, m.z - this.goal.z) <= this.goalReach) { this.onArrive?.(m); return; }
    this.repath -= dt;
    if (!this.path || this.repath <= 0 || this.pi >= this.path.length) {
      this.path = this.game.world?.findPath?.(m.x, m.z, this.goal.x, this.goal.z) || [this.goal];
      this.pi = 0;
      this.repath = 4;
    }
    const p = this.path[this.pi];
    if (!p) return;
    this._loop('run');
    if (this.step(p.x, p.z, this.runSpeed || 3, dt, 0.4)) this.pi++;
    this.home = { x: m.x, z: m.z };      // the brain's pursuit / explore anchor follows the marcher along the road, not its gate
    if (this.stuck > 1.5) { this.repath = 0; this.stuck = 0; }
    this.state = 'idle';
    this.timer = 1e9;
  }
  _loop(state) {
    if (this.m._gpState === state) return;
    this.m._gpState = state; this.m._gpHold = 0;
    this.m.play(state, { loop: true, moveSpeed: (this.runSpeed || 3) * this.speedMul() });
  }
}
