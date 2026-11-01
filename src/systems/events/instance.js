// Instance-style event runs (Colosseum Arena, Infinite Battle, Forgotten Shipwreck, Forbidden Fetters, Infinite
// Battle 2): the dungeon timers (waiting / dungeon / closing, dungeon message codes 30-39 in the dungeontime window),
// entry rules (share/dungeonlist.csv via events.json maps[m].dungeon: kickTo, expire), the exit NPC dialogs
// (20000 can't leave yet, 20010 failed, 40000 cleared) and the kick out. Message codes come from the map's string
// table (events_text.json) or, for maps the events builder did not scan, from dungeons.json maps[m].messages.
import { EventRun } from './run.js';

export const WAIT_SEC = 10;      // label 30 "Waiting Time" (server value, not in the client)
export const CLOSE_SEC = 60;     // label 39 "Dungeon Ends in" (server value, not in the client)

export class InstanceRun extends EventRun {
  constructor(sys, map, opts = {}) {
    super(sys, map, opts);
    this.dg = this.data.dg?.maps?.[map] || this.data.dg?.maps?.[String(map)] || {};
    this.rules = this.info.dungeon || this.dg.dungeon || {};
    this.limitSec = opts.limitSec ?? this.dg.timeLimit?.sec ?? 900;
    this.state = 'wait';          // wait | run | clear | fail | closing
    this.labels = { wait: 30, run: 31, close: 39 };
    this.kills = 0;
    this.extraRows = [];          // extra timer rows [text]
  }

  /** Parsed message (events_text first, dungeons.json messages second). */
  msgEntry(code) {
    const e = this.data.mapStr(this.map, code);
    if (e) return e;
    const m = this.dg.messages?.[code] ?? this.dg.messages?.[String(code)];
    if (!m || m.t === 'undefined') return null;          // the builder writes unset codes as the literal "undefined"
    const out = { text: String(m.t || '').replace(/^\s*\[message\]\s*/i, ''), kind: /^\s*\[message\]/i.test(m.t || '') || m.sent ? 'message' : 'dialog', effectUi: [], sound: [], effectSound: [] };
    for (const f of m.fx || []) {
      if (f.ui) out.effectUi.push({ id: f.ui, ms: f.ms || 3000 });
      if (f.sound) out.sound.push({ a: f.sound[0], id: f.sound[1] });
      if (f.sfx) out.effectSound.push({ cat: f.sfx[0], id: f.sfx[1], vol: f.sfx[2], range: f.sfx[3] });
    }
    return out;
  }
  say(code, opts = {}) { const e = this.msgEntry(code); if (e) this.msg.say(e, opts); return e; }
  text(code, dflt = '') { return this.msgEntry(code)?.text ?? dflt; }

  async start() {
    await super.start();
    await this.bricks.spawnInitial();
    this.setPhase('wait', WAIT_SEC);
    this.say(3000);
    await this.onWait?.();
  }

  onPhaseEnd(id) {
    if (id === 'wait') {
      this.state = 'run';
      this.setPhase('run', this.limitSec);
      this.say(1000);
      this.say(2500);
      this.onRun?.();
    } else if (id === 'run') {
      this.onTimeUp();
    } else if (id === 'close') {
      this.kick();
    }
  }

  /** Default: time up = fail. */
  onTimeUp() { this.fail(); }

  clear() {
    if (this.state === 'clear' || this.state === 'fail') return;
    this.state = 'clear';
    this.say(1001);
    this.say(1300);
    this.onClear?.();
    this.after(2, () => this.say(3002));
    this.setPhase('close', CLOSE_SEC);
  }
  fail(code = 3001) {
    if (this.state === 'clear' || this.state === 'fail') return;
    this.state = 'fail';
    this.say(code);
    this.say(1002);
    this.onFail?.();
    this.after(2, () => this.say(3002));
    this.setPhase('close', CLOSE_SEC);
  }

  kickPoint() {
    const k = this.rules.kickTo?.[0];
    if (k) return { map: Number(k[0]), x: Number(k[1]) + 0.5, z: Number(k[2]) + 0.5 };
    const r = this.game.respawnTarget?.(this.map);
    return r ? { map: r.mapIndex, x: r.x, z: r.z } : { map: 150, x: null, z: null };
  }
  kick() { const p = this.kickPoint(); this.end('kick'); return this.leave(p); }
  respawnTarget() { const p = this.kickPoint(); return { mapIndex: p.map, x: p.x, z: p.z, dirDeg: 0 }; }

  onDeath({ actor }) {
    if (actor === this.player && this.state === 'run' && this.failOnDeath) this.fail();
  }

  tick(dt) {
    this._uiT = (this._uiT || 0) - dt;
    if (this._uiT > 0) return;
    this._uiT = 0.25;
    const fmt = s => { const m = Math.floor(Math.max(0, s) / 60), ss = Math.floor(Math.max(0, s) % 60); return `${String(m).padStart(2, '0')}:${String(ss).padStart(2, '0')}`; };
    const lbl = c => this.text(c, '');
    const rows = [];
    if (this.phase === 'wait') rows.push(`${lbl(this.labels.wait)} ${fmt(this.phaseT)}`);
    else if (this.phase === 'run') rows.push(`${lbl(this.labels.run)} ${fmt(this.phaseT)}`);
    else if (this.phase === 'close') rows.push(`${lbl(this.labels.close)} ${fmt(this.phaseT)}`);
    for (const r of this.extraRows) if (r) rows.push(r);
    this.ui.dungeonTimes(rows);
  }

  /** Exit NPC (Reezena): 20000 during the run, 20010 after a failure, 40000 after a clear. */
  exitPage(npc) {
    const close = () => this.sys.dialog.close();
    const title = npc?.name;
    if (this.state === 'clear') return { title, text: this.text(40000, 'Congratulations!'), options: [{ label: this.text(40001, 'Exit'), pick: () => { close(); this.kick(); } }] };
    if (this.state === 'fail') return { title, text: this.text(20010, ''), options: [{ label: this.text(20011, 'Exit'), pick: () => { close(); this.kick(); } }] };
    return { title, text: this.text(20000, this.data.npc(npc?.npcIndex)?.greeting || ''), options: [{ label: this.text(20001, 'OK'), pick: close }] };
  }
}
