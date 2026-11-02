// Grade (Awakening), Chaotic / PK, and Titles (share/pc/awakening/*.csv, share/pc/{chaotic,pkcount,pklevelcap}.csv,
// share/pc/title/title_base.csv, share/pc/gradecap/*.csv, share/rebirth/*.csv via gamedata/life.json `grade`/`pk`
// + gamedata/life_rebirth.json). No dedicated grade/PK *window* ships in this client (the grade-up splash
// `game2/ui_gradenoticewnd.txt` bakes the grade name into per-grade art indices we cannot map without the live
// server's asset table, so it is not used - see docs/formats/life.md "grade" for the decision); grade-ups and
// PK-state changes are announced the way skills/dekapass do (hud.log + an original msgbox), and the values are
// exposed on `game.life.grade` for the windows that DO show them (character sheet / nameplate / target plate,
// owned by other systems) to read.
//
// Grade: `grades` (life.json) is a flat list of {division, grade, levelLimit, name, gradeExp, rewardSkill,
// rewardShield, rewardStat, rewardSpSkill, options[]} sorted by (division, grade). `gradeExp` is the cost (in
// accumulated Grade EXP) to reach that row from the previous one - the same "cumulative cost table" shape as
// craft.js's craft_exp.csv, applied the same way. A row is reached once its cumulative cost is paid AND the
// character's level >= levelLimit (levelLimit gates the division). Reaching a row with rewardStat/rewardSkill
// grants stat/skill points once (claimed[] latch); rewardShield is the grade's SHIELD AMOUNT (not an item - item 1501 is
// Polaris Pants), applied to the shield capacity by src/game/awakening-shield.js. Grade EXP itself comes from monster kills: gamedata/life.json
// `monsterGrade.monsters[index] = [wgrade, gradeExp, chaoticLevel, pPointMin, pPointMax, pPointRate]` (built from
// share/creature/monster.csv Wgrade/DwGradeExp/ChaoticLevel/P_point_*).
//
// Chaotic / PK (approximate - the live server's exact massacre-detection formula is not recoverable from client
// csvs alone, see docs/formats/life.md): killing a monster far below the character's level adds `pPointMin..Max`
// scaled by `pPointRate/100` to a "chaotic value" that decays over real time; `pk.chaotic` (start..end ranges)
// maps that value to a loot-drop penalty and a forced-respawn flag (glow/flag colour is the nameplate owner's
// job). Player-kill tracking (`addPk`, for a future duel/PvP system) raises the value in bigger steps from
// `pk.pkcount` (kills-in-a-window -> chaotic delta / the level required for that band), decayed at a rate from
// `pk.pkLevelCap` (level band -> rate %). `pk.selfRevive` lists the item indexes that let a chaotic/PK'd
// character self-revive (read by the death/revive flow, owned by coreintegrate).
//
// Titles (title_base.csv): cosmetic + one passive option each (Option_Index1/Value1, a stat-system option code -
// no stat-modifier hook exists yet in this build, so `titleBonus()` is data-only until one does). EVENT-MODES: a title
// is selectable once OWNED (save.life.titles, src/systems/life/title-rules.js): Type 1 = kill Type_Value1 x Type_Value2,
// Type 7 = downed by Type_Value1 x Type_Value2, Type 9 = locked (no condition data). In shared play the host owns both
// (server/world/titles.mjs) and src/systems/network/race.js replaces owns/setTitle.
// Rebirth (share/rebirth/changeoption.csv + itemoption_{armor,weapon}.csv, gamedata/life_rebirth.json): the
// "Dynamic Option" re-roll table for old (pre-rebirth) equipment. Exposed as plain data lookups (`rebirthOptions`,
// `changeOption`) for the item-upgrade system to call; no window of ours uses it directly.
import { str, strNow, msg, msgRef, state, itemInfo, canGive, giveItem, randInt, rebirthData, itemsLegacyData } from './common.js';
import { rebirthOptionsAt, changeOptionType, REBIRTH_UNRESOLVED } from './rebirth-rules.js';
import { dynamicOptionCost } from '../items/dynamic-option-rules.js';
import { titleProgress, ownsTitle } from './title-rules.js';
import { FIELD_PK } from '../../config/engine-chosen-pk.js';
import { chaoticDecayPerSec } from '../../game/chaotic-decay.js';
import {claimEligibleGradeRewards} from '../../game/grade-rewards.js';

const DECAY_PER_SEC = 0; // no engine fallback (f pass); the rate is per map only (maplist wChaoticDecrease / dwChaoticDecreasePeriod)

export class Grade {
  constructor(game, life) {
    this.game = game;
    this.life = life;
    this.G = life.data?.grade || null;
    this.PK = life.data?.pk || null;
    this.REB = null;
    this._rows = null;
  }

  // ------------------------------------------------------------------------------------------- grade table
  get rows() {
    if (this._rows) return this._rows;
    const list = (this.G?.grades || []).slice().sort((a, b) => a.division - b.division || a.grade - b.grade);
    let cum = 0;
    this._rows = list.map((r, i) => { cum += Math.max(0, Number(r.gradeExp) || 0); return { ...r, key: `${r.division}.${r.grade}`, cum, i }; });
    return this._rows;
  }

  get st() {
    const s = state(this.game);
    if (!s.grade) s.grade = { totalExp: 0, rowKey: null, claimed: {}, chaotic: 0, pk: 0, pkWindow: [], titleIndex: 0 };
    return s.grade;
  }

  /** The highest grade row reached: cumulative Grade EXP paid AND character level high enough. */
  current() {
    const lvl = Number(this.game.save?.level) || 1;
    const rows = this.rows, st = this.st;
    let cur = rows[0] || null;
    for (const r of rows) { if (st.totalExp >= r.cum && lvl >= (r.levelLimit || 0)) cur = r; else break; }
    return cur;
  }
  next() { const rows = this.rows, cur = this.current(); return cur ? rows[cur.i + 1] || null : rows[0] || null; }
  /** {cur, need, frac} progress toward the next row. */
  progress() {
    const cur = this.current(), nxt = this.next(), st = this.st;
    if (!nxt) return { cur: 1, need: 1, frac: 1 };
    const base = cur?.cum || 0;
    return { cur: st.totalExp - base, need: nxt.cum - base, frac: Math.max(0, Math.min(1, (st.totalExp - base) / Math.max(1, nxt.cum - base))) };
  }

  /** Add Grade EXP (monster kills, quest rewards...) and claim any newly-reached row's one-time gift. */
  addExp(n) {
    if (!(n > 0) || !this.G) return;
    const st = this.st;
    st.totalExp += n;
    this.claimRewards();
  }

  claimRewards() {
    if(!this.G||this.game.network?.active||this.game.save?.authority==='server')return;
    const g = this.game;
    const awarded=claimEligibleGradeRewards(g.save,this.G.grades);
    for (const r of awarded) {
      // rewardShield is a SHIELD AMOUNT (grade.csv Reward2(Sheild): 1501, 1760, ...), not an item: it raises the shield capacity
      // while the character holds the grade (src/game/awakening-shield.js); the old code handed out item 1501 (Polaris Pants)
      if (r.rewardShield > 0 && g.player) { try { g.refreshPlayerStats?.(false); } catch (err) { console.warn('[grade] shield refresh', err); } }
      if (r.name) msg(g, `[Grade] ${r.name}`, 'exp');
      g.events?.emit?.('life:grade', { row: r, division: r.division, grade: r.grade });
    }
    g.persist?.();
  }

  /** Grade EXP from a monster kill (monsterGrade table), called from install()'s death hook. */
  _onKill(monsterIndex) {
    const row = this.life.data?.monsterGrade?.monsters?.[monsterIndex];
    if (!row) return;
    const [, gradeExp, , pMin, pMax, pRate] = row;
    if (gradeExp > 0) this.addExp(gradeExp);
    if (pRate > 0 && pMax > 0) {
      // approximate massacre penalty: only weak-monster farming (below the char's grade division) raises it
      const cur = this.current();
      if ((cur?.division || 0) >= 2) this._addChaotic(randInt(pMin, pMax) * (pRate / 100));
    }
  }

  // ------------------------------------------------------------------------------------------- chaotic / pk
  chaoticRow(v = this.st.chaotic) {
    for (const r of this.PK?.chaotic || []) if (v >= r.start && v <= r.end) return r;
    return null;
  }
  /** {value, dropRate, forcedRespawn, level} - read by the nameplate / target-plate owner and the loot system. */
  chaoticStatus() {
    const st = this.st, row = this.chaoticRow(st.chaotic);
    return { value: st.chaotic, dropRate: row?.dropRate || 0, forcedRespawn: !!row?.respawn, pk: st.pk };
  }
  _addChaotic(n) {
    if (!(n > 0)) return;
    const st = this.st;
    const before = this.chaoticRow(st.chaotic);
    st.chaotic = Math.max(0, st.chaotic + n);
    const after = this.chaoticRow(st.chaotic);
    if (after && after !== before) { msg(this.game, strNow(this.game, 130, 40) || `Chaotic status: ${after.dropRate}% drop penalty${after.respawn ? ', forced respawn on death' : ''}.`, 'err'); this.game.events?.emit?.('life:chaotic', this.chaoticStatus()); }
  }
  /** A player kill (future PvP/duel system): rolls the kills-in-window -> chaotic delta table. */
  addPk() {
    const st = this.st;
    st.pk = (st.pk || 0) + 1;
    st.pkWindow.push(Date.now());
    st.pkWindow = st.pkWindow.filter((t) => Date.now() - t < 3600e3);
    const n = st.pkWindow.length;
    const row = (this.PK?.pkcount || []).find((r) => n >= r.start && n <= r.end) || (this.PK?.pkcount || []).slice(-1)[0];
    if (row) this._addChaotic(row.chaotic);
    this.game.events?.emit?.('life:pk', this.chaoticStatus());
    this.game.persist?.();
  }
  _decayRate() {
    // The current map's native rate (src/game/chaotic-decay.js), the same rule as the host (server/world/wanted.mjs).
    const g = this.game, index = g.world?.info?.index ?? g.save?.map;
    return chaoticDecayPerSec(index != null ? g.mapRow?.(index) : null, DECAY_PER_SEC);
  }

  // ------------------------------------------------------------------------------------------- titles
  get titles() { return this.G?.titles || []; }
  title(i = this.st.titleIndex) { return this.titles.find((t) => t.Index === i) || null; }
  /** Owned titles (save.life.titles). */
  owns(i) { return ownsTitle(state(this.game).titles, i); }
  _titleEvent(kind, monster) {
    if (this.game.network?.active) return;   // shared play: the host counts (server/world/titles.mjs)
    const s = state(this.game), r = titleProgress(this.titles, s.titles, { kind, monster });
    if (!r.changed) return;
    s.titles = r.state;
    // original messages 2802|9 "[<VALUE>] Title [COUNT1]/[COUNT2] in progress" / 2802|3 "[<VALUE>] Title Obtained" (TITLE_CHOSEN.progressNotice)
    for (const q of r.progress || []) { const text = strNow(this.game, 2802, 9); if (text) msg(this.game, text.replace('<VALUE>', this.title(q.index)?.Name || q.index).replace('[COUNT1]', q.have).replace('[COUNT2]', q.need)); }
    for (const i of r.earned) { void msgRef(this.game, 2802, 3, 'NORMAL', 'sys', { VALUE: this.title(i)?.Name || i }); this.game.events?.emit?.('life:title', { index: this.st.titleIndex, earned: i }); }
    this.game.persist?.();
  }
  setTitle(i) {
    if (i && !this.title(i)) return false;
    if (i && !this.owns(i)) return false;
    this.st.titleIndex = i;
    this.game.events?.emit?.('life:title', { index: i });
    this.game.persist?.();
    return true;
  }
  /** Data-only: {statIndex, value} of the equipped title's passive option (no stat-modifier hook exists yet). */
  titleBonus() { const t = this.title(); return t ? { statIndex: t.Option_Index1, value: t.Option_Value1, desc: t.Option_info } : null; }

  // ------------------------------------------------------------------------------------------- rebirth (dynamic option re-roll)
  // Data lookups via rebirth-rules.js. Material costs / dedicated Dynamic Option window: REBIRTH_UNRESOLVED.
  async _rebirth() { if (!this.REB) this.REB = await rebirthData(); return this.REB; }
  /** Possible dynamic options at an item's level for a weapon/armor re-roll (share/rebirth/itemoption_*.csv). */
  async rebirthOptions(isWeapon, level) {
    return rebirthOptionsAt(await this._rebirth(), isWeapon, level);
  }
  /** The "Change Option" text a legacy option type maps to for a class (share/rebirth/changeoption.csv). */
  async changeOption(fromType, job) {
    return changeOptionType(await this._rebirth(), fromType, job);
  }
  /** Required materials to change an item's dynamic options: Global share/item/optionchange/optionchange.csv row for the
   *  item (dynamic-option-rules.js dynamicOptionCost). { ok:false } when Global has no row for it (ENGINE-DEFAULT). */
  async rebirthCost(itemIndex) {
    const legacy = await itemsLegacyData();
    return dynamicOptionCost(legacy?.optionChange?.rows || [], itemIndex);
  }
  /** Documented gaps (no invented costs). */
  rebirthUnresolved() { return REBIRTH_UNRESOLVED; }

  // ------------------------------------------------------------------------------------------- lifecycle
  async install() {
    const g = this.game;
    if (!this.G) return;
    await str(g, 130, 40).catch(() => {});
    await str(g, 2802, 3).catch(() => {});   // title system messages (stringtable_title_syetem 2802)
    g.events?.on?.('levelup',()=>this.claimRewards());
    g.events?.on?.('death', ({ actor, killer }) => { if (actor?.kind === 'monster' && (killer === g.player || !killer)) this._onKill(Number(actor.def?.index ?? actor.monsterIndex ?? 0)); });
    g.events?.on?.('death', ({ actor, killer }) => {
      if (actor?.kind === 'monster' && (killer === g.player || !killer)) this._titleEvent('kill', Number(actor.def?.index ?? actor.monsterIndex ?? 0));
      else if (actor === g.player && killer?.kind === 'monster') this._titleEvent('downedBy', Number(killer.def?.index ?? killer.monsterIndex ?? 0));
    });
  }

  update(dt) {
    if (!this.G) return;
    const st = this.st;
    if (st.chaotic > 0) { st.chaotic = Math.max(0, st.chaotic - this._decayRate() * dt); }
  }
}
