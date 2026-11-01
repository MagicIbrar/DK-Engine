// ENGINE-CHOSEN host governor for interest-managed NPCs. Internet upload is a
// ceiling, never proof that the CPU or account store can run a native roster.
// The percentage controls nearby density and the presence-only background
// cohort; it does not activate full off-map gameplay.
export function npcUploadCeiling(mbps) {
  const speed=Number(mbps);
  if(!Number.isFinite(speed)||speed<=0)return 25; // unknown: stay conservative
  if(speed<5)return 20;
  if(speed<15)return 35;
  if(speed<30)return 55;
  if(speed<60)return 75;
  return 100;
}

export function npcInterestMode({interest,nativeCapacity}={}){
  if(interest!==undefined&&!['0','1'].includes(interest))throw Error('NPC interest mode must be 0 or 1.');
  if(nativeCapacity&&interest==='1')throw Error('Interest-managed bots and the native capacity tier are mutually exclusive.');
  return interest==='0'?false:!nativeCapacity;
}

// Interval-based Node histogram values include the configured timer period.
// Keep raw measurements observable; only excess delay drives lag thresholds.
export function npcEventLoopDelay(rawMs,resolutionMs){
  if(typeof rawMs!=='number'||!Number.isFinite(rawMs)||rawMs<0||!Number.isInteger(resolutionMs)||resolutionMs<=0)throw Error('Invalid NPC event-loop delay measurement');
  return {lagRawMs:rawMs,lagResolutionMs:resolutionMs,lagMs:Math.max(0,rawMs-resolutionMs)};
}

// Actual process CPU time, in single-core equivalents, not logical CPU count.
// This captures async/native/store work omitted by the tick+broadcast EWMA.
export function createNpcHostSampler({now=()=>performance.now(),cpuUsage=()=>process.cpuUsage()}={}){
  let previous=cpuUsage(),at=now(),failures=0;
  return live=>{const current=cpuUsage(),next=now(),elapsed=next-at,cpuRatio=elapsed>0?Math.max(0,(current.user-previous.user+current.system-previous.system)/(elapsed*1000)):0;
    previous=current;at=next;const failed=Number(live.storeWriter?.failed)||0,storeFailures=Math.max(0,failed-failures);failures=failed;
    return {cpuRatio,storeFailures,storeActive:Number(live.storeWriter?.active)||0,storeAgeMs:Number(live.storeWriter?.current?.elapsedMs)||0,saveFlights:Number(live.saveFlights)||0};};
}

export function createNpcAutoPopulation({uploadMbps=0,now=()=>performance.now()}={}) {
  if(typeof now!=='function')throw new Error('NPC host governor needs a clock.');
  let ceiling=npcUploadCeiling(uploadMbps),percent=Math.min(35,ceiling),last=now(),calmMs=0,pressureCalmMs=0,pressure=false,reason='warming',observation=null;
  const clamp=(n,low,high)=>Math.max(low,Math.min(high,n));
  return Object.freeze({
    value:()=>percent,
    optionalWorkAllowed:()=>!pressure,
    state:()=>({percent,ceiling,presenceTarget:Math.round(250+(percent-10)*1000/90),optionalWorkAllowed:!pressure,reason,observation:observation?{...observation}:null}),
    observe({uploadMbps:measured=uploadMbps,workMs=0,lagMs=0,lagRawMs=null,lagResolutionMs=null,heapUsedMB=0,heapLimitMB=0,humans=0,preparing=false,canonicalPreparing=false,cpuRatio=0,storeActive=0,storeAgeMs=0,saveFlights=0,storeFailures=0}={}) {
      const at=now(),elapsed=clamp(at-last,0,2000);last=at;
      observation={lagMs,lagRawMs,lagResolutionMs,cpuRatio,storeActive,storeAgeMs,saveFlights,storeFailures,preparing:!!preparing,canonicalPreparing:!!canonicalPreparing,humans};
      ceiling=npcUploadCeiling(measured);percent=Math.min(percent,ceiling);
      const ratio=heapLimitMB>0?heapUsedMB/heapLimitMB:0;
      const storeBusy=storeFailures>0||saveFlights>=8||storeActive>0&&storeAgeMs>250;
      const overloaded=workMs>50||lagMs>35||ratio>0.75||cpuRatio>.8||storeBusy;
      const calm=workMs<30&&lagMs<15&&ratio<0.65&&cpuRatio<.6&&!storeBusy;
      // The percentage only scales foreground NPCs in human-occupied scenes (and the
      // presence-only cohort). With no human in the world (bots OFF, startup, empty
      // world) no such actor exists, and canonical saved-profile preparation is a
      // one-time CPU-bound batch that admits no actors; lowering the target for either
      // relieves nothing and only winds the session down to the floor. Pressure still
      // pauses optional work immediately; occupied-world overload, including scene
      // admission preparation, still lowers the target.
      if(overloaded){pressure=true;pressureCalmMs=0;if(humans>0&&!canonicalPreparing)percent=Math.max(10,percent-10);calmMs=0;reason=storeBusy?'save pressure':ratio>0.75?'memory':cpuRatio>.8?'process CPU':lagMs>35?'server delay':'server work';}
      else if(calm){pressureCalmMs+=elapsed;if(pressureCalmMs>=3000)pressure=false;if(humans>0&&!preparing){calmMs+=elapsed;reason='stable';if(!pressure&&calmMs>=10000&&percent<ceiling){percent=Math.min(ceiling,percent+5);calmMs=0;}}else{calmMs=0;reason=pressure?'recovering':preparing?'preparing':'waiting for players';}}
      else{calmMs=0;pressureCalmMs=0;reason=humans>0?'holding':'waiting for players';}
      return percent;
    },
  });
}
