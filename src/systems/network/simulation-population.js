// Server snapshot counts, explicitly separate from connected human/scene actors.
// A queue is waiting for native work; neither saved nor queued implies earned XP.
const MAX_COUNT=1000000;
export function simulationPopulationView(raw){
 if(!raw||typeof raw!=='object'||Array.isArray(raw)||Object.getOwnPropertyDescriptor(raw,'enabled')?.value!==true)return null;
 const counts={enabled:true};
 for(const key of ['saved','queued','materialized','remoteWorkers','humans']){
  const value=Object.getOwnPropertyDescriptor(raw,key)?.value;if(!Number.isSafeInteger(value)||value<0||value>MAX_COUNT)return null;
  counts[key]=value;
 }
 const simulated=counts.queued+counts.materialized;
 if(simulated>counts.saved||counts.remoteWorkers>counts.materialized)return null;
 const dormant=Object.getOwnPropertyDescriptor(raw,'simulated')?.value;
 if(dormant!==undefined&&dormant!==null&&(!Number.isSafeInteger(dormant)||dormant<0||dormant+counts.materialized>counts.saved))return null;
 if(Number.isSafeInteger(dormant))counts.simulated=dormant;
 return Object.freeze({counts:Object.freeze(counts),label:`ONLINE · ${counts.humans} real · ${counts.materialized} bots`,
  title:`Global loaded population: ${counts.humans} real players; ${counts.materialized} physically loaded bot actors, including ${counts.remoteWorkers} background workers. Separate saved population: ${counts.saved} saved bot identities; ${counts.queued} queued${Number.isSafeInteger(dormant)?`, ${dormant} dormant simulated`:''}. Saved or simulated identities are not online actors; waiting does not earn XP, DIL or items. Dormant simulation earns no quest progress.`});
}
