// CHAR-TRADE (chartradewnd): the requester gives one of their account's other characters to a nearby player, who may
// pay with items and DIL. Flow (ENGINE-CHOSEN, see src/config/engine-chosen-char-trade.js):
//   request -> invited (target sees chartradeinvite_msgbox) -> accept -> open (seller chooses, buyer offers payment)
//   -> both confirm -> locked (556:39 safety time) -> both approve -> one account-store transaction moves the
//   character record and writes both payment profiles.
import {publishProfileChanges,refreshConcurrentBuffStats,persistInterveningProgress} from './profile-publication.mjs';
import {randomUUID} from 'node:crypto';
import {sameScene} from './scene.mjs';
import {AuthoritativeInventory} from './inventory.mjs';
import {Container} from '../../src/systems/items/model.js';
import {cursorTradeSaving} from './cursor-trade.mjs';
import {CHAR_TRADE_ENGINE_CHOSEN as C} from '../../src/config/engine-chosen-char-trade.js';

export const CHAR_TRADE_SCHEMAS={chartrade:['token','type','operation','targetId','id','revision','characterId','items','dil']};
// Refusals carry the original string id (stringtable_chartrade 556:n) so the client shows the shipped text.
const fail=(msg,text,status=400)=>{throw Object.assign(new Error(`[556:${msg}] ${text}`),{status,charTradeMsg:msg});};
const sessions=world=>world.charTrades||=new Map();
function live(world,p){return world.players.get(p.account)===p&&!p.leaving&&!p.dead&&(!p.sceneTransition||cursorTradeSaving(p));}
function near(a,b){return sameScene(a,b)&&Math.hypot(a.x-b.x,a.z-b.z)<=C.range;}
function valid(world,t){return t.players.every(p=>live(world,p))&&near(...t.players);}
function current(world,p){return sessions(world).get(p.charTradeId)||null;}
function notify(world,t,reason,msg=null,recipients=t.players){world.emit(t.players[0].map,{type:'chartrade',id:t.id,reason,msg,recipients:recipients.map(p=>p.id)});}
export function cancelCharTrade(world,p,reason='cancelled',msg=C.msg.cancelled){
  const t=current(world,p);if(!t||t.committing)return;
  sessions(world).delete(t.id);for(const q of t.players)if(q.charTradeId===t.id)q.charTradeId=null;notify(world,t,reason,msg);
}
export function tickCharTrades(world){
  for(const t of sessions(world).values()){
    if(t.committing)continue;
    if(!valid(world,t)||world.now()>=t.expiresAt){cancelCharTrade(world,t.players[0],'expired or interrupted');continue;}
    if(t.phase==='locked'&&!t.unlocked&&world.now()>=t.lockUntil){t.unlocked=true;notify(world,t,'approve');}
  }
}
/** Used by HTTP's account command scheduler to lock both participants. */
export function charTradeAccounts(world,p,input){
  const target=input.operation==='request'?[...world.players.values()].find(q=>q.id===input.targetId):null;
  return [...new Set([p.account,...(current(world,p)?.players||[]).map(q=>q.account),...(target?[target.account]:[])])].sort();
}
const role=(t,p)=>t.players[0]===p?'seller':'buyer';
const pub=c=>c&&{id:c.id,name:c.name,level:c.level,classIndex:c.classIndex,className:c.className,restricted:!!c.restricted,detail:structuredClone(c.detail)};
export function charTradeSnapshot(world,p){
  const t=current(world,p);if(!t||!valid(world,t)||world.now()>=t.expiresAt)return null;
  const [seller,buyer]=t.players,other=t.players.find(q=>q!==p),flags=set=>({seller:set.has(seller.id),buyer:set.has(buyer.id)});
  return {id:t.id,revision:t.revision,phase:t.phase,role:role(t,p),expiresAt:t.expiresAt,lockUntil:t.lockUntil||0,unlocked:!!t.unlocked,
    incoming:t.phase==='invited'&&buyer===p,partner:{id:other.id,name:other.profile.name},seller:{id:seller.id,name:seller.profile.name},buyer:{id:buyer.id,name:buyer.profile.name},
    characters:role(t,p)==='seller'?(t.candidates||[]).map(pub):null,character:pub(t.character),
    payment:{dil:t.payment.dil,items:structuredClone(t.payment.items)},confirmed:flags(t.confirmed),approved:flags(t.approved)};
}
function blocked(world,p,self){
  if(p.instanceId&&C.noTradeInInstances)return C.msg.map;
  if(p.tradeId||current(world,p))return self?C.msg.trading:C.msg.otherBusy;
  if(p.pcShopOpen||p.tradeCommitting||p.dead)return self?C.msg.busy:C.msg.otherBusy;
  return 0;
}
function payment(world,p,input){
  if(!Array.isArray(input.items)||input.items.length>50||!Number.isSafeInteger(input.dil)||input.dil<0||input.dil>C.maxPaymentDil)fail(C.msg.failed,'Choose up to fifty owned items and a valid DIL amount.');
  if(input.dil>(p.profile.dil||0))fail(C.msg.failed,'Insufficient DIL for this payment.');
  const seen=new Set(),items=[],fingerprints=new Map(),container=new Container([],world.data.itemDB,{pages:1,...C.paymentGrid});
  for(const row of input.items){
    if(!row||typeof row!=='object'||Array.isArray(row)||Object.keys(row).some(k=>!['uid','count'].includes(k))||typeof row.uid!=='string'||seen.has(row.uid)||!Number.isInteger(row.count)||row.count<1)fail(C.msg.failed,'Send each item UID and quantity once.');
    seen.add(row.uid);const item=p.profile.inventory?.find(i=>i.uid===row.uid),def=item&&world.data.itemDB.def(item.itemIndex);
    if(!def||item.bound||Number(def.trade)===0||item.expiresAt&&item.expiresAt<=world.now()||item.pet?.active||item.pet?.inv?.length)fail(C.msg.failed,'That item cannot be traded.');
    if(row.count>(item.count||1))fail(C.msg.failed,'That item quantity is unavailable.');
    const entry=structuredClone(item);entry.count=row.count;delete entry.page;delete entry.x;delete entry.y;
    if(!container.add(entry,{noStack:true}).ok)fail(C.msg.failed,'The payment exceeds the trade grid.');
    items.push(entry);fingerprints.set(item.uid,JSON.stringify(item));
  }
  return {dil:input.dil,items,fingerprints};
}
// Buyer pays the seller; profiles are copies until the store commits.
function paid(world,t){
  const [seller,buyer]=t.players,profiles=[structuredClone(seller.profile),structuredClone(buyer.profile)];
  const bags=profiles.map(profile=>new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random}).bag),taken=[];
  if(t.payment.dil>(profiles[1].dil||0))fail(C.msg.wait,'The offered DIL is no longer available.');
  for(const offered of t.payment.items){
    const item=bags[1].byUid(offered.uid);
    if(!item||JSON.stringify(item)!==t.payment.fingerprints.get(offered.uid)||item.expiresAt&&item.expiresAt<=world.now())fail(C.msg.wait,'An offered item changed.');
    const removed=bags[1].take(item,offered.count);for(const key of ['page','x','y'])delete removed[key];taken.push(removed);
  }
  const dil=(profiles[0].dil||0)+t.payment.dil;
  if(!Number.isSafeInteger(dil)||dil>C.maxPaymentDil)fail(C.msg.inventoryFull,'The seller DIL balance would exceed its limit.');
  profiles[0].dil=dil;profiles[1].dil=(profiles[1].dil||0)-t.payment.dil;
  for(const item of taken)if(!bags[0].add(item).ok)fail(C.msg.inventoryFull,'The seller inventory has insufficient room.');
  return profiles;
}
const changed=t=>{t.confirmed.clear();t.approved.clear();t.revision++;};
export async function charTradeCommand(world,p,input){
  if(input.operation!=='cancel'&&current(world,p)?.players.some(q=>cursorTradeSaving(q)))fail(C.msg.locked,'Wait for the held item save before changing or confirming the transfer.',409);
  tickCharTrades(world);
  const allowed={request:['targetId'],accept:['id','revision'],decline:['id'],choose:['id','revision','characterId'],offer:['id','revision','items','dil'],confirm:['id','revision'],approve:['id','revision'],cancel:['id']};
  if(!Object.hasOwn(allowed,input.operation)||Object.keys(input).some(k=>!['token','type','operation',...allowed[input.operation]].includes(k)))fail(C.msg.failed,'Invalid character transfer operation.');
  if(!world.data.itemDB)fail(C.msg.failed,'Character transfer requires the original item catalog.');
  if(input.operation==='request'){
    const target=[...world.players.values()].find(q=>q.id===input.targetId);
    if(target===p)fail(C.msg.self,'You cannot transfer the character to yourself.');
    const mine=blocked(world,p,true);if(mine)fail(mine,'You cannot request a character transfer now.');
    if(!target||!live(world,target)||!live(world,p)||!near(p,target))fail(C.msg.notFound,'Choose a nearby connected player.');
    const theirs=blocked(world,target,false);if(theirs)fail(theirs===C.msg.map?C.msg.map:C.msg.otherBusy,'The other player is busy.');
    if(target.account===p.account)fail(C.msg.self,'You cannot transfer the character to yourself.');
    if(!world.charTransferInfo||!world.transferCharacter)fail(C.msg.failed,'Character transfer storage is unavailable.',503);
    const t={id:randomUUID(),players:[p,target],phase:'invited',revision:1,expiresAt:world.now()+C.inviteMs,confirmed:new Set(),approved:new Set(),payment:{dil:0,items:[],fingerprints:new Map()},candidates:[],character:null};
    sessions(world).set(t.id,t);p.charTradeId=target.charTradeId=t.id;notify(world,t,'invited',C.msg.wants);return {phase:'invited'};
  }
  const t=current(world,p);
  if(!t||t.id!==input.id||!valid(world,t)||t.committing)fail(C.msg.cancelled,'That character transfer is no longer available.');
  if(input.operation==='cancel'||input.operation==='decline'){cancelCharTrade(world,p,input.operation==='decline'?'declined':'cancelled');return {phase:'closed'};}
  if(input.revision!==t.revision)fail(C.msg.wait,'The conditions changed. Review them again.');
  const [seller,buyer]=t.players;
  if(input.operation==='accept'){
    if(t.phase!=='invited'||buyer!==p)fail(C.msg.failed,'Only the invited player can accept this transfer.');
    const info=await world.charTransferInfo(seller.account,seller.characterId);
    if(!info?.characters?.length){cancelCharTrade(world,p,'no character',C.msg.noCharacter);return {phase:'closed',msg:C.msg.noCharacter};}
    t.candidates=info.characters;t.phase='open';t.revision++;t.expiresAt=world.now()+C.sessionMs;for(const q of t.players)q.path=[];notify(world,t,'opened');return {phase:'open'};
  }
  if(t.phase==='invited')fail(C.msg.failed,'Wait for the invited player to accept.');
  if(input.operation==='choose'||input.operation==='offer'){
    if(t.phase!=='open')fail(C.msg.locked,'The safety system has started; conditions cannot change.');
    if(input.operation==='choose'){
      if(seller!==p)fail(C.msg.failed,'Only the giving player chooses the character.');
      const info=await world.charTransferInfo(seller.account,seller.characterId);t.candidates=info?.characters||[];
      const c=t.candidates.find(row=>row.id===input.characterId);
      if(!c)fail(C.msg.noCharacter,'No tradeable character.');
      if(c.restricted)fail(C.msg.restricted,'This character is restricted from transfer.');
      t.character=c;
    }else{
      if(buyer!==p)fail(C.msg.failed,'Only the receiving player offers payment.');
      t.payment=payment(world,p,input);
    }
    changed(t);t.expiresAt=world.now()+C.sessionMs;notify(world,t,'conditions changed');return {phase:t.phase};
  }
  if(input.operation==='confirm'){
    if(t.phase!=='open')fail(C.msg.locked,'The safety system has already started.');
    if(!t.character)fail(C.msg.confirmFirst,'Choose the character before confirming.');
    if(p===buyer){const info=await world.charTransferInfo(buyer.account,null);if((info?.count||0)>=C.receiverMaxCharacters)fail(C.msg.slotsFull,'No empty character slot.');}
    paid(world,t);t.confirmed.add(p.id);
    if(t.confirmed.size===2){t.phase='locked';t.lockUntil=world.now()+C.safetyMs;t.unlocked=false;t.revision++;notify(world,t,'locked',C.msg.locked);}
    else notify(world,t,'confirmed');
    return {phase:t.phase};
  }
  // approve
  if(t.phase!=='locked')fail(C.msg.confirmFirst,'Both players confirm the conditions first.');
  if(world.now()<t.lockUntil)fail(C.msg.wait,'Wait for the safety time to finish.');
  paid(world,t);t.approved.add(p.id);
  if(t.approved.size!==2){notify(world,t,'approved');return {phase:t.phase};}
  t.committing=true;for(const q of t.players)q.tradeCommitting=true;
  let moved=null;
  const task=world.saveQueue.catch(()=>{}).then(async()=>{
    if(!valid(world,t))fail(C.msg.failed,'A participant disconnected or moved.');
    const beforeProfiles=t.players.map(q=>structuredClone(q.profile)),revisions=t.players.map(q=>q.revision??0);
    const profiles=paid(world,t),updates=t.players.map((q,i)=>({accountId:q.account,characterId:q.characterId,profile:world.canonical({...q,profile:profiles[i]})}));
    const info=await world.charTransferInfo(seller.account,seller.characterId),now=info?.characters?.find(c=>c.id===t.character.id);
    if(!now)fail(C.msg.notFound,'The character is no longer on the account.');
    if(JSON.stringify(now)!==JSON.stringify(t.character))fail(C.msg.wait,'The character changed during the transfer.');
    moved=await world.transferCharacter({fromAccount:seller.account,toAccount:buyer.account,characterId:t.character.id,updates});
    if(!moved)fail(C.msg.failed,'The character transfer could not be saved.',503);
    t.players.forEach((q,i)=>{const intervening=(q.revision??0)-revisions[i];publishProfileChanges(q.profile,beforeProfiles[i],profiles[i]);refreshConcurrentBuffStats(world,q,beforeProfiles[i]);world.changed(q);q.dirty=intervening!==0;q.saveError=null;});
    t.committing=false;sessions(world).delete(t.id);for(const q of t.players)if(q.charTradeId===t.id)q.charTradeId=null;
    notify(world,t,'completed',C.msg.done,[seller]);notify(world,t,'completed',C.msg.received,[buyer]);
  });world.saveQueue=task.catch(()=>{});
  try{await task;await persistInterveningProgress(world,t.players);}
  catch(error){t.approved.clear();t.confirmed.clear();t.phase='open';t.revision++;notify(world,t,'save failed; review again',error.charTradeMsg??C.msg.failed);
    if(error.charTradeMsg!==undefined){if(!/^\[556:/.test(error.message))error.message=`[556:${error.charTradeMsg}] ${error.message}`;error.status||=400;}throw error;}
  finally{t.committing=false;for(const q of t.players)q.tradeCommitting=false;}
  return {phase:'completed',character:{id:moved.id,name:moved.name},msg:p===seller?C.msg.done:C.msg.received};
}
