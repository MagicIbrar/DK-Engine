// Optional build/learning commands are ordinary durable actions. Spread their
// starts while humans are playing so they do not saturate the shared store.
// Combat, earned progress and human commands never pass through this gate.
export function createNpcOptionalWorkPacer({now,hasHuman,intervalMs=750}){
 if(typeof now!=='function'||typeof hasHuman!=='function'||!Number.isFinite(intervalMs)||intervalMs<1)throw Error('Invalid NPC optional work pacing');
 let nextAt=0;
 return {
  take(){
   if(!hasHuman()){nextAt=0;return true;}
   const at=Number(now());if(!Number.isFinite(at)||at<nextAt)return false;
   nextAt=at+intervalMs;return true;
  },
  nextAt(){return nextAt;}
 };
}
