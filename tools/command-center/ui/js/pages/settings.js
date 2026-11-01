// Settings & About: every launcher preference with a description and when it takes effect; paths; version,
// licenses, documentation and contributors.
import {h, icon, replace, clear} from '../core/dom.js';
import {call} from '../core/api.js';
import {state, on} from '../core/state.js';
import * as f from '../core/format.js';
import {button, card, pill, notice, textField, selectField, switchRow, tabs, toast, kv, collapsible, dialog, setError, applies, seg} from '../ui/components.js';

const GROUP_TAB = {Appearance: 'appearance', Launcher: 'launcher', Notifications: 'launcher', Play: 'launcher', Advanced: 'advanced'};
const OPTIONS = {theme: [['dark', 'Dark'], ['light', 'Light'], ['system', 'Follow Windows']], reducedMotion: [['system', 'Follow Windows'], ['on', 'Reduce motion'], ['off', 'Allow motion']], density: [['comfortable', 'Comfortable'], ['compact', 'Compact']], startupPage: [['home', 'Home'], ['play', 'Play & Connect'], ['server', 'Server'], ['sql', 'SQL & Storage'], ['content', 'Game & Content'], ['updates', 'Updates & Diagnostics'], ['settings', 'Settings & About']], defaultTarget: [['native', 'DX11 Client'], ['native-fullscreen', 'DX11 Fullscreen'], ['desktop', 'Desktop App'], ['browser', 'Web Browser']]};
export function create({saveSettings}) {
  const ids = ['appearance', 'launcher', 'advanced', 'about'];
  const panels = Object.fromEntries(ids.map(i => [i, h('div', {class: 'tab-panel', id: 'panel-' + i, role: 'tabpanel', 'aria-labelledby': 'tab-' + i, hidden: i !== 'appearance'})]));
  let active = 'appearance', schema = null, current = null;
  const bar = tabs([{id: 'appearance', label: 'Appearance', ico: 'sun'}, {id: 'launcher', label: 'Launcher', ico: 'gear'}, {id: 'advanced', label: 'Advanced', ico: 'terminal'}, {id: 'about', label: 'About', ico: 'info'}], {current: 'appearance', label: 'Settings sections', onSelect: t => select(t)});
  function select(t) { active = t; for (const [k, p] of Object.entries(panels)) p.hidden = k !== t; if (t === 'about' && !panels.about.firstChild) about(); history.replaceState(null, '', `#/settings/${t}`); }
  const el = h('div', {class: 'stack loose'}, bar, ...Object.values(panels));

  function control(key, meta) {
    const value = current[key], fieldId = 'set-' + key, ap = meta.applies;
    const save = async v => { try { const r = await saveSettings({[key]: v}); current = r.settings; toast(`${meta.label} saved${ap === 'now' ? '' : ' (' + {'next-start': 'applies at the next world start', 'next-launch': 'applies the next time the launcher opens', 'next-game-window': 'applies to the next game window'}[ap] + ')'}.`, 'ok'); } catch (e) { toast(e.message, 'err'); throw e; } };
    if (typeof meta.default === 'boolean') return h('div', {id: fieldId + '-row'}, switchRow({title: meta.label, desc: meta.description, checked: value, applies: ap, fieldId, onChange: save}));
    if (OPTIONS[key]) return selectField({label: meta.label, value, options: OPTIONS[key].map(([v, l]) => ({value: v, label: l})), help: meta.description, applies: ap, fieldId, onChange: v => save(v).catch(() => {})});
    if (key === 'scale') { const w = h('div', {class: 'field'}); const lbl = h('span', {class: 'label'}, meta.label, applies(ap)); const out = h('span', {class: 'num', text: Math.round(value * 100) + '%'}); const r = h('input', {type: 'range', id: fieldId, min: '85', max: '150', step: '5', value: String(Math.round(value * 100)), 'aria-label': meta.label}); r.addEventListener('input', () => { out.textContent = r.value + '%'; document.documentElement.style.setProperty('--scale', String(r.value / 100)); }); r.addEventListener('change', () => save(Number(r.value) / 100).catch(() => {})); w.append(lbl, h('div', {class: 'row'}, r, out), h('div', {class: 'help', text: meta.description})); return w; }
    const fld = textField({label: meta.label, value: String(value), type: 'number', help: meta.description, applies: ap, fieldId});
    fld.input.addEventListener('change', async () => { setError(fld, null); try { await save(Number(fld.input.value)); } catch (e) { setError(fld, e.message.replace(/^params\.patch\.\w+: /, '')); fld.input.value = String(current[key]); } });
    return fld;
  }
  async function load() {
    const r = await call('settings.get'); schema = r.schema; current = r.settings;
    for (const t of ['appearance', 'launcher', 'advanced']) clear(panels[t]);
    const groups = {};
    for (const [k, m] of Object.entries(schema)) (groups[m.group] ||= []).push([k, m]);
    for (const [g, items] of Object.entries(groups)) {
      const tab = GROUP_TAB[g]; const switches = items.filter(([, m]) => typeof m.default === 'boolean'), others = items.filter(([, m]) => typeof m.default !== 'boolean');
      panels[tab].append(card({title: g, id: g === 'Advanced' ? 'adv' : undefined, desc: g === 'Advanced' ? 'Bounded refresh, query limits and history privacy.' : undefined, children: [others.length ? h('div', {class: 'form-grid'}, others.map(([k, m]) => control(k, m))) : null, switches.length ? h('div', {class: 'rows'}, switches.map(([k, m]) => control(k, m))) : null, h('div', {class: 'row end'}, button('Reset to defaults', {kind: 'ghost', size: 'small', onClick: async () => { const rr = await call('settings.reset', {keys: items.map(([k]) => k)}); state.settings = rr.settings; current = rr.settings; await load(); toast(`${g} reset.`, 'ok'); }}))]}));
    }
    panels.advanced.append(card({title: 'Paths', id: 'paths', desc: state.mode === 'install' ? 'Your engine and launcher profile are kept in separate folders so updates preserve settings.' : 'Where the preview keeps its files. Everything it writes stays inside the preview folder (plus DKPREVIEW_ test databases).', children: [kv(Object.entries(r.paths).map(([k, v]) => [{installation: 'Engine installation', preview: 'Preview folder', sandboxEngine: 'Sandbox engine', profile: 'Launcher profile', logs: 'Logs', backups: 'Backups', preparedData: 'Prepared Global data'}[k] || k, h('span', {class: 'mono wrap-any', text: v})])), h('div', {class: 'row wrap'}, button('Open logs', {kind: 'ghost', ico: 'folder', onClick: () => call('diag.openFolder', {which: 'logs'}).catch(e => toast(e.message, 'err'))}), button(state.mode === 'install' ? 'Open engine' : 'Open sandbox', {kind: 'ghost', ico: 'folder', onClick: () => call('diag.openFolder', {which: 'sandbox'}).catch(e => toast(e.message, 'err'))}))]}),
      card({title: 'Startup behaviour', desc: 'The launcher checks for updates when it opens and every 5 minutes, attaches to a world that is already running, and leaves externally started worlds alone.', children: [kv([['Closing with a running world', 'Asks first; closing saves and stops a world this launcher started. A world started elsewhere stays running.'], ['Background polling', 'Only visible pages refresh; a minimized window does not poll.'], ['SQL services', 'Never stopped by the launcher.']])]}));
    if (state.mode === 'install') {
      const classic = await call('app.classic');
      panels.launcher.append(card({title: 'Launcher choice', desc: 'This changes what Client.exe opens the next time you start it.', children: [switchRow({title: 'Use the classic launcher', desc: 'Return to the original galaxy launcher at the next start. You can switch back here, or delete run/classic-launcher.flag.', checked: classic.enabled, onChange: async enabled => { await call('app.classic.set', {enabled}); toast(enabled ? 'The classic launcher will open next time.' : 'Command Center will open next time.', 'ok'); }})]}));
    }
  }
  async function about() {
    const a = await call('about.info');
    const docsBox = h('div', {class: 'rows'}, a.docs.map(d => h('div', {class: ['r', 'clickable'], role: 'button', tabindex: '0', onClick: () => openDoc(d.name)}, icon('book', 18), h('span', {class: 'grow', text: d.title}), icon('chevronRight', 16))));
    const contributors = collapsible('Contributors', h('div', {class: 'stack tight'}, h('p', {class: 'muted', text: 'People whose knowledge, files and testing shaped this engine.'}), h('div', {class: 'grid four stretch'}, a.contributors.map((c, i) => h('section', {class: ['card', 'tint', ['mint', 'rose', 'amber', 'violet'][i % 4], 'stat']}, h('div', {class: 'stat-label', text: c}))))), {open: false, desc: 'Franky, DEV ShadoW, CYBER and Magic Ibrar'});
    contributors.id = 'contributors';
    panels.about.append(h('div', {class: 'split'}, h('div', {class: 'stack'}, card({title: 'DK Command Center', id: 'about', desc: a.edition || 'DK Engine launcher', children: [kv(state.mode === 'install' ? [['App version', a.appVersion], ['Engine', a.engineVersion], ['App identity', a.identity], ['Node.js', a.node], ['WebView2 runtime', a.webview2 || (a.window ? 'unknown' : 'headless')], ['Local world', `Port ${a.install.worldPort}`]] : [['Preview version', a.previewVersion], ['Engine (sandbox)', a.engineVersion], ['Installed game', a.installedVersion], ['Published release', a.published], ['App identity', a.identity], ['Node.js', a.node], ['WebView2 runtime', a.webview2 || (a.window ? 'unknown' : 'headless')], ['Sandbox world', `${a.sandbox.engine} · port ${a.sandbox.worldPort}`]])]}), contributors, card({title: 'Licenses', children: [kv(a.licenses.map(l => [l.name, `${l.license}${l.file ? ' · ' + l.file : ''}`]))]})), card({title: 'Documentation', id: 'docs', children: [docsBox]})));
  }
  async function openDoc(name) { try { const d = await call('about.doc', {name}); dialog({title: name, wide: true, body: h('pre', {class: 'block', text: d.text})}); } catch (e) { toast(e.message, 'err'); } }
  let loaded = false;
  return {el, async show(tab) { if (!loaded) { await load(); loaded = true; } bar.select(ids.includes(tab) ? tab : active); }};
}
