// Retired engine-authored wings: saved-item compatibility shared by client/server.
// Original extracted tables stay unchanged. These IDs are separate from GM drafts.
import { WING_DESIGNS, WING_ITEM_BASE, wingAssetKey } from './wings-catalog.js';

export const WING_SHOP_MAIN = 4;
export const WING_PRICE = 500;
const SOURCE = 'engine-wings';
// Native Favnil's Wings share this baseline in every supported class. The
// collection's all-class, level-one, permanent policy and price stay authored.
export const WING_NATIVE_BASELINE = Object.freeze({
  family: "Favnil's Wings", quality: 24,
  classSources: Object.freeze([54406, 54407, 54408, 54409, 54410, 54411, 54412, 7439, 54432, 54424, 54413, 54414, 54425, 54442, 54437]),
  options: Object.freeze([Object.freeze([9, 8]), Object.freeze([17, 8]), Object.freeze([43, 8])]),
  // Native Favnil equipped shapes carry no particle effect/effectAdd reference.
  equippedEffects: Object.freeze([]),
});

export function installWingItems(db) {
  if (!db?.items) return;
  db.visual ||= {}; db.visual.shapes ||= {};
  db.looks ||= {}; db.looks.looks ||= {}; db.looks.assets ||= [];
  db.descriptions ||= {};
  for (const design of WING_DESIGNS) {
    const index = WING_ITEM_BASE + design.id;
    if (db.items[index] && db.items[index].src !== SOURCE) throw new Error('The installed item catalog conflicts with the engine wing collection.');
    const asset = { mesh: wingAssetKey(design.id) };
    let assetId = db.looks.assets.findIndex(row => row?.mesh === asset.mesh);
    if (assetId < 0) { assetId = db.looks.assets.length; db.looks.assets.push(asset); }
    db.items[index] = {
      name: design.name, src: SOURCE, type: 6, code: 1, slot: 'wing', rank: 0,
      classMask: 32767, reqLv: 1, maxLv: 0, reqStr: 0, reqDex: 0, reqSpr: 0, reqGrade: 0,
      w: 2, h: 1, stack: 0, maxStack: 1, autoStack: 0, quality: 24,
      cash: WING_PRICE, price: 0, sell: 0, npcSell: 0, period: 0, trade: 1,
      purchaseLimit: 0, purchaseLimitLv: 0, action: 0, prev: 0, next: 0,
      shape: index, desc: index, options: WING_NATIVE_BASELINE.options.map(option => [...option]), exOptions: [], optionPools: [],
      socketRates: [0, 0, 0, 0], melee: [0, 0], magic: [0, 0], ranged: [0, 0], def: [0, 0],
      pvpDmg: 0, pvpDef: 0, block: 0, range: 0, speed: 0, crit: 0,
    };
    db.descriptions[index] = `${design.description || design.name}\nAnimated wings for every class. Favnil's Wings baseline: Max HP +8%, Max MP +8%, Movement Speed +8%.`;
    db.visual.shapes[index] = { game: asset, inv: asset, field: asset, invTwoSide: true, invScale: 1 };
    db.looks.looks[index] = { slot: 'wing', all: assetId, bone: db.equipment?.wingBone || 'weaponW' };
    db._defs?.delete(index);
  }
}

const catalogs = new WeakMap();
// The Wings tab wrapper retains idempotence when native products are appended.
export function registerWingShopExtension(base,result) {
  if(catalogs.get(base)!==base)throw new Error('Native wings require an installed Wings tab.');
  catalogs.set(result,result);
}
export function withWingShop(catalog) {
  if (!catalog || typeof catalog !== 'object') return catalog;
  if (catalogs.has(catalog)) return catalogs.get(catalog);
  if ((catalog.tabs || []).some(tab => tab.main === WING_SHOP_MAIN)) throw new Error('The installed D-Shop catalog conflicts with the Wings tab.');
  // Retire offers only. Definitions/meshes remain installed for already-owned
  // bag, equipment and cash-inventory items; no profile or receipt migration.
  const retired = new Set(WING_DESIGNS.map(design => WING_ITEM_BASE + design.id));
  const retireOffers = rows => (rows || []).flatMap(product => {
    if (retired.has(Number(product.id))) return [];
    if (!product.items?.some(index => retired.has(Number(index)))) return [product];
    const variants = product.items.filter(index => !retired.has(Number(index)));
    return variants.length ? [{ ...product, items: variants }] : [];
  });
  const products = retireOffers(catalog.products), items = { ...(catalog.items || {}) };
  for (const index of retired) delete items[index];
  const vipShop = catalog.vipShop ? { ...catalog.vipShop, products: retireOffers(catalog.vipShop.products) } : catalog.vipShop;
  const result = { ...catalog, products, items, vipShop, tabs: [...(catalog.tabs || []), {
    main: WING_SHOP_MAIN, key: 'wings', name: 'Wings', button: 'btn_wings',
    subs: [{ sub: 0, name: 'All wings', button: 'btn_all_wings', products: 0 }],
  }] };
  catalogs.set(catalog, result); catalogs.set(result, result);
  return result;
}
