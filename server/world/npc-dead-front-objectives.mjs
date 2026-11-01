import {npcEventObjectivePlan} from './npc-event-objectives.mjs';
import {mapFor} from './scene.mjs';
import {createNpcApproachCache} from './npc-navigation.mjs';

// ENGINE-CHOSEN optional scoring strategy. Native placement, channel duration,
// interaction authority and score remain in the unchanged DeadFrontRun.
const caches=new WeakMap();
export function npcDeadFrontObjectivePlan(world,p,options={}){
 const fallback=npcEventObjectivePlan(world,p,options),instance=world.instances?.get(p.instanceId),run=instance?.run;
 const isNpc=options.isNpc||((q)=>!!q.npcPlayer);
 if(!isNpc(p)||p.dead||p.leaving||p.sceneTransition||instance?.kind!=='deadFront'||!run||run.ended||instance.closeRequested||fallback?.waiting||fallback?.action||run.phase!=='fortress'||run.won!=null)return fallback;
 if(!instance.members?.has(p.id)||!instance.admitted?.has(p.characterId))return fallback;
 const info=world.data.eventData.map(instance.map),scene=mapFor(world,p);
 if(!scene||[...scene.monsters.values()].some(m=>!m.dead&&!m.isBrick&&Math.hypot(m.x-p.x,m.z-p.z)<=8))return fallback;
 let approach=caches.get(world);if(!approach){approach=createNpcApproachCache(()=>world.now());caches.set(world,approach);}
 const candidates=(info.objectiveNpcs?.depot||[]).filter(id=>!run.depots.has(id)).map(id=>{
  const row=info.npcs?.find(r=>Number(r[0])===Number(id)),channel=info.deadFront?.depots?.find?.(r=>Number(r[0])===Number(id))||run.M?.depots?.find(r=>Number(r[0])===Number(id));
  return row&&{npc:Number(id),x:Number(row[1])+.5,z:Number(row[2])+.5,seconds:Number(channel?.[2])||10};
 }).filter(at=>at&&Math.hypot(at.x-p.x,at.z-p.z)<=20&&run.phaseT>=at.seconds+30).sort((a,b)=>Math.hypot(a.x-p.x,a.z-p.z)-Math.hypot(b.x-p.x,b.z-p.z));
 for(const target of candidates.slice(0,2)){
  if((instance.channels||[]).some(c=>c.p!==p&&Math.hypot(c.start.x-target.x,c.start.z-target.z)<=8))continue;
  const endpoint=approach(scene,p,target,8);if(!endpoint)continue;
  const near=Math.hypot(target.x-p.x,target.z-p.z)<=8;
  return {stage:'capturing native supply depot',at:{map:p.map,...endpoint,npc:target.npc},action:near?{type:'event',operation:'npc',npc:target.npc,path:[0]}:null};
 }
 return fallback;
}
