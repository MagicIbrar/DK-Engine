// Bricks: gates, walls and breakable barricades of the instance maps (share/map/*/BRICK_*.csv placed on
// share/creature/brick.csv definitions; docs/formats/dungeons.md "Bricks").
//
//   role 'gate'      immune (resist 100 / 10,000,000 HP): only the map script (the director) opens it: OPENBRICK clip,
//                    then its blocking footprint is removed.
//   role 'wall'      invisible immune blocker (hidden_brick mesh): collision only, removed by the director.
//   role 'breakable' targetable, damaged through the normal combat code (kind 'monster'); melee/range/magic resist %
//                    scales the damage it takes; on death: DEAD clip (or OPENBRICK), exp / dil / item sets, footprint off.
//
// A standing brick blocks `size` = [WidthSize, HeightSize] cells around its position, rotated by Direction (FILE
// frame: local X -> (cos a, -sin a), local Z -> (sin a, cos a); rotation.y = dir), written into the world's collision
// mask (so the player, the monsters and A* all respect it) and restored when it opens.
import { Actor } from '../../actors/actor.js';
import {blockCollisionCells} from '../../world/collision-blockers.js';

const MARGIN = 0.5;   // footprint margin (cells): a 1-cell-thick gate still becomes a solid wall on the grid

/** Cells covered by a brick footprint: [{i, x, z}] (FILE frame cell indices). */
export function footprintCells(world, x, z, dirDeg, size) {
  const col = world?.collision;
  if (!col) return [];
  const w = Math.max(1, Number(size?.[0]) || 1), h = Math.max(1, Number(size?.[1]) || 1);
  const a = (Number(dirDeg) || 0) * Math.PI / 180;
  const ca = Math.cos(a), sa = Math.sin(a);
  const hw = w / 2 + MARGIN, hh = h / 2 + MARGIN;
  const R = Math.ceil(Math.hypot(hw, hh)) + 1;
  const out = [];
  for (let cz = Math.floor(z - R); cz <= Math.floor(z + R); cz++) {
    for (let cx = Math.floor(x - R); cx <= Math.floor(x + R); cx++) {
      if (cx < 0 || cz < 0 || cx >= col.width || cz >= col.height) continue;
      const dx = cx + 0.5 - x, dz = cz + 0.5 - z;
      const lx = dx * ca - dz * sa;       // along local X
      const lz = dx * sa + dz * ca;       // along local Z
      if (Math.abs(lx) <= hw && Math.abs(lz) <= hh) out.push({ i: cz * col.width + cx, x: cx, z: cz });
    }
  }
  return out;
}

export class Brick extends Actor {
  /**
   * @param game
   * @param def    dungeons.json bricks[index]
   * @param place  maps[m].bricks[k] {uid, brick, x, y, dir, create, ...}
   */
  constructor(game, def, place) {
    const breakable = def?.role === 'breakable';
    super(game, { kind: breakable ? 'monster' : 'brick', name: def?.name || 'Brick', level: Number(def?.level) || 1 });
    this.isDungeonObject = true;
    this.isBrick = true;
    this.brick = def || {};
    this.place = place || {};
    this.uid = place?.uid;
    this.breakable = breakable;
    this.cullable = true;
    this.fadeOnDeath = !!def?.disappear;
    this.invulnerable = !breakable;
    this.open = false;
    this.blocked = [];         // [{i, prev}] collision cells this brick set
    const r = def?.resist || {};
    this._resist = { melee: Number(r.melee) || 0, range: Number(r.range) || 0, magic: Number(r.magic) || 0, physical: Number(r.physical) || 0 };
    // monster-shaped definition for combat.js / loot.js (defence, guard, exp, dil, item sets)
    const raw = def?.raw || {};
    this.def = {
      index: -1, brickIndex: place?.brick, name: this.name, level: this.level, hp: def?.hp || 1, exp: Number(def?.exp) || 0,
      def: Array.isArray(def?.def) ? def.def : [0, 0], guard: [Number(raw.GuardRate) || 0, Number(raw.GuardEfficiency) || 0],
      resist: [0, 0, 0, 0, 0, 0, 0, this._resist.magic],
      money: Array.isArray(def?.money) ? def.money : [0, 0, 0],
      drops: { sets: (def?.drops || []).map(([s, ratio]) => [s, ratio, 0]), maxSets: Number(raw.MaxItemSet) || 1 },
      jobs: [], roles: [], mapVisible: 0, nameVisible: def?.showName ? 1 : 0, role: 'brick',
    };
    this.maxHp = Math.max(1, Number(def?.hp) || 1);
    this._hp = Math.max(1, Number(def?.hp0) || this.maxHp);
    this.yaw = ((Number(place?.dir) || 0) * Math.PI) / 180;
    this.setPosition(Number(place?.x) || 0, Number(place?.y) || 0);
  }

  // resist %: the combat code writes hp -= amount; only (100 - resist)% of a decrease is applied
  get hp() { return this._hp ?? 1; }
  set hp(v) {
    v = Number(v);
    if (!Number.isFinite(v)) return;
    const cur = this._hp ?? v;
    if (this._resist && v < cur && !this._forceHp) {
      const res = Math.max(this._resist.physical, 0) / 100;
      v = cur - (cur - v) * Math.max(0, 1 - res);
    }
    this._hp = Math.max(0, v);
  }

  _clip(name) { return this.brick?.act?.clips?.[name] || null; }

  async _load() {
    const d = this.brick, models = this.game?.models;
    if (!models || !d.mesh || d.invisible) return;
    const skel = d.act?.skel;
    if (skel) {
      const model = await models.loadSkinned({ skelKey: skel, parts: [{ meshKey: d.mesh, tpackKey: d.tpack || null }] });
      if (this.disposed) return;
      if (model && !model.empty) this._setSkinned(model);
    } else {
      const model = await models.loadStatic(d.mesh, { tpackKey: d.tpack || null });
      if (this.disposed) return;
      if (model) this._setStatic(model);
    }
    const m = this.model;
    if (m?.bbox && !m.bbox.isEmpty()) { this.height = Math.max(1, m.bbox.max.y); this.radius = Math.max(0.6, Math.min(4, Math.min(m.bbox.max.x - m.bbox.min.x, m.bbox.max.z - m.bbox.min.z) * 0.5)); }
    else { this.height = 2; this.radius = 1; }
  }

  _specFor(state) {
    const c = (n) => { const x = this._clip(n); return x ? { key: x.anim, duration: x.len > 0 ? x.len : null, loop: false } : null; };
    switch (state) {
      case 'idle': case 'idleCombat': {
        const s = this._clip('STAND');
        if (s) return { key: s.anim, duration: s.len > 0 ? s.len : null, loop: true };
        return c('CLOSEBRICK');
      }
      case 'open': return c('OPENBRICK') || c('DEAD');
      case 'close': return c('CLOSEBRICK');
      case 'die': return c('DEAD') || c('OPENBRICK');
      case 'hit': return null;
      default: return null;
    }
  }

  _restState() { return null; }   // hold the last pose (an opened gate stays open)

  _afterLoad() {
    this._snapY(true);
    this._syncGroup();
    if (this.open) this.play('open', { loop: false, startAt: Math.max(0.01, (this._clip('OPENBRICK')?.len || this._clip('DEAD')?.len || 1) - 0.02) });
    else if (!this.dead) this.play('idle', {});
  }

  /** Write the footprint into the world collision mask. */
  block() {
    const w = this.game?.world;
    if (!w?.collision || this.blocked.length || this.open || this.dead) return;
    this.blocked=footprintCells(w, this.x, this.z, this.place?.dir, this.brick?.size);
    this._releaseCollision=blockCollisionCells(w.collision,this.blocked.map(c=>c.i));
    // never trap the player inside the footprint
    const p = this.game.player;
    if (p && !w.collision.isWalkable(p.x, p.z)) {
      const s = w.collision.nearestWalkable(p.x, p.z, 12);
      if (s) p.setPosition(s.x, s.z);
    }
  }

  /** Restore the collision cells this brick blocked. */
  unblock() {
    this._releaseCollision?.();this._releaseCollision=null;
    this.blocked = [];
  }

  /** Director: open the gate (OPENBRICK / DEAD when disappear) and free its cells. */
  openGate() {
    if (this.open || this.dead) return false;
    this.open = true;
    this.unblock();
    if (this.brick?.disappear) this.play('die', { loop: false }); else this.play('open', { loop: false });
    if (this.brick?.invisible) this.group.visible = false;
    this.game?.events?.emit?.('dungeon:brick', { brick: this, open: true });
    return true;
  }

  /** Director: close it again (CLOSEBRICK) and block. */
  closeGate() {
    if (!this.open || this.dead) return false;
    this.open = false;
    this.group.visible = !this.brick?.invisible;
    this.play('close', { loop: false });
    this.block();
    this.game?.events?.emit?.('dungeon:brick', { brick: this, open: false });
    return true;
  }

  /** Called by the director on the 'death' event of a breakable brick. */
  destroyed() {
    this.unblock();
    this.open = true;
  }

  update(dt) {
    super.update(dt);
    if (this.brick?.invisible && this.group.visible) this.group.visible = false;
  }

  dispose() { this.unblock(); super.dispose(); }
}
