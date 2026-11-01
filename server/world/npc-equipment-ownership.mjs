// Shared read-only ownership guard for durable ENGINE-CHOSEN equipment work.
export function protectedNpcEquipmentUids(world,p){
 const task=p.profile.npcEquipment;
 return new Set(task?.version===1&&task.policy==='ENGINE-CHOSEN'&&task.phase==='working'?[task.plan?.uid,...(task.plan?.inputs||[])].filter(Boolean):[]);
}
