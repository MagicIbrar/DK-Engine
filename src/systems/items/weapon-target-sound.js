// Event-weapon attack sound: item_shape.csv column 22 "Targeteffect" selects modeleffect.csv group 38 / code2 1 / code3.
// NATIVE DATA (Global): 38/1/1..5 are eff_cate 4 sound scenes ("Agama / Tuban / lollipop / electric flyswatter / squeaky hammer
// attack sound", code3 "1..65500"); 12 shapes carry a value: 124 Argama Pet = 1 -> 4:1170 item_agama_att.wav, the other 11
// (Tuban's Head 1160, flags, lollipops, hammer, flyswatter, Gramen's Club, Master Craftsman's Dagger) = 2 -> 4:1177
// item_thuban_att.wav. The literal value is kept: no Global shape names 38/1/3..5.
// Client behaviour: for each of the attacker's right- and left-hand weapon items with a nonzero Targeteffect, the client
// plays modeleffect (38, 1, value) on the struck actor when an attack result lands.
// ENGINE-CHOSEN (src/config/engine-chosen-weapon-target-sound.js): which engine hit events count as those results.
import { fetchText } from '../../engine/assets.js';
import { parseCSV } from '../../formats/binreader.js';
import { TARGET_SOUND } from '../../config/engine-chosen-weapon-target-sound.js';

/** modeleffect.csv rows (cell arrays; header tolerated) -> Map(code3 -> {cate, id, scene, timeMs}) of native group 38 / code2 1. */
export function targetSoundRows(rows) {
  const out = new Map();
  for (const r of rows || []) {
    if (Number(r?.[0]) !== TARGET_SOUND.code1 || Number(r[1]) !== TARGET_SOUND.code2 || !(Number(r[2]) > 0) || Number(r[3])) continue;
    if (Number(r[5]) > 0) out.set(Number(r[2]), { cate: Number(r[4]), id: Number(r[5]), scene: Number(r[6]) || 1, timeMs: Number(r[7]) || 0 });
  }
  return out;
}

/** The attacker's equipped weapon items (main hand, then a distinct left-hand item) whose shape names a target sound. */
export function weaponTargetCodes(db, view) {
  const w = view?.weapon, out = [];
  if (!db || !w?.itemIndex) return out;
  const add = index => { const def = db.def(index), code = Number(db.shape(def)?.targetEffect) || 0; if (code > 0) out.push({ itemIndex: Number(index), code }); };
  add(w.itemIndex);
  if (Number(w.leftItemIndex) > 0 && (!TARGET_SOUND.distinctLeftItem || Number(w.leftItemIndex) !== Number(w.itemIndex))) add(w.leftItemIndex);
  return out;
}

/** sound.json records for those codes: effectSound[cate][id].scenes[scene] (no record -> nothing, never a generic sound). */
export function targetSoundLists(sound, rows, codes) {
  const out = [];
  for (const { code } of codes || []) {
    const ref = rows?.get(Number(code));
    const list = ref ? sound?.effectSound?.[String(ref.cate)]?.[String(ref.id)]?.scenes?.[String(ref.scene)] : null;
    if (Array.isArray(list) && list.length) out.push({ code: Number(code), ref, list });
  }
  return out;
}

/** True for a hit event that plays the attacker's weapon target sound (TARGET_SOUND.landedHitsOnly / attackerKinds). */
export function targetSoundHit(e) {
  const { source, target, miss, dot, skill } = e || {};
  if (!source || !target || source === target || dot) return false;
  if (TARGET_SOUND.landedHitsOnly && miss) return false;
  if (!TARGET_SOUND.skillHits && skill) return false;
  return TARGET_SOUND.attackerKinds.includes(source.kind);
}

/** Wire the offline 'damage' and online cosmetic 'server:damage' events. Returns {ready, played, dispose}. */
export function installWeaponTargetSounds(game, db, { load = () => fetchText('script/effect/modeleffect.csv').then(parseCSV) } = {}) {
  let rows = null, pending = null, disposed = false;
  const played = [];
  const ensure = () => rows || pending || (pending = Promise.resolve().then(load).then(r => (rows = targetSoundRows(r)))
    .catch(error => { pending = null; console.warn('[items] weapon target sound table', error); return null; }));
  const onHit = e => {
    if (disposed || !targetSoundHit(e)) return;
    const codes = weaponTargetCodes(db, e.source.save?.equipment);
    if (!codes.length) return;
    const play = table => {
      if (disposed || !table) return;
      const S = game.audio?.S || game.data?.sound, t = e.target;
      for (const hit of targetSoundLists(S, table, codes)) {
        played.push({ code: hit.code, key: `${hit.ref.cate}:${hit.ref.id}`, path: hit.list[0]?.path || null }); if (played.length > 16) played.shift();
        try { game.audio?.playAll?.(hit.list, { at: t === game.player ? null : { x: Number(t.x) || 0, z: Number(t.z) || 0 } }); } catch (error) { console.warn('[items] weapon target sound', error); }
      }
    };
    if (rows) play(rows); else Promise.resolve(ensure()).then(play);
  };
  const off = ['damage', 'server:damage'].map(type => game.events?.on?.(type, onHit));
  return {
    get ready() { return Promise.resolve(ensure()); },
    played,
    dispose() { disposed = true; for (const f of off) if (typeof f === 'function') f(); },
  };
}
