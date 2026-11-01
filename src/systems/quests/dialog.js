// The NPC dialog: script/ui/game2/ui_dialog_renewal.txt ("dialog", 764 x 558: pan_dialog 382 wide + pan_quest_info).
//   title_label       NPC name
//   textbox           page text (client markup) followed by the menu / option rows. The textbox's own props drive the rows:
//                     lineheight 18, button_pos 22 0 (text x), buttonwidth 270, titles 0 = green ff00ff00, over/down = white.
//                     Each row carries its renewalquest row sprite (#30..#52: ! / ? / shop / talk icons, 294 x 16).
//   btn_init          "Go back"   -> the NPC's first page (greeting + menu)
//   btn_exit / btn_close          -> close
//   btn_info          "See more"  -> pan_quest_info (right half): "Quest Details" = journal of the quest on screen
// Quest pages follow dialogs.json (docs/formats/quests.md §3.5 / §8-4): the entry page by quest state, options open
// next[option] or close the branch: offer accept -> accept, complete claim/choice -> claim.
import { atlas } from '../../ui/atlas.js';
import { applyFont } from '../../ui/uiwin/fonts.js';
import { renderMarkup, fillPlaceholders, plainText } from './markup.js';
import { questLevelTag, questLevelRequirement } from './levels.js';
import { purchaseInfo, purchasesDone, purchasePage, purchaseFlag } from './vehicle-purchase.js';
import { NATIVE_TICKET_BINDINGS } from './native-ticket-issuance.js';
import {nativeExchangeMenu,ARGATE_RECIPES,OBLIVION_GROUPS} from './native-exchange-menus.js';
import {stoneObjective} from './native-earned-objectives.js';

const QUEST_JOBS = new Set([1, 57, 106, 114]);       // QUEST, DAILY_QUEST_STD, QUEST_MAIN, MISSION_TITLE
const OFFICE_JOBS = new Set([18, 54]);               // REQUEST_QUEST, DAILY_REQUEST_QUEST (commission boards)
const MISSION_JOB = 114;
const JOB_BORROW = { 102: 0, 35: 168, 45: 19 };      // job type -> the jobtype string it borrows (no line of its own)
const ROW = { availRed: 30, availYellow: 31, availBlue: 51, progress: 32, doneRed: 33, doneYellow: 34, doneBlue: 52, shop: 35, plain: 36, talk: 37, bubble: 38, mission: 39, missionQ: 40 };
const REPEAT_CATS = new Set(['daily', 'repeat', 'weekday', 'weekly', 'ticket', 'request', 'wanted']);
const GREEN = '#00ff00', WHITE = '#ffffff';

export class NpcDialog {
  constructor(sys) {
    this.sys = sys;
    this.game = sys.game;
    this.win = null;
    this.s = null;    // { npc, n, view, quest, page, entry, branch, stack }
  }
  get db() { return this.sys.db; }
  get eng() { return this.sys.engine; }

  register() {
    const self = this;
    this.game.uiwin.registerWindow('npc', {
      script: 'game2/ui_dialog_renewal.txt',
      escClose: true,
      create(win) { self._create(win); },
      onOpen(win, npc) { self._open(npc); },
      onClose() { self._closed(); },
    });
  }

  _create(win) {
    this.win = win;
    const tb = win.control('textbox');
    this.tb = tb;
    const p = tb.spec?.props || {};
    this.lh = Number(p.lineheight?.[0]) || 18;
    this.btnX = Number(p.button_pos?.[0]) || 22;
    this.btnW = Number(p.buttonwidth?.[0]) || 270;
    this.rowColors = { none: tb.titles?.['0']?.color || tb.titles?.none?.color, over: tb.titles?.over?.color };
    win.control('btn_init').onClick(() => this.home());
    win.control('btn_info').onClick(() => this.toggleInfo());
    win.control('btn_info').hide();
    win.control('pan_quest_info').hide();
  }

  // ------------------------------------------------------------------ open / close
  _open(npc) {
    const n = Number(npc?.npcIndex ?? npc?.index ?? npc?.def?.index);
    this.s = { npc, n, view: 'menu', stack: [] };
    try { this.game.audio?.npcGreeting?.(n, npc); } catch { /* optional */ }
    try { npc?.faceTowards?.(this.game.player?.x, this.game.player?.z); } catch { /* optional */ }
    this.game.events?.emit?.('npc:talk', { npc, npcIndex: n });
    this.home();
  }
  _closed() {
    const s = this.s;
    this.s = null;
    this.win?.control('pan_quest_info').hide();
    if (s) this.game.events?.emit?.('npc:close', { npc: s.npc, npcIndex: s.n });
  }
  close() { this.game.uiwin.close('npc'); }

  /** Open the dialog of an NPC actor (also game.windows.openNpc(npc)). */
  open(npc) { return this.game.uiwin.open('npc', npc); }

  // ------------------------------------------------------------------ first page: greeting + menu
  home() {
    const previous = this.s;
    if (!previous) return;
    // Navigation invalidates replies still waiting on a previous quest.
    const s = this.s = { npc: previous.npc, n: previous.n, view: 'menu', stack: [] };
    const d = this.db.npc(s.n);
    this.win.control('title_label').setText(d?.name || this.db.npcName(s.n));
    this.win.control('btn_info').hide();
    this.win.control('pan_quest_info').hide();
    this.win.control('btn_init').setEnabled(false);
    const entries = this.menuEntries(s.n);
    this._render(d?.greeting || '', entries.map(e => ({ ...e, onClick: () => this._menuClick(e) })), { lineFeeds: d?.lineFeed || [] });
  }

  /** The NPC menu: its jobs in npc.csv order (quest jobs by state), plus the quests it completes / is talked to for. */
  menuEntries(n) {
    const db = this.db, eng = this.eng;
    const d = db.npc(n);
    const jobs = d?.jobs || (this.game.data?.npcs?.npcs?.[n]?.jobs || []).map(j => [j[0], j[1], db.jobLabel(j[0]) || '']);
    const out = [];
    const extraServices=this.sys.services?.extraEntries?.(n)||[];
    const seen = new Set();
    const questEntry = (id, jobType, label) => {
      const q = db.quest(id);
      if (!q || seen.has(Number(id))) return;
      const tree = db.tree(id);
      if (eng.isTalkOnly(q) && (!eng.isActive(id)||nativeExchangeMenu(db,id)||[23,24].includes(id))) {
        // a talk tree (side lines, guides, legacy exchange menus): no quest state, never enters the log
        const c = eng.check(id);
        if (!c.list && c.reason !== 'low') return;
        let entryPage = [q.flow?.offer, q.flow?.entry, ...(tree?.entries || [])].find(p => p != null && db.pageText(id, p) != null);
        // a scripted vehicle purchase (Sergio, "Purchase Swift Box") opens on the page of the NEXT purchase: its price rises every time
        const sale = purchaseInfo(db, id);
        if (sale) entryPage = purchasePage(sale, purchasesDone(eng.st.flags, id)) ?? entryPage;
        if (entryPage != null) { seen.add(Number(id)); out.push({ kind: 'tree', id: Number(id), page: entryPage, label: q.title || label || '', row: ROW.talk }); }
        return;
      }
      const st = eng.stateAt(id, n);
      if (!st) return;
      if ((st === 'active' || st === 'complete') && !this._involved(q, n)) return;
      seen.add(Number(id));
      out.push({ kind: 'quest', id: Number(id), state: st, jobType, label: `${questLevelTag(q, this.sys.db.Q)} ${q.title || label || `Quest ${id}`}`, row: this._rowFor(q, st, jobType) });
    };
    for (const [type, index, label] of jobs) {
      if (QUEST_JOBS.has(Number(type))) questEntry(Number(index), Number(type), label);
      else if (OFFICE_JOBS.has(Number(type))) out.push({ kind: 'board', jobType: Number(type), jobIndex: Number(index), label: label || db.jobLabel(type) || '', row: ROW.bubble });
      else {
        const extra=extraServices.find(e=>Number(e.jobType)===Number(type)&&Number(e.jobIndex)===Number(index));
        const role = extra?.role || this.sys.services.roleOf(Number(type));
        let text = this._serviceLabel(label, type, index) || extra?.label;
        // job types without their own stringtable_jobtype line borrow the closest one (MULTISHOP -> the [Shop] line,
        // EXCHANGE -> [Exchange], TROOP_DUNGEON -> [Mission]); dungeon script NPCs use their script label
        if (!String(text || '').trim() && JOB_BORROW[Number(type)] != null) text = this._serviceLabel(null, JOB_BORROW[Number(type)], index);
        if (!String(text || '').trim() && (Number(type) === 31 || Number(type) === 80)) text = this.game.dungeons?.director?.scriptNpc?.(n)?.label || '';
        // jobs with no menu line at all (GUARD 12, TERRITORY_MANAGE 118, ...) are not listed by the client: a blank
        // row that does nothing is not shown
        if (!String(text || '').trim()) continue;
        out.push({ kind: 'service', jobType: Number(type), jobIndex: Number(index), role, label: text, row: this.sys.services.isShop(Number(type)) ? ROW.shop : ROW.bubble });
      }
    }
    // shared-play service lines a system provides for this NPC (NpcServices.provide), e.g. the Zuto registration
    for (const e of extraServices) {
      if(jobs.some(([type,index])=>Number(type)===Number(e.jobType)&&Number(index)===Number(e.jobIndex)))continue;
      out.push({ kind: 'service', jobType: Number.isInteger(e.jobType)?e.jobType:-1, jobIndex: Number(e.jobIndex) || 0, role: String(e.role).toUpperCase(), label: e.label, row: ROW.bubble });
    }
    // quests this NPC completes, is the talk target of, or gives without listing them (unplaced event NPCs)
    for (const id of eng.activeIds()) if (!seen.has(id)) { const q = db.quest(id); if (q && this._involved(q, n)) questEntry(id, 1, q.title); }
    // (quests this NPC lists on a request board, JobType 18 / 54, are taken through the board window only)
    const onBoard = id => (db.quest(id)?.listedBy || []).some(l => Number(l[0]) === n && OFFICE_JOBS.has(Number(l[1])));
    for (const id of db.byGiver.get(n) || []) if (!seen.has(id) && !onBoard(id) && eng.stateAt(id, n) === 'available' && db.quest(id)?.offered) questEntry(id, 1, db.quest(id)?.title);
    return out;
  }
  _serviceLabel(label, type, index) {
    let t = label || this.db.jobLabel(type) || '';
    // Exchange-store %s names its currency, not a map. Resolve the NPC/job pair.
    if (!t || /%s/.test(t)) t = this.game.shops?.jobLabel?.(this.s?.n, type, index) || t;
    if (/%s/.test(t)) { const m = this.db.mapName(index); t = t.replace(/%s/g, m); }
    return t;
  }
  /** Is NPC n the giver, turn-in or a talk target of quest q? */
  _involved(q, n) {
    if (Number(q.turnIn?.npc) === n || (q.turnIn?.alt || []).map(Number).includes(n)) return true;
    if (Number(q.giver?.npc) === n || (q.giver?.alt || []).map(Number).includes(n)) return true;
    for (const o of q.objectives || []) {
      if(stoneObjective(q,o)?.includes(n))return true;
      if (o.kind === 'talk' && (o.targets || []).some(t => Number(t.id) === n) && !this.eng.objectiveDone(q, o)) return true;
      if (o.weak && Number(o.navNpc) === n && !this.eng.objectiveDone(q, o)) return true;
    }
    return false;
  }
  _isTurnIn(q, n) { return Number(q.turnIn?.npc) === n || (q.turnIn?.alt || []).map(Number).includes(n); }
  _isGiver(q, n) { return Number(q.giver?.npc) === n || (q.giver?.alt || []).map(Number).includes(n); }
  /** Row sprite of a quest line: colour = main (red) / repeatable (blue) / normal (yellow). */
  _rowFor(q, state, jobType) {
    const mission = Number(jobType) === MISSION_JOB;
    const colour = q.cat === 'main' ? 'Red' : REPEAT_CATS.has(q.cat) || q.repeat ? 'Blue' : 'Yellow';
    if (state === 'available' || state === 'low') return mission ? ROW.mission : ROW[`avail${colour}`];
    if (state === 'complete') return mission ? ROW.missionQ : ROW[`done${colour}`];
    if (state === 'repeatDone' || state === 'locked') return ROW.plain;
    return mission ? ROW.missionQ : ROW.progress;
  }

  _menuClick(e) {
    const s = this.s;
    if (!s) return;
    if (e.kind === 'quest') return this.openQuest(e.id);
    if (e.kind === 'tree') { s.view = 'tree'; s.quest = e.id; s.entry = e.page; s.branch = null; return this.showPage(e.page); }
    if (e.kind === 'board') { this.sys.board?.open(s.npc, e); return; }
    const r = this.sys.services.dispatch(s.npc, e);
    if (r === true) this.close();
    else if (!r) this._say(this.sys.text.serviceUnavailable);
  }

  // ------------------------------------------------------------------ quest pages
  /** Open a quest's dialog at this NPC, at the page its state selects. */
  async openQuest(id) {
    const previous = this.s, db = this.db, eng = this.eng;
    if (!previous) return;
    const q = db.quest(id);
    if (!q) return;
    // A fresh state owns this transition. The old page cannot claim the new
    // quest while its authoritative talk response is still in flight.
    const s = this.s = { npc: previous.npc, n: previous.n, view: 'quest', quest: Number(id), mode: 'loading', page: null, entry: null, branch: null, stack: [], pending: true };
    const n = s.n;
    try {
    if (eng.isActive(id)) await eng.talkTo(n, id);     // server validates the NPC before progressing talk
    if(this.s !== s) return;
    let page = null, mode = 'other';
    if (eng.isActive(id)) {
      const done = eng.isComplete(id);
      if (done && this._isTurnIn(q, n)) { page = this._completePage(q); mode = 'complete'; }
      else if (!done && this._talkTargetPage(q, n) != null) { page = this._talkTargetPage(q, n); mode = 'talk'; }
      else if (this._isTurnIn(q, n) && !this._isGiver(q, n)) page = q.flow?.progress ?? q.flow?.progressAtGiver;
      else page = q.flow?.progressAtGiver ?? q.flow?.progress;
      if (mode === 'complete' && (page == null || db.pageText(id, page) == null)) {
        // no completion page in the tree: turn it in directly
        const r = await eng.claim(id, { npc: n });
        if (r.ok && this.s === s) await this._afterClaim(q);
        return;
      }
    } else {
      const st = eng.stateAt(id, n);
      if (st === 'available') { page = eng.repeatPage(q) ?? q.flow?.offer; mode = 'offer'; }
      else if (st === 'low') { page = q.flow?.lowLevel; mode = 'low'; }
      else if (st === 'repeatDone') { eng.message(1030, q); return; }
      else if (st === 'locked') { const c = eng.check(id); if (c.code) eng.message(c.code, q); return; }
      if (mode === 'offer' && (page == null || db.pageText(id, page) == null)) {
        // no offer page: accept directly (the NPC hands it over)
        const r = await eng.acceptOffered(id, { npc: n });   // only where this NPC natively offers it (native-offer.js)
        if (r.ok && this.s === s) this.close();
        return;
      }
    }
    if (page == null || db.pageText(id, page) == null) {
      // nothing to read: show the journal line of the quest
      page = null;
    }
    s.mode = mode;
    s.entry = page;
    if (page == null) { this._renderQuestFallback(q); return; }
    this.showPage(page);
    } finally { s.pending = false; }
  }
  _completePage(q) {
    const f = q.flow || {};
    if(q.nativeChoicePages)return q.nativeChoicePages[this.eng.classIndex]??null;
    if (q.require?.completeAny) {
      const slot = this.eng.completedSlot(q.id);
      const p = (f.complete ?? 30000) + 1000 * slot;
      if (this.db.pageText(q.id, p) != null) return p;
    }
    return f.complete ?? 30000;
  }
  _talkTargetPage(q, n) {
    if((q.objectives||[]).some(o=>stoneObjective(q,o)?.includes(n))){
      const page=q.id===8072?21000:21000+(n-5907)*1000;
      if(this.db.pageText(q.id,page)!=null)return page;
    }
    for (const o of q.objectives || []) {
      if (o.kind !== 'talk' || !(o.targets || []).some(t => Number(t.id) === n)) continue;
      const p = o.talkMsg ?? q.flow?.talk?.[o.slot];
      if (p != null && this.db.pageText(q.id, p) != null && !this._isTurnIn(q, n)) return p;
    }
    return null;
  }

  /** Show a page of the current quest tree. */
  showPage(page) {
    const s = this.s, db = this.db;
    if (!s) return;
    const id = s.quest;
    const q = db.quest(id) || { id, objectives: [] };
    s.page = Number(page);
    this.win.control('title_label').setText(db.npc(s.n)?.name || db.npcName(s.n));
    this.win.control('btn_init').setEnabled(true);
    const text = fillPlaceholders(db.pageText(id, page) ?? '', this.eng.ctx(q));
    const opts = db.pageOptions(id, page).map(o => ({ kind: 'option', option: o.option, label: fillPlaceholders(o.text, this.eng.ctx(q)), row: ROW.plain, onClick: () => { if (this.s === s && s.page === Number(page)) return this._option(o.option); } }));
    const isQuest = s.view === 'quest' && !!db.quest(id);
    this.win.control('btn_info').setVisible(isQuest);
    if (isQuest && this.win.control('pan_quest_info').isVisible()) this._fillInfo(q);
    this._render(text, opts);
  }

  /** "Purchase." / "Maybe next time." / "That's okay." of a scripted vehicle-purchase dialog. */
  async _purchaseOption(sale, option) {
    const s = this.s, eng = this.eng;
    const tier = sale.tiers.find(t => t.page === s.page);
    if (!tier || Number(option) !== tier.purchaseOption) return this.close();   // decline, or the sold-out page
    let r;
    try { r = await eng.purchase(s.quest, { npc: s.n, option }); }
    catch (err) { eng.say(String(err?.message || err), 'err'); return this.close(); }
    if (!r?.ok) return this.close();   // the engine / host named the reason
    const flags = eng.st.flags, count = Number(r.purchase?.count) || purchasesDone(flags, s.quest) + 1;
    flags[purchaseFlag(s.quest)] = Math.max(count, purchasesDone(flags, s.quest));   // the host snapshot carries the same number
    const page = purchasePage(sale, purchasesDone(flags, s.quest));
    if (page == null) return this.close();
    s.entry = page;
    return this.showPage(page);   // the next price (or "I don't have any left in stock.")
  }

  async _option(option) {
    const s = this.s, db = this.db, eng = this.eng;
    if (!s || s.pending) return;
    const choiceQuest=s.view==='quest'&&s.mode==='complete'?db.quest(s.quest):null;
    if(choiceQuest?.nativeChoicePages&&choiceQuest.rewardVariants.list.some(v=>v.option===option&&v.classIndex===eng.classIndex)){
      s.pending=true;try{const r=await eng.claim(s.quest,{npc:s.n,option});if(r.ok&&this.s===s)this._afterClaim(choiceQuest);}finally{s.pending=false;}return;
    }
    const exchange=s.view==='tree'?nativeExchangeMenu(db,s.quest):null;
    if(exchange&&(exchange==='argate'?ARGATE_RECIPES:OBLIVION_GROUPS)[option]){
      s.pending=true;
      try{const result=await eng.exchange(s.quest,{npc:s.n,option});if(this.s!==s)return;if(result.page!=null)return this.showPage(result.page);return this.close();}
      catch(error){eng.say(String(error?.message||error),'err');return this.close();}
      finally{s.pending=false;}
    }
    const sale = s.view === 'tree' ? purchaseInfo(db, s.quest) : null;
    if (sale) return this._purchaseOption(sale, option);
    if (s.branch == null && s.page === s.entry) s.branch = option;
    const next = db.nextPage(s.quest, option);
    const offered = s.view === 'quest' && s.mode === 'offer' ? db.quest(s.quest) : null;
    if (offered && s.page === s.entry) {
      const options = db.pageOptions(s.quest, s.page).map(o => o.option);
      // An authored accepted leaf acknowledges acceptance; merely navigating to it
      // never calls the engine. Intermediate/decline pages remain ordinary traversal.
      const acceptedLeaf = option === offered.flow?.accept && next != null && next === offered.flow?.accepted && db.pageOptions(s.quest, next).length === 0;
      // Recovered issuance menus encode the next round as next[option]. The current
      // native repeat reward, not that navigation link, owns this click's transaction.
      const issuance = NATIVE_TICKET_BINDINGS.some(b => b.quest === offered.id && b.file === offered.recoveredFrom) && offered.rewardVariants?.mode === 'repeat' && eng._instant(offered) && eng.repeatPage(offered) === s.page && options.length === 1;
      if (options.includes(option) && (acceptedLeaf || issuance)) return this._acceptOffer(offered, acceptedLeaf ? next : null);
    }
    if (next != null) { s.stack.push(s.page); return this.showPage(next); }
    // A talk-tree branch whose end is a host-owned service (registered by that system in game.npcTreeActions as 'quest:option',
    // e.g. 1641:10001 "[Frontier Dungeon] Move." -> src/systems/network/travel.js). The host decides; no quest state changes here.
    const hostAction = s.view === 'tree' ? this.game.npcTreeActions?.get?.(`${s.quest}:${option}`) : null;
    if (hostAction) { const npc = s.npc, n = s.n; this.close(); return hostAction(npc, n); }
    if(s.view==='tree'&&[23,24].includes(s.quest)&&option===10001&&eng.isTalkOnly(db.quest(s.quest))){const n=s.n;this.close();return this.game.sharedTravel?.hideoutMove?.(n);}
    // the branch ends: apply it
    const q = db.quest(s.quest);
    if (!q || s.view !== 'quest') return this.close();
    const f = q.flow || {};
    const entryOpts = db.pageOptions(q.id, s.entry).map(o => o.option);
    const first = entryOpts[0], last = entryOpts.length > 1 ? entryOpts[entryOpts.length - 1] : null;
    if (s.mode === 'offer') {
      const acceptOpt = f.accept ?? first;
      const declineOpt = f.decline ?? last;
      if (s.branch === declineOpt && s.branch !== acceptOpt) return this.close();
      return this._acceptOffer(q);
    }
    if (s.mode === 'complete') {
      const claimOpts = f.completeOptions?.length ? f.completeOptions : entryOpts;
      if (claimOpts.length && !claimOpts.includes(s.branch) && s.branch !== f.claim) return this.close();
      const choice = q.rewardVariants?.mode === 'choice' ? s.branch : null;
      s.pending = true;
      try {
        const r = await eng.claim(q.id, { npc: s.n, option: choice ?? s.branch });
        if (r.ok && this.s === s && s.quest === q.id) this._afterClaim(q);
      } finally { s.pending = false; }
      return;
    }
    this.close();
  }

  async _acceptOffer(q, acceptedPage = null) {
    const s = this.s, eng = this.eng;
    if (!s || s.pending) return;
    const npc = s.n, entry = s.entry;
    s.pending = true;
    try {
      const r = await eng.acceptOffered(q.id, { npc: s.n, option: s.branch });
      if (this.s !== s || s.quest !== q.id || s.n !== npc || s.entry !== entry) return; // A late reply must not replace another NPC dialog.
      const page = r.page ?? (r.ok ? acceptedPage : null);
      if (page != null) { s.mode = 'other'; s.entry = page; return this.showPage(page); }
      if (r.ok && eng._instant(q)) this._afterClaim(q, true);
      else this.close();
    } finally { s.pending = false; }
  }

  /** After a turn-in: the chain's next quest when this NPC gives it, else close. */
  _afterClaim(q, stay = false) {
    const s = this.s;
    if (!s) return;
    const next = q.next != null ? this.db.quest(q.next) : null;
    if (next && this._isGiver(next, s.n) && this.eng.stateAt(next.id, s.n) === 'available') return this.openQuest(next.id);
    if (stay) return this.home();
    this.close();
  }

  _renderQuestFallback(q) {
    const s = this.s;
    s.page = null;
    this.win.control('btn_init').setEnabled(true);
    this.win.control('btn_info').show();
    const text = this.db.str(q.id, 12, { common: false }) || q.title || '';
    this._render(fillPlaceholders(text, this.eng.ctx(q)), []);
  }

  // ------------------------------------------------------------------ quest details (right panel)
  toggleInfo() {
    const pan = this.win.control('pan_quest_info');
    if (pan.isVisible()) { pan.hide(); return; }
    const q = this.db.quest(this.s?.quest);
    if (!q) return;
    this._fillInfo(q);
    pan.show();
  }
  _fillInfo(q) {
    const tb = this.win.control('textbox_questinfo');
    const lines = [];
    lines.push(`<font=4><color=FFCA40>${questLevelTag(q, this.sys.db.Q)} ${q.title || ''}</color></font>`);
    lines.push(questLevelRequirement(q, this.sys.db.Q));
    const s = this.eng.slots(q.id);
    if (s) for (const o of q.objectives || []) lines.push(`${this.eng.objectiveDone(q, o) ? '<color=7f7f7f>' : '<color=ffffff>'}${this.eng.objectiveText(q, o)}</color>`);
    lines.push('');
    const j = this.db.str(q.id, 12, { common: false });
    if (j) lines.push(fillPlaceholders(j, this.eng.ctx(q)));
    const diary = this.db.str(q.id, 13, { common: false });
    if (diary) { lines.push(''); lines.push(diary); }
    this.sys.fillTextBox(tb, lines.join('\n'));
  }

  // ------------------------------------------------------------------ rendering
  /**
   * Fill the textbox: markup text, a blank line, then the rows. rows: [{label, row (sprite index), onClick}]
   */
  _render(text, rows, { lineFeeds = [] } = {}) {
    const tb = this.tb;
    if (!tb?.content) return;
    tb.clear();
    const c = tb.content;
    const lh = this.lh;
    if (text) this.sys.renderText(c, text, { lineHeight: lh, font: tb.font });
    if (rows.length) { const sp = document.createElement('div'); sp.style.height = `${lh}px`; c.appendChild(sp); }
    for (const r of rows) {
      const lf = lineFeeds.find(x => Number(x[0]) === r.jobType && Number(x[1]) === (r.jobIndex ?? r.id));
      if (lf && Number(lf[2]) > 0) for (let i = 0; i < Math.min(3, Number(lf[2])); i++) { const sp = document.createElement('div'); sp.style.height = `${lh}px`; c.appendChild(sp); }
      c.appendChild(this._row(r));
    }
    this.sys.relayout(tb);
  }
  _row(r) {
    const lh = this.lh;
    const row = document.createElement('div');
    row.className = 'qd-row';
    Object.assign(row.style, { position: 'relative', height: `${lh}px`, pointerEvents: 'auto', cursor: 'pointer', whiteSpace: 'nowrap' });
    const bg = document.createElement('div');
    Object.assign(bg.style, { position: 'absolute', left: '0', top: `${Math.round((lh - 16) / 2)}px`, width: '294px', height: '16px', backgroundRepeat: 'no-repeat', backgroundSize: '294px 16px', pointerEvents: 'none' });
    if (r.row != null) {
      const sp = atlas.spriteNow('renewalquest', r.row);
      if (sp) bg.style.backgroundImage = `url("${sp.url}")`;
      else atlas.sprite('renewalquest', r.row).then(x => { if (x) bg.style.backgroundImage = `url("${x.url}")`; });
    }
    row.appendChild(bg);
    const t = document.createElement('span');
    Object.assign(t.style, { position: 'absolute', left: `${this.btnX}px`, top: '0', width: `${this.btnW}px`, lineHeight: `${lh}px`, overflow: 'hidden', textOverflow: 'ellipsis', pointerEvents: 'none' });
    applyFont(t, this.tb?.font || 2, lh);
    const col = this._argb(this.rowColors.none) || GREEN, over = this._argb(this.rowColors.over) || WHITE;
    t.style.color = col;
    t.textContent = plainText(r.label, this.sys.engine.names);
    row.appendChild(t);
    row.addEventListener('pointerenter', () => { t.style.color = over; });
    row.addEventListener('pointerleave', () => { t.style.color = col; });
    row.addEventListener('pointerdown', e => { if (e.button === 0) e.stopPropagation(); });
    row.addEventListener('click', e => { e.stopPropagation(); this.game.uiwin?.sound?.(0); r.onClick?.(); });
    return row;
  }
  _argb(c) {
    if (!c) return null;
    if (Array.isArray(c)) return `rgba(${c[1]},${c[2]},${c[3]},${(c[0] / 255).toFixed(3)})`;
    const h = String(c).replace(/^0x/i, '').replace(/^#/, '');
    if (h.length === 8) return `#${h.slice(2)}`;
    if (h.length === 6) return `#${h}`;
    return null;
  }
  _say(t) { if (t) this.eng.say(plainText(t, this.eng.names), 'sys'); }

  /** Refresh the menu after quest changes while the dialog shows it. */
  refresh() { if (this.s?.view === 'menu' && this.win?.isOpen) this.home(); }
}
