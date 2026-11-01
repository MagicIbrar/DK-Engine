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

const t0 = performance.now();
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

function shell() {
  const nav = h('nav', {class: 'nav', 'aria-label': 'Main'}, PAGES.map(p => h('a', {href: `#/${p.id}`, id: 'nav-' + p.id, 'data-tip': p.label, 'aria-label': p.label}, h('span', {class: 'nav-ico'}, icon(p.ico, 20)), h('span', {class: 'nav-label', text: p.label}), p.id === 'updates' ? [h('span', {class: 'nav-badge', id: 'nav-err', hidden: true}), h('span', {class: 'nav-badge-dot', id: 'nav-err-dot', hidden: true})] : null)));
  // Day / night switch: a sliding sun-and-moon toggle.
  const themeBtn = h('button', {type: 'button', id: 'theme-toggle', class: 'daynight', 'aria-label': 'Switch theme', 'aria-pressed': 'false'}, h('span', {class: 'dn-track', 'aria-hidden': 'true'}, h('span', {class: 'dn-sun'}, icon('sun', 15)), h('span', {class: 'dn-moon'}, icon('moon', 15)), h('span', {class: 'dn-knob'})), h('span', {class: 'label', text: 'Night mode'}));
  themeBtn.addEventListener('click', () => saveSettings({theme: effectiveTheme() === 'light' ? 'dark' : 'light'}).catch(e => toast(e.message, 'err')));
  const rail = h('aside', {class: 'rail'},
    h('div', {class: 'brand'}, h('div', {class: 'brand-mark', 'aria-hidden': 'true'}, h('span', {text: 'DK'})), h('div', {class: 'brand-text'}, h('div', {class: 'brand-name', text: 'Command Center'}), h('div', {class: 'brand-sub', id: 'brand-version', text: 'DK Engine'}))),
    nav, h('div', {class: 'rail-foot'}, themeBtn, h('div', {class: 'preview-tag', id: 'edition-tag', 'data-tip': 'Isolated preview: its own sandbox world, ports, accounts and test database. Main is never changed.', text: 'Test preview'})));
  const search = h('label', {class: 'search-pill', for: 'global-search'}, icon('search', 18), h('input', {id: 'global-search', type: 'search', placeholder: 'Search settings, pages, files…', autocomplete: 'off', 'aria-label': 'Search settings, pages and files'}), h('kbd', {text: 'Ctrl K'}));
  search.querySelector('input').addEventListener('focus', e => { e.target.blur(); openPalette(); });
  const worldChip = h('button', {type: 'button', class: 'status-chip', id: 'chip-world', 'aria-label': 'World status'}, pill('Checking', ''), h('span', {class: 'label', text: 'World'}));
  worldChip.addEventListener('click', () => navigate('server/overview'));
  const dev = iconBtn('Developer tools', 'terminal', () => openDevMenu(dev, {navigate}), {id: 'dev-menu', 'aria-haspopup': 'menu'});
  const topbar = h('header', {class: 'topbar'}, h('div', {class: 'title-wrap'}, h('h1', {id: 'page-title', text: 'Command Center'}), h('div', {class: 'subtitle', id: 'page-subtitle'})), search, h('div', {class: 'top-actions'}, worldChip, dev));
  const content = h('main', {class: 'content', id: 'content', tabindex: '-1'});
  document.body.append(h('div', {class: 'app'}, rail, h('div', {class: 'main'}, topbar, content)), h('div', {class: 'toasts', id: 'toasts', 'aria-live': 'polite'}));
}

export async function navigate(route, {anchor, replaceHash} = {}) {
  const [pageId = 'home', tab] = String(route || '').split('/'); const p = PAGES.find(x => x.id === pageId) || PAGES[0];
  const started = performance.now();
  const hash = `#/${p.id}${tab ? '/' + tab : ''}`; if (location.hash !== hash) { if (replaceHash) history.replaceState(null, '', hash); else history.pushState(null, '', hash); }
  document.querySelectorAll('.nav a').forEach(a => { if (a.id === 'nav-' + p.id) a.setAttribute('aria-current', 'page'); else a.removeAttribute('aria-current'); });
  $('#page-title').textContent = p.title; $('#page-subtitle').textContent = p.subtitle;
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
  shell(); installTooltips();
  try { await boot(); }
  catch (e) { replace($('#content'), h('div', {class: 'page'}, h('div', {class: 'notice err', text: e.message}))); return; }
  onSessionLost.add(() => toast('The launcher session ended. Close and reopen DK Command Center.', 'err', {timeout: 0}));
  let bootInfo; try { bootInfo = await call('app.boot'); } catch (e) { toast(e.message, 'err'); return; }
  state.mode = bootInfo.mode;
  $('#brand-version').textContent = `DK Engine ${bootInfo.engineVersion || '—'}`;
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
  const map = {running: ['ok', w.stale ? 'Running (stale)' : 'Running'], starting: ['warn', 'Starting'], stopping: ['warn', 'Stopping'], stopped: ['', 'Stopped'], unknown: ['warn', 'Unknown']};
  const [kind, text] = map[w.status] || ['', w.status];
  replace(chip, pill(text, kind, {live: w.status === 'running'}), h('span', {class: 'label', text: w.status === 'running' && w.population?.known ? `${w.population.humans} players · ${w.population.bots} bots` : 'World'}));
}
start();
