// Minimal PNG writer for debugging/visual verification (Node only, no deps).
// writePNG(path, width, height, rgba: Uint8Array(width*height*4))
import fs from 'node:fs';
import zlib from 'node:zlib';

const CRC_TABLE = new Uint32Array(256).map((_, n) => {
  let c = n;
  for (let k = 0; k < 8; k++) c = c & 1 ? 0xedb88320 ^ (c >>> 1) : c >>> 1;
  return c >>> 0;
});
function crc32(buf) {
  let c = 0xffffffff;
  for (let i = 0; i < buf.length; i++) c = CRC_TABLE[(c ^ buf[i]) & 0xff] ^ (c >>> 8);
  return (c ^ 0xffffffff) >>> 0;
}
function chunk(type, data) {
  const len = Buffer.alloc(4); len.writeUInt32BE(data.length);
  const td = Buffer.concat([Buffer.from(type, 'ascii'), data]);
  const crc = Buffer.alloc(4); crc.writeUInt32BE(crc32(td));
  return Buffer.concat([len, td, crc]);
}

export function encodePNG(width, height, rgba) {
  const raw = Buffer.alloc((width * 4 + 1) * height);
  for (let y = 0; y < height; y++) {
    raw[y * (width * 4 + 1)] = 0;
    Buffer.from(rgba.buffer, rgba.byteOffset + y * width * 4, width * 4).copy(raw, y * (width * 4 + 1) + 1);
  }
  const ihdr = Buffer.alloc(13);
  ihdr.writeUInt32BE(width, 0); ihdr.writeUInt32BE(height, 4);
  ihdr[8] = 8; ihdr[9] = 6; ihdr[10] = 0; ihdr[11] = 0; ihdr[12] = 0;
  return Buffer.concat([
    Buffer.from([0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a]),
    chunk('IHDR', ihdr), chunk('IDAT', zlib.deflateSync(raw)), chunk('IEND', Buffer.alloc(0)),
  ]);
}

export function writePNG(path, width, height, rgba) {
  fs.writeFileSync(path, encodePNG(width, height, rgba));
}

/** Grayscale helper: values Float32Array/Array (w*h), auto-normalised. */
export function writeGrayPNG(path, width, height, values) {
  let min = Infinity, max = -Infinity;
  for (const v of values) { if (Number.isFinite(v)) { if (v < min) min = v; if (v > max) max = v; } }
  const rgba = new Uint8Array(width * height * 4);
  const span = max - min || 1;
  for (let i = 0; i < width * height; i++) {
    const g = Math.round(((values[i] - min) / span) * 255);
    rgba[i * 4] = rgba[i * 4 + 1] = rgba[i * 4 + 2] = g; rgba[i * 4 + 3] = 255;
  }
  writePNG(path, width, height, rgba);
}
