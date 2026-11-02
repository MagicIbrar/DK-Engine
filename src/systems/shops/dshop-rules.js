// D-Shop (Cash Shop) + VIP / Mileage Shop purchase helpers.
// Evidence: share/cashshop/cashshop.csv + script/mileageshop/mileageshop.csv -> gamedata/dshop.json;
// server/world/shops.mjs dshopbuy (currency dkc vs vipPoints); client dshop.js makeCashShop.
// Mock currency only: profile.dkc / profile.vipPoints. No real payment, billing, or external refill.
// script/cashshop.csv may list legacy SKUs not in share/cashshop; prepared dshop.products follows share
// (report.legacyOnlyItems). Do not invent prices for missing SKUs.

export const DSHOP_CURRENCY = Object.freeze({ cash: 'dkc', vip: 'vipPoints' });
export const DSHOP_CASH_INVEN_MAX = 1000; // shops.mjs / dshop-gifts.mjs bound
export const DSHOP_CART_MAX = 28;

/** Profile field debited for a purchase. VIP shop uses VIP Points (mileage); D-Shop uses DKC. */
export function dshopCurrencyKey(vip) {
  return vip ? DSHOP_CURRENCY.vip : DSHOP_CURRENCY.cash;
}

/**
 * Catalog unit price for one product variant.
 * VIP: items[i].vipCost || items[i].cash; D-Shop: items[i].cash (native wings use nativeWingPurchasePrice).
 */
export function dshopVariantPrice(record, { vip = false, nativeWingPrice = null } = {}) {
  if (nativeWingPrice != null && Number.isFinite(Number(nativeWingPrice))) return Number(nativeWingPrice);
  if (vip) return Number(record?.vipCost ?? record?.cash ?? 0) || 0;
  return Number(record?.cash ?? 0) || 0;
}

/** Units granted per purchase of this item index (catalog stack, min 1). */
export function dshopPurchaseUnits(catalogItem) {
  const n = Number(catalogItem?.stack ?? 1);
  return Number.isFinite(n) && n >= 1 ? Math.floor(n) : 1;
}

/** Period seconds for timed cash items (0 = permanent). */
export function dshopPurchasePeriod(record) {
  const n = Number(record?.period) || 0;
  return n > 0 ? n : 0;
}

/**
 * Quote a cart against a dshop.json catalog.
 * cart: [{ product, itemIndex }], products list is catalog.products or catalog.vipShop.products.
 */
export function quoteDshopCart(catalog, cart, { vip = false, nativeWingPriceOf = null } = {}) {
  if (!catalog) throw Object.assign(new Error('D-Shop catalog is unavailable.'), { status: 503 });
  if (!Array.isArray(cart) || cart.length < 1 || cart.length > DSHOP_CART_MAX) {
    throw Object.assign(new Error('Choose between one and 28 catalog products.'), { status: 400 });
  }
  const products = vip ? catalog.vipShop?.products : catalog.products;
  let total = 0;
  const buys = cart.map((row) => {
    if (!row || Object.keys(row).some((k) => !['product', 'itemIndex'].includes(k))) {
      throw Object.assign(new Error('Send catalog product identifiers only.'), { status: 400 });
    }
    const product = products?.find((p) => p.id === row.product && p.items.includes(row.itemIndex));
    const record = { ...(catalog.items?.[row.itemIndex] || {}) };
    if (!product) throw Object.assign(new Error('This product is not in the selected shop.'), { status: 400 });
    const native = product.nativeWing && typeof nativeWingPriceOf === 'function'
      ? nativeWingPriceOf(catalog.items?.[row.itemIndex])
      : null;
    const price = dshopVariantPrice(record, { vip, nativeWingPrice: native });
    const units = dshopPurchaseUnits(catalog.items?.[row.itemIndex]);
    const period = dshopPurchasePeriod(record);
    total += price;
    return { itemIndex: row.itemIndex, price, units, period, product: row.product };
  });
  return { currency: dshopCurrencyKey(vip), total, buys, shop: vip ? 'vip' : 'dshop' };
}

/** Debit mock currency on a profile clone. Throws if balance is too low (same messages as shops.mjs cost). */
export function debitDshopCurrency(profile, currencyKey, amount) {
  if (!Number.isSafeInteger(amount) || amount < 0) throw Object.assign(new Error('Invalid catalog price.'), { status: 400 });
  const have = Number(profile[currencyKey]) || 0;
  if (have < amount) {
    const label = currencyKey === 'dil' ? 'DIL' : currencyKey === 'dkc' ? 'DKC' : 'points';
    throw Object.assign(new Error(`Not enough ${label}.`), { status: 400 });
  }
  profile[currencyKey] = have - amount;
  return profile[currencyKey];
}

/** Whether cash inventory can accept `count` more staged rows. */
export function cashInventoryCanAccept(cashInv, count) {
  const n = Array.isArray(cashInv) ? cashInv.length : 0;
  return n + count <= DSHOP_CASH_INVEN_MAX;
}
