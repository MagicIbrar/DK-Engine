// Owner-only admission fence. Never creates a guild, mutates sessions or runs a job.
// The private launcher already enqueues setup; ordinary readiness polls only observe it.
// ALLOW_JOIN_ON_GUILD_FAIL: staff may enter while guild prep retries (Play must not hard-block).
export function createAdminGuildReadiness({now=Date.now,timeoutMs=180000}={}){
 if(typeof now!=='function'||!Number.isSafeInteger(timeoutMs)||timeoutMs<1)throw Error('Invalid owner guild readiness policy.');
 let started=null;
 const pendingReasons=new Set(['world-not-ready','human-admission-or-host-stopping','human-admission-or-setup-budget']);
 return {
  reset(){started=null;},
  read(base,report){
   if(!base.ready)return base;
   if(report?.complete===true){started=null;return base;}
   if(started===null)started=now();
   const pending=['queued','running'].includes(report?.phase)||report?.phase==='deferred'&&pendingReasons.has(report.reason);
   // Soft-wait only while actively preparing within budget; never hard-fail Play admission.
   if(pending&&now()-started<timeoutMs)return {ready:false,phase:'preparing',retryAfterMs:1000};
   started=null;
   return base; // ALLOW_JOIN_ON_GUILD_FAIL
  },
 };
}

export function requestOwnerGuildPreparation(world){const report=world.adminGuildReport;return report?.complete===true?report:world.requestAdminGuild();}