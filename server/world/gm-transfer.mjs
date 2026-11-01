import {publishProfileChanges,persistInterveningProgress} from './profile-publication.mjs';
import {ownedItems} from './item-ownership.mjs';
import {randomUUID} from 'node:crypto';
import {characterRef} from '../accounts/character-ref.mjs';
import {gmInventoryRevision,gmTransferIdentity} from '../accounts/gm-transfers.mjs';
import {Container} from '../../src/systems/items/model.js';
const fail=(status,message)=>{throw Object.assign(new Error(message),{status});};
export function validateGMTransfer(input){
  if(Object.keys(input).some(k=>!['token','operation','ref','container','uid','count','revision','destinationRevision','requestId','reason'].includes(k))||input.operation!=='takeInventoryItem'||typeof input.ref!=='string'||!/^[a-f0-9]{64}$/.test(input.ref)||!['inventory','storage'].includes(input.container)||typeof input.uid!=='string'||input.uid.length<1||input.uid.length>160||!Number.isSafeInteger(input.count)||input.count<1||input.count>100000||![input.revision,input.destinationRevision].every(x=>typeof x==='string'&&/^[a-f0-9]{64}$/.test(x))||typeof input.requestId!=='string'||!/^[a-zA-Z0-9_-]{16,100}$/.test(input.requestId)||typeof input.reason!=='string'||!input.reason.trim()||input.reason.length>160)fail(400,'Send a current item UID, quantity, inventory revisions and transfer ID.');
}
export async function gmTransferAccounts(world,user,input){
  if(!user.capabilities?.includes('gm:commands'))fail(403,'GM permission is required to transfer items.');validateGMTransfer(input);
  if(!world.describeGMCharacter||!world.commitGMTransfer||!world.readGMTransfer)fail(503,'Atomic GM transfer storage is unavailable.');
  const source=await world.describeGMCharacter(input.ref);if(!source)fail(404,'The source character is unavailable.');
  return [user.id,source.accountId];
}
const liveRevision=p=>gmInventoryRevision(p.profile,p.token);
const owned=ownedItems;
function grid(profile,db,kind){profile[kind]||=[];return new Container(profile[kind],db,{pages:kind==='storage'?4:7,cols:10,rows:kind==='storage'?10:5,unlocked:()=>kind==='storage'?profile.stashUnlocked||2:profile.bagsUnlocked||2});}
function gridValid(container){const uids=new Set();for(const it of container.list){const [w,h]=container.size(it),def=container.db.def(it.itemIndex),count=it.count??1;if(!def||typeof it.uid!=='string'||!it.uid||uids.has(it.uid)||!Number.isSafeInteger(count)||count<1||count>container.db.stackSize(def)||![it.page,it.x,it.y].every(Number.isInteger)||it.page<0||it.page>=container.unlocked||!container.inside(it.x,it.y,w,h)||container.occupants(it.page,it.x,it.y,w,h,it).length)fail(409,'The saved item grid needs repair before a transfer.');uids.add(it.uid);}}
export async function takeInventoryItem(world,user,input,{req}={}){
  await gmTransferAccounts(world,user,input);
  const operator=world.lease(user.id,input.token),operatorRef=characterRef(operator.account,operator.characterId),identity=gmTransferIdentity(operatorRef,input);
  if(world.now()-(operator.gmRateAt||0)>=1000){operator.gmRateAt=world.now();operator.gmActions=0;}if((operator.gmActions=(operator.gmActions||0)+1)>20)fail(429,'Too many GM commands.');
  const previous=await world.readGMTransfer(identity.key);
  if(previous){if(previous.digest!==identity.digest)fail(409,'This transfer ID was already used for different input.');return {ok:true,replayed:true,transfer:previous.receipt,state:world.snapshot(operator)};}
  const sourceRecord=await world.describeGMCharacter(input.ref),destinationRecord=await world.describeGMCharacter(operatorRef);
  if(!sourceRecord||!destinationRecord)fail(404,'A transfer character is unavailable.');
  if(sourceRecord.accountId===operator.account)fail(400,'Choose a character on another account.');
  const accountActor=world.players.get(sourceRecord.accountId),source=accountActor?.characterId===sourceRecord.characterId?accountActor:null;
  const participants=[operator,...(source?[source]:[])];
  const validate=()=>{world.lease(user.id,input.token);for(const p of participants)if(world.players.get(p.account)!==p||p.leaving||p.revoked||p.dead||p.instanceId||p.tradeId||p.tradeCommitting||p.progressCommitting||(p.commandActive||0)>1)fail(409,'Wait for this character to finish its current transaction.');if(world.players.get(sourceRecord.accountId)!==accountActor)fail(409,'The source session changed. Refresh the inventory.');if(accountActor?.leaving||accountActor?.revoked)fail(409,'Wait for the source account to finish disconnecting.');};
  validate();if(participants.some(p=>p.sceneTransition))fail(409,'Wait for current travel or progress saves.');
  if((source?liveRevision(source):gmInventoryRevision(sourceRecord.profile))!==input.revision||liveRevision(operator)!==input.destinationRevision)fail(409,'An inventory changed. Refresh before transferring this item.');
  if(!world.data.itemDB)fail(503,'The original item catalog is unavailable.');
  const revisions=participants.map(p=>p.revision??0),barriers=participants.map(p=>p.sceneTransition);
  participants.forEach(p=>{p.sceneTransition=true;});
  const task=world.saveQueue.catch(()=>{}).then(async()=>{
    validate();
    // Drain older autosaves, then compare the store version used for this commit.
    const records=await Promise.all([world.describeGMCharacter(input.ref),world.describeGMCharacter(operatorRef)]);
    if(records.some(x=>!x))fail(404,'A transfer character is unavailable.');
    const sourceProfile=source?structuredClone(source.profile):structuredClone(records[0].profile),destinationProfile=structuredClone(operator.profile);
    if((source?liveRevision(source):gmInventoryRevision(sourceProfile))!==input.revision||liveRevision(operator)!==input.destinationRevision)fail(409,'An inventory changed. Refresh before transferring this item.');
    const beforeProfiles=[structuredClone(sourceProfile),structuredClone(destinationProfile)];
    const bag=grid(sourceProfile,world.data.itemDB,input.container),destination=grid(destinationProfile,world.data.itemDB,'inventory');gridValid(bag);gridValid(destination);
    const item=bag.byUid(input.uid),def=item&&world.data.itemDB.def(item.itemIndex);
    if(!def||owned(sourceProfile).filter(i=>i.uid===input.uid).length!==1||owned(destinationProfile).some(i=>i.uid===input.uid))fail(409,'This item UID is unavailable or duplicated.');
    if(item.bound||Number(def.trade)===0||item.expiresAt&&item.expiresAt<=world.now()||item.pet?.active||item.pet?.inv?.length)fail(400,'Bound, untradeable, expired or occupied pet items cannot be transferred.');
    const available=item.count??1;if(input.count>available)fail(409,'The selected item quantity changed or exceeds its original stack limit.');
    const beforeCount=bag.count(item.itemIndex)+destination.count(item.itemIndex);
    const partial=input.count<available,removed=bag.take(item,input.count);if(partial)removed.uid=`gm-${randomUUID()}`;for(const key of ['page','x','y'])delete removed[key];
    // Preserve every instance modifier and whole-item UID; avoid merging metadata.
    const receivedUid=removed.uid;if(!destination.add(removed,{noStack:true}).ok)fail(409,'The GM inventory has insufficient room.');
    if(bag.count(item.itemIndex)+destination.count(item.itemIndex)!==beforeCount)fail(409,'The transfer quantity could not be conserved.');
    if(owned(destinationProfile).filter(i=>i.uid===receivedUid).length!==1)fail(409,'Invalid destination item UID.');
    const profiles=[sourceProfile,destinationProfile],actors=[source,operator];
    const updates=profiles.map((profile,i)=>({ref:i===0?input.ref:operatorRef,expectedRevision:records[i].revision,profile:actors[i]?world.canonical({...actors[i],profile}):profile}));
    // Offline inventory moves never replace account-wide shared features.
    if(!source)delete updates[0].profile.accountFeatures;
    const result=await world.commitGMTransfer(req,{operatorRef,...identity,updates,audit:{requestId:input.requestId,source:input.ref,container:input.container,uid:input.uid,receivedUid,itemIndex:item.itemIndex,count:input.count,reason:input.reason.trim(),sourceOnline:!!source,beforeRevision:input.revision,destinationBeforeRevision:input.destinationRevision},guard:()=>{validate();if(source&&liveRevision(source)!==input.revision||liveRevision(operator)!==input.destinationRevision)fail(409,'An inventory changed before commit.');}});
    if(!result?.receipt||typeof result.replayed!=='boolean')fail(503,'Atomic GM transfer storage did not confirm a durable receipt.');
    if(!result.replayed){participants.forEach((p,i)=>{const profileIndex=p===operator?1:0;publishProfileChanges(p.profile,beforeProfiles[profileIndex],profiles[profileIndex]);const intervening=(p.revision??0)-revisions[i];world.changed(p);p.dirty=intervening!==0;p.saveError=null;});}
    return {ok:true,replayed:result.replayed,transfer:result.receipt,message:`Transferred ${input.count} item(s) to your inventory.`,state:world.snapshot(operator)};
  });world.saveQueue=task.catch(()=>{});
  try{const result=await task;if(!result.replayed){result.progressPending=await persistInterveningProgress(world,participants);result.state=world.snapshot(operator);if(result.progressPending)result.message+=' Newer character progress is retained and awaiting a save retry.';}return result;}finally{participants.forEach((p,i)=>{p.sceneTransition=barriers[i];});}
}
