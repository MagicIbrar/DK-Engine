// Dead Front ("Fort Focas"), maps 39-44, 60, 160 and the DK copies 77-83, 161. docs/formats/events.md §4.
// Flow (modes.deadFront.flow; message codes of stringtable_deadfront.txt#<map>):
//   waitStart: team 0 at fields[m].starts[0], entrance barriers 101-104 stand (IsCreate 0)          1001, 1002 (5..1)
//   fortress : 1003 (battle BGM 3001), entrances removed. Lane A: kill the guards of each canyon barrier (vine pillar
//              DEAD) 1101/1102/1103; supply depots (10 s channel, 1 point each) #300|10/121/122. Junction 117 1201,
//              bridge 118 1202, Las Alhage (3 points) 1203 -> 119,136,137; inner castle 1204 -> 122 + ivy 138-141.
//              Levers (NE/NW/SE/SW slate-room levers 10001-10020) open their slate-room gates 123-126 (1601).
//              Slates (10 s gauge) 1205-1209; Ancient Book 1210 (all four slates) or 1211 -> 127,128,129,133,134;
//              secret wall 1212 -> 135,142; Oppucus (5 points): entrance lines 1301-1303, Wall of Fire 130 falls and
//              the Orphina statues 131/132 open, transformation 1304-1306 at half HP, death 1307-1309;
//              armories 1505/1506 -> wood fences 120/121; after the final PvP result, the winning team reaches the
//              native winner room and its treasure boxes (tier block of 9).
//   final    : uncontested win when Oppucus died (else loss), winnerRespawn / loserRespawn, result window.
//   waitClose: 300 s, Reezena (30001) or the timer -> endWarRespawn (Chain of Fire 45 / 84).
// INFERRED (server script not shipped, events.md §4.4): guard placement (lane slot k guards canyon barrier k, the 4th
// guards barrier 3; fortress groups along the road 117 -> 118 -> 119, keep groups in the slate rooms), group size
// (soloRules groupSize 6), the lever -> slate-room gate binding, the boss spawn at the Orphina statues.
import { PartyWarRun } from './partywar.js';
import { DEAD_FRONT_ENGINE_CHOSEN as DF } from '../../config/engine-chosen-dungeon.js';

// guard placement, group size and the boss / end message timings are ENGINE-CHOSEN (config)
const GROUP_SIZE = DF.groupSize;
const LANE = 'A';

export class DeadFrontRun extends PartyWarRun {
  constructor(sys, map, opts) {
    super(sys, map, opts, 'deadFront');
    this.layout = this.M.layout || {};
    this.lane = this.layout.lanes?.[LANE] || {};
    const t = this.tierInfo?.tier || {};
    this.tier = t;
    this.slotMon = new Map((t.monsters?.slots || []).map(([s, m]) => [Number(s), Number(m)]));
    this.objective = this.info.objectiveNpcs || {};
    this.levers = new Set();
    this.slates = new Set();
    this.depots = new Set();
    this.bossHalf = false;
  }

  mon(slot) { return this.slotMon.get(slot) ?? ((this.tier.monsters?.base ?? 0) + slot); }

  // ------------------------------------------------------------------------------------------ setup
  async onWaitStart() {
    // routes and guard posts are computed on the empty grid, then the bricks go up
    this._planRoute();
    await this.bricks.spawnInitial();
    await this.bricks.spawnAll(this.layout.entrances || [101, 102, 103, 104]);
  }

  /** Routes of the lanes in play (planLanes; solo: lane A). A multi-party war (server/world/party-war.mjs) plans every
   *  lane during waitStart because teams k = lane A-D (layout.lanes[L].team) can still join. */
  _planRoute() {
    this.laneLegs = {};
    for (const L of this.planLanes || [LANE]) this.laneLegs[L] = this._routeOf(L);
    this.legs = this.laneLegs[LANE] || Object.values(this.laneLegs)[0] || [];
  }

  /** Points along the walkable route: lane start -> barrier 1..3 -> 117 -> 118 -> 119 (the guard posts). */
  _routeOf(L) {
    const w = this.game.world;
    const lane = this.layout.lanes?.[L] || {};
    const at = uid => { const p = this.bricks.placements.get(uid); return p ? { x: p.x, z: p.z } : null; };
    const start = this.point(this.field.starts?.[lane.team ?? this.team]) || { x: 374.5, z: 22.5 };
    const legs = [];
    let from = start;
    const route = [...(lane.barriers || []), 117, 118, 119];
    for (const uid of route) {
      const to = at(uid);
      if (!to) continue;
      const path = w?.findPath?.(from.x, from.z, to.x, to.z) || [to];
      legs.push({ uid, from, to, path: [from, ...path] });
      from = to;
    }
    return legs;
  }

  /** A point `back` cells before the end of a leg (on the approach side), snapped to a walkable cell. */
  _postBefore(uid, back = DF.laneGuardBack) {
    const leg = this.legs?.find(l => l.uid === uid) || Object.values(this.laneLegs || {}).flat().find(l => l.uid === uid);
    const w = this.game.world;
    if (!leg) { const p = this.bricks.placements.get(uid); return p ? { x: p.x, z: p.z } : null; }
    const pts = leg.path;
    let left = back;
    for (let i = pts.length - 1; i > 0; i--) {
      const a = pts[i - 1], b = pts[i];
      const d = Math.hypot(b.x - a.x, b.z - a.z);
      if (d >= left) {
        const f = (d - left) / d;
        const p = { x: a.x + (b.x - a.x) * f, z: a.z + (b.z - a.z) * f };
        return w?.isWalkable(p.x, p.z) ? p : (w?.nearestWalkable(p.x, p.z, 6) || p);
      }
      left -= d;
    }
    return pts[0];
  }
  /** Points spread along a leg (fractions of its length). */
  _alongLeg(uid, frac) {
    const leg = this.legs?.find(l => l.uid === uid);
    if (!leg) return null;
    const pts = leg.path;
    let total = 0;
    for (let i = 1; i < pts.length; i++) total += Math.hypot(pts[i].x - pts[i - 1].x, pts[i].z - pts[i - 1].z);
    let want = total * frac;
    for (let i = 1; i < pts.length; i++) {
      const a = pts[i - 1], b = pts[i];
      const d = Math.hypot(b.x - a.x, b.z - a.z);
      if (d >= want) { const f = want / Math.max(d, 1e-6); return { x: a.x + (b.x - a.x) * f, z: a.z + (b.z - a.z) * f }; }
      want -= d;
    }
    return pts[pts.length - 1];
  }

  _group(key, slot, at, count = GROUP_SIZE, opts = {}) {
    const mon = this.mon(slot);
    return this.waves.spawn(key, [{ monster: mon, x: at.x, z: at.z, radius: count > 1 ? 3 : 0, count, exact: true }], { aggressive: true, ...opts });
  }

  // ------------------------------------------------------------------------------------------ fortress
  onFortress() {
    this.bricks.removeAll(this.layout.entrances || [101, 102, 103, 104], 'die');
    // every lane in play (teamLanes: the lanes of the war's teams; solo: lane A) gets its own canyon guards
    for (const L of this.teamLanes || [LANE]) {
      const lanes = this.M.laneSlots?.[L] || [2, 7, 8, 22];
      const barriers = this.layout.lanes?.[L]?.barriers || [105, 106, 107];
      // lane guards: slot k at barrier k, the 4th slot also at barrier 3
      barriers.forEach((uid, k) => {
        const post = this._postBefore(uid, DF.laneGuardBack);
        if (!post) return;
        const slots = k < 2 ? [lanes[k]] : lanes.slice(2);
        slots.forEach((s, j) => this._group(`${this._canyonKey(L, k + 1)}${j}`, s, { x: post.x + j * DF.laneGuardSpread, z: post.z + j * DF.laneGuardSpread }));
      });
      this.after(DF.canyonWatchSec, () => this._watchCanyon(1, L));
    }
  }

  /** Wave key prefix of canyon k of lane L (lane A keeps the solo keys canyon<k>_). */
  _canyonKey(L, k) { return L === LANE ? `canyon${k}_` : `canyon${L}${k}_`; }

  _watchCanyon(k, L = LANE) {
    const keys = [...this.waves.groups.keys()].filter(g => g.startsWith(this._canyonKey(L, k)));
    const check = () => {
      if (this.ended) return;
      if (keys.every(g => this.waves.isDone(g))) this._canyonBroken(k, L);
      else this.after(0.5, check);
    };
    check();
  }

  _canyonBroken(k, L = LANE) {
    const uid = (this.layout.lanes?.[L]?.barriers || this.lane.barriers || [])[k - 1];
    if (uid) this.bricks.remove(uid, 'die');
    this.say(1100 + k);
    if (k < 3) this._watchCanyon(k + 1, L);
    // the junction (117) and the fortress road are shared: the first lane through opens them
    else if (!this._junctionOpen) { this._junctionOpen = true; this.after(3, () => this._junction()); }
  }

  _junction() {
    this.bricks.remove(117, 'die');
    this.say(1201);
    // fortress road: the first five fortress groups before the bridge, the next five up to Las Alhage
    const F = this.M.fortressSlots || [0, 1, 26, 12, 31, 32, 13, 15, 27, 33, 14, 16, 17, 18, 28, 21];
    const iMid = F.indexOf(14);
    const road = F.slice(0, iMid);
    const firstHalf = road.slice(0, Math.ceil(road.length / 2));
    const secondHalf = road.slice(firstHalf.length);
    firstHalf.forEach((s, i) => { const p = this._alongLeg(118, (i + 1) / (firstHalf.length + 1)); if (p) this._group(`bridge_${i}`, s, p); });
    secondHalf.forEach((s, i) => { const p = this._alongLeg(119, (i + DF.roadSecondLegOffset) / (secondHalf.length + DF.roadSecondLegOffset)); if (p) this._group(`road_${i}`, s, p); });
    this._when(() => firstHalf.every((_, i) => this.waves.isDone(`bridge_${i}`)), () => this._bridge());
    // Las Alhage in front of his Magical Field
    const post = this._postBefore(119, DF.midBossBack);
    this.midBoss = this.tier.bosses?.mid ?? this.mon(14);
    this.waves.spawn('midBoss', [{ monster: this.midBoss, x: post.x, z: post.z, exact: true }], {
      aggressive: true,
      onDone: () => this._midBossDead(),
    });
  }

  _bridge() { this.bricks.remove(118, 'die'); this.say(1202); }

  _midBossDead() {
    this.addScore(this.pointsFor(this.midBoss) || this.tier.bosses?.midPoints || 3);
    this.first('defeat', this.data.monsterInfo(this.midBoss)?.name || 'Las Alhage');
    this.bricks.removeAll([119, 136, 137], 'die');
    this.say(1203);
    this.after(DF.innerOpenSec, () => {
      this.bricks.removeAll([122, 138, 139, 140, 141], 'die');
      this.say(1204);
      this.innerOpen = true;
      // keep groups: one per slate room, next to its slate
      const F = this.M.fortressSlots || [];
      const keep = F.slice(F.indexOf(14) + 1, F.indexOf(21) >= 0 ? F.indexOf(21) : undefined);
      (this.objective.slates || []).forEach((npc, i) => {
        const s = keep[i % keep.length];
        const pl = this._npcPos(npc);
        if (pl && s != null) this._group(`keep_${i}`, s, this._near(pl, 5));
      });
    });
  }

  _npcPos(npcIndex, nth = 0) {
    const rows = (this.info.npcs || []).filter(r => Number(r[0]) === Number(npcIndex));
    const r = rows[nth];
    return r ? { x: Number(r[1]), z: Number(r[2]) } : null;
  }
  _near(p, r) {
    const w = this.game.world;
    for (let i = 0; i < 12; i++) {
      const a = Math.random() * Math.PI * 2;
      const q = { x: p.x + Math.cos(a) * r, z: p.z + Math.sin(a) * r };
      if (!w || w.isWalkable(q.x, q.z)) return q;
    }
    return w?.nearestWalkable(p.x, p.z, 8) || p;
  }
  _when(cond, fn) {
    const check = () => { if (this.ended) return; if (cond()) fn(); else this.after(0.5, check); };
    check();
  }

  // ------------------------------------------------------------------------------------------ NPCs
  npcPage(npc) {
    const id = Number(npc.npcIndex ?? npc.def?.index);
    const O = this.objective;
    const title = npc.name;
    const greet = this.data.npc(id)?.greeting || '';
    const nth = this._nthOf(npc, id);
    const sn = (this.info.scriptNpcs || []).filter(s => Number(s.npc) === id)[nth] || (this.info.scriptNpcs || []).find(s => Number(s.npc) === id);
    if ((O.depot || []).includes(id)) return this._depotPage(npc, id, greet);
    if (id === 5672) return this.exitPage(npc);
    if (!sn) return null;
    const label = this.text(sn.jobIndex);
    const info = this.text(sn.infoNode);
    const opt = (sn.options || []).map(c => this.text(c));
    const exc = this.text(sn.exceptionNodes?.[0]);
    const page2 = (options) => ({ title, text: info, options });
    const done = (txt) => ({ title, text: txt || exc, options: [] });
    const cancel = { label: opt[1], pick: () => this.sys.dialog.close() };
    let first = null;
    if ((O.levers || []).includes(id)) {
      const k = O.levers.indexOf(id);
      first = () => (!this.innerOpen || this.levers.has(k)) ? done(exc) : page2([{ label: opt[0], pick: () => this._lever(k) }, cancel]);
    } else if ((O.slates || []).includes(id)) {
      const k = O.slates.indexOf(id);
      first = () => (!this.levers.has(k) || this.slates.has(k)) ? done(exc) : page2([{ label: opt[0], pick: () => this._slate(k, sn) }, cancel]);
    } else if ((O.book || []).includes(id)) {
      first = () => this.bookDone ? done(exc) : page2([{ label: opt[0], pick: () => this._book() }, cancel]);
    } else if ((O.secretWall || []).includes(id)) {
      first = () => (!this.bookDone || this.wallDone) ? done(exc) : page2([{ label: opt[0], pick: () => this._secretWall() }, cancel]);
    }
    if (!first) return null;
    return { title, text: greet, options: [{ label, pick: () => this.sys.dialog.show(first()) }] };
  }

  _nthOf(npc, id) {
    const rows = (this.info.npcs || []).filter(r => Number(r[0]) === id);
    let best = 0, bd = Infinity;
    rows.forEach((r, i) => { const d = Math.hypot(Number(r[1]) - npc.x, Number(r[2]) - npc.z); if (d < bd) { bd = d; best = i; } });
    return best;
  }

  _lever(k) {
    this.sys.dialog.close();
    this.levers.add(k);
    this.say(1601);
    const gate = [123, 124, 125, 126][k];
    if (gate) this.bricks.remove(gate, 'die');
  }

  async _slate(k, sn) {
    this.sys.dialog.close();
    const node = this.data.mapStr(this.map, sn.options?.[0]);
    const g = node?.gauge || { ms: 10000, text: 'Slate Deciphering ...' };
    this.say(1205);
    if (g.snd) this.msg.code(g.snd[0], g.snd[1], g.snd[2], g.snd[3], this.player);
    const ok = await this.channel(g.text, g.ms);
    if (!ok || this.ended) return;
    this.slates.add(k);
    this.say(1206 + k);
  }

  _book() {
    this.sys.dialog.close();
    if (this.slates.size < 4) { this.say(1211); return; }
    this.bookDone = true;
    this.say(1210);
    this.bricks.remove(127, 'die');
    this.bricks.remove(128, 'open');
    this.bricks.removeAll([129, 133, 134], 'die');
  }

  _secretWall() {
    this.sys.dialog.close();
    this.wallDone = true;
    this.say(1212);
    this.bricks.removeAll([135, 142], 'die');
    this.after(DF.finalBossDelaySec, () => this._finalBoss());
  }

  _finalBoss() {
    const [a, b, c] = [1301, 1302, 1303];
    this.say(a);
    this.after(DF.finalBossLineSec[0], () => this.say(b));
    this.after(DF.finalBossLineSec[1], () => {
      this.say(c);
      this.bricks.remove(130, 'die');
      for (const u of [131, 132]) this.bricks.get(u)?.play('open', { loop: false });
      const p = this.bricks.placements.get(132) || this.bricks.placements.get(131);
      this.finalBoss = this.tier.bosses?.final ?? this.mon(21);
      this.waves.spawn('finalBoss', [{ monster: this.finalBoss, x: p ? p.x - DF.finalBossOffsetX : 192, z: p ? p.z : 392, exact: true }], {
        aggressive: true,
        onSpawn: (m) => { this.finalActor = m; },
        onDone: () => this._finalBossDead(),
      });
    });
  }

  tick(dt) {
    super.tick(dt);
    const m = this.finalActor;
    if (m && !m.dead && !this.bossHalf && m.maxHp > 0 && m.hp <= m.maxHp * DF.bossHalfHp) {
      this.bossHalf = true;
      this.say(1304);
      this.after(DF.bossHalfLineSec[0], () => this.say(1305));
      this.after(DF.bossHalfLineSec[1], () => this.say(1306));
    }
  }

  _finalBossDead() {
    this.bossDead = true;
    this.addScore(this.pointsFor(this.finalBoss) || this.tier.bosses?.finalPoints || 5);
    this.first('defeat', this.data.monsterInfo(this.finalBoss)?.name || 'Oppucus');
    this.say(1307);
    this.after(DF.endLineSec[0], () => this.say(1308));
    this.after(DF.endLineSec[1], () => this.say(1309));
    this.after(DF.armorySec, () => {
      this.bricks.remove(120, 'die'); this.say(1505);
      this.bricks.remove(121, 'die'); this.after(DF.armorySecondSec, () => this.say(1506));
      this.after(DF.winResolveSec, () => this.resolveFinal(true));
    });
  }

  _treasure() {
    if (this.treasureSpawned) return;
    this.treasureSpawned = true;
    const boxes = this.tier.treasureBoxes || [];
    const winner = this.point(this.field.winnerRespawn);
    if (!winner) return;
    const w = this.game.world;
    boxes.forEach((mon, i) => {
      const x = winner.x + ((i % 3) - 1) * 3;
      const z = winner.z + (Math.floor(i / 3) - 1) * 3;
      const p = w?.nearestWalkable?.(x, z, 5) || { x, z };
      this.waves.spawn(`box_${i}`, [{ monster: mon, x: p.x, z: p.z, exact: true }], {
        onSpawn: m => { m.eventTreasure = true; },
      });
    });
  }

  rewards() {
    if (this.won) this._treasure();
    super.rewards();
  }

  objectiveDone() { return !!this.bossDead; }

  // ------------------------------------------------------------------------------------------ supply depots
  _depotPage(npc, id, greet) {
    const row = (this.M.depots || []).find(d => Number(d[0]) === id);
    const rank = row ? Number(row[1]) : 1;
    const sec = row ? Number(row[2]) : 10;
    const label = this.data.jobTypeLabel?.(39) || this.data.ev.jobTypes?.[39]?.label || 'Attempt to Occupy Supply Depot';
    return {
      title: npc.name, text: greet,
      options: [{ label, pick: () => this._occupy(npc, id, rank, sec) }],
    };
  }

  async _occupy(npc, id, rank, sec) {
    this.sys.dialog.close();
    if (this.phase !== 'fortress') { this.pw(200, 2); return; }
    if (this.depots.has(id)) { this.pw(300, 107); return; }
    this.pw(300, 120);
    const ok = await this.channel(this.data.txt(this.pwFile, 300, 10).replace('%d', String(rank)), sec * 1000);
    if (!ok || this.ended) { this.say(1108); return; }
    this.depots.add(id);
    this.pw(300, 121, { args: [rank] });
    this.addScore(this.pointsFor(id) || 1, 'depot');
  }
}
