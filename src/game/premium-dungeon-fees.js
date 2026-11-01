import {activePremiums,premiumFields,almightyOf} from '../systems/shops/premium-rules.js';
// Native item descriptions: 701 (Almighty), 358 (Hunting Master), 291 (Growth Blessing).
// Only a genuine service whose own current description specifies a fee discount can lower DIL admission.
export function premiumDungeonDiscount(world,profile){
 let percent=0;const db=world.data.itemDB,dshop=world.data.shopData?.dshop;
 for(const entry of activePremiums(profile.premium,world.now())){
  if(!premiumFields(dshop,entry.item))continue;
  const def=db?.def(entry.item);
  // 1171289 has a package tooltip (353); cashshop_almightypremium explicitly grants the default Almighty service.
  const text=almightyOf(dshop,entry.item)?db?.descriptions?.[701]||'':db?.description(def)||'';
  const match=/(?:^|\n)(\d+)% discount on instant dungeon/i.exec(text)||/InDun\s*(?:Fee\s*)?(\d+)%\s*discount/i.exec(text);
  if(match)percent+=Number(match[1]);
 }
 return Math.min(100,Math.max(0,percent));
}
export function premiumDungeonFee(world,profile,fee){
 // ENGINE-CHOSEN integer-DIL rounding: ceil prevents the reduction exceeding the authored percentage.
 return Math.ceil(Math.max(0,Number(fee)||0)*(100-premiumDungeonDiscount(world,profile))/100);
}
