// Ice Castle ("Tower of Shield"), maps 167-174 (dead_front_2.map). docs/formats/events.md §5.
// Every brick is IsCreate 0 (the script builds the castle when the battle starts); the waves are data
// (maps[m].calls, exact cells). Solo: team 0 starts in corner 0; spawnAllCorners (default on) also fills the corners of
// the absent teams, because the call tables define the whole map.
//   barbican 1/2/3 : each Old Iron Gate opens when the call groups nearest to it are cleared (teamCorners: corner 0 =
//                    calls 1-2 -> gates 101/105), 1101 / 1104 / 1107. Wolf Statues (36818) and Crystals (36819) are
//                    destructible for points 1102/1103, 1201/1202; Arils 1105/1106.
//   castle gates   : the Old Iron gates 117-124 open when their gate packs (calls 37-64) die; 121/122 are the western
//                    paw altar doors (1204/1208, both 1203), 123/124 the eastern ones (1215/1219, both 1214).
//   paw altars     : (the near-monster refusal 1206 was removed, Lane 68: no source for its radius); operating them (1207 / 1211 /
//                    1218 / 1222, Dreamy Light OPENBRICK); both paws of a side melt its ice shield (1212 / 1223: ice
//                    barrier 129 / 130) and enable its lever; the lever opens the central gates (1213 / 1224: 125+127 /
//                    126+128) and releases that side's Qusil (calls 87-90 / 92-95). Qusil 1225-1228, Regina 30000.
//   Asla Statue    : needs a middle boss dead (10033); lending power (10031) starts the tower defence: lines
//                    1301-1303, the Tower of Shield (36820, HP 100) rises at the target (248.29, 266.37).
//   tower defence  : online 3 rounds x 3 waves over the Global scriptmonster order (Karke from round 3 wave 2); rounds
//                    1-2 use 4 of the 6 Gates of Devildom 142-147 at random, round 3 all 6; attackers walk to the target;
//                    within reach they hit the tower for towerDamage (10, Karke 100) and vanish. 0 HP = the defence fails. Re-energize: 100 000 DIL
//                    at the Asla Statue (10034-10037).
//   cleared        : 1505, end lines, then the older server reference close frame (ice-castle-script-ref.js) -> 166.
import { PartyWarRun } from './partywar.js';
import { MarchBrain } from './waves.js';
import { payDil } from './inventory.js';
import { hudLog } from './text.js';
import { ICE_CASTLE_GLOBAL as G, ICE_CASTLE_SCRIPT_TIMINGS as T, ICE_CASTLE_TOWER_DEFENCE as D } from '../../config/ice-castle-script-ref.js';
import { correctedEventCalls } from './native-event-call-corrections.js';

// Lane 68: every value is labelled in src/config/ice-castle-script-ref.js (Global / older server reference / online);
// the invented wave size, wave gap, stage split, paw radius and tower warning HP were removed.
const REENERGIZE_DIL = G.reenergizeDil;

// Client data\script\partywar\icecastle.csv (43.12.0): [id, x, z, name, partywar #400 code]; client groups by name.
export const ICE_CHECKPOINTS = Object.freeze([[0,45,113,'Wolf Statue',3],[1,58,377,'Wolf Statue',3],[2,460,114,'Wolf Statue',3],[3,458,380,'Wolf Statue',3],
  [4,183,38,'Aril',1],[5,183,464,'Aril',1],[6,336,38,'Aril',1],[7,336,464,'Aril',1],[8,253,21,'Crystal',3],[9,256,493,'Crystal',3],
  [10,256,158,'Qusil',1],[11,256,363,'Qusil',1],[12,248,266,'Karke',2]]);
const FIRST_KIND = { 1102: 'Wolf Statue', 1105: 'Aril', 1201: 'Crystal', 1225: 'Qusil' };

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
    this.towerHp = G.towerHp;
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
      if (idx === 36818) { this.once(1102, b); this.say(1103); this.addScore(this.pointsFor(36818) || 1); }
      if (idx === 36819) { this.once(1201, b); this.say(1202); this.addScore(this.pointsFor(36819) || 1); }
    };
  }

  /** A first-time announcement of the map table (1102 / 1105 / 1201 / 1225: "Party <team> has ... for the first time"). */
  once(code, at = null) {
    if (this.flags.has(`first${code}`)) return;
    this.flags.add(`first${code}`);
    if (FIRST_KIND[code]) this.checkpoint(FIRST_KIND[code], at);
    this.say(code, { vars: this.vars() });
  }

  /** First owner of a checkpoint group: the icecastle.csv row of that kind nearest to `at` (first row when `at` has no x/z). */
  checkpoint(kind, at = null) {
    const rows = ICE_CHECKPOINTS.filter(r => r[3] === kind);
    if (!rows.length || (this.checkpoints ||= new Map()).has(kind)) return null;
    const d = r => (at && Number.isFinite(at.x) && Number.isFinite(at.z) ? Math.hypot(r[1] - at.x, r[2] - at.z) : 0);
    const row = rows.reduce((a, r) => (d(r) < d(a) ? r : a));
    const c = { id: row[0], kind, code: row[4], team: null };
    this.checkpoints.set(kind, c);
    this.onCheckpoint?.(c);          // party-war layer fills c.team
    return c;
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
    for (const k of arils) this._spawnCall(k, { onKill: (m) => { if (bossSet.has(Number(m.monsterIndex))) { this.once(1105, m); this.say(1106); this.addScore(this.pointsFor(m.monsterIndex) || 1); } } });
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
    const gateOpen = { 5172: 121, 5173: 122, 5175: 123, 5176: 124 }[id];
    if (gateOpen && this.bricks.standing(gateOpen)) { hudLog(this.game, this.text(sn.exceptionNodes?.[0]), 'err'); return; }
    // Lane 68: the "too many monsters" refusal (1206 / 1210 / 1217 / 1221) is removed: no source gives its radius.
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
        this.once(1225, m);
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
    if (this.tower || this.towerStarting) return { text: t(10032), options: opts };
    if (this.midDead <= 0) return { text: t(10033), options: [] };
    return { text: t(sn.infoNode), options: [{ label: t(10031), pick: () => this._startTower() }] };
  }

  _reenergize() {
    this.sys.dialog.close();
    if (!this.tower || this.cleared || this.towerHp >= G.towerHp) { this.say(10036); return; }
    if (!payDil(this.game, REENERGIZE_DIL)) { this.say(10037); return; }
    this.towerHp = G.towerHp;
    this.ui.tower(1);
    this.say(10035);
  }

  // ------------------------------------------------------------------------------------------ script frame
  // Lane 68: start / close / fail follow the older server reference Dead Front frame (ice-castle-script-ref.js), whose
  // message codes Ice Castle shares 1:1 (Global stringtables). 300:105 / 300:106 are Global (partywar2).
  /** waitStart = the 1001 / 1002 / start steps (120 + 55 + 5 = Global waitStart 180). */
  waitStartSec() { return T.firstNoticeSec + T.countdownSec + T.startSec; }
  fortressSec() { return T.fortressSec; }

  onPhaseEnd(id) {
    // the cleared tower defence resolves itself (its end lines are still playing)
    if (id === 'fortress' && this.cleared) return;
    return super.onPhaseEnd(id);
  }

  tick(dt) {
    super.tick(dt);
    if (this.phase === 'waitStart' && this.phaseT <= this.waitStartSec() - T.firstNoticeSec && !this.flags.has('ic1001')) { this.flags.add('ic1001'); this.say(1001); }
    if (this.phase === 'waitClose' && !this.failed) {
      const [, , c, d] = T.closeLineSec;
      if (this.phaseT <= G.closeNoticeSec && !this.flags.has('ic300106')) { this.flags.add('ic300106'); this.pw(G.closeNotice[0], G.closeNotice[1]); }
      if (this.phaseT <= c + d && !this.flags.has('ic1502')) { this.flags.add('ic1502'); this.say(1502); }
      if (this.phaseT <= d && !this.flags.has('ic1002')) { this.flags.add('ic1002'); this.say(1002); }
    }
  }

  /** The close step: 1501 to everybody, (solo win) 1403 + 300:105, the treasure boxes, rewards; +7 s waitClose. */
  _closeStep() {
    if (this.closeStepped || this.ended) return;
    this.closeStepped = true;
    this.say(1501);
    if (this.won && !((this.teamIds?.length || 1) > 1)) { this.say(1403); this.pw(G.winNotice[0], G.winNotice[1]); }
    this._treasure();
    this.rewards();
    this.after(T.closeLineSec[0], () => this.setPhase('waitClose', T.closeLineSec.slice(1).reduce((a, b) => a + b, 0)));
  }

  /** Tower down or fortress timeout: +1 s 1504, +8 s 1503, the run ends 15 s after. */
  _timeout() {
    if (this.timedOut) return;
    this.timedOut = true; this.failed = true; this.won = false;
    this._clearAttackers();
    const [a, b] = T.timeoutLineSec;
    this.after(a, () => this.say(1504));
    this.after(a + b, () => this.say(1503));
    this.setPhase('waitClose', T.timeoutEndSec);
    this.rewards();
  }

  // ------------------------------------------------------------------------------------------ tower defence
  async _startTower() {
    this.sys.dialog.close();
    if (this.tower || this.towerStarting) return;
    this.towerStarting = true;
    // Asla lines 1301-1303 (older server reference gaps of the Dead Front 1301-1303 monologue), tower rises 1 s after
    const [l1, l2, l3] = G.aslaTowerLines, [g1, g2] = T.aslaLineGapSec;
    this.say(l1);
    this.after(g1, () => this.say(l2));
    this.after(g1 + g2, () => this.say(l3));
    this.after(g1 + g2 + T.towerRiseSec, () => { void this._raiseTower(); });
  }

  async _raiseTower() {
    if (this.ended || this.tower) return;
    const tgt = this.M.towerTarget?.targets?.[0] || [...G.towerTarget, 9];
    this.target = { x: tgt[0], z: tgt[1], reach: tgt[2] || 9 };
    // the Tower of Shield rises at the target (brick 36820 is created by the script, it has no placement row)
    this.bricks.placements.set(900, { uid: 900, brick: this.M.towerBrick || G.towerBrick, x: this.target.x, z: this.target.z, dir: 0, isCreate: 0 });
    this.tower = await this.bricks.spawn(900);
    this.towerHp = G.towerHp;
    this.ui.tower(1);
    this.dmg = new Map((this.M.towerDamage?.[this.map]?.damage || []).map(([m, d]) => [Number(m), Number(d)]));
    this.karkeIds = new Set((this.bosses.karke || []).map(Number));
    this.rounds = this._buildRounds();
    this._round(0);
  }

  /** Online 3 rounds x 3 waves over the Global scriptmonster order (file order); Karke joins round 3 wave 2. */
  _buildRounds() {
    const order = (this.tierInfo?.tier?.scriptOrder || []).filter(s => typeof s === 'string' && s.startsWith('s')).map(s => Number(s.slice(1)));
    const base = this.tierInfo?.tier?.monsters?.base ?? 6500;
    const mons = order.map(s => base + s);
    const karke = mons.filter(m => this.karkeIds.has(m)), rest = mons.filter(m => !this.karkeIds.has(m));
    const n = D.rounds * D.wavesPerRound;
    const waves = Array.from({ length: n }, (_, k) => rest.slice(Math.floor(k * rest.length / n), Math.floor((k + 1) * rest.length / n)));
    const k = (D.karkeFrom.round - 1) * D.wavesPerRound + (D.karkeFrom.wave - 1);
    waves[k] = [...waves[k], ...karke];
    return Array.from({ length: D.rounds }, (_, r) => waves.slice(r * D.wavesPerRound, (r + 1) * D.wavesPerRound));
  }

  _gates(i) {
    const all = G.devildomGates.map(u => this.bricks.placements.get(u)).filter(Boolean);
    const want = D.gatesPerRound[i] ?? all.length;
    if (want >= all.length) return all;
    // online: the active gates are chosen at random, a new set each wave
    const pool = [...all];
    for (let j = pool.length - 1; j > 0; j--) { const r = Math.floor(Math.random() * (j + 1)); [pool[j], pool[r]] = [pool[r], pool[j]]; }
    return pool.slice(0, want);
  }

  _round(i) {
    if (this.ended || this.failed) return;
    if (!this.rounds[i]) return;
    this.say(G.stageStartLines[i][0]);
    this._wave(i, 0);
  }

  _wave(i, w) {
    if (this.ended || this.failed) return;
    const mons = this.rounds[i][w];
    if (!mons) { this._roundEnd(i); return; }
    if (w === 1) this.say(G.stageStartLines[i][1]);   // Global "Stage N Phase 2" with the second wave
    const gates = this._gates(i);
    const rows = [];
    for (const mon of mons) {
      const karke = this.karkeIds.has(mon);
      for (const g of karke ? gates.slice(0, 1) : gates) rows.push({ monster: mon, x: g.x, z: g.z, exact: true });
    }
    const key = `td${i}_${w}`;
    this.waves.spawn(key, rows, {
      brain: (game, m) => new MarchBrain(game, m, { target: this.target, reach: this.target.reach, onArrive: (mm) => this._hitTower(mm) }),
      onKill: (m) => { if (this.karkeIds.has(Number(m.monsterIndex))) { this.checkpoint('Karke', m); this.first('defeat', m.name); this.addScore(this.pointsFor(m.monsterIndex) || 3); } },
      onSpawn: (m) => { if (this.karkeIds.has(Number(m.monsterIndex))) this.say(G.karkeLine); },
    });
    // next wave when this one is gone (no source has a wave gap)
    this._when(() => this.waves.isDone(key), () => this._wave(i, w + 1));
  }

  /** Round end lines (older server reference boss-dead gaps +1 / +4 / +5, next step +5). */
  _roundEnd(i) {
    if (this.failed || this.ended) return;
    const last = i === this.rounds.length - 1;
    if (last) { this.cleared = true; this.say(G.roundClearLine); }
    const [a, b, c, d] = T.stageEndLineSec;
    const offs = [a, a + b, a + b + c];
    const lines = G.stageEndLines[i] || [];
    lines.forEach((code, j) => this.after(offs[j], () => { if (!this.failed) this.say(code); }));
    let t = offs[Math.max(0, lines.length - 1)] + d;
    if (!last) { this.after(t, () => this._round(i + 1)); return; }
    // round 3: then Asla 1318-1320 (Dead Front 1301-1303 gaps), then the objective is done
    const [g1, g2] = T.aslaLineGapSec;
    const [s1, s2, s3] = G.aslaEndLines;
    this.after(t, () => this.say(s1));
    this.after(t + g1, () => this.say(s2));
    this.after(t + g1 + g2, () => this.say(s3));
    this.after(t + g1 + g2 + d, () => this.resolveFinal(true));
  }

  _hitTower(m) {
    if (this.failed || this.cleared) { this.waves.removeMonster(m); return; }
    const d = this.dmg?.get(Number(m.monsterIndex)) ?? 10;   // towerdamage.csv (Global: 10, Karke 100)
    this.waves.removeMonster(m);
    this.towerHp = Math.max(0, this.towerHp - d);
    this.ui.tower(this.towerHp / G.towerHp);
    if (this.towerHp <= 0) this._towerDown();
  }

  _clearAttackers() {
    for (const k of [...(this.waves.groups?.keys?.() || [])]) if (k.startsWith('td')) this.waves.clearGroup(k);
  }

  _towerDown() {
    if (this.failed) return;
    this.bricks.remove(900, 'die');
    this._clearAttackers();
    this.resolveFinal(false);
  }

  /** Treasure boxes 3350-3358 (Global scriptmonster) at the Tower of Shield cell (Global icecastle.csv checkpoint 12). */
  _treasure() {
    if (this.treasureSpawned || !this.won) return;
    this.treasureSpawned = true;
    const at = this.target || { x: G.towerTarget[0], z: G.towerTarget[1] };
    const boxes = this.tierInfo?.tier?.treasureBoxes || [];
    boxes.forEach((mon, i) => this.waves.spawn(`box_${i}`, [{ monster: mon, x: at.x, z: at.z, exact: true }], {}));
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
