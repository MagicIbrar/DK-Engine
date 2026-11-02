// Shared components. All follow one design system (tokens.css + app.css) and one accessibility contract:
// real buttons/inputs, labels tied to controls, visible focus, Escape closes overlays, focus returns where it came from.
import {h, icon, clear, id, append} from '../core/dom.js';
import {call, follow} from '../core/api.js';
import * as f from '../core/format.js';

export function button(label, {kind = '', size = '', ico, onClick, title, disabled, type = 'button', attrs = {}} = {}) {
  const b = h('button', {type, class: ['btn', kind, size], disabled, 'data-tip': title, ...attrs}, ico ? icon(ico, 18) : null, label ? h('span', {class: 'ellipsis', text: label}) : null);
  if (onClick) b.addEventListener('click', e => guard(b, () => onClick(e)));
  return b;
}
/** Runs an async handler once at a time per button: repeated clicks while pending are ignored. */
export async function guard(btn, fn) {
  if (btn.getAttribute('aria-busy') === 'true') return;
  btn.setAttribute('aria-busy', 'true'); const wasDisabled = btn.disabled; btn.disabled = true;
  try { return await fn(); } finally { btn.removeAttribute('aria-busy'); btn.disabled = wasDisabled; }
}
export const round = (label, onClick, {ico = 'arrow', small} = {}) => { const b = h('button', {type: 'button', class: ['round', small && 'small'], 'aria-label': label, 'data-tip': label}, icon(ico, small ? 16 : 18)); if (onClick) b.addEventListener('click', e => guard(b, () => onClick(e))); return b; };
export const iconBtn = (label, ico, onClick, attrs = {}) => { const b = h('button', {type: 'button', class: 'icon-btn', 'aria-label': label, 'data-tip': label, ...attrs}, icon(ico, 18)); if (onClick) b.addEventListener('click', e => guard(b, () => onClick(e))); return b; };
export function card({title, desc, tint, cls, actions, children = [], headExtra, id: cardId, eyebrow} = {}) {
  return h('section', {class: ['card', tint && 'tint', tint, cls], id: cardId, 'aria-label': typeof title === 'string' ? title : undefined},
    title || actions || headExtra ? h('div', {class: 'card-head'}, h('div', {class: 'titles'}, eyebrow ? h('span', {class: 'eyebrow', text: eyebrow}) : null, typeof title === 'string' ? h('h3', {text: title}) : title, desc ? h('p', {class: 'desc', text: desc}) : null), headExtra || null, actions ? h('div', {class: 'row'}, actions) : null) : null,
    children);
}
export function stat({label, value, unit, note, tint = 'mint', open, small, valueId, noteId}) {
  const v = h('div', {class: ['stat-value', small && 'small'], id: valueId}, value ?? '—', unit ? h('span', {class: 'stat-unit', text: unit}) : null);
  return h('section', {class: ['card', 'tint', tint, 'stat'], 'aria-label': label},
    h('div', {class: 'stat-label', text: label}),
    h('div', {class: 'stat-bottom'}, h('div', {class: 'stack tight grow'}, v, note !== undefined ? h('div', {class: 'stat-note', id: noteId, text: note}) : null), open ? round(open.label || 'Open ' + label, open.onClick) : null));
}
export function pill(text, kind = '', {live, title} = {}) { return h('span', {class: ['pill', kind, live && 'live'], 'data-tip': title}, h('span', {class: 'dot', 'aria-hidden': 'true'}), text); }
export function notice(kind, text, {action} = {}) { return h('div', {class: ['notice', kind], role: kind === 'err' ? 'alert' : 'status'}, icon(kind === 'ok' ? 'check' : kind === 'err' || kind === 'warn' ? 'alert' : 'info', 18), h('div', {class: 'grow'}, text), action || null); }
export const applies = a => h('span', {class: 'badge-applies', text: {now: 'Applies now', 'next-start': 'Next world start', 'next-launch': 'Next launch', 'next-game-window': 'Next game window', restart: 'Restart required'}[a] || a});

// ---- fields (labels tied to inputs; errors render next to the control)
export function textField({label, value = '', type = 'text', placeholder, help, maxLength, autocomplete = 'off', onInput, onChange, applies: ap, disabled, attrs = {}, fieldId}) {
  const inputId = fieldId || id('f');
  const input = h('input', {id: inputId, class: 'input', type, value, placeholder, maxlength: maxLength, autocomplete, spellcheck: 'false', disabled, 'aria-describedby': inputId + '-help', ...attrs});
  const err = h('div', {class: 'error', id: inputId + '-err', role: 'alert', hidden: true});
  const wrap = h('div', {class: 'field'}, h('label', {for: inputId}, label, ap ? applies(ap) : null), input, help ? h('div', {class: 'help', id: inputId + '-help', text: help}) : null, err);
  if (onInput) input.addEventListener('input', () => onInput(input.value));
  if (onChange) input.addEventListener('change', () => onChange(input.value));
  input.addEventListener('input', () => setError(wrap, null));
  wrap.input = input; return wrap;
}
export function setError(wrap, message) { const e = wrap.querySelector('.error'); if (!e) return; wrap.classList.toggle('invalid', !!message); e.hidden = !message; e.textContent = message || ''; if (message) wrap.input?.setAttribute('aria-invalid', 'true'); else wrap.input?.removeAttribute('aria-invalid'); }
export function selectField({label, options, value, help, onChange, applies: ap, disabled, fieldId}) {
  const sid = fieldId || id('s');
  const sel = h('select', {id: sid, class: 'input', disabled}, options.map(o => h('option', {value: o.value, selected: o.value === value, text: o.label})));
  if (onChange) sel.addEventListener('change', () => onChange(sel.value));
  const wrap = h('div', {class: 'field'}, h('label', {for: sid}, label, ap ? applies(ap) : null), sel, help ? h('div', {class: 'help', text: help}) : null, h('div', {class: 'error', role: 'alert', hidden: true}));
  wrap.input = sel; return wrap;
}
export function switchRow({title, desc, checked, onChange, applies: ap, disabled, fieldId}) {
  const sid = fieldId || id('sw');
  const input = h('input', {id: sid, type: 'checkbox', role: 'switch', checked, disabled, 'aria-describedby': sid + '-d'});
  const row = h('div', {class: 'switch-row'}, h('div', {class: 'text'}, h('label', {class: 't', for: sid}, title, ap ? applies(ap) : null), desc ? h('div', {class: 'd', id: sid + '-d', text: desc}) : null), h('span', {class: 'switch'}, input));
  if (onChange) input.addEventListener('change', async () => { const want = input.checked; input.disabled = true; try { if (await onChange(want) === false) input.checked = !want; } catch (e) { input.checked = !want; toast(e.message, 'err'); } finally { input.disabled = !!disabled; } });
  row.input = input; return row;
}
/** A sliding highlight that follows the selected button of a group (segmented control or tab bar). */
function slider(host, current) {
  const thumb = h('span', {class: 'slide-thumb', 'aria-hidden': 'true'}); host.prepend(thumb);
  const place = () => { const on = current(); if (!on || !on.offsetWidth) { thumb.style.opacity = '0'; return; } thumb.style.opacity = '1'; thumb.style.width = on.offsetWidth + 'px'; thumb.style.height = on.offsetHeight + 'px'; thumb.style.transform = `translate(${on.offsetLeft}px, ${on.offsetTop}px)`; };
  new ResizeObserver(place).observe(host); requestAnimationFrame(place);
  return place;
}
export function seg(options, value, onChange, {label, disabled, title} = {}) {
  const g = h('div', {class: 'seg', role: 'group', 'aria-label': label, 'data-tip': title});
  const btns = options.map(o => { const b = h('button', {type: 'button', 'aria-pressed': String(o.value === value), disabled}, o.ico ? icon(o.ico, 16) : null, h('span', {text: o.label})); b.addEventListener('click', () => { if (b.getAttribute('aria-pressed') === 'true') return; btns.forEach(x => x.setAttribute('aria-pressed', String(x === b))); place(); onChange(o.value); }); return b; });
  append(g, btns);
  const place = slider(g, () => btns.find(b => b.getAttribute('aria-pressed') === 'true'));
  g.set = v => { btns.forEach((b, i) => b.setAttribute('aria-pressed', String(options[i].value === v))); place(); };
  return g;
}

// ---- section categories (Global 0.0.1 focus workspace). Same API the pages used for tabs: select(id) still
// switches section; show(id) opens a section or, with no id and nothing chosen yet, the category grid.
// The page keeps its own panels (#panel-<id>); they are moved under this workspace so the hub and the
// "Choose a category" picker replace the old tab bar. Categories back button removed (declutter) —
// overview stays available via the empty picker option. No section is removed.
export function tabs(list, {current, onSelect, onOverview, label, overview = true}) {
  let active = overview ? null : (current || list[0]?.id || null);
  const picker = h('select', {class: 'input', 'aria-label': label || 'Choose a section'}, h('option', {value: '', text: 'Choose a category'}), list.map(t => h('option', {value: t.id, text: t.label})));
  const hub = h('div', {class: 'focus-workspace-hub', role: 'group', 'aria-label': label || 'Categories'}, list.map(t => {
    const b = button(t.label, {kind: 'ghost', ico: t.ico || 'chevronRight', attrs: {'data-section': t.id, id: 'tab-' + t.id, title: t.desc || t.label}, onClick: () => select(t.id, {focus: true})});
    if (t.badge) b.append(h('span', {class: 'pill err', text: t.badge}));
    return b;
  }));
  const body = h('div', {class: 'focus-workspace-body'}, hub);
  const host = h('section', {class: 'focus-workspace tab-hub', 'aria-label': label || 'Sections'}, h('div', {class: 'focus-workspace-nav'}, picker), body);
  const panels = () => list.map(t => {
    const scope = host.closest('.page') || host.parentElement?.parentElement || host.parentElement;
    const p = scope?.querySelector('[id="panel-' + t.id + '"]');
    if (p && p.parentElement !== body) body.append(p);
    return p;
  });
  function present({focus = false} = {}) {
    picker.value = active || ''; hub.hidden = active !== null; host.dataset.view = active ? 'section' : 'categories';
    if (active === null) { for (const p of panels()) if (p) p.hidden = true; if (focus) hub.querySelector('button')?.focus(); }
  }
  function select(id, {focus = false} = {}) {
    if (!list.some(t => t.id === id)) return host.overview({focus});
    panels(); active = id; present(); onSelect(id);
    if (focus) { const p = body.querySelector('[id="panel-' + id + '"]'), heading = p?.querySelector('h2,h3'); if (heading) { heading.tabIndex = -1; heading.focus({preventScroll: true}); } }
    return active;
  }
  host.select = id => select(id);
  host.overview = ({focus = false} = {}) => { active = null; present({focus}); onOverview?.(); return null; };
  host.show = id => (list.some(t => t.id === id) ? select(id) : active ? select(active) : host.overview());
  Object.defineProperty(host, 'active', {get: () => active});
  picker.addEventListener('change', () => (picker.value ? select(picker.value, {focus: true}) : host.overview()));
  present();
  return host;
}
export function collapsible(title, content, {open = false, desc, cardCls = ''} = {}) {
  const bid = id('c'); const body = h('div', {id: bid, class: 'stack', hidden: !open});
  append(body, [content]);
  const btn = h('button', {type: 'button', class: 'btn ghost', 'aria-expanded': String(open), 'aria-controls': bid}, icon(open ? 'chevronDown' : 'chevronRight', 18), h('span', {text: title}));
  btn.addEventListener('click', () => { const o = btn.getAttribute('aria-expanded') !== 'true'; btn.setAttribute('aria-expanded', String(o)); body.hidden = !o; btn.replaceChild(icon(o ? 'chevronDown' : 'chevronRight', 18), btn.firstChild); });
  return h('section', {class: ['card', cardCls]}, h('div', {class: 'card-head'}, h('div', {class: 'titles'}, btn, desc ? h('p', {class: 'desc', text: desc}) : null)), body);
}

// ---- table with deliberate horizontal scrolling and optional sorting
export function table({columns, rows, empty = 'Nothing to show.', onRow, sortable = true, tall, caption, selectedKey, rowKey}) {
  let sortKey = null, dir = 1;
  const wrap = h('div', {class: ['table-wrap', tall && 'tall'], tabindex: '0', role: 'region', 'aria-label': caption || 'Table'});
  function render() {
    const data = [...rows]; if (sortKey !== null) { const c = columns.find(x => x.key === sortKey); data.sort((a, b) => { const x = c.sort ? c.sort(a) : a[sortKey], y = c.sort ? c.sort(b) : b[sortKey]; return (x > y ? 1 : x < y ? -1 : 0) * dir; }); }
    const thead = h('thead', {}, h('tr', {}, columns.map(c => h('th', {class: [c.num && 'num', c.wrap && 'wrap'], scope: 'col', 'aria-sort': sortKey === c.key ? (dir > 0 ? 'ascending' : 'descending') : undefined}, sortable && c.sortable !== false ? h('button', {type: 'button', onClick: () => { dir = sortKey === c.key ? -dir : 1; sortKey = c.key; render(); }}, c.label, sortKey === c.key ? icon(dir > 0 ? 'chevronDown' : 'chevronDown', 12) : null) : c.label))));
    const tbody = h('tbody', {}, data.length ? data.map(r => { const tr = h('tr', {class: rowKey && selectedKey && rowKey(r) === selectedKey ? 'selected' : null, tabindex: onRow ? '0' : undefined}, columns.map(c => { const v = c.render ? c.render(r) : r[c.key]; return h('td', {class: [c.num && 'num', c.mono && 'mono', c.wrap && 'wrap']}, v === null || v === undefined ? h('span', {class: 'cell-null', text: c.nullText || 'null'}) : v); })); if (onRow) { tr.addEventListener('click', () => onRow(r)); tr.addEventListener('keydown', e => { if (e.key === 'Enter') onRow(r); }); tr.style.cursor = 'pointer'; } return tr; }) : h('tr', {}, h('td', {colspan: columns.length, class: 'wrap faint', text: empty})));
    clear(wrap).append(h('table', {class: 't'}, caption ? h('caption', {class: 'sr-only', text: caption}) : null, thead, tbody));
  }
  render(); wrap.update = next => { rows = next; render(); }; return wrap;
}
export const kv = pairs => h('dl', {class: 'kv'}, pairs.filter(Boolean).flatMap(([k, v]) => [h('dt', {text: k}), h('dd', {}, v ?? '—')]));

// ---- overlays
let lastFocus = null;
export function dialog({title, body, actions = [], wide, dismissible = true, onClose, labelledBy}) {
  lastFocus = document.activeElement;
  const titleId = id('dlg');
  const close = h('button', {type: 'button', class: 'icon-btn', 'aria-label': 'Close dialog'}, icon('close', 18));
  const box = h('div', {class: ['dialog', wide && 'wide'], role: 'dialog', 'aria-modal': 'true', 'aria-labelledby': labelledBy || titleId},
    h('div', {class: 'dlg-head'}, h('h2', {id: titleId, text: title}), dismissible ? close : null), h('div', {class: 'dlg-body'}, body), actions.length ? h('div', {class: 'dlg-foot'}, actions) : null);
  const scrim = h('div', {class: 'scrim'}, box);
  const done = value => { scrim.remove(); document.removeEventListener('keydown', key, true); onClose?.(value); try { lastFocus?.focus(); } catch {} };
  const key = e => {
    if (e.key === 'Escape' && dismissible) { e.preventDefault(); e.stopPropagation(); done(null); }
    if (e.key === 'Tab') { const items = [...box.querySelectorAll('button,input,select,textarea,a[href],[tabindex="0"]')].filter(x => !x.disabled && x.offsetParent !== null); if (!items.length) return; const first = items[0], last = items.at(-1); if (e.shiftKey && document.activeElement === first) { e.preventDefault(); last.focus(); } else if (!e.shiftKey && document.activeElement === last) { e.preventDefault(); first.focus(); } }
  };
  close.addEventListener('click', () => done(null));
  scrim.addEventListener('mousedown', e => { if (e.target === scrim && dismissible) done(null); });
  document.addEventListener('keydown', key, true);
  document.body.append(scrim);
  setTimeout(() => (box.querySelector('[autofocus]') || box.querySelector('.dlg-body input, .dlg-body select, .dlg-body textarea') || box.querySelector('.dlg-foot .btn') || close).focus(), 0);
  return {close: done, box};
}
export function confirm({title, message, confirmLabel = 'Continue', danger, requireText}) {
  return new Promise(resolve => {
    const field = requireText ? textField({label: `Type ${requireText} to confirm`, attrs: {autofocus: true}}) : null;
    const ok = button(confirmLabel, {kind: danger ? 'danger' : 'primary', onClick: () => { if (field && field.input.value.trim() !== requireText) { setError(field, 'The text does not match.'); return; } d.close(field ? field.input.value.trim() : true); }});
    const d = dialog({title, body: [typeof message === 'string' ? h('p', {class: 'wrap-any', text: message}) : message, field], actions: [button('Cancel', {kind: 'ghost', onClick: () => d.close(null)}), ok], onClose: v => resolve(v)});
  });
}
const toastHost = () => document.getElementById('toasts');
export function toast(message, kind = 'info', {timeout = kind === 'err' ? 9000 : 4500, action} = {}) {
  const t = h('div', {class: ['toast', kind], role: kind === 'err' ? 'alert' : 'status'}, icon(kind === 'ok' ? 'check' : kind === 'info' ? 'info' : 'alert', 18), h('div', {class: 'grow', text: message}), action || null, iconBtn('Dismiss', 'close', () => t.remove()));
  toastHost()?.append(t); while (toastHost()?.children.length > 4) toastHost().firstChild.remove();
  if (timeout) setTimeout(() => t.remove(), timeout);
  return t;
}
/** Dropdown menu that stays inside the window (flips up/left when needed). */
export function menu(anchor, items, {minWidth} = {}) {
  closeMenus();
  const m = h('div', {class: 'menu', role: 'menu'});
  if (minWidth) m.style.minWidth = minWidth + 'px';
  for (const it of items) {
    if (it === '-') { m.append(h('div', {class: 'sep', role: 'separator'})); continue; }
    if (it.header) { m.append(h('div', {class: 'mh eyebrow', text: it.header})); continue; }
    const b = h('button', {type: 'button', class: 'mi', role: 'menuitem', disabled: it.disabled}, it.ico ? icon(it.ico, 18) : null, h('span', {class: 'grow ellipsis', text: it.label}), it.hint ? h('span', {class: 'k', text: it.hint}) : null);
    b.addEventListener('click', () => { closeMenus(); it.onClick?.(); }); m.append(b);
  }
  document.body.append(m);
  const r = anchor.getBoundingClientRect(), mw = m.offsetWidth, mh = m.offsetHeight;
  let left = Math.min(r.right - mw, window.innerWidth - mw - 12); left = Math.max(12, left);
  let top = r.bottom + 6; if (top + mh > window.innerHeight - 12) top = Math.max(12, r.top - mh - 6);
  m.style.left = left + 'px'; m.style.top = top + 'px';
  const items$ = [...m.querySelectorAll('.mi:not(:disabled)')]; items$[0]?.focus();
  const key = e => { const i = items$.indexOf(document.activeElement); if (e.key === 'Escape') { closeMenus(); anchor.focus(); } else if (e.key === 'ArrowDown') { e.preventDefault(); items$[(i + 1) % items$.length]?.focus(); } else if (e.key === 'ArrowUp') { e.preventDefault(); items$[(i - 1 + items$.length) % items$.length]?.focus(); } };
  m.addEventListener('keydown', key);
  setTimeout(() => document.addEventListener('mousedown', outside), 0);
  function outside(e) { if (!m.contains(e.target)) closeMenus(); }
  m.cleanup = () => document.removeEventListener('mousedown', outside);
  return m;
}
export function closeMenus() { for (const m of document.querySelectorAll('.menu')) { m.cleanup?.(); m.remove(); } }

// ---- tooltips for any [data-tip] (mouse and keyboard focus), kept inside the window
let tipEl = null;
export function installTooltips() {
  const show = target => { const text = target.getAttribute('data-tip'); if (!text) return; hide(); tipEl = h('div', {class: 'tooltip', role: 'tooltip', text}); document.body.append(tipEl); const r = target.getBoundingClientRect(), w = tipEl.offsetWidth, ht = tipEl.offsetHeight; let left = r.left + r.width / 2 - w / 2; left = Math.max(8, Math.min(left, window.innerWidth - w - 8)); let top = r.bottom + 8; if (top + ht > window.innerHeight - 8) top = r.top - ht - 8; if (r.width < 90 && r.left < 100) { left = r.right + 10; top = r.top + r.height / 2 - ht / 2; } tipEl.style.left = left + 'px'; tipEl.style.top = top + 'px'; };
  const hide = () => { tipEl?.remove(); tipEl = null; };
  document.addEventListener('mouseover', e => { const t = e.target.closest?.('[data-tip]'); if (t) show(t); });
  document.addEventListener('mouseout', e => { if (e.target.closest?.('[data-tip]')) hide(); });
  document.addEventListener('focusin', e => { const t = e.target.closest?.('[data-tip]'); if (t && t.matches(':focus-visible')) show(t); });
  document.addEventListener('focusout', hide); document.addEventListener('scroll', hide, true); document.addEventListener('keydown', e => { if (e.key === 'Escape') hide(); });
}

// ---- progress for backend jobs: phase list, honest bar, log, cancel
export function jobView(job, {onDone, compact} = {}) {
  const phases = h('div', {class: 'phases', 'aria-live': 'polite'}), bar = h('div', {class: 'bar indeterminate', role: 'progressbar', 'aria-label': job.title}, h('i'));
  const msg = h('div', {class: 'muted wrap-any'}), counts = h('div', {class: 'faint num'}), log = h('pre', {class: 'block', hidden: compact});
  const cancel = button('Cancel', {kind: 'ghost', size: 'small', onClick: async () => { try { await call('jobs.cancel', {id: job.id}); } catch (e) { toast(e.message, 'warn'); } }});
  const el = h('div', {class: 'stack tight'}, h('div', {class: 'row between'}, h('strong', {text: job.title}), cancel), bar, h('div', {class: 'row between wrap'}, msg, counts), phases, compact ? null : collapsibleLog(log));
  const update = j => {
    clear(phases).append(...j.phases.map((p, i) => { const last = i === j.phases.length - 1; const state = !last || j.state === 'succeeded' ? 'done' : j.state === 'running' ? 'now' : 'failed'; return h('div', {class: ['ph', state]}, h('span', {class: 'mk', 'aria-hidden': 'true'}, state === 'done' ? icon('check', 12) : null), h('span', {text: p.name}), p.endedAt ? h('span', {class: 'faint num', text: f.duration(p.endedAt - p.startedAt)}) : null); }));
    const p = j.progress;
    if (p && j.state === 'running') { bar.classList.remove('indeterminate'); bar.firstChild.style.width = Math.round(100 * p.done / p.total) + '%'; bar.setAttribute('aria-valuenow', Math.round(100 * p.done / p.total)); bar.setAttribute('aria-valuemin', '0'); bar.setAttribute('aria-valuemax', '100'); counts.textContent = `${f.n(p.done)} / ${f.n(p.total)} ${p.unit}`; }
    else if (j.state === 'running') { bar.classList.add('indeterminate'); bar.firstChild.style.width = ''; bar.removeAttribute('aria-valuenow'); counts.textContent = j.phase ? 'In progress' : ''; }
    else { bar.classList.remove('indeterminate'); bar.firstChild.style.width = j.state === 'succeeded' ? '100%' : bar.firstChild.style.width || '0%'; counts.textContent = j.state === 'succeeded' ? 'Done' : j.state === 'cancelled' ? 'Cancelled' : 'Failed'; }
    msg.textContent = j.state === 'failed' ? j.error : j.message || '';
    msg.classList.toggle('muted', j.state !== 'failed'); if (j.state === 'failed') msg.style.color = 'var(--err)';
    cancel.hidden = !j.cancellable;
    log.textContent = j.log.map(l => `${f.time(l.at)}  ${l.line}`).join('\n');
  };
  update(job);
  el.done = follow(job, update).then(j => { update(j || job); onDone?.(j); return j; });
  return el;
}
function collapsibleLog(log) { const b = h('button', {type: 'button', class: 'btn ghost small', 'aria-expanded': 'false'}, icon('list', 16), 'Details'); b.addEventListener('click', () => { const o = log.hidden; log.hidden = !o; b.setAttribute('aria-expanded', String(o)); }); return h('div', {class: 'stack tight'}, b, log); }
/** Start a job-returning operation and show its progress in a dialog until it ends. */
export async function runJob(method, params, {title, successText, onDone, keepOpen} = {}) {
  let job; try { job = await call(method, params); } catch (e) { toast(e.message, 'err'); throw e; }
  if (!job?.id) return job;
  const view = jobView(job);
  const d = dialog({title: title || job.title, body: view, actions: [button('Hide', {kind: 'ghost', onClick: () => d.close()})], wide: false});
  const final = await view.done;
  if (final?.state === 'succeeded') { toast(successText || `${job.title}: done`, 'ok'); if (!keepOpen) d.close(); }
  else if (final?.state === 'failed') toast(final.error || 'Failed.', 'err');
  onDone?.(final); return final;
}
export function empty(text, {ico = 'info', action} = {}) { return h('div', {class: 'stack tight', style: null}, h('div', {class: 'row faint'}, icon(ico, 18), h('span', {text})), action || null); }
export function copyText(text, label = 'Copied') { return navigator.clipboard.writeText(text).then(() => toast(label, 'ok'), () => toast('Copy was refused by the system clipboard.', 'warn')); }
export function sparkline(values, {width = 160, height = 36, max} = {}) {
  const pts = values.filter(v => Number.isFinite(v)); const top = max ?? Math.max(1, ...pts);
  const s = h('svg', {svg: true, viewBox: `0 0 ${width} ${height}`, width, height, role: 'img', 'aria-label': pts.length ? `Last ${pts.length} samples, latest ${pts.at(-1)}` : 'No samples yet'});
  if (pts.length > 1) {
    const step = width / (pts.length - 1), y = v => height - 3 - (v / top) * (height - 6);
    const line = pts.map((v, i) => `${i ? 'L' : 'M'}${(i * step).toFixed(1)},${y(v).toFixed(1)}`).join('');
    s.append(h('path', {svg: true, d: line + `L${width},${height}L0,${height}Z`, fill: 'currentColor', opacity: '.12'}), h('path', {svg: true, d: line, fill: 'none', stroke: 'currentColor', 'stroke-width': 1.8}), h('circle', {svg: true, cx: width, cy: y(pts.at(-1)), r: 3, fill: 'currentColor'}));
  }
  return s;
}
