// Infinite Battle (PvE): 153 Secret Arena, 154 Cartel, 155 Colosseum, 613 Stadion. docs/formats/events.md §6.3.
//   Monsters are summoned for the time limit (5 / 7 minutes, the NPC greeting; 153: 11 minutes and two missions),
//   call after call (calls 1-7, cycling), and accumulate. Warnings at 80 / 90 / 95 living monsters (1106-1108);
//   100 living = "the Instance Dungeon will end after 1 minute" (1101) and the mission fails. Surviving the time
//   limit clears it (40000 "You survived!"). Boss calls 11 / 12 (154, 155) come at 1/2 and 3/4 of the time.
//   153 (Norak Secret Arena): mission 10 = 200 kills (201), then Davich's Alter Ego (7971, 202) = mission 11 -> clear.
//   Combo (153: 300/301/302): 50 kills in a row x3 EXP, 100 x5, 150 summons Hidnil (7977).
// Server values (not in the client): one call every 20 s, the combo hold time 10 s.
import { InstanceRun } from './instance.js';
import { grantExp } from '../../game/progression.js';
import { monsterDef } from '../../game/combat.js';

const CALL_EVERY = 20;
const COMBO_HOLD = 10;
const MAX_ALIVE = 100;

export class InfiniteRun extends InstanceRun {
  constructor(sys, map, opts) {
    const cfg = (sys.data.modes.colosseum?.infiniteBattle || []).find(b => Number(b.map) === Number(map)) || {};
    const min = Number(cfg.gate?.minutes?.[0]) || 5;
    const isNorak = Number(map) === 153;
    super(sys, map, { ...opts, limitSec: isNorak ? (sys.data.dg?.maps?.[153]?.timeLimit?.sec || 660) : min * 60 });
    this.cfg = cfg;
    this.isNorak = isNorak;
    this.calls = Object.keys(this.info.calls || {}).map(Number).filter(c => c < 10).sort((a, b) => a - b);
    this.bossCalls = (cfg.bossCalls || []).map(Number);
    this.ci = 0;
    this.callT = 0;
    this.combo = 0; this.comboT = 0; this.mult = 1;
    this.warned = new Set();
    this.overflowT = null;
  }

  onRun() { this.callT = 0.1; }

  tick(dt) {
    if (this.state === 'run') {
      // summons
      if (!this.bossPhase) {
        this.callT -= dt;
        if (this.callT <= 0) { this.callT = CALL_EVERY; this._call(this.calls[this.ci++ % Math.max(1, this.calls.length)]); }
      }
      if (this.bossCalls.length) {
        const f = 1 - this.phaseT / this.limitSec;
        if (f >= 0.5 && !this.flags.has('boss1')) { this.flags.add('boss1'); this._call(this.bossCalls[0]); }
        if (f >= 0.75 && this.bossCalls[1] && !this.flags.has('boss2')) { this.flags.add('boss2'); this._call(this.bossCalls[1]); }
      }
      // accumulation
      const alive = this.waves.aliveCount();
      for (const [n, code] of [[80, 1106], [90, 1107], [95, 1108]]) {
        if (alive >= n && !this.warned.has(n)) { this.warned.add(n); this.say(code); this.say(code + 2000); }
        if (alive < n - 10) this.warned.delete(n);
      }
      if (alive >= MAX_ALIVE && this.overflowT == null) { this.overflowT = 60; this.say(204); this.say(1101); }
      if (this.overflowT != null) {
        this.overflowT -= dt;
        if (this.overflowT <= 0) { this.overflowT = null; this.fail(); }
      }
      this.ui.counter(null, `${alive} / ${MAX_ALIVE}`);
      // combo
      if (this.comboT > 0) { this.comboT -= dt; if (this.comboT <= 0) { if (this.combo > 1) this.say(303); this.combo = 0; this.mult = 1; } }
      this.extraRows = this.comboT > 0 ? [`${this.text(35, 'Combo Maint.')} 00:${String(Math.ceil(this.comboT)).padStart(2, '0')}`] : [];
    }
    super.tick(dt);
  }

  _call(c) {
    if (c == null || !this.info.calls?.[c]) return;
    this.say(230);
    this.waves.spawn(`c${c}_${Math.round(this.time * 10)}`, this.info.calls[c], { aggressive: true, sight: 25, pursuit: 80, onKill: (m) => this._kill(m) });
  }

  _kill(m) {
    this.kills++;
    this.combo = this.comboT > 0 ? this.combo + 1 : 1;
    this.comboT = COMBO_HOLD;
    if (this.isNorak) {
      if (this.combo === 50) { this.mult = 3; this.say(300); }
      if (this.combo === 100) { this.mult = 5; this.say(301); }
      if (this.combo === 150) { this.say(302); this._spawnScript(7977); }
      if (this.kills === 200 && !this.bossPhase) {
        this.bossPhase = true;
        this.say(201);
        this.after(3, () => { this.say(202); this._spawnScript(7971, { onDone: () => this.clear() }); });
      }
    }
    const def = monsterDef(m);
    if (this.mult > 1 && def?.exp > 0) grantExp(this.game, def.exp * (this.mult - 1), def.level);
  }

  _spawnScript(mon, opts = {}) {
    const ss = (this.data.dg?.maps?.[this.map]?.scriptSpawns || []).find(s => Number(s.monster) === mon);
    const at = ss?.suggest ? { x: ss.suggest[0] + 0.5, z: ss.suggest[1] + 0.5 } : { x: this.player.x + 4, z: this.player.z };
    this.waves.spawn(`s${mon}_${Math.round(this.time)}`, [{ monster: mon, x: at.x, z: at.z, exact: true }], { aggressive: true, sight: 30, pursuit: 80, ...opts });
  }

  /** Surviving the limit clears the infinite battles (153 needs its missions). */
  onTimeUp() { if (this.isNorak) this.fail(); else this.clear(); }

  onClear() { for (const k of [...this.waves.groups.keys()]) this.waves.clearGroup(k); this.ui.close('ev_count'); this.say(203); }
  onFail() { for (const k of [...this.waves.groups.keys()]) this.waves.clearGroup(k); this.ui.close('ev_count'); }

  npcPage(npc) {
    const sn = (this.info.scriptNpcs || this.data.dg?.maps?.[this.map]?.scriptNpcs || []).find(s => Number(s.npc) === Number(npc.npcIndex));
    if (sn || /reezena|rezeena/i.test(npc.name || '')) return this.exitPage(npc);
    return null;
  }
}
