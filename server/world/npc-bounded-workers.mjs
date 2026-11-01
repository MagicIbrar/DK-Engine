import {sceneKey} from './scene.mjs';

// ENGINE-CHOSEN six finite native work leases, not offline rewards or1250
// physical players. All actions, admission, checkpoints and exits stay native.
export function createNpcBoundedWorkers({world,profiles,enabled,isOccupied,isProtected=()=>false,shouldHandoff=()=>false,eligible=()=>true,nativeEligible,onJoin=()=>{},onLeave=()=>{},beforeLeave=()=>{},step,ready=()=>true,onError=()=>{},admitScene,admissionBudget,generation=()=>0,optionalAdmissionAllowed=()=>true,checkpoint=p=>world.persist(p)},options={}){
 if(!admissionBudget||typeof admitScene!=='function'||typeof nativeEligible!=='function')throw Error('Bounded workers require shared admissions and native residency.');
 const bound=(v,d,min,max)=>Number.isFinite(v)?Math.max(min,Math.min(max,Math.trunc(v))):d;
 const policy={boundedInterest:true,workers:6,physicalCap:150,sliceMs:bound(options.sliceMs,120000,1,120000),tickMs:bound(options.tickMs,1000,1,60000),scan:8,retryMs:15000};
 const workers=new Map(),flights=new Map(),transfers=new Map(),departures=new Map(),reservations=new Map(),retries=new Map(),refusals=new Map(),unconfirmed=new Set();
 let closed=false,draining=0,maintenance=null,closing=null,iterator=null,cursor=0,nextAt=0,lastNow=0,scanned=0,joins=0,leaves=0,steps=0,rejected=0,admissionRequests=0,admissionRefused=0,admissionReleases=0;
 const now=()=>{lastNow=Math.max(lastNow,Number(world.now())||0);return lastNow;};
 const report=(error,phase,p)=>{try{onError(error,{phase,player:p});}catch{}};
 const canonical=p=>{const saved=profiles.profiles.get(p?.account);return /^npc_[a-f0-9]{32}$/.test(p?.account||'')&&world.players.get(p.account)===p&&p.profile?.authority==='server'&&p.profile?.npcPlayer===true&&p.npcPlayer===true&&saved?.id===p.characterId&&p.profile.id===p.characterId&&p.id===p.account+':'+p.characterId;};
 const current=(p,e)=>workers.get(p.account)===e&&e.player===p&&p.token===e.token&&p.id===e.id&&p.characterId===e.characterId&&canonical(p);
 const live=()=>!closed&&!draining&&enabled();
 const occupied=p=>isOccupied(p)===true;
 const refuse=reason=>{admissionRefused++;refusals.set(reason,(refusals.get(reason)||0)+1);};
 const fail=(e,error,phase)=>{if(current(e.player,e)){e.failed=String(error?.message||error);e.phase='failed';report(error,phase,e.player);}};
 const snapshotCheckpoint=async(p,e)=>{
  const accepted=p._npcLatestFlight;
  if(accepted?.token===e.token&&accepted.id===e.id&&accepted.characterId===e.characterId)await accepted.task;
 };
 const settleActor=async(p,e)=>{const f=flights.get(p.account);if(f?.entry===e)await f.task;};
 function start(e){
  const p=e.player,account=p.account,epoch=generation(),scene=sceneKey(p.map,p.instanceId,p.channel||0);
  if(!live()||optionalAdmissionAllowed()!==true||e.failed||flights.size>=6||flights.has(account)||transfers.has(account)||departures.has(account)||!current(p,e)||p.leaving||world.npcHumanVictims?.has(account)||occupied(p)||shouldHandoff(p)||now()>=e.until&&!isProtected(p)||!ready(p))return false;
  const f={player:p,entry:e,task:null};flights.set(account,f);e.phase='working';
  f.task=Promise.resolve().then(async()=>{
   if(!live()||optionalAdmissionAllowed()!==true||generation()!==epoch||!current(p,e)||sceneKey(p.map,p.instanceId,p.channel||0)!==scene||world.npcHumanVictims?.has(account)||occupied(p)||shouldHandoff(p))return;
   let failure;try{await step(p);}catch(error){failure=error;}
   // Accepted action/checkpoint custody survives OFF/generation changes.
   // The next action start does not. Never chase a replacement save tail.
   if(current(p,e))try{await snapshotCheckpoint(p,e);}catch(error){failure??=error;}
   if(failure)throw failure;if(current(p,e)){e.lastWorked=now();steps++;}
  }).catch(error=>fail(e,error,'actor-step')).finally(()=>{if(flights.get(account)===f)flights.delete(account);if(current(p,e)&&!e.failed)e.phase='ready';});
  return true;
 }
 function dispatch(){const rows=[...workers.values()],at=performance.now(),initial=cursor;for(let n=0;n<rows.length&&flights.size<6;n++){const index=(initial+n)%rows.length;cursor=(index+1)%rows.length;start(rows[index]);if(performance.now()-at>=4)break;}}
 async function drop(p,e,reason){if(workers.get(p.account)!==e)return;workers.delete(p.account);if(reason!=='foreground-requested')retries.set(p.account,now()+policy.retryMs);await onLeave(p,{reason,detached:world.players.get(p.account)!==p});}
 function handoffCurrent(p,{requested=()=>true}={}){
  const e=workers.get(p?.account),pending=transfers.get(p?.account);if(pending)return pending.player===p?pending.task:Promise.resolve(false);
  if(!p||!live()||!e||!current(p,e)||p.leaving)return Promise.resolve(false);
  const epoch=generation(),op={player:p,task:null};transfers.set(p.account,op);e.phase='settling';
  op.task=(async()=>{
   await settleActor(p,e);if(!live()||generation()!==epoch||!current(p,e)||!requested())return false;
   // A failed automatic checkpoint is retried only by this explicit handoff
   // request; no automatic failed-worker replay can fabricate readiness.
   if(p.dirty||p.saveError||e.failed)await checkpoint(p);
   if(!live()||generation()!==epoch||!current(p,e)||p.leaving||!requested())return false;
   e.failed=null;await drop(p,e,'foreground-requested');return true;
  })().catch(error=>{fail(e,error,'foreground-checkpoint');throw error;}).finally(()=>{if(transfers.get(p.account)===op)transfers.delete(p.account);if(current(p,e)&&!e.failed)e.phase='ready';});
  void op.task.catch(()=>{});return op.task;
 }
 function retire(p,e,{shutdown=false}={}){
  const pending=departures.get(p.account);if(pending)return pending.entry===e?pending.task:Promise.resolve(false);
  const op={entry:e,task:null};departures.set(p.account,op);e.phase='settling';
  op.task=(async()=>{
   await settleActor(p,e);const transfer=transfers.get(p.account);if(transfer)await transfer.task;
   if(workers.get(p.account)!==e)return true;
   if(world.players.get(p.account)!==p){await drop(p,e,'replaced');return true;}
   if(!current(p,e))throw Error('Worker departure identity changed.');
   if(!shutdown&&(occupied(p)||shouldHandoff(p)))return false;
   if(!shutdown&&isProtected(p))return false;
   await beforeLeave(p,{reason:shutdown?'disabled':'expired'});
   if(!current(p,e))throw Error('Worker departure custody changed during maintenance.');
   if(!shutdown&&(occupied(p)||shouldHandoff(p)||isProtected(p)))return false;
   await world.leave(p.account,e.token);
   if(world.players.get(p.account)===p)throw Error('Worker durable departure did not release its actor.');
   leaves++;await drop(p,e,shutdown?'disabled':'expired');return true;
  })().catch(error=>{fail(e,error,'departure');throw error;}).finally(()=>{if(departures.get(p.account)===op)departures.delete(p.account);if(current(p,e)&&!e.failed)e.phase='ready';});
  void op.task.catch(()=>{});return op.task;
 }
 const selectable=(account,p,at)=>!workers.has(account)&&!unconfirmed.has(account)&&!reservations.has(account)&&!world.players.has(account)&&at>=(retries.get(account)||0)&&nativeEligible(world,account,p)&&eligible(p,{account})&&!occupied({map:p.map,channel:p.channel??0,instanceId:null,profile:p});
 async function maintain(){
  for(const e of [...workers.values()]){const p=e.player;if(e.failed||transfers.has(p.account)||departures.has(p.account))continue;if(world.players.get(p.account)!==p){await drop(p,e,'replaced');continue;}if(occupied(p)||shouldHandoff(p)){void handoffCurrent(p,{requested:()=>occupied(p)||shouldHandoff(p)}).catch(()=>{});continue;}if(now()>=e.until&&!isProtected(p))void retire(p,e).catch(()=>{});}
  if(!live()||unconfirmed.size||optionalAdmissionAllowed()!==true||workers.size+reservations.size>=6)return;
  const at=now();for(let n=0;n<8;n++){
   if(!iterator)iterator=profiles.profiles.entries();let row=iterator.next();if(row.done){iterator=profiles.profiles.entries();row=iterator.next();if(row.done)return;}
   const [account,profile]=row.value;scanned++;if(!selectable(account,profile,at))continue;
   const ticket=admissionBudget.reserve([account],{role:'worker'});if(!ticket)return;
   const captured={account,profile,characterId:profile.id,map:profile.map,channel:profile.channel??0,epoch:generation()};reservations.set(account,captured);let lease=null,owned=null;
   const valid=()=>live()&&generation()===captured.epoch&&optionalAdmissionAllowed()===true&&ticket.valid()&&profiles.profiles.get(account)===profile&&profile.id===captured.characterId&&profile.map===captured.map&&(profile.channel??0)===captured.channel&&selectableIgnoringReservation()&&!occupied({map:captured.map,channel:captured.channel,instanceId:null});
   const selectableIgnoringReservation=()=>!world.players.has(account)&&nativeEligible(world,account,profile)&&eligible(profile,{account});
   try{
    admissionRequests++;lease=await admitScene({map:captured.map,channel:captured.channel,account,profile});
    if(lease?.ok!==true||typeof lease.release!=='function'){refuse(lease?.reason||'native residency refused');retries.set(account,at+policy.retryMs);return;}
    if(!valid()){refuse('admission scope changed');return;}
    if(typeof world.npcJoinWave!=='function')throw Error('Bounded workers require atomic native admission receipts.');
    const result=await world.npcJoinWave([{account,characterId:captured.characterId}]),r=result?.admissions?.[0],candidate=world.players.get(account);
    if(result?.committed!==true||result.admissions?.length!==1||r?.account!==account||r.characterId!==captured.characterId||candidate?.token!==r.token||!canonical(candidate))throw Error('Bounded worker admission receipt mismatch.');
    owned=candidate;
    if(!canonical(owned)||owned.characterId!==captured.characterId)throw Error('Bounded worker canonical admission unavailable.');
    const e={player:owned,token:owned.token,id:owned.id,characterId:owned.characterId,until:now()+policy.sliceMs,lastWorked:null,phase:'ready',failed:null};workers.set(account,e);joins++;
    await onJoin(owned);
    if(!current(owned,e))throw Error('Bounded worker changed during registration.');
    if(closed||!enabled()||generation()!==captured.epoch)await retire(owned,e,{shutdown:true});
    else if(owned.map!==captured.map||(owned.channel??0)!==captured.channel||owned.instanceId||!nativeEligible(world,account,{...owned.profile,map:owned.map,channel:owned.channel??0}))await retire(owned,e,{shutdown:true});
    else if(occupied(owned)||shouldHandoff(owned))await handoffCurrent(owned,{requested:()=>occupied(owned)||shouldHandoff(owned)});
   }catch(error){
    rejected++;retries.set(account,at+policy.retryMs);const e=workers.get(account);
    if(e){fail(e,error,'admission');try{await retire(e.player,e,{shutdown:true});}catch{}}
    // Only an exact returned/error-referenced actor can be cleaned up. A
    // namespace reread never authorizes leaving an unconfirmed replacement.
    else {const refs=error.npcAdmissionActors;if(Array.isArray(refs))owned=refs.find(p=>p.account===account&&p.characterId===captured.characterId&&canonical(p));if(owned&&canonical(owned)){const failed={player:owned,token:owned.token,id:owned.id,characterId:owned.characterId,until:now(),phase:'failed',failed:error.message,lastWorked:null};workers.set(account,failed);try{await retire(owned,failed,{shutdown:true});}catch{}}else if(world.players.has(account))unconfirmed.add(account);}
    report(error,'admission',owned);
   }finally{if(lease?.release){lease.release();admissionReleases++;}ticket();reservations.delete(account);}
   return; // One bounded optional admission per maintenance turn.
  }
 }
 const api={
  schedule(){if(!live())return;dispatch();if(maintenance||now()<nextAt)return;nextAt=now()+policy.tickMs;maintenance=Promise.resolve().then(maintain).catch(e=>report(e,'maintenance')).finally(()=>{maintenance=null;});},
  async tick(){api.schedule();if(maintenance)await maintenance;dispatch();},
  owns:p=>workers.get(p?.account)?.player===p,
  inFlight:p=>flights.get(p?.account)?.player===p||transfers.get(p?.account)?.player===p||departures.get(p?.account)?.entry.player===p,
  ownedPlayers:()=>[...workers.values()].map(e=>e.player),
  handoffCurrent,
  adoptCurrent:()=>Promise.resolve(false),
  preload:()=>Promise.resolve({phase:'bounded-not-requested',complete:false}),
  async settleAccepted(){draining++;try{if(maintenance)await maintenance;await Promise.allSettled([...flights.values(),...transfers.values(),...departures.values()].map(o=>o.task));}finally{draining--; }},
  queuedProfileIds(){if(!live())return new Set();const at=now();return new Set([...profiles.profiles].filter(([a,p])=>selectable(a,p,at)).map(([,p])=>p.id));},
  close(){if(closing)return closing;closed=true;closing=(async()=>{await api.settleAccepted();for(const e of [...workers.values()])await retire(e.player,e,{shutdown:true});if(unconfirmed.size)throw Error('Unconfirmed worker admission requires exact native custody recovery.');})().finally(()=>{closing=null;});return closing;},
  snapshot(){return {kind:'bounded native-action workers',policy:'ENGINE-CHOSEN finite scheduling; ordinary native authorities',...policy,enabled:live(),workers:workers.size,inFlight:flights.size,maxInFlight:6,pendingTransfers:transfers.size,pendingDepartures:departures.size,reservedAdmissions:[...reservations.keys()].filter(account=>!world.players.has(account)).length,failedWorkers:[...workers.values()].filter(e=>e.failed).length,unconfirmedAdmissions:unconfirmed.size,maintenancePending:!!maintenance,canonicalProfiles:profiles.profiles.size,scanned,admissionRequests,admissionRefused,admissionReleases,rejected,steps,joins,leaves,logicalOnline:false,refusals:[...refusals].map(([reason,count])=>({reason,count})),rows:[...workers.values()].map(e=>({map:e.player.map,level:e.player.profile.level,phase:e.phase,lastWorked:e.lastWorked,until:e.until}))};},
 };
 return api;
}
