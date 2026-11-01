// The GM panel window (F10, /gm panel). The client ships no GM panel, so the frame is a window script written in the
// client's own tag format (parsed and drawn by the UI platform like every script/ui file, docs/UIWIN.md) from original
// sprites only: frame etc_01#87 (the common message window, nine-sliced), tabs auto_hunt#6/#7 (the auto-hunt option
// tabs), body board bigmap#61, close button etc_01#315/316/317, title/status in the client fonts. The tab bodies are
// data-heavy (95 000 items, 4 577 monsters, 3 178 quests in searchable virtual lists), so they are DOM content hosted in
// the body board (kit.js: the client's Tahoma look, etc_01#2 buttons, the minimap atlas for the coordinate picker).
import { parseTagScript, buildSpecs } from '../../ui/uiwin/index.js';
import { h, injectKitCSS } from './kit.js';
import { PAGES } from './pages.js';
import { toolSearch } from './tool-search.js';
import {requireGMPanelPermission} from './permissions.js';

export const W = 880, H = 652;
export const TABS = [
  ['commands', 'Commands'], ['monsters', 'Monsters'], ['items', 'Items'], ['teleport', 'Teleport'], ['npcs', 'NPCs'],
  ['character', 'Character'], ['players', 'Players'], ['inventories', 'Inventory'], ['quests', 'Quests'], ['world', 'World'], ['drops', 'Drops'], ['builders', 'Builders'], ['tools', 'Tools'],
];
const BODY = { x: 10, y: 98, w: W - 20, h: H - 130 };

const q = (s) => `"${String(s).replace(/"/g, "'")}"`;
const img = (screen, index, key = 'none') => `<image>\nkey ${key}\nscreen ${screen}\nindex ${index}\n</image>`;
const title = ({ state = 'none', color = 'ffffffff', font = 2, pos = '0 0', text = null }) =>
  `<title>\nstate ${state}\ncolor ${color}\nfontindex ${font}\nposition ${pos}${text != null ? `\ntext ${q(text)}` : ''}\n</title>`;
const rect = (x, y, w, hh) => `rect ${x} ${y} ${w} ${hh}`;

/** The panel's window script (client tag format). */
export function panelScript() {
  const L = [];
  const label = (id, x, y, w, hh, text, { color = 'ffffffff', font = 2, align = 'left', layer = 20 } = {}) =>
    `<label>\nid ${id}\n${rect(x, y, w, hh)}\nlayer ${layer}\nalign ${align}\nintersect false\n${title({ color, font, text, pos: '0 1' })}\n</label>`;
  const tab = (id, x, y, w, text) => `<button>\nid ${id}\n${rect(x, y, w, 23)}\nlayer 30\nalign center\nsound 0\n${img('auto_hunt', 6)}\n${img('auto_hunt', 7, 'check')}\n`
    + `${title({ color: 'ff929292', font: 2, pos: '0 6', text })}\n${title({ state: 'over', color: 'ffffffff', font: 2, pos: '0 6' })}\n${title({ state: 'check', color: 'ff1a1a1a', font: 4, pos: '0 6' })}\n</button>`;
  L.push('<window>', 'name gmpanel', rect(0, 0, W, H), `titlerect 0 0 ${W - 40} 36`, 'layer 100');
  L.push('<panel>', 'id pan_bg', rect(0, 0, W, H), 'layer 0', img('etc_01', 87), '</panel>');
  L.push(label('lbl_title', 0, 11, W, 18, 'Command Center', { align: 'center', font: 4, color: 'fff4d27a', layer: 5 }));
  L.push(label('lbl_hint', 20, 13, 360, 14, 'F10 panel  ·  ` console  ·  /gm help', { color: 'ff8c8c8c', layer: 5 }));
  L.push(`<button>\nid btn_close\n${rect(W - 28, 9, 19, 19)}\nlayer 50\n${img('etc_01', 315)}\n${img('etc_01', 316, 'over')}\n${img('etc_01', 317, 'down')}\n</button>`);
  const tw = Math.floor((W - 20) / TABS.length);
  TABS.forEach(([k, t], i) => L.push(tab(`btn_tab_${k}`, 10 + i * tw, 72, tw, t)));
  L.push('<panel>', 'id pan_body', rect(BODY.x, BODY.y, BODY.w, BODY.h), 'layer 5', img('bigmap', 61), '</panel>');
  L.push(label('lbl_status', 16, H - 26, W - 32, 14, '', { color: 'ffffe38c', layer: 20 }));
  L.push('</window>');
  return L.join('\n');
}

let _spec = null;
export function panelSpec() {
  if (_spec) return _spec;
  const parsed = parseTagScript(panelScript(), { file: 'gm/ui_gmpanel' });
  const specs = buildSpecs(parsed.roots, { file: 'gm/ui_gmpanel' });
  if (parsed.warnings.length || specs.warnings.length) console.warn('[gm] panel script warnings', [...parsed.warnings, ...specs.warnings].slice(0, 10));
  _spec = specs.windows[0];
  return _spec;
}

export class GMPanel {
  constructor(gm) {
    this.gm = gm;
    this.game = gm.game;
    this.tab = 'commands';
    this.pages = {};
    this.win = null;
    this.host = null;
    this._t = 0;
  }

  register() {
    injectKitCSS();
    const self = this;
    this.game.uiwin.registerWindow('gmpanel', {
      script: panelSpec(),
      create(win) { self._create(win); },
      onOpen(win, arg) { self._onOpen(win, arg); },
      onClose() { self.search?.close(); self.pages[self.tab]?.onHide?.(); self.game.uiwin.tooltips?.hide?.(); },
    });
  }

  get isOpen() { return !!this.game.uiwin?.isOpen('gmpanel'); }
  async open(tab = null, arg = null) { await this.gm.ready;requireGMPanelPermission(this.game);return this.game.uiwin.open('gmpanel', { tab, arg }); }
  toggle() { if (this.isOpen) this.game.uiwin.close('gmpanel'); else this.open(); }

  _create(win) {
    this.win = win;
    const body = win.control('pan_body');
    this.host = h('div.gmk', { style: { left: '6px', top: '6px', right: '6px', bottom: '6px', position: 'absolute', overflow: 'hidden' } });
    // clicks / wheel inside the DOM content never reach the world or the window drag
    for (const ev of ['mousedown', 'wheel', 'contextmenu']) this.host.addEventListener(ev, (e) => e.stopPropagation(), { passive: ev !== 'contextmenu' });
    this.host.addEventListener('keydown', (e) => { if (e.code !== 'F10' && e.code !== 'Escape') e.stopPropagation(); });
    body.el.appendChild(this.host);
    body.el.style.pointerEvents = 'auto';
    this.search = toolSearch(this, TABS);
    body.el.parentElement.appendChild(this.search.el);
    for (const [k] of TABS) win.control(`btn_tab_${k}`).onClick(() => this.show(k));
  }

  _onOpen(win, arg) {
    const tab = arg?.tab && PAGES[String(arg.tab).toLowerCase()] ? String(arg.tab).toLowerCase() : this.tab;
    this.show(tab, arg?.arg ?? null);
  }

  /** Show a tab (built on first use). */
  show(k, arg = null) {
    requireGMPanelPermission(this.game);
    if (!PAGES[k]) k = 'commands';
    if(this.tab!==k)this.pages[this.tab]?.onHide?.();
    this.tab = k;
    for (const [id] of TABS) this.win?.control(`btn_tab_${id}`).setChecked(id === k);
    // each page lives in its own wrapper (the page element keeps its own display: flex / block)
    for (const [id, p] of Object.entries(this.pages)) p.wrap.style.display = id === k ? '' : 'none';
    let p = this.pages[k];
    if (!p) {
      try {
        p = this.pages[k] = PAGES[k](this.ctx());
      } catch (err) {
        console.error(`[gm] page ${k}`, err);
        p = this.pages[k] = { el: h('div', null, `This page failed to build: ${err.message}`) };
      }
      p.wrap = h('div', { style: { position: 'absolute', left: '0', top: '0', right: '0', bottom: '0' } }, p.el);
      p.el.style.height = '100%';
      this.host.appendChild(p.wrap);
    }
    try { p.onShow?.(arg); } catch (err) { console.error(`[gm] page ${k} onShow`, err); }
  }

  /** Context handed to the page builders. */
  ctx() {
    const gm = this.gm, game = this.game;
    return {
      gm, game, panel: this,
      run: (line) => gm.run(line, { source: 'panel' }),
      status: (t, c) => this.status(t, c),
      show: (k, arg) => this.show(k, arg),
    };
  }

  status(text, color = 'ffffe38c') {
    const l = this.win?.control('lbl_status');
    if (!l) return;
    l.setText(String(text ?? '').split('\n')[0].slice(0, 160));
    l.setTextColor(color);
  }

  update(dt) {
    if (!this.isOpen) return;
    this._t -= dt;
    if (this._t > 0) return;
    this._t = 0.5;
    try { this.pages[this.tab]?.tick?.(); } catch (err) { console.warn('[gm] tick', err); }
  }

  revoke() {
    this.search?.close();this.search?.reset?.();this.playerTarget=null;
    for(const p of Object.values(this.pages))p.onHide?.();
    this.game.uiwin?.close?.('gmpanel');
    // Cached inventory/character data must not remain in a hidden window.
    this.host?.replaceChildren();this.pages={};
  }
}
