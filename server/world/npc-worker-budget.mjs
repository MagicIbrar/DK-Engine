// ENGINE-CHOSEN shared physical/admission limits. This census grants no
// actor custody, native map access, progress or online-presence authority.
export function npcWorkerBudgetCensus({players,held=new Map(),humanReservations=[],workerPlayers=[],capacity=150,maxWorkers=6}={}){
 const actual=new Set(players.keys()),all=new Set(actual),worker=new Set();
 let pendingHuman=0,pendingForeground=0,pendingWorker=0;
 for(const account of humanReservations)if(!actual.has(account)){all.add(account);pendingHuman++;}
 for(const [account,ticket]of held){all.add(account);if(ticket.role==='worker')worker.add(account);if(actual.has(account))continue;if(ticket.role==='worker')pendingWorker++;else pendingForeground++;}
 for(const p of workerPlayers)if(p&&players.get(p.account)===p)worker.add(p.account);
 return {actual:actual.size,total:all.size,pendingHuman,pendingForeground,pendingWorker,workerUnits:worker.size,capacity,maxWorkers,available:Math.max(0,capacity-all.size),workerAvailable:Math.max(0,maxWorkers-worker.size)};
}
