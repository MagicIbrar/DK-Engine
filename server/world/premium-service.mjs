// Authoritative premium service state (Growth Blessing / Holy Water of the Almighty): the timed service is server-owned
// (profile.premium = {group: {item,start,until,fields}}). Rules shared with the client live in
// src/systems/shops/premium-rules.js; tables are share/item/premiereitem.csv + share/premiere/teleport.csv/respon.csv.
import {PREMIUM_TEXT,PREMIUM_PASS_NAME,almightyOf,activePremiums,premiumAny,premiumSum,premiumBlock,premiumActivation,premiumFields} from '../../src/systems/shops/premium-rules.js';

const fail=(message,status=400)=>{throw Object.assign(new Error(message),{status});};
export const dshopOf=world=>world.data.shopData?.dshop||null;

export const premiumActive=(world,profile)=>activePremiums(profile.premium,world.now());
export const premiumHas=(world,profile,key)=>premiumAny(profile.premium,world.now(),key);
/** Percent bonus (Rate column) added to hunting EXP while a service is active. */
export const premiumExpPercent=(world,profile)=>premiumSum(profile.premium,world.now(),'rate');
export const premiumPartyBonus=(world,profile)=>premiumSum(profile.premium,world.now(),'partyBonusRate');
export const premiumUpgradeBonus=(world,profile)=>premiumSum(profile.premium,world.now(),'itemUpgradeRate');
/** Remote storage: premiereitem.csv has no storage column. The Holy Water of Almighty item text (description 701 "Remote storage")
 *  and the client's Stash button (src/systems/shops/premium.js isAlmighty) tie it to the Almighty services: StoreIndex / Post / Brokerage. */
export const premiumRemoteStorage=(world,profile)=>['storeIndex','post','brokerage'].some(key=>premiumHas(world,profile,key));
/** Remote store: only the StoreIndex shop of a running service, decided from the server-owned premium state (never a client flag). */
export const premiumStoreShop=(world,profile,shop)=>Number.isInteger(shop)&&shop>0&&premiumActive(world,profile).some(entry=>Number(entry.fields?.storeIndex)===shop);
export const isPremiumItem=(world,idx)=>{const dshop=dshopOf(world);return Number(idx)>0&&!!dshop&&!!premiumFields(dshop,idx);};

/** Throws the original refusal for an item that cannot start now (before the item is consumed). */
export function checkPremiumItem(world,profile,itemIndex){
  const dshop=dshopOf(world);if(!dshop||!premiumFields(dshop,itemIndex))return;
  const block=premiumBlock(dshop,profile.premium,itemIndex,world.now());
  if(block==='together')fail(PREMIUM_TEXT.together);
  if(block==='renew'){const alm=almightyOf(dshop,itemIndex);fail(`${world.data.itemDB?.def(itemIndex)?.name||'This service'}: it can be renewed during its last ${alm.updatableDays} days.`);}
}

/** Keep the StatusIndex buffs (premium:<item>) in profile.buffs equal to the running services; real-time expiry. */
export function syncPremiumBuffs(world,profile){
  const now=world.now(),statuses=world.data.itemUseData?.statuses||{};
  if(profile.premium)for(const [group,entry] of Object.entries(profile.premium))if(!entry||entry.until<=now)delete profile.premium[group];
  // Premium/regular Holy Water share their status; keep one application, lasting until the later expiry.
  const statusesWanted=new Map();for(const p of activePremiums(profile.premium,now).filter(p=>p.fields?.statusIndex>0)){const old=statusesWanted.get(p.fields.statusIndex);if(!old||p.until>old.until)statusesWanted.set(p.fields.statusIndex,p);}
  const want=new Map([...statusesWanted.values()].map(p=>[`premium:${p.item}`,p]));
  const buffs=profile.buffs||=[];
  for(let i=buffs.length-1;i>=0;i--){
    const key=String(buffs[i].key||'');
    if(key.startsWith('premium:')&&!want.has(key))buffs.splice(i,1);
    // the generic item-use path's own copy of the same status: one buff per service instead
    else if(key.startsWith('premiere:')&&want.has(`premium:${key.slice(9)}`))buffs.splice(i,1);
  }
  for(const [key,p] of want){
    const def=statuses[p.fields.statusIndex];if(!def)continue;
    const entry={key,statusIndex:p.fields.statusIndex,premium:p.item,name:world.data.itemDB?.def(p.item)?.name||def.description||'Premium service',description:def.description||'',iconIndex:def.iconIndex??null,
      options:(def.options||[]).map(o=>({code:o.code,value:o.value})),duration:(p.until-p.start)/1000,remaining:(p.until-now)/1000,tick:0,item:true,group:def.group,expiresAt:p.until};
    const at=buffs.findIndex(b=>b.key===key);if(at>=0)buffs[at]=entry;else buffs.push(entry);
  }
}

/** Start/extend the service of a consumed premium item inside the (cloned) item-use profile. */
export function startPremium(world,profile,itemIndex){
  const dshop=dshopOf(world);if(!dshop||!premiumFields(dshop,itemIndex))return false;
  const {group,entry}=premiumActivation(dshop,profile.premium||{},itemIndex,world.now());
  if(PREMIUM_PASS_NAME.test(String(world.data.itemDB?.def(itemIndex)?.name||''))){
    entry.accountWide=true;profile.accountFeatures||={};
    profile.accountFeatures.premium={...(profile.accountFeatures.premium||{}),[group]:structuredClone(entry)};
  }
  profile.premium={...(profile.premium||{})};
  const previous=profile.premium[group];
  if(entry.accountWide&&previous&&!previous.accountWide&&previous.until>world.now())profile.premium[`regular:${group}`]=previous;
  profile.premium[group]=entry;
  delete profile.premiere;   // the single-slot record of the generic item path; the grouped state replaces it
  syncPremiumBuffs(world,profile);
  return true;
}
