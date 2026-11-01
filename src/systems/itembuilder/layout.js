// The item builder window, written as a window script in the client's own tag format (the same parser and renderer
// as every script/ui file, docs/UIWIN.md) and drawn with original sprites only:
//   frame etc_01#87 (the common message window, nine-sliced), boards bigmap#61 (nine-sliced 6 px border),
//   list backgrounds pcpop#79 (black 80 %), tabs auto_hunt#6/#7 (the auto-hunt option tabs), buttons
//   item_shop_popup#11/12/13 (message box buttons) and etc_01#88/89/90, fields auto_hunt#8/#17/#19, combobox
//   party#4 board + etc_01#15/16/17 arrow, checkboxes etc_01#303/304, close etc_01#315/316/317, list scrollbar
//   new_StorePurchase#8..15 (the store search list), separators StorePurchase#2.
// 900 x 600 reference px: picker lists (left), the editor pages (middle), the live 3D preview + icon (right).
import { parseTagScript, buildSpecs } from '../../ui/uiwin/index.js';

export const W = 900, H = 600;
export const PICK_TABS = [['lib', 'Mine'], ['items', 'Items'], ['models', 'Models'], ['tex', 'Textures'], ['icons', 'Icons']];
export const PAGES = [['general', 'General'], ['stats', 'Stats'], ['options', 'Options'], ['look', 'Look']];
export const MODES = [['character', 'Character'], ['item', 'Model'], ['icon', 'Icon']];
export const BUTTONS = [['new', 'New'], ['save', 'Save'], ['saveas', 'Save as New'], ['delete', 'Delete'], ['spawn', 'Spawn'], ['equip', 'Spawn + Equip'], ['export', 'Export'], ['import', 'Import']];
export const PREVIEW = { x: 616, y: 69, w: 272, h: 320 };

const q = (s) => `"${String(s).replace(/"/g, "'")}"`;
const img = (screen, index, key = 'none', color = null) => `<image>\nkey ${key}\nscreen ${screen}\nindex ${index}${color ? `\ncolor ${color}` : ''}\n</image>`;
const title = ({ state = 'none', color = 'ffffffff', font = 2, pos = '0 0', text = null }) =>
  `<title>\nstate ${state}\ncolor ${color}\nfontindex ${font}\nposition ${pos}${text != null ? `\ntext ${q(text)}` : ''}\n</title>`;
const rect = (x, y, w, h) => `rect ${x} ${y} ${w} ${h}`;

export function builderScript(classNames = []) {
  const L = [];
  const push = (...a) => L.push(...a);
  const panel = (id, x, y, w, h, inner = '', { layer = 1, intersect = true, visible = true } = {}) =>
    push('<panel>', `id ${id}`, rect(x, y, w, h), `layer ${layer}`, `intersect ${intersect}`, `visible ${visible}`, inner, '</panel>');
  const label = (id, x, y, w, h, text, { color = 'ffffffff', font = 2, align = 'left', layer = 20, multiline = false, pos = '0 1' } = {}) =>
    `<label>\nid ${id}\n${rect(x, y, w, h)}\nlayer ${layer}\nalign ${align}\nintersect false${multiline ? '\nmultiline true' : ''}\n${title({ color, font, text, pos })}\n</label>`;
  const button = (id, x, y, w, h, text, { small = false, layer = 30 } = {}) => {
    const [a, b, c] = small ? [88, 89, 90].map(i => ['etc_01', i]) : [11, 12, 13].map(i => ['item_shop_popup', i]);
    const f = small ? 2 : 3;
    const py = small ? Math.max(2, Math.round((h - 12) / 2)) : Math.max(3, Math.round((h - 13) / 2));
    return `<button>\nid ${id}\n${rect(x, y, w, h)}\nlayer ${layer}\nalign center\nsound 0\n${img(a[0], a[1])}\n${img(b[0], b[1], 'over')}\n${img(c[0], c[1], 'down')}\n${img(a[0], a[1], 'disable')}\n`
      + `${title({ color: 'ffe6e6e6', font: f, pos: `0 ${py}`, text })}\n${title({ state: 'over', color: 'ffffffff', font: f, pos: `0 ${py}` })}\n${title({ state: 'down', color: 'ffc8c8c8', font: f, pos: `0 ${py + 1}` })}\n${title({ state: 'disable', color: 'ff707070', font: f, pos: `0 ${py}` })}\n</button>`;
  };
  const tab = (id, x, y, w, text) => `<button>\nid ${id}\n${rect(x, y, w, 23)}\nlayer 30\nalign center\nsound 0\n${img('auto_hunt', 6)}\n${img('auto_hunt', 7, 'check')}\n`
    + `${title({ color: 'ff929292', font: 2, pos: '0 6', text })}\n${title({ state: 'over', color: 'ffffffff', font: 2, pos: '0 6' })}\n${title({ state: 'check', color: 'ff1a1a1a', font: 4, pos: '0 6' })}\n</button>`;
  const edit = (id, x, y, w, h = 18, { digits = false, max = 0, align = 'left', multi = false, bg = null } = {}) => {
    const b = bg || (w >= 180 ? ['auto_hunt', 8] : w >= 70 ? ['auto_hunt', 17] : ['auto_hunt', 19]);
    return `<panel>\nid ${id}_bg\n${rect(x, y, w, h)}\nlayer 10\nintersect false\n${img(b[0], b[1])}\n</panel>\n`
      + `<edit>\nid ${id}\n${rect(x + 3, y + 1, w - 6, h - 2)}\nlayer 20\nfont_type 2\ninput_type ${digits ? 2 : 0}\nalign ${align}\ncolor ffffffff\nmultiline ${multi}${max ? `\nmaxlength ${max}` : ''}\n</edit>`;
  };
  const combo = (id, x, y, w, h = 18, rows = 18) => `<panel>\nid ${id}_bg\n${rect(x, y, w, h)}\nlayer 10\nintersect false\n${img('auto_hunt', 17)}\n</panel>\n`
    + `<combobox>\nid ${id}\n${rect(x, y, w, h)}\nlayer 40\nborder false\n${title({ color: 'ffffffff', font: 2 })}\n${title({ state: 'check', color: 'ffffd24a', font: 2 })}\n`
    + `<iteminfo>\nrect 2 0 ${w - 18} ${h}\n</iteminfo>\n<nodeinfo>\nselrect 0 0 ${Math.max(w, 180)} ${rows}\nbtnrect ${w - 15} ${Math.round((h - 12) / 2)} 12 12\n${img('party', 4, 'board_body')}\n${img('etc_01', 15, 'btn_none')}\n${img('etc_01', 16, 'btn_over')}\n${img('etc_01', 17, 'btn_down')}\n</nodeinfo>\n</combobox>`;
  const check = (id, x, y, text, w = 150) => `<checkbox>\nid ${id}\n${rect(x, y, w, 18)}\nlayer 30\n${img('etc_01', 303)}\n${img('etc_01', 304, 'check')}\n${title({ color: 'ffd8d8d8', font: 2, pos: '2 3', text })}\n</checkbox>`;
  const board = (id, x, y, w, h, inner = '', opts = {}) => panel(id, x, y, w, h, `${img('bigmap', 61)}\n${inner}`, opts);
  const header = (id, x, y, w, text) => `${label(id, x, y, w, 14, text, { color: 'ffffcc66', font: 4 })}\n<panel>\nid ${id}_line\n${rect(x, y + 15, w, 2)}\nlayer 15\nintersect false\n${img('StorePurchase', 2)}\n</panel>`;
  const row = (id, y, text, w = 88) => label(`cap_${id}`, 10, y + 2, w, 14, text, { color: 'ffc0c0c0' });

  // ------------------------------------------------------------------ window + frame
  push('<window>', 'name itembuilder', rect(0, 0, W, H), 'titlerect 0 0 860 34', 'layer 100');
  panel('pan_bg', 0, 0, W, H, img('etc_01', 87), { layer: 0 });
  push(label('lbl_title', 0, 11, W, 18, 'Item Builder', { align: 'center', font: 4, color: 'fff4d27a', layer: 5 }));
  push(label('lbl_status', 20, 13, 400, 14, '', { color: 'ffb4b4b4', layer: 5 }));
  push(`<button>\nid btn_close\n${rect(W - 28, 9, 19, 19)}\nlayer 50\n${img('etc_01', 315)}\n${img('etc_01', 316, 'over')}\n${img('etc_01', 317, 'down')}\n</button>`);

  // ------------------------------------------------------------------ left: pickers
  PICK_TABS.forEach(([k, t], i) => push(tab(`btn_pick_${k}`, 12 + i * 50, 44, 50, t)));
  board('pan_pick', 12, 69, 250, 452, [
    edit('edit_search', 6, 6, 180, 20, { max: 60 }),
    button('btn_search', 190, 6, 54, 20, 'Find', { small: true }),
    combo('com_pickfilter', 6, 30, 238, 18),
    `<panel>\nid pan_listbg\n${rect(6, 52, 238, 352)}\nlayer 5\nintersect false\n${img('pcpop', 79)}\n</panel>`,
    `<listbox>\nid lst_pick\n${rect(8, 54, 234, 348)}\nlayer 20\nnodeheight 16\noffset 3\n${title({ color: 'ffdcdcdc', font: 2 })}\n${title({ state: 'over', color: 'ffffffff', font: 2 })}\n${title({ state: 'check', color: 'ffffd24a', font: 2 })}\n${img('common', 1, 'check', '50b48c3c')}\n`
      + `<vscroll>\nid lst_pick_scroll\n${rect(222, 0, 10, 348)}\nlayer 30\nmaxvalue 0\nbuttontick 1\n`
      + `<button>\nid lst_pick_scroll_upbtn\nrect 0 0 10 6\ntype 1\nlayer 100\n${img('new_StorePurchase', 8)}\n${img('new_StorePurchase', 9, 'over')}\n${img('new_StorePurchase', 10, 'down')}\n${img('new_StorePurchase', 8, 'disable')}\n</button>\n`
      + `<button>\nid lst_pick_scroll_downbtn\nrect 0 342 10 6\ntype 1\nlayer 100\n${img('new_StorePurchase', 11)}\n${img('new_StorePurchase', 12, 'over')}\n${img('new_StorePurchase', 13, 'down')}\n${img('new_StorePurchase', 11, 'disable')}\n</button>\n`
      + `<panel>\nid lst_pick_scroll_bar\nrect 0 6 10 36\nmoveable true\nlayer 100\n${img('new_StorePurchase', 14)}\n${img('new_StorePurchase', 15, 'over')}\n</panel>\n</vscroll>\n</listbox>`,
    label('lbl_pickinfo', 6, 408, 238, 14, '', { color: 'ff9a9a9a' }),
    button('btn_pick_use', 6, 425, 116, 22, 'Use'),
    button('btn_pick_clone', 128, 425, 116, 22, 'Clone'),
  ].join('\n'));

  // ------------------------------------------------------------------ middle: editor pages
  PAGES.forEach(([k, t], i) => push(tab(`btn_tab_${k}`, 274 + i * 82, 44, 82, t)));
  const page = (k, inner) => board(`pan_page_${k}`, 274, 69, 330, 452, inner.join('\n'), { visible: k === 'general' });
  // General
  {
    const I = [];
    I.push(row('name', 10, 'Name'), edit('edit_name', 100, 8, 220, 18, { max: 100 }));
    I.push(row('desc', 34, 'Description'), edit('edit_desc', 100, 32, 220, 54, { multi: true, max: 1000, bg: ['bigmap', 61] }));
    I.push(row('kind', 92, 'Kind'), combo('com_kind', 100, 90, 220, 18));
    I.push(row('slot', 114, 'Slot'), label('lbl_slot', 100, 116, 220, 14, '', { color: 'ffffffff' }));
    I.push(row('rank', 134, 'Rank'), combo('com_rank', 100, 132, 220, 18));
    I.push(row('grade', 156, 'Spawn grade'), combo('com_grade', 100, 154, 220, 18));
    I.push(row('classes', 180, 'Classes'), button('btn_cls_all', 100, 177, 60, 20, 'All', { small: true }), button('btn_cls_none', 164, 177, 60, 20, 'None', { small: true }));
    for (let c = 0; c < 15; c++) I.push(check(`chk_cls_${c}`, 10 + (c >= 8 ? 160 : 0), 202 + (c % 8) * 18, classNames[c] || `Class ${c}`, 155));
    I.push(row('price', 356, 'Price (dil)'), edit('edit_price', 100, 354, 80, 18, { digits: true, max: 10 }), label('lbl_sell', 190, 358, 44, 14, 'Sell', { color: 'ffc0c0c0' }), edit('edit_sell', 240, 354, 80, 18, { digits: true, max: 10 }));
    I.push(row('stack', 378, 'Stack size'), edit('edit_stack', 100, 376, 50, 18, { digits: true, max: 4, align: 'center' }), check('chk_trade', 190, 376, 'Tradeable', 130));
    I.push(row('size', 400, 'Size (cells)'), edit('edit_w', 100, 398, 34, 18, { digits: true, max: 1, align: 'center' }), label('lbl_x', 138, 402, 14, 14, 'x', { align: 'center' }), edit('edit_h', 154, 398, 34, 18, { digits: true, max: 1, align: 'center' }),
      label('lbl_sockets', 200, 402, 80, 14, 'Sockets', { color: 'ffc0c0c0' }), edit('edit_sockets', 286, 398, 34, 18, { digits: true, max: 1, align: 'center' }));
    I.push(check('chk_roll', 10, 424, 'Roll random options when spawned', 310));
    page('general', I);
  }
  // Stats
  {
    const I = [];
    const pairRow = (id, y, text) => { I.push(row(id, y, text, 118), edit(`edit_${id}0`, 130, y - 2, 80, 18, { digits: true, max: 7, align: 'center' }), label(`lbl_${id}_to`, 212, y + 2, 26, 14, '~', { align: 'center' }), edit(`edit_${id}1`, 240, y - 2, 80, 18, { digits: true, max: 7, align: 'center' })); };
    const oneRow = (id, y, text, max = 7) => I.push(row(id, y, text, 118), edit(`edit_${id}`, 130, y - 2, 80, 18, { digits: true, max, align: 'center' }));
    I.push(header('hdr_req', 10, 8, 310, 'Requirements'));
    oneRow('reqlv', 32, 'Required level', 3);
    I.push(label('lbl_maxlv', 216, 34, 50, 14, 'Max', { color: 'ffc0c0c0', align: 'right' }), edit('edit_maxlv', 270, 30, 50, 18, { digits: true, max: 3, align: 'center' }));
    I.push(row('reqstat', 54, 'STR / DEX / SPR', 118), edit('edit_reqstr', 130, 52, 60, 18, { digits: true, max: 5, align: 'center' }), edit('edit_reqdex', 195, 52, 60, 18, { digits: true, max: 5, align: 'center' }), edit('edit_reqspr', 260, 52, 60, 18, { digits: true, max: 5, align: 'center' }));
    I.push(header('hdr_combat', 10, 80, 310, 'Attack / Defense'));
    pairRow('melee', 104, 'Melee damage');
    pairRow('magic', 126, 'Magic damage');
    pairRow('ranged', 148, 'Ranged damage');
    pairRow('def', 170, 'Defense');
    oneRow('pvpdmg', 192, 'PvP damage');
    oneRow('pvpdef', 214, 'PvP defense');
    oneRow('block', 236, 'Block rate %', 3);
    oneRow('range', 258, 'Attack range', 3);
    oneRow('speed', 280, 'Attack speed class', 2);
    oneRow('crit', 302, 'Critical rate', 5);
    oneRow('itemlv', 324, 'Upgrade level (+N)', 2);
    I.push(header('hdr_use', 10, 350, 310, 'Use effect / lifetime'));
    oneRow('usehp', 374, 'Restores HP');
    oneRow('usemp', 396, 'Restores MP');
    oneRow('period', 418, 'Lifetime (s, 0 = none)', 9);
    page('stats', I);
  }
  // Options
  {
    const I = [];
    I.push(header('hdr_opt', 10, 8, 310, 'Options (always active)'));
    for (let k = 0; k < 6; k++) I.push(combo(`com_opt_${k}`, 10, 30 + k * 22, 232, 18), edit(`edit_optv_${k}`, 250, 30 + k * 22, 70, 18, { max: 7, align: 'center' }));
    I.push(header('hdr_exo', 10, 166, 310, 'Additional options'));
    for (let k = 0; k < 7; k++) I.push(combo(`com_exo_${k}`, 10, 188 + k * 22, 232, 18), edit(`edit_exov_${k}`, 250, 188 + k * 22, 70, 18, { max: 7, align: 'center' }));
    I.push(header('hdr_set', 10, 346, 310, 'Set bonus'));
    I.push(combo('com_set', 10, 368, 310, 18));
    I.push(label('lbl_setinfo', 10, 392, 310, 56, '', { color: 'ff9ad0ff', multiline: true }));
    page('options', I);
  }
  // Look
  {
    const I = [];
    I.push(header('hdr_model', 10, 8, 310, 'Equipped model'));
    I.push(row('lookclass', 32, 'Model for'), combo('com_lookclass', 100, 30, 220, 18));
    I.push(row('mesh', 54, 'Mesh'), label('lbl_mesh', 100, 54, 220, 14, '-', { color: 'ffffffff' }));
    I.push(row('tpack', 72, 'Texture pack'), label('lbl_tpack', 100, 72, 220, 14, '-', { color: 'ffb4b4b4' }));
    I.push(row('mat', 92, 'Material'), combo('com_mat', 100, 90, 60, 18), label('lbl_tex', 166, 92, 154, 14, '-', { color: 'ffffffff' }));
    I.push(button('btn_tex_reset', 100, 112, 105, 20, 'Reset texture', { small: true }), button('btn_mesh_clear', 215, 112, 105, 20, 'No model', { small: true }));
    I.push(header('hdr_left', 10, 140, 310, 'Second (left hand) model'));
    I.push(row('left', 164, 'Mesh'), label('lbl_left', 100, 164, 150, 14, '-', { color: 'ffffffff' }), button('btn_left_clear', 255, 160, 65, 20, 'Clear', { small: true }));
    I.push(header('hdr_inv', 10, 186, 310, 'Inventory model (icon)'));
    I.push(row('inv', 210, 'Mesh'), label('lbl_inv', 100, 210, 220, 14, '-', { color: 'ffffffff' }));
    I.push(button('btn_inv_same', 100, 228, 105, 20, 'Use game model', { small: true }), button('btn_inv_clear', 215, 228, 105, 20, 'Default', { small: true }));
    I.push(header('hdr_act', 10, 256, 310, 'Animation (legend weapons / wings)'));
    I.push(row('action', 280, 'Action table'), label('lbl_action', 100, 280, 150, 14, '-', { color: 'ffffffff' }), button('btn_action_clear', 255, 276, 65, 20, 'Remove', { small: true }));
    I.push(header('hdr_target', 10, 302, 310, 'Pickers and keys apply to'));
    I.push(combo('com_target', 10, 324, 310, 18));
    I.push(label('lbl_meshkey', 10, 348, 200, 14, 'Mesh key (mesh/...)', { color: 'ffc0c0c0' }), edit('edit_meshkey', 10, 364, 250, 18, { max: 200 }), button('btn_meshkey', 264, 363, 56, 20, 'Set', { small: true }));
    I.push(label('lbl_texkey', 10, 388, 200, 14, 'Texture key (texture/...)', { color: 'ffc0c0c0' }), edit('edit_texkey', 10, 404, 250, 18, { max: 200 }), button('btn_texkey', 264, 403, 56, 20, 'Set', { small: true }));
    I.push(button('btn_meshy',10,428,160,22,'Import Meshy GLB',{small:true}));
    page('look', I);
  }

  // ------------------------------------------------------------------ right: preview
  MODES.forEach(([k, t], i) => push(tab(`btn_mode_${k}`, 616 + i * 90, 44, 90, t)));
  board('pan_preview', PREVIEW.x, PREVIEW.y, PREVIEW.w, PREVIEW.h, [
    `<panel>\nid pan_view\n${rect(4, 4, PREVIEW.w - 8, PREVIEW.h - 8)}\nlayer 5\n</panel>`,
    label('lbl_pvstatus', 8, PREVIEW.h - 22, PREVIEW.w - 16, 14, '', { color: 'ffffd24a', layer: 40 }),
    label('lbl_pvhint', 8, 8, PREVIEW.w - 16, 14, 'drag: turn - wheel: zoom', { color: 'ff707070', layer: 40 }),
  ].join('\n'));
  push(combo('com_pvclass', 616, 395, 150, 18), combo('com_pvanim', 772, 395, 116, 18));
  board('pan_iconbox', 616, 419, 100, 102, `<panel>\nid pan_icon\n${rect(18, 3, 64, 96)}\nlayer 10\n</panel>`);
  const info = ['index', 'kind', 'slot', 'size', 'lib'];
  info.forEach((k, i) => push(label(`lbl_info_${k}`, 724, 421 + i * 20, 164, 14, '', { color: i === 0 ? 'ffffd24a' : 'ffc8c8c8' })));

  // ------------------------------------------------------------------ bottom buttons
  BUTTONS.forEach(([k, t], i) => push(button(`btn_${k}`, 12 + i * 110, 560, 104, 23, t)));
  push('</window>');
  return L.join('\n');
}

/** The window spec (built once). */
export function builderSpec(classNames) {
  const parsed = parseTagScript(builderScript(classNames), { file: 'itembuilder/ui_itembuilder' });
  const specs = buildSpecs(parsed.roots, { file: 'itembuilder/ui_itembuilder' });
  if (parsed.warnings.length || specs.warnings.length) console.warn('[itembuilder] script warnings', [...parsed.warnings, ...specs.warnings].slice(0, 10));
  return specs.windows[0];
}
