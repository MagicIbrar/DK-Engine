// NEW PRIVATE V2 INTEGRATION CANDIDATE. V1 and frozen predecessor remain history.
import {randomUUID} from 'node:crypto';
import {mapFor,sceneKey} from './scene.mjs';
import {serializeLife,commitLife} from './life-transactions.mjs';
import {AuthoritativeInventory} from './inventory.mjs';
import {Equipment} from '../../src/systems/items/equip.js';
import {npcRequestDecision,NPC_AGENCY_POLICY} from './npc-agency.mjs';
import {dialogueIntent} from './npc-dialogue.mjs';

export const FISHING_CANDIDATE_POLICY=Object.freeze({durationMs:120000,retryMs:2000,pollMs:500,waterReads:95});
const FIELD='npcFishingCandidate',own=(w,p)=>w.players?.get(p.account)===p&&p.npcPlayer===true&&p.profile?.npcPlayer===true&&p.profile.authority==='server';
const rank=v=>Number(typeof v==='object'?v?.level:v)||0;
const owned=p=>[...(p.profile.inventory||[]),...Object.values(p.profile.equip?.items||{})];
const unique=(p,uid)=>[...owned(p),...[p.profile.potionBelt,p.profile.storage,p.profile.cashInv,p.profile.costumeBag,p.profile.accountFeatures?.shared].flatMap(v=>Array.isArray(v)?v:[])].filter(i=>i.uid===uid);
const same=(a,b)=>JSON.stringify(a)===JSON.stringify(b);
const finite=n=>Number.isFinite(n);
const scene=p=>sceneKey(p.map,p.instanceId,p.channel||0);
const stateValid=(s,p)=>s?.version===2&&s.policy==='PRIVATE ENGINE-CHOSEN'&&s.owner===p.profile.id&&typeof s.boot==='string'&&typeof s.key==='string'&&s.key.length<=96&&finite(s.started)&&finite(s.deadline)&&s.deadline-s.started===FISHING_CANDIDATE_POLICY.durationMs&&s.original&&Number.isInteger(s.original.preset)&&s.original.preset>=0&&s.original.preset<5&&['working','restoring','done'].includes(s.phase)&&Array.isArray(s.initialJobs)&&s.initialJobs.length<=3&&Array.isArray(s.initialUids)&&s.initialUids.length<=1000&&Array.isArray(s.materialFingerprint)&&s.materialFingerprint.length<=350;

/** Exactly the existing authority's bounded current-facing fan. This does not
 * search a shoreline, load maps, choose coordinates or write position/yaw. */
export function npcFishingCurrentWater(world,p){
 const F=world.data?.fishing,map=mapFor(world,p),col=map?.collision;
 if(!col||typeof col.attrAt!=='function'||!F?.cells||![p.x,p.z,p.yaw].every(finite))return null;
 const fx=-Math.sin(p.yaw),fz=-Math.cos(p.yaw);let reads=0;
 for(let d=0;d<=9;d+=.5)for(const a of [0,.35,-.35,.7,-.7]){
  const c=Math.cos(a),s=Math.sin(a),x=p.x+(fx*c-fz*s)*d,z=p.z+(fx*s+fz*c)*d;
  const attr=col.attrAt(x,z),cell=F.cells[attr];reads++;
  if(cell?.fishing&&cell.fish?.length)return d>4.5?null:{map:p.map,scene:scene(p),attr,x,z,reads,kind:'actual loaded collision/current facing only'};
 }
 return null;
}

function protectedReason(world,p,b,now){
 if(p.dead||p.leaving||p.revoked)return 'actor unavailable';
 if(mapFor(world,p)?.index!==p.map||p.profile.map!==p.map)return 'current native scene unavailable';
 if(p.instanceId||String(p.channel||'').startsWith('dk')||world.data.eventData?.modeOf?.(p.map))return 'private or event scene';
 if(p.mount||p.sceneTransition||p.commandActive||p.progressCommitting||p.tradeCommitting)return 'native operation pending';
 if(p.tradeId||p.pcShopOpen)return 'trade or open shop';
 if(p.partyId||world.partyInvites?.get(p.id)?.expires>now)return 'party or invitation';
 if([...(world.partyInvites||[])].some(([,i])=>i.party&&i.party===p.partyId&&i.expires>now))return 'party invitation';
 if(b.follow||['wait','follow','lure'].includes(b.mode))return 'human request or deliberate mode';
 for(const msg of (b.queue||[]).slice(0,4)){
  const sender=[...world.players.values()].find(q=>q.id===msg.speaker&&!q.leaving&&q.npcPlayer!==true&&q.profile?.npcPlayer!==true),intent=dialogueIntent(msg.text);
  if(sender&&now-msg.at<=20000&&msg.at<=now&&['follow','lure','party','stop','roam','prepare','pvp'].includes(intent)&&(msg.channel!=='party'||msg.partyId&&p.partyId===msg.partyId&&sender.partyId===msg.partyId)&&npcRequestDecision({world,player:p,brain:b,requester:sender,intent,now}).accept)return 'accepted human request';
 }
 if(b.objectiveFlight||b.refineRestore||p.profile.npcEquipment?.phase==='working'||b.questId||Object.keys(p.profile.quests?.active||{}).length)return 'owned quest or service';
 if(now<(b.pauseUntil||0)||now<(b.prepareUntil||0)||now<(b.organizerUntil||0)||b.recovering||b.deadSeen||p.recovering||p.hp/p.maxHp<NPC_AGENCY_POLICY.lowHp)return 'finite preparation or recovery';
 const t=b.taskGoal||p.profile.npcRoutine;
 if(t&&t.map===p.map&&(t.version===2&&['farm','merchant'].includes(t.kind)?Number(t.workedMs)<Number(t.durationMs):Number(t.until)>now))return 'finite ordinary task';
 if(p.attackTarget||p._skills?.engine.casting||p.path?.length||p.lastCombat!=null&&now-p.lastCombat<2000)return 'combat, cast or movement';
 return null;
}
function originalGear(p){
 const e=p.profile.equip;if(!e?.presets||!e.items)return null;const preset=e.active||0,row=e.presets[preset]||{},result={preset,main:row[4]||null,off:row[5]||null};
 for(const uid of [result.main,result.off].filter(Boolean))if(unique(p,uid).length!==1||e.presets.reduce((n,r)=>n+Object.values(r).filter(v=>v===uid).length,0)!==1)return null;
 return result;
}
function equipment(world,p){const profile=structuredClone(p.profile);return new Equipment({db:world.data.itemDB,game:{save:profile,player:{stats:p.stats}},changed(){}});}
function rodEligible(world,p,item){
 const db=world.data.itemDB,def=db?.def(item?.itemIndex),index=world.data.fishing?.rodItems?.[item?.itemIndex];
 if(!def||!index||!world.data.fishing.rods[index]||unique(p,item.uid).length!==1||item.expiresAt&&item.expiresAt<=world.now())return false;
 const eq=equipment(world,p),style=db.weaponRule(def)?.style;
 return eq.check(item,4,p.stats).ok&&Number.isInteger(style)&&eq.canStyle(style)&&!!eq.assetFor(item.itemIndex);
}
function recipeVisible(world){
 const C=world.data?.craft,r=C?.recipes?.[536];
 return !!r&&C.trees?.common?.some(row=>row.code===536)&&r.type===11&&r.item===56537&&r.count===1&&r.time===1&&r.dil===0&&r.prob===100&&r.needPoint===1&&same(r.mats,[[6103,120]]);
}
function mats(world,p){return (p.profile.inventory||[]).filter(i=>i.itemIndex===6103&&!(i.expiresAt&&i.expiresAt<=world.now())).map(i=>[i.uid,i.itemIndex,i.count||1,i.expiresAt||0]).sort((a,b)=>a[0].localeCompare(b[0]));}
function usableMastery(world,p){const id=world.data.fishing?.skills?.[p.profile.classIndex],sys=p._skills,def=sys?.engine?.skillDef(id);return Number.isSafeInteger(id)&&def&&def.class===p.profile.classIndex&&!def.hidden&&def.tree?.window==='life'&&sys.game?._playerRecord===p&&sys.game?._world===world&&sys.engine?.game===sys.game?{id,engine:sys.engine}:null;}
function jobs(p){return p.profile.life?.craft?.jobs||[];}
function rodChoices(world,p){return owned(p).filter(i=>rodEligible(world,p,i)).sort((a,b)=>Number(a.uid!==p.profile.equip.presets[p.profile.equip.active||0]?.[4])-Number(b.uid!==p.profile.equip.presets[p.profile.equip.active||0]?.[4])||a.uid.localeCompare(b.uid));}
const outcome=(status,extra={})=>({handled:true,status,...extra});

/** Uses canonical profile metadata through actual life transactions. The act
 * callback must be the ordinary authority; it is never a grant callback.
 * requestKey is an explicit finite intention, not a global activity toggle. */
export function createNpcFishingObjectiveController(){
 const boot=randomUUID(),running=new WeakSet(),pendingCancellation=new WeakMap(),pendingReceipts=new WeakMap(),decisionBrains=new WeakMap(),decisionEnabled=new WeakMap();
 const isEnabled=value=>(typeof value==='function'?value():value)===true;
 async function checkpoint(world,p,state){
  const expected=structuredClone(p.profile?.[FIELD]);
  await serializeLife(p,async()=>{
   if(!own(world,p)||p.profile.id!==state.owner)throw Error('Fishing objective owner is no longer live.');
   if(!same(p.profile[FIELD],expected))throw Object.assign(Error('Fishing objective changed while queued.'),{status:409});
   // Clone the latest canonical profile only after earlier accepted life work.
   // This transaction owns its marker, never a prequeue profile snapshot.
   const profile=structuredClone(p.profile);profile[FIELD]=structuredClone(state);
   await commitLife(world,p,profile);
  });return p.profile[FIELD];
 }
 function commandFresh(world,p,s,input,pose){
  const e=p.profile.equip,row=e?.presets?.[s.original.preset]||{},slot=slot=>(row[slot]||null),A=p.fishing;
  if(e?.active!==s.original.preset)return false;
  if(input.type==='fishing'&&input.operation!=='start'){
   if(!s.sessionId||input.sessionId!==s.sessionId||A?.id!==s.sessionId||A.rod?.uid!==s.rodUid)return false;
   if(input.operation==='sync')return A.phase==='close';if(input.operation==='stop')return s.phase==='restoring'&&A.phase!=='close';
   return input.operation==='pull'&&s.phase==='working'&&A.phase==='fight'&&scene(A)===scene(p)&&input.pull===!A.resisting&&slot(4)===s.rodUid&&unique(p,s.rodUid).length===1&&rodEligible(world,p,unique(p,s.rodUid)[0])&&Math.hypot(p.x-A.x,p.z-A.z)<.1&&same(pose,{scene:scene(p),x:p.x,z:p.z,yaw:p.yaw});
  }
  if(input.type==='equip'||input.type==='unequip'){
   const original=input.slot===4?s.original.main:input.slot===5?s.original.off:undefined;if(original===undefined||input.preset!==s.original.preset)return false;
   if(s.phase==='restoring')return (!slot(input.slot)||slot(input.slot)===s.rodUid||slot(input.slot)===original)&&(input.type==='unequip'?original===null&&slot(input.slot)===s.rodUid:input.uid===original&&unique(p,input.uid).length===1&&p.profile.inventory?.some(i=>i.uid===input.uid));
   return input.type==='equip'&&input.slot===4&&input.uid===s.rodUid&&slot(4)===s.original.main&&slot(5)===s.original.off&&unique(p,s.rodUid).length===1&&p.profile.inventory?.some(i=>i.uid===s.rodUid)&&rodEligible(world,p,unique(p,s.rodUid)[0]);
  }
  if(s.phase!=='working')return false;
  const mastery=usableMastery(world,p);if(!mastery||rank(p.profile.skills?.[mastery.id])<1&&!mastery.engine.canLevel(mastery.id).ok)return false;
  if(input.type==='production'){
   if(slot(4)!==s.original.main||slot(5)!==s.original.off)return false;
   if(input.operation==='make'){const inv=new AuthoritativeInventory(structuredClone(p.profile),world.data.itemDB,{now:world.now,random:world.random});return input.recipe===536&&input.count===1&&recipeVisible(world)&&same(mats(world,p),s.materialFingerprint)&&inv.count(6103)>=120&&!!inv.bag.findSpot(...inv.bag.size({itemIndex:56537}))&&same(jobs(p).map(j=>j.id),s.initialJobs);}
   const j=jobs(p).find(j=>j.id===s.jobId);return input.operation==='receive'&&input.jobId===s.jobId&&j?.recipe===536&&j.count===1&&j.end<=world.now();
  }
  if(input.type==='learn')return input.skillId===mastery.id&&rank(p.profile.skills?.[mastery.id])<1&&mastery.engine.canLevel(mastery.id).ok&&slot(4)===s.original.main&&slot(5)===s.original.off&&unique(p,s.rodUid).length===1&&rodEligible(world,p,unique(p,s.rodUid)[0]);
  if(input.type==='fishing'&&input.operation==='start')return rank(p.profile.skills?.[mastery.id])>=1&&slot(4)===s.rodUid&&unique(p,s.rodUid).length===1&&rodEligible(world,p,unique(p,s.rodUid)[0])&&(!A||A.settled&&A.phase==='close')&&(A?.id||null)===(s.attempt.beforeSession||null)&&same(pose,{scene:scene(p),x:p.x,z:p.z,yaw:p.yaw})&&!!npcFishingCurrentWater(world,p);
  return false;
 }
 async function action(world,p,s,act,input,attempt={}){
  const now=world.now(),pose={scene:scene(p),x:p.x,z:p.z,yaw:p.yaw},next={...s,lastAt:now,retryAt:now+FISHING_CANDIDATE_POLICY.retryMs,attempt:{kind:input.operation||input.type,at:now,boot,status:'pending',...attempt}};
  await checkpoint(world,p,next); // No command before durable ownership marker.
  // Storage awaited: another lawful request, deadline, owner, scene or vital
  // change may have won meanwhile. Never act on the pre-await decision.
  const current=p.profile[FIELD],at=world.now(),b=decisionBrains.get(p)||{};
  if(!own(world,p)||!stateValid(current,p)||current.key!==s.key||current.phase!==s.phase)return outcome('objective identity changed after checkpoint');
  if(s.phase==='working'){
   const reason=pendingCancellation.get(p)||(!isEnabled(decisionEnabled.get(p))?'actors OFF':protectedReason(world,p,b,at)|| (at<s.lastAt?'clock rollback':at>=s.deadline?'finite deadline':scene(p)!==s.scene?'scene changed':!npcFishingCurrentWater(world,p)?'water opportunity changed':null));
   if(reason){await cancel(world,p,current,reason);return outcome('priority changed after checkpoint');}
  }else if(p.commandActive||p.sceneTransition||p.progressCommitting||input.type!=='fishing'&&(p.dead||p.leaving||p._skills?.engine.casting||p.tradeId||p.pcShopOpen))return outcome('cleanup authority changed after checkpoint');
  if(!commandFresh(world,p,current,input,pose)){if(current.phase==='working')await cancel(world,p,current,'command facts changed after checkpoint');return outcome('command facts changed; no dispatch');}
  let result;try{result=await act(p,input);if(result==null)throw Object.assign(Error('Ordinary authority returned no accepted command.'),{status:409});}
  catch(e){if(!['make','receive','start'].includes(next.attempt.kind)){await checkpoint(world,p,{...p.profile[FIELD],attempt:{...next.attempt,status:'refused'}});}else pendingCancellation.set(p,'unresolved ordinary command');throw e;}
  let saved={...p.profile[FIELD],attempt:{...next.attempt,status:'returned'},retryAt:world.now()+FISHING_CANDIDATE_POLICY.pollMs};
  if(input.type==='production'&&input.operation==='make'){
   const id=result.productionResult?.jobId,j=jobs(p).find(j=>j.id===id);if(typeof id!=='string'||!j||j.recipe!==536||j.count!==1||s.initialJobs.includes(id))throw Error('Ordinary make returned no exact new owned job identity.');saved.jobId=id;saved.jobStarted=j.start;
  }
  if(input.type==='production'&&input.operation==='receive'){
   const r=result.productionResult;if(r?.jobId!==s.jobId)throw Error('Ordinary receive returned wrong owned job identity.');
   if(r.accepted){const rods=owned(p).filter(i=>!s.initialUids.includes(i.uid)&&i.itemIndex===56537&&rodEligible(world,p,i));if(rods.length!==1)throw Error('Received owned rod identity is ambiguous.');saved.rodUid=rods[0].uid;}
  }
  if(input.type==='fishing'&&input.operation==='start'){
   const A=p.fishing;if(!A||A.id===attempt.beforeSession||A.rod?.uid!==s.rodUid||!finite(A.started)||result.self?.fishing?.id!==A.id)throw Error('Ordinary start returned no exact new owned session.');saved.sessionId=A.id;saved.sessionStarted=A.started;
  }
  pendingReceipts.set(p,saved);await checkpoint(world,p,saved);pendingReceipts.delete(p);
  return outcome('ordinary action attempted',{action:input,result});
 }
 async function cancel(world,p,s,reason){
  pendingCancellation.set(p,reason);
  if(s.phase==='restoring')return s;
  return checkpoint(world,p,{...s,phase:'restoring',cancelReason:reason,lastAt:world.now(),retryAt:0});
 }
 async function restore(world,p,s,act){
  if(p.dead||p.leaving||p.revoked)return outcome('cleanup waits for live ordinary authority');
  const A=p.fishing;
  if(A&&!A.settled){
   if(!s.sessionId||A.id!==s.sessionId||A.rod?.uid!==s.rodUid)return outcome('unowned session; cleanup deferred');
   if(p.commandActive||p.sceneTransition||p.progressCommitting)return outcome('cleanup waits for native operation');
   return action(world,p,s,act,{type:'fishing',operation:A.phase==='close'?'sync':'stop',sessionId:s.sessionId});
  }
  if(p.dead||p.leaving||p.revoked||p.commandActive||p.sceneTransition||p.progressCommitting||p._skills?.engine.casting||p.tradeId||p.pcShopOpen)return outcome('restoration waits for native authority');
  const preset=s.original.preset,row=p.profile.equip?.presets?.[preset]||{};
  for(const [slot,uid]of [[4,s.original.main],[5,s.original.off]]){
   if((row[slot]||null)===uid)continue;
   if(row[slot]&&row[slot]!==s.rodUid)return outcome('restoration conflict; original UID retained');
   if(uid){
    if(unique(p,uid).length!==1||!p.profile.inventory?.some(i=>i.uid===uid))return outcome('original UID unavailable; restoration retained');
    return action(world,p,s,act,{type:'equip',uid,slot,preset});
   }
   if(row[slot]===s.rodUid)return action(world,p,s,act,{type:'unequip',slot,preset});
  }
  if(s.unresolvedOrdinaryAttempt)return outcome('unresolved ordinary identity retained; no guessed recovery');
  await checkpoint(world,p,{...s,phase:'done',lastAt:world.now(),retryAt:0});
  pendingCancellation.delete(p);
  return outcome(s.cancelReason?'cancelled and restored':'completed and restored',{result:s.result||null});
 }
 async function stepInternal({world,player:p,brain:b={},act,requestKey=null,cancel:stop=false,enabled=true}={}){
  if(!world||!p||typeof act!=='function'||!own(world,p))return {handled:false,status:'not a live canonical NPC'};
  const now=Number(world.now());if(!finite(now))return {handled:false,status:'invalid server clock'};
  const allowed=isEnabled(enabled);
  let s=p.profile[FIELD];
  if(s&&!stateValid(s,p))return {handled:false,status:'invalid or foreign objective metadata'};
  const receipt=pendingReceipts.get(p);if(receipt){if(receipt.key!==s?.key||receipt.owner!==p.profile.id)throw Error('Pending ordinary receipt owner changed.');await checkpoint(world,p,receipt);pendingReceipts.delete(p);return outcome('exact returned ordinary identity persisted');}
  if(s?.phase==='working'&&s.boot!==boot){s=await checkpoint(world,p,{...s,phase:'restoring',cancelReason:'caller boot changed; no renewed consent',unresolvedOrdinaryAttempt:s.attempt?.status==='pending'&&['make','receive','start'].includes(s.attempt.kind),lastAt:now,retryAt:0});}
  if(!s||s.phase==='done'){
   if(!allowed||stop||typeof requestKey!=='string'||requestKey.length<1||requestKey.length>96||s?.key===requestKey)return {handled:false,status:'no new finite request'};
   const protectedBy=protectedReason(world,p,b,now);if(protectedBy)return {handled:false,status:protectedBy};
   if(p.fishing&&(p.fishing.phase!=='close'||p.fishing.settled!==true))return {handled:false,status:'existing fishing session'};
   const water=npcFishingCurrentWater(world,p);if(!water)return {handled:false,status:'no verified water opportunity'};
   const mastery=usableMastery(world,p);if(!mastery||rank(p.profile.skills?.[mastery.id])<1&&!mastery.engine.canLevel(mastery.id).ok)return {handled:false,status:'ordinary mastery unavailable'};
   const original=originalGear(p);if(!original)return {handled:false,status:'equipment restoration is not uniquely owned'};
   const choices=rodChoices(world,p),rod=choices[0];
   if(!rod){
    if(!recipeVisible(world))return {handled:false,status:'visible native recipe unavailable'};
    const inv=new AuthoritativeInventory(structuredClone(p.profile),world.data.itemDB,{now:world.now,random:world.random});
    if(inv.count(6103)<120||!inv.bag.findSpot(...inv.bag.size({itemIndex:56537})))return {handled:false,status:'owned materials or bag space unavailable'};
    const probe={uid:'prototype-eligibility-only',itemIndex:56537};
    // Check class/style/model without representing this probe as owned stock.
    const eq=equipment(world,p),def=world.data.itemDB.def(56537),style=world.data.itemDB.weaponRule(def)?.style;
    if(!eq.check(probe,4,p.stats).ok||!eq.canStyle(style)||!eq.assetFor(56537))return {handled:false,status:'native rod class/style unavailable'};
   }
   s=await checkpoint(world,p,{version:2,boot,policy:'PRIVATE ENGINE-CHOSEN',owner:p.profile.id,key:requestKey,phase:'working',started:now,lastAt:now,deadline:now+FISHING_CANDIDATE_POLICY.durationMs,scene:scene(p),original,rodUid:rod?.uid||null,initialUids:owned(p).map(i=>i.uid),initialJobs:jobs(p).map(j=>j.id),materialFingerprint:mats(world,p),retryAt:0});
   return outcome('finite objective checkpointed');
  }
  if(pendingCancellation.has(p)||stop||!allowed||now<s.started||now<s.lastAt||now>=s.deadline||s.scene!==scene(p)||protectedReason(world,p,b,now))s=await cancel(world,p,s,pendingCancellation.get(p)|| (stop?'explicit cancellation':!allowed?'actors OFF':now<s.lastAt?'clock rollback':now>=s.deadline?'finite deadline':s.scene!==scene(p)?'scene changed':'higher priority ordinary work'));
  if(s.phase==='restoring'){
   if(s.attempt?.status==='pending'&&['make','receive','start'].includes(s.attempt.kind)&&!pendingReceipts.has(p)&&(!s.jobId&&s.attempt.kind==='make'||!s.rodUid&&s.attempt.kind==='receive'||!s.sessionId&&s.attempt.kind==='start'))s=await checkpoint(world,p,{...s,unresolvedOrdinaryAttempt:true});
   if(now<(s.retryAt||0))return outcome('cleanup retry backoff');
   return restore(world,p,s,act);
  }
  if(now<(s.retryAt||0))return outcome('ordinary retry backoff');
  if(!npcFishingCurrentWater(world,p)){s=await cancel(world,p,s,'verified water opportunity lost');return restore(world,p,s,act);}
  const mastery=usableMastery(world,p);if(!mastery){s=await cancel(world,p,s,'own-class mastery changed');return restore(world,p,s,act);}
  if(rank(p.profile.skills?.[mastery.id])<1&&!mastery.engine.canLevel(mastery.id).ok){s=await cancel(world,p,s,'ordinary mastery resources unavailable');return restore(world,p,s,act);}
  if(!s.rodUid){
   const J=jobs(p);
   if(!s.jobId&&s.attempt?.kind==='make'&&s.attempt.status==='pending'){s=await checkpoint(world,p,{...s,phase:'restoring',unresolvedOrdinaryAttempt:true,cancelReason:'paid production identity unresolved'});return restore(world,p,s,act);}
   if(s.jobId){
    const j=J.find(j=>j.id===s.jobId);
    if(!j){
     s=await cancel(world,p,s,'owned production job missing or ambiguous');return restore(world,p,s,act);
    }
    if(j.recipe!==536||j.count!==1||j.id!==s.jobId){s=await cancel(world,p,s,'production job changed');return restore(world,p,s,act);}
    if(j.end>now)return outcome('waiting for ordinary production clock');
    return action(world,p,s,act,{type:'production',operation:'receive',jobId:j.id});
   }
   if(!recipeVisible(world)||!same(mats(world,p),s.materialFingerprint))return outcome('production inputs changed; no make');
   return action(world,p,s,act,{type:'production',operation:'make',recipe:536,count:1});
  }
  const rod=unique(p,s.rodUid);if(rod.length!==1||!rodEligible(world,p,rod[0])){s=await cancel(world,p,s,'owned rod UID unavailable');return restore(world,p,s,act);}
  if(rank(p.profile.skills?.[mastery.id])<1){
   if(!mastery.engine.canLevel(mastery.id).ok){s=await cancel(world,p,s,'ordinary mastery resources unavailable');return restore(world,p,s,act);}
   return action(world,p,s,act,{type:'learn',skillId:mastery.id});
  }
  const current=p.profile.equip?.presets?.[s.original.preset]?.[4];
  if(p.profile.equip.active!==s.original.preset){s=await cancel(world,p,s,'active preset changed');return restore(world,p,s,act);}
  if(current!==s.rodUid){
   if(current!==s.original.main||!p.profile.inventory.some(i=>i.uid===s.rodUid)){s=await cancel(world,p,s,'equipment changed before fishing');return restore(world,p,s,act);}
   return action(world,p,s,act,{type:'equip',uid:s.rodUid,slot:4,preset:s.original.preset});
  }
  const A=p.fishing;
  if(!s.sessionId){
   if(s.attempt?.kind==='start'&&s.attempt.status==='pending'){s=await checkpoint(world,p,{...s,phase:'restoring',unresolvedOrdinaryAttempt:true,cancelReason:'session identity unresolved'});return restore(world,p,s,act);}
   if(A&&!A.settled)return outcome('unowned session; start refused');
   return action(world,p,s,act,{type:'fishing',operation:'start'},{beforeSession:A?.id||null});
  }
  if(!A||A.id!==s.sessionId||A.rod?.uid!==s.rodUid){s=await cancel(world,p,s,'session identity changed');return restore(world,p,s,act);}
  if(A.phase==='close'){
   if(!A.settled)return action(world,p,s,act,{type:'fishing',operation:'sync',sessionId:s.sessionId});
   s=await checkpoint(world,p,{...s,phase:'restoring',result:A.result,lastAt:now,retryAt:0});return restore(world,p,s,act);
  }
  if(A.phase==='fight'&&!!A.pull===!!A.resisting)return action(world,p,s,act,{type:'fishing',operation:'pull',sessionId:s.sessionId,pull:!A.resisting});
  return outcome('waiting for ordinary fishing tick');
 }
 return {async step(input){const p=input?.player;if(!p||running.has(p)){if(p&&input.cancel)pendingCancellation.set(p,'explicit cancellation while decision pending');return {handled:false,status:'objective decision already pending'};}running.add(p);decisionBrains.set(p,input.brain||{});decisionEnabled.set(p,input.enabled??true);try{return await stepInternal(input);}finally{running.delete(p);decisionBrains.delete(p);decisionEnabled.delete(p);}},field:FIELD};
}

// Same admitted actor, same ordinary command/lease path; no extra scheduler.
export function createNpcFishingDirectorHook({world,enabled,closed=()=>false,command,onError=()=>{}}){
 const controller=createNpcFishingObjectiveController(),field=controller.field;
 const state=p=>{const s=p?.profile?.[field];return own(world,p)&&stateValid(s,p)&&s.phase!=='done'?s:null;};
 function urgent(p,b){
  if(p.dead||p.leaving||p.revoked||b.follow||['wait','follow','lure'].includes(b.mode)||p.partyId||world.partyInvites?.has(p.id))return true;
  if(p.instanceId||p.tradeId||p.pcShopOpen||p.profile.npcMerchantReservation?.phase==='held'||['listing','open','closing'].includes(p.profile.npcMerchant?.phase)||['prepared','invited','confirming'].includes(p.profile.npcGift?.phase)||b.forwardGoal||b.routeGoal)return true;
  return [...(mapFor(world,p)?.monsters?.values()||[])].some(m=>!m.dead&&!m.isBrick&&!m.eventObject&&m.def?.role==='creature'&&m.targetId===p.id&&Math.hypot(p.x-m.x,p.z-m.z)<25);
 }
 async function ordinary(p,input){
  const s=state(p);if(!s)throw Object.assign(Error('Fishing caller lost canonical objective.'),{status:409});
  if(s.phase==='working'&&(closed()||enabled()!==true))throw Object.assign(Error('Fishing work disabled.'),{status:409});
  if(s.phase==='restoring'){
   const A=p.fishing,slot=input.slot,original=slot===4?s.original.main:slot===5?s.original.off:undefined,row=p.profile.equip?.presets?.[s.original.preset]||{};
   const session=input.type==='fishing'&&['stop','sync'].includes(input.operation)&&s.sessionId&&input.sessionId===s.sessionId&&A?.id===s.sessionId&&A.rod?.uid===s.rodUid;
   const gear=['equip','unequip'].includes(input.type)&&original!==undefined&&input.preset===s.original.preset&&p.profile.equip.active===s.original.preset&&(!row[slot]||row[slot]===s.rodUid||row[slot]===original)&&(input.type==='equip'?input.uid===original&&unique(p,original).length===1&&p.profile.inventory?.some(i=>i.uid===original):original===null&&row[slot]===s.rodUid);
   if(!session&&!gear)throw Object.assign(Error('Only exact owned fishing cleanup is allowed.'),{status:409});
  }
  const result=await command(p.account,{...input,token:p.token});if(result==null)throw Object.assign(Error('Ordinary command did not dispatch.'),{status:409});return result;
 }
 async function maintain(p,b){
  if(!state(p))return {reserve:false,hold:false};
  const priority=urgent(p,b),r=await controller.step({world,player:p,brain:b,act:ordinary,requestKey:null,cancel:priority||closed(),enabled:()=>enabled()===true&&!closed()});
  const s=state(p);if((priority||closed()||enabled()!==true)&&s?.phase==='working')throw Object.assign(Error('Fishing cancellation is not yet durably acknowledged.'),{status:409});return {reserve:!!s,hold:!!s&&s.phase==='working'&&!priority||!!r.action,status:r.status};
 }
 async function start(p,b){
  if(state(p))return maintain(p,b);if(closed()||enabled()!==true||urgent(p,b))return {reserve:false,hold:false};
  const t=b.taskGoal||p.profile.npcRoutine,now=world.now();
  // A completed hunt or merchant trip is not consent to swap a quester's
  // weapon for a rod. Fishing belongs to an idle break at verified water.
  const complete=t?.map===p.map&&t.kind==='rest'&&Number(t.until)<=now;
  if(!complete)return {reserve:false,hold:false};
  const key=`fish:${p.profile.id}:${t.map}:${t.cycle}:${Math.trunc(t.started)}`;if(key.length>96)return {reserve:false,hold:false};
  const r=await controller.step({world,player:p,brain:b,act:ordinary,requestKey:key,enabled:()=>enabled()===true&&!closed()});return {reserve:!!state(p),hold:!!state(p),status:r.status};
 }
 async function retire(p,b){
  if(!state(p))return;await controller.step({world,player:p,brain:b,act:ordinary,cancel:true,enabled:false});if(state(p)?.phase==='working')throw Object.assign(Error('Fishing retirement waits for durable cancellation.'),{status:409});
  // One bounded maintenance decision; a remaining marker persists through the
  // existing ordinary leave. Never invent completion or stall shutdown forever.
 }
 return {field,pending:p=>!!state(p),protected:p=>{const s=state(p);return !!s&&s.phase==='working'&&world.now()<s.deadline;},maintain,start,retire,ordinary,controller};
}
