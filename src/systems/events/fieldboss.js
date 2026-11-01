// Field boss (share/fieldboss/config.csv + summonsmonster.csv, share/creature/bossmemento.csv; dungeons.json
// fieldBosses / fieldBossSummons / bossMemento): Saturday 23:00-23:20 in Mitera (533), "distorted the world tree"
// (9490) at (53, 57) facing 260 deg, with its slaves. While it lives it calls its summons group (Index 1: 9491 every
// 18 s, 9492 every 12 s, 3 at a time, 5-48 cells around it, up to dwMaxLimit alive). The Mitera Red Hole messages
// (stringtable_dungeon_06 #533) frame it: 120 five minutes before, 101 at the start, 111-114 as the Red Hole energy
// reaches 80-95 % of the 20 minutes, 116 when the time runs out (the boss leaves), 118 / 119 when it is purified.
// The field boss time window (game2/fieldboss/ui_fieldbosstimewnd.txt) shows the time left and the energy.
import { EventRun } from './run.js';

export class FieldBossRun extends EventRun {
  constructor(sys, map, opts = {}) {
    super(sys, map, opts);
    this.fb = this.data.dg?.fieldBosses?.[0] || {};
    const s = this.fb.start || [23, 0], e = this.fb.end || [23, 20];
    this.duration = Math.max(60, ((e[0] * 60 + e[1]) - (s[0] * 60 + s[1])) * 60);
    this.startIn = Number(opts.startIn ?? 10);
    this.summons = (this.data.dg?.fieldBossSummons || []).filter(r => Number(r.group) === 1);
    this.sumT = new Map();
    this.energyMsgs = new Set();
    this.state = 'wait';
  }

  async start() {
    await super.start();
    if (this.startIn > 60) this.say(120);
    this.setPhase('wait', this.startIn);
  }

  onPhaseEnd(id) {
    if (id === 'wait') this._spawnBoss();
    else if (id === 'fight') this._timeUp();
    else if (id === 'close') this.end('close');
  }

  _spawnBoss() {
    const fb = this.fb;
    this.state = 'fight';
    this.setPhase('fight', this.duration);
    this.say(101);
    const rows = [{ monster: Number(fb.monster) || 9490, x: Number(fb.x) + 0.5, z: Number(fb.y) + 0.5, exact: true }];
    this.waves.spawn('boss', rows, {
      dir: fb.dir, aggressive: true, sight: 20, pursuit: 60,
      onSpawn: (m) => { this.boss = m; },
      onDone: () => this._purified(),
    });
    // the slaves stand with it
    const sl = (fb.slaves || []).filter(Boolean).map((m, i) => ({ monster: m, x: Number(fb.x) + 0.5 + Math.cos(i * 2.1) * 4, z: Number(fb.y) + 0.5 + Math.sin(i * 2.1) * 4, exact: true }));
    if (sl.length) this.waves.spawn('slaves', sl, { aggressive: true });
    const mem = this.data.dg?.bossMemento?.[fb.monster];
    if (mem?.bgm) this.msg.cue({ a: 0, id: 3004 });
  }

  tick(dt) {
    if (this.state === 'fight') {
      const b = this.boss;
      if (b && !b.dead) {
        for (const s of this.summons) {
          const k = `${s.group}:${s.no}`;
          const t = (this.sumT.get(k) ?? (Number(s.tickMs) || 15000) / 1000) - dt;
          if (t > 0) { this.sumT.set(k, t); continue; }
          this.sumT.set(k, (Number(s.tickMs) || 15000) / 1000);
          const key = `sum_${k}`;
          const alive = this.waves.groups.has(key) ? this.waves.left(key) : 0;
          const cap = Number(s.maxLimit) || 50;
          const n = Math.min(Number(s.count?.[0]) || 1, Math.max(0, cap - alive));
          if (n <= 0) continue;
          const [r0, r1] = s.range || [5, 48];
          const rows = [];
          for (let i = 0; i < n; i++) {
            const a = Math.random() * Math.PI * 2, d = r0 + Math.random() * Math.max(0, Math.min(r1, 48) - r0);
            rows.push({ monster: s.monster, x: b.x + Math.cos(a) * d, z: b.z + Math.sin(a) * d, exact: true });
          }
          const g = this.waves.groups.get(key);
          if (g && !g.done) { const add = this.waves.spawn(`${key}_${Math.round(this.time)}`, rows, { aggressive: true }); void add; }
          else this.waves.spawn(key, rows, { aggressive: true });
        }
      }
      const f = 1 - this.phaseT / this.duration;
      for (const [p, code] of [[0.8, 111], [0.85, 112], [0.9, 113], [0.95, 114]]) if (f >= p && !this.energyMsgs.has(code)) { this.energyMsgs.add(code); this.say(code); }
    }
    this._uiT = (this._uiT || 0) - dt;
    if (this._uiT <= 0) {
      this._uiT = 0.25;
      const mmss = s => `${String(Math.floor(s / 60)).padStart(2, '0')}:${String(Math.floor(s % 60)).padStart(2, '0')}`;
      const rows = this.state === 'wait' ? [`<color=fdb602>${this.data.mapTxt(this.map, 120) ? 'Red Hole' : 'Field Boss'}</color> ${mmss(this.phaseT)}`]
        : this.state === 'fight' ? [`<color=fdb602>Time Left:</color> ${mmss(this.phaseT)}`, `<color=fdb602>Red Hole</color> ${Math.floor((1 - this.phaseT / this.duration) * 100)}%`]
          : [`<color=fdb602>Closing In:</color> ${mmss(this.phaseT)}`];
      this.ui.fieldBossTimes(rows);
    }
  }

  _purified() {
    if (this.state !== 'fight') return;
    this.state = 'done';
    this.say(118);
    this.after(3, () => this.say(119));
    for (const k of [...this.waves.groups.keys()]) if (k.startsWith('sum_')) this.waves.clearGroup(k);
    this.setPhase('close', 60);
  }

  _timeUp() {
    if (this.state !== 'fight') return;
    this.state = 'done';
    this.say(116);
    for (const k of [...this.waves.groups.keys()]) this.waves.clearGroup(k);
    this.setPhase('close', 30);
  }

  onEnd() { this.ui.close('ev_fbtime'); }
}
