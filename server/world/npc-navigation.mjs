// ENGINE-CHOSEN NPC goal validation over the unchanged native collision grid.
// PathFinder can return a partial path for an unreachable goal. Such a path is
// usable for a service only if its walkable endpoint reaches that service's
// existing authority radius. This never opens a wall or teleports an actor.
export function npcReachableApproach(map,source,target,radius=1){
 if(!map||![source?.x,source?.z,target?.x,target?.z,radius].every(Number.isFinite)||radius<0)return null;
 const distance=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
 if(distance(source,target)<=radius)return {x:source.x,z:source.z};
 const goal=map.isWalkable?.(target.x,target.z)?target:map.nearest?.(target.x,target.z);
 if(!goal||distance(goal,target)>radius)return null;
 const path=map.path?.(source.x,source.z,goal.x,goal.z),end=path?.at(-1);
 return end&&distance(end,target)<=radius?{x:end.x,z:end.z}:null;
}

// ENGINE-CHOSEN 2 s / 128-entry planning cache. Native .mac cells are 1 unit.
// This memoizes planning only; every issued movement still uses ordinary server
// validation. Map identity, source cell, exact target and authority radius are
// part of the key. Short expiry also releases a negative result after changes.
export function createNpcApproachCache(now){
 const maps=new WeakMap();
 return function approach(map,source,target,radius=1){
  if(!map||![source?.x,source?.z,target?.x,target?.z,radius].every(Number.isFinite)||radius<0)return null;
  if(Math.hypot(source.x-target.x,source.z-target.z)<=radius)return {x:source.x,z:source.z};
  let entries=maps.get(map);if(!entries){entries=new Map();maps.set(map,entries);}
  const key=[Math.floor(source.x),Math.floor(source.z),target.x,target.z,radius].join(':'),stamp=now(),saved=entries.get(key);
  if(saved&&saved.until>stamp)return saved.at&&{...saved.at};
  const at=npcReachableApproach(map,source,target,radius);
  if(entries.size>=128)entries.delete(entries.keys().next().value);
  entries.set(key,{until:stamp+2000,at});return at&&{...at};
 };
}
