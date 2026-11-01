import { fetchJSON } from '../../engine/assets.js';

// Private proposal. ENGINE-CHOSEN bounded recovery follows assets.js's 1s/2s cooldown.
export async function requiredCatalog(url, kind) {
  for (let attempt=0; ; attempt++) {
    let value;
    try { value=await fetchJSON(url); }
    catch(error) {
      const transient=error?.transient&&!error?.missing&&(!error.status||error.status>=500||[408,429].includes(error.status));
      if(!transient||attempt>=2)throw error;
      await new Promise(resolve=>setTimeout(resolve,1025*2**attempt));
      continue;
    }
    const fields=kind==='effects'?['scenes','units']:kind==='status'?['statuses']:['skills'];
    for(const field of fields)if(!value?.[field]||typeof value[field]!=='object'||Array.isArray(value[field]))throw new Error(`Invalid required ${kind} catalog: ${field}`);
    return value;
  }
}

// Cancel only this waiter. The shared fetch/cache remains valid for other actors.
// ENGINE-CHOSEN: the existing loading-stage deadline is 30 seconds. Timing out
// never publishes a late-ready class; a page reload starts fresh shared requests.
export function awaitCatalog(promise,signal) {
  if(signal?.aborted){promise.catch(()=>{});return Promise.reject(signal.reason||new DOMException('Cancelled','AbortError'));}
  return new Promise((resolve,reject)=>{
    let done=false;
    const finish=(error,value)=>{if(done)return;done=true;clearTimeout(timer);signal?.removeEventListener('abort',cancel);error?reject(error):resolve(value);};
    const cancel=()=>finish(signal.reason||new DOMException('Cancelled','AbortError'));
    const timer=setTimeout(()=>finish(Object.assign(new Error('Skill catalogs did not finish. Retry loading.'),{loadingStageFailure:true,loadingStageReason:'timeout'})),30000);
    signal?.addEventListener('abort',cancel,{once:true});
    promise.then(value=>signal?.aborted?cancel():finish(null,value),error=>finish(error));
  });
}
