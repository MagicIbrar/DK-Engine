// The on-screen quest tracker ("Quest Progress Window"): script/ui/game2/quest/ui_new_questassist.txt (186 x 120).
//   pan_body     renewalquest#25 (186 x 83, nine-slice top 32 / bottom 10): grows with the listed quests
//   lbl_tagtitle "Quest Progress Window";  btn_minimize -> only btn_redo (renewalquest#26..28) stays; btn_redo restores
//   pan_object   row template (btn_cancel "x" = unregister from the Quest Alarm, lbl_object = title + objectives)
//   btn_up / btn_down scroll when more quests are registered than fit.
// Lists the Quest Alarm quests (engine.st.alarm, max 10) in registration order.
import { plainText } from './markup.js';
import { questDisplayLevel } from './levels.js';
import { measureText } from '../../ui/uiwin/fonts.js';
function fitLines(text,width=148){let count=0;for(const line of plainText(text).split('\n')){let run='';count++;for(const token of line.split(/(\s+)/)){if(measureText(run+token,2)<=width){run+=token;continue;}if(run){count++;run='';}for(const ch of token){if(run&&measureText(run+ch,2)>width){count++;run='';}run+=ch;}}}return count;}


const TOP = 33;            // first row (under the title strip)
const BOTTOM_PAD = 10;     // bottom margin of the nine-slice
const LINE = 14;           // fontIndex 2 line height
const MAX_H = 300;         // body height cap before scrolling
const LS_MIN = 'dekaron-solo:quests:trackerMin';
const T = (cate, code) => ({ group: 'NORMAL', cate, code });

export class QuestTracker {
  constructor(sys) { this.sys = sys; this.game = sys.game; this.win = null; this.top = 0; this.rows = []; this._pending = false; }
  get eng() { return this.sys.engine; }

  register() {
    const self = this;
    const W = this.game.uiwin;
    this.game.uiwin.registerWindow('questassist', {
      script: 'game2/quest/ui_new_questassist.txt',
      hud: true,
      band: 'hud',
      pos: { x: Math.max(0, W.screen.w - 186 - 8), y: 212 },
      create(win) { self._create(win); },
      onOpen() { self.render(); },
    });
    W.on('resize', () => { const w = W.window('questassist'); if (w?.isOpen && !W.savedPosition('questassist')) { w.opts.pos = { x: Math.max(0, W.screen.w - 186 - 8), y: 212 }; w.place(); self.render(); } });
  }

  _create(win) {
    this.win = win;
    win.root.setClip(false);
    this.tpl = win.control('pan_object');
    win.control('btn_minimize').onClick(() => this.setMinimized(true));
    win.control('btn_redo').onClick(() => this.setMinimized(false));
    win.control('btn_up').onClick(() => { this.top = Math.max(0, this.top - 1); this.render(); });
    win.control('btn_down').onClick(() => { this.top += 1; this.render(); });
    this.minimized = (() => { try { return localStorage.getItem(LS_MIN) === '1'; } catch { return false; } })();
  }

  /** "[Lv.N]" tag of the original recommended quest level, shared with the quest window. */
  _lv(q) {
    const W = this.game.uiwin;
    const lv = questDisplayLevel(q, this.sys.db.Q);
    return `${W?.strings?.get?.(T(1002, 23)) ?? '[Lv.'}${lv}${W?.strings?.get?.(T(1002, 24)) ?? ']'}`;
  }

  setMinimized(on) {
    this.minimized = !!on;
    try { localStorage.setItem(LS_MIN, on ? '1' : '0'); } catch { /* private mode */ }
    this.render();
  }

  /** Show / hide by the Quest Alarm contents; called on quest changes. */
  sync() {
    if (this._pending) return;
    this._pending = true;
    queueMicrotask(async () => {
      this._pending = false;
      const W = this.game.uiwin;
      const any = this.eng.st.alarm.some(id => this.eng.isActive(id));
      if (any && !W.isOpen('questassist')) await W.open('questassist');
      else if (!any && W.isOpen('questassist')) W.close('questassist');
      else if (any) this.render();
    });
  }

  render() {
    const win = this.win;
    if (!win) return;
    const eng = this.eng, db = this.sys.db;
    const ids = eng.st.alarm.filter(id => eng.isActive(id));
    const body = win.control('pan_body');
    const redo = win.control('btn_redo');
    body.setVisible(!this.minimized);
    redo.setVisible(!!this.minimized);
    for (const r of this.rows) r.remove?.();
    this.rows = [];
    if (this.minimized) return;
    // build the blocks
    const blocks = ids.map(id => {
      const q = db.quest(id);
      const ready = eng.isComplete(id);
      const lines = [`<color=${ready ? 'ff8000' : 'fcb602'}>${this._lv(q)} ${plainText(q.title || q.name || String(id), eng.names)}</color>`];
      if (ready) lines.push(`<color=ff8000>${this.game.uiwin.strings.get({ group: 'NORMAL', cate: 100, code: 143 }) || ''}</color>`);
      else for (const o of q.objectives || []) {
        const done = eng.objectiveDone(q, o);
        lines.push(`<color=${done ? '8a8a8a' : 'ffffff'}>- ${plainText(eng.objectiveText(q, o), eng.names)}</color>`);
      }
      return { id, lines, h: lines.reduce((n,line)=>n+fitLines(line),0) * LINE + 4 };
    });
    this.top = Math.max(0, Math.min(this.top, Math.max(0, blocks.length - 1)));
    let y = TOP;
    const shown = [];
    for (let i = this.top; i < blocks.length; i++) {
      const b = blocks[i];
      if (shown.length && y + b.h > MAX_H - BOTTOM_PAD) break;
      shown.push({ ...b, y });
      y += b.h;
    }
    const height = Math.max(83, y + BOTTOM_PAD);
    body.setRect(0, 0, 186, height);
    shown.forEach((b, i) => {
      const row = this.tpl.cloneAs(`_${i}`, { x: 0, y: b.y, visible: true });
      row.setRect(0, b.y, 168, b.h);
      const lbl = row.control ? row.control(`lbl_object_${i}`) : null;
      const cancel = row.control ? row.control(`btn_cancel_${i}`) : null;
      if (lbl) {
        lbl.setRect(20, 0, 148, b.h);
        if (lbl.setRichText) lbl.setRichText(b.lines.join('\n')); else lbl.setText(b.lines.map(l => plainText(l)).join('\n'));
        lbl.onClick(() => this.game.uiwin.open('quest', { quest: b.id }));
        lbl.setTooltip?.(null);
      }
      cancel?.onClick(() => { this.eng.track(b.id, false); });
      this.rows.push(row);
    });
    const more = blocks.length > shown.length || this.top > 0;
    win.control('btn_up').setVisible(more).setEnabled(this.top > 0);
    win.control('btn_down').setVisible(more).setEnabled(this.top + shown.length < blocks.length);
  }
}
