import {pickFromSet} from '../../src/game/loot.js';

// Additional native share/item/monsterdropitem_map.csv rows. Rates are explicit
// per100000. Slot cap/order inherit the existing monster roller contract;
// the unavailable executable's RNG sequence is not claimed. Zero rates fail
// closed. Current prepared rows have no positive map-money entries.
export function rollMapDrops({map,monsterIndex,lootData,itemNames={}},{rng=Math.random,itemRate=1}={}){
 const row=lootData?.mapDrops?.[map];
 if(!row||row.exclude?.includes(Number(monsterIndex)))return [];
 const out=[],ratio=rate=>Number(rate)>0&&rng()*100000<Number(rate)*Math.max(0,Number(itemRate)||0);
 const count=(a,b)=>{a=Math.max(1,Math.round(Number(a)||1));b=Math.max(a,Math.round(Number(b)||a));return a+Math.floor(rng()*(b-a+1));};
 const pick=id=>pickFromSet(lootData.itemSets?.[id],itemNames,rng);
 const cap=row.maxSets>0?row.maxSets:1;let accepted=0;
 for(const [id,rate]of row.sets||[]){if(accepted>=cap)break;if(!ratio(rate))continue;const item=pick(id);if(item){out.push(item);accepted++;}}
 for(const [id,stack,min,max,rate]of row.fixed||[]){if(!ratio(rate))continue;const n=count(min,max);out.push({kind:'item',itemIndex:id,name:itemNames[id]||`Item #${id}`,count:n,stack:!!stack||n>1,grade:'normal'});}
 for(const [id,min,max,rate]of row.fixedSets||[]){if(!ratio(rate))continue;const n=count(min,max);for(let i=0;i<n;i++){const item=pick(id);if(item)out.push(item);}}
 return out;
}
