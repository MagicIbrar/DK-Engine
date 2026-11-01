// .dkmap = one custom map in one file (export / import / share with friends):
//   8 bytes  magic "DKMAP01\0"
//   u32      meta JSON byte length, meta JSON (UTF-8)
//   3 x      u32 length + bytes: the original .map, .mol, .mac files (format.js writers)
// Pure module (browser + Node).
const MAGIC = 'DKMAP01\0';

export function packDkmap({ meta, map, mol, mac }) {
  const json = new TextEncoder().encode(JSON.stringify(meta || {}));
  const parts = [map, mol, mac].map(b => (b ? new Uint8Array(b) : new Uint8Array(0)));
  const total = 8 + 4 + json.length + parts.reduce((s, p) => s + 4 + p.length, 0);
  const out = new Uint8Array(total), dv = new DataView(out.buffer);
  for (let i = 0; i < 8; i++) out[i] = MAGIC.charCodeAt(i);
  let o = 8;
  dv.setUint32(o, json.length, true); o += 4; out.set(json, o); o += json.length;
  for (const p of parts) { dv.setUint32(o, p.length, true); o += 4; out.set(p, o); o += p.length; }
  return out.buffer;
}

/** @returns {{meta:object, map:ArrayBuffer, mol:ArrayBuffer, mac:ArrayBuffer}|null} */
export function unpackDkmap(buf) {
  const u8 = new Uint8Array(buf);
  if (u8.length < 12||u8.length>256*1024*1024) return null;
  for (let i = 0; i < 8; i++) if (u8[i] !== MAGIC.charCodeAt(i)) return null;
  const dv = new DataView(u8.buffer, u8.byteOffset, u8.byteLength);
  let o = 8;
  const jl = dv.getUint32(o, true); o += 4;
  if (jl>16*1024*1024||o + jl > u8.length) return null;
  let meta;
  try { meta = JSON.parse(new TextDecoder().decode(u8.subarray(o, o + jl))); } catch { return null; }
  if(!meta||typeof meta!=='object'||Array.isArray(meta))return null;
  o += jl;
  const out = { meta };
  for (const k of ['map', 'mol', 'mac']) {
    if (o + 4 > u8.length) return null;
    const n = dv.getUint32(o, true); o += 4;
    if (o + n > u8.length) return null;
    out[k] = u8.slice(o, o + n).buffer; o += n;
  }
  return out.map.byteLength&&o===u8.length ? out : null;
}
