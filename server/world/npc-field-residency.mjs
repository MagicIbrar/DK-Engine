import {sceneKey,sameScene} from './scene.mjs';import {isDkChannel,channelData} from './channels.mjs';
import {npcCapacityPolicy} from './npc-capacity-policy.mjs';import {types} from 'node:util';

// ENGINE-CHOSEN resource budgets, not Global progression/respawn rules.
export const NPC_FIELD_RESIDENCY_POLICY=Object.freeze({maxWorkerFields:4,maxParkedScenes:64,maxRetainedMonsters:100000,maxTypedGeometryBytes:64*1024*1024});
const geometryKeys=['collision','path','nearest','isWalkable'],schemas=new WeakMap();
export function rememberNativeFieldScene(scene){schemas.set(scene,new Set(Object.keys(scene)));return scene;}
const count=v=>v instanceof Map||v instanceof Set?v.size:Array.isArray(v)?v.length:v==null?0:Infinity;
const monsterKeys=new Set(['id','instanceId','channel','map','name','monsterIndex','respawnSec','x','z','hp','maxHp','home','dead','targetId','attackAt','respawnAt','def','hate','aiState','anchor','idleMove','called','specialReadyAt','powerReadyAt','statuses','_fk']);
// Parking-only shape check, by descriptor (no getter/trap is invoked). Two
// source-proven inert native fields are admitted, each validated narrowly:
// - yaw: SharedWorld.step (core.mjs) writes Math.atan2 facing as an ordinary
//   own enumerable number. Only an own, enumerable, writable, configurable,
//   finite number data property is accepted; accessors, inherited, non-number
//   and non-finite values still veto.
// - _skillActor: skills.mjs actorFor caches exactly one non-enumerable,
//   writable, configurable Proxy over this same record. It owns no timer,
//   lease, geometry or scene reference and resolves its map dynamically.
// Every other key must be an allowlisted own enumerable data property; symbol
// keys, other non-enumerable keys and non-plain prototypes still veto.
// Active targets, follow slots, hate, statuses, skills and marches keep their
// separate vetoes in npcFieldParkingRefusal below.
const parkedYaw=d=>!!d&&Object.hasOwn(d,'value')&&d.enumerable===true&&d.writable===true&&d.configurable===true&&typeof d.value==='number'&&Number.isFinite(d.value);
const parkedSkillActor=d=>!!d&&Object.hasOwn(d,'value')&&d.enumerable===false&&d.writable===true&&d.configurable===true&&(d.value===null||types.isProxy(d.value));
export function npcParkedMonsterShapeRefusal(m){
 if(!m||typeof m!=='object'||Object.getPrototypeOf(m)!==Object.prototype)return 'unknown or scripted monster state';
 if(!Object.hasOwn(m,'yaw')&&Reflect.has(m,'yaw'))return 'unknown or scripted monster state';
 for(const key of Reflect.ownKeys(m)){
  if(typeof key!=='string')return 'unknown or scripted monster state';
  const d=Object.getOwnPropertyDescriptor(m,key);
  if(key==='yaw'){if(!parkedYaw(d))return 'unknown or scripted monster state';continue;}
  if(key==='_skillActor'){if(!parkedSkillActor(d))return 'unknown or scripted monster state';continue;}
  if(!monsterKeys.has(key)||!d||!Object.hasOwn(d,'value')||d.enumerable!==true)return 'unknown or scripted monster state';
 }
 return null;
}
// Optional workers do not gain access to unknown/scripted runtime state merely
// because a human warmed its geometry. Parking keeps its stricter no-actor,
// no-effects/leases/reference vetoes unchanged below.
export function npcFieldWorkerStateRefusal(scene){
 const schema=schemas.get(scene);if(!schema||Object.keys(scene).some(k=>!schema.has(k)&&k!=='_skillStatusAt'))return 'unknown scene state';
 const stamp=Object.getOwnPropertyDescriptor(scene,'_skillStatusAt');if(stamp&&(!Object.hasOwn(stamp,'value')||!Number.isFinite(stamp.value)||stamp.value<0||stamp.value>Number.MAX_SAFE_INTEGER))return 'unknown scene state';
 if(Object.keys(scene).some(k=>!Object.hasOwn(Object.getOwnPropertyDescriptor(scene,k)||{},'value')))return 'unknown scene accessor';
 if(!(scene.monsters instanceof Map))return 'unknown monster collection';
 for(const m of scene.monsters.values()){
  if(!m||Object.keys(m).some(k=>!monsterKeys.has(k)||!Object.hasOwn(Object.getOwnPropertyDescriptor(m,k)||{},'value'))||m.def?.role!=='creature')return 'unknown or scripted monster state';
  if(m.eventMarch||m._skills||m._fk!=null)return 'scripted monster effect';
  if(m.hate!=null&&!(m.hate instanceof Map))return 'unknown hostility state';
 }
 return null;
}
export function npcFieldParkingRefusal(world,scene){
 if(!scene||world.maps?.get(sceneKey(scene.index,scene.instanceId,scene.channel))!==scene)return 'scene is not live';
 if(scene.instanceId||isDkChannel(scene.channel)||!Number.isInteger(scene.channel??0)||(scene.channel??0)<0||scene.custom||world.data.fieldParkingAllowed?.(scene.index)!==true)return 'not a proven unscripted native public field';
 if(typeof world.data.releaseMap!=='function'||typeof world.data.retainMap!=='function')return 'geometry ownership unavailable';
 // Normal skill status ticks add only this dedupe timestamp after map creation.
 // Inspect the descriptor rather than invoking an unknown getter. Keep the
 // original schema fixed; an arbitrary post-combat property remains a veto.
 const statusTick=Object.getOwnPropertyDescriptor(scene,'_skillStatusAt');
 if(statusTick&&(!Object.hasOwn(statusTick,'value')||typeof statusTick.value!=='number'||!Number.isFinite(statusTick.value)||statusTick.value<0||statusTick.value>Number.MAX_SAFE_INTEGER))return 'unknown scene state';
 const schema=schemas.get(scene);if(!schema||Object.keys(scene).some(k=>!schema.has(k)&&k!=='_skillStatusAt'))return 'unknown scene state';
 if(geometryKeys.some(k=>!Object.getOwnPropertyDescriptor(scene,k)?.configurable))return 'geometry cannot detach';
 if([...world.players.values()].some(p=>sameScene(p,{map:scene.index,instanceId:null,channel:scene.channel||0})))return 'actual actor still owns scene';
 if(world._sceneLeases?.get('*')||world._sceneLeases?.get(sceneKey(scene.index,null,scene.channel||0)))return 'scene admission or load lease';
 if(world.accountQueues?.size||world._saveFlights)return 'ordinary command or save pending';
 const edits=world.originalMapEdits;if(edits&&(!Array.isArray(edits.allowedMaps)||edits.allowedMaps.map(Number).includes(scene.index)||edits.isCommitting||typeof edits.isFrozen!=='function'||edits.isFrozen(scene.index)))return 'editor may retain geometry';
 if(world.data.customMaps&&(typeof world.data.customMaps.isDeploying!=='function'||world.data.customMaps.isDeploying(scene.index)))return 'custom publication state unknown or active';
 if([...world.maps.values()].some(s=>s!==scene&&s.index===scene.index))return 'another scene shares geometry';
 if([...world.groundLoot?.values()||[]].some(d=>sameScene(d,{map:scene.index,channel:scene.channel||0,instanceId:null})))return 'ground loot remains';
 if([...world.instances?.values()||[]].some(i=>i.map===scene.index||i.scene===scene))return 'instance or admission retains scene';
 // Explicit unknown scene references veto rather than guessing their lifecycle.
 for(const [k,v]of Object.entries(world)){if(['maps','_parkedFieldScenes','data'].includes(k))continue;if(v===scene||v?.scene===scene||v instanceof Map&&[...v.values()].some(r=>r===scene||r?.scene===scene))return 'external scene reference';}
 for(const m of scene.monsters?.values()||[]){
  if(npcParkedMonsterShapeRefusal(m)||m.def?.role!=='creature')return 'unknown or scripted monster state';
  if(m.eventMarch||m._skills||m._fk!=null||m.targetId||count(m.statuses)>0)return 'active monster combat or effect';
  if(m.hate!=null&&!(m.hate instanceof Map))return 'unknown hostility state';
 }
 if(!(scene.monsters instanceof Map))return 'unknown monster collection';
 const parked=world._parkedFieldScenes;if(!(parked instanceof Map)||parked.size>=NPC_FIELD_RESIDENCY_POLICY.maxParkedScenes)return 'retained scene budget';
 if([...parked.values()].reduce((n,s)=>n+s.monsters.size,scene.monsters.size)>NPC_FIELD_RESIDENCY_POLICY.maxRetainedMonsters)return 'retained monster budget';
 return null;
}
export function parkNativeFieldScene(world,index,channel=0){
 const key=sceneKey(index,null,channel),scene=world.maps.get(key),reason=npcFieldParkingRefusal(world,scene);if(reason)return {parked:false,reason};
 const owner=world._fieldMapOwners?.get(Number(index));if(!owner)return {parked:false,reason:'geometry owner absent'};
 // releaseMap runs only once this world's live geometry references are zero.
 // Failure restores the exact scene and leaves all its fields/cache untouched.
 world.maps.delete(key);let released=false;try{released=world.data.releaseMap(Number(index),{owner})===true;}catch{released=false;}
 if(!released){world.maps.set(key,scene);return {parked:false,reason:'geometry release refused'};}
 for(const k of geometryKeys)delete scene[k];world._fieldMapOwners.delete(Number(index));world._parkedFieldScenes.set(key,scene);
 return {parked:true,geometryReleased:true,retainedMonsters:scene.monsters.size};
}
export function createNpcFieldResidency(world,options={}){
 const capacity=npcCapacityPolicy(options.capacity);
 const bounded=(k,min)=>Math.max(min,Math.min(NPC_FIELD_RESIDENCY_POLICY[k],Number.isFinite(options[k])?Math.trunc(options[k]):NPC_FIELD_RESIDENCY_POLICY[k]));
 const policy={maxWorkerFields:bounded('maxWorkerFields',0),maxParkedScenes:bounded('maxParkedScenes',0),maxRetainedMonsters:bounded('maxRetainedMonsters',0),maxTypedGeometryBytes:bounded('maxTypedGeometryBytes',1)},workers=new Map();
 if(capacity)Object.assign(policy,{maxWorkerFields:capacity.maxWorkerFields,maxTypedGeometryBytes:Math.min(capacity.maxTypedGeometryBytes,1073741824)});
 const reservations=new Map();
 world.npcFieldResourceReservations=()=>[...reservations].map(([index,r])=>({index,bytes:r.bytes}));
 const publicRefusal=(index,channel,subject)=>{const profile=subject?.profile,actor=subject?.actor,account=subject?.account;
  if(!/^npc_[a-f0-9]{32}$/.test(account)||!profile||profile.authority!=='server'||profile.npcPlayer!==true||typeof profile.id!=='string')return 'canonical NPC identity required';
  if(actor?(world.players.get(account)!==actor||actor.account!==account||actor.profile!==profile||actor.characterId!==profile.id||actor.leaving||actor.instanceId||isDkChannel(actor.channel)):(profile.map!==index||(profile.channel??0)!==channel||profile.instance||profile.dkReturn))return 'canonical NPC scene ownership required';
  const channels=channelData(world);if(!Number.isInteger(channel)||channel<0||!channels?.field?.some(c=>c.index===channel)||Object.hasOwn(channels?.dkMaps||{},String(index)))return 'not an original public field channel/map';
  if(world.data.customMaps?.has?.(index)||world.data.customMaps?.isDeploying?.(index))return 'custom map refused';
  const d=world.data.publicFieldDescriptor?.(index),level=profile.level;if(!d||!Number.isInteger(level)||level<d.minLevel||level>d.maxLevel)return 'native public map/level admission refused';return null;
 };
 const resources=()=>{const m=world.data.mapCacheSnapshot?.();if(!m?.accountingReady||!Number.isSafeInteger(m.reservedGeometryBytes)||!Array.isArray(m.rows)||typeof world.data.ownsMapGeometry!=='function')return null;const costs=new Map();for(const r of m.rows){if(!Number.isInteger(r.index)||!Number.isSafeInteger(r.accountedBytes)||r.accountedBytes<0||costs.has(r.index))return null;costs.set(r.index,r.accountedBytes);}for(const[index,r]of reservations)costs.set(index,Math.max(costs.get(index)||0,r.bytes));const eventReservations=world.npcEventResourceReservations?.()||[];for(const r of eventReservations){if(!Number.isInteger(r.index)||!Number.isSafeInteger(r.bytes)||r.bytes<0||!Number.isSafeInteger(r.cloneBytes)||r.cloneBytes<0)return null;costs.set(r.index,Math.max(costs.get(r.index)||0,r.bytes));}let protectedCloneBytes=eventReservations.reduce((n,r)=>n+r.cloneBytes,0);const clones=new Set();const scenes=[...world.maps.values(),...[...world.instances?.values()||[]].map(i=>i.scene).filter(Boolean)];for(const s of scenes){const c=s.collision;if(!c||world.data.ownsMapGeometry(s.index,c)||clones.has(c))continue;const w=c.width,h=c.height;if(!Number.isInteger(w)||!Number.isInteger(h)||w<1||h<1||w>8192||h>8192)return null;clones.add(c);protectedCloneBytes+=20*w*h+2097152;}return {bytes:[...costs.values()].reduce((n,v)=>n+v,protectedCloneBytes),maps:costs.size+clones.size+eventReservations.filter(r=>r.cloneBytes>0).length,reservations:reservations.size,protectedCloneBytes};};
 const humans=()=>new Set([...world.players.values()].filter(p=>p.profile?.npcPlayer!==true&&!p.leaving).map(p=>sceneKey(p.map,p.instanceId,p.channel||0)));
 const workerKeys=()=>{const human=humans(),keys=new Set([...workers.keys()].filter(k=>!human.has(k)));for(const [k,s]of world.maps)if(!human.has(k)&&!s.instanceId&&!isDkChannel(s.channel)&&(world.data.fieldParkingAllowed?.(s.index)===true||world.data.publicFieldDescriptor?.(s.index)))keys.add(k);for(const p of world.players.values()){const k=sceneKey(p.map,p.instanceId,p.channel||0);if(p.profile?.npcPlayer===true&&!p.leaving&&!p.instanceId&&!human.has(k)&&(world.data.fieldParkingAllowed?.(p.map)===true||world.data.publicFieldDescriptor?.(p.map)))keys.add(k);}return keys;};
 const snapshot=()=>{const human=humans(),worker=workerKeys(),loaded=[...world.maps],other=loaded.filter(([k])=>!human.has(k)&&!worker.has(k));return {policy:'ENGINE-CHOSEN ordinary native field residency',limits:policy,workerFields:worker.size,workerFieldLeases:workers.size,humanScenes:human.size,loadedHumanScenes:loaded.filter(([k])=>human.has(k)).length,loadedWorkerScenes:loaded.filter(([k])=>worker.has(k)).length,loadedProtectedNonworkerScenes:other.length,loadedProtectedNonworkerGeometries:new Set(other.map(([,s])=>s.collision).filter(Boolean)).size,loadedScenes:world.maps.size,parkedScenes:world._parkedFieldScenes.size,retainedMonsters:[...world._parkedFieldScenes.values()].reduce((n,s)=>n+s.monsters.size,0),geometry:world.data.mapCacheSnapshot?.()||{typedGeometryBytes:null,otherObjectBytes:null},resourceReservation:resources()};};
 const acquire=async(index,channel,subject,strictWorker=false)=>{
  const key=sceneKey(index,null,channel),human=humans().has(key),old=workers.get(key),occupied=workerKeys();
  // Legacy callers can pin the exact already occupied human scene even with
  // zero optional-worker fields. This never loads/increases geometry and is
  // unavailable to strict optional-worker admission/travel.
  const originalScene=world.maps.get(key),collision=originalScene?.collision,humanActor=!strictWorker&&human?[...world.players.values()].find(p=>p.profile?.npcPlayer!==true&&!p.leaving&&sceneKey(p.map,p.instanceId,p.channel||0)===key):null;
  const legacyHumanCurrent=()=>humanActor&&world.players.get(humanActor.account)===humanActor&&!humanActor.leaving&&humanActor.profile?.npcPlayer!==true&&sceneKey(humanActor.map,humanActor.instanceId,humanActor.channel||0)===key&&world.maps.get(key)===originalScene&&originalScene?.collision===collision;
  if(!human&&!occupied.has(key)&&occupied.size>=policy.maxWorkerFields)return {ok:false,reason:'worker field budget'};
  const releaseScene=world.acquireSceneLease(index,null,channel),entry=old||{refs:0};if(!human){entry.refs++;workers.set(key,entry);}let released=false,reserved=null;
  const release=()=>{if(released)return;released=true;releaseScene();if(!human&&--entry.refs===0)workers.delete(key);if(reserved&&--reserved.refs===0&&reservations.get(index)===reserved)reservations.delete(index);};
  try{
   const f=await world.data.mapGeometryForecast(index);if(!Number.isSafeInteger(f?.reservedBytes)||f.reservedBytes<=0)throw Error('geometry forecast unavailable');
   if(subject){const reason=publicRefusal(index,channel,subject);if(reason)throw Error(reason);}
   const eventLimits=world.npcEventResourceLimits?.(),maxBytes=Math.max(policy.maxTypedGeometryBytes,eventLimits?.maxBytes||0),maxMaps=Math.max(policy.maxWorkerFields,eventLimits?.maxMaps||0);const current=resources();if(!current)throw Error('geometry accounting unavailable');
   const rows=world.data.mapCacheSnapshot().rows,charged=Math.max(rows.find(r=>r.index===index)?.accountedBytes||0,reservations.get(index)?.bytes||0);
   const legacyReuse=!strictWorker&&!!legacyHumanCurrent()&&charged>=f.reservedBytes;
   if(!legacyReuse&&current.bytes+Math.max(0,f.reservedBytes-charged)>maxBytes)throw Error('geometry reservation budget');
   if(!charged&&current.maps>=maxMaps)throw Error('geometry map budget');
   reserved=reservations.get(index)||{bytes:f.reservedBytes,refs:0};reserved.refs++;reservations.set(index,reserved);
   const scene=await world.map(index,null,channel);
   if(subject){const reason=publicRefusal(index,channel,subject);if(reason)throw Error(reason);}
   const after=resources();if(!after||(!legacyReuse&&(after.bytes>maxBytes||after.maps>maxMaps)))throw Error('loaded geometry exceeds worker budget');
   if(legacyReuse&&(!legacyHumanCurrent()||scene!==originalScene||after.bytes>current.bytes||after.maps>current.maps))throw Error('legacy human geometry custody or census changed');
   if(world.maps.get(key)!==scene||scene.index!==index||scene.instanceId||scene.custom||(scene.channel??0)!==channel)throw Error('ordinary native scene identity mismatch');
   if(strictWorker){const reason=npcFieldWorkerStateRefusal(scene);if(reason)throw Error(reason);}
   return {ok:true,scene,release};
  }catch(error){release();return {ok:false,reason:error.message};}
 };
 return {
  async acquire(index,channel=0){index=Number(index);if(!Number.isInteger(index)||!Number.isInteger(channel)||channel<0||world.data.fieldParkingAllowed?.(index)!==true)return {ok:false,reason:'not a proven native worker field'};return acquire(index,channel,null);},
  async acquirePublic(index,channel=0,subject){index=Number(index);const reason=publicRefusal(index,channel,subject);if(reason)return {ok:false,reason};return acquire(index,channel,subject);},
  async acquireWorker(index,channel=0,subject){index=Number(index);const reason=publicRefusal(index,channel,subject);if(reason)return {ok:false,reason};if(world.data.fieldParkingAllowed?.(index)!==true||world.data.publicFieldDescriptor?.(index)?.scripted!==false)return {ok:false,reason:'not a proven unscripted native worker field'};const scene=world.maps.get(sceneKey(index,null,channel));if(scene){const state=npcFieldWorkerStateRefusal(scene);if(state)return {ok:false,reason:state};}return acquire(index,channel,subject,true);},
  parkVacant(){const out=[],human=humans();for(const [key,s]of [...world.maps]){if(workers.has(key)||human.has(key))continue;if(world._parkedFieldScenes.size>=policy.maxParkedScenes||[...world._parkedFieldScenes.values()].reduce((n,p)=>n+p.monsters.size,s.monsters.size)>policy.maxRetainedMonsters)break;const result=world.parkFieldScene(s.index,s.channel||0);out.push({map:s.index,channel:s.channel||0,...result});}return out;},
  snapshot,
 };
}
