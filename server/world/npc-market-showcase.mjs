import {AuthoritativeInventory} from './inventory.mjs';

// One-time private-bot market stock from verified native, tradeable items.
// Sold items are never silently replenished.
const MARKET_ITEMS=[64652,64653,64654];
const SHOWCASE_COUNT=3;
const SHOWCASE_DIL=1000000000;

export async function prepareNpcMarketShowcase({world,profiles}={}){
 if(!world?.data?.itemDB||!(profiles?.profiles instanceof Map)||typeof profiles.saveMany!=='function')throw Error('NPC market preparation requires the private saved roster.');
 const db=world.data.itemDB;
 for(const index of MARKET_ITEMS){const d=db.def(index);if(!d||d.slot!=='accessory'||Number(d.reqLv)<150||Number(d.price)<10000000||Number(d.trade)===0||d.period||d.eventType)throw Error('Native premium market catalog changed.');}
 const marked=[...profiles.profiles].filter(([,p])=>p.npcMarketShowcase?.version===1);
 if(marked.length>=SHOWCASE_COUNT)return {prepared:0,total:marked.length};
 const selected=new Set(marked.map(([id])=>id)),available=[...profiles.profiles]
  .filter(([id,p])=>!selected.has(id)&&Number(p.map)===150&&Number(p.level)>=200&&p.npcSeed?.stock&&p.authority==='server'&&p.npcPlayer===true&&!world.players.has(id))
  .sort((a,b)=>Number(b[1].level)-Number(a[1].level)||Number(b[1].npcTraits?.gear==='strong')-Number(a[1].npcTraits?.gear==='strong')||a[0].localeCompare(b[0]));
 const updates=[];
 for(const [account,p] of available.slice(0,SHOWCASE_COUNT-marked.length)){
  const profile=structuredClone(p),inventory=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random}),uids=[];
  for(const index of MARKET_ITEMS){const before=new Set(profile.inventory.map(item=>item.uid));
   if(!inventory.add(index,1,{grade:'divine',bound:false,roll:true}))throw Error('Native premium market item does not fit the private bot inventory.');
   const item=profile.inventory.find(row=>!before.has(row.uid)&&row.itemIndex===index);if(!item||item.bound)throw Error('Native premium market item could not be staged.');uids.push(item.uid);
  }
  profile.dil=Math.max(Number(profile.dil)||0,SHOWCASE_DIL);
  profile.npcMarketShowcase={version:1,policy:'ENGINE-CHOSEN one-time private bot market stock',uids,createdAt:world.now()};
  updates.push({accountId:account,characterId:profile.id,profile});
 }
 if(updates.length&&await profiles.saveMany(updates)!==true)throw Error('Private bot market stock could not be saved.');
 return {prepared:updates.length,total:marked.length+updates.length};
}
