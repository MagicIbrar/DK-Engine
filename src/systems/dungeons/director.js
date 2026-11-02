// Dungeon director: the per-instance state machine that plays one floor of an instance map from the client data
// (docs/formats/dungeons.md "Engine requirements"). The server map scripts are not in the client; the director plays
// the builder's inferred flow (maps[m].stages, inferred: 1) plus the per-map plans of scripts.js:
//
//   countdown   (32 "Dungeon Starting") START_COUNTDOWN s  -> 2000 start effect + jingle
//   running     (30 "Running Time") the floor's time limit (code 3); stages spawn through the Spawner:
//                 'populate' dungeons (hallways) spawn every wave at the start, 'sequential' ones (arenas,
//                 infinite battles, grouped floors) one stage / group after the other;
//                 a cleared stage opens its gates (OPENBRICK) with the next 9xx alert;
//                 script bosses appear on their summon NPC (or when the waves are done): 3xx alert + 80x flash,
//                 boss-room create:0 bricks close behind; their death plays the 81x-83x flash and reopens them
//   cleared     1300 cleared effect (+ 930 perfect when nobody died), 920 exit info, (34 "Transfer Time")
//                 TRANSFER_SECONDS: take the next-floor NPC / the exit NPC, else the dungeon closes (KickTo)
//   failed      time out: 3000 failed effect, (39 "Close in") CLOSE_SECONDS, then KickTo
//
// Script NPCs (job 31/80) talk through the original dialog window (dialog.js): label -> dialog code -> menu codes,
// <guage> entries run the select-wait gauge, then the role action (start / bossSummon / interact / warp / exit).
import {
  D, mapInfo, dungeonById, brickDef, triggerDef, message, messageText, messageFx, plain, sysText, monsterName, rng, location, startPos,
} from './data.js';
import { Brick } from './bricks.js';
import { Trigger } from './triggers.js';
import { correctedMapInfo } from './native-row-corrections.js';
import { nativeStageRespawn } from '../../game/native-stage-index.js';
import { serverRefPositions, serverRefSpawnTiming, SERVER_REF } from './server-ref-plans.js';

export const START_COUNTDOWN = 5;
export const TRANSFER_SECONDS = 60;
export const CLOSE_SECONDS = 10;
const POLL = 0.25;
const LOCK_RADIUS = 30;          // create:0 bricks this close to a script boss lock its room
// Lane 65: SQUAD = 3 copies per script monster removed (invented). A Global scriptmonster row is one monster; where
// the older server reference script of the floor spawns it, its Spawn(mon, x, y) cells are used (server-ref-plans.js).

const HALL_BACK = 9;             // ENGINE placement (no Global X/Y): a hallway squad stands this many path cells before its gate
// Lane 65: HALL_SQUAD = 6 monsters per hallway removed (invented): a hallway squad is one of each Global scriptmonster creature.
const ADD_EVERY = 10;            // s between the adds a live spawner object (crystal) calls
const ADD_RANGE = 35;            // the spawner object only calls adds while the player is this close
const STUCK_EVERY = 6;           // s between progress-guard checks (_unstick)
const DOOR_DEPTH = 8;            // a door NPC's doorway: up to this many cells to the walkable floor on each side
const DOOR_HALF = 2.5;           // ... and this many cells to each side of its axis

/** The place a teleport device names: "Sacrifice Chamber Exit" / "To the Sacrifice Chamber" -> "sacrifice chamber". */
function warpBase(name) {
  return String(name || '').toLowerCase().replace(/[^a-z0-9 ]+/g, ' ').replace(/\b(exit|entrance|to|the|of|move|go)\b/g, ' ').replace(/\s+/g, ' ').trim();
}

/** Path distance field (4-neighbour BFS over walkable cells) from (x, z): Int32Array, -1 = unreachable. */
export function pathField(col, x, z) {
  const W = col.width, H = col.height;
  let sx = Math.floor(x), sz = Math.floor(z);
  if (!col.walkableCell?.(sx, sz)) { const n = col.nearestWalkable?.(x, z, 12); if (!n) return null; sx = Math.floor(n.x); sz = Math.floor(n.z); }
  const dist = new Int32Array(W * H).fill(-1);
  const q = new Int32Array(W * H);
  let h = 0, t = 0;
  dist[sz * W + sx] = 0; q[t++] = sz * W + sx;
  while (h < t) {
    const c = q[h++]; const cx = c % W, cz = (c / W) | 0, dc = dist[c] + 1;
    if (cx > 0 && dist[c - 1] < 0 && !col.cells[c - 1]) { dist[c - 1] = dc; q[t++] = c - 1; }
    if (cx < W - 1 && dist[c + 1] < 0 && !col.cells[c + 1]) { dist[c + 1] = dc; q[t++] = c + 1; }
    if (cz > 0 && dist[c - W] < 0 && !col.cells[c - W]) { dist[c - W] = dc; q[t++] = c - W; }
    if (cz < H - 1 && dist[c + W] < 0 && !col.cells[c + W]) { dist[c + W] = dc; q[t++] = c + W; }
  }
  return dist;
}
/** Smallest path distance of the reachable cells within r of (x, z), or -1. */
function fieldMin(field, col, x, z, r) {
  let best = -1;
  for (let cz = Math.floor(z - r); cz <= Math.floor(z + r); cz++) for (let cx = Math.floor(x - r); cx <= Math.floor(x + r); cx++) {
    if (cx < 0 || cz < 0 || cx >= col.width || cz >= col.height) continue;
    const d = field[cz * col.width + cx];
    if (d >= 0 && (best < 0 || d < best)) best = d;
  }
  return best;
}
/** The cell `back` path steps before a gate (path distance gd) nearest to it: [x, z] (cell centre) or null. */
function cellBefore(field, col, gx, gz, gd, back) {
  const want = gd - back, R = back + 6;
  let best = null, bd = Infinity;
  for (let cz = Math.floor(gz - R); cz <= Math.floor(gz + R); cz++) for (let cx = Math.floor(gx - R); cx <= Math.floor(gx + R); cx++) {
    if (cx < 0 || cz < 0 || cx >= col.width || cz >= col.height) continue;
    const d = field[cz * col.width + cx];
    if (d < 0 || Math.abs(d - want) > 1) continue;
    const e = Math.hypot(cx + 0.5 - gx, cz + 0.5 - gz);
    if (e < bd) { bd = e; best = [cx + 0.5, cz + 0.5]; }
  }
  return best;
}

const SEQ_NAME =/infinite|arena|altar|fight|theme park|time attack|stadion|blue hole|colosseum|summon|mazokie's training|cartel|white day|independence/i;

// Exact native ordered-floor crystal associations. Job 501 alone is not a
// next-floor rule; the same job appears on other roles/placements.
const SHIPWRECK_FLOOR_LINKS=Object.freeze([
  [234,235,6111,"Touch the crystal to enter Nepturos' Tomb."],
  [250,251,6175,"Moving to Tritone's Sanctuary."],
  [263,264,6111,"Move to Nepturos' Sanctuary."],
]);
export function nativeShipwreckNextFloor(d,sn){
  return sn?.role==='warp'&&sn.dialog==null&&Number(sn.job?.[0])===31&&Number(sn.job?.[1])===501
    &&d.info?.scriptNpcs?.includes(sn)&&d.floor===0&&d.floors===d.dungeon?.floors
    &&SHIPWRECK_FLOOR_LINKS.some(([from,to,npc,label])=>Number(d.map)===from&&String(d.dungeonId)===String(from)
      &&d.floors.length===2&&Number(d.floors[0])===from&&Number(d.floors[1])===to&&Number(sn.npc)===npc&&sn.label===label);
}

export class Director {
  /**
   * @param sys   the dungeon system (index.js)
   * @param opts  { map, dungeonId, floor }
   */
  constructor(sys, { map, dungeonId, floor = 0 }) {
    this.sys = sys;
    this.game = sys.game;
    this.map = Number(map);
    this.info = correctedMapInfo(this.map, mapInfo(map)) || {};
    this.dungeonId = String(dungeonId);
    this.dungeon = dungeonById(dungeonId) || {};
    this.floor = floor;
    this.floors = this.dungeon.floors || [this.map];
    this.phase = 'countdown';
    this.countdown = START_COUNTDOWN;
    this.elapsed = 0;
    this.limit = Number(this.info.timeLimit?.sec || (floor === 0 ? this.dungeon.timeLimit?.sec : 0)) || 0;
    this.transfer = 0;
    this.closing = 0;
    this.deaths = 0;
    this.kills = 0;
    this.killedIdx = new Map();      // monster index -> kills
    this.spawnedIdx = new Map();     // monster index -> spawned copies
    this.bricks = [];
    this.brickByUid = new Map();
    this.pendingBricks = new Map();  // uid -> placement (create:0, not built)
    this.triggers = [];
    this.used = new Set();           // script NPC indices already operated
    this.alertsUsed = new Set();
    this.extraTimers = [];           // plan timers {caption, sec}
    this._poll = 0;
    this._seq = 0;
    this.name = this.dungeon.name || this.info.name || '';
    this.mapName = this.info.title || this.info.name || this.name;
    this.vars = { mapName: this.mapName, floor: floor + 1, count: 0 };
    this.plan = null;                // scripts.js plan
    this.rand = rng((this.map * 7919 + 17) >>> 0);
  }

  get scriptNpcs() { return this.info.scriptNpcs || []; }
  get messages() { return this.info.messages || {}; }
  get running() { return this.phase === 'running'; }
  get isLastFloor() { return this.floor >= this.floors.length - 1; }
  msg(code) { return message(this.map, code); }
  text(code) { return messageText(this.map, code, this.vars); }

  // ======================================================================================== setup
  async start(plan) {
    this.plan = plan || null;
    const g = this.game;
    // statics of the map (MON_ rows already handed to the spawner by game.enterMap)
    this.statics = (g.spawner?.records || []).filter(r => !r.dg);
    // an instance is populated once: its MON_ rows do not respawn (the floor stays cleared)
    for (const r of this.statics) { this._countSpawn(r.spawn.monsterIndex); r.respawnSec = Infinity; }
    this._layout();
    for (const r of this.statics) {
      const [x, z] = this._placeable(r.spawn.x, r.spawn.z);
      if (x !== r.spawn.x || z !== r.spawn.z) { r.spawn.x = x; r.spawn.z = z; r.monster?.setPosition?.(x, z); if (r.monster) r.monster.home = { x, z }; }
    }
    this._buildStages();
    this._buildMissions();
    await this._buildBricks();
    this._buildTriggers();
    this.waitStart = this.scriptNpcs.some(n => n.role === 'start');
    try { this.plan?.setup?.(this); } catch (err) { console.error('[dungeons] plan setup', err); }
    this._refreshInfo();
    this.sys.ui.alarm(true, true);
    this.sys.ui.openInfo();
    g.events?.emit?.('dungeon:enter', { map: this.map, dungeon: this.dungeonId, floor: this.floor });
  }

  // ---------------------------------------------------------------------------------------- stages
  _buildStages() {
    const inf = this.info;
    const src = inf.stages?.stages || [];
    const waves = new Map((inf.waves || []).map(w => [w.call, w]));
    const bossIdx = new Set((inf.bosses || []).map(b => b.monster));
    this.stages = [];
    for (const s of src) {
      if (s.script) continue;
      const w = waves.get(s.call);
      if (!w) continue;
      this.stages.push({ n: s.n, call: s.call, kind: 'wave', objective: s.objective, rows: w.rows, center: w.center,
        opens: s.opens || [], bosses: s.bosses || [], group: 0, spawned: false, done: false, recs: [] });
    }
    // grouped calls (floor*10+k): one group at a time
    const groups = inf.stages?.groups;
    if (groups?.length) {
      const gOf = new Map();
      groups.forEach((gr, gi) => { for (const c of gr.calls || []) gOf.set(c, gi + 1); });
      for (const st of this.stages) st.group = gOf.get(st.call) || 0;
      // Payment belongs to this instance. Prepared groups are shared by every
      // run; mutating their paid flag would suppress later parties' clear EXP.
      this.groups = groups.map(group=>({...group,paid:false}));
    }
    // Lane 52: no foreign-wave adoption. A floor whose Global call file carries the same rows as a sibling's
    // (Tower of Spell 1F 89 = 2F 90 except the MapIndex header) plays its own file exactly as Global ships it.
    // script monsters: bosses -> summon stage (trigger NPC), others -> a guard squad at their suggested point
    const sSpawns = inf.scriptSpawns || [];
    const scriptBossStage = src.find(s => s.script);
    const bosses = sSpawns.filter(s => s.boss);
    const minions = sSpawns.filter(s => !s.boss);
    const refOf = (m) => serverRefPositions(this.map, m.monster);
    const refRows = minions.flatMap(m => (refOf(m) || []).map(p => [m.monster, p[0], p[1], 0, 1]));
    if (refRows.length) {
      // older server reference: the floor's own script spawns these monsters at these cells; minions it never
      // spawns keep one ENGINE-placed copy at the builder's point
      const rows = [...refRows];
      for (const m of minions) if (!refOf(m) && m.suggest) rows.push([m.monster, m.suggest[0], m.suggest[1], 3, 1]);
      this.stages.push({ n: 900, kind: 'squad', objective: 'kill-all', rows, opens: [], bosses: [], group: 0, spawned: false, done: false, recs: [], atStart: true, source: SERVER_REF });
    } else if (minions.length) {
      const halls = this.stages.length ? null : this._hallwaySquads(minions, bosses);
      if (halls?.length) for (const st of halls) this.stages.push(st);
      else {
        const rows = [];
        for (const m of minions) if (m.suggest) rows.push([m.monster, m.suggest[0], m.suggest[1], 3, 1]);   // ENGINE placement, one per row
        if (rows.length) this.stages.push({ n: 900, kind: 'squad', objective: 'kill-all', rows, opens: [], bosses: [], group: 0, spawned: false, done: false, recs: [], atStart: true });
      }
    }
    if (bosses.length) {
      // older server reference cell (first Spawn call of the boss) where the floor's reference script has one, else ENGINE placement
      const rows = bosses.map(b => { const r = refOf(b)?.[0]; return r ? [b.monster, r[0], r[1], 0, 1] : (b.suggest ? [b.monster, b.suggest[0], b.suggest[1], 0, 1] : null); }).filter(Boolean);
      const trig = scriptBossStage?.trigger || null;
      if (rows.length) this.stages.push({ n: 999, kind: 'boss', objective: 'kill-boss', rows, opens: [], bosses: bosses.map(b => b.monster),
        alert: scriptBossStage?.alert || [], trigger: trig, group: 0, spawned: false, done: false, recs: [], script: true });
    }
    // mode
    const name = `${this.dungeon.name || ''} ${inf.name || ''}`;
    const centers = this.stages.filter(s => s.kind === 'wave' && s.center).map(s => s.center);
    let spread = 0;
    for (let i = 0; i < centers.length; i++) for (let j = i + 1; j < centers.length; j++) spread = Math.max(spread, Math.hypot(centers[i][0] - centers[j][0], centers[i][1] - centers[j][1]));
    this.sequential = !!groups?.length || SEQ_NAME.test(name) || (centers.length > 1 && spread < 25);
    // "Eliminate 200 invaded monsters": looping waves until the kill target (infinite battles)
    const target = (inf.missions || []).map(m => /(\d{2,5})\s+(?:\w+\s+){0,3}monsters?/i.exec(m.text || '')).find(Boolean);
    const waveTotal = this.stages.filter(s => s.kind === 'wave').reduce((a, s) => a + s.rows.reduce((b, r) => b + Math.max(1, r[4] || 1), 0), 0);
    this.killTarget = target && Number(target[1]) > waveTotal ? Number(target[1]) : 0;
    if (this.killTarget) this.sequential = true;
    this.clearDef = inf.stages?.clear || { kind: 'script' };
    // the builder's clear monster can be a hazard with no body (ThunderBlue / lava_safezone / Yogshield_Fire traps):
    // the floor's strongest boss creature(s) then close it (Emperor Baz, Rudene, the four confined creatures)
    if (this.clearDef.kind === 'boss') {
      const mdef = (i) => this.game.data?.monster?.(Number(i)) || null;
      const real = (this.clearDef.monsters || []).filter(i => mdef(i)?.role !== 'invisible');
      if (!real.length) {
        const cand = new Map();
        for (const st of this.stages) for (const r of st.rows) { const m = mdef(r[0]); if (m?.role === 'creature' && (Number(m.rank) || 0) >= 3) cand.set(Number(r[0]), Number(m.rank)); }
        if (cand.size) { const top = Math.max(...cand.values()); this.clearDef = { kind: 'boss', monsters: [...cand].filter(([, r]) => r === top).map(([i]) => i), derived: true }; }
        else this.clearDef = { kind: 'all-waves' };
      }
    }
  }

  /**
   * Floors whose only monster data is the script monster list (no call waves): one guard squad per hallway gate
   * (closed gate bricks in path order from the start, the gate the start lever opens and the boss-room gates
   * excluded), each standing HALL_BACK cells before its gate on the start side; killing the squad opens its gate.
   * The hallway count follows the floor's own missions ("Defeat monsters in the first ... fourth hallway").
   * Object monsters (crystals) stand with the last squad. Returns null when the floor has no gates (the squad then
   * stays at the builder's suggested point).
   */
  _hallwaySquads(minions, bosses) {
    const col = this.game.world?.collision;
    const inf = this.info;
    if (!col) return null;
    const gates = (inf.bricks || []).filter(b => b.create && brickDef(b.brick)?.role === 'gate');
    if (!gates.length) return null;
    const s = startPos(this.map) || (this.game.player ? { x: this.game.player.x, z: this.game.player.z } : null);
    if (!s) return null;
    const field = pathField(col, s.x, s.z);
    if (!field) return null;
    const startNpc = this.scriptNpcs.find(n => n.role === 'start');
    let startGate = null;
    if (startNpc) { let bd = Infinity; for (const g of gates) { const dd = Math.hypot(g.x - startNpc.x, g.y - startNpc.y); if (dd < bd) { bd = dd; startGate = g; } } if (bd > 20) startGate = null; }
    const bossPts = bosses.filter(b => b.suggest).map(b => b.suggest);
    const halls = gates
      .filter(g => g !== startGate && !bossPts.some(p => Math.hypot(g.x - p[0], g.y - p[1]) < 14))
      .map(g => ({ g, d: fieldMin(field, col, g.x, g.y, 4) }))
      .filter(h => h.d > HALL_BACK)
      .sort((a, b) => a.d - b.d);
    if (!halls.length) return null;
    const hallMissions = (inf.missions || []).filter(m => /hallway/i.test(m.text || '')).length;
    const n = Math.max(1, Math.min(halls.length, hallMissions || halls.length, 6));
    const mdef = (i) => this.game.data?.monster?.(Number(i)) || null;
    const creatures = minions.filter(m => mdef(m.monster)?.role !== 'object').map(m => m.monster);
    const objects = minions.filter(m => mdef(m.monster)?.role === 'object').map(m => m.monster);
    if (!creatures.length) return null;
    const out = [];
    for (let i = 0; i < n; i++) {
      const h = halls[i];
      const p = cellBefore(field, col, h.g.x, h.g.y, h.d, HALL_BACK);
      if (!p) continue;
      const rows = [];
      for (const c of creatures) rows.push([c, Math.floor(p[0]), Math.floor(p[1]), 3, 1]);
      if (i === n - 1) for (const o of objects) rows.push([o, Math.floor(p[0]), Math.floor(p[1]), 2, 1]);
      out.push({ n: 900 + i, kind: 'squad', objective: 'kill-all', rows, opens: [h.g.uid], bosses: [], group: 0, spawned: false, done: false, recs: [], atStart: true, hall: i + 1 });
    }
    return out.length ? out : null;
  }

  /**
   * The playable parts of the floor: 4-connected walkable regions of the .mac grid (bricks not yet placed) that the
   * floor's start, a script NPC, a brick, a trigger or a warp location touches (within 4 cells). Everything else is
   * scenery walled off from play (the open sea around the Tower of Spell, sealed alcoves). A spawn point there - the
   * client ships a few call files of a sibling floor (Tower of Spell 1F carries the 2F rows) - moves to the nearest
   * playable cell (_placeable), so every monster the floor needs can be reached.
   */
  _layout() {
    const col = this.game.world?.collision;
    this.comp = null; this.playable = null;
    if (!col?.cells) return;
    const W = col.width, H = col.height, C = col.cells;
    const comp = new Int32Array(W * H).fill(-1);
    const q = new Int32Array(W * H);
    let id = 0;
    for (let i = 0; i < C.length; i++) {
      if (C[i] || comp[i] >= 0) continue;
      let h = 0, t = 0;
      comp[i] = id; q[t++] = i;
      while (h < t) {
        const c = q[h++], x = c % W;
        if (x > 0 && !C[c - 1] && comp[c - 1] < 0) { comp[c - 1] = id; q[t++] = c - 1; }
        if (x < W - 1 && !C[c + 1] && comp[c + 1] < 0) { comp[c + 1] = id; q[t++] = c + 1; }
        if (c >= W && !C[c - W] && comp[c - W] < 0) { comp[c - W] = id; q[t++] = c - W; }
        if (c + W < C.length && !C[c + W] && comp[c + W] < 0) { comp[c + W] = id; q[t++] = c + W; }
      }
      id++;
    }
    const playable = new Set();
    const touch = (x, z, r = 4) => {
      x = Number(x); z = Number(z);
      if (!Number.isFinite(x) || !Number.isFinite(z)) return;
      for (let dz = -r; dz <= r; dz++) for (let dx = -r; dx <= r; dx++) {
        const cx = Math.floor(x) + dx, cz = Math.floor(z) + dz;
        if (cx >= 0 && cz >= 0 && cx < W && cz < H && comp[cz * W + cx] >= 0) playable.add(comp[cz * W + cx]);
      }
    };
    const s = startPos(this.map);
    if (s) touch(s.x, s.z);
    if (this.game.player) touch(this.game.player.x, this.game.player.z);
    for (const n of this.scriptNpcs) touch(n.x, n.y);
    for (const b of this.info.bricks || []) touch(b.x, b.y);
    for (const t of this.info.triggers || []) touch(t.x, t.y);
    for (const i of this.info.locations || []) { const l = location(i); if (l && Number(l[0]) === this.map) touch(l[1], l[2]); }
    for (const n of this.game.npcs || []) if (!n.isBrick && !n.isTrigger) touch(n.x, n.z);
    this.comp = comp;
    this.playable = playable;
  }

  /** [x, z] of a spawn point, moved to the nearest playable cell when it is off the playable floor. */
  _placeable(x, z) {
    const col = this.game.world?.collision, comp = this.comp, P = this.playable;
    if (!col || !comp || !P?.size) return [x, z];
    const W = col.width, H = col.height;
    const ok = (cx, cz) => cx >= 0 && cz >= 0 && cx < W && cz < H && P.has(comp[cz * W + cx]);
    const fx = Math.floor(x), fz = Math.floor(z);
    if (ok(fx, fz)) return [x, z];
    for (let r = 1; r <= 64; r++) {
      let best = null, bd = Infinity;
      for (let dz = -r; dz <= r; dz++) for (let dx = -r; dx <= r; dx++) {
        if (Math.max(Math.abs(dx), Math.abs(dz)) !== r || !ok(fx + dx, fz + dz)) continue;
        const e = dx * dx + dz * dz;
        if (e < bd) { bd = e; best = [fx + dx + 0.5, fz + dz + 0.5]; }
      }
      if (best) return best;
    }
    return [x, z];
  }

  /** Stages that must be done for "all waves" (not the script boss, not optional adds). */
  _required() { return this.stages.filter(s => !s.script && !s.optional); }

  _stageRows(st) {
    const out = [];
    const col = this.game.world?.collision;
    for (const [mon, x, y, cell, count] of st.rows) {
      const n = Math.max(1, Number(count) || 1);
      for (let k = 0; k < n; k++) {
        let px = Number(x) + 0.5, pz = Number(y) + 0.5;
        const r = Number(cell) || 0;
        if (r > 0 || n > 1) {
          const rr = Math.max(r, n > 1 ? 1.5 : 0);
          const a = this.rand() * Math.PI * 2, d = Math.sqrt(this.rand()) * rr;
          px += Math.cos(a) * d; pz += Math.sin(a) * d;
        }
        if (col && !col.isWalkable(px, pz)) { const s = col.nearestWalkable(px, pz, 6); if (s) { px = s.x; pz = s.z; } }
        [px, pz] = this._placeable(px, pz);
        // Retain unresolved placement evidence for stage preflight. Geometry
        // cannot make a mandatory visible native creature an optional helper.
        const unplaceable = !!col?.nearestWalkable && !col.isWalkable(px, pz) && !col.nearestWalkable(px, pz, 32);
        out.push({ monsterIndex: Number(mon), x: px, z: pz, ...(unplaceable ? { unplaceable: true, row: [Number(mon), Number(x), Number(y)] } : {}) });
      }
    }
    return out;
  }

  _spawnStage(st) {
    const sp = this.game.spawner;
    if (!sp || st.spawned) return;
    const rows = this._stageRows(st);
    const unresolved = rows.find(s => s.unplaceable && this.game.data?.monster?.(s.monsterIndex)?.role !== 'invisible');
    if (unresolved) {
      this.nativeSpawnFault = { stage: st.n, call: st.call ?? null, monster: unresolved.monsterIndex, row: unresolved.row };
      throw Object.assign(new Error('No safe original dungeon monster spawn exists.'), { code: 'NATIVE_DUNGEON_SPAWN_UNRESOLVED' });
    }
    st.spawned = true;
    st.recs = [];
    for (const s of rows) {
      const rec = {
        id: `dg${this.map}_${st.n}_${this._seq++}`,
        spawn: { monsterIndex: s.monsterIndex, x: s.x, z: s.z, respawnSec: 0 },
        respawnSec: Infinity, monster: null, loading: false, deadAt: null, respawnAt: 0, failedUntil: 0, skip: false,
        dg: { stage: st, killed: false },
      };
      const def = this.game.data?.monster?.(s.monsterIndex);
      if (!def || def.role === 'invisible') { rec.skip = true; rec.dg.killed = true; }
      // lane65: older server reference spawn timer (server-ref-plans.js SERVER_REF_SPAWN_TIMING)
      const tm = rec.skip ? null : serverRefSpawnTiming(this.map, s.monsterIndex);
      if (tm?.after != null) { rec.failedUntil = Infinity; rec.dg.waitFor = tm; }
      else if (tm?.sec) rec.failedUntil = (this.game.time || 0) + tm.sec;
      sp.records.push(rec);
      st.recs.push(rec);
      if (!rec.skip) this._countSpawn(s.monsterIndex);    // invisible helpers (fire traps) are never killed
    }
    sp._scan = 0;   // activate the nearest ones on the next frame
    if (st.kind === 'boss') this._bossAppears(st);
    this.game.events?.emit?.('dungeon:stage', { map: this.map, stage: st.n, spawned: true });
  }

  _countSpawn(idx) { this.spawnedIdx.set(Number(idx), (this.spawnedIdx.get(Number(idx)) || 0) + 1); }

  _stageAlive(st) { return st.recs.some(r => !r.dg.killed && !r.skip); }

  _startStages() {
    const list = this.stages.filter(s => !s.script);
    for (const st of list.filter(s => s.atStart)) this._spawnStage(st);
    if (this.sequential) {
      const next = this._nextSequential();
      if (next) for (const st of next) this._spawnStage(st);
    } else {
      for (const st of list) this._spawnStage(st);
    }
    this._maybeAutoBoss();
  }

  /** Next stage(s) to spawn in sequential mode: the next group, or the next stage. */
  _nextSequential() {
    const waiting = this.stages.filter(s => s.kind === 'wave' && !s.spawned);
    if (!waiting.length) {
      if (this.killTarget && this.kills < this.killTarget && this.stages.some(s => s.kind === 'wave')) {
        // infinite battle: the rounds repeat until the kill target
        for (const s of this.stages) if (s.kind === 'wave') { s.spawned = false; s.done = false; s.recs = []; }
        return this._nextSequential();
      }
      return null;
    }
    if (this.groups) {
      const g = Math.min(...waiting.map(s => s.group || 0));
      return waiting.filter(s => (s.group || 0) === g);
    }
    return [waiting[0]];
  }

  _maybeAutoBoss() {
    const boss = this.stages.find(s => s.kind === 'boss' && !s.spawned);
    if (!boss) return;
    const npcPlaced = boss.trigger && this.game.npcs?.some(n => n.npcIndex === boss.trigger.npc);
    if (npcPlaced) return;                                     // summoned from its NPC
    const waves = this._required();
    // "Destroy all 3 statues" before the boss appears
    const bricksLeft = (this.missions || []).some(m => m.kind === 'bricks' && !m.done);
    if (waves.every(s => s.done) && !bricksLeft && (!this.killTarget || this.kills >= this.killTarget)) this._spawnStage(boss);
  }

  /**
   * Spawn-limit missions: a live object monster of the floor (Creation Crystal) calls one add (Creator's Fury)
   * every ADD_EVERY s while the player is near it; reaching the mission's limit fails the dungeon.
   */
  _adds() {
    const lims = (this.missions || []).filter(m => m.kind === 'limit' && !m.failed && !m.done);
    if (!lims.length) return;
    const now = this._clock || 0;
    const p = this.game.player;
    for (const st of this.stages) {
      if (!st.spawned || st.optional) continue;
      for (const rec of st.recs) {
        const mon = rec.monster;
        if (!mon || mon.dead || rec.dg?.killed || mon.def?.role !== 'object') continue;
        if (!p || Math.hypot(p.x - mon.x, p.z - mon.z) > ADD_RANGE) continue;
        if ((rec._addAt ?? (rec._addAt = now + ADD_EVERY)) > now) continue;
        rec._addAt = now + ADD_EVERY;
        for (const m of lims) {
          let st2 = this.stages.find(s => s.kind === 'adds');
          if (!st2) { st2 = { n: 950, kind: 'adds', objective: 'none', rows: [], opens: [], bosses: [], group: 0, spawned: true, done: false, recs: [], optional: true }; this.stages.push(st2); }
          this._spawnOne(st2, m.idx[0], mon.x, mon.z, 2);
          m.count = (m.count || 0) + 1;
          if (m.count >= m.limit) { m.failed = true; this._refreshInfo(); this.fail('mission'); return; }
        }
      }
    }
  }

  /** One extra record of a stage at (x, z) (scatter r cells). */
  _spawnOne(st, idx, x, z, r = 0) {
    const sp = this.game.spawner;
    if (!sp) return null;
    const col = this.game.world?.collision;
    const a = this.rand() * Math.PI * 2, d = Math.sqrt(this.rand()) * r;
    let px = x + Math.cos(a) * d, pz = z + Math.sin(a) * d;
    if (col && !col.isWalkable(px, pz)) { const s = col.nearestWalkable(px, pz, 6); if (s) { px = s.x; pz = s.z; } }
    const rec = {
      id: `dg${this.map}_${st.n}_${this._seq++}`, spawn: { monsterIndex: Number(idx), x: px, z: pz, respawnSec: 0 },
      respawnSec: Infinity, monster: null, loading: false, deadAt: null, respawnAt: 0, failedUntil: 0, skip: false, dg: { stage: st, killed: false },
    };
    sp.records.push(rec);
    st.recs.push(rec);
    st.done = false;
    this._countSpawn(idx);
    sp._scan = 0;
    return rec;
  }

  _bossAppears(st) {
    for (const code of st.alert?.length ? st.alert : this._bossAlertCodes(st)) this.alert(code);
    const flash = this._nextCode(800, 809);
    if (flash != null) this.alert(flash);
    // lock the boss room: create:0 bricks close to the boss
    const c = st.rows[0];
    if (c) {
      for (const [uid, pl] of this.pendingBricks) {
        if (Math.hypot(pl.x - c[1], pl.y - c[2]) <= LOCK_RADIUS) { this._createBrick(pl, true).then(b => { if (b) { b.lockFor = st; } }); this.pendingBricks.delete(uid); }
      }
    }
  }

  _bossAlertCodes(st) {
    const out = [];
    for (const b of this.info.bosses || []) if (st.bosses.includes(b.monster)) out.push(...(b.alert || []));
    return out;
  }

  /** First unused message code in [a, b] that has text or effects. */
  _nextCode(a, b) {
    for (let c = a; c <= b; c++) {
      const m = this.messages[String(c)];
      if (!m || this.alertsUsed.has(c)) continue;
      if ((m.t && m.t !== '[message]' && m.t !== '[Message]') || m.fx?.length) return c;
    }
    return null;
  }

  // ---------------------------------------------------------------------------------------- bricks / triggers
  async _buildBricks() {
    const jobs = [];
    for (const pl of this.info.bricks || []) {
      if (pl.create) jobs.push(this._createBrick(pl, false));
      else this.pendingBricks.set(pl.uid, pl);
    }
    await Promise.all(jobs);
  }

  async _createBrick(pl, closing) {
    const def = brickDef(pl.brick);
    if (!def) return null;
    const b = new Brick(this.game, def, pl);
    this.bricks.push(b);
    this.brickByUid.set(pl.uid, b);
    this.game.npcs.push(b);
    b.block();
    await b.load();
    if (b.disposed) return null;
    if (closing) b.play('close', { loop: false });
    return b;
  }

  openBrick(uid, alert = true) {
    const b = this.brickByUid.get(uid);
    if (!b || b.open || b.breakable) return false;
    const ok = b.openGate();
    if (ok && alert) { const c = this._gateAlert(null); if (c != null) this.alert(c); }
    return ok;
  }

  openAllGates(alert = false) {
    let any = false;
    for (const b of this.bricks) if (!b.open && !b.breakable && !b.dead) { b.openGate(); any = true; }
    if (any && alert) { const c = this._gateAlert(null); if (c != null) this.alert(c); }
    return any;
  }

  _buildTriggers() {
    const drops = D.dg?.triggerDrops || {};
    for (const pl of this.info.triggers || []) {
      const def = triggerDef(pl.trigger);
      if (!def) continue;
      const t = new Trigger(this.game, def, pl, this.map);
      const drop = drops[pl.drop || `${this.map}:${pl.trigger}`] || null;
      t.drop = drop;
      if (drop && !/^click$/i.test(drop.cond || 'Click')) t.locked = true;   // <map>_KillMainBoss / _Siege: after the clear
      this.triggers.push(t);
      this.game.npcs.push(t);
      t.load();
    }
  }

  async useTrigger(t) {
    if (!t || t.disposed) return;
    const dlg = this.sys.dialog;
    if (t.locked) { this.sysMessage(this.text(200) || plain(sysText(8))); return; }
    if (!t.clickable) return;
    const s = t.stateDef;
    t.busy = true;
    try {
      // Global: gauge + triggerinteractiveaction motion chain run together when the CSV has a row.
      const interactP = this.game.life?.interact?.(t.place?.trigger);
      if (s && (s.ms > 0 || s.text)) {
        const seq = dlg._seq, world = this.game.world;
        const ok = await dlg.gauge(s.text || t.name, Math.max(300, Number(s.ms) || 1000));
        if (!ok || seq !== dlg._seq || world !== this.game.world) return;
      }
      if (interactP) await interactP.catch?.(() => false);
      t.advance();
      this.used.add(`t${t.place?.trigger}`);
      if (t.opened && t.drop) this._dropTrigger(t);
      this._updateMissions();
      this.game.events?.emit?.('dungeon:trigger', { map: this.map, trigger: t.place?.trigger, state: t.tstate });
    } finally { t.busy = false; }
  }

  _dropTrigger(t) {
    const loot = this.game.loot, drop = t.drop;
    if (!loot || !drop) return;
    const def = { drops: { money: drop.money ? [drop.money] : [], sets: drop.sets || [], fixed: drop.fixed || [], fixedSets: drop.fixedSets || [], maxSets: drop.maxItemSet || 1 } };
    import('../../game/loot.js').then(({ rollMonsterDrops }) => {
      const list = rollMonsterDrops(def, this.game.data?.monsters, { itemRate: this.game.settings?.dropRate ?? 1, moneyRate: this.game.settings?.moneyRate ?? 1 });
      list.forEach((e, i) => { const a = (i / Math.max(1, list.length)) * Math.PI * 2; loot.spawnDrop(e, t.x + Math.cos(a) * 1.2, t.z + Math.sin(a) * 1.2); });
    }).catch(err => console.warn('[dungeons] trigger drop', err));
  }

  // ---------------------------------------------------------------------------------------- missions
  _buildMissions() {
    const inf = this.info;
    const names = new Map();   // lowercase monster name -> [idx]
    const addName = (idx) => { const n = monsterName(this.game, idx).toLowerCase(); if (!names.has(n)) names.set(n, new Set()); names.get(n).add(Number(idx)); };
    for (const w of inf.waves || []) for (const r of w.rows) addName(r[0]);
    for (const s of inf.scriptSpawns || []) addName(s.monster);
    for (const r of inf.static?.rows || []) addName(r[0]);
    const bossIdx = new Set((inf.bosses || []).map(b => b.monster));
    const ORD = ['first', 'second', 'third', 'fourth', 'fifth', 'sixth'];
    const hallStages = this.stages.filter(s => s.hall);
    // breakable bricks of the floor by the last word of their name ("Mana Statue" -> statue)
    const breakWords = new Set();
    for (const pl of inf.bricks || []) { const b = brickDef(pl.brick); if (b?.role === 'breakable' && pl.create) { const w = String(b.name || '').toLowerCase().split(/\s+/).pop(); if (w && w.length >= 4) breakWords.add(w); } }
    this.missions = (inf.missions || []).map(m => {
      const text = m.text || '';
      const lower = `${text} ${m.note || ''}`.toLowerCase();
      const out = { code: m.code, text, note: m.note, done: false, failed: false, kind: 'clear', idx: null, npcs: null };
      // "You will fail the mission if you allow 24 or more Creator's Furies spawn."
      const lim = /allow\s+(\d+)\s+or\s+more\s+([\s\S]+?)\s+spawn/i.exec(text);
      if (lim) {
        const want = lim[2].toLowerCase().replace(/\s+/g, ' ');
        const idx = [...names.entries()].filter(([n]) => n.length >= 4 && want.includes(n.replace(/(y|s)$/, ''))).flatMap(([, s]) => [...s]);
        if (idx.length) { out.kind = 'limit'; out.limit = Number(lim[1]); out.idx = idx; out.count = 0; return out; }
      }
      const hallK = ORD.findIndex(o => new RegExp(`\\b${o}\\s+hallway`).test(lower));
      if (hallK >= 0 && hallStages.some(s => s.hall === hallK + 1)) { out.kind = 'hall'; out.hall = hallK + 1; return out; }
      if (breakWords.size && /\b(destroy|break|smash)\b/.test(lower) && [...breakWords].some(w => lower.includes(w))) { out.kind = 'bricks'; return out; }
      // named monsters (plural "Klaatus" -> "klaatu")
      const hit = [];
      for (const [n, set] of names) {
        const stem = n.replace(/s$/, '');
        if (stem.length >= 4 && lower.includes(stem)) hit.push(...set);
      }
      const npcHit = this.scriptNpcs.filter(n => n.name && lower.includes(String(n.name).toLowerCase()) && n.role !== 'exit');
      if (npcHit.length && !hit.length) { out.kind = 'npc'; out.npcs = npcHit.map(n => n.npc); }
      else if (hit.length) { out.kind = hit.every(i => bossIdx.has(i)) ? 'boss' : 'kill'; out.idx = [...new Set(hit)]; }
      else if (/\b(lever|operate|examine|statue|stone|touch|activate|switch|device|speak|talk)\b/.test(lower)) out.kind = 'anynpc';
      else if (/\bboss/.test(lower)) out.kind = 'clear';
      else if (/(hallway|monsters?|eliminat|defeat|kill|destroy)/.test(lower)) out.kind = 'waves';
      return out;
    });
  }

  _updateMissions() {
    let changed = false;
    for (const m of this.missions || []) {
      if (m.done) continue;
      let ok = false;
      switch (m.kind) {
        case 'kill': case 'boss':
          ok = m.idx.some(i => (this.spawnedIdx.get(i) || 0) > 0) && m.idx.every(i => (this.killedIdx.get(i) || 0) >= (this.spawnedIdx.get(i) || 0));
          break;
        case 'npc': ok = m.npcs.some(n => this.used.has(n)); break;
        case 'anynpc': ok = [...this.used].some(u => typeof u === 'number' && this.scriptNpcs.find(n => n.npc === u && n.role !== 'exit' && n.role !== 'warp')) || [...this.used].some(u => typeof u === 'string'); break;
        case 'waves': ok = this._required().length > 0 && this._required().every(s => s.done) && (!this.killTarget || this.kills >= this.killTarget); break;
        case 'hall': ok = !!this.stages.find(s => s.hall === m.hall)?.done; break;
        case 'bricks': { const bs = this.bricks.filter(b => b.breakable); ok = bs.length > 0 && bs.every(b => b.dead || b.open); break; }
        case 'limit': ok = false; break;
        default: ok = this.phase === 'cleared';
      }
      if (this.phase === 'cleared') ok = true;
      if (ok) { m.done = true; changed = true; }
    }
    if (changed) { this._refreshInfo(); this.sys.ui.alarm(true, true); }
  }

  _refreshInfo() {
    const time = this.info.timeLimit?.text || this.dungeon.timeLimit?.text || (this.limit ? `${Math.round(this.limit / 60)} min` : sysText(139));
    this.sys.ui.setInfo({
      title: this.text(1) || this.mapName,
      mission: this.text(2) || this.dungeon.mission || '',
      time,
      missions: (this.missions || []).map(m => ({ text: m.text, done: m.done, failed: m.failed })),
    });
  }

  // ======================================================================================== frame
  /** Run fn after `sec` seconds of game time (paused with the game, dropped with the instance). */
  later(sec, fn) { (this._later ||= []).push({ t: (this._clock || 0) + Math.max(0, Number(sec) || 0), fn }); }

  update(dt) {
    if (this.disposed) return;
    this._clock = (this._clock || 0) + dt;
    if (this._later?.length) {
      const due = this._later.filter(x => x.t <= this._clock);
      if (due.length) {
        this._later = this._later.filter(x => x.t > this._clock);
        for (const x of due) { try { x.fn(); } catch (err) { console.error('[dungeons] later', err); } }
      }
    }
    switch (this.phase) {
      case 'countdown':
        this.countdown -= dt;
        if (this.countdown <= 0) this._begin();
        break;
      case 'running':
        this.elapsed += dt;
        if (this.limit && this.elapsed >= this.limit) { this.fail('time'); break; }
        this._poll -= dt;
        if (this._poll <= 0) { this._poll = POLL; this._tick(); }
        break;
      case 'cleared':
        this.transfer -= dt;
        if (this.transfer <= 0) this.sys.leave(this, 'transfer');
        break;
      case 'failed':
        this.closing -= dt;
        if (this.closing <= 0) this.sys.leave(this, 'fail');
        break;
      default: break;
    }
    try { this.plan?.update?.(this, dt); } catch (err) { console.error('[dungeons] plan update', err); this.plan.update = null; }
    this._timers();
  }

  _timers() {
    const rows = [];
    const cap = (c, d) => (this.messages[String(c)]?.t ?? d);
    if (this.phase === 'countdown') rows.push({ caption: cap(32, 'Dungeon Starting:'), sec: this.countdown });
    else if (this.phase === 'running') {
      if (this.limit) rows.push({ caption: cap(30, 'Running Time:'), sec: this.limit - this.elapsed });
      for (const t of this.extraTimers) rows.push(t);
    } else if (this.phase === 'cleared') rows.push({ caption: cap(34, 'Transfer Time:'), sec: this.transfer });
    else if (this.phase === 'failed') rows.push({ caption: cap(39, null) ?? cap(31, 'Close in:'), sec: this.closing });
    this.sys.ui.setTimers(rows);
  }

  _begin() {
    this.phase = 'running';
    this.elapsed = 0;
    if (!this.plan?.noStartEffect) this.effect(2000);   // lane65: a server-ref plan that plays its own start notice
    try { this.plan?.begin?.(this); } catch (err) { console.error('[dungeons] plan begin', err); }
    if (!this.plan?.noStages) this._startStages();
    if (this.killTarget) this.sys.ui.count(`${this.kills} / ${this.killTarget}`, sysText(104));
    this.game.events?.emit?.('dungeon:start', { map: this.map, dungeon: this.dungeonId, floor: this.floor });
  }

  _tick() {
    // stage completion
    for (const st of this.stages) {
      if (!st.spawned || st.done) continue;
      if (st.optional) { if (!this._stageAlive(st)) st.done = true; continue; }
      if (!this._stageAlive(st)) this._stageDone(st);
    }
    this._adds();
    if (this.phase !== 'running') return;
    this._updateMissions();
    this._maybeAutoBoss();
    if (this.phase === 'running' && this._clearMet()) { this.clear(); return; }
    if ((this._clock || 0) >= (this._stuckAt ?? 8)) { this._stuckAt = (this._clock || 0) + STUCK_EVERY; this._unstick(); }
  }

  /**
   * Progress guard. The server scripts that open some gates are not in the client, so when nothing the floor still
   * needs (live monsters, unkilled statics, unused lever / summon NPCs) can be reached from where the player stands,
   * the closed gate between them opens: the reachable one nearest to the closest target.
   */
  _unstick() {
    const col = this.game.world?.collision, p = this.game.player;
    if (!col || !p || p.dead) return false;
    const targets = this._targets();
    const npcs = [];
    for (const sn of this.scriptNpcs) if (!this.used.has(sn.npc) && ['start', 'bossSummon', 'interact'].includes(sn.role)) npcs.push([sn.x, sn.y]);
    // devices the player can still use from here: "start the test" NPCs, in-floor teleports
    const devices = this.scriptNpcs.filter(sn => (sn.role === 'talk' && /start|enter|move|teleport|go to|begin|test/i.test(sn.label || ''))
      || (sn.role === 'warp' && !/next|floor|stairs|\dF\b/i.test(`${sn.label} ${sn.name}`)) || (sn.role === 'exit' && this._isInFloorExit(sn))).map(sn => [sn.x, sn.y]);
    if (!targets.length) targets.push(...npcs);
    if (!targets.length) return false;
    const field = pathField(col, p.x, p.z);
    if (!field) return false;
    const reach = (f, pts) => pts.some(([x, z]) => fieldMin(f, col, x, z, 2) >= 0);
    // something to do within reach (a monster, or a lever / summon NPC still to operate): not stuck
    if (reach(field, targets) || reach(field, npcs)) return false;
    const deviceHere = reach(field, devices);
    const cands = [];
    for (const b of this.bricks) {
      if (b.open || b.dead || b.breakable) continue;
      if (fieldMin(field, col, b.x, b.z, 4) < 0) continue;
      let bd = Infinity;
      for (const [x, z] of targets) bd = Math.min(bd, Math.hypot(b.x - x, b.z - z));
      cands.push([bd, b]);
    }
    cands.sort((a, b) => a[0] - b[0]);
    for (const [, b] of cands.slice(0, 6)) {
      // open it only when that makes a target reachable (a target cut off by the terrain itself is not a gate's fault)
      b.unblock();
      const f2 = pathField(col, p.x, p.z);
      if (f2 && reach(f2, targets)) {
        b.openGate();
        const c = this._gateAlert(null);
        if (c != null) this.alert(c);
        this.game.events?.emit?.('dungeon:unstick', { map: this.map, brick: b.uid });
        return true;
      }
      b.block();
    }
    // no gate between: the server moves the party on (troop / expedition floors: "After killing monsters, go
    // inside the castle."), unless a teleport device here is the way on
    if (!deviceHere) return this._transferToWork(field);
    return false;
  }

  /**
   * Move the player to the map location (maplist warp points of this floor) that lies in a walled-off part with
   * targets left, nearest to the player; else to the nearest such part's closest cell (_gateTravel).
   */
  _transferToWork(field) {
    const g = this.game, col = g.world?.collision, p = g.player, comp = this.comp;
    if (!col || !p || !comp) return false;
    const W = col.width;
    const compNear = (x, z) => { for (let r = 0; r <= 3; r++) for (let dz = -r; dz <= r; dz++) for (let dx = -r; dx <= r; dx++) { const cx = Math.floor(x) + dx, cz = Math.floor(z) + dz; if (cx < 0 || cz < 0 || cx >= W || cz >= col.height) continue; const v = comp[cz * W + cx]; if (v >= 0) return v; } return -1; };
    const work = new Set(this._targets().filter(([x, z]) => fieldMin(field, col, x, z, 2) < 0).map(([x, z]) => compNear(x, z)).filter(v => v >= 0));
    if (!work.size) return false;
    let best = null, bd = Infinity;
    for (const i of this.info.locations || []) {
      const l = location(i);
      if (!l || Number(l[0]) !== this.map) continue;
      const x = Number(l[1]) + 0.5, z = Number(l[2]) + 0.5;
      if (fieldMin(field, col, x, z, 2) >= 0 || !work.has(compNear(x, z))) continue;
      const e = Math.hypot(x - p.x, z - p.z);
      if (e < bd) { bd = e; best = { x, z, dirDeg: Number(l[3]) || 0 }; }
    }
    if (best) {
      const s = col.walkableCell(Math.floor(best.x), Math.floor(best.z)) ? best : { ...best, ...(col.nearestWalkable(best.x, best.z, 6) || {}) };
      g.travel(this.map, { x: s.x, z: s.z, dirDeg: best.dirDeg });
      g.events?.emit?.('dungeon:transferwork', { map: this.map, to: [s.x, s.z] });
      return true;
    }
    return this._gateTravel(p);
  }

  _stageDone(st) {
    st.done = true;
    let opened = false;
    for (const uid of st.opens || []) opened = this.openBrick(uid, false) || opened;
    if (st.kind === 'squad' && !(st.opens || []).length) {
      // the guard squad opens the gate it stands next to
      const c0 = st.rows[0];
      const gate = this._nearestClosedGate(c0[1], c0[2]);
      if (gate) { gate.openGate(); opened = true; }
    }
    if (opened) { const c = this._gateAlert(st); if (c != null) this.alert(c); }
    if (st.kind === 'boss') {
      const c = this._nextCode(810, 839);
      if (c != null) this.alert(c);
      for (const b of this.bricks) if (b.lockFor === st) b.openGate();
    }
    // Forbidden Fetters: floor-group clear EXP (forbiddenshacklesdata.csv)
    if (this.groups && st.group) {
      const gi = st.group - 1, gr = this.groups[gi];
      if (gr && !gr.paid && this.stages.filter(s => s.group === st.group).every(s => s.done)) {
        gr.paid = true;
        if (gr.clearExp) this.sys.grantExp(Number(gr.clearExp));
      }
    }
    if (this.sequential) {
      const next = this._nextSequential();
      if (next) this.later(3, () => { if (this.running) for (const s of next) this._spawnStage(s); });
    }
    // every hallway cleared: nothing left behind a gate
    if (this._required().every(s => s.done)) this.openAllGates(false);
    this._maybeAutoBoss();
    try { this.plan?.stageDone?.(this, st); } catch (err) { console.error('[dungeons] plan stageDone', err); }
    this.game.events?.emit?.('dungeon:stage', { map: this.map, stage: st.n, done: true });
  }

  _nearestClosedGate(x, z) {
    let best = null, bd = Infinity;
    for (const b of this.bricks) {
      if (b.open || b.breakable || b.dead || !b.place?.create) continue;
      const d = Math.hypot(b.x - x, b.z - z);
      if (d < bd) { bd = d; best = b; }
    }
    return best;
  }

  _clearMet() {
    if (this.nativeSpawnFault) return false;
    if (this.plan?.clearMet) { try { return !!this.plan.clearMet(this); } catch { return false; } }
    const c = this.clearDef || {};
    const waves = this._required();
    switch (c.kind) {
      case 'boss': {
        // a clear monster that has no body (Yogshield_Fire, an invisible fire trap) cannot be killed: every wave then
        const ids = (c.monsters || []).map(Number).filter(i => this.game.data?.monster?.(i)?.role !== 'invisible');
        if (!ids.length) return waves.length > 0 && waves.every(s => s.done) && (!this.killTarget || this.kills >= this.killTarget);
        return ids.every(i => (this.spawnedIdx.get(i) || 0) > 0 && (this.killedIdx.get(i) || 0) >= (this.spawnedIdx.get(i) || 0));
      }
      case 'all-waves': return waves.length > 0 && waves.every(s => s.done) && (!this.killTarget || this.kills >= this.killTarget);
      case 'all-static': return this.statics.length > 0 && this.statics.every(r => r.dgDead || r.skip);
      default: {
        // no monster data in the client (server-side script): everything the floor spawned is dead
        const all = [...this.stages];
        const spawnedAny = all.some(s => s.spawned) || this.statics.length;
        if (!spawnedAny) return false;
        return all.every(s => !s.spawned || s.done) && all.every(s => s.spawned || s.script) && this.statics.every(r => r.dgDead || r.skip);
      }
    }
  }

  // ======================================================================================== events
  onDeath(actor, killer) {
    if (actor === this.game.player) { this.deaths++; return; }
    if (actor?.isBrick) {
      actor.destroyed?.();
      if (this.game.player?.target === actor) this.game.controller?.setTarget?.(null);
      return;
    }
    if (actor?.kind !== 'monster') return;
    const idx = Number(actor.monsterIndex ?? actor.def?.index);
    const rec = actor.spawnRecord;
    if (rec?.dg) { if (rec.dg.killed) return; rec.dg.killed = true; }
    else if (rec && this.statics.includes(rec)) { rec.dgDead = true; }
    else return;
    this.kills++;
    this.vars.count = this.kills;
    if (Number.isFinite(idx)) this.killedIdx.set(idx, (this.killedIdx.get(idx) || 0) + 1);
    // lane65: a reference-timed monster waiting for this kill starts its timer now
    if (Number.isFinite(idx)) for (const r of this.game.spawner?.records || []) if (r.dg?.waitFor?.after === idx && r.failedUntil === Infinity) r.failedUntil = (this.game.time || 0) + r.dg.waitFor.sec;
    if (this.killTarget) this.sys.ui.count(`${this.kills} / ${this.killTarget}`, sysText(104));
    try { this.plan?.onKill?.(this, actor, rec); } catch (err) { console.error('[dungeons] plan onKill', err); }
    this._poll = 0;
  }

  // ======================================================================================== clear / fail
  clear() {
    if (this.phase !== 'running' || this.nativeSpawnFault) return;
    this.phase = 'cleared';
    this.transfer = TRANSFER_SECONDS;
    this.effect(this.info.stages?.clearMessage || 1300);
    if (this.deaths === 0 && this.msg(930)) this.later(2.6, () => this._perfect());
    if (this.msg(920)) this.alert(920);
    this.openAllGates(false);
    for (const t of this.triggers) t.locked = false;
    this._updateMissions();
    this._refreshInfo();
    // rewards of special dungeons
    const sp = this.dungeon.rewards?.special;
    if (sp === 'forgottenShipwreck' && this.isLastFloor) this.sys.rollRewardList(D.dg?.forgottenShipwreck?.rewards?.win);
    this.sys.recordRun(this, true);
    try { this.game.quests?.notify?.('clear', { map: this.map }); } catch (err) { console.error('[dungeons] quest clear', err); }
    this.game.events?.emit?.('dungeon:clear', { map: this.map, dungeon: this.dungeonId, floor: this.floor, time: this.elapsed, deaths: this.deaths, perfect: this.deaths === 0 });
  }

  /** 930 "Perfect EXP Reward": the flash (Perfect_Clear+500000) names the bonus EXP it shows. */
  async _perfect() {
    this.effect(930);
    for (const u of messageFx(this.map, 930).ui) {
      const e = await this.sys.uifx.info(u.ui);
      const m = /\+(\d{3,})/.exec(e?.name || '');
      if (m) { this.sys.grantExp(Number(m[1])); break; }
    }
    this.game.events?.emit?.('dungeon:perfect', { map: this.map, dungeon: this.dungeonId });
  }

  fail(reason = 'time') {
    if (this.phase !== 'running' && this.phase !== 'countdown') return;
    this.phase = 'failed';
    this.closing = CLOSE_SECONDS;
    this.effect(this.info.stages?.failMessage || 3000);
    for (const m of this.missions || []) if (!m.done) m.failed = true;
    this._refreshInfo();
    if (this.dungeon.rewards?.special === 'forgottenShipwreck') this.sys.rollRewardList(D.dg?.forgottenShipwreck?.rewards?.lose);
    this.sys.recordRun(this, false);
    this.game.events?.emit?.('dungeon:fail', { map: this.map, dungeon: this.dungeonId, floor: this.floor, reason });
  }

  // ======================================================================================== messages / fx
  /** Show a script message: text to the chat / notice, UI flash effects, sounds. */
  alert(code) {
    const c = Number(code);
    this.alertsUsed.add(c);
    const t = this.text(c);
    const fx = messageFx(this.map, c);
    // a UI flash carries its own text image (tower_korean01.dds = "Foolish Humans ..."): no chat line then
    if (t && !fx.ui.length && !/^\[?message\]?$/i.test(t.trim())) this.sysMessage(t, c >= 800 && c < 900);
    this.effect(c, false);
  }

  /** The 9xx gate alert of a stage: one whose text names this stage's monsters, else one naming no monster. */
  _gateAlert(st) {
    const names = this._nameIndex || (this._nameIndex = (() => {
      const m = new Map();
      const add = (i) => { const n = monsterName(this.game, i).toLowerCase().replace(/s$/, ''); if (n.length >= 4) m.set(n, Number(i)); };
      for (const w of this.info.waves || []) for (const r of w.rows) add(r[0]);
      for (const s of this.info.scriptSpawns || []) add(s.monster);
      return m;
    })());
    const mine = new Set((st?.rows || []).map(r => Number(r[0])));
    let generic = null;
    for (let c = 900; c <= 919; c++) {
      const m = this.messages[String(c)];
      if (!m || this.alertsUsed.has(c) || !m.t || /^\[?message\]?$/i.test(m.t.trim())) continue;
      const low = m.t.toLowerCase();
      const named = [...names.entries()].filter(([n]) => low.includes(n)).map(([, i]) => i);
      if (named.length && named.some(i => mine.has(i))) return c;
      if (!named.length && generic == null) generic = c;
    }
    return generic;
  }

  /** Play a code's directives (effectui / effectsound / sound). withText: also print its text. */
  effect(code, withText = true) {
    const fx = messageFx(this.map, code);
    for (const u of fx.ui) this.sys.uifx.play(u.ui, u.ms);
    for (const s of fx.sfx) this.sys.playEffectSound(s);
    for (const s of fx.sound) this.sys.playJingle(s);
    if (withText) { const t = this.text(code); if (t && !/^\[?message\]?$/i.test(t.trim())) this.sysMessage(t); }
  }

  sysMessage(text, flash = false) { this.sys.notice(text, flash); }

  // ======================================================================================== NPCs
  scriptNpc(npcIndex) { return this.scriptNpcs.find(n => n.npc === Number(npcIndex)) || null; }

  /** Open the dialog of a script NPC; returns true when handled. */
  talk(npc) {
    const sn = this.scriptNpc(npc?.npcIndex);
    if (!sn) return false;
    try { if (this.plan?.talk?.(this, npc, sn)) return true; } catch (err) { console.error('[dungeons] plan talk', err); }
    const dlg = this.sys.dialog;
    const title = npc.name || sn.name;
    const operated = this.used.has(sn.npc) && ['interact', 'start', 'bossSummon'].includes(sn.role);
    let code = operated ? this._alreadyCode() : sn.dialog;
    const m = code != null ? this.msg(code) : null;
    const text = m ? this.text(code) : (sn.label || '');
    const menuCodes = m?.m || [];
    const menu = menuCodes.length
      ? menuCodes.map((mc, i) => ({ text: plain(this.text(mc)) || sn.label || 'OK', onClick: () => (operated ? null : this._choose(npc, sn, mc, i)) }))
      : [{ text: plain(sn.label) || 'OK', onClick: () => (operated ? null : this.act(npc, sn)) }];
    dlg.open({ title, text, menu, options: true });
    return true;
  }

  _alreadyCode() {
    for (const [c, m] of Object.entries(this.messages)) if (Number(c) >= 10000 && m.m && /already/i.test(`${m.t} ${m.c || ''}`)) return Number(c);
    return null;
  }

  async _choose(npc, sn, code, i) {
    const m = this.msg(code);
    // a menu entry that opens another dialog page
    if (m?.m?.length && !(m.fx || []).some(f => f.gauge)) {
      this.sys.dialog.push({ title: npc.name, text: this.text(code), options: true, menu: m.m.map((mc, k) => ({ text: plain(this.text(mc)) || 'OK', onClick: () => this._choose(npc, sn, mc, k) })) });
      return 'keep';
    }
    // the second / third entries of a yes/no page ("No, I need more time.") just close
    if (i > 0 && !(m?.fx || []).some(f => f.gauge)) return null;
    const fx = messageFx(this.map, code);
    if (fx.gauge) {
      this.sys.dialog.close();
      const dlg = this.sys.dialog, seq = dlg._seq, world = this.game.world;
      const ok = await dlg.gauge(fx.gauge.text, fx.gauge.ms, { sound: fx.gauge.sound });
      if (!ok || seq !== dlg._seq || world !== this.game.world) return null;
    }
    return this.act(npc, sn, code);
  }

  /** The role action of a script NPC (after its dialog / gauge). */
  act(npc, sn, code = null) {
    try { if (this.plan?.act?.(this, npc, sn, code)) return; } catch (err) { console.error('[dungeons] plan act', err); }
    const role = sn.role;
    const firstUse = !this.used.has(sn.npc);
    if (role !== 'exit' && role !== 'warp' && role !== 'talk') this.used.add(sn.npc);
    switch (role) {
      case 'start': {
        if (!firstUse) { const c = this._nextCode(500, 599); if (c != null) this.alert(c); break; }
        const gate = this._nearestClosedGate(npc.x, npc.z);
        if (gate) gate.openGate();
        this.waitStart = false;
        break;
      }
      case 'bossSummon': {
        const st = this.stages.find(s => s.kind === 'boss' && !s.spawned && (!s.trigger || s.trigger.npc === sn.npc)) || this.stages.find(s => s.kind === 'boss' && !s.spawned);
        if (!this.running) { this.sysMessage(this.text(200)); break; }
        if (st) this._spawnStage(st);
        break;
      }
      case 'warp': this._warp(npc, sn); break;
      case 'exit': if (this._isInFloorExit(sn)) this._inFloorWarp(npc, sn); else this._exit(npc, sn); break;
      case 'interact': {
        // an interact NPC tied to the boss stage summons it
        const st = this.stages.find(s => s.kind === 'boss' && !s.spawned && s.trigger?.npc === sn.npc);
        if (st && this.running) this._spawnStage(st);
        // a door / lever / switch NPC opens the closed gate next to it
        else if (firstUse && /door|gate|lever|switch|pulley|knob|device|seal/i.test(`${sn.name} ${sn.label}`)) {
          // a door NPC standing in its doorway (blocked .mac cells) opens the passage it closes
          const carved = this._carveDoor(npc, sn);
          const gate = this._nearestClosedGate(npc.x, npc.z);
          if (gate && Math.hypot(gate.x - npc.x, gate.z - npc.z) <= 20) { gate.openGate(); const c = this._gateAlert(null); if (c != null) this.alert(c); }
          else if (carved) { const c = this._gateAlert(null); if (c != null) this.alert(c); }
        }
        break;
      }
      case 'talk': {
        // "The test will start." / "Enter the gate.": the server moves the party on into the part of the floor that
        // still has something to do when it is walled off from here
        if (/start|enter|move|teleport|go to|begin|test/i.test(`${sn.label}`)) this._gateTravel(npc, sn);
        break;
      }
      default: break;
    }
    this._updateMissions();
    this.game.events?.emit?.('dungeon:npc', { map: this.map, npc: sn.npc, role, code });
  }

  /**
   * Door NPCs (job 31 "Open the door.") stand in doorways that the .mac grid keeps blocked (the server opens them).
   * Opening one unblocks the doorway: along the door's facing, from the first walkable cell on one side to the
   * first on the other (at most DOOR_DEPTH each way), DOOR_HALF cells to each side. Only plain "not walkable"
   * cells (value 1) are opened; walls, water and siege barriers stay. Returns the number of cells opened.
   */
  _carveDoor(npc, sn) {
    const col = this.game.world?.collision;
    if (!col) return 0;
    const attrs = col.grid?.attrs || null;
    const x0 = Number(sn.x ?? npc.x), z0 = Number(sn.y ?? npc.z);
    if (col.walkableCell(Math.floor(x0), Math.floor(z0))) return 0;       // not in a doorway
    const a = ((Number(sn.dir) || 0) * Math.PI) / 180;
    const fx = -Math.sin(a), fz = -Math.cos(a), sx = Math.cos(a), sz = -Math.sin(a);
    const firstOpen = (sgn) => {
      for (let t = 1; t <= DOOR_DEPTH; t++) if (col.walkableCell(Math.floor(x0 + fx * t * sgn), Math.floor(z0 + fz * t * sgn))) return t;
      return 0;
    };
    const t1 = firstOpen(1), t2 = firstOpen(-1);
    if (!t1 || !t2) return 0;
    const W = col.width, cells = col.cells;
    const opened = (this._carved ||= []);
    this._carvedCol = col;
    let n = 0;
    for (let t = -t2; t <= t1; t += 0.5) {
      for (let s = -DOOR_HALF; s <= DOOR_HALF; s += 0.5) {
        const cx = Math.floor(x0 + fx * t + sx * s), cz = Math.floor(z0 + fz * t + sz * s);
        if (cx < 0 || cz < 0 || cx >= W || cz >= col.height) continue;
        const i = cz * W + cx;
        if (!cells[i] || (attrs && attrs[i] !== 1)) continue;
        opened.push([i, cells[i]]);
        cells[i] = 0;
        n++;
      }
    }
    if (n) this.game.events?.emit?.('dungeon:door', { map: this.map, npc: sn.npc, cells: n });
    return n;
  }

  /** Floor targets still to do: [[x, z]] (live / unspawned stage monsters, unkilled statics). */
  _targets() {
    const out = [];
    for (const st of this.stages) {
      if (st.optional || st.done) continue;
      if (st.spawned) { for (const r of st.recs) if (!r.dg.killed && !r.skip) out.push([r.monster?.x ?? r.spawn.x, r.monster?.z ?? r.spawn.z]); }
      else for (const row of st.rows) out.push([Number(row[1]) + 0.5, Number(row[2]) + 0.5]);
    }
    for (const r of this.statics || []) if (!r.dgDead && !r.skip) out.push([r.monster?.x ?? r.spawn.x, r.monster?.z ?? r.spawn.z]);
    return out;
  }

  /**
   * Move the player into the walled-off part of the floor that still has targets (the one nearest to the NPC), at
   * its cell nearest to the NPC. Nothing happens when every target can be walked to from here. True when moved.
   */
  _gateTravel(npc) {
    const col = this.game.world?.collision, p = this.game.player;
    if (!col || !p) return false;
    const here = pathField(col, p.x, p.z);
    if (!here) return false;
    let far = this._targets().filter(([x, z]) => fieldMin(here, col, x, z, 2) < 0);
    if (!far.length) {
      // no monsters left out there: a lever / statue still to operate
      far = this.scriptNpcs.filter(n => !this.used.has(n.npc) && ['start', 'bossSummon', 'interact'].includes(n.role)).map(n => [n.x, n.y])
        .filter(([x, z]) => fieldMin(here, col, x, z, 3) < 0);
    }
    if (!far.length) return false;
    far.sort((a, b) => Math.hypot(a[0] - npc.x, a[1] - npc.z) - Math.hypot(b[0] - npc.x, b[1] - npc.z));
    const [tx, tz] = far[0];
    const there = pathField(col, tx, tz);
    if (!there) return false;
    let best = null, bd = Infinity;
    for (let i = 0; i < there.length; i++) {
      if (there[i] < 0) continue;
      const x = (i % col.width) + 0.5, z = ((i / col.width) | 0) + 0.5;
      const e = Math.hypot(x - npc.x, z - npc.z);
      if (e < bd) { bd = e; best = [x, z]; }
    }
    if (!best) return false;
    this.game.travel(this.map, { x: best[0], z: best[1], dirDeg: 0 });
    this.game.events?.emit?.('dungeon:gatetravel', { map: this.map, to: best });
    return true;
  }

  _warp(npc, sn) {
    const nextFloorNpc = nativeShipwreckNextFloor(this,sn) || /next|floor|stairs|\dF\b|move to the/i.test(`${sn.label} ${sn.name}`) || String(sn.job?.[1]) === '6';
    if (nextFloorNpc && !this.isLastFloor) {
      if (this.phase !== 'cleared') { this.sysMessage(this.text(200) || sysText(8)); return; }
      this.sys.enterFloor(this.dungeonId, this.floor + 1, this);
      return;
    }
    this._inFloorWarp(npc, sn);
  }

  /** An 'exit' NPC that only leads back inside the floor ("Sacrifice Chamber Exit", "To Lobby"), not out of it. */
  _isInFloorExit(sn) {
    if (/reezena|leave the dungeon|dungeon exit/i.test(`${sn.name} ${sn.label}`)) return false;
    if (/lobby/i.test(sn.name)) return true;
    if (!/\bexit\b/i.test(sn.name)) return false;
    const b = warpBase(sn.name);
    return !!b && this.scriptNpcs.some(o => o !== sn && warpBase(o.name) === b);
  }

  /**
   * In-floor teleport devices (job 31 "Move by using the equipment."). The server's destinations are not in the
   * client; the NPC names say where they lead:
   *   "To Lobby" / "... Lobby"           -> the floor's start (the lobby), when it is walled off from here
   *   "X" <-> "X Exit"                   -> the other NPC of the pair ("Sacrifice Chamber" <-> "Sacrifice Chamber Exit")
   *   anything else                      -> the nearest walled-off part of the floor with something still to do
   *                                         (monsters, unused levers / statues), else the map's warp locations
   */
  _inFloorWarp(npc, sn) {
    const g = this.game, col = g.world?.collision, p = g.player;
    if (!col || !p) return false;
    const here = pathField(col, p.x, p.z);
    const reach = (x, z) => !!here && fieldMin(here, col, x, z, 3) >= 0;
    const goNear = (x, z, dir = 0) => {
      const s = col.walkableCell(Math.floor(x), Math.floor(z)) ? { x: Math.floor(x) + 0.5, z: Math.floor(z) + 0.5 } : col.nearestWalkable(x, z, 8);
      if (!s) return false;
      g.travel(this.map, { x: s.x, z: s.z, dirDeg: dir });
      g.events?.emit?.('dungeon:warp', { map: this.map, npc: sn.npc, to: [s.x, s.z] });
      return true;
    };
    if (/lobby/i.test(sn.name)) {
      const s = startPos(this.map);
      if (s && !reach(s.x, s.z)) return goNear(s.x, s.z, s.dirDeg || 0);
    }
    const b = warpBase(sn.name);
    if (b) {
      // A repeated generic label (Crespo's many "Lever" NPCs) is not an
      // entrance/exit pair. Pair only distinct names describing the same place;
      // otherwise use this device's remaining-work route below.
      const name = String(sn.name || '').trim().toLowerCase();
      const partner = this.scriptNpcs.find(o => o !== sn && String(o.name || '').trim().toLowerCase() !== name && warpBase(o.name) === b && !reach(o.x, o.y));
      if (partner) {
        // stand on the walkable side of the partner device (its warp point, else next to it)
        const [wx, wz] = partner.warp || [partner.x, partner.y];
        return goNear(Number(wx) + 0.5, Number(wz) + 0.5, partner.dir || 0);
      }
    }
    if (this._gateTravel(npc, sn)) return true;
    const locs = (this.info.locations || []).map(i => location(i)).filter(l => l && Number(l[0]) === this.map && (l[1] || l[2]) && !reach(l[1] + 0.5, l[2] + 0.5));
    if (locs.length) { const l = locs[0]; return goNear(l[1] + 0.5, l[2] + 0.5, l[3] || 0); }
    return false;
  }

  _exit() {
    if (this.phase === 'running' && !this.isLastFloor) { /* leaving early */ }
    this.sys.leave(this, this.phase === 'cleared' ? 'exit' : 'leave');
  }

  /** Where the player comes back after dying on this floor (inside the instance). */
  respawnPoint() {
    const sr = this.info.stageRespawn;
    if (sr?.stages?.length && Number(sr.respawnMap) === this.map) {
      const pick = nativeStageRespawn({map:this.map,info:this.info,monsterDef:index=>this.game.data?.monster?.(Number(index)),killed:this.killedIdx,bricks:this.brickByUid}) || sr.stages[0];
      if (pick) return { mapIndex: this.map, x: pick.x + 0.5, z: pick.y + 0.5, dirDeg: 0 };
    }
    const s = startPos(this.map);
    return s ? { mapIndex: this.map, ...s } : null;
  }

  dispose() {
    this.disposed = true;
    for (const b of this.bricks) b.unblock?.();
    const col = this.game.world?.collision;
    if (col && this._carvedCol === col) for (const [i, v] of this._carved || []) col.cells[i] = v;
    try { this.plan?.dispose?.(this); } catch { /* ignore */ }
  }
}
