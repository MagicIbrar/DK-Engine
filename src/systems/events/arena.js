// Colosseum Arena (PvE): 615 solo (colosseum_02.map) / 616 party (colosseum_05.map). docs/formats/events.md §6.2.
//   entry   : Dein (5931) in the Colosseum Lobby 162, Lv 190 / 195, 500 000 DIL, the entrance ticket is collected
//             (4002041 solo / 4002107 party), 15 minutes. The party arena allows solo entry (allowSoloParty).
//   solo    : the Battle Royale prison: 16 cells closed by Old Bars; call k opens the bars of its cells (DEAD) and the
//             champions step out (200 "Fighter came out from the prison"). The next call follows when the previous
//             one is beaten, after the "Fighters Appear in" timer (40).
//   party   : waves by the tens digit of the call index (11 | 21-23 | 31-32 | 41-43).
//   combo   : a kill inside the combo hold time (35) raises the combo; solo 5/10/15, party 10/25/45 -> mission EXP
//             x2/x3/x4 (202-204); a lapse resets it (201 / 303). The scoreboard window shows it.
//   clear   : 1001 clear effect, trophy chests (scriptMonsters 8931/8932 solo, 8973 party), Reezena 40000 -> kick.
//   fail    : time out 3001 / 1002, Reezena 20010 -> kick to dungeonlist KickTo (Colosseum Lobby 162 (307, 211)).
// The champions are ordinary monster records (8919-8930, 8960-8972): no AI players.
// Server values (not in the client): waiting 10 s, fighters-appear 10 s, combo hold 10 s; mission EXP = the kill EXP
// multiplied by the combo rate (the extra part is granted on top of the normal kill EXP).
import { InstanceRun } from './instance.js';
import { grantExp } from '../../game/progression.js';
import { monsterDef } from '../../game/combat.js';

const APPEAR_SEC = 10;
const COMBO_HOLD = 10;

export class ArenaRun extends InstanceRun {
  constructor(sys, map, opts) {
    super(sys, map, { ...opts, limitSec: 15 * 60 });
    const R = this.data.modes.colosseum?.arena?.rules || {};
    this.party = this.map === 616;
    this.cfg = this.party ? R.party : R.solo;
    this.combo = 0;
    this.comboT = 0;
    this.mult = 1;
    this.waveIdx = -1;
    this.waves_ = this.party ? this._partyWaves() : (this.cfg?.waves || [1, 2, 3, 4]).map(c => [c]);
    this.failOnDeath = false;
  }

  _partyWaves() {
    const calls = (this.cfg?.waves || [11, 21, 22, 23, 31, 32, 41, 42, 43]).map(Number);
    const by = new Map();
    for (const c of calls) { const w = Math.floor(c / 10); if (!by.has(w)) by.set(w, []); by.get(w).push(c); }
    return [...by.keys()].sort((a, b) => a - b).map(k => by.get(k));
  }

  /** The prison bars are created by the arena script when it starts (IsCreate 0, events.md §6.2). */
  async onWait() { if (!this.party) await this.bricks.spawnAll(this.bricks.rows().map(p => p.uid)); }

  onRun() { this._nextWave(); }

  _nextWave() {
    this.waveIdx++;
    const calls = this.waves_[this.waveIdx];
    if (!calls) { this.clear(); return; }
    this.appearT = this.waveIdx === 0 ? 0.1 : APPEAR_SEC;
    this.pendingCalls = calls;
  }

  _release(calls) {
    const prison = this.cfg?.prison;
    if (prison && !this.party) {
      for (const cell of prison.cells || []) {
        if (cell.champion && calls.includes(Number(cell.champion[0]))) this.bricks.removeAll(cell.bars || [], 'die');
      }
    }
    this.say(200);
    const keys = [];
    for (const c of calls) {
      const key = `w${this.waveIdx}_${c}`;
      keys.push(key);
      this.waves.spawn(key, this.info.calls?.[c] || [], { aggressive: true, sight: 30, pursuit: 80, onKill: (m) => this._kill(m) });
    }
    this._watch = keys;
  }

  _kill(m) {
    this.kills++;
    this.combo = this.comboT > 0 ? this.combo + 1 : 1;
    this.comboT = COMBO_HOLD;
    const steps = this.cfg?.combo || [];
    for (const s of steps) {
      if (this.combo === Number(s.combo)) { this.mult = Number(s.expMul) || 1; this.say(s.code); }
    }
    if (this.combo > 1) this.say(400, { vars: { MAP_COUNT_0: this.combo }, notice: false });
    const def = monsterDef(m);
    if (this.mult > 1 && def?.exp > 0) grantExp(this.game, def.exp * (this.mult - 1), def.level);
  }

  tick(dt) {
    if (this.pendingCalls) {
      this.appearT -= dt;
      this.extraRows = [`${this.text(40, 'Fighters Appear in:')} 00:${String(Math.max(0, Math.ceil(this.appearT))).padStart(2, '0')}`];
      if (this.appearT <= 0) { const c = this.pendingCalls; this.pendingCalls = null; this.extraRows = []; this._release(c); }
    } else if (this._watch && this._watch.every(k => this.waves.isDone(k))) {
      this._watch = null;
      this._nextWave();
    }
    if (this.comboT > 0) {
      this.comboT -= dt;
      if (this.comboT <= 0) {
        if (this.mult > 1) this.say(201); else if (this.combo > 1) this.say(303);
        this.combo = 0; this.mult = 1;
      }
    }
    if (this.state === 'run') {
      const rows = this.extraRows.filter(r => !/Combo/.test(r));
      if (this.comboT > 0) rows.push(`${this.text(35, 'Combo Holding Time:')} 00:${String(Math.ceil(this.comboT)).padStart(2, '0')}`);
      this.extraRows = rows;
      this._sbT = (this._sbT || 0) - dt;
      if (this._sbT <= 0) { this._sbT = 0.2; this.ui.scoreboard(this.comboT / COMBO_HOLD, this.combo, this.mult > 1); }
    }
    super.tick(dt);
  }

  onClear() {
    const troph = this.cfg?.trophies || this.info.scriptMonsters || [];
    const p = this.player;
    troph.forEach((mon, i) => {
      const a = (i / Math.max(1, troph.length)) * Math.PI * 2;
      this.waves.spawn(`trophy_${i}`, [{ monster: mon, x: p.x + Math.cos(a) * 2.5, z: p.z + Math.sin(a) * 2.5, exact: true }], {});
    });
    this.ui.close('ev_score');
  }
  onFail() {
    for (const k of [...this.waves.groups.keys()]) if (k.startsWith('w')) this.waves.clearGroup(k);
    this.ui.close('ev_score');
  }

  npcPage(npc) {
    const id = Number(npc.npcIndex);
    if (id === 5930 || id === 5954) return this.exitPage(npc);
    return null;
  }
}
