// Game & Content: game window options that the launcher really controls, Global data selection/preparation status,
// read-only integrity verification, compatibility, Item/Map Builder, authored content and small previews.
import {h, icon, replace, clear} from '../core/dom.js';
import {call} from '../core/api.js';
import {state, on} from '../core/state.js';
import * as f from '../core/format.js';
import {button, card, pill, notice, selectField, switchRow, tabs, table, toast, kv, empty, runJob, confirm} from '../ui/components.js';

export function create({navigate, saveSettings}) {
  const ids = ['launch', 'global', 'tools', 'overrides'];
  const panels = Object.fromEntries(ids.map(i => [i, h('div', {class: 'tab-panel', id: 'panel-' + i, role: 'tabpanel', 'aria-labelledby': 'tab-' + i, hidden: i !== 'launch'})]));
  let active = 'launch'; const built = {};
  const bar = tabs([{id: 'launch', label: 'Game window', ico: 'play'}, {id: 'global', label: 'Global data', ico: 'layers'}, {id: 'tools', label: 'Tools', ico: 'wand'}, {id: 'overrides', label: 'Content', ico: 'map'}], {current: 'launch', label: 'Game & Content sections', onSelect: t => select(t)});
  function select(t) { active = t; for (const [k, p] of Object.entries(panels)) p.hidden = k !== t; if (!built[t]) built[t] = ({launch, global, tools, overrides})[t](); built[t].show?.(); history.replaceState(null, '', `#/content/${t}`); }
  const el = h('div', {class: 'stack loose'}, bar, ...Object.values(panels));

  function launch() {
    const p = panels.launch, opts = h('div', {class: 'stack'}), wins = h('div', {class: 'stack tight'});
    p.append(h('div', {class: 'split'}, card({title: 'Game window options', id: 'launch-opts', desc: 'What the launcher itself controls. Graphics, audio and key bindings are changed inside the game (Options) and saved per game window profile.', children: [opts]}), card({title: 'Remembered window sizes', desc: 'Saved by the DX11 window per account (Options › resolution, window mode, F11).', children: [wins]})));
    function render(s) {
      replace(opts, selectField({label: 'Default game window', value: s.defaultTarget, applies: 'now', options: [{value: 'native', label: 'DX11 Client (windowed 1280×720)'}, {value: 'native-fullscreen', label: 'DX11 Fullscreen (borderless)'}, {value: 'desktop', label: 'Desktop App (Edge/Chrome app window)'}, {value: 'browser', label: 'Web Browser tab'}], onChange: v => saveSettings({defaultTarget: v}).then(() => toast('Default game window saved.', 'ok'), e => toast(e.message, 'err'))}),
        h('div', {class: 'rows'}, switchRow({title: 'Uncapped frame rate (benchmark)', desc: 'Existing opt-in for Desktop App windows only: lifts the frame cap and vsync. The picture will tear.', checked: s.uncappedFps, applies: 'next-game-window', onChange: v => saveSettings({uncappedFps: v})})),
        kv([['DX11 window', `GameWindow.exe in ${state.mode === 'install' ? 'this engine' : 'the sandbox engine'}; F11 toggles fullscreen; the last applied resolution is remembered per account.`], ['Desktop App', 'Throw-away browser profile per window, removed after it closes; GPU rasterization and no background throttling (existing switches).'], ['Pre-launch byte verification', state.mode === 'install' ? 'Prepared assets are checked before the game window opens. Global data › Verify runs a full read-only integrity check.' : 'Not used in the preview: the engine verifier needs prepared data inside the engine folder and writes receipts there. Use Global data › Verify for a read-only check.']]));
    }
    async function loadWins() { try { const r = await call('content.windows'); replace(wins, r.profiles.length ? table({caption: 'Window sizes', columns: [{key: 'profile', label: 'Account'}, {key: 'size', label: 'Size', render: x => x.width ? `${x.width}×${x.height}` : x.raw}, {key: 'fullscreen', label: 'Fullscreen', render: x => x.fullscreen ? 'yes' : 'no'}, {key: 'x', label: '', sortable: false, render: x => button('Reset', {size: 'small', kind: 'ghost', onClick: async () => { await call('content.windows.reset', {profile: x.profile}); toast(`Window size reset for ${x.profile}.`, 'ok'); loadWins(); }})}], rows: r.profiles}) : empty('No DX11 window has saved a size yet.'), h('p', {class: 'faint', text: r.note})); } catch (e) { replace(wins, notice('warn', e.message)); } }
    on('settings', s => { if (built.launch) render(s); });
    return {show() { render(state.settings); loadWins(); }};
  }

  function global() {
    const p = panels.global, sel = h('div', {class: 'stack'}), integ = h('div', {class: 'stack tight'}), compat = h('div', {class: 'stack tight'});
    p.append(h('div', {class: 'split'}, h('div', {class: 'stack'}, card({title: 'Selected Global data', id: 'global', children: [sel]}), card({title: 'Compatibility', id: 'compat', desc: 'Structural check of core tables, item records and map headers. Recognizing a layout does not mean a new Global format works.', children: [compat]})), card({title: 'Integrity', id: 'verify', desc: 'Reads every prepared byte once and compares SHA-256 with this installation\'s receipt. Read-only.', children: [integ]})));
    async function load() {
      let g; try { g = await call('content.global'); } catch (e) { replace(sel, notice('err', e.message)); return; }
      replace(sel, kv([['Source', g.selected.kind], ['Location', h('span', {class: 'mono wrap-any', text: g.selected.sourceEngine})], ['Generation', h('span', {class: 'mono', text: g.generation})], ['Fingerprint', h('span', {class: 'mono', text: f.short(g.fingerprint, 16)})], ['Prepared', f.dateTime(g.prepared)], ['Files', `${f.n(g.files)} · ${f.bytes(g.bytes)}`], ['Readiness', g.readiness.ready ? pill('Ready', 'ok') : pill('Not ready', 'err')]]), h('p', {class: 'faint', text: g.selected.note}), notice('info', g.preparation.reason));
      const last = g.lastIntegrity;
      replace(integ, last ? notice(last.ok ? 'ok' : 'err', last.ok ? `Verified ${f.n(last.files)} files (${f.bytes(last.bytes)}) in ${last.seconds} s on ${f.dateTime(last.at)}.` : `${last.failures.length} problem(s) found on ${f.dateTime(last.at)}.`) : empty(state.mode === 'install' ? 'Not verified yet.' : 'Not verified from the preview yet.'), last?.failures?.length ? table({caption: 'Problems', columns: [{key: 'file', label: 'File', mono: true, wrap: true}, {key: 'problem', label: 'Problem'}], rows: last.failures}) : null, h('div', {class: 'row'}, button('Verify prepared data', {kind: 'primary', ico: 'shield', onClick: async () => { await runJob('content.verify', {}, {title: 'Verify prepared Global data', successText: 'Prepared data verified.'}).catch(() => {}); load(); }})), h('p', {class: 'faint', text: 'Takes about as long as reading ~10 GB from disk. Prepared game data is read only.'}));
    }
    async function loadCompat() { replace(compat, h('div', {class: 'row faint'}, h('span', {class: 'spinner'}), 'Inspecting…')); try { const r = await call('content.compat'); replace(compat, notice(r.compatible ? 'ok' : 'warn', r.compatible ? `Compatible: ${r.inputs.length} inputs recognized in ${r.ms} ms.` : `${r.issues.length} issue(s).`), r.issues.length ? table({caption: 'Issues', columns: [{key: 'file', label: 'File', mono: true}, {key: 'code', label: 'Issue'}], rows: r.issues}) : null, table({caption: 'Recognized inputs', tall: true, columns: [{key: 'file', label: 'Input', mono: true, wrap: true}, {key: 'kind', label: 'Kind'}, {key: 'profile', label: 'Profile'}, {key: 'bytes', label: 'Size', num: true, render: x => f.bytes(x.bytes)}], rows: r.inputs.filter(i => i.kind !== 'map-header').concat([{file: `${r.inputs.filter(i => i.kind === 'map-header').length} map headers`, kind: 'map-header', profile: '', bytes: r.inputs.filter(i => i.kind === 'map-header').reduce((a, i) => a + i.bytes, 0)}])}), h('p', {class: 'faint', text: r.note})); } catch (e) { replace(compat, notice('err', e.message)); } }
    return {show() { load(); if (!compat.firstChild) loadCompat(); }};
  }

  function tools() {
    const p = panels.tools, body = h('div', {class: 'stack'});
    p.append(card({title: 'Builders', id: 'tools', desc: 'Item Builder and Map Builder open inside the primary GM game window: the first account that signed in after Start. GM permission required.', children: [body]}));
    function render(w) {
      const ready = w?.status === 'running' && w.builderReady;
      replace(body, h('div', {class: 'grid two stretch'},
        h('section', {class: 'card tint amber stat'}, h('div', {class: 'stat-label', text: 'Item Builder'}), h('div', {class: 'stat-bottom'}, h('div', {class: 'stat-note', text: 'Create custom items from native looks or rigid GLB models.'}), button('Open', {kind: 'primary', disabled: !ready, onClick: () => open('itembuilder')}))),
        h('section', {class: 'card tint sky stat'}, h('div', {class: 'stat-label', text: 'Map Builder'}), h('div', {class: 'stat-bottom'}, h('div', {class: 'stat-note', text: 'Edit custom maps and overlays on original maps.'}), button('Open', {kind: 'primary', disabled: !ready, onClick: () => open('mapbuilder')})))),
        ready ? notice('ok', `Ready in primary account ${w.primary}.`) : notice('info', w?.status !== 'running' ? 'Start the world, sign in with a GM account and enter a character.' : w.primary ? `Waiting for primary account ${w.primary} to finish loading in game (GM permission required).` : 'Sign in to the first game window and enter a character first.', {action: button('Test Bench', {size: 'small', kind: 'ghost', onClick: () => navigate('play/bench')})}));
    }
    async function open(tool) { try { const r = await call('world.tool', {tool}); toast(r.message, 'ok'); } catch (e) { toast(e.message, 'err'); } }
    on('world', w => { if (active === 'tools') render(w); });
    return {show() { render(state.world); }};
  }

  function overrides() {
    const p = panels.overrides, lib = h('div', {class: 'stack'}), prev = h('div', {class: 'stack tight'});
    const which = h('select', {class: 'input', 'aria-label': 'Table', id: 'preview'}, [['maps', 'Maps (maplist.csv)'], ['classes', 'Classes (classes.json)'], ['items', 'Items']].map(([v, l]) => h('option', {value: v, text: l})));
    const q = h('input', {class: 'input', type: 'search', placeholder: 'Search', 'aria-label': 'Search preview'});
    p.append(h('div', {class: 'split'}, card({title: 'Authored content and precedence', id: 'overrides', children: [lib]}), card({title: 'Content preview', desc: 'From tables the existing loaders already produce; read-only.', children: [h('div', {class: 'input-row'}, which, q), prev]})));
    async function load() { try { const r = await call('content.overrides'); replace(lib, h('ol', {class: 'stack tight'}, r.precedence.map(x => h('li', {text: x}))), ...r.worlds.map(w => h('div', {class: 'stack tight'}, h('h3', {text: w.scope}), table({caption: w.scope, columns: [{key: 'kind', label: 'Library'}, {key: 'path', label: 'Location', mono: true, wrap: true}, {key: 'state', label: 'State', render: x => !x.exists ? 'none yet' : x.items !== undefined && x.items !== null ? `${x.items} items${x.valid === false ? ' · invalid format' : ''}` : x.entries !== undefined ? `${x.entries} entries` : f.bytes(x.bytes)}], rows: w.libraries}))), h('p', {class: 'faint', text: r.note})); } catch (e) { replace(lib, notice('err', e.message)); } }
    let t = null; const runPrev = async () => { try { const r = await call('content.preview', {table: which.value, search: q.value || undefined}); replace(prev, r.rows.length ? table({caption: 'Preview', tall: true, columns: Object.keys(r.rows[0]).map(k => ({key: k, label: k})), rows: r.rows}) : r.note ? notice('info', r.note) : empty('No rows.'), h('p', {class: 'faint', text: `${r.total ?? '—'} rows · ${r.source || ''}`})); } catch (e) { replace(prev, notice('warn', e.message)); } };
    which.addEventListener('change', runPrev); q.addEventListener('input', () => { clearTimeout(t); t = setTimeout(runPrev, 250); });
    return {show() { load(); runPrev(); }};
  }
  return {el, show(tab) { bar.select(ids.includes(tab) ? tab : active); }};
}
