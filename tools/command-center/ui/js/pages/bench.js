// Test Bench: a real game client inside the launcher (signed in as the local world's local admin) with a tooling
// sidebar and the action/file watcher. The native view sits over the placeholder below and is hidden while any
// launcher overlay (dialog, menu, search) is open, because a native view always draws above page content.
import {h, icon, replace, clear} from '../core/dom.js';
import {call} from '../core/api.js';
import {poller} from '../core/poll.js';
import {state, on} from '../core/state.js';
import * as f from '../core/format.js';
import {button, card, pill, notice, switchRow, toast, jobView, seg, iconBtn, empty, copyText} from '../ui/components.js';
import {restartWorld, startWorld} from './world-actions.js';

export function createBench({navigate}) {
  const view = h('div', {class: 'bench-view', id: 'bench', role: 'region', 'aria-label': 'Embedded game client'}, h('div', {class: 'stack tight', style: null}, icon('play', 28), h('span', {text: 'The embedded client appears here.'})));
  const status = h('div', {class: 'row wrap'}), prog = h('div', {class: 'stack tight', hidden: true}), guildBox = h('div', {'aria-live': 'polite'});
  const openBtn = button('Open client as local admin', {kind: 'primary', ico: 'play', onClick: () => open()});
  const clientBtns = [button('Reload', {ico: 'refresh', kind: 'ghost', onClick: () => call('bench.reload').catch(e => toast(e.message, 'err'))}), button('Dev tools', {ico: 'terminal', kind: 'ghost', onClick: () => call('bench.devtools').catch(e => toast(e.message, 'err'))}), button('Screenshot', {ico: 'download', kind: 'ghost', onClick: async () => { try { const r = await call('bench.screenshot'); toast('Saved ' + r.file, 'ok'); } catch (e) { toast(e.message, 'err'); } }}), button('Close client', {kind: 'ghost', ico: 'close', onClick: async () => { await call('bench.close'); opened = false; update(); }})];
  const ctrls = h('div', {class: 'row wrap'}, openBtn, clientBtns);
  // Sidebar tools
  const worldBox = h('div', {class: 'stack tight'}), quick = h('div', {class: 'rows'}), toolsBox = h('div', {class: 'row wrap'}), metrics = h('div', {class: 'stack tight'});
  const watchOn = switchRow({title: 'Action / file watcher', desc: 'Shows every file the game loads, every world action it sends, console errors and files the local world writes.', checked: false, onChange: v => call('bench.watch', {enabled: v}).then(r => { watching = r.watching; })});
  let kind = 'all', filter = '', paused = false, after = 0, rows = [], fsAfter = 0, watching = false, opened = false;
  const kinds = seg([{value: 'all', label: 'All'}, {value: 'asset', label: 'Files'}, {value: 'api', label: 'Actions'}, {value: 'error', label: 'Errors'}, {value: 'console', label: 'Console'}, {value: 'fs', label: 'Writes'}], 'all', v => { kind = v; render(); }, {label: 'Watcher filter'});
  const q = h('input', {class: 'input', type: 'search', placeholder: 'Filter (file name, route, text)', 'aria-label': 'Filter watcher'}); q.addEventListener('input', () => { filter = q.value.toLowerCase(); render(); });
  const counts = h('div', {class: 'row wrap'});
  const list = h('div', {class: 'log', role: 'log', 'aria-label': 'Watcher events', tabindex: '0'});
  const watchCard = card({title: 'Watcher', children: [watchOn, kinds, q, counts, list, h('div', {class: 'row wrap'}, iconBtn('Pause', 'pause', () => { paused = !paused; }, {'aria-pressed': 'false'}), iconBtn('Clear', 'trash', async () => { await call('bench.clear'); rows = []; render(); }), iconBtn('Copy visible', 'copy', () => copyText(visible().map(line).join('\n'), 'Copied.')), button('Open live logs', {size: 'small', kind: 'ghost', onClick: () => navigate('updates/logs')}))]});
  const side = h('div', {class: 'bench-side'}, card({title: 'World', children: [worldBox]}), card({title: 'Quick switches', children: [quick]}), card({title: 'Builders', desc: 'Open in this embedded client (it is the primary GM account).', children: [toolsBox]}), card({title: 'Live', children: [metrics]}), watchCard);
  const el = h('div', {class: 'stack'}, card({title: 'Test Bench', desc: 'A real client of your world, signed in as its local admin (owner characters and guild prepared by the server). The embedded client connects to your local world.', children: [status, guildBox, ctrls, prog]}), h('div', {class: 'bench'}, view, side));

  // ---- keep the native view glued to the placeholder
  let visibleTab = false, raf = 0, lastRect = '';
  const overlayOpen = () => !!document.querySelector('.scrim, .menu, .update-card');
  // The native view is clipped to the scrolling content area so it never covers the navigation or top bar.
  const clipRect = () => { const c = document.getElementById('content')?.getBoundingClientRect(); return c ? {clipX: c.left, clipY: c.top, clipWidth: c.width, clipHeight: c.height} : {}; };
  function sync() { cancelAnimationFrame(raf); raf = requestAnimationFrame(() => { if (!opened) return; const r = view.getBoundingClientRect(), clip = clipRect(); const vis = visibleTab && !document.hidden && !overlayOpen() && r.width > 50 && r.height > 50; const key = [r.left, r.top, r.width, r.height, clip.clipX, clip.clipY, clip.clipWidth, clip.clipHeight].map(Math.round).join(',') + vis; if (key === lastRect) return; lastRect = key; call('bench.bounds', {x: r.left, y: r.top, width: Math.max(0, r.width), height: Math.max(0, r.height), visible: vis, ...clip}).catch(() => {}); }); }
  new ResizeObserver(sync).observe(view); window.addEventListener('resize', sync); document.getElementById('content')?.addEventListener('scroll', sync, {passive: true}); document.addEventListener('visibilitychange', sync);
  new MutationObserver(sync).observe(document.body, {childList: true});
  async function open() {
    const r = view.getBoundingClientRect();
    let job; try { job = await call('bench.open', {x: r.left, y: r.top, width: r.width, height: r.height, ...clipRect()}); } catch (e) { toast(e.message, 'err'); return; }
    const v = jobView(job, {compact: true}); prog.replaceChildren(v); prog.hidden = false;
    const final = await v.done; if (final?.state === 'succeeded') { opened = true; lastRect = ''; sync(); prog.hidden = true; toast('Test Bench client opened.', 'ok'); }
    else if (final && /Owner guild preparation/i.test(final.error || '')) prog.replaceChildren(notice('warn', final.error + ' The engine keeps preparing in the background; progress is shown above.', {action: button('Retry', {size: 'small', onClick: () => open()})}));
    else if (final) toast(final.error, 'err');
    update();
  }
  function update() {
    const w = state.world || {};
    replace(status, opened ? pill('Client open · local admin', 'ok', {live: true}) : pill('Client closed', ''), w.status === 'running' ? pill(`World running · ${w.population?.known ? `${w.population.humans} players · ${w.population.bots} bots` : ''}`, 'ok') : pill('World stopped', 'warn'), watching ? pill('Watching', 'gold', {live: true}) : null);
    openBtn.disabled = w.status !== 'running' || w.mode !== 'local' || opened;
    for (const b of clientBtns) { b.disabled = !opened; b.dataset.tip = opened ? '' : 'Open the client first.'; }
    const g = w.status === 'running' && w.mode === 'local' ? w.adminGuild : null;
    replace(guildBox, g && g.complete !== true && Number(g.eligible) > 0 ? notice('info', `The engine is preparing the local admin's characters and guild: ${f.n(g.enrolled || 0)} of ${f.n(g.eligible)} enrolled. This runs once for a new world and can take several minutes; opening the client waits for it.`) : null);
    replace(worldBox, w.status === 'running' ? h('div', {class: 'stack tight'}, h('span', {class: 'muted wrap-any', text: `${w.name || 'World'} · ${w.url}`}), h('div', {class: 'row wrap'}, button('Restart world', {size: 'small', ico: 'refresh', onClick: () => restartWorld()}), button('Server page', {size: 'small', kind: 'ghost', onClick: () => navigate('server/overview')}))) : h('div', {class: 'stack tight'}, notice('info', 'Start the local local world to use the Test Bench.'), button('Start world', {kind: 'primary', size: 'small', onClick: () => startWorld()})));
    replace(toolsBox, button('Item Builder', {size: 'small', ico: 'sword', disabled: !w.builderReady, onClick: () => call('world.tool', {tool: 'itembuilder'}).then(r => toast(r.message, 'ok'), e => toast(e.message, 'err'))}), button('Map Builder', {size: 'small', ico: 'map', disabled: !w.builderReady, onClick: () => call('world.tool', {tool: 'mapbuilder'}).then(r => toast(r.message, 'ok'), e => toast(e.message, 'err'))}), !w.builderReady ? h('span', {class: 'faint', text: 'Ready once the admin has entered a character.'}) : null);
  }
  async function loadQuick() {
    if (state.world?.status !== 'running') { replace(quick, empty('World stopped.')); return; }
    try { const s = await call('world.settings.get', {scope: 'local'}); const set = async (k, val) => { const r = await call('world.settings.set', {scope: 'local', change: {[k]: val}}); toast(r.message, 'ok'); };
      replace(quick, switchRow({title: 'Bots', checked: s.settings.npcPlayers === true, onChange: x => set('npcPlayers', x)}), switchRow({title: 'PK on open maps', checked: s.settings.fieldPk !== false, onChange: x => set('fieldPk', x)}), switchRow({title: 'Starter pack', checked: s.settings.starterPack !== false, onChange: x => set('starterPack', x)})); } catch (e) { replace(quick, notice('warn', e.message)); }
  }
  // ---- watcher feed
  const line = e => e.kind === 'asset' || e.kind === 'api' ? `${f.time(e.at)} ${e.kind === 'api' ? 'ACTION' : 'FILE'} ${e.method || ''} ${e.status ?? ''} ${e.url}${e.ms !== undefined && e.ms !== null ? ' ' + e.ms + ' ms' : ''}${e.bytes ? ' ' + f.bytes(e.bytes) : ''}${e.cache && e.cache !== 'network' ? ' (' + e.cache + ')' : ''}${e.body ? ' ' + e.body : ''}${e.reply ? ' → ' + e.reply : ''}` : e.kind === 'fs' ? `${f.time(e.at)} WRITE ${e.type} ${e.rel}${e.size !== undefined ? ' ' + f.bytes(e.size) : ''}${e.removed ? ' (removed)' : ''}` : `${f.time(e.at)} ${e.kind.toUpperCase()} ${e.text}${e.source ? '  @ ' + e.source : ''}`;
  const visible = () => rows.filter(e => (kind === 'all' || e.kind === kind) && (!filter || line(e).toLowerCase().includes(filter)));
  function render() {
    const vis = visible().slice(-800);
    clear(list).append(...(vis.length ? vis.map(e => { const ln = h('div', {class: ['ln', e.kind === 'error' ? 'error' : e.state === 'failed' || (e.status >= 400) ? 'warn' : null]}, line(e)); if (e.file) { ln.style.cursor = 'pointer'; ln.title = 'Open in Code & files'; ln.addEventListener('click', () => { navigate('updates/files').then(() => window.dispatchEvent(new CustomEvent('dk-open-file', {detail: {...e.file, kind: 'name'}}))); }); } if (e.kind === 'fs' && !e.private && !e.removed && !e.dir) { ln.style.cursor = 'pointer'; ln.addEventListener('click', () => { const rel = e.rel.replace(/^engine\//, ''); navigate('updates/files').then(() => window.dispatchEvent(new CustomEvent('dk-open-file', {detail: {root: 'engine', rel, kind: 'name'}}))); }); } return ln; }) : [h('div', {class: 'ln faint', text: watching ? 'Waiting for activity… cast a skill, click or change maps in the client.' : 'Turn the watcher on to see the game\'s file loads, actions, errors and the local world\'s file writes.'})]));
    list.scrollTop = list.scrollHeight;
  }
  const wp = poller(async signal => {
    if (paused) return;
    const r = await call('bench.events', {after}, {signal}); after = r.last; rows.push(...r.events);
    if (watching) { const fsr = await call('watch.fs.poll', {after: fsAfter}, {signal}); if (fsr.events.length) { fsAfter = fsr.events.at(-1).seq; rows.push(...fsr.events.map(e => ({...e, kind: 'fs'}))); } }
    if (rows.length > 4000) rows.splice(0, rows.length - 4000);
    replace(counts, ...Object.entries(r.counts).map(([k, n]) => pill(`${k} ${f.n(n)}`, k === 'error' && n ? 'err' : '')));
    if (r.events.length || watching) render();
    opened = r.open; watching = r.watching; watchOn.input.checked = watching;
  }, {interval: 700, active: () => visibleTab, name: 'bench-watch'});
  const mp = poller(async signal => { const m = await call('world.metrics', {}, {signal}); replace(metrics, m.process ? h('div', {class: 'stack tight'}, h('span', {text: `CPU ${m.process.cpuPercent ?? '…'} % · ${f.n(m.process.workingSetMB)} MB`}), h('span', {class: 'faint', text: m.latency ? `Status round trip p50 ${f.n(m.latency.p50, 1)} ms` : ''}), m.capacity?.live ? h('span', {class: 'faint', text: `${m.capacity.live.players} players · ${f.n(m.capacity.live.sentKBps)} KB/s sent`}) : null) : empty('World stopped.')); }, {interval: 4000, active: () => visibleTab, name: 'bench-metrics'});
  on('world', () => { if (visibleTab) update(); });
  return {el, show() { visibleTab = true; update(); loadQuick(); wp.start(); mp.start(); call('bench.status').then(s => { opened = s.open; watching = s.watching; lastRect = ''; sync(); update(); }).catch(() => {}); }, hide() { visibleTab = false; wp.stop(); mp.stop(); lastRect = ''; if (opened) call('bench.bounds', {x: 0, y: 0, width: 0, height: 0, visible: false}).catch(() => {}); }};
}
