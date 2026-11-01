// ENGINE-CHOSEN scene preparation bookkeeping. It does not admit actors,
// release player leases, grant progress, or certify client asset readiness.
export function createNpcSceneWarming({now=Date.now,maxScenes=128}={}) {
 const states=new Map(),flights=new Map();let revision=0;
 const snapshot=key=>{const s=states.get(key);return s?{...s}:null;};
 return {
  warming:key=>flights.has(key),
  snapshot,
  run({key,map,instanceId=null,channel=0},work){
   if(flights.has(key))return flights.get(key);
   if(typeof work!=='function')throw Error('Scene warming requires ordinary admission work.');
   if(!states.has(key)&&states.size>=maxScenes){const old=[...states.keys()].find(k=>!flights.has(k));if(old!==undefined)states.delete(old);else return Promise.reject(Error('Scene warming budget is occupied.'));}
   const previous=states.get(key),targetRetries=previous?.failed==='target-changed'?(previous.targetRetries||0)+1:0;
   const state={map,instanceId,channel,phase:'warming',ceiling:0,eligible:0,target:0,active:0,complete:false,failed:null,targetRetries,revision:++revision,startedAt:now(),updatedAt:now()};states.set(key,state);
   const update=fields=>{if(states.get(key)===state)Object.assign(state,fields,{revision:++revision,updatedAt:now()});};
   const task=Promise.resolve().then(()=>work(update)).then(result=>{
    const ceiling=result?.ceiling??state.ceiling,eligible=result?.eligible??state.eligible,target=result?.target||0,active=result?.actors||0;
    const complete=result?.complete===true&&[ceiling,eligible,target,active].every(n=>Number.isInteger(n)&&n>=0&&n<=1250)&&target===Math.min(ceiling,eligible)&&active>=target;
    const failed=['scene-changed','capacity','native-admission','target-changed'].includes(result?.reason)?result.reason:complete?null:'native-admission';
    update({ceiling,eligible,target,active,complete,phase:complete?'ready':'incomplete',failed});return result;
   },error=>{update({phase:'incomplete',complete:false,failed:'native-admission'});throw error;}).finally(()=>{if(flights.get(key)===task)flights.delete(key);});
   flights.set(key,task);return task;
  },
  async settle(){while(flights.size)await Promise.allSettled([...flights.values()]);},
  clear(){if(flights.size)throw Error('Settle native scene admission before clearing readiness.');states.clear();},
  pending:()=>flights.size,
 };
}
