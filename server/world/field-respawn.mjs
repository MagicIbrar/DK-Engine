import {serializeLife} from './life-transactions.mjs';
import {forcedRespawnLocation,noteSafeTime} from './wanted.mjs';
import {travelLocation,boundReturnTarget} from './travel.mjs';
import {reviveScene,isDkChannel} from './channels.mjs';
import {publishProfileChanges,refreshConcurrentBuffStats,persistInterveningProgress} from './profile-publication.mjs';
import {mergeRewardProgress} from './reward-progress.mjs';
import {trackForcedDisplacement} from './movement-authority.mjs';
import {initializePets} from './pets.mjs';
import {applyRespawnVitals} from '../../src/game/progression.js';
const fail=(message,status=409)=>{throw Object.assign(Error(message),{status});};

// Ordinary field revival: original bound return point, native chaotic-band
// forced destination, and the existing DK/premium precedence. Special runs
// retain their authenticated controllers; this cannot allocate an instance.
export async function reviveNativeField(world,p,premiumAt,authorize){
 if(p.instanceId)return false;
 return world.serializeAccount(p.account,()=>serializeLife(p,async()=>{
  const token=p.token,source=p.map,channel=p.channel??0,profileIdentity=p.profile;
  const check=()=>{
   authorize();
   if(world.players.get(p.account)!==p||p.token!==token||p.profile!==profileIdentity||p.profile.id!==p.characterId||p.leaving||p.revoked||!p.dead||p.hp>0||p.map!==source||(p.channel??0)!==channel||p.instanceId||p.profile.instance||p.customMapPending||p.progressCommitting||p.tradeCommitting)fail('The original field revival scope changed.');
   if(Number.isFinite(p.respawnReadyAt)&&world.now()<p.respawnReadyAt)fail('Wait for the original revival countdown.',400);
  };
  check();
  const forcedIndex=isDkChannel(channel)?null:forcedRespawnLocation(world,p);
  const forcedAt=forcedIndex?travelLocation(world,forcedIndex):null;
  if(forcedIndex&&!forcedAt)fail('The native forced revival destination is unavailable.',503);
  const route=reviveScene(world,p,forcedAt||premiumAt);
  let destination=forcedAt||premiumAt||route.at||boundReturnTarget(world,p.profile),town,point;
  if(!destination||![destination.map,destination.x,destination.z].every(Number.isFinite)||world.data.requiresInstance?.(destination.map))fail('The original field revival destination is unavailable.',503);
  try{town=await world.map(destination.map,null,route.channel);point=town.nearest(destination.x,destination.z);}catch(error){if(!premiumAt||forcedAt)throw error;}
  // A missing premium point retains the original ordinary return fallback.
  if(premiumAt&&!forcedAt&&!point){destination=boundReturnTarget(world,p.profile);if(!destination||world.data.requiresInstance?.(destination.map))fail('The original return destination is unavailable.',503);town=await world.map(destination.map,null,route.channel);point=town.nearest(destination.x,destination.z);}
  check();if(!point||!town.isWalkable(point.x,point.z))fail('No safe original revive point is available.',503);
  const before={profile:structuredClone(p.profile),revision:p.revision},transition=p.sceneTransition;
  const profile=structuredClone(before.profile);if(route.leftDk)delete profile.dkReturn;
  initializePets(profile);
  const candidate={...p,profile,stats:{...p.stats},map:destination.map,channel:route.channel,x:point.x,z:point.z,yaw:-(Number(destination.dirDeg)||0)*Math.PI/180,path:[],attackTarget:null,smartWarp:null,mount:null,pet:null,dead:false,hp:p.maxHp,mp:p.stats.maxMp||0,maxShield:Math.max(0,Number(p.stats.maxShield)||0),shield:Math.max(0,Number(p.stats.maxShield)||0)};
  // Removing a dead rider must remove its native mounted stat options in the
  // very same saved generation. Retain learned passive options once, as the
  // ordinary shared skill refresh does, without persisting them as buffs.
  const passives=p._skills?.engine?.passiveEntries?.()||[];
  candidate.stats=world.data.stats({...profile,buffs:[...(profile.buffs||[]),...passives]},candidate,world.now());
  candidate.maxHp=candidate.stats.maxHp;
  { const vitals=applyRespawnVitals(candidate, world.data); candidate.hp=vitals.hp; candidate.mp=vitals.mp; }
  candidate.maxShield=Math.max(0,Number(candidate.stats.maxShield)||0);candidate.shield=candidate.maxShield;
  world.changed(candidate);p.sceneTransition=true;
  try{
   check();await world.persist(candidate);
   const intervening=p.revision-before.revision,merged=mergeRewardProgress(world,p,before.profile,candidate,{dil:candidate.profile.dil});
   publishProfileChanges(p.profile,before.profile,candidate.profile);
   p.stats=candidate.stats;p.maxHp=candidate.maxHp;
   for(const key of ['map','channel','x','z','yaw','path','attackTarget','smartWarp','mount','pet','dead'])p[key]=candidate[key];
   p.revision=candidate.revision+intervening;p.dirty=!!candidate.dirty||intervening!==0;p.saveError=candidate.saveError||null;
   refreshConcurrentBuffStats(world,p,before.profile);
   p.hp=candidate.hp;p.mp=candidate.mp;p.maxShield=Math.max(0,Number(p.stats.maxShield)||0);p.shield=p.maxShield;delete p.respawnReadyAt;
   trackForcedDisplacement(world,p);world.snapshotPublicRows?.delete(p);
   if(source!==p.map||channel!==p.channel){world.emit(source,{type:'leave',actorId:p.id,instanceId:null,channel});world.emit(p.map,{type:'join',actorId:p.id,instanceId:null,channel:p.channel});}
   for(const [map,event]of merged.notices)world.emit(map,event);
   // Field-PK Safe Time on revive after a PK death (stringtable_pc 1003:10; formula.ini dwNonPKTime).
   if(p.pkSafePending){
     delete p.pkSafePending;
     const ms=Number(world.data?.pvpRules?.nonPkTimeMs)||0;
     if(ms>0){ noteSafeTime(world,p,ms); world.emit(p.map,{type:'pk',reason:'safetime',actorId:p.id,targetId:p.id,recipients:[p.id]}); }
   }
   world.emit(p.map,{type:'revive',actorId:p.id,instanceId:null});await persistInterveningProgress(world,[p]);
  }finally{p.sceneTransition=transition;}
  return true;
 }));
}
