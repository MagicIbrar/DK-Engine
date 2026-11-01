// Developer dropdown: everything a developer needs one click away.
import {h, icon, clear} from '../core/dom.js';
import {call} from '../core/api.js';
import {activePollers} from '../core/poll.js';
import {menu, dialog, button, toast, table, kv, pill, runJob, copyText} from './components.js';
import * as f from '../core/format.js';

export async function openDevMenu(anchor, {navigate}) {
  let running = 0; try { running = (await call('jobs.list', {running: true})).jobs.length; } catch {}
  menu(anchor, [
    {header: 'Diagnose'},
    {label: 'Live logs', ico: 'list', hint: 'errors in real time', onClick: () => navigate('updates/logs')},
    {label: 'Code & file finder', ico: 'search', hint: 'text + hex', onClick: () => navigate('updates/files')},
    {label: 'Health check', ico: 'shield', onClick: () => navigate('updates/health')},
    {label: 'Event timeline', ico: 'clock', onClick: () => navigate('updates/timeline')},
    {label: 'Test Bench (embedded client)', ico: 'bolt', onClick: () => navigate('play/bench')},
    '-', {header: 'Inspect'},
    {label: `Jobs${running ? ` (${running} running)` : ''}`, ico: 'layers', onClick: () => jobsDialog()},
    {label: 'Processes & resources', ico: 'cpu', onClick: () => devDialog('processes')},
    {label: 'Bridge statistics', ico: 'plug', onClick: () => devDialog('bridge')},
    {label: 'World status (raw JSON)', ico: 'server', onClick: () => devDialog('world')},
    {label: 'Environment summary', ico: 'info', onClick: () => devDialog('env')},
    '-', {header: 'Actions'},
    {label: 'Export support bundle (redacted)', ico: 'download', onClick: () => runJob('diag.export', {toFile: true}, {title: 'Support export', successText: 'Support bundle saved.'}).catch(() => {})},
    {label: 'Verify Main unchanged', ico: 'shield', onClick: () => verifyMain()},
    {label: 'Open logs folder', ico: 'folder', onClick: () => call('diag.openFolder', {which: 'logs'}).catch(e => toast(e.message, 'err'))},
    {label: 'Reload interface', ico: 'refresh', hint: 'keeps the world running', onClick: () => location.reload()},
  ], {minWidth: 300});
}
async function verifyMain() {
  const final = await runJob('diag.mainUnchanged', {}, {title: 'Verify Main unchanged', keepOpen: true}).catch(() => null);
  if (final?.state !== 'succeeded') return;
  const r = final.result;
  dialog({title: r.identical ? 'Main is unchanged' : 'Main changed since the baseline', body: [h('p', {class: 'muted', text: r.identical ? 'File list, sizes, modification times, hashes of mutable state and SQL row counts all match the baseline taken before the preview existed.' : 'Some entries differ. Changes made by someone playing or by another agent also appear here; the preview never writes inside Main.'}), kv([['Changed files', String(r.changed.length)], ['Added files', String(r.added.length)], ['Removed files', String(r.removed.length)], ['Hashed state that differs', r.hashDiff.join(', ') || 'none'], ['SQL row counts', r.sqlSame ? 'same' : 'different']]), r.changed.length || r.added.length ? h('pre', {class: 'block', text: [...r.changed.map(x => 'changed ' + x), ...r.added.map(x => 'added ' + x), ...r.removed.map(x => 'removed ' + x)].slice(0, 80).join('\n')}) : null]});
}
async function jobsDialog() {
  const body = h('div', {class: 'stack'});
  const d = dialog({title: 'Jobs', wide: true, body, actions: [button('Close', {onClick: () => d.close()})]});
  async function load() { const {jobs} = await call('jobs.list', {}); clear(body).append(table({caption: 'Jobs', columns: [{key: 'title', label: 'Operation'}, {key: 'state', label: 'State', render: j => pill(j.state, j.state === 'succeeded' ? 'ok' : j.state === 'failed' ? 'err' : j.state === 'running' ? 'warn' : '')}, {key: 'phase', label: 'Phase'}, {key: 'startedAt', label: 'Started', render: j => f.time(j.startedAt)}, {key: 'dur', label: 'Duration', num: true, render: j => f.duration((j.endedAt || Date.now()) - j.startedAt)}, {key: 'error', label: 'Result', wrap: true, render: j => j.error || j.message || ''}, {key: 'x', label: '', sortable: false, render: j => j.cancellable ? button('Cancel', {size: 'small', kind: 'ghost', onClick: async () => { await call('jobs.cancel', {id: j.id}).catch(e => toast(e.message, 'warn')); load(); }}) : ''}], rows: jobs.reverse(), empty: 'No operations yet.'})); }
  await load();
}
async function devDialog(which) {
  const body = h('div', {class: 'stack'}, h('div', {class: 'row faint'}, h('span', {class: 'spinner'}), 'Loading…'));
  const d = dialog({title: {processes: 'Processes & resources', bridge: 'Bridge statistics', world: 'World status', env: 'Environment'}[which], wide: true, body, actions: [button('Copy JSON', {kind: 'ghost', ico: 'copy', onClick: () => copyText(JSON.stringify(data, null, 2))}), button('Close', {onClick: () => d.close()})]});
  let data;
  try {
    const r = await call('diag.dev'); clear(body);
    if (which === 'processes') { data = {processes: r.processes, backend: r.backend, shell: r.shell, pollers: activePollers()};
      body.append(table({caption: 'Processes', columns: [{key: 'pid', label: 'PID', num: true}, {key: 'role', label: 'Role'}, {key: 'name', label: 'Image'}, {key: 'cpuMs', label: 'CPU time', num: true, render: p => f.ms(p.cpuMs)}, {key: 'workingSet', label: 'Working set', num: true, render: p => f.bytes(p.workingSet)}, {key: 'private', label: 'Private', num: true, render: p => f.bytes(p.private)}, {key: 'threads', label: 'Threads', num: true}, {key: 'handles', label: 'Handles', num: true}], rows: r.processes}),
        kv([['Backend CPU', r.backend.cpuPercent === null ? '—' : r.backend.cpuPercent + ' %'], ['Backend memory', `${r.backend.rssMB} MB RSS · ${r.backend.heapMB} MB heap`], ['Event loop delay', `p50 ${r.backend.loopDelayMs.p50} ms · p99 ${r.backend.loopDelayMs.p99} ms · max ${r.backend.loopDelayMs.max} ms`], ['Window', r.shell ? `${r.shell.width}×${r.shell.height} px at ${r.shell.dpi} dpi · backend ready ${r.shell.backendReadyMs} ms · view ready ${r.shell.webviewReadyMs} ms` : 'headless'], ['Active pollers', activePollers().join(', ') || 'none']])); }
    if (which === 'bridge') { data = r.bridge; const rows = Object.entries(r.bridge?.byMethod || {}).map(([k, m]) => ({method: k, ...m})).sort((a, b) => b.n - a.n);
      body.append(kv([['Requests', f.n(r.bridge.requests)], ['API calls', f.n(r.bridge.apiCalls)], ['Rejected', f.n(r.bridge.rejected)], ['Slowest call', f.ms(r.bridge.slowest)]]), table({caption: 'Operations', tall: true, columns: [{key: 'method', label: 'Operation', mono: true}, {key: 'n', label: 'Calls', num: true}, {key: 'avgMs', label: 'Avg', num: true, render: x => f.ms(x.avgMs)}, {key: 'maxMs', label: 'Max', num: true, render: x => f.ms(x.maxMs)}], rows})); }
    if (which === 'world') { data = r.world; body.append(h('pre', {class: 'block', text: JSON.stringify(r.world, null, 2)})); }
    if (which === 'env') { data = r.env; body.append(kv(Object.entries(r.env).map(([k, v]) => [k, typeof v === 'object' ? h('pre', {class: 'block', text: JSON.stringify(v, null, 2)}) : String(v)]))); }
  } catch (e) { clear(body).append(h('div', {class: 'notice err', text: e.message})); }
}
