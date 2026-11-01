// Home: world status and the right next action, honest progress, players vs bots, events, problems, quick settings.
import {h, icon, replace, clear} from '../core/dom.js';
import {call} from '../core/api.js';
import {poller} from '../core/poll.js';
import {state, on} from '../core/state.js';
import * as f from '../core/format.js';
import {button, card, stat, pill, notice, switchRow, round, toast, empty, textField, setError} from '../ui/components.js';
import {startWorld, stopWorld, restartWorld, storageSwitch} from './world-actions.js';
import {storagePresentation} from './world-presentation.js';

export function create({navigate}) {
  const heroTitle = h('div', {class: 'hero-title', text: 'Checking your world…'});
  const heroSub = h('p', {class: 'muted wrap-any'});
  const heroPills = h('div', {class: 'row wrap'});
  const heroActions = h('div', {class: 'row wrap hero-actions'});
  const progressHost = h('div', {class: 'stack tight', hidden: true, 'aria-live': 'polite'});
  const orb = h('div', {class: 'world-orb', 'aria-hidden': 'true'}, h('span', {class: 'orb-glow'}), h('span', {class: 'orb-ripple'}), h('span', {class: 'orb-ripple r2'}), h('span', {class: 'orb-arc'}), h('span', {class: 'orb-core'}));
  const firstBox = h('div', {class: 'first-start', hidden: true});
  const heroFoot = h('div', {class: 'hero-foot'}, storageSwitch(), h('span', {class: 'faint', text: state.mode === 'install' ? 'Port 7996 · this PC only' : 'Port 17996 · this PC only'}));
  const hero = h('section', {class: 'card hero', 'aria-label': 'World'},
    h('div', {class: 'hero-top'}, h('div', {class: 'stack tight grow'}, h('div', {class: 'row wrap'}, h('span', {class: 'eyebrow', text: state.mode === 'install' ? 'Your world' : 'Sandbox world'}), heroPills), heroTitle, heroSub), orb),
    firstBox, progressHost, heroActions, heroFoot);

  const humans = stat({label: 'Players online', value: '—', note: 'Real people signed in', tint: 'mint', valueId: 'v-humans', open: {label: 'Open players', onClick: () => navigate('server/players')}});
  const bots = stat({label: 'Bots', value: '—', note: 'Simulated players', tint: 'amber', valueId: 'v-bots', open: {label: 'Open bot settings', onClick: () => navigate('server/world', {anchor: 'set-bots'})}});
  const capacity = stat({label: 'Player cap', value: '—', note: 'Maximum human players', tint: 'violet', valueId: 'v-cap', open: {label: 'Open capacity', onClick: () => navigate('server/capacity')}});
  const storage = stat({label: 'Storage', value: '—', note: '', tint: 'rose', small: true, valueId: 'v-storage', noteId: 'n-storage', open: {label: 'Open SQL & Storage', onClick: () => navigate('sql/overview')}});
  const stats = h('div', {class: 'grid four stretch', id: 'card-pop'}, humans, bots, capacity, storage);

  const eventsList = h('div', {class: 'rows'}, empty('Loading recent events…'));
  const events = card({title: 'Recent events', desc: 'What the launcher and world actually did', id: 'card-events', actions: [button('All', {kind: 'ghost', size: 'small', onClick: () => navigate('updates/timeline')})], children: [eventsList]});
  const problemsList = h('div', {class: 'stack tight'}, empty('Running checks…'));
  const problems = card({title: 'Needs attention', id: 'card-problems', actions: [button('Health', {kind: 'ghost', size: 'small', onClick: () => navigate('updates/health')})], children: [problemsList]});
  const quickRows = h('div', {class: 'rows'}, empty('Loading settings…'));
  const quick = card({title: 'Quick settings', desc: 'Same switches as Server › World settings', id: 'card-quick', children: [quickRows]});
  const versionBody = h('div', {class: 'stack tight'});
  const version = card({title: 'Installation', id: 'card-version', children: [versionBody], actions: [round('Open Updates', () => navigate('updates/updates'), {small: true})]});
  const connBody = h('div', {class: 'stack tight'});
  const conn = card({title: 'Connection', id: 'card-conn', children: [connBody], actions: [round('Open Play & Connect', () => navigate('play/join'), {small: true})]});

  const el = h('div', {class: 'stack loose'}, hero, h('div', {class: 'section-title'}, h('h2', {text: 'Players and capacity'})), stats,
    h('div', {class: 'split'}, h('div', {class: 'stack'}, events, problems), h('div', {class: 'stack'}, quick, conn, version)));

  let world = null, cap = null, stor = null, settingsLoaded = false, review = null, first = null;
  // First start stays one click: the existing settings review is shown inline (with its defaults) and saved by the
  // same Start world press, instead of a dialog after it.
  function firstForm() {
    if (first) return first;
    const cur = review.settings || {};
    const name = textField({label: 'Server name', value: cur.name || 'Dekaron Online', maxLength: 64, help: 'Shown in the client, the world list and the in-game server display.'});
    const toggles = [['starterPack', 'Starter pack', 'New characters get the starter pack', cur.starterPack !== false], ['fieldPk', 'PK on open maps', 'Hold Ctrl to attack players on open PvP maps', cur.fieldPk !== false], ['npcPlayers', 'Bots', 'Experimental simulated players', cur.npcPlayers === true]]
      .map(([key, title, desc, on]) => { const i = h('input', {type: 'checkbox', role: 'switch', checked: on, id: 'fs-' + key}); return {key, input: i, el: h('label', {class: 'fs-toggle', for: 'fs-' + key, 'data-tip': desc}, h('span', {class: 'switch'}, i), h('span', {text: title}))}; });
    first = {name, toggles, el: h('div', {class: 'stack tight'}, h('div', {class: 'fs-head'}, icon('sparkle', 18), h('strong', {text: 'First start: choose your world'}), h('span', {class: 'faint', text: 'Saved when you press Start world · change any time in Server › World settings'})), h('div', {class: 'fs-grid'}, name, h('div', {class: 'fs-toggles'}, toggles.map(t => t.el))))};
    return first;
  }
  async function start() {
    if (review && review.reviewed === false && first) {
      const scope = review.scope, cur = review.settings || {}, n = first.name.input.value.trim();
      if (!n || n.length > 64) { setError(first.name, 'Use a server name of 1-64 printable characters.'); return; }
      try {
        if (n !== cur.name) await call('world.settings.set', {scope, change: {name: n}});
        for (const t of first.toggles) { const was = t.key === 'npcPlayers' ? cur.npcPlayers === true : cur[t.key] !== false; if (t.input.checked !== was) await call('world.settings.set', {scope, change: {[t.key]: t.input.checked}}); }
        await call('world.review.complete', {scope}); review.reviewed = true; firstBox.hidden = true;
      } catch (e) { toast(e.message, 'err'); return; }
      return startWorld({host: progressHost, reviewed: true});
    }
    return startWorld({host: progressHost});
  }
  function renderWorld(w) {
    world = w; const running = w.status === 'running', busy = w.busy, stopped = w.status === 'stopped';
    const isFirst = stopped && !busy && review && review.reviewed === false;
    const starting = w.status === 'starting' || (!running && busy && /start|restart/.test(busy.kind)), stopping = w.status === 'stopping' || (busy && busy.kind === 'world.stop');
    hero.dataset.state = running && !stopping ? 'running' : stopped && !busy ? 'stopped' : 'busy';
    heroTitle.textContent = stopping ? 'Saving and stopping…' : running ? (w.name ? `${w.name} is live` : 'Your world is live') : starting ? 'Starting your world…' : isFirst ? 'Welcome! Your world is one click away' : 'Your world is resting';
    heroSub.textContent = running ? `Game address ${w.url} · Saves: ${w.storageMode === 'sqlserver' ? 'SQL Server' : w.storageMode === 'json' ? 'local files' : 'checking'} · ${w.mode === 'hosted' ? 'Hosted world' : 'Local world'} · up ${f.duration(w.uptimeMs)}${w.adopted ? ' · attached (started outside this launcher)' : ''}` : isFirst ? (state.mode === 'install' ? 'Name it, choose your settings and start your world. Your Global game files stay in place.' : 'Name it, pick a few options and press Start world. Everything runs in the preview sandbox with its own accounts; the installed game is only read.') : (state.mode === 'install' ? 'Start whenever you are ready. Local and SQL Server storage are available below.' : 'Start whenever you are ready. The preview world uses its own accounts, port 17996 and prepared Global data read-only from the installed game.');
    replace(heroPills, pill(running ? (w.stale ? 'Running · status stale' : 'Running') : stopped ? 'Stopped' : w.status, running ? (w.stale ? 'warn' : 'ok') : stopped ? '' : 'warn', {live: running}), running && w.hostMode ? pill(w.hostMode === 'local' ? 'This PC only' : w.hostMode === 'friends' ? 'Invite only' : 'Open', 'info') : null);
    if (isFirst) { if (!firstBox.firstChild) firstBox.append(firstForm().el); firstBox.hidden = false; } else firstBox.hidden = true;
    clear(heroActions);
    if (running) heroActions.append(
      button('DX11 Client', {kind: 'primary', size: 'large', ico: 'play', onClick: () => launch('native')}), button('DX11 Fullscreen', {size: 'large', onClick: () => launch('native-fullscreen')}),
      button('Desktop App', {kind: 'ghost', onClick: () => launch('desktop')}), button('Web Browser', {kind: 'ghost', onClick: () => launch('browser')}),
      h('span', {class: 'grow'}), button('Restart', {kind: 'ghost', ico: 'refresh', disabled: !!busy || w.adopted, title: w.adopted ? 'This world was started outside this launcher.' : undefined, onClick: () => restartWorld({host: progressHost})}), button('Stop world', {kind: 'danger', ico: 'stop', disabled: !!busy, attrs: {id: 'act-stop'}, onClick: () => stopWorld({host: progressHost})}));
    else heroActions.append(button(busy ? busy.title + '…' : 'Start world', {kind: 'primary', size: 'large', ico: 'power', disabled: !!busy || !stopped, attrs: {id: 'act-start'}, onClick: () => start()}), button('Host friends', {size: 'large', onClick: () => navigate('play/host')}), button('Join a server', {kind: 'ghost', onClick: () => navigate('play/join')}));
    heroFoot.hidden = running;
    const p = w.population;
    humans.querySelector('.stat-value').firstChild.textContent = running && p?.known ? f.n(p.humans) : running && p?.total !== null && p?.total !== undefined ? '?' : '—';
    bots.querySelector('.stat-value').firstChild.textContent = running && p?.known ? f.n(p.bots) : '—';
    humans.querySelector('.stat-note').textContent = running ? (p?.known ? `${f.n(p.total)} total active` : 'Split unavailable from this server') : 'World stopped';
    bots.querySelector('.stat-note').textContent = running ? (p?.known ? 'Counted separately from people' : 'Unknown') : 'World stopped';
    renderConn();
    renderStorage();
  }
  function renderStorage() {
    const shown = storagePresentation(world, stor || {});
    storage.querySelector('.stat-value').firstChild.textContent = shown.label;
    storage.querySelector('.stat-note').textContent = shown.note;
  }
  function launch(target) { navigate('play/play').then(() => window.dispatchEvent(new CustomEvent('dk-target', {detail: target}))); }
  function renderConn() {
    if (!world) return;
    replace(connBody, h('div', {class: 'row between'}, h('span', {class: 'muted', text: 'Mode'}), h('strong', {text: world.status === 'running' ? (world.mode === 'hosted' ? 'Hosting friends' : 'Local play') : 'Not running'})),
      h('div', {class: 'row between'}, h('span', {class: 'muted', text: 'Listening'}), h('span', {class: 'mono', text: world.listenHost ? `${world.listenHost}:${world.port}` : '—'})),
      h('div', {class: 'row between'}, h('span', {class: 'muted', text: 'Relay'}), h('span', {text: world.relayEnabled ? 'On' : 'Off'})));
  }
  async function loadOnce() {
    try { const a = await call('about.info'); replace(versionBody, ...(state.mode === 'install' ? [h('div', {class: 'row between'}, h('span', {class: 'muted', text: 'Installed DK Engine'}), h('strong', {class: 'num', text: a.engineVersion || '—'}))] : [h('div', {class: 'row between'}, h('span', {class: 'muted', text: 'Installed game (Main)'}), h('strong', {class: 'num', text: a.installedVersion || '—'})), h('div', {class: 'row between'}, h('span', {class: 'muted', text: 'Preview sandbox engine'}), h('strong', {class: 'num', text: a.engineVersion || '—'})), h('div', {class: 'row between'}, h('span', {class: 'muted', text: 'Published release'}), h('strong', {class: 'num', text: a.published}))]), h('div', {class: 'row between'}, h('span', {class: 'muted', text: 'Update'}), h('span', {id: 'home-update', text: 'Checking…'}))); } catch (e) { replace(versionBody, notice('err', e.message)); }
  }
  async function loadSlow() {
    try { const c = await call('world.capacity.get'); cap = c; capacity.querySelector('.stat-value').firstChild.textContent = f.n(c.settings?.maxPlayers); const pop = state.world?.population; capacity.querySelector('.stat-note').textContent = c.running ? `${c.live ? f.n(c.live.players) + ' connected now · ' : pop?.known ? f.n(pop.humans) + ' connected now · ' : ''}memory ${c.settings.memoryMB ? f.n(c.settings.memoryMB) + ' MB' : 'automatic'}` : 'Saved for next start'; } catch {}
    try { stor = await call('storage.get'); renderStorage(); } catch {}
    loadQuick();
    try { const r = await call('diag.health'); const bad = r.checks.filter(c => c.state === 'error' || c.state === 'warn'); replace(problemsList, bad.length ? bad.slice(0, 6).map(c => notice(c.state === 'error' ? 'err' : 'warn', `${c.name}: ${c.detail}`)) : [notice('ok', `All ${r.checks.length} checks pass. ${state.errors ? state.errors + ' error lines are in the logs.' : ''}`)], state.errors ? button('Open live logs', {kind: 'ghost', size: 'small', onClick: () => navigate('updates/logs')}) : null); } catch (e) { replace(problemsList, notice('err', 'Health check failed: ' + e.message)); }
  }
  async function loadQuick() {
    try {
      const s = await call('world.settings.get', {scope: world?.mode === 'hosted' ? 'friends' : 'local'}); const scope = s.scope;
      review = s.live ? null : {reviewed: s.reviewed, settings: s.settings, scope}; if (world) renderWorld(world);
      const set = async (key, val) => { const r = await call('world.settings.set', {scope, change: {[key]: val}}); toast(r.message, 'ok'); };
      replace(quickRows, switchRow({title: 'Bots (experimental)', desc: 'Simulated players; off by default', checked: s.settings.npcPlayers === true, applies: s.live ? 'now' : 'next-start', onChange: v => set('npcPlayers', v)}),
        switchRow({title: 'Allow PK on open maps', desc: 'Hold Ctrl to attack players on open PvP maps', checked: s.settings.fieldPk !== false, applies: s.live ? 'now' : 'next-start', onChange: v => set('fieldPk', v)}),
        switchRow({title: 'Starter pack for new characters', checked: s.settings.starterPack !== false, applies: s.live ? 'now' : 'next-start', onChange: v => set('starterPack', v)}),
        h('p', {class: 'faint', text: s.live ? 'Changes apply to the running world.' : 'The world is stopped; changes are saved for its next start.'}));
      settingsLoaded = true;
    } catch (e) { replace(quickRows, notice('warn', e.message)); }
  }
  const eventsPoll = poller(async signal => {
    const r = await call('diag.timeline', {limit: 8}, {signal});
    replace(eventsList, r.events.length ? r.events.slice().reverse().map(e => h('div', {class: 'r'}, h('span', {class: ['event-dot', e.level === 'ok' ? 'ok' : e.level]}), h('div', {class: 'grow stack tight'}, h('span', {class: 'wrap-any', text: e.message}), h('span', {class: 'faint', text: `${e.area} · ${f.ago(e.at)}`})))) : [empty('No events yet.')]);
    return r;
  }, {interval: 5000, active: () => visible, name: 'home-events'});
  let visible = false, lastStatus = null;
  on('world', w => { renderWorld(w); if (lastStatus && lastStatus !== w.status && visible) loadSlow(); lastStatus = w.status; });
  on('updates', u => { const el2 = versionBody.querySelector('#home-update'); if (el2) el2.textContent = u.available ? `${u.available.version} available${u.available.fixture ? ' (test fixture)' : ''}` : u.error ? 'Check unavailable' : 'Up to date'; });
  loadOnce();
  return {el, show() { visible = true; eventsPoll.start(); loadSlow(); if (state.world) renderWorld(state.world); }, hide() { visible = false; eventsPoll.stop(); }};
}
