// GM command parser (docs/formats/gmcommands.md §6.1): "/gm <command> <args…>" or a bare alias ("/call", "/item",
// "/move" ...). Tokens are space separated, "…" quotes a value with spaces, the last `text` argument takes the rest of
// the line. Each argument is coerced by its registry type: enums case-insensitive, numbers within min..max, list
// arguments by id or (case-insensitive) name: exact, unique prefix, then substring; ambiguous names list up to 10.
// Errors use the client's console strings 160:60 "This value is invalid.", 160:61 "No such mode exists." and
// 160:62 "Failed to execute the command.".
import { gmData, GMData } from './data.js';

export const ERR = { invalid: [160, 60, 'This value is invalid.'], mode: [160, 61, 'No such mode exists.'], failed: [160, 62, 'Failed to execute the command.'] };

/** Split a command line into tokens; quotes group words. Returns [{t, start}] with the source offset of each token. */
export function tokenize(line) {
  const out = [];
  const s = String(line || '');
  let i = 0;
  while (i < s.length) {
    while (i < s.length && /\s/.test(s[i])) i++;
    if (i >= s.length) break;
    const start = i;
    if (s[i] === '"') {
      const j = s.indexOf('"', i + 1);
      const end = j < 0 ? s.length : j;
      out.push({ t: s.slice(i + 1, end), start, quoted: true });
      i = end + 1;
    } else {
      let j = i;
      while (j < s.length && !/\s/.test(s[j])) j++;
      out.push({ t: s.slice(i, j), start });
      i = j;
    }
  }
  return out;
}

/**
 * Which command does a chat line invoke? Returns { cmd, rest (tokens after the command word), line } or null.
 * `/gm` alone -> { panel: true }.
 */
export function matchLine(line, data = gmData) {
  const text = String(line || '').trim();
  if (!text) return null;
  const toks = tokenize(text);
  if (!toks.length) return null;
  const w0 = toks[0].t.toLowerCase();
  if (w0 === '/gm' || w0 === 'gm') {
    if (toks.length === 1) return { panel: true, line: text };
    const w1 = toks[1].t.toLowerCase();
    const cmd = data.command(w1) || data.extra?.get(w1) || null;
    return { cmd, word: w1, rest: toks.slice(2), line: text, restText: text.slice(toks[1].start + toks[1].t.length).trim() };
  }
  if (w0 === '`') { const cmd = data.command('console'); return { cmd, word: '`', rest: toks.slice(1), line: text, restText: '' }; }
  if (w0.startsWith('/')) {
    const cmd = data.bareAlias(w0);
    if (cmd && cmd.category !== 'player' && cmd.id !== 'console') return { cmd, word: w0, rest: toks.slice(1), line: text, restText: text.slice(toks[0].t.length).trim() };
  }
  return null;
}

const ON = new Set(['on', '1', 'true', 'yes', 'y', 'enable', 'enabled']);
const OFF = new Set(['off', '0', 'false', 'no', 'n', 'disable', 'disabled']);

/** Coerce a boolean token (null when not a boolean word). */
export function boolOf(t) { const s = String(t ?? '').toLowerCase(); return ON.has(s) ? true : OFF.has(s) ? false : null; }

class ArgError extends Error { constructor(kind, detail) { super(detail || kind); this.kind = kind; this.detail = detail; } }

/** Resolve a list token (greedy over several words for names with spaces). Returns {row, used} or throws. */
async function resolveList(listId, toks, i, reserve, data) {
  const lists = Array.isArray(listId) ? listId : [listId];
  // prefixes for the two-list argument (droptable): "m:102" / "i:3805" / "item:..."
  let want = lists;
  let first = toks[i]?.t ?? '';
  const pm = /^(m|mon|monster|i|item):(.*)$/i.exec(first);
  if (pm && lists.length > 1) { want = [/^m/i.test(pm[1]) ? 'monsters' : 'items']; first = pm[2]; }
  const maxWords = Math.max(1, toks.length - i - reserve);
  for (const L of want) {
    const rows = await data.list(L);
    // 1) exact id / exact name over the longest run of words first
    for (let n = Math.min(maxWords, 8); n >= 1; n--) {
      const words = toks.slice(i, i + n).map((t, k) => (k === 0 ? first : t.t)).join(' ');
      const r = rows.byId.get(words) || (/^-?\d+$/.test(words) ? rows.byId.get(String(Number(words))) : null);
      if (r) return { row: r, used: n, list: L };
      const q = words.toLowerCase();
      const ex = rows.find(x => x.name.toLowerCase() === q);
      if (ex) return { row: ex, used: n, list: L };
    }
  }
  // 2) prefix / substring on the longest run that is unique
  for (const L of want) {
    for (let n = Math.min(maxWords, 8); n >= 1; n--) {
      const words = toks.slice(i, i + n).map((t, k) => (k === 0 ? first : t.t)).join(' ');
      const f = await data.find(L, words);
      if (f.row && !f.many) return { row: f.row, used: n, list: L };
      if (f.many && n === 1) throw new ArgError('ambiguous', f.many.slice(0, 10).map(r => `${r.id} ${r.name}`).join(' | '));
    }
  }
  throw new ArgError('invalid', `no ${want.join('/')} matches "${toks.slice(i, i + Math.min(maxWords, 3)).map(t => t.t).join(' ')}"`);
}

/** Minimum tokens the arguments after index k still need. */
const need = (args, k) => args.slice(k + 1).filter(a => !a.optional).length;

/**
 * Coerce the tokens of a command into an args object { name: value }. List args give the row object (with .id).
 * Throws ArgError {kind: 'invalid'|'mode'|'ambiguous'|'missing'}.
 */
export async function coerceArgs(cmd, toks, restText = '', data = gmData) {
  const out = {};
  const args = cmd.args || [];
  let i = 0;
  for (let k = 0; k < args.length; k++) {
    const a = args[k];
    const tok = toks[i];
    if (!tok) {
      if (a.optional || a.default != null) { if (a.default != null) out[a.name] = a.default; continue; }
      throw new ArgError('missing', `missing <${a.name}>`);
    }
    const t = tok.t;
    switch (a.type) {
      case 'enum': {
        const v = (a.enum || []).find(e => e.toLowerCase() === t.toLowerCase())
          || (a.enum?.includes('on') && boolOf(t) != null ? (boolOf(t) ? 'on' : 'off') : null);
        if (!v) {
          if (a.optional) continue;   // leave the token for the next argument
          throw new ArgError('mode', `<${a.name}> must be ${(a.enum || []).join('|')}`);
        }
        out[a.name] = v; i++; break;
      }
      case 'int': case 'float': case 'cell': {
        const n = Number(t);
        if (!Number.isFinite(n)) {
          if (a.optional) continue;
          throw new ArgError('invalid', `<${a.name}> must be a number`);
        }
        const v = a.type === 'int' ? Math.trunc(n) : n;
        if ((a.min != null && v < a.min) || (a.max != null && v > a.max)) throw new ArgError('invalid', `<${a.name}> ${a.min ?? ''}..${a.max ?? ''}`);
        out[a.name] = v; i++; break;
      }
      case 'bool': {
        const b = boolOf(t);
        if (b == null) { if (a.optional) continue; throw new ArgError('invalid', `<${a.name}> must be on|off`); }
        out[a.name] = b; i++; break;
      }
      case 'text': {
        // the last text argument takes the rest of the line
        const last = !args.slice(k + 1).some(x => !x.optional);
        if (last) { out[a.name] = toks.slice(i).map(x => (x.quoted ? `"${x.t}"` : x.t)).join(' ').replace(/^"(.*)"$/, '$1'); i = toks.length; }
        else { out[a.name] = t; i++; }
        if (a.max != null && String(out[a.name]).length > a.max) out[a.name] = String(out[a.name]).slice(0, a.max);
        break;
      }
      case 'player': {
        out[a.name] = t; i++; break;
      }
      default: {
        if (a.list) {
          if (a.repeat) {
            // repeated [list value] pairs (makeitem options)
            const list = [];
            while (i < toks.length && list.length < a.repeat) {
              const r = await resolveList(a.list, toks, i, 1, data);
              i += r.used;
              const v = Number(toks[i]?.t);
              if (!Number.isFinite(v)) throw new ArgError('invalid', `option ${r.row.id} needs a value`);
              i++;
              list.push([r.row, v]);
            }
            out[a.name] = list;
            break;
          }
          const r = await resolveList(a.list, toks, i, need(args, k), data);
          out[a.name] = r.row; if (r.list) out[`${a.name}List`] = r.list;
          i += r.used;
          break;
        }
        out[a.name] = t; i++;
      }
    }
  }
  if (i < toks.length && !args.some(a => a.type === 'text')) out._extra = toks.slice(i).map(x => x.t);
  return out;
}

/** Build the chat line of a command from args (panel "copy as command"). */
export function lineOf(cmd, args = {}) {
  const m = /^\/gm\s+(\S+)/.exec(cmd.syntax || '');
  const head = m ? `/gm ${m[1]}` : `/gm ${cmd.id}`;
  const parts = [head];
  for (const a of cmd.args || []) {
    const v = args[a.name];
    if (v == null || v === '') continue;
    if (Array.isArray(v)) { for (const [r, x] of v) parts.push(String(r?.id ?? r), String(x)); continue; }
    const s = typeof v === 'object' ? String(v.id) : String(v);
    parts.push(/\s/.test(s) ? `"${s}"` : s);
  }
  return parts.join(' ');
}

export { ArgError, GMData };
