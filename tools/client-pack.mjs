// Known Global pack.hdr/pack.dNN reader. Payloads are uncompressed; no external unpacker is used.
import fs from 'node:fs/promises';
import path from 'node:path';
import { createHash } from 'node:crypto';

export async function inspectPack(directory) {
  const header = await fs.readFile(path.join(directory, 'pack.hdr'));
  const sections = [];
  for (let at = header.indexOf('pack.d'); at >= 0; at = header.indexOf('pack.d', at + 1)) {
    const name = header.toString('ascii', at, at + 8);
    if (at >= 4 && header.readUInt32LE(at - 4) === 8 && /^pack\.d\d\d$/.test(name)) sections.push({ at, name });
  }
  if (!sections.length) throw new Error('Unsupported pack header: no known pack.dNN sections. No files were changed.');
  const decoder = new TextDecoder('euc-kr', { fatal: true });
  const entries = new Map(); let section = -1, scanned = 0;
  for (let at = header.indexOf('/data/'); at >= 0; at = header.indexOf('/data/', at + 1)) {
    if (at < 4) continue;
    const length = header.readUInt32LE(at - 4);
    if (length < 7 || length > 400 || at + length + 20 > header.length) continue;
    const bytes = header.subarray(at, at + length);
    if (bytes.includes(0)) continue;
    while (section + 1 < sections.length && sections[section + 1].at <= at) section++;
    if (section < 0) throw new Error('Unsupported pack header: file record precedes its pack section.');
    const rel = decoder.decode(bytes).replace(/^\/data\//, '').replace(/\\/g, '/').toLowerCase();
    if (!rel || rel.split('/').some(p => !p || p === '.' || p === '..') || /[:\x00-\x1f]/.test(rel)) throw new Error(`Unsafe pack filename: ${rel}`);
    const offset = header.readBigUInt64LE(at + length), size = header.readUInt32LE(at + length + 8);
    if (offset > BigInt(Number.MAX_SAFE_INTEGER)) throw new Error('Unsupported pack offset exceeds the safe integer range.');
    entries.set(rel, { rel, pack: sections[section].name, offset: Number(offset), size });
    scanned++; at += length + 19;
  }
  if (!entries.has('share/maplist.csv')) throw new Error('Unsupported/incomplete Global pack: share/maplist.csv is missing.');
  const packs = new Map();
  for (const name of new Set([...entries.values()].map(e => e.pack))) {
    const stat = await fs.stat(path.join(directory, name));
    if (!stat.isFile()) throw new Error(`Missing pack file ${name}.`);
    packs.set(name, stat);
  }
  for (const entry of entries.values()) if (entry.offset + entry.size > packs.get(entry.pack).size) throw new Error(`Pack record outside ${entry.pack}: ${entry.rel}`);
  return { directory, header, entries: [...entries.values()], packs, scanned, bytes: [...entries.values()].reduce((n, e) => n + e.size, 0) };
}

export async function extractPack(pack, output, progress = () => {}, digests = null) {
  // digests (optional Map): rel -> sha256 of the PACK bytes written, so a later reuse can prove the extraction still equals the pack.
  await fs.mkdir(output, { recursive: true });
  const handles = new Map();
  const directories = new Map(); let next = 0, complete = 0, failed = false;
  async function directory(dir) { if (!directories.has(dir)) directories.set(dir, fs.mkdir(dir, { recursive: true })); await directories.get(dir); }
  try {
    for (const name of pack.packs.keys()) handles.set(name, await fs.open(path.join(pack.directory, name), 'r'));
    const results = await Promise.allSettled(Array.from({ length: 8 }, async () => {
      try {
      const buffer = Buffer.allocUnsafe(1024 * 1024);
      while (!failed && next < pack.entries.length) {
        const entry = pack.entries[next++], destination = path.resolve(output, ...entry.rel.split('/'));
        if (!destination.startsWith(path.resolve(output) + path.sep)) throw new Error('Pack target escaped the staging directory.');
        await directory(path.dirname(destination));
        const out = await fs.open(destination, 'wx'); const sha = digests ? createHash('sha256') : null;
        try {
          let offset = 0;
          while (offset < entry.size) {
            const length = Math.min(buffer.length, entry.size - offset);
            const { bytesRead } = await handles.get(entry.pack).read(buffer, 0, length, entry.offset + offset);
            if (bytesRead !== length) throw new Error(`Truncated pack payload: ${entry.rel}`);
            let written = 0;
            while (written < bytesRead) { const result = await out.write(buffer, written, bytesRead - written, offset + written); if (!result.bytesWritten) throw new Error('Incomplete extracted file write.'); written += result.bytesWritten; }
            sha?.update(buffer.subarray(0, bytesRead)); offset += bytesRead;
          }
          if (sha) digests.set(entry.rel, sha.digest('hex'));
        } finally { await out.close(); }
        progress(++complete, pack.entries.length);
      }
      } catch (error) { failed = true; throw error; }
    }));
    const failure = results.find(result => result.status === 'rejected');
    if (failure) throw failure.reason;
  } finally { await Promise.allSettled([...handles.values()].map(handle => handle.close())); }
}
