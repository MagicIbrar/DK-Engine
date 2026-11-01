import {randomUUID} from 'node:crypto';
import {rejectsResurrection} from './gameplay-preferences.mjs';
import {sameScene} from './scene.mjs';

// ENGINE-CHOSEN offer lifetime: Global supplies the native Yes/No prompt (1002:41), not its timeout.
export const RESURRECTION_OFFER_MS=60000;
export function resurrectionOffer(world,p){
  const offer=p.resurrectionOffer;
  if(!offer||!p.dead||p.leaving||offer.token!==p.token||offer.death!==p.respawnReadyAt||!sameScene(offer,p)||offer.expires<=world.now()||rejectsResurrection(p)){
    delete p.resurrectionOffer;return null;
  }
  return offer;
}
export function offerResurrection(world,p,fraction){
  if(!p?.dead||p.leaving||rejectsResurrection(p)||!Number.isFinite(fraction)||fraction<=0||fraction>1)return false;
  const match=p.partyPvpId&&world.partyMatches?.get(p.partyPvpId);
  if(match&&(!['wait','fight'].includes(match.phase)||match.mode!==4))return false;
  world.changed(p); // establish the host death generation before binding consent
  p.resurrectionOffer={id:randomUUID(),fraction,expires:world.now()+RESURRECTION_OFFER_MS,token:p.token,death:p.respawnReadyAt,map:p.map,instanceId:p.instanceId||null,channel:p.channel??0};
  world.changed(p);return true;
}
export function resurrectionSnapshot(world,p){
  const offer=resurrectionOffer(world,p);return offer?{id:offer.id,expires:offer.expires}:null;
}
export async function answerResurrection(world,p,input){
  const fail=message=>{throw Object.assign(Error(message),{status:400});};
  if(Object.keys(input).some(k=>!['token','type','id','accept'].includes(k))||typeof input.accept!=='boolean')fail('Invalid resurrection answer.');
  const offer=resurrectionOffer(world,p);
  if(!offer||input.id!==offer.id)fail('This resurrection request is no longer available.');
  delete p.resurrectionOffer;
  if(!input.accept){world.changed(p);return false;}
  const before={hp:p.hp,path:p.path,ready:p.respawnReadyAt};
  p.dead=false;p.hp=Math.max(1,Math.round(p.maxHp*offer.fraction));p.path=[];
  world.changed(p);
  try{await world.persist(p);}
  catch(error){p.dead=true;p.hp=before.hp;p.path=before.path;p.respawnReadyAt=before.ready;p.resurrectionOffer=offer;world.changed(p);throw error;}
  world.emit(p.map,{type:'revive',actorId:p.id,instanceId:p.instanceId||null});
  return true;
}
