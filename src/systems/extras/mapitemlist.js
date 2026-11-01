// UI-MAPITEMLIST: the original "Main Reward Item List" window (game2/itemlist/ui_mapitemlist.txt "mapitemlist", 520x558; title
// 2004:125) opened by the big map's scripted-hidden btn_itemlist (game2/ui_new_mapwnd.txt 710 12, quest#14). Left: multi_tree
// "All" (2004:126), "Common (All Regions)" (2004:127) and one entry per region with its maps; right: 11 rows of pan_item_cell
// (item_icon + lbl_item_name, 300x40) with slot_scroll; bottom: edit_search (maxlength 50), Search (2009:84), Reset (2009:86);
// an empty result reads "No Results Found" (2004:128). The content is derived from the monster spawn and drop tables
// (mapitemlist-rules.js); every selection / filter rule is ENGINE-CHOSEN (src/config/engine-chosen-mapitemlist.js).
import { str, strNow } from '../life/common.js';
import { slotIcon } from '../items/ui/common.js';
import { buildTooltip } from '../items/tooltip.js';
import { buildMapItemList, filterItems, entryForMap } from './mapitemlist-rules.js';

export const MIL_SCRIPT = 'game2/itemlist/ui_mapitemlist.txt';
export const MIL_ROWS = 11, MIL_ROW_H = 40;   // pan_mid_right 300x440 / pan_item_cell 300x40
const STRINGS = [[2004, [125, 126, 127, 128]], [2009, [84, 86]]];

export class MapItemList {
  constructor(game) { this.game = game; this.win = null; this.list = null; this.sel = { kind: 'all' }; this.query = ''; this.top = 0; this.rows = []; this.shown = []; this.paintIcon = slotIcon; }
  t(c, n, f = '') { return strNow(this.game, c, n) || f; }
  /** Built once from the loaded tables (gamedata/monsters.json, maplist.csv, the item database). */
  data() {
    if (this.list) return this.list;
    const g = this.game, db = g.items?.db || null;
    this.list = buildMapItemList({ monsters: g.data?.monsters, maplist: g.data?.maplist, db: db ? { has: (i) => db.has(i), def: (i) => db.def(i), name: (i) => db.name(i) } : null });
    return this.list;
  }
  async install() {
    const g = this.game, ui = g.uiwin;
    if (!ui?.registerWindow) return;
    void Promise.all(STRINGS.flatMap(([c, codes]) => codes.map((n) => str(g, c, n).catch(() => null))));
    ui.registerWindow('mapitemlist', { script: MIL_SCRIPT, create: (w) => this._create(w), onOpen: (w, arg) => this._open(w, arg) });
    // the big map's btn_itemlist is scripted hidden: show it and open the list on the shown map
    ui.on?.('open', (w) => {
      if (w?.name !== 'map') return;
      const b = w.control('btn_itemlist');
      b.setVisible?.(true);
      b.setTooltip?.(() => this.t(2004, 125, 'Main Reward Item List'));
      if (!b._milWired) { b._milWired = true; b.onClick(() => { void ui.open('mapitemlist', { map: g.world?.info?.index }); }); }
    });
    g.mapItemList = this;
  }
  _create(w) {
    this.win = w;
    w.control('btn_exit').onClick(() => this.game.uiwin.close(w));
    const tpl = w.control('pan_item_cell');
    for (let i = 0; i < MIL_ROWS; i++) {
      const r = tpl.cloneAs(`_${i}`, { y: i * MIL_ROW_H });
      const icon = r.control(`item_icon_${i}`);
      icon.setTooltip?.(() => (r.data.item && this.game.items ? buildTooltip(this.game.items, r.data.item.index, { where: 'mapitemlist' }) : null));
      this.rows.push(r);
    }
    tpl.hide?.();
    const sc = w.control('slot_scroll');
    sc.on?.('change', (v) => { this.top = Math.round(Number(v) || 0); this._render(); });
    w.control('pan_mid_right').el?.addEventListener?.('wheel', (e) => { e.preventDefault?.(); this.top += Math.sign(e.deltaY); this._render(); }, { passive: false });
    const tree = w.control('multi_tree');
    tree.on?.('select', (n) => { if (n?.data) { this.sel = n.data; this.top = 0; this._render(); } });
    const search = () => { this.query = String(w.control('edit_search').getValue?.() ?? ''); this.top = 0; this._render(); };
    w.control('btn_search').onClick(search);
    w.control('edit_search').on?.('enter', search);
    w.control('btn_refresh').onClick(() => { w.control('edit_search').setValue?.(''); this.query = ''; this.top = 0; this._render(); });
  }
  _nodes() {
    const L = this.data(), sel = this.sel;
    const node = (text, data, state, extra = {}) => ({ text, data, state, ...extra });
    const same = (d) => d.kind === sel.kind && (d.kind !== 'map' || (d.region === sel.region && d.name === sel.name));
    const out = [node(this.t(2004, 126, 'All'), { kind: 'all' }, 'head'), node(this.t(2004, 127, 'Common (All Regions)'), { kind: 'common' }, 'head')];
    for (const r of L.regions) out.push(node(r.name, null, 'head', { open: sel.kind === 'map' && sel.region === r.territory,
      children: r.maps.map((m) => node(m.name, { kind: 'map', region: r.territory, name: m.name }, 'sub')) }));
    const mark = (list) => { for (const n of list) { if (n.data && same(n.data)) n.selected = true; if (n.children) mark(n.children); } };
    mark(out);
    return out;
  }
  items() {
    const L = this.data(), s = this.sel;
    let base = s.kind === 'common' ? L.common : s.kind === 'map' ? (L.regions.find((r) => r.territory === s.region)?.maps.find((m) => m.name === s.name)?.items || []) : L.all;
    return filterItems(base, this.query);
  }
  _open(w, arg) {
    const L = this.data(), hit = arg?.map != null ? entryForMap(L, arg.map) : null;
    this.sel = hit ? { kind: 'map', region: hit.region.territory, name: hit.map.name } : { kind: 'all' };
    this.query = ''; this.top = 0;
    w.control('edit_search').setValue?.('');
    const tree = w.control('multi_tree');
    tree.setNodes?.(this._nodes());
    const pick = (list) => { for (const n of list) { if (n.selected) return n; const c = n.children && pick(n.children); if (c) return c; } return null; };
    const n = pick(tree.nodes || []);
    if (n) tree.select?.(n, false);
    w.center?.();
    this._render();
  }
  _render() {
    const w = this.win; if (!w) return;
    const items = this.shown = this.items(), max = Math.max(0, items.length - MIL_ROWS);
    this.top = Math.max(0, Math.min(this.top, max));
    const sc = w.control('slot_scroll'); sc.setRange?.(max, MIL_ROWS); sc.setValue?.(this.top);
    const sys = this.game.items;
    for (let i = 0; i < MIL_ROWS; i++) {
      const r = this.rows[i], it = items[this.top + i] || null;
      r.data.item = it;
      const icon = r.control(`item_icon_${i}`), name = r.control(`lbl_item_name_${i}`);
      const empty = !items.length && i === 0;
      r.setVisible?.(!!it || empty);
      icon.setVisible?.(!!it);
      if (it && sys) this.paintIcon(sys, icon, { itemIndex: it.index, count: 1, grade: 'normal' });
      name.setText(it ? it.name : empty ? this.t(2004, 128, 'No Results Found') : '');
    }
  }
}