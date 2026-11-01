// Per-map texture sampler state of the client (textures dull / flat vs the original).
//
// The client draws every map with the Direct3D 9 sampler state its share/maplist.csv row names: MipMapEnable,
// MipMapBias, MipMapFilter, MaxFilter, MinFilter (D3DTEXTUREFILTERTYPE 0 NONE, 1 POINT, 2 LINEAR, 3 ANISOTROPIC).
// Fields and dungeons mostly sample POINT within a mip level with a -0.5 LOD bias (Deneb, Braiken, Loa: sharper than
// the trilinear default), many maps sample no mips at all (MipMapFilter 0: Draco Desert, Requies Beach, Avalon...),
// the selection maps use a -10 bias (always the full-size level). The engine used to draw everything trilinear with
// anisotropy 4 and no bias, which softens the textures at every distance.
//
// samplerFromMapRow(row) -> state; threeFilters(state, hasMips) -> three.js filters; MIP_BIAS is the uniform the lit
// world materials add to their diffuse lookup (src/world/shade.js); TextureCache.setSampler (src/engine/textures.js)
// applies the filters. The values not in the data are ENGINE-CHOSEN in src/engine/material-constants.js.
import * as THREE from 'three';
import { SAMPLER_ANISOTROPY } from './material-constants.js';

export const D3DTEXF = Object.freeze({ NONE: 0, POINT: 1, LINEAR: 2, ANISOTROPIC: 3 });
// Global data/binary/billboard.fx overrides the map sampler for this pass.
export const BILLBOARD_SAMPLER = Object.freeze({source:'billboard',mag:2,min:2,mip:1,bias:0,anisotropy:1});

/** LOD bias of the current map, shared by every shade.js-patched material (no recompiles on map change). */
export const MIP_BIAS = { value: 0 };

/** No map loaded (front-end, tools, tests): the engine default (material-constants.js SAMPLER_DEFAULT). */
export const DEFAULT_SAMPLER = Object.freeze({ source: 'default', mag: D3DTEXF.LINEAR, min: D3DTEXF.LINEAR, mip: D3DTEXF.LINEAR, bias: 0, anisotropy: null });

const num = v => (v === '' || v == null ? NaN : Number(v));

/** Magnification / minification filter: NONE samples as POINT, out of range as LINEAR (SAMPLER_NONE_FILTER). */
function texFilter(v) {
  const n = num(v);
  if (!Number.isInteger(n) || n < 0 || n > 3) return D3DTEXF.LINEAR;
  return n === D3DTEXF.NONE ? D3DTEXF.POINT : n;
}
/** Mip filter: NONE = no mips; out of range = LINEAR. */
function mipFilter(v) {
  const n = num(v);
  if (!Number.isInteger(n) || n < 0 || n > 3) return D3DTEXF.LINEAR;
  return n === D3DTEXF.ANISOTROPIC ? D3DTEXF.LINEAR : n;
}

/**
 * Sampler state of a maplist row (raw CSV columns) or of environment.js mapEnvironmentInfo().mipmap
 * ({enable, bias, filter, maxFilter, minFilter}). null / no columns -> DEFAULT_SAMPLER.
 */
export function samplerFromMapRow(row) {
  if (!row) return DEFAULT_SAMPLER;
  const m = 'MipMapFilter' in row || 'MinFilter' in row
    ? { enable: row.MipMapEnable, bias: row.MipMapBias, filter: row.MipMapFilter, maxFilter: row.MaxFilter, minFilter: row.MinFilter }
    : row;
  if (m.filter === undefined && m.minFilter === undefined && m.maxFilter === undefined) return DEFAULT_SAMPLER;
  const bias = num(m.enable) === 1 && Number.isFinite(num(m.bias)) ? num(m.bias) : 0;   // SAMPLER_BIAS_GATE
  const min = texFilter(m.minFilter);
  return Object.freeze({
    source: 'maplist', mag: texFilter(m.maxFilter), min, mip: mipFilter(m.filter), bias,
    anisotropy: min === D3DTEXF.ANISOTROPIC ? null : SAMPLER_ANISOTROPY,
  });
}

/**
 * three.js filters of a state for a texture with / without a mip chain.
 * @returns {{magFilter:number, minFilter:number, anisotropy:number|null}}  anisotropy null = keep the texture's own
 */
export function threeFilters(s, hasMips) {
  const st = s || DEFAULT_SAMPLER;
  const magFilter = st.mag === D3DTEXF.POINT ? THREE.NearestFilter : THREE.LinearFilter;
  const lin = st.min !== D3DTEXF.POINT;
  let minFilter;
  if (!hasMips || st.mip === D3DTEXF.NONE) minFilter = lin ? THREE.LinearFilter : THREE.NearestFilter;
  else if (st.mip === D3DTEXF.POINT) minFilter = lin ? THREE.LinearMipmapNearestFilter : THREE.NearestMipmapNearestFilter;
  else minFilter = lin ? THREE.LinearMipmapLinearFilter : THREE.NearestMipmapLinearFilter;
  return { magFilter, minFilter, anisotropy: st.anisotropy };
}

/** The texture carries (or will generate) a mip chain. */
export function textureHasMips(tex) {
  return !!tex && ((Array.isArray(tex.mipmaps) && tex.mipmaps.length > 1) || tex.generateMipmaps === true);
}

/** GLSL: three's map_fragment with the map LOD bias (texture(sampler, uv, bias): D3DSAMP_MIPMAPLODBIAS). */
export const MAP_FRAGMENT_BIAS = THREE.ShaderChunk.map_fragment.replace('texture2D( map, vMapUv )', 'texture2D( map, vMapUv, dkMipBias )');
export const MIP_BIAS_GLSL = 'uniform float dkMipBias;';