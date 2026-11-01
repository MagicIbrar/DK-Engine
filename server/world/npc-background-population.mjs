import {sceneKey} from './scene.mjs';
import {npcSlotsAvailable,npcSlotTarget} from './npc-human-slots.mjs';
import {isDkChannel} from './channels.mjs';
import {npcCapacityPolicy,createNpcAdmissionFence} from './npc-capacity-policy.mjs';
import {createNpcBoundedWorkers} from './npc-bounded-workers.mjs';

export const NPC_BACKGROUND_POPULATION_POLICY=Object.freeze({workers:6,physicalCap:42,sliceMs:120000,tickMs:1000,scan:8,retryMs:15000});
const nativeProfile=(world,account,p)=>{
 const row=world.data.mapRow?.(p?.map),level=Number(p?.level);
 return /^npc_[a-f0-9]{32}$/.test(account)&&p?.authority==='server'&&p.npcPlayer===true&&typeof p.id==='string'&&Number.isInteger(p.map)&&Number.isInteger(p.channel??0)&&(p.channel??0)>=0&&!isDkChannel(p.channel)&&row&&!p.instance&&!p.dkReturn&&!world.data.requiresInstance?.(p.map)&&!world.data.eventData?.modeOf?.(p.map)&&!Number(row.IsSiege)&&level>=(Number(row.LimitMinLevel)||1)&&level<=(Number(row.LimitMaxLevel)||world.data.maxLevel||250);
};
// Read-only admission basis shared by scheduler and public census decoration.
export const npcBackgroundProfileEligible=nativeProfile;
/** Only canonical saved characters. `step` executes existing ordinary native
 * director actions; this scheduler never fabricates a profile, reward or route.
 * Cold-scene admission stays an explicit root-owned residency contract. */
export function createNpcBackgroundPopulation(input,options={}){
 if(options.boundedInterest===true){if(options.capacity)throw Error('Bounded workers cannot select retained capacity.');return createNpcBoundedWorkers({...input,nativeEligible:nativeProfile},options);}
 const {world,profiles,enabled,isOccupied,isProtected=()=>false,shouldHandoff=()=>false,eligible=()=>true,onJoin=()=>{},onLeave=()=>{},beforeLeave=()=>{},step,ready=()=>true,priority=()=>false,onError=()=>{},admitScene=null,additionalWorkers=()=>0,additionalActors=()=>[],admissionFence=null,leaveWave=null}=input;
 if(!(profiles?.profiles instanceof Map)||typeof enabled!=='function'||typeof isOccupied!=='function'||typeof step!=='function'||typeof additionalActors!=='function'||typeof priority!=='function')throw Error('Background population requires canonical profiles and ordinary actor callbacks.');
 const bound=(v,d,min,max)=>Number.isFinite(v)?Math.max(min,Math.min(max,Math.trunc(v))):d;
 const capacity=npcCapacityPolicy(options.capacity);
 const slots=capacity?(admissionFence||createNpcAdmissionFence({world,profiles,actorCap:capacity.actorCap,enabled})):null;
 const preloadInfo={phase:'not-started',pending:null,deadlineExceeded:false,turns:0,joined:0,elapsedMs:0,requestedMs:0,complete:false};let preloadBusy=null,preloadDeadline=0,preloadRunning=false;
 const observeBoundary=label=>{if(!preloadRunning)return;preloadInfo.pending=label;if(performance.now()>=preloadDeadline){preloadInfo.deadlineExceeded=true;preloadInfo.phase=label?'deadline-exceeded-settling':'deadline-incomplete';}};
 const policy={workers:bound(options.workers,6,0,6),physicalCap:bound(options.physicalCap,42,1,42),sliceMs:bound(options.sliceMs,120000,1,120000),tickMs:bound(options.tickMs,1000,1,60000),scan:bound(options.scan,8,1,8),retryMs:bound(options.retryMs,15000,1000,60000)};
 if(capacity)Object.assign(policy,{workers:capacity.actorCap,physicalCap:capacity.actorCap,retained:true,maxDecisionsPerCycle:capacity.maxDecisionsPerCycle,decisionBudgetMs:capacity.decisionBudgetMs,preloadAdmissionsPerTurn:capacity.preloadAdmissionsPerTurn,preloadAdmissionBudgetMs:capacity.preloadAdmissionBudgetMs,desiredDecisionMs:capacity.desiredDecisionMs});
 const workers=new Map(),retries=new Map(),flights=new Map(),transfers=new Map(),adoptions=new Map(),reservations=new Map(),reconciliation=new Map();let waveBusy=null,waves=0,waveAdmissions=0;let iterator=null,cursor=0,busy=null,closed=false,nextAt=0,lastNow=0,scanned=0,awaitingResidency=0,admissionRequests=0,admissionRefused=0,admissionReleases=0,rejected=0,steps=0,joins=0,leaves=0;
 const starts=new Map();let urgentCursor=0,backgroundCursor=0,urgentStartRun=0,nextDecisionAt=0,pumpHandle=null,pumpBusy=null,pumpWanted=false,decisionDraining=0,pumpSlices=0,pumpErrors=0,decisionStarts=0;
 const now=()=>{const n=Number(world.now());if(Number.isFinite(n))lastNow=Math.max(lastNow,n);return lastNow;};
 const present=p=>isOccupied(p)===true;
 const canonicalActual=(account,p)=>{const profile=profiles.profiles.get(account);return /^npc_[a-f0-9]{32}$/.test(account)&&p?.account===account&&p.profile?.authority==='server'&&p.profile?.npcPlayer===true&&profile?.authority==='server'&&profile?.npcPlayer===true&&typeof profile.id==='string'&&p.profile.id===profile.id&&p.characterId===profile.id&&p.id===account+':'+profile.id&&Number.isInteger(p.map);};
 const physical=()=>[...world.players].filter(([account,p])=>policy.retained?canonicalActual(account,p):p.npcPlayer===true||p.profile?.npcPlayer===true).length;
 const externalWorkers=()=>{const n=Number(additionalWorkers());return Number.isFinite(n)?Math.max(0,Math.min(policy.workers,Math.trunc(n))):policy.workers;};
 const selectable=(account,p,at,occupied=present)=>npcSlotsAvailable(world)&&!workers.has(account)&&!reservations.has(account)&&!reconciliation.has(account)&&!world.players.has(account)&&at>=(retries.get(account)||0)&&nativeProfile(world,account,p)&&eligible(p,{account})&&(policy.retained||!occupied({map:p.map,channel:p.channel??0,instanceId:null,profile:p}));
 // ENGINE-CHOSEN16 accepted actor thinks at once; all ordinary API/native
 // actions and durable writes remain inside the unchanged step callback.
 const settleActor=async p=>{const flight=flights.get(p?.account);if(flight?.player===p)await flight.task;};
 function dispatchActor(p,entry,urgent=false){
  const account=p.account,token=p.token,scene=sceneKey(p.map,p.instanceId,p.channel||0);
  if(closed||!enabled()||flights.size>=16||flights.has(account)||transfers.has(account)||adoptions.has(account)||world.players.get(account)!==p||!canonicalActual(account,p))return false;
  const flight={player:p,token,scene,urgent,task:null};flights.set(account,flight);starts.set(account,{player:p,token,at:now()});decisionStarts++;
  flight.task=Promise.resolve().then(async()=>{
   if(world.players.get(account)!==p||p.token!==token||sceneKey(p.map,p.instanceId,p.channel||0)!==scene||!canonicalActual(account,p)||(entry.foreground?workers.has(account):workers.get(account)!==entry))return;
   let stepFailure=null;try{await step(p);}catch(error){stepFailure={error};}
   // Await only this exact actor's captured accepted NPC checkpoint, even after a failed step.
   // Never chase a moving queue tail or a replacement actor's checkpoint.
   const checkpoint=p._npcLatestFlight;
   if(world.players.get(account)===p&&p.token===token&&canonicalActual(account,p)&&checkpoint?.token===token&&checkpoint.id===p.id&&checkpoint.characterId===p.characterId){
    try{await checkpoint.task;}catch(error){if(!stepFailure)stepFailure={error};}
   }
   if(stepFailure)throw stepFailure.error;
   if(world.players.get(account)===p&&p.token===token){entry.lastWorked=now();steps++;}
  }).catch(error=>{if(world.players.get(account)===p&&p.token===token){flight.error=error.message;try{onError(error,{player:p,phase:'actor-step'});}catch{}}}).finally(()=>{if(flights.get(account)===flight)flights.delete(account);requestDecisionPump();});
  return true;
 }
 // ENGINE-CHOSEN retained pacing: maintenance stays one second while
 // decisions refill after actual settlement. Sixteen accepted flights maximum.
 // The time budget is soft: a native synchronous continuation cannot be preempted.
 const canPump=()=>policy.retained&&!closed&&enabled()&&world.npcPreparationPending!==true&&!preloadRunning&&!preloadBusy&&!decisionDraining;
 function cancelDecisionPump(){if(pumpHandle!==null){clearImmediate(pumpHandle);pumpHandle=null;}pumpWanted=false;}
 function requestDecisionPump(){
  if(!canPump())return;if(pumpBusy){pumpWanted=true;return;}if(pumpHandle!==null)return;
  pumpHandle=setImmediate(()=>{pumpHandle=null;if(!canPump())return;
   pumpBusy=decisionSlice().catch(error=>{pumpErrors++;try{onError(error,{phase:'decision-pump'});}catch{}}).finally(()=>{pumpBusy=null;if(pumpWanted){pumpWanted=false;requestDecisionPump();}});
  });
 }
 const decisionEligible=(account,e,urgent,at)=>{
  const p=e.player,last=starts.get(account),minimum=urgent?100:policy.desiredDecisionMs;
  return !e.failed&&!p.leaving&&!flights.has(account)&&!transfers.has(account)&&!adoptions.has(account)&&world.players.get(account)===p&&canonicalActual(account,p)&&(e.foreground?!workers.has(account):workers.get(account)===e)&&!(!e.foreground&&shouldHandoff(p))&&!(e.until!==null&&at>=e.until&&!isProtected(p))&&!(last?.player===p&&last.token===p.token&&at-last.at<minimum)&&ready(p);
 };
 async function decisionSlice(){
  if(!canPump())return;const started=performance.now(),urgent=[],background=[],seen=new Set();pumpSlices++;
  const add=(account,e)=>{if(seen.has(account)||world.players.get(account)!==e.player||!canonicalActual(account,e.player))return;seen.add(account);(priority(e.player)===true?urgent:background).push([account,e]);};
  for(const [account,e]of workers)add(account,e);
  for(const p of additionalActors())if(p&&!workers.has(p.account))add(p.account,{player:p,foreground:true,until:null,lastWorked:null});
  const pick=(list,cursor,important,at)=>{for(let n=0;n<list.length;n++){const index=(cursor+n)%list.length,[account,e]=list[index];if(decisionEligible(account,e,important,at))return{account,e,index};}return null;};
  let decisions=0;
  while(canPump()&&flights.size<16&&decisions<policy.maxDecisionsPerCycle){
   const at=now(),u=pick(urgent,urgentCursor,true,at),b=pick(background,backgroundCursor,false,at);
   // ENGINE-CHOSEN3:1 accepted starts, carried across slices/settlements.
   // Outstanding-flight counts alone starve background on quick completion.
   const useUrgent=!!u&&(!b||urgentStartRun<3),chosen=useUrgent?u:b;if(!chosen)break;
   if(useUrgent)urgentCursor=(chosen.index+1)%urgent.length;else backgroundCursor=(chosen.index+1)%background.length;
   if(dispatchActor(chosen.e.player,chosen.e,useUrgent)){decisions++;urgentStartRun=useUrgent?Math.min(3,urgentStartRun+1):0;}
   // Charge initial synchronous step work to this slice before accepting more.
   await Promise.resolve();
   if(decisions&&performance.now()-started>=policy.decisionBudgetMs){if(flights.size<16)pumpWanted=true;break;}
  }
  if(decisions>=policy.maxDecisionsPerCycle&&flights.size<16)pumpWanted=true;
 }
 function drop(account,entry,reason){workers.delete(account);if(reason!=='occupied'&&reason!=='human-protected'&&reason!=='foreground-requested')retries.set(account,now()+policy.retryMs);return onLeave(entry.player,{reason,detached:world.players.get(account)!==entry.player});}
 async function release(account,entry,reason){
  await settleActor(entry.player);
  if(world.players.get(account)!==entry.player){await drop(account,entry,'replaced');return true;}
  if(reason==='occupied'||reason==='human-protected'){await drop(account,entry,reason);return true;}
  if(isProtected(entry.player))return false;
  // Narrow caller maintenance before the ordinary durable leave boundary.
  observeBoundary('departure-maintenance');await beforeLeave(entry.player,{reason});observeBoundary(null);
  if(world.players.get(account)!==entry.player){await drop(account,entry,'replaced');return true;}
  if(!policy.retained&&present(entry.player)){await drop(account,entry,'occupied');return true;}
  if(shouldHandoff(entry.player)){await drop(account,entry,'human-protected');return true;}
  if(isProtected(entry.player))return false;
  observeBoundary('departure-commit');await world.leave(account,entry.player.token);observeBoundary(null);leaves++;await drop(account,entry,reason);return true;
 }

 // Trusted native leases are reserved before one-to-sixteen durable admissions.
 // Only returned receipts authorize registration. Error references are internal
 // exact staged actors, never guessed from a reread of the account namespace.
 async function cleanupWaveActors(owned,reason){
  for(const {player:p,token}of owned){
   await settleActor(p);
   const current=()=>world.players.get(p.account)===p&&p.token===token&&canonicalActual(p.account,p);
   if(!current()){reconciliation.set(p.account,{characterId:p.characterId,reason:'actor-replaced'});continue;}
   if(isProtected(p)||shouldHandoff(p)){reconciliation.set(p.account,{characterId:p.characterId,reason:'actor-protected'});continue;}
   await beforeLeave(p,{reason});
   if(!current()||isProtected(p)||shouldHandoff(p)){reconciliation.set(p.account,{characterId:p.characterId,reason:'cleanup-revalidation'});continue;}
   await world.leave(p.account,token);leaves++;reconciliation.delete(p.account);
   const entry=workers.get(p.account);if(entry?.player===p)await drop(p.account,entry,reason);else await onLeave(p,{reason,detached:true});
  }
 }
 async function collectAdmissionWave(at){
  const selected=[],leases=[],owned=[],limit=Math.min(16,policy.preloadAdmissionsPerTurn);let returned=false,cleanupStarted=false,sliceStarted=performance.now();
  try{
   for(let scan=0;scan<policy.scan*limit&&selected.length<limit;scan++){
    // ENGINE-CHOSEN soft collection slices; retain at most16 native leases
    // across yields so awaited scene IO does not force one durable row per wave.
    if(performance.now()-sliceStarted>=policy.preloadAdmissionBudgetMs){await new Promise(resolve=>setImmediate(resolve));sliceStarted=performance.now();}
    if(closed||!enabled()||performance.now()>=preloadDeadline||workers.size+externalWorkers()+reservations.size>=policy.workers||physical()+reservations.size>=policy.physicalCap)break;
    if(!iterator)iterator=profiles.profiles.entries();let row=iterator.next();if(row.done){iterator=profiles.profiles.entries();row=iterator.next();if(row.done)break;}
    const [account,profile]=row.value;scanned++;if(!selectable(account,profile,at))continue;
    const slot=slots.reserve(account,profile.id);if(!slot)continue;
    const member={account,characterId:profile.id,profile,map:profile.map,channel:profile.channel??0,slot};reservations.set(account,member);admissionRequests++;if(!world.maps.has(sceneKey(member.map,null,member.channel)))awaitingResidency++;
    observeBoundary('wave-scene-admission');const lease=await admitScene?.({map:member.map,channel:member.channel,account,profile});observeBoundary(null);
    if(typeof lease?.release==='function')leases.push(lease);
    const current=()=>profiles.profiles.get(account)===profile&&profile.id===member.characterId&&profile.map===member.map&&(profile.channel??0)===member.channel&&nativeProfile(world,account,profile)&&eligible(profile,{account})&&!world.players.has(account);
    if(lease?.ok!==true||typeof lease.release!=='function'||!world.maps.has(sceneKey(member.map,null,member.channel))||!current()||!slot.valid()||workers.size+externalWorkers()+reservations.size>policy.workers){reservations.delete(account);slot.release();admissionRefused++;retries.set(account,at+policy.retryMs);continue;}
    if(closed||!enabled()||performance.now()>=preloadDeadline)break;
    selected.push(member);
   }
   if(!selected.length||closed||!enabled()||performance.now()>=preloadDeadline||selected.some(r=>!r.slot.valid())||slots.used()>policy.physicalCap||workers.size+externalWorkers()+reservations.size>policy.workers)return;
   if(selected.some(r=>profiles.profiles.get(r.account)!==r.profile||r.profile.id!==r.characterId||r.profile.map!==r.map||(r.profile.channel??0)!==r.channel||world.players.has(r.account)||!nativeProfile(world,r.account,r.profile)||!eligible(r.profile,{account:r.account})))throw Error('NPC wave selection changed while reserving.');
   observeBoundary('wave-durable-admission');waves++;
   const result=await world.npcJoinWave(selected.map(({account,characterId})=>({account,characterId})));observeBoundary(null);
   if(result?.committed!==true||!Array.isArray(result.admissions)||result.admissions.length!==selected.length)throw Object.assign(Error('NPC wave returned invalid durable admissions.'),{npcAdmissionCommitted:result?.committed===true});
   const accepted=new Set();
   for(const receipt of result.admissions){const member=selected.find(r=>r.account===receipt?.account),p=world.players.get(receipt?.account);if(!member||receipt.characterId!==member.characterId||accepted.has(receipt.account)||!p||!canonicalActual(receipt.account,p)||p.characterId!==member.characterId||p.token!==receipt.token)throw Object.assign(Error('NPC wave returned an invalid actor identity.'),{npcAdmissionCommitted:true});accepted.add(receipt.account);owned.push({player:p,token:receipt.token});}
   returned=true;waveAdmissions+=owned.length;
   if(closed||!enabled()){cleanupStarted=true;await cleanupWaveActors(owned,'wave-disabled');return;}
   // No registration before commit or before validation of every returned row.
   for(const {player:p}of owned){if(world.players.get(p.account)!==p)throw Object.assign(Error('NPC wave actor replaced during registration.'),{npcAdmissionCommitted:true});const entry={player:p,until:null,lastWorked:null};workers.set(p.account,entry);joins++;await onJoin(p);}
  }catch(error){
   rejected++;if(returned)error.npcAdmissionCommitted=true;for(const r of selected)retries.set(r.account,at+policy.retryMs);
   if(error.npcAdmissionCommitted===true){
    if(!returned){
     const refs=error.npcAdmissionActors;
     if(Array.isArray(refs)){for(const p of refs){const r=selected.find(r=>r.account===p?.account);if(r&&p.characterId===r.characterId&&world.players.get(r.account)===p&&canonicalActual(r.account,p)&&!owned.some(o=>o.player===p))owned.push({player:p,token:p.token});}
      for(const r of selected)if(world.players.has(r.account)&&!owned.some(o=>o.player===world.players.get(r.account)))reconciliation.set(r.account,{characterId:r.characterId,reason:'unconfirmed-published-actor'});
     }else for(const r of selected)reconciliation.set(r.account,{characterId:r.characterId,reason:'missing-error-ownership-contract'});
    }
    try{if(cleanupStarted){for(const o of owned)if(world.players.get(o.player.account)===o.player)reconciliation.set(o.player.account,{characterId:o.player.characterId,reason:'ordinary-cleanup-failed'});}else{cleanupStarted=true;await cleanupWaveActors(owned,'wave-failed');}}catch(cleanup){for(const o of owned)if(world.players.get(o.player.account)===o.player)reconciliation.set(o.player.account,{characterId:o.player.characterId,reason:'ordinary-cleanup-failed'});try{onError(cleanup,{phase:'wave-cleanup'});}catch{}}
   }
   throw error;
  }finally{
   for(const r of [...reservations.values()]){r.slot.release();reservations.delete(r.account);}
   for(const lease of leases){try{lease.release();admissionReleases++;}catch(error){try{onError(error,{phase:'wave-release'});}catch{}}}
   observeBoundary(null);
  }
 }

 async function cycle(preload=false){
  const at=now();if(closed||!enabled()){
   await Promise.allSettled([...flights.values()].map(f=>f.task));const e=workers.entries().next().value;if(e)await release(...e,'disabled');return;
  }if(!policy.retained&&!preload&&at<nextAt)return;
  if(preload||at>=nextAt){nextAt=at+policy.tickMs;
  // At most one departure or takeover per turn; accepted native work remains
  // protected until its caller permits ordinary durable departure. A refused
  // (still protected) departure does not consume the turn's single departure.
  for(const[account,e]of workers){if(flights.has(account)||transfers.has(account)||adoptions.has(account))continue;if(world.players.get(account)!==e.player||(!policy.retained&&present(e.player))||shouldHandoff(e.player)||(e.until!==null&&at>=e.until)||e.failed&&at>=e.cleanupAt){if(await release(account,e,!policy.retained&&present(e.player)?'occupied':shouldHandoff(e.player)?'human-protected':e.failed?'join-failed':'slice-complete'))break;}}
  if(preload&&policy.retained&&typeof world.npcJoinWave==='function'){waveBusy=collectAdmissionWave(at);try{await waveBusy;}finally{waveBusy=null;}}else{
  const admissionStarted=performance.now();
  for(let turn=0;turn<(preload?policy.preloadAdmissionsPerTurn||1:1);turn++){
   if(preload&&(performance.now()>=preloadDeadline||performance.now()-admissionStarted>=policy.preloadAdmissionBudgetMs))break;
   if(closed||!enabled()||workers.size+externalWorkers()>=policy.workers||physical()>=policy.physicalCap)break;
  if(workers.size+externalWorkers()<policy.workers&&physical()<policy.physicalCap){
   let admissionAttempted=false;for(let n=0;n<policy.scan;n++){
    if(!iterator)iterator=profiles.profiles.entries();let row=iterator.next();if(row.done){iterator=profiles.profiles.entries();row=iterator.next();if(row.done)break;}
    const[account,p]=row.value;scanned++;
    const channel=p.channel??0,target={map:p.map,channel,instanceId:null,profile:p};
    if(!selectable(account,p,at))continue;
    const key=sceneKey(p.map,null,channel),warm=world.maps.has(key);if(!warm)awaitingResidency++;let releaseAdmission=null;const slot=policy.retained?slots.reserve(account,p.id):null;if(policy.retained&&!slot)continue;
    try{
     let admission=warm&&!admitScene;
     if(admitScene&&!admissionAttempted){admissionAttempted=true;admissionRequests++;if(preload)observeBoundary('scene-admission');admission=await admitScene({map:p.map,channel,account,profile:p});if(preload)observeBoundary(null);}
     if(typeof admission?.release==='function')releaseAdmission=()=>admission.release();
     const admitted=admission===true||admission?.ok===true&&releaseAdmission!==null;
     if(!admitted||!world.maps.has(key)){admissionRefused++;retries.set(account,at+policy.retryMs);continue;}
     // Hold admission through every awaited native join/registration path.
     // A warm geometry cache is not an admission lease or budget approval.
     if(preload&&performance.now()>=preloadDeadline)break;
     if(closed||!enabled()||world.players.has(account)||workers.size+externalWorkers()>=policy.workers||physical()>=policy.physicalCap||policy.retained&&!slot.valid()||!policy.retained&&present(target))break;
     if(preload)observeBoundary('join-commit');await (world.joinNpc||world.join).call(world,account,p.id);if(preload)observeBoundary(null);const actor=world.players.get(account);
     if(!actor||actor.profile?.id!==p.id||actor.profile?.authority!=='server'||actor.profile?.npcPlayer!==true)throw Error('Canonical background join is unavailable.');
     const entry={player:actor,until:policy.retained?null:at+policy.sliceMs,lastWorked:null};workers.set(account,entry);joins++;
     // Actual native restore is authoritative. Never undo a lawful scene/level
     // correction or manufacture an on-map position from metadata.
     if(preload)observeBoundary('registration');await onJoin(actor);if(preload)observeBoundary(null);
     if(world.players.get(account)!==actor){await release(account,entry,'replaced');break;}
     if(!policy.retained&&present(actor)){await release(account,entry,'occupied');break;}
     if(closed||!enabled()){await release(account,entry,'disabled');break;}
     if(actor.instanceId||world.data.requiresInstance?.(actor.map)||world.data.eventData?.modeOf?.(actor.map)){await release(account,entry,'native-admission');break;}
    }catch(error){rejected++;retries.set(account,at+policy.retryMs);const entry=workers.get(account);if(entry){entry.failed=true;entry.cleanupAt=at+policy.retryMs;try{await release(account,entry,'join-failed');}catch(cleanup){onError(cleanup);}}throw error;}
    finally{try{if(releaseAdmission){releaseAdmission();admissionReleases++;}}finally{slot?.release();}}
    break;
   }
  }
  }
  }
  }
  if(preload)return; // No think actions during this admission-only operation.
  if(policy.retained){if(at>=nextDecisionAt){nextDecisionAt=at+100;requestDecisionPump();}return;}
  const active=[...workers.entries()];if(policy.retained)for(const p of additionalActors())if(world.players.get(p?.account)===p&&canonicalActual(p.account,p)&&!workers.has(p.account))active.push([p.account,{player:p,foreground:true,until:null,lastWorked:null}]);
  const started=performance.now(),turnCursor=cursor,decisionLimit=policy.retained?Math.min(policy.maxDecisionsPerCycle,Math.max(1,Math.ceil(active.length*policy.tickMs/policy.desiredDecisionMs))):1;let decisions=0;for(let n=0;n<active.length;n++){
   if(policy.retained&&(flights.size>=16||decisions>=decisionLimit||performance.now()-started>=policy.decisionBudgetMs))break;
   const index=(turnCursor+n)%active.length,[account,e]=active[index];
   // An expired protected actor must still finish ordinary pending maintenance
   // so its protection can clear. Never renew the original work deadline.
   if(policy.retained)cursor=(index+1)%active.length;
   if(e.failed||flights.has(account)||transfers.has(account)||adoptions.has(account)||world.players.get(account)!==e.player||!policy.retained&&present(e.player)||!e.foreground&&shouldHandoff(e.player)||e.until!==null&&at>=e.until&&!isProtected(e.player)||!ready(e.player))continue;
   cursor=(index+1)%active.length;if(policy.retained){if(dispatchActor(e.player,e))decisions++;continue;}decisions++;await step(e.player);e.lastWorked=now();steps++;break;
  }
 }
 return{
  tick({preload=false}={}){if(busy)return busy;busy=cycle(preload&&policy.retained===true).catch(e=>{onError(e);throw e;}).finally(()=>{busy=null;});return busy;},
  owns(p){return workers.get(p?.account)?.player===p;},
  inFlight(p){return flights.get(p?.account)?.player===p;},
  async settleAccepted(){decisionDraining++;cancelDecisionPump();try{if(pumpBusy)await pumpBusy;if(waveBusy)await waveBusy.catch(()=>{});await Promise.allSettled([...flights.values()].map(f=>f.task));}finally{decisionDraining--;}},
  handoffCurrent(p,{requested=()=>true}={}){
   if(!p||closed||!enabled()||!policy.retained||preloadBusy||world.players.get(p?.account)!==p||!canonicalActual(p.account,p)||p.leaving)return Promise.resolve(false);
   const pending=transfers.get(p.account);if(pending)return pending.player===p?pending.task:Promise.resolve(false);
   const entry=workers.get(p.account),token=p.token;if(entry?.player!==p)return Promise.resolve(false);
   const operation={player:p,task:null};transfers.set(p.account,operation);
   operation.task=(async()=>{await settleActor(p);if(closed||!enabled()||world.players.get(p.account)!==p||p.token!==token||workers.get(p.account)!==entry||!canonicalActual(p.account,p)||!requested())return false;await drop(p.account,entry,'foreground-requested');return true;})().finally(()=>{if(transfers.get(p.account)===operation)transfers.delete(p.account);});return operation.task;
  },
  adoptCurrent(p,{requested=()=>true}={}){
   if(!p||typeof p.account!=='string')return Promise.resolve(false);
   const account=p?.account,token=p?.token,key=p&&sceneKey(p.map,p.instanceId,p.channel||0),pending=adoptions.get(account);
   if(pending)return pending.player===p?pending.task:Promise.resolve(false);
   const admissible=()=>!closed&&enabled()&&policy.retained&&!preloadBusy&&!flights.has(account)&&world.players.get(account)===p&&p.token===token&&!p.leaving&&!workers.has(account)&&canonicalActual(account,p)&&!isProtected(p)&&!shouldHandoff(p)&&!p._skills?.engine.casting&&nativeProfile(world,account,{...p.profile,map:p.map,channel:p.channel??0,instance:p.instanceId})&&eligible(p.profile,{account})&&workers.size+externalWorkers()+reservations.size<policy.workers&&slots.used()<=policy.physicalCap&&sceneKey(p.map,p.instanceId,p.channel||0)===key&&requested();
   const operation={player:p,task:null};adoptions.set(account,operation);
   operation.task=(async()=>{await settleActor(p);if(!admissible())return false;let releaseAdmission=null;
    try{const admission=admitScene?await admitScene({map:p.map,channel:p.channel??0,account,profile:p.profile,actor:p}):world.maps.has(key);
     if(typeof admission?.release==='function')releaseAdmission=()=>admission.release();
     if(!(admission===true||admission?.ok===true&&releaseAdmission)||!world.maps.has(key)||!admissible())return false;
     workers.set(account,{player:p,until:null,lastWorked:null});retries.delete(account);return true;
    }finally{if(releaseAdmission)releaseAdmission();}
   })().finally(()=>{if(adoptions.get(account)===operation)adoptions.delete(account);});return operation.task;
  },
  preload({wallBudgetMs=120000}={}){
   if(preloadBusy)return preloadBusy;
   if(!policy.retained)return Promise.resolve({phase:'legacy-not-requested',complete:false});
   if(!Number.isInteger(wallBudgetMs)||wallBudgetMs<1||wallBudgetMs>120000)throw Error('Invalid bounded preload deadline');
   const start=performance.now(),initial=joins;preloadDeadline=start+wallBudgetMs;
   Object.assign(preloadInfo,{phase:'preparing',pending:null,deadlineExceeded:false,turns:0,joined:0,elapsedMs:0,requestedMs:wallBudgetMs,complete:false});preloadRunning=true;cancelDecisionPump();
   const deadlineTimer=setTimeout(()=>{preloadInfo.deadlineExceeded=true;preloadInfo.phase=preloadInfo.pending?'deadline-exceeded-settling':'deadline-incomplete';},wallBudgetMs);
   preloadBusy=(async()=>{let noProgressScans=0,noProgressTurns=0;
    const maxTurns=Math.min(10000,Math.max(1,profiles.profiles.size*2));
    for(let turn=0;turn<maxTurns&&performance.now()<preloadDeadline&&!closed&&enabled()&&physical()<npcSlotTarget(world,policy.physicalCap);turn++){
     const beforeJoins=joins,beforeScans=scanned;await this.tick({preload:true});preloadInfo.turns++;
     noProgressScans=joins>beforeJoins?0:noProgressScans+scanned-beforeScans;
     noProgressTurns=joins===beforeJoins&&scanned===beforeScans?noProgressTurns+1:0;
     preloadInfo.joined=joins-initial;preloadInfo.elapsedMs=performance.now()-start;
     if(noProgressScans>=profiles.profiles.size||noProgressTurns>=2)break;
     await new Promise(resolve=>setImmediate(resolve));
    }
    preloadInfo.complete=physical()>=npcSlotTarget(world,policy.physicalCap)&&reconciliation.size===0&&reservations.size===0;
    preloadInfo.elapsedMs=performance.now()-start;
    preloadInfo.phase=closed||!enabled()?'disabled':preloadInfo.complete?'admitted':performance.now()>=preloadDeadline?'deadline-incomplete':'admission-blocked';
    return {...preloadInfo,materialized:physical(),workers:workers.size,target:npcSlotTarget(world,policy.physicalCap),admissionRefused,awaitingResidency};
   })().catch(error=>{preloadInfo.phase='failed';throw error;}).finally(()=>{clearTimeout(deadlineTimer);preloadRunning=false;preloadInfo.pending=null;preloadBusy=null;});return preloadBusy;
  },
  // Internal profile IDs only. This is the actual iterator's pending selection
  // predicate, not online connections, materialized actors or offline work.
  queuedProfileIds({memoOccupiedByScene=false}={}){if(closed||!enabled()||policy.workers===0)return new Set();const at=now();let occupied=present;if(memoOccupiedByScene){const memo=new Map();occupied=target=>{const key=sceneKey(target.map,target.instanceId,target.channel);if(!memo.has(key))memo.set(key,present(target));return memo.get(key);};}return new Set([...profiles.profiles].filter(([a,p])=>selectable(a,p,at,occupied)).map(([,p])=>p.id));},
  async close(){
   if(!leaveWave){closed=true;cancelDecisionPump();await this.settleAccepted();await Promise.allSettled([...transfers.values(),...adoptions.values()].map(o=>o.task));if(preloadBusy)await preloadBusy.catch(()=>{});if(busy)await busy.catch(()=>{});for(const[a,e]of [...workers])await release(a,e,'disabled');return;}
   if(this._departureClose)return this._departureClose;
   closed=true;cancelDecisionPump();
   const task=(async()=>{
    await this.settleAccepted();await Promise.allSettled([...transfers.values(),...adoptions.values()].map(o=>o.task));if(preloadBusy)await preloadBusy.catch(()=>{});if(busy)await busy.catch(()=>{});await this.settleAccepted();
    const refuse=()=>Object.assign(Error('Exact scheduler departure custody changed.'),{status:409});
    let wave=[];
    const flush=async()=>{
     if(!wave.length)return;const pending=wave;wave=[];
     await leaveWave(pending.map(row=>({player:row.entry.player,token:row.token})),async row=>{
      const own=pending.find(r=>r.entry.player===row.player&&r.token===row.token);
      if(!own||workers.get(own.account)!==own.entry||world.players.has(own.account)||own.entry.player.token!==own.token)throw refuse();
      leaves++;await drop(own.account,own.entry,'disabled');
     });
    };
    for(const[account,entry]of [...workers]){
     const p=entry.player,token=p.token;
     await settleActor(p);
     if(workers.get(account)!==entry||world.players.get(account)!==p||!canonicalActual(account,p))throw refuse();
     observeBoundary('departure-maintenance');await beforeLeave(p,{reason:'disabled'});observeBoundary(null);
     if(workers.get(account)!==entry||world.players.get(account)!==p||p.token!==token||!canonicalActual(account,p))throw refuse();
     wave.push({account,entry,token});if(wave.length===64)await flush();
    }
    await flush();
   })();
   this._departureClose=task;try{return await task;}finally{if(this._departureClose===task)this._departureClose=null;}
  },
  snapshot(){return {kind:'bounded native-action workers',preload:{...preloadInfo},policy:'ENGINE-CHOSEN pacing; ordinary native authorities',...policy,enabled:!closed&&!!enabled(),workers:workers.size,admissionFence:slots?.snapshot()||null,admissionWavePending:!!waveBusy,reservedAdmissions:reservations.size,waves,waveAdmissions,reconciliationPending:[...reconciliation].map(([account,r])=>({account,...r})),inFlight:flights.size,maxInFlight:16,decisionStarts,pumpSlices,pumpErrors,decisionPumpPending:pumpHandle!==null||!!pumpBusy,decisionRefillMs:policy.retained?100:null,urgentMinimumMs:policy.retained?100:null,pendingTransfers:transfers.size,pendingAdoptions:adoptions.size,canonicalProfiles:profiles.profiles.size,scanned,awaitingResidency,admissionRequests,admissionRefused,admissionReleases,rejected,steps,joins,leaves,logicalOnline:false,rows:[...workers.values()].map(e=>({npcRosterId:e.player.profile.npcRosterId||null,name:e.player.profile.name,map:e.player.map,level:e.player.profile.level,status:e.lastWorked===null?'native worker ready':'native worker scheduled',lastWorked:e.lastWorked,until:e.until}))};},
 };
}
