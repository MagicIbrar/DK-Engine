// Dekaron .mel — map effect list: placed effect-scene instances (ambient sounds, particle/mesh effects,
// local light/fog zones, weather...). map/<name>.mel, 268 files (+ "###ardeca_global.mel").
//
// Layout (little-endian, fixed 60-byte records, no header/version):
//   u32 count
//   count x {                         // 60 bytes
//     f32 x, z                        // +0  world X / Z (file frame), terrain-cell units (same as .mol)
//     f32 qx, qy, qz, qw              // +8  rotation quaternion (D3DX x,y,z,w), file (left-handed) frame
//     f32 y                           // +24 height OFFSET above terrain at (x,z)  (same as .mol)
//     f32 scale                       // +28 uniform scale (almost always 1)
//     u16 effectId                    // +32 effect-scene id ("id" inside <effect> of property/effect/effectscene.*.txt)
//     u16 category                    // +34 effect-scene category ("<cate> N" block): 3 sound, 5 game, 9 light, ...
//     u32 unk0                        // +36 1 in 99.9% (0/2/3 only on a few 'game'/'game_sound' entries) — play mode/count?
//     u32 period                      // +40 ms. Re-trigger period / instance lifetime. 1000000 or 10000000 = "forever".
//     u32 periodRandom                // +44 ms. 0 or 1000 (random extra delay added to period).
//     u32 unk3, unk4, unk5            // +48 zero, except uninitialised editor memory in 1144 records (entry.dirty)
//   }
// File size is always exactly 4 + count*60 (validated by tools/test-mol.mjs over all files).
//
// Placement uses exactly the same conventions as .mol (see mol.js / docs/formats/mol.md):
//   three.js position = (x, terrainHeight(x,z) + y, -z), quaternion = (-qx, -qy, qz, qw).
// Effect lookup key = (category, effectId) in the effect-scene tables listed in script/effect/list_scene.txt.
// Map effects are defined in property/effect/effectscene.map.txt (cate 5 'game', 9 'light', 10 'weather') and
// ambient sounds in property/effect/effectscene.snd.txt (cate 3 'sound', 4 'game_sound'). See docs/formats/mel.md.

import { BinReader, toArrayBuffer, decodeText } from './binreader.js';

export const MEL_RECORD_BYTES = 60;

/** Effect-scene category numbers ("<cate> N name" in effectscene.*.txt). */
export const EFFECT_CATEGORY = {
  0: 'none', 1: 'monster', 3: 'sound', 4: 'game_sound', 5: 'game', 6: 'hit', 7: 'item', 8: 'ui',
  9: 'light', 10: 'weather', 11: 'condition', 12: 'event', 100: 'skill',
};

/** Which effectscene file (property/effect/effectscene.<suffix>.txt) to search first for a category (map context). */
export const MEL_CATEGORY_PRIMARY_FILE = {
  3: 'snd', 4: 'snd', 5: 'map', 8: 'map', 9: 'map', 10: 'map', 100: 'map',
  1: 'snd', 6: 'com', 7: 'com', 11: 'snd', 12: 'snd',
};

/** Search order when the primary file does not define (category,id) (mirrors list_scene.txt + map/snd first). */
export const EFFECTSCENE_FILES = ['map', 'snd', 'com', '01', '02', '03'];

/**
 * @param {ArrayBuffer|Uint8Array} buf
 * @returns {{count:number, entries:Array<object>, positions:Float32Array, quaternions:Float32Array, scales:Float32Array,
 *            effectIds:Uint16Array, categories:Uint16Array, bytesConsumed:number, trailingBytes:number}}
 */
export function parseMel(buf) {
  const ab = toArrayBuffer(buf);
  const r = new BinReader(ab);
  if (r.length < 4) throw new Error('mel: file too small');
  const count = r.u32();
  if (4 + count * MEL_RECORD_BYTES > r.length) throw new Error(`mel: count ${count} needs ${4 + count * 60} bytes, file has ${r.length}`);
  const entries = new Array(count);
  const positions = new Float32Array(count * 3);
  const quaternions = new Float32Array(count * 4);
  const scales = new Float32Array(count);
  const effectIds = new Uint16Array(count);
  const categories = new Uint16Array(count);
  for (let i = 0; i < count; i++) {
    const x = r.f32(), z = r.f32();
    const qx = r.f32(), qy = r.f32(), qz = r.f32(), qw = r.f32();
    const y = r.f32(), scale = r.f32();
    const effectId = r.u16(), category = r.u16();
    const unk0 = r.u32(), period = r.u32(), periodRandom = r.u32();
    const unk3 = r.u32(), unk4 = r.u32(), unk5 = r.u32();
    // 'dirty': the editor left uninitialised memory in bytes +44..+59 (norak, parca, ares_n, cs_ar02, elmar_dungeon);
    // periodRandom is then garbage too -> treat as 0.
    const dirty = (unk3 | unk4 | unk5) !== 0;
    entries[i] = {
      x, z, y, qx, qy, qz, qw, scale,
      effectId, category, categoryName: EFFECT_CATEGORY[category] || `cate${category}`,
      unk0, period, periodRandom, unk3, unk4, unk5, dirty,
    };
    positions[i * 3] = x; positions[i * 3 + 1] = y; positions[i * 3 + 2] = z;
    quaternions[i * 4] = qx; quaternions[i * 4 + 1] = qy; quaternions[i * 4 + 2] = qz; quaternions[i * 4 + 3] = qw;
    scales[i] = scale; effectIds[i] = effectId; categories[i] = category;
  }
  return { count, entries, positions, quaternions, scales, effectIds, categories, bytesConsumed: r.pos, trailingBytes: r.length - r.pos };
}

/** Same three.js conversion as .mol. */
export function melToThree(e, terrainHeight = 0) {
  return {
    position: [e.x, terrainHeight + e.y, -e.z],
    quaternion: [-e.qx, -e.qy, e.qz, e.qw],
    scale: [e.scale, e.scale, e.scale],
  };
}

/** True if the period means "never expires" (the scene is started once and kept alive / looped). */
export function melIsPersistent(e) { return e.period >= 1000000; }

/**
 * Light-weight index of an effectscene.*.txt file: only <cate>, <effect> id and name (plus the <list> res names).
 * Enough to resolve .mel references; full effect-scene parsing belongs to the effects module.
 * @param {string|ArrayBuffer|Uint8Array} src
 * @returns {Map<string, {category:number, id:number, name:string, res:string[]}>}  key = `${category}:${id}` (first definition wins)
 */
export function indexEffectScenes(src) {
  const text = typeof src === 'string' ? src : decodeText(src instanceof ArrayBuffer ? new Uint8Array(src) : src);
  const out = new Map();
  let cate = -1, cur = null, inList = false;
  for (const raw of text.split(/\r?\n/)) {
    const line = raw.trim();
    if (!line || line[0] === '#') continue;
    const low = line.toLowerCase();
    if (low.startsWith('<cate>')) { cate = parseInt(line.slice(6), 10); continue; }
    if (low.startsWith('</cate>')) { continue; }
    if (low.startsWith('<effect>')) { cur = { category: cate, id: -1, name: '', res: [] }; inList = false; continue; }
    if (low.startsWith('</effect>')) {
      if (cur && cur.id >= 0) { const k = `${cur.category}:${cur.id}`; if (!out.has(k)) out.set(k, cur); }
      cur = null; continue;
    }
    if (!cur) continue;
    if (low.startsWith('<list>')) { inList = true; continue; }
    if (low.startsWith('</list>')) { inList = false; continue; }
    if (low.startsWith('<scene>')) { inList = false; if (cur.id >= 0 && cur.name) cur.done = true; continue; }
    if (cur.done) continue;
    const t = line.split(/\s+/);
    if (t[0] === 'id' && cur.id < 0) cur.id = parseInt(t[1], 10);
    else if (t[0] === 'name' && !cur.name) cur.name = t.slice(1).join(' ');
    else if (inList && t[0] === 'res') cur.res.push(t.slice(2).join(' '));
  }
  for (const v of out.values()) delete v.done;
  return out;
}

/**
 * Resolve a .mel entry against indexes built with indexEffectScenes().
 * @param {{effectId:number, category:number}} e
 * @param {Record<string, Map>} indexes  e.g. { map: indexEffectScenes(mapTxt), snd: indexEffectScenes(sndTxt), ... }
 * @returns {{file:string, def:object}|null}
 */
export function resolveMelEffect(e, indexes) {
  const key = `${e.category}:${e.effectId}`;
  const primary = MEL_CATEGORY_PRIMARY_FILE[e.category];
  const order = primary ? [primary, ...EFFECTSCENE_FILES.filter(f => f !== primary)] : EFFECTSCENE_FILES;
  for (const f of order) {
    const idx = indexes[f];
    const def = idx && idx.get(key);
    if (def) return { file: f, def };
  }
  return null;
}
