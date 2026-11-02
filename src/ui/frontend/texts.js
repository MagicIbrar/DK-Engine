// The client's own strings (EU English): window scripts refer to them as `text2 <cate> <code>`.
// script/string/list.txt says which file holds which categories ("# 30, 31" above "NORMAL,string/normal/
// stringtable_loginmsg.txt"); a category is loaded from exactly that file, so duplicated category numbers in other
// files (e.g. <cate> 100 of stringtable_system.txt) do not override it, as in the client.
//   30/31 login / select / create + armour-set names   2000 buttons   100 window titles   80/81 message boxes
// Format (EUC-KR text): "<cate> N" starts a category, "code N" a string, the text sits between "{" and "}" (it may
// also be inline: code 16 {Select Class}). "\n" inside a string is a line break; <center> and <color=rrggbb>..</color>
// are inline markup (toHTML). script/loading_map_info.csv holds the loading-screen tips (Map_Index 65535 = any map).
import { fetchText, fetchCSV } from '../../engine/assets.js';

export const STRING_LIST = 'script/string/list.txt';
export const LOADING_TIPS = 'script/loading_map_info.csv';
/** Bundled Global tip strings when script/loading_map_info.csv is missing from the served data. */
export const TIPS_FALLBACK = '/src/ui/frontend/tips.json';
/** Categories the front-end needs. */
export const FRONT_CATES = [30, 31, 2000, 100, 101, 80, 81];

/** Parse a categorised string table -> Map('cate:code' -> text). Later duplicates win. */
export function parseCategorised(text) {
  const out = new Map();
  let cate = 0, code = null, buf = null;
  const put = s => { if (code != null) out.set(`${cate}:${code}`, s); };
  for (const raw of String(text || '').split(/\r?\n/)) {
    const line = raw.replace(/\s+$/, '');
    if (buf) {
      const close = line.lastIndexOf('}');
      if (close >= 0 && !/\{/.test(line.slice(0, close))) {
        const last = line.slice(0, close);
        if (last.trim()) buf.push(last);
        while (buf.length && !buf[0].trim()) buf.shift();
        while (buf.length && !buf[buf.length - 1].trim()) buf.pop();
        put(buf.map(s => s.replace(/^\t+/, '')).join('\n'));
        buf = null; code = null;
      } else buf.push(line);
      continue;
    }
    let m = /^\s*<cate>\s+(-?\d+)/i.exec(line);
    if (m) { cate = Number(m[1]); continue; }
    m = /^\s*code\s+(-?\d+)[^{]*(\{(.*))?$/i.exec(line);
    if (m) {
      code = Number(m[1]);
      if (m[2] != null) {
        const rest = m[3];
        const close = rest.lastIndexOf('}');
        if (close >= 0) { put(rest.slice(0, close).trim()); code = null; }
        else buf = rest.trim() ? [rest] : [];
      }
      continue;
    }
    const open = line.indexOf('{');
    if (open >= 0 && code != null) {
      const rest = line.slice(open + 1);
      const close = rest.lastIndexOf('}');
      if (close >= 0) { put(rest.slice(0, close).trim()); code = null; }
      else buf = rest.trim() ? [rest] : [];
    }
  }
  return out;
}

/** list.txt -> Map(cate -> file key). */
export function parseStringList(text) {
  const out = new Map();
  let pending = [];
  for (const raw of String(text || '').split(/\r?\n/)) {
    const line = raw.trim();
    if (!line) continue;
    if (line.startsWith('#')) { pending = (line.slice(1).match(/\d+/g) || []).map(Number); continue; }
    const m = /^[A-Z]+\s*,\s*(.+)$/i.exec(line);
    if (m) {
      const key = `script/${m[1].trim().replace(/\\/g, '/')}`.toLowerCase();
      for (const c of pending) if (!out.has(c)) out.set(c, key);
      pending = [];
    }
  }
  return out;
}

/** Literal "\n" sequences -> real line breaks. */
export function unescapeText(s) {
  return String(s ?? '').replace(/\\n/g, '\n');
}

const esc = s => String(s).replace(/[&<>"']/g, c => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;', "'": '&#39;' }[c]));

/**
 * Client markup -> safe HTML: <center> (the line is centred), <color=rrggbb>...</color>, "\n" line breaks.
 * Everything else is escaped.
 */
export function toHTML(s) {
  const lines = unescapeText(s).split('\n');
  if (lines.length === 1 && !/<center>/i.test(lines[0])) return inline(lines[0]);
  return lines.map(line => {
    let center = false;
    line = line.replace(/<center>/gi, () => { center = true; return ''; });
    const html = inline(line);
    return center ? `<div style="text-align:center">${html || '&nbsp;'}</div>` : `<div>${html || '&nbsp;'}</div>`;
  }).join('');
}

function inline(line) {
  let html = '';
  const re = /<color=([0-9a-f]{6,8})>|<\/color>/gi;
  let last = 0, m, open = 0;
  while ((m = re.exec(line))) {
    html += esc(line.slice(last, m.index));
    if (m[1]) { html += `<span style="color:#${m[1].slice(-6)}">`; open++; } else if (open) { html += '</span>'; open--; }
    last = re.lastIndex;
  }
  html += esc(line.slice(last));
  while (open-- > 0) html += '</span>';
  return html;
}

/** Plain text (markup stripped). */
export function toPlain(s) {
  return unescapeText(s).replace(/<\/?(center|color[^>]*)>/gi, '');
}

// English fallbacks (the same wording as the EU tables) so the UI works before / without the files.
const FALLBACK = {
  '30:16': 'Select Class', '30:18': 'Back', '30:21': 'Character', '30:22': 'New', '30:23': 'Delete', '30:24': 'Connect',
  '30:25': 'Log Out', '30:26': 'Log In', '30:27': 'ID', '30:28': 'PW', '30:29': 'Server', '30:30': 'Exit',
  '30:48': '<center>You cannot create any more characters\n<center>because your character slots are full.',
  '30:51': 'Please enter a character name.', '30:54': 'Only alphanumeric characters can be used.',
  '30:55': 'Spaces are not allowed.', '30:59': 'This name is already in use.', '30:61': 'Do you really want to delete?',
  '30:131': 'Please enter a name.', '30:202': 'Information', '30:203': 'Preview', '30:208': 'Standard', '30:209': 'Arena',
  '2000:13': 'Exit Game', '2000:14': 'Cancel', '2000:15': 'Ok', '2000:22': 'Confirm', '2000:79': 'Exit Game',
  '2000:80': 'Server Login', '100:63': 'Delete Character',
  '30:123': '<color=ff0000>Deletion</color>\n<color=ff0000>in progress</color>\n%s', '30:124': '<color=00ff00>Deletion</color>\n<color=00ff00>in Progress</color>',
  '30:125': 'Cancel Deletion', '30:126': 'Delete',
  '101:17': 'Day(s)', '101:18': 'Hour(s)', '101:19': 'Minute(s)', '101:20': 'Second(s)',
};

export class Texts {
  constructor() {
    this.map = new Map(Object.entries(FALLBACK));
    this.tips = [];
    this._loading = null;
    this._files = new Map();
    this._list = null;
  }

  /** Load a string-table file once (never rejects). */
  _file(key) {
    if (!this._files.has(key)) this._files.set(key, fetchText(key, true).then(parseCategorised).catch(() => new Map()));
    return this._files.get(key);
  }

  /** Make sure these categories are loaded (from the files list.txt names). */
  async ensure(cates) {
    if (!this._list) this._list = fetchText(STRING_LIST, true).then(parseStringList).catch(() => new Map());
    const list = await this._list;
    const files = [...new Set(cates.map(c => list.get(Number(c))).filter(Boolean))];
    const maps = await Promise.all(files.map(f => this._file(f).then(m => ({ f, m }))));
    for (const { f, m } of maps) {
      for (const [k, v] of m) {
        const cate = Number(k.split(':')[0]);
        if (list.get(cate) === f) this.map.set(k, v);    // only the categories this file owns
      }
    }
    return this;
  }

  /** Load the front-end categories and the loading tips (never rejects). */
  load() {
    if (!this._loading) {
      this._loading = this.ensure(FRONT_CATES)
        .then(() => fetchCSV(LOADING_TIPS, true).catch(() => []))
        .then(async rows => {
          this.tips = rows.slice(1).map(r => {
            const text = r.slice(2).join(',').replace(/,+\s*$/, '').trim();
            return { map: Number(r[1]), text };
          }).filter(t => t.text && Number.isFinite(t.map));
          // Global CSV missing from a thin data slice: use bundled tips.json (Scrubbed Global strings).
          if (!this.tips.length) {
            try {
              const res = await fetch(TIPS_FALLBACK, { cache: 'no-store' });
              if (res.ok) {
                const body = await res.json();
                const list = Array.isArray(body?.tips) ? body.tips : Array.isArray(body) ? body : [];
                this.tips = list.map(tip => ({ map: Number(tip.map), text: String(tip.text || '').trim() }))
                  .filter(tip => tip.text && Number.isFinite(tip.map));
              }
            } catch { /* tips stay empty; load screen keeps the wait line */ }
          }
          return this;
        })
    }
    return this._loading;
  }

  /** Raw string (client markup kept), or the fallback. */
  raw(cate, code, fallback = '') {
    const v = this.map.get(`${cate}:${code}`);
    return v != null ? v : fallback;
  }

  /** Plain text. */
  get(cate, code, fallback = '') { return toPlain(this.raw(cate, code, fallback)); }

  /** Safe HTML. */
  html(cate, code, fallback = '') { return toHTML(this.raw(cate, code, fallback)); }

  /** A loading tip for a map (map-specific ones preferred half of the time), as raw client markup. */
  tipFor(mapIndex, rnd = Math.random) {
    const own = this.tips.filter(t => t.map === Number(mapIndex));
    const any = this.tips.filter(t => t.map === 65535);
    const pool = own.length && (rnd() < 0.5 || !any.length) ? own : any;
    return pool.length ? pool[Math.floor(rnd() * pool.length)].text : '';
  }
}

/** Shared instance. */
export const texts = new Texts();
