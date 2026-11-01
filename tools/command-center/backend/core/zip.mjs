// Minimal ZIP writer (deflate or store, CRC-32, no links). Used for support exports and update fixtures.
import zlib from 'node:zlib';
import fs from 'node:fs';

const TABLE = (() => { const t = new Uint32Array(256); for (let n = 0; n < 256; n++) { let c = n; for (let k = 0; k < 8; k++) c = c & 1 ? 0xedb88320 ^ (c >>> 1) : c >>> 1; t[n] = c >>> 0; } return t; })();
export function crc32(buf) { let c = 0xffffffff; for (let i = 0; i < buf.length; i++) c = TABLE[(c ^ buf[i]) & 0xff] ^ (c >>> 8); return (c ^ 0xffffffff) >>> 0; }
function dos(date) { const d = new Date(date); return {time: (d.getHours() << 11) | (d.getMinutes() << 5) | Math.floor(d.getSeconds() / 2), date: ((d.getFullYear() - 1980) << 9) | ((d.getMonth() + 1) << 5) | d.getDate()}; }
/** entries: [{name: 'a/b.txt', data: Buffer|string}] -> writes a ZIP file. */
export function writeZip(file, entries, {level = 6} = {}) {
  const fd = fs.openSync(file, 'wx'); let offset = 0; const central = [];
  const put = b => { fs.writeSync(fd, b); offset += b.length; };
  try {
    for (const e of entries) {
      if (!/^[^\\:\0]+$/.test(e.name) || e.name.startsWith('/') || e.name.split('/').some(p => p === '..' || p === '.')) throw Error('Unsafe zip entry name: ' + e.name);
      const raw = Buffer.isBuffer(e.data) ? e.data : Buffer.from(String(e.data), 'utf8');
      const deflated = level > 0 ? zlib.deflateRawSync(raw, {level}) : raw, method = level > 0 && deflated.length < raw.length ? 8 : 0, body = method === 8 ? deflated : raw;
      const name = Buffer.from(e.name, 'utf8'), crc = crc32(raw), {time, date} = dos(e.mtime || Date.now()), at = offset;
      const local = Buffer.alloc(30); local.writeUInt32LE(0x04034b50, 0); local.writeUInt16LE(20, 4); local.writeUInt16LE(0x0800, 6); local.writeUInt16LE(method, 8); local.writeUInt16LE(time, 10); local.writeUInt16LE(date, 12); local.writeUInt32LE(crc, 14); local.writeUInt32LE(body.length, 18); local.writeUInt32LE(raw.length, 22); local.writeUInt16LE(name.length, 26); local.writeUInt16LE(0, 28);
      put(local); put(name); put(body);
      const c = Buffer.alloc(46); c.writeUInt32LE(0x02014b50, 0); c.writeUInt16LE(20, 4); c.writeUInt16LE(20, 6); c.writeUInt16LE(0x0800, 8); c.writeUInt16LE(method, 10); c.writeUInt16LE(time, 12); c.writeUInt16LE(date, 14); c.writeUInt32LE(crc, 16); c.writeUInt32LE(body.length, 20); c.writeUInt32LE(raw.length, 24); c.writeUInt16LE(name.length, 28); c.writeUInt32LE(0, 38); c.writeUInt32LE(at, 42);
      central.push(Buffer.concat([c, name]));
    }
    const start = offset; for (const c of central) put(c);
    const end = Buffer.alloc(22); end.writeUInt32LE(0x06054b50, 0); end.writeUInt16LE(central.length, 8); end.writeUInt16LE(central.length, 10); end.writeUInt32LE(offset - start, 12); end.writeUInt32LE(start, 16);
    put(end);
  } finally { fs.closeSync(fd); }
  return {file, entries: entries.length, bytes: offset};
}
