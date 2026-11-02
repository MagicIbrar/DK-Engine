// Start / stop / restart with the existing first-start settings review and honest job progress.
import {h, replace} from '../core/dom.js';
import {call} from '../core/api.js';
import {state, on} from '../core/state.js';
import {dialog, button, toast, jobView, textField, switchRow, notice, setError, seg} from '../ui/components.js';
import {worldJobNotice} from './world-presentation.js';

const inlineNotices = new WeakMap();

/** Local files / SQL Server choice for the next world start, shown right beside Start world. */
export function storageSwitch() {
  const el = h('div', {class: 'storage-switch'}); let cfg = null, lastStatus = null;
  const render = () => {
    if (!cfg) return;
    const busy = state.world && state.world.status !== 'stopped';
    replace(el, h('span', {class: 'ss-label eyebrow', text: 'Storage'}),
      seg([{value: 'json', label: 'Local files', ico: 'folder'}, {value: 'sqlserver', label: 'SQL Server', ico: 'database'}], cfg.mode, async v => {
        try { cfg = {...cfg, ...(await call('storage.set', {mode: v}))}; toast(v === 'sqlserver' ? `SQL Server for the next start: ${cfg.localDatabase} on ${cfg.instance}.` : (state.mode === 'install' ? 'Local files for the next start (Engine/server/accounts).' : 'Local files for the next start (sandbox accounts folder).'), 'ok'); }
        catch (e) { toast(e.message, 'err'); }
        render();
      }, {label: 'World storage', disabled: busy, title: busy ? 'Stop the world to change where it saves.' : 'Where the world saves accounts and characters. Applies at the next start; switching never merges or moves data.'}),
      h('span', {class: 'ss-note faint', text: cfg.mode === 'sqlserver' ? `Next start: ${cfg.localDatabase} · ${cfg.instance}. Game connects through localhost.` : (state.mode === 'install' ? 'Next start: engine accounts folder' : 'Next start: sandbox accounts folder')}));
  };
  call('storage.get').then(c => { cfg = c; render(); }).catch(e => replace(el, notice('warn', e.message)));
  on('world', w => { if (w.status !== lastStatus) { lastStatus = w.status; render(); } });
  return el;
}


/** The host's requested launch mode, independent of this machine's default. */
export function gameGuardSwitch() {
  const el = h('div', {class: 'gameguard-switch', id: 'act-gameguard'}); let enabled = true, loaded = false;
  const render = () => {
    const locked = !loaded || state.world?.status !== 'stopped' || !!state.world?.busy;
    replace(el, h('span', {class: 'ss-label eyebrow', text: 'Server GameGuard request'}),
      seg([{value: 'on', label: 'ON'}, {value: 'off', label: 'OFF'}], enabled ? 'on' : 'off', async v => {
        const want = v === 'on';
        try {
          await call('settings.set', {patch: {serverGameGuardRequired: want}});
          enabled = want;
          toast(want ? 'Joining DX11 clients will try to start GameGuard; protection is not verified.' : 'Joining DX11 clients will skip the GameGuard start request.', 'ok');
        } catch (e) { toast(e.message, 'err'); }
        render();
      }, {label: 'Server GameGuard request', disabled: locked, title: locked ? 'Stop your server before changing this request.' : 'Applies to your server at its next start. Guard startup and protection are not verified.'}),
      h('span', {class: 'ss-note faint', text: !loaded ? 'Loading…' : (locked ? 'Stop your server to change this request' : (enabled ? 'Requested for DX11; not verified' : 'Not requested for DX11'))}));
  };
  render();
  const apply = async () => {
    try {
      const r = await call('settings.get');
      enabled = r.settings?.serverGameGuardRequired !== false; loaded = true; render();
    } catch (e) { replace(el, notice('warn', e.message)); }
  };
  apply();
  on('world', () => render());
  return el;
}
export async function startWorld({mode = 'local', reviewed = false, host} = {}) {
  let job; try { job = await call('world.start', {mode, reviewed}); } catch (e) { toast(e.message, 'err'); return null; }
  return show(job, host, {onReview: async data => { if (await review(mode, data)) return startWorld({mode, reviewed: true, host}); return null; }});
}
export async function stopWorld({host} = {}) { let job; try { job = await call('world.stop'); } catch (e) { toast(e.message, 'err'); return null; } return show(job, host); }
export async function restartWorld({host} = {}) { let job; try { job = await call('world.restart'); } catch (e) { toast(e.message, 'err'); return null; } return show(job, host); }

async function show(job, host, {onReview} = {}) {
  const view = jobView(job, {compact: !!host});
  let d = null;
  let tracked = null;
  if (host) {
    inlineNotices.get(host)?.dispose();
    host.replaceChildren(view); host.hidden = false;
    tracked = worldJobNotice({host, view, job, readWorld: () => state.world, subscribe: fn => on('world', fn)});
    inlineNotices.set(host, tracked);
  } else d = dialog({title: job.title, body: view, actions: [button('Hide', {kind: 'ghost', onClick: () => d.close()})]});
  const final = await view.done;
  tracked?.update(final);
  refreshWorld();
  if (final?.state === 'succeeded') { toast(final.result?.attached ? 'The sandbox world was already running; attached to it.' : `${job.title}: done`, 'ok'); if (host) setTimeout(() => { if (host.firstChild === view) host.hidden = true; }, 2500); tracked?.dispose(); d?.close(); }
  else if (final?.errorCode === 'review-required') { if (host) host.hidden = true; d?.close(); return onReview?.(final.errorData); }
  else if (final?.errorCode === 'clients-connected') { toast(final.error, 'warn', {timeout: 12000}); }
  else if (final?.state === 'failed') toast(final.error, 'err');
  return final;
}
export function refreshWorld() { call('world.status', {fresh: true}).then(w => { state.world = w; }).catch(() => {}); }

/** First start: the existing launcher asks for the world settings before preparation and startup. */
function review(mode, current = {}) {
  return new Promise(resolve => {
    const name = textField({label: 'Server name', value: current.name || 'Dekaron Dedicated', maxLength: 64, help: 'Shown in the client, the world list and the in-game server display.', attrs: {autofocus: true}});
    const starter = switchRow({title: 'New characters get the starter pack', checked: current.starterPack !== false});
    const pk = switchRow({title: 'Allow PK on open maps', desc: 'Hold Ctrl to attack other players on open PvP maps. Safe zones, parties and guild mates stay protected.', checked: current.fieldPk !== false});
    const bots = switchRow({title: 'Bots (experimental)', desc: 'Off by default. Behaviour and performance are still being improved.', checked: current.npcPlayers === true});
    const err = h('div');
    const go = button('Save and start', {kind: 'primary', onClick: async () => {
      const scope = mode === 'hosted' ? 'friends' : 'local';
      const n = name.input.value.trim(); if (!n || n.length > 64) { setError(name, 'Use a server name of 1-64 printable characters.'); return; }
      try {
        if (n !== current.name) await call('world.settings.set', {scope, change: {name: n}});
        for (const [key, row, def] of [['starterPack', starter, current.starterPack !== false], ['fieldPk', pk, current.fieldPk !== false], ['npcPlayers', bots, current.npcPlayers === true]]) if (row.input.checked !== def) await call('world.settings.set', {scope, change: {[key]: row.input.checked}});
        await call('world.review.complete', {scope}); d.close(true);
      } catch (e) { err.replaceChildren(notice('err', e.message)); }
    }});
    const d = dialog({title: 'Review your world settings', body: [h('p', {class: 'muted', text: 'This world has not started before. Choose its settings; you can change them later in Server › World settings.'}), name, h('div', {class: 'rows'}, starter, pk, bots), err], actions: [button('Cancel', {kind: 'ghost', onClick: () => d.close(false)}), go], onClose: v => resolve(!!v)});
  });
}
