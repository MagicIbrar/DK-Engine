// A driver promise cannot be cancelled, but its obsolete result must never admit a scene.
export function awaitLoadingStage(work,{current=()=>true,timeoutMs=30000,pollMs=100,stage='Scene graphics'}={}){
  return new Promise((resolve,reject)=>{
    let done=false,timer,poll;
    const finish=(error,value)=>{if(done)return;done=true;clearTimeout(timer);clearInterval(poll);error?reject(error):resolve(value);};
    const error=(message,reason='changed')=>Object.assign(new Error(message),{loadingStageFailure:true,loadingStageReason:reason});
    const valid=()=>{try{return current()===true;}catch{return false;}};
    const check=()=>{if(!valid())finish(error('Map loading changed. Retry loading.'));};
    if(!valid()){finish(error('Map loading changed. Retry loading.'));return;}
    timer=setTimeout(()=>finish(error(stage+' did not finish. Retry loading.','timeout')),timeoutMs);
    poll=setInterval(check,pollMs);
    Promise.resolve().then(()=>{if(done||!valid()){finish(error('Map loading changed. Retry loading.'));return;}return work();}).then(value=>valid()?finish(null,value):finish(error('Map loading changed. Retry loading.')),failure=>finish(error(stage+' failed. Retry loading.','driver')));
  });
}
