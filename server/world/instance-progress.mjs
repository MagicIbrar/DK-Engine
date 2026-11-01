/** Durable director rewards: candidates stay private until the atomic party write succeeds. */
const error=message=>Object.assign(Error(message),{status:409});
const occupants=(world,i,recipients=null)=>[...world.players.values()].filter(p=>p.instanceId===i.id&&(recipients?recipients.has(p.id):!p.leaving));
export function hasPendingInstanceProgress(world,p){const i=world.instances?.get(p.instanceId);return !!i&&(!!i.floorTransition||[...i.progressJobs?.values()||[]].some(job=>job.recipients.has(p.id)));}
export function queueInstanceProgress(world,i,key,apply,onCommit=()=>{}){
  i.progressJobs||=new Map();i.progressDone||=new Set();
  if(i.progressDone.has(key)||i.progressJobs.has(key))return;
  // Eligibility belongs to the earned event, not to the lease status at retry.
  const recipients=new Set(occupants(world,i).map(p=>p.id));
  if(!recipients.size){i.progressDone.add(key);onCommit();return;}
  i.progressJobs.set(key,{key,apply,onCommit,recipients});i.flushProgress=actor=>flushInstanceProgress(world,actor,i);
  retryInstanceProgress(world,i);
}
function drain(world,i,actor=null){
  if(i.progressSave)return i.progressSave;
  const job=i.progressJobs?.values().next().value;if(!job)return null;
  const players=occupants(world,i,job.recipients);
  if(players.length!==job.recipients.size){if(actor)throw error('An earned reward participant is waiting for reconnect.');return null;}
  // A running API command can replace a profile after its first awaited write.
  // Defer automatic settlement until those commands have completed.
  if(players.some(p=>p.sceneTransition||(p.commandActive||0)>(p===actor?1:0))){if(actor)throw error('Wait for party actions to finish before leaving the run.');return null;}
  const events=[],candidates=players.map(p=>({...p,profile:structuredClone(p.profile)}));
  players.forEach(p=>{p.sceneTransition=true;p.progressCommitting=true;});
  const task=Promise.resolve().then(async()=>{
    try{
      for(const p of candidates){const receipts=p.profile.instanceProgressReceipts||=[];if(receipts.includes(job.key))continue;job.apply(p,{...world,changed(){},emit:(map,event)=>events.push([map,event])});receipts.push(job.key);if(receipts.length>128)receipts.shift();world.changed(p);}
      await world.persistMany(candidates);
      candidates.forEach((candidate,index)=>{const p=players[index],leveled=candidate.profile.level>p.profile.level;p.profile=candidate.profile;p.revision=candidate.revision;p.dirty=candidate.dirty;p.saveError=null;if(leveled)for(const key of ['stats','maxHp','hp','mp'])p[key]=candidate[key];});
      i.progressJobs.delete(job.key);i.progressDone.add(job.key);i.saveError=null;i.progressRetryAt=0;
      for(const[map,event]of events)world.emit(map,event);job.onCommit();
    }catch(cause){i.saveError=cause.message;i.progressRetryAt=world.now()+1000;world.saveQueue=world.saveQueue?.catch(()=>{});throw cause;}
    finally{players.forEach(p=>{p.sceneTransition=false;p.progressCommitting=false;if(p.progressSave===task)p.progressSave=null;});if(i.progressSave===task)i.progressSave=null;}
  });
  i.progressSave=task;players.forEach(p=>p.progressSave=task);return task;
}
export function retryInstanceProgress(world,i){
  if(i.progressSave||world.now()<(i.progressRetryAt||0))return;
  const task=drain(world,i);void task?.catch(()=>{});
}
export async function flushInstanceProgress(world,p,instance=world.instances?.get(p?.instanceId),{allowFloorTransition=false}={}){
  if(!instance)return;
  if(instance.floorTransition&&!allowFloorTransition){if(!instance.pendingTransfer)throw error('Wait for the current dungeon floor to finish saving.');await instance.pendingTransfer;}
  while(instance.progressJobs?.size){const task=drain(world,instance,p);if(!task)throw error('Instance progress is waiting for storage. Retry leaving after it settles.');await task;}
}
