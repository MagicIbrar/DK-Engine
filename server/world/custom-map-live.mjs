// Occupied publication is enabled only by this explicit integration hook.
// The API's global publication barrier must drain commands before publish().
import {fishingBusy} from './fishing.mjs';
import {randomUUID} from 'node:crypto';
export const CUSTOM_MAP_READY_MS=30000;
const installed=new WeakSet();
const fail=message=>{throw Object.assign(new Error(message),{status:409,code:'WORLD_BUSY'});};
const publishing=world=>!!world.data.customMaps?.isPublishing;

export function installCustomMapWorld(world){
 if(installed.has(world))return world;
 installed.add(world);
 const tick=world.tick;
 world.tick=function(){
  // Freeze all simulation for the short filesystem commit. This also covers
  // cross-map party rewards, monster attacks and autonomous skill callbacks.
  if(publishing(this)){this.lastTick=this.now();return;}
  // The server-owned deadline cannot be extended by polling or forged acks.
  // Revoke and durably disconnect at the safe committed position on timeout.
  for(const p of this.players.values())if(p.customMapPending&&this.now()>=p.customMapPending.deadline){p.customMapPending=null;p.sceneTransition=false;p.revoked=true;p.leaving=true;p.lastSave=this.now()-5000;}
  return tick.call(this);
 };
 const publicPlayer=world.publicPlayer;
 world.publicPlayer=function(p,self=false){const result=publicPlayer.call(this,p,self);if(self)result.customMapPending=p.customMapPending?{...p.customMapPending}:null;return result;};
 for(const method of ['action','_join','detachPlayer','close']){
  const original=world[method];
  world[method]=function(...args){
   if(publishing(this))return Promise.reject(Object.assign(new Error('Map publication is in progress. Retry after it finishes.'),{status:409,code:'WORLD_BUSY'}));
   return original.apply(this,args);
  };
 }
 return world;
}

function point(map,actor){
 if(map.isWalkable(actor.x,actor.z))return {x:actor.x,z:actor.z};
 const near=map.nearest(actor.x,actor.z),at=near||map.start;
 if(!at||!map.isWalkable(at.x,at.z))fail('No safe relocation point is available.');
 return {x:at.x,z:at.z};
}
const sameSpawn=(a,b)=>a&&a.monsterIndex===b.monsterIndex&&a.home?.x===b.x&&a.home?.z===b.z&&a.respawnSec===b.respawnSec;

/** Prepare without exposing new geometry/positions. Failure leaves old state intact. */
export async function prepareCustomMapUpdate(world,index,map,spawns){
 let occupants=[...world.players.values()].filter(p=>Number(p.map)===index);
 if(!installed.has(world)){
  if(occupants.length)fail('This map has connected players. Live publication is unavailable on this server.');
  return null;
 }
 // The deployment flag is already set, so tick cannot enqueue new saves.
 await world.saveQueue;
 occupants=[...world.players.values()].filter(p=>Number(p.map)===index);
 const scenes=[...world.maps].filter(([,scene])=>Number(scene.index)===index);
 if(scenes.some(([,scene])=>scene.instanceId)||occupants.some(p=>p.instanceId))fail('Instanced custom scenes cannot be replaced live.');
 for(const p of occupants){
  // These services retain targets/cells or pending reward state. Reject until
  // settled instead of discarding effects, currency, summoned actors or loot.
  const skills=p._skills;
  if(p.sceneTransition||p.progressCommitting||p.tradeCommitting||p.tradeId||fishingBusy(p)||p.smartWarp||p.pet||p.mount||skills?.engine?.casting||skills?.engine?.active||skills?.engine?.queued||skills?.engine?.remotes?.list?.length||skills?.summons?.all?.().length||skills?.summons?.totems?.length||skills?.summons?._respawn?.length)
   fail('A player has an active cast, projectile, summon, pet, mount, trade, fishing or travel service. Finish it before publishing live.');
 }
 if(scenes.length>1)fail('Unexpected duplicate custom scenes.');
 const oldScene=scenes[0]?.[1],monsters=new Map(),monsterMoves=[],placements=occupants.map(p=>({p,at:point(map,p),pending:{index,revision:map.customRevision,generation:randomUUID()}}));
 for(const spawn of spawns){
  const def=world.data.monsterDef(spawn.monsterIndex);
  if(!def||def.role==='object'||def.role==='invisible')continue;   // role 'invisible' rows are never spawned (client spawner.js parity; see monster-rules.js isNonCombatant)
  const old=oldScene?.monsters.get(spawn.id);
  if(sameSpawn(old,spawn)){monsters.set(spawn.id,old);monsterMoves.push({actor:old,at:point(map,old),home:old.home});}
  else monsters.set(spawn.id,{...spawn,id:spawn.id,instanceId:null,map:index,name:def.name,hp:def.hp,maxHp:def.hp,home:{x:spawn.x,z:spawn.z},dead:false,targetId:null,attackAt:0,respawnAt:0,def});
 }
 // Dynamically summoned/GM actors are not part of the authored spawn set.
 // Preserve them and their combat state; special scripted objects need their
 // owner-specific collision/state update and are refused for this operation.
 for(const [id,actor]of oldScene?.monsters||[]){
  if(id.startsWith(`${index}:custom:`))continue;
  if(actor.isBrick||actor.eventMarch||actor.boxOwner)fail('A scripted map actor prevents live replacement.');
  monsters.set(id,actor);monsterMoves.push({actor,at:point(map,actor),home:point(map,actor.home||actor)});
 }
 const drops=[...(world.groundLoot?.values()||[])].filter(d=>Number(d.map)===index).map(d=>({d,at:point(map,d)}));
 const scene={...map,index,instanceId:null,monsters};
 return {
  occupants:placements.length,relocated:placements.filter(({p,at})=>p.x!==at.x||p.z!==at.z).length,
  // Only plain assignments/Map writes occur after the durable manifest commit.
  commit(){
   if(oldScene||occupants.length)world.maps.set(index,scene);
   for(const {actor,at,home}of monsterMoves){actor.x=at.x;actor.z=at.z;actor.home=home;actor.anchor=null;actor.targetId=null;}
   const deadline=world.now()+CUSTOM_MAP_READY_MS;
   for(const {p,at,pending}of placements){p.x=at.x;p.z=at.z;p.path=[];pending.deadline=deadline;p.customMapPending=pending;p.sceneTransition=true;p.dirty=true;p.revision++;}
   for(const {d,at}of drops){d.x=at.x;d.z=at.z;}
  },
 };
}
