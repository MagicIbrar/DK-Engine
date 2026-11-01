// Source-native Wings catalog. Native definitions remain unchanged.
import { registerWingShopExtension, WING_PRICE } from './wing-items.js';
export const NATIVE_WING_MAIN = 4;
// Explicit ENGINE listing policy, not recovered official pricing.
export const NATIVE_WING_PRICE = WING_PRICE;
export const NATIVE_WING_PRICE_POLICY = 'engine-native-wing-500-v1';
export function nativeWingPurchasePrice(record) {
  if(record?.nativeWing!==true || record.shopPrice!==NATIVE_WING_PRICE || record.pricePolicy!==NATIVE_WING_PRICE_POLICY)
    throw new Error('The native wing engine price policy is invalid.');
  return record.shopPrice;
}
// These original source meshes contain only picking helpers, with no drawable
// geometry or lines. Exclude their class/version records rather than grant an
// invisible equipped wing. Source hashes and all60 IDs are in the C36 asset audit.
const emptyEquippedMeshes = new Set([
  "mesh/item/armor/wing/wing_doughnut_big.mesh",
  "mesh/item/armor/wing/wing_doughnut_mid.mesh",
  "mesh/item/armor/wing/wing_doughnut_sma.mesh"
]);
const cache = new WeakMap();
export function nativeWingRows({core,looks,visual,mounts}={}) {
  const included=[],excluded=[],defaults=core?.itemDefaults||{};
  // Test the four selecting fields before merging: the merge copied all 95,000 item rows (10,053 are wings; 0.34 s of
  // the 2.2.0 loading screen, measured). Own row fields win over itemDefaults exactly as in the spread below.
  const field=(row,k)=>Object.hasOwn(row,k)?row[k]:defaults[k];
  for(const [key,row] of Object.entries(core?.items||{})) {
    if(field(row,'type')!==6||field(row,'code')!==1||field(row,'slot')!=='wing'||field(row,'src')==='engine-wings')continue;
    const d={index:Number(key),...core.itemDefaults,...row};
    const reasons=[],look=looks?.looks?.[key],shape=visual?.shapes?.[d.shape],mount=mounts?.wings?.[key];
    const asset=look&&looks.assets?.[look.all],mountAsset=mount&&mounts.assets?.[mount[0]];
    if(!Number.isSafeInteger(d.index)||d.index<=0)reasons.push('invalid original index');
    if(!Number.isInteger(d.classMask)||d.classMask<=0||d.classMask>32767)reasons.push('no supported class eligibility');
    if(!asset?.mesh||!mountAsset?.mesh||asset.mesh!==mountAsset.mesh||look?.slot!=='wing')reasons.push('missing or inconsistent equipped wing');
    if(emptyEquippedMeshes.has(asset?.mesh))reasons.push('original equipped mesh has no drawable geometry');
    if(!shape?.inv?.mesh)reasons.push('missing inventory wing model');
    if(!Number.isInteger(d.w)||!Number.isInteger(d.h)||d.w<1||d.h<1||d.w>10||d.h>5)reasons.push('unsupported inventory footprint');
    // An original nonzero action requires the existing native animation mapping;
    // do not silently convert an unresolved animated wing to a rigid cosmetic.
    if(d.action&&(!mount||mount[1]!==d.action||!mounts.wingActions?.[d.action]?.skel||!mounts.wingActions[d.action].rows?.length))reasons.push('missing native action table');
    if(!Number.isSafeInteger(d.cash)||d.cash<0||d.cash>1_000_000_000||!Number.isSafeInteger(d.period)||d.period<0)reasons.push('invalid original price or period');
    if(reasons.length){excluded.push({index:d.index,name:d.name,reasons});continue;}
    included.push({index:d.index,def:d,look,shape,asset,mountAsset,action:mount?.[1]??null,purchasable:true});
  }
  included.sort((a,b)=>a.index-b.index);excluded.sort((a,b)=>a.index-b.index);
  return {included,excluded};
}
export function withNativeWingShop(catalog,parts) {
  if(!catalog||typeof catalog!=='object')return catalog;
  if(cache.has(catalog))return cache.get(catalog);
  const tab=catalog.tabs?.find(tab=>tab.main===NATIVE_WING_MAIN);
  if(!tab)throw Error('Install the authored Wings tab before native wing entries.');
  const products=[...(catalog.products||[])],items={...(catalog.items||{})},reserved=new Set(products.map(p=>p.id));
  const {included}=nativeWingRows(parts);
  for(const {index,def:d,shape,purchasable}of included){
    if(reserved.has(index))throw Error('Native wing product identifier conflicts with an existing product.');
    // Item IDs are original IDs; product IDs reuse that exact ID, never a guessed range.
    products.push({id:index,main:NATIVE_WING_MAIN,sub:0,items:[index],nativeWing:true});
    reserved.add(index);
    items[index]={...items[index],name:d.name,cash:d.cash,stack:1,period:d.period,classMask:d.classMask,
      purchaseLimit:d.purchaseLimit,purchaseLimitLv:d.purchaseLimitLv,purchaseType:d.purchaseType,
      nativeWing:true,purchasable,shopPrice:NATIVE_WING_PRICE,pricePolicy:NATIVE_WING_PRICE_POLICY,
      icon:[shape.inv.mesh,shape.inv.tpack||null,shape.invScale||1]};
  }
  const count=products.filter(p=>p.main===NATIVE_WING_MAIN).length;
  const result={...catalog,products,items,tabs:catalog.tabs.map(t=>t===tab?{...t,subs:t.subs.map(s=>s.sub===0?{...s,products:count}:s)}:t)};
  registerWingShopExtension(catalog,result);
  cache.set(catalog,result);cache.set(result,result);return result;
}
