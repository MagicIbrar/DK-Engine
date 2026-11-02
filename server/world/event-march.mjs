// Host counterpart of MarchBrain (src/systems/events/waves.js). Scripted tower
// attackers follow native walkable paths and periodically reconsider gates.
import {tagMonsterMarch} from './monster-gait.mjs';   // Lane 60: Global MoveDest destination (row.mv)
export function stepEventMarch(world, actor, map, dt, {blocked=false,speedMul=1}={}) {
  const march=actor.eventMarch;
  if(!march)return false;
  if(Math.hypot(actor.x-march.goal.x,actor.z-march.goal.z)<=march.reach) {
    tagMonsterMarch(actor,null,0);
    if(!march.onArrive)return false;
    march.onArrive(actor);
    return true;
  }
  if(blocked||dt<=0||speedMul<=0){tagMonsterMarch(actor,null,0);return false;}
  march.repath=(march.repath||0)-dt;
  if(!march.path||march.repath<=0||march.pi>=march.path.length) {
    march.path=map.path?.(actor.x,actor.z,march.goal.x,march.goal.z)||[march.goal];
    march.pi=0;
    march.repath=4;
  }
  const point=march.path[march.pi];
  if(!point){tagMonsterMarch(actor,null,0);return false;}
  const before={x:actor.x,z:actor.z};
  const moved=world.step(actor,point,march.speed*speedMul,dt,map);if(moved)march.pi++;
  tagMonsterMarch(actor,actor.x===before.x&&actor.z===before.z?null:(march.path[march.pi]||point),march.speed*speedMul);
  actor.home={x:actor.x,z:actor.z};
  march.stuck=Math.hypot(actor.x-before.x,actor.z-before.z)<1e-6?(march.stuck||0)+dt:0;
  if(march.stuck>1.5){march.repath=0;march.stuck=0;}
  return false;
}
