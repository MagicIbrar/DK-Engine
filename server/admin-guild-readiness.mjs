// Owner-only admission fence. Never creates a guild, mutates sessions or runs a job.
// The private launcher already enqueues setup; ordinary readiness polls only observe it.
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
   if(pending&&now()-started<timeoutMs)return {ready:false,phase:'preparing',retryAfterMs:1000};
   const reason=pending?'timeout':report?.reason||'setup-not-queued';
   const error=reason==='existing-session-active'
    ?'Owner guild preparation needs the other owner game session to sign out. Return to Client and retry owner sign-in.'
    :reason==='timeout'?'Owner guild preparation did not finish within three minutes. Return to Client, inspect host setup status, and retry owner sign-in.'
    :'Owner guild preparation could not finish. Check the private host setup status, then retry owner sign-in.';
   return {ready:false,phase:'failed',retryAfterMs:0,code:reason==='timeout'?'OWNER_GUILD_SETUP_TIMEOUT':'OWNER_GUILD_SETUP_FAILED',error};
  },
 };
}

export function requestOwnerGuildPreparation(world){const report=world.adminGuildReport;return report?.complete===true?report:world.requestAdminGuild();}
