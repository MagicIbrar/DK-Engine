import {playersPage,renameControls} from './players.js';
import {inventoryPage} from './inventory-viewer.js';
import {gearBuilder} from './gear-builder.js';
import { embeddedModelPreview } from './model-preview.js';
// The GM panel's tab bodies (panel.js hosts them). Every action goes through the same command runner as the chat box
// and the console (game.gm.run('/gm ...')), so the panel, the chat and the console always behave the same; the forms
// only build the command lines. Lists are the builder's data (gamedata/gmcommands*.json, docs/formats/gmcommands.md).
import { gmData, GMData, GM_ONLY_NPCS } from './data.js';
import { h, btn, toggleBtn, input, select, check, vlist, picker, minimapPicker, table } from './kit.js';
import { dropTable, whoDrops, simulate, pct } from './drops.js';
import { describeItem, makeItem, editItem, ownedItems, GRADES, optionCode } from './itemgen.js';
import { WEATHER_NAMES } from './commands.js';
import { openBuilder } from './builders.js';
import {commandSupport,applyCommandSupport} from './online-support.js';

const fmt = n => Number(n || 0).toLocaleString('en-US');
const nz = (v, d = 0) => { const x = Number(v); return Number.isFinite(x) ? x : d; };
const qv = (s) => { const t = String(s ?? '').trim(); return /\s/.test(t) ? `"${t.replace(/"/g, "'")}"` : t; };
const row = (label, ...els) => h('div.row', null, label != null ? h('span.lbl', null, label) : null, ...els);
const numIn = (v = '', w = 64, attrs = {}) => { const e = input('number', v, attrs); e.style.width = `${w}px`; return e; };
const txtIn = (v = '', w = 160, attrs = {}) => { const e = input('text', v, { spellcheck: false, ...attrs }); e.style.width = `${w}px`; return e; };
const sect = (title, ...kids) => h('div', null, h('h4', null, title), ...kids);
const supportId=id=>gmData.command(id)?.id||id;
const supportedButton=(ctx,id,text,action,opts={})=>{
  const canonical=supportId(id),button=btn(text,()=>{const state=commandSupport(ctx.game,canonical,opts.args);if(!state.enabled){ctx.status(state.reason,'ffff5a45');return;}return action();},opts);
  const state=applyCommandSupport(button,ctx.game,canonical,opts.args);
  return state.enabled?button:h('span',{style:{display:'inline-flex',flexDirection:'column',maxWidth:'300px'}},button,h('span.tip',{style:{whiteSpace:'normal'}},state.reason));
};
const supportSection=(ctx,id,title,...kids)=>{
  const section=sect(title,...kids),state=commandSupport(ctx.game,supportId(id));
  if(!state.enabled){for(const control of section.querySelectorAll('button,input,select,textarea'))applyCommandSupport(control,ctx.game,supportId(id));section.appendChild(h('div.tip',{style:{whiteSpace:'normal'}},state.reason));}
  else if(state.reason)section.appendChild(h('div.tip',{style:{whiteSpace:'normal'}},state.reason));
  return section;
};
const supportedToggle=(ctx,id,text,get,set,opts={})=>{
  const button=toggleBtn(text,get,v=>{const state=commandSupport(ctx.game,supportId(id));if(state.enabled)return set(v);ctx.status(state.reason,'ffff5a45');},opts);
  const state=applyCommandSupport(button,ctx.game,supportId(id));return state.enabled?button:h('span',{title:state.reason,style:{display:'inline-flex',flexDirection:'column',maxWidth:'230px'}},button,h('span.tip',{style:{whiteSpace:'normal'}},state.reason));
};
const tag = (text, onClick, title) => { const t = h('span.tag', { title: title || null, style: onClick ? { cursor: 'pointer' } : null }, text); if (onClick) t.addEventListener('click', onClick); return t; };
const split = (leftW, left, right) => {
  const r = h('div.scroll', { style: { flex: '1 1 auto', height: '100%', paddingRight: '4px', minWidth: 0 } }, right);
  return { el: h('div', { style: { display: 'flex', gap: '8px', height: '100%' } }, h('div.col', { style: { width: `${leftW}px`, flex: 'none', height: '100%' } }, left), r), right: r };
};
const clear = (el) => { while (el.firstChild) el.firstChild.remove(); return el; };
const debounce = (fn, ms = 140) => { let t = 0; return (...a) => { clearTimeout(t); t = setTimeout(() => fn(...a), ms); }; };
const here = g => ({ map: g.world?.info?.index, x: g.player?.x ?? 0, z: g.player?.z ?? 0 });

/**
 * A searchable list over a GM list. opts: {list | rows(), cols, height, filter(row), onSelect, extra (elements beside
 * the search), limit}. Returns {el, vl, input, refresh(), rows}.
 */
function searchList(opts) {
  const inp = txtIn('', 170, { placeholder: 'search (name or index)…' });
  const count = h('span.dim');
  const vl = vlist({ height: opts.height || 440, cols: opts.cols, onSelect: opts.onSelect, onDbl: opts.onDbl });
  const api = { vl, input: inp, rows: null };
  const refresh = async () => {
    api.rows = api.rows || (opts.rows ? await opts.rows() : await gmData.list(opts.list));
    const res = GMData.search(api.rows, inp.value, opts.limit || 100000, opts.filter ? (r => opts.filter(r)) : null);
    vl.setRows(res);
    count.textContent = `${fmt(res.length)} / ${fmt(api.rows.length)}`;
  };
  inp.addEventListener('input', debounce(refresh));
  inp.addEventListener('keydown', (e) => { if (e.key === 'Enter' && vl.rows[0]) { vl.select(vl.rows[0]); opts.onSelect?.(vl.rows[0]); } });
  api.refresh = refresh;
  api.reload = () => { api.rows = null; return refresh(); };
  api.el = h('div.col', null, h('div.row', null, inp, count), opts.extra ? h('div.row', null, ...[opts.extra].flat()) : null, vl.el);
  return api;
}

// ======================================================================================================== commands
function commandsPage(ctx) {
  const { gm,game } = ctx;
  const cats = new Set();
  const rows = () => {
    const seen = new Set(), out = [];
    for (const c of [...gmData.commands, ...gmData.extra.values()]) {
      if (!c || seen.has(c.id)) continue;
      seen.add(c.id); cats.add(c.category);
      out.push({ id: c.id, name: c.id, sub: `${c.category} · ${c.origin}`, cmd: c,
        search: `${c.id} ${c.category} ${c.origin} ${c.syntax} ${(c.aliases || []).join(' ')} ${c.desc || ''}`.toLowerCase() });
    }
    return out;
  };
  const catSel = select([['', 'all categories']], '', () => list.refresh());
  const list = searchList({
    rows: async () => { const r = rows(); for (const c of cats) catSel.appendChild(h('option', { value: c }, c)); return r; },
    height: 452,
    cols: [{ key: 'name', width: 'grow' }, { get: r => r.cmd.category, width: 64, cls: 'dim' }, { get: r => r.cmd.origin, width: 96, cls: 'dim' }],
    filter: r => !catSel.value || r.cmd.category === catSel.value,
    extra: catSel,
    onSelect: r => showCmd(r.cmd),
  });
  const right = h('div');
  const sp = split(300, list.el, right);

  function head(cmd) {
    const m = /^\/gm\s+(\S+)/.exec(cmd.syntax || '');
    return `/gm ${m ? m[1] : cmd.id}`;
  }
  function showCmd(cmd) {
    clear(right);
    right.appendChild(h('h4', null, cmd.syntax));
    if (cmd.aliases?.length) right.appendChild(h('div.dim', null, `aliases: ${cmd.aliases.join(', ')}`));
    if (cmd.desc) right.appendChild(h('div', { style: { margin: '4px 0', whiteSpace: 'normal' } }, cmd.desc));
    const meta = [`id ${cmd.id}`, `category ${cmd.category}`, `origin ${cmd.origin}`];
    if (cmd.privilege) meta.push(`privilege ${cmd.privilege}`);
    if (cmd.confidence) meta.push(`confidence ${cmd.confidence}`);
    if (cmd.multiplayerOnly) meta.push('multiplayer only in the original');
    right.appendChild(h('div.dim', null, meta.join(' · ')));
    if (cmd.evidence?.length) right.appendChild(h('div.tip', { style: { whiteSpace: 'normal', margin: '3px 0' } }, `evidence: ${cmd.evidence.map(e => `${e.kind} ${e.ref}${e.ok === false ? ' (!)' : ''}`).join(' · ')}`));
    // the form
    const vals = {};
    const form = h('div.grid2', { style: { marginTop: '8px' } });
    const preview = h('div.out', { style: { margin: '8px 0', padding: '4px 6px', background: 'rgba(0,0,0,.4)', border: '1px solid #5a4a2a' } });
    const availability=h('div.tip',{style:{whiteSpace:'normal'}});
    const runButton=btn('Run',()=>{if(!commandSupport(game,cmd.id,vals).enabled)return;return gm.run(build(),{source:'panel'});},{big:true});
    const build = () => {
      const parts = [head(cmd)];
      const args = cmd.args || [];
      let lastFilled = -1;
      args.forEach((a, i) => { const v = vals[a.name]; if (v != null && v !== '' && !(Array.isArray(v) && !v.length)) lastFilled = i; });
      args.forEach((a, i) => {
        let v = vals[a.name];
        const empty = v == null || v === '' || (Array.isArray(v) && !v.length);
        if (empty) {
          if (i > lastFilled) return;
          v = a.default ?? (a.enum ? a.enum[0] : (a.type === 'int' || a.type === 'float' || a.type === 'cell') ? (a.min ?? 1) : '');
          if (v === '') return;
        }
        if (Array.isArray(v)) { for (const [r, x] of v) parts.push(String(r.id), String(x)); return; }
        if (v && typeof v === 'object') { parts.push(`${v._prefix || ''}${v.id}`); return; }
        const lastText = a.type === 'text' && !args.slice(i + 1).some(x => !x.optional);
        parts.push(lastText ? String(v) : qv(v));
      });
      return parts.join(' ');
    };
    const upd = () => { preview.textContent = build();const state=applyCommandSupport(runButton,game,cmd.id,vals);availability.textContent=state.reason||(game.save.authority==='server'?state.kind==='server'?'Runs on the shared server.':'Local inspection tool.':''); };
    for (const a of cmd.args || []) {
      form.appendChild(h('span.lbl', { title: a.desc || '' }, `${a.name}${a.optional ? '' : ' *'}`));
      form.appendChild(argControl(a, (v) => { vals[a.name] = v; upd(); }));
    }
    if (!(cmd.args || []).length) form.appendChild(h('span.dim', null, 'no arguments'));
    right.appendChild(form);
    right.appendChild(preview);
    right.appendChild(availability);
    right.appendChild(h('div.row', null,
      runButton,
      btn('To console', () => { gm.toggleConsole(); setTimeout(() => { const ed = gm.windows.cwin?.control('edit_command'); ed?.setValue?.(build()); ed?.focus?.(); }, 80); }),
      btn('Help', () => gm.run(`/gm help ${cmd.id}`, { source: 'panel' }))));
    upd();
  }

  function argControl(a, set) {
    if (a.type === 'enum') {
      const s = select([['', a.optional ? '(default)' : '(choose)'], ...(a.enum || [])], '', v => set(v));
      return s;
    }
    const lists = a.list ? (Array.isArray(a.list) ? a.list : String(a.list).split(',')) : null;
    if (lists && a.repeat) {
      // repeated [option value] pairs (makeitem)
      const box = h('div.col');
      const pairs = [];
      const addRow = () => {
        if (pairs.length >= a.repeat) return;
        const e = { row: null, v: numIn('', 60) };
        const pk = picker({ list: lists[0], data: gmData, width: 230, onPick: r => { e.row = r; e.v.placeholder = `${r.raw?.min ?? ''}~${r.raw?.max ?? ''}`; if (e.v.value === '') e.v.value = r.raw?.max ?? 1; emit(); } });
        e.v.addEventListener('input', emit);
        pairs.push(e);
        box.insertBefore(h('div.row', null, pk.el, e.v), addB);
      };
      const emit = () => set(pairs.filter(p => p.row).map(p => [p.row, nz(p.v.value, 1)]));
      const addB = btn('+ option', addRow);
      box.appendChild(addB);
      return box;
    }
    if (lists) {
      const wrap = h('div.row');
      let which = lists[0];
      const mk = () => picker({ list: which, data: gmData, width: 300, onPick: r => set(lists.length > 1 ? { ...r, _prefix: which === 'items' ? 'i:' : 'm:' } : r) });
      let pk = mk();
      if (lists.length > 1) {
        const s = select(lists, which, v => { which = v; const n = mk(); pk.el.replaceWith(n.el); pk = n; set(null); });
        wrap.appendChild(s);
      }
      wrap.appendChild(pk.el);
      return wrap;
    }
    if (a.type === 'int' || a.type === 'float' || a.type === 'cell') {
      const e = numIn(a.default ?? '', 90, { min: a.min ?? null, max: a.max ?? null, step: a.type === 'float' ? 'any' : '1', placeholder: a.min != null ? `${a.min}..${a.max ?? ''}` : '' });
      e.addEventListener('input', () => set(e.value));
      if (a.default != null) set(String(a.default));
      return e;
    }
    if (a.type === 'bool') return select([['', '(default)'], 'on', 'off'], '', v => set(v));
    const e = txtIn('', a.type === 'text' ? 360 : 160, { placeholder: a.desc || a.type });
    e.addEventListener('input', () => set(e.value));
    return e;
  }

  return { el: sp.el, onShow(arg) { if (!list.rows) list.refresh(); if (arg?.command) { const c = gmData.command(arg.command) || gmData.extra.get(arg.command); if (c) showCmd(c); } } };
}

// ======================================================================================================== monsters
function monstersPage(ctx) {
  const { gm, game } = ctx;
  const st = { onMap: false, sel: null };
  const roleSel = select([['', 'all roles']], '', () => list.refresh());
  const onMap = check('this map', () => st.onMap, v => { st.onMap = v; list.refresh(); });
  const list = searchList({
    list: 'monsters', height: 430,
    rows: async () => {
      const r = await gmData.list('monsters');
      const roles = [...new Set(r.map(x => x.raw.role).filter(Boolean))].sort();
      for (const x of roles) roleSel.appendChild(h('option', { value: x }, x));
      return r;
    },
    cols: [{ key: 'id', width: 46, cls: 'dim' }, { key: 'name', width: 'grow' }, { get: r => r.raw.level, width: 32 }, { get: r => fmt(r.raw.hp), width: 70, cls: 'dim' }, { get: r => (r.raw.drops || []).length, width: 30, cls: 'dim' }],
    filter: r => (!roleSel.value || r.raw.role === roleSel.value) && (!st.onMap || (r.raw.spawnMaps || []).includes(here(game).map) || (r.raw.callMaps || []).includes(here(game).map)),
    extra: [roleSel, onMap],
    onSelect: r => showMon(r),
  });
  const right = h('div',null,h('h4',null,'Choose a monster to edit its HP, attack and drops.'));
  const sp = split(400, list.el, right);

  async function showMon(r) {
    st.sel = r;
    clear(right);
    const m = r.raw;
    right.appendChild(h('h4', null, `${r.name}  #${r.id}`));
    embeddedModelPreview(ctx, right, 'monster', r.id);
    right.appendChild(h('div', null, `Lv ${m.level} · HP ${fmt(m.hp)} · EXP ${fmt(m.exp)} · rank ${m.rank ?? '-'} · ${m.role || 'creature'} · ${m.aggressive ? 'aggressive' : 'passive'}${m.nameKr ? ` · ${m.nameKr}` : ''}`));
    const def = game.data?.monster?.(r.id);
    if (def) right.appendChild(h('div.dim', null, `speed walk ${def.speed?.[0] ?? def.walkSpeed ?? '-'} run ${def.speed?.[1] ?? def.runSpeed ?? '-'} · sight ${def.sight ?? def.sightRange ?? '-'} · model ${def.model || def.shape || def.skel || '-'}`));
    const maps = h('div.row', null, h('span.lbl', null, 'spawns on'), ...(m.spawnMaps || []).slice(0, 30).map(x => tag(`map ${x}`, () => ctx.run(`/gm move ${x}`), 'go to this map')));
    if (!(m.spawnMaps || []).length) maps.appendChild(h('span.dim', null, 'no field spawn (called by scripts / dungeons)'));
    right.appendChild(maps);
    if ((m.callMaps || []).length) right.appendChild(h('div.row', null, h('span.lbl', null, 'called on'), ...m.callMaps.slice(0, 30).map(x => tag(`map ${x}`, () => ctx.run(`/gm move ${x}`)))));
    // call
    const cnt = numIn(1, 50, { min: 1, max: 200 });
    const cx = numIn('', 60, { placeholder: 'x' }), cz = numIn('', 60, { placeholder: 'z' });
    right.appendChild(sect('Call (/gm callmonster)',
      row('count', cnt, btn('Call here', () => ctx.run(`/gm callmonster ${r.id} ${nz(cnt.value, 1)}`), { big: true }),
        h('span.dim', null, 'at'), cx, cz, btn('Call at', () => ctx.run(`/gm callmonster ${r.id} ${nz(cnt.value, 1)} ${nz(cx.value)} ${nz(cz.value)}`))),
      row(null, btn('Kill all', () => ctx.run('/gm killall')), toggleBtn('Freeze', () => gm.st.freeze, v => ctx.run(`/gm freeze ${v ? 'on' : 'off'}`)),
        btn('Respawn map', () => ctx.run('/gm respawn')), btn('Model viewer', () => ctx.run(`/gm viewer monster ${r.id}`)),
        btn('Target → inspect', () => ctx.run('/gm inspect')))));
    // Runtime monster tools are available through chat, but they also need
    // direct controls on the monster page so a GM can discover and use them.
    const stat = select([['hp','Max HP'],['attack','Attack damage'],['drop','Item drop chance']], 'hp');
    const factor = numIn(1, 70, {min:0.1,max:10,step:0.1});
    const itemId = numIn('', 90, {min:1,step:1,placeholder:'item ID'});
    const chance = numIn(10000, 90, {min:0,max:100000,step:1});
    const count = numIn(1, 55, {min:1,max:99,step:1});
    const validFactor = () => Number.isFinite(Number(factor.value))&&Number(factor.value)>=0.1&&Number(factor.value)<=10;
    const validLoot = () => Number.isSafeInteger(Number(itemId.value))&&Number(itemId.value)>0&&
      Number.isSafeInteger(Number(chance.value))&&Number(chance.value)>=0&&Number(chance.value)<=100000&&
      Number.isSafeInteger(Number(count.value))&&Number(count.value)>=1&&Number(count.value)<=99;
    right.appendChild(sect('Monster HP, attack and drops (this server run)',
      row('Stat', stat, h('span.lbl',null,'Multiplier'), factor,
        supportedButton(ctx,'monstertune','Apply',()=>{
          if(!validFactor())return ctx.status('Enter a multiplier from 0.1 to 10.','ffff5a45');
          return ctx.run(`/gm monstertune ${r.id} ${stat.value} ${factor.value}`);
        }),
        supportedButton(ctx,'monstertune','Restore',()=>ctx.run(`/gm monstertune ${r.id} ${stat.value} 1`))),
      h('div.tip',null,`Original ${r.name} HP: ${fmt(m.hp)}. Multiplier 1 restores the original stat.`),
      row('Item ID', itemId, h('span.lbl',null,'Chance / 100000'), chance,
        h('span.lbl',null,'Count'), count,
        supportedButton(ctx,'monsterloot','Set drop',()=>{
          if(!validLoot())return ctx.status('Enter a valid item ID, chance 0–100000, and count 1–99.','ffff5a45');
          return ctx.run(`/gm monsterloot ${r.id} ${itemId.value} ${chance.value} ${count.value}`);
        }),
        supportedButton(ctx,'monsterloot','Remove drop',()=>{
          if(!Number.isSafeInteger(Number(itemId.value))||Number(itemId.value)<1)return ctx.status('Enter the item ID to remove.','ffff5a45');
          return ctx.run(`/gm monsterloot ${r.id} ${itemId.value} 0`);
        })),
      h('div.tip',null,'These changes take effect immediately on the shared server and clear when it restarts.')));
    // drops
    const mapSel = select([['cur', `current map (${here(game).map})`], ['none', 'own table only'], ...(m.spawnMaps || []).map(x => [String(x), `map ${x}`])], 'cur', () => drawDrops());
    const clsSel = select((game.data?.classes || []).map((c, i) => [String(c.index ?? i), c.name || `class ${i}`]), String(game.save.classIndex ?? 0), () => drawDrops());
    const dropBox = h('div');
    right.appendChild(sect('Drops (per kill, before rate events)', row('map layer', mapSel, h('span.lbl', null, 'killer class'), clsSel), dropBox));
    async function drawDrops() {
      clear(dropBox).appendChild(h('div.dim', null, 'loading…'));
      const map = mapSel.value === 'cur' ? here(game).map : mapSel.value === 'none' ? null : Number(mapSel.value);
      const t = await dropTable(r.id, { map, classIndex: Number(clsSel.value), playerLevel: game.save.level });
      clear(dropBox);
      if (!t) { dropBox.appendChild(h('div.bad', null, 'no drop data')); return; }
      for (const n of t.notes) dropBox.appendChild(h('div.dim', null, n));
      for (const mo of t.money) dropBox.appendChild(h('div.gold', null, `DIL ${fmt(mo.min)} - ${fmt(mo.max)}${mo.count ? ` (x${mo.count[0]}-${mo.count[1]})` : ''}: ${pct(mo.p)} [${mo.layer}]`));
      const tb = table(['item', 'chance', 'stack', 'layer'], t.items.slice(0, 400).map(it => {
        const n = h('span', { style: { cursor: 'pointer', color: '#9fd2ff' }, title: 'open in the item spawner' }, `${it.name} (${it.item})`);
        n.addEventListener('click', () => ctx.show('items', { item: it.item }));
        return [n, pct(it.p), it.min != null ? `${it.min}-${it.max}` : '', it.layers.join('+')];
      }));
      dropBox.appendChild(h('div.dim', null, `${t.items.length} item(s)${t.items.length > 400 ? ' (first 400 shown)' : ''}`));
      dropBox.appendChild(tb);
    }
    drawDrops();
    // simulate
    const kills = numIn(1000, 70, { min: 1, max: 100000 });
    const simBox = h('div');
    right.appendChild(sect('Simulate kills (the loot roller of real kills)', row('kills', kills, btn('Simulate', async () => {
      clear(simBox).appendChild(h('div.dim', null, 'rolling…'));
      const s = await simulate(game, r.id, nz(kills.value, 1000));
      clear(simBox);
      if (!s) { simBox.appendChild(h('div.bad', null, 'no monster record')); return; }
      simBox.appendChild(h('div.gold', null, `${fmt(s.kills)} kills on map ${s.map}: ${fmt(s.dil)} DIL · ${s.items.length} kinds`));
      simBox.appendChild(table(['item', 'drops', 'count', 'per kill'], s.items.slice(0, 200).map(i => [`${i.name} (${i.item})`, fmt(i.drops), fmt(i.count), pct(i.drops / s.kills)])));
    })), simBox));
  }

  return { el: sp.el, onShow(arg) { if (!list.rows) list.refresh(); if (arg?.monster != null) gmData.get('monsters', arg.monster).then(r => { if (r) { list.vl.select(r); showMon(r); } }); } };
}

// ======================================================================================================== items
function itemsPage(ctx) {
  const { gm, game } = ctx;
  const tblSel = select([['', 'all tables'], 'weapon', 'armor', 'accessory', 'etc', 'socket', 'cash', 'mileage', 'accessoryEvent', 'cashEvent', 'etcEvent'], '', () => list.refresh());
  const list = searchList({
    list: 'items', height: 430,
    cols: [{ key: 'id', width: 58, cls: 'dim' }, { key: 'name', width: 'grow' }, { get: r => r.raw.table, width: 62, cls: 'dim' }, { get: r => r.raw.reqLv, width: 28 }],
    filter: r => !tblSel.value || r.raw.table === tblSel.value,
    extra: tblSel,
    onSelect: r => showItem(r.id),
  });
  const right = h('div');
  const sp = split(380, list.el, right);
  const F = { grade: 'normal', upgrade: null, sockets: 0, stones: [0, 0, 0, 0], options: [], count: 1, to: 'bag', bound: false, roll: true, free: false };
  let selection = 0;

  async function showItem(index) {
    const request = ++selection;
    const d = await describeItem(game, index);
    if (request !== selection) return;
    clear(right);
    const icon = h('div', { style: { width: '64px', height: '64px', flex: 'none', background: 'rgba(0,0,0,.5) no-repeat center/contain', border: '1px solid #5a4a2a' } });
    game.items?.icon?.(d.index, 64, 64)?.then?.(v => { if (v?.url) icon.style.backgroundImage = `url("${v.url}")`; });
    const r = d.row?.raw || {};
    embeddedModelPreview(ctx, right, 'item', d.index);
    right.appendChild(h('div', { style: { display: 'flex', gap: '8px' } }, icon, h('div.col', { style: { gap: '1px' } },
      h('div', { style: { color: '#ffe38c', fontWeight: 'bold' } }, `${d.name}  #${d.index}`),
      h('div', null, `${r.table || d.kind || ''}${d.kind ? ` · ${d.kind}` : ''}${d.rankName ? ` · ${d.rankName}` : ''} · req Lv ${d.reqLv ?? '-'} · ${d.w}x${d.h} cells · stack ${d.stack}`),
      h('div.dim', null, `type ${r.type ?? d.def?.type} / code ${r.code ?? d.def?.code} · price ${fmt(r.price ?? d.def?.price)} · job ${r.job || '-'}${d.chain.length > 1 ? ` · upgrade chain +${d.chain[0].lv}..+${d.maxUpgrade}` : ''}`),
      d.loadable ? null : h('div.bad', null, 'Not in the item tables the game loads (csv-only row): cannot be created.'))));
    // generator
    F.upgrade = d.level; F.options = []; F.stones = [0, 0, 0, 0];
    const gradeSel = select(GRADES, F.grade, v => { F.grade = v; });
    const upSel = select(d.chain.length ? d.chain.map(c => [String(c.lv), `+${c.lv} ${c.name}`]) : [[String(d.level), `+${d.level}`]], String(d.level), v => { F.upgrade = Number(v); });
    if (d.chain.length <= 1) upSel.disabled = true;
    const cnt = numIn(1, 70, { min: 1, max: 100000 }); cnt.addEventListener('input', () => { F.count = nz(cnt.value, 1); });
    F.count = 1;
    const sockSel = select([0, 1, 2, 3, 4].map(n => [String(n), `${n} socket(s)`]), String(F.sockets), v => { F.sockets = Number(v); paintStones(); });
    const stoneRow = h('div.col');
    const paintStones = () => {
      clear(stoneRow);
      for (let i = 0; i < F.sockets; i++) {
        const pk = picker({ list: 'sockets', data: gmData, width: 260, placeholder: `socket ${i + 1}: empty (type to insert a stone)…`, onPick: s => { F.stones[i] = Number(s.id); } });
        if (F.stones[i]) gmData.get('sockets', F.stones[i]).then(s => s && pk.set(s));
        stoneRow.appendChild(h('div.row', null, h('span.dim', null, `#${i + 1}`), pk.el, btn('empty', () => { F.stones[i] = 0; pk.clear(); })));
      }
    };
    paintStones();
    const optBox = h('div.col');
    const table_ = d.table;
    const addOpt = () => {
      if (F.options.length >= 6) return;
      const o = { row: null, v: numIn('', 54), mm: h('span.dim', { style: { minWidth: '44px' } }) };
      const pk = picker({ list: 'itemOptions', data: gmData, width: 230, placeholder: `option (${table_ || 'any table'})…`, filter: table_ ? (x => x.raw.table === table_) : null,
        onPick: x => { o.row = x; o.mm.textContent = `${x.raw.min} ~ ${x.raw.max}`; if (o.v.value === '') o.v.value = x.raw.max; } });
      F.options.push(o);
      const line = h('div.row', null, pk.el, o.v, o.mm, btn('x', () => { F.options.splice(F.options.indexOf(o), 1); line.remove(); }));
      optBox.insertBefore(line, addB);
    };
    const addB = btn('+ option', addOpt);
    optBox.appendChild(addB);
    const toSel = select([['bag', 'inventory'], ['ground', 'ground (at your feet)'], ['cash', 'cash inventory']], F.to, v => { F.to = v; });
    right.appendChild(sect('Item spawner',
      h('div.grid2', null,
        h('span.lbl', null, 'count'), h('div.row', null, cnt, h('span.dim', null, d.stack > 1 ? `stacks of ${d.stack} (the bag splits them)` : 'one instance each')),
        h('span.lbl', null, 'grade'), h('div.row', null, gradeSel, h('span.dim', null, 'normal / magic / noble / divine')),
        h('span.lbl', null, 'upgrade'), upSel,
        h('span.lbl', null, 'sockets'), h('div.col', null, sockSel, stoneRow),
        h('span.lbl', null, 'options'), optBox,
        h('span.lbl', null, 'to'), h('div.row', null, toSel, check('bound', () => F.bound, v => { F.bound = v; }), check('roll random options', () => F.roll, v => { F.roll = v; }), check('free values (no min..max clamp)', () => F.free, v => { F.free = v; }))),
      h('div.row', { style: { marginTop: '6px' } },
        btn('Spawn', () => spawn(d.index), { big: true }),
        btn('Copy as command', () => { const l = cmdLine(d.index); navigator.clipboard?.writeText(l).catch(() => {}); ctx.status(l); }),
        btn('Who drops it', () => ctx.show('drops', { item: d.index })),
        btn('Model viewer', () => ctx.run(`/gm viewer item ${d.index}`)))));
    // box contents
    const box = d.box;
    if (box?.e?.length) {
      const items = await gmData.list('items');
      const tot = nz(box.total) || box.e.reduce((s, e) => s + nz(e[2]), 0) || 1;
      right.appendChild(sect(`Box contents (${box.k || 'box'}${box.give ? `, gives ${box.give}` : ''})`, table(['item', 'count', 'chance'], box.e.slice(0, 120).map(e => {
        const n = h('span', { style: { cursor: 'pointer', color: '#9fd2ff' } }, `${items.byId.get(String(e[0]))?.name || `Item ${e[0]}`} (${e[0]})`);
        n.addEventListener('click', () => { list.vl.select(null); showItem(e[0]); });
        return [n, e[1], box.k === 'random' ? pct(nz(e[2]) / tot) : ''];
      }))));
    }
    // who drops (top)
    const who = h('div.dim', null, 'looking up drops…');
    right.appendChild(sect('Dropped by', who));
    whoDrops(d.index).then(w => {
      clear(who);
      if (!w.monsters.length && !w.maps.length) { who.appendChild(h('span.dim', null, `no monster drops it${w.sets.length ? ` (in item sets ${w.sets.slice(0, 8).join(', ')})` : ''}`)); return; }
      who.appendChild(table(['monster', 'Lv', 'chance'], w.monsters.slice(0, 12).map(x => {
        const n = h('span', { style: { cursor: 'pointer', color: '#9fd2ff' } }, `${x.monster.name} (${x.monster.id})`);
        n.addEventListener('click', () => ctx.show('monsters', { monster: x.monster.id }));
        return [n, x.monster.raw.level, pct(x.p)];
      })));
      if (w.maps.length) who.appendChild(h('div.dim', null, `map layers: ${w.maps.slice(0, 10).map(x => `map ${x.map} ${pct(x.p)}`).join(' · ')}`));
    });
    // edit an owned item
    const own = ownedItems(game);
    const ownSel = select([['', `(choose one of your ${own.length} items)`], ...own.map((o, i) => [String(i), o.label])], '', () => {});
    right.appendChild(sect('Edit an owned item (/gm itemedit)', row(null, ownSel,
      btn('Apply grade / upgrade / sockets / options', async () => {
          const o = ownSel.value === '' ? null : own[Number(ownSel.value)];
        if (!o) return ctx.status('Choose an item first.', 'ffff5a45');
        const ok = await editItem(game, o.inst, { grade: F.grade, upgrade: F.upgrade, sockets: F.sockets ? F.stones.slice(0, F.sockets) : 0, options: optionList(), count: F.count, roll: F.roll });
        ctx.status(ok ? `${o.inst.name} edited.` : 'Edit failed.', ok ? 'ffffe38c' : 'ffff5a45');
      }))));
  }
  const optionList = () => F.options.filter(o => o.row).map(o => [o.row, nz(o.v.value, o.row.raw.max)]);
  const cmdLine = (index) => {
    const opts = optionList().map(([r, v]) => `${r.id} ${v}`).join(' ');
    return `/gm makeitem ${index} ${F.count} ${F.upgrade ?? 0} ${F.sockets}${opts ? ` ${opts}` : ''}`;
  };
  async function spawn(index) {
    const r = await makeItem(game, { item: index, count: F.count, upgrade: F.upgrade, grade: F.grade, sockets: F.sockets ? F.stones.slice(0, F.sockets) : 0, options: optionList(), to: F.to, bound: F.bound, roll: F.roll, free: F.free });
    gm.say(r.ok ? r.message : r.message, r.ok ? undefined : 'ffff5a45');
    ctx.status(r.message, r.ok ? 'ffffe38c' : 'ffff5a45');
    if (r.ok) gm.log(`makeitem ${r.message}`);
  }
  return { el: sp.el, onShow(arg) { if (!list.rows) list.refresh(); if (arg?.item != null) showItem(arg.item); if (arg?.edit) ctx.status('Pick an item, set the form, then "Apply" under "Edit an owned item".'); } };
}

// ======================================================================================================== teleport
function teleportPage(ctx) {
  const { gm, game } = ctx;
  const st = { mode: 'maps', sel: null, point: null };
  const modeSel = select([['maps', 'Maps'], ['locations', 'Locations'], ['dungeons', 'Dungeons'], ['bookmarks', 'Bookmarks']], 'maps', v => { st.mode = v;st.sel=null;updateTravelSupport();list.reload(); });
  const BM = 'dekaron-solo:gm:bookmarks';
  const bookmarks = () => { try { return JSON.parse(localStorage.getItem(BM) || '[]'); } catch { return []; } };
  const list = searchList({
    height: 430,
    rows: async () => {
      if (st.mode === 'bookmarks') return bookmarks().map((b, i) => ({ id: i, name: b.name, sub: `map ${b.map} (${Math.floor(b.x)}, ${Math.floor(b.z)})`, search: `${b.name} ${b.map}`.toLowerCase(), raw: b }));
      return gmData.list(st.mode);
    },
    cols: [{ key: 'id', width: 44, cls: 'dim' }, { key: 'name', width: 'grow' }, { key: 'sub', width: 120, cls: 'dim' }],
    extra: modeSel,
    onSelect: r => pick(r),
    onDbl: r => { pick(r); go(); },
  });
  const info = h('div');
  // Ctrl+click on the minimap = pick + Go at once (the same /gm move Go sends, so the server route and its checks apply)
  const mm = minimapPicker({ size: 330, onPick: (p, e) => { st.point = p; xi.value = Math.floor(p.x); zi.value = Math.floor(p.z); if (e?.ctrlKey) go(); } });
  const xi = numIn('', 64, { placeholder: 'x' }), zi = numIn('', 64, { placeholder: 'z' });
  const posLbl = h('span.dim');
  const goButton=btn('Go',()=>go(),{big:true}),landingButton=btn('Landing point',()=>{st.point=null;xi.value='';zi.value='';go();}),travelSupport=h('div.tip',{style:{whiteSpace:'normal',width:'170px'}});
  function updateTravelSupport(){const id=st.mode==='dungeons'?'enterdungeon':'move',state=applyCommandSupport(goButton,game,id);applyCommandSupport(landingButton,game,id);travelSupport.textContent=state.reason;}
  updateTravelSupport();
  const right = h('div', null, info,
    h('div', { style: { display: 'flex', gap: '10px', alignItems: 'flex-start' } }, mm.el, h('div.col', null,
      h('div.tip', { style: { whiteSpace: 'normal', width: '170px' } }, 'Click the minimap to pick a cell, then Go. Ctrl+click the minimap or double-click a list row to go at once.'),
      row('x', xi), row('z', zi),
      goButton,landingButton,travelSupport,
      btn('Here (my position)', () => { const p = here(game); xi.value = Math.floor(p.x); zi.value = Math.floor(p.z); mm.setPoint({ x: p.x, z: p.z }); }),
      btn('Bookmark this spot', () => { const p = here(game); const b = bookmarks(); b.push({ name: `${game.world?.info?.name || 'map'} ${Math.floor(p.x)},${Math.floor(p.z)}`, map: p.map, x: p.x, z: p.z }); localStorage.setItem(BM, JSON.stringify(b)); if (st.mode === 'bookmarks') list.reload(); ctx.status('Bookmarked.'); }),
      posLbl)),
    sect('Teleport tools',
      row(null, supportedToggle(ctx,'tpclick','Ctrl+click teleport', () => gm.st.tpclick, v => ctx.run(`/gm tpclick ${v ? 'on' : 'off'}`), { title: 'Ctrl+left click on the ground, the minimap or the world map teleports you there' }),
        supportedToggle(ctx,'unlockmaps','Ignore map limits', () => gm.st.unlock, () => ctx.run('/gm unlockmaps')),
        btn('Return to town', () => { const r = game.respawnTarget(); ctx.run(`/gm move ${r.mapIndex} ${Math.floor(r.x)} ${Math.floor(r.z)}`); }),
        btn('Ardeca', () => ctx.run('/gm move 150 349 129')))));
  const sp = split(360, list.el, right);

  async function pick(r) {
    st.sel = r;
    clear(info);
    const x = r.raw;
    let map = null, pt = null;
    if (st.mode === 'maps') {
      map = x.index;
      info.appendChild(h('h4', null, `${r.name}  (map ${x.index})`));
      info.appendChild(h('div', null, `${x.file || ''} · Lv ${x.level?.[0] ?? '?'}-${x.level?.[1] ?? '?'} · ${[x.dungeon && 'dungeon', x.pvp && 'PvP', x.siege && 'siege', x.peace && 'peace', x.portal && 'portal', x.vehicle && 'vehicle', x.pet && 'pet'].filter(Boolean).join(' · ') || 'field'}${x.serverOnly ? ' · server-only' : ''}`));
      if (x.landing) { pt = { x: x.landing[0] + 0.5, z: x.landing[1] + 0.5 }; info.appendChild(h('div.dim', null, `landing ${x.landing[0]}, ${x.landing[1]} (${x.landingFrom || ''})`)); }
    } else if (st.mode === 'locations') {
      map = x.map; pt = { x: nz(x.x) + 0.5, z: nz(x.y) + 0.5 };
      info.appendChild(h('h4', null, `${r.name}  (location ${x.index})`));
      info.appendChild(h('div', null, `map ${x.map} · ${x.x}, ${x.y} · dir ${x.dir}`));
    } else if (st.mode === 'dungeons') {
      map = x.maps?.[0];
      info.appendChild(h('h4', null, `${r.name}  (dungeon ${x.index})`));
      info.appendChild(h('div', null, `keeper ${x.keeper || '-'} · ${x.expireMin || 0} min · members ${(x.members || []).join('-')} · floors ${(x.maps || []).join(', ')}${x.ticket ? ` · ticket ${x.ticket}` : ''}`));
      const fl = select((x.maps || []).map((m, i) => [String(i), `floor ${i + 1} (map ${m})`]), '0', () => {});
      info.appendChild(supportSection(ctx,'enterdungeon','Dungeon entry',row('floor',fl,btn('Enter',()=>ctx.run(`/gm dungeon ${x.index} ${fl.value}`),{big:true}))));
    } else {
      map = x.map; pt = { x: x.x, z: x.z };
      info.appendChild(h('h4', null, r.name));
      info.appendChild(row(null, btn('Delete bookmark', () => { const b = bookmarks(); b.splice(r.id, 1); localStorage.setItem(BM, JSON.stringify(b)); list.reload(); })));
    }
    st.map = map;
    st.point = pt;
    xi.value = pt ? Math.floor(pt.x) : ''; zi.value = pt ? Math.floor(pt.z) : '';
    if (map != null) { await mm.setMap(map); mm.setPoint(pt); tick(); }
  }
  function go() {
    const support=commandSupport(game,st.mode==='dungeons'?'enterdungeon':'move');if(!support.enabled){ctx.status(support.reason,'ffff5a45');return;}
    const r = st.sel;
    if (!r && st.map == null) { ctx.status('Pick a map first.', 'ffff5a45'); return; }
    if (st.mode === 'locations' && xi.value === '' ) return ctx.run(`/gm goloc ${r.raw.index}`);
    if (st.mode === 'dungeons') return ctx.run(`/gm dungeon ${r.raw.index} 0`);
    const map = st.map ?? here(game).map;
    const x = xi.value, z = zi.value;
    return ctx.run(x !== '' && z !== '' ? `/gm move ${map} ${nz(x)} ${nz(z)}` : `/gm move ${map}`);
  }
  function tick() {
    const p = here(game);
    posLbl.textContent = `you: map ${p.map} · ${Math.floor(p.x)}, ${Math.floor(p.z)}`;
    mm.setPlayer(mm.map === p.map ? { x: p.x, z: p.z } : null);
  }
  return {
    el: sp.el, tick,
    onShow() {
      if (!list.rows) list.refresh();
      if (st.map == null) { const m = here(game).map; st.map = m; mm.setMap(m).then(tick); gmData.get('maps', m).then(r => { if (r && !st.sel) { st.sel = r; pick(r); } }); }
    },
  };
}

// ======================================================================================================== npcs
function npcsPage(ctx) {
  const { gm, game } = ctx;
  const st = { gm: false };
  const gmOnly = check('GM / test NPCs', () => st.gm, v => { st.gm = v; list.refresh(); });
  const gmSet = new Set((gmData.reg?.original?.gmNpcs || []).map(n => Number(n.npc)));
  const list = searchList({
    list: 'npcs', height: 300,
    cols: [{ key: 'id', width: 44, cls: 'dim' }, { key: 'name', width: 'grow' }, { get: r => (r.raw.roles || []).join(', '), width: 120, cls: 'dim' }],
    filter: r => !st.gm || gmSet.has(Number(r.id)),
    extra: gmOnly,
    onSelect: r => showNpc(r),
  });
  const live = vlist({ height: 116, cols: [{ key: 'id', width: 44, cls: 'dim' }, { key: 'name', width: 'grow' }, { key: 'sub', width: 90, cls: 'dim' }], onDbl: r => game.windows?.openNpc?.(r.npc) });
  const right = h('div');
  const sp = split(380, h('div.col', null, list.el, h('h4', null, 'On this map (double-click: talk)'), live.el), right);
  function showNpc(r) {
    clear(right);
    const x = r.raw;
    const G = (gmData.reg?.original?.gmNpcs || []).find(n => Number(n.npc) === Number(r.id));
    right.appendChild(h('h4', null, `${r.name}  #${r.id}`));
    embeddedModelPreview(ctx, right, 'npc', r.id);
    if (G) right.appendChild(h('div.gold', { style: { whiteSpace: 'normal' } }, `${G.role}${GM_ONLY_NPCS.has(Number(r.id)) ? ' · GM characters only (shown in GM mode)' : ''}`));
    right.appendChild(h('div', null, `roles: ${(x.roles || []).join(', ') || 'npc'}`));
    if ((x.jobs || []).length) right.appendChild(h('div.dim', { style: { whiteSpace: 'normal' } }, `jobs: ${x.jobs.map(j => `${j[0]}:${j[1]}`).join(' ')}`));
    right.appendChild(h('div.row', null, h('span.lbl', null, 'placed on'), ...(x.maps || []).slice(0, 30).map(m => tag(`map ${m}`, () => ctx.run(`/gm move ${m}`))), (x.maps || []).length ? null : h('span.dim', null, 'not placed on any map')));
    const px = numIn('', 60, { placeholder: 'x' }), pz = numIn('', 60, { placeholder: 'z' }), pd = numIn('', 50, { placeholder: 'dir' });
    right.appendChild(sect('Actions',
      row(null, btn('Go to', () => ctx.run(`/gm gotonpc ${r.id}`), { big: true }), supportedButton(ctx,'spawnnpc','Spawn in front of me', () => ctx.run(`/gm spawnnpc ${r.id}`), { big: true }), btn('Model viewer', () => ctx.run(`/gm viewer npc ${r.id}`))),
      supportSection(ctx,'spawnnpc','Live NPC placement',row('spawn at',px,pz,pd,btn('Spawn',()=>ctx.run(`/gm spawnnpc ${r.id} ${nz(px.value, here(game).x)} ${nz(pz.value, here(game).z)} ${nz(pd.value)}`))))));
    const def = game.data?.npcs?.npcs?.[r.id];
    if (def) right.appendChild(h('div.tip', null, `shape ${def.shape || '-'} · action ${def.act || '-'} · desc ${def.desc ?? '-'}`));
  }
  function tick() {
    const rows = (game.npcs || []).map(n => ({ id: n.npcIndex, name: n.name, sub: n.gmSpawned ? 'spawned' : (n.role || ''), npc: n }));
    if (rows.length !== live.rows.length || rows.some((x, i) => x.npc !== live.rows[i]?.npc)) live.setRows(rows);
  }
  return { el: sp.el, tick, onShow(arg) { if (!list.rows) list.refresh(); tick(); if (arg?.npc != null) gmData.get('npcs', arg.npc).then(r => { if (r) { list.vl.select(r); showNpc(r); } }); } };
}

// ======================================================================================================== character
function characterPage(ctx) {
  const { gm, game } = ctx;
  const rename=game.save.authority==='server'?renameControls(ctx):null;
  const s = () => game.save;
  const live = h('div.out', { style: { whiteSpace: 'pre-wrap', marginBottom: '4px' } });
  const lv = numIn(s().level, 60, { min: 1, max: 250 });
  const expIn = numIn(100000, 110), dilIn = numIn(1000000, 120), coinIn = numIn('', 110), vipIn = numIn(1000, 110);
  const statIn = Object.fromEntries(['str', 'dex', 'con', 'spr', 'points'].map(k => [k, numIn(k === 'points' ? s().statPoints : s().stats?.[k], 58)]));
  const gradeIn = numIn(s().gradePoints || 0, 80);
  const clsSel = select((game.data?.classes || []).filter(c => c.playable !== false).map(c => [String(c.index), c.name]), String(s().classIndex ?? 0), () => {});
  const speed = input('range', gm.st.speed || 1, { min: 0.1, max: 10, step: 0.1 });
  const speedLbl = h('span.gold', null, `x${gm.st.speed || 1}`);
  speed.addEventListener('input', () => { speedLbl.textContent = `x${speed.value}`; });
  speed.addEventListener('change', () => ctx.run(`/gm speed ${speed.value}`));
  const T = (label, key, cmd) => supportedToggle(ctx,cmd,label, () => (key === 'mode' ? gm.st.mode : gm.st[key]), v => ctx.run(`/gm ${cmd} ${v ? 'on' : 'off'}`));
  const toggles = [T('God mode', 'god', 'god'), T('Hide', 'hide', 'hide'), T('One-hit kills', 'onehit', 'onehit'), T('Infinite MP', 'infmp', 'infmp'), T('No-clip', 'noclip', 'noclip'),
    toggleBtn('Cooldowns off', () => gm.st.noCooldowns, v => ctx.run(`/gm cooldowns ${v ? 'off' : 'on'}`)), T('Ctrl+click teleport', 'tpclick', 'tpclick'), T('GM mode [GM]', 'mode', 'gmmode')];
  // skills of the class
  const skillList = vlist({ height: 170, cols: [{ key: 'id', width: 50, cls: 'dim' }, { key: 'name', width: 'grow' }, { get: r => `${game.skills?.learnedLevel?.(r.id) ?? 0} / ${r.max}`, width: 60 }], onSelect: r => { skLv.value = r.max; } });
  const skLv = numIn('', 50, { min: 0, max: 60 });
  const fillSkills = () => {
    const eng = game.skills;
    const rows = (eng?.list || []).map(sk => { const d = eng.skillDef(sk.index) || sk; return { id: d.index, name: d.name || `Skill ${d.index}`, max: d.levels?.length || 1, search: '' }; }).filter(r => r.id != null);
    skillList.setRows(rows);
  };
  // buffs
  const buffPk = picker({ list: 'statuses', data: gmData, width: 300, placeholder: 'status (buff / debuff)…' });
  const buffMin = numIn(30, 50);
  const gmBuffSel = select([], '', () => {});let gmBuffRows=[];
  gmData.list('gmBuffs').then(rows => {gmBuffRows=rows;for (const r of rows) gmBuffSel.appendChild(h('option', { value: String(r.id) }, `${r.name} (${r.sub})`)); });
  const el = h('div.scroll', { style: { height: '100%' } },
    live, rename?.el, gearBuilder(ctx),
    h('div', { style: { display: 'flex', gap: '14px' } },
      h('div', { style: { flex: '1 1 50%' } },
        sect('Level / EXP / money',
          row('level', lv, btn('Set level', () => ctx.run(`/gm level ${nz(lv.value, 1)}`), { big: true }), h('span.tip', null, 'up = the normal level-up path')),
          row('EXP', expIn, btn('Add EXP', () => ctx.run(`/gm exp ${nz(expIn.value)}`))),
          row('DIL', dilIn, btn('Add', () => ctx.run(`/gm dil ${nz(dilIn.value)}`)), btn('Set', () => ctx.run(`/gm dil ${nz(dilIn.value) - nz(s().dil)}`))),
          row('D-Shop coins', coinIn, btn('Set', () => ctx.run(`/gm dkc ${nz(coinIn.value)}`)), btn('Unlimited', () => ctx.run('/gm dkc unlimited'))),
          row('VIP Points', vipIn, btn('Set', () => ctx.run(`/gm vip set ${nz(vipIn.value)}`)), btn('Add', () => ctx.run(`/gm vip add ${nz(vipIn.value)}`))),
          row('grade points', gradeIn, btn('Set', () => ctx.run(`/gm grade ${nz(gradeIn.value)}`)))),
        sect('Stats',
          h('div.row', null, ...['str', 'dex', 'con', 'spr', 'points'].map(k => h('span', null, h('span.lbl', { style: { minWidth: '0', marginRight: '3px' } }, k.toUpperCase()), statIn[k]))),
          row(null, btn('Apply stats', async () => { for (const k of ['str', 'dex', 'con', 'spr', 'points']) if (statIn[k].value !== '') await ctx.run(`/gm setstat ${k} ${nz(statIn[k].value)}`); }, { big: true }),
            btn('Stat reset', () => ctx.run('/gm statreset')))),
        supportSection(ctx,'setclass','Class', row(null, clsSel, btn('Change class (reloads)', () => ctx.run(`/gm setclass ${clsSel.value}`)))),
        sect('Cheats', h('div.row', null, ...toggles),
          row('move speed', speed, speedLbl),
          row(null, btn('Heal', () => ctx.run('/gm heal')), btn('Revive', () => ctx.run('/gm revive')), btn('Reset cooldowns', () => ctx.run('/gm cooldowns')), btn('Kill all', () => ctx.run('/gm killall')), btn('Inspect', () => ctx.run('/gm inspect'))))),
      h('div', { style: { flex: '1 1 50%' } },
        sect('Skills', skillList.el,
          row('level', skLv, btn('Set skill level', () => { const r = skillList.selected; if (r) ctx.run(`/gm skill ${r.id} ${nz(skLv.value, r.max)}`).then(() => skillList.refresh()); }), btn('All skills', () => ctx.run('/gm allskills').then(() => skillList.refresh())), btn('Skill reset', () => ctx.run('/gm skillreset').then(() => skillList.refresh()))),
          supportSection(ctx,'meister','Meister path',row('meister',btn('Path A',()=>ctx.run('/gm meister A')),btn('Path B',()=>ctx.run('/gm meister B'))))),
        sect('Buffs', row(null, buffPk.el), row('minutes', buffMin, btn('Apply buff', () => { if (buffPk.value) ctx.run(`/gm buff ${buffPk.value.id} ${nz(buffMin.value, 30)}`); })),
          row('GM buff', gmBuffSel, btn('Grant original buff', () => { if(!gmBuffSel.value)return;if(game.save.authority!=='server')return ctx.run(`/gm mapbuff ${gmBuffSel.value}`);const buff=gmBuffRows.find(r=>String(r.id)===gmBuffSel.value)?.raw;if(buff?.status!=null)return ctx.run(`/gm mapbuff ${gmBuffSel.value}`);ctx.status('Choose an original GM buff with a status definition.','ffff5a45'); }))))));
  function tick() {
    rename?.refresh();
    const p = game.player, sv = s();
    if (!p) return;
    live.textContent = `${sv.name} · ${game.classDef?.name || ''} · Lv ${sv.level} · EXP ${fmt(sv.exp)} · HP ${fmt(Math.round(p.hp))}/${fmt(p.maxHp)} · MP ${fmt(Math.round(p.mp))}/${fmt(p.maxMp)} · DIL ${fmt(sv.dil)} · coins ${gm.coinsText()}\n`
      + `STR ${sv.stats?.str} DEX ${sv.stats?.dex} CON ${sv.stats?.con} SPR ${sv.stats?.spr} · stat points ${sv.statPoints ?? 0} · skill points ${sv.skillPoints ?? 0} · speed ${(p.groundSpeed?.('run') || 0).toFixed(2)} u/s`;
    for (const t of toggles) t._paint?.();
  }
  return { el, tick, onShow() { lv.value = s().level; for (const k of ['str', 'dex', 'con', 'spr']) statIn[k].value = s().stats?.[k] ?? ''; statIn.points.value = s().statPoints ?? 0; coinIn.value = gm.dshopBalance() ?? ''; fillSkills(); tick(); } };
}

// ======================================================================================================== quests
function questsPage(ctx) {
  const { game } = ctx;
  const Q = () => game.quests;
  const npcName = id => game.data?.npcs?.npcs?.[id]?.name || `NPC ${id}`;
  // quest text links: [nlink]npc[/nlink], [mlink]monster[/mlink], [ilink]item[/ilink]
  const links = s => String(s).replace(/\[nlink\](\d+)\[\/nlink\]/gi, (_, n) => npcName(n))
    .replace(/\[mlink\](\d+)\[\/mlink\]/gi, (_, n) => game.data?.monster?.(Number(n))?.name || `Monster ${n}`)
    .replace(/\[ilink\](\d+)\[\/ilink\]/gi, (_, n) => game.items?.db?.name?.(Number(n)) || `Item ${n}`)
    .replace(/\[\/?[a-z]+link\]/gi, '');
  const stateOf = id => { const q = Q(); if (!q) return ''; return q.isActive(id) ? (q.isComplete(id) ? 'ready' : 'active') : q.isDone(id) ? 'done' : ''; };
  const fSel = select([['', 'all quests'], ['active', 'in progress'], ['done', 'done'], ['new', 'not started']], '', () => list.refresh());
  const list = searchList({
    list: 'quests', height: 430,
    cols: [{ key: 'id', width: 50, cls: 'dim' }, { key: 'name', width: 'grow' }, { get: r => r.raw.level ?? '', width: 30 }, { get: r => stateOf(r.id), width: 44, cls: 'gold' }],
    filter: r => { const s = stateOf(r.id); return !fSel.value || (fSel.value === 'active' ? (s === 'active' || s === 'ready') : fSel.value === 'done' ? s === 'done' : !s); },
    extra: fSel,
    onSelect: r => showQuest(r),
  });
  const right = h('div');
  const sp = split(380, list.el, right);
  function showQuest(r) {
    clear(right);
    const id = Number(r.id), q = Q(), def = q?.db?.quest?.(id);
    right.appendChild(h('h4', null, `${r.name}  #${id}`));
    right.appendChild(h('div', null, `type ${r.raw.type ?? '-'} · Lv ${r.raw.level ?? '-'} · parent ${r.raw.parent ?? '-'}${def?.cat ? ` · ${def.cat}` : ''}${def?.map != null ? ` · map ${def.map}` : ''}`));
    right.appendChild(h('div.dim', null, r.raw.script || def?.src || ''));
    if (!q) { right.appendChild(h('div.bad', null, 'The quest system is not installed.')); return; }
    const state = h('div.gold');
    const paintState = () => { state.textContent = `state: ${q.isActive(id) ? (q.isComplete(id) ? 'in progress, complete (ready to claim)' : 'in progress') : q.isDone(id) ? `done x${q.engine.doneCount(id)}` : 'not started'}`; };
    paintState();
    right.appendChild(state);
    const who = v => (v == null ? '-' : Array.isArray(v) ? v.map(who).join(', ') : typeof v === 'object' ? `${v.name || npcName(v.npc ?? v.id ?? v.index)} (${v.npc ?? v.id ?? v.index ?? '?'})` : `${npcName(v)} (${v})`);
    if (def?.giver != null || def?.turnIn != null) right.appendChild(h('div.dim', null, `giver ${who(def.giver)} · turn in ${who(def.turnIn)}${def.next ? ` · next ${Array.isArray(def.next) ? def.next.join(', ') : def.next}` : ''}`));
    // objectives + slot editor
    const objs = def?.objectives || [];
    const slots = q.engine.slots(id);
    const ins = [];
    const tb = h('div.col');
    for (const o of objs) {
      const e = numIn(slots?.[o.slot] ?? 0, 60, { min: 0 });applyCommandSupport(e,game,'questslots');
      ins.push([o, e]);
      tb.appendChild(h('div.row', null, h('span.dim', null, `slot ${o.slot}`), h('span', { style: { whiteSpace: 'normal', flex: '1' } }, `${o.kind}: ${links(o.label || q.engine.objectiveText?.(def, o) || '')}`), e, h('span.dim', null, `/ ${o.count || 1}`)));
    }
    right.appendChild(sect('Objectives', objs.length ? tb : h('div.dim', null, 'no objectives (talk / scripted)'),
      objs.length ? row(null, supportedButton(ctx,'questslots','Save slot values', () => {
        if (!q.isActive(id)) { ctx.status('Start the quest first.', 'ffff5a45'); return; }
        const s = q.engine.slots(id);
        for (const [o, e] of ins) s[o.slot] = nz(e.value);
        q.engine._changed?.(id);
        game.events?.emit?.('quest:changed', { ids: [id] });
        paintState(); ctx.status('Slots saved.');
      }), supportedButton(ctx,'questslots','Fill all', () => { for (const [o, e] of ins) e.value = o.count || 1; })) : null));
    right.appendChild(sect('State',
      row(null, btn('Start', () => ctx.run(`/gm quest start ${id}`).then(() => showQuest(r)), { big: true }), btn('Complete', () => ctx.run(`/gm quest complete ${id}`).then(() => showQuest(r)), { big: true }),
        btn('Reset', () => ctx.run(`/gm quest reset ${id}`).then(() => showQuest(r))), btn('Abandon', () => ctx.run(`/gm quest abandon ${id}`).then(() => showQuest(r))),
        supportedButton(ctx,'questdone','Mark done', () => { q.setDone(id, (q.engine.doneCount(id) || 0) + 1); showQuest(r); })),
      row(null, btn('Offer (start dialog)', () => q.offer?.(id)), btn('Open quest log', () => q.openLog?.(id)), btn('Track', () => q.track?.(id, true)))));
    if (def?.rewards) right.appendChild(sect('Rewards', h('div.out', { style: { maxHeight: '120px', overflow: 'auto' } }, JSON.stringify(def.rewards, null, 0).slice(0, 1500))));
  }
  return { el: sp.el, onShow(arg) { if (!list.rows) list.refresh(); else list.refresh(); if (arg?.quest != null) gmData.get('quests', arg.quest).then(r => r && showQuest(r)); } };
}

// ======================================================================================================== world
function worldPage(ctx) {
  const { gm, game } = ctx;
  const clockLbl = h('span.gold');
  const hour = input('range', 12, { min: 0, max: 24, step: 0.25 });
  const hourLbl = h('span', null, '12:00');
  hour.addEventListener('input', () => { const v = Number(hour.value); hourLbl.textContent = `${String(Math.floor(v)).padStart(2, '0')}:${String(Math.round((v % 1) * 60)).padStart(2, '0')}`; });
  const skySel = select([], '', () => {});
  gmData.list('skies').then(rows => { for (const r of rows) skySel.appendChild(h('option', { value: String(r.id) }, `${r.id} ${r.name}`)); });
  const ts = input('range', 1, { min: 0.1, max: 5, step: 0.1 });
  const tsLbl = h('span.gold', null, 'x1');
  ts.addEventListener('input', () => { tsLbl.textContent = `x${ts.value}`; });
  ts.addEventListener('change', () => ctx.run(`/gm timescale ${ts.value}`));
  const rate = k => { const m = numIn(2, 50, { min: 0.1, step: 'any' }), mn = numIn('', 50, { placeholder: 'min' }); return row(`${k} rate`, m, h('span.dim', null, 'x for'), mn, h('span.dim', null, 'minutes'), btn('Start', () => ctx.run(`/gm ${k}rate ${nz(m.value, 1)}${mn.value ? ` ${nz(mn.value)}` : ''}`)), btn('End', () => ctx.run(`/gm ${k}rate 1`))); };
  const pcIn = numIn(20, 50);
  const noticeIn = txtIn('', 420, { placeholder: 'notice text (\\n = new line)', maxlength: 511 });
  // events
  const evSel = select([], '', () => {});
  const fillEvents = () => {
    clear(evSel);
    const named = [['Dead Front', 'Dead Front'], ['Ice Castle', 'Ice Castle'], ['Field Boss', 'Field Boss (Mitera)'], ['Colosseum Arena', 'Colosseum Arena'], ['Infinite Battle', 'Infinite Battle']];
    for (const [v, t] of named) evSel.appendChild(h('option', { value: v }, t));
    const rows = game.eventsSystem?.schedule?.rows || game.eventsSystem?.data?.ev?.schedule?.timetable || [];
    for (const r of rows) if (r?.Name) evSel.appendChild(h('option', { value: r.Name }, `${r.Name} - ${r.Map || ''} (${r.Level || ''}) ${r.Time || ''}`));
  };
  const contentSel = select([], '', () => {});
  gmData.list('contents').then(rows => { for (const r of rows) contentSel.appendChild(h('option', { value: r.name }, r.name)); });
  const bgmPk = picker({ list: 'maps', data: gmData, width: 240, placeholder: 'map music…' });
  const fxPk = picker({ list: 'effects', data: gmData, width: 280, placeholder: 'effect scene (11 521)…' });
  const fxScene = numIn('', 50, { placeholder: 'scene' });
  const fxOn = select(['self', 'target', 'ground'], 'self', () => {});
  const oxQ = picker({ list: 'oxQuestions', data: gmData, width: 380, placeholder: 'OX question (or random)…' });
  const shutIn = numIn(5, 50);
  const el = h('div.scroll', { style: { height: '100%' } },
    h('div', { style: { display: 'flex', gap: '14px' } },
      h('div', { style: { flex: '1 1 50%' } },
        supportSection(ctx,'time','Time of day (the world clock, maplist OnedayTime)', row('now', clockLbl),
          row('set', hour, hourLbl, btn('Set', () => ctx.run(`/gm time ${hourLbl.textContent}`))),
          row(null, btn('Freeze', () => ctx.run('/gm time freeze')), btn('Resume', () => ctx.run('/gm time resume')), btn('Real clock', () => ctx.run('/gm time reset')),
            btn('Dawn 6h', () => ctx.run('/gm time 6')), btn('Noon', () => ctx.run('/gm time 12')), btn('Night 22h', () => ctx.run('/gm time 22')))),
        supportSection(ctx,'weatherfx','Weather (effect 100 scenes)', h('div.row', null, ...WEATHER_NAMES.map(w => btn(w, () => ctx.run(`/gm weatherfx ${w}`))))),
        supportSection(ctx,'sky','Sky (script/environment/sky_table.txt)', row(null, skySel, btn('Apply', () => ctx.run(`/gm sky ${skySel.value}`)))),
        supportSection(ctx,'timescale','Game speed', row(null, ts, tsLbl, btn('x1', () => { ts.value = 1; tsLbl.textContent = 'x1'; ctx.run('/gm timescale 1'); }))),
        supportSection(ctx,'exprate','Rate events (GM Tool: 178:1-5 banners)', rate('exp'), rate('drop'), rate('dil'),
          row('PC-cafe EXP', pcIn, h('span.dim', null, '%'), btn('Set', () => ctx.run(`/gm pcroomexp ${nz(pcIn.value)}`)))),
        sect('Notice (GM Tool "Write Notice")', row(null, noticeIn),
          row(null, btn('Send to all', () => noticeIn.value && ctx.run(`/gm notice all ${noticeIn.value}`)), btn('Send to map', () => noticeIn.value && ctx.run(`/gm notice map ${noticeIn.value}`)),
            btn('Remove', () => ctx.run('/gm notice clear')), btn('Notice window', () => ctx.run('/gm notice all'))))),
      h('div', { style: { flex: '1 1 50%' } },
        sect('Event starter', row(null, evSel), row(null, supportedButton(ctx,'event','Start now', () => evSel.value && ctx.run(`/gm event ${evSel.value}`), { big: true }), btn('Contents timetable', () => game.eventsSystem?.openTimetable?.())),
          supportSection(ctx,'partywar','Party war',row('party war', contentSel, btn('open', () => ctx.run(`/gm partywar "${contentSel.value}" open`)), btn('start', () => ctx.run(`/gm partywar "${contentSel.value}" start`)), btn('end', () => ctx.run(`/gm partywar "${contentSel.value}" end`)))),
          supportSection(ctx,'siege','Siege',row('siege', ...['open', 'start', 'end', 'reset'].map(x => btn(x, () => ctx.run(`/gm siege ${x}`)))))),
        sect('OX quiz (map 22 Undo Stadion, Start Stone 5830)', row(null, oxQ.el),
          row(null, btn('Go to arena', () => ctx.run('/gm move 22')), supportedButton(ctx,'ox','Ask', () => ctx.run(`/gm ox ask${game.save.authority!=='server'&&oxQ.value ? ` ${oxQ.value.id}` : ''}`)), supportedButton(ctx,'ox','Auto', () => ctx.run('/gm ox auto'),{args:{action:'auto'}}),
            supportedButton(ctx,'ox','Wall', () => ctx.run('/gm ox wall')), supportedButton(ctx,'ox','Unwall', () => ctx.run('/gm ox unwall'))),
          row(null, supportedButton(ctx,'ox','Eliminate (O)', () => ctx.run('/gm ox killo')), supportedButton(ctx,'ox','Eliminate (X)', () => ctx.run('/gm ox killx')), supportedButton(ctx,'oxentry','Entry open', () => ctx.run('/gm oxentry open')), supportedButton(ctx,'oxentry','Entry closed', () => ctx.run('/gm oxentry close')), supportedButton(ctx,'ox','Export all', () => ctx.run('/gm ox end')))),
        supportSection(ctx,'bgm','Music', row(null, bgmPk.el, btn('Play', () => bgmPk.value && ctx.run(`/gm bgm ${bgmPk.value.id}`)), btn('Off', () => ctx.run('/gm bgm off')))),
        supportSection(ctx,'effect','Effect preview (/gm effect)', row(null, fxPk.el), row(null, fxScene, fxOn, btn('Play', () => fxPk.value && ctx.run(`/gm effect ${fxPk.value.id}${fxScene.value ? ` ${nz(fxScene.value)}` : ' 1'} ${fxOn.value}`)))),
        sect('Server (GM Tool)', supportSection(ctx,'shutdown','Shutdown',row('shutdown in', shutIn, h('span.dim', null, 'min'), btn('Start', () => ctx.run(`/gm shutdown ${nz(shutIn.value, 5)}`)), btn('Cancel', () => ctx.run('/gm shutdown 0')))),
          row(null, btn('User count', () => ctx.run('/gm usercount')), btn('Map users', () => ctx.run('/gm mapusercount')), supportedButton(ctx,'resetcounts','Reset day counters', () => ctx.run('/gm resetcounts')), supportedButton(ctx,'reload','Reload scripts', () => ctx.run('/gm reload all')))))));
  function tick() {
    const c = game.life?.clock;
    clockLbl.textContent = c ? `${c.text()}${c.frozen != null ? ' (frozen)' : ''} · day = ${c.dayMinutes} min · weather ${game.life?.weather?.name || '-'}${gm.st.weather != null ? ' (forced)' : ''}` : 'no world clock (life system)';
  }
  return { el, tick, onShow() { fillEvents(); ts.value = gm.timescale; tsLbl.textContent = `x${gm.timescale}`; const c = game.life?.clock; if (c) { hour.value = c.hour; hour.dispatchEvent(new Event('input')); } tick(); } };
}

// ======================================================================================================== drops
function dropsPage(ctx) {
  const { game } = ctx;
  const out = h('div');
  const monPk = picker({ list: 'monsters', data: gmData, width: 300, placeholder: 'monster…', onPick: () => showMon() });
  const itemPk = picker({ list: 'items', data: gmData, width: 300, placeholder: 'item…', onPick: () => showItem() });
  const mapIn = numIn('', 60, { placeholder: 'map' });
  const clsSel = select((game.data?.classes || []).map((c, i) => [String(c.index ?? i), c.name || `class ${i}`]), String(game.save.classIndex ?? 0), () => showMon());
  const kills = numIn(1000, 70);
  async function showMon() {
    const m = monPk.value; if (!m) return;
    clear(out).appendChild(h('div.dim', null, 'loading…'));
    const map = mapIn.value === '' ? here(game).map : nz(mapIn.value);
    const t = await dropTable(m.id, { map, classIndex: Number(clsSel.value), playerLevel: game.save.level });
    clear(out);
    out.appendChild(h('h4', null, `${m.name} (#${m.id}, Lv ${m.raw.level}) on map ${map}: ${t.items.length} item(s)`));
    out.appendChild(btn('Edit HP / Attack / Drops',()=>ctx.show('monsters',{monster:m.id})));
    for (const n of t.notes) out.appendChild(h('div.dim', null, n));
    for (const mo of t.money) out.appendChild(h('div.gold', null, `DIL ${fmt(mo.min)} - ${fmt(mo.max)}: ${pct(mo.p)} [${mo.layer}]`));
    out.appendChild(table(['item', 'chance', 'stack', 'layers', 'via'], t.items.slice(0, 600).map(it => {
      const n = h('span', { style: { cursor: 'pointer', color: '#9fd2ff' } }, `${it.name} (${it.item})`);
      n.addEventListener('click', () => ctx.show('items', { item: it.item }));
      return [n, pct(it.p), it.min != null ? `${it.min}-${it.max}` : '', it.layers.join('+'), (it.via || []).slice(0, 2).join(', ')];
    })));
  }
  async function showItem() {
    const it = itemPk.value; if (!it) return;
    clear(out).appendChild(h('div.dim', null, 'searching every drop table…'));
    const w = await whoDrops(it.id);
    clear(out);
    out.appendChild(h('h4', null, `${it.name} (#${it.id}): ${w.monsters.length} monster(s), ${w.maps.length} map layer(s), ${w.sets.length} item set(s)`));
    out.appendChild(table(['monster', 'Lv', 'maps', 'chance'], w.monsters.slice(0, 500).map(x => {
      const n = h('span', { style: { cursor: 'pointer', color: '#9fd2ff' } }, `${x.monster.name} (${x.monster.id})`);
      n.addEventListener('click', () => ctx.show('monsters', { monster: x.monster.id }));
      return [n, x.monster.raw.level, (x.monster.raw.spawnMaps || []).slice(0, 5).join(','), pct(x.p)];
    })));
    if (w.maps.length) out.appendChild(h('div', null, `Map layers (every monster killed on the map): ${w.maps.map(x => `map ${x.map} ${pct(x.p)}`).join(' · ')}`));
    if (w.sets.length) out.appendChild(h('div.dim', { style: { whiteSpace: 'normal' } }, `item sets: ${w.sets.join(', ')}`));
  }
  const el = h('div.scroll', { style: { height: '100%' } },
    sect('Monster → items (own table + map layer + class layer)', row(null, monPk.el, h('span.lbl', null, 'map'), mapIn, h('span.lbl', null, 'class'), clsSel, btn('Show', () => showMon()),
      kills, btn('Simulate', async () => {
        const m = monPk.value; if (!m) return;
        clear(out).appendChild(h('div.dim', null, 'rolling…'));
        const s = await simulate(ctx.game, m.id, nz(kills.value, 1000), { map: mapIn.value === '' ? undefined : nz(mapIn.value) });
        clear(out);
        out.appendChild(h('h4', null, `${m.name}: ${fmt(s.kills)} kills on map ${s.map} → ${fmt(s.dil)} DIL, ${s.items.length} item kinds`));
        out.appendChild(table(['item', 'drops', 'count', 'per kill'], s.items.slice(0, 300).map(i => [`${i.name} (${i.item})`, fmt(i.drops), fmt(i.count), pct(i.drops / s.kills)])));
      }))),
    sect('Item → monsters', row(null, itemPk.el, btn('Show', () => showItem()))),
    out);
  return {
    el,
    onShow(arg) {
      if (arg?.item != null) gmData.get('items', arg.item).then(r => { if (r) { itemPk.set(r); showItem(); } });
      if (arg?.monster != null || arg?.target) {
        const id = arg.monster ?? arg.target?.id;
        if (arg.list === 'items') gmData.get('items', id).then(r => { if (r) { itemPk.set(r); showItem(); } });
        else gmData.get('monsters', id).then(r => { if (r) { monPk.set(r); showMon(); } });
      }
    },
  };
}

// ======================================================================================================== tools
function toolsPage(ctx) {
  const { gm, game } = ctx;
  const layers = ['collision', 'nav', 'spawns', 'npcs', 'grid', 'bounds'];
  const dbg = layers.map(l => toggleBtn(l, () => gm.debug.on.has(l), () => ctx.run(`/gm show ${l}`)));
  const vId = h('div');let viewerPick=null;
  const fillViewerPick=()=>{clear(vId);viewerPick=null;if(vKind.value==='target'){vId.appendChild(h('span.dim',null,'Current selected actor'));return;}
    viewerPick=picker({list:{monster:'monsters',npc:'npcs',class:'classes',item:'items'}[vKind.value],data:gmData,width:240,placeholder:'Search original model by name or index…'});vId.appendChild(viewerPick.el);};
  const vKind = select(['monster', 'npc', 'class', 'item', 'target'], 'target', fillViewerPick);fillViewerPick();
  const snapName = txtIn('slot1', 120);
  const snapSel = select([], '', () => {});
  const fillSnaps = () => { clear(snapSel); for (const n of gm.snapshotNames()) snapSel.appendChild(h('option', { value: n }, n)); };
  const file = h('input', { type: 'file', accept: '.json,application/json', style: { display: 'none' } });applyCommandSupport(file,game,'importSave');
  file.addEventListener('change', async () => {
    const f = file.files?.[0]; if (!f) return;
    try { const obj = JSON.parse(await f.text()); await gm.importSave(obj); } catch (err) { ctx.status(`Import failed: ${err.message}`, 'ffff5a45'); }
    file.value = '';
  });
  const editor = h('textarea', { rows: 12, spellcheck: false, style: { width: '100%', height: '190px' } });
  editor.readOnly=game.save.authority==='server';
  const fPk = picker({ list: 'formula', data: gmData, width: 190, placeholder: 'formula key (formula.ini)…', onPick: r => { fVal.value = r.raw.value; } });
  const fVal = numIn('', 70, { step: 'any' });
  const sPk = picker({ list: 'systemVariables', data: gmData, width: 190, placeholder: 'system variable…', onPick: r => { sVal.value = gm.sysvar(r.id) ?? r.raw.value; } });
  const sVal = numIn('', 70, { step: 'any' });
  const mtIn = txtIn('', 360, { placeholder: 'map tool command, e.g. create_map test 256 256' });
  const el = h('div.scroll', { style: { height: '100%' } },
    h('div', { style: { display: 'flex', gap: '14px' } },
      h('div', { style: { flex: '1 1 50%' } },
        sect('View', row(null, toggleBtn('Free camera', () => gm.freecam.on, v => ctx.run(`/gm freecam ${v ? 'on' : 'off'}`), { title: 'WASD / Q E, right-drag to look, wheel = speed, Shift = fast' }),
          toggleBtn('Performance overlay', () => gm.perf.on, () => ctx.run('/gm fps')), btn('Hide UI (Esc / F10 back)', () => ctx.run('/gm hideui'))),
          h('div.row', null, h('span.lbl', null, 'debug'), ...dbg, btn('none', () => { ctx.run('/gm show none'); for (const b of dbg) setTimeout(() => b._paint(), 50); }))),
        sect('Windows', row(null, btn('GM console (`)', () => gm.toggleConsole()), btn('System info', () => ctx.run('/gm sysinfo')), btn('User monitor', () => ctx.run('/gm monitor')), btn('Notice editor', () => ctx.run('/gm notice all')), btn('Restrain chat', () => game.uiwin.open('gmrestrain')))),
        sect('Model viewer (tools/viewer.html)', row(null, vKind, vId, btn('Open', () => {if(vKind.value!=='target'&&!viewerPick?.value){ctx.status('Choose an original catalog model first.','ffff5a45');return;}return ctx.run(`/gm viewer ${vKind.value}${viewerPick?.value?` ${viewerPick.value.id}`:''}`);}))),
        supportSection(ctx,'formula','Tunables', row('formula', fPk.el, fVal, btn('Set', () => fPk.value && ctx.run(`/gm formula ${fPk.value.id} ${nz(fVal.value)}`))),
          row('sysvar', sPk.el, sVal, btn('Set', () => sPk.value && ctx.run(`/gm sysvar ${sPk.value.id} ${nz(sVal.value)}`))),
          row(null, btn('Apply all (save)', () => ctx.run('/gm applyall')), btn('Reset formula', () => { if(game.save.authority==='server'){ctx.status('Formula overrides are unavailable in the authoritative world.','ffff5a45');return;}gm.resetFormula(); ctx.status('Formula overrides removed.'); }))),
        sect('Map tool (forwarded to the map builder)', row(null, mtIn, btn('Run', () => mtIn.value && ctx.run(`/gm maptool ${mtIn.value}`)))),
        sect('Misc', row(null, btn('Clear inventory', async () => { if (await game.uiwin.msgbox('Remove every item from every bag?', { kind: 'yesno' }) === 'yes') ctx.run('/gm clearinv'); }),
          btn('Repair all', () => ctx.run('/gm repairall')), btn('Event log', () => ctx.run('/gm userlog 30')), btn('Position', () => ctx.run('/gm pos'))))),
      h('div', { style: { flex: '1 1 50%' } },
        sect('Save', row(null, btn('Save now', () => ctx.run('/gm save now')), btn('Export .json', () => ctx.run('/gm save export')), supportedButton(ctx,'importSave','Import .json', () => file.click()), file),
          supportSection(ctx,'snapshot','Local snapshots',row('snapshot', snapName, btn('Save', () => ctx.run(`/gm snapshot save ${qv(snapName.value || 'slot1')}`).then(fillSnaps))),
          row(null, snapSel, btn('Load', () => snapSel.value && ctx.run(`/gm snapshot load ${qv(snapSel.value)}`))))),
        sect('Save editor (the character record as JSON)', editor,
          row(null, btn('Load current', () => { try { game.persist(); } catch { /* ignore */ } editor.value = JSON.stringify(game.save, null, 1); }),
            supportedButton(ctx,'importSave','Apply (reloads)', async () => {
              let obj; try { obj = JSON.parse(editor.value); } catch (err) { ctx.status(`JSON error: ${err.message}`, 'ffff5a45'); return; }
              if (await game.uiwin.msgbox('Replace the character record with the edited JSON and reload?', { kind: 'yesno' }) === 'yes') {
                try { await gm.importSave(obj); } catch (err) { ctx.status(`Import failed: ${err.message}`, 'ffff5a45'); }
              }
            }))))));
  return { el, tick() { for (const b of dbg) b._paint?.(); }, onShow() { fillSnaps(); if (!editor.value) { editor.value = JSON.stringify(game.save, null, 1); } } };
}

function buildersPage(ctx){
  const open=(tool,options)=>openBuilder(ctx.game,tool,options).catch(error=>ctx.status(error.message,'ffff5a45'));
  return {el:h('div.scroll',null,sect('Builders',
    h('p',null,'Edit your supported current field or open the separate custom-map builder.'),
    row(null,btn('Item Builder',()=>open('itembuilder'),{title:'Create and edit server item definitions'}),btn('Edit current',()=>open('mapbuilder',{currentOriginal:true}),{title:'Edit a supported current field from your standing character'}),btn('Custom maps',()=>open('mapbuilder',{currentOriginal:false}),{title:'Open the separate custom-map builder'}))))};
}
export const PAGES = {
  inventories: inventoryPage,
  commands: commandsPage, monsters: monstersPage, items: itemsPage, teleport: teleportPage, npcs: npcsPage,
  players: playersPage, character: characterPage, quests: questsPage, world: worldPage, drops: dropsPage, builders:buildersPage, tools: toolsPage,
};
export { optionCode };
