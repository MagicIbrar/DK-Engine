// The NPC dialog of the event NPCs, drawn with the original dialog window (game2/ui_dialog_renewal.txt): title_label =
// NPC name, textbox = the NPC's lines, followed by the menu lines (the textbox's own `state 0` title colour ff00FF00,
// white on hover, `button_pos 22 0`, `buttonwidth 270`). btn_init "Go back" returns to the NPC's first page,
// btn_exit "Close" closes, btn_info "See more" opens the right-hand info page (pan_quest_info) with the event rules.
// Pages: { title, text, options: [{label, pick(), color}], info: {title, text} }.
import { plain } from './text.js';

export class EventDialog {
  constructor(game) {
    this.game = game;
    this.npc = null;
    this.root = null;
    this.page = null;
    game.uiwin?.registerWindow('ev_dialog', {
      script: 'game2/ui_dialog_renewal.txt',
      create: (win) => {
        win.control('btn_init').onClick(() => { if (this.root) this.show(this.root); });
        win.control('btn_info').onClick(() => this._toggleInfo());
      },
      onClose: () => { this.npc = null; this.root = null; this.page = null; },
    });
  }

  get isOpen() { return !!this.game.uiwin?.isOpen('ev_dialog'); }

  /** Open the dialog for an NPC actor with a first page. */
  async open(npc, page) {
    this.npc = npc;
    this.root = page;
    this.game.audio?.npcGreeting?.(npc?.npcIndex ?? npc?.def?.index, npc);
    await this.show(page);
  }

  async show(page) {
    const ui = this.game.uiwin;
    if (!ui) return;
    this.page = page;
    const win = await ui.open('ev_dialog');
    if (this.page !== page) return;
    win.control('title_label').setText(page.title ?? this.npc?.name ?? '');
    win.control('btn_info').setVisible(!!page.info);
    win.control('pan_quest_info').setVisible(false);
    const tb = win.control('textbox');
    tb.clear?.();
    for (const line of String(page.text ?? '').split('\n')) tb.addLine?.(line);
    const opts = page.options || [];
    if (opts.length && tb.content) {
      tb.addLine?.('');
      for (const o of opts) {
        const d = document.createElement('div');
        d.className = 'uw-hit';
        d.style.cssText = `min-height:${tb.lh || 18}px;padding-left:22px;width:270px;cursor:pointer;color:${o.color || '#00ff00'};pointer-events:auto`;
        d.textContent = plain(o.label);
        d.addEventListener('pointerenter', () => { d.style.color = '#ffffff'; });
        d.addEventListener('pointerleave', () => { d.style.color = o.color || '#00ff00'; });
        d.addEventListener('pointerdown', (e) => { e.stopPropagation(); });
        d.addEventListener('click', (e) => {
          e.stopPropagation();
          this.game.uiwin?.sound?.(0);
          try { o.pick?.(); } catch (err) { console.error('[events] dialog option', err); }
        });
        tb.content.appendChild(d);
      }
      tb._range?.();
    }
    tb.setTop?.(0);
  }

  _toggleInfo() {
    const win = this.game.uiwin?.window('ev_dialog');
    const info = this.page?.info;
    if (!win || !info) return;
    const pan = win.control('pan_quest_info');
    const on = !pan.isVisible();
    pan.setVisible(on);
    if (!on) return;
    win.control('lbl_questinfo_title').setText(info.title || '');
    const tb = win.control('textbox_questinfo');
    tb.clear?.();
    for (const line of String(info.text || '').split('\n')) tb.addLine?.(line);
    tb.setTop?.(0);
  }

  close() { this.game.uiwin?.close('ev_dialog'); }
}
