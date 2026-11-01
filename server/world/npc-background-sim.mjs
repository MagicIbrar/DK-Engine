// ENGINE-CHOSEN background presence simulation for dormant canonical bots.
// A dormant bot is NOT an actor: nothing here loads a map, touches a saved
// profile, grants exp/loot/quests/items, or counts as a connection. It only
// decides which ordinary public native map each saved character is "on", so the
// director can materialise the right residents when a human actually stands there.
const hash=v=>{let n=2166136261;for(const c of String(v??''))n=Math.imul(n^c.charCodeAt(0),16777619)>>>0;return n;};
export const NPC_BACKGROUND_SIM_POLICY=Object.freeze({tickMs:1000,perTick:48,stayMinMs:180000,staySpanMs:600000,travelOdds:0,rebuildMs:60000});
export const NPC_BACKGROUND_ACTIVITIES=Object.freeze(['farm','quest','merchant','rest']);
/** profiles: canonical account->saved profile Map (read only). present(account): a physical actor exists.
 * candidateMaps(): public native map indices bots may drift between. eligible(account,profile,map):
 * ordinary native admission/level test for that destination. locked(account,profile): never relocate. */
export function createNpcBackgroundSim({profiles,present,candidateMaps,eligible,locked=()=>false,now,random=Math.random,activeCount=null,policy:overrides={}}){
 if(!(profiles instanceof Map)||typeof present!=='function'||typeof candidateMaps!=='function'||typeof eligible!=='function'||typeof locked!=='function'||typeof now!=='function'||typeof random!=='function')throw Error('Background simulation requires canonical profiles and ordinary callbacks.');
 const bound=(v,d,lo,hi)=>Number.isFinite(v)?Math.max(lo,Math.min(hi,Math.trunc(v))):d,base=NPC_BACKGROUND_SIM_POLICY;
 const policy={tickMs:bound(overrides.tickMs,base.tickMs,1,60000),perTick:bound(overrides.perTick,base.perTick,1,512),stayMinMs:bound(overrides.stayMinMs,base.stayMinMs,1,3600000),staySpanMs:bound(overrides.staySpanMs,base.staySpanMs,1,3600000),rebuildMs:bound(overrides.rebuildMs,base.rebuildMs,1,600000),travelOdds:Number.isFinite(overrides.travelOdds)?Math.max(0,Math.min(1,overrides.travelOdds)):base.travelOdds};
 const states=new Map();let order=[],active=null,cursor=0,orderAt=-Infinity,lastTick=-Infinity,maps=[],moves=0,ticks=0,cohortTarget=null,knownSize=-1,preferred=[];
 const stay=()=>policy.stayMinMs+Math.floor(random()*policy.staySpanMs),pick=list=>list[Math.min(list.length-1,Math.floor(random()*list.length))];
 // Staggered first decisions keep the whole roster from changing maps in one burst.
 const state=(account,profile,at)=>{let s=states.get(account);if(!s){s={map:Number(profile.map),activity:NPC_BACKGROUND_ACTIVITIES[hash(account)%NPC_BACKGROUND_ACTIVITIES.length],until:at+hash(account+':stagger')%(policy.stayMinMs+policy.staySpanMs),present:false};states.set(account,s);}return s;};
 // A bot that was physically present and has since retired resumes from the map it last stood on.
 const sync=(account,profile,at)=>{const s=state(account,profile,at);if(present(account)===true)s.present=true;else if(s.present){s.present=false;s.map=Number(profile.map);s.until=at+stay();s.activity=pick(NPC_BACKGROUND_ACTIVITIES);}return s;};
 function rebuild(at){const saved=[...profiles.keys()];cohortTarget=typeof activeCount==='function'?bound(activeCount(),saved.length,0,saved.length):null;
  if(cohortTarget===null){active=null;order=saved;}
  else{const visible=saved.filter(present),chosen=new Set(visible);for(const account of preferred){if(chosen.size>=cohortTarget)break;if(profiles.has(account))chosen.add(account);}for(const account of saved.toSorted((a,b)=>hash(a)-hash(b)||a.localeCompare(b))){if(chosen.size>=cohortTarget)break;chosen.add(account);}active=chosen;order=[...chosen];for(const account of order)state(account,profiles.get(account),at);}
  knownSize=saved.length;orderAt=at+policy.rebuildMs;for(const account of states.keys())if(!profiles.has(account)||active&&!active.has(account))states.delete(account);if(order.length)cursor%=order.length;else cursor=0;maps=[...new Set((candidateMaps()||[]).map(Number).filter(Number.isInteger))].sort((a,b)=>a-b);}
 function ensure(at){if(knownSize!==profiles.size||at>=orderAt||active&&bound(activeCount(),profiles.size,0,profiles.size)!==cohortTarget)rebuild(at);}
 return {
  // At most three caller-verified city merchants may replace dormant hash picks.
  // Already visible actors and the same cohort ceiling always take precedence.
  prefer(accounts){const next=[...new Set(accounts)].filter(account=>profiles.has(account)).slice(0,3);if(next.length===preferred.length&&next.every((account,i)=>account===preferred[i]))return;preferred=next;orderAt=-Infinity;},
  /** Advance a bounded slice of the roster. Returns how many bots changed map. */
  tick(){
   const at=Number(now());if(!Number.isFinite(at)||at-lastTick<policy.tickMs)return 0;lastTick=at;ticks++;
   ensure(at);
   let moved=0;
   for(let n=0;n<policy.perTick&&order.length;n++){
    const account=order[cursor];cursor=(cursor+1)%order.length;const profile=profiles.get(account);if(!profile)continue;
    const s=sync(account,profile,at);if(s.present||at<s.until)continue;
    s.until=at+stay();s.activity=pick(NPC_BACKGROUND_ACTIVITIES);
    if(random()>=policy.travelOdds||locked(account,profile))continue;
    const options=maps.filter(map=>map!==s.map&&eligible(account,profile,map));if(!options.length)continue;
    s.map=pick(options);moved++;moves++;
   }
   return moved;
  },
  /** Dormant account IDs currently simulated on this public map. */
  residents(map){const at=Number(now()),target=Number(map),out=[];ensure(at);for(const account of active||profiles.keys()){const profile=profiles.get(account);if(!profile)continue;const s=sync(account,profile,at);if(!s.present&&s.map===target)out.push(account);}return out;},
  locate(account){const at=Number(now());ensure(at);if(active&&!active.has(account))return null;const profile=profiles.get(account);return profile?sync(account,profile,at).map:null;},
  activityOf(account){const at=Number(now());ensure(at);if(active&&!active.has(account))return null;const profile=profiles.get(account);return profile?sync(account,profile,at).activity:null;},
  /** The real world just placed this bot (spawn/arrival); continue the simulation from there. */
  place(account,map){const at=Number(now());ensure(at);const profile=profiles.get(account);if(!profile||active&&!active.has(account)||!Number.isInteger(Number(map)))return false;const s=state(account,profile,at);s.map=Number(map);s.present=present(account)===true;s.until=at+stay();return true;},
  forget(account){states.delete(account);},
  clear(){states.clear();order=[];active=null;cursor=0;orderAt=-Infinity;lastTick=-Infinity;maps=[];knownSize=-1;preferred=[];},
  snapshot(){const byMap=new Map();let dormant=0,live=0;for(const s of states.values()){if(s.present)live++;else{dormant++;byMap.set(s.map,(byMap.get(s.map)||0)+1);}}
   return {kind:'background presence simulation',policy:'ENGINE-CHOSEN presence only; no exp, loot, quests, items or connections',tracked:states.size,cohortTarget,dormant,materialized:live,moves,ticks,candidateMaps:maps.length,maps:[...byMap].sort((a,b)=>b[1]-a[1]||a[0]-b[0]).slice(0,12).map(([map,count])=>({map,count})),limits:{...policy}};},
 };
}
