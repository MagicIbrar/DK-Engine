// Party war runs (Dead Front = type 1, Ice Castle = type 2): the shared phase machine of share/partywar/config.csv,
// the timers of partywar #300|3-9, the solo rules of events.json soloRules (docs/formats/events.md §4-§7):
//   waitStart 180 s (skippable) -> fortress 1800 s (PvE, runs exactly) -> [waitPvp / pvp / extension: skipped, the
//   final battle is an uncontested win when the objective boss died, else a loss] -> waitClose 300 s -> endWarRespawn.
// Score = objective points (result.csv killPoints) + pvpPoints[0] on the uncontested win. Result window: rank 1 of 1,
// Additional EXP = score x advRatio (inferred), winRPoint R-points, DK maps add winExp4PvP / winRPoint4PvP (or the lost
// values). Dead Front fortress failure has no PvP bonus or placement. Death: DK maps with a dkmaplist row return
// to its respawn, else to endWarRespawn (the run ends).
import { EventRun } from './run.js';
import { grantExp } from '../../game/progression.js';
import { addPoints } from './inventory.js';
import { hudLog } from './text.js';
// Lane 59: Dead Front start / close / timeout steps follow the older server reference script (deadfront.js)
// Lane 68: Ice Castle uses the same frame (src/config/ice-castle-script-ref.js, icecastle.js _closeStep / _timeout);
// the former engine-chosen party-war gaps were removed (ice-castle-script-ref.js ICE_CASTLE_REMOVED).
import { DEAD_FRONT_SCRIPT_TIMINGS as DFT } from '../../config/dead-front-script-ref.js';

const PHASE_FMT = { waitStart: 3, fortress: 4, waitPvp: 5, pvp: 6, waitExtension: 7, extension: 8, waitClose: 9 };

export class PartyWarRun extends EventRun {
  constructor(sys, map, opts, mode) {
    super(sys, map, opts);
    this.mode = mode;                                   // 'deadFront' | 'iceCastle'
    this.M = this.data.modes[mode];
    this.pwFile = mode === 'iceCastle' ? 'stringtable_partywar2.txt' : 'stringtable_partywar.txt';
    this.field = this.data.field(mode, map) || {};
    this.res = this.data.result(mode, map) || {};
    this.tierInfo = this.data.tierOf(mode, map);
    this.team = 0;                                       // solo: team 0 (Purple), lane A / corner 0
    this.teamName = this.M.teams?.[this.team]?.name || 'Purple';
    this.inMap = Object.fromEntries((this.M.timeline?.inMap || []).map(p => [p.id, p]));
    this.won = null;
    this.firsts = new Set();
    this.bossesKilled = new Set();
  }

  vars(extra = {}) { return { PARTYNAME: this.teamName, PARTYNAMES: this.teamName, ...extra }; }
  pw(cate, code, opts = {}) { return this.sayIn(this.pwFile, cate, code, { vars: this.vars(opts.vars), ...opts }); }
  pwText(cate, code) { return this.data.txt(this.pwFile, cate, code); }
  point(p) { return this.data.fieldPoint(this.mode, this.map, p); }

  async start() {
    await super.start();
    this.setPhase('waitStart', this.waitStartSec?.() ?? this.inMap.waitStart?.sec ?? 180);
    // 1001 plays 120 s into the wait (older server reference; deadfront.js / icecastle.js tick)
    this.ui.partyInfo(this.score, 1);
    await this.onWaitStart?.();
    this._offerSkip();
  }

  /** The solo countdown can be skipped (soloRules: "run (countdown, can be skipped by the player)"). */
  async _offerSkip() {
    const ui = this.game.uiwin;
    if (!ui) return;
    const r = await ui.msgbox(`${this.text(1001, this.pwText(300, 3))}\n\nStart the battle now?`, { title: this.text(1, this.info.name), kind: 'yesno' });
    if (r === 'yes' && this.phase === 'waitStart' && !this.ended) this.phaseT = Math.min(this.phaseT, 5.2);
  }

  onPhase(id) {
    this.timerFmt = this.pwText(300, PHASE_FMT[id]) || `${this.text(this.inMap[id]?.labelCode ?? 101)} %02d Min %02d Sec`;
  }

  onPhaseEnd(id) {
    if (id === 'waitStart') {
      this.setPhase('fortress', this.fortressSec?.() ?? this.inMap.fortress?.sec ?? 1800);
      this.say(1003);
      this.pw(300, 100);
      this.onFortress?.();
    } else if (id === 'fortress') {
      this.resolveFinal(this.objectiveDone());
    } else if (id === 'waitClose') {
      this.close();
    }
  }

  tick(dt) {
    // the countdown effect 1002 (5..1) plays in the last 5 s of the start wait, 1503 before the close
    if (this.phase === 'waitStart' && this.phaseT <= 5 && !this.flags.has('cd1')) { this.flags.add('cd1'); this.say(1002); }
    // the close lines are the script close of each mode (deadfront.js / icecastle.js tick)
    this._uiT = (this._uiT || 0) - dt;
    if (this._uiT <= 0) {
      this._uiT = 0.25;
      this.ui.timer(this.timerFmt || '%02d:%02d', this.phaseT);
    }
  }

  /**
   * The attach-process channel (supply depots, slates). A cancelled channel prints its original reason line,
   * partywar #300|124 moved / 125 attacked / 126 left the map (both partywar tables), before the caller's failure line.
   */
  async channel(text, ms, extra = {}) {
    let why = null;
    const ok = await this.ui.channel(text, ms, { ...extra, onFail: (w) => { why = w; } });
    const code = { moved: 124, hit: 125, left: 126 }[why];
    if (!ok && code && !this.ended) this.pw(300, code);
    return ok;
  }

  /** Did the solo party reach the objective (the final boss / the tower defence)? */
  objectiveDone() { return false; }

  /** Add objective points; `depot` prints #300|122 ("You have acquired %d points for occupying the supply depot"). */
  addScore(n, why = '') {
    if (!(n > 0)) return;
    this.score += n;
    this.ui.partyInfo(this.score, 1);
    if (why === 'depot') this.pw(300, 122, { args: [n] });
  }
  /** result.csv killPoints value of an id (depot npc, brick index, monster index). */
  pointsFor(id) {
    for (const [i, p] of this.res.killPoints || []) if (Number(i) === Number(id)) return Number(p) || 0;
    return 0;
  }

  /** Solo final battle: uncontested win (objective done) or loss; then the close wait. */
  resolveFinal(win) {
    if (this.won != null) return;
    // older server reference (Dead Front script; Ice Castle shares its frame codes, Lane 68): fail / timeout -> 1504 /
    // 1503 / end at 15 s (_timeout); one party -> the close step 5 s after the objective (_closeStep). No 1401 / 1402
    // for one party (the script sends none). field.csv Loser / Winner respawns stay (Global data).
    if (!win || !this.objectiveDone()) {
      const point = this.point(this.field.loserRespawn);
      if (point) void this.teleport(point).catch(error => hudLog(this.game, error?.message || String(error), 'err'));
      this._timeout();
      return;
    }
    this.won = true;
    this.after(DFT.closeSec, async () => {
      const p = this.point(this.field.winnerRespawn);
      if (p) await this.teleport(p);
      this._closeStep();
    });
  }

  rewards() {
    const fortressFailed = this.failed && !this.won;   // Dead Front fortress / Ice Castle tower failure (script frame)
    if (fortressFailed && this._failedRewardsGranted) return;
    if (fortressFailed) this._failedRewardsGranted = true;
    const res = this.res;
    if (this.won) this.score += Number(res.pvpPoints?.[0]) || 0;
    const adv = Number(res.advRatio) || 0;
    const exp = Math.round(this.score * adv);
    const r = [];
    let rp = 0, bonusExp = 0;
    if (this.won) {
      rp += Number(this.field.winRPoint) || 0;
      rp += Number(res.winRPoint4PvP) || 0;
      bonusExp += Number(res.winExp4PvP) || 0;
    } else if (!fortressFailed) {
      rp += Number(res.lostRPoint4PvP) || 0;
      bonusExp += Number(res.lostExp4PvP) || 0;
    }
    r.push({ rank: fortressFailed ? '' : 1, party: this.teamName, point: this.score, exp: exp + bonusExp });
    this.ui.partyInfo(this.score, fortressFailed ? '' : 1);
    const total = exp + bonusExp;
    if (total > 0) grantExp(this.game, total);
    if (rp > 0) {
      addPoints(this.game, 'rPoint', rp);
      hudLog(this.game, `You have acquired ${rp.toLocaleString('en-US')} R-Points.`, 'sys');
    }
    this.game.persist?.();
    this.ui.result(r, null);
  }

  /** The close timer ended (or Reezena was used): everybody goes to endWarRespawn. */
  close() {
    const p = this.data.fieldPoint(this.mode, this.map, this.field.endWarRespawn) || null;
    const to = p && p.map !== this.map ? p : { map: this.field.endWarRespawn?.map ?? this.M.lobbies?.[0], x: (this.field.endWarRespawn?.x ?? 340) + 0.5, z: (this.field.endWarRespawn?.y ?? 250) + 0.5 };
    this.end('close');
    return this.leave(to);
  }

  respawnTarget() {
    const dk = this.info.dkMapList;
    if (dk?.respawnType === 'DEFAULT' && dk.respawn?.[0]) {
      const [m, x, y] = dk.respawn[0];
      return { mapIndex: Number(m), x: Number(x) + 0.5, z: Number(y) + 0.5, dirDeg: 0 };
    }
    const e = this.field.endWarRespawn;
    return e ? { mapIndex: Number(e.map), x: Number(e.x) + 0.5, z: Number(e.y) + 0.5, dirDeg: 0 } : null;
  }

  /** Reezena (5672, exit): 30001 "You are exiting ... with a reward" -> leave to endWarRespawn. */
  exitPage(npc) {
    const done = this.phase === 'waitClose';
    return {
      title: npc?.name,
      text: this.data.npc(5672)?.greeting || '',
      options: done
        ? [{ label: this.text(30001, 'Exit'), pick: () => { this.sys.dialog.close(); this.close(); } }]
        : [{ label: this.text(30001, 'Exit'), pick: () => { this.sys.dialog.close(); hudLog(this.game, this.pwText(200, 2) || 'It is not the time.', 'err'); } }],
    };
  }

  /** First-time announcements (#400|1-4). */
  first(kind, checkpoint) {
    if (this.firsts.has(`${kind}:${checkpoint}`)) return;
    this.firsts.add(`${kind}:${checkpoint}`);
    this.pw(400, kind === 'destroy' ? 3 : 1, { vars: this.vars({ CHECKPOINT: checkpoint }) });
  }
}
