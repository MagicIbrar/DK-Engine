// Mini help: the original `game2/minihelp/ui_minihelpwnd.txt` (a 344 x 38 text line above the bottom-left of the screen) driven by
// the timing table script/minihelp.csv and the tutorial strings (NORMAL cate 3100). The movement tutorial (codes 1-8) walks a new
// level-1 character through W / S / A / D, looking left and right with the right mouse button, and a ground click; the welcome
// question (10001) and the "end the tutorial?" confirmation (10002) are the client's own texts. Rules and assumptions:
// minihelp-rules.js. State is per character in localStorage (a tutorial hint is not game state).
import { fetchText } from '../../engine/assets.js';
import { strings } from '../../ui/uiwin/strings.js';
import { LS } from '../hud-options/util.js';
import { parseMiniHelpCsv, fadeTiming, hintPhase, normaliseTutorialMarkup, MovementTutorial, TUTORIAL_CATE, FADE_DEFAULT } from './minihelp-rules.js';

const txt = code => strings.resolve({ group: 'NORMAL', cate: TUTORIAL_CATE, code }).then(v => normaliseTutorialMarkup(v || ''));

export class MiniHelp {
  constructor(game) {
    this.game = game; this.win = null; this.timing = { ...FADE_DEFAULT }; this.cur = null; this.tutorial = null;
    this.texts = new Map(); this._asked = false; this._order = null;
  }
  get storageKey() { return `dekaron.minihelp.${this.game.save?.id || 'guest'}`; }
  get state() { return LS.load(this.storageKey, null); }

  async install() {
    const g = this.game;
    try { this.rows = parseMiniHelpCsv(await fetchText('script/minihelp.csv', true)); this.timing = fadeTiming(this.rows); } catch (err) { console.warn('[minihelp] minihelp.csv', err); this.rows = []; }
    await Promise.all([1, 2, 3, 4, 5, 6, 7, 8, 10000, 10001, 10002, 50000].map(async c => this.texts.set(c, await txt(c))));
    g.uiwin.registerWindow('minihelp', {
      script: 'game2/minihelp/ui_minihelpwnd.txt', hud: true, escClose: false, remember: false,
      create: w => { this.win = w; w.control('lbl_help').setText(''); w.root.el.style.opacity = '0'; },
    });
    g.minihelp = this;
    g.events?.on?.('map', () => { this._asked = false; this._order = null; });
    await g.uiwin.open('minihelp').catch(err => console.error('[minihelp] open', err));
  }

  /** Show a hint: fade in, hold, fade out (the table timing). `repeat` shows it again after the table's delay until hide(). */
  show(text, { repeat = false } = {}) {
    this.cur = { text: String(text || ''), t: 0, repeat, wait: 0 };
    this.win?.control('lbl_help').setRichText(this.cur.text);
    this._alpha(0);
  }
  hide() { this.cur = null; this._alpha(0); this.win?.control('lbl_help').setText(''); }
  _alpha(a) { if (this.win?.root?.el) this.win.root.el.style.opacity = String(Math.max(0, Math.min(1, a))); }

  update(dt) {
    const c = this.cur;
    if (c) {
      if (c.wait > 0) { c.wait -= dt * 1000; if (c.wait <= 0) { c.t = 0; this._alpha(0); } }
      else {
        c.t += dt * 1000;
        const { alpha, done } = hintPhase(c.t, this.timing);
        this._alpha(alpha);
        if (done) { if (c.repeat) { c.wait = this.timing.delay; this._alpha(0); } else this.hide(); }
      }
    }
    this._tutorialTick(dt);
  }

  // ------------------------------------------------------------------------------------------------ the movement tutorial
  _eligible() {
    const g = this.game, p = g.player;
    if (!p || !g.world || this.state != null || (Number(g.save?.level) || 1) > 1) return false;
    // cell attribute 7 = TUTORIAL (share/arrange/cell.csv: the Ardeca starting yard); game.zones is not installed in server mode
    return g.world.collision?.attrAt?.(p.x, p.z) === 7;
  }
  async _ask() {
    const g = this.game, ui = g.uiwin;
    this._asked = true;
    const title = this.texts.get(10000) || 'tutorial';
    let answer = await ui.msgbox(this.texts.get(10001), { kind: 'yesno', title });
    while (answer !== 'yes') {
      // "You can't begin the tutorial again if you cancel. Are you sure you want to end the tutorial?"
      if (await ui.msgbox(this.texts.get(10002), { kind: 'yesno', title }) === 'yes') { LS.save(this.storageKey, 'skipped'); return; }
      answer = await ui.msgbox(this.texts.get(10001), { kind: 'yesno', title });
    }
    this.begin();
  }
  begin() {
    this.tutorial = new MovementTutorial();
    this._shown = null;
  }
  _tutorialTick(dt) {
    const g = this.game;
    if (!this.tutorial) {
      if (!this._asked && !g.uiwin?.capturesInput && this._eligible()) { this._waited = (this._waited || 0) + dt; if (this._waited > 4) { this._waited = 0; void this._ask(); } }
      return;
    }
    const inp = g.input, ctl = g.controller, t = this.tutorial;
    if ((Number(g.save?.level) || 1) > 1) { this._finish('done'); return; }
    const order = ctl?.order?.type === 'move' ? ctl.order : null;
    const clickMove = !!order && order !== this._order;
    this._order = order || this._order;
    const code = t.feed({ keys: inp?.keys, rightHeld: !!inp?.held?.right, dx: Number(inp?.mouse?.dx) || 0, clickMove });
    if (code == null) { this._finish('done'); return; }
    if (code !== this._shown) {
      this._shown = code;
      this.show(this.texts.get(code), { repeat: code !== 8 });
    }
    // the completion line is shown once; when it has faded out the tutorial is over
    if (code === 8 && !this.cur) { t.advance(); this._finish('done'); }
  }
  _finish(state) {
    this.tutorial = null; this.hide(); LS.save(this.storageKey, state);
    const done = this.texts.get(50000);
    if (state === 'done' && done) void this.game.uiwin.msgbox(done, { kind: 'ok', title: this.texts.get(10000) || 'tutorial' });
  }
  dispose() { this.cur = null; this.tutorial = null; }
}
