import {beltEligible} from '../../src/systems/items/belt.js';
import {commitLife,serializeLife} from './life-transactions.mjs';
import {mapFor,sameScene} from './scene.mjs';
import fs from 'node:fs/promises';
import path from 'node:path';
import { Equipment, emptyEquip, PRESETS, S, pairedPreset, clonePresetTo } from '../../src/systems/items/equip.js';
import { computeItemStats, applyPost } from '../../src/systems/items/stats.js';
import { ItemUse } from '../../src/systems/items/use.js';
import { Container, canStack } from '../../src/systems/items/model.js';
import { deriveStats } from '../../src/game/progression.js';
import { foldSharedStatusStats } from '../../src/game/shared-status-stats.js';
import { decodeText, parseCSV } from '../../src/formats/binreader.js';
import { parseStringTableCates } from '../../src/ui/uiwin/strings.js';
import { AuthoritativeInventory } from './inventory.mjs';
import {boundReturnTarget,canReturnScroll,commitFieldTravel} from './travel.mjs';
import {createPersonalPortal} from './personal-portal.mjs';
import {partyPvpItemGuard} from './party-pvp.mjs';
import {progressDekaPass} from './dekapass.mjs';
import {isPremiumItem,checkPremiumItem,startPremium,premiumRemoteStorage} from './premium-service.mjs';
import {nearbyNpc} from './npc-services.mjs';
import {itemCooldownEntries,acceptedItemCooldowns} from './item-cooldowns.mjs';
import {assertNieteService} from './niete-services.mjs';
import {isAncientStone,ancientStoneUse} from './dead-island-run.mjs';
import {applyCursorOperation} from '../../src/systems/items/cursor-custody.js';
import {cursorTradeTransaction,guardCursorTrade} from './cursor-trade.mjs';
import {grantGroundItem} from './loot.mjs';

export const ITEM_ACTION_SCHEMAS = {
  cursor:['token','type','operation','revision','uid','container','page','x','y','slot','preset','targetUid','parentUid'],
  itemuse:['token','type','uid'], beltmove:['token','type','uid','direction','slot','page','x','y'], equip:['token','type','uid','slot','preset'],
  unequip:['token','type','slot','preset','page','x','y'], preset:['token','type','preset'],
  weapontab:['token','type'], itemmove:['token','type','uid','page','x','y'],
  storage:['token','type','uid','direction','page','x','y','shared'],stashmove:['token','type','uid','page','x','y','shared'],
  split:['token','type','uid','count','page','x','y'],sortitems:['token','type','container','page'],bank:['token','type','direction','amount','shared'],
  equipswap:['token','type','slot','targetSlot','preset'],clonepreset:['token','type','slot','preset','targets'],
};
const fail=message=>{throw Object.assign(new Error(message),{status:400});};
const ITEM_USE_FALLBACKS={
  50:'You cannot use this item in this location.',51:'This item cannot be used now.',
  53:'This item is cooling down. Try again shortly.',54:'Dead characters cannot use items.',
  56:'You do not meet this item’s level or class requirements.',59:'This item’s benefit is already active or fully unlocked.',
  94:'You cannot use a Return Scroll on this map.',99:'This item’s effect is unavailable.',
};
function itemUseMessage(messages,cate,code){
  const original=messages?.get?.(`${cate}:${code}`);
  return String(original||'').replace(/<[^>]+>/g,'').trim()||(Number(cate)===40&&ITEM_USE_FALLBACKS[code])||'This item cannot be used now.';
}
// LANE-22: both off-hand slots of one preset must stay a native pairing with that preset's own main weapon
// (Equipment.check combination/class/level rules; stats=null, never a new requirement).
function whole(value,min,max){if(!Number.isInteger(value)||value<min||value>max)fail('Invalid inventory position or equipment preset.');return value;}
function destination(input,container){
  if(input.page==null&&input.x==null&&input.y==null)return null;
  return {page:whole(input.page,0,container.unlocked-1),x:whole(input.x,0,container.cols-1),y:whole(input.y,0,container.rows-1)};
}
function placeRequested(container,item,at){
  if(!at)return container.add(item).ok;
  const placed=container.placeAt(item,at.page,at.x,at.y);
  return placed==='moved'||placed==='merged';
}
export async function loadWorldItemData(gamedataRoot,dataRoot) {
  const [tables,statuses]=await Promise.all(['items-tables.json','skills_status.json'].map(name=>fs.readFile(path.join(gamedataRoot,name),'utf8').then(JSON.parse)));
  const locations=new Map(),messages=new Map();
  if(dataRoot){
    const [locationBytes,messageBytes]=await Promise.all([fs.readFile(path.join(dataRoot,'share/arrange/location.csv')),fs.readFile(path.join(dataRoot,'script/string/normal/stringtable_pc.txt')).catch(error=>{if(error.code==='ENOENT')return null;throw error;})]);
    const rows=parseCSV(decodeText(locationBytes));for(const row of rows.slice(1)){const id=Number(row[0]);if(Number.isFinite(id))locations.set(id,{map:Number(row[2]),x:Number(row[3])+0.5,z:Number(row[4])+0.5,dirDeg:Number(row[5])*360/256});}
    // One original table, retaining only the eight ItemUse rejection codes; no group-wide preload.
    if(messageBytes)for(const [key,text]of parseStringTableCates(decodeText(messageBytes)))if(key.startsWith('40:')&&Object.hasOwn(ITEM_USE_FALLBACKS,key.slice(3)))messages.set(key,text);
  }
  return {tables,statuses:statuses.statuses||{},locations,messages};
}
export function deriveEquipment(profile,db,classDef,progressionData,now=Date.now(),mounts=null,passivePools=null) {
  profile.equip||=emptyEquip();
  for(const [uid,item]of Object.entries(profile.equip.items)){if(item.expiresAt&&item.expiresAt<=now){delete profile.equip.items[uid];for(const preset of profile.equip.presets)for(const [slot,id]of Object.entries(preset))if(id===uid)delete preset[slot];}}
  profile.buffs=(profile.buffs||[]).filter(buff=>!buff.expiresAt||buff.expiresAt>now);
  const sys={db,game:{save:profile,data:progressionData,settings:{},mounts:mounts||{isMounted:()=>false,extraOptions:()=>[]}}};sys.equip=new Equipment(sys);
  const itemStats=computeItemStats(sys);profile.equipment=sys.equip.view(itemStats);
  const buffs=[...(profile.buffs||[]),...itemStats.statuses];
  const stats=applyPost(deriveStats(profile,classDef,progressionData,buffs),itemStats);
  // Preserve deriveStats' captured shield inputs on the original stats object.
  return Object.assign(stats,foldSharedStatusStats(stats,profile.buffs,passivePools?.(profile,sys.equip.style())||[]));
}
function context(world,p) {
  const profile=structuredClone(p.profile),beforeProfile=structuredClone(profile),db=world.data.itemDB;
  const inventory=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random});
  const player={...p,stats:{...p.stats},maxMp:p.stats.maxMp||0,maxShield:p.stats.maxShield||0}, game={save:profile,player,now:world.now,time:world.now()/1000,classDef:world.data.classDef(profile.classIndex),settings:{},events:{emit(){}},world:{info:{index:p.map,row:mapFor(world,p)?.row}},data:world.data.progressionData};
  let travel=null;
  const sys={db,game,bag:inventory.bag,consume:(inst,n)=>{if(!inventory.consumeEntry(inst,n))fail('This item is no longer available.');},changed(){},msg:(cate,code,text)=>{if(text)return;sys.error=itemUseMessage(world.data.itemUseData?.messages,cate,code);},str:()=>'',account:()=>profile.accountFeatures||={},saveAccount(){}};
  sys.equip=new Equipment(sys);
  game.refreshPlayerStats=()=>{player.stats=world.data.stats(profile,p,world.now());player.maxHp=player.stats.maxHp;player.maxMp=player.stats.maxMp;player.hp=Math.min(player.hp,player.maxHp);player.mp=Math.min(player.mp,player.maxMp);};
  game.world.info.row={...game.world.info.row,ReturnScroll:canReturnScroll(world,p)?1:0};
  game.respawnTarget=()=>{const at=boundReturnTarget(world,profile);return at?{...at,mapIndex:at.map}:null;};
  game.mapRow=index=>({Index:index});game.travel=(map,target)=>{travel={map,...target};};
  game.hud={log(){}};
  return {profile,beforeProfile,inventory,sys,game,player,hpBefore:player.hp,mpBefore:player.mp,shieldBefore:player.shield,get travel(){return travel;}};
}
export function dispatchItemAction(world,p,input) {
  if(!Object.hasOwn(ITEM_ACTION_SCHEMAS,input.type))return Promise.resolve(false);
  return serializeLife(p,()=>input.type==='cursor'?cursorTradeTransaction(world,p,input,()=>applyItemAction(world,p,input)):applyItemAction(world,p,input));
}
async function applyItemAction(world,p,input) {
  if(p.dead)fail('You cannot use inventory while dead.');
  if(!world.data.itemDB)fail('The item catalog is unavailable.');
  const c=context(world,p),db=c.sys.db,preset=input.preset==null?(c.profile.equip?.active||0):whole(input.preset,0,PRESETS-1);
  let cooldowns,usedItemIndex=null,afterCommit=null;
  if(input.type==='cursor') {
    if(p.cursorVersion!==1)fail('Reconnect with the updated client to use item pickup.');
    if(input.operation==='discard'){
      if(Number(mapFor(world,p)?.row?.ItemDrop??1)===0)fail('This map does not allow ground drops.');
      const held=c.profile.itemCursor?.item,def=db.def(held?.itemIndex);
      if(held&&!held.bound&&Number(def?.trade)!==0){const dropped=structuredClone(held);afterCommit=()=>grantGroundItem(world,p,dropped);}
    }
    applyCursorOperation(c.profile,db,input,{stats:c.player.stats,now:world.now(),access:(name,operation,item,origin)=>{
      if(!['stash','shared'].includes(name))return;
      if(!nearbyNpc(world,p,{role:'STORAGE'})&&!premiumRemoteStorage(world,p.profile))fail('Walk near a storage NPC before using storage.');
      if(name==='shared'&&!c.profile.accountFeatures?.sharedStash)fail('Unlock account-shared storage first.');
      if(operation==='place'){
        if(name==='shared'&&origin?.container!=='shared'&&(item.bound||Number(db.def(item.itemIndex)?.trade)===0))fail('Bound or non-tradable items cannot enter account-shared storage.');
        if(name==='shared'&&origin?.container!=='shared'&&(item.pet?.active||item.pet?.inv?.length))fail('Dismiss the pet and empty its inventory first.');
        if(origin?.container!==name){const fee=Number(db.equipment.formula?.stStorageCostPerUnit)||10;if(c.inventory.dil<fee)fail('Not enough DIL for storage.');c.inventory.addDil(-fee);}
      }
    }});
  } else if(input.type==='itemuse') {
    const entries=[...c.inventory.bag.list,...c.inventory.belt.list].filter(item=>item.uid===input.uid);if(entries.length!==1)fail('That item is not owned once in your bag or potion belt.');const entry=entries[0];
    const def=db.def(entry.itemIndex);if(!def)fail('Unknown item.');
    // Dead Island Ancient Stones (code71): host run service; effect lands after the durable consumption.
    if(isAncientStone(entry.itemIndex)){afterCommit=ancientStoneUse(world,p,c,entry,def).apply;usedItemIndex=entry.itemIndex;}else{
    if(def.use?.teleport!=null||Number(def.type)===3&&Number(def.code)===4)assertNieteService(world,p);
    c.game.createPersonalPortal=def=>createPersonalPortal(world,p,c.profile,def);
    partyPvpItemGuard(world,p,def);   // PARTY-PVP 280:69
    const use=new ItemUse(c.sys);use.cooldowns=new Map(itemCooldownEntries(c.profile.itemCooldowns,c.game.time*1000));cooldowns=use.cooldowns;
    use.statuses=async()=>world.data.itemUseData?.statuses||{};use.locations=async()=>world.data.itemUseData?.locations||new Map();
    const apply=use.applyStatus.bind(use);use.applyStatus=async(...args)=>{const status=await apply(...args);if(status)status.expiresAt=world.now()+args[1];return status;};
    const table=world.data.itemUseData?.tables||{};db.T=table;db.tables=async()=>table;
    if(def.use?.itemStatus!=null){const effect=table.itemStatus?.[def.use.itemStatus];if(!effect||!world.data.itemUseData?.statuses?.[effect.statusIndex])fail('That item status is unavailable.');}
    // Book/box hooks are server services; their absence must never consume an item.
    c.game.skills=world.itemSkillFacade?.(p,c.profile)||null;
    c.game.boxes=world.itemBoxFacade?.(p,c.profile,c.inventory)||null;
    // Premium services (Growth Blessing / Almighty): the other kind cannot be running; the grouped server state replaces the generic record.
    const premium=def.use?.premiere!=null&&isPremiumItem(world,entry.itemIndex);
    if(premium)checkPremiumItem(world,c.profile,entry.itemIndex);
    if(!await use.use(entry))fail(c.sys.error||'This item cannot be used now.');
    if(premium)startPremium(world,c.profile,entry.itemIndex);
    c.profile.itemCooldowns=acceptedItemCooldowns(c.profile.itemCooldowns,cooldowns,Number(def.appraisal),c.game.time*1000);
    usedItemIndex=entry.itemIndex;}
  } else if(input.type==='beltmove') {
    const belt=c.inventory.belt,bag=c.inventory.bag;
    if(!['deposit','withdraw','move'].includes(input.direction))fail('Invalid potion belt transfer.');
    const from=input.direction==='deposit'?bag:belt,entry=from.byUid(input.uid);if(!entry)fail('That item is not in the source container.');
    if(input.direction==='move'){const slot=whole(input.slot,0,9);if(!belt.moveTo(entry,0,slot,0))fail('That potion belt slot is unavailable.');}
    else {const to=input.direction==='deposit'?belt:bag;
      if(input.direction==='deposit'&&(!beltEligible(db.def(entry.itemIndex))||entry.expiresAt&&entry.expiresAt<=world.now()))fail('Only available recovery potions and item-status buffs belong in the potion belt.');
      const def=db.def(entry.itemIndex);if(input.direction==='deposit'&&def.use?.itemStatus!=null){const status=world.data.itemUseData?.tables?.itemStatus?.[def.use.itemStatus];if(!status||!world.data.itemUseData?.statuses?.[status.statusIndex])fail('That item-status buff is unavailable.');}
      const at=input.direction==='deposit'?{page:0,x:whole(input.slot,0,9),y:0}:destination(input,bag);
      const displaced=input.direction==='deposit'?belt.list.find(item=>item.x===at.x):null;
      if(displaced&&!canStack(entry,displaced,db)){
        // Swap on this transaction's clone. The displaced stack must fit the
        // vacated bag footprint; never redirect it or publish half a transfer.
        const origin={page:entry.page,x:entry.x,y:entry.y};
        bag.take(entry);belt.take(displaced);
        if(!bag.fits(origin.page,origin.x,origin.y,...bag.size(displaced))||!placeRequested(belt,entry,at)||!placeRequested(bag,displaced,origin))fail('The destination is unavailable or cannot fit the whole stack.');
      }else{
      from.take(entry);delete entry.page;delete entry.x;delete entry.y;if(!placeRequested(to,entry,at))fail('The destination is unavailable or cannot fit the whole stack.');
      }
    }
  } else if(input.type==='equip') {
    const entry=c.inventory.bag.list.find(item=>item.uid===input.uid);if(!entry)fail('That item is not in your bag.');
    const slot=input.slot==null?c.sys.equip.autoSlot(db.def(entry.itemIndex),preset):whole(input.slot,0,114);
    const checked=c.sys.equip.check(entry,slot,c.player.stats,preset);if(!checked.ok)fail('This equipment does not meet the slot, class, level, or stat requirements.');
    c.inventory.bag.take(entry);delete entry.page;delete entry.x;delete entry.y;
    if(db.def(entry.itemIndex).belong===1)entry.bound=true;
    const result=c.sys.equip.place(entry,slot,preset);if(!result.ok)fail('This equipment slot is locked.');
    for(const old of result.displaced)if(!c.inventory.bag.add(old).ok)fail('Your inventory has no space for the replaced equipment.');
  } else if(input.type==='unequip') {
    const slot=whole(input.slot,0,114),held=c.sys.equip.get(slot,preset);if(!held)fail('This equipment slot is empty.');
    if(c.sys.equip.data.locked)fail('Equipment movement is locked.');
    const bag=c.inventory.bag,at=destination(input,bag),size=bag.size(held);
    const occupants=at?bag.occupants(at.page,at.x,at.y,...size):[];
    if(occupants.length){
      if(occupants.length!==1)fail('Choose a position overlapping only one inventory item.');
      const replacement=occupants[0];bag.take(replacement);
      // A bag destination is a bag swap, never an implicit equip request for
      // the item clicked there. Park the displaced UID safely; the client
      // continues holding it, regardless of its item type or requirements.
      const removed=c.sys.equip.remove(slot,preset);
      if(!removed?.inst)fail('This item is still registered in another equipment preset.');
      if(!placeRequested(bag,removed.inst,at)||!bag.add(replacement,{noStack:true}).ok)fail('The requested inventory position is unavailable.');
      for(const item of removed.extra)if(!bag.add(item,{noStack:true}).ok)fail('Your inventory is full.');
    }else{
      const removed=c.sys.equip.remove(slot,preset);
      if(removed.inst&&!placeRequested(bag,removed.inst,at))fail('The requested inventory position is unavailable.');
      for(const item of removed.extra)if(!bag.add(item).ok)fail('Your inventory is full.');
    }
  } else if(input.type==='equipswap') {
    const slot=whole(input.slot,0,114),targetSlot=whole(input.targetSlot,0,114),row=c.sys.equip.preset(preset),uid=row[slot],item=c.sys.equip.data.items[uid];
    if(!item||slot===targetSlot||!c.sys.equip.slotsFor(db.def(item.itemIndex)).includes(targetSlot))fail('Choose matching equipment slots.');
    const other=row[targetSlot];if(other&&!c.sys.equip.slotsFor(db.def(c.sys.equip.data.items[other].itemIndex)).includes(slot))fail('The other item cannot occupy that slot.');
    row[targetSlot]=uid;if(other)row[slot]=other;else delete row[slot];
    if(!pairedPreset(c.sys.equip,preset))fail('The off-hand cannot be worn with that weapon in this preset.');
  } else if(input.type==='clonepreset') {
    const slot=whole(input.slot,0,114),item=c.sys.equip.get(slot,preset);if(!item)fail('This equipment slot is empty.');let copied=false;
    // Global inven/ui_selectpresetequipwnd: the presets ticked in the box (only empty slots the preset can wear: 260:75 "Not allowed")
    if(input.targets!==undefined){
      if(!Array.isArray(input.targets)||!input.targets.length||input.targets.length>PRESETS-1)fail('Choose the presets to register the item in.');
      const targets=input.targets.map(t=>whole(t,0,PRESETS-1));
      if(!clonePresetTo(c.sys.equip,slot,preset,targets).length)fail('None of those presets can take that equipment.');
      copied=true;
    }
    let unpaired=false;
    for(let k=1;k<5&&!copied;k++){const t=(preset+k)%5,row=c.sys.equip.preset(t);if(row[slot])continue;row[slot]=item.uid;if(!pairedPreset(c.sys.equip,t)){delete row[slot];unpaired=true;continue;}copied=true;break;}
    if(!copied)fail(unpaired?'No other preset can wear that equipment with its current weapons.':'All matching preset slots are occupied.');
  } else if(input.type==='preset')c.sys.equip.data.active=whole(input.preset,0,PRESETS-1);
  else if(input.type==='weapontab')c.sys.equip.swapWeaponTab();
  else if(input.type==='split') {
    const entry=c.inventory.bag.list.find(item=>item.uid===input.uid);if(!entry)fail('That item is not in your bag.');
    whole(input.count,1,(entry.count||1)-1);whole(input.page,0,6);whole(input.x,0,9);whole(input.y,0,4);
    const [w,h]=c.inventory.bag.size(entry);if(!c.inventory.bag.fits(input.page,input.x,input.y,w,h))fail('The split position is occupied.');
    const part=c.inventory.bag.take(entry,input.count);Object.assign(part,{page:input.page,x:input.x,y:input.y});c.inventory.bag.list.push(part);
  } else if(input.type==='sortitems'&&input.container==='bag') {if(input.page!=null)whole(input.page,0,(c.profile.bagsUnlocked||2)-1);c.inventory.bag.sort(input.page??null);}
  else if(input.type==='itemmove') {
    const entry=c.inventory.bag.list.find(item=>item.uid===input.uid);if(!entry)fail('That item is not in your bag.');
    whole(input.page,0,6);whole(input.x,0,9);whole(input.y,0,4);
    if(!c.inventory.bag.moveTo(entry,input.page,input.x,input.y))fail('The requested inventory position is unavailable.');
  } else {
    if(input.type==='storage'&&!['deposit','withdraw'].includes(input.direction))fail('Choose deposit or withdraw.');
    if(input.shared!==undefined&&typeof input.shared!=='boolean')fail('Choose personal or account-shared storage.');
    // a nearby Storage NPC, or the Holy Water of Almighty "Remote storage" (server-owned premium state, premium-service.mjs)
    if(!nearbyNpc(world,p,{role:'STORAGE'})&&!premiumRemoteStorage(world,p.profile))fail('Walk near a storage NPC before using storage.');
    const shared=input.shared===true||input.type==='sortitems'&&input.container==='shared';
    if(shared&&!c.profile.accountFeatures?.sharedStash)fail('Unlock account-shared storage with a Storage Keeper\'s Key.');
    c.profile.storage||=[];
    if(shared){c.profile.accountFeatures.shared||=[];c.profile.accountFeatures.sharedDil||=0;}
    const stash=new Container(shared?c.profile.accountFeatures.shared:c.profile.storage,db,{pages:shared?1:4,cols:10,rows:10,unlocked:()=>shared?1:c.profile.stashUnlocked||2});
    if(input.type==='stashmove'){
      const at=destination(input,stash),entry=stash.list.find(item=>item.uid===input.uid);
      if(!at||!entry||!stash.moveTo(entry,at.page,at.x,at.y))fail('The requested storage position is unavailable.');
    } else if(input.type==='bank') {
      whole(input.amount,1,10000000000);if(!['deposit','withdraw'].includes(input.direction))fail('Invalid bank operation.');
      const bank=shared?c.profile.accountFeatures:c.profile,key=shared?'sharedDil':'stashDil',from=input.direction==='deposit'?c.profile:bank,to=input.direction==='deposit'?bank:c.profile,fromKey=input.direction==='deposit'?'dil':key,toKey=input.direction==='deposit'?key:'dil';
      if((from[fromKey]||0)<input.amount||(to[toKey]||0)+input.amount>10000000000)fail('Insufficient currency or full balance.');from[fromKey]=(from[fromKey]||0)-input.amount;to[toKey]=(to[toKey]||0)+input.amount;
    } else if(input.type==='sortitems') {if(!['stash','shared'].includes(input.container))fail('Unsupported container.');if(input.page!=null)whole(input.page,0,stash.unlocked-1);stash.sort(input.page??null);}
    else {
    const from=input.direction==='deposit'?c.inventory.bag:stash,to=input.direction==='deposit'?stash:c.inventory.bag,entry=from.list.find(item=>item.uid===input.uid);
    if(input.direction==='deposit'){const fee=Number(db.equipment.formula?.stStorageCostPerUnit)||10;if(c.inventory.dil<fee)fail('Not enough DIL for storage.');c.inventory.addDil(-fee);}
    if(!entry)fail('The requested item is not in that container.');
    if(shared&&input.direction==='deposit'&&(entry.bound||Number(db.def(entry.itemIndex)?.trade)===0))fail('Bound or non-tradable items cannot enter account-shared storage.');
    // A pet item carries its own inventory; every other owner-changing path (trade, mail, char trade, shops, GM transfer)
    // refuses it while occupied, so bound/non-tradable items cannot reach another character inside it.
    if(shared&&input.direction==='deposit'&&(entry.pet?.active||entry.pet?.inv?.length))fail('Dismiss the pet and empty its inventory first.');
    const at=destination(input,to);from.take(entry);if(!placeRequested(to,entry,at))fail('The requested destination is unavailable or full.');
    }
  }
  if(input.type==='cursor')guardCursorTrade(world,p,input,c.profile);
  const stats=world.data.stats(c.profile,p,world.now());
  if(c.travel){await commitFieldTravel(world,p,{...c.travel,map:c.travel.mapIndex??c.travel.map},c.profile);c.game.boxes?.publish?.();world.emit(p.map,{type:'inventory',actorId:p.id,reason:input.type});return true;}
  if(usedItemIndex!=null)progressDekaPass(world,{...p,profile:c.profile},5,22,usedItemIndex,1);
  const recovery=usedItemIndex!=null?{hp:Math.max(0,c.player.hp-c.hpBefore),mp:Math.max(0,(c.player.mp||0)-(c.mpBefore||0)),shield:Math.max(0,(c.player.shield||0)-(c.shieldBefore||0))}:{hp:0,mp:0,shield:0};
  await commitLife(world,p,c.profile,{stats,hp:Math.min(c.player.hp,stats.maxHp),mp:Math.min(c.player.mp,stats.maxMp||0),shield:Math.min(c.player.shield||0,stats.maxShield||0),vitalDeltas:recovery,profileBefore:c.beforeProfile});
  c.game.skills?.publish?.();
  c.game.boxes?.publish?.();
  afterCommit?.();
  if(cooldowns){p.itemCooldowns=[...cooldowns];p.itemCooldownState=structuredClone(c.profile.itemCooldowns);}
  world.emit(p.map,{type:'inventory',actorId:p.id,reason:input.type});
  if(usedItemIndex!=null)world.emit(p.map,{type:'itemuse',actorId:p.id,itemIndex:usedItemIndex,...(recovery.hp>0?{hp:Math.round(recovery.hp)}:{}),...(recovery.mp>0?{mp:Math.round(recovery.mp)}:{})});
  return true;
}
export function expireItemEffects(world,p) {
  const now=world.now();
  if(!(p.profile.buffs||[]).some(buff=>buff.expiresAt&&buff.expiresAt<=now)&&!Object.values(p.profile.equip?.items||{}).some(item=>item.expiresAt&&item.expiresAt<=now))return;
  p.stats=world.data.stats(p.profile,p,world.now());p.maxHp=p.stats.maxHp;p.hp=Math.min(p.hp,p.maxHp);p.mp=Math.min(p.mp,p.stats.maxMp||0);world.changed(p);
}
