import {destinationAllowed,travelLocation} from './travel.mjs';
import {assertNieteService} from './niete-services.mjs';
import {channelData} from './channels.mjs';
import {dkMap,dkLocates,isDkChannel} from '../../src/systems/channels/channel-rules.js';

// ENGINE-CHOSEN path selection: shortest available ordinary field/DK route (12
// transitions maximum). Every edge retains its native placement/job/table/cost;
// executing its command still goes through world.action and current host guards.
const validAt=a=>a&&[a.map,a.x,a.z].every(Number.isFinite);
function field(world,p,at){
 const mode=world.data.eventData?.modeOf(at?.map);
 if(!validAt(at)||world.data.requiresInstance?.(at.map)||mode&&!mode.endsWith('Lobby'))return false;
 try{return destinationAllowed(world,p,at)==='field';}catch{return false;}
}
export function npcRoutingEdges(data,map){
 const world={data},out=[];
 for(const g of data.gates?.(Number(map))||[]){if(!g.box||!validAt(g.to))continue;
  out.push({from:Number(map),to:g.to.map,at:{map:Number(map),x:(g.box[0]+g.box[2])/2,z:(g.box[1]+g.box[3])/2},box:g.box,exclusive:!!g.exclusive,cost:0,level:0,action:{type:'travel',map:g.to.map},arrival:g.to,provenance:'native field gate'});
 }
 const tr=data.travelData,catalog=data.progression?.npcs;if(!tr||!catalog)return out;
 // Raw native placements only: do not promote inferred or Map Builder NPCs to
 // transport connections. Job ownership is revalidated by travelCommand.
 for(const [id,x,z] of catalog.placements?.[map]?.rows||[])for(const [type,table] of catalog.npcs?.[id]?.jobs||[]){
  const at={map:Number(map),x:Number(x),z:Number(z),npc:Number(id)};if(!validAt(at))continue;
  if(Number(type)===2||Number(type)===42){const t=Number(type)===2?tr.teleports?.[table]:tr.skyTeleports?.find(t=>Number(t.id)===Number(table));
   for(const row of t?.units||[]){const arrival=travelLocation(world,row.location),cost=Number(row.cost)||0;if(!validAt(arrival)||!Number.isFinite(cost)||cost<0)continue;
    const requirements=Number(type)===42?{skyQuest:Number(t.skyQuest)||0,unitSkyQuest:Number(row.skyQuest)||0}:null;
    out.push({from:Number(map),to:arrival.map,at,cost,level:Number(row.level)||0,arrival,requirements,unverifiedUnlock:!!requirements&&(requirements.skyQuest!==0||requirements.unitSkyQuest!==0),action:{type:'npctravel',operation:Number(type)===2?'teleport':'sky',npcIndex:Number(id),table:Number(table),unit:Number(row.unit)},provenance:'native placed NPC job and teleport unit'});
   }
  }else if(Number(type)===96){
   // DK entry is a distinct, ordinary channel service, not a field warp. Use
   // the full NPC catalog: events.ev.npcs intentionally omits normal portals.
   const channels=channelData(world),row=dkMap(channels,Number(table));
   if(!row||row.costItems.length||row.cashCostItems.length)continue;
   for(const pick of dkLocates(channels,Number(table))){const arrival={map:Number(table),x:Number(row.locate[0])+.5,z:Number(row.locate[1])+.5,channel:pick.channel};if(!validAt(arrival))continue;
    out.push({from:Number(map),to:arrival.map,at,cost:0,level:0,arrival,requirements:{leavesFieldParty:true},action:{type:'channel',operation:'dkenter',npcIndex:Number(id),locate:pick.index},provenance:'native placed NPC job96 and dkmaplist locate'});
   }
  }else if(Number(type)===16&&data.dungeonCatalog?.maps?.[map]?.flags?.portal!==0){
   for(const portal of tr.portals||[]){const r=tr.portalArrivals?.find(r=>Number(r.map)===Number(portal.map));if(!r)continue;const arrival={map:Number(r.map),x:Number(r.x)+.5,z:Number(r.y)+.5,dirDeg:Number(r.dir)||0};if(!validAt(arrival))continue;
    out.push({from:Number(map),to:arrival.map,at,cost:0,level:0,arrival,action:{type:'npctravel',operation:'portal',npcIndex:Number(id),table:Number(table),map:arrival.map},provenance:'native placed NPC portal job and portal arrival'});
   }
  }
 }
 return out;
}
// LANE1-PERF: edges are a pure function of the loaded native tables, so they are
// cached per data object and map, and dropped when the custom-map library
// revision changes (published custom portals) or invalidateNpcRoutingEdges runs.
// The public npcRoutingEdges above stays uncached; returned routes are cloned so
// callers never share cached edge objects.
const ROUTING_EDGE_CACHE=new WeakMap();
function cachedRoutingEdges(data,map){
 if(!data||typeof data!=='object')return npcRoutingEdges(data,map);
 const revision=data.customMaps?.revision??0;let cache=ROUTING_EDGE_CACHE.get(data);
 if(!cache||cache.revision!==revision){cache={revision,byMap:new Map()};ROUTING_EDGE_CACHE.set(data,cache);}
 const key=Number(map);let edges=cache.byMap.get(key);if(!edges){edges=npcRoutingEdges(data,map);cache.byMap.set(key,edges);}return edges;
}
export function invalidateNpcRoutingEdges(data){if(data&&typeof data==='object')ROUTING_EDGE_CACHE.delete(data);}
export function npcNativeRoute(data,from,to,{level=1,dil=0,maxSteps=12,channel=0,origin}={}){
 from=Number(from);to=Number(to);if(from===to)return [];
 const world={data},p={profile:{level}},queue=[{map:from,path:[],cost:0,channel}],best=new Map([[`${from}#${channel}`,0]]);let head=0;
 while(head<queue.length){const q=queue[head++];if(q.path.length>=Math.min(12,maxSteps))continue;
  // First-hop proximity chooses between otherwise ordinary routes with the
  // same number of transitions. It does not waive a fee or native guard.
  // This avoids walking to a distant field gate when a nearby eligible
  // portal already reaches the teammate's destination.
  let edges=cachedRoutingEdges(data,q.map);if(!q.path.length&&Number.isFinite(origin?.x)&&Number.isFinite(origin?.z))edges=edges.slice().sort((a,b)=>Math.hypot(a.at.x-origin.x,a.at.z-origin.z)-Math.hypot(b.at.x-origin.x,b.at.z-origin.z));
  for(const edge of edges){const cost=q.cost+edge.cost;
   if(edge.unverifiedUnlock||level<edge.level||cost>dil||!field(world,p,edge.arrival)||edge.action.type==='travel'&&data.eventData?.modeOf(edge.to)||edge.action.operation==='dkenter'&&isDkChannel(q.channel))continue;
   const path=[...q.path,edge];if(edge.to===to)return structuredClone(path);
   const nextChannel=edge.arrival.channel??(isDkChannel(q.channel)?0:q.channel),key=`${edge.to}#${nextChannel}`;
   if(best.has(key)&&best.get(key)<=cost)continue;best.set(key,cost);queue.push({map:edge.to,path,cost,channel:nextChannel});
  }
 }
 return null;
}
export function npcRoutePlan(world,p,to){
 const blockedReason=p.instanceId?'Use the current instance admission/exit.':p.dead||p.mount||p.sceneTransition?'Travel is unavailable in the current actor state.':null;
 if(blockedReason)return{at:null,action:null,blockedReason};
 if(to.map==null||Number(to.map)===Number(p.map)){
  // A coordinate on another channel is another scene. DK entry/return require
  // their placed native portals; walking cannot perform a channel transition.
  if(to.channel!=null&&(to.channel||0)!==(p.channel||0))return{at:null,action:null,blockedReason:'The target is on another channel; use a supported native channel transition.',route:[]};
  return{at:{...to,map:p.map},action:null,blockedReason:null,route:[]};
 }
 const route=npcNativeRoute(world.data,p.map,to.map,{level:Number(p.profile.level)||1,dil:Number(p.profile.dil)||0,channel:p.channel??0,origin:p});
 if(!route?.length)return{at:null,action:null,blockedReason:'No affordable native ordinary field route meets the current level/admission requirements.'};
 const edge=route[0];if(edge.action.type==='npctravel'||edge.action.type==='channel'){try{assertNieteService(world,p);}catch(e){return{at:null,action:null,blockedReason:e.message};}}
 const near=edge.box?p.x>=edge.box[0]&&p.z>=edge.box[1]&&p.x<edge.box[2]+(edge.exclusive?0:1)&&p.z<edge.box[3]+(edge.exclusive?0:1):Math.hypot(p.x-edge.at.x,p.z-edge.at.z)<=8;
 return{at:edge.at,action:near?{...edge.action}:null,blockedReason:null,route};
}
