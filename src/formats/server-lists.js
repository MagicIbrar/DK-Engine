// share/server lists (FEATURE-CENSUS D11). One on-disk format is known: g1 and the refreshed Global g2 copies are byte-identical
// (2026-10-19). Parsers accept that format with ANSI/cp949 or UTF-16 text and CRLF/LF, and refuse anything else loudly.
// Global evidence (DekaronServer.exe strings, audit/global-re/server-strings): ">>> Loading ServiceObject/Properties/ToolIPList",
// "ServiceObject::Properties::ToolIPList::Provider::LoadIPList", "TOOL_GRADELIST" + ">>> Loading ServiceObject/Roader/GradeList",
// ">>> Loading Ornament/RandomEffect" + "[strRandomEffect::Load]", "Loader\Logic\Arrange\Provider.cpp" + "[Arrange::Load] [Can't find %s]".
// sync.csv has no loader string in DekaronServer.exe (its consumer is unknown; parsed and exposed only).
import { decodeText, parseCSV } from './binreader.js';
const rowsOf = (buf) => parseCSV(typeof buf === 'string' ? buf : decodeText(buf, true)).map(r => r.map(c => String(c ?? '').trim())).filter(r => r.some(Boolean));
const int = (v, what) => { if (!/^-?\d+$/.test(v)) throw new Error(`${what}: expected an integer, got "${v}"`); return Number(v); };
const header = (rows, want, file) => { const h = rows[0] || []; if (want.some((c, i) => (h[i] || '').toLowerCase() !== c.toLowerCase())) throw new Error(`${file}: unsupported header "${h.join(',')}" (expected ${want.join(',')})`); return rows.slice(1); };
const IPV4 = /^(\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3})$/;

/** iplist.csv: IP,Grade — GM tool address list with a grade per address. */
export function parseIpList(buf) {
  return header(rowsOf(buf), ['IP', 'Grade'], 'iplist.csv').map(r => { if (!IPV4.test(r[0])) throw new Error(`iplist.csv: bad IPv4 "${r[0]}"`); return { ip: r[0], grade: int(r[1], 'iplist.csv Grade') }; });
}
/** tooliplist.csv: class,From,To with rows classA..classD — one inclusive range per IPv4 octet (A = first octet). */
export function parseToolIpList(buf) {
  const out = {};
  for (const r of header(rowsOf(buf), ['class', 'From', 'To'], 'tooliplist.csv')) {
    const m = /^class([a-d])$/i.exec(r[0]); if (!m) throw new Error(`tooliplist.csv: unknown class "${r[0]}"`);
    const from = int(r[1], 'tooliplist.csv From'), to = int(r[2], 'tooliplist.csv To');
    if (from < 0 || to > 255 || from > to) throw new Error(`tooliplist.csv: bad range ${from}-${to}`);
    out[m[1].toUpperCase()] = { from, to };
  }
  return out;
}
export function toolIpInRange(ranges, ip) {
  const m = IPV4.exec(String(ip || '')); if (!m || !ranges) return false;
  return ['A', 'B', 'C', 'D'].every((k, i) => !ranges[k] || (Number(m[i + 1]) >= ranges[k].from && Number(m[i + 1]) <= ranges[k].to));
}
/** gradelist.csv: ID,PW,GRADE,<privilege flags...>. The PW column is DROPPED here: it is never returned or stored. */
export function parseGradeList(buf) {
  const rows = rowsOf(buf), h = rows[0] || [];
  if ((h[0] || '').toUpperCase() !== 'ID' || (h[1] || '').toUpperCase() !== 'PW' || (h[2] || '').toUpperCase() !== 'GRADE') throw new Error(`gradelist.csv: unsupported header "${h.slice(0, 3).join(',')}"`);
  const flags = h.slice(3);
  return { privileges: flags, accounts: rows.slice(1).map(r => ({ id: r[0], grade: int(r[2], 'gradelist.csv GRADE'),
    privileges: Object.fromEntries(flags.map((f, i) => [f, int(r[i + 3] || '0', `gradelist.csv ${f}`) !== 0])) })) };
}
/** "Count,N" + "Index,<cols>" lists (sync.csv, arrange.csv). Count is the index SPACE, not the row count: Global's copies say
 *  Count,23 with 21 rows (indices 4 and 9 absent), so every Index must be unique and < Count. Map paths are client-relative. */
function countedList(buf, file, cols) {
  const rows = rowsOf(buf); if ((rows[0]?.[0] || '').toLowerCase() !== 'count') throw new Error(`${file}: missing Count line`);
  const count = int(rows[0][1], `${file} Count`), body = header(rows.slice(1), ['Index', ...cols], file);
  // "..\\Map\\X" is relative to share/server, i.e. share/map/x (verified: every referenced file exists there in g2)
  const norm = (p) => p ? ('share/' + p.replace(/\\/g, '/').replace(/^\.\.\//, '')).toLowerCase() : null;
  const seen = new Set();
  return body.map(r => { const index = int(r[0], `${file} Index`);
    if (index < 0 || index >= count || seen.has(index)) throw new Error(`${file}: Index ${index} outside Count ${count} or duplicated`); seen.add(index);
    return { index, ...Object.fromEntries(cols.map((c, i) => [c.toLowerCase(), norm(r[i + 1])])) }; });
}
/** sync.csv: Count,N / Index,Name — map index -> map attribute file (.mal). */
export const parseSyncList = (buf) => countedList(buf, 'sync.csv', ['Name']);
/** arrange.csv: Count,N / Index,Monster,NPC — map index -> monster and NPC arrangement tables (empty = none). */
export const parseArrangeList = (buf) => countedList(buf, 'arrange.csv', ['Monster', 'NPC']);
/** randomeffect.csv: column-major. Row "ItemIndex" lists items; rows EffectIndexN give that item's Nth effect index. */
export function parseRandomEffect(buf) {
  const rows = rowsOf(buf); if ((rows[0]?.[0] || '') !== 'ItemIndex') throw new Error('randomeffect.csv: first row must be ItemIndex');
  const items = rows[0].slice(1).map(v => int(v, 'randomeffect.csv ItemIndex')), out = {};
  rows.slice(1).forEach((r, n) => { if (r[0] !== `EffectIndex${n}`) throw new Error(`randomeffect.csv: expected EffectIndex${n}, got ${r[0]}`); });
  items.forEach((id, j) => { out[id] = rows.slice(1).map(r => int(r[j + 1], 'randomeffect.csv EffectIndex')); });
  return out;
}
export const SERVER_LISTS = { iplist: parseIpList, tooliplist: parseToolIpList, gradelist: parseGradeList, sync: parseSyncList, arrange: parseArrangeList, randomeffect: parseRandomEffect };
