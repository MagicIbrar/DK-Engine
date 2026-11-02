import {AuthoritativeInventory,inventoryDestination,receiveAt} from './inventory.mjs';
import {nearbyNpc} from './npc-services.mjs';
import {serializeLife,validateLife,lifeError as fail} from './life-transactions.mjs';
import {Container,createItem} from '../../src/systems/items/model.js';
import {Equipment,PRESETS,S} from '../../src/systems/items/equip.js';
import {optCode} from '../../src/systems/items/ui/enchant.js';
import {createQuestContext} from './quests.mjs';
import {crestRule,CREST_SUPPORTED_EFFECTS,crestInsertPrice,crestExtractDil,CREST_EXTRACT_TEXT,ENGINE_CHOSEN_UNPROTECTED_CREST_KEEP_RATE} from '../../src/systems/items/crest-rules.js';
import {progressDekaPass} from './dekapass.mjs';
import {optionNameMap,optionCodeByName,rollCostumeOptions,sewingSucceeds} from '../../src/systems/mounts/costume-rules.js';
import {wingVisual,wingUpgradeRow,wingUpgradeSucceeds,wingChangeCost,wingChangeCandidates,wingExchangeGroup} from '../../src/systems/mounts/wing-rules.js';
import {bindsOnPickup} from './item-flags.mjs';

export const ITEM_SERVICE_SCHEMAS={
  crest:['token','type','operation','uid','crests','slots','plier'],
  stonemachine:['token','type','operation','machine','locks','uids'],
  talisman:['token','type','operation','uid','effect'],
  costume:['token','type','operation','uid','slot','preset','page','x','y','count','appearance'],
  wing:['token','type','operation','uid','appearance','classIndex','ticket'],
};
const CREST_GROUPS=[23,23,24,24,25,26];
function fields(input,permitted) {if(Object.keys(input).some(key=>!['token','type','operation',...permitted].includes(key)))fail('Send only the selected service intent.');}
function integer(value,min=0,max=100000) {if(!Number.isSafeInteger(value)||value<min||value>max)fail('Invalid original item-service value.');return value;}
function originalInteger(value,min=0,max=100000) {if(value==null||value==='')fail('The original item-service value is unavailable.');return integer(Number(value),min,max);}
function debit(inv,value) {value=originalInteger(value,0,10_000_000_000);if(inv.dil<value)fail('Not enough DIL for this service.');inv.addDil(-value);}
function owned(inv,uid) {
  if(typeof uid!=='string')fail('Choose an owned item in your bag.');
  const item=inv.bag.list.find(item=>item.uid===uid);
  if(!item||item.expiresAt&&item.expiresAt<=inv.now())fail('Choose an owned, unexpired item in your bag.');return item;
}
function uniqueSlots(values,max,length) {
  if(!Array.isArray(values)||values.length>length||new Set(values).size!==values.length)fail('Choose different valid service slots.');
  for(const value of values)integer(value,0,max);return values;
}
function nearby(world,p,role) {if(!nearbyNpc(world,p,{role}))fail('Walk near the original item-service NPC.');}
function range(row,world) {
  const min=integer(Number(row.min),-1000000000,1000000000),max=integer(Number(row.max),min,1000000000);
  return min+Math.floor(world.random()*(max-min+1));
}
function originalOption(db,row) {const code=row&&optCode(db,row.type);if(code==null||!CREST_SUPPORTED_EFFECTS.has(row.type)||row.min==null||row.min===''||row.max==null||row.max===''||!Number.isFinite(Number(row.min))||!Number.isFinite(Number(row.max)))fail('The original crest option is unavailable.');return code;}
function syncCrest(item) {
  const crest=item.crest;crest.options=[...crest.slots.filter(Boolean).map(slot=>slot.opt),...(crest.bonus?[crest.bonus]:[])];
  if(!crest.slots.some(Boolean))delete item.crest;
}
function crest(world,p,inv,input) {
  nearby(world,p,'MUNZANG_MAN');const item=owned(inv,input.uid),db=inv.db,T=world.data.itemUseData?.tables;
  // Per-call view keeps original source rules local to the selected server catalog.
  const rulesDB=Object.assign(Object.create(db),{crestSources:world.data.itemServiceData?.crestSources||[]});
  if(db.def(item.itemIndex)?.slot!=='costume')fail('Only an owned costume can receive crests.');
  if(item.crest&&!Array.isArray(item.crest.slots)||item.crest?.slots?.length!==undefined&&item.crest.slots.length!==6)fail('This legacy crest layout is unsupported.');
  item.crest||={slots:Array(6).fill(null),bonus:null,options:[]};
  if(input.operation==='insert') {
    fields(input,['uid','crests']);
    if(!Array.isArray(input.crests)||!input.crests.length||input.crests.length>6)fail('Choose between one and six crests.');
    const slots=new Set(),uids=new Set();let total=0;
    const adds=input.crests.map(entry=>{
      if(!entry||Object.keys(entry).some(key=>!['slot','uid'].includes(key)))fail('Send crest slot and owned item identifiers only.');
      const slot=integer(entry.slot,0,5),source=owned(inv,entry.uid),def=db.def(source.itemIndex);
      if(slots.has(slot)||uids.has(source.uid)||source===item||item.crest.slots[slot])fail('Each empty crest slot requires a different owned item.');
      slots.add(slot);uids.add(source.uid);
      if(Number(def?.type)!==1||Number(def.code)!==CREST_GROUPS[slot])fail('The crest color does not match that slot.');
      const row=crestRule(rulesDB,T,def),code=originalOption(db,row);
      const price=crestInsertPrice(db,T,def);
      if(price.error==='missing')fail('The original crest price is unavailable.');
      if(price.error==='value')fail('The original crest price value is unavailable.');
      if(price.error==='ambiguous')fail('The original crest price is ambiguous.');total+=price.dil;
      return {slot,source,row,code};
    });
    debit(inv,total);
    for(const {slot,source,row,code} of adds) {
      const saved=structuredClone(source);saved.count=1;delete saved.page;delete saved.x;delete saved.y;
      // Nonstackable original crests keep their exact instance metadata through extraction.
      if(db.stackSize(db.def(source.itemIndex))!==1)fail('Stacked crest metadata is unsupported.');
      if(!inv.consumeEntry(source,1))fail('The selected crest is unavailable.');
      item.crest.slots[slot]={item:source.itemIndex,opt:[code,range(row,world)],source:saved};
    }
    if(item.crest.slots.every(Boolean)&&!item.crest.bonus) {
      // Same established solo bonus pool; unsupported translations/options never become guessed stats.
      const rows=T?.crestIncuse?.rows?.filter(row=>Number.isFinite(Number(row.level))&&!/[^\x00-\x7f]/.test(row.descEn||''))||[];
      if(!rows.length)fail('The original full-crest bonus pool is unavailable.');
      const row=rows[Math.floor(world.random()*rows.length)];item.crest.bonus=[originalOption(db,row),range(row,world)];
    }
    syncCrest(item);return {uid:item.uid,inserted:adds.length};
  }
  if(input.operation!=='extract')fail('Unknown crest operation.');fields(input,['uid','slots','plier']);
  const slots=uniqueSlots(input.slots,5,6);if(!slots.length||slots.some(slot=>!item.crest.slots[slot]))fail('Select installed crests to extract.');
  const plier=input.plier?owned(inv,input.plier):null,pd=plier&&db.def(plier.itemIndex);
  if(plier&&(Number(pd?.type)!==1||![27,28].includes(Number(pd.code))))fail('Choose an original Plier or Hot Plier.');
  if(slots.length>1&&Number(pd?.code)!==28)fail('Use a Hot Plier to extract several crests.');
  // Removal is priced per crest grade (official guide 16; 311:32/311:33); the Hot Plier removes without DIL. The price is paid
  // whether or not an unprotected extraction keeps the crest, inside the same staged profile as the plier and the slots.
  const price=crestExtractDil(slots.map(slot=>db.def(item.crest.slots[slot].item)),{hotPlier:Number(pd?.code)===28});
  if(price==null)fail(CREST_EXTRACT_TEXT.unknown);
  if(inv.dil<price)fail(CREST_EXTRACT_TEXT.dil);
  inv.addDil(-price);
  const keep=!!plier||world.random()<ENGINE_CHOSEN_UNPROTECTED_CREST_KEEP_RATE;
  if(plier&&!inv.consumeEntry(plier,1))fail('The selected plier is unavailable.');
  if(keep)for(const slot of slots) {
    const stored=item.crest.slots[slot],def=db.def(stored.item);
    if(!def)fail('The extracted original crest is unavailable.');
    const source=stored.source?structuredClone(stored.source):createItem(db,stored.item,{now:world.now(),rng:world.random,roll:false});
    if(source.itemIndex!==stored.item||source.count!==1||inv.bag.list.some(item=>item.uid===source.uid))fail('The extracted crest metadata is invalid.');
    if(!inv.bag.add(source).ok)fail('Your inventory cannot fit the extracted crests.');
  }
  for(const slot of slots)item.crest.slots[slot]=null;item.crest.bonus=null;syncCrest(item);
  return {uid:item.uid,kept:keep,extracted:slots.length,dil:price};
}
function removeKind(inv,code,count) {
  integer(code,1,10000);integer(count);
  let left=count;for(const item of [...inv.bag.list]) {
    const def=inv.db.def(item.itemIndex);if(Number(def?.type)!==0||Number(def.code)!==code||item.expiresAt&&item.expiresAt<=inv.now())continue;
    const take=Math.min(left,item.count||1);if(take&&!inv.consumeEntry(item,take))fail('A machine material is unavailable.');left-=take;if(!left)break;
  }
  if(left)fail('Missing original stone-machine materials or locks.');
}
function stone(world,p,inv,input) {
  const data=world.data.itemServiceData;
  if(input.operation==='produce') {
    fields(input,['machine','locks']);
    // The original combined window exposes production and crushing from either machine job.
    if(!nearbyNpc(world,p,{role:'ITEM_SOCKETSTONE_PRODUCE'})&&!nearbyNpc(world,p,{role:'ITEM_SOCKETSTONE_CRUSHER'}))fail('Walk near the original stone-machine NPC.');
    integer(input.machine,1);
    const row=data?.stoneProduce?.find(row=>Number(row.Index)===input.machine);if(!row)fail('This original stone machine is unavailable.');
    const count=integer(Number(row.Count),1,20),locks=uniqueSlots(input.locks,count-1,count),normal=integer(Number(row.Normal_Lock_Viable),0,count),premium=integer(Number(row.Primium_Lock_Viable),0,count);
    if(locks.length>normal+premium)fail('Too many stone-machine locks.');
    const results=[];let previous=0;
    for(let i=1;i<=count;i++) {
      const dice=integer(Number(row[`Dice_${i}`]),previous,1000000000),index=integer(Number(row[`Result_Item_${i}`]),1,Number.MAX_SAFE_INTEGER);
      if(!inv.db.def(index))fail('An original machine outcome is unavailable.');
      const weight=dice-previous;previous=dice;if(weight>0&&!locks.includes(i-1))results.push({slot:i-1,index,weight});
    }
    const total=results.reduce((sum,row)=>sum+row.weight,0);if(!total)fail('All original machine outcomes are locked or unavailable.');
    debit(inv,row.Need_DIL);removeKind(inv,Number(row.Need_Item_Type),Number(row.Need_Item_Count));
    const nl=Math.min(normal,locks.length),pl=locks.length-nl;
    removeKind(inv,Number(row.Normal_Lock_Need_ItemType),nl);removeKind(inv,Number(row.Primium_Lock_Need_ItemType),pl);
    let dice=world.random()*total,result=results.at(-1);for(const choice of results) {if(dice<choice.weight){result=choice;break;}dice-=choice.weight;}
    if(!inv.add(result.index,1,{roll:false}))fail('Your inventory cannot fit the machine result.');
    return {machine:input.machine,slot:result.slot,itemIndex:result.index,count:1};
  }
  if(input.operation!=='crush')fail('Unknown stone-machine operation.');fields(input,['uids']);nearby(world,p,'ITEM_SOCKETSTONE_CRUSHER');
  if(!Array.isArray(input.uids)||!input.uids.length||input.uids.length>10||new Set(input.uids).size!==input.uids.length)fail('Choose up to ten different owned stones.');
  let totalCost=0;const sources=input.uids.map(uid=>{
    const item=owned(inv,uid),row=data?.stoneCrusher?.find(row=>Number(row.Need_Item)===item.itemIndex);if(!row)fail('This stone has no original crushing rule.');
    totalCost+=originalInteger(row.Need_Dil,0,10_000_000_000);return {item,row};
  });debit(inv,totalCost);
  const outputs=new Map();
  for(const {item,row} of sources) {
    const min=integer(Number(row.Count_Min)),max=integer(Number(row.Count_Max),min),out=integer(Number(row.Output_Item),1,Number.MAX_SAFE_INTEGER);
    if(!inv.db.def(out))fail('The original crusher output is unavailable.');
    const count=Math.round(min+world.random()*(max-min));outputs.set(out,(outputs.get(out)||0)+count);
    if(!inv.consumeEntry(item,1))fail('The selected stone is unavailable.');
  }
  for(const [index,count]of outputs)if(count&&!inv.add(index,count,{roll:false}))fail('Your inventory cannot fit the crushed materials.');
  return {outputs:[...outputs].map(([itemIndex,count])=>({itemIndex,count}))};
}
function talisman(world,p,inv,input) {
  nearby(world,p,'TALISMAN_EFFECT_TRANSFORM');const item=owned(inv,input.uid),def=inv.db.def(item.itemIndex),rows=world.data.itemServiceData?.talisman;
  if(Number(def?.type)!==5||Number(def.code)!==18)fail('Choose an owned talisman.');
  if(input.operation==='transform') {
    fields(input,['uid','effect']);integer(input.effect,1);
    const row=rows?.find(row=>Number(row.effectIndex)===input.effect);if(!row)fail('This original talisman appearance is unavailable.');
    if(item.appearance===input.effect)fail('That talisman appearance is already applied.');debit(inv,row.NeedDil);
    for(let k=1;k<=2;k++) {
      const index=integer(Number(row[`NeedItemIndex${k}`]),0,Number.MAX_SAFE_INTEGER),count=integer(Number(row[`NeedItem${k}Count`]));
      if(!index&&count||index&&(!count||!inv.remove(index,count)))fail('Missing original talisman materials.');
    }
    item.appearance=input.effect;
  } else if(input.operation==='reset') {
    fields(input,['uid']);const row=rows?.find(row=>Number(row.effectIndex)===item.appearance);
    if(item.appearance==null||!row)fail('This talisman has no supported appearance to reset.');debit(inv,row.ResetDil);delete item.appearance;
  }else fail('Unknown talisman operation.');
  return {uid:item.uid,effect:item.appearance??null};
}
function costume(world,p,inv,input) {
  const profile=inv.profile,wardrobe=new Container(profile.costumeBag||=[],inv.db,{pages:1,cols:6,rows:8,name:'costume',accept:def=>def?.slot==='costume'});
  if(['fabric','disassemble','shape','sew','option'].includes(input.operation))return costumeCycle(world,p,inv,wardrobe,input);
  const equip=new Equipment({db:inv.db,game:{save:profile,player:{stats:p.stats}},changed(){}});
  if(['deposit','withdraw','move'].includes(input.operation)) {
    fields(input,['uid','page','x','y']);const source=input.operation==='deposit'?inv.bag:wardrobe,target=input.operation==='withdraw'?inv.bag:wardrobe;
    const item=source.byUid(input.uid);if(!item||item.expiresAt&&item.expiresAt<=world.now()||inv.db.def(item.itemIndex)?.slot!=='costume')fail('Choose an owned, unexpired costume.');
    const at=inventoryDestination(input,target);
    if(input.operation==='move') {if(!at||!source.moveTo(item,at.page,at.x,at.y))fail('The requested costume position is unavailable.');}
    else {source.take(item);if(!receiveAt(target,item,at))fail('The requested costume destination is unavailable or full.');}
    return {uid:item.uid};
  }
  if(!['equip','unequip','swap'].includes(input.operation))fail('Unknown costume operation.');
  if(profile.equip?.locked)fail('Equipment is locked.');const preset=input.preset==null?equip.data.active:integer(input.preset,0,PRESETS-1);
  if(input.operation==='swap') {fields(input,['preset']);equip.swapCostume();if(preset!==equip.data.active)fail('Only the active costume preset can be swapped.');return {};}
  if(input.operation==='equip') {
    fields(input,['uid','slot','preset']);const item=wardrobe.byUid(input.uid);if(!item||item.expiresAt&&item.expiresAt<=world.now())fail('Choose an owned, unexpired wardrobe costume.');
    const slot=input.slot==null?equip.autoSlot(inv.db.def(item.itemIndex),preset):integer(input.slot,0,114);
    if(![S.costume,S.costume2].includes(slot)||!equip.check(item,slot,p.stats).ok)fail('This costume does not meet the slot, class or level requirements.');
    wardrobe.take(item);delete item.page;delete item.x;delete item.y;if(bindsOnPickup(inv.db.def(item.itemIndex)))item.bound=true;
    const result=equip.place(item,slot,preset);for(const old of result.displaced)if(!inv.bag.add(old).ok)fail('Your inventory cannot fit the replaced costume.');return {uid:item.uid};
  }
  fields(input,['slot','preset','page','x','y']);const slot=integer(input.slot,0,114);
  if(![S.costume,S.costume2].includes(slot)||!equip.get(slot,preset))fail('Choose an equipped costume slot.');
  const at=inventoryDestination(input,wardrobe),result=equip.remove(slot,preset);
  if(result.inst&&!receiveAt(wardrobe,result.inst,at))fail('The requested wardrobe position is unavailable or full.');return {sharedPreset:!result.inst};
}
function costumeCycle(world,p,inv,wardrobe,input) {
  nearby(world,p,'COSTUME_CYCLE');const tables=world.data.itemServiceData?.costume;
  const rule=type=>{
    const rows=tables?.sewing?.filter(row=>Number(row.Type)===type);
    if(rows?.length!==1)fail('The original costume service rule is unavailable.');return rows[0];
  };
  const itemIndex=value=>{const index=integer(Number(value),1,Number.MAX_SAFE_INTEGER);if(!inv.db.def(index))fail('The original costume service item is unavailable.');return index;};
  /** Dil + fabric of a costumesewing.csv row (the bound variant first); a throw discards the staged profile, so nothing is half-paid. */
  const payFabric=row=>{
    const primary=itemIndex(row.KeyItem_index_1),secondary=itemIndex(row.KeyItem_index_2),need=integer(Number(row.Keycount),1);
    if(primary===secondary)fail('The original fabric variants are ambiguous.');
    debit(inv,row.Dil);const first=Math.min(need,inv.count(primary));
    if(first&&!inv.remove(primary,first)||need>first&&!inv.remove(secondary,need-first))fail('Missing original costume materials.');
  };
  if(input.operation==='sew') {
    // Transcendence (costumesewing.csv Type 0): each attempt costs the fabric + dil; on success the class's Transcendence Costume
    // is made wearing the chosen appearance (costumesewinglist.csv Type 0); a failed roll keeps nothing (Penalty NOT_FAIL).
    fields(input,['appearance']);const appearance=integer(input.appearance,1,Number.MAX_SAFE_INTEGER),look=inv.db.def(appearance),ci=integer(inv.profile.classIndex,0,14);
    if(!tables?.sewingList?.some(row=>Number(row.Type)===0&&Number(row.Itemindex)===appearance)||look?.slot!=='costume'||!((Number(look.classMask)>>>ci)&1))fail('This original appearance is unavailable for your class.');
    const visual=world.data.mountData?.costumes?.[appearance],asset=visual?.c?visual.c[ci]:visual?.a;
    if(asset==null||!world.data.mountData?.assets?.[asset])fail('The original costume appearance is unavailable.');
    const row=rule(0);if(row.Penalty!=='NOT_FAIL'||originalInteger(row.Keycount2)!==0)fail('This costume sewing rule is unsupported.');
    const reward=tables?.transcendence?.find(entry=>(Number(inv.db.def(Number(entry.ItemIndex))?.classMask)>>>ci)&1);
    if(!reward)fail('The original Transcendence Costume for your class is unavailable.');
    payFabric(row);
    if(!sewingSucceeds(integer(Number(row.Rate),0,1000000),world.random))return {sewn:false};
    const rewardIndex=itemIndex(reward.ItemIndex);
    if(!inv.add(rewardIndex,1,{roll:false}))fail('Your inventory cannot fit the Transcendence Costume.');
    const made=[...inv.bag.list].reverse().find(entry=>entry.itemIndex===rewardIndex&&entry.appearance==null);
    if(!made)fail('The sewn costume could not be placed.');made.appearance=appearance;return {sewn:true,uid:made.uid,itemIndex:rewardIndex,appearance};
  }
  if(input.operation==='fabric') {
    fields(input,['count']);const count=integer(input.count,1,10000),row=rule(4);
    if(Number(row.Rate)!==1000000||row.Penalty!=='NOT_FAIL')fail('This costume exchange outcome is unsupported.');
    const primary=itemIndex(row.KeyItem_index_1),secondary=itemIndex(row.KeyItem_index_2),output=itemIndex(row.Itemindex);
    const need=integer(Number(row.Keycount),1)*count,need2=integer(Number(row.Keycount2),1)*count;
    debit(inv,originalInteger(row.Dil,0,10_000_000_000)*count);
    if(!inv.remove(primary,need)||!inv.remove(secondary,need2))fail('Missing original fabric exchange materials.');
    if(!inv.add(output,count,{roll:false}))fail('Your inventory cannot fit the exchanged fabric.');
    return {itemIndex:output,count};
  }
  const container=inv.bag.byUid(input.uid)?inv.bag:wardrobe,item=container.byUid(input.uid),def=item&&inv.db.def(item.itemIndex);
  if(typeof input.uid!=='string'||!item||def?.slot!=='costume'||item.expiresAt&&item.expiresAt<=world.now())fail('Choose an owned, unexpired costume in your bag or wardrobe.');
  if((item.count||1)!==1||inv.db.stackSize(def)!==1)fail('Stacked costume services are unsupported.');
  const trans=tables?.transcendence?.some(row=>Number(row.ItemIndex)===item.itemIndex);
  if(input.operation==='disassemble') {
    fields(input,['uid']);const rows=tables?.disassemble?.filter(row=>Number(row.ItemIndex)===item.itemIndex);
    if(rows?.length>1)fail('The original costume dismantling rule is ambiguous.');
    let row=rows?.[0];
    if(!row&&trans) {
      const original=rule(1);
      if(Number(original.Rate)!==1000000||original.Penalty!=='RETRUN_ITEM'||originalInteger(original.Keycount2)!==0)fail('This costume return rule is unsupported.');
      row={Output_Item:original.KeyItem_index_1,Count_Min:original.Keycount,Count_Max:original.Keycount,Need_Dil:original.Dil};
    }
    if(!row)fail('This costume has no original dismantling rule.');
    const min=integer(Number(row.Count_Min),1),max=integer(Number(row.Count_Max),min);
    // Current original rows are exact returns; unknown random count distributions stay disabled.
    if(min!==max)fail('This costume dismantling distribution is unsupported.');
    const output=itemIndex(row.Output_Item);debit(inv,row.Need_Dil);
    container.take(item);if(!inv.add(output,min,{roll:false}))fail('Your inventory cannot fit the costume materials.');
    return {uid:item.uid,itemIndex:output,count:min};
  }
  if(input.operation==='option') {
    // Change Options (costumesewing.csv Type 2): three new random options of costume_option.csv replace the old ones.
    fields(input,['uid']);if(!trans)fail('Choose an original Transcendence Costume.');
    const row=rule(2);if(Number(row.Rate)!==1000000||row.Penalty!=='NOT_FAIL'||originalInteger(row.Keycount2)!==0)fail('This costume option rule is unsupported.');
    const byName=optionNameMap(inv.db.options?.optionTypes,world.data.mountData?.optionLabels);
    const rolled=rollCostumeOptions(tables?.option,name=>optionCodeByName(byName,name),world.random);
    if(rolled.length!==3)fail('The original costume option table is unavailable.');
    payFabric(row);item.rnd=rolled;return {uid:item.uid,rnd:rolled};
  }
  fields(input,['uid','appearance']);if(!trans)fail('Choose an original Transcendence Costume.');
  const appearance=integer(input.appearance,1,Number.MAX_SAFE_INTEGER),look=inv.db.def(appearance),ci=integer(inv.profile.classIndex,0,14);
  const rows=tables?.shapes?.filter(row=>Number(row.Itemindex)===appearance);
  if(!rows?.length||rows.some(row=>Number(row.Type)!==2)||look?.slot!=='costume'||!((Number(look.classMask)>>>ci)&1)||!((Number(def.classMask)>>>ci)&1))fail('This original appearance is unavailable for your class.');
  const visual=world.data.mountData?.costumes?.[appearance],asset=visual?.c?visual.c[ci]:visual?.a;
  if(asset==null||!world.data.mountData?.assets?.[asset])fail('The original costume appearance is unavailable.');
  if(item.appearance===appearance)fail('That costume appearance is already applied.');
  const row=rule(3);if(Number(row.Rate)!==1000000||row.Penalty!=='NOT_FAIL'||originalInteger(row.Keycount2)!==0)fail('This costume appearance rule is unsupported.');
  const primary=itemIndex(row.KeyItem_index_1),secondary=itemIndex(row.KeyItem_index_2),need=integer(Number(row.Keycount),1);
  if(primary===secondary)fail('The original fabric variants are ambiguous.');
  debit(inv,row.Dil);const first=Math.min(need,inv.count(primary));
  if(first&&!inv.remove(primary,first)||need>first&&!inv.remove(secondary,need-first))fail('Missing original costume appearance materials.');
  item.appearance=appearance;return {uid:item.uid,appearance};
}
/**
 * Wing services (game2/itemupgrade/ui_wing*.txt), all on a wing in the bag:
 *   upgrade   Wing Awakening at WINGUPGRADE: wingupgrade.csv WINGS row of the wing's item level: material x count + dil, success
 *             rate percent, penalty NOT_FAIL (a failed roll only loses the cost); success turns it into the item's `next`
 *   shape     appearance change at WING_SHAPE_CHANGE: one of the wingchangelist.csv candidates for the wing, cost = the first row's
 *             NeedMoney + NeedMaterialIndex1 x NeedCount; the look is item.appearance
 *   restore   back to the wing's own look (same cost)
 *   exchange  Wing Class Exchange (ticket item type 0 / code 81): the same wing of another class (itemwingexchange.csv)
 */
function wing(world,p,inv,input) {
  const tables=world.data.itemServiceData?.wing,mount=world.data.mountData;
  if(!tables?.upgrade?.length||!tables.change?.length||!tables.exchange?.length)fail('The original wing service tables are unavailable.');
  const ci=integer(inv.profile.classIndex,0,14),defOf=index=>inv.db.def(index),visualOf=index=>wingVisual(mount,index);
  const wingOf=uid=>{
    if(typeof uid!=='string')fail('Choose an owned wing in your bag.');
    const item=inv.bag.byUid(uid);
    if(!item||item.expiresAt&&item.expiresAt<=inv.now())fail('Choose an owned, unexpired wing in your bag.');
    if(defOf(item.itemIndex)?.slot!=='wing'&&!visualOf(item.itemIndex))fail('Choose a wing.');
    if((item.count||1)!==1)fail('Stacked wing services are unsupported.');
    return item;
  };
  const payChange=()=>{
    const row=wingChangeCost(tables.change);if(!row)fail('The original wing appearance cost is unavailable.');
    const material=integer(Number(row.NeedMaterialIndex1),1,Number.MAX_SAFE_INTEGER),need=integer(Number(row.NeedCount),1);
    if(!defOf(material))fail('The original wing service item is unavailable.');
    debit(inv,row.NeedMoney);if(!inv.remove(material,need))fail('Missing original wing appearance materials.');
  };
  if(input.operation==='upgrade') {
    nearby(world,p,'WINGUPGRADE');fields(input,['uid']);
    const item=wingOf(input.uid),def=defOf(item.itemIndex),row=wingUpgradeRow(tables.upgrade,def);
    if(!def?.next||!row||!defOf(def.next))fail('This wing is already awakened to the maximum level.');
    if(row.penalty!=='NOT_FAIL')fail('This wing awakening penalty is unsupported.');
    const material=integer(Number(row.material),1,Number.MAX_SAFE_INTEGER),need=integer(Number(row.materialCount),1),rate=originalInteger(row.rate,0,100);
    if(!defOf(material))fail('The original wing awakening material is unavailable.');
    debit(inv,row.costDil);if(!inv.remove(material,need))fail('Missing original wing awakening materials.');
    if(!wingUpgradeSucceeds(rate,world.random))return {upgraded:false,uid:item.uid,itemIndex:item.itemIndex};
    item.itemIndex=def.next;if(item.index!=null)item.index=def.next;
    return {upgraded:true,uid:item.uid,itemIndex:item.itemIndex};
  }
  if(input.operation==='shape') {
    nearby(world,p,'WING_SHAPE_CHANGE');fields(input,['uid','appearance']);
    const item=wingOf(input.uid),appearance=integer(input.appearance,1,Number.MAX_SAFE_INTEGER);
    if(!wingChangeCandidates({rows:tables.change,index:item.itemIndex,classIndex:ci,defOf,visualOf}).includes(appearance))fail('This original wing appearance is unavailable for this wing.');
    if(item.appearance===appearance)fail('That wing appearance is already applied.');
    payChange();item.appearance=appearance;return {uid:item.uid,appearance};
  }
  if(input.operation==='restore') {
    nearby(world,p,'WING_SHAPE_CHANGE');fields(input,['uid']);
    const item=wingOf(input.uid);if(!item.appearance)fail('This wing already has its own appearance.');
    payChange();delete item.appearance;return {uid:item.uid,restored:true};
  }
  if(input.operation==='exchange') {
    fields(input,['uid','classIndex','ticket']);
    const item=wingOf(input.uid),target=integer(input.classIndex,0,14),group=wingExchangeGroup(tables.exchange,item.itemIndex),next=group?Number(group[`class${target}`]):0;
    if(!group||!next||next===item.itemIndex||!defOf(next))fail('This wing cannot be exchanged to that class.');
    const ticket=typeof input.ticket==='string'?inv.bag.byUid(input.ticket):inv.bag.list.find(entry=>defOf(entry.itemIndex)?.type===0&&defOf(entry.itemIndex)?.code===81);
    const ticketDef=ticket&&defOf(ticket.itemIndex);
    if(!ticket||ticket.expiresAt&&ticket.expiresAt<=inv.now()||ticketDef?.type!==0||ticketDef?.code!==81)fail('A Wing Class Exchange ticket is required.');
    if(!inv.consumeEntry(ticket,1))fail('A Wing Class Exchange ticket is required.');
    item.itemIndex=next;if(item.index!=null)item.index=next;return {uid:item.uid,itemIndex:next};
  }
  fail('Unknown wing operation.');
}
/** Call from the central action router after lease/schema validation and trade cancellation. */
export function itemServiceCommand(world,p,input) {return serializeLife(p,async()=>{
  validateLife(input,ITEM_SERVICE_SCHEMAS);
  if(p.dead||p.leaving||p.sceneTransition)fail('Item services are unavailable while dead or changing maps.');
  if(!world.data.itemDB)fail('The original item catalog is unavailable.');
  const profile=structuredClone(p.profile),inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});
  const result=({crest,stonemachine:stone,talisman,costume,wing})[input.type](world,p,inv,input);
  if(input.type==='wing'&&(input.operation==='shape'||input.operation==='upgrade'&&result.upgraded)) {
    // Original season missions of the WING category (10): 29 = awakening (UPGRADE, counted on success), 24 = appearance change
    progressDekaPass({...world,changed(){}},{...p,profile},10,input.operation==='shape'?24:29,result.itemIndex??inv.bag.byUid(input.uid)?.itemIndex??0,1);
  }
  if(input.type==='costume'&&['shape','sew','option'].includes(input.operation)) {
    // Original season missions of the COSTUME category (6): 24 = appearance change (SHAPECHANGE), 23 = create a Transcendence
    // Costume (a successful sewing), 11 = change its options (5 times). Progress belongs to the same staged profile as the
    // service costs and result.
    const credit=(sub,itemIndex)=>progressDekaPass({...world,changed(){}},{...p,profile},6,sub,itemIndex,1);
    if(input.operation==='sew') {if(result.sewn)credit(23,result.itemIndex);}
    else credit(input.operation==='shape'?24:11,(inv.bag.byUid(input.uid)||profile.costumeBag?.find(item=>item.uid===input.uid)).itemIndex);
  }
  const quests=createQuestContext(world,p,{profile,inventory:inv,commitToPlayer:false});
  quests?.engine.recountCollect(null,true);
  // Existing simulation guard freezes this actor during the durable write. SSE snapshots
  // continue to expose the old inventory until persistence succeeds.
  const previousTransition=p.sceneTransition;p.sceneTransition=true;
  try {
    const candidate={...p,profile};
    if(world.data.stats){candidate.stats=world.data.stats(profile,p,world.now());candidate.maxHp=candidate.stats.maxHp;candidate.hp=Math.min(p.hp,candidate.maxHp);candidate.mp=Math.min(p.mp||0,candidate.stats.maxMp||0);}
    world.changed(candidate);await world.persist(candidate);
    p.profile=profile;p.stats=candidate.stats;p.maxHp=candidate.maxHp;p.hp=candidate.hp;p.mp=candidate.mp;
    world.changed(p);p.dirty=false;p.saveError=null;
  } finally {p.sceneTransition=previousTransition;}
  quests?.commit();
  world.emit(p.map,{type:'itemservice',actorId:p.id,service:input.type,operation:input.operation,...result});
  return result;
});}

