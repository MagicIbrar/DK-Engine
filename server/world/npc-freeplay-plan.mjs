import {npcNativeRoute} from './npc-routing.mjs';
import {isDkChannel} from './channels.mjs';

export const NPC_FREEPLAY_POLICY=Object.freeze({scan:2,routeChecks:2,retryMs:15000});
const integer=n=>Number.isSafeInteger(n)&&n>=0;
const publicMap=(data,map,level)=>{const row=data.mapRow?.(map);return integer(map)&&row&&!data.requiresInstance?.(map)&&!data.eventData?.modeOf?.(map)&&!Number(row.IsSiege)&&level>=(Number(row.LimitMinLevel)||1)&&level<=(Number(row.LimitMaxLevel)||data.maxLevel);};
const farm=(area,level)=>{if(!(area?.farmLevels instanceof Set))return false;for(let n=level-8;n<=level+8;n++)if(area.farmLevels.has(n))return true;return false;};
function protectedWork(world,p,b){
 const active=Object.keys(p.profile.quests?.active||{}),questFallback=b.questUnavailable?.map===p.map&&active.includes(String(b.questUnavailable.questId));
 if(world.players?.get(p.account)!==p||p.profile?.authority!=='server'||p.profile?.npcPlayer!==true||p.npcPlayer!==true||p.dead||p.leaving||p.revoked||p.instanceId||isDkChannel(p.channel)||p.mount||p.sceneTransition||p.commandActive||p.progressCommitting||p.attackTarget||p._skills?.engine.casting||p.tradeId||p.pcShopOpen||p.path?.length||b.objectiveFlight||b.refineRestore||p.profile.npcEquipment?.phase==='working'||b.follow||!questFallback&&(b.questId||active.length))return true;
 // Admission and membership belong to the ordinary party/event handlers.
 if(p.partyId||world.partyInvites?.get(p.id)?.expires>world.now()||[...(world.partyInvites||[])].some(([,i])=>i.party===p.partyId&&i.expires>world.now()))return true;
 return false;
}
/** Pure bounded intentions over PREPARED native metadata. Caller owns state
 * publication, ordinary quest eligibility, movement, commerce and persistence.
 * areas: Map<map,{farmLevels:Set<positive-XP ordinary native creature level>}>;
 * maps: fixed native public map index array. Never loads geometry or earns XP.
 * localQuest/localCommerce are caller-verified current executable plans.
 * farmLevels may be prepared once from data.spawns/monsterDef, never invented.
 */
export function npcFreeplayPlan({world,player:p,brain:b={},catalog,state={},localQuest=null,localCommerce=null,now=world?.now?.()}={}){
 if(!world?.data||!p||!Number.isFinite(now)||protectedWork(world,p,b))return null;
 const data=world.data,level=Number(p.profile.level),cap=Number(data.maxLevel);
 if(!Number.isInteger(level)||!Number.isInteger(cap)||!publicMap(data,p.map,level)||!(catalog?.areas instanceof Map)||!Array.isArray(catalog.maps))return null;
 const policy=p.profile.npcLongTermGoal?.kind==='freeplay'||level>=cap?'freeplay':'progress';
 const key=JSON.stringify([p.map,p.channel??0,level,p.profile.dil||0,policy,catalog.revision??null]);
 const structureKey=JSON.stringify([p.map,p.channel??0,level,policy,catalog.revision??null]);
 // Resource changes invalidate retry/affordability, not fair scan history or
 // the selected intention. Migrate older persisted keys without trusting fees.
 let savedStructure=state.structureKey;
 if(savedStructure===undefined&&typeof state.key==='string'&&state.key.length<=512){try{const k=JSON.parse(state.key);if(Array.isArray(k)&&k.length===6)savedStructure=JSON.stringify([k[0],k[1],k[2],k[4],k[5]]);}catch{}}
 const previous=savedStructure===structureKey?state:{},seed=Number(p.profile.npcSeed?.slot);
 const next={key,structureKey,cursor:integer(state.cursor)?state.cursor:integer(seed)?seed:0,retryAt:previous.key===key?Number(previous.retryAt)||0:0};
 if(integer(previous.destinationMap))next.destinationMap=previous.destinationMap;
 const result=(kind,extra={})=>({kind,policy:'ENGINE-CHOSEN finite intention; ordinary native actions only',mode:policy,nextState:{...next},...extra});
 if(localQuest?.verified===true&&Number.isSafeInteger(localQuest.questId)&&localQuest.map===p.map)return result('local',{task:'quest',questId:localQuest.questId,reason:'Caller-verified eligible local native quest'});
 if(policy==='progress'&&farm(catalog.areas.get(p.map),level))return result('local',{task:'farm',reason:'Prepared ordinary positive-XP native creature level band; live target/path still required'});
 if(localCommerce?.verified===true&&localCommerce.map===p.map)return result('local',{task:'merchant',reason:'Caller-verified executable owned-stock native commerce'});
 if(policy==='freeplay')return result('local',{task:'rest',reason:'No supplied executable local freeplay objective; no reward inferred'});
 // A selected destination is revalidated against current native metadata and
 // ordinary route authorities. Never reuse stale affordability/unlock proof.
 const destination=previous.destinationMap;
 if(destination!==p.map&&publicMap(data,destination,level)&&farm(catalog.areas.get(destination),level)){
  const route=npcNativeRoute(data,p.map,destination,{level,dil:Number(p.profile.dil)||0,channel:p.channel??0,origin:p});
  if(route?.length){next.destinationMap=destination;return result('route',{destinationMap:destination,reason:'Existing native feasible onward intention',route});}
 }
 if(now<next.retryAt)return result('wait',{reason:'Bounded retry after unsuccessful metadata scan'});
 // Keep route searches within the same two-candidate limit. A revalidation
 // consumes one search even when its route became unavailable.
 let routeChecks=destination!==undefined?1:0,scanned=0;
 for(let n=0;n<NPC_FREEPLAY_POLICY.scan&&scanned<catalog.maps.length;n++){
  const size=Math.max(1,catalog.maps.length),index=next.cursor%size,map=catalog.maps[index];next.cursor=next.cursor<Number.MAX_SAFE_INTEGER?next.cursor+1:index+1;scanned++;
  if(map===p.map||!publicMap(data,map,level)||!farm(catalog.areas.get(map),level))continue;
  if(routeChecks>=NPC_FREEPLAY_POLICY.routeChecks)break;routeChecks++;
  const route=npcNativeRoute(data,p.map,map,{level,dil:Number(p.profile.dil)||0,channel:p.channel??0,origin:p});
  if(route?.length){next.destinationMap=map;return result('route',{destinationMap:map,reason:'Native affordable level-eligible ordinary onward route',route});}
 }
 next.retryAt=now+NPC_FREEPLAY_POLICY.retryMs;return result('wait',{scanned,routeChecks,reason:'No feasible onward objective in bounded metadata slice; no progress inferred'});
}
