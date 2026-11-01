// DirectDraw Surface (.dds) parser + software decoder for Dekaron textures.
// Pure ES module: no three.js, no Node APIs. Works on ArrayBuffer | Node Buffer | typed array view.
//
// Corpus facts (37,695 files under data/, see docs/formats/dds.md):
//   DXT1 64% · DXT3 22% · DXT5 14% · A8R8G8B8 · A4R4G4B4 · R5G6B5 · R8G8B8 · X8R8G8B8 · X1R5G5B5
//   · one DXT1 cubemap · one D3DFMT_R32F (fourCC = 114) · no DX10 headers, no volumes.
//   Some files named *.dds are really PNG / JPEG / PSD (D3DX sniffs content, not the extension):
//   use sniffImageType() first and route PNG/JPEG to the browser decoder, PSD to image.js.
//
// Orientation: row 0 of every level is the TOP of the image (D3D convention). Upload with
// texture.flipY = false and use the mesh's D3D texcoords unchanged (D3D v=0 == first row in memory
// == GL t=0 of the uploaded data). decodeToRGBA() keeps the same top-down row order.

const MAGIC_DDS = 0x20534444; // 'DDS '

// DDS_HEADER.dwFlags
export const DDSD = { CAPS: 0x1, HEIGHT: 0x2, WIDTH: 0x4, PITCH: 0x8, PIXELFORMAT: 0x1000, MIPMAPCOUNT: 0x20000, LINEARSIZE: 0x80000, DEPTH: 0x800000 };
// DDS_PIXELFORMAT.dwFlags
export const DDPF = { ALPHAPIXELS: 0x1, ALPHA: 0x2, FOURCC: 0x4, PALETTEINDEXED8: 0x20, RGB: 0x40, YUV: 0x200, LUMINANCE: 0x20000, BUMPDUDV: 0x80000 };
// dwCaps2
export const DDSCAPS2 = { CUBEMAP: 0x200, POSX: 0x400, NEGX: 0x800, POSY: 0x1000, NEGY: 0x2000, POSZ: 0x4000, NEGZ: 0x8000, VOLUME: 0x200000 };
export const CUBE_FACE_NAMES = ['+X', '-X', '+Y', '-Y', '+Z', '-Z'];

// Block-compressed formats -> WebGL (WEBGL_compressed_texture_s3tc / _rgtc) info.
// DXT1 uses the RGBA variant so 1-bit punch-through alpha (c0 <= c1, index 3) survives, as in D3D9.
const BLOCK_FORMATS = {
  DXT1: { blockBytes: 8, glFormat: 0x83F1, threeFormat: 'RGBA_S3TC_DXT1_Format', alpha: '1bit' },
  DXT2: { blockBytes: 16, glFormat: 0x83F2, threeFormat: 'RGBA_S3TC_DXT3_Format', alpha: 'explicit', premultiplied: true },
  DXT3: { blockBytes: 16, glFormat: 0x83F2, threeFormat: 'RGBA_S3TC_DXT3_Format', alpha: 'explicit' },
  DXT4: { blockBytes: 16, glFormat: 0x83F3, threeFormat: 'RGBA_S3TC_DXT5_Format', alpha: 'interpolated', premultiplied: true },
  DXT5: { blockBytes: 16, glFormat: 0x83F3, threeFormat: 'RGBA_S3TC_DXT5_Format', alpha: 'interpolated' },
  ATI1: { blockBytes: 8, glFormat: 0x8DBB, threeFormat: 'RED_RGTC1_Format', alpha: 'none' },
  ATI2: { blockBytes: 16, glFormat: 0x8DBD, threeFormat: 'RED_GREEN_RGTC2_Format', alpha: 'none' },
};
const FOURCC_ALIASES = { BC1: 'DXT1', BC2: 'DXT3', BC3: 'DXT5', BC4U: 'ATI1', BC5U: 'ATI2' };

// Uncompressed layouts as { bits, r, g, b, a, flags } masks. Keys are the D3DFMT names.
const MASK_FORMATS = {
  A8R8G8B8: [32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000],
  X8R8G8B8: [32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0],
  A8B8G8R8: [32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000],
  X8B8G8R8: [32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0],
  A2R10G10B10: [32, 0x000003ff, 0x000ffc00, 0x3ff00000, 0xc0000000],
  A2B10G10R10: [32, 0x3ff00000, 0x000ffc00, 0x000003ff, 0xc0000000],
  R8G8B8: [24, 0xff0000, 0x00ff00, 0x0000ff, 0],
  B8G8R8: [24, 0x0000ff, 0x00ff00, 0xff0000, 0],
  R5G6B5: [16, 0xf800, 0x07e0, 0x001f, 0],
  X1R5G5B5: [16, 0x7c00, 0x03e0, 0x001f, 0],
  A1R5G5B5: [16, 0x7c00, 0x03e0, 0x001f, 0x8000],
  A4R4G4B4: [16, 0x0f00, 0x00f0, 0x000f, 0xf000],
  X4R4G4B4: [16, 0x0f00, 0x00f0, 0x000f, 0],
  A8R3G3B2: [16, 0x00e0, 0x001c, 0x0003, 0xff00],
  R3G3B2: [8, 0xe0, 0x1c, 0x03, 0],
  G16R16: [32, 0x0000ffff, 0xffff0000, 0, 0],
  L8: [8, 0xff, 0, 0, 0, 'L'],
  A8L8: [16, 0x00ff, 0, 0, 0xff00, 'L'],
  A4L4: [8, 0x0f, 0, 0, 0xf0, 'L'],
  L16: [16, 0xffff, 0, 0, 0, 'L'],
  A8: [8, 0, 0, 0, 0xff, 'A'],
  V8U8: [16, 0x00ff, 0xff00, 0, 0, 'UV'],
};

// D3DFORMAT numeric codes that some exporters put in dwFourCC.
const D3DFMT_CODES = {
  20: 'R8G8B8', 21: 'A8R8G8B8', 22: 'X8R8G8B8', 23: 'R5G6B5', 24: 'X1R5G5B5', 25: 'A1R5G5B5', 26: 'A4R4G4B4',
  27: 'R3G3B2', 28: 'A8', 29: 'A8R3G3B2', 30: 'X4R4G4B4', 31: 'A2B10G10R10', 32: 'A8B8G8R8', 33: 'X8B8G8R8',
  34: 'G16R16', 35: 'A2R10G10B10', 36: 'A16B16G16R16', 50: 'L8', 51: 'A8L8', 52: 'A4L4', 60: 'V8U8', 81: 'L16',
  110: 'Q16W16V16U16', 111: 'R16F', 112: 'G16R16F', 113: 'A16B16G16R16F', 114: 'R32F', 115: 'G32R32F', 116: 'A32B32G32R32F',
};
// Wide / float formats: bytes per pixel, channel count, component type.
const WIDE_FORMATS = {
  A16B16G16R16: { bpp: 8, ch: 4, type: 'u16' },
  Q16W16V16U16: { bpp: 8, ch: 4, type: 's16' },
  R16F: { bpp: 2, ch: 1, type: 'f16' },
  G16R16F: { bpp: 4, ch: 2, type: 'f16' },
  A16B16G16R16F: { bpp: 8, ch: 4, type: 'f16' },
  R32F: { bpp: 4, ch: 1, type: 'f32' },
  G32R32F: { bpp: 8, ch: 2, type: 'f32' },
  A32B32G32R32F: { bpp: 16, ch: 4, type: 'f32' },
};
// Minimal DXGI support for DX10 headers (none in the Dekaron corpus).
const DXGI = {
  71: 'DXT1', 72: 'DXT1', 74: 'DXT3', 75: 'DXT3', 77: 'DXT5', 78: 'DXT5', 80: 'ATI1', 83: 'ATI2',
  28: 'A8B8G8R8', 29: 'A8B8G8R8', 87: 'A8R8G8B8', 88: 'X8R8G8B8', 91: 'A8R8G8B8', 85: 'R5G6B5', 86: 'A1R5G5B5', 115: 'A4R4G4B4',
  61: 'L8', 65: 'A8', 2: 'A32B32G32R32F', 10: 'A16B16G16R16F', 41: 'R32F', 54: 'R16F', 16: 'G32R32F', 34: 'G16R16F',
};

export class DDSError extends Error {
  constructor(msg, code) { super(msg); this.name = 'DDSError'; this.code = code; }
}

function toU8(buf) {
  if (buf instanceof Uint8Array) return buf;
  if (buf instanceof ArrayBuffer) return new Uint8Array(buf);
  if (ArrayBuffer.isView(buf)) return new Uint8Array(buf.buffer, buf.byteOffset, buf.byteLength);
  throw new TypeError('parseDDS: expected ArrayBuffer or typed array');
}

/**
 * Identify an image container by its magic bytes (the game's D3DX loader ignores the extension).
 * @returns {'dds'|'png'|'jpeg'|'bmp'|'gif'|'psd'|'tga'|'unknown'}
 */
export function sniffImageType(buf) {
  const u = toU8(buf);
  if (u.length >= 4 && u[0] === 0x44 && u[1] === 0x44 && u[2] === 0x53 && u[3] === 0x20) return 'dds';
  if (u.length >= 8 && u[0] === 0x89 && u[1] === 0x50 && u[2] === 0x4e && u[3] === 0x47) return 'png';
  if (u.length >= 3 && u[0] === 0xff && u[1] === 0xd8 && u[2] === 0xff) return 'jpeg';
  if (u.length >= 4 && u[0] === 0x38 && u[1] === 0x42 && u[2] === 0x50 && u[3] === 0x53) return 'psd';
  if (u.length >= 6 && u[0] === 0x47 && u[1] === 0x49 && u[2] === 0x46 && u[3] === 0x38) return 'gif';
  if (u.length >= 26 && u[0] === 0x42 && u[1] === 0x4d) {
    const hs = u[14] | (u[15] << 8) | (u[16] << 16) | (u[17] << 24);
    if (hs === 12 || hs === 40 || hs === 52 || hs === 56 || hs === 108 || hs === 124) return 'bmp';
  }
  if (u.length >= 18) {
    // TGA has no magic: validate the header fields.
    const cmType = u[1], imgType = u[2], bpp = u[16];
    const w = u[12] | (u[13] << 8), h = u[14] | (u[15] << 8);
    if (cmType <= 1 && [1, 2, 3, 9, 10, 11].includes(imgType) && [8, 15, 16, 24, 32].includes(bpp) && w > 0 && h > 0) return 'tga';
  }
  return 'unknown';
}

export function isDDS(buf) {
  const u = toU8(buf);
  return u.length >= 128 && u[0] === 0x44 && u[1] === 0x44 && u[2] === 0x53 && u[3] === 0x20;
}

function fourCCString(v) {
  let s = '';
  for (let i = 0; i < 4; i++) { const c = (v >>> (i * 8)) & 0xff; s += c >= 32 && c < 127 ? String.fromCharCode(c) : '\0'; }
  return s.replace(/\0+$/, '');
}

function maskInfo(mask) {
  if (!mask) return { shift: 0, bits: 0, max: 0 };
  let shift = 0; while (((mask >>> shift) & 1) === 0) shift++;
  let bits = 0; while (shift + bits < 32 && ((mask >>> (shift + bits)) & 1)) bits++;
  return { shift, bits, max: bits >= 32 ? 0xffffffff : (2 ** bits) - 1 };
}

/** Name a mask layout if it matches a known D3DFMT, else 'MASK'. */
function nameForMasks(bits, r, g, b, a, pfFlags) {
  const lum = !!(pfFlags & DDPF.LUMINANCE), alphaOnly = !!(pfFlags & DDPF.ALPHA) && !(pfFlags & DDPF.RGB) && !lum;
  const bump = !!(pfFlags & DDPF.BUMPDUDV);
  for (const [name, m] of Object.entries(MASK_FORMATS)) {
    const kind = m[5] || 'RGB';
    if (m[0] !== bits) continue;
    if (kind === 'L' && !lum) continue;
    if (kind === 'A' && !alphaOnly) continue;
    if (kind === 'UV' && !bump) continue;
    if (kind === 'RGB' && (lum || alphaOnly || bump)) continue;
    const aa = (pfFlags & (DDPF.ALPHAPIXELS | DDPF.ALPHA)) ? a >>> 0 : 0;
    if ((m[1] >>> 0) === (r >>> 0) && (m[2] >>> 0) === (g >>> 0) && (m[3] >>> 0) === (b >>> 0) && (m[4] >>> 0) === aa) return name;
  }
  return 'MASK';
}

function levelSize(fmt, w, h) {
  if (fmt.blockBytes) return Math.max(1, (w + 3) >> 2) * Math.max(1, (h + 3) >> 2) * fmt.blockBytes;
  return fmt.pitch(w) * h;
}

/**
 * Parse a DDS file.
 * @param {ArrayBuffer|Uint8Array|Buffer} buf
 * @returns {{
 *   width:number, height:number, depth:number, format:string, compressed:boolean,
 *   blockBytes:number|0, bytesPerPixel:number|0, glFormat:number|null, threeFormat:string|null,
 *   hasAlpha:boolean, premultiplied:boolean, isCubemap:boolean, isVolume:boolean,
 *   mipmaps:{data:Uint8Array,width:number,height:number,depth?:number,pitch?:number}[],
 *   faces:(null|{data:Uint8Array,width:number,height:number}[])[]|undefined,
 *   mipCount:number, declaredMipCount:number, truncated:boolean, trailingBytes:number, warnings:string[],
 *   pixelFormat:{flags,fourCC,fourCCString,rgbBitCount,rMask,gMask,bMask,aMask}, masks?:object,
 *   header:{flags,pitchOrLinearSize,caps,caps2,caps3,caps4,unkReserved1:number[]}, dx10?:object, palette?:Uint8Array
 * }}
 * mipmaps[i].data are views into the input buffer (no copy) - copy them if the buffer is reused.
 * Throws DDSError('not a DDS file', 'MAGIC') for PNG/JPEG/garbage content (check sniffImageType()).
 */
export function parseDDS(buf) {
  const u8 = toU8(buf);
  if (u8.length < 128) throw new DDSError(`DDS too short (${u8.length} bytes)`, 'SHORT');
  const dv = new DataView(u8.buffer, u8.byteOffset, u8.byteLength);
  const U = (o) => dv.getUint32(o, true);
  if (U(0) !== MAGIC_DDS) throw new DDSError('not a DDS file (bad magic)', 'MAGIC');
  const warnings = [];
  const headerSize = U(4);
  if (headerSize !== 124) warnings.push(`dwSize=${headerSize} (expected 124)`);
  const flags = U(8);
  let height = U(12), width = U(16);
  const pitchOrLinearSize = U(20);
  let depth = U(24);
  const declaredMipCount = U(28);
  const unkReserved1 = []; for (let i = 0; i < 11; i++) unkReserved1.push(U(32 + i * 4));
  const pfSize = U(76), pfFlags = U(80), fourCC = U(84), rgbBitCount = U(88);
  const rMask = U(92) >>> 0, gMask = U(96) >>> 0, bMask = U(100) >>> 0, aMask = U(104) >>> 0;
  const caps = U(108), caps2 = U(112), caps3 = U(116), caps4 = U(120);
  if (pfSize !== 32) warnings.push(`ddspf.dwSize=${pfSize} (expected 32)`);
  if (!width || !height || width > 16384 || height > 16384) throw new DDSError(`bad dimensions ${width}x${height}`, 'DIMS');

  let dataOffset = 128;
  let dx10 = null;
  let format, fmt, palette = null, masks = null;
  const fcc = fourCCString(fourCC);

  if (pfFlags & DDPF.FOURCC) {
    if (fcc === 'DX10') {
      if (u8.length < 148) throw new DDSError('truncated DX10 header', 'SHORT');
      dx10 = { dxgiFormat: U(128), resourceDimension: U(132), miscFlag: U(136), arraySize: U(140), miscFlags2: U(144) };
      dataOffset = 148;
      format = DXGI[dx10.dxgiFormat];
      if (!format) throw new DDSError(`unsupported DXGI format ${dx10.dxgiFormat}`, 'FORMAT');
    } else if (BLOCK_FORMATS[fcc] || FOURCC_ALIASES[fcc]) {
      format = FOURCC_ALIASES[fcc] || fcc;
    } else if (D3DFMT_CODES[fourCC]) {
      format = D3DFMT_CODES[fourCC];
    } else {
      throw new DDSError(`unsupported FourCC '${fcc}' (0x${fourCC.toString(16)})`, 'FORMAT');
    }
  } else if (pfFlags & DDPF.PALETTEINDEXED8) {
    format = 'P8';
  } else if (pfFlags & (DDPF.RGB | DDPF.LUMINANCE | DDPF.ALPHA | DDPF.BUMPDUDV | DDPF.ALPHAPIXELS)) {
    if (![8, 16, 24, 32].includes(rgbBitCount)) throw new DDSError(`unsupported rgbBitCount ${rgbBitCount}`, 'FORMAT');
    format = nameForMasks(rgbBitCount, rMask, gMask, bMask, aMask, pfFlags);
    const hasA = (pfFlags & (DDPF.ALPHAPIXELS | DDPF.ALPHA)) && aMask;
    masks = {
      bits: rgbBitCount,
      kind: pfFlags & DDPF.LUMINANCE ? 'L' : (pfFlags & DDPF.BUMPDUDV ? 'UV' : ((pfFlags & DDPF.ALPHA) && !(pfFlags & DDPF.RGB) ? 'A' : 'RGB')),
      r: rMask, g: gMask, b: bMask, a: hasA ? aMask : 0,
    };
  } else {
    throw new DDSError(`unknown pixel format flags 0x${pfFlags.toString(16)}`, 'FORMAT');
  }

  // Describe how a level is laid out.
  if (BLOCK_FORMATS[format]) {
    fmt = { ...BLOCK_FORMATS[format] };
  } else if (WIDE_FORMATS[format]) {
    const wf = WIDE_FORMATS[format];
    fmt = { bpp: wf.bpp, wide: wf, pitch: (w) => w * wf.bpp };
  } else if (format === 'P8') {
    fmt = { bpp: 1, pitch: (w) => w };
  } else {
    if (!masks) { // named D3DFMT from FourCC code / DXGI
      const m = MASK_FORMATS[format];
      if (!m) throw new DDSError(`no layout for ${format}`, 'FORMAT');
      masks = { bits: m[0], kind: m[5] || 'RGB', r: m[1] >>> 0, g: m[2] >>> 0, b: m[3] >>> 0, a: m[4] >>> 0 };
    }
    const bpp = masks.bits >> 3;
    fmt = { bpp, pitch: (w) => w * bpp };
  }

  if (format === 'P8') {
    if (u8.length < dataOffset + 1024) throw new DDSError('truncated palette', 'SHORT');
    palette = u8.subarray(dataOffset, dataOffset + 1024); // 256 x (R,G,B,A) PALETTEENTRY
    dataOffset += 1024;
  }

  const isCubemap = !!(caps2 & DDSCAPS2.CUBEMAP);
  const isVolume = !!(caps2 & DDSCAPS2.VOLUME) && depth > 1;
  if (!isVolume) depth = 1;

  // Mip count: honour dwMipMapCount only when DDSD_MIPMAPCOUNT is set; clamp to the full chain length.
  const maxLevels = Math.floor(Math.log2(Math.max(width, height, depth))) + 1;
  let mipCount = (flags & DDSD.MIPMAPCOUNT) && declaredMipCount > 1 ? declaredMipCount : 1;
  if (mipCount > maxLevels) { warnings.push(`dwMipMapCount ${declaredMipCount} > max ${maxLevels}; clamped`); mipCount = maxLevels; }

  // Uncompressed row pitch: D3DX writes tight rows; some tools DWORD-align them. Detect from file size.
  if (!fmt.blockBytes && !fmt.wide && format !== 'P8') {
    const tight = fmt.pitch;
    const aligned = (w) => (w * fmt.bpp + 3) & ~3;
    if (tight(width) !== aligned(width)) {
      const faces = isCubemap ? 6 : 1;
      let tightTotal = 0, alignedTotal = 0;
      for (let i = 0, w = width, h = height; i < mipCount; i++, w = Math.max(1, w >> 1), h = Math.max(1, h >> 1)) {
        tightTotal += tight(w) * h; alignedTotal += aligned(w) * h;
      }
      const avail = u8.length - dataOffset;
      // Prefer tight rows; switch to aligned rows only when the file size matches them exactly.
      if (avail === alignedTotal * faces * depth && avail !== tightTotal * faces * depth) {
        fmt.pitch = aligned; warnings.push('DWORD-aligned row pitch');
      }
    }
  }

  const readChain = (offset) => {
    const levels = [];
    let w = width, h = height, d = depth, off = offset, truncated = false;
    for (let i = 0; i < mipCount; i++) {
      const sliceSize = levelSize(fmt, w, h);
      const size = sliceSize * d;
      if (off + size > u8.length) {
        if (i === 0) {
          // Keep what exists, zero-fill the rest so level 0 is always usable.
          const data = new Uint8Array(size);
          if (off < u8.length) data.set(u8.subarray(off, u8.length));
          levels.push(mip(data, w, h, d));
          warnings.push(`level 0 truncated (${Math.max(0, u8.length - off)}/${size} bytes)`);
        }
        truncated = true;
        off = u8.length;
        break;
      }
      levels.push(mip(u8.subarray(off, off + size), w, h, d));
      off += size;
      w = Math.max(1, w >> 1); h = Math.max(1, h >> 1); d = Math.max(1, d >> 1);
    }
    return { levels, end: off, truncated };
  };
  const mip = (data, w, h, d) => {
    const m = { data, width: w, height: h };
    if (isVolume) m.depth = d;
    if (!fmt.blockBytes) m.pitch = fmt.pitch(w);
    return m;
  };

  let mipmaps, faces, truncated = false, end;
  if (isCubemap) {
    faces = [];
    let off = dataOffset;
    for (let f = 0; f < 6; f++) {
      if (!(caps2 & (DDSCAPS2.POSX << f))) { faces.push(null); continue; }
      const r = readChain(off);
      faces.push(r.levels); off = r.end; truncated ||= r.truncated;
    }
    end = off;
    mipmaps = faces.find(Boolean) || [];
    // Keep every face at the same mip count (WebGL cube completeness).
    const n = Math.min(...faces.filter(Boolean).map(f => f.length));
    for (let f = 0; f < 6; f++) if (faces[f]) faces[f] = faces[f].slice(0, n);
    mipmaps = mipmaps.slice(0, n);
  } else {
    const r = readChain(dataOffset);
    mipmaps = r.levels; end = r.end; truncated = r.truncated;
  }
  if (truncated) warnings.push(`mip chain truncated: ${mipmaps.length}/${mipCount} levels present`);
  const trailingBytes = Math.max(0, u8.length - end);

  const hasAlpha = fmt.blockBytes
    ? fmt.alpha !== 'none'
    : format === 'P8' ? true
      : fmt.wide ? fmt.wide.ch === 4
        : !!(masks && masks.a);

  const out = {
    width, height, depth, format,
    compressed: !!fmt.blockBytes,
    blockBytes: fmt.blockBytes || 0,
    bytesPerPixel: fmt.blockBytes ? 0 : fmt.bpp,
    glFormat: fmt.blockBytes ? fmt.glFormat : null,
    threeFormat: fmt.blockBytes ? fmt.threeFormat : null,
    hasAlpha,
    premultiplied: !!fmt.premultiplied,
    isCubemap, isVolume,
    mipmaps,
    mipCount: mipmaps.length,
    declaredMipCount,
    truncated,
    trailingBytes,
    warnings,
    pixelFormat: { flags: pfFlags, fourCC, fourCCString: fcc, rgbBitCount, rMask, gMask, bMask, aMask },
    header: { flags, pitchOrLinearSize, caps, caps2, caps3, caps4, unkReserved1 },
  };
  if (masks) out.masks = masks;
  if (faces) out.faces = faces;
  if (dx10) out.dx10 = dx10;
  if (palette) out.palette = palette;
  // DXT1: does level 0 really use punch-through alpha? (hasAlpha is only the format capability)
  if (format === 'DXT1') out.punchThrough = mipmaps.length ? dxt1PunchThrough(out, 0, 0) : false;
  return out;
}

/**
 * WebGL upload plan for a parsed DDS. Compressed data can go straight to THREE.CompressedTexture when
 * level-0 width/height are multiples of 4 (WEBGL_compressed_texture_s3tc rule); otherwise use decodeToRGBA.
 * @returns {{ compressed:boolean, ok:boolean, levels:number, reason?:string }}
 */
export function webglCompressedPlan(dds) {
  if (!dds.compressed) return { compressed: false, ok: false, levels: 0, reason: 'uncompressed' };
  // Chrome/ANGLE and Firefox check the implied base size of every level: (size << level) % 4 == 0.
  // For a chain that halves from level 0 this reduces to "level 0 is a multiple of 4".
  if (dds.width % 4 || dds.height % 4) return { compressed: true, ok: false, levels: 0, reason: `level 0 ${dds.width}x${dds.height} not a multiple of 4` };
  if (dds.premultiplied) return { compressed: true, ok: true, levels: dds.mipmaps.length, reason: 'premultiplied alpha (DXT2/4): use premultiplied blending' };
  return { compressed: true, ok: true, levels: dds.mipmaps.length };
}

/**
 * True if a DXT1 level actually uses 1-bit punch-through alpha (some block has c0 <= c1 and an index-3
 * texel, which D3D9 and RGBA_S3TC_DXT1 sample as transparent black). `dds.hasAlpha` only says the FORMAT
 * can carry alpha (true for every DXT1); use this to decide alphaTest / transparency. Non-DXT1 -> hasAlpha.
 * Cheap: scans block headers only (no decode). Result for level 0 is cached as dds.punchThrough.
 */
export function dxt1PunchThrough(dds, mipLevel = 0, face = 0) {
  if (dds.format !== 'DXT1') return !!dds.hasAlpha;
  if (mipLevel === 0 && face === 0 && typeof dds.punchThrough === 'boolean') return dds.punchThrough;
  const chain = dds.isCubemap && dds.faces ? (dds.faces[face] || dds.mipmaps) : dds.mipmaps;
  const level = chain[Math.min(mipLevel, chain.length - 1)];
  if (!level) return false;
  const src = level.data;
  for (let o = 0; o + 8 <= src.length; o += 8) {
    const c0 = src[o] | (src[o + 1] << 8), c1 = src[o + 2] | (src[o + 3] << 8);
    if (c0 > c1) continue;
    const idx = (src[o + 4] | (src[o + 5] << 8) | (src[o + 6] << 16) | (src[o + 7] << 24)) >>> 0;
    // any 2-bit index == 3  <=>  some pair of bits is 11
    if ((idx & (idx >>> 1) & 0x55555555) !== 0) return true;
  }
  return false;
}

// ---------------------------------------------------------------------------------------------
// Software decoding (fallback path + tools).

const EXP5 = new Uint8Array(32), EXP6 = new Uint8Array(64);
for (let i = 0; i < 32; i++) EXP5[i] = (i << 3) | (i >> 2);
for (let i = 0; i < 64; i++) EXP6[i] = (i << 2) | (i >> 4);

function decodeColorBlock(src, o, pal, fourColor) {
  const c0 = src[o] | (src[o + 1] << 8), c1 = src[o + 2] | (src[o + 3] << 8);
  const r0 = EXP5[c0 >> 11], g0 = EXP6[(c0 >> 5) & 63], b0 = EXP5[c0 & 31];
  const r1 = EXP5[c1 >> 11], g1 = EXP6[(c1 >> 5) & 63], b1 = EXP5[c1 & 31];
  pal[0] = r0; pal[1] = g0; pal[2] = b0; pal[3] = 255;
  pal[4] = r1; pal[5] = g1; pal[6] = b1; pal[7] = 255;
  if (fourColor || c0 > c1) {
    pal[8] = (2 * r0 + r1 + 1) / 3 | 0; pal[9] = (2 * g0 + g1 + 1) / 3 | 0; pal[10] = (2 * b0 + b1 + 1) / 3 | 0; pal[11] = 255;
    pal[12] = (r0 + 2 * r1 + 1) / 3 | 0; pal[13] = (g0 + 2 * g1 + 1) / 3 | 0; pal[14] = (b0 + 2 * b1 + 1) / 3 | 0; pal[15] = 255;
  } else {
    pal[8] = (r0 + r1 + 1) >> 1; pal[9] = (g0 + g1 + 1) >> 1; pal[10] = (b0 + b1 + 1) >> 1; pal[11] = 255;
    pal[12] = 0; pal[13] = 0; pal[14] = 0; pal[15] = 0; // transparent black (DXT1 punch-through)
  }
}

function decodeBlocks(format, src, width, height) {
  const out = new Uint8Array(width * height * 4);
  const bw = Math.max(1, (width + 3) >> 2), bh = Math.max(1, (height + 3) >> 2);
  const blockBytes = BLOCK_FORMATS[format].blockBytes;
  const pal = new Uint8Array(16);
  const alpha = new Uint8Array(16);
  const apal = new Uint8Array(8);
  const premul = format === 'DXT2' || format === 'DXT4';
  for (let by = 0; by < bh; by++) {
    for (let bx = 0; bx < bw; bx++) {
      const o = (by * bw + bx) * blockBytes;
      if (o + blockBytes > src.length) continue;
      let co = o;
      let hasAlphaBlock = false;
      if (format === 'DXT3' || format === 'DXT2') {
        for (let i = 0; i < 8; i++) { const v = src[o + i]; alpha[i * 2] = (v & 15) * 17; alpha[i * 2 + 1] = (v >> 4) * 17; }
        co = o + 8; hasAlphaBlock = true;
      } else if (format === 'DXT5' || format === 'DXT4' || format === 'ATI1' || format === 'ATI2') {
        decodeAlphaBlock(src, o, apal, alpha);
        co = o + 8; hasAlphaBlock = true;
      }
      if (format === 'ATI1' || format === 'ATI2') {
        // BC4: red = alpha-style block; BC5: red + green blocks.
        const red = alpha.slice();
        let green = null;
        if (format === 'ATI2') { green = new Uint8Array(16); decodeAlphaBlock(src, o + 8, apal, green); }
        for (let py = 0; py < 4; py++) {
          const y = by * 4 + py; if (y >= height) break;
          for (let px = 0; px < 4; px++) {
            const x = bx * 4 + px; if (x >= width) break;
            const d = (y * width + x) * 4, k = py * 4 + px;
            out[d] = red[k]; out[d + 1] = green ? green[k] : red[k]; out[d + 2] = green ? 0 : red[k]; out[d + 3] = 255;
          }
        }
        continue;
      }
      decodeColorBlock(src, co, pal, format !== 'DXT1');
      const idx = src[co + 4] | (src[co + 5] << 8) | (src[co + 6] << 16) | (src[co + 7] << 24);
      for (let py = 0; py < 4; py++) {
        const y = by * 4 + py; if (y >= height) break;
        for (let px = 0; px < 4; px++) {
          const x = bx * 4 + px; if (x >= width) break;
          const k = py * 4 + px;
          const ci = ((idx >>> (k * 2)) & 3) * 4;
          const d = (y * width + x) * 4;
          out[d] = pal[ci]; out[d + 1] = pal[ci + 1]; out[d + 2] = pal[ci + 2];
          out[d + 3] = hasAlphaBlock ? alpha[k] : pal[ci + 3];
          if (premul && out[d + 3] > 0 && out[d + 3] < 255) {
            const a = out[d + 3];
            out[d] = Math.min(255, Math.round(out[d] * 255 / a));
            out[d + 1] = Math.min(255, Math.round(out[d + 1] * 255 / a));
            out[d + 2] = Math.min(255, Math.round(out[d + 2] * 255 / a));
          }
        }
      }
    }
  }
  return out;
}

function decodeAlphaBlock(src, o, apal, alpha) {
  const a0 = src[o], a1 = src[o + 1];
  apal[0] = a0; apal[1] = a1;
  if (a0 > a1) {
    for (let i = 1; i < 7; i++) apal[i + 1] = ((7 - i) * a0 + i * a1 + 3) / 7 | 0;
  } else {
    for (let i = 1; i < 5; i++) apal[i + 1] = ((5 - i) * a0 + i * a1 + 2) / 5 | 0;
    apal[6] = 0; apal[7] = 255;
  }
  // 48 bits of 3-bit indices, little-endian.
  const lo = src[o + 2] | (src[o + 3] << 8) | (src[o + 4] << 16);
  const hi = src[o + 5] | (src[o + 6] << 8) | (src[o + 7] << 16);
  for (let i = 0; i < 8; i++) alpha[i] = apal[(lo >> (i * 3)) & 7];
  for (let i = 0; i < 8; i++) alpha[8 + i] = apal[(hi >> (i * 3)) & 7];
}

function halfToFloat(h) {
  const s = h & 0x8000 ? -1 : 1, e = (h >> 10) & 31, f = h & 1023;
  if (e === 0) return s * f * 2 ** -24;
  if (e === 31) return f ? NaN : s * Infinity;
  return s * (1 + f / 1024) * 2 ** (e - 15);
}
const clamp255 = (v) => (v <= 0 || v !== v ? 0 : v >= 1 ? 255 : Math.round(v * 255));

function decodeMasked(dds, level) {
  const { width: w, height: h, data, pitch } = level;
  const m = dds.masks || (() => { const f = MASK_FORMATS[dds.format]; return { bits: f[0], kind: f[5] || 'RGB', r: f[1], g: f[2], b: f[3], a: f[4] }; })();
  const bpp = m.bits >> 3;
  const out = new Uint8Array(w * h * 4);
  const R = maskInfo(m.r), G = maskInfo(m.g), B = maskInfo(m.b), A = maskInfo(m.a);
  const scale = (v, info) => (info.bits === 8 ? v : info.bits === 0 ? 0 : Math.round(v * 255 / info.max));
  // Fast paths for the layouts that actually occur.
  const fast = dds.format === 'A8R8G8B8' || dds.format === 'X8R8G8B8';
  for (let y = 0; y < h; y++) {
    let s = y * pitch;
    let d = y * w * 4;
    for (let x = 0; x < w; x++, s += bpp, d += 4) {
      if (s + bpp > data.length) { out[d + 3] = 255; continue; }
      if (fast) {
        out[d] = data[s + 2]; out[d + 1] = data[s + 1]; out[d + 2] = data[s];
        out[d + 3] = dds.format === 'A8R8G8B8' ? data[s + 3] : 255;
        continue;
      }
      let px = data[s];
      if (bpp > 1) px |= data[s + 1] << 8;
      if (bpp > 2) px |= data[s + 2] << 16;
      if (bpp > 3) px = (px | (data[s + 3] << 24)) >>> 0;
      if (m.kind === 'L') {
        const l = scale((px & m.r) >>> R.shift, R);
        out[d] = out[d + 1] = out[d + 2] = l;
        out[d + 3] = m.a ? scale((px & m.a) >>> A.shift, A) : 255;
      } else if (m.kind === 'A') {
        out[d] = out[d + 1] = out[d + 2] = 0; // D3D9 A8 samples as (0,0,0,a)
        out[d + 3] = scale((px & m.a) >>> A.shift, A);
      } else if (m.kind === 'UV') {
        // Signed du/dv -> biased unsigned for display.
        const u = (px & m.r) >>> R.shift, v = (px & m.g) >>> G.shift;
        const su = u > (R.max >> 1) ? u - R.max - 1 : u, sv = v > (G.max >> 1) ? v - G.max - 1 : v;
        out[d] = Math.round((su / (R.max >> 1)) * 127.5 + 127.5);
        out[d + 1] = Math.round((sv / (G.max >> 1)) * 127.5 + 127.5);
        out[d + 2] = 255; out[d + 3] = 255;
      } else {
        out[d] = m.r ? scale((px & m.r) >>> R.shift, R) : 0;
        out[d + 1] = m.g ? scale((px & m.g) >>> G.shift, G) : 0;
        out[d + 2] = m.b ? scale((px & m.b) >>> B.shift, B) : 0;
        out[d + 3] = m.a ? scale((px & m.a) >>> A.shift, A) : 255;
      }
    }
  }
  return out;
}

function decodeWide(dds, level) {
  const { width: w, height: h, data } = level;
  const wf = WIDE_FORMATS[dds.format];
  const dv = new DataView(data.buffer, data.byteOffset, data.byteLength);
  const out = new Uint8Array(w * h * 4);
  const comp = wf.type === 'f32' ? 4 : 2;
  for (let i = 0; i < w * h; i++) {
    const s = i * wf.bpp;
    const v = [0, 0, 0, 1];
    if (s + wf.bpp <= data.length) {
      for (let c = 0; c < wf.ch; c++) {
        const o = s + c * comp;
        v[c] = wf.type === 'f32' ? dv.getFloat32(o, true)
          : wf.type === 'f16' ? halfToFloat(dv.getUint16(o, true))
            : wf.type === 's16' ? dv.getInt16(o, true) / 32767 * 0.5 + 0.5
              : dv.getUint16(o, true) / 65535;
      }
    }
    // Channel order in memory is R,G,B,A for all of these (D3DFMT_A16B16G16R16 etc. name MSB->LSB).
    const d = i * 4;
    if (wf.ch === 1) { out[d] = out[d + 1] = out[d + 2] = clamp255(v[0]); out[d + 3] = 255; }
    else if (wf.ch === 2) { out[d] = clamp255(v[0]); out[d + 1] = clamp255(v[1]); out[d + 2] = 0; out[d + 3] = 255; }
    else { out[d] = clamp255(v[0]); out[d + 1] = clamp255(v[1]); out[d + 2] = clamp255(v[2]); out[d + 3] = clamp255(v[3]); }
  }
  return out;
}

/**
 * Software-decode one level (and face) to RGBA8, rows top-down.
 * @param {ReturnType<typeof parseDDS>} dds
 * @param {number} [mipLevel=0]
 * @param {number} [face=0] cubemap face index (+X,-X,+Y,-Y,+Z,-Z)
 * @returns {{ width:number, height:number, data:Uint8Array }}  (volume textures: all slices stacked vertically)
 */
export function decodeToRGBA(dds, mipLevel = 0, face = 0) {
  const chain = dds.isCubemap && dds.faces ? (dds.faces[face] || dds.mipmaps) : dds.mipmaps;
  const level = chain[Math.min(mipLevel, chain.length - 1)];
  if (!level) throw new DDSError('no mip levels', 'EMPTY');
  const slices = level.depth || 1;
  const w = level.width, h = level.height * slices;
  let data;
  if (dds.compressed) {
    if (slices === 1) data = decodeBlocks(dds.format, level.data, w, level.height);
    else {
      data = new Uint8Array(w * h * 4);
      const sliceBytes = level.data.length / slices;
      for (let s = 0; s < slices; s++) data.set(decodeBlocks(dds.format, level.data.subarray(s * sliceBytes, (s + 1) * sliceBytes), w, level.height), s * w * level.height * 4);
    }
  } else if (dds.format === 'P8') {
    data = new Uint8Array(w * h * 4);
    const pal = dds.palette;
    for (let i = 0; i < w * h; i++) {
      const p = (level.data[i] || 0) * 4;
      data[i * 4] = pal[p]; data[i * 4 + 1] = pal[p + 1]; data[i * 4 + 2] = pal[p + 2]; data[i * 4 + 3] = pal[p + 3];
    }
  } else if (WIDE_FORMATS[dds.format]) {
    data = decodeWide(dds, { ...level, height: h });
  } else {
    data = decodeMasked(dds, { ...level, height: h });
  }
  return { width: w, height: h, data };
}

/**
 * Convenience for THREE.DataTexture uploads of uncompressed DDS: every level converted to RGBA8.
 * @returns {{ width:number, height:number, data:Uint8Array }[]}
 */
export function decodeAllLevelsRGBA(dds, face = 0) {
  const chain = dds.isCubemap && dds.faces ? (dds.faces[face] || dds.mipmaps) : dds.mipmaps;
  return chain.map((_, i) => decodeToRGBA(dds, i, face));
}
