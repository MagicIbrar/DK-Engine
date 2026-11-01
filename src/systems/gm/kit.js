// Small DOM kit for the GM panel's dynamic content, drawn with the original UI art where the client has it
// (etc_01#2 basic button, etc_01#66 tooltip frame, etc_01#315-317 close button, the minimap atlas) and the client's
// Tahoma look everywhere else. Virtualised lists keep 95 000 items / 4 577 monsters smooth.
import { atlas } from '../../ui/atlas.js';
import { GMData } from './data.js';

const CSS = `
.gmk{position:absolute;pointer-events:auto;font:11px Tahoma,Verdana,"Segoe UI",sans-serif;color:#e8e0c8;-webkit-user-select:text;user-select:text}
.gmk *{box-sizing:border-box}
.gmk .row{display:flex;gap:6px;align-items:center;margin:3px 0;flex-wrap:wrap}
.gmk .col{display:flex;flex-direction:column;gap:4px}
.gmk .lbl{color:#c9b98a;min-width:74px}
.gmk .dim{color:#8f8a78}
.gmk .ok{color:#8fe07a}.gmk .bad{color:#ff7a62}.gmk .gold{color:#ffe38c}.gmk .blue{color:#9fd2ff}
.gmk h4{margin:6px 0 3px;color:#ffe38c;font:bold 11px Tahoma,Verdana,sans-serif;border-bottom:1px solid rgba(160,130,70,.45);padding-bottom:2px}
.gmk input[type=text],.gmk input[type=number],.gmk select,.gmk textarea{background:rgba(6,5,3,.85);color:#fff;border:1px solid #6b5a33;
  font:11px Tahoma,Verdana,sans-serif;height:19px;padding:1px 4px;outline:none;border-radius:0}
.gmk textarea{height:auto;resize:vertical;font:11px Consolas,"Courier New",monospace;white-space:pre}
.gmk input:focus,.gmk select:focus,.gmk textarea:focus{border-color:#d9b45a}
.gmk input[type=number]{width:70px}
.gmk input[type=checkbox]{accent-color:#d9b45a;margin:0 3px 0 0;vertical-align:-2px}
.gmk input[type=range]{accent-color:#d9b45a;width:140px}
.gmk .btn{display:inline-flex;align-items:center;justify-content:center;min-width:57px;height:19px;padding:0 8px;cursor:pointer;color:#dcdcdc;
  background:#3a3022 no-repeat;background-size:100% 100%;white-space:nowrap;border:0;font:11px Tahoma,Verdana,sans-serif;text-shadow:1px 1px 0 #000}
.gmk .btn:hover{color:#fff;filter:brightness(1.25)}
.gmk .btn:active{filter:brightness(.85)}
.gmk .btn.on{color:#ffe38c;filter:brightness(1.35) sepia(.4)}
.gmk .btn.big{height:22px;min-width:80px}
.gmk .btn:disabled{opacity:.45;cursor:default;filter:none}
.gmk input:disabled,.gmk select:disabled{opacity:.55;cursor:default}
.gmk .list{position:relative;overflow:auto;background:rgba(0,0,0,.45);border:1px solid #5a4a2a;scrollbar-color:#6b5a33 #120f0a;scrollbar-width:thin}
.gmk .list .sp{position:relative}
.gmk .list .r{position:absolute;left:0;right:0;height:18px;line-height:18px;padding:0 5px;white-space:nowrap;overflow:hidden;text-overflow:ellipsis;cursor:pointer;display:flex;gap:8px}
.gmk .list .r:hover{background:rgba(255,230,160,.10)}
.gmk .list .r.sel{background:rgba(217,180,90,.30);color:#fff}
.gmk .list .r .c{overflow:hidden;text-overflow:ellipsis;white-space:nowrap;flex:none}
.gmk .list .r .c.grow{flex:1 1 auto}
.gmk .scroll{overflow:auto;scrollbar-color:#6b5a33 #120f0a;scrollbar-width:thin}
.gmk .box{background:rgba(0,0,0,.38);border:1px solid rgba(110,90,50,.7);padding:5px 7px}
.gmk table{border-collapse:collapse;width:100%}
.gmk td,.gmk th{padding:1px 5px;text-align:left;white-space:nowrap;border-bottom:1px solid rgba(90,74,42,.35)}
.gmk th{color:#c9b98a;font-weight:bold;position:sticky;top:0;background:#16120c}
.gmk .pick{position:relative;display:inline-block}
.gmk .pick input{width:100%}
.gmk .pickdrop{position:absolute;z-index:50;left:0;top:20px;width:100%;min-width:260px;height:220px;background:#0d0b08;border:1px solid #9a7d45;box-shadow:0 4px 14px rgba(0,0,0,.7)}
.gmk .mm{position:relative;flex:none;background:#050505;border:1px solid #6b5a33;cursor:crosshair;overflow:hidden;background-size:100% 100%;image-rendering:auto}
.gmk .mm .dot{position:absolute;width:9px;height:9px;margin:-5px 0 0 -5px;border-radius:50%;border:1px solid #000;pointer-events:none}
.gmk .mm .cross{position:absolute;width:15px;height:15px;margin:-8px 0 0 -8px;pointer-events:none;border:2px solid #ffe38c;border-radius:50%;box-shadow:0 0 0 1px #000}
.gmk .tip{color:#8f8a78;font-size:10px}
.gmk .out{font:11px Consolas,"Courier New",monospace;white-space:pre-wrap;color:#ffedfc}
.gmk .grid2{display:grid;grid-template-columns:auto 1fr;gap:3px 8px;align-items:start}
.gmk .grid2>.lbl{padding-top:3px}
.gmk .tag{display:inline-block;padding:0 4px;border:1px solid #6b5a33;color:#c9b98a;font-size:10px;line-height:13px;margin-right:3px}
`;
let injected = false;
export function injectKitCSS() {
  if (injected || typeof document === 'undefined') return;
  injected = true;
  const s = document.createElement('style');
  s.id = 'gm-kit-css';
  s.textContent = CSS;
  document.head.appendChild(s);
}

/** h('div.row', {onclick}, children...) */
export function h(tag, attrs = null, ...kids) {
  const [t, ...cls] = String(tag).split('.');
  const el = document.createElement(t || 'div');
  if (cls.length) el.className = cls.join(' ');
  if (attrs) for (const [k, v] of Object.entries(attrs)) {
    if (v == null || v === false) continue;
    if (k === 'style' && typeof v === 'object') Object.assign(el.style, v);
    else if (k.startsWith('on') && typeof v === 'function') el.addEventListener(k.slice(2), v);
    else if (k === 'text') el.textContent = v;
    else if (k === 'html') el.innerHTML = v;
    else if (k in el && typeof v !== 'string') el[k] = v;
    else el.setAttribute(k, v === true ? '' : v);
  }
  for (const k of kids.flat(3)) if (k != null && k !== false) el.appendChild(k instanceof Node ? k : document.createTextNode(String(k)));
  return el;
}

/** Original basic button (etc_01#2 stretched). */
export function btn(text, onClick, opts = {}) {
  const b = h(`button.btn${opts.big ? '.big' : ''}`, { type: 'button', title: opts.title || null, onclick: (e) => { e.stopPropagation(); onClick?.(e); } }, text);
  if (opts.width) b.style.minWidth = `${opts.width}px`;
  atlas.sprite('etc_01', 2).then(s => { if (s) b.style.backgroundImage = `url("${s.url}")`; });
  return b;
}
export function toggleBtn(text, get, set, opts = {}) {
  // set() usually runs a command (async): repaint once it has landed too
  const b = btn(text, () => { set(!get()); paint(); setTimeout(paint, 120); setTimeout(paint, 600); }, opts);
  const paint = () => b.classList.toggle('on', !!get());
  b._paint = paint; paint();
  return b;
}

export function input(type = 'text', value = '', attrs = {}) { return h('input', { type, value: value ?? '', ...attrs }); }
export function select(options, value, onchange) {
  const s = h('select', { onchange: () => onchange?.(s.value) });
  for (const o of options) {
    const [v, t] = Array.isArray(o) ? o : [o, o];
    s.appendChild(h('option', { value: String(v) }, String(t)));
  }
  if (value != null) s.value = String(value);
  return s;
}
export function check(label, get, set) {
  const c = h('input', { type: 'checkbox' });
  c.checked = !!get();
  c.addEventListener('change', () => set(c.checked));
  const l = h('label', { style: { cursor: 'pointer', whiteSpace: 'nowrap' } }, c, label);
  l._sync = () => { c.checked = !!get(); };
  return l;
}

/**
 * Virtualised list. cols: [{key|get(row), width|'grow', cls, title}]. rows: array. onSelect(row), onDbl(row).
 * Returns {el, setRows(rows), selected, select(row), refresh()}.
 */
export function vlist({ height = 200, cols, onSelect, onDbl, rowH = 18 }) {
  const el = h('div.list', { style: { height: `${height}px` } });
  const sp = h('div.sp');
  el.appendChild(sp);
  const api = { el, rows: [], selected: null };
  const cell = (c, r) => {
    const v = c.get ? c.get(r) : r[c.key];
    const d = h(`span.c${c.width === 'grow' ? '.grow' : ''}${c.cls ? `.${c.cls}` : ''}`, null, v == null ? '' : v);
    if (c.width !== 'grow') d.style.width = `${c.width || 60}px`;
    return d;
  };
  let pool = [];
  const draw = () => {
    const n = api.rows.length;
    sp.style.height = `${n * rowH}px`;
    const top = el.scrollTop, vis = Math.ceil((el.clientHeight || height) / rowH) + 2;
    const i0 = Math.max(0, Math.floor(top / rowH) - 1), i1 = Math.min(n, i0 + vis);
    for (const p of pool) p.remove();
    pool = [];
    for (let i = i0; i < i1; i++) {
      const r = api.rows[i];
      const d = h('div.r', { title: cols.map(c => (c.get ? c.get(r) : r[c.key])).filter(x => x != null && typeof x !== 'object').join('  ') });
      if (r === api.selected) d.classList.add('sel');
      d.style.top = `${i * rowH}px`;
      for (const c of cols) d.appendChild(cell(c, r));
      d.addEventListener('click', () => { api.select(r); onSelect?.(r); });
      if (onDbl) d.addEventListener('dblclick', () => onDbl(r));
      sp.appendChild(d); pool.push(d);
    }
  };
  el.addEventListener('scroll', draw, { passive: true });
  api.setRows = (rows) => { api.rows = rows || []; el.scrollTop = 0; draw(); };
  api.select = (r) => { api.selected = r; draw(); };
  api.refresh = draw;
  api.scrollTo = (r) => { const i = api.rows.indexOf(r); if (i >= 0) { el.scrollTop = Math.max(0, i * rowH - 40); draw(); } };
  return api;
}

/**
 * Searchable picker over a GM list (input + dropdown). opts: {list, gmData, placeholder, width, filter, onPick(row), sub}
 * Returns {el, value (row), set(row), clear()}.
 */
export function picker({ list, data, placeholder = 'type to search…', width = 240, filter = null, onPick, cols }) {
  const wrap = h('div.pick', { style: { width: `${width}px` } });
  const inp = input('text', '', { placeholder, spellcheck: false });
  wrap.appendChild(inp);
  const api = { el: wrap, value: null, input: inp };
  let drop = null, vl = null, rows = null;
  const close = () => { drop?.remove(); drop = null; };
  const open = async () => {
    rows = rows || await data.list(list);
    if (!drop) {
      drop = h('div.pickdrop');
      vl = vlist({ height: 218, cols: cols || [{ key: 'id', width: 58, cls: 'dim' }, { key: 'name', width: 'grow' }, { key: 'sub', width: 150, cls: 'dim' }], onSelect: (r) => { api.set(r); close(); onPick?.(r); } });
      vl.el.style.border = '0';
      drop.appendChild(vl.el);
      wrap.appendChild(drop);
    }
    vl.setRows(GMData.search(rows, inp.value === (api.value?.name || '\u0000') ? '' : inp.value, 3000, filter));
  };
  inp.addEventListener('focus', open);
  inp.addEventListener('input', open);
  inp.addEventListener('keydown', (e) => {
    if (e.key === 'Enter' && vl?.rows?.length) { const r = vl.rows[0]; api.set(r); close(); onPick?.(r); }
    else if (e.key === 'Escape') { close(); }
    e.stopPropagation();
  });
  inp.addEventListener('blur', () => setTimeout(close, 180));
  api.set = (r) => { api.value = r || null; inp.value = r ? r.name : ''; inp.title = r ? `${r.id} · ${r.name} · ${r.sub}` : ''; };
  api.clear = () => api.set(null);
  api.setFilter = (f) => { filter = f; };
  return api;
}

/**
 * Minimap coordinate picker: the imagetable `minimap` sprite of a map (512 px = 512 cells, transposed: texel
 * u = FILE Z, v = FILE X, docs/formats/coords.md). onPick({x, z}).
 */
export function minimapPicker({ size = 256, onPick }) {
  const el = h('div.mm', { style: { width: `${size}px`, height: `${size}px` } });
  const cross = h('div.cross'); cross.style.display = 'none';
  const me = h('div.dot', { style: { background: '#40ff60' } }); me.style.display = 'none';
  const note = h('div', { style: { position: 'absolute', left: '4px', top: '3px', color: '#8f8a78', pointerEvents: 'none', textShadow: '1px 1px 0 #000' } });
  el.append(cross, me, note);
  const api = { el, map: null, cells: 512, point: null };
  const k = () => size / api.cells;
  api.setMap = async (map, cells = 512) => {
    api.map = map; api.cells = cells || 512;
    el.style.backgroundImage = '';
    note.textContent = `map ${map}`;
    const s = await atlas.sprite('minimap', Number(map)).catch(() => null);
    if (api.map !== map) return;
    if (s) el.style.backgroundImage = `url("${s.url}")`; else note.textContent = `map ${map}: no minimap in the client`;
  };
  api.setPoint = (p) => {
    api.point = p;
    if (!p) { cross.style.display = 'none'; return; }
    cross.style.display = '';
    cross.style.left = `${p.z * k()}px`; cross.style.top = `${p.x * k()}px`;
  };
  api.setPlayer = (p) => {
    if (!p) { me.style.display = 'none'; return; }
    me.style.display = '';
    me.style.left = `${p.z * k()}px`; me.style.top = `${p.x * k()}px`;
  };
  el.addEventListener('click', (e) => {
    const r = el.getBoundingClientRect();
    const sx = r.width / size, sy = r.height / size;
    const u = (e.clientX - r.left) / sx / k(), v = (e.clientY - r.top) / sy / k();
    const p = { x: Math.max(0, Math.min(api.cells - 1, v)), z: Math.max(0, Math.min(api.cells - 1, u)) };
    api.setPoint(p);
    onPick?.(p, e);   // the event too, so a page can act on Ctrl+click
  });
  return api;
}

/** A table from rows [[cells]] with a header. */
export function table(head, rows) {
  return h('table', null, h('thead', null, h('tr', null, head.map(x => h('th', null, x)))), h('tbody', null, rows.map(r => h('tr', null, r.map(c => h('td', null, c))))));
}

/** Paint an original sprite as the background of an element. */
export function sprite(el, group, index) { atlas.sprite(group, index).then(s => { if (s) { el.style.backgroundImage = `url("${s.url}")`; el.style.backgroundSize = '100% 100%'; el.style.backgroundRepeat = 'no-repeat'; } }); return el; }
