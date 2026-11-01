// ENGINE-CHOSEN autonomous combat scheduling through the ordinary skill queue.
// No public input, actor stats, costs, cooldowns, authored phases or engine flags are changed here.
import {sameScene,mapFor} from './scene.mjs';
import {npcImmediateThreat} from './npc-combat-intel.mjs';
import {findWorldPlayer} from './actor-lookup.mjs';
const distance=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);

export function npcRememberCombatStart(p,b,target,engine,forced=false){
 const a=engine.active;if(!a)return;const world=engine.game?._world,party=p.partyId&&world?.parties?.get(p.partyId),instance=p.instanceId&&world?.instances?.get(p.instanceId);
 b.combatQueueIntent={player:p,session:p.token,engine,activeId:a.id,target,map:p.map,instanceId:p.instanceId||null,channel:p.channel||0,forced,partyId:p.partyId||null,partyLeader:party?.leader,questId:b.questId,follow:b.follow,partyFollow:b.partyFollow,desiredChannel:b.desiredChannel,instance,eventRun:instance?.run,eventPhase:instance?.run?.phase,eventEnded:instance?.ended,mode:b.mode,task:b.taskGoal,taskKind:b.taskGoal?.kind,taskMap:b.taskGoal?.map,brainTarget:b.target,farmTarget:b.farmTarget};
}

// Reservation follows one unchanged combat objective, including native teams.
// Changed plans and higher-priority custody invalidate it. The health/mana thresholds are the existing support/recovery gates.
export function npcQueuePriorityReady(world,p,b,intent){
 const now=world.now(),hpMax=p.maxHp||p.stats.maxHp||1,mpMax=p.stats.maxMp||0;
 if(p.hp<hpMax*.65||mpMax>0&&p.mp<mpMax*.25||p.sceneTransition||p.progressCommitting||p.tradeId||p.pcShopOpen||p.smartWarp||p.duelId||p.pvpRestore||p.pvpLastHit&&now-Number(p.pvpLastHit.at)<10000)return false;
 const party=p.partyId&&world.parties?.get(p.partyId),instance=p.instanceId&&world.instances?.get(p.instanceId);
 // Let due native event support inspect healing/buffs after this animation,
 // instead of indefinitely extending an offensive chain past its opportunity.
 if(['deadFront','iceCastle'].includes(instance?.kind)&&(!b.eventSupport||now>=b.eventSupport.nextAt))return false;
 if((p.partyId||null)!==intent.partyId||party?.leader!==intent.partyLeader||b.questId!==intent.questId||b.follow!==intent.follow||b.partyFollow!==intent.partyFollow||b.desiredChannel!==intent.desiredChannel||instance!==intent.instance||instance?.run!==intent.eventRun||instance?.run?.phase!==intent.eventPhase||instance?.ended!==intent.eventEnded)return false;
 if(!(['roam'].includes(b.mode)||b.mode==='follow'&&b.partyFollow&&party?.leader===b.follow)||b.mode!==intent.mode||b.follow&&!b.partyFollow||b.closeFollow||b.pull||b.queue?.length||b.duelTarget||b.pkTarget||b.objectiveFlight||b.refineRestore||now<(b.pauseUntil||0)||now<(b.prepareUntil||0)||now<(b.organizerUntil||0))return false;
 if(world.partyInvites?.has(p.id)||world.data.eventData?.modeOf?.(p.map)&&!instance||Number(world.data.mapRow?.(p.map)?.IsSiege)||p.profile.npcEquipment?.phase==='working'||b.routeGoal)return false;
 if(b.taskGoal!==intent.task||b.taskGoal?.kind!==intent.taskKind||b.taskGoal?.map!==intent.taskMap||b.taskGoal&&!['farm','quest','dungeon','event'].includes(b.taskGoal.kind)||b.target!==intent.brainTarget||b.farmTarget!==intent.farmTarget||intent.target?.profile)return false;
 return true;
}

export function npcSettleQueuedCadence(world,p,b,cadence){
 const receipt=b.combatQueuedReceipt,engine=p._skills?.engine;
 if(!receipt)return;
 if(receipt.engine!==engine){delete b.combatQueuedReceipt;return;}
 if(engine.active?.id!==receipt.activeId&&!engine.queued){const started=engine.lastUsed.get(receipt.index);if(Number.isFinite(started)&&started!==receipt.priorStart){b.skillReady=started*1000+cadence(p,b,world.now());
   // Extend only the exact accepted chain after the successor really started.
   // Keep its original goal/session/party context for subsequent cancellation.
   if(engine.active?.skill.index===receipt.index&&b.combatQueueIntent===receipt.intent&&p.token===receipt.intent?.session)b.combatQueueIntent={...receipt.intent,activeId:engine.active.id};
  }delete b.combatQueuedReceipt;}
}

export function createNpcQueueRequester({select,cadence,ready,refusal,priority=npcQueuePriorityReady}){
 return async function npcRequestNextSkill(world,p,b,act){
  npcSettleQueuedCadence(world,p,b,cadence);
  const engine=p._skills?.engine,a=engine?.active,intent=b.combatQueueIntent;
  if(!a||!intent||p.profile?.authority!=='server'||p.profile.npcPlayer!==true||p.dead||p.leaving||world.players.get(p.account)!==p||intent.player!==p||intent.session!==p.token||intent.engine!==engine||intent.activeId!==a.id||intent.map!==p.map||intent.instanceId!==(p.instanceId||null)||intent.channel!==(p.channel||0)||engine.queued||b.combatQueueRequestedId===a.id||!ready(b,world.now()))return false;
  const target=intent.target,isPlayer=!!target?.profile,map=mapFor(world,p);
  const valid=()=>{
   if(!priority(world,p,b,intent))return false;
   if(p.dead||p.leaving||world.players.get(p.account)!==p||p.token!==intent.session||p._skills?.engine!==engine||engine.active?.id!==intent.activeId||p.map!==intent.map||(p.instanceId||null)!==intent.instanceId||(p.channel||0)!==intent.channel||!target||target.dead||target.leaving||target.disposed||!sameScene(p,target)||mapFor(world,p)!==map)return false;
   if(target.isBrick||target.eventObject||target.def?.role!=='creature')return false;
   const party=p.partyId&&world.parties.get(p.partyId);
   // The director's own immediate-threat choice (same helper), so a queued cast follows it.
   const immediateThreat=npcImmediateThreat(world,p,map,party,{lookup:id=>findWorldPlayer(world,id),current:b.intelFocus});
   if(immediateThreat&&immediateThreat!==target)return false;
   return isPlayer?world.players.get(target.account)===target:map?.monsters.get(target.id)===target;
  };
  if(!valid())return false;
  const candidates=select(world,p,b,target,{isPlayer,forced:!!intent.forced,queueNext:true});
  const row=candidates.find(row=>Number(row.skill.index)!==Number(a.skill.index));if(!row)return false;
  // One deliberate ordinary request per active ID, including failed/429 requests.
  b.combatQueueRequestedId=a.id;
  const index=Number(row.skill.index),before=engine.queued,priorStart=engine.lastUsed.get(index),point={x:target.x,z:target.z};
  // Internal pending request survives ordinary per-account serialization. The
  // server validates it at command execution and installs the finish guard
  // synchronously with the real queue acceptance, before the next native tick.
  const pending={index,targetId:target.id,validate:()=>valid()&&engine.active===a&&!engine.queued,
   accepted:()=>{b.combatQueuedReceipt={engine,index,priorStart,activeId:a.id,intent};},
   startGuard:queued=>{
   if(engine.queued!==queued||!valid())return false;
   const actor=queued.opts?.target;
   if(!actor||actor._record!==target||actor.dead||actor.disposed||engine.statuses.flags(actor).target)return false;
   if(map.collision?.lineOfSight&&!map.collision.lineOfSight(p.x,p.z,target.x,target.z))return false;
   const pt=queued.opts?.point;
   if(pt&&(!Number.isFinite(pt.x)||!Number.isFinite(pt.z)||!map.isWalkable(pt.x,pt.z)||map.collision?.lineOfSight&&!map.collision.lineOfSight(p.x,p.z,pt.x,pt.z)))return false;
   const skill=engine.skillDef(index),distance=Math.hypot(p.x-target.x,p.z-target.z),range=Math.max(1.5,Number(skill?.range)||3)+(Number(actor.radius)||.5)+.3;
   return !!skill&&engine.skillLevel(index)>0&&!engine.isPassive(skill)&&distance<=range;
  }};
  engine._npcQueueRequest=pending;
  try{await act(p,{type:'cast',skillId:index,targetId:target.id,x:point.x,z:point.z,...(intent.forced?{forced:true}:{})});}catch(error){if(!error.status)throw error;refusal(world,p,b,target,index,error);return false;}finally{if(engine._npcQueueRequest===pending)delete engine._npcQueueRequest;}
  const queued=engine.queued;
  if(!valid()||!queued||queued===before||queued.index!==index||engine.active!==a||typeof queued.npcStartGuard!=='function')return false;
  b.activity='queueing the next skill';return true;
 };
}
