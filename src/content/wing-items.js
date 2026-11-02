// Retired engine-authored wings REMOVED from live catalog (2026-10-27 ANIM-FX-GLOBAL-REA).
// Procedural WING_DESIGNS / engine/wings/*.wing were fabricated — NOT Global data.
// Live wings = native Global mounts.json + mesh/item/armor/wing/* only (native-wing-shop.js).
// Saved engine-wings item IDs (88010001+) no longer resolve to fake geometry; shop offers stay retired.
import { WING_DESIGNS, WING_ITEM_BASE } from './wings-catalog.js';

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

/** No-op: fabricated engine wing definitions are not installed. Global native wings only. */
export function installWingItems(db) {
  if (!db?.items) return;
  // Strip any previously injected engine-wings rows if a hot reload left them.
  for (const design of WING_DESIGNS) {
    const index = WING_ITEM_BASE + design.id;
    if (db.items[index]?.src === SOURCE) {
      delete db.items[index];
      delete db.descriptions?.[index];
      delete db.visual?.shapes?.[index];
      delete db.looks?.looks?.[index];
      db._defs?.delete?.(index);
    }
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
