import {sameScene,mapFor} from './scene.mjs';
import {npcReachableApproach} from './npc-navigation.mjs';
import {PARTY_MAX} from './party.mjs';
import {createQuestContext} from './quests.mjs';
import {archetypesEnabled,npcArchetypeTask,npcArchetypeRestMs,npcArchetype} from './npc-archetypes.mjs';
const ARCHETYPE_TASKS=archetypesEnabled();
// ENGINE-CHOSEN routines. Goals persist instead of replacing an active native
// route with a random destination. Native commands own progress and rewards.
const distance=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
// ENGINE-CHOSEN finite routine work budget. Actor/brain identity binds each
// observed interval to this loaded session; no persisted offline timestamp.
const routineClocks=new WeakMap();
const finiteRoutine=t=>t&&['farm','merchant'].includes(t.kind);
const routineDuration=t=>Math.max(1,Math.min(240000,Number(t.durationMs)||Math.max(180000,Number(t.until)-Number(t.started)||180000)));
function restoreFiniteRoutine(task,now){const t=structuredClone(task),durationMs=routineDuration(t);return {...t,version:2,durationMs,workedMs:Math.max(0,Math.min(durationMs,Number(t.workedMs)||0)),until:now+Math.max(0,durationMs-(Number(t.workedMs)||0))};}
export function npcRoutineWork(world,p,b,{paused=false}={}){
 if(paused){routineClocks.delete(b);return 0;}
 const t=b.taskGoal,now=Number(world.now());if(!finiteRoutine(t)||t.version!==2||!Number.isFinite(now)){routineClocks.delete(b);return 0;}
 const key=[t.map,t.cycle,t.started,t.kind].join(':'),previous=routineClocks.get(b);
 routineClocks.set(b,{player:p,key,at:Math.max(now,previous?.at??now)});
 if(!previous||previous.player!==p||previous.key!==key||world.players?.get(p.account)!==p||p.leaving||p.dead||p.commandActive||p.progressCommitting||p.sceneTransition||b.objectiveFlight||p.tradeId||p.pcShopOpen||now<previous.at)return 0;
 // A delayed/suspended poll is not proof that the whole gap was worked.
 const elapsed=Math.min(6000,now-previous.at),remaining=Math.max(0,t.durationMs-t.workedMs),used=Math.min(remaining,elapsed);if(!used)return 0;
 t.workedMs+=used;t.until=now+Math.max(0,t.durationMs-t.workedMs);p.profile.npcRoutine=structuredClone(t);world.changed(p);return used;
}
export function npcPendingHumanInvite(world,p,isHuman){return [...(world.partyInvites||[])].some(([id,i])=>i.party===p.partyId&&i.expires>world.now()&&[...world.players.values()].some(q=>q.id===id&&!q.leaving&&isHuman(q)));}
export function npcAssignActivity(world,p,b,{duty=null}={}){
 const saved=p.profile.npcRoutine;
 if(!b.activityRestored){
  b.activityRestored=true;
  const c=createQuestContext(world,p),active=c?.engine.activeIds().filter(id=>{const q=c.engine.db.quest(id);return q&&!q.hidden&&!q.isGroup;})||[];
  const preferred=[b.questId,saved?.questId,p.profile.npcSeed?.initialGoal?.questId,...active].find(id=>active.includes(Number(id)));
  if(preferred!=null){b.questId=Number(preferred);b.questTitle=c.engine.db.quest(preferred)?.title||'';b.taskGoal={kind:'quest',questId:b.questId,cycle:Number(saved?.cycle)||1,map:p.map,started:saved?.started??world.now(),until:Math.max(world.now()+180000,Number(saved?.until)||0)};p.profile.npcRoutine=structuredClone(b.taskGoal);world.changed(p);return b.taskGoal;}
  if(c&&b.questId&&!active.includes(Number(b.questId))){b.questId=null;b.questTitle='';}
  // Restore the remaining actual-work budget, never add another180s on join.
  // Legacy timestamps carry no proof of worked time, so migration starts at0.
  if(!b.questId&&saved?.map===p.map&&finiteRoutine(saved)){
   b.taskGoal=restoreFiniteRoutine(saved,world.now());p.profile.npcRoutine=structuredClone(b.taskGoal);world.changed(p);npcRoutineWork(world,p,b);
   if(b.taskGoal.workedMs<b.taskGoal.durationMs)return b.taskGoal;
  }
 }
 npcRoutineWork(world,p,b);
 // Archetype mode only: kinds executable here. A market hub (PeaceZone+PcStore, the
 // same town test used elsewhere) has no farmable creatures, and the Ardeca city duty decides whether a resident may head out
 // (quest) or runs errands. A duty rotation can make the current routine kind
 // inexecutable; it is then re-elected (accepted quests/instances are never dropped).
 const hubRow=world.data.mapRow?.(p.map),hub=Number(hubRow?.PeaceZone)===1&&Number(hubRow?.PcStore)===1,allowed=duty==='quest'?['quest']:duty==='service'?['merchant','rest']:duty==='rest'?['rest']:hub?['quest','merchant','rest']:['quest','farm','merchant','rest'];
 const stale=kind=>ARCHETYPE_TASKS&&!b.questId&&!p.instanceId&&!allowed.includes(kind);
 if(finiteRoutine(b.taskGoal)&&b.taskGoal.version===2&&b.taskGoal.map===p.map&&b.taskGoal.workedMs<b.taskGoal.durationMs&&!stale(b.taskGoal.kind))return b.taskGoal;
 if(b.taskGoal&&b.taskGoal.map===p.map&&b.taskGoal.until>world.now()&&!stale(b.taskGoal.kind))return b.taskGoal;
 if(saved?.map===p.map&&saved.until>world.now()&&!stale(saved.kind)){b.taskGoal=structuredClone(saved);return b.taskGoal;}
 const serial=Number(p.profile.npcSeed?.slot)||0,initial=p.profile.npcSeed?.initialGoal,stage=b.activityCycle??(Number(saved?.cycle)||0);b.activityCycle=stage+1;
 const initialValid=initial?.kind==='quest'||initial?.map===p.map&&['merchant','rest'].includes(initial.kind)&&Number(world.data.mapRow?.(p.map)?.PeaceZone)===1&&Number(world.data.mapRow?.(p.map)?.PcStore)===1;
 // Legacy: the saved initial intention is used on the first cycle only. Archetype
 // mode defers it (instead of losing it) until the current duty can execute it.
 if(ARCHETYPE_TASKS)b.initialPending??=stage===0;
 const keepInitial=ARCHETYPE_TASKS?!!b.initialPending&&initialValid&&!stale(initial.kind):stage===0&&initialValid;
 if(ARCHETYPE_TASKS&&(keepInitial||!initialValid))b.initialPending=false;
 // ENGINE-CHOSEN archetype weighting replaces the fixed six-step rotation among the
 // SAME routine kinds; the saved initial intention, accepted quests and instances win.
 const elected=!keepInitial&&ARCHETYPE_TASKS?npcArchetypeTask(p.profile,stage,{allowed}):null;
 let kind=keepInitial?initial.kind:elected||['quest','farm','farm','merchant','quest','rest'][(serial+stage)%6],source=keepInitial?'initial':elected?'archetype':'rotation';
 if(b.questId){kind='quest';source='accepted-quest';}if(p.instanceId){kind='dungeon';source='instance';}
 const restMs=kind==='rest'&&elected?npcArchetypeRestMs(p.profile,stage):null;b.taskSelection={cycle:stage+1,kind,source,archetype:ARCHETYPE_TASKS?npcArchetype(p.profile)?.id:null,at:world.now()};
 const task={kind,cycle:stage+1,map:p.map,started:world.now(),until:world.now()+(kind==='rest'?restMs??20000+serial%5*5000:180000+serial%7*10000),...(kind==='quest'&&(b.questId||initial?.questId)?{questId:b.questId||initial.questId}:{})};
 const selected=finiteRoutine(task)?restoreFiniteRoutine(task,world.now()):task;p.profile.npcRoutine=structuredClone(selected);world.changed(p);b.taskGoal=selected;b.farmTarget=null;npcRoutineWork(world,p,b);return selected;
}
export function npcFarmEnemy(world,p,b,{brains,isNpc}={}){
 const map=mapFor(world,p);if(!map)return null;const valid=m=>m&&!m.dead&&!m.isBrick&&!m.eventObject&&m.def?.role==='creature'&&Number(m.def.exp)>0&&Math.abs(Number(m.def.level)-p.profile.level)<=8;
 const current=map.monsters.get(b.farmTarget);if(valid(current))return current;
 const reserved=new Set();for(const [id,other]of brains||[]){const q=world.players.get(id);if(q&&q!==p&&isNpc?.(q)&&sameScene(p,q)&&(!p.partyId||q.partyId!==p.partyId)&&other.farmTarget)reserved.add(other.farmTarget);}
 const pool=[...map.monsters.values()].filter(valid).sort((a,q)=>Number(reserved.has(a.id))-Number(reserved.has(q.id))||distance(p,a)-distance(p,q));
 const reachable=pool.slice(0,24).filter(m=>npcReachableApproach(map,p,m,Math.min(8,p.stats?.attackRange||5)));if(!reachable.length)return null;
 const open=reachable.filter(m=>!reserved.has(m.id)),choices=open.length?open:reachable,serial=Number(p.profile.npcSeed?.slot)||0,pick=choices[serial%Math.min(6,choices.length)];b.farmTarget=pick.id;return pick;
}
function fieldPurpose(p,brains){const task=brains.get(p.account)?.taskGoal||p.profile.npcRoutine;return task&&['farm','quest'].includes(task.kind)?{kind:task.kind,questId:task.questId??null}:null;}
export function npcFieldPartyBudget(world,p,{isNpc}){
 const actors=[...world.players.values()].filter(q=>isNpc(q)&&!q.leaving),npcIds=new Set(actors.map(q=>q.id)),residents=actors.filter(q=>!q.instanceId&&sameScene(p,q)),byId=new Map(residents.map(q=>[q.id,q])),reserved=new Set();
 // Dead residents still own real leases, and a temporarily cross-map crew
 // still reserves its local members. Human-containing parties remain exempt.
 for(const crew of world.parties.values())if(crew.members.length&&crew.members.every(id=>npcIds.has(id))){for(const id of crew.members)if(byId.has(id))reserved.add(id);for(const[id,invite]of world.partyInvites||[])if(invite.party===crew.id&&invite.expires>world.now()&&byId.has(id))reserved.add(id);}
 // ENGINE-CHOSEN: at most one quarter of ordinary residents in bot-only field
 // crews. Actual human parties and legal seven-member event admission differ.
 const limit=Math.floor(residents.length/4);return {residents:residents.length,limit,reserved:reserved.size,remaining:Math.max(0,limit-reserved.size)};
}
export function npcFieldPartyCandidates(world,p,{isNpc,brains}){
 const purpose=fieldPurpose(p,brains);if(!purpose)return [];
 const budget=npcFieldPartyBudget(world,p,{isNpc});if(budget.remaining<2)return [];
 // ENGINE-CHOSEN: willing nearby players group for a shared task; people
 // running shops/resting, solo players and other quests retain their plans.
 const pool=[...world.players.values()].filter(q=>{
  if(!isNpc(q)||q.leaving||q.dead||q.sceneTransition||q.instanceId||q.partyId||q.profile.npcTraits?.social!=='social'||!sameScene(p,q)||distance(p,q)>35||Math.abs(p.profile.level-q.profile.level)>12)return false;
  if(world.partyInvites?.get(q.id)?.expires>world.now())return false;
  const goal=fieldPurpose(q,brains);return goal?.kind===purpose.kind&&(purpose.kind!=='quest'||goal.questId===purpose.questId);
 }).sort((a,q)=>(a.profile.npcSeed?.slot||0)-(q.profile.npcSeed?.slot||0));
 if(pool[0]!==p)return [];
 const selected=[p],remaining=pool.slice(1),classes=new Set([p.profile.classIndex]),size=Math.min(budget.remaining,[2,3,4][Math.floor((p.profile.npcSeed?.slot||0)/3)%3],PARTY_MAX);
 while(remaining.length&&selected.length<size){remaining.sort((a,q)=>Number(classes.has(a.profile.classIndex))-Number(classes.has(q.profile.classIndex))||distance(p,a)-distance(p,q));const next=remaining.shift();selected.push(next);classes.add(next.profile.classIndex);}
 return selected;
}
export async function npcFieldTeam(world,p,b,{act,isNpc,brains}){
 if(p.partyId||p.instanceId||p.dead||p.profile.npcTraits?.social!=='social'||world.now()<(b.fieldPartyAt||0))return false;b.fieldPartyAt=world.now()+30000;
 const pool=npcFieldPartyCandidates(world,p,{isNpc,brains});if(pool.length<2)return false;
 await act(p,{type:'party',operation:'create',name:p.profile.name+' crew'});
 for(const q of pool.slice(1))await act(p,{type:'party',operation:'invite',targetId:q.id});
 b.activity='forming a '+fieldPurpose(p,brains).kind+' party';return true;
}

/** A finite empty-handed merchant can inspect actual town services, not invent
 * sale stock or replace an accepted quest/human-directed plan. */
export function npcTownMerchantInspection(world,p,b){
 const t=b.taskGoal,row=world.data.mapRow?.(p.map);
 return !!(t?.kind==='merchant'&&t.map===p.map&&t.version===2&&t.workedMs<t.durationMs&&Number(row?.PeaceZone)===1&&Number(row?.PcStore)===1&&!p.instanceId&&!p.partyId&&!p.tradeId&&!p.pcShopOpen&&!p.dead&&!p.leaving&&!p.sceneTransition&&!b.questId&&!Object.keys(p.profile.quests?.active||{}).length&&!['wait','follow','lure'].includes(b.mode)&&!b.follow&&!b.lure&&!b.queue?.length&&!world.partyInvites?.has(p.id));
}
