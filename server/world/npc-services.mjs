import {questNpcLayout} from '../../src/systems/quests/npc-layout.js';
import {withChosenPlacements} from '../../src/config/engine-chosen-guild-tournament.js';
import {assertNpcServiceUse} from './npc-service-guard.mjs';
/** Published placement jobs replace the original NPC jobs, including an explicitly empty list. */
export function isCustomScene(world,map){return !!world.data.customMaps?.has?.(map);}
// lane-perf: within one synchronous snapshot broadcast the placements of a map are the same for every viewer (core.mjs
// broadcastMemo); each caller still gets its own array. Outside a broadcast this computes every call, as before.
// STABILITY-PING: original (non-custom) placements depend only on the loaded catalog/quest tables, yet map 150 re-ran
// questNpcLayout for every action reply and snapshot (~3% of the main thread at 100 players). They are cached per loaded
// table set (identity-checked) and shared like the broadcast memo already shares them; custom scenes are never cached.
const STATIC_PLACEMENTS=new WeakMap();
function staticPlacements(world,map){
  const data=world?.data;if(!data||typeof data!=='object'||isCustomScene(world,map))return null;
  const progression=data.progression,npcs=progression?.npcs,quests=progression?.quests;
  let byMap=STATIC_PLACEMENTS.get(data);if(!byMap||byMap.progression!==progression||byMap.npcs!==npcs||byMap.quests!==quests){byMap={progression,npcs,quests,rows:new Map()};STATIC_PLACEMENTS.set(data,byMap);}
  const key=String(map);let rows=byMap.rows.get(key);if(!rows){rows=computeNpcPlacements(world,map);byMap.rows.set(key,rows);}
  return rows;
}
export function npcPlacements(world,map){
  const fixed=staticPlacements(world,map);if(fixed)return fixed.slice();
  if(world?._broadcastMemo&&world.broadcastMemo)return world.broadcastMemo(`npcPlacements:${map}`,()=>computeNpcPlacements(world,map)).slice();
  return computeNpcPlacements(world,map);
}
function computeNpcPlacements(world,map){
  const catalog=world.data.progression?.npcs;
  if(isCustomScene(world,map))return (world.data.customNpcPlacements?.(map)||[]).map(row=>{
    const source=catalog?.npcs?.[row.npcIndex],jobs=row.jobs===undefined?source?.jobs||[]:row.jobs;
    const supported=jobs.filter(([type,index])=>source?.jobs?.some(([t,i])=>Number(t)===Number(type)&&Number(i)===Number(index)));
    return {...row,jobs,roles:[...new Set(supported.map(([type])=>catalog?.jobTypes?.[type]?.name).filter(Boolean))],custom:true};
  });
  const original=withChosenPlacements(map,catalog?.placements?.[map]?.rows||[]).map(([npcIndex,x,z])=>({npcIndex:Number(npcIndex),x:Number(x),z:Number(z),jobs:catalog.npcs?.[npcIndex]?.jobs||[],roles:catalog.npcs?.[npcIndex]?.roles||[],custom:false}));
  if(Number(map)!==150)return original;
  const inferred=questNpcLayout(world.data.progression?.quests,catalog).placements;
  return [...original,...inferred.map(row=>({...row,jobs:catalog.npcs[row.npcIndex]?.jobs||[],roles:catalog.npcs[row.npcIndex]?.roles||[],custom:false}))];
}
export function nearbyNpc(world,p,{npcIndex,role,jobType,jobIndex,radius=12}={}){
  const row=npcPlacements(world,p.map).find(row=>(npcIndex===undefined||row.npcIndex===Number(npcIndex))&&(!role||row.roles.includes(role))&&(jobType===undefined||row.jobs.some(([type,index])=>Number(type)===Number(jobType)&&(jobIndex===undefined||Number(index)===Number(jobIndex))))&&Math.hypot(p.x-row.x,p.z-row.z)<=radius)||null;
  if(row)assertNpcServiceUse(world,p,{jobType});   // guide 62: no NPC use in battle status (npc-service-guard.mjs; only inside a command)
  return row;
}
/** Authored jobs can reuse a supported original table; arbitrary table substitutions need their own integration. */
export function offersOriginalJob(world,row,type,index){
  return row.jobs.some(([t,i])=>Number(t)===Number(type)&&Number(i)===Number(index))&&(!row.custom||world.data.progression?.npcs?.npcs?.[row.npcIndex]?.jobs?.some(([t,i])=>Number(t)===Number(type)&&Number(i)===Number(index)));
}
