// Stage-driven event instances, run from the dungeon builder's stage model (gamedata/dungeons.json maps[m]:
// stages[{n, call | script[], objective 'kill-all' | 'kill-boss', bosses, opens[]}], waves[{call, rows}],
// scriptSpawns[{monster, suggest}], missions, messages, timeLimit, scriptNpcs):
//   ShipwreckRun   Forgotten Shipwreck 234 -> 235 (party) / 263 -> 264 (solo): the vines, the ship, Odyssey, the
//                  crystal into Nepturos' Tomb, Nepturos; clear = the reward roulette (ui_reward_slotwnd, share/
//                  forgottenshipwreck/rewardslot.csv win table; lose table on a failure).
//   FettersRun     Forbidden Fetters 260: 20 floors (calls floor*10+k), clearExp per floor, resetCost to start over
//                  (share/forbiddenshackles/forbiddenshacklesdata.csv); progress is kept per character.
//   Infinite2Run   Infinite Battle 2 (228 / 229 / 534): no waves in the client; the script bosses are fought in order.
// Each stage spawns its call (or script monsters at their suggested cells); when every monster of it is dead the
// stage's `opens` bricks open and the next stage starts. The last stage clears the instance.
import { InstanceRun } from './instance.js';
import { grantExp } from '../../game/progression.js';
import { addItem, payDil } from './inventory.js';
import { hudLog } from './text.js';

export class StagedRun extends InstanceRun {
  constructor(sys, map, opts = {}) {
    super(sys, map, opts);
    this.stages = this.dg.stages?.stages || [];
    this.si = -1;
    this.wavesByCall = new Map((this.dg.waves || []).map(w => [Number(w.call), w.rows || []]));
    this.labels = { wait: 30, run: 31, close: 39 };
  }

  onRun() { this.nextStage(); }

  nextStage() {
    this.si++;
    const st = this.stages[this.si];
    if (!st) { this.clear(); return; }
    const mission = this.dg.stages?.missions?.[this.si];
    if (mission != null) this.say(mission);
    const rows = [];
    if (st.call != null) for (const r of this.wavesByCall.get(Number(st.call)) || this.info.calls?.[st.call] || []) rows.push(r);
    for (const mon of st.script || []) {
      const ss = (this.dg.scriptSpawns || []).find(s => Number(s.monster) === Number(mon));
      const at = ss?.suggest || [Math.round(this.player.x), Math.round(this.player.z)];
      rows.push([Number(mon), at[0], at[1], 1, 1]);
    }
    for (const a of st.alert || []) this.say(a);
    const key = `st${this.si}`;
    this.waves.spawn(key, rows, { aggressive: true, sight: 20, pursuit: 60, onKill: () => { this.kills++; }, onDone: () => this.stageDone(st) });
    this.onStage?.(st, this.si);
  }

  stageDone(st) {
    if (this.state !== 'run') return;
    for (const u of st.opens || []) this.bricks.remove(u, this.bricks.get(u)?._clip?.('OPENBRICK') ? 'open' : 'die');
    this.after(2, () => this.nextStage());
  }

  npcPage(npc) {
    const id = Number(npc.npcIndex);
    const sn = (this.dg.scriptNpcs || []).find(s => Number(s.npc) === id);
    if (!sn) return null;
    if (sn.role === 'exit' || /reezena|rezeena/i.test(sn.name || '')) return this.exitPage(npc);
    return this.scriptNpcPage?.(npc, sn) || null;
  }
}

// ============================================================================================ Forgotten Shipwreck
export class ShipwreckRun extends StagedRun {
  constructor(sys, map, opts) {
    super(sys, map, opts);
    this.upper = [234, 263].includes(this.map);
    this.lowerMap = { 234: 235, 263: 264 }[this.map] || null;
    if (opts.carry?.timeLeft) this.limitSec = opts.carry.timeLeft;
    this.labels = { wait: 200, run: 201, close: 202 };
  }
  async onWait() { if (!this.upper) this.phaseT = 2; }
  onClear() {
    if (this.upper) return;
    this._roulette('win');
  }
  clear() {
    if (this.upper) {
      // the upper deck is done: the crystal (6111 / 6046) leads to Nepturos' Tomb
      this.state = 'boarded';
      this.say(14);
      return;
    }
    super.clear();
  }
  onFail() { this._roulette('lose'); }
  scriptNpcPage(npc, sn) {
    const close = () => this.sys.dialog.close();
    if (Number(sn.job?.[1]) === 501) {
      return { title: npc.name, text: this.data.npc(npc.npcIndex)?.greeting || '', options: [{ label: sn.label, pick: () => {
        close();
        if (this.state !== 'boarded') { hudLog(this.game, this.text(4007, 'You have not completed the mission yet.'), 'err'); return; }
        const left = this.phaseT;
        this.sys.pending = { map: this.lowerMap, carry: { timeLeft: left } };
        const sp = this.data.dg?.maps?.[this.lowerMap]?.spawn;
        this.end('floor');
        const at = sp?.snap ? { x: Number(sp.snap[0]), z: Number(sp.snap[1]) }
          : sp && sp.walk !== -1 ? { x: Number(sp.x) + 0.5, z: Number(sp.y) + 0.5 } : { x: null, z: null };
        this.leave({ map: this.lowerMap, ...at });
      } }] };
    }
    if (Number(sn.job?.[1]) === 500) {
      return { title: npc.name, text: this.data.npc(npc.npcIndex)?.greeting || '', options: [{ label: sn.label, pick: () => { close(); const w = sn.warp || []; if (w[0] > 1 && w[1] > 1) this.teleport({ x: w[0] + 0.5, z: w[1] + 0.5 }); else hudLog(this.game, sn.label, 'sys'); } }] };
    }
    return null;
  }

  /** The reward roulette (ui_reward_slotwnd.txt): START spins over the slot table and gives the picked item. */
  async _roulette(team) {
    const table = (this.data.dg?.forgottenShipwreck?.rewards?.[team]) || [];
    if (!table.length || !this.game.uiwin) return;
    const ui = this.game.uiwin;
    const win = await ui.create('game2/forgottenshipwreck/ui_reward_slotwnd.txt', { name: 'ev_reward_slot', escClose: false, disposeOnClose: true });
    ui.openWindow(win);
    const lbl = win.control('lbl_result_rullet');
    const start = win.control('btn_start');
    let spun = false;
    const pick = () => {
      const sum = table.reduce((a, r) => a + (Number(r[2]) || 0), 0);
      let r = Math.random() * sum;
      for (const row of table) { r -= Number(row[2]) || 0; if (r <= 0) return row; }
      return table[table.length - 1];
    };
    start.onClick(() => {
      if (spun) { win.close('ok'); return; }
      spun = true;
      start.setEnabled(false);
      lbl.setVisible(true);
      let n = 0;
      const final = pick();
      const tick = () => {
        const row = n < 18 ? table[Math.floor(Math.random() * table.length)] : final;
        lbl.setText(`${this.data.itemName(row[0])} x${row[1]}`);
        if (n++ < 18) setTimeout(tick, 60 + n * 12);
        else {
          addItem(this.game, row[0], Number(row[1]) || 1, this.data.itemName(row[0]));
          hudLog(this.game, `${this.data.itemName(row[0])} x${row[1]}`, 'item');
          start.setEnabled(true);
          start.setText('OK');
        }
      };
      tick();
    });
  }
}

// ============================================================================================ Forbidden Fetters
export class FettersRun extends StagedRun {
  constructor(sys, map, opts) {
    super(sys, map, opts);
    this.table = this.data.dg?.forbiddenShackles || [];
    const st = (this.game.save.eventState ||= {});
    this.progress = (st.fetters ||= { floor: 1 });
    this.floor = Math.max(1, Math.min(this.table.length || 20, Number(this.progress.floor) || 1));
    this.labels = { wait: 30, run: 31, close: 39 };
    // the floor's calls: floor*10 + 1..9 (groups 1-20 of the stage list)
    this._buildFloor();
  }
  _buildFloor() {
    const lo = this.floor * 10, hi = lo + 10;
    this.stages = (this.dg.stages?.stages || []).filter(s => s.call != null && s.call >= lo && s.call < hi);
    this.si = -1;
  }
  onStage() { if (this.si === 0) this.say(2000 + this.floor); }
  clear() {
    if (this.state !== 'run') return;
    const row = this.table.find(r => Number(r.floor) === this.floor);
    if (row?.clearExp) grantExp(this.game, Number(row.clearExp));
    this.say(1300);
    if (this.floor < (this.table.length || 20)) {
      this.floor++;
      this.progress.floor = this.floor;
      this.game.persist?.();
      this.say(1501);
      this._buildFloor();
      this.after(5, () => { this.setPhase('run', this.limitSec); this.nextStage(); });
    } else {
      this.progress.floor = this.floor;
      super.clear();
    }
  }
  scriptNpcPage() { return null; }
  /** Reezena: 41000 "Are you sure you want to leave?" -> 41001 leave / 41002 cancel, or pay the floor's reset cost
   *  (forbiddenshacklesdata.csv) to start over from floor 1. */
  exitPage(npc) {
    const close = () => this.sys.dialog.close();
    const row = this.table.find(r => Number(r.floor) === this.floor) || {};
    const opts = [{ label: this.text(41001, 'Leaving the dungeon.'), pick: () => { close(); this.kick(); } }];
    if (this.floor > 1) opts.push({ label: `${this.text(2001, 'Floor 1')} (${Number(row.resetCost || 0).toLocaleString('en-US')} DIL)`, pick: () => {
      close();
      if (!payDil(this.game, Number(row.resetCost) || 0)) { this.say(309); return; }
      this.progress.floor = 1; this.floor = 1; this.game.persist?.(); this.kick();
    } });
    opts.push({ label: this.text(41002, 'Cancel'), pick: close });
    const floorName = this.text(2000 + this.floor, `Floor ${this.floor}`);
    return { title: npc.name, text: `${floorName}\n${this.text(41000, this.text(5, 'Are you sure you want to leave?'))}`, options: opts };
  }
}

// ============================================================================================ Infinite Battle 2
export class Infinite2Run extends StagedRun {
  constructor(sys, map, opts) {
    super(sys, map, opts);
    this.labels = { wait: 31, run: 30, close: 39 };
    // the bosses come one by one (the stage lists them together)
    const st = this.stages[0];
    if (st?.script?.length) this.stages = st.script.map((m, i) => ({ n: i + 1, script: [m], objective: 'kill-boss', bosses: [m] }));
  }
  scriptNpcPage(npc, sn) {
    if (Number(sn.job?.[1]) === 10011) return this.exitPage(npc);
    return { title: npc.name, text: this.data.npc(npc.npcIndex)?.greeting || '', options: [{ label: sn.label, pick: () => { this.sys.dialog.close(); if (this.phase === 'wait') this.phaseT = 0.1; } }] };
  }
}
