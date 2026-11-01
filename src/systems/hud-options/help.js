// Help, game guide, contents guide and the contents time table.
//   help           game2/ui_infownd.txt              "Help": Basic Controls / Basic System / Major System topic buttons
//                                                    (captions 120:*) -> script/helpermapping.csv -> HELPER pages
//                                                    (script/string/help/stringtable_helper.txt), page arrows
//   guide          game2/helpwindow/ui_infownd2.txt   the Game Guide: Game Information / Class Information /
//                                                    Progress Guide trees from script/guide/guide_list_*.csv
//                                                    (Depth, Name, Category, Code -> HELPER guide_info_*), + Search
//   contentsguide  game2/ui_tutorialreviewwnd.txt     "Contents Guide": the tutorial pages (HELPER cates 41xx/42xx,
//                                                    menu names stringtable_tutorialmenu 2400/2600) with page arrows
//   contents       game2/notice/ui_contentsnoticerenewwnd.txt   content time table (script/contents_timetable.csv)
// renderRich() draws the client's help markup: <img screen= index= width= height=>, <chart TOKEN= LINEFEED=
// COLUMLENGTH=>rows</chart>, <font=N>, <color=..>, <center>, <set=N>.
import { fetchCSVObjects, fetchText } from '../../engine/assets.js';
import { strings } from '../../ui/uiwin/strings.js';
import { applyFont } from '../../ui/uiwin/fonts.js';
import { paintIcon } from '../../ui/uiwin/controls.js';
import { str, plainText } from './util.js';
import { URBAN_WARFARE_HELP, urbanWarfareHelpScheduleText } from '../events/urban-warfare-routes.js';

const H = (cate, code) => strings.resolve({ group: 'HELPER', cate: Number(cate), code: Number(code) });

// ------------------------------------------------------------------------------------------ rich text
/** Render help markup into a UITextBox (its content element), keeping its scrolling. */
export function renderRich(tb, text, { width = null } = {}) {
  if (!tb?.content) { tb?.setText?.(plainText(text)); return; }
  const root = tb.content;
  root.replaceChildren();
  tb.lines = [];
  const lh = tb.lh || 15;
  const W = width || Math.max(100, (tb.box?.w || 400) - 24);
  const lines = String(text ?? '').replace(/\r/g, '').split('\n');
  let skip = 0;
  for (let li = 0; li < lines.length; li++) {
    let line = lines[li];
    if (/^\s*<chart\b/i.test(line)) {
      const head = line;
      const rows = [];
      while (++li < lines.length && !/^\s*<\/chart>/i.test(lines[li])) rows.push(lines[li]);
      root.appendChild(renderChart(head, rows, W, tb.font));
      continue;
    }
    const img = /<img\s+screen=(\S+)\s+index=(\d+)(?:\s+width=(\d+))?(?:\s+height=(\d+))?\s*>/i.exec(line);
    if (img) {
      const [, screen, index, w, h] = img;
      const el = document.createElement('div');
      el.style.cssText = `position:relative;width:${Number(w) || 256}px;height:${Number(h) || 128}px;max-width:100%;background-size:100% 100%`;
      paintIcon(el, { sprite: [screen, Number(index)] });
      el.style.position = 'relative';
      root.appendChild(el);
      // the text reserves the picture's height with empty lines: skip as many as the picture covers
      skip = Math.round((Number(h) || 128) / lh);
      line = line.replace(img[0], '');
      if (!line.trim()) continue;
    }
    if (skip > 0 && !line.trim()) { skip--; continue; }
    skip = 0;
    root.appendChild(renderLine(line, lh));
  }
  tb.top = 0;
  tb._range?.();
  tb.setTop?.(0);
}

function renderLine(line, lh) {
  const d = document.createElement('div');
  d.style.minHeight = `${lh}px`;
  d.style.whiteSpace = 'pre-wrap';
  const setm = /<set=(\d+)>/i.exec(line);
  if (setm) d.style.paddingLeft = `${Math.min(300, Number(setm[1]) / 2)}px`;
  if (/<center>/i.test(line)) d.style.textAlign = 'center';
  const colorStack = [], fontStack = [];
  const re = /<color=(?:0x)?([0-9a-f]{6,8})>|<\/color>|<font=(\d+)>|<\/font>|<[^>]*>/gi;
  let last = 0, m;
  const push = (t) => {
    if (!t) return;
    const s = document.createElement('span');
    s.textContent = t.replace(/\\\\?$/, '');
    const c = colorStack[colorStack.length - 1];
    if (c) s.style.color = `#${c.slice(-6)}`;
    const f = fontStack[fontStack.length - 1];
    if (f) applyFont(s, Number(f));
    d.appendChild(s);
  };
  while ((m = re.exec(line))) {
    push(line.slice(last, m.index));
    last = re.lastIndex;
    if (m[1]) colorStack.push(m[1]);
    else if (m[0].toLowerCase() === '</color>') colorStack.pop();
    else if (m[2]) fontStack.push(m[2]);
    else if (m[0].toLowerCase() === '</font>') fontStack.pop();
  }
  push(line.slice(last));
  return d;
}

function renderChart(head, rows, W, font) {
  const attr = (k, d) => { const m = new RegExp(`${k}=([^\\s>]+)`, 'i').exec(head); return m ? m[1] : d; };
  const TOKEN = attr('TOKEN', '$'), LF = attr('LINEFEED', '^'), LINE = attr('LINECOLOR', 'c6c6c6');
  const cols = String(attr('COLUMLENGTH', '15,45')).split(',').map(Number);
  const sum = cols.reduce((a, b) => a + b, 0) || 1;
  const t = document.createElement('table');
  t.style.cssText = `border-collapse:collapse;width:${Math.min(W, 520)}px;margin:2px 0;table-layout:fixed`;
  for (const raw of rows) {
    const r = raw.replace(/^\s*</, '');
    if (!r.trim()) continue;
    const parts = r.split(TOKEN);
    const tr = document.createElement('tr');
    let cur = {};
    let ci = 0;
    for (const p of parts) {
      const kv = /^(Align|textcolor|BackColor)=(.*)$/i.exec(p.trim());
      if (kv) { cur[kv[1].toLowerCase()] = kv[2]; continue; }
      const td = document.createElement('td');
      td.style.cssText = `border:1px solid #${LINE};padding:2px 4px;vertical-align:middle;width:${(cols[ci] || 10) / sum * 100}%`;
      if (cur.align) td.style.textAlign = cur.align.toLowerCase();
      if (cur.textcolor) td.style.color = `#${cur.textcolor}`;
      if (cur.backcolor) td.style.background = `#${cur.backcolor}`;
      applyFont(td, font || 2);
      td.textContent = plainText(p).split(LF).join('\n');
      td.style.whiteSpace = 'pre-wrap';
      tr.appendChild(td);
      cur = {};
      ci++;
    }
    t.appendChild(tr);
  }
  return t;
}

// ------------------------------------------------------------------------------------------ windows
export function registerHelpWindows(game, ctx) {
  // Preserve the native bitmap, frame and close button. The missing Game
  // Guide body below opens this original panel when its topic is selected.
  game.uiwin.registerWindow(URBAN_WARFARE_HELP.window, {
    script: URBAN_WARFARE_HELP.script,
    create(win) { win.control('btn_exit').onClick(() => game.uiwin.close(URBAN_WARFARE_HELP.window)); },
  });
  // ---------------------------------------------------------------- Help (Basic Controls / System / Major)
  game.uiwin.registerWindow('help', {
    script: 'game2/ui_infownd.txt',
    async create(win) {
      const d = win.data;
      // script/helpermapping.csv: "topic caption,HELPER cate" rows, no header row
      const map = new Map();
      try {
        const raw = await fetchText('script/helpermapping.csv');
        for (const line of raw.split(/\r?\n/)) {
          const i = line.lastIndexOf(',');
          if (i <= 0) continue;
          const cate = Number(line.slice(i + 1));
          if (Number.isFinite(cate) && cate > 0) map.set(line.slice(0, i).trim().toLowerCase(), cate);
        }
      } catch (err) { console.warn('[hud-options] helpermapping.csv', err); }
      d.map = map;
      const tabs = { btn_tab1: 'pan_tab1', btn_tab2: 'pan_tab2', btn_tab3: 'pan_tab3' };
      const show = (b) => { for (const [t, p] of Object.entries(tabs)) { win.control(t).setChecked(t === b); win.control(p).setVisible(t === b); } };
      for (const b of Object.keys(tabs)) win.control(b).onClick(() => show(b));
      d.show = show;
      win.control('pan_chart').setVisible(false);
      const subs = win.controls(/^btn_sub_/i);
      for (const b of subs) b.onClick(() => { for (const o of subs) o.setChecked(o === b); openTopic(b.getText()); });
      async function openTopic(name) {
        const cate = d.map.get(String(name || '').trim().toLowerCase());
        win.control('lbl_subTitle').setText(name || '');
        d.cate = cate; d.page = 1; d.pages = 0;
        if (!cate) { renderRich(win.control('textbox'), ''); return; }
        let n = 0;
        while (n < 20 && (await H(cate, n + 1)) != null) n++;
        d.pages = n;
        paintPage();
      }
      async function paintPage() {
        const t = d.cate ? await H(d.cate, d.page) : '';
        renderRich(win.control('textbox'), t || '');
        win.control('lbl_pageNum').setText(`${d.pages ? d.page : 0}/${d.pages}`);
        win.control('btn_leftArrow').setEnabled(d.page > 1);
        win.control('btn_rightArrow').setEnabled(d.page < d.pages);
      }
      win.control('btn_leftArrow').onClick(() => { if (d.page > 1) { d.page--; paintPage(); } });
      win.control('btn_rightArrow').onClick(() => { if (d.page < d.pages) { d.page++; paintPage(); } });
      d.openTopic = (n) => { const b = subs.find(x => x.getText() === n) || subs[0]; b?.emit('click'); for (const o of subs) o.setChecked(o === b); openTopic(b?.getText()); };
    },
    onOpen(win) { const d = win.data; if (!d.cate) { d.show?.('btn_tab1'); d.openTopic?.(); } },
  });

  // ---------------------------------------------------------------- Game Guide (guide lists + search)
  game.uiwin.registerWindow('guide', {
    script: 'game2/helpwindow/ui_infownd2.txt',
    async create(win) {
      const d = win.data;
      const files = { btn_tab1: 'guide_list_system', btn_tab2: 'guide_list_job', btn_tab3: 'guide_list_level' };
      const pans = { btn_tab1: 'pan_tab1', btn_tab2: 'pan_tab2', btn_tab3: 'pan_tab3', btn_tab4: 'pan_tab4', btn_tab5: 'pan_tab5' };
      win.control('pan_chart').setVisible(false);
      const trees = {};
      for (const [tab, file] of Object.entries(files)) {
        const rows = await fetchCSVObjects(`script/guide/${file}.csv`, true).catch(() => []);
        const nodes = [];
        let cur = null;
        for (const r of rows) {
          const depth = Number(r.Depth), node = { text: String(r.Name || '').trim(), data: { cate: Number(r.Category), code: Number(r.Code) }, children: [] };
          if (depth <= 1) { node.state = 'head'; nodes.push(node); cur = node; } else if (cur) { node.state = 'sub'; cur.children.push(node); } else nodes.push(node);
        }
        trees[tab] = nodes;
        const tree = win.control(pans[tab]).control('multi_tree');
        tree?.setNodes(nodes);
        tree?.on('select', (n) => openNode(n));
      }
      d.trees = trees;
      const show = (b) => { for (const [t, p] of Object.entries(pans)) { win.control(t).setChecked(t === b); win.control(p).setVisible(t === b); } };
      for (const b of Object.keys(pans)) win.control(b).onClick(() => show(b));
      d.show = show;
      // search: every node whose name or text contains the word goes into the Search tab tree
      win.control('btn_tab4').setVisible(true);
      const doSearch = async () => {
        const q = win.control('edit_search').getValue().trim().toLowerCase();
        if (!q) return;
        const found = [];
        for (const nodes of Object.values(trees)) for (const h of nodes) for (const n of [h, ...h.children]) {
          if (!n.data?.cate) continue;
          const text = (await H(n.data.cate, n.data.code)) || '';
          if (n.text.toLowerCase().includes(q) || text.toLowerCase().includes(q)) found.push({ text: n.text, data: n.data, state: 'sub' });
        }
        const title = (str(120, 46) || '⊙ Result (%d)').replace('%d', found.length);
        const tree = win.control('pan_tab4').control('multi_tree');
        tree?.setNodes([{ text: title, state: 'head', open: true, children: found }]);
        if (!tree._hoWired) { tree._hoWired = true; tree.on('select', n => openNode(n)); }
        show('btn_tab4');
      };
      win.control('btn_search').onClick(doSearch);
      win.control('edit_search').on('enter', doSearch);
      async function openNode(n) {
        if (!n?.data?.cate) return;
        const revision = d.topicRevision = (d.topicRevision || 0) + 1;
        win.control('lbl_subTitle').setText(n.text);
        const text = await H(n.data.cate, n.data.code);
        if (d.topicRevision !== revision) return;
        if (!text?.trim() && Number(n.data.cate) === URBAN_WARFARE_HELP.cate && Number(n.data.code) === URBAN_WARFARE_HELP.code) {
          d.urbanSchedule ||= fetchCSVObjects('share/urbanwarfare/time.csv').catch(() => []);
          const rows = await d.urbanSchedule;
          if (d.topicRevision !== revision || !win.isOpen) return;
          renderRich(win.control('textbox'), urbanWarfareHelpScheduleText(rows));
          await game.uiwin.open(URBAN_WARFARE_HELP.window);
        } else renderRich(win.control('textbox'), text || '');
      }
      d.first = () => { const n = trees.btn_tab1?.[0]?.children?.[0]; if (n) openNode(n); };
    },
    onOpen(win) { win.data.show?.('btn_tab1'); if (!win.data.opened) { win.data.opened = true; win.data.first?.(); } },
  });

  // ---------------------------------------------------------------- Contents Guide
  game.uiwin.registerWindow('contentsguide', {
    script: 'game2/ui_tutorialreviewwnd.txt',
    async create(win) {
      const d = win.data;
      const menu = [];
      for (let c = 1; c <= 30; c++) { const s = await strings.resolve({ group: 'NORMAL', cate: 2400, code: c }); if (s) menu.push(s); }
      const entries = [];
      for (let cate = 4101; cate <= 4135; cate++) {
        const first = await H(cate, 1);
        if (first == null) continue;
        const plain = plainText(first).toLowerCase();
        const words = (s) => s.toLowerCase().replace(/\[.*?\]|\(.*?\)/g, ' ').split(/[^a-z]+/).filter(w => w.length > 3);
        let best = null, bs = 0;
        for (const m of menu) { const sc = words(m).filter(w => plain.includes(w)).length; if (sc > bs) { bs = sc; best = m; } }
        entries.push({ cate, title: best || plainText(first).trim().slice(0, 28) });
      }
      for (let n = 1; n <= 20; n++) {
        const s = await strings.resolve({ group: 'NORMAL', cate: 2600, code: n });
        if (s && (await H(4200 + n, 1)) != null) entries.push({ cate: 4200 + n, title: s });
      }
      d.entries = entries;
      const list = win.control('list_tutorial');
      list.setItems(entries.map(e => ({ text: e.title, data: e })));
      list.on('select', (i, it) => open(it?.data));
      async function open(e) {
        if (!e) return;
        d.cur = e; d.page = 1;
        let n = 0;
        while (n < 20 && (await H(e.cate, n + 1)) != null) n++;
        d.pages = n;
        paint();
      }
      async function paint() {
        const e = d.cur;
        win.control('lbl_subTitle').setText(e?.title || '');
        renderRich(win.control('textbox'), e ? (await H(e.cate, d.page)) || '' : '');
        win.control('lbl_pageNum').setText(`${d.pages ? d.page : 0}/${d.pages || 0}`);
        win.control('btn_leftArrow').setEnabled(d.page > 1);
        win.control('btn_rightArrow').setEnabled(d.page < d.pages);
      }
      win.control('btn_leftArrow').onClick(() => { if (d.page > 1) { d.page--; paint(); } });
      win.control('btn_rightArrow').onClick(() => { if (d.page < d.pages) { d.page++; paint(); } });
      d.open = open;
    },
    onOpen(win) { const d = win.data; if (!d.cur && d.entries?.length) { win.control('list_tutorial').select(0); d.open(d.entries[0]); } },
  });

  // ---------------------------------------------------------------- Contents time table
  game.uiwin.registerWindow('contents', {
    script: 'game2/notice/ui_contentsnoticerenewwnd.txt',
    async create(win) {
      const d = win.data;
      d.rows = await fetchCSVObjects('script/contents_timetable.csv').catch(() => []);
      d.lines = [];
      const tabs = ['btn_tab1', 'btn_tab2', 'btn_tab3', 'btn_tab4', 'btn_tab5'];
      tabs.forEach((b, i) => win.control(b).onClick(() => show(i + 1)));
      const bg = win.control('pan_bg');
      function show(tab) {
        tabs.forEach((b, i) => win.control(b).setChecked(i + 1 === tab));
        for (const l of d.lines) l.remove();
        d.lines = [];
        const rows = d.rows.filter(r => Number(r.TAB) === tab);
        // columns: tab 4 (DK Square) uses the Channel / Entry Location / Castle Name captions
        const alt = tab === 4;
        for (const id of ['lbl_column_time', 'lbl_column_endtime', 'lbl_column_subject', 'lbl_column_map', 'lbl_column_level']) win.control(id).setVisible(!alt || /time/.test(id));
        for (const id of ['lbl_column_subject3', 'lbl_column_map3', 'lbl_column_level3']) win.control(id).setVisible(alt);
        const tpl = win.control('pan_list');
        const mid = win.control('pan_mid');
        const n = Math.max(1, rows.length);
        tpl.setVisible(false);
        rows.forEach((r, i) => {
          const y = 55 + i * 25;
          // the top piece (130 px) holds the first three rows; each further row adds an Add_Mid piece
          if (y + 25 > 130) d.lines.push(mid.cloneAs(`_${i}`, { x: 0, y, parent: bg }));
          const row = tpl.cloneAs(`_${i}`, { x: 88, y, parent: bg });
          const week = String(r.week || '').trim();
          win.control(`lbl_time_${i}`).setText(`${week ? `${week} ` : ''}${r.Time || ''}`);
          win.control(`lbl_endtime_${i}`).setText(r.EndTime || '');
          win.control(`lbl_subject_${i}`).setText(r.Name || '');
          win.control(`lbl_map_${i}`).setText(r.Map || '');
          win.control(`lbl_level_${i}`).setText(r.Level || '');
          d.lines.push(row);
        });
        // the frame grows with the rows (Add_Mid pieces), bottom piece below the last row
        const h = Math.max(130, 55 + n * 25);
        win.control('pan_bottom').setRect(0, h, 620, 25);
        win.control('pan_bg').setRect(0, 0, 620, h + 25);
      }
      d.show = show;
    },
    onOpen(win) { win.data.show?.(1); },
  });
}
