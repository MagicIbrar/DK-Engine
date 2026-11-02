// DK Command Center: app shell, router and global pollers.
import {h, icon, $, replace} from './core/dom.js';
import {boot, call, onSessionLost, reportPerf} from './core/api.js';
import {poller} from './core/poll.js';
import {state, on} from './core/state.js';
import {PAGES} from './ui/search-index.js';
import {installTooltips, toast, iconBtn, pill} from './ui/components.js';
import {openPalette} from './ui/palette.js';
import {openDevMenu} from './ui/devmenu.js';
import {mountUpdateCard} from './ui/updatecard.js';
import {watchClose} from './ui/closeflow.js';
import {navigationTile, navigationGlyph} from './ui/nav-icons.js';

const t0 = performance.now();
const SPLASH_STEPS = [
  {id:'start', phase:'1 / 4  START', sub:'Starting the launcher shell…', detail:'Preparing UI', overall:12, fine:28},
  {id:'session', phase:'2 / 4  SESSION', sub:'Opening a secure launcher session…', detail:'Handshake', overall:38, fine:55},
  {id:'backend', phase:'3 / 4  BACKEND', sub:'Connecting to the Command Center backend…', detail:'app.boot', overall:68, fine:82},
  {id:'home', phase:'4 / 4  HOME', sub:'Opening your Home dashboard…', detail:'First page', overall:92, fine:100},
];
const sleep = (ms) => new Promise(r => setTimeout(r, ms));
function setSplash(stepId, patch = {}) {
  const splash = document.getElementById('splash'); if (!splash) return;
  const step = SPLASH_STEPS.find(s => s.id === stepId) || SPLASH_STEPS[0];
  const phase = patch.phase || step.phase, sub = patch.sub || step.sub, detail = patch.detail || step.detail;
  const overall = patch.overall ?? step.overall, fine = patch.fine ?? step.fine;
  const el = id => document.getElementById(id);
  if (el('splash-phase')) el('splash-phase').textContent = phase;
  if (el('splash-sub')) el('splash-sub').textContent = sub;
  if (el('splash-detail')) el('splash-detail').textContent = detail;
  if (el('splash-bar-overall')) el('splash-bar-overall').style.width = overall + '%';
  if (el('splash-bar-fine')) el('splash-bar-fine').style.width = fine + '%';
  const idx = SPLASH_STEPS.findIndex(s => s.id === step.id);
  document.querySelectorAll('#splash-steps li').forEach((li, i) => {
    li.classList.toggle('now', i === idx);
    li.classList.toggle('done', i < idx);
    const mk = li.querySelector('.mk'); if (mk) mk.textContent = i < idx ? '✓' : String(i + 1);
  });
}
const pages = new Map(); let current = null;
const loaders = {home: () => import('./pages/home.js'), play: () => import('./pages/play.js'), server: () => import('./pages/server.js'), sql: () => import('./pages/sql.js'), content: () => import('./pages/content.js'), updates: () => import('./pages/updates.js'), settings: () => import('./pages/settings.js')};

export function applySettings(s) {
  const root = document.documentElement;
  if (s.theme === 'system') root.removeAttribute('data-theme'); else root.setAttribute('data-theme', s.theme);
  root.style.setProperty('--scale', String(s.scale || 1));
  if (s.reducedMotion === 'system') root.removeAttribute('data-motion'); else root.setAttribute('data-motion', s.reducedMotion === 'on' ? 'off' : 'on');
  root.setAttribute('data-density', s.density);
  const t = $('#theme-toggle'); if (t) { const light = effectiveTheme() === 'light'; t.setAttribute('aria-pressed', String(light)); t.setAttribute('aria-label', light ? 'Day mode on. Switch to night mode' : 'Night mode on. Switch to day mode'); t.dataset.tip = light ? 'Switch to night mode' : 'Switch to day mode'; t.querySelector('.label').textContent = light ? 'Day mode' : 'Night mode'; }
}
export const effectiveTheme = () => { const s = state.settings?.theme; return s === 'light' || (s === 'system' && matchMedia('(prefers-color-scheme: light)').matches) ? 'light' : 'dark'; };
export async function saveSettings(patch) { const r = await call('settings.set', {patch}); state.settings = r.settings; applySettings(r.settings); return r; }

// Shell: Global 0.0.1 layout (icon-tile rail with grouped pages, route picker for small windows, search pill,
// status dot and diagnostics button). Pages are this engine's own; 0.0.1-only pages are not shown.
const GROUPS = [['Play', ['home', 'play']], ['Your world', ['server']], ['Tools', ['sql', 'content']], ['Help & settings', ['updates', 'settings']]];
function shell() {
  document.getElementById('splash')?.remove();
  const pageLink = p => h('a', {href: `#/${p.id}`, id: 'nav-' + p.id, class: 'nav-link nav-interactive', 'data-nav-route': p.id, 'data-tip': p.label, 'aria-label': p.label}, navigationTile(p.id, 21), p.id === 'updates' ? [h('span', {class: 'nav-badge', id: 'nav-err', hidden: true}), h('span', {class: 'nav-badge-dot', id: 'nav-err-dot', hidden: true})] : null);
  const nav = h('nav', {class: 'nav', 'aria-label': 'Main'}, GROUPS.map(([label, ids]) => h('div', {class: 'nav-group', role: 'group', 'aria-label': label}, h('div', {class: 'nav-group-pages'}, PAGES.filter(p => ids.includes(p.id)).map(pageLink)))));
  const picker = h('select', {class: 'input', id: 'page-picker', 'aria-label': 'Open page'}, GROUPS.map(([label, ids]) => h('optgroup', {label}, PAGES.filter(p => ids.includes(p.id)).map(p => h('option', {value: p.id, text: p.label})))));
  picker.addEventListener('change', () => navigate(picker.value));
  // Day / night switch: a sliding sun-and-moon toggle.
  const themeBtn = h('button', {type: 'button', id: 'theme-toggle', class: 'daynight', 'aria-label': 'Switch theme', 'aria-pressed': 'false'}, h('span', {class: 'dn-track', 'aria-hidden': 'true'}, h('span', {class: 'dn-sun'}, icon('sun', 15)), h('span', {class: 'dn-moon'}, icon('moon', 15)), h('span', {class: 'dn-knob'})), h('span', {class: 'label sr-only', text: 'Night mode'}));
  themeBtn.addEventListener('click', () => saveSettings({theme: effectiveTheme() === 'light' ? 'dark' : 'light'}).catch(e => toast(e.message, 'err')));
  const rail = h('aside', {class: 'rail'},
    h('span', {class: 'sr-only', id: 'brand-version', text: 'DK Engine'}),
    nav, h('div', {class: 'rail-foot'}, themeBtn, h('div', {class: 'preview-tag', id: 'edition-tag', tabindex: '0', 'aria-label': 'Test preview', 'data-tip': 'Isolated preview: its own sandbox world, ports, accounts and test database. Main is never changed.'}, icon('info', 16))));
  const search = h('label', {class: 'search-pill', for: 'global-search'}, icon('search', 18), h('input', {id: 'global-search', type: 'search', placeholder: 'Search settings, pages, files…', autocomplete: 'off', 'aria-label': 'Search settings, pages and files'}), h('kbd', {text: 'Ctrl K'}));
  search.querySelector('input').addEventListener('focus', e => { e.target.blur(); openPalette(); });
  search.addEventListener('click', e => { if (window.innerWidth <= 620) { e.preventDefault(); openPalette(); } });
  const worldChip = h('button', {type: 'button', class: 'status-dot-button', id: 'chip-world', 'data-status': 'unknown', 'aria-label': 'World status: checking. Open Server overview.', 'data-tip': 'World status: checking. Open Server overview.'}, h('i', {'aria-hidden': 'true'}));
  worldChip.addEventListener('click', () => navigate('server/overview'));
  const dev = iconBtn('Developer tools', 'terminal', () => openDevMenu(dev, {navigate}), {id: 'dev-menu', 'aria-haspopup': 'menu'});
  dev.classList.add('nav-interactive', 'diagnostics-tool'); dev.querySelector('svg')?.replaceWith(navigationGlyph('diagnostics', 18));
  const topbar = h('header', {class: 'topbar'}, h('img', {class: 'brand-logo', src: 'img/engine-logo-outline.png', alt: '', 'aria-hidden': 'true'}), h('label', {class: 'route-picker'}, h('span', {class: 'sr-only', text: 'Page'}), picker), search, h('div', {class: 'top-actions'}, worldChip, dev));
  const content = h('main', {class: 'content', id: 'content', tabindex: '-1'});
  document.body.append(h('div', {class: 'app'}, rail, h('div', {class: 'main'}, topbar, content)), h('div', {class: 'toasts', id: 'toasts', 'aria-live': 'polite'}));
}

export async function navigate(route, {anchor, replaceHash} = {}) {
  const [pageId = 'home', tab] = String(route || '').split('/'); const p = PAGES.find(x => x.id === pageId) || PAGES[0];
  const started = performance.now();
  const hash = `#/${p.id}${tab ? '/' + tab : ''}`; if (location.hash !== hash) { if (replaceHash) history.replaceState(null, '', hash); else history.pushState(null, '', hash); }
  document.querySelectorAll('.nav a').forEach(a => { if (a.id === 'nav-' + p.id) a.setAttribute('aria-current', 'page'); else a.removeAttribute('aria-current'); });
  if ($('#page-picker')) $('#page-picker').value = p.id;
  $('#content').setAttribute('aria-label', p.title); document.title = `${p.title} · DK Command Center`;
  let page = pages.get(p.id), created = false;
  if (!page) {
    const holder = h('div', {class: 'page', id: 'page-' + p.id}, h('div', {class: 'row faint'}, h('span', {class: 'spinner'}), 'Opening…')); $('#content').append(holder);
    try { const mod = await loaders[p.id](); page = mod.create({navigate, toast, call, state, on, saveSettings}); } catch (e) { replace(holder, h('div', {class: 'notice err', text: 'This page could not load: ' + e.message})); return; }
    replace(holder, page.el); page.holder = holder; pages.set(p.id, page); created = true;
  }
  if (current && current !== page) { current.hide?.(); current.holder.hidden = true; }
  page.holder.hidden = false; current = page;
  await page.show?.(tab, anchor);
  if (anchor) focusAnchor(anchor);
  else if (!created) $('#content').scrollTo({top: 0});
  requestAnimationFrame(() => reportPerf(created ? 'page-open' : 'page-switch', performance.now() - started, p.id + (tab ? '/' + tab : '')));
}
export function focusAnchor(anchor) {
  requestAnimationFrame(() => { const el = document.getElementById(anchor); if (!el) return; el.scrollIntoView({block: 'center'}); const target = el.matches('input,select,textarea,button') ? el : el.querySelector('input,select,textarea,button') || el; if (!target.hasAttribute('tabindex') && !target.matches('input,select,textarea,button,a')) target.setAttribute('tabindex', '-1'); target.focus({preventScroll: true}); el.animate?.([{boxShadow: '0 0 0 3px var(--accent)'}, {boxShadow: '0 0 0 0 transparent'}], {duration: 1400}); });
}

async function start() {
  setSplash('start');
  await sleep(220);
  setSplash('session');
  try { await boot(); }
  catch (e) {
    setSplash('session', {sub: e.message, detail: 'Session failed', overall: 20, fine: 20});
    document.getElementById('splash')?.setAttribute('aria-busy', 'false');
    const hold = document.getElementById('splash-sub'); if (hold) hold.textContent = e.message;
    return;
  }
  await sleep(160);
  setSplash('backend');
  let bootInfo;
  try { bootInfo = await call('app.boot'); }
  catch (e) {
    setSplash('backend', {sub: e.message, detail: 'Backend failed', overall: 55, fine: 55});
    document.getElementById('splash')?.setAttribute('aria-busy', 'false');
    return;
  }
  await sleep(160);
  setSplash('home', {overall: 100, fine: 100});
  // Always hold the final splash beat so load bars / steps are readable.
  await sleep(700);
  shell(); installTooltips();
  onSessionLost.add(() => toast('The launcher session ended. Close and reopen DK Command Center.', 'err', {timeout: 0}));
  state.mode = bootInfo.mode;
  $('#brand-version').textContent = `DK Engine ${bootInfo.engineVersion || '-'}`;
  if (bootInfo.mode === 'install') $('#edition-tag').remove();
  state.settings = bootInfo.settings; applySettings(bootInfo.settings);
  matchMedia('(prefers-color-scheme: light)').addEventListener('change', () => applySettings(state.settings));
  window.addEventListener('popstate', () => route(location.hash));
  document.addEventListener('keydown', e => { if ((e.ctrlKey || e.metaKey) && e.key.toLowerCase() === 'k') { e.preventDefault(); openPalette(); } });
  // World chip: always visible, so status polls at the configured interval while the window is visible.
  const worldPoll = poller(async signal => { const w = await call('world.status', {}, {signal}); state.world = w; return w; }, {interval: (state.settings.statusPollSeconds || 3) * 1000, name: 'world'}).start();
  on('settings', s => worldPoll.setInterval((s.statusPollSeconds || 3) * 1000));
  on('world', renderWorldChip);
  poller(async signal => { const r = await call('diag.sources', {}, {signal}); const errs = Object.values(r.counts || {}).reduce((a, c) => a + (c.errors || 0), 0); state.errors = errs; const b = $('#nav-err'), d = $('#nav-err-dot'); b.hidden = d.hidden = !errs; b.textContent = errs > 99 ? '99+' : String(errs); b.title = `${errs} error lines in logs`; return r; }, {interval: 10000, name: 'errors'}).start();
  mountUpdateCard({navigate}); watchClose(); calmWhenIdle();
  await route(location.hash || '#/' + (bootInfo.settings.startupPage || 'home'), true);
  reportPerf('first-render', performance.now() - t0, 'shell + first page');
}
// Living effects (world orb, live dots) run while the launcher is in use and settle into a still glow when the
// window is in the background or untouched for 90 s: a continuous animation costs a CPU core's worth of compositing.
function calmWhenIdle() {
  const root = document.documentElement; let timer = 0, last = 0;
  const calm = () => { clearTimeout(timer); root.classList.add('calm'); };
  const wake = () => { const now = Date.now(); if (now - last < 1000 && !root.classList.contains('calm')) return; last = now; root.classList.remove('calm'); clearTimeout(timer); timer = setTimeout(calm, 90000); };
  window.addEventListener('focus', wake); window.addEventListener('blur', calm);
  for (const e of ['pointermove', 'pointerdown', 'keydown', 'wheel']) window.addEventListener(e, () => { if (document.hasFocus()) wake(); }, {passive: true});
  if (document.hasFocus()) wake(); else calm();
}
function route(hash, first) { const m = /^#\/([a-z]+)(?:\/([a-z]+))?/.exec(hash || ''); return navigate(m ? m[1] + (m[2] ? '/' + m[2] : '') : 'home', {replaceHash: first}); }
function renderWorldChip(w) {
  const chip = $('#chip-world'); if (!chip) return;
  const label = {running: w.stale ? 'Running (stale)' : 'Running', starting: 'Starting', stopping: 'Stopping', stopped: 'Stopped', unknown: 'Unknown'}[w.status] || String(w.status || 'Unknown');
  chip.dataset.status = w.stale || w.lastError ? 'error' : w.status === 'running' ? 'running' : w.status === 'stopped' ? 'stopped' : ['starting', 'stopping'].includes(w.status) ? 'error' : 'unknown';
  const pop = w.status === 'running' && w.population?.known ? ` · ${w.population.humans} players · ${w.population.bots} bots` : '';
  chip.dataset.tip = `World: ${label}${pop}${w.lastError ? ' · ' + String(w.lastError).slice(0, 300) : ''} · Open Server overview`;
  chip.setAttribute('aria-label', chip.dataset.tip);
}
start();
