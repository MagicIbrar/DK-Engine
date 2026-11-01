// Bricks: the dynamic map objects of the event maps (gates, barriers, bars, statues, crystals, the Tower of Shield).
// docs/formats/events.md §2.4/§8.1, docs/formats/dungeons.md "Bricks".
//
//   placement  maps[m].bricks[] = [uid, brickIndex, x, y, dirDeg, isCreate, revival, regenCycle]   (FILE frame)
//   def        events.json bricks[brickIndex]: name, maxHP, widthSize x heightSize (blocked cells, rotated by dir),
//              melee/range/physical/magicDamageResist (100 = immune), visual {mesh, tpack}, act {skel, clips[[NAME,len,anim]]}
//
// A brick blocks its footprint in the .mac collision grid (world.collision.cells) while it stands. Removing it plays
// DEAD (destroyed) or OPENBRICK (opened), then frees the cells. Breakable bricks (targetable, min(melee, range) resist
// < 100: fences, statues, crystals, cross bars) are 'monster'-kind actors in the spawner list, so the player can target
// and destroy them with normal combat; resists are applied by the brick's brain (100 = immune to that damage kind).
// Immune bricks (gates, barriers, walls, the tower) are only removed by the event scripts.
import { Actor, bodyRadius } from '../../actors/actor.js';
import {blockCollisionCells} from '../../world/collision-blockers.js';

const num = (v, d = 0) => { const x = Number(v); return Number.isFinite(x) ? x : d; };

/** Is a brick definition destructible by the player? */
export function isBreakable(def) {
  if (!def) return false;
  if (!num(def.targeting, 1) || !num(def.isAttackable, 1)) return false;
  return Math.min(num(def.meleeDamageResist), num(def.rangeDamageResist)) < 100;
}

/** Cells (cx, cz) covered by a brick footprint: w x h centred on (x, z), rotated by dir degrees. */
export function footprintCells(x, z, dirDeg, w, h) {
  w = Math.max(1, num(w, 1)); h = Math.max(1, num(h, 1));
  const a = (num(dirDeg) * Math.PI) / 180;
  const c = Math.cos(a), s = Math.sin(a);
  const R = Math.ceil(Math.hypot(w, h) / 2) + 1;
  const out = [];
  const cx0 = Math.floor(x), cz0 = Math.floor(z);
  for (let dz = -R; dz <= R; dz++) {
    for (let dx = -R; dx <= R; dx++) {
      const px = cx0 + dx + 0.5 - x, pz = cz0 + dz + 0.5 - z;
      // FILE rotation.y = a: local X -> (cos a, -sin a), local Z -> (sin a, cos a)
      const lx = px * c - pz * s, lz = px * s + pz * c;
      if (Math.abs(lx) <= w / 2 + 1e-6 && Math.abs(lz) <= h / 2 + 1e-6) out.push([cx0 + dx, cz0 + dz]);
    }
  }
  if (!out.length) out.push([cx0, cz0]);
  return out;
}

const DEAD_FRONT_MAPS = new Set([39,40,41,42,43,44,60,77,78,79,80,81,82,83,160,161]);
/** Dead Front's authored sizes alternate 4x7 / 7x4 with world orientation, and describe half extents.
 * This interpretation closes the original MAC corridors; the old full-size second rotation left gaps.
 * Native table/geometry reconstruction, not a recovered Global executable collision equation.
 * Invisible magical-field bricks use their authored sizes too; no substitute art is created. */
export function eventBrickFootprintCells(map, row, def) {
  const deadFront = DEAD_FRONT_MAPS.has(Number(map)) && Number(row.uid)>=101 && Number(row.uid)<=142;
  return footprintCells(row.x,row.z??row.y,deadFront?0:row.dir,Math.max(1,num(def?.widthSize,1))*(deadFront?2:1),Math.max(1,num(def?.heightSize,1))*(deadFront?2:1));
}

/** Brain of a breakable brick: never moves or attacks; applies the brick's damage resists. */
class BrickBrain {
  constructor(game, brick) { this.game = game; this.m = brick; this.state = 'idle'; }
  update() {}
  engage() {}
  onDeath() { this.state = 'dead'; }
  onDamaged(attacker, amount, result) {
    const d = this.m.brickDef || {};
    const kind = result?.kind || 'melee';
    const resist = kind === 'magic' ? num(d.magicResist) : kind === 'range' ? num(d.rangeDamageResist) : num(d.meleeDamageResist);
    const phys = kind === 'magic' ? 0 : num(d.physicalResist);
    const r = Math.min(100, Math.max(resist, phys)) / 100;
    if (r > 0 && amount > 0 && !this.m.dead) this.m.hp = Math.min(this.m.maxHp, this.m.hp + Math.round(amount * r));
  }
}

export class Brick extends Actor {
  constructor(game, def, pl) {
    const breakable = isBreakable(def);
    super(game, { kind: breakable ? 'monster' : 'brick', name: def?.name || `Brick ${pl.brick}`, level: num(def?.level, 1) });
    this.brickDef = def || {};
    this.uid = pl.uid;
    this.brickIndex = pl.brick;
    this.dirDeg = pl.dir;
    this.breakable = breakable;
    this.persistent = true;              // spawner.js never deactivates it
    this.fadeOnDeath = false;
    this.cullable = true;
    this.maxHp = this.hp = Math.max(1, num(def?.maxHP, num(def?.defaultHP, 1)));
    // combat profile (combat.js defenceProfile reads def.def / guard / resist; kill() grants def.exp, loot rolls def.money)
    const raw = def?.raw || {};
    this.def = {
      index: null, name: this.name, level: this.level, hp: this.maxHp, exp: num(def?.exp), role: 'object',
      def: [0, 0], guard: [num(def?.guardRate), num(def?.guardEfficiency)], resist: [],
      money: raw.Money_Rate ? [num(raw.Money_Min), num(raw.Money_Max), num(raw.Money_Rate)] : null,
      speed: [0, 0], brick: true,
    };
    this.cells = [];
    this.blocking = false;
    this.removed = false;
    this.yaw = (num(pl.dir) * Math.PI) / 180;
    this.setPosition(num(pl.x), num(pl.z ?? pl.y));
    if (breakable) this.brain = new BrickBrain(game, this);
  }

  _clip(name) {
    const c = (this.brickDef.act?.clips || []).find(e => e[0] === name);
    return c && c[2] ? { key: c[2], duration: num(c[1]) > 0 ? num(c[1]) : null } : null;
  }

  async _load() {
    const v = this.brickDef.visual, act = this.brickDef.act;
    const models = this.game?.models;
    if (!v?.mesh || !models) { this.height = 2; this.radius = 1; return; }
    const part = { meshKey: v.mesh, tpackKey: v.tpack || null };
    let model = null;
    if (act?.skel) model = await models.loadSkinned({ skelKey: act.skel, parts: [part] }).catch(() => null);
    if (this.disposed) return;
    if (model) this._setSkinned(model);
    else {
      const st = await models.loadStatic(v.mesh, { tpackKey: v.tpack || null }).catch(() => null);
      if (this.disposed) return;
      if (st) this._setStatic(st);
    }
    const m = this.model;
    if (m?.bbox && !m.bbox.isEmpty()) {
      this.height = Math.max(0.5, m.height || m.bbox.max.y || 2);
      this.radius = Math.max(bodyRadius(m.bbox), Math.min(3, Math.max(num(this.brickDef.widthSize), num(this.brickDef.heightSize)) * 0.4));
    } else { this.height = 2; this.radius = 1; }
    await this._preload([['idle']]);
  }

  _specFor(state) {
    const stand = this._clip('STAND') || this._clip('CLOSEBRICK');
    switch (state) {
      case 'idle': case 'idleCombat': return stand ? { ...stand, loop: true } : null;
      case 'die': { const c = this._clip('DEAD'); return c ? { ...c, loop: false } : null; }
      case 'open': { const c = this._clip('OPENBRICK'); return c ? { ...c, loop: false } : null; }
      case 'close': { const c = this._clip('CLOSEBRICK'); return c ? { ...c, loop: false } : null; }
      default: return null;
    }
  }
  _restState() { return this.dead || this.removed ? null : 'idle'; }

  /** Block the footprint cells (remembering what was there). */
  block(collision) {
    if (this.blocking || !collision?.cells) return;
    const d = this.brickDef;
    this.cells = eventBrickFootprintCells(this.game.world?.info?.index,{uid:this.uid,x:this.x,z:this.z,dir:this.dirDeg},d)
      .filter(([cx, cz]) => cx >= 0 && cz >= 0 && cx < collision.width && cz < collision.height)
      .map(([cx, cz]) => { const i = cz * collision.width + cx; return [i, collision.cells[i]]; });
    this._releaseCollision=blockCollisionCells(collision,this.cells.map(([i])=>i));
    this._col = collision;
    this.blocking = true;
  }
  /** Free the footprint cells. */
  unblock() {
    if (!this.blocking) return;
    this._releaseCollision?.();this._releaseCollision=null;
    this.blocking = false;
  }
  dispose(){this.unblock();super.dispose();}
}

/** All bricks of the current event map. */
export class BrickSet {
  constructor(game, data, mapIndex) {
    this.game = game;
    this.data = data;
    this.map = mapIndex;
    this.byUid = new Map();       // uid -> Brick (standing or removed)
    this.placements = new Map();  // uid -> placement
    this.own = [];                // non-spawner bricks (updated here)
    for (const r of data.map(mapIndex)?.bricks || []) {
      const [uid, brick, x, y, dir, isCreate, revival, regen] = r;
      this.placements.set(uid, { uid, brick, x, z: y, dir, isCreate, revival, regen });
    }
  }

  /** Placement rows (optionally filtered). */
  rows(filter = () => true) { return [...this.placements.values()].filter(filter); }

  /** Create (and block) a brick by uid; resolves the Brick. Already standing = no-op. */
  async spawn(uid) {
    const pl = this.placements.get(uid);
    if (!pl) return null;
    const cur = this.byUid.get(uid);
    if (cur && !cur.removed && !cur.dead) return cur;
    const def = this.data.brick(pl.brick);
    if (!def) return null;
    const b = new Brick(this.game, def, pl);
    this.byUid.set(uid, b);
    b.block(this.game.world?.collision);
    if (b.breakable && this.game.spawner) this.game.spawner.monsters.push(b);
    else this.own.push(b);
    await b.load();
    return b;
  }
  /** Spawn several (parallel). */
  spawnAll(uids) { return Promise.all([...uids].map(u => this.spawn(u))); }
  /** Every IsCreate 1 brick (the ones present when the map loads). */
  spawnInitial() { return this.spawnAll(this.rows(p => Number(p.isCreate) === 1).map(p => p.uid)); }

  get(uid) { return this.byUid.get(uid) || null; }
  standing(uid) { const b = this.byUid.get(uid); return !!b && !b.removed && !b.dead; }

  /** Remove a brick: 'die' (DEAD clip) or 'open' (OPENBRICK), then free its cells. */
  remove(uid, how = 'die') {
    const b = this.byUid.get(uid);
    if (!b || b.removed) return false;
    b.removed = true;
    b.unblock();
    const clip = b._specFor(how);
    const vanish = () => { if (how === 'die' && !b.disposed) { b.group.visible = false; b._cullHidden = false; } };
    if (clip) b.play(how, { loop: false, onEnd: () => setTimeout(vanish, 400) });
    else vanish();
    if (b.breakable && !b.dead) { b.dead = true; b.hp = 0; }
    return true;
  }
  removeAll(uids, how = 'die') { for (const u of uids) this.remove(u, how); }

  /** A breakable brick died in combat: free its cells. */
  onDeath(actor) {
    if (!(actor instanceof Brick)) return null;
    actor.removed = true;
    actor.unblock();
    return actor;
  }

  update(dt) { for (const b of this.own) b.update(dt); }

  dispose() {
    for (const b of this.byUid.values()) {
      b.unblock();
      if (b.breakable) {
        const list = this.game.spawner?.monsters;
        const i = list ? list.indexOf(b) : -1;
        if (i >= 0) list.splice(i, 1);
      }
      if (this.game.player?.target === b) { if (this.game.controller?.setTarget) this.game.controller.setTarget(null); else this.game.player.target = null; }
      b.dispose();
    }
    this.byUid.clear();
    this.own = [];
  }
}
