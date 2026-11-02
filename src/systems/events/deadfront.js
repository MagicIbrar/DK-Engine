// Dead Front ("Fort Focas"), maps 39-44, 60, 160 and the DK copies 77-83, 161. docs/formats/events.md §4.
// Lane 59 rebuild (owner approved): the fortress flow follows the OLDER SERVER REFERENCE triggers of
// ScriptProcess.dll (IScript::Dungeon Dead_Front_<class> / _DK), per version, values in
// src/config/dead-front-script-ref.js (every value tagged 'older server reference'; Global ships no server script).
// Reimplemented from the decoded trigger table, no script code copied. Stage (script var 0):
//   0 lanes   : all four lanes A-D get their guards at the start (1003, entrance barriers 101-104 fall). Each lane counts
//               kills of its stage monsters: count -> 1101 / 1102 / 1103, the next guards, its canyon barrier falls.
//               The first lane through its third barrier opens stage 1 and the approach groups.
//   1 junction: approach kills -> 1201, junction groups, 117 / 140 / 141 fall            2 bridge: kills -> 1202, Las Alhage,
//               118 / 138 / 139 fall      3 Las Alhage dead -> +5 s 1203, inner castle groups, 119 / 136 / 137 fall
//   4 inner   : inner-castle kills -> 1204, 122 falls (armory wood fences 120 / 121 broken now -> 1505 / 1506 + guards)
//   5 keep    : lever k (slate-room gate 123-126 + its guard), slate k after its lever, Ancient Book after all four
//               slates (1210, 127 falls; else 1211)          6: secret wall -> 1212, 129 / 133 / 134 fall
//   7 boss room: +7 s 1301 (Orphina 131 passable, 132 rises), +5 1302, +6 1303 (128 / 132 close), +1 131 falls;
//               Pitborn waves from +20 s, 8 per wave at the script spots, per-version gap / wave cap
//   8 horde   : wave kills -> +4 s 128 passable + 1304, +5 1305 (132 falls), +5 1306; +17 s Wall of Fire 130 falls,
//               Oppucus and two guards at the script spots (no half-HP trigger)
//   9 Oppucus dead: +1 1307, +4 1308, +5 1309, +5: two or more parties -> PvP (server/world/party-war.mjs), else the close
//   close     : +5 s 1501 (to all), treasure boxes at the script spots, 135 / 142 fall; +7 s waitClose (128 passable),
//               1502 with 30 s left, 1002 with 6 s left, end.  Timeout (1800 s): +1 1504, +8 1503, end at 15 s.
// Lane 59 (c): the former unknown ops are resolved from the older server reference (src/config/dead-front-script-extras.js,
// every value labelled): Op1034 = GiveExp on the mid / final boss kill, Op1c20 = the two kill-all ids on the final boss
// death, Op1c28 = kill-all at the close step, Op101ae = the treasure monsters drop Orphina's Seal / Clear Water of Volcano
// at their cells, OnLevelUp gifts (Rabble / Peer) with the Global popup strings, OnMissionFail = the timeout path.
// The NPC 4161 exchange handler is wired but no 4161 is placed (Global and the reference place none: removed).
// Supply depots, the slate channel UX (Global gauge, 1205) and the lever sound (1601) are the Global data features of
// the earlier lanes and are kept. 1602 has no trigger anywhere and is not played.
import { PartyWarRun } from './partywar.js';
import { deadFrontScript, DEAD_FRONT_SCRIPT_TIMINGS as T } from '../../config/dead-front-script-ref.js';
import { deadFrontExtras, levelUpGift, NPC_4161_EXCHANGE as EX, MISSION_FAIL } from '../../config/dead-front-script-extras.js';
import { grantExp } from '../../game/progression.js';
import { addItem } from './inventory.js';

const LANES = ['A', 'B', 'C', 'D'];
/** Script var 0 values (older server reference). */
export const DF_STAGE = Object.freeze({ lanes: 0, junction: 1, bridge: 2, midBoss: 3, inner: 4, keep: 5, wall: 6, bossRoom: 7, horde: 8, bossDead: 9 });
const S = DF_STAGE;
const sum = a => a.reduce((n, v) => n + v, 0);

export class DeadFrontRun extends PartyWarRun {
  constructor(sys, map, opts) {
    super(sys, map, opts, 'deadFront');
    this.layout = this.M.layout || {};
    this.tier = this.tierInfo?.tier || {};
    this.objective = this.info.objectiveNpcs || {};
    this.ref = deadFrontScript(map);
    this.extra = deadFrontExtras(map);                                // Lane 59 (c): resolved script ops (older server reference)
    this.stage = S.lanes;
    this.count = 0;                                                   // script var 5 (shared stage counter)
    this.laneState = (this.ref?.lanes || []).map(() => ({ stage: 0, kills: 0 }));
    this.keys = [0, 0, 0, 0];                                         // script vars 6-9: 0 / 1 lever pulled / 2 slate read
    this.waveN = 0;                                                   // script var 11
    this.depots = new Set();
    this.levers = new Set();
    this.slates = new Set();
  }

  /** waitStart length = the script's 1001 / 1002 / start steps (120 + 55 + 5 = Global timeline waitStart 180). */
  waitStartSec() { return T.firstNoticeSec + T.countdownSec + T.startSec; }
  fortressSec() { return T.fortressSec; }

  // ------------------------------------------------------------------------------------------ setup
  async onWaitStart() {
    // after installPartyWar (its brick hook setter keeps this function)
    this.onBrickDestroyed = b => this._brickDestroyed(b);
    await this.bricks.spawnInitial();
    await this.bricks.spawnAll(this.layout.entrances || [101, 102, 103, 104]);
    // script OnCreate: 128 red cell open, 132 removed
    this._passable(128, true);
    this.bricks.remove(132, 'die');
    this._listenLevelUp();
  }

  // ------------------------------------------------------------------------------------------ resolved script ops (Lane 59 c)
  /** OnLevelUp (older server reference, Rabble / Peer scripts): the gifts and the InformDialog popup (Global map string). */
  _listenLevelUp() {
    if (this._onLevelUp || !this.extra?.levelUpGifts || !this.game?.events?.on) return;
    this._onLevelUp = ({ level } = {}) => this._levelUp(level);
    this.game.events.on('levelup', this._onLevelUp);
  }
  _offLevelUp() {
    if (this._onLevelUp) this.game?.events?.off?.('levelup', this._onLevelUp);
    this._onLevelUp = null;
  }
  _levelUp(level) {
    if (this.ended) return null;
    const g = levelUpGift(this.map, level, Number(this.game?.save?.classIndex) || 0);
    if (!g) return null;
    for (const [item, count, roomItem] of g.items) this._giveOrDrop(item, count, roomItem);
    if (g.popup != null) this.say(g.popup);
    return g;
  }
  /** Item room check -> give, else drop at the player (Item+0x14 / +0x18 / +0x30 / +0x40, older server reference). */
  _giveOrDrop(item, count = 1, roomItem = item) {
    const name = this.data.item?.(item)?.name || '';
    const loot = this.game?.loot;
    const roomOk = !loot?.canFit || loot.canFit({ itemIndex: Number(roomItem), count, grade: 'normal', stack: count > 1 });
    if (roomOk && addItem(this.game, item, count, name)) return 'given';
    const p = this.player;
    loot?.spawnDrop?.({ itemIndex: Number(item), name: name || `Item ${item}`, count, grade: 'normal', stack: count > 1 }, p?.x ?? 0, p?.z ?? 0);
    return 'dropped';
  }
  /** Item+0x4c(item, x, y): an item on the ground at server cell (x, y). */
  _dropAt(item, x, y) {
    const name = this.data.item?.(item)?.name || `Item ${item}`;
    return this.game?.loot?.spawnDrop?.({ itemIndex: Number(item), name, count: 1, grade: 'normal', stack: false }, x + 0.5, y + 0.5) || null;
  }
  /** Monster+0x20 (ids) / +0x28 (no ids): take the event monsters off the map (no kill credit, no OnKillMonster). */
  _killAll(ids = null) {
    // Lane 59 (d): the shared host's waves take the monsters off its scene (server/world/dead-front-host.mjs)
    if (typeof this.waves?.killAll === 'function') return this.waves.killAll(ids);
    const set = ids ? new Set(ids.map(Number)) : null;
    let n = 0;
    for (const rec of [...(this.waves?.recs || [])]) {
      const ev = rec.event;
      if (!ev || ev.killed || ev.removed) continue;
      if (set && !set.has(Number(rec.spawn?.monsterIndex))) continue;
      if (rec.monster && !rec.monster.dead) this.waves.removeMonster(rec.monster);
      else if (!rec.monster) { rec.skip = true; ev.removed = true; ev.group.removed++; }
      else continue;
      n++;
    }
    return n;
  }
  /** Op1034 GiveExp(n) to every player on the map (older server reference). Solo: the local player; the shared host
   *  replaces this with a durable grant to every member (server/world/dead-front-host.mjs, Lane 59 d). */
  _giveExp(exp, key) { if (exp > 0) grantExp(this.game, exp); return key; }
  /** OnMissionFail (older server reference): the fortress timer expires now -> the timeout path. */
  onMissionFail() {
    if (this.ended || this.bossDead || MISSION_FAIL.action !== 'timeout') return;
    this._timeout();
  }
  /** NPC 4161 exchange (older server reference; no 4161 is placed, see dead-front-script-extras.js). */
  _exchangePage(npc) {
    const e = this.extra?.exchange;
    if (!e || this.var100 !== EX.needVar100) return null;
    const title = npc?.name || this.data.npc(EX.npc)?.name || '';
    return { title, text: this.text(EX.dialog), options: [{ label: this.text(EX.answer), pick: () => this._exchange() }] };
  }
  _exchange() {
    this.sys.dialog?.close?.();
    const e = this.extra?.exchange;
    if (!e || this.var100 !== EX.needVar100 || this.ended) return false;
    const loot = this.game?.loot;
    const fits = !loot?.canFit || (loot.canFit({ itemIndex: EX.give, count: EX.giveCount, grade: 'normal', stack: false })
      && loot.canFit({ itemIndex: e.item, count: EX.xCount, grade: 'normal', stack: true }));
    if (!fits) { this.say(EX.fullNotice); return false; }
    addItem(this.game, EX.give, EX.giveCount, this.data.item?.(EX.give)?.name || '');
    addItem(this.game, e.item, EX.xCount, this.data.item?.(e.item)?.name || '');
    if (e.dest) void this.leave({ map: e.dest.map, x: e.dest.x + 0.5, z: e.dest.y + 0.5, dirDeg: e.dest.dirDeg });
    return true;
  }
  onEnd(reason) { this._offLevelUp(); return super.onEnd?.(reason); }

  _passable(uid, on) { this.bricks.setPassable?.(uid, on); }

  /** Spawn script rows [monster, x, y, radius, count] (server cells, FILE x / z). */
  _spawn(key, rows, opts = {}) {
    if (!rows?.length) return null;
    return this.waves.spawn(key, rows.map(([monster, x, y, radius, count]) => ({ monster, x: x + 0.5, z: y + 0.5, radius, count, exact: true })), {
      ...opts,
      onKill: (m, g, killer) => { opts.onKill?.(m, g, killer); this._kill(m); },
    });
  }

  // ------------------------------------------------------------------------------------------ fortress
  onFortress() {
    if (!this.ref) return;
    this.bricks.removeAll(this.ref.start.destroy, 'die');
    this._spawn('start', this.ref.start.spawns);
  }

  _monsterOf(m) { return Number(m?.monsterIndex ?? m?.spawnRecord?.spawn?.monsterIndex ?? m?.def?.index); }

  /** OnKillMonster: lane counters, the stage counter, the two bosses. */
  _kill(m) {
    if (this.ended || this.failed || !this.ref) return;
    const id = this._monsterOf(m);
    this.ref.lanes.forEach((lane, i) => {
      const s = this.laneState[i], st = lane.stages[s.stage];
      if (!st || !st.monsters.includes(id)) return;
      if (++s.kills >= st.count) { s.stage++; s.kills = 0; this._canyonBroken(i, s.stage); }
    });
    const gate = { [S.junction]: 'junction', [S.bridge]: 'bridge', [S.inner]: 'innerGate', [S.horde]: null, [S.bossRoom]: 'horde' }[this.stage];
    const g = gate && this.ref[gate];
    if (g && g.monsters.includes(id) && ++this.count >= g.count) {
      this.count = 0;
      if (gate === 'junction') this._junction();
      else if (gate === 'bridge') this._bridge();
      else if (gate === 'innerGate') this._innerGate();
      else this._horde();
    }
    const drop = this.extra?.treasureDrops?.[id];
    if (drop && m?.eventTreasure) this._dropAt(...drop);                // Op101ae (older server reference)
    if (this.stage === S.midBoss && id === this.ref.midBoss) this._midBossDead();
    if (this.stage === S.horde && id === this.ref.boss.monster) this._finalBossDead();
  }

  /** Lane i finished stage n (1-3): its line, next guards, its canyon barrier falls. */
  _canyonBroken(i, n) {
    const st = this.ref.lanes[i].stages[n - 1];
    this.say(st.notice);
    this._spawn(`lane${LANES[i]}_${n}`, st.spawns);
    this.bricks.removeAll(st.destroy, 'die');
    if (n === 3 && this.stage === S.lanes) {
      this.stage = S.junction; this.count = 0;
      this._spawn('approach', this.ref.approach);
    }
  }

  _junction() {
    const j = this.ref.junction;
    this.stage = S.bridge;
    this.say(j.notice);
    this._spawn('junction', j.spawns);
    this.bricks.removeAll(j.destroy, 'die');
  }

  _bridge() {
    const b = this.ref.bridge;
    this.stage = S.midBoss;
    this.say(b.notice);
    this.midBoss = this.ref.midBoss;
    this._spawn('midBoss', b.spawns);
    this.bricks.removeAll(b.destroy, 'die');
  }

  _midBossDead() {
    const exp = this.extra?.bossExp?.[this.ref.midBoss];
    this._giveExp(exp, 'midBoss');                                     // Op1034 GiveExp (older server reference)
    this.addScore(this.pointsFor(this.ref.midBoss) || this.tier.bosses?.midPoints || 3);
    this.first('defeat', this.data.monsterInfo(this.ref.midBoss)?.name || 'Las Alhage');
    this.after(T.innerNoticeSec, () => {
      if (this.stage !== S.midBoss || this.failed) return;
      const n = this.ref.inner;
      this.stage = S.inner; this.count = 0;
      this.say(n.notice);
      this._spawn('inner', n.spawns);
      this.bricks.removeAll(n.destroy, 'die');
    });
  }

  _innerGate() {
    const g = this.ref.innerGate;
    this.stage = S.keep;
    this.innerOpen = true;
    this.say(g.notice);
    this.bricks.removeAll(g.destroy, 'die');
  }

  /** OnDestroyBrick: the armory wood fences 120 / 121 while the inner castle is being fought (stage 4). */
  _brickDestroyed(b) {
    const uid = Number(b?.uid);
    const a = this.ref?.armories?.[uid];
    if (!a || this.stage !== S.inner || this.failed) return;
    this.say(a.notice);
    this._spawn(`armory${uid}`, a.spawns);
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
    if (id === EX.npc) return this._exchangePage(npc);
    if (!sn || !this.ref) return null;
    const label = this.text(sn.jobIndex);
    const info = this.text(sn.infoNode);
    const opt = (sn.options || []).map(c => this.text(c));
    const exc = this.text(sn.exceptionNodes?.[0]);
    const page2 = (options) => ({ title, text: info, options });
    const done = (txt) => ({ title, text: txt || exc, options: [] });
    const cancel = { label: opt[1], pick: () => this.sys.dialog.close() };
    const k = i => this.ref.levers.findIndex(l => l.npc === i);
    const ks = i => this.ref.slates.findIndex(l => l.npc === i);
    let first = null;
    if (k(id) >= 0) {
      const i = k(id);
      first = () => (this.stage !== S.keep || this.keys[i] !== 0) ? done(exc) : page2([{ label: opt[0], pick: () => this._lever(i) }, cancel]);
    } else if (ks(id) >= 0) {
      const i = ks(id);
      first = () => this.keys[i] !== 1 ? done(exc) : page2([{ label: opt[0], pick: () => this._slate(i, sn) }, cancel]);
    } else if (this.ref.book.npc === id) {
      first = () => this.stage !== S.keep ? done(exc) : page2([{ label: opt[0], pick: () => this._book() }, cancel]);
    } else if (this.ref.wall.npc === id) {
      first = () => this.stage !== S.wall ? done(exc) : page2([{ label: opt[0], pick: () => this._secretWall() }, cancel]);
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

  _lever(i) {
    this.sys.dialog.close();
    if (this.stage !== S.keep || this.keys[i] !== 0) return;
    const l = this.ref.levers[i];
    this.keys[i] = 1; this.levers.add(i);
    this.say(1601);
    this._spawn(`lever${i}`, l.spawns);
    this.bricks.removeAll(l.destroy, 'die');
  }

  async _slate(i, sn) {
    this.sys.dialog.close();
    if (this.keys[i] !== 1) return;
    const node = this.data.mapStr(this.map, sn.options?.[0]);
    const g = node?.gauge || { ms: 10000, text: 'Slate Deciphering ...' };
    this.say(1205);
    if (g.snd) this.msg.code(g.snd[0], g.snd[1], g.snd[2], g.snd[3], this.player);
    const ok = await this.channel(g.text, g.ms);
    if (!ok || this.ended || this.keys[i] !== 1) return;
    this.keys[i] = 2; this.slates.add(i);
    this.say(this.ref.slates[i].notice);
  }

  _book() {
    this.sys.dialog.close();
    if (this.stage !== S.keep) return;
    if (!this.keys.every(v => v === 2)) { this.say(this.ref.book.notReady); return; }
    this.bookDone = true;
    this.stage = S.wall;
    this.say(this.ref.book.notice);
    this.bricks.removeAll(this.ref.book.destroy, 'die');
  }

  _secretWall() {
    this.sys.dialog.close();
    if (this.stage !== S.wall) return;
    this.wallDone = true;
    this.stage = S.bossRoom; this.count = 0; this.waveN = 0;
    this.say(this.ref.wall.notice);
    this.bricks.removeAll(this.ref.wall.destroy, 'die');
    this.after(T.bossRoomLineSec[0], () => this._finalBoss());
    this.after(T.waveFirstSec, () => this._wave());
  }

  /** Boss-room entrance lines (stage 7): 1301 / 1302 / 1303, the Orphina statues. */
  _finalBoss() {
    const [, a, b, c] = T.bossRoomLineSec;
    const on = () => this.stage === S.bossRoom && !this.failed;
    if (!on()) return;
    this.say(1301); this._passable(131, true); void this.bricks.spawn(132);
    this.after(a, () => {
      if (!on()) return;
      this.say(1302);
      this.after(b, () => {
        if (!on()) return;
        this.say(1303); this._passable(128, false); this._passable(132, false);
        this.after(c, () => { if (on()) this.bricks.remove(131, 'die'); });
      });
    });
  }

  /** One Pitborn wave: a random pick of each point's pair, at most ref.waves.max waves, ref.waves.gapSec apart. */
  _wave() {
    const w = this.ref.waves;
    if (this.stage !== S.bossRoom || this.failed || this.ended || this.waveN >= w.max) return;
    const rows = w.points.map(([x, y, pick]) => [pick[Math.floor(Math.random() * pick.length) % pick.length], x, y, 0, 1]);
    this._spawn(`wave${this.waveN}`, rows);
    this.waveN++;
    this.after(w.gapSec, () => this._wave());
  }

  /** The wave kill count was reached (stage 8): 1304-1306 on the script timer, then Oppucus (no half-HP trigger). */
  _horde() {
    this.stage = S.horde; this.count = 0;
    const [a, b, c] = T.hordeLineSec, on = () => this.stage === S.horde && !this.failed;
    this.after(a, () => {
      if (!on()) return;
      this._passable(128, true); this.say(1304);
      this.after(b, () => {
        if (!on()) return;
        this.say(1305); this.bricks.remove(132, 'die');
        this.after(c, () => { if (on()) this.say(1306); });
      });
    });
    this.after(sum(T.hordeBossSec), () => {
      if (!on()) return;
      this.bricks.removeAll(this.ref.boss.destroy, 'die');
      this.finalBoss = this.ref.boss.monster;
      this._spawn('finalBoss', this.ref.boss.spawns, { onSpawn: m => { if (this._monsterOf(m) === this.finalBoss) this.finalActor = m; } });
    });
  }

  _finalBossDead() {
    if (this.bossDead) return;
    this.bossDead = true;
    this.stage = S.bossDead;
    this._killAll(this.extra?.bossDeathKills || []);                   // Op1c20 (older server reference)
    this.var100 = 10;                                                  // script var100 = 10 (the 4161 exchange gate)
    const exp = this.extra?.bossExp?.[this.ref.boss.monster];
    this._giveExp(exp, 'finalBoss');                                   // Op1034 GiveExp (older server reference)
    this.addScore(this.pointsFor(this.ref.boss.monster) || this.tier.bosses?.finalPoints || 5);
    this.first('defeat', this.data.monsterInfo(this.ref.boss.monster)?.name || 'Oppucus');
    const [a, b, c, d] = T.bossDeadLineSec;
    this.after(a, () => this.say(1307));
    this.after(a + b, () => this.say(1308));
    this.after(a + b + c, () => this.say(1309));
    this.after(a + b + c + d, () => this.resolveFinal(true));
  }

  /** The script close step: 1501 to everybody, the treasure boxes, 135 / 142 fall, rewards; +7 s waitClose. */
  _closeStep() {
    if (this.closeStepped || this.ended) return;
    this.closeStepped = true;
    if (this.extra?.closeKillAll) this._killAll();                     // Op1c28 kill-all (older server reference)
    this.say(this.ref?.treasure?.notice ?? 1501);
    this._treasure();
    this.bricks.removeAll(this.ref?.treasure?.destroy || [], 'die');
    this.rewards();
    this.after(T.closeLineSec[0], () => {
      this._passable(128, true);
      this.setPhase('waitClose', sum(T.closeLineSec.slice(1)));
    });
  }

  /** Fortress timeout: +1 s 1504, +8 s 1503, the run ends 15 s after the timeout. */
  _timeout() {
    if (this.timedOut) return;
    this.timedOut = true; this.failed = true; this.won = false;
    this.stage = S.lanes;
    const [a, b] = T.timeoutLineSec;
    this.after(a, () => this.say(1504));
    this.after(a + b, () => this.say(1503));
    this.setPhase('waitClose', T.timeoutEndSec);
    this.rewards();
  }

  onPhaseEnd(id) {
    // the boss death kills the fortress timer (script KillTimer 0)
    if (id === 'fortress' && this.bossDead) return;
    return super.onPhaseEnd(id);
  }

  tick(dt) {
    super.tick(dt);
    if (this.phase === 'waitStart' && this.phaseT <= this.waitStartSec() - T.firstNoticeSec && !this.flags.has('df1001')) { this.flags.add('df1001'); this.say(1001); }
    if (this.phase === 'waitClose' && !this.failed) {
      const [, , c, d] = T.closeLineSec;
      if (this.phaseT <= c + d && !this.flags.has('df1502')) { this.flags.add('df1502'); this.say(1502); }
      if (this.phaseT <= d && !this.flags.has('df1002')) { this.flags.add('df1002'); this.say(1002); }
    }
  }

  _treasure() {
    if (this.treasureSpawned) return;
    this.treasureSpawned = true;
    this._spawn('treasure', this.ref?.treasure?.spawns || [], { onSpawn: m => { m.eventTreasure = true; } });
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
    const ok = await this.channel(this.data.txt(this.pwFile, 300, 10).replace('%d', String(rank)), sec * 1000, { depot: { id, rank } });
    if (!ok || this.ended) { this.say(1108); return; }
    this.depots.add(id);
    this.lastDepot = { id, rank };   // consumed by the party-war addScore wrapper (team + points)
    this.pw(300, 121, { args: [rank] });
    this.addScore(this.pointsFor(id) || 1, 'depot');
  }
}