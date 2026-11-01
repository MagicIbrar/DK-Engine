// Guild War Hunting: "Braiken Castle Defense Battle" (map 707, Defense Battle, braiken_broken.map; share/guildwarhunting
// + maps[707].randomCalls / randomPositions, stringtable_dungeon_22 #707). A PvE score race: invaders appear "somewhere
// in Braiken Castle" (102) at a random point of the position table (10 points, radius 4); the 20 random call tables
// escalate from the 100-point soldiers (9330-9338) to the 2 500-point captains (9354-9358) and the 5 000-point
// generals (9359-9362) (monsterScore). Score = sum of the scores of the invaders killed; the result is the hunt
// scoreboard (game2/guildwarhunting/ui_huntscoreboardwnd.txt) with the character's guild (or name).
// Enter: Vascuda (Ardeca, job 137) at config StartX/Y (397, 410); a death revives at ReviveX1/Y1 (the map has no exit
// respawn: dkmaplist NONE). Timers 100 "Begin in", 101 "Progress Time", 103 "End waiting time".
// Server values that are not in the client data come from src/config/engine-chosen-guild-war-hunting.js (ENGINE-CHOSEN),
// shared with the host run (server/world/guild-war-hunting.mjs).
import { EventRun } from './run.js';
import { addPoints } from './inventory.js';
import { GUILD_WAR_HUNTING_ENGINE_CHOSEN as CHOSEN } from '../../config/engine-chosen-guild-war-hunting.js';

const BEGIN_SEC = CHOSEN.beginSec, BATTLE_SEC = CHOSEN.battleSec, CALL_EVERY = CHOSEN.callEverySec, END_SEC = CHOSEN.endSec;

export class DefenseRun extends EventRun {
  constructor(sys, map, opts) {
    super(sys, map, opts);
    this.M = this.data.modes.guildWarHunting || {};
    this.scoreOf = new Map((this.M.monsterScore || []).map(([m, s]) => [Number(m), Number(s)]));
    this.calls = new Map();
    for (const [ci, mon, count, pos] of this.info.randomCalls || []) {
      if (!this.calls.has(ci)) this.calls.set(ci, []);
      this.calls.get(ci).push({ mon, count, pos });
    }
    this.positions = new Map();
    for (const [pi, x, y, r] of this.info.randomPositions || []) {
      if (!this.positions.has(pi)) this.positions.set(pi, []);
      this.positions.get(pi).push([x, y, r]);
    }
    this.order = [...this.calls.keys()].sort((a, b) => a - b);
    this.ci = 0;
  }

  async start() {
    await super.start();
    await this.bricks.spawnInitial();
    this.setPhase('begin', BEGIN_SEC);
  }

  onPhaseEnd(id) {
    if (id === 'begin') { this.setPhase('battle', BATTLE_SEC); this.say(200); this.callT = 1; }
    else if (id === 'battle') { this.say(201); for (const k of [...this.waves.groups.keys()]) this.waves.clearGroup(k); this._scoreboard(); this.setPhase('end', END_SEC); }
    else if (id === 'end') { this.end('close'); const r = this.game.respawnTarget?.(150); this.leave({ map: 150, x: r?.x ?? null, z: r?.z ?? null }); }
  }

  tick(dt) {
    if (this.phase === 'battle') {
      this.callT -= dt;
      if (this.callT <= 0 && this.ci < this.order.length) {
        this.callT = CALL_EVERY;
        const ci = this.order[this.ci++];
        const rows = [];
        for (const c of this.calls.get(ci) || []) {
          const pts = this.positions.get(c.pos) || [];
          const p = pts[Math.floor(Math.random() * pts.length)] || [this.player.x, this.player.z, 4];
          rows.push([c.mon, p[0], p[1], p[2] || 4, c.count || 1]);
        }
        this.say(102);
        this.waves.spawn(`inv${ci}`, rows, { aggressive: true, onKill: (m) => this._kill(m) });   // sight / pursuit stay the monsters' own data AI
      }
    }
    this._uiT = (this._uiT || 0) - dt;
    if (this._uiT <= 0) {
      this._uiT = 0.25;
      const mmss = s => `${String(Math.floor(s / 60)).padStart(2, '0')}:${String(Math.floor(s % 60)).padStart(2, '0')}`;
      const code = this.phase === 'begin' ? 100 : this.phase === 'battle' ? 101 : 103;
      this.ui.dungeonTimes([`${this.text(code)} ${mmss(this.phaseT)}`, this.score ? `<color=fdb602>Score:</color> ${this.score.toLocaleString('en-US')}` : null]);
    }
  }

  _kill(m) {
    const s = this.scoreOf.get(Number(m.monsterIndex)) || 0;
    if (s > 0) { this.score += s; addPoints(this.game, 'huntScore', s); }
  }

  async _scoreboard() {
    const ui = this.game.uiwin;
    if (!ui) return;
    try {
      const win = await ui.create('game2/guildwarhunting/ui_huntscoreboardwnd.txt', { name: 'ev_hunt', disposeOnClose: true });
      ui.openWindow(win);
      const g = this.game.save?.guild?.name || this.game.save?.guildName || this.game.save?.name || '';
      const name = this.game.save?.name || '';
      win.control('lbl_firstrank').setText('1');
      win.control('lbl_firstguildname').setText(g);
      win.control('lbl_firstguildscore').setText(this.score.toLocaleString('en-US'));
      for (let i = 0; i < 10; i++) {
        const own = i === 0;
        win.control(`lbl_vecrank_${i}`).setText(own ? '1' : '');
        win.control(`lbl_vecguildname_${i}`).setText(own ? g : '');
        win.control(`lbl_vecservername_${i}`).setText(own ? CHOSEN.serverName : '');
        win.control(`lbl_vecguildlevel_${i}`).setText(own ? String(this.game.save?.guild?.level ?? 1) : '');
        win.control(`lbl_vecguildmaster_${i}`).setText(own ? name : '');
        win.control(`lbl_vecguildscore_${i}`).setText(own ? this.score.toLocaleString('en-US') : '');
      }
      win.control('lbl_guildrank').setText('1');
      win.control('lbl_guildname').setText(g);
      win.control('lbl_servername').setText(CHOSEN.serverName);
      win.control('lbl_pcname').setText(name);
      win.control('lbl_guildscore').setText(this.score.toLocaleString('en-US'));
      const exit = win.control('btn_exit');
      exit.setVisible(true); exit.setEnabled(true);
      exit.onClick(() => win.close('ok'));
    } catch (err) { console.warn('[events] hunt scoreboard', err); }
  }

  respawnTarget() {
    const c = this.M.config || {};
    return { mapIndex: this.map, x: (Number(c.ReviveX1) || 397) + 0.5, z: (Number(c.ReviveY1) || 410) + 0.5, dirDeg: 0 };
  }
}
