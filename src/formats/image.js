// Non-DDS image decoders for Dekaron data: .tga (raw + RLE), .bmp, .psd (flattened composite),
// plus a content-sniffing dispatcher. Pure ES module (no three.js, no Node APIs).
//
// All decoders return { width, height, data: Uint8Array(width*height*4) } in RGBA8 with rows
// TOP-DOWN (row 0 = top of the picture), the same convention as dds.js. Upload with flipY = false
// and keep D3D texcoords unchanged.
//
// Corpus: 45 .tga (all type 2, 32-bit BGRA, bottom-up, alpha bits 8), 70 .bmp (24-bit, one 32-bit,
// BI_RGB, bottom-up), 3 real .psd + 2 PSDs named *.dds, 11 .jpg, 3 .png + 41 PNGs and 1 JPEG named *.dds.
// The one 32-bit BMP (to_in_spider_egg_02) carries a vein mask in alpha, not transparency: decodeBMP returns it
// as stored; material blending must come from the material/effect data, not from texture alpha.

import { assetWork } from '../engine/asset-work.js';
import { sniffImageType, parseDDS, decodeToRGBA } from './dds.js';

export { sniffImageType };

function toU8(buf) {
  if (buf instanceof Uint8Array) return buf;
  if (buf instanceof ArrayBuffer) return new Uint8Array(buf);
  if (ArrayBuffer.isView(buf)) return new Uint8Array(buf.buffer, buf.byteOffset, buf.byteLength);
  throw new TypeError('expected ArrayBuffer or typed array');
}

export class ImageDecodeError extends Error {
  constructor(msg) { super(msg); this.name = 'ImageDecodeError'; }
}

// ------------------------------------------------------------------------------------------ TGA

/**
 * Decode a Truevision TGA. Supports image types 1/9 (colour-mapped), 2/10 (true colour),
 * 3/11 (grey), 8/15/16/24/32 bpp, RLE, and both origins. Alpha: 32-bit uses its alpha byte unless
 * the descriptor says 0 alpha bits AND every alpha byte is 0 (common exporter bug) -> opaque.
 * @returns {{width:number,height:number,data:Uint8Array, unkImageId:Uint8Array, originTop:boolean, bpp:number, imageType:number, alphaBits:number}}
 */
export function decodeTGA(buf) {
  const u = toU8(buf);
  if (u.length < 18) throw new ImageDecodeError('TGA too short');
  const idLen = u[0], cmType = u[1], type = u[2];
  const cmFirst = u[3] | (u[4] << 8), cmLen = u[5] | (u[6] << 8), cmBits = u[7];
  const width = u[12] | (u[13] << 8), height = u[14] | (u[15] << 8);
  const bpp = u[16], desc = u[17];
  const alphaBits = desc & 15, originTop = !!(desc & 0x20), originRight = !!(desc & 0x10);
  if (![1, 2, 3, 9, 10, 11].includes(type)) throw new ImageDecodeError(`unsupported TGA type ${type}`);
  if (!width || !height) throw new ImageDecodeError('TGA zero size');
  let p = 18;
  const imageId = u.subarray(p, p + idLen); p += idLen;
  let cmap = null;
  if (cmType === 1) {
    const eb = Math.ceil(cmBits / 8);
    cmap = new Uint8Array((cmFirst + cmLen) * 4);
    for (let i = 0; i < cmLen; i++) readPixel(u, p + i * eb, cmBits, cmap, (cmFirst + i) * 4, false);
    p += cmLen * eb;
  }
  const bytesPP = Math.ceil(bpp / 8);
  const n = width * height;
  // Unpack (RLE or raw) into a raw pixel stream first.
  let raw;
  if (type >= 9) {
    raw = new Uint8Array(n * bytesPP);
    let o = 0;
    while (o < raw.length && p < u.length) {
      const hdr = u[p++];
      const count = (hdr & 0x7f) + 1;
      if (hdr & 0x80) {
        for (let i = 0; i < count && o < raw.length; i++) { for (let b = 0; b < bytesPP; b++) raw[o++] = u[p + b]; }
        p += bytesPP;
      } else {
        const len = Math.min(count * bytesPP, raw.length - o, u.length - p);
        raw.set(u.subarray(p, p + len), o); o += len; p += count * bytesPP;
      }
    }
  } else {
    raw = u.subarray(p, p + n * bytesPP);
  }
  const grey = type === 3 || type === 11, mapped = type === 1 || type === 9;
  const out = new Uint8Array(n * 4);
  const tmp = new Uint8Array(4);
  let anyAlpha = false;
  for (let i = 0; i < n; i++) {
    const sx = i % width, sy = (i / width) | 0;
    const dx = originRight ? width - 1 - sx : sx;
    const dy = originTop ? sy : height - 1 - sy;
    const d = (dy * width + dx) * 4;
    const s = i * bytesPP;
    if (s + bytesPP > raw.length) { out[d + 3] = 255; continue; }
    if (mapped) {
      const idx = bytesPP === 1 ? raw[s] : raw[s] | (raw[s + 1] << 8);
      const c = idx * 4;
      out[d] = cmap[c]; out[d + 1] = cmap[c + 1]; out[d + 2] = cmap[c + 2]; out[d + 3] = cmap[c + 3];
    } else if (grey) {
      out[d] = out[d + 1] = out[d + 2] = raw[s];
      out[d + 3] = bytesPP > 1 ? raw[s + 1] : 255;
    } else {
      readPixel(raw, s, bpp, tmp, 0, alphaBits > 0);
      out[d] = tmp[0]; out[d + 1] = tmp[1]; out[d + 2] = tmp[2]; out[d + 3] = tmp[3];
      if (bpp === 32 && raw[s + 3]) anyAlpha = true;
    }
  }
  if (bpp === 32 && !anyAlpha && alphaBits === 0) for (let i = 3; i < out.length; i += 4) out[i] = 255;
  return { width, height, data: out, unkImageId: imageId, originTop, bpp, imageType: type, alphaBits };
}

function readPixel(src, s, bits, out, d, useAlpha) {
  if (bits === 32) { out[d] = src[s + 2]; out[d + 1] = src[s + 1]; out[d + 2] = src[s]; out[d + 3] = src[s + 3]; }
  else if (bits === 24) { out[d] = src[s + 2]; out[d + 1] = src[s + 1]; out[d + 2] = src[s]; out[d + 3] = 255; }
  else if (bits === 16 || bits === 15) {
    const v = src[s] | (src[s + 1] << 8);
    out[d] = (((v >> 10) & 31) * 255 / 31) | 0; out[d + 1] = (((v >> 5) & 31) * 255 / 31) | 0; out[d + 2] = ((v & 31) * 255 / 31) | 0;
    out[d + 3] = bits === 16 && useAlpha ? (v & 0x8000 ? 255 : 0) : 255;
  } else if (bits === 8) { out[d] = out[d + 1] = out[d + 2] = src[s]; out[d + 3] = 255; }
}

// ------------------------------------------------------------------------------------------ BMP

/**
 * Decode a Windows BMP: 1/4/8-bit palettised (incl. RLE4/RLE8), 16/24/32-bit BI_RGB and BI_BITFIELDS,
 * bottom-up or top-down. 32-bit BI_RGB alpha is used only when some pixel has non-zero alpha.
 * @returns {{width:number,height:number,data:Uint8Array,bitCount:number,compression:number,topDown:boolean}}
 */
export function decodeBMP(buf) {
  const u = toU8(buf);
  const dv = new DataView(u.buffer, u.byteOffset, u.byteLength);
  if (u.length < 26 || u[0] !== 0x42 || u[1] !== 0x4d) throw new ImageDecodeError('not a BMP');
  const dataOff = dv.getUint32(10, true);
  const hs = dv.getUint32(14, true);
  let width, height, planes, bitCount, compression = 0, clrUsed = 0;
  let rMask = 0, gMask = 0, bMask = 0, aMask = 0;
  if (hs === 12) {
    width = dv.getUint16(18, true); height = dv.getInt16(20, true); planes = dv.getUint16(22, true); bitCount = dv.getUint16(24, true);
  } else {
    width = dv.getInt32(18, true); height = dv.getInt32(22, true); planes = dv.getUint16(26, true); bitCount = dv.getUint16(28, true);
    compression = dv.getUint32(30, true); clrUsed = dv.getUint32(46, true);
    if (compression === 3 || compression === 6) {
      const mo = hs >= 52 ? 54 : 14 + hs; // masks inside V2+ headers, else right after the 40-byte header
      rMask = dv.getUint32(mo, true); gMask = dv.getUint32(mo + 4, true); bMask = dv.getUint32(mo + 8, true);
      if (hs >= 56 || compression === 6) aMask = dv.getUint32(mo + 12, true);
    }
  }
  void planes;
  const topDown = height < 0; height = Math.abs(height);
  if (!width || !height) throw new ImageDecodeError('BMP zero size');
  const out = new Uint8Array(width * height * 4);
  // Palette
  let pal = null;
  if (bitCount <= 8) {
    const entries = clrUsed || (1 << bitCount);
    const pe = hs === 12 ? 3 : 4;
    const po = 14 + hs + (compression === 3 && hs === 40 ? 12 : 0);
    pal = new Uint8Array(256 * 4);
    for (let i = 0; i < entries && i < 256; i++) {
      const s = po + i * pe;
      if (s + 3 > u.length) break;
      pal[i * 4] = u[s + 2]; pal[i * 4 + 1] = u[s + 1]; pal[i * 4 + 2] = u[s]; pal[i * 4 + 3] = 255;
    }
  }
  const put = (x, y, r, g, b, a) => {
    if (x >= width || y >= height) return;
    const row = topDown ? y : height - 1 - y;
    const d = (row * width + x) * 4;
    out[d] = r; out[d + 1] = g; out[d + 2] = b; out[d + 3] = a;
  };
  if (compression === 1 || compression === 2) {
    // RLE8 / RLE4 (always bottom-up)
    let p = dataOff, x = 0, y = 0;
    const rle4 = compression === 2;
    while (p + 1 < u.length && y < height) {
      const c = u[p++], v = u[p++];
      if (c > 0) {
        for (let i = 0; i < c; i++) {
          const idx = rle4 ? (i & 1 ? v & 15 : v >> 4) : v;
          put(x++, y, pal[idx * 4], pal[idx * 4 + 1], pal[idx * 4 + 2], 255);
        }
      } else if (v === 0) { x = 0; y++; }
      else if (v === 1) break;
      else if (v === 2) { x += u[p++]; y += u[p++]; }
      else {
        const nb = rle4 ? (v + 1) >> 1 : v;
        for (let i = 0; i < v; i++) {
          const byte = u[p + (rle4 ? i >> 1 : i)];
          const idx = rle4 ? (i & 1 ? byte & 15 : byte >> 4) : byte;
          put(x++, y, pal[idx * 4], pal[idx * 4 + 1], pal[idx * 4 + 2], 255);
        }
        p += nb + (nb & 1);
      }
    }
    return { width, height, data: out, bitCount, compression, topDown };
  }
  const stride = ((width * bitCount + 31) >> 5) << 2;
  const mi = (m) => { if (!m) return null; let s = 0; while (!((m >>> s) & 1)) s++; let b = 0; while (s + b < 32 && ((m >>> (s + b)) & 1)) b++; return { s, max: 2 ** b - 1 }; };
  const R = mi(rMask), G = mi(gMask), B = mi(bMask), A = mi(aMask);
  let anyAlpha = false;
  for (let y = 0; y < height; y++) {
    const rowOff = dataOff + y * stride;
    for (let x = 0; x < width; x++) {
      let r = 0, g = 0, b = 0, a = 255;
      if (bitCount <= 8) {
        const bitPos = x * bitCount;
        const byte = u[rowOff + (bitPos >> 3)] || 0;
        const idx = (byte >> (8 - bitCount - (bitPos & 7))) & ((1 << bitCount) - 1);
        r = pal[idx * 4]; g = pal[idx * 4 + 1]; b = pal[idx * 4 + 2];
      } else if (bitCount === 24) {
        const s = rowOff + x * 3; b = u[s]; g = u[s + 1]; r = u[s + 2];
      } else if (bitCount === 16 || bitCount === 32) {
        const s = rowOff + x * (bitCount >> 3);
        if (s + (bitCount >> 3) > u.length) continue;
        const v = bitCount === 16 ? dv.getUint16(s, true) : dv.getUint32(s, true);
        if (R) {
          r = Math.round(((v & rMask) >>> R.s) * 255 / R.max); g = Math.round(((v & gMask) >>> G.s) * 255 / G.max); b = Math.round(((v & bMask) >>> B.s) * 255 / B.max);
          if (A) a = Math.round(((v & aMask) >>> A.s) * 255 / A.max);
        } else if (bitCount === 16) {
          r = ((v >> 10) & 31) * 255 / 31 | 0; g = ((v >> 5) & 31) * 255 / 31 | 0; b = (v & 31) * 255 / 31 | 0;
        } else {
          b = u[s]; g = u[s + 1]; r = u[s + 2]; a = u[s + 3]; if (a) anyAlpha = true;
        }
      }
      put(x, y, r, g, b, a);
    }
  }
  if (bitCount === 32 && !R && !anyAlpha) for (let i = 3; i < out.length; i += 4) out[i] = 255;
  return { width, height, data: out, bitCount, compression, topDown };
}

// ------------------------------------------------------------------------------------------ PSD

/**
 * Decode the flattened composite of an Adobe Photoshop file (8/16-bit RGB, greyscale, indexed;
 * raw or PackBits RLE). Layers are ignored (the composite is what D3D-era tools exported).
 * @returns {{width:number,height:number,data:Uint8Array,channels:number,depth:number,colorMode:number}}
 */
export function decodePSD(buf) {
  const u = toU8(buf);
  const dv = new DataView(u.buffer, u.byteOffset, u.byteLength);
  if (u.length < 26 || u[0] !== 0x38 || u[1] !== 0x42 || u[2] !== 0x50 || u[3] !== 0x53) throw new ImageDecodeError('not a PSD');
  const version = dv.getUint16(4);
  const channels = dv.getUint16(12), height = dv.getUint32(14), width = dv.getUint32(18);
  const depth = dv.getUint16(22), colorMode = dv.getUint16(24);
  if (depth !== 8 && depth !== 16) throw new ImageDecodeError(`PSD depth ${depth} unsupported`);
  let p = 26;
  const cmLen = dv.getUint32(p); const cmData = u.subarray(p + 4, p + 4 + cmLen); p += 4 + cmLen;
  p += 4 + dv.getUint32(p); // image resources
  p += version === 2 ? 8 + Number(dv.getBigUint64(p)) : 4 + dv.getUint32(p); // layer & mask info
  const compression = dv.getUint16(p); p += 2;
  const bpc = depth >> 3;
  const plane = width * height * bpc;
  const planes = [];
  if (compression === 0) {
    for (let c = 0; c < channels; c++) planes.push(u.subarray(p + c * plane, p + (c + 1) * plane));
  } else if (compression === 1) {
    const cntBytes = version === 2 ? 4 : 2;
    const counts = [];
    for (let i = 0; i < channels * height; i++) counts.push(cntBytes === 2 ? dv.getUint16(p + i * 2) : dv.getUint32(p + i * 4));
    p += channels * height * cntBytes;
    for (let c = 0; c < channels; c++) {
      const dst = new Uint8Array(plane);
      let o = 0;
      for (let y = 0; y < height; y++) {
        const end = p + counts[c * height + y];
        const rowEnd = (y + 1) * width * bpc;
        while (p < end && o < rowEnd) {
          const n = (u[p] << 24) >> 24; p++;
          if (n >= 0) { const len = Math.min(n + 1, rowEnd - o); dst.set(u.subarray(p, p + len), o); o += len; p += n + 1; }
          else if (n !== -128) { const len = Math.min(1 - n, rowEnd - o); dst.fill(u[p], o, o + len); o += len; p++; }
        }
        p = end; o = rowEnd;
      }
      planes.push(dst);
    }
  } else throw new ImageDecodeError(`PSD compression ${compression} unsupported`);
  const out = new Uint8Array(width * height * 4);
  const get = (c, i) => (planes[c] ? planes[c][i * bpc] : 255);
  for (let i = 0; i < width * height; i++) {
    const d = i * 4;
    if (colorMode === 3) { // RGB
      out[d] = get(0, i); out[d + 1] = get(1, i); out[d + 2] = get(2, i); out[d + 3] = channels > 3 ? get(3, i) : 255;
    } else if (colorMode === 1 || colorMode === 8) { // greyscale / duotone
      out[d] = out[d + 1] = out[d + 2] = get(0, i); out[d + 3] = channels > 1 ? get(1, i) : 255;
    } else if (colorMode === 2) { // indexed
      const k = get(0, i);
      out[d] = cmData[k]; out[d + 1] = cmData[256 + k]; out[d + 2] = cmData[512 + k]; out[d + 3] = 255;
    } else {
      out[d] = get(0, i); out[d + 1] = get(1, i); out[d + 2] = get(2, i); out[d + 3] = 255;
    }
  }
  // Photoshop stores the composite's extra channel as "merged transparency" only when the document
  // has transparency; an all-zero 4th channel means none -> force opaque.
  if (channels > 3 && colorMode === 3) {
    let any = false; for (let i = 3; i < out.length; i += 4) if (out[i]) { any = true; break; }
    if (!any) for (let i = 3; i < out.length; i += 4) out[i] = 255;
  }
  return { width, height, data: out, channels, depth, colorMode };
}

// ------------------------------------------------------------------------------------------ dispatch

/**
 * Decode any Dekaron texture file synchronously when possible.
 * - dds  -> { kind:'dds', dds } (parsed, NOT decoded: prefer the compressed GPU path; call decodeToRGBA for RGBA)
 * - tga / bmp / psd -> { kind, width, height, data }
 * - png / jpeg / gif -> { kind, encoded: Uint8Array, mimeType }  (decode with createImageBitmap / decodeImageAsync)
 * - unknown -> throws ImageDecodeError
 */
export function decodeImage(buf) {
  const u = toU8(buf);
  const kind = sniffImageType(u);
  switch (kind) {
    case 'dds': return { kind, dds: parseDDS(u) };
    case 'tga': return { kind, ...decodeTGA(u) };
    case 'bmp': return { kind, ...decodeBMP(u) };
    case 'psd': return { kind, ...decodePSD(u) };
    case 'png': return { kind, encoded: u, mimeType: 'image/png' };
    case 'jpeg': return { kind, encoded: u, mimeType: 'image/jpeg' };
    case 'gif': return { kind, encoded: u, mimeType: 'image/gif' };
    default: throw new ImageDecodeError('unrecognised image data (corrupt file?)');
  }
}

/**
 * Browser helper: decode any supported file to RGBA8 top-down (uses createImageBitmap + OffscreenCanvas
 * for PNG/JPEG). Resolves { width, height, data }.
 */
export async function decodeImageAsync(buf) {
  if (sniffImageType(toU8(buf)) === 'dds') {
    const u = toU8(buf);
    const buffer = u.byteOffset === 0 && u.byteLength === u.buffer.byteLength ? u.buffer : u.buffer.slice(u.byteOffset, u.byteOffset + u.byteLength);
    const result = await assetWork('dds', buffer, { decode: true, mipmaps: 'none' });
    return result.img || result.cubeImages?.[0]; // Match the old level-zero/first-face UI decode.
  }
  const r = decodeImage(buf);
  if (!r.encoded) return { width: r.width, height: r.height, data: r.data };
  if (typeof createImageBitmap !== 'function' || typeof OffscreenCanvas === 'undefined') {
    throw new ImageDecodeError(`${r.kind} decoding needs createImageBitmap/OffscreenCanvas`);
  }
  const bmp = await createImageBitmap(new Blob([r.encoded], { type: r.mimeType }), { premultiplyAlpha: 'none', colorSpaceConversion: 'none', imageOrientation: 'from-image' });
  const cv = new OffscreenCanvas(bmp.width, bmp.height);
  const ctx = cv.getContext('2d', { willReadFrequently: true });
  ctx.drawImage(bmp, 0, 0);
  const id = ctx.getImageData(0, 0, bmp.width, bmp.height);
  bmp.close?.();
  return { width: id.width, height: id.height, data: new Uint8Array(id.data.buffer) };
}
