// The quest window: script/ui/game2/quest/ui_quest.txt ("quest", 690 x 538, renewalquest#1 art).
//   tab_quest_1 "Quest Progress" (x 9)   active quests by type ([Main] [General] [Repeat] [Daily] [Request] [Mission])
//   tab_quest_4 "Weekly Quest"   (x 90)  daily / weekly / weekday / repeatable quests (active + done this period)
//   tab_quest_2 "Quest Alarm"    (x 171) the quests registered in the Quest Alarm (tracker), max 10
//   tab_quest_3 "Quest Journal"  (x 252) completed quests
//   quest_tree   head / sub / finish / unknown / complete node titles of the script
//   pan_right    "Quest Details": lbl_subtitle (title), lbl_object (state, objectives, NPCs, area), textbox (journal +
//                story), btn_confirm "Confirm" (close), btn_cancel "Abandon" (msgbox 80:84 / 81:89).
// Double-click a quest (or its tracker "x") to register / unregister it in the Quest Alarm.
import { fillPlaceholders, plainText } from './markup.js';
import { questDisplayLevel, questLevelTag, questLevelRequirement } from './levels.js';

const TABS = [['tab_quest_1', 'progress'], ['tab_quest_4', 'weekly'], ['tab_quest_2', 'alarm'], ['tab_quest_3', 'journal']];
const T = (cate, code) => ({ group: 'NORMAL', cate, code });
const TYPE_TAG = { main: T(100, 145), normal: T(100, 114), growth: T(100, 114), event: T(100, 114), wanted: T(100, 114), request: T(100, 115), daily: T(100, 116), weekday: T(100, 116), ticket: T(100, 116), weekly: T(100, 116), repeat: T(100, 147), mission: T(100, 151) };
const TYPE_ORDER = ['main', 'normal', 'repeat', 'daily', 'request', 'mission'];
const WEEKLY_CATS = new Set(['daily', 'weekday', 'weekly', 'ticket', 'repeat']);

export class QuestLog {
  constructor(sys) { this.sys = sys; this.game = sys.game; this.tab = 'progress'; this.sel = null; this.win = null; }
  get db() { return this.sys.db; }
  get eng() { return this.sys.engine; }

  register() {
    const self = this;
    this.game.uiwin.registerWindow('quest', {
      script: 'game2/quest/ui_quest.txt',
      hotkey: 'KeyQ',
      menuButton: 'btn_quest',
      create(win) { self._create(win); },
      onOpen(win, arg) { if (arg?.quest != null) { self.sel = Number(arg.quest); self.tab = self.eng.isActive(arg.quest) ? 'progress' : self.eng.isDone(arg.quest) ? 'journal' : self.tab; } self.refresh(); },
    });
  }

  _create(win) {
    this.win = win;
    // the full-window art (layer 10) sits under the two page panels (layer 1): draw it first like the client
    const bg = win.control('pan_bg');
    if (bg?.el) bg.el.style.zIndex = '0';
    for (const [id] of TABS) { const c = win.find(id); if (c) c.el.style.zIndex = '101'; }
    for (const [id, tab] of TABS) win.control(id).onClick(() => { this.tab = tab; this.sel = null; this.refresh(); });
    const tree = win.control('quest_tree');
    this.tree = tree;
    tree.on('select', n => { if (n?.data?.quest != null) { this.sel = n.data.quest; this._details(); } });
    tree.on('dblclick', n => { const id = n?.data?.quest; if (id != null && this.eng.isActive(id)) { this.eng.track(id, !this.eng.isTracked(id)); this.refresh(); } });
    win.control('btn_confirm').onClick(() => win.close());
    win.control('btn_cancel').onClick(() => this._abandon());
    this.game.events?.on?.('quest:changed', () => { if (win.isOpen) this.refresh(); });
  }

  _str(ref, fb = '') { return this.game.uiwin.strings.get(ref) ?? fb; }
  _tag(q) {
    const listed = q.listedBy || [];
    if (listed.some(l => Number(l[1]) === 114)) return this._str(TYPE_TAG.mission, '[Mission]');
    return this._str(TYPE_TAG[q.cat] || TYPE_TAG.normal, '');
  }
  _typeKey(q) {
    if ((q.listedBy || []).some(l => Number(l[1]) === 114)) return 'mission';
    if (q.cat === 'main') return 'main';
    if (q.cat === 'request' || q.cat === 'wanted') return 'request';
    if (['daily', 'weekday', 'ticket', 'weekly'].includes(q.cat)) return 'daily';
    if (q.cat === 'repeat' || q.repeat) return 'repeat';
    return 'normal';
  }

  refresh() {
    const win = this.win;
    if (!win) return;
    for (const [id, tab] of TABS) win.control(id).setChecked(this.tab === tab);
    const eng = this.eng, db = this.db;
    let ids = [];
    if (this.tab === 'progress') ids = eng.activeIds();
    else if (this.tab === 'weekly') {
      eng.checkReset();
      const P = eng.st.period;
      const set = new Set(eng.activeIds().filter(id => WEEKLY_CATS.has(db.quest(id)?.cat) || db.quest(id)?.repeat));
      for (const id of [...Object.keys(P.c || {}), ...Object.keys(P.cw || {})]) set.add(Number(id));
      ids = [...set];
    } else if (this.tab === 'alarm') ids = eng.st.alarm.filter(id => eng.isActive(id));
    else ids = Object.keys(eng.st.done).map(Number).sort((a, b) => (eng.st.done[b]?.t || 0) - (eng.st.done[a]?.t || 0));

    const groups = new Map();
    for (const id of ids) {
      const q = db.quest(id);
      if (!q) continue;
      const k = this._typeKey(q);
      if (!groups.has(k)) groups.set(k, []);
      groups.get(k).push(q);
    }
    const nodes = [];
    for (const k of TYPE_ORDER) {
      const list = groups.get(k);
      if (!list?.length) continue;
      const tag = this._str(TYPE_TAG[k], `[${k}]`);
      nodes.push({
        text: `${tag} (${list.length})`, state: 'head', open: true, selectable: false,
        children: list.map(q => {
          const active = eng.isActive(q.id);
          const ready = active && eng.isComplete(q.id);
          const state = !active ? (this.tab === 'journal' ? 'complete' : 'unknown') : ready ? 'finish' : 'sub';
          const lv = questDisplayLevel(q, this.sys.db.Q);
          const count = this.tab === 'weekly' && !active ? ` (${eng.periodCount(q.id)}/${eng.repeatLimit(q) || 1})` : '';
          return { text: `${this._str(T(1002, 23), '[Lv.')}${lv}${this._str(T(1002, 24), ']')} ${q.title || q.name || q.id}${count}`, state, data: { quest: q.id } };
        }),
      });
    }
    this.tree.setNodes(nodes);
    const flat = nodes.flatMap(n => n.children);
    let pick = flat.find(n => n.data.quest === this.sel) || flat[0] || null;
    this.sel = pick?.data.quest ?? null;
    if (pick) this.tree.select(pick);
    this._details();
  }

  _details() {
    const win = this.win, q = this.db.quest(this.sel), eng = this.eng, db = this.db;
    const tb = win.control('textbox');
    if (!q) {
      win.control('lbl_subtitle').setText('');
      win.control('lbl_object').setText('');
      this.sys.fillTextBox(tb, '');
      win.control('btn_cancel').setEnabled(false);
      return;
    }
    const active = eng.isActive(q.id);
    win.control('lbl_subtitle').setText(`${questLevelTag(q, this.sys.db.Q)} ${this._tag(q)} ${q.title || q.name || ''}`.trim());
    const lines = [];
    if (active) lines.push(this._str(eng.isComplete(q.id) ? T(100, 143) : T(100, 142), ''));
    if (active) for (const o of q.objectives || []) lines.push(plainText(eng.objectiveText(q, o), eng.names));
    win.control('lbl_object').setText(lines.filter(Boolean).join('\n'));
    const info = [questLevelRequirement(q, this.sys.db.Q)];
    const fmt = (ref, v) => (this._str(ref, '%s')).replace('%s', v);
    if (q.giver?.npc != null) info.push(fmt(T(100, 149), db.npcName(q.giver.npc)));
    if (q.turnIn?.npc != null) info.push(fmt(T(100, 150), db.npcName(q.turnIn.npc)));
    if (q.map != null) info.push(fmt(T(100, 148), db.mapName(q.map)));
    const journal = db.str(q.id, 12, { common: false });
    const diary = db.str(q.id, 13, { common: false });
    const body = [info.join('\n'), journal ? fillPlaceholders(journal, eng.ctx(q)) : '', diary || ''].filter(Boolean).join('\n\n');
    this.sys.fillTextBox(tb, body);
    win.control('btn_cancel').setEnabled(active);
  }

  async _abandon() {
    const id = this.sel;
    if (id == null || !this.eng.isActive(id)) return;
    const W = this.game.uiwin;
    await W.strings.need([T(80, 84), T(81, 89)]).catch(() => {});
    // messagebox 81:89 "<center><color=00ff00>\n<center>Abandon quest?" (client markup: centred, green)
    const r = await this.sys.msgbox(this._str(T(81, 89), 'Abandon quest?'), { title: this._str(T(80, 84), 'Abandon Quest'), kind: 'yesno' });
    if (r !== 'yes') return;
    this.eng.abandon(id);
    this.sel = null;
    this.refresh();
  }
}
