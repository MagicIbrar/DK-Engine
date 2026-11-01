// Trusted NPC capacity policy. Native workload acceptance remains a release gate.
// Resource budgets are ENGINE-CHOSEN; no offline or mathematical progress.
export const NPC_CAPACITY_TIERS=Object.freeze([256,512,1249,1250,1500,2500]);
import {npcSlotTarget} from './npc-human-slots.mjs';
export function npcCapacityPolicy(value){
 if(value==null)return null;
 if(!value||typeof value!=='object'||Array.isArray(value))throw Error('Invalid NPC capacity configuration');
 const keys=['actorCap','maxWorkerFields','maxTypedGeometryBytes','maxDecisionsPerCycle','decisionBudgetMs','preloadAdmissionsPerTurn','preloadAdmissionBudgetMs','desiredDecisionMs'];
 if(Object.keys(value).some(k=>!keys.includes(k)))throw Error('Unknown NPC capacity option');
 const {actorCap,maxWorkerFields,maxTypedGeometryBytes,maxDecisionsPerCycle=256,decisionBudgetMs=8,preloadAdmissionsPerTurn=8,preloadAdmissionBudgetMs=8,desiredDecisionMs=750}=value;
 if(!NPC_CAPACITY_TIERS.includes(actorCap))throw Error('Unsupported NPC capacity tier');
 // Caller must supply measured native geometry/resource admission budgets.
 // These upper bounds are defensive ceilings, not tested resource capacity.
 if(!Number.isSafeInteger(maxWorkerFields)||maxWorkerFields<1||maxWorkerFields>128)throw Error('Explicit field budget required');
 if(!Number.isSafeInteger(maxTypedGeometryBytes)||maxTypedGeometryBytes<1||maxTypedGeometryBytes>2*1024*1024*1024)throw Error('Explicit geometry budget required');
 if(!Number.isInteger(maxDecisionsPerCycle)||maxDecisionsPerCycle<1||maxDecisionsPerCycle>1024)throw Error('Invalid decision bound');
 if(!Number.isFinite(decisionBudgetMs)||decisionBudgetMs<1||decisionBudgetMs>16)throw Error('Invalid decision time budget');
 if(!Number.isInteger(preloadAdmissionsPerTurn)||preloadAdmissionsPerTurn<1||preloadAdmissionsPerTurn>16)throw Error('Invalid sequential admission count');
 if(!Number.isFinite(preloadAdmissionBudgetMs)||preloadAdmissionBudgetMs<1||preloadAdmissionBudgetMs>16)throw Error('Invalid soft admission budget');
 if(!Number.isInteger(desiredDecisionMs)||desiredDecisionMs<150||desiredDecisionMs>10000)throw Error('Invalid desired decision cadence');
 return Object.freeze({actorCap,maxWorkerFields,maxTypedGeometryBytes,maxDecisionsPerCycle,decisionBudgetMs,preloadAdmissionsPerTurn,preloadAdmissionBudgetMs,desiredDecisionMs});
}

// ENGINE-CHOSEN optional render cohort; mandatory native actors may exceed it.
export const NPC_OPTIONAL_INTEREST_MAX=512;
export function npcSnapshotInterest(world,viewer,{events=[],mandatory=()=>false}={}){
 if(world.players.get(viewer?.account)!==viewer||viewer.leaving)return null;
 const same=(p)=>Number(p.map)===Number(viewer.map)&&(p.instanceId||null)===(viewer.instanceId||null)&&(!!viewer.instanceId||(p.channel||0)===(viewer.channel||0));
 const actors=[...world.players.values()].filter(p=>!p.leaving&&same(p)),byId=new Map(actors.map(p=>[p.id,p])),ids=new Set(),optional=[];
 const npc=p=>/^npc_[a-f0-9]{32}$/.test(p.account)&&p.profile?.authority==='server'&&p.profile?.npcPlayer===true&&p.characterId===p.profile.id&&p.id===p.account+':'+p.profile.id;
 const add=id=>{if(byId.has(id))ids.add(id);};let areaTimeline=false;
 for(const p of actors){
  if(p===viewer||!npc(p)||p.partyId&&p.partyId===viewer.partyId||p.pcShopOpen||p.tradeId||p.commandActive||p.progressCommitting||p.sceneTransition||mandatory(p))add(p.id);
  if(p.attackTarget){add(p.id);add(typeof p.attackTarget==='string'?p.attackTarget:p.attackTarget.id);}
  // Preserve PvP sources conservatively; no invented expiry for this native record.
  if(p.pvpLastHit?.by){add(p.id);add(p.pvpLastHit.by);}
  const engine=p._skills?.engine;if(engine?.active||engine?.queued)areaTimeline=true;
 }
 // Native area/self/ground recipient modes vary: during a live timeline retain
 // the whole current scene instead of hiding a possible recipient/telegraph.
 if(areaTimeline)for(const p of actors)add(p.id);
 for(const e of events)for(const id of [e.actorId,e.sourceId,e.targetId,e.sellerId])add(id);
 const map=world.maps.get(viewer.instanceId?Number(viewer.map)+'@'+viewer.instanceId:viewer.channel?Number(viewer.map)+'#'+viewer.channel:Number(viewer.map));
 for(const m of map?.monsters?.values()||[])if(!m.dead&&m.targetId)add(m.targetId);
 for(const p of actors)if(!ids.has(p.id)){const distance=Number.isFinite(p.x)&&Number.isFinite(p.z)&&Number.isFinite(viewer.x)&&Number.isFinite(viewer.z)?(p.x-viewer.x)**2+(p.z-viewer.z)**2:Infinity;optional.push({p,distance});}
 optional.sort((a,b)=>a.distance-b.distance||(a.p.id<b.p.id?-1:a.p.id>b.p.id?1:0));
 for(const {p}of optional.slice(0,NPC_OPTIONAL_INTEREST_MAX))add(p.id);
 return ids;
}

// One trusted fence shared by every director/scheduler actor admission producer.
// Geometry leases do not reserve actor slots. Tickets remain owned through actual
// commit/publication; already-materialized matching actors consume their one slot.
export function createNpcAdmissionFence({world,profiles,actorCap,enabled}){
 if(!(world?.players instanceof Map)||!(profiles?.profiles instanceof Map)||!NPC_CAPACITY_TIERS.includes(actorCap)||typeof enabled!=='function')throw Error('Invalid NPC admission fence');
 const tickets=new Map();
 const canonical=(account,p)=>{const profile=profiles.profiles.get(account);return /^npc_[a-f0-9]{32}$/.test(account)&&p?.account===account&&p.profile?.authority==='server'&&p.profile?.npcPlayer===true&&profile?.authority==='server'&&profile?.npcPlayer===true&&typeof profile.id==='string'&&p.profile.id===profile.id&&p.characterId===profile.id&&p.id===account+':'+profile.id&&Number.isInteger(p.map);};
 const physical=()=>[...world.players].filter(([a,p])=>canonical(a,p)).length;
 const materialized=t=>{const p=world.players.get(t.account);return canonical(t.account,p)&&p.characterId===t.characterId;};
 const pending=()=>[...tickets.values()].filter(t=>!materialized(t)).length;
 const used=()=>physical()+pending();
 const target=()=>npcSlotTarget(world,actorCap);
 return Object.freeze({
  used,pending,
  reserve(account,characterId){const profile=profiles.profiles.get(account);if(!enabled())return null;
   if(!/^npc_[a-f0-9]{32}$/.test(account)||typeof characterId!=='string'||profile?.id!==characterId||profile.authority!=='server'||profile.npcPlayer!==true||world.players.has(account)||tickets.has(account)||used()>=target())return null;
   const owner={account,characterId};tickets.set(account,owner);
   return Object.freeze({account,characterId,valid:()=>enabled()&&tickets.get(account)===owner&&profiles.profiles.get(account)?.id===characterId&&profiles.profiles.get(account)?.authority==='server'&&profiles.profiles.get(account)?.npcPlayer===true&&used()<=target(),release:()=>{if(tickets.get(account)===owner)tickets.delete(account);}});
  },
  snapshot:()=>({actorCap,physical:physical(),pending:pending(),used:used(),held:tickets.size})
 });
}
