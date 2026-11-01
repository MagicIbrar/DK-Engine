// Play & Connect: sign in and open the game (all four existing targets), join / saved / public servers,
// host friends (invite or open, rates, relay, public listing with consent, LAN, invitations, phone QR, setup kits),
// and the Test Bench (embedded client).
import {h, icon, replace, clear, id} from '../core/dom.js';
import {call} from '../core/api.js';
import {poller} from '../core/poll.js';
import {state, on} from '../core/state.js';
import * as f from '../core/format.js';
import {button, card, pill, notice, textField, selectField, switchRow, seg, tabs, collapsible, table, dialog, confirm, toast, jobView, setError, copyText, empty, kv, round, guard} from '../ui/components.js';
import {startWorld} from './world-actions.js';
import {createBench} from './bench.js';

const TARGETS = [{value: 'native', label: 'DX11 Client'}, {value: 'native-fullscreen', label: 'DX11 Fullscreen'}, {value: 'desktop', label: 'Desktop App'}, {value: 'browser', label: 'Web Browser'}];
export function create({navigate}) {
  const panels = {play: h('div', {class: 'tab-panel', id: 'panel-play', role: 'tabpanel', 'aria-labelledby': 'tab-play'}), join: h('div', {class: 'tab-panel', id: 'panel-join', role: 'tabpanel', 'aria-labelledby': 'tab-join', hidden: true}), host: h('div', {class: 'tab-panel', id: 'panel-host', role: 'tabpanel', 'aria-labelledby': 'tab-host', hidden: true}), bench: h('div', {class: 'tab-panel', id: 'panel-bench', role: 'tabpanel', 'aria-labelledby': 'tab-bench', hidden: true})};
  let active = 'play';
  const bar = tabs([{id: 'play', label: 'Play', ico: 'play'}, {id: 'join', label: 'Join', ico: 'globe'}, {id: 'host', label: 'Host', ico: 'users'}, {id: 'bench', label: 'Test Bench', ico: 'bolt'}], {current: 'play', label: 'Play & Connect sections', onSelect: t => select(t)});
  const el = h('div', {class: 'stack loose'}, bar, ...Object.values(panels));
  const built = {};
  function select(t) { active = t; for (const [k, p] of Object.entries(panels)) p.hidden = k !== t; if (!built[t]) { built[t] = ({play: buildPlay, join: buildJoin, host: buildHost, bench: buildBench})[t](); } built[t].show?.(); for (const [k, b] of Object.entries(built)) if (k !== t) b.hide?.(); history.replaceState(null, '', `#/play/${t}`); }

  // ---------------- Play
  let chosenServer = 'local';
  function buildPlay() {
    const p = panels.play;
    let target = state.settings?.defaultTarget || 'native', mode = 'signin', meta = null;
    const serverSel = h('select', {class: 'input', id: 'play-server', 'aria-label': 'Server'});
    const targetSeg = h('div');
    const modeSeg = seg([{value: 'signin', label: 'Sign in'}, {value: 'signup', label: 'Create account'}], 'signin', v => { mode = v; renderForm(); }, {label: 'Sign in or create account'});
    const invite = textField({label: 'Invite password', type: 'password', maxLength: 128, help: 'Required by invite-only servers. Sent only in the request body, never in a URL.', fieldId: 'play-invite'});
    const acct = textField({label: 'Account ID', maxLength: 32, help: '3-32 letters, numbers, _ or -. Accounts belong to this server only.', fieldId: 'play-id', attrs: {list: 'saved-ids'}});
    const pass = textField({label: 'Password', type: 'password', maxLength: 128, help: '6-128 characters. Leave empty to use a saved login.', fieldId: 'play-pass', autocomplete: 'current-password'});
    const confirm2 = textField({label: 'Repeat password', type: 'password', maxLength: 128, fieldId: 'play-confirm'});
    const remember = switchRow({title: 'Save account on this server', desc: 'Stores a server-issued token with Windows DPAPI for your user. No password is stored.', checked: false, fieldId: 'play-remember'});
    const owner = switchRow({title: 'Auto-sign in as local admin', desc: 'Installation owner of this local world: owner characters and guild are prepared before the game opens.', checked: false, fieldId: 'owner'});
    owner.input.addEventListener('change', () => { acct.input.disabled = pass.input.disabled = owner.input.checked; });
    const savedList = h('datalist', {id: 'saved-ids'});
    const savedBox = h('div', {class: 'rows', id: 'saved'});
    const result = h('div', {class: 'stack tight', 'aria-live': 'polite'});
    const submit = button('Open DX11 Client', {kind: 'primary', size: 'large', ico: 'play', attrs: {id: 'signin'}, onClick: () => go()});
    const serverInfo = h('div', {class: 'stack tight'});
    const form = h('div', {class: 'stack'}, h('div', {class: 'form-grid'}, h('div', {class: 'field'}, h('label', {for: 'play-server', text: 'Server'}), serverSel, h('div', {class: 'help', text: 'Your world, or a server you joined. Accounts belong to one server.'})), h('div', {class: 'field'}, h('span', {class: 'label', text: 'Mode'}), modeSeg)), serverInfo,
      h('div', {class: 'field'}, h('span', {class: 'label', text: 'Open the game in'}), targetSeg), owner, invite, h('div', {class: 'form-grid'}, acct, pass, confirm2), savedList, remember, h('div', {class: 'row wrap'}, submit, button('Create account', {kind: 'ghost', attrs: {id: 'signup'}, onClick: () => { modeSeg.querySelectorAll('button')[1].click(); }})), result);
    const signCard = card({title: 'Sign in and play', desc: 'Every target signs in first and opens the game already signed in with a one-use ticket.', children: [form]});
    const savedCard = card({title: 'Saved accounts on this server', children: [savedBox]});
    const gamesBox = h('div', {class: 'rows'});
    const gamesCard = card({title: 'Game windows opened from here', desc: 'Closing a game window never stops the world.', children: [gamesBox]});
    p.append(h('div', {class: 'split'}, signCard, h('div', {class: 'stack'}, savedCard, gamesCard)));
    window.addEventListener('dk-target', e => { target = e.detail; renderTargets(); select('play'); bar.select('play'); setTimeout(() => acct.input.focus(), 50); });
    window.addEventListener('dk-server', e => { chosenServer = e.detail; loadServers(); });
    let seenStatus = null; on('world', w => { if (w.status !== seenStatus) { const was = seenStatus; seenStatus = w.status; if (was !== null && chosenServer === 'local') loadServers(); } });
    function renderTargets() { replace(targetSeg, seg(TARGETS, target, v => { target = v; renderForm(); }, {label: 'Game window'})); renderForm(); }
    function renderForm() {
      const signup = mode === 'signup', local = chosenServer === 'local';
      confirm2.hidden = !signup; remember.hidden = signup; owner.hidden = signup || !local || !(state.world?.ownerAvailable && state.world?.mode !== 'hosted');
      invite.hidden = !(meta?.requiresInvite || (local && state.world?.hostMode === 'friends'));
      targetSeg.parentElement.hidden = signup;
      submit.querySelector('span').textContent = signup ? 'Create account' : 'Open ' + TARGETS.find(t => t.value === target).label;
      // Signing in or creating an account needs a running world; say so on the button instead of failing after a click.
      const stoppedLocal = local && state.world?.status !== 'running';
      submit.disabled = stoppedLocal; submit.dataset.tip = stoppedLocal ? 'Start the local world first (button above or Home › Start world).' : '';
      pass.querySelector('.help').textContent = signup ? '6-128 characters.' : '6-128 characters. Leave empty to use a saved login.';
    }
    async function loadServers() {
      const servers = await call('play.servers').catch(() => ({saved: []}));
      clear(serverSel).append(h('option', {value: 'local', text: state.world?.status === 'running' ? `This PC – local world (${state.world.url})` : 'This PC – local world (stopped)'}), ...servers.saved.map(s => h('option', {value: s.url, text: `${s.name} – ${s.url}`})));
      serverSel.value = [...serverSel.options].some(o => o.value === chosenServer) ? chosenServer : 'local'; chosenServer = serverSel.value; await serverChanged();
    }
    serverSel.addEventListener('change', () => { chosenServer = serverSel.value; serverChanged(); });
    async function serverChanged() {
      meta = null; clear(serverInfo);
      if (chosenServer === 'local') { if (state.world?.status !== 'running') serverInfo.append(notice('info', 'The local world is stopped. Signing in starts nothing; start the world first.', {action: button('Start world', {size: 'small', onClick: () => startWorld()})})); }
      else { serverInfo.append(h('div', {class: 'row faint'}, h('span', {class: 'spinner'}), 'Checking server…')); try { const r = await call('play.probe', {urls: [chosenServer]}); meta = r.results[0]; replace(serverInfo, meta.online ? h('div', {class: 'row wrap'}, pill('Online', 'ok'), pill(meta.requiresInvite ? 'Invite password required' : 'Open', 'info'), meta.known ? pill(`${meta.humans} players · ${meta.bots} bots`, '') : pill(meta.total === null ? 'Population unavailable' : `${meta.total} online`, ''), meta.rates ? h('span', {class: 'faint', text: `EXP ${meta.rates.exp}x · DIL ${meta.rates.dil}x · Drop ${meta.rates.drop}x`}) : null) : notice('warn', `This server did not answer (${meta.error}).`)); } catch (e) { replace(serverInfo, notice('err', e.message)); } }
      renderForm(); loadSaved();
    }
    async function loadSaved() {
      try {
        const {accounts} = await call('play.saved', {server: chosenServer});
        clear(savedList).append(...accounts.map(a => h('option', {value: a.id})));
        replace(savedBox, accounts.length ? accounts.map(a => h('div', {class: 'r'}, icon('user', 18), h('div', {class: 'grow stack tight'}, h('strong', {text: a.id}), h('span', {class: 'faint', text: a.hasToken ? 'Saved login (no password stored)' : 'ID only'})), button('Use', {size: 'small', onClick: () => { acct.input.value = a.id; pass.input.value = ''; pass.input.focus(); }}), button('Forget', {size: 'small', kind: 'ghost', onClick: async () => { if (await confirm({title: `Forget ${a.id}?`, message: 'The saved login is revoked on the server and removed from this PC.', confirmLabel: 'Forget'})) { await call('play.saved.forget', {server: chosenServer, id: a.id}); toast('Saved login forgotten.', 'ok'); loadSaved(); } }}))) : [empty('No saved accounts for this server yet.')]);
      } catch (e) { replace(savedBox, notice('warn', e.message)); }
    }
    async function go() {
      for (const w of [acct, pass, confirm2, invite]) setError(w, null);
      const signup = mode === 'signup', params = {server: chosenServer, target, id: acct.input.value.trim().toLowerCase() || undefined, password: pass.input.value || undefined, invitePassword: invite.hidden ? undefined : (invite.input.value || undefined), remember: remember.input.checked, owner: !owner.hidden && owner.input.checked};
      if (signup) { params.confirm = confirm2.input.value; }
      let job; try { job = await call(signup ? 'play.signup' : 'play.signin', signup ? {server: chosenServer, id: params.id || '', password: params.password || '', confirm: params.confirm || '', invitePassword: params.invitePassword} : params); } catch (e) { fieldError(e); return; }
      const view = jobView(job, {compact: true}); replace(result, view);
      const final = await view.done; for (const w of [pass, confirm2, invite]) w.input.value = '';
      if (final?.state === 'succeeded') { toast(signup ? `Account ${final.result.created} created. Sign in with it now.` : `Game opened for ${final.result.account === 'admin' ? 'the local admin' : final.result.account}.`, 'ok'); if (signup) modeSeg.querySelector('button').click(); loadSaved(); loadGames(); }
      else if (final?.state === 'failed') { replace(result, notice('err', final.error)); }
    }
    function fieldError(e) { const map = {id: acct, password: pass, confirm: confirm2, invitePassword: invite}; const w = map[e.field?.replace(/^params\./, '')]; if (w) { setError(w, e.message.replace(/^params\.\w+: /, '')); w.input.focus(); } else replace(result, notice('err', e.message)); }
    async function loadGames() { try { const {games} = await call('play.games'); replace(gamesBox, games.length ? games.map(g => h('div', {class: 'r'}, icon(g.target.startsWith('native') ? 'play' : 'globe', 18), h('div', {class: 'grow stack tight'}, h('strong', {text: `${g.account || 'player'} · ${TARGETS.find(t => t.value === g.target)?.label}`}), h('span', {class: 'faint', text: `pid ${g.pid} · ${g.server} · ${f.ago(g.startedAt)}`})))) : [empty('No game windows open from this launcher.')]); } catch {} }
    renderTargets();
    const gp = poller(async () => loadGames(), {interval: 4000, active: () => active === 'play', name: 'play-games'});
    return {show() { loadServers(); gp.start(); }, hide() { gp.stop(); }};
  }

  // ---------------- Join
  function buildJoin() {
    const p = panels.join;
    const addr = textField({label: 'Server address', placeholder: '192.0.2.20:7778 or https://world.example.com', help: 'A bare LAN IP uses port 7778. Internet servers need HTTPS.', fieldId: 'join-address', maxLength: 300});
    const save = switchRow({title: 'Save server for next launch', checked: true, fieldId: 'join-save'});
    const out = h('div', {class: 'stack tight', 'aria-live': 'polite'});
    const joinCard = card({title: 'Connect to a world', desc: 'Checks the address directly (no redirects) before anything else.', children: [addr, save, h('div', {class: 'row wrap'}, button('Test address & connect', {kind: 'primary', ico: 'link', onClick: async () => { setError(addr, null); try { const r = await call('play.connect', {address: addr.input.value, save: save.input.checked}); replace(out, notice('ok', `${r.metadata.name || r.url}: ${r.metadata.hostMode === 'open' ? 'open server' : 'invite only'}, answered in ${f.ms(r.ms)}.`, {action: button('Sign in here', {size: 'small', onClick: () => useServer(r.url)})})); loadSaved(); } catch (e) { setError(addr, e.message); } }}), button('Use my local world', {kind: 'ghost', onClick: async () => { await call('play.local'); useServer('local'); }})), out]});
    const savedSearch = h('input', {class: 'input', type: 'search', id: 'saved-search', placeholder: 'Search saved name or address', 'aria-label': 'Search saved servers'});
    const savedBox = h('div', {class: 'rows'});
    const savedCard = card({title: 'Saved servers', id: 'saved-servers', desc: 'Live status refreshes every 10 s while this tab is open.', children: [savedSearch, savedBox]});
    const dirInput = textField({label: 'Directory address (HTTPS)', placeholder: 'https://directory.example.com/', fieldId: 'dir-address', maxLength: 300});
    const dirSearch = h('input', {class: 'input', type: 'search', placeholder: 'Search name or address', 'aria-label': 'Search public servers'});
    const dirOut = h('div', {class: 'stack tight'});
    const dirCard = card({title: 'Public server list', id: 'directory', desc: 'Pulled from the directory you choose; at most one automatic request a minute.', children: [h('div', {class: 'input-row'}, dirInput.input, button('Refresh', {ico: 'refresh', onClick: () => loadDir(true)}), button('Save', {kind: 'ghost', onClick: async () => { try { await call('play.directory.save', {address: dirInput.input.value}); toast('Directory saved.', 'ok'); } catch (e) { setError(dirInput, e.message); } }})), dirInput.querySelector('.error'), dirSearch, dirOut]});
    const extraCard = card({title: 'Open another client', id: 'extra', desc: 'Pick any server, then sign in with a different account per window (an account can be signed in once).', children: [button('Choose server and sign in', {kind: 'ghost', ico: 'plus', onClick: () => { select('play'); bar.select('play'); }})]});
    p.append(h('div', {class: 'split'}, h('div', {class: 'stack'}, joinCard, dirCard), h('div', {class: 'stack'}, savedCard, extraCard)));
    let saved = [], live = {}, dirRows = [];
    function useServer(url) { chosenServer = url; window.dispatchEvent(new CustomEvent('dk-server', {detail: url})); select('play'); bar.select('play'); }
    async function loadSaved() { const r = await call('play.servers'); saved = r.saved; if (r.directory && !dirInput.input.value) dirInput.input.value = r.directory; renderSaved(); }
    function renderSaved() {
      const q = savedSearch.value.trim().toLowerCase();
      const rows = saved.filter(s => !q || (s.name + s.url).toLowerCase().includes(q));
      replace(savedBox, rows.length ? rows.map(s => { const st = live[s.url]; return h('div', {class: 'r'}, h('span', {class: ['event-dot', st ? (st.online ? 'ok' : 'error') : '']}), h('div', {class: 'grow stack tight'}, h('strong', {class: 'wrap-any', text: s.name}), h('span', {class: 'faint wrap-any', text: s.url + (st ? (st.online ? ` · ${st.known ? `${st.humans} players · ${st.bots} bots` : st.total !== null ? st.total + ' online' : 'online'} · ${f.ms(st.ms)}` : ' · offline') : '')})), button('Sign in', {size: 'small', onClick: () => useServer(s.url)}), button('Remove', {size: 'small', kind: 'ghost', onClick: async () => { await call('play.server.remove', {url: s.url}); loadSaved(); }})); }) : [empty(saved.length ? 'No saved server matches.' : 'No saved servers yet. Connect to one above.')]);
    }
    savedSearch.addEventListener('input', renderSaved);
    const probe = poller(async signal => { const urls = [...saved.map(s => s.url), ...dirRows.slice(0, 12).map(s => s.url)].slice(0, 24); if (!urls.length) return; const r = await call('play.probe', {urls}, {signal}); for (const x of r.results) live[x.url] = x; renderSaved(); renderDir(); }, {interval: 10000, active: () => active === 'join', name: 'join-probe'});
    async function loadDir(force) { if (!dirInput.input.value.trim()) { replace(dirOut, empty('No directory set. Enter one to see public worlds.')); return; } replace(dirOut, h('div', {class: 'row faint'}, h('span', {class: 'spinner'}), 'Loading the public list…')); try { const r = await call('play.directory', {address: dirInput.input.value, force: !!force}); dirRows = r.servers; renderDir(); probe.now(); } catch (e) { replace(dirOut, notice('warn', e.message)); } }
    function renderDir() { if (!dirRows.length && !dirOut.querySelector('table')) return; const q = dirSearch.value.trim().toLowerCase(); replace(dirOut, table({caption: 'Public servers', columns: [{key: 'name', label: 'Server', wrap: true}, {key: 'access', label: 'Access', render: r => r.requiresInvite ? 'Password required' : 'Open'}, {key: 'pop', label: 'Online', render: r => { const st = live[r.url]; return st ? (st.online ? (st.known ? `${st.humans} / ${st.bots} bots` : String(st.total ?? '—')) : 'offline') : (r.players ?? '—'); }}, {key: 'rates', label: 'Rates', render: r => r.rates ? `${r.rates.exp}/${r.rates.dil}/${r.rates.drop}` : '—'}, {key: 'x', label: '', sortable: false, render: r => button('Select', {size: 'small', onClick: async () => { try { const j = await call('play.connect', {address: r.url, save: true}); useServer(j.url); } catch (e) { toast(e.message, 'err'); } }})}], rows: dirRows.filter(r => !q || (r.name + r.url).toLowerCase().includes(q)), empty: 'The directory lists no servers.'})); }
    dirSearch.addEventListener('input', renderDir);
    return {show() { loadSaved().then(() => { loadDir(false); probe.start(); }); }, hide() { probe.stop(); }};
  }

  // ---------------- Host
  function buildHost() {
    const p = panels.host;
    const statusBox = h('div', {class: 'stack tight'});
    const statusCard = card({title: 'Your hosted world', id: 'host-setup', children: [statusBox]});
    const name = textField({label: 'Server name', value: 'Dekaron Online', maxLength: 64, fieldId: 'host-name'});
    const access = selectField({label: 'Access', options: [{value: 'invite', label: 'Invite only (server password)'}, {value: 'open', label: 'Open (accounts required)'}], value: 'invite', fieldId: 'host-access'});
    const gm = textField({label: 'New GM account ID', maxLength: 32, fieldId: 'host-gm'}), gmPass = textField({label: 'GM password (12+ characters)', type: 'password', maxLength: 128, fieldId: 'host-gm-pass'}), gmPass2 = textField({label: 'Repeat GM password', type: 'password', maxLength: 128, fieldId: 'host-gm-pass2'});
    const invitePass = textField({label: 'Invite password (different, 12+)', type: 'password', maxLength: 128, help: 'Players enter it once per session. It is never listed publicly.', fieldId: 'host-invite'});
    const rates = ['exp', 'dil', 'drop'].map(k => textField({label: {exp: 'EXP multiplier', dil: 'DIL multiplier', drop: 'Drop multiplier'}[k], value: '1', type: 'number', attrs: {min: '0.1', max: '100', step: '0.1'}, fieldId: 'rate-' + k}));
    access.input.addEventListener('change', () => { invitePass.hidden = access.input.value === 'open'; });
    const formOut = h('div');
    const setupForm = h('div', {class: 'stack'}, h('div', {class: 'form-grid'}, name, access), h('div', {class: 'form-grid'}, gm, gmPass, gmPass2), invitePass, collapsible('Rates (EXP / DIL / Drop)', h('div', {class: 'form-grid'}, rates)), h('div', {class: 'row'}, button('Create host', {kind: 'primary', onClick: async () => {
      for (const w of [name, gm, gmPass, gmPass2, invitePass]) setError(w, null);
      if (gmPass.input.value !== gmPass2.input.value) { setError(gmPass2, 'Passwords do not match.'); return; }
      try { await call('host.configure', {id: gm.input.value.trim().toLowerCase(), password: gmPass.input.value, confirmPassword: gmPass2.input.value, ...(access.input.value === 'invite' ? {serverPassword: invitePass.input.value} : {}), name: name.input.value, mode: access.input.value, rates: Object.fromEntries(rates.map((r, i) => [['exp', 'dil', 'drop'][i], Number(r.input.value)]))}); for (const w of [gmPass, gmPass2, invitePass]) w.input.value = ''; toast('Host configured. Start hosting when ready.', 'ok'); load(); }
      catch (e) { const map = {id: gm, password: gmPass, confirmPassword: gmPass2, serverPassword: invitePass, name}; const w = map[e.field?.replace(/^params\./, '')]; if (w) setError(w, e.message.replace(/^params\.\w+: /, '')); else replace(formOut, notice('err', e.message)); }
    }})), formOut);
    const setupCard = card({title: 'Host setup', desc: 'A separate private world: accounts here are separate from local play. Hosted worlds use the engine\'s fixed port 7778.', children: [setupForm]});
    const inviteBox = h('div', {class: 'stack tight'}); const inviteCard = card({title: 'Invite your party', id: 'invite', children: [inviteBox]});
    const qrBox = h('div', {class: 'stack tight'}); const qrCard = card({title: 'Phone / tablet QR', id: 'qr', desc: 'Address only. Install the Android app, tap Scan server QR, then Join after the server check. Passwords stay separate.', children: [qrBox]});
    const relayOn = switchRow({title: 'Online relay (managed HTTPS)', desc: 'Outbound Cloudflare named tunnel: your home IP is never published. Needs your own tunnel token file.', fieldId: 'relay-on'});
    const relayHost = textField({label: 'Your HTTPS relay hostname', placeholder: 'https://world.example.com', fieldId: 'relay-host'});
    const relayToken = textField({label: 'Token file (ingress port 7840)', placeholder: 'C:\\…\\tunnel-token.txt', fieldId: 'relay-token'});
    const relayCard = card({title: 'Internet access', id: 'relay', children: [relayOn, relayHost, h('div', {class: 'input-row'}, relayToken.input, button('Browse…', {onClick: async () => { const r = await call('shell.pick', {kind: 'file', title: 'Choose your private cloudflared token file'}).catch(e => { toast(e.message, 'err'); return {}; }); if (r.path) relayToken.input.value = r.path; }})), relayToken.querySelector('.error'), h('div', {class: 'row wrap'}, button('Save relay settings', {onClick: () => saveRelay()}), button('Cloudflare tunnel guide', {kind: 'ghost', ico: 'external', onClick: () => call('shell.openExternal', {url: 'https://developers.cloudflare.com/cloudflare-one/connections/connect-networks/'}).catch(e => toast(e.message, 'warn'))}))]});
    const lan = switchRow({title: 'Allow direct LAN connections the next time I host', desc: 'Binds to your network (0.0.0.0) and shows your LAN address to friends. Relay-only is the default.', applies: 'next-start', fieldId: 'lan', onChange: v => call('host.prefs.set', {allowLan: v}).then(() => toast(v ? 'LAN connections allowed for the next host start.' : 'Relay-only for the next host start.', 'ok'))});
    const listDir = textField({label: 'Directory (HTTPS root)', placeholder: 'https://directory.example.com/', fieldId: 'list-dir'});
    const listState = h('div');
    const listingCard = card({title: 'Public listing', id: 'listing', desc: 'Optional. Lists your server name, relay address, player count, rates and whether a password is needed.', children: [lan, listDir, h('div', {class: 'row wrap'}, button('Review warning and list…', {onClick: () => listingConsent()}), button('Withdraw listing', {kind: 'ghost', onClick: async () => { try { await call('host.listing.set', {enabled: false}); toast('Listing withdrawn. Your relay keeps running.', 'ok'); } catch (e) { toast(e.message, 'warn'); } }})), listState]});
    const kitsCard = card({title: 'Hosting setup kits', id: 'kits', desc: 'Writes a guide plus ready-to-edit files into the installation and opens the folder. Nothing is deployed or contacted.', children: [h('div', {class: 'row wrap'}, ...[['local', 'On this PC'], ['vps', 'My own VPS'], ['vercel', 'Vercel'], ['cloudflare', 'Cloudflare']].map(([route, label]) => button(label, {onClick: async () => { try { const r = await call('host.kit', {route, relay: relayHost.input.value || undefined, directory: listDir.input.value || undefined}); toast(`Guide written: ${r.files.join(', ')}${r.placeholders.length ? ' (uses example values for ' + r.placeholders.join(' and ') + ')' : ''}.`, 'ok'); } catch (e) { toast(e.message, 'err'); } }})))]});
    p.append(h('div', {class: 'split'}, h('div', {class: 'stack'}, statusCard, setupCard, relayCard, listingCard), h('div', {class: 'stack'}, inviteCard, qrCard, kitsCard)));
    async function saveRelay() { try { await call('host.prefs.set', {relay: relayOn.input.checked ? {enabled: true, publicOrigin: relayHost.input.value, tokenFile: relayToken.input.value} : {enabled: false}}); toast('Relay settings saved for the next host start.', 'ok'); } catch (e) { toast(e.message, 'err'); } }
    async function listingConsent() {
      try { const w = await call('host.listing.warning', {directory: listDir.input.value}); if (!await confirm({title: 'List your server publicly?', message: h('pre', {class: 'block', text: w.text}), confirmLabel: 'List my server'})) { toast('Not listed. You did not confirm the warning.', 'info'); return; }
        await call('host.listing.consent', {directory: w.directory, accepted: true});
        if (relayOn.input.checked) await call('host.prefs.set', {relay: {enabled: true, publicOrigin: relayHost.input.value, tokenFile: relayToken.input.value, publish: true, directory: w.directory}});
        if (state.world?.status === 'running' && state.world.mode === 'hosted') { await call('host.listing.set', {enabled: true}); toast('Listed. Switch it off here any time.', 'ok'); } else toast('Consent saved. The server lists itself when you host with the relay.', 'ok');
      } catch (e) { toast(e.message, 'err'); }
    }
    async function load() {
      let s; try { s = await call('host.status'); } catch (e) { replace(statusBox, notice('err', e.message)); return; }
      const cfg = s.config, w = state.world, hosting = w?.status === 'running' && w.mode === 'hosted';
      replace(statusBox, cfg.configured ? kv([['Status', hosting ? pill('Hosting now', 'ok', {live: true}) : pill('Configured', 'info')], ['Name', cfg.name], ['Access', cfg.mode === 'open' ? 'Open (accounts required)' : 'Invite only'], ['Rates', cfg.rates ? `EXP ${cfg.rates.exp}x · DIL ${cfg.rates.dil}x · Drop ${cfg.rates.drop}x` : '—'], ['Port 7778', s.hostedPortFree ? 'free' : hosting ? 'used by this hosted world' : 'in use by another program (the installed game may be hosting)']]) : notice('info', cfg.error || 'No host is configured yet. Create one below.'),
        h('div', {class: 'row wrap'}, cfg.configured && !hosting ? button(w?.status === 'running' ? 'Stop the local world first' : 'Start hosting', {kind: 'primary', ico: 'power', disabled: w?.status === 'running' || !s.hostedPortFree, onClick: () => startWorld({mode: 'hosted'})}) : null, hosting ? button('Open Server', {kind: 'ghost', onClick: () => navigate('server/overview')}) : null), s.note ? h('p', {class: 'faint', text: s.note}) : null);
      setupCard.hidden = false;
      const h2 = s.prefs?.hosting; lan.input.checked = !!h2?.allowLan; if (h2?.relay) { relayOn.input.checked = true; relayHost.input.value = h2.relay.publicOrigin; relayToken.input.value = h2.relay.tokenFile; } if (h2?.listDirectory) listDir.input.value = h2.listDirectory;
      replace(listState, s.relay.listed ? notice('ok', 'Listed now.') : h2?.listingConsent ? notice('info', `Warning accepted for ${h2.listingConsent.directory} on ${f.dateTime(h2.listingConsent.acceptedAt)}.`) : null);
      if (hosting) { try { const inv = await call('host.invite'); replace(inviteBox, inv.address ? h('div', {class: 'input-row'}, h('input', {class: 'input mono', readOnly: true, value: inv.address, 'aria-label': 'Invite address'}), button('Copy', {ico: 'copy', onClick: () => copyText(inv.address, 'Address copied. Send the invite password separately.')})) : null, h('p', {class: 'muted', text: inv.note})); } catch (e) { replace(inviteBox, notice('warn', e.message)); } loadQr(); }
      else { replace(inviteBox, empty('Start hosting to get an address to share.')); replace(qrBox, empty('The QR appears while your hosted world is running with LAN access or the relay.')); }
    }
    async function loadQr() {
      try { const r = await call('host.qr'); const a = r.addresses.find(x => !x.error); if (!a) { replace(qrBox, notice('warn', r.addresses[0]?.error || 'No shareable address.')); return; }
        replace(qrBox, qrSvg(a), h('div', {class: 'mono wrap-any', text: a.address}), h('div', {class: 'row wrap'}, button('Copy app link', {ico: 'copy', onClick: () => copyText(a.payload, 'App link copied. No password is included.')}), button('Save QR image…', {kind: 'ghost', ico: 'download', onClick: async () => { const s2 = await call('host.qr.save', {address: a.address}).catch(e => toast(e.message, 'err')); if (s2?.saved) toast('QR saved. Share passwords separately.', 'ok'); }})));
      } catch (e) { replace(qrBox, notice('warn', e.message)); }
    }
    on('world', () => { if (active === 'host') load(); });
    return {show() { load(); }};
  }
  function buildBench() { const b = createBench({navigate}); panels.bench.append(b.el); return b; }
  function qrSvg(q) { const n = q.size, z = q.quietZone, s = h('svg', {svg: true, viewBox: `0 0 ${n + 2 * z} ${n + 2 * z}`, width: 220, height: 220, role: 'img', 'aria-label': 'Server QR code', 'shape-rendering': 'crispEdges'}); s.append(h('rect', {svg: true, width: n + 2 * z, height: n + 2 * z, fill: '#ffffff'})); let d = ''; q.matrix.forEach((row, y) => { for (let x = 0; x < n; x++) if (row[x] === '1') d += `M${x + z},${y + z}h1v1h-1z`; }); s.append(h('path', {svg: true, d, fill: '#000000'})); return h('div', {class: 'row'}, s); }
  return {el, show(tab) { const t = ['play', 'join', 'host', 'bench'].includes(tab) ? tab : active; bar.select(t); }, hide() { for (const b of Object.values(built)) b.hide?.(); }};
}
