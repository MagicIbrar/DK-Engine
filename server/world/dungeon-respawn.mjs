import {flushInstanceProgress} from './instance-progress.mjs';
import {disposeEmptyInstances} from './instances.mjs';
import {publishProfileChanges,refreshConcurrentBuffStats,persistInterveningProgress} from './profile-publication.mjs';
import {mergeRewardProgress} from './reward-progress.mjs';
import {cancelFishing} from './fishing.mjs';
import {sceneKey} from './scene.mjs';
import {nativeStageRespawn} from '../../src/game/native-stage-index.js';
const fail=(text,status=409)=>{throw Object.assign(Error(text),{status});};

/** Native maprespawn rows only. No table row means retain the existing return path.
 * Map49 selects only a checkpoint evidenced by the host's own native objective
 * deaths. This explicitly reconstructed rule falls back to the first native
 * return when the source facts do not authenticate; no wave percentage is used.
 * Maps52–55 each have one explicit destination on ordinary map51.
 */
export async function reviveNativeDungeon(world,p,authorize){
 const row=p.instanceId&&world.data.dungeonData?.dg?.maps?.[p.map]?.stageRespawn;
 if(!row)return false;
 return world.serializeAccount(p.account,async()=>{
  const instance=world.instances?.get(p.instanceId),previousMap=p.map,previousInstance=p.instanceId,token=p.token;
  const check=()=>{
   authorize();
   if(world.players.get(p.account)!==p||p.token!==token||!p.dead||p.map!==previousMap||p.instanceId!==previousInstance||world.instances.get(previousInstance)!==instance||instance?.kind!=='dungeon'||instance.map!==p.map||instance.closed||instance.closeRequested||instance.admitting||instance.floorTransition||instance.faulted||instance.expiresAt<=world.now()||!instance.admitted.has(p.characterId)||!instance.members.has(p.id)||instance.director?.map!==p.map||instance.director.disposed||world.maps.get(sceneKey(p.map,previousInstance))!==instance.scene)fail('The original dungeon revival scope is no longer available.');
  };
  check();await flushInstanceProgress(world,p,instance);check();
  const info=world.data.dungeonData.dg.maps[p.map],checkpoint=nativeStageRespawn({map:p.map,info,monsterDef:index=>world.data.monsterDef?.(index),killed:instance.director.killedIdx,bricks:instance.director.brickByUid});
  const first=checkpoint||row.stages?.[0],map=Number(row.respawnMap),same=map===previousMap;
  if(!first||!Number.isSafeInteger(map)||!Number.isFinite(first.x)||!Number.isFinite(first.y)||(!same&&world.data.requiresInstance?.(map)))fail('The native dungeon revive destination is unavailable.',503);
  const scene=same?instance.scene:await world.map(map,null,p.channel??0);check();
  const point={x:first.x+.5,z:first.y+.5},at=scene?.isWalkable(point.x,point.z)?point:scene?.nearest(point.x,point.z);
  if(!at)fail('No safe native dungeon revive point is available.',503);
  const before={profile:structuredClone(p.profile),revision:p.revision},transition=p.sceneTransition;
  const candidate={...p,profile:structuredClone(p.profile),stats:{...p.stats},map,instanceId:same?previousInstance:null,x:at.x,z:at.z,path:[],attackTarget:null,mount:null,pet:null,dead:false,hp:p.maxHp,mp:p.stats.maxMp||0,maxShield:Math.max(0,Number(p.stats.maxShield)||0),shield:Math.max(0,Number(p.stats.maxShield)||0),fishing:p.fishing?structuredClone(p.fishing):p.fishing};
  if(!same)delete candidate.profile.instance;
  cancelFishing(world,candidate);world.changed(candidate);p.sceneTransition=true;
  try{
   check();await world.persist(candidate);
   // The account fence retains human custody through this durable write.
   // Once accepted, a later timer/close request cannot reject the committed
   // return and leave the live corpse disagreeing with its saved profile.
   const intervening=p.revision-before.revision,merged=mergeRewardProgress(world,p,before.profile,candidate,{dil:candidate.profile.dil});
   publishProfileChanges(p.profile,before.profile,candidate.profile);
   if(merged.levelChanged){p.stats=candidate.stats;p.maxHp=candidate.maxHp;}
   for(const key of ['map','instanceId','x','z','path','attackTarget','mount','pet','dead','fishing'])p[key]=candidate[key];
   p.revision=candidate.revision+intervening;p.dirty=!!candidate.dirty||intervening!==0;p.saveError=candidate.saveError||null;
   refreshConcurrentBuffStats(world,p,before.profile);
   p.hp=p.maxHp;p.mp=p.stats.maxMp||0;p.maxShield=Math.max(0,Number(p.stats.maxShield)||0);p.shield=p.maxShield;delete p.respawnReadyAt;
   world.snapshotPublicRows?.delete(p);
   if(!same){world.emit(previousMap,{type:'leave',actorId:p.id,instanceId:previousInstance});instance.members.delete(p.id);world.emit(map,{type:'join',actorId:p.id,instanceId:null});disposeEmptyInstances(world);}
   for(const[m,event]of merged.notices)world.emit(m,event);
   world.emit(map,{type:'revive',actorId:p.id,instanceId:p.instanceId});
   await persistInterveningProgress(world,[p]);
  }finally{p.sceneTransition=transition;}
  return true;
 });
}
