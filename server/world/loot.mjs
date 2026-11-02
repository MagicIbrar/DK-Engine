import {mapFor,sameScene} from './scene.mjs';
import {randomUUID} from 'node:crypto';
import {rollMonsterDrops,LootSystem} from '../../src/game/loot.js';
import fs from 'node:fs/promises';
import path from 'node:path';
import {partyLootOwner,partyDilRewards} from './party.mjs';
import {AuthoritativeInventory} from './inventory.mjs';
import {createItem} from '../../src/systems/items/model.js';
import {DEFAULT_WORLD_RATES,scaledReward} from './rates.mjs';
import {playerRewardBonus} from '../../src/game/reward-bonus.js';
import {formulaOf} from '../../src/game/progression.js';
import {commitLife} from './life-transactions.mjs';
import {persistInterveningProgress} from './profile-publication.mjs';
import {rollMapDrops} from './map-drops.mjs';
import {canDiscardDef,canDropToGround} from './item-flags.mjs';
import {activePremiums} from '../../src/systems/shops/premium-rules.js';
// ENGINE-CHOSEN (scan fix A, A6): how long a ground drop stays. No Global data key (share/formula.ini has only
// dwOwnershipLifeTime 20000 for ownership) and no decompile constant for it was found, so 180 s is this engine's choice,
// shared with the offline client (src/game/loot.js DROP_LIFETIME).
export const GROUND_LOOT_LIFETIME_MS=180000;
const pickupClaims=new WeakSet();
export const LOOT_ACTION_SCHEMAS={pickup:['token','type','dropId'],discard:['token','type','uid','count'],dropdil:['token','type','amount']};
export async function loadWorldLootData(gamedataRoot){const json=JSON.parse(await fs.readFile(path.join(gamedataRoot,'gmcommands_monsters.json'),'utf8')),byMap=new Map();for(const row of json.classDrops||[]){const map=Number(row[0]);if(!byMap.has(map))byMap.set(map,[]);byMap.get(map).push(row);}return {byMap,mapDrops:json.mapDrops||{},itemSets:json.itemSets||{}};}
export function groundDrops(world,map,instanceId=null,channel=0){world.groundLoot||=new Map();for(const[id,d]of world.groundLoot)if(d.expiresAt<=world.now())world.groundLoot.delete(id);return [...world.groundLoot.values()].filter(d=>sameScene(d,{map,instanceId,channel})).map(d=>({...d}));}
/** share/formula.ini dwOwnershipLifeTime (ms; Global g2 formula.ini:44 = 20000); Global's 20000 only when the key is absent. */
export function lootOwnershipMs(world){const native=Number(formulaOf(world?.data?.progressionData)?.dwOwnershipLifeTime);return Number.isFinite(native)?Math.max(0,native):20000;}
function add(world,p,entry,x,z){world.groundLoot||=new Map();const ownershipMs=lootOwnershipMs(world); // share/formula.ini dwOwnershipLifeTime (milliseconds); Global inventory guide confirms 20s.
const d={id:randomUUID(),map:p.map,instanceId:p.instanceId||null,channel:p.channel??0,x,z,entry,ownerId:p.id,protectedUntil:world.now()+ownershipMs,expiresAt:world.now()+GROUND_LOOT_LIFETIME_MS};world.groundLoot.set(d.id,d);return d;}
export function grantGroundItem(world,p,inst){return add(world,p,{kind:'item',itemIndex:inst.itemIndex,name:inst.name,count:inst.count,grade:inst.grade,inst},p.x,p.z);}
// + the killer's RESULT_DROP_MUL / RESULT_DIL_MUL (buffs / items, src/game/reward-bonus.js) on the item drop chance and dropped DIL
export function monsterLoot(world,p,m){const db=world.data.progression?.monsters||world.data.monsters;if(!db)return false;const now=world.now?.()??Date.now(),formula=world.data.progressionData?.formula||{},rates=world.rates||DEFAULT_WORLD_RATES,tune=world.monsterTuning?.get(Number(m.monsterIndex)),itemRate=(Number(formula.fMonItemDropRatio)||1)*rates.drop*(tune?.drop||1)*(1+playerRewardBonus('drop',p,now)/100),moneyRate=Number(formula.fMonMoneyDropRatio)||1,dilBonus=1+playerRewardBonus('dil',p,now)/100;
// scan fix A (M2/M3): premium decides PREMIUM_Y/PREMIUM_N drop rows (JUDGMENT, see dropConditionMet); GainLimitTime (ms, Global
// rows 9490/9690 = 30000) is read as that row's ownership time in place of dwOwnershipLifeTime (JUDGMENT); PetPick 0 rows
// are marked so the pet auto-pickup (pets.mjs) leaves them.
const rowTags=d=>{const dr=m.def?.drops;if(Number(dr?.gainLimitTime)>0)d.protectedUntil=world.now()+Number(dr.gainLimitTime);if(dr?.noPetPick)d.noPetPick=true;return d;};
const entries=rollMonsterDrops(m.def,db,{rng:world.random,itemRate,moneyRate,premium:activePremiums(p.profile?.premium,now).length>0});if(world.data.lootData){entries.push(...rollMapDrops({map:p.map,monsterIndex:m.monsterIndex,lootData:world.data.lootData,itemNames:db.itemNames},{rng:world.random,itemRate}));entries.push(...LootSystem.prototype.rollClassDrops.call({_classDrops:world.data.lootData,game:{world:{info:{index:p.map}},save:p.profile,data:{monsters:db}}},m,m.def,{itemRate,rng:world.random}));}
for(const [itemIndex,rule] of tune?.items||[])if(world.random()*100000<Math.min(100000,rule.chance*itemRate))entries.push({kind:'item',itemIndex,count:rule.count,name:world.data.itemDB.def(itemIndex)?.name||`Item ${itemIndex}`});
for(const entry of entries){
  if(entry.kind==='dil')entry.amount=Math.floor(scaledReward(entry.amount,rates.dil)*dilBonus);
  if(entry.kind==='item'){
    const itemDB=world.data.itemDB,def=itemDB?.def(entry.itemIndex);if(!def)continue;
    // Fix the random rank options at monster death. A full bag, retry or different pickup path must not reroll
    // this same dropped item. Equipment counts become distinct instances; native stackables retain their count.
    const n=itemDB.stackSize(def)<=1?Math.max(1,Number(entry.count)||1):1;
    for(let i=0;i<n;i++){
      const inst=createItem(itemDB,entry.itemIndex,{grade:entry.grade,count:n===1?entry.count:1,now,rng:world.random});
      const ownership=partyLootOwner(world,p,m),drop=rowTags(add(world,ownership.player||p,{...entry,count:inst.count,grade:inst.grade,inst},m.x??p.x,m.z??p.z));if(ownership.free)drop.protectedUntil=0;
    }
    continue;
  }
  const ownership=partyLootOwner(world,p,m);const drop=rowTags(add(world,ownership.player||p,entry,m.x??p.x,m.z??p.z));if(ownership.free)drop.protectedUntil=0;
}return true;}
export async function dispatchLootAction(world,p,input){if(!Object.hasOwn(LOOT_ACTION_SCHEMAS,input.type))return false;
  const fail=message=>{throw Object.assign(new Error(message),{status:400});};if(p.dead)fail(input.type==='pickup'?(world.groundLoot?.get?.(input.dropId)?.entry?.kind==='dil'?'You cannot pick up dil while dead.':'You cannot pick up items while dead.'):input.type==='dropdil'?'Failed to discard the dil.':'Failed to discard the item(s).'); // Global 40:84/74/92/79
  const profile=structuredClone(p.profile),inventory=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});let gotDil=0,gotItem=null,picked=null,created=null,dilShares=null;
  if(input.type==='pickup'){
    groundDrops(world,p.map,p.instanceId);const drop=world.groundLoot.get(input.dropId);
    if(!drop||!sameScene(drop,p)||Math.hypot(drop.x-p.x,drop.z-p.z)>3)fail('Walk near an existing ground drop.');
    if(pickupClaims.has(drop))fail('This drop is already being picked up.');
    if(drop.protectedUntil>world.now()&&drop.ownerId!==p.id)fail(drop.entry.kind==='dil'?'[Message] This dil is reserved for another user.':'[Message] This item is reserved for another user.');
    if(drop.entry.kind==='dil'){dilShares=partyDilRewards(world,p,drop.entry.amount,drop);const share=dilShares.find(s=>s.player===p)?.dil||0,before=inventory.dil;inventory.addDil(share);gotDil=inventory.dil-before;}   // what the bag really gained (10 B cap)
    else{if(drop.entry.inst?!inventory.bag.add(structuredClone(drop.entry.inst)).ok:!inventory.add(drop.entry.itemIndex,drop.entry.count||1,{grade:drop.entry.grade}))fail('You do not have enough Inventory space.');
      gotItem={name:drop.entry.name||drop.entry.inst?.name||world.data.itemDB?.def?.(drop.entry.itemIndex)?.name||`Item ${drop.entry.itemIndex}`,count:Number(drop.entry.count||drop.entry.inst?.count)||1,grade:drop.entry.inst?.grade||drop.entry.grade||'normal'};}
    picked=drop;pickupClaims.add(drop);
  }else if(input.type==='dropdil'){
    if(!Number.isSafeInteger(input.amount)||input.amount<1||input.amount>inventory.dil)fail('Choose an owned DIL amount.');
    if(Number(mapFor(world,p)?.row?.ItemDrop??1)===0)fail('You cannot discard items or dil while in this map.');
    inventory.addDil(-input.amount);created={kind:'dil',amount:input.amount};
  }else{
    const item=inventory.bag.list.find(i=>i.uid===input.uid),count=input.count;
    if(!item||!Number.isInteger(count)||count<1||count>(item.count||1))fail('Choose an owned inventory item and quantity.');
    const def=world.data.itemDB.def(item.itemIndex);if(!canDiscardDef(def))fail('[Message] Quest or Event items cannot be discarded.');
    if(Number(mapFor(world,p)?.row?.ItemDrop??1)===0)fail('You cannot discard items or dil while in this map.');
    const taken=inventory.bag.take(item,count);if(canDropToGround(def,item))created={kind:'item',itemIndex:taken.itemIndex,name:taken.name,count:taken.count,grade:taken.grade,inst:taken};
  }
  try{
    // Ground ownership changes only after the same inventory transaction has reached durable storage.
    if(dilShares?.some(s=>s.player!==p))await commitPartyDil(world,p,dilShares);
    else await commitLife(world,p,profile);
    if(picked)world.groundLoot.delete(picked.id);if(created)add(world,p,created,p.x,p.z);
    world.emit(p.map,{type:'loot',actorId:p.id,...(gotDil>0?{dil:gotDil}:{}),...(gotItem?{item:gotItem}:{})});return true;
  }finally{if(picked)pickupClaims.delete(picked);}
}

async function commitPartyDil(world,p,shares){
 const members=shares.map(s=>s.player),locked=[...new Set([p,...members])];
 if(locked.some(q=>q.sceneTransition||q.tradeCommitting||q.progressCommitting))throw Object.assign(Error('Wait until party inventory changes finish.'),{status:409});
 if(!world.saveProfiles)throw Object.assign(Error('Atomic party currency storage is unavailable.'),{status:503});
 const flags=locked.map(q=>q.sceneTransition);locked.forEach(q=>q.sceneTransition=true);
 const queue=world.saveQueue||Promise.resolve();
 const task=queue.catch(()=>{}).then(async()=>{
  const before=members.map(q=>structuredClone(q.profile)),revisions=members.map(q=>q.revision??0);
  const candidates=shares.map(({player,dil},i)=>{const profile=structuredClone(player.profile),inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});inv.addDil(dil);return {...player,profile};});
  const updates=candidates.map(q=>({accountId:q.account,characterId:q.characterId,profile:world.canonical?world.canonical(q):q.profile}));
  if(await world.saveProfiles(updates)===false)throw Object.assign(Error('Party currency could not be saved.'),{status:503});
  members.forEach((q,i)=>{
   const staged=candidates[i],gain=staged.profile.dil-before[i].dil,intervening=(q.revision??0)-revisions[i];
   // Only this pickup owns the currency increment; retain any later trusted recipient reward.
   const inv=new AuthoritativeInventory(q.profile,world.data.itemDB,{now:world.now,random:world.random});inv.addDil(gain);
   world.changed(q);q.dirty=intervening!==0;q.saveError=null;
   if(gain>0&&q!==p)world.emit(q.map,{type:'loot',actorId:q.id,dil:gain,recipients:[q.id]});
  });
 });world.saveQueue=task.catch(()=>{});
 try{await task;await persistInterveningProgress(world,members);}finally{locked.forEach((q,i)=>q.sceneTransition=flags[i]);}
}
