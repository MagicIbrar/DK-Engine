// Embedded update card: a small card inside the launcher window. Install now / Later / X (and Escape) - dismissing never
// consents to installation; the update stays available on Updates & Diagnostics.
import {h, icon, clear} from '../core/dom.js';
import {call, follow} from '../core/api.js';
import {poller} from '../core/poll.js';
import {state} from '../core/state.js';
import {button, iconBtn, toast, jobView, pill} from './components.js';

let card = null, job = null, prevFocus = null, failure = null;
export function mountUpdateCard({navigate}) {
  const p = poller(async signal => { const s = await call('updates.status', {}, {signal}); state.updates = s; render(s, navigate); return s; }, {interval: 30000, name: 'updates'}).start();
  window.addEventListener('dk-updates-changed', () => p.now());
  document.addEventListener('keydown', e => { if (e.key === 'Escape' && card && !document.querySelector('.scrim') && (card.contains(document.activeElement) || document.activeElement === document.body)) { e.preventDefault(); dismiss(); } });
}
function dismiss() { const v = state.updates?.available?.version; failure = null; if (v) call('updates.dismiss', {version: v}).then(() => window.dispatchEvent(new Event('dk-updates-changed'))).catch(() => {}); hide(); toast('Update notice hidden. It stays available in Updates & Diagnostics.', 'info'); }
function hide() { card?.remove(); card = null; try { prevFocus?.focus(); } catch {} prevFocus = null; }
function render(s, navigate) {
  const worker = s.worker?.status && s.worker.status !== 'idle' ? s.worker : null;
  const show = (s.notify && !card) || (card && (s.available || worker || job || failure));
  if (!show) { if (card && !job) hide(); return; }
  if (!card) { prevFocus = document.activeElement; card = h('aside', {class: 'update-card', role: 'region', 'aria-label': 'Engine update', id: 'update-card'}); document.body.append(card); }
  const a = s.available;
  const head = h('div', {class: 'uc-head'}, h('div', {class: 'uc-badge'}, icon('download', 20)), h('div', {class: 'stack tight grow'}, h('h3', {text: worker ? `Update ${worker.version || a?.version || ''}` : `Update ${a?.version} available`}), h('div', {class: 'row wrap'}, a?.fixture ? pill('Test fixture', 'gold', {title: 'This release comes from the preview\'s fake update service, not GitHub.'}) : null, worker ? pill(worker.status, worker.status === 'failed' ? 'err' : worker.status === 'complete' ? 'ok' : 'warn') : null)), iconBtn('Dismiss update notification', 'close', dismiss));
  const text = failure && !job ? 'The update was not installed. Nothing on this installation changed.' : worker ? worker.message : (a?.fixture ? 'A newer verified release is ready to download. Size and SHA-256 are checked before anything is scheduled; installation waits until the game, world and launcher are closed.' : 'A newer release is available.');
  const notes = s.notes ? h('details', {}, h('summary', {text: 'Release notes'}), h('pre', {class: 'block', text: s.notes})) : null;
  const actions = h('div', {class: 'row end wrap'});
  if (job) actions.append(button('Show progress', {kind: 'ghost', onClick: () => navigate('updates/updates')}));
  else if (failure) actions.append(button('Later', {kind: 'ghost', onClick: dismiss}), button('Retry', {kind: 'primary', ico: 'refresh', onClick: () => install(navigate)}));
  else if (worker?.status === 'failed') actions.append(button('Retry', {kind: 'primary', ico: 'refresh', onClick: () => install(navigate)}), button('Later', {kind: 'ghost', onClick: dismiss}));
  else if (worker && ['queued', 'downloading', 'waiting', 'applying'].includes(worker.status)) actions.append(button('Details', {kind: 'ghost', onClick: () => navigate('updates/updates')}), button('Hide', {kind: 'ghost', onClick: hide}));
  else if (worker?.status === 'complete') actions.append(button('Done', {kind: 'primary', onClick: hide}));
  else actions.append(button('Later', {kind: 'ghost', onClick: dismiss}), button('Install now', {kind: 'primary', onClick: () => install(navigate)}));
  const failNote = failure && !job ? h('div', {class: 'notice err', role: 'alert'}, icon('alert', 18), h('div', {class: 'grow', text: failure})) : null;
  clear(card).append(...[head, h('p', {class: 'muted', text: text}), failNote, job ? job.view : null, notes, actions].filter(Boolean));
}
async function install(navigate) {
  failure = null;
  try {
    const j = await call('updates.install'); const view = jobView(j, {compact: true}); job = {view};
    render(state.updates, navigate);
    const final = await view.done; job = null;
    if (final?.state === 'succeeded') toast('Update scheduled. It installs after the fixture installation\'s world, game and launcher are closed.', 'ok');
    else if (final) failure = final.state === 'cancelled' ? 'Cancelled before anything was scheduled.' : (final.error || 'Update failed.');
  } catch (e) { job = null; failure = e.message; }
  render(state.updates, navigate);
  window.dispatchEvent(new Event('dk-updates-changed'));
}
