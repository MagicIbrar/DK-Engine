import {setTimeout as pause} from 'node:timers/promises';
import {nearbyNpc,npcPlacements} from './world/npc-services.mjs';
import {mapFor,sceneKey} from './world/scene.mjs';
import {npcNativeRoute} from './world/npc-routing.mjs';

// Ordinary native NPC travel and same-map walking only; no coordinate writes,
// scene entry, tick acceleration or invented placement.
export function createAdminGuildServiceVisit({world,send,wait=pause,shouldYield=()=>false,timeoutMs=60000,pollMs=100}={}){
 if(!world||typeof send!=='function'||typeof wait!=='function'||typeof shouldYield!=='function'||!Number.isInteger(timeoutMs)||timeoutMs<1||timeoutMs>60000||!Number.isInteger(pollMs)||pollMs<1||pollMs>1000)throw Error('Bounded ordinary service visit hooks required.');
 const fail=reason=>{throw Object.assign(Error(reason),{setupReason:reason});};
 const roles=new Set(['GUILD','GUILDMARK','GUILD_ADVERTISE_APPLICATION','GUILD_ADVERTISE_LIST']);
 const live=p=>{if(world.players.get(p.account)!==p||p.leaving||p.dead||p.instanceId||p.sceneTransition)fail('ordinary-service-session-unavailable');};
 return async function visit(p,role){
  if(!roles.has(role))fail('unsupported-guild-service');live(p);if(shouldYield())fail('human-admission-or-setup-budget');
  // Restrict targets to the recovered original placement rows; npcPlacements
  // also contains engine-chosen/inferred rows which are not native evidence.
  const native=world.data.progression?.npcs?.placements?.[p.map]?.rows||[];
  const rows=npcPlacements(world,p.map).filter(row=>!row.custom&&row.roles.includes(role)&&native.some(([id,x,z])=>Number(id)===row.npcIndex&&Number(x)===row.x&&Number(z)===row.z));
  if(!rows.length){
   // A saved founder may be in Deneb, which has an original guild-advertising
   // NPC but no original guild-founding/mark service. Follow one verified native
   // NPC route to Ardeca, paying any authored cost through the normal action.
   // No position, guild, or currency is edited directly.
   const routeOptions={level:Number(p.profile.level)||1,dil:Number(p.profile.dil)||0,maxSteps:1,channel:p.channel||0,origin:p};
   // Prefer a verified free native portal, preserving the exact guild setup budget.
   const route=npcNativeRoute(world.data,p.map,150,{...routeOptions,dil:0})||npcNativeRoute(world.data,p.map,150,routeOptions);
   const edge=route?.[0];
   if(!edge||edge.to!==150||edge.action.type!=='npctravel'||!['portal','teleport'].includes(edge.action.operation))fail('native-service-not-on-current-map');
   const nearEdge=()=>Math.hypot(p.x-edge.at.x,p.z-edge.at.z)<=8;
   await approach(p,edge.at,nearEdge);
   await send(p,edge.action);
   if(p.map!==150)fail('ordinary-service-route-unavailable');
   return visit(p,role);
  }
  const near=()=>rows.some(row=>{const found=nearbyNpc(world,p,{npcIndex:row.npcIndex,role,radius:8});return found&&!found.custom&&found.x===row.x&&found.z===row.z&&Math.hypot(p.x-row.x,p.z-row.z)<=8;});
  return approach(p,rows,near);
 };
 async function approach(p,targets,near){
  if(near())return;
  const map=mapFor(world,p);if(!map?.path||!map.isWalkable)fail('ordinary-service-path-unavailable');
  const rows=Array.isArray(targets)?targets:[targets];
  const goals=rows.sort((a,b)=>Math.hypot(p.x-a.x,p.z-a.z)-Math.hypot(p.x-b.x,p.z-b.z)).map(row=>{
   const at=map.isWalkable(row.x,row.z)?row:map.collision?.nearestWalkable?.(row.x,row.z,3);
   return at&&Math.hypot(at.x-row.x,at.z-row.z)<=3&&map.isWalkable(at.x,at.z)?at:null;
  }).filter(Boolean);
  let goal=goals.find(at=>map.path(p.x,p.z,at.x,at.z)?.length);
  if(!goal)fail('ordinary-service-path-unavailable');
  const scene=sceneKey(p.map,p.instanceId,p.channel||0),started=Date.now();
  let lastX=p.x,lastZ=p.z,replans=0;
  await send(p,{type:'move',x:goal.x,z:goal.z});
  for(let polls=0;polls<Math.ceil(timeoutMs/pollMs)&&Date.now()-started<timeoutMs;polls++){
   live(p);if(sceneKey(p.map,p.instanceId,p.channel||0)!==scene||mapFor(world,p)!==map)fail('ordinary-service-scene-changed');
   if(shouldYield()){await send(p,{type:'stop'});fail('human-admission-or-setup-budget');}
   if(near()){await send(p,{type:'stop'});return;}
   if(!p.path?.length){
    if(++replans>Math.max(6,goals.length*2))fail('ordinary-service-path-stalled');
    const advanced=Math.hypot(p.x-lastX,p.z-lastZ)>=0.1;
    if(!advanced&&goals.length>1){const next=goals[(goals.indexOf(goal)+1)%goals.length];if(next)goal=next;}
    if(!map.path(p.x,p.z,goal.x,goal.z)?.length)fail('ordinary-service-path-stalled');
    lastX=p.x;lastZ=p.z;
    await wait(Math.max(200,pollMs)); // ordinary move intents have a 150 ms host limit
    await send(p,{type:'move',x:goal.x,z:goal.z});
   }
   await wait(pollMs); // The existing host timer advances world ticks.
  }
  live(p);if(sceneKey(p.map,p.instanceId,p.channel||0)===scene&&mapFor(world,p)===map)await send(p,{type:'stop'});
  fail('ordinary-service-visit-timeout');
 }
}
