// Updates & Diagnostics: updates and history, health / support export / recovery, live log reader, code & file
// finder (text + hex), event timeline and measured performance.
import {h, icon, replace, clear} from '../core/dom.js';
import {call} from '../core/api.js';
import {poller} from '../core/poll.js';
import {state, on} from '../core/state.js';
import * as f from '../core/format.js';
import {button, card, pill, notice, selectField, switchRow, tabs, table, dialog, toast, kv, empty, runJob, copyText, seg, iconBtn} from '../ui/components.js';

export function create({navigate}) {
  const ids = ['updates', 'health', 'logs', 'files', 'timeline', 'performance'];
  const panels = Object.fromEntries(ids.map(i => [i, h('div', {class: 'tab-panel', id: 'panel-' + i, role: 'tabpanel', 'aria-labelledby': 'tab-' + i, hidden: i !== 'updates'})]));
  let active = 'updates'; const built = {};
  const bar = tabs([{id: 'updates', label: 'Updates', ico: 'download'}, {id: 'health', label: 'Health', ico: 'shield'}, {id: 'logs', label: 'Live logs', ico: 'list'}, {id: 'files', label: 'Code & files', ico: 'search'}, {id: 'timeline', label: 'Timeline', ico: 'clock'}, {id: 'performance', label: 'Performance', ico: 'pulse'}], {current: 'updates', label: 'Diagnostics categories', onSelect: t => select(t), onOverview: () => { for (const b of Object.values(built)) b.hide?.(); history.replaceState(null, '', '#/updates'); }});
  function select(t) { active = t; for (const [k, p] of Object.entries(panels)) p.hidden = k !== t; if (!built[t]) built[t] = ({updates, health, logs, files, timeline, performance})[t](); built[t].show?.(); for (const [k, b] of Object.entries(built)) if (k !== t) b.hide?.(); history.replaceState(null, '', `#/updates/${t}`); }
  const el = h('div', {class: 'stack loose'}, bar, ...Object.values(panels));
  window.addEventListener('dk-open-file', e => { select('files'); bar.select('files'); built.files?.open(e.detail); });

  // ---------- updates
  function updates() {
    const p = panels.updates, top = h('div', {class: 'grid four stretch', id: 'upd'}), avail = h('div', {class: 'stack'}), workerBox = h('div', {class: 'stack tight'}), histBox = h('div', {class: 'rows'}), notesBox = h('div'), testBox = h('div', {class: 'stack tight'});
    p.append(top, h('div', {class: 'split'}, h('div', {class: 'stack'}, card({title: 'Available update', children: [avail]}), card({title: 'Installation progress', desc: 'Reported by the engine\'s deferred updater. It waits until the game, world and launcher are safely closed and never force-stops anything.', children: [workerBox]}), card({title: 'Installed release notes', children: [notesBox]})), h('div', {class: 'stack'}, card({title: 'Update source', desc: state.mode === 'install' ? 'Verified releases from the project GitHub repository.' : 'The preview uses a fake update service (fixture) or a read-only GitHub check. Main and the sandbox engine are never updated here.', children: [testBox]}), card({title: 'History', children: [histBox]}))));
    function render(s) {
      const t = (label, value, note, tint) => h('section', {class: ['card', 'tint', tint, 'stat']}, h('div', {class: 'stat-label', text: label}), h('div', {class: 'stat-value small num', text: value || '—'}), h('div', {class: 'stat-note', text: note}));
      replace(top, ...(s.install ? [t('Installed engine', s.installed.engine, 'This PC', 'mint'), t('Update source', 'GitHub', 'Verified release feed', 'violet')] : [t('Installed game', s.installed.main, 'Main (read only)', 'mint'), t('Sandbox engine', s.installed.sandbox, 'Runs the preview world', 'violet'), t('Fixture install', s.installed.fixtureInstall || 'not built', 'Disposable update target', 'amber')]), t('Latest check', s.lastCheck ? s.lastCheck.status : '—', s.lastCheck ? `${s.lastCheck.mode === 'live' ? 'GitHub' : 'fixture'} · ${f.ago(s.lastCheck.at)}` : 'not yet', 'sky'));
      const a = s.available;
      replace(avail, a ? h('div', {class: 'stack tight'}, h('div', {class: 'row wrap'}, h('h3', {text: `Version ${a.version}`}), a.fixture ? pill('Test fixture', 'gold') : pill('GitHub', 'info'), s.dismissed === a.version ? pill('Notice dismissed', '') : null), kv([['Asset', a.name], ['Size', f.bytes(a.bytes)], ['SHA-256', h('span', {class: 'mono', text: f.short(a.sha256, 24)})], ['Source', h('span', {class: 'mono wrap-any', text: a.url})]]), s.notes ? h('details', {}, h('summary', {text: 'Release notes'}), h('pre', {class: 'block', text: s.notes})) : null, h('div', {class: 'row'}, button('Install now', {kind: 'primary', disabled: !s.install && (!a.fixture || !s.fixtureInstallExists), onClick: async () => { await runJob('updates.install', {}, {title: `Install ${a.version}`, successText: s.install ? 'Update scheduled. Close the game, world and launcher to install it.' : 'Update scheduled. It installs when the fixture installation is closed.'}).catch(() => {}); refresh(); }}), !s.install && !s.fixtureInstallExists ? h('span', {class: 'faint', text: 'Build the test fixture first.'}) : null)) : s.error ? notice('warn', s.error) : notice('ok', 'No newer release. Your engine is up to date.'));
      const w = s.worker;
      replace(workerBox, w && w.status !== 'idle' ? [h('div', {class: 'phases'}, ['queued', 'downloading', 'waiting', 'applying', 'complete'].map((ph, i, all) => { const at = all.indexOf(w.status); const st = w.status === 'failed' ? (i === 0 ? 'failed' : '') : i < at ? 'done' : i === at ? (ph === 'complete' ? 'done' : 'now') : ''; return h('div', {class: ['ph', st]}, h('span', {class: 'mk'}, st === 'done' ? icon('check', 12) : null), h('span', {text: {queued: 'Requested', downloading: 'Download and verify', waiting: 'Wait for game, world and launcher to close', applying: 'Install with rollback copy', complete: 'Installed'}[ph]})); })), notice(w.status === 'failed' ? 'err' : w.status === 'complete' ? 'ok' : 'info', `${w.message}${w.updatedAt ? ' · ' + f.ago(w.updatedAt) : ''}`), w.status === 'failed' ? button('Retry', {ico: 'refresh', onClick: async () => { await runJob('updates.install', {}, {title: 'Retry update'}).catch(() => {}); refresh(); }}) : null] : [empty('No installation requested.')]);
      replace(histBox, s.history.length ? s.history.map(x => h('div', {class: 'r'}, h('span', {class: ['event-dot', x.status === 'available' || x.kind === 'install-requested' ? 'info' : x.status === 'offline' ? 'warn' : 'ok']}), h('div', {class: 'grow stack tight'}, h('span', {text: x.kind === 'check' ? `Check (${x.mode === 'live' ? 'GitHub' : 'fixture'}): ${x.status}${x.version ? ' ' + x.version : ''}` : x.kind === 'dismissed' ? `Notice for ${x.version} dismissed` : `Install requested: ${x.version} (${x.status})`}), h('span', {class: 'faint', text: f.dateTime(x.at)})))) : [empty('No update activity yet.')]);
      replace(notesBox, s.notesInstalled ? h('pre', {class: 'block', text: s.notesInstalled}) : empty('No release notes found.'));
      const scen = s.install ? null : selectField({label: 'Fixture scenario', value: s.scenario, options: s.scenarios.map(v => ({value: v, label: {available: 'Update available (4.0.2 fixture)', current: 'Already current', offline: 'Service offline', 'download-fail': 'Download interrupted', 'hash-mismatch': 'Corrupted download (hash mismatch)'}[v]})), onChange: async v => { try { const r = await call('updates.scenario', {scenario: v}); state.updates = r; render(r); window.dispatchEvent(new Event('dk-updates-changed')); } catch (e) { toast(e.message, 'err'); } }});
      if (s.install) { replace(testBox, button('Check GitHub now', {ico: 'refresh', onClick: () => check('live')}), switchRow({title: 'Check for updates when the launcher opens', desc: 'Updates remain available here even if opening notices are off.', checked: s.preferences?.checkOnLaunch !== false, onChange: v => call('updates.preferences', {checkOnLaunch: v}).then(() => toast('Preference saved.', 'ok'))}), h('p', {class: 'faint', text: s.safety})); return; }
      replace(testBox, h('div', {class: 'row wrap'}, button('Check fixture now', {ico: 'refresh', onClick: () => check('fixture')}), button('Check GitHub (read only)', {kind: 'ghost', ico: 'globe', onClick: () => check('live')})), scen, switchRow({title: 'Check for updates when the launcher opens', desc: 'Engine updater preference (stored in the preview\'s redirected updater folder). Checks still run every 5 minutes while open.', checked: s.preferences?.checkOnLaunch !== false, onChange: v => call('updates.preferences', {checkOnLaunch: v}).then(() => toast('Preference saved.', 'ok'))}), s.fixture ? kv([['Fixture release', s.fixture.version], ['Fixture archive', `${s.fixture.zip} · ${f.bytes(s.fixture.bytes)}`]]) : notice('info', 'The fixture is not built yet.'), button(s.fixture ? 'Rebuild test fixture' : 'Build test fixture', {kind: 'ghost', onClick: async () => { await runJob('updates.fixture.build', {}, {title: 'Build update test fixture', successText: 'Fixture ready.'}).catch(() => {}); refresh(); }}), h('p', {class: 'faint', text: s.safety}));
    }
    async function check(mode) { try { const r = await call('updates.check', {mode}); state.updates = r; render(r); window.dispatchEvent(new Event('dk-updates-changed')); toast(r.available ? `Update ${r.available.version} available.` : r.error ? r.error : 'Up to date.', r.error ? 'warn' : 'ok'); } catch (e) { toast(e.message, 'err'); } }
    async function refresh() { try { const r = await call('updates.status'); state.updates = r; render(r); } catch (e) { toast(e.message, 'err'); } }
    const pp = poller(async () => refresh(), {interval: 4000, active: () => active === 'updates', name: 'updates-page'});
    return {show() { pp.start(); }, hide() { pp.stop(); }};
  }

  // ---------- health
  function health() {
    const p = panels.health, checks = h('div', {class: 'stack tight'}), rec = h('div', {class: 'stack tight'});
    p.append(h('div', {class: 'split'}, card({title: 'Health checks', id: 'health', actions: [button('Run again', {size: 'small', ico: 'refresh', onClick: () => load()})], children: [checks]}), h('div', {class: 'stack'}, card({title: 'Support export', id: 'support', desc: 'A ZIP with health, timeline, settings and recent log tails. Home paths, user names, tokens, passwords, cookies and tickets are removed. No account data or SQL passwords.', children: [h('div', {class: 'row wrap'}, button('Export…', {kind: 'primary', ico: 'download', onClick: () => runJob('diag.export', {toFile: true}, {title: 'Support export', successText: 'Support bundle saved.'}).catch(() => {})}), button('Export to evidence folder', {kind: 'ghost', onClick: async () => { const r = await runJob('diag.export', {toFile: false}, {title: 'Support export'}).catch(() => null); if (r?.result?.file) toast('Saved: ' + r.result.file, 'ok'); }}))]}), state.mode === 'install' ? null : card({title: 'Installed game unchanged?', id: 'main-check', desc: 'Compares Main with the read-only baseline taken before the preview existed: file list, sizes, times, hashes of mutable state and SQL row counts.', children: [button('Verify Main unchanged', {ico: 'shield', onClick: async () => { const r = await runJob('diag.mainUnchanged', {}, {title: 'Verify Main unchanged', keepOpen: true}).catch(() => null); if (r?.result) toast(r.result.identical ? 'Main is identical to the baseline.' : `Main differs: ${r.result.changed.length} changed, ${r.result.added.length} added, ${r.result.removed.length} removed files.`, r.result.identical ? 'ok' : 'warn', {timeout: 12000}); }})]}), card({title: 'Recovery and rollback', id: 'recovery', children: [rec]}))));
    async function load() {
      replace(checks, h('div', {class: 'row faint'}, h('span', {class: 'spinner'}), 'Running checks…'));
      try { const r = await call('diag.health'); replace(checks, h('div', {class: 'row wrap'}, pill(`${r.summary.ok} ok`, 'ok'), r.summary.warn ? pill(`${r.summary.warn} warnings`, 'warn') : null, r.summary.error ? pill(`${r.summary.error} errors`, 'err') : null, h('span', {class: 'faint', text: f.time(r.at)})), table({caption: 'Checks', columns: [{key: 'area', label: 'Area'}, {key: 'name', label: 'Check'}, {key: 'state', label: 'State', render: c => pill(c.state === 'error' ? 'Error' : c.state === 'warn' ? 'Warning' : c.state === 'ok' ? 'OK' : 'Info', c.state === 'error' ? 'err' : c.state === 'warn' ? 'warn' : c.state === 'ok' ? 'ok' : 'info')}, {key: 'detail', label: 'Detail', wrap: true}], rows: r.checks})); }
      catch (e) { replace(checks, notice('err', e.message)); }
      try { const r = await call('diag.recovery'); replace(rec, r.rollbacks.length ? table({caption: 'Rollback folders', columns: [{key: 'name', label: 'Folder', mono: true}, {key: 'note', label: 'What it is', wrap: true}], rows: r.rollbacks}) : empty('No rollback folders found.'), r.sqlSetupBackups.length ? kv([['SQL setup account backups', r.sqlSetupBackups.join(', ')]]) : null, r.backups.length ? kv([['Latest SQL backup', `${r.backups[0].database || r.backups[0].target} · ${f.dateTime(r.backups[0].at)}`]]) : null, ...r.notes.map(n => h('p', {class: 'faint', text: n}))); } catch (e) { replace(rec, notice('warn', e.message)); }
    }
    return {show() { if (!checks.firstChild) load(); }};
  }

  // ---------- live logs
  function logs() {
    const p = panels.logs, srcBox = h('div', {class: 'rows'}), view = h('div', {class: 'log', id: 'logs', role: 'log', 'aria-live': 'off', tabindex: '0', 'aria-label': 'Log lines'}), status = h('span', {class: 'faint'});
    let sources = [], src = 'world', cursor = -1, lines = [], level = 'all', search = '', follow = true, paused = false, all = false, allCursors = {};
    const lvl = seg([{value: 'all', label: 'All'}, {value: 'warn', label: 'Warnings +'}, {value: 'error', label: 'Errors'}], 'all', v => { level = v; render(); }, {label: 'Level'});
    const q = h('input', {class: 'input', type: 'search', placeholder: 'Search lines', 'aria-label': 'Search log lines'}); q.addEventListener('input', () => { search = q.value.toLowerCase(); render(); });
    const followBtn = iconBtn('Follow new lines', 'chevronDown', () => { follow = !follow; followBtn.setAttribute('aria-pressed', String(follow)); if (follow) view.scrollTop = view.scrollHeight; }, {'aria-pressed': 'true'});
    const pauseBtn = iconBtn('Pause reading', 'pause', () => { paused = !paused; pauseBtn.setAttribute('aria-pressed', String(paused)); status.textContent = paused ? 'Paused' : ''; if (!paused) lp.now(); }, {'aria-pressed': 'false'});
    const allBtn = button('Errors in all logs', {kind: 'ghost', size: 'small', ico: 'alert', onClick: () => { all = !all; allBtn.setAttribute('aria-pressed', String(all)); lines = []; cursor = -1; allCursors = {}; render(); lp.now(); }}); allBtn.setAttribute('aria-pressed', 'false');
    const toolbar = h('div', {class: 'row wrap'}, lvl, h('div', {class: 'grow', style: null}, q), followBtn, pauseBtn, iconBtn('Jump to latest error', 'alert', () => { const e = [...view.querySelectorAll('.ln.error')].at(-1); if (e) { follow = false; followBtn.setAttribute('aria-pressed', 'false'); e.scrollIntoView({block: 'center'}); e.classList.add('hit'); setTimeout(() => e.classList.remove('hit'), 1500); } else toast('No error lines in view.', 'info'); }), iconBtn('Copy visible lines', 'copy', () => copyText(visible().map(l => l.text).join('\n'), 'Lines copied (already redacted).')), iconBtn('Open logs folder', 'folder', () => call('diag.openFolder', {which: 'logs'}).catch(e => toast(e.message, 'err'))), iconBtn('Clear view', 'trash', () => { lines = []; render(); }));
    p.append(h('div', {class: 'split'}, card({title: 'Live log reader', desc: 'Reads at most 64 KB per refresh from where it left off; pauses when hidden. All text is redacted.', children: [toolbar, view, h('div', {class: 'row between'}, status, allBtn)]}), card({title: 'Sources', children: [srcBox]})));
    view.addEventListener('scroll', () => { const atEnd = view.scrollHeight - view.scrollTop - view.clientHeight < 40; if (!atEnd && follow) { follow = false; followBtn.setAttribute('aria-pressed', 'false'); } });
    const visible = () => lines.filter(l => (level === 'all' || (level === 'error' ? l.level === 'error' : l.level !== 'info')) && (!search || l.text.toLowerCase().includes(search)));
    function render() {
      const vis = visible().slice(-3000); const frag = document.createDocumentFragment();
      vis.forEach((l, i) => { const ln = h('div', {class: ['ln', l.level !== 'info' && l.level]}, h('span', {class: 'lno', text: String(i + 1)}), all ? h('span', {class: 'faint', text: l.src}) : null); if (search) { const t = l.text, lo = t.toLowerCase(); let at = 0, k; while ((k = lo.indexOf(search, at)) >= 0) { ln.append(t.slice(at, k), h('mark', {text: t.slice(k, k + search.length)})); at = k + search.length; } ln.append(t.slice(at)); } else ln.append(l.text); frag.append(ln); });
      clear(view).append(vis.length ? frag : h('div', {class: 'ln faint', text: lines.length ? 'No line matches the filter.' : 'No lines yet.'}));
      if (follow) view.scrollTop = view.scrollHeight;
    }
    function renderSources() { replace(srcBox, ...sources.map(s => h('div', {class: ['r', 'clickable'], role: 'button', tabindex: '0', 'aria-pressed': String(s.id === src && !all), onClick: () => { src = s.id; all = false; allBtn.setAttribute('aria-pressed', 'false'); cursor = -1; lines = []; render(); renderSources(); lp.now(); }}, h('span', {class: ['event-dot', s.counts?.errors ? 'error' : s.exists ? 'ok' : '']}), h('div', {class: 'grow stack tight'}, h('strong', {text: s.label}), h('span', {class: 'faint wrap-any', text: s.exists ? `${f.bytes(s.size)} · ${f.ago(s.mtime)}${s.counts ? ` · ${s.counts.errors} errors · ${s.counts.warnings} warnings` : ''}` : 'not created yet'})), s.id === src && !all ? icon('check', 18) : null))); }
    const lp = poller(async signal => {
      if (paused) return;
      const r = await call('diag.sources', {}, {signal}); sources = r.sources.map(s => ({...s, counts: r.counts[s.id]})); renderSources();
      const before = lines.length;
      if (all) { for (const s of sources.filter(x => x.exists && x.id !== 'timeline')) { const t = await call('diag.tail', {source: s.id, cursor: allCursors[s.id] ?? -1, level: 'error'}, {signal}); allCursors[s.id] = t.cursor; lines.push(...t.lines.map(l => ({...l, src: s.label}))); } }
      else { const t = await call('diag.tail', {source: src, cursor}, {signal}); if (t.reset) lines.push({text: '— log was truncated or rotated; continuing from the end —', level: 'warn'}); cursor = t.cursor; lines.push(...t.lines); status.textContent = t.exists === false ? 'This log does not exist yet.' : `${f.bytes(t.size)} read to ${f.bytes(t.cursor)}${t.more ? ' (catching up)' : ''}`; if (t.more) setTimeout(() => lp.now(), 50); }
      if (lines.length > 6000) lines.splice(0, lines.length - 6000);
      if (lines.length !== before) render();
    }, {interval: 1000, active: () => active === 'logs', name: 'logs'});
    return {show() { lp.start(); }, hide() { lp.stop(); }};
  }

  // ---------- code & file finder
  function files() {
    const p = panels.files, results = h('div', {class: 'rows'}), viewer = h('div', {class: 'stack tight'}), stat = h('span', {class: 'faint'});
    const qi = h('input', {class: 'input', type: 'search', id: 'files', placeholder: 'Words to find in file names and contents', 'aria-label': 'Search code and files'});
    let mode = 'both', roots = {engine: true, preview: true, prepared: true}, exact = false, cs = false, ext = '', nm = false, sid = null;
    const modeSeg = seg([{value: 'both', label: 'Names + contents'}, {value: 'name', label: 'Names'}, {value: 'content', label: 'Contents'}], 'both', v => { mode = v; }, {label: 'Search in'});
    const chk = (label, key, obj) => { const id2 = 'fr-' + key; const i = h('input', {type: 'checkbox', id: id2, checked: obj ? obj[key] : false}); i.addEventListener('change', () => { if (obj) obj[key] = i.checked; else if (key === 'exact') exact = i.checked; else if (key === 'cs') cs = i.checked; else nm = i.checked; }); return h('label', {class: 'check', for: id2}, i, label); };
    const extIn = h('input', {class: 'input', placeholder: 'Type, e.g. mjs, dat', 'aria-label': 'File type filter', maxlength: '12'}); extIn.addEventListener('input', () => { ext = extIn.value.trim(); });
    const go = button('Search', {kind: 'primary', ico: 'search', onClick: () => run()}); qi.addEventListener('keydown', e => { if (e.key === 'Enter') run(); });
    p.append(card({title: 'Code & file finder', desc: state.mode === 'install' ? 'Read-only search of the engine, Command Center and prepared Global filenames. Account and secret files are excluded.' : 'Read-only. Searches the sandbox engine code, the preview\'s own code and the names of every prepared Global file. Files that can hold secrets (accounts, saved logins, tokens) are excluded.', children: [h('div', {class: 'input-row'}, qi, go), h('div', {class: 'row wrap'}, modeSeg, chk('Engine code', 'engine', roots), chk(state.mode === 'install' ? 'Command Center code' : 'Preview code', 'preview', roots), chk('Prepared data names', 'prepared', roots), chk('Exact phrase', 'exact'), chk('Match case', 'cs'), chk('Include node_modules', 'nm'), h('div', {class: 'row'}, extIn)), stat]}), h('div', {class: 'split'}, card({title: 'Viewer', children: [viewer]}), card({title: 'Results', children: [results]})));
    replace(viewer, empty('Open a result to see its text, or a hex view for binary files.'));
    async function run() {
      const query = qi.value.trim(); if (query.length < 2) { toast('Type at least 2 characters.', 'info'); return; }
      if (sid) call('find.cancel', {id: sid}).catch(() => {});
      replace(results, h('div', {class: 'row faint'}, h('span', {class: 'spinner'}), 'Searching…'));
      try { sid = (await call('find.start', {query, mode, roots: Object.keys(roots).filter(k => roots[k]), exact, caseSensitive: cs, ...(ext ? {ext} : {}), nodeModules: nm, limit: 1000})).id; const mine = sid;
        for (;;) { const r = await call('find.poll', {id: mine}); if (mine !== sid) return; stat.textContent = `${f.n(r.total)} result(s) · ${f.n(r.scanned)} files scanned · ${f.bytes(r.bytes)} read · ${f.ms(r.ms)}${r.done ? '' : ' · searching'}${r.error ? ' · ' + r.error : ''}`; renderResults(r.results); if (r.done) break; await new Promise(res => setTimeout(res, 200)); }
      } catch (e) { replace(results, notice('err', e.message)); }
    }
    function renderResults(rs) { replace(results, rs.length ? rs.slice(0, 500).map(r => h('div', {class: ['r', 'clickable'], role: 'button', tabindex: '0', onClick: () => open(r), onKeydown: e => { if (e.key === 'Enter') open(r); }}, icon(r.kind === 'content' ? 'search' : r.root === 'prepared' ? 'hex' : 'file', 18), h('div', {class: 'grow stack tight'}, h('strong', {class: 'wrap-any', text: r.rel + (r.line ? ':' + r.line : '')}), r.text ? h('span', {class: 'mono faint ellipsis', text: r.text}) : h('span', {class: 'faint', text: (r.root === 'prepared' ? 'Prepared data' : r.root === 'engine' ? 'Engine code' : 'Preview code') + (r.size ? ' · ' + f.bytes(r.size) : '')})))) : [empty('No matches.')]); }
    async function open(r, offset = 0, view = 'auto') {
      replace(viewer, h('div', {class: 'row faint'}, h('span', {class: 'spinner'}), 'Opening…'));
      try { const o = await call('find.open', {root: r.root, rel: r.rel, offset, view});
        const atMatch = r.offset !== undefined;
        const toHex = () => open(r, atMatch ? Math.max(0, Math.floor(r.offset / 16) * 16 - 64) : 0, 'hex');
        const head = h('div', {class: 'stack tight'}, h('div', {class: 'row wrap between'}, h('strong', {class: 'mono wrap-any', text: o.rel + (r.line ? `:${r.line}:${r.column || 1}` : '')}), h('div', {class: 'row'}, iconBtn('Copy path', 'copy', () => copyText(o.rel + (r.line ? ':' + r.line : ''))), button(o.binary ? 'Text view' : atMatch ? 'Bytes at match' : 'Hex view', {size: 'small', kind: 'ghost', ico: 'hex', onClick: () => o.binary ? open(r, 0, 'text') : toHex()}))),
          atMatch ? h('span', {class: 'faint', text: `Match at line ${r.line}, column ${r.column || 1} · byte offset ${f.n(r.offset)} (0x${r.offset.toString(16)})`}) : null, h('div', {class: 'row wrap'}, pill(o.binary ? (o.textFile ? 'Text file · bytes' : 'Binary') : 'Text', o.binary && !o.textFile ? 'warn' : 'info'), pill(f.bytes(o.size), ''), pill('Read only', 'ok'), h('span', {class: 'faint', text: `modified ${f.dateTime(o.modified)}`})), h('div', {class: 'row wrap', id: 'sha-row'}, o.sha256 ? h('span', {class: 'mono faint wrap-any', text: 'SHA-256 ' + o.sha256}) : button('Compute SHA-256', {size: 'small', onClick: async () => { const x = await call('find.hash', {root: r.root, rel: r.rel}); document.getElementById('sha-row').replaceChildren(h('span', {class: 'mono faint wrap-any', text: `SHA-256 ${x.sha256} (${x.source})`})); }})));
        let body;
        if (o.binary) {
          // Highlight the matched bytes (when opened from a content hit) so the text match and its binary line up.
          const from = atMatch ? r.offset : -1, to = atMatch ? r.offset + (r.matchBytes || 1) : -1;
          const bytes = (row, field) => { const parts = field === 'hex' ? row.hex.split(' ') : [...row.ascii]; return parts.map((b, i) => { const at = row.offset + i; return at >= from && at < to ? h('mark', {text: b}) : b; }).flatMap((x, i, a) => field === 'hex' && i < a.length - 1 ? [x, ' '] : [x]); };
          let marked = false;
          body = h('div', {class: 'hex', role: 'region', 'aria-label': 'Hex view', tabindex: '0'}, o.rows.map(row => { const hitRow = row.offset + 16 > from && row.offset < to; const first = hitRow && !marked; if (first) marked = true; return h('div', {class: ['hr', hitRow && 'hit'], id: first ? 'hit-line' : undefined}, h('span', {class: 'off', text: row.offset.toString(16).padStart(8, '0')}), h('span', {}, hitRow ? bytes(row, 'hex') : row.hex), h('span', {class: 'asc'}, hitRow ? bytes(row, 'asc') : row.ascii)); }));
        }
        else { const ls = o.text.split(/\r?\n/); body = h('div', {class: 'code-view', role: 'region', 'aria-label': 'File text', tabindex: '0'}, ls.map((t, i) => h('div', {class: ['ln', r.line === i + 1 && 'hit'], id: r.line === i + 1 ? 'hit-line' : undefined}, h('span', {class: 'lno', text: String(i + 1)}), t))); }
        const pager = h('div', {class: 'row between'}, h('span', {class: 'faint', text: `bytes ${f.n(o.offset)}–${f.n(o.offset + o.length)} of ${f.n(o.size)}`}), h('div', {class: 'row'}, button('Previous', {size: 'small', disabled: o.offset === 0, onClick: () => open(r, Math.max(0, o.offset - o.length), o.binary ? 'hex' : 'text')}), button('Next', {size: 'small', disabled: o.offset + o.length >= o.size, onClick: () => open(r, o.offset + o.length, o.binary ? 'hex' : 'text')})));
        replace(viewer, head, body, pager); document.getElementById('hit-line')?.scrollIntoView({block: 'center'});
      } catch (e) { replace(viewer, notice('err', e.message)); }
    }
    return {show() { qi.focus(); }, open};
  }

  // ---------- timeline
  function timeline() {
    const p = panels.timeline, list = h('div', {class: 'rows', id: 'timeline'});
    let area = '', lv = '', q = '';
    const areaSel = h('select', {class: 'input', 'aria-label': 'Area'}, [['', 'All areas'], ...['app', 'world', 'play', 'host', 'sql', 'content', 'update', 'diag'].map(a => [a, a])].map(([v, l]) => h('option', {value: v, text: l})));
    const lvSel = h('select', {class: 'input', 'aria-label': 'Level'}, [['', 'All levels'], ['error', 'Errors'], ['warn', 'Warnings'], ['ok', 'Done'], ['info', 'Info']].map(([v, l]) => h('option', {value: v, text: l})));
    const qIn = h('input', {class: 'input', type: 'search', placeholder: 'Search events', 'aria-label': 'Search events'});
    areaSel.addEventListener('change', () => { area = areaSel.value; tp.now(); }); lvSel.addEventListener('change', () => { lv = lvSel.value; tp.now(); }); qIn.addEventListener('input', () => { q = qIn.value.toLowerCase(); tp.now(); });
    p.append(card({title: 'Event timeline', desc: 'What the launcher and the world actually did, newest first. Stored redacted in the launcher profile.', children: [h('div', {class: 'row wrap'}, areaSel, lvSel, h('div', {class: 'grow'}, qIn)), list]}));
    const tp = poller(async signal => { const r = await call('diag.timeline', {limit: 500, ...(area ? {area} : {}), ...(lv ? {level: lv} : {})}, {signal}); const ev = r.events.filter(e => !q || (e.message + ' ' + (e.detail || '')).toLowerCase().includes(q)).reverse(); replace(list, ev.length ? ev.slice(0, 300).map(e => h('div', {class: 'r'}, h('span', {class: ['event-dot', e.level === 'ok' ? 'ok' : e.level]}), h('div', {class: 'grow stack tight'}, h('span', {class: 'wrap-any', text: e.message}), e.detail ? h('span', {class: 'mono faint wrap-any', text: e.detail}) : null), h('span', {class: 'faint num', text: `${e.area} · ${f.time(e.at)}`}))) : [empty('No events match.')]); return r; }, {interval: 3000, active: () => active === 'timeline', name: 'timeline'});
    return {show() { tp.start(); }, hide() { tp.stop(); }};
  }

  // ---------- performance
  function performance() {
    const p = panels.performance, body = h('div', {class: 'stack', id: 'perf'});
    p.append(card({title: 'Measured performance', desc: 'Real measurements with units and times. Nothing is estimated or animated.', actions: [button('Refresh', {size: 'small', ico: 'refresh', onClick: () => load()})], children: [body]}));
    async function load() {
      try { const [d, perf] = await Promise.all([call('diag.dev'), call('diag.perf')]);
        const by = {}; for (const m of perf.ui) (by[m.name] ||= []).push(m);
        const stat2 = arr => { const v = arr.map(x => x.ms).sort((a, b) => a - b); return {n: v.length, p50: v[Math.floor(v.length / 2)], p95: v[Math.min(v.length - 1, Math.floor(v.length * .95))], max: v.at(-1)}; };
        replace(body, kv([['Window start', d.shell ? `backend ready ${f.ms(d.shell.backendReadyMs)} · view ready ${f.ms(d.shell.webviewReadyMs)} · first page ${f.ms(d.shell.firstNavigationMs)} (since the window process started)` : 'headless (no window)'], ['Backend', `${d.backend.cpuPercent ?? '—'} % CPU · ${d.backend.rssMB} MB RSS · event loop p99 ${d.backend.loopDelayMs.p99} ms · up ${f.duration(d.backend.uptimeS * 1000)}`], ['Bridge', d.bridge ? `${f.n(d.bridge.apiCalls)} calls · slowest ${f.ms(d.bridge.slowest)} · ${f.n(d.bridge.rejected)} rejected` : '—']]),
          table({caption: 'Interface timings', columns: [{key: 'name', label: 'Measurement'}, {key: 'n', label: 'Samples', num: true}, {key: 'p50', label: 'Median', num: true, render: x => f.ms(x.p50)}, {key: 'p95', label: 'p95', num: true, render: x => f.ms(x.p95)}, {key: 'max', label: 'Max', num: true, render: x => f.ms(x.max)}], rows: Object.entries(by).map(([name, arr]) => ({name: {'first-render': 'Launcher first render', 'page-open': 'Open a page (first time)', 'page-switch': 'Switch to an open page'}[name] || name, ...stat2(arr)})), empty: 'No interface measurements yet.'}),
          table({caption: 'Slowest operations', tall: true, columns: [{key: 'method', label: 'Operation', mono: true}, {key: 'n', label: 'Calls', num: true}, {key: 'avgMs', label: 'Average', num: true, render: x => f.ms(x.avgMs)}, {key: 'maxMs', label: 'Max', num: true, render: x => f.ms(x.maxMs)}], rows: Object.entries(d.bridge?.byMethod || {}).map(([method, m]) => ({method, ...m})).sort((a, b) => b.maxMs - a.maxMs).slice(0, 25)}),
          h('p', {class: 'faint', text: `Measured ${f.time(d.backend.at)}. World CPU, memory and request latency are on Server › Overview; SQL monitor cost is shown on SQL & Storage › Monitor.`}));
      } catch (e) { replace(body, notice('err', e.message)); }
    }
    return {show() { load(); }};
  }
  return {el, show(tab) { bar.show(tab); }, hide() { for (const b of Object.values(built)) b.hide?.(); }};
}
