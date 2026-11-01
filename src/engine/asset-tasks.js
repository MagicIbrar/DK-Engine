// CPU-only task implementations: usable in module Workers and the compatibility fallback.
import { parseMesh } from '../formats/mesh.js';
import { parseSkel } from '../formats/skel.js';
import { parseAnim } from '../formats/anim.js';
import { parseDDS, webglCompressedPlan, decodeToRGBA } from '../formats/dds.js';
import { analyseDDSAlpha, analyseRGBA, rgbaMipChain, encodeDXTMips, ENCODABLE } from './texture-codec.js';

export function prepareDDS(buffer, options) {
  const dds = parseDDS(new Uint8Array(buffer));
  const { s3tc, decode, mipmaps } = options;
  const compressed = webglCompressedPlan(dds).ok && s3tc && !dds.premultiplied && !decode &&
    (dds.isCubemap || mipmaps !== 'generate');
  const result = { dds, alpha: null, encodedMips: null, img: null, rgbaMips: null, cubeImages: null };
  if (dds.isCubemap && dds.faces) {
    if (!compressed) result.cubeImages = dds.faces.map((_, f) => decodeToRGBA(dds, 0, f));
    return result;
  }
  result.alpha = analyseDDSAlpha(dds);
  if (compressed) {
    if (mipmaps === 'auto' && dds.mipmaps.length === 1 && Math.max(dds.width, dds.height) > 1 && ENCODABLE.has(dds.format)) {
      try {
        result.encodedMips = encodeDXTMips(dds.format, decodeToRGBA(dds, 0), { punch: dds.format === 'DXT1' && !!dds.punchThrough });
      } catch (err) { result.mipError = String(err?.message || err); } // keep the original file texture usable
    }
  } else {
    result.img = decodeToRGBA(dds, 0);
    if (!result.alpha) result.alpha = analyseRGBA(result.img.data);
    const wants = mipmaps !== 'none' && (mipmaps !== 'file' || dds.mipmaps.length > 1);
    if (wants && result.alpha.hasAlpha) result.rgbaMips = rgbaMipChain(result.img);
  }
  return result;
}

export function runAssetTask(type, buffer, options = {}) {
  switch (type) {
    case 'mesh': return parseMesh(buffer);
    case 'skeleton': return parseSkel(buffer);
    case 'anim': return parseAnim(buffer);
    case 'dds': return prepareDDS(buffer, options);
    default: throw new Error(`Unknown asset task: ${type}`);
  }
}

export function transferBuffers(value, out = new Set(), seen = new Set()) {
  if (!value || typeof value !== 'object' || seen.has(value)) return [...out];
  seen.add(value);
  if (value instanceof ArrayBuffer) out.add(value);
  else if (ArrayBuffer.isView(value)) out.add(value.buffer);
  else for (const item of Object.values(value)) transferBuffers(item, out, seen);
  return [...out];
}
