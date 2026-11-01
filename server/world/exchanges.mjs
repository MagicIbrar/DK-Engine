import {AuthoritativeInventory} from './inventory.mjs';
import {nearbyNpc,offersOriginalJob} from './npc-services.mjs';
import {serializeLife,commitLife,validateLife} from './life-transactions.mjs';
import {assertNieteService} from './niete-services.mjs';

// Row ordinals disambiguate repeated item offers. All quantities, currencies,
// additional items and limits come from the host's native prepared catalogue.
export const EXCHANGE_ACTION_SCHEMAS={exchangebuy:['token','type','npcIndex','kind','catalog','row','count']};
const KINDS={exchange:{table:'exchanges',job:35},store:{table:'exchangeStores',job:166},material:{table:'materialExchanges',job:168}};
const fail=(text,status=400)=>{throw Object.assign(new Error(text),{status});};
const integer=(v,min=0,max=Number.MAX_SAFE_INTEGER)=>{if(!Number.isSafeInteger(v)||v<min||v>max)fail('Invalid exchange selection or quantity.');return v;};
const scaled=(v,count,min=1,max=100000)=>integer(integer(v,min,max)*count,min,max);
function pay(inv,items,count){
 const ids=[...new Set(items.filter(Boolean).map(i=>integer(i,1)))];integer(count,1,10000000000);
 if(!ids.length||ids.reduce((n,id)=>n+inv.count(id),0)<count)fail('You do not have the required exchange materials.');
 let left=count;
 for(const id of ids){const n=Math.min(inv.count(id),left);if(n&&!inv.remove(id,n))fail('Your exchange materials changed.');left-=n;if(!left)return;}
 fail('Your exchange materials changed.');
}
export function exchangeAction(world,p,input){
 validateLife(input,EXCHANGE_ACTION_SCHEMAS);
 const kind=typeof input.kind==='string'&&Object.hasOwn(KINDS,input.kind)?KINDS[input.kind]:null;if(!kind)fail('Invalid exchange type.');
 integer(input.npcIndex,1);integer(input.catalog,1);integer(input.row,0,100000);integer(input.count,1,9999);
 return serializeLife(p,async()=>{
  assertNieteService(world,p);if(p.dead)fail('You cannot trade while dead.');
  const db=world.data.itemDB;if(!db)fail('Item catalog is unavailable.',503);
  const catalog=(world.data.shopData?.shops||world.data.shops)?.[kind.table]?.[input.catalog],row=catalog?.entries?.[input.row];
  if(!row)fail('That exchange offer is unavailable.');
  const placed=nearbyNpc(world,p,{npcIndex:input.npcIndex,jobType:kind.job,jobIndex:input.catalog,radius:6.2});
  if(!placed||!offersOriginalJob(world,placed,kind.job,input.catalog))fail('Walk near the NPC offering this exchange.',403);
  const profile=structuredClone(p.profile),inv=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random}),n=input.count;
  const item=integer(row[0],1);if(!db.def(item))fail('The exchanged item is unavailable.');
  let count;
  if(input.kind==='exchange'){
   if(n!==1)fail('Choose one exchange at a time.');count=scaled(row[1],n);
   if(row[3]&&!inv.remove(integer(row[3],1),1))fail('You do not have the additional exchange item.');
   pay(inv,[catalog.priceItem,...(catalog.priceItemAlt||[])],scaled(row[2],n,1,10000000000));
  }else if(input.kind==='store'){
   // Season reset semantics are not recovered. Do not grant seasonal offers by
   // silently ignoring the native Season column (all More offers are Season 0).
   if(integer(row[5]??0)!==0)fail('This seasonal exchange is not available.');
   count=scaled(row[3],n);const limit=integer(row[4]??0),key=`${input.catalog}:${item}`;
   const used=integer(profile.shopLimits?.[key]??0);if(limit>0&&used+n>limit)fail('The exchange purchase limit has been reached.');
   pay(inv,[row[1],...(row[6]||[])],scaled(row[2],n,1,10000000000));
   if(limit>0)(profile.shopLimits||={})[key]=used+n;
  }else{
   count=scaled(row[1],n);
   for(const [a,b,c]of[[row[2],row[3],row[4]],[row[5],row[6],row[7]]])if(integer(c??0)>0)pay(inv,[a,b],scaled(c,n,1,10000000000));
   const dil=integer(integer(row[8]??0,0,10000000000)*n,0,10000000000);
   if(inv.dil<dil)fail('You do not have enough DIL.');profile.dil=inv.dil-dil;
  }
  if(!inv.add(item,count))fail('Your inventory cannot fit the exchanged items.');
  await commitLife(world,p,profile);
  world.emit(p.map,{type:'inventory',actorId:p.id,reason:'exchangebuy'});
  return true;
 });
}
