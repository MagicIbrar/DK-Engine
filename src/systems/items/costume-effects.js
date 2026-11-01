// Intrinsic worn effect of a costume (G6, 3.1.0). Pure; no browser or scene state.
//
// NATIVE BINDING: script/shape/cos_shape.csv authors every costume look per class as the triple `<class>/mesh, tpack, effect`
// (header: Index,swd/mesh,tpack,effect,arc/mesh,tpack,effect,...,tri/mesh,tpack,effect,lod). The effect column is a
// script/effect/modeleffect.csv 31/1 index, the same namespace as item_shape.csv's effect column, and the rows it names
// are the costume variants themselves (31/1/232 "화사한 교복 (드래곤 나이트)", 31/1/306 "청명한 교복 (여성 캐릭터)",
// 31/1/572 "데스나이트 코스튬", ...). tools/build-items.mjs copies a non-zero cos_shape effect into the per-class look asset
// (items-looks.json assets[].effect), and Equipment.view() spreads that asset into the worn costume parts.
//
// ENGINE RULE (follows the existing "intrinsic FX belong to the item supplying this mesh" rule for off-hands in
// authored-effects.js): the costume's effect is the one of the asset that supplies the drawn mesh.
//   * a cos_shape asset plays its own cos_shape effect (0 = none);
//   * only a costume drawn from its item_shape mesh (no cos_shape row/entry) plays item_shape effect/effectAdd.
// Why not item_shape for every costume: shared item_shape rows are placeholders for many costumes. Example: the
// Dragon Knight School/Gorgeous/Bright uniforms all reuse item_shape 5019 (effect 232) but author cos_shape effects
// 0/232/306 on the same mesh, and the D-Knight Yukata's item_shape 5100 is a dual-blade weapon whose effect 192 is
// "푸른용무기 10강 이펙트_오른쪽" (a +10 weapon effect); its cos_shape 37 entry authors no effect.

const meshKey = mesh => String(mesh || '').replace(/\\/g, '/').toLowerCase();
const ids = list => list.map(Number).filter(id => Number.isInteger(id) && id > 0);

/** Effect ids (modeleffect 31/1) of one worn costume part of an Equipment.view() entry ({...asset, itemIndex, costume:true}). */
export function costumeIntrinsicEffects(db, asset) {
  if (!asset?.itemIndex) return [];
  // The look asset carries a cos_shape effect only when it came from cos_shape (the appearance item's, when one is shown).
  if (Number(asset.effect) > 0) return ids([asset.effect]);
  const def = db?.def?.(asset.itemIndex) || null, shape = db?.shape?.(def) || null;
  const cos = def?.cosShape ? db?.visual?.cosShapes?.[def.cosShape] || null : null;
  if (!cos) return ids([shape?.effect, shape?.effectAdd]);                 // drawn from item_shape: its effect applies
  const mesh = meshKey(asset.mesh), entries = Object.values(cos.byClass || {});
  if (entries.some(entry => meshKey(entry?.mesh) === mesh)) return [];      // drawn from cos_shape, which authors no effect here
  // A class without a cos_shape entry is drawn from the item_shape mesh (tools/build-items.mjs `cos.byClass[c] ?? sh.game`).
  if (meshKey(shape?.game?.mesh) === mesh) return ids([shape?.effect, shape?.effectAdd]);
  return [];                                                                 // another costume's cos_shape look (appearance) without an effect
}
