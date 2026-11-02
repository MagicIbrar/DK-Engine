// Private host queue. request() never awaits native readiness or setup and must
// not be exposed as a browser-triggered mutation. Status reads only snapshot.
export function createAdminGuildJob({prepare,shouldYield=()=>false,schedule=setImmediate,retryMs=0,delay=setTimeout,cancel=clearTimeout}={}){
 if(typeof prepare!=='function'||typeof shouldYield!=='function'||typeof schedule!=='function'||typeof delay!=='function'||typeof cancel!=='function'||!Number.isInteger(retryMs)||retryMs<0||retryMs>60000)throw Error('Private ADMIN job hooks required.');
 let flight,retryTimer,stopped=false,report={phase:'idle',complete:false};
 const snapshot=()=>structuredClone(report),yielding=()=>stopped||shouldYield();
 const job={
  snapshot,
  request(){
   if(stopped)return {phase:'stopped',complete:false};if(flight)return snapshot();
   if(retryTimer){cancel(retryTimer);retryTimer=null;}
   report={...report,phase:'queued',complete:false};let finish;flight=new Promise(resolve=>finish=resolve);
   schedule(async()=>{
    try{
     const y=yielding();if(y)report={...report,phase:'deferred',complete:false,reason:typeof y==='string'?y:'human-admission-or-host-stopping'};
     else{report={...report,phase:'running',complete:false};const result=await prepare(yielding);report={...result,phase:result.complete?'complete':result.partial?'partial':'deferred'};}
    }catch(error){const setupReason=typeof error?.setupReason==='string'?error.setupReason:null;const msg=typeof error?.message==='string'?error.message.slice(0,160):'';console.error('[admin-guild] prepare failed',setupReason||msg||error);report={...report,phase:'failed',complete:false,reason:setupReason||'ordinary-preparation-failed',error:msg||undefined};}
    finally{
     flight=null;finish();
     // A long ordinary NPC walk can exceed one cooperative budget. Resume
     // only that interruption; persisted guild intents make each pass safe.
     if(retryMs&&report.reason==='human-admission-or-setup-budget'&&!yielding()){
      retryTimer=delay(()=>{retryTimer=null;job.request();},retryMs);
      retryTimer?.unref?.();
     }
    }
   });
   return snapshot();
  },
  async settle(){await flight;return snapshot();},
  async close(){stopped=true;if(retryTimer){cancel(retryTimer);retryTimer=null;}await flight;return snapshot();},
 };
 return job;
}
