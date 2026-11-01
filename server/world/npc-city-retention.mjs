// ENGINE-CHOSEN retention hysteresis for already admitted quiet city bodies.
// This grants no admission, account, scene, transaction or movement authority.
export function createNpcCityRetention({now,graceMs=30000,stepMs=5000,maximum=55}={}) {
  if(typeof now!=='function')throw Error('City retention needs a clock.');
  const scenes=new Map();
  return {
    target(key,{scaled,quiet,actual,optionalWorkAllowed,percent}) {
      if(!Number.isSafeInteger(scaled)||scaled<0||!Number.isSafeInteger(quiet)||quiet<0||!Number.isSafeInteger(actual)||actual<quiet||typeof optionalWorkAllowed!=='boolean'||!Number.isFinite(percent))return scaled;
      const at=now();let state=scenes.get(key);
      if(!state){state={pressureAt:null,ceiling:maximum,lastStep:at};scenes.set(key,state);}
      if(optionalWorkAllowed||percent>10){state.pressureAt=null;state.ceiling=maximum;state.lastStep=at;}
      else {
        if(state.pressureAt===null||at<state.pressureAt){state.pressureAt=at;state.lastStep=at+graceMs;}
        if(at>=state.pressureAt+graceMs&&at-state.lastStep>=stepMs){
          const steps=Math.floor((at-state.lastStep)/stepMs);
          state.ceiling=Math.max(scaled,state.ceiling-steps);state.lastStep+=steps*stepMs;
        }
      }
      // Every admitted resident is retained, not only "quiet + 10": saved bots carrying
      // accepted quests (and fresh arrivals not yet given a city duty) are never quiet, so
      // that cap retired them seconds after each join wave and re-admitted the same
      // profiles on the next calm second (bots vanished and reappeared in place).
      return Math.max(scaled,Math.min(actual,state.ceiling,maximum));
    },
    forget:key=>scenes.delete(key),
    clear:()=>scenes.clear()
  };
}
