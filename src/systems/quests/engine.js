// Quest rules: per-character state, availability gates, accept / progress / claim / abandon, repeat periods, quest
// drops and rewards (docs/formats/quests.md §5 and §8). No DOM here: the windows (dialog.js, log.js, tracker.js)
// and marks.js call into this and listen to game.events 'quest:*'.
//
// save.quests = {
//   v: 1,
//   active: { [id]: { s: [slot counts x10], t: accepted (ms) } },
//   done:   { [id]: { n: completions, t: last (ms) } },
//   period: { day: 'd:YYYY-M-D', week: 'w:YYYY-M-D', c: { [id]: completions this period } },
//   alarm:  [ids]            quests registered in the Quest Alarm (tracker), max 10 (string 1002:36)
//   titles: [title ids], points: {adv, royal}, flags: {...}
// }
import { fillPlaceholders, plainText } from './markup.js';
import { questLevelRange } from './levels.js';
import {awardMeisterRank} from '../skills/rank.js';
import { purchaseInfo, purchasesDone, purchaseFlag, purchasePage } from './vehicle-purchase.js';
import { resolveQuestWarp } from '../../game/warp-location.js';
import {titleState} from '../life/title-rules.js';
import { activePremiums, holyWaterFields } from '../shops/premium-rules.js';
import { nativeOfferPath } from './native-offer.js';
import { clearObjectiveMatches, nativeKillBinding, nativeKillBindingMatches, scriptedObjectiveNeedsBinding, unearnedTurnInTalk } from './objective-credit.js';
import {rankObjective,earnedKillKind,earnedKillMatches,earnedFishMatches,stoneObjective} from './native-earned-objectives.js';
import {awakeningGradeRow,awakeningShieldRows} from '../../game/awakening-shield.js';
import {nativeExchangeMenu,ARGATE_RECIPES,OBLIVION_GROUPS,questInventoryTransfer} from './native-exchange-menus.js';

export const MAX_ACTIVE = 20;           // "up to 20 General quests" (quest strings 99 / common 1025)
export const MAX_DAILY = 15;             // "The limit for daily quest issuance is 15." (common 1026)
export const GROWTH_MAX_LEVEL = 199;     // "[Growth] quests can only be completed by characters below level 199." (common 1051)
export const MAX_ALARM = 10;             // "Max 10 quests can be registered in Quest Alarm." (1002:36)
export const RESET_HOUR = 9;             // daily reset hour (event text: 09:00)
const SLOTS = 10;

const num = v => Number(v) || 0;

/** Period keys (the daily reset is at RESET_HOUR local time; the week starts on Monday). */
export function periodKeys(date = new Date()) {
  const d = new Date(date.getTime() - RESET_HOUR * 3600e3);
  const day = `d:${d.getFullYear()}-${d.getMonth() + 1}-${d.getDate()}`;
  const mon = new Date(d); mon.setDate(d.getDate() - ((d.getDay() + 6) % 7));
  const week = `w:${mon.getFullYear()}-${mon.getMonth() + 1}-${mon.getDate()}`;
  return { day, week, weekday: d.getDay() === 0 ? 7 : d.getDay() };   // 1 = Mon .. 7 = Sun (repeat.weekday)
}

export class QuestEngine {
  /**
   * @param game  the Game
   * @param db    QuestDB (data.js)
   * @param inv   InventoryAdapter (inv.js)
   */
  constructor(game, db, inv) {
    this.game = game;
    this.db = db;
    this.inv = inv;
    this.say = (text, kind) => { try { game.hud?.log?.(text, kind || 'sys'); } catch (err) { console.warn('[quests] chat line', err?.message || err); } };
    this._dirty = new Set();
    // Older quest saves stored native title rewards only in quests.titles. Keep these selectable in the life UI.
    if(game.save.quests?.titles?.length){game.save.life||={};const titles=titleState(game.save.life.titles);titles.owned=[...new Set([...titles.owned,...game.save.quests.titles.filter(i=>Number.isSafeInteger(i)&&i>0)])].sort((a,b)=>a-b);game.save.life.titles=titles;}
  }

  // ------------------------------------------------------------------ state
  get st() {
    const s = this.game.save;
    if (!s.quests || typeof s.quests !== 'object') s.quests = {};
    const q = s.quests;
    q.v ||= 1;
    q.active ||= {};
    q.done ||= {};
    q.period ||= { day: '', week: '', c: {}, cw: {} };
    q.period.c ||= {};
    q.period.cw ||= {};
    q.alarm ||= [];
    q.titles ||= [];
    q.points ||= { adv: 0, royal: 0 };
    q.flags ||= {};
    return q;
  }
  get level() { return num(this.game.save?.level) || 1; }
  get classIndex() { return num(this.game.save?.classIndex); }
  get mapIndex() { return this.game.world?.info?.index ?? this.game.save?.map; }
  get now() { return typeof this.game.now==='function'?this.game.now():Date.now(); }
  random() { return typeof this.game.random==='function'?this.game.random():Math.random(); }

  isActive(id) { return !!this.st.active[id]; }
  isDone(id) { return num(this.st.done[id]?.n) > 0; }
  doneCount(id) { return num(this.st.done[id]?.n); }
  activeIds() { return Object.keys(this.st.active).map(Number); }
  slots(id) { return this.st.active[id]?.s || null; }
  isTracked(id) { return this.st.alarm.includes(Number(id)); }

  /** Completions of a repeatable quest in its current period. */
  periodCount(id) {
    this.checkReset();
    const q = this.db.quest(id);
    const P = this.st.period;
    return num((this._weekly(q) ? P.cw : P.c)[id]);
  }
  _weekly(q) { return q?.cat === 'weekly' || (q?.repeat && !q.repeat.daily && q.cat === 'weekly'); }
  /** Completions allowed per period (repeatable quests), or 0 when not repeatable. */
  repeatLimit(q) {
    if (!q?.repeat) return 0;
    return Math.max(1, num(q.repeat.perPeriod) || num(q.repeat.count) || 1);
  }

  /** Daily / weekly reset of the period counters (repeat quests). */
  checkReset() {
    const k = periodKeys(new Date(this.now));
    const P = this.st.period;
    if (P.day !== k.day) { P.day = k.day; P.c = {}; }
    if (P.week !== k.week) { P.week = k.week; P.cw = {}; }
  }

  // ------------------------------------------------------------------ objectives
  objectiveDone(q, o, s = this.slots(q.id)) { return !!s && num(s[o.slot]) >= Math.max(1, num(o.count) || 1); }

  /** Are the objectives met (all, or any with require.completeAny)? */
  isComplete(id) {
    const q = this.db.quest(id);
    const s = this.slots(id);
    if (!q || !s) return false;
    const objs = (q.objectives || []);
    if (!objs.length) return true;
    if (q.require?.completeAny) return objs.some(o => this.objectiveDone(q, o, s));
    return objs.every(o => this.objectiveDone(q, o, s));
  }
  /** The first completed slot (for completeAny / objective rewards). */
  completedSlot(id) {
    const q = this.db.quest(id);
    const s = this.slots(id);
    for (const o of q?.objectives || []) if (this.objectiveDone(q, o, s)) return o.slot;
    return 0;
  }

  /** Objective label with count (tracker / log). */
  objectiveText(q, o, s = this.slots(q.id)) {
    const cnt = Math.min(num(s?.[o.slot]), Math.max(1, num(o.count) || 1));
    const max = Math.max(1, num(o.count) || 1);
    const os = this.db.D.objectiveStrings?.[q.id]?.[o.slot];
    if (os) return fillPlaceholders(os, { count: cnt, maxCount: max });
    const label = o.label || this._autoLabel(o);
    return `${label} ${cnt}/${max}`;
  }
  _autoLabel(o) {
    const t = (o.targets || [])[0];
    switch (o.kind) {
      case 'kill': return t ? `[mlink]${t.id}[/mlink]` : 'Defeat monsters';
      case 'collect': return t ? `[ilink]${t.id}[/ilink]` : 'Collect items';
      case 'talk': return t ? `Talk to [nlink]${t.id}[/nlink]` : 'Talk';
      case 'killOnMap': return t ? `Monsters of ${this.db.mapName(t.id)}` : 'Monsters';
      case 'clearMap': return t ? `Clear ${this.db.mapName(t.id)}` : 'Clear the dungeon';
      case 'useSkill': return t ? t.name || `Skill ${t.id}` : 'Use skills';
      case 'fish': return 'Fishing';
      default: return o.label || '';
    }
  }
  /** Placeholder context of a quest (for <COUNTk>, <Object_k>, <code N>). */
  ctx(q) {
    const s = this.slots(q.id) || [];
    const counts = [], max = [];
    for (const o of q.objectives || []) { counts[o.slot] = Math.min(num(s[o.slot]), num(o.count) || 1); max[o.slot] = num(o.count) || 1; }
    return {
      counts, max, questIndex: q.title || q.id, title: q.titleName || '',
      objectLabel: k => { const o = (q.objectives || []).find(x => x.slot === k); return o ? plainText(o.label || this._autoLabel(o), this.names) : ''; },
      code: n => this.db.str(q.id, n) ?? '',
    };
  }
  get names() {
    const db = this.db;
    return { npc: i => db.npcName(i), monster: i => db.monsterName(i), item: i => db.itemName(i) };
  }

  // ------------------------------------------------------------------ availability
  /**
   * Gate check for accepting / listing a quest.
   * @returns {{ok:boolean, list:boolean, low?:boolean, code?:number, reason?:string}}
   *   list = whether an NPC menu should show it (hidden gates: prerequisites, class, schedule...).
   */
  check(id) {
    const q = this.db.quest(id);
    if (!q || q.isGroup) return { ok: false, list: false, reason: 'none' };
    if (q.src === 'server') return { ok: false, list: false, reason: 'server' };
    if (q.require?.unavailable) return {ok:false,list:true,reason:'unavailable',code:q.require.unavailable,page:q.require.unavailablePage};
    if (this.isActive(id)) return { ok: false, list: true, reason: 'active', code: 1039 };
    const lv = this.level;
    const { min: lmin, max: lmax } = questLevelRange(q);
    const rep = this.repeatLimit(q);
    if (this.isDone(id) && !rep) return { ok: false, list: false, reason: 'done', code: 1042 };
    if (q.prereq && !this.isDone(q.prereq)) return { ok: false, list: false, reason: 'prereq', code: 1011 };
    if (q.going && !this.isActive(q.going)) return { ok: false, list: false, reason: 'going' };
    const r = q.require || {};
    if (r.titleAbsent && (this.st.titles.includes(Number(r.titleAbsent)) || (this.game.save.life?.titles?.owned||[]).includes(Number(r.titleAbsent)))) return {ok:false,list:false,reason:'ownedTitle',code:104};
    if (r.class != null && Number(r.class) !== this.classIndex) return { ok: false, list: false, reason: 'class', code: 1007 };
    if(q.nativeChoicePages&&q.nativeChoicePages[this.classIndex]==null)return {ok:false,list:false,reason:'class',code:1007};
    if (r.awakened && !this.game.save?.awakened) return { ok: false, list: false, reason: 'awakened' };
    if (r.meister && !this.game.save?.meister) return { ok: false, list: false, reason: 'meister', code: 1031 };
    if (q.schedule) {
      if (q.schedule.unavailable) return { ok: false, list: false, reason: 'schedule', code: 1027 };
      const t = this.now, a = Date.parse(q.schedule.start), b = Date.parse(q.schedule.end);
      if ((Number.isFinite(a) && t < a) || (Number.isFinite(b) && t > b)) return { ok: false, list: false, reason: 'schedule', code:1027 };
    }
    if (lmax && lmax < 250 && lv > lmax) return { ok: false, list: false, reason: 'high', code: 1004 };
    if (lv < num(lmin)) return { ok: false, list: !!q.flow?.lowLevel, low: true, reason: 'low', code: 1004 };
    if (rep) {
      if (q.repeat.weekday && num(q.repeat.weekday) !== periodKeys(new Date(this.now)).weekday) return { ok: false, list: false, reason: 'weekday', code: 1027 };
      if (this.periodCount(id) >= rep) return { ok: false, list: true, reason: 'repeat', code: 1030 };
    }
    // guild quests (Commission Center tests / missions): "Not a member of a guild." (common 1048)
    if ((q.tags || []).includes('guild') && !this._inGuild()) return { ok: false, list: true, reason: 'guild', code: 1048 };
    const instant = this._instant(q);
    if (!instant) {
      // separate issuance limits (quests.md §5.1-1): daily 15 (common 1026), general 20 (common 1025, or the quest's own
      // string 99 "The maximum number of active quests is 20, including commissioned and normal quests."), mission 20
      const grp = this._limitGroup(q);
      const n = this.activeIds().filter(a => this._limitGroup(this.db.quest(a)) === grp).length;
      if (grp === 'daily' && n >= MAX_DAILY) return { ok: false, list: true, reason: 'limit', code: 1026 };
      if (grp !== 'daily' && n >= MAX_ACTIVE) return { ok: false, list: true, reason: 'limit', code: this.db.str(id, 99, { common: false }) ? 99 : 1025 };
    }
    return { ok: true, list: true };
  }
  _limitGroup(q) {
    if ((q?.listedBy || []).some(l => Number(l[1]) === 114)) return 'mission';
    return this._isDaily(q) ? 'daily' : 'general';
  }
  _inGuild() { const g = this.game; return !!(g.save?.guild || g.guild?.name); }
  /** Daily quests (their own issuance limit): daily / weekday / weekly categories and DAILY_QUEST_STD (JobType 57) lines. */
  _isDaily(q) {
    if (!q) return false;
    if (['daily', 'weekday', 'weekly'].includes(q.cat)) return true;
    return (q.listedBy || []).some(l => Number(l[1]) === 57);
  }
  _instant(q) { return !!q.require?.instant || q.kind === 'instant' || q.kind === 'exchange'; }
  /**
   * A quest-job line that is only a talk tree: no objectives and nothing to hand out (NPC side lines, guides,
   * legacy [Exchange] menus whose server script is not in the client). It opens its pages and never enters the log.
   */
  isTalkOnly(q) {
    if (!q) return false;
    if(nativeExchangeMenu(this.db,q.id)||[23,24].includes(q.id)&&/quest_(?:23|24)_guild_agit_warp_[12]\.csv$/.test(q.dialog?.file||''))return true;
    if ((q.objectives || []).length || this._instant(q)) return false;
    const r = q.rewards || {};
    const gives = num(r.exp) || num(r.dil) || (r.items || []).length || r.timedItem || r.title || num(r.adv) || r.warp || r.status || r.awakening || r.meister || (q.rewardVariants?.list || []).length;
    if (gives) return false;
    return q.kind === 'dialog' || q.kind === 'none' || q.src === 'text' || (q.tags || []).includes('guide') || (q.tags || []).includes('exchange') || !q.kind;
  }

  /**
   * Menu state of a quest at an NPC: 'available' | 'low' | 'active' | 'complete' | 'repeatDone' | null (hidden).
   */
  stateAt(id, npcIndex) {
    const q = this.db.quest(id);
    if (!q) return null;
    if (this.isActive(id)) return this.isComplete(id) ? 'complete' : 'active';
    const c = this.check(id);
    if (c.ok) return 'available';
    if (c.reason === 'limit') return 'available';      // offered; the accept prints the issuance limit (1025 / 1026)
    if (c.low && c.list) return 'low';
    if (c.reason === 'repeat') return 'repeatDone';
    if (c.reason === 'guild') return 'locked';         // listed; opening it prints "Not a member of a guild." (1048)
    if (c.reason === 'unavailable') return 'locked';   // native event-ended / cannot-complete refusal
    return null;
  }

  // ------------------------------------------------------------------ accept
  /** Messages: common quest strings, printed as system lines. */
  message(code, q = null, extra = {}) {
    let t = (q && this.db.str(q.id, code, { common: false })) ?? this.db.common(code);
    if (t == null) return;
    t = fillPlaceholders(t, q ? this.ctx(q) : {});
    t = t.replace(/<TITLE>/g, extra.title ?? '').replace(/<Quest_Index>/gi, extra.quest ?? '');
    this.say(plainText(t, this.names), 'sys');
  }
  /** Client notice string (1002:26 "The quest has started." etc.) */
  notice(text) { if (text) this.say(plainText(text, this.names), 'sys'); }

  /**
   * Take a quest into the log (the accept branch of the offer dialog).
   * @returns {{ok:boolean, code?:number, page?:number}}  page = a message page to show instead (missing items)
   */
  accept(id, { silent = false, npc = null } = {}) {
    const q = this.db.quest(id);
    if (!q) return { ok: false };
    if(this.isTalkOnly(q))return {ok:false,code:1050};
    const c = this.check(id);
    if (!c.ok) { if (c.code && !silent) this.message(c.code, q, { quest: this.db.quest(q.prereq)?.title || q.prereq }); return { ok: false, code: c.code, ...(c.page?{page:c.page}:{}) }; }
    const r = q.require || {};
    const required=this.requiredItems(q); if(!required.ok)return required;
    if (r.status && !this._hasStatus(r.status)) { this.message(1047, q); return { ok: false, code: 1047 }; }
    if (r.giveOnAccept?.length && !this.inv.canFit(r.giveOnAccept)) { this.message(this.db.str(id, 57) ? 57 : 1002, q); return { ok: false, code: 1002 }; }

    this.st.active[id] = { s: new Array(SLOTS).fill(0), t: this.now };
    for (const it of r.giveOnAccept || []) this.inv.add(it.item, it.count, { reason: 'questAccept' });
    // Accepting a legacy service is not evidence of its exchange/warp/ticket
    // operation. Its private-script objective stays pending until explicitly bound.
    if (this.st.alarm.length < MAX_ALARM && !this._instant(q)) this.st.alarm.push(Number(id));
    if (q.callMonster) this._callMonster(q.callMonster);
    this.recountCollect(id, true);
    if (!silent) {
      const S = this.db.Q.assets?.sounds || {};
      // mission quests (NPC JobType 114 MISSION_TITLE) announce "Mission start" (sound/word_missionstart.wav)
      const snd = this._limitGroup(q) === 'mission' ? (S.missionStart || 'word_missionstart.wav') : (S.accept || 'quest_accept.wav');
      this.game.audio?.sfx?.(snd.replace(/^sound\//, ''));
      this.notice(this.game.uiwin?.strings?.get({ group: 'NORMAL', cate: 1002, code: 26 }) || '[message] The quest has started.');
    }
    this.game.events?.emit?.('quest:accept', { id, npc });
    this._changed(id);
    return { ok: true };
  }

  // Recheck at hand-in too: showing an item when accepting does not establish
  // that it is still carried when the reward is claimed (including older saves).
  requiredItems(q) {
    const r=q.require||{};
    if(r.unavailable)return {ok:false,code:r.unavailable,...(r.unavailablePage?{page:r.unavailablePage}:{})};
    if(r.dil&&this.inv.dil<num(r.dil)){this.message(1000,q);return {ok:false,code:1000,...(r.missingDilPage?{page:r.missingDilPage}:{})};}
    for(const it of r.items||[]){
      const ids=Array.isArray(it.item)?it.item:[it.item];
      if(ids.reduce((sum,id)=>sum+this.inv.count(id),0)>=Math.max(1,num(it.count)))continue;
      const code=r.missingItemsCode||1003;this.message(code,q);
      return {ok:false,code,...(r.missingItemsMsg&&this.db.pageText(q.id,r.missingItemsMsg)!=null?{page:r.missingItemsMsg}:{})};
    }
    return {ok:true};
  }

  /** Give up a quest (quest window "Abandon"). */
  abandon(id) {
    const q = this.db.quest(id);
    if (!this.isActive(id)) return false;
    delete this.st.active[id];
    this.st.alarm = this.st.alarm.filter(x => x !== Number(id));
    // items handed over on accept are taken back (they belong to the quest)
    for (const it of q?.require?.giveOnAccept || []) this.inv.remove(it.item, Math.min(this.inv.count(it.item), num(it.count) || 1), { reason: 'questAbandon' });
    this.game.audio?.sfx?.(this.db.Q.assets?.sounds?.giveUp?.replace(/^sound\//, '') || 'quest_qive_up.wav');
    this.notice(this.game.uiwin?.strings?.get({ group: 'NORMAL', cate: 1002, code: 25 }) || '[message] The quest has been cancelled.');
    this.game.events?.emit?.('quest:abandon', { id });
    this._changed(id);
    return true;
  }

  // ------------------------------------------------------------------ progress
  /** Add progress to a slot; prints the progress / slot-complete / all-complete lines. */
  advance(id, slot, amount = 1, { set = false } = {}) {
    const q = this.db.quest(id);
    const a = this.st.active[id];
    if (!q || !a) return false;
    const o = (q.objectives || []).find(x => x.slot === slot);
    if (!o) return false;
    const max = Math.max(1, num(o.count) || 1);
    const before = num(a.s[slot]);
    const wasComplete = this.isComplete(id);
    const after = Math.max(0, Math.min(max, set ? num(amount) : before + num(amount)));
    if (after === before) return false;
    a.s[slot] = after;
    if (after > before) {
      const pm = o.progressMsg ?? (200 + slot);
      const own = this.db.str(id, pm, { common: false });
      if (own) this._printQuestLine(q, own);
      else {
        const label = plainText(o.label || this._autoLabel(o), this.names);
        this.say(`${label} ${after}/${max}`, 'sys');
      }
      if (after >= max) {
        const done = this.db.str(id, 300 + slot, { common: false });
        if (done) this._printQuestLine(q, done);
        else this.message(300 + slot, q);
      }
      if (!wasComplete && this.isComplete(id)) {
        const all = this.db.str(id, 400, { common: false });
        if (all) this._printQuestLine(q, all); else this.message(400, q);
        this.game.events?.emit?.('quest:ready', { id });
      }
    }
    this.game.events?.emit?.('quest:progress', { id, slot, count: after, max });
    this._changed(id);
    return true;
  }
  _printQuestLine(q, text) {
    if (!/\[message\]/i.test(text) && text.length > 160) return;   // a dialog page, not a chat line
    this.say(plainText(fillPlaceholders(text, this.ctx(q)), this.names), 'sys');
  }

  /** A monster died (game.events 'death'). */
  onKill(actor, killer) {
    const g = this.game;
    const p = g.player;
    if (!actor || actor.kind !== 'monster' || !killer || !(killer === p || killer.owner === p)) return;
    const mi = Number(actor.monsterIndex ?? actor.def?.index ?? actor.index);
    const map = this.mapIndex;
    const name = String(actor.def?.name || actor.name || '').toLowerCase();
    for (const id of this.activeIds()) {
      const q = this.db.quest(id);
      if (!q) continue;
      const qMap = q.require?.map;
      for (const o of q.objectives || []) {
        if (this.objectiveDone(q, o)) continue;
        if(rankObjective(q,o))continue;
        if(earnedKillKind(q,o)){
          if(earnedKillMatches(this,q,o,actor))this.advance(id,o.slot,1);
          continue;
        }
        const om = o.map ?? qMap;
        if (om != null && Number(om) !== Number(map)) continue;
        let hit = false;
        if (o.kind === 'kill') {
          hit = (o.targets || []).some(t => Number(t.id) === mi) || (Array.isArray(o.range) && mi >= o.range[0] && mi <= o.range[1]);
        } else if (o.kind === 'killOnMap') {
          hit = (o.targets || []).some(t => Number(t.id) === Number(map));
        } else if (scriptedObjectiveNeedsBinding(o)) {
          // only a source-resolved boss binding (objective-credit.js) may credit a scripted dungeon slot
          hit = nativeKillBindingMatches(nativeKillBinding(id, o), mi, map);
        } else if (o.kind === 'scripted' && (o.hint === 'kill' || o.hint === 'collect') && q.map != null && Number(q.map) === Number(map) && name) {
          const lab = plainText(o.label || '', this.names).toLowerCase();
          hit = !!lab && (lab.includes(name) || name.split(/\s+/).filter(w => w.length > 3).some(w => lab.includes(w)));
        }
        if (!hit) continue;
        if (o.chance != null && this.random() >= Number(o.chance)) continue;
        this.advance(id, o.slot, Math.max(1, num(o.per) || 1));
      }
      this._rollQuestDrops(q, mi, map);
    }
  }

  /** Quest-item drops (questdropitem.csv): roll while the quest is active and the collect slot is not full. */
  _rollQuestDrops(q, monsterIndex, map) {
    for (const d of q.drops || []) {
      if (!(d.monsters || []).some(m => Number(m) === monsterIndex)) continue;
      if (d.map && Number(d.map) !== Number(map)) continue;
      if (d.levelCap && this.level > num(d.levelCap)) continue;
      const o = (q.objectives || []).find(x => x.kind === 'collect' && (x.targets || []).some(t => Number(t.id) === Number(d.item)));
      if (o && this.inv.count(d.item) >= Math.max(1, num(o.count) || 1)) continue;
      if (!o && this.inv.count(d.item) > 0 && this.db.itemStack(d.item) <= 1) continue;
      if (this.random() >= (d.chance ?? 1)) continue;
      if (!this.inv.canFit([{ item: d.item, count: 1 }])) { this.message(1002, q); continue; }
      if (this.inv.add(d.item, 1, { reason: 'questDrop' })) {
        const name = this.db.itemName(d.item);
        this.game.events?.emit?.('loot', { name, count: 1, kind: 'item', itemIndex: Number(d.item), quest: q.id });
        this.recountCollect(q.id);
      }
    }
  }

  /** Collect objectives follow the inventory count of the item (clamped to the required count). */
  recountCollect(onlyId = null, silent = false) {
    for (const id of onlyId != null ? [Number(onlyId)] : this.activeIds()) {
      const q = this.db.quest(id);
      const a = this.st.active[id];
      if (!q || !a) continue;
      for (const o of q.objectives || []) {
        if (o.kind !== 'collect') continue;
        const max = Math.max(1, num(o.count) || 1);
        let have = 0;
        for (const t of o.targets || []) have += this.inv.count(t.id);
        have = Math.min(max, have);
        if (have !== num(a.s[o.slot])) {
          if (silent) { a.s[o.slot] = have; this._changed(id); } else this.advance(id, o.slot, have, { set: true });
        }
      }
    }
  }

  /** A skill was used ('skill' event): useSkill objectives. */
  onSkill(skillIndex) {
    const map = this.mapIndex;
    for (const id of this.activeIds()) {
      const q = this.db.quest(id);
      for (const o of q?.objectives || []) {
        if (o.kind !== 'useSkill' || this.objectiveDone(q, o)) continue;
        const om = o.map ?? q.require?.map;
        if (om != null && Number(om) !== Number(map)) continue;
        if ((o.targets || []).some(t => Number(t.id) === Number(skillIndex))) this.advance(id, o.slot, Math.max(1, num(o.per) || 1));
      }
    }
  }
  /** Fishing success ('fish' event). */
  onFish(count = 1, itemIndex = null) {
    for (const id of this.activeIds()) {
      const q = this.db.quest(id);
      for (const o of q?.objectives || []) if ((o.kind === 'fish'||earnedFishMatches(q,o,itemIndex)) && !this.objectiveDone(q, o)) this.advance(id, o.slot, count);
    }
  }
  /** A dungeon / battlefield was cleared ('dungeon:clear' {map}). */
  onClearMap(map) {
    for (const id of this.activeIds()) {
      const q = this.db.quest(id);
      for (const o of q?.objectives || []) {
        if (this.objectiveDone(q, o)) continue;
        if (clearObjectiveMatches(o, map)) this.advance(id, o.slot, 1);
      }
    }
  }

  /**
   * Talking to an NPC: complete talk objectives that target it (taking needItem). Other scripted hints keep the
   * turn-in talk credit only where speaking to the turn-in NPC is their original operation; services, dungeon
   * conditions and the rows of objective-credit.js UNEARNED_TURN_IN_TALK require their actual operation (as online).
   */
  talkTo(npcIndex, onlyId = null) {
    const n = Number(npcIndex);
    const changed = [];
    for (const id of onlyId != null ? [Number(onlyId)] : this.activeIds()) {
      const q = this.db.quest(id);
      if (!q || !this.isActive(id)) continue;
      for (const o of q.objectives || []) {
        if (this.objectiveDone(q, o)) continue;
        const rank=rankObjective(q,o);
        if(rank){
          if(n!==5489)continue;
          const rows=this.game.data?.gradeRows||this.game.life?.data?.grade?.grades;
          const current=awakeningGradeRow(this.game.save,awakeningShieldRows(rows));
          if(current&&current.grade>=rank&&this.advance(id,o.slot,1,{set:true}))changed.push(id);
          continue;
        }
        const stones=stoneObjective(q,o);
        if(stones){
          // The host first checks live admission. Solo uses the actual native
          // stone dialog in map650. Distinct stones persist with the quest.
          if(this.mapIndex!==650||!stones.includes(n))continue;
          const a=this.st.active[id],seen=new Set((a.investigatedStones||[]).filter(x=>stones.includes(x)));
          if(seen.has(n))continue;
          seen.add(n);a.investigatedStones=[...seen];
          if(this.advance(id,o.slot,seen.size,{set:true}))changed.push(id);
          continue;
        }
        if (scriptedObjectiveNeedsBinding(o)) continue;
        const target = (o.kind === 'talk' && (o.targets || []).some(t => Number(t.id) === n)) || (o.weak && Number(o.navNpc) === n);
        const scriptedAtTurnIn = o.kind === 'scripted' && !['kill', 'collect', 'dungeon'].includes(o.hint) && Number(q.turnIn?.npc) === n && !unearnedTurnInTalk(id, o);
        if (!target && !scriptedAtTurnIn) continue;
        if (o.needItem?.item) {
          const need = Math.max(1, num(o.needItem.count) || 1);
          if (this.inv.count(o.needItem.item) < need) { this.message(1009, q); continue; }
          this.inv.remove(o.needItem.item, need, { reason: 'questTalk' });
        }
        if (this.advance(id, o.slot, Math.max(1, num(o.count) || 1), { set: true })) changed.push(id);
      }
    }
    return changed;
  }

  // ------------------------------------------------------------------ claim
  /** The reward block that applies (variants by choice option / repeat number / completed slot / class). */
  rewardFor(q, option = null) {
    let base = q.rewards || {};
    if(base.guildExp){
      const cap=base.guildExp,rows=this.game.data?.exp?.levels;
      const top=Number(rows?.find(r=>Number(r.level)===cap.capLevel)?.toNext),current=Number(rows?.find(r=>Number(r.level)===this.level)?.toNext);
      // Native text fixes the170+ payout but omits its earlier curve. Explicit
      // ENGINE-CHOSEN: preserve its fraction of the installed level EXP curve.
      const exp=this.level>=cap.capLevel?cap.exp:top>0&&current>0?Math.max(1,Math.round(cap.exp*Math.min(1,current/top))):0;
      base={...base,exp};
    }
    const V = q.rewardVariants;
    if (!V?.list?.length) return base;
    const cls = this.classIndex;
    const classOk = v => v.classIndex == null || Number(v.classIndex) === cls;
    let pick = null;
    if (V.mode === 'choice') pick = V.list.find(v => classOk(v) && option != null && Number(v.option) === Number(option));
    else if (V.mode === 'repeat') { const nth = this.periodCount(q.id) + 1; pick = V.list.find(v => classOk(v) && Number(v.repeat) === nth) || V.list.filter(classOk).slice(-1)[0]; }
    else if (V.mode === 'objective') { const s = this.completedSlot(q.id); pick = V.list.find(v => classOk(v) && Number(v.slot) === s); }
    else if (V.mode === 'level') pick = V.list.find(v => classOk(v) && this.level >= v.level?.[0] && this.level <= v.level?.[1]);
    if (!pick) pick = V.list.find(v => classOk(v) && v.slot != null && v.slot === this.completedSlot(q.id) && (option == null || v.option == null));
    if (!pick && !['choice','level'].includes(V.mode)) pick = V.list.find(classOk);
    return pick ? { ...base, ...pick.reward } : base;
  }
  /** Message page of the repeat variant for this period's next completion (ticket issuance pages). */
  repeatPage(q) {
    const V = q.rewardVariants;
    if (V?.mode !== 'repeat') return null;
    const nth = this.periodCount(q.id) + 1;
    const v = V.list.find(x => Number(x.repeat) === nth);
    return v?.msg ?? null;
  }

  /**
   * Turn in a quest: verify, take, grant (docs quests.md §5.1-5 / §8-7).
   * @returns {{ok:boolean, code?:number, reward?:object}}
   */
  claim(id, { option = null, npc = null, silent = false } = {}) {
    const g = this.game;
    const q = this.db.quest(id);
    if (!q || !this.isActive(id)) return { ok: false, code: 1050 };
    const required=this.requiredItems(q);if(!required.ok)return required;
    if (!this.isComplete(id)) { this.message(1050, q); return { ok: false, code: 1050 }; }
    if (q.cat === 'growth' && this.level >= GROWTH_MAX_LEVEL) { this.message(1051, q); return { ok: false, code: 1051 }; }
    if(q.require?.titleAbsent&&(this.st.titles.includes(Number(q.require.titleAbsent))||(g.save.life?.titles?.owned||[]).includes(Number(q.require.titleAbsent))))return {ok:false,code:104};
    let R = this.rewardFor(q, option);
    if(q.rewardVariants?.mode==='level'&&!q.rewardVariants.list.some(v=>(v.classIndex==null||Number(v.classIndex)===this.classIndex)&&this.level>=v.level?.[0]&&this.level<=v.level?.[1]))return {ok:false,code:1004};
    if(q.nativeChoicePages&&!q.rewardVariants?.list?.some(v=>v.classIndex===this.classIndex&&v.option===option))return {ok:false,code:1007};
    if(R.randomRewards?.length){const a=this.st.active[id];if(!Number.isInteger(a.rewardChoice)||a.rewardChoice<0||a.rewardChoice>=R.randomRewards.length)a.rewardChoice=Math.min(R.randomRewards.length-1,Math.floor(this.random()*R.randomRewards.length));R={...R,...R.randomRewards[a.rewardChoice]};}
    if(R.donationTiers){const price=R.donationTiers.find(price=>this.inv.dil>=price);if(!price)return {ok:false,code:1000,page:16000};R={...R,takeDil:price};}
    // the reward's own level range (renew Reward_Level [min, max]): outside it the turn-in is refused (1004)
    if (Array.isArray(R.level)) {
      const [a, b] = R.level.map(num);
      if (this.level < a || (b && b < 250 && this.level > b)) { this.message(1004, q); return { ok: false, code: 1004 }; }
    }
    // Native timed-ticket rows (quest_rewardlist Reward_Dupl_Check=1 with Item_Limit/Limit_Time): the issuing
    // quest's own message 1000 refuses while an unexpired copy is held ("You may not possess more than 1 ticket").
    const ticket = num(R.raw?.Reward_Dupl_Check) === 1 && R.timedItem?.item ? Number(R.timedItem.item) : null;
    if (ticket && this.inv.count(ticket) > 0) { this.message(1000, q); return { ok: false, code: 1000 }; }
    // Recovered quest 35 rounds 3-5: its own message 1002 limits additional issuance to Holy Water of Almighty users.
    if (R.requireHolyWater && !activePremiums(this.game.save?.premium, this.now).some(p => holyWaterFields(p.fields))) { this.message(1002, q); return { ok: false, code: 1002 }; }
    // requirements of the reward: items to take, DIL to take, space for the items
    for (const t of R.take || []) {
      const ids = Array.isArray(t.item) ? t.item : [t.item];
      const need = Math.max(1, num(t.count) || 1);
      // a ticket quest's own 1001 names the missing Super Passes (its 1003 is the issue notice)
      const short = ticket && /super ?pass/i.test(this.db.str(q.id, 1001, { common: false }) || '') ? 1001 : 1003;
      if (!ids.some(i => this.inv.count(i) >= need) && !(ids.reduce((a, i) => a + this.inv.count(i), 0) >= need)) { this.message(short, q); return { ok: false, code: short }; }
    }
    if (R.takeDil && this.inv.dil < num(R.takeDil)) { this.message(1000, q); return { ok: false, code: 1000 }; }
    const give = [], skipped=[];
    for (const it of R.items || []) {
      // ENGINE-CHOSEN parity for text-only legacy rewards whose original item
      // does not exist: preserve the valid rewards, omit the absent item in both
      // modes and expose it in the result. Never manufacture an undefined item.
      if(!Number.isSafeInteger(it.item)||it.item<=0||(this.db.itemExists&&!this.db.itemExists(it.item))){skipped.push({text:it.text||'',count:Math.max(1,num(it.count)||1)});continue;}
      if (it.chance != null && it.chance > 0 && it.chance < 1 && this.random() >= it.chance) continue;
      give.push({ item: it.item, count: Math.max(1, num(it.count) || 1), sockets: it.sockets });
    }
    if (R.timedItem?.item) give.push({ item: R.timedItem.item, count: 1, period: num(R.timedItem.seconds) });
    // collect-objective items are handed in unless the reward says otherwise (they are quest items)
    // grant
    let exp = num(R.exp);
    const take=(R.take||[]).map(t=>({...t,count:Math.max(1,num(t.count)||1)}));
    if (R.expBonus?.item && this.inv.count(R.expBonus.item) > 0 && exp > 0) {
      exp += Math.round(exp * num(R.expBonus.rate));
      if (R.expBonus.consume) take.push({item:R.expBonus.item,count:1});
    }
    const dil = num(R.dil);
    if(!questInventoryTransfer(this.inv,{take,give,takeDil:num(R.takeDil),giveDil:dil})){this.message(1002,q);return {ok:false,code:1002};}
    if (R.title) {
      if (!this.st.titles.includes(Number(R.title))) { this.st.titles.push(Number(R.title)); this.message(1016, q, { title: R.titleName || R.title }); }
      else this.message(1012, q);
      g.save.life||={};const titles=titleState(g.save.life.titles);if(!titles.owned.includes(Number(R.title)))titles.owned.push(Number(R.title));titles.owned.sort((a,b)=>a-b);g.save.life.titles=titles;
    }
    if (R.takeTitle){this.st.titles = this.st.titles.filter(t => t !== Number(R.takeTitle));if(g.save.life?.titles){g.save.life.titles=titleState(g.save.life.titles);g.save.life.titles.owned=g.save.life.titles.owned.filter(t=>t!==Number(R.takeTitle));}if(Number(g.save.life?.grade?.titleIndex)===Number(R.takeTitle))g.save.life.grade.titleIndex=0;}
    if(R.title||R.takeTitle)g.events?.emit?.('life:title',{earned:Number(R.title)||null,taken:Number(R.takeTitle)||null,index:Number(g.save.life?.grade?.titleIndex)||0});
    if (R.adv) this.st.points.adv = num(this.st.points.adv) + num(R.adv);
    if (R.royal) this.st.points.royal = num(this.st.points.royal) + num(R.royal);
    if (R.awakening) g.save.awakened = true;
    if (R.meister) awardMeisterRank(g.save,R.meister);
    if (R.status?.id && g.player) { try { g.skills?.addStatus?.(g.player, null, Number(R.status.id), num(R.status.seconds) * 1000, g.player); } catch { /* optional */ } }
    if (R.removeQuest) { delete this.st.active[R.removeQuest]; delete this.st.done[R.removeQuest]; }

    // bookkeeping
    delete this.st.active[id];
    this.st.alarm = this.st.alarm.filter(x => x !== Number(id));
    const d = (this.st.done[id] ||= { n: 0, t: 0 });
    d.n += 1; d.t = this.now;
    if (q.repeat) { this.checkReset(); const P = this.st.period; const c = this._weekly(q) ? P.cw : P.c; c[id] = num(c[id]) + 1; }
    if (exp > 0) {
      if (typeof g.grantQuestExp === 'function') g.grantQuestExp(exp);
      else import('../../game/progression.js').then(m => m.grantExp(g, exp)).catch(err => console.warn('[quests] exp', err));
    }
    if (!silent) {
      g.audio?.sfx?.(this.db.Q.assets?.sounds?.complete?.replace(/^sound\//, '') || 'quest_finish.wav');
      this.notice(g.uiwin?.strings?.get({ group: 'NORMAL', cate: 1002, code: 27 }) || '[message] The quest has been completed.');
      if (dil) this.say(`${dil.toLocaleString('en-US')} Dil obtained.`, 'item');
      for (const it of give) this.say(`${this.db.itemName(it.item)} ${it.count}x obtained.`, 'item');
    }
    g.events?.emit?.('quest:complete', { id, npc, reward: R, exp, dil });
    this._changed(id);
    if (R.warp?.map != null && Array.isArray(R.warp.pos)) {
      // a location the client table leaves at (0,0) resolves to its pair's arrival row (warp-location.js, ENGINE-CHOSEN)
      const spot = resolveQuestWarp(R.warp, i => (typeof g.locationOf === 'function' ? g.locationOf(i) : g.data?.travel?.locations?.[String(i)]) ?? null);
      const w = spot ? { ...R.warp, map: spot.map, pos: spot.pos, dir: spot.dir } : R.warp;
      if(typeof g.questWarp === 'function') g.questWarp(w);
      else setTimeout(() => { Promise.resolve(g.travel?.(Number(w.map), { x: num(w.pos[0]) + 0.5, z: num(w.pos[1]) + 0.5, dirDeg: num(w.dir) })).catch(err => console.warn('[quests] warp', err)); }, 0);
    }
    return { ok: true, reward: R, exp, dil, ...(skipped.length?{skipped}:{}) };
  }

  /** Instant quests (exchanges, tickets, teleports): accept + claim at once. */
  acceptInstant(id, opts = {}) {
    const r = this.accept(id, { ...opts, silent: true });
    if (!r.ok) return r;
    const q = this.db.quest(id);
    for (const o of q.objectives || []) this.st.active[id].s[o.slot] = Math.max(1, num(o.count) || 1);
    const c = this.claim(id, opts);
    if (!c.ok) { delete this.st.active[id]; this.st.alarm = this.st.alarm.filter(x => x !== Number(id)); this._changed(id); }
    return c;
  }

  /** The native path that offers quest `id` here (native-offer.js: NPC menu/board/giver/NextIndex chain, or the starter), or null. */
  offerPath(id, { npc = null, starter = false } = {}) {
    return nativeOfferPath(this.db.Q, this.db.quest(id), npc == null ? null : Number(npc), { isDone: x => this.isDone(x), starter });
  }
  /** A player's accept (NPC dialog, request board, starter offer): only through a native offering path, then accept / instant. */
  acceptOffered(id, opts = {}) {
    const q = this.db.quest(id);
    if (!q) return { ok: false };
    if (!this.offerPath(id, opts)) return { ok: false, code: 'offer' };
    return this._instant(q) ? this.acceptInstant(id, opts) : this.accept(id, opts);
  }

  /** "Purchase." in a scripted vehicle-purchase dialog (Sergio's "Purchase Swift Box", quest 15820): pay the price of the NEXT tier (it rises
   *  with every purchase), take one box, count it. Price tiers, level and the sold-out page come from the dialog text (vehicle-purchase.js). */
  purchase(id, { option = null } = {}) {
    const q = this.db.quest(id), info = purchaseInfo(this.db, id);
    if (!q || !info) return { ok: false, code: 'none' };
    const flags = this.st.flags, done = purchasesDone(flags, id);
    if (done >= info.tiers.length) return { ok: false, code: 'soldout' };
    const tier = info.tiers[done];
    if (option != null && Number(option) !== tier.purchaseOption) return { ok: false, code: 'option' };
    if (this.level < info.minLevel) { this.message(1004, q); return { ok: false, code: 1004 }; }
    if (this.inv.dil < tier.price) { this.message(1000, q); return { ok: false, code: 1000 }; }
    const give = [{ item: info.item, count: 1 }];
    if (!this.inv.canFit(give)) { this.message(1002, q); return { ok: false, code: 1002 }; }
    this.inv.addDil(-tier.price);
    if (!this.inv.add(info.item, 1)) { this.inv.addDil(tier.price); this.message(1002, q); return { ok: false, code: 1002 }; }
    flags[purchaseFlag(id)] = done + 1;
    this._changed(id);
    return { ok: true, purchase: { item: info.item, price: tier.price, count: done + 1, page: purchasePage(info, done + 1) } };
  }

  exchange(id,{option=null}={}){
    const kind=nativeExchangeMenu(this.db,Number(id)),q=this.db.quest(id);
    if(kind==='argate'){
      const recipe=ARGATE_RECIPES[option];if(!recipe)return {ok:false,code:1050};
      if(!this.db.itemExists(recipe.take)||!this.db.itemExists(recipe.give))return {ok:false,code:1050};
      if(this.inv.count(recipe.take)<recipe.need){this.message(101,q);return {ok:false,code:101};}
      if(!questInventoryTransfer(this.inv,{take:[{item:recipe.take,count:recipe.need}],give:[{item:recipe.give,count:recipe.count}]})){this.message(1002,q);return {ok:false,code:1002};}
      this.message(recipe.message,q);this._changed(id);return {ok:true,page:recipe.message};
    }
    if(kind==='oblivion'){
      const group=OBLIVION_GROUPS[option];if(!group)return {ok:false,code:1050};
      this.checkReset();const day=this.st.period.day;
      if(this.st.flags.oblivionDay===day)return {ok:false,page:12000,code:1030};
      const completed=group.quests.filter(id=>this.periodCount(id)>0);if(!completed.length)return {ok:false,page:11000,code:101};
      const item=group.items.find(id=>this.inv.count(id)>0);if(!item)return {ok:false,code:100};
      if(!this.inv.remove(item,1))return {ok:false,code:100};
      for(const id of completed)this.st.period.c[id]=0;
      this.st.flags.oblivionDay=day;this._changed(id);return {ok:true};
    }
    return {ok:false,code:1050};
  }

  // ------------------------------------------------------------------ tracker
  track(id, on = true) {
    const a = this.st.alarm;
    const i = a.indexOf(Number(id));
    if (on && i < 0) {
      if (a.length >= MAX_ALARM) { this.say(this.game.uiwin?.strings?.get({ group: 'NORMAL', cate: 1002, code: 36 }) || 'Max 10 quests can be registered in Quest Alarm.', 'err'); return false; }
      a.push(Number(id));
    } else if (!on && i >= 0) a.splice(i, 1);
    this.game.events?.emit?.('quest:track', { id, on });
    this._changed(id);
    return true;
  }

  // ------------------------------------------------------------------ helpers
  _hasStatus(statusIndex) {
    const p = this.game.player;
    const list = p?.statuses || this.game.save?.buffs || [];
    return (Array.isArray(list) ? list : Object.values(list)).some(s => Number(s?.index ?? s?.statusIndex ?? s?.id) === Number(statusIndex));
  }
  _callMonster(cm) {
    const g = this.game;
    if (cm.map != null && Number(cm.map) !== Number(this.mapIndex)) return;
    const [x, z] = cm.pos || [g.player?.x, g.player?.z];
    for (let i = 0; i < Math.max(1, num(cm.count) || 1); i++) spawnMonster(g, Number(cm.monster), num(x) + (i ? this.random() * 2 - 1 : 0), num(z) + (i ? this.random() * 2 - 1 : 0));
  }
  _changed(id) {
    this._dirty.add(Number(id));
    if (!this._flushT) this._flushT = setTimeout(() => {
      this._flushT = null;
      const ids = [...this._dirty]; this._dirty.clear();
      this.game.events?.emit?.('quest:changed', { ids });
    }, 0);
  }
}

/**
 * Spawn a one-off monster at (x, z) through the spawner (quest callMonster, summon boxes). It never respawns.
 * Uses game.spawner.spawnMonster when a system provides one.
 */
export function spawnMonster(game, monsterIndex, x, z) {
  const sp = game.spawner;
  if (!sp) return null;
  if (typeof sp.spawnMonster === 'function') return sp.spawnMonster(monsterIndex, x, z, { oneShot: true });
  if (!Array.isArray(sp.records)) return null;
  const w = game.world;
  let px = x, pz = z;
  if (w?.isWalkable && !w.isWalkable(px, pz)) { const n = w.nearestWalkable?.(px, pz, 6); if (n) { px = n.x; pz = n.z; } }
  const rec = {
    id: `q${Date.now().toString(36)}${Math.random().toString(36).slice(2, 5)}`,
    spawn: { monsterIndex: Number(monsterIndex), x: px, z: pz, respawnSec: 0 },
    respawnSec: 1e12, monster: null, loading: false, deadAt: null, respawnAt: 0, failedUntil: 0, skip: false, oneShot: true,
  };
  sp.records.push(rec);
  sp._scan = 0;
  const off = game.events?.on?.('death', ({ actor } = {}) => { if (actor && actor.spawnRecord === rec) { rec.skip = true; if (typeof off === 'function') off(); } });
  return rec;
}
