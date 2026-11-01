// Closing the window while a world or an operation is running asks first (existing behaviour: closing saves and stops
// a world this launcher started; an attached world is left running).
import {h} from '../core/dom.js';
import {call} from '../core/api.js';
import {poller} from '../core/poll.js';
import {state} from '../core/state.js';
import {dialog, button, notice, toast} from './components.js';

let showing = false;
export function watchClose() {
  poller(async signal => { const r = await call('app.pendingClose', {}, {signal}); if (r.pending && !showing) ask(r.state); return r; }, {interval: 900, name: 'close'}).start();
}
function ask(s) {
  showing = true;
  const owned = s.world === 'running' && s.owned;
  const body = [
    s.world === 'running' ? notice(owned ? 'warn' : 'info', owned ? `Your ${state.mode === 'install' ? '' : 'sandbox '}world is running. Closing saves every character and stops the world this launcher started.` : `The ${state.mode === 'install' ? '' : 'sandbox '}world was already running when the launcher opened. Closing leaves it running.`) : null,
    s.jobs.length ? notice('warn', 'Still running: ' + s.jobs.join(', ') + '. Closing cancels what can be cancelled safely.') : null,
    h('p', {class: 'muted', text: 'Game windows stay open. Close them first if you want the world to stop now; a world refuses to stop while clients are connected.'}),
  ];
  const err = h('div'); body.push(err);
  const finish = async decision => {
    if (decision !== 'cancel') { err.replaceChildren(notice('info', decision === 'stop-and-close' ? `Closing the ${state.mode === 'install' ? 'DX11' : 'Test Bench'} client if it is open (the world releases its session within about a minute), then saving every character and stopping the world…` : 'Closing…')); d.box?.querySelectorAll('button').forEach(b => { b.disabled = true; }); }
    try { await call('app.close', {decision}, {timeoutMs: 180000}); if (decision === 'cancel') { d.close(); } }
    catch (e) { err.replaceChildren(notice('err', e.message)); d.box?.querySelectorAll('button').forEach(b => { b.disabled = false; }); await call('app.pendingClose.clear').catch(() => {}); showing = false; }
  };
  const d = dialog({title: 'Close DK Command Center?', body, dismissible: false, actions: [
    button('Keep open', {kind: 'ghost', onClick: async () => { await call('app.pendingClose.clear').catch(() => {}); await finish('cancel'); showing = false; }}),
    owned ? button('Save, stop and close', {kind: 'primary', onClick: () => finish('stop-and-close')}) : button('Close', {kind: 'primary', onClick: () => finish('close')}),
  ]});
}
