import {canonicalNpc,npcSlotsAvailable} from './npc-human-slots.mjs';
import {sameScene} from './scene.mjs';

// ENGINE-CHOSEN finite foreground event custody. This never admits a new actor,
// relaxes worker script guards, grants tickets, or mutates native event rules.
const books=new WeakMap();
const fail=message=>{throw Object.assign(Error(message),{status:409});};
const cloneCost=f=>20*f.width*f.height+2097152;
export function createNpcEventResourceBudget(world){
 if(books.has(world))return books.get(world);
 const held=new Set();
 const currentJoin=r=>r.joinInstance&&world.instances?.get(r.joinInstance.id)===r.joinInstance&&r.joinInstance.map===r.map&&!r.joinInstance.closed&&!r.joinInstance.closeRequested&&!r.joinInstance.run?.ended&&r.joinInstance.run?.phase==='waitStart'&&r.joinInstance.run.phaseT>5;
 const activeClone=r=>currentJoin(r)||[...(world.instances?.values()||[])].some(i=>i.map===r.map&&r.accounts.every(a=>i.members?.has(world.players.get(a)?.id)));
 const pending=()=>[...held].filter(r=>!r.released).map(r=>({index:r.map,bytes:r.forecast.reservedBytes,cloneBytes:r.instance&&!activeClone(r)?cloneCost(r.forecast):0}));
 world.npcEventResourceReservations=pending;
 const valid=r=>!r.released&&(!r.joinInstance||currentJoin(r))&&world.now()<r.until&&npcSlotsAvailable(world,0)&&!world.npcHumanReservations?.size&&r.members.every((p,k)=>world.players.get(p.account)===p&&canonicalNpc(p)&&p.token===r.tokens[k]&&!p.leaving&&!p.revoked&&!p.dead&&(!r.partyId||p.partyId===r.partyId));
 const census=()=>{
  const cache=world.data.mapCacheSnapshot?.();if(!cache?.accountingReady||!Array.isArray(cache.rows))return null;
  const costs=new Map();for(const r of cache.rows){if(!Number.isInteger(r.index)||!Number.isSafeInteger(r.accountedBytes)||r.accountedBytes<0||costs.has(r.index))return null;costs.set(r.index,r.accountedBytes);}
  for(const r of pending())costs.set(r.index,Math.max(costs.get(r.index)||0,r.bytes));
  for(const r of world.npcFieldResourceReservations?.()||[]){if(!Number.isInteger(r.index)||!Number.isSafeInteger(r.bytes)||r.bytes<0)return null;costs.set(r.index,Math.max(costs.get(r.index)||0,r.bytes));}
  let clones=0,bytes=0;const seen=new Set();
  for(const s of [...world.maps.values(),...[...(world.instances?.values()||[])].map(i=>i.scene).filter(Boolean)]){const c=s.collision;if(!c||world.data.ownsMapGeometry?.(s.index,c)||seen.has(c))continue;if(!Number.isInteger(c.width)||!Number.isInteger(c.height)||c.width<1||c.height<1)return null;seen.add(c);clones++;bytes+=20*c.width*c.height+2097152;}
  for(const r of pending())if(r.cloneBytes){clones++;bytes+=r.cloneBytes;}
  const humanMaps=new Set([...world.players.values()].filter(p=>!canonicalNpc(p)&&!p.leaving).map(p=>Number(p.map)));
  const humanBytes=[...humanMaps].reduce((n,map)=>n+(costs.get(map)||0),0);
  return {maps:costs.size+clones,bytes:[...costs.values()].reduce((n,v)=>n+v,bytes),maxMaps:4+humanMaps.size,maxBytes:Math.max(64*1024*1024,humanBytes)};
 };
 world.npcEventResourceLimits=()=>held.size||[...(world.instances?.values()||[])].some(i=>['deadFront','iceCastle'].includes(i.kind)&&[...world.players.values()].some(p=>canonicalNpc(p)&&p.instanceId===i.id))?census():null;
 const book={
  async acquire(members,{map,until,instance=false,partyId=null,cycle=null,joinInstance=null}={}){
   if(!Array.isArray(members)||members.length<1||members.length>7||new Set(members.map(p=>p.account)).size!==members.length||!Number.isInteger(map)||!Number.isFinite(until)||until<=world.now()||until-world.now()>3600000)return null;
   if(joinInstance&&(!instance||!['deadFront','iceCastle'].includes(joinInstance.kind)))return null;
   const r={members:[...members],accounts:members.map(p=>p.account),tokens:members.map(p=>p.token),map,until,instance,partyId,cycle,joinInstance,released:false};
   if(!valid(r)||members.some(p=>p.instanceId||p.commandActive||p.progressCommitting||p.sceneTransition)||partyId&&world.parties?.get(partyId)?.members.length!==members.length)return null;
   let forecast;try{forecast=await world.data.mapGeometryForecast(map);}catch{return null;}
   if(!valid(r)||![forecast?.width,forecast?.height,forecast?.reservedBytes].every(Number.isSafeInteger)||forecast.width<1||forecast.height<1||forecast.reservedBytes<1)return null;
   r.forecast=forecast;held.add(r);let cost=census();
   // A completed ordinary approach can leave its vacant public field loaded.
   // Reuse the existing conservative parking authority before refusing optional
   // event work; scripted/town/occupied/leased/pending scenes remain protected.
   if(cost&&(cost.maps>cost.maxMaps||cost.bytes>cost.maxBytes)&&typeof world.parkFieldScene==='function'){
    let checked=0;for(const s of [...world.maps.values()]){
     if(checked>=4||!cost||cost.maps<=cost.maxMaps&&cost.bytes<=cost.maxBytes)break;
     if(s.instanceId||world.data.fieldParkingAllowed?.(s.index)!==true)continue;
     checked++;world.parkFieldScene(s.index,s.channel||0);cost=census();
    }
   }
   // Optional event work refuses pressure; ordinary human entry is untouched.
   if(!cost||cost.maps>cost.maxMaps||cost.bytes>cost.maxBytes){held.delete(r);return null;}
   return {valid:()=>valid(r),release(){r.released=true;held.delete(r);},map,cycle,partyId,members:r.members};
  },
  admission(members,{map,leader,cycle,war=null}){
   const r=[...held].find(r=>r.instance&&r.map===map&&r.cycle===cycle&&r.partyId===leader.partyId&&r.members.length===members.length&&r.members.every(p=>members.includes(p))&&valid(r));
   if(!r)fail('NPC event team has no current finite foreground reservation.');
   if(r.joinInstance&&war!==r.joinInstance||!r.joinInstance&&war&&!r.members.every(p=>war.members?.has(p.id)))fail('NPC event target changed.');
   const party=world.parties?.get(r.partyId);if(!party||party.leader!==leader.id||members.some(p=>!sameScene(p,leader)))fail('NPC event team changed.');
   const cost=census();if(!cost||cost.maps>cost.maxMaps||cost.bytes>cost.maxBytes)fail('NPC event geometry budget is unavailable.');
   return true;
  },
  snapshot:()=>({pending:held.size,geometry:census()}),
  dispose(){for(const r of held)r.released=true;held.clear();},
 };
 books.set(world,book);return book;
}
export function npcEventReservedAdmission(world,members,input){return createNpcEventResourceBudget(world).admission(members,input);}
