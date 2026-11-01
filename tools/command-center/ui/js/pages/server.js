// Server: lifecycle and readiness, separate status per real service, live metrics (measured only), players and
// accounts, world settings, capacity, hosting summary.
import {h, icon, replace, clear} from '../core/dom.js';
import {call} from '../core/api.js';
import {poller} from '../core/poll.js';
import {state, on} from '../core/state.js';
import * as f from '../core/format.js';
import {button, card, stat, pill, notice, textField, selectField, switchRow, tabs, table, confirm, toast, kv, empty, sparkline, setError, applies} from '../ui/components.js';
import {startWorld, stopWorld, restartWorld, storageSwitch} from './world-actions.js';

export function create({navigate}) {
  const ids = ['overview', 'players', 'world', 'capacity'];
  const panels = Object.fromEntries(ids.map(i => [i, h('div', {class: 'tab-panel', id: 'panel-' + i, role: 'tabpanel', 'aria-labelledby': 'tab-' + i, hidden: i !== 'overview'})]));
  let active = 'overview'; const built = {};
  const bar = tabs([{id: 'overview', label: 'Overview', ico: 'server'}, {id: 'players', label: 'Players & accounts', ico: 'users'}, {id: 'world', label: 'World settings', ico: 'gear'}, {id: 'capacity', label: 'Capacity', ico: 'cpu'}], {current: 'overview', label: 'Server sections', onSelect: t => select(t)});
  function select(t) { active = t; for (const [k, p] of Object.entries(panels)) p.hidden = k !== t; if (!built[t]) built[t] = ({overview, players, world: worldSettings, capacity})[t](); built[t].show?.(); for (const [k, b] of Object.entries(built)) if (k !== t) b.hide?.(); history.replaceState(null, '', `#/server/${t}`); }
  const el = h('div', {class: 'stack loose'}, bar, ...Object.values(panels));

  function overview() {
    const p = panels.overview, prog = h('div', {class: 'stack tight', hidden: true});
    const lifeBody = h('div', {class: 'stack'}), services = h('div', {class: 'rows'}), metricsBox = h('div', {class: 'grid four stretch'}), metricsNote = h('p', {class: 'faint'}), hostingBox = h('div', {class: 'stack tight'});
    p.append(card({title: 'World lifecycle', id: 'lifecycle', children: [lifeBody, prog, h('div', {class: 'hero-foot'}, storageSwitch())]}),
      h('div', {class: 'section-title'}, h('h2', {text: 'Live measurements'}), h('span', {class: 'count', id: 'metrics-at'})), h('div', {id: 'metrics', class: 'stack'}, metricsBox, metricsNote),
      h('div', {class: 'split'}, card({title: 'Services', desc: 'Only services this engine actually runs are listed.', children: [services]}), card({title: 'Hosting', id: 'hosting-summary', children: [hostingBox]})));
    const hist = {cpu: [], mem: [], lat: [], sent: []};
    function life(w) {
      const running = w.status === 'running';
      replace(lifeBody, h('div', {class: 'row between wrap'}, h('div', {class: 'stack tight'}, h('div', {class: 'row wrap'}, pill(w.status, running ? 'ok' : w.status === 'stopped' ? '' : 'warn', {live: running}), w.adopted ? pill('Attached, not owned', 'info', {title: 'Started outside this launcher; closing the launcher leaves it running.'}) : null, w.stale ? pill('Status stale', 'warn') : null), h('span', {class: 'muted wrap-any', text: running ? `${w.name || 'World'} · ${w.url} · pid ${w.pid} · up ${f.duration(w.uptimeMs)}` : 'Stopped. Start it here or from Home.'})),
        h('div', {class: 'row wrap'}, running ? [button('Restart', {ico: 'refresh', disabled: !!w.busy || w.adopted, onClick: () => restartWorld({host: prog})}), button('Save and stop', {kind: 'danger', ico: 'stop', disabled: !!w.busy, onClick: () => stopWorld({host: prog})})] : [button('Start local world', {kind: 'primary', ico: 'power', disabled: !!w.busy || w.status !== 'stopped', onClick: () => startWorld({host: prog})}), button('Start hosted world', {disabled: !!w.busy || w.status !== 'stopped', onClick: () => startWorld({mode: 'hosted', host: prog})})])),
        running ? notice('info', 'Stopping waits until every client has disconnected, saves every character, then waits (bounded, never killing) for the process to exit.') : null,
        w.lastError ? notice('warn', w.lastError) : null);
      const svc = [['World server (HTTP + game API)', running ? 'ok' : '', running ? `listening on ${w.listenHost}:${w.port}` : 'stopped'], ['Launcher control channel', running ? 'ok' : '', running ? 'private token verified' : '—'], ['Online relay', w.relayEnabled ? 'ok' : '', w.relayEnabled ? 'enabled for this world' : 'not configured'], ['Storage', '', w.status === 'running' ? 'see SQL & Storage' : 'applies at start']];
      replace(services, ...svc.map(([n, k, d]) => h('div', {class: 'r'}, h('span', {class: ['event-dot', k]}), h('strong', {class: 'grow', text: n}), h('span', {class: 'faint', text: d}))), h('p', {class: 'faint', text: 'The engine runs one process: there is no separate login, zone or database service to start or stop.'}));
      replace(hostingBox, kv([['Mode', running ? (w.mode === 'hosted' ? 'Hosted (friends)' : 'Local') : '—'], ['Access', w.hostMode === 'friends' ? 'Invite only' : w.hostMode === 'open' ? 'Open' : w.hostMode === 'local' ? 'This PC only' : '—'], ['Bind address', w.listenHost || '—'], ['Relay', w.relayEnabled ? 'On' : 'Off']]), button('Hosting options', {kind: 'ghost', onClick: () => navigate('play/host')}));
    }
    const mp = poller(async signal => {
      const m = await call('world.metrics', {}, {signal});
      const c = m.capacity?.live, pr = m.process;
      if (pr?.cpuPercent !== null && pr?.cpuPercent !== undefined) hist.cpu.push(pr.cpuPercent); if (pr) hist.mem.push(pr.workingSetMB); if (m.latency) hist.lat.push(m.latency.p50); if (c?.sentKBps !== undefined) hist.sent.push(c.sentKBps);
      for (const k of Object.keys(hist)) if (hist[k].length > 40) hist[k].shift();
      const tile = (label, value, unit, note, tint, series) => h('section', {class: ['card', 'tint', tint, 'stat']}, h('div', {class: 'stat-label', text: label}), h('div', {class: 'stat-bottom'}, h('div', {class: 'stack tight grow'}, h('div', {class: 'stat-value small'}, value, unit ? h('span', {class: 'stat-unit', text: unit}) : null), h('div', {class: 'stat-note', text: note})), series ? sparkline(series, {width: 96, height: 34}) : null));
      if (m.world.status !== 'running') { replace(metricsBox, tile('CPU', '—', '', 'World stopped', 'mint'), tile('Memory', '—', '', 'World stopped', 'violet'), tile('Status latency', '—', '', 'No samples', 'sky'), tile('Uptime', '—', '', '', 'amber')); metricsNote.textContent = `Launcher backend: ${m.backend.rssMB} MB RSS. Measurements appear while the world runs.`; return m; }
      replace(metricsBox,
        tile('CPU', pr?.cpuPercent ?? '…', pr?.cpuPercent !== null && pr?.cpuPercent !== undefined ? '%' : '', pr ? 'world process, all cores' : (m.processError || 'unavailable'), 'mint', hist.cpu),
        tile('Memory', pr ? f.n(pr.workingSetMB) : '—', 'MB', c?.memory ? `heap ${c.memory.heapUsedMB}/${c.memory.heapLimitMB} MB` : 'working set', 'violet', hist.mem),
        tile('Status latency', m.latency ? f.n(m.latency.p50, 1) : '—', 'ms', m.latency ? `p95 ${f.n(m.latency.p95, 1)} ms · ${m.latency.samples} samples` : 'no samples', 'sky', hist.lat),
        tile('Upload sent', c?.sentKBps !== undefined ? f.n(c.sentKBps) : '—', 'KB/s', c ? `${c.players}/${c.maxPlayers} players · ${c.perPlayerKBps ?? '—'} KB/s each` : 'unavailable', 'amber', hist.sent));
      metricsNote.textContent = `Measured ${f.time(m.at)}. CPU is the share of all logical CPUs since the previous 5 s sample. Latency is the round trip of the launcher's own status request. ${c?.workMs !== undefined ? `World work per tick: ${f.n(c.workMs, 1)} ms. ` : 'Tick duration is not exposed by this engine. '}${c?.botAuto ? `Bots: automatic density ${c.botAuto.percent}% (${c.botAuto.reason}). ` : ''}Uptime ${f.duration(m.world.uptimeMs)}.`;
      document.getElementById('metrics-at').textContent = 'every 5 s';
      return m;
    }, {interval: 5000, active: () => active === 'overview', name: 'server-metrics'});
    const off = on('world', w => { if (active === 'overview') life(w); });
    return {show() { if (state.world) life(state.world); mp.start(); }, hide() { mp.stop(); }};
  }

  function players() {
    const p = panels.players, accBox = h('div', {class: 'stack tight'}), rosterBox = h('div', {class: 'stack tight'}), storageNote = h('p', {class: 'faint', text: 'Start your world to manage its registered accounts.'}), search = h('input', {class: 'input', type: 'search', placeholder: 'Search account or role', 'aria-label': 'Search accounts'});
    p.append(h('div', {class: 'split'}, card({title: 'Player accounts', id: 'accounts', desc: 'Grant or revoke GM on your own world. The player must re-enter their character afterwards.', children: [storageNote, search, accBox]}), card({title: 'Who is online', children: [h('div', {id: 'online-now', class: 'stack tight'})]})), card({title: 'Character roster', id: 'roster', desc: 'Read-only, from the world server (the authoritative record).', children: [rosterBox]}));
    let rows = [];
    async function loadAccounts() {
      try { const result = await call('world.accounts'); rows = result.accounts; storageNote.textContent = result.storageMode === 'sqlserver' ? 'Accounts loaded from this running SQL Server world. GM roles apply to these accounts after they re-enter.' : 'Accounts loaded from this running local-file world. GM roles apply after players re-enter.'; render(); } catch (e) { replace(accBox, notice(e.status === 409 ? 'info' : 'warn', e.message)); }
    }
    function render() {
      const q = search.value.trim().toLowerCase();
      replace(accBox, table({caption: 'Accounts', columns: [
        {key: 'id', label: 'Account'},
        {key: 'role', label: 'Role', render: r => pill(r.role === 'gm' ? 'GM' : 'Player', r.role === 'gm' ? 'gold' : '')},
        {key: 'gm', label: 'GM access', sortable: false, render: r => switchRow({
          title: r.role === 'gm' ? 'On' : 'Off',
          checked: r.role === 'gm',
          fieldId: `gm-${r.id}`,
          onChange: async want => {
            const role = want ? 'gm' : 'player';
            if (!await confirm({title: `${want ? 'Grant GM to' : 'Revoke GM from'} ${r.id}?`, message: 'The player will leave their active character and must re-enter.', confirmLabel: want ? 'Grant GM' : 'Revoke GM'})) return false;
            const res = await call('world.accounts.setRole', {account: r.id, role});
            toast(res.message, 'ok');
            await loadAccounts();
          }
        })}
      ], rows: rows.filter(r => !q || (r.id + r.role).includes(q)), empty: rows.length ? 'No account matches.' : 'No other accounts yet. Players sign up, then appear here.'}));
    }
    search.addEventListener('input', render);
    async function loadRoster() { try { const r = await call('world.characters'); replace(rosterBox, table({caption: 'Characters', tall: true, columns: [{key: 'name', label: 'Character'}, {key: 'account', label: 'Account', render: c => c.account || c.accountId || '—'}, {key: 'className', label: 'Class'}, {key: 'level', label: 'Level', num: true}, {key: 'map', label: 'Map', num: true}], rows: r.characters, empty: 'No characters yet.'}), h('p', {class: 'faint', text: r.note})); } catch (e) { replace(rosterBox, notice(e.status === 409 ? 'info' : 'warn', e.message)); } }
    const off = on('world', w => { const o = document.getElementById('online-now'); if (!o) return; replace(o, w.status === 'running' && w.population?.known ? kv([['People', f.n(w.population.humans)], ['Bots', f.n(w.population.bots)], ['Connected clients', f.n(w.population.connectedClients)], ['Primary GM window', w.primary || 'none yet']]) : notice('info', w.status === 'running' ? 'Population split unavailable.' : 'World stopped.')); });
    return {show() { loadAccounts(); loadRoster(); }};
  }

  function worldSettings() {
    const p = panels.world, body = h('div', {class: 'stack'});
    p.append(card({title: 'World settings', desc: 'One change per save, confirmed by the server. While the world is stopped, changes are saved for its next start.', children: [body]}));
    async function load() {
      clear(body).append(h('div', {class: 'row faint'}, h('span', {class: 'spinner'}), 'Loading…'));
      let s; try { s = await call('world.settings.get', {scope: state.world?.mode === 'hosted' ? 'friends' : 'local'}); } catch (e) { replace(body, notice('warn', e.message)); return; }
      const ap = s.live ? 'now' : 'next-start', set = async change => { const r = await call('world.settings.set', {scope: s.scope, change}); toast(r.message, 'ok'); return r; };
      const name = textField({label: 'Server name', value: s.settings.name, maxLength: 64, help: 'Shown in the client, world list and in-game server display.', applies: ap, fieldId: 'set-name'});
      const saveName = button('Save name', {onClick: async () => { setError(name, null); try { await set({name: name.input.value}); } catch (e) { setError(name, e.message); } }});
      const lang = selectField({label: 'Bot chat language', value: s.settings.npcLanguage || 'en', options: [['en', 'English'], ['es', 'Spanish'], ['pt', 'Portuguese'], ['de', 'German'], ['fr', 'French']].map(([value, label]) => ({value, label})), help: 'Common bot replies and short requests. Native item and skill names stay unchanged.', applies: ap, fieldId: 'set-lang', onChange: v => set({npcLanguage: v}).catch(e => toast(e.message, 'err'))});
      replace(body, h('div', {class: 'row top wrap'}, h('div', {class: 'grow'}, name), h('div', {class: 'row', style: null}, saveName)),
        h('div', {class: 'rows'},
          h('div', {id: 'set-starter'}, switchRow({title: 'New characters get the starter pack', desc: 'Characters that already exist keep what they have.', checked: s.settings.starterPack !== false, applies: ap, onChange: v => set({starterPack: v})})),
          h('div', {id: 'set-pk'}, switchRow({title: 'Allow PK on open maps', desc: 'Hold Ctrl to attack players on open PvP maps. Safe zones, parties and guild mates stay protected.', checked: s.settings.fieldPk !== false, applies: ap, onChange: v => set({fieldPk: v})})),
          h('div', {id: 'set-bots'}, switchRow({title: 'Bots (experimental)', desc: 'Off by default. Optional automated players with automatic population; behaviour and performance are still being improved.', checked: s.settings.npcPlayers === true, applies: ap, onChange: v => set({npcPlayers: v})}))),
        lang, h('p', {class: 'faint', text: `Source: ${s.source}.${s.reviewed === false ? ' This world has not had its first-start review yet; Start asks for it.' : ''}`}));
    }
    on('world', w => { if (active === 'world' && (w.status === 'running' || w.status === 'stopped')) { /* reload only on lifecycle changes */ } });
    let lastStatus = null; on('world', w => { if (lastStatus && lastStatus !== w.status && active === 'world') load(); lastStatus = w.status; });
    return {show() { load(); }};
  }

  function capacity() {
    const p = panels.capacity, body = h('div', {class: 'stack'});
    p.append(card({title: 'Server capacity', id: 'cap', desc: 'Player cap and upload apply at once while running; memory applies at the next start.', children: [body]}));
    async function load() {
      let c; try { c = await call('world.capacity.get'); } catch (e) { replace(body, notice('warn', e.message)); return; }
      const s = c.settings, r = c.memoryRange;
      const maxP = textField({label: 'Maximum human players', type: 'number', value: String(s.maxPlayers), help: '1-500. The owner and GM accounts may always join.', applies: c.live ? 'now' : 'next-start', attrs: {min: '1', max: '500', step: '1'}, fieldId: 'cap-players'});
      const auto = switchRow({title: 'Automatic memory (Node default)', checked: !s.memoryMB, applies: 'next-start'});
      const mem = textField({label: 'Server memory (MB)', type: 'number', value: String(s.memoryMB || r.recommended), help: `${f.n(r.min)}-${f.n(r.max)} MB on this PC (recommended ${f.n(r.recommended)} MB of ${f.n(r.totalMB)} MB).`, applies: 'next-start', attrs: {min: String(r.min), max: String(r.max), step: String(r.step)}, fieldId: 'cap-mem'});
      mem.input.disabled = auto.input.checked; auto.input.addEventListener('change', () => { mem.input.disabled = auto.input.checked; });
      const up = textField({label: 'Your upload speed (Mbps)', type: 'number', value: String(s.uploadMbps), help: '0 means no upload limit. Start can measure it automatically (Settings › Launcher).', applies: c.live ? 'now' : 'next-start', attrs: {min: '0', max: '10000', step: '0.1'}, fieldId: 'cap-up'});
      const share = textField({label: 'Upload share used by the game (%)', type: 'number', value: String(Math.round(s.uploadShare * 100)), help: '10-95%. The rest stays free for the network.', applies: c.live ? 'now' : 'next-start', attrs: {min: '10', max: '95', step: '1'}, fieldId: 'cap-share'});
      const live = c.live ? kv([['Players', `${c.live.players} / ${c.live.maxPlayers}`], ['Sent', `${f.n(c.live.sentKBps)} KB/s`], ['Heap', `${c.live.memory?.heapUsedMB} / ${c.live.memory?.heapLimitMB} MB`], ['Process', `${c.live.memory?.rssMB} MB`], c.live.botAuto ? ['Bots', `automatic density ${c.live.botAuto.percent}% · up to ${c.live.botAuto.presenceTarget} simulated (${c.live.botAuto.reason})`] : null]) : notice('info', 'Saved startup settings. The world is stopped.');
      replace(body, h('div', {class: 'form-grid'}, maxP, up, share), auto, mem, h('div', {class: 'row'}, button('Save capacity', {kind: 'primary', onClick: async () => {
        for (const w of [maxP, mem, up, share]) setError(w, null);
        const input = {maxPlayers: Number(maxP.input.value), memoryMB: auto.input.checked ? 0 : Number(mem.input.value), uploadMbps: Number(up.input.value), uploadShare: Number(share.input.value) / 100};
        try { await call('world.capacity.set', input); toast('Capacity saved. Player cap and upload apply now; memory at the next start.', 'ok'); load(); }
        catch (e) { const map = {maxPlayers: maxP, memoryMB: mem, uploadMbps: up, uploadShare: share}; const w = map[e.field?.replace(/^params\./, '')]; if (w) setError(w, e.message.replace(/^params\.\w+: /, '')); else toast(e.message, 'err'); }
      }}), button('Refresh', {kind: 'ghost', onClick: load})), h('div', {class: 'stack tight'}, h('h3', {text: 'Live'}), live));
    }
    return {show() { load(); }};
  }
  return {el, show(tab) { bar.select(ids.includes(tab) ? tab : active); }, hide() { for (const b of Object.values(built)) b.hide?.(); }};
}
