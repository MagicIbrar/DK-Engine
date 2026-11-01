// Ice Castle ("Tower of Shield"), maps 167-174 (dead_front_2.map). docs/formats/events.md §5.
// Every brick is IsCreate 0 (the script builds the castle when the battle starts); the waves are data
// (maps[m].calls, exact cells). Solo: team 0 starts in corner 0; spawnAllCorners (default on) also fills the corners of
// the absent teams, because the call tables define the whole map.
//   barbican 1/2/3 : each Old Iron Gate opens when the call groups nearest to it are cleared (teamCorners: corner 0 =
//                    calls 1-2 -> gates 101/105), 1101 / 1104 / 1107. Wolf Statues (36818) and Crystals (36819) are
//                    destructible for points 1102/1103, 1201/1202; Arils 1105/1106.
//   castle gates   : the Old Iron gates 117-124 open when their gate packs (calls 37-64) die; 121/122 are the western
//                    paw altar doors (1204/1208, both 1203), 123/124 the eastern ones (1215/1219, both 1214).
//   paw altars     : the paw switches refuse while monsters are near (10004 / 1206); operating them (1207 / 1211 /
//                    1218 / 1222, Dreamy Light OPENBRICK); both paws of a side melt its ice shield (1212 / 1223: ice
//                    barrier 129 / 130) and enable its lever; the lever opens the central gates (1213 / 1224: 125+127 /
//                    126+128) and releases that side's Qusil (calls 87-90 / 92-95). Qusil 1225-1228, Regina 30000.
//   Asla Statue    : needs a middle boss dead (10033); lending power (10031) starts the tower defence: lines
//                    1301-1303, the Tower of Shield (36820, HP 100) rises at the target (248.29, 266.37).
//   tower defence  : 3 stages (scriptOrder entries 1-8, 9-16, 17-23 + Karke, inferred), attackers leave the Gates of
//                    Devildom 142-147 and walk to the target; within 9 cells they hit the tower for towerDamage (10,
//                    Karke 100) and vanish. 25302 / 25303 warnings; 0 HP = the defence fails. Re-energize: 100 000 DIL
//                    at the Asla Statue (10034-10037).
//   cleared        : 1505, treasure boxes, uncontested final battle, result, close -> Frozen Valley 166.
import { PartyWarRun } from './partywar.js';
import { MarchBrain } from './waves.js';
import { payDil } from './inventory.js';
import { hudLog } from './text.js';
import { ICE_CASTLE_ENGINE_CHOSEN as IC } from '../../config/engine-chosen-dungeon.js';
import { correctedEventCalls } from './native-event-call-corrections.js';

// wave size / gaps, the paw-switch radius, the stage split and the message timings are ENGINE-CHOSEN (config)
const WAVE_SIZE = IC.waveSize;
const WAVE_GAP = IC.waveGapSec;
const NEAR_MONSTERS = IC.nearMonsters;
const REENERGIZE_DIL = 100000;

export class IceCastleRun extends PartyWarRun {
  constructor(sys, map, opts) {
    super(sys, map, opts, 'iceCastle');
    // ENGINE CHOICE (native-event-call-corrections.js): the one off-grid call 53 row per tier keeps its native monster
    // and stays required, relocated from the off-map Y=3752 to the likely typo cell 166,375; every other original row is
    // played as shipped. Shared host and offline runs both use this.
    const corrected = correctedEventCalls(map, this.info.calls || {});
    this.calls = corrected.calls;
    this.engineChoices = corrected.engineChoices;
    this.corner = this.M.teamCorners?.[this.team] || { calls: [1, 2], gates: [101, 105], statue: 131 };
    this.bosses = this.info.bosses || {};
    this.paws = new Set();
    this.levers = new Set();
    this.towerHp = 100;
    this.midDead = 0;
  }

  async onWaitStart() {
    await this.bricks.spawnAll(this.bricks.rows().map(p => p.uid));
  }

  // ------------------------------------------------------------------------------------------ helpers
  _callCenter(k) {
    const rows = this.calls[k] || [];
    if (!rows.length) return null;
    let x = 0, z = 0;
    for (const r of rows) { x += r[1] + 0.5; z += r[2] + 0.5; }
    return { x: x / rows.length, z: z / rows.length };
  }
  _spawnCall(k, opts = {}) { return this.waves.spawn(`c${k}`, this.calls[k] || [], { aggressive: true, ...opts }); }
  _allDone(keys) { return keys.every(k => this.waves.isDone(`c${k}`)); }
  _when(cond, fn) { const check = () => { if (this.ended) return; if (cond()) fn(); else this.after(0.5, check); }; check(); }

  /** Open each gate when the calls nearest to it are dead. gates: uids; calls: call indices. */
  _guardGates(gates, calls, onOpen) {
    const at = u => this.bricks.placements.get(u);
    const byGate = new Map(gates.map(g => [g, []]));
    for (const c of calls) {
      const cc = this._callCenter(c);
      if (!cc) continue;
      let best = null, bd = Infinity;
      for (const g of gates) { const p = at(g); if (!p) continue; const d = Math.hypot(p.x - cc.x, p.z - cc.z); if (d < bd) { bd = d; best = g; } }
      if (best != null) byGate.get(best).push(c);
    }
    for (const [g, cs] of byGate) {
      this._when(() => this._allDone(cs), () => { this.bricks.remove(g, 'open'); onOpen?.(g); });
    }
    return byGate;
  }

  // ------------------------------------------------------------------------------------------ flow
  onFortress() {
    const cornerCalls = [1, 2, 4, 5, 7, 8, 10, 11];
    for (const k of cornerCalls) this._spawnCall(k);
    // barbican 1: each corner's two gates (teamCorners), 1101 when the player's corner opens
    const corners = this.M.teamCorners || [];
    for (const c of corners) {
      this._when(() => this._allDone(c.calls), () => {
        this.bricks.removeAll(c.gates || [], 'open');
        // barbican 2 onward is shared: the first corner of a team in play (teamIds; solo: team 0) moves the castle on
        if ((this.teamIds || [this.team]).includes(c.team) && !this._barbican1Open) { this._barbican1Open = true; this._barbican1(); }
      });
    }
    this._statues();
  }

  _statues() {
    // points for each destroyed Wolf Statue / Crystal (breakable bricks die in combat -> sys routes 'death' here)
    this.onBrickDestroyed = (b) => {
      const idx = Number(b.brickIndex);
      if (idx === 36818) { this.once(1102); this.say(1103); this.addScore(this.pointsFor(36818) || 1); }
      if (idx === 36819) { this.once(1201); this.say(1202); this.addScore(this.pointsFor(36819) || 1); }
    };
  }

  /** A first-time announcement of the map table (1102 / 1105 / 1201 / 1225: "Party <team> has ... for the first time"). */
  once(code) {
    if (this.flags.has(`first${code}`)) return;
    this.flags.add(`first${code}`);
    this.say(code, { vars: this.vars() });
  }

  _barbican1() {
    if (this.flags.has('b1')) return; this.flags.add('b1');
    this.say(1101);
    const fairies = [13, 14, 16, 17, 19, 20, 22, 23];
    for (const k of fairies) this._spawnCall(k);
    this._guardGates([109, 110, 111, 112], fairies, () => { if (!this.flags.has('b2')) { this.flags.add('b2'); this.say(1104); this._barbican2(); } });
  }

  _barbican2() {
    const arils = [25, 26, 28, 29, 31, 32, 34, 35];
    const bossSet = new Set((this.bosses.aril || []).map(Number));
    for (const k of arils) this._spawnCall(k, { onKill: (m) => { if (bossSet.has(Number(m.monsterIndex))) { this.once(1105); this.say(1106); this.addScore(this.pointsFor(m.monsterIndex) || 1); } } });
    this._guardGates([113, 114, 115, 116], arils, () => { if (!this.flags.has('b3')) { this.flags.add('b3'); this.say(1107); this._castle(); } });
  }

  _castle() {
    const packs = [37, 38, 39, 42, 43, 44, 47, 48, 49, 52, 53, 54, 57, 58, 59, 62, 63, 64];
    for (const k of packs) this._spawnCall(k);
    const opened = new Set();
    this._guardGates([117, 118, 119, 120, 121, 122, 123, 124], packs, (g) => {
      opened.add(g);
      const msg = { 121: 1204, 122: 1208, 123: 1215, 124: 1219 }[g];
      if (msg) this.say(msg);
      if (g === 121 || g === 122) { if (opened.has(121) && opened.has(122)) this.say(1203); }
      if (g === 123 || g === 124) { if (opened.has(123) && opened.has(124)) this.say(1214); }
    });
    // the altar guards (Penril Priests / Giants) at the paws
    for (const k of [67, 68, 69, 72, 73, 74, 77, 78, 79, 82, 83, 84]) this._spawnCall(k);
  }

  objectiveDone() { return !!this.cleared; }

  // ------------------------------------------------------------------------------------------ NPCs
  npcPage(npc) {
    const id = Number(npc.npcIndex ?? npc.def?.index);
    const O = this.info.objectiveNpcs || {};
    const title = npc.name;
    const greet = this.data.npc(id)?.greeting || '';
    if (id === 5672) return this.exitPage(npc);
    const sn = (this.info.scriptNpcs || []).find(s => Number(s.npc) === id);
    if (!sn) return null;
    const t = c => this.text(c);
    const close = () => this.sys.dialog.close();
    if (id === 5671) {
      // Regina (middle): "I want to continue on" -> into the Tower of Shield chamber
      return { title, text: greet, options: [{ label: t(30000), pick: () => { close(); if (this.midDead > 0) this.teleport(this._near({ x: 255.5, z: 280 }, 2)); else hudLog(this.game, t(10033), 'err'); } }] };
    }
    const first = () => {
      if ((O.paws || []).includes(id)) return this._pawPage(id, sn);
      if ((O.levers || []).includes(id)) return this._leverPage(id, sn);
      if ((O.asla || []).includes(id)) return this._aslaPage(sn);
      return null;
    };
    return { title, text: greet, options: [{ label: t(sn.jobIndex), pick: () => { const p = first(); if (p) this.sys.dialog.show({ title, ...p }); } }] };
  }

  _side(id) { return [5172, 5173, 5174].includes(id) ? 'west' : 'east'; }

  _pawPage(id, sn) {
    const t = c => this.text(c);
    if (this.paws.has(id)) return { text: t(sn.exceptionNodes?.[1] ?? sn.exceptionNodes?.[0]), options: [] };
    return { text: t(sn.infoNode), options: [{ label: t(sn.options?.[0]), pick: () => this._paw(id, sn) }] };
  }

  _paw(id, sn) {
    this.sys.dialog.close();
    const npc = this.game.npcs.find(n => Number(n.npcIndex) === id);
    const near = npc ? this.game.spawner?.near?.(npc.x, npc.z, NEAR_MONSTERS)?.filter(m => !m.brickDef) || [] : [];
    const gateOpen = { 5172: 121, 5173: 122, 5175: 123, 5176: 124 }[id];
    if (gateOpen && this.bricks.standing(gateOpen)) { hudLog(this.game, this.text(sn.exceptionNodes?.[0]), 'err'); return; }
    if (near.length) { this.say({ 5172: 1206, 5173: 1210, 5175: 1221, 5176: 1217 }[id] ?? 1206); return; }
    this.paws.add(id);
    this.say({ 5172: 1207, 5173: 1211, 5175: 1222, 5176: 1218 }[id] ?? 1207);
    const light = { 5172: 138, 5173: 139, 5175: 140, 5176: 141 }[id];
    this.bricks.get(light)?.play('open', { loop: false });
    if (this.paws.has(5172) && this.paws.has(5173) && !this.flags.has('iceW')) { this.flags.add('iceW'); this.say(1212); this.bricks.remove(129, 'die'); }
    if (this.paws.has(5175) && this.paws.has(5176) && !this.flags.has('iceE')) { this.flags.add('iceE'); this.say(1223); this.bricks.remove(130, 'die'); }
  }

  _leverPage(id, sn) {
    const t = c => this.text(c);
    const side = this._side(id);
    const ready = side === 'west' ? this.flags.has('iceW') : this.flags.has('iceE');
    if (!ready || this.levers.has(id)) return { text: t(sn.exceptionNodes?.[0]), options: [] };
    return { text: t(sn.infoNode), options: [{ label: t(sn.options?.[0]), pick: () => this._lever(id, side) }] };
  }

  _lever(id, side) {
    this.sys.dialog.close();
    this.levers.add(id);
    const west = side === 'west';
    this.say(west ? 1213 : 1224);
    this.bricks.removeAll(west ? [125, 127] : [126, 128], 'open');
    const calls = west ? [87, 88, 89, 90] : [92, 93, 94, 95];
    const q = new Set((this.bosses.qusil || []).map(Number));
    for (const k of calls) this._spawnCall(k, {
      onKill: (m) => {
        if (!q.has(Number(m.monsterIndex))) return;
        this.midDead++;
        this.once(1225);
        this.say(1226);
        this.say(west ? 1227 : 1228);
        this.addScore(this.pointsFor(m.monsterIndex) || 1);
      },
    });
  }

  _aslaPage(sn) {
    const t = c => this.text(c);
    const opts = [];
    if (this.tower && !this.cleared) opts.push({ label: t(10034), pick: () => this._reenergize() });
    if (this.tower) return { text: t(10032), options: opts };
    if (this.midDead <= 0) return { text: t(10033), options: [] };
    return { text: t(sn.infoNode), options: [{ label: t(10031), pick: () => this._startTower() }] };
  }

  _reenergize() {
    this.sys.dialog.close();
    if (!this.tower || this.cleared || this.towerHp >= 100) { this.say(10036); return; }
    if (!payDil(this.game, REENERGIZE_DIL)) { this.say(10037); return; }
    this.towerHp = 100;
    this.ui.tower(1);
    this.say(10035);
  }

  // ------------------------------------------------------------------------------------------ tower defence
  async _startTower() {
    this.sys.dialog.close();
    if (this.tower) return;
    this.say(1301);
    this.after(IC.towerLineSec[0], () => this.say(1302));
    this.after(IC.towerLineSec[1], () => this.say(1303));
    const tgt = this.M.towerTarget?.targets?.[0] || [248.29, 266.37, 9];
    this.target = { x: tgt[0], z: tgt[1], reach: tgt[2] || 9 };
    // the Tower of Shield rises at the target (brick 36820 is created by the script, it has no placement row)
    this.bricks.placements.set(900, { uid: 900, brick: this.M.towerBrick || 36820, x: this.target.x, z: this.target.z, dir: 0, isCreate: 0 });
    this.tower = await this.bricks.spawn(900);
    this.towerHp = 100;
    this.ui.tower(1);
    const order = (this.tierInfo?.tier?.scriptOrder || []).filter(s => typeof s === 'string' && s.startsWith('s')).map(s => Number(s.slice(1)));
    const base = this.tierInfo?.tier?.monsters?.base ?? 6500;
    const dmg = new Map((this.M.towerDamage?.[this.map]?.damage || []).map(([m, d]) => [Number(m), Number(d)]));
    this.dmg = dmg;
    this.stages = [order.slice(0, IC.stageSplit[0]), order.slice(IC.stageSplit[0], IC.stageSplit[1]), order.slice(IC.stageSplit[1])].map(st => st.map(s => base + s));
    this.after(IC.stageStartSec, () => this._stage(0));
  }

  _stage(i) {
    if (this.ended || this.failed) return;
    const st = this.stages[i];
    if (!st) { this._cleared(); return; }
    const phaseMsg = [[1304, 1305], [1309, 1310], [1314, 1315]][i];
    const endMsg = [[1306, 1307, 1308], [1311, 1312, 1313], [1316, 1317, 1318, 1319, 1320]][i];
    this.say(phaseMsg[0]);
    const gates = [142, 143, 144, 145, 146, 147].map(u => this.bricks.placements.get(u)).filter(Boolean);
    const keys = [];
    st.forEach((mon, w) => {
      this.after(w * WAVE_GAP, () => {
        if (this.ended || this.failed) return;
        if (w === Math.floor(st.length / 2)) this.say(phaseMsg[1]);
        const karke = (this.bosses.karke || []).map(Number).includes(mon);
        const n = karke ? 1 : WAVE_SIZE;
        const rows = [];
        for (let j = 0; j < n; j++) { const g = gates[(w + j) % gates.length]; rows.push({ monster: mon, x: g.x, z: g.z, radius: 1.5, exact: true }); }
        const key = `td${i}_${w}`;
        keys.push(key);
        this.waves.spawn(key, rows, {
          brain: (game, m) => new MarchBrain(game, m, { target: this.target, reach: this.target.reach, onArrive: (mm) => this._hitTower(mm) }),
          onKill: (m) => { if (karke) { this.first('defeat', m.name); this.addScore(this.pointsFor(mon) || 3); } },
          onSpawn: (m) => { if (karke) this.say(25301); },
        });
      });
    });
    this.after(st.length * WAVE_GAP, () => this._when(() => keys.length === st.length && keys.every(k => this.waves.isDone(k)), () => {
      if (this.failed) return;
      endMsg.forEach((c, j) => this.after(j * IC.stageEndLineGapSec, () => this.say(c)));
      this.after(endMsg.length * IC.stageEndLineGapSec + IC.nextStageSec, () => this._stage(i + 1));
    }));
  }

  _hitTower(m) {
    if (this.failed || this.cleared) { this.waves.removeMonster(m); return; }
    const d = this.dmg?.get(Number(m.monsterIndex)) ?? 10;
    this.waves.removeMonster(m);
    const before = this.towerHp;
    this.towerHp = Math.max(0, this.towerHp - d);
    this.ui.tower(this.towerHp / 100);
    const [w1, w2] = IC.towerWarnHp;
    if (before > w1 && this.towerHp <= w1) this.say(25302);
    if (before > w2 && this.towerHp <= w2) this.say(25303);
    if (this.towerHp <= 0) this._towerDown();
  }

  _towerDown() {
    if (this.failed) return;
    this.failed = true;
    this.bricks.remove(900, 'die');
    for (const k of [...this.waves.groups.keys()]) if (k.startsWith('td')) this.waves.clearGroup(k);
    this.say(1504);
    this.after(IC.failResolveSec, () => this.resolveFinal(false));
  }

  _cleared() {
    if (this.cleared) return;
    this.cleared = true;
    this.say(1505);
    // armory treasure boxes around the tower
    const boxes = this.tierInfo?.tier?.treasureBoxes || [];
    boxes.forEach((mon, i) => {
      const a = (i / Math.max(1, boxes.length)) * Math.PI * 2;
      const p = this._near({ x: this.target.x + Math.cos(a) * 5, z: this.target.z + Math.sin(a) * 5 }, 0.5);
      this.waves.spawn(`box_${i}`, [{ monster: mon, x: p.x, z: p.z, exact: true }], {});
    });
    this.after(IC.winResolveSec, () => this.resolveFinal(true));
  }

  _near(p, r) {
    const w = this.game.world;
    if (w?.isWalkable(p.x, p.z) && r < 1) return p;
    for (let i = 0; i < 12; i++) {
      const a = Math.random() * Math.PI * 2;
      const q = { x: p.x + Math.cos(a) * r, z: p.z + Math.sin(a) * r };
      if (!w || w.isWalkable(q.x, q.z)) return q;
    }
    return w?.nearestWalkable(p.x, p.z, 8) || p;
  }
}
