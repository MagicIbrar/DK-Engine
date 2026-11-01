// Smaller quest windows:
//   QuestStartDialog   script/ui/game2/ui_quest_start_dialog.txt   (297 x 365, renewalquest#29): a quest offered without an
//                      NPC (the main story start of a new character). textbox = offer page, btn_start "Accept".
//   QuestCompleteDialog script/ui/game2/ui_quest_complet_dialog.txt: a quest that completes without a turn-in NPC.
//                      textbox = completion page, btn_complet "Completed" -> claim.
//   QuestNotice        script/ui/game2/ui_qnoticealarm.txt (30 x 30 alarm button, blinks when new guide entries appear)
//                      + ui_qnoticeinfo.txt "Quest Alert" (the level guide of script/questnotice.csv: noticectrl rows
//                      with result / subject / NPC - location, lbl_empty "No new quests are available to accept.").
//   QuestBoard         script/ui/game2/quest/ui_clientquestlist.txt "Quest Commission": the request boards
//                      (JobType 18 / 54) listing their quests (Status / Level / Quest Name).
import { fillPlaceholders, plainText } from './markup.js';
import { questDisplayLevel, questLevelTag, questLevelRequirement } from './levels.js';

// ============================================================================================ start / complete
export class QuestStartDialog {
  constructor(sys) { this.sys = sys; this.game = sys.game; this.q = null; }
  register() {
    const self = this;
    this.game.uiwin.registerWindow('queststart', {
      script: 'game2/ui_quest_start_dialog.txt',
      create(win) {
        self.win = win;
        win.control('btn_start').onClick(() => self._accept());
      },
      onOpen(win, id) { self._fill(Number(id)); },
    });
  }
  /** Offer quest `id` in the start dialog. */
  show(id) { return this.game.uiwin.open('queststart', id); }
  _fill(id) {
    const db = this.sys.db, eng = this.sys.engine;
    const q = db.quest(id);
    this.q = q;
    if (!q) return;
    this.win.control('title_label').setText(`${questLevelTag(q, this.sys.db.Q)} ${q.title || ''}`);
    const page = eng.repeatPage(q) ?? q.flow?.offer ?? 10000;
    const text = db.pageText(id, page) ?? db.str(id, 12, { common: false }) ?? '';
    this.sys.fillTextBox(this.win.control('textbox'), fillPlaceholders(text, eng.ctx(q)));
    this.win.control('btn_start').setEnabled(eng.check(id).ok);
  }
  async _accept() {
    const q = this.q;
    if (!q) return;
    const r = await this.sys.engine.acceptOffered(q.id, { starter: true });   // the starter offer only (native-offer.js)
    if (r.ok || r.code) this.win.close('accept');
  }
}

export class QuestCompleteDialog {
  constructor(sys) { this.sys = sys; this.game = sys.game; this.q = null; }
  register() {
    const self = this;
    this.game.uiwin.registerWindow('questcomplete', {
      script: 'game2/ui_quest_complet_dialog.txt',
      create(win) {
        self.win = win;
        win.control('btn_complet').onClick(() => self._claim());
      },
      onOpen(win, id) { self._fill(Number(id)); },
    });
  }
  show(id) { return this.game.uiwin.open('questcomplete', id); }
  _fill(id) {
    const db = this.sys.db, eng = this.sys.engine;
    const q = db.quest(id);
    this.q = q;
    if (!q) return;
    this.win.control('title_label').setText(`${questLevelTag(q, this.sys.db.Q)} ${q.title || ''}`);
    const text = db.pageText(id, q.flow?.complete ?? 30000) ?? db.str(id, 400) ?? '';
    this.sys.fillTextBox(this.win.control('textbox'), fillPlaceholders(text, eng.ctx(q)));
  }
  async _claim() {
    const q = this.q;
    if (!q) return;
    const r = await this.sys.engine.claim(q.id, {});
    if (r.ok) this.win.close('claim');
  }
}

// ============================================================================================ level guide
export class QuestNotice {
  constructor(sys) { this.sys = sys; this.game = sys.game; this.rows = []; this.seen = new Set(); this.top = 0; }
  register() {
    const self = this;
    const W = this.game.uiwin;
    W.registerWindow('qnotice_alarm', {
      script: 'game2/ui_qnoticealarm.txt',
      hud: true, band: 'hud',
      // The Quest Alert button is the first slot of the HUD alarm grid under the clock (rect 10 60; the other alarm
      // scripts of that grid are 'position inverse inverse', i.e. absolute 1024x768 px). This script has no anchor, so the
      // generic "same relative place on larger screens" rule moved it off the grid (19,85 at 1920x1080, on top of the
      // Supply Machine alarm at 10 100). Keep it on its scripted rect like the rest of the grid.
      onOpen(win) { const [x, y] = win.spec.rect || []; if (Number.isFinite(x) && Number.isFinite(y)) win.setPosition(x, y, false); },
      create(win) { self.alarm = win; win.control('btn_alarm').onClick(() => { win.control('btn_alarm').setBlink(false); W.toggle('qnotice_info'); }); },
    });
    W.registerWindow('qnotice_info', {
      script: 'game2/ui_qnoticeinfo.txt',
      create(win) {
        self.info = win;
        win.control('scroll_notice').on('change', v => { self.top = v; self._fill(); });
        win.control('pan_back').on('wheel', (e, d) => { const s = win.control('scroll_notice'); s.setValue(s.getValue() + d, false); });
      },
      onOpen() { self.top = 0; self._fill(); self._markSeen(); },
    });
  }
  /** Level-guide entries for the current level: quests not taken or done yet. */
  entries() {
    const eng = this.sys.engine, lv = eng.level;
    return (this.sys.db.Q.notices || []).filter(n => lv >= n.show?.[0] && lv <= n.show?.[1] && !eng.isActive(n.quest) && !eng.isDone(n.quest) && eng.check(n.quest).list !== false);
  }
  /** Show the alarm button when the guide has entries; blink for new ones. */
  async sync() {
    const W = this.game.uiwin;
    const list = this.entries();
    if (!list.length) { if (W.isOpen('qnotice_alarm')) W.close('qnotice_alarm'); if (W.isOpen('qnotice_info')) this._fill(); return; }
    if (!W.isOpen('qnotice_alarm')) await W.open('qnotice_alarm');
    const fresh = list.some(n => !this.seen.has(n.quest));
    this.alarm?.control('btn_alarm').setBlink(fresh);
    if (W.isOpen('qnotice_info')) this._fill();
  }
  _tip(text) {
    const el = document.createElement('div');
    el.style.maxWidth = '300px';
    el.style.whiteSpace = 'normal';
    this.sys.renderText(el, text, { lineHeight: 15 });
    return el;
  }
  _markSeen() { for (const n of this.entries()) this.seen.add(n.quest); this.alarm?.control('btn_alarm').setBlink(false); }
  _fill() {
    const win = this.info;
    if (!win) return;
    for (const r of this.rows) r.remove?.();
    this.rows = [];
    const list = this.entries();
    win.control('lbl_empty').setVisible(!list.length);
    const tpl = win.find('noticectrl_0');
    if (!tpl) return;
    const H = 50, vis = 3;
    const scroll = win.control('scroll_notice');
    scroll.setRange?.(Math.max(0, list.length - vis), vis);
    this.top = Math.max(0, Math.min(this.top, Math.max(0, list.length - vis)));
    list.slice(this.top, this.top + vis).forEach((n, i) => {
      const row = tpl.cloneAs(`_r${i}`, { y: tpl.spec.rect[1] + i * H, visible: true });
      const q = this.sys.db.quest(n.quest);
      row.control(`noticectrl_0_result_label_r${i}`)?.setText(`Lv.${questDisplayLevel(q, this.sys.db.Q)}`);
      row.control(`noticectrl_0_subtitle_label_r${i}`)?.setText(q?.title || n.subject || '');
      const giver = q?.giver;
      const where = giver?.map != null ? this.sys.db.mapName(giver.map) : n.location || '';
      row.control(`noticectrl_0_npctitle_label_r${i}`)?.setText(`${giver?.npc != null ? this.sys.db.npcName(giver.npc) : n.npc || ''} - ${where}`);
      row.onClick(() => this.sys.navigateToNpc(giver?.npc, giver?.map));
      // the quest's guide text (quest string `noticeMsg` = 14, "Tip: ... / Quest Alarm ..."): 160 of the 161 guide
      // quests carry one, so it belongs to this window; shown as the row's tooltip (client markup)
      const tip = q?.noticeMsg != null ? this.sys.db.str(q.id, q.noticeMsg, { common: false }) : null;
      if (row.setTooltip) row.setTooltip(() => this._tip([questLevelRequirement(q, this.sys.db.Q), tip].filter(Boolean).join('\n')));
      this.rows.push(row);
    });
  }
}

// ============================================================================================ commission board
export class QuestBoard {
  constructor(sys) { this.sys = sys; this.game = sys.game; this.board = null; this.npc = null; this.items = []; }
  register() {
    const self = this;
    this.game.uiwin.registerWindow('clientquest', {
      script: 'game2/quest/ui_clientquestlist.txt',
      create(win) {
        self.win = win;
        const list = win.control('maillist');
        // the casebox has no icon / title / content rects (the client lays the columns out in code): put them under
        // the header labels lbl_state (x 9, w 20), lbl_level (x 45) and lbl_questname (x 85), in the 218 x 25 row
        if (list.tpl) {
          const P = { ...(list.tpl.spec.props || {}) };
          P.icon ||= ['11', '4', '27', '20'];
          P.title ||= ['45', '6', '80', '20'];
          P.content ||= ['85', '6', '218', '20'];
          list.tpl.spec = { ...list.tpl.spec, props: P };
        }
        list.on('select', (i, it) => self._pick(it));
        list.on('dblclick', (i, it) => self._pick(it));
      },
      onOpen() { self._fill(); },
    });
    this.game.events?.on?.('quest:changed', () => { if (this.win?.isOpen) this._fill(); });
  }
  /** Open the board of an NPC menu entry {jobType, jobIndex}. */
  open(npc, entry) {
    this.npc = npc;
    this.board = this.sys.db.Q.requestBoards?.boards?.[`${entry.jobType}:${entry.jobIndex}`] || { quests: [], count: 0 };
    return this.game.uiwin.open('clientquest');
  }
  _fill() {
    const eng = this.sys.engine, db = this.sys.db;
    const n = Number(this.npc?.npcIndex ?? this.npc?.index);
    const quests = (this.board?.quests || []).map(id => db.quest(id)).filter(Boolean);
    const avail = quests.filter(q => { const st = eng.stateAt(q.id, n); return st && st !== 'low'; });
    const cap = Number(this.board?.count) || avail.length;
    const shown = avail.slice(0, Math.max(cap, avail.filter(q => eng.isActive(q.id)).length));
    this.items = shown.map(q => {
      const st = eng.stateAt(q.id, n);
      // new_quest_npc #10 arrow = in progress, #12 check = ready / done today, #11 x = not available today, #13 blank = available
      const icon = st === 'complete' || st === 'repeatDone' ? 12 : st === 'active' ? 10 : st === 'available' ? 13 : 11;
      return { icon: { sprite: ['new_quest_npc', icon] }, title: String(questDisplayLevel(q, this.sys.db.Q)), content: q.title || '', read: st === 'repeatDone', data: q.id };
    });
    this.win.control('maillist').setItems(this.items);
  }
  _pick(it) {
    if (!it) return;
    const dlg = this.sys.dialog;
    if (!dlg.s) return;
    dlg.openQuest(it.data);
  }
}
