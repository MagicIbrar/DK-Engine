// NPC dialogs of the dungeon / travel system on the ORIGINAL dialog window (script/ui/game2/ui_dialog_renewal.txt,
// the same window the quest system uses for NPC talk): title_label = NPC name, the textbox shows the text and the
// menu entries as clickable lines (the textbox's own `state 0` colour ff00FF00 = entry, `over` = white,
// `button_pos 22 0`, `buttonwidth 270`), btn_init "Go back" returns to the first page, btn_exit "Close".
// Menu entries that carry a <guage> directive run the original "select wait" gauge window
// (game2/msgbox/ui_npcdialog_selectwait.txt: siege#6 plate, siege#10/#11 bar, title = the gauge caption).

const DIALOG_SCRIPT = 'game2/ui_dialog_renewal.txt';
const WAIT_SCRIPT = 'game2/msgbox/ui_npcdialog_selectwait.txt';

// Shared renderers (loaded lazily so a missing module never breaks the dialog): the UI platform's fonts + atlas and
// the client-markup renderer the quest dialog uses (same window, same text look).
const MK = { render: null, applyFont: null, atlas: null };
Promise.all([
  import('../../ui/uiwin/fonts.js').catch(() => null),
  import('../../ui/atlas.js').catch(() => null),
  import('../quests/markup.js').catch(() => null),
]).then(([fonts, at, mk]) => {
  MK.applyFont = fonts?.applyFont || null;
  MK.atlas = at?.atlas || null;
  if (mk?.renderMarkup) {
    MK.render = (parent, text, lh, font, game) => mk.renderMarkup(parent, text, game?.quests?.engine?.names || {}, {
      lineHeight: lh,
      applyFont: (el, idx, h) => { MK.applyFont?.(el, idx, 0); el.style.lineHeight = h ? `${h}px` : ''; },
      linkColor: '#00ff00',
      onLink: (link) => { if (link?.kind === 'npc' && game?.findAuto?.goToNpc) game.findAuto.goToNpc(Number(link.id)); },
      sprite: (el, screen, index, w, h) => MK.atlas?.sprite(screen, index).then(s => { if (s) { el.style.backgroundImage = `url("${s.url}")`; el.style.backgroundSize = '100% 100%'; if (!w) el.style.width = `${s.w}px`; if (!h) el.style.height = `${s.h}px`; } }),
    });
  }
}).catch(() => {});

const argbCss = (h) => {
  if (Array.isArray(h)) return `rgba(${h[1]},${h[2]},${h[3]},${((h[0] ?? 255) / 255).toFixed(3)})`;
  const s = String(h).replace(/^0x/i, '').padStart(8, 'f');
  return `rgba(${parseInt(s.slice(2, 4), 16)},${parseInt(s.slice(4, 6), 16)},${parseInt(s.slice(6, 8), 16)},${(parseInt(s.slice(0, 2), 16) / 255).toFixed(3)})`;
};

export class DungeonDialog {
  constructor(sys) {
    this.sys = sys;
    this.game = sys.game;
    this.win = null;
    this.pages = [];
    this._creating = null;
    this._seq = 0;   // open / NPC-selection generation (a late open never paints over a newer selection or map)
    // The original client has ONE NPC dialog window: talking to an NPC (the quest system's 'npc' window emits
    // npc:talk) replaces the service menu the previous NPC left open, so its entries cannot run the old service.
    this.game.events?.on?.('npc:talk', () => { this._seq++; if (this.win?.isOpen) this.close(); });
    this.game.uiwin?.on?.('closeAll', () => { this._seq++; });
    this.game.events?.on?.('network', ({state} = {}) => {
      if (state === 'disconnected' || state === 'expired') { this._seq++; this.close(); }
    });
  }

  async _window() {
    if (this.win) return this.win;
    if (!this._creating) {
      this._creating = this.game.uiwin.create(DIALOG_SCRIPT, { name: 'dungeon_dialog', escClose: true }).then(win => {
        win.control('btn_info').hide();
        win.control('btn_itemlist').hide();
        win.control('pan_quest_info').hide();
        win.control('btn_init').onClick(() => { if (this.pages.length > 1) { this.pages.length = 1; this._render(); } });
        win.control('btn_exit').onClick(() => win.close('close'));
        win.on('close', () => { const p = this.pages[0]; this.pages = []; try { p?.onClose?.(); } catch (e) { console.error(e); } });
        this.win = win;
        return win;
      });
    }
    return this._creating;
  }

  get isOpen() { return !!this.win?.isOpen; }

  /**
   * Open a dialog page. page = { title, text (client markup ok), menu: [{text, onClick(dialog), keep}], onClose }.
   * A menu entry closes the dialog after its onClick unless it returns 'keep' / opens another page.
   */
  async open(page) {
    const seq = ++this._seq, world = this.game.world;
    const win = await this._window();
    // superseded while the window was being created: a newer page, another NPC's dialog or a map change
    if (seq !== this._seq || this.game.world !== world) return null;
    this.game.uiwin.close('npc');            // the quest system's NPC dialog (same window script)
    this.pages = [page];
    this._render();
    if (!win.isOpen) win.open();
    return win;
  }

  /** Push a sub page (btn_init "Go back" returns to the first page). */
  push(page) { this.pages.push(page); this._render(); }

  close() { this.win?.close('close'); }

  _render() {
    const win = this.win, page = this.pages[this.pages.length - 1];
    if (!win || !page) return;
    win.control('title_label').setText(page.title || '');
    win.control('btn_init').setEnabled?.(this.pages.length > 1);
    const tb = win.control('textbox');
    tb.clear?.();
    const props = tb.spec?.props || {};
    const lh = Number(props.lineheight?.[0]) || tb.lh || 18;
    const bx = Number(props.button_pos?.[0]) || 22;
    const bw = Number(props.buttonwidth?.[0]) || 270;
    const titles = tb.spec?.titles || [];
    const col = (st, d) => { const t = titles.find(x => String(x.state) === st); return t?.color ? argbCss(t.color) : d; };
    const cNone = col('0', col('none', 'rgba(0,255,0,1)')), cOver = col('over', '#fff');
    // the page text: client markup (colours, <font=N>, <center>, NPC / item links) as the quest dialog renders it
    const text = String(page.text || '');
    if (tb.content && MK.render) MK.render(tb.content, text, lh, tb.font || 2, this.game);
    else for (const line of text.replace(/<\/?font[^>]*>/gi, '').replace(/<\/?center>/gi, '').split('\n')) tb.addLine?.(line);
    const menu = page.menu || [];
    if (menu.length && tb.content) {
      const sp = document.createElement('div'); sp.style.height = `${lh}px`; tb.content.appendChild(sp);
      for (const m of menu) {
        // one menu line = the renewalquest row sprite (294 x 16: #38 talk bubble for NPC jobs, #36 plain option)
        const row = document.createElement('div');
        Object.assign(row.style, { position: 'relative', height: `${lh}px`, pointerEvents: 'auto', cursor: 'pointer', whiteSpace: 'nowrap' });
        const bg = document.createElement('div');
        Object.assign(bg.style, { position: 'absolute', left: '0', top: `${Math.round((lh - 16) / 2)}px`, width: '294px', height: '16px', backgroundRepeat: 'no-repeat', backgroundSize: '294px 16px', pointerEvents: 'none' });
        const rowSprite = m.row ?? (page.options ? 36 : 38);
        if (MK.atlas) {
          const s = MK.atlas.spriteNow?.('renewalquest', rowSprite);
          if (s) bg.style.backgroundImage = `url("${s.url}")`;
          else MK.atlas.sprite('renewalquest', rowSprite).then(x => { if (x) bg.style.backgroundImage = `url("${x.url}")`; });
        }
        row.appendChild(bg);
        const t = document.createElement('span');
        Object.assign(t.style, { position: 'absolute', left: `${bx}px`, top: '0', width: `${bw}px`, lineHeight: `${lh}px`, overflow: 'hidden', textOverflow: 'ellipsis', pointerEvents: 'none', color: cNone });
        MK.applyFont?.(t, tb.font || 2, lh);
        t.textContent = String(m.text || '').replace(/<[^>]+>/g, '');
        row.appendChild(t);
        row.addEventListener('pointerenter', () => { t.style.color = cOver; });
        row.addEventListener('pointerleave', () => { t.style.color = cNone; });
        row.addEventListener('pointerdown', (e) => { if (e.button === 0) e.stopPropagation(); });
        row.addEventListener('click', async (e) => {
          e.stopPropagation();
          this.game.uiwin.sound?.(0);
          const depth = this.pages.length, cur = this.pages[depth - 1];
          let r;
          try { r = await m.onClick?.(this); } catch (err) { console.error('[dungeons] dialog entry', err); }
          if (r === 'keep' || this.pages.length !== depth || this.pages[depth - 1] !== cur) return;
          this.close();
        });
        tb.content.appendChild(row);
        tb.lines?.push?.({ text: m.text, menu: true });
      }
    }
    tb._range?.();
    tb.setTop?.(0);
    requestAnimationFrame(() => tb._range?.());
  }

  /**
   * The original select-wait gauge: caption, progress over `ms`, cancel with the close button / Esc.
   * Resolves true when it completed, false when cancelled.
   */
  async gauge(text, ms = 1000, { sound = null } = {}) {
    const mgr = this.game.uiwin, seq = this._seq, world = this.game.world;
    const valid = () => seq === this._seq && world === this.game.world;
    const win = await mgr.create(WAIT_SCRIPT, { name: 'dungeon_selectwait', modal: true, escClose: true, remember: false, disposeOnClose: true });
    if (!valid()) {
      if (mgr.wins.get(win.name) === win) mgr.wins.delete(win.name);
      win.dispose();
      return false;
    }
    win.control('lbl_title').setText(String(text || '').replace(/<[^>]+>/g, ''));
    const bar = win.control('processbar');
    bar.setGauge(0);
    if (sound) this.sys.playEffectSound(sound);
    return new Promise((resolve) => {
      let t = 0, done = false;
      const tick = (dt) => {
        if (done) return;
        if (!valid()) { win.close('cancel'); return; }
        t += dt * 1000;
        bar.setGauge(Math.min(1, t / Math.max(1, ms)));
        if (t >= ms) { done = true; win.close('done'); }
      };
      const cancel = () => { if (!valid()) win.close('cancel'); };
      this.game.events?.on?.('npc:talk', cancel);
      this.game.events?.on?.('network', cancel);
      mgr.on('closeAll', cancel);
      win.on('update', tick);
      win.once('close', (r) => {
        done = true;
        this.game.events?.off?.('npc:talk', cancel);
        this.game.events?.off?.('network', cancel);
        mgr.off('closeAll', cancel);
        win.off('update', tick);
        resolve(r === 'done' && valid());
      });
      mgr.openWindow(win);
    });
  }
}
