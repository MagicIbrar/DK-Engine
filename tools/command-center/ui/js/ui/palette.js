// Global search (Ctrl+K): pages (with their tabs one click away), settings and actions jump straight to the control;
// matching files in the engine code and prepared data open in the read-only file viewer.
import {h, icon, clear} from '../core/dom.js';
import {call} from '../core/api.js';
import {state} from '../core/state.js';
import {ENTRIES, PAGES, routeLabel} from './search-index.js';

let open = null;
export function openPalette(initial = '') {
  if (open) { open.input.focus(); return; }
  const prev = document.activeElement;
  const input = h('input', {type: 'search', id: 'palette-input', 'aria-label': 'Search', placeholder: 'Type a setting, page, action or file name…', autocomplete: 'off', value: initial, role: 'combobox', 'aria-expanded': 'true', 'aria-controls': 'palette-list'});
  const list = h('div', {class: 'p-results', id: 'palette-list', role: 'listbox'});
  const box = h('div', {class: 'dialog palette', role: 'dialog', 'aria-modal': 'true', 'aria-label': 'Search'}, h('div', {class: 'p-input'}, icon('search', 20), input, h('kbd', {text: 'Esc'})), list, h('div', {class: 'dlg-foot'}, h('span', {class: 'faint', text: `Enter opens · ↑↓ move · ←→ choose a tab · files search the ${state.mode === 'install' ? 'engine' : 'sandbox engine'} code and prepared data names (read-only)`})));
  const scrim = h('div', {class: 'scrim'}, box); document.body.append(scrim);
  let items = [], sel = 0, sub = -1, search = null, fileTimer = null, files = [], fileState = '';
  const close = () => { scrim.remove(); open = null; if (search) call('find.cancel', {id: search}).catch(() => {}); clearTimeout(fileTimer); try { prev?.focus(); } catch {} };
  const go = it => { close(); if (it.kind === 'file') import('../main.js').then(m => m.navigate('updates/files', {})).then(() => window.dispatchEvent(new CustomEvent('dk-open-file', {detail: it}))); else import('../main.js').then(m => m.navigate(it.route, {anchor: it.anchor})); };
  const GROUP = {page: 'Pages', tab: 'Tabs', entry: 'Settings and actions', file: 'Files'};
  function render() {
    const q = input.value.trim().toLowerCase(), words = q.split(/\s+/).filter(Boolean);
    const score = e => { const t = (e.title + ' ' + e.keywords + ' ' + routeLabel(e.route)).toLowerCase(); if (!words.every(w => t.includes(w))) return -1; return (e.title.toLowerCase().startsWith(q) ? 3 : 0) + (e.title.toLowerCase().includes(q) ? 2 : 0); };
    const pagesHit = PAGES.filter(p => !q || p.label.toLowerCase().includes(q)).map(p => ({title: p.label, route: p.id, kind: 'page', ico: p.ico, tabs: p.tabs, pid: p.id, where: p.tabs.length ? `${p.tabs.length} tabs` : 'Page'}));
    const tabsHit = q ? PAGES.flatMap(p => p.tabs.filter(([, label]) => words.every(w => label.toLowerCase().includes(w) || p.label.toLowerCase().includes(w))).map(([id, label]) => ({title: label, route: `${p.id}/${id}`, kind: 'tab', ico: p.ico, where: p.label}))).slice(0, 6) : [];
    const hits = q ? ENTRIES.map(e => ({...e, s: score(e)})).filter(e => e.s >= 0).sort((a, b) => b.s - a.s).slice(0, 14) : ENTRIES.slice(0, 8);
    const dupe = e => tabsHit.some(t => t.route === e.route && t.title.toLowerCase() === e.title.toLowerCase());
    items = [...pagesHit.slice(0, q ? 3 : 7), ...tabsHit, ...hits.filter(e => !dupe(e)).map(e => ({...e, kind: 'entry', where: routeLabel(e.route)})), ...files.map(f => ({...f, kind: 'file', title: f.rel.split('/').pop(), where: (f.root === 'prepared' ? 'Prepared data' : f.root === 'engine' ? 'Engine code' : state.mode === 'install' ? 'Launcher code' : 'Preview code') + ' · ' + f.rel + (f.line ? ':' + f.line : '')}))];
    if (sel >= items.length) sel = Math.max(0, items.length - 1);
    clear(list);
    let lastKind = null;
    items.forEach((it, i) => {
      if (it.kind !== lastKind) { list.append(h('div', {class: 'p-group eyebrow', text: GROUP[it.kind]})); lastKind = it.kind; }
      const lead = h('span', {class: ['p-ico', it.kind]}, icon(it.kind === 'file' ? (it.text ? 'search' : 'file') : it.kind === 'entry' ? 'enter' : it.ico, 18));
      // Page rows list their tabs as chips: one click (or ← → then Enter) opens that tab directly.
      const chips = it.kind === 'page' && it.tabs.length ? h('div', {class: 'p-tabs', role: 'group', 'aria-label': `${it.title} tabs`}, it.tabs.map(([id, label], k) => { const b = h('button', {type: 'button', class: 'p-chip', tabindex: '-1', 'data-k': String(k), text: label}); b.addEventListener('click', e => { e.stopPropagation(); go({kind: 'tab', route: `${it.pid}/${id}`}); }); return b; })) : null;
      const el = h('div', {class: 'p-item', role: 'option', id: 'po-' + i, 'aria-selected': String(i === sel)}, lead, h('div', {class: 'stack tight grow'}, h('span', {class: 'ellipsis p-title', text: it.title}), it.text ? h('span', {class: 'snippet ellipsis', text: it.text}) : null, chips), h('span', {class: 'where ellipsis', text: it.where, title: it.where}));
      el.addEventListener('mousemove', () => { if (sel !== i) { sel = i; sub = -1; mark(); } }); el.addEventListener('click', () => go(it)); list.append(el);
    });
    if (fileState) list.append(h('div', {class: 'p-group faint', text: fileState}));
    mark(false);
  }
  function mark(scroll = true) {
    list.querySelectorAll('.p-item').forEach((el, i) => { el.setAttribute('aria-selected', String(i === sel)); el.querySelectorAll('.p-chip').forEach(c => c.classList.toggle('on', i === sel && Number(c.dataset.k) === sub)); });
    if (scroll) list.querySelector(`#po-${sel}`)?.scrollIntoView({block: 'nearest'});
    input.setAttribute('aria-activedescendant', items.length ? 'po-' + sel : '');
  }
  async function fileSearch() {
    const q = input.value.trim(); if (search) { call('find.cancel', {id: search}).catch(() => {}); search = null; }
    files = []; if (q.length < 3) { fileState = q ? 'Type 3+ characters to search files.' : ''; render(); return; }
    fileState = 'Searching files…'; render();
    try {
      const {id} = await call('find.start', {query: q, mode: 'both', limit: 60}); search = id;
      for (let i = 0; i < 80 && open && search === id; i++) { const r = await call('find.poll', {id}); files = r.results.slice(0, 25); fileState = r.done ? (r.total ? `${r.total} file match${r.total === 1 ? '' : 'es'}${r.total > 25 ? ' (first 25 shown; open Code & files for all)' : ''} · ${r.ms} ms` : 'No files match.') : `Searching files… ${r.scanned} scanned`; render(); if (r.done) break; await new Promise(res => setTimeout(res, 150)); }
    } catch (e) { fileState = 'File search unavailable: ' + e.message; render(); }
  }
  input.addEventListener('input', () => { sel = 0; sub = -1; render(); clearTimeout(fileTimer); fileTimer = setTimeout(fileSearch, 280); });
  input.addEventListener('keydown', e => {
    const it = items[sel], n = it?.kind === 'page' ? it.tabs.length : 0;
    if (e.key === 'ArrowDown') { e.preventDefault(); sel = Math.min(items.length - 1, sel + 1); sub = -1; mark(); }
    else if (e.key === 'ArrowUp') { e.preventDefault(); sel = Math.max(0, sel - 1); sub = -1; mark(); }
    else if (e.key === 'ArrowRight' && n && input.selectionStart === input.value.length) { e.preventDefault(); sub = Math.min(n - 1, sub + 1); mark(); }
    else if (e.key === 'ArrowLeft' && n && sub >= 0) { e.preventDefault(); sub -= 1; mark(); }
    else if (e.key === 'Enter' && it) { e.preventDefault(); go(sub >= 0 && n ? {kind: 'tab', route: `${it.pid}/${it.tabs[sub][0]}`} : it); }
    else if (e.key === 'Escape') { e.preventDefault(); close(); }
  });
  scrim.addEventListener('mousedown', e => { if (e.target === scrim) close(); });
  open = {input}; render(); if (initial) fileSearch(); setTimeout(() => input.focus(), 0);
}
