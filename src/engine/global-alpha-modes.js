// Global 43.19 mesh alpha modes (LANE-54, 2026-10-29). Replaces the ENGINE-CHOSEN alphaTest 0.5 cut-out of models.js material().
// Evidence (read-only, decompile; reimplemented, not copied):
//  * Texture alpha class: 32-bit FUN_0151e070 (texture resource +0x48) by the loaded D3D format:
//      DXT1 / A1R5G5B5 (D3DFMT 25)          -> 1, or 0 when the name is listed in script/DXTAlphaFilterTable.txt
//                                              (DAT_01f9b7a0, filled by LoadData_DXTAlphaFilterTable_txt 007822d0;
//                                              64-bit UsesFile_DXTAlphaFilterTable_txt 7ff67086a4e0)
//      DXT3 / DXT5 / A8R8G8B8 (21) / A4R4G4B4 (26) -> 2
//      anything else (DXT2, DXT4, X8R8G8B8, R5G6B5, P8, ...) -> 0
//  * Routing per subset: 64-bit Bone::Normal submit FUN_7ff6716aa930: class 2 (or material alpha != 0xFF) -> blended bucket,
//      a '#' in the texture name -> the '#' blended bucket; else class 1 -> cut-out bucket; else opaque bucket.
//  * Bucket render states: FUN_7ff6716c9870 (32-bit FUN_0158b790 via queue FUN_0158b0b0/FUN_0158b460):
//      opaque: blend off, alpha test off
//      cut-out: blend off, ALPHATEST GREATER, ALPHAREF 0xF0 (240)
//      blended: blend on, ALPHATEST GREATER, ALPHAREF 1, SrcAlpha/InvSrcAlpha; with the additive flag SrcAlpha/One
//  * Bone::Normal vf01 7ff6716aafb0 draws opaque + cut-out with flag 0; vf02 7ff6716ab000 draws the blended bucket with
//      flag 0 and the '#' bucket with flag 1 -> '#' textures in the blended path are ADDITIVE.
//  * Item meshes FUN_7ff6716b8ab0 use the same split (class 1 -> ref 240, else blended ref 1, '#' additive).
//  * Depth writes: neither the Bone::Normal draw nor the MeshImpl presets set D3DRS_ZWRITEENABLE (0xe); the bone passes
//      around them (FUN_7ff6716c6940, ref_ShadowBoneDepth_*) restore it to 1. Depth writes stay on.
// Alpha-test equality (LANE-54 pass 5): D3DCMP_GREATER passes an 8-bit alpha only when it is > ALPHAREF (Microsoft D3D9
// D3DCMPFUNC / D3DRS_ALPHAFUNC docs), three.js discards alpha < alphaTest. alphaTest = (ref + 0.5) / 255, the midpoint of the
// 8-bit steps ref and ref + 1, so alpha byte <= ref is discarded and >= ref + 1 kept, as D3D does (robust to float sampling).
//  * The "alpha != 0xFF -> blended" test of FUN_7ff6716aa930 reads the per-instance packed colour of the 0x70 Bone::Normal
//      record (+0x14, built by FUN_7ff6712a7cd0 from the submitter's D3DCOLOR; packing FUN_7ff670862010), NOT a mesh-file
//      material. Map objects (Ghost::DollObject::Field::FieldImpl slot 3 FUN_7ff671737340 -> FUN_7ff6717378a0) submit
//      0xFFFFFFFF, so their routing is the texture class alone (globalAlphaMode). Effect Mesh units submit their animated
//      RGBA (globalEffectMeshMode); MeshImpl FUN_7ff6716c9fc0 sets f4GlobalColor (shader handle 0xc) = colour/255 and,
//      for transparent records (entry+0x23), alpha = min(entry+0x22 (pool default 0xFF, FUN_7ff67165c1e0), A) / 255.
//      Device stage 0 ALPHAOP MODULATE(TEXTURE, DIFFUSE) (FUN_7ff67166c9b0) -> output alpha = texel alpha * unit alpha.
//  * Non-DDS images: 32-bit FUN_0151e070 loads every file through D3DXGetImageInfoFromFileInMemory + D3DXCreateTexture-
//      FromFileInMemoryEx with Format = the file's own D3DX format, then classifies that format like a DDS one. Which
//      D3DFORMAT D3DX reports for each container is library behaviour (online secondary): d3dxImageFormat.
//  * Palette PNG (colour type 3, with or without tRNS): D3DFMT_P8 (online: Wine d3dx9_36 D3DXGetImageInfoFromFileInMemory
//      PNG_COLOR_TYPE_PALETTE -> D3DFMT_P8) -> class 0 by FUN_0151e070 (32-bit main: the class reads the D3DXIMAGE_INFO Format,
//      local_64 -> texture +0x38, not the created surface). The Global data ships no palette PNG under texture/ or mesh/.
//  * 16-bit-per-channel PSD: REMOVED from the format table (null). The only one, texture/item/eff_bag_squirrel.psd, has no
//      consumer: texturepack/item/armor/wing/wing_bag_squirrel_up.tpack names eff_BAG_SQUIRREL.dds (a real DDS).
import { normPath } from './assets.js';

export const ALPHA_REF_BYTES = Object.freeze({ CUTOUT: 0xf0, BLEND: 1 });   // FUN_7ff6716c9870 D3DRS_ALPHAREF values
/** three.js alphaTest equivalent of D3D ALPHATEST GREATER with ALPHAREF ref (alpha byte <= ref discarded). */
export const alphaRefThreshold = ref => (ref + 0.5) / 255;
export const GLOBAL_ALPHA_REF = Object.freeze({ CUTOUT: alphaRefThreshold(ALPHA_REF_BYTES.CUTOUT), BLEND: alphaRefThreshold(ALPHA_REF_BYTES.BLEND) });
export const DXT_ALPHA_FILTER_TABLE = 'script/dxtalphafiltertable.txt';
const CLASS1 = new Set(['DXT1', 'A1R5G5B5']);
const CLASS2 = new Set(['DXT3', 'DXT5', 'A8R8G8B8', 'A4R4G4B4']);
const DDS_FORMATS = new Set(['DXT1', 'DXT2', 'DXT3', 'DXT4', 'DXT5', 'ATI1', 'ATI2', 'R8G8B8', 'A8R8G8B8', 'X8R8G8B8', 'R5G6B5',
  'X1R5G5B5', 'A1R5G5B5', 'A4R4G4B4', 'A8B8G8R8', 'X8B8G8R8', 'P8', 'L8', 'A8L8', 'A8']);

/** DXTAlphaFilterTable.txt lines are paths under texture/ ("object/x.dds"): a Set of normalised data keys. */
export function parseDxtAlphaFilterTable(text) {
  const out = new Set();
  for (const raw of String(text || '').split(/\r?\n/)) {
    const line = raw.trim();
    if (!line) continue;
    out.add(normPath(`texture/${line}`));
  }
  return out;
}

/** True when the format string came from a DDS header (the only case the Global rule is applied to). */
export function isDdsFormat(format) { return DDS_FORMATS.has(String(format || '').toUpperCase()); }

/** FUN_0151e070 texture alpha class: 0 none, 1 cut-out, 2 blended. */
export function textureAlphaClass(format, key, filter = null) {
  const f = String(format || '').toUpperCase();
  if (CLASS2.has(f)) return 2;
  if (CLASS1.has(f)) return filter && key && filter.has(normPath(key)) ? 0 : 1;
  return 0;
}

/** True when the texture file name contains '#' (Bone::Normal '#' bucket). */
export function isHashTexture(key) {
  const k = String(key || '');
  return k.slice(k.lastIndexOf('/') + 1).includes('#');
}

/**
 * Global draw mode for a texture: { mode: 'opaque' | 'cutout' | 'blend' | 'additive', alphaTest, cls }.
 * alphaKind 'none' (every texel alpha 255) in a non-'#' blended texture draws exactly like opaque (SrcAlpha/InvSrcAlpha of
 * alpha 1 = source), so it stays opaque; a '#' texture adds even at alpha 1, so it is additive regardless.
 */
export function globalAlphaMode({ format, key, alphaKind } = {}, filter = null) {
  const cls = textureAlphaClass(format, key, filter);
  if (cls === 2) {
    if (isHashTexture(key)) return { mode: 'additive', alphaTest: GLOBAL_ALPHA_REF.BLEND, cls };
    if (alphaKind === 'none') return { mode: 'opaque', alphaTest: 0, cls };
    return { mode: 'blend', alphaTest: GLOBAL_ALPHA_REF.BLEND, cls };
  }
  if (cls === 1) return { mode: 'cutout', alphaTest: alphaKind === 'none' ? 0 : GLOBAL_ALPHA_REF.CUTOUT, cls };
  return { mode: 'opaque', alphaTest: 0, cls };
}

/** D3DXCOLOR channel -> D3DCOLOR byte (64-bit FUN_7ff670862010: >= 1 -> 255, <= 0 -> 0, else trunc(v * 255 + 0.5)). */
export function packColorByte(v) {
  const n = Number(v);
  if (!(n > 0)) return 0;
  if (n >= 1) return 255;
  return Math.trunc(n * 255 + 0.5);
}

/**
 * Global draw mode of one effect Mesh unit layer (Bone::Normal submit FUN_7ff6716aa930 with the unit's packed colour):
 *  transparent true  -> transparent bucket (+0x28) or, '#' texture, transparent '#' bucket (+0x30, additive); ref 1.
 *  transparent false -> class 2 or alpha byte != 0xFF -> blended bucket (+0x18) or '#' bucket (+0x20, additive); ref 1;
 *                       else class 1 -> cut-out (ref 240, no blend); else opaque.
 * Output alpha = texel alpha * unit alpha in every bucket (stage 0 MODULATE). Returns { mode, alphaTest, cls, bucket, alphaByte }.
 */
export function globalEffectMeshMode({ format, key } = {}, { transparent = false, alpha = 1 } = {}, filter = null) {
  const cls = textureAlphaClass(format, key, filter);
  const hash = isHashTexture(key);
  const alphaByte = packColorByte(alpha);
  const B = GLOBAL_ALPHA_REF.BLEND;
  if (transparent) return { mode: hash ? 'additive' : 'blend', alphaTest: B, cls, bucket: hash ? 'transparent#' : 'transparent', alphaByte };
  if (cls === 2 || alphaByte !== 0xff) return { mode: hash ? 'additive' : 'blend', alphaTest: B, cls, bucket: hash ? 'blend#' : 'blend', alphaByte };
  if (cls === 1) return { mode: 'cutout', alphaTest: GLOBAL_ALPHA_REF.CUTOUT, cls, bucket: 'cutout', alphaByte };
  return { mode: 'opaque', alphaTest: 0, cls, bucket: 'opaque', alphaByte };
}

/**
 * D3DFORMAT that D3DX reports for a non-DDS image (online secondary: D3DX9 file loader behaviour), from the file header.
 * TGA: 32 bpp + alpha bits A8R8G8B8, 32 bpp X8R8G8B8, 24 R8G8B8, 16 + 1 alpha bit A1R5G5B5, 16 X1R5G5B5, colour-mapped P8,
 * grey L8. BMP: 32 X8R8G8B8 (BI_RGB), 24 R8G8B8, 16 X1R5G5B5, <= 8 P8. PNG: RGBA8 A8R8G8B8, RGB8 X8R8G8B8, grey L8,
 * grey+alpha A8L8, palette P8. JPEG X8R8G8B8. PSD RGB 8-bit: >= 4 channels A8R8G8B8, 3 X8R8G8B8. Anything else -> null (no
 * format: the previous material handling; Global data has no such texture in use - see the header).
 */
export function d3dxImageFormat(u8) {
  const b = u8 instanceof Uint8Array ? u8 : new Uint8Array(u8 || []);
  const n = b.length;
  const u16le = o => b[o] | (b[o + 1] << 8);
  const u16be = o => (b[o] << 8) | b[o + 1];
  if (n >= 8 && b[0] === 0x89 && b[1] === 0x50 && b[2] === 0x4e && b[3] === 0x47) {
    if (n < 26) return null;
    const depth = b[24], ct = b[25];
    if (ct === 3 && depth <= 8) return 'P8';   // palette (Wine d3dx9: P8); tRNS does not change the reported format
    if (depth !== 8) return null;
    return ({ 6: 'A8R8G8B8', 2: 'X8R8G8B8', 0: 'L8', 4: 'A8L8', 3: 'P8' })[ct] || null;
  }
  if (n >= 3 && b[0] === 0xff && b[1] === 0xd8 && b[2] === 0xff) return 'X8R8G8B8';
  if (n >= 26 && b[0] === 0x38 && b[1] === 0x42 && b[2] === 0x50 && b[3] === 0x53) {
    const ch = u16be(12), depth = u16be(22), mode = u16be(24);
    if (mode !== 3 || depth !== 8) return null;
    return ch >= 4 ? 'A8R8G8B8' : ch === 3 ? 'X8R8G8B8' : null;
  }
  if (n >= 30 && b[0] === 0x42 && b[1] === 0x4d) {
    const bpp = u16le(28);
    if (bpp === 32) return 'X8R8G8B8';
    if (bpp === 24) return 'R8G8B8';
    if (bpp === 16) return 'X1R5G5B5';
    if (bpp > 0 && bpp <= 8) return 'P8';
    return null;
  }
  if (n >= 18) {
    const type = b[2] & ~8, bpp = b[16], abits = b[17] & 15;
    if (type === 1) return 'P8';
    if (type === 3) return bpp === 8 ? 'L8' : null;
    if (type === 2) {
      if (bpp === 32) return abits ? 'A8R8G8B8' : 'X8R8G8B8';
      if (bpp === 24) return 'R8G8B8';
      if (bpp === 16 || bpp === 15) return abits ? 'A1R5G5B5' : 'X1R5G5B5';
    }
  }
  return null;
}
