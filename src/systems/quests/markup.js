// Client text markup of quest / NPC strings (docs/formats/quests.md §3.6, dialogs.json `markup`):
//   \n (also the tables' "\" line joins) new line; <color=RRGGBB>..</color> (also 0xRRGGBB / AARRGGBB); <font=N>..</font>;
//   <center>; <img screen=.. index=.. width=.. height=..>; [nlink]N[/nlink] NPC name (link); [mlink]N[/mlink] monster;
//   [ilink]N[/ilink] item (tooltip); [elink]N[/elink][Label] link to NPC N shown as Label; [Label][vlink]N[/vlink] link
//   to monster N shown as Label. Placeholders (<COUNTk>, <MAX_COUNTk>, <Object_k>, <code N>, <Quest_Index>, <TITLE>,
//   <COUNT>, <MAX_COUNT>) are filled by fillPlaceholders() before parsing.
// elink/vlink also take the [Label] on the other side ([Label][elink]N[/elink], [vlink]N[/vlink][Label]); a tag with no
// adjacent [Label] shows nothing. Global's stringtable_quest_objectstring.txt gives the same objectives without tags.
// Colour and font apply until </color> / </font> or the end of the line (the client draws line by line: every line
// starts in the control's colour and font, which is why the tables repeat <color=..> on each line).

/** Normalise line breaks: CRLF, and the string tables' trailing "\" joins. */
export function normalizeText(s) {
  return String(s ?? '').replace(/\r\n?/g, '\n').replace(/\\\\?\n/g, '\n').replace(/\\n/g, '\n');
}

const TOKEN = /<color\s*=\s*(?:0x|#)?([0-9a-f]{6,8})\s*>|<\/color>|<font\s*=\s*(\d+)\s*>|<\/font>|<center>|<\/center>|<img\s+([^>]*)>|\[nlink\](\d+)\[\/nlink\]|\[mlink\](\d+)\[\/mlink\]|\[ilink\](\d+)\[\/ilink\]|\[elink\](\d+)\[\/elink\]\[([^\]]*)\]|\[([^\][]*)\]\[vlink\](\d+)\[\/vlink\]|\[([^\][]*)\]\[elink\](\d+)\[\/elink\]|\[vlink\](\d+)\[\/vlink\]\[([^\]]*)\]|[ \t]*\[(elink|vlink)\](\d+)\[\/\15\](?!\[)|\n/gi;

/**
 * Parse markup into lines of runs.
 * @returns {Array<{center:boolean, runs:Array<{text, color, font, link?:{kind:'npc'|'monster'|'item', id}, img?:{screen,index,w,h}}>}>}
 */
export function parseMarkup(text, names = {}) {
  const s = normalizeText(text);
  const lines = [];
  let line = { center: false, runs: [] };
  let colors = [], fonts = [];
  const cur = () => ({ color: colors[colors.length - 1] || null, font: fonts[fonts.length - 1] ?? null });
  const push = (t, extra) => { if (t || extra) line.runs.push({ text: t || '', ...cur(), ...(extra || {}) }); };
  const nm = (kind, id) => {
    const f = names[kind];
    try { const v = f?.(Number(id)); if (v) return String(v); } catch { /* ignore */ }
    return String(id);
  };
  let last = 0, m;
  TOKEN.lastIndex = 0;
  while ((m = TOKEN.exec(s))) {
    push(s.slice(last, m.index));
    last = TOKEN.lastIndex;
    const tok = m[0];
    if (tok === '\n') { lines.push(line); line = { center: false, runs: [] }; colors = []; fonts = []; continue; }
    if (m[1]) { colors.push(`#${m[1].slice(-6)}`); continue; }
    if (/^<\/color>/i.test(tok)) { colors.pop(); continue; }
    if (m[2]) { fonts.push(Number(m[2])); continue; }
    if (/^<\/font>/i.test(tok)) { fonts.pop(); continue; }
    if (/^<center>/i.test(tok)) { line.center = true; continue; }
    if (/^<\/center>/i.test(tok)) continue;
    if (m[3] != null) {
      const a = {};
      for (const p of m[3].matchAll(/(\w+)\s*=\s*"?([^\s">]+)"?/g)) a[p[1].toLowerCase()] = p[2];
      if (a.screen) push('', { img: { screen: a.screen, index: Number(a.index) || 0, w: Number(a.width) || 0, h: Number(a.height) || 0 } });
      continue;
    }
    if (m[4]) { push(nm('npc', m[4]), { link: { kind: 'npc', id: Number(m[4]) } }); continue; }
    if (m[5]) { push(nm('monster', m[5]), { link: { kind: 'monster', id: Number(m[5]) } }); continue; }
    if (m[6]) { push(nm('item', m[6]), { link: { kind: 'item', id: Number(m[6]) } }); continue; }
    if (m[7]) { push(m[8] || nm('npc', m[7]), { link: { kind: 'npc', id: Number(m[7]) } }); continue; }
    if (m[10]) { push(m[9] || nm('monster', m[10]), { link: { kind: 'monster', id: Number(m[10]) } }); continue; }
    if (m[12]) { push(m[11] || nm('npc', m[12]), { link: { kind: 'npc', id: Number(m[12]) } }); continue; }
    if (m[13]) { push(m[14] || nm('monster', m[13]), { link: { kind: 'monster', id: Number(m[13]) } }); continue; }
    if (m[16]) continue;
  }
  push(s.slice(last));
  lines.push(line);
  return lines;
}

/** Plain text (chat lines, tooltips): links resolved to names, tags dropped, "[message]" prefix removed. */
export function plainText(text, names = {}) {
  return parseMarkup(String(text ?? '').replace(/^\s*\[message\]\s*/i, ''), names)
    .map(l => l.runs.map(r => r.text).join('')).join('\n');
}

/**
 * Render parsed lines into `parent` (DOM). opts: {font, color, lineHeight, applyFont(el, idx, lh), onLink(link, ev),
 * sprite(el, screen, index, w, h), linkColor}. Returns the created line elements.
 */
export function renderMarkup(parent, text, names = {}, opts = {}) {
  const els = [];
  for (const ln of parseMarkup(text, names)) {
    const d = document.createElement('div');
    d.className = 'qm-line';
    d.style.minHeight = `${opts.lineHeight || 16}px`;
    d.style.whiteSpace = 'pre-wrap';
    d.style.wordBreak = 'break-word';
    if (ln.center) d.style.textAlign = 'center';
    for (const r of ln.runs) {
      if (r.img) {
        const im = document.createElement('span');
        im.style.display = 'inline-block';
        im.style.verticalAlign = 'middle';
        im.style.width = `${r.img.w || 16}px`; im.style.height = `${r.img.h || 16}px`;
        opts.sprite?.(im, r.img.screen, r.img.index, r.img.w, r.img.h);
        d.appendChild(im);
        continue;
      }
      const sp = document.createElement('span');
      sp.textContent = r.text;
      if (r.font != null && opts.applyFont) opts.applyFont(sp, r.font, opts.lineHeight || 0);
      if (r.color) sp.style.color = r.color;
      if (r.link) {
        sp.className = `qm-link qm-${r.link.kind}`;
        sp.style.pointerEvents = 'auto';
        sp.style.cursor = 'pointer';
        if (!r.color && opts.linkColor) sp.style.color = opts.linkColor;
        sp.addEventListener('pointerdown', e => e.stopPropagation());
        sp.addEventListener('click', e => { e.stopPropagation(); opts.onLink?.(r.link, e); });
        if (opts.linkTitle) { const t = opts.linkTitle(r.link); if (t) sp.title = t; }
      }
      d.appendChild(sp);
    }
    parent.appendChild(d);
    els.push(d);
  }
  return els;
}

/**
 * Fill the quest placeholders. ctx: {counts:[..], max:[..], objectLabel(k), code(n), questIndex, title, count, maxCount}
 */
export function fillPlaceholders(text, ctx = {}) {
  return String(text ?? '')
    .replace(/<COUNT(\d)>/gi, (m, k) => String(ctx.counts?.[k] ?? 0))
    .replace(/<MAX_COUNT(\d)>/gi, (m, k) => String(ctx.max?.[k] ?? 0))
    .replace(/<Object_(\d)>/gi, (m, k) => String(ctx.objectLabel?.(Number(k)) ?? ''))
    .replace(/<code\s+(\d+)>/gi, (m, n) => String(ctx.code?.(Number(n)) ?? ''))
    .replace(/<Quest_Index>/gi, () => String(ctx.questIndex ?? ''))
    .replace(/<TITLE>/g, () => String(ctx.title ?? ''))
    .replace(/<COUNT>/g, () => String(ctx.count ?? 0))
    .replace(/<MAX_COUNT>/g, () => String(ctx.maxCount ?? 0));
}
