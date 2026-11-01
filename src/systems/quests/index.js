// Quests, NPC dialogs and boxes (docs/formats/quests.md, boxes.md; docs/QUESTS.md).
//   game.quests   quest state / rules API (engine.js) + the windows
//   game.boxes    box / package / random box / keyed chest / egg opening (boxes.js)
//   game.npcServices  the NPC dialog's service registry (services.js) other systems register their NPC jobs in
// Windows (original scripts through the uiwin platform): NPC dialog 'npc' (ui_dialog_renewal), quest window 'quest'
// (ui_quest, Q / btn_quest), tracker 'questassist' (ui_new_questassist), start / complete dialogs, level guide
// (qnotice alarm + info), commission board 'clientquest', box windows. NPC overhead marks + minimap icons (marks.js).
// A new character in Ardeca is offered the main story's first quest (9414 "Beginning of Great Journey") at once.
import { loadQuests, loadDialogs, QuestDB } from './data.js';
import { InventoryAdapter } from './inv.js';
import { QuestEngine } from './engine.js';
import { NpcServices } from './services.js';
import { NpcDialog } from './dialog.js';
import { QuestLog } from './log.js';
import { QuestTracker } from './tracker.js';
import { QuestStartDialog, QuestCompleteDialog, QuestNotice, QuestBoard } from './popups.js';
import { QuestMarks } from './marks.js';
import { BoxSystem } from './boxes.js';
import { renderMarkup, plainText } from './markup.js';
import { applyFont } from '../../ui/uiwin/fonts.js';
import { atlas } from '../../ui/atlas.js';
import { installServerQuests } from './server.js';
import { location as dungeonLocation } from '../dungeons/data.js';
import { visibleUnplacedQuest } from './unplaced-policy.js';

const ARDECA = 150;
const N = (cate, code) => ({ group: 'NORMAL', cate, code });
let SYS = null;

class QuestSystem {
  constructor(game) {
    this.game = game;
    this.text = { serviceUnavailable: 'Not available in current state.' };
    this._collectT = 0;
  }

  async init() {
    const g = this.game;
    const [Q, D] = await Promise.all([loadQuests(), loadDialogs()]);
    this.db = new QuestDB(g, Q, D);
    this.inv = new InventoryAdapter(g, this.db);
    this.engine = new QuestEngine(g, this.db, this.inv);
    this.engine.checkReset();
    installServerQuests(this);

    // NPC services: adopt a registry another system may have created first
    const prev = g.npcServices;
    this.services = new NpcServices(g);
    if (prev && prev !== this.services) this.services.adopt(prev);
    g.npcServices = this.services;
    this._registerCommonServices();

    this.boxes = new BoxSystem(this);
    this.dialog = new NpcDialog(this);
    this.log = new QuestLog(this);
    this.tracker = new QuestTracker(this);
    this.start = new QuestStartDialog(this);
    this.complete = new QuestCompleteDialog(this);
    this.notice = new QuestNotice(this);
    this.board = new QuestBoard(this);
    this.marks = new QuestMarks(this);

    if (g.uiwin) {
      this.dialog.register();
      this.log.register();
      this.tracker.register();
      this.start.register();
      this.complete.register();
      this.notice.register();
      this.board.register();
      this.boxes.registerWindows();
    }
    this.marks.install();
    this._api();
    this._wire();
    // client strings the quest code prints (loaded once; lookups are synchronous afterwards)
    g.uiwin?.strings?.need?.([N(1002, 23), N(1002, 24), N(1002, 25), N(1002, 26), N(1002, 27), N(1002, 36), N(1002, 14), N(100, 114), N(100, 115),
      N(100, 116), N(100, 141), N(100, 142), N(100, 143), N(100, 145), N(100, 147), N(100, 148), N(100, 149), N(100, 150), N(100, 151), N(80, 84), N(81, 89),
      N(81, 87), { group: 'SYSTEM', cate: 101, code: 252 }]).then(() => {
      const t = g.uiwin.strings.get({ group: 'SYSTEM', cate: 101, code: 252 });
      if (t) this.text.serviceUnavailable = t;
    }).catch(() => {});
    atlas.load().then(() => { for (const k of [30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 51, 52]) atlas.sprite('renewalquest', k); });
    return this;
  }

  // ------------------------------------------------------------------ public API
  _api() {
    const g = this.game, eng = this.engine, self = this;
    if (typeof g.locationOf !== 'function') g.locationOf = dungeonLocation;   // location.csv rows (travel data) for quest warps, see warp-location.js
    g.quests = {
      ready: Promise.resolve(true),
      db: this.db,
      engine: eng,
      get state() { return eng.st; },
      isActive: id => eng.isActive(id),
      isDone: id => eng.isDone(id),
      isComplete: id => eng.isComplete(id),
      check: id => eng.check(id),
      accept: (id, o) => eng.accept(id, o),
      complete: (id, o) => eng.claim(id, o),
      claim: (id, o) => eng.claim(id, o),
      abandon: id => eng.abandon(id),
      advance: (id, slot, n, o) => eng.advance(id, slot, n, o),
      track: (id, on) => eng.track(id, on),
      /** Progress hooks for other systems: notify('kill', {actor}) | ('skill', {index}) | ('fish', {count}) | ('clear', {map}) | ('talk', {npc}) */
      notify(kind, d = {}) {
        if (kind === 'kill') eng.onKill(d.actor, d.killer || g.player);
        else if (kind === 'skill') eng.onSkill(d.index ?? d.skill?.index);
        else if (kind === 'fish') eng.onFish(d.count || 1,d.item??d.itemIndex);
        else if (kind === 'clear') eng.onClearMap(d.map);
        else if (kind === 'talk') eng.talkTo(d.npc);
        else if (kind === 'collect') eng.recountCollect();
      },
      openDialog: npc => self.dialog.open(npc),
      offer: id => self.start.show(id),
      openLog: id => g.uiwin?.open('quest', id != null ? { quest: id } : undefined),
      /** GM / tools: set a quest state directly. */
      setDone(id, n = 1) { delete eng.st.active[id]; eng.st.done[id] = { n, t: Date.now() }; eng._changed(id); },
      reset(id) { delete eng.st.active[id]; delete eng.st.done[id]; eng.st.alarm = eng.st.alarm.filter(x => x !== Number(id)); eng._changed(id); },
      starterQuest: () => self.starterQuest(),
    };
    g.boxes = {
      get ready() { return self.boxes.ready; },
      isBox: i => self.boxes.isBox(i),
      info: i => self.boxes.info(i),
      open: inst => self.boxes.open(inst),
      showInfo: i => self.boxes.showInfo(i),
      roll: (i, rng) => { const b = self.boxes.info(i); return b ? self.boxes.roll(b, undefined, rng) : null; },
      grantStarter: () => self.boxes.grantStarter(),
    };
  }

  /**
   * NPC point-reset services no other system claims (stringtable_jobtype.txt 200/7,13,120: "[Skill Reset] Reset my
   * skills.", "[Stat Reset] Reset my stats.", "[Attribute Reset] Reset my attributes."). Each opens its Global box:
   * msgbox/ui_skillreset (skill and attribute) and msgbox/ui_statreset (skills/ui-skillwnd.js; rules src/game/point-resets.js,
   * the shared server server/world/point-resets.mjs).
   */
  _registerCommonServices() {
    const g = this.game, svc = this.services;
    svc.register('SKILLCLEAR', () => { g.skillsUI?.reset?.('skill'); return 'keep'; });
    svc.register('EXSKILLCLEAR', () => { g.skillsUI?.reset?.('attribute'); return 'keep'; });
    svc.register('STATCLEAR', () => { g.skillsUI?.statReset?.(); return 'keep'; });
  }

  // ------------------------------------------------------------------ events
  _wire() {
    const g = this.game, eng = this.engine, E = g.events;
    E.on('death', ({ actor, killer } = {}) => { try { eng.onKill(actor, killer); } catch (err) { console.error('[quests] kill', err); } });
    E.on('skill', ({ actor, skill } = {}) => { if (actor === g.player && skill) eng.onSkill(skill.index ?? skill.skillIndex ?? skill.id); });
    E.on('fish', (d = {}) => eng.onFish(Number(d.count) || 1,d.item??d.itemIndex));
    E.on('fishing', (d = {}) => { if (d.success || d.caught || d.item) eng.onFish(1,d.item??d.itemIndex); });
    E.on('dungeon:clear', (d = {}) => eng.onClearMap(d.map ?? d.index ?? g.world?.info?.index));
    const recount = () => { this._collectT = 0.05; };
    for (const ev of ['inventory', 'loot', 'item:add', 'itemuse']) E.on(ev, recount);
    E.on('quest:changed', () => this._questsChanged());
    // turn-in: the "quest_end" effect scene (effectscene 5:1122, quests.md §8-7) on the player
    E.on('quest:complete', () => { try { if (g.player) g.effects?.play?.(g.player, { cate: 5, id: 1122 }); } catch (err) { console.warn('[quests] quest_end effect', err); } });
    E.on('quest:ready', ({ id } = {}) => this._ready(id));
    E.on('levelup', ({ level } = {}) => { this.notice.sync(); this.boxes.levelUp?.(level); this._questsChanged(); });
    E.on('map', () => this._mapEntered());
    E.on('server:profile', () => { if (g.save.authority === 'server' && !g._loadingMap && !g.paused) this._afterEntry().catch(err => console.warn('[quests] starter offer', err)); });
    E.on('ui:open', (win) => { if (win?.name === 'npc') E.emit('npc:open', { npc: this.dialog.s?.npc }); });
  }

  _questsChanged() {
    this.tracker.sync();
    this.dialog.refresh();
    this.notice.sync();
    this.marks._dirty = true;
    clearTimeout(this._saveT);
    this._saveT = setTimeout(() => { try { this.game.persist?.(); } catch { /* ignore */ } }, 250);
  }

  /** A quest's objectives are met: without a turn-in NPC anywhere, it completes through the complete dialog. */
  _ready(id) {
    const q = this.db.quest(id);
    if (!q) return;
    if (q.turnIn?.npc == null && q.giver?.npc == null) this.complete.show(id);
  }

  _mapEntered() {
    const g = this.game;
    this._requestedUnplaced = new Set();
    this.marks.clear();
    this.marks._dirty = true;
    this.engine.recountCollect(null, true);
    this.tracker.sync();
    this.notice.sync();
    this._spawnUnplaced().catch(err => console.warn('[quests] unplaced NPCs', err));
    // after the loading screen: the new character's first main quest + starter boxes
    const wait = () => (g._loadingMap || g.paused ? setTimeout(wait, 200) : this._afterEntry().catch(err => console.warn('[quests] starter offer', err)));
    setTimeout(wait, 300);
  }

  /** The main story's first quest in Ardeca (lines.main.story: the chain whose start is given in Ardeca at level 1). */
  starterQuest() {
    const L = this.db.Q.lines?.main;
    for (const id of L?.story || []) {
      const q = this.db.quest(id);
      if (q && Number(q.giver?.map) === ARDECA && (q.level?.[0] ?? 1) <= 1) return q.id;
    }
    const c = (L?.chains || []).find(ch => (ch.maps || []).includes(ARDECA) && ch.level?.[0] <= 1);
    return c?.start ?? 9414;
  }

  async _afterEntry() {
    const g = this.game, eng = this.engine;
    const fl = eng.st.flags;
    if(g.save.authority==='server') {
      const id=this.starterQuest();
      if(Number(g.world?.info?.index)===ARDECA && !fl.autoStarted && !eng.isActive(id) && !eng.isDone(id) && eng.check(id).ok && this._serverStarterOffered !== g.save.id && !this._serverStarterOpening){
        this._serverStarterOpening=true;
        try { const win=await this.start.show(id); if(win) this._serverStarterOffered=g.save.id; }
        finally { this._serverStarterOpening=false; }
      }
      return;
    }
    const fresh = (Number(g.save.level) || 1) <= 1 && !(Number(g.save.exp) > 0) && !Object.keys(eng.st.done).length && !eng.activeIds().length;
    if (!fl.starterGiven && fresh) await this.boxes.grantStarter();
    if (!fl.autoStarted && Number(g.world?.info?.index) === ARDECA) {
      const id = this.starterQuest();
      if (id != null && !eng.isActive(id) && !eng.isDone(id) && eng.check(id).ok) {
        fl.autoStarted = Date.now();
        await this.start.show(id);
      } else if (eng.isActive(id) || eng.isDone(id)) fl.autoStarted = Date.now();
    }
  }

  /** Quest NPCs without a placement (event / Arcadia NPCs, quests.md §6.1 / §8-10) are spawned at their suggested spot. */
  async _spawnUnplaced() {
    const g = this.game, map = Number(g.world?.info?.index);
    if (!Number.isFinite(map)) return;
    const want = new Map();
    for (const q of Object.values(this.db.quests)) {
      if (!q || q.isGroup || q.require?.unavailable) continue;
      for (const who of [q.giver, q.turnIn]) {
        const relevant = visibleUnplacedQuest({quest:q,who,map,active:this.engine.isActive(q.id),eligible:map!==ARDECA&&this.engine.check(q.id).ok,requested:this._requestedUnplaced});
        if (relevant) want.set(Number(who.npc), who);
      }
    }
    // Only inferred actors are retired; original native NPCs, shops and gates
    // are untouched. Keep an open dialog's actor until the owner closes it.
    for (const npc of [...(g.npcs || [])]) if (npc.questSpawned && !want.has(Number(npc.npcIndex)) && this.dialog.s?.npc!==npc) {
      const i=g.npcs.indexOf(npc); if(i>=0)g.npcs.splice(i,1); npc.dispose?.();
    }
    if (!want.size) return;
    const present = new Set((g.npcs || []).map(n => Number(n.npcIndex)));
    const { NPC } = await import('../../actors/npc.js');
    const world = g.world;
    for (const [n, who] of want) {
      if (present.has(n)) continue;
      const def = g.data?.npcs?.npcs?.[n];
      if (!def) continue;
      const npc = new NPC(g, { index: n, ...def }, { npcIndex: n, x: Number(who.pos[0]), z: Number(who.pos[1]), dirDeg: Number(who.dir) || 0 });
      try { await npc.load(); } catch { npc.dispose?.(); continue; }
      if (g.world !== world) { npc.dispose(); return; }
      npc.questSpawned = true;
      g.npcs.push(npc);
    }
    this.marks._dirty = true;
  }

  // ------------------------------------------------------------------ text helpers for the windows
  get names() { return this.engine.names; }

  /** Render client markup into an element (links: NPC -> auto-find, monster -> its spawn, item -> tooltip). */
  renderText(parent, text, { lineHeight = 16, font = 2 } = {}) {
    return renderMarkup(parent, text, this.names, {
      lineHeight,
      applyFont: (el, idx, lh) => { applyFont(el, idx, 0); el.style.lineHeight = lh ? `${lh}px` : ''; },
      linkColor: '#00ff00',
      onLink: (link) => this.followLink(link),
      linkTitle: (link) => (link.kind === 'item' ? this.db.itemName(link.id) : null),
      sprite: (el, screen, index, w, h) => atlas.sprite(screen, index).then(s => { if (s) { el.style.backgroundImage = `url("${s.url}")`; el.style.backgroundSize = '100% 100%'; if (!w) el.style.width = `${s.w}px`; if (!h) el.style.height = `${s.h}px`; } }),
    }).map(el => { if (font !== 2) applyFont(el, font, lineHeight); return el; });
  }
  /** Replace a textbox's content with rendered markup and update its scroll range. */
  fillTextBox(tb, text) {
    if (!tb?.content) { tb?.setText?.(plainText(text, this.names)); return; }
    tb.clear();
    const lh = tb.lh || 16;
    this.renderText(tb.content, text, { lineHeight: lh, font: tb.font || 2 });
    this.relayout(tb);
  }
  relayout(tb) {
    tb._range?.();
    tb.setTop?.(0);
    requestAnimationFrame(() => { tb._range?.(); });
  }
  /** Rich message box (the platform's msgbox with client markup in its text). */
  async msgbox(text, opts = {}) {
    const W = this.game.uiwin;
    const onOpen = (win) => {
      const lbl = win?.find?.('lbl_text') || win?.find?.('lbl_msg');
      if (!lbl) return;
      W.off('open', onOpen);
      this.setRich(lbl, text);
    };
    W.on('open', onOpen);
    try { return await W.msgbox(plainText(text), opts); } finally { W.off('open', onOpen); }
  }
  /** Client markup on a label: colours (setRichText), <center> lines centred, line breaks kept (no wrapping). */
  setRich(lbl, text, { wrap = false } = {}) {
    const center = /<center>/i.test(text);
    lbl.setRichText(String(text ?? '').replace(/<center>/gi, '').replace(/<\/?font[^>]*>/gi, '').replace(/\\\r?\n/g, '\n'));
    if (lbl.txt) {
      if (center) { lbl.txt.style.justifyContent = 'center'; lbl.txt.style.textAlign = 'center'; }
      if (!wrap) { lbl.txt.classList.remove('uw-wrap'); lbl.txt.style.whiteSpace = 'pre'; }
    }
  }

  followLink(link) {
    const g = this.game;
    if (link.kind === 'npc') return this.navigateToNpc(link.id);
    if (link.kind === 'monster') {
      const here = (g.world?.spawns || []).filter(s => Number(s.monsterIndex) === Number(link.id));
      const p = g.player;
      if (here.length && p) {
        here.sort((a, b) => Math.hypot(a.x - p.x, a.z - p.z) - Math.hypot(b.x - p.x, b.z - p.z));
        const t = here[0];
        if (g.findAuto?.goTo) g.findAuto.goTo({ map: g.world.info.index, x: t.x, z: t.z, name: this.db.monsterName(link.id) });
        else g.controller?.moveTo?.(t.x, t.z);
        return;
      }
      const S = g.data?.monsters?.spawns || {};
      for (const [map, m] of Object.entries(S)) {
        const r = (m.rows || []).find(row => Number(row[0]) === Number(link.id));
        if (r && g.findAuto?.goTo) { g.findAuto.goTo({ map: Number(map), x: Number(r[2]) + 0.5, z: Number(r[3]) + 0.5, name: this.db.monsterName(link.id) }); return; }
      }
      return;
    }
    if (link.kind === 'item') {
      const t = g.items?.tooltip?.(link.id);
      if (t && g.uiwin?.tooltips?.show) { const r = globalThis.event; g.uiwin.tooltips.show(t, r?.clientX ?? 400, r?.clientY ?? 300); }
    }
  }
  async navigateToNpc(npcIndex, map = null) {
    const g = this.game;
    if (npcIndex == null) return;
    // Explicit quest navigation may reveal one inferred quest actor without
    // resurrecting the whole seasonal ring. No source placement is changed.
    if (Number(g.world?.info?.index)===ARDECA) {
      (this._requestedUnplaced ||= new Set()).add(Number(npcIndex));
      await this._spawnUnplaced();
    }
    if (g.findAuto?.goToNpc?.(Number(npcIndex))) return;
    const npc = (g.npcs || []).find(n => Number(n.npcIndex) === Number(npcIndex));
    if (npc) {
      const ip = npc.interactPoint || npc;
      if (g.findAuto?.goTo) g.findAuto.goTo({ map: g.world.info.index, x: ip.x, z: ip.z, npc: Number(npcIndex), name: npc.name });
      else g.controller?.moveTo?.(ip.x, ip.z);
    }
    else if (map != null) this.engine.say(`${this.db.npcName(npcIndex)} - ${this.db.mapName(map)}`, 'sys');
  }

  update(dt) {
    if (this._collectT > 0) { this._collectT -= dt; if (this._collectT <= 0) this.engine.recountCollect(); }
    this.marks.update(dt);
    this._resetT = (this._resetT || 0) + dt;
    if (this._resetT > 30) { this._resetT = 0; const before = this.engine.st.period.day; this.engine.checkReset(); if (before !== this.engine.st.period.day) this._questsChanged(); }
  }
}

export async function install(game) {
  SYS = new QuestSystem(game);
  game.questSystem = SYS;
  await SYS.init();
  return SYS;
}
export function update(dt) { SYS?.update(dt); }
export function dispose() { SYS?.boxes?.dispose(); SYS?.marks?.clear(); SYS = null; }
export { QuestSystem };
