// Texture helpers for the world module.
// Prefers the engine TextureCache (game.textures, src/engine/textures.js); falls back to a local DDS/TGA/BMP decoder
// so the world still renders (e.g. in tools/world.html) when the render module is not available.
// Colour rule (docs/ARCHITECTURE.md): colorSpace = NoColorSpace, flipY = false on every texture.
import * as THREE from 'three';
import { tryFetchBuffer, listDir, normPath } from '../engine/assets.js';
import { parseDDS, decodeToRGBA, sniffImageType } from '../formats/dds.js';
import { decodeImage } from '../formats/image.js';

/** Decode any client image buffer to {width,height,data RGBA8 top-down} (null on failure). */
export function decodeRGBA(buf) {
  if (!buf) return null;
  try {
    const kind = sniffImageType(buf);
    if (kind === 'dds') return decodeToRGBA(parseDDS(buf));
    const img = decodeImage(buf);
    if (img && img.data) return { width: img.width, height: img.height, data: img.data };
    if (img && img.kind === 'dds') return decodeToRGBA(img.dds);
  } catch { /* fall through */ }
  return null;
}

/** Fetch + decode the first existing key. */
export async function loadRGBA(keys) {
  for (const k of keys) {
    if (!k) continue;
    // tryFetchBuffer already maps missing -> null and rethrows transient transport errors.
    const buf = await tryFetchBuffer(k);
    if (!buf) continue;
    const img = decodeRGBA(new Uint8Array(buf));
    if (img) return img;
  }
  return null;
}

/** RGBA image -> DataTexture (mipmapped, repeat, NoColorSpace, flipY=false). */
export function rgbaTexture(img, { repeat = true, mipmaps = true } = {}) {
  const tex = new THREE.DataTexture(img.data, img.width, img.height, THREE.RGBAFormat, THREE.UnsignedByteType);
  tex.flipY = false;
  tex.colorSpace = THREE.NoColorSpace;
  tex.wrapS = tex.wrapT = repeat ? THREE.RepeatWrapping : THREE.ClampToEdgeWrapping;
  tex.magFilter = THREE.LinearFilter;
  tex.minFilter = mipmaps ? THREE.LinearMipmapLinearFilter : THREE.LinearFilter;
  tex.generateMipmaps = mipmaps;
  tex.anisotropy = 4;
  tex.needsUpdate = true;
  return tex;
}

const localCache = new Map();

/**
 * Load a texture by candidate keys. Uses game.textures (TextureCache) when present, else the local decoder.
 * Resolves null (never throws) when nothing decodes.
 * @param {{textures?:object}|null} game
 * @param {string[]} keys
 */
export async function loadTexture(game, keys, { repeat = true } = {}) {
  keys = [...new Set(keys.filter(Boolean).map(normPath))];
  const tc = game && game.textures;
  if (tc && typeof tc.load === 'function') {
    // probe the candidates quietly (TextureCache logs nothing for _quiet loads); callers report what stays missing
    for (const k of keys) {
      try {
        const t = await tc.load(k, { repeat, _quiet: true });
        if (t && t !== tc.placeholder) return fixTexture(t);
      } catch (err) {
        if (err?.transient) throw err;
        /* next candidate */
      }
    }
    return null;
  }
  const id = keys.join('|') + (repeat ? '' : '#clamp');
  let p = localCache.get(id);
  if (!p) {
    p = loadRGBA(keys).then(img => (img ? rgbaTexture(img, { repeat }) : null)).catch(err => {
      if (err?.transient) {
        if (localCache.get(id) === p) localCache.delete(id);
        throw err;
      }
      return null;
    });
    localCache.set(id, p);
  }
  return p;
}

function fixTexture(t) {
  // Colour rule: textures are raw gamma-space values (NoColorSpace), flipY = false.
  if (t.colorSpace !== THREE.NoColorSpace || t.flipY) {
    t.colorSpace = THREE.NoColorSpace;
    t.flipY = false;
    t.needsUpdate = true;
  }
  return t;
}

// ------------------------------------------------------------------ basename index (texture/maptile/**)
let maptileIndex = null;
/**
 * Map of lower-case basename -> [data keys] over texture/maptile/<folder>/ (one directory level), built once per
 * session. Decal records that name a texture of another map folder need this fallback (dds.md: 710 records).
 */
export function maptileBasenameIndex() {
  if (!maptileIndex) {
    maptileIndex = (async () => {
      const idx = new Map();
      const add = (key) => { const b = key.slice(key.lastIndexOf('/') + 1); if (!idx.has(b)) idx.set(b, []); idx.get(b).push(key); };
      try {
        const top = await listDir('texture/maptile');
        const dirs = top.filter(e => e.dir).map(e => e.name.toLowerCase());
        for (const e of top) if (!e.dir) add(`texture/maptile/${e.name.toLowerCase()}`);
        let i = 0;
        const worker = async () => {
          while (i < dirs.length) {
            const d = dirs[i++];
            try { for (const e of await listDir(`texture/maptile/${d}`)) if (!e.dir) add(`texture/maptile/${d}/${e.name.toLowerCase()}`); }
            catch { /* ignore */ }
          }
        };
        await Promise.all(Array.from({ length: 8 }, worker));
      } catch { /* no listing available */ }
      return idx;
    })();
  }
  return maptileIndex;
}

/** Candidate keys for a decal/maptile texture: as named, .dds twin, then same basename in any maptile folder. */
export async function maptileCandidates(path, pathAlt) {
  const out = [path, pathAlt].filter(Boolean);
  const base = String(path || '').slice(String(path || '').lastIndexOf('/') + 1);
  const stem = base.replace(/\.[^.]+$/, '');
  const idx = await maptileBasenameIndex();
  for (const b of [base, `${stem}.dds`]) for (const k of idx.get(b) || []) if (!out.includes(k)) out.push(k);
  return out;
}
