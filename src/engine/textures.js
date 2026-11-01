// TextureCache: game texture files -> THREE textures (docs/ARCHITECTURE.md §3.1).
//
// Rules (ARCHITECTURE.md §1 + ENGINE_NOTES "DDS"):
//  * content is sniffed first: 41 PNGs, 1 JPEG and 2 PSDs hide behind *.dds names.
//  * DDS DXT1/3/5 -> THREE.CompressedTexture. Level 0 (and any mip levels the file has) are uploaded bit-exact; DXT1
//    always as RGBA_S3TC_DXT1 so the 1-bit punch-through alpha survives, as in D3D9. Cubemaps -> CompressedCubeTexture.
//  * Mip chains: nearly every client DDS is single-level (declared mip count 1). D3DX (D3DXCreateTextureFromFile with
//    D3DX_DEFAULT levels), which the original client used, builds the missing levels itself IN THE FILE'S FORMAT. We do
//    the same: box-filter the decoded level 0 and re-encode each level to DXT1/3/5 (encodeDXTMips below), so the GPU
//    keeps DXT memory (8x smaller than RGBA8 for DXT1) and distant surfaces do not shimmer. opts.mipmaps = 'file'
//    uploads exactly the file's chain instead.
//  * Everything else (uncompressed D3DFMTs, level 0 not a multiple of 4, no S3TC extension, premultiplied DXT2/4,
//    opts.decode) -> decodeToRGBA -> THREE.DataTexture with a mip chain (CPU box filter when the texture has alpha,
//    GPU generateMipmap otherwise).
//  * Mip box filter weights colour by alpha, so the black texels behind DXT1 punch-through (and other cut-outs) do not
//    bleed dark rims into distant hair / foliage.
//  * .tga/.bmp/.psd via src/formats/image.js; .png/.jpg via createImageBitmap (image.js decodeImageAsync).
//  * EVERY texture: colorSpace = NoColorSpace (DX9 gamma-space look), flipY = false (D3D rows are top-first and the
//    mesh UVs are used as stored), RepeatWrapping (unless opts.repeat === false), anisotropy 4.
//  * texture.userData = { key, hasAlpha, alphaKind, format, width, height, compressed, mipLevels, mipSource, ... }:
//      hasAlpha  = the image really contains non-opaque texels (DXT1: punch-through blocks present; others: scanned).
//      alphaKind = 'none' | 'binary' (every texel ~0 or ~255: cut-out) | 'smooth' (real translucency).
//      mipSource = 'file' | 'encoded' (DXT re-encoded) | 'cpu' | 'gpu' | 'none'.
//    A 32-bit BMP's alpha is a mask in this corpus (to_in_spider_egg_02, ENGINE_NOTES), so BMP alpha never counts.
//  * load() never throws: a missing / undecodable file resolves null and is logged once.
//  * Sampler state: setSampler(state) gives every 2D texture the current map's maplist filters
//    (src/engine/sampler-state.js); the anisotropy 4 / trilinear above is the no-map default.
import * as THREE from 'three';
import { tryFetchBuffer, normPath } from './assets.js';
import { sniffImageType, webglCompressedPlan, decodeToRGBA } from '../formats/dds.js';
import { breathe } from './yield.js';
import { assetWork } from './asset-work.js';
import { TextureUploads } from './texture-uploads.js';
import { decodeTGA, decodeBMP, decodePSD, decodeImageAsync } from '../formats/image.js';
import { DEFAULT_SAMPLER, MIP_BIAS, threeFilters, textureHasMips } from './sampler-state.js';
import { recordTextureRequest } from './prefetch.js';

const MIP_FILTERS = new Set([THREE.NearestMipmapNearestFilter, THREE.NearestMipmapLinearFilter, THREE.LinearMipmapNearestFilter, THREE.LinearMipmapLinearFilter]);

const warned = new Set();
function warnOnce(key, msg) {
  if (warned.has(key)) return;
  warned.add(key);
  console.warn(`[textures] ${msg}`);
}

import { classifyCounts, analyseRGBA, analyseDDSAlpha, rgbaMipChain, ENCODABLE, encodeDXTMips } from './texture-codec.js';
export { downsampleRGBA, encodeDXT, encodeDXTMips } from './texture-codec.js';

// ------------------------------------------------------------------------------------------ cache
function optsKey(o) {
  return `r${o.repeat ? 1 : 0}a${o.anisotropy}m${o.mipmaps}d${o.decode ? 1 : 0}s${o.fixedSampler ? JSON.stringify([o.fixedSampler.mag,o.fixedSampler.min,o.fixedSampler.mip,o.fixedSampler.anisotropy]) : 'map'}`;
}

export class TextureCache {
  /**
   * @param {THREE.WebGLRenderer|null} renderer  (null in Node tests: everything takes the RGBA path)
   * @param {{anisotropy?:number}} [options]
   */
  constructor(renderer = null, { anisotropy = 4 } = {}) {
    this.renderer = renderer;
    this.uploads = new TextureUploads(renderer);
    let s3tc = false, maxAniso = 1;
    try {
      s3tc = !!renderer?.extensions?.has?.('WEBGL_compressed_texture_s3tc');
      maxAniso = renderer?.capabilities?.getMaxAnisotropy?.() || 1;
    } catch { /* headless */ }
    this.s3tc = s3tc;
    this.anisotropy = Math.max(1, Math.min(anisotropy, maxAniso));
    this._cache = new Map();          // key|opts -> Promise<Texture|null>
    this._textures = new Map();       // key|opts -> Texture (resolved, for dispose/stats)
    this.stats = { requested: 0, loaded: 0, missing: 0, failed: 0, compressed: 0, decoded: 0, encodedMips: 0 };
    this.sampler = DEFAULT_SAMPLER;  // the current map's sampler state (setSampler)
    this._fixedSamplers = new WeakMap();
    this._aniso = new WeakMap();      // texture -> its requested anisotropy (the no-map default)

    const px = new Uint8Array([128, 128, 128, 255]);
    this.placeholder = this._dataTexture({ data: px, width: 1, height: 1 }, { repeat: true, mipmaps: 'none', anisotropy: 1 }, false);
    this.placeholder.name = 'placeholder';
    this.placeholder.userData = { key: null, hasAlpha: false, alphaKind: 'none', format: 'placeholder', width: 1, height: 1 };
  }

  _norm(opts = {}) {
    return {
      repeat: opts.repeat !== false,
      anisotropy: opts.anisotropy != null ? Math.max(1, Math.min(opts.anisotropy, 16)) : this.anisotropy,
      // 'auto': file chain when there is one, else a generated chain (DXT re-encode / CPU / GPU)
      // 'file': the file's chain only · 'generate': always decode to RGBA + generated chain · 'none': level 0 only
      mipmaps: opts.mipmaps || 'auto',
      decode: !!opts.decode,
      fixedSampler: opts.fixedSampler ? Object.freeze({...opts.fixedSampler}) : null,
    };
  }

  /**
   * Load a texture by data key ('texture/monster/spider.dds'). Resolves null (never rejects) when the file is missing
   * or undecodable; the failure is logged once per key.
   * @param {string} key
   * @param {{repeat?:boolean, srgb?:boolean, anisotropy?:number, mipmaps?:'auto'|'file'|'generate'|'none', decode?:boolean, sampler?:object, priority?:string}} [opts]
   *   srgb is accepted for API compatibility and ignored: every texture is NoColorSpace (ARCHITECTURE.md colour rule).
   *   fixedSampler: shader-owned filters; separate cache entry, preserved across map transitions.
   *   sampler (engine/prefetch.js): the sampler state this texture gets instead of the current one (a texture loaded ahead
   *   for another map); priority: fetch priority hint. Neither is part of the cache key.
   */
  load(key, opts = {}) {
    if (!key) return Promise.resolve(null);
    const k = normPath(key);
    const o = this._norm(opts);
    recordTextureRequest(k, o);
    const ck = `${k}|${optsKey(o)}`;
    let p = this._cache.get(ck);
    if (!p) {
      this.stats.requested++;
      p = this._load(k, o, !!opts._quiet, opts.sampler || null, opts.priority || null).then(tex => {
        if (tex) { this._textures.set(ck, tex); this.stats.loaded++; }
        return tex;
      }, err => {
        this.stats.failed++;
        // The fetch layer retains the failed request through its backoff. A
        // transient failure must not also become a permanent null texture.
        if (err?.transient && this._cache.get(ck) === p) this._cache.delete(ck);
        warnOnce(k, `failed ${k}: ${err && err.message || err}`);
        return null;
      });
      this._cache.set(ck, p);
    }
    return p;
  }

  /** First existing + decodable texture of a candidate list (e.g. tpack.js resolveTexture). Missing candidates are
   *  silent; one warning when none of them loads. */
  async loadFirst(keys, opts = {}) {
    const list = (keys || []).filter(Boolean);
    for (const k of list) {
      const tex = await this.load(k, { ...opts, _quiet: true });
      if (tex) return tex;
    }
    if (list.length) warnOnce(`first:${normPath(list[0])}`, `no texture found for ${normPath(list[0])} (${list.length} candidates)`);
    return null;
  }

  /** Synchronous lookup of an already-loaded texture (or undefined). */
  peek(key, opts = {}) {
    return this._textures.get(`${normPath(key)}|${optsKey(this._norm(opts))}`);
  }

  /**
   * Sampler state of the current map (sampler-state.js samplerFromMapRow; null = engine default). Re-filters every
   * loaded 2D texture (changed ones re-upload through the upload queue: three sets sampler parameters at upload) and
   * sets the shared LOD bias uniform. Returns the number of textures whose filters changed.
   */
  setSampler(state) {
    this.sampler = state || DEFAULT_SAMPLER;
    MIP_BIAS.value = Number(this.sampler.bias) || 0;
    let changed = 0;
    for (const tex of this._textures.values()) {
      if (this._applySampler(tex) !== true) continue;
      changed++;
      this.uploads.upload(tex).catch(() => {});
    }
    return changed;
  }

  /**
   * Give one texture the current sampler filters. true = changed (needsUpdate set), false = unchanged, 'defer' = a
   * GPU-generated chain must be built first (three generates mips at the first upload only when the filter samples
   * them): call again after that upload.
   */
  _applySampler(tex, beforeUpload = false, state = null) {
    if (!tex || tex === this.placeholder || tex.isCubeTexture || tex.userData?.cube) return false;
    const f = threeFilters(this._fixedSamplers.get(tex) || state || this.sampler, textureHasMips(tex));
    if (beforeUpload && tex.generateMipmaps && !MIP_FILTERS.has(f.minFilter)) return 'defer';
    const aniso = f.anisotropy ?? (this._aniso.get(tex) ?? tex.anisotropy);
    if (tex.minFilter === f.minFilter && tex.magFilter === f.magFilter && tex.anisotropy === aniso) return false;
    tex.minFilter = f.minFilter; tex.magFilter = f.magFilter; tex.anisotropy = aniso;
    tex.needsUpdate = true;
    return true;
  }

  /** Dispose textures whose key matches filter (GPU memory) and drop them from the cache. */
  clear(filter = () => true) {
    for (const [ck, tex] of [...this._textures]) {
      const key = ck.slice(0, ck.lastIndexOf('|'));
      if (!filter(key)) continue;
      tex.dispose();
      this._textures.delete(ck);
      this._cache.delete(ck);
    }
  }

  // ---------------------------------------------------------------------------------------- internals
  async _load(key, o, quiet, sampler = null, priority = null) {
    const buf = await tryFetchBuffer(key, priority ? { priority } : undefined);
    if (!buf) {
      this.stats.missing++;
      if (!quiet) warnOnce(key, `missing ${key}`);
      return null;
    }
    await breathe();                 // time-slice decoding / mip encoding across frames (engine/yield.js)
    const u8 = new Uint8Array(buf);
    const kind = sniffImageType(u8);
    let tex;
    switch (kind) {
      case 'dds': {
        const prepared = await assetWork('dds', buf, { ...o, s3tc: this.s3tc });
        tex = this._fromDDS(prepared.dds, key, o, prepared);
        break;
      }
      case 'tga': tex = this._fromRGBA(decodeTGA(u8), key, o, 'TGA'); break;
      case 'bmp': tex = this._fromRGBA(decodeBMP(u8), key, o, 'BMP', { ignoreAlpha: true }); break;
      case 'psd': tex = this._fromRGBA(decodePSD(u8), key, o, 'PSD'); break;
      case 'png': case 'jpeg': case 'gif': tex = this._fromRGBA(await decodeImageAsync(u8), key, o, kind.toUpperCase()); break;
      default: throw new Error(`unrecognised image data (${kind})`);
    }
    const later = this._applySampler(tex, true, sampler) === 'defer';   // The map's sampler state from the start
    const up = this.uploads.upload(tex);
    return later ? up.then(t => { if (this._applySampler(t, false, sampler) === true) return this.uploads.upload(t); return t; }) : up;
  }

  _common(tex, key, o) {
    tex.name = key;
    tex.flipY = false;
    tex.colorSpace = THREE.NoColorSpace;
    tex.wrapS = tex.wrapT = o.repeat ? THREE.RepeatWrapping : THREE.ClampToEdgeWrapping;
    tex.anisotropy = o.anisotropy;
    this._aniso?.set(tex, o.anisotropy);
    if (o.fixedSampler) this._fixedSamplers.set(tex, o.fixedSampler);
    tex.magFilter = THREE.LinearFilter;
    tex.needsUpdate = true;
    return tex;
  }

  /**
   * RGBA8 image -> DataTexture. Mips (unless 'none'/'file'): a CPU alpha-weighted chain when the image has alpha
   * (cut-out edges stay clean), else GPU generateMipmap.
   */
  _dataTexture(img, o, hasAlpha, preparedMips = null) {
    const { data, width, height } = img;
    const tex = new THREE.DataTexture(data, width, height, THREE.RGBAFormat, THREE.UnsignedByteType);
    const wantMips = o.mipmaps !== 'none' && o.mipmaps !== 'file' && (width > 1 || height > 1);
    let source = 'none';
    tex.generateMipmaps = false;
    if (wantMips && hasAlpha) {
      tex.mipmaps = preparedMips || rgbaMipChain(img);
      source = 'cpu';
    } else if (wantMips) {
      tex.generateMipmaps = true;
      source = 'gpu';
    }
    tex.minFilter = wantMips ? THREE.LinearMipmapLinearFilter : THREE.LinearFilter;
    tex.unpackAlignment = 1;
    this._common(tex, '', o);
    tex.userData.mipSource = source;
    return tex;
  }

  _fromRGBA(img, key, o, format, { ignoreAlpha = false } = {}) {
    const a = ignoreAlpha ? classifyCounts(0, 0, 1) : analyseRGBA(img.data);
    const tex = this._dataTexture(img, o, a.hasAlpha);
    tex.name = key;
    const mipSource = tex.userData.mipSource;
    tex.userData = { key, format, width: img.width, height: img.height, compressed: false,
      mipLevels: tex.mipmaps.length || (tex.generateMipmaps ? 'generated' : 1), mipSource, ...a };
    this.stats.decoded++;
    return tex;
  }

  _fromDDS(dds, key, o, prepared = null) {
    if (dds.isCubemap && dds.faces) return this._cubeFromDDS(dds, key, o, prepared);
    const plan = webglCompressedPlan(dds);
    const useCompressed = plan.ok && this.s3tc && !dds.premultiplied && !o.decode && o.mipmaps !== 'generate' &&
      THREE[dds.threeFormat] !== undefined;
    let alpha = prepared ? prepared.alpha : analyseDDSAlpha(dds);
    let tex;
    if (useCompressed) {
      let levels = (o.mipmaps === 'none' ? dds.mipmaps.slice(0, 1) : dds.mipmaps)
        .map(m => ({ data: m.data, width: m.width, height: m.height }));
      let mipSource = levels.length > 1 ? 'file' : 'none';
      const fullCount = 1 + Math.floor(Math.log2(Math.max(dds.width, dds.height)));
      if (o.mipmaps === 'auto' && levels.length === 1 && fullCount > 1 && ENCODABLE.has(dds.format)) {
        try {
          if (prepared?.mipError) throw new Error(prepared.mipError);
          const extra = prepared?.encodedMips || encodeDXTMips(dds.format, decodeToRGBA(dds, 0), { punch: dds.format === 'DXT1' && !!dds.punchThrough });
          levels = levels.concat(extra);
          mipSource = 'encoded';
          this.stats.encodedMips++;
        } catch (err) {
          warnOnce(`mip:${key}`, `mip generation failed for ${key}: ${err && err.message || err}`);
        }
      }
      tex = new THREE.CompressedTexture(levels, dds.width, dds.height, THREE[dds.threeFormat]);
      tex.minFilter = levels.length > 1 ? THREE.LinearMipmapLinearFilter : THREE.LinearFilter;
      tex.generateMipmaps = false;
      this._common(tex, key, o);
      this.stats.compressed++;
      tex.userData = { key, format: dds.format, width: dds.width, height: dds.height, compressed: true,
        mipLevels: levels.length, mipSource, ...alpha };
    } else {
      const img = prepared?.img || decodeToRGBA(dds, 0);
      if (!alpha) alpha = analyseRGBA(img.data);
      tex = this._dataTexture(img, o.mipmaps === 'file' && dds.mipmaps.length > 1 ? { ...o, mipmaps: 'auto' } : o, alpha.hasAlpha, prepared?.rgbaMips);
      tex.name = key;
      const mipSource = tex.userData.mipSource;
      this.stats.decoded++;
      tex.userData = { key, format: dds.format, width: img.width, height: img.height, compressed: false,
        mipLevels: tex.mipmaps.length || (tex.generateMipmaps ? 'generated' : 1), mipSource, ...alpha };
    }
    tex.userData.punchThrough = !!dds.punchThrough;
    return tex;
  }

  _cubeFromDDS(dds, key, o, prepared = null) {
    const faces = dds.faces.map(f => f || dds.mipmaps);
    const plan = webglCompressedPlan(dds);
    let tex;
    if (plan.ok && this.s3tc && !dds.premultiplied && !o.decode) {
      const fmt = THREE[dds.threeFormat];
      tex = new THREE.CompressedCubeTexture(faces.map(levels => ({
        width: levels[0].width, height: levels[0].height, format: fmt,
        mipmaps: levels.map(m => ({ data: m.data, width: m.width, height: m.height })),
      })), fmt);
      tex.minFilter = faces[0].length > 1 ? THREE.LinearMipmapLinearFilter : THREE.LinearFilter;
      this.stats.compressed++;
    } else {
      const imgs = prepared?.cubeImages || faces.map((_, f) => decodeToRGBA(dds, 0, f));
      tex = new THREE.CubeTexture(imgs.map(img => {
        const d = new THREE.DataTexture(img.data, img.width, img.height, THREE.RGBAFormat, THREE.UnsignedByteType);
        d.flipY = false;
        return d;
      }));
      tex.generateMipmaps = false;
      tex.minFilter = THREE.LinearFilter;
      this.stats.decoded++;
    }
    this._common(tex, key, { ...o, repeat: false });
    tex.userData = { key, format: dds.format, width: dds.width, height: dds.height, compressed: tex.isCompressedTexture === true,
      cube: true, hasAlpha: false, alphaKind: 'none', mipSource: faces[0].length > 1 ? 'file' : 'none' };
    return tex;
  }
}
