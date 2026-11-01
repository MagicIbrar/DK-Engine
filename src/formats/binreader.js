// Shared little-endian binary reader used by every Dekaron format parser.
// Works identically in the browser and in Node (pass an ArrayBuffer or a Node Buffer).

const latin1 = new TextDecoder('latin1');
let euckr = null;
try { euckr = new TextDecoder('euc-kr'); } catch { euckr = latin1; }

export function toArrayBuffer(buf) {
  if (buf instanceof ArrayBuffer) return buf;
  // Node Buffer / typed array view
  return buf.buffer.slice(buf.byteOffset, buf.byteOffset + buf.byteLength);
}

export class BinReader {
  constructor(buf, offset = 0) {
    this.buf = toArrayBuffer(buf);
    this.dv = new DataView(this.buf);
    this.u8 = new Uint8Array(this.buf);
    this.pos = offset;
  }
  get length() { return this.buf.byteLength; }
  get remaining() { return this.buf.byteLength - this.pos; }
  eof() { return this.pos >= this.buf.byteLength; }
  seek(p) { this.pos = p; return this; }
  skip(n) { this.pos += n; return this; }
  ensure(n) {
    if (this.pos + n > this.buf.byteLength) {
      throw new RangeError(`BinReader: read of ${n} bytes at ${this.pos} past end (${this.buf.byteLength})`);
    }
  }
  u8r() { this.ensure(1); return this.dv.getUint8(this.pos++); }
  i8() { this.ensure(1); return this.dv.getInt8(this.pos++); }
  u16() { this.ensure(2); const v = this.dv.getUint16(this.pos, true); this.pos += 2; return v; }
  i16() { this.ensure(2); const v = this.dv.getInt16(this.pos, true); this.pos += 2; return v; }
  u32() { this.ensure(4); const v = this.dv.getUint32(this.pos, true); this.pos += 4; return v; }
  i32() { this.ensure(4); const v = this.dv.getInt32(this.pos, true); this.pos += 4; return v; }
  f32() { this.ensure(4); const v = this.dv.getFloat32(this.pos, true); this.pos += 4; return v; }
  f64() { this.ensure(8); const v = this.dv.getFloat64(this.pos, true); this.pos += 8; return v; }
  vec2() { return [this.f32(), this.f32()]; }
  vec3() { return [this.f32(), this.f32(), this.f32()]; }
  vec4() { return [this.f32(), this.f32(), this.f32(), this.f32()]; }
  bytes(n) { this.ensure(n); const v = this.u8.subarray(this.pos, this.pos + n); this.pos += n; return v; }
  f32array(n) {
    this.ensure(n * 4);
    const out = new Float32Array(n);
    for (let i = 0; i < n; i++) out[i] = this.dv.getFloat32(this.pos + i * 4, true);
    this.pos += n * 4; return out;
  }
  u16array(n) {
    this.ensure(n * 2);
    const out = new Uint16Array(n);
    for (let i = 0; i < n; i++) out[i] = this.dv.getUint16(this.pos + i * 2, true);
    this.pos += n * 2; return out;
  }
  u32array(n) {
    this.ensure(n * 4);
    const out = new Uint32Array(n);
    for (let i = 0; i < n; i++) out[i] = this.dv.getUint32(this.pos + i * 4, true);
    this.pos += n * 4; return out;
  }
  /** Fixed-size, NUL-terminated string (Korean paths are EUC-KR/CP949). */
  fixedStr(n, korean = false) {
    const b = this.bytes(n);
    let end = b.indexOf(0); if (end < 0) end = n;
    return (korean ? euckr : latin1).decode(b.subarray(0, end));
  }
  /** Length-prefixed (u32) string. */
  lpStr(korean = false) {
    const n = this.u32();
    const b = this.bytes(n);
    let end = b.indexOf(0); if (end < 0) end = n;
    return (korean ? euckr : latin1).decode(b.subarray(0, end));
  }
  cStr(korean = false) {
    const start = this.pos;
    while (this.pos < this.buf.byteLength && this.u8[this.pos] !== 0) this.pos++;
    const s = (korean ? euckr : latin1).decode(this.u8.subarray(start, this.pos));
    if (this.pos < this.buf.byteLength) this.pos++;
    return s;
  }
}

/**
 * Remove a UTF-8 byte-order mark (EF BB BF) from a byte view. UTF-16 needs decoding, not byte stripping; use decodeText for encoded files.
 * (a view, never a copy) so decoders never see it as part of the first header cell (Global update safety: "﻿Index" != "Index").
 */
export function stripBOM(buf) {
  const u8 = buf instanceof ArrayBuffer ? new Uint8Array(buf) : buf;
  if (u8.length >= 3 && u8[0] === 0xef && u8[1] === 0xbb && u8[2] === 0xbf) return u8.subarray(3);
  return u8;
}
/** The same mark seen from a decoded string: U+FEFF, or its three bytes read as latin1 ("ï»¿"). */
export const stripBOMText = (s) => (typeof s === 'string' ? s.replace(/^(?:﻿|ï»¿)/, '') : s);

/** Parse a Dekaron CSV (latin1 / EUC-KR, CRLF, optional quotes). Returns array of string arrays. */
export function parseCSV(text) {
  text = stripBOMText(text);
  const rows = [];
  let row = [], field = '', q = false;
  for (let i = 0; i < text.length; i++) {
    const c = text[i];
    if (q) {
      if (c === '"') { if (text[i + 1] === '"') { field += '"'; i++; } else q = false; }
      else field += c;
    } else if (c === '"') q = true;
    else if (c === ',') { row.push(field); field = ''; }
    else if (c === '\n') { row.push(field.replace(/\r$/, '')); rows.push(row); row = []; field = ''; }
    else field += c;
  }
  if (field.length || row.length) { row.push(field.replace(/\r$/, '')); rows.push(row); }
  return rows;
}

export function decodeText(buf, korean = false) {
  const bytes = buf instanceof ArrayBuffer ? new Uint8Array(buf) : new Uint8Array(buf.buffer, buf.byteOffset, buf.byteLength);
  // An explicit encoding declaration wins over the caller's legacy code page.
  // Do not guess unmarked UTF-8: original CP949/Windows-1252 bytes remain unchanged.
  if (bytes.length >= 4 && ((bytes[0]===0xff && bytes[1]===0xfe && bytes[2]===0 && bytes[3]===0) ||
      (bytes[0]===0 && bytes[1]===0 && bytes[2]===0xfe && bytes[3]===0xff))) throw new Error('Unsupported UTF-32 text encoding.');
  let encoding;
  if (bytes[0]===0xef && bytes[1]===0xbb && bytes[2]===0xbf) encoding='utf-8';
  else if (bytes[0]===0xff && bytes[1]===0xfe) encoding='utf-16le';
  else if (bytes[0]===0xfe && bytes[1]===0xff) encoding='utf-16be';
  return encoding ? new TextDecoder(encoding,{fatal:true}).decode(bytes) : (korean ? euckr : latin1).decode(bytes);
}
