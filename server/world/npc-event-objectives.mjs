import {npcEventPartyFocus} from './npc-event-party-focus.mjs';
import {npcDeadFrontTargetPriority} from './npc-dead-front-target-priority.mjs';
import {mapFor} from './scene.mjs';
// Lane 68: the Ice Castle paw near-monster radius (engine-chosen, no source) was removed with the run's refusal.
import {canClaimDeadFrontTreasure} from './dead-front-treasure.mjs';
import {createNpcApproachCache} from './npc-navigation.mjs';
import {npcEventWalkStage} from './npc-chain-fire-attendance.mjs';

// ENGINE-CHOSEN wave target choice (3.1.2). The straight-line nearest wave can
// stand behind an authored barrier (native Dead Front canyon gates): choosing
// it left a whole team idle at its start. Prefer a wave already engaging this
// team, else the nearest wave the unchanged bounded native search reaches; a
// cluster that failed once is not re-searched in the same decision. At most
// `pathChecks` ordinary searches per decision; a reachable choice is kept for
// `memoMs`. Movement, combat validation, collision and barriers are unchanged.
// The fallback staged step is the existing npcEventWalkStage (one search plus
// at most two waypoint approach searches); its decision is also kept memoMs.
export const NPC_EVENT_TARGET_POLICY=Object.freeze({pathChecks:4,stageSearches:3,clusterRadius:6,engagedRange:25,directReach:8,memoMs:3000,approachRadius:1});
const approaches=new WeakMap(),memos=new WeakMap(),objectiveMemos=new WeakMap();
// DF interaction positions can require more than the native bounded search
// reaches in one call. A staged point is a walking intent only; the unchanged
// service radius decides when a real lever/slate/book/wall action is available.
// ENGINE-CHOSEN navigation policy, not a recovered Global bot algorithm.
function deadFrontInteraction(world,p,instance,scene,choices){
 const P=NPC_EVENT_TARGET_POLICY,now=world.now(),near=a=>Math.hypot(p.x-a.x,p.z-a.z);
 const ready=choices.find(c=>c.action);if(ready){objectiveMemos.delete(p);return ready;}
 const memo=objectiveMemos.get(p),held=memo&&memo.instance===instance&&memo.run===instance.run&&memo.scene===scene&&memo.token===p.token&&choices.find(c=>c.at.npc===memo.npc);
 const walking=p.path?.at(-1),accepted=walking&&memo&&Math.hypot(walking.x-memo.at.x,walking.z-memo.at.z)<=1;
 if(held&&(memo.until>now||accepted)&&near(memo.at)>1&&scene.isWalkable?.(memo.at.x,memo.at.z))return {...held,at:memo.at,action:null};
 const keep=(choice,point)=>{const at={map:p.map,x:point.x,z:point.z,npc:choice.at.npc};objectiveMemos.set(p,{instance,run:instance.run,scene,token:p.token,npc:choice.at.npc,at,until:now+P.memoMs});return {...choice,at,action:null};};
 let approach=approaches.get(world);if(!approach){approach=createNpcApproachCache(()=>world.now());approaches.set(world,approach);}
 for(const choice of choices.slice(0,P.pathChecks)){
  const at=approach(scene,p,choice.at,8);
  if(at&&near(at)>.5)return keep(choice,at);
 }
 const first=choices[0],at=npcEventWalkStage(scene,p,first.at);
 if(at)return keep(first,at);
 objectiveMemos.delete(p);
 return {...first,at:null,action:null,waiting:true};
}
export function npcEventWaveTarget(world,p,scene,targets,options={}){
 let approach=approaches.get(world);if(!approach){approach=createNpcApproachCache(()=>world.now());approaches.set(world,approach);}
 let searches=0;
 // One shared budget covers required targets, party focus and ordinary fallback.
 // The existing staged-walk fallback has its separate <=3-search bound.
 const searchApproach=m=>searches<NPC_EVENT_TARGET_POLICY.pathChecks?(searches++,approach(scene,p,m,NPC_EVENT_TARGET_POLICY.approachRadius)):null;
 const reachable=(m,search=searchApproach)=>{if(Math.hypot(m.x-p.x,m.z-p.z)<=NPC_EVENT_TARGET_POLICY.directReach&&scene.collision?.lineOfSight?.(p.x,p.z,m.x,m.z))return true;const at=search(m);return !!at&&!!scene.collision?.lineOfSight?.(at.x,at.z,m.x,m.z);};
 const target=npcDeadFrontTargetPriority(world,p,scene,targets,options).find(m=>reachable(m));
 if(!target)return pickEventWaveTarget(world,p,scene,targets,{...options,priorityTier:null,searchApproach});
 const instance=world.instances.get(p.instanceId),run=instance.run;
 // A required target is already path-checked; old filler focus/memos cannot
 // override this tier. Validation may perform one fresh bounded approach.
 return {target,priority:'native-required',validate:()=>world.instances.get(p.instanceId)===instance&&instance.run===run&&npcDeadFrontTargetPriority(world,p,scene,targets,options).includes(target)&&reachable(target,m=>approach(scene,p,m,NPC_EVENT_TARGET_POLICY.approachRadius))};
}
function pickEventWaveTarget(world,p,scene,targets,options={}){
 const P=NPC_EVENT_TARGET_POLICY,now=world.now(),distance=a=>Math.hypot(p.x-a.x,p.z-a.z);
 let approach=approaches.get(world);if(!approach){approach=createNpcApproachCache(()=>world.now());approaches.set(world,approach);}
 const search=options.searchApproach||(m=>approach(scene,p,m,P.approachRadius));
 const reachable=m=>m.isBrick||distance(m)<=P.directReach||!!search(m);
 const keep=m=>{memos.set(p,{id:m.id,until:now+P.memoMs,tier:options.priorityTier});return {target:m};};
 const focusOptions={...options,reachable:m=>{const at=search(m);return !!at&&!!scene.collision?.lineOfSight?.(at.x,at.z,m.x,m.z);}},focused=npcEventPartyFocus(world,p,scene,targets,focusOptions);
 if(focused)return {target:focused,validate:()=>npcEventPartyFocus(world,p,scene,targets,focusOptions)===focused};
 const saved=memos.get(p),memo=saved?.tier===options.priorityTier?saved:null,held=memo&&memo.until>now&&targets.find(m=>m.id===memo.id);if(held)return {target:held};
 if(memo?.stage&&memo.until>now&&memo.first===targets[0]?.id)return {stage:memo.stage};
 const party=p.partyId&&world.parties?.get(p.partyId),mates=new Set(party?.members||[]);mates.add(p.id);
 let checks=0;const rejected=[];
 const tryTarget=m=>{if(rejected.some(r=>Math.hypot(r.x-m.x,r.z-m.z)<=P.clusterRadius))return false;if(m.isBrick||distance(m)<=P.directReach)return true;if(checks>=P.pathChecks)return false;checks++;if(reachable(m))return true;rejected.push(m);return false;};
 for(const m of targets)if(mates.has(m.targetId)&&distance(m)<=P.engagedRange&&tryTarget(m))return keep(m);
 for(const m of targets)if(tryTarget(m))return keep(m);
 // Nothing reachable within the bounded searches: take one ordinary staged
 // walking step toward the nearest wave (never a direct claim of arrival).
 const stage=targets.length?npcEventWalkStage(scene,p,targets[0]):null;
 if(stage){memos.set(p,{stage,first:targets[0].id,until:now+P.memoMs,tier:options.priorityTier});return {stage};}
 return {target:targets[0]||null};
}

// ENGINE-CHOSEN NPC strategy over existing native-backed host objectives. This
// chooses ordinary combat/dialogue actions; it never changes run flags, timers,
// rewards, bricks, tickets or admissions. Root owns movement/combat execution.
export function npcEventObjectivePlan(world,p,{isNpc=q=>!!q.npcPlayer,canAssist}={}){
 const instance=world.instances?.get(p.instanceId),run=instance?.run;
 if(!isNpc(p)||p.dead||p.leaving||p.sceneTransition||!['deadFront','iceCastle'].includes(instance?.kind)||!run||run.ended||instance.closeRequested)return null;
 if(!instance.members?.has(p.id)||!instance.admitted?.has(p.characterId))return null;
 if(run.won!=null){
  if(!instance.rewarded)return {stage:'waiting for durable native event result',waiting:true,at:null,action:null};
  const scene=mapFor(world,p),boxes=[...scene.monsters.values()].filter(m=>m.eventTreasure&&!m.dead&&canClaimDeadFrontTreasure(world,p,m)).sort((a,b)=>Math.hypot(p.x-a.x,p.z-a.z)-Math.hypot(p.x-b.x,p.z-b.z));
  if(boxes.length)return {stage:'opening native winner treasure',targetId:boxes[0].id,at:{map:p.map,x:boxes[0].x,z:boxes[0].z},action:null};
  return {stage:'event exit',at:null,action:{type:'event',operation:'exit'}};
 }
 // ENGINE-CHOSEN preparation intent only. The director executes ordinary
 // support; native resource, cooldown and recipient authority remains there.
 if(run.phase==='waitStart')return {stage:'preparing during event countdown',at:null,action:null,waiting:true};
 if(run.phase!=='fortress')return null;
 if((instance.channels||[]).some(c=>c.p===p))return {stage:'finishing native objective channel',at:null,action:null,waiting:true};
 const info=world.data.eventData.map(instance.map),O=info?.objectiveNpcs||{},scene=mapFor(world,p),distance=a=>Math.hypot(p.x-a.x,p.z-a.z),choices=[];
 const add=(npc,path,stage)=>{const row=info?.npcs?.find(r=>Number(r[0])===Number(npc));if(!row)return;
  if(path.length===2&&!info.scriptNpcs?.some(s=>Number(s.npc)===Number(npc)))return;
  const at={map:p.map,x:Number(row[1])+.5,z:Number(row[2])+.5,npc:Number(npc)};
  choices.push({stage,at,action:distance(at)<=8?{type:'event',operation:'npc',npc:Number(npc),path}:null});
 };
 if(instance.kind==='deadFront'){
  if(run.innerOpen){for(const [k,id]of (O.levers||[]).entries())if(!run.levers.has(k))add(id,[0,0],'opening native slate room');
   for(const [k,id]of (O.slates||[]).entries())if(run.levers.has(k)&&!run.slates.has(k))add(id,[0,0],'deciphering native slate');
  }
  if(run.slates.size>=4&&!run.bookDone)for(const id of O.book||[])add(id,[0,0],'reading native ancient book');
  if(run.bookDone&&!run.wallDone)for(const id of O.secretWall||[])add(id,[0,0],'opening native secret wall');
 }else{
  const gates={5172:121,5173:122,5175:123,5176:124};
  for(const id of O.paws||[]){const row=info.npcs?.find(r=>Number(r[0])===Number(id));if(!row||run.paws.has(id)||run.bricks.standing(gates[id]))continue;
   add(id,[0,0],'activating native ice altar');
  }
  for(const id of O.levers||[]){const west=[5172,5173,5174].includes(id);if(run.flags.has(west?'iceW':'iceE')&&!run.levers.has(id))add(id,[0,0],'opening native ice lever');}
  if(run.midDead>0&&!run.tower&&!run.towerStarting)for(const id of O.asla||[]){
   const row=info.npcs?.find(r=>Number(r[0])===Number(id)),at=row&&{x:Number(row[1])+.5,z:Number(row[2])+.5};
   if(at&&distance(at)>8&&scene.path&&!scene.path(p.x,p.z,at.x,at.z)?.length)add(5671,[0],'using native Regina chamber travel');
   else add(id,[0,0],'starting native shield tower');
  }
 }
 // Prioritize an available authored interaction before hunting more waves.
 // Party coordination and the chosen nearest-objective order are NPC policy.
 choices.sort((a,b)=>distance(a.at)-distance(b.at));if(choices.length)return instance.kind==='deadFront'?deadFrontInteraction(world,p,instance,scene,choices):choices[0];
 const targets=[...scene.monsters.values()].filter(m=>!m.dead&&(!m.isBrick||m.eventObject)&&!['invisible','npc','trap'].includes(m.def?.role));
 targets.sort((a,b)=>distance(a)-distance(b));const choice=npcEventWaveTarget(world,p,scene,targets,{isNpc,canAssist}),target=choice.target;
 if(!target&&choice.stage)return {stage:'moving toward native event wave',at:choice.stage,action:null};
 return target?{...(choice.validate?{validate:choice.validate}:{}),...(choice.priority?{priority:choice.priority}:{}),stage:target.eventObject?'fighting native event statue':choice.priority?'fighting native required objective':'fighting native event wave',at:{map:p.map,x:target.x,z:target.z},targetId:target.id,action:null}:null;
}
