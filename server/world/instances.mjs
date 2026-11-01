import {randomUUID} from 'node:crypto';
import {cancelFishing} from './fishing.mjs';
import {sceneKey,mapFor} from './scene.mjs';
import {flushInstanceProgress,hasPendingInstanceProgress} from './instance-progress.mjs';
import {publishProfileChanges,refreshConcurrentBuffStats,persistInterveningProgress} from './profile-publication.mjs';
import {mergeRewardProgress} from './reward-progress.mjs';
function publishSceneCandidate(world,p,candidate,before){
 // The scene owns admission/exit fields; trusted recipient progress can arrive
 // during storage. Merge its earned interval and retain live profile identity.
 const intervening=p.revision-before.revision;
 const merged=mergeRewardProgress(world,p,before.profile,candidate,{dil:candidate.profile.dil});
 publishProfileChanges(p.profile,before.profile,candidate.profile);
 for(const key of ['instanceId','map','x','z','path','mount','pet'])p[key]=candidate[key];
 if(merged.levelChanged){p.stats=candidate.stats;p.maxHp=candidate.maxHp;}
 p.revision=candidate.revision+intervening;p.dirty=!!candidate.dirty||intervening!==0;p.saveError=candidate.saveError||null;
 refreshConcurrentBuffStats(world,p,before.profile);
 p.hp=Math.min(p.hp,p.maxHp);p.mp=Math.min(p.mp||0,p.stats.maxMp||0);
 return merged.notices;
}
/** Build an admission privately, then publish its members and events after saving. */
export function stageInstanceMembers(world,members,profiles){
 const before=members.map(p=>({profile:structuredClone(p.profile),revision:p.revision}));
 const candidates=members.map((p,index)=>({...p,profile:profiles[index],stats:{...p.stats},path:[...p.path],fishing:p.fishing?structuredClone(p.fishing):p.fishing}));
 const players=new Map(world.players);for(const p of candidates)players.set(p.account,p);
 const events=[];let staging=true;
 const facade=new Proxy(world,{get(target,key,receiver){
  if(key==='players'&&staging)return players;
  if(key==='emit'&&staging)return (map,event)=>{
   const ids=[event.actorId,event.sourceId,event.targetId].filter(Boolean),actor=candidates.find(p=>ids.includes(p.id));
   events.push([map,{...event,instanceId:event.instanceId!==undefined?event.instanceId:actor?.instanceId||null}]);
  };
  return Reflect.get(target,key,receiver);
 }});
 return {world:facade,candidates,async commit(){
  const notices=members.flatMap((p,index)=>publishSceneCandidate(world,p,candidates[index],before[index]));
  for(const p of members)cancelFishing(world,p);
  staging=false;for(const[map,event]of events)world.emit(map,event);
  for(const[map,event]of notices)world.emit(map,event);
  await persistInterveningProgress(world,members);
 }};
}
export function restoreInstance(world,profile){
 const saved=profile.instance,instance=saved&&world.instances?.get(saved.id);
 if(instance&&!instance.closed&&instance.expiresAt>world.now()&&instance.admitted.has(profile.id))return instance.id;
 if(saved){const exit=saved.exit||world.data.start;profile.map=exit.map;profile.pos={x:exit.x,z:exit.z,dirDeg:0};delete profile.instance;}
 return null;
}
export async function createInstance(world,{map,members,kind,exit,durationMs=3600000,emitLeave=true}){
 if(!Array.isArray(members)||!members.length||members.some(p=>p.leaving||p.instanceId))throw Object.assign(Error('Party members must be connected outside an instance.'),{status:400});
 world.instances ||= new Map();const id=randomUUID(),instance={id,map,kind,exit,admitted:new Set(members.map(p=>p.characterId)),members:new Set(members.map(p=>p.id)),expiresAt:world.now()+durationMs,closed:false};
 const scene=await world.map(map,id);instance.scene=scene;world.instances.set(id,instance);
 for(const p of members){cancelFishing(world,p);if(emitLeave)world.emit(p.map,{type:'leave',actorId:p.id});p.instanceId=id;p.map=map;p.path=[];p.mount=null;p.pet=null;p.profile.instance={id,kind,map,exit};world.changed(p);}
 return instance;
}
export async function exitInstance(world,p,{persist=true}={}){
 if(!p.instanceId)return;
 await flushInstanceProgress(world,p);
 const instance=world.instances?.get(p.instanceId),exit=instance?.exit||p.profile.instance?.exit||world.data.start;
 const scene=await world.map(exit.map,null,p.channel??0),point=scene.nearest(exit.x,exit.z);if(!point)throw Object.assign(Error('No safe instance exit is available.'),{status:503});
 const before={profile:structuredClone(p.profile),revision:p.revision},transition=p.sceneTransition;
 const previousMap=p.map,previousInstance=p.instanceId,candidate={...p,profile:structuredClone(p.profile),stats:{...p.stats},instanceId:null,map:exit.map,x:point.x,z:point.z,path:[],mount:null,pet:null};delete candidate.profile.instance;world.changed(candidate);
 p.sceneTransition=true;
 try{if(persist)await world.persist(candidate);const notices=publishSceneCandidate(world,p,candidate,before);for(const[map,event]of notices)world.emit(map,event);if(persist)await persistInterveningProgress(world,[p]);}
 finally{p.sceneTransition=transition;}
 cancelFishing(world,p);world.emit(previousMap,{type:'leave',actorId:p.id,instanceId:previousInstance});instance?.members.delete(p.id);world.emit(p.map,{type:'join',actorId:p.id});disposeEmptyInstances(world);
}
// Timed closure must survive failed profile writes and drain earned progress.
// The instance stays alive until every remaining participant has durably exited.
export function requestInstanceClose(world,instance){
 instance.closeRequested=true;
 if(instance.exitSave||world.now()<(instance.exitRetryAt||0))return instance.exitSave;
 const members=[...world.players.values()].filter(p=>!p.leaving&&p.instanceId===instance.id);
 if(members.some(p=>p.sceneTransition||p.commandActive)){instance.exitRetryAt=world.now()+1000;return null;}
 const task=Promise.resolve().then(async()=>{
  const results=await Promise.allSettled(members.map(p=>exitInstance(world,p))),failed=results.find(result=>result.status==='rejected');
  if(failed){instance.saveError=failed.reason.message;instance.exitRetryAt=world.now()+1000;}
  else {instance.saveError=null;instance.exitRetryAt=0;}
 }).finally(()=>{if(instance.exitSave===task)instance.exitSave=null;});
 instance.exitSave=task;void task.catch(error=>{instance.saveError=error.message;instance.exitRetryAt=world.now()+1000;});return task;
}
export function disposeEmptyInstances(world){
 for(const[id,instance]of world.instances||[]){if(instance.admitting)continue;const live=[...world.players.values()].some(p=>p.instanceId===id&&(!p.leaving||hasPendingInstanceProgress(world,p)));if(!live){instance.closed=true;instance.run?.end('empty');world.maps.delete(sceneKey(instance.map,id));for(const[key,drop]of world.groundLoot||[])if(drop.instanceId===id)world.groundLoot.delete(key);world.instances.delete(id);}}
}

// Only trusted server callers may use this: admission/GM/quest/gate validation happens first.
export async function enterTrustedScene(world,p,map,point,{kind='field',durable=false}={}){
 const original={map:p.map,x:p.x,z:p.z};
 const scoped=!!world.data.requiresInstance?.(Number(map));
 // A field arrival must register the full simulation scene before publishing p.map.
 // Loading raw geometry alone leaves mapFor(world,p) undefined on the next move/interaction.
 const candidate=scoped?await world.data.map(Number(map),{instance:true}):await world.map(Number(map),null,p.channel??0);
 const at=candidate.nearest(point.x,point.z);if(!at)throw Object.assign(Error('No safe arrival point is available.'),{status:503});
 if(durable){
  // Keep the old scene and membership live until the candidate is durable.
  await flushInstanceProgress(world,p);
  const transition=p.sceneTransition,previousInstance=p.instanceId,staged=stageInstanceMembers(world,[p],[structuredClone(p.profile)]),q=staged.candidates[0];let instance;
  p.sceneTransition=true;
  try{
   cancelFishing(staged.world,q);staged.world.emit(q.map,{type:'leave',actorId:q.id,instanceId:previousInstance});q.instanceId=null;delete q.profile.instance;
   if(scoped){instance=await createInstance(staged.world,{map:Number(map),members:[q],kind,exit:world.instances?.get(previousInstance)?.exit||original,emitLeave:false});instance.admitting=true;}
   else q.map=Number(map);
   q.x=at.x;q.z=at.z;q.path=[];world.changed(q);staged.world.emit(q.map,{type:'join',actorId:q.id});
   await world.persist(q);await staged.commit();
   if(instance)instance.admitting=false;
   world.instances?.get(previousInstance)?.members.delete(p.id);disposeEmptyInstances(world);
  }catch(error){if(instance){world.instances.delete(instance.id);world.maps.delete(sceneKey(instance.map,instance.id));}throw error;}
  finally{p.sceneTransition=transition;}
  return at;
 }
 cancelFishing(world,p);
 if(p.instanceId)await exitInstance(world,p,{persist:false});
 if(scoped)await createInstance(world,{map:Number(map),members:[p],kind,exit:original});
 else {world.emit(p.map,{type:'leave',actorId:p.id});p.map=Number(map);p.instanceId=null;}
 p.x=at.x;p.z=at.z;p.path=[];world.changed(p);world.emit(p.map,{type:'join',actorId:p.id});
 return at;
}
