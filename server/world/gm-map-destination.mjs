import {commitFieldTravel} from './travel.mjs';
const fail=(status,message)=>{throw Object.assign(new Error(message),{status});};
export async function teleportGM(world,user,input,{revalidate}={}){
  if(!user.capabilities?.includes('gm:commands'))fail(403,'GM permission is required to teleport.');
  if(Object.keys(input).some(k=>!['token','operation','map','x','z'].includes(k))||!Number.isSafeInteger(input.map)||input.map<0||input.map>1000000||![input.x,input.z].every(Number.isFinite))fail(400,'Choose a valid marked map destination.');
  const p=world.lease(user.id,input.token);if(p.instanceId||p.dead||p.sceneTransition||p.tradeId||p.tradeCommitting)fail(409,'Exit the instance or finish the current action before teleporting.');
  if(world.now()-(p.gmRateAt||0)>=1000){p.gmRateAt=world.now();p.gmActions=0;}if((p.gmActions=(p.gmActions||0)+1)>20)fail(429,'Too many GM commands.');
  if(world.data.requiresInstance?.(input.map)||world.data.eventData?.modeOf(input.map))fail(403,'Use the original admission service for this map.');
  const map=await world.map(input.map);world.lease(user.id,input.token);const current=await revalidate?.();if(!current||current.id!==user.id||!current.capabilities?.includes('gm:commands'))fail(403,'GM permission or session changed.');
  if(world.lease(user.id,input.token)!==p||p.instanceId||p.dead||p.sceneTransition||p.tradeId||p.tradeCommitting)fail(409,'The GM character changed while the map loaded.');
  if(input.x<0||input.z<0||input.x>=map.width||input.z>=map.height||!map.isWalkable(input.x,input.z))fail(400,'Mark a walkable location inside the map.');
  await commitFieldTravel(world,p,{map:input.map,x:input.x,z:input.z});
  return {ok:true,message:`Teleported to Map ${p.map} (${p.x.toFixed(1)}, ${p.z.toFixed(1)}).`,destination:{map:p.map,x:p.x,z:p.z},state:world.snapshot(p)};
}
