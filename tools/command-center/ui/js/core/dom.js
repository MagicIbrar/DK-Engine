// Tiny DOM helpers. No innerHTML with data: every text goes through textContent.
export function h(tag, attrs, ...children) {
  const el = tag === 'svg' || attrs?.svg ? document.createElementNS('http://www.w3.org/2000/svg', tag) : document.createElement(tag);
  if (attrs) for (const [k, v] of Object.entries(attrs)) {
    if (v === undefined || v === null || v === false || k === 'svg') continue;
    if (k === 'class') el.setAttribute('class', Array.isArray(v) ? v.filter(Boolean).join(' ') : v);
    else if (k === 'text') el.textContent = v;
    else if (k.startsWith('on') && typeof v === 'function') el.addEventListener(k.slice(2).toLowerCase(), v);
    else if (k === 'dataset') Object.assign(el.dataset, v);
    else if (k === 'value' && 'value' in el) el.value = v;
    else if (k === 'checked' || k === 'disabled' || k === 'hidden' || k === 'selected' || k === 'readOnly' || k === 'multiple') el[k] = !!v;
    else if (k === 'ref' && typeof v === 'function') v(el);
    else el.setAttribute(k, v === true ? '' : String(v));
  }
  append(el, children);
  return el;
}
export function append(el, children) {
  for (const c of children.flat(Infinity)) {
    if (c === null || c === undefined || c === false || c === true) continue;
    el.append(c instanceof Node ? c : document.createTextNode(String(c)));
  }
  return el;
}
export const clear = el => { while (el.firstChild) el.firstChild.remove(); return el; };
export const replace = (el, ...children) => append(clear(el), children);
export const $ = (sel, root = document) => root.querySelector(sel);
export const $$ = (sel, root = document) => [...root.querySelectorAll(sel)];
let uid = 0; export const id = prefix => `${prefix}-${++uid}`;

// Icons: 24-unit stroke paths drawn for this app (no external icon font).
const P = {
  home: 'M4 5.5h6.5v6.5H4zM13.5 5.5H20V12h-6.5zM4 15h6.5v4H4zM13.5 15H20v4h-6.5z',
  play: 'M7 4.8 19 12 7 19.2z',
  server: 'M4 5h16v5H4zM4 14h16v5H4zM7.5 7.5h.01M7.5 16.5h.01',
  database: 'M5 6.5C5 5 8.1 4 12 4s7 1 7 2.5S15.9 9 12 9 5 8 5 6.5zM5 6.5v11C5 19 8.1 20 12 20s7-1 7-2.5v-11M5 12c0 1.5 3.1 2.5 7 2.5s7-1 7-2.5',
  content: 'M12 3.5 20 8v8l-8 4.5L4 16V8zM12 12.5V20.5M12 12.5 20 8M12 12.5 4 8',
  pulse: 'M3 12h4l2.5-6 4 12 2.5-6H21',
  gear: 'M12 9a3 3 0 1 0 0 6 3 3 0 0 0 0-6zM19.4 13.5l1.6 1.2-2 3.4-1.9-.7a7 7 0 0 1-2 1.2l-.3 2h-4l-.3-2a7 7 0 0 1-2-1.2l-1.9.7-2-3.4 1.6-1.2a7 7 0 0 1 0-3L3 9.3l2-3.4 1.9.7a7 7 0 0 1 2-1.2l.3-2h4l.3 2a7 7 0 0 1 2 1.2l1.9-.7 2 3.4-1.6 1.2a7 7 0 0 1 0 3z',
  search: 'M10.5 4.5a6 6 0 1 0 0 12 6 6 0 0 0 0-12zM15 15l5 5',
  arrow: 'M7 17 17 7M9 7h8v8',
  chevronDown: 'M6 9l6 6 6-6', chevronRight: 'M9 6l6 6-6 6', chevronLeft: 'M15 6l-6 6 6 6',
  close: 'M6 6l12 12M18 6 6 18',
  check: 'M5 12.5l4.5 4.5L19 7.5',
  alert: 'M12 4 21 19H3zM12 10v4M12 16.8v.01',
  info: 'M12 3.5a8.5 8.5 0 1 0 0 17 8.5 8.5 0 0 0 0-17zM12 11v5.5M12 7.8v.01',
  refresh: 'M19 12a7 7 0 1 1-2.05-4.95M19 4.5V8h-3.5',
  external: 'M14 4h6v6M20 4l-9 9M18 14v5H5V6h5',
  folder: 'M3.5 6.5h6l2 2h9v10h-17z',
  copy: 'M9 9h10v10H9zM5 15V5h10',
  terminal: 'M4 5h16v14H4zM7.5 9.5l3 2.5-3 2.5M12.5 15h4',
  bug: 'M9 7.5a3 3 0 0 1 6 0M7.5 10h9v5a4.5 4.5 0 0 1-9 0zM4 12h3.5M16.5 12H20M5 7.5l2.5 2M19 7.5l-2.5 2M5 18l2.7-2M19 18l-2.7-2M12 10v9.5',
  user: 'M12 4.5a3.5 3.5 0 1 0 0 7 3.5 3.5 0 0 0 0-7zM5 19.5c.8-3.6 3.6-5.5 7-5.5s6.2 1.9 7 5.5',
  users: 'M9 5a3 3 0 1 0 0 6 3 3 0 0 0 0-6zM3.5 19c.6-3 2.8-4.8 5.5-4.8s4.9 1.8 5.5 4.8M16 6.2a2.6 2.6 0 0 1 0 4.6M17.5 14.6c1.6.6 2.7 2 3 4.4',
  bot: 'M6 9h12v9H6zM12 5v4M9.5 13h.01M14.5 13h.01M4 13v2.5M20 13v2.5M10 16h4',
  cpu: 'M7 7h10v10H7zM10 10h4v4h-4zM9 3.5V7M15 3.5V7M9 17v3.5M15 17v3.5M3.5 9H7M3.5 15H7M17 9h3.5M17 15h3.5',
  clock: 'M12 3.5a8.5 8.5 0 1 0 0 17 8.5 8.5 0 0 0 0-17zM12 7.5V12l3 2',
  shield: 'M12 3.5 19 6v5.5c0 4.3-2.9 7.6-7 9-4.1-1.4-7-4.7-7-9V6z',
  key: 'M8.5 11a3.5 3.5 0 1 0 0 7 3.5 3.5 0 0 0 0-7zM11 12.5l8.5-8.5M16 7l2.5 2.5M14 9l2 2',
  globe: 'M12 3.5a8.5 8.5 0 1 0 0 17 8.5 8.5 0 0 0 0-17zM3.5 12h17M12 3.5c2.4 2.3 3.6 5.1 3.6 8.5s-1.2 6.2-3.6 8.5c-2.4-2.3-3.6-5.1-3.6-8.5S9.6 5.8 12 3.5z',
  lan: 'M9 4h6v5H9zM4 15h6v5H4zM14 15h6v5h-6zM12 9v3M7 15v-3h10v3',
  qr: 'M4 4h6v6H4zM14 4h6v6h-6zM4 14h6v6H4zM14 14h2.5v2.5H14zM17.5 17.5H20V20h-2.5zM17.5 14H20v2M14 18.5V20h2',
  wand: 'M5 19 15.5 8.5M14 5l1 2 2 1-2 1-1 2-1-2-2-1 2-1zM18.5 12.5l.6 1.2 1.2.6-1.2.6-.6 1.2-.6-1.2-1.2-.6 1.2-.6z',
  map: 'M3.5 6.5 9 4.5l6 2 5.5-2v13L15 19.5l-6-2-5.5 2zM9 4.5v13M15 6.5v13',
  sword: 'M14.5 4H20v5.5L10 19.5l-2.5.5.5-2.5zM6 14l4 4M4 18.5 5.5 20',
  file: 'M6 3.5h8l4 4v13H6zM14 3.5v4h4',
  hex: 'M8 4 4 12l4 8M16 4l4 8-4 8M10.5 9h3M10.5 15h3',
  eye: 'M2.5 12S6 5.5 12 5.5 21.5 12 21.5 12 18 18.5 12 18.5 2.5 12 2.5 12zM12 9a3 3 0 1 0 0 6 3 3 0 0 0 0-6z',
  pause: 'M8 5h3v14H8zM13 5h3v14h-3z',
  stop: 'M6.5 6.5h11v11h-11z',
  power: 'M12 3.5v8M7 6.5a7 7 0 1 0 10 0',
  sun: 'M12 8a4 4 0 1 0 0 8 4 4 0 0 0 0-8zM12 2.5v2M12 19.5v2M2.5 12h2M19.5 12h2M5.3 5.3l1.4 1.4M17.3 17.3l1.4 1.4M5.3 18.7l1.4-1.4M17.3 6.7l1.4-1.4',
  moon: 'M19 14.5A7.5 7.5 0 0 1 9.5 5a7.5 7.5 0 1 0 9.5 9.5z',
  panel: 'M4 5h16v14H4zM9 5v14',
  download: 'M12 4v11M7.5 10.5 12 15l4.5-4.5M5 19.5h14',
  upload: 'M12 20V9M7.5 13.5 12 9l4.5 4.5M5 4.5h14',
  list: 'M8 6.5h12M8 12h12M8 17.5h12M4 6.5h.01M4 12h.01M4 17.5h.01',
  table: 'M4 5h16v14H4zM4 10h16M4 14.5h16M10 10v9',
  plug: 'M9 3.5V8M15 3.5V8M7 8h10v3a5 5 0 0 1-10 0zM12 16v4.5',
  layers: 'M12 4 20.5 8.5 12 13 3.5 8.5zM3.5 12.5 12 17l8.5-4.5M3.5 16.5 12 21l8.5-4.5',
  star: 'M12 4l2.5 5.2 5.5.8-4 3.9.9 5.6L12 16.8l-4.9 2.7.9-5.6-4-3.9 5.5-.8z',
  link: 'M10 14a4 4 0 0 0 5.7 0l3-3a4 4 0 0 0-5.7-5.7l-1 1M14 10a4 4 0 0 0-5.7 0l-3 3a4 4 0 0 0 5.7 5.7l1-1',
  trash: 'M5 7h14M9.5 7V4.5h5V7M7 7l1 13h8l1-13',
  plus: 'M12 5v14M5 12h14',
  minus: 'M5 12h14',
  book: 'M4 5c2.6-.8 5.3-.6 8 1v13.5c-2.7-1.6-5.4-1.8-8-1zM20 5c-2.6-.8-5.3-.6-8 1v13.5c2.7-1.6 5.4-1.8 8-1z',
  bolt: 'M13 3.5 5 13.5h6l-1 7 8-10h-6z',
  watch: 'M12 6.5a5.5 5.5 0 1 0 0 11 5.5 5.5 0 0 0 0-11zM12 9.5V12l1.8 1.2M9 3.5h6M9 20.5h6',
  enter: 'M9.5 10 5 14.5 9.5 19M5 14.5h10a4 4 0 0 0 4-4V5',
  sparkle: 'M12 3.5l1.9 5.1 5.1 1.9-5.1 1.9L12 17.5l-1.9-5.1-5.1-1.9 5.1-1.9zM18.5 15.5l.8 2 2 .8-2 .8-.8 2-.8-2-2-.8 2-.8z',
};
export function icon(name, size = 20, cls = 'ico') {
  const s = h('svg', {svg: true, viewBox: '0 0 24 24', width: size, height: size, fill: 'none', stroke: 'currentColor', 'stroke-width': 1.8, 'stroke-linecap': 'round', 'stroke-linejoin': 'round', 'aria-hidden': 'true', class: cls, focusable: 'false'});
  const d = P[name] || P.info;
  if (name === 'play' || name === 'stop' || name === 'pause') s.setAttribute('fill', 'currentColor');
  s.append(h('path', {svg: true, d}));
  return s;
}
