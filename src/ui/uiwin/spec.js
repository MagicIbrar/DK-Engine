// Window-script node trees (script.js) -> normalised window / control specs used by the renderer.
// Pure (no DOM). See docs/UIWIN.md "Spec" for every field.
import { parseTagScript, parseLegacyScript, detectFormat, splitTokens } from './script.js';

/** Control tags that carry no own box: they are properties of their parent. */
export const PROPERTY_TAGS = new Set(['image', 'title', 'iteminfo', 'nodeinfo', 'iconimg', 'iconimage', 'classimage', 'node', 'element']);
/** Every control tag the game scripts use (docs/formats/ui.md, survey of all 714 files). */
export const CONTROL_TAGS = new Set([
  'panel', 'label', 'button', 'checkbox', 'edit', 'textbox', 'chattextbox', 'vscroll', 'slidebar', 'combobox', 'listbox',
  'processbar', 'imagenumber', 'itemslot', 'item', 'quickslot', 'timerpanel', 'treectrl', 'multitreectrl', 'skilltree',
  'messengertree', 'tab', 'freeboardctrl', 'maillist', 'casebox', 'emoti', 'pivot', 'slotctrl', 'noticectrl', 'window',
]);

const H_ANCHORS = new Set(['left', 'center', 'right', 'inverse', 'cetner']);
const V_ANCHORS = new Set(['top', 'center', 'bottom', 'inverse', 'caption', 'cetner']);

export const num = (v, d = 0) => { const n = Number(v); return Number.isFinite(n) ? n : d; };
/** 'true'/'TRUE' -> true, 'false'/'FALSE'/'flase' -> false, anything else -> dflt. */
export function bool(tokens, dflt) {
  const v = String(tokens?.[0] ?? '').toLowerCase();
  if (/^true/.test(v) || v === '1') return true;
  if (/^(false|flase|flse)/.test(v) || v === '0') return false;
  return dflt;
}
const nums = (tokens, n = 4) => { const a = (tokens || []).map(Number).filter(Number.isFinite); while (a.length < n) a.push(0); return a.slice(0, n); };

/** AARRGGBB / 0xAARRGGBB (window-script colour) -> [a, r, g, b] 0..255, or null. */
export function parseARGB(v) {
  if (v == null) return null;
  const h = String(v).trim().replace(/^0x/i, '');
  if (!/^[0-9a-f]{1,8}$/i.test(h)) return null;
  const p = h.padStart(8, '0');
  return [parseInt(p.slice(0, 2), 16), parseInt(p.slice(2, 4), 16), parseInt(p.slice(4, 6), 16), parseInt(p.slice(6, 8), 16)];
}

/** 'position' tokens -> anchor ['left'|'center'|'right'|'inverse', 'top'|'center'|'bottom'|'inverse'] or null. */
export function parseAnchor(tokens) {
  if (!tokens || tokens.length < 2) return null;
  let h = String(tokens[0]).toLowerCase(), v = String(tokens[1]).toLowerCase();
  if (!H_ANCHORS.has(h) || !V_ANCHORS.has(v)) return null;
  if (h === 'cetner') h = 'center';
  if (v === 'cetner') v = 'center';
  if (v === 'caption') v = 'top';
  return [h, v];
}

/** 'align' tokens -> {h, v}. 'center' = horizontal centre, 'center center' = both, numeric 0/1 (edit) = left/center. */
export function parseAlign(tokens) {
  if (!tokens || !tokens.length) return null;
  const a = String(tokens[0]).toLowerCase(), b = tokens[1] != null ? String(tokens[1]).toLowerCase() : null;
  const hmap = { left: 'left', center: 'center', right: 'right', 0: 'left', 1: 'center', 2: 'right' };
  const h = hmap[a] || 'left';
  const v = b === 'center' ? 'center' : b === 'bottom' ? 'bottom' : 'top';
  return { h, v };
}

function imageKey(tokens) {
  const k = String(tokens?.[0] ?? 'none').toLowerCase();
  return k === '0' || k === '' ? 'none' : k;
}

function parseImageNode(n) {
  const p = n.props;
  const img = {
    key: imageKey(p.key || p.state),
    screen: p.screen ? String(p.screen[0]) : null,
    index: p.index ? num(p.index[0], -1) : -1,
    color: p.color ? parseARGB(p.color[0]) : null,
    tag: n.tag,
  };
  if (p.effect) img.effect = p.effect.map(Number);
  return img;
}

/** Text reference of a title/label: literal text, or a string-table reference {group, cate, code}. */
export function textRef(p) {
  if (p.text2 && p.text2.length >= 2) return { group: 'NORMAL', cate: num(p.text2[0]), code: num(p.text2[1]) };
  if (p.text3 && p.text3.length >= 2) return { group: 'SYSTEM', cate: num(p.text3[0]), code: num(p.text3[1]) };
  if (p.text_pet && p.text_pet.length >= 2) return { group: 'PET', cate: num(p.text_pet[0]), code: num(p.text_pet[1]) };
  return null;
}

function parseTitleNode(n) {
  const p = n.props;
  const t = { state: p.state ? String(p.state[0]).toLowerCase() : 'none' };
  if (t.state === '0') t.state = 'none';
  if (p.color) t.color = parseARGB(p.color[0]);
  if (p.fontindex) t.font = num(p.fontindex[0], 2);
  if (p.position) t.pos = nums(p.position, 2);
  if (p.text) t.text = p.text.join(' ');
  const ref = textRef(p);
  if (ref) t.ref = ref;
  if (p.align) t.align = parseAlign(p.align);
  if (p.lineheight) t.lineheight = num(p.lineheight[0]);
  if (p.multiline) t.multiline = bool(p.multiline, false);
  if (p.effect) t.effect = p.effect.map(Number);
  if (p.usefreetype) t.freetype = bool(p.usefreetype, false);
  return t;
}

let uid = 0;

/** Combobox <item> caption reference: `string cate code` (NORMAL, e.g. the option window's quality lists) or text2/text3. */
function itemRef(p) {
  if (p.string && p.string.length >= 2) return { ref: { group: 'NORMAL', cate: num(p.string[0]), code: num(p.string[1]) } };
  const r = textRef(p);
  return r ? { ref: r } : {};
}

/** Deep copy of a control spec (for clone). */
function cloneSpec(s) {
  return {
    ...s,
    rect: s.rect.slice(),
    images: s.images.map(i => ({ ...i })),
    titles: s.titles.map(t => ({ ...t })),
    props: { ...s.props },
    extra: s.extra ? JSON.parse(JSON.stringify(s.extra)) : s.extra,
    children: s.children.map(cloneSpec),
    uid: ++uid,
  };
}

/**
 * Build a control spec from a node. `ctx.byId` resolves `clone` sources (latest definition wins),
 * ctx.warnings collects problems.
 */
function buildControl(n, ctx, parentType) {
  const p = n.props;
  let base = null;
  if (p.clone && p.clone[0]) {
    const cid = String(p.clone[0]).toLowerCase();
    let src = ctx.byId.get(cid);
    if (!src) {
      // defined later in the file (forward clone): build that node on its own first
      const raw = ctx.rawById.get(cid);
      if (raw && raw !== n && !ctx.building.has(raw)) {
        ctx.building.add(raw);
        src = buildControl(raw, { ...ctx, byId: new Map(ctx.byId), warnings: [] }, parentType);
        ctx.building.delete(raw);
      }
    }
    if (src) base = cloneSpec(src);
    else ctx.warnings.push(`${ctx.file}:${n.line} clone source "${p.clone[0]}" not found`);
  }
  const s = base || {
    type: n.tag, id: '', rect: [0, 0, 0, 0], anchor: null, offset: null, layer: 0, enable: true, visible: true,
    intersect: true, moveable: false, align: null, images: [], titles: [], props: {}, children: [], extra: null,
  };
  s.type = n.tag;
  s.uid = ++uid;
  s.line = n.line;
  s.file = ctx.file;
  if (base) s.cloneOf = String(p.clone[0]);
  s.id = p.id ? String(p.id[0] ?? '') : (base ? s.id : '');
  for (const [k, v] of n.order) s.props[k] = v;
  // a clone that pins an axis itself drops the source's pins of that axis (ui_charselectwnd.txt btn_exit = clone of
  // the right-aligned btn_delete_char, placed with align_left 10)
  if (base) {
    const own = new Set(n.order.map(([k]) => k));
    for (const ax of [['align_left', 'align_right', 'center_h'], ['align_top', 'align_bottom', 'center_v']]) {
      if (ax.some(k => own.has(k))) for (const k of ax) if (!own.has(k)) delete s.props[k];
    }
  }
  if (p.rect) s.rect = nums(p.rect, 4);
  if (p.position) { const a = parseAnchor(p.position); if (a) s.anchor = a; else if (p.position.length >= 2) s.offset = nums(p.position, 2); }
  if (p.layer) s.layer = num(p.layer[0], s.layer);
  if (p.enable) s.enable = bool(p.enable, s.enable);
  if (p.visible) s.visible = bool(p.visible, s.visible);
  if (p.intersect) s.intersect = bool(p.intersect, s.intersect);
  if (p.moveable) s.moveable = bool(p.moveable, s.moveable);
  if (p.align) s.align = parseAlign(p.align);

  // property children: images, titles, combobox iteminfo/nodeinfo, board nodes, casebox icons, slot class images
  const ownImages = [], ownTitles = [], kids = [];
  for (const c of n.children) {
    if (c.tag === 'image' || c.tag === 'iconimg' || c.tag === 'iconimage' || c.tag === 'classimage') ownImages.push(parseImageNode(c));
    else if (c.tag === 'title') ownTitles.push(parseTitleNode(c));
    else if (c.tag === 'iteminfo') { (s.extra ||= {}).iteminfo = [...(s.extra?.iteminfo || []), { rect: nums(c.props.rect, 4), items: c.children.filter(x => x.tag === 'item').map(x => ({ id: x.props.id?.[0], rect: nums(x.props.rect, 4), text: x.props.text?.join(' '), index: num(x.props.index?.[0]), data: num(x.props.data?.[0]), ...itemRef(x.props) })) }]; }
    else if (c.tag === 'nodeinfo') {
      const ni = { selrect: nums(c.props.selrect, 4), btnrect: nums(c.props.btnrect, 4), images: c.children.filter(x => x.tag === 'image').map(parseImageNode) };
      (s.extra ||= {}).nodeinfo = ni;
    } else if (c.tag === 'node') {
      const np = c.props;
      const node = {
        state: num(np.state?.[0]), width: num(np.width?.[0]), sort: bool(np.sort, false), intersect: bool(np.intersect, true),
        ref: np.text2 ? { group: 'NORMAL', cate: num(np.text2[0]), code: num(np.text2[1]) } : null,
        tooltip: np.tooltip ? { group: 'NORMAL', cate: num(np.tooltip[0]), code: num(np.tooltip[1]) } : null,
        align: np.align ? parseAlign(np.align) : null,
        elements: c.children.filter(x => x.tag === 'element').map(x => ({
          type: x.props.type?.[0], id: x.props.id?.[0], align: x.props.align ? parseAlign(x.props.align) : null,
          intersect: bool(x.props.intersect, true), size: x.props.size ? nums(x.props.size, 2) : null, width: x.props.width ? num(x.props.width[0]) : null,
          images: x.children.filter(y => y.tag === 'image').map(parseImageNode), titles: x.children.filter(y => y.tag === 'title').map(parseTitleNode),
        })),
      };
      ((s.extra ||= {}).nodes ||= []).push(node);
    } else if (c.tag === 'window') {
      kids.push(buildWindow(c, ctx, true));
    } else kids.push(c);
  }
  // merge images by key and titles by state over the clone source
  for (const im of ownImages) {
    const i = s.images.findIndex(x => x.key === im.key && x.tag === im.tag);
    if (i >= 0 && base) s.images[i] = { ...s.images[i], ...Object.fromEntries(Object.entries(im).filter(([, v]) => v != null && v !== -1)) };
    else s.images.push(im);
  }
  for (const t of ownTitles) {
    const i = s.titles.findIndex(x => x.state === t.state);
    if (i >= 0 && base) {
      const merged = { ...s.titles[i], ...t };
      if (t.ref || t.text != null) { merged.ref = t.ref || null; merged.text = t.text; if (!t.ref) delete merged.ref; if (t.text == null) delete merged.text; }
      s.titles[i] = merged;
    } else s.titles.push(t);
  }
  const addTooltip = (key, group) => { if (p[key] && p[key].length >= 2) s.tooltip = { group, cate: num(p[key][0]), code: num(p[key][1]) }; };
  addTooltip('tooltip', 'NORMAL');
  addTooltip('tooltip_pet', 'PET');
  if (p.string && p.string.length >= 2) s.stringRef = { group: 'NORMAL', cate: num(p.string[0]), code: num(p.string[1]) };
  if (p.text) s.text = p.text.join(' ');
  const tr = textRef(p);
  if (tr) s.ref = tr;
  if (p.init_text2 && p.init_text2.length >= 2) s.initRef = { group: 'NORMAL', cate: num(p.init_text2[0]), code: num(p.init_text2[1]), color: parseARGB(p.init_text2[2]) };

  if (s.id) ctx.byId.set(s.id.toLowerCase(), s);
  for (const c of kids) {
    if (c.kind === 'window') { s.children.push(c); continue; }
    if (PROPERTY_TAGS.has(c.tag)) continue;
    s.children.push(buildControl(c, ctx, s.type));
  }
  return s;
}

/** Build a window spec from a <window> node. */
function buildWindow(n, ctx, nested = false) {
  const p = n.props;
  const w = {
    kind: 'window', type: 'window', uid: ++uid, file: ctx.file, line: n.line, nested,
    name: p.name ? String(p.name[0]) : '', id: p.id ? String(p.id[0]) : '',
    rect: p.rect ? nums(p.rect, 4) : null,
    anchor: parseAnchor(p.position),
    center: p.center_h || p.center_v ? [num(p.center_h?.[0]), num(p.center_v?.[0])] : null,
    edges: null,
    titlerect: p.titlerect ? nums(p.titlerect, 4) : null,
    layer: num(p.layer?.[0], 100),
    layertype: p.layertype ? String(p.layertype[0]).toLowerCase() : 'normal',
    enable: bool(p.enable, true), visible: bool(p.visible, true),
    alwaysontop: bool(p.alwaysontop, false) || bool(p.always_top_ui, false),
    modal: bool(p.modal, false), moveable: bool(p.moveable, true), intersect: bool(p.intersect, true),
    props: Object.fromEntries(n.order), images: [], titles: [], children: [],
  };
  for (const e of ['top', 'left', 'right', 'bottom']) if (p[`align_${e}`]) (w.edges ||= {})[e] = num(p[`align_${e}`][0]);
  for (const c of n.children) {
    if (c.tag === 'image') w.images.push(parseImageNode(c));
    else if (c.tag === 'title') w.titles.push(parseTitleNode(c));
    else if (c.tag === 'window') w.children.push(buildWindow(c, ctx, true));
    else if (!PROPERTY_TAGS.has(c.tag)) w.children.push(buildControl(c, ctx, 'window'));
  }
  // the auction / personal shop windows carry no titlerect property: their drag strip is the <pivot> "pivot_titlerect" (rect 0 0 340 30)
  if (!w.titlerect) {
    const pv = w.children.find(k => k.type === 'pivot' && String(k.id).toLowerCase() === 'pivot_titlerect' && Array.isArray(k.rect));
    if (pv) w.titlerect = [pv.rect[0], pv.rect[1], pv.rect[0] + pv.rect[2], pv.rect[1] + pv.rect[3]];
  }
  return w;
}

/**
 * Normalise parsed 'tags' roots into specs.
 * @returns {{ windows: WindowSpec[], fragments: ControlSpec[], warnings: string[] }}
 *   fragments = top-level controls of template files (loadchild targets such as ui_invenwnd_base.txt)
 */
export function buildSpecs(roots, { file = '', warnings = [] } = {}) {
  const ctx = { file, byId: new Map(), rawById: new Map(), building: new Set(), warnings };
  const index = (n) => {
    const id = n.props?.id?.[0];
    if (id && !PROPERTY_TAGS.has(n.tag) && !ctx.rawById.has(String(id).toLowerCase())) ctx.rawById.set(String(id).toLowerCase(), n);
    for (const c of n.children || []) index(c);
  };
  roots.forEach(index);
  const windows = [], fragments = [];
  for (const n of roots) {
    // a doubled "<window>" line wraps the real window in an empty one (msgbox/ui_errorbox.txt, ui_resultbox.txt, ...):
    // hoist the inner window(s)
    if (n.tag === 'window' && n.order.length === 0 && n.children.some(c => c.tag === 'window')) {
      const inner = n.children.filter(c => c.tag === 'window');
      const rest = n.children.filter(c => c.tag !== 'window');
      inner[0].children.push(...rest);
      for (const w of inner) windows.push(buildWindow(w, ctx));
      ctx.warnings.push(`${file}:${n.line} empty <window> wrapper hoisted`);
      continue;
    }
    if (n.tag === 'window') windows.push(buildWindow(n, ctx));
    else if (!PROPERTY_TAGS.has(n.tag)) fragments.push(buildControl(n, ctx, null));
  }
  return { windows, fragments, warnings };
}

// ------------------------------------------------------------------------------------------ includes
/** 'UI/Game2/Inven/x.txt' -> 'script/ui/game2/inven/x.txt' (data key). */
export function scriptKey(path) {
  let p = String(path).trim().replace(/\\/g, '/').replace(/^\/+/, '').toLowerCase();
  if (p.startsWith('script/')) return p;
  if (p.startsWith('ui/')) return `script/${p}`;
  return `script/ui/${p}`;
}

/**
 * Resolve every `loadchild` (and its `loadchildname <VAR> value` template variables) by parsing the child file
 * and appending its top-level nodes to the node that asked for it. Recursive, cycle-safe.
 * @param roots   parsed nodes (mutated)
 * @param getText async (dataKey) => text|null
 */
export async function expandIncludes(roots, getText, { file = '', warnings = [], depth = 0, vars = null } = {}) {
  const visit = async (n) => {
    for (const c of n.children) await visit(c);
    const lc = n.order.filter(([k]) => k === 'loadchild');
    if (!lc.length) return;
    const v = { ...(vars || {}) };
    for (const [k, t] of n.order) if (k === 'loadchildname' && t.length >= 2) v[t[0]] = t.slice(1).join(' ');
    for (const [, t] of lc) {
      const key = scriptKey(t.join(' '));
      if (depth > 6) { warnings.push(`${file}: loadchild depth limit at ${key}`); continue; }
      const text = await getText(key);
      if (text == null) { warnings.push(`${file}:${n.line} loadchild missing ${key}`); continue; }
      const parsed = parseTagScript(text, { file: key, vars: v });
      warnings.push(...parsed.warnings);
      await expandIncludes(parsed.roots, getText, { file: key, warnings, depth: depth + 1, vars: v });
      for (const r of parsed.roots) { r.fromFile = key; n.children.push(r); }
    }
  };
  for (const r of roots) await visit(r);
  return roots;
}

// ------------------------------------------------------------------------------------------ legacy tool UI
/**
 * Legacy create_control scripts -> one window spec. Controls: type = kind, rect from control_drawpoint/drawsize,
 * legacy = { image: {flags, tex, x, y, w, h}, div: [axis, n], text: {x, y, text}, textColor, font, color, style, group, ... }.
 */
export function buildLegacySpec(parsed, { file = '' } = {}) {
  const wp = parsed.window.props;
  const conv = (n) => {
    const p = n.props;
    const pt = nums(p.control_drawpoint, 2), sz = nums(p.control_drawsize, 2);
    const s = {
      type: n.tag, legacyKind: n.tag, id: p.id?.[0] || '', uid: ++uid, file, line: n.line,
      rect: [pt[0], pt[1], sz[0], sz[1]], anchor: p.control_alignaxis ? parseAnchor(p.control_alignaxis) : null,
      layer: 0, enable: bool(p.control_enable, true), visible: bool(p.control_visible, true), intersect: true, moveable: false,
      align: null, images: [], titles: [], props: Object.fromEntries(n.order), children: [], legacy: {},
    };
    const L = s.legacy;
    if (p.control_image) { const t = p.control_image; L.image = { flags: t[0], tex: t[1], x: num(t[2]), y: num(t[3]), w: num(t[4]), h: num(t[5]) }; }
    if (p.control_drawdiv) L.div = [String(p.control_drawdiv[0]), num(p.control_drawdiv[1])];
    if (p.control_text) L.text = { x: num(p.control_text[0]), y: num(p.control_text[1]), text: p.control_text.slice(2).join(' ') };
    if (p.control_textcolor) L.textColor = nums(p.control_textcolor, 3);
    if (p.control_textfont) L.font = String(p.control_textfont[0]);
    if (p.control_color) L.color = { on: bool(p.control_color, false), argb: nums(p.control_color.slice(1), 4) };
    if (p.control_style) L.style = String(p.control_style[0]);
    if (p.control_group) L.group = num(p.control_group[0]);
    if (p.control_tab) L.tab = num(p.control_tab[0]);
    L.add = n.order.filter(([k]) => k === 'addcontrol_image').map(([, t]) => (t[1] === 'color' ? { part: t[0], color: nums(t.slice(2), 4) } : { part: t[0], tex: t[1], x: num(t[2]), y: num(t[3]), w: num(t[4]), h: num(t[5]) }));
    if (p.addcontrol_drawsize) L.addSize = nums(p.addcontrol_drawsize, 2);
    if (p.addcontrol_drawpoint) L.addPoint = nums(p.addcontrol_drawpoint, 2);
    if (p.addcontrol_drawdiv) L.addDiv = [String(p.addcontrol_drawdiv[0]), num(p.addcontrol_drawdiv[1])];
    for (const k of Object.keys(p)) if (/^(cedit|cslidebar|ccombobox|clist)_/.test(k)) L[k] = p[k];
    s.children = n.children.map(conv);
    return s;
  };
  const pos = nums(wp.window_position, 2), size = nums(wp.window_size, 2);
  return {
    kind: 'window', type: 'window', legacy: true, uid: ++uid, file, line: 0, name: file.split('/').pop().replace(/\.txt$/i, ''), id: '',
    rect: [pos[0], pos[1], pos[0] + size[0], pos[1] + size[1]], anchor: wp.window_alignaxis ? parseAnchor(wp.window_alignaxis) : null,
    center: null, edges: null, titlerect: [0, 0, size[0], 20], layer: 100, layertype: 'normal', enable: true,
    visible: bool(wp.window_visible, true), alwaysontop: false, modal: false, moveable: true, intersect: true,
    props: Object.fromEntries(parsed.window.order), images: [], titles: [], children: parsed.roots.map(conv),
  };
}

// ------------------------------------------------------------------------------------------ one-stop
/**
 * Parse + include + normalise one script file.
 * @param key     data key ('script/ui/game2/msgbox/ui_msgbox.txt')
 * @param getText async (key) => text|null  (EUC-KR decoded)
 * @returns {Promise<{ key, format, windows, fragments, warnings, sprites? }>}
 */
export async function loadScriptSpecs(key, getText) {
  const text = await getText(key);
  if (text == null) return { key, format: 'missing', windows: [], fragments: [], warnings: [`missing ${key}`] };
  const format = detectFormat(text);
  const warnings = [];
  if (format === 'legacy') {
    const parsed = parseLegacyScript(text, { file: key });
    warnings.push(...parsed.warnings);
    return { key, format, windows: [buildLegacySpec(parsed, { file: key })], fragments: [], warnings };
  }
  if (format === 'table') return { key, format, windows: [], fragments: [], warnings };
  const parsed = parseTagScript(text, { file: key });
  warnings.push(...parsed.warnings);
  await expandIncludes(parsed.roots, getText, { file: key, warnings });
  const specs = buildSpecs(parsed.roots, { file: key, warnings });
  return { key, format, ...specs, warnings };
}

export { splitTokens };
