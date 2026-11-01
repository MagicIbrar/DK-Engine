// Every-table compatibility check (lane L2). Complements tools/client-compatibility.mjs (4 csv + 3 dat hand-picked).
// A manifest is captured from a known-good Global generation (box-local copy); a candidate source is then checked
// table-by-table: every reference CSV must exist and keep every reference header column (extra columns = info only),
// every compiled .dat must have a size divisible by one of its known Global record strides.
// Structural only: recognising a layout does not implement a feature.
import fs from 'node:fs'; import path from 'node:path'; import { createHash } from 'node:crypto';
import { decodeText, parseCSV } from '../../src/formats/binreader.js';

/** Known compiled-table strides (bytes/record) with the evidence file that decodes them. */
export const DAT_STRIDES = {
  'share/item/item.dat': [565], 'share/item/itemevent/itemevent.dat': [565], 'share/item/itemevent.dat': [565],
  'share/item/itemoption.dat': [148],
  'share/creature/monster.dat': [2643], 'share/creature/monster64.dat': [4323], // tools/build-monsters.mjs
  'share/article/shoplist.dat': [482],                                          // tools/build-shops.mjs
};
const SKILL_DAT = /^share\/skill\/skill\/\d+\.dat$/; const SKILL_SIZES = [12294, 12290]; // tools/build-skills.mjs

function walk(root, rel = 'share', out = []) {
  let ents; try { ents = fs.readdirSync(path.join(root, rel), { withFileTypes: true }); } catch { return out; }
  for (const e of ents) { const r = rel + '/' + e.name; if (e.isSymbolicLink()) continue; e.isDirectory() ? walk(root, r, out) : e.isFile() && out.push(r); }
  return out;
}
/** Header signature of a CSV: columns of the first non-empty row (handles UTF-16 via decodeText). */
export function csvHeader(buf) {
  const text = decodeText(buf, true); const rows = parseCSV(text);
  const first = rows.find(r => r && r.some(c => String(c).trim() !== '')) || [];
  return first.map(c => String(c).trim());
}
const key = (r) => r.toLowerCase();

export function captureManifest(dataRoot) {
  const tables = {};
  for (const rel of walk(dataRoot)) {
    const k = key(rel), full = path.join(dataRoot, rel), size = fs.statSync(full).size;
    if (k.endsWith('.csv')) tables[k] = { kind: 'csv', columns: csvHeader(fs.readFileSync(full)) };
    else if (k.endsWith('.dat')) {
      if (SKILL_DAT.test(k)) continue; // family checked by size rule, not per file
      tables[k] = { kind: 'dat', bytes: size, strides: DAT_STRIDES[k] || null };
    }
  }
  return { version: 1, capturedFrom: path.resolve(dataRoot), tableCount: Object.keys(tables).length, tables };
}

export function checkTables(dataRoot, manifest) {
  const present = new Map(walk(dataRoot).map(r => [key(r), r]));
  const issues = [], info = []; let checked = 0;
  for (const [k, ref] of Object.entries(manifest.tables)) {
    const rel = present.get(k);
    if (!rel) { issues.push({ file: k, code: 'table-missing' }); continue; }
    const buf = fs.readFileSync(path.join(dataRoot, rel)); checked++;
    if (ref.kind === 'csv') {
      const cols = csvHeader(buf), have = new Set(cols);
      const missing = ref.columns.filter(c => c && !have.has(c));
      if (missing.length) issues.push({ file: k, code: 'columns-missing', columns: missing.slice(0, 20), missingCount: missing.length });
      const extra = cols.filter(c => c && !ref.columns.includes(c));
      if (extra.length) info.push({ file: k, code: 'columns-added', columns: extra.slice(0, 20) });
    } else if (ref.strides) {
      if (!buf.length || !ref.strides.some(s => buf.length % s === 0)) issues.push({ file: k, code: 'unsupported-binary-layout', bytes: buf.length, expectedRecordBytes: ref.strides });
    } else if (buf.length !== ref.bytes) info.push({ file: k, code: 'unparsed-dat-size-changed', bytes: buf.length, reference: ref.bytes });
  }
  for (const [k] of present) if (SKILL_DAT.test(k)) { checked++; const n = fs.statSync(path.join(dataRoot, present.get(k))).size; if (!SKILL_SIZES.includes(n)) issues.push({ file: k, code: 'unsupported-skill-dat-size', bytes: n }); }
  for (const [k] of present) if ((k.endsWith('.csv') || k.endsWith('.dat')) && !SKILL_DAT.test(k) && !manifest.tables[k]) info.push({ file: k, code: 'table-not-in-manifest' });
  return { ok: issues.length === 0, checked, issues, info };
}
export function sha256(buf) { return createHash('sha256').update(buf).digest('hex'); }

// CLI: node tools/lib/table-compat.mjs capture <dataRoot> <out.json> | check <dataRoot> <manifest.json>
if (import.meta.url === `file://${process.argv[1]}`) {
  const [cmd, root, file] = process.argv.slice(2);
  if (cmd === 'capture') { const m = captureManifest(root); fs.writeFileSync(file, JSON.stringify(m)); console.log(`captured ${m.tableCount} tables -> ${file}`); }
  else if (cmd === 'check') { const r = checkTables(root, JSON.parse(fs.readFileSync(file, 'utf8'))); console.log(JSON.stringify({ ok: r.ok, checked: r.checked, issues: r.issues.length, info: r.info.length, sample: r.issues.slice(0, 10) }, null, 1)); process.exitCode = r.ok ? 0 : 1; }
  else { console.error('usage: capture|check <dataRoot> <json>'); process.exitCode = 2; }
}
