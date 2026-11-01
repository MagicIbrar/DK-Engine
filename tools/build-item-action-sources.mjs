// Item Action_Index is the ITEM action-table header index. Older exports also
// put it at the start of the filename; Ultimate exports use ultimate.act.N.dat.
// Keep established numeric choices, then resolve missing requested IDs from
// verified headers. Never guess a number embedded elsewhere in a filename.
export function itemActionSources(files, readHeader, requiredIndexes) {
  const selected = new Map(), named = [];
  const required = new Set([...requiredIndexes].filter(n => Number.isSafeInteger(n) && n > 0));
  for (const file of files) {
    const match = /^share\/action\/action\/item\/([^/]+)\.dat$/.exec(file);
    if (!match) continue;
    const numeric = /^(\d+)/.exec(match[1]);
    if (numeric) {
      const index = Number(numeric[1]);
      if (!selected.has(index)) selected.set(index, file);
    } else named.push(file);
  }
  const missing = new Set([...required].filter(index => !selected.has(index)));
  if (!missing.size) return selected;
  const fallback = new Map();
  for (const file of named) {
    const bytes = readHeader(file);
    if (!(bytes instanceof Uint8Array) || bytes.byteLength < 8) throw new Error(`${file}: truncated item action header`);
    const header = new DataView(bytes.buffer, bytes.byteOffset, bytes.byteLength);
    const creature = header.getUint32(0, true), index = header.getUint32(4, true);
    if (creature !== 9 || !index) throw new Error(`${file}: unsupported item action header (creature ${creature}, index ${index})`);
    if (!missing.has(index)) continue;
    if (fallback.has(index)) throw new Error(`Ambiguous item action ${index}: ${fallback.get(index)} and ${file}`);
    fallback.set(index, file);
  }
  for (const [index, file] of fallback) selected.set(index, file);
  return selected;
}
