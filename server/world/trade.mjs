import {publishProfileChanges,refreshConcurrentBuffStats,persistInterveningProgress} from './profile-publication.mjs';
import {randomUUID} from 'node:crypto';
import {sameScene} from './scene.mjs';
import {AuthoritativeInventory} from './inventory.mjs';
import {Container} from '../../src/systems/items/model.js';
import {cursorTradeSaving} from './cursor-trade.mjs';
import {canTradeOffer} from './item-flags.mjs';

export const TRADE_SCHEMAS={trade:['token','type','operation','targetId','id','revision','items','dil']};
const fail=(message,status=400)=>{throw Object.assign(new Error(message),{status});};
const MAX_DIL=10_000_000_000;
// ENGINE-CHOSEN: the supplied trade UI/messages require a review bar but supply no duration.
export const TRADE_REVIEW_MS=3000;
const sessions=world=>world.trades||=new Map();
function live(world,p){return world.players.get(p.account)===p&&!p.leaving&&!p.dead&&(!p.sceneTransition||cursorTradeSaving(p));}
function valid(world,trade){return trade.players.every(p=>live(world,p))&&sameScene(...trade.players)&&Math.hypot(trade.players[0].x-trade.players[1].x,trade.players[0].z-trade.players[1].z)<=12;}
function current(world,p){return sessions(world).get(p.tradeId)||null;}
// LANE-26: char-trade.mjs refuses while an item trade is open; the reverse must hold too, or a locked char-trade payment can be traded away.
const charTrading=(world,p)=>!!(p.charTradeId&&world.charTrades?.get(p.charTradeId));
function notify(world,trade,reason){world.emit(trade.players[0].map,{type:'trade',id:trade.id,reason,recipients:trade.players.map(p=>p.id)});}
export function cancelTrade(world,p,reason='cancelled'){
  const trade=current(world,p);if(!trade||trade.committing)return;
  sessions(world).delete(trade.id);for(const q of trade.players)if(q.tradeId===trade.id)q.tradeId=null;notify(world,trade,reason);
}
export function tickTrades(world){for(const trade of sessions(world).values()){
  if(trade.committing)continue;
  if(!valid(world,trade)||world.now()>=trade.expiresAt){cancelTrade(world,trade.players[0],'expired or interrupted');continue;}
  if(trade.phase==='review'&&world.now()>=trade.reviewReadyAt){trade.phase='ready';notify(world,trade,'ready for final confirmation');}
}}
/** Used by HTTP's existing account command scheduler to lock both participants. */
export function tradeAccounts(world,p,input){
  const target=input.operation==='request'?[...world.players.values()].find(q=>q.id===input.targetId):null;
  return [...new Set([p.account,...(current(world,p)?.players||[]).map(q=>q.account),...(target?[target.account]:[])])].sort();
}
export function tradeSnapshot(world,p){
  const trade=current(world,p);if(!trade||!valid(world,trade)||world.now()>=trade.expiresAt)return null;
  const other=trade.players.find(q=>q!==p),offer=q=>{
    const row=trade.offers.get(q.id);return {dil:row.dil,items:structuredClone(row.items),confirmed:trade.confirmed.has(q.id),finalConfirmed:trade.finalConfirmed.has(q.id)};
  };
  const phase=trade.phase==='review'&&world.now()>=trade.reviewReadyAt?'ready':trade.phase;
  return {id:trade.id,revision:trade.revision,phase,expiresAt:trade.expiresAt,reviewStartedAt:trade.reviewStartedAt,reviewReadyAt:trade.reviewReadyAt,incoming:trade.phase==='invited'&&trade.players[1]===p,partner:{id:other.id,name:other.profile.name},self:offer(p),other:offer(other)};
}
function resetConfirmation(trade){trade.phase='open';trade.confirmed.clear();trade.finalConfirmed.clear();trade.reviewStartedAt=null;trade.reviewReadyAt=null;}
function offer(world,p,input){
  if(!Array.isArray(input.items)||input.items.length>50||!Number.isSafeInteger(input.dil)||input.dil<0||input.dil>MAX_DIL)fail('Choose up to fifty owned items and a valid DIL amount.');
  if(input.dil>(p.profile.dil||0))fail('Insufficient DIL for this offer.');
  const seen=new Set(),items=[],fingerprints=new Map(),container=new Container([],world.data.itemDB,{pages:1,cols:10,rows:5});
  for(const row of input.items){
    if(!row||typeof row!=='object'||Array.isArray(row)||Object.keys(row).some(k=>!['uid','count'].includes(k))||typeof row.uid!=='string'||seen.has(row.uid)||!Number.isInteger(row.count)||row.count<1)fail('Send each item UID and quantity once.');
    seen.add(row.uid);const item=p.profile.inventory?.find(i=>i.uid===row.uid),def=item&&world.data.itemDB.def(item.itemIndex);
    if(!canTradeOffer(def,item,world.now()))fail('That item cannot be traded.');
    if(row.count>(item.count||1))fail('That item quantity is unavailable.');
    const entry=structuredClone(item);entry.count=row.count;delete entry.page;delete entry.x;delete entry.y;
    if(!container.add(entry,{noStack:true}).ok)fail('The offer exceeds the original trade grid.');
    items.push(entry);fingerprints.set(item.uid,JSON.stringify(item));
  }
  return {dil:input.dil,items,fingerprints};
}
function exchanged(world,trade){
  const profiles=trade.players.map(p=>structuredClone(p.profile)),bags=profiles.map(profile=>new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random}).bag),taken=[[],[]];
  for(const [i,p]of trade.players.entries()){
    const row=trade.offers.get(p.id);
    if(row.dil>(profiles[i].dil||0))fail('Offered DIL is no longer available.');
    for(const offered of row.items){
      const item=bags[i].byUid(offered.uid);
      if(!item||JSON.stringify(item)!==row.fingerprints.get(offered.uid)||item.expiresAt&&item.expiresAt<=world.now())fail('An offered item changed. Review a new offer.');
      const removed=bags[i].take(item,offered.count);for(const key of ['page','x','y'])delete removed[key];taken[i].push(removed);
    }
  }
  for(const [i,p]of trade.players.entries()){
    const mine=trade.offers.get(p.id),theirs=trade.offers.get(trade.players[1-i].id),dil=(profiles[i].dil||0)-mine.dil+theirs.dil;
    if(!Number.isSafeInteger(dil)||dil>MAX_DIL)fail('A recipient DIL balance would exceed its limit.');
    profiles[i].dil=dil;for(const item of taken[1-i])if(!bags[i].add(item).ok)fail('A recipient inventory has insufficient room.');
  }
  return profiles;
}
export async function tradeCommand(world,p,input){
  tickTrades(world);
  if(input.operation!=='cancel'&&current(world,p)?.players.some(q=>cursorTradeSaving(q)))fail('Wait for the held item save before changing or confirming the trade.',409);
  const allowed={request:['targetId'],accept:['id','revision'],offer:['id','revision','items','dil'],confirm:['id','revision'],finalConfirm:['id','revision'],cancel:['id']};
  if(!Object.hasOwn(allowed,input.operation)||Object.keys(input).some(k=>!['token','type','operation',...allowed[input.operation]].includes(k)))fail('Invalid trade operation.');
  if(!world.data.itemDB)fail('Trading requires the original item catalog.');
  if(input.operation==='request'){
    const target=[...world.players.values()].find(q=>q.id===input.targetId);
    if(!target||target===p||!live(world,p)||!live(world,target)||!sameScene(p,target)||Math.hypot(p.x-target.x,p.z-target.z)>12)fail('Choose a nearby connected player.');
    if(current(world,p)||current(world,target)||charTrading(world,p)||charTrading(world,target))fail('One of the players is already trading.');
    const trade={id:randomUUID(),players:[p,target],phase:'invited',revision:1,expiresAt:world.now()+60000,confirmed:new Set(),finalConfirmed:new Set(),reviewStartedAt:null,reviewReadyAt:null,offers:new Map([p,target].map(q=>[q.id,{items:[],dil:0,fingerprints:new Map()}]))};
    sessions(world).set(trade.id,trade);p.tradeId=target.tradeId=trade.id;notify(world,trade,'invited');return;
  }
  const trade=current(world,p);
  if(!trade||trade.id!==input.id||!valid(world,trade)||trade.committing)fail('That trade is no longer available.');
  if(input.operation==='cancel'){cancelTrade(world,p);return;}
  if(input.revision!==trade.revision)fail('The offer changed. Review the current trade before confirming.');
  if(input.operation==='accept'){
    if(trade.phase!=='invited'||trade.players[1]!==p)fail('Only the invited player can accept this trade.');
    trade.phase='open';trade.revision++;trade.expiresAt=world.now()+300000;for(const q of trade.players)q.path=[];notify(world,trade,'opened');return;
  }
  if(trade.phase==='invited')fail('Wait for the invited player to accept.');
  if(input.operation==='offer'){
    if(trade.phase!=='open')fail('The trade safety lock is active. Confirm the reviewed offer or cancel the trade.');
    const next=offer(world,p,input);trade.offers.set(p.id,next);resetConfirmation(trade);trade.revision++;trade.expiresAt=world.now()+300000;notify(world,trade,'offer changed');return;
  }
  // First confirmation locks the displayed offer. Neither first vote transfers ownership.
  if(input.operation==='confirm'){
    if(trade.phase!=='open')fail('The offer is locked for review. Use the final confirmation after the review bar fills.');
    exchanged(world,trade);trade.confirmed.add(p.id);
    if(trade.confirmed.size===2){trade.phase='review';trade.reviewStartedAt=world.now();trade.reviewReadyAt=trade.reviewStartedAt+TRADE_REVIEW_MS;}
    notify(world,trade,trade.phase==='review'?'review started':'confirmed');return;
  }
  // The server, rather than the client's gauge or repeat clicks, authorizes the final stage.
  if(trade.phase!=='ready'||trade.confirmed.size!==2||world.now()<trade.reviewReadyAt)fail('Confirm both offers and wait for the review bar to fill before the final confirmation.');
  exchanged(world,trade);trade.finalConfirmed.add(p.id);
  if(trade.finalConfirmed.size!==2){notify(world,trade,'final confirmed');return;}
  if(!world.saveProfiles){resetConfirmation(trade);trade.revision++;fail('Atomic trade storage is unavailable.',503);}
  trade.committing=true;for(const q of trade.players)q.tradeCommitting=true;
  const task=world.saveQueue.catch(()=>{}).then(async()=>{
    if(!valid(world,trade))fail('A trade participant disconnected or moved.');
    const beforeProfiles=trade.players.map(q=>structuredClone(q.profile)),revisions=trade.players.map(q=>q.revision??0);
    const profiles=exchanged(world,trade),updates=trade.players.map((q,i)=>({accountId:q.account,characterId:q.characterId,profile:world.canonical({...q,profile:profiles[i]})}));
    // Keep live inventories untouched until the atomic store confirms durability.
    if(await world.saveProfiles(updates)===false)fail('The trade could not be saved.',503);
    trade.players.forEach((q,i)=>{const intervening=(q.revision??0)-revisions[i];publishProfileChanges(q.profile,beforeProfiles[i],profiles[i]);refreshConcurrentBuffStats(world,q,beforeProfiles[i]);world.changed(q);q.dirty=intervening!==0;q.saveError=null;});
    trade.committing=false;cancelTrade(world,p,'completed');
  });world.saveQueue=task.catch(()=>{});
  try{await task;await persistInterveningProgress(world,trade.players);}catch(error){resetConfirmation(trade);trade.revision++;notify(world,trade,'save failed; review again');throw error;}
  finally{trade.committing=false;for(const q of trade.players)q.tradeCommitting=false;}
}
