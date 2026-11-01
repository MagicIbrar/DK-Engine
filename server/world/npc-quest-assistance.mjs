import {createQuestContext} from './quests.mjs';
import {mapFor,sameScene} from './scene.mjs';
import {npcRoutePlan} from './npc-routing.mjs';
import {createNpcApproachCache} from './npc-navigation.mjs';

// ENGINE-CHOSEN explicit cooperative quest guidance.50 is the owner's requested
// native-cell leash (FILE x/z, cellSize1). No human commands/progress are emitted.
export const NPC_QUEST_ASSISTANCE_POLICY=Object.freeze({gap:50,resumeGap:48,motion:.25,stationaryMs:1500,pendingMs:120000,lifetimeMs:1800000,transitionMs:30000,maximum:100});
const distance=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z),ordinaryNpc=p=>/^npc_[a-f0-9]{32}$/.test(p?.account||'')&&p.profile?.authority==='server'&&p.profile?.npcPlayer===true;
const placed=(world,map,npc)=>{const row=world.data.progression?.npcs?.placements?.[map]?.rows?.find(r=>Number(r[0])===Number(npc));return row?{map:Number(map),x:Number(row[1]),z:Number(row[2]),npc:Number(npc)}:null;};
const supported=new Set(['talk','kill','killOnMap','collect']);
export function createNpcQuestAssistance(world,{isNpc=ordinaryNpc,isHuman=p=>!ordinaryNpc(p),policy=NPC_QUEST_ASSISTANCE_POLICY}={}){
 const goals=new Map(),approach=createNpcApproachCache(world.now);let closed=false;
 const current=p=>p&&world.players.get(p.account)===p&&!p.leaving&&!p.revoked&&p.characterId===p.profile?.id;
 const reject=(p,reason)=>{goals.delete(p?.account);return {cancelled:true,waiting:true,stage:'quest assistance ended',reason};};
 function request(p,h,{explicit=false,questId}={}){
  if(closed||explicit!==true||!current(p)||!current(h)||p===h||!isNpc(p)||!isHuman(h)||!sameScene(p,h)||p.dead||h.dead)return false;
  const c=createQuestContext(world,p),ids=c?.engine.activeIds()||[],id=questId==null?ids.find(id=>{const q=c.engine.db.quest(id);return q&&!q.isGroup&&(c.engine.isComplete(id)||(q.objectives||[]).some(o=>supported.has(o.kind)&&!c.engine.objectiveDone(q,o)));}):Number(questId),q=c?.engine.db.quest(id);
  if(!Number.isSafeInteger(id)||!ids.includes(id)||!q||q.isGroup)return false;
  if(goals.has(p.account)){plan(p);const old=goals.get(p.account);if(old)return old.humanAccount===h.account&&old.humanId===h.id&&old.humanToken===h.token&&old.questId===id;}
  if(!goals.has(p.account)&&goals.size>=policy.maximum)return false;
  const now=world.now();goals.set(p.account,{npcId:p.id,npcCharacter:p.characterId,npcToken:p.token,humanAccount:h.account,humanId:h.id,humanCharacter:h.characterId,humanToken:h.token,questId:id,requested:now,pendingUntil:now+policy.pendingMs,until:now+policy.lifetimeMs,partyId:null,position:{x:h.x,z:h.z,movedAt:now},waiting:false,transition:null});return true;
 }
 function plan(p){
  const g=goals.get(p?.account);if(!g)return null;const now=world.now(),h=world.players.get(g.humanAccount);
  if(closed||!current(p)||!current(h)||!isNpc(p)||!isHuman(h)||p.id!==g.npcId||p.characterId!==g.npcCharacter||p.token!==g.npcToken||h.id!==g.humanId||h.characterId!==g.humanCharacter||h.token!==g.humanToken||now>g.until)return reject(p,'The assistance binding is no longer current.');
  if(!p.profile.quests?.active?.[g.questId])return reject(p,'The NPC quest is no longer accepted.');
  const party=p.partyId&&world.parties.get(p.partyId),joined=!!party&&p.partyId===h.partyId&&party.members.includes(p.id)&&party.members.includes(h.id);
  if(g.partyId&&(!joined||g.partyId!==party.id))return reject(p,'The accepted party membership changed.');
  if(!joined){if(now>g.pendingUntil)return reject(p,'The ordinary party invitation was not accepted.');return {waiting:true,stop:!!p.path?.length,stage:'waiting for party acceptance',questId:g.questId};}
  g.partyId=party.id;
  if(!sameScene(p,h)){
   const t=g.transition;if(t&&now<=t.until&&!p.instanceId&&!h.instanceId&&p.map===t.to&&h.map===t.from&&(p.channel||0)===(h.channel||0))return {waiting:true,stop:!!p.path?.length,stage:'waiting at the ordinary arrival',questId:g.questId};
   return reject(p,'The teammate is in a different map, channel or private instance.');
  }
  g.transition=null;
  if(p.dead||h.dead||p.sceneTransition||h.sceneTransition||p.tradeId||p.tradeCommitting||p.pcShopOpen||p.commandActive||p.progressCommitting||p._skills?.engine?.casting||p._skills?.engine?.active)return {waiting:true,stop:!!p.path?.length,stage:'waiting for the teammate or current native action',questId:g.questId};
  const moved=distance(h,g.position)>policy.motion;if(moved){g.position={x:h.x,z:h.z,movedAt:now};}
  const gap=distance(p,h);if(g.waiting&&gap<policy.resumeGap)g.waiting=false;
  if(gap>=policy.gap&&!moved&&now-g.position.movedAt>=policy.stationaryMs)g.waiting=true;
  if(g.waiting)return {waiting:true,stop:!!p.path?.length,stage:'waiting for you to catch up',questId:g.questId,gap};
  const c=createQuestContext(world,p),q=c?.engine.db.quest(g.questId);if(!q||q.isGroup||!c.engine.isActive(g.questId))return reject(p,'The NPC quest is no longer accepted.');
  const complete=c.engine.isComplete(q.id),o=complete?null:(q.objectives||[]).find(o=>!c.engine.objectiveDone(q,o));
  let at,action,targetId,stage;
  if(complete||o?.kind==='talk'){
   const who=complete?q.turnIn||q.giver:o.targets?.[0];at=placed(world,Number(who?.map??q.giver?.map??p.map),Number(complete?who?.npc:who?.id));
   if(!at)return {waiting:true,blockedReason:'No actual native NPC placement binds this objective.',stage:'quest objective unavailable',questId:q.id};
   stage=complete?'walking to turn in my quest':'leading to a quest NPC';
   if(at.map===p.map&&distance(p,at)<=7){if(complete&&q.rewardVariants?.mode==='choice')return {waiting:true,blockedReason:'The native reward requires the existing choice handler.',stage:'waiting for the native reward choice',questId:q.id,at};action={type:'quest',operation:complete?'claim':'talk',questId:Number(q.id),npc:at.npc};}
  }else if(o&&['kill','killOnMap','collect'].includes(o.kind)){
   const ids=new Set((o.kind==='collect'?[...(q.drops||[]).filter(d=>(o.targets||[]).some(t=>Number(t.id)===Number(d.item))).flatMap(d=>d.monsters||[]),...(o.sources?.monsters||[]).map(r=>r[0])]:(o.targets||[]).map(t=>t.id)).map(Number));
   const map=mapFor(world,p);let target=null;
   for(const m of map?.monsters.values()||[])if(!m.dead&&!m.isBrick&&!m.eventObject&&m.def?.role==='creature'&&(o.map==null||Number(o.map)===p.map)&&(o.kind==='killOnMap'?ids.has(p.map):ids.has(Number(m.monsterIndex)))&&(!target||distance(p,m)<distance(p,target)))target=m;
   if(target){at={map:p.map,x:target.x,z:target.z};targetId=target.id;stage=o.kind==='collect'?'looking for quest items':'leading to a quest enemy';}
   else{
    const destination=Number(o.map??(o.kind==='killOnMap'?o.targets?.[0]?.id:o.targets?.find(t=>t.map!=null)?.map));
    const spawn=Number.isFinite(destination)&&destination!==p.map&&(world.data.spawns?.(destination)||[]).find(s=>o.kind==='killOnMap'?world.data.monsterDef?.(s.monsterIndex)?.role==='creature':ids.has(Number(s.monsterIndex)));
    if(spawn){at={map:destination,x:Number(spawn.x),z:Number(spawn.z)};stage='leading to the native quest area';}
    else return {waiting:true,blockedReason:'No current native enemy or verified spawn location binds this objective.',stage:'waiting for a quest target',questId:q.id};
   }
  }else return {waiting:true,blockedReason:'This objective needs its existing native script or skill handler.',stage:'quest objective unavailable',questId:q.id};
  if(at.map!==p.map){
   if(p.instanceId)return {waiting:true,blockedReason:'Use the existing private-instance admission or exit.',stage:'waiting for ordinary admission',questId:q.id};
   const route=npcRoutePlan(world,p,at);if(route.blockedReason||route.route?.some(e=>e.action?.operation==='dkenter'))return {waiting:true,blockedReason:route.blockedReason||'This native route dissolves the current party.',stage:'waiting for an ordinary party route',questId:q.id};
   at=route.at;action=route.action;if(action){const edge=route.route?.[0];if(edge)g.transition={from:p.map,to:edge.to,until:now+policy.transitionMs};}
  }
  if(!action){const radius=targetId?Math.min(8,p.stats?.attackRange||5)+.3:at.npc?7:1,reachable=approach(mapFor(world,p),p,at,radius);if(!reachable)return {waiting:true,blockedReason:'No ordinary native path reaches this quest goal.',stage:'waiting for a reachable quest goal',questId:q.id};at={...at,x:reachable.x,z:reachable.z};}
  return {stage,questId:q.id,at,action,targetId,waiting:false,context:{accepted:true,objectiveKind:o?.kind||'turnIn',objectiveSlot:o?.slot??null},gap};
 }
 return {request,plan,cancel(p){return goals.delete(typeof p==='string'?p:p?.account);},snapshot(){return [...goals.values()].map(g=>({npcId:g.npcId,humanId:g.humanId,questId:g.questId,partyId:g.partyId,waiting:g.waiting}));},dispose(){closed=true;goals.clear();}};
}
