// Quest / dialog / box tables (gamedata/quests.json, dialogs.json, boxes.json; docs/formats/quests.md, boxes.md)
// plus name lookups shared by the quest windows. Everything is loaded once and cached per page.
import { fetchJSON } from '../../engine/assets.js';
import { questNpcLayout } from './npc-layout.js';
import { nativeTitleExchanges } from './native-title-exchanges.js';
import { nativeTicketIssuance } from './native-ticket-issuance.js';
import { nativeQuestCustody } from './native-quest-custody.js';
import { nativeTextRequirements } from './native-text-requirements.js';
import { nativeTextRewards } from './native-text-rewards.js';
import { nativeEarnedObjectives } from './native-earned-objectives.js';
import { nativeExchangePage } from './native-exchange-menus.js';

let questsP = null, dialogsP = null, boxesP = null;

/** quests.json (quests, groups, lines, notices, requestBoards, assets, enums). */
export function loadQuests() { return (questsP ||= fetchJSON('/gamedata/quests.json')); }
/** dialogs.json (quests[q] trees, strings[q][code], objectiveStrings, common, npcs, jobTypeLabels). */
export function loadDialogs() { return (dialogsP ||= fetchJSON('/gamedata/dialogs.json')); }
/** boxes.json (boxes, items, itemSets, summons, levelUpChains, starter, ui). */
export function loadBoxes() { return (boxesP ||= fetchJSON('/gamedata/boxes.json')); }

/**
 * The shared quest database: raw tables + helpers. `Q` is created by the quest system and also used by the
 * windows (game.quests.db).
 */
export class QuestDB {
  constructor(game, quests, dialogs) {
    this.game = game;
    this.Q = nativeQuestCustody(nativeTicketIssuance(nativeTitleExchanges(questNpcLayout(quests, game?.data?.npcs).quests, dialogs, game), dialogs, game), dialogs, game);
    this.Q = nativeTextRequirements(nativeTextRewards(this.Q, dialogs, game), dialogs, game);
    this.Q = nativeEarnedObjectives(this.Q, dialogs);
    this.D = dialogs;         // dialogs.json
    this.B = null;            // boxes.json (lazy)
    this._pageIndex = new Map();   // quest -> Map(page -> [message, stringCode, options])
    // NPC -> quests where it is the giver / turn-in / talk target (for marks and menus)
    this.byGiver = new Map();
    this.byTurnIn = new Map();
    this.byTalk = new Map();
    // indexed from the overlaid catalogue (overlays change NPCs only where native custody is recovered)
    for (const q of Object.values(this.Q.quests || {})) {
      if (!q || q.isGroup) continue;
      const add = (m, npc) => { if (npc == null) return; const k = Number(npc); if (!m.has(k)) m.set(k, []); m.get(k).push(q.id); };
      add(this.byGiver, q.giver?.npc);
      for (const a of q.giver?.alt || []) add(this.byGiver, a);
      add(this.byTurnIn, q.turnIn?.npc);
      for (const a of q.turnIn?.alt || []) add(this.byTurnIn, a);
      for (const o of q.objectives || []) {
        if (o.kind === 'talk') for (const t of o.targets || []) add(this.byTalk, t.id);
        if (o.weak && o.navNpc != null) add(this.byTalk, o.navNpc);
      }
    }
  }

  quest(id) { return this.Q.quests?.[id] || null; }
  get quests() { return this.Q.quests || {}; }

  /** Dialog tree of a quest: {file, messages, next, entries, alt}. */
  tree(id) { return this.D.quests?.[id] || null; }

  /** [message, stringCode, options] of a page of a quest's tree, or null. */
  page(id, page) {
    let m = this._pageIndex.get(id);
    if (!m) {
      m = new Map();
      for (const row of this.tree(id)?.messages || []) m.set(Number(row[0]), row);
      this._pageIndex.set(id, m);
    }
    return m.get(Number(page)) || null;
  }

  /** Quest string (strings[q][code]); falls back to the dialog header's cate, then common strings. */
  str(id, code, { common = true } = {}) {
    const S = this.D.strings || {};
    const v = S[id]?.[code];
    if (v != null) return v;
    const h = this.tree(id)?.header;
    if (h != null && S[h]?.[code] != null) return S[h][code];
    if (common && this.D.common?.[code] != null) return this.D.common[code];
    return null;
  }

  /** Common quest system message (quest_commonstring.csv). */
  common(code) { return this.D.common?.[code] ?? null; }

  /** Page text of a quest page (the message's string code), or null when the page has no text. */
  pageText(id, page) {
    const row = this.page(id, page);
    if (!row) return null;
    return this.str(id, row[1], { common: false });
  }

  /** Visible options of a page: [{option, text}] (template leftovers without text are dropped). */
  pageOptions(id, page) {
    const row = this.page(id, page);
    if (!row) return [];
    const out = [];
    for (const o of row[2] || []) {
      if (!o) continue;
      const t = this.str(id, o, { common: false });
      if (t != null && String(t).trim() !== '') out.push({ option: Number(o), text: t });
    }
    return out;
  }

  /** Page opened by an option (dialogs.json next[option]), or null (the dialog closes). */
  nextPage(id, option) {
    const service=nativeExchangePage(this,Number(id),Number(option));if(service!==undefined)return service;
    const n = this.tree(id)?.next?.[option];
    if (n != null && this.pageText(id, n) != null) return Number(n);
    return null;
  }

  /** NPC talk entry {name, fullName, greeting, comm, jobs:[[type, index, label]], lineFeed}. */
  npc(n) { return this.D.npcs?.[n] || null; }
  npcName(n) {
    const d = this.npc(n);
    if (d?.name) return d.name;
    const def = this.game?.data?.npcs?.npcs?.[n];
    return def?.name || `NPC ${n}`;
  }
  monsterName(m) { return this.game?.data?.monsters?.monsters?.[m]?.name || `Monster ${m}`; }
  mapName(i) { const r = this.game?.mapRow?.(i) || this.game?.data?.mapByIndex?.(i); return r?.Name ? String(r.Name).trim() : `Map ${i}`; }
  jobLabel(type) { return this.D.jobTypeLabels?.[type] ?? null; }

  /** Item name from the best source available (items system > boxes.json items > monsters.json itemNames). */
  itemName(i) {
    const g = this.game;
    try {
      const it = g?.items?.get?.(i) || g?.items?.def?.(i) || g?.itemDB?.get?.(i);
      if (it?.name) return String(it.name).trim();
      const n = g?.items?.name?.(i);
      if (n) return String(n).trim();
    } catch { /* optional */ }
    const b = this.B?.items?.[i];
    if (b?.[0]) return String(b[0]).trim();
    const m = g?.data?.monsters?.itemNames?.[i];
    if (m) return String(m).trim();
    for (const q of this._questItemNames()) { const v = q.get(Number(i)); if (v) return v; }
    return `Item ${i}`;
  }
  itemExists(i) {
    if (!Number.isSafeInteger(Number(i)) || Number(i) <= 0) return false;
    const g=this.game;
    if(g?.items?.db?.def)return !!g.items.db.def(i);
    if(g?.items?.def)return !!g.items.def(i);
    return !!(this.B?.items?.[i] || g?.data?.monsters?.itemNames?.[i]);
  }
  _questItemNames() {
    if (!this._qin) {
      const m = new Map();
      for (const q of Object.values(this.quests)) for (const o of q?.objectives || []) if (o.kind === 'collect') for (const t of o.targets || []) if (t.name) m.set(Number(t.id), t.name);
      this._qin = [m];
    }
    return this._qin;
  }

  /** Item stack size (0/1 = does not stack). */
  itemStack(i) {
    const g = this.game;
    try {
      const it = g?.items?.get?.(i) || g?.items?.def?.(i);
      if (it && it.stack != null) return Number(it.stack) || 0;
    } catch { /* optional */ }
    const b = this.B?.items?.[i];
    if (b) return Number(b[6]) || 0;
    const s = g?.loot?.stackMax?.(i);
    return s != null ? s : 0;
  }
  /** Item lifetime in seconds (0 = permanent). */
  itemPeriod(i) {
    const g = this.game;
    try { const it = g?.items?.get?.(i) || g?.items?.def?.(i); if (it && it.period != null) return Number(it.period) || 0; } catch { /* optional */ }
    const b = this.B?.items?.[i];
    return b ? Number(b[5]) || 0 : 0;
  }
  /** Item required level. */
  itemReqLv(i) {
    const g = this.game;
    try { const it = g?.items?.get?.(i) || g?.items?.def?.(i); if (it && it.reqLv != null) return Number(it.reqLv) || 0; } catch { /* optional */ }
    const b = this.B?.items?.[i];
    return b ? Number(b[3]) || 0 : 0;
  }
  /** Item footprint [w, h] cells. */
  itemSize(i) {
    const g = this.game;
    try { const it = g?.items?.get?.(i) || g?.items?.def?.(i); if (it && it.w) return [Number(it.w) || 1, Number(it.h) || 1]; } catch { /* optional */ }
    const b = this.B?.items?.[i];
    return b ? [Number(b[7]) || 1, Number(b[8]) || 1] : [1, 1];
  }
  /** Item job mask (bit c = class c allowed; 65535/32767 = all). */
  itemJobMask(i) {
    const b = this.B?.items?.[i];
    return b ? Number(b[4]) : 65535;
  }
}
