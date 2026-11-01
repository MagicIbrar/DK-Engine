// Client string tables for the window scripts (docs/formats/gmcommands.md §3.3).
//   title `text2 cate code`    -> group NORMAL (then COMMON)
//   title `text3 cate code`    -> group SYSTEM
//   title `text_pet cate code` -> group PET
//   control `tooltip cate code` -> NORMAL, `tooltip_pet` -> PET, item `string cate code` -> NORMAL
// script/string/list.txt assigns every table file to a group; the "# 21, 22, ..." comment above each entry lists
// the cates that file holds, which lets a lookup fetch just that file. (cate, code) is unique only within a
// group; files are searched in list order, first match wins. Unknown cates fall back to every file of the group.
import { fetchText } from '../../engine/assets.js';

const LIST = 'script/string/list.txt';

/** Parse list.txt -> [{group, file, cates:number[]|null}] (file relative to script/, e.g. 'string/normal/stringtable_title.txt'). */
export function parseStringList(text) {
  const out = [];
  let hint = null;
  for (const raw of String(text || '').split(/\r\n|\n|\r/)) {
    const s = raw.trim();
    if (!s) continue;
    if (s.startsWith('#')) {
      const nums = (s.slice(1).match(/\d+/g) || []).map(Number);
      hint = nums.length ? nums : null;
      continue;
    }
    const m = /^([A-Z_0-9]+)\s*,\s*(\S+\.txt)/i.exec(s);
    if (!m) continue;
    out.push({ group: m[1].toUpperCase(), file: m[2].replace(/\\/g, '/').toLowerCase(), cates: hint });
    hint = null;
  }
  return out;
}

/** Parse a string table -> Map<'cate:code', text>. Multi-line {...} blocks keep their inner line breaks. */
export function parseStringTableCates(text) {
  const out = new Map();
  let cate = 0, code = null, acc = null;
  for (const raw of String(text || '').split(/\r\n|\n|\r/)) {
    const s = raw.trim();
    if (acc) {
      if (s === '}' || s.endsWith('}') && !s.includes('{')) {
        if (s !== '}') acc.push(raw.replace(/\s*}\s*$/, ''));
        while (acc.length && !acc[0].trim()) acc.shift();
        while (acc.length && !acc[acc.length - 1].trim()) acc.pop();
        out.set(`${cate}:${code}`, acc.map(l => l.replace(/^\t+/, '').replace(/\s+$/, '')).join('\n'));
        acc = null;
      } else acc.push(raw);
      continue;
    }
    let m;
    if ((m = /^<cate>\s*(-?\d+)/i.exec(s))) { cate = Number(m[1]); continue; }
    if ((m = /^code\s+(-?\d+)/i.exec(s))) { code = Number(m[1]); continue; }
    if (s.startsWith('{') && code != null) {
      const rest = s.slice(1).trim();
      if (rest.endsWith('}')) { out.set(`${cate}:${code}`, rest.slice(0, -1).trim()); continue; }
      acc = rest ? [rest] : [];
    }
  }
  return out;
}

const GROUP_CHAIN = { NORMAL: ['NORMAL', 'COMMON'], CASHITEM: ['NORMAL'] };

export class StringTables {
  constructor() {
    this.list = null;
    this._listP = null;
    this._files = new Map();     // file -> Promise<Map>
    this._loaded = new Map();    // file -> Map (sync access)
  }

  loadList() {
    if (!this._listP) {
      this._listP = fetchText(LIST, true).then(t => { this.list = parseStringList(t); return this.list; })
        .catch(() => { this.list = []; return this.list; });
    }
    return this._listP;
  }

  _file(file) {
    if (!this._files.has(file)) {
      this._files.set(file, fetchText(`script/${file}`, true).then(t => {
        const m = parseStringTableCates(t); this._loaded.set(file, m); return m;
      }).catch(() => { const m = new Map(); this._loaded.set(file, m); return m; }));
    }
    return this._files.get(file);
  }

  _candidates(ref) {
    const groups = GROUP_CHAIN[String(ref.group || 'NORMAL').toUpperCase()] || [String(ref.group).toUpperCase()];
    const out = [];
    for (const g of groups) {
      const entries = (this.list || []).filter(e => e.group === g);
      const hinted = entries.filter(e => e.cates && e.cates.includes(Number(ref.cate)));
      out.push(...(hinted.length ? hinted : entries));
    }
    return out;
  }

  /** Make sure the files that can hold these refs are loaded (then get() works synchronously). */
  async need(refs) {
    await this.loadList();
    const files = new Set();
    for (const r of refs) if (r) for (const e of this._candidates(r)) files.add(e.file);
    await Promise.all([...files].map(f => this._file(f)));
  }

  /** Synchronous lookup (null when not loaded / not found). */
  get(ref) {
    if (!ref || !this.list) return null;
    for (const e of this._candidates(ref)) {
      const m = this._loaded.get(e.file);
      const v = m?.get(`${ref.cate}:${ref.code}`);
      if (v != null) return v;
    }
    // hinted files may not hold it: search every loaded file of the group chain
    return null;
  }

  /** Async lookup: loads what is needed. */
  async resolve(ref) {
    await this.need([ref]);
    let v = this.get(ref);
    if (v == null) {
      // the cate hint was wrong or missing: load the whole group once
      const groups = GROUP_CHAIN[String(ref.group).toUpperCase()] || [String(ref.group).toUpperCase()];
      await Promise.all((this.list || []).filter(e => groups.includes(e.group)).map(e => this._file(e.file)));
      for (const g of groups) for (const e of (this.list || []).filter(x => x.group === g)) {
        const m = this._loaded.get(e.file); const t = m?.get(`${ref.cate}:${ref.code}`);
        if (t != null) return t;
      }
    }
    return v;
  }
}

/** Shared instance. */
export const strings = new StringTables();

/**
 * printf-style fill of client strings: %d %s %u %f %.1f %% and %1..%9, in order.
 *   formatString('Level %d', 5) -> 'Level 5'
 */
export function formatString(fmt, ...args) {
  let i = 0;
  // named placeholders of the client strings (<VALUE>, <NAME>, <COUNT>...): an object argument fills them by name,
  // otherwise they take the positional arguments in order (after any printf specs)
  const named = args.length === 1 && args[0] && typeof args[0] === 'object' && !Array.isArray(args[0]) ? args[0] : null;
  if (named) return String(fmt ?? '').replace(/<([A-Za-z_][A-Za-z_0-9]*)>/g, (m, k) => (k in named ? String(named[k]) : k.toUpperCase() in named ? String(named[k.toUpperCase()]) : m));
  const out = String(fmt ?? '').replace(/%(%|\d(?!\d)|[-+ 0#]*\d*(?:\.\d+)?[dsuifxXcl]+)/g, (m, spec) => {
    if (spec === '%') return '%';
    if (/^\d$/.test(spec)) { const v = args[Number(spec) - 1]; return v == null ? m : String(v); }
    const v = args[i++];
    if (v == null) return m;
    const pm = /\.(\d+)f/.exec(spec);
    if (pm) return Number(v).toFixed(Number(pm[1]));
    if (/[di]/.test(spec)) return String(Math.trunc(Number(v)));
    return String(v);
  });
  if (i >= args.length) return out;
  return out.replace(/<([A-Z_][A-Z_0-9]*)>/g, (m) => (i < args.length ? String(args[i++]) : m));
}

/**
 * Split client markup into styled runs: <color=RRGGBB>..</color>, <#RRGGBB>, [c=RRGGBB], \n.
 * @returns {Array<{text:string, color:string|null, br?:true}>}
 */
export function markupRuns(text) {
  const runs = [];
  const stack = [];
  const re = /<color\s*=\s*#?([0-9a-f]{6,8})>|<\/color>|<#([0-9a-f]{6})>|\n/gi;
  let last = 0, m;
  const s = String(text ?? '');
  const push = (t) => { if (t) runs.push({ text: t, color: stack[stack.length - 1] || null }); };
  while ((m = re.exec(s))) {
    push(s.slice(last, m.index));
    last = re.lastIndex;
    if (m[0] === '\n') runs.push({ text: '', color: null, br: true });
    else if (m[1]) stack.push(`#${m[1].slice(-6)}`);
    else if (m[2]) stack.push(`#${m[2]}`);
    else stack.pop();
  }
  push(s.slice(last));
  return runs;
}
